/**
* @file rbusPINMUX_LVDSPHYReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_PINMUX_LVDSPHY_REG_H_
#define _RBUS_PINMUX_LVDSPHY_REG_H_

#include "rbus_types.h"



//  PINMUX_LVDSPHY Register Address
#define  PINMUX_LVDSPHY_LVDS_0                                                   0x18000C80
#define  PINMUX_LVDSPHY_LVDS_0_reg_addr                                          "0xB8000C80"
#define  PINMUX_LVDSPHY_LVDS_0_reg                                               0xB8000C80
#define  PINMUX_LVDSPHY_LVDS_0_inst_addr                                         "0x0000"
#define  set_PINMUX_LVDSPHY_LVDS_0_reg(data)                                     (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDS_0_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDS_0_reg                                           (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDS_0_reg))
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txgp_ps_shift                              (28)
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txgn_ps_shift                              (24)
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txfp_ps_shift                              (20)
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txfn_ps_shift                              (16)
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txep_ps_shift                              (12)
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txen_ps_shift                              (8)
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txdp_ps_shift                              (4)
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txdn_ps_shift                              (0)
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txgp_ps_mask                               (0xF0000000)
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txgn_ps_mask                               (0x0F000000)
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txfp_ps_mask                               (0x00F00000)
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txfn_ps_mask                               (0x000F0000)
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txep_ps_mask                               (0x0000F000)
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txen_ps_mask                               (0x00000F00)
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txdp_ps_mask                               (0x000000F0)
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txdn_ps_mask                               (0x0000000F)
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txgp_ps(data)                              (0xF0000000&((data)<<28))
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txgn_ps(data)                              (0x0F000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txfp_ps(data)                              (0x00F00000&((data)<<20))
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txfn_ps(data)                              (0x000F0000&((data)<<16))
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txep_ps(data)                              (0x0000F000&((data)<<12))
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txen_ps(data)                              (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txdp_ps(data)                              (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txdn_ps(data)                              (0x0000000F&(data))
#define  PINMUX_LVDSPHY_LVDS_0_get_plt_p0_txgp_ps(data)                          ((0xF0000000&(data))>>28)
#define  PINMUX_LVDSPHY_LVDS_0_get_plt_p0_txgn_ps(data)                          ((0x0F000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDS_0_get_plt_p0_txfp_ps(data)                          ((0x00F00000&(data))>>20)
#define  PINMUX_LVDSPHY_LVDS_0_get_plt_p0_txfn_ps(data)                          ((0x000F0000&(data))>>16)
#define  PINMUX_LVDSPHY_LVDS_0_get_plt_p0_txep_ps(data)                          ((0x0000F000&(data))>>12)
#define  PINMUX_LVDSPHY_LVDS_0_get_plt_p0_txen_ps(data)                          ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDS_0_get_plt_p0_txdp_ps(data)                          ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_LVDS_0_get_plt_p0_txdn_ps(data)                          (0x0000000F&(data))

#define  PINMUX_LVDSPHY_LVDS_1                                                   0x18000C84
#define  PINMUX_LVDSPHY_LVDS_1_reg_addr                                          "0xB8000C84"
#define  PINMUX_LVDSPHY_LVDS_1_reg                                               0xB8000C84
#define  PINMUX_LVDSPHY_LVDS_1_inst_addr                                         "0x0001"
#define  set_PINMUX_LVDSPHY_LVDS_1_reg(data)                                     (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDS_1_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDS_1_reg                                           (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDS_1_reg))
#define  PINMUX_LVDSPHY_LVDS_1_plt_p3_txdp_ps_shift                              (28)
#define  PINMUX_LVDSPHY_LVDS_1_plt_p3_txdn_ps_shift                              (24)
#define  PINMUX_LVDSPHY_LVDS_1_plt_p3_txcp_ps_shift                              (20)
#define  PINMUX_LVDSPHY_LVDS_1_plt_p3_txcn_ps_shift                              (16)
#define  PINMUX_LVDSPHY_LVDS_1_plt_p3_txbp_ps_shift                              (12)
#define  PINMUX_LVDSPHY_LVDS_1_plt_p3_txbn_ps_shift                              (8)
#define  PINMUX_LVDSPHY_LVDS_1_plt_p3_txap_ps_shift                              (4)
#define  PINMUX_LVDSPHY_LVDS_1_plt_p3_txan_ps_shift                              (0)
#define  PINMUX_LVDSPHY_LVDS_1_plt_p3_txdp_ps_mask                               (0xF0000000)
#define  PINMUX_LVDSPHY_LVDS_1_plt_p3_txdn_ps_mask                               (0x0F000000)
#define  PINMUX_LVDSPHY_LVDS_1_plt_p3_txcp_ps_mask                               (0x00F00000)
#define  PINMUX_LVDSPHY_LVDS_1_plt_p3_txcn_ps_mask                               (0x000F0000)
#define  PINMUX_LVDSPHY_LVDS_1_plt_p3_txbp_ps_mask                               (0x0000F000)
#define  PINMUX_LVDSPHY_LVDS_1_plt_p3_txbn_ps_mask                               (0x00000F00)
#define  PINMUX_LVDSPHY_LVDS_1_plt_p3_txap_ps_mask                               (0x000000F0)
#define  PINMUX_LVDSPHY_LVDS_1_plt_p3_txan_ps_mask                               (0x0000000F)
#define  PINMUX_LVDSPHY_LVDS_1_plt_p3_txdp_ps(data)                              (0xF0000000&((data)<<28))
#define  PINMUX_LVDSPHY_LVDS_1_plt_p3_txdn_ps(data)                              (0x0F000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDS_1_plt_p3_txcp_ps(data)                              (0x00F00000&((data)<<20))
#define  PINMUX_LVDSPHY_LVDS_1_plt_p3_txcn_ps(data)                              (0x000F0000&((data)<<16))
#define  PINMUX_LVDSPHY_LVDS_1_plt_p3_txbp_ps(data)                              (0x0000F000&((data)<<12))
#define  PINMUX_LVDSPHY_LVDS_1_plt_p3_txbn_ps(data)                              (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDS_1_plt_p3_txap_ps(data)                              (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_LVDS_1_plt_p3_txan_ps(data)                              (0x0000000F&(data))
#define  PINMUX_LVDSPHY_LVDS_1_get_plt_p3_txdp_ps(data)                          ((0xF0000000&(data))>>28)
#define  PINMUX_LVDSPHY_LVDS_1_get_plt_p3_txdn_ps(data)                          ((0x0F000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDS_1_get_plt_p3_txcp_ps(data)                          ((0x00F00000&(data))>>20)
#define  PINMUX_LVDSPHY_LVDS_1_get_plt_p3_txcn_ps(data)                          ((0x000F0000&(data))>>16)
#define  PINMUX_LVDSPHY_LVDS_1_get_plt_p3_txbp_ps(data)                          ((0x0000F000&(data))>>12)
#define  PINMUX_LVDSPHY_LVDS_1_get_plt_p3_txbn_ps(data)                          ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDS_1_get_plt_p3_txap_ps(data)                          ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_LVDS_1_get_plt_p3_txan_ps(data)                          (0x0000000F&(data))

#define  PINMUX_LVDSPHY_LVDS_2                                                   0x18000C88
#define  PINMUX_LVDSPHY_LVDS_2_reg_addr                                          "0xB8000C88"
#define  PINMUX_LVDSPHY_LVDS_2_reg                                               0xB8000C88
#define  PINMUX_LVDSPHY_LVDS_2_inst_addr                                         "0x0002"
#define  set_PINMUX_LVDSPHY_LVDS_2_reg(data)                                     (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDS_2_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDS_2_reg                                           (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDS_2_reg))
#define  PINMUX_LVDSPHY_LVDS_2_plt_p0_txcp_ps_shift                              (28)
#define  PINMUX_LVDSPHY_LVDS_2_plt_p0_txcn_ps_shift                              (24)
#define  PINMUX_LVDSPHY_LVDS_2_plt_p0_txbp_ps_shift                              (20)
#define  PINMUX_LVDSPHY_LVDS_2_plt_p0_txbn_ps_shift                              (16)
#define  PINMUX_LVDSPHY_LVDS_2_plt_p3_txep_ps_shift                              (12)
#define  PINMUX_LVDSPHY_LVDS_2_plt_p3_txen_ps_shift                              (8)
#define  PINMUX_LVDSPHY_LVDS_2_plt_p0_txcp_ps_mask                               (0xF0000000)
#define  PINMUX_LVDSPHY_LVDS_2_plt_p0_txcn_ps_mask                               (0x0F000000)
#define  PINMUX_LVDSPHY_LVDS_2_plt_p0_txbp_ps_mask                               (0x00F00000)
#define  PINMUX_LVDSPHY_LVDS_2_plt_p0_txbn_ps_mask                               (0x000F0000)
#define  PINMUX_LVDSPHY_LVDS_2_plt_p3_txep_ps_mask                               (0x0000F000)
#define  PINMUX_LVDSPHY_LVDS_2_plt_p3_txen_ps_mask                               (0x00000F00)
#define  PINMUX_LVDSPHY_LVDS_2_plt_p0_txcp_ps(data)                              (0xF0000000&((data)<<28))
#define  PINMUX_LVDSPHY_LVDS_2_plt_p0_txcn_ps(data)                              (0x0F000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDS_2_plt_p0_txbp_ps(data)                              (0x00F00000&((data)<<20))
#define  PINMUX_LVDSPHY_LVDS_2_plt_p0_txbn_ps(data)                              (0x000F0000&((data)<<16))
#define  PINMUX_LVDSPHY_LVDS_2_plt_p3_txep_ps(data)                              (0x0000F000&((data)<<12))
#define  PINMUX_LVDSPHY_LVDS_2_plt_p3_txen_ps(data)                              (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDS_2_get_plt_p0_txcp_ps(data)                          ((0xF0000000&(data))>>28)
#define  PINMUX_LVDSPHY_LVDS_2_get_plt_p0_txcn_ps(data)                          ((0x0F000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDS_2_get_plt_p0_txbp_ps(data)                          ((0x00F00000&(data))>>20)
#define  PINMUX_LVDSPHY_LVDS_2_get_plt_p0_txbn_ps(data)                          ((0x000F0000&(data))>>16)
#define  PINMUX_LVDSPHY_LVDS_2_get_plt_p3_txep_ps(data)                          ((0x0000F000&(data))>>12)
#define  PINMUX_LVDSPHY_LVDS_2_get_plt_p3_txen_ps(data)                          ((0x00000F00&(data))>>8)

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_4                                     0x18000C10
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_4_reg_addr                            "0xB8000C10"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_4_reg                                 0xB8000C10
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_4_inst_addr                           "0x0003"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_4_reg(data)                       (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_4_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_4_reg                             (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_4_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_4_plt_p0_txlap_mode_shift             (29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_4_plt_p0_txlan_mode_shift             (26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_4_plt_p0_txla_ckphs_shift             (24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_4_plt_p0_txla_sel_emp_shift           (21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_4_plt_p0_txla_sr_shift                (19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_4_plt_p0_txla_term_shift              (17)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_4_plt_p0_txl_epicml_shift             (0)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_4_plt_p0_txlap_mode_mask              (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_4_plt_p0_txlan_mode_mask              (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_4_plt_p0_txla_ckphs_mask              (0x03000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_4_plt_p0_txla_sel_emp_mask            (0x00E00000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_4_plt_p0_txla_sr_mask                 (0x00180000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_4_plt_p0_txla_term_mask               (0x00060000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_4_plt_p0_txl_epicml_mask              (0x0000007F)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_4_plt_p0_txlap_mode(data)             (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_4_plt_p0_txlan_mode(data)             (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_4_plt_p0_txla_ckphs(data)             (0x03000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_4_plt_p0_txla_sel_emp(data)           (0x00E00000&((data)<<21))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_4_plt_p0_txla_sr(data)                (0x00180000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_4_plt_p0_txla_term(data)              (0x00060000&((data)<<17))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_4_plt_p0_txl_epicml(data)             (0x0000007F&(data))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_4_get_plt_p0_txlap_mode(data)         ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_4_get_plt_p0_txlan_mode(data)         ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_4_get_plt_p0_txla_ckphs(data)         ((0x03000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_4_get_plt_p0_txla_sel_emp(data)       ((0x00E00000&(data))>>21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_4_get_plt_p0_txla_sr(data)            ((0x00180000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_4_get_plt_p0_txla_term(data)          ((0x00060000&(data))>>17)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_4_get_plt_p0_txl_epicml(data)         (0x0000007F&(data))

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_5                                     0x18000C14
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_5_reg_addr                            "0xB8000C14"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_5_reg                                 0xB8000C14
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_5_inst_addr                           "0x0004"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_5_reg(data)                       (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_5_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_5_reg                             (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_5_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_5_plt_p0_txlbp_mode_shift             (29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_5_plt_p0_txlbn_mode_shift             (26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_5_plt_p0_txlb_ckphs_shift             (24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_5_plt_p0_txlb_sel_emp_shift           (21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_5_plt_p0_txlb_sr_shift                (19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_5_plt_p0_txlb_term_shift              (17)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_5_plt_p0_txlbp_mode_mask              (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_5_plt_p0_txlbn_mode_mask              (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_5_plt_p0_txlb_ckphs_mask              (0x03000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_5_plt_p0_txlb_sel_emp_mask            (0x00E00000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_5_plt_p0_txlb_sr_mask                 (0x00180000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_5_plt_p0_txlb_term_mask               (0x00060000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_5_plt_p0_txlbp_mode(data)             (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_5_plt_p0_txlbn_mode(data)             (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_5_plt_p0_txlb_ckphs(data)             (0x03000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_5_plt_p0_txlb_sel_emp(data)           (0x00E00000&((data)<<21))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_5_plt_p0_txlb_sr(data)                (0x00180000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_5_plt_p0_txlb_term(data)              (0x00060000&((data)<<17))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_5_get_plt_p0_txlbp_mode(data)         ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_5_get_plt_p0_txlbn_mode(data)         ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_5_get_plt_p0_txlb_ckphs(data)         ((0x03000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_5_get_plt_p0_txlb_sel_emp(data)       ((0x00E00000&(data))>>21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_5_get_plt_p0_txlb_sr(data)            ((0x00180000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_5_get_plt_p0_txlb_term(data)          ((0x00060000&(data))>>17)

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_6                                     0x18000C18
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_6_reg_addr                            "0xB8000C18"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_6_reg                                 0xB8000C18
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_6_inst_addr                           "0x0005"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_6_reg(data)                       (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_6_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_6_reg                             (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_6_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_6_plt_p0_txlcp_mode_shift             (29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_6_plt_p0_txlcn_mode_shift             (26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_6_plt_p0_txlc_ckphs_shift             (24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_6_plt_p0_txlc_sel_emp_shift           (21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_6_plt_p0_txlc_sr_shift                (19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_6_plt_p0_txlc_term_shift              (17)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_6_plt_p0_txlcp_mode_mask              (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_6_plt_p0_txlcn_mode_mask              (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_6_plt_p0_txlc_ckphs_mask              (0x03000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_6_plt_p0_txlc_sel_emp_mask            (0x00E00000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_6_plt_p0_txlc_sr_mask                 (0x00180000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_6_plt_p0_txlc_term_mask               (0x00060000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_6_plt_p0_txlcp_mode(data)             (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_6_plt_p0_txlcn_mode(data)             (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_6_plt_p0_txlc_ckphs(data)             (0x03000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_6_plt_p0_txlc_sel_emp(data)           (0x00E00000&((data)<<21))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_6_plt_p0_txlc_sr(data)                (0x00180000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_6_plt_p0_txlc_term(data)              (0x00060000&((data)<<17))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_6_get_plt_p0_txlcp_mode(data)         ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_6_get_plt_p0_txlcn_mode(data)         ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_6_get_plt_p0_txlc_ckphs(data)         ((0x03000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_6_get_plt_p0_txlc_sel_emp(data)       ((0x00E00000&(data))>>21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_6_get_plt_p0_txlc_sr(data)            ((0x00180000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_6_get_plt_p0_txlc_term(data)          ((0x00060000&(data))>>17)

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_7                                     0x18000C1C
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_7_reg_addr                            "0xB8000C1C"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_7_reg                                 0xB8000C1C
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_7_inst_addr                           "0x0006"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_7_reg(data)                       (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_7_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_7_reg                             (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_7_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_7_plt_p0_txldp_mode_shift             (29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_7_plt_p0_txldn_mode_shift             (26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_7_plt_p0_txld_ckphs_shift             (24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_7_plt_p0_txld_sel_emp_shift           (21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_7_plt_p0_txld_sr_shift                (19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_7_plt_p0_txld_term_shift              (17)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_7_plt_p0_txldp_mode_mask              (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_7_plt_p0_txldn_mode_mask              (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_7_plt_p0_txld_ckphs_mask              (0x03000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_7_plt_p0_txld_sel_emp_mask            (0x00E00000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_7_plt_p0_txld_sr_mask                 (0x00180000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_7_plt_p0_txld_term_mask               (0x00060000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_7_plt_p0_txldp_mode(data)             (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_7_plt_p0_txldn_mode(data)             (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_7_plt_p0_txld_ckphs(data)             (0x03000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_7_plt_p0_txld_sel_emp(data)           (0x00E00000&((data)<<21))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_7_plt_p0_txld_sr(data)                (0x00180000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_7_plt_p0_txld_term(data)              (0x00060000&((data)<<17))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_7_get_plt_p0_txldp_mode(data)         ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_7_get_plt_p0_txldn_mode(data)         ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_7_get_plt_p0_txld_ckphs(data)         ((0x03000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_7_get_plt_p0_txld_sel_emp(data)       ((0x00E00000&(data))>>21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_7_get_plt_p0_txld_sr(data)            ((0x00180000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_7_get_plt_p0_txld_term(data)          ((0x00060000&(data))>>17)

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_8                                     0x18000C20
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_8_reg_addr                            "0xB8000C20"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_8_reg                                 0xB8000C20
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_8_inst_addr                           "0x0007"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_8_reg(data)                       (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_8_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_8_reg                             (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_8_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_8_plt_p0_txlep_mode_shift             (29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_8_plt_p0_txlen_mode_shift             (26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_8_plt_p0_txle_ckphs_shift             (24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_8_plt_p0_txle_sel_emp_shift           (21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_8_plt_p0_txle_sr_shift                (19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_8_plt_p0_txle_term_shift              (17)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_8_plt_p0_txlep_mode_mask              (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_8_plt_p0_txlen_mode_mask              (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_8_plt_p0_txle_ckphs_mask              (0x03000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_8_plt_p0_txle_sel_emp_mask            (0x00E00000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_8_plt_p0_txle_sr_mask                 (0x00180000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_8_plt_p0_txle_term_mask               (0x00060000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_8_plt_p0_txlep_mode(data)             (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_8_plt_p0_txlen_mode(data)             (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_8_plt_p0_txle_ckphs(data)             (0x03000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_8_plt_p0_txle_sel_emp(data)           (0x00E00000&((data)<<21))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_8_plt_p0_txle_sr(data)                (0x00180000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_8_plt_p0_txle_term(data)              (0x00060000&((data)<<17))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_8_get_plt_p0_txlep_mode(data)         ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_8_get_plt_p0_txlen_mode(data)         ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_8_get_plt_p0_txle_ckphs(data)         ((0x03000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_8_get_plt_p0_txle_sel_emp(data)       ((0x00E00000&(data))>>21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_8_get_plt_p0_txle_sr(data)            ((0x00180000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_8_get_plt_p0_txle_term(data)          ((0x00060000&(data))>>17)

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_9                                     0x18000C24
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_9_reg_addr                            "0xB8000C24"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_9_reg                                 0xB8000C24
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_9_inst_addr                           "0x0008"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_9_reg(data)                       (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_9_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_9_reg                             (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_9_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_9_plt_p0_txlfp_mode_shift             (29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_9_plt_p0_txlfn_mode_shift             (26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_9_plt_p0_txlf_ckphs_shift             (24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_9_plt_p0_txlf_sel_emp_shift           (21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_9_plt_p0_txlf_sr_shift                (19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_9_plt_p0_txlf_term_shift              (17)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_9_plt_p0_txlfp_mode_mask              (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_9_plt_p0_txlfn_mode_mask              (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_9_plt_p0_txlf_ckphs_mask              (0x03000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_9_plt_p0_txlf_sel_emp_mask            (0x00E00000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_9_plt_p0_txlf_sr_mask                 (0x00180000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_9_plt_p0_txlf_term_mask               (0x00060000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_9_plt_p0_txlfp_mode(data)             (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_9_plt_p0_txlfn_mode(data)             (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_9_plt_p0_txlf_ckphs(data)             (0x03000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_9_plt_p0_txlf_sel_emp(data)           (0x00E00000&((data)<<21))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_9_plt_p0_txlf_sr(data)                (0x00180000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_9_plt_p0_txlf_term(data)              (0x00060000&((data)<<17))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_9_get_plt_p0_txlfp_mode(data)         ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_9_get_plt_p0_txlfn_mode(data)         ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_9_get_plt_p0_txlf_ckphs(data)         ((0x03000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_9_get_plt_p0_txlf_sel_emp(data)       ((0x00E00000&(data))>>21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_9_get_plt_p0_txlf_sr(data)            ((0x00180000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_9_get_plt_p0_txlf_term(data)          ((0x00060000&(data))>>17)

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_19                                    0x18000C54
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_19_reg_addr                           "0xB8000C54"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_19_reg                                0xB8000C54
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_19_inst_addr                          "0x0009"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_19_reg(data)                      (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_19_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_19_reg                            (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_19_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_19_plt_p0_txl_ck1x_delay_shift        (29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_19_plt_p0_txl_cml_str_shift           (16)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_19_plt_p0_txl_en_emp_shift            (8)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_19_plt_p0_txl_en_term_shift           (0)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_19_plt_p0_txl_ck1x_delay_mask         (0x60000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_19_plt_p0_txl_cml_str_mask            (0x007F0000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_19_plt_p0_txl_en_emp_mask             (0x00007F00)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_19_plt_p0_txl_en_term_mask            (0x0000007F)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_19_plt_p0_txl_ck1x_delay(data)        (0x60000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_19_plt_p0_txl_cml_str(data)           (0x007F0000&((data)<<16))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_19_plt_p0_txl_en_emp(data)            (0x00007F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_19_plt_p0_txl_en_term(data)           (0x0000007F&(data))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_19_get_plt_p0_txl_ck1x_delay(data)    ((0x60000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_19_get_plt_p0_txl_cml_str(data)       ((0x007F0000&(data))>>16)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_19_get_plt_p0_txl_en_emp(data)        ((0x00007F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_19_get_plt_p0_txl_en_term(data)       (0x0000007F&(data))

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_10                                    0x18000C28
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_10_reg_addr                           "0xB8000C28"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_10_reg                                0xB8000C28
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_10_inst_addr                          "0x000A"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_10_reg(data)                      (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_10_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_10_reg                            (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_10_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_10_plt_p0_txl_ck7x_delay_shift        (30)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_10_plt_p0_txl_ck7x_inv_shift          (29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_10_plt_p0_txl_cm_mode_shift           (27)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_10_plt_p0_txl_ib2x_shift              (20)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_10_plt_p0_txl_ck7x_lag_shift          (12)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_10_plt_p0_txl_ck7x_delay_mask         (0xC0000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_10_plt_p0_txl_ck7x_inv_mask           (0x20000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_10_plt_p0_txl_cm_mode_mask            (0x08000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_10_plt_p0_txl_ib2x_mask               (0x07F00000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_10_plt_p0_txl_ck7x_lag_mask           (0x0007F000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_10_plt_p0_txl_ck7x_delay(data)        (0xC0000000&((data)<<30))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_10_plt_p0_txl_ck7x_inv(data)          (0x20000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_10_plt_p0_txl_cm_mode(data)           (0x08000000&((data)<<27))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_10_plt_p0_txl_ib2x(data)              (0x07F00000&((data)<<20))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_10_plt_p0_txl_ck7x_lag(data)          (0x0007F000&((data)<<12))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_10_get_plt_p0_txl_ck7x_delay(data)    ((0xC0000000&(data))>>30)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_10_get_plt_p0_txl_ck7x_inv(data)      ((0x20000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_10_get_plt_p0_txl_cm_mode(data)       ((0x08000000&(data))>>27)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_10_get_plt_p0_txl_ib2x(data)          ((0x07F00000&(data))>>20)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_10_get_plt_p0_txl_ck7x_lag(data)      ((0x0007F000&(data))>>12)

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_17                                    0x18000C48
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_17_reg_addr                           "0xB8000C48"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_17_reg                                0xB8000C48
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_17_inst_addr                          "0x000B"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_17_reg(data)                      (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_17_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_17_reg                            (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_17_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_17_plt_p1_txl_ck7x_delay_shift        (30)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_17_plt_p1_txl_ck7x_inv_shift          (29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_17_plt_p1_txl_cm_mode_shift           (27)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_17_plt_p1_txl_ib2x_shift              (20)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_17_plt_p1_txl_ck7x_lag_shift          (12)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_17_plt_p1_txl_ck7x_delay_mask         (0xC0000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_17_plt_p1_txl_ck7x_inv_mask           (0x20000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_17_plt_p1_txl_cm_mode_mask            (0x08000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_17_plt_p1_txl_ib2x_mask               (0x07F00000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_17_plt_p1_txl_ck7x_lag_mask           (0x0007F000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_17_plt_p1_txl_ck7x_delay(data)        (0xC0000000&((data)<<30))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_17_plt_p1_txl_ck7x_inv(data)          (0x20000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_17_plt_p1_txl_cm_mode(data)           (0x08000000&((data)<<27))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_17_plt_p1_txl_ib2x(data)              (0x07F00000&((data)<<20))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_17_plt_p1_txl_ck7x_lag(data)          (0x0007F000&((data)<<12))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_17_get_plt_p1_txl_ck7x_delay(data)    ((0xC0000000&(data))>>30)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_17_get_plt_p1_txl_ck7x_inv(data)      ((0x20000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_17_get_plt_p1_txl_cm_mode(data)       ((0x08000000&(data))>>27)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_17_get_plt_p1_txl_ib2x(data)          ((0x07F00000&(data))>>20)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_17_get_plt_p1_txl_ck7x_lag(data)      ((0x0007F000&(data))>>12)

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_11                                    0x18000C30
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_11_reg_addr                           "0xB8000C30"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_11_reg                                0xB8000C30
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_11_inst_addr                          "0x000C"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_11_reg(data)                      (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_11_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_11_reg                            (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_11_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_11_plt_p1_txlap_mode_shift            (29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_11_plt_p1_txlan_mode_shift            (26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_11_plt_p1_txla_ckphs_shift            (24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_11_plt_p1_txla_sel_emp_shift          (21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_11_plt_p1_txla_sr_shift               (19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_11_plt_p1_txla_term_shift             (17)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_11_plt_p1_txl_epicml_shift            (0)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_11_plt_p1_txlap_mode_mask             (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_11_plt_p1_txlan_mode_mask             (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_11_plt_p1_txla_ckphs_mask             (0x03000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_11_plt_p1_txla_sel_emp_mask           (0x00E00000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_11_plt_p1_txla_sr_mask                (0x00180000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_11_plt_p1_txla_term_mask              (0x00060000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_11_plt_p1_txl_epicml_mask             (0x0000007F)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_11_plt_p1_txlap_mode(data)            (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_11_plt_p1_txlan_mode(data)            (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_11_plt_p1_txla_ckphs(data)            (0x03000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_11_plt_p1_txla_sel_emp(data)          (0x00E00000&((data)<<21))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_11_plt_p1_txla_sr(data)               (0x00180000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_11_plt_p1_txla_term(data)             (0x00060000&((data)<<17))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_11_plt_p1_txl_epicml(data)            (0x0000007F&(data))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_11_get_plt_p1_txlap_mode(data)        ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_11_get_plt_p1_txlan_mode(data)        ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_11_get_plt_p1_txla_ckphs(data)        ((0x03000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_11_get_plt_p1_txla_sel_emp(data)      ((0x00E00000&(data))>>21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_11_get_plt_p1_txla_sr(data)           ((0x00180000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_11_get_plt_p1_txla_term(data)         ((0x00060000&(data))>>17)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_11_get_plt_p1_txl_epicml(data)        (0x0000007F&(data))

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_12                                    0x18000C34
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_12_reg_addr                           "0xB8000C34"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_12_reg                                0xB8000C34
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_12_inst_addr                          "0x000D"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_12_reg(data)                      (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_12_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_12_reg                            (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_12_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_12_plt_p1_txlbp_mode_shift            (29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_12_plt_p1_txlbn_mode_shift            (26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_12_plt_p1_txlb_ckphs_shift            (24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_12_plt_p1_txlb_sel_emp_shift          (21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_12_plt_p1_txlb_sr_shift               (19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_12_plt_p1_txlb_term_shift             (17)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_12_plt_p1_txlbp_mode_mask             (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_12_plt_p1_txlbn_mode_mask             (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_12_plt_p1_txlb_ckphs_mask             (0x03000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_12_plt_p1_txlb_sel_emp_mask           (0x00E00000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_12_plt_p1_txlb_sr_mask                (0x00180000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_12_plt_p1_txlb_term_mask              (0x00060000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_12_plt_p1_txlbp_mode(data)            (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_12_plt_p1_txlbn_mode(data)            (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_12_plt_p1_txlb_ckphs(data)            (0x03000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_12_plt_p1_txlb_sel_emp(data)          (0x00E00000&((data)<<21))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_12_plt_p1_txlb_sr(data)               (0x00180000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_12_plt_p1_txlb_term(data)             (0x00060000&((data)<<17))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_12_get_plt_p1_txlbp_mode(data)        ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_12_get_plt_p1_txlbn_mode(data)        ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_12_get_plt_p1_txlb_ckphs(data)        ((0x03000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_12_get_plt_p1_txlb_sel_emp(data)      ((0x00E00000&(data))>>21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_12_get_plt_p1_txlb_sr(data)           ((0x00180000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_12_get_plt_p1_txlb_term(data)         ((0x00060000&(data))>>17)

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_13                                    0x18000C38
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_13_reg_addr                           "0xB8000C38"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_13_reg                                0xB8000C38
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_13_inst_addr                          "0x000E"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_13_reg(data)                      (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_13_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_13_reg                            (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_13_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_13_plt_p1_txlcp_mode_shift            (29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_13_plt_p1_txlcn_mode_shift            (26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_13_plt_p1_txlc_ckphs_shift            (24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_13_plt_p1_txlc_sel_emp_shift          (21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_13_plt_p1_txlc_sr_shift               (19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_13_plt_p1_txlc_term_shift             (17)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_13_plt_p1_txlcp_mode_mask             (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_13_plt_p1_txlcn_mode_mask             (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_13_plt_p1_txlc_ckphs_mask             (0x03000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_13_plt_p1_txlc_sel_emp_mask           (0x00E00000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_13_plt_p1_txlc_sr_mask                (0x00180000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_13_plt_p1_txlc_term_mask              (0x00060000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_13_plt_p1_txlcp_mode(data)            (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_13_plt_p1_txlcn_mode(data)            (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_13_plt_p1_txlc_ckphs(data)            (0x03000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_13_plt_p1_txlc_sel_emp(data)          (0x00E00000&((data)<<21))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_13_plt_p1_txlc_sr(data)               (0x00180000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_13_plt_p1_txlc_term(data)             (0x00060000&((data)<<17))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_13_get_plt_p1_txlcp_mode(data)        ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_13_get_plt_p1_txlcn_mode(data)        ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_13_get_plt_p1_txlc_ckphs(data)        ((0x03000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_13_get_plt_p1_txlc_sel_emp(data)      ((0x00E00000&(data))>>21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_13_get_plt_p1_txlc_sr(data)           ((0x00180000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_13_get_plt_p1_txlc_term(data)         ((0x00060000&(data))>>17)

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_14                                    0x18000C3C
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_14_reg_addr                           "0xB8000C3C"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_14_reg                                0xB8000C3C
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_14_inst_addr                          "0x000F"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_14_reg(data)                      (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_14_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_14_reg                            (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_14_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_14_plt_p1_txldp_mode_shift            (29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_14_plt_p1_txldn_mode_shift            (26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_14_plt_p1_txld_ckphs_shift            (24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_14_plt_p1_txld_sel_emp_shift          (21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_14_plt_p1_txld_sr_shift               (19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_14_plt_p1_txld_term_shift             (17)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_14_plt_p1_txldp_mode_mask             (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_14_plt_p1_txldn_mode_mask             (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_14_plt_p1_txld_ckphs_mask             (0x03000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_14_plt_p1_txld_sel_emp_mask           (0x00E00000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_14_plt_p1_txld_sr_mask                (0x00180000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_14_plt_p1_txld_term_mask              (0x00060000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_14_plt_p1_txldp_mode(data)            (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_14_plt_p1_txldn_mode(data)            (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_14_plt_p1_txld_ckphs(data)            (0x03000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_14_plt_p1_txld_sel_emp(data)          (0x00E00000&((data)<<21))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_14_plt_p1_txld_sr(data)               (0x00180000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_14_plt_p1_txld_term(data)             (0x00060000&((data)<<17))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_14_get_plt_p1_txldp_mode(data)        ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_14_get_plt_p1_txldn_mode(data)        ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_14_get_plt_p1_txld_ckphs(data)        ((0x03000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_14_get_plt_p1_txld_sel_emp(data)      ((0x00E00000&(data))>>21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_14_get_plt_p1_txld_sr(data)           ((0x00180000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_14_get_plt_p1_txld_term(data)         ((0x00060000&(data))>>17)

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_15                                    0x18000C40
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_15_reg_addr                           "0xB8000C40"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_15_reg                                0xB8000C40
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_15_inst_addr                          "0x0010"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_15_reg(data)                      (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_15_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_15_reg                            (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_15_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_15_plt_p1_txlep_mode_shift            (29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_15_plt_p1_txlen_mode_shift            (26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_15_plt_p1_txle_ckphs_shift            (24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_15_plt_p1_txle_sel_emp_shift          (21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_15_plt_p1_txle_sr_shift               (19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_15_plt_p1_txle_term_shift             (17)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_15_plt_p1_txlep_mode_mask             (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_15_plt_p1_txlen_mode_mask             (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_15_plt_p1_txle_ckphs_mask             (0x03000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_15_plt_p1_txle_sel_emp_mask           (0x00E00000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_15_plt_p1_txle_sr_mask                (0x00180000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_15_plt_p1_txle_term_mask              (0x00060000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_15_plt_p1_txlep_mode(data)            (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_15_plt_p1_txlen_mode(data)            (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_15_plt_p1_txle_ckphs(data)            (0x03000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_15_plt_p1_txle_sel_emp(data)          (0x00E00000&((data)<<21))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_15_plt_p1_txle_sr(data)               (0x00180000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_15_plt_p1_txle_term(data)             (0x00060000&((data)<<17))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_15_get_plt_p1_txlep_mode(data)        ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_15_get_plt_p1_txlen_mode(data)        ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_15_get_plt_p1_txle_ckphs(data)        ((0x03000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_15_get_plt_p1_txle_sel_emp(data)      ((0x00E00000&(data))>>21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_15_get_plt_p1_txle_sr(data)           ((0x00180000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_15_get_plt_p1_txle_term(data)         ((0x00060000&(data))>>17)

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_16                                    0x18000C44
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_16_reg_addr                           "0xB8000C44"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_16_reg                                0xB8000C44
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_16_inst_addr                          "0x0011"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_16_reg(data)                      (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_16_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_16_reg                            (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_16_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_16_plt_p1_txlfp_mode_shift            (29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_16_plt_p1_txlfn_mode_shift            (26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_16_plt_p1_txlf_ckphs_shift            (24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_16_plt_p1_txlf_sel_emp_shift          (21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_16_plt_p1_txlf_sr_shift               (19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_16_plt_p1_txlf_term_shift             (17)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_16_plt_p1_txlfp_mode_mask             (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_16_plt_p1_txlfn_mode_mask             (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_16_plt_p1_txlf_ckphs_mask             (0x03000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_16_plt_p1_txlf_sel_emp_mask           (0x00E00000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_16_plt_p1_txlf_sr_mask                (0x00180000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_16_plt_p1_txlf_term_mask              (0x00060000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_16_plt_p1_txlfp_mode(data)            (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_16_plt_p1_txlfn_mode(data)            (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_16_plt_p1_txlf_ckphs(data)            (0x03000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_16_plt_p1_txlf_sel_emp(data)          (0x00E00000&((data)<<21))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_16_plt_p1_txlf_sr(data)               (0x00180000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_16_plt_p1_txlf_term(data)             (0x00060000&((data)<<17))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_16_get_plt_p1_txlfp_mode(data)        ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_16_get_plt_p1_txlfn_mode(data)        ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_16_get_plt_p1_txlf_ckphs(data)        ((0x03000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_16_get_plt_p1_txlf_sel_emp(data)      ((0x00E00000&(data))>>21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_16_get_plt_p1_txlf_sr(data)           ((0x00180000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_16_get_plt_p1_txlf_term(data)         ((0x00060000&(data))>>17)

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_4                                     0x18000D10
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_4_reg_addr                            "0xB8000D10"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_4_reg                                 0xB8000D10
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_4_inst_addr                           "0x0012"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_4_reg(data)                       (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_4_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_4_reg                             (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_4_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_4_plt_p2_txlap_mode_shift             (29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_4_plt_p2_txlan_mode_shift             (26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_4_plt_p2_txla_ckphs_shift             (24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_4_plt_p2_txla_sel_emp_shift           (21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_4_plt_p2_txla_sr_shift                (19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_4_plt_p2_txla_term_shift              (17)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_4_plt_p2_txl_epicml_shift             (0)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_4_plt_p2_txlap_mode_mask              (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_4_plt_p2_txlan_mode_mask              (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_4_plt_p2_txla_ckphs_mask              (0x03000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_4_plt_p2_txla_sel_emp_mask            (0x00E00000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_4_plt_p2_txla_sr_mask                 (0x00180000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_4_plt_p2_txla_term_mask               (0x00060000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_4_plt_p2_txl_epicml_mask              (0x0000007F)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_4_plt_p2_txlap_mode(data)             (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_4_plt_p2_txlan_mode(data)             (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_4_plt_p2_txla_ckphs(data)             (0x03000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_4_plt_p2_txla_sel_emp(data)           (0x00E00000&((data)<<21))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_4_plt_p2_txla_sr(data)                (0x00180000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_4_plt_p2_txla_term(data)              (0x00060000&((data)<<17))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_4_plt_p2_txl_epicml(data)             (0x0000007F&(data))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_4_get_plt_p2_txlap_mode(data)         ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_4_get_plt_p2_txlan_mode(data)         ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_4_get_plt_p2_txla_ckphs(data)         ((0x03000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_4_get_plt_p2_txla_sel_emp(data)       ((0x00E00000&(data))>>21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_4_get_plt_p2_txla_sr(data)            ((0x00180000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_4_get_plt_p2_txla_term(data)          ((0x00060000&(data))>>17)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_4_get_plt_p2_txl_epicml(data)         (0x0000007F&(data))

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_5                                     0x18000D14
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_5_reg_addr                            "0xB8000D14"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_5_reg                                 0xB8000D14
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_5_inst_addr                           "0x0013"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_5_reg(data)                       (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_5_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_5_reg                             (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_5_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_5_plt_p2_txlbp_mode_shift             (29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_5_plt_p2_txlbn_mode_shift             (26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_5_plt_p2_txlb_ckphs_shift             (24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_5_plt_p2_txlb_sel_emp_shift           (21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_5_plt_p2_txlb_sr_shift                (19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_5_plt_p2_txlb_term_shift              (17)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_5_plt_p2_txlbp_mode_mask              (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_5_plt_p2_txlbn_mode_mask              (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_5_plt_p2_txlb_ckphs_mask              (0x03000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_5_plt_p2_txlb_sel_emp_mask            (0x00E00000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_5_plt_p2_txlb_sr_mask                 (0x00180000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_5_plt_p2_txlb_term_mask               (0x00060000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_5_plt_p2_txlbp_mode(data)             (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_5_plt_p2_txlbn_mode(data)             (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_5_plt_p2_txlb_ckphs(data)             (0x03000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_5_plt_p2_txlb_sel_emp(data)           (0x00E00000&((data)<<21))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_5_plt_p2_txlb_sr(data)                (0x00180000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_5_plt_p2_txlb_term(data)              (0x00060000&((data)<<17))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_5_get_plt_p2_txlbp_mode(data)         ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_5_get_plt_p2_txlbn_mode(data)         ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_5_get_plt_p2_txlb_ckphs(data)         ((0x03000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_5_get_plt_p2_txlb_sel_emp(data)       ((0x00E00000&(data))>>21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_5_get_plt_p2_txlb_sr(data)            ((0x00180000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_5_get_plt_p2_txlb_term(data)          ((0x00060000&(data))>>17)

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_6                                     0x18000D18
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_6_reg_addr                            "0xB8000D18"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_6_reg                                 0xB8000D18
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_6_inst_addr                           "0x0014"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_6_reg(data)                       (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_6_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_6_reg                             (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_6_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_6_plt_p2_txlcp_mode_shift             (29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_6_plt_p2_txlcn_mode_shift             (26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_6_plt_p2_txlc_ckphs_shift             (24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_6_plt_p2_txlc_sel_emp_shift           (21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_6_plt_p2_txlc_sr_shift                (19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_6_plt_p2_txlc_term_shift              (17)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_6_plt_p2_txlcp_mode_mask              (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_6_plt_p2_txlcn_mode_mask              (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_6_plt_p2_txlc_ckphs_mask              (0x03000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_6_plt_p2_txlc_sel_emp_mask            (0x00E00000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_6_plt_p2_txlc_sr_mask                 (0x00180000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_6_plt_p2_txlc_term_mask               (0x00060000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_6_plt_p2_txlcp_mode(data)             (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_6_plt_p2_txlcn_mode(data)             (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_6_plt_p2_txlc_ckphs(data)             (0x03000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_6_plt_p2_txlc_sel_emp(data)           (0x00E00000&((data)<<21))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_6_plt_p2_txlc_sr(data)                (0x00180000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_6_plt_p2_txlc_term(data)              (0x00060000&((data)<<17))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_6_get_plt_p2_txlcp_mode(data)         ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_6_get_plt_p2_txlcn_mode(data)         ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_6_get_plt_p2_txlc_ckphs(data)         ((0x03000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_6_get_plt_p2_txlc_sel_emp(data)       ((0x00E00000&(data))>>21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_6_get_plt_p2_txlc_sr(data)            ((0x00180000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_6_get_plt_p2_txlc_term(data)          ((0x00060000&(data))>>17)

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_7                                     0x18000D1C
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_7_reg_addr                            "0xB8000D1C"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_7_reg                                 0xB8000D1C
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_7_inst_addr                           "0x0015"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_7_reg(data)                       (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_7_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_7_reg                             (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_7_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_7_plt_p2_txldp_mode_shift             (29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_7_plt_p2_txldn_mode_shift             (26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_7_plt_p2_txld_ckphs_shift             (24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_7_plt_p2_txld_sel_emp_shift           (21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_7_plt_p2_txld_sr_shift                (19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_7_plt_p2_txld_term_shift              (17)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_7_plt_p2_txldp_mode_mask              (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_7_plt_p2_txldn_mode_mask              (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_7_plt_p2_txld_ckphs_mask              (0x03000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_7_plt_p2_txld_sel_emp_mask            (0x00E00000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_7_plt_p2_txld_sr_mask                 (0x00180000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_7_plt_p2_txld_term_mask               (0x00060000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_7_plt_p2_txldp_mode(data)             (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_7_plt_p2_txldn_mode(data)             (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_7_plt_p2_txld_ckphs(data)             (0x03000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_7_plt_p2_txld_sel_emp(data)           (0x00E00000&((data)<<21))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_7_plt_p2_txld_sr(data)                (0x00180000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_7_plt_p2_txld_term(data)              (0x00060000&((data)<<17))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_7_get_plt_p2_txldp_mode(data)         ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_7_get_plt_p2_txldn_mode(data)         ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_7_get_plt_p2_txld_ckphs(data)         ((0x03000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_7_get_plt_p2_txld_sel_emp(data)       ((0x00E00000&(data))>>21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_7_get_plt_p2_txld_sr(data)            ((0x00180000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_7_get_plt_p2_txld_term(data)          ((0x00060000&(data))>>17)

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_8                                     0x18000D20
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_8_reg_addr                            "0xB8000D20"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_8_reg                                 0xB8000D20
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_8_inst_addr                           "0x0016"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_8_reg(data)                       (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_8_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_8_reg                             (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_8_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_8_plt_p2_txlep_mode_shift             (29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_8_plt_p2_txlen_mode_shift             (26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_8_plt_p2_txle_ckphs_shift             (24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_8_plt_p2_txle_sel_emp_shift           (21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_8_plt_p2_txle_sr_shift                (19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_8_plt_p2_txle_term_shift              (17)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_8_plt_p2_txlep_mode_mask              (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_8_plt_p2_txlen_mode_mask              (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_8_plt_p2_txle_ckphs_mask              (0x03000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_8_plt_p2_txle_sel_emp_mask            (0x00E00000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_8_plt_p2_txle_sr_mask                 (0x00180000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_8_plt_p2_txle_term_mask               (0x00060000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_8_plt_p2_txlep_mode(data)             (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_8_plt_p2_txlen_mode(data)             (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_8_plt_p2_txle_ckphs(data)             (0x03000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_8_plt_p2_txle_sel_emp(data)           (0x00E00000&((data)<<21))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_8_plt_p2_txle_sr(data)                (0x00180000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_8_plt_p2_txle_term(data)              (0x00060000&((data)<<17))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_8_get_plt_p2_txlep_mode(data)         ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_8_get_plt_p2_txlen_mode(data)         ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_8_get_plt_p2_txle_ckphs(data)         ((0x03000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_8_get_plt_p2_txle_sel_emp(data)       ((0x00E00000&(data))>>21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_8_get_plt_p2_txle_sr(data)            ((0x00180000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_8_get_plt_p2_txle_term(data)          ((0x00060000&(data))>>17)

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_9                                     0x18000D24
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_9_reg_addr                            "0xB8000D24"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_9_reg                                 0xB8000D24
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_9_inst_addr                           "0x0017"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_9_reg(data)                       (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_9_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_9_reg                             (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_9_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_9_plt_p2_txlfp_mode_shift             (29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_9_plt_p2_txlfn_mode_shift             (26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_9_plt_p2_txlf_ckphs_shift             (24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_9_plt_p2_txlf_sel_emp_shift           (21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_9_plt_p2_txlf_sr_shift                (19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_9_plt_p2_txlf_term_shift              (17)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_9_plt_p2_txlfp_mode_mask              (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_9_plt_p2_txlfn_mode_mask              (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_9_plt_p2_txlf_ckphs_mask              (0x03000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_9_plt_p2_txlf_sel_emp_mask            (0x00E00000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_9_plt_p2_txlf_sr_mask                 (0x00180000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_9_plt_p2_txlf_term_mask               (0x00060000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_9_plt_p2_txlfp_mode(data)             (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_9_plt_p2_txlfn_mode(data)             (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_9_plt_p2_txlf_ckphs(data)             (0x03000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_9_plt_p2_txlf_sel_emp(data)           (0x00E00000&((data)<<21))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_9_plt_p2_txlf_sr(data)                (0x00180000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_9_plt_p2_txlf_term(data)              (0x00060000&((data)<<17))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_9_get_plt_p2_txlfp_mode(data)         ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_9_get_plt_p2_txlfn_mode(data)         ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_9_get_plt_p2_txlf_ckphs(data)         ((0x03000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_9_get_plt_p2_txlf_sel_emp(data)       ((0x00E00000&(data))>>21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_9_get_plt_p2_txlf_sr(data)            ((0x00180000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_9_get_plt_p2_txlf_term(data)          ((0x00060000&(data))>>17)

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_11                                    0x18000D30
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_11_reg_addr                           "0xB8000D30"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_11_reg                                0xB8000D30
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_11_inst_addr                          "0x0018"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_11_reg(data)                      (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_11_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_11_reg                            (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_11_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_11_plt_p3_txlap_mode_shift            (29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_11_plt_p3_txlan_mode_shift            (26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_11_plt_p3_txla_ckphs_shift            (24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_11_plt_p3_txla_sel_emp_shift          (21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_11_plt_p3_txla_sr_shift               (19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_11_plt_p3_txla_term_shift             (17)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_11_plt_p3_txl_epicml_shift            (0)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_11_plt_p3_txlap_mode_mask             (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_11_plt_p3_txlan_mode_mask             (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_11_plt_p3_txla_ckphs_mask             (0x03000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_11_plt_p3_txla_sel_emp_mask           (0x00E00000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_11_plt_p3_txla_sr_mask                (0x00180000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_11_plt_p3_txla_term_mask              (0x00060000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_11_plt_p3_txl_epicml_mask             (0x0000007F)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_11_plt_p3_txlap_mode(data)            (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_11_plt_p3_txlan_mode(data)            (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_11_plt_p3_txla_ckphs(data)            (0x03000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_11_plt_p3_txla_sel_emp(data)          (0x00E00000&((data)<<21))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_11_plt_p3_txla_sr(data)               (0x00180000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_11_plt_p3_txla_term(data)             (0x00060000&((data)<<17))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_11_plt_p3_txl_epicml(data)            (0x0000007F&(data))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_11_get_plt_p3_txlap_mode(data)        ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_11_get_plt_p3_txlan_mode(data)        ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_11_get_plt_p3_txla_ckphs(data)        ((0x03000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_11_get_plt_p3_txla_sel_emp(data)      ((0x00E00000&(data))>>21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_11_get_plt_p3_txla_sr(data)           ((0x00180000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_11_get_plt_p3_txla_term(data)         ((0x00060000&(data))>>17)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_11_get_plt_p3_txl_epicml(data)        (0x0000007F&(data))

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_12                                    0x18000D34
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_12_reg_addr                           "0xB8000D34"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_12_reg                                0xB8000D34
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_12_inst_addr                          "0x0019"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_12_reg(data)                      (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_12_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_12_reg                            (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_12_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_12_plt_p3_txlbp_mode_shift            (29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_12_plt_p3_txlbn_mode_shift            (26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_12_plt_p3_txlb_ckphs_shift            (24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_12_plt_p3_txlb_sel_emp_shift          (21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_12_plt_p3_txlb_sr_shift               (19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_12_plt_p3_txlb_term_shift             (17)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_12_plt_p3_txlbp_mode_mask             (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_12_plt_p3_txlbn_mode_mask             (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_12_plt_p3_txlb_ckphs_mask             (0x03000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_12_plt_p3_txlb_sel_emp_mask           (0x00E00000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_12_plt_p3_txlb_sr_mask                (0x00180000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_12_plt_p3_txlb_term_mask              (0x00060000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_12_plt_p3_txlbp_mode(data)            (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_12_plt_p3_txlbn_mode(data)            (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_12_plt_p3_txlb_ckphs(data)            (0x03000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_12_plt_p3_txlb_sel_emp(data)          (0x00E00000&((data)<<21))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_12_plt_p3_txlb_sr(data)               (0x00180000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_12_plt_p3_txlb_term(data)             (0x00060000&((data)<<17))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_12_get_plt_p3_txlbp_mode(data)        ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_12_get_plt_p3_txlbn_mode(data)        ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_12_get_plt_p3_txlb_ckphs(data)        ((0x03000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_12_get_plt_p3_txlb_sel_emp(data)      ((0x00E00000&(data))>>21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_12_get_plt_p3_txlb_sr(data)           ((0x00180000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_12_get_plt_p3_txlb_term(data)         ((0x00060000&(data))>>17)

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_13                                    0x18000D38
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_13_reg_addr                           "0xB8000D38"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_13_reg                                0xB8000D38
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_13_inst_addr                          "0x001A"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_13_reg(data)                      (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_13_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_13_reg                            (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_13_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_13_plt_p3_txlcp_mode_shift            (29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_13_plt_p3_txlcn_mode_shift            (26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_13_plt_p3_txlc_ckphs_shift            (24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_13_plt_p3_txlc_sel_emp_shift          (21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_13_plt_p3_txlc_sr_shift               (19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_13_plt_p3_txlc_term_shift             (17)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_13_plt_p3_txlcp_mode_mask             (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_13_plt_p3_txlcn_mode_mask             (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_13_plt_p3_txlc_ckphs_mask             (0x03000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_13_plt_p3_txlc_sel_emp_mask           (0x00E00000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_13_plt_p3_txlc_sr_mask                (0x00180000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_13_plt_p3_txlc_term_mask              (0x00060000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_13_plt_p3_txlcp_mode(data)            (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_13_plt_p3_txlcn_mode(data)            (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_13_plt_p3_txlc_ckphs(data)            (0x03000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_13_plt_p3_txlc_sel_emp(data)          (0x00E00000&((data)<<21))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_13_plt_p3_txlc_sr(data)               (0x00180000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_13_plt_p3_txlc_term(data)             (0x00060000&((data)<<17))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_13_get_plt_p3_txlcp_mode(data)        ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_13_get_plt_p3_txlcn_mode(data)        ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_13_get_plt_p3_txlc_ckphs(data)        ((0x03000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_13_get_plt_p3_txlc_sel_emp(data)      ((0x00E00000&(data))>>21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_13_get_plt_p3_txlc_sr(data)           ((0x00180000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_13_get_plt_p3_txlc_term(data)         ((0x00060000&(data))>>17)

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_14                                    0x18000D3C
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_14_reg_addr                           "0xB8000D3C"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_14_reg                                0xB8000D3C
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_14_inst_addr                          "0x001B"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_14_reg(data)                      (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_14_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_14_reg                            (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_14_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_14_plt_p3_txldp_mode_shift            (29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_14_plt_p3_txldn_mode_shift            (26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_14_plt_p3_txld_ckphs_shift            (24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_14_plt_p3_txld_sel_emp_shift          (21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_14_plt_p3_txld_sr_shift               (19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_14_plt_p3_txld_term_shift             (17)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_14_plt_p3_txldp_mode_mask             (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_14_plt_p3_txldn_mode_mask             (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_14_plt_p3_txld_ckphs_mask             (0x03000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_14_plt_p3_txld_sel_emp_mask           (0x00E00000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_14_plt_p3_txld_sr_mask                (0x00180000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_14_plt_p3_txld_term_mask              (0x00060000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_14_plt_p3_txldp_mode(data)            (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_14_plt_p3_txldn_mode(data)            (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_14_plt_p3_txld_ckphs(data)            (0x03000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_14_plt_p3_txld_sel_emp(data)          (0x00E00000&((data)<<21))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_14_plt_p3_txld_sr(data)               (0x00180000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_14_plt_p3_txld_term(data)             (0x00060000&((data)<<17))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_14_get_plt_p3_txldp_mode(data)        ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_14_get_plt_p3_txldn_mode(data)        ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_14_get_plt_p3_txld_ckphs(data)        ((0x03000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_14_get_plt_p3_txld_sel_emp(data)      ((0x00E00000&(data))>>21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_14_get_plt_p3_txld_sr(data)           ((0x00180000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_14_get_plt_p3_txld_term(data)         ((0x00060000&(data))>>17)

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_15                                    0x18000D40
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_15_reg_addr                           "0xB8000D40"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_15_reg                                0xB8000D40
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_15_inst_addr                          "0x001C"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_15_reg(data)                      (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_15_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_15_reg                            (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_15_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_15_plt_p3_txlep_mode_shift            (29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_15_plt_p3_txlen_mode_shift            (26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_15_plt_p3_txle_ckphs_shift            (24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_15_plt_p3_txle_sel_emp_shift          (21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_15_plt_p3_txle_sr_shift               (19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_15_plt_p3_txle_term_shift             (17)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_15_plt_p3_txlep_mode_mask             (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_15_plt_p3_txlen_mode_mask             (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_15_plt_p3_txle_ckphs_mask             (0x03000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_15_plt_p3_txle_sel_emp_mask           (0x00E00000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_15_plt_p3_txle_sr_mask                (0x00180000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_15_plt_p3_txle_term_mask              (0x00060000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_15_plt_p3_txlep_mode(data)            (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_15_plt_p3_txlen_mode(data)            (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_15_plt_p3_txle_ckphs(data)            (0x03000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_15_plt_p3_txle_sel_emp(data)          (0x00E00000&((data)<<21))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_15_plt_p3_txle_sr(data)               (0x00180000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_15_plt_p3_txle_term(data)             (0x00060000&((data)<<17))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_15_get_plt_p3_txlep_mode(data)        ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_15_get_plt_p3_txlen_mode(data)        ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_15_get_plt_p3_txle_ckphs(data)        ((0x03000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_15_get_plt_p3_txle_sel_emp(data)      ((0x00E00000&(data))>>21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_15_get_plt_p3_txle_sr(data)           ((0x00180000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_15_get_plt_p3_txle_term(data)         ((0x00060000&(data))>>17)

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_16                                    0x18000D44
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_16_reg_addr                           "0xB8000D44"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_16_reg                                0xB8000D44
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_16_inst_addr                          "0x001D"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_16_reg(data)                      (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_16_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_16_reg                            (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_16_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_16_plt_p3_txlfp_mode_shift            (29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_16_plt_p3_txlfn_mode_shift            (26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_16_plt_p3_txlf_ckphs_shift            (24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_16_plt_p3_txlf_sel_emp_shift          (21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_16_plt_p3_txlf_sr_shift               (19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_16_plt_p3_txlf_term_shift             (17)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_16_plt_p3_txlfp_mode_mask             (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_16_plt_p3_txlfn_mode_mask             (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_16_plt_p3_txlf_ckphs_mask             (0x03000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_16_plt_p3_txlf_sel_emp_mask           (0x00E00000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_16_plt_p3_txlf_sr_mask                (0x00180000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_16_plt_p3_txlf_term_mask              (0x00060000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_16_plt_p3_txlfp_mode(data)            (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_16_plt_p3_txlfn_mode(data)            (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_16_plt_p3_txlf_ckphs(data)            (0x03000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_16_plt_p3_txlf_sel_emp(data)          (0x00E00000&((data)<<21))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_16_plt_p3_txlf_sr(data)               (0x00180000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_16_plt_p3_txlf_term(data)             (0x00060000&((data)<<17))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_16_get_plt_p3_txlfp_mode(data)        ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_16_get_plt_p3_txlfn_mode(data)        ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_16_get_plt_p3_txlf_ckphs(data)        ((0x03000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_16_get_plt_p3_txlf_sel_emp(data)      ((0x00E00000&(data))>>21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_16_get_plt_p3_txlf_sr(data)           ((0x00180000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_16_get_plt_p3_txlf_term(data)         ((0x00060000&(data))>>17)

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_21                                    0x18000C5C
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_21_reg_addr                           "0xB8000C5C"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_21_reg                                0xB8000C5C
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_21_inst_addr                          "0x001E"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_21_reg(data)                      (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_21_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_21_reg                            (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_21_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_21_plt_p1_txl_ck1x_delay_shift        (29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_21_plt_p1_txl_cml_str_shift           (16)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_21_plt_p1_txl_en_emp_shift            (8)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_21_plt_p1_txl_en_term_shift           (0)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_21_plt_p1_txl_ck1x_delay_mask         (0x60000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_21_plt_p1_txl_cml_str_mask            (0x007F0000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_21_plt_p1_txl_en_emp_mask             (0x00007F00)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_21_plt_p1_txl_en_term_mask            (0x0000007F)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_21_plt_p1_txl_ck1x_delay(data)        (0x60000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_21_plt_p1_txl_cml_str(data)           (0x007F0000&((data)<<16))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_21_plt_p1_txl_en_emp(data)            (0x00007F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_21_plt_p1_txl_en_term(data)           (0x0000007F&(data))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_21_get_plt_p1_txl_ck1x_delay(data)    ((0x60000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_21_get_plt_p1_txl_cml_str(data)       ((0x007F0000&(data))>>16)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_21_get_plt_p1_txl_en_emp(data)        ((0x00007F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_21_get_plt_p1_txl_en_term(data)       (0x0000007F&(data))

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_19                                    0x18000D54
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_19_reg_addr                           "0xB8000D54"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_19_reg                                0xB8000D54
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_19_inst_addr                          "0x001F"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_19_reg(data)                      (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_19_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_19_reg                            (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_19_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_19_plt_p2_txl_ck1x_delay_shift        (29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_19_plt_p2_txl_cml_str_shift           (16)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_19_plt_p2_txl_en_emp_shift            (8)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_19_plt_p2_txl_en_term_shift           (0)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_19_plt_p2_txl_ck1x_delay_mask         (0x60000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_19_plt_p2_txl_cml_str_mask            (0x007F0000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_19_plt_p2_txl_en_emp_mask             (0x00007F00)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_19_plt_p2_txl_en_term_mask            (0x0000007F)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_19_plt_p2_txl_ck1x_delay(data)        (0x60000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_19_plt_p2_txl_cml_str(data)           (0x007F0000&((data)<<16))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_19_plt_p2_txl_en_emp(data)            (0x00007F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_19_plt_p2_txl_en_term(data)           (0x0000007F&(data))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_19_get_plt_p2_txl_ck1x_delay(data)    ((0x60000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_19_get_plt_p2_txl_cml_str(data)       ((0x007F0000&(data))>>16)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_19_get_plt_p2_txl_en_emp(data)        ((0x00007F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_19_get_plt_p2_txl_en_term(data)       (0x0000007F&(data))

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_21                                    0x18000D5C
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_21_reg_addr                           "0xB8000D5C"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_21_reg                                0xB8000D5C
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_21_inst_addr                          "0x0020"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_21_reg(data)                      (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_21_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_21_reg                            (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_21_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_21_plt_p3_txl_ck1x_delay_shift        (29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_21_plt_p3_txl_cml_str_shift           (16)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_21_plt_p3_txl_en_emp_shift            (8)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_21_plt_p3_txl_en_term_shift           (0)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_21_plt_p3_txl_ck1x_delay_mask         (0x60000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_21_plt_p3_txl_cml_str_mask            (0x007F0000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_21_plt_p3_txl_en_emp_mask             (0x00007F00)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_21_plt_p3_txl_en_term_mask            (0x0000007F)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_21_plt_p3_txl_ck1x_delay(data)        (0x60000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_21_plt_p3_txl_cml_str(data)           (0x007F0000&((data)<<16))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_21_plt_p3_txl_en_emp(data)            (0x00007F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_21_plt_p3_txl_en_term(data)           (0x0000007F&(data))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_21_get_plt_p3_txl_ck1x_delay(data)    ((0x60000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_21_get_plt_p3_txl_cml_str(data)       ((0x007F0000&(data))>>16)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_21_get_plt_p3_txl_en_emp(data)        ((0x00007F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_21_get_plt_p3_txl_en_term(data)       (0x0000007F&(data))

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_10                                    0x18000D28
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_10_reg_addr                           "0xB8000D28"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_10_reg                                0xB8000D28
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_10_inst_addr                          "0x0021"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_10_reg(data)                      (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_10_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_10_reg                            (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_10_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_10_plt_p2_txl_ck7x_delay_shift        (30)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_10_plt_p2_txl_ck7x_inv_shift          (29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_10_plt_p2_txl_cm_mode_shift           (27)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_10_plt_p2_txl_ib2x_shift              (20)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_10_plt_p2_txl_ck7x_lag_shift          (12)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_10_plt_p2_txl_ck7x_delay_mask         (0xC0000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_10_plt_p2_txl_ck7x_inv_mask           (0x20000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_10_plt_p2_txl_cm_mode_mask            (0x08000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_10_plt_p2_txl_ib2x_mask               (0x07F00000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_10_plt_p2_txl_ck7x_lag_mask           (0x0007F000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_10_plt_p2_txl_ck7x_delay(data)        (0xC0000000&((data)<<30))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_10_plt_p2_txl_ck7x_inv(data)          (0x20000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_10_plt_p2_txl_cm_mode(data)           (0x08000000&((data)<<27))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_10_plt_p2_txl_ib2x(data)              (0x07F00000&((data)<<20))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_10_plt_p2_txl_ck7x_lag(data)          (0x0007F000&((data)<<12))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_10_get_plt_p2_txl_ck7x_delay(data)    ((0xC0000000&(data))>>30)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_10_get_plt_p2_txl_ck7x_inv(data)      ((0x20000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_10_get_plt_p2_txl_cm_mode(data)       ((0x08000000&(data))>>27)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_10_get_plt_p2_txl_ib2x(data)          ((0x07F00000&(data))>>20)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_10_get_plt_p2_txl_ck7x_lag(data)      ((0x0007F000&(data))>>12)

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_17                                    0x18000D48
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_17_reg_addr                           "0xB8000D48"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_17_reg                                0xB8000D48
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_17_inst_addr                          "0x0022"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_17_reg(data)                      (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_17_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_17_reg                            (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_17_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_17_plt_p3_txl_ck7x_delay_shift        (30)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_17_plt_p3_txl_ck7x_inv_shift          (29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_17_plt_p3_txl_cm_mode_shift           (27)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_17_plt_p3_txl_ib2x_shift              (20)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_17_plt_p3_txl_ck7x_lag_shift          (12)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_17_plt_p3_txl_ck7x_delay_mask         (0xC0000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_17_plt_p3_txl_ck7x_inv_mask           (0x20000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_17_plt_p3_txl_cm_mode_mask            (0x08000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_17_plt_p3_txl_ib2x_mask               (0x07F00000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_17_plt_p3_txl_ck7x_lag_mask           (0x0007F000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_17_plt_p3_txl_ck7x_delay(data)        (0xC0000000&((data)<<30))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_17_plt_p3_txl_ck7x_inv(data)          (0x20000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_17_plt_p3_txl_cm_mode(data)           (0x08000000&((data)<<27))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_17_plt_p3_txl_ib2x(data)              (0x07F00000&((data)<<20))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_17_plt_p3_txl_ck7x_lag(data)          (0x0007F000&((data)<<12))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_17_get_plt_p3_txl_ck7x_delay(data)    ((0xC0000000&(data))>>30)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_17_get_plt_p3_txl_ck7x_inv(data)      ((0x20000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_17_get_plt_p3_txl_cm_mode(data)       ((0x08000000&(data))>>27)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_17_get_plt_p3_txl_ib2x(data)          ((0x07F00000&(data))>>20)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_17_get_plt_p3_txl_ck7x_lag(data)      ((0x0007F000&(data))>>12)

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0                                     0x18000DB0
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_reg_addr                            "0xB8000DB0"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_reg                                 0xB8000DB0
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_inst_addr                           "0x0023"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_reg(data)                       (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_reg                             (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_cmu_y_bpsdivm_shift                 (31)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_plt_p0_txlgn_mode_shift             (25)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_plt_p0_txlgp_mode_shift             (21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_plt_p0_txlg_ckphs_shift             (19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_plt_p0_txlg_sel_emp_shift           (16)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_plt_p0_txlg_sr_shift                (14)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_plt_p0_txlg_term_shift              (12)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_plt_p1_txlgn_mode_shift             (9)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_plt_p1_txlgp_mode_shift             (5)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_plt_p1_txlg_ckphs_shift             (3)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_plt_p1_txlg_sel_emp_shift           (0)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_cmu_y_bpsdivm_mask                  (0x80000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_plt_p0_txlgn_mode_mask              (0x0E000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_plt_p0_txlgp_mode_mask              (0x00E00000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_plt_p0_txlg_ckphs_mask              (0x00180000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_plt_p0_txlg_sel_emp_mask            (0x00070000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_plt_p0_txlg_sr_mask                 (0x0000C000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_plt_p0_txlg_term_mask               (0x00003000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_plt_p1_txlgn_mode_mask              (0x00000E00)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_plt_p1_txlgp_mode_mask              (0x000000E0)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_plt_p1_txlg_ckphs_mask              (0x00000018)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_plt_p1_txlg_sel_emp_mask            (0x00000007)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_cmu_y_bpsdivm(data)                 (0x80000000&((data)<<31))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_plt_p0_txlgn_mode(data)             (0x0E000000&((data)<<25))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_plt_p0_txlgp_mode(data)             (0x00E00000&((data)<<21))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_plt_p0_txlg_ckphs(data)             (0x00180000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_plt_p0_txlg_sel_emp(data)           (0x00070000&((data)<<16))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_plt_p0_txlg_sr(data)                (0x0000C000&((data)<<14))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_plt_p0_txlg_term(data)              (0x00003000&((data)<<12))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_plt_p1_txlgn_mode(data)             (0x00000E00&((data)<<9))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_plt_p1_txlgp_mode(data)             (0x000000E0&((data)<<5))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_plt_p1_txlg_ckphs(data)             (0x00000018&((data)<<3))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_plt_p1_txlg_sel_emp(data)           (0x00000007&(data))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_get_cmu_y_bpsdivm(data)             ((0x80000000&(data))>>31)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_get_plt_p0_txlgn_mode(data)         ((0x0E000000&(data))>>25)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_get_plt_p0_txlgp_mode(data)         ((0x00E00000&(data))>>21)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_get_plt_p0_txlg_ckphs(data)         ((0x00180000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_get_plt_p0_txlg_sel_emp(data)       ((0x00070000&(data))>>16)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_get_plt_p0_txlg_sr(data)            ((0x0000C000&(data))>>14)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_get_plt_p0_txlg_term(data)          ((0x00003000&(data))>>12)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_get_plt_p1_txlgn_mode(data)         ((0x00000E00&(data))>>9)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_get_plt_p1_txlgp_mode(data)         ((0x000000E0&(data))>>5)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_get_plt_p1_txlg_ckphs(data)         ((0x00000018&(data))>>3)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_0_get_plt_p1_txlg_sel_emp(data)       (0x00000007&(data))

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_0                                     0x18000D00
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_0_reg_addr                            "0xB8000D00"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_0_reg                                 0xB8000D00
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_0_inst_addr                           "0x0024"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_0_reg(data)                       (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_0_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_0_reg                             (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_0_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_0_plt_y_a1_pi_phsel_shift             (20)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_0_plt_y_a1_sel_2xi_shift              (19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_0_plt_y_a2_pi_phsel_shift             (7)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_0_plt_y_a2_sel_2xi_shift              (6)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_0_plt_y_a_pi_freq_shift               (4)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_0_plt_y_sel_v25_shift                 (0)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_0_plt_y_a1_pi_phsel_mask              (0xFFF00000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_0_plt_y_a1_sel_2xi_mask               (0x00080000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_0_plt_y_a2_pi_phsel_mask              (0x0007FF80)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_0_plt_y_a2_sel_2xi_mask               (0x00000040)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_0_plt_y_a_pi_freq_mask                (0x00000030)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_0_plt_y_sel_v25_mask                  (0x00000001)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_0_plt_y_a1_pi_phsel(data)             (0xFFF00000&((data)<<20))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_0_plt_y_a1_sel_2xi(data)              (0x00080000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_0_plt_y_a2_pi_phsel(data)             (0x0007FF80&((data)<<7))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_0_plt_y_a2_sel_2xi(data)              (0x00000040&((data)<<6))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_0_plt_y_a_pi_freq(data)               (0x00000030&((data)<<4))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_0_plt_y_sel_v25(data)                 (0x00000001&(data))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_0_get_plt_y_a1_pi_phsel(data)         ((0xFFF00000&(data))>>20)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_0_get_plt_y_a1_sel_2xi(data)          ((0x00080000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_0_get_plt_y_a2_pi_phsel(data)         ((0x0007FF80&(data))>>7)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_0_get_plt_y_a2_sel_2xi(data)          ((0x00000040&(data))>>6)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_0_get_plt_y_a_pi_freq(data)           ((0x00000030&(data))>>4)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_0_get_plt_y_sel_v25(data)             (0x00000001&(data))

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_2                                     0x18000D08
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_2_reg_addr                            "0xB8000D08"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_2_reg                                 0xB8000D08
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_2_inst_addr                           "0x0025"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_2_reg(data)                       (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_2_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_2_reg                             (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_2_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_2_plt_y_ab_pi_phsel_shift             (20)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_2_plt_y_ab_freq_shift                 (18)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_2_plt_y_ab_sel_2xi_shift              (17)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_2_plt_y_ab_pi_phsel_mask              (0xFFF00000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_2_plt_y_ab_freq_mask                  (0x000C0000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_2_plt_y_ab_sel_2xi_mask               (0x00020000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_2_plt_y_ab_pi_phsel(data)             (0xFFF00000&((data)<<20))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_2_plt_y_ab_freq(data)                 (0x000C0000&((data)<<18))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_2_plt_y_ab_sel_2xi(data)              (0x00020000&((data)<<17))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_2_get_plt_y_ab_pi_phsel(data)         ((0xFFF00000&(data))>>20)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_2_get_plt_y_ab_freq(data)             ((0x000C0000&(data))>>18)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_2_get_plt_y_ab_sel_2xi(data)          ((0x00020000&(data))>>17)

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_1                                     0x18000D04
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_1_reg_addr                            "0xB8000D04"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_1_reg                                 0xB8000D04
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_1_inst_addr                           "0x0026"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_1_reg(data)                       (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_1_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_1_reg                             (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_1_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_1_plt_y_b1_pi_phsel_shift             (20)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_1_plt_y_b1_sel_2xi_shift              (19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_1_plt_y_b2_pi_phsel_shift             (7)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_1_plt_y_b2_sel_2xi_shift              (6)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_1_plt_y_b_pi_freq_shift               (4)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_1_plt_y_b1_pi_phsel_mask              (0xFFF00000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_1_plt_y_b1_sel_2xi_mask               (0x00080000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_1_plt_y_b2_pi_phsel_mask              (0x0007FF80)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_1_plt_y_b2_sel_2xi_mask               (0x00000040)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_1_plt_y_b_pi_freq_mask                (0x00000030)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_1_plt_y_b1_pi_phsel(data)             (0xFFF00000&((data)<<20))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_1_plt_y_b1_sel_2xi(data)              (0x00080000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_1_plt_y_b2_pi_phsel(data)             (0x0007FF80&((data)<<7))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_1_plt_y_b2_sel_2xi(data)              (0x00000040&((data)<<6))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_1_plt_y_b_pi_freq(data)               (0x00000030&((data)<<4))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_1_get_plt_y_b1_pi_phsel(data)         ((0xFFF00000&(data))>>20)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_1_get_plt_y_b1_sel_2xi(data)          ((0x00080000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_1_get_plt_y_b2_pi_phsel(data)         ((0x0007FF80&(data))>>7)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_1_get_plt_y_b2_sel_2xi(data)          ((0x00000040&(data))>>6)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_1_get_plt_y_b_pi_freq(data)           ((0x00000030&(data))>>4)

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3                                     0x18000D0C
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_reg_addr                            "0xB8000D0C"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_reg                                 0xB8000D0C
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_inst_addr                           "0x0027"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_reg(data)                       (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_reg                             (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_big_kvco_shift            (31)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_ckpixel_inv_shift         (30)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_ck_ref_inv_shift          (29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_div248_shift              (26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_loop_divp_shift           (20)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_sel_cp_i_shift            (16)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_sel_sc1_shift             (13)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_sel_sc2_shift             (12)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_sel_sr_shift              (9)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_sel_vldo_shift            (7)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_en_test_shift                 (6)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_a_pi_bypass_shift         (5)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_b_pi_bypass_shift         (4)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_wdrst_shift               (2)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_wdset_shift               (1)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_cmu_y_wdo_shift                     (0)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_big_kvco_mask             (0x80000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_ckpixel_inv_mask          (0x40000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_ck_ref_inv_mask           (0x20000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_div248_mask               (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_loop_divp_mask            (0x03F00000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_sel_cp_i_mask             (0x00070000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_sel_sc1_mask              (0x0000E000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_sel_sc2_mask              (0x00001000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_sel_sr_mask               (0x00000E00)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_sel_vldo_mask             (0x00000180)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_en_test_mask                  (0x00000040)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_a_pi_bypass_mask          (0x00000020)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_b_pi_bypass_mask          (0x00000010)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_wdrst_mask                (0x00000004)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_wdset_mask                (0x00000002)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_cmu_y_wdo_mask                      (0x00000001)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_big_kvco(data)            (0x80000000&((data)<<31))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_ckpixel_inv(data)         (0x40000000&((data)<<30))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_ck_ref_inv(data)          (0x20000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_div248(data)              (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_loop_divp(data)           (0x03F00000&((data)<<20))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_sel_cp_i(data)            (0x00070000&((data)<<16))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_sel_sc1(data)             (0x0000E000&((data)<<13))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_sel_sc2(data)             (0x00001000&((data)<<12))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_sel_sr(data)              (0x00000E00&((data)<<9))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_sel_vldo(data)            (0x00000180&((data)<<7))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_en_test(data)                 (0x00000040&((data)<<6))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_a_pi_bypass(data)         (0x00000020&((data)<<5))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_b_pi_bypass(data)         (0x00000010&((data)<<4))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_wdrst(data)               (0x00000004&((data)<<2))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_plt_y_cmu_wdset(data)               (0x00000002&((data)<<1))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_cmu_y_wdo(data)                     (0x00000001&(data))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_get_plt_y_cmu_big_kvco(data)        ((0x80000000&(data))>>31)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_get_plt_y_cmu_ckpixel_inv(data)     ((0x40000000&(data))>>30)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_get_plt_y_cmu_ck_ref_inv(data)      ((0x20000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_get_plt_y_cmu_div248(data)          ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_get_plt_y_cmu_loop_divp(data)       ((0x03F00000&(data))>>20)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_get_plt_y_cmu_sel_cp_i(data)        ((0x00070000&(data))>>16)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_get_plt_y_cmu_sel_sc1(data)         ((0x0000E000&(data))>>13)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_get_plt_y_cmu_sel_sc2(data)         ((0x00001000&(data))>>12)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_get_plt_y_cmu_sel_sr(data)          ((0x00000E00&(data))>>9)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_get_plt_y_cmu_sel_vldo(data)        ((0x00000180&(data))>>7)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_get_plt_y_en_test(data)             ((0x00000040&(data))>>6)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_get_plt_y_cmu_a_pi_bypass(data)     ((0x00000020&(data))>>5)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_get_plt_y_cmu_b_pi_bypass(data)     ((0x00000010&(data))>>4)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_get_plt_y_cmu_wdrst(data)           ((0x00000004&(data))>>2)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_get_plt_y_cmu_wdset(data)           ((0x00000002&(data))>>1)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_3_get_cmu_y_wdo(data)                 (0x00000001&(data))

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_18                                    0x18000D50
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_18_reg_addr                           "0xB8000D50"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_18_reg                                0xB8000D50
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_18_inst_addr                          "0x0028"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_18_reg(data)                      (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_18_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_18_reg                            (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_18_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_18_plt_y_sel_isource_shift            (31)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_18_plt_y_sel_test_shift               (28)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_18_plt_y_sel_txl_vldo_shift           (26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_18_plt_y_sel_tx_i_shift               (22)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_18_plt_y_sel_vcm_shift                (17)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_18_plt_y_en_lv_ldo_shift              (15)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_18_plt_y_en_txl_ldo_shift             (14)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_18_plt_y_sel_lv_vldo_shift            (11)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_18_plt_y_sel_isource_mask             (0x80000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_18_plt_y_sel_test_mask                (0x30000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_18_plt_y_sel_txl_vldo_mask            (0x0C000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_18_plt_y_sel_tx_i_mask                (0x03C00000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_18_plt_y_sel_vcm_mask                 (0x003E0000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_18_plt_y_en_lv_ldo_mask               (0x00008000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_18_plt_y_en_txl_ldo_mask              (0x00004000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_18_plt_y_sel_lv_vldo_mask             (0x00003800)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_18_plt_y_sel_isource(data)            (0x80000000&((data)<<31))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_18_plt_y_sel_test(data)               (0x30000000&((data)<<28))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_18_plt_y_sel_txl_vldo(data)           (0x0C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_18_plt_y_sel_tx_i(data)               (0x03C00000&((data)<<22))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_18_plt_y_sel_vcm(data)                (0x003E0000&((data)<<17))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_18_plt_y_en_lv_ldo(data)              (0x00008000&((data)<<15))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_18_plt_y_en_txl_ldo(data)             (0x00004000&((data)<<14))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_18_plt_y_sel_lv_vldo(data)            (0x00003800&((data)<<11))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_18_get_plt_y_sel_isource(data)        ((0x80000000&(data))>>31)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_18_get_plt_y_sel_test(data)           ((0x30000000&(data))>>28)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_18_get_plt_y_sel_txl_vldo(data)       ((0x0C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_18_get_plt_y_sel_tx_i(data)           ((0x03C00000&(data))>>22)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_18_get_plt_y_sel_vcm(data)            ((0x003E0000&(data))>>17)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_18_get_plt_y_en_lv_ldo(data)          ((0x00008000&(data))>>15)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_18_get_plt_y_en_txl_ldo(data)         ((0x00004000&(data))>>14)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_18_get_plt_y_sel_lv_vldo(data)        ((0x00003800&(data))>>11)

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_2                                     0x18000C08
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_2_reg_addr                            "0xB8000C08"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_2_reg                                 0xB8000C08
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_2_inst_addr                           "0x0029"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_2_reg(data)                       (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_2_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_2_reg                             (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_2_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_2_plt_x_ab_pi_phsel_shift             (20)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_2_plt_x_ab_freq_shift                 (18)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_2_plt_x_ab_sel_2xi_shift              (17)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_2_cmu_x_bpsdivm_shift                 (11)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_2_plt_x_ab_pi_phsel_mask              (0xFFF00000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_2_plt_x_ab_freq_mask                  (0x000C0000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_2_plt_x_ab_sel_2xi_mask               (0x00020000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_2_cmu_x_bpsdivm_mask                  (0x00000800)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_2_plt_x_ab_pi_phsel(data)             (0xFFF00000&((data)<<20))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_2_plt_x_ab_freq(data)                 (0x000C0000&((data)<<18))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_2_plt_x_ab_sel_2xi(data)              (0x00020000&((data)<<17))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_2_cmu_x_bpsdivm(data)                 (0x00000800&((data)<<11))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_2_get_plt_x_ab_pi_phsel(data)         ((0xFFF00000&(data))>>20)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_2_get_plt_x_ab_freq(data)             ((0x000C0000&(data))>>18)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_2_get_plt_x_ab_sel_2xi(data)          ((0x00020000&(data))>>17)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_2_get_cmu_x_bpsdivm(data)             ((0x00000800&(data))>>11)

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_0                                     0x18000C00
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_0_reg_addr                            "0xB8000C00"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_0_reg                                 0xB8000C00
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_0_inst_addr                           "0x002A"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_0_reg(data)                       (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_0_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_0_reg                             (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_0_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_0_plt_x_a1_pi_phsel_shift             (20)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_0_plt_x_a1_sel_2xi_shift              (19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_0_plt_x_a2_pi_phsel_shift             (7)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_0_plt_x_a2_sel_2xi_shift              (6)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_0_plt_x_a_pi_freq_shift               (4)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_0_plt_sbg_shift                       (1)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_0_plt_x_sel_v25_shift                 (0)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_0_plt_x_a1_pi_phsel_mask              (0xFFF00000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_0_plt_x_a1_sel_2xi_mask               (0x00080000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_0_plt_x_a2_pi_phsel_mask              (0x0007FF80)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_0_plt_x_a2_sel_2xi_mask               (0x00000040)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_0_plt_x_a_pi_freq_mask                (0x00000030)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_0_plt_sbg_mask                        (0x00000006)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_0_plt_x_sel_v25_mask                  (0x00000001)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_0_plt_x_a1_pi_phsel(data)             (0xFFF00000&((data)<<20))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_0_plt_x_a1_sel_2xi(data)              (0x00080000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_0_plt_x_a2_pi_phsel(data)             (0x0007FF80&((data)<<7))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_0_plt_x_a2_sel_2xi(data)              (0x00000040&((data)<<6))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_0_plt_x_a_pi_freq(data)               (0x00000030&((data)<<4))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_0_plt_sbg(data)                       (0x00000006&((data)<<1))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_0_plt_x_sel_v25(data)                 (0x00000001&(data))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_0_get_plt_x_a1_pi_phsel(data)         ((0xFFF00000&(data))>>20)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_0_get_plt_x_a1_sel_2xi(data)          ((0x00080000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_0_get_plt_x_a2_pi_phsel(data)         ((0x0007FF80&(data))>>7)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_0_get_plt_x_a2_sel_2xi(data)          ((0x00000040&(data))>>6)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_0_get_plt_x_a_pi_freq(data)           ((0x00000030&(data))>>4)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_0_get_plt_sbg(data)                   ((0x00000006&(data))>>1)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_0_get_plt_x_sel_v25(data)             (0x00000001&(data))

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_1                                     0x18000C04
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_1_reg_addr                            "0xB8000C04"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_1_reg                                 0xB8000C04
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_1_inst_addr                           "0x002B"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_1_reg(data)                       (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_1_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_1_reg                             (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_1_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_1_plt_x_b1_pi_phsel_shift             (20)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_1_plt_x_b1_sel_2xi_shift              (19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_1_plt_x_b2_pi_phsel_shift             (7)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_1_plt_x_b2_sel_2xi_shift              (6)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_1_plt_x_b_pi_freq_shift               (4)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_1_plt_x_b1_pi_phsel_mask              (0xFFF00000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_1_plt_x_b1_sel_2xi_mask               (0x00080000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_1_plt_x_b2_pi_phsel_mask              (0x0007FF80)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_1_plt_x_b2_sel_2xi_mask               (0x00000040)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_1_plt_x_b_pi_freq_mask                (0x00000030)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_1_plt_x_b1_pi_phsel(data)             (0xFFF00000&((data)<<20))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_1_plt_x_b1_sel_2xi(data)              (0x00080000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_1_plt_x_b2_pi_phsel(data)             (0x0007FF80&((data)<<7))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_1_plt_x_b2_sel_2xi(data)              (0x00000040&((data)<<6))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_1_plt_x_b_pi_freq(data)               (0x00000030&((data)<<4))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_1_get_plt_x_b1_pi_phsel(data)         ((0xFFF00000&(data))>>20)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_1_get_plt_x_b1_sel_2xi(data)          ((0x00080000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_1_get_plt_x_b2_pi_phsel(data)         ((0x0007FF80&(data))>>7)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_1_get_plt_x_b2_sel_2xi(data)          ((0x00000040&(data))>>6)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_1_get_plt_x_b_pi_freq(data)           ((0x00000030&(data))>>4)

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3                                     0x18000C0C
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_reg_addr                            "0xB8000C0C"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_reg                                 0xB8000C0C
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_inst_addr                           "0x002C"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_reg(data)                       (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_reg                             (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_big_kvco_shift            (31)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_ckpixel_inv_shift         (30)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_ck_ref_inv_shift          (29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_div248_shift              (26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_loop_divp_shift           (20)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_sel_cp_i_shift            (16)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_sel_sc1_shift             (13)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_sel_sc2_shift             (12)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_sel_sr_shift              (9)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_sel_vldo_shift            (7)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_en_test_shift                 (6)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_a_pi_bypass_shift         (5)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_b_pi_bypass_shift         (4)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_wdrst_shift               (2)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_wdset_shift               (1)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_cmu_x_wdo_shift                     (0)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_big_kvco_mask             (0x80000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_ckpixel_inv_mask          (0x40000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_ck_ref_inv_mask           (0x20000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_div248_mask               (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_loop_divp_mask            (0x03F00000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_sel_cp_i_mask             (0x00070000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_sel_sc1_mask              (0x0000E000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_sel_sc2_mask              (0x00001000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_sel_sr_mask               (0x00000E00)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_sel_vldo_mask             (0x00000180)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_en_test_mask                  (0x00000040)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_a_pi_bypass_mask          (0x00000020)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_b_pi_bypass_mask          (0x00000010)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_wdrst_mask                (0x00000004)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_wdset_mask                (0x00000002)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_cmu_x_wdo_mask                      (0x00000001)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_big_kvco(data)            (0x80000000&((data)<<31))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_ckpixel_inv(data)         (0x40000000&((data)<<30))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_ck_ref_inv(data)          (0x20000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_div248(data)              (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_loop_divp(data)           (0x03F00000&((data)<<20))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_sel_cp_i(data)            (0x00070000&((data)<<16))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_sel_sc1(data)             (0x0000E000&((data)<<13))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_sel_sc2(data)             (0x00001000&((data)<<12))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_sel_sr(data)              (0x00000E00&((data)<<9))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_sel_vldo(data)            (0x00000180&((data)<<7))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_en_test(data)                 (0x00000040&((data)<<6))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_a_pi_bypass(data)         (0x00000020&((data)<<5))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_b_pi_bypass(data)         (0x00000010&((data)<<4))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_wdrst(data)               (0x00000004&((data)<<2))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_plt_x_cmu_wdset(data)               (0x00000002&((data)<<1))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_cmu_x_wdo(data)                     (0x00000001&(data))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_get_plt_x_cmu_big_kvco(data)        ((0x80000000&(data))>>31)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_get_plt_x_cmu_ckpixel_inv(data)     ((0x40000000&(data))>>30)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_get_plt_x_cmu_ck_ref_inv(data)      ((0x20000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_get_plt_x_cmu_div248(data)          ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_get_plt_x_cmu_loop_divp(data)       ((0x03F00000&(data))>>20)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_get_plt_x_cmu_sel_cp_i(data)        ((0x00070000&(data))>>16)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_get_plt_x_cmu_sel_sc1(data)         ((0x0000E000&(data))>>13)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_get_plt_x_cmu_sel_sc2(data)         ((0x00001000&(data))>>12)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_get_plt_x_cmu_sel_sr(data)          ((0x00000E00&(data))>>9)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_get_plt_x_cmu_sel_vldo(data)        ((0x00000180&(data))>>7)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_get_plt_x_en_test(data)             ((0x00000040&(data))>>6)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_get_plt_x_cmu_a_pi_bypass(data)     ((0x00000020&(data))>>5)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_get_plt_x_cmu_b_pi_bypass(data)     ((0x00000010&(data))>>4)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_get_plt_x_cmu_wdrst(data)           ((0x00000004&(data))>>2)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_get_plt_x_cmu_wdset(data)           ((0x00000002&(data))>>1)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_3_get_cmu_x_wdo(data)                 (0x00000001&(data))

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_18                                    0x18000C50
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_18_reg_addr                           "0xB8000C50"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_18_reg                                0xB8000C50
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_18_inst_addr                          "0x002D"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_18_reg(data)                      (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_18_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_18_reg                            (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_18_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_18_plt_x_sel_isource_shift            (31)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_18_plt_x_sel_test_shift               (28)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_18_plt_x_sel_txl_vldo_shift           (26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_18_plt_x_sel_tx_i_shift               (22)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_18_plt_x_sel_vcm_shift                (17)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_18_plt_x_en_lv_ldo_shift              (15)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_18_plt_x_en_txl_ldo_shift             (14)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_18_plt_x_sel_lv_vldo_shift            (11)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_18_plt_x_sel_isource_mask             (0x80000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_18_plt_x_sel_test_mask                (0x30000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_18_plt_x_sel_txl_vldo_mask            (0x0C000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_18_plt_x_sel_tx_i_mask                (0x03C00000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_18_plt_x_sel_vcm_mask                 (0x003E0000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_18_plt_x_en_lv_ldo_mask               (0x00008000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_18_plt_x_en_txl_ldo_mask              (0x00004000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_18_plt_x_sel_lv_vldo_mask             (0x00003800)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_18_plt_x_sel_isource(data)            (0x80000000&((data)<<31))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_18_plt_x_sel_test(data)               (0x30000000&((data)<<28))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_18_plt_x_sel_txl_vldo(data)           (0x0C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_18_plt_x_sel_tx_i(data)               (0x03C00000&((data)<<22))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_18_plt_x_sel_vcm(data)                (0x003E0000&((data)<<17))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_18_plt_x_en_lv_ldo(data)              (0x00008000&((data)<<15))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_18_plt_x_en_txl_ldo(data)             (0x00004000&((data)<<14))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_18_plt_x_sel_lv_vldo(data)            (0x00003800&((data)<<11))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_18_get_plt_x_sel_isource(data)        ((0x80000000&(data))>>31)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_18_get_plt_x_sel_test(data)           ((0x30000000&(data))>>28)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_18_get_plt_x_sel_txl_vldo(data)       ((0x0C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_18_get_plt_x_sel_tx_i(data)           ((0x03C00000&(data))>>22)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_18_get_plt_x_sel_vcm(data)            ((0x003E0000&(data))>>17)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_18_get_plt_x_en_lv_ldo(data)          ((0x00008000&(data))>>15)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_18_get_plt_x_en_txl_ldo(data)         ((0x00004000&(data))>>14)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_18_get_plt_x_sel_lv_vldo(data)        ((0x00003800&(data))>>11)

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1                                     0x18000DB4
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_reg_addr                            "0xB8000DB4"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_reg                                 0xB8000DB4
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_inst_addr                           "0x002E"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_reg(data)                       (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_reg                             (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_plt_p1_txlg_sr_shift                (30)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_plt_p1_txlg_term_shift              (28)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_plt_p2_txlgn_mode_shift             (25)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_plt_p2_txlgp_mode_shift             (22)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_plt_p2_txlg_ckphs_shift             (20)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_plt_p2_txlg_sel_emp_shift           (17)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_plt_p2_txlg_sr_shift                (15)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_plt_p2_txlg_term_shift              (13)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_plt_p3_txlgn_mode_shift             (10)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_plt_p3_txlgp_mode_shift             (7)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_plt_p3_txlg_ckphs_shift             (5)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_plt_p3_txlg_sel_emp_shift           (2)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_plt_p3_txlg_sr_shift                (0)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_plt_p1_txlg_sr_mask                 (0xC0000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_plt_p1_txlg_term_mask               (0x30000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_plt_p2_txlgn_mode_mask              (0x0E000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_plt_p2_txlgp_mode_mask              (0x01C00000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_plt_p2_txlg_ckphs_mask              (0x00300000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_plt_p2_txlg_sel_emp_mask            (0x000E0000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_plt_p2_txlg_sr_mask                 (0x00018000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_plt_p2_txlg_term_mask               (0x00006000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_plt_p3_txlgn_mode_mask              (0x00001C00)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_plt_p3_txlgp_mode_mask              (0x00000380)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_plt_p3_txlg_ckphs_mask              (0x00000060)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_plt_p3_txlg_sel_emp_mask            (0x0000001C)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_plt_p3_txlg_sr_mask                 (0x00000003)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_plt_p1_txlg_sr(data)                (0xC0000000&((data)<<30))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_plt_p1_txlg_term(data)              (0x30000000&((data)<<28))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_plt_p2_txlgn_mode(data)             (0x0E000000&((data)<<25))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_plt_p2_txlgp_mode(data)             (0x01C00000&((data)<<22))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_plt_p2_txlg_ckphs(data)             (0x00300000&((data)<<20))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_plt_p2_txlg_sel_emp(data)           (0x000E0000&((data)<<17))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_plt_p2_txlg_sr(data)                (0x00018000&((data)<<15))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_plt_p2_txlg_term(data)              (0x00006000&((data)<<13))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_plt_p3_txlgn_mode(data)             (0x00001C00&((data)<<10))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_plt_p3_txlgp_mode(data)             (0x00000380&((data)<<7))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_plt_p3_txlg_ckphs(data)             (0x00000060&((data)<<5))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_plt_p3_txlg_sel_emp(data)           (0x0000001C&((data)<<2))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_plt_p3_txlg_sr(data)                (0x00000003&(data))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_get_plt_p1_txlg_sr(data)            ((0xC0000000&(data))>>30)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_get_plt_p1_txlg_term(data)          ((0x30000000&(data))>>28)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_get_plt_p2_txlgn_mode(data)         ((0x0E000000&(data))>>25)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_get_plt_p2_txlgp_mode(data)         ((0x01C00000&(data))>>22)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_get_plt_p2_txlg_ckphs(data)         ((0x00300000&(data))>>20)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_get_plt_p2_txlg_sel_emp(data)       ((0x000E0000&(data))>>17)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_get_plt_p2_txlg_sr(data)            ((0x00018000&(data))>>15)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_get_plt_p2_txlg_term(data)          ((0x00006000&(data))>>13)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_get_plt_p3_txlgn_mode(data)         ((0x00001C00&(data))>>10)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_get_plt_p3_txlgp_mode(data)         ((0x00000380&(data))>>7)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_get_plt_p3_txlg_ckphs(data)         ((0x00000060&(data))>>5)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_get_plt_p3_txlg_sel_emp(data)       ((0x0000001C&(data))>>2)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_1_get_plt_p3_txlg_sr(data)            (0x00000003&(data))

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_2                                     0x18000DB8
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_2_reg_addr                            "0xB8000DB8"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_2_reg                                 0xB8000DB8
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_2_inst_addr                           "0x002F"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_2_reg(data)                       (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_2_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_2_reg                             (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_2_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_2_plt_p3_txlg_term_shift              (30)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_2_plt_c_sel_lv_vldo_shift             (28)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_2_plt_p3_txlg_term_mask               (0xC0000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_2_plt_c_sel_lv_vldo_mask              (0x30000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_2_plt_p3_txlg_term(data)              (0xC0000000&((data)<<30))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_2_plt_c_sel_lv_vldo(data)             (0x30000000&((data)<<28))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_2_get_plt_p3_txlg_term(data)          ((0xC0000000&(data))>>30)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_2_2_get_plt_c_sel_lv_vldo(data)         ((0x30000000&(data))>>28)

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_20                                    0x18000C58
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_20_reg_addr                           "0xB8000C58"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_20_reg                                0xB8000C58
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_20_inst_addr                          "0x0030"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_20_reg(data)                      (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_20_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_20_reg                            (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_20_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_20_plt_p0_txl_pre_drv_shift           (24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_20_plt_p0_txl_sr_td_shift             (16)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_20_plt_p0_txl_pre_drv_mask            (0x7F000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_20_plt_p0_txl_sr_td_mask              (0x007F0000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_20_plt_p0_txl_pre_drv(data)           (0x7F000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_20_plt_p0_txl_sr_td(data)             (0x007F0000&((data)<<16))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_20_get_plt_p0_txl_pre_drv(data)       ((0x7F000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_20_get_plt_p0_txl_sr_td(data)         ((0x007F0000&(data))>>16)

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_25                                    0x18000C6C
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_25_reg_addr                           "0xB8000C6C"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_25_reg                                0xB8000C6C
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_25_inst_addr                          "0x0031"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_25_reg(data)                      (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_25_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_25_reg                            (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_25_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_25_plt_p1_dummy_lvds_shift            (0)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_25_plt_p1_dummy_lvds_mask             (0x0FFFFFFF)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_25_plt_p1_dummy_lvds(data)            (0x0FFFFFFF&(data))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_25_get_plt_p1_dummy_lvds(data)        (0x0FFFFFFF&(data))

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_22                                    0x18000C60
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_22_reg_addr                           "0xB8000C60"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_22_reg                                0xB8000C60
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_22_inst_addr                          "0x0032"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_22_reg(data)                      (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_22_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_22_reg                            (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_22_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_22_plt_p1_txl_pre_drv_shift           (24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_22_plt_p1_txl_sr_td_shift             (16)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_22_plt_p1_txl_pre_drv_mask            (0x7F000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_22_plt_p1_txl_sr_td_mask              (0x007F0000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_22_plt_p1_txl_pre_drv(data)           (0x7F000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_22_plt_p1_txl_sr_td(data)             (0x007F0000&((data)<<16))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_22_get_plt_p1_txl_pre_drv(data)       ((0x7F000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_22_get_plt_p1_txl_sr_td(data)         ((0x007F0000&(data))>>16)

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_20                                    0x18000D58
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_20_reg_addr                           "0xB8000D58"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_20_reg                                0xB8000D58
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_20_inst_addr                          "0x0033"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_20_reg(data)                      (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_20_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_20_reg                            (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_20_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_20_plt_p2_txl_pre_drv_shift           (24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_20_plt_p2_txl_sr_td_shift             (16)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_20_plt_p2_txl_pre_drv_mask            (0x7F000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_20_plt_p2_txl_sr_td_mask              (0x007F0000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_20_plt_p2_txl_pre_drv(data)           (0x7F000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_20_plt_p2_txl_sr_td(data)             (0x007F0000&((data)<<16))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_20_get_plt_p2_txl_pre_drv(data)       ((0x7F000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_20_get_plt_p2_txl_sr_td(data)         ((0x007F0000&(data))>>16)

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_22                                    0x18000D60
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_22_reg_addr                           "0xB8000D60"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_22_reg                                0xB8000D60
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_22_inst_addr                          "0x0034"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_22_reg(data)                      (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_22_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_22_reg                            (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_22_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_22_plt_p3_txl_pre_drv_shift           (24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_22_plt_p3_txl_sr_td_shift             (16)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_22_plt_p3_txl_pre_drv_mask            (0x7F000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_22_plt_p3_txl_sr_td_mask              (0x007F0000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_22_plt_p3_txl_pre_drv(data)           (0x7F000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_22_plt_p3_txl_sr_td(data)             (0x007F0000&((data)<<16))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_22_get_plt_p3_txl_pre_drv(data)       ((0x7F000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_22_get_plt_p3_txl_sr_td(data)         ((0x007F0000&(data))>>16)

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_23                                    0x18000D64
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_23_reg_addr                           "0xB8000D64"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_23_reg                                0xB8000D64
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_23_inst_addr                          "0x0035"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_23_reg(data)                      (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_23_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_23_reg                            (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_23_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_23_plt_p2_dummy_lvds_shift            (0)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_23_plt_p2_dummy_lvds_mask             (0x0FFFFFFF)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_23_plt_p2_dummy_lvds(data)            (0x0FFFFFFF&(data))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_23_get_plt_p2_dummy_lvds(data)        (0x0FFFFFFF&(data))

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_23                                    0x18000C64
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_23_reg_addr                           "0xB8000C64"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_23_reg                                0xB8000C64
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_23_inst_addr                          "0x0036"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_23_reg(data)                      (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_23_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_23_reg                            (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_23_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_23_plt_p0_dummy_lvds_shift            (0)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_23_plt_p0_dummy_lvds_mask             (0x0FFFFFFF)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_23_plt_p0_dummy_lvds(data)            (0x0FFFFFFF&(data))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_23_get_plt_p0_dummy_lvds(data)        (0x0FFFFFFF&(data))

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_25                                    0x18000D6C
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_25_reg_addr                           "0xB8000D6C"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_25_reg                                0xB8000D6C
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_25_inst_addr                          "0x0037"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_25_reg(data)                      (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_25_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_25_reg                            (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_25_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_25_plt_p3_dummy_lvds_shift            (0)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_25_plt_p3_dummy_lvds_mask             (0x0FFFFFFF)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_25_plt_p3_dummy_lvds(data)            (0x0FFFFFFF&(data))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_25_get_plt_p3_dummy_lvds(data)        (0x0FFFFFFF&(data))

#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_27                                    0x18000C74
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_27_reg_addr                           "0xB8000C74"
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_27_reg                                0xB8000C74
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_27_inst_addr                          "0x0038"
#define  set_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_27_reg(data)                      (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_27_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_27_reg                            (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_27_reg))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_27_pow_plt_x_shift                    (31)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_27_pow_plt_p0_txl_shift               (24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_27_pow_plt_y_shift                    (23)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_27_pow_plt_p1_txl_shift               (16)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_27_pow_plt_p2_txl_shift               (8)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_27_pow_plt_p3_txl_shift               (0)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_27_pow_plt_x_mask                     (0x80000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_27_pow_plt_p0_txl_mask                (0x7F000000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_27_pow_plt_y_mask                     (0x00800000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_27_pow_plt_p1_txl_mask                (0x007F0000)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_27_pow_plt_p2_txl_mask                (0x00007F00)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_27_pow_plt_p3_txl_mask                (0x0000007F)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_27_pow_plt_x(data)                    (0x80000000&((data)<<31))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_27_pow_plt_p0_txl(data)               (0x7F000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_27_pow_plt_y(data)                    (0x00800000&((data)<<23))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_27_pow_plt_p1_txl(data)               (0x007F0000&((data)<<16))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_27_pow_plt_p2_txl(data)               (0x00007F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_27_pow_plt_p3_txl(data)               (0x0000007F&(data))
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_27_get_pow_plt_x(data)                ((0x80000000&(data))>>31)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_27_get_pow_plt_p0_txl(data)           ((0x7F000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_27_get_pow_plt_y(data)                ((0x00800000&(data))>>23)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_27_get_pow_plt_p1_txl(data)           ((0x007F0000&(data))>>16)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_27_get_pow_plt_p2_txl(data)           ((0x00007F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_27_get_pow_plt_p3_txl(data)           (0x0000007F&(data))

#define  PINMUX_LVDSPHY_TXPLL_CTRL0                                              0x18000DBC
#define  PINMUX_LVDSPHY_TXPLL_CTRL0_reg_addr                                     "0xB8000DBC"
#define  PINMUX_LVDSPHY_TXPLL_CTRL0_reg                                          0xB8000DBC
#define  PINMUX_LVDSPHY_TXPLL_CTRL0_inst_addr                                    "0x0039"
#define  set_PINMUX_LVDSPHY_TXPLL_CTRL0_reg(data)                                (*((volatile unsigned int*)PINMUX_LVDSPHY_TXPLL_CTRL0_reg)=data)
#define  get_PINMUX_LVDSPHY_TXPLL_CTRL0_reg                                      (*((volatile unsigned int*)PINMUX_LVDSPHY_TXPLL_CTRL0_reg))
#define  PINMUX_LVDSPHY_TXPLL_CTRL0_lvds_dummy_shift                             (16)
#define  PINMUX_LVDSPHY_TXPLL_CTRL0_plt_p3_ttl_str_shift                         (15)
#define  PINMUX_LVDSPHY_TXPLL_CTRL0_plt_p2_ttl_str_shift                         (14)
#define  PINMUX_LVDSPHY_TXPLL_CTRL0_plt_p1_ttl_str_shift                         (13)
#define  PINMUX_LVDSPHY_TXPLL_CTRL0_plt_p0_ttl_str_shift                         (12)
#define  PINMUX_LVDSPHY_TXPLL_CTRL0_txpll_prediv_bypass_shift                    (8)
#define  PINMUX_LVDSPHY_TXPLL_CTRL0_txpll_ckin_div_n_shift                       (0)
#define  PINMUX_LVDSPHY_TXPLL_CTRL0_lvds_dummy_mask                              (0xFFFF0000)
#define  PINMUX_LVDSPHY_TXPLL_CTRL0_plt_p3_ttl_str_mask                          (0x00008000)
#define  PINMUX_LVDSPHY_TXPLL_CTRL0_plt_p2_ttl_str_mask                          (0x00004000)
#define  PINMUX_LVDSPHY_TXPLL_CTRL0_plt_p1_ttl_str_mask                          (0x00002000)
#define  PINMUX_LVDSPHY_TXPLL_CTRL0_plt_p0_ttl_str_mask                          (0x00001000)
#define  PINMUX_LVDSPHY_TXPLL_CTRL0_txpll_prediv_bypass_mask                     (0x00000100)
#define  PINMUX_LVDSPHY_TXPLL_CTRL0_txpll_ckin_div_n_mask                        (0x0000003F)
#define  PINMUX_LVDSPHY_TXPLL_CTRL0_lvds_dummy(data)                             (0xFFFF0000&((data)<<16))
#define  PINMUX_LVDSPHY_TXPLL_CTRL0_plt_p3_ttl_str(data)                         (0x00008000&((data)<<15))
#define  PINMUX_LVDSPHY_TXPLL_CTRL0_plt_p2_ttl_str(data)                         (0x00004000&((data)<<14))
#define  PINMUX_LVDSPHY_TXPLL_CTRL0_plt_p1_ttl_str(data)                         (0x00002000&((data)<<13))
#define  PINMUX_LVDSPHY_TXPLL_CTRL0_plt_p0_ttl_str(data)                         (0x00001000&((data)<<12))
#define  PINMUX_LVDSPHY_TXPLL_CTRL0_txpll_prediv_bypass(data)                    (0x00000100&((data)<<8))
#define  PINMUX_LVDSPHY_TXPLL_CTRL0_txpll_ckin_div_n(data)                       (0x0000003F&(data))
#define  PINMUX_LVDSPHY_TXPLL_CTRL0_get_lvds_dummy(data)                         ((0xFFFF0000&(data))>>16)
#define  PINMUX_LVDSPHY_TXPLL_CTRL0_get_plt_p3_ttl_str(data)                     ((0x00008000&(data))>>15)
#define  PINMUX_LVDSPHY_TXPLL_CTRL0_get_plt_p2_ttl_str(data)                     ((0x00004000&(data))>>14)
#define  PINMUX_LVDSPHY_TXPLL_CTRL0_get_plt_p1_ttl_str(data)                     ((0x00002000&(data))>>13)
#define  PINMUX_LVDSPHY_TXPLL_CTRL0_get_plt_p0_ttl_str(data)                     ((0x00001000&(data))>>12)
#define  PINMUX_LVDSPHY_TXPLL_CTRL0_get_txpll_prediv_bypass(data)                ((0x00000100&(data))>>8)
#define  PINMUX_LVDSPHY_TXPLL_CTRL0_get_txpll_ckin_div_n(data)                   (0x0000003F&(data))

#define  PINMUX_LVDSPHY_VBY1EPI_00                                               0x18000E00
#define  PINMUX_LVDSPHY_VBY1EPI_00_reg_addr                                      "0xB8000E00"
#define  PINMUX_LVDSPHY_VBY1EPI_00_reg                                           0xB8000E00
#define  PINMUX_LVDSPHY_VBY1EPI_00_inst_addr                                     "0x003A"
#define  set_PINMUX_LVDSPHY_VBY1EPI_00_reg(data)                                 (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_00_reg)=data)
#define  get_PINMUX_LVDSPHY_VBY1EPI_00_reg                                       (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_00_reg))
#define  PINMUX_LVDSPHY_VBY1EPI_00_pow_vby1_bg_shift                             (28)
#define  PINMUX_LVDSPHY_VBY1EPI_00_pow_vby1_top_shift                            (24)
#define  PINMUX_LVDSPHY_VBY1EPI_00_vby1_bg_sel_shift                             (20)
#define  PINMUX_LVDSPHY_VBY1EPI_00_vby1_bg_isel_shift                            (16)
#define  PINMUX_LVDSPHY_VBY1EPI_00_ldo_cptest_en_shift                           (12)
#define  PINMUX_LVDSPHY_VBY1EPI_00_ldo_cptest_sel_shift                          (8)
#define  PINMUX_LVDSPHY_VBY1EPI_00_pow_vby1_bg_mask                              (0x10000000)
#define  PINMUX_LVDSPHY_VBY1EPI_00_pow_vby1_top_mask                             (0x01000000)
#define  PINMUX_LVDSPHY_VBY1EPI_00_vby1_bg_sel_mask                              (0x00300000)
#define  PINMUX_LVDSPHY_VBY1EPI_00_vby1_bg_isel_mask                             (0x000F0000)
#define  PINMUX_LVDSPHY_VBY1EPI_00_ldo_cptest_en_mask                            (0x00001000)
#define  PINMUX_LVDSPHY_VBY1EPI_00_ldo_cptest_sel_mask                           (0x00000300)
#define  PINMUX_LVDSPHY_VBY1EPI_00_pow_vby1_bg(data)                             (0x10000000&((data)<<28))
#define  PINMUX_LVDSPHY_VBY1EPI_00_pow_vby1_top(data)                            (0x01000000&((data)<<24))
#define  PINMUX_LVDSPHY_VBY1EPI_00_vby1_bg_sel(data)                             (0x00300000&((data)<<20))
#define  PINMUX_LVDSPHY_VBY1EPI_00_vby1_bg_isel(data)                            (0x000F0000&((data)<<16))
#define  PINMUX_LVDSPHY_VBY1EPI_00_ldo_cptest_en(data)                           (0x00001000&((data)<<12))
#define  PINMUX_LVDSPHY_VBY1EPI_00_ldo_cptest_sel(data)                          (0x00000300&((data)<<8))
#define  PINMUX_LVDSPHY_VBY1EPI_00_get_pow_vby1_bg(data)                         ((0x10000000&(data))>>28)
#define  PINMUX_LVDSPHY_VBY1EPI_00_get_pow_vby1_top(data)                        ((0x01000000&(data))>>24)
#define  PINMUX_LVDSPHY_VBY1EPI_00_get_vby1_bg_sel(data)                         ((0x00300000&(data))>>20)
#define  PINMUX_LVDSPHY_VBY1EPI_00_get_vby1_bg_isel(data)                        ((0x000F0000&(data))>>16)
#define  PINMUX_LVDSPHY_VBY1EPI_00_get_ldo_cptest_en(data)                       ((0x00001000&(data))>>12)
#define  PINMUX_LVDSPHY_VBY1EPI_00_get_ldo_cptest_sel(data)                      ((0x00000300&(data))>>8)

#define  PINMUX_LVDSPHY_VBY1EPI_B0                                               0x18000EB0
#define  PINMUX_LVDSPHY_VBY1EPI_B0_reg_addr                                      "0xB8000EB0"
#define  PINMUX_LVDSPHY_VBY1EPI_B0_reg                                           0xB8000EB0
#define  PINMUX_LVDSPHY_VBY1EPI_B0_inst_addr                                     "0x003B"
#define  set_PINMUX_LVDSPHY_VBY1EPI_B0_reg(data)                                 (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_B0_reg)=data)
#define  get_PINMUX_LVDSPHY_VBY1EPI_B0_reg                                       (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_B0_reg))
#define  PINMUX_LVDSPHY_VBY1EPI_B0_txpll_ldo1v_pow_shift                         (24)
#define  PINMUX_LVDSPHY_VBY1EPI_B0_txpll_ldolv_sel_shift                         (20)
#define  PINMUX_LVDSPHY_VBY1EPI_B0_txpll_ldov18_sel_shift                        (16)
#define  PINMUX_LVDSPHY_VBY1EPI_B0_txpll_mode_shift                              (12)
#define  PINMUX_LVDSPHY_VBY1EPI_B0_txpll_macpll_divm_shift                       (8)
#define  PINMUX_LVDSPHY_VBY1EPI_B0_txpll_prescalerdiv_shift                      (4)
#define  PINMUX_LVDSPHY_VBY1EPI_B0_txpll_pow_shift                               (0)
#define  PINMUX_LVDSPHY_VBY1EPI_B0_txpll_ldo1v_pow_mask                          (0x01000000)
#define  PINMUX_LVDSPHY_VBY1EPI_B0_txpll_ldolv_sel_mask                          (0x00300000)
#define  PINMUX_LVDSPHY_VBY1EPI_B0_txpll_ldov18_sel_mask                         (0x00030000)
#define  PINMUX_LVDSPHY_VBY1EPI_B0_txpll_mode_mask                               (0x00001000)
#define  PINMUX_LVDSPHY_VBY1EPI_B0_txpll_macpll_divm_mask                        (0x00000700)
#define  PINMUX_LVDSPHY_VBY1EPI_B0_txpll_prescalerdiv_mask                       (0x00000030)
#define  PINMUX_LVDSPHY_VBY1EPI_B0_txpll_pow_mask                                (0x00000001)
#define  PINMUX_LVDSPHY_VBY1EPI_B0_txpll_ldo1v_pow(data)                         (0x01000000&((data)<<24))
#define  PINMUX_LVDSPHY_VBY1EPI_B0_txpll_ldolv_sel(data)                         (0x00300000&((data)<<20))
#define  PINMUX_LVDSPHY_VBY1EPI_B0_txpll_ldov18_sel(data)                        (0x00030000&((data)<<16))
#define  PINMUX_LVDSPHY_VBY1EPI_B0_txpll_mode(data)                              (0x00001000&((data)<<12))
#define  PINMUX_LVDSPHY_VBY1EPI_B0_txpll_macpll_divm(data)                       (0x00000700&((data)<<8))
#define  PINMUX_LVDSPHY_VBY1EPI_B0_txpll_prescalerdiv(data)                      (0x00000030&((data)<<4))
#define  PINMUX_LVDSPHY_VBY1EPI_B0_txpll_pow(data)                               (0x00000001&(data))
#define  PINMUX_LVDSPHY_VBY1EPI_B0_get_txpll_ldo1v_pow(data)                     ((0x01000000&(data))>>24)
#define  PINMUX_LVDSPHY_VBY1EPI_B0_get_txpll_ldolv_sel(data)                     ((0x00300000&(data))>>20)
#define  PINMUX_LVDSPHY_VBY1EPI_B0_get_txpll_ldov18_sel(data)                    ((0x00030000&(data))>>16)
#define  PINMUX_LVDSPHY_VBY1EPI_B0_get_txpll_mode(data)                          ((0x00001000&(data))>>12)
#define  PINMUX_LVDSPHY_VBY1EPI_B0_get_txpll_macpll_divm(data)                   ((0x00000700&(data))>>8)
#define  PINMUX_LVDSPHY_VBY1EPI_B0_get_txpll_prescalerdiv(data)                  ((0x00000030&(data))>>4)
#define  PINMUX_LVDSPHY_VBY1EPI_B0_get_txpll_pow(data)                           (0x00000001&(data))

#define  PINMUX_LVDSPHY_VBY1EPI_C4                                               0x18000EC4
#define  PINMUX_LVDSPHY_VBY1EPI_C4_reg_addr                                      "0xB8000EC4"
#define  PINMUX_LVDSPHY_VBY1EPI_C4_reg                                           0xB8000EC4
#define  PINMUX_LVDSPHY_VBY1EPI_C4_inst_addr                                     "0x003C"
#define  set_PINMUX_LVDSPHY_VBY1EPI_C4_reg(data)                                 (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_C4_reg)=data)
#define  get_PINMUX_LVDSPHY_VBY1EPI_C4_reg                                       (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_C4_reg))
#define  PINMUX_LVDSPHY_VBY1EPI_C4_vby1_txpll_prediv_bypass_shift                (28)
#define  PINMUX_LVDSPHY_VBY1EPI_C4_macpll_cko_inv_shift                          (20)
#define  PINMUX_LVDSPHY_VBY1EPI_C4_ck1xp_inv_shift                               (16)
#define  PINMUX_LVDSPHY_VBY1EPI_C4_ck20xp_inv_shift                              (12)
#define  PINMUX_LVDSPHY_VBY1EPI_C4_txpll_epi_div_sel_shift                       (8)
#define  PINMUX_LVDSPHY_VBY1EPI_C4_txpll_scan_postdivp_shift                     (4)
#define  PINMUX_LVDSPHY_VBY1EPI_C4_vby1_txpll_prediv_bypass_mask                 (0x10000000)
#define  PINMUX_LVDSPHY_VBY1EPI_C4_macpll_cko_inv_mask                           (0x00100000)
#define  PINMUX_LVDSPHY_VBY1EPI_C4_ck1xp_inv_mask                                (0x00010000)
#define  PINMUX_LVDSPHY_VBY1EPI_C4_ck20xp_inv_mask                               (0x00001000)
#define  PINMUX_LVDSPHY_VBY1EPI_C4_txpll_epi_div_sel_mask                        (0x00000300)
#define  PINMUX_LVDSPHY_VBY1EPI_C4_txpll_scan_postdivp_mask                      (0x00000070)
#define  PINMUX_LVDSPHY_VBY1EPI_C4_vby1_txpll_prediv_bypass(data)                (0x10000000&((data)<<28))
#define  PINMUX_LVDSPHY_VBY1EPI_C4_macpll_cko_inv(data)                          (0x00100000&((data)<<20))
#define  PINMUX_LVDSPHY_VBY1EPI_C4_ck1xp_inv(data)                               (0x00010000&((data)<<16))
#define  PINMUX_LVDSPHY_VBY1EPI_C4_ck20xp_inv(data)                              (0x00001000&((data)<<12))
#define  PINMUX_LVDSPHY_VBY1EPI_C4_txpll_epi_div_sel(data)                       (0x00000300&((data)<<8))
#define  PINMUX_LVDSPHY_VBY1EPI_C4_txpll_scan_postdivp(data)                     (0x00000070&((data)<<4))
#define  PINMUX_LVDSPHY_VBY1EPI_C4_get_vby1_txpll_prediv_bypass(data)            ((0x10000000&(data))>>28)
#define  PINMUX_LVDSPHY_VBY1EPI_C4_get_macpll_cko_inv(data)                      ((0x00100000&(data))>>20)
#define  PINMUX_LVDSPHY_VBY1EPI_C4_get_ck1xp_inv(data)                           ((0x00010000&(data))>>16)
#define  PINMUX_LVDSPHY_VBY1EPI_C4_get_ck20xp_inv(data)                          ((0x00001000&(data))>>12)
#define  PINMUX_LVDSPHY_VBY1EPI_C4_get_txpll_epi_div_sel(data)                   ((0x00000300&(data))>>8)
#define  PINMUX_LVDSPHY_VBY1EPI_C4_get_txpll_scan_postdivp(data)                 ((0x00000070&(data))>>4)

#define  PINMUX_LVDSPHY_VBY1EPI_C0                                               0x18000EC0
#define  PINMUX_LVDSPHY_VBY1EPI_C0_reg_addr                                      "0xB8000EC0"
#define  PINMUX_LVDSPHY_VBY1EPI_C0_reg                                           0xB8000EC0
#define  PINMUX_LVDSPHY_VBY1EPI_C0_inst_addr                                     "0x003D"
#define  set_PINMUX_LVDSPHY_VBY1EPI_C0_reg(data)                                 (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_C0_reg)=data)
#define  get_PINMUX_LVDSPHY_VBY1EPI_C0_reg                                       (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_C0_reg))
#define  PINMUX_LVDSPHY_VBY1EPI_C0_txpll_ckinepi_inv_shift                       (28)
#define  PINMUX_LVDSPHY_VBY1EPI_C0_txpll_ckin_sel_shift                          (24)
#define  PINMUX_LVDSPHY_VBY1EPI_C0_txpll_cp_shift                                (20)
#define  PINMUX_LVDSPHY_VBY1EPI_C0_txpll_cs_shift                                (16)
#define  PINMUX_LVDSPHY_VBY1EPI_C0_txpll_ip_shift                                (12)
#define  PINMUX_LVDSPHY_VBY1EPI_C0_txpll_scan_mode_shift                         (8)
#define  PINMUX_LVDSPHY_VBY1EPI_C0_vby1_txpll_ckin_div_n_shift                   (0)
#define  PINMUX_LVDSPHY_VBY1EPI_C0_txpll_ckinepi_inv_mask                        (0x10000000)
#define  PINMUX_LVDSPHY_VBY1EPI_C0_txpll_ckin_sel_mask                           (0x01000000)
#define  PINMUX_LVDSPHY_VBY1EPI_C0_txpll_cp_mask                                 (0x00300000)
#define  PINMUX_LVDSPHY_VBY1EPI_C0_txpll_cs_mask                                 (0x00030000)
#define  PINMUX_LVDSPHY_VBY1EPI_C0_txpll_ip_mask                                 (0x0000F000)
#define  PINMUX_LVDSPHY_VBY1EPI_C0_txpll_scan_mode_mask                          (0x00000100)
#define  PINMUX_LVDSPHY_VBY1EPI_C0_vby1_txpll_ckin_div_n_mask                    (0x0000003F)
#define  PINMUX_LVDSPHY_VBY1EPI_C0_txpll_ckinepi_inv(data)                       (0x10000000&((data)<<28))
#define  PINMUX_LVDSPHY_VBY1EPI_C0_txpll_ckin_sel(data)                          (0x01000000&((data)<<24))
#define  PINMUX_LVDSPHY_VBY1EPI_C0_txpll_cp(data)                                (0x00300000&((data)<<20))
#define  PINMUX_LVDSPHY_VBY1EPI_C0_txpll_cs(data)                                (0x00030000&((data)<<16))
#define  PINMUX_LVDSPHY_VBY1EPI_C0_txpll_ip(data)                                (0x0000F000&((data)<<12))
#define  PINMUX_LVDSPHY_VBY1EPI_C0_txpll_scan_mode(data)                         (0x00000100&((data)<<8))
#define  PINMUX_LVDSPHY_VBY1EPI_C0_vby1_txpll_ckin_div_n(data)                   (0x0000003F&(data))
#define  PINMUX_LVDSPHY_VBY1EPI_C0_get_txpll_ckinepi_inv(data)                   ((0x10000000&(data))>>28)
#define  PINMUX_LVDSPHY_VBY1EPI_C0_get_txpll_ckin_sel(data)                      ((0x01000000&(data))>>24)
#define  PINMUX_LVDSPHY_VBY1EPI_C0_get_txpll_cp(data)                            ((0x00300000&(data))>>20)
#define  PINMUX_LVDSPHY_VBY1EPI_C0_get_txpll_cs(data)                            ((0x00030000&(data))>>16)
#define  PINMUX_LVDSPHY_VBY1EPI_C0_get_txpll_ip(data)                            ((0x0000F000&(data))>>12)
#define  PINMUX_LVDSPHY_VBY1EPI_C0_get_txpll_scan_mode(data)                     ((0x00000100&(data))>>8)
#define  PINMUX_LVDSPHY_VBY1EPI_C0_get_vby1_txpll_ckin_div_n(data)               (0x0000003F&(data))

#define  PINMUX_LVDSPHY_VBY1EPI_B8                                               0x18000EB8
#define  PINMUX_LVDSPHY_VBY1EPI_B8_reg_addr                                      "0xB8000EB8"
#define  PINMUX_LVDSPHY_VBY1EPI_B8_reg                                           0xB8000EB8
#define  PINMUX_LVDSPHY_VBY1EPI_B8_inst_addr                                     "0x003E"
#define  set_PINMUX_LVDSPHY_VBY1EPI_B8_reg(data)                                 (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_B8_reg)=data)
#define  get_PINMUX_LVDSPHY_VBY1EPI_B8_reg                                       (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_B8_reg))
#define  PINMUX_LVDSPHY_VBY1EPI_B8_txpll_reserve_shift                           (28)
#define  PINMUX_LVDSPHY_VBY1EPI_B8_txpll_vcogain_shift                           (20)
#define  PINMUX_LVDSPHY_VBY1EPI_B8_txpll_wdrst_shift                             (16)
#define  PINMUX_LVDSPHY_VBY1EPI_B8_txpll_wdset_shift                             (12)
#define  PINMUX_LVDSPHY_VBY1EPI_B8_txpll_rs_shift                                (8)
#define  PINMUX_LVDSPHY_VBY1EPI_B8_txpll_tst_div_shift                           (4)
#define  PINMUX_LVDSPHY_VBY1EPI_B8_txmacpll_bpsdivm_shift                        (0)
#define  PINMUX_LVDSPHY_VBY1EPI_B8_txpll_reserve_mask                            (0xF0000000)
#define  PINMUX_LVDSPHY_VBY1EPI_B8_txpll_vcogain_mask                            (0x00100000)
#define  PINMUX_LVDSPHY_VBY1EPI_B8_txpll_wdrst_mask                              (0x00010000)
#define  PINMUX_LVDSPHY_VBY1EPI_B8_txpll_wdset_mask                              (0x00001000)
#define  PINMUX_LVDSPHY_VBY1EPI_B8_txpll_rs_mask                                 (0x00000700)
#define  PINMUX_LVDSPHY_VBY1EPI_B8_txpll_tst_div_mask                            (0x00000070)
#define  PINMUX_LVDSPHY_VBY1EPI_B8_txmacpll_bpsdivm_mask                         (0x00000001)
#define  PINMUX_LVDSPHY_VBY1EPI_B8_txpll_reserve(data)                           (0xF0000000&((data)<<28))
#define  PINMUX_LVDSPHY_VBY1EPI_B8_txpll_vcogain(data)                           (0x00100000&((data)<<20))
#define  PINMUX_LVDSPHY_VBY1EPI_B8_txpll_wdrst(data)                             (0x00010000&((data)<<16))
#define  PINMUX_LVDSPHY_VBY1EPI_B8_txpll_wdset(data)                             (0x00001000&((data)<<12))
#define  PINMUX_LVDSPHY_VBY1EPI_B8_txpll_rs(data)                                (0x00000700&((data)<<8))
#define  PINMUX_LVDSPHY_VBY1EPI_B8_txpll_tst_div(data)                           (0x00000070&((data)<<4))
#define  PINMUX_LVDSPHY_VBY1EPI_B8_txmacpll_bpsdivm(data)                        (0x00000001&(data))
#define  PINMUX_LVDSPHY_VBY1EPI_B8_get_txpll_reserve(data)                       ((0xF0000000&(data))>>28)
#define  PINMUX_LVDSPHY_VBY1EPI_B8_get_txpll_vcogain(data)                       ((0x00100000&(data))>>20)
#define  PINMUX_LVDSPHY_VBY1EPI_B8_get_txpll_wdrst(data)                         ((0x00010000&(data))>>16)
#define  PINMUX_LVDSPHY_VBY1EPI_B8_get_txpll_wdset(data)                         ((0x00001000&(data))>>12)
#define  PINMUX_LVDSPHY_VBY1EPI_B8_get_txpll_rs(data)                            ((0x00000700&(data))>>8)
#define  PINMUX_LVDSPHY_VBY1EPI_B8_get_txpll_tst_div(data)                       ((0x00000070&(data))>>4)
#define  PINMUX_LVDSPHY_VBY1EPI_B8_get_txmacpll_bpsdivm(data)                    (0x00000001&(data))

#define  PINMUX_LVDSPHY_VBY1EPI_A0                                               0x18000EA0
#define  PINMUX_LVDSPHY_VBY1EPI_A0_reg_addr                                      "0xB8000EA0"
#define  PINMUX_LVDSPHY_VBY1EPI_A0_reg                                           0xB8000EA0
#define  PINMUX_LVDSPHY_VBY1EPI_A0_inst_addr                                     "0x003F"
#define  set_PINMUX_LVDSPHY_VBY1EPI_A0_reg(data)                                 (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_A0_reg)=data)
#define  get_PINMUX_LVDSPHY_VBY1EPI_A0_reg                                       (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_A0_reg))
#define  PINMUX_LVDSPHY_VBY1EPI_A0_tx_rten_lane_shift                            (0)
#define  PINMUX_LVDSPHY_VBY1EPI_A0_tx_rten_lane_mask                             (0x00FFFFFF)
#define  PINMUX_LVDSPHY_VBY1EPI_A0_tx_rten_lane(data)                            (0x00FFFFFF&(data))
#define  PINMUX_LVDSPHY_VBY1EPI_A0_get_tx_rten_lane(data)                        (0x00FFFFFF&(data))

#define  PINMUX_LVDSPHY_VBY1EPI_98                                               0x18000E98
#define  PINMUX_LVDSPHY_VBY1EPI_98_reg_addr                                      "0xB8000E98"
#define  PINMUX_LVDSPHY_VBY1EPI_98_reg                                           0xB8000E98
#define  PINMUX_LVDSPHY_VBY1EPI_98_inst_addr                                     "0x0040"
#define  set_PINMUX_LVDSPHY_VBY1EPI_98_reg(data)                                 (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_98_reg)=data)
#define  get_PINMUX_LVDSPHY_VBY1EPI_98_reg                                       (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_98_reg))
#define  PINMUX_LVDSPHY_VBY1EPI_98_tx_rpen_lane_shift                            (0)
#define  PINMUX_LVDSPHY_VBY1EPI_98_tx_rpen_lane_mask                             (0x00FFFFFF)
#define  PINMUX_LVDSPHY_VBY1EPI_98_tx_rpen_lane(data)                            (0x00FFFFFF&(data))
#define  PINMUX_LVDSPHY_VBY1EPI_98_get_tx_rpen_lane(data)                        (0x00FFFFFF&(data))

#define  PINMUX_LVDSPHY_VBY1EPI_90                                               0x18000E90
#define  PINMUX_LVDSPHY_VBY1EPI_90_reg_addr                                      "0xB8000E90"
#define  PINMUX_LVDSPHY_VBY1EPI_90_reg                                           0xB8000E90
#define  PINMUX_LVDSPHY_VBY1EPI_90_inst_addr                                     "0x0041"
#define  set_PINMUX_LVDSPHY_VBY1EPI_90_reg(data)                                 (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_90_reg)=data)
#define  get_PINMUX_LVDSPHY_VBY1EPI_90_reg                                       (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_90_reg))
#define  PINMUX_LVDSPHY_VBY1EPI_90_tx_pow_lane_shift                             (0)
#define  PINMUX_LVDSPHY_VBY1EPI_90_tx_pow_lane_mask                              (0x00FFFFFF)
#define  PINMUX_LVDSPHY_VBY1EPI_90_tx_pow_lane(data)                             (0x00FFFFFF&(data))
#define  PINMUX_LVDSPHY_VBY1EPI_90_get_tx_pow_lane(data)                         (0x00FFFFFF&(data))

#define  PINMUX_LVDSPHY_VBY1EPI_88                                               0x18000E88
#define  PINMUX_LVDSPHY_VBY1EPI_88_reg_addr                                      "0xB8000E88"
#define  PINMUX_LVDSPHY_VBY1EPI_88_reg                                           0xB8000E88
#define  PINMUX_LVDSPHY_VBY1EPI_88_inst_addr                                     "0x0042"
#define  set_PINMUX_LVDSPHY_VBY1EPI_88_reg(data)                                 (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_88_reg)=data)
#define  get_PINMUX_LVDSPHY_VBY1EPI_88_reg                                       (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_88_reg))
#define  PINMUX_LVDSPHY_VBY1EPI_88_tx_emph_lane_shift                            (0)
#define  PINMUX_LVDSPHY_VBY1EPI_88_tx_emph_lane_mask                             (0x00FFFFFF)
#define  PINMUX_LVDSPHY_VBY1EPI_88_tx_emph_lane(data)                            (0x00FFFFFF&(data))
#define  PINMUX_LVDSPHY_VBY1EPI_88_get_tx_emph_lane(data)                        (0x00FFFFFF&(data))

#define  PINMUX_LVDSPHY_VBY1EPI_A8                                               0x18000EA8
#define  PINMUX_LVDSPHY_VBY1EPI_A8_reg_addr                                      "0xB8000EA8"
#define  PINMUX_LVDSPHY_VBY1EPI_A8_reg                                           0xB8000EA8
#define  PINMUX_LVDSPHY_VBY1EPI_A8_inst_addr                                     "0x0043"
#define  set_PINMUX_LVDSPHY_VBY1EPI_A8_reg(data)                                 (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_A8_reg)=data)
#define  get_PINMUX_LVDSPHY_VBY1EPI_A8_reg                                       (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_A8_reg))
#define  PINMUX_LVDSPHY_VBY1EPI_A8_txlane0003_biasmode_shift                     (28)
#define  PINMUX_LVDSPHY_VBY1EPI_A8_txlane0407_biasmode_shift                     (24)
#define  PINMUX_LVDSPHY_VBY1EPI_A8_txlane0811_biasmode_shift                     (20)
#define  PINMUX_LVDSPHY_VBY1EPI_A8_txlane1215_biasmode_shift                     (16)
#define  PINMUX_LVDSPHY_VBY1EPI_A8_txlane1619_biasmode_shift                     (12)
#define  PINMUX_LVDSPHY_VBY1EPI_A8_txlane2023_biasmode_shift                     (8)
#define  PINMUX_LVDSPHY_VBY1EPI_A8_txlane0003_biasmode_mask                      (0xF0000000)
#define  PINMUX_LVDSPHY_VBY1EPI_A8_txlane0407_biasmode_mask                      (0x0F000000)
#define  PINMUX_LVDSPHY_VBY1EPI_A8_txlane0811_biasmode_mask                      (0x00F00000)
#define  PINMUX_LVDSPHY_VBY1EPI_A8_txlane1215_biasmode_mask                      (0x000F0000)
#define  PINMUX_LVDSPHY_VBY1EPI_A8_txlane1619_biasmode_mask                      (0x0000F000)
#define  PINMUX_LVDSPHY_VBY1EPI_A8_txlane2023_biasmode_mask                      (0x00000F00)
#define  PINMUX_LVDSPHY_VBY1EPI_A8_txlane0003_biasmode(data)                     (0xF0000000&((data)<<28))
#define  PINMUX_LVDSPHY_VBY1EPI_A8_txlane0407_biasmode(data)                     (0x0F000000&((data)<<24))
#define  PINMUX_LVDSPHY_VBY1EPI_A8_txlane0811_biasmode(data)                     (0x00F00000&((data)<<20))
#define  PINMUX_LVDSPHY_VBY1EPI_A8_txlane1215_biasmode(data)                     (0x000F0000&((data)<<16))
#define  PINMUX_LVDSPHY_VBY1EPI_A8_txlane1619_biasmode(data)                     (0x0000F000&((data)<<12))
#define  PINMUX_LVDSPHY_VBY1EPI_A8_txlane2023_biasmode(data)                     (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_VBY1EPI_A8_get_txlane0003_biasmode(data)                 ((0xF0000000&(data))>>28)
#define  PINMUX_LVDSPHY_VBY1EPI_A8_get_txlane0407_biasmode(data)                 ((0x0F000000&(data))>>24)
#define  PINMUX_LVDSPHY_VBY1EPI_A8_get_txlane0811_biasmode(data)                 ((0x00F00000&(data))>>20)
#define  PINMUX_LVDSPHY_VBY1EPI_A8_get_txlane1215_biasmode(data)                 ((0x000F0000&(data))>>16)
#define  PINMUX_LVDSPHY_VBY1EPI_A8_get_txlane1619_biasmode(data)                 ((0x0000F000&(data))>>12)
#define  PINMUX_LVDSPHY_VBY1EPI_A8_get_txlane2023_biasmode(data)                 ((0x00000F00&(data))>>8)

#define  PINMUX_LVDSPHY_VBY1EPI_60                                               0x18000E60
#define  PINMUX_LVDSPHY_VBY1EPI_60_reg_addr                                      "0xB8000E60"
#define  PINMUX_LVDSPHY_VBY1EPI_60_reg                                           0xB8000E60
#define  PINMUX_LVDSPHY_VBY1EPI_60_inst_addr                                     "0x0044"
#define  set_PINMUX_LVDSPHY_VBY1EPI_60_reg(data)                                 (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_60_reg)=data)
#define  get_PINMUX_LVDSPHY_VBY1EPI_60_reg                                       (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_60_reg))
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx0_rp_shift                                  (30)
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx1_rp_shift                                  (28)
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx2_rp_shift                                  (26)
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx3_rp_shift                                  (24)
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx4_rp_shift                                  (22)
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx5_rp_shift                                  (20)
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx6_rp_shift                                  (18)
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx7_rp_shift                                  (16)
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx8_rp_shift                                  (14)
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx9_rp_shift                                  (12)
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx10_rp_shift                                 (10)
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx11_rp_shift                                 (8)
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx12_rp_shift                                 (6)
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx13_rp_shift                                 (4)
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx14_rp_shift                                 (2)
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx15_rp_shift                                 (0)
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx0_rp_mask                                   (0xC0000000)
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx1_rp_mask                                   (0x30000000)
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx2_rp_mask                                   (0x0C000000)
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx3_rp_mask                                   (0x03000000)
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx4_rp_mask                                   (0x00C00000)
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx5_rp_mask                                   (0x00300000)
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx6_rp_mask                                   (0x000C0000)
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx7_rp_mask                                   (0x00030000)
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx8_rp_mask                                   (0x0000C000)
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx9_rp_mask                                   (0x00003000)
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx10_rp_mask                                  (0x00000C00)
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx11_rp_mask                                  (0x00000300)
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx12_rp_mask                                  (0x000000C0)
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx13_rp_mask                                  (0x00000030)
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx14_rp_mask                                  (0x0000000C)
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx15_rp_mask                                  (0x00000003)
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx0_rp(data)                                  (0xC0000000&((data)<<30))
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx1_rp(data)                                  (0x30000000&((data)<<28))
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx2_rp(data)                                  (0x0C000000&((data)<<26))
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx3_rp(data)                                  (0x03000000&((data)<<24))
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx4_rp(data)                                  (0x00C00000&((data)<<22))
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx5_rp(data)                                  (0x00300000&((data)<<20))
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx6_rp(data)                                  (0x000C0000&((data)<<18))
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx7_rp(data)                                  (0x00030000&((data)<<16))
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx8_rp(data)                                  (0x0000C000&((data)<<14))
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx9_rp(data)                                  (0x00003000&((data)<<12))
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx10_rp(data)                                 (0x00000C00&((data)<<10))
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx11_rp(data)                                 (0x00000300&((data)<<8))
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx12_rp(data)                                 (0x000000C0&((data)<<6))
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx13_rp(data)                                 (0x00000030&((data)<<4))
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx14_rp(data)                                 (0x0000000C&((data)<<2))
#define  PINMUX_LVDSPHY_VBY1EPI_60_tx15_rp(data)                                 (0x00000003&(data))
#define  PINMUX_LVDSPHY_VBY1EPI_60_get_tx0_rp(data)                              ((0xC0000000&(data))>>30)
#define  PINMUX_LVDSPHY_VBY1EPI_60_get_tx1_rp(data)                              ((0x30000000&(data))>>28)
#define  PINMUX_LVDSPHY_VBY1EPI_60_get_tx2_rp(data)                              ((0x0C000000&(data))>>26)
#define  PINMUX_LVDSPHY_VBY1EPI_60_get_tx3_rp(data)                              ((0x03000000&(data))>>24)
#define  PINMUX_LVDSPHY_VBY1EPI_60_get_tx4_rp(data)                              ((0x00C00000&(data))>>22)
#define  PINMUX_LVDSPHY_VBY1EPI_60_get_tx5_rp(data)                              ((0x00300000&(data))>>20)
#define  PINMUX_LVDSPHY_VBY1EPI_60_get_tx6_rp(data)                              ((0x000C0000&(data))>>18)
#define  PINMUX_LVDSPHY_VBY1EPI_60_get_tx7_rp(data)                              ((0x00030000&(data))>>16)
#define  PINMUX_LVDSPHY_VBY1EPI_60_get_tx8_rp(data)                              ((0x0000C000&(data))>>14)
#define  PINMUX_LVDSPHY_VBY1EPI_60_get_tx9_rp(data)                              ((0x00003000&(data))>>12)
#define  PINMUX_LVDSPHY_VBY1EPI_60_get_tx10_rp(data)                             ((0x00000C00&(data))>>10)
#define  PINMUX_LVDSPHY_VBY1EPI_60_get_tx11_rp(data)                             ((0x00000300&(data))>>8)
#define  PINMUX_LVDSPHY_VBY1EPI_60_get_tx12_rp(data)                             ((0x000000C0&(data))>>6)
#define  PINMUX_LVDSPHY_VBY1EPI_60_get_tx13_rp(data)                             ((0x00000030&(data))>>4)
#define  PINMUX_LVDSPHY_VBY1EPI_60_get_tx14_rp(data)                             ((0x0000000C&(data))>>2)
#define  PINMUX_LVDSPHY_VBY1EPI_60_get_tx15_rp(data)                             (0x00000003&(data))

#define  PINMUX_LVDSPHY_VBY1EPI_68                                               0x18000E68
#define  PINMUX_LVDSPHY_VBY1EPI_68_reg_addr                                      "0xB8000E68"
#define  PINMUX_LVDSPHY_VBY1EPI_68_reg                                           0xB8000E68
#define  PINMUX_LVDSPHY_VBY1EPI_68_inst_addr                                     "0x0045"
#define  set_PINMUX_LVDSPHY_VBY1EPI_68_reg(data)                                 (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_68_reg)=data)
#define  get_PINMUX_LVDSPHY_VBY1EPI_68_reg                                       (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_68_reg))
#define  PINMUX_LVDSPHY_VBY1EPI_68_tx16_rp_shift                                 (30)
#define  PINMUX_LVDSPHY_VBY1EPI_68_tx17_rp_shift                                 (28)
#define  PINMUX_LVDSPHY_VBY1EPI_68_tx18_rp_shift                                 (26)
#define  PINMUX_LVDSPHY_VBY1EPI_68_tx19_rp_shift                                 (24)
#define  PINMUX_LVDSPHY_VBY1EPI_68_tx20_rp_shift                                 (22)
#define  PINMUX_LVDSPHY_VBY1EPI_68_tx21_rp_shift                                 (20)
#define  PINMUX_LVDSPHY_VBY1EPI_68_tx22_rp_shift                                 (18)
#define  PINMUX_LVDSPHY_VBY1EPI_68_tx23_rp_shift                                 (16)
#define  PINMUX_LVDSPHY_VBY1EPI_68_tx16_rp_mask                                  (0xC0000000)
#define  PINMUX_LVDSPHY_VBY1EPI_68_tx17_rp_mask                                  (0x30000000)
#define  PINMUX_LVDSPHY_VBY1EPI_68_tx18_rp_mask                                  (0x0C000000)
#define  PINMUX_LVDSPHY_VBY1EPI_68_tx19_rp_mask                                  (0x03000000)
#define  PINMUX_LVDSPHY_VBY1EPI_68_tx20_rp_mask                                  (0x00C00000)
#define  PINMUX_LVDSPHY_VBY1EPI_68_tx21_rp_mask                                  (0x00300000)
#define  PINMUX_LVDSPHY_VBY1EPI_68_tx22_rp_mask                                  (0x000C0000)
#define  PINMUX_LVDSPHY_VBY1EPI_68_tx23_rp_mask                                  (0x00030000)
#define  PINMUX_LVDSPHY_VBY1EPI_68_tx16_rp(data)                                 (0xC0000000&((data)<<30))
#define  PINMUX_LVDSPHY_VBY1EPI_68_tx17_rp(data)                                 (0x30000000&((data)<<28))
#define  PINMUX_LVDSPHY_VBY1EPI_68_tx18_rp(data)                                 (0x0C000000&((data)<<26))
#define  PINMUX_LVDSPHY_VBY1EPI_68_tx19_rp(data)                                 (0x03000000&((data)<<24))
#define  PINMUX_LVDSPHY_VBY1EPI_68_tx20_rp(data)                                 (0x00C00000&((data)<<22))
#define  PINMUX_LVDSPHY_VBY1EPI_68_tx21_rp(data)                                 (0x00300000&((data)<<20))
#define  PINMUX_LVDSPHY_VBY1EPI_68_tx22_rp(data)                                 (0x000C0000&((data)<<18))
#define  PINMUX_LVDSPHY_VBY1EPI_68_tx23_rp(data)                                 (0x00030000&((data)<<16))
#define  PINMUX_LVDSPHY_VBY1EPI_68_get_tx16_rp(data)                             ((0xC0000000&(data))>>30)
#define  PINMUX_LVDSPHY_VBY1EPI_68_get_tx17_rp(data)                             ((0x30000000&(data))>>28)
#define  PINMUX_LVDSPHY_VBY1EPI_68_get_tx18_rp(data)                             ((0x0C000000&(data))>>26)
#define  PINMUX_LVDSPHY_VBY1EPI_68_get_tx19_rp(data)                             ((0x03000000&(data))>>24)
#define  PINMUX_LVDSPHY_VBY1EPI_68_get_tx20_rp(data)                             ((0x00C00000&(data))>>22)
#define  PINMUX_LVDSPHY_VBY1EPI_68_get_tx21_rp(data)                             ((0x00300000&(data))>>20)
#define  PINMUX_LVDSPHY_VBY1EPI_68_get_tx22_rp(data)                             ((0x000C0000&(data))>>18)
#define  PINMUX_LVDSPHY_VBY1EPI_68_get_tx23_rp(data)                             ((0x00030000&(data))>>16)

#define  PINMUX_LVDSPHY_VBY1EPI_40                                               0x18000E40
#define  PINMUX_LVDSPHY_VBY1EPI_40_reg_addr                                      "0xB8000E40"
#define  PINMUX_LVDSPHY_VBY1EPI_40_reg                                           0xB8000E40
#define  PINMUX_LVDSPHY_VBY1EPI_40_inst_addr                                     "0x0046"
#define  set_PINMUX_LVDSPHY_VBY1EPI_40_reg(data)                                 (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_40_reg)=data)
#define  get_PINMUX_LVDSPHY_VBY1EPI_40_reg                                       (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_40_reg))
#define  PINMUX_LVDSPHY_VBY1EPI_40_tx8_iem_shift                                 (28)
#define  PINMUX_LVDSPHY_VBY1EPI_40_tx9_iem_shift                                 (24)
#define  PINMUX_LVDSPHY_VBY1EPI_40_tx10_iem_shift                                (20)
#define  PINMUX_LVDSPHY_VBY1EPI_40_tx11_iem_shift                                (16)
#define  PINMUX_LVDSPHY_VBY1EPI_40_tx12_iem_shift                                (12)
#define  PINMUX_LVDSPHY_VBY1EPI_40_tx13_iem_shift                                (8)
#define  PINMUX_LVDSPHY_VBY1EPI_40_tx14_iem_shift                                (4)
#define  PINMUX_LVDSPHY_VBY1EPI_40_tx15_iem_shift                                (0)
#define  PINMUX_LVDSPHY_VBY1EPI_40_tx8_iem_mask                                  (0xF0000000)
#define  PINMUX_LVDSPHY_VBY1EPI_40_tx9_iem_mask                                  (0x0F000000)
#define  PINMUX_LVDSPHY_VBY1EPI_40_tx10_iem_mask                                 (0x00F00000)
#define  PINMUX_LVDSPHY_VBY1EPI_40_tx11_iem_mask                                 (0x000F0000)
#define  PINMUX_LVDSPHY_VBY1EPI_40_tx12_iem_mask                                 (0x0000F000)
#define  PINMUX_LVDSPHY_VBY1EPI_40_tx13_iem_mask                                 (0x00000F00)
#define  PINMUX_LVDSPHY_VBY1EPI_40_tx14_iem_mask                                 (0x000000F0)
#define  PINMUX_LVDSPHY_VBY1EPI_40_tx15_iem_mask                                 (0x0000000F)
#define  PINMUX_LVDSPHY_VBY1EPI_40_tx8_iem(data)                                 (0xF0000000&((data)<<28))
#define  PINMUX_LVDSPHY_VBY1EPI_40_tx9_iem(data)                                 (0x0F000000&((data)<<24))
#define  PINMUX_LVDSPHY_VBY1EPI_40_tx10_iem(data)                                (0x00F00000&((data)<<20))
#define  PINMUX_LVDSPHY_VBY1EPI_40_tx11_iem(data)                                (0x000F0000&((data)<<16))
#define  PINMUX_LVDSPHY_VBY1EPI_40_tx12_iem(data)                                (0x0000F000&((data)<<12))
#define  PINMUX_LVDSPHY_VBY1EPI_40_tx13_iem(data)                                (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_VBY1EPI_40_tx14_iem(data)                                (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_VBY1EPI_40_tx15_iem(data)                                (0x0000000F&(data))
#define  PINMUX_LVDSPHY_VBY1EPI_40_get_tx8_iem(data)                             ((0xF0000000&(data))>>28)
#define  PINMUX_LVDSPHY_VBY1EPI_40_get_tx9_iem(data)                             ((0x0F000000&(data))>>24)
#define  PINMUX_LVDSPHY_VBY1EPI_40_get_tx10_iem(data)                            ((0x00F00000&(data))>>20)
#define  PINMUX_LVDSPHY_VBY1EPI_40_get_tx11_iem(data)                            ((0x000F0000&(data))>>16)
#define  PINMUX_LVDSPHY_VBY1EPI_40_get_tx12_iem(data)                            ((0x0000F000&(data))>>12)
#define  PINMUX_LVDSPHY_VBY1EPI_40_get_tx13_iem(data)                            ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_VBY1EPI_40_get_tx14_iem(data)                            ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_VBY1EPI_40_get_tx15_iem(data)                            (0x0000000F&(data))

#define  PINMUX_LVDSPHY_VBY1EPI_38                                               0x18000E38
#define  PINMUX_LVDSPHY_VBY1EPI_38_reg_addr                                      "0xB8000E38"
#define  PINMUX_LVDSPHY_VBY1EPI_38_reg                                           0xB8000E38
#define  PINMUX_LVDSPHY_VBY1EPI_38_inst_addr                                     "0x0047"
#define  set_PINMUX_LVDSPHY_VBY1EPI_38_reg(data)                                 (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_38_reg)=data)
#define  get_PINMUX_LVDSPHY_VBY1EPI_38_reg                                       (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_38_reg))
#define  PINMUX_LVDSPHY_VBY1EPI_38_tx0_iem_shift                                 (28)
#define  PINMUX_LVDSPHY_VBY1EPI_38_tx1_iem_shift                                 (24)
#define  PINMUX_LVDSPHY_VBY1EPI_38_tx2_iem_shift                                 (20)
#define  PINMUX_LVDSPHY_VBY1EPI_38_tx3_iem_shift                                 (16)
#define  PINMUX_LVDSPHY_VBY1EPI_38_tx4_iem_shift                                 (12)
#define  PINMUX_LVDSPHY_VBY1EPI_38_tx5_iem_shift                                 (8)
#define  PINMUX_LVDSPHY_VBY1EPI_38_tx6_iem_shift                                 (4)
#define  PINMUX_LVDSPHY_VBY1EPI_38_tx7_iem_shift                                 (0)
#define  PINMUX_LVDSPHY_VBY1EPI_38_tx0_iem_mask                                  (0xF0000000)
#define  PINMUX_LVDSPHY_VBY1EPI_38_tx1_iem_mask                                  (0x0F000000)
#define  PINMUX_LVDSPHY_VBY1EPI_38_tx2_iem_mask                                  (0x00F00000)
#define  PINMUX_LVDSPHY_VBY1EPI_38_tx3_iem_mask                                  (0x000F0000)
#define  PINMUX_LVDSPHY_VBY1EPI_38_tx4_iem_mask                                  (0x0000F000)
#define  PINMUX_LVDSPHY_VBY1EPI_38_tx5_iem_mask                                  (0x00000F00)
#define  PINMUX_LVDSPHY_VBY1EPI_38_tx6_iem_mask                                  (0x000000F0)
#define  PINMUX_LVDSPHY_VBY1EPI_38_tx7_iem_mask                                  (0x0000000F)
#define  PINMUX_LVDSPHY_VBY1EPI_38_tx0_iem(data)                                 (0xF0000000&((data)<<28))
#define  PINMUX_LVDSPHY_VBY1EPI_38_tx1_iem(data)                                 (0x0F000000&((data)<<24))
#define  PINMUX_LVDSPHY_VBY1EPI_38_tx2_iem(data)                                 (0x00F00000&((data)<<20))
#define  PINMUX_LVDSPHY_VBY1EPI_38_tx3_iem(data)                                 (0x000F0000&((data)<<16))
#define  PINMUX_LVDSPHY_VBY1EPI_38_tx4_iem(data)                                 (0x0000F000&((data)<<12))
#define  PINMUX_LVDSPHY_VBY1EPI_38_tx5_iem(data)                                 (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_VBY1EPI_38_tx6_iem(data)                                 (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_VBY1EPI_38_tx7_iem(data)                                 (0x0000000F&(data))
#define  PINMUX_LVDSPHY_VBY1EPI_38_get_tx0_iem(data)                             ((0xF0000000&(data))>>28)
#define  PINMUX_LVDSPHY_VBY1EPI_38_get_tx1_iem(data)                             ((0x0F000000&(data))>>24)
#define  PINMUX_LVDSPHY_VBY1EPI_38_get_tx2_iem(data)                             ((0x00F00000&(data))>>20)
#define  PINMUX_LVDSPHY_VBY1EPI_38_get_tx3_iem(data)                             ((0x000F0000&(data))>>16)
#define  PINMUX_LVDSPHY_VBY1EPI_38_get_tx4_iem(data)                             ((0x0000F000&(data))>>12)
#define  PINMUX_LVDSPHY_VBY1EPI_38_get_tx5_iem(data)                             ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_VBY1EPI_38_get_tx6_iem(data)                             ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_VBY1EPI_38_get_tx7_iem(data)                             (0x0000000F&(data))

#define  PINMUX_LVDSPHY_VBY1EPI_48                                               0x18000E48
#define  PINMUX_LVDSPHY_VBY1EPI_48_reg_addr                                      "0xB8000E48"
#define  PINMUX_LVDSPHY_VBY1EPI_48_reg                                           0xB8000E48
#define  PINMUX_LVDSPHY_VBY1EPI_48_inst_addr                                     "0x0048"
#define  set_PINMUX_LVDSPHY_VBY1EPI_48_reg(data)                                 (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_48_reg)=data)
#define  get_PINMUX_LVDSPHY_VBY1EPI_48_reg                                       (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_48_reg))
#define  PINMUX_LVDSPHY_VBY1EPI_48_tx16_iem_shift                                (28)
#define  PINMUX_LVDSPHY_VBY1EPI_48_tx17_iem_shift                                (24)
#define  PINMUX_LVDSPHY_VBY1EPI_48_tx18_iem_shift                                (20)
#define  PINMUX_LVDSPHY_VBY1EPI_48_tx19_iem_shift                                (16)
#define  PINMUX_LVDSPHY_VBY1EPI_48_tx20_iem_shift                                (12)
#define  PINMUX_LVDSPHY_VBY1EPI_48_tx21_iem_shift                                (8)
#define  PINMUX_LVDSPHY_VBY1EPI_48_tx22_iem_shift                                (4)
#define  PINMUX_LVDSPHY_VBY1EPI_48_tx23_iem_shift                                (0)
#define  PINMUX_LVDSPHY_VBY1EPI_48_tx16_iem_mask                                 (0xF0000000)
#define  PINMUX_LVDSPHY_VBY1EPI_48_tx17_iem_mask                                 (0x0F000000)
#define  PINMUX_LVDSPHY_VBY1EPI_48_tx18_iem_mask                                 (0x00F00000)
#define  PINMUX_LVDSPHY_VBY1EPI_48_tx19_iem_mask                                 (0x000F0000)
#define  PINMUX_LVDSPHY_VBY1EPI_48_tx20_iem_mask                                 (0x0000F000)
#define  PINMUX_LVDSPHY_VBY1EPI_48_tx21_iem_mask                                 (0x00000F00)
#define  PINMUX_LVDSPHY_VBY1EPI_48_tx22_iem_mask                                 (0x000000F0)
#define  PINMUX_LVDSPHY_VBY1EPI_48_tx23_iem_mask                                 (0x0000000F)
#define  PINMUX_LVDSPHY_VBY1EPI_48_tx16_iem(data)                                (0xF0000000&((data)<<28))
#define  PINMUX_LVDSPHY_VBY1EPI_48_tx17_iem(data)                                (0x0F000000&((data)<<24))
#define  PINMUX_LVDSPHY_VBY1EPI_48_tx18_iem(data)                                (0x00F00000&((data)<<20))
#define  PINMUX_LVDSPHY_VBY1EPI_48_tx19_iem(data)                                (0x000F0000&((data)<<16))
#define  PINMUX_LVDSPHY_VBY1EPI_48_tx20_iem(data)                                (0x0000F000&((data)<<12))
#define  PINMUX_LVDSPHY_VBY1EPI_48_tx21_iem(data)                                (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_VBY1EPI_48_tx22_iem(data)                                (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_VBY1EPI_48_tx23_iem(data)                                (0x0000000F&(data))
#define  PINMUX_LVDSPHY_VBY1EPI_48_get_tx16_iem(data)                            ((0xF0000000&(data))>>28)
#define  PINMUX_LVDSPHY_VBY1EPI_48_get_tx17_iem(data)                            ((0x0F000000&(data))>>24)
#define  PINMUX_LVDSPHY_VBY1EPI_48_get_tx18_iem(data)                            ((0x00F00000&(data))>>20)
#define  PINMUX_LVDSPHY_VBY1EPI_48_get_tx19_iem(data)                            ((0x000F0000&(data))>>16)
#define  PINMUX_LVDSPHY_VBY1EPI_48_get_tx20_iem(data)                            ((0x0000F000&(data))>>12)
#define  PINMUX_LVDSPHY_VBY1EPI_48_get_tx21_iem(data)                            ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_VBY1EPI_48_get_tx22_iem(data)                            ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_VBY1EPI_48_get_tx23_iem(data)                            (0x0000000F&(data))

#define  PINMUX_LVDSPHY_VBY1EPI_20                                               0x18000E20
#define  PINMUX_LVDSPHY_VBY1EPI_20_reg_addr                                      "0xB8000E20"
#define  PINMUX_LVDSPHY_VBY1EPI_20_reg                                           0xB8000E20
#define  PINMUX_LVDSPHY_VBY1EPI_20_inst_addr                                     "0x0049"
#define  set_PINMUX_LVDSPHY_VBY1EPI_20_reg(data)                                 (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_20_reg)=data)
#define  get_PINMUX_LVDSPHY_VBY1EPI_20_reg                                       (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_20_reg))
#define  PINMUX_LVDSPHY_VBY1EPI_20_tx0_idrv_shift                                (28)
#define  PINMUX_LVDSPHY_VBY1EPI_20_tx1_idrv_shift                                (24)
#define  PINMUX_LVDSPHY_VBY1EPI_20_tx2_idrv_shift                                (20)
#define  PINMUX_LVDSPHY_VBY1EPI_20_tx3_idrv_shift                                (16)
#define  PINMUX_LVDSPHY_VBY1EPI_20_tx4_idrv_shift                                (12)
#define  PINMUX_LVDSPHY_VBY1EPI_20_tx5_idrv_shift                                (8)
#define  PINMUX_LVDSPHY_VBY1EPI_20_tx6_idrv_shift                                (4)
#define  PINMUX_LVDSPHY_VBY1EPI_20_tx7_idrv_shift                                (0)
#define  PINMUX_LVDSPHY_VBY1EPI_20_tx0_idrv_mask                                 (0xF0000000)
#define  PINMUX_LVDSPHY_VBY1EPI_20_tx1_idrv_mask                                 (0x0F000000)
#define  PINMUX_LVDSPHY_VBY1EPI_20_tx2_idrv_mask                                 (0x00F00000)
#define  PINMUX_LVDSPHY_VBY1EPI_20_tx3_idrv_mask                                 (0x000F0000)
#define  PINMUX_LVDSPHY_VBY1EPI_20_tx4_idrv_mask                                 (0x0000F000)
#define  PINMUX_LVDSPHY_VBY1EPI_20_tx5_idrv_mask                                 (0x00000F00)
#define  PINMUX_LVDSPHY_VBY1EPI_20_tx6_idrv_mask                                 (0x000000F0)
#define  PINMUX_LVDSPHY_VBY1EPI_20_tx7_idrv_mask                                 (0x0000000F)
#define  PINMUX_LVDSPHY_VBY1EPI_20_tx0_idrv(data)                                (0xF0000000&((data)<<28))
#define  PINMUX_LVDSPHY_VBY1EPI_20_tx1_idrv(data)                                (0x0F000000&((data)<<24))
#define  PINMUX_LVDSPHY_VBY1EPI_20_tx2_idrv(data)                                (0x00F00000&((data)<<20))
#define  PINMUX_LVDSPHY_VBY1EPI_20_tx3_idrv(data)                                (0x000F0000&((data)<<16))
#define  PINMUX_LVDSPHY_VBY1EPI_20_tx4_idrv(data)                                (0x0000F000&((data)<<12))
#define  PINMUX_LVDSPHY_VBY1EPI_20_tx5_idrv(data)                                (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_VBY1EPI_20_tx6_idrv(data)                                (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_VBY1EPI_20_tx7_idrv(data)                                (0x0000000F&(data))
#define  PINMUX_LVDSPHY_VBY1EPI_20_get_tx0_idrv(data)                            ((0xF0000000&(data))>>28)
#define  PINMUX_LVDSPHY_VBY1EPI_20_get_tx1_idrv(data)                            ((0x0F000000&(data))>>24)
#define  PINMUX_LVDSPHY_VBY1EPI_20_get_tx2_idrv(data)                            ((0x00F00000&(data))>>20)
#define  PINMUX_LVDSPHY_VBY1EPI_20_get_tx3_idrv(data)                            ((0x000F0000&(data))>>16)
#define  PINMUX_LVDSPHY_VBY1EPI_20_get_tx4_idrv(data)                            ((0x0000F000&(data))>>12)
#define  PINMUX_LVDSPHY_VBY1EPI_20_get_tx5_idrv(data)                            ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_VBY1EPI_20_get_tx6_idrv(data)                            ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_VBY1EPI_20_get_tx7_idrv(data)                            (0x0000000F&(data))

#define  PINMUX_LVDSPHY_VBY1EPI_28                                               0x18000E28
#define  PINMUX_LVDSPHY_VBY1EPI_28_reg_addr                                      "0xB8000E28"
#define  PINMUX_LVDSPHY_VBY1EPI_28_reg                                           0xB8000E28
#define  PINMUX_LVDSPHY_VBY1EPI_28_inst_addr                                     "0x004A"
#define  set_PINMUX_LVDSPHY_VBY1EPI_28_reg(data)                                 (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_28_reg)=data)
#define  get_PINMUX_LVDSPHY_VBY1EPI_28_reg                                       (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_28_reg))
#define  PINMUX_LVDSPHY_VBY1EPI_28_tx8_idrv_shift                                (28)
#define  PINMUX_LVDSPHY_VBY1EPI_28_tx9_idrv_shift                                (24)
#define  PINMUX_LVDSPHY_VBY1EPI_28_tx10_idrv_shift                               (20)
#define  PINMUX_LVDSPHY_VBY1EPI_28_tx11_idrv_shift                               (16)
#define  PINMUX_LVDSPHY_VBY1EPI_28_tx12_idrv_shift                               (12)
#define  PINMUX_LVDSPHY_VBY1EPI_28_tx13_idrv_shift                               (8)
#define  PINMUX_LVDSPHY_VBY1EPI_28_tx14_idrv_shift                               (4)
#define  PINMUX_LVDSPHY_VBY1EPI_28_tx15_idrv_shift                               (0)
#define  PINMUX_LVDSPHY_VBY1EPI_28_tx8_idrv_mask                                 (0xF0000000)
#define  PINMUX_LVDSPHY_VBY1EPI_28_tx9_idrv_mask                                 (0x0F000000)
#define  PINMUX_LVDSPHY_VBY1EPI_28_tx10_idrv_mask                                (0x00F00000)
#define  PINMUX_LVDSPHY_VBY1EPI_28_tx11_idrv_mask                                (0x000F0000)
#define  PINMUX_LVDSPHY_VBY1EPI_28_tx12_idrv_mask                                (0x0000F000)
#define  PINMUX_LVDSPHY_VBY1EPI_28_tx13_idrv_mask                                (0x00000F00)
#define  PINMUX_LVDSPHY_VBY1EPI_28_tx14_idrv_mask                                (0x000000F0)
#define  PINMUX_LVDSPHY_VBY1EPI_28_tx15_idrv_mask                                (0x0000000F)
#define  PINMUX_LVDSPHY_VBY1EPI_28_tx8_idrv(data)                                (0xF0000000&((data)<<28))
#define  PINMUX_LVDSPHY_VBY1EPI_28_tx9_idrv(data)                                (0x0F000000&((data)<<24))
#define  PINMUX_LVDSPHY_VBY1EPI_28_tx10_idrv(data)                               (0x00F00000&((data)<<20))
#define  PINMUX_LVDSPHY_VBY1EPI_28_tx11_idrv(data)                               (0x000F0000&((data)<<16))
#define  PINMUX_LVDSPHY_VBY1EPI_28_tx12_idrv(data)                               (0x0000F000&((data)<<12))
#define  PINMUX_LVDSPHY_VBY1EPI_28_tx13_idrv(data)                               (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_VBY1EPI_28_tx14_idrv(data)                               (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_VBY1EPI_28_tx15_idrv(data)                               (0x0000000F&(data))
#define  PINMUX_LVDSPHY_VBY1EPI_28_get_tx8_idrv(data)                            ((0xF0000000&(data))>>28)
#define  PINMUX_LVDSPHY_VBY1EPI_28_get_tx9_idrv(data)                            ((0x0F000000&(data))>>24)
#define  PINMUX_LVDSPHY_VBY1EPI_28_get_tx10_idrv(data)                           ((0x00F00000&(data))>>20)
#define  PINMUX_LVDSPHY_VBY1EPI_28_get_tx11_idrv(data)                           ((0x000F0000&(data))>>16)
#define  PINMUX_LVDSPHY_VBY1EPI_28_get_tx12_idrv(data)                           ((0x0000F000&(data))>>12)
#define  PINMUX_LVDSPHY_VBY1EPI_28_get_tx13_idrv(data)                           ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_VBY1EPI_28_get_tx14_idrv(data)                           ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_VBY1EPI_28_get_tx15_idrv(data)                           (0x0000000F&(data))

#define  PINMUX_LVDSPHY_VBY1EPI_30                                               0x18000E30
#define  PINMUX_LVDSPHY_VBY1EPI_30_reg_addr                                      "0xB8000E30"
#define  PINMUX_LVDSPHY_VBY1EPI_30_reg                                           0xB8000E30
#define  PINMUX_LVDSPHY_VBY1EPI_30_inst_addr                                     "0x004B"
#define  set_PINMUX_LVDSPHY_VBY1EPI_30_reg(data)                                 (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_30_reg)=data)
#define  get_PINMUX_LVDSPHY_VBY1EPI_30_reg                                       (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_30_reg))
#define  PINMUX_LVDSPHY_VBY1EPI_30_tx16_idrv_shift                               (28)
#define  PINMUX_LVDSPHY_VBY1EPI_30_tx17_idrv_shift                               (24)
#define  PINMUX_LVDSPHY_VBY1EPI_30_tx18_idrv_shift                               (20)
#define  PINMUX_LVDSPHY_VBY1EPI_30_tx19_idrv_shift                               (16)
#define  PINMUX_LVDSPHY_VBY1EPI_30_tx20_idrv_shift                               (12)
#define  PINMUX_LVDSPHY_VBY1EPI_30_tx21_idrv_shift                               (8)
#define  PINMUX_LVDSPHY_VBY1EPI_30_tx22_idrv_shift                               (4)
#define  PINMUX_LVDSPHY_VBY1EPI_30_tx23_idrv_shift                               (0)
#define  PINMUX_LVDSPHY_VBY1EPI_30_tx16_idrv_mask                                (0xF0000000)
#define  PINMUX_LVDSPHY_VBY1EPI_30_tx17_idrv_mask                                (0x0F000000)
#define  PINMUX_LVDSPHY_VBY1EPI_30_tx18_idrv_mask                                (0x00F00000)
#define  PINMUX_LVDSPHY_VBY1EPI_30_tx19_idrv_mask                                (0x000F0000)
#define  PINMUX_LVDSPHY_VBY1EPI_30_tx20_idrv_mask                                (0x0000F000)
#define  PINMUX_LVDSPHY_VBY1EPI_30_tx21_idrv_mask                                (0x00000F00)
#define  PINMUX_LVDSPHY_VBY1EPI_30_tx22_idrv_mask                                (0x000000F0)
#define  PINMUX_LVDSPHY_VBY1EPI_30_tx23_idrv_mask                                (0x0000000F)
#define  PINMUX_LVDSPHY_VBY1EPI_30_tx16_idrv(data)                               (0xF0000000&((data)<<28))
#define  PINMUX_LVDSPHY_VBY1EPI_30_tx17_idrv(data)                               (0x0F000000&((data)<<24))
#define  PINMUX_LVDSPHY_VBY1EPI_30_tx18_idrv(data)                               (0x00F00000&((data)<<20))
#define  PINMUX_LVDSPHY_VBY1EPI_30_tx19_idrv(data)                               (0x000F0000&((data)<<16))
#define  PINMUX_LVDSPHY_VBY1EPI_30_tx20_idrv(data)                               (0x0000F000&((data)<<12))
#define  PINMUX_LVDSPHY_VBY1EPI_30_tx21_idrv(data)                               (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_VBY1EPI_30_tx22_idrv(data)                               (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_VBY1EPI_30_tx23_idrv(data)                               (0x0000000F&(data))
#define  PINMUX_LVDSPHY_VBY1EPI_30_get_tx16_idrv(data)                           ((0xF0000000&(data))>>28)
#define  PINMUX_LVDSPHY_VBY1EPI_30_get_tx17_idrv(data)                           ((0x0F000000&(data))>>24)
#define  PINMUX_LVDSPHY_VBY1EPI_30_get_tx18_idrv(data)                           ((0x00F00000&(data))>>20)
#define  PINMUX_LVDSPHY_VBY1EPI_30_get_tx19_idrv(data)                           ((0x000F0000&(data))>>16)
#define  PINMUX_LVDSPHY_VBY1EPI_30_get_tx20_idrv(data)                           ((0x0000F000&(data))>>12)
#define  PINMUX_LVDSPHY_VBY1EPI_30_get_tx21_idrv(data)                           ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_VBY1EPI_30_get_tx22_idrv(data)                           ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_VBY1EPI_30_get_tx23_idrv(data)                           (0x0000000F&(data))

#define  PINMUX_LVDSPHY_VBY1EPI_18                                               0x18000E18
#define  PINMUX_LVDSPHY_VBY1EPI_18_reg_addr                                      "0xB8000E18"
#define  PINMUX_LVDSPHY_VBY1EPI_18_reg                                           0xB8000E18
#define  PINMUX_LVDSPHY_VBY1EPI_18_inst_addr                                     "0x004C"
#define  set_PINMUX_LVDSPHY_VBY1EPI_18_reg(data)                                 (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_18_reg)=data)
#define  get_PINMUX_LVDSPHY_VBY1EPI_18_reg                                       (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_18_reg))
#define  PINMUX_LVDSPHY_VBY1EPI_18_tx16_dummy_shift                              (28)
#define  PINMUX_LVDSPHY_VBY1EPI_18_tx17_dummy_shift                              (24)
#define  PINMUX_LVDSPHY_VBY1EPI_18_tx18_dummy_shift                              (20)
#define  PINMUX_LVDSPHY_VBY1EPI_18_tx19_dummy_shift                              (16)
#define  PINMUX_LVDSPHY_VBY1EPI_18_tx20_dummy_shift                              (12)
#define  PINMUX_LVDSPHY_VBY1EPI_18_tx21_dummy_shift                              (8)
#define  PINMUX_LVDSPHY_VBY1EPI_18_tx22_dummy_shift                              (4)
#define  PINMUX_LVDSPHY_VBY1EPI_18_tx23_dummy_shift                              (0)
#define  PINMUX_LVDSPHY_VBY1EPI_18_tx16_dummy_mask                               (0xF0000000)
#define  PINMUX_LVDSPHY_VBY1EPI_18_tx17_dummy_mask                               (0x0F000000)
#define  PINMUX_LVDSPHY_VBY1EPI_18_tx18_dummy_mask                               (0x00F00000)
#define  PINMUX_LVDSPHY_VBY1EPI_18_tx19_dummy_mask                               (0x000F0000)
#define  PINMUX_LVDSPHY_VBY1EPI_18_tx20_dummy_mask                               (0x0000F000)
#define  PINMUX_LVDSPHY_VBY1EPI_18_tx21_dummy_mask                               (0x00000F00)
#define  PINMUX_LVDSPHY_VBY1EPI_18_tx22_dummy_mask                               (0x000000F0)
#define  PINMUX_LVDSPHY_VBY1EPI_18_tx23_dummy_mask                               (0x0000000F)
#define  PINMUX_LVDSPHY_VBY1EPI_18_tx16_dummy(data)                              (0xF0000000&((data)<<28))
#define  PINMUX_LVDSPHY_VBY1EPI_18_tx17_dummy(data)                              (0x0F000000&((data)<<24))
#define  PINMUX_LVDSPHY_VBY1EPI_18_tx18_dummy(data)                              (0x00F00000&((data)<<20))
#define  PINMUX_LVDSPHY_VBY1EPI_18_tx19_dummy(data)                              (0x000F0000&((data)<<16))
#define  PINMUX_LVDSPHY_VBY1EPI_18_tx20_dummy(data)                              (0x0000F000&((data)<<12))
#define  PINMUX_LVDSPHY_VBY1EPI_18_tx21_dummy(data)                              (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_VBY1EPI_18_tx22_dummy(data)                              (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_VBY1EPI_18_tx23_dummy(data)                              (0x0000000F&(data))
#define  PINMUX_LVDSPHY_VBY1EPI_18_get_tx16_dummy(data)                          ((0xF0000000&(data))>>28)
#define  PINMUX_LVDSPHY_VBY1EPI_18_get_tx17_dummy(data)                          ((0x0F000000&(data))>>24)
#define  PINMUX_LVDSPHY_VBY1EPI_18_get_tx18_dummy(data)                          ((0x00F00000&(data))>>20)
#define  PINMUX_LVDSPHY_VBY1EPI_18_get_tx19_dummy(data)                          ((0x000F0000&(data))>>16)
#define  PINMUX_LVDSPHY_VBY1EPI_18_get_tx20_dummy(data)                          ((0x0000F000&(data))>>12)
#define  PINMUX_LVDSPHY_VBY1EPI_18_get_tx21_dummy(data)                          ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_VBY1EPI_18_get_tx22_dummy(data)                          ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_VBY1EPI_18_get_tx23_dummy(data)                          (0x0000000F&(data))

#define  PINMUX_LVDSPHY_VBY1EPI_10                                               0x18000E10
#define  PINMUX_LVDSPHY_VBY1EPI_10_reg_addr                                      "0xB8000E10"
#define  PINMUX_LVDSPHY_VBY1EPI_10_reg                                           0xB8000E10
#define  PINMUX_LVDSPHY_VBY1EPI_10_inst_addr                                     "0x004D"
#define  set_PINMUX_LVDSPHY_VBY1EPI_10_reg(data)                                 (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_10_reg)=data)
#define  get_PINMUX_LVDSPHY_VBY1EPI_10_reg                                       (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_10_reg))
#define  PINMUX_LVDSPHY_VBY1EPI_10_tx8_dummy_shift                               (28)
#define  PINMUX_LVDSPHY_VBY1EPI_10_tx9_dummy_shift                               (24)
#define  PINMUX_LVDSPHY_VBY1EPI_10_tx10_dummy_shift                              (20)
#define  PINMUX_LVDSPHY_VBY1EPI_10_tx11_dummy_shift                              (16)
#define  PINMUX_LVDSPHY_VBY1EPI_10_tx12_dummy_shift                              (12)
#define  PINMUX_LVDSPHY_VBY1EPI_10_tx13_dummy_shift                              (8)
#define  PINMUX_LVDSPHY_VBY1EPI_10_tx14_dummy_shift                              (4)
#define  PINMUX_LVDSPHY_VBY1EPI_10_tx15_dummy_shift                              (0)
#define  PINMUX_LVDSPHY_VBY1EPI_10_tx8_dummy_mask                                (0xF0000000)
#define  PINMUX_LVDSPHY_VBY1EPI_10_tx9_dummy_mask                                (0x0F000000)
#define  PINMUX_LVDSPHY_VBY1EPI_10_tx10_dummy_mask                               (0x00F00000)
#define  PINMUX_LVDSPHY_VBY1EPI_10_tx11_dummy_mask                               (0x000F0000)
#define  PINMUX_LVDSPHY_VBY1EPI_10_tx12_dummy_mask                               (0x0000F000)
#define  PINMUX_LVDSPHY_VBY1EPI_10_tx13_dummy_mask                               (0x00000F00)
#define  PINMUX_LVDSPHY_VBY1EPI_10_tx14_dummy_mask                               (0x000000F0)
#define  PINMUX_LVDSPHY_VBY1EPI_10_tx15_dummy_mask                               (0x0000000F)
#define  PINMUX_LVDSPHY_VBY1EPI_10_tx8_dummy(data)                               (0xF0000000&((data)<<28))
#define  PINMUX_LVDSPHY_VBY1EPI_10_tx9_dummy(data)                               (0x0F000000&((data)<<24))
#define  PINMUX_LVDSPHY_VBY1EPI_10_tx10_dummy(data)                              (0x00F00000&((data)<<20))
#define  PINMUX_LVDSPHY_VBY1EPI_10_tx11_dummy(data)                              (0x000F0000&((data)<<16))
#define  PINMUX_LVDSPHY_VBY1EPI_10_tx12_dummy(data)                              (0x0000F000&((data)<<12))
#define  PINMUX_LVDSPHY_VBY1EPI_10_tx13_dummy(data)                              (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_VBY1EPI_10_tx14_dummy(data)                              (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_VBY1EPI_10_tx15_dummy(data)                              (0x0000000F&(data))
#define  PINMUX_LVDSPHY_VBY1EPI_10_get_tx8_dummy(data)                           ((0xF0000000&(data))>>28)
#define  PINMUX_LVDSPHY_VBY1EPI_10_get_tx9_dummy(data)                           ((0x0F000000&(data))>>24)
#define  PINMUX_LVDSPHY_VBY1EPI_10_get_tx10_dummy(data)                          ((0x00F00000&(data))>>20)
#define  PINMUX_LVDSPHY_VBY1EPI_10_get_tx11_dummy(data)                          ((0x000F0000&(data))>>16)
#define  PINMUX_LVDSPHY_VBY1EPI_10_get_tx12_dummy(data)                          ((0x0000F000&(data))>>12)
#define  PINMUX_LVDSPHY_VBY1EPI_10_get_tx13_dummy(data)                          ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_VBY1EPI_10_get_tx14_dummy(data)                          ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_VBY1EPI_10_get_tx15_dummy(data)                          (0x0000000F&(data))

#define  PINMUX_LVDSPHY_VBY1EPI_08                                               0x18000E08
#define  PINMUX_LVDSPHY_VBY1EPI_08_reg_addr                                      "0xB8000E08"
#define  PINMUX_LVDSPHY_VBY1EPI_08_reg                                           0xB8000E08
#define  PINMUX_LVDSPHY_VBY1EPI_08_inst_addr                                     "0x004E"
#define  set_PINMUX_LVDSPHY_VBY1EPI_08_reg(data)                                 (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_08_reg)=data)
#define  get_PINMUX_LVDSPHY_VBY1EPI_08_reg                                       (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_08_reg))
#define  PINMUX_LVDSPHY_VBY1EPI_08_tx0_dummy_shift                               (28)
#define  PINMUX_LVDSPHY_VBY1EPI_08_tx1_dummy_shift                               (24)
#define  PINMUX_LVDSPHY_VBY1EPI_08_tx2_dummy_shift                               (20)
#define  PINMUX_LVDSPHY_VBY1EPI_08_tx3_dummy_shift                               (16)
#define  PINMUX_LVDSPHY_VBY1EPI_08_tx4_dummy_shift                               (12)
#define  PINMUX_LVDSPHY_VBY1EPI_08_tx5_dummy_shift                               (8)
#define  PINMUX_LVDSPHY_VBY1EPI_08_tx6_dummy_shift                               (4)
#define  PINMUX_LVDSPHY_VBY1EPI_08_tx7_dummy_shift                               (0)
#define  PINMUX_LVDSPHY_VBY1EPI_08_tx0_dummy_mask                                (0xF0000000)
#define  PINMUX_LVDSPHY_VBY1EPI_08_tx1_dummy_mask                                (0x0F000000)
#define  PINMUX_LVDSPHY_VBY1EPI_08_tx2_dummy_mask                                (0x00F00000)
#define  PINMUX_LVDSPHY_VBY1EPI_08_tx3_dummy_mask                                (0x000F0000)
#define  PINMUX_LVDSPHY_VBY1EPI_08_tx4_dummy_mask                                (0x0000F000)
#define  PINMUX_LVDSPHY_VBY1EPI_08_tx5_dummy_mask                                (0x00000F00)
#define  PINMUX_LVDSPHY_VBY1EPI_08_tx6_dummy_mask                                (0x000000F0)
#define  PINMUX_LVDSPHY_VBY1EPI_08_tx7_dummy_mask                                (0x0000000F)
#define  PINMUX_LVDSPHY_VBY1EPI_08_tx0_dummy(data)                               (0xF0000000&((data)<<28))
#define  PINMUX_LVDSPHY_VBY1EPI_08_tx1_dummy(data)                               (0x0F000000&((data)<<24))
#define  PINMUX_LVDSPHY_VBY1EPI_08_tx2_dummy(data)                               (0x00F00000&((data)<<20))
#define  PINMUX_LVDSPHY_VBY1EPI_08_tx3_dummy(data)                               (0x000F0000&((data)<<16))
#define  PINMUX_LVDSPHY_VBY1EPI_08_tx4_dummy(data)                               (0x0000F000&((data)<<12))
#define  PINMUX_LVDSPHY_VBY1EPI_08_tx5_dummy(data)                               (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_VBY1EPI_08_tx6_dummy(data)                               (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_VBY1EPI_08_tx7_dummy(data)                               (0x0000000F&(data))
#define  PINMUX_LVDSPHY_VBY1EPI_08_get_tx0_dummy(data)                           ((0xF0000000&(data))>>28)
#define  PINMUX_LVDSPHY_VBY1EPI_08_get_tx1_dummy(data)                           ((0x0F000000&(data))>>24)
#define  PINMUX_LVDSPHY_VBY1EPI_08_get_tx2_dummy(data)                           ((0x00F00000&(data))>>20)
#define  PINMUX_LVDSPHY_VBY1EPI_08_get_tx3_dummy(data)                           ((0x000F0000&(data))>>16)
#define  PINMUX_LVDSPHY_VBY1EPI_08_get_tx4_dummy(data)                           ((0x0000F000&(data))>>12)
#define  PINMUX_LVDSPHY_VBY1EPI_08_get_tx5_dummy(data)                           ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_VBY1EPI_08_get_tx6_dummy(data)                           ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_VBY1EPI_08_get_tx7_dummy(data)                           (0x0000000F&(data))

#define  PINMUX_LVDSPHY_VBY1EPI_D0                                               0x18000ED0
#define  PINMUX_LVDSPHY_VBY1EPI_D0_reg_addr                                      "0xB8000ED0"
#define  PINMUX_LVDSPHY_VBY1EPI_D0_reg                                           0xB8000ED0
#define  PINMUX_LVDSPHY_VBY1EPI_D0_inst_addr                                     "0x004F"
#define  set_PINMUX_LVDSPHY_VBY1EPI_D0_reg(data)                                 (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_D0_reg)=data)
#define  get_PINMUX_LVDSPHY_VBY1EPI_D0_reg                                       (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_D0_reg))
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx15_ndrv_shift                               (30)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx14_ndrv_shift                               (28)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx13_ndrv_shift                               (26)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx12_ndrv_shift                               (24)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx11_ndrv_shift                               (22)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx10_ndrv_shift                               (20)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx9_ndrv_shift                                (18)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx8_ndrv_shift                                (16)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx7_ndrv_shift                                (14)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx6_ndrv_shift                                (12)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx5_ndrv_shift                                (10)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx4_ndrv_shift                                (8)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx3_ndrv_shift                                (6)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx2_ndrv_shift                                (4)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx1_ndrv_shift                                (2)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx0_ndrv_shift                                (0)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx15_ndrv_mask                                (0xC0000000)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx14_ndrv_mask                                (0x30000000)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx13_ndrv_mask                                (0x0C000000)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx12_ndrv_mask                                (0x03000000)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx11_ndrv_mask                                (0x00C00000)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx10_ndrv_mask                                (0x00300000)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx9_ndrv_mask                                 (0x000C0000)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx8_ndrv_mask                                 (0x00030000)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx7_ndrv_mask                                 (0x0000C000)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx6_ndrv_mask                                 (0x00003000)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx5_ndrv_mask                                 (0x00000C00)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx4_ndrv_mask                                 (0x00000300)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx3_ndrv_mask                                 (0x000000C0)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx2_ndrv_mask                                 (0x00000030)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx1_ndrv_mask                                 (0x0000000C)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx0_ndrv_mask                                 (0x00000003)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx15_ndrv(data)                               (0xC0000000&((data)<<30))
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx14_ndrv(data)                               (0x30000000&((data)<<28))
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx13_ndrv(data)                               (0x0C000000&((data)<<26))
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx12_ndrv(data)                               (0x03000000&((data)<<24))
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx11_ndrv(data)                               (0x00C00000&((data)<<22))
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx10_ndrv(data)                               (0x00300000&((data)<<20))
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx9_ndrv(data)                                (0x000C0000&((data)<<18))
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx8_ndrv(data)                                (0x00030000&((data)<<16))
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx7_ndrv(data)                                (0x0000C000&((data)<<14))
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx6_ndrv(data)                                (0x00003000&((data)<<12))
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx5_ndrv(data)                                (0x00000C00&((data)<<10))
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx4_ndrv(data)                                (0x00000300&((data)<<8))
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx3_ndrv(data)                                (0x000000C0&((data)<<6))
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx2_ndrv(data)                                (0x00000030&((data)<<4))
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx1_ndrv(data)                                (0x0000000C&((data)<<2))
#define  PINMUX_LVDSPHY_VBY1EPI_D0_tx0_ndrv(data)                                (0x00000003&(data))
#define  PINMUX_LVDSPHY_VBY1EPI_D0_get_tx15_ndrv(data)                           ((0xC0000000&(data))>>30)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_get_tx14_ndrv(data)                           ((0x30000000&(data))>>28)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_get_tx13_ndrv(data)                           ((0x0C000000&(data))>>26)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_get_tx12_ndrv(data)                           ((0x03000000&(data))>>24)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_get_tx11_ndrv(data)                           ((0x00C00000&(data))>>22)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_get_tx10_ndrv(data)                           ((0x00300000&(data))>>20)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_get_tx9_ndrv(data)                            ((0x000C0000&(data))>>18)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_get_tx8_ndrv(data)                            ((0x00030000&(data))>>16)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_get_tx7_ndrv(data)                            ((0x0000C000&(data))>>14)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_get_tx6_ndrv(data)                            ((0x00003000&(data))>>12)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_get_tx5_ndrv(data)                            ((0x00000C00&(data))>>10)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_get_tx4_ndrv(data)                            ((0x00000300&(data))>>8)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_get_tx3_ndrv(data)                            ((0x000000C0&(data))>>6)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_get_tx2_ndrv(data)                            ((0x00000030&(data))>>4)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_get_tx1_ndrv(data)                            ((0x0000000C&(data))>>2)
#define  PINMUX_LVDSPHY_VBY1EPI_D0_get_tx0_ndrv(data)                            (0x00000003&(data))

#define  PINMUX_LVDSPHY_VBY1EPI_CC                                               0x18000ECC
#define  PINMUX_LVDSPHY_VBY1EPI_CC_reg_addr                                      "0xB8000ECC"
#define  PINMUX_LVDSPHY_VBY1EPI_CC_reg                                           0xB8000ECC
#define  PINMUX_LVDSPHY_VBY1EPI_CC_inst_addr                                     "0x0050"
#define  set_PINMUX_LVDSPHY_VBY1EPI_CC_reg(data)                                 (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_CC_reg)=data)
#define  get_PINMUX_LVDSPHY_VBY1EPI_CC_reg                                       (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_CC_reg))
#define  PINMUX_LVDSPHY_VBY1EPI_CC_tx23_ndrv_shift                               (14)
#define  PINMUX_LVDSPHY_VBY1EPI_CC_tx22_ndrv_shift                               (12)
#define  PINMUX_LVDSPHY_VBY1EPI_CC_tx21_ndrv_shift                               (10)
#define  PINMUX_LVDSPHY_VBY1EPI_CC_tx20_ndrv_shift                               (8)
#define  PINMUX_LVDSPHY_VBY1EPI_CC_tx19_ndrv_shift                               (6)
#define  PINMUX_LVDSPHY_VBY1EPI_CC_tx18_ndrv_shift                               (4)
#define  PINMUX_LVDSPHY_VBY1EPI_CC_tx17_ndrv_shift                               (2)
#define  PINMUX_LVDSPHY_VBY1EPI_CC_tx16_ndrv_shift                               (0)
#define  PINMUX_LVDSPHY_VBY1EPI_CC_tx23_ndrv_mask                                (0x0000C000)
#define  PINMUX_LVDSPHY_VBY1EPI_CC_tx22_ndrv_mask                                (0x00003000)
#define  PINMUX_LVDSPHY_VBY1EPI_CC_tx21_ndrv_mask                                (0x00000C00)
#define  PINMUX_LVDSPHY_VBY1EPI_CC_tx20_ndrv_mask                                (0x00000300)
#define  PINMUX_LVDSPHY_VBY1EPI_CC_tx19_ndrv_mask                                (0x000000C0)
#define  PINMUX_LVDSPHY_VBY1EPI_CC_tx18_ndrv_mask                                (0x00000030)
#define  PINMUX_LVDSPHY_VBY1EPI_CC_tx17_ndrv_mask                                (0x0000000C)
#define  PINMUX_LVDSPHY_VBY1EPI_CC_tx16_ndrv_mask                                (0x00000003)
#define  PINMUX_LVDSPHY_VBY1EPI_CC_tx23_ndrv(data)                               (0x0000C000&((data)<<14))
#define  PINMUX_LVDSPHY_VBY1EPI_CC_tx22_ndrv(data)                               (0x00003000&((data)<<12))
#define  PINMUX_LVDSPHY_VBY1EPI_CC_tx21_ndrv(data)                               (0x00000C00&((data)<<10))
#define  PINMUX_LVDSPHY_VBY1EPI_CC_tx20_ndrv(data)                               (0x00000300&((data)<<8))
#define  PINMUX_LVDSPHY_VBY1EPI_CC_tx19_ndrv(data)                               (0x000000C0&((data)<<6))
#define  PINMUX_LVDSPHY_VBY1EPI_CC_tx18_ndrv(data)                               (0x00000030&((data)<<4))
#define  PINMUX_LVDSPHY_VBY1EPI_CC_tx17_ndrv(data)                               (0x0000000C&((data)<<2))
#define  PINMUX_LVDSPHY_VBY1EPI_CC_tx16_ndrv(data)                               (0x00000003&(data))
#define  PINMUX_LVDSPHY_VBY1EPI_CC_get_tx23_ndrv(data)                           ((0x0000C000&(data))>>14)
#define  PINMUX_LVDSPHY_VBY1EPI_CC_get_tx22_ndrv(data)                           ((0x00003000&(data))>>12)
#define  PINMUX_LVDSPHY_VBY1EPI_CC_get_tx21_ndrv(data)                           ((0x00000C00&(data))>>10)
#define  PINMUX_LVDSPHY_VBY1EPI_CC_get_tx20_ndrv(data)                           ((0x00000300&(data))>>8)
#define  PINMUX_LVDSPHY_VBY1EPI_CC_get_tx19_ndrv(data)                           ((0x000000C0&(data))>>6)
#define  PINMUX_LVDSPHY_VBY1EPI_CC_get_tx18_ndrv(data)                           ((0x00000030&(data))>>4)
#define  PINMUX_LVDSPHY_VBY1EPI_CC_get_tx17_ndrv(data)                           ((0x0000000C&(data))>>2)
#define  PINMUX_LVDSPHY_VBY1EPI_CC_get_tx16_ndrv(data)                           (0x00000003&(data))

#define  PINMUX_LVDSPHY_VBY1EPI_DC                                               0x18000EDC
#define  PINMUX_LVDSPHY_VBY1EPI_DC_reg_addr                                      "0xB8000EDC"
#define  PINMUX_LVDSPHY_VBY1EPI_DC_reg                                           0xB8000EDC
#define  PINMUX_LVDSPHY_VBY1EPI_DC_inst_addr                                     "0x0051"
#define  set_PINMUX_LVDSPHY_VBY1EPI_DC_reg(data)                                 (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_DC_reg)=data)
#define  get_PINMUX_LVDSPHY_VBY1EPI_DC_reg                                       (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_DC_reg))
#define  PINMUX_LVDSPHY_VBY1EPI_DC_tx7_rt_shift                                  (28)
#define  PINMUX_LVDSPHY_VBY1EPI_DC_tx6_rt_shift                                  (24)
#define  PINMUX_LVDSPHY_VBY1EPI_DC_tx5_rt_shift                                  (20)
#define  PINMUX_LVDSPHY_VBY1EPI_DC_tx4_rt_shift                                  (16)
#define  PINMUX_LVDSPHY_VBY1EPI_DC_tx3_rt_shift                                  (12)
#define  PINMUX_LVDSPHY_VBY1EPI_DC_tx2_rt_shift                                  (8)
#define  PINMUX_LVDSPHY_VBY1EPI_DC_tx1_rt_shift                                  (4)
#define  PINMUX_LVDSPHY_VBY1EPI_DC_tx0_rt_shift                                  (0)
#define  PINMUX_LVDSPHY_VBY1EPI_DC_tx7_rt_mask                                   (0xF0000000)
#define  PINMUX_LVDSPHY_VBY1EPI_DC_tx6_rt_mask                                   (0x0F000000)
#define  PINMUX_LVDSPHY_VBY1EPI_DC_tx5_rt_mask                                   (0x00F00000)
#define  PINMUX_LVDSPHY_VBY1EPI_DC_tx4_rt_mask                                   (0x000F0000)
#define  PINMUX_LVDSPHY_VBY1EPI_DC_tx3_rt_mask                                   (0x0000F000)
#define  PINMUX_LVDSPHY_VBY1EPI_DC_tx2_rt_mask                                   (0x00000F00)
#define  PINMUX_LVDSPHY_VBY1EPI_DC_tx1_rt_mask                                   (0x000000F0)
#define  PINMUX_LVDSPHY_VBY1EPI_DC_tx0_rt_mask                                   (0x0000000F)
#define  PINMUX_LVDSPHY_VBY1EPI_DC_tx7_rt(data)                                  (0xF0000000&((data)<<28))
#define  PINMUX_LVDSPHY_VBY1EPI_DC_tx6_rt(data)                                  (0x0F000000&((data)<<24))
#define  PINMUX_LVDSPHY_VBY1EPI_DC_tx5_rt(data)                                  (0x00F00000&((data)<<20))
#define  PINMUX_LVDSPHY_VBY1EPI_DC_tx4_rt(data)                                  (0x000F0000&((data)<<16))
#define  PINMUX_LVDSPHY_VBY1EPI_DC_tx3_rt(data)                                  (0x0000F000&((data)<<12))
#define  PINMUX_LVDSPHY_VBY1EPI_DC_tx2_rt(data)                                  (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_VBY1EPI_DC_tx1_rt(data)                                  (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_VBY1EPI_DC_tx0_rt(data)                                  (0x0000000F&(data))
#define  PINMUX_LVDSPHY_VBY1EPI_DC_get_tx7_rt(data)                              ((0xF0000000&(data))>>28)
#define  PINMUX_LVDSPHY_VBY1EPI_DC_get_tx6_rt(data)                              ((0x0F000000&(data))>>24)
#define  PINMUX_LVDSPHY_VBY1EPI_DC_get_tx5_rt(data)                              ((0x00F00000&(data))>>20)
#define  PINMUX_LVDSPHY_VBY1EPI_DC_get_tx4_rt(data)                              ((0x000F0000&(data))>>16)
#define  PINMUX_LVDSPHY_VBY1EPI_DC_get_tx3_rt(data)                              ((0x0000F000&(data))>>12)
#define  PINMUX_LVDSPHY_VBY1EPI_DC_get_tx2_rt(data)                              ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_VBY1EPI_DC_get_tx1_rt(data)                              ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_VBY1EPI_DC_get_tx0_rt(data)                              (0x0000000F&(data))

#define  PINMUX_LVDSPHY_VBY1EPI_D8                                               0x18000ED8
#define  PINMUX_LVDSPHY_VBY1EPI_D8_reg_addr                                      "0xB8000ED8"
#define  PINMUX_LVDSPHY_VBY1EPI_D8_reg                                           0xB8000ED8
#define  PINMUX_LVDSPHY_VBY1EPI_D8_inst_addr                                     "0x0052"
#define  set_PINMUX_LVDSPHY_VBY1EPI_D8_reg(data)                                 (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_D8_reg)=data)
#define  get_PINMUX_LVDSPHY_VBY1EPI_D8_reg                                       (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_D8_reg))
#define  PINMUX_LVDSPHY_VBY1EPI_D8_tx15_rt_shift                                 (28)
#define  PINMUX_LVDSPHY_VBY1EPI_D8_tx14_rt_shift                                 (24)
#define  PINMUX_LVDSPHY_VBY1EPI_D8_tx13_rt_shift                                 (20)
#define  PINMUX_LVDSPHY_VBY1EPI_D8_tx12_rt_shift                                 (16)
#define  PINMUX_LVDSPHY_VBY1EPI_D8_tx11_rt_shift                                 (12)
#define  PINMUX_LVDSPHY_VBY1EPI_D8_tx10_rt_shift                                 (8)
#define  PINMUX_LVDSPHY_VBY1EPI_D8_tx9_rt_shift                                  (4)
#define  PINMUX_LVDSPHY_VBY1EPI_D8_tx8_rt_shift                                  (0)
#define  PINMUX_LVDSPHY_VBY1EPI_D8_tx15_rt_mask                                  (0xF0000000)
#define  PINMUX_LVDSPHY_VBY1EPI_D8_tx14_rt_mask                                  (0x0F000000)
#define  PINMUX_LVDSPHY_VBY1EPI_D8_tx13_rt_mask                                  (0x00F00000)
#define  PINMUX_LVDSPHY_VBY1EPI_D8_tx12_rt_mask                                  (0x000F0000)
#define  PINMUX_LVDSPHY_VBY1EPI_D8_tx11_rt_mask                                  (0x0000F000)
#define  PINMUX_LVDSPHY_VBY1EPI_D8_tx10_rt_mask                                  (0x00000F00)
#define  PINMUX_LVDSPHY_VBY1EPI_D8_tx9_rt_mask                                   (0x000000F0)
#define  PINMUX_LVDSPHY_VBY1EPI_D8_tx8_rt_mask                                   (0x0000000F)
#define  PINMUX_LVDSPHY_VBY1EPI_D8_tx15_rt(data)                                 (0xF0000000&((data)<<28))
#define  PINMUX_LVDSPHY_VBY1EPI_D8_tx14_rt(data)                                 (0x0F000000&((data)<<24))
#define  PINMUX_LVDSPHY_VBY1EPI_D8_tx13_rt(data)                                 (0x00F00000&((data)<<20))
#define  PINMUX_LVDSPHY_VBY1EPI_D8_tx12_rt(data)                                 (0x000F0000&((data)<<16))
#define  PINMUX_LVDSPHY_VBY1EPI_D8_tx11_rt(data)                                 (0x0000F000&((data)<<12))
#define  PINMUX_LVDSPHY_VBY1EPI_D8_tx10_rt(data)                                 (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_VBY1EPI_D8_tx9_rt(data)                                  (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_VBY1EPI_D8_tx8_rt(data)                                  (0x0000000F&(data))
#define  PINMUX_LVDSPHY_VBY1EPI_D8_get_tx15_rt(data)                             ((0xF0000000&(data))>>28)
#define  PINMUX_LVDSPHY_VBY1EPI_D8_get_tx14_rt(data)                             ((0x0F000000&(data))>>24)
#define  PINMUX_LVDSPHY_VBY1EPI_D8_get_tx13_rt(data)                             ((0x00F00000&(data))>>20)
#define  PINMUX_LVDSPHY_VBY1EPI_D8_get_tx12_rt(data)                             ((0x000F0000&(data))>>16)
#define  PINMUX_LVDSPHY_VBY1EPI_D8_get_tx11_rt(data)                             ((0x0000F000&(data))>>12)
#define  PINMUX_LVDSPHY_VBY1EPI_D8_get_tx10_rt(data)                             ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_VBY1EPI_D8_get_tx9_rt(data)                              ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_VBY1EPI_D8_get_tx8_rt(data)                              (0x0000000F&(data))

#define  PINMUX_LVDSPHY_VBY1EPI_D4                                               0x18000ED4
#define  PINMUX_LVDSPHY_VBY1EPI_D4_reg_addr                                      "0xB8000ED4"
#define  PINMUX_LVDSPHY_VBY1EPI_D4_reg                                           0xB8000ED4
#define  PINMUX_LVDSPHY_VBY1EPI_D4_inst_addr                                     "0x0053"
#define  set_PINMUX_LVDSPHY_VBY1EPI_D4_reg(data)                                 (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_D4_reg)=data)
#define  get_PINMUX_LVDSPHY_VBY1EPI_D4_reg                                       (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1EPI_D4_reg))
#define  PINMUX_LVDSPHY_VBY1EPI_D4_tx23_rt_shift                                 (28)
#define  PINMUX_LVDSPHY_VBY1EPI_D4_tx22_rt_shift                                 (24)
#define  PINMUX_LVDSPHY_VBY1EPI_D4_tx21_rt_shift                                 (20)
#define  PINMUX_LVDSPHY_VBY1EPI_D4_tx20_rt_shift                                 (16)
#define  PINMUX_LVDSPHY_VBY1EPI_D4_tx19_rt_shift                                 (12)
#define  PINMUX_LVDSPHY_VBY1EPI_D4_tx18_rt_shift                                 (8)
#define  PINMUX_LVDSPHY_VBY1EPI_D4_tx17_rt_shift                                 (4)
#define  PINMUX_LVDSPHY_VBY1EPI_D4_tx16_rt_shift                                 (0)
#define  PINMUX_LVDSPHY_VBY1EPI_D4_tx23_rt_mask                                  (0xF0000000)
#define  PINMUX_LVDSPHY_VBY1EPI_D4_tx22_rt_mask                                  (0x0F000000)
#define  PINMUX_LVDSPHY_VBY1EPI_D4_tx21_rt_mask                                  (0x00F00000)
#define  PINMUX_LVDSPHY_VBY1EPI_D4_tx20_rt_mask                                  (0x000F0000)
#define  PINMUX_LVDSPHY_VBY1EPI_D4_tx19_rt_mask                                  (0x0000F000)
#define  PINMUX_LVDSPHY_VBY1EPI_D4_tx18_rt_mask                                  (0x00000F00)
#define  PINMUX_LVDSPHY_VBY1EPI_D4_tx17_rt_mask                                  (0x000000F0)
#define  PINMUX_LVDSPHY_VBY1EPI_D4_tx16_rt_mask                                  (0x0000000F)
#define  PINMUX_LVDSPHY_VBY1EPI_D4_tx23_rt(data)                                 (0xF0000000&((data)<<28))
#define  PINMUX_LVDSPHY_VBY1EPI_D4_tx22_rt(data)                                 (0x0F000000&((data)<<24))
#define  PINMUX_LVDSPHY_VBY1EPI_D4_tx21_rt(data)                                 (0x00F00000&((data)<<20))
#define  PINMUX_LVDSPHY_VBY1EPI_D4_tx20_rt(data)                                 (0x000F0000&((data)<<16))
#define  PINMUX_LVDSPHY_VBY1EPI_D4_tx19_rt(data)                                 (0x0000F000&((data)<<12))
#define  PINMUX_LVDSPHY_VBY1EPI_D4_tx18_rt(data)                                 (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_VBY1EPI_D4_tx17_rt(data)                                 (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_VBY1EPI_D4_tx16_rt(data)                                 (0x0000000F&(data))
#define  PINMUX_LVDSPHY_VBY1EPI_D4_get_tx23_rt(data)                             ((0xF0000000&(data))>>28)
#define  PINMUX_LVDSPHY_VBY1EPI_D4_get_tx22_rt(data)                             ((0x0F000000&(data))>>24)
#define  PINMUX_LVDSPHY_VBY1EPI_D4_get_tx21_rt(data)                             ((0x00F00000&(data))>>20)
#define  PINMUX_LVDSPHY_VBY1EPI_D4_get_tx20_rt(data)                             ((0x000F0000&(data))>>16)
#define  PINMUX_LVDSPHY_VBY1EPI_D4_get_tx19_rt(data)                             ((0x0000F000&(data))>>12)
#define  PINMUX_LVDSPHY_VBY1EPI_D4_get_tx18_rt(data)                             ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_VBY1EPI_D4_get_tx17_rt(data)                             ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_VBY1EPI_D4_get_tx16_rt(data)                             (0x0000000F&(data))

#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00                                    0x18000EE0
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_reg_addr                           "0xB8000EE0"
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_reg                                0xB8000EE0
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_inst_addr                          "0x0054"
#define  set_PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_reg(data)                      (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_reg)=data)
#define  get_PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_reg                            (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_reg))
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_bist_repeat_shift                  (31)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_bist_tp_sel_shift                  (30)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_delay_sel0_shift                   (27)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_delay_sel1_shift                   (24)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_delay_sel2_shift                   (21)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_delay_sel3_shift                   (18)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_delay_sel4_shift                   (15)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_delay_sel5_shift                   (12)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_delay_sel6_shift                   (9)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_delay_sel7_shift                   (6)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_tp_type_sel_shift                  (5)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_scramble_default_shift             (4)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_txbist_mode_shift                  (2)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_prbs_sel_shift                     (1)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_x1x2_sel_shift                     (0)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_bist_repeat_mask                   (0x80000000)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_bist_tp_sel_mask                   (0x40000000)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_delay_sel0_mask                    (0x38000000)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_delay_sel1_mask                    (0x07000000)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_delay_sel2_mask                    (0x00E00000)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_delay_sel3_mask                    (0x001C0000)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_delay_sel4_mask                    (0x00038000)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_delay_sel5_mask                    (0x00007000)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_delay_sel6_mask                    (0x00000E00)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_delay_sel7_mask                    (0x000001C0)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_tp_type_sel_mask                   (0x00000020)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_scramble_default_mask              (0x00000010)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_txbist_mode_mask                   (0x0000000C)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_prbs_sel_mask                      (0x00000002)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_x1x2_sel_mask                      (0x00000001)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_bist_repeat(data)                  (0x80000000&((data)<<31))
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_bist_tp_sel(data)                  (0x40000000&((data)<<30))
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_delay_sel0(data)                   (0x38000000&((data)<<27))
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_delay_sel1(data)                   (0x07000000&((data)<<24))
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_delay_sel2(data)                   (0x00E00000&((data)<<21))
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_delay_sel3(data)                   (0x001C0000&((data)<<18))
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_delay_sel4(data)                   (0x00038000&((data)<<15))
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_delay_sel5(data)                   (0x00007000&((data)<<12))
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_delay_sel6(data)                   (0x00000E00&((data)<<9))
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_delay_sel7(data)                   (0x000001C0&((data)<<6))
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_tp_type_sel(data)                  (0x00000020&((data)<<5))
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_scramble_default(data)             (0x00000010&((data)<<4))
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_txbist_mode(data)                  (0x0000000C&((data)<<2))
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_prbs_sel(data)                     (0x00000002&((data)<<1))
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_x1x2_sel(data)                     (0x00000001&(data))
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_get_bist_repeat(data)              ((0x80000000&(data))>>31)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_get_bist_tp_sel(data)              ((0x40000000&(data))>>30)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_get_delay_sel0(data)               ((0x38000000&(data))>>27)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_get_delay_sel1(data)               ((0x07000000&(data))>>24)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_get_delay_sel2(data)               ((0x00E00000&(data))>>21)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_get_delay_sel3(data)               ((0x001C0000&(data))>>18)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_get_delay_sel4(data)               ((0x00038000&(data))>>15)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_get_delay_sel5(data)               ((0x00007000&(data))>>12)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_get_delay_sel6(data)               ((0x00000E00&(data))>>9)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_get_delay_sel7(data)               ((0x000001C0&(data))>>6)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_get_tp_type_sel(data)              ((0x00000020&(data))>>5)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_get_scramble_default(data)         ((0x00000010&(data))>>4)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_get_txbist_mode(data)              ((0x0000000C&(data))>>2)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_get_prbs_sel(data)                 ((0x00000002&(data))>>1)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_00_get_x1x2_sel(data)                 (0x00000001&(data))

#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_01                                    0x18000EE4
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_01_reg_addr                           "0xB8000EE4"
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_01_reg                                0xB8000EE4
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_01_inst_addr                          "0x0055"
#define  set_PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_01_reg(data)                      (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_01_reg)=data)
#define  get_PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_01_reg                            (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_01_reg))
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_01_reserved_txbist_01_shift           (28)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_01_enhance_mode_shift                 (27)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_01_prbs_reverse_shift                 (26)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_01_scramble_dis_shift                 (25)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_01_pn_swap_shift                      (24)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_01_bist_seed_shift                    (16)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_01_packet_length_shift                (8)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_01_packet_number_shift                (0)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_01_reserved_txbist_01_mask            (0xF0000000)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_01_enhance_mode_mask                  (0x08000000)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_01_prbs_reverse_mask                  (0x04000000)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_01_scramble_dis_mask                  (0x02000000)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_01_pn_swap_mask                       (0x01000000)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_01_bist_seed_mask                     (0x00FF0000)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_01_packet_length_mask                 (0x0000FF00)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_01_packet_number_mask                 (0x000000FF)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_01_reserved_txbist_01(data)           (0xF0000000&((data)<<28))
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_01_enhance_mode(data)                 (0x08000000&((data)<<27))
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_01_prbs_reverse(data)                 (0x04000000&((data)<<26))
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_01_scramble_dis(data)                 (0x02000000&((data)<<25))
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_01_pn_swap(data)                      (0x01000000&((data)<<24))
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_01_bist_seed(data)                    (0x00FF0000&((data)<<16))
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_01_packet_length(data)                (0x0000FF00&((data)<<8))
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_01_packet_number(data)                (0x000000FF&(data))
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_01_get_reserved_txbist_01(data)       ((0xF0000000&(data))>>28)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_01_get_enhance_mode(data)             ((0x08000000&(data))>>27)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_01_get_prbs_reverse(data)             ((0x04000000&(data))>>26)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_01_get_scramble_dis(data)             ((0x02000000&(data))>>25)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_01_get_pn_swap(data)                  ((0x01000000&(data))>>24)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_01_get_bist_seed(data)                ((0x00FF0000&(data))>>16)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_01_get_packet_length(data)            ((0x0000FF00&(data))>>8)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_01_get_packet_number(data)            (0x000000FF&(data))

#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_02                                    0x18000EE8
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_02_reg_addr                           "0xB8000EE8"
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_02_reg                                0xB8000EE8
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_02_inst_addr                          "0x0056"
#define  set_PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_02_reg(data)                      (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_02_reg)=data)
#define  get_PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_02_reg                            (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_02_reg))
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_02_reserved_txbist_02_shift           (24)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_02_lane_enable_shift                  (16)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_02_debug_sel_shift                    (8)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_02_err_period_shift                   (0)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_02_reserved_txbist_02_mask            (0xFF000000)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_02_lane_enable_mask                   (0x00FF0000)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_02_debug_sel_mask                     (0x0000FF00)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_02_err_period_mask                    (0x000000FF)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_02_reserved_txbist_02(data)           (0xFF000000&((data)<<24))
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_02_lane_enable(data)                  (0x00FF0000&((data)<<16))
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_02_debug_sel(data)                    (0x0000FF00&((data)<<8))
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_02_err_period(data)                   (0x000000FF&(data))
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_02_get_reserved_txbist_02(data)       ((0xFF000000&(data))>>24)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_02_get_lane_enable(data)              ((0x00FF0000&(data))>>16)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_02_get_debug_sel(data)                ((0x0000FF00&(data))>>8)
#define  PINMUX_LVDSPHY_VBY1_D_PHY0_TXBIST_02_get_err_period(data)               (0x000000FF&(data))

#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00                                    0x18000EF0
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_reg_addr                           "0xB8000EF0"
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_reg                                0xB8000EF0
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_inst_addr                          "0x0057"
#define  set_PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_reg(data)                      (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_reg)=data)
#define  get_PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_reg                            (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_reg))
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_bist_repeat_2_shift                (31)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_bist_tp_sel_2_shift                (30)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_delay_sel0_2_shift                 (27)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_delay_sel1_2_shift                 (24)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_delay_sel2_2_shift                 (21)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_delay_sel3_2_shift                 (18)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_delay_sel4_2_shift                 (15)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_delay_sel5_2_shift                 (12)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_delay_sel6_2_shift                 (9)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_delay_sel7_2_shift                 (6)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_tp_type_sel_2_shift                (5)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_scramble_default_2_shift           (4)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_txbist_mode_2_shift                (2)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_prbs_sel_2_shift                   (1)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_x1x2_sel_2_shift                   (0)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_bist_repeat_2_mask                 (0x80000000)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_bist_tp_sel_2_mask                 (0x40000000)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_delay_sel0_2_mask                  (0x38000000)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_delay_sel1_2_mask                  (0x07000000)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_delay_sel2_2_mask                  (0x00E00000)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_delay_sel3_2_mask                  (0x001C0000)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_delay_sel4_2_mask                  (0x00038000)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_delay_sel5_2_mask                  (0x00007000)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_delay_sel6_2_mask                  (0x00000E00)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_delay_sel7_2_mask                  (0x000001C0)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_tp_type_sel_2_mask                 (0x00000020)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_scramble_default_2_mask            (0x00000010)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_txbist_mode_2_mask                 (0x0000000C)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_prbs_sel_2_mask                    (0x00000002)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_x1x2_sel_2_mask                    (0x00000001)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_bist_repeat_2(data)                (0x80000000&((data)<<31))
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_bist_tp_sel_2(data)                (0x40000000&((data)<<30))
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_delay_sel0_2(data)                 (0x38000000&((data)<<27))
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_delay_sel1_2(data)                 (0x07000000&((data)<<24))
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_delay_sel2_2(data)                 (0x00E00000&((data)<<21))
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_delay_sel3_2(data)                 (0x001C0000&((data)<<18))
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_delay_sel4_2(data)                 (0x00038000&((data)<<15))
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_delay_sel5_2(data)                 (0x00007000&((data)<<12))
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_delay_sel6_2(data)                 (0x00000E00&((data)<<9))
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_delay_sel7_2(data)                 (0x000001C0&((data)<<6))
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_tp_type_sel_2(data)                (0x00000020&((data)<<5))
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_scramble_default_2(data)           (0x00000010&((data)<<4))
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_txbist_mode_2(data)                (0x0000000C&((data)<<2))
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_prbs_sel_2(data)                   (0x00000002&((data)<<1))
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_x1x2_sel_2(data)                   (0x00000001&(data))
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_get_bist_repeat_2(data)            ((0x80000000&(data))>>31)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_get_bist_tp_sel_2(data)            ((0x40000000&(data))>>30)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_get_delay_sel0_2(data)             ((0x38000000&(data))>>27)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_get_delay_sel1_2(data)             ((0x07000000&(data))>>24)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_get_delay_sel2_2(data)             ((0x00E00000&(data))>>21)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_get_delay_sel3_2(data)             ((0x001C0000&(data))>>18)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_get_delay_sel4_2(data)             ((0x00038000&(data))>>15)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_get_delay_sel5_2(data)             ((0x00007000&(data))>>12)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_get_delay_sel6_2(data)             ((0x00000E00&(data))>>9)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_get_delay_sel7_2(data)             ((0x000001C0&(data))>>6)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_get_tp_type_sel_2(data)            ((0x00000020&(data))>>5)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_get_scramble_default_2(data)       ((0x00000010&(data))>>4)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_get_txbist_mode_2(data)            ((0x0000000C&(data))>>2)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_get_prbs_sel_2(data)               ((0x00000002&(data))>>1)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_00_get_x1x2_sel_2(data)               (0x00000001&(data))

#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_01                                    0x18000EF4
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_01_reg_addr                           "0xB8000EF4"
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_01_reg                                0xB8000EF4
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_01_inst_addr                          "0x0058"
#define  set_PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_01_reg(data)                      (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_01_reg)=data)
#define  get_PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_01_reg                            (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_01_reg))
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_01_reserved_txbist_01_2_shift         (28)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_01_enhance_mode_2_shift               (27)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_01_prbs_reverse_2_shift               (26)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_01_scramble_dis_2_shift               (25)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_01_pn_swap_2_shift                    (24)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_01_bist_seed_2_shift                  (16)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_01_packet_length_2_shift              (8)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_01_packet_number_2_shift              (0)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_01_reserved_txbist_01_2_mask          (0xF0000000)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_01_enhance_mode_2_mask                (0x08000000)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_01_prbs_reverse_2_mask                (0x04000000)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_01_scramble_dis_2_mask                (0x02000000)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_01_pn_swap_2_mask                     (0x01000000)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_01_bist_seed_2_mask                   (0x00FF0000)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_01_packet_length_2_mask               (0x0000FF00)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_01_packet_number_2_mask               (0x000000FF)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_01_reserved_txbist_01_2(data)         (0xF0000000&((data)<<28))
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_01_enhance_mode_2(data)               (0x08000000&((data)<<27))
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_01_prbs_reverse_2(data)               (0x04000000&((data)<<26))
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_01_scramble_dis_2(data)               (0x02000000&((data)<<25))
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_01_pn_swap_2(data)                    (0x01000000&((data)<<24))
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_01_bist_seed_2(data)                  (0x00FF0000&((data)<<16))
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_01_packet_length_2(data)              (0x0000FF00&((data)<<8))
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_01_packet_number_2(data)              (0x000000FF&(data))
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_01_get_reserved_txbist_01_2(data)     ((0xF0000000&(data))>>28)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_01_get_enhance_mode_2(data)           ((0x08000000&(data))>>27)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_01_get_prbs_reverse_2(data)           ((0x04000000&(data))>>26)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_01_get_scramble_dis_2(data)           ((0x02000000&(data))>>25)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_01_get_pn_swap_2(data)                ((0x01000000&(data))>>24)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_01_get_bist_seed_2(data)              ((0x00FF0000&(data))>>16)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_01_get_packet_length_2(data)          ((0x0000FF00&(data))>>8)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_01_get_packet_number_2(data)          (0x000000FF&(data))

#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_02                                    0x18000EF8
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_02_reg_addr                           "0xB8000EF8"
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_02_reg                                0xB8000EF8
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_02_inst_addr                          "0x0059"
#define  set_PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_02_reg(data)                      (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_02_reg)=data)
#define  get_PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_02_reg                            (*((volatile unsigned int*)PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_02_reg))
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_02_reserved_txbist_02_2_shift         (24)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_02_lane_enable_2_shift                (16)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_02_debug_sel_2_shift                  (8)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_02_err_period_2_shift                 (0)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_02_reserved_txbist_02_2_mask          (0xFF000000)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_02_lane_enable_2_mask                 (0x00FF0000)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_02_debug_sel_2_mask                   (0x0000FF00)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_02_err_period_2_mask                  (0x000000FF)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_02_reserved_txbist_02_2(data)         (0xFF000000&((data)<<24))
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_02_lane_enable_2(data)                (0x00FF0000&((data)<<16))
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_02_debug_sel_2(data)                  (0x0000FF00&((data)<<8))
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_02_err_period_2(data)                 (0x000000FF&(data))
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_02_get_reserved_txbist_02_2(data)     ((0xFF000000&(data))>>24)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_02_get_lane_enable_2(data)            ((0x00FF0000&(data))>>16)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_02_get_debug_sel_2(data)              ((0x0000FF00&(data))>>8)
#define  PINMUX_LVDSPHY_VBY1_D_PHY1_TXBIST_02_get_err_period_2(data)             (0x000000FF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======PINMUX_LVDSPHY register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p0_txgp_ps:4;
        RBus_UInt32  plt_p0_txgn_ps:4;
        RBus_UInt32  plt_p0_txfp_ps:4;
        RBus_UInt32  plt_p0_txfn_ps:4;
        RBus_UInt32  plt_p0_txep_ps:4;
        RBus_UInt32  plt_p0_txen_ps:4;
        RBus_UInt32  plt_p0_txdp_ps:4;
        RBus_UInt32  plt_p0_txdn_ps:4;
    };
}pinmux_lvdsphy_lvds_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p3_txdp_ps:4;
        RBus_UInt32  plt_p3_txdn_ps:4;
        RBus_UInt32  plt_p3_txcp_ps:4;
        RBus_UInt32  plt_p3_txcn_ps:4;
        RBus_UInt32  plt_p3_txbp_ps:4;
        RBus_UInt32  plt_p3_txbn_ps:4;
        RBus_UInt32  plt_p3_txap_ps:4;
        RBus_UInt32  plt_p3_txan_ps:4;
    };
}pinmux_lvdsphy_lvds_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p0_txcp_ps:4;
        RBus_UInt32  plt_p0_txcn_ps:4;
        RBus_UInt32  plt_p0_txbp_ps:4;
        RBus_UInt32  plt_p0_txbn_ps:4;
        RBus_UInt32  plt_p3_txep_ps:4;
        RBus_UInt32  plt_p3_txen_ps:4;
        RBus_UInt32  res1:8;
    };
}pinmux_lvdsphy_lvds_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p0_txlap_mode:3;
        RBus_UInt32  plt_p0_txlan_mode:3;
        RBus_UInt32  plt_p0_txla_ckphs:2;
        RBus_UInt32  plt_p0_txla_sel_emp:3;
        RBus_UInt32  plt_p0_txla_sr:2;
        RBus_UInt32  plt_p0_txla_term:2;
        RBus_UInt32  res1:10;
        RBus_UInt32  plt_p0_txl_epicml:7;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p0_txlbp_mode:3;
        RBus_UInt32  plt_p0_txlbn_mode:3;
        RBus_UInt32  plt_p0_txlb_ckphs:2;
        RBus_UInt32  plt_p0_txlb_sel_emp:3;
        RBus_UInt32  plt_p0_txlb_sr:2;
        RBus_UInt32  plt_p0_txlb_term:2;
        RBus_UInt32  res1:17;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p0_txlcp_mode:3;
        RBus_UInt32  plt_p0_txlcn_mode:3;
        RBus_UInt32  plt_p0_txlc_ckphs:2;
        RBus_UInt32  plt_p0_txlc_sel_emp:3;
        RBus_UInt32  plt_p0_txlc_sr:2;
        RBus_UInt32  plt_p0_txlc_term:2;
        RBus_UInt32  res1:17;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p0_txldp_mode:3;
        RBus_UInt32  plt_p0_txldn_mode:3;
        RBus_UInt32  plt_p0_txld_ckphs:2;
        RBus_UInt32  plt_p0_txld_sel_emp:3;
        RBus_UInt32  plt_p0_txld_sr:2;
        RBus_UInt32  plt_p0_txld_term:2;
        RBus_UInt32  res1:17;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p0_txlep_mode:3;
        RBus_UInt32  plt_p0_txlen_mode:3;
        RBus_UInt32  plt_p0_txle_ckphs:2;
        RBus_UInt32  plt_p0_txle_sel_emp:3;
        RBus_UInt32  plt_p0_txle_sr:2;
        RBus_UInt32  plt_p0_txle_term:2;
        RBus_UInt32  res1:17;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p0_txlfp_mode:3;
        RBus_UInt32  plt_p0_txlfn_mode:3;
        RBus_UInt32  plt_p0_txlf_ckphs:2;
        RBus_UInt32  plt_p0_txlf_sel_emp:3;
        RBus_UInt32  plt_p0_txlf_sr:2;
        RBus_UInt32  plt_p0_txlf_term:2;
        RBus_UInt32  res1:17;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  plt_p0_txl_ck1x_delay:2;
        RBus_UInt32  res2:6;
        RBus_UInt32  plt_p0_txl_cml_str:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  plt_p0_txl_en_emp:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  plt_p0_txl_en_term:7;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p0_txl_ck7x_delay:2;
        RBus_UInt32  plt_p0_txl_ck7x_inv:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  plt_p0_txl_cm_mode:1;
        RBus_UInt32  plt_p0_txl_ib2x:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  plt_p0_txl_ck7x_lag:7;
        RBus_UInt32  res3:12;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p1_txl_ck7x_delay:2;
        RBus_UInt32  plt_p1_txl_ck7x_inv:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  plt_p1_txl_cm_mode:1;
        RBus_UInt32  plt_p1_txl_ib2x:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  plt_p1_txl_ck7x_lag:7;
        RBus_UInt32  res3:12;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p1_txlap_mode:3;
        RBus_UInt32  plt_p1_txlan_mode:3;
        RBus_UInt32  plt_p1_txla_ckphs:2;
        RBus_UInt32  plt_p1_txla_sel_emp:3;
        RBus_UInt32  plt_p1_txla_sr:2;
        RBus_UInt32  plt_p1_txla_term:2;
        RBus_UInt32  res1:10;
        RBus_UInt32  plt_p1_txl_epicml:7;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p1_txlbp_mode:3;
        RBus_UInt32  plt_p1_txlbn_mode:3;
        RBus_UInt32  plt_p1_txlb_ckphs:2;
        RBus_UInt32  plt_p1_txlb_sel_emp:3;
        RBus_UInt32  plt_p1_txlb_sr:2;
        RBus_UInt32  plt_p1_txlb_term:2;
        RBus_UInt32  res1:17;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p1_txlcp_mode:3;
        RBus_UInt32  plt_p1_txlcn_mode:3;
        RBus_UInt32  plt_p1_txlc_ckphs:2;
        RBus_UInt32  plt_p1_txlc_sel_emp:3;
        RBus_UInt32  plt_p1_txlc_sr:2;
        RBus_UInt32  plt_p1_txlc_term:2;
        RBus_UInt32  res1:17;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p1_txldp_mode:3;
        RBus_UInt32  plt_p1_txldn_mode:3;
        RBus_UInt32  plt_p1_txld_ckphs:2;
        RBus_UInt32  plt_p1_txld_sel_emp:3;
        RBus_UInt32  plt_p1_txld_sr:2;
        RBus_UInt32  plt_p1_txld_term:2;
        RBus_UInt32  res1:17;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p1_txlep_mode:3;
        RBus_UInt32  plt_p1_txlen_mode:3;
        RBus_UInt32  plt_p1_txle_ckphs:2;
        RBus_UInt32  plt_p1_txle_sel_emp:3;
        RBus_UInt32  plt_p1_txle_sr:2;
        RBus_UInt32  plt_p1_txle_term:2;
        RBus_UInt32  res1:17;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p1_txlfp_mode:3;
        RBus_UInt32  plt_p1_txlfn_mode:3;
        RBus_UInt32  plt_p1_txlf_ckphs:2;
        RBus_UInt32  plt_p1_txlf_sel_emp:3;
        RBus_UInt32  plt_p1_txlf_sr:2;
        RBus_UInt32  plt_p1_txlf_term:2;
        RBus_UInt32  res1:17;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p2_txlap_mode:3;
        RBus_UInt32  plt_p2_txlan_mode:3;
        RBus_UInt32  plt_p2_txla_ckphs:2;
        RBus_UInt32  plt_p2_txla_sel_emp:3;
        RBus_UInt32  plt_p2_txla_sr:2;
        RBus_UInt32  plt_p2_txla_term:2;
        RBus_UInt32  res1:10;
        RBus_UInt32  plt_p2_txl_epicml:7;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p2_txlbp_mode:3;
        RBus_UInt32  plt_p2_txlbn_mode:3;
        RBus_UInt32  plt_p2_txlb_ckphs:2;
        RBus_UInt32  plt_p2_txlb_sel_emp:3;
        RBus_UInt32  plt_p2_txlb_sr:2;
        RBus_UInt32  plt_p2_txlb_term:2;
        RBus_UInt32  res1:17;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p2_txlcp_mode:3;
        RBus_UInt32  plt_p2_txlcn_mode:3;
        RBus_UInt32  plt_p2_txlc_ckphs:2;
        RBus_UInt32  plt_p2_txlc_sel_emp:3;
        RBus_UInt32  plt_p2_txlc_sr:2;
        RBus_UInt32  plt_p2_txlc_term:2;
        RBus_UInt32  res1:17;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p2_txldp_mode:3;
        RBus_UInt32  plt_p2_txldn_mode:3;
        RBus_UInt32  plt_p2_txld_ckphs:2;
        RBus_UInt32  plt_p2_txld_sel_emp:3;
        RBus_UInt32  plt_p2_txld_sr:2;
        RBus_UInt32  plt_p2_txld_term:2;
        RBus_UInt32  res1:17;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p2_txlep_mode:3;
        RBus_UInt32  plt_p2_txlen_mode:3;
        RBus_UInt32  plt_p2_txle_ckphs:2;
        RBus_UInt32  plt_p2_txle_sel_emp:3;
        RBus_UInt32  plt_p2_txle_sr:2;
        RBus_UInt32  plt_p2_txle_term:2;
        RBus_UInt32  res1:17;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p2_txlfp_mode:3;
        RBus_UInt32  plt_p2_txlfn_mode:3;
        RBus_UInt32  plt_p2_txlf_ckphs:2;
        RBus_UInt32  plt_p2_txlf_sel_emp:3;
        RBus_UInt32  plt_p2_txlf_sr:2;
        RBus_UInt32  plt_p2_txlf_term:2;
        RBus_UInt32  res1:17;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p3_txlap_mode:3;
        RBus_UInt32  plt_p3_txlan_mode:3;
        RBus_UInt32  plt_p3_txla_ckphs:2;
        RBus_UInt32  plt_p3_txla_sel_emp:3;
        RBus_UInt32  plt_p3_txla_sr:2;
        RBus_UInt32  plt_p3_txla_term:2;
        RBus_UInt32  res1:10;
        RBus_UInt32  plt_p3_txl_epicml:7;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p3_txlbp_mode:3;
        RBus_UInt32  plt_p3_txlbn_mode:3;
        RBus_UInt32  plt_p3_txlb_ckphs:2;
        RBus_UInt32  plt_p3_txlb_sel_emp:3;
        RBus_UInt32  plt_p3_txlb_sr:2;
        RBus_UInt32  plt_p3_txlb_term:2;
        RBus_UInt32  res1:17;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p3_txlcp_mode:3;
        RBus_UInt32  plt_p3_txlcn_mode:3;
        RBus_UInt32  plt_p3_txlc_ckphs:2;
        RBus_UInt32  plt_p3_txlc_sel_emp:3;
        RBus_UInt32  plt_p3_txlc_sr:2;
        RBus_UInt32  plt_p3_txlc_term:2;
        RBus_UInt32  res1:17;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p3_txldp_mode:3;
        RBus_UInt32  plt_p3_txldn_mode:3;
        RBus_UInt32  plt_p3_txld_ckphs:2;
        RBus_UInt32  plt_p3_txld_sel_emp:3;
        RBus_UInt32  plt_p3_txld_sr:2;
        RBus_UInt32  plt_p3_txld_term:2;
        RBus_UInt32  res1:17;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p3_txlep_mode:3;
        RBus_UInt32  plt_p3_txlen_mode:3;
        RBus_UInt32  plt_p3_txle_ckphs:2;
        RBus_UInt32  plt_p3_txle_sel_emp:3;
        RBus_UInt32  plt_p3_txle_sr:2;
        RBus_UInt32  plt_p3_txle_term:2;
        RBus_UInt32  res1:17;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p3_txlfp_mode:3;
        RBus_UInt32  plt_p3_txlfn_mode:3;
        RBus_UInt32  plt_p3_txlf_ckphs:2;
        RBus_UInt32  plt_p3_txlf_sel_emp:3;
        RBus_UInt32  plt_p3_txlf_sr:2;
        RBus_UInt32  plt_p3_txlf_term:2;
        RBus_UInt32  res1:17;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  plt_p1_txl_ck1x_delay:2;
        RBus_UInt32  res2:6;
        RBus_UInt32  plt_p1_txl_cml_str:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  plt_p1_txl_en_emp:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  plt_p1_txl_en_term:7;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  plt_p2_txl_ck1x_delay:2;
        RBus_UInt32  res2:6;
        RBus_UInt32  plt_p2_txl_cml_str:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  plt_p2_txl_en_emp:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  plt_p2_txl_en_term:7;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  plt_p3_txl_ck1x_delay:2;
        RBus_UInt32  res2:6;
        RBus_UInt32  plt_p3_txl_cml_str:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  plt_p3_txl_en_emp:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  plt_p3_txl_en_term:7;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p2_txl_ck7x_delay:2;
        RBus_UInt32  plt_p2_txl_ck7x_inv:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  plt_p2_txl_cm_mode:1;
        RBus_UInt32  plt_p2_txl_ib2x:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  plt_p2_txl_ck7x_lag:7;
        RBus_UInt32  res3:12;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p3_txl_ck7x_delay:2;
        RBus_UInt32  plt_p3_txl_ck7x_inv:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  plt_p3_txl_cm_mode:1;
        RBus_UInt32  plt_p3_txl_ib2x:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  plt_p3_txl_ck7x_lag:7;
        RBus_UInt32  res3:12;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmu_y_bpsdivm:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  plt_p0_txlgn_mode:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  plt_p0_txlgp_mode:3;
        RBus_UInt32  plt_p0_txlg_ckphs:2;
        RBus_UInt32  plt_p0_txlg_sel_emp:3;
        RBus_UInt32  plt_p0_txlg_sr:2;
        RBus_UInt32  plt_p0_txlg_term:2;
        RBus_UInt32  plt_p1_txlgn_mode:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  plt_p1_txlgp_mode:3;
        RBus_UInt32  plt_p1_txlg_ckphs:2;
        RBus_UInt32  plt_p1_txlg_sel_emp:3;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_2_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_y_a1_pi_phsel:12;
        RBus_UInt32  plt_y_a1_sel_2xi:1;
        RBus_UInt32  plt_y_a2_pi_phsel:12;
        RBus_UInt32  plt_y_a2_sel_2xi:1;
        RBus_UInt32  plt_y_a_pi_freq:2;
        RBus_UInt32  res1:3;
        RBus_UInt32  plt_y_sel_v25:1;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_y_ab_pi_phsel:12;
        RBus_UInt32  plt_y_ab_freq:2;
        RBus_UInt32  plt_y_ab_sel_2xi:1;
        RBus_UInt32  res1:17;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_y_b1_pi_phsel:12;
        RBus_UInt32  plt_y_b1_sel_2xi:1;
        RBus_UInt32  plt_y_b2_pi_phsel:12;
        RBus_UInt32  plt_y_b2_sel_2xi:1;
        RBus_UInt32  plt_y_b_pi_freq:2;
        RBus_UInt32  res1:4;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_y_cmu_big_kvco:1;
        RBus_UInt32  plt_y_cmu_ckpixel_inv:1;
        RBus_UInt32  plt_y_cmu_ck_ref_inv:1;
        RBus_UInt32  plt_y_cmu_div248:3;
        RBus_UInt32  plt_y_cmu_loop_divp:6;
        RBus_UInt32  res1:1;
        RBus_UInt32  plt_y_cmu_sel_cp_i:3;
        RBus_UInt32  plt_y_cmu_sel_sc1:3;
        RBus_UInt32  plt_y_cmu_sel_sc2:1;
        RBus_UInt32  plt_y_cmu_sel_sr:3;
        RBus_UInt32  plt_y_cmu_sel_vldo:2;
        RBus_UInt32  plt_y_en_test:1;
        RBus_UInt32  plt_y_cmu_a_pi_bypass:1;
        RBus_UInt32  plt_y_cmu_b_pi_bypass:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  plt_y_cmu_wdrst:1;
        RBus_UInt32  plt_y_cmu_wdset:1;
        RBus_UInt32  cmu_y_wdo:1;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_y_sel_isource:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  plt_y_sel_test:2;
        RBus_UInt32  plt_y_sel_txl_vldo:2;
        RBus_UInt32  plt_y_sel_tx_i:4;
        RBus_UInt32  plt_y_sel_vcm:5;
        RBus_UInt32  res2:1;
        RBus_UInt32  plt_y_en_lv_ldo:1;
        RBus_UInt32  plt_y_en_txl_ldo:1;
        RBus_UInt32  plt_y_sel_lv_vldo:3;
        RBus_UInt32  res3:11;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_x_ab_pi_phsel:12;
        RBus_UInt32  plt_x_ab_freq:2;
        RBus_UInt32  plt_x_ab_sel_2xi:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  cmu_x_bpsdivm:1;
        RBus_UInt32  res2:11;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_x_a1_pi_phsel:12;
        RBus_UInt32  plt_x_a1_sel_2xi:1;
        RBus_UInt32  plt_x_a2_pi_phsel:12;
        RBus_UInt32  plt_x_a2_sel_2xi:1;
        RBus_UInt32  plt_x_a_pi_freq:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  plt_sbg:2;
        RBus_UInt32  plt_x_sel_v25:1;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_x_b1_pi_phsel:12;
        RBus_UInt32  plt_x_b1_sel_2xi:1;
        RBus_UInt32  plt_x_b2_pi_phsel:12;
        RBus_UInt32  plt_x_b2_sel_2xi:1;
        RBus_UInt32  plt_x_b_pi_freq:2;
        RBus_UInt32  res1:4;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_x_cmu_big_kvco:1;
        RBus_UInt32  plt_x_cmu_ckpixel_inv:1;
        RBus_UInt32  plt_x_cmu_ck_ref_inv:1;
        RBus_UInt32  plt_x_cmu_div248:3;
        RBus_UInt32  plt_x_cmu_loop_divp:6;
        RBus_UInt32  res1:1;
        RBus_UInt32  plt_x_cmu_sel_cp_i:3;
        RBus_UInt32  plt_x_cmu_sel_sc1:3;
        RBus_UInt32  plt_x_cmu_sel_sc2:1;
        RBus_UInt32  plt_x_cmu_sel_sr:3;
        RBus_UInt32  plt_x_cmu_sel_vldo:2;
        RBus_UInt32  plt_x_en_test:1;
        RBus_UInt32  plt_x_cmu_a_pi_bypass:1;
        RBus_UInt32  plt_x_cmu_b_pi_bypass:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  plt_x_cmu_wdrst:1;
        RBus_UInt32  plt_x_cmu_wdset:1;
        RBus_UInt32  cmu_x_wdo:1;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_x_sel_isource:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  plt_x_sel_test:2;
        RBus_UInt32  plt_x_sel_txl_vldo:2;
        RBus_UInt32  plt_x_sel_tx_i:4;
        RBus_UInt32  plt_x_sel_vcm:5;
        RBus_UInt32  res2:1;
        RBus_UInt32  plt_x_en_lv_ldo:1;
        RBus_UInt32  plt_x_en_txl_ldo:1;
        RBus_UInt32  plt_x_sel_lv_vldo:3;
        RBus_UInt32  res3:11;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p1_txlg_sr:2;
        RBus_UInt32  plt_p1_txlg_term:2;
        RBus_UInt32  plt_p2_txlgn_mode:3;
        RBus_UInt32  plt_p2_txlgp_mode:3;
        RBus_UInt32  plt_p2_txlg_ckphs:2;
        RBus_UInt32  plt_p2_txlg_sel_emp:3;
        RBus_UInt32  plt_p2_txlg_sr:2;
        RBus_UInt32  plt_p2_txlg_term:2;
        RBus_UInt32  plt_p3_txlgn_mode:3;
        RBus_UInt32  plt_p3_txlgp_mode:3;
        RBus_UInt32  plt_p3_txlg_ckphs:2;
        RBus_UInt32  plt_p3_txlg_sel_emp:3;
        RBus_UInt32  plt_p3_txlg_sr:2;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p3_txlg_term:2;
        RBus_UInt32  plt_c_sel_lv_vldo:2;
        RBus_UInt32  res1:28;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  plt_p0_txl_pre_drv:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  plt_p0_txl_sr_td:7;
        RBus_UInt32  res3:16;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  plt_p1_dummy_lvds:28;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  plt_p1_txl_pre_drv:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  plt_p1_txl_sr_td:7;
        RBus_UInt32  res3:16;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  plt_p2_txl_pre_drv:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  plt_p2_txl_sr_td:7;
        RBus_UInt32  res3:16;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  plt_p3_txl_pre_drv:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  plt_p3_txl_sr_td:7;
        RBus_UInt32  res3:16;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  plt_p2_dummy_lvds:28;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  plt_p0_dummy_lvds:28;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  plt_p3_dummy_lvds:28;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pow_plt_x:1;
        RBus_UInt32  pow_plt_p0_txl:7;
        RBus_UInt32  pow_plt_y:1;
        RBus_UInt32  pow_plt_p1_txl:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  pow_plt_p2_txl:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  pow_plt_p3_txl:7;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_dummy:16;
        RBus_UInt32  plt_p3_ttl_str:1;
        RBus_UInt32  plt_p2_ttl_str:1;
        RBus_UInt32  plt_p1_ttl_str:1;
        RBus_UInt32  plt_p0_ttl_str:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  txpll_prediv_bypass:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  txpll_ckin_div_n:6;
    };
}pinmux_lvdsphy_txpll_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  pow_vby1_bg:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  pow_vby1_top:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  vby1_bg_sel:2;
        RBus_UInt32  vby1_bg_isel:4;
        RBus_UInt32  res4:3;
        RBus_UInt32  ldo_cptest_en:1;
        RBus_UInt32  res5:2;
        RBus_UInt32  ldo_cptest_sel:2;
        RBus_UInt32  res6:8;
    };
}pinmux_lvdsphy_vby1epi_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  txpll_ldo1v_pow:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  txpll_ldolv_sel:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  txpll_ldov18_sel:2;
        RBus_UInt32  res4:3;
        RBus_UInt32  txpll_mode:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  txpll_macpll_divm:3;
        RBus_UInt32  res6:2;
        RBus_UInt32  txpll_prescalerdiv:2;
        RBus_UInt32  res7:3;
        RBus_UInt32  txpll_pow:1;
    };
}pinmux_lvdsphy_vby1epi_b0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  vby1_txpll_prediv_bypass:1;
        RBus_UInt32  res2:7;
        RBus_UInt32  macpll_cko_inv:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  ck1xp_inv:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  ck20xp_inv:1;
        RBus_UInt32  res5:2;
        RBus_UInt32  txpll_epi_div_sel:2;
        RBus_UInt32  res6:1;
        RBus_UInt32  txpll_scan_postdivp:3;
        RBus_UInt32  res7:4;
    };
}pinmux_lvdsphy_vby1epi_c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  txpll_ckinepi_inv:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  txpll_ckin_sel:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  txpll_cp:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  txpll_cs:2;
        RBus_UInt32  txpll_ip:4;
        RBus_UInt32  res5:3;
        RBus_UInt32  txpll_scan_mode:1;
        RBus_UInt32  res6:2;
        RBus_UInt32  vby1_txpll_ckin_div_n:6;
    };
}pinmux_lvdsphy_vby1epi_c0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  txpll_reserve:4;
        RBus_UInt32  res1:7;
        RBus_UInt32  txpll_vcogain:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  txpll_wdrst:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  txpll_wdset:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  txpll_rs:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  txpll_tst_div:3;
        RBus_UInt32  res6:3;
        RBus_UInt32  txmacpll_bpsdivm:1;
    };
}pinmux_lvdsphy_vby1epi_b8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tx_rten_lane:24;
    };
}pinmux_lvdsphy_vby1epi_a0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tx_rpen_lane:24;
    };
}pinmux_lvdsphy_vby1epi_98_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tx_pow_lane:24;
    };
}pinmux_lvdsphy_vby1epi_90_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tx_emph_lane:24;
    };
}pinmux_lvdsphy_vby1epi_88_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  txlane0003_biasmode:4;
        RBus_UInt32  txlane0407_biasmode:4;
        RBus_UInt32  txlane0811_biasmode:4;
        RBus_UInt32  txlane1215_biasmode:4;
        RBus_UInt32  txlane1619_biasmode:4;
        RBus_UInt32  txlane2023_biasmode:4;
        RBus_UInt32  res1:8;
    };
}pinmux_lvdsphy_vby1epi_a8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx0_rp:2;
        RBus_UInt32  tx1_rp:2;
        RBus_UInt32  tx2_rp:2;
        RBus_UInt32  tx3_rp:2;
        RBus_UInt32  tx4_rp:2;
        RBus_UInt32  tx5_rp:2;
        RBus_UInt32  tx6_rp:2;
        RBus_UInt32  tx7_rp:2;
        RBus_UInt32  tx8_rp:2;
        RBus_UInt32  tx9_rp:2;
        RBus_UInt32  tx10_rp:2;
        RBus_UInt32  tx11_rp:2;
        RBus_UInt32  tx12_rp:2;
        RBus_UInt32  tx13_rp:2;
        RBus_UInt32  tx14_rp:2;
        RBus_UInt32  tx15_rp:2;
    };
}pinmux_lvdsphy_vby1epi_60_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx16_rp:2;
        RBus_UInt32  tx17_rp:2;
        RBus_UInt32  tx18_rp:2;
        RBus_UInt32  tx19_rp:2;
        RBus_UInt32  tx20_rp:2;
        RBus_UInt32  tx21_rp:2;
        RBus_UInt32  tx22_rp:2;
        RBus_UInt32  tx23_rp:2;
        RBus_UInt32  res1:16;
    };
}pinmux_lvdsphy_vby1epi_68_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx8_iem:4;
        RBus_UInt32  tx9_iem:4;
        RBus_UInt32  tx10_iem:4;
        RBus_UInt32  tx11_iem:4;
        RBus_UInt32  tx12_iem:4;
        RBus_UInt32  tx13_iem:4;
        RBus_UInt32  tx14_iem:4;
        RBus_UInt32  tx15_iem:4;
    };
}pinmux_lvdsphy_vby1epi_40_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx0_iem:4;
        RBus_UInt32  tx1_iem:4;
        RBus_UInt32  tx2_iem:4;
        RBus_UInt32  tx3_iem:4;
        RBus_UInt32  tx4_iem:4;
        RBus_UInt32  tx5_iem:4;
        RBus_UInt32  tx6_iem:4;
        RBus_UInt32  tx7_iem:4;
    };
}pinmux_lvdsphy_vby1epi_38_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx16_iem:4;
        RBus_UInt32  tx17_iem:4;
        RBus_UInt32  tx18_iem:4;
        RBus_UInt32  tx19_iem:4;
        RBus_UInt32  tx20_iem:4;
        RBus_UInt32  tx21_iem:4;
        RBus_UInt32  tx22_iem:4;
        RBus_UInt32  tx23_iem:4;
    };
}pinmux_lvdsphy_vby1epi_48_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx0_idrv:4;
        RBus_UInt32  tx1_idrv:4;
        RBus_UInt32  tx2_idrv:4;
        RBus_UInt32  tx3_idrv:4;
        RBus_UInt32  tx4_idrv:4;
        RBus_UInt32  tx5_idrv:4;
        RBus_UInt32  tx6_idrv:4;
        RBus_UInt32  tx7_idrv:4;
    };
}pinmux_lvdsphy_vby1epi_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx8_idrv:4;
        RBus_UInt32  tx9_idrv:4;
        RBus_UInt32  tx10_idrv:4;
        RBus_UInt32  tx11_idrv:4;
        RBus_UInt32  tx12_idrv:4;
        RBus_UInt32  tx13_idrv:4;
        RBus_UInt32  tx14_idrv:4;
        RBus_UInt32  tx15_idrv:4;
    };
}pinmux_lvdsphy_vby1epi_28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx16_idrv:4;
        RBus_UInt32  tx17_idrv:4;
        RBus_UInt32  tx18_idrv:4;
        RBus_UInt32  tx19_idrv:4;
        RBus_UInt32  tx20_idrv:4;
        RBus_UInt32  tx21_idrv:4;
        RBus_UInt32  tx22_idrv:4;
        RBus_UInt32  tx23_idrv:4;
    };
}pinmux_lvdsphy_vby1epi_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx16_dummy:4;
        RBus_UInt32  tx17_dummy:4;
        RBus_UInt32  tx18_dummy:4;
        RBus_UInt32  tx19_dummy:4;
        RBus_UInt32  tx20_dummy:4;
        RBus_UInt32  tx21_dummy:4;
        RBus_UInt32  tx22_dummy:4;
        RBus_UInt32  tx23_dummy:4;
    };
}pinmux_lvdsphy_vby1epi_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx8_dummy:4;
        RBus_UInt32  tx9_dummy:4;
        RBus_UInt32  tx10_dummy:4;
        RBus_UInt32  tx11_dummy:4;
        RBus_UInt32  tx12_dummy:4;
        RBus_UInt32  tx13_dummy:4;
        RBus_UInt32  tx14_dummy:4;
        RBus_UInt32  tx15_dummy:4;
    };
}pinmux_lvdsphy_vby1epi_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx0_dummy:4;
        RBus_UInt32  tx1_dummy:4;
        RBus_UInt32  tx2_dummy:4;
        RBus_UInt32  tx3_dummy:4;
        RBus_UInt32  tx4_dummy:4;
        RBus_UInt32  tx5_dummy:4;
        RBus_UInt32  tx6_dummy:4;
        RBus_UInt32  tx7_dummy:4;
    };
}pinmux_lvdsphy_vby1epi_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx15_ndrv:2;
        RBus_UInt32  tx14_ndrv:2;
        RBus_UInt32  tx13_ndrv:2;
        RBus_UInt32  tx12_ndrv:2;
        RBus_UInt32  tx11_ndrv:2;
        RBus_UInt32  tx10_ndrv:2;
        RBus_UInt32  tx9_ndrv:2;
        RBus_UInt32  tx8_ndrv:2;
        RBus_UInt32  tx7_ndrv:2;
        RBus_UInt32  tx6_ndrv:2;
        RBus_UInt32  tx5_ndrv:2;
        RBus_UInt32  tx4_ndrv:2;
        RBus_UInt32  tx3_ndrv:2;
        RBus_UInt32  tx2_ndrv:2;
        RBus_UInt32  tx1_ndrv:2;
        RBus_UInt32  tx0_ndrv:2;
    };
}pinmux_lvdsphy_vby1epi_d0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  tx23_ndrv:2;
        RBus_UInt32  tx22_ndrv:2;
        RBus_UInt32  tx21_ndrv:2;
        RBus_UInt32  tx20_ndrv:2;
        RBus_UInt32  tx19_ndrv:2;
        RBus_UInt32  tx18_ndrv:2;
        RBus_UInt32  tx17_ndrv:2;
        RBus_UInt32  tx16_ndrv:2;
    };
}pinmux_lvdsphy_vby1epi_cc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx7_rt:4;
        RBus_UInt32  tx6_rt:4;
        RBus_UInt32  tx5_rt:4;
        RBus_UInt32  tx4_rt:4;
        RBus_UInt32  tx3_rt:4;
        RBus_UInt32  tx2_rt:4;
        RBus_UInt32  tx1_rt:4;
        RBus_UInt32  tx0_rt:4;
    };
}pinmux_lvdsphy_vby1epi_dc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx15_rt:4;
        RBus_UInt32  tx14_rt:4;
        RBus_UInt32  tx13_rt:4;
        RBus_UInt32  tx12_rt:4;
        RBus_UInt32  tx11_rt:4;
        RBus_UInt32  tx10_rt:4;
        RBus_UInt32  tx9_rt:4;
        RBus_UInt32  tx8_rt:4;
    };
}pinmux_lvdsphy_vby1epi_d8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx23_rt:4;
        RBus_UInt32  tx22_rt:4;
        RBus_UInt32  tx21_rt:4;
        RBus_UInt32  tx20_rt:4;
        RBus_UInt32  tx19_rt:4;
        RBus_UInt32  tx18_rt:4;
        RBus_UInt32  tx17_rt:4;
        RBus_UInt32  tx16_rt:4;
    };
}pinmux_lvdsphy_vby1epi_d4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_repeat:1;
        RBus_UInt32  bist_tp_sel:1;
        RBus_UInt32  delay_sel0:3;
        RBus_UInt32  delay_sel1:3;
        RBus_UInt32  delay_sel2:3;
        RBus_UInt32  delay_sel3:3;
        RBus_UInt32  delay_sel4:3;
        RBus_UInt32  delay_sel5:3;
        RBus_UInt32  delay_sel6:3;
        RBus_UInt32  delay_sel7:3;
        RBus_UInt32  tp_type_sel:1;
        RBus_UInt32  scramble_default:1;
        RBus_UInt32  txbist_mode:2;
        RBus_UInt32  prbs_sel:1;
        RBus_UInt32  x1x2_sel:1;
    };
}pinmux_lvdsphy_vby1_d_phy0_txbist_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reserved_txbist_01:4;
        RBus_UInt32  enhance_mode:1;
        RBus_UInt32  prbs_reverse:1;
        RBus_UInt32  scramble_dis:1;
        RBus_UInt32  pn_swap:1;
        RBus_UInt32  bist_seed:8;
        RBus_UInt32  packet_length:8;
        RBus_UInt32  packet_number:8;
    };
}pinmux_lvdsphy_vby1_d_phy0_txbist_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reserved_txbist_02:8;
        RBus_UInt32  lane_enable:8;
        RBus_UInt32  debug_sel:8;
        RBus_UInt32  err_period:8;
    };
}pinmux_lvdsphy_vby1_d_phy0_txbist_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_repeat_2:1;
        RBus_UInt32  bist_tp_sel_2:1;
        RBus_UInt32  delay_sel0_2:3;
        RBus_UInt32  delay_sel1_2:3;
        RBus_UInt32  delay_sel2_2:3;
        RBus_UInt32  delay_sel3_2:3;
        RBus_UInt32  delay_sel4_2:3;
        RBus_UInt32  delay_sel5_2:3;
        RBus_UInt32  delay_sel6_2:3;
        RBus_UInt32  delay_sel7_2:3;
        RBus_UInt32  tp_type_sel_2:1;
        RBus_UInt32  scramble_default_2:1;
        RBus_UInt32  txbist_mode_2:2;
        RBus_UInt32  prbs_sel_2:1;
        RBus_UInt32  x1x2_sel_2:1;
    };
}pinmux_lvdsphy_vby1_d_phy1_txbist_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reserved_txbist_01_2:4;
        RBus_UInt32  enhance_mode_2:1;
        RBus_UInt32  prbs_reverse_2:1;
        RBus_UInt32  scramble_dis_2:1;
        RBus_UInt32  pn_swap_2:1;
        RBus_UInt32  bist_seed_2:8;
        RBus_UInt32  packet_length_2:8;
        RBus_UInt32  packet_number_2:8;
    };
}pinmux_lvdsphy_vby1_d_phy1_txbist_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reserved_txbist_02_2:8;
        RBus_UInt32  lane_enable_2:8;
        RBus_UInt32  debug_sel_2:8;
        RBus_UInt32  err_period_2:8;
    };
}pinmux_lvdsphy_vby1_d_phy1_txbist_02_RBUS;

#else //apply LITTLE_ENDIAN

//======PINMUX_LVDSPHY register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p0_txdn_ps:4;
        RBus_UInt32  plt_p0_txdp_ps:4;
        RBus_UInt32  plt_p0_txen_ps:4;
        RBus_UInt32  plt_p0_txep_ps:4;
        RBus_UInt32  plt_p0_txfn_ps:4;
        RBus_UInt32  plt_p0_txfp_ps:4;
        RBus_UInt32  plt_p0_txgn_ps:4;
        RBus_UInt32  plt_p0_txgp_ps:4;
    };
}pinmux_lvdsphy_lvds_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p3_txan_ps:4;
        RBus_UInt32  plt_p3_txap_ps:4;
        RBus_UInt32  plt_p3_txbn_ps:4;
        RBus_UInt32  plt_p3_txbp_ps:4;
        RBus_UInt32  plt_p3_txcn_ps:4;
        RBus_UInt32  plt_p3_txcp_ps:4;
        RBus_UInt32  plt_p3_txdn_ps:4;
        RBus_UInt32  plt_p3_txdp_ps:4;
    };
}pinmux_lvdsphy_lvds_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  plt_p3_txen_ps:4;
        RBus_UInt32  plt_p3_txep_ps:4;
        RBus_UInt32  plt_p0_txbn_ps:4;
        RBus_UInt32  plt_p0_txbp_ps:4;
        RBus_UInt32  plt_p0_txcn_ps:4;
        RBus_UInt32  plt_p0_txcp_ps:4;
    };
}pinmux_lvdsphy_lvds_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p0_txl_epicml:7;
        RBus_UInt32  res1:10;
        RBus_UInt32  plt_p0_txla_term:2;
        RBus_UInt32  plt_p0_txla_sr:2;
        RBus_UInt32  plt_p0_txla_sel_emp:3;
        RBus_UInt32  plt_p0_txla_ckphs:2;
        RBus_UInt32  plt_p0_txlan_mode:3;
        RBus_UInt32  plt_p0_txlap_mode:3;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  plt_p0_txlb_term:2;
        RBus_UInt32  plt_p0_txlb_sr:2;
        RBus_UInt32  plt_p0_txlb_sel_emp:3;
        RBus_UInt32  plt_p0_txlb_ckphs:2;
        RBus_UInt32  plt_p0_txlbn_mode:3;
        RBus_UInt32  plt_p0_txlbp_mode:3;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  plt_p0_txlc_term:2;
        RBus_UInt32  plt_p0_txlc_sr:2;
        RBus_UInt32  plt_p0_txlc_sel_emp:3;
        RBus_UInt32  plt_p0_txlc_ckphs:2;
        RBus_UInt32  plt_p0_txlcn_mode:3;
        RBus_UInt32  plt_p0_txlcp_mode:3;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  plt_p0_txld_term:2;
        RBus_UInt32  plt_p0_txld_sr:2;
        RBus_UInt32  plt_p0_txld_sel_emp:3;
        RBus_UInt32  plt_p0_txld_ckphs:2;
        RBus_UInt32  plt_p0_txldn_mode:3;
        RBus_UInt32  plt_p0_txldp_mode:3;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  plt_p0_txle_term:2;
        RBus_UInt32  plt_p0_txle_sr:2;
        RBus_UInt32  plt_p0_txle_sel_emp:3;
        RBus_UInt32  plt_p0_txle_ckphs:2;
        RBus_UInt32  plt_p0_txlen_mode:3;
        RBus_UInt32  plt_p0_txlep_mode:3;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  plt_p0_txlf_term:2;
        RBus_UInt32  plt_p0_txlf_sr:2;
        RBus_UInt32  plt_p0_txlf_sel_emp:3;
        RBus_UInt32  plt_p0_txlf_ckphs:2;
        RBus_UInt32  plt_p0_txlfn_mode:3;
        RBus_UInt32  plt_p0_txlfp_mode:3;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p0_txl_en_term:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  plt_p0_txl_en_emp:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  plt_p0_txl_cml_str:7;
        RBus_UInt32  res3:6;
        RBus_UInt32  plt_p0_txl_ck1x_delay:2;
        RBus_UInt32  res4:1;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  plt_p0_txl_ck7x_lag:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  plt_p0_txl_ib2x:7;
        RBus_UInt32  plt_p0_txl_cm_mode:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  plt_p0_txl_ck7x_inv:1;
        RBus_UInt32  plt_p0_txl_ck7x_delay:2;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  plt_p1_txl_ck7x_lag:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  plt_p1_txl_ib2x:7;
        RBus_UInt32  plt_p1_txl_cm_mode:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  plt_p1_txl_ck7x_inv:1;
        RBus_UInt32  plt_p1_txl_ck7x_delay:2;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p1_txl_epicml:7;
        RBus_UInt32  res1:10;
        RBus_UInt32  plt_p1_txla_term:2;
        RBus_UInt32  plt_p1_txla_sr:2;
        RBus_UInt32  plt_p1_txla_sel_emp:3;
        RBus_UInt32  plt_p1_txla_ckphs:2;
        RBus_UInt32  plt_p1_txlan_mode:3;
        RBus_UInt32  plt_p1_txlap_mode:3;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  plt_p1_txlb_term:2;
        RBus_UInt32  plt_p1_txlb_sr:2;
        RBus_UInt32  plt_p1_txlb_sel_emp:3;
        RBus_UInt32  plt_p1_txlb_ckphs:2;
        RBus_UInt32  plt_p1_txlbn_mode:3;
        RBus_UInt32  plt_p1_txlbp_mode:3;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  plt_p1_txlc_term:2;
        RBus_UInt32  plt_p1_txlc_sr:2;
        RBus_UInt32  plt_p1_txlc_sel_emp:3;
        RBus_UInt32  plt_p1_txlc_ckphs:2;
        RBus_UInt32  plt_p1_txlcn_mode:3;
        RBus_UInt32  plt_p1_txlcp_mode:3;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  plt_p1_txld_term:2;
        RBus_UInt32  plt_p1_txld_sr:2;
        RBus_UInt32  plt_p1_txld_sel_emp:3;
        RBus_UInt32  plt_p1_txld_ckphs:2;
        RBus_UInt32  plt_p1_txldn_mode:3;
        RBus_UInt32  plt_p1_txldp_mode:3;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  plt_p1_txle_term:2;
        RBus_UInt32  plt_p1_txle_sr:2;
        RBus_UInt32  plt_p1_txle_sel_emp:3;
        RBus_UInt32  plt_p1_txle_ckphs:2;
        RBus_UInt32  plt_p1_txlen_mode:3;
        RBus_UInt32  plt_p1_txlep_mode:3;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  plt_p1_txlf_term:2;
        RBus_UInt32  plt_p1_txlf_sr:2;
        RBus_UInt32  plt_p1_txlf_sel_emp:3;
        RBus_UInt32  plt_p1_txlf_ckphs:2;
        RBus_UInt32  plt_p1_txlfn_mode:3;
        RBus_UInt32  plt_p1_txlfp_mode:3;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p2_txl_epicml:7;
        RBus_UInt32  res1:10;
        RBus_UInt32  plt_p2_txla_term:2;
        RBus_UInt32  plt_p2_txla_sr:2;
        RBus_UInt32  plt_p2_txla_sel_emp:3;
        RBus_UInt32  plt_p2_txla_ckphs:2;
        RBus_UInt32  plt_p2_txlan_mode:3;
        RBus_UInt32  plt_p2_txlap_mode:3;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  plt_p2_txlb_term:2;
        RBus_UInt32  plt_p2_txlb_sr:2;
        RBus_UInt32  plt_p2_txlb_sel_emp:3;
        RBus_UInt32  plt_p2_txlb_ckphs:2;
        RBus_UInt32  plt_p2_txlbn_mode:3;
        RBus_UInt32  plt_p2_txlbp_mode:3;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  plt_p2_txlc_term:2;
        RBus_UInt32  plt_p2_txlc_sr:2;
        RBus_UInt32  plt_p2_txlc_sel_emp:3;
        RBus_UInt32  plt_p2_txlc_ckphs:2;
        RBus_UInt32  plt_p2_txlcn_mode:3;
        RBus_UInt32  plt_p2_txlcp_mode:3;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  plt_p2_txld_term:2;
        RBus_UInt32  plt_p2_txld_sr:2;
        RBus_UInt32  plt_p2_txld_sel_emp:3;
        RBus_UInt32  plt_p2_txld_ckphs:2;
        RBus_UInt32  plt_p2_txldn_mode:3;
        RBus_UInt32  plt_p2_txldp_mode:3;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  plt_p2_txle_term:2;
        RBus_UInt32  plt_p2_txle_sr:2;
        RBus_UInt32  plt_p2_txle_sel_emp:3;
        RBus_UInt32  plt_p2_txle_ckphs:2;
        RBus_UInt32  plt_p2_txlen_mode:3;
        RBus_UInt32  plt_p2_txlep_mode:3;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  plt_p2_txlf_term:2;
        RBus_UInt32  plt_p2_txlf_sr:2;
        RBus_UInt32  plt_p2_txlf_sel_emp:3;
        RBus_UInt32  plt_p2_txlf_ckphs:2;
        RBus_UInt32  plt_p2_txlfn_mode:3;
        RBus_UInt32  plt_p2_txlfp_mode:3;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p3_txl_epicml:7;
        RBus_UInt32  res1:10;
        RBus_UInt32  plt_p3_txla_term:2;
        RBus_UInt32  plt_p3_txla_sr:2;
        RBus_UInt32  plt_p3_txla_sel_emp:3;
        RBus_UInt32  plt_p3_txla_ckphs:2;
        RBus_UInt32  plt_p3_txlan_mode:3;
        RBus_UInt32  plt_p3_txlap_mode:3;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  plt_p3_txlb_term:2;
        RBus_UInt32  plt_p3_txlb_sr:2;
        RBus_UInt32  plt_p3_txlb_sel_emp:3;
        RBus_UInt32  plt_p3_txlb_ckphs:2;
        RBus_UInt32  plt_p3_txlbn_mode:3;
        RBus_UInt32  plt_p3_txlbp_mode:3;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  plt_p3_txlc_term:2;
        RBus_UInt32  plt_p3_txlc_sr:2;
        RBus_UInt32  plt_p3_txlc_sel_emp:3;
        RBus_UInt32  plt_p3_txlc_ckphs:2;
        RBus_UInt32  plt_p3_txlcn_mode:3;
        RBus_UInt32  plt_p3_txlcp_mode:3;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  plt_p3_txld_term:2;
        RBus_UInt32  plt_p3_txld_sr:2;
        RBus_UInt32  plt_p3_txld_sel_emp:3;
        RBus_UInt32  plt_p3_txld_ckphs:2;
        RBus_UInt32  plt_p3_txldn_mode:3;
        RBus_UInt32  plt_p3_txldp_mode:3;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  plt_p3_txle_term:2;
        RBus_UInt32  plt_p3_txle_sr:2;
        RBus_UInt32  plt_p3_txle_sel_emp:3;
        RBus_UInt32  plt_p3_txle_ckphs:2;
        RBus_UInt32  plt_p3_txlen_mode:3;
        RBus_UInt32  plt_p3_txlep_mode:3;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  plt_p3_txlf_term:2;
        RBus_UInt32  plt_p3_txlf_sr:2;
        RBus_UInt32  plt_p3_txlf_sel_emp:3;
        RBus_UInt32  plt_p3_txlf_ckphs:2;
        RBus_UInt32  plt_p3_txlfn_mode:3;
        RBus_UInt32  plt_p3_txlfp_mode:3;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p1_txl_en_term:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  plt_p1_txl_en_emp:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  plt_p1_txl_cml_str:7;
        RBus_UInt32  res3:6;
        RBus_UInt32  plt_p1_txl_ck1x_delay:2;
        RBus_UInt32  res4:1;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p2_txl_en_term:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  plt_p2_txl_en_emp:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  plt_p2_txl_cml_str:7;
        RBus_UInt32  res3:6;
        RBus_UInt32  plt_p2_txl_ck1x_delay:2;
        RBus_UInt32  res4:1;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p3_txl_en_term:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  plt_p3_txl_en_emp:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  plt_p3_txl_cml_str:7;
        RBus_UInt32  res3:6;
        RBus_UInt32  plt_p3_txl_ck1x_delay:2;
        RBus_UInt32  res4:1;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  plt_p2_txl_ck7x_lag:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  plt_p2_txl_ib2x:7;
        RBus_UInt32  plt_p2_txl_cm_mode:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  plt_p2_txl_ck7x_inv:1;
        RBus_UInt32  plt_p2_txl_ck7x_delay:2;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  plt_p3_txl_ck7x_lag:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  plt_p3_txl_ib2x:7;
        RBus_UInt32  plt_p3_txl_cm_mode:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  plt_p3_txl_ck7x_inv:1;
        RBus_UInt32  plt_p3_txl_ck7x_delay:2;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p1_txlg_sel_emp:3;
        RBus_UInt32  plt_p1_txlg_ckphs:2;
        RBus_UInt32  plt_p1_txlgp_mode:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  plt_p1_txlgn_mode:3;
        RBus_UInt32  plt_p0_txlg_term:2;
        RBus_UInt32  plt_p0_txlg_sr:2;
        RBus_UInt32  plt_p0_txlg_sel_emp:3;
        RBus_UInt32  plt_p0_txlg_ckphs:2;
        RBus_UInt32  plt_p0_txlgp_mode:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  plt_p0_txlgn_mode:3;
        RBus_UInt32  res3:3;
        RBus_UInt32  cmu_y_bpsdivm:1;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_2_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_y_sel_v25:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  plt_y_a_pi_freq:2;
        RBus_UInt32  plt_y_a2_sel_2xi:1;
        RBus_UInt32  plt_y_a2_pi_phsel:12;
        RBus_UInt32  plt_y_a1_sel_2xi:1;
        RBus_UInt32  plt_y_a1_pi_phsel:12;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  plt_y_ab_sel_2xi:1;
        RBus_UInt32  plt_y_ab_freq:2;
        RBus_UInt32  plt_y_ab_pi_phsel:12;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  plt_y_b_pi_freq:2;
        RBus_UInt32  plt_y_b2_sel_2xi:1;
        RBus_UInt32  plt_y_b2_pi_phsel:12;
        RBus_UInt32  plt_y_b1_sel_2xi:1;
        RBus_UInt32  plt_y_b1_pi_phsel:12;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmu_y_wdo:1;
        RBus_UInt32  plt_y_cmu_wdset:1;
        RBus_UInt32  plt_y_cmu_wdrst:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  plt_y_cmu_b_pi_bypass:1;
        RBus_UInt32  plt_y_cmu_a_pi_bypass:1;
        RBus_UInt32  plt_y_en_test:1;
        RBus_UInt32  plt_y_cmu_sel_vldo:2;
        RBus_UInt32  plt_y_cmu_sel_sr:3;
        RBus_UInt32  plt_y_cmu_sel_sc2:1;
        RBus_UInt32  plt_y_cmu_sel_sc1:3;
        RBus_UInt32  plt_y_cmu_sel_cp_i:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  plt_y_cmu_loop_divp:6;
        RBus_UInt32  plt_y_cmu_div248:3;
        RBus_UInt32  plt_y_cmu_ck_ref_inv:1;
        RBus_UInt32  plt_y_cmu_ckpixel_inv:1;
        RBus_UInt32  plt_y_cmu_big_kvco:1;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  plt_y_sel_lv_vldo:3;
        RBus_UInt32  plt_y_en_txl_ldo:1;
        RBus_UInt32  plt_y_en_lv_ldo:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  plt_y_sel_vcm:5;
        RBus_UInt32  plt_y_sel_tx_i:4;
        RBus_UInt32  plt_y_sel_txl_vldo:2;
        RBus_UInt32  plt_y_sel_test:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  plt_y_sel_isource:1;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  cmu_x_bpsdivm:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  plt_x_ab_sel_2xi:1;
        RBus_UInt32  plt_x_ab_freq:2;
        RBus_UInt32  plt_x_ab_pi_phsel:12;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_x_sel_v25:1;
        RBus_UInt32  plt_sbg:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  plt_x_a_pi_freq:2;
        RBus_UInt32  plt_x_a2_sel_2xi:1;
        RBus_UInt32  plt_x_a2_pi_phsel:12;
        RBus_UInt32  plt_x_a1_sel_2xi:1;
        RBus_UInt32  plt_x_a1_pi_phsel:12;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  plt_x_b_pi_freq:2;
        RBus_UInt32  plt_x_b2_sel_2xi:1;
        RBus_UInt32  plt_x_b2_pi_phsel:12;
        RBus_UInt32  plt_x_b1_sel_2xi:1;
        RBus_UInt32  plt_x_b1_pi_phsel:12;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmu_x_wdo:1;
        RBus_UInt32  plt_x_cmu_wdset:1;
        RBus_UInt32  plt_x_cmu_wdrst:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  plt_x_cmu_b_pi_bypass:1;
        RBus_UInt32  plt_x_cmu_a_pi_bypass:1;
        RBus_UInt32  plt_x_en_test:1;
        RBus_UInt32  plt_x_cmu_sel_vldo:2;
        RBus_UInt32  plt_x_cmu_sel_sr:3;
        RBus_UInt32  plt_x_cmu_sel_sc2:1;
        RBus_UInt32  plt_x_cmu_sel_sc1:3;
        RBus_UInt32  plt_x_cmu_sel_cp_i:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  plt_x_cmu_loop_divp:6;
        RBus_UInt32  plt_x_cmu_div248:3;
        RBus_UInt32  plt_x_cmu_ck_ref_inv:1;
        RBus_UInt32  plt_x_cmu_ckpixel_inv:1;
        RBus_UInt32  plt_x_cmu_big_kvco:1;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  plt_x_sel_lv_vldo:3;
        RBus_UInt32  plt_x_en_txl_ldo:1;
        RBus_UInt32  plt_x_en_lv_ldo:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  plt_x_sel_vcm:5;
        RBus_UInt32  plt_x_sel_tx_i:4;
        RBus_UInt32  plt_x_sel_txl_vldo:2;
        RBus_UInt32  plt_x_sel_test:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  plt_x_sel_isource:1;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p3_txlg_sr:2;
        RBus_UInt32  plt_p3_txlg_sel_emp:3;
        RBus_UInt32  plt_p3_txlg_ckphs:2;
        RBus_UInt32  plt_p3_txlgp_mode:3;
        RBus_UInt32  plt_p3_txlgn_mode:3;
        RBus_UInt32  plt_p2_txlg_term:2;
        RBus_UInt32  plt_p2_txlg_sr:2;
        RBus_UInt32  plt_p2_txlg_sel_emp:3;
        RBus_UInt32  plt_p2_txlg_ckphs:2;
        RBus_UInt32  plt_p2_txlgp_mode:3;
        RBus_UInt32  plt_p2_txlgn_mode:3;
        RBus_UInt32  plt_p1_txlg_term:2;
        RBus_UInt32  plt_p1_txlg_sr:2;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  plt_c_sel_lv_vldo:2;
        RBus_UInt32  plt_p3_txlg_term:2;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  plt_p0_txl_sr_td:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  plt_p0_txl_pre_drv:7;
        RBus_UInt32  res3:1;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p1_dummy_lvds:28;
        RBus_UInt32  res1:4;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  plt_p1_txl_sr_td:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  plt_p1_txl_pre_drv:7;
        RBus_UInt32  res3:1;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  plt_p2_txl_sr_td:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  plt_p2_txl_pre_drv:7;
        RBus_UInt32  res3:1;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  plt_p3_txl_sr_td:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  plt_p3_txl_pre_drv:7;
        RBus_UInt32  res3:1;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p2_dummy_lvds:28;
        RBus_UInt32  res1:4;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p0_dummy_lvds:28;
        RBus_UInt32  res1:4;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p3_dummy_lvds:28;
        RBus_UInt32  res1:4;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_1_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pow_plt_p3_txl:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  pow_plt_p2_txl:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  pow_plt_p1_txl:7;
        RBus_UInt32  pow_plt_y:1;
        RBus_UInt32  pow_plt_p0_txl:7;
        RBus_UInt32  pow_plt_x:1;
    };
}pinmux_lvdsphy_lvdsepi_phy_ctrl_0_27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  txpll_ckin_div_n:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  txpll_prediv_bypass:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  plt_p0_ttl_str:1;
        RBus_UInt32  plt_p1_ttl_str:1;
        RBus_UInt32  plt_p2_ttl_str:1;
        RBus_UInt32  plt_p3_ttl_str:1;
        RBus_UInt32  lvds_dummy:16;
    };
}pinmux_lvdsphy_txpll_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ldo_cptest_sel:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  ldo_cptest_en:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  vby1_bg_isel:4;
        RBus_UInt32  vby1_bg_sel:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  pow_vby1_top:1;
        RBus_UInt32  res5:3;
        RBus_UInt32  pow_vby1_bg:1;
        RBus_UInt32  res6:3;
    };
}pinmux_lvdsphy_vby1epi_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  txpll_pow:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  txpll_prescalerdiv:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  txpll_macpll_divm:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  txpll_mode:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  txpll_ldov18_sel:2;
        RBus_UInt32  res5:2;
        RBus_UInt32  txpll_ldolv_sel:2;
        RBus_UInt32  res6:2;
        RBus_UInt32  txpll_ldo1v_pow:1;
        RBus_UInt32  res7:7;
    };
}pinmux_lvdsphy_vby1epi_b0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  txpll_scan_postdivp:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  txpll_epi_div_sel:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  ck20xp_inv:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  ck1xp_inv:1;
        RBus_UInt32  res5:3;
        RBus_UInt32  macpll_cko_inv:1;
        RBus_UInt32  res6:7;
        RBus_UInt32  vby1_txpll_prediv_bypass:1;
        RBus_UInt32  res7:3;
    };
}pinmux_lvdsphy_vby1epi_c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vby1_txpll_ckin_div_n:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  txpll_scan_mode:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  txpll_ip:4;
        RBus_UInt32  txpll_cs:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  txpll_cp:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  txpll_ckin_sel:1;
        RBus_UInt32  res5:3;
        RBus_UInt32  txpll_ckinepi_inv:1;
        RBus_UInt32  res6:3;
    };
}pinmux_lvdsphy_vby1epi_c0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  txmacpll_bpsdivm:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  txpll_tst_div:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  txpll_rs:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  txpll_wdset:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  txpll_wdrst:1;
        RBus_UInt32  res5:3;
        RBus_UInt32  txpll_vcogain:1;
        RBus_UInt32  res6:7;
        RBus_UInt32  txpll_reserve:4;
    };
}pinmux_lvdsphy_vby1epi_b8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx_rten_lane:24;
        RBus_UInt32  res1:8;
    };
}pinmux_lvdsphy_vby1epi_a0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx_rpen_lane:24;
        RBus_UInt32  res1:8;
    };
}pinmux_lvdsphy_vby1epi_98_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx_pow_lane:24;
        RBus_UInt32  res1:8;
    };
}pinmux_lvdsphy_vby1epi_90_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx_emph_lane:24;
        RBus_UInt32  res1:8;
    };
}pinmux_lvdsphy_vby1epi_88_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  txlane2023_biasmode:4;
        RBus_UInt32  txlane1619_biasmode:4;
        RBus_UInt32  txlane1215_biasmode:4;
        RBus_UInt32  txlane0811_biasmode:4;
        RBus_UInt32  txlane0407_biasmode:4;
        RBus_UInt32  txlane0003_biasmode:4;
    };
}pinmux_lvdsphy_vby1epi_a8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx15_rp:2;
        RBus_UInt32  tx14_rp:2;
        RBus_UInt32  tx13_rp:2;
        RBus_UInt32  tx12_rp:2;
        RBus_UInt32  tx11_rp:2;
        RBus_UInt32  tx10_rp:2;
        RBus_UInt32  tx9_rp:2;
        RBus_UInt32  tx8_rp:2;
        RBus_UInt32  tx7_rp:2;
        RBus_UInt32  tx6_rp:2;
        RBus_UInt32  tx5_rp:2;
        RBus_UInt32  tx4_rp:2;
        RBus_UInt32  tx3_rp:2;
        RBus_UInt32  tx2_rp:2;
        RBus_UInt32  tx1_rp:2;
        RBus_UInt32  tx0_rp:2;
    };
}pinmux_lvdsphy_vby1epi_60_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  tx23_rp:2;
        RBus_UInt32  tx22_rp:2;
        RBus_UInt32  tx21_rp:2;
        RBus_UInt32  tx20_rp:2;
        RBus_UInt32  tx19_rp:2;
        RBus_UInt32  tx18_rp:2;
        RBus_UInt32  tx17_rp:2;
        RBus_UInt32  tx16_rp:2;
    };
}pinmux_lvdsphy_vby1epi_68_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx15_iem:4;
        RBus_UInt32  tx14_iem:4;
        RBus_UInt32  tx13_iem:4;
        RBus_UInt32  tx12_iem:4;
        RBus_UInt32  tx11_iem:4;
        RBus_UInt32  tx10_iem:4;
        RBus_UInt32  tx9_iem:4;
        RBus_UInt32  tx8_iem:4;
    };
}pinmux_lvdsphy_vby1epi_40_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx7_iem:4;
        RBus_UInt32  tx6_iem:4;
        RBus_UInt32  tx5_iem:4;
        RBus_UInt32  tx4_iem:4;
        RBus_UInt32  tx3_iem:4;
        RBus_UInt32  tx2_iem:4;
        RBus_UInt32  tx1_iem:4;
        RBus_UInt32  tx0_iem:4;
    };
}pinmux_lvdsphy_vby1epi_38_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx23_iem:4;
        RBus_UInt32  tx22_iem:4;
        RBus_UInt32  tx21_iem:4;
        RBus_UInt32  tx20_iem:4;
        RBus_UInt32  tx19_iem:4;
        RBus_UInt32  tx18_iem:4;
        RBus_UInt32  tx17_iem:4;
        RBus_UInt32  tx16_iem:4;
    };
}pinmux_lvdsphy_vby1epi_48_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx7_idrv:4;
        RBus_UInt32  tx6_idrv:4;
        RBus_UInt32  tx5_idrv:4;
        RBus_UInt32  tx4_idrv:4;
        RBus_UInt32  tx3_idrv:4;
        RBus_UInt32  tx2_idrv:4;
        RBus_UInt32  tx1_idrv:4;
        RBus_UInt32  tx0_idrv:4;
    };
}pinmux_lvdsphy_vby1epi_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx15_idrv:4;
        RBus_UInt32  tx14_idrv:4;
        RBus_UInt32  tx13_idrv:4;
        RBus_UInt32  tx12_idrv:4;
        RBus_UInt32  tx11_idrv:4;
        RBus_UInt32  tx10_idrv:4;
        RBus_UInt32  tx9_idrv:4;
        RBus_UInt32  tx8_idrv:4;
    };
}pinmux_lvdsphy_vby1epi_28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx23_idrv:4;
        RBus_UInt32  tx22_idrv:4;
        RBus_UInt32  tx21_idrv:4;
        RBus_UInt32  tx20_idrv:4;
        RBus_UInt32  tx19_idrv:4;
        RBus_UInt32  tx18_idrv:4;
        RBus_UInt32  tx17_idrv:4;
        RBus_UInt32  tx16_idrv:4;
    };
}pinmux_lvdsphy_vby1epi_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx23_dummy:4;
        RBus_UInt32  tx22_dummy:4;
        RBus_UInt32  tx21_dummy:4;
        RBus_UInt32  tx20_dummy:4;
        RBus_UInt32  tx19_dummy:4;
        RBus_UInt32  tx18_dummy:4;
        RBus_UInt32  tx17_dummy:4;
        RBus_UInt32  tx16_dummy:4;
    };
}pinmux_lvdsphy_vby1epi_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx15_dummy:4;
        RBus_UInt32  tx14_dummy:4;
        RBus_UInt32  tx13_dummy:4;
        RBus_UInt32  tx12_dummy:4;
        RBus_UInt32  tx11_dummy:4;
        RBus_UInt32  tx10_dummy:4;
        RBus_UInt32  tx9_dummy:4;
        RBus_UInt32  tx8_dummy:4;
    };
}pinmux_lvdsphy_vby1epi_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx7_dummy:4;
        RBus_UInt32  tx6_dummy:4;
        RBus_UInt32  tx5_dummy:4;
        RBus_UInt32  tx4_dummy:4;
        RBus_UInt32  tx3_dummy:4;
        RBus_UInt32  tx2_dummy:4;
        RBus_UInt32  tx1_dummy:4;
        RBus_UInt32  tx0_dummy:4;
    };
}pinmux_lvdsphy_vby1epi_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx0_ndrv:2;
        RBus_UInt32  tx1_ndrv:2;
        RBus_UInt32  tx2_ndrv:2;
        RBus_UInt32  tx3_ndrv:2;
        RBus_UInt32  tx4_ndrv:2;
        RBus_UInt32  tx5_ndrv:2;
        RBus_UInt32  tx6_ndrv:2;
        RBus_UInt32  tx7_ndrv:2;
        RBus_UInt32  tx8_ndrv:2;
        RBus_UInt32  tx9_ndrv:2;
        RBus_UInt32  tx10_ndrv:2;
        RBus_UInt32  tx11_ndrv:2;
        RBus_UInt32  tx12_ndrv:2;
        RBus_UInt32  tx13_ndrv:2;
        RBus_UInt32  tx14_ndrv:2;
        RBus_UInt32  tx15_ndrv:2;
    };
}pinmux_lvdsphy_vby1epi_d0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx16_ndrv:2;
        RBus_UInt32  tx17_ndrv:2;
        RBus_UInt32  tx18_ndrv:2;
        RBus_UInt32  tx19_ndrv:2;
        RBus_UInt32  tx20_ndrv:2;
        RBus_UInt32  tx21_ndrv:2;
        RBus_UInt32  tx22_ndrv:2;
        RBus_UInt32  tx23_ndrv:2;
        RBus_UInt32  res1:16;
    };
}pinmux_lvdsphy_vby1epi_cc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx0_rt:4;
        RBus_UInt32  tx1_rt:4;
        RBus_UInt32  tx2_rt:4;
        RBus_UInt32  tx3_rt:4;
        RBus_UInt32  tx4_rt:4;
        RBus_UInt32  tx5_rt:4;
        RBus_UInt32  tx6_rt:4;
        RBus_UInt32  tx7_rt:4;
    };
}pinmux_lvdsphy_vby1epi_dc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx8_rt:4;
        RBus_UInt32  tx9_rt:4;
        RBus_UInt32  tx10_rt:4;
        RBus_UInt32  tx11_rt:4;
        RBus_UInt32  tx12_rt:4;
        RBus_UInt32  tx13_rt:4;
        RBus_UInt32  tx14_rt:4;
        RBus_UInt32  tx15_rt:4;
    };
}pinmux_lvdsphy_vby1epi_d8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx16_rt:4;
        RBus_UInt32  tx17_rt:4;
        RBus_UInt32  tx18_rt:4;
        RBus_UInt32  tx19_rt:4;
        RBus_UInt32  tx20_rt:4;
        RBus_UInt32  tx21_rt:4;
        RBus_UInt32  tx22_rt:4;
        RBus_UInt32  tx23_rt:4;
    };
}pinmux_lvdsphy_vby1epi_d4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  x1x2_sel:1;
        RBus_UInt32  prbs_sel:1;
        RBus_UInt32  txbist_mode:2;
        RBus_UInt32  scramble_default:1;
        RBus_UInt32  tp_type_sel:1;
        RBus_UInt32  delay_sel7:3;
        RBus_UInt32  delay_sel6:3;
        RBus_UInt32  delay_sel5:3;
        RBus_UInt32  delay_sel4:3;
        RBus_UInt32  delay_sel3:3;
        RBus_UInt32  delay_sel2:3;
        RBus_UInt32  delay_sel1:3;
        RBus_UInt32  delay_sel0:3;
        RBus_UInt32  bist_tp_sel:1;
        RBus_UInt32  bist_repeat:1;
    };
}pinmux_lvdsphy_vby1_d_phy0_txbist_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  packet_number:8;
        RBus_UInt32  packet_length:8;
        RBus_UInt32  bist_seed:8;
        RBus_UInt32  pn_swap:1;
        RBus_UInt32  scramble_dis:1;
        RBus_UInt32  prbs_reverse:1;
        RBus_UInt32  enhance_mode:1;
        RBus_UInt32  reserved_txbist_01:4;
    };
}pinmux_lvdsphy_vby1_d_phy0_txbist_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  err_period:8;
        RBus_UInt32  debug_sel:8;
        RBus_UInt32  lane_enable:8;
        RBus_UInt32  reserved_txbist_02:8;
    };
}pinmux_lvdsphy_vby1_d_phy0_txbist_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  x1x2_sel_2:1;
        RBus_UInt32  prbs_sel_2:1;
        RBus_UInt32  txbist_mode_2:2;
        RBus_UInt32  scramble_default_2:1;
        RBus_UInt32  tp_type_sel_2:1;
        RBus_UInt32  delay_sel7_2:3;
        RBus_UInt32  delay_sel6_2:3;
        RBus_UInt32  delay_sel5_2:3;
        RBus_UInt32  delay_sel4_2:3;
        RBus_UInt32  delay_sel3_2:3;
        RBus_UInt32  delay_sel2_2:3;
        RBus_UInt32  delay_sel1_2:3;
        RBus_UInt32  delay_sel0_2:3;
        RBus_UInt32  bist_tp_sel_2:1;
        RBus_UInt32  bist_repeat_2:1;
    };
}pinmux_lvdsphy_vby1_d_phy1_txbist_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  packet_number_2:8;
        RBus_UInt32  packet_length_2:8;
        RBus_UInt32  bist_seed_2:8;
        RBus_UInt32  pn_swap_2:1;
        RBus_UInt32  scramble_dis_2:1;
        RBus_UInt32  prbs_reverse_2:1;
        RBus_UInt32  enhance_mode_2:1;
        RBus_UInt32  reserved_txbist_01_2:4;
    };
}pinmux_lvdsphy_vby1_d_phy1_txbist_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  err_period_2:8;
        RBus_UInt32  debug_sel_2:8;
        RBus_UInt32  lane_enable_2:8;
        RBus_UInt32  reserved_txbist_02_2:8;
    };
}pinmux_lvdsphy_vby1_d_phy1_txbist_02_RBUS;




#endif 


#endif 
