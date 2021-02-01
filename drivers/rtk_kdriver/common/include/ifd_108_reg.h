/**
* @file rbusIFD_108Reg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_IFD_108_REG_H_
#define _RBUS_IFD_108_REG_H_

#include "rbus_types.h"



//  IFD_108 Register Address
#define  IFD_108_cr_bpf_sel                                                      0x18032000
#define  IFD_108_cr_bpf_sel_reg_addr                                             "0xB8032000"
#define  IFD_108_cr_bpf_sel_reg                                                  0xB8032000
#define  IFD_108_cr_bpf_sel_inst_addr                                            "0x0000"
#define  set_IFD_108_cr_bpf_sel_reg(data)                                        (*((volatile unsigned int*)IFD_108_cr_bpf_sel_reg)=data)
#define  get_IFD_108_cr_bpf_sel_reg                                              (*((volatile unsigned int*)IFD_108_cr_bpf_sel_reg))
#define  IFD_108_cr_bpf_sel_cr_delay_shift                                       (28)
#define  IFD_108_cr_bpf_sel_cr_inner_lpf_sel_shift                               (27)
#define  IFD_108_cr_bpf_sel_cr_inner_lpf_en_shift                                (26)
#define  IFD_108_cr_bpf_sel_cr_bpf_en_shift                                      (25)
#define  IFD_108_cr_bpf_sel_cr_bpf_coe_modify_en_shift                           (24)
#define  IFD_108_cr_bpf_sel_cr_bpf_coe_tap_shift                                 (16)
#define  IFD_108_cr_bpf_sel_cr_bpf_coe_shift                                     (0)
#define  IFD_108_cr_bpf_sel_cr_delay_mask                                        (0xF0000000)
#define  IFD_108_cr_bpf_sel_cr_inner_lpf_sel_mask                                (0x08000000)
#define  IFD_108_cr_bpf_sel_cr_inner_lpf_en_mask                                 (0x04000000)
#define  IFD_108_cr_bpf_sel_cr_bpf_en_mask                                       (0x02000000)
#define  IFD_108_cr_bpf_sel_cr_bpf_coe_modify_en_mask                            (0x01000000)
#define  IFD_108_cr_bpf_sel_cr_bpf_coe_tap_mask                                  (0x007F0000)
#define  IFD_108_cr_bpf_sel_cr_bpf_coe_mask                                      (0x00007FFF)
#define  IFD_108_cr_bpf_sel_cr_delay(data)                                       (0xF0000000&((data)<<28))
#define  IFD_108_cr_bpf_sel_cr_inner_lpf_sel(data)                               (0x08000000&((data)<<27))
#define  IFD_108_cr_bpf_sel_cr_inner_lpf_en(data)                                (0x04000000&((data)<<26))
#define  IFD_108_cr_bpf_sel_cr_bpf_en(data)                                      (0x02000000&((data)<<25))
#define  IFD_108_cr_bpf_sel_cr_bpf_coe_modify_en(data)                           (0x01000000&((data)<<24))
#define  IFD_108_cr_bpf_sel_cr_bpf_coe_tap(data)                                 (0x007F0000&((data)<<16))
#define  IFD_108_cr_bpf_sel_cr_bpf_coe(data)                                     (0x00007FFF&(data))
#define  IFD_108_cr_bpf_sel_get_cr_delay(data)                                   ((0xF0000000&(data))>>28)
#define  IFD_108_cr_bpf_sel_get_cr_inner_lpf_sel(data)                           ((0x08000000&(data))>>27)
#define  IFD_108_cr_bpf_sel_get_cr_inner_lpf_en(data)                            ((0x04000000&(data))>>26)
#define  IFD_108_cr_bpf_sel_get_cr_bpf_en(data)                                  ((0x02000000&(data))>>25)
#define  IFD_108_cr_bpf_sel_get_cr_bpf_coe_modify_en(data)                       ((0x01000000&(data))>>24)
#define  IFD_108_cr_bpf_sel_get_cr_bpf_coe_tap(data)                             ((0x007F0000&(data))>>16)
#define  IFD_108_cr_bpf_sel_get_cr_bpf_coe(data)                                 (0x00007FFF&(data))

#define  IFD_108_cr_bpf_read                                                     0x18032004
#define  IFD_108_cr_bpf_read_reg_addr                                            "0xB8032004"
#define  IFD_108_cr_bpf_read_reg                                                 0xB8032004
#define  IFD_108_cr_bpf_read_inst_addr                                           "0x0001"
#define  set_IFD_108_cr_bpf_read_reg(data)                                       (*((volatile unsigned int*)IFD_108_cr_bpf_read_reg)=data)
#define  get_IFD_108_cr_bpf_read_reg                                             (*((volatile unsigned int*)IFD_108_cr_bpf_read_reg))
#define  IFD_108_cr_bpf_read_cr_bpf_coe_read_tap_shift                           (16)
#define  IFD_108_cr_bpf_read_cr_bpf_coe_read_shift                               (0)
#define  IFD_108_cr_bpf_read_cr_bpf_coe_read_tap_mask                            (0x007F0000)
#define  IFD_108_cr_bpf_read_cr_bpf_coe_read_mask                                (0x00007FFF)
#define  IFD_108_cr_bpf_read_cr_bpf_coe_read_tap(data)                           (0x007F0000&((data)<<16))
#define  IFD_108_cr_bpf_read_cr_bpf_coe_read(data)                               (0x00007FFF&(data))
#define  IFD_108_cr_bpf_read_get_cr_bpf_coe_read_tap(data)                       ((0x007F0000&(data))>>16)
#define  IFD_108_cr_bpf_read_get_cr_bpf_coe_read(data)                           (0x00007FFF&(data))

#define  IFD_108_cr_pgain                                                        0x18032008
#define  IFD_108_cr_pgain_reg_addr                                               "0xB8032008"
#define  IFD_108_cr_pgain_reg                                                    0xB8032008
#define  IFD_108_cr_pgain_inst_addr                                              "0x0002"
#define  set_IFD_108_cr_pgain_reg(data)                                          (*((volatile unsigned int*)IFD_108_cr_pgain_reg)=data)
#define  get_IFD_108_cr_pgain_reg                                                (*((volatile unsigned int*)IFD_108_cr_pgain_reg))
#define  IFD_108_cr_pgain_cr_st4_kp_shift                                        (28)
#define  IFD_108_cr_pgain_cr_st4_ki_shift                                        (24)
#define  IFD_108_cr_pgain_cr_st2_kp_shift                                        (20)
#define  IFD_108_cr_pgain_cr_st2_ki_shift                                        (16)
#define  IFD_108_cr_pgain_cr_st0_kp_shift                                        (12)
#define  IFD_108_cr_pgain_cr_st0_ki_shift                                        (8)
#define  IFD_108_cr_pgain_cr_pgain_shift                                         (4)
#define  IFD_108_cr_pgain_cr_igain_shift                                         (0)
#define  IFD_108_cr_pgain_cr_st4_kp_mask                                         (0xF0000000)
#define  IFD_108_cr_pgain_cr_st4_ki_mask                                         (0x0F000000)
#define  IFD_108_cr_pgain_cr_st2_kp_mask                                         (0x00F00000)
#define  IFD_108_cr_pgain_cr_st2_ki_mask                                         (0x000F0000)
#define  IFD_108_cr_pgain_cr_st0_kp_mask                                         (0x0000F000)
#define  IFD_108_cr_pgain_cr_st0_ki_mask                                         (0x00000F00)
#define  IFD_108_cr_pgain_cr_pgain_mask                                          (0x000000F0)
#define  IFD_108_cr_pgain_cr_igain_mask                                          (0x0000000F)
#define  IFD_108_cr_pgain_cr_st4_kp(data)                                        (0xF0000000&((data)<<28))
#define  IFD_108_cr_pgain_cr_st4_ki(data)                                        (0x0F000000&((data)<<24))
#define  IFD_108_cr_pgain_cr_st2_kp(data)                                        (0x00F00000&((data)<<20))
#define  IFD_108_cr_pgain_cr_st2_ki(data)                                        (0x000F0000&((data)<<16))
#define  IFD_108_cr_pgain_cr_st0_kp(data)                                        (0x0000F000&((data)<<12))
#define  IFD_108_cr_pgain_cr_st0_ki(data)                                        (0x00000F00&((data)<<8))
#define  IFD_108_cr_pgain_cr_pgain(data)                                         (0x000000F0&((data)<<4))
#define  IFD_108_cr_pgain_cr_igain(data)                                         (0x0000000F&(data))
#define  IFD_108_cr_pgain_get_cr_st4_kp(data)                                    ((0xF0000000&(data))>>28)
#define  IFD_108_cr_pgain_get_cr_st4_ki(data)                                    ((0x0F000000&(data))>>24)
#define  IFD_108_cr_pgain_get_cr_st2_kp(data)                                    ((0x00F00000&(data))>>20)
#define  IFD_108_cr_pgain_get_cr_st2_ki(data)                                    ((0x000F0000&(data))>>16)
#define  IFD_108_cr_pgain_get_cr_st0_kp(data)                                    ((0x0000F000&(data))>>12)
#define  IFD_108_cr_pgain_get_cr_st0_ki(data)                                    ((0x00000F00&(data))>>8)
#define  IFD_108_cr_pgain_get_cr_pgain(data)                                     ((0x000000F0&(data))>>4)
#define  IFD_108_cr_pgain_get_cr_igain(data)                                     (0x0000000F&(data))

#define  IFD_108_cr_lock                                                         0x1803200C
#define  IFD_108_cr_lock_reg_addr                                                "0xB803200C"
#define  IFD_108_cr_lock_reg                                                     0xB803200C
#define  IFD_108_cr_lock_inst_addr                                               "0x0003"
#define  set_IFD_108_cr_lock_reg(data)                                           (*((volatile unsigned int*)IFD_108_cr_lock_reg)=data)
#define  get_IFD_108_cr_lock_reg                                                 (*((volatile unsigned int*)IFD_108_cr_lock_reg))
#define  IFD_108_cr_lock_cr_lock_freq_thr_shift                                  (20)
#define  IFD_108_cr_lock_cr_lock_with_freq_shift                                 (16)
#define  IFD_108_cr_lock_cr_lock_with_hsync_shift                                (13)
#define  IFD_108_cr_lock_cr_lock_with_agc_shift                                  (12)
#define  IFD_108_cr_lock_cr_lock_ref_shift                                       (4)
#define  IFD_108_cr_lock_cr_lock_shift                                           (0)
#define  IFD_108_cr_lock_cr_lock_freq_thr_mask                                   (0xFFF00000)
#define  IFD_108_cr_lock_cr_lock_with_freq_mask                                  (0x00010000)
#define  IFD_108_cr_lock_cr_lock_with_hsync_mask                                 (0x00002000)
#define  IFD_108_cr_lock_cr_lock_with_agc_mask                                   (0x00001000)
#define  IFD_108_cr_lock_cr_lock_ref_mask                                        (0x00000FF0)
#define  IFD_108_cr_lock_cr_lock_mask                                            (0x00000001)
#define  IFD_108_cr_lock_cr_lock_freq_thr(data)                                  (0xFFF00000&((data)<<20))
#define  IFD_108_cr_lock_cr_lock_with_freq(data)                                 (0x00010000&((data)<<16))
#define  IFD_108_cr_lock_cr_lock_with_hsync(data)                                (0x00002000&((data)<<13))
#define  IFD_108_cr_lock_cr_lock_with_agc(data)                                  (0x00001000&((data)<<12))
#define  IFD_108_cr_lock_cr_lock_ref(data)                                       (0x00000FF0&((data)<<4))
#define  IFD_108_cr_lock_cr_lock(data)                                           (0x00000001&(data))
#define  IFD_108_cr_lock_get_cr_lock_freq_thr(data)                              ((0xFFF00000&(data))>>20)
#define  IFD_108_cr_lock_get_cr_lock_with_freq(data)                             ((0x00010000&(data))>>16)
#define  IFD_108_cr_lock_get_cr_lock_with_hsync(data)                            ((0x00002000&(data))>>13)
#define  IFD_108_cr_lock_get_cr_lock_with_agc(data)                              ((0x00001000&(data))>>12)
#define  IFD_108_cr_lock_get_cr_lock_ref(data)                                   ((0x00000FF0&(data))>>4)
#define  IFD_108_cr_lock_get_cr_lock(data)                                       (0x00000001&(data))

#define  IFD_108_cr_nco_fix_data                                                 0x18032010
#define  IFD_108_cr_nco_fix_data_reg_addr                                        "0xB8032010"
#define  IFD_108_cr_nco_fix_data_reg                                             0xB8032010
#define  IFD_108_cr_nco_fix_data_inst_addr                                       "0x0004"
#define  set_IFD_108_cr_nco_fix_data_reg(data)                                   (*((volatile unsigned int*)IFD_108_cr_nco_fix_data_reg)=data)
#define  get_IFD_108_cr_nco_fix_data_reg                                         (*((volatile unsigned int*)IFD_108_cr_nco_fix_data_reg))
#define  IFD_108_cr_nco_fix_data_cr_ncoerr_en_shift                              (20)
#define  IFD_108_cr_nco_fix_data_cr_nco_fix_data_shift                           (0)
#define  IFD_108_cr_nco_fix_data_cr_ncoerr_en_mask                               (0x00100000)
#define  IFD_108_cr_nco_fix_data_cr_nco_fix_data_mask                            (0x000FFFFF)
#define  IFD_108_cr_nco_fix_data_cr_ncoerr_en(data)                              (0x00100000&((data)<<20))
#define  IFD_108_cr_nco_fix_data_cr_nco_fix_data(data)                           (0x000FFFFF&(data))
#define  IFD_108_cr_nco_fix_data_get_cr_ncoerr_en(data)                          ((0x00100000&(data))>>20)
#define  IFD_108_cr_nco_fix_data_get_cr_nco_fix_data(data)                       (0x000FFFFF&(data))

#define  IFD_108_cr_freq_sat                                                     0x18032014
#define  IFD_108_cr_freq_sat_reg_addr                                            "0xB8032014"
#define  IFD_108_cr_freq_sat_reg                                                 0xB8032014
#define  IFD_108_cr_freq_sat_inst_addr                                           "0x0005"
#define  set_IFD_108_cr_freq_sat_reg(data)                                       (*((volatile unsigned int*)IFD_108_cr_freq_sat_reg)=data)
#define  get_IFD_108_cr_freq_sat_reg                                             (*((volatile unsigned int*)IFD_108_cr_freq_sat_reg))
#define  IFD_108_cr_freq_sat_cr_offset_sat_shift                                 (0)
#define  IFD_108_cr_freq_sat_cr_offset_sat_mask                                  (0x0001FFFF)
#define  IFD_108_cr_freq_sat_cr_offset_sat(data)                                 (0x0001FFFF&(data))
#define  IFD_108_cr_freq_sat_get_cr_offset_sat(data)                             (0x0001FFFF&(data))

#define  IFD_108_cr_freq_status                                                  0x18032018
#define  IFD_108_cr_freq_status_reg_addr                                         "0xB8032018"
#define  IFD_108_cr_freq_status_reg                                              0xB8032018
#define  IFD_108_cr_freq_status_inst_addr                                        "0x0006"
#define  set_IFD_108_cr_freq_status_reg(data)                                    (*((volatile unsigned int*)IFD_108_cr_freq_status_reg)=data)
#define  get_IFD_108_cr_freq_status_reg                                          (*((volatile unsigned int*)IFD_108_cr_freq_status_reg))
#define  IFD_108_cr_freq_status_cr_freq_status_shift                             (0)
#define  IFD_108_cr_freq_status_cr_freq_status_mask                              (0x000FFFFF)
#define  IFD_108_cr_freq_status_cr_freq_status(data)                             (0x000FFFFF&(data))
#define  IFD_108_cr_freq_status_get_cr_freq_status(data)                         (0x000FFFFF&(data))

#define  IFD_108_cr_weight_en                                                    0x1803201C
#define  IFD_108_cr_weight_en_reg_addr                                           "0xB803201C"
#define  IFD_108_cr_weight_en_reg                                                0xB803201C
#define  IFD_108_cr_weight_en_inst_addr                                          "0x0007"
#define  set_IFD_108_cr_weight_en_reg(data)                                      (*((volatile unsigned int*)IFD_108_cr_weight_en_reg)=data)
#define  get_IFD_108_cr_weight_en_reg                                            (*((volatile unsigned int*)IFD_108_cr_weight_en_reg))
#define  IFD_108_cr_weight_en_cr_weighting_thr_shift                             (16)
#define  IFD_108_cr_weight_en_cr_weighting_thr_en_shift                          (12)
#define  IFD_108_cr_weight_en_cr_weighting_cr_lock_dis_shift                     (9)
#define  IFD_108_cr_weight_en_cr_weighting_en_shift                              (8)
#define  IFD_108_cr_weight_en_cr_weight_max_decrease_shift                       (4)
#define  IFD_108_cr_weight_en_cr_weight_shift_shift                              (0)
#define  IFD_108_cr_weight_en_cr_weighting_thr_mask                              (0x0FFF0000)
#define  IFD_108_cr_weight_en_cr_weighting_thr_en_mask                           (0x00001000)
#define  IFD_108_cr_weight_en_cr_weighting_cr_lock_dis_mask                      (0x00000200)
#define  IFD_108_cr_weight_en_cr_weighting_en_mask                               (0x00000100)
#define  IFD_108_cr_weight_en_cr_weight_max_decrease_mask                        (0x000000F0)
#define  IFD_108_cr_weight_en_cr_weight_shift_mask                               (0x0000000F)
#define  IFD_108_cr_weight_en_cr_weighting_thr(data)                             (0x0FFF0000&((data)<<16))
#define  IFD_108_cr_weight_en_cr_weighting_thr_en(data)                          (0x00001000&((data)<<12))
#define  IFD_108_cr_weight_en_cr_weighting_cr_lock_dis(data)                     (0x00000200&((data)<<9))
#define  IFD_108_cr_weight_en_cr_weighting_en(data)                              (0x00000100&((data)<<8))
#define  IFD_108_cr_weight_en_cr_weight_max_decrease(data)                       (0x000000F0&((data)<<4))
#define  IFD_108_cr_weight_en_cr_weight_shift(data)                              (0x0000000F&(data))
#define  IFD_108_cr_weight_en_get_cr_weighting_thr(data)                         ((0x0FFF0000&(data))>>16)
#define  IFD_108_cr_weight_en_get_cr_weighting_thr_en(data)                      ((0x00001000&(data))>>12)
#define  IFD_108_cr_weight_en_get_cr_weighting_cr_lock_dis(data)                 ((0x00000200&(data))>>9)
#define  IFD_108_cr_weight_en_get_cr_weighting_en(data)                          ((0x00000100&(data))>>8)
#define  IFD_108_cr_weight_en_get_cr_weight_max_decrease(data)                   ((0x000000F0&(data))>>4)
#define  IFD_108_cr_weight_en_get_cr_weight_shift(data)                          (0x0000000F&(data))

#define  IFD_108_cr_sine_part_inner_lpf                                          0x18032020
#define  IFD_108_cr_sine_part_inner_lpf_reg_addr                                 "0xB8032020"
#define  IFD_108_cr_sine_part_inner_lpf_reg                                      0xB8032020
#define  IFD_108_cr_sine_part_inner_lpf_inst_addr                                "0x0008"
#define  set_IFD_108_cr_sine_part_inner_lpf_reg(data)                            (*((volatile unsigned int*)IFD_108_cr_sine_part_inner_lpf_reg)=data)
#define  get_IFD_108_cr_sine_part_inner_lpf_reg                                  (*((volatile unsigned int*)IFD_108_cr_sine_part_inner_lpf_reg))
#define  IFD_108_cr_sine_part_inner_lpf_sin_sample_d_shift                       (0)
#define  IFD_108_cr_sine_part_inner_lpf_sin_sample_d_mask                        (0x00007FFF)
#define  IFD_108_cr_sine_part_inner_lpf_sin_sample_d(data)                       (0x00007FFF&(data))
#define  IFD_108_cr_sine_part_inner_lpf_get_sin_sample_d(data)                   (0x00007FFF&(data))

#define  IFD_108_cr_inner_lpf_1                                                  0x18032024
#define  IFD_108_cr_inner_lpf_1_reg_addr                                         "0xB8032024"
#define  IFD_108_cr_inner_lpf_1_reg                                              0xB8032024
#define  IFD_108_cr_inner_lpf_1_inst_addr                                        "0x0009"
#define  set_IFD_108_cr_inner_lpf_1_reg(data)                                    (*((volatile unsigned int*)IFD_108_cr_inner_lpf_1_reg)=data)
#define  get_IFD_108_cr_inner_lpf_1_reg                                          (*((volatile unsigned int*)IFD_108_cr_inner_lpf_1_reg))
#define  IFD_108_cr_inner_lpf_1_cr_inner_lpf_tap1_shift                          (16)
#define  IFD_108_cr_inner_lpf_1_cr_inner_lpf_tap0_shift                          (0)
#define  IFD_108_cr_inner_lpf_1_cr_inner_lpf_tap1_mask                           (0x7FFF0000)
#define  IFD_108_cr_inner_lpf_1_cr_inner_lpf_tap0_mask                           (0x00007FFF)
#define  IFD_108_cr_inner_lpf_1_cr_inner_lpf_tap1(data)                          (0x7FFF0000&((data)<<16))
#define  IFD_108_cr_inner_lpf_1_cr_inner_lpf_tap0(data)                          (0x00007FFF&(data))
#define  IFD_108_cr_inner_lpf_1_get_cr_inner_lpf_tap1(data)                      ((0x7FFF0000&(data))>>16)
#define  IFD_108_cr_inner_lpf_1_get_cr_inner_lpf_tap0(data)                      (0x00007FFF&(data))

#define  IFD_108_cr_inner_lpf_2                                                  0x18032028
#define  IFD_108_cr_inner_lpf_2_reg_addr                                         "0xB8032028"
#define  IFD_108_cr_inner_lpf_2_reg                                              0xB8032028
#define  IFD_108_cr_inner_lpf_2_inst_addr                                        "0x000A"
#define  set_IFD_108_cr_inner_lpf_2_reg(data)                                    (*((volatile unsigned int*)IFD_108_cr_inner_lpf_2_reg)=data)
#define  get_IFD_108_cr_inner_lpf_2_reg                                          (*((volatile unsigned int*)IFD_108_cr_inner_lpf_2_reg))
#define  IFD_108_cr_inner_lpf_2_cr_inner_lpf_tap3_shift                          (16)
#define  IFD_108_cr_inner_lpf_2_cr_inner_lpf_tap2_shift                          (0)
#define  IFD_108_cr_inner_lpf_2_cr_inner_lpf_tap3_mask                           (0x7FFF0000)
#define  IFD_108_cr_inner_lpf_2_cr_inner_lpf_tap2_mask                           (0x00007FFF)
#define  IFD_108_cr_inner_lpf_2_cr_inner_lpf_tap3(data)                          (0x7FFF0000&((data)<<16))
#define  IFD_108_cr_inner_lpf_2_cr_inner_lpf_tap2(data)                          (0x00007FFF&(data))
#define  IFD_108_cr_inner_lpf_2_get_cr_inner_lpf_tap3(data)                      ((0x7FFF0000&(data))>>16)
#define  IFD_108_cr_inner_lpf_2_get_cr_inner_lpf_tap2(data)                      (0x00007FFF&(data))

#define  IFD_108_dummy1                                                          0x1803202C
#define  IFD_108_dummy1_reg_addr                                                 "0xB803202C"
#define  IFD_108_dummy1_reg                                                      0xB803202C
#define  IFD_108_dummy1_inst_addr                                                "0x000B"
#define  set_IFD_108_dummy1_reg(data)                                            (*((volatile unsigned int*)IFD_108_dummy1_reg)=data)
#define  get_IFD_108_dummy1_reg                                                  (*((volatile unsigned int*)IFD_108_dummy1_reg))
#define  IFD_108_dummy1_dummy1_shift                                             (0)
#define  IFD_108_dummy1_dummy1_mask                                              (0xFFFFFFFF)
#define  IFD_108_dummy1_dummy1(data)                                             (0xFFFFFFFF&(data))
#define  IFD_108_dummy1_get_dummy1(data)                                         (0xFFFFFFFF&(data))

#define  IFD_108_dummy2                                                          0x18032030
#define  IFD_108_dummy2_reg_addr                                                 "0xB8032030"
#define  IFD_108_dummy2_reg                                                      0xB8032030
#define  IFD_108_dummy2_inst_addr                                                "0x000C"
#define  set_IFD_108_dummy2_reg(data)                                            (*((volatile unsigned int*)IFD_108_dummy2_reg)=data)
#define  get_IFD_108_dummy2_reg                                                  (*((volatile unsigned int*)IFD_108_dummy2_reg))
#define  IFD_108_dummy2_dummy2_shift                                             (0)
#define  IFD_108_dummy2_dummy2_mask                                              (0xFFFFFFFF)
#define  IFD_108_dummy2_dummy2(data)                                             (0xFFFFFFFF&(data))
#define  IFD_108_dummy2_get_dummy2(data)                                         (0xFFFFFFFF&(data))

#define  IFD_108_dummy3                                                          0x18032034
#define  IFD_108_dummy3_reg_addr                                                 "0xB8032034"
#define  IFD_108_dummy3_reg                                                      0xB8032034
#define  IFD_108_dummy3_inst_addr                                                "0x000D"
#define  set_IFD_108_dummy3_reg(data)                                            (*((volatile unsigned int*)IFD_108_dummy3_reg)=data)
#define  get_IFD_108_dummy3_reg                                                  (*((volatile unsigned int*)IFD_108_dummy3_reg))
#define  IFD_108_dummy3_dummy3_shift                                             (0)
#define  IFD_108_dummy3_dummy3_mask                                              (0xFFFFFFFF)
#define  IFD_108_dummy3_dummy3(data)                                             (0xFFFFFFFF&(data))
#define  IFD_108_dummy3_get_dummy3(data)                                         (0xFFFFFFFF&(data))

#define  IFD_108_dummy4                                                          0x18032038
#define  IFD_108_dummy4_reg_addr                                                 "0xB8032038"
#define  IFD_108_dummy4_reg                                                      0xB8032038
#define  IFD_108_dummy4_inst_addr                                                "0x000E"
#define  set_IFD_108_dummy4_reg(data)                                            (*((volatile unsigned int*)IFD_108_dummy4_reg)=data)
#define  get_IFD_108_dummy4_reg                                                  (*((volatile unsigned int*)IFD_108_dummy4_reg))
#define  IFD_108_dummy4_dummy4_shift                                             (0)
#define  IFD_108_dummy4_dummy4_mask                                              (0xFFFFFFFF)
#define  IFD_108_dummy4_dummy4(data)                                             (0xFFFFFFFF&(data))
#define  IFD_108_dummy4_get_dummy4(data)                                         (0xFFFFFFFF&(data))

#define  IFD_108_dummy5                                                          0x1803203C
#define  IFD_108_dummy5_reg_addr                                                 "0xB803203C"
#define  IFD_108_dummy5_reg                                                      0xB803203C
#define  IFD_108_dummy5_inst_addr                                                "0x000F"
#define  set_IFD_108_dummy5_reg(data)                                            (*((volatile unsigned int*)IFD_108_dummy5_reg)=data)
#define  get_IFD_108_dummy5_reg                                                  (*((volatile unsigned int*)IFD_108_dummy5_reg))
#define  IFD_108_dummy5_dummy5_shift                                             (0)
#define  IFD_108_dummy5_dummy5_mask                                              (0xFFFFFFFF)
#define  IFD_108_dummy5_dummy5(data)                                             (0xFFFFFFFF&(data))
#define  IFD_108_dummy5_get_dummy5(data)                                         (0xFFFFFFFF&(data))

#define  IFD_108_shape_filter_selection                                          0x18032040
#define  IFD_108_shape_filter_selection_reg_addr                                 "0xB8032040"
#define  IFD_108_shape_filter_selection_reg                                      0xB8032040
#define  IFD_108_shape_filter_selection_inst_addr                                "0x0010"
#define  set_IFD_108_shape_filter_selection_reg(data)                            (*((volatile unsigned int*)IFD_108_shape_filter_selection_reg)=data)
#define  get_IFD_108_shape_filter_selection_reg                                  (*((volatile unsigned int*)IFD_108_shape_filter_selection_reg))
#define  IFD_108_shape_filter_selection_data_gain_shift                          (16)
#define  IFD_108_shape_filter_selection_data_gain_mask_en_shift                  (12)
#define  IFD_108_shape_filter_selection_data_gain_sel_shift                      (8)
#define  IFD_108_shape_filter_selection_shaping_bw_sel_shift                     (4)
#define  IFD_108_shape_filter_selection_shaping_image_sel_shift                  (0)
#define  IFD_108_shape_filter_selection_data_gain_mask                           (0x7FFF0000)
#define  IFD_108_shape_filter_selection_data_gain_mask_en_mask                   (0x00001000)
#define  IFD_108_shape_filter_selection_data_gain_sel_mask                       (0x00000700)
#define  IFD_108_shape_filter_selection_shaping_bw_sel_mask                      (0x00000010)
#define  IFD_108_shape_filter_selection_shaping_image_sel_mask                   (0x00000001)
#define  IFD_108_shape_filter_selection_data_gain(data)                          (0x7FFF0000&((data)<<16))
#define  IFD_108_shape_filter_selection_data_gain_mask_en(data)                  (0x00001000&((data)<<12))
#define  IFD_108_shape_filter_selection_data_gain_sel(data)                      (0x00000700&((data)<<8))
#define  IFD_108_shape_filter_selection_shaping_bw_sel(data)                     (0x00000010&((data)<<4))
#define  IFD_108_shape_filter_selection_shaping_image_sel(data)                  (0x00000001&(data))
#define  IFD_108_shape_filter_selection_get_data_gain(data)                      ((0x7FFF0000&(data))>>16)
#define  IFD_108_shape_filter_selection_get_data_gain_mask_en(data)              ((0x00001000&(data))>>12)
#define  IFD_108_shape_filter_selection_get_data_gain_sel(data)                  ((0x00000700&(data))>>8)
#define  IFD_108_shape_filter_selection_get_shaping_bw_sel(data)                 ((0x00000010&(data))>>4)
#define  IFD_108_shape_filter_selection_get_shaping_image_sel(data)              (0x00000001&(data))

#define  IFD_108_soft_reset_27_clk_phase                                         0x18032048
#define  IFD_108_soft_reset_27_clk_phase_reg_addr                                "0xB8032048"
#define  IFD_108_soft_reset_27_clk_phase_reg                                     0xB8032048
#define  IFD_108_soft_reset_27_clk_phase_inst_addr                               "0x0011"
#define  set_IFD_108_soft_reset_27_clk_phase_reg(data)                           (*((volatile unsigned int*)IFD_108_soft_reset_27_clk_phase_reg)=data)
#define  get_IFD_108_soft_reset_27_clk_phase_reg                                 (*((volatile unsigned int*)IFD_108_soft_reset_27_clk_phase_reg))
#define  IFD_108_soft_reset_27_clk_phase_soft_reset_shift                        (0)
#define  IFD_108_soft_reset_27_clk_phase_soft_reset_mask                         (0x00000001)
#define  IFD_108_soft_reset_27_clk_phase_soft_reset(data)                        (0x00000001&(data))
#define  IFD_108_soft_reset_27_clk_phase_get_soft_reset(data)                    (0x00000001&(data))

#define  IFD_108_dma                                                             0x1803204C
#define  IFD_108_dma_reg_addr                                                    "0xB803204C"
#define  IFD_108_dma_reg                                                         0xB803204C
#define  IFD_108_dma_inst_addr                                                   "0x0012"
#define  set_IFD_108_dma_reg(data)                                               (*((volatile unsigned int*)IFD_108_dma_reg)=data)
#define  get_IFD_108_dma_reg                                                     (*((volatile unsigned int*)IFD_108_dma_reg))
#define  IFD_108_dma_dma_fifo_debug_full_shift                                   (7)
#define  IFD_108_dma_dma_fifo_debug_empty_shift                                  (6)
#define  IFD_108_dma_dma_fifo_adc_full_shift                                     (5)
#define  IFD_108_dma_dma_fifo_adc_empty_shift                                    (4)
#define  IFD_108_dma_dma_fifo_debug_full_mask                                    (0x00000080)
#define  IFD_108_dma_dma_fifo_debug_empty_mask                                   (0x00000040)
#define  IFD_108_dma_dma_fifo_adc_full_mask                                      (0x00000020)
#define  IFD_108_dma_dma_fifo_adc_empty_mask                                     (0x00000010)
#define  IFD_108_dma_dma_fifo_debug_full(data)                                   (0x00000080&((data)<<7))
#define  IFD_108_dma_dma_fifo_debug_empty(data)                                  (0x00000040&((data)<<6))
#define  IFD_108_dma_dma_fifo_adc_full(data)                                     (0x00000020&((data)<<5))
#define  IFD_108_dma_dma_fifo_adc_empty(data)                                    (0x00000010&((data)<<4))
#define  IFD_108_dma_get_dma_fifo_debug_full(data)                               ((0x00000080&(data))>>7)
#define  IFD_108_dma_get_dma_fifo_debug_empty(data)                              ((0x00000040&(data))>>6)
#define  IFD_108_dma_get_dma_fifo_adc_full(data)                                 ((0x00000020&(data))>>5)
#define  IFD_108_dma_get_dma_fifo_adc_empty(data)                                ((0x00000010&(data))>>4)

#define  IFD_108_cr_lock_thd                                                     0x18032050
#define  IFD_108_cr_lock_thd_reg_addr                                            "0xB8032050"
#define  IFD_108_cr_lock_thd_reg                                                 0xB8032050
#define  IFD_108_cr_lock_thd_inst_addr                                           "0x0013"
#define  set_IFD_108_cr_lock_thd_reg(data)                                       (*((volatile unsigned int*)IFD_108_cr_lock_thd_reg)=data)
#define  get_IFD_108_cr_lock_thd_reg                                             (*((volatile unsigned int*)IFD_108_cr_lock_thd_reg))
#define  IFD_108_cr_lock_thd_cr_lock_thd_shift                                   (16)
#define  IFD_108_cr_lock_thd_cr_lock_len_shift                                   (8)
#define  IFD_108_cr_lock_thd_cr_cnt_thd_shift                                    (0)
#define  IFD_108_cr_lock_thd_cr_lock_thd_mask                                    (0x00FF0000)
#define  IFD_108_cr_lock_thd_cr_lock_len_mask                                    (0x0000FF00)
#define  IFD_108_cr_lock_thd_cr_cnt_thd_mask                                     (0x000000FF)
#define  IFD_108_cr_lock_thd_cr_lock_thd(data)                                   (0x00FF0000&((data)<<16))
#define  IFD_108_cr_lock_thd_cr_lock_len(data)                                   (0x0000FF00&((data)<<8))
#define  IFD_108_cr_lock_thd_cr_cnt_thd(data)                                    (0x000000FF&(data))
#define  IFD_108_cr_lock_thd_get_cr_lock_thd(data)                               ((0x00FF0000&(data))>>16)
#define  IFD_108_cr_lock_thd_get_cr_lock_len(data)                               ((0x0000FF00&(data))>>8)
#define  IFD_108_cr_lock_thd_get_cr_cnt_thd(data)                                (0x000000FF&(data))

#define  IFD_108_cr_auto_reset_en                                                0x18032054
#define  IFD_108_cr_auto_reset_en_reg_addr                                       "0xB8032054"
#define  IFD_108_cr_auto_reset_en_reg                                            0xB8032054
#define  IFD_108_cr_auto_reset_en_inst_addr                                      "0x0014"
#define  set_IFD_108_cr_auto_reset_en_reg(data)                                  (*((volatile unsigned int*)IFD_108_cr_auto_reset_en_reg)=data)
#define  get_IFD_108_cr_auto_reset_en_reg                                        (*((volatile unsigned int*)IFD_108_cr_auto_reset_en_reg))
#define  IFD_108_cr_auto_reset_en_cr_nco_offset_shift                            (16)
#define  IFD_108_cr_auto_reset_en_cr_sin_trunc_len_shift                         (12)
#define  IFD_108_cr_auto_reset_en_cr_track_len_shift                             (8)
#define  IFD_108_cr_auto_reset_en_cr_unlock_track_en_shift                       (4)
#define  IFD_108_cr_auto_reset_en_cr_reset_track_en_shift                        (3)
#define  IFD_108_cr_auto_reset_en_cr_nco_track_sel_shift                         (2)
#define  IFD_108_cr_auto_reset_en_cr_auto_reset_en_shift                         (0)
#define  IFD_108_cr_auto_reset_en_cr_nco_offset_mask                             (0xFFFF0000)
#define  IFD_108_cr_auto_reset_en_cr_sin_trunc_len_mask                          (0x00003000)
#define  IFD_108_cr_auto_reset_en_cr_track_len_mask                              (0x00000F00)
#define  IFD_108_cr_auto_reset_en_cr_unlock_track_en_mask                        (0x00000010)
#define  IFD_108_cr_auto_reset_en_cr_reset_track_en_mask                         (0x00000008)
#define  IFD_108_cr_auto_reset_en_cr_nco_track_sel_mask                          (0x00000004)
#define  IFD_108_cr_auto_reset_en_cr_auto_reset_en_mask                          (0x00000001)
#define  IFD_108_cr_auto_reset_en_cr_nco_offset(data)                            (0xFFFF0000&((data)<<16))
#define  IFD_108_cr_auto_reset_en_cr_sin_trunc_len(data)                         (0x00003000&((data)<<12))
#define  IFD_108_cr_auto_reset_en_cr_track_len(data)                             (0x00000F00&((data)<<8))
#define  IFD_108_cr_auto_reset_en_cr_unlock_track_en(data)                       (0x00000010&((data)<<4))
#define  IFD_108_cr_auto_reset_en_cr_reset_track_en(data)                        (0x00000008&((data)<<3))
#define  IFD_108_cr_auto_reset_en_cr_nco_track_sel(data)                         (0x00000004&((data)<<2))
#define  IFD_108_cr_auto_reset_en_cr_auto_reset_en(data)                         (0x00000001&(data))
#define  IFD_108_cr_auto_reset_en_get_cr_nco_offset(data)                        ((0xFFFF0000&(data))>>16)
#define  IFD_108_cr_auto_reset_en_get_cr_sin_trunc_len(data)                     ((0x00003000&(data))>>12)
#define  IFD_108_cr_auto_reset_en_get_cr_track_len(data)                         ((0x00000F00&(data))>>8)
#define  IFD_108_cr_auto_reset_en_get_cr_unlock_track_en(data)                   ((0x00000010&(data))>>4)
#define  IFD_108_cr_auto_reset_en_get_cr_reset_track_en(data)                    ((0x00000008&(data))>>3)
#define  IFD_108_cr_auto_reset_en_get_cr_nco_track_sel(data)                     ((0x00000004&(data))>>2)
#define  IFD_108_cr_auto_reset_en_get_cr_auto_reset_en(data)                     (0x00000001&(data))

#define  IFD_108_cr_phase_inverse                                                0x18032058
#define  IFD_108_cr_phase_inverse_reg_addr                                       "0xB8032058"
#define  IFD_108_cr_phase_inverse_reg                                            0xB8032058
#define  IFD_108_cr_phase_inverse_inst_addr                                      "0x0015"
#define  set_IFD_108_cr_phase_inverse_reg(data)                                  (*((volatile unsigned int*)IFD_108_cr_phase_inverse_reg)=data)
#define  get_IFD_108_cr_phase_inverse_reg                                        (*((volatile unsigned int*)IFD_108_cr_phase_inverse_reg))
#define  IFD_108_cr_phase_inverse_cr_phase_inverse_en_st4_shift                  (26)
#define  IFD_108_cr_phase_inverse_cr_phase_inverse_en_st2_shift                  (25)
#define  IFD_108_cr_phase_inverse_cr_phase_inverse_en_st0_shift                  (24)
#define  IFD_108_cr_phase_inverse_cr_phase_inverse_thr_shift                     (8)
#define  IFD_108_cr_phase_inverse_cr_cordic_phase_modify_en_shift                (4)
#define  IFD_108_cr_phase_inverse_cr_phase_inverse_fine_lock_dis_shift           (2)
#define  IFD_108_cr_phase_inverse_cr_phase_inverse_cr_lock_dis_shift             (1)
#define  IFD_108_cr_phase_inverse_cr_phase_inverse_en_shift                      (0)
#define  IFD_108_cr_phase_inverse_cr_phase_inverse_en_st4_mask                   (0x04000000)
#define  IFD_108_cr_phase_inverse_cr_phase_inverse_en_st2_mask                   (0x02000000)
#define  IFD_108_cr_phase_inverse_cr_phase_inverse_en_st0_mask                   (0x01000000)
#define  IFD_108_cr_phase_inverse_cr_phase_inverse_thr_mask                      (0x007FFF00)
#define  IFD_108_cr_phase_inverse_cr_cordic_phase_modify_en_mask                 (0x00000010)
#define  IFD_108_cr_phase_inverse_cr_phase_inverse_fine_lock_dis_mask            (0x00000004)
#define  IFD_108_cr_phase_inverse_cr_phase_inverse_cr_lock_dis_mask              (0x00000002)
#define  IFD_108_cr_phase_inverse_cr_phase_inverse_en_mask                       (0x00000001)
#define  IFD_108_cr_phase_inverse_cr_phase_inverse_en_st4(data)                  (0x04000000&((data)<<26))
#define  IFD_108_cr_phase_inverse_cr_phase_inverse_en_st2(data)                  (0x02000000&((data)<<25))
#define  IFD_108_cr_phase_inverse_cr_phase_inverse_en_st0(data)                  (0x01000000&((data)<<24))
#define  IFD_108_cr_phase_inverse_cr_phase_inverse_thr(data)                     (0x007FFF00&((data)<<8))
#define  IFD_108_cr_phase_inverse_cr_cordic_phase_modify_en(data)                (0x00000010&((data)<<4))
#define  IFD_108_cr_phase_inverse_cr_phase_inverse_fine_lock_dis(data)           (0x00000004&((data)<<2))
#define  IFD_108_cr_phase_inverse_cr_phase_inverse_cr_lock_dis(data)             (0x00000002&((data)<<1))
#define  IFD_108_cr_phase_inverse_cr_phase_inverse_en(data)                      (0x00000001&(data))
#define  IFD_108_cr_phase_inverse_get_cr_phase_inverse_en_st4(data)              ((0x04000000&(data))>>26)
#define  IFD_108_cr_phase_inverse_get_cr_phase_inverse_en_st2(data)              ((0x02000000&(data))>>25)
#define  IFD_108_cr_phase_inverse_get_cr_phase_inverse_en_st0(data)              ((0x01000000&(data))>>24)
#define  IFD_108_cr_phase_inverse_get_cr_phase_inverse_thr(data)                 ((0x007FFF00&(data))>>8)
#define  IFD_108_cr_phase_inverse_get_cr_cordic_phase_modify_en(data)            ((0x00000010&(data))>>4)
#define  IFD_108_cr_phase_inverse_get_cr_phase_inverse_fine_lock_dis(data)       ((0x00000004&(data))>>2)
#define  IFD_108_cr_phase_inverse_get_cr_phase_inverse_cr_lock_dis(data)         ((0x00000002&(data))>>1)
#define  IFD_108_cr_phase_inverse_get_cr_phase_inverse_en(data)                  (0x00000001&(data))

#define  IFD_108_cr_track_status                                                 0x1803205C
#define  IFD_108_cr_track_status_reg_addr                                        "0xB803205C"
#define  IFD_108_cr_track_status_reg                                             0xB803205C
#define  IFD_108_cr_track_status_inst_addr                                       "0x0016"
#define  set_IFD_108_cr_track_status_reg(data)                                   (*((volatile unsigned int*)IFD_108_cr_track_status_reg)=data)
#define  get_IFD_108_cr_track_status_reg                                         (*((volatile unsigned int*)IFD_108_cr_track_status_reg))
#define  IFD_108_cr_track_status_cr_auto_reset_len_shift                         (20)
#define  IFD_108_cr_track_status_cr_track_nco_shift                              (0)
#define  IFD_108_cr_track_status_cr_auto_reset_len_mask                          (0x01F00000)
#define  IFD_108_cr_track_status_cr_track_nco_mask                               (0x000FFFFF)
#define  IFD_108_cr_track_status_cr_auto_reset_len(data)                         (0x01F00000&((data)<<20))
#define  IFD_108_cr_track_status_cr_track_nco(data)                              (0x000FFFFF&(data))
#define  IFD_108_cr_track_status_get_cr_auto_reset_len(data)                     ((0x01F00000&(data))>>20)
#define  IFD_108_cr_track_status_get_cr_track_nco(data)                          (0x000FFFFF&(data))

#define  IFD_108_cr_shift_en                                                     0x18032060
#define  IFD_108_cr_shift_en_reg_addr                                            "0xB8032060"
#define  IFD_108_cr_shift_en_reg                                                 0xB8032060
#define  IFD_108_cr_shift_en_inst_addr                                           "0x0017"
#define  set_IFD_108_cr_shift_en_reg(data)                                       (*((volatile unsigned int*)IFD_108_cr_shift_en_reg)=data)
#define  get_IFD_108_cr_shift_en_reg                                             (*((volatile unsigned int*)IFD_108_cr_shift_en_reg))
#define  IFD_108_cr_shift_en_cr_fm_en_shift                                      (28)
#define  IFD_108_cr_shift_en_cr_shift_en_shift                                   (24)
#define  IFD_108_cr_shift_en_cr_shift_polar_shift                                (20)
#define  IFD_108_cr_shift_en_cr_shift_nco_offset_shift                           (0)
#define  IFD_108_cr_shift_en_cr_fm_en_mask                                       (0x10000000)
#define  IFD_108_cr_shift_en_cr_shift_en_mask                                    (0x01000000)
#define  IFD_108_cr_shift_en_cr_shift_polar_mask                                 (0x00100000)
#define  IFD_108_cr_shift_en_cr_shift_nco_offset_mask                            (0x000FFFFF)
#define  IFD_108_cr_shift_en_cr_fm_en(data)                                      (0x10000000&((data)<<28))
#define  IFD_108_cr_shift_en_cr_shift_en(data)                                   (0x01000000&((data)<<24))
#define  IFD_108_cr_shift_en_cr_shift_polar(data)                                (0x00100000&((data)<<20))
#define  IFD_108_cr_shift_en_cr_shift_nco_offset(data)                           (0x000FFFFF&(data))
#define  IFD_108_cr_shift_en_get_cr_fm_en(data)                                  ((0x10000000&(data))>>28)
#define  IFD_108_cr_shift_en_get_cr_shift_en(data)                               ((0x01000000&(data))>>24)
#define  IFD_108_cr_shift_en_get_cr_shift_polar(data)                            ((0x00100000&(data))>>20)
#define  IFD_108_cr_shift_en_get_cr_shift_nco_offset(data)                       (0x000FFFFF&(data))

#define  IFD_108_cr_data_gain_en                                                 0x18032064
#define  IFD_108_cr_data_gain_en_reg_addr                                        "0xB8032064"
#define  IFD_108_cr_data_gain_en_reg                                             0xB8032064
#define  IFD_108_cr_data_gain_en_inst_addr                                       "0x0018"
#define  set_IFD_108_cr_data_gain_en_reg(data)                                   (*((volatile unsigned int*)IFD_108_cr_data_gain_en_reg)=data)
#define  get_IFD_108_cr_data_gain_en_reg                                         (*((volatile unsigned int*)IFD_108_cr_data_gain_en_reg))
#define  IFD_108_cr_data_gain_en_cr_less_delay_shift                             (4)
#define  IFD_108_cr_data_gain_en_cr_data_gain_en_shift                           (0)
#define  IFD_108_cr_data_gain_en_cr_less_delay_mask                              (0x00000010)
#define  IFD_108_cr_data_gain_en_cr_data_gain_en_mask                            (0x00000001)
#define  IFD_108_cr_data_gain_en_cr_less_delay(data)                             (0x00000010&((data)<<4))
#define  IFD_108_cr_data_gain_en_cr_data_gain_en(data)                           (0x00000001&(data))
#define  IFD_108_cr_data_gain_en_get_cr_less_delay(data)                         ((0x00000010&(data))>>4)
#define  IFD_108_cr_data_gain_en_get_cr_data_gain_en(data)                       (0x00000001&(data))

#define  IFD_108_cr_phase_error_sel                                              0x18032068
#define  IFD_108_cr_phase_error_sel_reg_addr                                     "0xB8032068"
#define  IFD_108_cr_phase_error_sel_reg                                          0xB8032068
#define  IFD_108_cr_phase_error_sel_inst_addr                                    "0x0019"
#define  set_IFD_108_cr_phase_error_sel_reg(data)                                (*((volatile unsigned int*)IFD_108_cr_phase_error_sel_reg)=data)
#define  get_IFD_108_cr_phase_error_sel_reg                                      (*((volatile unsigned int*)IFD_108_cr_phase_error_sel_reg))
#define  IFD_108_cr_phase_error_sel_cr_phase_error_sel_shift                     (0)
#define  IFD_108_cr_phase_error_sel_cr_phase_error_sel_mask                      (0x00000003)
#define  IFD_108_cr_phase_error_sel_cr_phase_error_sel(data)                     (0x00000003&(data))
#define  IFD_108_cr_phase_error_sel_get_cr_phase_error_sel(data)                 (0x00000003&(data))

#define  IFD_108_cr_bpf_mask_en                                                  0x18032070
#define  IFD_108_cr_bpf_mask_en_reg_addr                                         "0xB8032070"
#define  IFD_108_cr_bpf_mask_en_reg                                              0xB8032070
#define  IFD_108_cr_bpf_mask_en_inst_addr                                        "0x001A"
#define  set_IFD_108_cr_bpf_mask_en_reg(data)                                    (*((volatile unsigned int*)IFD_108_cr_bpf_mask_en_reg)=data)
#define  get_IFD_108_cr_bpf_mask_en_reg                                          (*((volatile unsigned int*)IFD_108_cr_bpf_mask_en_reg))
#define  IFD_108_cr_bpf_mask_en_cr_bpf_mask_en_shift                             (0)
#define  IFD_108_cr_bpf_mask_en_cr_bpf_mask_en_mask                              (0x00000001)
#define  IFD_108_cr_bpf_mask_en_cr_bpf_mask_en(data)                             (0x00000001&(data))
#define  IFD_108_cr_bpf_mask_en_get_cr_bpf_mask_en(data)                         (0x00000001&(data))

#define  IFD_108_cr_bpf_mask_thr                                                 0x18032074
#define  IFD_108_cr_bpf_mask_thr_reg_addr                                        "0xB8032074"
#define  IFD_108_cr_bpf_mask_thr_reg                                             0xB8032074
#define  IFD_108_cr_bpf_mask_thr_inst_addr                                       "0x001B"
#define  set_IFD_108_cr_bpf_mask_thr_reg(data)                                   (*((volatile unsigned int*)IFD_108_cr_bpf_mask_thr_reg)=data)
#define  get_IFD_108_cr_bpf_mask_thr_reg                                         (*((volatile unsigned int*)IFD_108_cr_bpf_mask_thr_reg))
#define  IFD_108_cr_bpf_mask_thr_cr_bpf_mask_out_thr_shift                       (16)
#define  IFD_108_cr_bpf_mask_thr_cr_bpf_mask_in_thr_shift                        (0)
#define  IFD_108_cr_bpf_mask_thr_cr_bpf_mask_out_thr_mask                        (0xFFFF0000)
#define  IFD_108_cr_bpf_mask_thr_cr_bpf_mask_in_thr_mask                         (0x0000FFFF)
#define  IFD_108_cr_bpf_mask_thr_cr_bpf_mask_out_thr(data)                       (0xFFFF0000&((data)<<16))
#define  IFD_108_cr_bpf_mask_thr_cr_bpf_mask_in_thr(data)                        (0x0000FFFF&(data))
#define  IFD_108_cr_bpf_mask_thr_get_cr_bpf_mask_out_thr(data)                   ((0xFFFF0000&(data))>>16)
#define  IFD_108_cr_bpf_mask_thr_get_cr_bpf_mask_in_thr(data)                    (0x0000FFFF&(data))

#define  IFD_108_data_gain_mask_thr                                              0x18032078
#define  IFD_108_data_gain_mask_thr_reg_addr                                     "0xB8032078"
#define  IFD_108_data_gain_mask_thr_reg                                          0xB8032078
#define  IFD_108_data_gain_mask_thr_inst_addr                                    "0x001C"
#define  set_IFD_108_data_gain_mask_thr_reg(data)                                (*((volatile unsigned int*)IFD_108_data_gain_mask_thr_reg)=data)
#define  get_IFD_108_data_gain_mask_thr_reg                                      (*((volatile unsigned int*)IFD_108_data_gain_mask_thr_reg))
#define  IFD_108_data_gain_mask_thr_data_gain_mask_out_thr_shift                 (16)
#define  IFD_108_data_gain_mask_thr_data_gain_mask_in_thr_shift                  (0)
#define  IFD_108_data_gain_mask_thr_data_gain_mask_out_thr_mask                  (0xFFFF0000)
#define  IFD_108_data_gain_mask_thr_data_gain_mask_in_thr_mask                   (0x0000FFFF)
#define  IFD_108_data_gain_mask_thr_data_gain_mask_out_thr(data)                 (0xFFFF0000&((data)<<16))
#define  IFD_108_data_gain_mask_thr_data_gain_mask_in_thr(data)                  (0x0000FFFF&(data))
#define  IFD_108_data_gain_mask_thr_get_data_gain_mask_out_thr(data)             ((0xFFFF0000&(data))>>16)
#define  IFD_108_data_gain_mask_thr_get_data_gain_mask_in_thr(data)              (0x0000FFFF&(data))

#define  IFD_108_decimation_filter_enable                                        0x18032080
#define  IFD_108_decimation_filter_enable_reg_addr                               "0xB8032080"
#define  IFD_108_decimation_filter_enable_reg                                    0xB8032080
#define  IFD_108_decimation_filter_enable_inst_addr                              "0x001D"
#define  set_IFD_108_decimation_filter_enable_reg(data)                          (*((volatile unsigned int*)IFD_108_decimation_filter_enable_reg)=data)
#define  get_IFD_108_decimation_filter_enable_reg                                (*((volatile unsigned int*)IFD_108_decimation_filter_enable_reg))
#define  IFD_108_decimation_filter_enable_decimation_en_shift                    (20)
#define  IFD_108_decimation_filter_enable_decimation_en_mask                     (0x00100000)
#define  IFD_108_decimation_filter_enable_decimation_en(data)                    (0x00100000&((data)<<20))
#define  IFD_108_decimation_filter_enable_get_decimation_en(data)                ((0x00100000&(data))>>20)

#define  IFD_108_output_lpf_vsync_start                                          0x18032084
#define  IFD_108_output_lpf_vsync_start_reg_addr                                 "0xB8032084"
#define  IFD_108_output_lpf_vsync_start_reg                                      0xB8032084
#define  IFD_108_output_lpf_vsync_start_inst_addr                                "0x001E"
#define  set_IFD_108_output_lpf_vsync_start_reg(data)                            (*((volatile unsigned int*)IFD_108_output_lpf_vsync_start_reg)=data)
#define  get_IFD_108_output_lpf_vsync_start_reg                                  (*((volatile unsigned int*)IFD_108_output_lpf_vsync_start_reg))
#define  IFD_108_output_lpf_vsync_start_lpf_vsync_start_shift                    (16)
#define  IFD_108_output_lpf_vsync_start_lpf_vsync_end_shift                      (0)
#define  IFD_108_output_lpf_vsync_start_lpf_vsync_start_mask                     (0xFFFF0000)
#define  IFD_108_output_lpf_vsync_start_lpf_vsync_end_mask                       (0x0000FFFF)
#define  IFD_108_output_lpf_vsync_start_lpf_vsync_start(data)                    (0xFFFF0000&((data)<<16))
#define  IFD_108_output_lpf_vsync_start_lpf_vsync_end(data)                      (0x0000FFFF&(data))
#define  IFD_108_output_lpf_vsync_start_get_lpf_vsync_start(data)                ((0xFFFF0000&(data))>>16)
#define  IFD_108_output_lpf_vsync_start_get_lpf_vsync_end(data)                  (0x0000FFFF&(data))

#define  IFD_108_resampler_status                                                0x1803208C
#define  IFD_108_resampler_status_reg_addr                                       "0xB803208C"
#define  IFD_108_resampler_status_reg                                            0xB803208C
#define  IFD_108_resampler_status_inst_addr                                      "0x001F"
#define  set_IFD_108_resampler_status_reg(data)                                  (*((volatile unsigned int*)IFD_108_resampler_status_reg)=data)
#define  get_IFD_108_resampler_status_reg                                        (*((volatile unsigned int*)IFD_108_resampler_status_reg))
#define  IFD_108_resampler_status_fifo_full_clear_shift                          (5)
#define  IFD_108_resampler_status_fifo_empty_clear_shift                         (4)
#define  IFD_108_resampler_status_fifo_full_shift                                (1)
#define  IFD_108_resampler_status_fifo_empty_shift                               (0)
#define  IFD_108_resampler_status_fifo_full_clear_mask                           (0x00000020)
#define  IFD_108_resampler_status_fifo_empty_clear_mask                          (0x00000010)
#define  IFD_108_resampler_status_fifo_full_mask                                 (0x00000002)
#define  IFD_108_resampler_status_fifo_empty_mask                                (0x00000001)
#define  IFD_108_resampler_status_fifo_full_clear(data)                          (0x00000020&((data)<<5))
#define  IFD_108_resampler_status_fifo_empty_clear(data)                         (0x00000010&((data)<<4))
#define  IFD_108_resampler_status_fifo_full(data)                                (0x00000002&((data)<<1))
#define  IFD_108_resampler_status_fifo_empty(data)                               (0x00000001&(data))
#define  IFD_108_resampler_status_get_fifo_full_clear(data)                      ((0x00000020&(data))>>5)
#define  IFD_108_resampler_status_get_fifo_empty_clear(data)                     ((0x00000010&(data))>>4)
#define  IFD_108_resampler_status_get_fifo_full(data)                            ((0x00000002&(data))>>1)
#define  IFD_108_resampler_status_get_fifo_empty(data)                           (0x00000001&(data))

#define  IFD_108_cr_phase_error_avg_set                                          0x18032090
#define  IFD_108_cr_phase_error_avg_set_reg_addr                                 "0xB8032090"
#define  IFD_108_cr_phase_error_avg_set_reg                                      0xB8032090
#define  IFD_108_cr_phase_error_avg_set_inst_addr                                "0x0020"
#define  set_IFD_108_cr_phase_error_avg_set_reg(data)                            (*((volatile unsigned int*)IFD_108_cr_phase_error_avg_set_reg)=data)
#define  get_IFD_108_cr_phase_error_avg_set_reg                                  (*((volatile unsigned int*)IFD_108_cr_phase_error_avg_set_reg))
#define  IFD_108_cr_phase_error_avg_set_cr_phase_error_avg_src_shift             (24)
#define  IFD_108_cr_phase_error_avg_set_cr_phase_error_avg_vcatch_shift          (20)
#define  IFD_108_cr_phase_error_avg_set_cr_phase_error_avg_interval_shift        (8)
#define  IFD_108_cr_phase_error_avg_set_cr_phase_error_avg_length_shift          (4)
#define  IFD_108_cr_phase_error_avg_set_cr_phase_error_avg_linebase_shift        (0)
#define  IFD_108_cr_phase_error_avg_set_cr_phase_error_avg_src_mask              (0x01000000)
#define  IFD_108_cr_phase_error_avg_set_cr_phase_error_avg_vcatch_mask           (0x00100000)
#define  IFD_108_cr_phase_error_avg_set_cr_phase_error_avg_interval_mask         (0x000FFF00)
#define  IFD_108_cr_phase_error_avg_set_cr_phase_error_avg_length_mask           (0x00000070)
#define  IFD_108_cr_phase_error_avg_set_cr_phase_error_avg_linebase_mask         (0x00000001)
#define  IFD_108_cr_phase_error_avg_set_cr_phase_error_avg_src(data)             (0x01000000&((data)<<24))
#define  IFD_108_cr_phase_error_avg_set_cr_phase_error_avg_vcatch(data)          (0x00100000&((data)<<20))
#define  IFD_108_cr_phase_error_avg_set_cr_phase_error_avg_interval(data)        (0x000FFF00&((data)<<8))
#define  IFD_108_cr_phase_error_avg_set_cr_phase_error_avg_length(data)          (0x00000070&((data)<<4))
#define  IFD_108_cr_phase_error_avg_set_cr_phase_error_avg_linebase(data)        (0x00000001&(data))
#define  IFD_108_cr_phase_error_avg_set_get_cr_phase_error_avg_src(data)         ((0x01000000&(data))>>24)
#define  IFD_108_cr_phase_error_avg_set_get_cr_phase_error_avg_vcatch(data)      ((0x00100000&(data))>>20)
#define  IFD_108_cr_phase_error_avg_set_get_cr_phase_error_avg_interval(data)    ((0x000FFF00&(data))>>8)
#define  IFD_108_cr_phase_error_avg_set_get_cr_phase_error_avg_length(data)      ((0x00000070&(data))>>4)
#define  IFD_108_cr_phase_error_avg_set_get_cr_phase_error_avg_linebase(data)    (0x00000001&(data))

#define  IFD_108_cr_phase_error_avg_status                                       0x18032094
#define  IFD_108_cr_phase_error_avg_status_reg_addr                              "0xB8032094"
#define  IFD_108_cr_phase_error_avg_status_reg                                   0xB8032094
#define  IFD_108_cr_phase_error_avg_status_inst_addr                             "0x0021"
#define  set_IFD_108_cr_phase_error_avg_status_reg(data)                         (*((volatile unsigned int*)IFD_108_cr_phase_error_avg_status_reg)=data)
#define  get_IFD_108_cr_phase_error_avg_status_reg                               (*((volatile unsigned int*)IFD_108_cr_phase_error_avg_status_reg))
#define  IFD_108_cr_phase_error_avg_status_cr_phase_error_mean_shift             (12)
#define  IFD_108_cr_phase_error_avg_status_cr_phase_error_var_shift              (0)
#define  IFD_108_cr_phase_error_avg_status_cr_phase_error_mean_mask              (0x00FFF000)
#define  IFD_108_cr_phase_error_avg_status_cr_phase_error_var_mask               (0x00000FFF)
#define  IFD_108_cr_phase_error_avg_status_cr_phase_error_mean(data)             (0x00FFF000&((data)<<12))
#define  IFD_108_cr_phase_error_avg_status_cr_phase_error_var(data)              (0x00000FFF&(data))
#define  IFD_108_cr_phase_error_avg_status_get_cr_phase_error_mean(data)         ((0x00FFF000&(data))>>12)
#define  IFD_108_cr_phase_error_avg_status_get_cr_phase_error_var(data)          (0x00000FFF&(data))

#define  IFD_108_cr_freq_error_avg_set                                           0x180320A0
#define  IFD_108_cr_freq_error_avg_set_reg_addr                                  "0xB80320A0"
#define  IFD_108_cr_freq_error_avg_set_reg                                       0xB80320A0
#define  IFD_108_cr_freq_error_avg_set_inst_addr                                 "0x0022"
#define  set_IFD_108_cr_freq_error_avg_set_reg(data)                             (*((volatile unsigned int*)IFD_108_cr_freq_error_avg_set_reg)=data)
#define  get_IFD_108_cr_freq_error_avg_set_reg                                   (*((volatile unsigned int*)IFD_108_cr_freq_error_avg_set_reg))
#define  IFD_108_cr_freq_error_avg_set_cr_freq_error_avg_vinterval_shift         (21)
#define  IFD_108_cr_freq_error_avg_set_cr_freq_error_avg_vcatch_shift            (20)
#define  IFD_108_cr_freq_error_avg_set_cr_freq_error_avg_interval_shift          (8)
#define  IFD_108_cr_freq_error_avg_set_cr_freq_error_avg_length_shift            (4)
#define  IFD_108_cr_freq_error_avg_set_cr_freq_error_avg_linebase_shift          (0)
#define  IFD_108_cr_freq_error_avg_set_cr_freq_error_avg_vinterval_mask          (0xFFE00000)
#define  IFD_108_cr_freq_error_avg_set_cr_freq_error_avg_vcatch_mask             (0x00100000)
#define  IFD_108_cr_freq_error_avg_set_cr_freq_error_avg_interval_mask           (0x000FFF00)
#define  IFD_108_cr_freq_error_avg_set_cr_freq_error_avg_length_mask             (0x00000070)
#define  IFD_108_cr_freq_error_avg_set_cr_freq_error_avg_linebase_mask           (0x00000001)
#define  IFD_108_cr_freq_error_avg_set_cr_freq_error_avg_vinterval(data)         (0xFFE00000&((data)<<21))
#define  IFD_108_cr_freq_error_avg_set_cr_freq_error_avg_vcatch(data)            (0x00100000&((data)<<20))
#define  IFD_108_cr_freq_error_avg_set_cr_freq_error_avg_interval(data)          (0x000FFF00&((data)<<8))
#define  IFD_108_cr_freq_error_avg_set_cr_freq_error_avg_length(data)            (0x00000070&((data)<<4))
#define  IFD_108_cr_freq_error_avg_set_cr_freq_error_avg_linebase(data)          (0x00000001&(data))
#define  IFD_108_cr_freq_error_avg_set_get_cr_freq_error_avg_vinterval(data)     ((0xFFE00000&(data))>>21)
#define  IFD_108_cr_freq_error_avg_set_get_cr_freq_error_avg_vcatch(data)        ((0x00100000&(data))>>20)
#define  IFD_108_cr_freq_error_avg_set_get_cr_freq_error_avg_interval(data)      ((0x000FFF00&(data))>>8)
#define  IFD_108_cr_freq_error_avg_set_get_cr_freq_error_avg_length(data)        ((0x00000070&(data))>>4)
#define  IFD_108_cr_freq_error_avg_set_get_cr_freq_error_avg_linebase(data)      (0x00000001&(data))

#define  IFD_108_cr_freq_error_avg_status                                        0x180320A4
#define  IFD_108_cr_freq_error_avg_status_reg_addr                               "0xB80320A4"
#define  IFD_108_cr_freq_error_avg_status_reg                                    0xB80320A4
#define  IFD_108_cr_freq_error_avg_status_inst_addr                              "0x0023"
#define  set_IFD_108_cr_freq_error_avg_status_reg(data)                          (*((volatile unsigned int*)IFD_108_cr_freq_error_avg_status_reg)=data)
#define  get_IFD_108_cr_freq_error_avg_status_reg                                (*((volatile unsigned int*)IFD_108_cr_freq_error_avg_status_reg))
#define  IFD_108_cr_freq_error_avg_status_cr_freq_error_mean_shift               (16)
#define  IFD_108_cr_freq_error_avg_status_cr_freq_error_var_shift                (0)
#define  IFD_108_cr_freq_error_avg_status_cr_freq_error_mean_mask                (0xFFFF0000)
#define  IFD_108_cr_freq_error_avg_status_cr_freq_error_var_mask                 (0x0000FFFF)
#define  IFD_108_cr_freq_error_avg_status_cr_freq_error_mean(data)               (0xFFFF0000&((data)<<16))
#define  IFD_108_cr_freq_error_avg_status_cr_freq_error_var(data)                (0x0000FFFF&(data))
#define  IFD_108_cr_freq_error_avg_status_get_cr_freq_error_mean(data)           ((0xFFFF0000&(data))>>16)
#define  IFD_108_cr_freq_error_avg_status_get_cr_freq_error_var(data)            (0x0000FFFF&(data))

#define  IFD_108_cr_vsync_start                                                  0x180320A8
#define  IFD_108_cr_vsync_start_reg_addr                                         "0xB80320A8"
#define  IFD_108_cr_vsync_start_reg                                              0xB80320A8
#define  IFD_108_cr_vsync_start_inst_addr                                        "0x0024"
#define  set_IFD_108_cr_vsync_start_reg(data)                                    (*((volatile unsigned int*)IFD_108_cr_vsync_start_reg)=data)
#define  get_IFD_108_cr_vsync_start_reg                                          (*((volatile unsigned int*)IFD_108_cr_vsync_start_reg))
#define  IFD_108_cr_vsync_start_cr_vsync_start_shift                             (16)
#define  IFD_108_cr_vsync_start_cr_vsync_end_shift                               (0)
#define  IFD_108_cr_vsync_start_cr_vsync_start_mask                              (0xFFFF0000)
#define  IFD_108_cr_vsync_start_cr_vsync_end_mask                                (0x0000FFFF)
#define  IFD_108_cr_vsync_start_cr_vsync_start(data)                             (0xFFFF0000&((data)<<16))
#define  IFD_108_cr_vsync_start_cr_vsync_end(data)                               (0x0000FFFF&(data))
#define  IFD_108_cr_vsync_start_get_cr_vsync_start(data)                         ((0xFFFF0000&(data))>>16)
#define  IFD_108_cr_vsync_start_get_cr_vsync_end(data)                           (0x0000FFFF&(data))

#define  IFD_108_cr_hsync_start                                                  0x180320AC
#define  IFD_108_cr_hsync_start_reg_addr                                         "0xB80320AC"
#define  IFD_108_cr_hsync_start_reg                                              0xB80320AC
#define  IFD_108_cr_hsync_start_inst_addr                                        "0x0025"
#define  set_IFD_108_cr_hsync_start_reg(data)                                    (*((volatile unsigned int*)IFD_108_cr_hsync_start_reg)=data)
#define  get_IFD_108_cr_hsync_start_reg                                          (*((volatile unsigned int*)IFD_108_cr_hsync_start_reg))
#define  IFD_108_cr_hsync_start_cr_hsync_start_shift                             (8)
#define  IFD_108_cr_hsync_start_cr_hsync_end_shift                               (0)
#define  IFD_108_cr_hsync_start_cr_hsync_start_mask                              (0x0000FF00)
#define  IFD_108_cr_hsync_start_cr_hsync_end_mask                                (0x000000FF)
#define  IFD_108_cr_hsync_start_cr_hsync_start(data)                             (0x0000FF00&((data)<<8))
#define  IFD_108_cr_hsync_start_cr_hsync_end(data)                               (0x000000FF&(data))
#define  IFD_108_cr_hsync_start_get_cr_hsync_start(data)                         ((0x0000FF00&(data))>>8)
#define  IFD_108_cr_hsync_start_get_cr_hsync_end(data)                           (0x000000FF&(data))

#define  IFD_108_mod_detect_max_cntl                                             0x180320C0
#define  IFD_108_mod_detect_max_cntl_reg_addr                                    "0xB80320C0"
#define  IFD_108_mod_detect_max_cntl_reg                                         0xB80320C0
#define  IFD_108_mod_detect_max_cntl_inst_addr                                   "0x0026"
#define  set_IFD_108_mod_detect_max_cntl_reg(data)                               (*((volatile unsigned int*)IFD_108_mod_detect_max_cntl_reg)=data)
#define  get_IFD_108_mod_detect_max_cntl_reg                                     (*((volatile unsigned int*)IFD_108_mod_detect_max_cntl_reg))
#define  IFD_108_mod_detect_max_cntl_mod_max_out_shift                           (20)
#define  IFD_108_mod_detect_max_cntl_mod_max_slow_charge_en_shift                (17)
#define  IFD_108_mod_detect_max_cntl_mod_max_slow_charge_value_shift             (12)
#define  IFD_108_mod_detect_max_cntl_mod_max_cntl_shift                          (0)
#define  IFD_108_mod_detect_max_cntl_mod_max_out_mask                            (0x7FF00000)
#define  IFD_108_mod_detect_max_cntl_mod_max_slow_charge_en_mask                 (0x00020000)
#define  IFD_108_mod_detect_max_cntl_mod_max_slow_charge_value_mask              (0x0001F000)
#define  IFD_108_mod_detect_max_cntl_mod_max_cntl_mask                           (0x00000FFF)
#define  IFD_108_mod_detect_max_cntl_mod_max_out(data)                           (0x7FF00000&((data)<<20))
#define  IFD_108_mod_detect_max_cntl_mod_max_slow_charge_en(data)                (0x00020000&((data)<<17))
#define  IFD_108_mod_detect_max_cntl_mod_max_slow_charge_value(data)             (0x0001F000&((data)<<12))
#define  IFD_108_mod_detect_max_cntl_mod_max_cntl(data)                          (0x00000FFF&(data))
#define  IFD_108_mod_detect_max_cntl_get_mod_max_out(data)                       ((0x7FF00000&(data))>>20)
#define  IFD_108_mod_detect_max_cntl_get_mod_max_slow_charge_en(data)            ((0x00020000&(data))>>17)
#define  IFD_108_mod_detect_max_cntl_get_mod_max_slow_charge_value(data)         ((0x0001F000&(data))>>12)
#define  IFD_108_mod_detect_max_cntl_get_mod_max_cntl(data)                      (0x00000FFF&(data))

#define  IFD_108_mod_detect_min_cntl                                             0x180320C4
#define  IFD_108_mod_detect_min_cntl_reg_addr                                    "0xB80320C4"
#define  IFD_108_mod_detect_min_cntl_reg                                         0xB80320C4
#define  IFD_108_mod_detect_min_cntl_inst_addr                                   "0x0027"
#define  set_IFD_108_mod_detect_min_cntl_reg(data)                               (*((volatile unsigned int*)IFD_108_mod_detect_min_cntl_reg)=data)
#define  get_IFD_108_mod_detect_min_cntl_reg                                     (*((volatile unsigned int*)IFD_108_mod_detect_min_cntl_reg))
#define  IFD_108_mod_detect_min_cntl_mod_min_out_shift                           (20)
#define  IFD_108_mod_detect_min_cntl_mod_min_slow_charge_en_shift                (17)
#define  IFD_108_mod_detect_min_cntl_mod_min_slow_charge_value_shift             (12)
#define  IFD_108_mod_detect_min_cntl_mod_min_cntl_shift                          (0)
#define  IFD_108_mod_detect_min_cntl_mod_min_out_mask                            (0x7FF00000)
#define  IFD_108_mod_detect_min_cntl_mod_min_slow_charge_en_mask                 (0x00020000)
#define  IFD_108_mod_detect_min_cntl_mod_min_slow_charge_value_mask              (0x0001F000)
#define  IFD_108_mod_detect_min_cntl_mod_min_cntl_mask                           (0x00000FFF)
#define  IFD_108_mod_detect_min_cntl_mod_min_out(data)                           (0x7FF00000&((data)<<20))
#define  IFD_108_mod_detect_min_cntl_mod_min_slow_charge_en(data)                (0x00020000&((data)<<17))
#define  IFD_108_mod_detect_min_cntl_mod_min_slow_charge_value(data)             (0x0001F000&((data)<<12))
#define  IFD_108_mod_detect_min_cntl_mod_min_cntl(data)                          (0x00000FFF&(data))
#define  IFD_108_mod_detect_min_cntl_get_mod_min_out(data)                       ((0x7FF00000&(data))>>20)
#define  IFD_108_mod_detect_min_cntl_get_mod_min_slow_charge_en(data)            ((0x00020000&(data))>>17)
#define  IFD_108_mod_detect_min_cntl_get_mod_min_slow_charge_value(data)         ((0x0001F000&(data))>>12)
#define  IFD_108_mod_detect_min_cntl_get_mod_min_cntl(data)                      (0x00000FFF&(data))

#define  IFD_108_mod_detect_update_cntl                                          0x180320C8
#define  IFD_108_mod_detect_update_cntl_reg_addr                                 "0xB80320C8"
#define  IFD_108_mod_detect_update_cntl_reg                                      0xB80320C8
#define  IFD_108_mod_detect_update_cntl_inst_addr                                "0x0028"
#define  set_IFD_108_mod_detect_update_cntl_reg(data)                            (*((volatile unsigned int*)IFD_108_mod_detect_update_cntl_reg)=data)
#define  get_IFD_108_mod_detect_update_cntl_reg                                  (*((volatile unsigned int*)IFD_108_mod_detect_update_cntl_reg))
#define  IFD_108_mod_detect_update_cntl_mod_in_sel_shift                         (20)
#define  IFD_108_mod_detect_update_cntl_mod_update_cntl_shift                    (4)
#define  IFD_108_mod_detect_update_cntl_mod_reset_shift                          (0)
#define  IFD_108_mod_detect_update_cntl_mod_in_sel_mask                          (0x00100000)
#define  IFD_108_mod_detect_update_cntl_mod_update_cntl_mask                     (0x0001FFF0)
#define  IFD_108_mod_detect_update_cntl_mod_reset_mask                           (0x00000001)
#define  IFD_108_mod_detect_update_cntl_mod_in_sel(data)                         (0x00100000&((data)<<20))
#define  IFD_108_mod_detect_update_cntl_mod_update_cntl(data)                    (0x0001FFF0&((data)<<4))
#define  IFD_108_mod_detect_update_cntl_mod_reset(data)                          (0x00000001&(data))
#define  IFD_108_mod_detect_update_cntl_get_mod_in_sel(data)                     ((0x00100000&(data))>>20)
#define  IFD_108_mod_detect_update_cntl_get_mod_update_cntl(data)                ((0x0001FFF0&(data))>>4)
#define  IFD_108_mod_detect_update_cntl_get_mod_reset(data)                      (0x00000001&(data))

#define  IFD_108_mod_detect_thr                                                  0x180320CC
#define  IFD_108_mod_detect_thr_reg_addr                                         "0xB80320CC"
#define  IFD_108_mod_detect_thr_reg                                              0xB80320CC
#define  IFD_108_mod_detect_thr_inst_addr                                        "0x0029"
#define  set_IFD_108_mod_detect_thr_reg(data)                                    (*((volatile unsigned int*)IFD_108_mod_detect_thr_reg)=data)
#define  get_IFD_108_mod_detect_thr_reg                                          (*((volatile unsigned int*)IFD_108_mod_detect_thr_reg))
#define  IFD_108_mod_detect_thr_mod_state_thr_shift                              (24)
#define  IFD_108_mod_detect_thr_neg_mod_thr_shift                                (12)
#define  IFD_108_mod_detect_thr_pos_mod_thr_shift                                (0)
#define  IFD_108_mod_detect_thr_mod_state_thr_mask                               (0x07000000)
#define  IFD_108_mod_detect_thr_neg_mod_thr_mask                                 (0x007FF000)
#define  IFD_108_mod_detect_thr_pos_mod_thr_mask                                 (0x000007FF)
#define  IFD_108_mod_detect_thr_mod_state_thr(data)                              (0x07000000&((data)<<24))
#define  IFD_108_mod_detect_thr_neg_mod_thr(data)                                (0x007FF000&((data)<<12))
#define  IFD_108_mod_detect_thr_pos_mod_thr(data)                                (0x000007FF&(data))
#define  IFD_108_mod_detect_thr_get_mod_state_thr(data)                          ((0x07000000&(data))>>24)
#define  IFD_108_mod_detect_thr_get_neg_mod_thr(data)                            ((0x007FF000&(data))>>12)
#define  IFD_108_mod_detect_thr_get_pos_mod_thr(data)                            (0x000007FF&(data))

#define  IFD_108_mod_detect_state                                                0x180320D0
#define  IFD_108_mod_detect_state_reg_addr                                       "0xB80320D0"
#define  IFD_108_mod_detect_state_reg                                            0xB80320D0
#define  IFD_108_mod_detect_state_inst_addr                                      "0x002A"
#define  set_IFD_108_mod_detect_state_reg(data)                                  (*((volatile unsigned int*)IFD_108_mod_detect_state_reg)=data)
#define  get_IFD_108_mod_detect_state_reg                                        (*((volatile unsigned int*)IFD_108_mod_detect_state_reg))
#define  IFD_108_mod_detect_state_min_diff_min_shift                             (16)
#define  IFD_108_mod_detect_state_mod_neg_cnt_shift                              (12)
#define  IFD_108_mod_detect_state_mod_pos_cnt_shift                              (8)
#define  IFD_108_mod_detect_state_uncertain_mod_cnt_shift                        (4)
#define  IFD_108_mod_detect_state_mod_state_shift                                (0)
#define  IFD_108_mod_detect_state_min_diff_min_mask                              (0x07FF0000)
#define  IFD_108_mod_detect_state_mod_neg_cnt_mask                               (0x00007000)
#define  IFD_108_mod_detect_state_mod_pos_cnt_mask                               (0x00000700)
#define  IFD_108_mod_detect_state_uncertain_mod_cnt_mask                         (0x00000070)
#define  IFD_108_mod_detect_state_mod_state_mask                                 (0x00000003)
#define  IFD_108_mod_detect_state_min_diff_min(data)                             (0x07FF0000&((data)<<16))
#define  IFD_108_mod_detect_state_mod_neg_cnt(data)                              (0x00007000&((data)<<12))
#define  IFD_108_mod_detect_state_mod_pos_cnt(data)                              (0x00000700&((data)<<8))
#define  IFD_108_mod_detect_state_uncertain_mod_cnt(data)                        (0x00000070&((data)<<4))
#define  IFD_108_mod_detect_state_mod_state(data)                                (0x00000003&(data))
#define  IFD_108_mod_detect_state_get_min_diff_min(data)                         ((0x07FF0000&(data))>>16)
#define  IFD_108_mod_detect_state_get_mod_neg_cnt(data)                          ((0x00007000&(data))>>12)
#define  IFD_108_mod_detect_state_get_mod_pos_cnt(data)                          ((0x00000700&(data))>>8)
#define  IFD_108_mod_detect_state_get_uncertain_mod_cnt(data)                    ((0x00000070&(data))>>4)
#define  IFD_108_mod_detect_state_get_mod_state(data)                            (0x00000003&(data))

#define  IFD_108_mod_detect_out                                                  0x180320D4
#define  IFD_108_mod_detect_out_reg_addr                                         "0xB80320D4"
#define  IFD_108_mod_detect_out_reg                                              0xB80320D4
#define  IFD_108_mod_detect_out_inst_addr                                        "0x002B"
#define  set_IFD_108_mod_detect_out_reg(data)                                    (*((volatile unsigned int*)IFD_108_mod_detect_out_reg)=data)
#define  get_IFD_108_mod_detect_out_reg                                          (*((volatile unsigned int*)IFD_108_mod_detect_out_reg))
#define  IFD_108_mod_detect_out_min_diff_max_shift                               (12)
#define  IFD_108_mod_detect_out_min_diff_value_shift                             (0)
#define  IFD_108_mod_detect_out_min_diff_max_mask                                (0x007FF000)
#define  IFD_108_mod_detect_out_min_diff_value_mask                              (0x00000FFF)
#define  IFD_108_mod_detect_out_min_diff_max(data)                               (0x007FF000&((data)<<12))
#define  IFD_108_mod_detect_out_min_diff_value(data)                             (0x00000FFF&(data))
#define  IFD_108_mod_detect_out_get_min_diff_max(data)                           ((0x007FF000&(data))>>12)
#define  IFD_108_mod_detect_out_get_min_diff_value(data)                         (0x00000FFF&(data))

#define  IFD_108_mod_detect_auto                                                 0x180320D8
#define  IFD_108_mod_detect_auto_reg_addr                                        "0xB80320D8"
#define  IFD_108_mod_detect_auto_reg                                             0xB80320D8
#define  IFD_108_mod_detect_auto_inst_addr                                       "0x002C"
#define  set_IFD_108_mod_detect_auto_reg(data)                                   (*((volatile unsigned int*)IFD_108_mod_detect_auto_reg)=data)
#define  get_IFD_108_mod_detect_auto_reg                                         (*((volatile unsigned int*)IFD_108_mod_detect_auto_reg))
#define  IFD_108_mod_detect_auto_mod_relate_cr_shift                             (12)
#define  IFD_108_mod_detect_auto_mod_relate_cr_thr_shift                         (8)
#define  IFD_108_mod_detect_auto_mod_once_auto_en_shift                          (4)
#define  IFD_108_mod_detect_auto_mod_auto_en_shift                               (0)
#define  IFD_108_mod_detect_auto_mod_relate_cr_mask                              (0x00001000)
#define  IFD_108_mod_detect_auto_mod_relate_cr_thr_mask                          (0x00000F00)
#define  IFD_108_mod_detect_auto_mod_once_auto_en_mask                           (0x00000010)
#define  IFD_108_mod_detect_auto_mod_auto_en_mask                                (0x00000001)
#define  IFD_108_mod_detect_auto_mod_relate_cr(data)                             (0x00001000&((data)<<12))
#define  IFD_108_mod_detect_auto_mod_relate_cr_thr(data)                         (0x00000F00&((data)<<8))
#define  IFD_108_mod_detect_auto_mod_once_auto_en(data)                          (0x00000010&((data)<<4))
#define  IFD_108_mod_detect_auto_mod_auto_en(data)                               (0x00000001&(data))
#define  IFD_108_mod_detect_auto_get_mod_relate_cr(data)                         ((0x00001000&(data))>>12)
#define  IFD_108_mod_detect_auto_get_mod_relate_cr_thr(data)                     ((0x00000F00&(data))>>8)
#define  IFD_108_mod_detect_auto_get_mod_once_auto_en(data)                      ((0x00000010&(data))>>4)
#define  IFD_108_mod_detect_auto_get_mod_auto_en(data)                           (0x00000001&(data))

#define  IFD_108_cr_state_debounce                                               0x180320E0
#define  IFD_108_cr_state_debounce_reg_addr                                      "0xB80320E0"
#define  IFD_108_cr_state_debounce_reg                                           0xB80320E0
#define  IFD_108_cr_state_debounce_inst_addr                                     "0x002D"
#define  set_IFD_108_cr_state_debounce_reg(data)                                 (*((volatile unsigned int*)IFD_108_cr_state_debounce_reg)=data)
#define  get_IFD_108_cr_state_debounce_reg                                       (*((volatile unsigned int*)IFD_108_cr_state_debounce_reg))
#define  IFD_108_cr_state_debounce_cr_st4_dn_debounce_shift                      (28)
#define  IFD_108_cr_state_debounce_cr_st3_dn_debounce_shift                      (24)
#define  IFD_108_cr_state_debounce_cr_st3_up_debounce_shift                      (20)
#define  IFD_108_cr_state_debounce_cr_st2_dn_debounce_shift                      (16)
#define  IFD_108_cr_state_debounce_cr_st2_up_debounce_shift                      (12)
#define  IFD_108_cr_state_debounce_cr_st1_dn_debounce_shift                      (8)
#define  IFD_108_cr_state_debounce_cr_st1_up_debounce_shift                      (4)
#define  IFD_108_cr_state_debounce_cr_st0_up_debounce_shift                      (0)
#define  IFD_108_cr_state_debounce_cr_st4_dn_debounce_mask                       (0x70000000)
#define  IFD_108_cr_state_debounce_cr_st3_dn_debounce_mask                       (0x07000000)
#define  IFD_108_cr_state_debounce_cr_st3_up_debounce_mask                       (0x00700000)
#define  IFD_108_cr_state_debounce_cr_st2_dn_debounce_mask                       (0x00070000)
#define  IFD_108_cr_state_debounce_cr_st2_up_debounce_mask                       (0x00007000)
#define  IFD_108_cr_state_debounce_cr_st1_dn_debounce_mask                       (0x00000700)
#define  IFD_108_cr_state_debounce_cr_st1_up_debounce_mask                       (0x00000070)
#define  IFD_108_cr_state_debounce_cr_st0_up_debounce_mask                       (0x00000007)
#define  IFD_108_cr_state_debounce_cr_st4_dn_debounce(data)                      (0x70000000&((data)<<28))
#define  IFD_108_cr_state_debounce_cr_st3_dn_debounce(data)                      (0x07000000&((data)<<24))
#define  IFD_108_cr_state_debounce_cr_st3_up_debounce(data)                      (0x00700000&((data)<<20))
#define  IFD_108_cr_state_debounce_cr_st2_dn_debounce(data)                      (0x00070000&((data)<<16))
#define  IFD_108_cr_state_debounce_cr_st2_up_debounce(data)                      (0x00007000&((data)<<12))
#define  IFD_108_cr_state_debounce_cr_st1_dn_debounce(data)                      (0x00000700&((data)<<8))
#define  IFD_108_cr_state_debounce_cr_st1_up_debounce(data)                      (0x00000070&((data)<<4))
#define  IFD_108_cr_state_debounce_cr_st0_up_debounce(data)                      (0x00000007&(data))
#define  IFD_108_cr_state_debounce_get_cr_st4_dn_debounce(data)                  ((0x70000000&(data))>>28)
#define  IFD_108_cr_state_debounce_get_cr_st3_dn_debounce(data)                  ((0x07000000&(data))>>24)
#define  IFD_108_cr_state_debounce_get_cr_st3_up_debounce(data)                  ((0x00700000&(data))>>20)
#define  IFD_108_cr_state_debounce_get_cr_st2_dn_debounce(data)                  ((0x00070000&(data))>>16)
#define  IFD_108_cr_state_debounce_get_cr_st2_up_debounce(data)                  ((0x00007000&(data))>>12)
#define  IFD_108_cr_state_debounce_get_cr_st1_dn_debounce(data)                  ((0x00000700&(data))>>8)
#define  IFD_108_cr_state_debounce_get_cr_st1_up_debounce(data)                  ((0x00000070&(data))>>4)
#define  IFD_108_cr_state_debounce_get_cr_st0_up_debounce(data)                  (0x00000007&(data))

#define  IFD_108_cr_state_thr1                                                   0x180320E4
#define  IFD_108_cr_state_thr1_reg_addr                                          "0xB80320E4"
#define  IFD_108_cr_state_thr1_reg                                               0xB80320E4
#define  IFD_108_cr_state_thr1_inst_addr                                         "0x002E"
#define  set_IFD_108_cr_state_thr1_reg(data)                                     (*((volatile unsigned int*)IFD_108_cr_state_thr1_reg)=data)
#define  get_IFD_108_cr_state_thr1_reg                                           (*((volatile unsigned int*)IFD_108_cr_state_thr1_reg))
#define  IFD_108_cr_state_thr1_cr_phase_var_st0_thr_shift                        (16)
#define  IFD_108_cr_state_thr1_cr_freq_var_st0_thr_shift                         (0)
#define  IFD_108_cr_state_thr1_cr_phase_var_st0_thr_mask                         (0x0FFF0000)
#define  IFD_108_cr_state_thr1_cr_freq_var_st0_thr_mask                          (0x0000FFFF)
#define  IFD_108_cr_state_thr1_cr_phase_var_st0_thr(data)                        (0x0FFF0000&((data)<<16))
#define  IFD_108_cr_state_thr1_cr_freq_var_st0_thr(data)                         (0x0000FFFF&(data))
#define  IFD_108_cr_state_thr1_get_cr_phase_var_st0_thr(data)                    ((0x0FFF0000&(data))>>16)
#define  IFD_108_cr_state_thr1_get_cr_freq_var_st0_thr(data)                     (0x0000FFFF&(data))

#define  IFD_108_cr_state_thr2                                                   0x180320E8
#define  IFD_108_cr_state_thr2_reg_addr                                          "0xB80320E8"
#define  IFD_108_cr_state_thr2_reg                                               0xB80320E8
#define  IFD_108_cr_state_thr2_inst_addr                                         "0x002F"
#define  set_IFD_108_cr_state_thr2_reg(data)                                     (*((volatile unsigned int*)IFD_108_cr_state_thr2_reg)=data)
#define  get_IFD_108_cr_state_thr2_reg                                           (*((volatile unsigned int*)IFD_108_cr_state_thr2_reg))
#define  IFD_108_cr_state_thr2_cr_phase_var_st2_thr_shift                        (16)
#define  IFD_108_cr_state_thr2_cr_freq_varvcheck_thr_shift                       (0)
#define  IFD_108_cr_state_thr2_cr_phase_var_st2_thr_mask                         (0x0FFF0000)
#define  IFD_108_cr_state_thr2_cr_freq_varvcheck_thr_mask                        (0x0000FFFF)
#define  IFD_108_cr_state_thr2_cr_phase_var_st2_thr(data)                        (0x0FFF0000&((data)<<16))
#define  IFD_108_cr_state_thr2_cr_freq_varvcheck_thr(data)                       (0x0000FFFF&(data))
#define  IFD_108_cr_state_thr2_get_cr_phase_var_st2_thr(data)                    ((0x0FFF0000&(data))>>16)
#define  IFD_108_cr_state_thr2_get_cr_freq_varvcheck_thr(data)                   (0x0000FFFF&(data))

#define  IFD_108_cr_state_thr3                                                   0x180320EC
#define  IFD_108_cr_state_thr3_reg_addr                                          "0xB80320EC"
#define  IFD_108_cr_state_thr3_reg                                               0xB80320EC
#define  IFD_108_cr_state_thr3_inst_addr                                         "0x0030"
#define  set_IFD_108_cr_state_thr3_reg(data)                                     (*((volatile unsigned int*)IFD_108_cr_state_thr3_reg)=data)
#define  get_IFD_108_cr_state_thr3_reg                                           (*((volatile unsigned int*)IFD_108_cr_state_thr3_reg))
#define  IFD_108_cr_state_thr3_cr_freq_var_st2_up_thr_shift                      (16)
#define  IFD_108_cr_state_thr3_cr_freq_var_st2_low_thr_shift                     (0)
#define  IFD_108_cr_state_thr3_cr_freq_var_st2_up_thr_mask                       (0xFFFF0000)
#define  IFD_108_cr_state_thr3_cr_freq_var_st2_low_thr_mask                      (0x0000FFFF)
#define  IFD_108_cr_state_thr3_cr_freq_var_st2_up_thr(data)                      (0xFFFF0000&((data)<<16))
#define  IFD_108_cr_state_thr3_cr_freq_var_st2_low_thr(data)                     (0x0000FFFF&(data))
#define  IFD_108_cr_state_thr3_get_cr_freq_var_st2_up_thr(data)                  ((0xFFFF0000&(data))>>16)
#define  IFD_108_cr_state_thr3_get_cr_freq_var_st2_low_thr(data)                 (0x0000FFFF&(data))

#define  IFD_108_cr_state_thr4                                                   0x180320F0
#define  IFD_108_cr_state_thr4_reg_addr                                          "0xB80320F0"
#define  IFD_108_cr_state_thr4_reg                                               0xB80320F0
#define  IFD_108_cr_state_thr4_inst_addr                                         "0x0031"
#define  set_IFD_108_cr_state_thr4_reg(data)                                     (*((volatile unsigned int*)IFD_108_cr_state_thr4_reg)=data)
#define  get_IFD_108_cr_state_thr4_reg                                           (*((volatile unsigned int*)IFD_108_cr_state_thr4_reg))
#define  IFD_108_cr_state_thr4_cr_freq_var_st4_thr_shift                         (16)
#define  IFD_108_cr_state_thr4_cr_freq_var_st3_thr_shift                         (0)
#define  IFD_108_cr_state_thr4_cr_freq_var_st4_thr_mask                          (0xFFFF0000)
#define  IFD_108_cr_state_thr4_cr_freq_var_st3_thr_mask                          (0x0000FFFF)
#define  IFD_108_cr_state_thr4_cr_freq_var_st4_thr(data)                         (0xFFFF0000&((data)<<16))
#define  IFD_108_cr_state_thr4_cr_freq_var_st3_thr(data)                         (0x0000FFFF&(data))
#define  IFD_108_cr_state_thr4_get_cr_freq_var_st4_thr(data)                     ((0xFFFF0000&(data))>>16)
#define  IFD_108_cr_state_thr4_get_cr_freq_var_st3_thr(data)                     (0x0000FFFF&(data))

#define  IFD_108_cr_state_cntl                                                   0x180320F4
#define  IFD_108_cr_state_cntl_reg_addr                                          "0xB80320F4"
#define  IFD_108_cr_state_cntl_reg                                               0xB80320F4
#define  IFD_108_cr_state_cntl_inst_addr                                         "0x0032"
#define  set_IFD_108_cr_state_cntl_reg(data)                                     (*((volatile unsigned int*)IFD_108_cr_state_cntl_reg)=data)
#define  get_IFD_108_cr_state_cntl_reg                                           (*((volatile unsigned int*)IFD_108_cr_state_cntl_reg))
#define  IFD_108_cr_state_cntl_cr_state_hvunlock_out_debounce_shift              (24)
#define  IFD_108_cr_state_cntl_cr_state_hvunlock_in_debounce_shift               (16)
#define  IFD_108_cr_state_cntl_cr_state_hvunlock_reset_shift                     (13)
#define  IFD_108_cr_state_cntl_cr_st2_dn_update_sel_shift                        (12)
#define  IFD_108_cr_state_cntl_cr_fix_state_shift                                (8)
#define  IFD_108_cr_state_cntl_cr_state_fix_en_shift                             (4)
#define  IFD_108_cr_state_cntl_cr_state_en_shift                                 (0)
#define  IFD_108_cr_state_cntl_cr_state_hvunlock_out_debounce_mask               (0x1F000000)
#define  IFD_108_cr_state_cntl_cr_state_hvunlock_in_debounce_mask                (0x001F0000)
#define  IFD_108_cr_state_cntl_cr_state_hvunlock_reset_mask                      (0x00002000)
#define  IFD_108_cr_state_cntl_cr_st2_dn_update_sel_mask                         (0x00001000)
#define  IFD_108_cr_state_cntl_cr_fix_state_mask                                 (0x00000700)
#define  IFD_108_cr_state_cntl_cr_state_fix_en_mask                              (0x00000010)
#define  IFD_108_cr_state_cntl_cr_state_en_mask                                  (0x00000001)
#define  IFD_108_cr_state_cntl_cr_state_hvunlock_out_debounce(data)              (0x1F000000&((data)<<24))
#define  IFD_108_cr_state_cntl_cr_state_hvunlock_in_debounce(data)               (0x001F0000&((data)<<16))
#define  IFD_108_cr_state_cntl_cr_state_hvunlock_reset(data)                     (0x00002000&((data)<<13))
#define  IFD_108_cr_state_cntl_cr_st2_dn_update_sel(data)                        (0x00001000&((data)<<12))
#define  IFD_108_cr_state_cntl_cr_fix_state(data)                                (0x00000700&((data)<<8))
#define  IFD_108_cr_state_cntl_cr_state_fix_en(data)                             (0x00000010&((data)<<4))
#define  IFD_108_cr_state_cntl_cr_state_en(data)                                 (0x00000001&(data))
#define  IFD_108_cr_state_cntl_get_cr_state_hvunlock_out_debounce(data)          ((0x1F000000&(data))>>24)
#define  IFD_108_cr_state_cntl_get_cr_state_hvunlock_in_debounce(data)           ((0x001F0000&(data))>>16)
#define  IFD_108_cr_state_cntl_get_cr_state_hvunlock_reset(data)                 ((0x00002000&(data))>>13)
#define  IFD_108_cr_state_cntl_get_cr_st2_dn_update_sel(data)                    ((0x00001000&(data))>>12)
#define  IFD_108_cr_state_cntl_get_cr_fix_state(data)                            ((0x00000700&(data))>>8)
#define  IFD_108_cr_state_cntl_get_cr_state_fix_en(data)                         ((0x00000010&(data))>>4)
#define  IFD_108_cr_state_cntl_get_cr_state_en(data)                             (0x00000001&(data))

#define  IFD_108_cr_state_read                                                   0x180320F8
#define  IFD_108_cr_state_read_reg_addr                                          "0xB80320F8"
#define  IFD_108_cr_state_read_reg                                               0xB80320F8
#define  IFD_108_cr_state_read_inst_addr                                         "0x0033"
#define  set_IFD_108_cr_state_read_reg(data)                                     (*((volatile unsigned int*)IFD_108_cr_state_read_reg)=data)
#define  get_IFD_108_cr_state_read_reg                                           (*((volatile unsigned int*)IFD_108_cr_state_read_reg))
#define  IFD_108_cr_state_read_cr_phase_inverse_en_shift                         (16)
#define  IFD_108_cr_state_read_cr_weight_shift_shift                             (12)
#define  IFD_108_cr_state_read_cr_pgain_shift                                    (8)
#define  IFD_108_cr_state_read_cr_igain_shift                                    (4)
#define  IFD_108_cr_state_read_cr_state_shift                                    (0)
#define  IFD_108_cr_state_read_cr_phase_inverse_en_mask                          (0x00010000)
#define  IFD_108_cr_state_read_cr_weight_shift_mask                              (0x0000F000)
#define  IFD_108_cr_state_read_cr_pgain_mask                                     (0x00000F00)
#define  IFD_108_cr_state_read_cr_igain_mask                                     (0x000000F0)
#define  IFD_108_cr_state_read_cr_state_mask                                     (0x00000007)
#define  IFD_108_cr_state_read_cr_phase_inverse_en(data)                         (0x00010000&((data)<<16))
#define  IFD_108_cr_state_read_cr_weight_shift(data)                             (0x0000F000&((data)<<12))
#define  IFD_108_cr_state_read_cr_pgain(data)                                    (0x00000F00&((data)<<8))
#define  IFD_108_cr_state_read_cr_igain(data)                                    (0x000000F0&((data)<<4))
#define  IFD_108_cr_state_read_cr_state(data)                                    (0x00000007&(data))
#define  IFD_108_cr_state_read_get_cr_phase_inverse_en(data)                     ((0x00010000&(data))>>16)
#define  IFD_108_cr_state_read_get_cr_weight_shift(data)                         ((0x0000F000&(data))>>12)
#define  IFD_108_cr_state_read_get_cr_pgain(data)                                ((0x00000F00&(data))>>8)
#define  IFD_108_cr_state_read_get_cr_igain(data)                                ((0x000000F0&(data))>>4)
#define  IFD_108_cr_state_read_get_cr_state(data)                                (0x00000007&(data))

#define  IFD_108_cr_state_weight_shift                                           0x180320FC
#define  IFD_108_cr_state_weight_shift_reg_addr                                  "0xB80320FC"
#define  IFD_108_cr_state_weight_shift_reg                                       0xB80320FC
#define  IFD_108_cr_state_weight_shift_inst_addr                                 "0x0034"
#define  set_IFD_108_cr_state_weight_shift_reg(data)                             (*((volatile unsigned int*)IFD_108_cr_state_weight_shift_reg)=data)
#define  get_IFD_108_cr_state_weight_shift_reg                                   (*((volatile unsigned int*)IFD_108_cr_state_weight_shift_reg))
#define  IFD_108_cr_state_weight_shift_cr_weight_shift_st4_shift                 (8)
#define  IFD_108_cr_state_weight_shift_cr_weight_shift_st2_shift                 (4)
#define  IFD_108_cr_state_weight_shift_cr_weight_shift_st0_shift                 (0)
#define  IFD_108_cr_state_weight_shift_cr_weight_shift_st4_mask                  (0x00000F00)
#define  IFD_108_cr_state_weight_shift_cr_weight_shift_st2_mask                  (0x000000F0)
#define  IFD_108_cr_state_weight_shift_cr_weight_shift_st0_mask                  (0x0000000F)
#define  IFD_108_cr_state_weight_shift_cr_weight_shift_st4(data)                 (0x00000F00&((data)<<8))
#define  IFD_108_cr_state_weight_shift_cr_weight_shift_st2(data)                 (0x000000F0&((data)<<4))
#define  IFD_108_cr_state_weight_shift_cr_weight_shift_st0(data)                 (0x0000000F&(data))
#define  IFD_108_cr_state_weight_shift_get_cr_weight_shift_st4(data)             ((0x00000F00&(data))>>8)
#define  IFD_108_cr_state_weight_shift_get_cr_weight_shift_st2(data)             ((0x000000F0&(data))>>4)
#define  IFD_108_cr_state_weight_shift_get_cr_weight_shift_st0(data)             (0x0000000F&(data))

#define  IFD_108_agc_enable_sel                                                  0x18032100
#define  IFD_108_agc_enable_sel_reg_addr                                         "0xB8032100"
#define  IFD_108_agc_enable_sel_reg                                              0xB8032100
#define  IFD_108_agc_enable_sel_inst_addr                                        "0x0035"
#define  set_IFD_108_agc_enable_sel_reg(data)                                    (*((volatile unsigned int*)IFD_108_agc_enable_sel_reg)=data)
#define  get_IFD_108_agc_enable_sel_reg                                          (*((volatile unsigned int*)IFD_108_agc_enable_sel_reg))
#define  IFD_108_agc_enable_sel_agc_max4_sel_shift                               (8)
#define  IFD_108_agc_enable_sel_agc_en_shift                                     (7)
#define  IFD_108_agc_enable_sel_dgain_en_shift                                   (6)
#define  IFD_108_agc_enable_sel_agc_bpf_en_shift                                 (5)
#define  IFD_108_agc_enable_sel_agc_max4_en_shift                                (4)
#define  IFD_108_agc_enable_sel_agc_lpf_en_shift                                 (3)
#define  IFD_108_agc_enable_sel_agc_if_en_shift                                  (2)
#define  IFD_108_agc_enable_sel_agc_rf_en_shift                                  (1)
#define  IFD_108_agc_enable_sel_agc_fine_tune_en_shift                           (0)
#define  IFD_108_agc_enable_sel_agc_max4_sel_mask                                (0x00000100)
#define  IFD_108_agc_enable_sel_agc_en_mask                                      (0x00000080)
#define  IFD_108_agc_enable_sel_dgain_en_mask                                    (0x00000040)
#define  IFD_108_agc_enable_sel_agc_bpf_en_mask                                  (0x00000020)
#define  IFD_108_agc_enable_sel_agc_max4_en_mask                                 (0x00000010)
#define  IFD_108_agc_enable_sel_agc_lpf_en_mask                                  (0x00000008)
#define  IFD_108_agc_enable_sel_agc_if_en_mask                                   (0x00000004)
#define  IFD_108_agc_enable_sel_agc_rf_en_mask                                   (0x00000002)
#define  IFD_108_agc_enable_sel_agc_fine_tune_en_mask                            (0x00000001)
#define  IFD_108_agc_enable_sel_agc_max4_sel(data)                               (0x00000100&((data)<<8))
#define  IFD_108_agc_enable_sel_agc_en(data)                                     (0x00000080&((data)<<7))
#define  IFD_108_agc_enable_sel_dgain_en(data)                                   (0x00000040&((data)<<6))
#define  IFD_108_agc_enable_sel_agc_bpf_en(data)                                 (0x00000020&((data)<<5))
#define  IFD_108_agc_enable_sel_agc_max4_en(data)                                (0x00000010&((data)<<4))
#define  IFD_108_agc_enable_sel_agc_lpf_en(data)                                 (0x00000008&((data)<<3))
#define  IFD_108_agc_enable_sel_agc_if_en(data)                                  (0x00000004&((data)<<2))
#define  IFD_108_agc_enable_sel_agc_rf_en(data)                                  (0x00000002&((data)<<1))
#define  IFD_108_agc_enable_sel_agc_fine_tune_en(data)                           (0x00000001&(data))
#define  IFD_108_agc_enable_sel_get_agc_max4_sel(data)                           ((0x00000100&(data))>>8)
#define  IFD_108_agc_enable_sel_get_agc_en(data)                                 ((0x00000080&(data))>>7)
#define  IFD_108_agc_enable_sel_get_dgain_en(data)                               ((0x00000040&(data))>>6)
#define  IFD_108_agc_enable_sel_get_agc_bpf_en(data)                             ((0x00000020&(data))>>5)
#define  IFD_108_agc_enable_sel_get_agc_max4_en(data)                            ((0x00000010&(data))>>4)
#define  IFD_108_agc_enable_sel_get_agc_lpf_en(data)                             ((0x00000008&(data))>>3)
#define  IFD_108_agc_enable_sel_get_agc_if_en(data)                              ((0x00000004&(data))>>2)
#define  IFD_108_agc_enable_sel_get_agc_rf_en(data)                              ((0x00000002&(data))>>1)
#define  IFD_108_agc_enable_sel_get_agc_fine_tune_en(data)                       (0x00000001&(data))

#define  IFD_108_agc_max_limit_cnt_1                                             0x18032104
#define  IFD_108_agc_max_limit_cnt_1_reg_addr                                    "0xB8032104"
#define  IFD_108_agc_max_limit_cnt_1_reg                                         0xB8032104
#define  IFD_108_agc_max_limit_cnt_1_inst_addr                                   "0x0036"
#define  set_IFD_108_agc_max_limit_cnt_1_reg(data)                               (*((volatile unsigned int*)IFD_108_agc_max_limit_cnt_1_reg)=data)
#define  get_IFD_108_agc_max_limit_cnt_1_reg                                     (*((volatile unsigned int*)IFD_108_agc_max_limit_cnt_1_reg))
#define  IFD_108_agc_max_limit_cnt_1_agc_max_count_limit_en_shift                (12)
#define  IFD_108_agc_max_limit_cnt_1_agc_max_count_limit_shift                   (0)
#define  IFD_108_agc_max_limit_cnt_1_agc_max_count_limit_en_mask                 (0x00001000)
#define  IFD_108_agc_max_limit_cnt_1_agc_max_count_limit_mask                    (0x00000FFF)
#define  IFD_108_agc_max_limit_cnt_1_agc_max_count_limit_en(data)                (0x00001000&((data)<<12))
#define  IFD_108_agc_max_limit_cnt_1_agc_max_count_limit(data)                   (0x00000FFF&(data))
#define  IFD_108_agc_max_limit_cnt_1_get_agc_max_count_limit_en(data)            ((0x00001000&(data))>>12)
#define  IFD_108_agc_max_limit_cnt_1_get_agc_max_count_limit(data)               (0x00000FFF&(data))

#define  IFD_108_agc_max_countforcoarsemode_agc_cntl1                            0x18032108
#define  IFD_108_agc_max_countforcoarsemode_agc_cntl1_reg_addr                   "0xB8032108"
#define  IFD_108_agc_max_countforcoarsemode_agc_cntl1_reg                        0xB8032108
#define  IFD_108_agc_max_countforcoarsemode_agc_cntl1_inst_addr                  "0x0037"
#define  set_IFD_108_agc_max_countforcoarsemode_agc_cntl1_reg(data)              (*((volatile unsigned int*)IFD_108_agc_max_countforcoarsemode_agc_cntl1_reg)=data)
#define  get_IFD_108_agc_max_countforcoarsemode_agc_cntl1_reg                    (*((volatile unsigned int*)IFD_108_agc_max_countforcoarsemode_agc_cntl1_reg))
#define  IFD_108_agc_max_countforcoarsemode_agc_cntl1_agc_peak_slow_charge_value_shift (20)
#define  IFD_108_agc_max_countforcoarsemode_agc_cntl1_agc_max_slow_charge_value_shift (16)
#define  IFD_108_agc_max_countforcoarsemode_agc_cntl1_agc_slow_charge_max_en_shift (13)
#define  IFD_108_agc_max_countforcoarsemode_agc_cntl1_agc_slow_charge_peak_en_shift (12)
#define  IFD_108_agc_max_countforcoarsemode_agc_cntl1_agc_max_cntl_unlock_shift  (0)
#define  IFD_108_agc_max_countforcoarsemode_agc_cntl1_agc_peak_slow_charge_value_mask (0x00700000)
#define  IFD_108_agc_max_countforcoarsemode_agc_cntl1_agc_max_slow_charge_value_mask (0x000F0000)
#define  IFD_108_agc_max_countforcoarsemode_agc_cntl1_agc_slow_charge_max_en_mask (0x00002000)
#define  IFD_108_agc_max_countforcoarsemode_agc_cntl1_agc_slow_charge_peak_en_mask (0x00001000)
#define  IFD_108_agc_max_countforcoarsemode_agc_cntl1_agc_max_cntl_unlock_mask   (0x00000FFF)
#define  IFD_108_agc_max_countforcoarsemode_agc_cntl1_agc_peak_slow_charge_value(data) (0x00700000&((data)<<20))
#define  IFD_108_agc_max_countforcoarsemode_agc_cntl1_agc_max_slow_charge_value(data) (0x000F0000&((data)<<16))
#define  IFD_108_agc_max_countforcoarsemode_agc_cntl1_agc_slow_charge_max_en(data) (0x00002000&((data)<<13))
#define  IFD_108_agc_max_countforcoarsemode_agc_cntl1_agc_slow_charge_peak_en(data) (0x00001000&((data)<<12))
#define  IFD_108_agc_max_countforcoarsemode_agc_cntl1_agc_max_cntl_unlock(data)  (0x00000FFF&(data))
#define  IFD_108_agc_max_countforcoarsemode_agc_cntl1_get_agc_peak_slow_charge_value(data) ((0x00700000&(data))>>20)
#define  IFD_108_agc_max_countforcoarsemode_agc_cntl1_get_agc_max_slow_charge_value(data) ((0x000F0000&(data))>>16)
#define  IFD_108_agc_max_countforcoarsemode_agc_cntl1_get_agc_slow_charge_max_en(data) ((0x00002000&(data))>>13)
#define  IFD_108_agc_max_countforcoarsemode_agc_cntl1_get_agc_slow_charge_peak_en(data) ((0x00001000&(data))>>12)
#define  IFD_108_agc_max_countforcoarsemode_agc_cntl1_get_agc_max_cntl_unlock(data) (0x00000FFF&(data))

#define  IFD_108_agc_max_countforfinelockmode_agc_cntl2                          0x1803210C
#define  IFD_108_agc_max_countforfinelockmode_agc_cntl2_reg_addr                 "0xB803210C"
#define  IFD_108_agc_max_countforfinelockmode_agc_cntl2_reg                      0xB803210C
#define  IFD_108_agc_max_countforfinelockmode_agc_cntl2_inst_addr                "0x0038"
#define  set_IFD_108_agc_max_countforfinelockmode_agc_cntl2_reg(data)            (*((volatile unsigned int*)IFD_108_agc_max_countforfinelockmode_agc_cntl2_reg)=data)
#define  get_IFD_108_agc_max_countforfinelockmode_agc_cntl2_reg                  (*((volatile unsigned int*)IFD_108_agc_max_countforfinelockmode_agc_cntl2_reg))
#define  IFD_108_agc_max_countforfinelockmode_agc_cntl2_agc_max_cntl_lock_shift  (0)
#define  IFD_108_agc_max_countforfinelockmode_agc_cntl2_agc_max_cntl_lock_mask   (0x00000FFF)
#define  IFD_108_agc_max_countforfinelockmode_agc_cntl2_agc_max_cntl_lock(data)  (0x00000FFF&(data))
#define  IFD_108_agc_max_countforfinelockmode_agc_cntl2_get_agc_max_cntl_lock(data) (0x00000FFF&(data))

#define  IFD_108_agc_avg_target                                                  0x18032110
#define  IFD_108_agc_avg_target_reg_addr                                         "0xB8032110"
#define  IFD_108_agc_avg_target_reg                                              0xB8032110
#define  IFD_108_agc_avg_target_inst_addr                                        "0x0039"
#define  set_IFD_108_agc_avg_target_reg(data)                                    (*((volatile unsigned int*)IFD_108_agc_avg_target_reg)=data)
#define  get_IFD_108_agc_avg_target_reg                                          (*((volatile unsigned int*)IFD_108_agc_avg_target_reg))
#define  IFD_108_agc_avg_target_agc_diff_level_inv_shift                         (12)
#define  IFD_108_agc_avg_target_agc_diff_targ_shift                              (0)
#define  IFD_108_agc_avg_target_agc_diff_level_inv_mask                          (0x00001000)
#define  IFD_108_agc_avg_target_agc_diff_targ_mask                               (0x000007FF)
#define  IFD_108_agc_avg_target_agc_diff_level_inv(data)                         (0x00001000&((data)<<12))
#define  IFD_108_agc_avg_target_agc_diff_targ(data)                              (0x000007FF&(data))
#define  IFD_108_agc_avg_target_get_agc_diff_level_inv(data)                     ((0x00001000&(data))>>12)
#define  IFD_108_agc_avg_target_get_agc_diff_targ(data)                          (0x000007FF&(data))

#define  IFD_108_agc_max_countforcoarsemode_agc_lock2                            0x18032114
#define  IFD_108_agc_max_countforcoarsemode_agc_lock2_reg_addr                   "0xB8032114"
#define  IFD_108_agc_max_countforcoarsemode_agc_lock2_reg                        0xB8032114
#define  IFD_108_agc_max_countforcoarsemode_agc_lock2_inst_addr                  "0x003A"
#define  set_IFD_108_agc_max_countforcoarsemode_agc_lock2_reg(data)              (*((volatile unsigned int*)IFD_108_agc_max_countforcoarsemode_agc_lock2_reg)=data)
#define  get_IFD_108_agc_max_countforcoarsemode_agc_lock2_reg                    (*((volatile unsigned int*)IFD_108_agc_max_countforcoarsemode_agc_lock2_reg))
#define  IFD_108_agc_max_countforcoarsemode_agc_lock2_agc_loop1_downsample_sel_shift (4)
#define  IFD_108_agc_max_countforcoarsemode_agc_lock2_agc_pos_en_shift           (0)
#define  IFD_108_agc_max_countforcoarsemode_agc_lock2_agc_loop1_downsample_sel_mask (0x0000FFF0)
#define  IFD_108_agc_max_countforcoarsemode_agc_lock2_agc_pos_en_mask            (0x00000001)
#define  IFD_108_agc_max_countforcoarsemode_agc_lock2_agc_loop1_downsample_sel(data) (0x0000FFF0&((data)<<4))
#define  IFD_108_agc_max_countforcoarsemode_agc_lock2_agc_pos_en(data)           (0x00000001&(data))
#define  IFD_108_agc_max_countforcoarsemode_agc_lock2_get_agc_loop1_downsample_sel(data) ((0x0000FFF0&(data))>>4)
#define  IFD_108_agc_max_countforcoarsemode_agc_lock2_get_agc_pos_en(data)       (0x00000001&(data))

#define  IFD_108_agc_targ_val                                                    0x18032118
#define  IFD_108_agc_targ_val_reg_addr                                           "0xB8032118"
#define  IFD_108_agc_targ_val_reg                                                0xB8032118
#define  IFD_108_agc_targ_val_inst_addr                                          "0x003B"
#define  set_IFD_108_agc_targ_val_reg(data)                                      (*((volatile unsigned int*)IFD_108_agc_targ_val_reg)=data)
#define  get_IFD_108_agc_targ_val_reg                                            (*((volatile unsigned int*)IFD_108_agc_targ_val_reg))
#define  IFD_108_agc_targ_val_agc_data_targ_shift                                (12)
#define  IFD_108_agc_targ_val_agc_targ_val_shift                                 (0)
#define  IFD_108_agc_targ_val_agc_data_targ_mask                                 (0x007FF000)
#define  IFD_108_agc_targ_val_agc_targ_val_mask                                  (0x000007FF)
#define  IFD_108_agc_targ_val_agc_data_targ(data)                                (0x007FF000&((data)<<12))
#define  IFD_108_agc_targ_val_agc_targ_val(data)                                 (0x000007FF&(data))
#define  IFD_108_agc_targ_val_get_agc_data_targ(data)                            ((0x007FF000&(data))>>12)
#define  IFD_108_agc_targ_val_get_agc_targ_val(data)                             (0x000007FF&(data))

#define  IFD_108_agc_cntl_sel                                                    0x1803211C
#define  IFD_108_agc_cntl_sel_reg_addr                                           "0xB803211C"
#define  IFD_108_agc_cntl_sel_reg                                                0xB803211C
#define  IFD_108_agc_cntl_sel_inst_addr                                          "0x003C"
#define  set_IFD_108_agc_cntl_sel_reg(data)                                      (*((volatile unsigned int*)IFD_108_agc_cntl_sel_reg)=data)
#define  get_IFD_108_agc_cntl_sel_reg                                            (*((volatile unsigned int*)IFD_108_agc_cntl_sel_reg))
#define  IFD_108_agc_cntl_sel_agc_if_sd_in_fix_value_shift                       (12)
#define  IFD_108_agc_cntl_sel_agc_out_inv_rf_shift                               (9)
#define  IFD_108_agc_cntl_sel_agc_if_sd_in_fix_en_shift                          (8)
#define  IFD_108_agc_cntl_sel_fine_cr_ind_shift                                  (6)
#define  IFD_108_agc_cntl_sel_agc_out_inv_if_shift                               (5)
#define  IFD_108_agc_cntl_sel_agc_if_manu_en_shift                               (4)
#define  IFD_108_agc_cntl_sel_agc_rf_manu_en_shift                               (3)
#define  IFD_108_agc_cntl_sel_agc_manu_en_shift                                  (2)
#define  IFD_108_agc_cntl_sel_agc_hold_shift                                     (1)
#define  IFD_108_agc_cntl_sel_agc_polar_shift                                    (0)
#define  IFD_108_agc_cntl_sel_agc_if_sd_in_fix_value_mask                        (0x01FFF000)
#define  IFD_108_agc_cntl_sel_agc_out_inv_rf_mask                                (0x00000200)
#define  IFD_108_agc_cntl_sel_agc_if_sd_in_fix_en_mask                           (0x00000100)
#define  IFD_108_agc_cntl_sel_fine_cr_ind_mask                                   (0x00000040)
#define  IFD_108_agc_cntl_sel_agc_out_inv_if_mask                                (0x00000020)
#define  IFD_108_agc_cntl_sel_agc_if_manu_en_mask                                (0x00000010)
#define  IFD_108_agc_cntl_sel_agc_rf_manu_en_mask                                (0x00000008)
#define  IFD_108_agc_cntl_sel_agc_manu_en_mask                                   (0x00000004)
#define  IFD_108_agc_cntl_sel_agc_hold_mask                                      (0x00000002)
#define  IFD_108_agc_cntl_sel_agc_polar_mask                                     (0x00000001)
#define  IFD_108_agc_cntl_sel_agc_if_sd_in_fix_value(data)                       (0x01FFF000&((data)<<12))
#define  IFD_108_agc_cntl_sel_agc_out_inv_rf(data)                               (0x00000200&((data)<<9))
#define  IFD_108_agc_cntl_sel_agc_if_sd_in_fix_en(data)                          (0x00000100&((data)<<8))
#define  IFD_108_agc_cntl_sel_fine_cr_ind(data)                                  (0x00000040&((data)<<6))
#define  IFD_108_agc_cntl_sel_agc_out_inv_if(data)                               (0x00000020&((data)<<5))
#define  IFD_108_agc_cntl_sel_agc_if_manu_en(data)                               (0x00000010&((data)<<4))
#define  IFD_108_agc_cntl_sel_agc_rf_manu_en(data)                               (0x00000008&((data)<<3))
#define  IFD_108_agc_cntl_sel_agc_manu_en(data)                                  (0x00000004&((data)<<2))
#define  IFD_108_agc_cntl_sel_agc_hold(data)                                     (0x00000002&((data)<<1))
#define  IFD_108_agc_cntl_sel_agc_polar(data)                                    (0x00000001&(data))
#define  IFD_108_agc_cntl_sel_get_agc_if_sd_in_fix_value(data)                   ((0x01FFF000&(data))>>12)
#define  IFD_108_agc_cntl_sel_get_agc_out_inv_rf(data)                           ((0x00000200&(data))>>9)
#define  IFD_108_agc_cntl_sel_get_agc_if_sd_in_fix_en(data)                      ((0x00000100&(data))>>8)
#define  IFD_108_agc_cntl_sel_get_fine_cr_ind(data)                              ((0x00000040&(data))>>6)
#define  IFD_108_agc_cntl_sel_get_agc_out_inv_if(data)                           ((0x00000020&(data))>>5)
#define  IFD_108_agc_cntl_sel_get_agc_if_manu_en(data)                           ((0x00000010&(data))>>4)
#define  IFD_108_agc_cntl_sel_get_agc_rf_manu_en(data)                           ((0x00000008&(data))>>3)
#define  IFD_108_agc_cntl_sel_get_agc_manu_en(data)                              ((0x00000004&(data))>>2)
#define  IFD_108_agc_cntl_sel_get_agc_hold(data)                                 ((0x00000002&(data))>>1)
#define  IFD_108_agc_cntl_sel_get_agc_polar(data)                                (0x00000001&(data))

#define  IFD_108_agc_manu_value                                                  0x18032120
#define  IFD_108_agc_manu_value_reg_addr                                         "0xB8032120"
#define  IFD_108_agc_manu_value_reg                                              0xB8032120
#define  IFD_108_agc_manu_value_inst_addr                                        "0x003D"
#define  set_IFD_108_agc_manu_value_reg(data)                                    (*((volatile unsigned int*)IFD_108_agc_manu_value_reg)=data)
#define  get_IFD_108_agc_manu_value_reg                                          (*((volatile unsigned int*)IFD_108_agc_manu_value_reg))
#define  IFD_108_agc_manu_value_agc_manu_value_shift                             (0)
#define  IFD_108_agc_manu_value_agc_manu_value_mask                              (0x00001FFF)
#define  IFD_108_agc_manu_value_agc_manu_value(data)                             (0x00001FFF&(data))
#define  IFD_108_agc_manu_value_get_agc_manu_value(data)                         (0x00001FFF&(data))

#define  IFD_108_agc_if_manu_value                                               0x18032124
#define  IFD_108_agc_if_manu_value_reg_addr                                      "0xB8032124"
#define  IFD_108_agc_if_manu_value_reg                                           0xB8032124
#define  IFD_108_agc_if_manu_value_inst_addr                                     "0x003E"
#define  set_IFD_108_agc_if_manu_value_reg(data)                                 (*((volatile unsigned int*)IFD_108_agc_if_manu_value_reg)=data)
#define  get_IFD_108_agc_if_manu_value_reg                                       (*((volatile unsigned int*)IFD_108_agc_if_manu_value_reg))
#define  IFD_108_agc_if_manu_value_agc_if_manu_value_shift                       (0)
#define  IFD_108_agc_if_manu_value_agc_if_manu_value_mask                        (0x00001FFF)
#define  IFD_108_agc_if_manu_value_agc_if_manu_value(data)                       (0x00001FFF&(data))
#define  IFD_108_agc_if_manu_value_get_agc_if_manu_value(data)                   (0x00001FFF&(data))

#define  IFD_108_agc_rf_manu_value                                               0x18032128
#define  IFD_108_agc_rf_manu_value_reg_addr                                      "0xB8032128"
#define  IFD_108_agc_rf_manu_value_reg                                           0xB8032128
#define  IFD_108_agc_rf_manu_value_inst_addr                                     "0x003F"
#define  set_IFD_108_agc_rf_manu_value_reg(data)                                 (*((volatile unsigned int*)IFD_108_agc_rf_manu_value_reg)=data)
#define  get_IFD_108_agc_rf_manu_value_reg                                       (*((volatile unsigned int*)IFD_108_agc_rf_manu_value_reg))
#define  IFD_108_agc_rf_manu_value_agc_rf_manu_value_shift                       (0)
#define  IFD_108_agc_rf_manu_value_agc_rf_manu_value_mask                        (0x00001FFF)
#define  IFD_108_agc_rf_manu_value_agc_rf_manu_value(data)                       (0x00001FFF&(data))
#define  IFD_108_agc_rf_manu_value_get_agc_rf_manu_value(data)                   (0x00001FFF&(data))

#define  IFD_108_ki_val                                                          0x1803212C
#define  IFD_108_ki_val_reg_addr                                                 "0xB803212C"
#define  IFD_108_ki_val_reg                                                      0xB803212C
#define  IFD_108_ki_val_inst_addr                                                "0x0040"
#define  set_IFD_108_ki_val_reg(data)                                            (*((volatile unsigned int*)IFD_108_ki_val_reg)=data)
#define  get_IFD_108_ki_val_reg                                                  (*((volatile unsigned int*)IFD_108_ki_val_reg))
#define  IFD_108_ki_val_agc_kpd_add_method_shift_shift                           (24)
#define  IFD_108_ki_val_agc_kp_shift                                             (4)
#define  IFD_108_ki_val_agc_ki_shift                                             (0)
#define  IFD_108_ki_val_agc_kpd_add_method_shift_mask                            (0x1F000000)
#define  IFD_108_ki_val_agc_kp_mask                                              (0x000001F0)
#define  IFD_108_ki_val_agc_ki_mask                                              (0x0000000F)
#define  IFD_108_ki_val_agc_kpd_add_method_shift(data)                           (0x1F000000&((data)<<24))
#define  IFD_108_ki_val_agc_kp(data)                                             (0x000001F0&((data)<<4))
#define  IFD_108_ki_val_agc_ki(data)                                             (0x0000000F&(data))
#define  IFD_108_ki_val_get_agc_kpd_add_method_shift(data)                       ((0x1F000000&(data))>>24)
#define  IFD_108_ki_val_get_agc_kp(data)                                         ((0x000001F0&(data))>>4)
#define  IFD_108_ki_val_get_agc_ki(data)                                         (0x0000000F&(data))

#define  IFD_108_if_agc_min                                                      0x18032130
#define  IFD_108_if_agc_min_reg_addr                                             "0xB8032130"
#define  IFD_108_if_agc_min_reg                                                  0xB8032130
#define  IFD_108_if_agc_min_inst_addr                                            "0x0041"
#define  set_IFD_108_if_agc_min_reg(data)                                        (*((volatile unsigned int*)IFD_108_if_agc_min_reg)=data)
#define  get_IFD_108_if_agc_min_reg                                              (*((volatile unsigned int*)IFD_108_if_agc_min_reg))
#define  IFD_108_if_agc_min_agc_if_max_shift                                     (16)
#define  IFD_108_if_agc_min_agc_if_min_shift                                     (0)
#define  IFD_108_if_agc_min_agc_if_max_mask                                      (0x1FFF0000)
#define  IFD_108_if_agc_min_agc_if_min_mask                                      (0x00001FFF)
#define  IFD_108_if_agc_min_agc_if_max(data)                                     (0x1FFF0000&((data)<<16))
#define  IFD_108_if_agc_min_agc_if_min(data)                                     (0x00001FFF&(data))
#define  IFD_108_if_agc_min_get_agc_if_max(data)                                 ((0x1FFF0000&(data))>>16)
#define  IFD_108_if_agc_min_get_agc_if_min(data)                                 (0x00001FFF&(data))

#define  IFD_108_rf_agc_limit_value                                              0x18032134
#define  IFD_108_rf_agc_limit_value_reg_addr                                     "0xB8032134"
#define  IFD_108_rf_agc_limit_value_reg                                          0xB8032134
#define  IFD_108_rf_agc_limit_value_inst_addr                                    "0x0042"
#define  set_IFD_108_rf_agc_limit_value_reg(data)                                (*((volatile unsigned int*)IFD_108_rf_agc_limit_value_reg)=data)
#define  get_IFD_108_rf_agc_limit_value_reg                                      (*((volatile unsigned int*)IFD_108_rf_agc_limit_value_reg))
#define  IFD_108_rf_agc_limit_value_agc_rf_min_shift                             (16)
#define  IFD_108_rf_agc_limit_value_agc_rf_max_shift                             (0)
#define  IFD_108_rf_agc_limit_value_agc_rf_min_mask                              (0x1FFF0000)
#define  IFD_108_rf_agc_limit_value_agc_rf_max_mask                              (0x00001FFF)
#define  IFD_108_rf_agc_limit_value_agc_rf_min(data)                             (0x1FFF0000&((data)<<16))
#define  IFD_108_rf_agc_limit_value_agc_rf_max(data)                             (0x00001FFF&(data))
#define  IFD_108_rf_agc_limit_value_get_agc_rf_min(data)                         ((0x1FFF0000&(data))>>16)
#define  IFD_108_rf_agc_limit_value_get_agc_rf_max(data)                         (0x00001FFF&(data))

#define  IFD_108_agc_lock_len                                                    0x18032138
#define  IFD_108_agc_lock_len_reg_addr                                           "0xB8032138"
#define  IFD_108_agc_lock_len_reg                                                0xB8032138
#define  IFD_108_agc_lock_len_inst_addr                                          "0x0043"
#define  set_IFD_108_agc_lock_len_reg(data)                                      (*((volatile unsigned int*)IFD_108_agc_lock_len_reg)=data)
#define  get_IFD_108_agc_lock_len_reg                                            (*((volatile unsigned int*)IFD_108_agc_lock_len_reg))
#define  IFD_108_agc_lock_len_agc_lock_debounce_num_shift                        (16)
#define  IFD_108_agc_lock_len_agc_lock_peak_thr_shift                            (4)
#define  IFD_108_agc_lock_len_agc_lock_cnt_len_off_shift                         (0)
#define  IFD_108_agc_lock_len_agc_lock_debounce_num_mask                         (0x001F0000)
#define  IFD_108_agc_lock_len_agc_lock_peak_thr_mask                             (0x0000FFF0)
#define  IFD_108_agc_lock_len_agc_lock_cnt_len_off_mask                          (0x00000003)
#define  IFD_108_agc_lock_len_agc_lock_debounce_num(data)                        (0x001F0000&((data)<<16))
#define  IFD_108_agc_lock_len_agc_lock_peak_thr(data)                            (0x0000FFF0&((data)<<4))
#define  IFD_108_agc_lock_len_agc_lock_cnt_len_off(data)                         (0x00000003&(data))
#define  IFD_108_agc_lock_len_get_agc_lock_debounce_num(data)                    ((0x001F0000&(data))>>16)
#define  IFD_108_agc_lock_len_get_agc_lock_peak_thr(data)                        ((0x0000FFF0&(data))>>4)
#define  IFD_108_agc_lock_len_get_agc_lock_cnt_len_off(data)                     (0x00000003&(data))

#define  IFD_108_agc_lock_th                                                     0x1803213C
#define  IFD_108_agc_lock_th_reg_addr                                            "0xB803213C"
#define  IFD_108_agc_lock_th_reg                                                 0xB803213C
#define  IFD_108_agc_lock_th_inst_addr                                           "0x0044"
#define  set_IFD_108_agc_lock_th_reg(data)                                       (*((volatile unsigned int*)IFD_108_agc_lock_th_reg)=data)
#define  get_IFD_108_agc_lock_th_reg                                             (*((volatile unsigned int*)IFD_108_agc_lock_th_reg))
#define  IFD_108_agc_lock_th_agc_lock_en_sel_shift                               (24)
#define  IFD_108_agc_lock_th_agc_lock_exception_shift                            (20)
#define  IFD_108_agc_lock_th_agc_lock_err_sel_shift                              (16)
#define  IFD_108_agc_lock_th_agc_lock_th_out_shift                               (8)
#define  IFD_108_agc_lock_th_agc_lock_th_shift                                   (0)
#define  IFD_108_agc_lock_th_agc_lock_en_sel_mask                                (0x03000000)
#define  IFD_108_agc_lock_th_agc_lock_exception_mask                             (0x00100000)
#define  IFD_108_agc_lock_th_agc_lock_err_sel_mask                               (0x00010000)
#define  IFD_108_agc_lock_th_agc_lock_th_out_mask                                (0x0000FF00)
#define  IFD_108_agc_lock_th_agc_lock_th_mask                                    (0x000000FF)
#define  IFD_108_agc_lock_th_agc_lock_en_sel(data)                               (0x03000000&((data)<<24))
#define  IFD_108_agc_lock_th_agc_lock_exception(data)                            (0x00100000&((data)<<20))
#define  IFD_108_agc_lock_th_agc_lock_err_sel(data)                              (0x00010000&((data)<<16))
#define  IFD_108_agc_lock_th_agc_lock_th_out(data)                               (0x0000FF00&((data)<<8))
#define  IFD_108_agc_lock_th_agc_lock_th(data)                                   (0x000000FF&(data))
#define  IFD_108_agc_lock_th_get_agc_lock_en_sel(data)                           ((0x03000000&(data))>>24)
#define  IFD_108_agc_lock_th_get_agc_lock_exception(data)                        ((0x00100000&(data))>>20)
#define  IFD_108_agc_lock_th_get_agc_lock_err_sel(data)                          ((0x00010000&(data))>>16)
#define  IFD_108_agc_lock_th_get_agc_lock_th_out(data)                           ((0x0000FF00&(data))>>8)
#define  IFD_108_agc_lock_th_get_agc_lock_th(data)                               (0x000000FF&(data))

#define  IFD_108_agc_lock_status                                                 0x18032140
#define  IFD_108_agc_lock_status_reg_addr                                        "0xB8032140"
#define  IFD_108_agc_lock_status_reg                                             0xB8032140
#define  IFD_108_agc_lock_status_inst_addr                                       "0x0045"
#define  set_IFD_108_agc_lock_status_reg(data)                                   (*((volatile unsigned int*)IFD_108_agc_lock_status_reg)=data)
#define  get_IFD_108_agc_lock_status_reg                                         (*((volatile unsigned int*)IFD_108_agc_lock_status_reg))
#define  IFD_108_agc_lock_status_agc_fpga_pga_test_en_shift                      (8)
#define  IFD_108_agc_lock_status_agc_fine_force_shift                            (5)
#define  IFD_108_agc_lock_status_agc_fine_shift                                  (4)
#define  IFD_108_agc_lock_status_agc_lock_shift                                  (0)
#define  IFD_108_agc_lock_status_agc_fpga_pga_test_en_mask                       (0x00000100)
#define  IFD_108_agc_lock_status_agc_fine_force_mask                             (0x00000020)
#define  IFD_108_agc_lock_status_agc_fine_mask                                   (0x00000010)
#define  IFD_108_agc_lock_status_agc_lock_mask                                   (0x00000001)
#define  IFD_108_agc_lock_status_agc_fpga_pga_test_en(data)                      (0x00000100&((data)<<8))
#define  IFD_108_agc_lock_status_agc_fine_force(data)                            (0x00000020&((data)<<5))
#define  IFD_108_agc_lock_status_agc_fine(data)                                  (0x00000010&((data)<<4))
#define  IFD_108_agc_lock_status_agc_lock(data)                                  (0x00000001&(data))
#define  IFD_108_agc_lock_status_get_agc_fpga_pga_test_en(data)                  ((0x00000100&(data))>>8)
#define  IFD_108_agc_lock_status_get_agc_fine_force(data)                        ((0x00000020&(data))>>5)
#define  IFD_108_agc_lock_status_get_agc_fine(data)                              ((0x00000010&(data))>>4)
#define  IFD_108_agc_lock_status_get_agc_lock(data)                              (0x00000001&(data))

#define  IFD_108_agc_hsync_start                                                 0x18032144
#define  IFD_108_agc_hsync_start_reg_addr                                        "0xB8032144"
#define  IFD_108_agc_hsync_start_reg                                             0xB8032144
#define  IFD_108_agc_hsync_start_inst_addr                                       "0x0046"
#define  set_IFD_108_agc_hsync_start_reg(data)                                   (*((volatile unsigned int*)IFD_108_agc_hsync_start_reg)=data)
#define  get_IFD_108_agc_hsync_start_reg                                         (*((volatile unsigned int*)IFD_108_agc_hsync_start_reg))
#define  IFD_108_agc_hsync_start_agc_gate_delay_shift                            (16)
#define  IFD_108_agc_hsync_start_agc_hsync_start_shift                           (8)
#define  IFD_108_agc_hsync_start_agc_hsync_end_shift                             (0)
#define  IFD_108_agc_hsync_start_agc_gate_delay_mask                             (0x00FF0000)
#define  IFD_108_agc_hsync_start_agc_hsync_start_mask                            (0x0000FF00)
#define  IFD_108_agc_hsync_start_agc_hsync_end_mask                              (0x000000FF)
#define  IFD_108_agc_hsync_start_agc_gate_delay(data)                            (0x00FF0000&((data)<<16))
#define  IFD_108_agc_hsync_start_agc_hsync_start(data)                           (0x0000FF00&((data)<<8))
#define  IFD_108_agc_hsync_start_agc_hsync_end(data)                             (0x000000FF&(data))
#define  IFD_108_agc_hsync_start_get_agc_gate_delay(data)                        ((0x00FF0000&(data))>>16)
#define  IFD_108_agc_hsync_start_get_agc_hsync_start(data)                       ((0x0000FF00&(data))>>8)
#define  IFD_108_agc_hsync_start_get_agc_hsync_end(data)                         (0x000000FF&(data))

#define  IFD_108_agc_vsync_start1                                                0x18032148
#define  IFD_108_agc_vsync_start1_reg_addr                                       "0xB8032148"
#define  IFD_108_agc_vsync_start1_reg                                            0xB8032148
#define  IFD_108_agc_vsync_start1_inst_addr                                      "0x0047"
#define  set_IFD_108_agc_vsync_start1_reg(data)                                  (*((volatile unsigned int*)IFD_108_agc_vsync_start1_reg)=data)
#define  get_IFD_108_agc_vsync_start1_reg                                        (*((volatile unsigned int*)IFD_108_agc_vsync_start1_reg))
#define  IFD_108_agc_vsync_start1_agc_vsync_start_shift                          (16)
#define  IFD_108_agc_vsync_start1_agc_vsync_end_shift                            (0)
#define  IFD_108_agc_vsync_start1_agc_vsync_start_mask                           (0xFFFF0000)
#define  IFD_108_agc_vsync_start1_agc_vsync_end_mask                             (0x0000FFFF)
#define  IFD_108_agc_vsync_start1_agc_vsync_start(data)                          (0xFFFF0000&((data)<<16))
#define  IFD_108_agc_vsync_start1_agc_vsync_end(data)                            (0x0000FFFF&(data))
#define  IFD_108_agc_vsync_start1_get_agc_vsync_start(data)                      ((0xFFFF0000&(data))>>16)
#define  IFD_108_agc_vsync_start1_get_agc_vsync_end(data)                        (0x0000FFFF&(data))

#define  IFD_108_agc_peak_detect                                                 0x18032150
#define  IFD_108_agc_peak_detect_reg_addr                                        "0xB8032150"
#define  IFD_108_agc_peak_detect_reg                                             0xB8032150
#define  IFD_108_agc_peak_detect_inst_addr                                       "0x0048"
#define  set_IFD_108_agc_peak_detect_reg(data)                                   (*((volatile unsigned int*)IFD_108_agc_peak_detect_reg)=data)
#define  get_IFD_108_agc_peak_detect_reg                                         (*((volatile unsigned int*)IFD_108_agc_peak_detect_reg))
#define  IFD_108_agc_peak_detect_agc_peak_force_shift                            (20)
#define  IFD_108_agc_peak_detect_agc_peak_status_shift                           (16)
#define  IFD_108_agc_peak_detect_agc_peak_en_shift                               (12)
#define  IFD_108_agc_peak_detect_agc_peak_cnt_shift                              (0)
#define  IFD_108_agc_peak_detect_agc_peak_force_mask                             (0x00100000)
#define  IFD_108_agc_peak_detect_agc_peak_status_mask                            (0x00010000)
#define  IFD_108_agc_peak_detect_agc_peak_en_mask                                (0x00001000)
#define  IFD_108_agc_peak_detect_agc_peak_cnt_mask                               (0x00000FFF)
#define  IFD_108_agc_peak_detect_agc_peak_force(data)                            (0x00100000&((data)<<20))
#define  IFD_108_agc_peak_detect_agc_peak_status(data)                           (0x00010000&((data)<<16))
#define  IFD_108_agc_peak_detect_agc_peak_en(data)                               (0x00001000&((data)<<12))
#define  IFD_108_agc_peak_detect_agc_peak_cnt(data)                              (0x00000FFF&(data))
#define  IFD_108_agc_peak_detect_get_agc_peak_force(data)                        ((0x00100000&(data))>>20)
#define  IFD_108_agc_peak_detect_get_agc_peak_status(data)                       ((0x00010000&(data))>>16)
#define  IFD_108_agc_peak_detect_get_agc_peak_en(data)                           ((0x00001000&(data))>>12)
#define  IFD_108_agc_peak_detect_get_agc_peak_cnt(data)                          (0x00000FFF&(data))

#define  IFD_108_agc_peak_value                                                  0x18032154
#define  IFD_108_agc_peak_value_reg_addr                                         "0xB8032154"
#define  IFD_108_agc_peak_value_reg                                              0xB8032154
#define  IFD_108_agc_peak_value_inst_addr                                        "0x0049"
#define  set_IFD_108_agc_peak_value_reg(data)                                    (*((volatile unsigned int*)IFD_108_agc_peak_value_reg)=data)
#define  get_IFD_108_agc_peak_value_reg                                          (*((volatile unsigned int*)IFD_108_agc_peak_value_reg))
#define  IFD_108_agc_peak_value_agc_peak_value_shift                             (0)
#define  IFD_108_agc_peak_value_agc_peak_value_mask                              (0x000007FF)
#define  IFD_108_agc_peak_value_agc_peak_value(data)                             (0x000007FF&(data))
#define  IFD_108_agc_peak_value_get_agc_peak_value(data)                         (0x000007FF&(data))

#define  IFD_108_agc_max_status                                                  0x1803215C
#define  IFD_108_agc_max_status_reg_addr                                         "0xB803215C"
#define  IFD_108_agc_max_status_reg                                              0xB803215C
#define  IFD_108_agc_max_status_inst_addr                                        "0x004A"
#define  set_IFD_108_agc_max_status_reg(data)                                    (*((volatile unsigned int*)IFD_108_agc_max_status_reg)=data)
#define  get_IFD_108_agc_max_status_reg                                          (*((volatile unsigned int*)IFD_108_agc_max_status_reg))
#define  IFD_108_agc_max_status_agc_peak_max_shift                               (12)
#define  IFD_108_agc_max_status_agc_max_shift                                    (0)
#define  IFD_108_agc_max_status_agc_peak_max_mask                                (0x00FFF000)
#define  IFD_108_agc_max_status_agc_max_mask                                     (0x000007FF)
#define  IFD_108_agc_max_status_agc_peak_max(data)                               (0x00FFF000&((data)<<12))
#define  IFD_108_agc_max_status_agc_max(data)                                    (0x000007FF&(data))
#define  IFD_108_agc_max_status_get_agc_peak_max(data)                           ((0x00FFF000&(data))>>12)
#define  IFD_108_agc_max_status_get_agc_max(data)                                (0x000007FF&(data))

#define  IFD_108_agc_err0_status                                                 0x18032160
#define  IFD_108_agc_err0_status_reg_addr                                        "0xB8032160"
#define  IFD_108_agc_err0_status_reg                                             0xB8032160
#define  IFD_108_agc_err0_status_inst_addr                                       "0x004B"
#define  set_IFD_108_agc_err0_status_reg(data)                                   (*((volatile unsigned int*)IFD_108_agc_err0_status_reg)=data)
#define  get_IFD_108_agc_err0_status_reg                                         (*((volatile unsigned int*)IFD_108_agc_err0_status_reg))
#define  IFD_108_agc_err0_status_agc_peak_error_shift                            (12)
#define  IFD_108_agc_err0_status_agc_err_shift                                   (0)
#define  IFD_108_agc_err0_status_agc_peak_error_mask                             (0x00FFF000)
#define  IFD_108_agc_err0_status_agc_err_mask                                    (0x00000FFF)
#define  IFD_108_agc_err0_status_agc_peak_error(data)                            (0x00FFF000&((data)<<12))
#define  IFD_108_agc_err0_status_agc_err(data)                                   (0x00000FFF&(data))
#define  IFD_108_agc_err0_status_get_agc_peak_error(data)                        ((0x00FFF000&(data))>>12)
#define  IFD_108_agc_err0_status_get_agc_err(data)                               (0x00000FFF&(data))

#define  IFD_108_agc_acc3_status                                                 0x18032164
#define  IFD_108_agc_acc3_status_reg_addr                                        "0xB8032164"
#define  IFD_108_agc_acc3_status_reg                                             0xB8032164
#define  IFD_108_agc_acc3_status_inst_addr                                       "0x004C"
#define  set_IFD_108_agc_acc3_status_reg(data)                                   (*((volatile unsigned int*)IFD_108_agc_acc3_status_reg)=data)
#define  get_IFD_108_agc_acc3_status_reg                                         (*((volatile unsigned int*)IFD_108_agc_acc3_status_reg))
#define  IFD_108_agc_acc3_status_agc_acc3_shift                                  (0)
#define  IFD_108_agc_acc3_status_agc_acc3_mask                                   (0x00003FFF)
#define  IFD_108_agc_acc3_status_agc_acc3(data)                                  (0x00003FFF&(data))
#define  IFD_108_agc_acc3_status_get_agc_acc3(data)                              (0x00003FFF&(data))

#define  IFD_108_agc_if_status                                                   0x18032168
#define  IFD_108_agc_if_status_reg_addr                                          "0xB8032168"
#define  IFD_108_agc_if_status_reg                                               0xB8032168
#define  IFD_108_agc_if_status_inst_addr                                         "0x004D"
#define  set_IFD_108_agc_if_status_reg(data)                                     (*((volatile unsigned int*)IFD_108_agc_if_status_reg)=data)
#define  get_IFD_108_agc_if_status_reg                                           (*((volatile unsigned int*)IFD_108_agc_if_status_reg))
#define  IFD_108_agc_if_status_agc_if_mode_shift                                 (0)
#define  IFD_108_agc_if_status_agc_if_mode_mask                                  (0x00001FFF)
#define  IFD_108_agc_if_status_agc_if_mode(data)                                 (0x00001FFF&(data))
#define  IFD_108_agc_if_status_get_agc_if_mode(data)                             (0x00001FFF&(data))

#define  IFD_108_agc_rf_status                                                   0x1803216C
#define  IFD_108_agc_rf_status_reg_addr                                          "0xB803216C"
#define  IFD_108_agc_rf_status_reg                                               0xB803216C
#define  IFD_108_agc_rf_status_inst_addr                                         "0x004E"
#define  set_IFD_108_agc_rf_status_reg(data)                                     (*((volatile unsigned int*)IFD_108_agc_rf_status_reg)=data)
#define  get_IFD_108_agc_rf_status_reg                                           (*((volatile unsigned int*)IFD_108_agc_rf_status_reg))
#define  IFD_108_agc_rf_status_agc_rf_mode_shift                                 (0)
#define  IFD_108_agc_rf_status_agc_rf_mode_mask                                  (0x00001FFF)
#define  IFD_108_agc_rf_status_agc_rf_mode(data)                                 (0x00001FFF&(data))
#define  IFD_108_agc_rf_status_get_agc_rf_mode(data)                             (0x00001FFF&(data))

#define  IFD_108_agc_pga_1                                                       0x18032170
#define  IFD_108_agc_pga_1_reg_addr                                              "0xB8032170"
#define  IFD_108_agc_pga_1_reg                                                   0xB8032170
#define  IFD_108_agc_pga_1_inst_addr                                             "0x004F"
#define  set_IFD_108_agc_pga_1_reg(data)                                         (*((volatile unsigned int*)IFD_108_agc_pga_1_reg)=data)
#define  get_IFD_108_agc_pga_1_reg                                               (*((volatile unsigned int*)IFD_108_agc_pga_1_reg))
#define  IFD_108_agc_pga_1_agc_pga_fix_en_shift                                  (16)
#define  IFD_108_agc_pga_1_agc_pga_fix_shift                                     (0)
#define  IFD_108_agc_pga_1_agc_pga_fix_en_mask                                   (0x00010000)
#define  IFD_108_agc_pga_1_agc_pga_fix_mask                                      (0x000001FF)
#define  IFD_108_agc_pga_1_agc_pga_fix_en(data)                                  (0x00010000&((data)<<16))
#define  IFD_108_agc_pga_1_agc_pga_fix(data)                                     (0x000001FF&(data))
#define  IFD_108_agc_pga_1_get_agc_pga_fix_en(data)                              ((0x00010000&(data))>>16)
#define  IFD_108_agc_pga_1_get_agc_pga_fix(data)                                 (0x000001FF&(data))

#define  IFD_108_agc_rf_hasten                                                   0x18032174
#define  IFD_108_agc_rf_hasten_reg_addr                                          "0xB8032174"
#define  IFD_108_agc_rf_hasten_reg                                               0xB8032174
#define  IFD_108_agc_rf_hasten_inst_addr                                         "0x0050"
#define  set_IFD_108_agc_rf_hasten_reg(data)                                     (*((volatile unsigned int*)IFD_108_agc_rf_hasten_reg)=data)
#define  get_IFD_108_agc_rf_hasten_reg                                           (*((volatile unsigned int*)IFD_108_agc_rf_hasten_reg))
#define  IFD_108_agc_rf_hasten_agc_rf_hasten_en_shift                            (28)
#define  IFD_108_agc_rf_hasten_agc_ki_rf_hasten_shift                            (24)
#define  IFD_108_agc_rf_hasten_agc_max_cntl_rf_hasten_shift                      (12)
#define  IFD_108_agc_rf_hasten_agc_rf_hasten_thr_shift                           (0)
#define  IFD_108_agc_rf_hasten_agc_rf_hasten_en_mask                             (0x10000000)
#define  IFD_108_agc_rf_hasten_agc_ki_rf_hasten_mask                             (0x0F000000)
#define  IFD_108_agc_rf_hasten_agc_max_cntl_rf_hasten_mask                       (0x00FFF000)
#define  IFD_108_agc_rf_hasten_agc_rf_hasten_thr_mask                            (0x00000FFF)
#define  IFD_108_agc_rf_hasten_agc_rf_hasten_en(data)                            (0x10000000&((data)<<28))
#define  IFD_108_agc_rf_hasten_agc_ki_rf_hasten(data)                            (0x0F000000&((data)<<24))
#define  IFD_108_agc_rf_hasten_agc_max_cntl_rf_hasten(data)                      (0x00FFF000&((data)<<12))
#define  IFD_108_agc_rf_hasten_agc_rf_hasten_thr(data)                           (0x00000FFF&(data))
#define  IFD_108_agc_rf_hasten_get_agc_rf_hasten_en(data)                        ((0x10000000&(data))>>28)
#define  IFD_108_agc_rf_hasten_get_agc_ki_rf_hasten(data)                        ((0x0F000000&(data))>>24)
#define  IFD_108_agc_rf_hasten_get_agc_max_cntl_rf_hasten(data)                  ((0x00FFF000&(data))>>12)
#define  IFD_108_agc_rf_hasten_get_agc_rf_hasten_thr(data)                       (0x00000FFF&(data))

#define  IFD_108_agc_sep_rf_if                                                   0x18032178
#define  IFD_108_agc_sep_rf_if_reg_addr                                          "0xB8032178"
#define  IFD_108_agc_sep_rf_if_reg                                               0xB8032178
#define  IFD_108_agc_sep_rf_if_inst_addr                                         "0x0051"
#define  set_IFD_108_agc_sep_rf_if_reg(data)                                     (*((volatile unsigned int*)IFD_108_agc_sep_rf_if_reg)=data)
#define  get_IFD_108_agc_sep_rf_if_reg                                           (*((volatile unsigned int*)IFD_108_agc_sep_rf_if_reg))
#define  IFD_108_agc_sep_rf_if_agc_sep_rf_if_en_shift                            (12)
#define  IFD_108_agc_sep_rf_if_agc_if_kp_shift                                   (4)
#define  IFD_108_agc_sep_rf_if_agc_if_ki_shift                                   (0)
#define  IFD_108_agc_sep_rf_if_agc_sep_rf_if_en_mask                             (0x00001000)
#define  IFD_108_agc_sep_rf_if_agc_if_kp_mask                                    (0x000001F0)
#define  IFD_108_agc_sep_rf_if_agc_if_ki_mask                                    (0x0000000F)
#define  IFD_108_agc_sep_rf_if_agc_sep_rf_if_en(data)                            (0x00001000&((data)<<12))
#define  IFD_108_agc_sep_rf_if_agc_if_kp(data)                                   (0x000001F0&((data)<<4))
#define  IFD_108_agc_sep_rf_if_agc_if_ki(data)                                   (0x0000000F&(data))
#define  IFD_108_agc_sep_rf_if_get_agc_sep_rf_if_en(data)                        ((0x00001000&(data))>>12)
#define  IFD_108_agc_sep_rf_if_get_agc_if_kp(data)                               ((0x000001F0&(data))>>4)
#define  IFD_108_agc_sep_rf_if_get_agc_if_ki(data)                               (0x0000000F&(data))

#define  IFD_108_vtop_value                                                      0x18032180
#define  IFD_108_vtop_value_reg_addr                                             "0xB8032180"
#define  IFD_108_vtop_value_reg                                                  0xB8032180
#define  IFD_108_vtop_value_inst_addr                                            "0x0052"
#define  set_IFD_108_vtop_value_reg(data)                                        (*((volatile unsigned int*)IFD_108_vtop_value_reg)=data)
#define  get_IFD_108_vtop_value_reg                                              (*((volatile unsigned int*)IFD_108_vtop_value_reg))
#define  IFD_108_vtop_value_agc_vtop_shift                                       (0)
#define  IFD_108_vtop_value_agc_vtop_mask                                        (0x00001FFF)
#define  IFD_108_vtop_value_agc_vtop(data)                                       (0x00001FFF&(data))
#define  IFD_108_vtop_value_get_agc_vtop(data)                                   (0x00001FFF&(data))

#define  IFD_108_krf_value                                                       0x18032184
#define  IFD_108_krf_value_reg_addr                                              "0xB8032184"
#define  IFD_108_krf_value_reg                                                   0xB8032184
#define  IFD_108_krf_value_inst_addr                                             "0x0053"
#define  set_IFD_108_krf_value_reg(data)                                         (*((volatile unsigned int*)IFD_108_krf_value_reg)=data)
#define  get_IFD_108_krf_value_reg                                               (*((volatile unsigned int*)IFD_108_krf_value_reg))
#define  IFD_108_krf_value_agc_krf_shift                                         (0)
#define  IFD_108_krf_value_agc_krf_mask                                          (0x00003FFF)
#define  IFD_108_krf_value_agc_krf(data)                                         (0x00003FFF&(data))
#define  IFD_108_krf_value_get_agc_krf(data)                                     (0x00003FFF&(data))

#define  IFD_108_read_pga                                                        0x18032188
#define  IFD_108_read_pga_reg_addr                                               "0xB8032188"
#define  IFD_108_read_pga_reg                                                    0xB8032188
#define  IFD_108_read_pga_inst_addr                                              "0x0054"
#define  set_IFD_108_read_pga_reg(data)                                          (*((volatile unsigned int*)IFD_108_read_pga_reg)=data)
#define  get_IFD_108_read_pga_reg                                                (*((volatile unsigned int*)IFD_108_read_pga_reg))
#define  IFD_108_read_pga_pga_set_read_shift                                     (0)
#define  IFD_108_read_pga_pga_set_read_mask                                      (0x000001FF)
#define  IFD_108_read_pga_pga_set_read(data)                                     (0x000001FF&(data))
#define  IFD_108_read_pga_get_pga_set_read(data)                                 (0x000001FF&(data))

#define  IFD_108_agc_linebase_ctl                                                0x18032198
#define  IFD_108_agc_linebase_ctl_reg_addr                                       "0xB8032198"
#define  IFD_108_agc_linebase_ctl_reg                                            0xB8032198
#define  IFD_108_agc_linebase_ctl_inst_addr                                      "0x0055"
#define  set_IFD_108_agc_linebase_ctl_reg(data)                                  (*((volatile unsigned int*)IFD_108_agc_linebase_ctl_reg)=data)
#define  get_IFD_108_agc_linebase_ctl_reg                                        (*((volatile unsigned int*)IFD_108_agc_linebase_ctl_reg))
#define  IFD_108_agc_linebase_ctl_agc_loop2_hold_shift                           (20)
#define  IFD_108_agc_linebase_ctl_agc_loop2_clear_shift                          (16)
#define  IFD_108_agc_linebase_ctl_agc_loop2_hold_mask                            (0x00100000)
#define  IFD_108_agc_linebase_ctl_agc_loop2_clear_mask                           (0x00010000)
#define  IFD_108_agc_linebase_ctl_agc_loop2_hold(data)                           (0x00100000&((data)<<20))
#define  IFD_108_agc_linebase_ctl_agc_loop2_clear(data)                          (0x00010000&((data)<<16))
#define  IFD_108_agc_linebase_ctl_get_agc_loop2_hold(data)                       ((0x00100000&(data))>>20)
#define  IFD_108_agc_linebase_ctl_get_agc_loop2_clear(data)                      ((0x00010000&(data))>>16)

#define  IFD_108_agc_max2_cnt_1                                                  0x1803219C
#define  IFD_108_agc_max2_cnt_1_reg_addr                                         "0xB803219C"
#define  IFD_108_agc_max2_cnt_1_reg                                              0xB803219C
#define  IFD_108_agc_max2_cnt_1_inst_addr                                        "0x0056"
#define  set_IFD_108_agc_max2_cnt_1_reg(data)                                    (*((volatile unsigned int*)IFD_108_agc_max2_cnt_1_reg)=data)
#define  get_IFD_108_agc_max2_cnt_1_reg                                          (*((volatile unsigned int*)IFD_108_agc_max2_cnt_1_reg))
#define  IFD_108_agc_max2_cnt_1_agc_max2_cntl_unlock_shift                       (12)
#define  IFD_108_agc_max2_cnt_1_agc_max2_cntl_lock_shift                         (0)
#define  IFD_108_agc_max2_cnt_1_agc_max2_cntl_unlock_mask                        (0x00FFF000)
#define  IFD_108_agc_max2_cnt_1_agc_max2_cntl_lock_mask                          (0x00000FFF)
#define  IFD_108_agc_max2_cnt_1_agc_max2_cntl_unlock(data)                       (0x00FFF000&((data)<<12))
#define  IFD_108_agc_max2_cnt_1_agc_max2_cntl_lock(data)                         (0x00000FFF&(data))
#define  IFD_108_agc_max2_cnt_1_get_agc_max2_cntl_unlock(data)                   ((0x00FFF000&(data))>>12)
#define  IFD_108_agc_max2_cnt_1_get_agc_max2_cntl_lock(data)                     (0x00000FFF&(data))

#define  IFD_108_agc_in_kp_ki                                                    0x180321A0
#define  IFD_108_agc_in_kp_ki_reg_addr                                           "0xB80321A0"
#define  IFD_108_agc_in_kp_ki_reg                                                0xB80321A0
#define  IFD_108_agc_in_kp_ki_inst_addr                                          "0x0057"
#define  set_IFD_108_agc_in_kp_ki_reg(data)                                      (*((volatile unsigned int*)IFD_108_agc_in_kp_ki_reg)=data)
#define  get_IFD_108_agc_in_kp_ki_reg                                            (*((volatile unsigned int*)IFD_108_agc_in_kp_ki_reg))
#define  IFD_108_agc_in_kp_ki_agc_in_kp_shift_shift                              (20)
#define  IFD_108_agc_in_kp_ki_agc_in_ki_shift_shift                              (16)
#define  IFD_108_agc_in_kp_ki_agc_in_kp_shift                                    (8)
#define  IFD_108_agc_in_kp_ki_agc_in_ki_shift                                    (0)
#define  IFD_108_agc_in_kp_ki_agc_in_kp_shift_mask                               (0x00F00000)
#define  IFD_108_agc_in_kp_ki_agc_in_ki_shift_mask                               (0x000F0000)
#define  IFD_108_agc_in_kp_ki_agc_in_kp_mask                                     (0x00001F00)
#define  IFD_108_agc_in_kp_ki_agc_in_ki_mask                                     (0x0000001F)
#define  IFD_108_agc_in_kp_ki_agc_in_kp_shift(data)                              (0x00F00000&((data)<<20))
#define  IFD_108_agc_in_kp_ki_agc_in_ki_shift(data)                              (0x000F0000&((data)<<16))
#define  IFD_108_agc_in_kp_ki_agc_in_kp(data)                                    (0x00001F00&((data)<<8))
#define  IFD_108_agc_in_kp_ki_agc_in_ki(data)                                    (0x0000001F&(data))
#define  IFD_108_agc_in_kp_ki_get_agc_in_kp_shift(data)                          ((0x00F00000&(data))>>20)
#define  IFD_108_agc_in_kp_ki_get_agc_in_ki_shift(data)                          ((0x000F0000&(data))>>16)
#define  IFD_108_agc_in_kp_ki_get_agc_in_kp(data)                                ((0x00001F00&(data))>>8)
#define  IFD_108_agc_in_kp_ki_get_agc_in_ki(data)                                (0x0000001F&(data))

#define  IFD_108_agc_in_max_min                                                  0x180321A4
#define  IFD_108_agc_in_max_min_reg_addr                                         "0xB80321A4"
#define  IFD_108_agc_in_max_min_reg                                              0xB80321A4
#define  IFD_108_agc_in_max_min_inst_addr                                        "0x0058"
#define  set_IFD_108_agc_in_max_min_reg(data)                                    (*((volatile unsigned int*)IFD_108_agc_in_max_min_reg)=data)
#define  get_IFD_108_agc_in_max_min_reg                                          (*((volatile unsigned int*)IFD_108_agc_in_max_min_reg))
#define  IFD_108_agc_in_max_min_agc_in_max_shift                                 (16)
#define  IFD_108_agc_in_max_min_agc_in_min_shift                                 (0)
#define  IFD_108_agc_in_max_min_agc_in_max_mask                                  (0xFFFF0000)
#define  IFD_108_agc_in_max_min_agc_in_min_mask                                  (0x0000FFFF)
#define  IFD_108_agc_in_max_min_agc_in_max(data)                                 (0xFFFF0000&((data)<<16))
#define  IFD_108_agc_in_max_min_agc_in_min(data)                                 (0x0000FFFF&(data))
#define  IFD_108_agc_in_max_min_get_agc_in_max(data)                             ((0xFFFF0000&(data))>>16)
#define  IFD_108_agc_in_max_min_get_agc_in_min(data)                             (0x0000FFFF&(data))

#define  IFD_108_agc_max2_limit_cnt_1                                            0x180321AC
#define  IFD_108_agc_max2_limit_cnt_1_reg_addr                                   "0xB80321AC"
#define  IFD_108_agc_max2_limit_cnt_1_reg                                        0xB80321AC
#define  IFD_108_agc_max2_limit_cnt_1_inst_addr                                  "0x0059"
#define  set_IFD_108_agc_max2_limit_cnt_1_reg(data)                              (*((volatile unsigned int*)IFD_108_agc_max2_limit_cnt_1_reg)=data)
#define  get_IFD_108_agc_max2_limit_cnt_1_reg                                    (*((volatile unsigned int*)IFD_108_agc_max2_limit_cnt_1_reg))
#define  IFD_108_agc_max2_limit_cnt_1_agc_max2_count_limit_shift                 (4)
#define  IFD_108_agc_max2_limit_cnt_1_agc_max2_count_limit_en_shift              (0)
#define  IFD_108_agc_max2_limit_cnt_1_agc_max2_count_limit_mask                  (0x0000FFF0)
#define  IFD_108_agc_max2_limit_cnt_1_agc_max2_count_limit_en_mask               (0x00000001)
#define  IFD_108_agc_max2_limit_cnt_1_agc_max2_count_limit(data)                 (0x0000FFF0&((data)<<4))
#define  IFD_108_agc_max2_limit_cnt_1_agc_max2_count_limit_en(data)              (0x00000001&(data))
#define  IFD_108_agc_max2_limit_cnt_1_get_agc_max2_count_limit(data)             ((0x0000FFF0&(data))>>4)
#define  IFD_108_agc_max2_limit_cnt_1_get_agc_max2_count_limit_en(data)          (0x00000001&(data))

#define  IFD_108_agc_looop2_err                                                  0x180321B0
#define  IFD_108_agc_looop2_err_reg_addr                                         "0xB80321B0"
#define  IFD_108_agc_looop2_err_reg                                              0xB80321B0
#define  IFD_108_agc_looop2_err_inst_addr                                        "0x005A"
#define  set_IFD_108_agc_looop2_err_reg(data)                                    (*((volatile unsigned int*)IFD_108_agc_looop2_err_reg)=data)
#define  get_IFD_108_agc_looop2_err_reg                                          (*((volatile unsigned int*)IFD_108_agc_looop2_err_reg))
#define  IFD_108_agc_looop2_err_loop2_err_shift                                  (0)
#define  IFD_108_agc_looop2_err_loop2_err_mask                                   (0x00000FFF)
#define  IFD_108_agc_looop2_err_loop2_err(data)                                  (0x00000FFF&(data))
#define  IFD_108_agc_looop2_err_get_loop2_err(data)                              (0x00000FFF&(data))

#define  IFD_108_agc_inner_status                                                0x180321B4
#define  IFD_108_agc_inner_status_reg_addr                                       "0xB80321B4"
#define  IFD_108_agc_inner_status_reg                                            0xB80321B4
#define  IFD_108_agc_inner_status_inst_addr                                      "0x005B"
#define  set_IFD_108_agc_inner_status_reg(data)                                  (*((volatile unsigned int*)IFD_108_agc_inner_status_reg)=data)
#define  get_IFD_108_agc_inner_status_reg                                        (*((volatile unsigned int*)IFD_108_agc_inner_status_reg))
#define  IFD_108_agc_inner_status_agc_inner1_shift                               (16)
#define  IFD_108_agc_inner_status_agc_inner2_shift                               (0)
#define  IFD_108_agc_inner_status_agc_inner1_mask                                (0xFFFF0000)
#define  IFD_108_agc_inner_status_agc_inner2_mask                                (0x0000FFFF)
#define  IFD_108_agc_inner_status_agc_inner1(data)                               (0xFFFF0000&((data)<<16))
#define  IFD_108_agc_inner_status_agc_inner2(data)                               (0x0000FFFF&(data))
#define  IFD_108_agc_inner_status_get_agc_inner1(data)                           ((0xFFFF0000&(data))>>16)
#define  IFD_108_agc_inner_status_get_agc_inner2(data)                           (0x0000FFFF&(data))

#define  IFD_108_loop2_kp_ki_err                                                 0x180321B8
#define  IFD_108_loop2_kp_ki_err_reg_addr                                        "0xB80321B8"
#define  IFD_108_loop2_kp_ki_err_reg                                             0xB80321B8
#define  IFD_108_loop2_kp_ki_err_inst_addr                                       "0x005C"
#define  set_IFD_108_loop2_kp_ki_err_reg(data)                                   (*((volatile unsigned int*)IFD_108_loop2_kp_ki_err_reg)=data)
#define  get_IFD_108_loop2_kp_ki_err_reg                                         (*((volatile unsigned int*)IFD_108_loop2_kp_ki_err_reg))
#define  IFD_108_loop2_kp_ki_err_loop2_err_kp_shift                              (16)
#define  IFD_108_loop2_kp_ki_err_loop2_err_ki_shift                              (0)
#define  IFD_108_loop2_kp_ki_err_loop2_err_kp_mask                               (0xFFFF0000)
#define  IFD_108_loop2_kp_ki_err_loop2_err_ki_mask                               (0x0000FFFF)
#define  IFD_108_loop2_kp_ki_err_loop2_err_kp(data)                              (0xFFFF0000&((data)<<16))
#define  IFD_108_loop2_kp_ki_err_loop2_err_ki(data)                              (0x0000FFFF&(data))
#define  IFD_108_loop2_kp_ki_err_get_loop2_err_kp(data)                          ((0xFFFF0000&(data))>>16)
#define  IFD_108_loop2_kp_ki_err_get_loop2_err_ki(data)                          (0x0000FFFF&(data))

#define  IFD_108_read_loop2_max                                                  0x180321BC
#define  IFD_108_read_loop2_max_reg_addr                                         "0xB80321BC"
#define  IFD_108_read_loop2_max_reg                                              0xB80321BC
#define  IFD_108_read_loop2_max_inst_addr                                        "0x005D"
#define  set_IFD_108_read_loop2_max_reg(data)                                    (*((volatile unsigned int*)IFD_108_read_loop2_max_reg)=data)
#define  get_IFD_108_read_loop2_max_reg                                          (*((volatile unsigned int*)IFD_108_read_loop2_max_reg))
#define  IFD_108_read_loop2_max_agc_lpf_out_dgained_shift                        (12)
#define  IFD_108_read_loop2_max_agc_max2_out_shift                               (0)
#define  IFD_108_read_loop2_max_agc_lpf_out_dgained_mask                         (0x007FF000)
#define  IFD_108_read_loop2_max_agc_max2_out_mask                                (0x000007FF)
#define  IFD_108_read_loop2_max_agc_lpf_out_dgained(data)                        (0x007FF000&((data)<<12))
#define  IFD_108_read_loop2_max_agc_max2_out(data)                               (0x000007FF&(data))
#define  IFD_108_read_loop2_max_get_agc_lpf_out_dgained(data)                    ((0x007FF000&(data))>>12)
#define  IFD_108_read_loop2_max_get_agc_max2_out(data)                           (0x000007FF&(data))

#define  IFD_108_agc_peak2_detect                                                0x180321C0
#define  IFD_108_agc_peak2_detect_reg_addr                                       "0xB80321C0"
#define  IFD_108_agc_peak2_detect_reg                                            0xB80321C0
#define  IFD_108_agc_peak2_detect_inst_addr                                      "0x005E"
#define  set_IFD_108_agc_peak2_detect_reg(data)                                  (*((volatile unsigned int*)IFD_108_agc_peak2_detect_reg)=data)
#define  get_IFD_108_agc_peak2_detect_reg                                        (*((volatile unsigned int*)IFD_108_agc_peak2_detect_reg))
#define  IFD_108_agc_peak2_detect_agc_adaptive_peak2_en_shift                    (28)
#define  IFD_108_agc_peak2_detect_agc_peak2_force_shift                          (20)
#define  IFD_108_agc_peak2_detect_agc_peak2_status_shift                         (16)
#define  IFD_108_agc_peak2_detect_agc_peak2_en_shift                             (12)
#define  IFD_108_agc_peak2_detect_agc_peak2_cnt_shift                            (0)
#define  IFD_108_agc_peak2_detect_agc_adaptive_peak2_en_mask                     (0x10000000)
#define  IFD_108_agc_peak2_detect_agc_peak2_force_mask                           (0x00100000)
#define  IFD_108_agc_peak2_detect_agc_peak2_status_mask                          (0x00010000)
#define  IFD_108_agc_peak2_detect_agc_peak2_en_mask                              (0x00001000)
#define  IFD_108_agc_peak2_detect_agc_peak2_cnt_mask                             (0x00000FFF)
#define  IFD_108_agc_peak2_detect_agc_adaptive_peak2_en(data)                    (0x10000000&((data)<<28))
#define  IFD_108_agc_peak2_detect_agc_peak2_force(data)                          (0x00100000&((data)<<20))
#define  IFD_108_agc_peak2_detect_agc_peak2_status(data)                         (0x00010000&((data)<<16))
#define  IFD_108_agc_peak2_detect_agc_peak2_en(data)                             (0x00001000&((data)<<12))
#define  IFD_108_agc_peak2_detect_agc_peak2_cnt(data)                            (0x00000FFF&(data))
#define  IFD_108_agc_peak2_detect_get_agc_adaptive_peak2_en(data)                ((0x10000000&(data))>>28)
#define  IFD_108_agc_peak2_detect_get_agc_peak2_force(data)                      ((0x00100000&(data))>>20)
#define  IFD_108_agc_peak2_detect_get_agc_peak2_status(data)                     ((0x00010000&(data))>>16)
#define  IFD_108_agc_peak2_detect_get_agc_peak2_en(data)                         ((0x00001000&(data))>>12)
#define  IFD_108_agc_peak2_detect_get_agc_peak2_cnt(data)                        (0x00000FFF&(data))

#define  IFD_108_agc_peak2_status                                                0x180321C8
#define  IFD_108_agc_peak2_status_reg_addr                                       "0xB80321C8"
#define  IFD_108_agc_peak2_status_reg                                            0xB80321C8
#define  IFD_108_agc_peak2_status_inst_addr                                      "0x005F"
#define  set_IFD_108_agc_peak2_status_reg(data)                                  (*((volatile unsigned int*)IFD_108_agc_peak2_status_reg)=data)
#define  get_IFD_108_agc_peak2_status_reg                                        (*((volatile unsigned int*)IFD_108_agc_peak2_status_reg))
#define  IFD_108_agc_peak2_status_agc_peak2_max_shift                            (16)
#define  IFD_108_agc_peak2_status_agc_peak2_error_shift                          (0)
#define  IFD_108_agc_peak2_status_agc_peak2_max_mask                             (0x0FFF0000)
#define  IFD_108_agc_peak2_status_agc_peak2_error_mask                           (0x00000FFF)
#define  IFD_108_agc_peak2_status_agc_peak2_max(data)                            (0x0FFF0000&((data)<<16))
#define  IFD_108_agc_peak2_status_agc_peak2_error(data)                          (0x00000FFF&(data))
#define  IFD_108_agc_peak2_status_get_agc_peak2_max(data)                        ((0x0FFF0000&(data))>>16)
#define  IFD_108_agc_peak2_status_get_agc_peak2_error(data)                      (0x00000FFF&(data))

#define  IFD_108_agc_loop2_cntl                                                  0x180321D0
#define  IFD_108_agc_loop2_cntl_reg_addr                                         "0xB80321D0"
#define  IFD_108_agc_loop2_cntl_reg                                              0xB80321D0
#define  IFD_108_agc_loop2_cntl_inst_addr                                        "0x0060"
#define  set_IFD_108_agc_loop2_cntl_reg(data)                                    (*((volatile unsigned int*)IFD_108_agc_loop2_cntl_reg)=data)
#define  get_IFD_108_agc_loop2_cntl_reg                                          (*((volatile unsigned int*)IFD_108_agc_loop2_cntl_reg))
#define  IFD_108_agc_loop2_cntl_agc_loop2_downsample_sel_shift                   (0)
#define  IFD_108_agc_loop2_cntl_agc_loop2_downsample_sel_mask                    (0x00000FFF)
#define  IFD_108_agc_loop2_cntl_agc_loop2_downsample_sel(data)                   (0x00000FFF&(data))
#define  IFD_108_agc_loop2_cntl_get_agc_loop2_downsample_sel(data)               (0x00000FFF&(data))

#define  IFD_108_sigma_delta_cntl                                                0x180321D4
#define  IFD_108_sigma_delta_cntl_reg_addr                                       "0xB80321D4"
#define  IFD_108_sigma_delta_cntl_reg                                            0xB80321D4
#define  IFD_108_sigma_delta_cntl_inst_addr                                      "0x0061"
#define  set_IFD_108_sigma_delta_cntl_reg(data)                                  (*((volatile unsigned int*)IFD_108_sigma_delta_cntl_reg)=data)
#define  get_IFD_108_sigma_delta_cntl_reg                                        (*((volatile unsigned int*)IFD_108_sigma_delta_cntl_reg))
#define  IFD_108_sigma_delta_cntl_agc_if_pad_control_shift                       (8)
#define  IFD_108_sigma_delta_cntl_agc_rf_pad_control_shift                       (4)
#define  IFD_108_sigma_delta_cntl_agc_sigma_delta_dnsel_shift                    (0)
#define  IFD_108_sigma_delta_cntl_agc_if_pad_control_mask                        (0x00000100)
#define  IFD_108_sigma_delta_cntl_agc_rf_pad_control_mask                        (0x00000010)
#define  IFD_108_sigma_delta_cntl_agc_sigma_delta_dnsel_mask                     (0x0000000F)
#define  IFD_108_sigma_delta_cntl_agc_if_pad_control(data)                       (0x00000100&((data)<<8))
#define  IFD_108_sigma_delta_cntl_agc_rf_pad_control(data)                       (0x00000010&((data)<<4))
#define  IFD_108_sigma_delta_cntl_agc_sigma_delta_dnsel(data)                    (0x0000000F&(data))
#define  IFD_108_sigma_delta_cntl_get_agc_if_pad_control(data)                   ((0x00000100&(data))>>8)
#define  IFD_108_sigma_delta_cntl_get_agc_rf_pad_control(data)                   ((0x00000010&(data))>>4)
#define  IFD_108_sigma_delta_cntl_get_agc_sigma_delta_dnsel(data)                (0x0000000F&(data))

#define  IFD_108_agc_interrupt_thd                                               0x180321D8
#define  IFD_108_agc_interrupt_thd_reg_addr                                      "0xB80321D8"
#define  IFD_108_agc_interrupt_thd_reg                                           0xB80321D8
#define  IFD_108_agc_interrupt_thd_inst_addr                                     "0x0062"
#define  set_IFD_108_agc_interrupt_thd_reg(data)                                 (*((volatile unsigned int*)IFD_108_agc_interrupt_thd_reg)=data)
#define  get_IFD_108_agc_interrupt_thd_reg                                       (*((volatile unsigned int*)IFD_108_agc_interrupt_thd_reg))
#define  IFD_108_agc_interrupt_thd_rf_agc_interrupt_thd_shift                    (0)
#define  IFD_108_agc_interrupt_thd_rf_agc_interrupt_thd_mask                     (0x00001FFF)
#define  IFD_108_agc_interrupt_thd_rf_agc_interrupt_thd(data)                    (0x00001FFF&(data))
#define  IFD_108_agc_interrupt_thd_get_rf_agc_interrupt_thd(data)                (0x00001FFF&(data))

#define  IFD_108_agc_2step_en                                                    0x180321DC
#define  IFD_108_agc_2step_en_reg_addr                                           "0xB80321DC"
#define  IFD_108_agc_2step_en_reg                                                0xB80321DC
#define  IFD_108_agc_2step_en_inst_addr                                          "0x0063"
#define  set_IFD_108_agc_2step_en_reg(data)                                      (*((volatile unsigned int*)IFD_108_agc_2step_en_reg)=data)
#define  get_IFD_108_agc_2step_en_reg                                            (*((volatile unsigned int*)IFD_108_agc_2step_en_reg))
#define  IFD_108_agc_2step_en_agc_2step_en_shift                                 (0)
#define  IFD_108_agc_2step_en_agc_2step_en_mask                                  (0x00000001)
#define  IFD_108_agc_2step_en_agc_2step_en(data)                                 (0x00000001&(data))
#define  IFD_108_agc_2step_en_get_agc_2step_en(data)                             (0x00000001&(data))

#define  IFD_108_agc_dgain_step                                                  0x180321E0
#define  IFD_108_agc_dgain_step_reg_addr                                         "0xB80321E0"
#define  IFD_108_agc_dgain_step_reg                                              0xB80321E0
#define  IFD_108_agc_dgain_step_inst_addr                                        "0x0064"
#define  set_IFD_108_agc_dgain_step_reg(data)                                    (*((volatile unsigned int*)IFD_108_agc_dgain_step_reg)=data)
#define  get_IFD_108_agc_dgain_step_reg                                          (*((volatile unsigned int*)IFD_108_agc_dgain_step_reg))
#define  IFD_108_agc_dgain_step_agc_dgain_up_step_shift                          (16)
#define  IFD_108_agc_dgain_step_agc_dgain_down_step_shift                        (0)
#define  IFD_108_agc_dgain_step_agc_dgain_up_step_mask                           (0xFFFF0000)
#define  IFD_108_agc_dgain_step_agc_dgain_down_step_mask                         (0x0000FFFF)
#define  IFD_108_agc_dgain_step_agc_dgain_up_step(data)                          (0xFFFF0000&((data)<<16))
#define  IFD_108_agc_dgain_step_agc_dgain_down_step(data)                        (0x0000FFFF&(data))
#define  IFD_108_agc_dgain_step_get_agc_dgain_up_step(data)                      ((0xFFFF0000&(data))>>16)
#define  IFD_108_agc_dgain_step_get_agc_dgain_down_step(data)                    (0x0000FFFF&(data))

#define  IFD_108_agc_dgain_thr                                                   0x180321E4
#define  IFD_108_agc_dgain_thr_reg_addr                                          "0xB80321E4"
#define  IFD_108_agc_dgain_thr_reg                                               0xB80321E4
#define  IFD_108_agc_dgain_thr_inst_addr                                         "0x0065"
#define  set_IFD_108_agc_dgain_thr_reg(data)                                     (*((volatile unsigned int*)IFD_108_agc_dgain_thr_reg)=data)
#define  get_IFD_108_agc_dgain_thr_reg                                           (*((volatile unsigned int*)IFD_108_agc_dgain_thr_reg))
#define  IFD_108_agc_dgain_thr_agc_dgain_low_thr_shift                           (16)
#define  IFD_108_agc_dgain_thr_agc_dgain_up_thr_shift                            (0)
#define  IFD_108_agc_dgain_thr_agc_dgain_low_thr_mask                            (0xFFFF0000)
#define  IFD_108_agc_dgain_thr_agc_dgain_up_thr_mask                             (0x0000FFFF)
#define  IFD_108_agc_dgain_thr_agc_dgain_low_thr(data)                           (0xFFFF0000&((data)<<16))
#define  IFD_108_agc_dgain_thr_agc_dgain_up_thr(data)                            (0x0000FFFF&(data))
#define  IFD_108_agc_dgain_thr_get_agc_dgain_low_thr(data)                       ((0xFFFF0000&(data))>>16)
#define  IFD_108_agc_dgain_thr_get_agc_dgain_up_thr(data)                        (0x0000FFFF&(data))

#define  IFD_108_agc_dgain_to_pga                                                0x180321E8
#define  IFD_108_agc_dgain_to_pga_reg_addr                                       "0xB80321E8"
#define  IFD_108_agc_dgain_to_pga_reg                                            0xB80321E8
#define  IFD_108_agc_dgain_to_pga_inst_addr                                      "0x0066"
#define  set_IFD_108_agc_dgain_to_pga_reg(data)                                  (*((volatile unsigned int*)IFD_108_agc_dgain_to_pga_reg)=data)
#define  get_IFD_108_agc_dgain_to_pga_reg                                        (*((volatile unsigned int*)IFD_108_agc_dgain_to_pga_reg))
#define  IFD_108_agc_dgain_to_pga_agc_dgain_min_pga_shift                        (24)
#define  IFD_108_agc_dgain_to_pga_agc_step_num_pga_shift                         (20)
#define  IFD_108_agc_dgain_to_pga_agc_settle_time_pga_shift                      (0)
#define  IFD_108_agc_dgain_to_pga_agc_dgain_min_pga_mask                         (0xFF000000)
#define  IFD_108_agc_dgain_to_pga_agc_step_num_pga_mask                          (0x00F00000)
#define  IFD_108_agc_dgain_to_pga_agc_settle_time_pga_mask                       (0x000FFFFF)
#define  IFD_108_agc_dgain_to_pga_agc_dgain_min_pga(data)                        (0xFF000000&((data)<<24))
#define  IFD_108_agc_dgain_to_pga_agc_step_num_pga(data)                         (0x00F00000&((data)<<20))
#define  IFD_108_agc_dgain_to_pga_agc_settle_time_pga(data)                      (0x000FFFFF&(data))
#define  IFD_108_agc_dgain_to_pga_get_agc_dgain_min_pga(data)                    ((0xFF000000&(data))>>24)
#define  IFD_108_agc_dgain_to_pga_get_agc_step_num_pga(data)                     ((0x00F00000&(data))>>20)
#define  IFD_108_agc_dgain_to_pga_get_agc_settle_time_pga(data)                  (0x000FFFFF&(data))

#define  IFD_108_agc_dgain_virtual_pga_hsync_gate                                0x180321EC
#define  IFD_108_agc_dgain_virtual_pga_hsync_gate_reg_addr                       "0xB80321EC"
#define  IFD_108_agc_dgain_virtual_pga_hsync_gate_reg                            0xB80321EC
#define  IFD_108_agc_dgain_virtual_pga_hsync_gate_inst_addr                      "0x0067"
#define  set_IFD_108_agc_dgain_virtual_pga_hsync_gate_reg(data)                  (*((volatile unsigned int*)IFD_108_agc_dgain_virtual_pga_hsync_gate_reg)=data)
#define  get_IFD_108_agc_dgain_virtual_pga_hsync_gate_reg                        (*((volatile unsigned int*)IFD_108_agc_dgain_virtual_pga_hsync_gate_reg))
#define  IFD_108_agc_dgain_virtual_pga_hsync_gate_agc_max_if_gain_count_shift    (16)
#define  IFD_108_agc_dgain_virtual_pga_hsync_gate_agc_max_if_gain_count_mask     (0x00FF0000)
#define  IFD_108_agc_dgain_virtual_pga_hsync_gate_agc_max_if_gain_count(data)    (0x00FF0000&((data)<<16))
#define  IFD_108_agc_dgain_virtual_pga_hsync_gate_get_agc_max_if_gain_count(data) ((0x00FF0000&(data))>>16)

#define  IFD_108_agc_fine_tune_down_sample                                       0x180321F4
#define  IFD_108_agc_fine_tune_down_sample_reg_addr                              "0xB80321F4"
#define  IFD_108_agc_fine_tune_down_sample_reg                                   0xB80321F4
#define  IFD_108_agc_fine_tune_down_sample_inst_addr                             "0x0068"
#define  set_IFD_108_agc_fine_tune_down_sample_reg(data)                         (*((volatile unsigned int*)IFD_108_agc_fine_tune_down_sample_reg)=data)
#define  get_IFD_108_agc_fine_tune_down_sample_reg                               (*((volatile unsigned int*)IFD_108_agc_fine_tune_down_sample_reg))
#define  IFD_108_agc_fine_tune_down_sample_fine_tune2_down_sample_en_shift       (28)
#define  IFD_108_agc_fine_tune_down_sample_fine_tune2_down_sample_shift          (16)
#define  IFD_108_agc_fine_tune_down_sample_fine_tune_down_sample_en_shift        (12)
#define  IFD_108_agc_fine_tune_down_sample_fine_tune_down_sample_shift           (0)
#define  IFD_108_agc_fine_tune_down_sample_fine_tune2_down_sample_en_mask        (0x10000000)
#define  IFD_108_agc_fine_tune_down_sample_fine_tune2_down_sample_mask           (0x0FFF0000)
#define  IFD_108_agc_fine_tune_down_sample_fine_tune_down_sample_en_mask         (0x00001000)
#define  IFD_108_agc_fine_tune_down_sample_fine_tune_down_sample_mask            (0x00000FFF)
#define  IFD_108_agc_fine_tune_down_sample_fine_tune2_down_sample_en(data)       (0x10000000&((data)<<28))
#define  IFD_108_agc_fine_tune_down_sample_fine_tune2_down_sample(data)          (0x0FFF0000&((data)<<16))
#define  IFD_108_agc_fine_tune_down_sample_fine_tune_down_sample_en(data)        (0x00001000&((data)<<12))
#define  IFD_108_agc_fine_tune_down_sample_fine_tune_down_sample(data)           (0x00000FFF&(data))
#define  IFD_108_agc_fine_tune_down_sample_get_fine_tune2_down_sample_en(data)   ((0x10000000&(data))>>28)
#define  IFD_108_agc_fine_tune_down_sample_get_fine_tune2_down_sample(data)      ((0x0FFF0000&(data))>>16)
#define  IFD_108_agc_fine_tune_down_sample_get_fine_tune_down_sample_en(data)    ((0x00001000&(data))>>12)
#define  IFD_108_agc_fine_tune_down_sample_get_fine_tune_down_sample(data)       (0x00000FFF&(data))

#define  IFD_108_agc_2step_status                                                0x180321F8
#define  IFD_108_agc_2step_status_reg_addr                                       "0xB80321F8"
#define  IFD_108_agc_2step_status_reg                                            0xB80321F8
#define  IFD_108_agc_2step_status_inst_addr                                      "0x0069"
#define  set_IFD_108_agc_2step_status_reg(data)                                  (*((volatile unsigned int*)IFD_108_agc_2step_status_reg)=data)
#define  get_IFD_108_agc_2step_status_reg                                        (*((volatile unsigned int*)IFD_108_agc_2step_status_reg))
#define  IFD_108_agc_2step_status_if_min_shift                                   (24)
#define  IFD_108_agc_2step_status_rf_full_shift                                  (20)
#define  IFD_108_agc_2step_status_if_lower_shift                                 (16)
#define  IFD_108_agc_2step_status_if_raise_shift                                 (12)
#define  IFD_108_agc_2step_status_if_gain_count_shift                            (0)
#define  IFD_108_agc_2step_status_if_min_mask                                    (0x01000000)
#define  IFD_108_agc_2step_status_rf_full_mask                                   (0x00100000)
#define  IFD_108_agc_2step_status_if_lower_mask                                  (0x00010000)
#define  IFD_108_agc_2step_status_if_raise_mask                                  (0x00001000)
#define  IFD_108_agc_2step_status_if_gain_count_mask                             (0x000001FF)
#define  IFD_108_agc_2step_status_if_min(data)                                   (0x01000000&((data)<<24))
#define  IFD_108_agc_2step_status_rf_full(data)                                  (0x00100000&((data)<<20))
#define  IFD_108_agc_2step_status_if_lower(data)                                 (0x00010000&((data)<<16))
#define  IFD_108_agc_2step_status_if_raise(data)                                 (0x00001000&((data)<<12))
#define  IFD_108_agc_2step_status_if_gain_count(data)                            (0x000001FF&(data))
#define  IFD_108_agc_2step_status_get_if_min(data)                               ((0x01000000&(data))>>24)
#define  IFD_108_agc_2step_status_get_rf_full(data)                              ((0x00100000&(data))>>20)
#define  IFD_108_agc_2step_status_get_if_lower(data)                             ((0x00010000&(data))>>16)
#define  IFD_108_agc_2step_status_get_if_raise(data)                             ((0x00001000&(data))>>12)
#define  IFD_108_agc_2step_status_get_if_gain_count(data)                        (0x000001FF&(data))

#define  IFD_108_agc_gain_avg_ctrl                                               0x18032200
#define  IFD_108_agc_gain_avg_ctrl_reg_addr                                      "0xB8032200"
#define  IFD_108_agc_gain_avg_ctrl_reg                                           0xB8032200
#define  IFD_108_agc_gain_avg_ctrl_inst_addr                                     "0x006A"
#define  set_IFD_108_agc_gain_avg_ctrl_reg(data)                                 (*((volatile unsigned int*)IFD_108_agc_gain_avg_ctrl_reg)=data)
#define  get_IFD_108_agc_gain_avg_ctrl_reg                                       (*((volatile unsigned int*)IFD_108_agc_gain_avg_ctrl_reg))
#define  IFD_108_agc_gain_avg_ctrl_agc_gain_avg_interval_shift                   (16)
#define  IFD_108_agc_gain_avg_ctrl_agc_gain_avg_sel_shift                        (8)
#define  IFD_108_agc_gain_avg_ctrl_agc_gain_avg_length_shift                     (0)
#define  IFD_108_agc_gain_avg_ctrl_agc_gain_avg_interval_mask                    (0x0FFF0000)
#define  IFD_108_agc_gain_avg_ctrl_agc_gain_avg_sel_mask                         (0x00000100)
#define  IFD_108_agc_gain_avg_ctrl_agc_gain_avg_length_mask                      (0x00000007)
#define  IFD_108_agc_gain_avg_ctrl_agc_gain_avg_interval(data)                   (0x0FFF0000&((data)<<16))
#define  IFD_108_agc_gain_avg_ctrl_agc_gain_avg_sel(data)                        (0x00000100&((data)<<8))
#define  IFD_108_agc_gain_avg_ctrl_agc_gain_avg_length(data)                     (0x00000007&(data))
#define  IFD_108_agc_gain_avg_ctrl_get_agc_gain_avg_interval(data)               ((0x0FFF0000&(data))>>16)
#define  IFD_108_agc_gain_avg_ctrl_get_agc_gain_avg_sel(data)                    ((0x00000100&(data))>>8)
#define  IFD_108_agc_gain_avg_ctrl_get_agc_gain_avg_length(data)                 (0x00000007&(data))

#define  IFD_108_agc_gain_status                                                 0x18032204
#define  IFD_108_agc_gain_status_reg_addr                                        "0xB8032204"
#define  IFD_108_agc_gain_status_reg                                             0xB8032204
#define  IFD_108_agc_gain_status_inst_addr                                       "0x006B"
#define  set_IFD_108_agc_gain_status_reg(data)                                   (*((volatile unsigned int*)IFD_108_agc_gain_status_reg)=data)
#define  get_IFD_108_agc_gain_status_reg                                         (*((volatile unsigned int*)IFD_108_agc_gain_status_reg))
#define  IFD_108_agc_gain_status_agc_gain_var_shift                              (16)
#define  IFD_108_agc_gain_status_agc_gain_mean_shift                             (0)
#define  IFD_108_agc_gain_status_agc_gain_var_mask                               (0xFFFF0000)
#define  IFD_108_agc_gain_status_agc_gain_mean_mask                              (0x0000FFFF)
#define  IFD_108_agc_gain_status_agc_gain_var(data)                              (0xFFFF0000&((data)<<16))
#define  IFD_108_agc_gain_status_agc_gain_mean(data)                             (0x0000FFFF&(data))
#define  IFD_108_agc_gain_status_get_agc_gain_var(data)                          ((0xFFFF0000&(data))>>16)
#define  IFD_108_agc_gain_status_get_agc_gain_mean(data)                         (0x0000FFFF&(data))

#define  IFD_108_agc_adapt_targ_cntl                                             0x18032208
#define  IFD_108_agc_adapt_targ_cntl_reg_addr                                    "0xB8032208"
#define  IFD_108_agc_adapt_targ_cntl_reg                                         0xB8032208
#define  IFD_108_agc_adapt_targ_cntl_inst_addr                                   "0x006C"
#define  set_IFD_108_agc_adapt_targ_cntl_reg(data)                               (*((volatile unsigned int*)IFD_108_agc_adapt_targ_cntl_reg)=data)
#define  get_IFD_108_agc_adapt_targ_cntl_reg                                     (*((volatile unsigned int*)IFD_108_agc_adapt_targ_cntl_reg))
#define  IFD_108_agc_adapt_targ_cntl_agc_fine_adapt_interval_shift               (16)
#define  IFD_108_agc_adapt_targ_cntl_agc_adapt_interval_shift                    (4)
#define  IFD_108_agc_adapt_targ_cntl_agc_adapt_targ_en_shift                     (0)
#define  IFD_108_agc_adapt_targ_cntl_agc_fine_adapt_interval_mask                (0x0FFF0000)
#define  IFD_108_agc_adapt_targ_cntl_agc_adapt_interval_mask                     (0x0000FFF0)
#define  IFD_108_agc_adapt_targ_cntl_agc_adapt_targ_en_mask                      (0x00000001)
#define  IFD_108_agc_adapt_targ_cntl_agc_fine_adapt_interval(data)               (0x0FFF0000&((data)<<16))
#define  IFD_108_agc_adapt_targ_cntl_agc_adapt_interval(data)                    (0x0000FFF0&((data)<<4))
#define  IFD_108_agc_adapt_targ_cntl_agc_adapt_targ_en(data)                     (0x00000001&(data))
#define  IFD_108_agc_adapt_targ_cntl_get_agc_fine_adapt_interval(data)           ((0x0FFF0000&(data))>>16)
#define  IFD_108_agc_adapt_targ_cntl_get_agc_adapt_interval(data)                ((0x0000FFF0&(data))>>4)
#define  IFD_108_agc_adapt_targ_cntl_get_agc_adapt_targ_en(data)                 (0x00000001&(data))

#define  IFD_108_agc_adapt_targ_inc_thr                                          0x1803220C
#define  IFD_108_agc_adapt_targ_inc_thr_reg_addr                                 "0xB803220C"
#define  IFD_108_agc_adapt_targ_inc_thr_reg                                      0xB803220C
#define  IFD_108_agc_adapt_targ_inc_thr_inst_addr                                "0x006D"
#define  set_IFD_108_agc_adapt_targ_inc_thr_reg(data)                            (*((volatile unsigned int*)IFD_108_agc_adapt_targ_inc_thr_reg)=data)
#define  get_IFD_108_agc_adapt_targ_inc_thr_reg                                  (*((volatile unsigned int*)IFD_108_agc_adapt_targ_inc_thr_reg))
#define  IFD_108_agc_adapt_targ_inc_thr_agc_targ_inc_thr_shift                   (0)
#define  IFD_108_agc_adapt_targ_inc_thr_agc_targ_inc_thr_mask                    (0x000007FF)
#define  IFD_108_agc_adapt_targ_inc_thr_agc_targ_inc_thr(data)                   (0x000007FF&(data))
#define  IFD_108_agc_adapt_targ_inc_thr_get_agc_targ_inc_thr(data)               (0x000007FF&(data))

#define  IFD_108_agc_adapt_targ_min_val                                          0x18032210
#define  IFD_108_agc_adapt_targ_min_val_reg_addr                                 "0xB8032210"
#define  IFD_108_agc_adapt_targ_min_val_reg                                      0xB8032210
#define  IFD_108_agc_adapt_targ_min_val_inst_addr                                "0x006E"
#define  set_IFD_108_agc_adapt_targ_min_val_reg(data)                            (*((volatile unsigned int*)IFD_108_agc_adapt_targ_min_val_reg)=data)
#define  get_IFD_108_agc_adapt_targ_min_val_reg                                  (*((volatile unsigned int*)IFD_108_agc_adapt_targ_min_val_reg))
#define  IFD_108_agc_adapt_targ_min_val_agc_min_diff_targ_shift                  (12)
#define  IFD_108_agc_adapt_targ_min_val_agc_min_targ_shift                       (0)
#define  IFD_108_agc_adapt_targ_min_val_agc_min_diff_targ_mask                   (0x007FF000)
#define  IFD_108_agc_adapt_targ_min_val_agc_min_targ_mask                        (0x000007FF)
#define  IFD_108_agc_adapt_targ_min_val_agc_min_diff_targ(data)                  (0x007FF000&((data)<<12))
#define  IFD_108_agc_adapt_targ_min_val_agc_min_targ(data)                       (0x000007FF&(data))
#define  IFD_108_agc_adapt_targ_min_val_get_agc_min_diff_targ(data)              ((0x007FF000&(data))>>12)
#define  IFD_108_agc_adapt_targ_min_val_get_agc_min_targ(data)                   (0x000007FF&(data))

#define  IFD_108_agc_adapt_targ_fine_mode                                        0x18032214
#define  IFD_108_agc_adapt_targ_fine_mode_reg_addr                               "0xB8032214"
#define  IFD_108_agc_adapt_targ_fine_mode_reg                                    0xB8032214
#define  IFD_108_agc_adapt_targ_fine_mode_inst_addr                              "0x006F"
#define  set_IFD_108_agc_adapt_targ_fine_mode_reg(data)                          (*((volatile unsigned int*)IFD_108_agc_adapt_targ_fine_mode_reg)=data)
#define  get_IFD_108_agc_adapt_targ_fine_mode_reg                                (*((volatile unsigned int*)IFD_108_agc_adapt_targ_fine_mode_reg))
#define  IFD_108_agc_adapt_targ_fine_mode_agc_fine_targ_thr_shift                (12)
#define  IFD_108_agc_adapt_targ_fine_mode_agc_diff_coarse_step_shift             (0)
#define  IFD_108_agc_adapt_targ_fine_mode_agc_fine_targ_thr_mask                 (0x007FF000)
#define  IFD_108_agc_adapt_targ_fine_mode_agc_diff_coarse_step_mask              (0x000007FF)
#define  IFD_108_agc_adapt_targ_fine_mode_agc_fine_targ_thr(data)                (0x007FF000&((data)<<12))
#define  IFD_108_agc_adapt_targ_fine_mode_agc_diff_coarse_step(data)             (0x000007FF&(data))
#define  IFD_108_agc_adapt_targ_fine_mode_get_agc_fine_targ_thr(data)            ((0x007FF000&(data))>>12)
#define  IFD_108_agc_adapt_targ_fine_mode_get_agc_diff_coarse_step(data)         (0x000007FF&(data))

#define  IFD_108_agc_adapt_targ_status                                           0x18032218
#define  IFD_108_agc_adapt_targ_status_reg_addr                                  "0xB8032218"
#define  IFD_108_agc_adapt_targ_status_reg                                       0xB8032218
#define  IFD_108_agc_adapt_targ_status_inst_addr                                 "0x0070"
#define  set_IFD_108_agc_adapt_targ_status_reg(data)                             (*((volatile unsigned int*)IFD_108_agc_adapt_targ_status_reg)=data)
#define  get_IFD_108_agc_adapt_targ_status_reg                                   (*((volatile unsigned int*)IFD_108_agc_adapt_targ_status_reg))
#define  IFD_108_agc_adapt_targ_status_adaptive_diff_targ_ro_shift               (12)
#define  IFD_108_agc_adapt_targ_status_adaptive_targ_val_ro_shift                (0)
#define  IFD_108_agc_adapt_targ_status_adaptive_diff_targ_ro_mask                (0x007FF000)
#define  IFD_108_agc_adapt_targ_status_adaptive_targ_val_ro_mask                 (0x000007FF)
#define  IFD_108_agc_adapt_targ_status_adaptive_diff_targ_ro(data)               (0x007FF000&((data)<<12))
#define  IFD_108_agc_adapt_targ_status_adaptive_targ_val_ro(data)                (0x000007FF&(data))
#define  IFD_108_agc_adapt_targ_status_get_adaptive_diff_targ_ro(data)           ((0x007FF000&(data))>>12)
#define  IFD_108_agc_adapt_targ_status_get_adaptive_targ_val_ro(data)            (0x000007FF&(data))

#define  IFD_108_impulsive_gate_set                                              0x18032220
#define  IFD_108_impulsive_gate_set_reg_addr                                     "0xB8032220"
#define  IFD_108_impulsive_gate_set_reg                                          0xB8032220
#define  IFD_108_impulsive_gate_set_inst_addr                                    "0x0071"
#define  set_IFD_108_impulsive_gate_set_reg(data)                                (*((volatile unsigned int*)IFD_108_impulsive_gate_set_reg)=data)
#define  get_IFD_108_impulsive_gate_set_reg                                      (*((volatile unsigned int*)IFD_108_impulsive_gate_set_reg))
#define  IFD_108_impulsive_gate_set_impn_gate_end_shift                          (20)
#define  IFD_108_impulsive_gate_set_impn_det_thr_shift                           (8)
#define  IFD_108_impulsive_gate_set_impn_det_input_sel_shift                     (4)
#define  IFD_108_impulsive_gate_set_agc_impn_mask_en_shift                       (1)
#define  IFD_108_impulsive_gate_set_impn_det_en_shift                            (0)
#define  IFD_108_impulsive_gate_set_impn_gate_end_mask                           (0xFFF00000)
#define  IFD_108_impulsive_gate_set_impn_det_thr_mask                            (0x000FFF00)
#define  IFD_108_impulsive_gate_set_impn_det_input_sel_mask                      (0x00000010)
#define  IFD_108_impulsive_gate_set_agc_impn_mask_en_mask                        (0x00000002)
#define  IFD_108_impulsive_gate_set_impn_det_en_mask                             (0x00000001)
#define  IFD_108_impulsive_gate_set_impn_gate_end(data)                          (0xFFF00000&((data)<<20))
#define  IFD_108_impulsive_gate_set_impn_det_thr(data)                           (0x000FFF00&((data)<<8))
#define  IFD_108_impulsive_gate_set_impn_det_input_sel(data)                     (0x00000010&((data)<<4))
#define  IFD_108_impulsive_gate_set_agc_impn_mask_en(data)                       (0x00000002&((data)<<1))
#define  IFD_108_impulsive_gate_set_impn_det_en(data)                            (0x00000001&(data))
#define  IFD_108_impulsive_gate_set_get_impn_gate_end(data)                      ((0xFFF00000&(data))>>20)
#define  IFD_108_impulsive_gate_set_get_impn_det_thr(data)                       ((0x000FFF00&(data))>>8)
#define  IFD_108_impulsive_gate_set_get_impn_det_input_sel(data)                 ((0x00000010&(data))>>4)
#define  IFD_108_impulsive_gate_set_get_agc_impn_mask_en(data)                   ((0x00000002&(data))>>1)
#define  IFD_108_impulsive_gate_set_get_impn_det_en(data)                        (0x00000001&(data))

#define  IFD_108_impulsive_gate_setII                                            0x18032224
#define  IFD_108_impulsive_gate_setII_reg_addr                                   "0xB8032224"
#define  IFD_108_impulsive_gate_setII_reg                                        0xB8032224
#define  IFD_108_impulsive_gate_setII_inst_addr                                  "0x0072"
#define  set_IFD_108_impulsive_gate_setII_reg(data)                              (*((volatile unsigned int*)IFD_108_impulsive_gate_setII_reg)=data)
#define  get_IFD_108_impulsive_gate_setII_reg                                    (*((volatile unsigned int*)IFD_108_impulsive_gate_setII_reg))
#define  IFD_108_impulsive_gate_setII_impn_detect_shift                          (20)
#define  IFD_108_impulsive_gate_setII_impn_det_stop_shift                        (12)
#define  IFD_108_impulsive_gate_setII_impn_gate_delay_shift                      (0)
#define  IFD_108_impulsive_gate_setII_impn_detect_mask                           (0x00100000)
#define  IFD_108_impulsive_gate_setII_impn_det_stop_mask                         (0x000FF000)
#define  IFD_108_impulsive_gate_setII_impn_gate_delay_mask                       (0x00000FFF)
#define  IFD_108_impulsive_gate_setII_impn_detect(data)                          (0x00100000&((data)<<20))
#define  IFD_108_impulsive_gate_setII_impn_det_stop(data)                        (0x000FF000&((data)<<12))
#define  IFD_108_impulsive_gate_setII_impn_gate_delay(data)                      (0x00000FFF&(data))
#define  IFD_108_impulsive_gate_setII_get_impn_detect(data)                      ((0x00100000&(data))>>20)
#define  IFD_108_impulsive_gate_setII_get_impn_det_stop(data)                    ((0x000FF000&(data))>>12)
#define  IFD_108_impulsive_gate_setII_get_impn_gate_delay(data)                  (0x00000FFF&(data))

#define  IFD_108_agc_sync_level_status                                           0x18032230
#define  IFD_108_agc_sync_level_status_reg_addr                                  "0xB8032230"
#define  IFD_108_agc_sync_level_status_reg                                       0xB8032230
#define  IFD_108_agc_sync_level_status_inst_addr                                 "0x0073"
#define  set_IFD_108_agc_sync_level_status_reg(data)                             (*((volatile unsigned int*)IFD_108_agc_sync_level_status_reg)=data)
#define  get_IFD_108_agc_sync_level_status_reg                                   (*((volatile unsigned int*)IFD_108_agc_sync_level_status_reg))
#define  IFD_108_agc_sync_level_status_agc_sync_level_avg_length_shift           (24)
#define  IFD_108_agc_sync_level_status_agc_sync_level_var_shift                  (12)
#define  IFD_108_agc_sync_level_status_agc_sync_level_mean_shift                 (0)
#define  IFD_108_agc_sync_level_status_agc_sync_level_avg_length_mask            (0x01000000)
#define  IFD_108_agc_sync_level_status_agc_sync_level_var_mask                   (0x00FFF000)
#define  IFD_108_agc_sync_level_status_agc_sync_level_mean_mask                  (0x00000FFF)
#define  IFD_108_agc_sync_level_status_agc_sync_level_avg_length(data)           (0x01000000&((data)<<24))
#define  IFD_108_agc_sync_level_status_agc_sync_level_var(data)                  (0x00FFF000&((data)<<12))
#define  IFD_108_agc_sync_level_status_agc_sync_level_mean(data)                 (0x00000FFF&(data))
#define  IFD_108_agc_sync_level_status_get_agc_sync_level_avg_length(data)       ((0x01000000&(data))>>24)
#define  IFD_108_agc_sync_level_status_get_agc_sync_level_var(data)              ((0x00FFF000&(data))>>12)
#define  IFD_108_agc_sync_level_status_get_agc_sync_level_mean(data)             (0x00000FFF&(data))

#define  IFD_108_agc_max_var_status                                              0x18032234
#define  IFD_108_agc_max_var_status_reg_addr                                     "0xB8032234"
#define  IFD_108_agc_max_var_status_reg                                          0xB8032234
#define  IFD_108_agc_max_var_status_inst_addr                                    "0x0074"
#define  set_IFD_108_agc_max_var_status_reg(data)                                (*((volatile unsigned int*)IFD_108_agc_max_var_status_reg)=data)
#define  get_IFD_108_agc_max_var_status_reg                                      (*((volatile unsigned int*)IFD_108_agc_max_var_status_reg))
#define  IFD_108_agc_max_var_status_agc_max_avg_length_shift                     (24)
#define  IFD_108_agc_max_var_status_agc_max_var_shift                            (12)
#define  IFD_108_agc_max_var_status_agc_max_mean_shift                           (0)
#define  IFD_108_agc_max_var_status_agc_max_avg_length_mask                      (0x01000000)
#define  IFD_108_agc_max_var_status_agc_max_var_mask                             (0x007FF000)
#define  IFD_108_agc_max_var_status_agc_max_mean_mask                            (0x000007FF)
#define  IFD_108_agc_max_var_status_agc_max_avg_length(data)                     (0x01000000&((data)<<24))
#define  IFD_108_agc_max_var_status_agc_max_var(data)                            (0x007FF000&((data)<<12))
#define  IFD_108_agc_max_var_status_agc_max_mean(data)                           (0x000007FF&(data))
#define  IFD_108_agc_max_var_status_get_agc_max_avg_length(data)                 ((0x01000000&(data))>>24)
#define  IFD_108_agc_max_var_status_get_agc_max_var(data)                        ((0x007FF000&(data))>>12)
#define  IFD_108_agc_max_var_status_get_agc_max_mean(data)                       (0x000007FF&(data))

#define  IFD_108_agc_hum_ctrl                                                    0x18032238
#define  IFD_108_agc_hum_ctrl_reg_addr                                           "0xB8032238"
#define  IFD_108_agc_hum_ctrl_reg                                                0xB8032238
#define  IFD_108_agc_hum_ctrl_inst_addr                                          "0x0075"
#define  set_IFD_108_agc_hum_ctrl_reg(data)                                      (*((volatile unsigned int*)IFD_108_agc_hum_ctrl_reg)=data)
#define  get_IFD_108_agc_hum_ctrl_reg                                            (*((volatile unsigned int*)IFD_108_agc_hum_ctrl_reg))
#define  IFD_108_agc_hum_ctrl_hum_detect_shift                                   (12)
#define  IFD_108_agc_hum_ctrl_agc_hum_debounce_shift                             (8)
#define  IFD_108_agc_hum_ctrl_agc_hum_update_sel_shift                           (4)
#define  IFD_108_agc_hum_ctrl_agc_hum_en_shift                                   (0)
#define  IFD_108_agc_hum_ctrl_hum_detect_mask                                    (0x00001000)
#define  IFD_108_agc_hum_ctrl_agc_hum_debounce_mask                              (0x00000700)
#define  IFD_108_agc_hum_ctrl_agc_hum_update_sel_mask                            (0x00000010)
#define  IFD_108_agc_hum_ctrl_agc_hum_en_mask                                    (0x00000001)
#define  IFD_108_agc_hum_ctrl_hum_detect(data)                                   (0x00001000&((data)<<12))
#define  IFD_108_agc_hum_ctrl_agc_hum_debounce(data)                             (0x00000700&((data)<<8))
#define  IFD_108_agc_hum_ctrl_agc_hum_update_sel(data)                           (0x00000010&((data)<<4))
#define  IFD_108_agc_hum_ctrl_agc_hum_en(data)                                   (0x00000001&(data))
#define  IFD_108_agc_hum_ctrl_get_hum_detect(data)                               ((0x00001000&(data))>>12)
#define  IFD_108_agc_hum_ctrl_get_agc_hum_debounce(data)                         ((0x00000700&(data))>>8)
#define  IFD_108_agc_hum_ctrl_get_agc_hum_update_sel(data)                       ((0x00000010&(data))>>4)
#define  IFD_108_agc_hum_ctrl_get_agc_hum_en(data)                               (0x00000001&(data))

#define  IFD_108_agc_hum_max_thr                                                 0x1803223C
#define  IFD_108_agc_hum_max_thr_reg_addr                                        "0xB803223C"
#define  IFD_108_agc_hum_max_thr_reg                                             0xB803223C
#define  IFD_108_agc_hum_max_thr_inst_addr                                       "0x0076"
#define  set_IFD_108_agc_hum_max_thr_reg(data)                                   (*((volatile unsigned int*)IFD_108_agc_hum_max_thr_reg)=data)
#define  get_IFD_108_agc_hum_max_thr_reg                                         (*((volatile unsigned int*)IFD_108_agc_hum_max_thr_reg))
#define  IFD_108_agc_hum_max_thr_agc_hum_max_thr_out_shift                       (12)
#define  IFD_108_agc_hum_max_thr_agc_hum_max_thr_in_shift                        (0)
#define  IFD_108_agc_hum_max_thr_agc_hum_max_thr_out_mask                        (0x007FF000)
#define  IFD_108_agc_hum_max_thr_agc_hum_max_thr_in_mask                         (0x000007FF)
#define  IFD_108_agc_hum_max_thr_agc_hum_max_thr_out(data)                       (0x007FF000&((data)<<12))
#define  IFD_108_agc_hum_max_thr_agc_hum_max_thr_in(data)                        (0x000007FF&(data))
#define  IFD_108_agc_hum_max_thr_get_agc_hum_max_thr_out(data)                   ((0x007FF000&(data))>>12)
#define  IFD_108_agc_hum_max_thr_get_agc_hum_max_thr_in(data)                    (0x000007FF&(data))

#define  IFD_108_agc_hum_sync_level_thr                                          0x18032240
#define  IFD_108_agc_hum_sync_level_thr_reg_addr                                 "0xB8032240"
#define  IFD_108_agc_hum_sync_level_thr_reg                                      0xB8032240
#define  IFD_108_agc_hum_sync_level_thr_inst_addr                                "0x0077"
#define  set_IFD_108_agc_hum_sync_level_thr_reg(data)                            (*((volatile unsigned int*)IFD_108_agc_hum_sync_level_thr_reg)=data)
#define  get_IFD_108_agc_hum_sync_level_thr_reg                                  (*((volatile unsigned int*)IFD_108_agc_hum_sync_level_thr_reg))
#define  IFD_108_agc_hum_sync_level_thr_agc_hum_sync_thr_out_shift               (12)
#define  IFD_108_agc_hum_sync_level_thr_agc_hum_sync_thr_in_shift                (0)
#define  IFD_108_agc_hum_sync_level_thr_agc_hum_sync_thr_out_mask                (0x00FFF000)
#define  IFD_108_agc_hum_sync_level_thr_agc_hum_sync_thr_in_mask                 (0x00000FFF)
#define  IFD_108_agc_hum_sync_level_thr_agc_hum_sync_thr_out(data)               (0x00FFF000&((data)<<12))
#define  IFD_108_agc_hum_sync_level_thr_agc_hum_sync_thr_in(data)                (0x00000FFF&(data))
#define  IFD_108_agc_hum_sync_level_thr_get_agc_hum_sync_thr_out(data)           ((0x00FFF000&(data))>>12)
#define  IFD_108_agc_hum_sync_level_thr_get_agc_hum_sync_thr_in(data)            (0x00000FFF&(data))

#define  IFD_108_pga_int_thr                                                     0x18032250
#define  IFD_108_pga_int_thr_reg_addr                                            "0xB8032250"
#define  IFD_108_pga_int_thr_reg                                                 0xB8032250
#define  IFD_108_pga_int_thr_inst_addr                                           "0x0078"
#define  set_IFD_108_pga_int_thr_reg(data)                                       (*((volatile unsigned int*)IFD_108_pga_int_thr_reg)=data)
#define  get_IFD_108_pga_int_thr_reg                                             (*((volatile unsigned int*)IFD_108_pga_int_thr_reg))
#define  IFD_108_pga_int_thr_agc_pga_int_thr_shift                               (0)
#define  IFD_108_pga_int_thr_agc_pga_int_thr_mask                                (0x000000FF)
#define  IFD_108_pga_int_thr_agc_pga_int_thr(data)                               (0x000000FF&(data))
#define  IFD_108_pga_int_thr_get_agc_pga_int_thr(data)                           (0x000000FF&(data))

#define  IFD_108_rf_int_thr                                                      0x18032254
#define  IFD_108_rf_int_thr_reg_addr                                             "0xB8032254"
#define  IFD_108_rf_int_thr_reg                                                  0xB8032254
#define  IFD_108_rf_int_thr_inst_addr                                            "0x0079"
#define  set_IFD_108_rf_int_thr_reg(data)                                        (*((volatile unsigned int*)IFD_108_rf_int_thr_reg)=data)
#define  get_IFD_108_rf_int_thr_reg                                              (*((volatile unsigned int*)IFD_108_rf_int_thr_reg))
#define  IFD_108_rf_int_thr_agc_rf_w2s_int_thr_shift                             (16)
#define  IFD_108_rf_int_thr_agc_rf_s2w_int_thr_shift                             (0)
#define  IFD_108_rf_int_thr_agc_rf_w2s_int_thr_mask                              (0x1FFF0000)
#define  IFD_108_rf_int_thr_agc_rf_s2w_int_thr_mask                              (0x00001FFF)
#define  IFD_108_rf_int_thr_agc_rf_w2s_int_thr(data)                             (0x1FFF0000&((data)<<16))
#define  IFD_108_rf_int_thr_agc_rf_s2w_int_thr(data)                             (0x00001FFF&(data))
#define  IFD_108_rf_int_thr_get_agc_rf_w2s_int_thr(data)                         ((0x1FFF0000&(data))>>16)
#define  IFD_108_rf_int_thr_get_agc_rf_s2w_int_thr(data)                         (0x00001FFF&(data))

#define  IFD_108_if_int_thr                                                      0x18032258
#define  IFD_108_if_int_thr_reg_addr                                             "0xB8032258"
#define  IFD_108_if_int_thr_reg                                                  0xB8032258
#define  IFD_108_if_int_thr_inst_addr                                            "0x007A"
#define  set_IFD_108_if_int_thr_reg(data)                                        (*((volatile unsigned int*)IFD_108_if_int_thr_reg)=data)
#define  get_IFD_108_if_int_thr_reg                                              (*((volatile unsigned int*)IFD_108_if_int_thr_reg))
#define  IFD_108_if_int_thr_agc_if_w2s_int_thr_shift                             (16)
#define  IFD_108_if_int_thr_agc_if_s2w_int_thr_shift                             (0)
#define  IFD_108_if_int_thr_agc_if_w2s_int_thr_mask                              (0x1FFF0000)
#define  IFD_108_if_int_thr_agc_if_s2w_int_thr_mask                              (0x00001FFF)
#define  IFD_108_if_int_thr_agc_if_w2s_int_thr(data)                             (0x1FFF0000&((data)<<16))
#define  IFD_108_if_int_thr_agc_if_s2w_int_thr(data)                             (0x00001FFF&(data))
#define  IFD_108_if_int_thr_get_agc_if_w2s_int_thr(data)                         ((0x1FFF0000&(data))>>16)
#define  IFD_108_if_int_thr_get_agc_if_s2w_int_thr(data)                         (0x00001FFF&(data))

#define  IFD_108_agc_peak_lsadc                                                  0x18032260
#define  IFD_108_agc_peak_lsadc_reg_addr                                         "0xB8032260"
#define  IFD_108_agc_peak_lsadc_reg                                              0xB8032260
#define  IFD_108_agc_peak_lsadc_inst_addr                                        "0x007B"
#define  set_IFD_108_agc_peak_lsadc_reg(data)                                    (*((volatile unsigned int*)IFD_108_agc_peak_lsadc_reg)=data)
#define  get_IFD_108_agc_peak_lsadc_reg                                          (*((volatile unsigned int*)IFD_108_agc_peak_lsadc_reg))
#define  IFD_108_agc_peak_lsadc_agc_auto_min_pga_en_shift                        (28)
#define  IFD_108_agc_peak_lsadc_agc_slow_charge_lsadc_peak_value_shift           (24)
#define  IFD_108_agc_peak_lsadc_agc_slow_charge_lsadc_peak_en_shift              (20)
#define  IFD_108_agc_peak_lsadc_agc_lsadc_peak_cnt_shift                         (8)
#define  IFD_108_agc_peak_lsadc_agc_peak_lsadc_shift                             (0)
#define  IFD_108_agc_peak_lsadc_agc_auto_min_pga_en_mask                         (0x10000000)
#define  IFD_108_agc_peak_lsadc_agc_slow_charge_lsadc_peak_value_mask            (0x07000000)
#define  IFD_108_agc_peak_lsadc_agc_slow_charge_lsadc_peak_en_mask               (0x00100000)
#define  IFD_108_agc_peak_lsadc_agc_lsadc_peak_cnt_mask                          (0x000FFF00)
#define  IFD_108_agc_peak_lsadc_agc_peak_lsadc_mask                              (0x0000003F)
#define  IFD_108_agc_peak_lsadc_agc_auto_min_pga_en(data)                        (0x10000000&((data)<<28))
#define  IFD_108_agc_peak_lsadc_agc_slow_charge_lsadc_peak_value(data)           (0x07000000&((data)<<24))
#define  IFD_108_agc_peak_lsadc_agc_slow_charge_lsadc_peak_en(data)              (0x00100000&((data)<<20))
#define  IFD_108_agc_peak_lsadc_agc_lsadc_peak_cnt(data)                         (0x000FFF00&((data)<<8))
#define  IFD_108_agc_peak_lsadc_agc_peak_lsadc(data)                             (0x0000003F&(data))
#define  IFD_108_agc_peak_lsadc_get_agc_auto_min_pga_en(data)                    ((0x10000000&(data))>>28)
#define  IFD_108_agc_peak_lsadc_get_agc_slow_charge_lsadc_peak_value(data)       ((0x07000000&(data))>>24)
#define  IFD_108_agc_peak_lsadc_get_agc_slow_charge_lsadc_peak_en(data)          ((0x00100000&(data))>>20)
#define  IFD_108_agc_peak_lsadc_get_agc_lsadc_peak_cnt(data)                     ((0x000FFF00&(data))>>8)
#define  IFD_108_agc_peak_lsadc_get_agc_peak_lsadc(data)                         (0x0000003F&(data))

#define  IFD_108_auto_pga_min                                                    0x18032264
#define  IFD_108_auto_pga_min_reg_addr                                           "0xB8032264"
#define  IFD_108_auto_pga_min_reg                                                0xB8032264
#define  IFD_108_auto_pga_min_inst_addr                                          "0x007C"
#define  set_IFD_108_auto_pga_min_reg(data)                                      (*((volatile unsigned int*)IFD_108_auto_pga_min_reg)=data)
#define  get_IFD_108_auto_pga_min_reg                                            (*((volatile unsigned int*)IFD_108_auto_pga_min_reg))
#define  IFD_108_auto_pga_min_agc_pga_min_update_step_shift                      (28)
#define  IFD_108_auto_pga_min_agc_pga_min_update_interval_shift                  (16)
#define  IFD_108_auto_pga_min_agc_pga_min_up_thr_shift                           (8)
#define  IFD_108_auto_pga_min_agc_pga_min_low_thr_shift                          (0)
#define  IFD_108_auto_pga_min_agc_pga_min_update_step_mask                       (0xF0000000)
#define  IFD_108_auto_pga_min_agc_pga_min_update_interval_mask                   (0x0FFF0000)
#define  IFD_108_auto_pga_min_agc_pga_min_up_thr_mask                            (0x00003F00)
#define  IFD_108_auto_pga_min_agc_pga_min_low_thr_mask                           (0x0000003F)
#define  IFD_108_auto_pga_min_agc_pga_min_update_step(data)                      (0xF0000000&((data)<<28))
#define  IFD_108_auto_pga_min_agc_pga_min_update_interval(data)                  (0x0FFF0000&((data)<<16))
#define  IFD_108_auto_pga_min_agc_pga_min_up_thr(data)                           (0x00003F00&((data)<<8))
#define  IFD_108_auto_pga_min_agc_pga_min_low_thr(data)                          (0x0000003F&(data))
#define  IFD_108_auto_pga_min_get_agc_pga_min_update_step(data)                  ((0xF0000000&(data))>>28)
#define  IFD_108_auto_pga_min_get_agc_pga_min_update_interval(data)              ((0x0FFF0000&(data))>>16)
#define  IFD_108_auto_pga_min_get_agc_pga_min_up_thr(data)                       ((0x00003F00&(data))>>8)
#define  IFD_108_auto_pga_min_get_agc_pga_min_low_thr(data)                      (0x0000003F&(data))

#define  IFD_108_lsadc_out                                                       0x18032268
#define  IFD_108_lsadc_out_reg_addr                                              "0xB8032268"
#define  IFD_108_lsadc_out_reg                                                   0xB8032268
#define  IFD_108_lsadc_out_inst_addr                                             "0x007D"
#define  set_IFD_108_lsadc_out_reg(data)                                         (*((volatile unsigned int*)IFD_108_lsadc_out_reg)=data)
#define  get_IFD_108_lsadc_out_reg                                               (*((volatile unsigned int*)IFD_108_lsadc_out_reg))
#define  IFD_108_lsadc_out_ls_adc_out_shift                                      (0)
#define  IFD_108_lsadc_out_ls_adc_out_mask                                       (0x0000003F)
#define  IFD_108_lsadc_out_ls_adc_out(data)                                      (0x0000003F&(data))
#define  IFD_108_lsadc_out_get_ls_adc_out(data)                                  (0x0000003F&(data))

#define  IFD_108_pga_min_status                                                  0x1803226C
#define  IFD_108_pga_min_status_reg_addr                                         "0xB803226C"
#define  IFD_108_pga_min_status_reg                                              0xB803226C
#define  IFD_108_pga_min_status_inst_addr                                        "0x007E"
#define  set_IFD_108_pga_min_status_reg(data)                                    (*((volatile unsigned int*)IFD_108_pga_min_status_reg)=data)
#define  get_IFD_108_pga_min_status_reg                                          (*((volatile unsigned int*)IFD_108_pga_min_status_reg))
#define  IFD_108_pga_min_status_pga_min_auto_shift                               (0)
#define  IFD_108_pga_min_status_pga_min_auto_mask                                (0x000000FF)
#define  IFD_108_pga_min_status_pga_min_auto(data)                               (0x000000FF&(data))
#define  IFD_108_pga_min_status_get_pga_min_auto(data)                           (0x000000FF&(data))

#define  IFD_108_input_power_ctrl                                                0x18032280
#define  IFD_108_input_power_ctrl_reg_addr                                       "0xB8032280"
#define  IFD_108_input_power_ctrl_reg                                            0xB8032280
#define  IFD_108_input_power_ctrl_inst_addr                                      "0x007F"
#define  set_IFD_108_input_power_ctrl_reg(data)                                  (*((volatile unsigned int*)IFD_108_input_power_ctrl_reg)=data)
#define  get_IFD_108_input_power_ctrl_reg                                        (*((volatile unsigned int*)IFD_108_input_power_ctrl_reg))
#define  IFD_108_input_power_ctrl_input_power_scan_mode_offset_shift             (20)
#define  IFD_108_input_power_ctrl_input_power_pc_sel_shift                       (16)
#define  IFD_108_input_power_ctrl_input_power_cal_shift_shift                    (12)
#define  IFD_108_input_power_ctrl_input_power_acc_len_shift                      (8)
#define  IFD_108_input_power_ctrl_input_power_cal_len_shift                      (4)
#define  IFD_108_input_power_ctrl_input_power_interrupt_mode_shift               (3)
#define  IFD_108_input_power_ctrl_input_power_cal_reset_shift                    (2)
#define  IFD_108_input_power_ctrl_input_power_mod_sel_shift                      (1)
#define  IFD_108_input_power_ctrl_input_power_mode_shift                         (0)
#define  IFD_108_input_power_ctrl_input_power_scan_mode_offset_mask              (0xFFF00000)
#define  IFD_108_input_power_ctrl_input_power_pc_sel_mask                        (0x00010000)
#define  IFD_108_input_power_ctrl_input_power_cal_shift_mask                     (0x00007000)
#define  IFD_108_input_power_ctrl_input_power_acc_len_mask                       (0x00000300)
#define  IFD_108_input_power_ctrl_input_power_cal_len_mask                       (0x00000070)
#define  IFD_108_input_power_ctrl_input_power_interrupt_mode_mask                (0x00000008)
#define  IFD_108_input_power_ctrl_input_power_cal_reset_mask                     (0x00000004)
#define  IFD_108_input_power_ctrl_input_power_mod_sel_mask                       (0x00000002)
#define  IFD_108_input_power_ctrl_input_power_mode_mask                          (0x00000001)
#define  IFD_108_input_power_ctrl_input_power_scan_mode_offset(data)             (0xFFF00000&((data)<<20))
#define  IFD_108_input_power_ctrl_input_power_pc_sel(data)                       (0x00010000&((data)<<16))
#define  IFD_108_input_power_ctrl_input_power_cal_shift(data)                    (0x00007000&((data)<<12))
#define  IFD_108_input_power_ctrl_input_power_acc_len(data)                      (0x00000300&((data)<<8))
#define  IFD_108_input_power_ctrl_input_power_cal_len(data)                      (0x00000070&((data)<<4))
#define  IFD_108_input_power_ctrl_input_power_interrupt_mode(data)               (0x00000008&((data)<<3))
#define  IFD_108_input_power_ctrl_input_power_cal_reset(data)                    (0x00000004&((data)<<2))
#define  IFD_108_input_power_ctrl_input_power_mod_sel(data)                      (0x00000002&((data)<<1))
#define  IFD_108_input_power_ctrl_input_power_mode(data)                         (0x00000001&(data))
#define  IFD_108_input_power_ctrl_get_input_power_scan_mode_offset(data)         ((0xFFF00000&(data))>>20)
#define  IFD_108_input_power_ctrl_get_input_power_pc_sel(data)                   ((0x00010000&(data))>>16)
#define  IFD_108_input_power_ctrl_get_input_power_cal_shift(data)                ((0x00007000&(data))>>12)
#define  IFD_108_input_power_ctrl_get_input_power_acc_len(data)                  ((0x00000300&(data))>>8)
#define  IFD_108_input_power_ctrl_get_input_power_cal_len(data)                  ((0x00000070&(data))>>4)
#define  IFD_108_input_power_ctrl_get_input_power_interrupt_mode(data)           ((0x00000008&(data))>>3)
#define  IFD_108_input_power_ctrl_get_input_power_cal_reset(data)                ((0x00000004&(data))>>2)
#define  IFD_108_input_power_ctrl_get_input_power_mod_sel(data)                  ((0x00000002&(data))>>1)
#define  IFD_108_input_power_ctrl_get_input_power_mode(data)                     (0x00000001&(data))

#define  IFD_108_nco_if                                                          0x18032284
#define  IFD_108_nco_if_reg_addr                                                 "0xB8032284"
#define  IFD_108_nco_if_reg                                                      0xB8032284
#define  IFD_108_nco_if_inst_addr                                                "0x0080"
#define  set_IFD_108_nco_if_reg(data)                                            (*((volatile unsigned int*)IFD_108_nco_if_reg)=data)
#define  get_IFD_108_nco_if_reg                                                  (*((volatile unsigned int*)IFD_108_nco_if_reg))
#define  IFD_108_nco_if_input_power_nco_pc_shift                                 (16)
#define  IFD_108_nco_if_input_power_nco_ac_shift                                 (0)
#define  IFD_108_nco_if_input_power_nco_pc_mask                                  (0xFFFF0000)
#define  IFD_108_nco_if_input_power_nco_ac_mask                                  (0x0000FFFF)
#define  IFD_108_nco_if_input_power_nco_pc(data)                                 (0xFFFF0000&((data)<<16))
#define  IFD_108_nco_if_input_power_nco_ac(data)                                 (0x0000FFFF&(data))
#define  IFD_108_nco_if_get_input_power_nco_pc(data)                             ((0xFFFF0000&(data))>>16)
#define  IFD_108_nco_if_get_input_power_nco_ac(data)                             (0x0000FFFF&(data))

#define  IFD_108_nco_sequential1                                                 0x18032288
#define  IFD_108_nco_sequential1_reg_addr                                        "0xB8032288"
#define  IFD_108_nco_sequential1_reg                                             0xB8032288
#define  IFD_108_nco_sequential1_inst_addr                                       "0x0081"
#define  set_IFD_108_nco_sequential1_reg(data)                                   (*((volatile unsigned int*)IFD_108_nco_sequential1_reg)=data)
#define  get_IFD_108_nco_sequential1_reg                                         (*((volatile unsigned int*)IFD_108_nco_sequential1_reg))
#define  IFD_108_nco_sequential1_input_power_nco_02_shift                        (16)
#define  IFD_108_nco_sequential1_input_power_nco_01_shift                        (0)
#define  IFD_108_nco_sequential1_input_power_nco_02_mask                         (0xFFFF0000)
#define  IFD_108_nco_sequential1_input_power_nco_01_mask                         (0x0000FFFF)
#define  IFD_108_nco_sequential1_input_power_nco_02(data)                        (0xFFFF0000&((data)<<16))
#define  IFD_108_nco_sequential1_input_power_nco_01(data)                        (0x0000FFFF&(data))
#define  IFD_108_nco_sequential1_get_input_power_nco_02(data)                    ((0xFFFF0000&(data))>>16)
#define  IFD_108_nco_sequential1_get_input_power_nco_01(data)                    (0x0000FFFF&(data))

#define  IFD_108_nco_sequential2                                                 0x1803228C
#define  IFD_108_nco_sequential2_reg_addr                                        "0xB803228C"
#define  IFD_108_nco_sequential2_reg                                             0xB803228C
#define  IFD_108_nco_sequential2_inst_addr                                       "0x0082"
#define  set_IFD_108_nco_sequential2_reg(data)                                   (*((volatile unsigned int*)IFD_108_nco_sequential2_reg)=data)
#define  get_IFD_108_nco_sequential2_reg                                         (*((volatile unsigned int*)IFD_108_nco_sequential2_reg))
#define  IFD_108_nco_sequential2_input_power_nco_04_shift                        (16)
#define  IFD_108_nco_sequential2_input_power_nco_03_shift                        (0)
#define  IFD_108_nco_sequential2_input_power_nco_04_mask                         (0xFFFF0000)
#define  IFD_108_nco_sequential2_input_power_nco_03_mask                         (0x0000FFFF)
#define  IFD_108_nco_sequential2_input_power_nco_04(data)                        (0xFFFF0000&((data)<<16))
#define  IFD_108_nco_sequential2_input_power_nco_03(data)                        (0x0000FFFF&(data))
#define  IFD_108_nco_sequential2_get_input_power_nco_04(data)                    ((0xFFFF0000&(data))>>16)
#define  IFD_108_nco_sequential2_get_input_power_nco_03(data)                    (0x0000FFFF&(data))

#define  IFD_108_nco_sequential3                                                 0x18032290
#define  IFD_108_nco_sequential3_reg_addr                                        "0xB8032290"
#define  IFD_108_nco_sequential3_reg                                             0xB8032290
#define  IFD_108_nco_sequential3_inst_addr                                       "0x0083"
#define  set_IFD_108_nco_sequential3_reg(data)                                   (*((volatile unsigned int*)IFD_108_nco_sequential3_reg)=data)
#define  get_IFD_108_nco_sequential3_reg                                         (*((volatile unsigned int*)IFD_108_nco_sequential3_reg))
#define  IFD_108_nco_sequential3_input_power_nco_06_shift                        (16)
#define  IFD_108_nco_sequential3_input_power_nco_05_shift                        (0)
#define  IFD_108_nco_sequential3_input_power_nco_06_mask                         (0xFFFF0000)
#define  IFD_108_nco_sequential3_input_power_nco_05_mask                         (0x0000FFFF)
#define  IFD_108_nco_sequential3_input_power_nco_06(data)                        (0xFFFF0000&((data)<<16))
#define  IFD_108_nco_sequential3_input_power_nco_05(data)                        (0x0000FFFF&(data))
#define  IFD_108_nco_sequential3_get_input_power_nco_06(data)                    ((0xFFFF0000&(data))>>16)
#define  IFD_108_nco_sequential3_get_input_power_nco_05(data)                    (0x0000FFFF&(data))

#define  IFD_108_nco_sequential4                                                 0x18032294
#define  IFD_108_nco_sequential4_reg_addr                                        "0xB8032294"
#define  IFD_108_nco_sequential4_reg                                             0xB8032294
#define  IFD_108_nco_sequential4_inst_addr                                       "0x0084"
#define  set_IFD_108_nco_sequential4_reg(data)                                   (*((volatile unsigned int*)IFD_108_nco_sequential4_reg)=data)
#define  get_IFD_108_nco_sequential4_reg                                         (*((volatile unsigned int*)IFD_108_nco_sequential4_reg))
#define  IFD_108_nco_sequential4_input_power_nco_08_shift                        (16)
#define  IFD_108_nco_sequential4_input_power_nco_07_shift                        (0)
#define  IFD_108_nco_sequential4_input_power_nco_08_mask                         (0xFFFF0000)
#define  IFD_108_nco_sequential4_input_power_nco_07_mask                         (0x0000FFFF)
#define  IFD_108_nco_sequential4_input_power_nco_08(data)                        (0xFFFF0000&((data)<<16))
#define  IFD_108_nco_sequential4_input_power_nco_07(data)                        (0x0000FFFF&(data))
#define  IFD_108_nco_sequential4_get_input_power_nco_08(data)                    ((0xFFFF0000&(data))>>16)
#define  IFD_108_nco_sequential4_get_input_power_nco_07(data)                    (0x0000FFFF&(data))

#define  IFD_108_nco_scan_range1                                                 0x18032298
#define  IFD_108_nco_scan_range1_reg_addr                                        "0xB8032298"
#define  IFD_108_nco_scan_range1_reg                                             0xB8032298
#define  IFD_108_nco_scan_range1_inst_addr                                       "0x0085"
#define  set_IFD_108_nco_scan_range1_reg(data)                                   (*((volatile unsigned int*)IFD_108_nco_scan_range1_reg)=data)
#define  get_IFD_108_nco_scan_range1_reg                                         (*((volatile unsigned int*)IFD_108_nco_scan_range1_reg))
#define  IFD_108_nco_scan_range1_input_power_range2_shift                        (16)
#define  IFD_108_nco_scan_range1_input_power_range1_shift                        (0)
#define  IFD_108_nco_scan_range1_input_power_range2_mask                         (0xFFFF0000)
#define  IFD_108_nco_scan_range1_input_power_range1_mask                         (0x0000FFFF)
#define  IFD_108_nco_scan_range1_input_power_range2(data)                        (0xFFFF0000&((data)<<16))
#define  IFD_108_nco_scan_range1_input_power_range1(data)                        (0x0000FFFF&(data))
#define  IFD_108_nco_scan_range1_get_input_power_range2(data)                    ((0xFFFF0000&(data))>>16)
#define  IFD_108_nco_scan_range1_get_input_power_range1(data)                    (0x0000FFFF&(data))

#define  IFD_108_nco_scan_range4                                                 0x1803229C
#define  IFD_108_nco_scan_range4_reg_addr                                        "0xB803229C"
#define  IFD_108_nco_scan_range4_reg                                             0xB803229C
#define  IFD_108_nco_scan_range4_inst_addr                                       "0x0086"
#define  set_IFD_108_nco_scan_range4_reg(data)                                   (*((volatile unsigned int*)IFD_108_nco_scan_range4_reg)=data)
#define  get_IFD_108_nco_scan_range4_reg                                         (*((volatile unsigned int*)IFD_108_nco_scan_range4_reg))
#define  IFD_108_nco_scan_range4_input_power_range4_shift                        (16)
#define  IFD_108_nco_scan_range4_input_power_range3_shift                        (0)
#define  IFD_108_nco_scan_range4_input_power_range4_mask                         (0xFFFF0000)
#define  IFD_108_nco_scan_range4_input_power_range3_mask                         (0x0000FFFF)
#define  IFD_108_nco_scan_range4_input_power_range4(data)                        (0xFFFF0000&((data)<<16))
#define  IFD_108_nco_scan_range4_input_power_range3(data)                        (0x0000FFFF&(data))
#define  IFD_108_nco_scan_range4_get_input_power_range4(data)                    ((0xFFFF0000&(data))>>16)
#define  IFD_108_nco_scan_range4_get_input_power_range3(data)                    (0x0000FFFF&(data))

#define  IFD_108_input_power_output_if                                           0x180322A0
#define  IFD_108_input_power_output_if_reg_addr                                  "0xB80322A0"
#define  IFD_108_input_power_output_if_reg                                       0xB80322A0
#define  IFD_108_input_power_output_if_inst_addr                                 "0x0087"
#define  set_IFD_108_input_power_output_if_reg(data)                             (*((volatile unsigned int*)IFD_108_input_power_output_if_reg)=data)
#define  get_IFD_108_input_power_output_if_reg                                   (*((volatile unsigned int*)IFD_108_input_power_output_if_reg))
#define  IFD_108_input_power_output_if_input_power_ac_shift                      (16)
#define  IFD_108_input_power_output_if_input_power_pc_shift                      (0)
#define  IFD_108_input_power_output_if_input_power_ac_mask                       (0xFFFF0000)
#define  IFD_108_input_power_output_if_input_power_pc_mask                       (0x0000FFFF)
#define  IFD_108_input_power_output_if_input_power_ac(data)                      (0xFFFF0000&((data)<<16))
#define  IFD_108_input_power_output_if_input_power_pc(data)                      (0x0000FFFF&(data))
#define  IFD_108_input_power_output_if_get_input_power_ac(data)                  ((0xFFFF0000&(data))>>16)
#define  IFD_108_input_power_output_if_get_input_power_pc(data)                  (0x0000FFFF&(data))

#define  IFD_108_input_power_output_00                                           0x180322A4
#define  IFD_108_input_power_output_00_reg_addr                                  "0xB80322A4"
#define  IFD_108_input_power_output_00_reg                                       0xB80322A4
#define  IFD_108_input_power_output_00_inst_addr                                 "0x0088"
#define  set_IFD_108_input_power_output_00_reg(data)                             (*((volatile unsigned int*)IFD_108_input_power_output_00_reg)=data)
#define  get_IFD_108_input_power_output_00_reg                                   (*((volatile unsigned int*)IFD_108_input_power_output_00_reg))
#define  IFD_108_input_power_output_00_input_power_offset_00_shift               (16)
#define  IFD_108_input_power_output_00_input_power_00_shift                      (0)
#define  IFD_108_input_power_output_00_input_power_offset_00_mask                (0xFFFF0000)
#define  IFD_108_input_power_output_00_input_power_00_mask                       (0x0000FFFF)
#define  IFD_108_input_power_output_00_input_power_offset_00(data)               (0xFFFF0000&((data)<<16))
#define  IFD_108_input_power_output_00_input_power_00(data)                      (0x0000FFFF&(data))
#define  IFD_108_input_power_output_00_get_input_power_offset_00(data)           ((0xFFFF0000&(data))>>16)
#define  IFD_108_input_power_output_00_get_input_power_00(data)                  (0x0000FFFF&(data))

#define  IFD_108_input_power_output_01                                           0x180322A8
#define  IFD_108_input_power_output_01_reg_addr                                  "0xB80322A8"
#define  IFD_108_input_power_output_01_reg                                       0xB80322A8
#define  IFD_108_input_power_output_01_inst_addr                                 "0x0089"
#define  set_IFD_108_input_power_output_01_reg(data)                             (*((volatile unsigned int*)IFD_108_input_power_output_01_reg)=data)
#define  get_IFD_108_input_power_output_01_reg                                   (*((volatile unsigned int*)IFD_108_input_power_output_01_reg))
#define  IFD_108_input_power_output_01_input_power_offset_01_shift               (16)
#define  IFD_108_input_power_output_01_input_power_01_shift                      (0)
#define  IFD_108_input_power_output_01_input_power_offset_01_mask                (0xFFFF0000)
#define  IFD_108_input_power_output_01_input_power_01_mask                       (0x0000FFFF)
#define  IFD_108_input_power_output_01_input_power_offset_01(data)               (0xFFFF0000&((data)<<16))
#define  IFD_108_input_power_output_01_input_power_01(data)                      (0x0000FFFF&(data))
#define  IFD_108_input_power_output_01_get_input_power_offset_01(data)           ((0xFFFF0000&(data))>>16)
#define  IFD_108_input_power_output_01_get_input_power_01(data)                  (0x0000FFFF&(data))

#define  IFD_108_input_power_output_02                                           0x180322AC
#define  IFD_108_input_power_output_02_reg_addr                                  "0xB80322AC"
#define  IFD_108_input_power_output_02_reg                                       0xB80322AC
#define  IFD_108_input_power_output_02_inst_addr                                 "0x008A"
#define  set_IFD_108_input_power_output_02_reg(data)                             (*((volatile unsigned int*)IFD_108_input_power_output_02_reg)=data)
#define  get_IFD_108_input_power_output_02_reg                                   (*((volatile unsigned int*)IFD_108_input_power_output_02_reg))
#define  IFD_108_input_power_output_02_input_power_offset_02_shift               (16)
#define  IFD_108_input_power_output_02_input_power_02_shift                      (0)
#define  IFD_108_input_power_output_02_input_power_offset_02_mask                (0xFFFF0000)
#define  IFD_108_input_power_output_02_input_power_02_mask                       (0x0000FFFF)
#define  IFD_108_input_power_output_02_input_power_offset_02(data)               (0xFFFF0000&((data)<<16))
#define  IFD_108_input_power_output_02_input_power_02(data)                      (0x0000FFFF&(data))
#define  IFD_108_input_power_output_02_get_input_power_offset_02(data)           ((0xFFFF0000&(data))>>16)
#define  IFD_108_input_power_output_02_get_input_power_02(data)                  (0x0000FFFF&(data))

#define  IFD_108_input_power_output_03                                           0x180322B0
#define  IFD_108_input_power_output_03_reg_addr                                  "0xB80322B0"
#define  IFD_108_input_power_output_03_reg                                       0xB80322B0
#define  IFD_108_input_power_output_03_inst_addr                                 "0x008B"
#define  set_IFD_108_input_power_output_03_reg(data)                             (*((volatile unsigned int*)IFD_108_input_power_output_03_reg)=data)
#define  get_IFD_108_input_power_output_03_reg                                   (*((volatile unsigned int*)IFD_108_input_power_output_03_reg))
#define  IFD_108_input_power_output_03_input_power_offset_03_shift               (16)
#define  IFD_108_input_power_output_03_input_power_03_shift                      (0)
#define  IFD_108_input_power_output_03_input_power_offset_03_mask                (0xFFFF0000)
#define  IFD_108_input_power_output_03_input_power_03_mask                       (0x0000FFFF)
#define  IFD_108_input_power_output_03_input_power_offset_03(data)               (0xFFFF0000&((data)<<16))
#define  IFD_108_input_power_output_03_input_power_03(data)                      (0x0000FFFF&(data))
#define  IFD_108_input_power_output_03_get_input_power_offset_03(data)           ((0xFFFF0000&(data))>>16)
#define  IFD_108_input_power_output_03_get_input_power_03(data)                  (0x0000FFFF&(data))

#define  IFD_108_input_power_output_04                                           0x180322B4
#define  IFD_108_input_power_output_04_reg_addr                                  "0xB80322B4"
#define  IFD_108_input_power_output_04_reg                                       0xB80322B4
#define  IFD_108_input_power_output_04_inst_addr                                 "0x008C"
#define  set_IFD_108_input_power_output_04_reg(data)                             (*((volatile unsigned int*)IFD_108_input_power_output_04_reg)=data)
#define  get_IFD_108_input_power_output_04_reg                                   (*((volatile unsigned int*)IFD_108_input_power_output_04_reg))
#define  IFD_108_input_power_output_04_input_power_offset_04_shift               (16)
#define  IFD_108_input_power_output_04_input_power_04_shift                      (0)
#define  IFD_108_input_power_output_04_input_power_offset_04_mask                (0xFFFF0000)
#define  IFD_108_input_power_output_04_input_power_04_mask                       (0x0000FFFF)
#define  IFD_108_input_power_output_04_input_power_offset_04(data)               (0xFFFF0000&((data)<<16))
#define  IFD_108_input_power_output_04_input_power_04(data)                      (0x0000FFFF&(data))
#define  IFD_108_input_power_output_04_get_input_power_offset_04(data)           ((0xFFFF0000&(data))>>16)
#define  IFD_108_input_power_output_04_get_input_power_04(data)                  (0x0000FFFF&(data))

#define  IFD_108_input_power_output_05                                           0x180322B8
#define  IFD_108_input_power_output_05_reg_addr                                  "0xB80322B8"
#define  IFD_108_input_power_output_05_reg                                       0xB80322B8
#define  IFD_108_input_power_output_05_inst_addr                                 "0x008D"
#define  set_IFD_108_input_power_output_05_reg(data)                             (*((volatile unsigned int*)IFD_108_input_power_output_05_reg)=data)
#define  get_IFD_108_input_power_output_05_reg                                   (*((volatile unsigned int*)IFD_108_input_power_output_05_reg))
#define  IFD_108_input_power_output_05_input_power_offset_05_shift               (16)
#define  IFD_108_input_power_output_05_input_power_05_shift                      (0)
#define  IFD_108_input_power_output_05_input_power_offset_05_mask                (0xFFFF0000)
#define  IFD_108_input_power_output_05_input_power_05_mask                       (0x0000FFFF)
#define  IFD_108_input_power_output_05_input_power_offset_05(data)               (0xFFFF0000&((data)<<16))
#define  IFD_108_input_power_output_05_input_power_05(data)                      (0x0000FFFF&(data))
#define  IFD_108_input_power_output_05_get_input_power_offset_05(data)           ((0xFFFF0000&(data))>>16)
#define  IFD_108_input_power_output_05_get_input_power_05(data)                  (0x0000FFFF&(data))

#define  IFD_108_input_power_done                                                0x180322BC
#define  IFD_108_input_power_done_reg_addr                                       "0xB80322BC"
#define  IFD_108_input_power_done_reg                                            0xB80322BC
#define  IFD_108_input_power_done_inst_addr                                      "0x008E"
#define  set_IFD_108_input_power_done_reg(data)                                  (*((volatile unsigned int*)IFD_108_input_power_done_reg)=data)
#define  get_IFD_108_input_power_done_reg                                        (*((volatile unsigned int*)IFD_108_input_power_done_reg))
#define  IFD_108_input_power_done_input_power_diff_thr_shift                     (20)
#define  IFD_108_input_power_done_input_power_diff_shift                         (4)
#define  IFD_108_input_power_done_input_power_detect_done_shift                  (0)
#define  IFD_108_input_power_done_input_power_diff_thr_mask                      (0xFFF00000)
#define  IFD_108_input_power_done_input_power_diff_mask                          (0x0007FFF0)
#define  IFD_108_input_power_done_input_power_detect_done_mask                   (0x00000001)
#define  IFD_108_input_power_done_input_power_diff_thr(data)                     (0xFFF00000&((data)<<20))
#define  IFD_108_input_power_done_input_power_diff(data)                         (0x0007FFF0&((data)<<4))
#define  IFD_108_input_power_done_input_power_detect_done(data)                  (0x00000001&(data))
#define  IFD_108_input_power_done_get_input_power_diff_thr(data)                 ((0xFFF00000&(data))>>20)
#define  IFD_108_input_power_done_get_input_power_diff(data)                     ((0x0007FFF0&(data))>>4)
#define  IFD_108_input_power_done_get_input_power_detect_done(data)              (0x00000001&(data))

#define  IFD_108_input_power_output_min                                          0x180322C0
#define  IFD_108_input_power_output_min_reg_addr                                 "0xB80322C0"
#define  IFD_108_input_power_output_min_reg                                      0xB80322C0
#define  IFD_108_input_power_output_min_inst_addr                                "0x008F"
#define  set_IFD_108_input_power_output_min_reg(data)                            (*((volatile unsigned int*)IFD_108_input_power_output_min_reg)=data)
#define  get_IFD_108_input_power_output_min_reg                                  (*((volatile unsigned int*)IFD_108_input_power_output_min_reg))
#define  IFD_108_input_power_output_min_input_power_offset_min_shift             (16)
#define  IFD_108_input_power_output_min_input_power_min_shift                    (0)
#define  IFD_108_input_power_output_min_input_power_offset_min_mask              (0xFFFF0000)
#define  IFD_108_input_power_output_min_input_power_min_mask                     (0x0000FFFF)
#define  IFD_108_input_power_output_min_input_power_offset_min(data)             (0xFFFF0000&((data)<<16))
#define  IFD_108_input_power_output_min_input_power_min(data)                    (0x0000FFFF&(data))
#define  IFD_108_input_power_output_min_get_input_power_offset_min(data)         ((0xFFFF0000&(data))>>16)
#define  IFD_108_input_power_output_min_get_input_power_min(data)                (0x0000FFFF&(data))

#define  IFD_108_input_power_min_diff                                            0x180322C4
#define  IFD_108_input_power_min_diff_reg_addr                                   "0xB80322C4"
#define  IFD_108_input_power_min_diff_reg                                        0xB80322C4
#define  IFD_108_input_power_min_diff_inst_addr                                  "0x0090"
#define  set_IFD_108_input_power_min_diff_reg(data)                              (*((volatile unsigned int*)IFD_108_input_power_min_diff_reg)=data)
#define  get_IFD_108_input_power_min_diff_reg                                    (*((volatile unsigned int*)IFD_108_input_power_min_diff_reg))
#define  IFD_108_input_power_min_diff_input_power_min_diff_shift                 (0)
#define  IFD_108_input_power_min_diff_input_power_min_diff_mask                  (0x0000FFFF)
#define  IFD_108_input_power_min_diff_input_power_min_diff(data)                 (0x0000FFFF&(data))
#define  IFD_108_input_power_min_diff_get_input_power_min_diff(data)             (0x0000FFFF&(data))

#define  IFD_108_input_power_cr_lock                                             0x180322C8
#define  IFD_108_input_power_cr_lock_reg_addr                                    "0xB80322C8"
#define  IFD_108_input_power_cr_lock_reg                                         0xB80322C8
#define  IFD_108_input_power_cr_lock_inst_addr                                   "0x0091"
#define  set_IFD_108_input_power_cr_lock_reg(data)                               (*((volatile unsigned int*)IFD_108_input_power_cr_lock_reg)=data)
#define  get_IFD_108_input_power_cr_lock_reg                                     (*((volatile unsigned int*)IFD_108_input_power_cr_lock_reg))
#define  IFD_108_input_power_cr_lock_cr_lock_power_diff_en_shift                 (16)
#define  IFD_108_input_power_cr_lock_cr_lock_power_diff_thr_shift                (0)
#define  IFD_108_input_power_cr_lock_cr_lock_power_diff_en_mask                  (0x00010000)
#define  IFD_108_input_power_cr_lock_cr_lock_power_diff_thr_mask                 (0x0000FFFF)
#define  IFD_108_input_power_cr_lock_cr_lock_power_diff_en(data)                 (0x00010000&((data)<<16))
#define  IFD_108_input_power_cr_lock_cr_lock_power_diff_thr(data)                (0x0000FFFF&(data))
#define  IFD_108_input_power_cr_lock_get_cr_lock_power_diff_en(data)             ((0x00010000&(data))>>16)
#define  IFD_108_input_power_cr_lock_get_cr_lock_power_diff_thr(data)            (0x0000FFFF&(data))

#define  IFD_108_IFD_BIST_DVS                                                    0x18032300
#define  IFD_108_IFD_BIST_DVS_reg_addr                                           "0xB8032300"
#define  IFD_108_IFD_BIST_DVS_reg                                                0xB8032300
#define  IFD_108_IFD_BIST_DVS_inst_addr                                          "0x0092"
#define  set_IFD_108_IFD_BIST_DVS_reg(data)                                      (*((volatile unsigned int*)IFD_108_IFD_BIST_DVS_reg)=data)
#define  get_IFD_108_IFD_BIST_DVS_reg                                            (*((volatile unsigned int*)IFD_108_IFD_BIST_DVS_reg))
#define  IFD_108_IFD_BIST_DVS_mbist_ifd_dvse_shift                               (4)
#define  IFD_108_IFD_BIST_DVS_mbist_ifd_dvs_shift                                (0)
#define  IFD_108_IFD_BIST_DVS_mbist_ifd_dvse_mask                                (0x00000010)
#define  IFD_108_IFD_BIST_DVS_mbist_ifd_dvs_mask                                 (0x0000000F)
#define  IFD_108_IFD_BIST_DVS_mbist_ifd_dvse(data)                               (0x00000010&((data)<<4))
#define  IFD_108_IFD_BIST_DVS_mbist_ifd_dvs(data)                                (0x0000000F&(data))
#define  IFD_108_IFD_BIST_DVS_get_mbist_ifd_dvse(data)                           ((0x00000010&(data))>>4)
#define  IFD_108_IFD_BIST_DVS_get_mbist_ifd_dvs(data)                            (0x0000000F&(data))

#define  IFD_108_IFD_BIST_MODE                                                   0x18032304
#define  IFD_108_IFD_BIST_MODE_reg_addr                                          "0xB8032304"
#define  IFD_108_IFD_BIST_MODE_reg                                               0xB8032304
#define  IFD_108_IFD_BIST_MODE_inst_addr                                         "0x0093"
#define  set_IFD_108_IFD_BIST_MODE_reg(data)                                     (*((volatile unsigned int*)IFD_108_IFD_BIST_MODE_reg)=data)
#define  get_IFD_108_IFD_BIST_MODE_reg                                           (*((volatile unsigned int*)IFD_108_IFD_BIST_MODE_reg))
#define  IFD_108_IFD_BIST_MODE_bist_mode_ifd_shift                               (0)
#define  IFD_108_IFD_BIST_MODE_bist_mode_ifd_mask                                (0x00000001)
#define  IFD_108_IFD_BIST_MODE_bist_mode_ifd(data)                               (0x00000001&(data))
#define  IFD_108_IFD_BIST_MODE_get_bist_mode_ifd(data)                           (0x00000001&(data))

#define  IFD_108_IFD_DRF_BIST_MODE                                               0x18032308
#define  IFD_108_IFD_DRF_BIST_MODE_reg_addr                                      "0xB8032308"
#define  IFD_108_IFD_DRF_BIST_MODE_reg                                           0xB8032308
#define  IFD_108_IFD_DRF_BIST_MODE_inst_addr                                     "0x0094"
#define  set_IFD_108_IFD_DRF_BIST_MODE_reg(data)                                 (*((volatile unsigned int*)IFD_108_IFD_DRF_BIST_MODE_reg)=data)
#define  get_IFD_108_IFD_DRF_BIST_MODE_reg                                       (*((volatile unsigned int*)IFD_108_IFD_DRF_BIST_MODE_reg))
#define  IFD_108_IFD_DRF_BIST_MODE_drf_bist_mode_ifd_shift                       (0)
#define  IFD_108_IFD_DRF_BIST_MODE_drf_bist_mode_ifd_mask                        (0x00000001)
#define  IFD_108_IFD_DRF_BIST_MODE_drf_bist_mode_ifd(data)                       (0x00000001&(data))
#define  IFD_108_IFD_DRF_BIST_MODE_get_drf_bist_mode_ifd(data)                   (0x00000001&(data))

#define  IFD_108_IFD_DRF_TEST_RESUME                                             0x1803230C
#define  IFD_108_IFD_DRF_TEST_RESUME_reg_addr                                    "0xB803230C"
#define  IFD_108_IFD_DRF_TEST_RESUME_reg                                         0xB803230C
#define  IFD_108_IFD_DRF_TEST_RESUME_inst_addr                                   "0x0095"
#define  set_IFD_108_IFD_DRF_TEST_RESUME_reg(data)                               (*((volatile unsigned int*)IFD_108_IFD_DRF_TEST_RESUME_reg)=data)
#define  get_IFD_108_IFD_DRF_TEST_RESUME_reg                                     (*((volatile unsigned int*)IFD_108_IFD_DRF_TEST_RESUME_reg))
#define  IFD_108_IFD_DRF_TEST_RESUME_drf_test_resume_ifd_shift                   (0)
#define  IFD_108_IFD_DRF_TEST_RESUME_drf_test_resume_ifd_mask                    (0x00000001)
#define  IFD_108_IFD_DRF_TEST_RESUME_drf_test_resume_ifd(data)                   (0x00000001&(data))
#define  IFD_108_IFD_DRF_TEST_RESUME_get_drf_test_resume_ifd(data)               (0x00000001&(data))

#define  IFD_108_IFD_LS_CNTL                                                     0x18032310
#define  IFD_108_IFD_LS_CNTL_reg_addr                                            "0xB8032310"
#define  IFD_108_IFD_LS_CNTL_reg                                                 0xB8032310
#define  IFD_108_IFD_LS_CNTL_inst_addr                                           "0x0096"
#define  set_IFD_108_IFD_LS_CNTL_reg(data)                                       (*((volatile unsigned int*)IFD_108_IFD_LS_CNTL_reg)=data)
#define  get_IFD_108_IFD_LS_CNTL_reg                                             (*((volatile unsigned int*)IFD_108_IFD_LS_CNTL_reg))
#define  IFD_108_IFD_LS_CNTL_mbist_ls_cntl_shift                                 (0)
#define  IFD_108_IFD_LS_CNTL_mbist_ls_cntl_mask                                  (0x00000001)
#define  IFD_108_IFD_LS_CNTL_mbist_ls_cntl(data)                                 (0x00000001&(data))
#define  IFD_108_IFD_LS_CNTL_get_mbist_ls_cntl(data)                             (0x00000001&(data))

#define  IFD_108_IFD_BIST_DONE                                                   0x18032314
#define  IFD_108_IFD_BIST_DONE_reg_addr                                          "0xB8032314"
#define  IFD_108_IFD_BIST_DONE_reg                                               0xB8032314
#define  IFD_108_IFD_BIST_DONE_inst_addr                                         "0x0097"
#define  set_IFD_108_IFD_BIST_DONE_reg(data)                                     (*((volatile unsigned int*)IFD_108_IFD_BIST_DONE_reg)=data)
#define  get_IFD_108_IFD_BIST_DONE_reg                                           (*((volatile unsigned int*)IFD_108_IFD_BIST_DONE_reg))
#define  IFD_108_IFD_BIST_DONE_bist_done_ifd_shift                               (0)
#define  IFD_108_IFD_BIST_DONE_bist_done_ifd_mask                                (0x00000001)
#define  IFD_108_IFD_BIST_DONE_bist_done_ifd(data)                               (0x00000001&(data))
#define  IFD_108_IFD_BIST_DONE_get_bist_done_ifd(data)                           (0x00000001&(data))

#define  IFD_108_IFD_DRF_BIST_DONE                                               0x18032318
#define  IFD_108_IFD_DRF_BIST_DONE_reg_addr                                      "0xB8032318"
#define  IFD_108_IFD_DRF_BIST_DONE_reg                                           0xB8032318
#define  IFD_108_IFD_DRF_BIST_DONE_inst_addr                                     "0x0098"
#define  set_IFD_108_IFD_DRF_BIST_DONE_reg(data)                                 (*((volatile unsigned int*)IFD_108_IFD_DRF_BIST_DONE_reg)=data)
#define  get_IFD_108_IFD_DRF_BIST_DONE_reg                                       (*((volatile unsigned int*)IFD_108_IFD_DRF_BIST_DONE_reg))
#define  IFD_108_IFD_DRF_BIST_DONE_drf_bist_done_ifd_shift                       (0)
#define  IFD_108_IFD_DRF_BIST_DONE_drf_bist_done_ifd_mask                        (0x00000001)
#define  IFD_108_IFD_DRF_BIST_DONE_drf_bist_done_ifd(data)                       (0x00000001&(data))
#define  IFD_108_IFD_DRF_BIST_DONE_get_drf_bist_done_ifd(data)                   (0x00000001&(data))

#define  IFD_108_IFD_BIST_FAIL                                                   0x1803231C
#define  IFD_108_IFD_BIST_FAIL_reg_addr                                          "0xB803231C"
#define  IFD_108_IFD_BIST_FAIL_reg                                               0xB803231C
#define  IFD_108_IFD_BIST_FAIL_inst_addr                                         "0x0099"
#define  set_IFD_108_IFD_BIST_FAIL_reg(data)                                     (*((volatile unsigned int*)IFD_108_IFD_BIST_FAIL_reg)=data)
#define  get_IFD_108_IFD_BIST_FAIL_reg                                           (*((volatile unsigned int*)IFD_108_IFD_BIST_FAIL_reg))
#define  IFD_108_IFD_BIST_FAIL_bist_fail_ifd_shift                               (0)
#define  IFD_108_IFD_BIST_FAIL_bist_fail_ifd_mask                                (0x00000001)
#define  IFD_108_IFD_BIST_FAIL_bist_fail_ifd(data)                               (0x00000001&(data))
#define  IFD_108_IFD_BIST_FAIL_get_bist_fail_ifd(data)                           (0x00000001&(data))

#define  IFD_108_IFD_DRF_BIST_FAIL                                               0x18032320
#define  IFD_108_IFD_DRF_BIST_FAIL_reg_addr                                      "0xB8032320"
#define  IFD_108_IFD_DRF_BIST_FAIL_reg                                           0xB8032320
#define  IFD_108_IFD_DRF_BIST_FAIL_inst_addr                                     "0x009A"
#define  set_IFD_108_IFD_DRF_BIST_FAIL_reg(data)                                 (*((volatile unsigned int*)IFD_108_IFD_DRF_BIST_FAIL_reg)=data)
#define  get_IFD_108_IFD_DRF_BIST_FAIL_reg                                       (*((volatile unsigned int*)IFD_108_IFD_DRF_BIST_FAIL_reg))
#define  IFD_108_IFD_DRF_BIST_FAIL_drf_bist_fail_ifd_shift                       (0)
#define  IFD_108_IFD_DRF_BIST_FAIL_drf_bist_fail_ifd_mask                        (0x00000001)
#define  IFD_108_IFD_DRF_BIST_FAIL_drf_bist_fail_ifd(data)                       (0x00000001&(data))
#define  IFD_108_IFD_DRF_BIST_FAIL_get_drf_bist_fail_ifd(data)                   (0x00000001&(data))

#define  IFD_108_IFD_DRF_BIST_PAUSE                                              0x18032324
#define  IFD_108_IFD_DRF_BIST_PAUSE_reg_addr                                     "0xB8032324"
#define  IFD_108_IFD_DRF_BIST_PAUSE_reg                                          0xB8032324
#define  IFD_108_IFD_DRF_BIST_PAUSE_inst_addr                                    "0x009B"
#define  set_IFD_108_IFD_DRF_BIST_PAUSE_reg(data)                                (*((volatile unsigned int*)IFD_108_IFD_DRF_BIST_PAUSE_reg)=data)
#define  get_IFD_108_IFD_DRF_BIST_PAUSE_reg                                      (*((volatile unsigned int*)IFD_108_IFD_DRF_BIST_PAUSE_reg))
#define  IFD_108_IFD_DRF_BIST_PAUSE_drf_start_pause_ifd_shift                    (0)
#define  IFD_108_IFD_DRF_BIST_PAUSE_drf_start_pause_ifd_mask                     (0x00000001)
#define  IFD_108_IFD_DRF_BIST_PAUSE_drf_start_pause_ifd(data)                    (0x00000001&(data))
#define  IFD_108_IFD_DRF_BIST_PAUSE_get_drf_start_pause_ifd(data)                (0x00000001&(data))

#define  IFD_108_debug_mode                                                      0x18032340
#define  IFD_108_debug_mode_reg_addr                                             "0xB8032340"
#define  IFD_108_debug_mode_reg                                                  0xB8032340
#define  IFD_108_debug_mode_inst_addr                                            "0x009C"
#define  set_IFD_108_debug_mode_reg(data)                                        (*((volatile unsigned int*)IFD_108_debug_mode_reg)=data)
#define  get_IFD_108_debug_mode_reg                                              (*((volatile unsigned int*)IFD_108_debug_mode_reg))
#define  IFD_108_debug_mode_debug_clk27_polar_shift                              (12)
#define  IFD_108_debug_mode_debug_clk49_polar_shift                              (11)
#define  IFD_108_debug_mode_debug_clk54_polar_shift                              (10)
#define  IFD_108_debug_mode_debug_clk108_polar_shift                             (9)
#define  IFD_108_debug_mode_debug_adcclk_polar_shift                             (8)
#define  IFD_108_debug_mode_debug_mode_en_shift                                  (7)
#define  IFD_108_debug_mode_debug_mode_shift                                     (0)
#define  IFD_108_debug_mode_debug_clk27_polar_mask                               (0x00001000)
#define  IFD_108_debug_mode_debug_clk49_polar_mask                               (0x00000800)
#define  IFD_108_debug_mode_debug_clk54_polar_mask                               (0x00000400)
#define  IFD_108_debug_mode_debug_clk108_polar_mask                              (0x00000200)
#define  IFD_108_debug_mode_debug_adcclk_polar_mask                              (0x00000100)
#define  IFD_108_debug_mode_debug_mode_en_mask                                   (0x00000080)
#define  IFD_108_debug_mode_debug_mode_mask                                      (0x0000007F)
#define  IFD_108_debug_mode_debug_clk27_polar(data)                              (0x00001000&((data)<<12))
#define  IFD_108_debug_mode_debug_clk49_polar(data)                              (0x00000800&((data)<<11))
#define  IFD_108_debug_mode_debug_clk54_polar(data)                              (0x00000400&((data)<<10))
#define  IFD_108_debug_mode_debug_clk108_polar(data)                             (0x00000200&((data)<<9))
#define  IFD_108_debug_mode_debug_adcclk_polar(data)                             (0x00000100&((data)<<8))
#define  IFD_108_debug_mode_debug_mode_en(data)                                  (0x00000080&((data)<<7))
#define  IFD_108_debug_mode_debug_mode(data)                                     (0x0000007F&(data))
#define  IFD_108_debug_mode_get_debug_clk27_polar(data)                          ((0x00001000&(data))>>12)
#define  IFD_108_debug_mode_get_debug_clk49_polar(data)                          ((0x00000800&(data))>>11)
#define  IFD_108_debug_mode_get_debug_clk54_polar(data)                          ((0x00000400&(data))>>10)
#define  IFD_108_debug_mode_get_debug_clk108_polar(data)                         ((0x00000200&(data))>>9)
#define  IFD_108_debug_mode_get_debug_adcclk_polar(data)                         ((0x00000100&(data))>>8)
#define  IFD_108_debug_mode_get_debug_mode_en(data)                              ((0x00000080&(data))>>7)
#define  IFD_108_debug_mode_get_debug_mode(data)                                 (0x0000007F&(data))

#define  IFD_108_debug_mode3                                                     0x18032344
#define  IFD_108_debug_mode3_reg_addr                                            "0xB8032344"
#define  IFD_108_debug_mode3_reg                                                 0xB8032344
#define  IFD_108_debug_mode3_inst_addr                                           "0x009D"
#define  set_IFD_108_debug_mode3_reg(data)                                       (*((volatile unsigned int*)IFD_108_debug_mode3_reg)=data)
#define  get_IFD_108_debug_mode3_reg                                             (*((volatile unsigned int*)IFD_108_debug_mode3_reg))
#define  IFD_108_debug_mode3_debug_mode3_en_shift                                (15)
#define  IFD_108_debug_mode3_debug_mode3_shift                                   (8)
#define  IFD_108_debug_mode3_debug_mode3_en_mask                                 (0x00008000)
#define  IFD_108_debug_mode3_debug_mode3_mask                                    (0x00007F00)
#define  IFD_108_debug_mode3_debug_mode3_en(data)                                (0x00008000&((data)<<15))
#define  IFD_108_debug_mode3_debug_mode3(data)                                   (0x00007F00&((data)<<8))
#define  IFD_108_debug_mode3_get_debug_mode3_en(data)                            ((0x00008000&(data))>>15)
#define  IFD_108_debug_mode3_get_debug_mode3(data)                               ((0x00007F00&(data))>>8)

#define  IFD_108_test_mode                                                       0x18032348
#define  IFD_108_test_mode_reg_addr                                              "0xB8032348"
#define  IFD_108_test_mode_reg                                                   0xB8032348
#define  IFD_108_test_mode_inst_addr                                             "0x009E"
#define  set_IFD_108_test_mode_reg(data)                                         (*((volatile unsigned int*)IFD_108_test_mode_reg)=data)
#define  get_IFD_108_test_mode_reg                                               (*((volatile unsigned int*)IFD_108_test_mode_reg))
#define  IFD_108_test_mode_test_mode_en_shift                                    (7)
#define  IFD_108_test_mode_test_mode_shift                                       (0)
#define  IFD_108_test_mode_test_mode_en_mask                                     (0x00000080)
#define  IFD_108_test_mode_test_mode_mask                                        (0x0000007F)
#define  IFD_108_test_mode_test_mode_en(data)                                    (0x00000080&((data)<<7))
#define  IFD_108_test_mode_test_mode(data)                                       (0x0000007F&(data))
#define  IFD_108_test_mode_get_test_mode_en(data)                                ((0x00000080&(data))>>7)
#define  IFD_108_test_mode_get_test_mode(data)                                   (0x0000007F&(data))

#define  IFD_108_cr_self_test                                                    0x1803234C
#define  IFD_108_cr_self_test_reg_addr                                           "0xB803234C"
#define  IFD_108_cr_self_test_reg                                                0xB803234C
#define  IFD_108_cr_self_test_inst_addr                                          "0x009F"
#define  set_IFD_108_cr_self_test_reg(data)                                      (*((volatile unsigned int*)IFD_108_cr_self_test_reg)=data)
#define  get_IFD_108_cr_self_test_reg                                            (*((volatile unsigned int*)IFD_108_cr_self_test_reg))
#define  IFD_108_cr_self_test_cr_self_test_en_shift                              (7)
#define  IFD_108_cr_self_test_agc_self_test_en_shift                             (3)
#define  IFD_108_cr_self_test_agc_self_test_sel_shift                            (2)
#define  IFD_108_cr_self_test_cr_self_test_en_mask                               (0x00000080)
#define  IFD_108_cr_self_test_agc_self_test_en_mask                              (0x00000008)
#define  IFD_108_cr_self_test_agc_self_test_sel_mask                             (0x00000004)
#define  IFD_108_cr_self_test_cr_self_test_en(data)                              (0x00000080&((data)<<7))
#define  IFD_108_cr_self_test_agc_self_test_en(data)                             (0x00000008&((data)<<3))
#define  IFD_108_cr_self_test_agc_self_test_sel(data)                            (0x00000004&((data)<<2))
#define  IFD_108_cr_self_test_get_cr_self_test_en(data)                          ((0x00000080&(data))>>7)
#define  IFD_108_cr_self_test_get_agc_self_test_en(data)                         ((0x00000008&(data))>>3)
#define  IFD_108_cr_self_test_get_agc_self_test_sel(data)                        ((0x00000004&(data))>>2)

#define  IFD_108_CRC_Ctrl_register                                               0x18032350
#define  IFD_108_CRC_Ctrl_register_reg_addr                                      "0xB8032350"
#define  IFD_108_CRC_Ctrl_register_reg                                           0xB8032350
#define  IFD_108_CRC_Ctrl_register_inst_addr                                     "0x00A0"
#define  set_IFD_108_CRC_Ctrl_register_reg(data)                                 (*((volatile unsigned int*)IFD_108_CRC_Ctrl_register_reg)=data)
#define  get_IFD_108_CRC_Ctrl_register_reg                                       (*((volatile unsigned int*)IFD_108_CRC_Ctrl_register_reg))
#define  IFD_108_CRC_Ctrl_register_crc1_insel_shift                              (6)
#define  IFD_108_CRC_Ctrl_register_crc2_en_shift                                 (3)
#define  IFD_108_CRC_Ctrl_register_crc2_insel_shift                              (2)
#define  IFD_108_CRC_Ctrl_register_crc1_insel_mask                               (0x00000040)
#define  IFD_108_CRC_Ctrl_register_crc2_en_mask                                  (0x00000008)
#define  IFD_108_CRC_Ctrl_register_crc2_insel_mask                               (0x00000004)
#define  IFD_108_CRC_Ctrl_register_crc1_insel(data)                              (0x00000040&((data)<<6))
#define  IFD_108_CRC_Ctrl_register_crc2_en(data)                                 (0x00000008&((data)<<3))
#define  IFD_108_CRC_Ctrl_register_crc2_insel(data)                              (0x00000004&((data)<<2))
#define  IFD_108_CRC_Ctrl_register_get_crc1_insel(data)                          ((0x00000040&(data))>>6)
#define  IFD_108_CRC_Ctrl_register_get_crc2_en(data)                             ((0x00000008&(data))>>3)
#define  IFD_108_CRC_Ctrl_register_get_crc2_insel(data)                          ((0x00000004&(data))>>2)

#define  IFD_108_CRC2_result                                                     0x18032358
#define  IFD_108_CRC2_result_reg_addr                                            "0xB8032358"
#define  IFD_108_CRC2_result_reg                                                 0xB8032358
#define  IFD_108_CRC2_result_inst_addr                                           "0x00A1"
#define  set_IFD_108_CRC2_result_reg(data)                                       (*((volatile unsigned int*)IFD_108_CRC2_result_reg)=data)
#define  get_IFD_108_CRC2_result_reg                                             (*((volatile unsigned int*)IFD_108_CRC2_result_reg))
#define  IFD_108_CRC2_result_crc2_result_shift                                   (0)
#define  IFD_108_CRC2_result_crc2_result_mask                                    (0xFFFFFFFF)
#define  IFD_108_CRC2_result_crc2_result(data)                                   (0xFFFFFFFF&(data))
#define  IFD_108_CRC2_result_get_crc2_result(data)                               (0xFFFFFFFF&(data))

#define  IFD_108_DACtest_register1                                               0x1803235C
#define  IFD_108_DACtest_register1_reg_addr                                      "0xB803235C"
#define  IFD_108_DACtest_register1_reg                                           0xB803235C
#define  IFD_108_DACtest_register1_inst_addr                                     "0x00A2"
#define  set_IFD_108_DACtest_register1_reg(data)                                 (*((volatile unsigned int*)IFD_108_DACtest_register1_reg)=data)
#define  get_IFD_108_DACtest_register1_reg                                       (*((volatile unsigned int*)IFD_108_DACtest_register1_reg))
#define  IFD_108_DACtest_register1_dactest_sel_shift                             (16)
#define  IFD_108_DACtest_register1_sinout_sel_shift                              (12)
#define  IFD_108_DACtest_register1_dac_dctest_shift                              (0)
#define  IFD_108_DACtest_register1_dactest_sel_mask                              (0x00010000)
#define  IFD_108_DACtest_register1_sinout_sel_mask                               (0x00001000)
#define  IFD_108_DACtest_register1_dac_dctest_mask                               (0x00000FFF)
#define  IFD_108_DACtest_register1_dactest_sel(data)                             (0x00010000&((data)<<16))
#define  IFD_108_DACtest_register1_sinout_sel(data)                              (0x00001000&((data)<<12))
#define  IFD_108_DACtest_register1_dac_dctest(data)                              (0x00000FFF&(data))
#define  IFD_108_DACtest_register1_get_dactest_sel(data)                         ((0x00010000&(data))>>16)
#define  IFD_108_DACtest_register1_get_sinout_sel(data)                          ((0x00001000&(data))>>12)
#define  IFD_108_DACtest_register1_get_dac_dctest(data)                          (0x00000FFF&(data))

#define  IFD_108_adbypassenable                                                  0x18032360
#define  IFD_108_adbypassenable_reg_addr                                         "0xB8032360"
#define  IFD_108_adbypassenable_reg                                              0xB8032360
#define  IFD_108_adbypassenable_inst_addr                                        "0x00A3"
#define  set_IFD_108_adbypassenable_reg(data)                                    (*((volatile unsigned int*)IFD_108_adbypassenable_reg)=data)
#define  get_IFD_108_adbypassenable_reg                                          (*((volatile unsigned int*)IFD_108_adbypassenable_reg))
#define  IFD_108_adbypassenable_bypassad_shift                                   (0)
#define  IFD_108_adbypassenable_bypassad_mask                                    (0x00000001)
#define  IFD_108_adbypassenable_bypassad(data)                                   (0x00000001&(data))
#define  IFD_108_adbypassenable_get_bypassad(data)                               (0x00000001&(data))

#define  IFD_108_fpga_test1                                                      0x18032380
#define  IFD_108_fpga_test1_reg_addr                                             "0xB8032380"
#define  IFD_108_fpga_test1_reg                                                  0xB8032380
#define  IFD_108_fpga_test1_inst_addr                                            "0x00A4"
#define  set_IFD_108_fpga_test1_reg(data)                                        (*((volatile unsigned int*)IFD_108_fpga_test1_reg)=data)
#define  get_IFD_108_fpga_test1_reg                                              (*((volatile unsigned int*)IFD_108_fpga_test1_reg))
#define  IFD_108_fpga_test1_fpga_test1_shift                                     (0)
#define  IFD_108_fpga_test1_fpga_test1_mask                                      (0xFFFFFFFF)
#define  IFD_108_fpga_test1_fpga_test1(data)                                     (0xFFFFFFFF&(data))
#define  IFD_108_fpga_test1_get_fpga_test1(data)                                 (0xFFFFFFFF&(data))

#define  IFD_108_fpga_test2                                                      0x18032384
#define  IFD_108_fpga_test2_reg_addr                                             "0xB8032384"
#define  IFD_108_fpga_test2_reg                                                  0xB8032384
#define  IFD_108_fpga_test2_inst_addr                                            "0x00A5"
#define  set_IFD_108_fpga_test2_reg(data)                                        (*((volatile unsigned int*)IFD_108_fpga_test2_reg)=data)
#define  get_IFD_108_fpga_test2_reg                                              (*((volatile unsigned int*)IFD_108_fpga_test2_reg))
#define  IFD_108_fpga_test2_fpga_test2_shift                                     (0)
#define  IFD_108_fpga_test2_fpga_test2_mask                                      (0xFFFFFFFF)
#define  IFD_108_fpga_test2_fpga_test2(data)                                     (0xFFFFFFFF&(data))
#define  IFD_108_fpga_test2_get_fpga_test2(data)                                 (0xFFFFFFFF&(data))

#define  IFD_108_fpga_test3                                                      0x18032388
#define  IFD_108_fpga_test3_reg_addr                                             "0xB8032388"
#define  IFD_108_fpga_test3_reg                                                  0xB8032388
#define  IFD_108_fpga_test3_inst_addr                                            "0x00A6"
#define  set_IFD_108_fpga_test3_reg(data)                                        (*((volatile unsigned int*)IFD_108_fpga_test3_reg)=data)
#define  get_IFD_108_fpga_test3_reg                                              (*((volatile unsigned int*)IFD_108_fpga_test3_reg))
#define  IFD_108_fpga_test3_fpga_test3_shift                                     (0)
#define  IFD_108_fpga_test3_fpga_test3_mask                                      (0xFFFFFFFF)
#define  IFD_108_fpga_test3_fpga_test3(data)                                     (0xFFFFFFFF&(data))
#define  IFD_108_fpga_test3_get_fpga_test3(data)                                 (0xFFFFFFFF&(data))

#define  IFD_108_fpga_test4_debug_clk                                            0x1803238C
#define  IFD_108_fpga_test4_debug_clk_reg_addr                                   "0xB803238C"
#define  IFD_108_fpga_test4_debug_clk_reg                                        0xB803238C
#define  IFD_108_fpga_test4_debug_clk_inst_addr                                  "0x00A7"
#define  set_IFD_108_fpga_test4_debug_clk_reg(data)                              (*((volatile unsigned int*)IFD_108_fpga_test4_debug_clk_reg)=data)
#define  get_IFD_108_fpga_test4_debug_clk_reg                                    (*((volatile unsigned int*)IFD_108_fpga_test4_debug_clk_reg))
#define  IFD_108_fpga_test4_debug_clk_fpga_test4_shift                           (5)
#define  IFD_108_fpga_test4_debug_clk_debug_clk5_shift                           (4)
#define  IFD_108_fpga_test4_debug_clk_debug_clk4_shift                           (3)
#define  IFD_108_fpga_test4_debug_clk_debug_clk3_shift                           (2)
#define  IFD_108_fpga_test4_debug_clk_debug_clk2_shift                           (1)
#define  IFD_108_fpga_test4_debug_clk_debug_clk1_shift                           (0)
#define  IFD_108_fpga_test4_debug_clk_fpga_test4_mask                            (0xFFFFFFE0)
#define  IFD_108_fpga_test4_debug_clk_debug_clk5_mask                            (0x00000010)
#define  IFD_108_fpga_test4_debug_clk_debug_clk4_mask                            (0x00000008)
#define  IFD_108_fpga_test4_debug_clk_debug_clk3_mask                            (0x00000004)
#define  IFD_108_fpga_test4_debug_clk_debug_clk2_mask                            (0x00000002)
#define  IFD_108_fpga_test4_debug_clk_debug_clk1_mask                            (0x00000001)
#define  IFD_108_fpga_test4_debug_clk_fpga_test4(data)                           (0xFFFFFFE0&((data)<<5))
#define  IFD_108_fpga_test4_debug_clk_debug_clk5(data)                           (0x00000010&((data)<<4))
#define  IFD_108_fpga_test4_debug_clk_debug_clk4(data)                           (0x00000008&((data)<<3))
#define  IFD_108_fpga_test4_debug_clk_debug_clk3(data)                           (0x00000004&((data)<<2))
#define  IFD_108_fpga_test4_debug_clk_debug_clk2(data)                           (0x00000002&((data)<<1))
#define  IFD_108_fpga_test4_debug_clk_debug_clk1(data)                           (0x00000001&(data))
#define  IFD_108_fpga_test4_debug_clk_get_fpga_test4(data)                       ((0xFFFFFFE0&(data))>>5)
#define  IFD_108_fpga_test4_debug_clk_get_debug_clk5(data)                       ((0x00000010&(data))>>4)
#define  IFD_108_fpga_test4_debug_clk_get_debug_clk4(data)                       ((0x00000008&(data))>>3)
#define  IFD_108_fpga_test4_debug_clk_get_debug_clk3(data)                       ((0x00000004&(data))>>2)
#define  IFD_108_fpga_test4_debug_clk_get_debug_clk2(data)                       ((0x00000002&(data))>>1)
#define  IFD_108_fpga_test4_debug_clk_get_debug_clk1(data)                       (0x00000001&(data))

#define  IFD_108_interrupt                                                       0x18032390
#define  IFD_108_interrupt_reg_addr                                              "0xB8032390"
#define  IFD_108_interrupt_reg                                                   0xB8032390
#define  IFD_108_interrupt_inst_addr                                             "0x00A8"
#define  set_IFD_108_interrupt_reg(data)                                         (*((volatile unsigned int*)IFD_108_interrupt_reg)=data)
#define  get_IFD_108_interrupt_reg                                               (*((volatile unsigned int*)IFD_108_interrupt_reg))
#define  IFD_108_interrupt_input_power_lower_int_shift                           (14)
#define  IFD_108_interrupt_input_power_over_int_shift                            (13)
#define  IFD_108_interrupt_if_w2s_int_shift                                      (12)
#define  IFD_108_interrupt_if_s2w_int_shift                                      (11)
#define  IFD_108_interrupt_rf_w2s_int_shift                                      (10)
#define  IFD_108_interrupt_rf_s2w_int_shift                                      (9)
#define  IFD_108_interrupt_pga_w2s_int_shift                                     (8)
#define  IFD_108_interrupt_pga_s2w_int_shift                                     (7)
#define  IFD_108_interrupt_agc_unlock_int_shift                                  (6)
#define  IFD_108_interrupt_mod_state_int_shift                                   (5)
#define  IFD_108_interrupt_cr_unlock_int_shift                                   (4)
#define  IFD_108_interrupt_input_fifo_int_shift                                  (3)
#define  IFD_108_interrupt_rf_agc_max_int_shift                                  (2)
#define  IFD_108_interrupt_agc_lock_int_shift                                    (1)
#define  IFD_108_interrupt_cr_lock_int_shift                                     (0)
#define  IFD_108_interrupt_input_power_lower_int_mask                            (0x00004000)
#define  IFD_108_interrupt_input_power_over_int_mask                             (0x00002000)
#define  IFD_108_interrupt_if_w2s_int_mask                                       (0x00001000)
#define  IFD_108_interrupt_if_s2w_int_mask                                       (0x00000800)
#define  IFD_108_interrupt_rf_w2s_int_mask                                       (0x00000400)
#define  IFD_108_interrupt_rf_s2w_int_mask                                       (0x00000200)
#define  IFD_108_interrupt_pga_w2s_int_mask                                      (0x00000100)
#define  IFD_108_interrupt_pga_s2w_int_mask                                      (0x00000080)
#define  IFD_108_interrupt_agc_unlock_int_mask                                   (0x00000040)
#define  IFD_108_interrupt_mod_state_int_mask                                    (0x00000020)
#define  IFD_108_interrupt_cr_unlock_int_mask                                    (0x00000010)
#define  IFD_108_interrupt_input_fifo_int_mask                                   (0x00000008)
#define  IFD_108_interrupt_rf_agc_max_int_mask                                   (0x00000004)
#define  IFD_108_interrupt_agc_lock_int_mask                                     (0x00000002)
#define  IFD_108_interrupt_cr_lock_int_mask                                      (0x00000001)
#define  IFD_108_interrupt_input_power_lower_int(data)                           (0x00004000&((data)<<14))
#define  IFD_108_interrupt_input_power_over_int(data)                            (0x00002000&((data)<<13))
#define  IFD_108_interrupt_if_w2s_int(data)                                      (0x00001000&((data)<<12))
#define  IFD_108_interrupt_if_s2w_int(data)                                      (0x00000800&((data)<<11))
#define  IFD_108_interrupt_rf_w2s_int(data)                                      (0x00000400&((data)<<10))
#define  IFD_108_interrupt_rf_s2w_int(data)                                      (0x00000200&((data)<<9))
#define  IFD_108_interrupt_pga_w2s_int(data)                                     (0x00000100&((data)<<8))
#define  IFD_108_interrupt_pga_s2w_int(data)                                     (0x00000080&((data)<<7))
#define  IFD_108_interrupt_agc_unlock_int(data)                                  (0x00000040&((data)<<6))
#define  IFD_108_interrupt_mod_state_int(data)                                   (0x00000020&((data)<<5))
#define  IFD_108_interrupt_cr_unlock_int(data)                                   (0x00000010&((data)<<4))
#define  IFD_108_interrupt_input_fifo_int(data)                                  (0x00000008&((data)<<3))
#define  IFD_108_interrupt_rf_agc_max_int(data)                                  (0x00000004&((data)<<2))
#define  IFD_108_interrupt_agc_lock_int(data)                                    (0x00000002&((data)<<1))
#define  IFD_108_interrupt_cr_lock_int(data)                                     (0x00000001&(data))
#define  IFD_108_interrupt_get_input_power_lower_int(data)                       ((0x00004000&(data))>>14)
#define  IFD_108_interrupt_get_input_power_over_int(data)                        ((0x00002000&(data))>>13)
#define  IFD_108_interrupt_get_if_w2s_int(data)                                  ((0x00001000&(data))>>12)
#define  IFD_108_interrupt_get_if_s2w_int(data)                                  ((0x00000800&(data))>>11)
#define  IFD_108_interrupt_get_rf_w2s_int(data)                                  ((0x00000400&(data))>>10)
#define  IFD_108_interrupt_get_rf_s2w_int(data)                                  ((0x00000200&(data))>>9)
#define  IFD_108_interrupt_get_pga_w2s_int(data)                                 ((0x00000100&(data))>>8)
#define  IFD_108_interrupt_get_pga_s2w_int(data)                                 ((0x00000080&(data))>>7)
#define  IFD_108_interrupt_get_agc_unlock_int(data)                              ((0x00000040&(data))>>6)
#define  IFD_108_interrupt_get_mod_state_int(data)                               ((0x00000020&(data))>>5)
#define  IFD_108_interrupt_get_cr_unlock_int(data)                               ((0x00000010&(data))>>4)
#define  IFD_108_interrupt_get_input_fifo_int(data)                              ((0x00000008&(data))>>3)
#define  IFD_108_interrupt_get_rf_agc_max_int(data)                              ((0x00000004&(data))>>2)
#define  IFD_108_interrupt_get_agc_lock_int(data)                                ((0x00000002&(data))>>1)
#define  IFD_108_interrupt_get_cr_lock_int(data)                                 (0x00000001&(data))

#define  IFD_108_interrupt_mask_en                                               0x18032394
#define  IFD_108_interrupt_mask_en_reg_addr                                      "0xB8032394"
#define  IFD_108_interrupt_mask_en_reg                                           0xB8032394
#define  IFD_108_interrupt_mask_en_inst_addr                                     "0x00A9"
#define  set_IFD_108_interrupt_mask_en_reg(data)                                 (*((volatile unsigned int*)IFD_108_interrupt_mask_en_reg)=data)
#define  get_IFD_108_interrupt_mask_en_reg                                       (*((volatile unsigned int*)IFD_108_interrupt_mask_en_reg))
#define  IFD_108_interrupt_mask_en_ifd_int_mask_shift                            (15)
#define  IFD_108_interrupt_mask_en_mask_input_power_lower_en_shift               (14)
#define  IFD_108_interrupt_mask_en_mask_input_power_over_en_shift                (13)
#define  IFD_108_interrupt_mask_en_mask_if_w2s_en_shift                          (12)
#define  IFD_108_interrupt_mask_en_mask_if_s2w_en_shift                          (11)
#define  IFD_108_interrupt_mask_en_mask_rf_w2s_en_shift                          (10)
#define  IFD_108_interrupt_mask_en_mask_rf_s2w_en_shift                          (9)
#define  IFD_108_interrupt_mask_en_mask_pga_w2s_en_shift                         (8)
#define  IFD_108_interrupt_mask_en_mask_pga_s2w_en_shift                         (7)
#define  IFD_108_interrupt_mask_en_mask_agc_unlock_en_shift                      (6)
#define  IFD_108_interrupt_mask_en_mask_mod_state_en_shift                       (5)
#define  IFD_108_interrupt_mask_en_mask_cr_unlock_en_shift                       (4)
#define  IFD_108_interrupt_mask_en_mask_input_fifo_status_en_shift               (3)
#define  IFD_108_interrupt_mask_en_mask_rf_agc_max_en_shift                      (2)
#define  IFD_108_interrupt_mask_en_mask_agc_lock_en_shift                        (1)
#define  IFD_108_interrupt_mask_en_mask_cr_lock_en_shift                         (0)
#define  IFD_108_interrupt_mask_en_ifd_int_mask_mask                             (0x00008000)
#define  IFD_108_interrupt_mask_en_mask_input_power_lower_en_mask                (0x00004000)
#define  IFD_108_interrupt_mask_en_mask_input_power_over_en_mask                 (0x00002000)
#define  IFD_108_interrupt_mask_en_mask_if_w2s_en_mask                           (0x00001000)
#define  IFD_108_interrupt_mask_en_mask_if_s2w_en_mask                           (0x00000800)
#define  IFD_108_interrupt_mask_en_mask_rf_w2s_en_mask                           (0x00000400)
#define  IFD_108_interrupt_mask_en_mask_rf_s2w_en_mask                           (0x00000200)
#define  IFD_108_interrupt_mask_en_mask_pga_w2s_en_mask                          (0x00000100)
#define  IFD_108_interrupt_mask_en_mask_pga_s2w_en_mask                          (0x00000080)
#define  IFD_108_interrupt_mask_en_mask_agc_unlock_en_mask                       (0x00000040)
#define  IFD_108_interrupt_mask_en_mask_mod_state_en_mask                        (0x00000020)
#define  IFD_108_interrupt_mask_en_mask_cr_unlock_en_mask                        (0x00000010)
#define  IFD_108_interrupt_mask_en_mask_input_fifo_status_en_mask                (0x00000008)
#define  IFD_108_interrupt_mask_en_mask_rf_agc_max_en_mask                       (0x00000004)
#define  IFD_108_interrupt_mask_en_mask_agc_lock_en_mask                         (0x00000002)
#define  IFD_108_interrupt_mask_en_mask_cr_lock_en_mask                          (0x00000001)
#define  IFD_108_interrupt_mask_en_ifd_int_mask(data)                            (0x00008000&((data)<<15))
#define  IFD_108_interrupt_mask_en_mask_input_power_lower_en(data)               (0x00004000&((data)<<14))
#define  IFD_108_interrupt_mask_en_mask_input_power_over_en(data)                (0x00002000&((data)<<13))
#define  IFD_108_interrupt_mask_en_mask_if_w2s_en(data)                          (0x00001000&((data)<<12))
#define  IFD_108_interrupt_mask_en_mask_if_s2w_en(data)                          (0x00000800&((data)<<11))
#define  IFD_108_interrupt_mask_en_mask_rf_w2s_en(data)                          (0x00000400&((data)<<10))
#define  IFD_108_interrupt_mask_en_mask_rf_s2w_en(data)                          (0x00000200&((data)<<9))
#define  IFD_108_interrupt_mask_en_mask_pga_w2s_en(data)                         (0x00000100&((data)<<8))
#define  IFD_108_interrupt_mask_en_mask_pga_s2w_en(data)                         (0x00000080&((data)<<7))
#define  IFD_108_interrupt_mask_en_mask_agc_unlock_en(data)                      (0x00000040&((data)<<6))
#define  IFD_108_interrupt_mask_en_mask_mod_state_en(data)                       (0x00000020&((data)<<5))
#define  IFD_108_interrupt_mask_en_mask_cr_unlock_en(data)                       (0x00000010&((data)<<4))
#define  IFD_108_interrupt_mask_en_mask_input_fifo_status_en(data)               (0x00000008&((data)<<3))
#define  IFD_108_interrupt_mask_en_mask_rf_agc_max_en(data)                      (0x00000004&((data)<<2))
#define  IFD_108_interrupt_mask_en_mask_agc_lock_en(data)                        (0x00000002&((data)<<1))
#define  IFD_108_interrupt_mask_en_mask_cr_lock_en(data)                         (0x00000001&(data))
#define  IFD_108_interrupt_mask_en_get_ifd_int_mask(data)                        ((0x00008000&(data))>>15)
#define  IFD_108_interrupt_mask_en_get_mask_input_power_lower_en(data)           ((0x00004000&(data))>>14)
#define  IFD_108_interrupt_mask_en_get_mask_input_power_over_en(data)            ((0x00002000&(data))>>13)
#define  IFD_108_interrupt_mask_en_get_mask_if_w2s_en(data)                      ((0x00001000&(data))>>12)
#define  IFD_108_interrupt_mask_en_get_mask_if_s2w_en(data)                      ((0x00000800&(data))>>11)
#define  IFD_108_interrupt_mask_en_get_mask_rf_w2s_en(data)                      ((0x00000400&(data))>>10)
#define  IFD_108_interrupt_mask_en_get_mask_rf_s2w_en(data)                      ((0x00000200&(data))>>9)
#define  IFD_108_interrupt_mask_en_get_mask_pga_w2s_en(data)                     ((0x00000100&(data))>>8)
#define  IFD_108_interrupt_mask_en_get_mask_pga_s2w_en(data)                     ((0x00000080&(data))>>7)
#define  IFD_108_interrupt_mask_en_get_mask_agc_unlock_en(data)                  ((0x00000040&(data))>>6)
#define  IFD_108_interrupt_mask_en_get_mask_mod_state_en(data)                   ((0x00000020&(data))>>5)
#define  IFD_108_interrupt_mask_en_get_mask_cr_unlock_en(data)                   ((0x00000010&(data))>>4)
#define  IFD_108_interrupt_mask_en_get_mask_input_fifo_status_en(data)           ((0x00000008&(data))>>3)
#define  IFD_108_interrupt_mask_en_get_mask_rf_agc_max_en(data)                  ((0x00000004&(data))>>2)
#define  IFD_108_interrupt_mask_en_get_mask_agc_lock_en(data)                    ((0x00000002&(data))>>1)
#define  IFD_108_interrupt_mask_en_get_mask_cr_lock_en(data)                     (0x00000001&(data))

#define  IFD_108_video_bw_sel                                                    0x18032600
#define  IFD_108_video_bw_sel_reg_addr                                           "0xB8032600"
#define  IFD_108_video_bw_sel_reg                                                0xB8032600
#define  IFD_108_video_bw_sel_inst_addr                                          "0x00AA"
#define  set_IFD_108_video_bw_sel_reg(data)                                      (*((volatile unsigned int*)IFD_108_video_bw_sel_reg)=data)
#define  get_IFD_108_video_bw_sel_reg                                            (*((volatile unsigned int*)IFD_108_video_bw_sel_reg))
#define  IFD_108_video_bw_sel_output_lpf_1m_shift                                (8)
#define  IFD_108_video_bw_sel_video_bw_sel_shift                                 (4)
#define  IFD_108_video_bw_sel_video_upsample_lp_sel_shift                        (0)
#define  IFD_108_video_bw_sel_output_lpf_1m_mask                                 (0x00000100)
#define  IFD_108_video_bw_sel_video_bw_sel_mask                                  (0x00000010)
#define  IFD_108_video_bw_sel_video_upsample_lp_sel_mask                         (0x0000000F)
#define  IFD_108_video_bw_sel_output_lpf_1m(data)                                (0x00000100&((data)<<8))
#define  IFD_108_video_bw_sel_video_bw_sel(data)                                 (0x00000010&((data)<<4))
#define  IFD_108_video_bw_sel_video_upsample_lp_sel(data)                        (0x0000000F&(data))
#define  IFD_108_video_bw_sel_get_output_lpf_1m(data)                            ((0x00000100&(data))>>8)
#define  IFD_108_video_bw_sel_get_video_bw_sel(data)                             ((0x00000010&(data))>>4)
#define  IFD_108_video_bw_sel_get_video_upsample_lp_sel(data)                    (0x0000000F&(data))

#define  IFD_108_grp_delay_en                                                    0x18032604
#define  IFD_108_grp_delay_en_reg_addr                                           "0xB8032604"
#define  IFD_108_grp_delay_en_reg                                                0xB8032604
#define  IFD_108_grp_delay_en_inst_addr                                          "0x00AB"
#define  set_IFD_108_grp_delay_en_reg(data)                                      (*((volatile unsigned int*)IFD_108_grp_delay_en_reg)=data)
#define  get_IFD_108_grp_delay_en_reg                                            (*((volatile unsigned int*)IFD_108_grp_delay_en_reg))
#define  IFD_108_grp_delay_en_grp_delay_en_shift                                 (24)
#define  IFD_108_grp_delay_en_grp_delay_coe_en_shift                             (20)
#define  IFD_108_grp_delay_en_grp_delay_select_tap_shift                         (12)
#define  IFD_108_grp_delay_en_grp_delay_coe_modofy_shift                         (0)
#define  IFD_108_grp_delay_en_grp_delay_en_mask                                  (0x01000000)
#define  IFD_108_grp_delay_en_grp_delay_coe_en_mask                              (0x00100000)
#define  IFD_108_grp_delay_en_grp_delay_select_tap_mask                          (0x000FF000)
#define  IFD_108_grp_delay_en_grp_delay_coe_modofy_mask                          (0x000007FF)
#define  IFD_108_grp_delay_en_grp_delay_en(data)                                 (0x01000000&((data)<<24))
#define  IFD_108_grp_delay_en_grp_delay_coe_en(data)                             (0x00100000&((data)<<20))
#define  IFD_108_grp_delay_en_grp_delay_select_tap(data)                         (0x000FF000&((data)<<12))
#define  IFD_108_grp_delay_en_grp_delay_coe_modofy(data)                         (0x000007FF&(data))
#define  IFD_108_grp_delay_en_get_grp_delay_en(data)                             ((0x01000000&(data))>>24)
#define  IFD_108_grp_delay_en_get_grp_delay_coe_en(data)                         ((0x00100000&(data))>>20)
#define  IFD_108_grp_delay_en_get_grp_delay_select_tap(data)                     ((0x000FF000&(data))>>12)
#define  IFD_108_grp_delay_en_get_grp_delay_coe_modofy(data)                     (0x000007FF&(data))

#define  IFD_108_grp_delay_read                                                  0x18032608
#define  IFD_108_grp_delay_read_reg_addr                                         "0xB8032608"
#define  IFD_108_grp_delay_read_reg                                              0xB8032608
#define  IFD_108_grp_delay_read_inst_addr                                        "0x00AC"
#define  set_IFD_108_grp_delay_read_reg(data)                                    (*((volatile unsigned int*)IFD_108_grp_delay_read_reg)=data)
#define  get_IFD_108_grp_delay_read_reg                                          (*((volatile unsigned int*)IFD_108_grp_delay_read_reg))
#define  IFD_108_grp_delay_read_grp_delay_select_tap_read_shift                  (12)
#define  IFD_108_grp_delay_read_grp_delay_coe_modofy_read_shift                  (0)
#define  IFD_108_grp_delay_read_grp_delay_select_tap_read_mask                   (0x000FF000)
#define  IFD_108_grp_delay_read_grp_delay_coe_modofy_read_mask                   (0x000007FF)
#define  IFD_108_grp_delay_read_grp_delay_select_tap_read(data)                  (0x000FF000&((data)<<12))
#define  IFD_108_grp_delay_read_grp_delay_coe_modofy_read(data)                  (0x000007FF&(data))
#define  IFD_108_grp_delay_read_get_grp_delay_select_tap_read(data)              ((0x000FF000&(data))>>12)
#define  IFD_108_grp_delay_read_get_grp_delay_coe_modofy_read(data)              (0x000007FF&(data))

#define  IFD_108_output_lpf_modify_en                                            0x18032610
#define  IFD_108_output_lpf_modify_en_reg_addr                                   "0xB8032610"
#define  IFD_108_output_lpf_modify_en_reg                                        0xB8032610
#define  IFD_108_output_lpf_modify_en_inst_addr                                  "0x00AD"
#define  set_IFD_108_output_lpf_modify_en_reg(data)                              (*((volatile unsigned int*)IFD_108_output_lpf_modify_en_reg)=data)
#define  get_IFD_108_output_lpf_modify_en_reg                                    (*((volatile unsigned int*)IFD_108_output_lpf_modify_en_reg))
#define  IFD_108_output_lpf_modify_en_output_lpf_vsync_coe_change_shift          (29)
#define  IFD_108_output_lpf_modify_en_output_lpf_coe_modify_en_shift             (24)
#define  IFD_108_output_lpf_modify_en_output_lpf_coe_tap_shift                   (16)
#define  IFD_108_output_lpf_modify_en_output_lpf_coe_shift                       (0)
#define  IFD_108_output_lpf_modify_en_output_lpf_vsync_coe_change_mask           (0x20000000)
#define  IFD_108_output_lpf_modify_en_output_lpf_coe_modify_en_mask              (0x01000000)
#define  IFD_108_output_lpf_modify_en_output_lpf_coe_tap_mask                    (0x007F0000)
#define  IFD_108_output_lpf_modify_en_output_lpf_coe_mask                        (0x00003FFF)
#define  IFD_108_output_lpf_modify_en_output_lpf_vsync_coe_change(data)          (0x20000000&((data)<<29))
#define  IFD_108_output_lpf_modify_en_output_lpf_coe_modify_en(data)             (0x01000000&((data)<<24))
#define  IFD_108_output_lpf_modify_en_output_lpf_coe_tap(data)                   (0x007F0000&((data)<<16))
#define  IFD_108_output_lpf_modify_en_output_lpf_coe(data)                       (0x00003FFF&(data))
#define  IFD_108_output_lpf_modify_en_get_output_lpf_vsync_coe_change(data)      ((0x20000000&(data))>>29)
#define  IFD_108_output_lpf_modify_en_get_output_lpf_coe_modify_en(data)         ((0x01000000&(data))>>24)
#define  IFD_108_output_lpf_modify_en_get_output_lpf_coe_tap(data)               ((0x007F0000&(data))>>16)
#define  IFD_108_output_lpf_modify_en_get_output_lpf_coe(data)                   (0x00003FFF&(data))

#define  IFD_108_output_lpf_read                                                 0x18032614
#define  IFD_108_output_lpf_read_reg_addr                                        "0xB8032614"
#define  IFD_108_output_lpf_read_reg                                             0xB8032614
#define  IFD_108_output_lpf_read_inst_addr                                       "0x00AE"
#define  set_IFD_108_output_lpf_read_reg(data)                                   (*((volatile unsigned int*)IFD_108_output_lpf_read_reg)=data)
#define  get_IFD_108_output_lpf_read_reg                                         (*((volatile unsigned int*)IFD_108_output_lpf_read_reg))
#define  IFD_108_output_lpf_read_output_lpf_coe_read_tap_shift                   (16)
#define  IFD_108_output_lpf_read_output_lpf_coe_read_shift                       (0)
#define  IFD_108_output_lpf_read_output_lpf_coe_read_tap_mask                    (0x007F0000)
#define  IFD_108_output_lpf_read_output_lpf_coe_read_mask                        (0x00003FFF)
#define  IFD_108_output_lpf_read_output_lpf_coe_read_tap(data)                   (0x007F0000&((data)<<16))
#define  IFD_108_output_lpf_read_output_lpf_coe_read(data)                       (0x00003FFF&(data))
#define  IFD_108_output_lpf_read_get_output_lpf_coe_read_tap(data)               ((0x007F0000&(data))>>16)
#define  IFD_108_output_lpf_read_get_output_lpf_coe_read(data)                   (0x00003FFF&(data))

#define  IFD_108_dnlpf_tap                                                       0x18032618
#define  IFD_108_dnlpf_tap_reg_addr                                              "0xB8032618"
#define  IFD_108_dnlpf_tap_reg                                                   0xB8032618
#define  IFD_108_dnlpf_tap_inst_addr                                             "0x00AF"
#define  set_IFD_108_dnlpf_tap_reg(data)                                         (*((volatile unsigned int*)IFD_108_dnlpf_tap_reg)=data)
#define  get_IFD_108_dnlpf_tap_reg                                               (*((volatile unsigned int*)IFD_108_dnlpf_tap_reg))
#define  IFD_108_dnlpf_tap_dnlpf_en_shift                                        (24)
#define  IFD_108_dnlpf_tap_dnlpf_en_mask                                         (0x01000000)
#define  IFD_108_dnlpf_tap_dnlpf_en(data)                                        (0x01000000&((data)<<24))
#define  IFD_108_dnlpf_tap_get_dnlpf_en(data)                                    ((0x01000000&(data))>>24)

#define  IFD_108_eq_filter_sel                                                   0x18032620
#define  IFD_108_eq_filter_sel_reg_addr                                          "0xB8032620"
#define  IFD_108_eq_filter_sel_reg                                               0xB8032620
#define  IFD_108_eq_filter_sel_inst_addr                                         "0x00B0"
#define  set_IFD_108_eq_filter_sel_reg(data)                                     (*((volatile unsigned int*)IFD_108_eq_filter_sel_reg)=data)
#define  get_IFD_108_eq_filter_sel_reg                                           (*((volatile unsigned int*)IFD_108_eq_filter_sel_reg))
#define  IFD_108_eq_filter_sel_eq_en_shift                                       (24)
#define  IFD_108_eq_filter_sel_eq_coe_modify_en_shift                            (20)
#define  IFD_108_eq_filter_sel_eq_coe_tap_shift                                  (12)
#define  IFD_108_eq_filter_sel_eq_coe_shift                                      (0)
#define  IFD_108_eq_filter_sel_eq_en_mask                                        (0x01000000)
#define  IFD_108_eq_filter_sel_eq_coe_modify_en_mask                             (0x00100000)
#define  IFD_108_eq_filter_sel_eq_coe_tap_mask                                   (0x0001F000)
#define  IFD_108_eq_filter_sel_eq_coe_mask                                       (0x000003FF)
#define  IFD_108_eq_filter_sel_eq_en(data)                                       (0x01000000&((data)<<24))
#define  IFD_108_eq_filter_sel_eq_coe_modify_en(data)                            (0x00100000&((data)<<20))
#define  IFD_108_eq_filter_sel_eq_coe_tap(data)                                  (0x0001F000&((data)<<12))
#define  IFD_108_eq_filter_sel_eq_coe(data)                                      (0x000003FF&(data))
#define  IFD_108_eq_filter_sel_get_eq_en(data)                                   ((0x01000000&(data))>>24)
#define  IFD_108_eq_filter_sel_get_eq_coe_modify_en(data)                        ((0x00100000&(data))>>20)
#define  IFD_108_eq_filter_sel_get_eq_coe_tap(data)                              ((0x0001F000&(data))>>12)
#define  IFD_108_eq_filter_sel_get_eq_coe(data)                                  (0x000003FF&(data))

#define  IFD_108_eq_filter_read                                                  0x18032624
#define  IFD_108_eq_filter_read_reg_addr                                         "0xB8032624"
#define  IFD_108_eq_filter_read_reg                                              0xB8032624
#define  IFD_108_eq_filter_read_inst_addr                                        "0x00B1"
#define  set_IFD_108_eq_filter_read_reg(data)                                    (*((volatile unsigned int*)IFD_108_eq_filter_read_reg)=data)
#define  get_IFD_108_eq_filter_read_reg                                          (*((volatile unsigned int*)IFD_108_eq_filter_read_reg))
#define  IFD_108_eq_filter_read_eq_coe_read_tap_shift                            (12)
#define  IFD_108_eq_filter_read_eq_coe_read_shift                                (0)
#define  IFD_108_eq_filter_read_eq_coe_read_tap_mask                             (0x0001F000)
#define  IFD_108_eq_filter_read_eq_coe_read_mask                                 (0x000003FF)
#define  IFD_108_eq_filter_read_eq_coe_read_tap(data)                            (0x0001F000&((data)<<12))
#define  IFD_108_eq_filter_read_eq_coe_read(data)                                (0x000003FF&(data))
#define  IFD_108_eq_filter_read_get_eq_coe_read_tap(data)                        ((0x0001F000&(data))>>12)
#define  IFD_108_eq_filter_read_get_eq_coe_read(data)                            (0x000003FF&(data))

#define  IFD_108_eq_out_rms                                                      0x18032628
#define  IFD_108_eq_out_rms_reg_addr                                             "0xB8032628"
#define  IFD_108_eq_out_rms_reg                                                  0xB8032628
#define  IFD_108_eq_out_rms_inst_addr                                            "0x00B2"
#define  set_IFD_108_eq_out_rms_reg(data)                                        (*((volatile unsigned int*)IFD_108_eq_out_rms_reg)=data)
#define  get_IFD_108_eq_out_rms_reg                                              (*((volatile unsigned int*)IFD_108_eq_out_rms_reg))
#define  IFD_108_eq_out_rms_eq_out_rms_shift                                     (0)
#define  IFD_108_eq_out_rms_eq_out_rms_mask                                      (0x003FFFFF)
#define  IFD_108_eq_out_rms_eq_out_rms(data)                                     (0x003FFFFF&(data))
#define  IFD_108_eq_out_rms_get_eq_out_rms(data)                                 (0x003FFFFF&(data))

#define  IFD_108_CRC3_Ctrl_result                                                0x18032630
#define  IFD_108_CRC3_Ctrl_result_reg_addr                                       "0xB8032630"
#define  IFD_108_CRC3_Ctrl_result_reg                                            0xB8032630
#define  IFD_108_CRC3_Ctrl_result_inst_addr                                      "0x00B3"
#define  set_IFD_108_CRC3_Ctrl_result_reg(data)                                  (*((volatile unsigned int*)IFD_108_CRC3_Ctrl_result_reg)=data)
#define  get_IFD_108_CRC3_Ctrl_result_reg                                        (*((volatile unsigned int*)IFD_108_CRC3_Ctrl_result_reg))
#define  IFD_108_CRC3_Ctrl_result_crc3_result_shift                              (4)
#define  IFD_108_CRC3_Ctrl_result_crc3_en_shift                                  (1)
#define  IFD_108_CRC3_Ctrl_result_crc3_insel_shift                               (0)
#define  IFD_108_CRC3_Ctrl_result_crc3_result_mask                               (0x000FFFF0)
#define  IFD_108_CRC3_Ctrl_result_crc3_en_mask                                   (0x00000002)
#define  IFD_108_CRC3_Ctrl_result_crc3_insel_mask                                (0x00000001)
#define  IFD_108_CRC3_Ctrl_result_crc3_result(data)                              (0x000FFFF0&((data)<<4))
#define  IFD_108_CRC3_Ctrl_result_crc3_en(data)                                  (0x00000002&((data)<<1))
#define  IFD_108_CRC3_Ctrl_result_crc3_insel(data)                               (0x00000001&(data))
#define  IFD_108_CRC3_Ctrl_result_get_crc3_result(data)                          ((0x000FFFF0&(data))>>4)
#define  IFD_108_CRC3_Ctrl_result_get_crc3_en(data)                              ((0x00000002&(data))>>1)
#define  IFD_108_CRC3_Ctrl_result_get_crc3_insel(data)                           (0x00000001&(data))

#define  IFD_108_dec_fifostatus                                                  0x18032640
#define  IFD_108_dec_fifostatus_reg_addr                                         "0xB8032640"
#define  IFD_108_dec_fifostatus_reg                                              0xB8032640
#define  IFD_108_dec_fifostatus_inst_addr                                        "0x00B4"
#define  set_IFD_108_dec_fifostatus_reg(data)                                    (*((volatile unsigned int*)IFD_108_dec_fifostatus_reg)=data)
#define  get_IFD_108_dec_fifostatus_reg                                          (*((volatile unsigned int*)IFD_108_dec_fifostatus_reg))
#define  IFD_108_dec_fifostatus_dec_fifo_full_clear_shift                        (5)
#define  IFD_108_dec_fifostatus_dec_fifo_empty_clear_shift                       (4)
#define  IFD_108_dec_fifostatus_dec_fifo_full_shift                              (1)
#define  IFD_108_dec_fifostatus_dec_fifo_empty_shift                             (0)
#define  IFD_108_dec_fifostatus_dec_fifo_full_clear_mask                         (0x00000020)
#define  IFD_108_dec_fifostatus_dec_fifo_empty_clear_mask                        (0x00000010)
#define  IFD_108_dec_fifostatus_dec_fifo_full_mask                               (0x00000002)
#define  IFD_108_dec_fifostatus_dec_fifo_empty_mask                              (0x00000001)
#define  IFD_108_dec_fifostatus_dec_fifo_full_clear(data)                        (0x00000020&((data)<<5))
#define  IFD_108_dec_fifostatus_dec_fifo_empty_clear(data)                       (0x00000010&((data)<<4))
#define  IFD_108_dec_fifostatus_dec_fifo_full(data)                              (0x00000002&((data)<<1))
#define  IFD_108_dec_fifostatus_dec_fifo_empty(data)                             (0x00000001&(data))
#define  IFD_108_dec_fifostatus_get_dec_fifo_full_clear(data)                    ((0x00000020&(data))>>5)
#define  IFD_108_dec_fifostatus_get_dec_fifo_empty_clear(data)                   ((0x00000010&(data))>>4)
#define  IFD_108_dec_fifostatus_get_dec_fifo_full(data)                          ((0x00000002&(data))>>1)
#define  IFD_108_dec_fifostatus_get_dec_fifo_empty(data)                         (0x00000001&(data))

#define  IFD_108_debug_mode4                                                     0x18032650
#define  IFD_108_debug_mode4_reg_addr                                            "0xB8032650"
#define  IFD_108_debug_mode4_reg                                                 0xB8032650
#define  IFD_108_debug_mode4_inst_addr                                           "0x00B5"
#define  set_IFD_108_debug_mode4_reg(data)                                       (*((volatile unsigned int*)IFD_108_debug_mode4_reg)=data)
#define  get_IFD_108_debug_mode4_reg                                             (*((volatile unsigned int*)IFD_108_debug_mode4_reg))
#define  IFD_108_debug_mode4_debug_mode4_en_shift                                (7)
#define  IFD_108_debug_mode4_debug_mode4_shift                                   (0)
#define  IFD_108_debug_mode4_debug_mode4_en_mask                                 (0x00000080)
#define  IFD_108_debug_mode4_debug_mode4_mask                                    (0x0000007F)
#define  IFD_108_debug_mode4_debug_mode4_en(data)                                (0x00000080&((data)<<7))
#define  IFD_108_debug_mode4_debug_mode4(data)                                   (0x0000007F&(data))
#define  IFD_108_debug_mode4_get_debug_mode4_en(data)                            ((0x00000080&(data))>>7)
#define  IFD_108_debug_mode4_get_debug_mode4(data)                               (0x0000007F&(data))

#define  IFD_108_vd_dac_test                                                     0x18032660
#define  IFD_108_vd_dac_test_reg_addr                                            "0xB8032660"
#define  IFD_108_vd_dac_test_reg                                                 0xB8032660
#define  IFD_108_vd_dac_test_inst_addr                                           "0x00B6"
#define  set_IFD_108_vd_dac_test_reg(data)                                       (*((volatile unsigned int*)IFD_108_vd_dac_test_reg)=data)
#define  get_IFD_108_vd_dac_test_reg                                             (*((volatile unsigned int*)IFD_108_vd_dac_test_reg))
#define  IFD_108_vd_dac_test_vddac_test_shift                                    (0)
#define  IFD_108_vd_dac_test_vddac_test_mask                                     (0x00000FFF)
#define  IFD_108_vd_dac_test_vddac_test(data)                                    (0x00000FFF&(data))
#define  IFD_108_vd_dac_test_get_vddac_test(data)                                (0x00000FFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======IFD_108 register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_delay:4;
        RBus_UInt32  cr_inner_lpf_sel:1;
        RBus_UInt32  cr_inner_lpf_en:1;
        RBus_UInt32  cr_bpf_en:1;
        RBus_UInt32  cr_bpf_coe_modify_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  cr_bpf_coe_tap:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  cr_bpf_coe:15;
    };
}ifd_108_cr_bpf_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  cr_bpf_coe_read_tap:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  cr_bpf_coe_read:15;
    };
}ifd_108_cr_bpf_read_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_st4_kp:4;
        RBus_UInt32  cr_st4_ki:4;
        RBus_UInt32  cr_st2_kp:4;
        RBus_UInt32  cr_st2_ki:4;
        RBus_UInt32  cr_st0_kp:4;
        RBus_UInt32  cr_st0_ki:4;
        RBus_UInt32  cr_pgain:4;
        RBus_UInt32  cr_igain:4;
    };
}ifd_108_cr_pgain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_lock_freq_thr:12;
        RBus_UInt32  res1:3;
        RBus_UInt32  cr_lock_with_freq:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  cr_lock_with_hsync:1;
        RBus_UInt32  cr_lock_with_agc:1;
        RBus_UInt32  cr_lock_ref:8;
        RBus_UInt32  res3:3;
        RBus_UInt32  cr_lock:1;
    };
}ifd_108_cr_lock_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  cr_ncoerr_en:1;
        RBus_UInt32  cr_nco_fix_data:20;
    };
}ifd_108_cr_nco_fix_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  cr_offset_sat:17;
    };
}ifd_108_cr_freq_sat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  cr_freq_status:20;
    };
}ifd_108_cr_freq_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  cr_weighting_thr:12;
        RBus_UInt32  res2:3;
        RBus_UInt32  cr_weighting_thr_en:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  cr_weighting_cr_lock_dis:1;
        RBus_UInt32  cr_weighting_en:1;
        RBus_UInt32  cr_weight_max_decrease:4;
        RBus_UInt32  cr_weight_shift:4;
    };
}ifd_108_cr_weight_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  sin_sample_d:15;
    };
}ifd_108_cr_sine_part_inner_lpf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  cr_inner_lpf_tap1:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  cr_inner_lpf_tap0:15;
    };
}ifd_108_cr_inner_lpf_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  cr_inner_lpf_tap3:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  cr_inner_lpf_tap2:15;
    };
}ifd_108_cr_inner_lpf_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1:32;
    };
}ifd_108_dummy1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy2:32;
    };
}ifd_108_dummy2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy3:32;
    };
}ifd_108_dummy3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy4:32;
    };
}ifd_108_dummy4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy5:32;
    };
}ifd_108_dummy5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  data_gain:15;
        RBus_UInt32  res2:3;
        RBus_UInt32  data_gain_mask_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  data_gain_sel:3;
        RBus_UInt32  res4:3;
        RBus_UInt32  shaping_bw_sel:1;
        RBus_UInt32  res5:3;
        RBus_UInt32  shaping_image_sel:1;
    };
}ifd_108_shape_filter_selection_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  soft_reset:1;
    };
}ifd_108_soft_reset_27_clk_phase_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dma_fifo_debug_full:1;
        RBus_UInt32  dma_fifo_debug_empty:1;
        RBus_UInt32  dma_fifo_adc_full:1;
        RBus_UInt32  dma_fifo_adc_empty:1;
        RBus_UInt32  res2:4;
    };
}ifd_108_dma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cr_lock_thd:8;
        RBus_UInt32  cr_lock_len:8;
        RBus_UInt32  cr_cnt_thd:8;
    };
}ifd_108_cr_lock_thd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_nco_offset:16;
        RBus_UInt32  res1:2;
        RBus_UInt32  cr_sin_trunc_len:2;
        RBus_UInt32  cr_track_len:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  cr_unlock_track_en:1;
        RBus_UInt32  cr_reset_track_en:1;
        RBus_UInt32  cr_nco_track_sel:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  cr_auto_reset_en:1;
    };
}ifd_108_cr_auto_reset_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  cr_phase_inverse_en_st4:1;
        RBus_UInt32  cr_phase_inverse_en_st2:1;
        RBus_UInt32  cr_phase_inverse_en_st0:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  cr_phase_inverse_thr:15;
        RBus_UInt32  res3:3;
        RBus_UInt32  cr_cordic_phase_modify_en:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  cr_phase_inverse_fine_lock_dis:1;
        RBus_UInt32  cr_phase_inverse_cr_lock_dis:1;
        RBus_UInt32  cr_phase_inverse_en:1;
    };
}ifd_108_cr_phase_inverse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  cr_auto_reset_len:5;
        RBus_UInt32  cr_track_nco:20;
    };
}ifd_108_cr_track_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cr_fm_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  cr_shift_en:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  cr_shift_polar:1;
        RBus_UInt32  cr_shift_nco_offset:20;
    };
}ifd_108_cr_shift_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  cr_less_delay:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  cr_data_gain_en:1;
    };
}ifd_108_cr_data_gain_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  cr_phase_error_sel:2;
    };
}ifd_108_cr_phase_error_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  cr_bpf_mask_en:1;
    };
}ifd_108_cr_bpf_mask_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_bpf_mask_out_thr:16;
        RBus_UInt32  cr_bpf_mask_in_thr:16;
    };
}ifd_108_cr_bpf_mask_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data_gain_mask_out_thr:16;
        RBus_UInt32  data_gain_mask_in_thr:16;
    };
}ifd_108_data_gain_mask_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  decimation_en:1;
        RBus_UInt32  res2:20;
    };
}ifd_108_decimation_filter_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lpf_vsync_start:16;
        RBus_UInt32  lpf_vsync_end:16;
    };
}ifd_108_output_lpf_vsync_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  fifo_full_clear:1;
        RBus_UInt32  fifo_empty_clear:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  fifo_full:1;
        RBus_UInt32  fifo_empty:1;
    };
}ifd_108_resampler_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  cr_phase_error_avg_src:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  cr_phase_error_avg_vcatch:1;
        RBus_UInt32  cr_phase_error_avg_interval:12;
        RBus_UInt32  res3:1;
        RBus_UInt32  cr_phase_error_avg_length:3;
        RBus_UInt32  res4:3;
        RBus_UInt32  cr_phase_error_avg_linebase:1;
    };
}ifd_108_cr_phase_error_avg_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cr_phase_error_mean:12;
        RBus_UInt32  cr_phase_error_var:12;
    };
}ifd_108_cr_phase_error_avg_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_freq_error_avg_vinterval:11;
        RBus_UInt32  cr_freq_error_avg_vcatch:1;
        RBus_UInt32  cr_freq_error_avg_interval:12;
        RBus_UInt32  res1:1;
        RBus_UInt32  cr_freq_error_avg_length:3;
        RBus_UInt32  res2:3;
        RBus_UInt32  cr_freq_error_avg_linebase:1;
    };
}ifd_108_cr_freq_error_avg_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_freq_error_mean:16;
        RBus_UInt32  cr_freq_error_var:16;
    };
}ifd_108_cr_freq_error_avg_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_vsync_start:16;
        RBus_UInt32  cr_vsync_end:16;
    };
}ifd_108_cr_vsync_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  cr_hsync_start:8;
        RBus_UInt32  cr_hsync_end:8;
    };
}ifd_108_cr_hsync_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  mod_max_out:11;
        RBus_UInt32  res2:2;
        RBus_UInt32  mod_max_slow_charge_en:1;
        RBus_UInt32  mod_max_slow_charge_value:5;
        RBus_UInt32  mod_max_cntl:12;
    };
}ifd_108_mod_detect_max_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  mod_min_out:11;
        RBus_UInt32  res2:2;
        RBus_UInt32  mod_min_slow_charge_en:1;
        RBus_UInt32  mod_min_slow_charge_value:5;
        RBus_UInt32  mod_min_cntl:12;
    };
}ifd_108_mod_detect_min_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  mod_in_sel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  mod_update_cntl:13;
        RBus_UInt32  res3:3;
        RBus_UInt32  mod_reset:1;
    };
}ifd_108_mod_detect_update_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  mod_state_thr:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  neg_mod_thr:11;
        RBus_UInt32  res3:1;
        RBus_UInt32  pos_mod_thr:11;
    };
}ifd_108_mod_detect_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  min_diff_min:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  mod_neg_cnt:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  mod_pos_cnt:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  uncertain_mod_cnt:3;
        RBus_UInt32  res5:2;
        RBus_UInt32  mod_state:2;
    };
}ifd_108_mod_detect_state_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  min_diff_max:11;
        RBus_UInt32  min_diff_value:12;
    };
}ifd_108_mod_detect_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  mod_relate_cr:1;
        RBus_UInt32  mod_relate_cr_thr:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  mod_once_auto_en:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  mod_auto_en:1;
    };
}ifd_108_mod_detect_auto_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  cr_st4_dn_debounce:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  cr_st3_dn_debounce:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  cr_st3_up_debounce:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  cr_st2_dn_debounce:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  cr_st2_up_debounce:3;
        RBus_UInt32  res6:1;
        RBus_UInt32  cr_st1_dn_debounce:3;
        RBus_UInt32  res7:1;
        RBus_UInt32  cr_st1_up_debounce:3;
        RBus_UInt32  res8:1;
        RBus_UInt32  cr_st0_up_debounce:3;
    };
}ifd_108_cr_state_debounce_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  cr_phase_var_st0_thr:12;
        RBus_UInt32  cr_freq_var_st0_thr:16;
    };
}ifd_108_cr_state_thr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  cr_phase_var_st2_thr:12;
        RBus_UInt32  cr_freq_varvcheck_thr:16;
    };
}ifd_108_cr_state_thr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_freq_var_st2_up_thr:16;
        RBus_UInt32  cr_freq_var_st2_low_thr:16;
    };
}ifd_108_cr_state_thr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_freq_var_st4_thr:16;
        RBus_UInt32  cr_freq_var_st3_thr:16;
    };
}ifd_108_cr_state_thr4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cr_state_hvunlock_out_debounce:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  cr_state_hvunlock_in_debounce:5;
        RBus_UInt32  res3:2;
        RBus_UInt32  cr_state_hvunlock_reset:1;
        RBus_UInt32  cr_st2_dn_update_sel:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  cr_fix_state:3;
        RBus_UInt32  res5:3;
        RBus_UInt32  cr_state_fix_en:1;
        RBus_UInt32  res6:3;
        RBus_UInt32  cr_state_en:1;
    };
}ifd_108_cr_state_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  cr_phase_inverse_en:1;
        RBus_UInt32  cr_weight_shift:4;
        RBus_UInt32  cr_pgain:4;
        RBus_UInt32  cr_igain:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  cr_state:3;
    };
}ifd_108_cr_state_read_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  cr_weight_shift_st4:4;
        RBus_UInt32  cr_weight_shift_st2:4;
        RBus_UInt32  cr_weight_shift_st0:4;
    };
}ifd_108_cr_state_weight_shift_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  agc_max4_sel:1;
        RBus_UInt32  agc_en:1;
        RBus_UInt32  dgain_en:1;
        RBus_UInt32  agc_bpf_en:1;
        RBus_UInt32  agc_max4_en:1;
        RBus_UInt32  agc_lpf_en:1;
        RBus_UInt32  agc_if_en:1;
        RBus_UInt32  agc_rf_en:1;
        RBus_UInt32  agc_fine_tune_en:1;
    };
}ifd_108_agc_enable_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  agc_max_count_limit_en:1;
        RBus_UInt32  agc_max_count_limit:12;
    };
}ifd_108_agc_max_limit_cnt_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_peak_slow_charge_value:3;
        RBus_UInt32  agc_max_slow_charge_value:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  agc_slow_charge_max_en:1;
        RBus_UInt32  agc_slow_charge_peak_en:1;
        RBus_UInt32  agc_max_cntl_unlock:12;
    };
}ifd_108_agc_max_countforcoarsemode_agc_cntl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  agc_max_cntl_lock:12;
    };
}ifd_108_agc_max_countforfinelockmode_agc_cntl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  agc_diff_level_inv:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_diff_targ:11;
    };
}ifd_108_agc_avg_target_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  agc_loop1_downsample_sel:12;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_pos_en:1;
    };
}ifd_108_agc_max_countforcoarsemode_agc_lock2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_data_targ:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_targ_val:11;
    };
}ifd_108_agc_targ_val_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  agc_if_sd_in_fix_value:13;
        RBus_UInt32  res2:2;
        RBus_UInt32  agc_out_inv_rf:1;
        RBus_UInt32  agc_if_sd_in_fix_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  fine_cr_ind:1;
        RBus_UInt32  agc_out_inv_if:1;
        RBus_UInt32  agc_if_manu_en:1;
        RBus_UInt32  agc_rf_manu_en:1;
        RBus_UInt32  agc_manu_en:1;
        RBus_UInt32  agc_hold:1;
        RBus_UInt32  agc_polar:1;
    };
}ifd_108_agc_cntl_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  agc_manu_value:13;
    };
}ifd_108_agc_manu_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  agc_if_manu_value:13;
    };
}ifd_108_agc_if_manu_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  agc_rf_manu_value:13;
    };
}ifd_108_agc_rf_manu_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  agc_kpd_add_method_shift:5;
        RBus_UInt32  res2:15;
        RBus_UInt32  agc_kp:5;
        RBus_UInt32  agc_ki:4;
    };
}ifd_108_ki_val_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  agc_if_max:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_if_min:13;
    };
}ifd_108_if_agc_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  agc_rf_min:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_rf_max:13;
    };
}ifd_108_rf_agc_limit_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  agc_lock_debounce_num:5;
        RBus_UInt32  agc_lock_peak_thr:12;
        RBus_UInt32  res2:2;
        RBus_UInt32  agc_lock_cnt_len_off:2;
    };
}ifd_108_agc_lock_len_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  agc_lock_en_sel:2;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_lock_exception:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  agc_lock_err_sel:1;
        RBus_UInt32  agc_lock_th_out:8;
        RBus_UInt32  agc_lock_th:8;
    };
}ifd_108_agc_lock_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  agc_fpga_pga_test_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  agc_fine_force:1;
        RBus_UInt32  agc_fine:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  agc_lock:1;
    };
}ifd_108_agc_lock_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  agc_gate_delay:8;
        RBus_UInt32  agc_hsync_start:8;
        RBus_UInt32  agc_hsync_end:8;
    };
}ifd_108_agc_hsync_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_vsync_start:16;
        RBus_UInt32  agc_vsync_end:16;
    };
}ifd_108_agc_vsync_start1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  agc_peak_force:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_peak_status:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  agc_peak_en:1;
        RBus_UInt32  agc_peak_cnt:12;
    };
}ifd_108_agc_peak_detect_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  agc_peak_value:11;
    };
}ifd_108_agc_peak_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  agc_peak_max:12;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_max:11;
    };
}ifd_108_agc_max_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  agc_peak_error:12;
        RBus_UInt32  agc_err:12;
    };
}ifd_108_agc_err0_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  agc_acc3:14;
    };
}ifd_108_agc_acc3_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  agc_if_mode:13;
    };
}ifd_108_agc_if_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  agc_rf_mode:13;
    };
}ifd_108_agc_rf_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  agc_pga_fix_en:1;
        RBus_UInt32  res2:7;
        RBus_UInt32  agc_pga_fix:9;
    };
}ifd_108_agc_pga_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  agc_rf_hasten_en:1;
        RBus_UInt32  agc_ki_rf_hasten:4;
        RBus_UInt32  agc_max_cntl_rf_hasten:12;
        RBus_UInt32  agc_rf_hasten_thr:12;
    };
}ifd_108_agc_rf_hasten_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  agc_sep_rf_if_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_if_kp:5;
        RBus_UInt32  agc_if_ki:4;
    };
}ifd_108_agc_sep_rf_if_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  agc_vtop:13;
    };
}ifd_108_vtop_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  agc_krf:14;
    };
}ifd_108_krf_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  pga_set_read:9;
    };
}ifd_108_read_pga_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  agc_loop2_hold:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_loop2_clear:1;
        RBus_UInt32  res3:16;
    };
}ifd_108_agc_linebase_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  agc_max2_cntl_unlock:12;
        RBus_UInt32  agc_max2_cntl_lock:12;
    };
}ifd_108_agc_max2_cnt_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  agc_in_kp_shift:4;
        RBus_UInt32  agc_in_ki_shift:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_in_kp:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  agc_in_ki:5;
    };
}ifd_108_agc_in_kp_ki_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_in_max:16;
        RBus_UInt32  agc_in_min:16;
    };
}ifd_108_agc_in_max_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  agc_max2_count_limit:12;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_max2_count_limit_en:1;
    };
}ifd_108_agc_max2_limit_cnt_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  loop2_err:12;
    };
}ifd_108_agc_looop2_err_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_inner1:16;
        RBus_UInt32  agc_inner2:16;
    };
}ifd_108_agc_inner_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  loop2_err_kp:16;
        RBus_UInt32  loop2_err_ki:16;
    };
}ifd_108_loop2_kp_ki_err_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_lpf_out_dgained:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_max2_out:11;
    };
}ifd_108_read_loop2_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  agc_adaptive_peak2_en:1;
        RBus_UInt32  res2:7;
        RBus_UInt32  agc_peak2_force:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  agc_peak2_status:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  agc_peak2_en:1;
        RBus_UInt32  agc_peak2_cnt:12;
    };
}ifd_108_agc_peak2_detect_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  agc_peak2_max:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  agc_peak2_error:12;
    };
}ifd_108_agc_peak2_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  agc_loop2_downsample_sel:12;
    };
}ifd_108_agc_loop2_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  agc_if_pad_control:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_rf_pad_control:1;
        RBus_UInt32  agc_sigma_delta_dnsel:4;
    };
}ifd_108_sigma_delta_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  rf_agc_interrupt_thd:13;
    };
}ifd_108_agc_interrupt_thd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  agc_2step_en:1;
    };
}ifd_108_agc_2step_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_dgain_up_step:16;
        RBus_UInt32  agc_dgain_down_step:16;
    };
}ifd_108_agc_dgain_step_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_dgain_low_thr:16;
        RBus_UInt32  agc_dgain_up_thr:16;
    };
}ifd_108_agc_dgain_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_dgain_min_pga:8;
        RBus_UInt32  agc_step_num_pga:4;
        RBus_UInt32  agc_settle_time_pga:20;
    };
}ifd_108_agc_dgain_to_pga_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  agc_max_if_gain_count:8;
        RBus_UInt32  res2:16;
    };
}ifd_108_agc_dgain_virtual_pga_hsync_gate_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  fine_tune2_down_sample_en:1;
        RBus_UInt32  fine_tune2_down_sample:12;
        RBus_UInt32  res2:3;
        RBus_UInt32  fine_tune_down_sample_en:1;
        RBus_UInt32  fine_tune_down_sample:12;
    };
}ifd_108_agc_fine_tune_down_sample_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  if_min:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  rf_full:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  if_lower:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  if_raise:1;
        RBus_UInt32  res5:3;
        RBus_UInt32  if_gain_count:9;
    };
}ifd_108_agc_2step_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  agc_gain_avg_interval:12;
        RBus_UInt32  res2:7;
        RBus_UInt32  agc_gain_avg_sel:1;
        RBus_UInt32  res3:5;
        RBus_UInt32  agc_gain_avg_length:3;
    };
}ifd_108_agc_gain_avg_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_gain_var:16;
        RBus_UInt32  agc_gain_mean:16;
    };
}ifd_108_agc_gain_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  agc_fine_adapt_interval:12;
        RBus_UInt32  agc_adapt_interval:12;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_adapt_targ_en:1;
    };
}ifd_108_agc_adapt_targ_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  agc_targ_inc_thr:11;
    };
}ifd_108_agc_adapt_targ_inc_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_min_diff_targ:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_min_targ:11;
    };
}ifd_108_agc_adapt_targ_min_val_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_fine_targ_thr:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_diff_coarse_step:11;
    };
}ifd_108_agc_adapt_targ_fine_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  adaptive_diff_targ_ro:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  adaptive_targ_val_ro:11;
    };
}ifd_108_agc_adapt_targ_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  impn_gate_end:12;
        RBus_UInt32  impn_det_thr:12;
        RBus_UInt32  res1:3;
        RBus_UInt32  impn_det_input_sel:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  agc_impn_mask_en:1;
        RBus_UInt32  impn_det_en:1;
    };
}ifd_108_impulsive_gate_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  impn_detect:1;
        RBus_UInt32  impn_det_stop:8;
        RBus_UInt32  impn_gate_delay:12;
    };
}ifd_108_impulsive_gate_setii_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  agc_sync_level_avg_length:1;
        RBus_UInt32  agc_sync_level_var:12;
        RBus_UInt32  agc_sync_level_mean:12;
    };
}ifd_108_agc_sync_level_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  agc_max_avg_length:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_max_var:11;
        RBus_UInt32  res3:1;
        RBus_UInt32  agc_max_mean:11;
    };
}ifd_108_agc_max_var_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  hum_detect:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_hum_debounce:3;
        RBus_UInt32  res3:3;
        RBus_UInt32  agc_hum_update_sel:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  agc_hum_en:1;
    };
}ifd_108_agc_hum_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_hum_max_thr_out:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_hum_max_thr_in:11;
    };
}ifd_108_agc_hum_max_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  agc_hum_sync_thr_out:12;
        RBus_UInt32  agc_hum_sync_thr_in:12;
    };
}ifd_108_agc_hum_sync_level_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  agc_pga_int_thr:8;
    };
}ifd_108_pga_int_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  agc_rf_w2s_int_thr:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_rf_s2w_int_thr:13;
    };
}ifd_108_rf_int_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  agc_if_w2s_int_thr:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_if_s2w_int_thr:13;
    };
}ifd_108_if_int_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  agc_auto_min_pga_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_slow_charge_lsadc_peak_value:3;
        RBus_UInt32  res3:3;
        RBus_UInt32  agc_slow_charge_lsadc_peak_en:1;
        RBus_UInt32  agc_lsadc_peak_cnt:12;
        RBus_UInt32  res4:2;
        RBus_UInt32  agc_peak_lsadc:6;
    };
}ifd_108_agc_peak_lsadc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_pga_min_update_step:4;
        RBus_UInt32  agc_pga_min_update_interval:12;
        RBus_UInt32  res1:2;
        RBus_UInt32  agc_pga_min_up_thr:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  agc_pga_min_low_thr:6;
    };
}ifd_108_auto_pga_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  ls_adc_out:6;
    };
}ifd_108_lsadc_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  pga_min_auto:8;
    };
}ifd_108_pga_min_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_scan_mode_offset:12;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_power_pc_sel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  input_power_cal_shift:3;
        RBus_UInt32  res3:2;
        RBus_UInt32  input_power_acc_len:2;
        RBus_UInt32  res4:1;
        RBus_UInt32  input_power_cal_len:3;
        RBus_UInt32  input_power_interrupt_mode:1;
        RBus_UInt32  input_power_cal_reset:1;
        RBus_UInt32  input_power_mod_sel:1;
        RBus_UInt32  input_power_mode:1;
    };
}ifd_108_input_power_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_nco_pc:16;
        RBus_UInt32  input_power_nco_ac:16;
    };
}ifd_108_nco_if_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_nco_02:16;
        RBus_UInt32  input_power_nco_01:16;
    };
}ifd_108_nco_sequential1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_nco_04:16;
        RBus_UInt32  input_power_nco_03:16;
    };
}ifd_108_nco_sequential2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_nco_06:16;
        RBus_UInt32  input_power_nco_05:16;
    };
}ifd_108_nco_sequential3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_nco_08:16;
        RBus_UInt32  input_power_nco_07:16;
    };
}ifd_108_nco_sequential4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_range2:16;
        RBus_UInt32  input_power_range1:16;
    };
}ifd_108_nco_scan_range1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_range4:16;
        RBus_UInt32  input_power_range3:16;
    };
}ifd_108_nco_scan_range4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_ac:16;
        RBus_UInt32  input_power_pc:16;
    };
}ifd_108_input_power_output_if_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_offset_00:16;
        RBus_UInt32  input_power_00:16;
    };
}ifd_108_input_power_output_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_offset_01:16;
        RBus_UInt32  input_power_01:16;
    };
}ifd_108_input_power_output_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_offset_02:16;
        RBus_UInt32  input_power_02:16;
    };
}ifd_108_input_power_output_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_offset_03:16;
        RBus_UInt32  input_power_03:16;
    };
}ifd_108_input_power_output_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_offset_04:16;
        RBus_UInt32  input_power_04:16;
    };
}ifd_108_input_power_output_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_offset_05:16;
        RBus_UInt32  input_power_05:16;
    };
}ifd_108_input_power_output_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_diff_thr:12;
        RBus_UInt32  res1:1;
        RBus_UInt32  input_power_diff:15;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_power_detect_done:1;
    };
}ifd_108_input_power_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_offset_min:16;
        RBus_UInt32  input_power_min:16;
    };
}ifd_108_input_power_output_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  input_power_min_diff:16;
    };
}ifd_108_input_power_min_diff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  cr_lock_power_diff_en:1;
        RBus_UInt32  cr_lock_power_diff_thr:16;
    };
}ifd_108_input_power_cr_lock_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  mbist_ifd_dvse:1;
        RBus_UInt32  mbist_ifd_dvs:4;
    };
}ifd_108_ifd_bist_dvs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  bist_mode_ifd:1;
    };
}ifd_108_ifd_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  drf_bist_mode_ifd:1;
    };
}ifd_108_ifd_drf_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  drf_test_resume_ifd:1;
    };
}ifd_108_ifd_drf_test_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  mbist_ls_cntl:1;
    };
}ifd_108_ifd_ls_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  bist_done_ifd:1;
    };
}ifd_108_ifd_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  drf_bist_done_ifd:1;
    };
}ifd_108_ifd_drf_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  bist_fail_ifd:1;
    };
}ifd_108_ifd_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  drf_bist_fail_ifd:1;
    };
}ifd_108_ifd_drf_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  drf_start_pause_ifd:1;
    };
}ifd_108_ifd_drf_bist_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  debug_clk27_polar:1;
        RBus_UInt32  debug_clk49_polar:1;
        RBus_UInt32  debug_clk54_polar:1;
        RBus_UInt32  debug_clk108_polar:1;
        RBus_UInt32  debug_adcclk_polar:1;
        RBus_UInt32  debug_mode_en:1;
        RBus_UInt32  debug_mode:7;
    };
}ifd_108_debug_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  debug_mode3_en:1;
        RBus_UInt32  debug_mode3:7;
        RBus_UInt32  res2:8;
    };
}ifd_108_debug_mode3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  test_mode_en:1;
        RBus_UInt32  test_mode:7;
    };
}ifd_108_test_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cr_self_test_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_self_test_en:1;
        RBus_UInt32  agc_self_test_sel:1;
        RBus_UInt32  res3:2;
    };
}ifd_108_cr_self_test_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  crc1_insel:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  crc2_en:1;
        RBus_UInt32  crc2_insel:1;
        RBus_UInt32  res3:2;
    };
}ifd_108_crc_ctrl_register_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc2_result:32;
    };
}ifd_108_crc2_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  dactest_sel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  sinout_sel:1;
        RBus_UInt32  dac_dctest:12;
    };
}ifd_108_dactest_register1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  bypassad:1;
    };
}ifd_108_adbypassenable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fpga_test1:32;
    };
}ifd_108_fpga_test1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fpga_test2:32;
    };
}ifd_108_fpga_test2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fpga_test3:32;
    };
}ifd_108_fpga_test3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fpga_test4:27;
        RBus_UInt32  debug_clk5:1;
        RBus_UInt32  debug_clk4:1;
        RBus_UInt32  debug_clk3:1;
        RBus_UInt32  debug_clk2:1;
        RBus_UInt32  debug_clk1:1;
    };
}ifd_108_fpga_test4_debug_clk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  input_power_lower_int:1;
        RBus_UInt32  input_power_over_int:1;
        RBus_UInt32  if_w2s_int:1;
        RBus_UInt32  if_s2w_int:1;
        RBus_UInt32  rf_w2s_int:1;
        RBus_UInt32  rf_s2w_int:1;
        RBus_UInt32  pga_w2s_int:1;
        RBus_UInt32  pga_s2w_int:1;
        RBus_UInt32  agc_unlock_int:1;
        RBus_UInt32  mod_state_int:1;
        RBus_UInt32  cr_unlock_int:1;
        RBus_UInt32  input_fifo_int:1;
        RBus_UInt32  rf_agc_max_int:1;
        RBus_UInt32  agc_lock_int:1;
        RBus_UInt32  cr_lock_int:1;
    };
}ifd_108_interrupt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  ifd_int_mask:1;
        RBus_UInt32  mask_input_power_lower_en:1;
        RBus_UInt32  mask_input_power_over_en:1;
        RBus_UInt32  mask_if_w2s_en:1;
        RBus_UInt32  mask_if_s2w_en:1;
        RBus_UInt32  mask_rf_w2s_en:1;
        RBus_UInt32  mask_rf_s2w_en:1;
        RBus_UInt32  mask_pga_w2s_en:1;
        RBus_UInt32  mask_pga_s2w_en:1;
        RBus_UInt32  mask_agc_unlock_en:1;
        RBus_UInt32  mask_mod_state_en:1;
        RBus_UInt32  mask_cr_unlock_en:1;
        RBus_UInt32  mask_input_fifo_status_en:1;
        RBus_UInt32  mask_rf_agc_max_en:1;
        RBus_UInt32  mask_agc_lock_en:1;
        RBus_UInt32  mask_cr_lock_en:1;
    };
}ifd_108_interrupt_mask_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  output_lpf_1m:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  video_bw_sel:1;
        RBus_UInt32  video_upsample_lp_sel:4;
    };
}ifd_108_video_bw_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  grp_delay_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  grp_delay_coe_en:1;
        RBus_UInt32  grp_delay_select_tap:8;
        RBus_UInt32  res3:1;
        RBus_UInt32  grp_delay_coe_modofy:11;
    };
}ifd_108_grp_delay_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  grp_delay_select_tap_read:8;
        RBus_UInt32  res2:1;
        RBus_UInt32  grp_delay_coe_modofy_read:11;
    };
}ifd_108_grp_delay_read_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  output_lpf_vsync_coe_change:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  output_lpf_coe_modify_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  output_lpf_coe_tap:7;
        RBus_UInt32  res4:2;
        RBus_UInt32  output_lpf_coe:14;
    };
}ifd_108_output_lpf_modify_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  output_lpf_coe_read_tap:7;
        RBus_UInt32  res2:2;
        RBus_UInt32  output_lpf_coe_read:14;
    };
}ifd_108_output_lpf_read_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  dnlpf_en:1;
        RBus_UInt32  res2:24;
    };
}ifd_108_dnlpf_tap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  eq_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  eq_coe_modify_en:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  eq_coe_tap:5;
        RBus_UInt32  res4:2;
        RBus_UInt32  eq_coe:10;
    };
}ifd_108_eq_filter_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  eq_coe_read_tap:5;
        RBus_UInt32  res2:2;
        RBus_UInt32  eq_coe_read:10;
    };
}ifd_108_eq_filter_read_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  eq_out_rms:22;
    };
}ifd_108_eq_out_rms_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  crc3_result:16;
        RBus_UInt32  res2:2;
        RBus_UInt32  crc3_en:1;
        RBus_UInt32  crc3_insel:1;
    };
}ifd_108_crc3_ctrl_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  dec_fifo_full_clear:1;
        RBus_UInt32  dec_fifo_empty_clear:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  dec_fifo_full:1;
        RBus_UInt32  dec_fifo_empty:1;
    };
}ifd_108_dec_fifostatus_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  debug_mode4_en:1;
        RBus_UInt32  debug_mode4:7;
    };
}ifd_108_debug_mode4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  vddac_test:12;
    };
}ifd_108_vd_dac_test_RBUS;

#else //apply LITTLE_ENDIAN

//======IFD_108 register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_bpf_coe:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  cr_bpf_coe_tap:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  cr_bpf_coe_modify_en:1;
        RBus_UInt32  cr_bpf_en:1;
        RBus_UInt32  cr_inner_lpf_en:1;
        RBus_UInt32  cr_inner_lpf_sel:1;
        RBus_UInt32  cr_delay:4;
    };
}ifd_108_cr_bpf_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_bpf_coe_read:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  cr_bpf_coe_read_tap:7;
        RBus_UInt32  res2:9;
    };
}ifd_108_cr_bpf_read_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_igain:4;
        RBus_UInt32  cr_pgain:4;
        RBus_UInt32  cr_st0_ki:4;
        RBus_UInt32  cr_st0_kp:4;
        RBus_UInt32  cr_st2_ki:4;
        RBus_UInt32  cr_st2_kp:4;
        RBus_UInt32  cr_st4_ki:4;
        RBus_UInt32  cr_st4_kp:4;
    };
}ifd_108_cr_pgain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_lock:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  cr_lock_ref:8;
        RBus_UInt32  cr_lock_with_agc:1;
        RBus_UInt32  cr_lock_with_hsync:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  cr_lock_with_freq:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  cr_lock_freq_thr:12;
    };
}ifd_108_cr_lock_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_nco_fix_data:20;
        RBus_UInt32  cr_ncoerr_en:1;
        RBus_UInt32  res1:11;
    };
}ifd_108_cr_nco_fix_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_offset_sat:17;
        RBus_UInt32  res1:15;
    };
}ifd_108_cr_freq_sat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_freq_status:20;
        RBus_UInt32  res1:12;
    };
}ifd_108_cr_freq_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_weight_shift:4;
        RBus_UInt32  cr_weight_max_decrease:4;
        RBus_UInt32  cr_weighting_en:1;
        RBus_UInt32  cr_weighting_cr_lock_dis:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  cr_weighting_thr_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  cr_weighting_thr:12;
        RBus_UInt32  res3:4;
    };
}ifd_108_cr_weight_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sin_sample_d:15;
        RBus_UInt32  res1:17;
    };
}ifd_108_cr_sine_part_inner_lpf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_inner_lpf_tap0:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  cr_inner_lpf_tap1:15;
        RBus_UInt32  res2:1;
    };
}ifd_108_cr_inner_lpf_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_inner_lpf_tap2:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  cr_inner_lpf_tap3:15;
        RBus_UInt32  res2:1;
    };
}ifd_108_cr_inner_lpf_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1:32;
    };
}ifd_108_dummy1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy2:32;
    };
}ifd_108_dummy2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy3:32;
    };
}ifd_108_dummy3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy4:32;
    };
}ifd_108_dummy4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy5:32;
    };
}ifd_108_dummy5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  shaping_image_sel:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  shaping_bw_sel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  data_gain_sel:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  data_gain_mask_en:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  data_gain:15;
        RBus_UInt32  res5:1;
    };
}ifd_108_shape_filter_selection_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  soft_reset:1;
        RBus_UInt32  res1:31;
    };
}ifd_108_soft_reset_27_clk_phase_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dma_fifo_adc_empty:1;
        RBus_UInt32  dma_fifo_adc_full:1;
        RBus_UInt32  dma_fifo_debug_empty:1;
        RBus_UInt32  dma_fifo_debug_full:1;
        RBus_UInt32  res2:24;
    };
}ifd_108_dma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_cnt_thd:8;
        RBus_UInt32  cr_lock_len:8;
        RBus_UInt32  cr_lock_thd:8;
        RBus_UInt32  res1:8;
    };
}ifd_108_cr_lock_thd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_auto_reset_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  cr_nco_track_sel:1;
        RBus_UInt32  cr_reset_track_en:1;
        RBus_UInt32  cr_unlock_track_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  cr_track_len:4;
        RBus_UInt32  cr_sin_trunc_len:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  cr_nco_offset:16;
    };
}ifd_108_cr_auto_reset_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_phase_inverse_en:1;
        RBus_UInt32  cr_phase_inverse_cr_lock_dis:1;
        RBus_UInt32  cr_phase_inverse_fine_lock_dis:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  cr_cordic_phase_modify_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  cr_phase_inverse_thr:15;
        RBus_UInt32  res3:1;
        RBus_UInt32  cr_phase_inverse_en_st0:1;
        RBus_UInt32  cr_phase_inverse_en_st2:1;
        RBus_UInt32  cr_phase_inverse_en_st4:1;
        RBus_UInt32  res4:5;
    };
}ifd_108_cr_phase_inverse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_track_nco:20;
        RBus_UInt32  cr_auto_reset_len:5;
        RBus_UInt32  res1:7;
    };
}ifd_108_cr_track_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_shift_nco_offset:20;
        RBus_UInt32  cr_shift_polar:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  cr_shift_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  cr_fm_en:1;
        RBus_UInt32  res3:3;
    };
}ifd_108_cr_shift_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_data_gain_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  cr_less_delay:1;
        RBus_UInt32  res2:27;
    };
}ifd_108_cr_data_gain_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_phase_error_sel:2;
        RBus_UInt32  res1:30;
    };
}ifd_108_cr_phase_error_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_bpf_mask_en:1;
        RBus_UInt32  res1:31;
    };
}ifd_108_cr_bpf_mask_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_bpf_mask_in_thr:16;
        RBus_UInt32  cr_bpf_mask_out_thr:16;
    };
}ifd_108_cr_bpf_mask_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data_gain_mask_in_thr:16;
        RBus_UInt32  data_gain_mask_out_thr:16;
    };
}ifd_108_data_gain_mask_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  decimation_en:1;
        RBus_UInt32  res2:11;
    };
}ifd_108_decimation_filter_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lpf_vsync_end:16;
        RBus_UInt32  lpf_vsync_start:16;
    };
}ifd_108_output_lpf_vsync_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fifo_empty:1;
        RBus_UInt32  fifo_full:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  fifo_empty_clear:1;
        RBus_UInt32  fifo_full_clear:1;
        RBus_UInt32  res2:26;
    };
}ifd_108_resampler_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_phase_error_avg_linebase:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  cr_phase_error_avg_length:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  cr_phase_error_avg_interval:12;
        RBus_UInt32  cr_phase_error_avg_vcatch:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  cr_phase_error_avg_src:1;
        RBus_UInt32  res4:7;
    };
}ifd_108_cr_phase_error_avg_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_phase_error_var:12;
        RBus_UInt32  cr_phase_error_mean:12;
        RBus_UInt32  res1:8;
    };
}ifd_108_cr_phase_error_avg_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_freq_error_avg_linebase:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  cr_freq_error_avg_length:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  cr_freq_error_avg_interval:12;
        RBus_UInt32  cr_freq_error_avg_vcatch:1;
        RBus_UInt32  cr_freq_error_avg_vinterval:11;
    };
}ifd_108_cr_freq_error_avg_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_freq_error_var:16;
        RBus_UInt32  cr_freq_error_mean:16;
    };
}ifd_108_cr_freq_error_avg_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_vsync_end:16;
        RBus_UInt32  cr_vsync_start:16;
    };
}ifd_108_cr_vsync_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_hsync_end:8;
        RBus_UInt32  cr_hsync_start:8;
        RBus_UInt32  res1:16;
    };
}ifd_108_cr_hsync_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mod_max_cntl:12;
        RBus_UInt32  mod_max_slow_charge_value:5;
        RBus_UInt32  mod_max_slow_charge_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  mod_max_out:11;
        RBus_UInt32  res2:1;
    };
}ifd_108_mod_detect_max_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mod_min_cntl:12;
        RBus_UInt32  mod_min_slow_charge_value:5;
        RBus_UInt32  mod_min_slow_charge_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  mod_min_out:11;
        RBus_UInt32  res2:1;
    };
}ifd_108_mod_detect_min_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mod_reset:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  mod_update_cntl:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  mod_in_sel:1;
        RBus_UInt32  res3:11;
    };
}ifd_108_mod_detect_update_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pos_mod_thr:11;
        RBus_UInt32  res1:1;
        RBus_UInt32  neg_mod_thr:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  mod_state_thr:3;
        RBus_UInt32  res3:5;
    };
}ifd_108_mod_detect_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mod_state:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  uncertain_mod_cnt:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  mod_pos_cnt:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  mod_neg_cnt:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  min_diff_min:11;
        RBus_UInt32  res5:5;
    };
}ifd_108_mod_detect_state_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  min_diff_value:12;
        RBus_UInt32  min_diff_max:11;
        RBus_UInt32  res1:9;
    };
}ifd_108_mod_detect_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mod_auto_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  mod_once_auto_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  mod_relate_cr_thr:4;
        RBus_UInt32  mod_relate_cr:1;
        RBus_UInt32  res3:19;
    };
}ifd_108_mod_detect_auto_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_st0_up_debounce:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  cr_st1_up_debounce:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  cr_st1_dn_debounce:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  cr_st2_up_debounce:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  cr_st2_dn_debounce:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  cr_st3_up_debounce:3;
        RBus_UInt32  res6:1;
        RBus_UInt32  cr_st3_dn_debounce:3;
        RBus_UInt32  res7:1;
        RBus_UInt32  cr_st4_dn_debounce:3;
        RBus_UInt32  res8:1;
    };
}ifd_108_cr_state_debounce_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_freq_var_st0_thr:16;
        RBus_UInt32  cr_phase_var_st0_thr:12;
        RBus_UInt32  res1:4;
    };
}ifd_108_cr_state_thr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_freq_varvcheck_thr:16;
        RBus_UInt32  cr_phase_var_st2_thr:12;
        RBus_UInt32  res1:4;
    };
}ifd_108_cr_state_thr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_freq_var_st2_low_thr:16;
        RBus_UInt32  cr_freq_var_st2_up_thr:16;
    };
}ifd_108_cr_state_thr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_freq_var_st3_thr:16;
        RBus_UInt32  cr_freq_var_st4_thr:16;
    };
}ifd_108_cr_state_thr4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_state_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  cr_state_fix_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  cr_fix_state:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  cr_st2_dn_update_sel:1;
        RBus_UInt32  cr_state_hvunlock_reset:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  cr_state_hvunlock_in_debounce:5;
        RBus_UInt32  res5:3;
        RBus_UInt32  cr_state_hvunlock_out_debounce:5;
        RBus_UInt32  res6:3;
    };
}ifd_108_cr_state_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_state:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  cr_igain:4;
        RBus_UInt32  cr_pgain:4;
        RBus_UInt32  cr_weight_shift:4;
        RBus_UInt32  cr_phase_inverse_en:1;
        RBus_UInt32  res2:15;
    };
}ifd_108_cr_state_read_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_weight_shift_st0:4;
        RBus_UInt32  cr_weight_shift_st2:4;
        RBus_UInt32  cr_weight_shift_st4:4;
        RBus_UInt32  res1:20;
    };
}ifd_108_cr_state_weight_shift_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_fine_tune_en:1;
        RBus_UInt32  agc_rf_en:1;
        RBus_UInt32  agc_if_en:1;
        RBus_UInt32  agc_lpf_en:1;
        RBus_UInt32  agc_max4_en:1;
        RBus_UInt32  agc_bpf_en:1;
        RBus_UInt32  dgain_en:1;
        RBus_UInt32  agc_en:1;
        RBus_UInt32  agc_max4_sel:1;
        RBus_UInt32  res1:23;
    };
}ifd_108_agc_enable_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_max_count_limit:12;
        RBus_UInt32  agc_max_count_limit_en:1;
        RBus_UInt32  res1:19;
    };
}ifd_108_agc_max_limit_cnt_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_max_cntl_unlock:12;
        RBus_UInt32  agc_slow_charge_peak_en:1;
        RBus_UInt32  agc_slow_charge_max_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  agc_max_slow_charge_value:4;
        RBus_UInt32  agc_peak_slow_charge_value:3;
        RBus_UInt32  res2:9;
    };
}ifd_108_agc_max_countforcoarsemode_agc_cntl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_max_cntl_lock:12;
        RBus_UInt32  res1:20;
    };
}ifd_108_agc_max_countforfinelockmode_agc_cntl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_diff_targ:11;
        RBus_UInt32  res1:1;
        RBus_UInt32  agc_diff_level_inv:1;
        RBus_UInt32  res2:19;
    };
}ifd_108_agc_avg_target_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_pos_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  agc_loop1_downsample_sel:12;
        RBus_UInt32  res2:16;
    };
}ifd_108_agc_max_countforcoarsemode_agc_lock2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_targ_val:11;
        RBus_UInt32  res1:1;
        RBus_UInt32  agc_data_targ:11;
        RBus_UInt32  res2:9;
    };
}ifd_108_agc_targ_val_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_polar:1;
        RBus_UInt32  agc_hold:1;
        RBus_UInt32  agc_manu_en:1;
        RBus_UInt32  agc_rf_manu_en:1;
        RBus_UInt32  agc_if_manu_en:1;
        RBus_UInt32  agc_out_inv_if:1;
        RBus_UInt32  fine_cr_ind:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  agc_if_sd_in_fix_en:1;
        RBus_UInt32  agc_out_inv_rf:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  agc_if_sd_in_fix_value:13;
        RBus_UInt32  res3:7;
    };
}ifd_108_agc_cntl_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_manu_value:13;
        RBus_UInt32  res1:19;
    };
}ifd_108_agc_manu_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_if_manu_value:13;
        RBus_UInt32  res1:19;
    };
}ifd_108_agc_if_manu_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_manu_value:13;
        RBus_UInt32  res1:19;
    };
}ifd_108_agc_rf_manu_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_ki:4;
        RBus_UInt32  agc_kp:5;
        RBus_UInt32  res1:15;
        RBus_UInt32  agc_kpd_add_method_shift:5;
        RBus_UInt32  res2:3;
    };
}ifd_108_ki_val_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_if_min:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  agc_if_max:13;
        RBus_UInt32  res2:3;
    };
}ifd_108_if_agc_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_max:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  agc_rf_min:13;
        RBus_UInt32  res2:3;
    };
}ifd_108_rf_agc_limit_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_lock_cnt_len_off:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  agc_lock_peak_thr:12;
        RBus_UInt32  agc_lock_debounce_num:5;
        RBus_UInt32  res2:11;
    };
}ifd_108_agc_lock_len_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_lock_th:8;
        RBus_UInt32  agc_lock_th_out:8;
        RBus_UInt32  agc_lock_err_sel:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  agc_lock_exception:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_lock_en_sel:2;
        RBus_UInt32  res3:6;
    };
}ifd_108_agc_lock_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_lock:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  agc_fine:1;
        RBus_UInt32  agc_fine_force:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  agc_fpga_pga_test_en:1;
        RBus_UInt32  res3:23;
    };
}ifd_108_agc_lock_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_hsync_end:8;
        RBus_UInt32  agc_hsync_start:8;
        RBus_UInt32  agc_gate_delay:8;
        RBus_UInt32  res1:8;
    };
}ifd_108_agc_hsync_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_vsync_end:16;
        RBus_UInt32  agc_vsync_start:16;
    };
}ifd_108_agc_vsync_start1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_peak_cnt:12;
        RBus_UInt32  agc_peak_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  agc_peak_status:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_peak_force:1;
        RBus_UInt32  res3:11;
    };
}ifd_108_agc_peak_detect_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_peak_value:11;
        RBus_UInt32  res1:21;
    };
}ifd_108_agc_peak_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_max:11;
        RBus_UInt32  res1:1;
        RBus_UInt32  agc_peak_max:12;
        RBus_UInt32  res2:8;
    };
}ifd_108_agc_max_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_err:12;
        RBus_UInt32  agc_peak_error:12;
        RBus_UInt32  res1:8;
    };
}ifd_108_agc_err0_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_acc3:14;
        RBus_UInt32  res1:18;
    };
}ifd_108_agc_acc3_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_if_mode:13;
        RBus_UInt32  res1:19;
    };
}ifd_108_agc_if_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_mode:13;
        RBus_UInt32  res1:19;
    };
}ifd_108_agc_rf_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_pga_fix:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  agc_pga_fix_en:1;
        RBus_UInt32  res2:15;
    };
}ifd_108_agc_pga_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_hasten_thr:12;
        RBus_UInt32  agc_max_cntl_rf_hasten:12;
        RBus_UInt32  agc_ki_rf_hasten:4;
        RBus_UInt32  agc_rf_hasten_en:1;
        RBus_UInt32  res1:3;
    };
}ifd_108_agc_rf_hasten_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_if_ki:4;
        RBus_UInt32  agc_if_kp:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  agc_sep_rf_if_en:1;
        RBus_UInt32  res2:19;
    };
}ifd_108_agc_sep_rf_if_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_vtop:13;
        RBus_UInt32  res1:19;
    };
}ifd_108_vtop_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_krf:14;
        RBus_UInt32  res1:18;
    };
}ifd_108_krf_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pga_set_read:9;
        RBus_UInt32  res1:23;
    };
}ifd_108_read_pga_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  agc_loop2_clear:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_loop2_hold:1;
        RBus_UInt32  res3:11;
    };
}ifd_108_agc_linebase_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_max2_cntl_lock:12;
        RBus_UInt32  agc_max2_cntl_unlock:12;
        RBus_UInt32  res1:8;
    };
}ifd_108_agc_max2_cnt_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_in_ki:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  agc_in_kp:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_in_ki_shift:4;
        RBus_UInt32  agc_in_kp_shift:4;
        RBus_UInt32  res3:8;
    };
}ifd_108_agc_in_kp_ki_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_in_min:16;
        RBus_UInt32  agc_in_max:16;
    };
}ifd_108_agc_in_max_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_max2_count_limit_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  agc_max2_count_limit:12;
        RBus_UInt32  res2:16;
    };
}ifd_108_agc_max2_limit_cnt_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  loop2_err:12;
        RBus_UInt32  res1:20;
    };
}ifd_108_agc_looop2_err_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_inner2:16;
        RBus_UInt32  agc_inner1:16;
    };
}ifd_108_agc_inner_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  loop2_err_ki:16;
        RBus_UInt32  loop2_err_kp:16;
    };
}ifd_108_loop2_kp_ki_err_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_max2_out:11;
        RBus_UInt32  res1:1;
        RBus_UInt32  agc_lpf_out_dgained:11;
        RBus_UInt32  res2:9;
    };
}ifd_108_read_loop2_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_peak2_cnt:12;
        RBus_UInt32  agc_peak2_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  agc_peak2_status:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_peak2_force:1;
        RBus_UInt32  res3:7;
        RBus_UInt32  agc_adaptive_peak2_en:1;
        RBus_UInt32  res4:3;
    };
}ifd_108_agc_peak2_detect_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_peak2_error:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  agc_peak2_max:12;
        RBus_UInt32  res2:4;
    };
}ifd_108_agc_peak2_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_loop2_downsample_sel:12;
        RBus_UInt32  res1:20;
    };
}ifd_108_agc_loop2_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_sigma_delta_dnsel:4;
        RBus_UInt32  agc_rf_pad_control:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  agc_if_pad_control:1;
        RBus_UInt32  res2:23;
    };
}ifd_108_sigma_delta_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rf_agc_interrupt_thd:13;
        RBus_UInt32  res1:19;
    };
}ifd_108_agc_interrupt_thd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_2step_en:1;
        RBus_UInt32  res1:31;
    };
}ifd_108_agc_2step_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_dgain_down_step:16;
        RBus_UInt32  agc_dgain_up_step:16;
    };
}ifd_108_agc_dgain_step_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_dgain_up_thr:16;
        RBus_UInt32  agc_dgain_low_thr:16;
    };
}ifd_108_agc_dgain_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_settle_time_pga:20;
        RBus_UInt32  agc_step_num_pga:4;
        RBus_UInt32  agc_dgain_min_pga:8;
    };
}ifd_108_agc_dgain_to_pga_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  agc_max_if_gain_count:8;
        RBus_UInt32  res2:8;
    };
}ifd_108_agc_dgain_virtual_pga_hsync_gate_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fine_tune_down_sample:12;
        RBus_UInt32  fine_tune_down_sample_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  fine_tune2_down_sample:12;
        RBus_UInt32  fine_tune2_down_sample_en:1;
        RBus_UInt32  res2:3;
    };
}ifd_108_agc_fine_tune_down_sample_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  if_gain_count:9;
        RBus_UInt32  res1:3;
        RBus_UInt32  if_raise:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  if_lower:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  rf_full:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  if_min:1;
        RBus_UInt32  res5:7;
    };
}ifd_108_agc_2step_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_gain_avg_length:3;
        RBus_UInt32  res1:5;
        RBus_UInt32  agc_gain_avg_sel:1;
        RBus_UInt32  res2:7;
        RBus_UInt32  agc_gain_avg_interval:12;
        RBus_UInt32  res3:4;
    };
}ifd_108_agc_gain_avg_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_gain_mean:16;
        RBus_UInt32  agc_gain_var:16;
    };
}ifd_108_agc_gain_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_adapt_targ_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  agc_adapt_interval:12;
        RBus_UInt32  agc_fine_adapt_interval:12;
        RBus_UInt32  res2:4;
    };
}ifd_108_agc_adapt_targ_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_targ_inc_thr:11;
        RBus_UInt32  res1:21;
    };
}ifd_108_agc_adapt_targ_inc_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_min_targ:11;
        RBus_UInt32  res1:1;
        RBus_UInt32  agc_min_diff_targ:11;
        RBus_UInt32  res2:9;
    };
}ifd_108_agc_adapt_targ_min_val_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_diff_coarse_step:11;
        RBus_UInt32  res1:1;
        RBus_UInt32  agc_fine_targ_thr:11;
        RBus_UInt32  res2:9;
    };
}ifd_108_agc_adapt_targ_fine_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adaptive_targ_val_ro:11;
        RBus_UInt32  res1:1;
        RBus_UInt32  adaptive_diff_targ_ro:11;
        RBus_UInt32  res2:9;
    };
}ifd_108_agc_adapt_targ_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  impn_det_en:1;
        RBus_UInt32  agc_impn_mask_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  impn_det_input_sel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  impn_det_thr:12;
        RBus_UInt32  impn_gate_end:12;
    };
}ifd_108_impulsive_gate_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  impn_gate_delay:12;
        RBus_UInt32  impn_det_stop:8;
        RBus_UInt32  impn_detect:1;
        RBus_UInt32  res1:11;
    };
}ifd_108_impulsive_gate_setii_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_sync_level_mean:12;
        RBus_UInt32  agc_sync_level_var:12;
        RBus_UInt32  agc_sync_level_avg_length:1;
        RBus_UInt32  res1:7;
    };
}ifd_108_agc_sync_level_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_max_mean:11;
        RBus_UInt32  res1:1;
        RBus_UInt32  agc_max_var:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_max_avg_length:1;
        RBus_UInt32  res3:7;
    };
}ifd_108_agc_max_var_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_hum_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  agc_hum_update_sel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_hum_debounce:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  hum_detect:1;
        RBus_UInt32  res4:19;
    };
}ifd_108_agc_hum_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_hum_max_thr_in:11;
        RBus_UInt32  res1:1;
        RBus_UInt32  agc_hum_max_thr_out:11;
        RBus_UInt32  res2:9;
    };
}ifd_108_agc_hum_max_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_hum_sync_thr_in:12;
        RBus_UInt32  agc_hum_sync_thr_out:12;
        RBus_UInt32  res1:8;
    };
}ifd_108_agc_hum_sync_level_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_pga_int_thr:8;
        RBus_UInt32  res1:24;
    };
}ifd_108_pga_int_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_s2w_int_thr:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  agc_rf_w2s_int_thr:13;
        RBus_UInt32  res2:3;
    };
}ifd_108_rf_int_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_if_s2w_int_thr:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  agc_if_w2s_int_thr:13;
        RBus_UInt32  res2:3;
    };
}ifd_108_if_int_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_peak_lsadc:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  agc_lsadc_peak_cnt:12;
        RBus_UInt32  agc_slow_charge_lsadc_peak_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_slow_charge_lsadc_peak_value:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  agc_auto_min_pga_en:1;
        RBus_UInt32  res4:3;
    };
}ifd_108_agc_peak_lsadc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_pga_min_low_thr:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  agc_pga_min_up_thr:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  agc_pga_min_update_interval:12;
        RBus_UInt32  agc_pga_min_update_step:4;
    };
}ifd_108_auto_pga_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ls_adc_out:6;
        RBus_UInt32  res1:26;
    };
}ifd_108_lsadc_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pga_min_auto:8;
        RBus_UInt32  res1:24;
    };
}ifd_108_pga_min_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_mode:1;
        RBus_UInt32  input_power_mod_sel:1;
        RBus_UInt32  input_power_cal_reset:1;
        RBus_UInt32  input_power_interrupt_mode:1;
        RBus_UInt32  input_power_cal_len:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  input_power_acc_len:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  input_power_cal_shift:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  input_power_pc_sel:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  input_power_scan_mode_offset:12;
    };
}ifd_108_input_power_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_nco_ac:16;
        RBus_UInt32  input_power_nco_pc:16;
    };
}ifd_108_nco_if_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_nco_01:16;
        RBus_UInt32  input_power_nco_02:16;
    };
}ifd_108_nco_sequential1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_nco_03:16;
        RBus_UInt32  input_power_nco_04:16;
    };
}ifd_108_nco_sequential2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_nco_05:16;
        RBus_UInt32  input_power_nco_06:16;
    };
}ifd_108_nco_sequential3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_nco_07:16;
        RBus_UInt32  input_power_nco_08:16;
    };
}ifd_108_nco_sequential4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_range1:16;
        RBus_UInt32  input_power_range2:16;
    };
}ifd_108_nco_scan_range1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_range3:16;
        RBus_UInt32  input_power_range4:16;
    };
}ifd_108_nco_scan_range4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_pc:16;
        RBus_UInt32  input_power_ac:16;
    };
}ifd_108_input_power_output_if_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_00:16;
        RBus_UInt32  input_power_offset_00:16;
    };
}ifd_108_input_power_output_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_01:16;
        RBus_UInt32  input_power_offset_01:16;
    };
}ifd_108_input_power_output_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_02:16;
        RBus_UInt32  input_power_offset_02:16;
    };
}ifd_108_input_power_output_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_03:16;
        RBus_UInt32  input_power_offset_03:16;
    };
}ifd_108_input_power_output_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_04:16;
        RBus_UInt32  input_power_offset_04:16;
    };
}ifd_108_input_power_output_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_05:16;
        RBus_UInt32  input_power_offset_05:16;
    };
}ifd_108_input_power_output_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_detect_done:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_power_diff:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  input_power_diff_thr:12;
    };
}ifd_108_input_power_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_min:16;
        RBus_UInt32  input_power_offset_min:16;
    };
}ifd_108_input_power_output_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_min_diff:16;
        RBus_UInt32  res1:16;
    };
}ifd_108_input_power_min_diff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_lock_power_diff_thr:16;
        RBus_UInt32  cr_lock_power_diff_en:1;
        RBus_UInt32  res1:15;
    };
}ifd_108_input_power_cr_lock_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_ifd_dvs:4;
        RBus_UInt32  mbist_ifd_dvse:1;
        RBus_UInt32  res1:27;
    };
}ifd_108_ifd_bist_dvs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_mode_ifd:1;
        RBus_UInt32  res1:31;
    };
}ifd_108_ifd_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_bist_mode_ifd:1;
        RBus_UInt32  res1:31;
    };
}ifd_108_ifd_drf_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_test_resume_ifd:1;
        RBus_UInt32  res1:31;
    };
}ifd_108_ifd_drf_test_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_ls_cntl:1;
        RBus_UInt32  res1:31;
    };
}ifd_108_ifd_ls_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_done_ifd:1;
        RBus_UInt32  res1:31;
    };
}ifd_108_ifd_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_bist_done_ifd:1;
        RBus_UInt32  res1:31;
    };
}ifd_108_ifd_drf_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_fail_ifd:1;
        RBus_UInt32  res1:31;
    };
}ifd_108_ifd_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_bist_fail_ifd:1;
        RBus_UInt32  res1:31;
    };
}ifd_108_ifd_drf_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_start_pause_ifd:1;
        RBus_UInt32  res1:31;
    };
}ifd_108_ifd_drf_bist_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  debug_mode:7;
        RBus_UInt32  debug_mode_en:1;
        RBus_UInt32  debug_adcclk_polar:1;
        RBus_UInt32  debug_clk108_polar:1;
        RBus_UInt32  debug_clk54_polar:1;
        RBus_UInt32  debug_clk49_polar:1;
        RBus_UInt32  debug_clk27_polar:1;
        RBus_UInt32  res1:19;
    };
}ifd_108_debug_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  debug_mode3:7;
        RBus_UInt32  debug_mode3_en:1;
        RBus_UInt32  res2:16;
    };
}ifd_108_debug_mode3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  test_mode:7;
        RBus_UInt32  test_mode_en:1;
        RBus_UInt32  res1:24;
    };
}ifd_108_test_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  agc_self_test_sel:1;
        RBus_UInt32  agc_self_test_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  cr_self_test_en:1;
        RBus_UInt32  res3:24;
    };
}ifd_108_cr_self_test_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  crc2_insel:1;
        RBus_UInt32  crc2_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  crc1_insel:1;
        RBus_UInt32  res3:25;
    };
}ifd_108_crc_ctrl_register_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc2_result:32;
    };
}ifd_108_crc2_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dac_dctest:12;
        RBus_UInt32  sinout_sel:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  dactest_sel:1;
        RBus_UInt32  res2:15;
    };
}ifd_108_dactest_register1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bypassad:1;
        RBus_UInt32  res1:31;
    };
}ifd_108_adbypassenable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fpga_test1:32;
    };
}ifd_108_fpga_test1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fpga_test2:32;
    };
}ifd_108_fpga_test2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fpga_test3:32;
    };
}ifd_108_fpga_test3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  debug_clk1:1;
        RBus_UInt32  debug_clk2:1;
        RBus_UInt32  debug_clk3:1;
        RBus_UInt32  debug_clk4:1;
        RBus_UInt32  debug_clk5:1;
        RBus_UInt32  fpga_test4:27;
    };
}ifd_108_fpga_test4_debug_clk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_lock_int:1;
        RBus_UInt32  agc_lock_int:1;
        RBus_UInt32  rf_agc_max_int:1;
        RBus_UInt32  input_fifo_int:1;
        RBus_UInt32  cr_unlock_int:1;
        RBus_UInt32  mod_state_int:1;
        RBus_UInt32  agc_unlock_int:1;
        RBus_UInt32  pga_s2w_int:1;
        RBus_UInt32  pga_w2s_int:1;
        RBus_UInt32  rf_s2w_int:1;
        RBus_UInt32  rf_w2s_int:1;
        RBus_UInt32  if_s2w_int:1;
        RBus_UInt32  if_w2s_int:1;
        RBus_UInt32  input_power_over_int:1;
        RBus_UInt32  input_power_lower_int:1;
        RBus_UInt32  res1:17;
    };
}ifd_108_interrupt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mask_cr_lock_en:1;
        RBus_UInt32  mask_agc_lock_en:1;
        RBus_UInt32  mask_rf_agc_max_en:1;
        RBus_UInt32  mask_input_fifo_status_en:1;
        RBus_UInt32  mask_cr_unlock_en:1;
        RBus_UInt32  mask_mod_state_en:1;
        RBus_UInt32  mask_agc_unlock_en:1;
        RBus_UInt32  mask_pga_s2w_en:1;
        RBus_UInt32  mask_pga_w2s_en:1;
        RBus_UInt32  mask_rf_s2w_en:1;
        RBus_UInt32  mask_rf_w2s_en:1;
        RBus_UInt32  mask_if_s2w_en:1;
        RBus_UInt32  mask_if_w2s_en:1;
        RBus_UInt32  mask_input_power_over_en:1;
        RBus_UInt32  mask_input_power_lower_en:1;
        RBus_UInt32  ifd_int_mask:1;
        RBus_UInt32  res1:16;
    };
}ifd_108_interrupt_mask_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  video_upsample_lp_sel:4;
        RBus_UInt32  video_bw_sel:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  output_lpf_1m:1;
        RBus_UInt32  res2:23;
    };
}ifd_108_video_bw_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  grp_delay_coe_modofy:11;
        RBus_UInt32  res1:1;
        RBus_UInt32  grp_delay_select_tap:8;
        RBus_UInt32  grp_delay_coe_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  grp_delay_en:1;
        RBus_UInt32  res3:7;
    };
}ifd_108_grp_delay_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  grp_delay_coe_modofy_read:11;
        RBus_UInt32  res1:1;
        RBus_UInt32  grp_delay_select_tap_read:8;
        RBus_UInt32  res2:12;
    };
}ifd_108_grp_delay_read_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  output_lpf_coe:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  output_lpf_coe_tap:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  output_lpf_coe_modify_en:1;
        RBus_UInt32  res3:4;
        RBus_UInt32  output_lpf_vsync_coe_change:1;
        RBus_UInt32  res4:2;
    };
}ifd_108_output_lpf_modify_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  output_lpf_coe_read:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  output_lpf_coe_read_tap:7;
        RBus_UInt32  res2:9;
    };
}ifd_108_output_lpf_read_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dnlpf_en:1;
        RBus_UInt32  res2:7;
    };
}ifd_108_dnlpf_tap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_coe:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  eq_coe_tap:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  eq_coe_modify_en:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  eq_en:1;
        RBus_UInt32  res4:7;
    };
}ifd_108_eq_filter_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_coe_read:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  eq_coe_read_tap:5;
        RBus_UInt32  res2:15;
    };
}ifd_108_eq_filter_read_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_out_rms:22;
        RBus_UInt32  res1:10;
    };
}ifd_108_eq_out_rms_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc3_insel:1;
        RBus_UInt32  crc3_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  crc3_result:16;
        RBus_UInt32  res2:12;
    };
}ifd_108_crc3_ctrl_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dec_fifo_empty:1;
        RBus_UInt32  dec_fifo_full:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  dec_fifo_empty_clear:1;
        RBus_UInt32  dec_fifo_full_clear:1;
        RBus_UInt32  res2:26;
    };
}ifd_108_dec_fifostatus_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  debug_mode4:7;
        RBus_UInt32  debug_mode4_en:1;
        RBus_UInt32  res1:24;
    };
}ifd_108_debug_mode4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vddac_test:12;
        RBus_UInt32  res1:20;
    };
}ifd_108_vd_dac_test_RBUS;




#endif 


#endif 
