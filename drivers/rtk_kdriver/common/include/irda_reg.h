/**
* @file rbusIRDAReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_IRDA_REG_H_
#define _RBUS_IRDA_REG_H_

#include "rbus_types.h"



//  IRDA Register Address
#define  IRDA_IR_PSR                                                             0x18061400
#define  IRDA_IR_PSR_reg_addr                                                    "0xB8061400"
#define  IRDA_IR_PSR_reg                                                         0xB8061400
#define  IRDA_IR_PSR_inst_addr                                                   "0x0000"
#define  set_IRDA_IR_PSR_reg(data)                                               (*((volatile unsigned int*)IRDA_IR_PSR_reg)=data)
#define  get_IRDA_IR_PSR_reg                                                     (*((volatile unsigned int*)IRDA_IR_PSR_reg))
#define  IRDA_IR_PSR_lat_lead_low_shift                                          (24)
#define  IRDA_IR_PSR_lat_logic_low_shift                                         (16)
#define  IRDA_IR_PSR_lat_data0_high_shift                                        (8)
#define  IRDA_IR_PSR_lat_data1_high_shift                                        (0)
#define  IRDA_IR_PSR_lat_lead_low_mask                                           (0xFF000000)
#define  IRDA_IR_PSR_lat_logic_low_mask                                          (0x00FF0000)
#define  IRDA_IR_PSR_lat_data0_high_mask                                         (0x0000FF00)
#define  IRDA_IR_PSR_lat_data1_high_mask                                         (0x000000FF)
#define  IRDA_IR_PSR_lat_lead_low(data)                                          (0xFF000000&((data)<<24))
#define  IRDA_IR_PSR_lat_logic_low(data)                                         (0x00FF0000&((data)<<16))
#define  IRDA_IR_PSR_lat_data0_high(data)                                        (0x0000FF00&((data)<<8))
#define  IRDA_IR_PSR_lat_data1_high(data)                                        (0x000000FF&(data))
#define  IRDA_IR_PSR_get_lat_lead_low(data)                                      ((0xFF000000&(data))>>24)
#define  IRDA_IR_PSR_get_lat_logic_low(data)                                     ((0x00FF0000&(data))>>16)
#define  IRDA_IR_PSR_get_lat_data0_high(data)                                    ((0x0000FF00&(data))>>8)
#define  IRDA_IR_PSR_get_lat_data1_high(data)                                    (0x000000FF&(data))

#define  IRDA_IR_PER                                                             0x18061404
#define  IRDA_IR_PER_reg_addr                                                    "0xB8061404"
#define  IRDA_IR_PER_reg                                                         0xB8061404
#define  IRDA_IR_PER_inst_addr                                                   "0x0001"
#define  set_IRDA_IR_PER_reg(data)                                               (*((volatile unsigned int*)IRDA_IR_PER_reg)=data)
#define  get_IRDA_IR_PER_reg                                                     (*((volatile unsigned int*)IRDA_IR_PER_reg))
#define  IRDA_IR_PER_ir_data_width_shift                                         (24)
#define  IRDA_IR_PER_ir_data_width_rst_shift                                     (23)
#define  IRDA_IR_PER_ir_data_cnt_sel_shift                                       (22)
#define  IRDA_IR_PER_lat_denos_num_shift                                         (16)
#define  IRDA_IR_PER_lat_rpt_high_shift                                          (8)
#define  IRDA_IR_PER_lat_lead_high_shift                                         (0)
#define  IRDA_IR_PER_ir_data_width_mask                                          (0xFF000000)
#define  IRDA_IR_PER_ir_data_width_rst_mask                                      (0x00800000)
#define  IRDA_IR_PER_ir_data_cnt_sel_mask                                        (0x00400000)
#define  IRDA_IR_PER_lat_denos_num_mask                                          (0x003F0000)
#define  IRDA_IR_PER_lat_rpt_high_mask                                           (0x0000FF00)
#define  IRDA_IR_PER_lat_lead_high_mask                                          (0x000000FF)
#define  IRDA_IR_PER_ir_data_width(data)                                         (0xFF000000&((data)<<24))
#define  IRDA_IR_PER_ir_data_width_rst(data)                                     (0x00800000&((data)<<23))
#define  IRDA_IR_PER_ir_data_cnt_sel(data)                                       (0x00400000&((data)<<22))
#define  IRDA_IR_PER_lat_denos_num(data)                                         (0x003F0000&((data)<<16))
#define  IRDA_IR_PER_lat_rpt_high(data)                                          (0x0000FF00&((data)<<8))
#define  IRDA_IR_PER_lat_lead_high(data)                                         (0x000000FF&(data))
#define  IRDA_IR_PER_get_ir_data_width(data)                                     ((0xFF000000&(data))>>24)
#define  IRDA_IR_PER_get_ir_data_width_rst(data)                                 ((0x00800000&(data))>>23)
#define  IRDA_IR_PER_get_ir_data_cnt_sel(data)                                   ((0x00400000&(data))>>22)
#define  IRDA_IR_PER_get_lat_denos_num(data)                                     ((0x003F0000&(data))>>16)
#define  IRDA_IR_PER_get_lat_rpt_high(data)                                      ((0x0000FF00&(data))>>8)
#define  IRDA_IR_PER_get_lat_lead_high(data)                                     (0x000000FF&(data))

#define  IRDA_IR_SF                                                              0x18061408
#define  IRDA_IR_SF_reg_addr                                                     "0xB8061408"
#define  IRDA_IR_SF_reg                                                          0xB8061408
#define  IRDA_IR_SF_inst_addr                                                    "0x0002"
#define  set_IRDA_IR_SF_reg(data)                                                (*((volatile unsigned int*)IRDA_IR_SF_reg)=data)
#define  get_IRDA_IR_SF_reg                                                      (*((volatile unsigned int*)IRDA_IR_SF_reg))
#define  IRDA_IR_SF_irit_shift                                                   (24)
#define  IRDA_IR_SF_iroct_shift                                                  (16)
#define  IRDA_IR_SF_irfd_shift                                                   (0)
#define  IRDA_IR_SF_irit_mask                                                    (0xFF000000)
#define  IRDA_IR_SF_iroct_mask                                                   (0x00FF0000)
#define  IRDA_IR_SF_irfd_mask                                                    (0x0000FFFF)
#define  IRDA_IR_SF_irit(data)                                                   (0xFF000000&((data)<<24))
#define  IRDA_IR_SF_iroct(data)                                                  (0x00FF0000&((data)<<16))
#define  IRDA_IR_SF_irfd(data)                                                   (0x0000FFFF&(data))
#define  IRDA_IR_SF_get_irit(data)                                               ((0xFF000000&(data))>>24)
#define  IRDA_IR_SF_get_iroct(data)                                              ((0x00FF0000&(data))>>16)
#define  IRDA_IR_SF_get_irfd(data)                                               (0x0000FFFF&(data))

#define  IRDA_IR_DPIR                                                            0x1806140C
#define  IRDA_IR_DPIR_reg_addr                                                   "0xB806140C"
#define  IRDA_IR_DPIR_reg                                                        0xB806140C
#define  IRDA_IR_DPIR_inst_addr                                                  "0x0003"
#define  set_IRDA_IR_DPIR_reg(data)                                              (*((volatile unsigned int*)IRDA_IR_DPIR_reg)=data)
#define  get_IRDA_IR_DPIR_reg                                                    (*((volatile unsigned int*)IRDA_IR_DPIR_reg))
#define  IRDA_IR_DPIR_ir_data_with_limit_shift                                   (16)
#define  IRDA_IR_DPIR_iriotcdp_shift                                             (0)
#define  IRDA_IR_DPIR_ir_data_with_limit_mask                                    (0xFFFF0000)
#define  IRDA_IR_DPIR_iriotcdp_mask                                              (0x0000FFFF)
#define  IRDA_IR_DPIR_ir_data_with_limit(data)                                   (0xFFFF0000&((data)<<16))
#define  IRDA_IR_DPIR_iriotcdp(data)                                             (0x0000FFFF&(data))
#define  IRDA_IR_DPIR_get_ir_data_with_limit(data)                               ((0xFFFF0000&(data))>>16)
#define  IRDA_IR_DPIR_get_iriotcdp(data)                                         (0x0000FFFF&(data))

#define  IRDA_IR_CR                                                              0x18061410
#define  IRDA_IR_CR_reg_addr                                                     "0xB8061410"
#define  IRDA_IR_CR_reg                                                          0xB8061410
#define  IRDA_IR_CR_inst_addr                                                    "0x0004"
#define  set_IRDA_IR_CR_reg(data)                                                (*((volatile unsigned int*)IRDA_IR_CR_reg)=data)
#define  get_IRDA_IR_CR_reg                                                      (*((volatile unsigned int*)IRDA_IR_CR_reg))
#define  IRDA_IR_CR_burst_len_check_old_shift                                    (25)
#define  IRDA_IR_CR_ir_data_limit_en_shift                                       (24)
#define  IRDA_IR_CR_irednm_shift                                                 (23)
#define  IRDA_IR_CR_rc5_rc6_common_mode_shift                                    (22)
#define  IRDA_IR_CR_iredn_shift                                                  (16)
#define  IRDA_IR_CR_burst_len_check_shift                                        (15)
#define  IRDA_IR_CR_normal_data_num_en_shift                                     (12)
#define  IRDA_IR_CR_ir_sony_sirc_shift                                           (11)
#define  IRDA_IR_CR_ir_hwval_ie_shift                                            (10)
#define  IRDA_IR_CR_lat_rx_endian_shift                                          (9)
#define  IRDA_IR_CR_main0_en_shift                                               (8)
#define  IRDA_IR_CR_lat_ph_len_shift                                             (7)
#define  IRDA_IR_CR_lat_burst_mode_shift                                         (6)
#define  IRDA_IR_CR_lat_data_ph_shift                                            (5)
#define  IRDA_IR_CR_lat_data_num_shift                                           (0)
#define  IRDA_IR_CR_burst_len_check_old_mask                                     (0x02000000)
#define  IRDA_IR_CR_ir_data_limit_en_mask                                        (0x01000000)
#define  IRDA_IR_CR_irednm_mask                                                  (0x00800000)
#define  IRDA_IR_CR_rc5_rc6_common_mode_mask                                     (0x00400000)
#define  IRDA_IR_CR_iredn_mask                                                   (0x003F0000)
#define  IRDA_IR_CR_burst_len_check_mask                                         (0x00008000)
#define  IRDA_IR_CR_normal_data_num_en_mask                                      (0x00001000)
#define  IRDA_IR_CR_ir_sony_sirc_mask                                            (0x00000800)
#define  IRDA_IR_CR_ir_hwval_ie_mask                                             (0x00000400)
#define  IRDA_IR_CR_lat_rx_endian_mask                                           (0x00000200)
#define  IRDA_IR_CR_main0_en_mask                                                (0x00000100)
#define  IRDA_IR_CR_lat_ph_len_mask                                              (0x00000080)
#define  IRDA_IR_CR_lat_burst_mode_mask                                          (0x00000040)
#define  IRDA_IR_CR_lat_data_ph_mask                                             (0x00000020)
#define  IRDA_IR_CR_lat_data_num_mask                                            (0x0000001F)
#define  IRDA_IR_CR_burst_len_check_old(data)                                    (0x02000000&((data)<<25))
#define  IRDA_IR_CR_ir_data_limit_en(data)                                       (0x01000000&((data)<<24))
#define  IRDA_IR_CR_irednm(data)                                                 (0x00800000&((data)<<23))
#define  IRDA_IR_CR_rc5_rc6_common_mode(data)                                    (0x00400000&((data)<<22))
#define  IRDA_IR_CR_iredn(data)                                                  (0x003F0000&((data)<<16))
#define  IRDA_IR_CR_burst_len_check(data)                                        (0x00008000&((data)<<15))
#define  IRDA_IR_CR_normal_data_num_en(data)                                     (0x00001000&((data)<<12))
#define  IRDA_IR_CR_ir_sony_sirc(data)                                           (0x00000800&((data)<<11))
#define  IRDA_IR_CR_ir_hwval_ie(data)                                            (0x00000400&((data)<<10))
#define  IRDA_IR_CR_lat_rx_endian(data)                                          (0x00000200&((data)<<9))
#define  IRDA_IR_CR_main0_en(data)                                               (0x00000100&((data)<<8))
#define  IRDA_IR_CR_lat_ph_len(data)                                             (0x00000080&((data)<<7))
#define  IRDA_IR_CR_lat_burst_mode(data)                                         (0x00000040&((data)<<6))
#define  IRDA_IR_CR_lat_data_ph(data)                                            (0x00000020&((data)<<5))
#define  IRDA_IR_CR_lat_data_num(data)                                           (0x0000001F&(data))
#define  IRDA_IR_CR_get_burst_len_check_old(data)                                ((0x02000000&(data))>>25)
#define  IRDA_IR_CR_get_ir_data_limit_en(data)                                   ((0x01000000&(data))>>24)
#define  IRDA_IR_CR_get_irednm(data)                                             ((0x00800000&(data))>>23)
#define  IRDA_IR_CR_get_rc5_rc6_common_mode(data)                                ((0x00400000&(data))>>22)
#define  IRDA_IR_CR_get_iredn(data)                                              ((0x003F0000&(data))>>16)
#define  IRDA_IR_CR_get_burst_len_check(data)                                    ((0x00008000&(data))>>15)
#define  IRDA_IR_CR_get_normal_data_num_en(data)                                 ((0x00001000&(data))>>12)
#define  IRDA_IR_CR_get_ir_sony_sirc(data)                                       ((0x00000800&(data))>>11)
#define  IRDA_IR_CR_get_ir_hwval_ie(data)                                        ((0x00000400&(data))>>10)
#define  IRDA_IR_CR_get_lat_rx_endian(data)                                      ((0x00000200&(data))>>9)
#define  IRDA_IR_CR_get_main0_en(data)                                           ((0x00000100&(data))>>8)
#define  IRDA_IR_CR_get_lat_ph_len(data)                                         ((0x00000080&(data))>>7)
#define  IRDA_IR_CR_get_lat_burst_mode(data)                                     ((0x00000040&(data))>>6)
#define  IRDA_IR_CR_get_lat_data_ph(data)                                        ((0x00000020&(data))>>5)
#define  IRDA_IR_CR_get_lat_data_num(data)                                       (0x0000001F&(data))

#define  IRDA_IR_RP                                                              0x18061414
#define  IRDA_IR_RP_reg_addr                                                     "0xB8061414"
#define  IRDA_IR_RP_reg                                                          0xB8061414
#define  IRDA_IR_RP_inst_addr                                                    "0x0005"
#define  set_IRDA_IR_RP_reg(data)                                                (*((volatile unsigned int*)IRDA_IR_RP_reg)=data)
#define  get_IRDA_IR_RP_reg                                                      (*((volatile unsigned int*)IRDA_IR_RP_reg))
#define  IRDA_IR_RP_irrp_shift                                                   (0)
#define  IRDA_IR_RP_irrp_mask                                                    (0xFFFFFFFF)
#define  IRDA_IR_RP_irrp(data)                                                   (0xFFFFFFFF&(data))
#define  IRDA_IR_RP_get_irrp(data)                                               (0xFFFFFFFF&(data))

#define  IRDA_IR_SR                                                              0x18061418
#define  IRDA_IR_SR_reg_addr                                                     "0xB8061418"
#define  IRDA_IR_SR_reg                                                          0xB8061418
#define  IRDA_IR_SR_inst_addr                                                    "0x0006"
#define  set_IRDA_IR_SR_reg(data)                                                (*((volatile unsigned int*)IRDA_IR_SR_reg)=data)
#define  get_IRDA_IR_SR_reg                                                      (*((volatile unsigned int*)IRDA_IR_SR_reg))
#define  IRDA_IR_SR_detect_data_main_short_1_shift                               (21)
#define  IRDA_IR_SR_detect_data_main_short_0_shift                               (20)
#define  IRDA_IR_SR_second_data_num_en_shift                                     (19)
#define  IRDA_IR_SR_second_data_num_shift                                        (12)
#define  IRDA_IR_SR_data_too_long_shift                                          (11)
#define  IRDA_IR_SR_data_toggle_shift                                            (10)
#define  IRDA_IR_SR_detect_data_main_1_shift                                     (9)
#define  IRDA_IR_SR_detect_data_main_0_shift                                     (8)
#define  IRDA_IR_SR_rc6_leader_wrong_shift                                       (6)
#define  IRDA_IR_SR_data_still_toggle_shift                                      (5)
#define  IRDA_IR_SR_ov_up_fl_st_shift                                            (4)
#define  IRDA_IR_SR_data_too_long_rc56_shift                                     (2)
#define  IRDA_IR_SR_irrf_shift                                                   (1)
#define  IRDA_IR_SR_irdvf_shift                                                  (0)
#define  IRDA_IR_SR_detect_data_main_short_1_mask                                (0x00200000)
#define  IRDA_IR_SR_detect_data_main_short_0_mask                                (0x00100000)
#define  IRDA_IR_SR_second_data_num_en_mask                                      (0x00080000)
#define  IRDA_IR_SR_second_data_num_mask                                         (0x0001F000)
#define  IRDA_IR_SR_data_too_long_mask                                           (0x00000800)
#define  IRDA_IR_SR_data_toggle_mask                                             (0x00000400)
#define  IRDA_IR_SR_detect_data_main_1_mask                                      (0x00000200)
#define  IRDA_IR_SR_detect_data_main_0_mask                                      (0x00000100)
#define  IRDA_IR_SR_rc6_leader_wrong_mask                                        (0x00000040)
#define  IRDA_IR_SR_data_still_toggle_mask                                       (0x00000020)
#define  IRDA_IR_SR_ov_up_fl_st_mask                                             (0x00000010)
#define  IRDA_IR_SR_data_too_long_rc56_mask                                      (0x00000004)
#define  IRDA_IR_SR_irrf_mask                                                    (0x00000002)
#define  IRDA_IR_SR_irdvf_mask                                                   (0x00000001)
#define  IRDA_IR_SR_detect_data_main_short_1(data)                               (0x00200000&((data)<<21))
#define  IRDA_IR_SR_detect_data_main_short_0(data)                               (0x00100000&((data)<<20))
#define  IRDA_IR_SR_second_data_num_en(data)                                     (0x00080000&((data)<<19))
#define  IRDA_IR_SR_second_data_num(data)                                        (0x0001F000&((data)<<12))
#define  IRDA_IR_SR_data_too_long(data)                                          (0x00000800&((data)<<11))
#define  IRDA_IR_SR_data_toggle(data)                                            (0x00000400&((data)<<10))
#define  IRDA_IR_SR_detect_data_main_1(data)                                     (0x00000200&((data)<<9))
#define  IRDA_IR_SR_detect_data_main_0(data)                                     (0x00000100&((data)<<8))
#define  IRDA_IR_SR_rc6_leader_wrong(data)                                       (0x00000040&((data)<<6))
#define  IRDA_IR_SR_data_still_toggle(data)                                      (0x00000020&((data)<<5))
#define  IRDA_IR_SR_ov_up_fl_st(data)                                            (0x00000010&((data)<<4))
#define  IRDA_IR_SR_data_too_long_rc56(data)                                     (0x00000004&((data)<<2))
#define  IRDA_IR_SR_irrf(data)                                                   (0x00000002&((data)<<1))
#define  IRDA_IR_SR_irdvf(data)                                                  (0x00000001&(data))
#define  IRDA_IR_SR_get_detect_data_main_short_1(data)                           ((0x00200000&(data))>>21)
#define  IRDA_IR_SR_get_detect_data_main_short_0(data)                           ((0x00100000&(data))>>20)
#define  IRDA_IR_SR_get_second_data_num_en(data)                                 ((0x00080000&(data))>>19)
#define  IRDA_IR_SR_get_second_data_num(data)                                    ((0x0001F000&(data))>>12)
#define  IRDA_IR_SR_get_data_too_long(data)                                      ((0x00000800&(data))>>11)
#define  IRDA_IR_SR_get_data_toggle(data)                                        ((0x00000400&(data))>>10)
#define  IRDA_IR_SR_get_detect_data_main_1(data)                                 ((0x00000200&(data))>>9)
#define  IRDA_IR_SR_get_detect_data_main_0(data)                                 ((0x00000100&(data))>>8)
#define  IRDA_IR_SR_get_rc6_leader_wrong(data)                                   ((0x00000040&(data))>>6)
#define  IRDA_IR_SR_get_data_still_toggle(data)                                  ((0x00000020&(data))>>5)
#define  IRDA_IR_SR_get_ov_up_fl_st(data)                                        ((0x00000010&(data))>>4)
#define  IRDA_IR_SR_get_data_too_long_rc56(data)                                 ((0x00000004&(data))>>2)
#define  IRDA_IR_SR_get_irrf(data)                                               ((0x00000002&(data))>>1)
#define  IRDA_IR_SR_get_irdvf(data)                                              (0x00000001&(data))

#define  IRDA_IR_PSR_UP                                                          0x18061430
#define  IRDA_IR_PSR_UP_reg_addr                                                 "0xB8061430"
#define  IRDA_IR_PSR_UP_reg                                                      0xB8061430
#define  IRDA_IR_PSR_UP_inst_addr                                                "0x0007"
#define  set_IRDA_IR_PSR_UP_reg(data)                                            (*((volatile unsigned int*)IRDA_IR_PSR_UP_reg)=data)
#define  get_IRDA_IR_PSR_UP_reg                                                  (*((volatile unsigned int*)IRDA_IR_PSR_UP_reg))
#define  IRDA_IR_PSR_UP_irrbl_up_shift                                           (24)
#define  IRDA_IR_PSR_UP_irrml_up_shift                                           (16)
#define  IRDA_IR_PSR_UP_irrdzl_up_shift                                          (8)
#define  IRDA_IR_PSR_UP_irrdol_up_shift                                          (0)
#define  IRDA_IR_PSR_UP_irrbl_up_mask                                            (0xFF000000)
#define  IRDA_IR_PSR_UP_irrml_up_mask                                            (0x00FF0000)
#define  IRDA_IR_PSR_UP_irrdzl_up_mask                                           (0x0000FF00)
#define  IRDA_IR_PSR_UP_irrdol_up_mask                                           (0x000000FF)
#define  IRDA_IR_PSR_UP_irrbl_up(data)                                           (0xFF000000&((data)<<24))
#define  IRDA_IR_PSR_UP_irrml_up(data)                                           (0x00FF0000&((data)<<16))
#define  IRDA_IR_PSR_UP_irrdzl_up(data)                                          (0x0000FF00&((data)<<8))
#define  IRDA_IR_PSR_UP_irrdol_up(data)                                          (0x000000FF&(data))
#define  IRDA_IR_PSR_UP_get_irrbl_up(data)                                       ((0xFF000000&(data))>>24)
#define  IRDA_IR_PSR_UP_get_irrml_up(data)                                       ((0x00FF0000&(data))>>16)
#define  IRDA_IR_PSR_UP_get_irrdzl_up(data)                                      ((0x0000FF00&(data))>>8)
#define  IRDA_IR_PSR_UP_get_irrdol_up(data)                                      (0x000000FF&(data))

#define  IRDA_IR_PER_UP                                                          0x18061434
#define  IRDA_IR_PER_UP_reg_addr                                                 "0xB8061434"
#define  IRDA_IR_PER_UP_reg                                                      0xB8061434
#define  IRDA_IR_PER_UP_inst_addr                                                "0x0008"
#define  set_IRDA_IR_PER_UP_reg(data)                                            (*((volatile unsigned int*)IRDA_IR_PER_UP_reg)=data)
#define  get_IRDA_IR_PER_UP_reg                                                  (*((volatile unsigned int*)IRDA_IR_PER_UP_reg))
#define  IRDA_IR_PER_UP_irrrl_up_shift                                           (8)
#define  IRDA_IR_PER_UP_irrsl_up_shift                                           (0)
#define  IRDA_IR_PER_UP_irrrl_up_mask                                            (0x0000FF00)
#define  IRDA_IR_PER_UP_irrsl_up_mask                                            (0x000000FF)
#define  IRDA_IR_PER_UP_irrrl_up(data)                                           (0x0000FF00&((data)<<8))
#define  IRDA_IR_PER_UP_irrsl_up(data)                                           (0x000000FF&(data))
#define  IRDA_IR_PER_UP_get_irrrl_up(data)                                       ((0x0000FF00&(data))>>8)
#define  IRDA_IR_PER_UP_get_irrsl_up(data)                                       (0x000000FF&(data))

#define  IRDA_IR_CTRL_RC6                                                        0x18061438
#define  IRDA_IR_CTRL_RC6_reg_addr                                               "0xB8061438"
#define  IRDA_IR_CTRL_RC6_reg                                                    0xB8061438
#define  IRDA_IR_CTRL_RC6_inst_addr                                              "0x0009"
#define  set_IRDA_IR_CTRL_RC6_reg(data)                                          (*((volatile unsigned int*)IRDA_IR_CTRL_RC6_reg)=data)
#define  get_IRDA_IR_CTRL_RC6_reg                                                (*((volatile unsigned int*)IRDA_IR_CTRL_RC6_reg))
#define  IRDA_IR_CTRL_RC6_last_bit_length_en_shift                               (10)
#define  IRDA_IR_CTRL_RC6_toshiba_en_shift                                       (9)
#define  IRDA_IR_CTRL_RC6_rc6_en_shift                                           (8)
#define  IRDA_IR_CTRL_RC6_irtr_shift                                             (0)
#define  IRDA_IR_CTRL_RC6_last_bit_length_en_mask                                (0x00000400)
#define  IRDA_IR_CTRL_RC6_toshiba_en_mask                                        (0x00000200)
#define  IRDA_IR_CTRL_RC6_rc6_en_mask                                            (0x00000100)
#define  IRDA_IR_CTRL_RC6_irtr_mask                                              (0x000000FF)
#define  IRDA_IR_CTRL_RC6_last_bit_length_en(data)                               (0x00000400&((data)<<10))
#define  IRDA_IR_CTRL_RC6_toshiba_en(data)                                       (0x00000200&((data)<<9))
#define  IRDA_IR_CTRL_RC6_rc6_en(data)                                           (0x00000100&((data)<<8))
#define  IRDA_IR_CTRL_RC6_irtr(data)                                             (0x000000FF&(data))
#define  IRDA_IR_CTRL_RC6_get_last_bit_length_en(data)                           ((0x00000400&(data))>>10)
#define  IRDA_IR_CTRL_RC6_get_toshiba_en(data)                                   ((0x00000200&(data))>>9)
#define  IRDA_IR_CTRL_RC6_get_rc6_en(data)                                       ((0x00000100&(data))>>8)
#define  IRDA_IR_CTRL_RC6_get_irtr(data)                                         (0x000000FF&(data))

#define  IRDA_IR_RP2                                                             0x1806143C
#define  IRDA_IR_RP2_reg_addr                                                    "0xB806143C"
#define  IRDA_IR_RP2_reg                                                         0xB806143C
#define  IRDA_IR_RP2_inst_addr                                                   "0x000A"
#define  set_IRDA_IR_RP2_reg(data)                                               (*((volatile unsigned int*)IRDA_IR_RP2_reg)=data)
#define  get_IRDA_IR_RP2_reg                                                     (*((volatile unsigned int*)IRDA_IR_RP2_reg))
#define  IRDA_IR_RP2_irrp_up_shift                                               (0)
#define  IRDA_IR_RP2_irrp_up_mask                                                (0xFFFFFFFF)
#define  IRDA_IR_RP2_irrp_up(data)                                               (0xFFFFFFFF&(data))
#define  IRDA_IR_RP2_get_irrp_up(data)                                           (0xFFFFFFFF&(data))

#define  IRDA_IR_EXT_RP_CF                                                       0x18061444
#define  IRDA_IR_EXT_RP_CF_reg_addr                                              "0xB8061444"
#define  IRDA_IR_EXT_RP_CF_reg                                                   0xB8061444
#define  IRDA_IR_EXT_RP_CF_inst_addr                                             "0x000B"
#define  set_IRDA_IR_EXT_RP_CF_reg(data)                                         (*((volatile unsigned int*)IRDA_IR_EXT_RP_CF_reg)=data)
#define  get_IRDA_IR_EXT_RP_CF_reg                                               (*((volatile unsigned int*)IRDA_IR_EXT_RP_CF_reg))
#define  IRDA_IR_EXT_RP_CF_rp_num_shift                                          (4)
#define  IRDA_IR_EXT_RP_CF_ext_rp_en_shift                                       (0)
#define  IRDA_IR_EXT_RP_CF_rp_num_mask                                           (0x000000F0)
#define  IRDA_IR_EXT_RP_CF_ext_rp_en_mask                                        (0x00000001)
#define  IRDA_IR_EXT_RP_CF_rp_num(data)                                          (0x000000F0&((data)<<4))
#define  IRDA_IR_EXT_RP_CF_ext_rp_en(data)                                       (0x00000001&(data))
#define  IRDA_IR_EXT_RP_CF_get_rp_num(data)                                      ((0x000000F0&(data))>>4)
#define  IRDA_IR_EXT_RP_CF_get_ext_rp_en(data)                                   (0x00000001&(data))

#define  IRDA_IR_EXT_RP_TIMING                                                   0x18061448
#define  IRDA_IR_EXT_RP_TIMING_reg_addr                                          "0xB8061448"
#define  IRDA_IR_EXT_RP_TIMING_reg                                               0xB8061448
#define  IRDA_IR_EXT_RP_TIMING_inst_addr                                         "0x000C"
#define  set_IRDA_IR_EXT_RP_TIMING_reg(data)                                     (*((volatile unsigned int*)IRDA_IR_EXT_RP_TIMING_reg)=data)
#define  get_IRDA_IR_EXT_RP_TIMING_reg                                           (*((volatile unsigned int*)IRDA_IR_EXT_RP_TIMING_reg))
#define  IRDA_IR_EXT_RP_TIMING_rp_burst_shift                                    (24)
#define  IRDA_IR_EXT_RP_TIMING_rp_silence_shift                                  (16)
#define  IRDA_IR_EXT_RP_TIMING_rp_tail_burst_shift                               (8)
#define  IRDA_IR_EXT_RP_TIMING_rp_tail_silence_shift                             (0)
#define  IRDA_IR_EXT_RP_TIMING_rp_burst_mask                                     (0xFF000000)
#define  IRDA_IR_EXT_RP_TIMING_rp_silence_mask                                   (0x00FF0000)
#define  IRDA_IR_EXT_RP_TIMING_rp_tail_burst_mask                                (0x0000FF00)
#define  IRDA_IR_EXT_RP_TIMING_rp_tail_silence_mask                              (0x000000FF)
#define  IRDA_IR_EXT_RP_TIMING_rp_burst(data)                                    (0xFF000000&((data)<<24))
#define  IRDA_IR_EXT_RP_TIMING_rp_silence(data)                                  (0x00FF0000&((data)<<16))
#define  IRDA_IR_EXT_RP_TIMING_rp_tail_burst(data)                               (0x0000FF00&((data)<<8))
#define  IRDA_IR_EXT_RP_TIMING_rp_tail_silence(data)                             (0x000000FF&(data))
#define  IRDA_IR_EXT_RP_TIMING_get_rp_burst(data)                                ((0xFF000000&(data))>>24)
#define  IRDA_IR_EXT_RP_TIMING_get_rp_silence(data)                              ((0x00FF0000&(data))>>16)
#define  IRDA_IR_EXT_RP_TIMING_get_rp_tail_burst(data)                           ((0x0000FF00&(data))>>8)
#define  IRDA_IR_EXT_RP_TIMING_get_rp_tail_silence(data)                         (0x000000FF&(data))

#define  IRDA_IR_EXT_RP_TIMING_UP                                                0x1806144C
#define  IRDA_IR_EXT_RP_TIMING_UP_reg_addr                                       "0xB806144C"
#define  IRDA_IR_EXT_RP_TIMING_UP_reg                                            0xB806144C
#define  IRDA_IR_EXT_RP_TIMING_UP_inst_addr                                      "0x000D"
#define  set_IRDA_IR_EXT_RP_TIMING_UP_reg(data)                                  (*((volatile unsigned int*)IRDA_IR_EXT_RP_TIMING_UP_reg)=data)
#define  get_IRDA_IR_EXT_RP_TIMING_UP_reg                                        (*((volatile unsigned int*)IRDA_IR_EXT_RP_TIMING_UP_reg))
#define  IRDA_IR_EXT_RP_TIMING_UP_rp_burst_up_shift                              (24)
#define  IRDA_IR_EXT_RP_TIMING_UP_rp_silence_up_shift                            (16)
#define  IRDA_IR_EXT_RP_TIMING_UP_rp_tail_burst_up_shift                         (8)
#define  IRDA_IR_EXT_RP_TIMING_UP_rp_tail_silence_up_shift                       (0)
#define  IRDA_IR_EXT_RP_TIMING_UP_rp_burst_up_mask                               (0xFF000000)
#define  IRDA_IR_EXT_RP_TIMING_UP_rp_silence_up_mask                             (0x00FF0000)
#define  IRDA_IR_EXT_RP_TIMING_UP_rp_tail_burst_up_mask                          (0x0000FF00)
#define  IRDA_IR_EXT_RP_TIMING_UP_rp_tail_silence_up_mask                        (0x000000FF)
#define  IRDA_IR_EXT_RP_TIMING_UP_rp_burst_up(data)                              (0xFF000000&((data)<<24))
#define  IRDA_IR_EXT_RP_TIMING_UP_rp_silence_up(data)                            (0x00FF0000&((data)<<16))
#define  IRDA_IR_EXT_RP_TIMING_UP_rp_tail_burst_up(data)                         (0x0000FF00&((data)<<8))
#define  IRDA_IR_EXT_RP_TIMING_UP_rp_tail_silence_up(data)                       (0x000000FF&(data))
#define  IRDA_IR_EXT_RP_TIMING_UP_get_rp_burst_up(data)                          ((0xFF000000&(data))>>24)
#define  IRDA_IR_EXT_RP_TIMING_UP_get_rp_silence_up(data)                        ((0x00FF0000&(data))>>16)
#define  IRDA_IR_EXT_RP_TIMING_UP_get_rp_tail_burst_up(data)                     ((0x0000FF00&(data))>>8)
#define  IRDA_IR_EXT_RP_TIMING_UP_get_rp_tail_silence_up(data)                   (0x000000FF&(data))

#define  IRDA_HW_decode_sel                                                      0x18061450
#define  IRDA_HW_decode_sel_reg_addr                                             "0xB8061450"
#define  IRDA_HW_decode_sel_reg                                                  0xB8061450
#define  IRDA_HW_decode_sel_inst_addr                                            "0x000E"
#define  set_IRDA_HW_decode_sel_reg(data)                                        (*((volatile unsigned int*)IRDA_HW_decode_sel_reg)=data)
#define  get_IRDA_HW_decode_sel_reg                                              (*((volatile unsigned int*)IRDA_HW_decode_sel_reg))
#define  IRDA_HW_decode_sel_decode_mask_data_en_shift                            (15)
#define  IRDA_HW_decode_sel_decode_mask_data_sel_shift                           (8)
#define  IRDA_HW_decode_sel_hw_decode_data_en_shift                              (7)
#define  IRDA_HW_decode_sel_hw_decode_data_sel_shift                             (0)
#define  IRDA_HW_decode_sel_decode_mask_data_en_mask                             (0x00008000)
#define  IRDA_HW_decode_sel_decode_mask_data_sel_mask                            (0x00001F00)
#define  IRDA_HW_decode_sel_hw_decode_data_en_mask                               (0x00000080)
#define  IRDA_HW_decode_sel_hw_decode_data_sel_mask                              (0x0000001F)
#define  IRDA_HW_decode_sel_decode_mask_data_en(data)                            (0x00008000&((data)<<15))
#define  IRDA_HW_decode_sel_decode_mask_data_sel(data)                           (0x00001F00&((data)<<8))
#define  IRDA_HW_decode_sel_hw_decode_data_en(data)                              (0x00000080&((data)<<7))
#define  IRDA_HW_decode_sel_hw_decode_data_sel(data)                             (0x0000001F&(data))
#define  IRDA_HW_decode_sel_get_decode_mask_data_en(data)                        ((0x00008000&(data))>>15)
#define  IRDA_HW_decode_sel_get_decode_mask_data_sel(data)                       ((0x00001F00&(data))>>8)
#define  IRDA_HW_decode_sel_get_hw_decode_data_en(data)                          ((0x00000080&(data))>>7)
#define  IRDA_HW_decode_sel_get_hw_decode_data_sel(data)                         (0x0000001F&(data))

#define  IRDA_HW_decode_read                                                     0x18061454
#define  IRDA_HW_decode_read_reg_addr                                            "0xB8061454"
#define  IRDA_HW_decode_read_reg                                                 0xB8061454
#define  IRDA_HW_decode_read_inst_addr                                           "0x000F"
#define  set_IRDA_HW_decode_read_reg(data)                                       (*((volatile unsigned int*)IRDA_HW_decode_read_reg)=data)
#define  get_IRDA_HW_decode_read_reg                                             (*((volatile unsigned int*)IRDA_HW_decode_read_reg))
#define  IRDA_HW_decode_read_hw_decode_data_read_shift                           (0)
#define  IRDA_HW_decode_read_hw_decode_data_read_mask                            (0xFFFFFFFF)
#define  IRDA_HW_decode_read_hw_decode_data_read(data)                           (0xFFFFFFFF&(data))
#define  IRDA_HW_decode_read_get_hw_decode_data_read(data)                       (0xFFFFFFFF&(data))

#define  IRDA_Decode_Mask_data_read                                              0x18061458
#define  IRDA_Decode_Mask_data_read_reg_addr                                     "0xB8061458"
#define  IRDA_Decode_Mask_data_read_reg                                          0xB8061458
#define  IRDA_Decode_Mask_data_read_inst_addr                                    "0x0010"
#define  set_IRDA_Decode_Mask_data_read_reg(data)                                (*((volatile unsigned int*)IRDA_Decode_Mask_data_read_reg)=data)
#define  get_IRDA_Decode_Mask_data_read_reg                                      (*((volatile unsigned int*)IRDA_Decode_Mask_data_read_reg))
#define  IRDA_Decode_Mask_data_read_decode_mask_data_read_shift                  (0)
#define  IRDA_Decode_Mask_data_read_decode_mask_data_read_mask                   (0xFFFFFFFF)
#define  IRDA_Decode_Mask_data_read_decode_mask_data_read(data)                  (0xFFFFFFFF&(data))
#define  IRDA_Decode_Mask_data_read_get_decode_mask_data_read(data)              (0xFFFFFFFF&(data))

#define  IRDA_HW_decode_data_                                                    0x1806145C
#define  IRDA_HW_decode_data__reg_addr                                           "0xB806145C"
#define  IRDA_HW_decode_data__reg                                                0xB806145C
#define  IRDA_HW_decode_data__inst_addr                                          "0x0011"
#define  set_IRDA_HW_decode_data__reg(data)                                      (*((volatile unsigned int*)IRDA_HW_decode_data__reg)=data)
#define  get_IRDA_HW_decode_data__reg                                            (*((volatile unsigned int*)IRDA_HW_decode_data__reg))
#define  IRDA_HW_decode_data__hw_decode_data_shift                               (0)
#define  IRDA_HW_decode_data__hw_decode_data_mask                                (0xFFFFFFFF)
#define  IRDA_HW_decode_data__hw_decode_data(data)                               (0xFFFFFFFF&(data))
#define  IRDA_HW_decode_data__get_hw_decode_data(data)                           (0xFFFFFFFF&(data))

#define  IRDA_Decode_Mask_data                                                   0x18061460
#define  IRDA_Decode_Mask_data_reg_addr                                          "0xB8061460"
#define  IRDA_Decode_Mask_data_reg                                               0xB8061460
#define  IRDA_Decode_Mask_data_inst_addr                                         "0x0012"
#define  set_IRDA_Decode_Mask_data_reg(data)                                     (*((volatile unsigned int*)IRDA_Decode_Mask_data_reg)=data)
#define  get_IRDA_Decode_Mask_data_reg                                           (*((volatile unsigned int*)IRDA_Decode_Mask_data_reg))
#define  IRDA_Decode_Mask_data_decode_mask_data_shift                            (0)
#define  IRDA_Decode_Mask_data_decode_mask_data_mask                             (0xFFFFFFFF)
#define  IRDA_Decode_Mask_data_decode_mask_data(data)                            (0xFFFFFFFF&(data))
#define  IRDA_Decode_Mask_data_get_decode_mask_data(data)                        (0xFFFFFFFF&(data))

#define  IRDA_INT_CTRL                                                           0x18061464
#define  IRDA_INT_CTRL_reg_addr                                                  "0xB8061464"
#define  IRDA_INT_CTRL_reg                                                       0xB8061464
#define  IRDA_INT_CTRL_inst_addr                                                 "0x0013"
#define  set_IRDA_INT_CTRL_reg(data)                                             (*((volatile unsigned int*)IRDA_INT_CTRL_reg)=data)
#define  get_IRDA_INT_CTRL_reg                                                   (*((volatile unsigned int*)IRDA_INT_CTRL_reg))
#define  IRDA_INT_CTRL_compare7_enable_shift                                     (31)
#define  IRDA_INT_CTRL_compare6_enable_shift                                     (30)
#define  IRDA_INT_CTRL_compare5_enable_shift                                     (29)
#define  IRDA_INT_CTRL_compare4_enable_shift                                     (28)
#define  IRDA_INT_CTRL_compare3_enable_shift                                     (27)
#define  IRDA_INT_CTRL_compare2_enable_shift                                     (26)
#define  IRDA_INT_CTRL_compare1_enable_shift                                     (25)
#define  IRDA_INT_CTRL_compare0_enable_shift                                     (24)
#define  IRDA_INT_CTRL_compare7_int_en_shift                                     (15)
#define  IRDA_INT_CTRL_compare6_int_en_shift                                     (14)
#define  IRDA_INT_CTRL_compare5_int_en_shift                                     (13)
#define  IRDA_INT_CTRL_compare4_int_en_shift                                     (12)
#define  IRDA_INT_CTRL_compare3_int_en_shift                                     (11)
#define  IRDA_INT_CTRL_compare2_int_en_shift                                     (10)
#define  IRDA_INT_CTRL_compare1_int_en_shift                                     (9)
#define  IRDA_INT_CTRL_compare0_int_en_shift                                     (8)
#define  IRDA_INT_CTRL_compare7_int_status_shift                                 (7)
#define  IRDA_INT_CTRL_compare6_int_status_shift                                 (6)
#define  IRDA_INT_CTRL_compare5_int_status_shift                                 (5)
#define  IRDA_INT_CTRL_compare4_int_status_shift                                 (4)
#define  IRDA_INT_CTRL_compare3_int_status_shift                                 (3)
#define  IRDA_INT_CTRL_compare2_int_status_shift                                 (2)
#define  IRDA_INT_CTRL_compare1_int_status_shift                                 (1)
#define  IRDA_INT_CTRL_compare0_int_status_shift                                 (0)
#define  IRDA_INT_CTRL_compare7_enable_mask                                      (0x80000000)
#define  IRDA_INT_CTRL_compare6_enable_mask                                      (0x40000000)
#define  IRDA_INT_CTRL_compare5_enable_mask                                      (0x20000000)
#define  IRDA_INT_CTRL_compare4_enable_mask                                      (0x10000000)
#define  IRDA_INT_CTRL_compare3_enable_mask                                      (0x08000000)
#define  IRDA_INT_CTRL_compare2_enable_mask                                      (0x04000000)
#define  IRDA_INT_CTRL_compare1_enable_mask                                      (0x02000000)
#define  IRDA_INT_CTRL_compare0_enable_mask                                      (0x01000000)
#define  IRDA_INT_CTRL_compare7_int_en_mask                                      (0x00008000)
#define  IRDA_INT_CTRL_compare6_int_en_mask                                      (0x00004000)
#define  IRDA_INT_CTRL_compare5_int_en_mask                                      (0x00002000)
#define  IRDA_INT_CTRL_compare4_int_en_mask                                      (0x00001000)
#define  IRDA_INT_CTRL_compare3_int_en_mask                                      (0x00000800)
#define  IRDA_INT_CTRL_compare2_int_en_mask                                      (0x00000400)
#define  IRDA_INT_CTRL_compare1_int_en_mask                                      (0x00000200)
#define  IRDA_INT_CTRL_compare0_int_en_mask                                      (0x00000100)
#define  IRDA_INT_CTRL_compare7_int_status_mask                                  (0x00000080)
#define  IRDA_INT_CTRL_compare6_int_status_mask                                  (0x00000040)
#define  IRDA_INT_CTRL_compare5_int_status_mask                                  (0x00000020)
#define  IRDA_INT_CTRL_compare4_int_status_mask                                  (0x00000010)
#define  IRDA_INT_CTRL_compare3_int_status_mask                                  (0x00000008)
#define  IRDA_INT_CTRL_compare2_int_status_mask                                  (0x00000004)
#define  IRDA_INT_CTRL_compare1_int_status_mask                                  (0x00000002)
#define  IRDA_INT_CTRL_compare0_int_status_mask                                  (0x00000001)
#define  IRDA_INT_CTRL_compare7_enable(data)                                     (0x80000000&((data)<<31))
#define  IRDA_INT_CTRL_compare6_enable(data)                                     (0x40000000&((data)<<30))
#define  IRDA_INT_CTRL_compare5_enable(data)                                     (0x20000000&((data)<<29))
#define  IRDA_INT_CTRL_compare4_enable(data)                                     (0x10000000&((data)<<28))
#define  IRDA_INT_CTRL_compare3_enable(data)                                     (0x08000000&((data)<<27))
#define  IRDA_INT_CTRL_compare2_enable(data)                                     (0x04000000&((data)<<26))
#define  IRDA_INT_CTRL_compare1_enable(data)                                     (0x02000000&((data)<<25))
#define  IRDA_INT_CTRL_compare0_enable(data)                                     (0x01000000&((data)<<24))
#define  IRDA_INT_CTRL_compare7_int_en(data)                                     (0x00008000&((data)<<15))
#define  IRDA_INT_CTRL_compare6_int_en(data)                                     (0x00004000&((data)<<14))
#define  IRDA_INT_CTRL_compare5_int_en(data)                                     (0x00002000&((data)<<13))
#define  IRDA_INT_CTRL_compare4_int_en(data)                                     (0x00001000&((data)<<12))
#define  IRDA_INT_CTRL_compare3_int_en(data)                                     (0x00000800&((data)<<11))
#define  IRDA_INT_CTRL_compare2_int_en(data)                                     (0x00000400&((data)<<10))
#define  IRDA_INT_CTRL_compare1_int_en(data)                                     (0x00000200&((data)<<9))
#define  IRDA_INT_CTRL_compare0_int_en(data)                                     (0x00000100&((data)<<8))
#define  IRDA_INT_CTRL_compare7_int_status(data)                                 (0x00000080&((data)<<7))
#define  IRDA_INT_CTRL_compare6_int_status(data)                                 (0x00000040&((data)<<6))
#define  IRDA_INT_CTRL_compare5_int_status(data)                                 (0x00000020&((data)<<5))
#define  IRDA_INT_CTRL_compare4_int_status(data)                                 (0x00000010&((data)<<4))
#define  IRDA_INT_CTRL_compare3_int_status(data)                                 (0x00000008&((data)<<3))
#define  IRDA_INT_CTRL_compare2_int_status(data)                                 (0x00000004&((data)<<2))
#define  IRDA_INT_CTRL_compare1_int_status(data)                                 (0x00000002&((data)<<1))
#define  IRDA_INT_CTRL_compare0_int_status(data)                                 (0x00000001&(data))
#define  IRDA_INT_CTRL_get_compare7_enable(data)                                 ((0x80000000&(data))>>31)
#define  IRDA_INT_CTRL_get_compare6_enable(data)                                 ((0x40000000&(data))>>30)
#define  IRDA_INT_CTRL_get_compare5_enable(data)                                 ((0x20000000&(data))>>29)
#define  IRDA_INT_CTRL_get_compare4_enable(data)                                 ((0x10000000&(data))>>28)
#define  IRDA_INT_CTRL_get_compare3_enable(data)                                 ((0x08000000&(data))>>27)
#define  IRDA_INT_CTRL_get_compare2_enable(data)                                 ((0x04000000&(data))>>26)
#define  IRDA_INT_CTRL_get_compare1_enable(data)                                 ((0x02000000&(data))>>25)
#define  IRDA_INT_CTRL_get_compare0_enable(data)                                 ((0x01000000&(data))>>24)
#define  IRDA_INT_CTRL_get_compare7_int_en(data)                                 ((0x00008000&(data))>>15)
#define  IRDA_INT_CTRL_get_compare6_int_en(data)                                 ((0x00004000&(data))>>14)
#define  IRDA_INT_CTRL_get_compare5_int_en(data)                                 ((0x00002000&(data))>>13)
#define  IRDA_INT_CTRL_get_compare4_int_en(data)                                 ((0x00001000&(data))>>12)
#define  IRDA_INT_CTRL_get_compare3_int_en(data)                                 ((0x00000800&(data))>>11)
#define  IRDA_INT_CTRL_get_compare2_int_en(data)                                 ((0x00000400&(data))>>10)
#define  IRDA_INT_CTRL_get_compare1_int_en(data)                                 ((0x00000200&(data))>>9)
#define  IRDA_INT_CTRL_get_compare0_int_en(data)                                 ((0x00000100&(data))>>8)
#define  IRDA_INT_CTRL_get_compare7_int_status(data)                             ((0x00000080&(data))>>7)
#define  IRDA_INT_CTRL_get_compare6_int_status(data)                             ((0x00000040&(data))>>6)
#define  IRDA_INT_CTRL_get_compare5_int_status(data)                             ((0x00000020&(data))>>5)
#define  IRDA_INT_CTRL_get_compare4_int_status(data)                             ((0x00000010&(data))>>4)
#define  IRDA_INT_CTRL_get_compare3_int_status(data)                             ((0x00000008&(data))>>3)
#define  IRDA_INT_CTRL_get_compare2_int_status(data)                             ((0x00000004&(data))>>2)
#define  IRDA_INT_CTRL_get_compare1_int_status(data)                             ((0x00000002&(data))>>1)
#define  IRDA_INT_CTRL_get_compare0_int_status(data)                             (0x00000001&(data))

#define  IRDA_INT_CTRL1                                                          0x18061468
#define  IRDA_INT_CTRL1_reg_addr                                                 "0xB8061468"
#define  IRDA_INT_CTRL1_reg                                                      0xB8061468
#define  IRDA_INT_CTRL1_inst_addr                                                "0x0014"
#define  set_IRDA_INT_CTRL1_reg(data)                                            (*((volatile unsigned int*)IRDA_INT_CTRL1_reg)=data)
#define  get_IRDA_INT_CTRL1_reg                                                  (*((volatile unsigned int*)IRDA_INT_CTRL1_reg))
#define  IRDA_INT_CTRL1_compare15_enable_shift                                   (31)
#define  IRDA_INT_CTRL1_compare14_enable_shift                                   (30)
#define  IRDA_INT_CTRL1_compare13_enable_shift                                   (29)
#define  IRDA_INT_CTRL1_compare12_enable_shift                                   (28)
#define  IRDA_INT_CTRL1_compare11_enable_shift                                   (27)
#define  IRDA_INT_CTRL1_compare10_enable_shift                                   (26)
#define  IRDA_INT_CTRL1_compare9_enable_shift                                    (25)
#define  IRDA_INT_CTRL1_compare8_enable_shift                                    (24)
#define  IRDA_INT_CTRL1_compare15_int_en_shift                                   (15)
#define  IRDA_INT_CTRL1_compare14_int_en_shift                                   (14)
#define  IRDA_INT_CTRL1_compare13_int_en_shift                                   (13)
#define  IRDA_INT_CTRL1_compare12_int_en_shift                                   (12)
#define  IRDA_INT_CTRL1_compare11_int_en_shift                                   (11)
#define  IRDA_INT_CTRL1_compare10_int_en_shift                                   (10)
#define  IRDA_INT_CTRL1_compare9_int_en_shift                                    (9)
#define  IRDA_INT_CTRL1_compare8_int_en_shift                                    (8)
#define  IRDA_INT_CTRL1_compare15_int_status_shift                               (7)
#define  IRDA_INT_CTRL1_compare14_int_status_shift                               (6)
#define  IRDA_INT_CTRL1_compare13_int_status_shift                               (5)
#define  IRDA_INT_CTRL1_compare12_int_status_shift                               (4)
#define  IRDA_INT_CTRL1_compare11_int_status_shift                               (3)
#define  IRDA_INT_CTRL1_compare10_int_status_shift                               (2)
#define  IRDA_INT_CTRL1_compare9_int_status_shift                                (1)
#define  IRDA_INT_CTRL1_compare8_int_status_shift                                (0)
#define  IRDA_INT_CTRL1_compare15_enable_mask                                    (0x80000000)
#define  IRDA_INT_CTRL1_compare14_enable_mask                                    (0x40000000)
#define  IRDA_INT_CTRL1_compare13_enable_mask                                    (0x20000000)
#define  IRDA_INT_CTRL1_compare12_enable_mask                                    (0x10000000)
#define  IRDA_INT_CTRL1_compare11_enable_mask                                    (0x08000000)
#define  IRDA_INT_CTRL1_compare10_enable_mask                                    (0x04000000)
#define  IRDA_INT_CTRL1_compare9_enable_mask                                     (0x02000000)
#define  IRDA_INT_CTRL1_compare8_enable_mask                                     (0x01000000)
#define  IRDA_INT_CTRL1_compare15_int_en_mask                                    (0x00008000)
#define  IRDA_INT_CTRL1_compare14_int_en_mask                                    (0x00004000)
#define  IRDA_INT_CTRL1_compare13_int_en_mask                                    (0x00002000)
#define  IRDA_INT_CTRL1_compare12_int_en_mask                                    (0x00001000)
#define  IRDA_INT_CTRL1_compare11_int_en_mask                                    (0x00000800)
#define  IRDA_INT_CTRL1_compare10_int_en_mask                                    (0x00000400)
#define  IRDA_INT_CTRL1_compare9_int_en_mask                                     (0x00000200)
#define  IRDA_INT_CTRL1_compare8_int_en_mask                                     (0x00000100)
#define  IRDA_INT_CTRL1_compare15_int_status_mask                                (0x00000080)
#define  IRDA_INT_CTRL1_compare14_int_status_mask                                (0x00000040)
#define  IRDA_INT_CTRL1_compare13_int_status_mask                                (0x00000020)
#define  IRDA_INT_CTRL1_compare12_int_status_mask                                (0x00000010)
#define  IRDA_INT_CTRL1_compare11_int_status_mask                                (0x00000008)
#define  IRDA_INT_CTRL1_compare10_int_status_mask                                (0x00000004)
#define  IRDA_INT_CTRL1_compare9_int_status_mask                                 (0x00000002)
#define  IRDA_INT_CTRL1_compare8_int_status_mask                                 (0x00000001)
#define  IRDA_INT_CTRL1_compare15_enable(data)                                   (0x80000000&((data)<<31))
#define  IRDA_INT_CTRL1_compare14_enable(data)                                   (0x40000000&((data)<<30))
#define  IRDA_INT_CTRL1_compare13_enable(data)                                   (0x20000000&((data)<<29))
#define  IRDA_INT_CTRL1_compare12_enable(data)                                   (0x10000000&((data)<<28))
#define  IRDA_INT_CTRL1_compare11_enable(data)                                   (0x08000000&((data)<<27))
#define  IRDA_INT_CTRL1_compare10_enable(data)                                   (0x04000000&((data)<<26))
#define  IRDA_INT_CTRL1_compare9_enable(data)                                    (0x02000000&((data)<<25))
#define  IRDA_INT_CTRL1_compare8_enable(data)                                    (0x01000000&((data)<<24))
#define  IRDA_INT_CTRL1_compare15_int_en(data)                                   (0x00008000&((data)<<15))
#define  IRDA_INT_CTRL1_compare14_int_en(data)                                   (0x00004000&((data)<<14))
#define  IRDA_INT_CTRL1_compare13_int_en(data)                                   (0x00002000&((data)<<13))
#define  IRDA_INT_CTRL1_compare12_int_en(data)                                   (0x00001000&((data)<<12))
#define  IRDA_INT_CTRL1_compare11_int_en(data)                                   (0x00000800&((data)<<11))
#define  IRDA_INT_CTRL1_compare10_int_en(data)                                   (0x00000400&((data)<<10))
#define  IRDA_INT_CTRL1_compare9_int_en(data)                                    (0x00000200&((data)<<9))
#define  IRDA_INT_CTRL1_compare8_int_en(data)                                    (0x00000100&((data)<<8))
#define  IRDA_INT_CTRL1_compare15_int_status(data)                               (0x00000080&((data)<<7))
#define  IRDA_INT_CTRL1_compare14_int_status(data)                               (0x00000040&((data)<<6))
#define  IRDA_INT_CTRL1_compare13_int_status(data)                               (0x00000020&((data)<<5))
#define  IRDA_INT_CTRL1_compare12_int_status(data)                               (0x00000010&((data)<<4))
#define  IRDA_INT_CTRL1_compare11_int_status(data)                               (0x00000008&((data)<<3))
#define  IRDA_INT_CTRL1_compare10_int_status(data)                               (0x00000004&((data)<<2))
#define  IRDA_INT_CTRL1_compare9_int_status(data)                                (0x00000002&((data)<<1))
#define  IRDA_INT_CTRL1_compare8_int_status(data)                                (0x00000001&(data))
#define  IRDA_INT_CTRL1_get_compare15_enable(data)                               ((0x80000000&(data))>>31)
#define  IRDA_INT_CTRL1_get_compare14_enable(data)                               ((0x40000000&(data))>>30)
#define  IRDA_INT_CTRL1_get_compare13_enable(data)                               ((0x20000000&(data))>>29)
#define  IRDA_INT_CTRL1_get_compare12_enable(data)                               ((0x10000000&(data))>>28)
#define  IRDA_INT_CTRL1_get_compare11_enable(data)                               ((0x08000000&(data))>>27)
#define  IRDA_INT_CTRL1_get_compare10_enable(data)                               ((0x04000000&(data))>>26)
#define  IRDA_INT_CTRL1_get_compare9_enable(data)                                ((0x02000000&(data))>>25)
#define  IRDA_INT_CTRL1_get_compare8_enable(data)                                ((0x01000000&(data))>>24)
#define  IRDA_INT_CTRL1_get_compare15_int_en(data)                               ((0x00008000&(data))>>15)
#define  IRDA_INT_CTRL1_get_compare14_int_en(data)                               ((0x00004000&(data))>>14)
#define  IRDA_INT_CTRL1_get_compare13_int_en(data)                               ((0x00002000&(data))>>13)
#define  IRDA_INT_CTRL1_get_compare12_int_en(data)                               ((0x00001000&(data))>>12)
#define  IRDA_INT_CTRL1_get_compare11_int_en(data)                               ((0x00000800&(data))>>11)
#define  IRDA_INT_CTRL1_get_compare10_int_en(data)                               ((0x00000400&(data))>>10)
#define  IRDA_INT_CTRL1_get_compare9_int_en(data)                                ((0x00000200&(data))>>9)
#define  IRDA_INT_CTRL1_get_compare8_int_en(data)                                ((0x00000100&(data))>>8)
#define  IRDA_INT_CTRL1_get_compare15_int_status(data)                           ((0x00000080&(data))>>7)
#define  IRDA_INT_CTRL1_get_compare14_int_status(data)                           ((0x00000040&(data))>>6)
#define  IRDA_INT_CTRL1_get_compare13_int_status(data)                           ((0x00000020&(data))>>5)
#define  IRDA_INT_CTRL1_get_compare12_int_status(data)                           ((0x00000010&(data))>>4)
#define  IRDA_INT_CTRL1_get_compare11_int_status(data)                           ((0x00000008&(data))>>3)
#define  IRDA_INT_CTRL1_get_compare10_int_status(data)                           ((0x00000004&(data))>>2)
#define  IRDA_INT_CTRL1_get_compare9_int_status(data)                            ((0x00000002&(data))>>1)
#define  IRDA_INT_CTRL1_get_compare8_int_status(data)                            (0x00000001&(data))

#define  IRDA_Compare_TEST_MODE                                                  0x1806146C
#define  IRDA_Compare_TEST_MODE_reg_addr                                         "0xB806146C"
#define  IRDA_Compare_TEST_MODE_reg                                              0xB806146C
#define  IRDA_Compare_TEST_MODE_inst_addr                                        "0x0015"
#define  set_IRDA_Compare_TEST_MODE_reg(data)                                    (*((volatile unsigned int*)IRDA_Compare_TEST_MODE_reg)=data)
#define  get_IRDA_Compare_TEST_MODE_reg                                          (*((volatile unsigned int*)IRDA_Compare_TEST_MODE_reg))
#define  IRDA_Compare_TEST_MODE_test_mode_en_shift                               (0)
#define  IRDA_Compare_TEST_MODE_test_mode_en_mask                                (0x00000001)
#define  IRDA_Compare_TEST_MODE_test_mode_en(data)                               (0x00000001&(data))
#define  IRDA_Compare_TEST_MODE_get_test_mode_en(data)                           (0x00000001&(data))

#define  IRDA_Compare_test_mode_data7_L                                          0x18061470
#define  IRDA_Compare_test_mode_data7_L_reg_addr                                 "0xB8061470"
#define  IRDA_Compare_test_mode_data7_L_reg                                      0xB8061470
#define  IRDA_Compare_test_mode_data7_L_inst_addr                                "0x0016"
#define  set_IRDA_Compare_test_mode_data7_L_reg(data)                            (*((volatile unsigned int*)IRDA_Compare_test_mode_data7_L_reg)=data)
#define  get_IRDA_Compare_test_mode_data7_L_reg                                  (*((volatile unsigned int*)IRDA_Compare_test_mode_data7_L_reg))
#define  IRDA_Compare_test_mode_data7_L_test_mode_data_0_shift                   (0)
#define  IRDA_Compare_test_mode_data7_L_test_mode_data_0_mask                    (0xFFFFFFFF)
#define  IRDA_Compare_test_mode_data7_L_test_mode_data_0(data)                   (0xFFFFFFFF&(data))
#define  IRDA_Compare_test_mode_data7_L_get_test_mode_data_0(data)               (0xFFFFFFFF&(data))

#define  IRDA_Compare_test_mode_data7_H                                          0x18061474
#define  IRDA_Compare_test_mode_data7_H_reg_addr                                 "0xB8061474"
#define  IRDA_Compare_test_mode_data7_H_reg                                      0xB8061474
#define  IRDA_Compare_test_mode_data7_H_inst_addr                                "0x0017"
#define  set_IRDA_Compare_test_mode_data7_H_reg(data)                            (*((volatile unsigned int*)IRDA_Compare_test_mode_data7_H_reg)=data)
#define  get_IRDA_Compare_test_mode_data7_H_reg                                  (*((volatile unsigned int*)IRDA_Compare_test_mode_data7_H_reg))
#define  IRDA_Compare_test_mode_data7_H_test_mode_data_1_shift                   (0)
#define  IRDA_Compare_test_mode_data7_H_test_mode_data_1_mask                    (0xFFFFFFFF)
#define  IRDA_Compare_test_mode_data7_H_test_mode_data_1(data)                   (0xFFFFFFFF&(data))
#define  IRDA_Compare_test_mode_data7_H_get_test_mode_data_1(data)               (0xFFFFFFFF&(data))

#define  IRDA_compare_test_mode_sel                                              0x18061478
#define  IRDA_compare_test_mode_sel_reg_addr                                     "0xB8061478"
#define  IRDA_compare_test_mode_sel_reg                                          0xB8061478
#define  IRDA_compare_test_mode_sel_inst_addr                                    "0x0018"
#define  set_IRDA_compare_test_mode_sel_reg(data)                                (*((volatile unsigned int*)IRDA_compare_test_mode_sel_reg)=data)
#define  get_IRDA_compare_test_mode_sel_reg                                      (*((volatile unsigned int*)IRDA_compare_test_mode_sel_reg))
#define  IRDA_compare_test_mode_sel_test_mode_sel_shift                          (0)
#define  IRDA_compare_test_mode_sel_test_mode_sel_mask                           (0xFFFFFFFF)
#define  IRDA_compare_test_mode_sel_test_mode_sel(data)                          (0xFFFFFFFF&(data))
#define  IRDA_compare_test_mode_sel_get_test_mode_sel(data)                      (0xFFFFFFFF&(data))

#define  IRDA_IR_PSR_RC5_RC6                                                     0x180614A0
#define  IRDA_IR_PSR_RC5_RC6_reg_addr                                            "0xB80614A0"
#define  IRDA_IR_PSR_RC5_RC6_reg                                                 0xB80614A0
#define  IRDA_IR_PSR_RC5_RC6_inst_addr                                           "0x0019"
#define  set_IRDA_IR_PSR_RC5_RC6_reg(data)                                       (*((volatile unsigned int*)IRDA_IR_PSR_RC5_RC6_reg)=data)
#define  get_IRDA_IR_PSR_RC5_RC6_reg                                             (*((volatile unsigned int*)IRDA_IR_PSR_RC5_RC6_reg))
#define  IRDA_IR_PSR_RC5_RC6_lat_lead_low_rc56_shift                             (24)
#define  IRDA_IR_PSR_RC5_RC6_lat_logic_low_rc56_shift                            (16)
#define  IRDA_IR_PSR_RC5_RC6_lat_data0_high_rc56_shift                           (8)
#define  IRDA_IR_PSR_RC5_RC6_lat_data1_high_rc56_shift                           (0)
#define  IRDA_IR_PSR_RC5_RC6_lat_lead_low_rc56_mask                              (0xFF000000)
#define  IRDA_IR_PSR_RC5_RC6_lat_logic_low_rc56_mask                             (0x00FF0000)
#define  IRDA_IR_PSR_RC5_RC6_lat_data0_high_rc56_mask                            (0x0000FF00)
#define  IRDA_IR_PSR_RC5_RC6_lat_data1_high_rc56_mask                            (0x000000FF)
#define  IRDA_IR_PSR_RC5_RC6_lat_lead_low_rc56(data)                             (0xFF000000&((data)<<24))
#define  IRDA_IR_PSR_RC5_RC6_lat_logic_low_rc56(data)                            (0x00FF0000&((data)<<16))
#define  IRDA_IR_PSR_RC5_RC6_lat_data0_high_rc56(data)                           (0x0000FF00&((data)<<8))
#define  IRDA_IR_PSR_RC5_RC6_lat_data1_high_rc56(data)                           (0x000000FF&(data))
#define  IRDA_IR_PSR_RC5_RC6_get_lat_lead_low_rc56(data)                         ((0xFF000000&(data))>>24)
#define  IRDA_IR_PSR_RC5_RC6_get_lat_logic_low_rc56(data)                        ((0x00FF0000&(data))>>16)
#define  IRDA_IR_PSR_RC5_RC6_get_lat_data0_high_rc56(data)                       ((0x0000FF00&(data))>>8)
#define  IRDA_IR_PSR_RC5_RC6_get_lat_data1_high_rc56(data)                       (0x000000FF&(data))

#define  IRDA_IR_PER_RC5_RC6                                                     0x180614A4
#define  IRDA_IR_PER_RC5_RC6_reg_addr                                            "0xB80614A4"
#define  IRDA_IR_PER_RC5_RC6_reg                                                 0xB80614A4
#define  IRDA_IR_PER_RC5_RC6_inst_addr                                           "0x001A"
#define  set_IRDA_IR_PER_RC5_RC6_reg(data)                                       (*((volatile unsigned int*)IRDA_IR_PER_RC5_RC6_reg)=data)
#define  get_IRDA_IR_PER_RC5_RC6_reg                                             (*((volatile unsigned int*)IRDA_IR_PER_RC5_RC6_reg))
#define  IRDA_IR_PER_RC5_RC6_rp_burst_rc56_shift                                 (22)
#define  IRDA_IR_PER_RC5_RC6_rp_silence_rc56_shift                               (14)
#define  IRDA_IR_PER_RC5_RC6_lat_denos_num_rc56_shift                            (8)
#define  IRDA_IR_PER_RC5_RC6_lat_lead_high_rc56_shift                            (0)
#define  IRDA_IR_PER_RC5_RC6_rp_burst_rc56_mask                                  (0x3FC00000)
#define  IRDA_IR_PER_RC5_RC6_rp_silence_rc56_mask                                (0x003FC000)
#define  IRDA_IR_PER_RC5_RC6_lat_denos_num_rc56_mask                             (0x00003F00)
#define  IRDA_IR_PER_RC5_RC6_lat_lead_high_rc56_mask                             (0x000000FF)
#define  IRDA_IR_PER_RC5_RC6_rp_burst_rc56(data)                                 (0x3FC00000&((data)<<22))
#define  IRDA_IR_PER_RC5_RC6_rp_silence_rc56(data)                               (0x003FC000&((data)<<14))
#define  IRDA_IR_PER_RC5_RC6_lat_denos_num_rc56(data)                            (0x00003F00&((data)<<8))
#define  IRDA_IR_PER_RC5_RC6_lat_lead_high_rc56(data)                            (0x000000FF&(data))
#define  IRDA_IR_PER_RC5_RC6_get_rp_burst_rc56(data)                             ((0x3FC00000&(data))>>22)
#define  IRDA_IR_PER_RC5_RC6_get_rp_silence_rc56(data)                           ((0x003FC000&(data))>>14)
#define  IRDA_IR_PER_RC5_RC6_get_lat_denos_num_rc56(data)                        ((0x00003F00&(data))>>8)
#define  IRDA_IR_PER_RC5_RC6_get_lat_lead_high_rc56(data)                        (0x000000FF&(data))

#define  IRDA_IR_PSR_UP_RC5_RC6                                                  0x180614A8
#define  IRDA_IR_PSR_UP_RC5_RC6_reg_addr                                         "0xB80614A8"
#define  IRDA_IR_PSR_UP_RC5_RC6_reg                                              0xB80614A8
#define  IRDA_IR_PSR_UP_RC5_RC6_inst_addr                                        "0x001B"
#define  set_IRDA_IR_PSR_UP_RC5_RC6_reg(data)                                    (*((volatile unsigned int*)IRDA_IR_PSR_UP_RC5_RC6_reg)=data)
#define  get_IRDA_IR_PSR_UP_RC5_RC6_reg                                          (*((volatile unsigned int*)IRDA_IR_PSR_UP_RC5_RC6_reg))
#define  IRDA_IR_PSR_UP_RC5_RC6_irrbl_up_rc56_shift                              (24)
#define  IRDA_IR_PSR_UP_RC5_RC6_irrml_up_rc56_shift                              (16)
#define  IRDA_IR_PSR_UP_RC5_RC6_irrdzl_up_rc56_shift                             (8)
#define  IRDA_IR_PSR_UP_RC5_RC6_irrdol_up_rc56_shift                             (0)
#define  IRDA_IR_PSR_UP_RC5_RC6_irrbl_up_rc56_mask                               (0xFF000000)
#define  IRDA_IR_PSR_UP_RC5_RC6_irrml_up_rc56_mask                               (0x00FF0000)
#define  IRDA_IR_PSR_UP_RC5_RC6_irrdzl_up_rc56_mask                              (0x0000FF00)
#define  IRDA_IR_PSR_UP_RC5_RC6_irrdol_up_rc56_mask                              (0x000000FF)
#define  IRDA_IR_PSR_UP_RC5_RC6_irrbl_up_rc56(data)                              (0xFF000000&((data)<<24))
#define  IRDA_IR_PSR_UP_RC5_RC6_irrml_up_rc56(data)                              (0x00FF0000&((data)<<16))
#define  IRDA_IR_PSR_UP_RC5_RC6_irrdzl_up_rc56(data)                             (0x0000FF00&((data)<<8))
#define  IRDA_IR_PSR_UP_RC5_RC6_irrdol_up_rc56(data)                             (0x000000FF&(data))
#define  IRDA_IR_PSR_UP_RC5_RC6_get_irrbl_up_rc56(data)                          ((0xFF000000&(data))>>24)
#define  IRDA_IR_PSR_UP_RC5_RC6_get_irrml_up_rc56(data)                          ((0x00FF0000&(data))>>16)
#define  IRDA_IR_PSR_UP_RC5_RC6_get_irrdzl_up_rc56(data)                         ((0x0000FF00&(data))>>8)
#define  IRDA_IR_PSR_UP_RC5_RC6_get_irrdol_up_rc56(data)                         (0x000000FF&(data))

#define  IRDA_IR_PER_UP_RC5_RC6                                                  0x180614AC
#define  IRDA_IR_PER_UP_RC5_RC6_reg_addr                                         "0xB80614AC"
#define  IRDA_IR_PER_UP_RC5_RC6_reg                                              0xB80614AC
#define  IRDA_IR_PER_UP_RC5_RC6_inst_addr                                        "0x001C"
#define  set_IRDA_IR_PER_UP_RC5_RC6_reg(data)                                    (*((volatile unsigned int*)IRDA_IR_PER_UP_RC5_RC6_reg)=data)
#define  get_IRDA_IR_PER_UP_RC5_RC6_reg                                          (*((volatile unsigned int*)IRDA_IR_PER_UP_RC5_RC6_reg))
#define  IRDA_IR_PER_UP_RC5_RC6_rp_burst_up_rc56_shift                           (24)
#define  IRDA_IR_PER_UP_RC5_RC6_rp_silence_up_rc56_shift                         (16)
#define  IRDA_IR_PER_UP_RC5_RC6_irrsl_up_rc56_shift                              (0)
#define  IRDA_IR_PER_UP_RC5_RC6_rp_burst_up_rc56_mask                            (0xFF000000)
#define  IRDA_IR_PER_UP_RC5_RC6_rp_silence_up_rc56_mask                          (0x00FF0000)
#define  IRDA_IR_PER_UP_RC5_RC6_irrsl_up_rc56_mask                               (0x000000FF)
#define  IRDA_IR_PER_UP_RC5_RC6_rp_burst_up_rc56(data)                           (0xFF000000&((data)<<24))
#define  IRDA_IR_PER_UP_RC5_RC6_rp_silence_up_rc56(data)                         (0x00FF0000&((data)<<16))
#define  IRDA_IR_PER_UP_RC5_RC6_irrsl_up_rc56(data)                              (0x000000FF&(data))
#define  IRDA_IR_PER_UP_RC5_RC6_get_rp_burst_up_rc56(data)                       ((0xFF000000&(data))>>24)
#define  IRDA_IR_PER_UP_RC5_RC6_get_rp_silence_up_rc56(data)                     ((0x00FF0000&(data))>>16)
#define  IRDA_IR_PER_UP_RC5_RC6_get_irrsl_up_rc56(data)                          (0x000000FF&(data))

#define  IRDA_IR_CR_RC5_RC6                                                      0x180614B0
#define  IRDA_IR_CR_RC5_RC6_reg_addr                                             "0xB80614B0"
#define  IRDA_IR_CR_RC5_RC6_reg                                                  0xB80614B0
#define  IRDA_IR_CR_RC5_RC6_inst_addr                                            "0x001D"
#define  set_IRDA_IR_CR_RC5_RC6_reg(data)                                        (*((volatile unsigned int*)IRDA_IR_CR_RC5_RC6_reg)=data)
#define  get_IRDA_IR_CR_RC5_RC6_reg                                              (*((volatile unsigned int*)IRDA_IR_CR_RC5_RC6_reg))
#define  IRDA_IR_CR_RC5_RC6_second_data_num_rc56_shift                           (17)
#define  IRDA_IR_CR_RC5_RC6_normal_data_num_en_rc56_shift                        (16)
#define  IRDA_IR_CR_RC5_RC6_trailer_code_rc56_shift                              (15)
#define  IRDA_IR_CR_RC5_RC6_rpt_code_rc56_shift                                  (14)
#define  IRDA_IR_CR_RC5_RC6_ph_mod_inv_rc56_shift                                (13)
#define  IRDA_IR_CR_RC5_RC6_len_mod_inv_rc56_shift                               (12)
#define  IRDA_IR_CR_RC5_RC6_lat_ph_len_rc56_shift                                (11)
#define  IRDA_IR_CR_RC5_RC6_start_bit_rc56_shift                                 (10)
#define  IRDA_IR_CR_RC5_RC6_lead_code_rc56_shift                                 (9)
#define  IRDA_IR_CR_RC5_RC6_lat_rx_endian_rc56_shift                             (8)
#define  IRDA_IR_CR_RC5_RC6_lat_data_ph_rc56_shift                               (7)
#define  IRDA_IR_CR_RC5_RC6_lat_data_num_rc56_shift                              (1)
#define  IRDA_IR_CR_RC5_RC6_main1_en_shift                                       (0)
#define  IRDA_IR_CR_RC5_RC6_second_data_num_rc56_mask                            (0x007E0000)
#define  IRDA_IR_CR_RC5_RC6_normal_data_num_en_rc56_mask                         (0x00010000)
#define  IRDA_IR_CR_RC5_RC6_trailer_code_rc56_mask                               (0x00008000)
#define  IRDA_IR_CR_RC5_RC6_rpt_code_rc56_mask                                   (0x00004000)
#define  IRDA_IR_CR_RC5_RC6_ph_mod_inv_rc56_mask                                 (0x00002000)
#define  IRDA_IR_CR_RC5_RC6_len_mod_inv_rc56_mask                                (0x00001000)
#define  IRDA_IR_CR_RC5_RC6_lat_ph_len_rc56_mask                                 (0x00000800)
#define  IRDA_IR_CR_RC5_RC6_start_bit_rc56_mask                                  (0x00000400)
#define  IRDA_IR_CR_RC5_RC6_lead_code_rc56_mask                                  (0x00000200)
#define  IRDA_IR_CR_RC5_RC6_lat_rx_endian_rc56_mask                              (0x00000100)
#define  IRDA_IR_CR_RC5_RC6_lat_data_ph_rc56_mask                                (0x00000080)
#define  IRDA_IR_CR_RC5_RC6_lat_data_num_rc56_mask                               (0x0000007E)
#define  IRDA_IR_CR_RC5_RC6_main1_en_mask                                        (0x00000001)
#define  IRDA_IR_CR_RC5_RC6_second_data_num_rc56(data)                           (0x007E0000&((data)<<17))
#define  IRDA_IR_CR_RC5_RC6_normal_data_num_en_rc56(data)                        (0x00010000&((data)<<16))
#define  IRDA_IR_CR_RC5_RC6_trailer_code_rc56(data)                              (0x00008000&((data)<<15))
#define  IRDA_IR_CR_RC5_RC6_rpt_code_rc56(data)                                  (0x00004000&((data)<<14))
#define  IRDA_IR_CR_RC5_RC6_ph_mod_inv_rc56(data)                                (0x00002000&((data)<<13))
#define  IRDA_IR_CR_RC5_RC6_len_mod_inv_rc56(data)                               (0x00001000&((data)<<12))
#define  IRDA_IR_CR_RC5_RC6_lat_ph_len_rc56(data)                                (0x00000800&((data)<<11))
#define  IRDA_IR_CR_RC5_RC6_start_bit_rc56(data)                                 (0x00000400&((data)<<10))
#define  IRDA_IR_CR_RC5_RC6_lead_code_rc56(data)                                 (0x00000200&((data)<<9))
#define  IRDA_IR_CR_RC5_RC6_lat_rx_endian_rc56(data)                             (0x00000100&((data)<<8))
#define  IRDA_IR_CR_RC5_RC6_lat_data_ph_rc56(data)                               (0x00000080&((data)<<7))
#define  IRDA_IR_CR_RC5_RC6_lat_data_num_rc56(data)                              (0x0000007E&((data)<<1))
#define  IRDA_IR_CR_RC5_RC6_main1_en(data)                                       (0x00000001&(data))
#define  IRDA_IR_CR_RC5_RC6_get_second_data_num_rc56(data)                       ((0x007E0000&(data))>>17)
#define  IRDA_IR_CR_RC5_RC6_get_normal_data_num_en_rc56(data)                    ((0x00010000&(data))>>16)
#define  IRDA_IR_CR_RC5_RC6_get_trailer_code_rc56(data)                          ((0x00008000&(data))>>15)
#define  IRDA_IR_CR_RC5_RC6_get_rpt_code_rc56(data)                              ((0x00004000&(data))>>14)
#define  IRDA_IR_CR_RC5_RC6_get_ph_mod_inv_rc56(data)                            ((0x00002000&(data))>>13)
#define  IRDA_IR_CR_RC5_RC6_get_len_mod_inv_rc56(data)                           ((0x00001000&(data))>>12)
#define  IRDA_IR_CR_RC5_RC6_get_lat_ph_len_rc56(data)                            ((0x00000800&(data))>>11)
#define  IRDA_IR_CR_RC5_RC6_get_start_bit_rc56(data)                             ((0x00000400&(data))>>10)
#define  IRDA_IR_CR_RC5_RC6_get_lead_code_rc56(data)                             ((0x00000200&(data))>>9)
#define  IRDA_IR_CR_RC5_RC6_get_lat_rx_endian_rc56(data)                         ((0x00000100&(data))>>8)
#define  IRDA_IR_CR_RC5_RC6_get_lat_data_ph_rc56(data)                           ((0x00000080&(data))>>7)
#define  IRDA_IR_CR_RC5_RC6_get_lat_data_num_rc56(data)                          ((0x0000007E&(data))>>1)
#define  IRDA_IR_CR_RC5_RC6_get_main1_en(data)                                   (0x00000001&(data))

#define  IRDA_IR_DPIR_RC5_RC6                                                    0x180614B4
#define  IRDA_IR_DPIR_RC5_RC6_reg_addr                                           "0xB80614B4"
#define  IRDA_IR_DPIR_RC5_RC6_reg                                                0xB80614B4
#define  IRDA_IR_DPIR_RC5_RC6_inst_addr                                          "0x001E"
#define  set_IRDA_IR_DPIR_RC5_RC6_reg(data)                                      (*((volatile unsigned int*)IRDA_IR_DPIR_RC5_RC6_reg)=data)
#define  get_IRDA_IR_DPIR_RC5_RC6_reg                                            (*((volatile unsigned int*)IRDA_IR_DPIR_RC5_RC6_reg))
#define  IRDA_IR_DPIR_RC5_RC6_irit_rc56_shift                                    (16)
#define  IRDA_IR_DPIR_RC5_RC6_iriotcdp_rc56_shift                                (0)
#define  IRDA_IR_DPIR_RC5_RC6_irit_rc56_mask                                     (0x00FF0000)
#define  IRDA_IR_DPIR_RC5_RC6_iriotcdp_rc56_mask                                 (0x0000FFFF)
#define  IRDA_IR_DPIR_RC5_RC6_irit_rc56(data)                                    (0x00FF0000&((data)<<16))
#define  IRDA_IR_DPIR_RC5_RC6_iriotcdp_rc56(data)                                (0x0000FFFF&(data))
#define  IRDA_IR_DPIR_RC5_RC6_get_irit_rc56(data)                                ((0x00FF0000&(data))>>16)
#define  IRDA_IR_DPIR_RC5_RC6_get_iriotcdp_rc56(data)                            (0x0000FFFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======IRDA register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lat_lead_low:8;
        RBus_UInt32  lat_logic_low:8;
        RBus_UInt32  lat_data0_high:8;
        RBus_UInt32  lat_data1_high:8;
    };
}irda_ir_psr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ir_data_width:8;
        RBus_UInt32  ir_data_width_rst:1;
        RBus_UInt32  ir_data_cnt_sel:1;
        RBus_UInt32  lat_denos_num:6;
        RBus_UInt32  lat_rpt_high:8;
        RBus_UInt32  lat_lead_high:8;
    };
}irda_ir_per_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  irit:8;
        RBus_UInt32  iroct:8;
        RBus_UInt32  irfd:16;
    };
}irda_ir_sf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ir_data_with_limit:16;
        RBus_UInt32  iriotcdp:16;
    };
}irda_ir_dpir_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  burst_len_check_old:1;
        RBus_UInt32  ir_data_limit_en:1;
        RBus_UInt32  irednm:1;
        RBus_UInt32  rc5_rc6_common_mode:1;
        RBus_UInt32  iredn:6;
        RBus_UInt32  burst_len_check:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  normal_data_num_en:1;
        RBus_UInt32  ir_sony_sirc:1;
        RBus_UInt32  ir_hwval_ie:1;
        RBus_UInt32  lat_rx_endian:1;
        RBus_UInt32  main0_en:1;
        RBus_UInt32  lat_ph_len:1;
        RBus_UInt32  lat_burst_mode:1;
        RBus_UInt32  lat_data_ph:1;
        RBus_UInt32  lat_data_num:5;
    };
}irda_ir_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  irrp:32;
    };
}irda_ir_rp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  detect_data_main_short_1:1;
        RBus_UInt32  detect_data_main_short_0:1;
        RBus_UInt32  second_data_num_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  second_data_num:5;
        RBus_UInt32  data_too_long:1;
        RBus_UInt32  data_toggle:1;
        RBus_UInt32  detect_data_main_1:1;
        RBus_UInt32  detect_data_main_0:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  rc6_leader_wrong:1;
        RBus_UInt32  data_still_toggle:1;
        RBus_UInt32  ov_up_fl_st:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  data_too_long_rc56:1;
        RBus_UInt32  irrf:1;
        RBus_UInt32  irdvf:1;
    };
}irda_ir_sr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  irrbl_up:8;
        RBus_UInt32  irrml_up:8;
        RBus_UInt32  irrdzl_up:8;
        RBus_UInt32  irrdol_up:8;
    };
}irda_ir_psr_up_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  irrrl_up:8;
        RBus_UInt32  irrsl_up:8;
    };
}irda_ir_per_up_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  last_bit_length_en:1;
        RBus_UInt32  toshiba_en:1;
        RBus_UInt32  rc6_en:1;
        RBus_UInt32  irtr:8;
    };
}irda_ir_ctrl_rc6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  irrp_up:32;
    };
}irda_ir_rp2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  rp_num:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  ext_rp_en:1;
    };
}irda_ir_ext_rp_cf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rp_burst:8;
        RBus_UInt32  rp_silence:8;
        RBus_UInt32  rp_tail_burst:8;
        RBus_UInt32  rp_tail_silence:8;
    };
}irda_ir_ext_rp_timing_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rp_burst_up:8;
        RBus_UInt32  rp_silence_up:8;
        RBus_UInt32  rp_tail_burst_up:8;
        RBus_UInt32  rp_tail_silence_up:8;
    };
}irda_ir_ext_rp_timing_up_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  decode_mask_data_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  decode_mask_data_sel:5;
        RBus_UInt32  hw_decode_data_en:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  hw_decode_data_sel:5;
    };
}irda_hw_decode_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hw_decode_data_read:32;
    };
}irda_hw_decode_read_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decode_mask_data_read:32;
    };
}irda_decode_mask_data_read_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hw_decode_data:32;
    };
}irda_hw_decode_data__RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decode_mask_data:32;
    };
}irda_decode_mask_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  compare7_enable:1;
        RBus_UInt32  compare6_enable:1;
        RBus_UInt32  compare5_enable:1;
        RBus_UInt32  compare4_enable:1;
        RBus_UInt32  compare3_enable:1;
        RBus_UInt32  compare2_enable:1;
        RBus_UInt32  compare1_enable:1;
        RBus_UInt32  compare0_enable:1;
        RBus_UInt32  res1:8;
        RBus_UInt32  compare7_int_en:1;
        RBus_UInt32  compare6_int_en:1;
        RBus_UInt32  compare5_int_en:1;
        RBus_UInt32  compare4_int_en:1;
        RBus_UInt32  compare3_int_en:1;
        RBus_UInt32  compare2_int_en:1;
        RBus_UInt32  compare1_int_en:1;
        RBus_UInt32  compare0_int_en:1;
        RBus_UInt32  compare7_int_status:1;
        RBus_UInt32  compare6_int_status:1;
        RBus_UInt32  compare5_int_status:1;
        RBus_UInt32  compare4_int_status:1;
        RBus_UInt32  compare3_int_status:1;
        RBus_UInt32  compare2_int_status:1;
        RBus_UInt32  compare1_int_status:1;
        RBus_UInt32  compare0_int_status:1;
    };
}irda_int_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  compare15_enable:1;
        RBus_UInt32  compare14_enable:1;
        RBus_UInt32  compare13_enable:1;
        RBus_UInt32  compare12_enable:1;
        RBus_UInt32  compare11_enable:1;
        RBus_UInt32  compare10_enable:1;
        RBus_UInt32  compare9_enable:1;
        RBus_UInt32  compare8_enable:1;
        RBus_UInt32  res1:8;
        RBus_UInt32  compare15_int_en:1;
        RBus_UInt32  compare14_int_en:1;
        RBus_UInt32  compare13_int_en:1;
        RBus_UInt32  compare12_int_en:1;
        RBus_UInt32  compare11_int_en:1;
        RBus_UInt32  compare10_int_en:1;
        RBus_UInt32  compare9_int_en:1;
        RBus_UInt32  compare8_int_en:1;
        RBus_UInt32  compare15_int_status:1;
        RBus_UInt32  compare14_int_status:1;
        RBus_UInt32  compare13_int_status:1;
        RBus_UInt32  compare12_int_status:1;
        RBus_UInt32  compare11_int_status:1;
        RBus_UInt32  compare10_int_status:1;
        RBus_UInt32  compare9_int_status:1;
        RBus_UInt32  compare8_int_status:1;
    };
}irda_int_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  test_mode_en:1;
    };
}irda_compare_test_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  test_mode_data_0:32;
    };
}irda_compare_test_mode_data7_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  test_mode_data_1:32;
    };
}irda_compare_test_mode_data7_h_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  test_mode_sel:32;
    };
}irda_compare_test_mode_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lat_lead_low_rc56:8;
        RBus_UInt32  lat_logic_low_rc56:8;
        RBus_UInt32  lat_data0_high_rc56:8;
        RBus_UInt32  lat_data1_high_rc56:8;
    };
}irda_ir_psr_rc5_rc6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  rp_burst_rc56:8;
        RBus_UInt32  rp_silence_rc56:8;
        RBus_UInt32  lat_denos_num_rc56:6;
        RBus_UInt32  lat_lead_high_rc56:8;
    };
}irda_ir_per_rc5_rc6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  irrbl_up_rc56:8;
        RBus_UInt32  irrml_up_rc56:8;
        RBus_UInt32  irrdzl_up_rc56:8;
        RBus_UInt32  irrdol_up_rc56:8;
    };
}irda_ir_psr_up_rc5_rc6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rp_burst_up_rc56:8;
        RBus_UInt32  rp_silence_up_rc56:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  irrsl_up_rc56:8;
    };
}irda_ir_per_up_rc5_rc6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  second_data_num_rc56:6;
        RBus_UInt32  normal_data_num_en_rc56:1;
        RBus_UInt32  trailer_code_rc56:1;
        RBus_UInt32  rpt_code_rc56:1;
        RBus_UInt32  ph_mod_inv_rc56:1;
        RBus_UInt32  len_mod_inv_rc56:1;
        RBus_UInt32  lat_ph_len_rc56:1;
        RBus_UInt32  start_bit_rc56:1;
        RBus_UInt32  lead_code_rc56:1;
        RBus_UInt32  lat_rx_endian_rc56:1;
        RBus_UInt32  lat_data_ph_rc56:1;
        RBus_UInt32  lat_data_num_rc56:6;
        RBus_UInt32  main1_en:1;
    };
}irda_ir_cr_rc5_rc6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  irit_rc56:8;
        RBus_UInt32  iriotcdp_rc56:16;
    };
}irda_ir_dpir_rc5_rc6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}irda_ir_sf_rc5_rc6_RBUS;

#else //apply LITTLE_ENDIAN

//======IRDA register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lat_data1_high:8;
        RBus_UInt32  lat_data0_high:8;
        RBus_UInt32  lat_logic_low:8;
        RBus_UInt32  lat_lead_low:8;
    };
}irda_ir_psr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lat_lead_high:8;
        RBus_UInt32  lat_rpt_high:8;
        RBus_UInt32  lat_denos_num:6;
        RBus_UInt32  ir_data_cnt_sel:1;
        RBus_UInt32  ir_data_width_rst:1;
        RBus_UInt32  ir_data_width:8;
    };
}irda_ir_per_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  irfd:16;
        RBus_UInt32  iroct:8;
        RBus_UInt32  irit:8;
    };
}irda_ir_sf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  iriotcdp:16;
        RBus_UInt32  ir_data_with_limit:16;
    };
}irda_ir_dpir_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lat_data_num:5;
        RBus_UInt32  lat_data_ph:1;
        RBus_UInt32  lat_burst_mode:1;
        RBus_UInt32  lat_ph_len:1;
        RBus_UInt32  main0_en:1;
        RBus_UInt32  lat_rx_endian:1;
        RBus_UInt32  ir_hwval_ie:1;
        RBus_UInt32  ir_sony_sirc:1;
        RBus_UInt32  normal_data_num_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  burst_len_check:1;
        RBus_UInt32  iredn:6;
        RBus_UInt32  rc5_rc6_common_mode:1;
        RBus_UInt32  irednm:1;
        RBus_UInt32  ir_data_limit_en:1;
        RBus_UInt32  burst_len_check_old:1;
        RBus_UInt32  res2:6;
    };
}irda_ir_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  irrp:32;
    };
}irda_ir_rp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  irdvf:1;
        RBus_UInt32  irrf:1;
        RBus_UInt32  data_too_long_rc56:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  ov_up_fl_st:1;
        RBus_UInt32  data_still_toggle:1;
        RBus_UInt32  rc6_leader_wrong:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  detect_data_main_0:1;
        RBus_UInt32  detect_data_main_1:1;
        RBus_UInt32  data_toggle:1;
        RBus_UInt32  data_too_long:1;
        RBus_UInt32  second_data_num:5;
        RBus_UInt32  res3:2;
        RBus_UInt32  second_data_num_en:1;
        RBus_UInt32  detect_data_main_short_0:1;
        RBus_UInt32  detect_data_main_short_1:1;
        RBus_UInt32  res4:10;
    };
}irda_ir_sr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  irrdol_up:8;
        RBus_UInt32  irrdzl_up:8;
        RBus_UInt32  irrml_up:8;
        RBus_UInt32  irrbl_up:8;
    };
}irda_ir_psr_up_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  irrsl_up:8;
        RBus_UInt32  irrrl_up:8;
        RBus_UInt32  res1:16;
    };
}irda_ir_per_up_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  irtr:8;
        RBus_UInt32  rc6_en:1;
        RBus_UInt32  toshiba_en:1;
        RBus_UInt32  last_bit_length_en:1;
        RBus_UInt32  res1:21;
    };
}irda_ir_ctrl_rc6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  irrp_up:32;
    };
}irda_ir_rp2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ext_rp_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  rp_num:4;
        RBus_UInt32  res2:24;
    };
}irda_ir_ext_rp_cf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rp_tail_silence:8;
        RBus_UInt32  rp_tail_burst:8;
        RBus_UInt32  rp_silence:8;
        RBus_UInt32  rp_burst:8;
    };
}irda_ir_ext_rp_timing_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rp_tail_silence_up:8;
        RBus_UInt32  rp_tail_burst_up:8;
        RBus_UInt32  rp_silence_up:8;
        RBus_UInt32  rp_burst_up:8;
    };
}irda_ir_ext_rp_timing_up_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hw_decode_data_sel:5;
        RBus_UInt32  res1:2;
        RBus_UInt32  hw_decode_data_en:1;
        RBus_UInt32  decode_mask_data_sel:5;
        RBus_UInt32  res2:2;
        RBus_UInt32  decode_mask_data_en:1;
        RBus_UInt32  res3:16;
    };
}irda_hw_decode_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hw_decode_data_read:32;
    };
}irda_hw_decode_read_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decode_mask_data_read:32;
    };
}irda_decode_mask_data_read_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hw_decode_data:32;
    };
}irda_hw_decode_data__RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decode_mask_data:32;
    };
}irda_decode_mask_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  compare0_int_status:1;
        RBus_UInt32  compare1_int_status:1;
        RBus_UInt32  compare2_int_status:1;
        RBus_UInt32  compare3_int_status:1;
        RBus_UInt32  compare4_int_status:1;
        RBus_UInt32  compare5_int_status:1;
        RBus_UInt32  compare6_int_status:1;
        RBus_UInt32  compare7_int_status:1;
        RBus_UInt32  compare0_int_en:1;
        RBus_UInt32  compare1_int_en:1;
        RBus_UInt32  compare2_int_en:1;
        RBus_UInt32  compare3_int_en:1;
        RBus_UInt32  compare4_int_en:1;
        RBus_UInt32  compare5_int_en:1;
        RBus_UInt32  compare6_int_en:1;
        RBus_UInt32  compare7_int_en:1;
        RBus_UInt32  res1:8;
        RBus_UInt32  compare0_enable:1;
        RBus_UInt32  compare1_enable:1;
        RBus_UInt32  compare2_enable:1;
        RBus_UInt32  compare3_enable:1;
        RBus_UInt32  compare4_enable:1;
        RBus_UInt32  compare5_enable:1;
        RBus_UInt32  compare6_enable:1;
        RBus_UInt32  compare7_enable:1;
    };
}irda_int_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  compare8_int_status:1;
        RBus_UInt32  compare9_int_status:1;
        RBus_UInt32  compare10_int_status:1;
        RBus_UInt32  compare11_int_status:1;
        RBus_UInt32  compare12_int_status:1;
        RBus_UInt32  compare13_int_status:1;
        RBus_UInt32  compare14_int_status:1;
        RBus_UInt32  compare15_int_status:1;
        RBus_UInt32  compare8_int_en:1;
        RBus_UInt32  compare9_int_en:1;
        RBus_UInt32  compare10_int_en:1;
        RBus_UInt32  compare11_int_en:1;
        RBus_UInt32  compare12_int_en:1;
        RBus_UInt32  compare13_int_en:1;
        RBus_UInt32  compare14_int_en:1;
        RBus_UInt32  compare15_int_en:1;
        RBus_UInt32  res1:8;
        RBus_UInt32  compare8_enable:1;
        RBus_UInt32  compare9_enable:1;
        RBus_UInt32  compare10_enable:1;
        RBus_UInt32  compare11_enable:1;
        RBus_UInt32  compare12_enable:1;
        RBus_UInt32  compare13_enable:1;
        RBus_UInt32  compare14_enable:1;
        RBus_UInt32  compare15_enable:1;
    };
}irda_int_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  test_mode_en:1;
        RBus_UInt32  res1:31;
    };
}irda_compare_test_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  test_mode_data_0:32;
    };
}irda_compare_test_mode_data7_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  test_mode_data_1:32;
    };
}irda_compare_test_mode_data7_h_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  test_mode_sel:32;
    };
}irda_compare_test_mode_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lat_data1_high_rc56:8;
        RBus_UInt32  lat_data0_high_rc56:8;
        RBus_UInt32  lat_logic_low_rc56:8;
        RBus_UInt32  lat_lead_low_rc56:8;
    };
}irda_ir_psr_rc5_rc6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lat_lead_high_rc56:8;
        RBus_UInt32  lat_denos_num_rc56:6;
        RBus_UInt32  rp_silence_rc56:8;
        RBus_UInt32  rp_burst_rc56:8;
        RBus_UInt32  res1:2;
    };
}irda_ir_per_rc5_rc6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  irrdol_up_rc56:8;
        RBus_UInt32  irrdzl_up_rc56:8;
        RBus_UInt32  irrml_up_rc56:8;
        RBus_UInt32  irrbl_up_rc56:8;
    };
}irda_ir_psr_up_rc5_rc6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  irrsl_up_rc56:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  rp_silence_up_rc56:8;
        RBus_UInt32  rp_burst_up_rc56:8;
    };
}irda_ir_per_up_rc5_rc6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  main1_en:1;
        RBus_UInt32  lat_data_num_rc56:6;
        RBus_UInt32  lat_data_ph_rc56:1;
        RBus_UInt32  lat_rx_endian_rc56:1;
        RBus_UInt32  lead_code_rc56:1;
        RBus_UInt32  start_bit_rc56:1;
        RBus_UInt32  lat_ph_len_rc56:1;
        RBus_UInt32  len_mod_inv_rc56:1;
        RBus_UInt32  ph_mod_inv_rc56:1;
        RBus_UInt32  rpt_code_rc56:1;
        RBus_UInt32  trailer_code_rc56:1;
        RBus_UInt32  normal_data_num_en_rc56:1;
        RBus_UInt32  second_data_num_rc56:6;
        RBus_UInt32  res1:9;
    };
}irda_ir_cr_rc5_rc6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  iriotcdp_rc56:16;
        RBus_UInt32  irit_rc56:8;
        RBus_UInt32  res1:8;
    };
}irda_ir_dpir_rc5_rc6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}irda_ir_sf_rc5_rc6_RBUS;




#endif 


#endif 
