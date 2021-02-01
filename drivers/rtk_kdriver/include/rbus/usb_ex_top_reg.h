/**
* @file Mac5-DesignSpec-USB_EX
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_USB_EX_TOP_REG_H_
#define _RBUS_USB_EX_TOP_REG_H_

#include "rbus_types.h"



//  USB_EX_TOP Register Address
#define  USB_EX_TOP_Wrapp                                                        0x18012800
#define  USB_EX_TOP_Wrapp_reg_addr                                               "0xB8012800"
#define  USB_EX_TOP_Wrapp_reg                                                    0xB8012800
#define  USB_EX_TOP_Wrapp_inst_addr                                              "0x0000"
#define  set_USB_EX_TOP_Wrapp_reg(data)                                          (*((volatile unsigned int*)USB_EX_TOP_Wrapp_reg)=data)
#define  get_USB_EX_TOP_Wrapp_reg                                                (*((volatile unsigned int*)USB_EX_TOP_Wrapp_reg))
#define  USB_EX_TOP_Wrapp_status_err_shift                                       (30)
#define  USB_EX_TOP_Wrapp_suspend_r_shift                                        (6)
#define  USB_EX_TOP_Wrapp_debug_mux_shift                                        (1)
#define  USB_EX_TOP_Wrapp_packing_shift                                          (0)
#define  USB_EX_TOP_Wrapp_status_err_mask                                        (0xC0000000)
#define  USB_EX_TOP_Wrapp_suspend_r_mask                                         (0x00000040)
#define  USB_EX_TOP_Wrapp_debug_mux_mask                                         (0x0000003E)
#define  USB_EX_TOP_Wrapp_packing_mask                                           (0x00000001)
#define  USB_EX_TOP_Wrapp_status_err(data)                                       (0xC0000000&((data)<<30))
#define  USB_EX_TOP_Wrapp_suspend_r(data)                                        (0x00000040&((data)<<6))
#define  USB_EX_TOP_Wrapp_debug_mux(data)                                        (0x0000003E&((data)<<1))
#define  USB_EX_TOP_Wrapp_packing(data)                                          (0x00000001&(data))
#define  USB_EX_TOP_Wrapp_get_status_err(data)                                   ((0xC0000000&(data))>>30)
#define  USB_EX_TOP_Wrapp_get_suspend_r(data)                                    ((0x00000040&(data))>>6)
#define  USB_EX_TOP_Wrapp_get_debug_mux(data)                                    ((0x0000003E&(data))>>1)
#define  USB_EX_TOP_Wrapp_get_packing(data)                                      (0x00000001&(data))

#define  USB_EX_TOP_VSTATUS                                                      0x18012804
#define  USB_EX_TOP_VSTATUS_reg_addr                                             "0xB8012804"
#define  USB_EX_TOP_VSTATUS_reg                                                  0xB8012804
#define  USB_EX_TOP_VSTATUS_inst_addr                                            "0x0001"
#define  set_USB_EX_TOP_VSTATUS_reg(data)                                        (*((volatile unsigned int*)USB_EX_TOP_VSTATUS_reg)=data)
#define  get_USB_EX_TOP_VSTATUS_reg                                              (*((volatile unsigned int*)USB_EX_TOP_VSTATUS_reg))
#define  USB_EX_TOP_VSTATUS_vstatus_out_shift                                    (0)
#define  USB_EX_TOP_VSTATUS_vstatus_out_mask                                     (0x000000FF)
#define  USB_EX_TOP_VSTATUS_vstatus_out(data)                                    (0x000000FF&(data))
#define  USB_EX_TOP_VSTATUS_get_vstatus_out(data)                                (0x000000FF&(data))

#define  USB_EX_TOP_USBIPINPUT                                                   0x18012808
#define  USB_EX_TOP_USBIPINPUT_reg_addr                                          "0xB8012808"
#define  USB_EX_TOP_USBIPINPUT_reg                                               0xB8012808
#define  USB_EX_TOP_USBIPINPUT_inst_addr                                         "0x0002"
#define  set_USB_EX_TOP_USBIPINPUT_reg(data)                                     (*((volatile unsigned int*)USB_EX_TOP_USBIPINPUT_reg)=data)
#define  get_USB_EX_TOP_USBIPINPUT_reg                                           (*((volatile unsigned int*)USB_EX_TOP_USBIPINPUT_reg))
#define  USB_EX_TOP_USBIPINPUT_pwr_mux_shift                                     (31)
#define  USB_EX_TOP_USBIPINPUT_ovrcur_mux_shift                                  (30)
#define  USB_EX_TOP_USBIPINPUT_ss_resume_utmi_pls_dis_i_shift                    (29)
#define  USB_EX_TOP_USBIPINPUT_ss_utmi_backward_enb_i_shift                      (28)
#define  USB_EX_TOP_USBIPINPUT_utmi_suspend_mux_shift                            (27)
#define  USB_EX_TOP_USBIPINPUT_host_disc_mux_shift                               (26)
#define  USB_EX_TOP_USBIPINPUT_sys_interrupt_i_shift                             (25)
#define  USB_EX_TOP_USBIPINPUT_ohci_0_app_irq12_i_shift                          (24)
#define  USB_EX_TOP_USBIPINPUT_ohci_0_app_irq1_i_shift                           (23)
#define  USB_EX_TOP_USBIPINPUT_ohci_0_app_io_hit_i_shift                         (22)
#define  USB_EX_TOP_USBIPINPUT_ss_nxt_power_state_valid_i_shift                  (21)
#define  USB_EX_TOP_USBIPINPUT_ss_next_power_state_i_shift                       (19)
#define  USB_EX_TOP_USBIPINPUT_ss_power_state_i_shift                            (17)
#define  USB_EX_TOP_USBIPINPUT_ohci_0_cntsel_i_n_shift                           (16)
#define  USB_EX_TOP_USBIPINPUT_ohci_0_clkcktrst_i_n_shift                        (15)
#define  USB_EX_TOP_USBIPINPUT_ehci_chirp_k_quick_resp_i_shift                   (14)
#define  USB_EX_TOP_USBIPINPUT_ss_fladj_val_5_i_shift                            (13)
#define  USB_EX_TOP_USBIPINPUT_ss_fladj_val_4_i_shift                            (12)
#define  USB_EX_TOP_USBIPINPUT_ss_fladj_val_3_i_shift                            (11)
#define  USB_EX_TOP_USBIPINPUT_ss_fladj_val_2_i_shift                            (10)
#define  USB_EX_TOP_USBIPINPUT_ss_fladj_val_1_i_shift                            (9)
#define  USB_EX_TOP_USBIPINPUT_ss_fladj_val_0_i_shift                            (8)
#define  USB_EX_TOP_USBIPINPUT_ss_fladj_val_host_i_shift                         (2)
#define  USB_EX_TOP_USBIPINPUT_ss_simulation_mode_i_shift                        (1)
#define  USB_EX_TOP_USBIPINPUT_ss_word_if_i_shift                                (0)
#define  USB_EX_TOP_USBIPINPUT_pwr_mux_mask                                      (0x80000000)
#define  USB_EX_TOP_USBIPINPUT_ovrcur_mux_mask                                   (0x40000000)
#define  USB_EX_TOP_USBIPINPUT_ss_resume_utmi_pls_dis_i_mask                     (0x20000000)
#define  USB_EX_TOP_USBIPINPUT_ss_utmi_backward_enb_i_mask                       (0x10000000)
#define  USB_EX_TOP_USBIPINPUT_utmi_suspend_mux_mask                             (0x08000000)
#define  USB_EX_TOP_USBIPINPUT_host_disc_mux_mask                                (0x04000000)
#define  USB_EX_TOP_USBIPINPUT_sys_interrupt_i_mask                              (0x02000000)
#define  USB_EX_TOP_USBIPINPUT_ohci_0_app_irq12_i_mask                           (0x01000000)
#define  USB_EX_TOP_USBIPINPUT_ohci_0_app_irq1_i_mask                            (0x00800000)
#define  USB_EX_TOP_USBIPINPUT_ohci_0_app_io_hit_i_mask                          (0x00400000)
#define  USB_EX_TOP_USBIPINPUT_ss_nxt_power_state_valid_i_mask                   (0x00200000)
#define  USB_EX_TOP_USBIPINPUT_ss_next_power_state_i_mask                        (0x00180000)
#define  USB_EX_TOP_USBIPINPUT_ss_power_state_i_mask                             (0x00060000)
#define  USB_EX_TOP_USBIPINPUT_ohci_0_cntsel_i_n_mask                            (0x00010000)
#define  USB_EX_TOP_USBIPINPUT_ohci_0_clkcktrst_i_n_mask                         (0x00008000)
#define  USB_EX_TOP_USBIPINPUT_ehci_chirp_k_quick_resp_i_mask                    (0x00004000)
#define  USB_EX_TOP_USBIPINPUT_ss_fladj_val_5_i_mask                             (0x00002000)
#define  USB_EX_TOP_USBIPINPUT_ss_fladj_val_4_i_mask                             (0x00001000)
#define  USB_EX_TOP_USBIPINPUT_ss_fladj_val_3_i_mask                             (0x00000800)
#define  USB_EX_TOP_USBIPINPUT_ss_fladj_val_2_i_mask                             (0x00000400)
#define  USB_EX_TOP_USBIPINPUT_ss_fladj_val_1_i_mask                             (0x00000200)
#define  USB_EX_TOP_USBIPINPUT_ss_fladj_val_0_i_mask                             (0x00000100)
#define  USB_EX_TOP_USBIPINPUT_ss_fladj_val_host_i_mask                          (0x000000FC)
#define  USB_EX_TOP_USBIPINPUT_ss_simulation_mode_i_mask                         (0x00000002)
#define  USB_EX_TOP_USBIPINPUT_ss_word_if_i_mask                                 (0x00000001)
#define  USB_EX_TOP_USBIPINPUT_pwr_mux(data)                                     (0x80000000&((data)<<31))
#define  USB_EX_TOP_USBIPINPUT_ovrcur_mux(data)                                  (0x40000000&((data)<<30))
#define  USB_EX_TOP_USBIPINPUT_ss_resume_utmi_pls_dis_i(data)                    (0x20000000&((data)<<29))
#define  USB_EX_TOP_USBIPINPUT_ss_utmi_backward_enb_i(data)                      (0x10000000&((data)<<28))
#define  USB_EX_TOP_USBIPINPUT_utmi_suspend_mux(data)                            (0x08000000&((data)<<27))
#define  USB_EX_TOP_USBIPINPUT_host_disc_mux(data)                               (0x04000000&((data)<<26))
#define  USB_EX_TOP_USBIPINPUT_sys_interrupt_i(data)                             (0x02000000&((data)<<25))
#define  USB_EX_TOP_USBIPINPUT_ohci_0_app_irq12_i(data)                          (0x01000000&((data)<<24))
#define  USB_EX_TOP_USBIPINPUT_ohci_0_app_irq1_i(data)                           (0x00800000&((data)<<23))
#define  USB_EX_TOP_USBIPINPUT_ohci_0_app_io_hit_i(data)                         (0x00400000&((data)<<22))
#define  USB_EX_TOP_USBIPINPUT_ss_nxt_power_state_valid_i(data)                  (0x00200000&((data)<<21))
#define  USB_EX_TOP_USBIPINPUT_ss_next_power_state_i(data)                       (0x00180000&((data)<<19))
#define  USB_EX_TOP_USBIPINPUT_ss_power_state_i(data)                            (0x00060000&((data)<<17))
#define  USB_EX_TOP_USBIPINPUT_ohci_0_cntsel_i_n(data)                           (0x00010000&((data)<<16))
#define  USB_EX_TOP_USBIPINPUT_ohci_0_clkcktrst_i_n(data)                        (0x00008000&((data)<<15))
#define  USB_EX_TOP_USBIPINPUT_ehci_chirp_k_quick_resp_i(data)                   (0x00004000&((data)<<14))
#define  USB_EX_TOP_USBIPINPUT_ss_fladj_val_5_i(data)                            (0x00002000&((data)<<13))
#define  USB_EX_TOP_USBIPINPUT_ss_fladj_val_4_i(data)                            (0x00001000&((data)<<12))
#define  USB_EX_TOP_USBIPINPUT_ss_fladj_val_3_i(data)                            (0x00000800&((data)<<11))
#define  USB_EX_TOP_USBIPINPUT_ss_fladj_val_2_i(data)                            (0x00000400&((data)<<10))
#define  USB_EX_TOP_USBIPINPUT_ss_fladj_val_1_i(data)                            (0x00000200&((data)<<9))
#define  USB_EX_TOP_USBIPINPUT_ss_fladj_val_0_i(data)                            (0x00000100&((data)<<8))
#define  USB_EX_TOP_USBIPINPUT_ss_fladj_val_host_i(data)                         (0x000000FC&((data)<<2))
#define  USB_EX_TOP_USBIPINPUT_ss_simulation_mode_i(data)                        (0x00000002&((data)<<1))
#define  USB_EX_TOP_USBIPINPUT_ss_word_if_i(data)                                (0x00000001&(data))
#define  USB_EX_TOP_USBIPINPUT_get_pwr_mux(data)                                 ((0x80000000&(data))>>31)
#define  USB_EX_TOP_USBIPINPUT_get_ovrcur_mux(data)                              ((0x40000000&(data))>>30)
#define  USB_EX_TOP_USBIPINPUT_get_ss_resume_utmi_pls_dis_i(data)                ((0x20000000&(data))>>29)
#define  USB_EX_TOP_USBIPINPUT_get_ss_utmi_backward_enb_i(data)                  ((0x10000000&(data))>>28)
#define  USB_EX_TOP_USBIPINPUT_get_utmi_suspend_mux(data)                        ((0x08000000&(data))>>27)
#define  USB_EX_TOP_USBIPINPUT_get_host_disc_mux(data)                           ((0x04000000&(data))>>26)
#define  USB_EX_TOP_USBIPINPUT_get_sys_interrupt_i(data)                         ((0x02000000&(data))>>25)
#define  USB_EX_TOP_USBIPINPUT_get_ohci_0_app_irq12_i(data)                      ((0x01000000&(data))>>24)
#define  USB_EX_TOP_USBIPINPUT_get_ohci_0_app_irq1_i(data)                       ((0x00800000&(data))>>23)
#define  USB_EX_TOP_USBIPINPUT_get_ohci_0_app_io_hit_i(data)                     ((0x00400000&(data))>>22)
#define  USB_EX_TOP_USBIPINPUT_get_ss_nxt_power_state_valid_i(data)              ((0x00200000&(data))>>21)
#define  USB_EX_TOP_USBIPINPUT_get_ss_next_power_state_i(data)                   ((0x00180000&(data))>>19)
#define  USB_EX_TOP_USBIPINPUT_get_ss_power_state_i(data)                        ((0x00060000&(data))>>17)
#define  USB_EX_TOP_USBIPINPUT_get_ohci_0_cntsel_i_n(data)                       ((0x00010000&(data))>>16)
#define  USB_EX_TOP_USBIPINPUT_get_ohci_0_clkcktrst_i_n(data)                    ((0x00008000&(data))>>15)
#define  USB_EX_TOP_USBIPINPUT_get_ehci_chirp_k_quick_resp_i(data)               ((0x00004000&(data))>>14)
#define  USB_EX_TOP_USBIPINPUT_get_ss_fladj_val_5_i(data)                        ((0x00002000&(data))>>13)
#define  USB_EX_TOP_USBIPINPUT_get_ss_fladj_val_4_i(data)                        ((0x00001000&(data))>>12)
#define  USB_EX_TOP_USBIPINPUT_get_ss_fladj_val_3_i(data)                        ((0x00000800&(data))>>11)
#define  USB_EX_TOP_USBIPINPUT_get_ss_fladj_val_2_i(data)                        ((0x00000400&(data))>>10)
#define  USB_EX_TOP_USBIPINPUT_get_ss_fladj_val_1_i(data)                        ((0x00000200&(data))>>9)
#define  USB_EX_TOP_USBIPINPUT_get_ss_fladj_val_0_i(data)                        ((0x00000100&(data))>>8)
#define  USB_EX_TOP_USBIPINPUT_get_ss_fladj_val_host_i(data)                     ((0x000000FC&(data))>>2)
#define  USB_EX_TOP_USBIPINPUT_get_ss_simulation_mode_i(data)                    ((0x00000002&(data))>>1)
#define  USB_EX_TOP_USBIPINPUT_get_ss_word_if_i(data)                            (0x00000001&(data))

#define  USB_EX_TOP_RESET_UTMI                                                   0x1801280C
#define  USB_EX_TOP_RESET_UTMI_reg_addr                                          "0xB801280C"
#define  USB_EX_TOP_RESET_UTMI_reg                                               0xB801280C
#define  USB_EX_TOP_RESET_UTMI_inst_addr                                         "0x0003"
#define  set_USB_EX_TOP_RESET_UTMI_reg(data)                                     (*((volatile unsigned int*)USB_EX_TOP_RESET_UTMI_reg)=data)
#define  get_USB_EX_TOP_RESET_UTMI_reg                                           (*((volatile unsigned int*)USB_EX_TOP_RESET_UTMI_reg))
#define  USB_EX_TOP_RESET_UTMI_test_rst_shift                                    (2)
#define  USB_EX_TOP_RESET_UTMI_test_en_shift                                     (1)
#define  USB_EX_TOP_RESET_UTMI_reset_utmi_shift                                  (0)
#define  USB_EX_TOP_RESET_UTMI_test_rst_mask                                     (0x00000004)
#define  USB_EX_TOP_RESET_UTMI_test_en_mask                                      (0x00000002)
#define  USB_EX_TOP_RESET_UTMI_reset_utmi_mask                                   (0x00000001)
#define  USB_EX_TOP_RESET_UTMI_test_rst(data)                                    (0x00000004&((data)<<2))
#define  USB_EX_TOP_RESET_UTMI_test_en(data)                                     (0x00000002&((data)<<1))
#define  USB_EX_TOP_RESET_UTMI_reset_utmi(data)                                  (0x00000001&(data))
#define  USB_EX_TOP_RESET_UTMI_get_test_rst(data)                                ((0x00000004&(data))>>2)
#define  USB_EX_TOP_RESET_UTMI_get_test_en(data)                                 ((0x00000002&(data))>>1)
#define  USB_EX_TOP_RESET_UTMI_get_reset_utmi(data)                              (0x00000001&(data))

#define  USB_EX_TOP_SELF_LOOP_BACK                                               0x18012810
#define  USB_EX_TOP_SELF_LOOP_BACK_reg_addr                                      "0xB8012810"
#define  USB_EX_TOP_SELF_LOOP_BACK_reg                                           0xB8012810
#define  USB_EX_TOP_SELF_LOOP_BACK_inst_addr                                     "0x0004"
#define  set_USB_EX_TOP_SELF_LOOP_BACK_reg(data)                                 (*((volatile unsigned int*)USB_EX_TOP_SELF_LOOP_BACK_reg)=data)
#define  get_USB_EX_TOP_SELF_LOOP_BACK_reg                                       (*((volatile unsigned int*)USB_EX_TOP_SELF_LOOP_BACK_reg))
#define  USB_EX_TOP_SELF_LOOP_BACK_force_test_opmode_en_shift                    (22)
#define  USB_EX_TOP_SELF_LOOP_BACK_test_opmode_shift                             (20)
#define  USB_EX_TOP_SELF_LOOP_BACK_force_test_txvalid_en_shift                   (19)
#define  USB_EX_TOP_SELF_LOOP_BACK_test_txvalid_shift                            (18)
#define  USB_EX_TOP_SELF_LOOP_BACK_simulation_mode_shift                         (17)
#define  USB_EX_TOP_SELF_LOOP_BACK_force_hs_mode_shift                           (16)
#define  USB_EX_TOP_SELF_LOOP_BACK_test_done_shift                               (13)
#define  USB_EX_TOP_SELF_LOOP_BACK_test_fail_shift                               (12)
#define  USB_EX_TOP_SELF_LOOP_BACK_test_speed_shift                              (10)
#define  USB_EX_TOP_SELF_LOOP_BACK_test_seed_shift                               (2)
#define  USB_EX_TOP_SELF_LOOP_BACK_test_psl_shift                                (0)
#define  USB_EX_TOP_SELF_LOOP_BACK_force_test_opmode_en_mask                     (0x00400000)
#define  USB_EX_TOP_SELF_LOOP_BACK_test_opmode_mask                              (0x00300000)
#define  USB_EX_TOP_SELF_LOOP_BACK_force_test_txvalid_en_mask                    (0x00080000)
#define  USB_EX_TOP_SELF_LOOP_BACK_test_txvalid_mask                             (0x00040000)
#define  USB_EX_TOP_SELF_LOOP_BACK_simulation_mode_mask                          (0x00020000)
#define  USB_EX_TOP_SELF_LOOP_BACK_force_hs_mode_mask                            (0x00010000)
#define  USB_EX_TOP_SELF_LOOP_BACK_test_done_mask                                (0x00002000)
#define  USB_EX_TOP_SELF_LOOP_BACK_test_fail_mask                                (0x00001000)
#define  USB_EX_TOP_SELF_LOOP_BACK_test_speed_mask                               (0x00000C00)
#define  USB_EX_TOP_SELF_LOOP_BACK_test_seed_mask                                (0x000003FC)
#define  USB_EX_TOP_SELF_LOOP_BACK_test_psl_mask                                 (0x00000003)
#define  USB_EX_TOP_SELF_LOOP_BACK_force_test_opmode_en(data)                    (0x00400000&((data)<<22))
#define  USB_EX_TOP_SELF_LOOP_BACK_test_opmode(data)                             (0x00300000&((data)<<20))
#define  USB_EX_TOP_SELF_LOOP_BACK_force_test_txvalid_en(data)                   (0x00080000&((data)<<19))
#define  USB_EX_TOP_SELF_LOOP_BACK_test_txvalid(data)                            (0x00040000&((data)<<18))
#define  USB_EX_TOP_SELF_LOOP_BACK_simulation_mode(data)                         (0x00020000&((data)<<17))
#define  USB_EX_TOP_SELF_LOOP_BACK_force_hs_mode(data)                           (0x00010000&((data)<<16))
#define  USB_EX_TOP_SELF_LOOP_BACK_test_done(data)                               (0x00002000&((data)<<13))
#define  USB_EX_TOP_SELF_LOOP_BACK_test_fail(data)                               (0x00001000&((data)<<12))
#define  USB_EX_TOP_SELF_LOOP_BACK_test_speed(data)                              (0x00000C00&((data)<<10))
#define  USB_EX_TOP_SELF_LOOP_BACK_test_seed(data)                               (0x000003FC&((data)<<2))
#define  USB_EX_TOP_SELF_LOOP_BACK_test_psl(data)                                (0x00000003&(data))
#define  USB_EX_TOP_SELF_LOOP_BACK_get_force_test_opmode_en(data)                ((0x00400000&(data))>>22)
#define  USB_EX_TOP_SELF_LOOP_BACK_get_test_opmode(data)                         ((0x00300000&(data))>>20)
#define  USB_EX_TOP_SELF_LOOP_BACK_get_force_test_txvalid_en(data)               ((0x00080000&(data))>>19)
#define  USB_EX_TOP_SELF_LOOP_BACK_get_test_txvalid(data)                        ((0x00040000&(data))>>18)
#define  USB_EX_TOP_SELF_LOOP_BACK_get_simulation_mode(data)                     ((0x00020000&(data))>>17)
#define  USB_EX_TOP_SELF_LOOP_BACK_get_force_hs_mode(data)                       ((0x00010000&(data))>>16)
#define  USB_EX_TOP_SELF_LOOP_BACK_get_test_done(data)                           ((0x00002000&(data))>>13)
#define  USB_EX_TOP_SELF_LOOP_BACK_get_test_fail(data)                           ((0x00001000&(data))>>12)
#define  USB_EX_TOP_SELF_LOOP_BACK_get_test_speed(data)                          ((0x00000C00&(data))>>10)
#define  USB_EX_TOP_SELF_LOOP_BACK_get_test_seed(data)                           ((0x000003FC&(data))>>2)
#define  USB_EX_TOP_SELF_LOOP_BACK_get_test_psl(data)                            (0x00000003&(data))

#define  USB_EX_TOP_VERSION                                                      0x18012814
#define  USB_EX_TOP_VERSION_reg_addr                                             "0xB8012814"
#define  USB_EX_TOP_VERSION_reg                                                  0xB8012814
#define  USB_EX_TOP_VERSION_inst_addr                                            "0x0005"
#define  set_USB_EX_TOP_VERSION_reg(data)                                        (*((volatile unsigned int*)USB_EX_TOP_VERSION_reg)=data)
#define  get_USB_EX_TOP_VERSION_reg                                              (*((volatile unsigned int*)USB_EX_TOP_VERSION_reg))
#define  USB_EX_TOP_VERSION_usbip_version_shift                                  (12)
#define  USB_EX_TOP_VERSION_trans_flag_host_shift                                (11)
#define  USB_EX_TOP_VERSION_dummy_reg_shift                                      (2)
#define  USB_EX_TOP_VERSION_nouse_done_shift                                     (1)
#define  USB_EX_TOP_VERSION_wrap_version_shift                                   (0)
#define  USB_EX_TOP_VERSION_usbip_version_mask                                   (0xFFFFF000)
#define  USB_EX_TOP_VERSION_trans_flag_host_mask                                 (0x00000800)
#define  USB_EX_TOP_VERSION_dummy_reg_mask                                       (0x000003FC)
#define  USB_EX_TOP_VERSION_nouse_done_mask                                      (0x00000002)
#define  USB_EX_TOP_VERSION_wrap_version_mask                                    (0x00000001)
#define  USB_EX_TOP_VERSION_usbip_version(data)                                  (0xFFFFF000&((data)<<12))
#define  USB_EX_TOP_VERSION_trans_flag_host(data)                                (0x00000800&((data)<<11))
#define  USB_EX_TOP_VERSION_dummy_reg(data)                                      (0x000003FC&((data)<<2))
#define  USB_EX_TOP_VERSION_nouse_done(data)                                     (0x00000002&((data)<<1))
#define  USB_EX_TOP_VERSION_wrap_version(data)                                   (0x00000001&(data))
#define  USB_EX_TOP_VERSION_get_usbip_version(data)                              ((0xFFFFF000&(data))>>12)
#define  USB_EX_TOP_VERSION_get_trans_flag_host(data)                            ((0x00000800&(data))>>11)
#define  USB_EX_TOP_VERSION_get_dummy_reg(data)                                  ((0x000003FC&(data))>>2)
#define  USB_EX_TOP_VERSION_get_nouse_done(data)                                 ((0x00000002&(data))>>1)
#define  USB_EX_TOP_VERSION_get_wrap_version(data)                               (0x00000001&(data))

#define  USB_EX_TOP_IPNEWINPUT_2port                                             0x18012834
#define  USB_EX_TOP_IPNEWINPUT_2port_reg_addr                                    "0xB8012834"
#define  USB_EX_TOP_IPNEWINPUT_2port_reg                                         0xB8012834
#define  USB_EX_TOP_IPNEWINPUT_2port_inst_addr                                   "0x0006"
#define  set_USB_EX_TOP_IPNEWINPUT_2port_reg(data)                               (*((volatile unsigned int*)USB_EX_TOP_IPNEWINPUT_2port_reg)=data)
#define  get_USB_EX_TOP_IPNEWINPUT_2port_reg                                     (*((volatile unsigned int*)USB_EX_TOP_IPNEWINPUT_2port_reg))
#define  USB_EX_TOP_IPNEWINPUT_2port_p0_app_prt_ovrcur_i_shift                   (30)
#define  USB_EX_TOP_IPNEWINPUT_2port_p0_hostdisconnect_shift                     (28)
#define  USB_EX_TOP_IPNEWINPUT_2port_ss_hubsetup_min_i_shift                     (6)
#define  USB_EX_TOP_IPNEWINPUT_2port_app_start_clk_i_shift                       (5)
#define  USB_EX_TOP_IPNEWINPUT_2port_ohci_susp_lgcy_i_shift                      (4)
#define  USB_EX_TOP_IPNEWINPUT_2port_ss_ulpi_pp2vbus_i_shift                     (3)
#define  USB_EX_TOP_IPNEWINPUT_2port_ss_autoppd_on_overcur_en_i_shift            (2)
#define  USB_EX_TOP_IPNEWINPUT_2port_ss_power_state_valid_i_shift                (1)
#define  USB_EX_TOP_IPNEWINPUT_2port_reg_usb_ck27m_sel_shift                     (0)
#define  USB_EX_TOP_IPNEWINPUT_2port_p0_app_prt_ovrcur_i_mask                    (0x40000000)
#define  USB_EX_TOP_IPNEWINPUT_2port_p0_hostdisconnect_mask                      (0x10000000)
#define  USB_EX_TOP_IPNEWINPUT_2port_ss_hubsetup_min_i_mask                      (0x00000040)
#define  USB_EX_TOP_IPNEWINPUT_2port_app_start_clk_i_mask                        (0x00000020)
#define  USB_EX_TOP_IPNEWINPUT_2port_ohci_susp_lgcy_i_mask                       (0x00000010)
#define  USB_EX_TOP_IPNEWINPUT_2port_ss_ulpi_pp2vbus_i_mask                      (0x00000008)
#define  USB_EX_TOP_IPNEWINPUT_2port_ss_autoppd_on_overcur_en_i_mask             (0x00000004)
#define  USB_EX_TOP_IPNEWINPUT_2port_ss_power_state_valid_i_mask                 (0x00000002)
#define  USB_EX_TOP_IPNEWINPUT_2port_reg_usb_ck27m_sel_mask                      (0x00000001)
#define  USB_EX_TOP_IPNEWINPUT_2port_p0_app_prt_ovrcur_i(data)                   (0x40000000&((data)<<30))
#define  USB_EX_TOP_IPNEWINPUT_2port_p0_hostdisconnect(data)                     (0x10000000&((data)<<28))
#define  USB_EX_TOP_IPNEWINPUT_2port_ss_hubsetup_min_i(data)                     (0x00000040&((data)<<6))
#define  USB_EX_TOP_IPNEWINPUT_2port_app_start_clk_i(data)                       (0x00000020&((data)<<5))
#define  USB_EX_TOP_IPNEWINPUT_2port_ohci_susp_lgcy_i(data)                      (0x00000010&((data)<<4))
#define  USB_EX_TOP_IPNEWINPUT_2port_ss_ulpi_pp2vbus_i(data)                     (0x00000008&((data)<<3))
#define  USB_EX_TOP_IPNEWINPUT_2port_ss_autoppd_on_overcur_en_i(data)            (0x00000004&((data)<<2))
#define  USB_EX_TOP_IPNEWINPUT_2port_ss_power_state_valid_i(data)                (0x00000002&((data)<<1))
#define  USB_EX_TOP_IPNEWINPUT_2port_reg_usb_ck27m_sel(data)                     (0x00000001&(data))
#define  USB_EX_TOP_IPNEWINPUT_2port_get_p0_app_prt_ovrcur_i(data)               ((0x40000000&(data))>>30)
#define  USB_EX_TOP_IPNEWINPUT_2port_get_p0_hostdisconnect(data)                 ((0x10000000&(data))>>28)
#define  USB_EX_TOP_IPNEWINPUT_2port_get_ss_hubsetup_min_i(data)                 ((0x00000040&(data))>>6)
#define  USB_EX_TOP_IPNEWINPUT_2port_get_app_start_clk_i(data)                   ((0x00000020&(data))>>5)
#define  USB_EX_TOP_IPNEWINPUT_2port_get_ohci_susp_lgcy_i(data)                  ((0x00000010&(data))>>4)
#define  USB_EX_TOP_IPNEWINPUT_2port_get_ss_ulpi_pp2vbus_i(data)                 ((0x00000008&(data))>>3)
#define  USB_EX_TOP_IPNEWINPUT_2port_get_ss_autoppd_on_overcur_en_i(data)        ((0x00000004&(data))>>2)
#define  USB_EX_TOP_IPNEWINPUT_2port_get_ss_power_state_valid_i(data)            ((0x00000002&(data))>>1)
#define  USB_EX_TOP_IPNEWINPUT_2port_get_reg_usb_ck27m_sel(data)                 (0x00000001&(data))

#define  USB_EX_TOP_USBPHY_SLB0                                                  0x18012838
#define  USB_EX_TOP_USBPHY_SLB0_reg_addr                                         "0xB8012838"
#define  USB_EX_TOP_USBPHY_SLB0_reg                                              0xB8012838
#define  USB_EX_TOP_USBPHY_SLB0_inst_addr                                        "0x0007"
#define  set_USB_EX_TOP_USBPHY_SLB0_reg(data)                                    (*((volatile unsigned int*)USB_EX_TOP_USBPHY_SLB0_reg)=data)
#define  get_USB_EX_TOP_USBPHY_SLB0_reg                                          (*((volatile unsigned int*)USB_EX_TOP_USBPHY_SLB0_reg))
#define  USB_EX_TOP_USBPHY_SLB0_usbphy_slb_done_shift                            (3)
#define  USB_EX_TOP_USBPHY_SLB0_usbphy_slb_fail_shift                            (2)
#define  USB_EX_TOP_USBPHY_SLB0_usbphy_slb_hs_shift                              (1)
#define  USB_EX_TOP_USBPHY_SLB0_usbphy_force_slb_shift                           (0)
#define  USB_EX_TOP_USBPHY_SLB0_usbphy_slb_done_mask                             (0x00000008)
#define  USB_EX_TOP_USBPHY_SLB0_usbphy_slb_fail_mask                             (0x00000004)
#define  USB_EX_TOP_USBPHY_SLB0_usbphy_slb_hs_mask                               (0x00000002)
#define  USB_EX_TOP_USBPHY_SLB0_usbphy_force_slb_mask                            (0x00000001)
#define  USB_EX_TOP_USBPHY_SLB0_usbphy_slb_done(data)                            (0x00000008&((data)<<3))
#define  USB_EX_TOP_USBPHY_SLB0_usbphy_slb_fail(data)                            (0x00000004&((data)<<2))
#define  USB_EX_TOP_USBPHY_SLB0_usbphy_slb_hs(data)                              (0x00000002&((data)<<1))
#define  USB_EX_TOP_USBPHY_SLB0_usbphy_force_slb(data)                           (0x00000001&(data))
#define  USB_EX_TOP_USBPHY_SLB0_get_usbphy_slb_done(data)                        ((0x00000008&(data))>>3)
#define  USB_EX_TOP_USBPHY_SLB0_get_usbphy_slb_fail(data)                        ((0x00000004&(data))>>2)
#define  USB_EX_TOP_USBPHY_SLB0_get_usbphy_slb_hs(data)                          ((0x00000002&(data))>>1)
#define  USB_EX_TOP_USBPHY_SLB0_get_usbphy_force_slb(data)                       (0x00000001&(data))

#define  USB_EX_TOP_USB_DUMMY                                                    0x18012840
#define  USB_EX_TOP_USB_DUMMY_reg_addr                                           "0xB8012840"
#define  USB_EX_TOP_USB_DUMMY_reg                                                0xB8012840
#define  USB_EX_TOP_USB_DUMMY_inst_addr                                          "0x0008"
#define  set_USB_EX_TOP_USB_DUMMY_reg(data)                                      (*((volatile unsigned int*)USB_EX_TOP_USB_DUMMY_reg)=data)
#define  get_USB_EX_TOP_USB_DUMMY_reg                                            (*((volatile unsigned int*)USB_EX_TOP_USB_DUMMY_reg))
#define  USB_EX_TOP_USB_DUMMY_reg3840_dummy_shift                                (0)
#define  USB_EX_TOP_USB_DUMMY_reg3840_dummy_mask                                 (0xFFFFFFFF)
#define  USB_EX_TOP_USB_DUMMY_reg3840_dummy(data)                                (0xFFFFFFFF&(data))
#define  USB_EX_TOP_USB_DUMMY_get_reg3840_dummy(data)                            (0xFFFFFFFF&(data))

#define  USB_EX_TOP_USB_CTR0                                                     0x18012848
#define  USB_EX_TOP_USB_CTR0_reg_addr                                            "0xB8012848"
#define  USB_EX_TOP_USB_CTR0_reg                                                 0xB8012848
#define  USB_EX_TOP_USB_CTR0_inst_addr                                           "0x0009"
#define  set_USB_EX_TOP_USB_CTR0_reg(data)                                       (*((volatile unsigned int*)USB_EX_TOP_USB_CTR0_reg)=data)
#define  get_USB_EX_TOP_USB_CTR0_reg                                             (*((volatile unsigned int*)USB_EX_TOP_USB_CTR0_reg))
#define  USB_EX_TOP_USB_CTR0_reg3848_dummy_shift                                 (19)
#define  USB_EX_TOP_USB_CTR0_wrap_sram_rd_opt_shift                              (18)
#define  USB_EX_TOP_USB_CTR0_pll_alive_enable_shift                              (17)
#define  USB_EX_TOP_USB_CTR0_reg3848_dummy15_shift                               (15)
#define  USB_EX_TOP_USB_CTR0_usb2_ldo_pw_p0_shift                                (14)
#define  USB_EX_TOP_USB_CTR0_usb_top_int_en_shift                                (13)
#define  USB_EX_TOP_USB_CTR0_usbphy_pow_p1_shift                                 (12)
#define  USB_EX_TOP_USB_CTR0_usbphy_pow_p0_shift                                 (11)
#define  USB_EX_TOP_USB_CTR0_usbip_port1_soft_reset_shift                        (10)
#define  USB_EX_TOP_USB_CTR0_usbip_port0_soft_reset_shift                        (9)
#define  USB_EX_TOP_USB_CTR0_prt_pwren_reg_ds_shift                              (7)
#define  USB_EX_TOP_USB_CTR0_prt_pwren_ctrl_shift                                (5)
#define  USB_EX_TOP_USB_CTR0_prt_ovrcur_reg_ds_shift                             (3)
#define  USB_EX_TOP_USB_CTR0_prt_ovrcur_ctrl_shift                               (1)
#define  USB_EX_TOP_USB_CTR0_usb_dbg_ctrl_shift                                  (0)
#define  USB_EX_TOP_USB_CTR0_reg3848_dummy_mask                                  (0xFFF80000)
#define  USB_EX_TOP_USB_CTR0_wrap_sram_rd_opt_mask                               (0x00040000)
#define  USB_EX_TOP_USB_CTR0_pll_alive_enable_mask                               (0x00020000)
#define  USB_EX_TOP_USB_CTR0_reg3848_dummy15_mask                                (0x00018000)
#define  USB_EX_TOP_USB_CTR0_usb2_ldo_pw_p0_mask                                 (0x00004000)
#define  USB_EX_TOP_USB_CTR0_usb_top_int_en_mask                                 (0x00002000)
#define  USB_EX_TOP_USB_CTR0_usbphy_pow_p1_mask                                  (0x00001000)
#define  USB_EX_TOP_USB_CTR0_usbphy_pow_p0_mask                                  (0x00000800)
#define  USB_EX_TOP_USB_CTR0_usbip_port1_soft_reset_mask                         (0x00000400)
#define  USB_EX_TOP_USB_CTR0_usbip_port0_soft_reset_mask                         (0x00000200)
#define  USB_EX_TOP_USB_CTR0_prt_pwren_reg_ds_mask                               (0x00000180)
#define  USB_EX_TOP_USB_CTR0_prt_pwren_ctrl_mask                                 (0x00000060)
#define  USB_EX_TOP_USB_CTR0_prt_ovrcur_reg_ds_mask                              (0x00000018)
#define  USB_EX_TOP_USB_CTR0_prt_ovrcur_ctrl_mask                                (0x00000006)
#define  USB_EX_TOP_USB_CTR0_usb_dbg_ctrl_mask                                   (0x00000001)
#define  USB_EX_TOP_USB_CTR0_reg3848_dummy(data)                                 (0xFFF80000&((data)<<19))
#define  USB_EX_TOP_USB_CTR0_wrap_sram_rd_opt(data)                              (0x00040000&((data)<<18))
#define  USB_EX_TOP_USB_CTR0_pll_alive_enable(data)                              (0x00020000&((data)<<17))
#define  USB_EX_TOP_USB_CTR0_reg3848_dummy15(data)                               (0x00018000&((data)<<15))
#define  USB_EX_TOP_USB_CTR0_usb2_ldo_pw_p0(data)                                (0x00004000&((data)<<14))
#define  USB_EX_TOP_USB_CTR0_usb_top_int_en(data)                                (0x00002000&((data)<<13))
#define  USB_EX_TOP_USB_CTR0_usbphy_pow_p1(data)                                 (0x00001000&((data)<<12))
#define  USB_EX_TOP_USB_CTR0_usbphy_pow_p0(data)                                 (0x00000800&((data)<<11))
#define  USB_EX_TOP_USB_CTR0_usbip_port1_soft_reset(data)                        (0x00000400&((data)<<10))
#define  USB_EX_TOP_USB_CTR0_usbip_port0_soft_reset(data)                        (0x00000200&((data)<<9))
#define  USB_EX_TOP_USB_CTR0_prt_pwren_reg_ds(data)                              (0x00000180&((data)<<7))
#define  USB_EX_TOP_USB_CTR0_prt_pwren_ctrl(data)                                (0x00000060&((data)<<5))
#define  USB_EX_TOP_USB_CTR0_prt_ovrcur_reg_ds(data)                             (0x00000018&((data)<<3))
#define  USB_EX_TOP_USB_CTR0_prt_ovrcur_ctrl(data)                               (0x00000006&((data)<<1))
#define  USB_EX_TOP_USB_CTR0_usb_dbg_ctrl(data)                                  (0x00000001&(data))
#define  USB_EX_TOP_USB_CTR0_get_reg3848_dummy(data)                             ((0xFFF80000&(data))>>19)
#define  USB_EX_TOP_USB_CTR0_get_wrap_sram_rd_opt(data)                          ((0x00040000&(data))>>18)
#define  USB_EX_TOP_USB_CTR0_get_pll_alive_enable(data)                          ((0x00020000&(data))>>17)
#define  USB_EX_TOP_USB_CTR0_get_reg3848_dummy15(data)                           ((0x00018000&(data))>>15)
#define  USB_EX_TOP_USB_CTR0_get_usb2_ldo_pw_p0(data)                            ((0x00004000&(data))>>14)
#define  USB_EX_TOP_USB_CTR0_get_usb_top_int_en(data)                            ((0x00002000&(data))>>13)
#define  USB_EX_TOP_USB_CTR0_get_usbphy_pow_p1(data)                             ((0x00001000&(data))>>12)
#define  USB_EX_TOP_USB_CTR0_get_usbphy_pow_p0(data)                             ((0x00000800&(data))>>11)
#define  USB_EX_TOP_USB_CTR0_get_usbip_port1_soft_reset(data)                    ((0x00000400&(data))>>10)
#define  USB_EX_TOP_USB_CTR0_get_usbip_port0_soft_reset(data)                    ((0x00000200&(data))>>9)
#define  USB_EX_TOP_USB_CTR0_get_prt_pwren_reg_ds(data)                          ((0x00000180&(data))>>7)
#define  USB_EX_TOP_USB_CTR0_get_prt_pwren_ctrl(data)                            ((0x00000060&(data))>>5)
#define  USB_EX_TOP_USB_CTR0_get_prt_ovrcur_reg_ds(data)                         ((0x00000018&(data))>>3)
#define  USB_EX_TOP_USB_CTR0_get_prt_ovrcur_ctrl(data)                           ((0x00000006&(data))>>1)
#define  USB_EX_TOP_USB_CTR0_get_usb_dbg_ctrl(data)                              (0x00000001&(data))

#define  USB_EX_TOP_USB_CTR1                                                     0x1801284C
#define  USB_EX_TOP_USB_CTR1_reg_addr                                            "0xB801284C"
#define  USB_EX_TOP_USB_CTR1_reg                                                 0xB801284C
#define  USB_EX_TOP_USB_CTR1_inst_addr                                           "0x000A"
#define  set_USB_EX_TOP_USB_CTR1_reg(data)                                       (*((volatile unsigned int*)USB_EX_TOP_USB_CTR1_reg)=data)
#define  get_USB_EX_TOP_USB_CTR1_reg                                             (*((volatile unsigned int*)USB_EX_TOP_USB_CTR1_reg))
#define  USB_EX_TOP_USB_CTR1_reg384c_dummy_shift                                 (0)
#define  USB_EX_TOP_USB_CTR1_reg384c_dummy_mask                                  (0xFFFFFFFF)
#define  USB_EX_TOP_USB_CTR1_reg384c_dummy(data)                                 (0xFFFFFFFF&(data))
#define  USB_EX_TOP_USB_CTR1_get_reg384c_dummy(data)                             (0xFFFFFFFF&(data))

#define  USB_EX_TOP_Wrapp_DBG1                                                   0x18012850
#define  USB_EX_TOP_Wrapp_DBG1_reg_addr                                          "0xB8012850"
#define  USB_EX_TOP_Wrapp_DBG1_reg                                               0xB8012850
#define  USB_EX_TOP_Wrapp_DBG1_inst_addr                                         "0x000B"
#define  set_USB_EX_TOP_Wrapp_DBG1_reg(data)                                     (*((volatile unsigned int*)USB_EX_TOP_Wrapp_DBG1_reg)=data)
#define  get_USB_EX_TOP_Wrapp_DBG1_reg                                           (*((volatile unsigned int*)USB_EX_TOP_Wrapp_DBG1_reg))
#define  USB_EX_TOP_Wrapp_DBG1_dbus_rwlast_data_l_shift                          (0)
#define  USB_EX_TOP_Wrapp_DBG1_dbus_rwlast_data_l_mask                           (0xFFFFFFFF)
#define  USB_EX_TOP_Wrapp_DBG1_dbus_rwlast_data_l(data)                          (0xFFFFFFFF&(data))
#define  USB_EX_TOP_Wrapp_DBG1_get_dbus_rwlast_data_l(data)                      (0xFFFFFFFF&(data))

#define  USB_EX_TOP_Wrapp_DBG2                                                   0x18012854
#define  USB_EX_TOP_Wrapp_DBG2_reg_addr                                          "0xB8012854"
#define  USB_EX_TOP_Wrapp_DBG2_reg                                               0xB8012854
#define  USB_EX_TOP_Wrapp_DBG2_inst_addr                                         "0x000C"
#define  set_USB_EX_TOP_Wrapp_DBG2_reg(data)                                     (*((volatile unsigned int*)USB_EX_TOP_Wrapp_DBG2_reg)=data)
#define  get_USB_EX_TOP_Wrapp_DBG2_reg                                           (*((volatile unsigned int*)USB_EX_TOP_Wrapp_DBG2_reg))
#define  USB_EX_TOP_Wrapp_DBG2_dbus_rwlast_data_h_shift                          (0)
#define  USB_EX_TOP_Wrapp_DBG2_dbus_rwlast_data_h_mask                           (0xFFFFFFFF)
#define  USB_EX_TOP_Wrapp_DBG2_dbus_rwlast_data_h(data)                          (0xFFFFFFFF&(data))
#define  USB_EX_TOP_Wrapp_DBG2_get_dbus_rwlast_data_h(data)                      (0xFFFFFFFF&(data))

#define  USB_EX_TOP_Wrapp_DBG3                                                   0x18012858
#define  USB_EX_TOP_Wrapp_DBG3_reg_addr                                          "0xB8012858"
#define  USB_EX_TOP_Wrapp_DBG3_reg                                               0xB8012858
#define  USB_EX_TOP_Wrapp_DBG3_inst_addr                                         "0x000D"
#define  set_USB_EX_TOP_Wrapp_DBG3_reg(data)                                     (*((volatile unsigned int*)USB_EX_TOP_Wrapp_DBG3_reg)=data)
#define  get_USB_EX_TOP_Wrapp_DBG3_reg                                           (*((volatile unsigned int*)USB_EX_TOP_Wrapp_DBG3_reg))
#define  USB_EX_TOP_Wrapp_DBG3_ictrl_state_shift                                 (16)
#define  USB_EX_TOP_Wrapp_DBG3_dbus_dma_busy_shift                               (15)
#define  USB_EX_TOP_Wrapp_DBG3_top_sm_shift                                      (0)
#define  USB_EX_TOP_Wrapp_DBG3_ictrl_state_mask                                  (0x00070000)
#define  USB_EX_TOP_Wrapp_DBG3_dbus_dma_busy_mask                                (0x00008000)
#define  USB_EX_TOP_Wrapp_DBG3_top_sm_mask                                       (0x00007FFF)
#define  USB_EX_TOP_Wrapp_DBG3_ictrl_state(data)                                 (0x00070000&((data)<<16))
#define  USB_EX_TOP_Wrapp_DBG3_dbus_dma_busy(data)                               (0x00008000&((data)<<15))
#define  USB_EX_TOP_Wrapp_DBG3_top_sm(data)                                      (0x00007FFF&(data))
#define  USB_EX_TOP_Wrapp_DBG3_get_ictrl_state(data)                             ((0x00070000&(data))>>16)
#define  USB_EX_TOP_Wrapp_DBG3_get_dbus_dma_busy(data)                           ((0x00008000&(data))>>15)
#define  USB_EX_TOP_Wrapp_DBG3_get_top_sm(data)                                  (0x00007FFF&(data))

#define  USB_EX_TOP_USB_CTR2                                                     0x18012878
#define  USB_EX_TOP_USB_CTR2_reg_addr                                            "0xB8012878"
#define  USB_EX_TOP_USB_CTR2_reg                                                 0xB8012878
#define  USB_EX_TOP_USB_CTR2_inst_addr                                           "0x000E"
#define  set_USB_EX_TOP_USB_CTR2_reg(data)                                       (*((volatile unsigned int*)USB_EX_TOP_USB_CTR2_reg)=data)
#define  get_USB_EX_TOP_USB_CTR2_reg                                             (*((volatile unsigned int*)USB_EX_TOP_USB_CTR2_reg))
#define  USB_EX_TOP_USB_CTR2_eco_option0_dis_shift                               (0)
#define  USB_EX_TOP_USB_CTR2_eco_option0_dis_mask                                (0x00000001)
#define  USB_EX_TOP_USB_CTR2_eco_option0_dis(data)                               (0x00000001&(data))
#define  USB_EX_TOP_USB_CTR2_get_eco_option0_dis(data)                           (0x00000001&(data))

#define  USB_EX_TOP_SF_test_CTR                                                  0x1801287C
#define  USB_EX_TOP_SF_test_CTR_reg_addr                                         "0xB801287C"
#define  USB_EX_TOP_SF_test_CTR_reg                                              0xB801287C
#define  USB_EX_TOP_SF_test_CTR_inst_addr                                        "0x000F"
#define  set_USB_EX_TOP_SF_test_CTR_reg(data)                                    (*((volatile unsigned int*)USB_EX_TOP_SF_test_CTR_reg)=data)
#define  get_USB_EX_TOP_SF_test_CTR_reg                                          (*((volatile unsigned int*)USB_EX_TOP_SF_test_CTR_reg))
#define  USB_EX_TOP_SF_test_CTR_reg_sf_tx_mode_shift                             (7)
#define  USB_EX_TOP_SF_test_CTR_reg_sf_tx_start_shift                            (6)
#define  USB_EX_TOP_SF_test_CTR_reg_sf_tx_work_ro_shift                          (5)
#define  USB_EX_TOP_SF_test_CTR_reg_sf_rx_mode_shift                             (4)
#define  USB_EX_TOP_SF_test_CTR_reg_sf_rx_start_shift                            (3)
#define  USB_EX_TOP_SF_test_CTR_reg_sf_rx_gated_shift                            (2)
#define  USB_EX_TOP_SF_test_CTR_reg_sf_rx_done_ro_shift                          (1)
#define  USB_EX_TOP_SF_test_CTR_reg_sf_rx_err_ro_shift                           (0)
#define  USB_EX_TOP_SF_test_CTR_reg_sf_tx_mode_mask                              (0x00000080)
#define  USB_EX_TOP_SF_test_CTR_reg_sf_tx_start_mask                             (0x00000040)
#define  USB_EX_TOP_SF_test_CTR_reg_sf_tx_work_ro_mask                           (0x00000020)
#define  USB_EX_TOP_SF_test_CTR_reg_sf_rx_mode_mask                              (0x00000010)
#define  USB_EX_TOP_SF_test_CTR_reg_sf_rx_start_mask                             (0x00000008)
#define  USB_EX_TOP_SF_test_CTR_reg_sf_rx_gated_mask                             (0x00000004)
#define  USB_EX_TOP_SF_test_CTR_reg_sf_rx_done_ro_mask                           (0x00000002)
#define  USB_EX_TOP_SF_test_CTR_reg_sf_rx_err_ro_mask                            (0x00000001)
#define  USB_EX_TOP_SF_test_CTR_reg_sf_tx_mode(data)                             (0x00000080&((data)<<7))
#define  USB_EX_TOP_SF_test_CTR_reg_sf_tx_start(data)                            (0x00000040&((data)<<6))
#define  USB_EX_TOP_SF_test_CTR_reg_sf_tx_work_ro(data)                          (0x00000020&((data)<<5))
#define  USB_EX_TOP_SF_test_CTR_reg_sf_rx_mode(data)                             (0x00000010&((data)<<4))
#define  USB_EX_TOP_SF_test_CTR_reg_sf_rx_start(data)                            (0x00000008&((data)<<3))
#define  USB_EX_TOP_SF_test_CTR_reg_sf_rx_gated(data)                            (0x00000004&((data)<<2))
#define  USB_EX_TOP_SF_test_CTR_reg_sf_rx_done_ro(data)                          (0x00000002&((data)<<1))
#define  USB_EX_TOP_SF_test_CTR_reg_sf_rx_err_ro(data)                           (0x00000001&(data))
#define  USB_EX_TOP_SF_test_CTR_get_reg_sf_tx_mode(data)                         ((0x00000080&(data))>>7)
#define  USB_EX_TOP_SF_test_CTR_get_reg_sf_tx_start(data)                        ((0x00000040&(data))>>6)
#define  USB_EX_TOP_SF_test_CTR_get_reg_sf_tx_work_ro(data)                      ((0x00000020&(data))>>5)
#define  USB_EX_TOP_SF_test_CTR_get_reg_sf_rx_mode(data)                         ((0x00000010&(data))>>4)
#define  USB_EX_TOP_SF_test_CTR_get_reg_sf_rx_start(data)                        ((0x00000008&(data))>>3)
#define  USB_EX_TOP_SF_test_CTR_get_reg_sf_rx_gated(data)                        ((0x00000004&(data))>>2)
#define  USB_EX_TOP_SF_test_CTR_get_reg_sf_rx_done_ro(data)                      ((0x00000002&(data))>>1)
#define  USB_EX_TOP_SF_test_CTR_get_reg_sf_rx_err_ro(data)                       (0x00000001&(data))

#define  USB_EX_TOP_USB2_port_status                                             0x18012880
#define  USB_EX_TOP_USB2_port_status_reg_addr                                    "0xB8012880"
#define  USB_EX_TOP_USB2_port_status_reg                                         0xB8012880
#define  USB_EX_TOP_USB2_port_status_inst_addr                                   "0x0010"
#define  set_USB_EX_TOP_USB2_port_status_reg(data)                               (*((volatile unsigned int*)USB_EX_TOP_USB2_port_status_reg)=data)
#define  get_USB_EX_TOP_USB2_port_status_reg                                     (*((volatile unsigned int*)USB_EX_TOP_USB2_port_status_reg))
#define  USB_EX_TOP_USB2_port_status_indicator_en_shift                          (31)
#define  USB_EX_TOP_USB2_port_status_indicator_clear_shift                       (30)
#define  USB_EX_TOP_USB2_port_status_p0_discon_indic_shift                       (19)
#define  USB_EX_TOP_USB2_port_status_p0_chrip_indic_shift                        (18)
#define  USB_EX_TOP_USB2_port_status_p0_reset_indic_shift                        (17)
#define  USB_EX_TOP_USB2_port_status_p0_resume_indic_shift                       (16)
#define  USB_EX_TOP_USB2_port_status_p0_suspend_indic_shift                      (15)
#define  USB_EX_TOP_USB2_port_status_p0_portstate_shift                          (0)
#define  USB_EX_TOP_USB2_port_status_indicator_en_mask                           (0x80000000)
#define  USB_EX_TOP_USB2_port_status_indicator_clear_mask                        (0x40000000)
#define  USB_EX_TOP_USB2_port_status_p0_discon_indic_mask                        (0x00080000)
#define  USB_EX_TOP_USB2_port_status_p0_chrip_indic_mask                         (0x00040000)
#define  USB_EX_TOP_USB2_port_status_p0_reset_indic_mask                         (0x00020000)
#define  USB_EX_TOP_USB2_port_status_p0_resume_indic_mask                        (0x00010000)
#define  USB_EX_TOP_USB2_port_status_p0_suspend_indic_mask                       (0x00008000)
#define  USB_EX_TOP_USB2_port_status_p0_portstate_mask                           (0x0000001F)
#define  USB_EX_TOP_USB2_port_status_indicator_en(data)                          (0x80000000&((data)<<31))
#define  USB_EX_TOP_USB2_port_status_indicator_clear(data)                       (0x40000000&((data)<<30))
#define  USB_EX_TOP_USB2_port_status_p0_discon_indic(data)                       (0x00080000&((data)<<19))
#define  USB_EX_TOP_USB2_port_status_p0_chrip_indic(data)                        (0x00040000&((data)<<18))
#define  USB_EX_TOP_USB2_port_status_p0_reset_indic(data)                        (0x00020000&((data)<<17))
#define  USB_EX_TOP_USB2_port_status_p0_resume_indic(data)                       (0x00010000&((data)<<16))
#define  USB_EX_TOP_USB2_port_status_p0_suspend_indic(data)                      (0x00008000&((data)<<15))
#define  USB_EX_TOP_USB2_port_status_p0_portstate(data)                          (0x0000001F&(data))
#define  USB_EX_TOP_USB2_port_status_get_indicator_en(data)                      ((0x80000000&(data))>>31)
#define  USB_EX_TOP_USB2_port_status_get_indicator_clear(data)                   ((0x40000000&(data))>>30)
#define  USB_EX_TOP_USB2_port_status_get_p0_discon_indic(data)                   ((0x00080000&(data))>>19)
#define  USB_EX_TOP_USB2_port_status_get_p0_chrip_indic(data)                    ((0x00040000&(data))>>18)
#define  USB_EX_TOP_USB2_port_status_get_p0_reset_indic(data)                    ((0x00020000&(data))>>17)
#define  USB_EX_TOP_USB2_port_status_get_p0_resume_indic(data)                   ((0x00010000&(data))>>16)
#define  USB_EX_TOP_USB2_port_status_get_p0_suspend_indic(data)                  ((0x00008000&(data))>>15)
#define  USB_EX_TOP_USB2_port_status_get_p0_portstate(data)                      (0x0000001F&(data))

#define  USB_EX_TOP_USB_CRC_CNT                                                  0x18012884
#define  USB_EX_TOP_USB_CRC_CNT_reg_addr                                         "0xB8012884"
#define  USB_EX_TOP_USB_CRC_CNT_reg                                              0xB8012884
#define  USB_EX_TOP_USB_CRC_CNT_inst_addr                                        "0x0011"
#define  set_USB_EX_TOP_USB_CRC_CNT_reg(data)                                    (*((volatile unsigned int*)USB_EX_TOP_USB_CRC_CNT_reg)=data)
#define  get_USB_EX_TOP_USB_CRC_CNT_reg                                          (*((volatile unsigned int*)USB_EX_TOP_USB_CRC_CNT_reg))
#define  USB_EX_TOP_USB_CRC_CNT_rx_crc_cnt_port0_shift                           (2)
#define  USB_EX_TOP_USB_CRC_CNT_rx_crc_cnt_rst_shift                             (1)
#define  USB_EX_TOP_USB_CRC_CNT_rx_crc_cnt_en_shift                              (0)
#define  USB_EX_TOP_USB_CRC_CNT_rx_crc_cnt_port0_mask                            (0x00000FFC)
#define  USB_EX_TOP_USB_CRC_CNT_rx_crc_cnt_rst_mask                              (0x00000002)
#define  USB_EX_TOP_USB_CRC_CNT_rx_crc_cnt_en_mask                               (0x00000001)
#define  USB_EX_TOP_USB_CRC_CNT_rx_crc_cnt_port0(data)                           (0x00000FFC&((data)<<2))
#define  USB_EX_TOP_USB_CRC_CNT_rx_crc_cnt_rst(data)                             (0x00000002&((data)<<1))
#define  USB_EX_TOP_USB_CRC_CNT_rx_crc_cnt_en(data)                              (0x00000001&(data))
#define  USB_EX_TOP_USB_CRC_CNT_get_rx_crc_cnt_port0(data)                       ((0x00000FFC&(data))>>2)
#define  USB_EX_TOP_USB_CRC_CNT_get_rx_crc_cnt_rst(data)                         ((0x00000002&(data))>>1)
#define  USB_EX_TOP_USB_CRC_CNT_get_rx_crc_cnt_en(data)                          (0x00000001&(data))

#define  USB_EX_TOP_USB_INT                                                      0x18012888
#define  USB_EX_TOP_USB_INT_reg_addr                                             "0xB8012888"
#define  USB_EX_TOP_USB_INT_reg                                                  0xB8012888
#define  USB_EX_TOP_USB_INT_inst_addr                                            "0x0012"
#define  set_USB_EX_TOP_USB_INT_reg(data)                                        (*((volatile unsigned int*)USB_EX_TOP_USB_INT_reg)=data)
#define  get_USB_EX_TOP_USB_INT_reg                                              (*((volatile unsigned int*)USB_EX_TOP_USB_INT_reg))
#define  USB_EX_TOP_USB_INT_p0_hostdisconnect_dic_shift                          (2)
#define  USB_EX_TOP_USB_INT_int_ehci_dic_shift                                   (1)
#define  USB_EX_TOP_USB_INT_int_ohci_dic_shift                                   (0)
#define  USB_EX_TOP_USB_INT_p0_hostdisconnect_dic_mask                           (0x00000004)
#define  USB_EX_TOP_USB_INT_int_ehci_dic_mask                                    (0x00000002)
#define  USB_EX_TOP_USB_INT_int_ohci_dic_mask                                    (0x00000001)
#define  USB_EX_TOP_USB_INT_p0_hostdisconnect_dic(data)                          (0x00000004&((data)<<2))
#define  USB_EX_TOP_USB_INT_int_ehci_dic(data)                                   (0x00000002&((data)<<1))
#define  USB_EX_TOP_USB_INT_int_ohci_dic(data)                                   (0x00000001&(data))
#define  USB_EX_TOP_USB_INT_get_p0_hostdisconnect_dic(data)                      ((0x00000004&(data))>>2)
#define  USB_EX_TOP_USB_INT_get_int_ehci_dic(data)                               ((0x00000002&(data))>>1)
#define  USB_EX_TOP_USB_INT_get_int_ohci_dic(data)                               (0x00000001&(data))

#define  USB_EX_TOP_USB_debug                                                    0x1801288C
#define  USB_EX_TOP_USB_debug_reg_addr                                           "0xB801288C"
#define  USB_EX_TOP_USB_debug_reg                                                0xB801288C
#define  USB_EX_TOP_USB_debug_inst_addr                                          "0x0013"
#define  set_USB_EX_TOP_USB_debug_reg(data)                                      (*((volatile unsigned int*)USB_EX_TOP_USB_debug_reg)=data)
#define  get_USB_EX_TOP_USB_debug_reg                                            (*((volatile unsigned int*)USB_EX_TOP_USB_debug_reg))
#define  USB_EX_TOP_USB_debug_usb_dbg_out1_shift                                 (16)
#define  USB_EX_TOP_USB_debug_usb_dbg_out0_shift                                 (0)
#define  USB_EX_TOP_USB_debug_usb_dbg_out1_mask                                  (0xFFFF0000)
#define  USB_EX_TOP_USB_debug_usb_dbg_out0_mask                                  (0x0000FFFF)
#define  USB_EX_TOP_USB_debug_usb_dbg_out1(data)                                 (0xFFFF0000&((data)<<16))
#define  USB_EX_TOP_USB_debug_usb_dbg_out0(data)                                 (0x0000FFFF&(data))
#define  USB_EX_TOP_USB_debug_get_usb_dbg_out1(data)                             ((0xFFFF0000&(data))>>16)
#define  USB_EX_TOP_USB_debug_get_usb_dbg_out0(data)                             (0x0000FFFF&(data))

#define  USB_EX_TOP_WRAP_CTR                                                     0x18012900
#define  USB_EX_TOP_WRAP_CTR_reg_addr                                            "0xB8012900"
#define  USB_EX_TOP_WRAP_CTR_reg                                                 0xB8012900
#define  USB_EX_TOP_WRAP_CTR_inst_addr                                           "0x0014"
#define  set_USB_EX_TOP_WRAP_CTR_reg(data)                                       (*((volatile unsigned int*)USB_EX_TOP_WRAP_CTR_reg)=data)
#define  get_USB_EX_TOP_WRAP_CTR_reg                                             (*((volatile unsigned int*)USB_EX_TOP_WRAP_CTR_reg))
#define  USB_EX_TOP_WRAP_CTR_usb_bist_mode_otg_ram_shift                         (2)
#define  USB_EX_TOP_WRAP_CTR_usb_bist_mode_host_ram_shift                        (1)
#define  USB_EX_TOP_WRAP_CTR_usb_bist_mode_wrap_shift                            (0)
#define  USB_EX_TOP_WRAP_CTR_usb_bist_mode_otg_ram_mask                          (0x00000004)
#define  USB_EX_TOP_WRAP_CTR_usb_bist_mode_host_ram_mask                         (0x00000002)
#define  USB_EX_TOP_WRAP_CTR_usb_bist_mode_wrap_mask                             (0x00000001)
#define  USB_EX_TOP_WRAP_CTR_usb_bist_mode_otg_ram(data)                         (0x00000004&((data)<<2))
#define  USB_EX_TOP_WRAP_CTR_usb_bist_mode_host_ram(data)                        (0x00000002&((data)<<1))
#define  USB_EX_TOP_WRAP_CTR_usb_bist_mode_wrap(data)                            (0x00000001&(data))
#define  USB_EX_TOP_WRAP_CTR_get_usb_bist_mode_otg_ram(data)                     ((0x00000004&(data))>>2)
#define  USB_EX_TOP_WRAP_CTR_get_usb_bist_mode_host_ram(data)                    ((0x00000002&(data))>>1)
#define  USB_EX_TOP_WRAP_CTR_get_usb_bist_mode_wrap(data)                        (0x00000001&(data))

#define  USB_EX_TOP_USB_BIST1                                                    0x18012904
#define  USB_EX_TOP_USB_BIST1_reg_addr                                           "0xB8012904"
#define  USB_EX_TOP_USB_BIST1_reg                                                0xB8012904
#define  USB_EX_TOP_USB_BIST1_inst_addr                                          "0x0015"
#define  set_USB_EX_TOP_USB_BIST1_reg(data)                                      (*((volatile unsigned int*)USB_EX_TOP_USB_BIST1_reg)=data)
#define  get_USB_EX_TOP_USB_BIST1_reg                                            (*((volatile unsigned int*)USB_EX_TOP_USB_BIST1_reg))
#define  USB_EX_TOP_USB_BIST1_usb_bist_done_otg_ram_shift                        (2)
#define  USB_EX_TOP_USB_BIST1_usb_bist_done_host_ram_shift                       (1)
#define  USB_EX_TOP_USB_BIST1_usb_bist_done_wrap_shift                           (0)
#define  USB_EX_TOP_USB_BIST1_usb_bist_done_otg_ram_mask                         (0x00000004)
#define  USB_EX_TOP_USB_BIST1_usb_bist_done_host_ram_mask                        (0x00000002)
#define  USB_EX_TOP_USB_BIST1_usb_bist_done_wrap_mask                            (0x00000001)
#define  USB_EX_TOP_USB_BIST1_usb_bist_done_otg_ram(data)                        (0x00000004&((data)<<2))
#define  USB_EX_TOP_USB_BIST1_usb_bist_done_host_ram(data)                       (0x00000002&((data)<<1))
#define  USB_EX_TOP_USB_BIST1_usb_bist_done_wrap(data)                           (0x00000001&(data))
#define  USB_EX_TOP_USB_BIST1_get_usb_bist_done_otg_ram(data)                    ((0x00000004&(data))>>2)
#define  USB_EX_TOP_USB_BIST1_get_usb_bist_done_host_ram(data)                   ((0x00000002&(data))>>1)
#define  USB_EX_TOP_USB_BIST1_get_usb_bist_done_wrap(data)                       (0x00000001&(data))

#define  USB_EX_TOP_USB_BIST2                                                    0x18012908
#define  USB_EX_TOP_USB_BIST2_reg_addr                                           "0xB8012908"
#define  USB_EX_TOP_USB_BIST2_reg                                                0xB8012908
#define  USB_EX_TOP_USB_BIST2_inst_addr                                          "0x0016"
#define  set_USB_EX_TOP_USB_BIST2_reg(data)                                      (*((volatile unsigned int*)USB_EX_TOP_USB_BIST2_reg)=data)
#define  get_USB_EX_TOP_USB_BIST2_reg                                            (*((volatile unsigned int*)USB_EX_TOP_USB_BIST2_reg))
#define  USB_EX_TOP_USB_BIST2_usb_bist_fail_otg_ram_shift                        (2)
#define  USB_EX_TOP_USB_BIST2_usb_bist_fail_host_ram_shift                       (1)
#define  USB_EX_TOP_USB_BIST2_usb_bist_fail_wrap_shift                           (0)
#define  USB_EX_TOP_USB_BIST2_usb_bist_fail_otg_ram_mask                         (0x00000004)
#define  USB_EX_TOP_USB_BIST2_usb_bist_fail_host_ram_mask                        (0x00000002)
#define  USB_EX_TOP_USB_BIST2_usb_bist_fail_wrap_mask                            (0x00000001)
#define  USB_EX_TOP_USB_BIST2_usb_bist_fail_otg_ram(data)                        (0x00000004&((data)<<2))
#define  USB_EX_TOP_USB_BIST2_usb_bist_fail_host_ram(data)                       (0x00000002&((data)<<1))
#define  USB_EX_TOP_USB_BIST2_usb_bist_fail_wrap(data)                           (0x00000001&(data))
#define  USB_EX_TOP_USB_BIST2_get_usb_bist_fail_otg_ram(data)                    ((0x00000004&(data))>>2)
#define  USB_EX_TOP_USB_BIST2_get_usb_bist_fail_host_ram(data)                   ((0x00000002&(data))>>1)
#define  USB_EX_TOP_USB_BIST2_get_usb_bist_fail_wrap(data)                       (0x00000001&(data))

#define  USB_EX_TOP_USB_DRF0                                                     0x18012918
#define  USB_EX_TOP_USB_DRF0_reg_addr                                            "0xB8012918"
#define  USB_EX_TOP_USB_DRF0_reg                                                 0xB8012918
#define  USB_EX_TOP_USB_DRF0_inst_addr                                           "0x0017"
#define  set_USB_EX_TOP_USB_DRF0_reg(data)                                       (*((volatile unsigned int*)USB_EX_TOP_USB_DRF0_reg)=data)
#define  get_USB_EX_TOP_USB_DRF0_reg                                             (*((volatile unsigned int*)USB_EX_TOP_USB_DRF0_reg))
#define  USB_EX_TOP_USB_DRF0_usb_drf_mode_otg_ram_shift                          (2)
#define  USB_EX_TOP_USB_DRF0_usb_drf_mode_host_ram_shift                         (1)
#define  USB_EX_TOP_USB_DRF0_usb_drf_mode_wrap_shift                             (0)
#define  USB_EX_TOP_USB_DRF0_usb_drf_mode_otg_ram_mask                           (0x00000004)
#define  USB_EX_TOP_USB_DRF0_usb_drf_mode_host_ram_mask                          (0x00000002)
#define  USB_EX_TOP_USB_DRF0_usb_drf_mode_wrap_mask                              (0x00000001)
#define  USB_EX_TOP_USB_DRF0_usb_drf_mode_otg_ram(data)                          (0x00000004&((data)<<2))
#define  USB_EX_TOP_USB_DRF0_usb_drf_mode_host_ram(data)                         (0x00000002&((data)<<1))
#define  USB_EX_TOP_USB_DRF0_usb_drf_mode_wrap(data)                             (0x00000001&(data))
#define  USB_EX_TOP_USB_DRF0_get_usb_drf_mode_otg_ram(data)                      ((0x00000004&(data))>>2)
#define  USB_EX_TOP_USB_DRF0_get_usb_drf_mode_host_ram(data)                     ((0x00000002&(data))>>1)
#define  USB_EX_TOP_USB_DRF0_get_usb_drf_mode_wrap(data)                         (0x00000001&(data))

#define  USB_EX_TOP_USB_DRF1                                                     0x1801291C
#define  USB_EX_TOP_USB_DRF1_reg_addr                                            "0xB801291C"
#define  USB_EX_TOP_USB_DRF1_reg                                                 0xB801291C
#define  USB_EX_TOP_USB_DRF1_inst_addr                                           "0x0018"
#define  set_USB_EX_TOP_USB_DRF1_reg(data)                                       (*((volatile unsigned int*)USB_EX_TOP_USB_DRF1_reg)=data)
#define  get_USB_EX_TOP_USB_DRF1_reg                                             (*((volatile unsigned int*)USB_EX_TOP_USB_DRF1_reg))
#define  USB_EX_TOP_USB_DRF1_usb_drf_resume_otg_ram_shift                        (2)
#define  USB_EX_TOP_USB_DRF1_usb_drf_resume_host_ram_shift                       (1)
#define  USB_EX_TOP_USB_DRF1_usb_drf_resume_wrap_shift                           (0)
#define  USB_EX_TOP_USB_DRF1_usb_drf_resume_otg_ram_mask                         (0x00000004)
#define  USB_EX_TOP_USB_DRF1_usb_drf_resume_host_ram_mask                        (0x00000002)
#define  USB_EX_TOP_USB_DRF1_usb_drf_resume_wrap_mask                            (0x00000001)
#define  USB_EX_TOP_USB_DRF1_usb_drf_resume_otg_ram(data)                        (0x00000004&((data)<<2))
#define  USB_EX_TOP_USB_DRF1_usb_drf_resume_host_ram(data)                       (0x00000002&((data)<<1))
#define  USB_EX_TOP_USB_DRF1_usb_drf_resume_wrap(data)                           (0x00000001&(data))
#define  USB_EX_TOP_USB_DRF1_get_usb_drf_resume_otg_ram(data)                    ((0x00000004&(data))>>2)
#define  USB_EX_TOP_USB_DRF1_get_usb_drf_resume_host_ram(data)                   ((0x00000002&(data))>>1)
#define  USB_EX_TOP_USB_DRF1_get_usb_drf_resume_wrap(data)                       (0x00000001&(data))

#define  USB_EX_TOP_USB_DRF2                                                     0x18012920
#define  USB_EX_TOP_USB_DRF2_reg_addr                                            "0xB8012920"
#define  USB_EX_TOP_USB_DRF2_reg                                                 0xB8012920
#define  USB_EX_TOP_USB_DRF2_inst_addr                                           "0x0019"
#define  set_USB_EX_TOP_USB_DRF2_reg(data)                                       (*((volatile unsigned int*)USB_EX_TOP_USB_DRF2_reg)=data)
#define  get_USB_EX_TOP_USB_DRF2_reg                                             (*((volatile unsigned int*)USB_EX_TOP_USB_DRF2_reg))
#define  USB_EX_TOP_USB_DRF2_usb_drf_done_otg_ram_shift                          (2)
#define  USB_EX_TOP_USB_DRF2_usb_drf_done_host_ram_shift                         (1)
#define  USB_EX_TOP_USB_DRF2_usb_drf_done_wrap_shift                             (0)
#define  USB_EX_TOP_USB_DRF2_usb_drf_done_otg_ram_mask                           (0x00000004)
#define  USB_EX_TOP_USB_DRF2_usb_drf_done_host_ram_mask                          (0x00000002)
#define  USB_EX_TOP_USB_DRF2_usb_drf_done_wrap_mask                              (0x00000001)
#define  USB_EX_TOP_USB_DRF2_usb_drf_done_otg_ram(data)                          (0x00000004&((data)<<2))
#define  USB_EX_TOP_USB_DRF2_usb_drf_done_host_ram(data)                         (0x00000002&((data)<<1))
#define  USB_EX_TOP_USB_DRF2_usb_drf_done_wrap(data)                             (0x00000001&(data))
#define  USB_EX_TOP_USB_DRF2_get_usb_drf_done_otg_ram(data)                      ((0x00000004&(data))>>2)
#define  USB_EX_TOP_USB_DRF2_get_usb_drf_done_host_ram(data)                     ((0x00000002&(data))>>1)
#define  USB_EX_TOP_USB_DRF2_get_usb_drf_done_wrap(data)                         (0x00000001&(data))

#define  USB_EX_TOP_USB_DRF3                                                     0x18012924
#define  USB_EX_TOP_USB_DRF3_reg_addr                                            "0xB8012924"
#define  USB_EX_TOP_USB_DRF3_reg                                                 0xB8012924
#define  USB_EX_TOP_USB_DRF3_inst_addr                                           "0x001A"
#define  set_USB_EX_TOP_USB_DRF3_reg(data)                                       (*((volatile unsigned int*)USB_EX_TOP_USB_DRF3_reg)=data)
#define  get_USB_EX_TOP_USB_DRF3_reg                                             (*((volatile unsigned int*)USB_EX_TOP_USB_DRF3_reg))
#define  USB_EX_TOP_USB_DRF3_usb_drf_pause_otg_ram_shift                         (2)
#define  USB_EX_TOP_USB_DRF3_usb_drf_pause_host_ram_shift                        (1)
#define  USB_EX_TOP_USB_DRF3_usb_drf_pause_wrap_shift                            (0)
#define  USB_EX_TOP_USB_DRF3_usb_drf_pause_otg_ram_mask                          (0x00000004)
#define  USB_EX_TOP_USB_DRF3_usb_drf_pause_host_ram_mask                         (0x00000002)
#define  USB_EX_TOP_USB_DRF3_usb_drf_pause_wrap_mask                             (0x00000001)
#define  USB_EX_TOP_USB_DRF3_usb_drf_pause_otg_ram(data)                         (0x00000004&((data)<<2))
#define  USB_EX_TOP_USB_DRF3_usb_drf_pause_host_ram(data)                        (0x00000002&((data)<<1))
#define  USB_EX_TOP_USB_DRF3_usb_drf_pause_wrap(data)                            (0x00000001&(data))
#define  USB_EX_TOP_USB_DRF3_get_usb_drf_pause_otg_ram(data)                     ((0x00000004&(data))>>2)
#define  USB_EX_TOP_USB_DRF3_get_usb_drf_pause_host_ram(data)                    ((0x00000002&(data))>>1)
#define  USB_EX_TOP_USB_DRF3_get_usb_drf_pause_wrap(data)                        (0x00000001&(data))

#define  USB_EX_TOP_USB_DRF4                                                     0x18012928
#define  USB_EX_TOP_USB_DRF4_reg_addr                                            "0xB8012928"
#define  USB_EX_TOP_USB_DRF4_reg                                                 0xB8012928
#define  USB_EX_TOP_USB_DRF4_inst_addr                                           "0x001B"
#define  set_USB_EX_TOP_USB_DRF4_reg(data)                                       (*((volatile unsigned int*)USB_EX_TOP_USB_DRF4_reg)=data)
#define  get_USB_EX_TOP_USB_DRF4_reg                                             (*((volatile unsigned int*)USB_EX_TOP_USB_DRF4_reg))
#define  USB_EX_TOP_USB_DRF4_usb_drf_fail_otg_ram_shift                          (2)
#define  USB_EX_TOP_USB_DRF4_usb_drf_fail_host_ram_shift                         (1)
#define  USB_EX_TOP_USB_DRF4_usb_drf_fail_wrap_shift                             (0)
#define  USB_EX_TOP_USB_DRF4_usb_drf_fail_otg_ram_mask                           (0x00000004)
#define  USB_EX_TOP_USB_DRF4_usb_drf_fail_host_ram_mask                          (0x00000002)
#define  USB_EX_TOP_USB_DRF4_usb_drf_fail_wrap_mask                              (0x00000001)
#define  USB_EX_TOP_USB_DRF4_usb_drf_fail_otg_ram(data)                          (0x00000004&((data)<<2))
#define  USB_EX_TOP_USB_DRF4_usb_drf_fail_host_ram(data)                         (0x00000002&((data)<<1))
#define  USB_EX_TOP_USB_DRF4_usb_drf_fail_wrap(data)                             (0x00000001&(data))
#define  USB_EX_TOP_USB_DRF4_get_usb_drf_fail_otg_ram(data)                      ((0x00000004&(data))>>2)
#define  USB_EX_TOP_USB_DRF4_get_usb_drf_fail_host_ram(data)                     ((0x00000002&(data))>>1)
#define  USB_EX_TOP_USB_DRF4_get_usb_drf_fail_wrap(data)                         (0x00000001&(data))

#define  USB_EX_TOP_USB_BIST_OPTION0                                             0x18012938
#define  USB_EX_TOP_USB_BIST_OPTION0_reg_addr                                    "0xB8012938"
#define  USB_EX_TOP_USB_BIST_OPTION0_reg                                         0xB8012938
#define  USB_EX_TOP_USB_BIST_OPTION0_inst_addr                                   "0x001C"
#define  set_USB_EX_TOP_USB_BIST_OPTION0_reg(data)                               (*((volatile unsigned int*)USB_EX_TOP_USB_BIST_OPTION0_reg)=data)
#define  get_USB_EX_TOP_USB_BIST_OPTION0_reg                                     (*((volatile unsigned int*)USB_EX_TOP_USB_BIST_OPTION0_reg))
#define  USB_EX_TOP_USB_BIST_OPTION0_usb_bist_wrap_ls0_shift                     (5)
#define  USB_EX_TOP_USB_BIST_OPTION0_usb_bist_wrap_rme0_shift                    (4)
#define  USB_EX_TOP_USB_BIST_OPTION0_usb_bist_wrap_rm0_shift                     (0)
#define  USB_EX_TOP_USB_BIST_OPTION0_usb_bist_wrap_ls0_mask                      (0x00000020)
#define  USB_EX_TOP_USB_BIST_OPTION0_usb_bist_wrap_rme0_mask                     (0x00000010)
#define  USB_EX_TOP_USB_BIST_OPTION0_usb_bist_wrap_rm0_mask                      (0x0000000F)
#define  USB_EX_TOP_USB_BIST_OPTION0_usb_bist_wrap_ls0(data)                     (0x00000020&((data)<<5))
#define  USB_EX_TOP_USB_BIST_OPTION0_usb_bist_wrap_rme0(data)                    (0x00000010&((data)<<4))
#define  USB_EX_TOP_USB_BIST_OPTION0_usb_bist_wrap_rm0(data)                     (0x0000000F&(data))
#define  USB_EX_TOP_USB_BIST_OPTION0_get_usb_bist_wrap_ls0(data)                 ((0x00000020&(data))>>5)
#define  USB_EX_TOP_USB_BIST_OPTION0_get_usb_bist_wrap_rme0(data)                ((0x00000010&(data))>>4)
#define  USB_EX_TOP_USB_BIST_OPTION0_get_usb_bist_wrap_rm0(data)                 (0x0000000F&(data))

#define  USB_EX_TOP_USB_BIST_OPTION1                                             0x1801293C
#define  USB_EX_TOP_USB_BIST_OPTION1_reg_addr                                    "0xB801293C"
#define  USB_EX_TOP_USB_BIST_OPTION1_reg                                         0xB801293C
#define  USB_EX_TOP_USB_BIST_OPTION1_inst_addr                                   "0x001D"
#define  set_USB_EX_TOP_USB_BIST_OPTION1_reg(data)                               (*((volatile unsigned int*)USB_EX_TOP_USB_BIST_OPTION1_reg)=data)
#define  get_USB_EX_TOP_USB_BIST_OPTION1_reg                                     (*((volatile unsigned int*)USB_EX_TOP_USB_BIST_OPTION1_reg))
#define  USB_EX_TOP_USB_BIST_OPTION1_usb_usb_host_ram_ls0_shift                  (5)
#define  USB_EX_TOP_USB_BIST_OPTION1_usb_usb_host_ram_rme0_shift                 (4)
#define  USB_EX_TOP_USB_BIST_OPTION1_usb_usb_host_ram_rm0_shift                  (0)
#define  USB_EX_TOP_USB_BIST_OPTION1_usb_usb_host_ram_ls0_mask                   (0x00000020)
#define  USB_EX_TOP_USB_BIST_OPTION1_usb_usb_host_ram_rme0_mask                  (0x00000010)
#define  USB_EX_TOP_USB_BIST_OPTION1_usb_usb_host_ram_rm0_mask                   (0x0000000F)
#define  USB_EX_TOP_USB_BIST_OPTION1_usb_usb_host_ram_ls0(data)                  (0x00000020&((data)<<5))
#define  USB_EX_TOP_USB_BIST_OPTION1_usb_usb_host_ram_rme0(data)                 (0x00000010&((data)<<4))
#define  USB_EX_TOP_USB_BIST_OPTION1_usb_usb_host_ram_rm0(data)                  (0x0000000F&(data))
#define  USB_EX_TOP_USB_BIST_OPTION1_get_usb_usb_host_ram_ls0(data)              ((0x00000020&(data))>>5)
#define  USB_EX_TOP_USB_BIST_OPTION1_get_usb_usb_host_ram_rme0(data)             ((0x00000010&(data))>>4)
#define  USB_EX_TOP_USB_BIST_OPTION1_get_usb_usb_host_ram_rm0(data)              (0x0000000F&(data))

#define  USB_EX_TOP_USB_BIST_OPTION2                                             0x18012940
#define  USB_EX_TOP_USB_BIST_OPTION2_reg_addr                                    "0xB8012940"
#define  USB_EX_TOP_USB_BIST_OPTION2_reg                                         0xB8012940
#define  USB_EX_TOP_USB_BIST_OPTION2_inst_addr                                   "0x001E"
#define  set_USB_EX_TOP_USB_BIST_OPTION2_reg(data)                               (*((volatile unsigned int*)USB_EX_TOP_USB_BIST_OPTION2_reg)=data)
#define  get_USB_EX_TOP_USB_BIST_OPTION2_reg                                     (*((volatile unsigned int*)USB_EX_TOP_USB_BIST_OPTION2_reg))
#define  USB_EX_TOP_USB_BIST_OPTION2_usb_usb_otg_ram_ls0_shift                   (5)
#define  USB_EX_TOP_USB_BIST_OPTION2_usb_usb_otg_ram_rme0_shift                  (4)
#define  USB_EX_TOP_USB_BIST_OPTION2_usb_usb_otg_ram_rm0_shift                   (0)
#define  USB_EX_TOP_USB_BIST_OPTION2_usb_usb_otg_ram_ls0_mask                    (0x00000020)
#define  USB_EX_TOP_USB_BIST_OPTION2_usb_usb_otg_ram_rme0_mask                   (0x00000010)
#define  USB_EX_TOP_USB_BIST_OPTION2_usb_usb_otg_ram_rm0_mask                    (0x0000000F)
#define  USB_EX_TOP_USB_BIST_OPTION2_usb_usb_otg_ram_ls0(data)                   (0x00000020&((data)<<5))
#define  USB_EX_TOP_USB_BIST_OPTION2_usb_usb_otg_ram_rme0(data)                  (0x00000010&((data)<<4))
#define  USB_EX_TOP_USB_BIST_OPTION2_usb_usb_otg_ram_rm0(data)                   (0x0000000F&(data))
#define  USB_EX_TOP_USB_BIST_OPTION2_get_usb_usb_otg_ram_ls0(data)               ((0x00000020&(data))>>5)
#define  USB_EX_TOP_USB_BIST_OPTION2_get_usb_usb_otg_ram_rme0(data)              ((0x00000010&(data))>>4)
#define  USB_EX_TOP_USB_BIST_OPTION2_get_usb_usb_otg_ram_rm0(data)               (0x0000000F&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======USB_EX_TOP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  status_err:2;
        RBus_UInt32  res1:23;
        RBus_UInt32  suspend_r:1;
        RBus_UInt32  debug_mux:5;
        RBus_UInt32  packing:1;
    };
}usb_ex_top_wrapp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  vstatus_out:8;
    };
}usb_ex_top_vstatus_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwr_mux:1;
        RBus_UInt32  ovrcur_mux:1;
        RBus_UInt32  ss_resume_utmi_pls_dis_i:1;
        RBus_UInt32  ss_utmi_backward_enb_i:1;
        RBus_UInt32  utmi_suspend_mux:1;
        RBus_UInt32  host_disc_mux:1;
        RBus_UInt32  sys_interrupt_i:1;
        RBus_UInt32  ohci_0_app_irq12_i:1;
        RBus_UInt32  ohci_0_app_irq1_i:1;
        RBus_UInt32  ohci_0_app_io_hit_i:1;
        RBus_UInt32  ss_nxt_power_state_valid_i:1;
        RBus_UInt32  ss_next_power_state_i:2;
        RBus_UInt32  ss_power_state_i:2;
        RBus_UInt32  ohci_0_cntsel_i_n:1;
        RBus_UInt32  ohci_0_clkcktrst_i_n:1;
        RBus_UInt32  ehci_chirp_k_quick_resp_i:1;
        RBus_UInt32  ss_fladj_val_5_i:1;
        RBus_UInt32  ss_fladj_val_4_i:1;
        RBus_UInt32  ss_fladj_val_3_i:1;
        RBus_UInt32  ss_fladj_val_2_i:1;
        RBus_UInt32  ss_fladj_val_1_i:1;
        RBus_UInt32  ss_fladj_val_0_i:1;
        RBus_UInt32  ss_fladj_val_host_i:6;
        RBus_UInt32  ss_simulation_mode_i:1;
        RBus_UInt32  ss_word_if_i:1;
    };
}usb_ex_top_usbipinput_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  test_rst:1;
        RBus_UInt32  test_en:1;
        RBus_UInt32  reset_utmi:1;
    };
}usb_ex_top_reset_utmi_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  force_test_opmode_en:1;
        RBus_UInt32  test_opmode:2;
        RBus_UInt32  force_test_txvalid_en:1;
        RBus_UInt32  test_txvalid:1;
        RBus_UInt32  simulation_mode:1;
        RBus_UInt32  force_hs_mode:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  test_done:1;
        RBus_UInt32  test_fail:1;
        RBus_UInt32  test_speed:2;
        RBus_UInt32  test_seed:8;
        RBus_UInt32  test_psl:2;
    };
}usb_ex_top_self_loop_back_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  usbip_version:20;
        RBus_UInt32  trans_flag_host:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  dummy_reg:8;
        RBus_UInt32  nouse_done:1;
        RBus_UInt32  wrap_version:1;
    };
}usb_ex_top_version_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}usb_ex_top_wrapp_2port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}usb_ex_top_vstatus_2port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}usb_ex_top_usbipinput_2port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}usb_ex_top_reset_utmi_2port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}usb_ex_top_self_loop_back_2port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  p0_app_prt_ovrcur_i:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  p0_hostdisconnect:1;
        RBus_UInt32  res3:21;
        RBus_UInt32  ss_hubsetup_min_i:1;
        RBus_UInt32  app_start_clk_i:1;
        RBus_UInt32  ohci_susp_lgcy_i:1;
        RBus_UInt32  ss_ulpi_pp2vbus_i:1;
        RBus_UInt32  ss_autoppd_on_overcur_en_i:1;
        RBus_UInt32  ss_power_state_valid_i:1;
        RBus_UInt32  reg_usb_ck27m_sel:1;
    };
}usb_ex_top_ipnewinput_2port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  usbphy_slb_done:1;
        RBus_UInt32  usbphy_slb_fail:1;
        RBus_UInt32  usbphy_slb_hs:1;
        RBus_UInt32  usbphy_force_slb:1;
    };
}usb_ex_top_usbphy_slb0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}usb_ex_top_usbphy_slb1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg3840_dummy:32;
    };
}usb_ex_top_usb_dummy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg3848_dummy:13;
        RBus_UInt32  wrap_sram_rd_opt:1;
        RBus_UInt32  pll_alive_enable:1;
        RBus_UInt32  reg3848_dummy15:2;
        RBus_UInt32  usb2_ldo_pw_p0:1;
        RBus_UInt32  usb_top_int_en:1;
        RBus_UInt32  usbphy_pow_p1:1;
        RBus_UInt32  usbphy_pow_p0:1;
        RBus_UInt32  usbip_port1_soft_reset:1;
        RBus_UInt32  usbip_port0_soft_reset:1;
        RBus_UInt32  prt_pwren_reg_ds:2;
        RBus_UInt32  prt_pwren_ctrl:2;
        RBus_UInt32  prt_ovrcur_reg_ds:2;
        RBus_UInt32  prt_ovrcur_ctrl:2;
        RBus_UInt32  usb_dbg_ctrl:1;
    };
}usb_ex_top_usb_ctr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg384c_dummy:32;
    };
}usb_ex_top_usb_ctr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbus_rwlast_data_l:32;
    };
}usb_ex_top_wrapp_dbg1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbus_rwlast_data_h:32;
    };
}usb_ex_top_wrapp_dbg2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  ictrl_state:3;
        RBus_UInt32  dbus_dma_busy:1;
        RBus_UInt32  top_sm:15;
    };
}usb_ex_top_wrapp_dbg3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}usb_ex_top_wrapp_3port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}usb_ex_top_vstatus_3port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}usb_ex_top_usbipinput_3port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}usb_ex_top_reset_utmi_3port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}usb_ex_top_self_loop_back_3port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}usb_ex_top_usbphy_slb2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  eco_option0_dis:1;
    };
}usb_ex_top_usb_ctr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  reg_sf_tx_mode:1;
        RBus_UInt32  reg_sf_tx_start:1;
        RBus_UInt32  reg_sf_tx_work_ro:1;
        RBus_UInt32  reg_sf_rx_mode:1;
        RBus_UInt32  reg_sf_rx_start:1;
        RBus_UInt32  reg_sf_rx_gated:1;
        RBus_UInt32  reg_sf_rx_done_ro:1;
        RBus_UInt32  reg_sf_rx_err_ro:1;
    };
}usb_ex_top_sf_test_ctr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  indicator_en:1;
        RBus_UInt32  indicator_clear:1;
        RBus_UInt32  res1:10;
        RBus_UInt32  p0_discon_indic:1;
        RBus_UInt32  p0_chrip_indic:1;
        RBus_UInt32  p0_reset_indic:1;
        RBus_UInt32  p0_resume_indic:1;
        RBus_UInt32  p0_suspend_indic:1;
        RBus_UInt32  res2:10;
        RBus_UInt32  p0_portstate:5;
    };
}usb_ex_top_usb2_port_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  rx_crc_cnt_port0:10;
        RBus_UInt32  rx_crc_cnt_rst:1;
        RBus_UInt32  rx_crc_cnt_en:1;
    };
}usb_ex_top_usb_crc_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  p0_hostdisconnect_dic:1;
        RBus_UInt32  int_ehci_dic:1;
        RBus_UInt32  int_ohci_dic:1;
    };
}usb_ex_top_usb_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  usb_dbg_out1:16;
        RBus_UInt32  usb_dbg_out0:16;
    };
}usb_ex_top_usb_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  usb_bist_mode_otg_ram:1;
        RBus_UInt32  usb_bist_mode_host_ram:1;
        RBus_UInt32  usb_bist_mode_wrap:1;
    };
}usb_ex_top_wrap_ctr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  usb_bist_done_otg_ram:1;
        RBus_UInt32  usb_bist_done_host_ram:1;
        RBus_UInt32  usb_bist_done_wrap:1;
    };
}usb_ex_top_usb_bist1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  usb_bist_fail_otg_ram:1;
        RBus_UInt32  usb_bist_fail_host_ram:1;
        RBus_UInt32  usb_bist_fail_wrap:1;
    };
}usb_ex_top_usb_bist2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  usb_drf_mode_otg_ram:1;
        RBus_UInt32  usb_drf_mode_host_ram:1;
        RBus_UInt32  usb_drf_mode_wrap:1;
    };
}usb_ex_top_usb_drf0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  usb_drf_resume_otg_ram:1;
        RBus_UInt32  usb_drf_resume_host_ram:1;
        RBus_UInt32  usb_drf_resume_wrap:1;
    };
}usb_ex_top_usb_drf1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  usb_drf_done_otg_ram:1;
        RBus_UInt32  usb_drf_done_host_ram:1;
        RBus_UInt32  usb_drf_done_wrap:1;
    };
}usb_ex_top_usb_drf2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  usb_drf_pause_otg_ram:1;
        RBus_UInt32  usb_drf_pause_host_ram:1;
        RBus_UInt32  usb_drf_pause_wrap:1;
    };
}usb_ex_top_usb_drf3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  usb_drf_fail_otg_ram:1;
        RBus_UInt32  usb_drf_fail_host_ram:1;
        RBus_UInt32  usb_drf_fail_wrap:1;
    };
}usb_ex_top_usb_drf4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  usb_bist_wrap_ls0:1;
        RBus_UInt32  usb_bist_wrap_rme0:1;
        RBus_UInt32  usb_bist_wrap_rm0:4;
    };
}usb_ex_top_usb_bist_option0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  usb_usb_host_ram_ls0:1;
        RBus_UInt32  usb_usb_host_ram_rme0:1;
        RBus_UInt32  usb_usb_host_ram_rm0:4;
    };
}usb_ex_top_usb_bist_option1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  usb_usb_otg_ram_ls0:1;
        RBus_UInt32  usb_usb_otg_ram_rme0:1;
        RBus_UInt32  usb_usb_otg_ram_rm0:4;
    };
}usb_ex_top_usb_bist_option2_RBUS;

#else //apply LITTLE_ENDIAN

//======USB_EX_TOP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  packing:1;
        RBus_UInt32  debug_mux:5;
        RBus_UInt32  suspend_r:1;
        RBus_UInt32  res1:23;
        RBus_UInt32  status_err:2;
    };
}usb_ex_top_wrapp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vstatus_out:8;
        RBus_UInt32  res1:24;
    };
}usb_ex_top_vstatus_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ss_word_if_i:1;
        RBus_UInt32  ss_simulation_mode_i:1;
        RBus_UInt32  ss_fladj_val_host_i:6;
        RBus_UInt32  ss_fladj_val_0_i:1;
        RBus_UInt32  ss_fladj_val_1_i:1;
        RBus_UInt32  ss_fladj_val_2_i:1;
        RBus_UInt32  ss_fladj_val_3_i:1;
        RBus_UInt32  ss_fladj_val_4_i:1;
        RBus_UInt32  ss_fladj_val_5_i:1;
        RBus_UInt32  ehci_chirp_k_quick_resp_i:1;
        RBus_UInt32  ohci_0_clkcktrst_i_n:1;
        RBus_UInt32  ohci_0_cntsel_i_n:1;
        RBus_UInt32  ss_power_state_i:2;
        RBus_UInt32  ss_next_power_state_i:2;
        RBus_UInt32  ss_nxt_power_state_valid_i:1;
        RBus_UInt32  ohci_0_app_io_hit_i:1;
        RBus_UInt32  ohci_0_app_irq1_i:1;
        RBus_UInt32  ohci_0_app_irq12_i:1;
        RBus_UInt32  sys_interrupt_i:1;
        RBus_UInt32  host_disc_mux:1;
        RBus_UInt32  utmi_suspend_mux:1;
        RBus_UInt32  ss_utmi_backward_enb_i:1;
        RBus_UInt32  ss_resume_utmi_pls_dis_i:1;
        RBus_UInt32  ovrcur_mux:1;
        RBus_UInt32  pwr_mux:1;
    };
}usb_ex_top_usbipinput_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reset_utmi:1;
        RBus_UInt32  test_en:1;
        RBus_UInt32  test_rst:1;
        RBus_UInt32  res1:29;
    };
}usb_ex_top_reset_utmi_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  test_psl:2;
        RBus_UInt32  test_seed:8;
        RBus_UInt32  test_speed:2;
        RBus_UInt32  test_fail:1;
        RBus_UInt32  test_done:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  force_hs_mode:1;
        RBus_UInt32  simulation_mode:1;
        RBus_UInt32  test_txvalid:1;
        RBus_UInt32  force_test_txvalid_en:1;
        RBus_UInt32  test_opmode:2;
        RBus_UInt32  force_test_opmode_en:1;
        RBus_UInt32  res2:9;
    };
}usb_ex_top_self_loop_back_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wrap_version:1;
        RBus_UInt32  nouse_done:1;
        RBus_UInt32  dummy_reg:8;
        RBus_UInt32  res1:1;
        RBus_UInt32  trans_flag_host:1;
        RBus_UInt32  usbip_version:20;
    };
}usb_ex_top_version_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}usb_ex_top_wrapp_2port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}usb_ex_top_vstatus_2port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}usb_ex_top_usbipinput_2port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}usb_ex_top_reset_utmi_2port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}usb_ex_top_self_loop_back_2port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_usb_ck27m_sel:1;
        RBus_UInt32  ss_power_state_valid_i:1;
        RBus_UInt32  ss_autoppd_on_overcur_en_i:1;
        RBus_UInt32  ss_ulpi_pp2vbus_i:1;
        RBus_UInt32  ohci_susp_lgcy_i:1;
        RBus_UInt32  app_start_clk_i:1;
        RBus_UInt32  ss_hubsetup_min_i:1;
        RBus_UInt32  res1:21;
        RBus_UInt32  p0_hostdisconnect:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  p0_app_prt_ovrcur_i:1;
        RBus_UInt32  res3:1;
    };
}usb_ex_top_ipnewinput_2port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  usbphy_force_slb:1;
        RBus_UInt32  usbphy_slb_hs:1;
        RBus_UInt32  usbphy_slb_fail:1;
        RBus_UInt32  usbphy_slb_done:1;
        RBus_UInt32  res1:28;
    };
}usb_ex_top_usbphy_slb0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}usb_ex_top_usbphy_slb1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg3840_dummy:32;
    };
}usb_ex_top_usb_dummy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  usb_dbg_ctrl:1;
        RBus_UInt32  prt_ovrcur_ctrl:2;
        RBus_UInt32  prt_ovrcur_reg_ds:2;
        RBus_UInt32  prt_pwren_ctrl:2;
        RBus_UInt32  prt_pwren_reg_ds:2;
        RBus_UInt32  usbip_port0_soft_reset:1;
        RBus_UInt32  usbip_port1_soft_reset:1;
        RBus_UInt32  usbphy_pow_p0:1;
        RBus_UInt32  usbphy_pow_p1:1;
        RBus_UInt32  usb_top_int_en:1;
        RBus_UInt32  usb2_ldo_pw_p0:1;
        RBus_UInt32  reg3848_dummy15:2;
        RBus_UInt32  pll_alive_enable:1;
        RBus_UInt32  wrap_sram_rd_opt:1;
        RBus_UInt32  reg3848_dummy:13;
    };
}usb_ex_top_usb_ctr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg384c_dummy:32;
    };
}usb_ex_top_usb_ctr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbus_rwlast_data_l:32;
    };
}usb_ex_top_wrapp_dbg1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbus_rwlast_data_h:32;
    };
}usb_ex_top_wrapp_dbg2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  top_sm:15;
        RBus_UInt32  dbus_dma_busy:1;
        RBus_UInt32  ictrl_state:3;
        RBus_UInt32  res1:13;
    };
}usb_ex_top_wrapp_dbg3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}usb_ex_top_wrapp_3port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}usb_ex_top_vstatus_3port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}usb_ex_top_usbipinput_3port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}usb_ex_top_reset_utmi_3port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}usb_ex_top_self_loop_back_3port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}usb_ex_top_usbphy_slb2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eco_option0_dis:1;
        RBus_UInt32  res1:31;
    };
}usb_ex_top_usb_ctr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_sf_rx_err_ro:1;
        RBus_UInt32  reg_sf_rx_done_ro:1;
        RBus_UInt32  reg_sf_rx_gated:1;
        RBus_UInt32  reg_sf_rx_start:1;
        RBus_UInt32  reg_sf_rx_mode:1;
        RBus_UInt32  reg_sf_tx_work_ro:1;
        RBus_UInt32  reg_sf_tx_start:1;
        RBus_UInt32  reg_sf_tx_mode:1;
        RBus_UInt32  res1:24;
    };
}usb_ex_top_sf_test_ctr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p0_portstate:5;
        RBus_UInt32  res1:10;
        RBus_UInt32  p0_suspend_indic:1;
        RBus_UInt32  p0_resume_indic:1;
        RBus_UInt32  p0_reset_indic:1;
        RBus_UInt32  p0_chrip_indic:1;
        RBus_UInt32  p0_discon_indic:1;
        RBus_UInt32  res2:10;
        RBus_UInt32  indicator_clear:1;
        RBus_UInt32  indicator_en:1;
    };
}usb_ex_top_usb2_port_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rx_crc_cnt_en:1;
        RBus_UInt32  rx_crc_cnt_rst:1;
        RBus_UInt32  rx_crc_cnt_port0:10;
        RBus_UInt32  res1:20;
    };
}usb_ex_top_usb_crc_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_ohci_dic:1;
        RBus_UInt32  int_ehci_dic:1;
        RBus_UInt32  p0_hostdisconnect_dic:1;
        RBus_UInt32  res1:29;
    };
}usb_ex_top_usb_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  usb_dbg_out0:16;
        RBus_UInt32  usb_dbg_out1:16;
    };
}usb_ex_top_usb_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  usb_bist_mode_wrap:1;
        RBus_UInt32  usb_bist_mode_host_ram:1;
        RBus_UInt32  usb_bist_mode_otg_ram:1;
        RBus_UInt32  res1:29;
    };
}usb_ex_top_wrap_ctr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  usb_bist_done_wrap:1;
        RBus_UInt32  usb_bist_done_host_ram:1;
        RBus_UInt32  usb_bist_done_otg_ram:1;
        RBus_UInt32  res1:29;
    };
}usb_ex_top_usb_bist1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  usb_bist_fail_wrap:1;
        RBus_UInt32  usb_bist_fail_host_ram:1;
        RBus_UInt32  usb_bist_fail_otg_ram:1;
        RBus_UInt32  res1:29;
    };
}usb_ex_top_usb_bist2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  usb_drf_mode_wrap:1;
        RBus_UInt32  usb_drf_mode_host_ram:1;
        RBus_UInt32  usb_drf_mode_otg_ram:1;
        RBus_UInt32  res1:29;
    };
}usb_ex_top_usb_drf0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  usb_drf_resume_wrap:1;
        RBus_UInt32  usb_drf_resume_host_ram:1;
        RBus_UInt32  usb_drf_resume_otg_ram:1;
        RBus_UInt32  res1:29;
    };
}usb_ex_top_usb_drf1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  usb_drf_done_wrap:1;
        RBus_UInt32  usb_drf_done_host_ram:1;
        RBus_UInt32  usb_drf_done_otg_ram:1;
        RBus_UInt32  res1:29;
    };
}usb_ex_top_usb_drf2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  usb_drf_pause_wrap:1;
        RBus_UInt32  usb_drf_pause_host_ram:1;
        RBus_UInt32  usb_drf_pause_otg_ram:1;
        RBus_UInt32  res1:29;
    };
}usb_ex_top_usb_drf3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  usb_drf_fail_wrap:1;
        RBus_UInt32  usb_drf_fail_host_ram:1;
        RBus_UInt32  usb_drf_fail_otg_ram:1;
        RBus_UInt32  res1:29;
    };
}usb_ex_top_usb_drf4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  usb_bist_wrap_rm0:4;
        RBus_UInt32  usb_bist_wrap_rme0:1;
        RBus_UInt32  usb_bist_wrap_ls0:1;
        RBus_UInt32  res1:26;
    };
}usb_ex_top_usb_bist_option0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  usb_usb_host_ram_rm0:4;
        RBus_UInt32  usb_usb_host_ram_rme0:1;
        RBus_UInt32  usb_usb_host_ram_ls0:1;
        RBus_UInt32  res1:26;
    };
}usb_ex_top_usb_bist_option1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  usb_usb_otg_ram_rm0:4;
        RBus_UInt32  usb_usb_otg_ram_rme0:1;
        RBus_UInt32  usb_usb_otg_ram_ls0:1;
        RBus_UInt32  res1:26;
    };
}usb_ex_top_usb_bist_option2_RBUS;




#endif 


#endif 
