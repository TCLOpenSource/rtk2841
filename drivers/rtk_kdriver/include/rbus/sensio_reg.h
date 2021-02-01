/**
* @file MacArthur5-DesignSpec-I-Domain_SENSIO
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_SENSIO_REG_H_
#define _RBUS_SENSIO_REG_H_

#include "rbus_types.h"



//  SENSIO Register Address
#define  SENSIO_Sensio_ctrl_0                                                    0x1806B900
#define  SENSIO_Sensio_ctrl_0_reg_addr                                           "0xB806B900"
#define  SENSIO_Sensio_ctrl_0_reg                                                0xB806B900
#define  SENSIO_Sensio_ctrl_0_inst_addr                                          "0x0000"
#define  set_SENSIO_Sensio_ctrl_0_reg(data)                                      (*((volatile unsigned int*)SENSIO_Sensio_ctrl_0_reg)=data)
#define  get_SENSIO_Sensio_ctrl_0_reg                                            (*((volatile unsigned int*)SENSIO_Sensio_ctrl_0_reg))
#define  SENSIO_Sensio_ctrl_0_re_decom_en_shift                                  (29)
#define  SENSIO_Sensio_ctrl_0_vflip_en_shift                                     (7)
#define  SENSIO_Sensio_ctrl_0_force_ctsfifo_rstn_sensio_shift                    (6)
#define  SENSIO_Sensio_ctrl_0_en_ctsfifo_vsrst_sensio_shift                      (5)
#define  SENSIO_Sensio_ctrl_0_en_ctsfifo_bypass_sensio_shift                     (4)
#define  SENSIO_Sensio_ctrl_0_re_decom_en_mask                                   (0x20000000)
#define  SENSIO_Sensio_ctrl_0_vflip_en_mask                                      (0x00000080)
#define  SENSIO_Sensio_ctrl_0_force_ctsfifo_rstn_sensio_mask                     (0x00000040)
#define  SENSIO_Sensio_ctrl_0_en_ctsfifo_vsrst_sensio_mask                       (0x00000020)
#define  SENSIO_Sensio_ctrl_0_en_ctsfifo_bypass_sensio_mask                      (0x00000010)
#define  SENSIO_Sensio_ctrl_0_re_decom_en(data)                                  (0x20000000&((data)<<29))
#define  SENSIO_Sensio_ctrl_0_vflip_en(data)                                     (0x00000080&((data)<<7))
#define  SENSIO_Sensio_ctrl_0_force_ctsfifo_rstn_sensio(data)                    (0x00000040&((data)<<6))
#define  SENSIO_Sensio_ctrl_0_en_ctsfifo_vsrst_sensio(data)                      (0x00000020&((data)<<5))
#define  SENSIO_Sensio_ctrl_0_en_ctsfifo_bypass_sensio(data)                     (0x00000010&((data)<<4))
#define  SENSIO_Sensio_ctrl_0_get_re_decom_en(data)                              ((0x20000000&(data))>>29)
#define  SENSIO_Sensio_ctrl_0_get_vflip_en(data)                                 ((0x00000080&(data))>>7)
#define  SENSIO_Sensio_ctrl_0_get_force_ctsfifo_rstn_sensio(data)                ((0x00000040&(data))>>6)
#define  SENSIO_Sensio_ctrl_0_get_en_ctsfifo_vsrst_sensio(data)                  ((0x00000020&(data))>>5)
#define  SENSIO_Sensio_ctrl_0_get_en_ctsfifo_bypass_sensio(data)                 ((0x00000010&(data))>>4)

#define  SENSIO_Sensio_ctrl_2                                                    0x1806B908
#define  SENSIO_Sensio_ctrl_2_reg_addr                                           "0xB806B908"
#define  SENSIO_Sensio_ctrl_2_reg                                                0xB806B908
#define  SENSIO_Sensio_ctrl_2_inst_addr                                          "0x0001"
#define  set_SENSIO_Sensio_ctrl_2_reg(data)                                      (*((volatile unsigned int*)SENSIO_Sensio_ctrl_2_reg)=data)
#define  get_SENSIO_Sensio_ctrl_2_reg                                            (*((volatile unsigned int*)SENSIO_Sensio_ctrl_2_reg))
#define  SENSIO_Sensio_ctrl_2_sensio_ivsize_shift                                (16)
#define  SENSIO_Sensio_ctrl_2_sensio_ihsize_shift                                (0)
#define  SENSIO_Sensio_ctrl_2_sensio_ivsize_mask                                 (0x0FFF0000)
#define  SENSIO_Sensio_ctrl_2_sensio_ihsize_mask                                 (0x00000FFF)
#define  SENSIO_Sensio_ctrl_2_sensio_ivsize(data)                                (0x0FFF0000&((data)<<16))
#define  SENSIO_Sensio_ctrl_2_sensio_ihsize(data)                                (0x00000FFF&(data))
#define  SENSIO_Sensio_ctrl_2_get_sensio_ivsize(data)                            ((0x0FFF0000&(data))>>16)
#define  SENSIO_Sensio_ctrl_2_get_sensio_ihsize(data)                            (0x00000FFF&(data))

#define  SENSIO_Sensio_ctrl_3                                                    0x1806B90C
#define  SENSIO_Sensio_ctrl_3_reg_addr                                           "0xB806B90C"
#define  SENSIO_Sensio_ctrl_3_reg                                                0xB806B90C
#define  SENSIO_Sensio_ctrl_3_inst_addr                                          "0x0002"
#define  set_SENSIO_Sensio_ctrl_3_reg(data)                                      (*((volatile unsigned int*)SENSIO_Sensio_ctrl_3_reg)=data)
#define  get_SENSIO_Sensio_ctrl_3_reg                                            (*((volatile unsigned int*)SENSIO_Sensio_ctrl_3_reg))
#define  SENSIO_Sensio_ctrl_3_sensio_double_apply_shift                          (18)
#define  SENSIO_Sensio_ctrl_3_sensio_double_en_shift                             (17)
#define  SENSIO_Sensio_ctrl_3_sensio_read_sel_shift                              (16)
#define  SENSIO_Sensio_ctrl_3_sensio_sub_double_apply_shift                      (1)
#define  SENSIO_Sensio_ctrl_3_sensio_sub_double_en_shift                         (0)
#define  SENSIO_Sensio_ctrl_3_sensio_double_apply_mask                           (0x00040000)
#define  SENSIO_Sensio_ctrl_3_sensio_double_en_mask                              (0x00020000)
#define  SENSIO_Sensio_ctrl_3_sensio_read_sel_mask                               (0x00010000)
#define  SENSIO_Sensio_ctrl_3_sensio_sub_double_apply_mask                       (0x00000002)
#define  SENSIO_Sensio_ctrl_3_sensio_sub_double_en_mask                          (0x00000001)
#define  SENSIO_Sensio_ctrl_3_sensio_double_apply(data)                          (0x00040000&((data)<<18))
#define  SENSIO_Sensio_ctrl_3_sensio_double_en(data)                             (0x00020000&((data)<<17))
#define  SENSIO_Sensio_ctrl_3_sensio_read_sel(data)                              (0x00010000&((data)<<16))
#define  SENSIO_Sensio_ctrl_3_sensio_sub_double_apply(data)                      (0x00000002&((data)<<1))
#define  SENSIO_Sensio_ctrl_3_sensio_sub_double_en(data)                         (0x00000001&(data))
#define  SENSIO_Sensio_ctrl_3_get_sensio_double_apply(data)                      ((0x00040000&(data))>>18)
#define  SENSIO_Sensio_ctrl_3_get_sensio_double_en(data)                         ((0x00020000&(data))>>17)
#define  SENSIO_Sensio_ctrl_3_get_sensio_read_sel(data)                          ((0x00010000&(data))>>16)
#define  SENSIO_Sensio_ctrl_3_get_sensio_sub_double_apply(data)                  ((0x00000002&(data))>>1)
#define  SENSIO_Sensio_ctrl_3_get_sensio_sub_double_en(data)                     (0x00000001&(data))

#define  SENSIO_decomp_ctrl_0                                                    0x1806B910
#define  SENSIO_decomp_ctrl_0_reg_addr                                           "0xB806B910"
#define  SENSIO_decomp_ctrl_0_reg                                                0xB806B910
#define  SENSIO_decomp_ctrl_0_inst_addr                                          "0x0003"
#define  set_SENSIO_decomp_ctrl_0_reg(data)                                      (*((volatile unsigned int*)SENSIO_decomp_ctrl_0_reg)=data)
#define  get_SENSIO_decomp_ctrl_0_reg                                            (*((volatile unsigned int*)SENSIO_decomp_ctrl_0_reg))
#define  SENSIO_decomp_ctrl_0_main_decomp_10bit_shift                            (0)
#define  SENSIO_decomp_ctrl_0_main_decomp_10bit_mask                             (0x00000003)
#define  SENSIO_decomp_ctrl_0_main_decomp_10bit(data)                            (0x00000003&(data))
#define  SENSIO_decomp_ctrl_0_get_main_decomp_10bit(data)                        (0x00000003&(data))

#define  SENSIO_SUB_vp9_decomp_ctrl_0                                            0x1806B920
#define  SENSIO_SUB_vp9_decomp_ctrl_0_reg_addr                                   "0xB806B920"
#define  SENSIO_SUB_vp9_decomp_ctrl_0_reg                                        0xB806B920
#define  SENSIO_SUB_vp9_decomp_ctrl_0_inst_addr                                  "0x0004"
#define  set_SENSIO_SUB_vp9_decomp_ctrl_0_reg(data)                              (*((volatile unsigned int*)SENSIO_SUB_vp9_decomp_ctrl_0_reg)=data)
#define  get_SENSIO_SUB_vp9_decomp_ctrl_0_reg                                    (*((volatile unsigned int*)SENSIO_SUB_vp9_decomp_ctrl_0_reg))
#define  SENSIO_SUB_vp9_decomp_ctrl_0_sub_vflip_en_shift                         (4)
#define  SENSIO_SUB_vp9_decomp_ctrl_0_sub_decomp_10bit_shift                     (2)
#define  SENSIO_SUB_vp9_decomp_ctrl_0_sub_re_decom_en_shift                      (1)
#define  SENSIO_SUB_vp9_decomp_ctrl_0_sub_vflip_en_mask                          (0x00000010)
#define  SENSIO_SUB_vp9_decomp_ctrl_0_sub_decomp_10bit_mask                      (0x0000000C)
#define  SENSIO_SUB_vp9_decomp_ctrl_0_sub_re_decom_en_mask                       (0x00000002)
#define  SENSIO_SUB_vp9_decomp_ctrl_0_sub_vflip_en(data)                         (0x00000010&((data)<<4))
#define  SENSIO_SUB_vp9_decomp_ctrl_0_sub_decomp_10bit(data)                     (0x0000000C&((data)<<2))
#define  SENSIO_SUB_vp9_decomp_ctrl_0_sub_re_decom_en(data)                      (0x00000002&((data)<<1))
#define  SENSIO_SUB_vp9_decomp_ctrl_0_get_sub_vflip_en(data)                     ((0x00000010&(data))>>4)
#define  SENSIO_SUB_vp9_decomp_ctrl_0_get_sub_decomp_10bit(data)                 ((0x0000000C&(data))>>2)
#define  SENSIO_SUB_vp9_decomp_ctrl_0_get_sub_re_decom_en(data)                  ((0x00000002&(data))>>1)

#define  SENSIO_sub_vp9_decomp_ctrl_1                                            0x1806B924
#define  SENSIO_sub_vp9_decomp_ctrl_1_reg_addr                                   "0xB806B924"
#define  SENSIO_sub_vp9_decomp_ctrl_1_reg                                        0xB806B924
#define  SENSIO_sub_vp9_decomp_ctrl_1_inst_addr                                  "0x0005"
#define  set_SENSIO_sub_vp9_decomp_ctrl_1_reg(data)                              (*((volatile unsigned int*)SENSIO_sub_vp9_decomp_ctrl_1_reg)=data)
#define  get_SENSIO_sub_vp9_decomp_ctrl_1_reg                                    (*((volatile unsigned int*)SENSIO_sub_vp9_decomp_ctrl_1_reg))
#define  SENSIO_sub_vp9_decomp_ctrl_1_sub_v_d_ivsize_shift                       (16)
#define  SENSIO_sub_vp9_decomp_ctrl_1_sub_v_d_ihsize_shift                       (0)
#define  SENSIO_sub_vp9_decomp_ctrl_1_sub_v_d_ivsize_mask                        (0x07FF0000)
#define  SENSIO_sub_vp9_decomp_ctrl_1_sub_v_d_ihsize_mask                        (0x00000FFF)
#define  SENSIO_sub_vp9_decomp_ctrl_1_sub_v_d_ivsize(data)                       (0x07FF0000&((data)<<16))
#define  SENSIO_sub_vp9_decomp_ctrl_1_sub_v_d_ihsize(data)                       (0x00000FFF&(data))
#define  SENSIO_sub_vp9_decomp_ctrl_1_get_sub_v_d_ivsize(data)                   ((0x07FF0000&(data))>>16)
#define  SENSIO_sub_vp9_decomp_ctrl_1_get_sub_v_d_ihsize(data)                   (0x00000FFF&(data))

#define  SENSIO_vp9_decomp_v_ctrl                                                0x1806B928
#define  SENSIO_vp9_decomp_v_ctrl_reg_addr                                       "0xB806B928"
#define  SENSIO_vp9_decomp_v_ctrl_reg                                            0xB806B928
#define  SENSIO_vp9_decomp_v_ctrl_inst_addr                                      "0x0006"
#define  set_SENSIO_vp9_decomp_v_ctrl_reg(data)                                  (*((volatile unsigned int*)SENSIO_vp9_decomp_v_ctrl_reg)=data)
#define  get_SENSIO_vp9_decomp_v_ctrl_reg                                        (*((volatile unsigned int*)SENSIO_vp9_decomp_v_ctrl_reg))
#define  SENSIO_vp9_decomp_v_ctrl_real_vp9_vend_shift                            (16)
#define  SENSIO_vp9_decomp_v_ctrl_real_vp9_vstart_shift                          (0)
#define  SENSIO_vp9_decomp_v_ctrl_real_vp9_vend_mask                             (0x0FFF0000)
#define  SENSIO_vp9_decomp_v_ctrl_real_vp9_vstart_mask                           (0x00000FFF)
#define  SENSIO_vp9_decomp_v_ctrl_real_vp9_vend(data)                            (0x0FFF0000&((data)<<16))
#define  SENSIO_vp9_decomp_v_ctrl_real_vp9_vstart(data)                          (0x00000FFF&(data))
#define  SENSIO_vp9_decomp_v_ctrl_get_real_vp9_vend(data)                        ((0x0FFF0000&(data))>>16)
#define  SENSIO_vp9_decomp_v_ctrl_get_real_vp9_vstart(data)                      (0x00000FFF&(data))

#define  SENSIO_sub_vp9_decomp_v_ctrl                                            0x1806B92C
#define  SENSIO_sub_vp9_decomp_v_ctrl_reg_addr                                   "0xB806B92C"
#define  SENSIO_sub_vp9_decomp_v_ctrl_reg                                        0xB806B92C
#define  SENSIO_sub_vp9_decomp_v_ctrl_inst_addr                                  "0x0007"
#define  set_SENSIO_sub_vp9_decomp_v_ctrl_reg(data)                              (*((volatile unsigned int*)SENSIO_sub_vp9_decomp_v_ctrl_reg)=data)
#define  get_SENSIO_sub_vp9_decomp_v_ctrl_reg                                    (*((volatile unsigned int*)SENSIO_sub_vp9_decomp_v_ctrl_reg))
#define  SENSIO_sub_vp9_decomp_v_ctrl_sub_real_vp9_vend_shift                    (16)
#define  SENSIO_sub_vp9_decomp_v_ctrl_sub_real_vp9_vstart_shift                  (0)
#define  SENSIO_sub_vp9_decomp_v_ctrl_sub_real_vp9_vend_mask                     (0x07FF0000)
#define  SENSIO_sub_vp9_decomp_v_ctrl_sub_real_vp9_vstart_mask                   (0x000007FF)
#define  SENSIO_sub_vp9_decomp_v_ctrl_sub_real_vp9_vend(data)                    (0x07FF0000&((data)<<16))
#define  SENSIO_sub_vp9_decomp_v_ctrl_sub_real_vp9_vstart(data)                  (0x000007FF&(data))
#define  SENSIO_sub_vp9_decomp_v_ctrl_get_sub_real_vp9_vend(data)                ((0x07FF0000&(data))>>16)
#define  SENSIO_sub_vp9_decomp_v_ctrl_get_sub_real_vp9_vstart(data)              (0x000007FF&(data))

#define  SENSIO_SENSIO_TIM_CTRL_0                                                0x1806B930
#define  SENSIO_SENSIO_TIM_CTRL_0_reg_addr                                       "0xB806B930"
#define  SENSIO_SENSIO_TIM_CTRL_0_reg                                            0xB806B930
#define  SENSIO_SENSIO_TIM_CTRL_0_inst_addr                                      "0x0008"
#define  set_SENSIO_SENSIO_TIM_CTRL_0_reg(data)                                  (*((volatile unsigned int*)SENSIO_SENSIO_TIM_CTRL_0_reg)=data)
#define  get_SENSIO_SENSIO_TIM_CTRL_0_reg                                        (*((volatile unsigned int*)SENSIO_SENSIO_TIM_CTRL_0_reg))
#define  SENSIO_SENSIO_TIM_CTRL_0_hs_width_shift                                 (16)
#define  SENSIO_SENSIO_TIM_CTRL_0_h_total_shift                                  (0)
#define  SENSIO_SENSIO_TIM_CTRL_0_hs_width_mask                                  (0x003F0000)
#define  SENSIO_SENSIO_TIM_CTRL_0_h_total_mask                                   (0x00001FFF)
#define  SENSIO_SENSIO_TIM_CTRL_0_hs_width(data)                                 (0x003F0000&((data)<<16))
#define  SENSIO_SENSIO_TIM_CTRL_0_h_total(data)                                  (0x00001FFF&(data))
#define  SENSIO_SENSIO_TIM_CTRL_0_get_hs_width(data)                             ((0x003F0000&(data))>>16)
#define  SENSIO_SENSIO_TIM_CTRL_0_get_h_total(data)                              (0x00001FFF&(data))

#define  SENSIO_SENSIO_TIM_CTRL_1                                                0x1806B934
#define  SENSIO_SENSIO_TIM_CTRL_1_reg_addr                                       "0xB806B934"
#define  SENSIO_SENSIO_TIM_CTRL_1_reg                                            0xB806B934
#define  SENSIO_SENSIO_TIM_CTRL_1_inst_addr                                      "0x0009"
#define  set_SENSIO_SENSIO_TIM_CTRL_1_reg(data)                                  (*((volatile unsigned int*)SENSIO_SENSIO_TIM_CTRL_1_reg)=data)
#define  get_SENSIO_SENSIO_TIM_CTRL_1_reg                                        (*((volatile unsigned int*)SENSIO_SENSIO_TIM_CTRL_1_reg))
#define  SENSIO_SENSIO_TIM_CTRL_1_v_den_st_shift                                 (16)
#define  SENSIO_SENSIO_TIM_CTRL_1_h_den_st_shift                                 (0)
#define  SENSIO_SENSIO_TIM_CTRL_1_v_den_st_mask                                  (0x00FF0000)
#define  SENSIO_SENSIO_TIM_CTRL_1_h_den_st_mask                                  (0x00000FFF)
#define  SENSIO_SENSIO_TIM_CTRL_1_v_den_st(data)                                 (0x00FF0000&((data)<<16))
#define  SENSIO_SENSIO_TIM_CTRL_1_h_den_st(data)                                 (0x00000FFF&(data))
#define  SENSIO_SENSIO_TIM_CTRL_1_get_v_den_st(data)                             ((0x00FF0000&(data))>>16)
#define  SENSIO_SENSIO_TIM_CTRL_1_get_h_den_st(data)                             (0x00000FFF&(data))

#define  SENSIO_SUB_SENSIO_TIM_CTRL_0                                            0x1806B938
#define  SENSIO_SUB_SENSIO_TIM_CTRL_0_reg_addr                                   "0xB806B938"
#define  SENSIO_SUB_SENSIO_TIM_CTRL_0_reg                                        0xB806B938
#define  SENSIO_SUB_SENSIO_TIM_CTRL_0_inst_addr                                  "0x000A"
#define  set_SENSIO_SUB_SENSIO_TIM_CTRL_0_reg(data)                              (*((volatile unsigned int*)SENSIO_SUB_SENSIO_TIM_CTRL_0_reg)=data)
#define  get_SENSIO_SUB_SENSIO_TIM_CTRL_0_reg                                    (*((volatile unsigned int*)SENSIO_SUB_SENSIO_TIM_CTRL_0_reg))
#define  SENSIO_SUB_SENSIO_TIM_CTRL_0_sub_hs_width_shift                         (16)
#define  SENSIO_SUB_SENSIO_TIM_CTRL_0_sub_h_total_shift                          (0)
#define  SENSIO_SUB_SENSIO_TIM_CTRL_0_sub_hs_width_mask                          (0x003F0000)
#define  SENSIO_SUB_SENSIO_TIM_CTRL_0_sub_h_total_mask                           (0x00001FFF)
#define  SENSIO_SUB_SENSIO_TIM_CTRL_0_sub_hs_width(data)                         (0x003F0000&((data)<<16))
#define  SENSIO_SUB_SENSIO_TIM_CTRL_0_sub_h_total(data)                          (0x00001FFF&(data))
#define  SENSIO_SUB_SENSIO_TIM_CTRL_0_get_sub_hs_width(data)                     ((0x003F0000&(data))>>16)
#define  SENSIO_SUB_SENSIO_TIM_CTRL_0_get_sub_h_total(data)                      (0x00001FFF&(data))

#define  SENSIO_SUB_SENSIO_TIM_CTRL_1                                            0x1806B93C
#define  SENSIO_SUB_SENSIO_TIM_CTRL_1_reg_addr                                   "0xB806B93C"
#define  SENSIO_SUB_SENSIO_TIM_CTRL_1_reg                                        0xB806B93C
#define  SENSIO_SUB_SENSIO_TIM_CTRL_1_inst_addr                                  "0x000B"
#define  set_SENSIO_SUB_SENSIO_TIM_CTRL_1_reg(data)                              (*((volatile unsigned int*)SENSIO_SUB_SENSIO_TIM_CTRL_1_reg)=data)
#define  get_SENSIO_SUB_SENSIO_TIM_CTRL_1_reg                                    (*((volatile unsigned int*)SENSIO_SUB_SENSIO_TIM_CTRL_1_reg))
#define  SENSIO_SUB_SENSIO_TIM_CTRL_1_sub_v_den_st_shift                         (16)
#define  SENSIO_SUB_SENSIO_TIM_CTRL_1_sub_h_den_st_shift                         (0)
#define  SENSIO_SUB_SENSIO_TIM_CTRL_1_sub_v_den_st_mask                          (0x00FF0000)
#define  SENSIO_SUB_SENSIO_TIM_CTRL_1_sub_h_den_st_mask                          (0x00000FFF)
#define  SENSIO_SUB_SENSIO_TIM_CTRL_1_sub_v_den_st(data)                         (0x00FF0000&((data)<<16))
#define  SENSIO_SUB_SENSIO_TIM_CTRL_1_sub_h_den_st(data)                         (0x00000FFF&(data))
#define  SENSIO_SUB_SENSIO_TIM_CTRL_1_get_sub_v_den_st(data)                     ((0x00FF0000&(data))>>16)
#define  SENSIO_SUB_SENSIO_TIM_CTRL_1_get_sub_h_den_st(data)                     (0x00000FFF&(data))

#define  SENSIO_SENSIO_MBIST_FAIL_0                                              0x1806B990
#define  SENSIO_SENSIO_MBIST_FAIL_0_reg_addr                                     "0xB806B990"
#define  SENSIO_SENSIO_MBIST_FAIL_0_reg                                          0xB806B990
#define  SENSIO_SENSIO_MBIST_FAIL_0_inst_addr                                    "0x000C"
#define  set_SENSIO_SENSIO_MBIST_FAIL_0_reg(data)                                (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_FAIL_0_reg)=data)
#define  get_SENSIO_SENSIO_MBIST_FAIL_0_reg                                      (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_FAIL_0_reg))
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_1_9_shift                          (19)
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_1_8_shift                          (18)
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_1_7_shift                          (17)
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_1_6_shift                          (16)
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_1_5_shift                          (15)
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_1_4_shift                          (14)
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_1_3_shift                          (13)
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_1_2_shift                          (12)
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_1_1_shift                          (11)
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_1_0_shift                          (10)
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_0_9_shift                          (9)
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_0_8_shift                          (8)
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_0_7_shift                          (7)
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_0_6_shift                          (6)
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_0_5_shift                          (5)
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_0_4_shift                          (4)
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_0_3_shift                          (3)
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_0_2_shift                          (2)
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_0_1_shift                          (1)
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_0_0_shift                          (0)
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_1_9_mask                           (0x00080000)
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_1_8_mask                           (0x00040000)
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_1_7_mask                           (0x00020000)
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_1_6_mask                           (0x00010000)
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_1_5_mask                           (0x00008000)
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_1_4_mask                           (0x00004000)
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_1_3_mask                           (0x00002000)
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_1_2_mask                           (0x00001000)
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_1_1_mask                           (0x00000800)
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_1_0_mask                           (0x00000400)
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_0_9_mask                           (0x00000200)
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_0_8_mask                           (0x00000100)
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_0_7_mask                           (0x00000080)
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_0_6_mask                           (0x00000040)
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_0_5_mask                           (0x00000020)
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_0_4_mask                           (0x00000010)
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_0_3_mask                           (0x00000008)
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_0_2_mask                           (0x00000004)
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_0_1_mask                           (0x00000002)
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_0_0_mask                           (0x00000001)
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_1_9(data)                          (0x00080000&((data)<<19))
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_1_8(data)                          (0x00040000&((data)<<18))
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_1_7(data)                          (0x00020000&((data)<<17))
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_1_6(data)                          (0x00010000&((data)<<16))
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_1_5(data)                          (0x00008000&((data)<<15))
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_1_4(data)                          (0x00004000&((data)<<14))
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_1_3(data)                          (0x00002000&((data)<<13))
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_1_2(data)                          (0x00001000&((data)<<12))
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_1_1(data)                          (0x00000800&((data)<<11))
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_1_0(data)                          (0x00000400&((data)<<10))
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_0_9(data)                          (0x00000200&((data)<<9))
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_0_8(data)                          (0x00000100&((data)<<8))
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_0_7(data)                          (0x00000080&((data)<<7))
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_0_6(data)                          (0x00000040&((data)<<6))
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_0_5(data)                          (0x00000020&((data)<<5))
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_0_4(data)                          (0x00000010&((data)<<4))
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_0_3(data)                          (0x00000008&((data)<<3))
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_0_2(data)                          (0x00000004&((data)<<2))
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_0_1(data)                          (0x00000002&((data)<<1))
#define  SENSIO_SENSIO_MBIST_FAIL_0_bist_fail_0_0(data)                          (0x00000001&(data))
#define  SENSIO_SENSIO_MBIST_FAIL_0_get_bist_fail_1_9(data)                      ((0x00080000&(data))>>19)
#define  SENSIO_SENSIO_MBIST_FAIL_0_get_bist_fail_1_8(data)                      ((0x00040000&(data))>>18)
#define  SENSIO_SENSIO_MBIST_FAIL_0_get_bist_fail_1_7(data)                      ((0x00020000&(data))>>17)
#define  SENSIO_SENSIO_MBIST_FAIL_0_get_bist_fail_1_6(data)                      ((0x00010000&(data))>>16)
#define  SENSIO_SENSIO_MBIST_FAIL_0_get_bist_fail_1_5(data)                      ((0x00008000&(data))>>15)
#define  SENSIO_SENSIO_MBIST_FAIL_0_get_bist_fail_1_4(data)                      ((0x00004000&(data))>>14)
#define  SENSIO_SENSIO_MBIST_FAIL_0_get_bist_fail_1_3(data)                      ((0x00002000&(data))>>13)
#define  SENSIO_SENSIO_MBIST_FAIL_0_get_bist_fail_1_2(data)                      ((0x00001000&(data))>>12)
#define  SENSIO_SENSIO_MBIST_FAIL_0_get_bist_fail_1_1(data)                      ((0x00000800&(data))>>11)
#define  SENSIO_SENSIO_MBIST_FAIL_0_get_bist_fail_1_0(data)                      ((0x00000400&(data))>>10)
#define  SENSIO_SENSIO_MBIST_FAIL_0_get_bist_fail_0_9(data)                      ((0x00000200&(data))>>9)
#define  SENSIO_SENSIO_MBIST_FAIL_0_get_bist_fail_0_8(data)                      ((0x00000100&(data))>>8)
#define  SENSIO_SENSIO_MBIST_FAIL_0_get_bist_fail_0_7(data)                      ((0x00000080&(data))>>7)
#define  SENSIO_SENSIO_MBIST_FAIL_0_get_bist_fail_0_6(data)                      ((0x00000040&(data))>>6)
#define  SENSIO_SENSIO_MBIST_FAIL_0_get_bist_fail_0_5(data)                      ((0x00000020&(data))>>5)
#define  SENSIO_SENSIO_MBIST_FAIL_0_get_bist_fail_0_4(data)                      ((0x00000010&(data))>>4)
#define  SENSIO_SENSIO_MBIST_FAIL_0_get_bist_fail_0_3(data)                      ((0x00000008&(data))>>3)
#define  SENSIO_SENSIO_MBIST_FAIL_0_get_bist_fail_0_2(data)                      ((0x00000004&(data))>>2)
#define  SENSIO_SENSIO_MBIST_FAIL_0_get_bist_fail_0_1(data)                      ((0x00000002&(data))>>1)
#define  SENSIO_SENSIO_MBIST_FAIL_0_get_bist_fail_0_0(data)                      (0x00000001&(data))

#define  SENSIO_SENSIO_MBIST_FAIL_1                                              0x1806B994
#define  SENSIO_SENSIO_MBIST_FAIL_1_reg_addr                                     "0xB806B994"
#define  SENSIO_SENSIO_MBIST_FAIL_1_reg                                          0xB806B994
#define  SENSIO_SENSIO_MBIST_FAIL_1_inst_addr                                    "0x000D"
#define  set_SENSIO_SENSIO_MBIST_FAIL_1_reg(data)                                (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_FAIL_1_reg)=data)
#define  get_SENSIO_SENSIO_MBIST_FAIL_1_reg                                      (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_FAIL_1_reg))
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_3_9_shift                          (19)
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_3_8_shift                          (18)
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_3_7_shift                          (17)
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_3_6_shift                          (16)
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_3_5_shift                          (15)
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_3_4_shift                          (14)
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_3_3_shift                          (13)
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_3_2_shift                          (12)
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_3_1_shift                          (11)
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_3_0_shift                          (10)
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_2_9_shift                          (9)
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_2_8_shift                          (8)
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_2_7_shift                          (7)
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_2_6_shift                          (6)
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_2_5_shift                          (5)
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_2_4_shift                          (4)
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_2_3_shift                          (3)
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_2_2_shift                          (2)
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_2_1_shift                          (1)
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_2_0_shift                          (0)
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_3_9_mask                           (0x00080000)
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_3_8_mask                           (0x00040000)
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_3_7_mask                           (0x00020000)
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_3_6_mask                           (0x00010000)
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_3_5_mask                           (0x00008000)
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_3_4_mask                           (0x00004000)
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_3_3_mask                           (0x00002000)
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_3_2_mask                           (0x00001000)
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_3_1_mask                           (0x00000800)
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_3_0_mask                           (0x00000400)
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_2_9_mask                           (0x00000200)
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_2_8_mask                           (0x00000100)
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_2_7_mask                           (0x00000080)
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_2_6_mask                           (0x00000040)
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_2_5_mask                           (0x00000020)
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_2_4_mask                           (0x00000010)
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_2_3_mask                           (0x00000008)
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_2_2_mask                           (0x00000004)
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_2_1_mask                           (0x00000002)
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_2_0_mask                           (0x00000001)
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_3_9(data)                          (0x00080000&((data)<<19))
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_3_8(data)                          (0x00040000&((data)<<18))
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_3_7(data)                          (0x00020000&((data)<<17))
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_3_6(data)                          (0x00010000&((data)<<16))
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_3_5(data)                          (0x00008000&((data)<<15))
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_3_4(data)                          (0x00004000&((data)<<14))
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_3_3(data)                          (0x00002000&((data)<<13))
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_3_2(data)                          (0x00001000&((data)<<12))
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_3_1(data)                          (0x00000800&((data)<<11))
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_3_0(data)                          (0x00000400&((data)<<10))
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_2_9(data)                          (0x00000200&((data)<<9))
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_2_8(data)                          (0x00000100&((data)<<8))
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_2_7(data)                          (0x00000080&((data)<<7))
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_2_6(data)                          (0x00000040&((data)<<6))
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_2_5(data)                          (0x00000020&((data)<<5))
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_2_4(data)                          (0x00000010&((data)<<4))
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_2_3(data)                          (0x00000008&((data)<<3))
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_2_2(data)                          (0x00000004&((data)<<2))
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_2_1(data)                          (0x00000002&((data)<<1))
#define  SENSIO_SENSIO_MBIST_FAIL_1_bist_fail_2_0(data)                          (0x00000001&(data))
#define  SENSIO_SENSIO_MBIST_FAIL_1_get_bist_fail_3_9(data)                      ((0x00080000&(data))>>19)
#define  SENSIO_SENSIO_MBIST_FAIL_1_get_bist_fail_3_8(data)                      ((0x00040000&(data))>>18)
#define  SENSIO_SENSIO_MBIST_FAIL_1_get_bist_fail_3_7(data)                      ((0x00020000&(data))>>17)
#define  SENSIO_SENSIO_MBIST_FAIL_1_get_bist_fail_3_6(data)                      ((0x00010000&(data))>>16)
#define  SENSIO_SENSIO_MBIST_FAIL_1_get_bist_fail_3_5(data)                      ((0x00008000&(data))>>15)
#define  SENSIO_SENSIO_MBIST_FAIL_1_get_bist_fail_3_4(data)                      ((0x00004000&(data))>>14)
#define  SENSIO_SENSIO_MBIST_FAIL_1_get_bist_fail_3_3(data)                      ((0x00002000&(data))>>13)
#define  SENSIO_SENSIO_MBIST_FAIL_1_get_bist_fail_3_2(data)                      ((0x00001000&(data))>>12)
#define  SENSIO_SENSIO_MBIST_FAIL_1_get_bist_fail_3_1(data)                      ((0x00000800&(data))>>11)
#define  SENSIO_SENSIO_MBIST_FAIL_1_get_bist_fail_3_0(data)                      ((0x00000400&(data))>>10)
#define  SENSIO_SENSIO_MBIST_FAIL_1_get_bist_fail_2_9(data)                      ((0x00000200&(data))>>9)
#define  SENSIO_SENSIO_MBIST_FAIL_1_get_bist_fail_2_8(data)                      ((0x00000100&(data))>>8)
#define  SENSIO_SENSIO_MBIST_FAIL_1_get_bist_fail_2_7(data)                      ((0x00000080&(data))>>7)
#define  SENSIO_SENSIO_MBIST_FAIL_1_get_bist_fail_2_6(data)                      ((0x00000040&(data))>>6)
#define  SENSIO_SENSIO_MBIST_FAIL_1_get_bist_fail_2_5(data)                      ((0x00000020&(data))>>5)
#define  SENSIO_SENSIO_MBIST_FAIL_1_get_bist_fail_2_4(data)                      ((0x00000010&(data))>>4)
#define  SENSIO_SENSIO_MBIST_FAIL_1_get_bist_fail_2_3(data)                      ((0x00000008&(data))>>3)
#define  SENSIO_SENSIO_MBIST_FAIL_1_get_bist_fail_2_2(data)                      ((0x00000004&(data))>>2)
#define  SENSIO_SENSIO_MBIST_FAIL_1_get_bist_fail_2_1(data)                      ((0x00000002&(data))>>1)
#define  SENSIO_SENSIO_MBIST_FAIL_1_get_bist_fail_2_0(data)                      (0x00000001&(data))

#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0                                          0x1806B998
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_reg_addr                                 "0xB806B998"
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_reg                                      0xB806B998
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_inst_addr                                "0x000E"
#define  set_SENSIO_SENSIO_MBIST_FAIL_SUB_0_reg(data)                            (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_FAIL_SUB_0_reg)=data)
#define  get_SENSIO_SENSIO_MBIST_FAIL_SUB_0_reg                                  (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_FAIL_SUB_0_reg))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_1_9_shift                  (19)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_1_8_shift                  (18)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_1_7_shift                  (17)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_1_6_shift                  (16)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_1_5_shift                  (15)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_1_4_shift                  (14)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_1_3_shift                  (13)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_1_2_shift                  (12)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_1_1_shift                  (11)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_1_0_shift                  (10)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_0_9_shift                  (9)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_0_8_shift                  (8)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_0_7_shift                  (7)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_0_6_shift                  (6)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_0_5_shift                  (5)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_0_4_shift                  (4)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_0_3_shift                  (3)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_0_2_shift                  (2)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_0_1_shift                  (1)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_0_0_shift                  (0)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_1_9_mask                   (0x00080000)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_1_8_mask                   (0x00040000)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_1_7_mask                   (0x00020000)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_1_6_mask                   (0x00010000)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_1_5_mask                   (0x00008000)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_1_4_mask                   (0x00004000)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_1_3_mask                   (0x00002000)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_1_2_mask                   (0x00001000)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_1_1_mask                   (0x00000800)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_1_0_mask                   (0x00000400)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_0_9_mask                   (0x00000200)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_0_8_mask                   (0x00000100)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_0_7_mask                   (0x00000080)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_0_6_mask                   (0x00000040)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_0_5_mask                   (0x00000020)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_0_4_mask                   (0x00000010)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_0_3_mask                   (0x00000008)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_0_2_mask                   (0x00000004)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_0_1_mask                   (0x00000002)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_0_0_mask                   (0x00000001)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_1_9(data)                  (0x00080000&((data)<<19))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_1_8(data)                  (0x00040000&((data)<<18))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_1_7(data)                  (0x00020000&((data)<<17))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_1_6(data)                  (0x00010000&((data)<<16))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_1_5(data)                  (0x00008000&((data)<<15))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_1_4(data)                  (0x00004000&((data)<<14))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_1_3(data)                  (0x00002000&((data)<<13))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_1_2(data)                  (0x00001000&((data)<<12))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_1_1(data)                  (0x00000800&((data)<<11))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_1_0(data)                  (0x00000400&((data)<<10))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_0_9(data)                  (0x00000200&((data)<<9))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_0_8(data)                  (0x00000100&((data)<<8))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_0_7(data)                  (0x00000080&((data)<<7))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_0_6(data)                  (0x00000040&((data)<<6))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_0_5(data)                  (0x00000020&((data)<<5))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_0_4(data)                  (0x00000010&((data)<<4))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_0_3(data)                  (0x00000008&((data)<<3))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_0_2(data)                  (0x00000004&((data)<<2))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_0_1(data)                  (0x00000002&((data)<<1))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_bist_fail_sub_0_0(data)                  (0x00000001&(data))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_get_bist_fail_sub_1_9(data)              ((0x00080000&(data))>>19)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_get_bist_fail_sub_1_8(data)              ((0x00040000&(data))>>18)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_get_bist_fail_sub_1_7(data)              ((0x00020000&(data))>>17)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_get_bist_fail_sub_1_6(data)              ((0x00010000&(data))>>16)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_get_bist_fail_sub_1_5(data)              ((0x00008000&(data))>>15)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_get_bist_fail_sub_1_4(data)              ((0x00004000&(data))>>14)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_get_bist_fail_sub_1_3(data)              ((0x00002000&(data))>>13)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_get_bist_fail_sub_1_2(data)              ((0x00001000&(data))>>12)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_get_bist_fail_sub_1_1(data)              ((0x00000800&(data))>>11)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_get_bist_fail_sub_1_0(data)              ((0x00000400&(data))>>10)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_get_bist_fail_sub_0_9(data)              ((0x00000200&(data))>>9)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_get_bist_fail_sub_0_8(data)              ((0x00000100&(data))>>8)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_get_bist_fail_sub_0_7(data)              ((0x00000080&(data))>>7)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_get_bist_fail_sub_0_6(data)              ((0x00000040&(data))>>6)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_get_bist_fail_sub_0_5(data)              ((0x00000020&(data))>>5)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_get_bist_fail_sub_0_4(data)              ((0x00000010&(data))>>4)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_get_bist_fail_sub_0_3(data)              ((0x00000008&(data))>>3)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_get_bist_fail_sub_0_2(data)              ((0x00000004&(data))>>2)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_get_bist_fail_sub_0_1(data)              ((0x00000002&(data))>>1)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_0_get_bist_fail_sub_0_0(data)              (0x00000001&(data))

#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1                                          0x1806B99C
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_reg_addr                                 "0xB806B99C"
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_reg                                      0xB806B99C
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_inst_addr                                "0x000F"
#define  set_SENSIO_SENSIO_MBIST_FAIL_SUB_1_reg(data)                            (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_FAIL_SUB_1_reg)=data)
#define  get_SENSIO_SENSIO_MBIST_FAIL_SUB_1_reg                                  (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_FAIL_SUB_1_reg))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_3_9_shift                  (19)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_3_8_shift                  (18)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_3_7_shift                  (17)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_3_6_shift                  (16)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_3_5_shift                  (15)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_3_4_shift                  (14)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_3_3_shift                  (13)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_3_2_shift                  (12)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_3_1_shift                  (11)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_3_0_shift                  (10)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_2_9_shift                  (9)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_2_8_shift                  (8)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_2_7_shift                  (7)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_2_6_shift                  (6)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_2_5_shift                  (5)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_2_4_shift                  (4)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_2_3_shift                  (3)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_2_2_shift                  (2)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_2_1_shift                  (1)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_2_0_shift                  (0)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_3_9_mask                   (0x00080000)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_3_8_mask                   (0x00040000)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_3_7_mask                   (0x00020000)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_3_6_mask                   (0x00010000)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_3_5_mask                   (0x00008000)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_3_4_mask                   (0x00004000)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_3_3_mask                   (0x00002000)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_3_2_mask                   (0x00001000)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_3_1_mask                   (0x00000800)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_3_0_mask                   (0x00000400)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_2_9_mask                   (0x00000200)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_2_8_mask                   (0x00000100)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_2_7_mask                   (0x00000080)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_2_6_mask                   (0x00000040)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_2_5_mask                   (0x00000020)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_2_4_mask                   (0x00000010)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_2_3_mask                   (0x00000008)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_2_2_mask                   (0x00000004)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_2_1_mask                   (0x00000002)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_2_0_mask                   (0x00000001)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_3_9(data)                  (0x00080000&((data)<<19))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_3_8(data)                  (0x00040000&((data)<<18))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_3_7(data)                  (0x00020000&((data)<<17))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_3_6(data)                  (0x00010000&((data)<<16))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_3_5(data)                  (0x00008000&((data)<<15))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_3_4(data)                  (0x00004000&((data)<<14))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_3_3(data)                  (0x00002000&((data)<<13))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_3_2(data)                  (0x00001000&((data)<<12))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_3_1(data)                  (0x00000800&((data)<<11))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_3_0(data)                  (0x00000400&((data)<<10))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_2_9(data)                  (0x00000200&((data)<<9))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_2_8(data)                  (0x00000100&((data)<<8))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_2_7(data)                  (0x00000080&((data)<<7))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_2_6(data)                  (0x00000040&((data)<<6))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_2_5(data)                  (0x00000020&((data)<<5))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_2_4(data)                  (0x00000010&((data)<<4))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_2_3(data)                  (0x00000008&((data)<<3))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_2_2(data)                  (0x00000004&((data)<<2))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_2_1(data)                  (0x00000002&((data)<<1))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_bist_fail_sub_2_0(data)                  (0x00000001&(data))
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_get_bist_fail_sub_3_9(data)              ((0x00080000&(data))>>19)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_get_bist_fail_sub_3_8(data)              ((0x00040000&(data))>>18)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_get_bist_fail_sub_3_7(data)              ((0x00020000&(data))>>17)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_get_bist_fail_sub_3_6(data)              ((0x00010000&(data))>>16)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_get_bist_fail_sub_3_5(data)              ((0x00008000&(data))>>15)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_get_bist_fail_sub_3_4(data)              ((0x00004000&(data))>>14)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_get_bist_fail_sub_3_3(data)              ((0x00002000&(data))>>13)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_get_bist_fail_sub_3_2(data)              ((0x00001000&(data))>>12)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_get_bist_fail_sub_3_1(data)              ((0x00000800&(data))>>11)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_get_bist_fail_sub_3_0(data)              ((0x00000400&(data))>>10)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_get_bist_fail_sub_2_9(data)              ((0x00000200&(data))>>9)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_get_bist_fail_sub_2_8(data)              ((0x00000100&(data))>>8)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_get_bist_fail_sub_2_7(data)              ((0x00000080&(data))>>7)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_get_bist_fail_sub_2_6(data)              ((0x00000040&(data))>>6)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_get_bist_fail_sub_2_5(data)              ((0x00000020&(data))>>5)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_get_bist_fail_sub_2_4(data)              ((0x00000010&(data))>>4)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_get_bist_fail_sub_2_3(data)              ((0x00000008&(data))>>3)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_get_bist_fail_sub_2_2(data)              ((0x00000004&(data))>>2)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_get_bist_fail_sub_2_1(data)              ((0x00000002&(data))>>1)
#define  SENSIO_SENSIO_MBIST_FAIL_SUB_1_get_bist_fail_sub_2_0(data)              (0x00000001&(data))

#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0                                          0x1806B9A0
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_reg_addr                                 "0xB806B9A0"
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_reg                                      0xB806B9A0
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_inst_addr                                "0x0010"
#define  set_SENSIO_SENSIO_MBIST_DRF_FAIL_0_reg(data)                            (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_DRF_FAIL_0_reg)=data)
#define  get_SENSIO_SENSIO_MBIST_DRF_FAIL_0_reg                                  (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_DRF_FAIL_0_reg))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_1_9_shift                  (19)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_1_8_shift                  (18)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_1_7_shift                  (17)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_1_6_shift                  (16)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_1_5_shift                  (15)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_1_4_shift                  (14)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_1_3_shift                  (13)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_1_2_shift                  (12)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_1_1_shift                  (11)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_1_0_shift                  (10)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_0_9_shift                  (9)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_0_8_shift                  (8)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_0_7_shift                  (7)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_0_6_shift                  (6)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_0_5_shift                  (5)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_0_4_shift                  (4)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_0_3_shift                  (3)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_0_2_shift                  (2)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_0_1_shift                  (1)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_0_0_shift                  (0)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_1_9_mask                   (0x00080000)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_1_8_mask                   (0x00040000)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_1_7_mask                   (0x00020000)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_1_6_mask                   (0x00010000)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_1_5_mask                   (0x00008000)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_1_4_mask                   (0x00004000)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_1_3_mask                   (0x00002000)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_1_2_mask                   (0x00001000)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_1_1_mask                   (0x00000800)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_1_0_mask                   (0x00000400)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_0_9_mask                   (0x00000200)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_0_8_mask                   (0x00000100)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_0_7_mask                   (0x00000080)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_0_6_mask                   (0x00000040)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_0_5_mask                   (0x00000020)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_0_4_mask                   (0x00000010)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_0_3_mask                   (0x00000008)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_0_2_mask                   (0x00000004)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_0_1_mask                   (0x00000002)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_0_0_mask                   (0x00000001)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_1_9(data)                  (0x00080000&((data)<<19))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_1_8(data)                  (0x00040000&((data)<<18))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_1_7(data)                  (0x00020000&((data)<<17))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_1_6(data)                  (0x00010000&((data)<<16))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_1_5(data)                  (0x00008000&((data)<<15))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_1_4(data)                  (0x00004000&((data)<<14))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_1_3(data)                  (0x00002000&((data)<<13))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_1_2(data)                  (0x00001000&((data)<<12))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_1_1(data)                  (0x00000800&((data)<<11))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_1_0(data)                  (0x00000400&((data)<<10))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_0_9(data)                  (0x00000200&((data)<<9))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_0_8(data)                  (0x00000100&((data)<<8))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_0_7(data)                  (0x00000080&((data)<<7))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_0_6(data)                  (0x00000040&((data)<<6))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_0_5(data)                  (0x00000020&((data)<<5))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_0_4(data)                  (0x00000010&((data)<<4))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_0_3(data)                  (0x00000008&((data)<<3))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_0_2(data)                  (0x00000004&((data)<<2))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_0_1(data)                  (0x00000002&((data)<<1))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_drf_bist_fail_0_0(data)                  (0x00000001&(data))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_get_drf_bist_fail_1_9(data)              ((0x00080000&(data))>>19)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_get_drf_bist_fail_1_8(data)              ((0x00040000&(data))>>18)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_get_drf_bist_fail_1_7(data)              ((0x00020000&(data))>>17)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_get_drf_bist_fail_1_6(data)              ((0x00010000&(data))>>16)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_get_drf_bist_fail_1_5(data)              ((0x00008000&(data))>>15)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_get_drf_bist_fail_1_4(data)              ((0x00004000&(data))>>14)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_get_drf_bist_fail_1_3(data)              ((0x00002000&(data))>>13)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_get_drf_bist_fail_1_2(data)              ((0x00001000&(data))>>12)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_get_drf_bist_fail_1_1(data)              ((0x00000800&(data))>>11)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_get_drf_bist_fail_1_0(data)              ((0x00000400&(data))>>10)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_get_drf_bist_fail_0_9(data)              ((0x00000200&(data))>>9)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_get_drf_bist_fail_0_8(data)              ((0x00000100&(data))>>8)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_get_drf_bist_fail_0_7(data)              ((0x00000080&(data))>>7)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_get_drf_bist_fail_0_6(data)              ((0x00000040&(data))>>6)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_get_drf_bist_fail_0_5(data)              ((0x00000020&(data))>>5)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_get_drf_bist_fail_0_4(data)              ((0x00000010&(data))>>4)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_get_drf_bist_fail_0_3(data)              ((0x00000008&(data))>>3)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_get_drf_bist_fail_0_2(data)              ((0x00000004&(data))>>2)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_get_drf_bist_fail_0_1(data)              ((0x00000002&(data))>>1)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_0_get_drf_bist_fail_0_0(data)              (0x00000001&(data))

#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1                                          0x1806B9A4
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_reg_addr                                 "0xB806B9A4"
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_reg                                      0xB806B9A4
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_inst_addr                                "0x0011"
#define  set_SENSIO_SENSIO_MBIST_DRF_FAIL_1_reg(data)                            (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_DRF_FAIL_1_reg)=data)
#define  get_SENSIO_SENSIO_MBIST_DRF_FAIL_1_reg                                  (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_DRF_FAIL_1_reg))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_3_9_shift                  (19)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_3_8_shift                  (18)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_3_7_shift                  (17)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_3_6_shift                  (16)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_3_5_shift                  (15)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_3_4_shift                  (14)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_3_3_shift                  (13)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_3_2_shift                  (12)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_3_1_shift                  (11)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_3_0_shift                  (10)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_2_9_shift                  (9)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_2_8_shift                  (8)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_2_7_shift                  (7)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_2_6_shift                  (6)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_2_5_shift                  (5)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_2_4_shift                  (4)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_2_3_shift                  (3)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_2_2_shift                  (2)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_2_1_shift                  (1)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_2_0_shift                  (0)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_3_9_mask                   (0x00080000)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_3_8_mask                   (0x00040000)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_3_7_mask                   (0x00020000)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_3_6_mask                   (0x00010000)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_3_5_mask                   (0x00008000)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_3_4_mask                   (0x00004000)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_3_3_mask                   (0x00002000)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_3_2_mask                   (0x00001000)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_3_1_mask                   (0x00000800)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_3_0_mask                   (0x00000400)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_2_9_mask                   (0x00000200)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_2_8_mask                   (0x00000100)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_2_7_mask                   (0x00000080)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_2_6_mask                   (0x00000040)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_2_5_mask                   (0x00000020)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_2_4_mask                   (0x00000010)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_2_3_mask                   (0x00000008)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_2_2_mask                   (0x00000004)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_2_1_mask                   (0x00000002)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_2_0_mask                   (0x00000001)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_3_9(data)                  (0x00080000&((data)<<19))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_3_8(data)                  (0x00040000&((data)<<18))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_3_7(data)                  (0x00020000&((data)<<17))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_3_6(data)                  (0x00010000&((data)<<16))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_3_5(data)                  (0x00008000&((data)<<15))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_3_4(data)                  (0x00004000&((data)<<14))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_3_3(data)                  (0x00002000&((data)<<13))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_3_2(data)                  (0x00001000&((data)<<12))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_3_1(data)                  (0x00000800&((data)<<11))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_3_0(data)                  (0x00000400&((data)<<10))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_2_9(data)                  (0x00000200&((data)<<9))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_2_8(data)                  (0x00000100&((data)<<8))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_2_7(data)                  (0x00000080&((data)<<7))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_2_6(data)                  (0x00000040&((data)<<6))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_2_5(data)                  (0x00000020&((data)<<5))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_2_4(data)                  (0x00000010&((data)<<4))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_2_3(data)                  (0x00000008&((data)<<3))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_2_2(data)                  (0x00000004&((data)<<2))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_2_1(data)                  (0x00000002&((data)<<1))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_drf_bist_fail_2_0(data)                  (0x00000001&(data))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_get_drf_bist_fail_3_9(data)              ((0x00080000&(data))>>19)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_get_drf_bist_fail_3_8(data)              ((0x00040000&(data))>>18)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_get_drf_bist_fail_3_7(data)              ((0x00020000&(data))>>17)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_get_drf_bist_fail_3_6(data)              ((0x00010000&(data))>>16)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_get_drf_bist_fail_3_5(data)              ((0x00008000&(data))>>15)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_get_drf_bist_fail_3_4(data)              ((0x00004000&(data))>>14)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_get_drf_bist_fail_3_3(data)              ((0x00002000&(data))>>13)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_get_drf_bist_fail_3_2(data)              ((0x00001000&(data))>>12)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_get_drf_bist_fail_3_1(data)              ((0x00000800&(data))>>11)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_get_drf_bist_fail_3_0(data)              ((0x00000400&(data))>>10)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_get_drf_bist_fail_2_9(data)              ((0x00000200&(data))>>9)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_get_drf_bist_fail_2_8(data)              ((0x00000100&(data))>>8)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_get_drf_bist_fail_2_7(data)              ((0x00000080&(data))>>7)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_get_drf_bist_fail_2_6(data)              ((0x00000040&(data))>>6)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_get_drf_bist_fail_2_5(data)              ((0x00000020&(data))>>5)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_get_drf_bist_fail_2_4(data)              ((0x00000010&(data))>>4)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_get_drf_bist_fail_2_3(data)              ((0x00000008&(data))>>3)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_get_drf_bist_fail_2_2(data)              ((0x00000004&(data))>>2)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_get_drf_bist_fail_2_1(data)              ((0x00000002&(data))>>1)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_1_get_drf_bist_fail_2_0(data)              (0x00000001&(data))

#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0                                      0x1806B9A8
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_reg_addr                             "0xB806B9A8"
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_reg                                  0xB806B9A8
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_inst_addr                            "0x0012"
#define  set_SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_reg(data)                        (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_reg)=data)
#define  get_SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_reg                              (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_reg))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_1_9_shift          (19)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_1_8_shift          (18)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_1_7_shift          (17)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_1_6_shift          (16)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_1_5_shift          (15)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_1_4_shift          (14)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_1_3_shift          (13)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_1_2_shift          (12)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_1_1_shift          (11)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_1_0_shift          (10)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_0_9_shift          (9)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_0_8_shift          (8)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_0_7_shift          (7)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_0_6_shift          (6)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_0_5_shift          (5)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_0_4_shift          (4)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_0_3_shift          (3)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_0_2_shift          (2)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_0_1_shift          (1)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_0_0_shift          (0)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_1_9_mask           (0x00080000)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_1_8_mask           (0x00040000)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_1_7_mask           (0x00020000)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_1_6_mask           (0x00010000)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_1_5_mask           (0x00008000)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_1_4_mask           (0x00004000)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_1_3_mask           (0x00002000)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_1_2_mask           (0x00001000)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_1_1_mask           (0x00000800)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_1_0_mask           (0x00000400)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_0_9_mask           (0x00000200)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_0_8_mask           (0x00000100)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_0_7_mask           (0x00000080)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_0_6_mask           (0x00000040)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_0_5_mask           (0x00000020)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_0_4_mask           (0x00000010)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_0_3_mask           (0x00000008)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_0_2_mask           (0x00000004)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_0_1_mask           (0x00000002)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_0_0_mask           (0x00000001)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_1_9(data)          (0x00080000&((data)<<19))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_1_8(data)          (0x00040000&((data)<<18))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_1_7(data)          (0x00020000&((data)<<17))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_1_6(data)          (0x00010000&((data)<<16))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_1_5(data)          (0x00008000&((data)<<15))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_1_4(data)          (0x00004000&((data)<<14))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_1_3(data)          (0x00002000&((data)<<13))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_1_2(data)          (0x00001000&((data)<<12))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_1_1(data)          (0x00000800&((data)<<11))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_1_0(data)          (0x00000400&((data)<<10))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_0_9(data)          (0x00000200&((data)<<9))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_0_8(data)          (0x00000100&((data)<<8))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_0_7(data)          (0x00000080&((data)<<7))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_0_6(data)          (0x00000040&((data)<<6))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_0_5(data)          (0x00000020&((data)<<5))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_0_4(data)          (0x00000010&((data)<<4))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_0_3(data)          (0x00000008&((data)<<3))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_0_2(data)          (0x00000004&((data)<<2))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_0_1(data)          (0x00000002&((data)<<1))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_drf_bist_fail_sub_0_0(data)          (0x00000001&(data))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_get_drf_bist_fail_sub_1_9(data)      ((0x00080000&(data))>>19)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_get_drf_bist_fail_sub_1_8(data)      ((0x00040000&(data))>>18)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_get_drf_bist_fail_sub_1_7(data)      ((0x00020000&(data))>>17)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_get_drf_bist_fail_sub_1_6(data)      ((0x00010000&(data))>>16)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_get_drf_bist_fail_sub_1_5(data)      ((0x00008000&(data))>>15)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_get_drf_bist_fail_sub_1_4(data)      ((0x00004000&(data))>>14)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_get_drf_bist_fail_sub_1_3(data)      ((0x00002000&(data))>>13)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_get_drf_bist_fail_sub_1_2(data)      ((0x00001000&(data))>>12)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_get_drf_bist_fail_sub_1_1(data)      ((0x00000800&(data))>>11)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_get_drf_bist_fail_sub_1_0(data)      ((0x00000400&(data))>>10)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_get_drf_bist_fail_sub_0_9(data)      ((0x00000200&(data))>>9)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_get_drf_bist_fail_sub_0_8(data)      ((0x00000100&(data))>>8)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_get_drf_bist_fail_sub_0_7(data)      ((0x00000080&(data))>>7)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_get_drf_bist_fail_sub_0_6(data)      ((0x00000040&(data))>>6)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_get_drf_bist_fail_sub_0_5(data)      ((0x00000020&(data))>>5)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_get_drf_bist_fail_sub_0_4(data)      ((0x00000010&(data))>>4)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_get_drf_bist_fail_sub_0_3(data)      ((0x00000008&(data))>>3)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_get_drf_bist_fail_sub_0_2(data)      ((0x00000004&(data))>>2)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_get_drf_bist_fail_sub_0_1(data)      ((0x00000002&(data))>>1)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_0_get_drf_bist_fail_sub_0_0(data)      (0x00000001&(data))

#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1                                      0x1806B9AC
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_reg_addr                             "0xB806B9AC"
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_reg                                  0xB806B9AC
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_inst_addr                            "0x0013"
#define  set_SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_reg(data)                        (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_reg)=data)
#define  get_SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_reg                              (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_reg))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_3_9_shift          (19)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_3_8_shift          (18)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_3_7_shift          (17)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_3_6_shift          (16)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_3_5_shift          (15)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_3_4_shift          (14)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_3_3_shift          (13)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_3_2_shift          (12)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_3_1_shift          (11)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_3_0_shift          (10)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_2_9_shift          (9)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_2_8_shift          (8)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_2_7_shift          (7)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_2_6_shift          (6)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_2_5_shift          (5)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_2_4_shift          (4)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_2_3_shift          (3)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_2_2_shift          (2)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_2_1_shift          (1)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_2_0_shift          (0)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_3_9_mask           (0x00080000)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_3_8_mask           (0x00040000)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_3_7_mask           (0x00020000)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_3_6_mask           (0x00010000)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_3_5_mask           (0x00008000)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_3_4_mask           (0x00004000)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_3_3_mask           (0x00002000)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_3_2_mask           (0x00001000)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_3_1_mask           (0x00000800)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_3_0_mask           (0x00000400)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_2_9_mask           (0x00000200)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_2_8_mask           (0x00000100)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_2_7_mask           (0x00000080)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_2_6_mask           (0x00000040)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_2_5_mask           (0x00000020)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_2_4_mask           (0x00000010)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_2_3_mask           (0x00000008)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_2_2_mask           (0x00000004)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_2_1_mask           (0x00000002)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_2_0_mask           (0x00000001)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_3_9(data)          (0x00080000&((data)<<19))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_3_8(data)          (0x00040000&((data)<<18))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_3_7(data)          (0x00020000&((data)<<17))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_3_6(data)          (0x00010000&((data)<<16))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_3_5(data)          (0x00008000&((data)<<15))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_3_4(data)          (0x00004000&((data)<<14))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_3_3(data)          (0x00002000&((data)<<13))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_3_2(data)          (0x00001000&((data)<<12))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_3_1(data)          (0x00000800&((data)<<11))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_3_0(data)          (0x00000400&((data)<<10))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_2_9(data)          (0x00000200&((data)<<9))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_2_8(data)          (0x00000100&((data)<<8))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_2_7(data)          (0x00000080&((data)<<7))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_2_6(data)          (0x00000040&((data)<<6))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_2_5(data)          (0x00000020&((data)<<5))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_2_4(data)          (0x00000010&((data)<<4))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_2_3(data)          (0x00000008&((data)<<3))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_2_2(data)          (0x00000004&((data)<<2))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_2_1(data)          (0x00000002&((data)<<1))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_drf_bist_fail_sub_2_0(data)          (0x00000001&(data))
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_get_drf_bist_fail_sub_3_9(data)      ((0x00080000&(data))>>19)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_get_drf_bist_fail_sub_3_8(data)      ((0x00040000&(data))>>18)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_get_drf_bist_fail_sub_3_7(data)      ((0x00020000&(data))>>17)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_get_drf_bist_fail_sub_3_6(data)      ((0x00010000&(data))>>16)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_get_drf_bist_fail_sub_3_5(data)      ((0x00008000&(data))>>15)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_get_drf_bist_fail_sub_3_4(data)      ((0x00004000&(data))>>14)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_get_drf_bist_fail_sub_3_3(data)      ((0x00002000&(data))>>13)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_get_drf_bist_fail_sub_3_2(data)      ((0x00001000&(data))>>12)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_get_drf_bist_fail_sub_3_1(data)      ((0x00000800&(data))>>11)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_get_drf_bist_fail_sub_3_0(data)      ((0x00000400&(data))>>10)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_get_drf_bist_fail_sub_2_9(data)      ((0x00000200&(data))>>9)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_get_drf_bist_fail_sub_2_8(data)      ((0x00000100&(data))>>8)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_get_drf_bist_fail_sub_2_7(data)      ((0x00000080&(data))>>7)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_get_drf_bist_fail_sub_2_6(data)      ((0x00000040&(data))>>6)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_get_drf_bist_fail_sub_2_5(data)      ((0x00000020&(data))>>5)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_get_drf_bist_fail_sub_2_4(data)      ((0x00000010&(data))>>4)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_get_drf_bist_fail_sub_2_3(data)      ((0x00000008&(data))>>3)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_get_drf_bist_fail_sub_2_2(data)      ((0x00000004&(data))>>2)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_get_drf_bist_fail_sub_2_1(data)      ((0x00000002&(data))>>1)
#define  SENSIO_SENSIO_MBIST_DRF_FAIL_SUB_1_get_drf_bist_fail_sub_2_0(data)      (0x00000001&(data))

#define  SENSIO_SENSIO_MBIST_LS_0                                                0x1806B9B0
#define  SENSIO_SENSIO_MBIST_LS_0_reg_addr                                       "0xB806B9B0"
#define  SENSIO_SENSIO_MBIST_LS_0_reg                                            0xB806B9B0
#define  SENSIO_SENSIO_MBIST_LS_0_inst_addr                                      "0x0014"
#define  set_SENSIO_SENSIO_MBIST_LS_0_reg(data)                                  (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_LS_0_reg)=data)
#define  get_SENSIO_SENSIO_MBIST_LS_0_reg                                        (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_LS_0_reg))
#define  SENSIO_SENSIO_MBIST_LS_0_ls_1_9_shift                                   (19)
#define  SENSIO_SENSIO_MBIST_LS_0_ls_1_8_shift                                   (18)
#define  SENSIO_SENSIO_MBIST_LS_0_ls_1_7_shift                                   (17)
#define  SENSIO_SENSIO_MBIST_LS_0_ls_1_6_shift                                   (16)
#define  SENSIO_SENSIO_MBIST_LS_0_ls_1_5_shift                                   (15)
#define  SENSIO_SENSIO_MBIST_LS_0_ls_1_4_shift                                   (14)
#define  SENSIO_SENSIO_MBIST_LS_0_ls_1_3_shift                                   (13)
#define  SENSIO_SENSIO_MBIST_LS_0_ls_1_2_shift                                   (12)
#define  SENSIO_SENSIO_MBIST_LS_0_ls_1_1_shift                                   (11)
#define  SENSIO_SENSIO_MBIST_LS_0_ls_1_0_shift                                   (10)
#define  SENSIO_SENSIO_MBIST_LS_0_ls_0_9_shift                                   (9)
#define  SENSIO_SENSIO_MBIST_LS_0_ls_0_8_shift                                   (8)
#define  SENSIO_SENSIO_MBIST_LS_0_ls_0_7_shift                                   (7)
#define  SENSIO_SENSIO_MBIST_LS_0_ls_0_6_shift                                   (6)
#define  SENSIO_SENSIO_MBIST_LS_0_ls_0_5_shift                                   (5)
#define  SENSIO_SENSIO_MBIST_LS_0_ls_0_4_shift                                   (4)
#define  SENSIO_SENSIO_MBIST_LS_0_ls_0_3_shift                                   (3)
#define  SENSIO_SENSIO_MBIST_LS_0_ls_0_2_shift                                   (2)
#define  SENSIO_SENSIO_MBIST_LS_0_ls_0_1_shift                                   (1)
#define  SENSIO_SENSIO_MBIST_LS_0_ls_0_0_shift                                   (0)
#define  SENSIO_SENSIO_MBIST_LS_0_ls_1_9_mask                                    (0x00080000)
#define  SENSIO_SENSIO_MBIST_LS_0_ls_1_8_mask                                    (0x00040000)
#define  SENSIO_SENSIO_MBIST_LS_0_ls_1_7_mask                                    (0x00020000)
#define  SENSIO_SENSIO_MBIST_LS_0_ls_1_6_mask                                    (0x00010000)
#define  SENSIO_SENSIO_MBIST_LS_0_ls_1_5_mask                                    (0x00008000)
#define  SENSIO_SENSIO_MBIST_LS_0_ls_1_4_mask                                    (0x00004000)
#define  SENSIO_SENSIO_MBIST_LS_0_ls_1_3_mask                                    (0x00002000)
#define  SENSIO_SENSIO_MBIST_LS_0_ls_1_2_mask                                    (0x00001000)
#define  SENSIO_SENSIO_MBIST_LS_0_ls_1_1_mask                                    (0x00000800)
#define  SENSIO_SENSIO_MBIST_LS_0_ls_1_0_mask                                    (0x00000400)
#define  SENSIO_SENSIO_MBIST_LS_0_ls_0_9_mask                                    (0x00000200)
#define  SENSIO_SENSIO_MBIST_LS_0_ls_0_8_mask                                    (0x00000100)
#define  SENSIO_SENSIO_MBIST_LS_0_ls_0_7_mask                                    (0x00000080)
#define  SENSIO_SENSIO_MBIST_LS_0_ls_0_6_mask                                    (0x00000040)
#define  SENSIO_SENSIO_MBIST_LS_0_ls_0_5_mask                                    (0x00000020)
#define  SENSIO_SENSIO_MBIST_LS_0_ls_0_4_mask                                    (0x00000010)
#define  SENSIO_SENSIO_MBIST_LS_0_ls_0_3_mask                                    (0x00000008)
#define  SENSIO_SENSIO_MBIST_LS_0_ls_0_2_mask                                    (0x00000004)
#define  SENSIO_SENSIO_MBIST_LS_0_ls_0_1_mask                                    (0x00000002)
#define  SENSIO_SENSIO_MBIST_LS_0_ls_0_0_mask                                    (0x00000001)
#define  SENSIO_SENSIO_MBIST_LS_0_ls_1_9(data)                                   (0x00080000&((data)<<19))
#define  SENSIO_SENSIO_MBIST_LS_0_ls_1_8(data)                                   (0x00040000&((data)<<18))
#define  SENSIO_SENSIO_MBIST_LS_0_ls_1_7(data)                                   (0x00020000&((data)<<17))
#define  SENSIO_SENSIO_MBIST_LS_0_ls_1_6(data)                                   (0x00010000&((data)<<16))
#define  SENSIO_SENSIO_MBIST_LS_0_ls_1_5(data)                                   (0x00008000&((data)<<15))
#define  SENSIO_SENSIO_MBIST_LS_0_ls_1_4(data)                                   (0x00004000&((data)<<14))
#define  SENSIO_SENSIO_MBIST_LS_0_ls_1_3(data)                                   (0x00002000&((data)<<13))
#define  SENSIO_SENSIO_MBIST_LS_0_ls_1_2(data)                                   (0x00001000&((data)<<12))
#define  SENSIO_SENSIO_MBIST_LS_0_ls_1_1(data)                                   (0x00000800&((data)<<11))
#define  SENSIO_SENSIO_MBIST_LS_0_ls_1_0(data)                                   (0x00000400&((data)<<10))
#define  SENSIO_SENSIO_MBIST_LS_0_ls_0_9(data)                                   (0x00000200&((data)<<9))
#define  SENSIO_SENSIO_MBIST_LS_0_ls_0_8(data)                                   (0x00000100&((data)<<8))
#define  SENSIO_SENSIO_MBIST_LS_0_ls_0_7(data)                                   (0x00000080&((data)<<7))
#define  SENSIO_SENSIO_MBIST_LS_0_ls_0_6(data)                                   (0x00000040&((data)<<6))
#define  SENSIO_SENSIO_MBIST_LS_0_ls_0_5(data)                                   (0x00000020&((data)<<5))
#define  SENSIO_SENSIO_MBIST_LS_0_ls_0_4(data)                                   (0x00000010&((data)<<4))
#define  SENSIO_SENSIO_MBIST_LS_0_ls_0_3(data)                                   (0x00000008&((data)<<3))
#define  SENSIO_SENSIO_MBIST_LS_0_ls_0_2(data)                                   (0x00000004&((data)<<2))
#define  SENSIO_SENSIO_MBIST_LS_0_ls_0_1(data)                                   (0x00000002&((data)<<1))
#define  SENSIO_SENSIO_MBIST_LS_0_ls_0_0(data)                                   (0x00000001&(data))
#define  SENSIO_SENSIO_MBIST_LS_0_get_ls_1_9(data)                               ((0x00080000&(data))>>19)
#define  SENSIO_SENSIO_MBIST_LS_0_get_ls_1_8(data)                               ((0x00040000&(data))>>18)
#define  SENSIO_SENSIO_MBIST_LS_0_get_ls_1_7(data)                               ((0x00020000&(data))>>17)
#define  SENSIO_SENSIO_MBIST_LS_0_get_ls_1_6(data)                               ((0x00010000&(data))>>16)
#define  SENSIO_SENSIO_MBIST_LS_0_get_ls_1_5(data)                               ((0x00008000&(data))>>15)
#define  SENSIO_SENSIO_MBIST_LS_0_get_ls_1_4(data)                               ((0x00004000&(data))>>14)
#define  SENSIO_SENSIO_MBIST_LS_0_get_ls_1_3(data)                               ((0x00002000&(data))>>13)
#define  SENSIO_SENSIO_MBIST_LS_0_get_ls_1_2(data)                               ((0x00001000&(data))>>12)
#define  SENSIO_SENSIO_MBIST_LS_0_get_ls_1_1(data)                               ((0x00000800&(data))>>11)
#define  SENSIO_SENSIO_MBIST_LS_0_get_ls_1_0(data)                               ((0x00000400&(data))>>10)
#define  SENSIO_SENSIO_MBIST_LS_0_get_ls_0_9(data)                               ((0x00000200&(data))>>9)
#define  SENSIO_SENSIO_MBIST_LS_0_get_ls_0_8(data)                               ((0x00000100&(data))>>8)
#define  SENSIO_SENSIO_MBIST_LS_0_get_ls_0_7(data)                               ((0x00000080&(data))>>7)
#define  SENSIO_SENSIO_MBIST_LS_0_get_ls_0_6(data)                               ((0x00000040&(data))>>6)
#define  SENSIO_SENSIO_MBIST_LS_0_get_ls_0_5(data)                               ((0x00000020&(data))>>5)
#define  SENSIO_SENSIO_MBIST_LS_0_get_ls_0_4(data)                               ((0x00000010&(data))>>4)
#define  SENSIO_SENSIO_MBIST_LS_0_get_ls_0_3(data)                               ((0x00000008&(data))>>3)
#define  SENSIO_SENSIO_MBIST_LS_0_get_ls_0_2(data)                               ((0x00000004&(data))>>2)
#define  SENSIO_SENSIO_MBIST_LS_0_get_ls_0_1(data)                               ((0x00000002&(data))>>1)
#define  SENSIO_SENSIO_MBIST_LS_0_get_ls_0_0(data)                               (0x00000001&(data))

#define  SENSIO_SENSIO_MBIST_LS_1                                                0x1806B9B4
#define  SENSIO_SENSIO_MBIST_LS_1_reg_addr                                       "0xB806B9B4"
#define  SENSIO_SENSIO_MBIST_LS_1_reg                                            0xB806B9B4
#define  SENSIO_SENSIO_MBIST_LS_1_inst_addr                                      "0x0015"
#define  set_SENSIO_SENSIO_MBIST_LS_1_reg(data)                                  (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_LS_1_reg)=data)
#define  get_SENSIO_SENSIO_MBIST_LS_1_reg                                        (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_LS_1_reg))
#define  SENSIO_SENSIO_MBIST_LS_1_ls_3_9_shift                                   (19)
#define  SENSIO_SENSIO_MBIST_LS_1_ls_3_8_shift                                   (18)
#define  SENSIO_SENSIO_MBIST_LS_1_ls_3_7_shift                                   (17)
#define  SENSIO_SENSIO_MBIST_LS_1_ls_3_6_shift                                   (16)
#define  SENSIO_SENSIO_MBIST_LS_1_ls_3_5_shift                                   (15)
#define  SENSIO_SENSIO_MBIST_LS_1_ls_3_4_shift                                   (14)
#define  SENSIO_SENSIO_MBIST_LS_1_ls_3_3_shift                                   (13)
#define  SENSIO_SENSIO_MBIST_LS_1_ls_3_2_shift                                   (12)
#define  SENSIO_SENSIO_MBIST_LS_1_ls_3_1_shift                                   (11)
#define  SENSIO_SENSIO_MBIST_LS_1_ls_3_0_shift                                   (10)
#define  SENSIO_SENSIO_MBIST_LS_1_ls_2_9_shift                                   (9)
#define  SENSIO_SENSIO_MBIST_LS_1_ls_2_8_shift                                   (8)
#define  SENSIO_SENSIO_MBIST_LS_1_ls_2_7_shift                                   (7)
#define  SENSIO_SENSIO_MBIST_LS_1_ls_2_6_shift                                   (6)
#define  SENSIO_SENSIO_MBIST_LS_1_ls_2_5_shift                                   (5)
#define  SENSIO_SENSIO_MBIST_LS_1_ls_2_4_shift                                   (4)
#define  SENSIO_SENSIO_MBIST_LS_1_ls_2_3_shift                                   (3)
#define  SENSIO_SENSIO_MBIST_LS_1_ls_2_2_shift                                   (2)
#define  SENSIO_SENSIO_MBIST_LS_1_ls_2_1_shift                                   (1)
#define  SENSIO_SENSIO_MBIST_LS_1_ls_2_0_shift                                   (0)
#define  SENSIO_SENSIO_MBIST_LS_1_ls_3_9_mask                                    (0x00080000)
#define  SENSIO_SENSIO_MBIST_LS_1_ls_3_8_mask                                    (0x00040000)
#define  SENSIO_SENSIO_MBIST_LS_1_ls_3_7_mask                                    (0x00020000)
#define  SENSIO_SENSIO_MBIST_LS_1_ls_3_6_mask                                    (0x00010000)
#define  SENSIO_SENSIO_MBIST_LS_1_ls_3_5_mask                                    (0x00008000)
#define  SENSIO_SENSIO_MBIST_LS_1_ls_3_4_mask                                    (0x00004000)
#define  SENSIO_SENSIO_MBIST_LS_1_ls_3_3_mask                                    (0x00002000)
#define  SENSIO_SENSIO_MBIST_LS_1_ls_3_2_mask                                    (0x00001000)
#define  SENSIO_SENSIO_MBIST_LS_1_ls_3_1_mask                                    (0x00000800)
#define  SENSIO_SENSIO_MBIST_LS_1_ls_3_0_mask                                    (0x00000400)
#define  SENSIO_SENSIO_MBIST_LS_1_ls_2_9_mask                                    (0x00000200)
#define  SENSIO_SENSIO_MBIST_LS_1_ls_2_8_mask                                    (0x00000100)
#define  SENSIO_SENSIO_MBIST_LS_1_ls_2_7_mask                                    (0x00000080)
#define  SENSIO_SENSIO_MBIST_LS_1_ls_2_6_mask                                    (0x00000040)
#define  SENSIO_SENSIO_MBIST_LS_1_ls_2_5_mask                                    (0x00000020)
#define  SENSIO_SENSIO_MBIST_LS_1_ls_2_4_mask                                    (0x00000010)
#define  SENSIO_SENSIO_MBIST_LS_1_ls_2_3_mask                                    (0x00000008)
#define  SENSIO_SENSIO_MBIST_LS_1_ls_2_2_mask                                    (0x00000004)
#define  SENSIO_SENSIO_MBIST_LS_1_ls_2_1_mask                                    (0x00000002)
#define  SENSIO_SENSIO_MBIST_LS_1_ls_2_0_mask                                    (0x00000001)
#define  SENSIO_SENSIO_MBIST_LS_1_ls_3_9(data)                                   (0x00080000&((data)<<19))
#define  SENSIO_SENSIO_MBIST_LS_1_ls_3_8(data)                                   (0x00040000&((data)<<18))
#define  SENSIO_SENSIO_MBIST_LS_1_ls_3_7(data)                                   (0x00020000&((data)<<17))
#define  SENSIO_SENSIO_MBIST_LS_1_ls_3_6(data)                                   (0x00010000&((data)<<16))
#define  SENSIO_SENSIO_MBIST_LS_1_ls_3_5(data)                                   (0x00008000&((data)<<15))
#define  SENSIO_SENSIO_MBIST_LS_1_ls_3_4(data)                                   (0x00004000&((data)<<14))
#define  SENSIO_SENSIO_MBIST_LS_1_ls_3_3(data)                                   (0x00002000&((data)<<13))
#define  SENSIO_SENSIO_MBIST_LS_1_ls_3_2(data)                                   (0x00001000&((data)<<12))
#define  SENSIO_SENSIO_MBIST_LS_1_ls_3_1(data)                                   (0x00000800&((data)<<11))
#define  SENSIO_SENSIO_MBIST_LS_1_ls_3_0(data)                                   (0x00000400&((data)<<10))
#define  SENSIO_SENSIO_MBIST_LS_1_ls_2_9(data)                                   (0x00000200&((data)<<9))
#define  SENSIO_SENSIO_MBIST_LS_1_ls_2_8(data)                                   (0x00000100&((data)<<8))
#define  SENSIO_SENSIO_MBIST_LS_1_ls_2_7(data)                                   (0x00000080&((data)<<7))
#define  SENSIO_SENSIO_MBIST_LS_1_ls_2_6(data)                                   (0x00000040&((data)<<6))
#define  SENSIO_SENSIO_MBIST_LS_1_ls_2_5(data)                                   (0x00000020&((data)<<5))
#define  SENSIO_SENSIO_MBIST_LS_1_ls_2_4(data)                                   (0x00000010&((data)<<4))
#define  SENSIO_SENSIO_MBIST_LS_1_ls_2_3(data)                                   (0x00000008&((data)<<3))
#define  SENSIO_SENSIO_MBIST_LS_1_ls_2_2(data)                                   (0x00000004&((data)<<2))
#define  SENSIO_SENSIO_MBIST_LS_1_ls_2_1(data)                                   (0x00000002&((data)<<1))
#define  SENSIO_SENSIO_MBIST_LS_1_ls_2_0(data)                                   (0x00000001&(data))
#define  SENSIO_SENSIO_MBIST_LS_1_get_ls_3_9(data)                               ((0x00080000&(data))>>19)
#define  SENSIO_SENSIO_MBIST_LS_1_get_ls_3_8(data)                               ((0x00040000&(data))>>18)
#define  SENSIO_SENSIO_MBIST_LS_1_get_ls_3_7(data)                               ((0x00020000&(data))>>17)
#define  SENSIO_SENSIO_MBIST_LS_1_get_ls_3_6(data)                               ((0x00010000&(data))>>16)
#define  SENSIO_SENSIO_MBIST_LS_1_get_ls_3_5(data)                               ((0x00008000&(data))>>15)
#define  SENSIO_SENSIO_MBIST_LS_1_get_ls_3_4(data)                               ((0x00004000&(data))>>14)
#define  SENSIO_SENSIO_MBIST_LS_1_get_ls_3_3(data)                               ((0x00002000&(data))>>13)
#define  SENSIO_SENSIO_MBIST_LS_1_get_ls_3_2(data)                               ((0x00001000&(data))>>12)
#define  SENSIO_SENSIO_MBIST_LS_1_get_ls_3_1(data)                               ((0x00000800&(data))>>11)
#define  SENSIO_SENSIO_MBIST_LS_1_get_ls_3_0(data)                               ((0x00000400&(data))>>10)
#define  SENSIO_SENSIO_MBIST_LS_1_get_ls_2_9(data)                               ((0x00000200&(data))>>9)
#define  SENSIO_SENSIO_MBIST_LS_1_get_ls_2_8(data)                               ((0x00000100&(data))>>8)
#define  SENSIO_SENSIO_MBIST_LS_1_get_ls_2_7(data)                               ((0x00000080&(data))>>7)
#define  SENSIO_SENSIO_MBIST_LS_1_get_ls_2_6(data)                               ((0x00000040&(data))>>6)
#define  SENSIO_SENSIO_MBIST_LS_1_get_ls_2_5(data)                               ((0x00000020&(data))>>5)
#define  SENSIO_SENSIO_MBIST_LS_1_get_ls_2_4(data)                               ((0x00000010&(data))>>4)
#define  SENSIO_SENSIO_MBIST_LS_1_get_ls_2_3(data)                               ((0x00000008&(data))>>3)
#define  SENSIO_SENSIO_MBIST_LS_1_get_ls_2_2(data)                               ((0x00000004&(data))>>2)
#define  SENSIO_SENSIO_MBIST_LS_1_get_ls_2_1(data)                               ((0x00000002&(data))>>1)
#define  SENSIO_SENSIO_MBIST_LS_1_get_ls_2_0(data)                               (0x00000001&(data))

#define  SENSIO_SENSIO_MBIST_LS_SUB_0                                            0x1806B9B8
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_reg_addr                                   "0xB806B9B8"
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_reg                                        0xB806B9B8
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_inst_addr                                  "0x0016"
#define  set_SENSIO_SENSIO_MBIST_LS_SUB_0_reg(data)                              (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_LS_SUB_0_reg)=data)
#define  get_SENSIO_SENSIO_MBIST_LS_SUB_0_reg                                    (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_LS_SUB_0_reg))
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_1_9_shift                           (19)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_1_8_shift                           (18)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_1_7_shift                           (17)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_1_6_shift                           (16)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_1_5_shift                           (15)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_1_4_shift                           (14)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_1_3_shift                           (13)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_1_2_shift                           (12)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_1_1_shift                           (11)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_1_0_shift                           (10)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_0_9_shift                           (9)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_0_8_shift                           (8)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_0_7_shift                           (7)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_0_6_shift                           (6)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_0_5_shift                           (5)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_0_4_shift                           (4)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_0_3_shift                           (3)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_0_2_shift                           (2)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_0_1_shift                           (1)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_0_0_shift                           (0)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_1_9_mask                            (0x00080000)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_1_8_mask                            (0x00040000)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_1_7_mask                            (0x00020000)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_1_6_mask                            (0x00010000)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_1_5_mask                            (0x00008000)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_1_4_mask                            (0x00004000)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_1_3_mask                            (0x00002000)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_1_2_mask                            (0x00001000)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_1_1_mask                            (0x00000800)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_1_0_mask                            (0x00000400)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_0_9_mask                            (0x00000200)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_0_8_mask                            (0x00000100)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_0_7_mask                            (0x00000080)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_0_6_mask                            (0x00000040)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_0_5_mask                            (0x00000020)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_0_4_mask                            (0x00000010)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_0_3_mask                            (0x00000008)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_0_2_mask                            (0x00000004)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_0_1_mask                            (0x00000002)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_0_0_mask                            (0x00000001)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_1_9(data)                           (0x00080000&((data)<<19))
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_1_8(data)                           (0x00040000&((data)<<18))
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_1_7(data)                           (0x00020000&((data)<<17))
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_1_6(data)                           (0x00010000&((data)<<16))
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_1_5(data)                           (0x00008000&((data)<<15))
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_1_4(data)                           (0x00004000&((data)<<14))
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_1_3(data)                           (0x00002000&((data)<<13))
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_1_2(data)                           (0x00001000&((data)<<12))
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_1_1(data)                           (0x00000800&((data)<<11))
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_1_0(data)                           (0x00000400&((data)<<10))
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_0_9(data)                           (0x00000200&((data)<<9))
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_0_8(data)                           (0x00000100&((data)<<8))
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_0_7(data)                           (0x00000080&((data)<<7))
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_0_6(data)                           (0x00000040&((data)<<6))
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_0_5(data)                           (0x00000020&((data)<<5))
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_0_4(data)                           (0x00000010&((data)<<4))
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_0_3(data)                           (0x00000008&((data)<<3))
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_0_2(data)                           (0x00000004&((data)<<2))
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_0_1(data)                           (0x00000002&((data)<<1))
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_ls_sub_0_0(data)                           (0x00000001&(data))
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_get_ls_sub_1_9(data)                       ((0x00080000&(data))>>19)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_get_ls_sub_1_8(data)                       ((0x00040000&(data))>>18)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_get_ls_sub_1_7(data)                       ((0x00020000&(data))>>17)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_get_ls_sub_1_6(data)                       ((0x00010000&(data))>>16)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_get_ls_sub_1_5(data)                       ((0x00008000&(data))>>15)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_get_ls_sub_1_4(data)                       ((0x00004000&(data))>>14)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_get_ls_sub_1_3(data)                       ((0x00002000&(data))>>13)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_get_ls_sub_1_2(data)                       ((0x00001000&(data))>>12)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_get_ls_sub_1_1(data)                       ((0x00000800&(data))>>11)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_get_ls_sub_1_0(data)                       ((0x00000400&(data))>>10)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_get_ls_sub_0_9(data)                       ((0x00000200&(data))>>9)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_get_ls_sub_0_8(data)                       ((0x00000100&(data))>>8)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_get_ls_sub_0_7(data)                       ((0x00000080&(data))>>7)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_get_ls_sub_0_6(data)                       ((0x00000040&(data))>>6)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_get_ls_sub_0_5(data)                       ((0x00000020&(data))>>5)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_get_ls_sub_0_4(data)                       ((0x00000010&(data))>>4)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_get_ls_sub_0_3(data)                       ((0x00000008&(data))>>3)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_get_ls_sub_0_2(data)                       ((0x00000004&(data))>>2)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_get_ls_sub_0_1(data)                       ((0x00000002&(data))>>1)
#define  SENSIO_SENSIO_MBIST_LS_SUB_0_get_ls_sub_0_0(data)                       (0x00000001&(data))

#define  SENSIO_SENSIO_MBIST_LS_SUB_1                                            0x1806B9BC
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_reg_addr                                   "0xB806B9BC"
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_reg                                        0xB806B9BC
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_inst_addr                                  "0x0017"
#define  set_SENSIO_SENSIO_MBIST_LS_SUB_1_reg(data)                              (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_LS_SUB_1_reg)=data)
#define  get_SENSIO_SENSIO_MBIST_LS_SUB_1_reg                                    (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_LS_SUB_1_reg))
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_3_9_shift                           (19)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_3_8_shift                           (18)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_3_7_shift                           (17)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_3_6_shift                           (16)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_3_5_shift                           (15)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_3_4_shift                           (14)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_3_3_shift                           (13)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_3_2_shift                           (12)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_3_1_shift                           (11)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_3_0_shift                           (10)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_2_9_shift                           (9)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_2_8_shift                           (8)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_2_7_shift                           (7)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_2_6_shift                           (6)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_2_5_shift                           (5)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_2_4_shift                           (4)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_2_3_shift                           (3)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_2_2_shift                           (2)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_2_1_shift                           (1)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_2_0_shift                           (0)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_3_9_mask                            (0x00080000)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_3_8_mask                            (0x00040000)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_3_7_mask                            (0x00020000)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_3_6_mask                            (0x00010000)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_3_5_mask                            (0x00008000)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_3_4_mask                            (0x00004000)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_3_3_mask                            (0x00002000)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_3_2_mask                            (0x00001000)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_3_1_mask                            (0x00000800)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_3_0_mask                            (0x00000400)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_2_9_mask                            (0x00000200)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_2_8_mask                            (0x00000100)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_2_7_mask                            (0x00000080)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_2_6_mask                            (0x00000040)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_2_5_mask                            (0x00000020)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_2_4_mask                            (0x00000010)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_2_3_mask                            (0x00000008)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_2_2_mask                            (0x00000004)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_2_1_mask                            (0x00000002)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_2_0_mask                            (0x00000001)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_3_9(data)                           (0x00080000&((data)<<19))
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_3_8(data)                           (0x00040000&((data)<<18))
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_3_7(data)                           (0x00020000&((data)<<17))
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_3_6(data)                           (0x00010000&((data)<<16))
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_3_5(data)                           (0x00008000&((data)<<15))
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_3_4(data)                           (0x00004000&((data)<<14))
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_3_3(data)                           (0x00002000&((data)<<13))
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_3_2(data)                           (0x00001000&((data)<<12))
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_3_1(data)                           (0x00000800&((data)<<11))
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_3_0(data)                           (0x00000400&((data)<<10))
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_2_9(data)                           (0x00000200&((data)<<9))
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_2_8(data)                           (0x00000100&((data)<<8))
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_2_7(data)                           (0x00000080&((data)<<7))
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_2_6(data)                           (0x00000040&((data)<<6))
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_2_5(data)                           (0x00000020&((data)<<5))
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_2_4(data)                           (0x00000010&((data)<<4))
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_2_3(data)                           (0x00000008&((data)<<3))
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_2_2(data)                           (0x00000004&((data)<<2))
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_2_1(data)                           (0x00000002&((data)<<1))
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_ls_sub_2_0(data)                           (0x00000001&(data))
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_get_ls_sub_3_9(data)                       ((0x00080000&(data))>>19)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_get_ls_sub_3_8(data)                       ((0x00040000&(data))>>18)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_get_ls_sub_3_7(data)                       ((0x00020000&(data))>>17)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_get_ls_sub_3_6(data)                       ((0x00010000&(data))>>16)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_get_ls_sub_3_5(data)                       ((0x00008000&(data))>>15)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_get_ls_sub_3_4(data)                       ((0x00004000&(data))>>14)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_get_ls_sub_3_3(data)                       ((0x00002000&(data))>>13)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_get_ls_sub_3_2(data)                       ((0x00001000&(data))>>12)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_get_ls_sub_3_1(data)                       ((0x00000800&(data))>>11)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_get_ls_sub_3_0(data)                       ((0x00000400&(data))>>10)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_get_ls_sub_2_9(data)                       ((0x00000200&(data))>>9)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_get_ls_sub_2_8(data)                       ((0x00000100&(data))>>8)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_get_ls_sub_2_7(data)                       ((0x00000080&(data))>>7)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_get_ls_sub_2_6(data)                       ((0x00000040&(data))>>6)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_get_ls_sub_2_5(data)                       ((0x00000020&(data))>>5)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_get_ls_sub_2_4(data)                       ((0x00000010&(data))>>4)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_get_ls_sub_2_3(data)                       ((0x00000008&(data))>>3)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_get_ls_sub_2_2(data)                       ((0x00000004&(data))>>2)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_get_ls_sub_2_1(data)                       ((0x00000002&(data))>>1)
#define  SENSIO_SENSIO_MBIST_LS_SUB_1_get_ls_sub_2_0(data)                       (0x00000001&(data))

#define  SENSIO_SENSIO_MBIST_RM_0                                                0x1806B9C0
#define  SENSIO_SENSIO_MBIST_RM_0_reg_addr                                       "0xB806B9C0"
#define  SENSIO_SENSIO_MBIST_RM_0_reg                                            0xB806B9C0
#define  SENSIO_SENSIO_MBIST_RM_0_inst_addr                                      "0x0018"
#define  set_SENSIO_SENSIO_MBIST_RM_0_reg(data)                                  (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_RM_0_reg)=data)
#define  get_SENSIO_SENSIO_MBIST_RM_0_reg                                        (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_RM_0_reg))
#define  SENSIO_SENSIO_MBIST_RM_0_rm_0_7_shift                                   (28)
#define  SENSIO_SENSIO_MBIST_RM_0_rm_0_6_shift                                   (24)
#define  SENSIO_SENSIO_MBIST_RM_0_rm_0_5_shift                                   (20)
#define  SENSIO_SENSIO_MBIST_RM_0_rm_0_4_shift                                   (16)
#define  SENSIO_SENSIO_MBIST_RM_0_rm_0_3_shift                                   (12)
#define  SENSIO_SENSIO_MBIST_RM_0_rm_0_2_shift                                   (8)
#define  SENSIO_SENSIO_MBIST_RM_0_rm_0_1_shift                                   (4)
#define  SENSIO_SENSIO_MBIST_RM_0_rm_0_0_shift                                   (0)
#define  SENSIO_SENSIO_MBIST_RM_0_rm_0_7_mask                                    (0xF0000000)
#define  SENSIO_SENSIO_MBIST_RM_0_rm_0_6_mask                                    (0x0F000000)
#define  SENSIO_SENSIO_MBIST_RM_0_rm_0_5_mask                                    (0x00F00000)
#define  SENSIO_SENSIO_MBIST_RM_0_rm_0_4_mask                                    (0x000F0000)
#define  SENSIO_SENSIO_MBIST_RM_0_rm_0_3_mask                                    (0x0000F000)
#define  SENSIO_SENSIO_MBIST_RM_0_rm_0_2_mask                                    (0x00000F00)
#define  SENSIO_SENSIO_MBIST_RM_0_rm_0_1_mask                                    (0x000000F0)
#define  SENSIO_SENSIO_MBIST_RM_0_rm_0_0_mask                                    (0x0000000F)
#define  SENSIO_SENSIO_MBIST_RM_0_rm_0_7(data)                                   (0xF0000000&((data)<<28))
#define  SENSIO_SENSIO_MBIST_RM_0_rm_0_6(data)                                   (0x0F000000&((data)<<24))
#define  SENSIO_SENSIO_MBIST_RM_0_rm_0_5(data)                                   (0x00F00000&((data)<<20))
#define  SENSIO_SENSIO_MBIST_RM_0_rm_0_4(data)                                   (0x000F0000&((data)<<16))
#define  SENSIO_SENSIO_MBIST_RM_0_rm_0_3(data)                                   (0x0000F000&((data)<<12))
#define  SENSIO_SENSIO_MBIST_RM_0_rm_0_2(data)                                   (0x00000F00&((data)<<8))
#define  SENSIO_SENSIO_MBIST_RM_0_rm_0_1(data)                                   (0x000000F0&((data)<<4))
#define  SENSIO_SENSIO_MBIST_RM_0_rm_0_0(data)                                   (0x0000000F&(data))
#define  SENSIO_SENSIO_MBIST_RM_0_get_rm_0_7(data)                               ((0xF0000000&(data))>>28)
#define  SENSIO_SENSIO_MBIST_RM_0_get_rm_0_6(data)                               ((0x0F000000&(data))>>24)
#define  SENSIO_SENSIO_MBIST_RM_0_get_rm_0_5(data)                               ((0x00F00000&(data))>>20)
#define  SENSIO_SENSIO_MBIST_RM_0_get_rm_0_4(data)                               ((0x000F0000&(data))>>16)
#define  SENSIO_SENSIO_MBIST_RM_0_get_rm_0_3(data)                               ((0x0000F000&(data))>>12)
#define  SENSIO_SENSIO_MBIST_RM_0_get_rm_0_2(data)                               ((0x00000F00&(data))>>8)
#define  SENSIO_SENSIO_MBIST_RM_0_get_rm_0_1(data)                               ((0x000000F0&(data))>>4)
#define  SENSIO_SENSIO_MBIST_RM_0_get_rm_0_0(data)                               (0x0000000F&(data))

#define  SENSIO_SENSIO_MBIST_RM_1                                                0x1806B9C4
#define  SENSIO_SENSIO_MBIST_RM_1_reg_addr                                       "0xB806B9C4"
#define  SENSIO_SENSIO_MBIST_RM_1_reg                                            0xB806B9C4
#define  SENSIO_SENSIO_MBIST_RM_1_inst_addr                                      "0x0019"
#define  set_SENSIO_SENSIO_MBIST_RM_1_reg(data)                                  (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_RM_1_reg)=data)
#define  get_SENSIO_SENSIO_MBIST_RM_1_reg                                        (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_RM_1_reg))
#define  SENSIO_SENSIO_MBIST_RM_1_rm_1_5_shift                                   (28)
#define  SENSIO_SENSIO_MBIST_RM_1_rm_1_4_shift                                   (24)
#define  SENSIO_SENSIO_MBIST_RM_1_rm_1_3_shift                                   (20)
#define  SENSIO_SENSIO_MBIST_RM_1_rm_1_2_shift                                   (16)
#define  SENSIO_SENSIO_MBIST_RM_1_rm_1_1_shift                                   (12)
#define  SENSIO_SENSIO_MBIST_RM_1_rm_1_0_shift                                   (8)
#define  SENSIO_SENSIO_MBIST_RM_1_rm_0_9_shift                                   (4)
#define  SENSIO_SENSIO_MBIST_RM_1_rm_0_8_shift                                   (0)
#define  SENSIO_SENSIO_MBIST_RM_1_rm_1_5_mask                                    (0xF0000000)
#define  SENSIO_SENSIO_MBIST_RM_1_rm_1_4_mask                                    (0x0F000000)
#define  SENSIO_SENSIO_MBIST_RM_1_rm_1_3_mask                                    (0x00F00000)
#define  SENSIO_SENSIO_MBIST_RM_1_rm_1_2_mask                                    (0x000F0000)
#define  SENSIO_SENSIO_MBIST_RM_1_rm_1_1_mask                                    (0x0000F000)
#define  SENSIO_SENSIO_MBIST_RM_1_rm_1_0_mask                                    (0x00000F00)
#define  SENSIO_SENSIO_MBIST_RM_1_rm_0_9_mask                                    (0x000000F0)
#define  SENSIO_SENSIO_MBIST_RM_1_rm_0_8_mask                                    (0x0000000F)
#define  SENSIO_SENSIO_MBIST_RM_1_rm_1_5(data)                                   (0xF0000000&((data)<<28))
#define  SENSIO_SENSIO_MBIST_RM_1_rm_1_4(data)                                   (0x0F000000&((data)<<24))
#define  SENSIO_SENSIO_MBIST_RM_1_rm_1_3(data)                                   (0x00F00000&((data)<<20))
#define  SENSIO_SENSIO_MBIST_RM_1_rm_1_2(data)                                   (0x000F0000&((data)<<16))
#define  SENSIO_SENSIO_MBIST_RM_1_rm_1_1(data)                                   (0x0000F000&((data)<<12))
#define  SENSIO_SENSIO_MBIST_RM_1_rm_1_0(data)                                   (0x00000F00&((data)<<8))
#define  SENSIO_SENSIO_MBIST_RM_1_rm_0_9(data)                                   (0x000000F0&((data)<<4))
#define  SENSIO_SENSIO_MBIST_RM_1_rm_0_8(data)                                   (0x0000000F&(data))
#define  SENSIO_SENSIO_MBIST_RM_1_get_rm_1_5(data)                               ((0xF0000000&(data))>>28)
#define  SENSIO_SENSIO_MBIST_RM_1_get_rm_1_4(data)                               ((0x0F000000&(data))>>24)
#define  SENSIO_SENSIO_MBIST_RM_1_get_rm_1_3(data)                               ((0x00F00000&(data))>>20)
#define  SENSIO_SENSIO_MBIST_RM_1_get_rm_1_2(data)                               ((0x000F0000&(data))>>16)
#define  SENSIO_SENSIO_MBIST_RM_1_get_rm_1_1(data)                               ((0x0000F000&(data))>>12)
#define  SENSIO_SENSIO_MBIST_RM_1_get_rm_1_0(data)                               ((0x00000F00&(data))>>8)
#define  SENSIO_SENSIO_MBIST_RM_1_get_rm_0_9(data)                               ((0x000000F0&(data))>>4)
#define  SENSIO_SENSIO_MBIST_RM_1_get_rm_0_8(data)                               (0x0000000F&(data))

#define  SENSIO_SENSIO_MBIST_RM_2                                                0x1806B9C8
#define  SENSIO_SENSIO_MBIST_RM_2_reg_addr                                       "0xB806B9C8"
#define  SENSIO_SENSIO_MBIST_RM_2_reg                                            0xB806B9C8
#define  SENSIO_SENSIO_MBIST_RM_2_inst_addr                                      "0x001A"
#define  set_SENSIO_SENSIO_MBIST_RM_2_reg(data)                                  (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_RM_2_reg)=data)
#define  get_SENSIO_SENSIO_MBIST_RM_2_reg                                        (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_RM_2_reg))
#define  SENSIO_SENSIO_MBIST_RM_2_rm_2_3_shift                                   (28)
#define  SENSIO_SENSIO_MBIST_RM_2_rm_2_2_shift                                   (24)
#define  SENSIO_SENSIO_MBIST_RM_2_rm_2_1_shift                                   (20)
#define  SENSIO_SENSIO_MBIST_RM_2_rm_2_0_shift                                   (16)
#define  SENSIO_SENSIO_MBIST_RM_2_rm_1_9_shift                                   (12)
#define  SENSIO_SENSIO_MBIST_RM_2_rm_1_8_shift                                   (8)
#define  SENSIO_SENSIO_MBIST_RM_2_rm_1_7_shift                                   (4)
#define  SENSIO_SENSIO_MBIST_RM_2_rm_1_6_shift                                   (0)
#define  SENSIO_SENSIO_MBIST_RM_2_rm_2_3_mask                                    (0xF0000000)
#define  SENSIO_SENSIO_MBIST_RM_2_rm_2_2_mask                                    (0x0F000000)
#define  SENSIO_SENSIO_MBIST_RM_2_rm_2_1_mask                                    (0x00F00000)
#define  SENSIO_SENSIO_MBIST_RM_2_rm_2_0_mask                                    (0x000F0000)
#define  SENSIO_SENSIO_MBIST_RM_2_rm_1_9_mask                                    (0x0000F000)
#define  SENSIO_SENSIO_MBIST_RM_2_rm_1_8_mask                                    (0x00000F00)
#define  SENSIO_SENSIO_MBIST_RM_2_rm_1_7_mask                                    (0x000000F0)
#define  SENSIO_SENSIO_MBIST_RM_2_rm_1_6_mask                                    (0x0000000F)
#define  SENSIO_SENSIO_MBIST_RM_2_rm_2_3(data)                                   (0xF0000000&((data)<<28))
#define  SENSIO_SENSIO_MBIST_RM_2_rm_2_2(data)                                   (0x0F000000&((data)<<24))
#define  SENSIO_SENSIO_MBIST_RM_2_rm_2_1(data)                                   (0x00F00000&((data)<<20))
#define  SENSIO_SENSIO_MBIST_RM_2_rm_2_0(data)                                   (0x000F0000&((data)<<16))
#define  SENSIO_SENSIO_MBIST_RM_2_rm_1_9(data)                                   (0x0000F000&((data)<<12))
#define  SENSIO_SENSIO_MBIST_RM_2_rm_1_8(data)                                   (0x00000F00&((data)<<8))
#define  SENSIO_SENSIO_MBIST_RM_2_rm_1_7(data)                                   (0x000000F0&((data)<<4))
#define  SENSIO_SENSIO_MBIST_RM_2_rm_1_6(data)                                   (0x0000000F&(data))
#define  SENSIO_SENSIO_MBIST_RM_2_get_rm_2_3(data)                               ((0xF0000000&(data))>>28)
#define  SENSIO_SENSIO_MBIST_RM_2_get_rm_2_2(data)                               ((0x0F000000&(data))>>24)
#define  SENSIO_SENSIO_MBIST_RM_2_get_rm_2_1(data)                               ((0x00F00000&(data))>>20)
#define  SENSIO_SENSIO_MBIST_RM_2_get_rm_2_0(data)                               ((0x000F0000&(data))>>16)
#define  SENSIO_SENSIO_MBIST_RM_2_get_rm_1_9(data)                               ((0x0000F000&(data))>>12)
#define  SENSIO_SENSIO_MBIST_RM_2_get_rm_1_8(data)                               ((0x00000F00&(data))>>8)
#define  SENSIO_SENSIO_MBIST_RM_2_get_rm_1_7(data)                               ((0x000000F0&(data))>>4)
#define  SENSIO_SENSIO_MBIST_RM_2_get_rm_1_6(data)                               (0x0000000F&(data))

#define  SENSIO_SENSIO_MBIST_RM_3                                                0x1806B9CC
#define  SENSIO_SENSIO_MBIST_RM_3_reg_addr                                       "0xB806B9CC"
#define  SENSIO_SENSIO_MBIST_RM_3_reg                                            0xB806B9CC
#define  SENSIO_SENSIO_MBIST_RM_3_inst_addr                                      "0x001B"
#define  set_SENSIO_SENSIO_MBIST_RM_3_reg(data)                                  (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_RM_3_reg)=data)
#define  get_SENSIO_SENSIO_MBIST_RM_3_reg                                        (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_RM_3_reg))
#define  SENSIO_SENSIO_MBIST_RM_3_rm_3_1_shift                                   (28)
#define  SENSIO_SENSIO_MBIST_RM_3_rm_3_0_shift                                   (24)
#define  SENSIO_SENSIO_MBIST_RM_3_rm_2_9_shift                                   (20)
#define  SENSIO_SENSIO_MBIST_RM_3_rm_2_8_shift                                   (16)
#define  SENSIO_SENSIO_MBIST_RM_3_rm_2_7_shift                                   (12)
#define  SENSIO_SENSIO_MBIST_RM_3_rm_2_6_shift                                   (8)
#define  SENSIO_SENSIO_MBIST_RM_3_rm_2_5_shift                                   (4)
#define  SENSIO_SENSIO_MBIST_RM_3_rm_2_4_shift                                   (0)
#define  SENSIO_SENSIO_MBIST_RM_3_rm_3_1_mask                                    (0xF0000000)
#define  SENSIO_SENSIO_MBIST_RM_3_rm_3_0_mask                                    (0x0F000000)
#define  SENSIO_SENSIO_MBIST_RM_3_rm_2_9_mask                                    (0x00F00000)
#define  SENSIO_SENSIO_MBIST_RM_3_rm_2_8_mask                                    (0x000F0000)
#define  SENSIO_SENSIO_MBIST_RM_3_rm_2_7_mask                                    (0x0000F000)
#define  SENSIO_SENSIO_MBIST_RM_3_rm_2_6_mask                                    (0x00000F00)
#define  SENSIO_SENSIO_MBIST_RM_3_rm_2_5_mask                                    (0x000000F0)
#define  SENSIO_SENSIO_MBIST_RM_3_rm_2_4_mask                                    (0x0000000F)
#define  SENSIO_SENSIO_MBIST_RM_3_rm_3_1(data)                                   (0xF0000000&((data)<<28))
#define  SENSIO_SENSIO_MBIST_RM_3_rm_3_0(data)                                   (0x0F000000&((data)<<24))
#define  SENSIO_SENSIO_MBIST_RM_3_rm_2_9(data)                                   (0x00F00000&((data)<<20))
#define  SENSIO_SENSIO_MBIST_RM_3_rm_2_8(data)                                   (0x000F0000&((data)<<16))
#define  SENSIO_SENSIO_MBIST_RM_3_rm_2_7(data)                                   (0x0000F000&((data)<<12))
#define  SENSIO_SENSIO_MBIST_RM_3_rm_2_6(data)                                   (0x00000F00&((data)<<8))
#define  SENSIO_SENSIO_MBIST_RM_3_rm_2_5(data)                                   (0x000000F0&((data)<<4))
#define  SENSIO_SENSIO_MBIST_RM_3_rm_2_4(data)                                   (0x0000000F&(data))
#define  SENSIO_SENSIO_MBIST_RM_3_get_rm_3_1(data)                               ((0xF0000000&(data))>>28)
#define  SENSIO_SENSIO_MBIST_RM_3_get_rm_3_0(data)                               ((0x0F000000&(data))>>24)
#define  SENSIO_SENSIO_MBIST_RM_3_get_rm_2_9(data)                               ((0x00F00000&(data))>>20)
#define  SENSIO_SENSIO_MBIST_RM_3_get_rm_2_8(data)                               ((0x000F0000&(data))>>16)
#define  SENSIO_SENSIO_MBIST_RM_3_get_rm_2_7(data)                               ((0x0000F000&(data))>>12)
#define  SENSIO_SENSIO_MBIST_RM_3_get_rm_2_6(data)                               ((0x00000F00&(data))>>8)
#define  SENSIO_SENSIO_MBIST_RM_3_get_rm_2_5(data)                               ((0x000000F0&(data))>>4)
#define  SENSIO_SENSIO_MBIST_RM_3_get_rm_2_4(data)                               (0x0000000F&(data))

#define  SENSIO_SENSIO_MBIST_RM_4                                                0x1806B9D0
#define  SENSIO_SENSIO_MBIST_RM_4_reg_addr                                       "0xB806B9D0"
#define  SENSIO_SENSIO_MBIST_RM_4_reg                                            0xB806B9D0
#define  SENSIO_SENSIO_MBIST_RM_4_inst_addr                                      "0x001C"
#define  set_SENSIO_SENSIO_MBIST_RM_4_reg(data)                                  (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_RM_4_reg)=data)
#define  get_SENSIO_SENSIO_MBIST_RM_4_reg                                        (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_RM_4_reg))
#define  SENSIO_SENSIO_MBIST_RM_4_rm_3_9_shift                                   (28)
#define  SENSIO_SENSIO_MBIST_RM_4_rm_3_8_shift                                   (24)
#define  SENSIO_SENSIO_MBIST_RM_4_rm_3_7_shift                                   (20)
#define  SENSIO_SENSIO_MBIST_RM_4_rm_3_6_shift                                   (16)
#define  SENSIO_SENSIO_MBIST_RM_4_rm_3_5_shift                                   (12)
#define  SENSIO_SENSIO_MBIST_RM_4_rm_3_4_shift                                   (8)
#define  SENSIO_SENSIO_MBIST_RM_4_rm_3_3_shift                                   (4)
#define  SENSIO_SENSIO_MBIST_RM_4_rm_3_2_shift                                   (0)
#define  SENSIO_SENSIO_MBIST_RM_4_rm_3_9_mask                                    (0xF0000000)
#define  SENSIO_SENSIO_MBIST_RM_4_rm_3_8_mask                                    (0x0F000000)
#define  SENSIO_SENSIO_MBIST_RM_4_rm_3_7_mask                                    (0x00F00000)
#define  SENSIO_SENSIO_MBIST_RM_4_rm_3_6_mask                                    (0x000F0000)
#define  SENSIO_SENSIO_MBIST_RM_4_rm_3_5_mask                                    (0x0000F000)
#define  SENSIO_SENSIO_MBIST_RM_4_rm_3_4_mask                                    (0x00000F00)
#define  SENSIO_SENSIO_MBIST_RM_4_rm_3_3_mask                                    (0x000000F0)
#define  SENSIO_SENSIO_MBIST_RM_4_rm_3_2_mask                                    (0x0000000F)
#define  SENSIO_SENSIO_MBIST_RM_4_rm_3_9(data)                                   (0xF0000000&((data)<<28))
#define  SENSIO_SENSIO_MBIST_RM_4_rm_3_8(data)                                   (0x0F000000&((data)<<24))
#define  SENSIO_SENSIO_MBIST_RM_4_rm_3_7(data)                                   (0x00F00000&((data)<<20))
#define  SENSIO_SENSIO_MBIST_RM_4_rm_3_6(data)                                   (0x000F0000&((data)<<16))
#define  SENSIO_SENSIO_MBIST_RM_4_rm_3_5(data)                                   (0x0000F000&((data)<<12))
#define  SENSIO_SENSIO_MBIST_RM_4_rm_3_4(data)                                   (0x00000F00&((data)<<8))
#define  SENSIO_SENSIO_MBIST_RM_4_rm_3_3(data)                                   (0x000000F0&((data)<<4))
#define  SENSIO_SENSIO_MBIST_RM_4_rm_3_2(data)                                   (0x0000000F&(data))
#define  SENSIO_SENSIO_MBIST_RM_4_get_rm_3_9(data)                               ((0xF0000000&(data))>>28)
#define  SENSIO_SENSIO_MBIST_RM_4_get_rm_3_8(data)                               ((0x0F000000&(data))>>24)
#define  SENSIO_SENSIO_MBIST_RM_4_get_rm_3_7(data)                               ((0x00F00000&(data))>>20)
#define  SENSIO_SENSIO_MBIST_RM_4_get_rm_3_6(data)                               ((0x000F0000&(data))>>16)
#define  SENSIO_SENSIO_MBIST_RM_4_get_rm_3_5(data)                               ((0x0000F000&(data))>>12)
#define  SENSIO_SENSIO_MBIST_RM_4_get_rm_3_4(data)                               ((0x00000F00&(data))>>8)
#define  SENSIO_SENSIO_MBIST_RM_4_get_rm_3_3(data)                               ((0x000000F0&(data))>>4)
#define  SENSIO_SENSIO_MBIST_RM_4_get_rm_3_2(data)                               (0x0000000F&(data))

#define  SENSIO_SENSIO_MBIST_RM_SUB_0                                            0x1806B9D4
#define  SENSIO_SENSIO_MBIST_RM_SUB_0_reg_addr                                   "0xB806B9D4"
#define  SENSIO_SENSIO_MBIST_RM_SUB_0_reg                                        0xB806B9D4
#define  SENSIO_SENSIO_MBIST_RM_SUB_0_inst_addr                                  "0x001D"
#define  set_SENSIO_SENSIO_MBIST_RM_SUB_0_reg(data)                              (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_RM_SUB_0_reg)=data)
#define  get_SENSIO_SENSIO_MBIST_RM_SUB_0_reg                                    (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_RM_SUB_0_reg))
#define  SENSIO_SENSIO_MBIST_RM_SUB_0_rm_sub_0_7_shift                           (28)
#define  SENSIO_SENSIO_MBIST_RM_SUB_0_rm_sub_0_6_shift                           (24)
#define  SENSIO_SENSIO_MBIST_RM_SUB_0_rm_sub_0_5_shift                           (20)
#define  SENSIO_SENSIO_MBIST_RM_SUB_0_rm_sub_0_4_shift                           (16)
#define  SENSIO_SENSIO_MBIST_RM_SUB_0_rm_sub_0_3_shift                           (12)
#define  SENSIO_SENSIO_MBIST_RM_SUB_0_rm_sub_0_2_shift                           (8)
#define  SENSIO_SENSIO_MBIST_RM_SUB_0_rm_sub_0_1_shift                           (4)
#define  SENSIO_SENSIO_MBIST_RM_SUB_0_rm_sub_0_0_shift                           (0)
#define  SENSIO_SENSIO_MBIST_RM_SUB_0_rm_sub_0_7_mask                            (0xF0000000)
#define  SENSIO_SENSIO_MBIST_RM_SUB_0_rm_sub_0_6_mask                            (0x0F000000)
#define  SENSIO_SENSIO_MBIST_RM_SUB_0_rm_sub_0_5_mask                            (0x00F00000)
#define  SENSIO_SENSIO_MBIST_RM_SUB_0_rm_sub_0_4_mask                            (0x000F0000)
#define  SENSIO_SENSIO_MBIST_RM_SUB_0_rm_sub_0_3_mask                            (0x0000F000)
#define  SENSIO_SENSIO_MBIST_RM_SUB_0_rm_sub_0_2_mask                            (0x00000F00)
#define  SENSIO_SENSIO_MBIST_RM_SUB_0_rm_sub_0_1_mask                            (0x000000F0)
#define  SENSIO_SENSIO_MBIST_RM_SUB_0_rm_sub_0_0_mask                            (0x0000000F)
#define  SENSIO_SENSIO_MBIST_RM_SUB_0_rm_sub_0_7(data)                           (0xF0000000&((data)<<28))
#define  SENSIO_SENSIO_MBIST_RM_SUB_0_rm_sub_0_6(data)                           (0x0F000000&((data)<<24))
#define  SENSIO_SENSIO_MBIST_RM_SUB_0_rm_sub_0_5(data)                           (0x00F00000&((data)<<20))
#define  SENSIO_SENSIO_MBIST_RM_SUB_0_rm_sub_0_4(data)                           (0x000F0000&((data)<<16))
#define  SENSIO_SENSIO_MBIST_RM_SUB_0_rm_sub_0_3(data)                           (0x0000F000&((data)<<12))
#define  SENSIO_SENSIO_MBIST_RM_SUB_0_rm_sub_0_2(data)                           (0x00000F00&((data)<<8))
#define  SENSIO_SENSIO_MBIST_RM_SUB_0_rm_sub_0_1(data)                           (0x000000F0&((data)<<4))
#define  SENSIO_SENSIO_MBIST_RM_SUB_0_rm_sub_0_0(data)                           (0x0000000F&(data))
#define  SENSIO_SENSIO_MBIST_RM_SUB_0_get_rm_sub_0_7(data)                       ((0xF0000000&(data))>>28)
#define  SENSIO_SENSIO_MBIST_RM_SUB_0_get_rm_sub_0_6(data)                       ((0x0F000000&(data))>>24)
#define  SENSIO_SENSIO_MBIST_RM_SUB_0_get_rm_sub_0_5(data)                       ((0x00F00000&(data))>>20)
#define  SENSIO_SENSIO_MBIST_RM_SUB_0_get_rm_sub_0_4(data)                       ((0x000F0000&(data))>>16)
#define  SENSIO_SENSIO_MBIST_RM_SUB_0_get_rm_sub_0_3(data)                       ((0x0000F000&(data))>>12)
#define  SENSIO_SENSIO_MBIST_RM_SUB_0_get_rm_sub_0_2(data)                       ((0x00000F00&(data))>>8)
#define  SENSIO_SENSIO_MBIST_RM_SUB_0_get_rm_sub_0_1(data)                       ((0x000000F0&(data))>>4)
#define  SENSIO_SENSIO_MBIST_RM_SUB_0_get_rm_sub_0_0(data)                       (0x0000000F&(data))

#define  SENSIO_SENSIO_MBIST_RM_SUB_1                                            0x1806B9D8
#define  SENSIO_SENSIO_MBIST_RM_SUB_1_reg_addr                                   "0xB806B9D8"
#define  SENSIO_SENSIO_MBIST_RM_SUB_1_reg                                        0xB806B9D8
#define  SENSIO_SENSIO_MBIST_RM_SUB_1_inst_addr                                  "0x001E"
#define  set_SENSIO_SENSIO_MBIST_RM_SUB_1_reg(data)                              (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_RM_SUB_1_reg)=data)
#define  get_SENSIO_SENSIO_MBIST_RM_SUB_1_reg                                    (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_RM_SUB_1_reg))
#define  SENSIO_SENSIO_MBIST_RM_SUB_1_rm_sub_1_5_shift                           (28)
#define  SENSIO_SENSIO_MBIST_RM_SUB_1_rm_sub_1_4_shift                           (24)
#define  SENSIO_SENSIO_MBIST_RM_SUB_1_rm_sub_1_3_shift                           (20)
#define  SENSIO_SENSIO_MBIST_RM_SUB_1_rm_sub_1_2_shift                           (16)
#define  SENSIO_SENSIO_MBIST_RM_SUB_1_rm_sub_1_1_shift                           (12)
#define  SENSIO_SENSIO_MBIST_RM_SUB_1_rm_sub_1_0_shift                           (8)
#define  SENSIO_SENSIO_MBIST_RM_SUB_1_rm_sub_0_9_shift                           (4)
#define  SENSIO_SENSIO_MBIST_RM_SUB_1_rm_sub_0_8_shift                           (0)
#define  SENSIO_SENSIO_MBIST_RM_SUB_1_rm_sub_1_5_mask                            (0xF0000000)
#define  SENSIO_SENSIO_MBIST_RM_SUB_1_rm_sub_1_4_mask                            (0x0F000000)
#define  SENSIO_SENSIO_MBIST_RM_SUB_1_rm_sub_1_3_mask                            (0x00F00000)
#define  SENSIO_SENSIO_MBIST_RM_SUB_1_rm_sub_1_2_mask                            (0x000F0000)
#define  SENSIO_SENSIO_MBIST_RM_SUB_1_rm_sub_1_1_mask                            (0x0000F000)
#define  SENSIO_SENSIO_MBIST_RM_SUB_1_rm_sub_1_0_mask                            (0x00000F00)
#define  SENSIO_SENSIO_MBIST_RM_SUB_1_rm_sub_0_9_mask                            (0x000000F0)
#define  SENSIO_SENSIO_MBIST_RM_SUB_1_rm_sub_0_8_mask                            (0x0000000F)
#define  SENSIO_SENSIO_MBIST_RM_SUB_1_rm_sub_1_5(data)                           (0xF0000000&((data)<<28))
#define  SENSIO_SENSIO_MBIST_RM_SUB_1_rm_sub_1_4(data)                           (0x0F000000&((data)<<24))
#define  SENSIO_SENSIO_MBIST_RM_SUB_1_rm_sub_1_3(data)                           (0x00F00000&((data)<<20))
#define  SENSIO_SENSIO_MBIST_RM_SUB_1_rm_sub_1_2(data)                           (0x000F0000&((data)<<16))
#define  SENSIO_SENSIO_MBIST_RM_SUB_1_rm_sub_1_1(data)                           (0x0000F000&((data)<<12))
#define  SENSIO_SENSIO_MBIST_RM_SUB_1_rm_sub_1_0(data)                           (0x00000F00&((data)<<8))
#define  SENSIO_SENSIO_MBIST_RM_SUB_1_rm_sub_0_9(data)                           (0x000000F0&((data)<<4))
#define  SENSIO_SENSIO_MBIST_RM_SUB_1_rm_sub_0_8(data)                           (0x0000000F&(data))
#define  SENSIO_SENSIO_MBIST_RM_SUB_1_get_rm_sub_1_5(data)                       ((0xF0000000&(data))>>28)
#define  SENSIO_SENSIO_MBIST_RM_SUB_1_get_rm_sub_1_4(data)                       ((0x0F000000&(data))>>24)
#define  SENSIO_SENSIO_MBIST_RM_SUB_1_get_rm_sub_1_3(data)                       ((0x00F00000&(data))>>20)
#define  SENSIO_SENSIO_MBIST_RM_SUB_1_get_rm_sub_1_2(data)                       ((0x000F0000&(data))>>16)
#define  SENSIO_SENSIO_MBIST_RM_SUB_1_get_rm_sub_1_1(data)                       ((0x0000F000&(data))>>12)
#define  SENSIO_SENSIO_MBIST_RM_SUB_1_get_rm_sub_1_0(data)                       ((0x00000F00&(data))>>8)
#define  SENSIO_SENSIO_MBIST_RM_SUB_1_get_rm_sub_0_9(data)                       ((0x000000F0&(data))>>4)
#define  SENSIO_SENSIO_MBIST_RM_SUB_1_get_rm_sub_0_8(data)                       (0x0000000F&(data))

#define  SENSIO_SENSIO_MBIST_RM_SUB_2                                            0x1806B9DC
#define  SENSIO_SENSIO_MBIST_RM_SUB_2_reg_addr                                   "0xB806B9DC"
#define  SENSIO_SENSIO_MBIST_RM_SUB_2_reg                                        0xB806B9DC
#define  SENSIO_SENSIO_MBIST_RM_SUB_2_inst_addr                                  "0x001F"
#define  set_SENSIO_SENSIO_MBIST_RM_SUB_2_reg(data)                              (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_RM_SUB_2_reg)=data)
#define  get_SENSIO_SENSIO_MBIST_RM_SUB_2_reg                                    (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_RM_SUB_2_reg))
#define  SENSIO_SENSIO_MBIST_RM_SUB_2_rm_sub_2_3_shift                           (28)
#define  SENSIO_SENSIO_MBIST_RM_SUB_2_rm_sub_2_2_shift                           (24)
#define  SENSIO_SENSIO_MBIST_RM_SUB_2_rm_sub_2_1_shift                           (20)
#define  SENSIO_SENSIO_MBIST_RM_SUB_2_rm_sub_2_0_shift                           (16)
#define  SENSIO_SENSIO_MBIST_RM_SUB_2_rm_sub_1_9_shift                           (12)
#define  SENSIO_SENSIO_MBIST_RM_SUB_2_rm_sub_1_8_shift                           (8)
#define  SENSIO_SENSIO_MBIST_RM_SUB_2_rm_sub_1_7_shift                           (4)
#define  SENSIO_SENSIO_MBIST_RM_SUB_2_rm_sub_1_6_shift                           (0)
#define  SENSIO_SENSIO_MBIST_RM_SUB_2_rm_sub_2_3_mask                            (0xF0000000)
#define  SENSIO_SENSIO_MBIST_RM_SUB_2_rm_sub_2_2_mask                            (0x0F000000)
#define  SENSIO_SENSIO_MBIST_RM_SUB_2_rm_sub_2_1_mask                            (0x00F00000)
#define  SENSIO_SENSIO_MBIST_RM_SUB_2_rm_sub_2_0_mask                            (0x000F0000)
#define  SENSIO_SENSIO_MBIST_RM_SUB_2_rm_sub_1_9_mask                            (0x0000F000)
#define  SENSIO_SENSIO_MBIST_RM_SUB_2_rm_sub_1_8_mask                            (0x00000F00)
#define  SENSIO_SENSIO_MBIST_RM_SUB_2_rm_sub_1_7_mask                            (0x000000F0)
#define  SENSIO_SENSIO_MBIST_RM_SUB_2_rm_sub_1_6_mask                            (0x0000000F)
#define  SENSIO_SENSIO_MBIST_RM_SUB_2_rm_sub_2_3(data)                           (0xF0000000&((data)<<28))
#define  SENSIO_SENSIO_MBIST_RM_SUB_2_rm_sub_2_2(data)                           (0x0F000000&((data)<<24))
#define  SENSIO_SENSIO_MBIST_RM_SUB_2_rm_sub_2_1(data)                           (0x00F00000&((data)<<20))
#define  SENSIO_SENSIO_MBIST_RM_SUB_2_rm_sub_2_0(data)                           (0x000F0000&((data)<<16))
#define  SENSIO_SENSIO_MBIST_RM_SUB_2_rm_sub_1_9(data)                           (0x0000F000&((data)<<12))
#define  SENSIO_SENSIO_MBIST_RM_SUB_2_rm_sub_1_8(data)                           (0x00000F00&((data)<<8))
#define  SENSIO_SENSIO_MBIST_RM_SUB_2_rm_sub_1_7(data)                           (0x000000F0&((data)<<4))
#define  SENSIO_SENSIO_MBIST_RM_SUB_2_rm_sub_1_6(data)                           (0x0000000F&(data))
#define  SENSIO_SENSIO_MBIST_RM_SUB_2_get_rm_sub_2_3(data)                       ((0xF0000000&(data))>>28)
#define  SENSIO_SENSIO_MBIST_RM_SUB_2_get_rm_sub_2_2(data)                       ((0x0F000000&(data))>>24)
#define  SENSIO_SENSIO_MBIST_RM_SUB_2_get_rm_sub_2_1(data)                       ((0x00F00000&(data))>>20)
#define  SENSIO_SENSIO_MBIST_RM_SUB_2_get_rm_sub_2_0(data)                       ((0x000F0000&(data))>>16)
#define  SENSIO_SENSIO_MBIST_RM_SUB_2_get_rm_sub_1_9(data)                       ((0x0000F000&(data))>>12)
#define  SENSIO_SENSIO_MBIST_RM_SUB_2_get_rm_sub_1_8(data)                       ((0x00000F00&(data))>>8)
#define  SENSIO_SENSIO_MBIST_RM_SUB_2_get_rm_sub_1_7(data)                       ((0x000000F0&(data))>>4)
#define  SENSIO_SENSIO_MBIST_RM_SUB_2_get_rm_sub_1_6(data)                       (0x0000000F&(data))

#define  SENSIO_SENSIO_MBIST_RM_SUB_3                                            0x1806B9E0
#define  SENSIO_SENSIO_MBIST_RM_SUB_3_reg_addr                                   "0xB806B9E0"
#define  SENSIO_SENSIO_MBIST_RM_SUB_3_reg                                        0xB806B9E0
#define  SENSIO_SENSIO_MBIST_RM_SUB_3_inst_addr                                  "0x0020"
#define  set_SENSIO_SENSIO_MBIST_RM_SUB_3_reg(data)                              (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_RM_SUB_3_reg)=data)
#define  get_SENSIO_SENSIO_MBIST_RM_SUB_3_reg                                    (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_RM_SUB_3_reg))
#define  SENSIO_SENSIO_MBIST_RM_SUB_3_rm_sub_3_1_shift                           (28)
#define  SENSIO_SENSIO_MBIST_RM_SUB_3_rm_sub_3_0_shift                           (24)
#define  SENSIO_SENSIO_MBIST_RM_SUB_3_rm_sub_2_9_shift                           (20)
#define  SENSIO_SENSIO_MBIST_RM_SUB_3_rm_sub_2_8_shift                           (16)
#define  SENSIO_SENSIO_MBIST_RM_SUB_3_rm_sub_2_7_shift                           (12)
#define  SENSIO_SENSIO_MBIST_RM_SUB_3_rm_sub_2_6_shift                           (8)
#define  SENSIO_SENSIO_MBIST_RM_SUB_3_rm_sub_2_5_shift                           (4)
#define  SENSIO_SENSIO_MBIST_RM_SUB_3_rm_sub_2_4_shift                           (0)
#define  SENSIO_SENSIO_MBIST_RM_SUB_3_rm_sub_3_1_mask                            (0xF0000000)
#define  SENSIO_SENSIO_MBIST_RM_SUB_3_rm_sub_3_0_mask                            (0x0F000000)
#define  SENSIO_SENSIO_MBIST_RM_SUB_3_rm_sub_2_9_mask                            (0x00F00000)
#define  SENSIO_SENSIO_MBIST_RM_SUB_3_rm_sub_2_8_mask                            (0x000F0000)
#define  SENSIO_SENSIO_MBIST_RM_SUB_3_rm_sub_2_7_mask                            (0x0000F000)
#define  SENSIO_SENSIO_MBIST_RM_SUB_3_rm_sub_2_6_mask                            (0x00000F00)
#define  SENSIO_SENSIO_MBIST_RM_SUB_3_rm_sub_2_5_mask                            (0x000000F0)
#define  SENSIO_SENSIO_MBIST_RM_SUB_3_rm_sub_2_4_mask                            (0x0000000F)
#define  SENSIO_SENSIO_MBIST_RM_SUB_3_rm_sub_3_1(data)                           (0xF0000000&((data)<<28))
#define  SENSIO_SENSIO_MBIST_RM_SUB_3_rm_sub_3_0(data)                           (0x0F000000&((data)<<24))
#define  SENSIO_SENSIO_MBIST_RM_SUB_3_rm_sub_2_9(data)                           (0x00F00000&((data)<<20))
#define  SENSIO_SENSIO_MBIST_RM_SUB_3_rm_sub_2_8(data)                           (0x000F0000&((data)<<16))
#define  SENSIO_SENSIO_MBIST_RM_SUB_3_rm_sub_2_7(data)                           (0x0000F000&((data)<<12))
#define  SENSIO_SENSIO_MBIST_RM_SUB_3_rm_sub_2_6(data)                           (0x00000F00&((data)<<8))
#define  SENSIO_SENSIO_MBIST_RM_SUB_3_rm_sub_2_5(data)                           (0x000000F0&((data)<<4))
#define  SENSIO_SENSIO_MBIST_RM_SUB_3_rm_sub_2_4(data)                           (0x0000000F&(data))
#define  SENSIO_SENSIO_MBIST_RM_SUB_3_get_rm_sub_3_1(data)                       ((0xF0000000&(data))>>28)
#define  SENSIO_SENSIO_MBIST_RM_SUB_3_get_rm_sub_3_0(data)                       ((0x0F000000&(data))>>24)
#define  SENSIO_SENSIO_MBIST_RM_SUB_3_get_rm_sub_2_9(data)                       ((0x00F00000&(data))>>20)
#define  SENSIO_SENSIO_MBIST_RM_SUB_3_get_rm_sub_2_8(data)                       ((0x000F0000&(data))>>16)
#define  SENSIO_SENSIO_MBIST_RM_SUB_3_get_rm_sub_2_7(data)                       ((0x0000F000&(data))>>12)
#define  SENSIO_SENSIO_MBIST_RM_SUB_3_get_rm_sub_2_6(data)                       ((0x00000F00&(data))>>8)
#define  SENSIO_SENSIO_MBIST_RM_SUB_3_get_rm_sub_2_5(data)                       ((0x000000F0&(data))>>4)
#define  SENSIO_SENSIO_MBIST_RM_SUB_3_get_rm_sub_2_4(data)                       (0x0000000F&(data))

#define  SENSIO_SENSIO_MBIST_RM_SUB_4                                            0x1806B9E4
#define  SENSIO_SENSIO_MBIST_RM_SUB_4_reg_addr                                   "0xB806B9E4"
#define  SENSIO_SENSIO_MBIST_RM_SUB_4_reg                                        0xB806B9E4
#define  SENSIO_SENSIO_MBIST_RM_SUB_4_inst_addr                                  "0x0021"
#define  set_SENSIO_SENSIO_MBIST_RM_SUB_4_reg(data)                              (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_RM_SUB_4_reg)=data)
#define  get_SENSIO_SENSIO_MBIST_RM_SUB_4_reg                                    (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_RM_SUB_4_reg))
#define  SENSIO_SENSIO_MBIST_RM_SUB_4_rm_sub_3_9_shift                           (28)
#define  SENSIO_SENSIO_MBIST_RM_SUB_4_rm_sub_3_8_shift                           (24)
#define  SENSIO_SENSIO_MBIST_RM_SUB_4_rm_sub_3_7_shift                           (20)
#define  SENSIO_SENSIO_MBIST_RM_SUB_4_rm_sub_3_6_shift                           (16)
#define  SENSIO_SENSIO_MBIST_RM_SUB_4_rm_sub_3_5_shift                           (12)
#define  SENSIO_SENSIO_MBIST_RM_SUB_4_rm_sub_3_4_shift                           (8)
#define  SENSIO_SENSIO_MBIST_RM_SUB_4_rm_sub_3_3_shift                           (4)
#define  SENSIO_SENSIO_MBIST_RM_SUB_4_rm_sub_3_2_shift                           (0)
#define  SENSIO_SENSIO_MBIST_RM_SUB_4_rm_sub_3_9_mask                            (0xF0000000)
#define  SENSIO_SENSIO_MBIST_RM_SUB_4_rm_sub_3_8_mask                            (0x0F000000)
#define  SENSIO_SENSIO_MBIST_RM_SUB_4_rm_sub_3_7_mask                            (0x00F00000)
#define  SENSIO_SENSIO_MBIST_RM_SUB_4_rm_sub_3_6_mask                            (0x000F0000)
#define  SENSIO_SENSIO_MBIST_RM_SUB_4_rm_sub_3_5_mask                            (0x0000F000)
#define  SENSIO_SENSIO_MBIST_RM_SUB_4_rm_sub_3_4_mask                            (0x00000F00)
#define  SENSIO_SENSIO_MBIST_RM_SUB_4_rm_sub_3_3_mask                            (0x000000F0)
#define  SENSIO_SENSIO_MBIST_RM_SUB_4_rm_sub_3_2_mask                            (0x0000000F)
#define  SENSIO_SENSIO_MBIST_RM_SUB_4_rm_sub_3_9(data)                           (0xF0000000&((data)<<28))
#define  SENSIO_SENSIO_MBIST_RM_SUB_4_rm_sub_3_8(data)                           (0x0F000000&((data)<<24))
#define  SENSIO_SENSIO_MBIST_RM_SUB_4_rm_sub_3_7(data)                           (0x00F00000&((data)<<20))
#define  SENSIO_SENSIO_MBIST_RM_SUB_4_rm_sub_3_6(data)                           (0x000F0000&((data)<<16))
#define  SENSIO_SENSIO_MBIST_RM_SUB_4_rm_sub_3_5(data)                           (0x0000F000&((data)<<12))
#define  SENSIO_SENSIO_MBIST_RM_SUB_4_rm_sub_3_4(data)                           (0x00000F00&((data)<<8))
#define  SENSIO_SENSIO_MBIST_RM_SUB_4_rm_sub_3_3(data)                           (0x000000F0&((data)<<4))
#define  SENSIO_SENSIO_MBIST_RM_SUB_4_rm_sub_3_2(data)                           (0x0000000F&(data))
#define  SENSIO_SENSIO_MBIST_RM_SUB_4_get_rm_sub_3_9(data)                       ((0xF0000000&(data))>>28)
#define  SENSIO_SENSIO_MBIST_RM_SUB_4_get_rm_sub_3_8(data)                       ((0x0F000000&(data))>>24)
#define  SENSIO_SENSIO_MBIST_RM_SUB_4_get_rm_sub_3_7(data)                       ((0x00F00000&(data))>>20)
#define  SENSIO_SENSIO_MBIST_RM_SUB_4_get_rm_sub_3_6(data)                       ((0x000F0000&(data))>>16)
#define  SENSIO_SENSIO_MBIST_RM_SUB_4_get_rm_sub_3_5(data)                       ((0x0000F000&(data))>>12)
#define  SENSIO_SENSIO_MBIST_RM_SUB_4_get_rm_sub_3_4(data)                       ((0x00000F00&(data))>>8)
#define  SENSIO_SENSIO_MBIST_RM_SUB_4_get_rm_sub_3_3(data)                       ((0x000000F0&(data))>>4)
#define  SENSIO_SENSIO_MBIST_RM_SUB_4_get_rm_sub_3_2(data)                       (0x0000000F&(data))

#define  SENSIO_SENSIO_MBIST_RME_0                                               0x1806B9F0
#define  SENSIO_SENSIO_MBIST_RME_0_reg_addr                                      "0xB806B9F0"
#define  SENSIO_SENSIO_MBIST_RME_0_reg                                           0xB806B9F0
#define  SENSIO_SENSIO_MBIST_RME_0_inst_addr                                     "0x0022"
#define  set_SENSIO_SENSIO_MBIST_RME_0_reg(data)                                 (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_RME_0_reg)=data)
#define  get_SENSIO_SENSIO_MBIST_RME_0_reg                                       (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_RME_0_reg))
#define  SENSIO_SENSIO_MBIST_RME_0_rme_1_9_shift                                 (19)
#define  SENSIO_SENSIO_MBIST_RME_0_rme_1_8_shift                                 (18)
#define  SENSIO_SENSIO_MBIST_RME_0_rme_1_7_shift                                 (17)
#define  SENSIO_SENSIO_MBIST_RME_0_rme_1_6_shift                                 (16)
#define  SENSIO_SENSIO_MBIST_RME_0_rme_1_5_shift                                 (15)
#define  SENSIO_SENSIO_MBIST_RME_0_rme_1_4_shift                                 (14)
#define  SENSIO_SENSIO_MBIST_RME_0_rme_1_3_shift                                 (13)
#define  SENSIO_SENSIO_MBIST_RME_0_rme_1_2_shift                                 (12)
#define  SENSIO_SENSIO_MBIST_RME_0_rme_1_1_shift                                 (11)
#define  SENSIO_SENSIO_MBIST_RME_0_rme_1_0_shift                                 (10)
#define  SENSIO_SENSIO_MBIST_RME_0_rme_0_9_shift                                 (9)
#define  SENSIO_SENSIO_MBIST_RME_0_rme_0_8_shift                                 (8)
#define  SENSIO_SENSIO_MBIST_RME_0_rme_0_7_shift                                 (7)
#define  SENSIO_SENSIO_MBIST_RME_0_rme_0_6_shift                                 (6)
#define  SENSIO_SENSIO_MBIST_RME_0_rme_0_5_shift                                 (5)
#define  SENSIO_SENSIO_MBIST_RME_0_rme_0_4_shift                                 (4)
#define  SENSIO_SENSIO_MBIST_RME_0_rme_0_3_shift                                 (3)
#define  SENSIO_SENSIO_MBIST_RME_0_rme_0_2_shift                                 (2)
#define  SENSIO_SENSIO_MBIST_RME_0_rme_0_1_shift                                 (1)
#define  SENSIO_SENSIO_MBIST_RME_0_rme_0_0_shift                                 (0)
#define  SENSIO_SENSIO_MBIST_RME_0_rme_1_9_mask                                  (0x00080000)
#define  SENSIO_SENSIO_MBIST_RME_0_rme_1_8_mask                                  (0x00040000)
#define  SENSIO_SENSIO_MBIST_RME_0_rme_1_7_mask                                  (0x00020000)
#define  SENSIO_SENSIO_MBIST_RME_0_rme_1_6_mask                                  (0x00010000)
#define  SENSIO_SENSIO_MBIST_RME_0_rme_1_5_mask                                  (0x00008000)
#define  SENSIO_SENSIO_MBIST_RME_0_rme_1_4_mask                                  (0x00004000)
#define  SENSIO_SENSIO_MBIST_RME_0_rme_1_3_mask                                  (0x00002000)
#define  SENSIO_SENSIO_MBIST_RME_0_rme_1_2_mask                                  (0x00001000)
#define  SENSIO_SENSIO_MBIST_RME_0_rme_1_1_mask                                  (0x00000800)
#define  SENSIO_SENSIO_MBIST_RME_0_rme_1_0_mask                                  (0x00000400)
#define  SENSIO_SENSIO_MBIST_RME_0_rme_0_9_mask                                  (0x00000200)
#define  SENSIO_SENSIO_MBIST_RME_0_rme_0_8_mask                                  (0x00000100)
#define  SENSIO_SENSIO_MBIST_RME_0_rme_0_7_mask                                  (0x00000080)
#define  SENSIO_SENSIO_MBIST_RME_0_rme_0_6_mask                                  (0x00000040)
#define  SENSIO_SENSIO_MBIST_RME_0_rme_0_5_mask                                  (0x00000020)
#define  SENSIO_SENSIO_MBIST_RME_0_rme_0_4_mask                                  (0x00000010)
#define  SENSIO_SENSIO_MBIST_RME_0_rme_0_3_mask                                  (0x00000008)
#define  SENSIO_SENSIO_MBIST_RME_0_rme_0_2_mask                                  (0x00000004)
#define  SENSIO_SENSIO_MBIST_RME_0_rme_0_1_mask                                  (0x00000002)
#define  SENSIO_SENSIO_MBIST_RME_0_rme_0_0_mask                                  (0x00000001)
#define  SENSIO_SENSIO_MBIST_RME_0_rme_1_9(data)                                 (0x00080000&((data)<<19))
#define  SENSIO_SENSIO_MBIST_RME_0_rme_1_8(data)                                 (0x00040000&((data)<<18))
#define  SENSIO_SENSIO_MBIST_RME_0_rme_1_7(data)                                 (0x00020000&((data)<<17))
#define  SENSIO_SENSIO_MBIST_RME_0_rme_1_6(data)                                 (0x00010000&((data)<<16))
#define  SENSIO_SENSIO_MBIST_RME_0_rme_1_5(data)                                 (0x00008000&((data)<<15))
#define  SENSIO_SENSIO_MBIST_RME_0_rme_1_4(data)                                 (0x00004000&((data)<<14))
#define  SENSIO_SENSIO_MBIST_RME_0_rme_1_3(data)                                 (0x00002000&((data)<<13))
#define  SENSIO_SENSIO_MBIST_RME_0_rme_1_2(data)                                 (0x00001000&((data)<<12))
#define  SENSIO_SENSIO_MBIST_RME_0_rme_1_1(data)                                 (0x00000800&((data)<<11))
#define  SENSIO_SENSIO_MBIST_RME_0_rme_1_0(data)                                 (0x00000400&((data)<<10))
#define  SENSIO_SENSIO_MBIST_RME_0_rme_0_9(data)                                 (0x00000200&((data)<<9))
#define  SENSIO_SENSIO_MBIST_RME_0_rme_0_8(data)                                 (0x00000100&((data)<<8))
#define  SENSIO_SENSIO_MBIST_RME_0_rme_0_7(data)                                 (0x00000080&((data)<<7))
#define  SENSIO_SENSIO_MBIST_RME_0_rme_0_6(data)                                 (0x00000040&((data)<<6))
#define  SENSIO_SENSIO_MBIST_RME_0_rme_0_5(data)                                 (0x00000020&((data)<<5))
#define  SENSIO_SENSIO_MBIST_RME_0_rme_0_4(data)                                 (0x00000010&((data)<<4))
#define  SENSIO_SENSIO_MBIST_RME_0_rme_0_3(data)                                 (0x00000008&((data)<<3))
#define  SENSIO_SENSIO_MBIST_RME_0_rme_0_2(data)                                 (0x00000004&((data)<<2))
#define  SENSIO_SENSIO_MBIST_RME_0_rme_0_1(data)                                 (0x00000002&((data)<<1))
#define  SENSIO_SENSIO_MBIST_RME_0_rme_0_0(data)                                 (0x00000001&(data))
#define  SENSIO_SENSIO_MBIST_RME_0_get_rme_1_9(data)                             ((0x00080000&(data))>>19)
#define  SENSIO_SENSIO_MBIST_RME_0_get_rme_1_8(data)                             ((0x00040000&(data))>>18)
#define  SENSIO_SENSIO_MBIST_RME_0_get_rme_1_7(data)                             ((0x00020000&(data))>>17)
#define  SENSIO_SENSIO_MBIST_RME_0_get_rme_1_6(data)                             ((0x00010000&(data))>>16)
#define  SENSIO_SENSIO_MBIST_RME_0_get_rme_1_5(data)                             ((0x00008000&(data))>>15)
#define  SENSIO_SENSIO_MBIST_RME_0_get_rme_1_4(data)                             ((0x00004000&(data))>>14)
#define  SENSIO_SENSIO_MBIST_RME_0_get_rme_1_3(data)                             ((0x00002000&(data))>>13)
#define  SENSIO_SENSIO_MBIST_RME_0_get_rme_1_2(data)                             ((0x00001000&(data))>>12)
#define  SENSIO_SENSIO_MBIST_RME_0_get_rme_1_1(data)                             ((0x00000800&(data))>>11)
#define  SENSIO_SENSIO_MBIST_RME_0_get_rme_1_0(data)                             ((0x00000400&(data))>>10)
#define  SENSIO_SENSIO_MBIST_RME_0_get_rme_0_9(data)                             ((0x00000200&(data))>>9)
#define  SENSIO_SENSIO_MBIST_RME_0_get_rme_0_8(data)                             ((0x00000100&(data))>>8)
#define  SENSIO_SENSIO_MBIST_RME_0_get_rme_0_7(data)                             ((0x00000080&(data))>>7)
#define  SENSIO_SENSIO_MBIST_RME_0_get_rme_0_6(data)                             ((0x00000040&(data))>>6)
#define  SENSIO_SENSIO_MBIST_RME_0_get_rme_0_5(data)                             ((0x00000020&(data))>>5)
#define  SENSIO_SENSIO_MBIST_RME_0_get_rme_0_4(data)                             ((0x00000010&(data))>>4)
#define  SENSIO_SENSIO_MBIST_RME_0_get_rme_0_3(data)                             ((0x00000008&(data))>>3)
#define  SENSIO_SENSIO_MBIST_RME_0_get_rme_0_2(data)                             ((0x00000004&(data))>>2)
#define  SENSIO_SENSIO_MBIST_RME_0_get_rme_0_1(data)                             ((0x00000002&(data))>>1)
#define  SENSIO_SENSIO_MBIST_RME_0_get_rme_0_0(data)                             (0x00000001&(data))

#define  SENSIO_SENSIO_MBIST_RME_1                                               0x1806B9F4
#define  SENSIO_SENSIO_MBIST_RME_1_reg_addr                                      "0xB806B9F4"
#define  SENSIO_SENSIO_MBIST_RME_1_reg                                           0xB806B9F4
#define  SENSIO_SENSIO_MBIST_RME_1_inst_addr                                     "0x0023"
#define  set_SENSIO_SENSIO_MBIST_RME_1_reg(data)                                 (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_RME_1_reg)=data)
#define  get_SENSIO_SENSIO_MBIST_RME_1_reg                                       (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_RME_1_reg))
#define  SENSIO_SENSIO_MBIST_RME_1_rme_3_9_shift                                 (19)
#define  SENSIO_SENSIO_MBIST_RME_1_rme_3_8_shift                                 (18)
#define  SENSIO_SENSIO_MBIST_RME_1_rme_3_7_shift                                 (17)
#define  SENSIO_SENSIO_MBIST_RME_1_rme_3_6_shift                                 (16)
#define  SENSIO_SENSIO_MBIST_RME_1_rme_3_5_shift                                 (15)
#define  SENSIO_SENSIO_MBIST_RME_1_rme_3_4_shift                                 (14)
#define  SENSIO_SENSIO_MBIST_RME_1_rme_3_3_shift                                 (13)
#define  SENSIO_SENSIO_MBIST_RME_1_rme_3_2_shift                                 (12)
#define  SENSIO_SENSIO_MBIST_RME_1_rme_3_1_shift                                 (11)
#define  SENSIO_SENSIO_MBIST_RME_1_rme_3_0_shift                                 (10)
#define  SENSIO_SENSIO_MBIST_RME_1_rme_2_9_shift                                 (9)
#define  SENSIO_SENSIO_MBIST_RME_1_rme_2_8_shift                                 (8)
#define  SENSIO_SENSIO_MBIST_RME_1_rme_2_7_shift                                 (7)
#define  SENSIO_SENSIO_MBIST_RME_1_rme_2_6_shift                                 (6)
#define  SENSIO_SENSIO_MBIST_RME_1_rme_2_5_shift                                 (5)
#define  SENSIO_SENSIO_MBIST_RME_1_rme_2_4_shift                                 (4)
#define  SENSIO_SENSIO_MBIST_RME_1_rme_2_3_shift                                 (3)
#define  SENSIO_SENSIO_MBIST_RME_1_rme_2_2_shift                                 (2)
#define  SENSIO_SENSIO_MBIST_RME_1_rme_2_1_shift                                 (1)
#define  SENSIO_SENSIO_MBIST_RME_1_rme_2_0_shift                                 (0)
#define  SENSIO_SENSIO_MBIST_RME_1_rme_3_9_mask                                  (0x00080000)
#define  SENSIO_SENSIO_MBIST_RME_1_rme_3_8_mask                                  (0x00040000)
#define  SENSIO_SENSIO_MBIST_RME_1_rme_3_7_mask                                  (0x00020000)
#define  SENSIO_SENSIO_MBIST_RME_1_rme_3_6_mask                                  (0x00010000)
#define  SENSIO_SENSIO_MBIST_RME_1_rme_3_5_mask                                  (0x00008000)
#define  SENSIO_SENSIO_MBIST_RME_1_rme_3_4_mask                                  (0x00004000)
#define  SENSIO_SENSIO_MBIST_RME_1_rme_3_3_mask                                  (0x00002000)
#define  SENSIO_SENSIO_MBIST_RME_1_rme_3_2_mask                                  (0x00001000)
#define  SENSIO_SENSIO_MBIST_RME_1_rme_3_1_mask                                  (0x00000800)
#define  SENSIO_SENSIO_MBIST_RME_1_rme_3_0_mask                                  (0x00000400)
#define  SENSIO_SENSIO_MBIST_RME_1_rme_2_9_mask                                  (0x00000200)
#define  SENSIO_SENSIO_MBIST_RME_1_rme_2_8_mask                                  (0x00000100)
#define  SENSIO_SENSIO_MBIST_RME_1_rme_2_7_mask                                  (0x00000080)
#define  SENSIO_SENSIO_MBIST_RME_1_rme_2_6_mask                                  (0x00000040)
#define  SENSIO_SENSIO_MBIST_RME_1_rme_2_5_mask                                  (0x00000020)
#define  SENSIO_SENSIO_MBIST_RME_1_rme_2_4_mask                                  (0x00000010)
#define  SENSIO_SENSIO_MBIST_RME_1_rme_2_3_mask                                  (0x00000008)
#define  SENSIO_SENSIO_MBIST_RME_1_rme_2_2_mask                                  (0x00000004)
#define  SENSIO_SENSIO_MBIST_RME_1_rme_2_1_mask                                  (0x00000002)
#define  SENSIO_SENSIO_MBIST_RME_1_rme_2_0_mask                                  (0x00000001)
#define  SENSIO_SENSIO_MBIST_RME_1_rme_3_9(data)                                 (0x00080000&((data)<<19))
#define  SENSIO_SENSIO_MBIST_RME_1_rme_3_8(data)                                 (0x00040000&((data)<<18))
#define  SENSIO_SENSIO_MBIST_RME_1_rme_3_7(data)                                 (0x00020000&((data)<<17))
#define  SENSIO_SENSIO_MBIST_RME_1_rme_3_6(data)                                 (0x00010000&((data)<<16))
#define  SENSIO_SENSIO_MBIST_RME_1_rme_3_5(data)                                 (0x00008000&((data)<<15))
#define  SENSIO_SENSIO_MBIST_RME_1_rme_3_4(data)                                 (0x00004000&((data)<<14))
#define  SENSIO_SENSIO_MBIST_RME_1_rme_3_3(data)                                 (0x00002000&((data)<<13))
#define  SENSIO_SENSIO_MBIST_RME_1_rme_3_2(data)                                 (0x00001000&((data)<<12))
#define  SENSIO_SENSIO_MBIST_RME_1_rme_3_1(data)                                 (0x00000800&((data)<<11))
#define  SENSIO_SENSIO_MBIST_RME_1_rme_3_0(data)                                 (0x00000400&((data)<<10))
#define  SENSIO_SENSIO_MBIST_RME_1_rme_2_9(data)                                 (0x00000200&((data)<<9))
#define  SENSIO_SENSIO_MBIST_RME_1_rme_2_8(data)                                 (0x00000100&((data)<<8))
#define  SENSIO_SENSIO_MBIST_RME_1_rme_2_7(data)                                 (0x00000080&((data)<<7))
#define  SENSIO_SENSIO_MBIST_RME_1_rme_2_6(data)                                 (0x00000040&((data)<<6))
#define  SENSIO_SENSIO_MBIST_RME_1_rme_2_5(data)                                 (0x00000020&((data)<<5))
#define  SENSIO_SENSIO_MBIST_RME_1_rme_2_4(data)                                 (0x00000010&((data)<<4))
#define  SENSIO_SENSIO_MBIST_RME_1_rme_2_3(data)                                 (0x00000008&((data)<<3))
#define  SENSIO_SENSIO_MBIST_RME_1_rme_2_2(data)                                 (0x00000004&((data)<<2))
#define  SENSIO_SENSIO_MBIST_RME_1_rme_2_1(data)                                 (0x00000002&((data)<<1))
#define  SENSIO_SENSIO_MBIST_RME_1_rme_2_0(data)                                 (0x00000001&(data))
#define  SENSIO_SENSIO_MBIST_RME_1_get_rme_3_9(data)                             ((0x00080000&(data))>>19)
#define  SENSIO_SENSIO_MBIST_RME_1_get_rme_3_8(data)                             ((0x00040000&(data))>>18)
#define  SENSIO_SENSIO_MBIST_RME_1_get_rme_3_7(data)                             ((0x00020000&(data))>>17)
#define  SENSIO_SENSIO_MBIST_RME_1_get_rme_3_6(data)                             ((0x00010000&(data))>>16)
#define  SENSIO_SENSIO_MBIST_RME_1_get_rme_3_5(data)                             ((0x00008000&(data))>>15)
#define  SENSIO_SENSIO_MBIST_RME_1_get_rme_3_4(data)                             ((0x00004000&(data))>>14)
#define  SENSIO_SENSIO_MBIST_RME_1_get_rme_3_3(data)                             ((0x00002000&(data))>>13)
#define  SENSIO_SENSIO_MBIST_RME_1_get_rme_3_2(data)                             ((0x00001000&(data))>>12)
#define  SENSIO_SENSIO_MBIST_RME_1_get_rme_3_1(data)                             ((0x00000800&(data))>>11)
#define  SENSIO_SENSIO_MBIST_RME_1_get_rme_3_0(data)                             ((0x00000400&(data))>>10)
#define  SENSIO_SENSIO_MBIST_RME_1_get_rme_2_9(data)                             ((0x00000200&(data))>>9)
#define  SENSIO_SENSIO_MBIST_RME_1_get_rme_2_8(data)                             ((0x00000100&(data))>>8)
#define  SENSIO_SENSIO_MBIST_RME_1_get_rme_2_7(data)                             ((0x00000080&(data))>>7)
#define  SENSIO_SENSIO_MBIST_RME_1_get_rme_2_6(data)                             ((0x00000040&(data))>>6)
#define  SENSIO_SENSIO_MBIST_RME_1_get_rme_2_5(data)                             ((0x00000020&(data))>>5)
#define  SENSIO_SENSIO_MBIST_RME_1_get_rme_2_4(data)                             ((0x00000010&(data))>>4)
#define  SENSIO_SENSIO_MBIST_RME_1_get_rme_2_3(data)                             ((0x00000008&(data))>>3)
#define  SENSIO_SENSIO_MBIST_RME_1_get_rme_2_2(data)                             ((0x00000004&(data))>>2)
#define  SENSIO_SENSIO_MBIST_RME_1_get_rme_2_1(data)                             ((0x00000002&(data))>>1)
#define  SENSIO_SENSIO_MBIST_RME_1_get_rme_2_0(data)                             (0x00000001&(data))

#define  SENSIO_SENSIO_MBIST_RME_SUB_0                                           0x1806B9F8
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_reg_addr                                  "0xB806B9F8"
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_reg                                       0xB806B9F8
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_inst_addr                                 "0x0024"
#define  set_SENSIO_SENSIO_MBIST_RME_SUB_0_reg(data)                             (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_RME_SUB_0_reg)=data)
#define  get_SENSIO_SENSIO_MBIST_RME_SUB_0_reg                                   (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_RME_SUB_0_reg))
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_1_9_shift                         (19)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_1_8_shift                         (18)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_1_7_shift                         (17)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_1_6_shift                         (16)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_1_5_shift                         (15)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_1_4_shift                         (14)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_1_3_shift                         (13)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_1_2_shift                         (12)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_1_1_shift                         (11)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_1_0_shift                         (10)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_0_9_shift                         (9)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_0_8_shift                         (8)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_0_7_shift                         (7)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_0_6_shift                         (6)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_0_5_shift                         (5)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_0_4_shift                         (4)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_0_3_shift                         (3)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_0_2_shift                         (2)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_0_1_shift                         (1)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_0_0_shift                         (0)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_1_9_mask                          (0x00080000)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_1_8_mask                          (0x00040000)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_1_7_mask                          (0x00020000)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_1_6_mask                          (0x00010000)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_1_5_mask                          (0x00008000)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_1_4_mask                          (0x00004000)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_1_3_mask                          (0x00002000)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_1_2_mask                          (0x00001000)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_1_1_mask                          (0x00000800)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_1_0_mask                          (0x00000400)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_0_9_mask                          (0x00000200)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_0_8_mask                          (0x00000100)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_0_7_mask                          (0x00000080)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_0_6_mask                          (0x00000040)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_0_5_mask                          (0x00000020)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_0_4_mask                          (0x00000010)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_0_3_mask                          (0x00000008)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_0_2_mask                          (0x00000004)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_0_1_mask                          (0x00000002)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_0_0_mask                          (0x00000001)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_1_9(data)                         (0x00080000&((data)<<19))
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_1_8(data)                         (0x00040000&((data)<<18))
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_1_7(data)                         (0x00020000&((data)<<17))
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_1_6(data)                         (0x00010000&((data)<<16))
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_1_5(data)                         (0x00008000&((data)<<15))
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_1_4(data)                         (0x00004000&((data)<<14))
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_1_3(data)                         (0x00002000&((data)<<13))
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_1_2(data)                         (0x00001000&((data)<<12))
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_1_1(data)                         (0x00000800&((data)<<11))
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_1_0(data)                         (0x00000400&((data)<<10))
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_0_9(data)                         (0x00000200&((data)<<9))
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_0_8(data)                         (0x00000100&((data)<<8))
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_0_7(data)                         (0x00000080&((data)<<7))
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_0_6(data)                         (0x00000040&((data)<<6))
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_0_5(data)                         (0x00000020&((data)<<5))
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_0_4(data)                         (0x00000010&((data)<<4))
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_0_3(data)                         (0x00000008&((data)<<3))
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_0_2(data)                         (0x00000004&((data)<<2))
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_0_1(data)                         (0x00000002&((data)<<1))
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_rme_sub_0_0(data)                         (0x00000001&(data))
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_get_rme_sub_1_9(data)                     ((0x00080000&(data))>>19)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_get_rme_sub_1_8(data)                     ((0x00040000&(data))>>18)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_get_rme_sub_1_7(data)                     ((0x00020000&(data))>>17)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_get_rme_sub_1_6(data)                     ((0x00010000&(data))>>16)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_get_rme_sub_1_5(data)                     ((0x00008000&(data))>>15)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_get_rme_sub_1_4(data)                     ((0x00004000&(data))>>14)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_get_rme_sub_1_3(data)                     ((0x00002000&(data))>>13)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_get_rme_sub_1_2(data)                     ((0x00001000&(data))>>12)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_get_rme_sub_1_1(data)                     ((0x00000800&(data))>>11)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_get_rme_sub_1_0(data)                     ((0x00000400&(data))>>10)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_get_rme_sub_0_9(data)                     ((0x00000200&(data))>>9)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_get_rme_sub_0_8(data)                     ((0x00000100&(data))>>8)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_get_rme_sub_0_7(data)                     ((0x00000080&(data))>>7)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_get_rme_sub_0_6(data)                     ((0x00000040&(data))>>6)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_get_rme_sub_0_5(data)                     ((0x00000020&(data))>>5)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_get_rme_sub_0_4(data)                     ((0x00000010&(data))>>4)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_get_rme_sub_0_3(data)                     ((0x00000008&(data))>>3)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_get_rme_sub_0_2(data)                     ((0x00000004&(data))>>2)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_get_rme_sub_0_1(data)                     ((0x00000002&(data))>>1)
#define  SENSIO_SENSIO_MBIST_RME_SUB_0_get_rme_sub_0_0(data)                     (0x00000001&(data))

#define  SENSIO_SENSIO_MBIST_RME_SUB_1                                           0x1806B9FC
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_reg_addr                                  "0xB806B9FC"
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_reg                                       0xB806B9FC
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_inst_addr                                 "0x0025"
#define  set_SENSIO_SENSIO_MBIST_RME_SUB_1_reg(data)                             (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_RME_SUB_1_reg)=data)
#define  get_SENSIO_SENSIO_MBIST_RME_SUB_1_reg                                   (*((volatile unsigned int*)SENSIO_SENSIO_MBIST_RME_SUB_1_reg))
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_3_9_shift                         (19)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_3_8_shift                         (18)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_3_7_shift                         (17)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_3_6_shift                         (16)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_3_5_shift                         (15)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_3_4_shift                         (14)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_3_3_shift                         (13)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_3_2_shift                         (12)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_3_1_shift                         (11)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_3_0_shift                         (10)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_2_9_shift                         (9)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_2_8_shift                         (8)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_2_7_shift                         (7)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_2_6_shift                         (6)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_2_5_shift                         (5)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_2_4_shift                         (4)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_2_3_shift                         (3)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_2_2_shift                         (2)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_2_1_shift                         (1)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_2_0_shift                         (0)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_3_9_mask                          (0x00080000)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_3_8_mask                          (0x00040000)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_3_7_mask                          (0x00020000)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_3_6_mask                          (0x00010000)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_3_5_mask                          (0x00008000)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_3_4_mask                          (0x00004000)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_3_3_mask                          (0x00002000)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_3_2_mask                          (0x00001000)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_3_1_mask                          (0x00000800)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_3_0_mask                          (0x00000400)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_2_9_mask                          (0x00000200)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_2_8_mask                          (0x00000100)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_2_7_mask                          (0x00000080)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_2_6_mask                          (0x00000040)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_2_5_mask                          (0x00000020)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_2_4_mask                          (0x00000010)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_2_3_mask                          (0x00000008)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_2_2_mask                          (0x00000004)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_2_1_mask                          (0x00000002)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_2_0_mask                          (0x00000001)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_3_9(data)                         (0x00080000&((data)<<19))
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_3_8(data)                         (0x00040000&((data)<<18))
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_3_7(data)                         (0x00020000&((data)<<17))
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_3_6(data)                         (0x00010000&((data)<<16))
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_3_5(data)                         (0x00008000&((data)<<15))
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_3_4(data)                         (0x00004000&((data)<<14))
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_3_3(data)                         (0x00002000&((data)<<13))
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_3_2(data)                         (0x00001000&((data)<<12))
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_3_1(data)                         (0x00000800&((data)<<11))
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_3_0(data)                         (0x00000400&((data)<<10))
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_2_9(data)                         (0x00000200&((data)<<9))
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_2_8(data)                         (0x00000100&((data)<<8))
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_2_7(data)                         (0x00000080&((data)<<7))
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_2_6(data)                         (0x00000040&((data)<<6))
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_2_5(data)                         (0x00000020&((data)<<5))
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_2_4(data)                         (0x00000010&((data)<<4))
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_2_3(data)                         (0x00000008&((data)<<3))
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_2_2(data)                         (0x00000004&((data)<<2))
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_2_1(data)                         (0x00000002&((data)<<1))
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_rme_sub_2_0(data)                         (0x00000001&(data))
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_get_rme_sub_3_9(data)                     ((0x00080000&(data))>>19)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_get_rme_sub_3_8(data)                     ((0x00040000&(data))>>18)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_get_rme_sub_3_7(data)                     ((0x00020000&(data))>>17)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_get_rme_sub_3_6(data)                     ((0x00010000&(data))>>16)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_get_rme_sub_3_5(data)                     ((0x00008000&(data))>>15)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_get_rme_sub_3_4(data)                     ((0x00004000&(data))>>14)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_get_rme_sub_3_3(data)                     ((0x00002000&(data))>>13)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_get_rme_sub_3_2(data)                     ((0x00001000&(data))>>12)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_get_rme_sub_3_1(data)                     ((0x00000800&(data))>>11)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_get_rme_sub_3_0(data)                     ((0x00000400&(data))>>10)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_get_rme_sub_2_9(data)                     ((0x00000200&(data))>>9)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_get_rme_sub_2_8(data)                     ((0x00000100&(data))>>8)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_get_rme_sub_2_7(data)                     ((0x00000080&(data))>>7)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_get_rme_sub_2_6(data)                     ((0x00000040&(data))>>6)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_get_rme_sub_2_5(data)                     ((0x00000020&(data))>>5)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_get_rme_sub_2_4(data)                     ((0x00000010&(data))>>4)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_get_rme_sub_2_3(data)                     ((0x00000008&(data))>>3)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_get_rme_sub_2_2(data)                     ((0x00000004&(data))>>2)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_get_rme_sub_2_1(data)                     ((0x00000002&(data))>>1)
#define  SENSIO_SENSIO_MBIST_RME_SUB_1_get_rme_sub_2_0(data)                     (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======SENSIO register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  re_decom_en:1;
        RBus_UInt32  res2:21;
        RBus_UInt32  vflip_en:1;
        RBus_UInt32  force_ctsfifo_rstn_sensio:1;
        RBus_UInt32  en_ctsfifo_vsrst_sensio:1;
        RBus_UInt32  en_ctsfifo_bypass_sensio:1;
        RBus_UInt32  res3:4;
    };
}sensio_sensio_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  sensio_ivsize:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  sensio_ihsize:12;
    };
}sensio_sensio_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  res2:5;
        RBus_UInt32  sensio_double_apply:1;
        RBus_UInt32  sensio_double_en:1;
        RBus_UInt32  sensio_read_sel:1;
        RBus_UInt32  res3:14;
        RBus_UInt32  sensio_sub_double_apply:1;
        RBus_UInt32  sensio_sub_double_en:1;
    };
}sensio_sensio_ctrl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  main_decomp_10bit:2;
    };
}sensio_decomp_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  sub_vflip_en:1;
        RBus_UInt32  sub_decomp_10bit:2;
        RBus_UInt32  sub_re_decom_en:1;
        RBus_UInt32  res2:1;
    };
}sensio_sub_vp9_decomp_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  sub_v_d_ivsize:11;
        RBus_UInt32  res2:4;
        RBus_UInt32  sub_v_d_ihsize:12;
    };
}sensio_sub_vp9_decomp_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  real_vp9_vend:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  real_vp9_vstart:12;
    };
}sensio_vp9_decomp_v_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  sub_real_vp9_vend:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  sub_real_vp9_vstart:11;
    };
}sensio_sub_vp9_decomp_v_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  hs_width:6;
        RBus_UInt32  res2:3;
        RBus_UInt32  h_total:13;
    };
}sensio_sensio_tim_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  v_den_st:8;
        RBus_UInt32  res2:4;
        RBus_UInt32  h_den_st:12;
    };
}sensio_sensio_tim_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  sub_hs_width:6;
        RBus_UInt32  res2:3;
        RBus_UInt32  sub_h_total:13;
    };
}sensio_sub_sensio_tim_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sub_v_den_st:8;
        RBus_UInt32  res2:4;
        RBus_UInt32  sub_h_den_st:12;
    };
}sensio_sub_sensio_tim_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  bist_fail_1_9:1;
        RBus_UInt32  bist_fail_1_8:1;
        RBus_UInt32  bist_fail_1_7:1;
        RBus_UInt32  bist_fail_1_6:1;
        RBus_UInt32  bist_fail_1_5:1;
        RBus_UInt32  bist_fail_1_4:1;
        RBus_UInt32  bist_fail_1_3:1;
        RBus_UInt32  bist_fail_1_2:1;
        RBus_UInt32  bist_fail_1_1:1;
        RBus_UInt32  bist_fail_1_0:1;
        RBus_UInt32  bist_fail_0_9:1;
        RBus_UInt32  bist_fail_0_8:1;
        RBus_UInt32  bist_fail_0_7:1;
        RBus_UInt32  bist_fail_0_6:1;
        RBus_UInt32  bist_fail_0_5:1;
        RBus_UInt32  bist_fail_0_4:1;
        RBus_UInt32  bist_fail_0_3:1;
        RBus_UInt32  bist_fail_0_2:1;
        RBus_UInt32  bist_fail_0_1:1;
        RBus_UInt32  bist_fail_0_0:1;
    };
}sensio_sensio_mbist_fail_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  bist_fail_3_9:1;
        RBus_UInt32  bist_fail_3_8:1;
        RBus_UInt32  bist_fail_3_7:1;
        RBus_UInt32  bist_fail_3_6:1;
        RBus_UInt32  bist_fail_3_5:1;
        RBus_UInt32  bist_fail_3_4:1;
        RBus_UInt32  bist_fail_3_3:1;
        RBus_UInt32  bist_fail_3_2:1;
        RBus_UInt32  bist_fail_3_1:1;
        RBus_UInt32  bist_fail_3_0:1;
        RBus_UInt32  bist_fail_2_9:1;
        RBus_UInt32  bist_fail_2_8:1;
        RBus_UInt32  bist_fail_2_7:1;
        RBus_UInt32  bist_fail_2_6:1;
        RBus_UInt32  bist_fail_2_5:1;
        RBus_UInt32  bist_fail_2_4:1;
        RBus_UInt32  bist_fail_2_3:1;
        RBus_UInt32  bist_fail_2_2:1;
        RBus_UInt32  bist_fail_2_1:1;
        RBus_UInt32  bist_fail_2_0:1;
    };
}sensio_sensio_mbist_fail_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  bist_fail_sub_1_9:1;
        RBus_UInt32  bist_fail_sub_1_8:1;
        RBus_UInt32  bist_fail_sub_1_7:1;
        RBus_UInt32  bist_fail_sub_1_6:1;
        RBus_UInt32  bist_fail_sub_1_5:1;
        RBus_UInt32  bist_fail_sub_1_4:1;
        RBus_UInt32  bist_fail_sub_1_3:1;
        RBus_UInt32  bist_fail_sub_1_2:1;
        RBus_UInt32  bist_fail_sub_1_1:1;
        RBus_UInt32  bist_fail_sub_1_0:1;
        RBus_UInt32  bist_fail_sub_0_9:1;
        RBus_UInt32  bist_fail_sub_0_8:1;
        RBus_UInt32  bist_fail_sub_0_7:1;
        RBus_UInt32  bist_fail_sub_0_6:1;
        RBus_UInt32  bist_fail_sub_0_5:1;
        RBus_UInt32  bist_fail_sub_0_4:1;
        RBus_UInt32  bist_fail_sub_0_3:1;
        RBus_UInt32  bist_fail_sub_0_2:1;
        RBus_UInt32  bist_fail_sub_0_1:1;
        RBus_UInt32  bist_fail_sub_0_0:1;
    };
}sensio_sensio_mbist_fail_sub_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  bist_fail_sub_3_9:1;
        RBus_UInt32  bist_fail_sub_3_8:1;
        RBus_UInt32  bist_fail_sub_3_7:1;
        RBus_UInt32  bist_fail_sub_3_6:1;
        RBus_UInt32  bist_fail_sub_3_5:1;
        RBus_UInt32  bist_fail_sub_3_4:1;
        RBus_UInt32  bist_fail_sub_3_3:1;
        RBus_UInt32  bist_fail_sub_3_2:1;
        RBus_UInt32  bist_fail_sub_3_1:1;
        RBus_UInt32  bist_fail_sub_3_0:1;
        RBus_UInt32  bist_fail_sub_2_9:1;
        RBus_UInt32  bist_fail_sub_2_8:1;
        RBus_UInt32  bist_fail_sub_2_7:1;
        RBus_UInt32  bist_fail_sub_2_6:1;
        RBus_UInt32  bist_fail_sub_2_5:1;
        RBus_UInt32  bist_fail_sub_2_4:1;
        RBus_UInt32  bist_fail_sub_2_3:1;
        RBus_UInt32  bist_fail_sub_2_2:1;
        RBus_UInt32  bist_fail_sub_2_1:1;
        RBus_UInt32  bist_fail_sub_2_0:1;
    };
}sensio_sensio_mbist_fail_sub_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  drf_bist_fail_1_9:1;
        RBus_UInt32  drf_bist_fail_1_8:1;
        RBus_UInt32  drf_bist_fail_1_7:1;
        RBus_UInt32  drf_bist_fail_1_6:1;
        RBus_UInt32  drf_bist_fail_1_5:1;
        RBus_UInt32  drf_bist_fail_1_4:1;
        RBus_UInt32  drf_bist_fail_1_3:1;
        RBus_UInt32  drf_bist_fail_1_2:1;
        RBus_UInt32  drf_bist_fail_1_1:1;
        RBus_UInt32  drf_bist_fail_1_0:1;
        RBus_UInt32  drf_bist_fail_0_9:1;
        RBus_UInt32  drf_bist_fail_0_8:1;
        RBus_UInt32  drf_bist_fail_0_7:1;
        RBus_UInt32  drf_bist_fail_0_6:1;
        RBus_UInt32  drf_bist_fail_0_5:1;
        RBus_UInt32  drf_bist_fail_0_4:1;
        RBus_UInt32  drf_bist_fail_0_3:1;
        RBus_UInt32  drf_bist_fail_0_2:1;
        RBus_UInt32  drf_bist_fail_0_1:1;
        RBus_UInt32  drf_bist_fail_0_0:1;
    };
}sensio_sensio_mbist_drf_fail_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  drf_bist_fail_3_9:1;
        RBus_UInt32  drf_bist_fail_3_8:1;
        RBus_UInt32  drf_bist_fail_3_7:1;
        RBus_UInt32  drf_bist_fail_3_6:1;
        RBus_UInt32  drf_bist_fail_3_5:1;
        RBus_UInt32  drf_bist_fail_3_4:1;
        RBus_UInt32  drf_bist_fail_3_3:1;
        RBus_UInt32  drf_bist_fail_3_2:1;
        RBus_UInt32  drf_bist_fail_3_1:1;
        RBus_UInt32  drf_bist_fail_3_0:1;
        RBus_UInt32  drf_bist_fail_2_9:1;
        RBus_UInt32  drf_bist_fail_2_8:1;
        RBus_UInt32  drf_bist_fail_2_7:1;
        RBus_UInt32  drf_bist_fail_2_6:1;
        RBus_UInt32  drf_bist_fail_2_5:1;
        RBus_UInt32  drf_bist_fail_2_4:1;
        RBus_UInt32  drf_bist_fail_2_3:1;
        RBus_UInt32  drf_bist_fail_2_2:1;
        RBus_UInt32  drf_bist_fail_2_1:1;
        RBus_UInt32  drf_bist_fail_2_0:1;
    };
}sensio_sensio_mbist_drf_fail_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  drf_bist_fail_sub_1_9:1;
        RBus_UInt32  drf_bist_fail_sub_1_8:1;
        RBus_UInt32  drf_bist_fail_sub_1_7:1;
        RBus_UInt32  drf_bist_fail_sub_1_6:1;
        RBus_UInt32  drf_bist_fail_sub_1_5:1;
        RBus_UInt32  drf_bist_fail_sub_1_4:1;
        RBus_UInt32  drf_bist_fail_sub_1_3:1;
        RBus_UInt32  drf_bist_fail_sub_1_2:1;
        RBus_UInt32  drf_bist_fail_sub_1_1:1;
        RBus_UInt32  drf_bist_fail_sub_1_0:1;
        RBus_UInt32  drf_bist_fail_sub_0_9:1;
        RBus_UInt32  drf_bist_fail_sub_0_8:1;
        RBus_UInt32  drf_bist_fail_sub_0_7:1;
        RBus_UInt32  drf_bist_fail_sub_0_6:1;
        RBus_UInt32  drf_bist_fail_sub_0_5:1;
        RBus_UInt32  drf_bist_fail_sub_0_4:1;
        RBus_UInt32  drf_bist_fail_sub_0_3:1;
        RBus_UInt32  drf_bist_fail_sub_0_2:1;
        RBus_UInt32  drf_bist_fail_sub_0_1:1;
        RBus_UInt32  drf_bist_fail_sub_0_0:1;
    };
}sensio_sensio_mbist_drf_fail_sub_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  drf_bist_fail_sub_3_9:1;
        RBus_UInt32  drf_bist_fail_sub_3_8:1;
        RBus_UInt32  drf_bist_fail_sub_3_7:1;
        RBus_UInt32  drf_bist_fail_sub_3_6:1;
        RBus_UInt32  drf_bist_fail_sub_3_5:1;
        RBus_UInt32  drf_bist_fail_sub_3_4:1;
        RBus_UInt32  drf_bist_fail_sub_3_3:1;
        RBus_UInt32  drf_bist_fail_sub_3_2:1;
        RBus_UInt32  drf_bist_fail_sub_3_1:1;
        RBus_UInt32  drf_bist_fail_sub_3_0:1;
        RBus_UInt32  drf_bist_fail_sub_2_9:1;
        RBus_UInt32  drf_bist_fail_sub_2_8:1;
        RBus_UInt32  drf_bist_fail_sub_2_7:1;
        RBus_UInt32  drf_bist_fail_sub_2_6:1;
        RBus_UInt32  drf_bist_fail_sub_2_5:1;
        RBus_UInt32  drf_bist_fail_sub_2_4:1;
        RBus_UInt32  drf_bist_fail_sub_2_3:1;
        RBus_UInt32  drf_bist_fail_sub_2_2:1;
        RBus_UInt32  drf_bist_fail_sub_2_1:1;
        RBus_UInt32  drf_bist_fail_sub_2_0:1;
    };
}sensio_sensio_mbist_drf_fail_sub_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  ls_1_9:1;
        RBus_UInt32  ls_1_8:1;
        RBus_UInt32  ls_1_7:1;
        RBus_UInt32  ls_1_6:1;
        RBus_UInt32  ls_1_5:1;
        RBus_UInt32  ls_1_4:1;
        RBus_UInt32  ls_1_3:1;
        RBus_UInt32  ls_1_2:1;
        RBus_UInt32  ls_1_1:1;
        RBus_UInt32  ls_1_0:1;
        RBus_UInt32  ls_0_9:1;
        RBus_UInt32  ls_0_8:1;
        RBus_UInt32  ls_0_7:1;
        RBus_UInt32  ls_0_6:1;
        RBus_UInt32  ls_0_5:1;
        RBus_UInt32  ls_0_4:1;
        RBus_UInt32  ls_0_3:1;
        RBus_UInt32  ls_0_2:1;
        RBus_UInt32  ls_0_1:1;
        RBus_UInt32  ls_0_0:1;
    };
}sensio_sensio_mbist_ls_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  ls_3_9:1;
        RBus_UInt32  ls_3_8:1;
        RBus_UInt32  ls_3_7:1;
        RBus_UInt32  ls_3_6:1;
        RBus_UInt32  ls_3_5:1;
        RBus_UInt32  ls_3_4:1;
        RBus_UInt32  ls_3_3:1;
        RBus_UInt32  ls_3_2:1;
        RBus_UInt32  ls_3_1:1;
        RBus_UInt32  ls_3_0:1;
        RBus_UInt32  ls_2_9:1;
        RBus_UInt32  ls_2_8:1;
        RBus_UInt32  ls_2_7:1;
        RBus_UInt32  ls_2_6:1;
        RBus_UInt32  ls_2_5:1;
        RBus_UInt32  ls_2_4:1;
        RBus_UInt32  ls_2_3:1;
        RBus_UInt32  ls_2_2:1;
        RBus_UInt32  ls_2_1:1;
        RBus_UInt32  ls_2_0:1;
    };
}sensio_sensio_mbist_ls_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  ls_sub_1_9:1;
        RBus_UInt32  ls_sub_1_8:1;
        RBus_UInt32  ls_sub_1_7:1;
        RBus_UInt32  ls_sub_1_6:1;
        RBus_UInt32  ls_sub_1_5:1;
        RBus_UInt32  ls_sub_1_4:1;
        RBus_UInt32  ls_sub_1_3:1;
        RBus_UInt32  ls_sub_1_2:1;
        RBus_UInt32  ls_sub_1_1:1;
        RBus_UInt32  ls_sub_1_0:1;
        RBus_UInt32  ls_sub_0_9:1;
        RBus_UInt32  ls_sub_0_8:1;
        RBus_UInt32  ls_sub_0_7:1;
        RBus_UInt32  ls_sub_0_6:1;
        RBus_UInt32  ls_sub_0_5:1;
        RBus_UInt32  ls_sub_0_4:1;
        RBus_UInt32  ls_sub_0_3:1;
        RBus_UInt32  ls_sub_0_2:1;
        RBus_UInt32  ls_sub_0_1:1;
        RBus_UInt32  ls_sub_0_0:1;
    };
}sensio_sensio_mbist_ls_sub_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  ls_sub_3_9:1;
        RBus_UInt32  ls_sub_3_8:1;
        RBus_UInt32  ls_sub_3_7:1;
        RBus_UInt32  ls_sub_3_6:1;
        RBus_UInt32  ls_sub_3_5:1;
        RBus_UInt32  ls_sub_3_4:1;
        RBus_UInt32  ls_sub_3_3:1;
        RBus_UInt32  ls_sub_3_2:1;
        RBus_UInt32  ls_sub_3_1:1;
        RBus_UInt32  ls_sub_3_0:1;
        RBus_UInt32  ls_sub_2_9:1;
        RBus_UInt32  ls_sub_2_8:1;
        RBus_UInt32  ls_sub_2_7:1;
        RBus_UInt32  ls_sub_2_6:1;
        RBus_UInt32  ls_sub_2_5:1;
        RBus_UInt32  ls_sub_2_4:1;
        RBus_UInt32  ls_sub_2_3:1;
        RBus_UInt32  ls_sub_2_2:1;
        RBus_UInt32  ls_sub_2_1:1;
        RBus_UInt32  ls_sub_2_0:1;
    };
}sensio_sensio_mbist_ls_sub_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_0_7:4;
        RBus_UInt32  rm_0_6:4;
        RBus_UInt32  rm_0_5:4;
        RBus_UInt32  rm_0_4:4;
        RBus_UInt32  rm_0_3:4;
        RBus_UInt32  rm_0_2:4;
        RBus_UInt32  rm_0_1:4;
        RBus_UInt32  rm_0_0:4;
    };
}sensio_sensio_mbist_rm_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_1_5:4;
        RBus_UInt32  rm_1_4:4;
        RBus_UInt32  rm_1_3:4;
        RBus_UInt32  rm_1_2:4;
        RBus_UInt32  rm_1_1:4;
        RBus_UInt32  rm_1_0:4;
        RBus_UInt32  rm_0_9:4;
        RBus_UInt32  rm_0_8:4;
    };
}sensio_sensio_mbist_rm_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_2_3:4;
        RBus_UInt32  rm_2_2:4;
        RBus_UInt32  rm_2_1:4;
        RBus_UInt32  rm_2_0:4;
        RBus_UInt32  rm_1_9:4;
        RBus_UInt32  rm_1_8:4;
        RBus_UInt32  rm_1_7:4;
        RBus_UInt32  rm_1_6:4;
    };
}sensio_sensio_mbist_rm_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_3_1:4;
        RBus_UInt32  rm_3_0:4;
        RBus_UInt32  rm_2_9:4;
        RBus_UInt32  rm_2_8:4;
        RBus_UInt32  rm_2_7:4;
        RBus_UInt32  rm_2_6:4;
        RBus_UInt32  rm_2_5:4;
        RBus_UInt32  rm_2_4:4;
    };
}sensio_sensio_mbist_rm_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_3_9:4;
        RBus_UInt32  rm_3_8:4;
        RBus_UInt32  rm_3_7:4;
        RBus_UInt32  rm_3_6:4;
        RBus_UInt32  rm_3_5:4;
        RBus_UInt32  rm_3_4:4;
        RBus_UInt32  rm_3_3:4;
        RBus_UInt32  rm_3_2:4;
    };
}sensio_sensio_mbist_rm_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_sub_0_7:4;
        RBus_UInt32  rm_sub_0_6:4;
        RBus_UInt32  rm_sub_0_5:4;
        RBus_UInt32  rm_sub_0_4:4;
        RBus_UInt32  rm_sub_0_3:4;
        RBus_UInt32  rm_sub_0_2:4;
        RBus_UInt32  rm_sub_0_1:4;
        RBus_UInt32  rm_sub_0_0:4;
    };
}sensio_sensio_mbist_rm_sub_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_sub_1_5:4;
        RBus_UInt32  rm_sub_1_4:4;
        RBus_UInt32  rm_sub_1_3:4;
        RBus_UInt32  rm_sub_1_2:4;
        RBus_UInt32  rm_sub_1_1:4;
        RBus_UInt32  rm_sub_1_0:4;
        RBus_UInt32  rm_sub_0_9:4;
        RBus_UInt32  rm_sub_0_8:4;
    };
}sensio_sensio_mbist_rm_sub_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_sub_2_3:4;
        RBus_UInt32  rm_sub_2_2:4;
        RBus_UInt32  rm_sub_2_1:4;
        RBus_UInt32  rm_sub_2_0:4;
        RBus_UInt32  rm_sub_1_9:4;
        RBus_UInt32  rm_sub_1_8:4;
        RBus_UInt32  rm_sub_1_7:4;
        RBus_UInt32  rm_sub_1_6:4;
    };
}sensio_sensio_mbist_rm_sub_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_sub_3_1:4;
        RBus_UInt32  rm_sub_3_0:4;
        RBus_UInt32  rm_sub_2_9:4;
        RBus_UInt32  rm_sub_2_8:4;
        RBus_UInt32  rm_sub_2_7:4;
        RBus_UInt32  rm_sub_2_6:4;
        RBus_UInt32  rm_sub_2_5:4;
        RBus_UInt32  rm_sub_2_4:4;
    };
}sensio_sensio_mbist_rm_sub_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_sub_3_9:4;
        RBus_UInt32  rm_sub_3_8:4;
        RBus_UInt32  rm_sub_3_7:4;
        RBus_UInt32  rm_sub_3_6:4;
        RBus_UInt32  rm_sub_3_5:4;
        RBus_UInt32  rm_sub_3_4:4;
        RBus_UInt32  rm_sub_3_3:4;
        RBus_UInt32  rm_sub_3_2:4;
    };
}sensio_sensio_mbist_rm_sub_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  rme_1_9:1;
        RBus_UInt32  rme_1_8:1;
        RBus_UInt32  rme_1_7:1;
        RBus_UInt32  rme_1_6:1;
        RBus_UInt32  rme_1_5:1;
        RBus_UInt32  rme_1_4:1;
        RBus_UInt32  rme_1_3:1;
        RBus_UInt32  rme_1_2:1;
        RBus_UInt32  rme_1_1:1;
        RBus_UInt32  rme_1_0:1;
        RBus_UInt32  rme_0_9:1;
        RBus_UInt32  rme_0_8:1;
        RBus_UInt32  rme_0_7:1;
        RBus_UInt32  rme_0_6:1;
        RBus_UInt32  rme_0_5:1;
        RBus_UInt32  rme_0_4:1;
        RBus_UInt32  rme_0_3:1;
        RBus_UInt32  rme_0_2:1;
        RBus_UInt32  rme_0_1:1;
        RBus_UInt32  rme_0_0:1;
    };
}sensio_sensio_mbist_rme_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  rme_3_9:1;
        RBus_UInt32  rme_3_8:1;
        RBus_UInt32  rme_3_7:1;
        RBus_UInt32  rme_3_6:1;
        RBus_UInt32  rme_3_5:1;
        RBus_UInt32  rme_3_4:1;
        RBus_UInt32  rme_3_3:1;
        RBus_UInt32  rme_3_2:1;
        RBus_UInt32  rme_3_1:1;
        RBus_UInt32  rme_3_0:1;
        RBus_UInt32  rme_2_9:1;
        RBus_UInt32  rme_2_8:1;
        RBus_UInt32  rme_2_7:1;
        RBus_UInt32  rme_2_6:1;
        RBus_UInt32  rme_2_5:1;
        RBus_UInt32  rme_2_4:1;
        RBus_UInt32  rme_2_3:1;
        RBus_UInt32  rme_2_2:1;
        RBus_UInt32  rme_2_1:1;
        RBus_UInt32  rme_2_0:1;
    };
}sensio_sensio_mbist_rme_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  rme_sub_1_9:1;
        RBus_UInt32  rme_sub_1_8:1;
        RBus_UInt32  rme_sub_1_7:1;
        RBus_UInt32  rme_sub_1_6:1;
        RBus_UInt32  rme_sub_1_5:1;
        RBus_UInt32  rme_sub_1_4:1;
        RBus_UInt32  rme_sub_1_3:1;
        RBus_UInt32  rme_sub_1_2:1;
        RBus_UInt32  rme_sub_1_1:1;
        RBus_UInt32  rme_sub_1_0:1;
        RBus_UInt32  rme_sub_0_9:1;
        RBus_UInt32  rme_sub_0_8:1;
        RBus_UInt32  rme_sub_0_7:1;
        RBus_UInt32  rme_sub_0_6:1;
        RBus_UInt32  rme_sub_0_5:1;
        RBus_UInt32  rme_sub_0_4:1;
        RBus_UInt32  rme_sub_0_3:1;
        RBus_UInt32  rme_sub_0_2:1;
        RBus_UInt32  rme_sub_0_1:1;
        RBus_UInt32  rme_sub_0_0:1;
    };
}sensio_sensio_mbist_rme_sub_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  rme_sub_3_9:1;
        RBus_UInt32  rme_sub_3_8:1;
        RBus_UInt32  rme_sub_3_7:1;
        RBus_UInt32  rme_sub_3_6:1;
        RBus_UInt32  rme_sub_3_5:1;
        RBus_UInt32  rme_sub_3_4:1;
        RBus_UInt32  rme_sub_3_3:1;
        RBus_UInt32  rme_sub_3_2:1;
        RBus_UInt32  rme_sub_3_1:1;
        RBus_UInt32  rme_sub_3_0:1;
        RBus_UInt32  rme_sub_2_9:1;
        RBus_UInt32  rme_sub_2_8:1;
        RBus_UInt32  rme_sub_2_7:1;
        RBus_UInt32  rme_sub_2_6:1;
        RBus_UInt32  rme_sub_2_5:1;
        RBus_UInt32  rme_sub_2_4:1;
        RBus_UInt32  rme_sub_2_3:1;
        RBus_UInt32  rme_sub_2_2:1;
        RBus_UInt32  rme_sub_2_1:1;
        RBus_UInt32  rme_sub_2_0:1;
    };
}sensio_sensio_mbist_rme_sub_1_RBUS;

#else //apply LITTLE_ENDIAN

//======SENSIO register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  en_ctsfifo_bypass_sensio:1;
        RBus_UInt32  en_ctsfifo_vsrst_sensio:1;
        RBus_UInt32  force_ctsfifo_rstn_sensio:1;
        RBus_UInt32  vflip_en:1;
        RBus_UInt32  res2:21;
        RBus_UInt32  re_decom_en:1;
        RBus_UInt32  res3:2;
    };
}sensio_sensio_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sensio_ihsize:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  sensio_ivsize:12;
        RBus_UInt32  res2:4;
    };
}sensio_sensio_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sensio_sub_double_en:1;
        RBus_UInt32  sensio_sub_double_apply:1;
        RBus_UInt32  res1:14;
        RBus_UInt32  sensio_read_sel:1;
        RBus_UInt32  sensio_double_en:1;
        RBus_UInt32  sensio_double_apply:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  res3:8;
    };
}sensio_sensio_ctrl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  main_decomp_10bit:2;
        RBus_UInt32  res1:30;
    };
}sensio_decomp_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  sub_re_decom_en:1;
        RBus_UInt32  sub_decomp_10bit:2;
        RBus_UInt32  sub_vflip_en:1;
        RBus_UInt32  res2:27;
    };
}sensio_sub_vp9_decomp_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sub_v_d_ihsize:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  sub_v_d_ivsize:11;
        RBus_UInt32  res2:5;
    };
}sensio_sub_vp9_decomp_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  real_vp9_vstart:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  real_vp9_vend:12;
        RBus_UInt32  res2:4;
    };
}sensio_vp9_decomp_v_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sub_real_vp9_vstart:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  sub_real_vp9_vend:11;
        RBus_UInt32  res2:5;
    };
}sensio_sub_vp9_decomp_v_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_total:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  hs_width:6;
        RBus_UInt32  res2:10;
    };
}sensio_sensio_tim_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_den_st:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  v_den_st:8;
        RBus_UInt32  res2:8;
    };
}sensio_sensio_tim_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sub_h_total:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  sub_hs_width:6;
        RBus_UInt32  res2:10;
    };
}sensio_sub_sensio_tim_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sub_h_den_st:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  sub_v_den_st:8;
        RBus_UInt32  res2:8;
    };
}sensio_sub_sensio_tim_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_fail_0_0:1;
        RBus_UInt32  bist_fail_0_1:1;
        RBus_UInt32  bist_fail_0_2:1;
        RBus_UInt32  bist_fail_0_3:1;
        RBus_UInt32  bist_fail_0_4:1;
        RBus_UInt32  bist_fail_0_5:1;
        RBus_UInt32  bist_fail_0_6:1;
        RBus_UInt32  bist_fail_0_7:1;
        RBus_UInt32  bist_fail_0_8:1;
        RBus_UInt32  bist_fail_0_9:1;
        RBus_UInt32  bist_fail_1_0:1;
        RBus_UInt32  bist_fail_1_1:1;
        RBus_UInt32  bist_fail_1_2:1;
        RBus_UInt32  bist_fail_1_3:1;
        RBus_UInt32  bist_fail_1_4:1;
        RBus_UInt32  bist_fail_1_5:1;
        RBus_UInt32  bist_fail_1_6:1;
        RBus_UInt32  bist_fail_1_7:1;
        RBus_UInt32  bist_fail_1_8:1;
        RBus_UInt32  bist_fail_1_9:1;
        RBus_UInt32  res1:12;
    };
}sensio_sensio_mbist_fail_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_fail_2_0:1;
        RBus_UInt32  bist_fail_2_1:1;
        RBus_UInt32  bist_fail_2_2:1;
        RBus_UInt32  bist_fail_2_3:1;
        RBus_UInt32  bist_fail_2_4:1;
        RBus_UInt32  bist_fail_2_5:1;
        RBus_UInt32  bist_fail_2_6:1;
        RBus_UInt32  bist_fail_2_7:1;
        RBus_UInt32  bist_fail_2_8:1;
        RBus_UInt32  bist_fail_2_9:1;
        RBus_UInt32  bist_fail_3_0:1;
        RBus_UInt32  bist_fail_3_1:1;
        RBus_UInt32  bist_fail_3_2:1;
        RBus_UInt32  bist_fail_3_3:1;
        RBus_UInt32  bist_fail_3_4:1;
        RBus_UInt32  bist_fail_3_5:1;
        RBus_UInt32  bist_fail_3_6:1;
        RBus_UInt32  bist_fail_3_7:1;
        RBus_UInt32  bist_fail_3_8:1;
        RBus_UInt32  bist_fail_3_9:1;
        RBus_UInt32  res1:12;
    };
}sensio_sensio_mbist_fail_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_fail_sub_0_0:1;
        RBus_UInt32  bist_fail_sub_0_1:1;
        RBus_UInt32  bist_fail_sub_0_2:1;
        RBus_UInt32  bist_fail_sub_0_3:1;
        RBus_UInt32  bist_fail_sub_0_4:1;
        RBus_UInt32  bist_fail_sub_0_5:1;
        RBus_UInt32  bist_fail_sub_0_6:1;
        RBus_UInt32  bist_fail_sub_0_7:1;
        RBus_UInt32  bist_fail_sub_0_8:1;
        RBus_UInt32  bist_fail_sub_0_9:1;
        RBus_UInt32  bist_fail_sub_1_0:1;
        RBus_UInt32  bist_fail_sub_1_1:1;
        RBus_UInt32  bist_fail_sub_1_2:1;
        RBus_UInt32  bist_fail_sub_1_3:1;
        RBus_UInt32  bist_fail_sub_1_4:1;
        RBus_UInt32  bist_fail_sub_1_5:1;
        RBus_UInt32  bist_fail_sub_1_6:1;
        RBus_UInt32  bist_fail_sub_1_7:1;
        RBus_UInt32  bist_fail_sub_1_8:1;
        RBus_UInt32  bist_fail_sub_1_9:1;
        RBus_UInt32  res1:12;
    };
}sensio_sensio_mbist_fail_sub_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_fail_sub_2_0:1;
        RBus_UInt32  bist_fail_sub_2_1:1;
        RBus_UInt32  bist_fail_sub_2_2:1;
        RBus_UInt32  bist_fail_sub_2_3:1;
        RBus_UInt32  bist_fail_sub_2_4:1;
        RBus_UInt32  bist_fail_sub_2_5:1;
        RBus_UInt32  bist_fail_sub_2_6:1;
        RBus_UInt32  bist_fail_sub_2_7:1;
        RBus_UInt32  bist_fail_sub_2_8:1;
        RBus_UInt32  bist_fail_sub_2_9:1;
        RBus_UInt32  bist_fail_sub_3_0:1;
        RBus_UInt32  bist_fail_sub_3_1:1;
        RBus_UInt32  bist_fail_sub_3_2:1;
        RBus_UInt32  bist_fail_sub_3_3:1;
        RBus_UInt32  bist_fail_sub_3_4:1;
        RBus_UInt32  bist_fail_sub_3_5:1;
        RBus_UInt32  bist_fail_sub_3_6:1;
        RBus_UInt32  bist_fail_sub_3_7:1;
        RBus_UInt32  bist_fail_sub_3_8:1;
        RBus_UInt32  bist_fail_sub_3_9:1;
        RBus_UInt32  res1:12;
    };
}sensio_sensio_mbist_fail_sub_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_bist_fail_0_0:1;
        RBus_UInt32  drf_bist_fail_0_1:1;
        RBus_UInt32  drf_bist_fail_0_2:1;
        RBus_UInt32  drf_bist_fail_0_3:1;
        RBus_UInt32  drf_bist_fail_0_4:1;
        RBus_UInt32  drf_bist_fail_0_5:1;
        RBus_UInt32  drf_bist_fail_0_6:1;
        RBus_UInt32  drf_bist_fail_0_7:1;
        RBus_UInt32  drf_bist_fail_0_8:1;
        RBus_UInt32  drf_bist_fail_0_9:1;
        RBus_UInt32  drf_bist_fail_1_0:1;
        RBus_UInt32  drf_bist_fail_1_1:1;
        RBus_UInt32  drf_bist_fail_1_2:1;
        RBus_UInt32  drf_bist_fail_1_3:1;
        RBus_UInt32  drf_bist_fail_1_4:1;
        RBus_UInt32  drf_bist_fail_1_5:1;
        RBus_UInt32  drf_bist_fail_1_6:1;
        RBus_UInt32  drf_bist_fail_1_7:1;
        RBus_UInt32  drf_bist_fail_1_8:1;
        RBus_UInt32  drf_bist_fail_1_9:1;
        RBus_UInt32  res1:12;
    };
}sensio_sensio_mbist_drf_fail_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_bist_fail_2_0:1;
        RBus_UInt32  drf_bist_fail_2_1:1;
        RBus_UInt32  drf_bist_fail_2_2:1;
        RBus_UInt32  drf_bist_fail_2_3:1;
        RBus_UInt32  drf_bist_fail_2_4:1;
        RBus_UInt32  drf_bist_fail_2_5:1;
        RBus_UInt32  drf_bist_fail_2_6:1;
        RBus_UInt32  drf_bist_fail_2_7:1;
        RBus_UInt32  drf_bist_fail_2_8:1;
        RBus_UInt32  drf_bist_fail_2_9:1;
        RBus_UInt32  drf_bist_fail_3_0:1;
        RBus_UInt32  drf_bist_fail_3_1:1;
        RBus_UInt32  drf_bist_fail_3_2:1;
        RBus_UInt32  drf_bist_fail_3_3:1;
        RBus_UInt32  drf_bist_fail_3_4:1;
        RBus_UInt32  drf_bist_fail_3_5:1;
        RBus_UInt32  drf_bist_fail_3_6:1;
        RBus_UInt32  drf_bist_fail_3_7:1;
        RBus_UInt32  drf_bist_fail_3_8:1;
        RBus_UInt32  drf_bist_fail_3_9:1;
        RBus_UInt32  res1:12;
    };
}sensio_sensio_mbist_drf_fail_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_bist_fail_sub_0_0:1;
        RBus_UInt32  drf_bist_fail_sub_0_1:1;
        RBus_UInt32  drf_bist_fail_sub_0_2:1;
        RBus_UInt32  drf_bist_fail_sub_0_3:1;
        RBus_UInt32  drf_bist_fail_sub_0_4:1;
        RBus_UInt32  drf_bist_fail_sub_0_5:1;
        RBus_UInt32  drf_bist_fail_sub_0_6:1;
        RBus_UInt32  drf_bist_fail_sub_0_7:1;
        RBus_UInt32  drf_bist_fail_sub_0_8:1;
        RBus_UInt32  drf_bist_fail_sub_0_9:1;
        RBus_UInt32  drf_bist_fail_sub_1_0:1;
        RBus_UInt32  drf_bist_fail_sub_1_1:1;
        RBus_UInt32  drf_bist_fail_sub_1_2:1;
        RBus_UInt32  drf_bist_fail_sub_1_3:1;
        RBus_UInt32  drf_bist_fail_sub_1_4:1;
        RBus_UInt32  drf_bist_fail_sub_1_5:1;
        RBus_UInt32  drf_bist_fail_sub_1_6:1;
        RBus_UInt32  drf_bist_fail_sub_1_7:1;
        RBus_UInt32  drf_bist_fail_sub_1_8:1;
        RBus_UInt32  drf_bist_fail_sub_1_9:1;
        RBus_UInt32  res1:12;
    };
}sensio_sensio_mbist_drf_fail_sub_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_bist_fail_sub_2_0:1;
        RBus_UInt32  drf_bist_fail_sub_2_1:1;
        RBus_UInt32  drf_bist_fail_sub_2_2:1;
        RBus_UInt32  drf_bist_fail_sub_2_3:1;
        RBus_UInt32  drf_bist_fail_sub_2_4:1;
        RBus_UInt32  drf_bist_fail_sub_2_5:1;
        RBus_UInt32  drf_bist_fail_sub_2_6:1;
        RBus_UInt32  drf_bist_fail_sub_2_7:1;
        RBus_UInt32  drf_bist_fail_sub_2_8:1;
        RBus_UInt32  drf_bist_fail_sub_2_9:1;
        RBus_UInt32  drf_bist_fail_sub_3_0:1;
        RBus_UInt32  drf_bist_fail_sub_3_1:1;
        RBus_UInt32  drf_bist_fail_sub_3_2:1;
        RBus_UInt32  drf_bist_fail_sub_3_3:1;
        RBus_UInt32  drf_bist_fail_sub_3_4:1;
        RBus_UInt32  drf_bist_fail_sub_3_5:1;
        RBus_UInt32  drf_bist_fail_sub_3_6:1;
        RBus_UInt32  drf_bist_fail_sub_3_7:1;
        RBus_UInt32  drf_bist_fail_sub_3_8:1;
        RBus_UInt32  drf_bist_fail_sub_3_9:1;
        RBus_UInt32  res1:12;
    };
}sensio_sensio_mbist_drf_fail_sub_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ls_0_0:1;
        RBus_UInt32  ls_0_1:1;
        RBus_UInt32  ls_0_2:1;
        RBus_UInt32  ls_0_3:1;
        RBus_UInt32  ls_0_4:1;
        RBus_UInt32  ls_0_5:1;
        RBus_UInt32  ls_0_6:1;
        RBus_UInt32  ls_0_7:1;
        RBus_UInt32  ls_0_8:1;
        RBus_UInt32  ls_0_9:1;
        RBus_UInt32  ls_1_0:1;
        RBus_UInt32  ls_1_1:1;
        RBus_UInt32  ls_1_2:1;
        RBus_UInt32  ls_1_3:1;
        RBus_UInt32  ls_1_4:1;
        RBus_UInt32  ls_1_5:1;
        RBus_UInt32  ls_1_6:1;
        RBus_UInt32  ls_1_7:1;
        RBus_UInt32  ls_1_8:1;
        RBus_UInt32  ls_1_9:1;
        RBus_UInt32  res1:12;
    };
}sensio_sensio_mbist_ls_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ls_2_0:1;
        RBus_UInt32  ls_2_1:1;
        RBus_UInt32  ls_2_2:1;
        RBus_UInt32  ls_2_3:1;
        RBus_UInt32  ls_2_4:1;
        RBus_UInt32  ls_2_5:1;
        RBus_UInt32  ls_2_6:1;
        RBus_UInt32  ls_2_7:1;
        RBus_UInt32  ls_2_8:1;
        RBus_UInt32  ls_2_9:1;
        RBus_UInt32  ls_3_0:1;
        RBus_UInt32  ls_3_1:1;
        RBus_UInt32  ls_3_2:1;
        RBus_UInt32  ls_3_3:1;
        RBus_UInt32  ls_3_4:1;
        RBus_UInt32  ls_3_5:1;
        RBus_UInt32  ls_3_6:1;
        RBus_UInt32  ls_3_7:1;
        RBus_UInt32  ls_3_8:1;
        RBus_UInt32  ls_3_9:1;
        RBus_UInt32  res1:12;
    };
}sensio_sensio_mbist_ls_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ls_sub_0_0:1;
        RBus_UInt32  ls_sub_0_1:1;
        RBus_UInt32  ls_sub_0_2:1;
        RBus_UInt32  ls_sub_0_3:1;
        RBus_UInt32  ls_sub_0_4:1;
        RBus_UInt32  ls_sub_0_5:1;
        RBus_UInt32  ls_sub_0_6:1;
        RBus_UInt32  ls_sub_0_7:1;
        RBus_UInt32  ls_sub_0_8:1;
        RBus_UInt32  ls_sub_0_9:1;
        RBus_UInt32  ls_sub_1_0:1;
        RBus_UInt32  ls_sub_1_1:1;
        RBus_UInt32  ls_sub_1_2:1;
        RBus_UInt32  ls_sub_1_3:1;
        RBus_UInt32  ls_sub_1_4:1;
        RBus_UInt32  ls_sub_1_5:1;
        RBus_UInt32  ls_sub_1_6:1;
        RBus_UInt32  ls_sub_1_7:1;
        RBus_UInt32  ls_sub_1_8:1;
        RBus_UInt32  ls_sub_1_9:1;
        RBus_UInt32  res1:12;
    };
}sensio_sensio_mbist_ls_sub_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ls_sub_2_0:1;
        RBus_UInt32  ls_sub_2_1:1;
        RBus_UInt32  ls_sub_2_2:1;
        RBus_UInt32  ls_sub_2_3:1;
        RBus_UInt32  ls_sub_2_4:1;
        RBus_UInt32  ls_sub_2_5:1;
        RBus_UInt32  ls_sub_2_6:1;
        RBus_UInt32  ls_sub_2_7:1;
        RBus_UInt32  ls_sub_2_8:1;
        RBus_UInt32  ls_sub_2_9:1;
        RBus_UInt32  ls_sub_3_0:1;
        RBus_UInt32  ls_sub_3_1:1;
        RBus_UInt32  ls_sub_3_2:1;
        RBus_UInt32  ls_sub_3_3:1;
        RBus_UInt32  ls_sub_3_4:1;
        RBus_UInt32  ls_sub_3_5:1;
        RBus_UInt32  ls_sub_3_6:1;
        RBus_UInt32  ls_sub_3_7:1;
        RBus_UInt32  ls_sub_3_8:1;
        RBus_UInt32  ls_sub_3_9:1;
        RBus_UInt32  res1:12;
    };
}sensio_sensio_mbist_ls_sub_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_0_0:4;
        RBus_UInt32  rm_0_1:4;
        RBus_UInt32  rm_0_2:4;
        RBus_UInt32  rm_0_3:4;
        RBus_UInt32  rm_0_4:4;
        RBus_UInt32  rm_0_5:4;
        RBus_UInt32  rm_0_6:4;
        RBus_UInt32  rm_0_7:4;
    };
}sensio_sensio_mbist_rm_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_0_8:4;
        RBus_UInt32  rm_0_9:4;
        RBus_UInt32  rm_1_0:4;
        RBus_UInt32  rm_1_1:4;
        RBus_UInt32  rm_1_2:4;
        RBus_UInt32  rm_1_3:4;
        RBus_UInt32  rm_1_4:4;
        RBus_UInt32  rm_1_5:4;
    };
}sensio_sensio_mbist_rm_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_1_6:4;
        RBus_UInt32  rm_1_7:4;
        RBus_UInt32  rm_1_8:4;
        RBus_UInt32  rm_1_9:4;
        RBus_UInt32  rm_2_0:4;
        RBus_UInt32  rm_2_1:4;
        RBus_UInt32  rm_2_2:4;
        RBus_UInt32  rm_2_3:4;
    };
}sensio_sensio_mbist_rm_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_2_4:4;
        RBus_UInt32  rm_2_5:4;
        RBus_UInt32  rm_2_6:4;
        RBus_UInt32  rm_2_7:4;
        RBus_UInt32  rm_2_8:4;
        RBus_UInt32  rm_2_9:4;
        RBus_UInt32  rm_3_0:4;
        RBus_UInt32  rm_3_1:4;
    };
}sensio_sensio_mbist_rm_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_3_2:4;
        RBus_UInt32  rm_3_3:4;
        RBus_UInt32  rm_3_4:4;
        RBus_UInt32  rm_3_5:4;
        RBus_UInt32  rm_3_6:4;
        RBus_UInt32  rm_3_7:4;
        RBus_UInt32  rm_3_8:4;
        RBus_UInt32  rm_3_9:4;
    };
}sensio_sensio_mbist_rm_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_sub_0_0:4;
        RBus_UInt32  rm_sub_0_1:4;
        RBus_UInt32  rm_sub_0_2:4;
        RBus_UInt32  rm_sub_0_3:4;
        RBus_UInt32  rm_sub_0_4:4;
        RBus_UInt32  rm_sub_0_5:4;
        RBus_UInt32  rm_sub_0_6:4;
        RBus_UInt32  rm_sub_0_7:4;
    };
}sensio_sensio_mbist_rm_sub_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_sub_0_8:4;
        RBus_UInt32  rm_sub_0_9:4;
        RBus_UInt32  rm_sub_1_0:4;
        RBus_UInt32  rm_sub_1_1:4;
        RBus_UInt32  rm_sub_1_2:4;
        RBus_UInt32  rm_sub_1_3:4;
        RBus_UInt32  rm_sub_1_4:4;
        RBus_UInt32  rm_sub_1_5:4;
    };
}sensio_sensio_mbist_rm_sub_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_sub_1_6:4;
        RBus_UInt32  rm_sub_1_7:4;
        RBus_UInt32  rm_sub_1_8:4;
        RBus_UInt32  rm_sub_1_9:4;
        RBus_UInt32  rm_sub_2_0:4;
        RBus_UInt32  rm_sub_2_1:4;
        RBus_UInt32  rm_sub_2_2:4;
        RBus_UInt32  rm_sub_2_3:4;
    };
}sensio_sensio_mbist_rm_sub_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_sub_2_4:4;
        RBus_UInt32  rm_sub_2_5:4;
        RBus_UInt32  rm_sub_2_6:4;
        RBus_UInt32  rm_sub_2_7:4;
        RBus_UInt32  rm_sub_2_8:4;
        RBus_UInt32  rm_sub_2_9:4;
        RBus_UInt32  rm_sub_3_0:4;
        RBus_UInt32  rm_sub_3_1:4;
    };
}sensio_sensio_mbist_rm_sub_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_sub_3_2:4;
        RBus_UInt32  rm_sub_3_3:4;
        RBus_UInt32  rm_sub_3_4:4;
        RBus_UInt32  rm_sub_3_5:4;
        RBus_UInt32  rm_sub_3_6:4;
        RBus_UInt32  rm_sub_3_7:4;
        RBus_UInt32  rm_sub_3_8:4;
        RBus_UInt32  rm_sub_3_9:4;
    };
}sensio_sensio_mbist_rm_sub_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rme_0_0:1;
        RBus_UInt32  rme_0_1:1;
        RBus_UInt32  rme_0_2:1;
        RBus_UInt32  rme_0_3:1;
        RBus_UInt32  rme_0_4:1;
        RBus_UInt32  rme_0_5:1;
        RBus_UInt32  rme_0_6:1;
        RBus_UInt32  rme_0_7:1;
        RBus_UInt32  rme_0_8:1;
        RBus_UInt32  rme_0_9:1;
        RBus_UInt32  rme_1_0:1;
        RBus_UInt32  rme_1_1:1;
        RBus_UInt32  rme_1_2:1;
        RBus_UInt32  rme_1_3:1;
        RBus_UInt32  rme_1_4:1;
        RBus_UInt32  rme_1_5:1;
        RBus_UInt32  rme_1_6:1;
        RBus_UInt32  rme_1_7:1;
        RBus_UInt32  rme_1_8:1;
        RBus_UInt32  rme_1_9:1;
        RBus_UInt32  res1:12;
    };
}sensio_sensio_mbist_rme_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rme_2_0:1;
        RBus_UInt32  rme_2_1:1;
        RBus_UInt32  rme_2_2:1;
        RBus_UInt32  rme_2_3:1;
        RBus_UInt32  rme_2_4:1;
        RBus_UInt32  rme_2_5:1;
        RBus_UInt32  rme_2_6:1;
        RBus_UInt32  rme_2_7:1;
        RBus_UInt32  rme_2_8:1;
        RBus_UInt32  rme_2_9:1;
        RBus_UInt32  rme_3_0:1;
        RBus_UInt32  rme_3_1:1;
        RBus_UInt32  rme_3_2:1;
        RBus_UInt32  rme_3_3:1;
        RBus_UInt32  rme_3_4:1;
        RBus_UInt32  rme_3_5:1;
        RBus_UInt32  rme_3_6:1;
        RBus_UInt32  rme_3_7:1;
        RBus_UInt32  rme_3_8:1;
        RBus_UInt32  rme_3_9:1;
        RBus_UInt32  res1:12;
    };
}sensio_sensio_mbist_rme_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rme_sub_0_0:1;
        RBus_UInt32  rme_sub_0_1:1;
        RBus_UInt32  rme_sub_0_2:1;
        RBus_UInt32  rme_sub_0_3:1;
        RBus_UInt32  rme_sub_0_4:1;
        RBus_UInt32  rme_sub_0_5:1;
        RBus_UInt32  rme_sub_0_6:1;
        RBus_UInt32  rme_sub_0_7:1;
        RBus_UInt32  rme_sub_0_8:1;
        RBus_UInt32  rme_sub_0_9:1;
        RBus_UInt32  rme_sub_1_0:1;
        RBus_UInt32  rme_sub_1_1:1;
        RBus_UInt32  rme_sub_1_2:1;
        RBus_UInt32  rme_sub_1_3:1;
        RBus_UInt32  rme_sub_1_4:1;
        RBus_UInt32  rme_sub_1_5:1;
        RBus_UInt32  rme_sub_1_6:1;
        RBus_UInt32  rme_sub_1_7:1;
        RBus_UInt32  rme_sub_1_8:1;
        RBus_UInt32  rme_sub_1_9:1;
        RBus_UInt32  res1:12;
    };
}sensio_sensio_mbist_rme_sub_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rme_sub_2_0:1;
        RBus_UInt32  rme_sub_2_1:1;
        RBus_UInt32  rme_sub_2_2:1;
        RBus_UInt32  rme_sub_2_3:1;
        RBus_UInt32  rme_sub_2_4:1;
        RBus_UInt32  rme_sub_2_5:1;
        RBus_UInt32  rme_sub_2_6:1;
        RBus_UInt32  rme_sub_2_7:1;
        RBus_UInt32  rme_sub_2_8:1;
        RBus_UInt32  rme_sub_2_9:1;
        RBus_UInt32  rme_sub_3_0:1;
        RBus_UInt32  rme_sub_3_1:1;
        RBus_UInt32  rme_sub_3_2:1;
        RBus_UInt32  rme_sub_3_3:1;
        RBus_UInt32  rme_sub_3_4:1;
        RBus_UInt32  rme_sub_3_5:1;
        RBus_UInt32  rme_sub_3_6:1;
        RBus_UInt32  rme_sub_3_7:1;
        RBus_UInt32  rme_sub_3_8:1;
        RBus_UInt32  rme_sub_3_9:1;
        RBus_UInt32  res1:12;
    };
}sensio_sensio_mbist_rme_sub_1_RBUS;




#endif 


#endif 
