/**
* @file rbusMdReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/12/14
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_MD_REG_H_
#define _RBUS_MD_REG_H_

#include "rbus_types.h"



//  MD Register Address
#define  MD_MD_SMQ_CNTL                                                          0x1800B000
#define  MD_MD_SMQ_CNTL_reg_addr                                                 "0xB800B000"
#define  MD_MD_SMQ_CNTL_reg                                                      0xB800B000
#define  MD_MD_SMQ_CNTL_inst_addr                                                "0x0000"
#define  set_MD_MD_SMQ_CNTL_reg(data)                                            (*((volatile unsigned int*)MD_MD_SMQ_CNTL_reg)=data)
#define  get_MD_MD_SMQ_CNTL_reg                                                  (*((volatile unsigned int*)MD_MD_SMQ_CNTL_reg))
#define  MD_MD_SMQ_CNTL_smq_idle_shift                                           (3)
#define  MD_MD_SMQ_CNTL_smq_cmd_swap_shift                                       (2)
#define  MD_MD_SMQ_CNTL_smq_go_shift                                             (1)
#define  MD_MD_SMQ_CNTL_write_data_shift                                         (0)
#define  MD_MD_SMQ_CNTL_smq_idle_mask                                            (0x00000008)
#define  MD_MD_SMQ_CNTL_smq_cmd_swap_mask                                        (0x00000004)
#define  MD_MD_SMQ_CNTL_smq_go_mask                                              (0x00000002)
#define  MD_MD_SMQ_CNTL_write_data_mask                                          (0x00000001)
#define  MD_MD_SMQ_CNTL_smq_idle(data)                                           (0x00000008&((data)<<3))
#define  MD_MD_SMQ_CNTL_smq_cmd_swap(data)                                       (0x00000004&((data)<<2))
#define  MD_MD_SMQ_CNTL_smq_go(data)                                             (0x00000002&((data)<<1))
#define  MD_MD_SMQ_CNTL_write_data(data)                                         (0x00000001&(data))
#define  MD_MD_SMQ_CNTL_get_smq_idle(data)                                       ((0x00000008&(data))>>3)
#define  MD_MD_SMQ_CNTL_get_smq_cmd_swap(data)                                   ((0x00000004&(data))>>2)
#define  MD_MD_SMQ_CNTL_get_smq_go(data)                                         ((0x00000002&(data))>>1)
#define  MD_MD_SMQ_CNTL_get_write_data(data)                                     (0x00000001&(data))

#define  MD_MD_SMQ_INT_STATUS                                                    0x1800B004
#define  MD_MD_SMQ_INT_STATUS_reg_addr                                           "0xB800B004"
#define  MD_MD_SMQ_INT_STATUS_reg                                                0xB800B004
#define  MD_MD_SMQ_INT_STATUS_inst_addr                                          "0x0001"
#define  set_MD_MD_SMQ_INT_STATUS_reg(data)                                      (*((volatile unsigned int*)MD_MD_SMQ_INT_STATUS_reg)=data)
#define  get_MD_MD_SMQ_INT_STATUS_reg                                            (*((volatile unsigned int*)MD_MD_SMQ_INT_STATUS_reg))
#define  MD_MD_SMQ_INT_STATUS_fdma_go_busy_shift                                 (10)
#define  MD_MD_SMQ_INT_STATUS_ur_length_err_shift                                (9)
#define  MD_MD_SMQ_INT_STATUS_ur_rx_timeout_shift                                (8)
#define  MD_MD_SMQ_INT_STATUS_ur_rx_thd_shift                                    (7)
#define  MD_MD_SMQ_INT_STATUS_ur_tx_thd_shift                                    (6)
#define  MD_MD_SMQ_INT_STATUS_smq_mode_2b4berr_shift                             (5)
#define  MD_MD_SMQ_INT_STATUS_fdma_done_shift                                    (4)
#define  MD_MD_SMQ_INT_STATUS_smq_empty_shift                                    (3)
#define  MD_MD_SMQ_INT_STATUS_smq_length_err_shift                               (2)
#define  MD_MD_SMQ_INT_STATUS_smq_inst_err_shift                                 (1)
#define  MD_MD_SMQ_INT_STATUS_write_data_shift                                   (0)
#define  MD_MD_SMQ_INT_STATUS_fdma_go_busy_mask                                  (0x00000400)
#define  MD_MD_SMQ_INT_STATUS_ur_length_err_mask                                 (0x00000200)
#define  MD_MD_SMQ_INT_STATUS_ur_rx_timeout_mask                                 (0x00000100)
#define  MD_MD_SMQ_INT_STATUS_ur_rx_thd_mask                                     (0x00000080)
#define  MD_MD_SMQ_INT_STATUS_ur_tx_thd_mask                                     (0x00000040)
#define  MD_MD_SMQ_INT_STATUS_smq_mode_2b4berr_mask                              (0x00000020)
#define  MD_MD_SMQ_INT_STATUS_fdma_done_mask                                     (0x00000010)
#define  MD_MD_SMQ_INT_STATUS_smq_empty_mask                                     (0x00000008)
#define  MD_MD_SMQ_INT_STATUS_smq_length_err_mask                                (0x00000004)
#define  MD_MD_SMQ_INT_STATUS_smq_inst_err_mask                                  (0x00000002)
#define  MD_MD_SMQ_INT_STATUS_write_data_mask                                    (0x00000001)
#define  MD_MD_SMQ_INT_STATUS_fdma_go_busy(data)                                 (0x00000400&((data)<<10))
#define  MD_MD_SMQ_INT_STATUS_ur_length_err(data)                                (0x00000200&((data)<<9))
#define  MD_MD_SMQ_INT_STATUS_ur_rx_timeout(data)                                (0x00000100&((data)<<8))
#define  MD_MD_SMQ_INT_STATUS_ur_rx_thd(data)                                    (0x00000080&((data)<<7))
#define  MD_MD_SMQ_INT_STATUS_ur_tx_thd(data)                                    (0x00000040&((data)<<6))
#define  MD_MD_SMQ_INT_STATUS_smq_mode_2b4berr(data)                             (0x00000020&((data)<<5))
#define  MD_MD_SMQ_INT_STATUS_fdma_done(data)                                    (0x00000010&((data)<<4))
#define  MD_MD_SMQ_INT_STATUS_smq_empty(data)                                    (0x00000008&((data)<<3))
#define  MD_MD_SMQ_INT_STATUS_smq_length_err(data)                               (0x00000004&((data)<<2))
#define  MD_MD_SMQ_INT_STATUS_smq_inst_err(data)                                 (0x00000002&((data)<<1))
#define  MD_MD_SMQ_INT_STATUS_write_data(data)                                   (0x00000001&(data))
#define  MD_MD_SMQ_INT_STATUS_get_fdma_go_busy(data)                             ((0x00000400&(data))>>10)
#define  MD_MD_SMQ_INT_STATUS_get_ur_length_err(data)                            ((0x00000200&(data))>>9)
#define  MD_MD_SMQ_INT_STATUS_get_ur_rx_timeout(data)                            ((0x00000100&(data))>>8)
#define  MD_MD_SMQ_INT_STATUS_get_ur_rx_thd(data)                                ((0x00000080&(data))>>7)
#define  MD_MD_SMQ_INT_STATUS_get_ur_tx_thd(data)                                ((0x00000040&(data))>>6)
#define  MD_MD_SMQ_INT_STATUS_get_smq_mode_2b4berr(data)                         ((0x00000020&(data))>>5)
#define  MD_MD_SMQ_INT_STATUS_get_fdma_done(data)                                ((0x00000010&(data))>>4)
#define  MD_MD_SMQ_INT_STATUS_get_smq_empty(data)                                ((0x00000008&(data))>>3)
#define  MD_MD_SMQ_INT_STATUS_get_smq_length_err(data)                           ((0x00000004&(data))>>2)
#define  MD_MD_SMQ_INT_STATUS_get_smq_inst_err(data)                             ((0x00000002&(data))>>1)
#define  MD_MD_SMQ_INT_STATUS_get_write_data(data)                               (0x00000001&(data))

#define  MD_MD_SMQ_INT_ENABLE                                                    0x1800B008
#define  MD_MD_SMQ_INT_ENABLE_reg_addr                                           "0xB800B008"
#define  MD_MD_SMQ_INT_ENABLE_reg                                                0xB800B008
#define  MD_MD_SMQ_INT_ENABLE_inst_addr                                          "0x0002"
#define  set_MD_MD_SMQ_INT_ENABLE_reg(data)                                      (*((volatile unsigned int*)MD_MD_SMQ_INT_ENABLE_reg)=data)
#define  get_MD_MD_SMQ_INT_ENABLE_reg                                            (*((volatile unsigned int*)MD_MD_SMQ_INT_ENABLE_reg))
#define  MD_MD_SMQ_INT_ENABLE_scpu_int_en_shift                                  (10)
#define  MD_MD_SMQ_INT_ENABLE_ur_length_err_en_shift                             (9)
#define  MD_MD_SMQ_INT_ENABLE_ur_rx_timeout_en_shift                             (8)
#define  MD_MD_SMQ_INT_ENABLE_ur_rx_thd_en_shift                                 (7)
#define  MD_MD_SMQ_INT_ENABLE_ur_tx_thd_en_shift                                 (6)
#define  MD_MD_SMQ_INT_ENABLE_smq_mode_2b4b_err_en_shift                         (5)
#define  MD_MD_SMQ_INT_ENABLE_fdma_done_en_shift                                 (4)
#define  MD_MD_SMQ_INT_ENABLE_smq_empty_en_shift                                 (3)
#define  MD_MD_SMQ_INT_ENABLE_smq_length_err_en_shift                            (2)
#define  MD_MD_SMQ_INT_ENABLE_smq_inst_err_en_shift                              (1)
#define  MD_MD_SMQ_INT_ENABLE_write_data_shift                                   (0)
#define  MD_MD_SMQ_INT_ENABLE_scpu_int_en_mask                                   (0x00000400)
#define  MD_MD_SMQ_INT_ENABLE_ur_length_err_en_mask                              (0x00000200)
#define  MD_MD_SMQ_INT_ENABLE_ur_rx_timeout_en_mask                              (0x00000100)
#define  MD_MD_SMQ_INT_ENABLE_ur_rx_thd_en_mask                                  (0x00000080)
#define  MD_MD_SMQ_INT_ENABLE_ur_tx_thd_en_mask                                  (0x00000040)
#define  MD_MD_SMQ_INT_ENABLE_smq_mode_2b4b_err_en_mask                          (0x00000020)
#define  MD_MD_SMQ_INT_ENABLE_fdma_done_en_mask                                  (0x00000010)
#define  MD_MD_SMQ_INT_ENABLE_smq_empty_en_mask                                  (0x00000008)
#define  MD_MD_SMQ_INT_ENABLE_smq_length_err_en_mask                             (0x00000004)
#define  MD_MD_SMQ_INT_ENABLE_smq_inst_err_en_mask                               (0x00000002)
#define  MD_MD_SMQ_INT_ENABLE_write_data_mask                                    (0x00000001)
#define  MD_MD_SMQ_INT_ENABLE_scpu_int_en(data)                                  (0x00000400&((data)<<10))
#define  MD_MD_SMQ_INT_ENABLE_ur_length_err_en(data)                             (0x00000200&((data)<<9))
#define  MD_MD_SMQ_INT_ENABLE_ur_rx_timeout_en(data)                             (0x00000100&((data)<<8))
#define  MD_MD_SMQ_INT_ENABLE_ur_rx_thd_en(data)                                 (0x00000080&((data)<<7))
#define  MD_MD_SMQ_INT_ENABLE_ur_tx_thd_en(data)                                 (0x00000040&((data)<<6))
#define  MD_MD_SMQ_INT_ENABLE_smq_mode_2b4b_err_en(data)                         (0x00000020&((data)<<5))
#define  MD_MD_SMQ_INT_ENABLE_fdma_done_en(data)                                 (0x00000010&((data)<<4))
#define  MD_MD_SMQ_INT_ENABLE_smq_empty_en(data)                                 (0x00000008&((data)<<3))
#define  MD_MD_SMQ_INT_ENABLE_smq_length_err_en(data)                            (0x00000004&((data)<<2))
#define  MD_MD_SMQ_INT_ENABLE_smq_inst_err_en(data)                              (0x00000002&((data)<<1))
#define  MD_MD_SMQ_INT_ENABLE_write_data(data)                                   (0x00000001&(data))
#define  MD_MD_SMQ_INT_ENABLE_get_scpu_int_en(data)                              ((0x00000400&(data))>>10)
#define  MD_MD_SMQ_INT_ENABLE_get_ur_length_err_en(data)                         ((0x00000200&(data))>>9)
#define  MD_MD_SMQ_INT_ENABLE_get_ur_rx_timeout_en(data)                         ((0x00000100&(data))>>8)
#define  MD_MD_SMQ_INT_ENABLE_get_ur_rx_thd_en(data)                             ((0x00000080&(data))>>7)
#define  MD_MD_SMQ_INT_ENABLE_get_ur_tx_thd_en(data)                             ((0x00000040&(data))>>6)
#define  MD_MD_SMQ_INT_ENABLE_get_smq_mode_2b4b_err_en(data)                     ((0x00000020&(data))>>5)
#define  MD_MD_SMQ_INT_ENABLE_get_fdma_done_en(data)                             ((0x00000010&(data))>>4)
#define  MD_MD_SMQ_INT_ENABLE_get_smq_empty_en(data)                             ((0x00000008&(data))>>3)
#define  MD_MD_SMQ_INT_ENABLE_get_smq_length_err_en(data)                        ((0x00000004&(data))>>2)
#define  MD_MD_SMQ_INT_ENABLE_get_smq_inst_err_en(data)                          ((0x00000002&(data))>>1)
#define  MD_MD_SMQ_INT_ENABLE_get_write_data(data)                               (0x00000001&(data))

#define  MD_MD_SMQBase                                                           0x1800B00C
#define  MD_MD_SMQBase_reg_addr                                                  "0xB800B00C"
#define  MD_MD_SMQBase_reg                                                       0xB800B00C
#define  MD_MD_SMQBase_inst_addr                                                 "0x0003"
#define  set_MD_MD_SMQBase_reg(data)                                             (*((volatile unsigned int*)MD_MD_SMQBase_reg)=data)
#define  get_MD_MD_SMQBase_reg                                                   (*((volatile unsigned int*)MD_MD_SMQBase_reg))
#define  MD_MD_SMQBase_smq_base_shift                                            (4)
#define  MD_MD_SMQBase_smq_base_mask                                             (0xFFFFFFF0)
#define  MD_MD_SMQBase_smq_base(data)                                            (0xFFFFFFF0&((data)<<4))
#define  MD_MD_SMQBase_get_smq_base(data)                                        ((0xFFFFFFF0&(data))>>4)

#define  MD_MD_SMQLimit                                                          0x1800B010
#define  MD_MD_SMQLimit_reg_addr                                                 "0xB800B010"
#define  MD_MD_SMQLimit_reg                                                      0xB800B010
#define  MD_MD_SMQLimit_inst_addr                                                "0x0004"
#define  set_MD_MD_SMQLimit_reg(data)                                            (*((volatile unsigned int*)MD_MD_SMQLimit_reg)=data)
#define  get_MD_MD_SMQLimit_reg                                                  (*((volatile unsigned int*)MD_MD_SMQLimit_reg))
#define  MD_MD_SMQLimit_smq_limit_shift                                          (4)
#define  MD_MD_SMQLimit_smq_limit_mask                                           (0xFFFFFFF0)
#define  MD_MD_SMQLimit_smq_limit(data)                                          (0xFFFFFFF0&((data)<<4))
#define  MD_MD_SMQLimit_get_smq_limit(data)                                      ((0xFFFFFFF0&(data))>>4)

#define  MD_MD_SMQRdptr                                                          0x1800B014
#define  MD_MD_SMQRdptr_reg_addr                                                 "0xB800B014"
#define  MD_MD_SMQRdptr_reg                                                      0xB800B014
#define  MD_MD_SMQRdptr_inst_addr                                                "0x0005"
#define  set_MD_MD_SMQRdptr_reg(data)                                            (*((volatile unsigned int*)MD_MD_SMQRdptr_reg)=data)
#define  get_MD_MD_SMQRdptr_reg                                                  (*((volatile unsigned int*)MD_MD_SMQRdptr_reg))
#define  MD_MD_SMQRdptr_smq_rdptr_shift                                          (4)
#define  MD_MD_SMQRdptr_smq_rdptr_mask                                           (0xFFFFFFF0)
#define  MD_MD_SMQRdptr_smq_rdptr(data)                                          (0xFFFFFFF0&((data)<<4))
#define  MD_MD_SMQRdptr_get_smq_rdptr(data)                                      ((0xFFFFFFF0&(data))>>4)

#define  MD_MD_SMQWrptr                                                          0x1800B018
#define  MD_MD_SMQWrptr_reg_addr                                                 "0xB800B018"
#define  MD_MD_SMQWrptr_reg                                                      0xB800B018
#define  MD_MD_SMQWrptr_inst_addr                                                "0x0006"
#define  set_MD_MD_SMQWrptr_reg(data)                                            (*((volatile unsigned int*)MD_MD_SMQWrptr_reg)=data)
#define  get_MD_MD_SMQWrptr_reg                                                  (*((volatile unsigned int*)MD_MD_SMQWrptr_reg))
#define  MD_MD_SMQWrptr_smq_wrptr_shift                                          (4)
#define  MD_MD_SMQWrptr_smq_wrptr_mask                                           (0xFFFFFFF0)
#define  MD_MD_SMQWrptr_smq_wrptr(data)                                          (0xFFFFFFF0&((data)<<4))
#define  MD_MD_SMQWrptr_get_smq_wrptr(data)                                      ((0xFFFFFFF0&(data))>>4)

#define  MD_MD_SMQFifoState                                                      0x1800B01C
#define  MD_MD_SMQFifoState_reg_addr                                             "0xB800B01C"
#define  MD_MD_SMQFifoState_reg                                                  0xB800B01C
#define  MD_MD_SMQFifoState_inst_addr                                            "0x0007"
#define  set_MD_MD_SMQFifoState_reg(data)                                        (*((volatile unsigned int*)MD_MD_SMQFifoState_reg)=data)
#define  get_MD_MD_SMQFifoState_reg                                              (*((volatile unsigned int*)MD_MD_SMQFifoState_reg))
#define  MD_MD_SMQFifoState_smq_inst_remain_shift                                (0)
#define  MD_MD_SMQFifoState_smq_inst_remain_mask                                 (0x0000001F)
#define  MD_MD_SMQFifoState_smq_inst_remain(data)                                (0x0000001F&(data))
#define  MD_MD_SMQFifoState_get_smq_inst_remain(data)                            (0x0000001F&(data))

#define  MD_MD_SMQ_INSTCNT                                                       0x1800B020
#define  MD_MD_SMQ_INSTCNT_reg_addr                                              "0xB800B020"
#define  MD_MD_SMQ_INSTCNT_reg                                                   0xB800B020
#define  MD_MD_SMQ_INSTCNT_inst_addr                                             "0x0008"
#define  set_MD_MD_SMQ_INSTCNT_reg(data)                                         (*((volatile unsigned int*)MD_MD_SMQ_INSTCNT_reg)=data)
#define  get_MD_MD_SMQ_INSTCNT_reg                                               (*((volatile unsigned int*)MD_MD_SMQ_INSTCNT_reg))
#define  MD_MD_SMQ_INSTCNT_smq_inst_cnt_shift                                    (0)
#define  MD_MD_SMQ_INSTCNT_smq_inst_cnt_mask                                     (0x0000FFFF)
#define  MD_MD_SMQ_INSTCNT_smq_inst_cnt(data)                                    (0x0000FFFF&(data))
#define  MD_MD_SMQ_INSTCNT_get_smq_inst_cnt(data)                                (0x0000FFFF&(data))

#define  MD_MD_VMQ_CNTL                                                          0x1800B030
#define  MD_MD_VMQ_CNTL_reg_addr                                                 "0xB800B030"
#define  MD_MD_VMQ_CNTL_reg                                                      0xB800B030
#define  MD_MD_VMQ_CNTL_inst_addr                                                "0x0009"
#define  set_MD_MD_VMQ_CNTL_reg(data)                                            (*((volatile unsigned int*)MD_MD_VMQ_CNTL_reg)=data)
#define  get_MD_MD_VMQ_CNTL_reg                                                  (*((volatile unsigned int*)MD_MD_VMQ_CNTL_reg))
#define  MD_MD_VMQ_CNTL_vmq_idle_shift                                           (3)
#define  MD_MD_VMQ_CNTL_vmq_cmd_swap_shift                                       (2)
#define  MD_MD_VMQ_CNTL_vmq_go_shift                                             (1)
#define  MD_MD_VMQ_CNTL_write_data_shift                                         (0)
#define  MD_MD_VMQ_CNTL_vmq_idle_mask                                            (0x00000008)
#define  MD_MD_VMQ_CNTL_vmq_cmd_swap_mask                                        (0x00000004)
#define  MD_MD_VMQ_CNTL_vmq_go_mask                                              (0x00000002)
#define  MD_MD_VMQ_CNTL_write_data_mask                                          (0x00000001)
#define  MD_MD_VMQ_CNTL_vmq_idle(data)                                           (0x00000008&((data)<<3))
#define  MD_MD_VMQ_CNTL_vmq_cmd_swap(data)                                       (0x00000004&((data)<<2))
#define  MD_MD_VMQ_CNTL_vmq_go(data)                                             (0x00000002&((data)<<1))
#define  MD_MD_VMQ_CNTL_write_data(data)                                         (0x00000001&(data))
#define  MD_MD_VMQ_CNTL_get_vmq_idle(data)                                       ((0x00000008&(data))>>3)
#define  MD_MD_VMQ_CNTL_get_vmq_cmd_swap(data)                                   ((0x00000004&(data))>>2)
#define  MD_MD_VMQ_CNTL_get_vmq_go(data)                                         ((0x00000002&(data))>>1)
#define  MD_MD_VMQ_CNTL_get_write_data(data)                                     (0x00000001&(data))

#define  MD_MD_VMQ_INT_STATUS                                                    0x1800B034
#define  MD_MD_VMQ_INT_STATUS_reg_addr                                           "0xB800B034"
#define  MD_MD_VMQ_INT_STATUS_reg                                                0xB800B034
#define  MD_MD_VMQ_INT_STATUS_inst_addr                                          "0x000A"
#define  set_MD_MD_VMQ_INT_STATUS_reg(data)                                      (*((volatile unsigned int*)MD_MD_VMQ_INT_STATUS_reg)=data)
#define  get_MD_MD_VMQ_INT_STATUS_reg                                            (*((volatile unsigned int*)MD_MD_VMQ_INT_STATUS_reg))
#define  MD_MD_VMQ_INT_STATUS_vmq_mode_2b4berr_shift                             (4)
#define  MD_MD_VMQ_INT_STATUS_vmq_empty_shift                                    (3)
#define  MD_MD_VMQ_INT_STATUS_vmq_length_err_shift                               (2)
#define  MD_MD_VMQ_INT_STATUS_vmq_inst_err_shift                                 (1)
#define  MD_MD_VMQ_INT_STATUS_write_data_shift                                   (0)
#define  MD_MD_VMQ_INT_STATUS_vmq_mode_2b4berr_mask                              (0x00000010)
#define  MD_MD_VMQ_INT_STATUS_vmq_empty_mask                                     (0x00000008)
#define  MD_MD_VMQ_INT_STATUS_vmq_length_err_mask                                (0x00000004)
#define  MD_MD_VMQ_INT_STATUS_vmq_inst_err_mask                                  (0x00000002)
#define  MD_MD_VMQ_INT_STATUS_write_data_mask                                    (0x00000001)
#define  MD_MD_VMQ_INT_STATUS_vmq_mode_2b4berr(data)                             (0x00000010&((data)<<4))
#define  MD_MD_VMQ_INT_STATUS_vmq_empty(data)                                    (0x00000008&((data)<<3))
#define  MD_MD_VMQ_INT_STATUS_vmq_length_err(data)                               (0x00000004&((data)<<2))
#define  MD_MD_VMQ_INT_STATUS_vmq_inst_err(data)                                 (0x00000002&((data)<<1))
#define  MD_MD_VMQ_INT_STATUS_write_data(data)                                   (0x00000001&(data))
#define  MD_MD_VMQ_INT_STATUS_get_vmq_mode_2b4berr(data)                         ((0x00000010&(data))>>4)
#define  MD_MD_VMQ_INT_STATUS_get_vmq_empty(data)                                ((0x00000008&(data))>>3)
#define  MD_MD_VMQ_INT_STATUS_get_vmq_length_err(data)                           ((0x00000004&(data))>>2)
#define  MD_MD_VMQ_INT_STATUS_get_vmq_inst_err(data)                             ((0x00000002&(data))>>1)
#define  MD_MD_VMQ_INT_STATUS_get_write_data(data)                               (0x00000001&(data))

#define  MD_MD_VMQ_INT_ENABLE                                                    0x1800B038
#define  MD_MD_VMQ_INT_ENABLE_reg_addr                                           "0xB800B038"
#define  MD_MD_VMQ_INT_ENABLE_reg                                                0xB800B038
#define  MD_MD_VMQ_INT_ENABLE_inst_addr                                          "0x000B"
#define  set_MD_MD_VMQ_INT_ENABLE_reg(data)                                      (*((volatile unsigned int*)MD_MD_VMQ_INT_ENABLE_reg)=data)
#define  get_MD_MD_VMQ_INT_ENABLE_reg                                            (*((volatile unsigned int*)MD_MD_VMQ_INT_ENABLE_reg))
#define  MD_MD_VMQ_INT_ENABLE_vcpu_int_en_shift                                  (5)
#define  MD_MD_VMQ_INT_ENABLE_vmq_mode_2b4b_err_en_shift                         (4)
#define  MD_MD_VMQ_INT_ENABLE_vmq_empty_en_shift                                 (3)
#define  MD_MD_VMQ_INT_ENABLE_vmq_length_err_en_shift                            (2)
#define  MD_MD_VMQ_INT_ENABLE_vmq_inst_err_en_shift                              (1)
#define  MD_MD_VMQ_INT_ENABLE_write_data_shift                                   (0)
#define  MD_MD_VMQ_INT_ENABLE_vcpu_int_en_mask                                   (0x00000020)
#define  MD_MD_VMQ_INT_ENABLE_vmq_mode_2b4b_err_en_mask                          (0x00000010)
#define  MD_MD_VMQ_INT_ENABLE_vmq_empty_en_mask                                  (0x00000008)
#define  MD_MD_VMQ_INT_ENABLE_vmq_length_err_en_mask                             (0x00000004)
#define  MD_MD_VMQ_INT_ENABLE_vmq_inst_err_en_mask                               (0x00000002)
#define  MD_MD_VMQ_INT_ENABLE_write_data_mask                                    (0x00000001)
#define  MD_MD_VMQ_INT_ENABLE_vcpu_int_en(data)                                  (0x00000020&((data)<<5))
#define  MD_MD_VMQ_INT_ENABLE_vmq_mode_2b4b_err_en(data)                         (0x00000010&((data)<<4))
#define  MD_MD_VMQ_INT_ENABLE_vmq_empty_en(data)                                 (0x00000008&((data)<<3))
#define  MD_MD_VMQ_INT_ENABLE_vmq_length_err_en(data)                            (0x00000004&((data)<<2))
#define  MD_MD_VMQ_INT_ENABLE_vmq_inst_err_en(data)                              (0x00000002&((data)<<1))
#define  MD_MD_VMQ_INT_ENABLE_write_data(data)                                   (0x00000001&(data))
#define  MD_MD_VMQ_INT_ENABLE_get_vcpu_int_en(data)                              ((0x00000020&(data))>>5)
#define  MD_MD_VMQ_INT_ENABLE_get_vmq_mode_2b4b_err_en(data)                     ((0x00000010&(data))>>4)
#define  MD_MD_VMQ_INT_ENABLE_get_vmq_empty_en(data)                             ((0x00000008&(data))>>3)
#define  MD_MD_VMQ_INT_ENABLE_get_vmq_length_err_en(data)                        ((0x00000004&(data))>>2)
#define  MD_MD_VMQ_INT_ENABLE_get_vmq_inst_err_en(data)                          ((0x00000002&(data))>>1)
#define  MD_MD_VMQ_INT_ENABLE_get_write_data(data)                               (0x00000001&(data))

#define  MD_MD_VMQBase                                                           0x1800B03C
#define  MD_MD_VMQBase_reg_addr                                                  "0xB800B03C"
#define  MD_MD_VMQBase_reg                                                       0xB800B03C
#define  MD_MD_VMQBase_inst_addr                                                 "0x000C"
#define  set_MD_MD_VMQBase_reg(data)                                             (*((volatile unsigned int*)MD_MD_VMQBase_reg)=data)
#define  get_MD_MD_VMQBase_reg                                                   (*((volatile unsigned int*)MD_MD_VMQBase_reg))
#define  MD_MD_VMQBase_vmq_base_shift                                            (4)
#define  MD_MD_VMQBase_vmq_base_mask                                             (0xFFFFFFF0)
#define  MD_MD_VMQBase_vmq_base(data)                                            (0xFFFFFFF0&((data)<<4))
#define  MD_MD_VMQBase_get_vmq_base(data)                                        ((0xFFFFFFF0&(data))>>4)

#define  MD_MD_VMQLimit                                                          0x1800B040
#define  MD_MD_VMQLimit_reg_addr                                                 "0xB800B040"
#define  MD_MD_VMQLimit_reg                                                      0xB800B040
#define  MD_MD_VMQLimit_inst_addr                                                "0x000D"
#define  set_MD_MD_VMQLimit_reg(data)                                            (*((volatile unsigned int*)MD_MD_VMQLimit_reg)=data)
#define  get_MD_MD_VMQLimit_reg                                                  (*((volatile unsigned int*)MD_MD_VMQLimit_reg))
#define  MD_MD_VMQLimit_vmq_limit_shift                                          (4)
#define  MD_MD_VMQLimit_vmq_limit_mask                                           (0xFFFFFFF0)
#define  MD_MD_VMQLimit_vmq_limit(data)                                          (0xFFFFFFF0&((data)<<4))
#define  MD_MD_VMQLimit_get_vmq_limit(data)                                      ((0xFFFFFFF0&(data))>>4)

#define  MD_MD_VMQRdptr                                                          0x1800B044
#define  MD_MD_VMQRdptr_reg_addr                                                 "0xB800B044"
#define  MD_MD_VMQRdptr_reg                                                      0xB800B044
#define  MD_MD_VMQRdptr_inst_addr                                                "0x000E"
#define  set_MD_MD_VMQRdptr_reg(data)                                            (*((volatile unsigned int*)MD_MD_VMQRdptr_reg)=data)
#define  get_MD_MD_VMQRdptr_reg                                                  (*((volatile unsigned int*)MD_MD_VMQRdptr_reg))
#define  MD_MD_VMQRdptr_vmq_rdptr_shift                                          (4)
#define  MD_MD_VMQRdptr_vmq_rdptr_mask                                           (0xFFFFFFF0)
#define  MD_MD_VMQRdptr_vmq_rdptr(data)                                          (0xFFFFFFF0&((data)<<4))
#define  MD_MD_VMQRdptr_get_vmq_rdptr(data)                                      ((0xFFFFFFF0&(data))>>4)

#define  MD_MD_VMQWrptr                                                          0x1800B048
#define  MD_MD_VMQWrptr_reg_addr                                                 "0xB800B048"
#define  MD_MD_VMQWrptr_reg                                                      0xB800B048
#define  MD_MD_VMQWrptr_inst_addr                                                "0x000F"
#define  set_MD_MD_VMQWrptr_reg(data)                                            (*((volatile unsigned int*)MD_MD_VMQWrptr_reg)=data)
#define  get_MD_MD_VMQWrptr_reg                                                  (*((volatile unsigned int*)MD_MD_VMQWrptr_reg))
#define  MD_MD_VMQWrptr_vmq_wrptr_shift                                          (4)
#define  MD_MD_VMQWrptr_vmq_wrptr_mask                                           (0xFFFFFFF0)
#define  MD_MD_VMQWrptr_vmq_wrptr(data)                                          (0xFFFFFFF0&((data)<<4))
#define  MD_MD_VMQWrptr_get_vmq_wrptr(data)                                      ((0xFFFFFFF0&(data))>>4)

#define  MD_MD_VMQFifoState                                                      0x1800B04C
#define  MD_MD_VMQFifoState_reg_addr                                             "0xB800B04C"
#define  MD_MD_VMQFifoState_reg                                                  0xB800B04C
#define  MD_MD_VMQFifoState_inst_addr                                            "0x0010"
#define  set_MD_MD_VMQFifoState_reg(data)                                        (*((volatile unsigned int*)MD_MD_VMQFifoState_reg)=data)
#define  get_MD_MD_VMQFifoState_reg                                              (*((volatile unsigned int*)MD_MD_VMQFifoState_reg))
#define  MD_MD_VMQFifoState_vmq_inst_remain_shift                                (0)
#define  MD_MD_VMQFifoState_vmq_inst_remain_mask                                 (0x0000001F)
#define  MD_MD_VMQFifoState_vmq_inst_remain(data)                                (0x0000001F&(data))
#define  MD_MD_VMQFifoState_get_vmq_inst_remain(data)                            (0x0000001F&(data))

#define  MD_MD_VMQ_INSTCNT                                                       0x1800B050
#define  MD_MD_VMQ_INSTCNT_reg_addr                                              "0xB800B050"
#define  MD_MD_VMQ_INSTCNT_reg                                                   0xB800B050
#define  MD_MD_VMQ_INSTCNT_inst_addr                                             "0x0011"
#define  set_MD_MD_VMQ_INSTCNT_reg(data)                                         (*((volatile unsigned int*)MD_MD_VMQ_INSTCNT_reg)=data)
#define  get_MD_MD_VMQ_INSTCNT_reg                                               (*((volatile unsigned int*)MD_MD_VMQ_INSTCNT_reg))
#define  MD_MD_VMQ_INSTCNT_vmq_inst_cnt_shift                                    (0)
#define  MD_MD_VMQ_INSTCNT_vmq_inst_cnt_mask                                     (0x0000FFFF)
#define  MD_MD_VMQ_INSTCNT_vmq_inst_cnt(data)                                    (0x0000FFFF&(data))
#define  MD_MD_VMQ_INSTCNT_get_vmq_inst_cnt(data)                                (0x0000FFFF&(data))

#define  MD_MD_KMQ_CNTL                                                          0x1800B060
#define  MD_MD_KMQ_CNTL_reg_addr                                                 "0xB800B060"
#define  MD_MD_KMQ_CNTL_reg                                                      0xB800B060
#define  MD_MD_KMQ_CNTL_inst_addr                                                "0x0012"
#define  set_MD_MD_KMQ_CNTL_reg(data)                                            (*((volatile unsigned int*)MD_MD_KMQ_CNTL_reg)=data)
#define  get_MD_MD_KMQ_CNTL_reg                                                  (*((volatile unsigned int*)MD_MD_KMQ_CNTL_reg))
#define  MD_MD_KMQ_CNTL_kmq_idle_shift                                           (3)
#define  MD_MD_KMQ_CNTL_kmq_cmd_swap_shift                                       (2)
#define  MD_MD_KMQ_CNTL_kmq_go_shift                                             (1)
#define  MD_MD_KMQ_CNTL_write_data_shift                                         (0)
#define  MD_MD_KMQ_CNTL_kmq_idle_mask                                            (0x00000008)
#define  MD_MD_KMQ_CNTL_kmq_cmd_swap_mask                                        (0x00000004)
#define  MD_MD_KMQ_CNTL_kmq_go_mask                                              (0x00000002)
#define  MD_MD_KMQ_CNTL_write_data_mask                                          (0x00000001)
#define  MD_MD_KMQ_CNTL_kmq_idle(data)                                           (0x00000008&((data)<<3))
#define  MD_MD_KMQ_CNTL_kmq_cmd_swap(data)                                       (0x00000004&((data)<<2))
#define  MD_MD_KMQ_CNTL_kmq_go(data)                                             (0x00000002&((data)<<1))
#define  MD_MD_KMQ_CNTL_write_data(data)                                         (0x00000001&(data))
#define  MD_MD_KMQ_CNTL_get_kmq_idle(data)                                       ((0x00000008&(data))>>3)
#define  MD_MD_KMQ_CNTL_get_kmq_cmd_swap(data)                                   ((0x00000004&(data))>>2)
#define  MD_MD_KMQ_CNTL_get_kmq_go(data)                                         ((0x00000002&(data))>>1)
#define  MD_MD_KMQ_CNTL_get_write_data(data)                                     (0x00000001&(data))

#define  MD_MD_KMQ_INT_STATUS                                                    0x1800B064
#define  MD_MD_KMQ_INT_STATUS_reg_addr                                           "0xB800B064"
#define  MD_MD_KMQ_INT_STATUS_reg                                                0xB800B064
#define  MD_MD_KMQ_INT_STATUS_inst_addr                                          "0x0013"
#define  set_MD_MD_KMQ_INT_STATUS_reg(data)                                      (*((volatile unsigned int*)MD_MD_KMQ_INT_STATUS_reg)=data)
#define  get_MD_MD_KMQ_INT_STATUS_reg                                            (*((volatile unsigned int*)MD_MD_KMQ_INT_STATUS_reg))
#define  MD_MD_KMQ_INT_STATUS_kmq_mode_2b4berr_shift                             (4)
#define  MD_MD_KMQ_INT_STATUS_kmq_empty_shift                                    (3)
#define  MD_MD_KMQ_INT_STATUS_kmq_length_err_shift                               (2)
#define  MD_MD_KMQ_INT_STATUS_kmq_inst_err_shift                                 (1)
#define  MD_MD_KMQ_INT_STATUS_write_data_shift                                   (0)
#define  MD_MD_KMQ_INT_STATUS_kmq_mode_2b4berr_mask                              (0x00000010)
#define  MD_MD_KMQ_INT_STATUS_kmq_empty_mask                                     (0x00000008)
#define  MD_MD_KMQ_INT_STATUS_kmq_length_err_mask                                (0x00000004)
#define  MD_MD_KMQ_INT_STATUS_kmq_inst_err_mask                                  (0x00000002)
#define  MD_MD_KMQ_INT_STATUS_write_data_mask                                    (0x00000001)
#define  MD_MD_KMQ_INT_STATUS_kmq_mode_2b4berr(data)                             (0x00000010&((data)<<4))
#define  MD_MD_KMQ_INT_STATUS_kmq_empty(data)                                    (0x00000008&((data)<<3))
#define  MD_MD_KMQ_INT_STATUS_kmq_length_err(data)                               (0x00000004&((data)<<2))
#define  MD_MD_KMQ_INT_STATUS_kmq_inst_err(data)                                 (0x00000002&((data)<<1))
#define  MD_MD_KMQ_INT_STATUS_write_data(data)                                   (0x00000001&(data))
#define  MD_MD_KMQ_INT_STATUS_get_kmq_mode_2b4berr(data)                         ((0x00000010&(data))>>4)
#define  MD_MD_KMQ_INT_STATUS_get_kmq_empty(data)                                ((0x00000008&(data))>>3)
#define  MD_MD_KMQ_INT_STATUS_get_kmq_length_err(data)                           ((0x00000004&(data))>>2)
#define  MD_MD_KMQ_INT_STATUS_get_kmq_inst_err(data)                             ((0x00000002&(data))>>1)
#define  MD_MD_KMQ_INT_STATUS_get_write_data(data)                               (0x00000001&(data))

#define  MD_MD_KMQ_INT_ENABLE                                                    0x1800B068
#define  MD_MD_KMQ_INT_ENABLE_reg_addr                                           "0xB800B068"
#define  MD_MD_KMQ_INT_ENABLE_reg                                                0xB800B068
#define  MD_MD_KMQ_INT_ENABLE_inst_addr                                          "0x0014"
#define  set_MD_MD_KMQ_INT_ENABLE_reg(data)                                      (*((volatile unsigned int*)MD_MD_KMQ_INT_ENABLE_reg)=data)
#define  get_MD_MD_KMQ_INT_ENABLE_reg                                            (*((volatile unsigned int*)MD_MD_KMQ_INT_ENABLE_reg))
#define  MD_MD_KMQ_INT_ENABLE_kcpu_int_en_shift                                  (5)
#define  MD_MD_KMQ_INT_ENABLE_kmq_mode_2b4b_err_en_shift                         (4)
#define  MD_MD_KMQ_INT_ENABLE_kmq_empty_en_shift                                 (3)
#define  MD_MD_KMQ_INT_ENABLE_kmq_length_err_en_shift                            (2)
#define  MD_MD_KMQ_INT_ENABLE_kmq_inst_err_en_shift                              (1)
#define  MD_MD_KMQ_INT_ENABLE_write_data_shift                                   (0)
#define  MD_MD_KMQ_INT_ENABLE_kcpu_int_en_mask                                   (0x00000020)
#define  MD_MD_KMQ_INT_ENABLE_kmq_mode_2b4b_err_en_mask                          (0x00000010)
#define  MD_MD_KMQ_INT_ENABLE_kmq_empty_en_mask                                  (0x00000008)
#define  MD_MD_KMQ_INT_ENABLE_kmq_length_err_en_mask                             (0x00000004)
#define  MD_MD_KMQ_INT_ENABLE_kmq_inst_err_en_mask                               (0x00000002)
#define  MD_MD_KMQ_INT_ENABLE_write_data_mask                                    (0x00000001)
#define  MD_MD_KMQ_INT_ENABLE_kcpu_int_en(data)                                  (0x00000020&((data)<<5))
#define  MD_MD_KMQ_INT_ENABLE_kmq_mode_2b4b_err_en(data)                         (0x00000010&((data)<<4))
#define  MD_MD_KMQ_INT_ENABLE_kmq_empty_en(data)                                 (0x00000008&((data)<<3))
#define  MD_MD_KMQ_INT_ENABLE_kmq_length_err_en(data)                            (0x00000004&((data)<<2))
#define  MD_MD_KMQ_INT_ENABLE_kmq_inst_err_en(data)                              (0x00000002&((data)<<1))
#define  MD_MD_KMQ_INT_ENABLE_write_data(data)                                   (0x00000001&(data))
#define  MD_MD_KMQ_INT_ENABLE_get_kcpu_int_en(data)                              ((0x00000020&(data))>>5)
#define  MD_MD_KMQ_INT_ENABLE_get_kmq_mode_2b4b_err_en(data)                     ((0x00000010&(data))>>4)
#define  MD_MD_KMQ_INT_ENABLE_get_kmq_empty_en(data)                             ((0x00000008&(data))>>3)
#define  MD_MD_KMQ_INT_ENABLE_get_kmq_length_err_en(data)                        ((0x00000004&(data))>>2)
#define  MD_MD_KMQ_INT_ENABLE_get_kmq_inst_err_en(data)                          ((0x00000002&(data))>>1)
#define  MD_MD_KMQ_INT_ENABLE_get_write_data(data)                               (0x00000001&(data))

#define  MD_MD_KMQBase                                                           0x1800B06C
#define  MD_MD_KMQBase_reg_addr                                                  "0xB800B06C"
#define  MD_MD_KMQBase_reg                                                       0xB800B06C
#define  MD_MD_KMQBase_inst_addr                                                 "0x0015"
#define  set_MD_MD_KMQBase_reg(data)                                             (*((volatile unsigned int*)MD_MD_KMQBase_reg)=data)
#define  get_MD_MD_KMQBase_reg                                                   (*((volatile unsigned int*)MD_MD_KMQBase_reg))
#define  MD_MD_KMQBase_kmq_base_shift                                            (4)
#define  MD_MD_KMQBase_kmq_base_mask                                             (0xFFFFFFF0)
#define  MD_MD_KMQBase_kmq_base(data)                                            (0xFFFFFFF0&((data)<<4))
#define  MD_MD_KMQBase_get_kmq_base(data)                                        ((0xFFFFFFF0&(data))>>4)

#define  MD_MD_KMQLimit                                                          0x1800B070
#define  MD_MD_KMQLimit_reg_addr                                                 "0xB800B070"
#define  MD_MD_KMQLimit_reg                                                      0xB800B070
#define  MD_MD_KMQLimit_inst_addr                                                "0x0016"
#define  set_MD_MD_KMQLimit_reg(data)                                            (*((volatile unsigned int*)MD_MD_KMQLimit_reg)=data)
#define  get_MD_MD_KMQLimit_reg                                                  (*((volatile unsigned int*)MD_MD_KMQLimit_reg))
#define  MD_MD_KMQLimit_kmq_limit_shift                                          (4)
#define  MD_MD_KMQLimit_kmq_limit_mask                                           (0xFFFFFFF0)
#define  MD_MD_KMQLimit_kmq_limit(data)                                          (0xFFFFFFF0&((data)<<4))
#define  MD_MD_KMQLimit_get_kmq_limit(data)                                      ((0xFFFFFFF0&(data))>>4)

#define  MD_MD_KMQRdptr                                                          0x1800B074
#define  MD_MD_KMQRdptr_reg_addr                                                 "0xB800B074"
#define  MD_MD_KMQRdptr_reg                                                      0xB800B074
#define  MD_MD_KMQRdptr_inst_addr                                                "0x0017"
#define  set_MD_MD_KMQRdptr_reg(data)                                            (*((volatile unsigned int*)MD_MD_KMQRdptr_reg)=data)
#define  get_MD_MD_KMQRdptr_reg                                                  (*((volatile unsigned int*)MD_MD_KMQRdptr_reg))
#define  MD_MD_KMQRdptr_kmq_rdptr_shift                                          (4)
#define  MD_MD_KMQRdptr_kmq_rdptr_mask                                           (0xFFFFFFF0)
#define  MD_MD_KMQRdptr_kmq_rdptr(data)                                          (0xFFFFFFF0&((data)<<4))
#define  MD_MD_KMQRdptr_get_kmq_rdptr(data)                                      ((0xFFFFFFF0&(data))>>4)

#define  MD_MD_KMQWrptr                                                          0x1800B078
#define  MD_MD_KMQWrptr_reg_addr                                                 "0xB800B078"
#define  MD_MD_KMQWrptr_reg                                                      0xB800B078
#define  MD_MD_KMQWrptr_inst_addr                                                "0x0018"
#define  set_MD_MD_KMQWrptr_reg(data)                                            (*((volatile unsigned int*)MD_MD_KMQWrptr_reg)=data)
#define  get_MD_MD_KMQWrptr_reg                                                  (*((volatile unsigned int*)MD_MD_KMQWrptr_reg))
#define  MD_MD_KMQWrptr_kmq_wrptr_shift                                          (4)
#define  MD_MD_KMQWrptr_kmq_wrptr_mask                                           (0xFFFFFFF0)
#define  MD_MD_KMQWrptr_kmq_wrptr(data)                                          (0xFFFFFFF0&((data)<<4))
#define  MD_MD_KMQWrptr_get_kmq_wrptr(data)                                      ((0xFFFFFFF0&(data))>>4)

#define  MD_MD_KMQFifoState                                                      0x1800B07C
#define  MD_MD_KMQFifoState_reg_addr                                             "0xB800B07C"
#define  MD_MD_KMQFifoState_reg                                                  0xB800B07C
#define  MD_MD_KMQFifoState_inst_addr                                            "0x0019"
#define  set_MD_MD_KMQFifoState_reg(data)                                        (*((volatile unsigned int*)MD_MD_KMQFifoState_reg)=data)
#define  get_MD_MD_KMQFifoState_reg                                              (*((volatile unsigned int*)MD_MD_KMQFifoState_reg))
#define  MD_MD_KMQFifoState_kmq_inst_remain_shift                                (0)
#define  MD_MD_KMQFifoState_kmq_inst_remain_mask                                 (0x0000001F)
#define  MD_MD_KMQFifoState_kmq_inst_remain(data)                                (0x0000001F&(data))
#define  MD_MD_KMQFifoState_get_kmq_inst_remain(data)                            (0x0000001F&(data))

#define  MD_MD_KMQ_INSTCNT                                                       0x1800B080
#define  MD_MD_KMQ_INSTCNT_reg_addr                                              "0xB800B080"
#define  MD_MD_KMQ_INSTCNT_reg                                                   0xB800B080
#define  MD_MD_KMQ_INSTCNT_inst_addr                                             "0x001A"
#define  set_MD_MD_KMQ_INSTCNT_reg(data)                                         (*((volatile unsigned int*)MD_MD_KMQ_INSTCNT_reg)=data)
#define  get_MD_MD_KMQ_INSTCNT_reg                                               (*((volatile unsigned int*)MD_MD_KMQ_INSTCNT_reg))
#define  MD_MD_KMQ_INSTCNT_kmq_inst_cnt_shift                                    (0)
#define  MD_MD_KMQ_INSTCNT_kmq_inst_cnt_mask                                     (0x0000FFFF)
#define  MD_MD_KMQ_INSTCNT_kmq_inst_cnt(data)                                    (0x0000FFFF&(data))
#define  MD_MD_KMQ_INSTCNT_get_kmq_inst_cnt(data)                                (0x0000FFFF&(data))

#define  MD_MD_DBG                                                               0x1800B0D0
#define  MD_MD_DBG_reg_addr                                                      "0xB800B0D0"
#define  MD_MD_DBG_reg                                                           0xB800B0D0
#define  MD_MD_DBG_inst_addr                                                     "0x001B"
#define  set_MD_MD_DBG_reg(data)                                                 (*((volatile unsigned int*)MD_MD_DBG_reg)=data)
#define  get_MD_MD_DBG_reg                                                       (*((volatile unsigned int*)MD_MD_DBG_reg))
#define  MD_MD_DBG_md_dbg_sel1_shift                                             (8)
#define  MD_MD_DBG_md_dbg_sel0_shift                                             (1)
#define  MD_MD_DBG_md_dbg_enable_shift                                           (0)
#define  MD_MD_DBG_md_dbg_sel1_mask                                              (0x00007F00)
#define  MD_MD_DBG_md_dbg_sel0_mask                                              (0x000000FE)
#define  MD_MD_DBG_md_dbg_enable_mask                                            (0x00000001)
#define  MD_MD_DBG_md_dbg_sel1(data)                                             (0x00007F00&((data)<<8))
#define  MD_MD_DBG_md_dbg_sel0(data)                                             (0x000000FE&((data)<<1))
#define  MD_MD_DBG_md_dbg_enable(data)                                           (0x00000001&(data))
#define  MD_MD_DBG_get_md_dbg_sel1(data)                                         ((0x00007F00&(data))>>8)
#define  MD_MD_DBG_get_md_dbg_sel0(data)                                         ((0x000000FE&(data))>>1)
#define  MD_MD_DBG_get_md_dbg_enable(data)                                       (0x00000001&(data))

#define  MD_MD_FDMA_DDR_SADDR                                                    0x1800B088
#define  MD_MD_FDMA_DDR_SADDR_reg_addr                                           "0xB800B088"
#define  MD_MD_FDMA_DDR_SADDR_reg                                                0xB800B088
#define  MD_MD_FDMA_DDR_SADDR_inst_addr                                          "0x001C"
#define  set_MD_MD_FDMA_DDR_SADDR_reg(data)                                      (*((volatile unsigned int*)MD_MD_FDMA_DDR_SADDR_reg)=data)
#define  get_MD_MD_FDMA_DDR_SADDR_reg                                            (*((volatile unsigned int*)MD_MD_FDMA_DDR_SADDR_reg))
#define  MD_MD_FDMA_DDR_SADDR_fdma_ddr_saddr_shift                               (0)
#define  MD_MD_FDMA_DDR_SADDR_fdma_ddr_saddr_mask                                (0xFFFFFFFF)
#define  MD_MD_FDMA_DDR_SADDR_fdma_ddr_saddr(data)                               (0xFFFFFFFF&(data))
#define  MD_MD_FDMA_DDR_SADDR_get_fdma_ddr_saddr(data)                           (0xFFFFFFFF&(data))

#define  MD_MD_FDMA_FL_SADDR                                                     0x1800B08C
#define  MD_MD_FDMA_FL_SADDR_reg_addr                                            "0xB800B08C"
#define  MD_MD_FDMA_FL_SADDR_reg                                                 0xB800B08C
#define  MD_MD_FDMA_FL_SADDR_inst_addr                                           "0x001D"
#define  set_MD_MD_FDMA_FL_SADDR_reg(data)                                       (*((volatile unsigned int*)MD_MD_FDMA_FL_SADDR_reg)=data)
#define  get_MD_MD_FDMA_FL_SADDR_reg                                             (*((volatile unsigned int*)MD_MD_FDMA_FL_SADDR_reg))
#define  MD_MD_FDMA_FL_SADDR_fdma_fl_saddr_shift                                 (0)
#define  MD_MD_FDMA_FL_SADDR_fdma_fl_saddr_mask                                  (0x01FFFFFF)
#define  MD_MD_FDMA_FL_SADDR_fdma_fl_saddr(data)                                 (0x01FFFFFF&(data))
#define  MD_MD_FDMA_FL_SADDR_get_fdma_fl_saddr(data)                             (0x01FFFFFF&(data))

#define  MD_MD_FDMA_CTRL2                                                        0x1800B090
#define  MD_MD_FDMA_CTRL2_reg_addr                                               "0xB800B090"
#define  MD_MD_FDMA_CTRL2_reg                                                    0xB800B090
#define  MD_MD_FDMA_CTRL2_inst_addr                                              "0x001E"
#define  set_MD_MD_FDMA_CTRL2_reg(data)                                          (*((volatile unsigned int*)MD_MD_FDMA_CTRL2_reg)=data)
#define  get_MD_MD_FDMA_CTRL2_reg                                                (*((volatile unsigned int*)MD_MD_FDMA_CTRL2_reg))
#define  MD_MD_FDMA_CTRL2_fl_cp_en_shift                                         (30)
#define  MD_MD_FDMA_CTRL2_fl_mapping_mode_shift                                  (29)
#define  MD_MD_FDMA_CTRL2_fdma_swap_shift                                        (28)
#define  MD_MD_FDMA_CTRL2_fdma_max_xfer_shift                                    (26)
#define  MD_MD_FDMA_CTRL2_fdma_dir_shift                                         (25)
#define  MD_MD_FDMA_CTRL2_fdma_length_shift                                      (0)
#define  MD_MD_FDMA_CTRL2_fl_cp_en_mask                                          (0x40000000)
#define  MD_MD_FDMA_CTRL2_fl_mapping_mode_mask                                   (0x20000000)
#define  MD_MD_FDMA_CTRL2_fdma_swap_mask                                         (0x10000000)
#define  MD_MD_FDMA_CTRL2_fdma_max_xfer_mask                                     (0x0C000000)
#define  MD_MD_FDMA_CTRL2_fdma_dir_mask                                          (0x02000000)
#define  MD_MD_FDMA_CTRL2_fdma_length_mask                                       (0x01FFFFFF)
#define  MD_MD_FDMA_CTRL2_fl_cp_en(data)                                         (0x40000000&((data)<<30))
#define  MD_MD_FDMA_CTRL2_fl_mapping_mode(data)                                  (0x20000000&((data)<<29))
#define  MD_MD_FDMA_CTRL2_fdma_swap(data)                                        (0x10000000&((data)<<28))
#define  MD_MD_FDMA_CTRL2_fdma_max_xfer(data)                                    (0x0C000000&((data)<<26))
#define  MD_MD_FDMA_CTRL2_fdma_dir(data)                                         (0x02000000&((data)<<25))
#define  MD_MD_FDMA_CTRL2_fdma_length(data)                                      (0x01FFFFFF&(data))
#define  MD_MD_FDMA_CTRL2_get_fl_cp_en(data)                                     ((0x40000000&(data))>>30)
#define  MD_MD_FDMA_CTRL2_get_fl_mapping_mode(data)                              ((0x20000000&(data))>>29)
#define  MD_MD_FDMA_CTRL2_get_fdma_swap(data)                                    ((0x10000000&(data))>>28)
#define  MD_MD_FDMA_CTRL2_get_fdma_max_xfer(data)                                ((0x0C000000&(data))>>26)
#define  MD_MD_FDMA_CTRL2_get_fdma_dir(data)                                     ((0x02000000&(data))>>25)
#define  MD_MD_FDMA_CTRL2_get_fdma_length(data)                                  (0x01FFFFFF&(data))

#define  MD_MD_FDMA_CTRL1                                                        0x1800B094
#define  MD_MD_FDMA_CTRL1_reg_addr                                               "0xB800B094"
#define  MD_MD_FDMA_CTRL1_reg                                                    0xB800B094
#define  MD_MD_FDMA_CTRL1_inst_addr                                              "0x001F"
#define  set_MD_MD_FDMA_CTRL1_reg(data)                                          (*((volatile unsigned int*)MD_MD_FDMA_CTRL1_reg)=data)
#define  get_MD_MD_FDMA_CTRL1_reg                                                (*((volatile unsigned int*)MD_MD_FDMA_CTRL1_reg))
#define  MD_MD_FDMA_CTRL1_write_en2_shift                                        (3)
#define  MD_MD_FDMA_CTRL1_fdma_stop_shift                                        (2)
#define  MD_MD_FDMA_CTRL1_write_en1_shift                                        (1)
#define  MD_MD_FDMA_CTRL1_fdma_go_shift                                          (0)
#define  MD_MD_FDMA_CTRL1_write_en2_mask                                         (0x00000008)
#define  MD_MD_FDMA_CTRL1_fdma_stop_mask                                         (0x00000004)
#define  MD_MD_FDMA_CTRL1_write_en1_mask                                         (0x00000002)
#define  MD_MD_FDMA_CTRL1_fdma_go_mask                                           (0x00000001)
#define  MD_MD_FDMA_CTRL1_write_en2(data)                                        (0x00000008&((data)<<3))
#define  MD_MD_FDMA_CTRL1_fdma_stop(data)                                        (0x00000004&((data)<<2))
#define  MD_MD_FDMA_CTRL1_write_en1(data)                                        (0x00000002&((data)<<1))
#define  MD_MD_FDMA_CTRL1_fdma_go(data)                                          (0x00000001&(data))
#define  MD_MD_FDMA_CTRL1_get_write_en2(data)                                    ((0x00000008&(data))>>3)
#define  MD_MD_FDMA_CTRL1_get_fdma_stop(data)                                    ((0x00000004&(data))>>2)
#define  MD_MD_FDMA_CTRL1_get_write_en1(data)                                    ((0x00000002&(data))>>1)
#define  MD_MD_FDMA_CTRL1_get_fdma_go(data)                                      (0x00000001&(data))

#define  MD_MD_FDMA_DDR_SADDR_K                                                  0x1800B190
#define  MD_MD_FDMA_DDR_SADDR_K_reg_addr                                         "0xB800B190"
#define  MD_MD_FDMA_DDR_SADDR_K_reg                                              0xB800B190
#define  MD_MD_FDMA_DDR_SADDR_K_inst_addr                                        "0x0020"
#define  set_MD_MD_FDMA_DDR_SADDR_K_reg(data)                                    (*((volatile unsigned int*)MD_MD_FDMA_DDR_SADDR_K_reg)=data)
#define  get_MD_MD_FDMA_DDR_SADDR_K_reg                                          (*((volatile unsigned int*)MD_MD_FDMA_DDR_SADDR_K_reg))
#define  MD_MD_FDMA_DDR_SADDR_K_fdma_ddr_saddr_k_shift                           (0)
#define  MD_MD_FDMA_DDR_SADDR_K_fdma_ddr_saddr_k_mask                            (0x7FFFFFFF)
#define  MD_MD_FDMA_DDR_SADDR_K_fdma_ddr_saddr_k(data)                           (0x7FFFFFFF&(data))
#define  MD_MD_FDMA_DDR_SADDR_K_get_fdma_ddr_saddr_k(data)                       (0x7FFFFFFF&(data))

#define  MD_MD_FDMA_FL_SADDR_K                                                   0x1800B194
#define  MD_MD_FDMA_FL_SADDR_K_reg_addr                                          "0xB800B194"
#define  MD_MD_FDMA_FL_SADDR_K_reg                                               0xB800B194
#define  MD_MD_FDMA_FL_SADDR_K_inst_addr                                         "0x0021"
#define  set_MD_MD_FDMA_FL_SADDR_K_reg(data)                                     (*((volatile unsigned int*)MD_MD_FDMA_FL_SADDR_K_reg)=data)
#define  get_MD_MD_FDMA_FL_SADDR_K_reg                                           (*((volatile unsigned int*)MD_MD_FDMA_FL_SADDR_K_reg))
#define  MD_MD_FDMA_FL_SADDR_K_fdma_fl_saddr_k_shift                             (0)
#define  MD_MD_FDMA_FL_SADDR_K_fdma_fl_saddr_k_mask                              (0x01FFFFFF)
#define  MD_MD_FDMA_FL_SADDR_K_fdma_fl_saddr_k(data)                             (0x01FFFFFF&(data))
#define  MD_MD_FDMA_FL_SADDR_K_get_fdma_fl_saddr_k(data)                         (0x01FFFFFF&(data))

#define  MD_MD_FDMA_CTRL2_K                                                      0x1800B198
#define  MD_MD_FDMA_CTRL2_K_reg_addr                                             "0xB800B198"
#define  MD_MD_FDMA_CTRL2_K_reg                                                  0xB800B198
#define  MD_MD_FDMA_CTRL2_K_inst_addr                                            "0x0022"
#define  set_MD_MD_FDMA_CTRL2_K_reg(data)                                        (*((volatile unsigned int*)MD_MD_FDMA_CTRL2_K_reg)=data)
#define  get_MD_MD_FDMA_CTRL2_K_reg                                              (*((volatile unsigned int*)MD_MD_FDMA_CTRL2_K_reg))
#define  MD_MD_FDMA_CTRL2_K_fl_cp_en_k_shift                                     (30)
#define  MD_MD_FDMA_CTRL2_K_fl_mapping_mode_k_shift                              (29)
#define  MD_MD_FDMA_CTRL2_K_fdma_swap_k_shift                                    (28)
#define  MD_MD_FDMA_CTRL2_K_fdma_max_xfer_k_shift                                (26)
#define  MD_MD_FDMA_CTRL2_K_fdma_dir_k_shift                                     (25)
#define  MD_MD_FDMA_CTRL2_K_fdma_length_k_shift                                  (0)
#define  MD_MD_FDMA_CTRL2_K_fl_cp_en_k_mask                                      (0x40000000)
#define  MD_MD_FDMA_CTRL2_K_fl_mapping_mode_k_mask                               (0x20000000)
#define  MD_MD_FDMA_CTRL2_K_fdma_swap_k_mask                                     (0x10000000)
#define  MD_MD_FDMA_CTRL2_K_fdma_max_xfer_k_mask                                 (0x0C000000)
#define  MD_MD_FDMA_CTRL2_K_fdma_dir_k_mask                                      (0x02000000)
#define  MD_MD_FDMA_CTRL2_K_fdma_length_k_mask                                   (0x01FFFFFF)
#define  MD_MD_FDMA_CTRL2_K_fl_cp_en_k(data)                                     (0x40000000&((data)<<30))
#define  MD_MD_FDMA_CTRL2_K_fl_mapping_mode_k(data)                              (0x20000000&((data)<<29))
#define  MD_MD_FDMA_CTRL2_K_fdma_swap_k(data)                                    (0x10000000&((data)<<28))
#define  MD_MD_FDMA_CTRL2_K_fdma_max_xfer_k(data)                                (0x0C000000&((data)<<26))
#define  MD_MD_FDMA_CTRL2_K_fdma_dir_k(data)                                     (0x02000000&((data)<<25))
#define  MD_MD_FDMA_CTRL2_K_fdma_length_k(data)                                  (0x01FFFFFF&(data))
#define  MD_MD_FDMA_CTRL2_K_get_fl_cp_en_k(data)                                 ((0x40000000&(data))>>30)
#define  MD_MD_FDMA_CTRL2_K_get_fl_mapping_mode_k(data)                          ((0x20000000&(data))>>29)
#define  MD_MD_FDMA_CTRL2_K_get_fdma_swap_k(data)                                ((0x10000000&(data))>>28)
#define  MD_MD_FDMA_CTRL2_K_get_fdma_max_xfer_k(data)                            ((0x0C000000&(data))>>26)
#define  MD_MD_FDMA_CTRL2_K_get_fdma_dir_k(data)                                 ((0x02000000&(data))>>25)
#define  MD_MD_FDMA_CTRL2_K_get_fdma_length_k(data)                              (0x01FFFFFF&(data))

#define  MD_MD_FDMA_CTRL1_K                                                      0x1800B19C
#define  MD_MD_FDMA_CTRL1_K_reg_addr                                             "0xB800B19C"
#define  MD_MD_FDMA_CTRL1_K_reg                                                  0xB800B19C
#define  MD_MD_FDMA_CTRL1_K_inst_addr                                            "0x0023"
#define  set_MD_MD_FDMA_CTRL1_K_reg(data)                                        (*((volatile unsigned int*)MD_MD_FDMA_CTRL1_K_reg)=data)
#define  get_MD_MD_FDMA_CTRL1_K_reg                                              (*((volatile unsigned int*)MD_MD_FDMA_CTRL1_K_reg))
#define  MD_MD_FDMA_CTRL1_K_write_en2_k_shift                                    (3)
#define  MD_MD_FDMA_CTRL1_K_fdma_stop_k_shift                                    (2)
#define  MD_MD_FDMA_CTRL1_K_write_en1_k_shift                                    (1)
#define  MD_MD_FDMA_CTRL1_K_fdma_go_k_shift                                      (0)
#define  MD_MD_FDMA_CTRL1_K_write_en2_k_mask                                     (0x00000008)
#define  MD_MD_FDMA_CTRL1_K_fdma_stop_k_mask                                     (0x00000004)
#define  MD_MD_FDMA_CTRL1_K_write_en1_k_mask                                     (0x00000002)
#define  MD_MD_FDMA_CTRL1_K_fdma_go_k_mask                                       (0x00000001)
#define  MD_MD_FDMA_CTRL1_K_write_en2_k(data)                                    (0x00000008&((data)<<3))
#define  MD_MD_FDMA_CTRL1_K_fdma_stop_k(data)                                    (0x00000004&((data)<<2))
#define  MD_MD_FDMA_CTRL1_K_write_en1_k(data)                                    (0x00000002&((data)<<1))
#define  MD_MD_FDMA_CTRL1_K_fdma_go_k(data)                                      (0x00000001&(data))
#define  MD_MD_FDMA_CTRL1_K_get_write_en2_k(data)                                ((0x00000008&(data))>>3)
#define  MD_MD_FDMA_CTRL1_K_get_fdma_stop_k(data)                                ((0x00000004&(data))>>2)
#define  MD_MD_FDMA_CTRL1_K_get_write_en1_k(data)                                ((0x00000002&(data))>>1)
#define  MD_MD_FDMA_CTRL1_K_get_fdma_go_k(data)                                  (0x00000001&(data))

#define  MD_MD_POWER                                                             0x1800B128
#define  MD_MD_POWER_reg_addr                                                    "0xB800B128"
#define  MD_MD_POWER_reg                                                         0xB800B128
#define  MD_MD_POWER_inst_addr                                                   "0x0024"
#define  set_MD_MD_POWER_reg(data)                                               (*((volatile unsigned int*)MD_MD_POWER_reg)=data)
#define  get_MD_MD_POWER_reg                                                     (*((volatile unsigned int*)MD_MD_POWER_reg))
#define  MD_MD_POWER_gating_en_shift                                             (0)
#define  MD_MD_POWER_gating_en_mask                                              (0x00000001)
#define  MD_MD_POWER_gating_en(data)                                             (0x00000001&(data))
#define  MD_MD_POWER_get_gating_en(data)                                         (0x00000001&(data))

#define  MD_MD_DUMMY1                                                            0x1800B09C
#define  MD_MD_DUMMY1_reg_addr                                                   "0xB800B09C"
#define  MD_MD_DUMMY1_reg                                                        0xB800B09C
#define  MD_MD_DUMMY1_inst_addr                                                  "0x0025"
#define  set_MD_MD_DUMMY1_reg(data)                                              (*((volatile unsigned int*)MD_MD_DUMMY1_reg)=data)
#define  get_MD_MD_DUMMY1_reg                                                    (*((volatile unsigned int*)MD_MD_DUMMY1_reg))
#define  MD_MD_DUMMY1_dummy1_shift                                               (0)
#define  MD_MD_DUMMY1_dummy1_mask                                                (0xFFFFFFFF)
#define  MD_MD_DUMMY1_dummy1(data)                                               (0xFFFFFFFF&(data))
#define  MD_MD_DUMMY1_get_dummy1(data)                                           (0xFFFFFFFF&(data))

#define  MD_MD_DUMMY2                                                            0x1800B0A0
#define  MD_MD_DUMMY2_reg_addr                                                   "0xB800B0A0"
#define  MD_MD_DUMMY2_reg                                                        0xB800B0A0
#define  MD_MD_DUMMY2_inst_addr                                                  "0x0026"
#define  set_MD_MD_DUMMY2_reg(data)                                              (*((volatile unsigned int*)MD_MD_DUMMY2_reg)=data)
#define  get_MD_MD_DUMMY2_reg                                                    (*((volatile unsigned int*)MD_MD_DUMMY2_reg))
#define  MD_MD_DUMMY2_dummy2_shift                                               (0)
#define  MD_MD_DUMMY2_dummy2_mask                                                (0xFFFFFFFF)
#define  MD_MD_DUMMY2_dummy2(data)                                               (0xFFFFFFFF&(data))
#define  MD_MD_DUMMY2_get_dummy2(data)                                           (0xFFFFFFFF&(data))

#define  MD_md_BIST_MODE                                                         0x1800B200
#define  MD_md_BIST_MODE_reg_addr                                                "0xB800B200"
#define  MD_md_BIST_MODE_reg                                                     0xB800B200
#define  MD_md_BIST_MODE_inst_addr                                               "0x0027"
#define  set_MD_md_BIST_MODE_reg(data)                                           (*((volatile unsigned int*)MD_md_BIST_MODE_reg)=data)
#define  get_MD_md_BIST_MODE_reg                                                 (*((volatile unsigned int*)MD_md_BIST_MODE_reg))
#define  MD_md_BIST_MODE_md_bist_mode_a_2p_shift                                 (1)
#define  MD_md_BIST_MODE_md_bist_mode_a_shift                                    (0)
#define  MD_md_BIST_MODE_md_bist_mode_a_2p_mask                                  (0x00000002)
#define  MD_md_BIST_MODE_md_bist_mode_a_mask                                     (0x00000001)
#define  MD_md_BIST_MODE_md_bist_mode_a_2p(data)                                 (0x00000002&((data)<<1))
#define  MD_md_BIST_MODE_md_bist_mode_a(data)                                    (0x00000001&(data))
#define  MD_md_BIST_MODE_get_md_bist_mode_a_2p(data)                             ((0x00000002&(data))>>1)
#define  MD_md_BIST_MODE_get_md_bist_mode_a(data)                                (0x00000001&(data))

#define  MD_md_BIST_DONE                                                         0x1800B204
#define  MD_md_BIST_DONE_reg_addr                                                "0xB800B204"
#define  MD_md_BIST_DONE_reg                                                     0xB800B204
#define  MD_md_BIST_DONE_inst_addr                                               "0x0028"
#define  set_MD_md_BIST_DONE_reg(data)                                           (*((volatile unsigned int*)MD_md_BIST_DONE_reg)=data)
#define  get_MD_md_BIST_DONE_reg                                                 (*((volatile unsigned int*)MD_md_BIST_DONE_reg))
#define  MD_md_BIST_DONE_md_bist_done_a_2p_shift                                 (1)
#define  MD_md_BIST_DONE_md_bist_done_a_shift                                    (0)
#define  MD_md_BIST_DONE_md_bist_done_a_2p_mask                                  (0x00000002)
#define  MD_md_BIST_DONE_md_bist_done_a_mask                                     (0x00000001)
#define  MD_md_BIST_DONE_md_bist_done_a_2p(data)                                 (0x00000002&((data)<<1))
#define  MD_md_BIST_DONE_md_bist_done_a(data)                                    (0x00000001&(data))
#define  MD_md_BIST_DONE_get_md_bist_done_a_2p(data)                             ((0x00000002&(data))>>1)
#define  MD_md_BIST_DONE_get_md_bist_done_a(data)                                (0x00000001&(data))

#define  MD_md_BIST_A_FAIL                                                       0x1800B20C
#define  MD_md_BIST_A_FAIL_reg_addr                                              "0xB800B20C"
#define  MD_md_BIST_A_FAIL_reg                                                   0xB800B20C
#define  MD_md_BIST_A_FAIL_inst_addr                                             "0x0029"
#define  set_MD_md_BIST_A_FAIL_reg(data)                                         (*((volatile unsigned int*)MD_md_BIST_A_FAIL_reg)=data)
#define  get_MD_md_BIST_A_FAIL_reg                                               (*((volatile unsigned int*)MD_md_BIST_A_FAIL_reg))
#define  MD_md_BIST_A_FAIL_md_bist_a_fail_1_shift                                (1)
#define  MD_md_BIST_A_FAIL_md_bist_a_fail_0_shift                                (0)
#define  MD_md_BIST_A_FAIL_md_bist_a_fail_1_mask                                 (0x00000002)
#define  MD_md_BIST_A_FAIL_md_bist_a_fail_0_mask                                 (0x00000001)
#define  MD_md_BIST_A_FAIL_md_bist_a_fail_1(data)                                (0x00000002&((data)<<1))
#define  MD_md_BIST_A_FAIL_md_bist_a_fail_0(data)                                (0x00000001&(data))
#define  MD_md_BIST_A_FAIL_get_md_bist_a_fail_1(data)                            ((0x00000002&(data))>>1)
#define  MD_md_BIST_A_FAIL_get_md_bist_a_fail_0(data)                            (0x00000001&(data))

#define  MD_md_DRF_MODE                                                          0x1800B210
#define  MD_md_DRF_MODE_reg_addr                                                 "0xB800B210"
#define  MD_md_DRF_MODE_reg                                                      0xB800B210
#define  MD_md_DRF_MODE_inst_addr                                                "0x002A"
#define  set_MD_md_DRF_MODE_reg(data)                                            (*((volatile unsigned int*)MD_md_DRF_MODE_reg)=data)
#define  get_MD_md_DRF_MODE_reg                                                  (*((volatile unsigned int*)MD_md_DRF_MODE_reg))
#define  MD_md_DRF_MODE_md_drf_mode_a_2p_shift                                   (1)
#define  MD_md_DRF_MODE_md_drf_mode_a_shift                                      (0)
#define  MD_md_DRF_MODE_md_drf_mode_a_2p_mask                                    (0x00000002)
#define  MD_md_DRF_MODE_md_drf_mode_a_mask                                       (0x00000001)
#define  MD_md_DRF_MODE_md_drf_mode_a_2p(data)                                   (0x00000002&((data)<<1))
#define  MD_md_DRF_MODE_md_drf_mode_a(data)                                      (0x00000001&(data))
#define  MD_md_DRF_MODE_get_md_drf_mode_a_2p(data)                               ((0x00000002&(data))>>1)
#define  MD_md_DRF_MODE_get_md_drf_mode_a(data)                                  (0x00000001&(data))

#define  MD_md_DRF_RESUME                                                        0x1800B214
#define  MD_md_DRF_RESUME_reg_addr                                               "0xB800B214"
#define  MD_md_DRF_RESUME_reg                                                    0xB800B214
#define  MD_md_DRF_RESUME_inst_addr                                              "0x002B"
#define  set_MD_md_DRF_RESUME_reg(data)                                          (*((volatile unsigned int*)MD_md_DRF_RESUME_reg)=data)
#define  get_MD_md_DRF_RESUME_reg                                                (*((volatile unsigned int*)MD_md_DRF_RESUME_reg))
#define  MD_md_DRF_RESUME_md_drf_resume_a_2p_shift                               (1)
#define  MD_md_DRF_RESUME_md_drf_resume_a_shift                                  (0)
#define  MD_md_DRF_RESUME_md_drf_resume_a_2p_mask                                (0x00000002)
#define  MD_md_DRF_RESUME_md_drf_resume_a_mask                                   (0x00000001)
#define  MD_md_DRF_RESUME_md_drf_resume_a_2p(data)                               (0x00000002&((data)<<1))
#define  MD_md_DRF_RESUME_md_drf_resume_a(data)                                  (0x00000001&(data))
#define  MD_md_DRF_RESUME_get_md_drf_resume_a_2p(data)                           ((0x00000002&(data))>>1)
#define  MD_md_DRF_RESUME_get_md_drf_resume_a(data)                              (0x00000001&(data))

#define  MD_md_DRF_DONE                                                          0x1800B218
#define  MD_md_DRF_DONE_reg_addr                                                 "0xB800B218"
#define  MD_md_DRF_DONE_reg                                                      0xB800B218
#define  MD_md_DRF_DONE_inst_addr                                                "0x002C"
#define  set_MD_md_DRF_DONE_reg(data)                                            (*((volatile unsigned int*)MD_md_DRF_DONE_reg)=data)
#define  get_MD_md_DRF_DONE_reg                                                  (*((volatile unsigned int*)MD_md_DRF_DONE_reg))
#define  MD_md_DRF_DONE_md_drf_done_a_2p_shift                                   (1)
#define  MD_md_DRF_DONE_md_drf_done_a_shift                                      (0)
#define  MD_md_DRF_DONE_md_drf_done_a_2p_mask                                    (0x00000002)
#define  MD_md_DRF_DONE_md_drf_done_a_mask                                       (0x00000001)
#define  MD_md_DRF_DONE_md_drf_done_a_2p(data)                                   (0x00000002&((data)<<1))
#define  MD_md_DRF_DONE_md_drf_done_a(data)                                      (0x00000001&(data))
#define  MD_md_DRF_DONE_get_md_drf_done_a_2p(data)                               ((0x00000002&(data))>>1)
#define  MD_md_DRF_DONE_get_md_drf_done_a(data)                                  (0x00000001&(data))

#define  MD_md_DRF_PAUSE                                                         0x1800B21C
#define  MD_md_DRF_PAUSE_reg_addr                                                "0xB800B21C"
#define  MD_md_DRF_PAUSE_reg                                                     0xB800B21C
#define  MD_md_DRF_PAUSE_inst_addr                                               "0x002D"
#define  set_MD_md_DRF_PAUSE_reg(data)                                           (*((volatile unsigned int*)MD_md_DRF_PAUSE_reg)=data)
#define  get_MD_md_DRF_PAUSE_reg                                                 (*((volatile unsigned int*)MD_md_DRF_PAUSE_reg))
#define  MD_md_DRF_PAUSE_md_drf_pause_a_2p_shift                                 (1)
#define  MD_md_DRF_PAUSE_md_drf_pause_a_shift                                    (0)
#define  MD_md_DRF_PAUSE_md_drf_pause_a_2p_mask                                  (0x00000002)
#define  MD_md_DRF_PAUSE_md_drf_pause_a_mask                                     (0x00000001)
#define  MD_md_DRF_PAUSE_md_drf_pause_a_2p(data)                                 (0x00000002&((data)<<1))
#define  MD_md_DRF_PAUSE_md_drf_pause_a(data)                                    (0x00000001&(data))
#define  MD_md_DRF_PAUSE_get_md_drf_pause_a_2p(data)                             ((0x00000002&(data))>>1)
#define  MD_md_DRF_PAUSE_get_md_drf_pause_a(data)                                (0x00000001&(data))

#define  MD_md_DRF_A_FAIL                                                        0x1800B220
#define  MD_md_DRF_A_FAIL_reg_addr                                               "0xB800B220"
#define  MD_md_DRF_A_FAIL_reg                                                    0xB800B220
#define  MD_md_DRF_A_FAIL_inst_addr                                              "0x002E"
#define  set_MD_md_DRF_A_FAIL_reg(data)                                          (*((volatile unsigned int*)MD_md_DRF_A_FAIL_reg)=data)
#define  get_MD_md_DRF_A_FAIL_reg                                                (*((volatile unsigned int*)MD_md_DRF_A_FAIL_reg))
#define  MD_md_DRF_A_FAIL_md_drf_a_fail_1_shift                                  (1)
#define  MD_md_DRF_A_FAIL_md_drf_a_fail_0_shift                                  (0)
#define  MD_md_DRF_A_FAIL_md_drf_a_fail_1_mask                                   (0x00000002)
#define  MD_md_DRF_A_FAIL_md_drf_a_fail_0_mask                                   (0x00000001)
#define  MD_md_DRF_A_FAIL_md_drf_a_fail_1(data)                                  (0x00000002&((data)<<1))
#define  MD_md_DRF_A_FAIL_md_drf_a_fail_0(data)                                  (0x00000001&(data))
#define  MD_md_DRF_A_FAIL_get_md_drf_a_fail_1(data)                              ((0x00000002&(data))>>1)
#define  MD_md_DRF_A_FAIL_get_md_drf_a_fail_0(data)                              (0x00000001&(data))

#define  MD_bist_dvs                                                             0x1800B228
#define  MD_bist_dvs_reg_addr                                                    "0xB800B228"
#define  MD_bist_dvs_reg                                                         0xB800B228
#define  MD_bist_dvs_inst_addr                                                   "0x002F"
#define  set_MD_bist_dvs_reg(data)                                               (*((volatile unsigned int*)MD_bist_dvs_reg)=data)
#define  get_MD_bist_dvs_reg                                                     (*((volatile unsigned int*)MD_bist_dvs_reg))
#define  MD_bist_dvs_testrwm_0_shift                                             (13)
#define  MD_bist_dvs_dvse_1_shift                                                (12)
#define  MD_bist_dvs_dvs_1_shift                                                 (8)
#define  MD_bist_dvs_dvse_0_shift                                                (4)
#define  MD_bist_dvs_dvs_0_shift                                                 (0)
#define  MD_bist_dvs_testrwm_0_mask                                              (0x00002000)
#define  MD_bist_dvs_dvse_1_mask                                                 (0x00001000)
#define  MD_bist_dvs_dvs_1_mask                                                  (0x00000F00)
#define  MD_bist_dvs_dvse_0_mask                                                 (0x00000010)
#define  MD_bist_dvs_dvs_0_mask                                                  (0x0000000F)
#define  MD_bist_dvs_testrwm_0(data)                                             (0x00002000&((data)<<13))
#define  MD_bist_dvs_dvse_1(data)                                                (0x00001000&((data)<<12))
#define  MD_bist_dvs_dvs_1(data)                                                 (0x00000F00&((data)<<8))
#define  MD_bist_dvs_dvse_0(data)                                                (0x00000010&((data)<<4))
#define  MD_bist_dvs_dvs_0(data)                                                 (0x0000000F&(data))
#define  MD_bist_dvs_get_testrwm_0(data)                                         ((0x00002000&(data))>>13)
#define  MD_bist_dvs_get_dvse_1(data)                                            ((0x00001000&(data))>>12)
#define  MD_bist_dvs_get_dvs_1(data)                                             ((0x00000F00&(data))>>8)
#define  MD_bist_dvs_get_dvse_0(data)                                            ((0x00000010&(data))>>4)
#define  MD_bist_dvs_get_dvs_0(data)                                             (0x0000000F&(data))

#define  MD_MD_REG_MODE                                                          0x1800B144
#define  MD_MD_REG_MODE_reg_addr                                                 "0xB800B144"
#define  MD_MD_REG_MODE_reg                                                      0xB800B144
#define  MD_MD_REG_MODE_inst_addr                                                "0x0030"
#define  set_MD_MD_REG_MODE_reg(data)                                            (*((volatile unsigned int*)MD_MD_REG_MODE_reg)=data)
#define  get_MD_MD_REG_MODE_reg                                                  (*((volatile unsigned int*)MD_MD_REG_MODE_reg))
#define  MD_MD_REG_MODE_reg_mode_shift                                           (0)
#define  MD_MD_REG_MODE_reg_mode_mask                                            (0x00000001)
#define  MD_MD_REG_MODE_reg_mode(data)                                           (0x00000001&(data))
#define  MD_MD_REG_MODE_get_reg_mode(data)                                       (0x00000001&(data))

#define  MD_MD_REG_CTRL                                                          0x1800B148
#define  MD_MD_REG_CTRL_reg_addr                                                 "0xB800B148"
#define  MD_MD_REG_CTRL_reg                                                      0xB800B148
#define  MD_MD_REG_CTRL_inst_addr                                                "0x0031"
#define  set_MD_MD_REG_CTRL_reg(data)                                            (*((volatile unsigned int*)MD_MD_REG_CTRL_reg)=data)
#define  get_MD_MD_REG_CTRL_reg                                                  (*((volatile unsigned int*)MD_MD_REG_CTRL_reg))
#define  MD_MD_REG_CTRL_reg_poll_shift                                           (16)
#define  MD_MD_REG_CTRL_loop_shift                                               (0)
#define  MD_MD_REG_CTRL_reg_poll_mask                                            (0x00010000)
#define  MD_MD_REG_CTRL_loop_mask                                                (0x0000FFFF)
#define  MD_MD_REG_CTRL_reg_poll(data)                                           (0x00010000&((data)<<16))
#define  MD_MD_REG_CTRL_loop(data)                                               (0x0000FFFF&(data))
#define  MD_MD_REG_CTRL_get_reg_poll(data)                                       ((0x00010000&(data))>>16)
#define  MD_MD_REG_CTRL_get_loop(data)                                           (0x0000FFFF&(data))

#define  MD_MD_REG_CMD1                                                          0x1800B14C
#define  MD_MD_REG_CMD1_reg_addr                                                 "0xB800B14C"
#define  MD_MD_REG_CMD1_reg                                                      0xB800B14C
#define  MD_MD_REG_CMD1_inst_addr                                                "0x0032"
#define  set_MD_MD_REG_CMD1_reg(data)                                            (*((volatile unsigned int*)MD_MD_REG_CMD1_reg)=data)
#define  get_MD_MD_REG_CMD1_reg                                                  (*((volatile unsigned int*)MD_MD_REG_CMD1_reg))
#define  MD_MD_REG_CMD1_cmd_word1_shift                                          (0)
#define  MD_MD_REG_CMD1_cmd_word1_mask                                           (0xFFFFFFFF)
#define  MD_MD_REG_CMD1_cmd_word1(data)                                          (0xFFFFFFFF&(data))
#define  MD_MD_REG_CMD1_get_cmd_word1(data)                                      (0xFFFFFFFF&(data))

#define  MD_MD_REG_CMD2                                                          0x1800B150
#define  MD_MD_REG_CMD2_reg_addr                                                 "0xB800B150"
#define  MD_MD_REG_CMD2_reg                                                      0xB800B150
#define  MD_MD_REG_CMD2_inst_addr                                                "0x0033"
#define  set_MD_MD_REG_CMD2_reg(data)                                            (*((volatile unsigned int*)MD_MD_REG_CMD2_reg)=data)
#define  get_MD_MD_REG_CMD2_reg                                                  (*((volatile unsigned int*)MD_MD_REG_CMD2_reg))
#define  MD_MD_REG_CMD2_cmd_word2_shift                                          (0)
#define  MD_MD_REG_CMD2_cmd_word2_mask                                           (0xFFFFFFFF)
#define  MD_MD_REG_CMD2_cmd_word2(data)                                          (0xFFFFFFFF&(data))
#define  MD_MD_REG_CMD2_get_cmd_word2(data)                                      (0xFFFFFFFF&(data))

#define  MD_MD_REG_CMD3                                                          0x1800B154
#define  MD_MD_REG_CMD3_reg_addr                                                 "0xB800B154"
#define  MD_MD_REG_CMD3_reg                                                      0xB800B154
#define  MD_MD_REG_CMD3_inst_addr                                                "0x0034"
#define  set_MD_MD_REG_CMD3_reg(data)                                            (*((volatile unsigned int*)MD_MD_REG_CMD3_reg)=data)
#define  get_MD_MD_REG_CMD3_reg                                                  (*((volatile unsigned int*)MD_MD_REG_CMD3_reg))
#define  MD_MD_REG_CMD3_cmd_word3_shift                                          (0)
#define  MD_MD_REG_CMD3_cmd_word3_mask                                           (0xFFFFFFFF)
#define  MD_MD_REG_CMD3_cmd_word3(data)                                          (0xFFFFFFFF&(data))
#define  MD_MD_REG_CMD3_get_cmd_word3(data)                                      (0xFFFFFFFF&(data))

#define  MD_MD_REG_CMD4                                                          0x1800B158
#define  MD_MD_REG_CMD4_reg_addr                                                 "0xB800B158"
#define  MD_MD_REG_CMD4_reg                                                      0xB800B158
#define  MD_MD_REG_CMD4_inst_addr                                                "0x0035"
#define  set_MD_MD_REG_CMD4_reg(data)                                            (*((volatile unsigned int*)MD_MD_REG_CMD4_reg)=data)
#define  get_MD_MD_REG_CMD4_reg                                                  (*((volatile unsigned int*)MD_MD_REG_CMD4_reg))
#define  MD_MD_REG_CMD4_cmd_word4_shift                                          (0)
#define  MD_MD_REG_CMD4_cmd_word4_mask                                           (0xFFFFFFFF)
#define  MD_MD_REG_CMD4_cmd_word4(data)                                          (0xFFFFFFFF&(data))
#define  MD_MD_REG_CMD4_get_cmd_word4(data)                                      (0xFFFFFFFF&(data))

#define  MD_MD_W_CRC_CTRL                                                        0x1800B15C
#define  MD_MD_W_CRC_CTRL_reg_addr                                               "0xB800B15C"
#define  MD_MD_W_CRC_CTRL_reg                                                    0xB800B15C
#define  MD_MD_W_CRC_CTRL_inst_addr                                              "0x0036"
#define  set_MD_MD_W_CRC_CTRL_reg(data)                                          (*((volatile unsigned int*)MD_MD_W_CRC_CTRL_reg)=data)
#define  get_MD_MD_W_CRC_CTRL_reg                                                (*((volatile unsigned int*)MD_MD_W_CRC_CTRL_reg))
#define  MD_MD_W_CRC_CTRL_auto_trigger_shift                                     (14)
#define  MD_MD_W_CRC_CTRL_const_ascending_value_shift                            (6)
#define  MD_MD_W_CRC_CTRL_const_ascending_byte_shift                             (4)
#define  MD_MD_W_CRC_CTRL_crc_const_ascending_mode_shift                         (3)
#define  MD_MD_W_CRC_CTRL_crc_data_ctrl_shift                                    (2)
#define  MD_MD_W_CRC_CTRL_w_crc_start_shift                                      (1)
#define  MD_MD_W_CRC_CTRL_w_crc_conti_shift                                      (0)
#define  MD_MD_W_CRC_CTRL_auto_trigger_mask                                      (0x00004000)
#define  MD_MD_W_CRC_CTRL_const_ascending_value_mask                             (0x00003FC0)
#define  MD_MD_W_CRC_CTRL_const_ascending_byte_mask                              (0x00000030)
#define  MD_MD_W_CRC_CTRL_crc_const_ascending_mode_mask                          (0x00000008)
#define  MD_MD_W_CRC_CTRL_crc_data_ctrl_mask                                     (0x00000004)
#define  MD_MD_W_CRC_CTRL_w_crc_start_mask                                       (0x00000002)
#define  MD_MD_W_CRC_CTRL_w_crc_conti_mask                                       (0x00000001)
#define  MD_MD_W_CRC_CTRL_auto_trigger(data)                                     (0x00004000&((data)<<14))
#define  MD_MD_W_CRC_CTRL_const_ascending_value(data)                            (0x00003FC0&((data)<<6))
#define  MD_MD_W_CRC_CTRL_const_ascending_byte(data)                             (0x00000030&((data)<<4))
#define  MD_MD_W_CRC_CTRL_crc_const_ascending_mode(data)                         (0x00000008&((data)<<3))
#define  MD_MD_W_CRC_CTRL_crc_data_ctrl(data)                                    (0x00000004&((data)<<2))
#define  MD_MD_W_CRC_CTRL_w_crc_start(data)                                      (0x00000002&((data)<<1))
#define  MD_MD_W_CRC_CTRL_w_crc_conti(data)                                      (0x00000001&(data))
#define  MD_MD_W_CRC_CTRL_get_auto_trigger(data)                                 ((0x00004000&(data))>>14)
#define  MD_MD_W_CRC_CTRL_get_const_ascending_value(data)                        ((0x00003FC0&(data))>>6)
#define  MD_MD_W_CRC_CTRL_get_const_ascending_byte(data)                         ((0x00000030&(data))>>4)
#define  MD_MD_W_CRC_CTRL_get_crc_const_ascending_mode(data)                     ((0x00000008&(data))>>3)
#define  MD_MD_W_CRC_CTRL_get_crc_data_ctrl(data)                                ((0x00000004&(data))>>2)
#define  MD_MD_W_CRC_CTRL_get_w_crc_start(data)                                  ((0x00000002&(data))>>1)
#define  MD_MD_W_CRC_CTRL_get_w_crc_conti(data)                                  (0x00000001&(data))

#define  MD_MD_W_CRC_MASK1                                                       0x1800B160
#define  MD_MD_W_CRC_MASK1_reg_addr                                              "0xB800B160"
#define  MD_MD_W_CRC_MASK1_reg                                                   0xB800B160
#define  MD_MD_W_CRC_MASK1_inst_addr                                             "0x0037"
#define  set_MD_MD_W_CRC_MASK1_reg(data)                                         (*((volatile unsigned int*)MD_MD_W_CRC_MASK1_reg)=data)
#define  get_MD_MD_W_CRC_MASK1_reg                                               (*((volatile unsigned int*)MD_MD_W_CRC_MASK1_reg))
#define  MD_MD_W_CRC_MASK1_w_crc_mask1_shift                                     (0)
#define  MD_MD_W_CRC_MASK1_w_crc_mask1_mask                                      (0xFFFFFFFF)
#define  MD_MD_W_CRC_MASK1_w_crc_mask1(data)                                     (0xFFFFFFFF&(data))
#define  MD_MD_W_CRC_MASK1_get_w_crc_mask1(data)                                 (0xFFFFFFFF&(data))

#define  MD_MD_W_CRC_MASK2                                                       0x1800B164
#define  MD_MD_W_CRC_MASK2_reg_addr                                              "0xB800B164"
#define  MD_MD_W_CRC_MASK2_reg                                                   0xB800B164
#define  MD_MD_W_CRC_MASK2_inst_addr                                             "0x0038"
#define  set_MD_MD_W_CRC_MASK2_reg(data)                                         (*((volatile unsigned int*)MD_MD_W_CRC_MASK2_reg)=data)
#define  get_MD_MD_W_CRC_MASK2_reg                                               (*((volatile unsigned int*)MD_MD_W_CRC_MASK2_reg))
#define  MD_MD_W_CRC_MASK2_w_crc_mask2_shift                                     (0)
#define  MD_MD_W_CRC_MASK2_w_crc_mask2_mask                                      (0xFFFFFFFF)
#define  MD_MD_W_CRC_MASK2_w_crc_mask2(data)                                     (0xFFFFFFFF&(data))
#define  MD_MD_W_CRC_MASK2_get_w_crc_mask2(data)                                 (0xFFFFFFFF&(data))

#define  MD_MD_W_CRC_RESULT                                                      0x1800B168
#define  MD_MD_W_CRC_RESULT_reg_addr                                             "0xB800B168"
#define  MD_MD_W_CRC_RESULT_reg                                                  0xB800B168
#define  MD_MD_W_CRC_RESULT_inst_addr                                            "0x0039"
#define  set_MD_MD_W_CRC_RESULT_reg(data)                                        (*((volatile unsigned int*)MD_MD_W_CRC_RESULT_reg)=data)
#define  get_MD_MD_W_CRC_RESULT_reg                                              (*((volatile unsigned int*)MD_MD_W_CRC_RESULT_reg))
#define  MD_MD_W_CRC_RESULT_w_crc_result_shift                                   (0)
#define  MD_MD_W_CRC_RESULT_w_crc_result_mask                                    (0xFFFFFFFF)
#define  MD_MD_W_CRC_RESULT_w_crc_result(data)                                   (0xFFFFFFFF&(data))
#define  MD_MD_W_CRC_RESULT_get_w_crc_result(data)                               (0xFFFFFFFF&(data))

#define  MD_MD_R_CRC_CTRL                                                        0x1800B16C
#define  MD_MD_R_CRC_CTRL_reg_addr                                               "0xB800B16C"
#define  MD_MD_R_CRC_CTRL_reg                                                    0xB800B16C
#define  MD_MD_R_CRC_CTRL_inst_addr                                              "0x003A"
#define  set_MD_MD_R_CRC_CTRL_reg(data)                                          (*((volatile unsigned int*)MD_MD_R_CRC_CTRL_reg)=data)
#define  get_MD_MD_R_CRC_CTRL_reg                                                (*((volatile unsigned int*)MD_MD_R_CRC_CTRL_reg))
#define  MD_MD_R_CRC_CTRL_auto_cmp_en_shift                                      (2)
#define  MD_MD_R_CRC_CTRL_r_crc_start_shift                                      (1)
#define  MD_MD_R_CRC_CTRL_r_crc_conti_shift                                      (0)
#define  MD_MD_R_CRC_CTRL_auto_cmp_en_mask                                       (0x00000004)
#define  MD_MD_R_CRC_CTRL_r_crc_start_mask                                       (0x00000002)
#define  MD_MD_R_CRC_CTRL_r_crc_conti_mask                                       (0x00000001)
#define  MD_MD_R_CRC_CTRL_auto_cmp_en(data)                                      (0x00000004&((data)<<2))
#define  MD_MD_R_CRC_CTRL_r_crc_start(data)                                      (0x00000002&((data)<<1))
#define  MD_MD_R_CRC_CTRL_r_crc_conti(data)                                      (0x00000001&(data))
#define  MD_MD_R_CRC_CTRL_get_auto_cmp_en(data)                                  ((0x00000004&(data))>>2)
#define  MD_MD_R_CRC_CTRL_get_r_crc_start(data)                                  ((0x00000002&(data))>>1)
#define  MD_MD_R_CRC_CTRL_get_r_crc_conti(data)                                  (0x00000001&(data))

#define  MD_MD_R_CRC_MASK1                                                       0x1800B170
#define  MD_MD_R_CRC_MASK1_reg_addr                                              "0xB800B170"
#define  MD_MD_R_CRC_MASK1_reg                                                   0xB800B170
#define  MD_MD_R_CRC_MASK1_inst_addr                                             "0x003B"
#define  set_MD_MD_R_CRC_MASK1_reg(data)                                         (*((volatile unsigned int*)MD_MD_R_CRC_MASK1_reg)=data)
#define  get_MD_MD_R_CRC_MASK1_reg                                               (*((volatile unsigned int*)MD_MD_R_CRC_MASK1_reg))
#define  MD_MD_R_CRC_MASK1_r_crc_mask1_shift                                     (0)
#define  MD_MD_R_CRC_MASK1_r_crc_mask1_mask                                      (0xFFFFFFFF)
#define  MD_MD_R_CRC_MASK1_r_crc_mask1(data)                                     (0xFFFFFFFF&(data))
#define  MD_MD_R_CRC_MASK1_get_r_crc_mask1(data)                                 (0xFFFFFFFF&(data))

#define  MD_MD_R_CRC_MASK2                                                       0x1800B174
#define  MD_MD_R_CRC_MASK2_reg_addr                                              "0xB800B174"
#define  MD_MD_R_CRC_MASK2_reg                                                   0xB800B174
#define  MD_MD_R_CRC_MASK2_inst_addr                                             "0x003C"
#define  set_MD_MD_R_CRC_MASK2_reg(data)                                         (*((volatile unsigned int*)MD_MD_R_CRC_MASK2_reg)=data)
#define  get_MD_MD_R_CRC_MASK2_reg                                               (*((volatile unsigned int*)MD_MD_R_CRC_MASK2_reg))
#define  MD_MD_R_CRC_MASK2_r_crc_mask2_shift                                     (0)
#define  MD_MD_R_CRC_MASK2_r_crc_mask2_mask                                      (0xFFFFFFFF)
#define  MD_MD_R_CRC_MASK2_r_crc_mask2(data)                                     (0xFFFFFFFF&(data))
#define  MD_MD_R_CRC_MASK2_get_r_crc_mask2(data)                                 (0xFFFFFFFF&(data))

#define  MD_MD_DES_CRC                                                           0x1800B178
#define  MD_MD_DES_CRC_reg_addr                                                  "0xB800B178"
#define  MD_MD_DES_CRC_reg                                                       0xB800B178
#define  MD_MD_DES_CRC_inst_addr                                                 "0x003D"
#define  set_MD_MD_DES_CRC_reg(data)                                             (*((volatile unsigned int*)MD_MD_DES_CRC_reg)=data)
#define  get_MD_MD_DES_CRC_reg                                                   (*((volatile unsigned int*)MD_MD_DES_CRC_reg))
#define  MD_MD_DES_CRC_des_crc_result_shift                                      (0)
#define  MD_MD_DES_CRC_des_crc_result_mask                                       (0xFFFFFFFF)
#define  MD_MD_DES_CRC_des_crc_result(data)                                      (0xFFFFFFFF&(data))
#define  MD_MD_DES_CRC_get_des_crc_result(data)                                  (0xFFFFFFFF&(data))

#define  MD_MD_R_CRC_RESULT                                                      0x1800B17C
#define  MD_MD_R_CRC_RESULT_reg_addr                                             "0xB800B17C"
#define  MD_MD_R_CRC_RESULT_reg                                                  0xB800B17C
#define  MD_MD_R_CRC_RESULT_inst_addr                                            "0x003E"
#define  set_MD_MD_R_CRC_RESULT_reg(data)                                        (*((volatile unsigned int*)MD_MD_R_CRC_RESULT_reg)=data)
#define  get_MD_MD_R_CRC_RESULT_reg                                              (*((volatile unsigned int*)MD_MD_R_CRC_RESULT_reg))
#define  MD_MD_R_CRC_RESULT_r_crc_result_shift                                   (0)
#define  MD_MD_R_CRC_RESULT_r_crc_result_mask                                    (0xFFFFFFFF)
#define  MD_MD_R_CRC_RESULT_r_crc_result(data)                                   (0xFFFFFFFF&(data))
#define  MD_MD_R_CRC_RESULT_get_r_crc_result(data)                               (0xFFFFFFFF&(data))

#define  MD_MD_CRC_STATUS                                                        0x1800B180
#define  MD_MD_CRC_STATUS_reg_addr                                               "0xB800B180"
#define  MD_MD_CRC_STATUS_reg                                                    0xB800B180
#define  MD_MD_CRC_STATUS_inst_addr                                              "0x003F"
#define  set_MD_MD_CRC_STATUS_reg(data)                                          (*((volatile unsigned int*)MD_MD_CRC_STATUS_reg)=data)
#define  get_MD_MD_CRC_STATUS_reg                                                (*((volatile unsigned int*)MD_MD_CRC_STATUS_reg))
#define  MD_MD_CRC_STATUS_cmd_addr_err_shift                                     (16)
#define  MD_MD_CRC_STATUS_crc_err_cnt_shift                                      (0)
#define  MD_MD_CRC_STATUS_cmd_addr_err_mask                                      (0x00010000)
#define  MD_MD_CRC_STATUS_crc_err_cnt_mask                                       (0x0000FFFF)
#define  MD_MD_CRC_STATUS_cmd_addr_err(data)                                     (0x00010000&((data)<<16))
#define  MD_MD_CRC_STATUS_crc_err_cnt(data)                                      (0x0000FFFF&(data))
#define  MD_MD_CRC_STATUS_get_cmd_addr_err(data)                                 ((0x00010000&(data))>>16)
#define  MD_MD_CRC_STATUS_get_crc_err_cnt(data)                                  (0x0000FFFF&(data))

#define  MD_MD_REG_CMD5                                                          0x1800B184
#define  MD_MD_REG_CMD5_reg_addr                                                 "0xB800B184"
#define  MD_MD_REG_CMD5_reg                                                      0xB800B184
#define  MD_MD_REG_CMD5_inst_addr                                                "0x0040"
#define  set_MD_MD_REG_CMD5_reg(data)                                            (*((volatile unsigned int*)MD_MD_REG_CMD5_reg)=data)
#define  get_MD_MD_REG_CMD5_reg                                                  (*((volatile unsigned int*)MD_MD_REG_CMD5_reg))
#define  MD_MD_REG_CMD5_cmd_word5_shift                                          (0)
#define  MD_MD_REG_CMD5_cmd_word5_mask                                           (0xFFFFFFFF)
#define  MD_MD_REG_CMD5_cmd_word5(data)                                          (0xFFFFFFFF&(data))
#define  MD_MD_REG_CMD5_get_cmd_word5(data)                                      (0xFFFFFFFF&(data))

#define  MD_MD_MULTI_REQ                                                         0x1800B230
#define  MD_MD_MULTI_REQ_reg_addr                                                "0xB800B230"
#define  MD_MD_MULTI_REQ_reg                                                     0xB800B230
#define  MD_MD_MULTI_REQ_inst_addr                                               "0x0041"
#define  set_MD_MD_MULTI_REQ_reg(data)                                           (*((volatile unsigned int*)MD_MD_MULTI_REQ_reg)=data)
#define  get_MD_MD_MULTI_REQ_reg                                                 (*((volatile unsigned int*)MD_MD_MULTI_REQ_reg))
#define  MD_MD_MULTI_REQ_cmd_wrap_en_shift                                       (5)
#define  MD_MD_MULTI_REQ_multi_req_en_shift                                      (0)
#define  MD_MD_MULTI_REQ_cmd_wrap_en_mask                                        (0x00000020)
#define  MD_MD_MULTI_REQ_multi_req_en_mask                                       (0x00000001)
#define  MD_MD_MULTI_REQ_cmd_wrap_en(data)                                       (0x00000020&((data)<<5))
#define  MD_MD_MULTI_REQ_multi_req_en(data)                                      (0x00000001&(data))
#define  MD_MD_MULTI_REQ_get_cmd_wrap_en(data)                                   ((0x00000020&(data))>>5)
#define  MD_MD_MULTI_REQ_get_multi_req_en(data)                                  (0x00000001&(data))

#define  MD_MD_DBG_PORT                                                          0x1800B188
#define  MD_MD_DBG_PORT_reg_addr                                                 "0xB800B188"
#define  MD_MD_DBG_PORT_reg                                                      0xB800B188
#define  MD_MD_DBG_PORT_inst_addr                                                "0x0042"
#define  set_MD_MD_DBG_PORT_reg(data)                                            (*((volatile unsigned int*)MD_MD_DBG_PORT_reg)=data)
#define  get_MD_MD_DBG_PORT_reg                                                  (*((volatile unsigned int*)MD_MD_DBG_PORT_reg))
#define  MD_MD_DBG_PORT_md_dbg_out1_shift                                        (16)
#define  MD_MD_DBG_PORT_md_dbg_out0_shift                                        (0)
#define  MD_MD_DBG_PORT_md_dbg_out1_mask                                         (0xFFFF0000)
#define  MD_MD_DBG_PORT_md_dbg_out0_mask                                         (0x0000FFFF)
#define  MD_MD_DBG_PORT_md_dbg_out1(data)                                        (0xFFFF0000&((data)<<16))
#define  MD_MD_DBG_PORT_md_dbg_out0(data)                                        (0x0000FFFF&(data))
#define  MD_MD_DBG_PORT_get_md_dbg_out1(data)                                    ((0xFFFF0000&(data))>>16)
#define  MD_MD_DBG_PORT_get_md_dbg_out0(data)                                    (0x0000FFFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======MD register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  smq_idle:1;
        RBus_UInt32  smq_cmd_swap:1;
        RBus_UInt32  smq_go:1;
        RBus_UInt32  write_data:1;
    };
}md_md_smq_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  fdma_go_busy:1;
        RBus_UInt32  ur_length_err:1;
        RBus_UInt32  ur_rx_timeout:1;
        RBus_UInt32  ur_rx_thd:1;
        RBus_UInt32  ur_tx_thd:1;
        RBus_UInt32  smq_mode_2b4berr:1;
        RBus_UInt32  fdma_done:1;
        RBus_UInt32  smq_empty:1;
        RBus_UInt32  smq_length_err:1;
        RBus_UInt32  smq_inst_err:1;
        RBus_UInt32  write_data:1;
    };
}md_md_smq_int_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  scpu_int_en:1;
        RBus_UInt32  ur_length_err_en:1;
        RBus_UInt32  ur_rx_timeout_en:1;
        RBus_UInt32  ur_rx_thd_en:1;
        RBus_UInt32  ur_tx_thd_en:1;
        RBus_UInt32  smq_mode_2b4b_err_en:1;
        RBus_UInt32  fdma_done_en:1;
        RBus_UInt32  smq_empty_en:1;
        RBus_UInt32  smq_length_err_en:1;
        RBus_UInt32  smq_inst_err_en:1;
        RBus_UInt32  write_data:1;
    };
}md_md_smq_int_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smq_base:28;
        RBus_UInt32  res1:4;
    };
}md_md_smqbase_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smq_limit:28;
        RBus_UInt32  res1:4;
    };
}md_md_smqlimit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smq_rdptr:28;
        RBus_UInt32  res1:4;
    };
}md_md_smqrdptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smq_wrptr:28;
        RBus_UInt32  res1:4;
    };
}md_md_smqwrptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  smq_inst_remain:5;
    };
}md_md_smqfifostate_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  smq_inst_cnt:16;
    };
}md_md_smq_instcnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  vmq_idle:1;
        RBus_UInt32  vmq_cmd_swap:1;
        RBus_UInt32  vmq_go:1;
        RBus_UInt32  write_data:1;
    };
}md_md_vmq_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  vmq_mode_2b4berr:1;
        RBus_UInt32  vmq_empty:1;
        RBus_UInt32  vmq_length_err:1;
        RBus_UInt32  vmq_inst_err:1;
        RBus_UInt32  write_data:1;
    };
}md_md_vmq_int_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  vcpu_int_en:1;
        RBus_UInt32  vmq_mode_2b4b_err_en:1;
        RBus_UInt32  vmq_empty_en:1;
        RBus_UInt32  vmq_length_err_en:1;
        RBus_UInt32  vmq_inst_err_en:1;
        RBus_UInt32  write_data:1;
    };
}md_md_vmq_int_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vmq_base:28;
        RBus_UInt32  res1:4;
    };
}md_md_vmqbase_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vmq_limit:28;
        RBus_UInt32  res1:4;
    };
}md_md_vmqlimit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vmq_rdptr:28;
        RBus_UInt32  res1:4;
    };
}md_md_vmqrdptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vmq_wrptr:28;
        RBus_UInt32  res1:4;
    };
}md_md_vmqwrptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  vmq_inst_remain:5;
    };
}md_md_vmqfifostate_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  vmq_inst_cnt:16;
    };
}md_md_vmq_instcnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  kmq_idle:1;
        RBus_UInt32  kmq_cmd_swap:1;
        RBus_UInt32  kmq_go:1;
        RBus_UInt32  write_data:1;
    };
}md_md_kmq_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  kmq_mode_2b4berr:1;
        RBus_UInt32  kmq_empty:1;
        RBus_UInt32  kmq_length_err:1;
        RBus_UInt32  kmq_inst_err:1;
        RBus_UInt32  write_data:1;
    };
}md_md_kmq_int_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  kcpu_int_en:1;
        RBus_UInt32  kmq_mode_2b4b_err_en:1;
        RBus_UInt32  kmq_empty_en:1;
        RBus_UInt32  kmq_length_err_en:1;
        RBus_UInt32  kmq_inst_err_en:1;
        RBus_UInt32  write_data:1;
    };
}md_md_kmq_int_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmq_base:28;
        RBus_UInt32  res1:4;
    };
}md_md_kmqbase_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmq_limit:28;
        RBus_UInt32  res1:4;
    };
}md_md_kmqlimit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmq_rdptr:28;
        RBus_UInt32  res1:4;
    };
}md_md_kmqrdptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmq_wrptr:28;
        RBus_UInt32  res1:4;
    };
}md_md_kmqwrptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  kmq_inst_remain:5;
    };
}md_md_kmqfifostate_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  kmq_inst_cnt:16;
    };
}md_md_kmq_instcnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  md_dbg_sel1:7;
        RBus_UInt32  md_dbg_sel0:7;
        RBus_UInt32  md_dbg_enable:1;
    };
}md_md_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fdma_ddr_saddr:32;
    };
}md_md_fdma_ddr_saddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  fdma_fl_saddr:25;
    };
}md_md_fdma_fl_saddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  fl_cp_en:1;
        RBus_UInt32  fl_mapping_mode:1;
        RBus_UInt32  fdma_swap:1;
        RBus_UInt32  fdma_max_xfer:2;
        RBus_UInt32  fdma_dir:1;
        RBus_UInt32  fdma_length:25;
    };
}md_md_fdma_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  write_en2:1;
        RBus_UInt32  fdma_stop:1;
        RBus_UInt32  write_en1:1;
        RBus_UInt32  fdma_go:1;
    };
}md_md_fdma_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  fdma_ddr_saddr_k:31;
    };
}md_md_fdma_ddr_saddr_k_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  fdma_fl_saddr_k:25;
    };
}md_md_fdma_fl_saddr_k_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  fl_cp_en_k:1;
        RBus_UInt32  fl_mapping_mode_k:1;
        RBus_UInt32  fdma_swap_k:1;
        RBus_UInt32  fdma_max_xfer_k:2;
        RBus_UInt32  fdma_dir_k:1;
        RBus_UInt32  fdma_length_k:25;
    };
}md_md_fdma_ctrl2_k_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  write_en2_k:1;
        RBus_UInt32  fdma_stop_k:1;
        RBus_UInt32  write_en1_k:1;
        RBus_UInt32  fdma_go_k:1;
    };
}md_md_fdma_ctrl1_k_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  gating_en:1;
    };
}md_md_power_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1:32;
    };
}md_md_dummy1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy2:32;
    };
}md_md_dummy2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  md_bist_mode_a_2p:1;
        RBus_UInt32  md_bist_mode_a:1;
    };
}md_md_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  md_bist_done_a_2p:1;
        RBus_UInt32  md_bist_done_a:1;
    };
}md_md_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  md_bist_a_fail_1:1;
        RBus_UInt32  md_bist_a_fail_0:1;
    };
}md_md_bist_a_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  md_drf_mode_a_2p:1;
        RBus_UInt32  md_drf_mode_a:1;
    };
}md_md_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  md_drf_resume_a_2p:1;
        RBus_UInt32  md_drf_resume_a:1;
    };
}md_md_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  md_drf_done_a_2p:1;
        RBus_UInt32  md_drf_done_a:1;
    };
}md_md_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  md_drf_pause_a_2p:1;
        RBus_UInt32  md_drf_pause_a:1;
    };
}md_md_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  md_drf_a_fail_1:1;
        RBus_UInt32  md_drf_a_fail_0:1;
    };
}md_md_drf_a_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  testrwm_0:1;
        RBus_UInt32  dvse_1:1;
        RBus_UInt32  dvs_1:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  dvse_0:1;
        RBus_UInt32  dvs_0:4;
    };
}md_bist_dvs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  reg_mode:1;
    };
}md_md_reg_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  reg_poll:1;
        RBus_UInt32  loop:16;
    };
}md_md_reg_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmd_word1:32;
    };
}md_md_reg_cmd1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmd_word2:32;
    };
}md_md_reg_cmd2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmd_word3:32;
    };
}md_md_reg_cmd3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmd_word4:32;
    };
}md_md_reg_cmd4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  auto_trigger:1;
        RBus_UInt32  const_ascending_value:8;
        RBus_UInt32  const_ascending_byte:2;
        RBus_UInt32  crc_const_ascending_mode:1;
        RBus_UInt32  crc_data_ctrl:1;
        RBus_UInt32  w_crc_start:1;
        RBus_UInt32  w_crc_conti:1;
    };
}md_md_w_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  w_crc_mask1:32;
    };
}md_md_w_crc_mask1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  w_crc_mask2:32;
    };
}md_md_w_crc_mask2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  w_crc_result:32;
    };
}md_md_w_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  auto_cmp_en:1;
        RBus_UInt32  r_crc_start:1;
        RBus_UInt32  r_crc_conti:1;
    };
}md_md_r_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_crc_mask1:32;
    };
}md_md_r_crc_mask1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_crc_mask2:32;
    };
}md_md_r_crc_mask2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  des_crc_result:32;
    };
}md_md_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_crc_result:32;
    };
}md_md_r_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  cmd_addr_err:1;
        RBus_UInt32  crc_err_cnt:16;
    };
}md_md_crc_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmd_word5:32;
    };
}md_md_reg_cmd5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  cmd_wrap_en:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  multi_req_en:1;
    };
}md_md_multi_req_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  md_dbg_out1:16;
        RBus_UInt32  md_dbg_out0:16;
    };
}md_md_dbg_port_RBUS;

#else //apply LITTLE_ENDIAN

//======MD register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  smq_go:1;
        RBus_UInt32  smq_cmd_swap:1;
        RBus_UInt32  smq_idle:1;
        RBus_UInt32  res1:28;
    };
}md_md_smq_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  smq_inst_err:1;
        RBus_UInt32  smq_length_err:1;
        RBus_UInt32  smq_empty:1;
        RBus_UInt32  fdma_done:1;
        RBus_UInt32  smq_mode_2b4berr:1;
        RBus_UInt32  ur_tx_thd:1;
        RBus_UInt32  ur_rx_thd:1;
        RBus_UInt32  ur_rx_timeout:1;
        RBus_UInt32  ur_length_err:1;
        RBus_UInt32  fdma_go_busy:1;
        RBus_UInt32  res1:21;
    };
}md_md_smq_int_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  smq_inst_err_en:1;
        RBus_UInt32  smq_length_err_en:1;
        RBus_UInt32  smq_empty_en:1;
        RBus_UInt32  fdma_done_en:1;
        RBus_UInt32  smq_mode_2b4b_err_en:1;
        RBus_UInt32  ur_tx_thd_en:1;
        RBus_UInt32  ur_rx_thd_en:1;
        RBus_UInt32  ur_rx_timeout_en:1;
        RBus_UInt32  ur_length_err_en:1;
        RBus_UInt32  scpu_int_en:1;
        RBus_UInt32  res1:21;
    };
}md_md_smq_int_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  smq_base:28;
    };
}md_md_smqbase_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  smq_limit:28;
    };
}md_md_smqlimit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  smq_rdptr:28;
    };
}md_md_smqrdptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  smq_wrptr:28;
    };
}md_md_smqwrptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smq_inst_remain:5;
        RBus_UInt32  res1:27;
    };
}md_md_smqfifostate_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smq_inst_cnt:16;
        RBus_UInt32  res1:16;
    };
}md_md_smq_instcnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  vmq_go:1;
        RBus_UInt32  vmq_cmd_swap:1;
        RBus_UInt32  vmq_idle:1;
        RBus_UInt32  res1:28;
    };
}md_md_vmq_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  vmq_inst_err:1;
        RBus_UInt32  vmq_length_err:1;
        RBus_UInt32  vmq_empty:1;
        RBus_UInt32  vmq_mode_2b4berr:1;
        RBus_UInt32  res1:27;
    };
}md_md_vmq_int_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  vmq_inst_err_en:1;
        RBus_UInt32  vmq_length_err_en:1;
        RBus_UInt32  vmq_empty_en:1;
        RBus_UInt32  vmq_mode_2b4b_err_en:1;
        RBus_UInt32  vcpu_int_en:1;
        RBus_UInt32  res1:26;
    };
}md_md_vmq_int_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  vmq_base:28;
    };
}md_md_vmqbase_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  vmq_limit:28;
    };
}md_md_vmqlimit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  vmq_rdptr:28;
    };
}md_md_vmqrdptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  vmq_wrptr:28;
    };
}md_md_vmqwrptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vmq_inst_remain:5;
        RBus_UInt32  res1:27;
    };
}md_md_vmqfifostate_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vmq_inst_cnt:16;
        RBus_UInt32  res1:16;
    };
}md_md_vmq_instcnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  kmq_go:1;
        RBus_UInt32  kmq_cmd_swap:1;
        RBus_UInt32  kmq_idle:1;
        RBus_UInt32  res1:28;
    };
}md_md_kmq_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  kmq_inst_err:1;
        RBus_UInt32  kmq_length_err:1;
        RBus_UInt32  kmq_empty:1;
        RBus_UInt32  kmq_mode_2b4berr:1;
        RBus_UInt32  res1:27;
    };
}md_md_kmq_int_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  kmq_inst_err_en:1;
        RBus_UInt32  kmq_length_err_en:1;
        RBus_UInt32  kmq_empty_en:1;
        RBus_UInt32  kmq_mode_2b4b_err_en:1;
        RBus_UInt32  kcpu_int_en:1;
        RBus_UInt32  res1:26;
    };
}md_md_kmq_int_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  kmq_base:28;
    };
}md_md_kmqbase_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  kmq_limit:28;
    };
}md_md_kmqlimit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  kmq_rdptr:28;
    };
}md_md_kmqrdptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  kmq_wrptr:28;
    };
}md_md_kmqwrptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmq_inst_remain:5;
        RBus_UInt32  res1:27;
    };
}md_md_kmqfifostate_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmq_inst_cnt:16;
        RBus_UInt32  res1:16;
    };
}md_md_kmq_instcnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  md_dbg_enable:1;
        RBus_UInt32  md_dbg_sel0:7;
        RBus_UInt32  md_dbg_sel1:7;
        RBus_UInt32  res1:17;
    };
}md_md_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fdma_ddr_saddr:32;
    };
}md_md_fdma_ddr_saddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fdma_fl_saddr:25;
        RBus_UInt32  res1:7;
    };
}md_md_fdma_fl_saddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fdma_length:25;
        RBus_UInt32  fdma_dir:1;
        RBus_UInt32  fdma_max_xfer:2;
        RBus_UInt32  fdma_swap:1;
        RBus_UInt32  fl_mapping_mode:1;
        RBus_UInt32  fl_cp_en:1;
        RBus_UInt32  res1:1;
    };
}md_md_fdma_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fdma_go:1;
        RBus_UInt32  write_en1:1;
        RBus_UInt32  fdma_stop:1;
        RBus_UInt32  write_en2:1;
        RBus_UInt32  res1:28;
    };
}md_md_fdma_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fdma_ddr_saddr_k:31;
        RBus_UInt32  res1:1;
    };
}md_md_fdma_ddr_saddr_k_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fdma_fl_saddr_k:25;
        RBus_UInt32  res1:7;
    };
}md_md_fdma_fl_saddr_k_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fdma_length_k:25;
        RBus_UInt32  fdma_dir_k:1;
        RBus_UInt32  fdma_max_xfer_k:2;
        RBus_UInt32  fdma_swap_k:1;
        RBus_UInt32  fl_mapping_mode_k:1;
        RBus_UInt32  fl_cp_en_k:1;
        RBus_UInt32  res1:1;
    };
}md_md_fdma_ctrl2_k_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fdma_go_k:1;
        RBus_UInt32  write_en1_k:1;
        RBus_UInt32  fdma_stop_k:1;
        RBus_UInt32  write_en2_k:1;
        RBus_UInt32  res1:28;
    };
}md_md_fdma_ctrl1_k_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gating_en:1;
        RBus_UInt32  res1:31;
    };
}md_md_power_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1:32;
    };
}md_md_dummy1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy2:32;
    };
}md_md_dummy2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  md_bist_mode_a:1;
        RBus_UInt32  md_bist_mode_a_2p:1;
        RBus_UInt32  res1:30;
    };
}md_md_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  md_bist_done_a:1;
        RBus_UInt32  md_bist_done_a_2p:1;
        RBus_UInt32  res1:30;
    };
}md_md_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  md_bist_a_fail_0:1;
        RBus_UInt32  md_bist_a_fail_1:1;
        RBus_UInt32  res1:30;
    };
}md_md_bist_a_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  md_drf_mode_a:1;
        RBus_UInt32  md_drf_mode_a_2p:1;
        RBus_UInt32  res1:30;
    };
}md_md_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  md_drf_resume_a:1;
        RBus_UInt32  md_drf_resume_a_2p:1;
        RBus_UInt32  res1:30;
    };
}md_md_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  md_drf_done_a:1;
        RBus_UInt32  md_drf_done_a_2p:1;
        RBus_UInt32  res1:30;
    };
}md_md_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  md_drf_pause_a:1;
        RBus_UInt32  md_drf_pause_a_2p:1;
        RBus_UInt32  res1:30;
    };
}md_md_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  md_drf_a_fail_0:1;
        RBus_UInt32  md_drf_a_fail_1:1;
        RBus_UInt32  res1:30;
    };
}md_md_drf_a_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dvs_0:4;
        RBus_UInt32  dvse_0:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  dvs_1:4;
        RBus_UInt32  dvse_1:1;
        RBus_UInt32  testrwm_0:1;
        RBus_UInt32  res2:18;
    };
}md_bist_dvs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_mode:1;
        RBus_UInt32  res1:31;
    };
}md_md_reg_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  loop:16;
        RBus_UInt32  reg_poll:1;
        RBus_UInt32  res1:15;
    };
}md_md_reg_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmd_word1:32;
    };
}md_md_reg_cmd1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmd_word2:32;
    };
}md_md_reg_cmd2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmd_word3:32;
    };
}md_md_reg_cmd3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmd_word4:32;
    };
}md_md_reg_cmd4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  w_crc_conti:1;
        RBus_UInt32  w_crc_start:1;
        RBus_UInt32  crc_data_ctrl:1;
        RBus_UInt32  crc_const_ascending_mode:1;
        RBus_UInt32  const_ascending_byte:2;
        RBus_UInt32  const_ascending_value:8;
        RBus_UInt32  auto_trigger:1;
        RBus_UInt32  res1:17;
    };
}md_md_w_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  w_crc_mask1:32;
    };
}md_md_w_crc_mask1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  w_crc_mask2:32;
    };
}md_md_w_crc_mask2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  w_crc_result:32;
    };
}md_md_w_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_crc_conti:1;
        RBus_UInt32  r_crc_start:1;
        RBus_UInt32  auto_cmp_en:1;
        RBus_UInt32  res1:29;
    };
}md_md_r_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_crc_mask1:32;
    };
}md_md_r_crc_mask1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_crc_mask2:32;
    };
}md_md_r_crc_mask2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  des_crc_result:32;
    };
}md_md_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_crc_result:32;
    };
}md_md_r_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_err_cnt:16;
        RBus_UInt32  cmd_addr_err:1;
        RBus_UInt32  res1:15;
    };
}md_md_crc_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmd_word5:32;
    };
}md_md_reg_cmd5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  multi_req_en:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  cmd_wrap_en:1;
        RBus_UInt32  res2:26;
    };
}md_md_multi_req_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  md_dbg_out0:16;
        RBus_UInt32  md_dbg_out1:16;
    };
}md_md_dbg_port_RBUS;




#endif 
#endif 
