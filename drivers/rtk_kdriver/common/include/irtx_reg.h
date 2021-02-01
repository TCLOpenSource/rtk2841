/**
* @file rbusIRTXReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_IRTX_REG_H_
#define _RBUS_IRTX_REG_H_

#include "rbus_types.h"



//  IRTX Register Address
#define  IRTX_IrTX_CTRL0                                                         0x1801BE00
#define  IRTX_IrTX_CTRL0_reg_addr                                                "0xB801BE00"
#define  IRTX_IrTX_CTRL0_reg                                                     0xB801BE00
#define  IRTX_IrTX_CTRL0_inst_addr                                               "0x0000"
#define  set_IRTX_IrTX_CTRL0_reg(data)                                           (*((volatile unsigned int*)IRTX_IrTX_CTRL0_reg)=data)
#define  get_IRTX_IrTX_CTRL0_reg                                                 (*((volatile unsigned int*)IRTX_IrTX_CTRL0_reg))
#define  IRTX_IrTX_CTRL0_dma_mode_shift                                          (31)
#define  IRTX_IrTX_CTRL0_frame_mode_shift                                        (9)
#define  IRTX_IrTX_CTRL0_h_sync_mode_sel_shift                                   (8)
#define  IRTX_IrTX_CTRL0_function_sel_shift                                      (7)
#define  IRTX_IrTX_CTRL0_default_val_shift                                       (6)
#define  IRTX_IrTX_CTRL0_l_r_change_shift                                        (5)
#define  IRTX_IrTX_CTRL0_modulation_shift                                        (4)
#define  IRTX_IrTX_CTRL0_endian_shift                                            (3)
#define  IRTX_IrTX_CTRL0_fifoout_inv_shift                                       (2)
#define  IRTX_IrTX_CTRL0_irtxout_inv_shift                                       (1)
#define  IRTX_IrTX_CTRL0_irtx_en_shift                                           (0)
#define  IRTX_IrTX_CTRL0_dma_mode_mask                                           (0x80000000)
#define  IRTX_IrTX_CTRL0_frame_mode_mask                                         (0x00000200)
#define  IRTX_IrTX_CTRL0_h_sync_mode_sel_mask                                    (0x00000100)
#define  IRTX_IrTX_CTRL0_function_sel_mask                                       (0x00000080)
#define  IRTX_IrTX_CTRL0_default_val_mask                                        (0x00000040)
#define  IRTX_IrTX_CTRL0_l_r_change_mask                                         (0x00000020)
#define  IRTX_IrTX_CTRL0_modulation_mask                                         (0x00000010)
#define  IRTX_IrTX_CTRL0_endian_mask                                             (0x00000008)
#define  IRTX_IrTX_CTRL0_fifoout_inv_mask                                        (0x00000004)
#define  IRTX_IrTX_CTRL0_irtxout_inv_mask                                        (0x00000002)
#define  IRTX_IrTX_CTRL0_irtx_en_mask                                            (0x00000001)
#define  IRTX_IrTX_CTRL0_dma_mode(data)                                          (0x80000000&((data)<<31))
#define  IRTX_IrTX_CTRL0_frame_mode(data)                                        (0x00000200&((data)<<9))
#define  IRTX_IrTX_CTRL0_h_sync_mode_sel(data)                                   (0x00000100&((data)<<8))
#define  IRTX_IrTX_CTRL0_function_sel(data)                                      (0x00000080&((data)<<7))
#define  IRTX_IrTX_CTRL0_default_val(data)                                       (0x00000040&((data)<<6))
#define  IRTX_IrTX_CTRL0_l_r_change(data)                                        (0x00000020&((data)<<5))
#define  IRTX_IrTX_CTRL0_modulation(data)                                        (0x00000010&((data)<<4))
#define  IRTX_IrTX_CTRL0_endian(data)                                            (0x00000008&((data)<<3))
#define  IRTX_IrTX_CTRL0_fifoout_inv(data)                                       (0x00000004&((data)<<2))
#define  IRTX_IrTX_CTRL0_irtxout_inv(data)                                       (0x00000002&((data)<<1))
#define  IRTX_IrTX_CTRL0_irtx_en(data)                                           (0x00000001&(data))
#define  IRTX_IrTX_CTRL0_get_dma_mode(data)                                      ((0x80000000&(data))>>31)
#define  IRTX_IrTX_CTRL0_get_frame_mode(data)                                    ((0x00000200&(data))>>9)
#define  IRTX_IrTX_CTRL0_get_h_sync_mode_sel(data)                               ((0x00000100&(data))>>8)
#define  IRTX_IrTX_CTRL0_get_function_sel(data)                                  ((0x00000080&(data))>>7)
#define  IRTX_IrTX_CTRL0_get_default_val(data)                                   ((0x00000040&(data))>>6)
#define  IRTX_IrTX_CTRL0_get_l_r_change(data)                                    ((0x00000020&(data))>>5)
#define  IRTX_IrTX_CTRL0_get_modulation(data)                                    ((0x00000010&(data))>>4)
#define  IRTX_IrTX_CTRL0_get_endian(data)                                        ((0x00000008&(data))>>3)
#define  IRTX_IrTX_CTRL0_get_fifoout_inv(data)                                   ((0x00000004&(data))>>2)
#define  IRTX_IrTX_CTRL0_get_irtxout_inv(data)                                   ((0x00000002&(data))>>1)
#define  IRTX_IrTX_CTRL0_get_irtx_en(data)                                       (0x00000001&(data))

#define  IRTX_IrTX_CTRL1                                                         0x1801BE04
#define  IRTX_IrTX_CTRL1_reg_addr                                                "0xB801BE04"
#define  IRTX_IrTX_CTRL1_reg                                                     0xB801BE04
#define  IRTX_IrTX_CTRL1_inst_addr                                               "0x0001"
#define  set_IRTX_IrTX_CTRL1_reg(data)                                           (*((volatile unsigned int*)IRTX_IrTX_CTRL1_reg)=data)
#define  get_IRTX_IrTX_CTRL1_reg                                                 (*((volatile unsigned int*)IRTX_IrTX_CTRL1_reg))
#define  IRTX_IrTX_CTRL1_immediate_start_shift                                   (31)
#define  IRTX_IrTX_CTRL1_lfag_sync_en_shift                                      (2)
#define  IRTX_IrTX_CTRL1_double_buf_en_shift                                     (1)
#define  IRTX_IrTX_CTRL1_modulation_len_shift                                    (0)
#define  IRTX_IrTX_CTRL1_immediate_start_mask                                    (0x80000000)
#define  IRTX_IrTX_CTRL1_lfag_sync_en_mask                                       (0x00000004)
#define  IRTX_IrTX_CTRL1_double_buf_en_mask                                      (0x00000002)
#define  IRTX_IrTX_CTRL1_modulation_len_mask                                     (0x00000001)
#define  IRTX_IrTX_CTRL1_immediate_start(data)                                   (0x80000000&((data)<<31))
#define  IRTX_IrTX_CTRL1_lfag_sync_en(data)                                      (0x00000004&((data)<<2))
#define  IRTX_IrTX_CTRL1_double_buf_en(data)                                     (0x00000002&((data)<<1))
#define  IRTX_IrTX_CTRL1_modulation_len(data)                                    (0x00000001&(data))
#define  IRTX_IrTX_CTRL1_get_immediate_start(data)                               ((0x80000000&(data))>>31)
#define  IRTX_IrTX_CTRL1_get_lfag_sync_en(data)                                  ((0x00000004&(data))>>2)
#define  IRTX_IrTX_CTRL1_get_double_buf_en(data)                                 ((0x00000002&(data))>>1)
#define  IRTX_IrTX_CTRL1_get_modulation_len(data)                                (0x00000001&(data))

#define  IRTX_H_sync_target1                                                     0x1801BE08
#define  IRTX_H_sync_target1_reg_addr                                            "0xB801BE08"
#define  IRTX_H_sync_target1_reg                                                 0xB801BE08
#define  IRTX_H_sync_target1_inst_addr                                           "0x0002"
#define  set_IRTX_H_sync_target1_reg(data)                                       (*((volatile unsigned int*)IRTX_H_sync_target1_reg)=data)
#define  get_IRTX_H_sync_target1_reg                                             (*((volatile unsigned int*)IRTX_H_sync_target1_reg))
#define  IRTX_H_sync_target1_counter_target1_shift                               (0)
#define  IRTX_H_sync_target1_counter_target1_mask                                (0x00000FFF)
#define  IRTX_H_sync_target1_counter_target1(data)                               (0x00000FFF&(data))
#define  IRTX_H_sync_target1_get_counter_target1(data)                           (0x00000FFF&(data))

#define  IRTX_H_sync_target2                                                     0x1801BE0C
#define  IRTX_H_sync_target2_reg_addr                                            "0xB801BE0C"
#define  IRTX_H_sync_target2_reg                                                 0xB801BE0C
#define  IRTX_H_sync_target2_inst_addr                                           "0x0003"
#define  set_IRTX_H_sync_target2_reg(data)                                       (*((volatile unsigned int*)IRTX_H_sync_target2_reg)=data)
#define  get_IRTX_H_sync_target2_reg                                             (*((volatile unsigned int*)IRTX_H_sync_target2_reg))
#define  IRTX_H_sync_target2_counter_target2_shift                               (0)
#define  IRTX_H_sync_target2_counter_target2_mask                                (0x00000FFF)
#define  IRTX_H_sync_target2_counter_target2(data)                               (0x00000FFF&(data))
#define  IRTX_H_sync_target2_get_counter_target2(data)                           (0x00000FFF&(data))

#define  IRTX_sampling_CTRL                                                      0x1801BE10
#define  IRTX_sampling_CTRL_reg_addr                                             "0xB801BE10"
#define  IRTX_sampling_CTRL_reg                                                  0xB801BE10
#define  IRTX_sampling_CTRL_inst_addr                                            "0x0004"
#define  set_IRTX_sampling_CTRL_reg(data)                                        (*((volatile unsigned int*)IRTX_sampling_CTRL_reg)=data)
#define  get_IRTX_sampling_CTRL_reg                                              (*((volatile unsigned int*)IRTX_sampling_CTRL_reg))
#define  IRTX_sampling_CTRL_df_shift                                             (0)
#define  IRTX_sampling_CTRL_df_mask                                              (0x0000FFFF)
#define  IRTX_sampling_CTRL_df(data)                                             (0x0000FFFF&(data))
#define  IRTX_sampling_CTRL_get_df(data)                                         (0x0000FFFF&(data))

#define  IRTX_Start_address1                                                     0x1801BE14
#define  IRTX_Start_address1_reg_addr                                            "0xB801BE14"
#define  IRTX_Start_address1_reg                                                 0xB801BE14
#define  IRTX_Start_address1_inst_addr                                           "0x0005"
#define  set_IRTX_Start_address1_reg(data)                                       (*((volatile unsigned int*)IRTX_Start_address1_reg)=data)
#define  get_IRTX_Start_address1_reg                                             (*((volatile unsigned int*)IRTX_Start_address1_reg))
#define  IRTX_Start_address1_start_addr_1_shift                                  (0)
#define  IRTX_Start_address1_start_addr_1_mask                                   (0xFFFFFFFF)
#define  IRTX_Start_address1_start_addr_1(data)                                  (0xFFFFFFFF&(data))
#define  IRTX_Start_address1_get_start_addr_1(data)                              (0xFFFFFFFF&(data))

#define  IRTX_Start_address2                                                     0x1801BE18
#define  IRTX_Start_address2_reg_addr                                            "0xB801BE18"
#define  IRTX_Start_address2_reg                                                 0xB801BE18
#define  IRTX_Start_address2_inst_addr                                           "0x0006"
#define  set_IRTX_Start_address2_reg(data)                                       (*((volatile unsigned int*)IRTX_Start_address2_reg)=data)
#define  get_IRTX_Start_address2_reg                                             (*((volatile unsigned int*)IRTX_Start_address2_reg))
#define  IRTX_Start_address2_start_addr_2_shift                                  (0)
#define  IRTX_Start_address2_start_addr_2_mask                                   (0xFFFFFFFF)
#define  IRTX_Start_address2_start_addr_2(data)                                  (0xFFFFFFFF&(data))
#define  IRTX_Start_address2_get_start_addr_2(data)                              (0xFFFFFFFF&(data))

#define  IRTX_Transition_Max1                                                    0x1801BE1C
#define  IRTX_Transition_Max1_reg_addr                                           "0xB801BE1C"
#define  IRTX_Transition_Max1_reg                                                0xB801BE1C
#define  IRTX_Transition_Max1_inst_addr                                          "0x0007"
#define  set_IRTX_Transition_Max1_reg(data)                                      (*((volatile unsigned int*)IRTX_Transition_Max1_reg)=data)
#define  get_IRTX_Transition_Max1_reg                                            (*((volatile unsigned int*)IRTX_Transition_Max1_reg))
#define  IRTX_Transition_Max1_max_length1_shift                                  (0)
#define  IRTX_Transition_Max1_max_length1_mask                                   (0xFFFFFFFF)
#define  IRTX_Transition_Max1_max_length1(data)                                  (0xFFFFFFFF&(data))
#define  IRTX_Transition_Max1_get_max_length1(data)                              (0xFFFFFFFF&(data))

#define  IRTX_Transition_Max2                                                    0x1801BE20
#define  IRTX_Transition_Max2_reg_addr                                           "0xB801BE20"
#define  IRTX_Transition_Max2_reg                                                0xB801BE20
#define  IRTX_Transition_Max2_inst_addr                                          "0x0008"
#define  set_IRTX_Transition_Max2_reg(data)                                      (*((volatile unsigned int*)IRTX_Transition_Max2_reg)=data)
#define  get_IRTX_Transition_Max2_reg                                            (*((volatile unsigned int*)IRTX_Transition_Max2_reg))
#define  IRTX_Transition_Max2_max_length2_shift                                  (0)
#define  IRTX_Transition_Max2_max_length2_mask                                   (0xFFFFFFFF)
#define  IRTX_Transition_Max2_max_length2(data)                                  (0xFFFFFFFF&(data))
#define  IRTX_Transition_Max2_get_max_length2(data)                              (0xFFFFFFFF&(data))

#define  IRTX_Carrier_PWM_CTRL                                                   0x1801BE24
#define  IRTX_Carrier_PWM_CTRL_reg_addr                                          "0xB801BE24"
#define  IRTX_Carrier_PWM_CTRL_reg                                               0xB801BE24
#define  IRTX_Carrier_PWM_CTRL_inst_addr                                         "0x0009"
#define  set_IRTX_Carrier_PWM_CTRL_reg(data)                                     (*((volatile unsigned int*)IRTX_Carrier_PWM_CTRL_reg)=data)
#define  get_IRTX_Carrier_PWM_CTRL_reg                                           (*((volatile unsigned int*)IRTX_Carrier_PWM_CTRL_reg))
#define  IRTX_Carrier_PWM_CTRL_pwm_clksrc_div_shift                              (16)
#define  IRTX_Carrier_PWM_CTRL_pwm_clk_duty_shift                                (8)
#define  IRTX_Carrier_PWM_CTRL_pwm_clk_div_shift                                 (0)
#define  IRTX_Carrier_PWM_CTRL_pwm_clksrc_div_mask                               (0x000F0000)
#define  IRTX_Carrier_PWM_CTRL_pwm_clk_duty_mask                                 (0x0000FF00)
#define  IRTX_Carrier_PWM_CTRL_pwm_clk_div_mask                                  (0x000000FF)
#define  IRTX_Carrier_PWM_CTRL_pwm_clksrc_div(data)                              (0x000F0000&((data)<<16))
#define  IRTX_Carrier_PWM_CTRL_pwm_clk_duty(data)                                (0x0000FF00&((data)<<8))
#define  IRTX_Carrier_PWM_CTRL_pwm_clk_div(data)                                 (0x000000FF&(data))
#define  IRTX_Carrier_PWM_CTRL_get_pwm_clksrc_div(data)                          ((0x000F0000&(data))>>16)
#define  IRTX_Carrier_PWM_CTRL_get_pwm_clk_duty(data)                            ((0x0000FF00&(data))>>8)
#define  IRTX_Carrier_PWM_CTRL_get_pwm_clk_div(data)                             (0x000000FF&(data))

#define  IRTX_TX_Set                                                             0x1801BE28
#define  IRTX_TX_Set_reg_addr                                                    "0xB801BE28"
#define  IRTX_TX_Set_reg                                                         0xB801BE28
#define  IRTX_TX_Set_inst_addr                                                   "0x000A"
#define  set_IRTX_TX_Set_reg(data)                                               (*((volatile unsigned int*)IRTX_TX_Set_reg)=data)
#define  get_IRTX_TX_Set_reg                                                     (*((volatile unsigned int*)IRTX_TX_Set_reg))
#define  IRTX_TX_Set_emp_en_shift                                                (1)
#define  IRTX_TX_Set_l_r_set_shift                                               (0)
#define  IRTX_TX_Set_emp_en_mask                                                 (0x00000002)
#define  IRTX_TX_Set_l_r_set_mask                                                (0x00000001)
#define  IRTX_TX_Set_emp_en(data)                                                (0x00000002&((data)<<1))
#define  IRTX_TX_Set_l_r_set(data)                                               (0x00000001&(data))
#define  IRTX_TX_Set_get_emp_en(data)                                            ((0x00000002&(data))>>1)
#define  IRTX_TX_Set_get_l_r_set(data)                                           (0x00000001&(data))

#define  IRTX_Status                                                             0x1801BE2C
#define  IRTX_Status_reg_addr                                                    "0xB801BE2C"
#define  IRTX_Status_reg                                                         0xB801BE2C
#define  IRTX_Status_inst_addr                                                   "0x000B"
#define  set_IRTX_Status_reg(data)                                               (*((volatile unsigned int*)IRTX_Status_reg)=data)
#define  get_IRTX_Status_reg                                                     (*((volatile unsigned int*)IRTX_Status_reg))
#define  IRTX_Status_l_r_status_shift                                            (1)
#define  IRTX_Status_emp_flag_shift                                              (0)
#define  IRTX_Status_l_r_status_mask                                             (0x00000002)
#define  IRTX_Status_emp_flag_mask                                               (0x00000001)
#define  IRTX_Status_l_r_status(data)                                            (0x00000002&((data)<<1))
#define  IRTX_Status_emp_flag(data)                                              (0x00000001&(data))
#define  IRTX_Status_get_l_r_status(data)                                        ((0x00000002&(data))>>1)
#define  IRTX_Status_get_emp_flag(data)                                          (0x00000001&(data))

#define  IRTX_FIFO_ST                                                            0x1801BE30
#define  IRTX_FIFO_ST_reg_addr                                                   "0xB801BE30"
#define  IRTX_FIFO_ST_reg                                                        0xB801BE30
#define  IRTX_FIFO_ST_inst_addr                                                  "0x000C"
#define  set_IRTX_FIFO_ST_reg(data)                                              (*((volatile unsigned int*)IRTX_FIFO_ST_reg)=data)
#define  get_IRTX_FIFO_ST_reg                                                    (*((volatile unsigned int*)IRTX_FIFO_ST_reg))
#define  IRTX_FIFO_ST_fifo_rst_shift                                             (31)
#define  IRTX_FIFO_ST_wrp_shift                                                  (8)
#define  IRTX_FIFO_ST_rdp_shift                                                  (0)
#define  IRTX_FIFO_ST_fifo_rst_mask                                              (0x80000000)
#define  IRTX_FIFO_ST_wrp_mask                                                   (0x00003F00)
#define  IRTX_FIFO_ST_rdp_mask                                                   (0x0000003F)
#define  IRTX_FIFO_ST_fifo_rst(data)                                             (0x80000000&((data)<<31))
#define  IRTX_FIFO_ST_wrp(data)                                                  (0x00003F00&((data)<<8))
#define  IRTX_FIFO_ST_rdp(data)                                                  (0x0000003F&(data))
#define  IRTX_FIFO_ST_get_fifo_rst(data)                                         ((0x80000000&(data))>>31)
#define  IRTX_FIFO_ST_get_wrp(data)                                              ((0x00003F00&(data))>>8)
#define  IRTX_FIFO_ST_get_rdp(data)                                              (0x0000003F&(data))

#define  IRTX_IRTX_FIFO                                                          0x1801BE34
#define  IRTX_IRTX_FIFO_reg_addr                                                 "0xB801BE34"
#define  IRTX_IRTX_FIFO_reg                                                      0xB801BE34
#define  IRTX_IRTX_FIFO_inst_addr                                                "0x000D"
#define  set_IRTX_IRTX_FIFO_reg(data)                                            (*((volatile unsigned int*)IRTX_IRTX_FIFO_reg)=data)
#define  get_IRTX_IRTX_FIFO_reg                                                  (*((volatile unsigned int*)IRTX_IRTX_FIFO_reg))
#define  IRTX_IRTX_FIFO_data_shift                                               (0)
#define  IRTX_IRTX_FIFO_data_mask                                                (0xFFFFFFFF)
#define  IRTX_IRTX_FIFO_data(data)                                               (0xFFFFFFFF&(data))
#define  IRTX_IRTX_FIFO_get_data(data)                                           (0xFFFFFFFF&(data))

#define  IRTX_CRC_CTRL                                                           0x1801BE38
#define  IRTX_CRC_CTRL_reg_addr                                                  "0xB801BE38"
#define  IRTX_CRC_CTRL_reg                                                       0xB801BE38
#define  IRTX_CRC_CTRL_inst_addr                                                 "0x000E"
#define  set_IRTX_CRC_CTRL_reg(data)                                             (*((volatile unsigned int*)IRTX_CRC_CTRL_reg)=data)
#define  get_IRTX_CRC_CTRL_reg                                                   (*((volatile unsigned int*)IRTX_CRC_CTRL_reg))
#define  IRTX_CRC_CTRL_crc_en_shift                                              (31)
#define  IRTX_CRC_CTRL_crc_en_mask                                               (0x80000000)
#define  IRTX_CRC_CTRL_crc_en(data)                                              (0x80000000&((data)<<31))
#define  IRTX_CRC_CTRL_get_crc_en(data)                                          ((0x80000000&(data))>>31)

#define  IRTX_CRC_INITIAL                                                        0x1801BE3C
#define  IRTX_CRC_INITIAL_reg_addr                                               "0xB801BE3C"
#define  IRTX_CRC_INITIAL_reg                                                    0xB801BE3C
#define  IRTX_CRC_INITIAL_inst_addr                                              "0x000F"
#define  set_IRTX_CRC_INITIAL_reg(data)                                          (*((volatile unsigned int*)IRTX_CRC_INITIAL_reg)=data)
#define  get_IRTX_CRC_INITIAL_reg                                                (*((volatile unsigned int*)IRTX_CRC_INITIAL_reg))
#define  IRTX_CRC_INITIAL_crc_initial_shift                                      (0)
#define  IRTX_CRC_INITIAL_crc_initial_mask                                       (0xFFFFFFFF)
#define  IRTX_CRC_INITIAL_crc_initial(data)                                      (0xFFFFFFFF&(data))
#define  IRTX_CRC_INITIAL_get_crc_initial(data)                                  (0xFFFFFFFF&(data))

#define  IRTX_IRTX_BIST                                                          0x1801BE40
#define  IRTX_IRTX_BIST_reg_addr                                                 "0xB801BE40"
#define  IRTX_IRTX_BIST_reg                                                      0xB801BE40
#define  IRTX_IRTX_BIST_inst_addr                                                "0x0010"
#define  set_IRTX_IRTX_BIST_reg(data)                                            (*((volatile unsigned int*)IRTX_IRTX_BIST_reg)=data)
#define  get_IRTX_IRTX_BIST_reg                                                  (*((volatile unsigned int*)IRTX_IRTX_BIST_reg))
#define  IRTX_IRTX_BIST_dvs_0_shift                                              (5)
#define  IRTX_IRTX_BIST_dvse_0_shift                                             (4)
#define  IRTX_IRTX_BIST_lowpower_shift                                           (2)
#define  IRTX_IRTX_BIST_dvs_0_mask                                               (0x000001E0)
#define  IRTX_IRTX_BIST_dvse_0_mask                                              (0x00000010)
#define  IRTX_IRTX_BIST_lowpower_mask                                            (0x00000004)
#define  IRTX_IRTX_BIST_dvs_0(data)                                              (0x000001E0&((data)<<5))
#define  IRTX_IRTX_BIST_dvse_0(data)                                             (0x00000010&((data)<<4))
#define  IRTX_IRTX_BIST_lowpower(data)                                           (0x00000004&((data)<<2))
#define  IRTX_IRTX_BIST_get_dvs_0(data)                                          ((0x000001E0&(data))>>5)
#define  IRTX_IRTX_BIST_get_dvse_0(data)                                         ((0x00000010&(data))>>4)
#define  IRTX_IRTX_BIST_get_lowpower(data)                                       ((0x00000004&(data))>>2)

#define  IRTX_CRC_RESULT                                                         0x1801BE44
#define  IRTX_CRC_RESULT_reg_addr                                                "0xB801BE44"
#define  IRTX_CRC_RESULT_reg                                                     0xB801BE44
#define  IRTX_CRC_RESULT_inst_addr                                               "0x0011"
#define  set_IRTX_CRC_RESULT_reg(data)                                           (*((volatile unsigned int*)IRTX_CRC_RESULT_reg)=data)
#define  get_IRTX_CRC_RESULT_reg                                                 (*((volatile unsigned int*)IRTX_CRC_RESULT_reg))
#define  IRTX_CRC_RESULT_crc_result_shift                                        (0)
#define  IRTX_CRC_RESULT_crc_result_mask                                         (0xFFFFFFFF)
#define  IRTX_CRC_RESULT_crc_result(data)                                        (0xFFFFFFFF&(data))
#define  IRTX_CRC_RESULT_get_crc_result(data)                                    (0xFFFFFFFF&(data))

#define  IRTX_IRTX_BIST_MODE                                                     0x1801BE48
#define  IRTX_IRTX_BIST_MODE_reg_addr                                            "0xB801BE48"
#define  IRTX_IRTX_BIST_MODE_reg                                                 0xB801BE48
#define  IRTX_IRTX_BIST_MODE_inst_addr                                           "0x0012"
#define  set_IRTX_IRTX_BIST_MODE_reg(data)                                       (*((volatile unsigned int*)IRTX_IRTX_BIST_MODE_reg)=data)
#define  get_IRTX_IRTX_BIST_MODE_reg                                             (*((volatile unsigned int*)IRTX_IRTX_BIST_MODE_reg))
#define  IRTX_IRTX_BIST_MODE_bist_mode_shift                                     (0)
#define  IRTX_IRTX_BIST_MODE_bist_mode_mask                                      (0x00000001)
#define  IRTX_IRTX_BIST_MODE_bist_mode(data)                                     (0x00000001&(data))
#define  IRTX_IRTX_BIST_MODE_get_bist_mode(data)                                 (0x00000001&(data))

#define  IRTX_IRTX_BIST_DONE                                                     0x1801BE4C
#define  IRTX_IRTX_BIST_DONE_reg_addr                                            "0xB801BE4C"
#define  IRTX_IRTX_BIST_DONE_reg                                                 0xB801BE4C
#define  IRTX_IRTX_BIST_DONE_inst_addr                                           "0x0013"
#define  set_IRTX_IRTX_BIST_DONE_reg(data)                                       (*((volatile unsigned int*)IRTX_IRTX_BIST_DONE_reg)=data)
#define  get_IRTX_IRTX_BIST_DONE_reg                                             (*((volatile unsigned int*)IRTX_IRTX_BIST_DONE_reg))
#define  IRTX_IRTX_BIST_DONE_bist_done_shift                                     (0)
#define  IRTX_IRTX_BIST_DONE_bist_done_mask                                      (0x00000001)
#define  IRTX_IRTX_BIST_DONE_bist_done(data)                                     (0x00000001&(data))
#define  IRTX_IRTX_BIST_DONE_get_bist_done(data)                                 (0x00000001&(data))

#define  IRTX_IRTX_BIST_FAIL                                                     0x1801BE50
#define  IRTX_IRTX_BIST_FAIL_reg_addr                                            "0xB801BE50"
#define  IRTX_IRTX_BIST_FAIL_reg                                                 0xB801BE50
#define  IRTX_IRTX_BIST_FAIL_inst_addr                                           "0x0014"
#define  set_IRTX_IRTX_BIST_FAIL_reg(data)                                       (*((volatile unsigned int*)IRTX_IRTX_BIST_FAIL_reg)=data)
#define  get_IRTX_IRTX_BIST_FAIL_reg                                             (*((volatile unsigned int*)IRTX_IRTX_BIST_FAIL_reg))
#define  IRTX_IRTX_BIST_FAIL_bist_fail_shift                                     (0)
#define  IRTX_IRTX_BIST_FAIL_bist_fail_mask                                      (0x00000001)
#define  IRTX_IRTX_BIST_FAIL_bist_fail(data)                                     (0x00000001&(data))
#define  IRTX_IRTX_BIST_FAIL_get_bist_fail(data)                                 (0x00000001&(data))

#define  IRTX_IRTX_DRF_MODE                                                      0x1801BE54
#define  IRTX_IRTX_DRF_MODE_reg_addr                                             "0xB801BE54"
#define  IRTX_IRTX_DRF_MODE_reg                                                  0xB801BE54
#define  IRTX_IRTX_DRF_MODE_inst_addr                                            "0x0015"
#define  set_IRTX_IRTX_DRF_MODE_reg(data)                                        (*((volatile unsigned int*)IRTX_IRTX_DRF_MODE_reg)=data)
#define  get_IRTX_IRTX_DRF_MODE_reg                                              (*((volatile unsigned int*)IRTX_IRTX_DRF_MODE_reg))
#define  IRTX_IRTX_DRF_MODE_drf_mode_shift                                       (0)
#define  IRTX_IRTX_DRF_MODE_drf_mode_mask                                        (0x00000001)
#define  IRTX_IRTX_DRF_MODE_drf_mode(data)                                       (0x00000001&(data))
#define  IRTX_IRTX_DRF_MODE_get_drf_mode(data)                                   (0x00000001&(data))

#define  IRTX_IRTX_DRF_RESUME                                                    0x1801BE58
#define  IRTX_IRTX_DRF_RESUME_reg_addr                                           "0xB801BE58"
#define  IRTX_IRTX_DRF_RESUME_reg                                                0xB801BE58
#define  IRTX_IRTX_DRF_RESUME_inst_addr                                          "0x0016"
#define  set_IRTX_IRTX_DRF_RESUME_reg(data)                                      (*((volatile unsigned int*)IRTX_IRTX_DRF_RESUME_reg)=data)
#define  get_IRTX_IRTX_DRF_RESUME_reg                                            (*((volatile unsigned int*)IRTX_IRTX_DRF_RESUME_reg))
#define  IRTX_IRTX_DRF_RESUME_drf_resume_shift                                   (0)
#define  IRTX_IRTX_DRF_RESUME_drf_resume_mask                                    (0x00000001)
#define  IRTX_IRTX_DRF_RESUME_drf_resume(data)                                   (0x00000001&(data))
#define  IRTX_IRTX_DRF_RESUME_get_drf_resume(data)                               (0x00000001&(data))

#define  IRTX_IRTX_DRF_DONE                                                      0x1801BE5C
#define  IRTX_IRTX_DRF_DONE_reg_addr                                             "0xB801BE5C"
#define  IRTX_IRTX_DRF_DONE_reg                                                  0xB801BE5C
#define  IRTX_IRTX_DRF_DONE_inst_addr                                            "0x0017"
#define  set_IRTX_IRTX_DRF_DONE_reg(data)                                        (*((volatile unsigned int*)IRTX_IRTX_DRF_DONE_reg)=data)
#define  get_IRTX_IRTX_DRF_DONE_reg                                              (*((volatile unsigned int*)IRTX_IRTX_DRF_DONE_reg))
#define  IRTX_IRTX_DRF_DONE_drf_done_shift                                       (0)
#define  IRTX_IRTX_DRF_DONE_drf_done_mask                                        (0x00000001)
#define  IRTX_IRTX_DRF_DONE_drf_done(data)                                       (0x00000001&(data))
#define  IRTX_IRTX_DRF_DONE_get_drf_done(data)                                   (0x00000001&(data))

#define  IRTX_IRTX_DRF_PAUSE                                                     0x1801BE60
#define  IRTX_IRTX_DRF_PAUSE_reg_addr                                            "0xB801BE60"
#define  IRTX_IRTX_DRF_PAUSE_reg                                                 0xB801BE60
#define  IRTX_IRTX_DRF_PAUSE_inst_addr                                           "0x0018"
#define  set_IRTX_IRTX_DRF_PAUSE_reg(data)                                       (*((volatile unsigned int*)IRTX_IRTX_DRF_PAUSE_reg)=data)
#define  get_IRTX_IRTX_DRF_PAUSE_reg                                             (*((volatile unsigned int*)IRTX_IRTX_DRF_PAUSE_reg))
#define  IRTX_IRTX_DRF_PAUSE_drf_pause_shift                                     (0)
#define  IRTX_IRTX_DRF_PAUSE_drf_pause_mask                                      (0x00000001)
#define  IRTX_IRTX_DRF_PAUSE_drf_pause(data)                                     (0x00000001&(data))
#define  IRTX_IRTX_DRF_PAUSE_get_drf_pause(data)                                 (0x00000001&(data))

#define  IRTX_IRTX_DRF_FAIL                                                      0x1801BE64
#define  IRTX_IRTX_DRF_FAIL_reg_addr                                             "0xB801BE64"
#define  IRTX_IRTX_DRF_FAIL_reg                                                  0xB801BE64
#define  IRTX_IRTX_DRF_FAIL_inst_addr                                            "0x0019"
#define  set_IRTX_IRTX_DRF_FAIL_reg(data)                                        (*((volatile unsigned int*)IRTX_IRTX_DRF_FAIL_reg)=data)
#define  get_IRTX_IRTX_DRF_FAIL_reg                                              (*((volatile unsigned int*)IRTX_IRTX_DRF_FAIL_reg))
#define  IRTX_IRTX_DRF_FAIL_drf_fail_shift                                       (0)
#define  IRTX_IRTX_DRF_FAIL_drf_fail_mask                                        (0x00000001)
#define  IRTX_IRTX_DRF_FAIL_drf_fail(data)                                       (0x00000001&(data))
#define  IRTX_IRTX_DRF_FAIL_get_drf_fail(data)                                   (0x00000001&(data))

#define  IRTX_IRTX_3D_GLASSES_TX                                                 0x1801BE68
#define  IRTX_IRTX_3D_GLASSES_TX_reg_addr                                        "0xB801BE68"
#define  IRTX_IRTX_3D_GLASSES_TX_reg                                             0xB801BE68
#define  IRTX_IRTX_3D_GLASSES_TX_inst_addr                                       "0x001A"
#define  set_IRTX_IRTX_3D_GLASSES_TX_reg(data)                                   (*((volatile unsigned int*)IRTX_IRTX_3D_GLASSES_TX_reg)=data)
#define  get_IRTX_IRTX_3D_GLASSES_TX_reg                                         (*((volatile unsigned int*)IRTX_IRTX_3D_GLASSES_TX_reg))
#define  IRTX_IRTX_3D_GLASSES_TX_irtx_3d_glassesmode_en_shift                    (16)
#define  IRTX_IRTX_3D_GLASSES_TX_rotation_num_shift                              (8)
#define  IRTX_IRTX_3D_GLASSES_TX_rlg_num_shift                                   (0)
#define  IRTX_IRTX_3D_GLASSES_TX_irtx_3d_glassesmode_en_mask                     (0x00010000)
#define  IRTX_IRTX_3D_GLASSES_TX_rotation_num_mask                               (0x00000700)
#define  IRTX_IRTX_3D_GLASSES_TX_rlg_num_mask                                    (0x00000007)
#define  IRTX_IRTX_3D_GLASSES_TX_irtx_3d_glassesmode_en(data)                    (0x00010000&((data)<<16))
#define  IRTX_IRTX_3D_GLASSES_TX_rotation_num(data)                              (0x00000700&((data)<<8))
#define  IRTX_IRTX_3D_GLASSES_TX_rlg_num(data)                                   (0x00000007&(data))
#define  IRTX_IRTX_3D_GLASSES_TX_get_irtx_3d_glassesmode_en(data)                ((0x00010000&(data))>>16)
#define  IRTX_IRTX_3D_GLASSES_TX_get_rotation_num(data)                          ((0x00000700&(data))>>8)
#define  IRTX_IRTX_3D_GLASSES_TX_get_rlg_num(data)                               (0x00000007&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======IRTX register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_mode:1;
        RBus_UInt32  res1:21;
        RBus_UInt32  frame_mode:1;
        RBus_UInt32  h_sync_mode_sel:1;
        RBus_UInt32  function_sel:1;
        RBus_UInt32  default_val:1;
        RBus_UInt32  l_r_change:1;
        RBus_UInt32  modulation:1;
        RBus_UInt32  endian:1;
        RBus_UInt32  fifoout_inv:1;
        RBus_UInt32  irtxout_inv:1;
        RBus_UInt32  irtx_en:1;
    };
}irtx_irtx_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  immediate_start:1;
        RBus_UInt32  res1:28;
        RBus_UInt32  lfag_sync_en:1;
        RBus_UInt32  double_buf_en:1;
        RBus_UInt32  modulation_len:1;
    };
}irtx_irtx_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  counter_target1:12;
    };
}irtx_h_sync_target1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  counter_target2:12;
    };
}irtx_h_sync_target2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  df:16;
    };
}irtx_sampling_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  start_addr_1:32;
    };
}irtx_start_address1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  start_addr_2:32;
    };
}irtx_start_address2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_length1:32;
    };
}irtx_transition_max1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_length2:32;
    };
}irtx_transition_max2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  pwm_clksrc_div:4;
        RBus_UInt32  pwm_clk_duty:8;
        RBus_UInt32  pwm_clk_div:8;
    };
}irtx_carrier_pwm_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  emp_en:1;
        RBus_UInt32  l_r_set:1;
    };
}irtx_tx_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  l_r_status:1;
        RBus_UInt32  emp_flag:1;
    };
}irtx_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fifo_rst:1;
        RBus_UInt32  res1:17;
        RBus_UInt32  wrp:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  rdp:6;
    };
}irtx_fifo_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}irtx_irtx_fifo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_en:1;
        RBus_UInt32  res1:31;
    };
}irtx_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_initial:32;
    };
}irtx_crc_initial_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:6;
        RBus_UInt32  dvs_0:4;
        RBus_UInt32  dvse_0:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  lowpower:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  res10:1;
    };
}irtx_irtx_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_result:32;
    };
}irtx_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  bist_mode:1;
    };
}irtx_irtx_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  bist_done:1;
    };
}irtx_irtx_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  bist_fail:1;
    };
}irtx_irtx_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  drf_mode:1;
    };
}irtx_irtx_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  drf_resume:1;
    };
}irtx_irtx_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  drf_done:1;
    };
}irtx_irtx_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  drf_pause:1;
    };
}irtx_irtx_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  drf_fail:1;
    };
}irtx_irtx_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  irtx_3d_glassesmode_en:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  rotation_num:3;
        RBus_UInt32  res3:5;
        RBus_UInt32  rlg_num:3;
    };
}irtx_irtx_3d_glasses_tx_RBUS;

#else //apply LITTLE_ENDIAN

//======IRTX register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  irtx_en:1;
        RBus_UInt32  irtxout_inv:1;
        RBus_UInt32  fifoout_inv:1;
        RBus_UInt32  endian:1;
        RBus_UInt32  modulation:1;
        RBus_UInt32  l_r_change:1;
        RBus_UInt32  default_val:1;
        RBus_UInt32  function_sel:1;
        RBus_UInt32  h_sync_mode_sel:1;
        RBus_UInt32  frame_mode:1;
        RBus_UInt32  res1:21;
        RBus_UInt32  dma_mode:1;
    };
}irtx_irtx_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  modulation_len:1;
        RBus_UInt32  double_buf_en:1;
        RBus_UInt32  lfag_sync_en:1;
        RBus_UInt32  res1:28;
        RBus_UInt32  immediate_start:1;
    };
}irtx_irtx_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  counter_target1:12;
        RBus_UInt32  res1:20;
    };
}irtx_h_sync_target1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  counter_target2:12;
        RBus_UInt32  res1:20;
    };
}irtx_h_sync_target2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  df:16;
        RBus_UInt32  res1:16;
    };
}irtx_sampling_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  start_addr_1:32;
    };
}irtx_start_address1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  start_addr_2:32;
    };
}irtx_start_address2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_length1:32;
    };
}irtx_transition_max1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_length2:32;
    };
}irtx_transition_max2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm_clk_div:8;
        RBus_UInt32  pwm_clk_duty:8;
        RBus_UInt32  pwm_clksrc_div:4;
        RBus_UInt32  res1:12;
    };
}irtx_carrier_pwm_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_r_set:1;
        RBus_UInt32  emp_en:1;
        RBus_UInt32  res1:30;
    };
}irtx_tx_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emp_flag:1;
        RBus_UInt32  l_r_status:1;
        RBus_UInt32  res1:30;
    };
}irtx_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rdp:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  wrp:6;
        RBus_UInt32  res2:17;
        RBus_UInt32  fifo_rst:1;
    };
}irtx_fifo_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}irtx_irtx_fifo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  crc_en:1;
    };
}irtx_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_initial:32;
    };
}irtx_crc_initial_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  lowpower:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  dvse_0:1;
        RBus_UInt32  dvs_0:4;
        RBus_UInt32  res4:6;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  res10:12;
    };
}irtx_irtx_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_result:32;
    };
}irtx_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_mode:1;
        RBus_UInt32  res1:31;
    };
}irtx_irtx_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_done:1;
        RBus_UInt32  res1:31;
    };
}irtx_irtx_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_fail:1;
        RBus_UInt32  res1:31;
    };
}irtx_irtx_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_mode:1;
        RBus_UInt32  res1:31;
    };
}irtx_irtx_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_resume:1;
        RBus_UInt32  res1:31;
    };
}irtx_irtx_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_done:1;
        RBus_UInt32  res1:31;
    };
}irtx_irtx_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_pause:1;
        RBus_UInt32  res1:31;
    };
}irtx_irtx_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_fail:1;
        RBus_UInt32  res1:31;
    };
}irtx_irtx_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rlg_num:3;
        RBus_UInt32  res1:5;
        RBus_UInt32  rotation_num:3;
        RBus_UInt32  res2:5;
        RBus_UInt32  irtx_3d_glassesmode_en:1;
        RBus_UInt32  res3:15;
    };
}irtx_irtx_3d_glasses_tx_RBUS;




#endif 


#endif 
