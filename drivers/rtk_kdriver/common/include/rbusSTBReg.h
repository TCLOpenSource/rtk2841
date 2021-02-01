/**
* @file rbusSTBReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015-2-16
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_STB_REG_H_
#define _RBUS_STB_REG_H_

#include "rbusTypes.h"



//  STB Register Address
#define  STB_SC_VerID                                                            0x18060000
#define  STB_SC_VerID_reg_addr                                                   "0xB8060000"
#define  STB_SC_VerID_reg                                                        0xB8060000
#define  STB_SC_VerID_inst_addr                                                  "0x0000"
#define  set_STB_SC_VerID_reg(data)                                              (*((volatile unsigned int*)STB_SC_VerID_reg)=data)
#define  get_STB_SC_VerID_reg                                                    (*((volatile unsigned int*)STB_SC_VerID_reg))
#define  STB_SC_VerID_vercode_shift                                              (0)
#define  STB_SC_VerID_vercode_mask                                               (0xFFFFFFFF)
#define  STB_SC_VerID_vercode(data)                                              (0xFFFFFFFF&(data))
#define  STB_SC_VerID_get_vercode(data)                                          (0xFFFFFFFF&(data))

#define  STB_SC_LV_RST                                                           0x18060004
#define  STB_SC_LV_RST_reg_addr                                                  "0xB8060004"
#define  STB_SC_LV_RST_reg                                                       0xB8060004
#define  STB_SC_LV_RST_inst_addr                                                 "0x0001"
#define  set_STB_SC_LV_RST_reg(data)                                             (*((volatile unsigned int*)STB_SC_LV_RST_reg)=data)
#define  get_STB_SC_LV_RST_reg                                                   (*((volatile unsigned int*)STB_SC_LV_RST_reg))
#define  STB_SC_LV_RST_por_reser_shift                                           (20)
#define  STB_SC_LV_RST_dummy_shift                                               (16)
#define  STB_SC_LV_RST_en_emb_shift                                              (15)
#define  STB_SC_LV_RST_main_pow_on_shift                                         (14)
#define  STB_SC_LV_RST_main_por_en_shift                                         (13)
#define  STB_SC_LV_RST_pll27x_top_en_shift                                       (12)
#define  STB_SC_LV_RST_por_v33set_l_shift                                        (10)
#define  STB_SC_LV_RST_por_v10set_l_shift                                        (8)
#define  STB_SC_LV_RST_por_scpu_sel_l_shift                                      (4)
#define  STB_SC_LV_RST_ldov10_sel_shift                                          (1)
#define  STB_SC_LV_RST_stbldo_pow_shift                                          (0)
#define  STB_SC_LV_RST_por_reser_mask                                            (0xFFF00000)
#define  STB_SC_LV_RST_dummy_mask                                                (0x000F0000)
#define  STB_SC_LV_RST_en_emb_mask                                               (0x00008000)
#define  STB_SC_LV_RST_main_pow_on_mask                                          (0x00004000)
#define  STB_SC_LV_RST_main_por_en_mask                                          (0x00002000)
#define  STB_SC_LV_RST_pll27x_top_en_mask                                        (0x00001000)
#define  STB_SC_LV_RST_por_v33set_l_mask                                         (0x00000C00)
#define  STB_SC_LV_RST_por_v10set_l_mask                                         (0x00000300)
#define  STB_SC_LV_RST_por_scpu_sel_l_mask                                       (0x00000030)
#define  STB_SC_LV_RST_ldov10_sel_mask                                           (0x0000000E)
#define  STB_SC_LV_RST_stbldo_pow_mask                                           (0x00000001)
#define  STB_SC_LV_RST_por_reser(data)                                           (0xFFF00000&((data)<<20))
#define  STB_SC_LV_RST_dummy(data)                                               (0x000F0000&((data)<<16))
#define  STB_SC_LV_RST_en_emb(data)                                              (0x00008000&((data)<<15))
#define  STB_SC_LV_RST_main_pow_on(data)                                         (0x00004000&((data)<<14))
#define  STB_SC_LV_RST_main_por_en(data)                                         (0x00002000&((data)<<13))
#define  STB_SC_LV_RST_pll27x_top_en(data)                                       (0x00001000&((data)<<12))
#define  STB_SC_LV_RST_por_v33set_l(data)                                        (0x00000C00&((data)<<10))
#define  STB_SC_LV_RST_por_v10set_l(data)                                        (0x00000300&((data)<<8))
#define  STB_SC_LV_RST_por_scpu_sel_l(data)                                      (0x00000030&((data)<<4))
#define  STB_SC_LV_RST_ldov10_sel(data)                                          (0x0000000E&((data)<<1))
#define  STB_SC_LV_RST_stbldo_pow(data)                                          (0x00000001&(data))
#define  STB_SC_LV_RST_get_por_reser(data)                                       ((0xFFF00000&(data))>>20)
#define  STB_SC_LV_RST_get_dummy(data)                                           ((0x000F0000&(data))>>16)
#define  STB_SC_LV_RST_get_en_emb(data)                                          ((0x00008000&(data))>>15)
#define  STB_SC_LV_RST_get_main_pow_on(data)                                     ((0x00004000&(data))>>14)
#define  STB_SC_LV_RST_get_main_por_en(data)                                     ((0x00002000&(data))>>13)
#define  STB_SC_LV_RST_get_pll27x_top_en(data)                                   ((0x00001000&(data))>>12)
#define  STB_SC_LV_RST_get_por_v33set_l(data)                                    ((0x00000C00&(data))>>10)
#define  STB_SC_LV_RST_get_por_v10set_l(data)                                    ((0x00000300&(data))>>8)
#define  STB_SC_LV_RST_get_por_scpu_sel_l(data)                                  ((0x00000030&(data))>>4)
#define  STB_SC_LV_RST_get_ldov10_sel(data)                                      ((0x0000000E&(data))>>1)
#define  STB_SC_LV_RST_get_stbldo_pow(data)                                      (0x00000001&(data))

#define  STB_SC_POL                                                              0x18060008
#define  STB_SC_POL_reg_addr                                                     "0xB8060008"
#define  STB_SC_POL_reg                                                          0xB8060008
#define  STB_SC_POL_inst_addr                                                    "0x0002"
#define  set_STB_SC_POL_reg(data)                                                (*((volatile unsigned int*)STB_SC_POL_reg)=data)
#define  get_STB_SC_POL_reg                                                      (*((volatile unsigned int*)STB_SC_POL_reg))
#define  STB_SC_POL_boption_rst_bypass_n_shift                                   (31)
#define  STB_SC_POL_boption_efuse_shift                                          (30)
#define  STB_SC_POL_boption_otpclk_rosc_shift                                    (29)
#define  STB_SC_POL_dummy_shift                                                  (20)
#define  STB_SC_POL_at_speed_pll_done_shift                                      (19)
#define  STB_SC_POL_porl_host_s_en_n_shift                                       (18)
#define  STB_SC_POL_porl_at_speed_scan_shift                                     (17)
#define  STB_SC_POL_porl_boot_mode_shift                                         (16)
#define  STB_SC_POL_porl_test_mode_shift                                         (4)
#define  STB_SC_POL_porl_test_en_n_shift                                         (3)
#define  STB_SC_POL_porl_pll_en_shift                                            (2)
#define  STB_SC_POL_porl_ejtag_en_n_shift                                        (1)
#define  STB_SC_POL_boption_rst_bypass_n_mask                                    (0x80000000)
#define  STB_SC_POL_boption_efuse_mask                                           (0x40000000)
#define  STB_SC_POL_boption_otpclk_rosc_mask                                     (0x20000000)
#define  STB_SC_POL_dummy_mask                                                   (0x1FF00000)
#define  STB_SC_POL_at_speed_pll_done_mask                                       (0x00080000)
#define  STB_SC_POL_porl_host_s_en_n_mask                                        (0x00040000)
#define  STB_SC_POL_porl_at_speed_scan_mask                                      (0x00020000)
#define  STB_SC_POL_porl_boot_mode_mask                                          (0x00010000)
#define  STB_SC_POL_porl_test_mode_mask                                          (0x000003F0)
#define  STB_SC_POL_porl_test_en_n_mask                                          (0x00000008)
#define  STB_SC_POL_porl_pll_en_mask                                             (0x00000004)
#define  STB_SC_POL_porl_ejtag_en_n_mask                                         (0x00000002)
#define  STB_SC_POL_boption_rst_bypass_n(data)                                   (0x80000000&((data)<<31))
#define  STB_SC_POL_boption_efuse(data)                                          (0x40000000&((data)<<30))
#define  STB_SC_POL_boption_otpclk_rosc(data)                                    (0x20000000&((data)<<29))
#define  STB_SC_POL_dummy(data)                                                  (0x1FF00000&((data)<<20))
#define  STB_SC_POL_at_speed_pll_done(data)                                      (0x00080000&((data)<<19))
#define  STB_SC_POL_porl_host_s_en_n(data)                                       (0x00040000&((data)<<18))
#define  STB_SC_POL_porl_at_speed_scan(data)                                     (0x00020000&((data)<<17))
#define  STB_SC_POL_porl_boot_mode(data)                                         (0x00010000&((data)<<16))
#define  STB_SC_POL_porl_test_mode(data)                                         (0x000003F0&((data)<<4))
#define  STB_SC_POL_porl_test_en_n(data)                                         (0x00000008&((data)<<3))
#define  STB_SC_POL_porl_pll_en(data)                                            (0x00000004&((data)<<2))
#define  STB_SC_POL_porl_ejtag_en_n(data)                                        (0x00000002&((data)<<1))
#define  STB_SC_POL_get_boption_rst_bypass_n(data)                               ((0x80000000&(data))>>31)
#define  STB_SC_POL_get_boption_efuse(data)                                      ((0x40000000&(data))>>30)
#define  STB_SC_POL_get_boption_otpclk_rosc(data)                                ((0x20000000&(data))>>29)
#define  STB_SC_POL_get_dummy(data)                                              ((0x1FF00000&(data))>>20)
#define  STB_SC_POL_get_at_speed_pll_done(data)                                  ((0x00080000&(data))>>19)
#define  STB_SC_POL_get_porl_host_s_en_n(data)                                   ((0x00040000&(data))>>18)
#define  STB_SC_POL_get_porl_at_speed_scan(data)                                 ((0x00020000&(data))>>17)
#define  STB_SC_POL_get_porl_boot_mode(data)                                     ((0x00010000&(data))>>16)
#define  STB_SC_POL_get_porl_test_mode(data)                                     ((0x000003F0&(data))>>4)
#define  STB_SC_POL_get_porl_test_en_n(data)                                     ((0x00000008&(data))>>3)
#define  STB_SC_POL_get_porl_pll_en(data)                                        ((0x00000004&(data))>>2)
#define  STB_SC_POL_get_porl_ejtag_en_n(data)                                    ((0x00000002&(data))>>1)

#define  STB_ST_CTRL0                                                            0x18060010
#define  STB_ST_CTRL0_reg_addr                                                   "0xB8060010"
#define  STB_ST_CTRL0_reg                                                        0xB8060010
#define  STB_ST_CTRL0_inst_addr                                                  "0x0003"
#define  set_STB_ST_CTRL0_reg(data)                                              (*((volatile unsigned int*)STB_ST_CTRL0_reg)=data)
#define  get_STB_ST_CTRL0_reg                                                    (*((volatile unsigned int*)STB_ST_CTRL0_reg))
#define  STB_ST_CTRL0_ddr_iso_rst1_en_shift                                      (5)
#define  STB_ST_CTRL0_efuse_isln_en_shift                                        (4)
#define  STB_ST_CTRL0_ddr_isln_en_shift                                          (3)
#define  STB_ST_CTRL0_getn_isln_en_shift                                         (2)
#define  STB_ST_CTRL0_rstn_mt_shift                                              (1)
#define  STB_ST_CTRL0_mt_isln_en_shift                                           (0)
#define  STB_ST_CTRL0_ddr_iso_rst1_en_mask                                       (0x00000020)
#define  STB_ST_CTRL0_efuse_isln_en_mask                                         (0x00000010)
#define  STB_ST_CTRL0_ddr_isln_en_mask                                           (0x00000008)
#define  STB_ST_CTRL0_getn_isln_en_mask                                          (0x00000004)
#define  STB_ST_CTRL0_rstn_mt_mask                                               (0x00000002)
#define  STB_ST_CTRL0_mt_isln_en_mask                                            (0x00000001)
#define  STB_ST_CTRL0_ddr_iso_rst1_en(data)                                      (0x00000020&((data)<<5))
#define  STB_ST_CTRL0_efuse_isln_en(data)                                        (0x00000010&((data)<<4))
#define  STB_ST_CTRL0_ddr_isln_en(data)                                          (0x00000008&((data)<<3))
#define  STB_ST_CTRL0_getn_isln_en(data)                                         (0x00000004&((data)<<2))
#define  STB_ST_CTRL0_rstn_mt(data)                                              (0x00000002&((data)<<1))
#define  STB_ST_CTRL0_mt_isln_en(data)                                           (0x00000001&(data))
#define  STB_ST_CTRL0_get_ddr_iso_rst1_en(data)                                  ((0x00000020&(data))>>5)
#define  STB_ST_CTRL0_get_efuse_isln_en(data)                                    ((0x00000010&(data))>>4)
#define  STB_ST_CTRL0_get_ddr_isln_en(data)                                      ((0x00000008&(data))>>3)
#define  STB_ST_CTRL0_get_getn_isln_en(data)                                     ((0x00000004&(data))>>2)
#define  STB_ST_CTRL0_get_rstn_mt(data)                                          ((0x00000002&(data))>>1)
#define  STB_ST_CTRL0_get_mt_isln_en(data)                                       (0x00000001&(data))

#define  STB_ST_SRST0                                                            0x18060030
#define  STB_ST_SRST0_reg_addr                                                   "0xB8060030"
#define  STB_ST_SRST0_reg                                                        0xB8060030
#define  STB_ST_SRST0_inst_addr                                                  "0x0004"
#define  set_STB_ST_SRST0_reg(data)                                              (*((volatile unsigned int*)STB_ST_SRST0_reg)=data)
#define  get_STB_ST_SRST0_reg                                                    (*((volatile unsigned int*)STB_ST_SRST0_reg))
#define  STB_ST_SRST0_rstn_getn_shift                                            (8)
#define  STB_ST_SRST0_rstn_iso_vfd_shift                                         (7)
#define  STB_ST_SRST0_rstn_i2c0_off_shift                                        (6)
#define  STB_ST_SRST0_rstn_uart0_off_shift                                       (5)
#define  STB_ST_SRST0_rstn_irda_off_shift                                        (4)
#define  STB_ST_SRST0_rstn_pwm_shift                                             (3)
#define  STB_ST_SRST0_rstn_pad_mux_shift                                         (2)
#define  STB_ST_SRST0_rstn_iso_misc_off_shift                                    (1)
#define  STB_ST_SRST0_rstn_iso_misc_shift                                        (0)
#define  STB_ST_SRST0_rstn_getn_mask                                             (0x00000100)
#define  STB_ST_SRST0_rstn_iso_vfd_mask                                          (0x00000080)
#define  STB_ST_SRST0_rstn_i2c0_off_mask                                         (0x00000040)
#define  STB_ST_SRST0_rstn_uart0_off_mask                                        (0x00000020)
#define  STB_ST_SRST0_rstn_irda_off_mask                                         (0x00000010)
#define  STB_ST_SRST0_rstn_pwm_mask                                              (0x00000008)
#define  STB_ST_SRST0_rstn_pad_mux_mask                                          (0x00000004)
#define  STB_ST_SRST0_rstn_iso_misc_off_mask                                     (0x00000002)
#define  STB_ST_SRST0_rstn_iso_misc_mask                                         (0x00000001)
#define  STB_ST_SRST0_rstn_getn(data)                                            (0x00000100&((data)<<8))
#define  STB_ST_SRST0_rstn_iso_vfd(data)                                         (0x00000080&((data)<<7))
#define  STB_ST_SRST0_rstn_i2c0_off(data)                                        (0x00000040&((data)<<6))
#define  STB_ST_SRST0_rstn_uart0_off(data)                                       (0x00000020&((data)<<5))
#define  STB_ST_SRST0_rstn_irda_off(data)                                        (0x00000010&((data)<<4))
#define  STB_ST_SRST0_rstn_pwm(data)                                             (0x00000008&((data)<<3))
#define  STB_ST_SRST0_rstn_pad_mux(data)                                         (0x00000004&((data)<<2))
#define  STB_ST_SRST0_rstn_iso_misc_off(data)                                    (0x00000002&((data)<<1))
#define  STB_ST_SRST0_rstn_iso_misc(data)                                        (0x00000001&(data))
#define  STB_ST_SRST0_get_rstn_getn(data)                                        ((0x00000100&(data))>>8)
#define  STB_ST_SRST0_get_rstn_iso_vfd(data)                                     ((0x00000080&(data))>>7)
#define  STB_ST_SRST0_get_rstn_i2c0_off(data)                                    ((0x00000040&(data))>>6)
#define  STB_ST_SRST0_get_rstn_uart0_off(data)                                   ((0x00000020&(data))>>5)
#define  STB_ST_SRST0_get_rstn_irda_off(data)                                    ((0x00000010&(data))>>4)
#define  STB_ST_SRST0_get_rstn_pwm(data)                                         ((0x00000008&(data))>>3)
#define  STB_ST_SRST0_get_rstn_pad_mux(data)                                     ((0x00000004&(data))>>2)
#define  STB_ST_SRST0_get_rstn_iso_misc_off(data)                                ((0x00000002&(data))>>1)
#define  STB_ST_SRST0_get_rstn_iso_misc(data)                                    (0x00000001&(data))

#define  STB_ST_SRST1                                                            0x18060034
#define  STB_ST_SRST1_reg_addr                                                   "0xB8060034"
#define  STB_ST_SRST1_reg                                                        0xB8060034
#define  STB_ST_SRST1_inst_addr                                                  "0x0005"
#define  set_STB_ST_SRST1_reg(data)                                              (*((volatile unsigned int*)STB_ST_SRST1_reg)=data)
#define  get_STB_ST_SRST1_reg                                                    (*((volatile unsigned int*)STB_ST_SRST1_reg))
#define  STB_ST_SRST1_rstn_ddc3_shift                                            (15)
#define  STB_ST_SRST1_rstn_ddc2_shift                                            (14)
#define  STB_ST_SRST1_rstn_ddc1_shift                                            (13)
#define  STB_ST_SRST1_rstn_osc_shift                                             (12)
#define  STB_ST_SRST1_rstn_emcu_top_shift                                        (10)
#define  STB_ST_SRST1_rstn_emcu_core_shift                                       (9)
#define  STB_ST_SRST1_rstn_hdmi_det_shift                                        (8)
#define  STB_ST_SRST1_rstn_cec_shift                                             (7)
#define  STB_ST_SRST1_rstn_syncp_shift                                           (6)
#define  STB_ST_SRST1_rstn_cbus_tx_shift                                         (5)
#define  STB_ST_SRST1_rstn_cbus_shift                                            (4)
#define  STB_ST_SRST1_rstn_alu_shift                                             (3)
#define  STB_ST_SRST1_rstn_irda_shift                                            (2)
#define  STB_ST_SRST1_rstn_ddc_shift                                             (1)
#define  STB_ST_SRST1_rstn_lsadc_shift                                           (0)
#define  STB_ST_SRST1_rstn_ddc3_mask                                             (0x00008000)
#define  STB_ST_SRST1_rstn_ddc2_mask                                             (0x00004000)
#define  STB_ST_SRST1_rstn_ddc1_mask                                             (0x00002000)
#define  STB_ST_SRST1_rstn_osc_mask                                              (0x00001000)
#define  STB_ST_SRST1_rstn_emcu_top_mask                                         (0x00000400)
#define  STB_ST_SRST1_rstn_emcu_core_mask                                        (0x00000200)
#define  STB_ST_SRST1_rstn_hdmi_det_mask                                         (0x00000100)
#define  STB_ST_SRST1_rstn_cec_mask                                              (0x00000080)
#define  STB_ST_SRST1_rstn_syncp_mask                                            (0x00000040)
#define  STB_ST_SRST1_rstn_cbus_tx_mask                                          (0x00000020)
#define  STB_ST_SRST1_rstn_cbus_mask                                             (0x00000010)
#define  STB_ST_SRST1_rstn_alu_mask                                              (0x00000008)
#define  STB_ST_SRST1_rstn_irda_mask                                             (0x00000004)
#define  STB_ST_SRST1_rstn_ddc_mask                                              (0x00000002)
#define  STB_ST_SRST1_rstn_lsadc_mask                                            (0x00000001)
#define  STB_ST_SRST1_rstn_ddc3(data)                                            (0x00008000&((data)<<15))
#define  STB_ST_SRST1_rstn_ddc2(data)                                            (0x00004000&((data)<<14))
#define  STB_ST_SRST1_rstn_ddc1(data)                                            (0x00002000&((data)<<13))
#define  STB_ST_SRST1_rstn_osc(data)                                             (0x00001000&((data)<<12))
#define  STB_ST_SRST1_rstn_emcu_top(data)                                        (0x00000400&((data)<<10))
#define  STB_ST_SRST1_rstn_emcu_core(data)                                       (0x00000200&((data)<<9))
#define  STB_ST_SRST1_rstn_hdmi_det(data)                                        (0x00000100&((data)<<8))
#define  STB_ST_SRST1_rstn_cec(data)                                             (0x00000080&((data)<<7))
#define  STB_ST_SRST1_rstn_syncp(data)                                           (0x00000040&((data)<<6))
#define  STB_ST_SRST1_rstn_cbus_tx(data)                                         (0x00000020&((data)<<5))
#define  STB_ST_SRST1_rstn_cbus(data)                                            (0x00000010&((data)<<4))
#define  STB_ST_SRST1_rstn_alu(data)                                             (0x00000008&((data)<<3))
#define  STB_ST_SRST1_rstn_irda(data)                                            (0x00000004&((data)<<2))
#define  STB_ST_SRST1_rstn_ddc(data)                                             (0x00000002&((data)<<1))
#define  STB_ST_SRST1_rstn_lsadc(data)                                           (0x00000001&(data))
#define  STB_ST_SRST1_get_rstn_ddc3(data)                                        ((0x00008000&(data))>>15)
#define  STB_ST_SRST1_get_rstn_ddc2(data)                                        ((0x00004000&(data))>>14)
#define  STB_ST_SRST1_get_rstn_ddc1(data)                                        ((0x00002000&(data))>>13)
#define  STB_ST_SRST1_get_rstn_osc(data)                                         ((0x00001000&(data))>>12)
#define  STB_ST_SRST1_get_rstn_emcu_top(data)                                    ((0x00000400&(data))>>10)
#define  STB_ST_SRST1_get_rstn_emcu_core(data)                                   ((0x00000200&(data))>>9)
#define  STB_ST_SRST1_get_rstn_hdmi_det(data)                                    ((0x00000100&(data))>>8)
#define  STB_ST_SRST1_get_rstn_cec(data)                                         ((0x00000080&(data))>>7)
#define  STB_ST_SRST1_get_rstn_syncp(data)                                       ((0x00000040&(data))>>6)
#define  STB_ST_SRST1_get_rstn_cbus_tx(data)                                     ((0x00000020&(data))>>5)
#define  STB_ST_SRST1_get_rstn_cbus(data)                                        ((0x00000010&(data))>>4)
#define  STB_ST_SRST1_get_rstn_alu(data)                                         ((0x00000008&(data))>>3)
#define  STB_ST_SRST1_get_rstn_irda(data)                                        ((0x00000004&(data))>>2)
#define  STB_ST_SRST1_get_rstn_ddc(data)                                         ((0x00000002&(data))>>1)
#define  STB_ST_SRST1_get_rstn_lsadc(data)                                       (0x00000001&(data))

#define  STB_ST_CLKEN0                                                           0x18060040
#define  STB_ST_CLKEN0_reg_addr                                                  "0xB8060040"
#define  STB_ST_CLKEN0_reg                                                       0xB8060040
#define  STB_ST_CLKEN0_inst_addr                                                 "0x0006"
#define  set_STB_ST_CLKEN0_reg(data)                                             (*((volatile unsigned int*)STB_ST_CLKEN0_reg)=data)
#define  get_STB_ST_CLKEN0_reg                                                   (*((volatile unsigned int*)STB_ST_CLKEN0_reg))
#define  STB_ST_CLKEN0_clken_getn_shift                                          (8)
#define  STB_ST_CLKEN0_clken_iso_vfd_shift                                       (7)
#define  STB_ST_CLKEN0_clken_i2c0_off_shift                                      (6)
#define  STB_ST_CLKEN0_clken_uart0_off_shift                                     (5)
#define  STB_ST_CLKEN0_clken_irda_off_shift                                      (4)
#define  STB_ST_CLKEN0_clken_pwm_shift                                           (3)
#define  STB_ST_CLKEN0_clken_pad_mux_shift                                       (2)
#define  STB_ST_CLKEN0_clken_iso_misc_off_shift                                  (1)
#define  STB_ST_CLKEN0_clken_iso_misc_shift                                      (0)
#define  STB_ST_CLKEN0_clken_getn_mask                                           (0x00000100)
#define  STB_ST_CLKEN0_clken_iso_vfd_mask                                        (0x00000080)
#define  STB_ST_CLKEN0_clken_i2c0_off_mask                                       (0x00000040)
#define  STB_ST_CLKEN0_clken_uart0_off_mask                                      (0x00000020)
#define  STB_ST_CLKEN0_clken_irda_off_mask                                       (0x00000010)
#define  STB_ST_CLKEN0_clken_pwm_mask                                            (0x00000008)
#define  STB_ST_CLKEN0_clken_pad_mux_mask                                        (0x00000004)
#define  STB_ST_CLKEN0_clken_iso_misc_off_mask                                   (0x00000002)
#define  STB_ST_CLKEN0_clken_iso_misc_mask                                       (0x00000001)
#define  STB_ST_CLKEN0_clken_getn(data)                                          (0x00000100&((data)<<8))
#define  STB_ST_CLKEN0_clken_iso_vfd(data)                                       (0x00000080&((data)<<7))
#define  STB_ST_CLKEN0_clken_i2c0_off(data)                                      (0x00000040&((data)<<6))
#define  STB_ST_CLKEN0_clken_uart0_off(data)                                     (0x00000020&((data)<<5))
#define  STB_ST_CLKEN0_clken_irda_off(data)                                      (0x00000010&((data)<<4))
#define  STB_ST_CLKEN0_clken_pwm(data)                                           (0x00000008&((data)<<3))
#define  STB_ST_CLKEN0_clken_pad_mux(data)                                       (0x00000004&((data)<<2))
#define  STB_ST_CLKEN0_clken_iso_misc_off(data)                                  (0x00000002&((data)<<1))
#define  STB_ST_CLKEN0_clken_iso_misc(data)                                      (0x00000001&(data))
#define  STB_ST_CLKEN0_get_clken_getn(data)                                      ((0x00000100&(data))>>8)
#define  STB_ST_CLKEN0_get_clken_iso_vfd(data)                                   ((0x00000080&(data))>>7)
#define  STB_ST_CLKEN0_get_clken_i2c0_off(data)                                  ((0x00000040&(data))>>6)
#define  STB_ST_CLKEN0_get_clken_uart0_off(data)                                 ((0x00000020&(data))>>5)
#define  STB_ST_CLKEN0_get_clken_irda_off(data)                                  ((0x00000010&(data))>>4)
#define  STB_ST_CLKEN0_get_clken_pwm(data)                                       ((0x00000008&(data))>>3)
#define  STB_ST_CLKEN0_get_clken_pad_mux(data)                                   ((0x00000004&(data))>>2)
#define  STB_ST_CLKEN0_get_clken_iso_misc_off(data)                              ((0x00000002&(data))>>1)
#define  STB_ST_CLKEN0_get_clken_iso_misc(data)                                  (0x00000001&(data))

#define  STB_ST_CLKEN1                                                           0x18060044
#define  STB_ST_CLKEN1_reg_addr                                                  "0xB8060044"
#define  STB_ST_CLKEN1_reg                                                       0xB8060044
#define  STB_ST_CLKEN1_inst_addr                                                 "0x0007"
#define  set_STB_ST_CLKEN1_reg(data)                                             (*((volatile unsigned int*)STB_ST_CLKEN1_reg)=data)
#define  get_STB_ST_CLKEN1_reg                                                   (*((volatile unsigned int*)STB_ST_CLKEN1_reg))
#define  STB_ST_CLKEN1_clken_ddc3_shift                                          (14)
#define  STB_ST_CLKEN1_clken_ddc2_shift                                          (13)
#define  STB_ST_CLKEN1_clken_ddc1_shift                                          (12)
#define  STB_ST_CLKEN1_clken_osc_shift                                           (11)
#define  STB_ST_CLKEN1_clken_cbus_tx_ip_shift                                    (10)
#define  STB_ST_CLKEN1_clken_emcu_core_shift                                     (9)
#define  STB_ST_CLKEN1_clken_hdmi_det_shift                                      (8)
#define  STB_ST_CLKEN1_clken_cec_shift                                           (7)
#define  STB_ST_CLKEN1_clken_syncp_shift                                         (6)
#define  STB_ST_CLKEN1_clken_cbus_tx_shift                                       (5)
#define  STB_ST_CLKEN1_clken_cbus_shift                                          (4)
#define  STB_ST_CLKEN1_clken_alu_shift                                           (3)
#define  STB_ST_CLKEN1_clken_irda_shift                                          (2)
#define  STB_ST_CLKEN1_clken_ddc_shift                                           (1)
#define  STB_ST_CLKEN1_clken_lsadc_shift                                         (0)
#define  STB_ST_CLKEN1_clken_ddc3_mask                                           (0x00004000)
#define  STB_ST_CLKEN1_clken_ddc2_mask                                           (0x00002000)
#define  STB_ST_CLKEN1_clken_ddc1_mask                                           (0x00001000)
#define  STB_ST_CLKEN1_clken_osc_mask                                            (0x00000800)
#define  STB_ST_CLKEN1_clken_cbus_tx_ip_mask                                     (0x00000400)
#define  STB_ST_CLKEN1_clken_emcu_core_mask                                      (0x00000200)
#define  STB_ST_CLKEN1_clken_hdmi_det_mask                                       (0x00000100)
#define  STB_ST_CLKEN1_clken_cec_mask                                            (0x00000080)
#define  STB_ST_CLKEN1_clken_syncp_mask                                          (0x00000040)
#define  STB_ST_CLKEN1_clken_cbus_tx_mask                                        (0x00000020)
#define  STB_ST_CLKEN1_clken_cbus_mask                                           (0x00000010)
#define  STB_ST_CLKEN1_clken_alu_mask                                            (0x00000008)
#define  STB_ST_CLKEN1_clken_irda_mask                                           (0x00000004)
#define  STB_ST_CLKEN1_clken_ddc_mask                                            (0x00000002)
#define  STB_ST_CLKEN1_clken_lsadc_mask                                          (0x00000001)
#define  STB_ST_CLKEN1_clken_ddc3(data)                                          (0x00004000&((data)<<14))
#define  STB_ST_CLKEN1_clken_ddc2(data)                                          (0x00002000&((data)<<13))
#define  STB_ST_CLKEN1_clken_ddc1(data)                                          (0x00001000&((data)<<12))
#define  STB_ST_CLKEN1_clken_osc(data)                                           (0x00000800&((data)<<11))
#define  STB_ST_CLKEN1_clken_cbus_tx_ip(data)                                    (0x00000400&((data)<<10))
#define  STB_ST_CLKEN1_clken_emcu_core(data)                                     (0x00000200&((data)<<9))
#define  STB_ST_CLKEN1_clken_hdmi_det(data)                                      (0x00000100&((data)<<8))
#define  STB_ST_CLKEN1_clken_cec(data)                                           (0x00000080&((data)<<7))
#define  STB_ST_CLKEN1_clken_syncp(data)                                         (0x00000040&((data)<<6))
#define  STB_ST_CLKEN1_clken_cbus_tx(data)                                       (0x00000020&((data)<<5))
#define  STB_ST_CLKEN1_clken_cbus(data)                                          (0x00000010&((data)<<4))
#define  STB_ST_CLKEN1_clken_alu(data)                                           (0x00000008&((data)<<3))
#define  STB_ST_CLKEN1_clken_irda(data)                                          (0x00000004&((data)<<2))
#define  STB_ST_CLKEN1_clken_ddc(data)                                           (0x00000002&((data)<<1))
#define  STB_ST_CLKEN1_clken_lsadc(data)                                         (0x00000001&(data))
#define  STB_ST_CLKEN1_get_clken_ddc3(data)                                      ((0x00004000&(data))>>14)
#define  STB_ST_CLKEN1_get_clken_ddc2(data)                                      ((0x00002000&(data))>>13)
#define  STB_ST_CLKEN1_get_clken_ddc1(data)                                      ((0x00001000&(data))>>12)
#define  STB_ST_CLKEN1_get_clken_osc(data)                                       ((0x00000800&(data))>>11)
#define  STB_ST_CLKEN1_get_clken_cbus_tx_ip(data)                                ((0x00000400&(data))>>10)
#define  STB_ST_CLKEN1_get_clken_emcu_core(data)                                 ((0x00000200&(data))>>9)
#define  STB_ST_CLKEN1_get_clken_hdmi_det(data)                                  ((0x00000100&(data))>>8)
#define  STB_ST_CLKEN1_get_clken_cec(data)                                       ((0x00000080&(data))>>7)
#define  STB_ST_CLKEN1_get_clken_syncp(data)                                     ((0x00000040&(data))>>6)
#define  STB_ST_CLKEN1_get_clken_cbus_tx(data)                                   ((0x00000020&(data))>>5)
#define  STB_ST_CLKEN1_get_clken_cbus(data)                                      ((0x00000010&(data))>>4)
#define  STB_ST_CLKEN1_get_clken_alu(data)                                       ((0x00000008&(data))>>3)
#define  STB_ST_CLKEN1_get_clken_irda(data)                                      ((0x00000004&(data))>>2)
#define  STB_ST_CLKEN1_get_clken_ddc(data)                                       ((0x00000002&(data))>>1)
#define  STB_ST_CLKEN1_get_clken_lsadc(data)                                     (0x00000001&(data))

#define  STB_ST_MHL_CBUS_TX                                                      0x18060048
#define  STB_ST_MHL_CBUS_TX_reg_addr                                             "0xB8060048"
#define  STB_ST_MHL_CBUS_TX_reg                                                  0xB8060048
#define  STB_ST_MHL_CBUS_TX_inst_addr                                            "0x0008"
#define  set_STB_ST_MHL_CBUS_TX_reg(data)                                        (*((volatile unsigned int*)STB_ST_MHL_CBUS_TX_reg)=data)
#define  get_STB_ST_MHL_CBUS_TX_reg                                              (*((volatile unsigned int*)STB_ST_MHL_CBUS_TX_reg))
#define  STB_ST_MHL_CBUS_TX_mhl_clkdiv_shift                                     (1)
#define  STB_ST_MHL_CBUS_TX_mhl_clkdiv_en_shift                                  (0)
#define  STB_ST_MHL_CBUS_TX_mhl_clkdiv_mask                                      (0x0000000E)
#define  STB_ST_MHL_CBUS_TX_mhl_clkdiv_en_mask                                   (0x00000001)
#define  STB_ST_MHL_CBUS_TX_mhl_clkdiv(data)                                     (0x0000000E&((data)<<1))
#define  STB_ST_MHL_CBUS_TX_mhl_clkdiv_en(data)                                  (0x00000001&(data))
#define  STB_ST_MHL_CBUS_TX_get_mhl_clkdiv(data)                                 ((0x0000000E&(data))>>1)
#define  STB_ST_MHL_CBUS_TX_get_mhl_clkdiv_en(data)                              (0x00000001&(data))

#define  STB_ST_BUSCLK                                                           0x18060050
#define  STB_ST_BUSCLK_reg_addr                                                  "0xB8060050"
#define  STB_ST_BUSCLK_reg                                                       0xB8060050
#define  STB_ST_BUSCLK_inst_addr                                                 "0x0009"
#define  set_STB_ST_BUSCLK_reg(data)                                             (*((volatile unsigned int*)STB_ST_BUSCLK_reg)=data)
#define  get_STB_ST_BUSCLK_reg                                                   (*((volatile unsigned int*)STB_ST_BUSCLK_reg))
#define  STB_ST_BUSCLK_bus_div_en_shift                                          (18)
#define  STB_ST_BUSCLK_bus_div_apply_shift                                       (17)
#define  STB_ST_BUSCLK_bus_div_busy_shift                                        (16)
#define  STB_ST_BUSCLK_bus_div_sel_shift                                         (12)
#define  STB_ST_BUSCLK_bus_clksel_shift                                          (0)
#define  STB_ST_BUSCLK_bus_div_en_mask                                           (0x00040000)
#define  STB_ST_BUSCLK_bus_div_apply_mask                                        (0x00020000)
#define  STB_ST_BUSCLK_bus_div_busy_mask                                         (0x00010000)
#define  STB_ST_BUSCLK_bus_div_sel_mask                                          (0x00007000)
#define  STB_ST_BUSCLK_bus_clksel_mask                                           (0x00000001)
#define  STB_ST_BUSCLK_bus_div_en(data)                                          (0x00040000&((data)<<18))
#define  STB_ST_BUSCLK_bus_div_apply(data)                                       (0x00020000&((data)<<17))
#define  STB_ST_BUSCLK_bus_div_busy(data)                                        (0x00010000&((data)<<16))
#define  STB_ST_BUSCLK_bus_div_sel(data)                                         (0x00007000&((data)<<12))
#define  STB_ST_BUSCLK_bus_clksel(data)                                          (0x00000001&(data))
#define  STB_ST_BUSCLK_get_bus_div_en(data)                                      ((0x00040000&(data))>>18)
#define  STB_ST_BUSCLK_get_bus_div_apply(data)                                   ((0x00020000&(data))>>17)
#define  STB_ST_BUSCLK_get_bus_div_busy(data)                                    ((0x00010000&(data))>>16)
#define  STB_ST_BUSCLK_get_bus_div_sel(data)                                     ((0x00007000&(data))>>12)
#define  STB_ST_BUSCLK_get_bus_clksel(data)                                      (0x00000001&(data))

#define  STB_ST_EMCUCLK                                                          0x18060054
#define  STB_ST_EMCUCLK_reg_addr                                                 "0xB8060054"
#define  STB_ST_EMCUCLK_reg                                                      0xB8060054
#define  STB_ST_EMCUCLK_inst_addr                                                "0x000A"
#define  set_STB_ST_EMCUCLK_reg(data)                                            (*((volatile unsigned int*)STB_ST_EMCUCLK_reg)=data)
#define  get_STB_ST_EMCUCLK_reg                                                  (*((volatile unsigned int*)STB_ST_EMCUCLK_reg))
#define  STB_ST_EMCUCLK_emcu_div_en_shift                                        (18)
#define  STB_ST_EMCUCLK_emcu_div_apply_shift                                     (17)
#define  STB_ST_EMCUCLK_emcu_div_busy_shift                                      (16)
#define  STB_ST_EMCUCLK_emcu_div_sel_shift                                       (12)
#define  STB_ST_EMCUCLK_emcu_div_en_mask                                         (0x00040000)
#define  STB_ST_EMCUCLK_emcu_div_apply_mask                                      (0x00020000)
#define  STB_ST_EMCUCLK_emcu_div_busy_mask                                       (0x00010000)
#define  STB_ST_EMCUCLK_emcu_div_sel_mask                                        (0x00007000)
#define  STB_ST_EMCUCLK_emcu_div_en(data)                                        (0x00040000&((data)<<18))
#define  STB_ST_EMCUCLK_emcu_div_apply(data)                                     (0x00020000&((data)<<17))
#define  STB_ST_EMCUCLK_emcu_div_busy(data)                                      (0x00010000&((data)<<16))
#define  STB_ST_EMCUCLK_emcu_div_sel(data)                                       (0x00007000&((data)<<12))
#define  STB_ST_EMCUCLK_get_emcu_div_en(data)                                    ((0x00040000&(data))>>18)
#define  STB_ST_EMCUCLK_get_emcu_div_apply(data)                                 ((0x00020000&(data))>>17)
#define  STB_ST_EMCUCLK_get_emcu_div_busy(data)                                  ((0x00010000&(data))>>16)
#define  STB_ST_EMCUCLK_get_emcu_div_sel(data)                                   ((0x00007000&(data))>>12)

#define  STB_ST_CLKMUX                                                           0x18060058
#define  STB_ST_CLKMUX_reg_addr                                                  "0xB8060058"
#define  STB_ST_CLKMUX_reg                                                       0xB8060058
#define  STB_ST_CLKMUX_inst_addr                                                 "0x000B"
#define  set_STB_ST_CLKMUX_reg(data)                                             (*((volatile unsigned int*)STB_ST_CLKMUX_reg)=data)
#define  get_STB_ST_CLKMUX_reg                                                   (*((volatile unsigned int*)STB_ST_CLKMUX_reg))
#define  STB_ST_CLKMUX_ecbus_clksel_shift                                        (3)
#define  STB_ST_CLKMUX_cec_clksel_shift                                          (2)
#define  STB_ST_CLKMUX_osc_clksel_shift                                          (1)
#define  STB_ST_CLKMUX_uart_clksel_shift                                         (0)
#define  STB_ST_CLKMUX_ecbus_clksel_mask                                         (0x00000008)
#define  STB_ST_CLKMUX_cec_clksel_mask                                           (0x00000004)
#define  STB_ST_CLKMUX_osc_clksel_mask                                           (0x00000002)
#define  STB_ST_CLKMUX_uart_clksel_mask                                          (0x00000001)
#define  STB_ST_CLKMUX_ecbus_clksel(data)                                        (0x00000008&((data)<<3))
#define  STB_ST_CLKMUX_cec_clksel(data)                                          (0x00000004&((data)<<2))
#define  STB_ST_CLKMUX_osc_clksel(data)                                          (0x00000002&((data)<<1))
#define  STB_ST_CLKMUX_uart_clksel(data)                                         (0x00000001&(data))
#define  STB_ST_CLKMUX_get_ecbus_clksel(data)                                    ((0x00000008&(data))>>3)
#define  STB_ST_CLKMUX_get_cec_clksel(data)                                      ((0x00000004&(data))>>2)
#define  STB_ST_CLKMUX_get_osc_clksel(data)                                      ((0x00000002&(data))>>1)
#define  STB_ST_CLKMUX_get_uart_clksel(data)                                     (0x00000001&(data))

#define  STB_ST_ALU_0                                                            0x1806005C
#define  STB_ST_ALU_0_reg_addr                                                   "0xB806005C"
#define  STB_ST_ALU_0_reg                                                        0xB806005C
#define  STB_ST_ALU_0_inst_addr                                                  "0x000C"
#define  set_STB_ST_ALU_0_reg(data)                                              (*((volatile unsigned int*)STB_ST_ALU_0_reg)=data)
#define  get_STB_ST_ALU_0_reg                                                    (*((volatile unsigned int*)STB_ST_ALU_0_reg))
#define  STB_ST_ALU_0_st2_isln_en_shift                                          (31)
#define  STB_ST_ALU_0_alu_test_mode_en_shift                                     (8)
#define  STB_ST_ALU_0_st2_wakeup_tim_shift                                       (4)
#define  STB_ST_ALU_0_st2_de_iso_ps_tim_shift                                    (0)
#define  STB_ST_ALU_0_st2_isln_en_mask                                           (0x80000000)
#define  STB_ST_ALU_0_alu_test_mode_en_mask                                      (0x00000100)
#define  STB_ST_ALU_0_st2_wakeup_tim_mask                                        (0x000000F0)
#define  STB_ST_ALU_0_st2_de_iso_ps_tim_mask                                     (0x0000000F)
#define  STB_ST_ALU_0_st2_isln_en(data)                                          (0x80000000&((data)<<31))
#define  STB_ST_ALU_0_alu_test_mode_en(data)                                     (0x00000100&((data)<<8))
#define  STB_ST_ALU_0_st2_wakeup_tim(data)                                       (0x000000F0&((data)<<4))
#define  STB_ST_ALU_0_st2_de_iso_ps_tim(data)                                    (0x0000000F&(data))
#define  STB_ST_ALU_0_get_st2_isln_en(data)                                      ((0x80000000&(data))>>31)
#define  STB_ST_ALU_0_get_alu_test_mode_en(data)                                 ((0x00000100&(data))>>8)
#define  STB_ST_ALU_0_get_st2_wakeup_tim(data)                                   ((0x000000F0&(data))>>4)
#define  STB_ST_ALU_0_get_st2_de_iso_ps_tim(data)                                (0x0000000F&(data))

#define  STB_ALU_IE                                                              0x18060060
#define  STB_ALU_IE_reg_addr                                                     "0xB8060060"
#define  STB_ALU_IE_reg                                                          0xB8060060
#define  STB_ALU_IE_inst_addr                                                    "0x000D"
#define  set_STB_ALU_IE_reg(data)                                                (*((volatile unsigned int*)STB_ALU_IE_reg)=data)
#define  get_STB_ALU_IE_reg                                                      (*((volatile unsigned int*)STB_ALU_IE_reg))
#define  STB_ALU_IE_stie_cbus_tx_shift                                           (5)
#define  STB_ALU_IE_stie_self_wakeup_shift                                       (4)
#define  STB_ALU_IE_stie_rtc_shift                                               (3)
#define  STB_ALU_IE_stie_cec_shift                                               (2)
#define  STB_ALU_IE_stie_cbus_shift                                              (1)
#define  STB_ALU_IE_stie_iso_misc_shift                                          (0)
#define  STB_ALU_IE_stie_cbus_tx_mask                                            (0x00000020)
#define  STB_ALU_IE_stie_self_wakeup_mask                                        (0x00000010)
#define  STB_ALU_IE_stie_rtc_mask                                                (0x00000008)
#define  STB_ALU_IE_stie_cec_mask                                                (0x00000004)
#define  STB_ALU_IE_stie_cbus_mask                                               (0x00000002)
#define  STB_ALU_IE_stie_iso_misc_mask                                           (0x00000001)
#define  STB_ALU_IE_stie_cbus_tx(data)                                           (0x00000020&((data)<<5))
#define  STB_ALU_IE_stie_self_wakeup(data)                                       (0x00000010&((data)<<4))
#define  STB_ALU_IE_stie_rtc(data)                                               (0x00000008&((data)<<3))
#define  STB_ALU_IE_stie_cec(data)                                               (0x00000004&((data)<<2))
#define  STB_ALU_IE_stie_cbus(data)                                              (0x00000002&((data)<<1))
#define  STB_ALU_IE_stie_iso_misc(data)                                          (0x00000001&(data))
#define  STB_ALU_IE_get_stie_cbus_tx(data)                                       ((0x00000020&(data))>>5)
#define  STB_ALU_IE_get_stie_self_wakeup(data)                                   ((0x00000010&(data))>>4)
#define  STB_ALU_IE_get_stie_rtc(data)                                           ((0x00000008&(data))>>3)
#define  STB_ALU_IE_get_stie_cec(data)                                           ((0x00000004&(data))>>2)
#define  STB_ALU_IE_get_stie_cbus(data)                                          ((0x00000002&(data))>>1)
#define  STB_ALU_IE_get_stie_iso_misc(data)                                      (0x00000001&(data))

#define  STB_ALU_IP                                                              0x18060064
#define  STB_ALU_IP_reg_addr                                                     "0xB8060064"
#define  STB_ALU_IP_reg                                                          0xB8060064
#define  STB_ALU_IP_inst_addr                                                    "0x000E"
#define  set_STB_ALU_IP_reg(data)                                                (*((volatile unsigned int*)STB_ALU_IP_reg)=data)
#define  get_STB_ALU_IP_reg                                                      (*((volatile unsigned int*)STB_ALU_IP_reg))
#define  STB_ALU_IP_stip_cbus_tx_shift                                           (5)
#define  STB_ALU_IP_stip_self_wakeup_shift                                       (4)
#define  STB_ALU_IP_stip_rtc_shift                                               (3)
#define  STB_ALU_IP_stip_cec_shift                                               (2)
#define  STB_ALU_IP_stip_cbus_shift                                              (1)
#define  STB_ALU_IP_stip_iso_misc_shift                                          (0)
#define  STB_ALU_IP_stip_cbus_tx_mask                                            (0x00000020)
#define  STB_ALU_IP_stip_self_wakeup_mask                                        (0x00000010)
#define  STB_ALU_IP_stip_rtc_mask                                                (0x00000008)
#define  STB_ALU_IP_stip_cec_mask                                                (0x00000004)
#define  STB_ALU_IP_stip_cbus_mask                                               (0x00000002)
#define  STB_ALU_IP_stip_iso_misc_mask                                           (0x00000001)
#define  STB_ALU_IP_stip_cbus_tx(data)                                           (0x00000020&((data)<<5))
#define  STB_ALU_IP_stip_self_wakeup(data)                                       (0x00000010&((data)<<4))
#define  STB_ALU_IP_stip_rtc(data)                                               (0x00000008&((data)<<3))
#define  STB_ALU_IP_stip_cec(data)                                               (0x00000004&((data)<<2))
#define  STB_ALU_IP_stip_cbus(data)                                              (0x00000002&((data)<<1))
#define  STB_ALU_IP_stip_iso_misc(data)                                          (0x00000001&(data))
#define  STB_ALU_IP_get_stip_cbus_tx(data)                                       ((0x00000020&(data))>>5)
#define  STB_ALU_IP_get_stip_self_wakeup(data)                                   ((0x00000010&(data))>>4)
#define  STB_ALU_IP_get_stip_rtc(data)                                           ((0x00000008&(data))>>3)
#define  STB_ALU_IP_get_stip_cec(data)                                           ((0x00000004&(data))>>2)
#define  STB_ALU_IP_get_stip_cbus(data)                                          ((0x00000002&(data))>>1)
#define  STB_ALU_IP_get_stip_iso_misc(data)                                      (0x00000001&(data))

#define  STB_ALU_PASS                                                            0x18060068
#define  STB_ALU_PASS_reg_addr                                                   "0xB8060068"
#define  STB_ALU_PASS_reg                                                        0xB8060068
#define  STB_ALU_PASS_inst_addr                                                  "0x000F"
#define  set_STB_ALU_PASS_reg(data)                                              (*((volatile unsigned int*)STB_ALU_PASS_reg)=data)
#define  get_STB_ALU_PASS_reg                                                    (*((volatile unsigned int*)STB_ALU_PASS_reg))
#define  STB_ALU_PASS_stpass_cbus_tx_shift                                       (5)
#define  STB_ALU_PASS_stpass_self_wakeup_shift                                   (4)
#define  STB_ALU_PASS_stpass_rtc_shift                                           (3)
#define  STB_ALU_PASS_stpass_cec_shift                                           (2)
#define  STB_ALU_PASS_stpass_cbus_shift                                          (1)
#define  STB_ALU_PASS_stpass_iso_misc_shift                                      (0)
#define  STB_ALU_PASS_stpass_cbus_tx_mask                                        (0x00000020)
#define  STB_ALU_PASS_stpass_self_wakeup_mask                                    (0x00000010)
#define  STB_ALU_PASS_stpass_rtc_mask                                            (0x00000008)
#define  STB_ALU_PASS_stpass_cec_mask                                            (0x00000004)
#define  STB_ALU_PASS_stpass_cbus_mask                                           (0x00000002)
#define  STB_ALU_PASS_stpass_iso_misc_mask                                       (0x00000001)
#define  STB_ALU_PASS_stpass_cbus_tx(data)                                       (0x00000020&((data)<<5))
#define  STB_ALU_PASS_stpass_self_wakeup(data)                                   (0x00000010&((data)<<4))
#define  STB_ALU_PASS_stpass_rtc(data)                                           (0x00000008&((data)<<3))
#define  STB_ALU_PASS_stpass_cec(data)                                           (0x00000004&((data)<<2))
#define  STB_ALU_PASS_stpass_cbus(data)                                          (0x00000002&((data)<<1))
#define  STB_ALU_PASS_stpass_iso_misc(data)                                      (0x00000001&(data))
#define  STB_ALU_PASS_get_stpass_cbus_tx(data)                                   ((0x00000020&(data))>>5)
#define  STB_ALU_PASS_get_stpass_self_wakeup(data)                               ((0x00000010&(data))>>4)
#define  STB_ALU_PASS_get_stpass_rtc(data)                                       ((0x00000008&(data))>>3)
#define  STB_ALU_PASS_get_stpass_cec(data)                                       ((0x00000004&(data))>>2)
#define  STB_ALU_PASS_get_stpass_cbus(data)                                      ((0x00000002&(data))>>1)
#define  STB_ALU_PASS_get_stpass_iso_misc(data)                                  (0x00000001&(data))

#define  STB_ST_RING_OSC_EN                                                      0x180600D0
#define  STB_ST_RING_OSC_EN_reg_addr                                             "0xB80600D0"
#define  STB_ST_RING_OSC_EN_reg                                                  0xB80600D0
#define  STB_ST_RING_OSC_EN_inst_addr                                            "0x0010"
#define  set_STB_ST_RING_OSC_EN_reg(data)                                        (*((volatile unsigned int*)STB_ST_RING_OSC_EN_reg)=data)
#define  get_STB_ST_RING_OSC_EN_reg                                              (*((volatile unsigned int*)STB_ST_RING_OSC_EN_reg))
#define  STB_ST_RING_OSC_EN_osc_sw_s_shift                                       (8)
#define  STB_ST_RING_OSC_EN_osc_rstb_emb_shift                                   (5)
#define  STB_ST_RING_OSC_EN_osc_track_lock_en_shift                              (3)
#define  STB_ST_RING_OSC_EN_osc_calibratable_en_shift                            (2)
#define  STB_ST_RING_OSC_EN_osc_tracking_mode_shift                              (1)
#define  STB_ST_RING_OSC_EN_osc_tracking_en_shift                                (0)
#define  STB_ST_RING_OSC_EN_osc_sw_s_mask                                        (0x00007F00)
#define  STB_ST_RING_OSC_EN_osc_rstb_emb_mask                                    (0x00000020)
#define  STB_ST_RING_OSC_EN_osc_track_lock_en_mask                               (0x00000008)
#define  STB_ST_RING_OSC_EN_osc_calibratable_en_mask                             (0x00000004)
#define  STB_ST_RING_OSC_EN_osc_tracking_mode_mask                               (0x00000002)
#define  STB_ST_RING_OSC_EN_osc_tracking_en_mask                                 (0x00000001)
#define  STB_ST_RING_OSC_EN_osc_sw_s(data)                                       (0x00007F00&((data)<<8))
#define  STB_ST_RING_OSC_EN_osc_rstb_emb(data)                                   (0x00000020&((data)<<5))
#define  STB_ST_RING_OSC_EN_osc_track_lock_en(data)                              (0x00000008&((data)<<3))
#define  STB_ST_RING_OSC_EN_osc_calibratable_en(data)                            (0x00000004&((data)<<2))
#define  STB_ST_RING_OSC_EN_osc_tracking_mode(data)                              (0x00000002&((data)<<1))
#define  STB_ST_RING_OSC_EN_osc_tracking_en(data)                                (0x00000001&(data))
#define  STB_ST_RING_OSC_EN_get_osc_sw_s(data)                                   ((0x00007F00&(data))>>8)
#define  STB_ST_RING_OSC_EN_get_osc_rstb_emb(data)                               ((0x00000020&(data))>>5)
#define  STB_ST_RING_OSC_EN_get_osc_track_lock_en(data)                          ((0x00000008&(data))>>3)
#define  STB_ST_RING_OSC_EN_get_osc_calibratable_en(data)                        ((0x00000004&(data))>>2)
#define  STB_ST_RING_OSC_EN_get_osc_tracking_mode(data)                          ((0x00000002&(data))>>1)
#define  STB_ST_RING_OSC_EN_get_osc_tracking_en(data)                            (0x00000001&(data))

#define  STB_ST_RING_OSC_STATUS                                                  0x180600D4
#define  STB_ST_RING_OSC_STATUS_reg_addr                                         "0xB80600D4"
#define  STB_ST_RING_OSC_STATUS_reg                                              0xB80600D4
#define  STB_ST_RING_OSC_STATUS_inst_addr                                        "0x0011"
#define  set_STB_ST_RING_OSC_STATUS_reg(data)                                    (*((volatile unsigned int*)STB_ST_RING_OSC_STATUS_reg)=data)
#define  get_STB_ST_RING_OSC_STATUS_reg                                          (*((volatile unsigned int*)STB_ST_RING_OSC_STATUS_reg))
#define  STB_ST_RING_OSC_STATUS_s_emb_shift                                      (24)
#define  STB_ST_RING_OSC_STATUS_osc_counter_shift                                (8)
#define  STB_ST_RING_OSC_STATUS_osc_s_overfloor_shift                            (5)
#define  STB_ST_RING_OSC_STATUS_osc_s_underfloor_shift                           (4)
#define  STB_ST_RING_OSC_STATUS_osc_track_lock_status_shift                      (3)
#define  STB_ST_RING_OSC_STATUS_osc_track_lock_check_status_shift                (2)
#define  STB_ST_RING_OSC_STATUS_osc_calibratable_status_shift                    (1)
#define  STB_ST_RING_OSC_STATUS_s_emb_mask                                       (0x7F000000)
#define  STB_ST_RING_OSC_STATUS_osc_counter_mask                                 (0x0007FF00)
#define  STB_ST_RING_OSC_STATUS_osc_s_overfloor_mask                             (0x00000020)
#define  STB_ST_RING_OSC_STATUS_osc_s_underfloor_mask                            (0x00000010)
#define  STB_ST_RING_OSC_STATUS_osc_track_lock_status_mask                       (0x00000008)
#define  STB_ST_RING_OSC_STATUS_osc_track_lock_check_status_mask                 (0x00000004)
#define  STB_ST_RING_OSC_STATUS_osc_calibratable_status_mask                     (0x00000002)
#define  STB_ST_RING_OSC_STATUS_s_emb(data)                                      (0x7F000000&((data)<<24))
#define  STB_ST_RING_OSC_STATUS_osc_counter(data)                                (0x0007FF00&((data)<<8))
#define  STB_ST_RING_OSC_STATUS_osc_s_overfloor(data)                            (0x00000020&((data)<<5))
#define  STB_ST_RING_OSC_STATUS_osc_s_underfloor(data)                           (0x00000010&((data)<<4))
#define  STB_ST_RING_OSC_STATUS_osc_track_lock_status(data)                      (0x00000008&((data)<<3))
#define  STB_ST_RING_OSC_STATUS_osc_track_lock_check_status(data)                (0x00000004&((data)<<2))
#define  STB_ST_RING_OSC_STATUS_osc_calibratable_status(data)                    (0x00000002&((data)<<1))
#define  STB_ST_RING_OSC_STATUS_get_s_emb(data)                                  ((0x7F000000&(data))>>24)
#define  STB_ST_RING_OSC_STATUS_get_osc_counter(data)                            ((0x0007FF00&(data))>>8)
#define  STB_ST_RING_OSC_STATUS_get_osc_s_overfloor(data)                        ((0x00000020&(data))>>5)
#define  STB_ST_RING_OSC_STATUS_get_osc_s_underfloor(data)                       ((0x00000010&(data))>>4)
#define  STB_ST_RING_OSC_STATUS_get_osc_track_lock_status(data)                  ((0x00000008&(data))>>3)
#define  STB_ST_RING_OSC_STATUS_get_osc_track_lock_check_status(data)            ((0x00000004&(data))>>2)
#define  STB_ST_RING_OSC_STATUS_get_osc_calibratable_status(data)                ((0x00000002&(data))>>1)

#define  STB_ST_RING_OSC_DETECT                                                  0x180600D8
#define  STB_ST_RING_OSC_DETECT_reg_addr                                         "0xB80600D8"
#define  STB_ST_RING_OSC_DETECT_reg                                              0xB80600D8
#define  STB_ST_RING_OSC_DETECT_inst_addr                                        "0x0012"
#define  set_STB_ST_RING_OSC_DETECT_reg(data)                                    (*((volatile unsigned int*)STB_ST_RING_OSC_DETECT_reg)=data)
#define  get_STB_ST_RING_OSC_DETECT_reg                                          (*((volatile unsigned int*)STB_ST_RING_OSC_DETECT_reg))
#define  STB_ST_RING_OSC_DETECT_s_emb_one_shot_shift                             (24)
#define  STB_ST_RING_OSC_DETECT_dummy_shift                                      (19)
#define  STB_ST_RING_OSC_DETECT_osc_detection_shift                              (8)
#define  STB_ST_RING_OSC_DETECT_osc_detection_lock_bound_shift                   (3)
#define  STB_ST_RING_OSC_DETECT_osc_detection_calibratable_bound_shift           (1)
#define  STB_ST_RING_OSC_DETECT_osc_detection_en_shift                           (0)
#define  STB_ST_RING_OSC_DETECT_s_emb_one_shot_mask                              (0x7F000000)
#define  STB_ST_RING_OSC_DETECT_dummy_mask                                       (0x00F80000)
#define  STB_ST_RING_OSC_DETECT_osc_detection_mask                               (0x0007FF00)
#define  STB_ST_RING_OSC_DETECT_osc_detection_lock_bound_mask                    (0x00000008)
#define  STB_ST_RING_OSC_DETECT_osc_detection_calibratable_bound_mask            (0x00000002)
#define  STB_ST_RING_OSC_DETECT_osc_detection_en_mask                            (0x00000001)
#define  STB_ST_RING_OSC_DETECT_s_emb_one_shot(data)                             (0x7F000000&((data)<<24))
#define  STB_ST_RING_OSC_DETECT_dummy(data)                                      (0x00F80000&((data)<<19))
#define  STB_ST_RING_OSC_DETECT_osc_detection(data)                              (0x0007FF00&((data)<<8))
#define  STB_ST_RING_OSC_DETECT_osc_detection_lock_bound(data)                   (0x00000008&((data)<<3))
#define  STB_ST_RING_OSC_DETECT_osc_detection_calibratable_bound(data)           (0x00000002&((data)<<1))
#define  STB_ST_RING_OSC_DETECT_osc_detection_en(data)                           (0x00000001&(data))
#define  STB_ST_RING_OSC_DETECT_get_s_emb_one_shot(data)                         ((0x7F000000&(data))>>24)
#define  STB_ST_RING_OSC_DETECT_get_dummy(data)                                  ((0x00F80000&(data))>>19)
#define  STB_ST_RING_OSC_DETECT_get_osc_detection(data)                          ((0x0007FF00&(data))>>8)
#define  STB_ST_RING_OSC_DETECT_get_osc_detection_lock_bound(data)               ((0x00000008&(data))>>3)
#define  STB_ST_RING_OSC_DETECT_get_osc_detection_calibratable_bound(data)       ((0x00000002&(data))>>1)
#define  STB_ST_RING_OSC_DETECT_get_osc_detection_en(data)                       (0x00000001&(data))

#define  STB_ST_RING_OSC_BOUND_COND                                              0x180600E0
#define  STB_ST_RING_OSC_BOUND_COND_reg_addr                                     "0xB80600E0"
#define  STB_ST_RING_OSC_BOUND_COND_reg                                          0xB80600E0
#define  STB_ST_RING_OSC_BOUND_COND_inst_addr                                    "0x0013"
#define  set_STB_ST_RING_OSC_BOUND_COND_reg(data)                                (*((volatile unsigned int*)STB_ST_RING_OSC_BOUND_COND_reg)=data)
#define  get_STB_ST_RING_OSC_BOUND_COND_reg                                      (*((volatile unsigned int*)STB_ST_RING_OSC_BOUND_COND_reg))
#define  STB_ST_RING_OSC_BOUND_COND_osc_calibratable_exit_num_shift              (16)
#define  STB_ST_RING_OSC_BOUND_COND_osc_track_lock_check_num_shift               (8)
#define  STB_ST_RING_OSC_BOUND_COND_osc_track_lock_exit_num_shift                (0)
#define  STB_ST_RING_OSC_BOUND_COND_osc_calibratable_exit_num_mask               (0x000F0000)
#define  STB_ST_RING_OSC_BOUND_COND_osc_track_lock_check_num_mask                (0x00000F00)
#define  STB_ST_RING_OSC_BOUND_COND_osc_track_lock_exit_num_mask                 (0x0000000F)
#define  STB_ST_RING_OSC_BOUND_COND_osc_calibratable_exit_num(data)              (0x000F0000&((data)<<16))
#define  STB_ST_RING_OSC_BOUND_COND_osc_track_lock_check_num(data)               (0x00000F00&((data)<<8))
#define  STB_ST_RING_OSC_BOUND_COND_osc_track_lock_exit_num(data)                (0x0000000F&(data))
#define  STB_ST_RING_OSC_BOUND_COND_get_osc_calibratable_exit_num(data)          ((0x000F0000&(data))>>16)
#define  STB_ST_RING_OSC_BOUND_COND_get_osc_track_lock_check_num(data)           ((0x00000F00&(data))>>8)
#define  STB_ST_RING_OSC_BOUND_COND_get_osc_track_lock_exit_num(data)            (0x0000000F&(data))

#define  STB_ST_RING_OSC_TRACK_LOCK                                              0x180600E4
#define  STB_ST_RING_OSC_TRACK_LOCK_reg_addr                                     "0xB80600E4"
#define  STB_ST_RING_OSC_TRACK_LOCK_reg                                          0xB80600E4
#define  STB_ST_RING_OSC_TRACK_LOCK_inst_addr                                    "0x0014"
#define  set_STB_ST_RING_OSC_TRACK_LOCK_reg(data)                                (*((volatile unsigned int*)STB_ST_RING_OSC_TRACK_LOCK_reg)=data)
#define  get_STB_ST_RING_OSC_TRACK_LOCK_reg                                      (*((volatile unsigned int*)STB_ST_RING_OSC_TRACK_LOCK_reg))
#define  STB_ST_RING_OSC_TRACK_LOCK_osc_track_lock_ub_shift                      (16)
#define  STB_ST_RING_OSC_TRACK_LOCK_osc_track_lock_lb_shift                      (0)
#define  STB_ST_RING_OSC_TRACK_LOCK_osc_track_lock_ub_mask                       (0x07FF0000)
#define  STB_ST_RING_OSC_TRACK_LOCK_osc_track_lock_lb_mask                       (0x000007FF)
#define  STB_ST_RING_OSC_TRACK_LOCK_osc_track_lock_ub(data)                      (0x07FF0000&((data)<<16))
#define  STB_ST_RING_OSC_TRACK_LOCK_osc_track_lock_lb(data)                      (0x000007FF&(data))
#define  STB_ST_RING_OSC_TRACK_LOCK_get_osc_track_lock_ub(data)                  ((0x07FF0000&(data))>>16)
#define  STB_ST_RING_OSC_TRACK_LOCK_get_osc_track_lock_lb(data)                  (0x000007FF&(data))

#define  STB_ST_RING_OSC_CALIBRATABLE                                            0x180600E8
#define  STB_ST_RING_OSC_CALIBRATABLE_reg_addr                                   "0xB80600E8"
#define  STB_ST_RING_OSC_CALIBRATABLE_reg                                        0xB80600E8
#define  STB_ST_RING_OSC_CALIBRATABLE_inst_addr                                  "0x0015"
#define  set_STB_ST_RING_OSC_CALIBRATABLE_reg(data)                              (*((volatile unsigned int*)STB_ST_RING_OSC_CALIBRATABLE_reg)=data)
#define  get_STB_ST_RING_OSC_CALIBRATABLE_reg                                    (*((volatile unsigned int*)STB_ST_RING_OSC_CALIBRATABLE_reg))
#define  STB_ST_RING_OSC_CALIBRATABLE_osc_calibratable_ub_shift                  (16)
#define  STB_ST_RING_OSC_CALIBRATABLE_osc_calibratable_lb_shift                  (0)
#define  STB_ST_RING_OSC_CALIBRATABLE_osc_calibratable_ub_mask                   (0x07FF0000)
#define  STB_ST_RING_OSC_CALIBRATABLE_osc_calibratable_lb_mask                   (0x000007FF)
#define  STB_ST_RING_OSC_CALIBRATABLE_osc_calibratable_ub(data)                  (0x07FF0000&((data)<<16))
#define  STB_ST_RING_OSC_CALIBRATABLE_osc_calibratable_lb(data)                  (0x000007FF&(data))
#define  STB_ST_RING_OSC_CALIBRATABLE_get_osc_calibratable_ub(data)              ((0x07FF0000&(data))>>16)
#define  STB_ST_RING_OSC_CALIBRATABLE_get_osc_calibratable_lb(data)              (0x000007FF&(data))

#define  STB_ST_DBG_1                                                            0x180600F0
#define  STB_ST_DBG_1_reg_addr                                                   "0xB80600F0"
#define  STB_ST_DBG_1_reg                                                        0xB80600F0
#define  STB_ST_DBG_1_inst_addr                                                  "0x0016"
#define  set_STB_ST_DBG_1_reg(data)                                              (*((volatile unsigned int*)STB_ST_DBG_1_reg)=data)
#define  get_STB_ST_DBG_1_reg                                                    (*((volatile unsigned int*)STB_ST_DBG_1_reg))
#define  STB_ST_DBG_1_detect_wd_rst_shift                                        (28)
#define  STB_ST_DBG_1_dummy_shift                                                (27)
#define  STB_ST_DBG_1_alu_dbg_sel_shift                                          (20)
#define  STB_ST_DBG_1_crt_dbg_sel_shift                                          (16)
#define  STB_ST_DBG_1_dbg_div_sel_shift                                          (0)
#define  STB_ST_DBG_1_detect_wd_rst_mask                                         (0x10000000)
#define  STB_ST_DBG_1_dummy_mask                                                 (0x08000000)
#define  STB_ST_DBG_1_alu_dbg_sel_mask                                           (0x07F00000)
#define  STB_ST_DBG_1_crt_dbg_sel_mask                                           (0x000F0000)
#define  STB_ST_DBG_1_dbg_div_sel_mask                                           (0x00000003)
#define  STB_ST_DBG_1_detect_wd_rst(data)                                        (0x10000000&((data)<<28))
#define  STB_ST_DBG_1_dummy(data)                                                (0x08000000&((data)<<27))
#define  STB_ST_DBG_1_alu_dbg_sel(data)                                          (0x07F00000&((data)<<20))
#define  STB_ST_DBG_1_crt_dbg_sel(data)                                          (0x000F0000&((data)<<16))
#define  STB_ST_DBG_1_dbg_div_sel(data)                                          (0x00000003&(data))
#define  STB_ST_DBG_1_get_detect_wd_rst(data)                                    ((0x10000000&(data))>>28)
#define  STB_ST_DBG_1_get_dummy(data)                                            ((0x08000000&(data))>>27)
#define  STB_ST_DBG_1_get_alu_dbg_sel(data)                                      ((0x07F00000&(data))>>20)
#define  STB_ST_DBG_1_get_crt_dbg_sel(data)                                      ((0x000F0000&(data))>>16)
#define  STB_ST_DBG_1_get_dbg_div_sel(data)                                      (0x00000003&(data))

#define  STB_WDOG_DATA1                                                          0x18060100
#define  STB_WDOG_DATA1_reg_addr                                                 "0xB8060100"
#define  STB_WDOG_DATA1_reg                                                      0xB8060100
#define  STB_WDOG_DATA1_inst_addr                                                "0x0017"
#define  set_STB_WDOG_DATA1_reg(data)                                            (*((volatile unsigned int*)STB_WDOG_DATA1_reg)=data)
#define  get_STB_WDOG_DATA1_reg                                                  (*((volatile unsigned int*)STB_WDOG_DATA1_reg))
#define  STB_WDOG_DATA1_wdog_data1_shift                                         (0)
#define  STB_WDOG_DATA1_wdog_data1_mask                                          (0xFFFFFFFF)
#define  STB_WDOG_DATA1_wdog_data1(data)                                         (0xFFFFFFFF&(data))
#define  STB_WDOG_DATA1_get_wdog_data1(data)                                     (0xFFFFFFFF&(data))

#define  STB_WDOG_DATA2                                                          0x18060104
#define  STB_WDOG_DATA2_reg_addr                                                 "0xB8060104"
#define  STB_WDOG_DATA2_reg                                                      0xB8060104
#define  STB_WDOG_DATA2_inst_addr                                                "0x0018"
#define  set_STB_WDOG_DATA2_reg(data)                                            (*((volatile unsigned int*)STB_WDOG_DATA2_reg)=data)
#define  get_STB_WDOG_DATA2_reg                                                  (*((volatile unsigned int*)STB_WDOG_DATA2_reg))
#define  STB_WDOG_DATA2_wdog_data2_shift                                         (0)
#define  STB_WDOG_DATA2_wdog_data2_mask                                          (0xFFFFFFFF)
#define  STB_WDOG_DATA2_wdog_data2(data)                                         (0xFFFFFFFF&(data))
#define  STB_WDOG_DATA2_get_wdog_data2(data)                                     (0xFFFFFFFF&(data))

#define  STB_WDOG_DATA3                                                          0x18060108
#define  STB_WDOG_DATA3_reg_addr                                                 "0xB8060108"
#define  STB_WDOG_DATA3_reg                                                      0xB8060108
#define  STB_WDOG_DATA3_inst_addr                                                "0x0019"
#define  set_STB_WDOG_DATA3_reg(data)                                            (*((volatile unsigned int*)STB_WDOG_DATA3_reg)=data)
#define  get_STB_WDOG_DATA3_reg                                                  (*((volatile unsigned int*)STB_WDOG_DATA3_reg))
#define  STB_WDOG_DATA3_wdog_data3_shift                                         (0)
#define  STB_WDOG_DATA3_wdog_data3_mask                                          (0xFFFFFFFF)
#define  STB_WDOG_DATA3_wdog_data3(data)                                         (0xFFFFFFFF&(data))
#define  STB_WDOG_DATA3_get_wdog_data3(data)                                     (0xFFFFFFFF&(data))

#define  STB_WDOG_DATA4                                                          0x1806010C
#define  STB_WDOG_DATA4_reg_addr                                                 "0xB806010C"
#define  STB_WDOG_DATA4_reg                                                      0xB806010C
#define  STB_WDOG_DATA4_inst_addr                                                "0x001A"
#define  set_STB_WDOG_DATA4_reg(data)                                            (*((volatile unsigned int*)STB_WDOG_DATA4_reg)=data)
#define  get_STB_WDOG_DATA4_reg                                                  (*((volatile unsigned int*)STB_WDOG_DATA4_reg))
#define  STB_WDOG_DATA4_wdog_data4_shift                                         (0)
#define  STB_WDOG_DATA4_wdog_data4_mask                                          (0xFFFFFFFF)
#define  STB_WDOG_DATA4_wdog_data4(data)                                         (0xFFFFFFFF&(data))
#define  STB_WDOG_DATA4_get_wdog_data4(data)                                     (0xFFFFFFFF&(data))

#define  STB_WDOG_DATA5                                                          0x18060110
#define  STB_WDOG_DATA5_reg_addr                                                 "0xB8060110"
#define  STB_WDOG_DATA5_reg                                                      0xB8060110
#define  STB_WDOG_DATA5_inst_addr                                                "0x001B"
#define  set_STB_WDOG_DATA5_reg(data)                                            (*((volatile unsigned int*)STB_WDOG_DATA5_reg)=data)
#define  get_STB_WDOG_DATA5_reg                                                  (*((volatile unsigned int*)STB_WDOG_DATA5_reg))
#define  STB_WDOG_DATA5_wdog_data5_shift                                         (0)
#define  STB_WDOG_DATA5_wdog_data5_mask                                          (0xFFFFFFFF)
#define  STB_WDOG_DATA5_wdog_data5(data)                                         (0xFFFFFFFF&(data))
#define  STB_WDOG_DATA5_get_wdog_data5(data)                                     (0xFFFFFFFF&(data))

#define  STB_WDOG_DATA6                                                          0x18060114
#define  STB_WDOG_DATA6_reg_addr                                                 "0xB8060114"
#define  STB_WDOG_DATA6_reg                                                      0xB8060114
#define  STB_WDOG_DATA6_inst_addr                                                "0x001C"
#define  set_STB_WDOG_DATA6_reg(data)                                            (*((volatile unsigned int*)STB_WDOG_DATA6_reg)=data)
#define  get_STB_WDOG_DATA6_reg                                                  (*((volatile unsigned int*)STB_WDOG_DATA6_reg))
#define  STB_WDOG_DATA6_wdog_data6_shift                                         (0)
#define  STB_WDOG_DATA6_wdog_data6_mask                                          (0xFFFFFFFF)
#define  STB_WDOG_DATA6_wdog_data6(data)                                         (0xFFFFFFFF&(data))
#define  STB_WDOG_DATA6_get_wdog_data6(data)                                     (0xFFFFFFFF&(data))

#define  STB_WDOG_DATA7                                                          0x18060118
#define  STB_WDOG_DATA7_reg_addr                                                 "0xB8060118"
#define  STB_WDOG_DATA7_reg                                                      0xB8060118
#define  STB_WDOG_DATA7_inst_addr                                                "0x001D"
#define  set_STB_WDOG_DATA7_reg(data)                                            (*((volatile unsigned int*)STB_WDOG_DATA7_reg)=data)
#define  get_STB_WDOG_DATA7_reg                                                  (*((volatile unsigned int*)STB_WDOG_DATA7_reg))
#define  STB_WDOG_DATA7_wdog_data7_shift                                         (0)
#define  STB_WDOG_DATA7_wdog_data7_mask                                          (0xFFFFFFFF)
#define  STB_WDOG_DATA7_wdog_data7(data)                                         (0xFFFFFFFF&(data))
#define  STB_WDOG_DATA7_get_wdog_data7(data)                                     (0xFFFFFFFF&(data))

#define  STB_WDOG_DATA8                                                          0x1806011C
#define  STB_WDOG_DATA8_reg_addr                                                 "0xB806011C"
#define  STB_WDOG_DATA8_reg                                                      0xB806011C
#define  STB_WDOG_DATA8_inst_addr                                                "0x001E"
#define  set_STB_WDOG_DATA8_reg(data)                                            (*((volatile unsigned int*)STB_WDOG_DATA8_reg)=data)
#define  get_STB_WDOG_DATA8_reg                                                  (*((volatile unsigned int*)STB_WDOG_DATA8_reg))
#define  STB_WDOG_DATA8_wdog_data8_shift                                         (0)
#define  STB_WDOG_DATA8_wdog_data8_mask                                          (0xFFFFFFFF)
#define  STB_WDOG_DATA8_wdog_data8(data)                                         (0xFFFFFFFF&(data))
#define  STB_WDOG_DATA8_get_wdog_data8(data)                                     (0xFFFFFFFF&(data))

#define  STB_WDOG_DATA9                                                          0x18060120
#define  STB_WDOG_DATA9_reg_addr                                                 "0xB8060120"
#define  STB_WDOG_DATA9_reg                                                      0xB8060120
#define  STB_WDOG_DATA9_inst_addr                                                "0x001F"
#define  set_STB_WDOG_DATA9_reg(data)                                            (*((volatile unsigned int*)STB_WDOG_DATA9_reg)=data)
#define  get_STB_WDOG_DATA9_reg                                                  (*((volatile unsigned int*)STB_WDOG_DATA9_reg))
#define  STB_WDOG_DATA9_wdog_data9_shift                                         (0)
#define  STB_WDOG_DATA9_wdog_data9_mask                                          (0xFFFFFFFF)
#define  STB_WDOG_DATA9_wdog_data9(data)                                         (0xFFFFFFFF&(data))
#define  STB_WDOG_DATA9_get_wdog_data9(data)                                     (0xFFFFFFFF&(data))

#define  STB_WDOG_DATA10                                                         0x18060124
#define  STB_WDOG_DATA10_reg_addr                                                "0xB8060124"
#define  STB_WDOG_DATA10_reg                                                     0xB8060124
#define  STB_WDOG_DATA10_inst_addr                                               "0x0020"
#define  set_STB_WDOG_DATA10_reg(data)                                           (*((volatile unsigned int*)STB_WDOG_DATA10_reg)=data)
#define  get_STB_WDOG_DATA10_reg                                                 (*((volatile unsigned int*)STB_WDOG_DATA10_reg))
#define  STB_WDOG_DATA10_wdog_data10_shift                                       (0)
#define  STB_WDOG_DATA10_wdog_data10_mask                                        (0xFFFFFFFF)
#define  STB_WDOG_DATA10_wdog_data10(data)                                       (0xFFFFFFFF&(data))
#define  STB_WDOG_DATA10_get_wdog_data10(data)                                   (0xFFFFFFFF&(data))

#define  STB_WDOG_DATA11                                                         0x18060128
#define  STB_WDOG_DATA11_reg_addr                                                "0xB8060128"
#define  STB_WDOG_DATA11_reg                                                     0xB8060128
#define  STB_WDOG_DATA11_inst_addr                                               "0x0021"
#define  set_STB_WDOG_DATA11_reg(data)                                           (*((volatile unsigned int*)STB_WDOG_DATA11_reg)=data)
#define  get_STB_WDOG_DATA11_reg                                                 (*((volatile unsigned int*)STB_WDOG_DATA11_reg))
#define  STB_WDOG_DATA11_wdog_data11_shift                                       (0)
#define  STB_WDOG_DATA11_wdog_data11_mask                                        (0xFFFFFFFF)
#define  STB_WDOG_DATA11_wdog_data11(data)                                       (0xFFFFFFFF&(data))
#define  STB_WDOG_DATA11_get_wdog_data11(data)                                   (0xFFFFFFFF&(data))

#define  STB_WDOG_DATA12                                                         0x1806012C
#define  STB_WDOG_DATA12_reg_addr                                                "0xB806012C"
#define  STB_WDOG_DATA12_reg                                                     0xB806012C
#define  STB_WDOG_DATA12_inst_addr                                               "0x0022"
#define  set_STB_WDOG_DATA12_reg(data)                                           (*((volatile unsigned int*)STB_WDOG_DATA12_reg)=data)
#define  get_STB_WDOG_DATA12_reg                                                 (*((volatile unsigned int*)STB_WDOG_DATA12_reg))
#define  STB_WDOG_DATA12_wdog_data12_shift                                       (0)
#define  STB_WDOG_DATA12_wdog_data12_mask                                        (0xFFFFFFFF)
#define  STB_WDOG_DATA12_wdog_data12(data)                                       (0xFFFFFFFF&(data))
#define  STB_WDOG_DATA12_get_wdog_data12(data)                                   (0xFFFFFFFF&(data))

#define  STB_WDOG_DATA13                                                         0x18060130
#define  STB_WDOG_DATA13_reg_addr                                                "0xB8060130"
#define  STB_WDOG_DATA13_reg                                                     0xB8060130
#define  STB_WDOG_DATA13_inst_addr                                               "0x0023"
#define  set_STB_WDOG_DATA13_reg(data)                                           (*((volatile unsigned int*)STB_WDOG_DATA13_reg)=data)
#define  get_STB_WDOG_DATA13_reg                                                 (*((volatile unsigned int*)STB_WDOG_DATA13_reg))
#define  STB_WDOG_DATA13_wdog_data13_shift                                       (3)
#define  STB_WDOG_DATA13_rstn_artc_shift                                         (2)
#define  STB_WDOG_DATA13_rstn_wdog_shift                                         (1)
#define  STB_WDOG_DATA13_rstn_rtc_shift                                          (0)
#define  STB_WDOG_DATA13_wdog_data13_mask                                        (0xFFFFFFF8)
#define  STB_WDOG_DATA13_rstn_artc_mask                                          (0x00000004)
#define  STB_WDOG_DATA13_rstn_wdog_mask                                          (0x00000002)
#define  STB_WDOG_DATA13_rstn_rtc_mask                                           (0x00000001)
#define  STB_WDOG_DATA13_wdog_data13(data)                                       (0xFFFFFFF8&((data)<<3))
#define  STB_WDOG_DATA13_rstn_artc(data)                                         (0x00000004&((data)<<2))
#define  STB_WDOG_DATA13_rstn_wdog(data)                                         (0x00000002&((data)<<1))
#define  STB_WDOG_DATA13_rstn_rtc(data)                                          (0x00000001&(data))
#define  STB_WDOG_DATA13_get_wdog_data13(data)                                   ((0xFFFFFFF8&(data))>>3)
#define  STB_WDOG_DATA13_get_rstn_artc(data)                                     ((0x00000004&(data))>>2)
#define  STB_WDOG_DATA13_get_rstn_wdog(data)                                     ((0x00000002&(data))>>1)
#define  STB_WDOG_DATA13_get_rstn_rtc(data)                                      (0x00000001&(data))

#define  STB_WDOG_DATA14                                                         0x18060134
#define  STB_WDOG_DATA14_reg_addr                                                "0xB8060134"
#define  STB_WDOG_DATA14_reg                                                     0xB8060134
#define  STB_WDOG_DATA14_inst_addr                                               "0x0024"
#define  set_STB_WDOG_DATA14_reg(data)                                           (*((volatile unsigned int*)STB_WDOG_DATA14_reg)=data)
#define  get_STB_WDOG_DATA14_reg                                                 (*((volatile unsigned int*)STB_WDOG_DATA14_reg))
#define  STB_WDOG_DATA14_wdog_data14_shift                                       (3)
#define  STB_WDOG_DATA14_clken_artc_shift                                        (2)
#define  STB_WDOG_DATA14_clken_wdog_shift                                        (1)
#define  STB_WDOG_DATA14_clken_rtc_shift                                         (0)
#define  STB_WDOG_DATA14_wdog_data14_mask                                        (0xFFFFFFF8)
#define  STB_WDOG_DATA14_clken_artc_mask                                         (0x00000004)
#define  STB_WDOG_DATA14_clken_wdog_mask                                         (0x00000002)
#define  STB_WDOG_DATA14_clken_rtc_mask                                          (0x00000001)
#define  STB_WDOG_DATA14_wdog_data14(data)                                       (0xFFFFFFF8&((data)<<3))
#define  STB_WDOG_DATA14_clken_artc(data)                                        (0x00000004&((data)<<2))
#define  STB_WDOG_DATA14_clken_wdog(data)                                        (0x00000002&((data)<<1))
#define  STB_WDOG_DATA14_clken_rtc(data)                                         (0x00000001&(data))
#define  STB_WDOG_DATA14_get_wdog_data14(data)                                   ((0xFFFFFFF8&(data))>>3)
#define  STB_WDOG_DATA14_get_clken_artc(data)                                    ((0x00000004&(data))>>2)
#define  STB_WDOG_DATA14_get_clken_wdog(data)                                    ((0x00000002&(data))>>1)
#define  STB_WDOG_DATA14_get_clken_rtc(data)                                     (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======STB register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vercode:32;
    };
}stb_sc_verid_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  por_reser:12;
        RBus_UInt32  dummy18060004_19_16:4;
        RBus_UInt32  en_emb:1;
        RBus_UInt32  main_pow_on:1;
        RBus_UInt32  main_por_en:1;
        RBus_UInt32  pll27x_top_en:1;
        RBus_UInt32  por_v33set_l:2;
        RBus_UInt32  por_v10set_l:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  por_scpu_sel_l:2;
        RBus_UInt32  ldov10_sel:3;
        RBus_UInt32  stbldo_pow:1;
    };
}stb_sc_lv_rst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  boption_rst_bypass_n:1;
        RBus_UInt32  boption_efuse:1;
        RBus_UInt32  boption_otpclk_rosc:1;
        RBus_UInt32  dummy18060008_28_20:9;
        RBus_UInt32  at_speed_pll_done:1;
        RBus_UInt32  porl_host_s_en_n:1;
        RBus_UInt32  porl_at_speed_scan:1;
        RBus_UInt32  porl_boot_mode:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  porl_test_mode:6;
        RBus_UInt32  porl_test_en_n:1;
        RBus_UInt32  porl_pll_en:1;
        RBus_UInt32  porl_ejtag_en_n:1;
        RBus_UInt32  res2:1;
    };
}stb_sc_pol_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  ddr_iso_rst1_en:1;
        RBus_UInt32  efuse_isln_en:1;
        RBus_UInt32  ddr_isln_en:1;
        RBus_UInt32  getn_isln_en:1;
        RBus_UInt32  rstn_mt:1;
        RBus_UInt32  mt_isln_en:1;
    };
}stb_st_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  rstn_getn:1;
        RBus_UInt32  rstn_iso_vfd:1;
        RBus_UInt32  rstn_i2c0_off:1;
        RBus_UInt32  rstn_uart0_off:1;
        RBus_UInt32  rstn_irda_off:1;
        RBus_UInt32  rstn_pwm:1;
        RBus_UInt32  rstn_pad_mux:1;
        RBus_UInt32  rstn_iso_misc_off:1;
        RBus_UInt32  rstn_iso_misc:1;
    };
}stb_st_srst0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  rstn_ddc3:1;
        RBus_UInt32  rstn_ddc2:1;
        RBus_UInt32  rstn_ddc1:1;
        RBus_UInt32  rstn_osc:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  rstn_emcu_top:1;
        RBus_UInt32  rstn_emcu_core:1;
        RBus_UInt32  rstn_hdmi_det:1;
        RBus_UInt32  rstn_cec:1;
        RBus_UInt32  rstn_syncp:1;
        RBus_UInt32  rstn_cbus_tx:1;
        RBus_UInt32  rstn_cbus:1;
        RBus_UInt32  rstn_alu:1;
        RBus_UInt32  rstn_irda:1;
        RBus_UInt32  rstn_ddc:1;
        RBus_UInt32  rstn_lsadc:1;
    };
}stb_st_srst1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  clken_getn:1;
        RBus_UInt32  clken_iso_vfd:1;
        RBus_UInt32  clken_i2c0_off:1;
        RBus_UInt32  clken_uart0_off:1;
        RBus_UInt32  clken_irda_off:1;
        RBus_UInt32  clken_pwm:1;
        RBus_UInt32  clken_pad_mux:1;
        RBus_UInt32  clken_iso_misc_off:1;
        RBus_UInt32  clken_iso_misc:1;
    };
}stb_st_clken0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  clken_ddc3:1;
        RBus_UInt32  clken_ddc2:1;
        RBus_UInt32  clken_ddc1:1;
        RBus_UInt32  clken_osc:1;
        RBus_UInt32  clken_cbus_tx_ip:1;
        RBus_UInt32  clken_emcu_core:1;
        RBus_UInt32  clken_hdmi_det:1;
        RBus_UInt32  clken_cec:1;
        RBus_UInt32  clken_syncp:1;
        RBus_UInt32  clken_cbus_tx:1;
        RBus_UInt32  clken_cbus:1;
        RBus_UInt32  clken_alu:1;
        RBus_UInt32  clken_irda:1;
        RBus_UInt32  clken_ddc:1;
        RBus_UInt32  clken_lsadc:1;
    };
}stb_st_clken1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  mhl_clkdiv:3;
        RBus_UInt32  mhl_clkdiv_en:1;
    };
}stb_st_mhl_cbus_tx_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  bus_div_en:1;
        RBus_UInt32  bus_div_apply:1;
        RBus_UInt32  bus_div_busy:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  bus_div_sel:3;
        RBus_UInt32  res3:11;
        RBus_UInt32  bus_clksel:1;
    };
}stb_st_busclk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  emcu_div_en:1;
        RBus_UInt32  emcu_div_apply:1;
        RBus_UInt32  emcu_div_busy:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  emcu_div_sel:3;
        RBus_UInt32  res3:11;
        RBus_UInt32  res4:1;
    };
}stb_st_emcuclk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  ecbus_clksel:1;
        RBus_UInt32  cec_clksel:1;
        RBus_UInt32  osc_clksel:1;
        RBus_UInt32  uart_clksel:1;
    };
}stb_st_clkmux_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st2_isln_en:1;
        RBus_UInt32  res1:22;
        RBus_UInt32  alu_test_mode_en:1;
        RBus_UInt32  st2_wakeup_tim:4;
        RBus_UInt32  st2_de_iso_ps_tim:4;
    };
}stb_st_alu_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  stie_cbus_tx:1;
        RBus_UInt32  stie_self_wakeup:1;
        RBus_UInt32  stie_rtc:1;
        RBus_UInt32  stie_cec:1;
        RBus_UInt32  stie_cbus:1;
        RBus_UInt32  stie_iso_misc:1;
    };
}stb_alu_ie_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  stip_cbus_tx:1;
        RBus_UInt32  stip_self_wakeup:1;
        RBus_UInt32  stip_rtc:1;
        RBus_UInt32  stip_cec:1;
        RBus_UInt32  stip_cbus:1;
        RBus_UInt32  stip_iso_misc:1;
    };
}stb_alu_ip_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  stpass_cbus_tx:1;
        RBus_UInt32  stpass_self_wakeup:1;
        RBus_UInt32  stpass_rtc:1;
        RBus_UInt32  stpass_cec:1;
        RBus_UInt32  stpass_cbus:1;
        RBus_UInt32  stpass_iso_misc:1;
    };
}stb_alu_pass_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}stb_stb_irq_all_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  osc_sw_s:7;
        RBus_UInt32  res2:2;
        RBus_UInt32  osc_rstb_emb:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  osc_track_lock_en:1;
        RBus_UInt32  osc_calibratable_en:1;
        RBus_UInt32  osc_tracking_mode:1;
        RBus_UInt32  osc_tracking_en:1;
    };
}stb_st_ring_osc_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  s_emb:7;
        RBus_UInt32  res2:5;
        RBus_UInt32  osc_counter:11;
        RBus_UInt32  res3:2;
        RBus_UInt32  osc_s_overfloor:1;
        RBus_UInt32  osc_s_underfloor:1;
        RBus_UInt32  osc_track_lock_status:1;
        RBus_UInt32  osc_track_lock_check_status:1;
        RBus_UInt32  osc_calibratable_status:1;
        RBus_UInt32  res4:1;
    };
}stb_st_ring_osc_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  s_emb_one_shot:7;
        RBus_UInt32  dummy180600d8_23_19:5;
        RBus_UInt32  osc_detection:11;
        RBus_UInt32  res2:4;
        RBus_UInt32  osc_detection_lock_bound:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  osc_detection_calibratable_bound:1;
        RBus_UInt32  osc_detection_en:1;
    };
}stb_st_ring_osc_detect_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  osc_calibratable_exit_num:4;
        RBus_UInt32  res2:4;
        RBus_UInt32  osc_track_lock_check_num:4;
        RBus_UInt32  res3:4;
        RBus_UInt32  osc_track_lock_exit_num:4;
    };
}stb_st_ring_osc_bound_cond_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  osc_track_lock_ub:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  osc_track_lock_lb:11;
    };
}stb_st_ring_osc_track_lock_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  osc_calibratable_ub:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  osc_calibratable_lb:11;
    };
}stb_st_ring_osc_calibratable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  detect_wd_rst:1;
        RBus_UInt32  dummy180600f0_27:1;
        RBus_UInt32  alu_dbg_sel:7;
        RBus_UInt32  crt_dbg_sel:4;
        RBus_UInt32  res2:14;
        RBus_UInt32  dbg_div_sel:2;
    };
}stb_st_dbg_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data1:32;
    };
}stb_wdog_data1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data2:32;
    };
}stb_wdog_data2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data3:32;
    };
}stb_wdog_data3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data4:32;
    };
}stb_wdog_data4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data5:32;
    };
}stb_wdog_data5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data6:32;
    };
}stb_wdog_data6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data7:32;
    };
}stb_wdog_data7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data8:32;
    };
}stb_wdog_data8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data9:32;
    };
}stb_wdog_data9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data10:32;
    };
}stb_wdog_data10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data11:32;
    };
}stb_wdog_data11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data12:32;
    };
}stb_wdog_data12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data13:29;
        RBus_UInt32  rstn_artc:1;
        RBus_UInt32  rstn_wdog:1;
        RBus_UInt32  rstn_rtc:1;
    };
}stb_wdog_data13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data14:29;
        RBus_UInt32  clken_artc:1;
        RBus_UInt32  clken_wdog:1;
        RBus_UInt32  clken_rtc:1;
    };
}stb_wdog_data14_RBUS;

#else //apply LITTLE_ENDIAN

//======STB register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vercode:32;
    };
}stb_sc_verid_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stbldo_pow:1;
        RBus_UInt32  ldov10_sel:3;
        RBus_UInt32  por_scpu_sel_l:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  por_v10set_l:2;
        RBus_UInt32  por_v33set_l:2;
        RBus_UInt32  pll27x_top_en:1;
        RBus_UInt32  main_por_en:1;
        RBus_UInt32  main_pow_on:1;
        RBus_UInt32  en_emb:1;
        RBus_UInt32  dummy18060004_19:4;
        RBus_UInt32  por_reser:12;
    };
}stb_sc_lv_rst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  porl_ejtag_en_n:1;
        RBus_UInt32  porl_pll_en:1;
        RBus_UInt32  porl_test_en_n:1;
        RBus_UInt32  porl_test_mode:6;
        RBus_UInt32  res2:6;
        RBus_UInt32  porl_boot_mode:1;
        RBus_UInt32  porl_at_speed_scan:1;
        RBus_UInt32  porl_host_s_en_n:1;
        RBus_UInt32  at_speed_pll_done:1;
        RBus_UInt32  dummy18060008_28:9;
        RBus_UInt32  boption_otpclk_rosc:1;
        RBus_UInt32  boption_efuse:1;
        RBus_UInt32  boption_rst_bypass_n:1;
    };
}stb_sc_pol_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mt_isln_en:1;
        RBus_UInt32  rstn_mt:1;
        RBus_UInt32  getn_isln_en:1;
        RBus_UInt32  ddr_isln_en:1;
        RBus_UInt32  efuse_isln_en:1;
        RBus_UInt32  ddr_iso_rst1_en:1;
        RBus_UInt32  res1:26;
    };
}stb_st_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rstn_iso_misc:1;
        RBus_UInt32  rstn_iso_misc_off:1;
        RBus_UInt32  rstn_pad_mux:1;
        RBus_UInt32  rstn_pwm:1;
        RBus_UInt32  rstn_irda_off:1;
        RBus_UInt32  rstn_uart0_off:1;
        RBus_UInt32  rstn_i2c0_off:1;
        RBus_UInt32  rstn_iso_vfd:1;
        RBus_UInt32  rstn_getn:1;
        RBus_UInt32  res1:23;
    };
}stb_st_srst0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rstn_lsadc:1;
        RBus_UInt32  rstn_ddc:1;
        RBus_UInt32  rstn_irda:1;
        RBus_UInt32  rstn_alu:1;
        RBus_UInt32  rstn_cbus:1;
        RBus_UInt32  rstn_cbus_tx:1;
        RBus_UInt32  rstn_syncp:1;
        RBus_UInt32  rstn_cec:1;
        RBus_UInt32  rstn_hdmi_det:1;
        RBus_UInt32  rstn_emcu_core:1;
        RBus_UInt32  rstn_emcu_top:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  rstn_osc:1;
        RBus_UInt32  rstn_ddc1:1;
        RBus_UInt32  rstn_ddc2:1;
        RBus_UInt32  rstn_ddc3:1;
        RBus_UInt32  res2:16;
    };
}stb_st_srst1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clken_iso_misc:1;
        RBus_UInt32  clken_iso_misc_off:1;
        RBus_UInt32  clken_pad_mux:1;
        RBus_UInt32  clken_pwm:1;
        RBus_UInt32  clken_irda_off:1;
        RBus_UInt32  clken_uart0_off:1;
        RBus_UInt32  clken_i2c0_off:1;
        RBus_UInt32  clken_iso_vfd:1;
        RBus_UInt32  clken_getn:1;
        RBus_UInt32  res1:23;
    };
}stb_st_clken0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clken_lsadc:1;
        RBus_UInt32  clken_ddc:1;
        RBus_UInt32  clken_irda:1;
        RBus_UInt32  clken_alu:1;
        RBus_UInt32  clken_cbus:1;
        RBus_UInt32  clken_cbus_tx:1;
        RBus_UInt32  clken_syncp:1;
        RBus_UInt32  clken_cec:1;
        RBus_UInt32  clken_hdmi_det:1;
        RBus_UInt32  clken_emcu_core:1;
        RBus_UInt32  clken_cbus_tx_ip:1;
        RBus_UInt32  clken_osc:1;
        RBus_UInt32  clken_ddc1:1;
        RBus_UInt32  clken_ddc2:1;
        RBus_UInt32  clken_ddc3:1;
        RBus_UInt32  res1:17;
    };
}stb_st_clken1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mhl_clkdiv_en:1;
        RBus_UInt32  mhl_clkdiv:3;
        RBus_UInt32  res1:28;
    };
}stb_st_mhl_cbus_tx_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bus_clksel:1;
        RBus_UInt32  res1:11;
        RBus_UInt32  bus_div_sel:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  bus_div_busy:1;
        RBus_UInt32  bus_div_apply:1;
        RBus_UInt32  bus_div_en:1;
        RBus_UInt32  res3:13;
    };
}stb_st_busclk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:11;
        RBus_UInt32  emcu_div_sel:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  emcu_div_busy:1;
        RBus_UInt32  emcu_div_apply:1;
        RBus_UInt32  emcu_div_en:1;
        RBus_UInt32  res4:13;
    };
}stb_st_emcuclk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uart_clksel:1;
        RBus_UInt32  osc_clksel:1;
        RBus_UInt32  cec_clksel:1;
        RBus_UInt32  ecbus_clksel:1;
        RBus_UInt32  res1:28;
    };
}stb_st_clkmux_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st2_de_iso_ps_tim:4;
        RBus_UInt32  st2_wakeup_tim:4;
        RBus_UInt32  alu_test_mode_en:1;
        RBus_UInt32  res1:22;
        RBus_UInt32  st2_isln_en:1;
    };
}stb_st_alu_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stie_iso_misc:1;
        RBus_UInt32  stie_cbus:1;
        RBus_UInt32  stie_cec:1;
        RBus_UInt32  stie_rtc:1;
        RBus_UInt32  stie_self_wakeup:1;
        RBus_UInt32  stie_cbus_tx:1;
        RBus_UInt32  res1:26;
    };
}stb_alu_ie_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stip_iso_misc:1;
        RBus_UInt32  stip_cbus:1;
        RBus_UInt32  stip_cec:1;
        RBus_UInt32  stip_rtc:1;
        RBus_UInt32  stip_self_wakeup:1;
        RBus_UInt32  stip_cbus_tx:1;
        RBus_UInt32  res1:26;
    };
}stb_alu_ip_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stpass_iso_misc:1;
        RBus_UInt32  stpass_cbus:1;
        RBus_UInt32  stpass_cec:1;
        RBus_UInt32  stpass_rtc:1;
        RBus_UInt32  stpass_self_wakeup:1;
        RBus_UInt32  stpass_cbus_tx:1;
        RBus_UInt32  res1:26;
    };
}stb_alu_pass_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}stb_stb_irq_all_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osc_tracking_en:1;
        RBus_UInt32  osc_tracking_mode:1;
        RBus_UInt32  osc_calibratable_en:1;
        RBus_UInt32  osc_track_lock_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  osc_rstb_emb:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  osc_sw_s:7;
        RBus_UInt32  res3:17;
    };
}stb_st_ring_osc_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  osc_calibratable_status:1;
        RBus_UInt32  osc_track_lock_check_status:1;
        RBus_UInt32  osc_track_lock_status:1;
        RBus_UInt32  osc_s_underfloor:1;
        RBus_UInt32  osc_s_overfloor:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  osc_counter:11;
        RBus_UInt32  res3:5;
        RBus_UInt32  s_emb:7;
        RBus_UInt32  res4:1;
    };
}stb_st_ring_osc_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osc_detection_en:1;
        RBus_UInt32  osc_detection_calibratable_bound:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  osc_detection_lock_bound:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  osc_detection:11;
        RBus_UInt32  dummy180600d8_23:5;
        RBus_UInt32  s_emb_one_shot:7;
        RBus_UInt32  res3:1;
    };
}stb_st_ring_osc_detect_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osc_track_lock_exit_num:4;
        RBus_UInt32  res1:4;
        RBus_UInt32  osc_track_lock_check_num:4;
        RBus_UInt32  res2:4;
        RBus_UInt32  osc_calibratable_exit_num:4;
        RBus_UInt32  res3:12;
    };
}stb_st_ring_osc_bound_cond_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osc_track_lock_lb:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  osc_track_lock_ub:11;
        RBus_UInt32  res2:5;
    };
}stb_st_ring_osc_track_lock_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osc_calibratable_lb:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  osc_calibratable_ub:11;
        RBus_UInt32  res2:5;
    };
}stb_st_ring_osc_calibratable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg_div_sel:2;
        RBus_UInt32  res1:14;
        RBus_UInt32  crt_dbg_sel:4;
        RBus_UInt32  alu_dbg_sel:7;
        RBus_UInt32  dummy180600f0_27_27:1;
        RBus_UInt32  detect_wd_rst:1;
        RBus_UInt32  res2:3;
    };
}stb_st_dbg_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data1:32;
    };
}stb_wdog_data1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data2:32;
    };
}stb_wdog_data2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data3:32;
    };
}stb_wdog_data3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data4:32;
    };
}stb_wdog_data4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data5:32;
    };
}stb_wdog_data5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data6:32;
    };
}stb_wdog_data6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data7:32;
    };
}stb_wdog_data7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data8:32;
    };
}stb_wdog_data8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data9:32;
    };
}stb_wdog_data9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data10:32;
    };
}stb_wdog_data10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data11:32;
    };
}stb_wdog_data11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdog_data12:32;
    };
}stb_wdog_data12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rstn_rtc:1;
        RBus_UInt32  rstn_wdog:1;
        RBus_UInt32  rstn_artc:1;
        RBus_UInt32  wdog_data13:29;
    };
}stb_wdog_data13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clken_rtc:1;
        RBus_UInt32  clken_wdog:1;
        RBus_UInt32  clken_artc:1;
        RBus_UInt32  wdog_data14:29;
    };
}stb_wdog_data14_RBUS;




#endif 


#endif 
