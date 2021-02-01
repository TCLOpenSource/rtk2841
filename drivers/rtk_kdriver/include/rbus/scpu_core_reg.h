/**
* @file Mac5-DesignSpec-SCPU_Core_Spec
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_SCPU_CORE_REG_H_
#define _RBUS_SCPU_CORE_REG_H_

#include "rbus_types.h"



//  SCPU_CORE Register Address
#define  SCPU_CORE_sys_pll_scpu1                                                 0x1805B000
#define  SCPU_CORE_sys_pll_scpu1_reg_addr                                        "0xB805B000"
#define  SCPU_CORE_sys_pll_scpu1_reg                                             0xB805B000
#define  SCPU_CORE_sys_pll_scpu1_inst_addr                                       "0x0000"
#define  set_SCPU_CORE_sys_pll_scpu1_reg(data)                                   (*((volatile unsigned int*)SCPU_CORE_sys_pll_scpu1_reg)=data)
#define  get_SCPU_CORE_sys_pll_scpu1_reg                                         (*((volatile unsigned int*)SCPU_CORE_sys_pll_scpu1_reg))
#define  SCPU_CORE_sys_pll_scpu1_pllscpu_wdset_shift                             (21)
#define  SCPU_CORE_sys_pll_scpu1_pllscpu_wdrst_shift                             (20)
#define  SCPU_CORE_sys_pll_scpu1_pllscpu_lpf_cs_shift                            (16)
#define  SCPU_CORE_sys_pll_scpu1_pllscpu_testsel_shift                           (13)
#define  SCPU_CORE_sys_pll_scpu1_pllscpu_sel_cco_shift                           (12)
#define  SCPU_CORE_sys_pll_scpu1_pllscpu_icp_shift                               (8)
#define  SCPU_CORE_sys_pll_scpu1_pllscpu_dbug_en_shift                           (7)
#define  SCPU_CORE_sys_pll_scpu1_pllscpu_pdiv_bps_shift                          (6)
#define  SCPU_CORE_sys_pll_scpu1_pllscpu_pdiv_shift                              (4)
#define  SCPU_CORE_sys_pll_scpu1_pllscpu_lpf_rs_shift                            (0)
#define  SCPU_CORE_sys_pll_scpu1_pllscpu_wdset_mask                              (0x00200000)
#define  SCPU_CORE_sys_pll_scpu1_pllscpu_wdrst_mask                              (0x00100000)
#define  SCPU_CORE_sys_pll_scpu1_pllscpu_lpf_cs_mask                             (0x00030000)
#define  SCPU_CORE_sys_pll_scpu1_pllscpu_testsel_mask                            (0x00002000)
#define  SCPU_CORE_sys_pll_scpu1_pllscpu_sel_cco_mask                            (0x00001000)
#define  SCPU_CORE_sys_pll_scpu1_pllscpu_icp_mask                                (0x00000700)
#define  SCPU_CORE_sys_pll_scpu1_pllscpu_dbug_en_mask                            (0x00000080)
#define  SCPU_CORE_sys_pll_scpu1_pllscpu_pdiv_bps_mask                           (0x00000040)
#define  SCPU_CORE_sys_pll_scpu1_pllscpu_pdiv_mask                               (0x00000030)
#define  SCPU_CORE_sys_pll_scpu1_pllscpu_lpf_rs_mask                             (0x00000007)
#define  SCPU_CORE_sys_pll_scpu1_pllscpu_wdset(data)                             (0x00200000&((data)<<21))
#define  SCPU_CORE_sys_pll_scpu1_pllscpu_wdrst(data)                             (0x00100000&((data)<<20))
#define  SCPU_CORE_sys_pll_scpu1_pllscpu_lpf_cs(data)                            (0x00030000&((data)<<16))
#define  SCPU_CORE_sys_pll_scpu1_pllscpu_testsel(data)                           (0x00002000&((data)<<13))
#define  SCPU_CORE_sys_pll_scpu1_pllscpu_sel_cco(data)                           (0x00001000&((data)<<12))
#define  SCPU_CORE_sys_pll_scpu1_pllscpu_icp(data)                               (0x00000700&((data)<<8))
#define  SCPU_CORE_sys_pll_scpu1_pllscpu_dbug_en(data)                           (0x00000080&((data)<<7))
#define  SCPU_CORE_sys_pll_scpu1_pllscpu_pdiv_bps(data)                          (0x00000040&((data)<<6))
#define  SCPU_CORE_sys_pll_scpu1_pllscpu_pdiv(data)                              (0x00000030&((data)<<4))
#define  SCPU_CORE_sys_pll_scpu1_pllscpu_lpf_rs(data)                            (0x00000007&(data))
#define  SCPU_CORE_sys_pll_scpu1_get_pllscpu_wdset(data)                         ((0x00200000&(data))>>21)
#define  SCPU_CORE_sys_pll_scpu1_get_pllscpu_wdrst(data)                         ((0x00100000&(data))>>20)
#define  SCPU_CORE_sys_pll_scpu1_get_pllscpu_lpf_cs(data)                        ((0x00030000&(data))>>16)
#define  SCPU_CORE_sys_pll_scpu1_get_pllscpu_testsel(data)                       ((0x00002000&(data))>>13)
#define  SCPU_CORE_sys_pll_scpu1_get_pllscpu_sel_cco(data)                       ((0x00001000&(data))>>12)
#define  SCPU_CORE_sys_pll_scpu1_get_pllscpu_icp(data)                           ((0x00000700&(data))>>8)
#define  SCPU_CORE_sys_pll_scpu1_get_pllscpu_dbug_en(data)                       ((0x00000080&(data))>>7)
#define  SCPU_CORE_sys_pll_scpu1_get_pllscpu_pdiv_bps(data)                      ((0x00000040&(data))>>6)
#define  SCPU_CORE_sys_pll_scpu1_get_pllscpu_pdiv(data)                          ((0x00000030&(data))>>4)
#define  SCPU_CORE_sys_pll_scpu1_get_pllscpu_lpf_rs(data)                        (0x00000007&(data))

#define  SCPU_CORE_sys_pll_scpu2                                                 0x1805B004
#define  SCPU_CORE_sys_pll_scpu2_reg_addr                                        "0xB805B004"
#define  SCPU_CORE_sys_pll_scpu2_reg                                             0xB805B004
#define  SCPU_CORE_sys_pll_scpu2_inst_addr                                       "0x0001"
#define  set_SCPU_CORE_sys_pll_scpu2_reg(data)                                   (*((volatile unsigned int*)SCPU_CORE_sys_pll_scpu2_reg)=data)
#define  get_SCPU_CORE_sys_pll_scpu2_reg                                         (*((volatile unsigned int*)SCPU_CORE_sys_pll_scpu2_reg))
#define  SCPU_CORE_sys_pll_scpu2_pllscpu_fcode_shift                             (16)
#define  SCPU_CORE_sys_pll_scpu2_pllscpu_ncode_shift                             (8)
#define  SCPU_CORE_sys_pll_scpu2_pllscpu_oeb_shift                               (2)
#define  SCPU_CORE_sys_pll_scpu2_pllscpu_rstb_shift                              (1)
#define  SCPU_CORE_sys_pll_scpu2_pllscpu_pow_shift                               (0)
#define  SCPU_CORE_sys_pll_scpu2_pllscpu_fcode_mask                              (0x07FF0000)
#define  SCPU_CORE_sys_pll_scpu2_pllscpu_ncode_mask                              (0x0000FF00)
#define  SCPU_CORE_sys_pll_scpu2_pllscpu_oeb_mask                                (0x00000004)
#define  SCPU_CORE_sys_pll_scpu2_pllscpu_rstb_mask                               (0x00000002)
#define  SCPU_CORE_sys_pll_scpu2_pllscpu_pow_mask                                (0x00000001)
#define  SCPU_CORE_sys_pll_scpu2_pllscpu_fcode(data)                             (0x07FF0000&((data)<<16))
#define  SCPU_CORE_sys_pll_scpu2_pllscpu_ncode(data)                             (0x0000FF00&((data)<<8))
#define  SCPU_CORE_sys_pll_scpu2_pllscpu_oeb(data)                               (0x00000004&((data)<<2))
#define  SCPU_CORE_sys_pll_scpu2_pllscpu_rstb(data)                              (0x00000002&((data)<<1))
#define  SCPU_CORE_sys_pll_scpu2_pllscpu_pow(data)                               (0x00000001&(data))
#define  SCPU_CORE_sys_pll_scpu2_get_pllscpu_fcode(data)                         ((0x07FF0000&(data))>>16)
#define  SCPU_CORE_sys_pll_scpu2_get_pllscpu_ncode(data)                         ((0x0000FF00&(data))>>8)
#define  SCPU_CORE_sys_pll_scpu2_get_pllscpu_oeb(data)                           ((0x00000004&(data))>>2)
#define  SCPU_CORE_sys_pll_scpu2_get_pllscpu_rstb(data)                          ((0x00000002&(data))>>1)
#define  SCPU_CORE_sys_pll_scpu2_get_pllscpu_pow(data)                           (0x00000001&(data))

#define  SCPU_CORE_sys_scpu_dvfs                                                 0x1805B008
#define  SCPU_CORE_sys_scpu_dvfs_reg_addr                                        "0xB805B008"
#define  SCPU_CORE_sys_scpu_dvfs_reg                                             0xB805B008
#define  SCPU_CORE_sys_scpu_dvfs_inst_addr                                       "0x0002"
#define  set_SCPU_CORE_sys_scpu_dvfs_reg(data)                                   (*((volatile unsigned int*)SCPU_CORE_sys_scpu_dvfs_reg)=data)
#define  get_SCPU_CORE_sys_scpu_dvfs_reg                                         (*((volatile unsigned int*)SCPU_CORE_sys_scpu_dvfs_reg))
#define  SCPU_CORE_sys_scpu_dvfs_pllscpu_bypass_pi_shift                         (31)
#define  SCPU_CORE_sys_scpu_dvfs_pllscpu_en_pi_debug_shift                       (30)
#define  SCPU_CORE_sys_scpu_dvfs_pllscpu_hs_oc_stop_shift                        (28)
#define  SCPU_CORE_sys_scpu_dvfs_pllscpu_pi_cur_sel_shift                        (26)
#define  SCPU_CORE_sys_scpu_dvfs_pllscpu_sel_oc_mode_shift                       (24)
#define  SCPU_CORE_sys_scpu_dvfs_pllscpu_ldo10v_sel_shift                        (22)
#define  SCPU_CORE_sys_scpu_dvfs_pllscpu_ldo18v_sel_shift                        (20)
#define  SCPU_CORE_sys_scpu_dvfs_pllscpu_oc_done_delay_shift                     (14)
#define  SCPU_CORE_sys_scpu_dvfs_pllscpu_oc_step_shift                           (4)
#define  SCPU_CORE_sys_scpu_dvfs_pllscpu_sdm_order_shift                         (2)
#define  SCPU_CORE_sys_scpu_dvfs_pllscpu_oc_en_shift                             (0)
#define  SCPU_CORE_sys_scpu_dvfs_pllscpu_bypass_pi_mask                          (0x80000000)
#define  SCPU_CORE_sys_scpu_dvfs_pllscpu_en_pi_debug_mask                        (0x40000000)
#define  SCPU_CORE_sys_scpu_dvfs_pllscpu_hs_oc_stop_mask                         (0x30000000)
#define  SCPU_CORE_sys_scpu_dvfs_pllscpu_pi_cur_sel_mask                         (0x0C000000)
#define  SCPU_CORE_sys_scpu_dvfs_pllscpu_sel_oc_mode_mask                        (0x03000000)
#define  SCPU_CORE_sys_scpu_dvfs_pllscpu_ldo10v_sel_mask                         (0x00C00000)
#define  SCPU_CORE_sys_scpu_dvfs_pllscpu_ldo18v_sel_mask                         (0x00300000)
#define  SCPU_CORE_sys_scpu_dvfs_pllscpu_oc_done_delay_mask                      (0x000FC000)
#define  SCPU_CORE_sys_scpu_dvfs_pllscpu_oc_step_mask                            (0x00003FF0)
#define  SCPU_CORE_sys_scpu_dvfs_pllscpu_sdm_order_mask                          (0x00000004)
#define  SCPU_CORE_sys_scpu_dvfs_pllscpu_oc_en_mask                              (0x00000001)
#define  SCPU_CORE_sys_scpu_dvfs_pllscpu_bypass_pi(data)                         (0x80000000&((data)<<31))
#define  SCPU_CORE_sys_scpu_dvfs_pllscpu_en_pi_debug(data)                       (0x40000000&((data)<<30))
#define  SCPU_CORE_sys_scpu_dvfs_pllscpu_hs_oc_stop(data)                        (0x30000000&((data)<<28))
#define  SCPU_CORE_sys_scpu_dvfs_pllscpu_pi_cur_sel(data)                        (0x0C000000&((data)<<26))
#define  SCPU_CORE_sys_scpu_dvfs_pllscpu_sel_oc_mode(data)                       (0x03000000&((data)<<24))
#define  SCPU_CORE_sys_scpu_dvfs_pllscpu_ldo10v_sel(data)                        (0x00C00000&((data)<<22))
#define  SCPU_CORE_sys_scpu_dvfs_pllscpu_ldo18v_sel(data)                        (0x00300000&((data)<<20))
#define  SCPU_CORE_sys_scpu_dvfs_pllscpu_oc_done_delay(data)                     (0x000FC000&((data)<<14))
#define  SCPU_CORE_sys_scpu_dvfs_pllscpu_oc_step(data)                           (0x00003FF0&((data)<<4))
#define  SCPU_CORE_sys_scpu_dvfs_pllscpu_sdm_order(data)                         (0x00000004&((data)<<2))
#define  SCPU_CORE_sys_scpu_dvfs_pllscpu_oc_en(data)                             (0x00000001&(data))
#define  SCPU_CORE_sys_scpu_dvfs_get_pllscpu_bypass_pi(data)                     ((0x80000000&(data))>>31)
#define  SCPU_CORE_sys_scpu_dvfs_get_pllscpu_en_pi_debug(data)                   ((0x40000000&(data))>>30)
#define  SCPU_CORE_sys_scpu_dvfs_get_pllscpu_hs_oc_stop(data)                    ((0x30000000&(data))>>28)
#define  SCPU_CORE_sys_scpu_dvfs_get_pllscpu_pi_cur_sel(data)                    ((0x0C000000&(data))>>26)
#define  SCPU_CORE_sys_scpu_dvfs_get_pllscpu_sel_oc_mode(data)                   ((0x03000000&(data))>>24)
#define  SCPU_CORE_sys_scpu_dvfs_get_pllscpu_ldo10v_sel(data)                    ((0x00C00000&(data))>>22)
#define  SCPU_CORE_sys_scpu_dvfs_get_pllscpu_ldo18v_sel(data)                    ((0x00300000&(data))>>20)
#define  SCPU_CORE_sys_scpu_dvfs_get_pllscpu_oc_done_delay(data)                 ((0x000FC000&(data))>>14)
#define  SCPU_CORE_sys_scpu_dvfs_get_pllscpu_oc_step(data)                       ((0x00003FF0&(data))>>4)
#define  SCPU_CORE_sys_scpu_dvfs_get_pllscpu_sdm_order(data)                     ((0x00000004&(data))>>2)
#define  SCPU_CORE_sys_scpu_dvfs_get_pllscpu_oc_en(data)                         (0x00000001&(data))

#define  SCPU_CORE_sys_scpu_status                                               0x1805B00C
#define  SCPU_CORE_sys_scpu_status_reg_addr                                      "0xB805B00C"
#define  SCPU_CORE_sys_scpu_status_reg                                           0xB805B00C
#define  SCPU_CORE_sys_scpu_status_inst_addr                                     "0x0003"
#define  set_SCPU_CORE_sys_scpu_status_reg(data)                                 (*((volatile unsigned int*)SCPU_CORE_sys_scpu_status_reg)=data)
#define  get_SCPU_CORE_sys_scpu_status_reg                                       (*((volatile unsigned int*)SCPU_CORE_sys_scpu_status_reg))
#define  SCPU_CORE_sys_scpu_status_pllscpu_wdout_ro_shift                        (21)
#define  SCPU_CORE_sys_scpu_status_pllscpu_oc_done_ro_shift                      (20)
#define  SCPU_CORE_sys_scpu_status_pllscpu_ncode_dbg_ro_shift                    (12)
#define  SCPU_CORE_sys_scpu_status_pllscpu_fcode_dbg_ro_shift                    (1)
#define  SCPU_CORE_sys_scpu_status_pllscpu_dfvs_fmod_dbg_shift                   (0)
#define  SCPU_CORE_sys_scpu_status_pllscpu_wdout_ro_mask                         (0x00200000)
#define  SCPU_CORE_sys_scpu_status_pllscpu_oc_done_ro_mask                       (0x00100000)
#define  SCPU_CORE_sys_scpu_status_pllscpu_ncode_dbg_ro_mask                     (0x000FF000)
#define  SCPU_CORE_sys_scpu_status_pllscpu_fcode_dbg_ro_mask                     (0x00000FFE)
#define  SCPU_CORE_sys_scpu_status_pllscpu_dfvs_fmod_dbg_mask                    (0x00000001)
#define  SCPU_CORE_sys_scpu_status_pllscpu_wdout_ro(data)                        (0x00200000&((data)<<21))
#define  SCPU_CORE_sys_scpu_status_pllscpu_oc_done_ro(data)                      (0x00100000&((data)<<20))
#define  SCPU_CORE_sys_scpu_status_pllscpu_ncode_dbg_ro(data)                    (0x000FF000&((data)<<12))
#define  SCPU_CORE_sys_scpu_status_pllscpu_fcode_dbg_ro(data)                    (0x00000FFE&((data)<<1))
#define  SCPU_CORE_sys_scpu_status_pllscpu_dfvs_fmod_dbg(data)                   (0x00000001&(data))
#define  SCPU_CORE_sys_scpu_status_get_pllscpu_wdout_ro(data)                    ((0x00200000&(data))>>21)
#define  SCPU_CORE_sys_scpu_status_get_pllscpu_oc_done_ro(data)                  ((0x00100000&(data))>>20)
#define  SCPU_CORE_sys_scpu_status_get_pllscpu_ncode_dbg_ro(data)                ((0x000FF000&(data))>>12)
#define  SCPU_CORE_sys_scpu_status_get_pllscpu_fcode_dbg_ro(data)                ((0x00000FFE&(data))>>1)
#define  SCPU_CORE_sys_scpu_status_get_pllscpu_dfvs_fmod_dbg(data)               (0x00000001&(data))

#define  SCPU_CORE_sys_scpu_reserve                                              0x1805B010
#define  SCPU_CORE_sys_scpu_reserve_reg_addr                                     "0xB805B010"
#define  SCPU_CORE_sys_scpu_reserve_reg                                          0xB805B010
#define  SCPU_CORE_sys_scpu_reserve_inst_addr                                    "0x0004"
#define  set_SCPU_CORE_sys_scpu_reserve_reg(data)                                (*((volatile unsigned int*)SCPU_CORE_sys_scpu_reserve_reg)=data)
#define  get_SCPU_CORE_sys_scpu_reserve_reg                                      (*((volatile unsigned int*)SCPU_CORE_sys_scpu_reserve_reg))
#define  SCPU_CORE_sys_scpu_reserve_pllscpu_reserve_shift                        (0)
#define  SCPU_CORE_sys_scpu_reserve_pllscpu_reserve_mask                         (0x0000003F)
#define  SCPU_CORE_sys_scpu_reserve_pllscpu_reserve(data)                        (0x0000003F&(data))
#define  SCPU_CORE_sys_scpu_reserve_get_pllscpu_reserve(data)                    (0x0000003F&(data))

#define  SCPU_CORE_sys_scpu_ckinv                                                0x1805B040
#define  SCPU_CORE_sys_scpu_ckinv_reg_addr                                       "0xB805B040"
#define  SCPU_CORE_sys_scpu_ckinv_reg                                            0xB805B040
#define  SCPU_CORE_sys_scpu_ckinv_inst_addr                                      "0x0005"
#define  set_SCPU_CORE_sys_scpu_ckinv_reg(data)                                  (*((volatile unsigned int*)SCPU_CORE_sys_scpu_ckinv_reg)=data)
#define  get_SCPU_CORE_sys_scpu_ckinv_reg                                        (*((volatile unsigned int*)SCPU_CORE_sys_scpu_ckinv_reg))
#define  SCPU_CORE_sys_scpu_ckinv_scpu_ssc_ckinv_shift                           (0)
#define  SCPU_CORE_sys_scpu_ckinv_scpu_ssc_ckinv_mask                            (0x00000001)
#define  SCPU_CORE_sys_scpu_ckinv_scpu_ssc_ckinv(data)                           (0x00000001&(data))
#define  SCPU_CORE_sys_scpu_ckinv_get_scpu_ssc_ckinv(data)                       (0x00000001&(data))

#define  SCPU_CORE_sys_scpu_clkratio_ctrl_0                                      0x1805B044
#define  SCPU_CORE_sys_scpu_clkratio_ctrl_0_reg_addr                             "0xB805B044"
#define  SCPU_CORE_sys_scpu_clkratio_ctrl_0_reg                                  0xB805B044
#define  SCPU_CORE_sys_scpu_clkratio_ctrl_0_inst_addr                            "0x0006"
#define  set_SCPU_CORE_sys_scpu_clkratio_ctrl_0_reg(data)                        (*((volatile unsigned int*)SCPU_CORE_sys_scpu_clkratio_ctrl_0_reg)=data)
#define  get_SCPU_CORE_sys_scpu_clkratio_ctrl_0_reg                              (*((volatile unsigned int*)SCPU_CORE_sys_scpu_clkratio_ctrl_0_reg))
#define  SCPU_CORE_sys_scpu_clkratio_ctrl_0_clkratio_scpu_shift                  (0)
#define  SCPU_CORE_sys_scpu_clkratio_ctrl_0_clkratio_scpu_mask                   (0x0000001F)
#define  SCPU_CORE_sys_scpu_clkratio_ctrl_0_clkratio_scpu(data)                  (0x0000001F&(data))
#define  SCPU_CORE_sys_scpu_clkratio_ctrl_0_get_clkratio_scpu(data)              (0x0000001F&(data))

#define  SCPU_CORE_sys_scpu_clkratio_ctrl_1                                      0x1805B048
#define  SCPU_CORE_sys_scpu_clkratio_ctrl_1_reg_addr                             "0xB805B048"
#define  SCPU_CORE_sys_scpu_clkratio_ctrl_1_reg                                  0xB805B048
#define  SCPU_CORE_sys_scpu_clkratio_ctrl_1_inst_addr                            "0x0007"
#define  set_SCPU_CORE_sys_scpu_clkratio_ctrl_1_reg(data)                        (*((volatile unsigned int*)SCPU_CORE_sys_scpu_clkratio_ctrl_1_reg)=data)
#define  get_SCPU_CORE_sys_scpu_clkratio_ctrl_1_reg                              (*((volatile unsigned int*)SCPU_CORE_sys_scpu_clkratio_ctrl_1_reg))
#define  SCPU_CORE_sys_scpu_clkratio_ctrl_1_clkratio_scpu_active_shift           (0)
#define  SCPU_CORE_sys_scpu_clkratio_ctrl_1_clkratio_scpu_active_mask            (0x00000001)
#define  SCPU_CORE_sys_scpu_clkratio_ctrl_1_clkratio_scpu_active(data)           (0x00000001&(data))
#define  SCPU_CORE_sys_scpu_clkratio_ctrl_1_get_clkratio_scpu_active(data)       (0x00000001&(data))

#define  SCPU_CORE_sys_scpu_clken                                                0x1805B04C
#define  SCPU_CORE_sys_scpu_clken_reg_addr                                       "0xB805B04C"
#define  SCPU_CORE_sys_scpu_clken_reg                                            0xB805B04C
#define  SCPU_CORE_sys_scpu_clken_inst_addr                                      "0x0008"
#define  set_SCPU_CORE_sys_scpu_clken_reg(data)                                  (*((volatile unsigned int*)SCPU_CORE_sys_scpu_clken_reg)=data)
#define  get_SCPU_CORE_sys_scpu_clken_reg                                        (*((volatile unsigned int*)SCPU_CORE_sys_scpu_clken_reg))
#define  SCPU_CORE_sys_scpu_clken_clken_dss_shift                                (14)
#define  SCPU_CORE_sys_scpu_clken_clken_a53_atb_shift                            (12)
#define  SCPU_CORE_sys_scpu_clken_clken_a53_apb_shift                            (11)
#define  SCPU_CORE_sys_scpu_clken_clken_top_atb_shift                            (10)
#define  SCPU_CORE_sys_scpu_clken_clken_top_apb_shift                            (9)
#define  SCPU_CORE_sys_scpu_clken_clken_a53_shift                                (6)
#define  SCPU_CORE_sys_scpu_clken_clken_scpu_top_logic_shift                     (2)
#define  SCPU_CORE_sys_scpu_clken_clken_top_ts_shift                             (0)
#define  SCPU_CORE_sys_scpu_clken_clken_dss_mask                                 (0x00004000)
#define  SCPU_CORE_sys_scpu_clken_clken_a53_atb_mask                             (0x00001000)
#define  SCPU_CORE_sys_scpu_clken_clken_a53_apb_mask                             (0x00000800)
#define  SCPU_CORE_sys_scpu_clken_clken_top_atb_mask                             (0x00000400)
#define  SCPU_CORE_sys_scpu_clken_clken_top_apb_mask                             (0x00000200)
#define  SCPU_CORE_sys_scpu_clken_clken_a53_mask                                 (0x00000040)
#define  SCPU_CORE_sys_scpu_clken_clken_scpu_top_logic_mask                      (0x00000004)
#define  SCPU_CORE_sys_scpu_clken_clken_top_ts_mask                              (0x00000001)
#define  SCPU_CORE_sys_scpu_clken_clken_dss(data)                                (0x00004000&((data)<<14))
#define  SCPU_CORE_sys_scpu_clken_clken_a53_atb(data)                            (0x00001000&((data)<<12))
#define  SCPU_CORE_sys_scpu_clken_clken_a53_apb(data)                            (0x00000800&((data)<<11))
#define  SCPU_CORE_sys_scpu_clken_clken_top_atb(data)                            (0x00000400&((data)<<10))
#define  SCPU_CORE_sys_scpu_clken_clken_top_apb(data)                            (0x00000200&((data)<<9))
#define  SCPU_CORE_sys_scpu_clken_clken_a53(data)                                (0x00000040&((data)<<6))
#define  SCPU_CORE_sys_scpu_clken_clken_scpu_top_logic(data)                     (0x00000004&((data)<<2))
#define  SCPU_CORE_sys_scpu_clken_clken_top_ts(data)                             (0x00000001&(data))
#define  SCPU_CORE_sys_scpu_clken_get_clken_dss(data)                            ((0x00004000&(data))>>14)
#define  SCPU_CORE_sys_scpu_clken_get_clken_a53_atb(data)                        ((0x00001000&(data))>>12)
#define  SCPU_CORE_sys_scpu_clken_get_clken_a53_apb(data)                        ((0x00000800&(data))>>11)
#define  SCPU_CORE_sys_scpu_clken_get_clken_top_atb(data)                        ((0x00000400&(data))>>10)
#define  SCPU_CORE_sys_scpu_clken_get_clken_top_apb(data)                        ((0x00000200&(data))>>9)
#define  SCPU_CORE_sys_scpu_clken_get_clken_a53(data)                            ((0x00000040&(data))>>6)
#define  SCPU_CORE_sys_scpu_clken_get_clken_scpu_top_logic(data)                 ((0x00000004&(data))>>2)
#define  SCPU_CORE_sys_scpu_clken_get_clken_top_ts(data)                         (0x00000001&(data))

#define  SCPU_CORE_sys_scpu_clkdiv_sel                                           0x1805B050
#define  SCPU_CORE_sys_scpu_clkdiv_sel_reg_addr                                  "0xB805B050"
#define  SCPU_CORE_sys_scpu_clkdiv_sel_reg                                       0xB805B050
#define  SCPU_CORE_sys_scpu_clkdiv_sel_inst_addr                                 "0x0009"
#define  set_SCPU_CORE_sys_scpu_clkdiv_sel_reg(data)                             (*((volatile unsigned int*)SCPU_CORE_sys_scpu_clkdiv_sel_reg)=data)
#define  get_SCPU_CORE_sys_scpu_clkdiv_sel_reg                                   (*((volatile unsigned int*)SCPU_CORE_sys_scpu_clkdiv_sel_reg))
#define  SCPU_CORE_sys_scpu_clkdiv_sel_trc_clk_delay_shift                       (2)
#define  SCPU_CORE_sys_scpu_clkdiv_sel_trc_clkdiv_sel_shift                      (0)
#define  SCPU_CORE_sys_scpu_clkdiv_sel_trc_clk_delay_mask                        (0x0000003C)
#define  SCPU_CORE_sys_scpu_clkdiv_sel_trc_clkdiv_sel_mask                       (0x00000003)
#define  SCPU_CORE_sys_scpu_clkdiv_sel_trc_clk_delay(data)                       (0x0000003C&((data)<<2))
#define  SCPU_CORE_sys_scpu_clkdiv_sel_trc_clkdiv_sel(data)                      (0x00000003&(data))
#define  SCPU_CORE_sys_scpu_clkdiv_sel_get_trc_clk_delay(data)                   ((0x0000003C&(data))>>2)
#define  SCPU_CORE_sys_scpu_clkdiv_sel_get_trc_clkdiv_sel(data)                  (0x00000003&(data))

#define  SCPU_CORE_sys_scpu_rst                                                  0x1805B054
#define  SCPU_CORE_sys_scpu_rst_reg_addr                                         "0xB805B054"
#define  SCPU_CORE_sys_scpu_rst_reg                                              0xB805B054
#define  SCPU_CORE_sys_scpu_rst_inst_addr                                        "0x000A"
#define  set_SCPU_CORE_sys_scpu_rst_reg(data)                                    (*((volatile unsigned int*)SCPU_CORE_sys_scpu_rst_reg)=data)
#define  get_SCPU_CORE_sys_scpu_rst_reg                                          (*((volatile unsigned int*)SCPU_CORE_sys_scpu_rst_reg))
#define  SCPU_CORE_sys_scpu_rst_resetsocdbgn_shift                               (14)
#define  SCPU_CORE_sys_scpu_rst_scpu_nic_rstn_shift                              (13)
#define  SCPU_CORE_sys_scpu_rst_scpu_core0_rstn_shift                            (12)
#define  SCPU_CORE_sys_scpu_rst_scpu_core1_rstn_shift                            (11)
#define  SCPU_CORE_sys_scpu_rst_scpu_core0_poreset_n_shift                       (10)
#define  SCPU_CORE_sys_scpu_rst_scpu_core1_poreset_n_shift                       (9)
#define  SCPU_CORE_sys_scpu_rst_scpu_dbg_rstn_shift                              (8)
#define  SCPU_CORE_sys_scpu_rst_scpu_l2_rstn_shift                               (7)
#define  SCPU_CORE_sys_scpu_rst_scpu_core2_rstn_shift                            (6)
#define  SCPU_CORE_sys_scpu_rst_scpu_core3_rstn_shift                            (5)
#define  SCPU_CORE_sys_scpu_rst_scpu_core2_poreset_n_shift                       (4)
#define  SCPU_CORE_sys_scpu_rst_scpu_core3_poreset_n_shift                       (3)
#define  SCPU_CORE_sys_scpu_rst_scpu_gic_rstn_shift                              (0)
#define  SCPU_CORE_sys_scpu_rst_resetsocdbgn_mask                                (0x00004000)
#define  SCPU_CORE_sys_scpu_rst_scpu_nic_rstn_mask                               (0x00002000)
#define  SCPU_CORE_sys_scpu_rst_scpu_core0_rstn_mask                             (0x00001000)
#define  SCPU_CORE_sys_scpu_rst_scpu_core1_rstn_mask                             (0x00000800)
#define  SCPU_CORE_sys_scpu_rst_scpu_core0_poreset_n_mask                        (0x00000400)
#define  SCPU_CORE_sys_scpu_rst_scpu_core1_poreset_n_mask                        (0x00000200)
#define  SCPU_CORE_sys_scpu_rst_scpu_dbg_rstn_mask                               (0x00000100)
#define  SCPU_CORE_sys_scpu_rst_scpu_l2_rstn_mask                                (0x00000080)
#define  SCPU_CORE_sys_scpu_rst_scpu_core2_rstn_mask                             (0x00000040)
#define  SCPU_CORE_sys_scpu_rst_scpu_core3_rstn_mask                             (0x00000020)
#define  SCPU_CORE_sys_scpu_rst_scpu_core2_poreset_n_mask                        (0x00000010)
#define  SCPU_CORE_sys_scpu_rst_scpu_core3_poreset_n_mask                        (0x00000008)
#define  SCPU_CORE_sys_scpu_rst_scpu_gic_rstn_mask                               (0x00000001)
#define  SCPU_CORE_sys_scpu_rst_resetsocdbgn(data)                               (0x00004000&((data)<<14))
#define  SCPU_CORE_sys_scpu_rst_scpu_nic_rstn(data)                              (0x00002000&((data)<<13))
#define  SCPU_CORE_sys_scpu_rst_scpu_core0_rstn(data)                            (0x00001000&((data)<<12))
#define  SCPU_CORE_sys_scpu_rst_scpu_core1_rstn(data)                            (0x00000800&((data)<<11))
#define  SCPU_CORE_sys_scpu_rst_scpu_core0_poreset_n(data)                       (0x00000400&((data)<<10))
#define  SCPU_CORE_sys_scpu_rst_scpu_core1_poreset_n(data)                       (0x00000200&((data)<<9))
#define  SCPU_CORE_sys_scpu_rst_scpu_dbg_rstn(data)                              (0x00000100&((data)<<8))
#define  SCPU_CORE_sys_scpu_rst_scpu_l2_rstn(data)                               (0x00000080&((data)<<7))
#define  SCPU_CORE_sys_scpu_rst_scpu_core2_rstn(data)                            (0x00000040&((data)<<6))
#define  SCPU_CORE_sys_scpu_rst_scpu_core3_rstn(data)                            (0x00000020&((data)<<5))
#define  SCPU_CORE_sys_scpu_rst_scpu_core2_poreset_n(data)                       (0x00000010&((data)<<4))
#define  SCPU_CORE_sys_scpu_rst_scpu_core3_poreset_n(data)                       (0x00000008&((data)<<3))
#define  SCPU_CORE_sys_scpu_rst_scpu_gic_rstn(data)                              (0x00000001&(data))
#define  SCPU_CORE_sys_scpu_rst_get_resetsocdbgn(data)                           ((0x00004000&(data))>>14)
#define  SCPU_CORE_sys_scpu_rst_get_scpu_nic_rstn(data)                          ((0x00002000&(data))>>13)
#define  SCPU_CORE_sys_scpu_rst_get_scpu_core0_rstn(data)                        ((0x00001000&(data))>>12)
#define  SCPU_CORE_sys_scpu_rst_get_scpu_core1_rstn(data)                        ((0x00000800&(data))>>11)
#define  SCPU_CORE_sys_scpu_rst_get_scpu_core0_poreset_n(data)                   ((0x00000400&(data))>>10)
#define  SCPU_CORE_sys_scpu_rst_get_scpu_core1_poreset_n(data)                   ((0x00000200&(data))>>9)
#define  SCPU_CORE_sys_scpu_rst_get_scpu_dbg_rstn(data)                          ((0x00000100&(data))>>8)
#define  SCPU_CORE_sys_scpu_rst_get_scpu_l2_rstn(data)                           ((0x00000080&(data))>>7)
#define  SCPU_CORE_sys_scpu_rst_get_scpu_core2_rstn(data)                        ((0x00000040&(data))>>6)
#define  SCPU_CORE_sys_scpu_rst_get_scpu_core3_rstn(data)                        ((0x00000020&(data))>>5)
#define  SCPU_CORE_sys_scpu_rst_get_scpu_core2_poreset_n(data)                   ((0x00000010&(data))>>4)
#define  SCPU_CORE_sys_scpu_rst_get_scpu_core3_poreset_n(data)                   ((0x00000008&(data))>>3)
#define  SCPU_CORE_sys_scpu_rst_get_scpu_gic_rstn(data)                          (0x00000001&(data))

#define  SCPU_CORE_sys_warmrst_en                                                0x1805B058
#define  SCPU_CORE_sys_warmrst_en_reg_addr                                       "0xB805B058"
#define  SCPU_CORE_sys_warmrst_en_reg                                            0xB805B058
#define  SCPU_CORE_sys_warmrst_en_inst_addr                                      "0x000B"
#define  set_SCPU_CORE_sys_warmrst_en_reg(data)                                  (*((volatile unsigned int*)SCPU_CORE_sys_warmrst_en_reg)=data)
#define  get_SCPU_CORE_sys_warmrst_en_reg                                        (*((volatile unsigned int*)SCPU_CORE_sys_warmrst_en_reg))
#define  SCPU_CORE_sys_warmrst_en_a53_warmreset_en_shift                         (0)
#define  SCPU_CORE_sys_warmrst_en_a53_warmreset_en_mask                          (0x00000001)
#define  SCPU_CORE_sys_warmrst_en_a53_warmreset_en(data)                         (0x00000001&(data))
#define  SCPU_CORE_sys_warmrst_en_get_a53_warmreset_en(data)                     (0x00000001&(data))

#define  SCPU_CORE_voltage_probe_ctrl                                            0x1805B400
#define  SCPU_CORE_voltage_probe_ctrl_reg_addr                                   "0xB805B400"
#define  SCPU_CORE_voltage_probe_ctrl_reg                                        0xB805B400
#define  SCPU_CORE_voltage_probe_ctrl_inst_addr                                  "0x000C"
#define  set_SCPU_CORE_voltage_probe_ctrl_reg(data)                              (*((volatile unsigned int*)SCPU_CORE_voltage_probe_ctrl_reg)=data)
#define  get_SCPU_CORE_voltage_probe_ctrl_reg                                    (*((volatile unsigned int*)SCPU_CORE_voltage_probe_ctrl_reg))
#define  SCPU_CORE_voltage_probe_ctrl_voltprob_a53_c0_pwr_ctrl_shift             (6)
#define  SCPU_CORE_voltage_probe_ctrl_voltprob_a53_c0_gnd_ctrl_shift             (4)
#define  SCPU_CORE_voltage_probe_ctrl_voltprob_scpu_lvl_pwr_ctrl_shift           (1)
#define  SCPU_CORE_voltage_probe_ctrl_voltprob_scpu_lvl_gnd_ctrl_shift           (0)
#define  SCPU_CORE_voltage_probe_ctrl_voltprob_a53_c0_pwr_ctrl_mask              (0x000000C0)
#define  SCPU_CORE_voltage_probe_ctrl_voltprob_a53_c0_gnd_ctrl_mask              (0x00000030)
#define  SCPU_CORE_voltage_probe_ctrl_voltprob_scpu_lvl_pwr_ctrl_mask            (0x00000002)
#define  SCPU_CORE_voltage_probe_ctrl_voltprob_scpu_lvl_gnd_ctrl_mask            (0x00000001)
#define  SCPU_CORE_voltage_probe_ctrl_voltprob_a53_c0_pwr_ctrl(data)             (0x000000C0&((data)<<6))
#define  SCPU_CORE_voltage_probe_ctrl_voltprob_a53_c0_gnd_ctrl(data)             (0x00000030&((data)<<4))
#define  SCPU_CORE_voltage_probe_ctrl_voltprob_scpu_lvl_pwr_ctrl(data)           (0x00000002&((data)<<1))
#define  SCPU_CORE_voltage_probe_ctrl_voltprob_scpu_lvl_gnd_ctrl(data)           (0x00000001&(data))
#define  SCPU_CORE_voltage_probe_ctrl_get_voltprob_a53_c0_pwr_ctrl(data)         ((0x000000C0&(data))>>6)
#define  SCPU_CORE_voltage_probe_ctrl_get_voltprob_a53_c0_gnd_ctrl(data)         ((0x00000030&(data))>>4)
#define  SCPU_CORE_voltage_probe_ctrl_get_voltprob_scpu_lvl_pwr_ctrl(data)       ((0x00000002&(data))>>1)
#define  SCPU_CORE_voltage_probe_ctrl_get_voltprob_scpu_lvl_gnd_ctrl(data)       (0x00000001&(data))

#define  SCPU_CORE_dss_ctrl_0                                                    0x1805B404
#define  SCPU_CORE_dss_ctrl_0_reg_addr                                           "0xB805B404"
#define  SCPU_CORE_dss_ctrl_0_reg                                                0xB805B404
#define  SCPU_CORE_dss_ctrl_0_inst_addr                                          "0x000D"
#define  set_SCPU_CORE_dss_ctrl_0_reg(data)                                      (*((volatile unsigned int*)SCPU_CORE_dss_ctrl_0_reg)=data)
#define  get_SCPU_CORE_dss_ctrl_0_reg                                            (*((volatile unsigned int*)SCPU_CORE_dss_ctrl_0_reg))
#define  SCPU_CORE_dss_ctrl_0_a53_dss_rst_n_shift                                (31)
#define  SCPU_CORE_dss_ctrl_0_a53_ro_sel_shift                                   (28)
#define  SCPU_CORE_dss_ctrl_0_a53_wire_sel_shift                                 (26)
#define  SCPU_CORE_dss_ctrl_0_a53_speed_en_0_shift                               (25)
#define  SCPU_CORE_dss_ctrl_0_a53_speed_en_1_shift                               (24)
#define  SCPU_CORE_dss_ctrl_0_a53_dss_rst_n_mask                                 (0x80000000)
#define  SCPU_CORE_dss_ctrl_0_a53_ro_sel_mask                                    (0x70000000)
#define  SCPU_CORE_dss_ctrl_0_a53_wire_sel_mask                                  (0x04000000)
#define  SCPU_CORE_dss_ctrl_0_a53_speed_en_0_mask                                (0x02000000)
#define  SCPU_CORE_dss_ctrl_0_a53_speed_en_1_mask                                (0x01000000)
#define  SCPU_CORE_dss_ctrl_0_a53_dss_rst_n(data)                                (0x80000000&((data)<<31))
#define  SCPU_CORE_dss_ctrl_0_a53_ro_sel(data)                                   (0x70000000&((data)<<28))
#define  SCPU_CORE_dss_ctrl_0_a53_wire_sel(data)                                 (0x04000000&((data)<<26))
#define  SCPU_CORE_dss_ctrl_0_a53_speed_en_0(data)                               (0x02000000&((data)<<25))
#define  SCPU_CORE_dss_ctrl_0_a53_speed_en_1(data)                               (0x01000000&((data)<<24))
#define  SCPU_CORE_dss_ctrl_0_get_a53_dss_rst_n(data)                            ((0x80000000&(data))>>31)
#define  SCPU_CORE_dss_ctrl_0_get_a53_ro_sel(data)                               ((0x70000000&(data))>>28)
#define  SCPU_CORE_dss_ctrl_0_get_a53_wire_sel(data)                             ((0x04000000&(data))>>26)
#define  SCPU_CORE_dss_ctrl_0_get_a53_speed_en_0(data)                           ((0x02000000&(data))>>25)
#define  SCPU_CORE_dss_ctrl_0_get_a53_speed_en_1(data)                           ((0x01000000&(data))>>24)

#define  SCPU_CORE_dss_ctrl_1                                                    0x1805B408
#define  SCPU_CORE_dss_ctrl_1_reg_addr                                           "0xB805B408"
#define  SCPU_CORE_dss_ctrl_1_reg                                                0xB805B408
#define  SCPU_CORE_dss_ctrl_1_inst_addr                                          "0x000E"
#define  set_SCPU_CORE_dss_ctrl_1_reg(data)                                      (*((volatile unsigned int*)SCPU_CORE_dss_ctrl_1_reg)=data)
#define  get_SCPU_CORE_dss_ctrl_1_reg                                            (*((volatile unsigned int*)SCPU_CORE_dss_ctrl_1_reg))
#define  SCPU_CORE_dss_ctrl_1_scpu_c31_9p5t_data_in_shift                        (12)
#define  SCPU_CORE_dss_ctrl_1_scpu_c31_9p5t_dss_rst_n_shift                      (11)
#define  SCPU_CORE_dss_ctrl_1_scpu_c31_9p5t_ro_sel_shift                         (8)
#define  SCPU_CORE_dss_ctrl_1_scpu_c31_9p5t_speed_en_shift                       (7)
#define  SCPU_CORE_dss_ctrl_1_scpu_c31_9p5t_wire_sel_shift                       (6)
#define  SCPU_CORE_dss_ctrl_1_scpu_c31_9p5t_data_in_mask                         (0xFFFFF000)
#define  SCPU_CORE_dss_ctrl_1_scpu_c31_9p5t_dss_rst_n_mask                       (0x00000800)
#define  SCPU_CORE_dss_ctrl_1_scpu_c31_9p5t_ro_sel_mask                          (0x00000700)
#define  SCPU_CORE_dss_ctrl_1_scpu_c31_9p5t_speed_en_mask                        (0x00000080)
#define  SCPU_CORE_dss_ctrl_1_scpu_c31_9p5t_wire_sel_mask                        (0x00000040)
#define  SCPU_CORE_dss_ctrl_1_scpu_c31_9p5t_data_in(data)                        (0xFFFFF000&((data)<<12))
#define  SCPU_CORE_dss_ctrl_1_scpu_c31_9p5t_dss_rst_n(data)                      (0x00000800&((data)<<11))
#define  SCPU_CORE_dss_ctrl_1_scpu_c31_9p5t_ro_sel(data)                         (0x00000700&((data)<<8))
#define  SCPU_CORE_dss_ctrl_1_scpu_c31_9p5t_speed_en(data)                       (0x00000080&((data)<<7))
#define  SCPU_CORE_dss_ctrl_1_scpu_c31_9p5t_wire_sel(data)                       (0x00000040&((data)<<6))
#define  SCPU_CORE_dss_ctrl_1_get_scpu_c31_9p5t_data_in(data)                    ((0xFFFFF000&(data))>>12)
#define  SCPU_CORE_dss_ctrl_1_get_scpu_c31_9p5t_dss_rst_n(data)                  ((0x00000800&(data))>>11)
#define  SCPU_CORE_dss_ctrl_1_get_scpu_c31_9p5t_ro_sel(data)                     ((0x00000700&(data))>>8)
#define  SCPU_CORE_dss_ctrl_1_get_scpu_c31_9p5t_speed_en(data)                   ((0x00000080&(data))>>7)
#define  SCPU_CORE_dss_ctrl_1_get_scpu_c31_9p5t_wire_sel(data)                   ((0x00000040&(data))>>6)

#define  SCPU_CORE_dss_ctrl_2                                                    0x1805B40C
#define  SCPU_CORE_dss_ctrl_2_reg_addr                                           "0xB805B40C"
#define  SCPU_CORE_dss_ctrl_2_reg                                                0xB805B40C
#define  SCPU_CORE_dss_ctrl_2_inst_addr                                          "0x000F"
#define  set_SCPU_CORE_dss_ctrl_2_reg(data)                                      (*((volatile unsigned int*)SCPU_CORE_dss_ctrl_2_reg)=data)
#define  get_SCPU_CORE_dss_ctrl_2_reg                                            (*((volatile unsigned int*)SCPU_CORE_dss_ctrl_2_reg))
#define  SCPU_CORE_dss_ctrl_2_scpu_c35_9p5t_data_in_shift                        (12)
#define  SCPU_CORE_dss_ctrl_2_scpu_c35_9p5t_dss_rst_n_shift                      (11)
#define  SCPU_CORE_dss_ctrl_2_scpu_c35_9p5t_ro_sel_shift                         (8)
#define  SCPU_CORE_dss_ctrl_2_scpu_c35_9p5t_speed_en_shift                       (7)
#define  SCPU_CORE_dss_ctrl_2_scpu_c35_9p5t_wire_sel_shift                       (6)
#define  SCPU_CORE_dss_ctrl_2_scpu_c35_9p5t_data_in_mask                         (0xFFFFF000)
#define  SCPU_CORE_dss_ctrl_2_scpu_c35_9p5t_dss_rst_n_mask                       (0x00000800)
#define  SCPU_CORE_dss_ctrl_2_scpu_c35_9p5t_ro_sel_mask                          (0x00000700)
#define  SCPU_CORE_dss_ctrl_2_scpu_c35_9p5t_speed_en_mask                        (0x00000080)
#define  SCPU_CORE_dss_ctrl_2_scpu_c35_9p5t_wire_sel_mask                        (0x00000040)
#define  SCPU_CORE_dss_ctrl_2_scpu_c35_9p5t_data_in(data)                        (0xFFFFF000&((data)<<12))
#define  SCPU_CORE_dss_ctrl_2_scpu_c35_9p5t_dss_rst_n(data)                      (0x00000800&((data)<<11))
#define  SCPU_CORE_dss_ctrl_2_scpu_c35_9p5t_ro_sel(data)                         (0x00000700&((data)<<8))
#define  SCPU_CORE_dss_ctrl_2_scpu_c35_9p5t_speed_en(data)                       (0x00000080&((data)<<7))
#define  SCPU_CORE_dss_ctrl_2_scpu_c35_9p5t_wire_sel(data)                       (0x00000040&((data)<<6))
#define  SCPU_CORE_dss_ctrl_2_get_scpu_c35_9p5t_data_in(data)                    ((0xFFFFF000&(data))>>12)
#define  SCPU_CORE_dss_ctrl_2_get_scpu_c35_9p5t_dss_rst_n(data)                  ((0x00000800&(data))>>11)
#define  SCPU_CORE_dss_ctrl_2_get_scpu_c35_9p5t_ro_sel(data)                     ((0x00000700&(data))>>8)
#define  SCPU_CORE_dss_ctrl_2_get_scpu_c35_9p5t_speed_en(data)                   ((0x00000080&(data))>>7)
#define  SCPU_CORE_dss_ctrl_2_get_scpu_c35_9p5t_wire_sel(data)                   ((0x00000040&(data))>>6)

#define  SCPU_CORE_dss_ctrl_3                                                    0x1805B410
#define  SCPU_CORE_dss_ctrl_3_reg_addr                                           "0xB805B410"
#define  SCPU_CORE_dss_ctrl_3_reg                                                0xB805B410
#define  SCPU_CORE_dss_ctrl_3_inst_addr                                          "0x0010"
#define  set_SCPU_CORE_dss_ctrl_3_reg(data)                                      (*((volatile unsigned int*)SCPU_CORE_dss_ctrl_3_reg)=data)
#define  get_SCPU_CORE_dss_ctrl_3_reg                                            (*((volatile unsigned int*)SCPU_CORE_dss_ctrl_3_reg))
#define  SCPU_CORE_dss_ctrl_3_scpu_c38_9p5t_data_in_shift                        (12)
#define  SCPU_CORE_dss_ctrl_3_scpu_c38_9p5t_dss_rst_n_shift                      (11)
#define  SCPU_CORE_dss_ctrl_3_scpu_c38_9p5t_ro_sel_shift                         (8)
#define  SCPU_CORE_dss_ctrl_3_scpu_c38_9p5t_speed_en_shift                       (7)
#define  SCPU_CORE_dss_ctrl_3_scpu_c38_9p5t_wire_sel_shift                       (6)
#define  SCPU_CORE_dss_ctrl_3_scpu_c38_9p5t_data_in_mask                         (0xFFFFF000)
#define  SCPU_CORE_dss_ctrl_3_scpu_c38_9p5t_dss_rst_n_mask                       (0x00000800)
#define  SCPU_CORE_dss_ctrl_3_scpu_c38_9p5t_ro_sel_mask                          (0x00000700)
#define  SCPU_CORE_dss_ctrl_3_scpu_c38_9p5t_speed_en_mask                        (0x00000080)
#define  SCPU_CORE_dss_ctrl_3_scpu_c38_9p5t_wire_sel_mask                        (0x00000040)
#define  SCPU_CORE_dss_ctrl_3_scpu_c38_9p5t_data_in(data)                        (0xFFFFF000&((data)<<12))
#define  SCPU_CORE_dss_ctrl_3_scpu_c38_9p5t_dss_rst_n(data)                      (0x00000800&((data)<<11))
#define  SCPU_CORE_dss_ctrl_3_scpu_c38_9p5t_ro_sel(data)                         (0x00000700&((data)<<8))
#define  SCPU_CORE_dss_ctrl_3_scpu_c38_9p5t_speed_en(data)                       (0x00000080&((data)<<7))
#define  SCPU_CORE_dss_ctrl_3_scpu_c38_9p5t_wire_sel(data)                       (0x00000040&((data)<<6))
#define  SCPU_CORE_dss_ctrl_3_get_scpu_c38_9p5t_data_in(data)                    ((0xFFFFF000&(data))>>12)
#define  SCPU_CORE_dss_ctrl_3_get_scpu_c38_9p5t_dss_rst_n(data)                  ((0x00000800&(data))>>11)
#define  SCPU_CORE_dss_ctrl_3_get_scpu_c38_9p5t_ro_sel(data)                     ((0x00000700&(data))>>8)
#define  SCPU_CORE_dss_ctrl_3_get_scpu_c38_9p5t_speed_en(data)                   ((0x00000080&(data))>>7)
#define  SCPU_CORE_dss_ctrl_3_get_scpu_c38_9p5t_wire_sel(data)                   ((0x00000040&(data))>>6)

#define  SCPU_CORE_dss_status_0                                                  0x1805B414
#define  SCPU_CORE_dss_status_0_reg_addr                                         "0xB805B414"
#define  SCPU_CORE_dss_status_0_reg                                              0xB805B414
#define  SCPU_CORE_dss_status_0_inst_addr                                        "0x0011"
#define  set_SCPU_CORE_dss_status_0_reg(data)                                    (*((volatile unsigned int*)SCPU_CORE_dss_status_0_reg)=data)
#define  get_SCPU_CORE_dss_status_0_reg                                          (*((volatile unsigned int*)SCPU_CORE_dss_status_0_reg))
#define  SCPU_CORE_dss_status_0_a53_ready_0_shift                                (31)
#define  SCPU_CORE_dss_status_0_a53_count_out_0_shift                            (11)
#define  SCPU_CORE_dss_status_0_a53_ready_0_mask                                 (0x80000000)
#define  SCPU_CORE_dss_status_0_a53_count_out_0_mask                             (0x7FFFF800)
#define  SCPU_CORE_dss_status_0_a53_ready_0(data)                                (0x80000000&((data)<<31))
#define  SCPU_CORE_dss_status_0_a53_count_out_0(data)                            (0x7FFFF800&((data)<<11))
#define  SCPU_CORE_dss_status_0_get_a53_ready_0(data)                            ((0x80000000&(data))>>31)
#define  SCPU_CORE_dss_status_0_get_a53_count_out_0(data)                        ((0x7FFFF800&(data))>>11)

#define  SCPU_CORE_dss_status_1                                                  0x1805B418
#define  SCPU_CORE_dss_status_1_reg_addr                                         "0xB805B418"
#define  SCPU_CORE_dss_status_1_reg                                              0xB805B418
#define  SCPU_CORE_dss_status_1_inst_addr                                        "0x0012"
#define  set_SCPU_CORE_dss_status_1_reg(data)                                    (*((volatile unsigned int*)SCPU_CORE_dss_status_1_reg)=data)
#define  get_SCPU_CORE_dss_status_1_reg                                          (*((volatile unsigned int*)SCPU_CORE_dss_status_1_reg))
#define  SCPU_CORE_dss_status_1_a53_ready_1_shift                                (31)
#define  SCPU_CORE_dss_status_1_a53_count_out_1_shift                            (11)
#define  SCPU_CORE_dss_status_1_a53_ready_1_mask                                 (0x80000000)
#define  SCPU_CORE_dss_status_1_a53_count_out_1_mask                             (0x7FFFF800)
#define  SCPU_CORE_dss_status_1_a53_ready_1(data)                                (0x80000000&((data)<<31))
#define  SCPU_CORE_dss_status_1_a53_count_out_1(data)                            (0x7FFFF800&((data)<<11))
#define  SCPU_CORE_dss_status_1_get_a53_ready_1(data)                            ((0x80000000&(data))>>31)
#define  SCPU_CORE_dss_status_1_get_a53_count_out_1(data)                        ((0x7FFFF800&(data))>>11)

#define  SCPU_CORE_dss_status_4                                                  0x1805B424
#define  SCPU_CORE_dss_status_4_reg_addr                                         "0xB805B424"
#define  SCPU_CORE_dss_status_4_reg                                              0xB805B424
#define  SCPU_CORE_dss_status_4_inst_addr                                        "0x0013"
#define  set_SCPU_CORE_dss_status_4_reg(data)                                    (*((volatile unsigned int*)SCPU_CORE_dss_status_4_reg)=data)
#define  get_SCPU_CORE_dss_status_4_reg                                          (*((volatile unsigned int*)SCPU_CORE_dss_status_4_reg))
#define  SCPU_CORE_dss_status_4_scpu_c31_9p5t_count_out_ro_shift                 (12)
#define  SCPU_CORE_dss_status_4_scpu_c31_9p5t_ready_ro_shift                     (11)
#define  SCPU_CORE_dss_status_4_scpu_c31_9p5t_wsort_go_ro_shift                  (10)
#define  SCPU_CORE_dss_status_4_scpu_c31_9p5t_count_out_ro_mask                  (0xFFFFF000)
#define  SCPU_CORE_dss_status_4_scpu_c31_9p5t_ready_ro_mask                      (0x00000800)
#define  SCPU_CORE_dss_status_4_scpu_c31_9p5t_wsort_go_ro_mask                   (0x00000400)
#define  SCPU_CORE_dss_status_4_scpu_c31_9p5t_count_out_ro(data)                 (0xFFFFF000&((data)<<12))
#define  SCPU_CORE_dss_status_4_scpu_c31_9p5t_ready_ro(data)                     (0x00000800&((data)<<11))
#define  SCPU_CORE_dss_status_4_scpu_c31_9p5t_wsort_go_ro(data)                  (0x00000400&((data)<<10))
#define  SCPU_CORE_dss_status_4_get_scpu_c31_9p5t_count_out_ro(data)             ((0xFFFFF000&(data))>>12)
#define  SCPU_CORE_dss_status_4_get_scpu_c31_9p5t_ready_ro(data)                 ((0x00000800&(data))>>11)
#define  SCPU_CORE_dss_status_4_get_scpu_c31_9p5t_wsort_go_ro(data)              ((0x00000400&(data))>>10)

#define  SCPU_CORE_dss_status_5                                                  0x1805B428
#define  SCPU_CORE_dss_status_5_reg_addr                                         "0xB805B428"
#define  SCPU_CORE_dss_status_5_reg                                              0xB805B428
#define  SCPU_CORE_dss_status_5_inst_addr                                        "0x0014"
#define  set_SCPU_CORE_dss_status_5_reg(data)                                    (*((volatile unsigned int*)SCPU_CORE_dss_status_5_reg)=data)
#define  get_SCPU_CORE_dss_status_5_reg                                          (*((volatile unsigned int*)SCPU_CORE_dss_status_5_reg))
#define  SCPU_CORE_dss_status_5_scpu_c31_9p5t_dbgo_ro_shift                      (16)
#define  SCPU_CORE_dss_status_5_scpu_c31_9p5t_dbgo_ro_mask                       (0xFFFF0000)
#define  SCPU_CORE_dss_status_5_scpu_c31_9p5t_dbgo_ro(data)                      (0xFFFF0000&((data)<<16))
#define  SCPU_CORE_dss_status_5_get_scpu_c31_9p5t_dbgo_ro(data)                  ((0xFFFF0000&(data))>>16)

#define  SCPU_CORE_dss_status_6                                                  0x1805B42C
#define  SCPU_CORE_dss_status_6_reg_addr                                         "0xB805B42C"
#define  SCPU_CORE_dss_status_6_reg                                              0xB805B42C
#define  SCPU_CORE_dss_status_6_inst_addr                                        "0x0015"
#define  set_SCPU_CORE_dss_status_6_reg(data)                                    (*((volatile unsigned int*)SCPU_CORE_dss_status_6_reg)=data)
#define  get_SCPU_CORE_dss_status_6_reg                                          (*((volatile unsigned int*)SCPU_CORE_dss_status_6_reg))
#define  SCPU_CORE_dss_status_6_scpu_c35_9p5t_count_out_ro_shift                 (12)
#define  SCPU_CORE_dss_status_6_scpu_c35_9p5t_ready_ro_shift                     (11)
#define  SCPU_CORE_dss_status_6_scpu_c35_9p5t_wsort_go_ro_shift                  (10)
#define  SCPU_CORE_dss_status_6_scpu_c35_9p5t_count_out_ro_mask                  (0xFFFFF000)
#define  SCPU_CORE_dss_status_6_scpu_c35_9p5t_ready_ro_mask                      (0x00000800)
#define  SCPU_CORE_dss_status_6_scpu_c35_9p5t_wsort_go_ro_mask                   (0x00000400)
#define  SCPU_CORE_dss_status_6_scpu_c35_9p5t_count_out_ro(data)                 (0xFFFFF000&((data)<<12))
#define  SCPU_CORE_dss_status_6_scpu_c35_9p5t_ready_ro(data)                     (0x00000800&((data)<<11))
#define  SCPU_CORE_dss_status_6_scpu_c35_9p5t_wsort_go_ro(data)                  (0x00000400&((data)<<10))
#define  SCPU_CORE_dss_status_6_get_scpu_c35_9p5t_count_out_ro(data)             ((0xFFFFF000&(data))>>12)
#define  SCPU_CORE_dss_status_6_get_scpu_c35_9p5t_ready_ro(data)                 ((0x00000800&(data))>>11)
#define  SCPU_CORE_dss_status_6_get_scpu_c35_9p5t_wsort_go_ro(data)              ((0x00000400&(data))>>10)

#define  SCPU_CORE_dss_status_7                                                  0x1805B430
#define  SCPU_CORE_dss_status_7_reg_addr                                         "0xB805B430"
#define  SCPU_CORE_dss_status_7_reg                                              0xB805B430
#define  SCPU_CORE_dss_status_7_inst_addr                                        "0x0016"
#define  set_SCPU_CORE_dss_status_7_reg(data)                                    (*((volatile unsigned int*)SCPU_CORE_dss_status_7_reg)=data)
#define  get_SCPU_CORE_dss_status_7_reg                                          (*((volatile unsigned int*)SCPU_CORE_dss_status_7_reg))
#define  SCPU_CORE_dss_status_7_scpu_c35_9p5t_dbgo_ro_shift                      (16)
#define  SCPU_CORE_dss_status_7_scpu_c35_9p5t_dbgo_ro_mask                       (0xFFFF0000)
#define  SCPU_CORE_dss_status_7_scpu_c35_9p5t_dbgo_ro(data)                      (0xFFFF0000&((data)<<16))
#define  SCPU_CORE_dss_status_7_get_scpu_c35_9p5t_dbgo_ro(data)                  ((0xFFFF0000&(data))>>16)

#define  SCPU_CORE_dss_status_8                                                  0x1805B434
#define  SCPU_CORE_dss_status_8_reg_addr                                         "0xB805B434"
#define  SCPU_CORE_dss_status_8_reg                                              0xB805B434
#define  SCPU_CORE_dss_status_8_inst_addr                                        "0x0017"
#define  set_SCPU_CORE_dss_status_8_reg(data)                                    (*((volatile unsigned int*)SCPU_CORE_dss_status_8_reg)=data)
#define  get_SCPU_CORE_dss_status_8_reg                                          (*((volatile unsigned int*)SCPU_CORE_dss_status_8_reg))
#define  SCPU_CORE_dss_status_8_scpu_c38_9p5t_count_out_ro_shift                 (12)
#define  SCPU_CORE_dss_status_8_scpu_c38_9p5t_ready_ro_shift                     (11)
#define  SCPU_CORE_dss_status_8_scpu_c38_9p5t_wsort_go_ro_shift                  (10)
#define  SCPU_CORE_dss_status_8_scpu_c38_9p5t_count_out_ro_mask                  (0xFFFFF000)
#define  SCPU_CORE_dss_status_8_scpu_c38_9p5t_ready_ro_mask                      (0x00000800)
#define  SCPU_CORE_dss_status_8_scpu_c38_9p5t_wsort_go_ro_mask                   (0x00000400)
#define  SCPU_CORE_dss_status_8_scpu_c38_9p5t_count_out_ro(data)                 (0xFFFFF000&((data)<<12))
#define  SCPU_CORE_dss_status_8_scpu_c38_9p5t_ready_ro(data)                     (0x00000800&((data)<<11))
#define  SCPU_CORE_dss_status_8_scpu_c38_9p5t_wsort_go_ro(data)                  (0x00000400&((data)<<10))
#define  SCPU_CORE_dss_status_8_get_scpu_c38_9p5t_count_out_ro(data)             ((0xFFFFF000&(data))>>12)
#define  SCPU_CORE_dss_status_8_get_scpu_c38_9p5t_ready_ro(data)                 ((0x00000800&(data))>>11)
#define  SCPU_CORE_dss_status_8_get_scpu_c38_9p5t_wsort_go_ro(data)              ((0x00000400&(data))>>10)

#define  SCPU_CORE_dss_status_9                                                  0x1805B438
#define  SCPU_CORE_dss_status_9_reg_addr                                         "0xB805B438"
#define  SCPU_CORE_dss_status_9_reg                                              0xB805B438
#define  SCPU_CORE_dss_status_9_inst_addr                                        "0x0018"
#define  set_SCPU_CORE_dss_status_9_reg(data)                                    (*((volatile unsigned int*)SCPU_CORE_dss_status_9_reg)=data)
#define  get_SCPU_CORE_dss_status_9_reg                                          (*((volatile unsigned int*)SCPU_CORE_dss_status_9_reg))
#define  SCPU_CORE_dss_status_9_scpu_c38_9p5t_dbgo_ro_shift                      (16)
#define  SCPU_CORE_dss_status_9_scpu_c38_9p5t_dbgo_ro_mask                       (0xFFFF0000)
#define  SCPU_CORE_dss_status_9_scpu_c38_9p5t_dbgo_ro(data)                      (0xFFFF0000&((data)<<16))
#define  SCPU_CORE_dss_status_9_get_scpu_c38_9p5t_dbgo_ro(data)                  ((0xFFFF0000&(data))>>16)

#define  SCPU_CORE_dss_ctrl_pllscpu                                              0x1805B4C0
#define  SCPU_CORE_dss_ctrl_pllscpu_reg_addr                                     "0xB805B4C0"
#define  SCPU_CORE_dss_ctrl_pllscpu_reg                                          0xB805B4C0
#define  SCPU_CORE_dss_ctrl_pllscpu_inst_addr                                    "0x0019"
#define  set_SCPU_CORE_dss_ctrl_pllscpu_reg(data)                                (*((volatile unsigned int*)SCPU_CORE_dss_ctrl_pllscpu_reg)=data)
#define  get_SCPU_CORE_dss_ctrl_pllscpu_reg                                      (*((volatile unsigned int*)SCPU_CORE_dss_ctrl_pllscpu_reg))
#define  SCPU_CORE_dss_ctrl_pllscpu_pllscpu_dss_data_in_shift                    (12)
#define  SCPU_CORE_dss_ctrl_pllscpu_pllscpu_dss_rst_n_shift                      (11)
#define  SCPU_CORE_dss_ctrl_pllscpu_pllscpu_dss_ro_sel_shift                     (8)
#define  SCPU_CORE_dss_ctrl_pllscpu_pllscpu_dss_speed_en_shift                   (7)
#define  SCPU_CORE_dss_ctrl_pllscpu_pllscpu_dss_wire_sel_shift                   (6)
#define  SCPU_CORE_dss_ctrl_pllscpu_pllscpu_dss_data_in_mask                     (0xFFFFF000)
#define  SCPU_CORE_dss_ctrl_pllscpu_pllscpu_dss_rst_n_mask                       (0x00000800)
#define  SCPU_CORE_dss_ctrl_pllscpu_pllscpu_dss_ro_sel_mask                      (0x00000700)
#define  SCPU_CORE_dss_ctrl_pllscpu_pllscpu_dss_speed_en_mask                    (0x00000080)
#define  SCPU_CORE_dss_ctrl_pllscpu_pllscpu_dss_wire_sel_mask                    (0x00000040)
#define  SCPU_CORE_dss_ctrl_pllscpu_pllscpu_dss_data_in(data)                    (0xFFFFF000&((data)<<12))
#define  SCPU_CORE_dss_ctrl_pllscpu_pllscpu_dss_rst_n(data)                      (0x00000800&((data)<<11))
#define  SCPU_CORE_dss_ctrl_pllscpu_pllscpu_dss_ro_sel(data)                     (0x00000700&((data)<<8))
#define  SCPU_CORE_dss_ctrl_pllscpu_pllscpu_dss_speed_en(data)                   (0x00000080&((data)<<7))
#define  SCPU_CORE_dss_ctrl_pllscpu_pllscpu_dss_wire_sel(data)                   (0x00000040&((data)<<6))
#define  SCPU_CORE_dss_ctrl_pllscpu_get_pllscpu_dss_data_in(data)                ((0xFFFFF000&(data))>>12)
#define  SCPU_CORE_dss_ctrl_pllscpu_get_pllscpu_dss_rst_n(data)                  ((0x00000800&(data))>>11)
#define  SCPU_CORE_dss_ctrl_pllscpu_get_pllscpu_dss_ro_sel(data)                 ((0x00000700&(data))>>8)
#define  SCPU_CORE_dss_ctrl_pllscpu_get_pllscpu_dss_speed_en(data)               ((0x00000080&(data))>>7)
#define  SCPU_CORE_dss_ctrl_pllscpu_get_pllscpu_dss_wire_sel(data)               ((0x00000040&(data))>>6)

#define  SCPU_CORE_dss_status_pllscpu_0                                          0x1805B4C4
#define  SCPU_CORE_dss_status_pllscpu_0_reg_addr                                 "0xB805B4C4"
#define  SCPU_CORE_dss_status_pllscpu_0_reg                                      0xB805B4C4
#define  SCPU_CORE_dss_status_pllscpu_0_inst_addr                                "0x001A"
#define  set_SCPU_CORE_dss_status_pllscpu_0_reg(data)                            (*((volatile unsigned int*)SCPU_CORE_dss_status_pllscpu_0_reg)=data)
#define  get_SCPU_CORE_dss_status_pllscpu_0_reg                                  (*((volatile unsigned int*)SCPU_CORE_dss_status_pllscpu_0_reg))
#define  SCPU_CORE_dss_status_pllscpu_0_pllscpu_dss_count_out_shift              (12)
#define  SCPU_CORE_dss_status_pllscpu_0_pllscpu_dss_ready_shift                  (11)
#define  SCPU_CORE_dss_status_pllscpu_0_pllscpu_dss_wsort_go_shift               (10)
#define  SCPU_CORE_dss_status_pllscpu_0_pllscpu_dss_count_out_mask               (0xFFFFF000)
#define  SCPU_CORE_dss_status_pllscpu_0_pllscpu_dss_ready_mask                   (0x00000800)
#define  SCPU_CORE_dss_status_pllscpu_0_pllscpu_dss_wsort_go_mask                (0x00000400)
#define  SCPU_CORE_dss_status_pllscpu_0_pllscpu_dss_count_out(data)              (0xFFFFF000&((data)<<12))
#define  SCPU_CORE_dss_status_pllscpu_0_pllscpu_dss_ready(data)                  (0x00000800&((data)<<11))
#define  SCPU_CORE_dss_status_pllscpu_0_pllscpu_dss_wsort_go(data)               (0x00000400&((data)<<10))
#define  SCPU_CORE_dss_status_pllscpu_0_get_pllscpu_dss_count_out(data)          ((0xFFFFF000&(data))>>12)
#define  SCPU_CORE_dss_status_pllscpu_0_get_pllscpu_dss_ready(data)              ((0x00000800&(data))>>11)
#define  SCPU_CORE_dss_status_pllscpu_0_get_pllscpu_dss_wsort_go(data)           ((0x00000400&(data))>>10)

#define  SCPU_CORE_dss_status_pllscpu_1                                          0x1805B4C8
#define  SCPU_CORE_dss_status_pllscpu_1_reg_addr                                 "0xB805B4C8"
#define  SCPU_CORE_dss_status_pllscpu_1_reg                                      0xB805B4C8
#define  SCPU_CORE_dss_status_pllscpu_1_inst_addr                                "0x001B"
#define  set_SCPU_CORE_dss_status_pllscpu_1_reg(data)                            (*((volatile unsigned int*)SCPU_CORE_dss_status_pllscpu_1_reg)=data)
#define  get_SCPU_CORE_dss_status_pllscpu_1_reg                                  (*((volatile unsigned int*)SCPU_CORE_dss_status_pllscpu_1_reg))
#define  SCPU_CORE_dss_status_pllscpu_1_pllscpu_dss_dbgo_shift                   (16)
#define  SCPU_CORE_dss_status_pllscpu_1_pllscpu_dss_dbgo_mask                    (0xFFFF0000)
#define  SCPU_CORE_dss_status_pllscpu_1_pllscpu_dss_dbgo(data)                   (0xFFFF0000&((data)<<16))
#define  SCPU_CORE_dss_status_pllscpu_1_get_pllscpu_dss_dbgo(data)               ((0xFFFF0000&(data))>>16)

#define  SCPU_CORE_sram_ctrl_0                                                   0x1805B43C
#define  SCPU_CORE_sram_ctrl_0_reg_addr                                          "0xB805B43C"
#define  SCPU_CORE_sram_ctrl_0_reg                                               0xB805B43C
#define  SCPU_CORE_sram_ctrl_0_inst_addr                                         "0x001C"
#define  set_SCPU_CORE_sram_ctrl_0_reg(data)                                     (*((volatile unsigned int*)SCPU_CORE_sram_ctrl_0_reg)=data)
#define  get_SCPU_CORE_sram_ctrl_0_reg                                           (*((volatile unsigned int*)SCPU_CORE_sram_ctrl_0_reg))
#define  SCPU_CORE_sram_ctrl_0_a53_rme_shift                                     (31)
#define  SCPU_CORE_sram_ctrl_0_a53_ds_l1_0_shift                                 (30)
#define  SCPU_CORE_sram_ctrl_0_a53_ds_l1_1_shift                                 (29)
#define  SCPU_CORE_sram_ctrl_0_a53_sd_l1_0_shift                                 (27)
#define  SCPU_CORE_sram_ctrl_0_a53_sd_l1_1_shift                                 (26)
#define  SCPU_CORE_sram_ctrl_0_a53_ds_l1_2_shift                                 (23)
#define  SCPU_CORE_sram_ctrl_0_a53_ds_l1_3_shift                                 (22)
#define  SCPU_CORE_sram_ctrl_0_a53_sd_l1_2_shift                                 (20)
#define  SCPU_CORE_sram_ctrl_0_a53_sd_l1_3_shift                                 (19)
#define  SCPU_CORE_sram_ctrl_0_a53_ls_off_shift                                  (0)
#define  SCPU_CORE_sram_ctrl_0_a53_rme_mask                                      (0x80000000)
#define  SCPU_CORE_sram_ctrl_0_a53_ds_l1_0_mask                                  (0x40000000)
#define  SCPU_CORE_sram_ctrl_0_a53_ds_l1_1_mask                                  (0x20000000)
#define  SCPU_CORE_sram_ctrl_0_a53_sd_l1_0_mask                                  (0x08000000)
#define  SCPU_CORE_sram_ctrl_0_a53_sd_l1_1_mask                                  (0x04000000)
#define  SCPU_CORE_sram_ctrl_0_a53_ds_l1_2_mask                                  (0x00800000)
#define  SCPU_CORE_sram_ctrl_0_a53_ds_l1_3_mask                                  (0x00400000)
#define  SCPU_CORE_sram_ctrl_0_a53_sd_l1_2_mask                                  (0x00100000)
#define  SCPU_CORE_sram_ctrl_0_a53_sd_l1_3_mask                                  (0x00080000)
#define  SCPU_CORE_sram_ctrl_0_a53_ls_off_mask                                   (0x00000001)
#define  SCPU_CORE_sram_ctrl_0_a53_rme(data)                                     (0x80000000&((data)<<31))
#define  SCPU_CORE_sram_ctrl_0_a53_ds_l1_0(data)                                 (0x40000000&((data)<<30))
#define  SCPU_CORE_sram_ctrl_0_a53_ds_l1_1(data)                                 (0x20000000&((data)<<29))
#define  SCPU_CORE_sram_ctrl_0_a53_sd_l1_0(data)                                 (0x08000000&((data)<<27))
#define  SCPU_CORE_sram_ctrl_0_a53_sd_l1_1(data)                                 (0x04000000&((data)<<26))
#define  SCPU_CORE_sram_ctrl_0_a53_ds_l1_2(data)                                 (0x00800000&((data)<<23))
#define  SCPU_CORE_sram_ctrl_0_a53_ds_l1_3(data)                                 (0x00400000&((data)<<22))
#define  SCPU_CORE_sram_ctrl_0_a53_sd_l1_2(data)                                 (0x00100000&((data)<<20))
#define  SCPU_CORE_sram_ctrl_0_a53_sd_l1_3(data)                                 (0x00080000&((data)<<19))
#define  SCPU_CORE_sram_ctrl_0_a53_ls_off(data)                                  (0x00000001&(data))
#define  SCPU_CORE_sram_ctrl_0_get_a53_rme(data)                                 ((0x80000000&(data))>>31)
#define  SCPU_CORE_sram_ctrl_0_get_a53_ds_l1_0(data)                             ((0x40000000&(data))>>30)
#define  SCPU_CORE_sram_ctrl_0_get_a53_ds_l1_1(data)                             ((0x20000000&(data))>>29)
#define  SCPU_CORE_sram_ctrl_0_get_a53_sd_l1_0(data)                             ((0x08000000&(data))>>27)
#define  SCPU_CORE_sram_ctrl_0_get_a53_sd_l1_1(data)                             ((0x04000000&(data))>>26)
#define  SCPU_CORE_sram_ctrl_0_get_a53_ds_l1_2(data)                             ((0x00800000&(data))>>23)
#define  SCPU_CORE_sram_ctrl_0_get_a53_ds_l1_3(data)                             ((0x00400000&(data))>>22)
#define  SCPU_CORE_sram_ctrl_0_get_a53_sd_l1_2(data)                             ((0x00100000&(data))>>20)
#define  SCPU_CORE_sram_ctrl_0_get_a53_sd_l1_3(data)                             ((0x00080000&(data))>>19)
#define  SCPU_CORE_sram_ctrl_0_get_a53_ls_off(data)                              (0x00000001&(data))

#define  SCPU_CORE_sram_ctrl_1                                                   0x1805B440
#define  SCPU_CORE_sram_ctrl_1_reg_addr                                          "0xB805B440"
#define  SCPU_CORE_sram_ctrl_1_reg                                               0xB805B440
#define  SCPU_CORE_sram_ctrl_1_inst_addr                                         "0x001D"
#define  set_SCPU_CORE_sram_ctrl_1_reg(data)                                     (*((volatile unsigned int*)SCPU_CORE_sram_ctrl_1_reg)=data)
#define  get_SCPU_CORE_sram_ctrl_1_reg                                           (*((volatile unsigned int*)SCPU_CORE_sram_ctrl_1_reg))
#define  SCPU_CORE_sram_ctrl_1_a53_rm_47_32_shift                                (0)
#define  SCPU_CORE_sram_ctrl_1_a53_rm_47_32_mask                                 (0x0000FFFF)
#define  SCPU_CORE_sram_ctrl_1_a53_rm_47_32(data)                                (0x0000FFFF&(data))
#define  SCPU_CORE_sram_ctrl_1_get_a53_rm_47_32(data)                            (0x0000FFFF&(data))

#define  SCPU_CORE_sram_ctrl_2                                                   0x1805B444
#define  SCPU_CORE_sram_ctrl_2_reg_addr                                          "0xB805B444"
#define  SCPU_CORE_sram_ctrl_2_reg                                               0xB805B444
#define  SCPU_CORE_sram_ctrl_2_inst_addr                                         "0x001E"
#define  set_SCPU_CORE_sram_ctrl_2_reg(data)                                     (*((volatile unsigned int*)SCPU_CORE_sram_ctrl_2_reg)=data)
#define  get_SCPU_CORE_sram_ctrl_2_reg                                           (*((volatile unsigned int*)SCPU_CORE_sram_ctrl_2_reg))
#define  SCPU_CORE_sram_ctrl_2_a53_rm_31_0_shift                                 (0)
#define  SCPU_CORE_sram_ctrl_2_a53_rm_31_0_mask                                  (0xFFFFFFFF)
#define  SCPU_CORE_sram_ctrl_2_a53_rm_31_0(data)                                 (0xFFFFFFFF&(data))
#define  SCPU_CORE_sram_ctrl_2_get_a53_rm_31_0(data)                             (0xFFFFFFFF&(data))

#define  SCPU_CORE_low_power_ctrl_0                                              0x1805B450
#define  SCPU_CORE_low_power_ctrl_0_reg_addr                                     "0xB805B450"
#define  SCPU_CORE_low_power_ctrl_0_reg                                          0xB805B450
#define  SCPU_CORE_low_power_ctrl_0_inst_addr                                    "0x001F"
#define  set_SCPU_CORE_low_power_ctrl_0_reg(data)                                (*((volatile unsigned int*)SCPU_CORE_low_power_ctrl_0_reg)=data)
#define  get_SCPU_CORE_low_power_ctrl_0_reg                                      (*((volatile unsigned int*)SCPU_CORE_low_power_ctrl_0_reg))
#define  SCPU_CORE_low_power_ctrl_0_a53_core_pwrctrl_in_shift                    (30)
#define  SCPU_CORE_low_power_ctrl_0_a53_core_clamp_en_shift                      (28)
#define  SCPU_CORE_low_power_ctrl_0_a53_core_pwrctrl_in_3_2_shift                (24)
#define  SCPU_CORE_low_power_ctrl_0_a53_core_clamp_en_3_2_shift                  (22)
#define  SCPU_CORE_low_power_ctrl_0_a53_core_pwrctrl_in_mask                     (0xC0000000)
#define  SCPU_CORE_low_power_ctrl_0_a53_core_clamp_en_mask                       (0x30000000)
#define  SCPU_CORE_low_power_ctrl_0_a53_core_pwrctrl_in_3_2_mask                 (0x03000000)
#define  SCPU_CORE_low_power_ctrl_0_a53_core_clamp_en_3_2_mask                   (0x00C00000)
#define  SCPU_CORE_low_power_ctrl_0_a53_core_pwrctrl_in(data)                    (0xC0000000&((data)<<30))
#define  SCPU_CORE_low_power_ctrl_0_a53_core_clamp_en(data)                      (0x30000000&((data)<<28))
#define  SCPU_CORE_low_power_ctrl_0_a53_core_pwrctrl_in_3_2(data)                (0x03000000&((data)<<24))
#define  SCPU_CORE_low_power_ctrl_0_a53_core_clamp_en_3_2(data)                  (0x00C00000&((data)<<22))
#define  SCPU_CORE_low_power_ctrl_0_get_a53_core_pwrctrl_in(data)                ((0xC0000000&(data))>>30)
#define  SCPU_CORE_low_power_ctrl_0_get_a53_core_clamp_en(data)                  ((0x30000000&(data))>>28)
#define  SCPU_CORE_low_power_ctrl_0_get_a53_core_pwrctrl_in_3_2(data)            ((0x03000000&(data))>>24)
#define  SCPU_CORE_low_power_ctrl_0_get_a53_core_clamp_en_3_2(data)              ((0x00C00000&(data))>>22)

#define  SCPU_CORE_low_power_ctrl_1                                              0x1805B454
#define  SCPU_CORE_low_power_ctrl_1_reg_addr                                     "0xB805B454"
#define  SCPU_CORE_low_power_ctrl_1_reg                                          0xB805B454
#define  SCPU_CORE_low_power_ctrl_1_inst_addr                                    "0x0020"
#define  set_SCPU_CORE_low_power_ctrl_1_reg(data)                                (*((volatile unsigned int*)SCPU_CORE_low_power_ctrl_1_reg)=data)
#define  get_SCPU_CORE_low_power_ctrl_1_reg                                      (*((volatile unsigned int*)SCPU_CORE_low_power_ctrl_1_reg))
#define  SCPU_CORE_low_power_ctrl_1_a53_power_mode_sel_shift                     (17)
#define  SCPU_CORE_low_power_ctrl_1_a53_power_delay_value_shift                  (8)
#define  SCPU_CORE_low_power_ctrl_1_a53_power_mode_sel_mask                      (0x00020000)
#define  SCPU_CORE_low_power_ctrl_1_a53_power_delay_value_mask                   (0x0000FF00)
#define  SCPU_CORE_low_power_ctrl_1_a53_power_mode_sel(data)                     (0x00020000&((data)<<17))
#define  SCPU_CORE_low_power_ctrl_1_a53_power_delay_value(data)                  (0x0000FF00&((data)<<8))
#define  SCPU_CORE_low_power_ctrl_1_get_a53_power_mode_sel(data)                 ((0x00020000&(data))>>17)
#define  SCPU_CORE_low_power_ctrl_1_get_a53_power_delay_value(data)              ((0x0000FF00&(data))>>8)

#define  SCPU_CORE_low_power_status_0                                            0x1805B458
#define  SCPU_CORE_low_power_status_0_reg_addr                                   "0xB805B458"
#define  SCPU_CORE_low_power_status_0_reg                                        0xB805B458
#define  SCPU_CORE_low_power_status_0_inst_addr                                  "0x0021"
#define  set_SCPU_CORE_low_power_status_0_reg(data)                              (*((volatile unsigned int*)SCPU_CORE_low_power_status_0_reg)=data)
#define  get_SCPU_CORE_low_power_status_0_reg                                    (*((volatile unsigned int*)SCPU_CORE_low_power_status_0_reg))
#define  SCPU_CORE_low_power_status_0_a53_core_pwrctrl_out_shift                 (30)
#define  SCPU_CORE_low_power_status_0_a53_core_pwrctrl_out_3_2_shift             (27)
#define  SCPU_CORE_low_power_status_0_a53_core_pwrctrl_out_mask                  (0xC0000000)
#define  SCPU_CORE_low_power_status_0_a53_core_pwrctrl_out_3_2_mask              (0x18000000)
#define  SCPU_CORE_low_power_status_0_a53_core_pwrctrl_out(data)                 (0xC0000000&((data)<<30))
#define  SCPU_CORE_low_power_status_0_a53_core_pwrctrl_out_3_2(data)             (0x18000000&((data)<<27))
#define  SCPU_CORE_low_power_status_0_get_a53_core_pwrctrl_out(data)             ((0xC0000000&(data))>>30)
#define  SCPU_CORE_low_power_status_0_get_a53_core_pwrctrl_out_3_2(data)         ((0x18000000&(data))>>27)

#define  SCPU_CORE_mbisr_ctrl_0                                                  0x1805B45C
#define  SCPU_CORE_mbisr_ctrl_0_reg_addr                                         "0xB805B45C"
#define  SCPU_CORE_mbisr_ctrl_0_reg                                              0xB805B45C
#define  SCPU_CORE_mbisr_ctrl_0_inst_addr                                        "0x0022"
#define  set_SCPU_CORE_mbisr_ctrl_0_reg(data)                                    (*((volatile unsigned int*)SCPU_CORE_mbisr_ctrl_0_reg)=data)
#define  get_SCPU_CORE_mbisr_ctrl_0_reg                                          (*((volatile unsigned int*)SCPU_CORE_mbisr_ctrl_0_reg))
#define  SCPU_CORE_mbisr_ctrl_0_a53_drf_bisr_mode_shift                          (30)
#define  SCPU_CORE_mbisr_ctrl_0_a53_drf_bisr_test_resume_shift                   (29)
#define  SCPU_CORE_mbisr_ctrl_0_a53_second_run_en_shift                          (28)
#define  SCPU_CORE_mbisr_ctrl_0_a53_drf_bisr_mode_mask                           (0x40000000)
#define  SCPU_CORE_mbisr_ctrl_0_a53_drf_bisr_test_resume_mask                    (0x20000000)
#define  SCPU_CORE_mbisr_ctrl_0_a53_second_run_en_mask                           (0x10000000)
#define  SCPU_CORE_mbisr_ctrl_0_a53_drf_bisr_mode(data)                          (0x40000000&((data)<<30))
#define  SCPU_CORE_mbisr_ctrl_0_a53_drf_bisr_test_resume(data)                   (0x20000000&((data)<<29))
#define  SCPU_CORE_mbisr_ctrl_0_a53_second_run_en(data)                          (0x10000000&((data)<<28))
#define  SCPU_CORE_mbisr_ctrl_0_get_a53_drf_bisr_mode(data)                      ((0x40000000&(data))>>30)
#define  SCPU_CORE_mbisr_ctrl_0_get_a53_drf_bisr_test_resume(data)               ((0x20000000&(data))>>29)
#define  SCPU_CORE_mbisr_ctrl_0_get_a53_second_run_en(data)                      ((0x10000000&(data))>>28)

#define  SCPU_CORE_mbisr_status_0                                                0x1805B460
#define  SCPU_CORE_mbisr_status_0_reg_addr                                       "0xB805B460"
#define  SCPU_CORE_mbisr_status_0_reg                                            0xB805B460
#define  SCPU_CORE_mbisr_status_0_inst_addr                                      "0x0023"
#define  set_SCPU_CORE_mbisr_status_0_reg(data)                                  (*((volatile unsigned int*)SCPU_CORE_mbisr_status_0_reg)=data)
#define  get_SCPU_CORE_mbisr_status_0_reg                                        (*((volatile unsigned int*)SCPU_CORE_mbisr_status_0_reg))
#define  SCPU_CORE_mbisr_status_0_a53_drf_bisr_done_shift                        (31)
#define  SCPU_CORE_mbisr_status_0_a53_drf_bisr_fail_shift                        (23)
#define  SCPU_CORE_mbisr_status_0_a53_drf_bisr_start_pause_shift                 (22)
#define  SCPU_CORE_mbisr_status_0_a53_bisr_fail_shift                            (14)
#define  SCPU_CORE_mbisr_status_0_a53_drf_bisr_done_mask                         (0x80000000)
#define  SCPU_CORE_mbisr_status_0_a53_drf_bisr_fail_mask                         (0x7F800000)
#define  SCPU_CORE_mbisr_status_0_a53_drf_bisr_start_pause_mask                  (0x00400000)
#define  SCPU_CORE_mbisr_status_0_a53_bisr_fail_mask                             (0x003FC000)
#define  SCPU_CORE_mbisr_status_0_a53_drf_bisr_done(data)                        (0x80000000&((data)<<31))
#define  SCPU_CORE_mbisr_status_0_a53_drf_bisr_fail(data)                        (0x7F800000&((data)<<23))
#define  SCPU_CORE_mbisr_status_0_a53_drf_bisr_start_pause(data)                 (0x00400000&((data)<<22))
#define  SCPU_CORE_mbisr_status_0_a53_bisr_fail(data)                            (0x003FC000&((data)<<14))
#define  SCPU_CORE_mbisr_status_0_get_a53_drf_bisr_done(data)                    ((0x80000000&(data))>>31)
#define  SCPU_CORE_mbisr_status_0_get_a53_drf_bisr_fail(data)                    ((0x7F800000&(data))>>23)
#define  SCPU_CORE_mbisr_status_0_get_a53_drf_bisr_start_pause(data)             ((0x00400000&(data))>>22)
#define  SCPU_CORE_mbisr_status_0_get_a53_bisr_fail(data)                        ((0x003FC000&(data))>>14)

#define  SCPU_CORE_mbisr_status_1                                                0x1805B464
#define  SCPU_CORE_mbisr_status_1_reg_addr                                       "0xB805B464"
#define  SCPU_CORE_mbisr_status_1_reg                                            0xB805B464
#define  SCPU_CORE_mbisr_status_1_inst_addr                                      "0x0024"
#define  set_SCPU_CORE_mbisr_status_1_reg(data)                                  (*((volatile unsigned int*)SCPU_CORE_mbisr_status_1_reg)=data)
#define  get_SCPU_CORE_mbisr_status_1_reg                                        (*((volatile unsigned int*)SCPU_CORE_mbisr_status_1_reg))
#define  SCPU_CORE_mbisr_status_1_a53_bisr_repaired_shift                        (0)
#define  SCPU_CORE_mbisr_status_1_a53_bisr_repaired_mask                         (0x00000001)
#define  SCPU_CORE_mbisr_status_1_a53_bisr_repaired(data)                        (0x00000001&(data))
#define  SCPU_CORE_mbisr_status_1_get_a53_bisr_repaired(data)                    (0x00000001&(data))

#define  SCPU_CORE_mbisr_status_2                                                0x1805B468
#define  SCPU_CORE_mbisr_status_2_reg_addr                                       "0xB805B468"
#define  SCPU_CORE_mbisr_status_2_reg                                            0xB805B468
#define  SCPU_CORE_mbisr_status_2_inst_addr                                      "0x0025"
#define  set_SCPU_CORE_mbisr_status_2_reg(data)                                  (*((volatile unsigned int*)SCPU_CORE_mbisr_status_2_reg)=data)
#define  get_SCPU_CORE_mbisr_status_2_reg                                        (*((volatile unsigned int*)SCPU_CORE_mbisr_status_2_reg))
#define  SCPU_CORE_mbisr_status_2_a53_bisr_out_55_32_shift                       (0)
#define  SCPU_CORE_mbisr_status_2_a53_bisr_out_55_32_mask                        (0x00FFFFFF)
#define  SCPU_CORE_mbisr_status_2_a53_bisr_out_55_32(data)                       (0x00FFFFFF&(data))
#define  SCPU_CORE_mbisr_status_2_get_a53_bisr_out_55_32(data)                   (0x00FFFFFF&(data))

#define  SCPU_CORE_mbisr_status_3                                                0x1805B46C
#define  SCPU_CORE_mbisr_status_3_reg_addr                                       "0xB805B46C"
#define  SCPU_CORE_mbisr_status_3_reg                                            0xB805B46C
#define  SCPU_CORE_mbisr_status_3_inst_addr                                      "0x0026"
#define  set_SCPU_CORE_mbisr_status_3_reg(data)                                  (*((volatile unsigned int*)SCPU_CORE_mbisr_status_3_reg)=data)
#define  get_SCPU_CORE_mbisr_status_3_reg                                        (*((volatile unsigned int*)SCPU_CORE_mbisr_status_3_reg))
#define  SCPU_CORE_mbisr_status_3_a53_bisr_out_31_0_shift                        (0)
#define  SCPU_CORE_mbisr_status_3_a53_bisr_out_31_0_mask                         (0xFFFFFFFF)
#define  SCPU_CORE_mbisr_status_3_a53_bisr_out_31_0(data)                        (0xFFFFFFFF&(data))
#define  SCPU_CORE_mbisr_status_3_get_a53_bisr_out_31_0(data)                    (0xFFFFFFFF&(data))

#define  SCPU_CORE_coordinator_ctrl_0                                            0x1805B480
#define  SCPU_CORE_coordinator_ctrl_0_reg_addr                                   "0xB805B480"
#define  SCPU_CORE_coordinator_ctrl_0_reg                                        0xB805B480
#define  SCPU_CORE_coordinator_ctrl_0_inst_addr                                  "0x0027"
#define  set_SCPU_CORE_coordinator_ctrl_0_reg(data)                              (*((volatile unsigned int*)SCPU_CORE_coordinator_ctrl_0_reg)=data)
#define  get_SCPU_CORE_coordinator_ctrl_0_reg                                    (*((volatile unsigned int*)SCPU_CORE_coordinator_ctrl_0_reg))
#define  SCPU_CORE_coordinator_ctrl_0_a53_share_bus_en_shift                     (30)
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_rstn_shift                        (29)
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_mode0_all_shift                   (28)
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_mode0_ddata_shift                 (27)
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_mode0_dtag_shift                  (26)
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_mode0_ddirty_shift                (25)
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_mode0_idata_shift                 (24)
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_mode0_itag_shift                  (23)
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_mode0_btac0_shift                 (22)
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_mode0_btac1_shift                 (21)
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_mode0_tlb_shift                   (20)
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_mode0_scu_shift                   (19)
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_mode0_l2_tag_shift                (18)
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_mode0_l2_victim_shift             (17)
#define  SCPU_CORE_coordinator_ctrl_0_a53_drf_bist_mode0_shift                   (16)
#define  SCPU_CORE_coordinator_ctrl_0_a53_drf_test_resume0_shift                 (15)
#define  SCPU_CORE_coordinator_ctrl_0_mbist0_all_mode_shift                      (14)
#define  SCPU_CORE_coordinator_ctrl_0_mbist1_all_mode_shift                      (13)
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_mode1_l2_data_shift               (12)
#define  SCPU_CORE_coordinator_ctrl_0_a53_diag_mode1_l2_data_shift               (11)
#define  SCPU_CORE_coordinator_ctrl_0_a53_diag_mode1_mbistarray1_shift           (9)
#define  SCPU_CORE_coordinator_ctrl_0_a53_share_bus_en_mask                      (0x40000000)
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_rstn_mask                         (0x20000000)
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_mode0_all_mask                    (0x10000000)
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_mode0_ddata_mask                  (0x08000000)
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_mode0_dtag_mask                   (0x04000000)
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_mode0_ddirty_mask                 (0x02000000)
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_mode0_idata_mask                  (0x01000000)
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_mode0_itag_mask                   (0x00800000)
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_mode0_btac0_mask                  (0x00400000)
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_mode0_btac1_mask                  (0x00200000)
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_mode0_tlb_mask                    (0x00100000)
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_mode0_scu_mask                    (0x00080000)
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_mode0_l2_tag_mask                 (0x00040000)
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_mode0_l2_victim_mask              (0x00020000)
#define  SCPU_CORE_coordinator_ctrl_0_a53_drf_bist_mode0_mask                    (0x00010000)
#define  SCPU_CORE_coordinator_ctrl_0_a53_drf_test_resume0_mask                  (0x00008000)
#define  SCPU_CORE_coordinator_ctrl_0_mbist0_all_mode_mask                       (0x00004000)
#define  SCPU_CORE_coordinator_ctrl_0_mbist1_all_mode_mask                       (0x00002000)
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_mode1_l2_data_mask                (0x00001000)
#define  SCPU_CORE_coordinator_ctrl_0_a53_diag_mode1_l2_data_mask                (0x00000800)
#define  SCPU_CORE_coordinator_ctrl_0_a53_diag_mode1_mbistarray1_mask            (0x00000600)
#define  SCPU_CORE_coordinator_ctrl_0_a53_share_bus_en(data)                     (0x40000000&((data)<<30))
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_rstn(data)                        (0x20000000&((data)<<29))
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_mode0_all(data)                   (0x10000000&((data)<<28))
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_mode0_ddata(data)                 (0x08000000&((data)<<27))
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_mode0_dtag(data)                  (0x04000000&((data)<<26))
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_mode0_ddirty(data)                (0x02000000&((data)<<25))
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_mode0_idata(data)                 (0x01000000&((data)<<24))
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_mode0_itag(data)                  (0x00800000&((data)<<23))
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_mode0_btac0(data)                 (0x00400000&((data)<<22))
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_mode0_btac1(data)                 (0x00200000&((data)<<21))
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_mode0_tlb(data)                   (0x00100000&((data)<<20))
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_mode0_scu(data)                   (0x00080000&((data)<<19))
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_mode0_l2_tag(data)                (0x00040000&((data)<<18))
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_mode0_l2_victim(data)             (0x00020000&((data)<<17))
#define  SCPU_CORE_coordinator_ctrl_0_a53_drf_bist_mode0(data)                   (0x00010000&((data)<<16))
#define  SCPU_CORE_coordinator_ctrl_0_a53_drf_test_resume0(data)                 (0x00008000&((data)<<15))
#define  SCPU_CORE_coordinator_ctrl_0_mbist0_all_mode(data)                      (0x00004000&((data)<<14))
#define  SCPU_CORE_coordinator_ctrl_0_mbist1_all_mode(data)                      (0x00002000&((data)<<13))
#define  SCPU_CORE_coordinator_ctrl_0_a53_bist_mode1_l2_data(data)               (0x00001000&((data)<<12))
#define  SCPU_CORE_coordinator_ctrl_0_a53_diag_mode1_l2_data(data)               (0x00000800&((data)<<11))
#define  SCPU_CORE_coordinator_ctrl_0_a53_diag_mode1_mbistarray1(data)           (0x00000600&((data)<<9))
#define  SCPU_CORE_coordinator_ctrl_0_get_a53_share_bus_en(data)                 ((0x40000000&(data))>>30)
#define  SCPU_CORE_coordinator_ctrl_0_get_a53_bist_rstn(data)                    ((0x20000000&(data))>>29)
#define  SCPU_CORE_coordinator_ctrl_0_get_a53_bist_mode0_all(data)               ((0x10000000&(data))>>28)
#define  SCPU_CORE_coordinator_ctrl_0_get_a53_bist_mode0_ddata(data)             ((0x08000000&(data))>>27)
#define  SCPU_CORE_coordinator_ctrl_0_get_a53_bist_mode0_dtag(data)              ((0x04000000&(data))>>26)
#define  SCPU_CORE_coordinator_ctrl_0_get_a53_bist_mode0_ddirty(data)            ((0x02000000&(data))>>25)
#define  SCPU_CORE_coordinator_ctrl_0_get_a53_bist_mode0_idata(data)             ((0x01000000&(data))>>24)
#define  SCPU_CORE_coordinator_ctrl_0_get_a53_bist_mode0_itag(data)              ((0x00800000&(data))>>23)
#define  SCPU_CORE_coordinator_ctrl_0_get_a53_bist_mode0_btac0(data)             ((0x00400000&(data))>>22)
#define  SCPU_CORE_coordinator_ctrl_0_get_a53_bist_mode0_btac1(data)             ((0x00200000&(data))>>21)
#define  SCPU_CORE_coordinator_ctrl_0_get_a53_bist_mode0_tlb(data)               ((0x00100000&(data))>>20)
#define  SCPU_CORE_coordinator_ctrl_0_get_a53_bist_mode0_scu(data)               ((0x00080000&(data))>>19)
#define  SCPU_CORE_coordinator_ctrl_0_get_a53_bist_mode0_l2_tag(data)            ((0x00040000&(data))>>18)
#define  SCPU_CORE_coordinator_ctrl_0_get_a53_bist_mode0_l2_victim(data)         ((0x00020000&(data))>>17)
#define  SCPU_CORE_coordinator_ctrl_0_get_a53_drf_bist_mode0(data)               ((0x00010000&(data))>>16)
#define  SCPU_CORE_coordinator_ctrl_0_get_a53_drf_test_resume0(data)             ((0x00008000&(data))>>15)
#define  SCPU_CORE_coordinator_ctrl_0_get_mbist0_all_mode(data)                  ((0x00004000&(data))>>14)
#define  SCPU_CORE_coordinator_ctrl_0_get_mbist1_all_mode(data)                  ((0x00002000&(data))>>13)
#define  SCPU_CORE_coordinator_ctrl_0_get_a53_bist_mode1_l2_data(data)           ((0x00001000&(data))>>12)
#define  SCPU_CORE_coordinator_ctrl_0_get_a53_diag_mode1_l2_data(data)           ((0x00000800&(data))>>11)
#define  SCPU_CORE_coordinator_ctrl_0_get_a53_diag_mode1_mbistarray1(data)       ((0x00000600&(data))>>9)

#define  SCPU_CORE_coordinator_status_0                                          0x1805B488
#define  SCPU_CORE_coordinator_status_0_reg_addr                                 "0xB805B488"
#define  SCPU_CORE_coordinator_status_0_reg                                      0xB805B488
#define  SCPU_CORE_coordinator_status_0_inst_addr                                "0x0028"
#define  set_SCPU_CORE_coordinator_status_0_reg(data)                            (*((volatile unsigned int*)SCPU_CORE_coordinator_status_0_reg)=data)
#define  get_SCPU_CORE_coordinator_status_0_reg                                  (*((volatile unsigned int*)SCPU_CORE_coordinator_status_0_reg))
#define  SCPU_CORE_coordinator_status_0_a53_bist_done0_ddata_shift               (31)
#define  SCPU_CORE_coordinator_status_0_a53_bist_done0_dtag_shift                (30)
#define  SCPU_CORE_coordinator_status_0_a53_bist_done0_ddirty_shift              (29)
#define  SCPU_CORE_coordinator_status_0_a53_bist_done0_idata_shift               (28)
#define  SCPU_CORE_coordinator_status_0_a53_bist_done0_itag_shift                (27)
#define  SCPU_CORE_coordinator_status_0_a53_bist_done0_btac0_shift               (26)
#define  SCPU_CORE_coordinator_status_0_a53_bist_done0_btac1_shift               (25)
#define  SCPU_CORE_coordinator_status_0_a53_bist_done0_tlb_shift                 (24)
#define  SCPU_CORE_coordinator_status_0_a53_bist_done0_scu_shift                 (23)
#define  SCPU_CORE_coordinator_status_0_a53_bist_done0_l2_tag_shift              (22)
#define  SCPU_CORE_coordinator_status_0_a53_bist_done0_l2_victim_shift           (21)
#define  SCPU_CORE_coordinator_status_0_a53_cpu0_bist_fail0_ddata_shift          (13)
#define  SCPU_CORE_coordinator_status_0_a53_cpu0_bist_fail0_dtag_shift           (9)
#define  SCPU_CORE_coordinator_status_0_a53_cpu0_bist_fail0_ddirty_shift         (8)
#define  SCPU_CORE_coordinator_status_0_a53_cpu0_bist_fail0_idata_shift          (6)
#define  SCPU_CORE_coordinator_status_0_a53_cpu0_bist_fail0_itag_shift           (4)
#define  SCPU_CORE_coordinator_status_0_a53_cpu0_bist_fail0_btac0_shift          (3)
#define  SCPU_CORE_coordinator_status_0_a53_cpu0_bist_fail0_btac1_shift          (2)
#define  SCPU_CORE_coordinator_status_0_a53_bist_done1_l2_data_shift             (1)
#define  SCPU_CORE_coordinator_status_0_a53_bist_done0_ddata_mask                (0x80000000)
#define  SCPU_CORE_coordinator_status_0_a53_bist_done0_dtag_mask                 (0x40000000)
#define  SCPU_CORE_coordinator_status_0_a53_bist_done0_ddirty_mask               (0x20000000)
#define  SCPU_CORE_coordinator_status_0_a53_bist_done0_idata_mask                (0x10000000)
#define  SCPU_CORE_coordinator_status_0_a53_bist_done0_itag_mask                 (0x08000000)
#define  SCPU_CORE_coordinator_status_0_a53_bist_done0_btac0_mask                (0x04000000)
#define  SCPU_CORE_coordinator_status_0_a53_bist_done0_btac1_mask                (0x02000000)
#define  SCPU_CORE_coordinator_status_0_a53_bist_done0_tlb_mask                  (0x01000000)
#define  SCPU_CORE_coordinator_status_0_a53_bist_done0_scu_mask                  (0x00800000)
#define  SCPU_CORE_coordinator_status_0_a53_bist_done0_l2_tag_mask               (0x00400000)
#define  SCPU_CORE_coordinator_status_0_a53_bist_done0_l2_victim_mask            (0x00200000)
#define  SCPU_CORE_coordinator_status_0_a53_cpu0_bist_fail0_ddata_mask           (0x001FE000)
#define  SCPU_CORE_coordinator_status_0_a53_cpu0_bist_fail0_dtag_mask            (0x00001E00)
#define  SCPU_CORE_coordinator_status_0_a53_cpu0_bist_fail0_ddirty_mask          (0x00000100)
#define  SCPU_CORE_coordinator_status_0_a53_cpu0_bist_fail0_idata_mask           (0x000000C0)
#define  SCPU_CORE_coordinator_status_0_a53_cpu0_bist_fail0_itag_mask            (0x00000030)
#define  SCPU_CORE_coordinator_status_0_a53_cpu0_bist_fail0_btac0_mask           (0x00000008)
#define  SCPU_CORE_coordinator_status_0_a53_cpu0_bist_fail0_btac1_mask           (0x00000004)
#define  SCPU_CORE_coordinator_status_0_a53_bist_done1_l2_data_mask              (0x00000002)
#define  SCPU_CORE_coordinator_status_0_a53_bist_done0_ddata(data)               (0x80000000&((data)<<31))
#define  SCPU_CORE_coordinator_status_0_a53_bist_done0_dtag(data)                (0x40000000&((data)<<30))
#define  SCPU_CORE_coordinator_status_0_a53_bist_done0_ddirty(data)              (0x20000000&((data)<<29))
#define  SCPU_CORE_coordinator_status_0_a53_bist_done0_idata(data)               (0x10000000&((data)<<28))
#define  SCPU_CORE_coordinator_status_0_a53_bist_done0_itag(data)                (0x08000000&((data)<<27))
#define  SCPU_CORE_coordinator_status_0_a53_bist_done0_btac0(data)               (0x04000000&((data)<<26))
#define  SCPU_CORE_coordinator_status_0_a53_bist_done0_btac1(data)               (0x02000000&((data)<<25))
#define  SCPU_CORE_coordinator_status_0_a53_bist_done0_tlb(data)                 (0x01000000&((data)<<24))
#define  SCPU_CORE_coordinator_status_0_a53_bist_done0_scu(data)                 (0x00800000&((data)<<23))
#define  SCPU_CORE_coordinator_status_0_a53_bist_done0_l2_tag(data)              (0x00400000&((data)<<22))
#define  SCPU_CORE_coordinator_status_0_a53_bist_done0_l2_victim(data)           (0x00200000&((data)<<21))
#define  SCPU_CORE_coordinator_status_0_a53_cpu0_bist_fail0_ddata(data)          (0x001FE000&((data)<<13))
#define  SCPU_CORE_coordinator_status_0_a53_cpu0_bist_fail0_dtag(data)           (0x00001E00&((data)<<9))
#define  SCPU_CORE_coordinator_status_0_a53_cpu0_bist_fail0_ddirty(data)         (0x00000100&((data)<<8))
#define  SCPU_CORE_coordinator_status_0_a53_cpu0_bist_fail0_idata(data)          (0x000000C0&((data)<<6))
#define  SCPU_CORE_coordinator_status_0_a53_cpu0_bist_fail0_itag(data)           (0x00000030&((data)<<4))
#define  SCPU_CORE_coordinator_status_0_a53_cpu0_bist_fail0_btac0(data)          (0x00000008&((data)<<3))
#define  SCPU_CORE_coordinator_status_0_a53_cpu0_bist_fail0_btac1(data)          (0x00000004&((data)<<2))
#define  SCPU_CORE_coordinator_status_0_a53_bist_done1_l2_data(data)             (0x00000002&((data)<<1))
#define  SCPU_CORE_coordinator_status_0_get_a53_bist_done0_ddata(data)           ((0x80000000&(data))>>31)
#define  SCPU_CORE_coordinator_status_0_get_a53_bist_done0_dtag(data)            ((0x40000000&(data))>>30)
#define  SCPU_CORE_coordinator_status_0_get_a53_bist_done0_ddirty(data)          ((0x20000000&(data))>>29)
#define  SCPU_CORE_coordinator_status_0_get_a53_bist_done0_idata(data)           ((0x10000000&(data))>>28)
#define  SCPU_CORE_coordinator_status_0_get_a53_bist_done0_itag(data)            ((0x08000000&(data))>>27)
#define  SCPU_CORE_coordinator_status_0_get_a53_bist_done0_btac0(data)           ((0x04000000&(data))>>26)
#define  SCPU_CORE_coordinator_status_0_get_a53_bist_done0_btac1(data)           ((0x02000000&(data))>>25)
#define  SCPU_CORE_coordinator_status_0_get_a53_bist_done0_tlb(data)             ((0x01000000&(data))>>24)
#define  SCPU_CORE_coordinator_status_0_get_a53_bist_done0_scu(data)             ((0x00800000&(data))>>23)
#define  SCPU_CORE_coordinator_status_0_get_a53_bist_done0_l2_tag(data)          ((0x00400000&(data))>>22)
#define  SCPU_CORE_coordinator_status_0_get_a53_bist_done0_l2_victim(data)       ((0x00200000&(data))>>21)
#define  SCPU_CORE_coordinator_status_0_get_a53_cpu0_bist_fail0_ddata(data)      ((0x001FE000&(data))>>13)
#define  SCPU_CORE_coordinator_status_0_get_a53_cpu0_bist_fail0_dtag(data)       ((0x00001E00&(data))>>9)
#define  SCPU_CORE_coordinator_status_0_get_a53_cpu0_bist_fail0_ddirty(data)     ((0x00000100&(data))>>8)
#define  SCPU_CORE_coordinator_status_0_get_a53_cpu0_bist_fail0_idata(data)      ((0x000000C0&(data))>>6)
#define  SCPU_CORE_coordinator_status_0_get_a53_cpu0_bist_fail0_itag(data)       ((0x00000030&(data))>>4)
#define  SCPU_CORE_coordinator_status_0_get_a53_cpu0_bist_fail0_btac0(data)      ((0x00000008&(data))>>3)
#define  SCPU_CORE_coordinator_status_0_get_a53_cpu0_bist_fail0_btac1(data)      ((0x00000004&(data))>>2)
#define  SCPU_CORE_coordinator_status_0_get_a53_bist_done1_l2_data(data)         ((0x00000002&(data))>>1)

#define  SCPU_CORE_coordinator_status_1                                          0x1805B48C
#define  SCPU_CORE_coordinator_status_1_reg_addr                                 "0xB805B48C"
#define  SCPU_CORE_coordinator_status_1_reg                                      0xB805B48C
#define  SCPU_CORE_coordinator_status_1_inst_addr                                "0x0029"
#define  set_SCPU_CORE_coordinator_status_1_reg(data)                            (*((volatile unsigned int*)SCPU_CORE_coordinator_status_1_reg)=data)
#define  get_SCPU_CORE_coordinator_status_1_reg                                  (*((volatile unsigned int*)SCPU_CORE_coordinator_status_1_reg))
#define  SCPU_CORE_coordinator_status_1_a53_cpu0_bist_fail0_tlb_shift            (28)
#define  SCPU_CORE_coordinator_status_1_a53_cpu0_bist_fail0_scu_shift            (24)
#define  SCPU_CORE_coordinator_status_1_a53_bist_fail0_l2_tag_shift              (8)
#define  SCPU_CORE_coordinator_status_1_a53_bist_fail0_l2_victim_shift           (7)
#define  SCPU_CORE_coordinator_status_1_a53_drf_start_pause0_shift               (6)
#define  SCPU_CORE_coordinator_status_1_a53_drf_bist_done0_shift                 (5)
#define  SCPU_CORE_coordinator_status_1_a53_bist_fail1_l2_data_shift             (0)
#define  SCPU_CORE_coordinator_status_1_a53_cpu0_bist_fail0_tlb_mask             (0xF0000000)
#define  SCPU_CORE_coordinator_status_1_a53_cpu0_bist_fail0_scu_mask             (0x0F000000)
#define  SCPU_CORE_coordinator_status_1_a53_bist_fail0_l2_tag_mask               (0x00FFFF00)
#define  SCPU_CORE_coordinator_status_1_a53_bist_fail0_l2_victim_mask            (0x00000080)
#define  SCPU_CORE_coordinator_status_1_a53_drf_start_pause0_mask                (0x00000040)
#define  SCPU_CORE_coordinator_status_1_a53_drf_bist_done0_mask                  (0x00000020)
#define  SCPU_CORE_coordinator_status_1_a53_bist_fail1_l2_data_mask              (0x0000000F)
#define  SCPU_CORE_coordinator_status_1_a53_cpu0_bist_fail0_tlb(data)            (0xF0000000&((data)<<28))
#define  SCPU_CORE_coordinator_status_1_a53_cpu0_bist_fail0_scu(data)            (0x0F000000&((data)<<24))
#define  SCPU_CORE_coordinator_status_1_a53_bist_fail0_l2_tag(data)              (0x00FFFF00&((data)<<8))
#define  SCPU_CORE_coordinator_status_1_a53_bist_fail0_l2_victim(data)           (0x00000080&((data)<<7))
#define  SCPU_CORE_coordinator_status_1_a53_drf_start_pause0(data)               (0x00000040&((data)<<6))
#define  SCPU_CORE_coordinator_status_1_a53_drf_bist_done0(data)                 (0x00000020&((data)<<5))
#define  SCPU_CORE_coordinator_status_1_a53_bist_fail1_l2_data(data)             (0x0000000F&(data))
#define  SCPU_CORE_coordinator_status_1_get_a53_cpu0_bist_fail0_tlb(data)        ((0xF0000000&(data))>>28)
#define  SCPU_CORE_coordinator_status_1_get_a53_cpu0_bist_fail0_scu(data)        ((0x0F000000&(data))>>24)
#define  SCPU_CORE_coordinator_status_1_get_a53_bist_fail0_l2_tag(data)          ((0x00FFFF00&(data))>>8)
#define  SCPU_CORE_coordinator_status_1_get_a53_bist_fail0_l2_victim(data)       ((0x00000080&(data))>>7)
#define  SCPU_CORE_coordinator_status_1_get_a53_drf_start_pause0(data)           ((0x00000040&(data))>>6)
#define  SCPU_CORE_coordinator_status_1_get_a53_drf_bist_done0(data)             ((0x00000020&(data))>>5)
#define  SCPU_CORE_coordinator_status_1_get_a53_bist_fail1_l2_data(data)         (0x0000000F&(data))

#define  SCPU_CORE_coordinator_status_2                                          0x1805B490
#define  SCPU_CORE_coordinator_status_2_reg_addr                                 "0xB805B490"
#define  SCPU_CORE_coordinator_status_2_reg                                      0xB805B490
#define  SCPU_CORE_coordinator_status_2_inst_addr                                "0x002A"
#define  set_SCPU_CORE_coordinator_status_2_reg(data)                            (*((volatile unsigned int*)SCPU_CORE_coordinator_status_2_reg)=data)
#define  get_SCPU_CORE_coordinator_status_2_reg                                  (*((volatile unsigned int*)SCPU_CORE_coordinator_status_2_reg))
#define  SCPU_CORE_coordinator_status_2_a53_cpu0_drf_bist_fail0_ddata_shift      (24)
#define  SCPU_CORE_coordinator_status_2_a53_cpu0_drf_bist_fail0_dtag_shift       (20)
#define  SCPU_CORE_coordinator_status_2_a53_cpu0_drf_bist_fail0_ddirty_shift     (19)
#define  SCPU_CORE_coordinator_status_2_a53_cpu0_drf_bist_fail0_idata_shift      (17)
#define  SCPU_CORE_coordinator_status_2_a53_cpu0_drf_bist_fail0_itag_shift       (15)
#define  SCPU_CORE_coordinator_status_2_a53_cpu0_drf_bist_fail0_btac0_shift      (14)
#define  SCPU_CORE_coordinator_status_2_a53_cpu0_drf_bist_fail0_btac1_shift      (13)
#define  SCPU_CORE_coordinator_status_2_a53_cpu0_drf_bist_fail0_tlb_shift        (9)
#define  SCPU_CORE_coordinator_status_2_a53_cpu0_drf_bist_fail0_scu_shift        (5)
#define  SCPU_CORE_coordinator_status_2_a53_cpu0_drf_bist_fail0_ddata_mask       (0xFF000000)
#define  SCPU_CORE_coordinator_status_2_a53_cpu0_drf_bist_fail0_dtag_mask        (0x00F00000)
#define  SCPU_CORE_coordinator_status_2_a53_cpu0_drf_bist_fail0_ddirty_mask      (0x00080000)
#define  SCPU_CORE_coordinator_status_2_a53_cpu0_drf_bist_fail0_idata_mask       (0x00060000)
#define  SCPU_CORE_coordinator_status_2_a53_cpu0_drf_bist_fail0_itag_mask        (0x00018000)
#define  SCPU_CORE_coordinator_status_2_a53_cpu0_drf_bist_fail0_btac0_mask       (0x00004000)
#define  SCPU_CORE_coordinator_status_2_a53_cpu0_drf_bist_fail0_btac1_mask       (0x00002000)
#define  SCPU_CORE_coordinator_status_2_a53_cpu0_drf_bist_fail0_tlb_mask         (0x00001E00)
#define  SCPU_CORE_coordinator_status_2_a53_cpu0_drf_bist_fail0_scu_mask         (0x000001E0)
#define  SCPU_CORE_coordinator_status_2_a53_cpu0_drf_bist_fail0_ddata(data)      (0xFF000000&((data)<<24))
#define  SCPU_CORE_coordinator_status_2_a53_cpu0_drf_bist_fail0_dtag(data)       (0x00F00000&((data)<<20))
#define  SCPU_CORE_coordinator_status_2_a53_cpu0_drf_bist_fail0_ddirty(data)     (0x00080000&((data)<<19))
#define  SCPU_CORE_coordinator_status_2_a53_cpu0_drf_bist_fail0_idata(data)      (0x00060000&((data)<<17))
#define  SCPU_CORE_coordinator_status_2_a53_cpu0_drf_bist_fail0_itag(data)       (0x00018000&((data)<<15))
#define  SCPU_CORE_coordinator_status_2_a53_cpu0_drf_bist_fail0_btac0(data)      (0x00004000&((data)<<14))
#define  SCPU_CORE_coordinator_status_2_a53_cpu0_drf_bist_fail0_btac1(data)      (0x00002000&((data)<<13))
#define  SCPU_CORE_coordinator_status_2_a53_cpu0_drf_bist_fail0_tlb(data)        (0x00001E00&((data)<<9))
#define  SCPU_CORE_coordinator_status_2_a53_cpu0_drf_bist_fail0_scu(data)        (0x000001E0&((data)<<5))
#define  SCPU_CORE_coordinator_status_2_get_a53_cpu0_drf_bist_fail0_ddata(data)  ((0xFF000000&(data))>>24)
#define  SCPU_CORE_coordinator_status_2_get_a53_cpu0_drf_bist_fail0_dtag(data)   ((0x00F00000&(data))>>20)
#define  SCPU_CORE_coordinator_status_2_get_a53_cpu0_drf_bist_fail0_ddirty(data) ((0x00080000&(data))>>19)
#define  SCPU_CORE_coordinator_status_2_get_a53_cpu0_drf_bist_fail0_idata(data)  ((0x00060000&(data))>>17)
#define  SCPU_CORE_coordinator_status_2_get_a53_cpu0_drf_bist_fail0_itag(data)   ((0x00018000&(data))>>15)
#define  SCPU_CORE_coordinator_status_2_get_a53_cpu0_drf_bist_fail0_btac0(data)  ((0x00004000&(data))>>14)
#define  SCPU_CORE_coordinator_status_2_get_a53_cpu0_drf_bist_fail0_btac1(data)  ((0x00002000&(data))>>13)
#define  SCPU_CORE_coordinator_status_2_get_a53_cpu0_drf_bist_fail0_tlb(data)    ((0x00001E00&(data))>>9)
#define  SCPU_CORE_coordinator_status_2_get_a53_cpu0_drf_bist_fail0_scu(data)    ((0x000001E0&(data))>>5)

#define  SCPU_CORE_coordinator_status_3                                          0x1805B494
#define  SCPU_CORE_coordinator_status_3_reg_addr                                 "0xB805B494"
#define  SCPU_CORE_coordinator_status_3_reg                                      0xB805B494
#define  SCPU_CORE_coordinator_status_3_inst_addr                                "0x002B"
#define  set_SCPU_CORE_coordinator_status_3_reg(data)                            (*((volatile unsigned int*)SCPU_CORE_coordinator_status_3_reg)=data)
#define  get_SCPU_CORE_coordinator_status_3_reg                                  (*((volatile unsigned int*)SCPU_CORE_coordinator_status_3_reg))
#define  SCPU_CORE_coordinator_status_3_a53_cpu1_drf_bist_fail0_ddata_shift      (24)
#define  SCPU_CORE_coordinator_status_3_a53_cpu1_drf_bist_fail0_dtag_shift       (20)
#define  SCPU_CORE_coordinator_status_3_a53_cpu1_drf_bist_fail0_ddirty_shift     (19)
#define  SCPU_CORE_coordinator_status_3_a53_cpu1_drf_bist_fail0_idata_shift      (17)
#define  SCPU_CORE_coordinator_status_3_a53_cpu1_drf_bist_fail0_itag_shift       (15)
#define  SCPU_CORE_coordinator_status_3_a53_cpu1_drf_bist_fail0_btac0_shift      (14)
#define  SCPU_CORE_coordinator_status_3_a53_cpu1_drf_bist_fail0_btac1_shift      (13)
#define  SCPU_CORE_coordinator_status_3_a53_cpu1_drf_bist_fail0_tlb_shift        (9)
#define  SCPU_CORE_coordinator_status_3_a53_cpu1_drf_bist_fail0_scu_shift        (5)
#define  SCPU_CORE_coordinator_status_3_a53_cpu1_drf_bist_fail0_ddata_mask       (0xFF000000)
#define  SCPU_CORE_coordinator_status_3_a53_cpu1_drf_bist_fail0_dtag_mask        (0x00F00000)
#define  SCPU_CORE_coordinator_status_3_a53_cpu1_drf_bist_fail0_ddirty_mask      (0x00080000)
#define  SCPU_CORE_coordinator_status_3_a53_cpu1_drf_bist_fail0_idata_mask       (0x00060000)
#define  SCPU_CORE_coordinator_status_3_a53_cpu1_drf_bist_fail0_itag_mask        (0x00018000)
#define  SCPU_CORE_coordinator_status_3_a53_cpu1_drf_bist_fail0_btac0_mask       (0x00004000)
#define  SCPU_CORE_coordinator_status_3_a53_cpu1_drf_bist_fail0_btac1_mask       (0x00002000)
#define  SCPU_CORE_coordinator_status_3_a53_cpu1_drf_bist_fail0_tlb_mask         (0x00001E00)
#define  SCPU_CORE_coordinator_status_3_a53_cpu1_drf_bist_fail0_scu_mask         (0x000001E0)
#define  SCPU_CORE_coordinator_status_3_a53_cpu1_drf_bist_fail0_ddata(data)      (0xFF000000&((data)<<24))
#define  SCPU_CORE_coordinator_status_3_a53_cpu1_drf_bist_fail0_dtag(data)       (0x00F00000&((data)<<20))
#define  SCPU_CORE_coordinator_status_3_a53_cpu1_drf_bist_fail0_ddirty(data)     (0x00080000&((data)<<19))
#define  SCPU_CORE_coordinator_status_3_a53_cpu1_drf_bist_fail0_idata(data)      (0x00060000&((data)<<17))
#define  SCPU_CORE_coordinator_status_3_a53_cpu1_drf_bist_fail0_itag(data)       (0x00018000&((data)<<15))
#define  SCPU_CORE_coordinator_status_3_a53_cpu1_drf_bist_fail0_btac0(data)      (0x00004000&((data)<<14))
#define  SCPU_CORE_coordinator_status_3_a53_cpu1_drf_bist_fail0_btac1(data)      (0x00002000&((data)<<13))
#define  SCPU_CORE_coordinator_status_3_a53_cpu1_drf_bist_fail0_tlb(data)        (0x00001E00&((data)<<9))
#define  SCPU_CORE_coordinator_status_3_a53_cpu1_drf_bist_fail0_scu(data)        (0x000001E0&((data)<<5))
#define  SCPU_CORE_coordinator_status_3_get_a53_cpu1_drf_bist_fail0_ddata(data)  ((0xFF000000&(data))>>24)
#define  SCPU_CORE_coordinator_status_3_get_a53_cpu1_drf_bist_fail0_dtag(data)   ((0x00F00000&(data))>>20)
#define  SCPU_CORE_coordinator_status_3_get_a53_cpu1_drf_bist_fail0_ddirty(data) ((0x00080000&(data))>>19)
#define  SCPU_CORE_coordinator_status_3_get_a53_cpu1_drf_bist_fail0_idata(data)  ((0x00060000&(data))>>17)
#define  SCPU_CORE_coordinator_status_3_get_a53_cpu1_drf_bist_fail0_itag(data)   ((0x00018000&(data))>>15)
#define  SCPU_CORE_coordinator_status_3_get_a53_cpu1_drf_bist_fail0_btac0(data)  ((0x00004000&(data))>>14)
#define  SCPU_CORE_coordinator_status_3_get_a53_cpu1_drf_bist_fail0_btac1(data)  ((0x00002000&(data))>>13)
#define  SCPU_CORE_coordinator_status_3_get_a53_cpu1_drf_bist_fail0_tlb(data)    ((0x00001E00&(data))>>9)
#define  SCPU_CORE_coordinator_status_3_get_a53_cpu1_drf_bist_fail0_scu(data)    ((0x000001E0&(data))>>5)

#define  SCPU_CORE_coordinator_status_4                                          0x1805B498
#define  SCPU_CORE_coordinator_status_4_reg_addr                                 "0xB805B498"
#define  SCPU_CORE_coordinator_status_4_reg                                      0xB805B498
#define  SCPU_CORE_coordinator_status_4_inst_addr                                "0x002C"
#define  set_SCPU_CORE_coordinator_status_4_reg(data)                            (*((volatile unsigned int*)SCPU_CORE_coordinator_status_4_reg)=data)
#define  get_SCPU_CORE_coordinator_status_4_reg                                  (*((volatile unsigned int*)SCPU_CORE_coordinator_status_4_reg))
#define  SCPU_CORE_coordinator_status_4_a53_drf_bist_fail0_l2_tag_shift          (16)
#define  SCPU_CORE_coordinator_status_4_a53_drf_bist_fail0_l2_victim_shift       (15)
#define  SCPU_CORE_coordinator_status_4_a53_drf_bist_fail0_l2_tag_mask           (0xFFFF0000)
#define  SCPU_CORE_coordinator_status_4_a53_drf_bist_fail0_l2_victim_mask        (0x00008000)
#define  SCPU_CORE_coordinator_status_4_a53_drf_bist_fail0_l2_tag(data)          (0xFFFF0000&((data)<<16))
#define  SCPU_CORE_coordinator_status_4_a53_drf_bist_fail0_l2_victim(data)       (0x00008000&((data)<<15))
#define  SCPU_CORE_coordinator_status_4_get_a53_drf_bist_fail0_l2_tag(data)      ((0xFFFF0000&(data))>>16)
#define  SCPU_CORE_coordinator_status_4_get_a53_drf_bist_fail0_l2_victim(data)   ((0x00008000&(data))>>15)

#define  SCPU_CORE_coordinator_status_5                                          0x1805B49C
#define  SCPU_CORE_coordinator_status_5_reg_addr                                 "0xB805B49C"
#define  SCPU_CORE_coordinator_status_5_reg                                      0xB805B49C
#define  SCPU_CORE_coordinator_status_5_inst_addr                                "0x002D"
#define  set_SCPU_CORE_coordinator_status_5_reg(data)                            (*((volatile unsigned int*)SCPU_CORE_coordinator_status_5_reg)=data)
#define  get_SCPU_CORE_coordinator_status_5_reg                                  (*((volatile unsigned int*)SCPU_CORE_coordinator_status_5_reg))
#define  SCPU_CORE_coordinator_status_5_a53_cpu1_bist_fail0_ddata_shift          (24)
#define  SCPU_CORE_coordinator_status_5_a53_cpu1_bist_fail0_dtag_shift           (20)
#define  SCPU_CORE_coordinator_status_5_a53_cpu1_bist_fail0_ddirty_shift         (19)
#define  SCPU_CORE_coordinator_status_5_a53_cpu1_bist_fail0_idata_shift          (17)
#define  SCPU_CORE_coordinator_status_5_a53_cpu1_bist_fail0_itag_shift           (15)
#define  SCPU_CORE_coordinator_status_5_a53_cpu1_bist_fail0_btac0_shift          (14)
#define  SCPU_CORE_coordinator_status_5_a53_cpu1_bist_fail0_btac1_shift          (13)
#define  SCPU_CORE_coordinator_status_5_a53_cpu1_bist_fail0_tlb_shift            (9)
#define  SCPU_CORE_coordinator_status_5_a53_cpu1_bist_fail0_scu_shift            (5)
#define  SCPU_CORE_coordinator_status_5_a53_cpu1_bist_fail0_ddata_mask           (0xFF000000)
#define  SCPU_CORE_coordinator_status_5_a53_cpu1_bist_fail0_dtag_mask            (0x00F00000)
#define  SCPU_CORE_coordinator_status_5_a53_cpu1_bist_fail0_ddirty_mask          (0x00080000)
#define  SCPU_CORE_coordinator_status_5_a53_cpu1_bist_fail0_idata_mask           (0x00060000)
#define  SCPU_CORE_coordinator_status_5_a53_cpu1_bist_fail0_itag_mask            (0x00018000)
#define  SCPU_CORE_coordinator_status_5_a53_cpu1_bist_fail0_btac0_mask           (0x00004000)
#define  SCPU_CORE_coordinator_status_5_a53_cpu1_bist_fail0_btac1_mask           (0x00002000)
#define  SCPU_CORE_coordinator_status_5_a53_cpu1_bist_fail0_tlb_mask             (0x00001E00)
#define  SCPU_CORE_coordinator_status_5_a53_cpu1_bist_fail0_scu_mask             (0x000001E0)
#define  SCPU_CORE_coordinator_status_5_a53_cpu1_bist_fail0_ddata(data)          (0xFF000000&((data)<<24))
#define  SCPU_CORE_coordinator_status_5_a53_cpu1_bist_fail0_dtag(data)           (0x00F00000&((data)<<20))
#define  SCPU_CORE_coordinator_status_5_a53_cpu1_bist_fail0_ddirty(data)         (0x00080000&((data)<<19))
#define  SCPU_CORE_coordinator_status_5_a53_cpu1_bist_fail0_idata(data)          (0x00060000&((data)<<17))
#define  SCPU_CORE_coordinator_status_5_a53_cpu1_bist_fail0_itag(data)           (0x00018000&((data)<<15))
#define  SCPU_CORE_coordinator_status_5_a53_cpu1_bist_fail0_btac0(data)          (0x00004000&((data)<<14))
#define  SCPU_CORE_coordinator_status_5_a53_cpu1_bist_fail0_btac1(data)          (0x00002000&((data)<<13))
#define  SCPU_CORE_coordinator_status_5_a53_cpu1_bist_fail0_tlb(data)            (0x00001E00&((data)<<9))
#define  SCPU_CORE_coordinator_status_5_a53_cpu1_bist_fail0_scu(data)            (0x000001E0&((data)<<5))
#define  SCPU_CORE_coordinator_status_5_get_a53_cpu1_bist_fail0_ddata(data)      ((0xFF000000&(data))>>24)
#define  SCPU_CORE_coordinator_status_5_get_a53_cpu1_bist_fail0_dtag(data)       ((0x00F00000&(data))>>20)
#define  SCPU_CORE_coordinator_status_5_get_a53_cpu1_bist_fail0_ddirty(data)     ((0x00080000&(data))>>19)
#define  SCPU_CORE_coordinator_status_5_get_a53_cpu1_bist_fail0_idata(data)      ((0x00060000&(data))>>17)
#define  SCPU_CORE_coordinator_status_5_get_a53_cpu1_bist_fail0_itag(data)       ((0x00018000&(data))>>15)
#define  SCPU_CORE_coordinator_status_5_get_a53_cpu1_bist_fail0_btac0(data)      ((0x00004000&(data))>>14)
#define  SCPU_CORE_coordinator_status_5_get_a53_cpu1_bist_fail0_btac1(data)      ((0x00002000&(data))>>13)
#define  SCPU_CORE_coordinator_status_5_get_a53_cpu1_bist_fail0_tlb(data)        ((0x00001E00&(data))>>9)
#define  SCPU_CORE_coordinator_status_5_get_a53_cpu1_bist_fail0_scu(data)        ((0x000001E0&(data))>>5)

#define  SCPU_CORE_coordinator_status_6                                          0x1805B4A0
#define  SCPU_CORE_coordinator_status_6_reg_addr                                 "0xB805B4A0"
#define  SCPU_CORE_coordinator_status_6_reg                                      0xB805B4A0
#define  SCPU_CORE_coordinator_status_6_inst_addr                                "0x002E"
#define  set_SCPU_CORE_coordinator_status_6_reg(data)                            (*((volatile unsigned int*)SCPU_CORE_coordinator_status_6_reg)=data)
#define  get_SCPU_CORE_coordinator_status_6_reg                                  (*((volatile unsigned int*)SCPU_CORE_coordinator_status_6_reg))
#define  SCPU_CORE_coordinator_status_6_a53_cpu2_bist_fail0_ddata_shift          (24)
#define  SCPU_CORE_coordinator_status_6_a53_cpu2_bist_fail0_dtag_shift           (20)
#define  SCPU_CORE_coordinator_status_6_a53_cpu2_bist_fail0_ddirty_shift         (19)
#define  SCPU_CORE_coordinator_status_6_a53_cpu2_bist_fail0_idata_shift          (17)
#define  SCPU_CORE_coordinator_status_6_a53_cpu2_bist_fail0_itag_shift           (15)
#define  SCPU_CORE_coordinator_status_6_a53_cpu2_bist_fail0_btac0_shift          (14)
#define  SCPU_CORE_coordinator_status_6_a53_cpu2_bist_fail0_btac1_shift          (13)
#define  SCPU_CORE_coordinator_status_6_a53_cpu2_bist_fail0_tlb_shift            (9)
#define  SCPU_CORE_coordinator_status_6_a53_cpu2_bist_fail0_scu_shift            (5)
#define  SCPU_CORE_coordinator_status_6_a53_cpu2_bist_fail0_ddata_mask           (0xFF000000)
#define  SCPU_CORE_coordinator_status_6_a53_cpu2_bist_fail0_dtag_mask            (0x00F00000)
#define  SCPU_CORE_coordinator_status_6_a53_cpu2_bist_fail0_ddirty_mask          (0x00080000)
#define  SCPU_CORE_coordinator_status_6_a53_cpu2_bist_fail0_idata_mask           (0x00060000)
#define  SCPU_CORE_coordinator_status_6_a53_cpu2_bist_fail0_itag_mask            (0x00018000)
#define  SCPU_CORE_coordinator_status_6_a53_cpu2_bist_fail0_btac0_mask           (0x00004000)
#define  SCPU_CORE_coordinator_status_6_a53_cpu2_bist_fail0_btac1_mask           (0x00002000)
#define  SCPU_CORE_coordinator_status_6_a53_cpu2_bist_fail0_tlb_mask             (0x00001E00)
#define  SCPU_CORE_coordinator_status_6_a53_cpu2_bist_fail0_scu_mask             (0x000001E0)
#define  SCPU_CORE_coordinator_status_6_a53_cpu2_bist_fail0_ddata(data)          (0xFF000000&((data)<<24))
#define  SCPU_CORE_coordinator_status_6_a53_cpu2_bist_fail0_dtag(data)           (0x00F00000&((data)<<20))
#define  SCPU_CORE_coordinator_status_6_a53_cpu2_bist_fail0_ddirty(data)         (0x00080000&((data)<<19))
#define  SCPU_CORE_coordinator_status_6_a53_cpu2_bist_fail0_idata(data)          (0x00060000&((data)<<17))
#define  SCPU_CORE_coordinator_status_6_a53_cpu2_bist_fail0_itag(data)           (0x00018000&((data)<<15))
#define  SCPU_CORE_coordinator_status_6_a53_cpu2_bist_fail0_btac0(data)          (0x00004000&((data)<<14))
#define  SCPU_CORE_coordinator_status_6_a53_cpu2_bist_fail0_btac1(data)          (0x00002000&((data)<<13))
#define  SCPU_CORE_coordinator_status_6_a53_cpu2_bist_fail0_tlb(data)            (0x00001E00&((data)<<9))
#define  SCPU_CORE_coordinator_status_6_a53_cpu2_bist_fail0_scu(data)            (0x000001E0&((data)<<5))
#define  SCPU_CORE_coordinator_status_6_get_a53_cpu2_bist_fail0_ddata(data)      ((0xFF000000&(data))>>24)
#define  SCPU_CORE_coordinator_status_6_get_a53_cpu2_bist_fail0_dtag(data)       ((0x00F00000&(data))>>20)
#define  SCPU_CORE_coordinator_status_6_get_a53_cpu2_bist_fail0_ddirty(data)     ((0x00080000&(data))>>19)
#define  SCPU_CORE_coordinator_status_6_get_a53_cpu2_bist_fail0_idata(data)      ((0x00060000&(data))>>17)
#define  SCPU_CORE_coordinator_status_6_get_a53_cpu2_bist_fail0_itag(data)       ((0x00018000&(data))>>15)
#define  SCPU_CORE_coordinator_status_6_get_a53_cpu2_bist_fail0_btac0(data)      ((0x00004000&(data))>>14)
#define  SCPU_CORE_coordinator_status_6_get_a53_cpu2_bist_fail0_btac1(data)      ((0x00002000&(data))>>13)
#define  SCPU_CORE_coordinator_status_6_get_a53_cpu2_bist_fail0_tlb(data)        ((0x00001E00&(data))>>9)
#define  SCPU_CORE_coordinator_status_6_get_a53_cpu2_bist_fail0_scu(data)        ((0x000001E0&(data))>>5)

#define  SCPU_CORE_coordinator_status_7                                          0x1805B4A4
#define  SCPU_CORE_coordinator_status_7_reg_addr                                 "0xB805B4A4"
#define  SCPU_CORE_coordinator_status_7_reg                                      0xB805B4A4
#define  SCPU_CORE_coordinator_status_7_inst_addr                                "0x002F"
#define  set_SCPU_CORE_coordinator_status_7_reg(data)                            (*((volatile unsigned int*)SCPU_CORE_coordinator_status_7_reg)=data)
#define  get_SCPU_CORE_coordinator_status_7_reg                                  (*((volatile unsigned int*)SCPU_CORE_coordinator_status_7_reg))
#define  SCPU_CORE_coordinator_status_7_a53_cpu3_bist_fail0_ddata_shift          (24)
#define  SCPU_CORE_coordinator_status_7_a53_cpu3_bist_fail0_dtag_shift           (20)
#define  SCPU_CORE_coordinator_status_7_a53_cpu3_bist_fail0_ddirty_shift         (19)
#define  SCPU_CORE_coordinator_status_7_a53_cpu3_bist_fail0_idata_shift          (17)
#define  SCPU_CORE_coordinator_status_7_a53_cpu3_bist_fail0_itag_shift           (15)
#define  SCPU_CORE_coordinator_status_7_a53_cpu3_bist_fail0_btac0_shift          (14)
#define  SCPU_CORE_coordinator_status_7_a53_cpu3_bist_fail0_btac1_shift          (13)
#define  SCPU_CORE_coordinator_status_7_a53_cpu3_bist_fail0_tlb_shift            (9)
#define  SCPU_CORE_coordinator_status_7_a53_cpu3_bist_fail0_scu_shift            (5)
#define  SCPU_CORE_coordinator_status_7_a53_cpu3_bist_fail0_ddata_mask           (0xFF000000)
#define  SCPU_CORE_coordinator_status_7_a53_cpu3_bist_fail0_dtag_mask            (0x00F00000)
#define  SCPU_CORE_coordinator_status_7_a53_cpu3_bist_fail0_ddirty_mask          (0x00080000)
#define  SCPU_CORE_coordinator_status_7_a53_cpu3_bist_fail0_idata_mask           (0x00060000)
#define  SCPU_CORE_coordinator_status_7_a53_cpu3_bist_fail0_itag_mask            (0x00018000)
#define  SCPU_CORE_coordinator_status_7_a53_cpu3_bist_fail0_btac0_mask           (0x00004000)
#define  SCPU_CORE_coordinator_status_7_a53_cpu3_bist_fail0_btac1_mask           (0x00002000)
#define  SCPU_CORE_coordinator_status_7_a53_cpu3_bist_fail0_tlb_mask             (0x00001E00)
#define  SCPU_CORE_coordinator_status_7_a53_cpu3_bist_fail0_scu_mask             (0x000001E0)
#define  SCPU_CORE_coordinator_status_7_a53_cpu3_bist_fail0_ddata(data)          (0xFF000000&((data)<<24))
#define  SCPU_CORE_coordinator_status_7_a53_cpu3_bist_fail0_dtag(data)           (0x00F00000&((data)<<20))
#define  SCPU_CORE_coordinator_status_7_a53_cpu3_bist_fail0_ddirty(data)         (0x00080000&((data)<<19))
#define  SCPU_CORE_coordinator_status_7_a53_cpu3_bist_fail0_idata(data)          (0x00060000&((data)<<17))
#define  SCPU_CORE_coordinator_status_7_a53_cpu3_bist_fail0_itag(data)           (0x00018000&((data)<<15))
#define  SCPU_CORE_coordinator_status_7_a53_cpu3_bist_fail0_btac0(data)          (0x00004000&((data)<<14))
#define  SCPU_CORE_coordinator_status_7_a53_cpu3_bist_fail0_btac1(data)          (0x00002000&((data)<<13))
#define  SCPU_CORE_coordinator_status_7_a53_cpu3_bist_fail0_tlb(data)            (0x00001E00&((data)<<9))
#define  SCPU_CORE_coordinator_status_7_a53_cpu3_bist_fail0_scu(data)            (0x000001E0&((data)<<5))
#define  SCPU_CORE_coordinator_status_7_get_a53_cpu3_bist_fail0_ddata(data)      ((0xFF000000&(data))>>24)
#define  SCPU_CORE_coordinator_status_7_get_a53_cpu3_bist_fail0_dtag(data)       ((0x00F00000&(data))>>20)
#define  SCPU_CORE_coordinator_status_7_get_a53_cpu3_bist_fail0_ddirty(data)     ((0x00080000&(data))>>19)
#define  SCPU_CORE_coordinator_status_7_get_a53_cpu3_bist_fail0_idata(data)      ((0x00060000&(data))>>17)
#define  SCPU_CORE_coordinator_status_7_get_a53_cpu3_bist_fail0_itag(data)       ((0x00018000&(data))>>15)
#define  SCPU_CORE_coordinator_status_7_get_a53_cpu3_bist_fail0_btac0(data)      ((0x00004000&(data))>>14)
#define  SCPU_CORE_coordinator_status_7_get_a53_cpu3_bist_fail0_btac1(data)      ((0x00002000&(data))>>13)
#define  SCPU_CORE_coordinator_status_7_get_a53_cpu3_bist_fail0_tlb(data)        ((0x00001E00&(data))>>9)
#define  SCPU_CORE_coordinator_status_7_get_a53_cpu3_bist_fail0_scu(data)        ((0x000001E0&(data))>>5)

#define  SCPU_CORE_coordinator_status_8                                          0x1805B4A8
#define  SCPU_CORE_coordinator_status_8_reg_addr                                 "0xB805B4A8"
#define  SCPU_CORE_coordinator_status_8_reg                                      0xB805B4A8
#define  SCPU_CORE_coordinator_status_8_inst_addr                                "0x0030"
#define  set_SCPU_CORE_coordinator_status_8_reg(data)                            (*((volatile unsigned int*)SCPU_CORE_coordinator_status_8_reg)=data)
#define  get_SCPU_CORE_coordinator_status_8_reg                                  (*((volatile unsigned int*)SCPU_CORE_coordinator_status_8_reg))
#define  SCPU_CORE_coordinator_status_8_a53_cpu2_drf_bist_fail0_ddata_shift      (24)
#define  SCPU_CORE_coordinator_status_8_a53_cpu2_drf_bist_fail0_dtag_shift       (20)
#define  SCPU_CORE_coordinator_status_8_a53_cpu2_drf_bist_fail0_ddirty_shift     (19)
#define  SCPU_CORE_coordinator_status_8_a53_cpu2_drf_bist_fail0_idata_shift      (17)
#define  SCPU_CORE_coordinator_status_8_a53_cpu2_drf_bist_fail0_itag_shift       (15)
#define  SCPU_CORE_coordinator_status_8_a53_cpu2_drf_bist_fail0_btac0_shift      (14)
#define  SCPU_CORE_coordinator_status_8_a53_cpu2_drf_bist_fail0_btac1_shift      (13)
#define  SCPU_CORE_coordinator_status_8_a53_cpu2_drf_bist_fail0_tlb_shift        (9)
#define  SCPU_CORE_coordinator_status_8_a53_cpu2_drf_bist_fail0_scu_shift        (5)
#define  SCPU_CORE_coordinator_status_8_a53_cpu2_drf_bist_fail0_ddata_mask       (0xFF000000)
#define  SCPU_CORE_coordinator_status_8_a53_cpu2_drf_bist_fail0_dtag_mask        (0x00F00000)
#define  SCPU_CORE_coordinator_status_8_a53_cpu2_drf_bist_fail0_ddirty_mask      (0x00080000)
#define  SCPU_CORE_coordinator_status_8_a53_cpu2_drf_bist_fail0_idata_mask       (0x00060000)
#define  SCPU_CORE_coordinator_status_8_a53_cpu2_drf_bist_fail0_itag_mask        (0x00018000)
#define  SCPU_CORE_coordinator_status_8_a53_cpu2_drf_bist_fail0_btac0_mask       (0x00004000)
#define  SCPU_CORE_coordinator_status_8_a53_cpu2_drf_bist_fail0_btac1_mask       (0x00002000)
#define  SCPU_CORE_coordinator_status_8_a53_cpu2_drf_bist_fail0_tlb_mask         (0x00001E00)
#define  SCPU_CORE_coordinator_status_8_a53_cpu2_drf_bist_fail0_scu_mask         (0x000001E0)
#define  SCPU_CORE_coordinator_status_8_a53_cpu2_drf_bist_fail0_ddata(data)      (0xFF000000&((data)<<24))
#define  SCPU_CORE_coordinator_status_8_a53_cpu2_drf_bist_fail0_dtag(data)       (0x00F00000&((data)<<20))
#define  SCPU_CORE_coordinator_status_8_a53_cpu2_drf_bist_fail0_ddirty(data)     (0x00080000&((data)<<19))
#define  SCPU_CORE_coordinator_status_8_a53_cpu2_drf_bist_fail0_idata(data)      (0x00060000&((data)<<17))
#define  SCPU_CORE_coordinator_status_8_a53_cpu2_drf_bist_fail0_itag(data)       (0x00018000&((data)<<15))
#define  SCPU_CORE_coordinator_status_8_a53_cpu2_drf_bist_fail0_btac0(data)      (0x00004000&((data)<<14))
#define  SCPU_CORE_coordinator_status_8_a53_cpu2_drf_bist_fail0_btac1(data)      (0x00002000&((data)<<13))
#define  SCPU_CORE_coordinator_status_8_a53_cpu2_drf_bist_fail0_tlb(data)        (0x00001E00&((data)<<9))
#define  SCPU_CORE_coordinator_status_8_a53_cpu2_drf_bist_fail0_scu(data)        (0x000001E0&((data)<<5))
#define  SCPU_CORE_coordinator_status_8_get_a53_cpu2_drf_bist_fail0_ddata(data)  ((0xFF000000&(data))>>24)
#define  SCPU_CORE_coordinator_status_8_get_a53_cpu2_drf_bist_fail0_dtag(data)   ((0x00F00000&(data))>>20)
#define  SCPU_CORE_coordinator_status_8_get_a53_cpu2_drf_bist_fail0_ddirty(data) ((0x00080000&(data))>>19)
#define  SCPU_CORE_coordinator_status_8_get_a53_cpu2_drf_bist_fail0_idata(data)  ((0x00060000&(data))>>17)
#define  SCPU_CORE_coordinator_status_8_get_a53_cpu2_drf_bist_fail0_itag(data)   ((0x00018000&(data))>>15)
#define  SCPU_CORE_coordinator_status_8_get_a53_cpu2_drf_bist_fail0_btac0(data)  ((0x00004000&(data))>>14)
#define  SCPU_CORE_coordinator_status_8_get_a53_cpu2_drf_bist_fail0_btac1(data)  ((0x00002000&(data))>>13)
#define  SCPU_CORE_coordinator_status_8_get_a53_cpu2_drf_bist_fail0_tlb(data)    ((0x00001E00&(data))>>9)
#define  SCPU_CORE_coordinator_status_8_get_a53_cpu2_drf_bist_fail0_scu(data)    ((0x000001E0&(data))>>5)

#define  SCPU_CORE_coordinator_status_9                                          0x1805B4AC
#define  SCPU_CORE_coordinator_status_9_reg_addr                                 "0xB805B4AC"
#define  SCPU_CORE_coordinator_status_9_reg                                      0xB805B4AC
#define  SCPU_CORE_coordinator_status_9_inst_addr                                "0x0031"
#define  set_SCPU_CORE_coordinator_status_9_reg(data)                            (*((volatile unsigned int*)SCPU_CORE_coordinator_status_9_reg)=data)
#define  get_SCPU_CORE_coordinator_status_9_reg                                  (*((volatile unsigned int*)SCPU_CORE_coordinator_status_9_reg))
#define  SCPU_CORE_coordinator_status_9_a53_cpu3_drf_bist_fail0_ddata_shift      (24)
#define  SCPU_CORE_coordinator_status_9_a53_cpu3_drf_bist_fail0_dtag_shift       (20)
#define  SCPU_CORE_coordinator_status_9_a53_cpu3_drf_bist_fail0_ddirty_shift     (19)
#define  SCPU_CORE_coordinator_status_9_a53_cpu3_drf_bist_fail0_idata_shift      (17)
#define  SCPU_CORE_coordinator_status_9_a53_cpu3_drf_bist_fail0_itag_shift       (15)
#define  SCPU_CORE_coordinator_status_9_a53_cpu3_drf_bist_fail0_btac0_shift      (14)
#define  SCPU_CORE_coordinator_status_9_a53_cpu3_drf_bist_fail0_btac1_shift      (13)
#define  SCPU_CORE_coordinator_status_9_a53_cpu3_drf_bist_fail0_tlb_shift        (9)
#define  SCPU_CORE_coordinator_status_9_a53_cpu3_drf_bist_fail0_scu_shift        (5)
#define  SCPU_CORE_coordinator_status_9_a53_cpu3_drf_bist_fail0_ddata_mask       (0xFF000000)
#define  SCPU_CORE_coordinator_status_9_a53_cpu3_drf_bist_fail0_dtag_mask        (0x00F00000)
#define  SCPU_CORE_coordinator_status_9_a53_cpu3_drf_bist_fail0_ddirty_mask      (0x00080000)
#define  SCPU_CORE_coordinator_status_9_a53_cpu3_drf_bist_fail0_idata_mask       (0x00060000)
#define  SCPU_CORE_coordinator_status_9_a53_cpu3_drf_bist_fail0_itag_mask        (0x00018000)
#define  SCPU_CORE_coordinator_status_9_a53_cpu3_drf_bist_fail0_btac0_mask       (0x00004000)
#define  SCPU_CORE_coordinator_status_9_a53_cpu3_drf_bist_fail0_btac1_mask       (0x00002000)
#define  SCPU_CORE_coordinator_status_9_a53_cpu3_drf_bist_fail0_tlb_mask         (0x00001E00)
#define  SCPU_CORE_coordinator_status_9_a53_cpu3_drf_bist_fail0_scu_mask         (0x000001E0)
#define  SCPU_CORE_coordinator_status_9_a53_cpu3_drf_bist_fail0_ddata(data)      (0xFF000000&((data)<<24))
#define  SCPU_CORE_coordinator_status_9_a53_cpu3_drf_bist_fail0_dtag(data)       (0x00F00000&((data)<<20))
#define  SCPU_CORE_coordinator_status_9_a53_cpu3_drf_bist_fail0_ddirty(data)     (0x00080000&((data)<<19))
#define  SCPU_CORE_coordinator_status_9_a53_cpu3_drf_bist_fail0_idata(data)      (0x00060000&((data)<<17))
#define  SCPU_CORE_coordinator_status_9_a53_cpu3_drf_bist_fail0_itag(data)       (0x00018000&((data)<<15))
#define  SCPU_CORE_coordinator_status_9_a53_cpu3_drf_bist_fail0_btac0(data)      (0x00004000&((data)<<14))
#define  SCPU_CORE_coordinator_status_9_a53_cpu3_drf_bist_fail0_btac1(data)      (0x00002000&((data)<<13))
#define  SCPU_CORE_coordinator_status_9_a53_cpu3_drf_bist_fail0_tlb(data)        (0x00001E00&((data)<<9))
#define  SCPU_CORE_coordinator_status_9_a53_cpu3_drf_bist_fail0_scu(data)        (0x000001E0&((data)<<5))
#define  SCPU_CORE_coordinator_status_9_get_a53_cpu3_drf_bist_fail0_ddata(data)  ((0xFF000000&(data))>>24)
#define  SCPU_CORE_coordinator_status_9_get_a53_cpu3_drf_bist_fail0_dtag(data)   ((0x00F00000&(data))>>20)
#define  SCPU_CORE_coordinator_status_9_get_a53_cpu3_drf_bist_fail0_ddirty(data) ((0x00080000&(data))>>19)
#define  SCPU_CORE_coordinator_status_9_get_a53_cpu3_drf_bist_fail0_idata(data)  ((0x00060000&(data))>>17)
#define  SCPU_CORE_coordinator_status_9_get_a53_cpu3_drf_bist_fail0_itag(data)   ((0x00018000&(data))>>15)
#define  SCPU_CORE_coordinator_status_9_get_a53_cpu3_drf_bist_fail0_btac0(data)  ((0x00004000&(data))>>14)
#define  SCPU_CORE_coordinator_status_9_get_a53_cpu3_drf_bist_fail0_btac1(data)  ((0x00002000&(data))>>13)
#define  SCPU_CORE_coordinator_status_9_get_a53_cpu3_drf_bist_fail0_tlb(data)    ((0x00001E00&(data))>>9)
#define  SCPU_CORE_coordinator_status_9_get_a53_cpu3_drf_bist_fail0_scu(data)    ((0x000001E0&(data))>>5)

#define  SCPU_CORE_coordinator_status_10                                         0x1805B4B0
#define  SCPU_CORE_coordinator_status_10_reg_addr                                "0xB805B4B0"
#define  SCPU_CORE_coordinator_status_10_reg                                     0xB805B4B0
#define  SCPU_CORE_coordinator_status_10_inst_addr                               "0x0032"
#define  set_SCPU_CORE_coordinator_status_10_reg(data)                           (*((volatile unsigned int*)SCPU_CORE_coordinator_status_10_reg)=data)
#define  get_SCPU_CORE_coordinator_status_10_reg                                 (*((volatile unsigned int*)SCPU_CORE_coordinator_status_10_reg))
#define  SCPU_CORE_coordinator_status_10_mbistack0_dbg_shift                     (31)
#define  SCPU_CORE_coordinator_status_10_a53_mbistack_all_shift                  (30)
#define  SCPU_CORE_coordinator_status_10_mbistack1_dbg_shift                     (29)
#define  SCPU_CORE_coordinator_status_10_mbistack0_dbg_mask                      (0x80000000)
#define  SCPU_CORE_coordinator_status_10_a53_mbistack_all_mask                   (0x40000000)
#define  SCPU_CORE_coordinator_status_10_mbistack1_dbg_mask                      (0x20000000)
#define  SCPU_CORE_coordinator_status_10_mbistack0_dbg(data)                     (0x80000000&((data)<<31))
#define  SCPU_CORE_coordinator_status_10_a53_mbistack_all(data)                  (0x40000000&((data)<<30))
#define  SCPU_CORE_coordinator_status_10_mbistack1_dbg(data)                     (0x20000000&((data)<<29))
#define  SCPU_CORE_coordinator_status_10_get_mbistack0_dbg(data)                 ((0x80000000&(data))>>31)
#define  SCPU_CORE_coordinator_status_10_get_a53_mbistack_all(data)              ((0x40000000&(data))>>30)
#define  SCPU_CORE_coordinator_status_10_get_mbistack1_dbg(data)                 ((0x20000000&(data))>>29)

#define  SCPU_CORE_general_ctrl0                                                 0x1805B800
#define  SCPU_CORE_general_ctrl0_reg_addr                                        "0xB805B800"
#define  SCPU_CORE_general_ctrl0_reg                                             0xB805B800
#define  SCPU_CORE_general_ctrl0_inst_addr                                       "0x0033"
#define  set_SCPU_CORE_general_ctrl0_reg(data)                                   (*((volatile unsigned int*)SCPU_CORE_general_ctrl0_reg)=data)
#define  get_SCPU_CORE_general_ctrl0_reg                                         (*((volatile unsigned int*)SCPU_CORE_general_ctrl0_reg))
#define  SCPU_CORE_general_ctrl0_partnumber_shift                                (4)
#define  SCPU_CORE_general_ctrl0_revision_shift                                  (0)
#define  SCPU_CORE_general_ctrl0_partnumber_mask                                 (0x0000FFF0)
#define  SCPU_CORE_general_ctrl0_revision_mask                                   (0x0000000F)
#define  SCPU_CORE_general_ctrl0_partnumber(data)                                (0x0000FFF0&((data)<<4))
#define  SCPU_CORE_general_ctrl0_revision(data)                                  (0x0000000F&(data))
#define  SCPU_CORE_general_ctrl0_get_partnumber(data)                            ((0x0000FFF0&(data))>>4)
#define  SCPU_CORE_general_ctrl0_get_revision(data)                              (0x0000000F&(data))

#define  SCPU_CORE_general_ctrl1                                                 0x1805B804
#define  SCPU_CORE_general_ctrl1_reg_addr                                        "0xB805B804"
#define  SCPU_CORE_general_ctrl1_reg                                             0xB805B804
#define  SCPU_CORE_general_ctrl1_inst_addr                                       "0x0034"
#define  set_SCPU_CORE_general_ctrl1_reg(data)                                   (*((volatile unsigned int*)SCPU_CORE_general_ctrl1_reg)=data)
#define  get_SCPU_CORE_general_ctrl1_reg                                         (*((volatile unsigned int*)SCPU_CORE_general_ctrl1_reg))
#define  SCPU_CORE_general_ctrl1_dbgromaddrv_shift                               (28)
#define  SCPU_CORE_general_ctrl1_dbgromaddr_39_12_shift                          (0)
#define  SCPU_CORE_general_ctrl1_dbgromaddrv_mask                                (0x10000000)
#define  SCPU_CORE_general_ctrl1_dbgromaddr_39_12_mask                           (0x0FFFFFFF)
#define  SCPU_CORE_general_ctrl1_dbgromaddrv(data)                               (0x10000000&((data)<<28))
#define  SCPU_CORE_general_ctrl1_dbgromaddr_39_12(data)                          (0x0FFFFFFF&(data))
#define  SCPU_CORE_general_ctrl1_get_dbgromaddrv(data)                           ((0x10000000&(data))>>28)
#define  SCPU_CORE_general_ctrl1_get_dbgromaddr_39_12(data)                      (0x0FFFFFFF&(data))

#define  SCPU_CORE_ace_master_a53                                                0x1805B820
#define  SCPU_CORE_ace_master_a53_reg_addr                                       "0xB805B820"
#define  SCPU_CORE_ace_master_a53_reg                                            0xB805B820
#define  SCPU_CORE_ace_master_a53_inst_addr                                      "0x0035"
#define  set_SCPU_CORE_ace_master_a53_reg(data)                                  (*((volatile unsigned int*)SCPU_CORE_ace_master_a53_reg)=data)
#define  get_SCPU_CORE_ace_master_a53_reg                                        (*((volatile unsigned int*)SCPU_CORE_ace_master_a53_reg))
#define  SCPU_CORE_ace_master_a53_a53l2flushreq_shift                            (1)
#define  SCPU_CORE_ace_master_a53_a53l2flushreq_mask                             (0x00000002)
#define  SCPU_CORE_ace_master_a53_a53l2flushreq(data)                            (0x00000002&((data)<<1))
#define  SCPU_CORE_ace_master_a53_get_a53l2flushreq(data)                        ((0x00000002&(data))>>1)

#define  SCPU_CORE_auth_slave_a53                                                0x1805B824
#define  SCPU_CORE_auth_slave_a53_reg_addr                                       "0xB805B824"
#define  SCPU_CORE_auth_slave_a53_reg                                            0xB805B824
#define  SCPU_CORE_auth_slave_a53_inst_addr                                      "0x0036"
#define  set_SCPU_CORE_auth_slave_a53_reg(data)                                  (*((volatile unsigned int*)SCPU_CORE_auth_slave_a53_reg)=data)
#define  get_SCPU_CORE_auth_slave_a53_reg                                        (*((volatile unsigned int*)SCPU_CORE_auth_slave_a53_reg))
#define  SCPU_CORE_auth_slave_a53_dbgen_auth_slave_a53_source_sel_shift          (3)
#define  SCPU_CORE_auth_slave_a53_niden_auth_slave_a53_source_sel_shift          (2)
#define  SCPU_CORE_auth_slave_a53_spiden_auth_slave_a53_source_sel_shift         (1)
#define  SCPU_CORE_auth_slave_a53_spniden_auth_slave_a53_source_sel_shift        (0)
#define  SCPU_CORE_auth_slave_a53_dbgen_auth_slave_a53_source_sel_mask           (0x00000008)
#define  SCPU_CORE_auth_slave_a53_niden_auth_slave_a53_source_sel_mask           (0x00000004)
#define  SCPU_CORE_auth_slave_a53_spiden_auth_slave_a53_source_sel_mask          (0x00000002)
#define  SCPU_CORE_auth_slave_a53_spniden_auth_slave_a53_source_sel_mask         (0x00000001)
#define  SCPU_CORE_auth_slave_a53_dbgen_auth_slave_a53_source_sel(data)          (0x00000008&((data)<<3))
#define  SCPU_CORE_auth_slave_a53_niden_auth_slave_a53_source_sel(data)          (0x00000004&((data)<<2))
#define  SCPU_CORE_auth_slave_a53_spiden_auth_slave_a53_source_sel(data)         (0x00000002&((data)<<1))
#define  SCPU_CORE_auth_slave_a53_spniden_auth_slave_a53_source_sel(data)        (0x00000001&(data))
#define  SCPU_CORE_auth_slave_a53_get_dbgen_auth_slave_a53_source_sel(data)      ((0x00000008&(data))>>3)
#define  SCPU_CORE_auth_slave_a53_get_niden_auth_slave_a53_source_sel(data)      ((0x00000004&(data))>>2)
#define  SCPU_CORE_auth_slave_a53_get_spiden_auth_slave_a53_source_sel(data)     ((0x00000002&(data))>>1)
#define  SCPU_CORE_auth_slave_a53_get_spniden_auth_slave_a53_source_sel(data)    (0x00000001&(data))

#define  SCPU_CORE_config_a53_0                                                  0x1805B828
#define  SCPU_CORE_config_a53_0_reg_addr                                         "0xB805B828"
#define  SCPU_CORE_config_a53_0_reg                                              0xB805B828
#define  SCPU_CORE_config_a53_0_inst_addr                                        "0x0037"
#define  set_SCPU_CORE_config_a53_0_reg(data)                                    (*((volatile unsigned int*)SCPU_CORE_config_a53_0_reg)=data)
#define  get_SCPU_CORE_config_a53_0_reg                                          (*((volatile unsigned int*)SCPU_CORE_config_a53_0_reg))
#define  SCPU_CORE_config_a53_0_a53dbgpwrdup_shift                               (15)
#define  SCPU_CORE_config_a53_0_a53dbgl1rstdisable_shift                         (14)
#define  SCPU_CORE_config_a53_0_a53cfgend_shift                                  (12)
#define  SCPU_CORE_config_a53_0_a53cfgte_shift                                   (10)
#define  SCPU_CORE_config_a53_0_a53cp15sdisable_shift                            (8)
#define  SCPU_CORE_config_a53_0_a53l2rstdisable_shift                            (6)
#define  SCPU_CORE_config_a53_0_a53vinithi_shift                                 (4)
#define  SCPU_CORE_config_a53_0_a53aa64naa32_shift                               (2)
#define  SCPU_CORE_config_a53_0_a53cryptodisable_shift                           (0)
#define  SCPU_CORE_config_a53_0_a53dbgpwrdup_mask                                (0x00018000)
#define  SCPU_CORE_config_a53_0_a53dbgl1rstdisable_mask                          (0x00004000)
#define  SCPU_CORE_config_a53_0_a53cfgend_mask                                   (0x00003000)
#define  SCPU_CORE_config_a53_0_a53cfgte_mask                                    (0x00000C00)
#define  SCPU_CORE_config_a53_0_a53cp15sdisable_mask                             (0x00000300)
#define  SCPU_CORE_config_a53_0_a53l2rstdisable_mask                             (0x00000040)
#define  SCPU_CORE_config_a53_0_a53vinithi_mask                                  (0x00000030)
#define  SCPU_CORE_config_a53_0_a53aa64naa32_mask                                (0x0000000C)
#define  SCPU_CORE_config_a53_0_a53cryptodisable_mask                            (0x00000003)
#define  SCPU_CORE_config_a53_0_a53dbgpwrdup(data)                               (0x00018000&((data)<<15))
#define  SCPU_CORE_config_a53_0_a53dbgl1rstdisable(data)                         (0x00004000&((data)<<14))
#define  SCPU_CORE_config_a53_0_a53cfgend(data)                                  (0x00003000&((data)<<12))
#define  SCPU_CORE_config_a53_0_a53cfgte(data)                                   (0x00000C00&((data)<<10))
#define  SCPU_CORE_config_a53_0_a53cp15sdisable(data)                            (0x00000300&((data)<<8))
#define  SCPU_CORE_config_a53_0_a53l2rstdisable(data)                            (0x00000040&((data)<<6))
#define  SCPU_CORE_config_a53_0_a53vinithi(data)                                 (0x00000030&((data)<<4))
#define  SCPU_CORE_config_a53_0_a53aa64naa32(data)                               (0x0000000C&((data)<<2))
#define  SCPU_CORE_config_a53_0_a53cryptodisable(data)                           (0x00000003&(data))
#define  SCPU_CORE_config_a53_0_get_a53dbgpwrdup(data)                           ((0x00018000&(data))>>15)
#define  SCPU_CORE_config_a53_0_get_a53dbgl1rstdisable(data)                     ((0x00004000&(data))>>14)
#define  SCPU_CORE_config_a53_0_get_a53cfgend(data)                              ((0x00003000&(data))>>12)
#define  SCPU_CORE_config_a53_0_get_a53cfgte(data)                               ((0x00000C00&(data))>>10)
#define  SCPU_CORE_config_a53_0_get_a53cp15sdisable(data)                        ((0x00000300&(data))>>8)
#define  SCPU_CORE_config_a53_0_get_a53l2rstdisable(data)                        ((0x00000040&(data))>>6)
#define  SCPU_CORE_config_a53_0_get_a53vinithi(data)                             ((0x00000030&(data))>>4)
#define  SCPU_CORE_config_a53_0_get_a53aa64naa32(data)                           ((0x0000000C&(data))>>2)
#define  SCPU_CORE_config_a53_0_get_a53cryptodisable(data)                       (0x00000003&(data))

#define  SCPU_CORE_config_a53_1                                                  0x1805B82C
#define  SCPU_CORE_config_a53_1_reg_addr                                         "0xB805B82C"
#define  SCPU_CORE_config_a53_1_reg                                              0xB805B82C
#define  SCPU_CORE_config_a53_1_inst_addr                                        "0x0038"
#define  set_SCPU_CORE_config_a53_1_reg(data)                                    (*((volatile unsigned int*)SCPU_CORE_config_a53_1_reg)=data)
#define  get_SCPU_CORE_config_a53_1_reg                                          (*((volatile unsigned int*)SCPU_CORE_config_a53_1_reg))
#define  SCPU_CORE_config_a53_1_a53rvbaraddr0_39_32_shift                        (0)
#define  SCPU_CORE_config_a53_1_a53rvbaraddr0_39_32_mask                         (0x000000FF)
#define  SCPU_CORE_config_a53_1_a53rvbaraddr0_39_32(data)                        (0x000000FF&(data))
#define  SCPU_CORE_config_a53_1_get_a53rvbaraddr0_39_32(data)                    (0x000000FF&(data))

#define  SCPU_CORE_config_a53_2                                                  0x1805B830
#define  SCPU_CORE_config_a53_2_reg_addr                                         "0xB805B830"
#define  SCPU_CORE_config_a53_2_reg                                              0xB805B830
#define  SCPU_CORE_config_a53_2_inst_addr                                        "0x0039"
#define  set_SCPU_CORE_config_a53_2_reg(data)                                    (*((volatile unsigned int*)SCPU_CORE_config_a53_2_reg)=data)
#define  get_SCPU_CORE_config_a53_2_reg                                          (*((volatile unsigned int*)SCPU_CORE_config_a53_2_reg))
#define  SCPU_CORE_config_a53_2_a53rvbaraddr0_31_2_shift                         (2)
#define  SCPU_CORE_config_a53_2_a53rvbaraddr0_31_2_mask                          (0xFFFFFFFC)
#define  SCPU_CORE_config_a53_2_a53rvbaraddr0_31_2(data)                         (0xFFFFFFFC&((data)<<2))
#define  SCPU_CORE_config_a53_2_get_a53rvbaraddr0_31_2(data)                     ((0xFFFFFFFC&(data))>>2)

#define  SCPU_CORE_config_a53_3                                                  0x1805B834
#define  SCPU_CORE_config_a53_3_reg_addr                                         "0xB805B834"
#define  SCPU_CORE_config_a53_3_reg                                              0xB805B834
#define  SCPU_CORE_config_a53_3_inst_addr                                        "0x003A"
#define  set_SCPU_CORE_config_a53_3_reg(data)                                    (*((volatile unsigned int*)SCPU_CORE_config_a53_3_reg)=data)
#define  get_SCPU_CORE_config_a53_3_reg                                          (*((volatile unsigned int*)SCPU_CORE_config_a53_3_reg))
#define  SCPU_CORE_config_a53_3_a53rvbaraddr1_39_32_shift                        (0)
#define  SCPU_CORE_config_a53_3_a53rvbaraddr1_39_32_mask                         (0x000000FF)
#define  SCPU_CORE_config_a53_3_a53rvbaraddr1_39_32(data)                        (0x000000FF&(data))
#define  SCPU_CORE_config_a53_3_get_a53rvbaraddr1_39_32(data)                    (0x000000FF&(data))

#define  SCPU_CORE_config_a53_4                                                  0x1805B838
#define  SCPU_CORE_config_a53_4_reg_addr                                         "0xB805B838"
#define  SCPU_CORE_config_a53_4_reg                                              0xB805B838
#define  SCPU_CORE_config_a53_4_inst_addr                                        "0x003B"
#define  set_SCPU_CORE_config_a53_4_reg(data)                                    (*((volatile unsigned int*)SCPU_CORE_config_a53_4_reg)=data)
#define  get_SCPU_CORE_config_a53_4_reg                                          (*((volatile unsigned int*)SCPU_CORE_config_a53_4_reg))
#define  SCPU_CORE_config_a53_4_a53rvbaraddr1_31_2_shift                         (2)
#define  SCPU_CORE_config_a53_4_a53rvbaraddr1_31_2_mask                          (0xFFFFFFFC)
#define  SCPU_CORE_config_a53_4_a53rvbaraddr1_31_2(data)                         (0xFFFFFFFC&((data)<<2))
#define  SCPU_CORE_config_a53_4_get_a53rvbaraddr1_31_2(data)                     ((0xFFFFFFFC&(data))>>2)

#define  SCPU_CORE_status_a53_0                                                  0x1805B83C
#define  SCPU_CORE_status_a53_0_reg_addr                                         "0xB805B83C"
#define  SCPU_CORE_status_a53_0_reg                                              0xB805B83C
#define  SCPU_CORE_status_a53_0_inst_addr                                        "0x003C"
#define  set_SCPU_CORE_status_a53_0_reg(data)                                    (*((volatile unsigned int*)SCPU_CORE_status_a53_0_reg)=data)
#define  get_SCPU_CORE_status_a53_0_reg                                          (*((volatile unsigned int*)SCPU_CORE_status_a53_0_reg))
#define  SCPU_CORE_status_a53_0_a53l2flushdone_shift                             (7)
#define  SCPU_CORE_status_a53_0_a53smpen_shift                                   (5)
#define  SCPU_CORE_status_a53_0_a53standbywfe_shift                              (3)
#define  SCPU_CORE_status_a53_0_a53standbywfi_shift                              (1)
#define  SCPU_CORE_status_a53_0_a53standbywfil2_shift                            (0)
#define  SCPU_CORE_status_a53_0_a53l2flushdone_mask                              (0x00000080)
#define  SCPU_CORE_status_a53_0_a53smpen_mask                                    (0x00000060)
#define  SCPU_CORE_status_a53_0_a53standbywfe_mask                               (0x00000018)
#define  SCPU_CORE_status_a53_0_a53standbywfi_mask                               (0x00000006)
#define  SCPU_CORE_status_a53_0_a53standbywfil2_mask                             (0x00000001)
#define  SCPU_CORE_status_a53_0_a53l2flushdone(data)                             (0x00000080&((data)<<7))
#define  SCPU_CORE_status_a53_0_a53smpen(data)                                   (0x00000060&((data)<<5))
#define  SCPU_CORE_status_a53_0_a53standbywfe(data)                              (0x00000018&((data)<<3))
#define  SCPU_CORE_status_a53_0_a53standbywfi(data)                              (0x00000006&((data)<<1))
#define  SCPU_CORE_status_a53_0_a53standbywfil2(data)                            (0x00000001&(data))
#define  SCPU_CORE_status_a53_0_get_a53l2flushdone(data)                         ((0x00000080&(data))>>7)
#define  SCPU_CORE_status_a53_0_get_a53smpen(data)                               ((0x00000060&(data))>>5)
#define  SCPU_CORE_status_a53_0_get_a53standbywfe(data)                          ((0x00000018&(data))>>3)
#define  SCPU_CORE_status_a53_0_get_a53standbywfi(data)                          ((0x00000006&(data))>>1)
#define  SCPU_CORE_status_a53_0_get_a53standbywfil2(data)                        (0x00000001&(data))

#define  SCPU_CORE_status_a53_1                                                  0x1805B840
#define  SCPU_CORE_status_a53_1_reg_addr                                         "0xB805B840"
#define  SCPU_CORE_status_a53_1_reg                                              0xB805B840
#define  SCPU_CORE_status_a53_1_inst_addr                                        "0x003D"
#define  set_SCPU_CORE_status_a53_1_reg(data)                                    (*((volatile unsigned int*)SCPU_CORE_status_a53_1_reg)=data)
#define  get_SCPU_CORE_status_a53_1_reg                                          (*((volatile unsigned int*)SCPU_CORE_status_a53_1_reg))
#define  SCPU_CORE_status_a53_1_a53pmuevent0_shift                               (0)
#define  SCPU_CORE_status_a53_1_a53pmuevent0_mask                                (0x3FFFFFFF)
#define  SCPU_CORE_status_a53_1_a53pmuevent0(data)                               (0x3FFFFFFF&(data))
#define  SCPU_CORE_status_a53_1_get_a53pmuevent0(data)                           (0x3FFFFFFF&(data))

#define  SCPU_CORE_status_a53_2                                                  0x1805B844
#define  SCPU_CORE_status_a53_2_reg_addr                                         "0xB805B844"
#define  SCPU_CORE_status_a53_2_reg                                              0xB805B844
#define  SCPU_CORE_status_a53_2_inst_addr                                        "0x003E"
#define  set_SCPU_CORE_status_a53_2_reg(data)                                    (*((volatile unsigned int*)SCPU_CORE_status_a53_2_reg)=data)
#define  get_SCPU_CORE_status_a53_2_reg                                          (*((volatile unsigned int*)SCPU_CORE_status_a53_2_reg))
#define  SCPU_CORE_status_a53_2_a53pmuevent1_shift                               (0)
#define  SCPU_CORE_status_a53_2_a53pmuevent1_mask                                (0x3FFFFFFF)
#define  SCPU_CORE_status_a53_2_a53pmuevent1(data)                               (0x3FFFFFFF&(data))
#define  SCPU_CORE_status_a53_2_get_a53pmuevent1(data)                           (0x3FFFFFFF&(data))

#define  SCPU_CORE_power_a53_0                                                   0x1805B848
#define  SCPU_CORE_power_a53_0_reg_addr                                          "0xB805B848"
#define  SCPU_CORE_power_a53_0_reg                                               0xB805B848
#define  SCPU_CORE_power_a53_0_inst_addr                                         "0x003F"
#define  set_SCPU_CORE_power_a53_0_reg(data)                                     (*((volatile unsigned int*)SCPU_CORE_power_a53_0_reg)=data)
#define  get_SCPU_CORE_power_a53_0_reg                                           (*((volatile unsigned int*)SCPU_CORE_power_a53_0_reg))
#define  SCPU_CORE_power_a53_0_a53dbgnopwrdwn_shift                              (2)
#define  SCPU_CORE_power_a53_0_a53dbgpwrupreq_shift                              (0)
#define  SCPU_CORE_power_a53_0_a53dbgnopwrdwn_mask                               (0x0000000C)
#define  SCPU_CORE_power_a53_0_a53dbgpwrupreq_mask                               (0x00000003)
#define  SCPU_CORE_power_a53_0_a53dbgnopwrdwn(data)                              (0x0000000C&((data)<<2))
#define  SCPU_CORE_power_a53_0_a53dbgpwrupreq(data)                              (0x00000003&(data))
#define  SCPU_CORE_power_a53_0_get_a53dbgnopwrdwn(data)                          ((0x0000000C&(data))>>2)
#define  SCPU_CORE_power_a53_0_get_a53dbgpwrupreq(data)                          (0x00000003&(data))

#define  SCPU_CORE_misc_a53_0                                                    0x1805B84C
#define  SCPU_CORE_misc_a53_0_reg_addr                                           "0xB805B84C"
#define  SCPU_CORE_misc_a53_0_reg                                                0xB805B84C
#define  SCPU_CORE_misc_a53_0_inst_addr                                          "0x0040"
#define  set_SCPU_CORE_misc_a53_0_reg(data)                                      (*((volatile unsigned int*)SCPU_CORE_misc_a53_0_reg)=data)
#define  get_SCPU_CORE_misc_a53_0_reg                                            (*((volatile unsigned int*)SCPU_CORE_misc_a53_0_reg))
#define  SCPU_CORE_misc_a53_0_a53dbgrstreq_shift                                 (2)
#define  SCPU_CORE_misc_a53_0_a53warmrstreq_shift                                (0)
#define  SCPU_CORE_misc_a53_0_a53dbgrstreq_mask                                  (0x0000000C)
#define  SCPU_CORE_misc_a53_0_a53warmrstreq_mask                                 (0x00000003)
#define  SCPU_CORE_misc_a53_0_a53dbgrstreq(data)                                 (0x0000000C&((data)<<2))
#define  SCPU_CORE_misc_a53_0_a53warmrstreq(data)                                (0x00000003&(data))
#define  SCPU_CORE_misc_a53_0_get_a53dbgrstreq(data)                             ((0x0000000C&(data))>>2)
#define  SCPU_CORE_misc_a53_0_get_a53warmrstreq(data)                            (0x00000003&(data))

#define  SCPU_CORE_config_a53_5                                                  0x1805B888
#define  SCPU_CORE_config_a53_5_reg_addr                                         "0xB805B888"
#define  SCPU_CORE_config_a53_5_reg                                              0xB805B888
#define  SCPU_CORE_config_a53_5_inst_addr                                        "0x0041"
#define  set_SCPU_CORE_config_a53_5_reg(data)                                    (*((volatile unsigned int*)SCPU_CORE_config_a53_5_reg)=data)
#define  get_SCPU_CORE_config_a53_5_reg                                          (*((volatile unsigned int*)SCPU_CORE_config_a53_5_reg))
#define  SCPU_CORE_config_a53_5_a53dbgpwrdup_3_2_shift                           (15)
#define  SCPU_CORE_config_a53_5_a53cfgend_3_2_shift                              (12)
#define  SCPU_CORE_config_a53_5_a53cfgte_3_2_shift                               (10)
#define  SCPU_CORE_config_a53_5_a53cp15sdisable_3_2_shift                        (8)
#define  SCPU_CORE_config_a53_5_a53vinithi_3_2_shift                             (4)
#define  SCPU_CORE_config_a53_5_a53aa64naa32_3_2_shift                           (2)
#define  SCPU_CORE_config_a53_5_a53cryptodisable_3_2_shift                       (0)
#define  SCPU_CORE_config_a53_5_a53dbgpwrdup_3_2_mask                            (0x00018000)
#define  SCPU_CORE_config_a53_5_a53cfgend_3_2_mask                               (0x00003000)
#define  SCPU_CORE_config_a53_5_a53cfgte_3_2_mask                                (0x00000C00)
#define  SCPU_CORE_config_a53_5_a53cp15sdisable_3_2_mask                         (0x00000300)
#define  SCPU_CORE_config_a53_5_a53vinithi_3_2_mask                              (0x00000030)
#define  SCPU_CORE_config_a53_5_a53aa64naa32_3_2_mask                            (0x0000000C)
#define  SCPU_CORE_config_a53_5_a53cryptodisable_3_2_mask                        (0x00000003)
#define  SCPU_CORE_config_a53_5_a53dbgpwrdup_3_2(data)                           (0x00018000&((data)<<15))
#define  SCPU_CORE_config_a53_5_a53cfgend_3_2(data)                              (0x00003000&((data)<<12))
#define  SCPU_CORE_config_a53_5_a53cfgte_3_2(data)                               (0x00000C00&((data)<<10))
#define  SCPU_CORE_config_a53_5_a53cp15sdisable_3_2(data)                        (0x00000300&((data)<<8))
#define  SCPU_CORE_config_a53_5_a53vinithi_3_2(data)                             (0x00000030&((data)<<4))
#define  SCPU_CORE_config_a53_5_a53aa64naa32_3_2(data)                           (0x0000000C&((data)<<2))
#define  SCPU_CORE_config_a53_5_a53cryptodisable_3_2(data)                       (0x00000003&(data))
#define  SCPU_CORE_config_a53_5_get_a53dbgpwrdup_3_2(data)                       ((0x00018000&(data))>>15)
#define  SCPU_CORE_config_a53_5_get_a53cfgend_3_2(data)                          ((0x00003000&(data))>>12)
#define  SCPU_CORE_config_a53_5_get_a53cfgte_3_2(data)                           ((0x00000C00&(data))>>10)
#define  SCPU_CORE_config_a53_5_get_a53cp15sdisable_3_2(data)                    ((0x00000300&(data))>>8)
#define  SCPU_CORE_config_a53_5_get_a53vinithi_3_2(data)                         ((0x00000030&(data))>>4)
#define  SCPU_CORE_config_a53_5_get_a53aa64naa32_3_2(data)                       ((0x0000000C&(data))>>2)
#define  SCPU_CORE_config_a53_5_get_a53cryptodisable_3_2(data)                   (0x00000003&(data))

#define  SCPU_CORE_config_a53_6                                                  0x1805B88C
#define  SCPU_CORE_config_a53_6_reg_addr                                         "0xB805B88C"
#define  SCPU_CORE_config_a53_6_reg                                              0xB805B88C
#define  SCPU_CORE_config_a53_6_inst_addr                                        "0x0042"
#define  set_SCPU_CORE_config_a53_6_reg(data)                                    (*((volatile unsigned int*)SCPU_CORE_config_a53_6_reg)=data)
#define  get_SCPU_CORE_config_a53_6_reg                                          (*((volatile unsigned int*)SCPU_CORE_config_a53_6_reg))
#define  SCPU_CORE_config_a53_6_a53rvbaraddr2_39_32_shift                        (0)
#define  SCPU_CORE_config_a53_6_a53rvbaraddr2_39_32_mask                         (0x000000FF)
#define  SCPU_CORE_config_a53_6_a53rvbaraddr2_39_32(data)                        (0x000000FF&(data))
#define  SCPU_CORE_config_a53_6_get_a53rvbaraddr2_39_32(data)                    (0x000000FF&(data))

#define  SCPU_CORE_config_a53_7                                                  0x1805B890
#define  SCPU_CORE_config_a53_7_reg_addr                                         "0xB805B890"
#define  SCPU_CORE_config_a53_7_reg                                              0xB805B890
#define  SCPU_CORE_config_a53_7_inst_addr                                        "0x0043"
#define  set_SCPU_CORE_config_a53_7_reg(data)                                    (*((volatile unsigned int*)SCPU_CORE_config_a53_7_reg)=data)
#define  get_SCPU_CORE_config_a53_7_reg                                          (*((volatile unsigned int*)SCPU_CORE_config_a53_7_reg))
#define  SCPU_CORE_config_a53_7_a53rvbaraddr2_31_2_shift                         (2)
#define  SCPU_CORE_config_a53_7_a53rvbaraddr2_31_2_mask                          (0xFFFFFFFC)
#define  SCPU_CORE_config_a53_7_a53rvbaraddr2_31_2(data)                         (0xFFFFFFFC&((data)<<2))
#define  SCPU_CORE_config_a53_7_get_a53rvbaraddr2_31_2(data)                     ((0xFFFFFFFC&(data))>>2)

#define  SCPU_CORE_config_a53_8                                                  0x1805B894
#define  SCPU_CORE_config_a53_8_reg_addr                                         "0xB805B894"
#define  SCPU_CORE_config_a53_8_reg                                              0xB805B894
#define  SCPU_CORE_config_a53_8_inst_addr                                        "0x0044"
#define  set_SCPU_CORE_config_a53_8_reg(data)                                    (*((volatile unsigned int*)SCPU_CORE_config_a53_8_reg)=data)
#define  get_SCPU_CORE_config_a53_8_reg                                          (*((volatile unsigned int*)SCPU_CORE_config_a53_8_reg))
#define  SCPU_CORE_config_a53_8_a53rvbaraddr3_39_32_shift                        (0)
#define  SCPU_CORE_config_a53_8_a53rvbaraddr3_39_32_mask                         (0x000000FF)
#define  SCPU_CORE_config_a53_8_a53rvbaraddr3_39_32(data)                        (0x000000FF&(data))
#define  SCPU_CORE_config_a53_8_get_a53rvbaraddr3_39_32(data)                    (0x000000FF&(data))

#define  SCPU_CORE_config_a53_9                                                  0x1805B898
#define  SCPU_CORE_config_a53_9_reg_addr                                         "0xB805B898"
#define  SCPU_CORE_config_a53_9_reg                                              0xB805B898
#define  SCPU_CORE_config_a53_9_inst_addr                                        "0x0045"
#define  set_SCPU_CORE_config_a53_9_reg(data)                                    (*((volatile unsigned int*)SCPU_CORE_config_a53_9_reg)=data)
#define  get_SCPU_CORE_config_a53_9_reg                                          (*((volatile unsigned int*)SCPU_CORE_config_a53_9_reg))
#define  SCPU_CORE_config_a53_9_a53rvbaraddr3_31_2_shift                         (2)
#define  SCPU_CORE_config_a53_9_a53rvbaraddr3_31_2_mask                          (0xFFFFFFFC)
#define  SCPU_CORE_config_a53_9_a53rvbaraddr3_31_2(data)                         (0xFFFFFFFC&((data)<<2))
#define  SCPU_CORE_config_a53_9_get_a53rvbaraddr3_31_2(data)                     ((0xFFFFFFFC&(data))>>2)

#define  SCPU_CORE_status_a53_3                                                  0x1805B89C
#define  SCPU_CORE_status_a53_3_reg_addr                                         "0xB805B89C"
#define  SCPU_CORE_status_a53_3_reg                                              0xB805B89C
#define  SCPU_CORE_status_a53_3_inst_addr                                        "0x0046"
#define  set_SCPU_CORE_status_a53_3_reg(data)                                    (*((volatile unsigned int*)SCPU_CORE_status_a53_3_reg)=data)
#define  get_SCPU_CORE_status_a53_3_reg                                          (*((volatile unsigned int*)SCPU_CORE_status_a53_3_reg))
#define  SCPU_CORE_status_a53_3_a53smpen_3_2_shift                               (9)
#define  SCPU_CORE_status_a53_3_a53standbywfe_3_2_shift                          (3)
#define  SCPU_CORE_status_a53_3_a53standbywfi_3_2_shift                          (1)
#define  SCPU_CORE_status_a53_3_a53smpen_3_2_mask                                (0x00000600)
#define  SCPU_CORE_status_a53_3_a53standbywfe_3_2_mask                           (0x00000018)
#define  SCPU_CORE_status_a53_3_a53standbywfi_3_2_mask                           (0x00000006)
#define  SCPU_CORE_status_a53_3_a53smpen_3_2(data)                               (0x00000600&((data)<<9))
#define  SCPU_CORE_status_a53_3_a53standbywfe_3_2(data)                          (0x00000018&((data)<<3))
#define  SCPU_CORE_status_a53_3_a53standbywfi_3_2(data)                          (0x00000006&((data)<<1))
#define  SCPU_CORE_status_a53_3_get_a53smpen_3_2(data)                           ((0x00000600&(data))>>9)
#define  SCPU_CORE_status_a53_3_get_a53standbywfe_3_2(data)                      ((0x00000018&(data))>>3)
#define  SCPU_CORE_status_a53_3_get_a53standbywfi_3_2(data)                      ((0x00000006&(data))>>1)

#define  SCPU_CORE_status_a53_4                                                  0x1805B8A0
#define  SCPU_CORE_status_a53_4_reg_addr                                         "0xB805B8A0"
#define  SCPU_CORE_status_a53_4_reg                                              0xB805B8A0
#define  SCPU_CORE_status_a53_4_inst_addr                                        "0x0047"
#define  set_SCPU_CORE_status_a53_4_reg(data)                                    (*((volatile unsigned int*)SCPU_CORE_status_a53_4_reg)=data)
#define  get_SCPU_CORE_status_a53_4_reg                                          (*((volatile unsigned int*)SCPU_CORE_status_a53_4_reg))
#define  SCPU_CORE_status_a53_4_a53pmuevent2_shift                               (0)
#define  SCPU_CORE_status_a53_4_a53pmuevent2_mask                                (0x3FFFFFFF)
#define  SCPU_CORE_status_a53_4_a53pmuevent2(data)                               (0x3FFFFFFF&(data))
#define  SCPU_CORE_status_a53_4_get_a53pmuevent2(data)                           (0x3FFFFFFF&(data))

#define  SCPU_CORE_status_a53_5                                                  0x1805B8A4
#define  SCPU_CORE_status_a53_5_reg_addr                                         "0xB805B8A4"
#define  SCPU_CORE_status_a53_5_reg                                              0xB805B8A4
#define  SCPU_CORE_status_a53_5_inst_addr                                        "0x0048"
#define  set_SCPU_CORE_status_a53_5_reg(data)                                    (*((volatile unsigned int*)SCPU_CORE_status_a53_5_reg)=data)
#define  get_SCPU_CORE_status_a53_5_reg                                          (*((volatile unsigned int*)SCPU_CORE_status_a53_5_reg))
#define  SCPU_CORE_status_a53_5_a53pmuevent3_shift                               (0)
#define  SCPU_CORE_status_a53_5_a53pmuevent3_mask                                (0x3FFFFFFF)
#define  SCPU_CORE_status_a53_5_a53pmuevent3(data)                               (0x3FFFFFFF&(data))
#define  SCPU_CORE_status_a53_5_get_a53pmuevent3(data)                           (0x3FFFFFFF&(data))

#define  SCPU_CORE_power_a53_1                                                   0x1805B8A8
#define  SCPU_CORE_power_a53_1_reg_addr                                          "0xB805B8A8"
#define  SCPU_CORE_power_a53_1_reg                                               0xB805B8A8
#define  SCPU_CORE_power_a53_1_inst_addr                                         "0x0049"
#define  set_SCPU_CORE_power_a53_1_reg(data)                                     (*((volatile unsigned int*)SCPU_CORE_power_a53_1_reg)=data)
#define  get_SCPU_CORE_power_a53_1_reg                                           (*((volatile unsigned int*)SCPU_CORE_power_a53_1_reg))
#define  SCPU_CORE_power_a53_1_a53dbgnopwrdwn_3_2_shift                          (2)
#define  SCPU_CORE_power_a53_1_a53dbgpwrupreq_3_2_shift                          (0)
#define  SCPU_CORE_power_a53_1_a53dbgnopwrdwn_3_2_mask                           (0x0000000C)
#define  SCPU_CORE_power_a53_1_a53dbgpwrupreq_3_2_mask                           (0x00000003)
#define  SCPU_CORE_power_a53_1_a53dbgnopwrdwn_3_2(data)                          (0x0000000C&((data)<<2))
#define  SCPU_CORE_power_a53_1_a53dbgpwrupreq_3_2(data)                          (0x00000003&(data))
#define  SCPU_CORE_power_a53_1_get_a53dbgnopwrdwn_3_2(data)                      ((0x0000000C&(data))>>2)
#define  SCPU_CORE_power_a53_1_get_a53dbgpwrupreq_3_2(data)                      (0x00000003&(data))

#define  SCPU_CORE_misc_a53_1                                                    0x1805B8AC
#define  SCPU_CORE_misc_a53_1_reg_addr                                           "0xB805B8AC"
#define  SCPU_CORE_misc_a53_1_reg                                                0xB805B8AC
#define  SCPU_CORE_misc_a53_1_inst_addr                                          "0x004A"
#define  set_SCPU_CORE_misc_a53_1_reg(data)                                      (*((volatile unsigned int*)SCPU_CORE_misc_a53_1_reg)=data)
#define  get_SCPU_CORE_misc_a53_1_reg                                            (*((volatile unsigned int*)SCPU_CORE_misc_a53_1_reg))
#define  SCPU_CORE_misc_a53_1_a53dbgrstreq_3_2_shift                             (2)
#define  SCPU_CORE_misc_a53_1_a53warmrstreq_3_2_shift                            (0)
#define  SCPU_CORE_misc_a53_1_a53dbgrstreq_3_2_mask                              (0x0000000C)
#define  SCPU_CORE_misc_a53_1_a53warmrstreq_3_2_mask                             (0x00000003)
#define  SCPU_CORE_misc_a53_1_a53dbgrstreq_3_2(data)                             (0x0000000C&((data)<<2))
#define  SCPU_CORE_misc_a53_1_a53warmrstreq_3_2(data)                            (0x00000003&(data))
#define  SCPU_CORE_misc_a53_1_get_a53dbgrstreq_3_2(data)                         ((0x0000000C&(data))>>2)
#define  SCPU_CORE_misc_a53_1_get_a53warmrstreq_3_2(data)                        (0x00000003&(data))

#define  SCPU_CORE_cs_ctrl_0                                                     0x1805B8C0
#define  SCPU_CORE_cs_ctrl_0_reg_addr                                            "0xB805B8C0"
#define  SCPU_CORE_cs_ctrl_0_reg                                                 0xB805B8C0
#define  SCPU_CORE_cs_ctrl_0_inst_addr                                           "0x004B"
#define  set_SCPU_CORE_cs_ctrl_0_reg(data)                                       (*((volatile unsigned int*)SCPU_CORE_cs_ctrl_0_reg)=data)
#define  get_SCPU_CORE_cs_ctrl_0_reg                                             (*((volatile unsigned int*)SCPU_CORE_cs_ctrl_0_reg))
#define  SCPU_CORE_cs_ctrl_0_a53_trace_tpctl_shift                               (9)
#define  SCPU_CORE_cs_ctrl_0_a53_trace_tpmaxdatasize_shift                       (4)
#define  SCPU_CORE_cs_ctrl_0_dbgen_authenticationinterface_cssys_shift           (1)
#define  SCPU_CORE_cs_ctrl_0_niden_authenticationinterface_cssys_shift           (0)
#define  SCPU_CORE_cs_ctrl_0_a53_trace_tpctl_mask                                (0x00000200)
#define  SCPU_CORE_cs_ctrl_0_a53_trace_tpmaxdatasize_mask                        (0x000001F0)
#define  SCPU_CORE_cs_ctrl_0_dbgen_authenticationinterface_cssys_mask            (0x00000002)
#define  SCPU_CORE_cs_ctrl_0_niden_authenticationinterface_cssys_mask            (0x00000001)
#define  SCPU_CORE_cs_ctrl_0_a53_trace_tpctl(data)                               (0x00000200&((data)<<9))
#define  SCPU_CORE_cs_ctrl_0_a53_trace_tpmaxdatasize(data)                       (0x000001F0&((data)<<4))
#define  SCPU_CORE_cs_ctrl_0_dbgen_authenticationinterface_cssys(data)           (0x00000002&((data)<<1))
#define  SCPU_CORE_cs_ctrl_0_niden_authenticationinterface_cssys(data)           (0x00000001&(data))
#define  SCPU_CORE_cs_ctrl_0_get_a53_trace_tpctl(data)                           ((0x00000200&(data))>>9)
#define  SCPU_CORE_cs_ctrl_0_get_a53_trace_tpmaxdatasize(data)                   ((0x000001F0&(data))>>4)
#define  SCPU_CORE_cs_ctrl_0_get_dbgen_authenticationinterface_cssys(data)       ((0x00000002&(data))>>1)
#define  SCPU_CORE_cs_ctrl_0_get_niden_authenticationinterface_cssys(data)       (0x00000001&(data))

#define  SCPU_CORE_ejtag_ctrl_0                                                  0x1805B8C4
#define  SCPU_CORE_ejtag_ctrl_0_reg_addr                                         "0xB805B8C4"
#define  SCPU_CORE_ejtag_ctrl_0_reg                                              0xB805B8C4
#define  SCPU_CORE_ejtag_ctrl_0_inst_addr                                        "0x004C"
#define  set_SCPU_CORE_ejtag_ctrl_0_reg(data)                                    (*((volatile unsigned int*)SCPU_CORE_ejtag_ctrl_0_reg)=data)
#define  get_SCPU_CORE_ejtag_ctrl_0_reg                                          (*((volatile unsigned int*)SCPU_CORE_ejtag_ctrl_0_reg))
#define  SCPU_CORE_ejtag_ctrl_0_ejtag_chain_mode_shift                           (24)
#define  SCPU_CORE_ejtag_ctrl_0_srstconnected_shift                              (16)
#define  SCPU_CORE_ejtag_ctrl_0_portenabled_shift                                (8)
#define  SCPU_CORE_ejtag_ctrl_0_portconnected_shift                              (0)
#define  SCPU_CORE_ejtag_ctrl_0_ejtag_chain_mode_mask                            (0x01000000)
#define  SCPU_CORE_ejtag_ctrl_0_srstconnected_mask                               (0x00FF0000)
#define  SCPU_CORE_ejtag_ctrl_0_portenabled_mask                                 (0x0000FF00)
#define  SCPU_CORE_ejtag_ctrl_0_portconnected_mask                               (0x000000FF)
#define  SCPU_CORE_ejtag_ctrl_0_ejtag_chain_mode(data)                           (0x01000000&((data)<<24))
#define  SCPU_CORE_ejtag_ctrl_0_srstconnected(data)                              (0x00FF0000&((data)<<16))
#define  SCPU_CORE_ejtag_ctrl_0_portenabled(data)                                (0x0000FF00&((data)<<8))
#define  SCPU_CORE_ejtag_ctrl_0_portconnected(data)                              (0x000000FF&(data))
#define  SCPU_CORE_ejtag_ctrl_0_get_ejtag_chain_mode(data)                       ((0x01000000&(data))>>24)
#define  SCPU_CORE_ejtag_ctrl_0_get_srstconnected(data)                          ((0x00FF0000&(data))>>16)
#define  SCPU_CORE_ejtag_ctrl_0_get_portenabled(data)                            ((0x0000FF00&(data))>>8)
#define  SCPU_CORE_ejtag_ctrl_0_get_portconnected(data)                          (0x000000FF&(data))

#define  SCPU_CORE_ejtag_ctrl_1                                                  0x1805B8C8
#define  SCPU_CORE_ejtag_ctrl_1_reg_addr                                         "0xB805B8C8"
#define  SCPU_CORE_ejtag_ctrl_1_reg                                              0xB805B8C8
#define  SCPU_CORE_ejtag_ctrl_1_inst_addr                                        "0x004D"
#define  set_SCPU_CORE_ejtag_ctrl_1_reg(data)                                    (*((volatile unsigned int*)SCPU_CORE_ejtag_ctrl_1_reg)=data)
#define  get_SCPU_CORE_ejtag_ctrl_1_reg                                          (*((volatile unsigned int*)SCPU_CORE_ejtag_ctrl_1_reg))
#define  SCPU_CORE_ejtag_ctrl_1_csrtck_dly_2_shift                               (4)
#define  SCPU_CORE_ejtag_ctrl_1_csrtck_dly_1_shift                               (2)
#define  SCPU_CORE_ejtag_ctrl_1_csrtck_dly_0_shift                               (0)
#define  SCPU_CORE_ejtag_ctrl_1_csrtck_dly_2_mask                                (0x00000030)
#define  SCPU_CORE_ejtag_ctrl_1_csrtck_dly_1_mask                                (0x0000000C)
#define  SCPU_CORE_ejtag_ctrl_1_csrtck_dly_0_mask                                (0x00000003)
#define  SCPU_CORE_ejtag_ctrl_1_csrtck_dly_2(data)                               (0x00000030&((data)<<4))
#define  SCPU_CORE_ejtag_ctrl_1_csrtck_dly_1(data)                               (0x0000000C&((data)<<2))
#define  SCPU_CORE_ejtag_ctrl_1_csrtck_dly_0(data)                               (0x00000003&(data))
#define  SCPU_CORE_ejtag_ctrl_1_get_csrtck_dly_2(data)                           ((0x00000030&(data))>>4)
#define  SCPU_CORE_ejtag_ctrl_1_get_csrtck_dly_1(data)                           ((0x0000000C&(data))>>2)
#define  SCPU_CORE_ejtag_ctrl_1_get_csrtck_dly_0(data)                           (0x00000003&(data))

#define  SCPU_CORE_ejtag_status_0                                                0x1805B8D0
#define  SCPU_CORE_ejtag_status_0_reg_addr                                       "0xB805B8D0"
#define  SCPU_CORE_ejtag_status_0_reg                                            0xB805B8D0
#define  SCPU_CORE_ejtag_status_0_inst_addr                                      "0x004E"
#define  set_SCPU_CORE_ejtag_status_0_reg(data)                                  (*((volatile unsigned int*)SCPU_CORE_ejtag_status_0_reg)=data)
#define  get_SCPU_CORE_ejtag_status_0_reg                                        (*((volatile unsigned int*)SCPU_CORE_ejtag_status_0_reg))
#define  SCPU_CORE_ejtag_status_0_status_status_jtagnsw_shift                    (9)
#define  SCPU_CORE_ejtag_status_0_status_status_jtagtop_shift                    (8)
#define  SCPU_CORE_ejtag_status_0_nsrstout_shift                                 (0)
#define  SCPU_CORE_ejtag_status_0_status_status_jtagnsw_mask                     (0x00000200)
#define  SCPU_CORE_ejtag_status_0_status_status_jtagtop_mask                     (0x00000100)
#define  SCPU_CORE_ejtag_status_0_nsrstout_mask                                  (0x000000FF)
#define  SCPU_CORE_ejtag_status_0_status_status_jtagnsw(data)                    (0x00000200&((data)<<9))
#define  SCPU_CORE_ejtag_status_0_status_status_jtagtop(data)                    (0x00000100&((data)<<8))
#define  SCPU_CORE_ejtag_status_0_nsrstout(data)                                 (0x000000FF&(data))
#define  SCPU_CORE_ejtag_status_0_get_status_status_jtagnsw(data)                ((0x00000200&(data))>>9)
#define  SCPU_CORE_ejtag_status_0_get_status_status_jtagtop(data)                ((0x00000100&(data))>>8)
#define  SCPU_CORE_ejtag_status_0_get_nsrstout(data)                             (0x000000FF&(data))

#define  SCPU_CORE_exok_ctrl                                                     0x1805B900
#define  SCPU_CORE_exok_ctrl_reg_addr                                            "0xB805B900"
#define  SCPU_CORE_exok_ctrl_reg                                                 0xB805B900
#define  SCPU_CORE_exok_ctrl_inst_addr                                           "0x004F"
#define  set_SCPU_CORE_exok_ctrl_reg(data)                                       (*((volatile unsigned int*)SCPU_CORE_exok_ctrl_reg)=data)
#define  get_SCPU_CORE_exok_ctrl_reg                                             (*((volatile unsigned int*)SCPU_CORE_exok_ctrl_reg))
#define  SCPU_CORE_exok_ctrl_exok_en_shift                                       (0)
#define  SCPU_CORE_exok_ctrl_exok_en_mask                                        (0x00000001)
#define  SCPU_CORE_exok_ctrl_exok_en(data)                                       (0x00000001&(data))
#define  SCPU_CORE_exok_ctrl_get_exok_en(data)                                   (0x00000001&(data))

#define  SCPU_CORE_interrupt_ctrl_1                                              0x1805B910
#define  SCPU_CORE_interrupt_ctrl_1_reg_addr                                     "0xB805B910"
#define  SCPU_CORE_interrupt_ctrl_1_reg                                          0xB805B910
#define  SCPU_CORE_interrupt_ctrl_1_inst_addr                                    "0x0050"
#define  set_SCPU_CORE_interrupt_ctrl_1_reg(data)                                (*((volatile unsigned int*)SCPU_CORE_interrupt_ctrl_1_reg)=data)
#define  get_SCPU_CORE_interrupt_ctrl_1_reg                                      (*((volatile unsigned int*)SCPU_CORE_interrupt_ctrl_1_reg))
#define  SCPU_CORE_interrupt_ctrl_1_a53_warmrstirq3_shift                        (23)
#define  SCPU_CORE_interrupt_ctrl_1_a53_warmrstirq2_shift                        (22)
#define  SCPU_CORE_interrupt_ctrl_1_a53_warmrstirq1_shift                        (21)
#define  SCPU_CORE_interrupt_ctrl_1_a53_warmrstirq0_shift                        (20)
#define  SCPU_CORE_interrupt_ctrl_1_a53_ctiirq3_shift                            (19)
#define  SCPU_CORE_interrupt_ctrl_1_a53_ctiirq2_shift                            (18)
#define  SCPU_CORE_interrupt_ctrl_1_a53_ctiirq1_shift                            (17)
#define  SCPU_CORE_interrupt_ctrl_1_a53_ctiirq0_shift                            (16)
#define  SCPU_CORE_interrupt_ctrl_1_a53_npmuirq3_shift                           (15)
#define  SCPU_CORE_interrupt_ctrl_1_a53_npmuirq2_shift                           (14)
#define  SCPU_CORE_interrupt_ctrl_1_a53_npmuirq1_shift                           (13)
#define  SCPU_CORE_interrupt_ctrl_1_a53_npmuirq0_shift                           (12)
#define  SCPU_CORE_interrupt_ctrl_1_na53exterrirq_shift                          (10)
#define  SCPU_CORE_interrupt_ctrl_1_irq_nirqout3_shift                           (7)
#define  SCPU_CORE_interrupt_ctrl_1_irq_nirqout2_shift                           (6)
#define  SCPU_CORE_interrupt_ctrl_1_irq_nirqout1_shift                           (5)
#define  SCPU_CORE_interrupt_ctrl_1_irq_nirqout0_shift                           (4)
#define  SCPU_CORE_interrupt_ctrl_1_irq_nfiqout3_shift                           (3)
#define  SCPU_CORE_interrupt_ctrl_1_irq_nfiqout2_shift                           (2)
#define  SCPU_CORE_interrupt_ctrl_1_irq_nfiqout1_shift                           (1)
#define  SCPU_CORE_interrupt_ctrl_1_irq_nfiqout0_shift                           (0)
#define  SCPU_CORE_interrupt_ctrl_1_a53_warmrstirq3_mask                         (0x00800000)
#define  SCPU_CORE_interrupt_ctrl_1_a53_warmrstirq2_mask                         (0x00400000)
#define  SCPU_CORE_interrupt_ctrl_1_a53_warmrstirq1_mask                         (0x00200000)
#define  SCPU_CORE_interrupt_ctrl_1_a53_warmrstirq0_mask                         (0x00100000)
#define  SCPU_CORE_interrupt_ctrl_1_a53_ctiirq3_mask                             (0x00080000)
#define  SCPU_CORE_interrupt_ctrl_1_a53_ctiirq2_mask                             (0x00040000)
#define  SCPU_CORE_interrupt_ctrl_1_a53_ctiirq1_mask                             (0x00020000)
#define  SCPU_CORE_interrupt_ctrl_1_a53_ctiirq0_mask                             (0x00010000)
#define  SCPU_CORE_interrupt_ctrl_1_a53_npmuirq3_mask                            (0x00008000)
#define  SCPU_CORE_interrupt_ctrl_1_a53_npmuirq2_mask                            (0x00004000)
#define  SCPU_CORE_interrupt_ctrl_1_a53_npmuirq1_mask                            (0x00002000)
#define  SCPU_CORE_interrupt_ctrl_1_a53_npmuirq0_mask                            (0x00001000)
#define  SCPU_CORE_interrupt_ctrl_1_na53exterrirq_mask                           (0x00000400)
#define  SCPU_CORE_interrupt_ctrl_1_irq_nirqout3_mask                            (0x00000080)
#define  SCPU_CORE_interrupt_ctrl_1_irq_nirqout2_mask                            (0x00000040)
#define  SCPU_CORE_interrupt_ctrl_1_irq_nirqout1_mask                            (0x00000020)
#define  SCPU_CORE_interrupt_ctrl_1_irq_nirqout0_mask                            (0x00000010)
#define  SCPU_CORE_interrupt_ctrl_1_irq_nfiqout3_mask                            (0x00000008)
#define  SCPU_CORE_interrupt_ctrl_1_irq_nfiqout2_mask                            (0x00000004)
#define  SCPU_CORE_interrupt_ctrl_1_irq_nfiqout1_mask                            (0x00000002)
#define  SCPU_CORE_interrupt_ctrl_1_irq_nfiqout0_mask                            (0x00000001)
#define  SCPU_CORE_interrupt_ctrl_1_a53_warmrstirq3(data)                        (0x00800000&((data)<<23))
#define  SCPU_CORE_interrupt_ctrl_1_a53_warmrstirq2(data)                        (0x00400000&((data)<<22))
#define  SCPU_CORE_interrupt_ctrl_1_a53_warmrstirq1(data)                        (0x00200000&((data)<<21))
#define  SCPU_CORE_interrupt_ctrl_1_a53_warmrstirq0(data)                        (0x00100000&((data)<<20))
#define  SCPU_CORE_interrupt_ctrl_1_a53_ctiirq3(data)                            (0x00080000&((data)<<19))
#define  SCPU_CORE_interrupt_ctrl_1_a53_ctiirq2(data)                            (0x00040000&((data)<<18))
#define  SCPU_CORE_interrupt_ctrl_1_a53_ctiirq1(data)                            (0x00020000&((data)<<17))
#define  SCPU_CORE_interrupt_ctrl_1_a53_ctiirq0(data)                            (0x00010000&((data)<<16))
#define  SCPU_CORE_interrupt_ctrl_1_a53_npmuirq3(data)                           (0x00008000&((data)<<15))
#define  SCPU_CORE_interrupt_ctrl_1_a53_npmuirq2(data)                           (0x00004000&((data)<<14))
#define  SCPU_CORE_interrupt_ctrl_1_a53_npmuirq1(data)                           (0x00002000&((data)<<13))
#define  SCPU_CORE_interrupt_ctrl_1_a53_npmuirq0(data)                           (0x00001000&((data)<<12))
#define  SCPU_CORE_interrupt_ctrl_1_na53exterrirq(data)                          (0x00000400&((data)<<10))
#define  SCPU_CORE_interrupt_ctrl_1_irq_nirqout3(data)                           (0x00000080&((data)<<7))
#define  SCPU_CORE_interrupt_ctrl_1_irq_nirqout2(data)                           (0x00000040&((data)<<6))
#define  SCPU_CORE_interrupt_ctrl_1_irq_nirqout1(data)                           (0x00000020&((data)<<5))
#define  SCPU_CORE_interrupt_ctrl_1_irq_nirqout0(data)                           (0x00000010&((data)<<4))
#define  SCPU_CORE_interrupt_ctrl_1_irq_nfiqout3(data)                           (0x00000008&((data)<<3))
#define  SCPU_CORE_interrupt_ctrl_1_irq_nfiqout2(data)                           (0x00000004&((data)<<2))
#define  SCPU_CORE_interrupt_ctrl_1_irq_nfiqout1(data)                           (0x00000002&((data)<<1))
#define  SCPU_CORE_interrupt_ctrl_1_irq_nfiqout0(data)                           (0x00000001&(data))
#define  SCPU_CORE_interrupt_ctrl_1_get_a53_warmrstirq3(data)                    ((0x00800000&(data))>>23)
#define  SCPU_CORE_interrupt_ctrl_1_get_a53_warmrstirq2(data)                    ((0x00400000&(data))>>22)
#define  SCPU_CORE_interrupt_ctrl_1_get_a53_warmrstirq1(data)                    ((0x00200000&(data))>>21)
#define  SCPU_CORE_interrupt_ctrl_1_get_a53_warmrstirq0(data)                    ((0x00100000&(data))>>20)
#define  SCPU_CORE_interrupt_ctrl_1_get_a53_ctiirq3(data)                        ((0x00080000&(data))>>19)
#define  SCPU_CORE_interrupt_ctrl_1_get_a53_ctiirq2(data)                        ((0x00040000&(data))>>18)
#define  SCPU_CORE_interrupt_ctrl_1_get_a53_ctiirq1(data)                        ((0x00020000&(data))>>17)
#define  SCPU_CORE_interrupt_ctrl_1_get_a53_ctiirq0(data)                        ((0x00010000&(data))>>16)
#define  SCPU_CORE_interrupt_ctrl_1_get_a53_npmuirq3(data)                       ((0x00008000&(data))>>15)
#define  SCPU_CORE_interrupt_ctrl_1_get_a53_npmuirq2(data)                       ((0x00004000&(data))>>14)
#define  SCPU_CORE_interrupt_ctrl_1_get_a53_npmuirq1(data)                       ((0x00002000&(data))>>13)
#define  SCPU_CORE_interrupt_ctrl_1_get_a53_npmuirq0(data)                       ((0x00001000&(data))>>12)
#define  SCPU_CORE_interrupt_ctrl_1_get_na53exterrirq(data)                      ((0x00000400&(data))>>10)
#define  SCPU_CORE_interrupt_ctrl_1_get_irq_nirqout3(data)                       ((0x00000080&(data))>>7)
#define  SCPU_CORE_interrupt_ctrl_1_get_irq_nirqout2(data)                       ((0x00000040&(data))>>6)
#define  SCPU_CORE_interrupt_ctrl_1_get_irq_nirqout1(data)                       ((0x00000020&(data))>>5)
#define  SCPU_CORE_interrupt_ctrl_1_get_irq_nirqout0(data)                       ((0x00000010&(data))>>4)
#define  SCPU_CORE_interrupt_ctrl_1_get_irq_nfiqout3(data)                       ((0x00000008&(data))>>3)
#define  SCPU_CORE_interrupt_ctrl_1_get_irq_nfiqout2(data)                       ((0x00000004&(data))>>2)
#define  SCPU_CORE_interrupt_ctrl_1_get_irq_nfiqout1(data)                       ((0x00000002&(data))>>1)
#define  SCPU_CORE_interrupt_ctrl_1_get_irq_nfiqout0(data)                       (0x00000001&(data))

#define  SCPU_CORE_interrupt_ctrl_0                                              0x1805B914
#define  SCPU_CORE_interrupt_ctrl_0_reg_addr                                     "0xB805B914"
#define  SCPU_CORE_interrupt_ctrl_0_reg                                          0xB805B914
#define  SCPU_CORE_interrupt_ctrl_0_inst_addr                                    "0x0051"
#define  set_SCPU_CORE_interrupt_ctrl_0_reg(data)                                (*((volatile unsigned int*)SCPU_CORE_interrupt_ctrl_0_reg)=data)
#define  get_SCPU_CORE_interrupt_ctrl_0_reg                                      (*((volatile unsigned int*)SCPU_CORE_interrupt_ctrl_0_reg))
#define  SCPU_CORE_interrupt_ctrl_0_a53_warmrstirq3_en_shift                     (23)
#define  SCPU_CORE_interrupt_ctrl_0_a53_warmrstirq2_en_shift                     (22)
#define  SCPU_CORE_interrupt_ctrl_0_a53_warmrstirq1_en_shift                     (21)
#define  SCPU_CORE_interrupt_ctrl_0_a53_warmrstirq0_en_shift                     (20)
#define  SCPU_CORE_interrupt_ctrl_0_a53_ctiirq3_en_shift                         (19)
#define  SCPU_CORE_interrupt_ctrl_0_a53_ctiirq2_en_shift                         (18)
#define  SCPU_CORE_interrupt_ctrl_0_a53_ctiirq1_en_shift                         (17)
#define  SCPU_CORE_interrupt_ctrl_0_a53_ctiirq0_en_shift                         (16)
#define  SCPU_CORE_interrupt_ctrl_0_a53_npmuirq3_en_shift                        (15)
#define  SCPU_CORE_interrupt_ctrl_0_a53_npmuirq2_en_shift                        (14)
#define  SCPU_CORE_interrupt_ctrl_0_a53_npmuirq1_en_shift                        (13)
#define  SCPU_CORE_interrupt_ctrl_0_a53_npmuirq0_en_shift                        (12)
#define  SCPU_CORE_interrupt_ctrl_0_irq_dest_sel_shift                           (11)
#define  SCPU_CORE_interrupt_ctrl_0_na53exterrirq_en_shift                       (10)
#define  SCPU_CORE_interrupt_ctrl_0_irq_nirqout3_en_shift                        (7)
#define  SCPU_CORE_interrupt_ctrl_0_irq_nirqout2_en_shift                        (6)
#define  SCPU_CORE_interrupt_ctrl_0_irq_nirqout1_en_shift                        (5)
#define  SCPU_CORE_interrupt_ctrl_0_irq_nirqout0_en_shift                        (4)
#define  SCPU_CORE_interrupt_ctrl_0_irq_nfiqout3_en_shift                        (3)
#define  SCPU_CORE_interrupt_ctrl_0_irq_nfiqout2_en_shift                        (2)
#define  SCPU_CORE_interrupt_ctrl_0_irq_nfiqout1_en_shift                        (1)
#define  SCPU_CORE_interrupt_ctrl_0_irq_nfiqout0_en_shift                        (0)
#define  SCPU_CORE_interrupt_ctrl_0_a53_warmrstirq3_en_mask                      (0x00800000)
#define  SCPU_CORE_interrupt_ctrl_0_a53_warmrstirq2_en_mask                      (0x00400000)
#define  SCPU_CORE_interrupt_ctrl_0_a53_warmrstirq1_en_mask                      (0x00200000)
#define  SCPU_CORE_interrupt_ctrl_0_a53_warmrstirq0_en_mask                      (0x00100000)
#define  SCPU_CORE_interrupt_ctrl_0_a53_ctiirq3_en_mask                          (0x00080000)
#define  SCPU_CORE_interrupt_ctrl_0_a53_ctiirq2_en_mask                          (0x00040000)
#define  SCPU_CORE_interrupt_ctrl_0_a53_ctiirq1_en_mask                          (0x00020000)
#define  SCPU_CORE_interrupt_ctrl_0_a53_ctiirq0_en_mask                          (0x00010000)
#define  SCPU_CORE_interrupt_ctrl_0_a53_npmuirq3_en_mask                         (0x00008000)
#define  SCPU_CORE_interrupt_ctrl_0_a53_npmuirq2_en_mask                         (0x00004000)
#define  SCPU_CORE_interrupt_ctrl_0_a53_npmuirq1_en_mask                         (0x00002000)
#define  SCPU_CORE_interrupt_ctrl_0_a53_npmuirq0_en_mask                         (0x00001000)
#define  SCPU_CORE_interrupt_ctrl_0_irq_dest_sel_mask                            (0x00000800)
#define  SCPU_CORE_interrupt_ctrl_0_na53exterrirq_en_mask                        (0x00000400)
#define  SCPU_CORE_interrupt_ctrl_0_irq_nirqout3_en_mask                         (0x00000080)
#define  SCPU_CORE_interrupt_ctrl_0_irq_nirqout2_en_mask                         (0x00000040)
#define  SCPU_CORE_interrupt_ctrl_0_irq_nirqout1_en_mask                         (0x00000020)
#define  SCPU_CORE_interrupt_ctrl_0_irq_nirqout0_en_mask                         (0x00000010)
#define  SCPU_CORE_interrupt_ctrl_0_irq_nfiqout3_en_mask                         (0x00000008)
#define  SCPU_CORE_interrupt_ctrl_0_irq_nfiqout2_en_mask                         (0x00000004)
#define  SCPU_CORE_interrupt_ctrl_0_irq_nfiqout1_en_mask                         (0x00000002)
#define  SCPU_CORE_interrupt_ctrl_0_irq_nfiqout0_en_mask                         (0x00000001)
#define  SCPU_CORE_interrupt_ctrl_0_a53_warmrstirq3_en(data)                     (0x00800000&((data)<<23))
#define  SCPU_CORE_interrupt_ctrl_0_a53_warmrstirq2_en(data)                     (0x00400000&((data)<<22))
#define  SCPU_CORE_interrupt_ctrl_0_a53_warmrstirq1_en(data)                     (0x00200000&((data)<<21))
#define  SCPU_CORE_interrupt_ctrl_0_a53_warmrstirq0_en(data)                     (0x00100000&((data)<<20))
#define  SCPU_CORE_interrupt_ctrl_0_a53_ctiirq3_en(data)                         (0x00080000&((data)<<19))
#define  SCPU_CORE_interrupt_ctrl_0_a53_ctiirq2_en(data)                         (0x00040000&((data)<<18))
#define  SCPU_CORE_interrupt_ctrl_0_a53_ctiirq1_en(data)                         (0x00020000&((data)<<17))
#define  SCPU_CORE_interrupt_ctrl_0_a53_ctiirq0_en(data)                         (0x00010000&((data)<<16))
#define  SCPU_CORE_interrupt_ctrl_0_a53_npmuirq3_en(data)                        (0x00008000&((data)<<15))
#define  SCPU_CORE_interrupt_ctrl_0_a53_npmuirq2_en(data)                        (0x00004000&((data)<<14))
#define  SCPU_CORE_interrupt_ctrl_0_a53_npmuirq1_en(data)                        (0x00002000&((data)<<13))
#define  SCPU_CORE_interrupt_ctrl_0_a53_npmuirq0_en(data)                        (0x00001000&((data)<<12))
#define  SCPU_CORE_interrupt_ctrl_0_irq_dest_sel(data)                           (0x00000800&((data)<<11))
#define  SCPU_CORE_interrupt_ctrl_0_na53exterrirq_en(data)                       (0x00000400&((data)<<10))
#define  SCPU_CORE_interrupt_ctrl_0_irq_nirqout3_en(data)                        (0x00000080&((data)<<7))
#define  SCPU_CORE_interrupt_ctrl_0_irq_nirqout2_en(data)                        (0x00000040&((data)<<6))
#define  SCPU_CORE_interrupt_ctrl_0_irq_nirqout1_en(data)                        (0x00000020&((data)<<5))
#define  SCPU_CORE_interrupt_ctrl_0_irq_nirqout0_en(data)                        (0x00000010&((data)<<4))
#define  SCPU_CORE_interrupt_ctrl_0_irq_nfiqout3_en(data)                        (0x00000008&((data)<<3))
#define  SCPU_CORE_interrupt_ctrl_0_irq_nfiqout2_en(data)                        (0x00000004&((data)<<2))
#define  SCPU_CORE_interrupt_ctrl_0_irq_nfiqout1_en(data)                        (0x00000002&((data)<<1))
#define  SCPU_CORE_interrupt_ctrl_0_irq_nfiqout0_en(data)                        (0x00000001&(data))
#define  SCPU_CORE_interrupt_ctrl_0_get_a53_warmrstirq3_en(data)                 ((0x00800000&(data))>>23)
#define  SCPU_CORE_interrupt_ctrl_0_get_a53_warmrstirq2_en(data)                 ((0x00400000&(data))>>22)
#define  SCPU_CORE_interrupt_ctrl_0_get_a53_warmrstirq1_en(data)                 ((0x00200000&(data))>>21)
#define  SCPU_CORE_interrupt_ctrl_0_get_a53_warmrstirq0_en(data)                 ((0x00100000&(data))>>20)
#define  SCPU_CORE_interrupt_ctrl_0_get_a53_ctiirq3_en(data)                     ((0x00080000&(data))>>19)
#define  SCPU_CORE_interrupt_ctrl_0_get_a53_ctiirq2_en(data)                     ((0x00040000&(data))>>18)
#define  SCPU_CORE_interrupt_ctrl_0_get_a53_ctiirq1_en(data)                     ((0x00020000&(data))>>17)
#define  SCPU_CORE_interrupt_ctrl_0_get_a53_ctiirq0_en(data)                     ((0x00010000&(data))>>16)
#define  SCPU_CORE_interrupt_ctrl_0_get_a53_npmuirq3_en(data)                    ((0x00008000&(data))>>15)
#define  SCPU_CORE_interrupt_ctrl_0_get_a53_npmuirq2_en(data)                    ((0x00004000&(data))>>14)
#define  SCPU_CORE_interrupt_ctrl_0_get_a53_npmuirq1_en(data)                    ((0x00002000&(data))>>13)
#define  SCPU_CORE_interrupt_ctrl_0_get_a53_npmuirq0_en(data)                    ((0x00001000&(data))>>12)
#define  SCPU_CORE_interrupt_ctrl_0_get_irq_dest_sel(data)                       ((0x00000800&(data))>>11)
#define  SCPU_CORE_interrupt_ctrl_0_get_na53exterrirq_en(data)                   ((0x00000400&(data))>>10)
#define  SCPU_CORE_interrupt_ctrl_0_get_irq_nirqout3_en(data)                    ((0x00000080&(data))>>7)
#define  SCPU_CORE_interrupt_ctrl_0_get_irq_nirqout2_en(data)                    ((0x00000040&(data))>>6)
#define  SCPU_CORE_interrupt_ctrl_0_get_irq_nirqout1_en(data)                    ((0x00000020&(data))>>5)
#define  SCPU_CORE_interrupt_ctrl_0_get_irq_nirqout0_en(data)                    ((0x00000010&(data))>>4)
#define  SCPU_CORE_interrupt_ctrl_0_get_irq_nfiqout3_en(data)                    ((0x00000008&(data))>>3)
#define  SCPU_CORE_interrupt_ctrl_0_get_irq_nfiqout2_en(data)                    ((0x00000004&(data))>>2)
#define  SCPU_CORE_interrupt_ctrl_0_get_irq_nfiqout1_en(data)                    ((0x00000002&(data))>>1)
#define  SCPU_CORE_interrupt_ctrl_0_get_irq_nfiqout0_en(data)                    (0x00000001&(data))

#define  SCPU_CORE_gic_ctrl_0                                                    0x1805B920
#define  SCPU_CORE_gic_ctrl_0_reg_addr                                           "0xB805B920"
#define  SCPU_CORE_gic_ctrl_0_reg                                                0xB805B920
#define  SCPU_CORE_gic_ctrl_0_inst_addr                                          "0x0052"
#define  set_SCPU_CORE_gic_ctrl_0_reg(data)                                      (*((volatile unsigned int*)SCPU_CORE_gic_ctrl_0_reg)=data)
#define  get_SCPU_CORE_gic_ctrl_0_reg                                            (*((volatile unsigned int*)SCPU_CORE_gic_ctrl_0_reg))
#define  SCPU_CORE_gic_ctrl_0_cfgsdisable_shift                                  (0)
#define  SCPU_CORE_gic_ctrl_0_cfgsdisable_mask                                   (0x00000001)
#define  SCPU_CORE_gic_ctrl_0_cfgsdisable(data)                                  (0x00000001&(data))
#define  SCPU_CORE_gic_ctrl_0_get_cfgsdisable(data)                              (0x00000001&(data))

#define  SCPU_CORE_eco_rw_reg                                                    0x1805B924
#define  SCPU_CORE_eco_rw_reg_reg_addr                                           "0xB805B924"
#define  SCPU_CORE_eco_rw_reg_reg                                                0xB805B924
#define  SCPU_CORE_eco_rw_reg_inst_addr                                          "0x0053"
#define  set_SCPU_CORE_eco_rw_reg_reg(data)                                      (*((volatile unsigned int*)SCPU_CORE_eco_rw_reg_reg)=data)
#define  get_SCPU_CORE_eco_rw_reg_reg                                            (*((volatile unsigned int*)SCPU_CORE_eco_rw_reg_reg))
#define  SCPU_CORE_eco_rw_reg_eco_rw_shift                                       (0)
#define  SCPU_CORE_eco_rw_reg_eco_rw_mask                                        (0xFFFFFFFF)
#define  SCPU_CORE_eco_rw_reg_eco_rw(data)                                       (0xFFFFFFFF&(data))
#define  SCPU_CORE_eco_rw_reg_get_eco_rw(data)                                   (0xFFFFFFFF&(data))

#define  SCPU_CORE_eco_r_reg                                                     0x1805B928
#define  SCPU_CORE_eco_r_reg_reg_addr                                            "0xB805B928"
#define  SCPU_CORE_eco_r_reg_reg                                                 0xB805B928
#define  SCPU_CORE_eco_r_reg_inst_addr                                           "0x0054"
#define  set_SCPU_CORE_eco_r_reg_reg(data)                                       (*((volatile unsigned int*)SCPU_CORE_eco_r_reg_reg)=data)
#define  get_SCPU_CORE_eco_r_reg_reg                                             (*((volatile unsigned int*)SCPU_CORE_eco_r_reg_reg))
#define  SCPU_CORE_eco_r_reg_eco_r_only_shift                                    (0)
#define  SCPU_CORE_eco_r_reg_eco_r_only_mask                                     (0xFFFFFFFF)
#define  SCPU_CORE_eco_r_reg_eco_r_only(data)                                    (0xFFFFFFFF&(data))
#define  SCPU_CORE_eco_r_reg_get_eco_r_only(data)                                (0xFFFFFFFF&(data))

#define  SCPU_CORE_a53_tie_reg                                                   0x1805B92C
#define  SCPU_CORE_a53_tie_reg_reg_addr                                          "0xB805B92C"
#define  SCPU_CORE_a53_tie_reg_reg                                               0xB805B92C
#define  SCPU_CORE_a53_tie_reg_inst_addr                                         "0x0055"
#define  set_SCPU_CORE_a53_tie_reg_reg(data)                                     (*((volatile unsigned int*)SCPU_CORE_a53_tie_reg_reg)=data)
#define  get_SCPU_CORE_a53_tie_reg_reg                                           (*((volatile unsigned int*)SCPU_CORE_a53_tie_reg_reg))
#define  SCPU_CORE_a53_tie_reg_a53_tie0_shift                                    (0)
#define  SCPU_CORE_a53_tie_reg_a53_tie0_mask                                     (0x00000001)
#define  SCPU_CORE_a53_tie_reg_a53_tie0(data)                                    (0x00000001&(data))
#define  SCPU_CORE_a53_tie_reg_get_a53_tie0(data)                                (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======SCPU_CORE register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  pllscpu_wdset:1;
        RBus_UInt32  pllscpu_wdrst:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllscpu_lpf_cs:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  pllscpu_testsel:1;
        RBus_UInt32  pllscpu_sel_cco:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  pllscpu_icp:3;
        RBus_UInt32  pllscpu_dbug_en:1;
        RBus_UInt32  pllscpu_pdiv_bps:1;
        RBus_UInt32  pllscpu_pdiv:2;
        RBus_UInt32  res5:1;
        RBus_UInt32  pllscpu_lpf_rs:3;
    };
}scpu_core_sys_pll_scpu1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  pllscpu_fcode:11;
        RBus_UInt32  pllscpu_ncode:8;
        RBus_UInt32  res2:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllscpu_oeb:1;
        RBus_UInt32  pllscpu_rstb:1;
        RBus_UInt32  pllscpu_pow:1;
    };
}scpu_core_sys_pll_scpu2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllscpu_bypass_pi:1;
        RBus_UInt32  pllscpu_en_pi_debug:1;
        RBus_UInt32  pllscpu_hs_oc_stop:2;
        RBus_UInt32  pllscpu_pi_cur_sel:2;
        RBus_UInt32  pllscpu_sel_oc_mode:2;
        RBus_UInt32  pllscpu_ldo10v_sel:2;
        RBus_UInt32  pllscpu_ldo18v_sel:2;
        RBus_UInt32  pllscpu_oc_done_delay:6;
        RBus_UInt32  pllscpu_oc_step:10;
        RBus_UInt32  res1:1;
        RBus_UInt32  pllscpu_sdm_order:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllscpu_oc_en:1;
    };
}scpu_core_sys_scpu_dvfs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  pllscpu_wdout_ro:1;
        RBus_UInt32  pllscpu_oc_done_ro:1;
        RBus_UInt32  pllscpu_ncode_dbg_ro:8;
        RBus_UInt32  pllscpu_fcode_dbg_ro:11;
        RBus_UInt32  pllscpu_dfvs_fmod_dbg:1;
    };
}scpu_core_sys_scpu_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  pllscpu_reserve:6;
    };
}scpu_core_sys_scpu_reserve_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  scpu_ssc_ckinv:1;
    };
}scpu_core_sys_scpu_ckinv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  clkratio_scpu:5;
    };
}scpu_core_sys_scpu_clkratio_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  clkratio_scpu_active:1;
    };
}scpu_core_sys_scpu_clkratio_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  clken_dss:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  clken_a53_atb:1;
        RBus_UInt32  clken_a53_apb:1;
        RBus_UInt32  clken_top_atb:1;
        RBus_UInt32  clken_top_apb:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  clken_a53:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  clken_scpu_top_logic:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  clken_top_ts:1;
    };
}scpu_core_sys_scpu_clken_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  trc_clk_delay:4;
        RBus_UInt32  trc_clkdiv_sel:2;
    };
}scpu_core_sys_scpu_clkdiv_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  resetsocdbgn:1;
        RBus_UInt32  scpu_nic_rstn:1;
        RBus_UInt32  scpu_core0_rstn:1;
        RBus_UInt32  scpu_core1_rstn:1;
        RBus_UInt32  scpu_core0_poreset_n:1;
        RBus_UInt32  scpu_core1_poreset_n:1;
        RBus_UInt32  scpu_dbg_rstn:1;
        RBus_UInt32  scpu_l2_rstn:1;
        RBus_UInt32  scpu_core2_rstn:1;
        RBus_UInt32  scpu_core3_rstn:1;
        RBus_UInt32  scpu_core2_poreset_n:1;
        RBus_UInt32  scpu_core3_poreset_n:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  scpu_gic_rstn:1;
    };
}scpu_core_sys_scpu_rst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  a53_warmreset_en:1;
    };
}scpu_core_sys_warmrst_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  voltprob_a53_c0_pwr_ctrl:2;
        RBus_UInt32  voltprob_a53_c0_gnd_ctrl:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  voltprob_scpu_lvl_pwr_ctrl:1;
        RBus_UInt32  voltprob_scpu_lvl_gnd_ctrl:1;
    };
}scpu_core_voltage_probe_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53_dss_rst_n:1;
        RBus_UInt32  a53_ro_sel:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  a53_wire_sel:1;
        RBus_UInt32  a53_speed_en_0:1;
        RBus_UInt32  a53_speed_en_1:1;
        RBus_UInt32  res2:24;
    };
}scpu_core_dss_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scpu_c31_9p5t_data_in:20;
        RBus_UInt32  scpu_c31_9p5t_dss_rst_n:1;
        RBus_UInt32  scpu_c31_9p5t_ro_sel:3;
        RBus_UInt32  scpu_c31_9p5t_speed_en:1;
        RBus_UInt32  scpu_c31_9p5t_wire_sel:1;
        RBus_UInt32  res1:6;
    };
}scpu_core_dss_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scpu_c35_9p5t_data_in:20;
        RBus_UInt32  scpu_c35_9p5t_dss_rst_n:1;
        RBus_UInt32  scpu_c35_9p5t_ro_sel:3;
        RBus_UInt32  scpu_c35_9p5t_speed_en:1;
        RBus_UInt32  scpu_c35_9p5t_wire_sel:1;
        RBus_UInt32  res1:6;
    };
}scpu_core_dss_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scpu_c38_9p5t_data_in:20;
        RBus_UInt32  scpu_c38_9p5t_dss_rst_n:1;
        RBus_UInt32  scpu_c38_9p5t_ro_sel:3;
        RBus_UInt32  scpu_c38_9p5t_speed_en:1;
        RBus_UInt32  scpu_c38_9p5t_wire_sel:1;
        RBus_UInt32  res1:6;
    };
}scpu_core_dss_ctrl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53_ready_0:1;
        RBus_UInt32  a53_count_out_0:20;
        RBus_UInt32  res1:11;
    };
}scpu_core_dss_status_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53_ready_1:1;
        RBus_UInt32  a53_count_out_1:20;
        RBus_UInt32  res1:11;
    };
}scpu_core_dss_status_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scpu_c31_9p5t_count_out_ro:20;
        RBus_UInt32  scpu_c31_9p5t_ready_ro:1;
        RBus_UInt32  scpu_c31_9p5t_wsort_go_ro:1;
        RBus_UInt32  res1:10;
    };
}scpu_core_dss_status_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scpu_c31_9p5t_dbgo_ro:16;
        RBus_UInt32  res1:16;
    };
}scpu_core_dss_status_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scpu_c35_9p5t_count_out_ro:20;
        RBus_UInt32  scpu_c35_9p5t_ready_ro:1;
        RBus_UInt32  scpu_c35_9p5t_wsort_go_ro:1;
        RBus_UInt32  res1:10;
    };
}scpu_core_dss_status_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scpu_c35_9p5t_dbgo_ro:16;
        RBus_UInt32  res1:16;
    };
}scpu_core_dss_status_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scpu_c38_9p5t_count_out_ro:20;
        RBus_UInt32  scpu_c38_9p5t_ready_ro:1;
        RBus_UInt32  scpu_c38_9p5t_wsort_go_ro:1;
        RBus_UInt32  res1:10;
    };
}scpu_core_dss_status_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scpu_c38_9p5t_dbgo_ro:16;
        RBus_UInt32  res1:16;
    };
}scpu_core_dss_status_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllscpu_dss_data_in:20;
        RBus_UInt32  pllscpu_dss_rst_n:1;
        RBus_UInt32  pllscpu_dss_ro_sel:3;
        RBus_UInt32  pllscpu_dss_speed_en:1;
        RBus_UInt32  pllscpu_dss_wire_sel:1;
        RBus_UInt32  res1:6;
    };
}scpu_core_dss_ctrl_pllscpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllscpu_dss_count_out:20;
        RBus_UInt32  pllscpu_dss_ready:1;
        RBus_UInt32  pllscpu_dss_wsort_go:1;
        RBus_UInt32  res1:10;
    };
}scpu_core_dss_status_pllscpu_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllscpu_dss_dbgo:16;
        RBus_UInt32  res1:16;
    };
}scpu_core_dss_status_pllscpu_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53_rme:1;
        RBus_UInt32  a53_ds_l1_0:1;
        RBus_UInt32  a53_ds_l1_1:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  a53_sd_l1_0:1;
        RBus_UInt32  a53_sd_l1_1:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  a53_ds_l1_2:1;
        RBus_UInt32  a53_ds_l1_3:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  a53_sd_l1_2:1;
        RBus_UInt32  a53_sd_l1_3:1;
        RBus_UInt32  res4:18;
        RBus_UInt32  a53_ls_off:1;
    };
}scpu_core_sram_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  a53_rm_47_32:16;
    };
}scpu_core_sram_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53_rm_31_0:32;
    };
}scpu_core_sram_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53_core_pwrctrl_in:2;
        RBus_UInt32  a53_core_clamp_en:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  a53_core_pwrctrl_in_3_2:2;
        RBus_UInt32  a53_core_clamp_en_3_2:2;
        RBus_UInt32  res2:22;
    };
}scpu_core_low_power_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  a53_power_mode_sel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  a53_power_delay_value:8;
        RBus_UInt32  res3:8;
    };
}scpu_core_low_power_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53_core_pwrctrl_out:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  a53_core_pwrctrl_out_3_2:2;
        RBus_UInt32  res2:27;
    };
}scpu_core_low_power_status_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  a53_drf_bisr_mode:1;
        RBus_UInt32  a53_drf_bisr_test_resume:1;
        RBus_UInt32  a53_second_run_en:1;
        RBus_UInt32  res2:28;
    };
}scpu_core_mbisr_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53_drf_bisr_done:1;
        RBus_UInt32  a53_drf_bisr_fail:8;
        RBus_UInt32  a53_drf_bisr_start_pause:1;
        RBus_UInt32  a53_bisr_fail:8;
        RBus_UInt32  res1:14;
    };
}scpu_core_mbisr_status_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  a53_bisr_repaired:1;
    };
}scpu_core_mbisr_status_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  a53_bisr_out_55_32:24;
    };
}scpu_core_mbisr_status_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53_bisr_out_31_0:32;
    };
}scpu_core_mbisr_status_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  a53_share_bus_en:1;
        RBus_UInt32  a53_bist_rstn:1;
        RBus_UInt32  a53_bist_mode0_all:1;
        RBus_UInt32  a53_bist_mode0_ddata:1;
        RBus_UInt32  a53_bist_mode0_dtag:1;
        RBus_UInt32  a53_bist_mode0_ddirty:1;
        RBus_UInt32  a53_bist_mode0_idata:1;
        RBus_UInt32  a53_bist_mode0_itag:1;
        RBus_UInt32  a53_bist_mode0_btac0:1;
        RBus_UInt32  a53_bist_mode0_btac1:1;
        RBus_UInt32  a53_bist_mode0_tlb:1;
        RBus_UInt32  a53_bist_mode0_scu:1;
        RBus_UInt32  a53_bist_mode0_l2_tag:1;
        RBus_UInt32  a53_bist_mode0_l2_victim:1;
        RBus_UInt32  a53_drf_bist_mode0:1;
        RBus_UInt32  a53_drf_test_resume0:1;
        RBus_UInt32  mbist0_all_mode:1;
        RBus_UInt32  mbist1_all_mode:1;
        RBus_UInt32  a53_bist_mode1_l2_data:1;
        RBus_UInt32  a53_diag_mode1_l2_data:1;
        RBus_UInt32  a53_diag_mode1_mbistarray1:2;
        RBus_UInt32  res2:9;
    };
}scpu_core_coordinator_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53_bist_done0_ddata:1;
        RBus_UInt32  a53_bist_done0_dtag:1;
        RBus_UInt32  a53_bist_done0_ddirty:1;
        RBus_UInt32  a53_bist_done0_idata:1;
        RBus_UInt32  a53_bist_done0_itag:1;
        RBus_UInt32  a53_bist_done0_btac0:1;
        RBus_UInt32  a53_bist_done0_btac1:1;
        RBus_UInt32  a53_bist_done0_tlb:1;
        RBus_UInt32  a53_bist_done0_scu:1;
        RBus_UInt32  a53_bist_done0_l2_tag:1;
        RBus_UInt32  a53_bist_done0_l2_victim:1;
        RBus_UInt32  a53_cpu0_bist_fail0_ddata:8;
        RBus_UInt32  a53_cpu0_bist_fail0_dtag:4;
        RBus_UInt32  a53_cpu0_bist_fail0_ddirty:1;
        RBus_UInt32  a53_cpu0_bist_fail0_idata:2;
        RBus_UInt32  a53_cpu0_bist_fail0_itag:2;
        RBus_UInt32  a53_cpu0_bist_fail0_btac0:1;
        RBus_UInt32  a53_cpu0_bist_fail0_btac1:1;
        RBus_UInt32  a53_bist_done1_l2_data:1;
        RBus_UInt32  res1:1;
    };
}scpu_core_coordinator_status_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53_cpu0_bist_fail0_tlb:4;
        RBus_UInt32  a53_cpu0_bist_fail0_scu:4;
        RBus_UInt32  a53_bist_fail0_l2_tag:16;
        RBus_UInt32  a53_bist_fail0_l2_victim:1;
        RBus_UInt32  a53_drf_start_pause0:1;
        RBus_UInt32  a53_drf_bist_done0:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  a53_bist_fail1_l2_data:4;
    };
}scpu_core_coordinator_status_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53_cpu0_drf_bist_fail0_ddata:8;
        RBus_UInt32  a53_cpu0_drf_bist_fail0_dtag:4;
        RBus_UInt32  a53_cpu0_drf_bist_fail0_ddirty:1;
        RBus_UInt32  a53_cpu0_drf_bist_fail0_idata:2;
        RBus_UInt32  a53_cpu0_drf_bist_fail0_itag:2;
        RBus_UInt32  a53_cpu0_drf_bist_fail0_btac0:1;
        RBus_UInt32  a53_cpu0_drf_bist_fail0_btac1:1;
        RBus_UInt32  a53_cpu0_drf_bist_fail0_tlb:4;
        RBus_UInt32  a53_cpu0_drf_bist_fail0_scu:4;
        RBus_UInt32  res1:5;
    };
}scpu_core_coordinator_status_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53_cpu1_drf_bist_fail0_ddata:8;
        RBus_UInt32  a53_cpu1_drf_bist_fail0_dtag:4;
        RBus_UInt32  a53_cpu1_drf_bist_fail0_ddirty:1;
        RBus_UInt32  a53_cpu1_drf_bist_fail0_idata:2;
        RBus_UInt32  a53_cpu1_drf_bist_fail0_itag:2;
        RBus_UInt32  a53_cpu1_drf_bist_fail0_btac0:1;
        RBus_UInt32  a53_cpu1_drf_bist_fail0_btac1:1;
        RBus_UInt32  a53_cpu1_drf_bist_fail0_tlb:4;
        RBus_UInt32  a53_cpu1_drf_bist_fail0_scu:4;
        RBus_UInt32  res1:5;
    };
}scpu_core_coordinator_status_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53_drf_bist_fail0_l2_tag:16;
        RBus_UInt32  a53_drf_bist_fail0_l2_victim:1;
        RBus_UInt32  res1:15;
    };
}scpu_core_coordinator_status_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53_cpu1_bist_fail0_ddata:8;
        RBus_UInt32  a53_cpu1_bist_fail0_dtag:4;
        RBus_UInt32  a53_cpu1_bist_fail0_ddirty:1;
        RBus_UInt32  a53_cpu1_bist_fail0_idata:2;
        RBus_UInt32  a53_cpu1_bist_fail0_itag:2;
        RBus_UInt32  a53_cpu1_bist_fail0_btac0:1;
        RBus_UInt32  a53_cpu1_bist_fail0_btac1:1;
        RBus_UInt32  a53_cpu1_bist_fail0_tlb:4;
        RBus_UInt32  a53_cpu1_bist_fail0_scu:4;
        RBus_UInt32  res1:5;
    };
}scpu_core_coordinator_status_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53_cpu2_bist_fail0_ddata:8;
        RBus_UInt32  a53_cpu2_bist_fail0_dtag:4;
        RBus_UInt32  a53_cpu2_bist_fail0_ddirty:1;
        RBus_UInt32  a53_cpu2_bist_fail0_idata:2;
        RBus_UInt32  a53_cpu2_bist_fail0_itag:2;
        RBus_UInt32  a53_cpu2_bist_fail0_btac0:1;
        RBus_UInt32  a53_cpu2_bist_fail0_btac1:1;
        RBus_UInt32  a53_cpu2_bist_fail0_tlb:4;
        RBus_UInt32  a53_cpu2_bist_fail0_scu:4;
        RBus_UInt32  res1:5;
    };
}scpu_core_coordinator_status_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53_cpu3_bist_fail0_ddata:8;
        RBus_UInt32  a53_cpu3_bist_fail0_dtag:4;
        RBus_UInt32  a53_cpu3_bist_fail0_ddirty:1;
        RBus_UInt32  a53_cpu3_bist_fail0_idata:2;
        RBus_UInt32  a53_cpu3_bist_fail0_itag:2;
        RBus_UInt32  a53_cpu3_bist_fail0_btac0:1;
        RBus_UInt32  a53_cpu3_bist_fail0_btac1:1;
        RBus_UInt32  a53_cpu3_bist_fail0_tlb:4;
        RBus_UInt32  a53_cpu3_bist_fail0_scu:4;
        RBus_UInt32  res1:5;
    };
}scpu_core_coordinator_status_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53_cpu2_drf_bist_fail0_ddata:8;
        RBus_UInt32  a53_cpu2_drf_bist_fail0_dtag:4;
        RBus_UInt32  a53_cpu2_drf_bist_fail0_ddirty:1;
        RBus_UInt32  a53_cpu2_drf_bist_fail0_idata:2;
        RBus_UInt32  a53_cpu2_drf_bist_fail0_itag:2;
        RBus_UInt32  a53_cpu2_drf_bist_fail0_btac0:1;
        RBus_UInt32  a53_cpu2_drf_bist_fail0_btac1:1;
        RBus_UInt32  a53_cpu2_drf_bist_fail0_tlb:4;
        RBus_UInt32  a53_cpu2_drf_bist_fail0_scu:4;
        RBus_UInt32  res1:5;
    };
}scpu_core_coordinator_status_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53_cpu3_drf_bist_fail0_ddata:8;
        RBus_UInt32  a53_cpu3_drf_bist_fail0_dtag:4;
        RBus_UInt32  a53_cpu3_drf_bist_fail0_ddirty:1;
        RBus_UInt32  a53_cpu3_drf_bist_fail0_idata:2;
        RBus_UInt32  a53_cpu3_drf_bist_fail0_itag:2;
        RBus_UInt32  a53_cpu3_drf_bist_fail0_btac0:1;
        RBus_UInt32  a53_cpu3_drf_bist_fail0_btac1:1;
        RBus_UInt32  a53_cpu3_drf_bist_fail0_tlb:4;
        RBus_UInt32  a53_cpu3_drf_bist_fail0_scu:4;
        RBus_UInt32  res1:5;
    };
}scpu_core_coordinator_status_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbistack0_dbg:1;
        RBus_UInt32  a53_mbistack_all:1;
        RBus_UInt32  mbistack1_dbg:1;
        RBus_UInt32  res1:29;
    };
}scpu_core_coordinator_status_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  partnumber:12;
        RBus_UInt32  revision:4;
    };
}scpu_core_general_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dbgromaddrv:1;
        RBus_UInt32  dbgromaddr_39_12:28;
    };
}scpu_core_general_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  a53l2flushreq:1;
        RBus_UInt32  res2:1;
    };
}scpu_core_ace_master_a53_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  dbgen_auth_slave_a53_source_sel:1;
        RBus_UInt32  niden_auth_slave_a53_source_sel:1;
        RBus_UInt32  spiden_auth_slave_a53_source_sel:1;
        RBus_UInt32  spniden_auth_slave_a53_source_sel:1;
    };
}scpu_core_auth_slave_a53_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  a53dbgpwrdup:2;
        RBus_UInt32  a53dbgl1rstdisable:1;
        RBus_UInt32  a53cfgend:2;
        RBus_UInt32  a53cfgte:2;
        RBus_UInt32  a53cp15sdisable:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  a53l2rstdisable:1;
        RBus_UInt32  a53vinithi:2;
        RBus_UInt32  a53aa64naa32:2;
        RBus_UInt32  a53cryptodisable:2;
    };
}scpu_core_config_a53_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  a53rvbaraddr0_39_32:8;
    };
}scpu_core_config_a53_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53rvbaraddr0_31_2:30;
        RBus_UInt32  res1:2;
    };
}scpu_core_config_a53_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  a53rvbaraddr1_39_32:8;
    };
}scpu_core_config_a53_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53rvbaraddr1_31_2:30;
        RBus_UInt32  res1:2;
    };
}scpu_core_config_a53_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  a53l2flushdone:1;
        RBus_UInt32  a53smpen:2;
        RBus_UInt32  a53standbywfe:2;
        RBus_UInt32  a53standbywfi:2;
        RBus_UInt32  a53standbywfil2:1;
    };
}scpu_core_status_a53_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  a53pmuevent0:30;
    };
}scpu_core_status_a53_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  a53pmuevent1:30;
    };
}scpu_core_status_a53_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  res2:2;
        RBus_UInt32  a53dbgnopwrdwn:2;
        RBus_UInt32  a53dbgpwrupreq:2;
    };
}scpu_core_power_a53_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  a53dbgrstreq:2;
        RBus_UInt32  a53warmrstreq:2;
    };
}scpu_core_misc_a53_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  a53dbgpwrdup_3_2:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  a53cfgend_3_2:2;
        RBus_UInt32  a53cfgte_3_2:2;
        RBus_UInt32  a53cp15sdisable_3_2:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  a53vinithi_3_2:2;
        RBus_UInt32  a53aa64naa32_3_2:2;
        RBus_UInt32  a53cryptodisable_3_2:2;
    };
}scpu_core_config_a53_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  a53rvbaraddr2_39_32:8;
    };
}scpu_core_config_a53_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53rvbaraddr2_31_2:30;
        RBus_UInt32  res1:2;
    };
}scpu_core_config_a53_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  a53rvbaraddr3_39_32:8;
    };
}scpu_core_config_a53_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53rvbaraddr3_31_2:30;
        RBus_UInt32  res1:2;
    };
}scpu_core_config_a53_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  a53smpen_3_2:2;
        RBus_UInt32  res2:4;
        RBus_UInt32  a53standbywfe_3_2:2;
        RBus_UInt32  a53standbywfi_3_2:2;
        RBus_UInt32  res3:1;
    };
}scpu_core_status_a53_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  a53pmuevent2:30;
    };
}scpu_core_status_a53_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  a53pmuevent3:30;
    };
}scpu_core_status_a53_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  res2:2;
        RBus_UInt32  a53dbgnopwrdwn_3_2:2;
        RBus_UInt32  a53dbgpwrupreq_3_2:2;
    };
}scpu_core_power_a53_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  a53dbgrstreq_3_2:2;
        RBus_UInt32  a53warmrstreq_3_2:2;
    };
}scpu_core_misc_a53_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  a53_trace_tpctl:1;
        RBus_UInt32  a53_trace_tpmaxdatasize:5;
        RBus_UInt32  res2:2;
        RBus_UInt32  dbgen_authenticationinterface_cssys:1;
        RBus_UInt32  niden_authenticationinterface_cssys:1;
    };
}scpu_core_cs_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  ejtag_chain_mode:1;
        RBus_UInt32  srstconnected:8;
        RBus_UInt32  portenabled:8;
        RBus_UInt32  portconnected:8;
    };
}scpu_core_ejtag_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  csrtck_dly_2:2;
        RBus_UInt32  csrtck_dly_1:2;
        RBus_UInt32  csrtck_dly_0:2;
    };
}scpu_core_ejtag_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  status_status_jtagnsw:1;
        RBus_UInt32  status_status_jtagtop:1;
        RBus_UInt32  nsrstout:8;
    };
}scpu_core_ejtag_status_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  exok_en:1;
    };
}scpu_core_exok_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  a53_warmrstirq3:1;
        RBus_UInt32  a53_warmrstirq2:1;
        RBus_UInt32  a53_warmrstirq1:1;
        RBus_UInt32  a53_warmrstirq0:1;
        RBus_UInt32  a53_ctiirq3:1;
        RBus_UInt32  a53_ctiirq2:1;
        RBus_UInt32  a53_ctiirq1:1;
        RBus_UInt32  a53_ctiirq0:1;
        RBus_UInt32  a53_npmuirq3:1;
        RBus_UInt32  a53_npmuirq2:1;
        RBus_UInt32  a53_npmuirq1:1;
        RBus_UInt32  a53_npmuirq0:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  na53exterrirq:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  irq_nirqout3:1;
        RBus_UInt32  irq_nirqout2:1;
        RBus_UInt32  irq_nirqout1:1;
        RBus_UInt32  irq_nirqout0:1;
        RBus_UInt32  irq_nfiqout3:1;
        RBus_UInt32  irq_nfiqout2:1;
        RBus_UInt32  irq_nfiqout1:1;
        RBus_UInt32  irq_nfiqout0:1;
    };
}scpu_core_interrupt_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  a53_warmrstirq3_en:1;
        RBus_UInt32  a53_warmrstirq2_en:1;
        RBus_UInt32  a53_warmrstirq1_en:1;
        RBus_UInt32  a53_warmrstirq0_en:1;
        RBus_UInt32  a53_ctiirq3_en:1;
        RBus_UInt32  a53_ctiirq2_en:1;
        RBus_UInt32  a53_ctiirq1_en:1;
        RBus_UInt32  a53_ctiirq0_en:1;
        RBus_UInt32  a53_npmuirq3_en:1;
        RBus_UInt32  a53_npmuirq2_en:1;
        RBus_UInt32  a53_npmuirq1_en:1;
        RBus_UInt32  a53_npmuirq0_en:1;
        RBus_UInt32  irq_dest_sel:1;
        RBus_UInt32  na53exterrirq_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  irq_nirqout3_en:1;
        RBus_UInt32  irq_nirqout2_en:1;
        RBus_UInt32  irq_nirqout1_en:1;
        RBus_UInt32  irq_nirqout0_en:1;
        RBus_UInt32  irq_nfiqout3_en:1;
        RBus_UInt32  irq_nfiqout2_en:1;
        RBus_UInt32  irq_nfiqout1_en:1;
        RBus_UInt32  irq_nfiqout0_en:1;
    };
}scpu_core_interrupt_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  cfgsdisable:1;
    };
}scpu_core_gic_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eco_rw:32;
    };
}scpu_core_eco_rw_reg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eco_r_only:32;
    };
}scpu_core_eco_r_reg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  a53_tie0:1;
    };
}scpu_core_a53_tie_reg_RBUS;

#else //apply LITTLE_ENDIAN

//======SCPU_CORE register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllscpu_lpf_rs:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pllscpu_pdiv:2;
        RBus_UInt32  pllscpu_pdiv_bps:1;
        RBus_UInt32  pllscpu_dbug_en:1;
        RBus_UInt32  pllscpu_icp:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllscpu_sel_cco:1;
        RBus_UInt32  pllscpu_testsel:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  pllscpu_lpf_cs:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  pllscpu_wdrst:1;
        RBus_UInt32  pllscpu_wdset:1;
        RBus_UInt32  res5:10;
    };
}scpu_core_sys_pll_scpu1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllscpu_pow:1;
        RBus_UInt32  pllscpu_rstb:1;
        RBus_UInt32  pllscpu_oeb:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pllscpu_ncode:8;
        RBus_UInt32  pllscpu_fcode:11;
        RBus_UInt32  res3:5;
    };
}scpu_core_sys_pll_scpu2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllscpu_oc_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  pllscpu_sdm_order:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllscpu_oc_step:10;
        RBus_UInt32  pllscpu_oc_done_delay:6;
        RBus_UInt32  pllscpu_ldo18v_sel:2;
        RBus_UInt32  pllscpu_ldo10v_sel:2;
        RBus_UInt32  pllscpu_sel_oc_mode:2;
        RBus_UInt32  pllscpu_pi_cur_sel:2;
        RBus_UInt32  pllscpu_hs_oc_stop:2;
        RBus_UInt32  pllscpu_en_pi_debug:1;
        RBus_UInt32  pllscpu_bypass_pi:1;
    };
}scpu_core_sys_scpu_dvfs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllscpu_dfvs_fmod_dbg:1;
        RBus_UInt32  pllscpu_fcode_dbg_ro:11;
        RBus_UInt32  pllscpu_ncode_dbg_ro:8;
        RBus_UInt32  pllscpu_oc_done_ro:1;
        RBus_UInt32  pllscpu_wdout_ro:1;
        RBus_UInt32  res1:10;
    };
}scpu_core_sys_scpu_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllscpu_reserve:6;
        RBus_UInt32  res1:26;
    };
}scpu_core_sys_scpu_reserve_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scpu_ssc_ckinv:1;
        RBus_UInt32  res1:31;
    };
}scpu_core_sys_scpu_ckinv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clkratio_scpu:5;
        RBus_UInt32  res1:27;
    };
}scpu_core_sys_scpu_clkratio_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clkratio_scpu_active:1;
        RBus_UInt32  res1:31;
    };
}scpu_core_sys_scpu_clkratio_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clken_top_ts:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  clken_scpu_top_logic:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  clken_a53:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  clken_top_apb:1;
        RBus_UInt32  clken_top_atb:1;
        RBus_UInt32  clken_a53_apb:1;
        RBus_UInt32  clken_a53_atb:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  clken_dss:1;
        RBus_UInt32  res5:17;
    };
}scpu_core_sys_scpu_clken_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  trc_clkdiv_sel:2;
        RBus_UInt32  trc_clk_delay:4;
        RBus_UInt32  res1:26;
    };
}scpu_core_sys_scpu_clkdiv_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scpu_gic_rstn:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  scpu_core3_poreset_n:1;
        RBus_UInt32  scpu_core2_poreset_n:1;
        RBus_UInt32  scpu_core3_rstn:1;
        RBus_UInt32  scpu_core2_rstn:1;
        RBus_UInt32  scpu_l2_rstn:1;
        RBus_UInt32  scpu_dbg_rstn:1;
        RBus_UInt32  scpu_core1_poreset_n:1;
        RBus_UInt32  scpu_core0_poreset_n:1;
        RBus_UInt32  scpu_core1_rstn:1;
        RBus_UInt32  scpu_core0_rstn:1;
        RBus_UInt32  scpu_nic_rstn:1;
        RBus_UInt32  resetsocdbgn:1;
        RBus_UInt32  res2:17;
    };
}scpu_core_sys_scpu_rst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53_warmreset_en:1;
        RBus_UInt32  res1:31;
    };
}scpu_core_sys_warmrst_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  voltprob_scpu_lvl_gnd_ctrl:1;
        RBus_UInt32  voltprob_scpu_lvl_pwr_ctrl:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  voltprob_a53_c0_gnd_ctrl:2;
        RBus_UInt32  voltprob_a53_c0_pwr_ctrl:2;
        RBus_UInt32  res2:24;
    };
}scpu_core_voltage_probe_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  a53_speed_en_1:1;
        RBus_UInt32  a53_speed_en_0:1;
        RBus_UInt32  a53_wire_sel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  a53_ro_sel:3;
        RBus_UInt32  a53_dss_rst_n:1;
    };
}scpu_core_dss_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  scpu_c31_9p5t_wire_sel:1;
        RBus_UInt32  scpu_c31_9p5t_speed_en:1;
        RBus_UInt32  scpu_c31_9p5t_ro_sel:3;
        RBus_UInt32  scpu_c31_9p5t_dss_rst_n:1;
        RBus_UInt32  scpu_c31_9p5t_data_in:20;
    };
}scpu_core_dss_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  scpu_c35_9p5t_wire_sel:1;
        RBus_UInt32  scpu_c35_9p5t_speed_en:1;
        RBus_UInt32  scpu_c35_9p5t_ro_sel:3;
        RBus_UInt32  scpu_c35_9p5t_dss_rst_n:1;
        RBus_UInt32  scpu_c35_9p5t_data_in:20;
    };
}scpu_core_dss_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  scpu_c38_9p5t_wire_sel:1;
        RBus_UInt32  scpu_c38_9p5t_speed_en:1;
        RBus_UInt32  scpu_c38_9p5t_ro_sel:3;
        RBus_UInt32  scpu_c38_9p5t_dss_rst_n:1;
        RBus_UInt32  scpu_c38_9p5t_data_in:20;
    };
}scpu_core_dss_ctrl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  a53_count_out_0:20;
        RBus_UInt32  a53_ready_0:1;
    };
}scpu_core_dss_status_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  a53_count_out_1:20;
        RBus_UInt32  a53_ready_1:1;
    };
}scpu_core_dss_status_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  scpu_c31_9p5t_wsort_go_ro:1;
        RBus_UInt32  scpu_c31_9p5t_ready_ro:1;
        RBus_UInt32  scpu_c31_9p5t_count_out_ro:20;
    };
}scpu_core_dss_status_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  scpu_c31_9p5t_dbgo_ro:16;
    };
}scpu_core_dss_status_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  scpu_c35_9p5t_wsort_go_ro:1;
        RBus_UInt32  scpu_c35_9p5t_ready_ro:1;
        RBus_UInt32  scpu_c35_9p5t_count_out_ro:20;
    };
}scpu_core_dss_status_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  scpu_c35_9p5t_dbgo_ro:16;
    };
}scpu_core_dss_status_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  scpu_c38_9p5t_wsort_go_ro:1;
        RBus_UInt32  scpu_c38_9p5t_ready_ro:1;
        RBus_UInt32  scpu_c38_9p5t_count_out_ro:20;
    };
}scpu_core_dss_status_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  scpu_c38_9p5t_dbgo_ro:16;
    };
}scpu_core_dss_status_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  pllscpu_dss_wire_sel:1;
        RBus_UInt32  pllscpu_dss_speed_en:1;
        RBus_UInt32  pllscpu_dss_ro_sel:3;
        RBus_UInt32  pllscpu_dss_rst_n:1;
        RBus_UInt32  pllscpu_dss_data_in:20;
    };
}scpu_core_dss_ctrl_pllscpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  pllscpu_dss_wsort_go:1;
        RBus_UInt32  pllscpu_dss_ready:1;
        RBus_UInt32  pllscpu_dss_count_out:20;
    };
}scpu_core_dss_status_pllscpu_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  pllscpu_dss_dbgo:16;
    };
}scpu_core_dss_status_pllscpu_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53_ls_off:1;
        RBus_UInt32  res1:18;
        RBus_UInt32  a53_sd_l1_3:1;
        RBus_UInt32  a53_sd_l1_2:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  a53_ds_l1_3:1;
        RBus_UInt32  a53_ds_l1_2:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  a53_sd_l1_1:1;
        RBus_UInt32  a53_sd_l1_0:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  a53_ds_l1_1:1;
        RBus_UInt32  a53_ds_l1_0:1;
        RBus_UInt32  a53_rme:1;
    };
}scpu_core_sram_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53_rm_47_32:16;
        RBus_UInt32  res1:16;
    };
}scpu_core_sram_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53_rm_31_0:32;
    };
}scpu_core_sram_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  a53_core_clamp_en_3_2:2;
        RBus_UInt32  a53_core_pwrctrl_in_3_2:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  a53_core_clamp_en:2;
        RBus_UInt32  a53_core_pwrctrl_in:2;
    };
}scpu_core_low_power_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  a53_power_delay_value:8;
        RBus_UInt32  res2:1;
        RBus_UInt32  a53_power_mode_sel:1;
        RBus_UInt32  res3:14;
    };
}scpu_core_low_power_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  a53_core_pwrctrl_out_3_2:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  a53_core_pwrctrl_out:2;
    };
}scpu_core_low_power_status_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  a53_second_run_en:1;
        RBus_UInt32  a53_drf_bisr_test_resume:1;
        RBus_UInt32  a53_drf_bisr_mode:1;
        RBus_UInt32  res2:1;
    };
}scpu_core_mbisr_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  a53_bisr_fail:8;
        RBus_UInt32  a53_drf_bisr_start_pause:1;
        RBus_UInt32  a53_drf_bisr_fail:8;
        RBus_UInt32  a53_drf_bisr_done:1;
    };
}scpu_core_mbisr_status_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53_bisr_repaired:1;
        RBus_UInt32  res1:31;
    };
}scpu_core_mbisr_status_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53_bisr_out_55_32:24;
        RBus_UInt32  res1:8;
    };
}scpu_core_mbisr_status_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53_bisr_out_31_0:32;
    };
}scpu_core_mbisr_status_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  a53_diag_mode1_mbistarray1:2;
        RBus_UInt32  a53_diag_mode1_l2_data:1;
        RBus_UInt32  a53_bist_mode1_l2_data:1;
        RBus_UInt32  mbist1_all_mode:1;
        RBus_UInt32  mbist0_all_mode:1;
        RBus_UInt32  a53_drf_test_resume0:1;
        RBus_UInt32  a53_drf_bist_mode0:1;
        RBus_UInt32  a53_bist_mode0_l2_victim:1;
        RBus_UInt32  a53_bist_mode0_l2_tag:1;
        RBus_UInt32  a53_bist_mode0_scu:1;
        RBus_UInt32  a53_bist_mode0_tlb:1;
        RBus_UInt32  a53_bist_mode0_btac1:1;
        RBus_UInt32  a53_bist_mode0_btac0:1;
        RBus_UInt32  a53_bist_mode0_itag:1;
        RBus_UInt32  a53_bist_mode0_idata:1;
        RBus_UInt32  a53_bist_mode0_ddirty:1;
        RBus_UInt32  a53_bist_mode0_dtag:1;
        RBus_UInt32  a53_bist_mode0_ddata:1;
        RBus_UInt32  a53_bist_mode0_all:1;
        RBus_UInt32  a53_bist_rstn:1;
        RBus_UInt32  a53_share_bus_en:1;
        RBus_UInt32  res2:1;
    };
}scpu_core_coordinator_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  a53_bist_done1_l2_data:1;
        RBus_UInt32  a53_cpu0_bist_fail0_btac1:1;
        RBus_UInt32  a53_cpu0_bist_fail0_btac0:1;
        RBus_UInt32  a53_cpu0_bist_fail0_itag:2;
        RBus_UInt32  a53_cpu0_bist_fail0_idata:2;
        RBus_UInt32  a53_cpu0_bist_fail0_ddirty:1;
        RBus_UInt32  a53_cpu0_bist_fail0_dtag:4;
        RBus_UInt32  a53_cpu0_bist_fail0_ddata:8;
        RBus_UInt32  a53_bist_done0_l2_victim:1;
        RBus_UInt32  a53_bist_done0_l2_tag:1;
        RBus_UInt32  a53_bist_done0_scu:1;
        RBus_UInt32  a53_bist_done0_tlb:1;
        RBus_UInt32  a53_bist_done0_btac1:1;
        RBus_UInt32  a53_bist_done0_btac0:1;
        RBus_UInt32  a53_bist_done0_itag:1;
        RBus_UInt32  a53_bist_done0_idata:1;
        RBus_UInt32  a53_bist_done0_ddirty:1;
        RBus_UInt32  a53_bist_done0_dtag:1;
        RBus_UInt32  a53_bist_done0_ddata:1;
    };
}scpu_core_coordinator_status_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53_bist_fail1_l2_data:4;
        RBus_UInt32  res1:1;
        RBus_UInt32  a53_drf_bist_done0:1;
        RBus_UInt32  a53_drf_start_pause0:1;
        RBus_UInt32  a53_bist_fail0_l2_victim:1;
        RBus_UInt32  a53_bist_fail0_l2_tag:16;
        RBus_UInt32  a53_cpu0_bist_fail0_scu:4;
        RBus_UInt32  a53_cpu0_bist_fail0_tlb:4;
    };
}scpu_core_coordinator_status_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  a53_cpu0_drf_bist_fail0_scu:4;
        RBus_UInt32  a53_cpu0_drf_bist_fail0_tlb:4;
        RBus_UInt32  a53_cpu0_drf_bist_fail0_btac1:1;
        RBus_UInt32  a53_cpu0_drf_bist_fail0_btac0:1;
        RBus_UInt32  a53_cpu0_drf_bist_fail0_itag:2;
        RBus_UInt32  a53_cpu0_drf_bist_fail0_idata:2;
        RBus_UInt32  a53_cpu0_drf_bist_fail0_ddirty:1;
        RBus_UInt32  a53_cpu0_drf_bist_fail0_dtag:4;
        RBus_UInt32  a53_cpu0_drf_bist_fail0_ddata:8;
    };
}scpu_core_coordinator_status_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  a53_cpu1_drf_bist_fail0_scu:4;
        RBus_UInt32  a53_cpu1_drf_bist_fail0_tlb:4;
        RBus_UInt32  a53_cpu1_drf_bist_fail0_btac1:1;
        RBus_UInt32  a53_cpu1_drf_bist_fail0_btac0:1;
        RBus_UInt32  a53_cpu1_drf_bist_fail0_itag:2;
        RBus_UInt32  a53_cpu1_drf_bist_fail0_idata:2;
        RBus_UInt32  a53_cpu1_drf_bist_fail0_ddirty:1;
        RBus_UInt32  a53_cpu1_drf_bist_fail0_dtag:4;
        RBus_UInt32  a53_cpu1_drf_bist_fail0_ddata:8;
    };
}scpu_core_coordinator_status_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  a53_drf_bist_fail0_l2_victim:1;
        RBus_UInt32  a53_drf_bist_fail0_l2_tag:16;
    };
}scpu_core_coordinator_status_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  a53_cpu1_bist_fail0_scu:4;
        RBus_UInt32  a53_cpu1_bist_fail0_tlb:4;
        RBus_UInt32  a53_cpu1_bist_fail0_btac1:1;
        RBus_UInt32  a53_cpu1_bist_fail0_btac0:1;
        RBus_UInt32  a53_cpu1_bist_fail0_itag:2;
        RBus_UInt32  a53_cpu1_bist_fail0_idata:2;
        RBus_UInt32  a53_cpu1_bist_fail0_ddirty:1;
        RBus_UInt32  a53_cpu1_bist_fail0_dtag:4;
        RBus_UInt32  a53_cpu1_bist_fail0_ddata:8;
    };
}scpu_core_coordinator_status_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  a53_cpu2_bist_fail0_scu:4;
        RBus_UInt32  a53_cpu2_bist_fail0_tlb:4;
        RBus_UInt32  a53_cpu2_bist_fail0_btac1:1;
        RBus_UInt32  a53_cpu2_bist_fail0_btac0:1;
        RBus_UInt32  a53_cpu2_bist_fail0_itag:2;
        RBus_UInt32  a53_cpu2_bist_fail0_idata:2;
        RBus_UInt32  a53_cpu2_bist_fail0_ddirty:1;
        RBus_UInt32  a53_cpu2_bist_fail0_dtag:4;
        RBus_UInt32  a53_cpu2_bist_fail0_ddata:8;
    };
}scpu_core_coordinator_status_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  a53_cpu3_bist_fail0_scu:4;
        RBus_UInt32  a53_cpu3_bist_fail0_tlb:4;
        RBus_UInt32  a53_cpu3_bist_fail0_btac1:1;
        RBus_UInt32  a53_cpu3_bist_fail0_btac0:1;
        RBus_UInt32  a53_cpu3_bist_fail0_itag:2;
        RBus_UInt32  a53_cpu3_bist_fail0_idata:2;
        RBus_UInt32  a53_cpu3_bist_fail0_ddirty:1;
        RBus_UInt32  a53_cpu3_bist_fail0_dtag:4;
        RBus_UInt32  a53_cpu3_bist_fail0_ddata:8;
    };
}scpu_core_coordinator_status_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  a53_cpu2_drf_bist_fail0_scu:4;
        RBus_UInt32  a53_cpu2_drf_bist_fail0_tlb:4;
        RBus_UInt32  a53_cpu2_drf_bist_fail0_btac1:1;
        RBus_UInt32  a53_cpu2_drf_bist_fail0_btac0:1;
        RBus_UInt32  a53_cpu2_drf_bist_fail0_itag:2;
        RBus_UInt32  a53_cpu2_drf_bist_fail0_idata:2;
        RBus_UInt32  a53_cpu2_drf_bist_fail0_ddirty:1;
        RBus_UInt32  a53_cpu2_drf_bist_fail0_dtag:4;
        RBus_UInt32  a53_cpu2_drf_bist_fail0_ddata:8;
    };
}scpu_core_coordinator_status_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  a53_cpu3_drf_bist_fail0_scu:4;
        RBus_UInt32  a53_cpu3_drf_bist_fail0_tlb:4;
        RBus_UInt32  a53_cpu3_drf_bist_fail0_btac1:1;
        RBus_UInt32  a53_cpu3_drf_bist_fail0_btac0:1;
        RBus_UInt32  a53_cpu3_drf_bist_fail0_itag:2;
        RBus_UInt32  a53_cpu3_drf_bist_fail0_idata:2;
        RBus_UInt32  a53_cpu3_drf_bist_fail0_ddirty:1;
        RBus_UInt32  a53_cpu3_drf_bist_fail0_dtag:4;
        RBus_UInt32  a53_cpu3_drf_bist_fail0_ddata:8;
    };
}scpu_core_coordinator_status_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  mbistack1_dbg:1;
        RBus_UInt32  a53_mbistack_all:1;
        RBus_UInt32  mbistack0_dbg:1;
    };
}scpu_core_coordinator_status_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  revision:4;
        RBus_UInt32  partnumber:12;
        RBus_UInt32  res1:16;
    };
}scpu_core_general_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbgromaddr_39_12:28;
        RBus_UInt32  dbgromaddrv:1;
        RBus_UInt32  res1:3;
    };
}scpu_core_general_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  a53l2flushreq:1;
        RBus_UInt32  res2:30;
    };
}scpu_core_ace_master_a53_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  spniden_auth_slave_a53_source_sel:1;
        RBus_UInt32  spiden_auth_slave_a53_source_sel:1;
        RBus_UInt32  niden_auth_slave_a53_source_sel:1;
        RBus_UInt32  dbgen_auth_slave_a53_source_sel:1;
        RBus_UInt32  res1:28;
    };
}scpu_core_auth_slave_a53_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53cryptodisable:2;
        RBus_UInt32  a53aa64naa32:2;
        RBus_UInt32  a53vinithi:2;
        RBus_UInt32  a53l2rstdisable:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  a53cp15sdisable:2;
        RBus_UInt32  a53cfgte:2;
        RBus_UInt32  a53cfgend:2;
        RBus_UInt32  a53dbgl1rstdisable:1;
        RBus_UInt32  a53dbgpwrdup:2;
        RBus_UInt32  res2:15;
    };
}scpu_core_config_a53_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53rvbaraddr0_39_32:8;
        RBus_UInt32  res1:24;
    };
}scpu_core_config_a53_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  a53rvbaraddr0_31_2:30;
    };
}scpu_core_config_a53_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53rvbaraddr1_39_32:8;
        RBus_UInt32  res1:24;
    };
}scpu_core_config_a53_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  a53rvbaraddr1_31_2:30;
    };
}scpu_core_config_a53_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53standbywfil2:1;
        RBus_UInt32  a53standbywfi:2;
        RBus_UInt32  a53standbywfe:2;
        RBus_UInt32  a53smpen:2;
        RBus_UInt32  a53l2flushdone:1;
        RBus_UInt32  res1:24;
    };
}scpu_core_status_a53_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53pmuevent0:30;
        RBus_UInt32  res1:2;
    };
}scpu_core_status_a53_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53pmuevent1:30;
        RBus_UInt32  res1:2;
    };
}scpu_core_status_a53_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53dbgpwrupreq:2;
        RBus_UInt32  a53dbgnopwrdwn:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  res2:26;
    };
}scpu_core_power_a53_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53warmrstreq:2;
        RBus_UInt32  a53dbgrstreq:2;
        RBus_UInt32  res1:28;
    };
}scpu_core_misc_a53_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53cryptodisable_3_2:2;
        RBus_UInt32  a53aa64naa32_3_2:2;
        RBus_UInt32  a53vinithi_3_2:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  a53cp15sdisable_3_2:2;
        RBus_UInt32  a53cfgte_3_2:2;
        RBus_UInt32  a53cfgend_3_2:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  a53dbgpwrdup_3_2:2;
        RBus_UInt32  res3:15;
    };
}scpu_core_config_a53_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53rvbaraddr2_39_32:8;
        RBus_UInt32  res1:24;
    };
}scpu_core_config_a53_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  a53rvbaraddr2_31_2:30;
    };
}scpu_core_config_a53_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53rvbaraddr3_39_32:8;
        RBus_UInt32  res1:24;
    };
}scpu_core_config_a53_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  a53rvbaraddr3_31_2:30;
    };
}scpu_core_config_a53_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  a53standbywfi_3_2:2;
        RBus_UInt32  a53standbywfe_3_2:2;
        RBus_UInt32  res2:4;
        RBus_UInt32  a53smpen_3_2:2;
        RBus_UInt32  res3:21;
    };
}scpu_core_status_a53_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53pmuevent2:30;
        RBus_UInt32  res1:2;
    };
}scpu_core_status_a53_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53pmuevent3:30;
        RBus_UInt32  res1:2;
    };
}scpu_core_status_a53_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53dbgpwrupreq_3_2:2;
        RBus_UInt32  a53dbgnopwrdwn_3_2:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  res2:26;
    };
}scpu_core_power_a53_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53warmrstreq_3_2:2;
        RBus_UInt32  a53dbgrstreq_3_2:2;
        RBus_UInt32  res1:28;
    };
}scpu_core_misc_a53_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  niden_authenticationinterface_cssys:1;
        RBus_UInt32  dbgen_authenticationinterface_cssys:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  a53_trace_tpmaxdatasize:5;
        RBus_UInt32  a53_trace_tpctl:1;
        RBus_UInt32  res2:22;
    };
}scpu_core_cs_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  portconnected:8;
        RBus_UInt32  portenabled:8;
        RBus_UInt32  srstconnected:8;
        RBus_UInt32  ejtag_chain_mode:1;
        RBus_UInt32  res1:7;
    };
}scpu_core_ejtag_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  csrtck_dly_0:2;
        RBus_UInt32  csrtck_dly_1:2;
        RBus_UInt32  csrtck_dly_2:2;
        RBus_UInt32  res1:26;
    };
}scpu_core_ejtag_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nsrstout:8;
        RBus_UInt32  status_status_jtagtop:1;
        RBus_UInt32  status_status_jtagnsw:1;
        RBus_UInt32  res1:22;
    };
}scpu_core_ejtag_status_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  exok_en:1;
        RBus_UInt32  res1:31;
    };
}scpu_core_exok_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  irq_nfiqout0:1;
        RBus_UInt32  irq_nfiqout1:1;
        RBus_UInt32  irq_nfiqout2:1;
        RBus_UInt32  irq_nfiqout3:1;
        RBus_UInt32  irq_nirqout0:1;
        RBus_UInt32  irq_nirqout1:1;
        RBus_UInt32  irq_nirqout2:1;
        RBus_UInt32  irq_nirqout3:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  na53exterrirq:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  a53_npmuirq0:1;
        RBus_UInt32  a53_npmuirq1:1;
        RBus_UInt32  a53_npmuirq2:1;
        RBus_UInt32  a53_npmuirq3:1;
        RBus_UInt32  a53_ctiirq0:1;
        RBus_UInt32  a53_ctiirq1:1;
        RBus_UInt32  a53_ctiirq2:1;
        RBus_UInt32  a53_ctiirq3:1;
        RBus_UInt32  a53_warmrstirq0:1;
        RBus_UInt32  a53_warmrstirq1:1;
        RBus_UInt32  a53_warmrstirq2:1;
        RBus_UInt32  a53_warmrstirq3:1;
        RBus_UInt32  res3:8;
    };
}scpu_core_interrupt_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  irq_nfiqout0_en:1;
        RBus_UInt32  irq_nfiqout1_en:1;
        RBus_UInt32  irq_nfiqout2_en:1;
        RBus_UInt32  irq_nfiqout3_en:1;
        RBus_UInt32  irq_nirqout0_en:1;
        RBus_UInt32  irq_nirqout1_en:1;
        RBus_UInt32  irq_nirqout2_en:1;
        RBus_UInt32  irq_nirqout3_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  na53exterrirq_en:1;
        RBus_UInt32  irq_dest_sel:1;
        RBus_UInt32  a53_npmuirq0_en:1;
        RBus_UInt32  a53_npmuirq1_en:1;
        RBus_UInt32  a53_npmuirq2_en:1;
        RBus_UInt32  a53_npmuirq3_en:1;
        RBus_UInt32  a53_ctiirq0_en:1;
        RBus_UInt32  a53_ctiirq1_en:1;
        RBus_UInt32  a53_ctiirq2_en:1;
        RBus_UInt32  a53_ctiirq3_en:1;
        RBus_UInt32  a53_warmrstirq0_en:1;
        RBus_UInt32  a53_warmrstirq1_en:1;
        RBus_UInt32  a53_warmrstirq2_en:1;
        RBus_UInt32  a53_warmrstirq3_en:1;
        RBus_UInt32  res2:8;
    };
}scpu_core_interrupt_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cfgsdisable:1;
        RBus_UInt32  res1:31;
    };
}scpu_core_gic_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eco_rw:32;
    };
}scpu_core_eco_rw_reg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eco_r_only:32;
    };
}scpu_core_eco_r_reg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a53_tie0:1;
        RBus_UInt32  res1:31;
    };
}scpu_core_a53_tie_reg_RBUS;




#endif 


#endif 
