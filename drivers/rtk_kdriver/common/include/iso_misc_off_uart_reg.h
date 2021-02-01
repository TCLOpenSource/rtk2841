/**
* @file rbusISO_MISC_OFF_UARTReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_ISO_MISC_OFF_UART_REG_H_
#define _RBUS_ISO_MISC_OFF_UART_REG_H_

#include "rbus_types.h"



//  ISO_MISC_OFF_UART Register Address
#define  ISO_MISC_OFF_UART_U0RBR_THR_DLL                                         0x18062300
#define  ISO_MISC_OFF_UART_U0RBR_THR_DLL_reg_addr                                "0xB8062300"
#define  ISO_MISC_OFF_UART_U0RBR_THR_DLL_reg                                     0xB8062300
#define  ISO_MISC_OFF_UART_U0RBR_THR_DLL_inst_addr                               "0x0000"
#define  set_ISO_MISC_OFF_UART_U0RBR_THR_DLL_reg(data)                           (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0RBR_THR_DLL_reg)=data)
#define  get_ISO_MISC_OFF_UART_U0RBR_THR_DLL_reg                                 (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0RBR_THR_DLL_reg))
#define  ISO_MISC_OFF_UART_U0RBR_THR_DLL_dll_shift                               (0)
#define  ISO_MISC_OFF_UART_U0RBR_THR_DLL_dll_mask                                (0x000000FF)
#define  ISO_MISC_OFF_UART_U0RBR_THR_DLL_dll(data)                               (0x000000FF&(data))
#define  ISO_MISC_OFF_UART_U0RBR_THR_DLL_get_dll(data)                           (0x000000FF&(data))

#define  ISO_MISC_OFF_UART_U0IER_DLH                                             0x18062304
#define  ISO_MISC_OFF_UART_U0IER_DLH_reg_addr                                    "0xB8062304"
#define  ISO_MISC_OFF_UART_U0IER_DLH_reg                                         0xB8062304
#define  ISO_MISC_OFF_UART_U0IER_DLH_inst_addr                                   "0x0001"
#define  set_ISO_MISC_OFF_UART_U0IER_DLH_reg(data)                               (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0IER_DLH_reg)=data)
#define  get_ISO_MISC_OFF_UART_U0IER_DLH_reg                                     (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0IER_DLH_reg))
#define  ISO_MISC_OFF_UART_U0IER_DLH_dlh_shift                                   (0)
#define  ISO_MISC_OFF_UART_U0IER_DLH_dlh_mask                                    (0x000000FF)
#define  ISO_MISC_OFF_UART_U0IER_DLH_dlh(data)                                   (0x000000FF&(data))
#define  ISO_MISC_OFF_UART_U0IER_DLH_get_dlh(data)                               (0x000000FF&(data))

#define  ISO_MISC_OFF_UART_U0IIR_FCR                                             0x18062308
#define  ISO_MISC_OFF_UART_U0IIR_FCR_reg_addr                                    "0xB8062308"
#define  ISO_MISC_OFF_UART_U0IIR_FCR_reg                                         0xB8062308
#define  ISO_MISC_OFF_UART_U0IIR_FCR_inst_addr                                   "0x0002"
#define  set_ISO_MISC_OFF_UART_U0IIR_FCR_reg(data)                               (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0IIR_FCR_reg)=data)
#define  get_ISO_MISC_OFF_UART_U0IIR_FCR_reg                                     (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0IIR_FCR_reg))
#define  ISO_MISC_OFF_UART_U0IIR_FCR_fifo16_shift                                (6)
#define  ISO_MISC_OFF_UART_U0IIR_FCR_iid_shift                                   (0)
#define  ISO_MISC_OFF_UART_U0IIR_FCR_fifo16_mask                                 (0x000000C0)
#define  ISO_MISC_OFF_UART_U0IIR_FCR_iid_mask                                    (0x0000000F)
#define  ISO_MISC_OFF_UART_U0IIR_FCR_fifo16(data)                                (0x000000C0&((data)<<6))
#define  ISO_MISC_OFF_UART_U0IIR_FCR_iid(data)                                   (0x0000000F&(data))
#define  ISO_MISC_OFF_UART_U0IIR_FCR_get_fifo16(data)                            ((0x000000C0&(data))>>6)
#define  ISO_MISC_OFF_UART_U0IIR_FCR_get_iid(data)                               (0x0000000F&(data))

#define  ISO_MISC_OFF_UART_U0LCR                                                 0x1806230C
#define  ISO_MISC_OFF_UART_U0LCR_reg_addr                                        "0xB806230C"
#define  ISO_MISC_OFF_UART_U0LCR_reg                                             0xB806230C
#define  ISO_MISC_OFF_UART_U0LCR_inst_addr                                       "0x0003"
#define  set_ISO_MISC_OFF_UART_U0LCR_reg(data)                                   (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0LCR_reg)=data)
#define  get_ISO_MISC_OFF_UART_U0LCR_reg                                         (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0LCR_reg))
#define  ISO_MISC_OFF_UART_U0LCR_dlab_shift                                      (7)
#define  ISO_MISC_OFF_UART_U0LCR_brk_shift                                       (6)
#define  ISO_MISC_OFF_UART_U0LCR_eps_shift                                       (4)
#define  ISO_MISC_OFF_UART_U0LCR_pen_shift                                       (3)
#define  ISO_MISC_OFF_UART_U0LCR_stb_shift                                       (2)
#define  ISO_MISC_OFF_UART_U0LCR_wls_shift                                       (0)
#define  ISO_MISC_OFF_UART_U0LCR_dlab_mask                                       (0x00000080)
#define  ISO_MISC_OFF_UART_U0LCR_brk_mask                                        (0x00000040)
#define  ISO_MISC_OFF_UART_U0LCR_eps_mask                                        (0x00000010)
#define  ISO_MISC_OFF_UART_U0LCR_pen_mask                                        (0x00000008)
#define  ISO_MISC_OFF_UART_U0LCR_stb_mask                                        (0x00000004)
#define  ISO_MISC_OFF_UART_U0LCR_wls_mask                                        (0x00000003)
#define  ISO_MISC_OFF_UART_U0LCR_dlab(data)                                      (0x00000080&((data)<<7))
#define  ISO_MISC_OFF_UART_U0LCR_brk(data)                                       (0x00000040&((data)<<6))
#define  ISO_MISC_OFF_UART_U0LCR_eps(data)                                       (0x00000010&((data)<<4))
#define  ISO_MISC_OFF_UART_U0LCR_pen(data)                                       (0x00000008&((data)<<3))
#define  ISO_MISC_OFF_UART_U0LCR_stb(data)                                       (0x00000004&((data)<<2))
#define  ISO_MISC_OFF_UART_U0LCR_wls(data)                                       (0x00000003&(data))
#define  ISO_MISC_OFF_UART_U0LCR_get_dlab(data)                                  ((0x00000080&(data))>>7)
#define  ISO_MISC_OFF_UART_U0LCR_get_brk(data)                                   ((0x00000040&(data))>>6)
#define  ISO_MISC_OFF_UART_U0LCR_get_eps(data)                                   ((0x00000010&(data))>>4)
#define  ISO_MISC_OFF_UART_U0LCR_get_pen(data)                                   ((0x00000008&(data))>>3)
#define  ISO_MISC_OFF_UART_U0LCR_get_stb(data)                                   ((0x00000004&(data))>>2)
#define  ISO_MISC_OFF_UART_U0LCR_get_wls(data)                                   (0x00000003&(data))

#define  ISO_MISC_OFF_UART_U0MCR                                                 0x18062310
#define  ISO_MISC_OFF_UART_U0MCR_reg_addr                                        "0xB8062310"
#define  ISO_MISC_OFF_UART_U0MCR_reg                                             0xB8062310
#define  ISO_MISC_OFF_UART_U0MCR_inst_addr                                       "0x0004"
#define  set_ISO_MISC_OFF_UART_U0MCR_reg(data)                                   (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0MCR_reg)=data)
#define  get_ISO_MISC_OFF_UART_U0MCR_reg                                         (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0MCR_reg))
#define  ISO_MISC_OFF_UART_U0MCR_afce_shift                                      (5)
#define  ISO_MISC_OFF_UART_U0MCR_loop_shift                                      (4)
#define  ISO_MISC_OFF_UART_U0MCR_afce_mask                                       (0x00000020)
#define  ISO_MISC_OFF_UART_U0MCR_loop_mask                                       (0x00000010)
#define  ISO_MISC_OFF_UART_U0MCR_afce(data)                                      (0x00000020&((data)<<5))
#define  ISO_MISC_OFF_UART_U0MCR_loop(data)                                      (0x00000010&((data)<<4))
#define  ISO_MISC_OFF_UART_U0MCR_get_afce(data)                                  ((0x00000020&(data))>>5)
#define  ISO_MISC_OFF_UART_U0MCR_get_loop(data)                                  ((0x00000010&(data))>>4)

#define  ISO_MISC_OFF_UART_U0LSR                                                 0x18062314
#define  ISO_MISC_OFF_UART_U0LSR_reg_addr                                        "0xB8062314"
#define  ISO_MISC_OFF_UART_U0LSR_reg                                             0xB8062314
#define  ISO_MISC_OFF_UART_U0LSR_inst_addr                                       "0x0005"
#define  set_ISO_MISC_OFF_UART_U0LSR_reg(data)                                   (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0LSR_reg)=data)
#define  get_ISO_MISC_OFF_UART_U0LSR_reg                                         (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0LSR_reg))
#define  ISO_MISC_OFF_UART_U0LSR_rfe_shift                                       (7)
#define  ISO_MISC_OFF_UART_U0LSR_temt_shift                                      (6)
#define  ISO_MISC_OFF_UART_U0LSR_thre_shift                                      (5)
#define  ISO_MISC_OFF_UART_U0LSR_bi_shift                                        (4)
#define  ISO_MISC_OFF_UART_U0LSR_fe_shift                                        (3)
#define  ISO_MISC_OFF_UART_U0LSR_pe_shift                                        (2)
#define  ISO_MISC_OFF_UART_U0LSR_oe_shift                                        (1)
#define  ISO_MISC_OFF_UART_U0LSR_dr_shift                                        (0)
#define  ISO_MISC_OFF_UART_U0LSR_rfe_mask                                        (0x00000080)
#define  ISO_MISC_OFF_UART_U0LSR_temt_mask                                       (0x00000040)
#define  ISO_MISC_OFF_UART_U0LSR_thre_mask                                       (0x00000020)
#define  ISO_MISC_OFF_UART_U0LSR_bi_mask                                         (0x00000010)
#define  ISO_MISC_OFF_UART_U0LSR_fe_mask                                         (0x00000008)
#define  ISO_MISC_OFF_UART_U0LSR_pe_mask                                         (0x00000004)
#define  ISO_MISC_OFF_UART_U0LSR_oe_mask                                         (0x00000002)
#define  ISO_MISC_OFF_UART_U0LSR_dr_mask                                         (0x00000001)
#define  ISO_MISC_OFF_UART_U0LSR_rfe(data)                                       (0x00000080&((data)<<7))
#define  ISO_MISC_OFF_UART_U0LSR_temt(data)                                      (0x00000040&((data)<<6))
#define  ISO_MISC_OFF_UART_U0LSR_thre(data)                                      (0x00000020&((data)<<5))
#define  ISO_MISC_OFF_UART_U0LSR_bi(data)                                        (0x00000010&((data)<<4))
#define  ISO_MISC_OFF_UART_U0LSR_fe(data)                                        (0x00000008&((data)<<3))
#define  ISO_MISC_OFF_UART_U0LSR_pe(data)                                        (0x00000004&((data)<<2))
#define  ISO_MISC_OFF_UART_U0LSR_oe(data)                                        (0x00000002&((data)<<1))
#define  ISO_MISC_OFF_UART_U0LSR_dr(data)                                        (0x00000001&(data))
#define  ISO_MISC_OFF_UART_U0LSR_get_rfe(data)                                   ((0x00000080&(data))>>7)
#define  ISO_MISC_OFF_UART_U0LSR_get_temt(data)                                  ((0x00000040&(data))>>6)
#define  ISO_MISC_OFF_UART_U0LSR_get_thre(data)                                  ((0x00000020&(data))>>5)
#define  ISO_MISC_OFF_UART_U0LSR_get_bi(data)                                    ((0x00000010&(data))>>4)
#define  ISO_MISC_OFF_UART_U0LSR_get_fe(data)                                    ((0x00000008&(data))>>3)
#define  ISO_MISC_OFF_UART_U0LSR_get_pe(data)                                    ((0x00000004&(data))>>2)
#define  ISO_MISC_OFF_UART_U0LSR_get_oe(data)                                    ((0x00000002&(data))>>1)
#define  ISO_MISC_OFF_UART_U0LSR_get_dr(data)                                    (0x00000001&(data))

#define  ISO_MISC_OFF_UART_U0MSR                                                 0x18062318
#define  ISO_MISC_OFF_UART_U0MSR_reg_addr                                        "0xB8062318"
#define  ISO_MISC_OFF_UART_U0MSR_reg                                             0xB8062318
#define  ISO_MISC_OFF_UART_U0MSR_inst_addr                                       "0x0006"
#define  set_ISO_MISC_OFF_UART_U0MSR_reg(data)                                   (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0MSR_reg)=data)
#define  get_ISO_MISC_OFF_UART_U0MSR_reg                                         (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0MSR_reg))
#define  ISO_MISC_OFF_UART_U0MSR_ddcd_shift                                      (3)
#define  ISO_MISC_OFF_UART_U0MSR_teri_shift                                      (2)
#define  ISO_MISC_OFF_UART_U0MSR_ddsr_shift                                      (1)
#define  ISO_MISC_OFF_UART_U0MSR_dcts_shift                                      (0)
#define  ISO_MISC_OFF_UART_U0MSR_ddcd_mask                                       (0x00000008)
#define  ISO_MISC_OFF_UART_U0MSR_teri_mask                                       (0x00000004)
#define  ISO_MISC_OFF_UART_U0MSR_ddsr_mask                                       (0x00000002)
#define  ISO_MISC_OFF_UART_U0MSR_dcts_mask                                       (0x00000001)
#define  ISO_MISC_OFF_UART_U0MSR_ddcd(data)                                      (0x00000008&((data)<<3))
#define  ISO_MISC_OFF_UART_U0MSR_teri(data)                                      (0x00000004&((data)<<2))
#define  ISO_MISC_OFF_UART_U0MSR_ddsr(data)                                      (0x00000002&((data)<<1))
#define  ISO_MISC_OFF_UART_U0MSR_dcts(data)                                      (0x00000001&(data))
#define  ISO_MISC_OFF_UART_U0MSR_get_ddcd(data)                                  ((0x00000008&(data))>>3)
#define  ISO_MISC_OFF_UART_U0MSR_get_teri(data)                                  ((0x00000004&(data))>>2)
#define  ISO_MISC_OFF_UART_U0MSR_get_ddsr(data)                                  ((0x00000002&(data))>>1)
#define  ISO_MISC_OFF_UART_U0MSR_get_dcts(data)                                  (0x00000001&(data))

#define  ISO_MISC_OFF_UART_U0SCR                                                 0x1806231C
#define  ISO_MISC_OFF_UART_U0SCR_reg_addr                                        "0xB806231C"
#define  ISO_MISC_OFF_UART_U0SCR_reg                                             0xB806231C
#define  ISO_MISC_OFF_UART_U0SCR_inst_addr                                       "0x0007"
#define  set_ISO_MISC_OFF_UART_U0SCR_reg(data)                                   (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0SCR_reg)=data)
#define  get_ISO_MISC_OFF_UART_U0SCR_reg                                         (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0SCR_reg))
#define  ISO_MISC_OFF_UART_U0SCR_scr_shift                                       (0)
#define  ISO_MISC_OFF_UART_U0SCR_scr_mask                                        (0x000000FF)
#define  ISO_MISC_OFF_UART_U0SCR_scr(data)                                       (0x000000FF&(data))
#define  ISO_MISC_OFF_UART_U0SCR_get_scr(data)                                   (0x000000FF&(data))

#define  ISO_MISC_OFF_UART_U0SRBR                                                0x18062330
#define  ISO_MISC_OFF_UART_U0SRBR_reg_addr                                       "0xB8062330"
#define  ISO_MISC_OFF_UART_U0SRBR_reg                                            0xB8062330
#define  ISO_MISC_OFF_UART_U0SRBR_inst_addr                                      "0x0008"
#define  set_ISO_MISC_OFF_UART_U0SRBR_reg(data)                                  (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0SRBR_reg)=data)
#define  get_ISO_MISC_OFF_UART_U0SRBR_reg                                        (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0SRBR_reg))
#define  ISO_MISC_OFF_UART_U0SRBR_rbd_shift                                      (0)
#define  ISO_MISC_OFF_UART_U0SRBR_rbd_mask                                       (0x000000FF)
#define  ISO_MISC_OFF_UART_U0SRBR_rbd(data)                                      (0x000000FF&(data))
#define  ISO_MISC_OFF_UART_U0SRBR_get_rbd(data)                                  (0x000000FF&(data))

#define  ISO_MISC_OFF_UART_U0FAR                                                 0x18062370
#define  ISO_MISC_OFF_UART_U0FAR_reg_addr                                        "0xB8062370"
#define  ISO_MISC_OFF_UART_U0FAR_reg                                             0xB8062370
#define  ISO_MISC_OFF_UART_U0FAR_inst_addr                                       "0x0009"
#define  set_ISO_MISC_OFF_UART_U0FAR_reg(data)                                   (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0FAR_reg)=data)
#define  get_ISO_MISC_OFF_UART_U0FAR_reg                                         (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0FAR_reg))
#define  ISO_MISC_OFF_UART_U0FAR_far_shift                                       (0)
#define  ISO_MISC_OFF_UART_U0FAR_far_mask                                        (0x00000001)
#define  ISO_MISC_OFF_UART_U0FAR_far(data)                                       (0x00000001&(data))
#define  ISO_MISC_OFF_UART_U0FAR_get_far(data)                                   (0x00000001&(data))

#define  ISO_MISC_OFF_UART_U0TFR                                                 0x18062374
#define  ISO_MISC_OFF_UART_U0TFR_reg_addr                                        "0xB8062374"
#define  ISO_MISC_OFF_UART_U0TFR_reg                                             0xB8062374
#define  ISO_MISC_OFF_UART_U0TFR_inst_addr                                       "0x000A"
#define  set_ISO_MISC_OFF_UART_U0TFR_reg(data)                                   (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0TFR_reg)=data)
#define  get_ISO_MISC_OFF_UART_U0TFR_reg                                         (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0TFR_reg))
#define  ISO_MISC_OFF_UART_U0TFR_far_shift                                       (0)
#define  ISO_MISC_OFF_UART_U0TFR_far_mask                                        (0x000000FF)
#define  ISO_MISC_OFF_UART_U0TFR_far(data)                                       (0x000000FF&(data))
#define  ISO_MISC_OFF_UART_U0TFR_get_far(data)                                   (0x000000FF&(data))

#define  ISO_MISC_OFF_UART_U0RFW                                                 0x18062378
#define  ISO_MISC_OFF_UART_U0RFW_reg_addr                                        "0xB8062378"
#define  ISO_MISC_OFF_UART_U0RFW_reg                                             0xB8062378
#define  ISO_MISC_OFF_UART_U0RFW_inst_addr                                       "0x000B"
#define  set_ISO_MISC_OFF_UART_U0RFW_reg(data)                                   (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0RFW_reg)=data)
#define  get_ISO_MISC_OFF_UART_U0RFW_reg                                         (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0RFW_reg))
#define  ISO_MISC_OFF_UART_U0RFW_rffe_shift                                      (9)
#define  ISO_MISC_OFF_UART_U0RFW_rfpf_shift                                      (8)
#define  ISO_MISC_OFF_UART_U0RFW_rfwd_shift                                      (0)
#define  ISO_MISC_OFF_UART_U0RFW_rffe_mask                                       (0x00000200)
#define  ISO_MISC_OFF_UART_U0RFW_rfpf_mask                                       (0x00000100)
#define  ISO_MISC_OFF_UART_U0RFW_rfwd_mask                                       (0x000000FF)
#define  ISO_MISC_OFF_UART_U0RFW_rffe(data)                                      (0x00000200&((data)<<9))
#define  ISO_MISC_OFF_UART_U0RFW_rfpf(data)                                      (0x00000100&((data)<<8))
#define  ISO_MISC_OFF_UART_U0RFW_rfwd(data)                                      (0x000000FF&(data))
#define  ISO_MISC_OFF_UART_U0RFW_get_rffe(data)                                  ((0x00000200&(data))>>9)
#define  ISO_MISC_OFF_UART_U0RFW_get_rfpf(data)                                  ((0x00000100&(data))>>8)
#define  ISO_MISC_OFF_UART_U0RFW_get_rfwd(data)                                  (0x000000FF&(data))

#define  ISO_MISC_OFF_UART_U0USR                                                 0x1806237C
#define  ISO_MISC_OFF_UART_U0USR_reg_addr                                        "0xB806237C"
#define  ISO_MISC_OFF_UART_U0USR_reg                                             0xB806237C
#define  ISO_MISC_OFF_UART_U0USR_inst_addr                                       "0x000C"
#define  set_ISO_MISC_OFF_UART_U0USR_reg(data)                                   (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0USR_reg)=data)
#define  get_ISO_MISC_OFF_UART_U0USR_reg                                         (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0USR_reg))
#define  ISO_MISC_OFF_UART_U0USR_rff_shift                                       (4)
#define  ISO_MISC_OFF_UART_U0USR_rfne_shift                                      (3)
#define  ISO_MISC_OFF_UART_U0USR_tfe_shift                                       (2)
#define  ISO_MISC_OFF_UART_U0USR_tfnf_shift                                      (1)
#define  ISO_MISC_OFF_UART_U0USR_busy_shift                                      (0)
#define  ISO_MISC_OFF_UART_U0USR_rff_mask                                        (0x00000010)
#define  ISO_MISC_OFF_UART_U0USR_rfne_mask                                       (0x00000008)
#define  ISO_MISC_OFF_UART_U0USR_tfe_mask                                        (0x00000004)
#define  ISO_MISC_OFF_UART_U0USR_tfnf_mask                                       (0x00000002)
#define  ISO_MISC_OFF_UART_U0USR_busy_mask                                       (0x00000001)
#define  ISO_MISC_OFF_UART_U0USR_rff(data)                                       (0x00000010&((data)<<4))
#define  ISO_MISC_OFF_UART_U0USR_rfne(data)                                      (0x00000008&((data)<<3))
#define  ISO_MISC_OFF_UART_U0USR_tfe(data)                                       (0x00000004&((data)<<2))
#define  ISO_MISC_OFF_UART_U0USR_tfnf(data)                                      (0x00000002&((data)<<1))
#define  ISO_MISC_OFF_UART_U0USR_busy(data)                                      (0x00000001&(data))
#define  ISO_MISC_OFF_UART_U0USR_get_rff(data)                                   ((0x00000010&(data))>>4)
#define  ISO_MISC_OFF_UART_U0USR_get_rfne(data)                                  ((0x00000008&(data))>>3)
#define  ISO_MISC_OFF_UART_U0USR_get_tfe(data)                                   ((0x00000004&(data))>>2)
#define  ISO_MISC_OFF_UART_U0USR_get_tfnf(data)                                  ((0x00000002&(data))>>1)
#define  ISO_MISC_OFF_UART_U0USR_get_busy(data)                                  (0x00000001&(data))

#define  ISO_MISC_OFF_UART_U0TFL                                                 0x18062380
#define  ISO_MISC_OFF_UART_U0TFL_reg_addr                                        "0xB8062380"
#define  ISO_MISC_OFF_UART_U0TFL_reg                                             0xB8062380
#define  ISO_MISC_OFF_UART_U0TFL_inst_addr                                       "0x000D"
#define  set_ISO_MISC_OFF_UART_U0TFL_reg(data)                                   (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0TFL_reg)=data)
#define  get_ISO_MISC_OFF_UART_U0TFL_reg                                         (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0TFL_reg))
#define  ISO_MISC_OFF_UART_U0TFL_tfl_shift                                       (0)
#define  ISO_MISC_OFF_UART_U0TFL_tfl_mask                                        (0x000000FF)
#define  ISO_MISC_OFF_UART_U0TFL_tfl(data)                                       (0x000000FF&(data))
#define  ISO_MISC_OFF_UART_U0TFL_get_tfl(data)                                   (0x000000FF&(data))

#define  ISO_MISC_OFF_UART_U0RFL                                                 0x18062384
#define  ISO_MISC_OFF_UART_U0RFL_reg_addr                                        "0xB8062384"
#define  ISO_MISC_OFF_UART_U0RFL_reg                                             0xB8062384
#define  ISO_MISC_OFF_UART_U0RFL_inst_addr                                       "0x000E"
#define  set_ISO_MISC_OFF_UART_U0RFL_reg(data)                                   (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0RFL_reg)=data)
#define  get_ISO_MISC_OFF_UART_U0RFL_reg                                         (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0RFL_reg))
#define  ISO_MISC_OFF_UART_U0RFL_rfl_shift                                       (0)
#define  ISO_MISC_OFF_UART_U0RFL_rfl_mask                                        (0x000000FF)
#define  ISO_MISC_OFF_UART_U0RFL_rfl(data)                                       (0x000000FF&(data))
#define  ISO_MISC_OFF_UART_U0RFL_get_rfl(data)                                   (0x000000FF&(data))

#define  ISO_MISC_OFF_UART_U0SRR                                                 0x18062388
#define  ISO_MISC_OFF_UART_U0SRR_reg_addr                                        "0xB8062388"
#define  ISO_MISC_OFF_UART_U0SRR_reg                                             0xB8062388
#define  ISO_MISC_OFF_UART_U0SRR_inst_addr                                       "0x000F"
#define  set_ISO_MISC_OFF_UART_U0SRR_reg(data)                                   (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0SRR_reg)=data)
#define  get_ISO_MISC_OFF_UART_U0SRR_reg                                         (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0SRR_reg))
#define  ISO_MISC_OFF_UART_U0SRR_xfr_shift                                       (2)
#define  ISO_MISC_OFF_UART_U0SRR_rfr_shift                                       (1)
#define  ISO_MISC_OFF_UART_U0SRR_ur_shift                                        (0)
#define  ISO_MISC_OFF_UART_U0SRR_xfr_mask                                        (0x00000004)
#define  ISO_MISC_OFF_UART_U0SRR_rfr_mask                                        (0x00000002)
#define  ISO_MISC_OFF_UART_U0SRR_ur_mask                                         (0x00000001)
#define  ISO_MISC_OFF_UART_U0SRR_xfr(data)                                       (0x00000004&((data)<<2))
#define  ISO_MISC_OFF_UART_U0SRR_rfr(data)                                       (0x00000002&((data)<<1))
#define  ISO_MISC_OFF_UART_U0SRR_ur(data)                                        (0x00000001&(data))
#define  ISO_MISC_OFF_UART_U0SRR_get_xfr(data)                                   ((0x00000004&(data))>>2)
#define  ISO_MISC_OFF_UART_U0SRR_get_rfr(data)                                   ((0x00000002&(data))>>1)
#define  ISO_MISC_OFF_UART_U0SRR_get_ur(data)                                    (0x00000001&(data))

#define  ISO_MISC_OFF_UART_U0SBCR                                                0x18062390
#define  ISO_MISC_OFF_UART_U0SBCR_reg_addr                                       "0xB8062390"
#define  ISO_MISC_OFF_UART_U0SBCR_reg                                            0xB8062390
#define  ISO_MISC_OFF_UART_U0SBCR_inst_addr                                      "0x0010"
#define  set_ISO_MISC_OFF_UART_U0SBCR_reg(data)                                  (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0SBCR_reg)=data)
#define  get_ISO_MISC_OFF_UART_U0SBCR_reg                                        (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0SBCR_reg))
#define  ISO_MISC_OFF_UART_U0SBCR_sbcr_shift                                     (0)
#define  ISO_MISC_OFF_UART_U0SBCR_sbcr_mask                                      (0x00000001)
#define  ISO_MISC_OFF_UART_U0SBCR_sbcr(data)                                     (0x00000001&(data))
#define  ISO_MISC_OFF_UART_U0SBCR_get_sbcr(data)                                 (0x00000001&(data))

#define  ISO_MISC_OFF_UART_U0SDMAM                                               0x18062394
#define  ISO_MISC_OFF_UART_U0SDMAM_reg_addr                                      "0xB8062394"
#define  ISO_MISC_OFF_UART_U0SDMAM_reg                                           0xB8062394
#define  ISO_MISC_OFF_UART_U0SDMAM_inst_addr                                     "0x0011"
#define  set_ISO_MISC_OFF_UART_U0SDMAM_reg(data)                                 (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0SDMAM_reg)=data)
#define  get_ISO_MISC_OFF_UART_U0SDMAM_reg                                       (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0SDMAM_reg))
#define  ISO_MISC_OFF_UART_U0SDMAM_sdmam_shift                                   (0)
#define  ISO_MISC_OFF_UART_U0SDMAM_sdmam_mask                                    (0x00000001)
#define  ISO_MISC_OFF_UART_U0SDMAM_sdmam(data)                                   (0x00000001&(data))
#define  ISO_MISC_OFF_UART_U0SDMAM_get_sdmam(data)                               (0x00000001&(data))

#define  ISO_MISC_OFF_UART_U0SFE                                                 0x18062398
#define  ISO_MISC_OFF_UART_U0SFE_reg_addr                                        "0xB8062398"
#define  ISO_MISC_OFF_UART_U0SFE_reg                                             0xB8062398
#define  ISO_MISC_OFF_UART_U0SFE_inst_addr                                       "0x0012"
#define  set_ISO_MISC_OFF_UART_U0SFE_reg(data)                                   (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0SFE_reg)=data)
#define  get_ISO_MISC_OFF_UART_U0SFE_reg                                         (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0SFE_reg))
#define  ISO_MISC_OFF_UART_U0SFE_sfe_shift                                       (0)
#define  ISO_MISC_OFF_UART_U0SFE_sfe_mask                                        (0x00000001)
#define  ISO_MISC_OFF_UART_U0SFE_sfe(data)                                       (0x00000001&(data))
#define  ISO_MISC_OFF_UART_U0SFE_get_sfe(data)                                   (0x00000001&(data))

#define  ISO_MISC_OFF_UART_U0SRT                                                 0x1806239C
#define  ISO_MISC_OFF_UART_U0SRT_reg_addr                                        "0xB806239C"
#define  ISO_MISC_OFF_UART_U0SRT_reg                                             0xB806239C
#define  ISO_MISC_OFF_UART_U0SRT_inst_addr                                       "0x0013"
#define  set_ISO_MISC_OFF_UART_U0SRT_reg(data)                                   (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0SRT_reg)=data)
#define  get_ISO_MISC_OFF_UART_U0SRT_reg                                         (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0SRT_reg))
#define  ISO_MISC_OFF_UART_U0SRT_srt_shift                                       (0)
#define  ISO_MISC_OFF_UART_U0SRT_srt_mask                                        (0x00000003)
#define  ISO_MISC_OFF_UART_U0SRT_srt(data)                                       (0x00000003&(data))
#define  ISO_MISC_OFF_UART_U0SRT_get_srt(data)                                   (0x00000003&(data))

#define  ISO_MISC_OFF_UART_U0STET                                                0x180623A0
#define  ISO_MISC_OFF_UART_U0STET_reg_addr                                       "0xB80623A0"
#define  ISO_MISC_OFF_UART_U0STET_reg                                            0xB80623A0
#define  ISO_MISC_OFF_UART_U0STET_inst_addr                                      "0x0014"
#define  set_ISO_MISC_OFF_UART_U0STET_reg(data)                                  (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0STET_reg)=data)
#define  get_ISO_MISC_OFF_UART_U0STET_reg                                        (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0STET_reg))
#define  ISO_MISC_OFF_UART_U0STET_stet_shift                                     (0)
#define  ISO_MISC_OFF_UART_U0STET_stet_mask                                      (0x00000003)
#define  ISO_MISC_OFF_UART_U0STET_stet(data)                                     (0x00000003&(data))
#define  ISO_MISC_OFF_UART_U0STET_get_stet(data)                                 (0x00000003&(data))

#define  ISO_MISC_OFF_UART_U0HTX                                                 0x180623A4
#define  ISO_MISC_OFF_UART_U0HTX_reg_addr                                        "0xB80623A4"
#define  ISO_MISC_OFF_UART_U0HTX_reg                                             0xB80623A4
#define  ISO_MISC_OFF_UART_U0HTX_inst_addr                                       "0x0015"
#define  set_ISO_MISC_OFF_UART_U0HTX_reg(data)                                   (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0HTX_reg)=data)
#define  get_ISO_MISC_OFF_UART_U0HTX_reg                                         (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0HTX_reg))
#define  ISO_MISC_OFF_UART_U0HTX_htx_shift                                       (0)
#define  ISO_MISC_OFF_UART_U0HTX_htx_mask                                        (0x00000001)
#define  ISO_MISC_OFF_UART_U0HTX_htx(data)                                       (0x00000001&(data))
#define  ISO_MISC_OFF_UART_U0HTX_get_htx(data)                                   (0x00000001&(data))

#define  ISO_MISC_OFF_UART_U0DMASA                                               0x180623A8
#define  ISO_MISC_OFF_UART_U0DMASA_reg_addr                                      "0xB80623A8"
#define  ISO_MISC_OFF_UART_U0DMASA_reg                                           0xB80623A8
#define  ISO_MISC_OFF_UART_U0DMASA_inst_addr                                     "0x0016"
#define  set_ISO_MISC_OFF_UART_U0DMASA_reg(data)                                 (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0DMASA_reg)=data)
#define  get_ISO_MISC_OFF_UART_U0DMASA_reg                                       (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0DMASA_reg))
#define  ISO_MISC_OFF_UART_U0DMASA_dmasa_shift                                   (0)
#define  ISO_MISC_OFF_UART_U0DMASA_dmasa_mask                                    (0x00000001)
#define  ISO_MISC_OFF_UART_U0DMASA_dmasa(data)                                   (0x00000001&(data))
#define  ISO_MISC_OFF_UART_U0DMASA_get_dmasa(data)                               (0x00000001&(data))

#define  ISO_MISC_OFF_UART_U0CPR                                                 0x180623F4
#define  ISO_MISC_OFF_UART_U0CPR_reg_addr                                        "0xB80623F4"
#define  ISO_MISC_OFF_UART_U0CPR_reg                                             0xB80623F4
#define  ISO_MISC_OFF_UART_U0CPR_inst_addr                                       "0x0017"
#define  set_ISO_MISC_OFF_UART_U0CPR_reg(data)                                   (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0CPR_reg)=data)
#define  get_ISO_MISC_OFF_UART_U0CPR_reg                                         (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0CPR_reg))
#define  ISO_MISC_OFF_UART_U0CPR_fifo_mode_shift                                 (16)
#define  ISO_MISC_OFF_UART_U0CPR_dma_extra_shift                                 (13)
#define  ISO_MISC_OFF_UART_U0CPR_uart_add_encoded_params_shift                   (12)
#define  ISO_MISC_OFF_UART_U0CPR_shadow_shift                                    (11)
#define  ISO_MISC_OFF_UART_U0CPR_fifo_stat_shift                                 (10)
#define  ISO_MISC_OFF_UART_U0CPR_fifo_access_shift                               (9)
#define  ISO_MISC_OFF_UART_U0CPR_additional_feat_shift                           (8)
#define  ISO_MISC_OFF_UART_U0CPR_sir_lp_mode_shift                               (7)
#define  ISO_MISC_OFF_UART_U0CPR_sir_mode_shift                                  (6)
#define  ISO_MISC_OFF_UART_U0CPR_thre_mode_shift                                 (5)
#define  ISO_MISC_OFF_UART_U0CPR_afce_mode_shift                                 (4)
#define  ISO_MISC_OFF_UART_U0CPR_apb_data_width_shift                            (0)
#define  ISO_MISC_OFF_UART_U0CPR_fifo_mode_mask                                  (0x00FF0000)
#define  ISO_MISC_OFF_UART_U0CPR_dma_extra_mask                                  (0x00002000)
#define  ISO_MISC_OFF_UART_U0CPR_uart_add_encoded_params_mask                    (0x00001000)
#define  ISO_MISC_OFF_UART_U0CPR_shadow_mask                                     (0x00000800)
#define  ISO_MISC_OFF_UART_U0CPR_fifo_stat_mask                                  (0x00000400)
#define  ISO_MISC_OFF_UART_U0CPR_fifo_access_mask                                (0x00000200)
#define  ISO_MISC_OFF_UART_U0CPR_additional_feat_mask                            (0x00000100)
#define  ISO_MISC_OFF_UART_U0CPR_sir_lp_mode_mask                                (0x00000080)
#define  ISO_MISC_OFF_UART_U0CPR_sir_mode_mask                                   (0x00000040)
#define  ISO_MISC_OFF_UART_U0CPR_thre_mode_mask                                  (0x00000020)
#define  ISO_MISC_OFF_UART_U0CPR_afce_mode_mask                                  (0x00000010)
#define  ISO_MISC_OFF_UART_U0CPR_apb_data_width_mask                             (0x00000003)
#define  ISO_MISC_OFF_UART_U0CPR_fifo_mode(data)                                 (0x00FF0000&((data)<<16))
#define  ISO_MISC_OFF_UART_U0CPR_dma_extra(data)                                 (0x00002000&((data)<<13))
#define  ISO_MISC_OFF_UART_U0CPR_uart_add_encoded_params(data)                   (0x00001000&((data)<<12))
#define  ISO_MISC_OFF_UART_U0CPR_shadow(data)                                    (0x00000800&((data)<<11))
#define  ISO_MISC_OFF_UART_U0CPR_fifo_stat(data)                                 (0x00000400&((data)<<10))
#define  ISO_MISC_OFF_UART_U0CPR_fifo_access(data)                               (0x00000200&((data)<<9))
#define  ISO_MISC_OFF_UART_U0CPR_additional_feat(data)                           (0x00000100&((data)<<8))
#define  ISO_MISC_OFF_UART_U0CPR_sir_lp_mode(data)                               (0x00000080&((data)<<7))
#define  ISO_MISC_OFF_UART_U0CPR_sir_mode(data)                                  (0x00000040&((data)<<6))
#define  ISO_MISC_OFF_UART_U0CPR_thre_mode(data)                                 (0x00000020&((data)<<5))
#define  ISO_MISC_OFF_UART_U0CPR_afce_mode(data)                                 (0x00000010&((data)<<4))
#define  ISO_MISC_OFF_UART_U0CPR_apb_data_width(data)                            (0x00000003&(data))
#define  ISO_MISC_OFF_UART_U0CPR_get_fifo_mode(data)                             ((0x00FF0000&(data))>>16)
#define  ISO_MISC_OFF_UART_U0CPR_get_dma_extra(data)                             ((0x00002000&(data))>>13)
#define  ISO_MISC_OFF_UART_U0CPR_get_uart_add_encoded_params(data)               ((0x00001000&(data))>>12)
#define  ISO_MISC_OFF_UART_U0CPR_get_shadow(data)                                ((0x00000800&(data))>>11)
#define  ISO_MISC_OFF_UART_U0CPR_get_fifo_stat(data)                             ((0x00000400&(data))>>10)
#define  ISO_MISC_OFF_UART_U0CPR_get_fifo_access(data)                           ((0x00000200&(data))>>9)
#define  ISO_MISC_OFF_UART_U0CPR_get_additional_feat(data)                       ((0x00000100&(data))>>8)
#define  ISO_MISC_OFF_UART_U0CPR_get_sir_lp_mode(data)                           ((0x00000080&(data))>>7)
#define  ISO_MISC_OFF_UART_U0CPR_get_sir_mode(data)                              ((0x00000040&(data))>>6)
#define  ISO_MISC_OFF_UART_U0CPR_get_thre_mode(data)                             ((0x00000020&(data))>>5)
#define  ISO_MISC_OFF_UART_U0CPR_get_afce_mode(data)                             ((0x00000010&(data))>>4)
#define  ISO_MISC_OFF_UART_U0CPR_get_apb_data_width(data)                        (0x00000003&(data))

#define  ISO_MISC_OFF_UART_U0UCV                                                 0x180623F8
#define  ISO_MISC_OFF_UART_U0UCV_reg_addr                                        "0xB80623F8"
#define  ISO_MISC_OFF_UART_U0UCV_reg                                             0xB80623F8
#define  ISO_MISC_OFF_UART_U0UCV_inst_addr                                       "0x0018"
#define  set_ISO_MISC_OFF_UART_U0UCV_reg(data)                                   (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0UCV_reg)=data)
#define  get_ISO_MISC_OFF_UART_U0UCV_reg                                         (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0UCV_reg))
#define  ISO_MISC_OFF_UART_U0UCV_ucv_shift                                       (0)
#define  ISO_MISC_OFF_UART_U0UCV_ucv_mask                                        (0xFFFFFFFF)
#define  ISO_MISC_OFF_UART_U0UCV_ucv(data)                                       (0xFFFFFFFF&(data))
#define  ISO_MISC_OFF_UART_U0UCV_get_ucv(data)                                   (0xFFFFFFFF&(data))

#define  ISO_MISC_OFF_UART_U0CTR                                                 0x180623FC
#define  ISO_MISC_OFF_UART_U0CTR_reg_addr                                        "0xB80623FC"
#define  ISO_MISC_OFF_UART_U0CTR_reg                                             0xB80623FC
#define  ISO_MISC_OFF_UART_U0CTR_inst_addr                                       "0x0019"
#define  set_ISO_MISC_OFF_UART_U0CTR_reg(data)                                   (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0CTR_reg)=data)
#define  get_ISO_MISC_OFF_UART_U0CTR_reg                                         (*((volatile unsigned int*)ISO_MISC_OFF_UART_U0CTR_reg))
#define  ISO_MISC_OFF_UART_U0CTR_ctr_shift                                       (0)
#define  ISO_MISC_OFF_UART_U0CTR_ctr_mask                                        (0xFFFFFFFF)
#define  ISO_MISC_OFF_UART_U0CTR_ctr(data)                                       (0xFFFFFFFF&(data))
#define  ISO_MISC_OFF_UART_U0CTR_get_ctr(data)                                   (0xFFFFFFFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======ISO_MISC_OFF_UART register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dll:8;
    };
}iso_misc_off_uart_u0rbr_thr_dll_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dlh:8;
    };
}iso_misc_off_uart_u0ier_dlh_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  fifo16:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  iid:4;
    };
}iso_misc_off_uart_u0iir_fcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dlab:1;
        RBus_UInt32  brk:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  eps:1;
        RBus_UInt32  pen:1;
        RBus_UInt32  stb:1;
        RBus_UInt32  wls:2;
    };
}iso_misc_off_uart_u0lcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  afce:1;
        RBus_UInt32  loop:1;
        RBus_UInt32  res2:4;
    };
}iso_misc_off_uart_u0mcr_RBUS;

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
}iso_misc_off_uart_u0lsr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  ddcd:1;
        RBus_UInt32  teri:1;
        RBus_UInt32  ddsr:1;
        RBus_UInt32  dcts:1;
    };
}iso_misc_off_uart_u0msr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  scr:8;
    };
}iso_misc_off_uart_u0scr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  rbd:8;
    };
}iso_misc_off_uart_u0srbr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  far:1;
    };
}iso_misc_off_uart_u0far_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  far:8;
    };
}iso_misc_off_uart_u0tfr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  rffe:1;
        RBus_UInt32  rfpf:1;
        RBus_UInt32  rfwd:8;
    };
}iso_misc_off_uart_u0rfw_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  rff:1;
        RBus_UInt32  rfne:1;
        RBus_UInt32  tfe:1;
        RBus_UInt32  tfnf:1;
        RBus_UInt32  busy:1;
    };
}iso_misc_off_uart_u0usr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  tfl:8;
    };
}iso_misc_off_uart_u0tfl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  rfl:8;
    };
}iso_misc_off_uart_u0rfl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  xfr:1;
        RBus_UInt32  rfr:1;
        RBus_UInt32  ur:1;
    };
}iso_misc_off_uart_u0srr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  sbcr:1;
    };
}iso_misc_off_uart_u0sbcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  sdmam:1;
    };
}iso_misc_off_uart_u0sdmam_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  sfe:1;
    };
}iso_misc_off_uart_u0sfe_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  srt:2;
    };
}iso_misc_off_uart_u0srt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  stet:2;
    };
}iso_misc_off_uart_u0stet_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  htx:1;
    };
}iso_misc_off_uart_u0htx_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  dmasa:1;
    };
}iso_misc_off_uart_u0dmasa_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  fifo_mode:8;
        RBus_UInt32  res2:2;
        RBus_UInt32  dma_extra:1;
        RBus_UInt32  uart_add_encoded_params:1;
        RBus_UInt32  shadow:1;
        RBus_UInt32  fifo_stat:1;
        RBus_UInt32  fifo_access:1;
        RBus_UInt32  additional_feat:1;
        RBus_UInt32  sir_lp_mode:1;
        RBus_UInt32  sir_mode:1;
        RBus_UInt32  thre_mode:1;
        RBus_UInt32  afce_mode:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  apb_data_width:2;
    };
}iso_misc_off_uart_u0cpr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ucv:32;
    };
}iso_misc_off_uart_u0ucv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ctr:32;
    };
}iso_misc_off_uart_u0ctr_RBUS;

#else //apply LITTLE_ENDIAN

//======ISO_MISC_OFF_UART register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dll:8;
        RBus_UInt32  res1:24;
    };
}iso_misc_off_uart_u0rbr_thr_dll_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dlh:8;
        RBus_UInt32  res1:24;
    };
}iso_misc_off_uart_u0ier_dlh_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  iid:4;
        RBus_UInt32  res1:2;
        RBus_UInt32  fifo16:2;
        RBus_UInt32  res2:24;
    };
}iso_misc_off_uart_u0iir_fcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wls:2;
        RBus_UInt32  stb:1;
        RBus_UInt32  pen:1;
        RBus_UInt32  eps:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  brk:1;
        RBus_UInt32  dlab:1;
        RBus_UInt32  res2:24;
    };
}iso_misc_off_uart_u0lcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  loop:1;
        RBus_UInt32  afce:1;
        RBus_UInt32  res2:26;
    };
}iso_misc_off_uart_u0mcr_RBUS;

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
}iso_misc_off_uart_u0lsr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dcts:1;
        RBus_UInt32  ddsr:1;
        RBus_UInt32  teri:1;
        RBus_UInt32  ddcd:1;
        RBus_UInt32  res1:28;
    };
}iso_misc_off_uart_u0msr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scr:8;
        RBus_UInt32  res1:24;
    };
}iso_misc_off_uart_u0scr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rbd:8;
        RBus_UInt32  res1:24;
    };
}iso_misc_off_uart_u0srbr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  far:1;
        RBus_UInt32  res1:31;
    };
}iso_misc_off_uart_u0far_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  far:8;
        RBus_UInt32  res1:24;
    };
}iso_misc_off_uart_u0tfr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rfwd:8;
        RBus_UInt32  rfpf:1;
        RBus_UInt32  rffe:1;
        RBus_UInt32  res1:22;
    };
}iso_misc_off_uart_u0rfw_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  busy:1;
        RBus_UInt32  tfnf:1;
        RBus_UInt32  tfe:1;
        RBus_UInt32  rfne:1;
        RBus_UInt32  rff:1;
        RBus_UInt32  res1:27;
    };
}iso_misc_off_uart_u0usr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tfl:8;
        RBus_UInt32  res1:24;
    };
}iso_misc_off_uart_u0tfl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rfl:8;
        RBus_UInt32  res1:24;
    };
}iso_misc_off_uart_u0rfl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ur:1;
        RBus_UInt32  rfr:1;
        RBus_UInt32  xfr:1;
        RBus_UInt32  res1:29;
    };
}iso_misc_off_uart_u0srr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sbcr:1;
        RBus_UInt32  res1:31;
    };
}iso_misc_off_uart_u0sbcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sdmam:1;
        RBus_UInt32  res1:31;
    };
}iso_misc_off_uart_u0sdmam_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfe:1;
        RBus_UInt32  res1:31;
    };
}iso_misc_off_uart_u0sfe_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srt:2;
        RBus_UInt32  res1:30;
    };
}iso_misc_off_uart_u0srt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stet:2;
        RBus_UInt32  res1:30;
    };
}iso_misc_off_uart_u0stet_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  htx:1;
        RBus_UInt32  res1:31;
    };
}iso_misc_off_uart_u0htx_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dmasa:1;
        RBus_UInt32  res1:31;
    };
}iso_misc_off_uart_u0dmasa_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  apb_data_width:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  afce_mode:1;
        RBus_UInt32  thre_mode:1;
        RBus_UInt32  sir_mode:1;
        RBus_UInt32  sir_lp_mode:1;
        RBus_UInt32  additional_feat:1;
        RBus_UInt32  fifo_access:1;
        RBus_UInt32  fifo_stat:1;
        RBus_UInt32  shadow:1;
        RBus_UInt32  uart_add_encoded_params:1;
        RBus_UInt32  dma_extra:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  fifo_mode:8;
        RBus_UInt32  res3:8;
    };
}iso_misc_off_uart_u0cpr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ucv:32;
    };
}iso_misc_off_uart_u0ucv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ctr:32;
    };
}iso_misc_off_uart_u0ctr_RBUS;




#endif 


#endif 
