/**
* @file Mac5-DesignSpec-pad_lvdsphy_regif.
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_PINMUX_LVDSPHY_REG_H_
#define _RBUS_PINMUX_LVDSPHY_REG_H_

#include "rbus_types.h"



//  PINMUX_LVDSPHY Register Address
#define  PINMUX_LVDSPHY_LVDS_0                                                   0x18000CA0
#define  PINMUX_LVDSPHY_LVDS_0_reg_addr                                          "0xB8000CA0"
#define  PINMUX_LVDSPHY_LVDS_0_reg                                               0xB8000CA0
#define  PINMUX_LVDSPHY_LVDS_0_inst_addr                                         "0x0000"
#define  set_PINMUX_LVDSPHY_LVDS_0_reg(data)                                     (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDS_0_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDS_0_reg                                           (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDS_0_reg))
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txfp_ps_shift                              (28)
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txfn_ps_shift                              (24)
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txep_ps_shift                              (20)
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txen_ps_shift                              (16)
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txdp_ps_shift                              (12)
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txdn_ps_shift                              (8)
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txcp_ps_shift                              (4)
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txcn_ps_shift                              (0)
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txfp_ps_mask                               (0xF0000000)
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txfn_ps_mask                               (0x0F000000)
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txep_ps_mask                               (0x00F00000)
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txen_ps_mask                               (0x000F0000)
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txdp_ps_mask                               (0x0000F000)
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txdn_ps_mask                               (0x00000F00)
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txcp_ps_mask                               (0x000000F0)
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txcn_ps_mask                               (0x0000000F)
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txfp_ps(data)                              (0xF0000000&((data)<<28))
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txfn_ps(data)                              (0x0F000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txep_ps(data)                              (0x00F00000&((data)<<20))
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txen_ps(data)                              (0x000F0000&((data)<<16))
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txdp_ps(data)                              (0x0000F000&((data)<<12))
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txdn_ps(data)                              (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txcp_ps(data)                              (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_LVDS_0_plt_p0_txcn_ps(data)                              (0x0000000F&(data))
#define  PINMUX_LVDSPHY_LVDS_0_get_plt_p0_txfp_ps(data)                          ((0xF0000000&(data))>>28)
#define  PINMUX_LVDSPHY_LVDS_0_get_plt_p0_txfn_ps(data)                          ((0x0F000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDS_0_get_plt_p0_txep_ps(data)                          ((0x00F00000&(data))>>20)
#define  PINMUX_LVDSPHY_LVDS_0_get_plt_p0_txen_ps(data)                          ((0x000F0000&(data))>>16)
#define  PINMUX_LVDSPHY_LVDS_0_get_plt_p0_txdp_ps(data)                          ((0x0000F000&(data))>>12)
#define  PINMUX_LVDSPHY_LVDS_0_get_plt_p0_txdn_ps(data)                          ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDS_0_get_plt_p0_txcp_ps(data)                          ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_LVDS_0_get_plt_p0_txcn_ps(data)                          (0x0000000F&(data))

#define  PINMUX_LVDSPHY_LVDS_1                                                   0x18000CA4
#define  PINMUX_LVDSPHY_LVDS_1_reg_addr                                          "0xB8000CA4"
#define  PINMUX_LVDSPHY_LVDS_1_reg                                               0xB8000CA4
#define  PINMUX_LVDSPHY_LVDS_1_inst_addr                                         "0x0001"
#define  set_PINMUX_LVDSPHY_LVDS_1_reg(data)                                     (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDS_1_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDS_1_reg                                           (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDS_1_reg))
#define  PINMUX_LVDSPHY_LVDS_1_plt_p0_txbp_ps_shift                              (28)
#define  PINMUX_LVDSPHY_LVDS_1_plt_p0_txbn_ps_shift                              (24)
#define  PINMUX_LVDSPHY_LVDS_1_plt_p0_txap_ps_shift                              (20)
#define  PINMUX_LVDSPHY_LVDS_1_plt_p0_txan_ps_shift                              (16)
#define  PINMUX_LVDSPHY_LVDS_1_plt_p1_txfp_ps_shift                              (12)
#define  PINMUX_LVDSPHY_LVDS_1_plt_p1_txfn_ps_shift                              (8)
#define  PINMUX_LVDSPHY_LVDS_1_plt_p1_txep_ps_shift                              (4)
#define  PINMUX_LVDSPHY_LVDS_1_plt_p1_txen_ps_shift                              (0)
#define  PINMUX_LVDSPHY_LVDS_1_plt_p0_txbp_ps_mask                               (0xF0000000)
#define  PINMUX_LVDSPHY_LVDS_1_plt_p0_txbn_ps_mask                               (0x0F000000)
#define  PINMUX_LVDSPHY_LVDS_1_plt_p0_txap_ps_mask                               (0x00F00000)
#define  PINMUX_LVDSPHY_LVDS_1_plt_p0_txan_ps_mask                               (0x000F0000)
#define  PINMUX_LVDSPHY_LVDS_1_plt_p1_txfp_ps_mask                               (0x0000F000)
#define  PINMUX_LVDSPHY_LVDS_1_plt_p1_txfn_ps_mask                               (0x00000F00)
#define  PINMUX_LVDSPHY_LVDS_1_plt_p1_txep_ps_mask                               (0x000000F0)
#define  PINMUX_LVDSPHY_LVDS_1_plt_p1_txen_ps_mask                               (0x0000000F)
#define  PINMUX_LVDSPHY_LVDS_1_plt_p0_txbp_ps(data)                              (0xF0000000&((data)<<28))
#define  PINMUX_LVDSPHY_LVDS_1_plt_p0_txbn_ps(data)                              (0x0F000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDS_1_plt_p0_txap_ps(data)                              (0x00F00000&((data)<<20))
#define  PINMUX_LVDSPHY_LVDS_1_plt_p0_txan_ps(data)                              (0x000F0000&((data)<<16))
#define  PINMUX_LVDSPHY_LVDS_1_plt_p1_txfp_ps(data)                              (0x0000F000&((data)<<12))
#define  PINMUX_LVDSPHY_LVDS_1_plt_p1_txfn_ps(data)                              (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDS_1_plt_p1_txep_ps(data)                              (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_LVDS_1_plt_p1_txen_ps(data)                              (0x0000000F&(data))
#define  PINMUX_LVDSPHY_LVDS_1_get_plt_p0_txbp_ps(data)                          ((0xF0000000&(data))>>28)
#define  PINMUX_LVDSPHY_LVDS_1_get_plt_p0_txbn_ps(data)                          ((0x0F000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDS_1_get_plt_p0_txap_ps(data)                          ((0x00F00000&(data))>>20)
#define  PINMUX_LVDSPHY_LVDS_1_get_plt_p0_txan_ps(data)                          ((0x000F0000&(data))>>16)
#define  PINMUX_LVDSPHY_LVDS_1_get_plt_p1_txfp_ps(data)                          ((0x0000F000&(data))>>12)
#define  PINMUX_LVDSPHY_LVDS_1_get_plt_p1_txfn_ps(data)                          ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDS_1_get_plt_p1_txep_ps(data)                          ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_LVDS_1_get_plt_p1_txen_ps(data)                          (0x0000000F&(data))

#define  PINMUX_LVDSPHY_LVDS_2                                                   0x18000CA8
#define  PINMUX_LVDSPHY_LVDS_2_reg_addr                                          "0xB8000CA8"
#define  PINMUX_LVDSPHY_LVDS_2_reg                                               0xB8000CA8
#define  PINMUX_LVDSPHY_LVDS_2_inst_addr                                         "0x0002"
#define  set_PINMUX_LVDSPHY_LVDS_2_reg(data)                                     (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDS_2_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDS_2_reg                                           (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDS_2_reg))
#define  PINMUX_LVDSPHY_LVDS_2_plt_p1_txdp_ps_shift                              (28)
#define  PINMUX_LVDSPHY_LVDS_2_plt_p1_txdn_ps_shift                              (24)
#define  PINMUX_LVDSPHY_LVDS_2_plt_p1_txcp_ps_shift                              (20)
#define  PINMUX_LVDSPHY_LVDS_2_plt_p1_txcn_ps_shift                              (16)
#define  PINMUX_LVDSPHY_LVDS_2_plt_p1_txbp_ps_shift                              (12)
#define  PINMUX_LVDSPHY_LVDS_2_plt_p1_txbn_ps_shift                              (8)
#define  PINMUX_LVDSPHY_LVDS_2_plt_p1_txap_ps_shift                              (4)
#define  PINMUX_LVDSPHY_LVDS_2_plt_p1_txan_ps_shift                              (0)
#define  PINMUX_LVDSPHY_LVDS_2_plt_p1_txdp_ps_mask                               (0xF0000000)
#define  PINMUX_LVDSPHY_LVDS_2_plt_p1_txdn_ps_mask                               (0x0F000000)
#define  PINMUX_LVDSPHY_LVDS_2_plt_p1_txcp_ps_mask                               (0x00F00000)
#define  PINMUX_LVDSPHY_LVDS_2_plt_p1_txcn_ps_mask                               (0x000F0000)
#define  PINMUX_LVDSPHY_LVDS_2_plt_p1_txbp_ps_mask                               (0x0000F000)
#define  PINMUX_LVDSPHY_LVDS_2_plt_p1_txbn_ps_mask                               (0x00000F00)
#define  PINMUX_LVDSPHY_LVDS_2_plt_p1_txap_ps_mask                               (0x000000F0)
#define  PINMUX_LVDSPHY_LVDS_2_plt_p1_txan_ps_mask                               (0x0000000F)
#define  PINMUX_LVDSPHY_LVDS_2_plt_p1_txdp_ps(data)                              (0xF0000000&((data)<<28))
#define  PINMUX_LVDSPHY_LVDS_2_plt_p1_txdn_ps(data)                              (0x0F000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDS_2_plt_p1_txcp_ps(data)                              (0x00F00000&((data)<<20))
#define  PINMUX_LVDSPHY_LVDS_2_plt_p1_txcn_ps(data)                              (0x000F0000&((data)<<16))
#define  PINMUX_LVDSPHY_LVDS_2_plt_p1_txbp_ps(data)                              (0x0000F000&((data)<<12))
#define  PINMUX_LVDSPHY_LVDS_2_plt_p1_txbn_ps(data)                              (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDS_2_plt_p1_txap_ps(data)                              (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_LVDS_2_plt_p1_txan_ps(data)                              (0x0000000F&(data))
#define  PINMUX_LVDSPHY_LVDS_2_get_plt_p1_txdp_ps(data)                          ((0xF0000000&(data))>>28)
#define  PINMUX_LVDSPHY_LVDS_2_get_plt_p1_txdn_ps(data)                          ((0x0F000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDS_2_get_plt_p1_txcp_ps(data)                          ((0x00F00000&(data))>>20)
#define  PINMUX_LVDSPHY_LVDS_2_get_plt_p1_txcn_ps(data)                          ((0x000F0000&(data))>>16)
#define  PINMUX_LVDSPHY_LVDS_2_get_plt_p1_txbp_ps(data)                          ((0x0000F000&(data))>>12)
#define  PINMUX_LVDSPHY_LVDS_2_get_plt_p1_txbn_ps(data)                          ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDS_2_get_plt_p1_txap_ps(data)                          ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_LVDS_2_get_plt_p1_txan_ps(data)                          (0x0000000F&(data))

#define  PINMUX_LVDSPHY_LVDS_3                                                   0x18000CAC
#define  PINMUX_LVDSPHY_LVDS_3_reg_addr                                          "0xB8000CAC"
#define  PINMUX_LVDSPHY_LVDS_3_reg                                               0xB8000CAC
#define  PINMUX_LVDSPHY_LVDS_3_inst_addr                                         "0x0003"
#define  set_PINMUX_LVDSPHY_LVDS_3_reg(data)                                     (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDS_3_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDS_3_reg                                           (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDS_3_reg))
#define  PINMUX_LVDSPHY_LVDS_3_plt_p2_txfp_ps_shift                              (28)
#define  PINMUX_LVDSPHY_LVDS_3_plt_p2_txfn_ps_shift                              (24)
#define  PINMUX_LVDSPHY_LVDS_3_plt_p2_txep_ps_shift                              (20)
#define  PINMUX_LVDSPHY_LVDS_3_plt_p2_txen_ps_shift                              (16)
#define  PINMUX_LVDSPHY_LVDS_3_plt_p2_txdp_ps_shift                              (12)
#define  PINMUX_LVDSPHY_LVDS_3_plt_p2_txdn_ps_shift                              (8)
#define  PINMUX_LVDSPHY_LVDS_3_plt_p2_txcp_ps_shift                              (4)
#define  PINMUX_LVDSPHY_LVDS_3_plt_p2_txcn_ps_shift                              (0)
#define  PINMUX_LVDSPHY_LVDS_3_plt_p2_txfp_ps_mask                               (0xF0000000)
#define  PINMUX_LVDSPHY_LVDS_3_plt_p2_txfn_ps_mask                               (0x0F000000)
#define  PINMUX_LVDSPHY_LVDS_3_plt_p2_txep_ps_mask                               (0x00F00000)
#define  PINMUX_LVDSPHY_LVDS_3_plt_p2_txen_ps_mask                               (0x000F0000)
#define  PINMUX_LVDSPHY_LVDS_3_plt_p2_txdp_ps_mask                               (0x0000F000)
#define  PINMUX_LVDSPHY_LVDS_3_plt_p2_txdn_ps_mask                               (0x00000F00)
#define  PINMUX_LVDSPHY_LVDS_3_plt_p2_txcp_ps_mask                               (0x000000F0)
#define  PINMUX_LVDSPHY_LVDS_3_plt_p2_txcn_ps_mask                               (0x0000000F)
#define  PINMUX_LVDSPHY_LVDS_3_plt_p2_txfp_ps(data)                              (0xF0000000&((data)<<28))
#define  PINMUX_LVDSPHY_LVDS_3_plt_p2_txfn_ps(data)                              (0x0F000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDS_3_plt_p2_txep_ps(data)                              (0x00F00000&((data)<<20))
#define  PINMUX_LVDSPHY_LVDS_3_plt_p2_txen_ps(data)                              (0x000F0000&((data)<<16))
#define  PINMUX_LVDSPHY_LVDS_3_plt_p2_txdp_ps(data)                              (0x0000F000&((data)<<12))
#define  PINMUX_LVDSPHY_LVDS_3_plt_p2_txdn_ps(data)                              (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDS_3_plt_p2_txcp_ps(data)                              (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_LVDS_3_plt_p2_txcn_ps(data)                              (0x0000000F&(data))
#define  PINMUX_LVDSPHY_LVDS_3_get_plt_p2_txfp_ps(data)                          ((0xF0000000&(data))>>28)
#define  PINMUX_LVDSPHY_LVDS_3_get_plt_p2_txfn_ps(data)                          ((0x0F000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDS_3_get_plt_p2_txep_ps(data)                          ((0x00F00000&(data))>>20)
#define  PINMUX_LVDSPHY_LVDS_3_get_plt_p2_txen_ps(data)                          ((0x000F0000&(data))>>16)
#define  PINMUX_LVDSPHY_LVDS_3_get_plt_p2_txdp_ps(data)                          ((0x0000F000&(data))>>12)
#define  PINMUX_LVDSPHY_LVDS_3_get_plt_p2_txdn_ps(data)                          ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDS_3_get_plt_p2_txcp_ps(data)                          ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_LVDS_3_get_plt_p2_txcn_ps(data)                          (0x0000000F&(data))

#define  PINMUX_LVDSPHY_LVDS_4                                                   0x18000CB0
#define  PINMUX_LVDSPHY_LVDS_4_reg_addr                                          "0xB8000CB0"
#define  PINMUX_LVDSPHY_LVDS_4_reg                                               0xB8000CB0
#define  PINMUX_LVDSPHY_LVDS_4_inst_addr                                         "0x0004"
#define  set_PINMUX_LVDSPHY_LVDS_4_reg(data)                                     (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDS_4_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDS_4_reg                                           (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDS_4_reg))
#define  PINMUX_LVDSPHY_LVDS_4_plt_p2_txbp_ps_shift                              (28)
#define  PINMUX_LVDSPHY_LVDS_4_plt_p2_txbn_ps_shift                              (24)
#define  PINMUX_LVDSPHY_LVDS_4_plt_p2_txap_ps_shift                              (20)
#define  PINMUX_LVDSPHY_LVDS_4_plt_p2_txan_ps_shift                              (16)
#define  PINMUX_LVDSPHY_LVDS_4_plt_p3_txfp_ps_shift                              (12)
#define  PINMUX_LVDSPHY_LVDS_4_plt_p3_txfn_ps_shift                              (8)
#define  PINMUX_LVDSPHY_LVDS_4_plt_p3_txep_ps_shift                              (4)
#define  PINMUX_LVDSPHY_LVDS_4_plt_p3_txen_ps_shift                              (0)
#define  PINMUX_LVDSPHY_LVDS_4_plt_p2_txbp_ps_mask                               (0xF0000000)
#define  PINMUX_LVDSPHY_LVDS_4_plt_p2_txbn_ps_mask                               (0x0F000000)
#define  PINMUX_LVDSPHY_LVDS_4_plt_p2_txap_ps_mask                               (0x00F00000)
#define  PINMUX_LVDSPHY_LVDS_4_plt_p2_txan_ps_mask                               (0x000F0000)
#define  PINMUX_LVDSPHY_LVDS_4_plt_p3_txfp_ps_mask                               (0x0000F000)
#define  PINMUX_LVDSPHY_LVDS_4_plt_p3_txfn_ps_mask                               (0x00000F00)
#define  PINMUX_LVDSPHY_LVDS_4_plt_p3_txep_ps_mask                               (0x000000F0)
#define  PINMUX_LVDSPHY_LVDS_4_plt_p3_txen_ps_mask                               (0x0000000F)
#define  PINMUX_LVDSPHY_LVDS_4_plt_p2_txbp_ps(data)                              (0xF0000000&((data)<<28))
#define  PINMUX_LVDSPHY_LVDS_4_plt_p2_txbn_ps(data)                              (0x0F000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDS_4_plt_p2_txap_ps(data)                              (0x00F00000&((data)<<20))
#define  PINMUX_LVDSPHY_LVDS_4_plt_p2_txan_ps(data)                              (0x000F0000&((data)<<16))
#define  PINMUX_LVDSPHY_LVDS_4_plt_p3_txfp_ps(data)                              (0x0000F000&((data)<<12))
#define  PINMUX_LVDSPHY_LVDS_4_plt_p3_txfn_ps(data)                              (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDS_4_plt_p3_txep_ps(data)                              (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_LVDS_4_plt_p3_txen_ps(data)                              (0x0000000F&(data))
#define  PINMUX_LVDSPHY_LVDS_4_get_plt_p2_txbp_ps(data)                          ((0xF0000000&(data))>>28)
#define  PINMUX_LVDSPHY_LVDS_4_get_plt_p2_txbn_ps(data)                          ((0x0F000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDS_4_get_plt_p2_txap_ps(data)                          ((0x00F00000&(data))>>20)
#define  PINMUX_LVDSPHY_LVDS_4_get_plt_p2_txan_ps(data)                          ((0x000F0000&(data))>>16)
#define  PINMUX_LVDSPHY_LVDS_4_get_plt_p3_txfp_ps(data)                          ((0x0000F000&(data))>>12)
#define  PINMUX_LVDSPHY_LVDS_4_get_plt_p3_txfn_ps(data)                          ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDS_4_get_plt_p3_txep_ps(data)                          ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_LVDS_4_get_plt_p3_txen_ps(data)                          (0x0000000F&(data))

#define  PINMUX_LVDSPHY_LVDS_5                                                   0x18000CB4
#define  PINMUX_LVDSPHY_LVDS_5_reg_addr                                          "0xB8000CB4"
#define  PINMUX_LVDSPHY_LVDS_5_reg                                               0xB8000CB4
#define  PINMUX_LVDSPHY_LVDS_5_inst_addr                                         "0x0005"
#define  set_PINMUX_LVDSPHY_LVDS_5_reg(data)                                     (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDS_5_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDS_5_reg                                           (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDS_5_reg))
#define  PINMUX_LVDSPHY_LVDS_5_plt_p3_txdp_ps_shift                              (28)
#define  PINMUX_LVDSPHY_LVDS_5_plt_p3_txdn_ps_shift                              (24)
#define  PINMUX_LVDSPHY_LVDS_5_plt_p3_txcp_ps_shift                              (20)
#define  PINMUX_LVDSPHY_LVDS_5_plt_p3_txcn_ps_shift                              (16)
#define  PINMUX_LVDSPHY_LVDS_5_plt_p3_txbp_ps_shift                              (12)
#define  PINMUX_LVDSPHY_LVDS_5_plt_p3_txbn_ps_shift                              (8)
#define  PINMUX_LVDSPHY_LVDS_5_plt_p3_txap_ps_shift                              (4)
#define  PINMUX_LVDSPHY_LVDS_5_plt_p3_txan_ps_shift                              (0)
#define  PINMUX_LVDSPHY_LVDS_5_plt_p3_txdp_ps_mask                               (0xF0000000)
#define  PINMUX_LVDSPHY_LVDS_5_plt_p3_txdn_ps_mask                               (0x0F000000)
#define  PINMUX_LVDSPHY_LVDS_5_plt_p3_txcp_ps_mask                               (0x00F00000)
#define  PINMUX_LVDSPHY_LVDS_5_plt_p3_txcn_ps_mask                               (0x000F0000)
#define  PINMUX_LVDSPHY_LVDS_5_plt_p3_txbp_ps_mask                               (0x0000F000)
#define  PINMUX_LVDSPHY_LVDS_5_plt_p3_txbn_ps_mask                               (0x00000F00)
#define  PINMUX_LVDSPHY_LVDS_5_plt_p3_txap_ps_mask                               (0x000000F0)
#define  PINMUX_LVDSPHY_LVDS_5_plt_p3_txan_ps_mask                               (0x0000000F)
#define  PINMUX_LVDSPHY_LVDS_5_plt_p3_txdp_ps(data)                              (0xF0000000&((data)<<28))
#define  PINMUX_LVDSPHY_LVDS_5_plt_p3_txdn_ps(data)                              (0x0F000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDS_5_plt_p3_txcp_ps(data)                              (0x00F00000&((data)<<20))
#define  PINMUX_LVDSPHY_LVDS_5_plt_p3_txcn_ps(data)                              (0x000F0000&((data)<<16))
#define  PINMUX_LVDSPHY_LVDS_5_plt_p3_txbp_ps(data)                              (0x0000F000&((data)<<12))
#define  PINMUX_LVDSPHY_LVDS_5_plt_p3_txbn_ps(data)                              (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDS_5_plt_p3_txap_ps(data)                              (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_LVDS_5_plt_p3_txan_ps(data)                              (0x0000000F&(data))
#define  PINMUX_LVDSPHY_LVDS_5_get_plt_p3_txdp_ps(data)                          ((0xF0000000&(data))>>28)
#define  PINMUX_LVDSPHY_LVDS_5_get_plt_p3_txdn_ps(data)                          ((0x0F000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDS_5_get_plt_p3_txcp_ps(data)                          ((0x00F00000&(data))>>20)
#define  PINMUX_LVDSPHY_LVDS_5_get_plt_p3_txcn_ps(data)                          ((0x000F0000&(data))>>16)
#define  PINMUX_LVDSPHY_LVDS_5_get_plt_p3_txbp_ps(data)                          ((0x0000F000&(data))>>12)
#define  PINMUX_LVDSPHY_LVDS_5_get_plt_p3_txbn_ps(data)                          ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDS_5_get_plt_p3_txap_ps(data)                          ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_LVDS_5_get_plt_p3_txan_ps(data)                          (0x0000000F&(data))

#define  PINMUX_LVDSPHY_Pin_Mux_LVDS                                             0x18000CB8
#define  PINMUX_LVDSPHY_Pin_Mux_LVDS_reg_addr                                    "0xB8000CB8"
#define  PINMUX_LVDSPHY_Pin_Mux_LVDS_reg                                         0xB8000CB8
#define  PINMUX_LVDSPHY_Pin_Mux_LVDS_inst_addr                                   "0x0006"
#define  set_PINMUX_LVDSPHY_Pin_Mux_LVDS_reg(data)                               (*((volatile unsigned int*)PINMUX_LVDSPHY_Pin_Mux_LVDS_reg)=data)
#define  get_PINMUX_LVDSPHY_Pin_Mux_LVDS_reg                                     (*((volatile unsigned int*)PINMUX_LVDSPHY_Pin_Mux_LVDS_reg))
#define  PINMUX_LVDSPHY_Pin_Mux_LVDS_epi_lock_sel_shift                          (0)
#define  PINMUX_LVDSPHY_Pin_Mux_LVDS_epi_lock_sel_mask                           (0x00000003)
#define  PINMUX_LVDSPHY_Pin_Mux_LVDS_epi_lock_sel(data)                          (0x00000003&(data))
#define  PINMUX_LVDSPHY_Pin_Mux_LVDS_get_epi_lock_sel(data)                      (0x00000003&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_4                                 0x18000C10
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_4_reg_addr                        "0xB8000C10"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_4_reg                             0xB8000C10
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_4_inst_addr                       "0x0007"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_4_reg(data)                   (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_4_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_4_reg                         (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_4_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_4_pif_p0_txlap_mode_shift         (29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_4_pif_p0_txlan_mode_shift         (26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_4_pif_p0_txla_ckphs_shift         (24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_4_pif_p0_txla_sr_shift            (19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_4_pif_p0_txla_term_shift          (8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_4_pif_p0_txla_iem_sel_shift       (4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_4_pif_p0_txla_idrv_sel_shift      (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_4_pif_p0_txlap_mode_mask          (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_4_pif_p0_txlan_mode_mask          (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_4_pif_p0_txla_ckphs_mask          (0x01000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_4_pif_p0_txla_sr_mask             (0x00080000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_4_pif_p0_txla_term_mask           (0x00000F00)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_4_pif_p0_txla_iem_sel_mask        (0x000000F0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_4_pif_p0_txla_idrv_sel_mask       (0x0000000F)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_4_pif_p0_txlap_mode(data)         (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_4_pif_p0_txlan_mode(data)         (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_4_pif_p0_txla_ckphs(data)         (0x01000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_4_pif_p0_txla_sr(data)            (0x00080000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_4_pif_p0_txla_term(data)          (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_4_pif_p0_txla_iem_sel(data)       (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_4_pif_p0_txla_idrv_sel(data)      (0x0000000F&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_4_get_pif_p0_txlap_mode(data)     ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_4_get_pif_p0_txlan_mode(data)     ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_4_get_pif_p0_txla_ckphs(data)     ((0x01000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_4_get_pif_p0_txla_sr(data)        ((0x00080000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_4_get_pif_p0_txla_term(data)      ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_4_get_pif_p0_txla_iem_sel(data)   ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_4_get_pif_p0_txla_idrv_sel(data)  (0x0000000F&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_5                                 0x18000C14
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_5_reg_addr                        "0xB8000C14"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_5_reg                             0xB8000C14
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_5_inst_addr                       "0x0008"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_5_reg(data)                   (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_5_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_5_reg                         (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_5_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_5_pif_p0_txlbp_mode_shift         (29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_5_pif_p0_txlbn_mode_shift         (26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_5_pif_p0_txlb_ckphs_shift         (24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_5_pif_p0_txlb_sr_shift            (19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_5_pif_p0_txlb_term_shift          (8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_5_pif_p0_txlb_iem_sel_shift       (4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_5_pif_p0_txlb_idrv_sel_shift      (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_5_pif_p0_txlbp_mode_mask          (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_5_pif_p0_txlbn_mode_mask          (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_5_pif_p0_txlb_ckphs_mask          (0x01000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_5_pif_p0_txlb_sr_mask             (0x00080000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_5_pif_p0_txlb_term_mask           (0x00000F00)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_5_pif_p0_txlb_iem_sel_mask        (0x000000F0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_5_pif_p0_txlb_idrv_sel_mask       (0x0000000F)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_5_pif_p0_txlbp_mode(data)         (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_5_pif_p0_txlbn_mode(data)         (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_5_pif_p0_txlb_ckphs(data)         (0x01000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_5_pif_p0_txlb_sr(data)            (0x00080000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_5_pif_p0_txlb_term(data)          (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_5_pif_p0_txlb_iem_sel(data)       (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_5_pif_p0_txlb_idrv_sel(data)      (0x0000000F&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_5_get_pif_p0_txlbp_mode(data)     ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_5_get_pif_p0_txlbn_mode(data)     ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_5_get_pif_p0_txlb_ckphs(data)     ((0x01000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_5_get_pif_p0_txlb_sr(data)        ((0x00080000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_5_get_pif_p0_txlb_term(data)      ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_5_get_pif_p0_txlb_iem_sel(data)   ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_5_get_pif_p0_txlb_idrv_sel(data)  (0x0000000F&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_6                                 0x18000C18
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_6_reg_addr                        "0xB8000C18"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_6_reg                             0xB8000C18
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_6_inst_addr                       "0x0009"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_6_reg(data)                   (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_6_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_6_reg                         (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_6_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_6_pif_p0_txlcp_mode_shift         (29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_6_pif_p0_txlcn_mode_shift         (26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_6_pif_p0_txlc_ckphs_shift         (24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_6_pif_p0_txlc_sr_shift            (19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_6_pif_p0_txlc_term_shift          (8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_6_pif_p0_txlc_iem_sel_shift       (4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_6_pif_p0_txlc_idrv_sel_shift      (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_6_pif_p0_txlcp_mode_mask          (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_6_pif_p0_txlcn_mode_mask          (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_6_pif_p0_txlc_ckphs_mask          (0x01000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_6_pif_p0_txlc_sr_mask             (0x00080000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_6_pif_p0_txlc_term_mask           (0x00000F00)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_6_pif_p0_txlc_iem_sel_mask        (0x000000F0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_6_pif_p0_txlc_idrv_sel_mask       (0x0000000F)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_6_pif_p0_txlcp_mode(data)         (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_6_pif_p0_txlcn_mode(data)         (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_6_pif_p0_txlc_ckphs(data)         (0x01000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_6_pif_p0_txlc_sr(data)            (0x00080000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_6_pif_p0_txlc_term(data)          (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_6_pif_p0_txlc_iem_sel(data)       (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_6_pif_p0_txlc_idrv_sel(data)      (0x0000000F&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_6_get_pif_p0_txlcp_mode(data)     ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_6_get_pif_p0_txlcn_mode(data)     ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_6_get_pif_p0_txlc_ckphs(data)     ((0x01000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_6_get_pif_p0_txlc_sr(data)        ((0x00080000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_6_get_pif_p0_txlc_term(data)      ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_6_get_pif_p0_txlc_iem_sel(data)   ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_6_get_pif_p0_txlc_idrv_sel(data)  (0x0000000F&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_7                                 0x18000C1C
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_7_reg_addr                        "0xB8000C1C"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_7_reg                             0xB8000C1C
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_7_inst_addr                       "0x000A"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_7_reg(data)                   (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_7_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_7_reg                         (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_7_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_7_pif_p0_txldp_mode_shift         (29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_7_pif_p0_txldn_mode_shift         (26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_7_pif_p0_txld_ckphs_shift         (24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_7_pif_p0_txld_sr_shift            (19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_7_pif_p0_txld_term_shift          (8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_7_pif_p0_txld_iem_sel_shift       (4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_7_pif_p0_txld_idrv_sel_shift      (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_7_pif_p0_txldp_mode_mask          (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_7_pif_p0_txldn_mode_mask          (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_7_pif_p0_txld_ckphs_mask          (0x01000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_7_pif_p0_txld_sr_mask             (0x00080000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_7_pif_p0_txld_term_mask           (0x00000F00)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_7_pif_p0_txld_iem_sel_mask        (0x000000F0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_7_pif_p0_txld_idrv_sel_mask       (0x0000000F)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_7_pif_p0_txldp_mode(data)         (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_7_pif_p0_txldn_mode(data)         (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_7_pif_p0_txld_ckphs(data)         (0x01000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_7_pif_p0_txld_sr(data)            (0x00080000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_7_pif_p0_txld_term(data)          (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_7_pif_p0_txld_iem_sel(data)       (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_7_pif_p0_txld_idrv_sel(data)      (0x0000000F&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_7_get_pif_p0_txldp_mode(data)     ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_7_get_pif_p0_txldn_mode(data)     ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_7_get_pif_p0_txld_ckphs(data)     ((0x01000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_7_get_pif_p0_txld_sr(data)        ((0x00080000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_7_get_pif_p0_txld_term(data)      ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_7_get_pif_p0_txld_iem_sel(data)   ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_7_get_pif_p0_txld_idrv_sel(data)  (0x0000000F&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_8                                 0x18000C20
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_8_reg_addr                        "0xB8000C20"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_8_reg                             0xB8000C20
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_8_inst_addr                       "0x000B"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_8_reg(data)                   (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_8_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_8_reg                         (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_8_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_8_pif_p0_txlep_mode_shift         (29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_8_pif_p0_txlen_mode_shift         (26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_8_pif_p0_txle_ckphs_shift         (24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_8_pif_p0_txle_sr_shift            (19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_8_pif_p0_txle_term_shift          (8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_8_pif_p0_txle_iem_sel_shift       (4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_8_pif_p0_txle_idrv_sel_shift      (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_8_pif_p0_txlep_mode_mask          (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_8_pif_p0_txlen_mode_mask          (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_8_pif_p0_txle_ckphs_mask          (0x01000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_8_pif_p0_txle_sr_mask             (0x00080000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_8_pif_p0_txle_term_mask           (0x00000F00)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_8_pif_p0_txle_iem_sel_mask        (0x000000F0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_8_pif_p0_txle_idrv_sel_mask       (0x0000000F)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_8_pif_p0_txlep_mode(data)         (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_8_pif_p0_txlen_mode(data)         (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_8_pif_p0_txle_ckphs(data)         (0x01000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_8_pif_p0_txle_sr(data)            (0x00080000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_8_pif_p0_txle_term(data)          (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_8_pif_p0_txle_iem_sel(data)       (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_8_pif_p0_txle_idrv_sel(data)      (0x0000000F&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_8_get_pif_p0_txlep_mode(data)     ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_8_get_pif_p0_txlen_mode(data)     ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_8_get_pif_p0_txle_ckphs(data)     ((0x01000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_8_get_pif_p0_txle_sr(data)        ((0x00080000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_8_get_pif_p0_txle_term(data)      ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_8_get_pif_p0_txle_iem_sel(data)   ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_8_get_pif_p0_txle_idrv_sel(data)  (0x0000000F&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_9                                 0x18000C24
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_9_reg_addr                        "0xB8000C24"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_9_reg                             0xB8000C24
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_9_inst_addr                       "0x000C"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_9_reg(data)                   (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_9_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_9_reg                         (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_9_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_9_pif_p0_txlfp_mode_shift         (29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_9_pif_p0_txlfn_mode_shift         (26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_9_pif_p0_txlf_ckphs_shift         (24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_9_pif_p0_txlf_sr_shift            (19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_9_pif_p0_txlf_term_shift          (8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_9_pif_p0_txlf_iem_sel_shift       (4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_9_pif_p0_txlf_idrv_sel_shift      (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_9_pif_p0_txlfp_mode_mask          (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_9_pif_p0_txlfn_mode_mask          (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_9_pif_p0_txlf_ckphs_mask          (0x01000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_9_pif_p0_txlf_sr_mask             (0x00080000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_9_pif_p0_txlf_term_mask           (0x00000F00)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_9_pif_p0_txlf_iem_sel_mask        (0x000000F0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_9_pif_p0_txlf_idrv_sel_mask       (0x0000000F)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_9_pif_p0_txlfp_mode(data)         (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_9_pif_p0_txlfn_mode(data)         (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_9_pif_p0_txlf_ckphs(data)         (0x01000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_9_pif_p0_txlf_sr(data)            (0x00080000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_9_pif_p0_txlf_term(data)          (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_9_pif_p0_txlf_iem_sel(data)       (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_9_pif_p0_txlf_idrv_sel(data)      (0x0000000F&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_9_get_pif_p0_txlfp_mode(data)     ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_9_get_pif_p0_txlfn_mode(data)     ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_9_get_pif_p0_txlf_ckphs(data)     ((0x01000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_9_get_pif_p0_txlf_sr(data)        ((0x00080000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_9_get_pif_p0_txlf_term(data)      ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_9_get_pif_p0_txlf_iem_sel(data)   ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_9_get_pif_p0_txlf_idrv_sel(data)  (0x0000000F&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_11                                0x18000C30
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_11_reg_addr                       "0xB8000C30"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_11_reg                            0xB8000C30
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_11_inst_addr                      "0x000D"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_11_reg(data)                  (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_11_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_11_reg                        (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_11_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_11_pif_p1_txlap_mode_shift        (29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_11_pif_p1_txlan_mode_shift        (26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_11_pif_p1_txla_ckphs_shift        (24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_11_pif_p1_txla_sr_shift           (19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_11_pif_p1_txla_term_shift         (8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_11_pif_p1_txla_iem_sel_shift      (4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_11_pif_p1_txla_idrv_sel_shift     (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_11_pif_p1_txlap_mode_mask         (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_11_pif_p1_txlan_mode_mask         (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_11_pif_p1_txla_ckphs_mask         (0x01000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_11_pif_p1_txla_sr_mask            (0x00080000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_11_pif_p1_txla_term_mask          (0x00000F00)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_11_pif_p1_txla_iem_sel_mask       (0x000000F0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_11_pif_p1_txla_idrv_sel_mask      (0x0000000F)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_11_pif_p1_txlap_mode(data)        (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_11_pif_p1_txlan_mode(data)        (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_11_pif_p1_txla_ckphs(data)        (0x01000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_11_pif_p1_txla_sr(data)           (0x00080000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_11_pif_p1_txla_term(data)         (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_11_pif_p1_txla_iem_sel(data)      (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_11_pif_p1_txla_idrv_sel(data)     (0x0000000F&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_11_get_pif_p1_txlap_mode(data)    ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_11_get_pif_p1_txlan_mode(data)    ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_11_get_pif_p1_txla_ckphs(data)    ((0x01000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_11_get_pif_p1_txla_sr(data)       ((0x00080000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_11_get_pif_p1_txla_term(data)     ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_11_get_pif_p1_txla_iem_sel(data)  ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_11_get_pif_p1_txla_idrv_sel(data) (0x0000000F&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_12                                0x18000C34
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_12_reg_addr                       "0xB8000C34"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_12_reg                            0xB8000C34
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_12_inst_addr                      "0x000E"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_12_reg(data)                  (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_12_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_12_reg                        (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_12_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_12_pif_p1_txlbp_mode_shift        (29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_12_pif_p1_txlbn_mode_shift        (26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_12_pif_p1_txlb_ckphs_shift        (24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_12_pif_p1_txlb_sr_shift           (19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_12_pif_p1_txlb_term_shift         (8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_12_pif_p1_txlb_iem_sel_shift      (4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_12_pif_p1_txlb_idrv_sel_shift     (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_12_pif_p1_txlbp_mode_mask         (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_12_pif_p1_txlbn_mode_mask         (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_12_pif_p1_txlb_ckphs_mask         (0x01000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_12_pif_p1_txlb_sr_mask            (0x00080000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_12_pif_p1_txlb_term_mask          (0x00000F00)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_12_pif_p1_txlb_iem_sel_mask       (0x000000F0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_12_pif_p1_txlb_idrv_sel_mask      (0x0000000F)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_12_pif_p1_txlbp_mode(data)        (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_12_pif_p1_txlbn_mode(data)        (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_12_pif_p1_txlb_ckphs(data)        (0x01000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_12_pif_p1_txlb_sr(data)           (0x00080000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_12_pif_p1_txlb_term(data)         (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_12_pif_p1_txlb_iem_sel(data)      (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_12_pif_p1_txlb_idrv_sel(data)     (0x0000000F&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_12_get_pif_p1_txlbp_mode(data)    ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_12_get_pif_p1_txlbn_mode(data)    ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_12_get_pif_p1_txlb_ckphs(data)    ((0x01000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_12_get_pif_p1_txlb_sr(data)       ((0x00080000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_12_get_pif_p1_txlb_term(data)     ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_12_get_pif_p1_txlb_iem_sel(data)  ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_12_get_pif_p1_txlb_idrv_sel(data) (0x0000000F&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_13                                0x18000C38
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_13_reg_addr                       "0xB8000C38"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_13_reg                            0xB8000C38
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_13_inst_addr                      "0x000F"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_13_reg(data)                  (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_13_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_13_reg                        (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_13_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_13_pif_p1_txlcp_mode_shift        (29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_13_pif_p1_txlcn_mode_shift        (26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_13_pif_p1_txlc_ckphs_shift        (24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_13_pif_p1_txlc_sr_shift           (19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_13_pif_p1_txlc_term_shift         (8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_13_pif_p1_txlc_iem_sel_shift      (4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_13_pif_p1_txlc_idrv_sel_shift     (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_13_pif_p1_txlcp_mode_mask         (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_13_pif_p1_txlcn_mode_mask         (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_13_pif_p1_txlc_ckphs_mask         (0x01000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_13_pif_p1_txlc_sr_mask            (0x00080000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_13_pif_p1_txlc_term_mask          (0x00000F00)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_13_pif_p1_txlc_iem_sel_mask       (0x000000F0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_13_pif_p1_txlc_idrv_sel_mask      (0x0000000F)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_13_pif_p1_txlcp_mode(data)        (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_13_pif_p1_txlcn_mode(data)        (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_13_pif_p1_txlc_ckphs(data)        (0x01000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_13_pif_p1_txlc_sr(data)           (0x00080000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_13_pif_p1_txlc_term(data)         (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_13_pif_p1_txlc_iem_sel(data)      (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_13_pif_p1_txlc_idrv_sel(data)     (0x0000000F&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_13_get_pif_p1_txlcp_mode(data)    ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_13_get_pif_p1_txlcn_mode(data)    ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_13_get_pif_p1_txlc_ckphs(data)    ((0x01000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_13_get_pif_p1_txlc_sr(data)       ((0x00080000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_13_get_pif_p1_txlc_term(data)     ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_13_get_pif_p1_txlc_iem_sel(data)  ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_13_get_pif_p1_txlc_idrv_sel(data) (0x0000000F&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_14                                0x18000C3C
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_14_reg_addr                       "0xB8000C3C"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_14_reg                            0xB8000C3C
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_14_inst_addr                      "0x0010"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_14_reg(data)                  (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_14_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_14_reg                        (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_14_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_14_pif_p1_txldp_mode_shift        (29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_14_pif_p1_txldn_mode_shift        (26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_14_pif_p1_txld_ckphs_shift        (24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_14_pif_p1_txld_sr_shift           (19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_14_pif_p1_txld_term_shift         (8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_14_pif_p1_txld_iem_sel_shift      (4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_14_pif_p1_txld_idrv_sel_shift     (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_14_pif_p1_txldp_mode_mask         (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_14_pif_p1_txldn_mode_mask         (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_14_pif_p1_txld_ckphs_mask         (0x01000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_14_pif_p1_txld_sr_mask            (0x00080000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_14_pif_p1_txld_term_mask          (0x00000F00)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_14_pif_p1_txld_iem_sel_mask       (0x000000F0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_14_pif_p1_txld_idrv_sel_mask      (0x0000000F)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_14_pif_p1_txldp_mode(data)        (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_14_pif_p1_txldn_mode(data)        (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_14_pif_p1_txld_ckphs(data)        (0x01000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_14_pif_p1_txld_sr(data)           (0x00080000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_14_pif_p1_txld_term(data)         (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_14_pif_p1_txld_iem_sel(data)      (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_14_pif_p1_txld_idrv_sel(data)     (0x0000000F&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_14_get_pif_p1_txldp_mode(data)    ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_14_get_pif_p1_txldn_mode(data)    ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_14_get_pif_p1_txld_ckphs(data)    ((0x01000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_14_get_pif_p1_txld_sr(data)       ((0x00080000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_14_get_pif_p1_txld_term(data)     ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_14_get_pif_p1_txld_iem_sel(data)  ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_14_get_pif_p1_txld_idrv_sel(data) (0x0000000F&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_15                                0x18000C40
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_15_reg_addr                       "0xB8000C40"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_15_reg                            0xB8000C40
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_15_inst_addr                      "0x0011"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_15_reg(data)                  (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_15_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_15_reg                        (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_15_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_15_pif_p1_txlep_mode_shift        (29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_15_pif_p1_txlen_mode_shift        (26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_15_pif_p1_txle_ckphs_shift        (24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_15_pif_p1_txle_sr_shift           (19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_15_pif_p1_txle_term_shift         (8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_15_pif_p1_txle_iem_sel_shift      (4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_15_pif_p1_txle_idrv_sel_shift     (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_15_pif_p1_txlep_mode_mask         (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_15_pif_p1_txlen_mode_mask         (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_15_pif_p1_txle_ckphs_mask         (0x01000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_15_pif_p1_txle_sr_mask            (0x00080000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_15_pif_p1_txle_term_mask          (0x00000F00)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_15_pif_p1_txle_iem_sel_mask       (0x000000F0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_15_pif_p1_txle_idrv_sel_mask      (0x0000000F)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_15_pif_p1_txlep_mode(data)        (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_15_pif_p1_txlen_mode(data)        (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_15_pif_p1_txle_ckphs(data)        (0x01000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_15_pif_p1_txle_sr(data)           (0x00080000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_15_pif_p1_txle_term(data)         (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_15_pif_p1_txle_iem_sel(data)      (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_15_pif_p1_txle_idrv_sel(data)     (0x0000000F&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_15_get_pif_p1_txlep_mode(data)    ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_15_get_pif_p1_txlen_mode(data)    ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_15_get_pif_p1_txle_ckphs(data)    ((0x01000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_15_get_pif_p1_txle_sr(data)       ((0x00080000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_15_get_pif_p1_txle_term(data)     ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_15_get_pif_p1_txle_iem_sel(data)  ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_15_get_pif_p1_txle_idrv_sel(data) (0x0000000F&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_16                                0x18000C44
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_16_reg_addr                       "0xB8000C44"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_16_reg                            0xB8000C44
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_16_inst_addr                      "0x0012"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_16_reg(data)                  (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_16_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_16_reg                        (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_16_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_16_pif_p1_txlfp_mode_shift        (29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_16_pif_p1_txlfn_mode_shift        (26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_16_pif_p1_txlf_ckphs_shift        (24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_16_pif_p1_txlf_sr_shift           (19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_16_pif_p1_txlf_term_shift         (8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_16_pif_p1_txlf_iem_sel_shift      (4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_16_pif_p1_txlf_idrv_sel_shift     (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_16_pif_p1_txlfp_mode_mask         (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_16_pif_p1_txlfn_mode_mask         (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_16_pif_p1_txlf_ckphs_mask         (0x01000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_16_pif_p1_txlf_sr_mask            (0x00080000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_16_pif_p1_txlf_term_mask          (0x00000F00)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_16_pif_p1_txlf_iem_sel_mask       (0x000000F0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_16_pif_p1_txlf_idrv_sel_mask      (0x0000000F)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_16_pif_p1_txlfp_mode(data)        (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_16_pif_p1_txlfn_mode(data)        (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_16_pif_p1_txlf_ckphs(data)        (0x01000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_16_pif_p1_txlf_sr(data)           (0x00080000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_16_pif_p1_txlf_term(data)         (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_16_pif_p1_txlf_iem_sel(data)      (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_16_pif_p1_txlf_idrv_sel(data)     (0x0000000F&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_16_get_pif_p1_txlfp_mode(data)    ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_16_get_pif_p1_txlfn_mode(data)    ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_16_get_pif_p1_txlf_ckphs(data)    ((0x01000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_16_get_pif_p1_txlf_sr(data)       ((0x00080000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_16_get_pif_p1_txlf_term(data)     ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_16_get_pif_p1_txlf_iem_sel(data)  ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_16_get_pif_p1_txlf_idrv_sel(data) (0x0000000F&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_4                                 0x18000D10
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_4_reg_addr                        "0xB8000D10"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_4_reg                             0xB8000D10
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_4_inst_addr                       "0x0013"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_4_reg(data)                   (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_4_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_4_reg                         (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_4_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_4_pif_p2_txlap_mode_shift         (29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_4_pif_p2_txlan_mode_shift         (26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_4_pif_p2_txla_ckphs_shift         (24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_4_pif_p2_txla_sr_shift            (19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_4_pif_p2_txla_term_shift          (8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_4_pif_p2_txla_iem_sel_shift       (4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_4_pif_p2_txla_idrv_sel_shift      (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_4_pif_p2_txlap_mode_mask          (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_4_pif_p2_txlan_mode_mask          (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_4_pif_p2_txla_ckphs_mask          (0x01000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_4_pif_p2_txla_sr_mask             (0x00080000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_4_pif_p2_txla_term_mask           (0x00000F00)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_4_pif_p2_txla_iem_sel_mask        (0x000000F0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_4_pif_p2_txla_idrv_sel_mask       (0x0000000F)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_4_pif_p2_txlap_mode(data)         (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_4_pif_p2_txlan_mode(data)         (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_4_pif_p2_txla_ckphs(data)         (0x01000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_4_pif_p2_txla_sr(data)            (0x00080000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_4_pif_p2_txla_term(data)          (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_4_pif_p2_txla_iem_sel(data)       (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_4_pif_p2_txla_idrv_sel(data)      (0x0000000F&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_4_get_pif_p2_txlap_mode(data)     ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_4_get_pif_p2_txlan_mode(data)     ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_4_get_pif_p2_txla_ckphs(data)     ((0x01000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_4_get_pif_p2_txla_sr(data)        ((0x00080000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_4_get_pif_p2_txla_term(data)      ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_4_get_pif_p2_txla_iem_sel(data)   ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_4_get_pif_p2_txla_idrv_sel(data)  (0x0000000F&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_5                                 0x18000D14
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_5_reg_addr                        "0xB8000D14"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_5_reg                             0xB8000D14
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_5_inst_addr                       "0x0014"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_5_reg(data)                   (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_5_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_5_reg                         (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_5_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_5_pif_p2_txlbp_mode_shift         (29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_5_pif_p2_txlbn_mode_shift         (26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_5_pif_p2_txlb_ckphs_shift         (24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_5_pif_p2_txlb_sr_shift            (19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_5_pif_p2_txlb_term_shift          (8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_5_pif_p2_txlb_iem_sel_shift       (4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_5_pif_p2_txlb_idrv_sel_shift      (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_5_pif_p2_txlbp_mode_mask          (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_5_pif_p2_txlbn_mode_mask          (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_5_pif_p2_txlb_ckphs_mask          (0x01000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_5_pif_p2_txlb_sr_mask             (0x00080000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_5_pif_p2_txlb_term_mask           (0x00000F00)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_5_pif_p2_txlb_iem_sel_mask        (0x000000F0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_5_pif_p2_txlb_idrv_sel_mask       (0x0000000F)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_5_pif_p2_txlbp_mode(data)         (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_5_pif_p2_txlbn_mode(data)         (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_5_pif_p2_txlb_ckphs(data)         (0x01000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_5_pif_p2_txlb_sr(data)            (0x00080000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_5_pif_p2_txlb_term(data)          (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_5_pif_p2_txlb_iem_sel(data)       (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_5_pif_p2_txlb_idrv_sel(data)      (0x0000000F&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_5_get_pif_p2_txlbp_mode(data)     ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_5_get_pif_p2_txlbn_mode(data)     ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_5_get_pif_p2_txlb_ckphs(data)     ((0x01000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_5_get_pif_p2_txlb_sr(data)        ((0x00080000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_5_get_pif_p2_txlb_term(data)      ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_5_get_pif_p2_txlb_iem_sel(data)   ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_5_get_pif_p2_txlb_idrv_sel(data)  (0x0000000F&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_6                                 0x18000D18
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_6_reg_addr                        "0xB8000D18"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_6_reg                             0xB8000D18
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_6_inst_addr                       "0x0015"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_6_reg(data)                   (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_6_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_6_reg                         (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_6_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_6_pif_p2_txlcp_mode_shift         (29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_6_pif_p2_txlcn_mode_shift         (26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_6_pif_p2_txlc_ckphs_shift         (24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_6_pif_p2_txlc_sr_shift            (19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_6_pif_p2_txlc_term_shift          (8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_6_pif_p2_txlc_iem_sel_shift       (4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_6_pif_p2_txlc_idrv_sel_shift      (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_6_pif_p2_txlcp_mode_mask          (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_6_pif_p2_txlcn_mode_mask          (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_6_pif_p2_txlc_ckphs_mask          (0x01000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_6_pif_p2_txlc_sr_mask             (0x00080000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_6_pif_p2_txlc_term_mask           (0x00000F00)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_6_pif_p2_txlc_iem_sel_mask        (0x000000F0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_6_pif_p2_txlc_idrv_sel_mask       (0x0000000F)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_6_pif_p2_txlcp_mode(data)         (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_6_pif_p2_txlcn_mode(data)         (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_6_pif_p2_txlc_ckphs(data)         (0x01000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_6_pif_p2_txlc_sr(data)            (0x00080000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_6_pif_p2_txlc_term(data)          (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_6_pif_p2_txlc_iem_sel(data)       (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_6_pif_p2_txlc_idrv_sel(data)      (0x0000000F&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_6_get_pif_p2_txlcp_mode(data)     ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_6_get_pif_p2_txlcn_mode(data)     ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_6_get_pif_p2_txlc_ckphs(data)     ((0x01000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_6_get_pif_p2_txlc_sr(data)        ((0x00080000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_6_get_pif_p2_txlc_term(data)      ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_6_get_pif_p2_txlc_iem_sel(data)   ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_6_get_pif_p2_txlc_idrv_sel(data)  (0x0000000F&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_7                                 0x18000D1C
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_7_reg_addr                        "0xB8000D1C"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_7_reg                             0xB8000D1C
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_7_inst_addr                       "0x0016"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_7_reg(data)                   (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_7_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_7_reg                         (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_7_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_7_pif_p2_txldp_mode_shift         (29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_7_pif_p2_txldn_mode_shift         (26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_7_pif_p2_txld_ckphs_shift         (24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_7_pif_p2_txld_sr_shift            (19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_7_pif_p2_txld_term_shift          (8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_7_pif_p2_txld_iem_sel_shift       (4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_7_pif_p2_txld_idrv_sel_shift      (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_7_pif_p2_txldp_mode_mask          (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_7_pif_p2_txldn_mode_mask          (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_7_pif_p2_txld_ckphs_mask          (0x01000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_7_pif_p2_txld_sr_mask             (0x00080000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_7_pif_p2_txld_term_mask           (0x00000F00)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_7_pif_p2_txld_iem_sel_mask        (0x000000F0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_7_pif_p2_txld_idrv_sel_mask       (0x0000000F)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_7_pif_p2_txldp_mode(data)         (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_7_pif_p2_txldn_mode(data)         (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_7_pif_p2_txld_ckphs(data)         (0x01000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_7_pif_p2_txld_sr(data)            (0x00080000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_7_pif_p2_txld_term(data)          (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_7_pif_p2_txld_iem_sel(data)       (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_7_pif_p2_txld_idrv_sel(data)      (0x0000000F&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_7_get_pif_p2_txldp_mode(data)     ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_7_get_pif_p2_txldn_mode(data)     ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_7_get_pif_p2_txld_ckphs(data)     ((0x01000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_7_get_pif_p2_txld_sr(data)        ((0x00080000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_7_get_pif_p2_txld_term(data)      ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_7_get_pif_p2_txld_iem_sel(data)   ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_7_get_pif_p2_txld_idrv_sel(data)  (0x0000000F&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_8                                 0x18000D20
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_8_reg_addr                        "0xB8000D20"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_8_reg                             0xB8000D20
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_8_inst_addr                       "0x0017"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_8_reg(data)                   (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_8_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_8_reg                         (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_8_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_8_pif_p2_txlep_mode_shift         (29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_8_pif_p2_txlen_mode_shift         (26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_8_pif_p2_txle_ckphs_shift         (24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_8_pif_p2_txle_sr_shift            (19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_8_pif_p2_txle_term_shift          (8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_8_pif_p2_txle_iem_sel_shift       (4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_8_pif_p2_txle_idrv_sel_shift      (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_8_pif_p2_txlep_mode_mask          (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_8_pif_p2_txlen_mode_mask          (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_8_pif_p2_txle_ckphs_mask          (0x01000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_8_pif_p2_txle_sr_mask             (0x00080000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_8_pif_p2_txle_term_mask           (0x00000F00)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_8_pif_p2_txle_iem_sel_mask        (0x000000F0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_8_pif_p2_txle_idrv_sel_mask       (0x0000000F)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_8_pif_p2_txlep_mode(data)         (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_8_pif_p2_txlen_mode(data)         (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_8_pif_p2_txle_ckphs(data)         (0x01000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_8_pif_p2_txle_sr(data)            (0x00080000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_8_pif_p2_txle_term(data)          (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_8_pif_p2_txle_iem_sel(data)       (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_8_pif_p2_txle_idrv_sel(data)      (0x0000000F&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_8_get_pif_p2_txlep_mode(data)     ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_8_get_pif_p2_txlen_mode(data)     ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_8_get_pif_p2_txle_ckphs(data)     ((0x01000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_8_get_pif_p2_txle_sr(data)        ((0x00080000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_8_get_pif_p2_txle_term(data)      ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_8_get_pif_p2_txle_iem_sel(data)   ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_8_get_pif_p2_txle_idrv_sel(data)  (0x0000000F&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_9                                 0x18000D24
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_9_reg_addr                        "0xB8000D24"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_9_reg                             0xB8000D24
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_9_inst_addr                       "0x0018"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_9_reg(data)                   (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_9_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_9_reg                         (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_9_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_9_pif_p2_txlfp_mode_shift         (29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_9_pif_p2_txlfn_mode_shift         (26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_9_pif_p2_txlf_ckphs_shift         (24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_9_pif_p2_txlf_sr_shift            (19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_9_pif_p2_txlf_term_shift          (8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_9_pif_p2_txlf_iem_sel_shift       (4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_9_pif_p2_txlf_idrv_sel_shift      (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_9_pif_p2_txlfp_mode_mask          (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_9_pif_p2_txlfn_mode_mask          (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_9_pif_p2_txlf_ckphs_mask          (0x01000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_9_pif_p2_txlf_sr_mask             (0x00080000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_9_pif_p2_txlf_term_mask           (0x00000F00)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_9_pif_p2_txlf_iem_sel_mask        (0x000000F0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_9_pif_p2_txlf_idrv_sel_mask       (0x0000000F)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_9_pif_p2_txlfp_mode(data)         (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_9_pif_p2_txlfn_mode(data)         (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_9_pif_p2_txlf_ckphs(data)         (0x01000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_9_pif_p2_txlf_sr(data)            (0x00080000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_9_pif_p2_txlf_term(data)          (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_9_pif_p2_txlf_iem_sel(data)       (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_9_pif_p2_txlf_idrv_sel(data)      (0x0000000F&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_9_get_pif_p2_txlfp_mode(data)     ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_9_get_pif_p2_txlfn_mode(data)     ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_9_get_pif_p2_txlf_ckphs(data)     ((0x01000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_9_get_pif_p2_txlf_sr(data)        ((0x00080000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_9_get_pif_p2_txlf_term(data)      ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_9_get_pif_p2_txlf_iem_sel(data)   ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_9_get_pif_p2_txlf_idrv_sel(data)  (0x0000000F&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_11                                0x18000D30
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_11_reg_addr                       "0xB8000D30"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_11_reg                            0xB8000D30
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_11_inst_addr                      "0x0019"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_11_reg(data)                  (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_11_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_11_reg                        (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_11_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_11_pif_p3_txlap_mode_shift        (29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_11_pif_p3_txlan_mode_shift        (26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_11_pif_p3_txla_ckphs_shift        (24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_11_pif_p3_txla_sr_shift           (19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_11_pif_p3_txla_term_shift         (8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_11_pif_p3_txla_iem_sel_shift      (4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_11_pif_p3_txla_idrv_sel_shift     (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_11_pif_p3_txlap_mode_mask         (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_11_pif_p3_txlan_mode_mask         (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_11_pif_p3_txla_ckphs_mask         (0x01000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_11_pif_p3_txla_sr_mask            (0x00080000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_11_pif_p3_txla_term_mask          (0x00000F00)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_11_pif_p3_txla_iem_sel_mask       (0x000000F0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_11_pif_p3_txla_idrv_sel_mask      (0x0000000F)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_11_pif_p3_txlap_mode(data)        (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_11_pif_p3_txlan_mode(data)        (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_11_pif_p3_txla_ckphs(data)        (0x01000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_11_pif_p3_txla_sr(data)           (0x00080000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_11_pif_p3_txla_term(data)         (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_11_pif_p3_txla_iem_sel(data)      (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_11_pif_p3_txla_idrv_sel(data)     (0x0000000F&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_11_get_pif_p3_txlap_mode(data)    ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_11_get_pif_p3_txlan_mode(data)    ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_11_get_pif_p3_txla_ckphs(data)    ((0x01000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_11_get_pif_p3_txla_sr(data)       ((0x00080000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_11_get_pif_p3_txla_term(data)     ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_11_get_pif_p3_txla_iem_sel(data)  ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_11_get_pif_p3_txla_idrv_sel(data) (0x0000000F&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_12                                0x18000D34
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_12_reg_addr                       "0xB8000D34"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_12_reg                            0xB8000D34
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_12_inst_addr                      "0x001A"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_12_reg(data)                  (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_12_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_12_reg                        (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_12_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_12_pif_p3_txlbp_mode_shift        (29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_12_pif_p3_txlbn_mode_shift        (26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_12_pif_p3_txlb_ckphs_shift        (24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_12_pif_p3_txlb_sr_shift           (19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_12_pif_p3_txlb_term_shift         (8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_12_pif_p3_txlb_iem_sel_shift      (4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_12_pif_p3_txlb_idrv_sel_shift     (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_12_pif_p3_txlbp_mode_mask         (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_12_pif_p3_txlbn_mode_mask         (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_12_pif_p3_txlb_ckphs_mask         (0x01000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_12_pif_p3_txlb_sr_mask            (0x00080000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_12_pif_p3_txlb_term_mask          (0x00000F00)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_12_pif_p3_txlb_iem_sel_mask       (0x000000F0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_12_pif_p3_txlb_idrv_sel_mask      (0x0000000F)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_12_pif_p3_txlbp_mode(data)        (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_12_pif_p3_txlbn_mode(data)        (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_12_pif_p3_txlb_ckphs(data)        (0x01000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_12_pif_p3_txlb_sr(data)           (0x00080000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_12_pif_p3_txlb_term(data)         (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_12_pif_p3_txlb_iem_sel(data)      (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_12_pif_p3_txlb_idrv_sel(data)     (0x0000000F&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_12_get_pif_p3_txlbp_mode(data)    ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_12_get_pif_p3_txlbn_mode(data)    ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_12_get_pif_p3_txlb_ckphs(data)    ((0x01000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_12_get_pif_p3_txlb_sr(data)       ((0x00080000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_12_get_pif_p3_txlb_term(data)     ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_12_get_pif_p3_txlb_iem_sel(data)  ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_12_get_pif_p3_txlb_idrv_sel(data) (0x0000000F&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_13                                0x18000D38
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_13_reg_addr                       "0xB8000D38"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_13_reg                            0xB8000D38
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_13_inst_addr                      "0x001B"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_13_reg(data)                  (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_13_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_13_reg                        (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_13_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_13_pif_p3_txlcp_mode_shift        (29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_13_pif_p3_txlcn_mode_shift        (26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_13_pif_p3_txlc_ckphs_shift        (24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_13_pif_p3_txlc_sr_shift           (19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_13_pif_p3_txlc_term_shift         (8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_13_pif_p3_txlc_iem_sel_shift      (4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_13_pif_p3_txlc_idrv_sel_shift     (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_13_pif_p3_txlcp_mode_mask         (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_13_pif_p3_txlcn_mode_mask         (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_13_pif_p3_txlc_ckphs_mask         (0x01000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_13_pif_p3_txlc_sr_mask            (0x00080000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_13_pif_p3_txlc_term_mask          (0x00000F00)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_13_pif_p3_txlc_iem_sel_mask       (0x000000F0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_13_pif_p3_txlc_idrv_sel_mask      (0x0000000F)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_13_pif_p3_txlcp_mode(data)        (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_13_pif_p3_txlcn_mode(data)        (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_13_pif_p3_txlc_ckphs(data)        (0x01000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_13_pif_p3_txlc_sr(data)           (0x00080000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_13_pif_p3_txlc_term(data)         (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_13_pif_p3_txlc_iem_sel(data)      (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_13_pif_p3_txlc_idrv_sel(data)     (0x0000000F&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_13_get_pif_p3_txlcp_mode(data)    ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_13_get_pif_p3_txlcn_mode(data)    ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_13_get_pif_p3_txlc_ckphs(data)    ((0x01000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_13_get_pif_p3_txlc_sr(data)       ((0x00080000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_13_get_pif_p3_txlc_term(data)     ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_13_get_pif_p3_txlc_iem_sel(data)  ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_13_get_pif_p3_txlc_idrv_sel(data) (0x0000000F&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_14                                0x18000D3C
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_14_reg_addr                       "0xB8000D3C"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_14_reg                            0xB8000D3C
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_14_inst_addr                      "0x001C"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_14_reg(data)                  (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_14_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_14_reg                        (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_14_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_14_pif_p3_txldp_mode_shift        (29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_14_pif_p3_txldn_mode_shift        (26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_14_pif_p3_txld_ckphs_shift        (24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_14_pif_p3_txld_sr_shift           (19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_14_pif_p3_txld_term_shift         (8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_14_pif_p3_txld_iem_sel_shift      (4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_14_pif_p3_txld_idrv_sel_shift     (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_14_pif_p3_txldp_mode_mask         (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_14_pif_p3_txldn_mode_mask         (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_14_pif_p3_txld_ckphs_mask         (0x01000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_14_pif_p3_txld_sr_mask            (0x00080000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_14_pif_p3_txld_term_mask          (0x00000F00)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_14_pif_p3_txld_iem_sel_mask       (0x000000F0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_14_pif_p3_txld_idrv_sel_mask      (0x0000000F)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_14_pif_p3_txldp_mode(data)        (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_14_pif_p3_txldn_mode(data)        (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_14_pif_p3_txld_ckphs(data)        (0x01000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_14_pif_p3_txld_sr(data)           (0x00080000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_14_pif_p3_txld_term(data)         (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_14_pif_p3_txld_iem_sel(data)      (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_14_pif_p3_txld_idrv_sel(data)     (0x0000000F&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_14_get_pif_p3_txldp_mode(data)    ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_14_get_pif_p3_txldn_mode(data)    ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_14_get_pif_p3_txld_ckphs(data)    ((0x01000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_14_get_pif_p3_txld_sr(data)       ((0x00080000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_14_get_pif_p3_txld_term(data)     ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_14_get_pif_p3_txld_iem_sel(data)  ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_14_get_pif_p3_txld_idrv_sel(data) (0x0000000F&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_15                                0x18000D40
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_15_reg_addr                       "0xB8000D40"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_15_reg                            0xB8000D40
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_15_inst_addr                      "0x001D"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_15_reg(data)                  (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_15_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_15_reg                        (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_15_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_15_pif_p3_txlep_mode_shift        (29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_15_pif_p3_txlen_mode_shift        (26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_15_pif_p3_txle_ckphs_shift        (24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_15_pif_p3_txle_sr_shift           (19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_15_pif_p3_txle_term_shift         (8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_15_pif_p3_txle_iem_sel_shift      (4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_15_pif_p3_txle_idrv_sel_shift     (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_15_pif_p3_txlep_mode_mask         (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_15_pif_p3_txlen_mode_mask         (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_15_pif_p3_txle_ckphs_mask         (0x01000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_15_pif_p3_txle_sr_mask            (0x00080000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_15_pif_p3_txle_term_mask          (0x00000F00)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_15_pif_p3_txle_iem_sel_mask       (0x000000F0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_15_pif_p3_txle_idrv_sel_mask      (0x0000000F)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_15_pif_p3_txlep_mode(data)        (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_15_pif_p3_txlen_mode(data)        (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_15_pif_p3_txle_ckphs(data)        (0x01000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_15_pif_p3_txle_sr(data)           (0x00080000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_15_pif_p3_txle_term(data)         (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_15_pif_p3_txle_iem_sel(data)      (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_15_pif_p3_txle_idrv_sel(data)     (0x0000000F&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_15_get_pif_p3_txlep_mode(data)    ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_15_get_pif_p3_txlen_mode(data)    ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_15_get_pif_p3_txle_ckphs(data)    ((0x01000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_15_get_pif_p3_txle_sr(data)       ((0x00080000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_15_get_pif_p3_txle_term(data)     ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_15_get_pif_p3_txle_iem_sel(data)  ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_15_get_pif_p3_txle_idrv_sel(data) (0x0000000F&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_16                                0x18000D44
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_16_reg_addr                       "0xB8000D44"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_16_reg                            0xB8000D44
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_16_inst_addr                      "0x001E"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_16_reg(data)                  (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_16_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_16_reg                        (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_16_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_16_pif_p3_txlfp_mode_shift        (29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_16_pif_p3_txlfn_mode_shift        (26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_16_pif_p3_txlf_ckphs_shift        (24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_16_pif_p3_txlf_sr_shift           (19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_16_pif_p3_txlf_term_shift         (8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_16_pif_p3_txlf_iem_sel_shift      (4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_16_pif_p3_txlf_idrv_sel_shift     (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_16_pif_p3_txlfp_mode_mask         (0xE0000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_16_pif_p3_txlfn_mode_mask         (0x1C000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_16_pif_p3_txlf_ckphs_mask         (0x01000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_16_pif_p3_txlf_sr_mask            (0x00080000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_16_pif_p3_txlf_term_mask          (0x00000F00)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_16_pif_p3_txlf_iem_sel_mask       (0x000000F0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_16_pif_p3_txlf_idrv_sel_mask      (0x0000000F)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_16_pif_p3_txlfp_mode(data)        (0xE0000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_16_pif_p3_txlfn_mode(data)        (0x1C000000&((data)<<26))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_16_pif_p3_txlf_ckphs(data)        (0x01000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_16_pif_p3_txlf_sr(data)           (0x00080000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_16_pif_p3_txlf_term(data)         (0x00000F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_16_pif_p3_txlf_iem_sel(data)      (0x000000F0&((data)<<4))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_16_pif_p3_txlf_idrv_sel(data)     (0x0000000F&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_16_get_pif_p3_txlfp_mode(data)    ((0xE0000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_16_get_pif_p3_txlfn_mode(data)    ((0x1C000000&(data))>>26)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_16_get_pif_p3_txlf_ckphs(data)    ((0x01000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_16_get_pif_p3_txlf_sr(data)       ((0x00080000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_16_get_pif_p3_txlf_term(data)     ((0x00000F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_16_get_pif_p3_txlf_iem_sel(data)  ((0x000000F0&(data))>>4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_16_get_pif_p3_txlf_idrv_sel(data) (0x0000000F&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_10                                0x18000C28
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_10_reg_addr                       "0xB8000C28"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_10_reg                            0xB8000C28
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_10_inst_addr                      "0x001F"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_10_reg(data)                  (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_10_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_10_reg                        (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_10_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_10_pif_p0_txl_ck7x_delay_shift    (30)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_10_pif_p0_txl_ck7x_inv_shift      (29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_10_pif_p0_txl_cm_mode_shift       (27)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_10_pif_p0_txl_ck7x_delay_mask     (0xC0000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_10_pif_p0_txl_ck7x_inv_mask       (0x20000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_10_pif_p0_txl_cm_mode_mask        (0x08000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_10_pif_p0_txl_ck7x_delay(data)    (0xC0000000&((data)<<30))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_10_pif_p0_txl_ck7x_inv(data)      (0x20000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_10_pif_p0_txl_cm_mode(data)       (0x08000000&((data)<<27))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_10_get_pif_p0_txl_ck7x_delay(data) ((0xC0000000&(data))>>30)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_10_get_pif_p0_txl_ck7x_inv(data)  ((0x20000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_10_get_pif_p0_txl_cm_mode(data)   ((0x08000000&(data))>>27)

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_17                                0x18000C48
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_17_reg_addr                       "0xB8000C48"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_17_reg                            0xB8000C48
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_17_inst_addr                      "0x0020"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_17_reg(data)                  (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_17_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_17_reg                        (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_17_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_17_pif_p1_txl_ck7x_delay_shift    (30)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_17_pif_p1_txl_ck7x_inv_shift      (29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_17_pif_p1_txl_cm_mode_shift       (27)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_17_pif_p1_txl_ck7x_delay_mask     (0xC0000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_17_pif_p1_txl_ck7x_inv_mask       (0x20000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_17_pif_p1_txl_cm_mode_mask        (0x08000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_17_pif_p1_txl_ck7x_delay(data)    (0xC0000000&((data)<<30))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_17_pif_p1_txl_ck7x_inv(data)      (0x20000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_17_pif_p1_txl_cm_mode(data)       (0x08000000&((data)<<27))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_17_get_pif_p1_txl_ck7x_delay(data) ((0xC0000000&(data))>>30)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_17_get_pif_p1_txl_ck7x_inv(data)  ((0x20000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_17_get_pif_p1_txl_cm_mode(data)   ((0x08000000&(data))>>27)

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_10                                0x18000D28
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_10_reg_addr                       "0xB8000D28"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_10_reg                            0xB8000D28
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_10_inst_addr                      "0x0021"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_10_reg(data)                  (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_10_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_10_reg                        (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_10_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_10_pif_p2_txl_ck7x_delay_shift    (30)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_10_pif_p2_txl_ck7x_inv_shift      (29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_10_pif_p2_txl_cm_mode_shift       (27)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_10_pif_p2_txl_ck7x_delay_mask     (0xC0000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_10_pif_p2_txl_ck7x_inv_mask       (0x20000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_10_pif_p2_txl_cm_mode_mask        (0x08000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_10_pif_p2_txl_ck7x_delay(data)    (0xC0000000&((data)<<30))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_10_pif_p2_txl_ck7x_inv(data)      (0x20000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_10_pif_p2_txl_cm_mode(data)       (0x08000000&((data)<<27))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_10_get_pif_p2_txl_ck7x_delay(data) ((0xC0000000&(data))>>30)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_10_get_pif_p2_txl_ck7x_inv(data)  ((0x20000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_10_get_pif_p2_txl_cm_mode(data)   ((0x08000000&(data))>>27)

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_17                                0x18000D48
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_17_reg_addr                       "0xB8000D48"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_17_reg                            0xB8000D48
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_17_inst_addr                      "0x0022"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_17_reg(data)                  (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_17_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_17_reg                        (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_17_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_17_pif_p3_txl_ck7x_delay_shift    (30)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_17_pif_p3_txl_ck7x_inv_shift      (29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_17_pif_p3_txl_cm_mode_shift       (27)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_17_pif_p3_txl_ck7x_delay_mask     (0xC0000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_17_pif_p3_txl_ck7x_inv_mask       (0x20000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_17_pif_p3_txl_cm_mode_mask        (0x08000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_17_pif_p3_txl_ck7x_delay(data)    (0xC0000000&((data)<<30))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_17_pif_p3_txl_ck7x_inv(data)      (0x20000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_17_pif_p3_txl_cm_mode(data)       (0x08000000&((data)<<27))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_17_get_pif_p3_txl_ck7x_delay(data) ((0xC0000000&(data))>>30)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_17_get_pif_p3_txl_ck7x_inv(data)  ((0x20000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_17_get_pif_p3_txl_cm_mode(data)   ((0x08000000&(data))>>27)

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_18                                0x18000D50
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_18_reg_addr                       "0xB8000D50"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_18_reg                            0xB8000D50
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_18_inst_addr                      "0x0023"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_18_reg(data)                  (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_18_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_18_reg                        (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_18_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_18_pif_y_sel_test_shift           (28)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_18_pif_y_sel_test_mask            (0x30000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_18_pif_y_sel_test(data)           (0x30000000&((data)<<28))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_18_get_pif_y_sel_test(data)       ((0x30000000&(data))>>28)

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_0                                 0x18000C00
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_0_reg_addr                        "0xB8000C00"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_0_reg                             0xB8000C00
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_0_inst_addr                       "0x0024"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_0_reg(data)                   (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_0_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_0_reg                         (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_0_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_0_pif_a1_pi_phsel_shift           (20)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_0_pif_a1_sel_2xi_shift            (19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_0_pif_a2_pi_phsel_shift           (7)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_0_pif_a2_sel_2xi_shift            (6)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_0_pif_a_pi_freq_shift             (4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_0_pif_sbg_shift                   (1)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_0_pif_a1_pi_phsel_mask            (0xFFF00000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_0_pif_a1_sel_2xi_mask             (0x00080000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_0_pif_a2_pi_phsel_mask            (0x0007FF80)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_0_pif_a2_sel_2xi_mask             (0x00000040)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_0_pif_a_pi_freq_mask              (0x00000030)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_0_pif_sbg_mask                    (0x00000006)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_0_pif_a1_pi_phsel(data)           (0xFFF00000&((data)<<20))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_0_pif_a1_sel_2xi(data)            (0x00080000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_0_pif_a2_pi_phsel(data)           (0x0007FF80&((data)<<7))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_0_pif_a2_sel_2xi(data)            (0x00000040&((data)<<6))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_0_pif_a_pi_freq(data)             (0x00000030&((data)<<4))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_0_pif_sbg(data)                   (0x00000006&((data)<<1))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_0_get_pif_a1_pi_phsel(data)       ((0xFFF00000&(data))>>20)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_0_get_pif_a1_sel_2xi(data)        ((0x00080000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_0_get_pif_a2_pi_phsel(data)       ((0x0007FF80&(data))>>7)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_0_get_pif_a2_sel_2xi(data)        ((0x00000040&(data))>>6)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_0_get_pif_a_pi_freq(data)         ((0x00000030&(data))>>4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_0_get_pif_sbg(data)               ((0x00000006&(data))>>1)

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_2                                 0x18000C08
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_2_reg_addr                        "0xB8000C08"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_2_reg                             0xB8000C08
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_2_inst_addr                       "0x0025"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_2_reg(data)                   (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_2_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_2_reg                         (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_2_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_2_pif_ab_pi_phsel_shift           (20)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_2_pif_ab_freq_shift               (18)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_2_pif_ab_sel_2xi_shift            (17)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_2_pif_h_cmu_sel_lv_vldo_shift     (8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_2_pif_h_cmu_mode_shift            (4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_2_pif_h_cmu_bw_set_shift          (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_2_pif_ab_pi_phsel_mask            (0xFFF00000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_2_pif_ab_freq_mask                (0x000C0000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_2_pif_ab_sel_2xi_mask             (0x00020000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_2_pif_h_cmu_sel_lv_vldo_mask      (0x00000300)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_2_pif_h_cmu_mode_mask             (0x00000030)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_2_pif_h_cmu_bw_set_mask           (0x00000003)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_2_pif_ab_pi_phsel(data)           (0xFFF00000&((data)<<20))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_2_pif_ab_freq(data)               (0x000C0000&((data)<<18))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_2_pif_ab_sel_2xi(data)            (0x00020000&((data)<<17))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_2_pif_h_cmu_sel_lv_vldo(data)     (0x00000300&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_2_pif_h_cmu_mode(data)            (0x00000030&((data)<<4))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_2_pif_h_cmu_bw_set(data)          (0x00000003&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_2_get_pif_ab_pi_phsel(data)       ((0xFFF00000&(data))>>20)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_2_get_pif_ab_freq(data)           ((0x000C0000&(data))>>18)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_2_get_pif_ab_sel_2xi(data)        ((0x00020000&(data))>>17)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_2_get_pif_h_cmu_sel_lv_vldo(data) ((0x00000300&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_2_get_pif_h_cmu_mode(data)        ((0x00000030&(data))>>4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_2_get_pif_h_cmu_bw_set(data)      (0x00000003&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_1                                 0x18000C04
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_1_reg_addr                        "0xB8000C04"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_1_reg                             0xB8000C04
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_1_inst_addr                       "0x0026"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_1_reg(data)                   (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_1_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_1_reg                         (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_1_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_1_pif_b1_pi_phsel_shift           (20)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_1_pif_b1_sel_2xi_shift            (19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_1_pif_b2_pi_phsel_shift           (7)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_1_pif_b2_sel_2xi_shift            (6)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_1_pif_b_pi_freq_shift             (4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_1_pif_b1_pi_phsel_mask            (0xFFF00000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_1_pif_b1_sel_2xi_mask             (0x00080000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_1_pif_b2_pi_phsel_mask            (0x0007FF80)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_1_pif_b2_sel_2xi_mask             (0x00000040)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_1_pif_b_pi_freq_mask              (0x00000030)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_1_pif_b1_pi_phsel(data)           (0xFFF00000&((data)<<20))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_1_pif_b1_sel_2xi(data)            (0x00080000&((data)<<19))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_1_pif_b2_pi_phsel(data)           (0x0007FF80&((data)<<7))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_1_pif_b2_sel_2xi(data)            (0x00000040&((data)<<6))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_1_pif_b_pi_freq(data)             (0x00000030&((data)<<4))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_1_get_pif_b1_pi_phsel(data)       ((0xFFF00000&(data))>>20)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_1_get_pif_b1_sel_2xi(data)        ((0x00080000&(data))>>19)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_1_get_pif_b2_pi_phsel(data)       ((0x0007FF80&(data))>>7)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_1_get_pif_b2_sel_2xi(data)        ((0x00000040&(data))>>6)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_1_get_pif_b_pi_freq(data)         ((0x00000030&(data))>>4)

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3                                 0x18000C0C
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_reg_addr                        "0xB8000C0C"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_reg                             0xB8000C0C
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_inst_addr                       "0x0027"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_reg(data)                   (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_reg                         (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_big_kvco_shift          (31)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_ckpixel_inv_shift       (30)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_ck_ref_inv_shift        (29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_ck_ref_sel_shift        (20)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_sel_cp_i_shift          (16)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_sel_sc1_shift           (13)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_sel_sc2_shift           (11)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_sel_sr_shift            (8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_sel_vldo_shift          (6)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_a_pi_bypass_shift       (5)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_b_pi_bypass_shift       (4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_hsdelay_sel_shift       (3)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_wdrst_shift             (2)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_wdset_shift             (1)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_cmu_wdo_shift                   (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_big_kvco_mask           (0x80000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_ckpixel_inv_mask        (0x40000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_ck_ref_inv_mask         (0x20000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_ck_ref_sel_mask         (0x00100000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_sel_cp_i_mask           (0x000F0000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_sel_sc1_mask            (0x0000E000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_sel_sc2_mask            (0x00001800)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_sel_sr_mask             (0x00000700)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_sel_vldo_mask           (0x000000C0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_a_pi_bypass_mask        (0x00000020)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_b_pi_bypass_mask        (0x00000010)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_hsdelay_sel_mask        (0x00000008)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_wdrst_mask              (0x00000004)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_wdset_mask              (0x00000002)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_cmu_wdo_mask                    (0x00000001)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_big_kvco(data)          (0x80000000&((data)<<31))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_ckpixel_inv(data)       (0x40000000&((data)<<30))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_ck_ref_inv(data)        (0x20000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_ck_ref_sel(data)        (0x00100000&((data)<<20))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_sel_cp_i(data)          (0x000F0000&((data)<<16))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_sel_sc1(data)           (0x0000E000&((data)<<13))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_sel_sc2(data)           (0x00001800&((data)<<11))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_sel_sr(data)            (0x00000700&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_sel_vldo(data)          (0x000000C0&((data)<<6))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_a_pi_bypass(data)       (0x00000020&((data)<<5))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_b_pi_bypass(data)       (0x00000010&((data)<<4))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_hsdelay_sel(data)       (0x00000008&((data)<<3))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_wdrst(data)             (0x00000004&((data)<<2))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_pif_cmu_wdset(data)             (0x00000002&((data)<<1))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_cmu_wdo(data)                   (0x00000001&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_get_pif_cmu_big_kvco(data)      ((0x80000000&(data))>>31)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_get_pif_cmu_ckpixel_inv(data)   ((0x40000000&(data))>>30)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_get_pif_cmu_ck_ref_inv(data)    ((0x20000000&(data))>>29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_get_pif_cmu_ck_ref_sel(data)    ((0x00100000&(data))>>20)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_get_pif_cmu_sel_cp_i(data)      ((0x000F0000&(data))>>16)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_get_pif_cmu_sel_sc1(data)       ((0x0000E000&(data))>>13)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_get_pif_cmu_sel_sc2(data)       ((0x00001800&(data))>>11)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_get_pif_cmu_sel_sr(data)        ((0x00000700&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_get_pif_cmu_sel_vldo(data)      ((0x000000C0&(data))>>6)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_get_pif_cmu_a_pi_bypass(data)   ((0x00000020&(data))>>5)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_get_pif_cmu_b_pi_bypass(data)   ((0x00000010&(data))>>4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_get_pif_cmu_hsdelay_sel(data)   ((0x00000008&(data))>>3)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_get_pif_cmu_wdrst(data)         ((0x00000004&(data))>>2)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_get_pif_cmu_wdset(data)         ((0x00000002&(data))>>1)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_get_cmu_wdo(data)               (0x00000001&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18                                0x18000C50
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_reg_addr                       "0xB8000C50"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_reg                            0xB8000C50
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_inst_addr                      "0x0028"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_reg(data)                  (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_reg                        (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_pif_x_sel_test_shift           (28)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_pif_sel_tx_i_shift             (22)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_pif_sel_vcm_shift              (17)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_pif_en_test_shift              (16)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_pif_en_lv_ldo_shift            (15)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_pif_en_txl_ldo_shift           (14)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_pif_p3_sel_txl_vldo_shift      (8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_pif_p2_sel_txl_vldo_shift      (6)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_pif_p1_sel_txl_vldo_shift      (4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_pif_p0_sel_txl_vldo_shift      (2)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_pif_hs_biasmode_shift          (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_pif_x_sel_test_mask            (0x30000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_pif_sel_tx_i_mask              (0x03C00000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_pif_sel_vcm_mask               (0x003E0000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_pif_en_test_mask               (0x00010000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_pif_en_lv_ldo_mask             (0x00008000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_pif_en_txl_ldo_mask            (0x00004000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_pif_p3_sel_txl_vldo_mask       (0x00000300)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_pif_p2_sel_txl_vldo_mask       (0x000000C0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_pif_p1_sel_txl_vldo_mask       (0x00000030)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_pif_p0_sel_txl_vldo_mask       (0x0000000C)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_pif_hs_biasmode_mask           (0x00000003)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_pif_x_sel_test(data)           (0x30000000&((data)<<28))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_pif_sel_tx_i(data)             (0x03C00000&((data)<<22))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_pif_sel_vcm(data)              (0x003E0000&((data)<<17))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_pif_en_test(data)              (0x00010000&((data)<<16))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_pif_en_lv_ldo(data)            (0x00008000&((data)<<15))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_pif_en_txl_ldo(data)           (0x00004000&((data)<<14))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_pif_p3_sel_txl_vldo(data)      (0x00000300&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_pif_p2_sel_txl_vldo(data)      (0x000000C0&((data)<<6))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_pif_p1_sel_txl_vldo(data)      (0x00000030&((data)<<4))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_pif_p0_sel_txl_vldo(data)      (0x0000000C&((data)<<2))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_pif_hs_biasmode(data)          (0x00000003&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_get_pif_x_sel_test(data)       ((0x30000000&(data))>>28)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_get_pif_sel_tx_i(data)         ((0x03C00000&(data))>>22)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_get_pif_sel_vcm(data)          ((0x003E0000&(data))>>17)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_get_pif_en_test(data)          ((0x00010000&(data))>>16)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_get_pif_en_lv_ldo(data)        ((0x00008000&(data))>>15)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_get_pif_en_txl_ldo(data)       ((0x00004000&(data))>>14)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_get_pif_p3_sel_txl_vldo(data)  ((0x00000300&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_get_pif_p2_sel_txl_vldo(data)  ((0x000000C0&(data))>>6)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_get_pif_p1_sel_txl_vldo(data)  ((0x00000030&(data))>>4)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_get_pif_p0_sel_txl_vldo(data)  ((0x0000000C&(data))>>2)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_get_pif_hs_biasmode(data)      (0x00000003&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_19                                0x18000C54
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_19_reg_addr                       "0xB8000C54"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_19_reg                            0xB8000C54
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_19_inst_addr                      "0x0029"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_19_reg(data)                  (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_19_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_19_reg                        (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_19_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_19_pif_p0_txl_ck1x_delay_shift    (29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_19_pif_p0_txl_ck1x_delay_mask     (0x60000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_19_pif_p0_txl_ck1x_delay(data)    (0x60000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_19_get_pif_p0_txl_ck1x_delay(data) ((0x60000000&(data))>>29)

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_21                                0x18000C5C
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_21_reg_addr                       "0xB8000C5C"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_21_reg                            0xB8000C5C
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_21_inst_addr                      "0x002A"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_21_reg(data)                  (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_21_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_21_reg                        (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_21_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_21_pif_p1_txl_ck1x_delay_shift    (29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_21_pif_p1_txl_ck1x_delay_mask     (0x60000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_21_pif_p1_txl_ck1x_delay(data)    (0x60000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_21_get_pif_p1_txl_ck1x_delay(data) ((0x60000000&(data))>>29)

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_19                                0x18000D54
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_19_reg_addr                       "0xB8000D54"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_19_reg                            0xB8000D54
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_19_inst_addr                      "0x002B"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_19_reg(data)                  (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_19_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_19_reg                        (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_19_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_19_pif_p2_txl_ck1x_delay_shift    (29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_19_pif_p2_txl_ck1x_delay_mask     (0x60000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_19_pif_p2_txl_ck1x_delay(data)    (0x60000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_19_get_pif_p2_txl_ck1x_delay(data) ((0x60000000&(data))>>29)

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_21                                0x18000D5C
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_21_reg_addr                       "0xB8000D5C"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_21_reg                            0xB8000D5C
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_21_inst_addr                      "0x002C"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_21_reg(data)                  (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_21_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_21_reg                        (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_21_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_21_pif_p3_txl_ck1x_delay_shift    (29)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_21_pif_p3_txl_ck1x_delay_mask     (0x60000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_21_pif_p3_txl_ck1x_delay(data)    (0x60000000&((data)<<29))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_21_get_pif_p3_txl_ck1x_delay(data) ((0x60000000&(data))>>29)

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_2                                 0x18000D78
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_2_reg_addr                        "0xB8000D78"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_2_reg                             0xB8000D78
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_2_inst_addr                       "0x002D"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_2_reg(data)                   (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_2_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_2_reg                         (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_2_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_2_pif_dpll_sel_lv_vldo_shift      (28)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_2_pif_dpll_sel_lv_vldo_mask       (0x30000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_2_pif_dpll_sel_lv_vldo(data)      (0x30000000&((data)<<28))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_2_get_pif_dpll_sel_lv_vldo(data)  ((0x30000000&(data))>>28)

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_27                                0x18000C74
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_27_reg_addr                       "0xB8000C74"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_27_reg                            0xB8000C74
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_27_inst_addr                      "0x002E"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_27_reg(data)                  (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_27_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_27_reg                        (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_27_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_27_pow_pif_shift                  (31)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_27_pow_pif_mask                   (0x80000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_27_pow_pif(data)                  (0x80000000&((data)<<31))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_27_get_pow_pif(data)              ((0x80000000&(data))>>31)

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_3                                 0x18000D7C
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_3_reg_addr                        "0xB8000D7C"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_3_reg                             0xB8000D7C
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_3_inst_addr                       "0x002F"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_3_reg(data)                   (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_3_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_3_reg                         (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_3_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_3_lvds_dummy_shift                (16)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_3_pif_p3_ttl_str_shift            (15)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_3_pif_p2_ttl_str_shift            (14)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_3_pif_p1_ttl_str_shift            (13)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_3_pif_p0_ttl_str_shift            (12)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_3_pif_h_cmu_rstb_shift            (10)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_3_pif_h_cmu_pow_shift             (9)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_3_lvds_dummy_mask                 (0xFFFF0000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_3_pif_p3_ttl_str_mask             (0x00008000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_3_pif_p2_ttl_str_mask             (0x00004000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_3_pif_p1_ttl_str_mask             (0x00002000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_3_pif_p0_ttl_str_mask             (0x00001000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_3_pif_h_cmu_rstb_mask             (0x00000400)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_3_pif_h_cmu_pow_mask              (0x00000200)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_3_lvds_dummy(data)                (0xFFFF0000&((data)<<16))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_3_pif_p3_ttl_str(data)            (0x00008000&((data)<<15))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_3_pif_p2_ttl_str(data)            (0x00004000&((data)<<14))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_3_pif_p1_ttl_str(data)            (0x00002000&((data)<<13))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_3_pif_p0_ttl_str(data)            (0x00001000&((data)<<12))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_3_pif_h_cmu_rstb(data)            (0x00000400&((data)<<10))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_3_pif_h_cmu_pow(data)             (0x00000200&((data)<<9))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_3_get_lvds_dummy(data)            ((0xFFFF0000&(data))>>16)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_3_get_pif_p3_ttl_str(data)        ((0x00008000&(data))>>15)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_3_get_pif_p2_ttl_str(data)        ((0x00004000&(data))>>14)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_3_get_pif_p1_ttl_str(data)        ((0x00002000&(data))>>13)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_3_get_pif_p0_ttl_str(data)        ((0x00001000&(data))>>12)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_3_get_pif_h_cmu_rstb(data)        ((0x00000400&(data))>>10)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_3_get_pif_h_cmu_pow(data)         ((0x00000200&(data))>>9)

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2                                 0x18000D88
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_reg_addr                        "0xB8000D88"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_reg                             0xB8000D88
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_inst_addr                       "0x0030"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_reg(data)                   (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_reg                         (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_pif_h_cmu_test_en_shift         (31)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_pif_h_cmu_lvdscmpi_divm_shift   (25)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_pif_h_cmu_test_sel_shift        (23)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_pif_h_cmu_ck20xp_inv_shift      (21)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_pif_h_cmu_ck1xp_inv_shift       (20)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_pif_h_cmu_tst_div_shift         (16)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_pif_h_cmu_prescalerdiv_ls_shift (12)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_pif_h_cmu_prescalerdiv_hs_shift (8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_pif_h_cmu_epi_div_sel_shift     (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_pif_h_cmu_test_en_mask          (0x80000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_pif_h_cmu_lvdscmpi_divm_mask    (0x7E000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_pif_h_cmu_test_sel_mask         (0x00800000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_pif_h_cmu_ck20xp_inv_mask       (0x00200000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_pif_h_cmu_ck1xp_inv_mask        (0x00100000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_pif_h_cmu_tst_div_mask          (0x00070000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_pif_h_cmu_prescalerdiv_ls_mask  (0x00007000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_pif_h_cmu_prescalerdiv_hs_mask  (0x00000300)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_pif_h_cmu_epi_div_sel_mask      (0x00000007)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_pif_h_cmu_test_en(data)         (0x80000000&((data)<<31))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_pif_h_cmu_lvdscmpi_divm(data)   (0x7E000000&((data)<<25))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_pif_h_cmu_test_sel(data)        (0x00800000&((data)<<23))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_pif_h_cmu_ck20xp_inv(data)      (0x00200000&((data)<<21))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_pif_h_cmu_ck1xp_inv(data)       (0x00100000&((data)<<20))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_pif_h_cmu_tst_div(data)         (0x00070000&((data)<<16))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_pif_h_cmu_prescalerdiv_ls(data) (0x00007000&((data)<<12))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_pif_h_cmu_prescalerdiv_hs(data) (0x00000300&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_pif_h_cmu_epi_div_sel(data)     (0x00000007&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_get_pif_h_cmu_test_en(data)     ((0x80000000&(data))>>31)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_get_pif_h_cmu_lvdscmpi_divm(data) ((0x7E000000&(data))>>25)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_get_pif_h_cmu_test_sel(data)    ((0x00800000&(data))>>23)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_get_pif_h_cmu_ck20xp_inv(data)  ((0x00200000&(data))>>21)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_get_pif_h_cmu_ck1xp_inv(data)   ((0x00100000&(data))>>20)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_get_pif_h_cmu_tst_div(data)     ((0x00070000&(data))>>16)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_get_pif_h_cmu_prescalerdiv_ls(data) ((0x00007000&(data))>>12)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_get_pif_h_cmu_prescalerdiv_hs(data) ((0x00000300&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_get_pif_h_cmu_epi_div_sel(data) (0x00000007&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_4                                 0x18000D80
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_4_reg_addr                        "0xB8000D80"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_4_reg                             0xB8000D80
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_4_inst_addr                       "0x0031"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_4_reg(data)                   (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_4_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_4_reg                         (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_4_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_4_pif_h_cmu_dummy_shift           (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_4_pif_h_cmu_dummy_mask            (0x000003FF)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_4_pif_h_cmu_dummy(data)           (0x000003FF&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_4_get_pif_h_cmu_dummy(data)       (0x000003FF&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_5                                 0x18000C78
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_5_reg_addr                        "0xB8000C78"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_5_reg                             0xB8000C78
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_5_inst_addr                       "0x0032"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_5_reg(data)                   (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_5_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_5_reg                         (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_5_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_5_txpll_ckin_div_n_shift          (8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_5_txpll_prediv_bypass_shift       (5)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_5_txpll_ckin_div_n_mask           (0x00003F00)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_5_txpll_prediv_bypass_mask        (0x00000020)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_5_txpll_ckin_div_n(data)          (0x00003F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_5_txpll_prediv_bypass(data)       (0x00000020&((data)<<5))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_5_get_txpll_ckin_div_n(data)      ((0x00003F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_5_get_txpll_prediv_bypass(data)   ((0x00000020&(data))>>5)

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_22                                0x18000D90
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_22_reg_addr                       "0xB8000D90"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_22_reg                            0xB8000D90
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_22_inst_addr                      "0x0033"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_22_reg(data)                  (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_22_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_22_reg                        (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_22_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_22_pow_pif_p3_txl_shift           (24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_22_pow_pif_p2_txl_shift           (16)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_22_pow_pif_p1_txl_shift           (8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_22_pow_pif_p0_txl_shift           (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_22_pow_pif_p3_txl_mask            (0x3F000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_22_pow_pif_p2_txl_mask            (0x003F0000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_22_pow_pif_p1_txl_mask            (0x00003F00)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_22_pow_pif_p0_txl_mask            (0x0000003F)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_22_pow_pif_p3_txl(data)           (0x3F000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_22_pow_pif_p2_txl(data)           (0x003F0000&((data)<<16))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_22_pow_pif_p1_txl(data)           (0x00003F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_22_pow_pif_p0_txl(data)           (0x0000003F&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_22_get_pow_pif_p3_txl(data)       ((0x3F000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_22_get_pow_pif_p2_txl(data)       ((0x003F0000&(data))>>16)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_22_get_pow_pif_p1_txl(data)       ((0x00003F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_22_get_pow_pif_p0_txl(data)       (0x0000003F&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_23                                0x18000D94
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_23_reg_addr                       "0xB8000D94"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_23_reg                            0xB8000D94
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_23_inst_addr                      "0x0034"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_23_reg(data)                  (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_23_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_23_reg                        (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_23_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_23_pif_p3_txl_ck7x_lag_shift      (24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_23_pif_p2_txl_ck7x_lag_shift      (16)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_23_pif_p1_txl_ck7x_lag_shift      (8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_23_pif_p0_txl_ck7x_lag_shift      (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_23_pif_p3_txl_ck7x_lag_mask       (0x3F000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_23_pif_p2_txl_ck7x_lag_mask       (0x003F0000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_23_pif_p1_txl_ck7x_lag_mask       (0x00003F00)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_23_pif_p0_txl_ck7x_lag_mask       (0x0000003F)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_23_pif_p3_txl_ck7x_lag(data)      (0x3F000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_23_pif_p2_txl_ck7x_lag(data)      (0x003F0000&((data)<<16))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_23_pif_p1_txl_ck7x_lag(data)      (0x00003F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_23_pif_p0_txl_ck7x_lag(data)      (0x0000003F&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_23_get_pif_p3_txl_ck7x_lag(data)  ((0x3F000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_23_get_pif_p2_txl_ck7x_lag(data)  ((0x003F0000&(data))>>16)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_23_get_pif_p1_txl_ck7x_lag(data)  ((0x00003F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_23_get_pif_p0_txl_ck7x_lag(data)  (0x0000003F&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_24                                0x18000D98
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_24_reg_addr                       "0xB8000D98"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_24_reg                            0xB8000D98
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_24_inst_addr                      "0x0035"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_24_reg(data)                  (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_24_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_24_reg                        (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_24_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_24_pif_p3_txl_cml_str_shift       (24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_24_pif_p2_txl_cml_str_shift       (16)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_24_pif_p1_txl_cml_str_shift       (8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_24_pif_p0_txl_cml_str_shift       (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_24_pif_p3_txl_cml_str_mask        (0x3F000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_24_pif_p2_txl_cml_str_mask        (0x003F0000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_24_pif_p1_txl_cml_str_mask        (0x00003F00)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_24_pif_p0_txl_cml_str_mask        (0x0000003F)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_24_pif_p3_txl_cml_str(data)       (0x3F000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_24_pif_p2_txl_cml_str(data)       (0x003F0000&((data)<<16))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_24_pif_p1_txl_cml_str(data)       (0x00003F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_24_pif_p0_txl_cml_str(data)       (0x0000003F&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_24_get_pif_p3_txl_cml_str(data)   ((0x3F000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_24_get_pif_p2_txl_cml_str(data)   ((0x003F0000&(data))>>16)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_24_get_pif_p1_txl_cml_str(data)   ((0x00003F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_24_get_pif_p0_txl_cml_str(data)   (0x0000003F&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_25                                0x18000D9C
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_25_reg_addr                       "0xB8000D9C"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_25_reg                            0xB8000D9C
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_25_inst_addr                      "0x0036"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_25_reg(data)                  (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_25_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_25_reg                        (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_25_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_25_pif_p3_txl_en_emp_shift        (24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_25_pif_p2_txl_en_emp_shift        (16)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_25_pif_p1_txl_en_emp_shift        (8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_25_pif_p0_txl_en_emp_shift        (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_25_pif_p3_txl_en_emp_mask         (0x3F000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_25_pif_p2_txl_en_emp_mask         (0x003F0000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_25_pif_p1_txl_en_emp_mask         (0x00003F00)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_25_pif_p0_txl_en_emp_mask         (0x0000003F)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_25_pif_p3_txl_en_emp(data)        (0x3F000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_25_pif_p2_txl_en_emp(data)        (0x003F0000&((data)<<16))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_25_pif_p1_txl_en_emp(data)        (0x00003F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_25_pif_p0_txl_en_emp(data)        (0x0000003F&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_25_get_pif_p3_txl_en_emp(data)    ((0x3F000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_25_get_pif_p2_txl_en_emp(data)    ((0x003F0000&(data))>>16)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_25_get_pif_p1_txl_en_emp(data)    ((0x00003F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_25_get_pif_p0_txl_en_emp(data)    (0x0000003F&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_26                                0x18000DA0
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_26_reg_addr                       "0xB8000DA0"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_26_reg                            0xB8000DA0
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_26_inst_addr                      "0x0037"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_26_reg(data)                  (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_26_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_26_reg                        (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_26_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_26_pif_p3_txl_en_term_shift       (24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_26_pif_p2_txl_en_term_shift       (16)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_26_pif_p1_txl_en_term_shift       (8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_26_pif_p0_txl_en_term_shift       (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_26_pif_p3_txl_en_term_mask        (0x3F000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_26_pif_p2_txl_en_term_mask        (0x003F0000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_26_pif_p1_txl_en_term_mask        (0x00003F00)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_26_pif_p0_txl_en_term_mask        (0x0000003F)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_26_pif_p3_txl_en_term(data)       (0x3F000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_26_pif_p2_txl_en_term(data)       (0x003F0000&((data)<<16))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_26_pif_p1_txl_en_term(data)       (0x00003F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_26_pif_p0_txl_en_term(data)       (0x0000003F&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_26_get_pif_p3_txl_en_term(data)   ((0x3F000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_26_get_pif_p2_txl_en_term(data)   ((0x003F0000&(data))>>16)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_26_get_pif_p1_txl_en_term(data)   ((0x00003F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_26_get_pif_p0_txl_en_term(data)   (0x0000003F&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_27                                0x18000DA4
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_27_reg_addr                       "0xB8000DA4"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_27_reg                            0xB8000DA4
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_27_inst_addr                      "0x0038"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_27_reg(data)                  (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_27_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_27_reg                        (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_27_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_27_pif_p3_txl_epicml_shift        (24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_27_pif_p2_txl_epicml_shift        (16)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_27_pif_p1_txl_epicml_shift        (8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_27_pif_p0_txl_epicml_shift        (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_27_pif_p3_txl_epicml_mask         (0x3F000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_27_pif_p2_txl_epicml_mask         (0x003F0000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_27_pif_p1_txl_epicml_mask         (0x00003F00)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_27_pif_p0_txl_epicml_mask         (0x0000003F)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_27_pif_p3_txl_epicml(data)        (0x3F000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_27_pif_p2_txl_epicml(data)        (0x003F0000&((data)<<16))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_27_pif_p1_txl_epicml(data)        (0x00003F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_27_pif_p0_txl_epicml(data)        (0x0000003F&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_27_get_pif_p3_txl_epicml(data)    ((0x3F000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_27_get_pif_p2_txl_epicml(data)    ((0x003F0000&(data))>>16)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_27_get_pif_p1_txl_epicml(data)    ((0x00003F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_27_get_pif_p0_txl_epicml(data)    (0x0000003F&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_28                                0x18000DA8
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_28_reg_addr                       "0xB8000DA8"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_28_reg                            0xB8000DA8
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_28_inst_addr                      "0x0039"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_28_reg(data)                  (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_28_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_28_reg                        (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_28_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_28_pif_p3_txl_pre_drv_shift       (24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_28_pif_p2_txl_pre_drv_shift       (16)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_28_pif_p1_txl_pre_drv_shift       (8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_28_pif_p0_txl_pre_drv_shift       (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_28_pif_p3_txl_pre_drv_mask        (0x3F000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_28_pif_p2_txl_pre_drv_mask        (0x003F0000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_28_pif_p1_txl_pre_drv_mask        (0x00003F00)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_28_pif_p0_txl_pre_drv_mask        (0x0000003F)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_28_pif_p3_txl_pre_drv(data)       (0x3F000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_28_pif_p2_txl_pre_drv(data)       (0x003F0000&((data)<<16))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_28_pif_p1_txl_pre_drv(data)       (0x00003F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_28_pif_p0_txl_pre_drv(data)       (0x0000003F&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_28_get_pif_p3_txl_pre_drv(data)   ((0x3F000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_28_get_pif_p2_txl_pre_drv(data)   ((0x003F0000&(data))>>16)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_28_get_pif_p1_txl_pre_drv(data)   ((0x00003F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_28_get_pif_p0_txl_pre_drv(data)   (0x0000003F&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_29                                0x18000DAC
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_29_reg_addr                       "0xB8000DAC"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_29_reg                            0xB8000DAC
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_29_inst_addr                      "0x003A"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_29_reg(data)                  (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_29_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_29_reg                        (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_29_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_29_pif_p3_txl_ib2x_shift          (24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_29_pif_p2_txl_ib2x_shift          (16)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_29_pif_p1_txl_ib2x_shift          (8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_29_pif_p0_txl_ib2x_shift          (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_29_pif_p3_txl_ib2x_mask           (0x3F000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_29_pif_p2_txl_ib2x_mask           (0x003F0000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_29_pif_p1_txl_ib2x_mask           (0x00003F00)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_29_pif_p0_txl_ib2x_mask           (0x0000003F)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_29_pif_p3_txl_ib2x(data)          (0x3F000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_29_pif_p2_txl_ib2x(data)          (0x003F0000&((data)<<16))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_29_pif_p1_txl_ib2x(data)          (0x00003F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_29_pif_p0_txl_ib2x(data)          (0x0000003F&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_29_get_pif_p3_txl_ib2x(data)      ((0x3F000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_29_get_pif_p2_txl_ib2x(data)      ((0x003F0000&(data))>>16)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_29_get_pif_p1_txl_ib2x(data)      ((0x00003F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_29_get_pif_p0_txl_ib2x(data)      (0x0000003F&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_30                                0x18000DB0
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_30_reg_addr                       "0xB8000DB0"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_30_reg                            0xB8000DB0
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_30_inst_addr                      "0x003B"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_30_reg(data)                  (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_30_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_30_reg                        (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_30_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_30_pif_p3_txl_sr_td_shift         (24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_30_pif_p2_txl_sr_td_shift         (16)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_30_pif_p1_txl_sr_td_shift         (8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_30_pif_p0_txl_sr_td_shift         (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_30_pif_p3_txl_sr_td_mask          (0x3F000000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_30_pif_p2_txl_sr_td_mask          (0x003F0000)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_30_pif_p1_txl_sr_td_mask          (0x00003F00)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_30_pif_p0_txl_sr_td_mask          (0x0000003F)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_30_pif_p3_txl_sr_td(data)         (0x3F000000&((data)<<24))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_30_pif_p2_txl_sr_td(data)         (0x003F0000&((data)<<16))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_30_pif_p1_txl_sr_td(data)         (0x00003F00&((data)<<8))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_30_pif_p0_txl_sr_td(data)         (0x0000003F&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_30_get_pif_p3_txl_sr_td(data)     ((0x3F000000&(data))>>24)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_30_get_pif_p2_txl_sr_td(data)     ((0x003F0000&(data))>>16)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_30_get_pif_p1_txl_sr_td(data)     ((0x00003F00&(data))>>8)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_30_get_pif_p0_txl_sr_td(data)     (0x0000003F&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_31                                0x18000DB4
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_31_reg_addr                       "0xB8000DB4"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_31_reg                            0xB8000DB4
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_31_inst_addr                      "0x003C"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_31_reg(data)                  (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_31_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_31_reg                        (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_31_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_31_pif_p0_dummy_lvds_shift        (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_31_pif_p0_dummy_lvds_mask         (0x00FFFFFF)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_31_pif_p0_dummy_lvds(data)        (0x00FFFFFF&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_31_get_pif_p0_dummy_lvds(data)    (0x00FFFFFF&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_32                                0x18000DB8
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_32_reg_addr                       "0xB8000DB8"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_32_reg                            0xB8000DB8
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_32_inst_addr                      "0x003D"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_32_reg(data)                  (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_32_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_32_reg                        (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_32_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_32_pif_p1_dummy_lvds_shift        (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_32_pif_p1_dummy_lvds_mask         (0x00FFFFFF)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_32_pif_p1_dummy_lvds(data)        (0x00FFFFFF&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_32_get_pif_p1_dummy_lvds(data)    (0x00FFFFFF&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_33                                0x18000DBC
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_33_reg_addr                       "0xB8000DBC"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_33_reg                            0xB8000DBC
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_33_inst_addr                      "0x003E"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_33_reg(data)                  (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_33_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_33_reg                        (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_33_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_33_pif_p2_dummy_lvds_shift        (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_33_pif_p2_dummy_lvds_mask         (0x00FFFFFF)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_33_pif_p2_dummy_lvds(data)        (0x00FFFFFF&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_33_get_pif_p2_dummy_lvds(data)    (0x00FFFFFF&(data))

#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_34                                0x18000DC0
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_34_reg_addr                       "0xB8000DC0"
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_34_reg                            0xB8000DC0
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_34_inst_addr                      "0x003F"
#define  set_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_34_reg(data)                  (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_34_reg)=data)
#define  get_PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_34_reg                        (*((volatile unsigned int*)PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_34_reg))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_34_pif_p3_dummy_lvds_shift        (0)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_34_pif_p3_dummy_lvds_mask         (0x00FFFFFF)
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_34_pif_p3_dummy_lvds(data)        (0x00FFFFFF&(data))
#define  PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_34_get_pif_p3_dummy_lvds(data)    (0x00FFFFFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======PINMUX_LVDSPHY register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p0_txfp_ps:4;
        RBus_UInt32  plt_p0_txfn_ps:4;
        RBus_UInt32  plt_p0_txep_ps:4;
        RBus_UInt32  plt_p0_txen_ps:4;
        RBus_UInt32  plt_p0_txdp_ps:4;
        RBus_UInt32  plt_p0_txdn_ps:4;
        RBus_UInt32  plt_p0_txcp_ps:4;
        RBus_UInt32  plt_p0_txcn_ps:4;
    };
}pinmux_lvdsphy_lvds_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p0_txbp_ps:4;
        RBus_UInt32  plt_p0_txbn_ps:4;
        RBus_UInt32  plt_p0_txap_ps:4;
        RBus_UInt32  plt_p0_txan_ps:4;
        RBus_UInt32  plt_p1_txfp_ps:4;
        RBus_UInt32  plt_p1_txfn_ps:4;
        RBus_UInt32  plt_p1_txep_ps:4;
        RBus_UInt32  plt_p1_txen_ps:4;
    };
}pinmux_lvdsphy_lvds_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p1_txdp_ps:4;
        RBus_UInt32  plt_p1_txdn_ps:4;
        RBus_UInt32  plt_p1_txcp_ps:4;
        RBus_UInt32  plt_p1_txcn_ps:4;
        RBus_UInt32  plt_p1_txbp_ps:4;
        RBus_UInt32  plt_p1_txbn_ps:4;
        RBus_UInt32  plt_p1_txap_ps:4;
        RBus_UInt32  plt_p1_txan_ps:4;
    };
}pinmux_lvdsphy_lvds_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p2_txfp_ps:4;
        RBus_UInt32  plt_p2_txfn_ps:4;
        RBus_UInt32  plt_p2_txep_ps:4;
        RBus_UInt32  plt_p2_txen_ps:4;
        RBus_UInt32  plt_p2_txdp_ps:4;
        RBus_UInt32  plt_p2_txdn_ps:4;
        RBus_UInt32  plt_p2_txcp_ps:4;
        RBus_UInt32  plt_p2_txcn_ps:4;
    };
}pinmux_lvdsphy_lvds_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p2_txbp_ps:4;
        RBus_UInt32  plt_p2_txbn_ps:4;
        RBus_UInt32  plt_p2_txap_ps:4;
        RBus_UInt32  plt_p2_txan_ps:4;
        RBus_UInt32  plt_p3_txfp_ps:4;
        RBus_UInt32  plt_p3_txfn_ps:4;
        RBus_UInt32  plt_p3_txep_ps:4;
        RBus_UInt32  plt_p3_txen_ps:4;
    };
}pinmux_lvdsphy_lvds_4_RBUS;

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
}pinmux_lvdsphy_lvds_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  epi_lock_sel:2;
    };
}pinmux_lvdsphy_pin_mux_lvds_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p0_txlap_mode:3;
        RBus_UInt32  pif_p0_txlan_mode:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pif_p0_txla_ckphs:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p0_txla_sr:1;
        RBus_UInt32  res3:7;
        RBus_UInt32  pif_p0_txla_term:4;
        RBus_UInt32  pif_p0_txla_iem_sel:4;
        RBus_UInt32  pif_p0_txla_idrv_sel:4;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p0_txlbp_mode:3;
        RBus_UInt32  pif_p0_txlbn_mode:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pif_p0_txlb_ckphs:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p0_txlb_sr:1;
        RBus_UInt32  res3:7;
        RBus_UInt32  pif_p0_txlb_term:4;
        RBus_UInt32  pif_p0_txlb_iem_sel:4;
        RBus_UInt32  pif_p0_txlb_idrv_sel:4;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p0_txlcp_mode:3;
        RBus_UInt32  pif_p0_txlcn_mode:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pif_p0_txlc_ckphs:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p0_txlc_sr:1;
        RBus_UInt32  res3:7;
        RBus_UInt32  pif_p0_txlc_term:4;
        RBus_UInt32  pif_p0_txlc_iem_sel:4;
        RBus_UInt32  pif_p0_txlc_idrv_sel:4;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p0_txldp_mode:3;
        RBus_UInt32  pif_p0_txldn_mode:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pif_p0_txld_ckphs:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p0_txld_sr:1;
        RBus_UInt32  res3:7;
        RBus_UInt32  pif_p0_txld_term:4;
        RBus_UInt32  pif_p0_txld_iem_sel:4;
        RBus_UInt32  pif_p0_txld_idrv_sel:4;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p0_txlep_mode:3;
        RBus_UInt32  pif_p0_txlen_mode:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pif_p0_txle_ckphs:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p0_txle_sr:1;
        RBus_UInt32  res3:7;
        RBus_UInt32  pif_p0_txle_term:4;
        RBus_UInt32  pif_p0_txle_iem_sel:4;
        RBus_UInt32  pif_p0_txle_idrv_sel:4;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p0_txlfp_mode:3;
        RBus_UInt32  pif_p0_txlfn_mode:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pif_p0_txlf_ckphs:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p0_txlf_sr:1;
        RBus_UInt32  res3:7;
        RBus_UInt32  pif_p0_txlf_term:4;
        RBus_UInt32  pif_p0_txlf_iem_sel:4;
        RBus_UInt32  pif_p0_txlf_idrv_sel:4;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p1_txlap_mode:3;
        RBus_UInt32  pif_p1_txlan_mode:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pif_p1_txla_ckphs:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p1_txla_sr:1;
        RBus_UInt32  res3:7;
        RBus_UInt32  pif_p1_txla_term:4;
        RBus_UInt32  pif_p1_txla_iem_sel:4;
        RBus_UInt32  pif_p1_txla_idrv_sel:4;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p1_txlbp_mode:3;
        RBus_UInt32  pif_p1_txlbn_mode:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pif_p1_txlb_ckphs:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p1_txlb_sr:1;
        RBus_UInt32  res3:7;
        RBus_UInt32  pif_p1_txlb_term:4;
        RBus_UInt32  pif_p1_txlb_iem_sel:4;
        RBus_UInt32  pif_p1_txlb_idrv_sel:4;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p1_txlcp_mode:3;
        RBus_UInt32  pif_p1_txlcn_mode:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pif_p1_txlc_ckphs:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p1_txlc_sr:1;
        RBus_UInt32  res3:7;
        RBus_UInt32  pif_p1_txlc_term:4;
        RBus_UInt32  pif_p1_txlc_iem_sel:4;
        RBus_UInt32  pif_p1_txlc_idrv_sel:4;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p1_txldp_mode:3;
        RBus_UInt32  pif_p1_txldn_mode:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pif_p1_txld_ckphs:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p1_txld_sr:1;
        RBus_UInt32  res3:7;
        RBus_UInt32  pif_p1_txld_term:4;
        RBus_UInt32  pif_p1_txld_iem_sel:4;
        RBus_UInt32  pif_p1_txld_idrv_sel:4;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p1_txlep_mode:3;
        RBus_UInt32  pif_p1_txlen_mode:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pif_p1_txle_ckphs:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p1_txle_sr:1;
        RBus_UInt32  res3:7;
        RBus_UInt32  pif_p1_txle_term:4;
        RBus_UInt32  pif_p1_txle_iem_sel:4;
        RBus_UInt32  pif_p1_txle_idrv_sel:4;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p1_txlfp_mode:3;
        RBus_UInt32  pif_p1_txlfn_mode:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pif_p1_txlf_ckphs:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p1_txlf_sr:1;
        RBus_UInt32  res3:7;
        RBus_UInt32  pif_p1_txlf_term:4;
        RBus_UInt32  pif_p1_txlf_iem_sel:4;
        RBus_UInt32  pif_p1_txlf_idrv_sel:4;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p2_txlap_mode:3;
        RBus_UInt32  pif_p2_txlan_mode:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pif_p2_txla_ckphs:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p2_txla_sr:1;
        RBus_UInt32  res3:7;
        RBus_UInt32  pif_p2_txla_term:4;
        RBus_UInt32  pif_p2_txla_iem_sel:4;
        RBus_UInt32  pif_p2_txla_idrv_sel:4;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p2_txlbp_mode:3;
        RBus_UInt32  pif_p2_txlbn_mode:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pif_p2_txlb_ckphs:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p2_txlb_sr:1;
        RBus_UInt32  res3:7;
        RBus_UInt32  pif_p2_txlb_term:4;
        RBus_UInt32  pif_p2_txlb_iem_sel:4;
        RBus_UInt32  pif_p2_txlb_idrv_sel:4;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p2_txlcp_mode:3;
        RBus_UInt32  pif_p2_txlcn_mode:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pif_p2_txlc_ckphs:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p2_txlc_sr:1;
        RBus_UInt32  res3:7;
        RBus_UInt32  pif_p2_txlc_term:4;
        RBus_UInt32  pif_p2_txlc_iem_sel:4;
        RBus_UInt32  pif_p2_txlc_idrv_sel:4;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p2_txldp_mode:3;
        RBus_UInt32  pif_p2_txldn_mode:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pif_p2_txld_ckphs:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p2_txld_sr:1;
        RBus_UInt32  res3:7;
        RBus_UInt32  pif_p2_txld_term:4;
        RBus_UInt32  pif_p2_txld_iem_sel:4;
        RBus_UInt32  pif_p2_txld_idrv_sel:4;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p2_txlep_mode:3;
        RBus_UInt32  pif_p2_txlen_mode:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pif_p2_txle_ckphs:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p2_txle_sr:1;
        RBus_UInt32  res3:7;
        RBus_UInt32  pif_p2_txle_term:4;
        RBus_UInt32  pif_p2_txle_iem_sel:4;
        RBus_UInt32  pif_p2_txle_idrv_sel:4;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p2_txlfp_mode:3;
        RBus_UInt32  pif_p2_txlfn_mode:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pif_p2_txlf_ckphs:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p2_txlf_sr:1;
        RBus_UInt32  res3:7;
        RBus_UInt32  pif_p2_txlf_term:4;
        RBus_UInt32  pif_p2_txlf_iem_sel:4;
        RBus_UInt32  pif_p2_txlf_idrv_sel:4;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p3_txlap_mode:3;
        RBus_UInt32  pif_p3_txlan_mode:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pif_p3_txla_ckphs:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p3_txla_sr:1;
        RBus_UInt32  res3:7;
        RBus_UInt32  pif_p3_txla_term:4;
        RBus_UInt32  pif_p3_txla_iem_sel:4;
        RBus_UInt32  pif_p3_txla_idrv_sel:4;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p3_txlbp_mode:3;
        RBus_UInt32  pif_p3_txlbn_mode:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pif_p3_txlb_ckphs:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p3_txlb_sr:1;
        RBus_UInt32  res3:7;
        RBus_UInt32  pif_p3_txlb_term:4;
        RBus_UInt32  pif_p3_txlb_iem_sel:4;
        RBus_UInt32  pif_p3_txlb_idrv_sel:4;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p3_txlcp_mode:3;
        RBus_UInt32  pif_p3_txlcn_mode:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pif_p3_txlc_ckphs:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p3_txlc_sr:1;
        RBus_UInt32  res3:7;
        RBus_UInt32  pif_p3_txlc_term:4;
        RBus_UInt32  pif_p3_txlc_iem_sel:4;
        RBus_UInt32  pif_p3_txlc_idrv_sel:4;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p3_txldp_mode:3;
        RBus_UInt32  pif_p3_txldn_mode:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pif_p3_txld_ckphs:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p3_txld_sr:1;
        RBus_UInt32  res3:7;
        RBus_UInt32  pif_p3_txld_term:4;
        RBus_UInt32  pif_p3_txld_iem_sel:4;
        RBus_UInt32  pif_p3_txld_idrv_sel:4;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p3_txlep_mode:3;
        RBus_UInt32  pif_p3_txlen_mode:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pif_p3_txle_ckphs:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p3_txle_sr:1;
        RBus_UInt32  res3:7;
        RBus_UInt32  pif_p3_txle_term:4;
        RBus_UInt32  pif_p3_txle_iem_sel:4;
        RBus_UInt32  pif_p3_txle_idrv_sel:4;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p3_txlfp_mode:3;
        RBus_UInt32  pif_p3_txlfn_mode:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pif_p3_txlf_ckphs:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p3_txlf_sr:1;
        RBus_UInt32  res3:7;
        RBus_UInt32  pif_p3_txlf_term:4;
        RBus_UInt32  pif_p3_txlf_iem_sel:4;
        RBus_UInt32  pif_p3_txlf_idrv_sel:4;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p0_txl_ck7x_delay:2;
        RBus_UInt32  pif_p0_txl_ck7x_inv:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  pif_p0_txl_cm_mode:1;
        RBus_UInt32  res2:27;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p1_txl_ck7x_delay:2;
        RBus_UInt32  pif_p1_txl_ck7x_inv:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  pif_p1_txl_cm_mode:1;
        RBus_UInt32  res2:27;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p2_txl_ck7x_delay:2;
        RBus_UInt32  pif_p2_txl_ck7x_inv:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  pif_p2_txl_cm_mode:1;
        RBus_UInt32  res2:27;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p3_txl_ck7x_delay:2;
        RBus_UInt32  pif_p3_txl_ck7x_inv:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  pif_p3_txl_cm_mode:1;
        RBus_UInt32  res2:27;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pif_y_sel_test:2;
        RBus_UInt32  res2:28;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_a1_pi_phsel:12;
        RBus_UInt32  pif_a1_sel_2xi:1;
        RBus_UInt32  pif_a2_pi_phsel:12;
        RBus_UInt32  pif_a2_sel_2xi:1;
        RBus_UInt32  pif_a_pi_freq:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  pif_sbg:2;
        RBus_UInt32  res2:1;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_ab_pi_phsel:12;
        RBus_UInt32  pif_ab_freq:2;
        RBus_UInt32  pif_ab_sel_2xi:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  pif_h_cmu_sel_lv_vldo:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  pif_h_cmu_mode:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  pif_h_cmu_bw_set:2;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_b1_pi_phsel:12;
        RBus_UInt32  pif_b1_sel_2xi:1;
        RBus_UInt32  pif_b2_pi_phsel:12;
        RBus_UInt32  pif_b2_sel_2xi:1;
        RBus_UInt32  pif_b_pi_freq:2;
        RBus_UInt32  res1:4;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_cmu_big_kvco:1;
        RBus_UInt32  pif_cmu_ckpixel_inv:1;
        RBus_UInt32  pif_cmu_ck_ref_inv:1;
        RBus_UInt32  res1:8;
        RBus_UInt32  pif_cmu_ck_ref_sel:1;
        RBus_UInt32  pif_cmu_sel_cp_i:4;
        RBus_UInt32  pif_cmu_sel_sc1:3;
        RBus_UInt32  pif_cmu_sel_sc2:2;
        RBus_UInt32  pif_cmu_sel_sr:3;
        RBus_UInt32  pif_cmu_sel_vldo:2;
        RBus_UInt32  pif_cmu_a_pi_bypass:1;
        RBus_UInt32  pif_cmu_b_pi_bypass:1;
        RBus_UInt32  pif_cmu_hsdelay_sel:1;
        RBus_UInt32  pif_cmu_wdrst:1;
        RBus_UInt32  pif_cmu_wdset:1;
        RBus_UInt32  cmu_wdo:1;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pif_x_sel_test:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  pif_sel_tx_i:4;
        RBus_UInt32  pif_sel_vcm:5;
        RBus_UInt32  pif_en_test:1;
        RBus_UInt32  pif_en_lv_ldo:1;
        RBus_UInt32  pif_en_txl_ldo:1;
        RBus_UInt32  res3:4;
        RBus_UInt32  pif_p3_sel_txl_vldo:2;
        RBus_UInt32  pif_p2_sel_txl_vldo:2;
        RBus_UInt32  pif_p1_sel_txl_vldo:2;
        RBus_UInt32  pif_p0_sel_txl_vldo:2;
        RBus_UInt32  pif_hs_biasmode:2;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  pif_p0_txl_ck1x_delay:2;
        RBus_UInt32  res2:29;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  pif_p1_txl_ck1x_delay:2;
        RBus_UInt32  res2:29;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  pif_p2_txl_ck1x_delay:2;
        RBus_UInt32  res2:29;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  pif_p3_txl_ck1x_delay:2;
        RBus_UInt32  res2:29;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pif_dpll_sel_lv_vldo:2;
        RBus_UInt32  res2:28;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pow_pif:1;
        RBus_UInt32  res1:31;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_dummy:16;
        RBus_UInt32  pif_p3_ttl_str:1;
        RBus_UInt32  pif_p2_ttl_str:1;
        RBus_UInt32  pif_p1_ttl_str:1;
        RBus_UInt32  pif_p0_ttl_str:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  pif_h_cmu_rstb:1;
        RBus_UInt32  pif_h_cmu_pow:1;
        RBus_UInt32  res2:9;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_2_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_h_cmu_test_en:1;
        RBus_UInt32  pif_h_cmu_lvdscmpi_divm:6;
        RBus_UInt32  res1:1;
        RBus_UInt32  pif_h_cmu_test_sel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  pif_h_cmu_ck20xp_inv:1;
        RBus_UInt32  pif_h_cmu_ck1xp_inv:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  pif_h_cmu_tst_div:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  pif_h_cmu_prescalerdiv_ls:3;
        RBus_UInt32  res5:2;
        RBus_UInt32  pif_h_cmu_prescalerdiv_hs:2;
        RBus_UInt32  res6:5;
        RBus_UInt32  pif_h_cmu_epi_div_sel:3;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_3_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  pif_h_cmu_dummy:10;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_2_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  txpll_ckin_div_n:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  txpll_prediv_bypass:1;
        RBus_UInt32  res3:5;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_2_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pow_pif_p3_txl:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pow_pif_p2_txl:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pow_pif_p1_txl:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  pow_pif_p0_txl:6;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pif_p3_txl_ck7x_lag:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pif_p2_txl_ck7x_lag:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pif_p1_txl_ck7x_lag:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  pif_p0_txl_ck7x_lag:6;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pif_p3_txl_cml_str:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pif_p2_txl_cml_str:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pif_p1_txl_cml_str:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  pif_p0_txl_cml_str:6;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pif_p3_txl_en_emp:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pif_p2_txl_en_emp:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pif_p1_txl_en_emp:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  pif_p0_txl_en_emp:6;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pif_p3_txl_en_term:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pif_p2_txl_en_term:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pif_p1_txl_en_term:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  pif_p0_txl_en_term:6;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pif_p3_txl_epicml:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pif_p2_txl_epicml:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pif_p1_txl_epicml:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  pif_p0_txl_epicml:6;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pif_p3_txl_pre_drv:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pif_p2_txl_pre_drv:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pif_p1_txl_pre_drv:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  pif_p0_txl_pre_drv:6;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pif_p3_txl_ib2x:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pif_p2_txl_ib2x:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pif_p1_txl_ib2x:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  pif_p0_txl_ib2x:6;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_29_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pif_p3_txl_sr_td:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pif_p2_txl_sr_td:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pif_p1_txl_sr_td:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  pif_p0_txl_sr_td:6;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pif_p0_dummy_lvds:24;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pif_p1_dummy_lvds:24;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pif_p2_dummy_lvds:24;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_33_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pif_p3_dummy_lvds:24;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_34_RBUS;

#else //apply LITTLE_ENDIAN

//======PINMUX_LVDSPHY register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p0_txcn_ps:4;
        RBus_UInt32  plt_p0_txcp_ps:4;
        RBus_UInt32  plt_p0_txdn_ps:4;
        RBus_UInt32  plt_p0_txdp_ps:4;
        RBus_UInt32  plt_p0_txen_ps:4;
        RBus_UInt32  plt_p0_txep_ps:4;
        RBus_UInt32  plt_p0_txfn_ps:4;
        RBus_UInt32  plt_p0_txfp_ps:4;
    };
}pinmux_lvdsphy_lvds_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p1_txen_ps:4;
        RBus_UInt32  plt_p1_txep_ps:4;
        RBus_UInt32  plt_p1_txfn_ps:4;
        RBus_UInt32  plt_p1_txfp_ps:4;
        RBus_UInt32  plt_p0_txan_ps:4;
        RBus_UInt32  plt_p0_txap_ps:4;
        RBus_UInt32  plt_p0_txbn_ps:4;
        RBus_UInt32  plt_p0_txbp_ps:4;
    };
}pinmux_lvdsphy_lvds_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p1_txan_ps:4;
        RBus_UInt32  plt_p1_txap_ps:4;
        RBus_UInt32  plt_p1_txbn_ps:4;
        RBus_UInt32  plt_p1_txbp_ps:4;
        RBus_UInt32  plt_p1_txcn_ps:4;
        RBus_UInt32  plt_p1_txcp_ps:4;
        RBus_UInt32  plt_p1_txdn_ps:4;
        RBus_UInt32  plt_p1_txdp_ps:4;
    };
}pinmux_lvdsphy_lvds_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p2_txcn_ps:4;
        RBus_UInt32  plt_p2_txcp_ps:4;
        RBus_UInt32  plt_p2_txdn_ps:4;
        RBus_UInt32  plt_p2_txdp_ps:4;
        RBus_UInt32  plt_p2_txen_ps:4;
        RBus_UInt32  plt_p2_txep_ps:4;
        RBus_UInt32  plt_p2_txfn_ps:4;
        RBus_UInt32  plt_p2_txfp_ps:4;
    };
}pinmux_lvdsphy_lvds_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plt_p3_txen_ps:4;
        RBus_UInt32  plt_p3_txep_ps:4;
        RBus_UInt32  plt_p3_txfn_ps:4;
        RBus_UInt32  plt_p3_txfp_ps:4;
        RBus_UInt32  plt_p2_txan_ps:4;
        RBus_UInt32  plt_p2_txap_ps:4;
        RBus_UInt32  plt_p2_txbn_ps:4;
        RBus_UInt32  plt_p2_txbp_ps:4;
    };
}pinmux_lvdsphy_lvds_4_RBUS;

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
}pinmux_lvdsphy_lvds_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  epi_lock_sel:2;
        RBus_UInt32  res1:30;
    };
}pinmux_lvdsphy_pin_mux_lvds_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p0_txla_idrv_sel:4;
        RBus_UInt32  pif_p0_txla_iem_sel:4;
        RBus_UInt32  pif_p0_txla_term:4;
        RBus_UInt32  res1:7;
        RBus_UInt32  pif_p0_txla_sr:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p0_txla_ckphs:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  pif_p0_txlan_mode:3;
        RBus_UInt32  pif_p0_txlap_mode:3;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p0_txlb_idrv_sel:4;
        RBus_UInt32  pif_p0_txlb_iem_sel:4;
        RBus_UInt32  pif_p0_txlb_term:4;
        RBus_UInt32  res1:7;
        RBus_UInt32  pif_p0_txlb_sr:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p0_txlb_ckphs:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  pif_p0_txlbn_mode:3;
        RBus_UInt32  pif_p0_txlbp_mode:3;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p0_txlc_idrv_sel:4;
        RBus_UInt32  pif_p0_txlc_iem_sel:4;
        RBus_UInt32  pif_p0_txlc_term:4;
        RBus_UInt32  res1:7;
        RBus_UInt32  pif_p0_txlc_sr:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p0_txlc_ckphs:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  pif_p0_txlcn_mode:3;
        RBus_UInt32  pif_p0_txlcp_mode:3;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p0_txld_idrv_sel:4;
        RBus_UInt32  pif_p0_txld_iem_sel:4;
        RBus_UInt32  pif_p0_txld_term:4;
        RBus_UInt32  res1:7;
        RBus_UInt32  pif_p0_txld_sr:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p0_txld_ckphs:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  pif_p0_txldn_mode:3;
        RBus_UInt32  pif_p0_txldp_mode:3;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p0_txle_idrv_sel:4;
        RBus_UInt32  pif_p0_txle_iem_sel:4;
        RBus_UInt32  pif_p0_txle_term:4;
        RBus_UInt32  res1:7;
        RBus_UInt32  pif_p0_txle_sr:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p0_txle_ckphs:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  pif_p0_txlen_mode:3;
        RBus_UInt32  pif_p0_txlep_mode:3;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p0_txlf_idrv_sel:4;
        RBus_UInt32  pif_p0_txlf_iem_sel:4;
        RBus_UInt32  pif_p0_txlf_term:4;
        RBus_UInt32  res1:7;
        RBus_UInt32  pif_p0_txlf_sr:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p0_txlf_ckphs:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  pif_p0_txlfn_mode:3;
        RBus_UInt32  pif_p0_txlfp_mode:3;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p1_txla_idrv_sel:4;
        RBus_UInt32  pif_p1_txla_iem_sel:4;
        RBus_UInt32  pif_p1_txla_term:4;
        RBus_UInt32  res1:7;
        RBus_UInt32  pif_p1_txla_sr:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p1_txla_ckphs:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  pif_p1_txlan_mode:3;
        RBus_UInt32  pif_p1_txlap_mode:3;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p1_txlb_idrv_sel:4;
        RBus_UInt32  pif_p1_txlb_iem_sel:4;
        RBus_UInt32  pif_p1_txlb_term:4;
        RBus_UInt32  res1:7;
        RBus_UInt32  pif_p1_txlb_sr:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p1_txlb_ckphs:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  pif_p1_txlbn_mode:3;
        RBus_UInt32  pif_p1_txlbp_mode:3;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p1_txlc_idrv_sel:4;
        RBus_UInt32  pif_p1_txlc_iem_sel:4;
        RBus_UInt32  pif_p1_txlc_term:4;
        RBus_UInt32  res1:7;
        RBus_UInt32  pif_p1_txlc_sr:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p1_txlc_ckphs:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  pif_p1_txlcn_mode:3;
        RBus_UInt32  pif_p1_txlcp_mode:3;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p1_txld_idrv_sel:4;
        RBus_UInt32  pif_p1_txld_iem_sel:4;
        RBus_UInt32  pif_p1_txld_term:4;
        RBus_UInt32  res1:7;
        RBus_UInt32  pif_p1_txld_sr:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p1_txld_ckphs:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  pif_p1_txldn_mode:3;
        RBus_UInt32  pif_p1_txldp_mode:3;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p1_txle_idrv_sel:4;
        RBus_UInt32  pif_p1_txle_iem_sel:4;
        RBus_UInt32  pif_p1_txle_term:4;
        RBus_UInt32  res1:7;
        RBus_UInt32  pif_p1_txle_sr:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p1_txle_ckphs:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  pif_p1_txlen_mode:3;
        RBus_UInt32  pif_p1_txlep_mode:3;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p1_txlf_idrv_sel:4;
        RBus_UInt32  pif_p1_txlf_iem_sel:4;
        RBus_UInt32  pif_p1_txlf_term:4;
        RBus_UInt32  res1:7;
        RBus_UInt32  pif_p1_txlf_sr:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p1_txlf_ckphs:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  pif_p1_txlfn_mode:3;
        RBus_UInt32  pif_p1_txlfp_mode:3;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p2_txla_idrv_sel:4;
        RBus_UInt32  pif_p2_txla_iem_sel:4;
        RBus_UInt32  pif_p2_txla_term:4;
        RBus_UInt32  res1:7;
        RBus_UInt32  pif_p2_txla_sr:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p2_txla_ckphs:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  pif_p2_txlan_mode:3;
        RBus_UInt32  pif_p2_txlap_mode:3;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p2_txlb_idrv_sel:4;
        RBus_UInt32  pif_p2_txlb_iem_sel:4;
        RBus_UInt32  pif_p2_txlb_term:4;
        RBus_UInt32  res1:7;
        RBus_UInt32  pif_p2_txlb_sr:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p2_txlb_ckphs:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  pif_p2_txlbn_mode:3;
        RBus_UInt32  pif_p2_txlbp_mode:3;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p2_txlc_idrv_sel:4;
        RBus_UInt32  pif_p2_txlc_iem_sel:4;
        RBus_UInt32  pif_p2_txlc_term:4;
        RBus_UInt32  res1:7;
        RBus_UInt32  pif_p2_txlc_sr:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p2_txlc_ckphs:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  pif_p2_txlcn_mode:3;
        RBus_UInt32  pif_p2_txlcp_mode:3;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p2_txld_idrv_sel:4;
        RBus_UInt32  pif_p2_txld_iem_sel:4;
        RBus_UInt32  pif_p2_txld_term:4;
        RBus_UInt32  res1:7;
        RBus_UInt32  pif_p2_txld_sr:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p2_txld_ckphs:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  pif_p2_txldn_mode:3;
        RBus_UInt32  pif_p2_txldp_mode:3;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p2_txle_idrv_sel:4;
        RBus_UInt32  pif_p2_txle_iem_sel:4;
        RBus_UInt32  pif_p2_txle_term:4;
        RBus_UInt32  res1:7;
        RBus_UInt32  pif_p2_txle_sr:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p2_txle_ckphs:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  pif_p2_txlen_mode:3;
        RBus_UInt32  pif_p2_txlep_mode:3;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p2_txlf_idrv_sel:4;
        RBus_UInt32  pif_p2_txlf_iem_sel:4;
        RBus_UInt32  pif_p2_txlf_term:4;
        RBus_UInt32  res1:7;
        RBus_UInt32  pif_p2_txlf_sr:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p2_txlf_ckphs:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  pif_p2_txlfn_mode:3;
        RBus_UInt32  pif_p2_txlfp_mode:3;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p3_txla_idrv_sel:4;
        RBus_UInt32  pif_p3_txla_iem_sel:4;
        RBus_UInt32  pif_p3_txla_term:4;
        RBus_UInt32  res1:7;
        RBus_UInt32  pif_p3_txla_sr:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p3_txla_ckphs:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  pif_p3_txlan_mode:3;
        RBus_UInt32  pif_p3_txlap_mode:3;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p3_txlb_idrv_sel:4;
        RBus_UInt32  pif_p3_txlb_iem_sel:4;
        RBus_UInt32  pif_p3_txlb_term:4;
        RBus_UInt32  res1:7;
        RBus_UInt32  pif_p3_txlb_sr:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p3_txlb_ckphs:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  pif_p3_txlbn_mode:3;
        RBus_UInt32  pif_p3_txlbp_mode:3;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p3_txlc_idrv_sel:4;
        RBus_UInt32  pif_p3_txlc_iem_sel:4;
        RBus_UInt32  pif_p3_txlc_term:4;
        RBus_UInt32  res1:7;
        RBus_UInt32  pif_p3_txlc_sr:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p3_txlc_ckphs:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  pif_p3_txlcn_mode:3;
        RBus_UInt32  pif_p3_txlcp_mode:3;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p3_txld_idrv_sel:4;
        RBus_UInt32  pif_p3_txld_iem_sel:4;
        RBus_UInt32  pif_p3_txld_term:4;
        RBus_UInt32  res1:7;
        RBus_UInt32  pif_p3_txld_sr:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p3_txld_ckphs:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  pif_p3_txldn_mode:3;
        RBus_UInt32  pif_p3_txldp_mode:3;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p3_txle_idrv_sel:4;
        RBus_UInt32  pif_p3_txle_iem_sel:4;
        RBus_UInt32  pif_p3_txle_term:4;
        RBus_UInt32  res1:7;
        RBus_UInt32  pif_p3_txle_sr:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p3_txle_ckphs:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  pif_p3_txlen_mode:3;
        RBus_UInt32  pif_p3_txlep_mode:3;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p3_txlf_idrv_sel:4;
        RBus_UInt32  pif_p3_txlf_iem_sel:4;
        RBus_UInt32  pif_p3_txlf_term:4;
        RBus_UInt32  res1:7;
        RBus_UInt32  pif_p3_txlf_sr:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pif_p3_txlf_ckphs:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  pif_p3_txlfn_mode:3;
        RBus_UInt32  pif_p3_txlfp_mode:3;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  pif_p0_txl_cm_mode:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  pif_p0_txl_ck7x_inv:1;
        RBus_UInt32  pif_p0_txl_ck7x_delay:2;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  pif_p1_txl_cm_mode:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  pif_p1_txl_ck7x_inv:1;
        RBus_UInt32  pif_p1_txl_ck7x_delay:2;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  pif_p2_txl_cm_mode:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  pif_p2_txl_ck7x_inv:1;
        RBus_UInt32  pif_p2_txl_ck7x_delay:2;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  pif_p3_txl_cm_mode:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  pif_p3_txl_ck7x_inv:1;
        RBus_UInt32  pif_p3_txl_ck7x_delay:2;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  pif_y_sel_test:2;
        RBus_UInt32  res2:2;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  pif_sbg:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  pif_a_pi_freq:2;
        RBus_UInt32  pif_a2_sel_2xi:1;
        RBus_UInt32  pif_a2_pi_phsel:12;
        RBus_UInt32  pif_a1_sel_2xi:1;
        RBus_UInt32  pif_a1_pi_phsel:12;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_h_cmu_bw_set:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  pif_h_cmu_mode:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  pif_h_cmu_sel_lv_vldo:2;
        RBus_UInt32  res3:7;
        RBus_UInt32  pif_ab_sel_2xi:1;
        RBus_UInt32  pif_ab_freq:2;
        RBus_UInt32  pif_ab_pi_phsel:12;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  pif_b_pi_freq:2;
        RBus_UInt32  pif_b2_sel_2xi:1;
        RBus_UInt32  pif_b2_pi_phsel:12;
        RBus_UInt32  pif_b1_sel_2xi:1;
        RBus_UInt32  pif_b1_pi_phsel:12;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmu_wdo:1;
        RBus_UInt32  pif_cmu_wdset:1;
        RBus_UInt32  pif_cmu_wdrst:1;
        RBus_UInt32  pif_cmu_hsdelay_sel:1;
        RBus_UInt32  pif_cmu_b_pi_bypass:1;
        RBus_UInt32  pif_cmu_a_pi_bypass:1;
        RBus_UInt32  pif_cmu_sel_vldo:2;
        RBus_UInt32  pif_cmu_sel_sr:3;
        RBus_UInt32  pif_cmu_sel_sc2:2;
        RBus_UInt32  pif_cmu_sel_sc1:3;
        RBus_UInt32  pif_cmu_sel_cp_i:4;
        RBus_UInt32  pif_cmu_ck_ref_sel:1;
        RBus_UInt32  res1:8;
        RBus_UInt32  pif_cmu_ck_ref_inv:1;
        RBus_UInt32  pif_cmu_ckpixel_inv:1;
        RBus_UInt32  pif_cmu_big_kvco:1;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_hs_biasmode:2;
        RBus_UInt32  pif_p0_sel_txl_vldo:2;
        RBus_UInt32  pif_p1_sel_txl_vldo:2;
        RBus_UInt32  pif_p2_sel_txl_vldo:2;
        RBus_UInt32  pif_p3_sel_txl_vldo:2;
        RBus_UInt32  res1:4;
        RBus_UInt32  pif_en_txl_ldo:1;
        RBus_UInt32  pif_en_lv_ldo:1;
        RBus_UInt32  pif_en_test:1;
        RBus_UInt32  pif_sel_vcm:5;
        RBus_UInt32  pif_sel_tx_i:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  pif_x_sel_test:2;
        RBus_UInt32  res3:2;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  pif_p0_txl_ck1x_delay:2;
        RBus_UInt32  res2:1;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  pif_p1_txl_ck1x_delay:2;
        RBus_UInt32  res2:1;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  pif_p2_txl_ck1x_delay:2;
        RBus_UInt32  res2:1;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  pif_p3_txl_ck1x_delay:2;
        RBus_UInt32  res2:1;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  pif_dpll_sel_lv_vldo:2;
        RBus_UInt32  res2:2;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  pow_pif:1;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_0_27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  pif_h_cmu_pow:1;
        RBus_UInt32  pif_h_cmu_rstb:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  pif_p0_ttl_str:1;
        RBus_UInt32  pif_p1_ttl_str:1;
        RBus_UInt32  pif_p2_ttl_str:1;
        RBus_UInt32  pif_p3_ttl_str:1;
        RBus_UInt32  lvds_dummy:16;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_2_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_h_cmu_epi_div_sel:3;
        RBus_UInt32  res1:5;
        RBus_UInt32  pif_h_cmu_prescalerdiv_hs:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  pif_h_cmu_prescalerdiv_ls:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  pif_h_cmu_tst_div:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  pif_h_cmu_ck1xp_inv:1;
        RBus_UInt32  pif_h_cmu_ck20xp_inv:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  pif_h_cmu_test_sel:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  pif_h_cmu_lvdscmpi_divm:6;
        RBus_UInt32  pif_h_cmu_test_en:1;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_3_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_h_cmu_dummy:10;
        RBus_UInt32  res1:22;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_2_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  txpll_prediv_bypass:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  txpll_ckin_div_n:6;
        RBus_UInt32  res3:18;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_2_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pow_pif_p0_txl:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  pow_pif_p1_txl:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pow_pif_p2_txl:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pow_pif_p3_txl:6;
        RBus_UInt32  res4:2;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p0_txl_ck7x_lag:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  pif_p1_txl_ck7x_lag:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pif_p2_txl_ck7x_lag:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pif_p3_txl_ck7x_lag:6;
        RBus_UInt32  res4:2;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p0_txl_cml_str:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  pif_p1_txl_cml_str:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pif_p2_txl_cml_str:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pif_p3_txl_cml_str:6;
        RBus_UInt32  res4:2;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p0_txl_en_emp:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  pif_p1_txl_en_emp:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pif_p2_txl_en_emp:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pif_p3_txl_en_emp:6;
        RBus_UInt32  res4:2;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p0_txl_en_term:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  pif_p1_txl_en_term:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pif_p2_txl_en_term:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pif_p3_txl_en_term:6;
        RBus_UInt32  res4:2;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p0_txl_epicml:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  pif_p1_txl_epicml:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pif_p2_txl_epicml:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pif_p3_txl_epicml:6;
        RBus_UInt32  res4:2;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p0_txl_pre_drv:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  pif_p1_txl_pre_drv:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pif_p2_txl_pre_drv:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pif_p3_txl_pre_drv:6;
        RBus_UInt32  res4:2;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p0_txl_ib2x:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  pif_p1_txl_ib2x:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pif_p2_txl_ib2x:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pif_p3_txl_ib2x:6;
        RBus_UInt32  res4:2;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_29_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p0_txl_sr_td:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  pif_p1_txl_sr_td:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pif_p2_txl_sr_td:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pif_p3_txl_sr_td:6;
        RBus_UInt32  res4:2;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p0_dummy_lvds:24;
        RBus_UInt32  res1:8;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p1_dummy_lvds:24;
        RBus_UInt32  res1:8;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p2_dummy_lvds:24;
        RBus_UInt32  res1:8;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_33_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_p3_dummy_lvds:24;
        RBus_UInt32  res1:8;
    };
}pinmux_lvdsphy_lvdsepivby1_phy_ctrl_1_34_RBUS;




#endif 


#endif 
