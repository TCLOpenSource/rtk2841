/**
* @file Mac5-DesignSpec_vd_ifd_input
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_VD_IFD_INPUT_REG_H_
#define _RBUS_VD_IFD_INPUT_REG_H_

#include "rbus_types.h"



//  VD_IFD_INPUT Register Address
#define  VD_IFD_INPUT_input_filter_set                                           0x18018094
#define  VD_IFD_INPUT_input_filter_set_reg_addr                                  "0xB8018094"
#define  VD_IFD_INPUT_input_filter_set_reg                                       0xB8018094
#define  VD_IFD_INPUT_input_filter_set_inst_addr                                 "0x0000"
#define  set_VD_IFD_INPUT_input_filter_set_reg(data)                             (*((volatile unsigned int*)VD_IFD_INPUT_input_filter_set_reg)=data)
#define  get_VD_IFD_INPUT_input_filter_set_reg                                   (*((volatile unsigned int*)VD_IFD_INPUT_input_filter_set_reg))
#define  VD_IFD_INPUT_input_filter_set_adc_fifo_in_sel_shift                     (8)
#define  VD_IFD_INPUT_input_filter_set_adc_clk_sel_shift                         (4)
#define  VD_IFD_INPUT_input_filter_set_input_dn_filter_sel_shift                 (0)
#define  VD_IFD_INPUT_input_filter_set_adc_fifo_in_sel_mask                      (0x00000100)
#define  VD_IFD_INPUT_input_filter_set_adc_clk_sel_mask                          (0x00000030)
#define  VD_IFD_INPUT_input_filter_set_input_dn_filter_sel_mask                  (0x00000007)
#define  VD_IFD_INPUT_input_filter_set_adc_fifo_in_sel(data)                     (0x00000100&((data)<<8))
#define  VD_IFD_INPUT_input_filter_set_adc_clk_sel(data)                         (0x00000030&((data)<<4))
#define  VD_IFD_INPUT_input_filter_set_input_dn_filter_sel(data)                 (0x00000007&(data))
#define  VD_IFD_INPUT_input_filter_set_get_adc_fifo_in_sel(data)                 ((0x00000100&(data))>>8)
#define  VD_IFD_INPUT_input_filter_set_get_adc_clk_sel(data)                     ((0x00000030&(data))>>4)
#define  VD_IFD_INPUT_input_filter_set_get_input_dn_filter_sel(data)             (0x00000007&(data))

#define  VD_IFD_INPUT_IFD_ADC_CLK_POLAR                                          0x18018098
#define  VD_IFD_INPUT_IFD_ADC_CLK_POLAR_reg_addr                                 "0xB8018098"
#define  VD_IFD_INPUT_IFD_ADC_CLK_POLAR_reg                                      0xB8018098
#define  VD_IFD_INPUT_IFD_ADC_CLK_POLAR_inst_addr                                "0x0001"
#define  set_VD_IFD_INPUT_IFD_ADC_CLK_POLAR_reg(data)                            (*((volatile unsigned int*)VD_IFD_INPUT_IFD_ADC_CLK_POLAR_reg)=data)
#define  get_VD_IFD_INPUT_IFD_ADC_CLK_POLAR_reg                                  (*((volatile unsigned int*)VD_IFD_INPUT_IFD_ADC_CLK_POLAR_reg))
#define  VD_IFD_INPUT_IFD_ADC_CLK_POLAR_clk54_polar_shift                        (0)
#define  VD_IFD_INPUT_IFD_ADC_CLK_POLAR_clk54_polar_mask                         (0x00000001)
#define  VD_IFD_INPUT_IFD_ADC_CLK_POLAR_clk54_polar(data)                        (0x00000001&(data))
#define  VD_IFD_INPUT_IFD_ADC_CLK_POLAR_get_clk54_polar(data)                    (0x00000001&(data))

#define  VD_IFD_INPUT_IFD_cp_test_enable                                         0x1801809C
#define  VD_IFD_INPUT_IFD_cp_test_enable_reg_addr                                "0xB801809C"
#define  VD_IFD_INPUT_IFD_cp_test_enable_reg                                     0xB801809C
#define  VD_IFD_INPUT_IFD_cp_test_enable_inst_addr                               "0x0002"
#define  set_VD_IFD_INPUT_IFD_cp_test_enable_reg(data)                           (*((volatile unsigned int*)VD_IFD_INPUT_IFD_cp_test_enable_reg)=data)
#define  get_VD_IFD_INPUT_IFD_cp_test_enable_reg                                 (*((volatile unsigned int*)VD_IFD_INPUT_IFD_cp_test_enable_reg))
#define  VD_IFD_INPUT_IFD_cp_test_enable_cp_test_enable_shift                    (0)
#define  VD_IFD_INPUT_IFD_cp_test_enable_cp_test_enable_mask                     (0x00000001)
#define  VD_IFD_INPUT_IFD_cp_test_enable_cp_test_enable(data)                    (0x00000001&(data))
#define  VD_IFD_INPUT_IFD_cp_test_enable_get_cp_test_enable(data)                (0x00000001&(data))

#define  VD_IFD_INPUT_VD_IN_DELAY_SEL1                                           0x180180A0
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL1_reg_addr                                  "0xB80180A0"
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL1_reg                                       0xB80180A0
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL1_inst_addr                                 "0x0003"
#define  set_VD_IFD_INPUT_VD_IN_DELAY_SEL1_reg(data)                             (*((volatile unsigned int*)VD_IFD_INPUT_VD_IN_DELAY_SEL1_reg)=data)
#define  get_VD_IFD_INPUT_VD_IN_DELAY_SEL1_reg                                   (*((volatile unsigned int*)VD_IFD_INPUT_VD_IN_DELAY_SEL1_reg))
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL1_ad4_input_delay_shift                     (24)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL1_ad3_input_delay_shift                     (16)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL1_ad2_input_delay_shift                     (8)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL1_ad1_input_delay_shift                     (0)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL1_ad4_input_delay_mask                      (0x1F000000)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL1_ad3_input_delay_mask                      (0x001F0000)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL1_ad2_input_delay_mask                      (0x00001F00)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL1_ad1_input_delay_mask                      (0x0000001F)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL1_ad4_input_delay(data)                     (0x1F000000&((data)<<24))
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL1_ad3_input_delay(data)                     (0x001F0000&((data)<<16))
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL1_ad2_input_delay(data)                     (0x00001F00&((data)<<8))
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL1_ad1_input_delay(data)                     (0x0000001F&(data))
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL1_get_ad4_input_delay(data)                 ((0x1F000000&(data))>>24)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL1_get_ad3_input_delay(data)                 ((0x001F0000&(data))>>16)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL1_get_ad2_input_delay(data)                 ((0x00001F00&(data))>>8)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL1_get_ad1_input_delay(data)                 (0x0000001F&(data))

#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2                                           0x180180A4
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_reg_addr                                  "0xB80180A4"
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_reg                                       0xB80180A4
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_inst_addr                                 "0x0004"
#define  set_VD_IFD_INPUT_VD_IN_DELAY_SEL2_reg(data)                             (*((volatile unsigned int*)VD_IFD_INPUT_VD_IN_DELAY_SEL2_reg)=data)
#define  get_VD_IFD_INPUT_VD_IN_DELAY_SEL2_reg                                   (*((volatile unsigned int*)VD_IFD_INPUT_VD_IN_DELAY_SEL2_reg))
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_cvbs_tve_mux_shift                        (31)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_ad5_input_delay_shift                     (8)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_sv_sel_shift                              (2)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_sv_yc_switch_shift                        (1)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_sv_in_one_adc_shift                       (0)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_cvbs_tve_mux_mask                         (0x80000000)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_ad5_input_delay_mask                      (0x00001F00)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_sv_sel_mask                               (0x0000000C)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_sv_yc_switch_mask                         (0x00000002)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_sv_in_one_adc_mask                        (0x00000001)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_cvbs_tve_mux(data)                        (0x80000000&((data)<<31))
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_ad5_input_delay(data)                     (0x00001F00&((data)<<8))
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_sv_sel(data)                              (0x0000000C&((data)<<2))
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_sv_yc_switch(data)                        (0x00000002&((data)<<1))
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_sv_in_one_adc(data)                       (0x00000001&(data))
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_get_cvbs_tve_mux(data)                    ((0x80000000&(data))>>31)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_get_ad5_input_delay(data)                 ((0x00001F00&(data))>>8)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_get_sv_sel(data)                          ((0x0000000C&(data))>>2)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_get_sv_yc_switch(data)                    ((0x00000002&(data))>>1)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_get_sv_in_one_adc(data)                   (0x00000001&(data))

#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL                                            0x180180A8
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_reg_addr                                   "0xB80180A8"
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_reg                                        0xB80180A8
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_inst_addr                                  "0x0005"
#define  set_VD_IFD_INPUT_VD_ADC_LSB_CTRL_reg(data)                              (*((volatile unsigned int*)VD_IFD_INPUT_VD_ADC_LSB_CTRL_reg)=data)
#define  get_VD_IFD_INPUT_VD_ADC_LSB_CTRL_reg                                    (*((volatile unsigned int*)VD_IFD_INPUT_VD_ADC_LSB_CTRL_reg))
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_scart_input_delay_108_shift                (24)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_yppb_input_delay_108_shift                 (20)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_yppg_input_delay_108_shift                 (16)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_yppr_input_delay_108_shift                 (12)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_vdadc_input_delay_108_shift                (8)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_adc3_lsb_force0_num_shift                  (6)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_adc2_lsb_force0_num_shift                  (4)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_adc1_lsb_force0_num_shift                  (2)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_adc0_lsb_force0_num_shift                  (0)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_scart_input_delay_108_mask                 (0x0F000000)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_yppb_input_delay_108_mask                  (0x00F00000)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_yppg_input_delay_108_mask                  (0x000F0000)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_yppr_input_delay_108_mask                  (0x0000F000)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_vdadc_input_delay_108_mask                 (0x00000F00)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_adc3_lsb_force0_num_mask                   (0x000000C0)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_adc2_lsb_force0_num_mask                   (0x00000030)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_adc1_lsb_force0_num_mask                   (0x0000000C)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_adc0_lsb_force0_num_mask                   (0x00000003)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_scart_input_delay_108(data)                (0x0F000000&((data)<<24))
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_yppb_input_delay_108(data)                 (0x00F00000&((data)<<20))
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_yppg_input_delay_108(data)                 (0x000F0000&((data)<<16))
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_yppr_input_delay_108(data)                 (0x0000F000&((data)<<12))
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_vdadc_input_delay_108(data)                (0x00000F00&((data)<<8))
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_adc3_lsb_force0_num(data)                  (0x000000C0&((data)<<6))
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_adc2_lsb_force0_num(data)                  (0x00000030&((data)<<4))
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_adc1_lsb_force0_num(data)                  (0x0000000C&((data)<<2))
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_adc0_lsb_force0_num(data)                  (0x00000003&(data))
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_get_scart_input_delay_108(data)            ((0x0F000000&(data))>>24)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_get_yppb_input_delay_108(data)             ((0x00F00000&(data))>>20)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_get_yppg_input_delay_108(data)             ((0x000F0000&(data))>>16)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_get_yppr_input_delay_108(data)             ((0x0000F000&(data))>>12)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_get_vdadc_input_delay_108(data)            ((0x00000F00&(data))>>8)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_get_adc3_lsb_force0_num(data)              ((0x000000C0&(data))>>6)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_get_adc2_lsb_force0_num(data)              ((0x00000030&(data))>>4)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_get_adc1_lsb_force0_num(data)              ((0x0000000C&(data))>>2)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_get_adc0_lsb_force0_num(data)              (0x00000003&(data))

#define  VD_IFD_INPUT_VD_INOUT_CTRL                                              0x180180AC
#define  VD_IFD_INPUT_VD_INOUT_CTRL_reg_addr                                     "0xB80180AC"
#define  VD_IFD_INPUT_VD_INOUT_CTRL_reg                                          0xB80180AC
#define  VD_IFD_INPUT_VD_INOUT_CTRL_inst_addr                                    "0x0006"
#define  set_VD_IFD_INPUT_VD_INOUT_CTRL_reg(data)                                (*((volatile unsigned int*)VD_IFD_INPUT_VD_INOUT_CTRL_reg)=data)
#define  get_VD_IFD_INPUT_VD_INOUT_CTRL_reg                                      (*((volatile unsigned int*)VD_IFD_INPUT_VD_INOUT_CTRL_reg))
#define  VD_IFD_INPUT_VD_INOUT_CTRL_fe_fil_sel_shift                             (4)
#define  VD_IFD_INPUT_VD_INOUT_CTRL_adc27_mod_shift                              (0)
#define  VD_IFD_INPUT_VD_INOUT_CTRL_fe_fil_sel_mask                              (0x00000070)
#define  VD_IFD_INPUT_VD_INOUT_CTRL_adc27_mod_mask                               (0x00000001)
#define  VD_IFD_INPUT_VD_INOUT_CTRL_fe_fil_sel(data)                             (0x00000070&((data)<<4))
#define  VD_IFD_INPUT_VD_INOUT_CTRL_adc27_mod(data)                              (0x00000001&(data))
#define  VD_IFD_INPUT_VD_INOUT_CTRL_get_fe_fil_sel(data)                         ((0x00000070&(data))>>4)
#define  VD_IFD_INPUT_VD_INOUT_CTRL_get_adc27_mod(data)                          (0x00000001&(data))

#define  VD_IFD_INPUT_CRC_EN                                                     0x180180B0
#define  VD_IFD_INPUT_CRC_EN_reg_addr                                            "0xB80180B0"
#define  VD_IFD_INPUT_CRC_EN_reg                                                 0xB80180B0
#define  VD_IFD_INPUT_CRC_EN_inst_addr                                           "0x0007"
#define  set_VD_IFD_INPUT_CRC_EN_reg(data)                                       (*((volatile unsigned int*)VD_IFD_INPUT_CRC_EN_reg)=data)
#define  get_VD_IFD_INPUT_CRC_EN_reg                                             (*((volatile unsigned int*)VD_IFD_INPUT_CRC_EN_reg))
#define  VD_IFD_INPUT_CRC_EN_crc_108mhz_en_shift                                 (0)
#define  VD_IFD_INPUT_CRC_EN_crc_108mhz_en_mask                                  (0x00000001)
#define  VD_IFD_INPUT_CRC_EN_crc_108mhz_en(data)                                 (0x00000001&(data))
#define  VD_IFD_INPUT_CRC_EN_get_crc_108mhz_en(data)                             (0x00000001&(data))

#define  VD_IFD_INPUT_CRC_108MHZ_RESULT1                                         0x180180B4
#define  VD_IFD_INPUT_CRC_108MHZ_RESULT1_reg_addr                                "0xB80180B4"
#define  VD_IFD_INPUT_CRC_108MHZ_RESULT1_reg                                     0xB80180B4
#define  VD_IFD_INPUT_CRC_108MHZ_RESULT1_inst_addr                               "0x0008"
#define  set_VD_IFD_INPUT_CRC_108MHZ_RESULT1_reg(data)                           (*((volatile unsigned int*)VD_IFD_INPUT_CRC_108MHZ_RESULT1_reg)=data)
#define  get_VD_IFD_INPUT_CRC_108MHZ_RESULT1_reg                                 (*((volatile unsigned int*)VD_IFD_INPUT_CRC_108MHZ_RESULT1_reg))
#define  VD_IFD_INPUT_CRC_108MHZ_RESULT1_crc_108mhz_result_1_shift               (0)
#define  VD_IFD_INPUT_CRC_108MHZ_RESULT1_crc_108mhz_result_1_mask                (0xFFFFFFFF)
#define  VD_IFD_INPUT_CRC_108MHZ_RESULT1_crc_108mhz_result_1(data)               (0xFFFFFFFF&(data))
#define  VD_IFD_INPUT_CRC_108MHZ_RESULT1_get_crc_108mhz_result_1(data)           (0xFFFFFFFF&(data))

#define  VD_IFD_INPUT_CRC_108MHZ_RESULT2                                         0x180180B8
#define  VD_IFD_INPUT_CRC_108MHZ_RESULT2_reg_addr                                "0xB80180B8"
#define  VD_IFD_INPUT_CRC_108MHZ_RESULT2_reg                                     0xB80180B8
#define  VD_IFD_INPUT_CRC_108MHZ_RESULT2_inst_addr                               "0x0009"
#define  set_VD_IFD_INPUT_CRC_108MHZ_RESULT2_reg(data)                           (*((volatile unsigned int*)VD_IFD_INPUT_CRC_108MHZ_RESULT2_reg)=data)
#define  get_VD_IFD_INPUT_CRC_108MHZ_RESULT2_reg                                 (*((volatile unsigned int*)VD_IFD_INPUT_CRC_108MHZ_RESULT2_reg))
#define  VD_IFD_INPUT_CRC_108MHZ_RESULT2_crc_108mhz_result_2_shift               (0)
#define  VD_IFD_INPUT_CRC_108MHZ_RESULT2_crc_108mhz_result_2_mask                (0xFFFFFFFF)
#define  VD_IFD_INPUT_CRC_108MHZ_RESULT2_crc_108mhz_result_2(data)               (0xFFFFFFFF&(data))
#define  VD_IFD_INPUT_CRC_108MHZ_RESULT2_get_crc_108mhz_result_2(data)           (0xFFFFFFFF&(data))

#define  VD_IFD_INPUT_INPUT_DEBUG                                                0x180180BC
#define  VD_IFD_INPUT_INPUT_DEBUG_reg_addr                                       "0xB80180BC"
#define  VD_IFD_INPUT_INPUT_DEBUG_reg                                            0xB80180BC
#define  VD_IFD_INPUT_INPUT_DEBUG_inst_addr                                      "0x000A"
#define  set_VD_IFD_INPUT_INPUT_DEBUG_reg(data)                                  (*((volatile unsigned int*)VD_IFD_INPUT_INPUT_DEBUG_reg)=data)
#define  get_VD_IFD_INPUT_INPUT_DEBUG_reg                                        (*((volatile unsigned int*)VD_IFD_INPUT_INPUT_DEBUG_reg))
#define  VD_IFD_INPUT_INPUT_DEBUG_input_debug_sel_shift                          (0)
#define  VD_IFD_INPUT_INPUT_DEBUG_input_debug_sel_mask                           (0x00000003)
#define  VD_IFD_INPUT_INPUT_DEBUG_input_debug_sel(data)                          (0x00000003&(data))
#define  VD_IFD_INPUT_INPUT_DEBUG_get_input_debug_sel(data)                      (0x00000003&(data))

#define  VD_IFD_INPUT_IF_PATTERNGEN                                              0x180180C0
#define  VD_IFD_INPUT_IF_PATTERNGEN_reg_addr                                     "0xB80180C0"
#define  VD_IFD_INPUT_IF_PATTERNGEN_reg                                          0xB80180C0
#define  VD_IFD_INPUT_IF_PATTERNGEN_inst_addr                                    "0x000B"
#define  set_VD_IFD_INPUT_IF_PATTERNGEN_reg(data)                                (*((volatile unsigned int*)VD_IFD_INPUT_IF_PATTERNGEN_reg)=data)
#define  get_VD_IFD_INPUT_IF_PATTERNGEN_reg                                      (*((volatile unsigned int*)VD_IFD_INPUT_IF_PATTERNGEN_reg))
#define  VD_IFD_INPUT_IF_PATTERNGEN_if_patterngen_nco_shift                      (4)
#define  VD_IFD_INPUT_IF_PATTERNGEN_if_patterngen_mod_sel_shift                  (1)
#define  VD_IFD_INPUT_IF_PATTERNGEN_if_patterngen_en_shift                       (0)
#define  VD_IFD_INPUT_IF_PATTERNGEN_if_patterngen_nco_mask                       (0x000FFFF0)
#define  VD_IFD_INPUT_IF_PATTERNGEN_if_patterngen_mod_sel_mask                   (0x00000002)
#define  VD_IFD_INPUT_IF_PATTERNGEN_if_patterngen_en_mask                        (0x00000001)
#define  VD_IFD_INPUT_IF_PATTERNGEN_if_patterngen_nco(data)                      (0x000FFFF0&((data)<<4))
#define  VD_IFD_INPUT_IF_PATTERNGEN_if_patterngen_mod_sel(data)                  (0x00000002&((data)<<1))
#define  VD_IFD_INPUT_IF_PATTERNGEN_if_patterngen_en(data)                       (0x00000001&(data))
#define  VD_IFD_INPUT_IF_PATTERNGEN_get_if_patterngen_nco(data)                  ((0x000FFFF0&(data))>>4)
#define  VD_IFD_INPUT_IF_PATTERNGEN_get_if_patterngen_mod_sel(data)              ((0x00000002&(data))>>1)
#define  VD_IFD_INPUT_IF_PATTERNGEN_get_if_patterngen_en(data)                   (0x00000001&(data))

#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS                                      0x180180D0
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_reg_addr                             "0xB80180D0"
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_reg                                  0xB80180D0
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_inst_addr                            "0x000C"
#define  set_VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_reg(data)                        (*((volatile unsigned int*)VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_reg)=data)
#define  get_VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_reg                              (*((volatile unsigned int*)VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_reg))
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_pg_full_clr_shift         (20)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_pg_empty_clr_shift        (19)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_pg_clr_shift              (18)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_pg_full_shift             (17)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_pg_empty_shift            (16)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_full_clr_shift            (4)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_empty_clr_shift           (3)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_clr_shift                 (2)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_full_shift                (1)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_empty_shift               (0)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_pg_full_clr_mask          (0x00100000)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_pg_empty_clr_mask         (0x00080000)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_pg_clr_mask               (0x00040000)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_pg_full_mask              (0x00020000)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_pg_empty_mask             (0x00010000)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_full_clr_mask             (0x00000010)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_empty_clr_mask            (0x00000008)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_clr_mask                  (0x00000004)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_full_mask                 (0x00000002)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_empty_mask                (0x00000001)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_pg_full_clr(data)         (0x00100000&((data)<<20))
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_pg_empty_clr(data)        (0x00080000&((data)<<19))
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_pg_clr(data)              (0x00040000&((data)<<18))
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_pg_full(data)             (0x00020000&((data)<<17))
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_pg_empty(data)            (0x00010000&((data)<<16))
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_full_clr(data)            (0x00000010&((data)<<4))
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_empty_clr(data)           (0x00000008&((data)<<3))
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_clr(data)                 (0x00000004&((data)<<2))
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_full(data)                (0x00000002&((data)<<1))
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_empty(data)               (0x00000001&(data))
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_get_input_fifo_pg_full_clr(data)     ((0x00100000&(data))>>20)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_get_input_fifo_pg_empty_clr(data)    ((0x00080000&(data))>>19)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_get_input_fifo_pg_clr(data)          ((0x00040000&(data))>>18)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_get_input_fifo_pg_full(data)         ((0x00020000&(data))>>17)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_get_input_fifo_pg_empty(data)        ((0x00010000&(data))>>16)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_get_input_fifo_full_clr(data)        ((0x00000010&(data))>>4)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_get_input_fifo_empty_clr(data)       ((0x00000008&(data))>>3)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_get_input_fifo_clr(data)             ((0x00000004&(data))>>2)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_get_input_fifo_full(data)            ((0x00000002&(data))>>1)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_get_input_fifo_empty(data)           (0x00000001&(data))

#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1                                      0x180180D4
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_reg_addr                             "0xB80180D4"
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_reg                                  0xB80180D4
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_inst_addr                            "0x000D"
#define  set_VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_reg(data)                        (*((volatile unsigned int*)VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_reg)=data)
#define  get_VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_reg                              (*((volatile unsigned int*)VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_reg))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad_debug_full_shift                  (28)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad_debug_empty_shift                 (27)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad5_fifo_full_shift                  (26)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad5_fifo_empty_shift                 (25)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_adc_sync_fifo_clr_shift              (24)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_vdadc_sync_fifo_full_shift           (23)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_vdadc_sync_fifo_empty_shift          (22)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ypp_blu_sync_fifo_full_shift         (21)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ypp_blu_sync_fifo_empty_shift        (20)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ypp_grn_sync_fifo_full_shift         (19)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ypp_grn_sync_fifo_empty_shift        (18)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ypp_red_sync_fifo_full_shift         (17)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ypp_red_sync_fifo_empty_shift        (16)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_scart_sync_fifo_full_shift           (15)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_scart_sync_fifo_empty_shift          (14)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ycref_sync_fifo_full_shift           (13)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ycref_sync_fifo_empty_shift          (12)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_vd_fifo_clr_shift                    (8)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad1_fifo_full_shift                  (7)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad1_fifo_empty_shift                 (6)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad2_fifo_full_shift                  (5)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad2_fifo_empty_shift                 (4)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad3_fifo_full_shift                  (3)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad3_fifo_empty_shift                 (2)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad4_fifo_full_shift                  (1)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad4_fifo_empty_shift                 (0)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad_debug_full_mask                   (0x10000000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad_debug_empty_mask                  (0x08000000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad5_fifo_full_mask                   (0x04000000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad5_fifo_empty_mask                  (0x02000000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_adc_sync_fifo_clr_mask               (0x01000000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_vdadc_sync_fifo_full_mask            (0x00800000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_vdadc_sync_fifo_empty_mask           (0x00400000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ypp_blu_sync_fifo_full_mask          (0x00200000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ypp_blu_sync_fifo_empty_mask         (0x00100000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ypp_grn_sync_fifo_full_mask          (0x00080000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ypp_grn_sync_fifo_empty_mask         (0x00040000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ypp_red_sync_fifo_full_mask          (0x00020000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ypp_red_sync_fifo_empty_mask         (0x00010000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_scart_sync_fifo_full_mask            (0x00008000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_scart_sync_fifo_empty_mask           (0x00004000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ycref_sync_fifo_full_mask            (0x00002000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ycref_sync_fifo_empty_mask           (0x00001000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_vd_fifo_clr_mask                     (0x00000100)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad1_fifo_full_mask                   (0x00000080)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad1_fifo_empty_mask                  (0x00000040)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad2_fifo_full_mask                   (0x00000020)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad2_fifo_empty_mask                  (0x00000010)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad3_fifo_full_mask                   (0x00000008)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad3_fifo_empty_mask                  (0x00000004)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad4_fifo_full_mask                   (0x00000002)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad4_fifo_empty_mask                  (0x00000001)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad_debug_full(data)                  (0x10000000&((data)<<28))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad_debug_empty(data)                 (0x08000000&((data)<<27))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad5_fifo_full(data)                  (0x04000000&((data)<<26))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad5_fifo_empty(data)                 (0x02000000&((data)<<25))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_adc_sync_fifo_clr(data)              (0x01000000&((data)<<24))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_vdadc_sync_fifo_full(data)           (0x00800000&((data)<<23))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_vdadc_sync_fifo_empty(data)          (0x00400000&((data)<<22))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ypp_blu_sync_fifo_full(data)         (0x00200000&((data)<<21))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ypp_blu_sync_fifo_empty(data)        (0x00100000&((data)<<20))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ypp_grn_sync_fifo_full(data)         (0x00080000&((data)<<19))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ypp_grn_sync_fifo_empty(data)        (0x00040000&((data)<<18))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ypp_red_sync_fifo_full(data)         (0x00020000&((data)<<17))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ypp_red_sync_fifo_empty(data)        (0x00010000&((data)<<16))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_scart_sync_fifo_full(data)           (0x00008000&((data)<<15))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_scart_sync_fifo_empty(data)          (0x00004000&((data)<<14))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ycref_sync_fifo_full(data)           (0x00002000&((data)<<13))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ycref_sync_fifo_empty(data)          (0x00001000&((data)<<12))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_vd_fifo_clr(data)                    (0x00000100&((data)<<8))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad1_fifo_full(data)                  (0x00000080&((data)<<7))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad1_fifo_empty(data)                 (0x00000040&((data)<<6))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad2_fifo_full(data)                  (0x00000020&((data)<<5))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad2_fifo_empty(data)                 (0x00000010&((data)<<4))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad3_fifo_full(data)                  (0x00000008&((data)<<3))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad3_fifo_empty(data)                 (0x00000004&((data)<<2))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad4_fifo_full(data)                  (0x00000002&((data)<<1))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad4_fifo_empty(data)                 (0x00000001&(data))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_ad_debug_full(data)              ((0x10000000&(data))>>28)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_ad_debug_empty(data)             ((0x08000000&(data))>>27)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_ad5_fifo_full(data)              ((0x04000000&(data))>>26)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_ad5_fifo_empty(data)             ((0x02000000&(data))>>25)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_adc_sync_fifo_clr(data)          ((0x01000000&(data))>>24)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_vdadc_sync_fifo_full(data)       ((0x00800000&(data))>>23)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_vdadc_sync_fifo_empty(data)      ((0x00400000&(data))>>22)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_ypp_blu_sync_fifo_full(data)     ((0x00200000&(data))>>21)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_ypp_blu_sync_fifo_empty(data)    ((0x00100000&(data))>>20)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_ypp_grn_sync_fifo_full(data)     ((0x00080000&(data))>>19)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_ypp_grn_sync_fifo_empty(data)    ((0x00040000&(data))>>18)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_ypp_red_sync_fifo_full(data)     ((0x00020000&(data))>>17)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_ypp_red_sync_fifo_empty(data)    ((0x00010000&(data))>>16)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_scart_sync_fifo_full(data)       ((0x00008000&(data))>>15)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_scart_sync_fifo_empty(data)      ((0x00004000&(data))>>14)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_ycref_sync_fifo_full(data)       ((0x00002000&(data))>>13)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_ycref_sync_fifo_empty(data)      ((0x00001000&(data))>>12)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_vd_fifo_clr(data)                ((0x00000100&(data))>>8)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_ad1_fifo_full(data)              ((0x00000080&(data))>>7)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_ad1_fifo_empty(data)             ((0x00000040&(data))>>6)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_ad2_fifo_full(data)              ((0x00000020&(data))>>5)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_ad2_fifo_empty(data)             ((0x00000010&(data))>>4)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_ad3_fifo_full(data)              ((0x00000008&(data))>>3)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_ad3_fifo_empty(data)             ((0x00000004&(data))>>2)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_ad4_fifo_full(data)              ((0x00000002&(data))>>1)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_ad4_fifo_empty(data)             (0x00000001&(data))

#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2                                      0x180180D8
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_reg_addr                             "0xB80180D8"
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_reg                                  0xB80180D8
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_inst_addr                            "0x000E"
#define  set_VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_reg(data)                        (*((volatile unsigned int*)VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_reg)=data)
#define  get_VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_reg                              (*((volatile unsigned int*)VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_reg))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad_debug_full_clr_shift              (28)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad_debug_empty_clr_shift             (27)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad5_fifo_full_clr_shift              (26)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad5_fifo_empty_clr_shift             (25)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_vdadc_sync_fifo_full_clr_shift       (23)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_vdadc_sync_fifo_empty_clr_shift      (22)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ypp_blu_sync_fifo_full_clr_shift     (21)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ypp_blu_sync_fifo_empty_clr_shift    (20)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ypp_grn_sync_fifo_full_clr_shift     (19)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ypp_grn_sync_fifo_empty_clr_shift    (18)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ypp_red_sync_fifo_full_clr_shift     (17)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ypp_red_sync_fifo_empty_clr_shift    (16)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_scart_sync_fifo_full_clr_shift       (15)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_scart_sync_fifo_empty_clr_shift      (14)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ycref_sync_fifo_full_clr_shift       (13)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ycref_sync_fifo_empty_clr_shift      (12)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad1_fifo_full_clr_shift              (7)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad1_fifo_empty_clr_shift             (6)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad2_fifo_full_clr_shift              (5)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad2_fifo_empty_clr_shift             (4)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad3_fifo_full_clr_shift              (3)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad3_fifo_empty_clr_shift             (2)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad4_fifo_full_clr_shift              (1)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad4_fifo_empty_clr_shift             (0)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad_debug_full_clr_mask               (0x10000000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad_debug_empty_clr_mask              (0x08000000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad5_fifo_full_clr_mask               (0x04000000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad5_fifo_empty_clr_mask              (0x02000000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_vdadc_sync_fifo_full_clr_mask        (0x00800000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_vdadc_sync_fifo_empty_clr_mask       (0x00400000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ypp_blu_sync_fifo_full_clr_mask      (0x00200000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ypp_blu_sync_fifo_empty_clr_mask     (0x00100000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ypp_grn_sync_fifo_full_clr_mask      (0x00080000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ypp_grn_sync_fifo_empty_clr_mask     (0x00040000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ypp_red_sync_fifo_full_clr_mask      (0x00020000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ypp_red_sync_fifo_empty_clr_mask     (0x00010000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_scart_sync_fifo_full_clr_mask        (0x00008000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_scart_sync_fifo_empty_clr_mask       (0x00004000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ycref_sync_fifo_full_clr_mask        (0x00002000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ycref_sync_fifo_empty_clr_mask       (0x00001000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad1_fifo_full_clr_mask               (0x00000080)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad1_fifo_empty_clr_mask              (0x00000040)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad2_fifo_full_clr_mask               (0x00000020)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad2_fifo_empty_clr_mask              (0x00000010)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad3_fifo_full_clr_mask               (0x00000008)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad3_fifo_empty_clr_mask              (0x00000004)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad4_fifo_full_clr_mask               (0x00000002)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad4_fifo_empty_clr_mask              (0x00000001)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad_debug_full_clr(data)              (0x10000000&((data)<<28))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad_debug_empty_clr(data)             (0x08000000&((data)<<27))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad5_fifo_full_clr(data)              (0x04000000&((data)<<26))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad5_fifo_empty_clr(data)             (0x02000000&((data)<<25))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_vdadc_sync_fifo_full_clr(data)       (0x00800000&((data)<<23))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_vdadc_sync_fifo_empty_clr(data)      (0x00400000&((data)<<22))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ypp_blu_sync_fifo_full_clr(data)     (0x00200000&((data)<<21))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ypp_blu_sync_fifo_empty_clr(data)    (0x00100000&((data)<<20))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ypp_grn_sync_fifo_full_clr(data)     (0x00080000&((data)<<19))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ypp_grn_sync_fifo_empty_clr(data)    (0x00040000&((data)<<18))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ypp_red_sync_fifo_full_clr(data)     (0x00020000&((data)<<17))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ypp_red_sync_fifo_empty_clr(data)    (0x00010000&((data)<<16))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_scart_sync_fifo_full_clr(data)       (0x00008000&((data)<<15))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_scart_sync_fifo_empty_clr(data)      (0x00004000&((data)<<14))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ycref_sync_fifo_full_clr(data)       (0x00002000&((data)<<13))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ycref_sync_fifo_empty_clr(data)      (0x00001000&((data)<<12))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad1_fifo_full_clr(data)              (0x00000080&((data)<<7))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad1_fifo_empty_clr(data)             (0x00000040&((data)<<6))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad2_fifo_full_clr(data)              (0x00000020&((data)<<5))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad2_fifo_empty_clr(data)             (0x00000010&((data)<<4))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad3_fifo_full_clr(data)              (0x00000008&((data)<<3))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad3_fifo_empty_clr(data)             (0x00000004&((data)<<2))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad4_fifo_full_clr(data)              (0x00000002&((data)<<1))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad4_fifo_empty_clr(data)             (0x00000001&(data))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_ad_debug_full_clr(data)          ((0x10000000&(data))>>28)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_ad_debug_empty_clr(data)         ((0x08000000&(data))>>27)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_ad5_fifo_full_clr(data)          ((0x04000000&(data))>>26)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_ad5_fifo_empty_clr(data)         ((0x02000000&(data))>>25)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_vdadc_sync_fifo_full_clr(data)   ((0x00800000&(data))>>23)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_vdadc_sync_fifo_empty_clr(data)  ((0x00400000&(data))>>22)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_ypp_blu_sync_fifo_full_clr(data) ((0x00200000&(data))>>21)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_ypp_blu_sync_fifo_empty_clr(data) ((0x00100000&(data))>>20)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_ypp_grn_sync_fifo_full_clr(data) ((0x00080000&(data))>>19)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_ypp_grn_sync_fifo_empty_clr(data) ((0x00040000&(data))>>18)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_ypp_red_sync_fifo_full_clr(data) ((0x00020000&(data))>>17)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_ypp_red_sync_fifo_empty_clr(data) ((0x00010000&(data))>>16)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_scart_sync_fifo_full_clr(data)   ((0x00008000&(data))>>15)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_scart_sync_fifo_empty_clr(data)  ((0x00004000&(data))>>14)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_ycref_sync_fifo_full_clr(data)   ((0x00002000&(data))>>13)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_ycref_sync_fifo_empty_clr(data)  ((0x00001000&(data))>>12)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_ad1_fifo_full_clr(data)          ((0x00000080&(data))>>7)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_ad1_fifo_empty_clr(data)         ((0x00000040&(data))>>6)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_ad2_fifo_full_clr(data)          ((0x00000020&(data))>>5)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_ad2_fifo_empty_clr(data)         ((0x00000010&(data))>>4)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_ad3_fifo_full_clr(data)          ((0x00000008&(data))>>3)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_ad3_fifo_empty_clr(data)         ((0x00000004&(data))>>2)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_ad4_fifo_full_clr(data)          ((0x00000002&(data))>>1)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_ad4_fifo_empty_clr(data)         (0x00000001&(data))

#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS3                                     0x180180DC
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS3_reg_addr                            "0xB80180DC"
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS3_reg                                 0xB80180DC
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS3_inst_addr                           "0x000F"
#define  set_VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS3_reg(data)                       (*((volatile unsigned int*)VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS3_reg)=data)
#define  get_VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS3_reg                             (*((volatile unsigned int*)VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS3_reg))
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS3_fifo_recover_depth_shift            (8)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS3_fifo_recover_thr_shift              (4)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS3_fifo_recover_en_shift               (0)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS3_fifo_recover_depth_mask             (0x00000300)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS3_fifo_recover_thr_mask               (0x00000070)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS3_fifo_recover_en_mask                (0x00000001)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS3_fifo_recover_depth(data)            (0x00000300&((data)<<8))
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS3_fifo_recover_thr(data)              (0x00000070&((data)<<4))
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS3_fifo_recover_en(data)               (0x00000001&(data))
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS3_get_fifo_recover_depth(data)        ((0x00000300&(data))>>8)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS3_get_fifo_recover_thr(data)          ((0x00000070&(data))>>4)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS3_get_fifo_recover_en(data)           (0x00000001&(data))

#define  VD_IFD_INPUT_IFD_FIFO_CRC                                               0x180180E0
#define  VD_IFD_INPUT_IFD_FIFO_CRC_reg_addr                                      "0xB80180E0"
#define  VD_IFD_INPUT_IFD_FIFO_CRC_reg                                           0xB80180E0
#define  VD_IFD_INPUT_IFD_FIFO_CRC_inst_addr                                     "0x0010"
#define  set_VD_IFD_INPUT_IFD_FIFO_CRC_reg(data)                                 (*((volatile unsigned int*)VD_IFD_INPUT_IFD_FIFO_CRC_reg)=data)
#define  get_VD_IFD_INPUT_IFD_FIFO_CRC_reg                                       (*((volatile unsigned int*)VD_IFD_INPUT_IFD_FIFO_CRC_reg))
#define  VD_IFD_INPUT_IFD_FIFO_CRC_fifo_crc_en_shift                             (0)
#define  VD_IFD_INPUT_IFD_FIFO_CRC_fifo_crc_en_mask                              (0x00000001)
#define  VD_IFD_INPUT_IFD_FIFO_CRC_fifo_crc_en(data)                             (0x00000001&(data))
#define  VD_IFD_INPUT_IFD_FIFO_CRC_get_fifo_crc_en(data)                         (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======VD_IFD_INPUT register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  adc_fifo_in_sel:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  adc_clk_sel:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  input_dn_filter_sel:3;
    };
}vd_ifd_input_input_filter_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  clk54_polar:1;
    };
}vd_ifd_input_ifd_adc_clk_polar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  cp_test_enable:1;
    };
}vd_ifd_input_ifd_cp_test_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ad4_input_delay:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  ad3_input_delay:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  ad2_input_delay:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  ad1_input_delay:5;
    };
}vd_ifd_input_vd_in_delay_sel1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cvbs_tve_mux:1;
        RBus_UInt32  res1:18;
        RBus_UInt32  ad5_input_delay:5;
        RBus_UInt32  res2:4;
        RBus_UInt32  sv_sel:2;
        RBus_UInt32  sv_yc_switch:1;
        RBus_UInt32  sv_in_one_adc:1;
    };
}vd_ifd_input_vd_in_delay_sel2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  scart_input_delay_108:4;
        RBus_UInt32  yppb_input_delay_108:4;
        RBus_UInt32  yppg_input_delay_108:4;
        RBus_UInt32  yppr_input_delay_108:4;
        RBus_UInt32  vdadc_input_delay_108:4;
        RBus_UInt32  adc3_lsb_force0_num:2;
        RBus_UInt32  adc2_lsb_force0_num:2;
        RBus_UInt32  adc1_lsb_force0_num:2;
        RBus_UInt32  adc0_lsb_force0_num:2;
    };
}vd_ifd_input_vd_adc_lsb_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  fe_fil_sel:3;
        RBus_UInt32  res2:3;
        RBus_UInt32  adc27_mod:1;
    };
}vd_ifd_input_vd_inout_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  crc_108mhz_en:1;
    };
}vd_ifd_input_crc_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_108mhz_result_1:32;
    };
}vd_ifd_input_crc_108mhz_result1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_108mhz_result_2:32;
    };
}vd_ifd_input_crc_108mhz_result2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  input_debug_sel:2;
    };
}vd_ifd_input_input_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  if_patterngen_nco:16;
        RBus_UInt32  res2:2;
        RBus_UInt32  if_patterngen_mod_sel:1;
        RBus_UInt32  if_patterngen_en:1;
    };
}vd_ifd_input_if_patterngen_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  input_fifo_pg_full_clr:1;
        RBus_UInt32  input_fifo_pg_empty_clr:1;
        RBus_UInt32  input_fifo_pg_clr:1;
        RBus_UInt32  input_fifo_pg_full:1;
        RBus_UInt32  input_fifo_pg_empty:1;
        RBus_UInt32  res2:11;
        RBus_UInt32  input_fifo_full_clr:1;
        RBus_UInt32  input_fifo_empty_clr:1;
        RBus_UInt32  input_fifo_clr:1;
        RBus_UInt32  input_fifo_full:1;
        RBus_UInt32  input_fifo_empty:1;
    };
}vd_ifd_input_ifd_input_fifo_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ad_debug_full:1;
        RBus_UInt32  ad_debug_empty:1;
        RBus_UInt32  ad5_fifo_full:1;
        RBus_UInt32  ad5_fifo_empty:1;
        RBus_UInt32  adc_sync_fifo_clr:1;
        RBus_UInt32  vdadc_sync_fifo_full:1;
        RBus_UInt32  vdadc_sync_fifo_empty:1;
        RBus_UInt32  ypp_blu_sync_fifo_full:1;
        RBus_UInt32  ypp_blu_sync_fifo_empty:1;
        RBus_UInt32  ypp_grn_sync_fifo_full:1;
        RBus_UInt32  ypp_grn_sync_fifo_empty:1;
        RBus_UInt32  ypp_red_sync_fifo_full:1;
        RBus_UInt32  ypp_red_sync_fifo_empty:1;
        RBus_UInt32  scart_sync_fifo_full:1;
        RBus_UInt32  scart_sync_fifo_empty:1;
        RBus_UInt32  ycref_sync_fifo_full:1;
        RBus_UInt32  ycref_sync_fifo_empty:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  vd_fifo_clr:1;
        RBus_UInt32  ad1_fifo_full:1;
        RBus_UInt32  ad1_fifo_empty:1;
        RBus_UInt32  ad2_fifo_full:1;
        RBus_UInt32  ad2_fifo_empty:1;
        RBus_UInt32  ad3_fifo_full:1;
        RBus_UInt32  ad3_fifo_empty:1;
        RBus_UInt32  ad4_fifo_full:1;
        RBus_UInt32  ad4_fifo_empty:1;
    };
}vd_ifd_input_vd_input_fifo_status1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ad_debug_full_clr:1;
        RBus_UInt32  ad_debug_empty_clr:1;
        RBus_UInt32  ad5_fifo_full_clr:1;
        RBus_UInt32  ad5_fifo_empty_clr:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  vdadc_sync_fifo_full_clr:1;
        RBus_UInt32  vdadc_sync_fifo_empty_clr:1;
        RBus_UInt32  ypp_blu_sync_fifo_full_clr:1;
        RBus_UInt32  ypp_blu_sync_fifo_empty_clr:1;
        RBus_UInt32  ypp_grn_sync_fifo_full_clr:1;
        RBus_UInt32  ypp_grn_sync_fifo_empty_clr:1;
        RBus_UInt32  ypp_red_sync_fifo_full_clr:1;
        RBus_UInt32  ypp_red_sync_fifo_empty_clr:1;
        RBus_UInt32  scart_sync_fifo_full_clr:1;
        RBus_UInt32  scart_sync_fifo_empty_clr:1;
        RBus_UInt32  ycref_sync_fifo_full_clr:1;
        RBus_UInt32  ycref_sync_fifo_empty_clr:1;
        RBus_UInt32  res3:4;
        RBus_UInt32  ad1_fifo_full_clr:1;
        RBus_UInt32  ad1_fifo_empty_clr:1;
        RBus_UInt32  ad2_fifo_full_clr:1;
        RBus_UInt32  ad2_fifo_empty_clr:1;
        RBus_UInt32  ad3_fifo_full_clr:1;
        RBus_UInt32  ad3_fifo_empty_clr:1;
        RBus_UInt32  ad4_fifo_full_clr:1;
        RBus_UInt32  ad4_fifo_empty_clr:1;
    };
}vd_ifd_input_vd_input_fifo_status2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  fifo_recover_depth:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  fifo_recover_thr:3;
        RBus_UInt32  res3:3;
        RBus_UInt32  fifo_recover_en:1;
    };
}vd_ifd_input_ifd_input_fifo_status3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  fifo_crc_en:1;
    };
}vd_ifd_input_ifd_fifo_crc_RBUS;

#else //apply LITTLE_ENDIAN

//======VD_IFD_INPUT register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_dn_filter_sel:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  adc_clk_sel:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  adc_fifo_in_sel:1;
        RBus_UInt32  res3:23;
    };
}vd_ifd_input_input_filter_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clk54_polar:1;
        RBus_UInt32  res1:31;
    };
}vd_ifd_input_ifd_adc_clk_polar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_test_enable:1;
        RBus_UInt32  res1:31;
    };
}vd_ifd_input_ifd_cp_test_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ad1_input_delay:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  ad2_input_delay:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  ad3_input_delay:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  ad4_input_delay:5;
        RBus_UInt32  res4:3;
    };
}vd_ifd_input_vd_in_delay_sel1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sv_in_one_adc:1;
        RBus_UInt32  sv_yc_switch:1;
        RBus_UInt32  sv_sel:2;
        RBus_UInt32  res1:4;
        RBus_UInt32  ad5_input_delay:5;
        RBus_UInt32  res2:18;
        RBus_UInt32  cvbs_tve_mux:1;
    };
}vd_ifd_input_vd_in_delay_sel2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc0_lsb_force0_num:2;
        RBus_UInt32  adc1_lsb_force0_num:2;
        RBus_UInt32  adc2_lsb_force0_num:2;
        RBus_UInt32  adc3_lsb_force0_num:2;
        RBus_UInt32  vdadc_input_delay_108:4;
        RBus_UInt32  yppr_input_delay_108:4;
        RBus_UInt32  yppg_input_delay_108:4;
        RBus_UInt32  yppb_input_delay_108:4;
        RBus_UInt32  scart_input_delay_108:4;
        RBus_UInt32  res1:4;
    };
}vd_ifd_input_vd_adc_lsb_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc27_mod:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  fe_fil_sel:3;
        RBus_UInt32  res2:25;
    };
}vd_ifd_input_vd_inout_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_108mhz_en:1;
        RBus_UInt32  res1:31;
    };
}vd_ifd_input_crc_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_108mhz_result_1:32;
    };
}vd_ifd_input_crc_108mhz_result1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_108mhz_result_2:32;
    };
}vd_ifd_input_crc_108mhz_result2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_debug_sel:2;
        RBus_UInt32  res1:30;
    };
}vd_ifd_input_input_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  if_patterngen_en:1;
        RBus_UInt32  if_patterngen_mod_sel:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  if_patterngen_nco:16;
        RBus_UInt32  res2:12;
    };
}vd_ifd_input_if_patterngen_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_fifo_empty:1;
        RBus_UInt32  input_fifo_full:1;
        RBus_UInt32  input_fifo_clr:1;
        RBus_UInt32  input_fifo_empty_clr:1;
        RBus_UInt32  input_fifo_full_clr:1;
        RBus_UInt32  res1:11;
        RBus_UInt32  input_fifo_pg_empty:1;
        RBus_UInt32  input_fifo_pg_full:1;
        RBus_UInt32  input_fifo_pg_clr:1;
        RBus_UInt32  input_fifo_pg_empty_clr:1;
        RBus_UInt32  input_fifo_pg_full_clr:1;
        RBus_UInt32  res2:11;
    };
}vd_ifd_input_ifd_input_fifo_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ad4_fifo_empty:1;
        RBus_UInt32  ad4_fifo_full:1;
        RBus_UInt32  ad3_fifo_empty:1;
        RBus_UInt32  ad3_fifo_full:1;
        RBus_UInt32  ad2_fifo_empty:1;
        RBus_UInt32  ad2_fifo_full:1;
        RBus_UInt32  ad1_fifo_empty:1;
        RBus_UInt32  ad1_fifo_full:1;
        RBus_UInt32  vd_fifo_clr:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  ycref_sync_fifo_empty:1;
        RBus_UInt32  ycref_sync_fifo_full:1;
        RBus_UInt32  scart_sync_fifo_empty:1;
        RBus_UInt32  scart_sync_fifo_full:1;
        RBus_UInt32  ypp_red_sync_fifo_empty:1;
        RBus_UInt32  ypp_red_sync_fifo_full:1;
        RBus_UInt32  ypp_grn_sync_fifo_empty:1;
        RBus_UInt32  ypp_grn_sync_fifo_full:1;
        RBus_UInt32  ypp_blu_sync_fifo_empty:1;
        RBus_UInt32  ypp_blu_sync_fifo_full:1;
        RBus_UInt32  vdadc_sync_fifo_empty:1;
        RBus_UInt32  vdadc_sync_fifo_full:1;
        RBus_UInt32  adc_sync_fifo_clr:1;
        RBus_UInt32  ad5_fifo_empty:1;
        RBus_UInt32  ad5_fifo_full:1;
        RBus_UInt32  ad_debug_empty:1;
        RBus_UInt32  ad_debug_full:1;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_vd_input_fifo_status1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ad4_fifo_empty_clr:1;
        RBus_UInt32  ad4_fifo_full_clr:1;
        RBus_UInt32  ad3_fifo_empty_clr:1;
        RBus_UInt32  ad3_fifo_full_clr:1;
        RBus_UInt32  ad2_fifo_empty_clr:1;
        RBus_UInt32  ad2_fifo_full_clr:1;
        RBus_UInt32  ad1_fifo_empty_clr:1;
        RBus_UInt32  ad1_fifo_full_clr:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  ycref_sync_fifo_empty_clr:1;
        RBus_UInt32  ycref_sync_fifo_full_clr:1;
        RBus_UInt32  scart_sync_fifo_empty_clr:1;
        RBus_UInt32  scart_sync_fifo_full_clr:1;
        RBus_UInt32  ypp_red_sync_fifo_empty_clr:1;
        RBus_UInt32  ypp_red_sync_fifo_full_clr:1;
        RBus_UInt32  ypp_grn_sync_fifo_empty_clr:1;
        RBus_UInt32  ypp_grn_sync_fifo_full_clr:1;
        RBus_UInt32  ypp_blu_sync_fifo_empty_clr:1;
        RBus_UInt32  ypp_blu_sync_fifo_full_clr:1;
        RBus_UInt32  vdadc_sync_fifo_empty_clr:1;
        RBus_UInt32  vdadc_sync_fifo_full_clr:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  ad5_fifo_empty_clr:1;
        RBus_UInt32  ad5_fifo_full_clr:1;
        RBus_UInt32  ad_debug_empty_clr:1;
        RBus_UInt32  ad_debug_full_clr:1;
        RBus_UInt32  res3:3;
    };
}vd_ifd_input_vd_input_fifo_status2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fifo_recover_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  fifo_recover_thr:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  fifo_recover_depth:2;
        RBus_UInt32  res3:22;
    };
}vd_ifd_input_ifd_input_fifo_status3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fifo_crc_en:1;
        RBus_UInt32  res1:31;
    };
}vd_ifd_input_ifd_fifo_crc_RBUS;




#endif 


#endif 
