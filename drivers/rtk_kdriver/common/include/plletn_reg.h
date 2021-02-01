/**
* @file rbusPLLETNReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_PLLETN_REG_H_
#define _RBUS_PLLETN_REG_H_

#include "rbus_types.h"



//  PLLETN Register Address
#define  PLLETN_GETN_RST                                                         0x18016C00
#define  PLLETN_GETN_RST_reg_addr                                                "0xB8016C00"
#define  PLLETN_GETN_RST_reg                                                     0xB8016C00
#define  PLLETN_GETN_RST_inst_addr                                               "0x0000"
#define  set_PLLETN_GETN_RST_reg(data)                                           (*((volatile unsigned int*)PLLETN_GETN_RST_reg)=data)
#define  get_PLLETN_GETN_RST_reg                                                 (*((volatile unsigned int*)PLLETN_GETN_RST_reg))
#define  PLLETN_GETN_RST_dummy_4_shift                                           (4)
#define  PLLETN_GETN_RST_rstn_getn_phy_shift                                     (3)
#define  PLLETN_GETN_RST_rstn_getn_mac_shift                                     (2)
#define  PLLETN_GETN_RST_rstn_getn_sys_shift                                     (1)
#define  PLLETN_GETN_RST_write_data_shift                                        (0)
#define  PLLETN_GETN_RST_dummy_4_mask                                            (0x00000010)
#define  PLLETN_GETN_RST_rstn_getn_phy_mask                                      (0x00000008)
#define  PLLETN_GETN_RST_rstn_getn_mac_mask                                      (0x00000004)
#define  PLLETN_GETN_RST_rstn_getn_sys_mask                                      (0x00000002)
#define  PLLETN_GETN_RST_write_data_mask                                         (0x00000001)
#define  PLLETN_GETN_RST_dummy_4(data)                                           (0x00000010&((data)<<4))
#define  PLLETN_GETN_RST_rstn_getn_phy(data)                                     (0x00000008&((data)<<3))
#define  PLLETN_GETN_RST_rstn_getn_mac(data)                                     (0x00000004&((data)<<2))
#define  PLLETN_GETN_RST_rstn_getn_sys(data)                                     (0x00000002&((data)<<1))
#define  PLLETN_GETN_RST_write_data(data)                                        (0x00000001&(data))
#define  PLLETN_GETN_RST_get_dummy_4(data)                                       ((0x00000010&(data))>>4)
#define  PLLETN_GETN_RST_get_rstn_getn_phy(data)                                 ((0x00000008&(data))>>3)
#define  PLLETN_GETN_RST_get_rstn_getn_mac(data)                                 ((0x00000004&(data))>>2)
#define  PLLETN_GETN_RST_get_rstn_getn_sys(data)                                 ((0x00000002&(data))>>1)
#define  PLLETN_GETN_RST_get_write_data(data)                                    (0x00000001&(data))

#define  PLLETN_GETN_CLKEN                                                       0x18016C04
#define  PLLETN_GETN_CLKEN_reg_addr                                              "0xB8016C04"
#define  PLLETN_GETN_CLKEN_reg                                                   0xB8016C04
#define  PLLETN_GETN_CLKEN_inst_addr                                             "0x0001"
#define  set_PLLETN_GETN_CLKEN_reg(data)                                         (*((volatile unsigned int*)PLLETN_GETN_CLKEN_reg)=data)
#define  get_PLLETN_GETN_CLKEN_reg                                               (*((volatile unsigned int*)PLLETN_GETN_CLKEN_reg))
#define  PLLETN_GETN_CLKEN_clken_getn_mac_shift                                  (2)
#define  PLLETN_GETN_CLKEN_clken_getn_sys_shift                                  (1)
#define  PLLETN_GETN_CLKEN_write_data_shift                                      (0)
#define  PLLETN_GETN_CLKEN_clken_getn_mac_mask                                   (0x00000004)
#define  PLLETN_GETN_CLKEN_clken_getn_sys_mask                                   (0x00000002)
#define  PLLETN_GETN_CLKEN_write_data_mask                                       (0x00000001)
#define  PLLETN_GETN_CLKEN_clken_getn_mac(data)                                  (0x00000004&((data)<<2))
#define  PLLETN_GETN_CLKEN_clken_getn_sys(data)                                  (0x00000002&((data)<<1))
#define  PLLETN_GETN_CLKEN_write_data(data)                                      (0x00000001&(data))
#define  PLLETN_GETN_CLKEN_get_clken_getn_mac(data)                              ((0x00000004&(data))>>2)
#define  PLLETN_GETN_CLKEN_get_clken_getn_sys(data)                              ((0x00000002&(data))>>1)
#define  PLLETN_GETN_CLKEN_get_write_data(data)                                  (0x00000001&(data))

#define  PLLETN_WOW_CLK                                                          0x18016C10
#define  PLLETN_WOW_CLK_reg_addr                                                 "0xB8016C10"
#define  PLLETN_WOW_CLK_reg                                                      0xB8016C10
#define  PLLETN_WOW_CLK_inst_addr                                                "0x0002"
#define  set_PLLETN_WOW_CLK_reg(data)                                            (*((volatile unsigned int*)PLLETN_WOW_CLK_reg)=data)
#define  get_PLLETN_WOW_CLK_reg                                                  (*((volatile unsigned int*)PLLETN_WOW_CLK_reg))
#define  PLLETN_WOW_CLK_dummy_31_shift                                           (31)
#define  PLLETN_WOW_CLK_wow_x27_clksel_shift                                     (1)
#define  PLLETN_WOW_CLK_wow_gmac_clksel_shift                                    (0)
#define  PLLETN_WOW_CLK_dummy_31_mask                                            (0x80000000)
#define  PLLETN_WOW_CLK_wow_x27_clksel_mask                                      (0x00000002)
#define  PLLETN_WOW_CLK_wow_gmac_clksel_mask                                     (0x00000001)
#define  PLLETN_WOW_CLK_dummy_31(data)                                           (0x80000000&((data)<<31))
#define  PLLETN_WOW_CLK_wow_x27_clksel(data)                                     (0x00000002&((data)<<1))
#define  PLLETN_WOW_CLK_wow_gmac_clksel(data)                                    (0x00000001&(data))
#define  PLLETN_WOW_CLK_get_dummy_31(data)                                       ((0x80000000&(data))>>31)
#define  PLLETN_WOW_CLK_get_wow_x27_clksel(data)                                 ((0x00000002&(data))>>1)
#define  PLLETN_WOW_CLK_get_wow_gmac_clksel(data)                                (0x00000001&(data))

#define  PLLETN_WOW_DBG                                                          0x18016C14
#define  PLLETN_WOW_DBG_reg_addr                                                 "0xB8016C14"
#define  PLLETN_WOW_DBG_reg                                                      0xB8016C14
#define  PLLETN_WOW_DBG_inst_addr                                                "0x0003"
#define  set_PLLETN_WOW_DBG_reg(data)                                            (*((volatile unsigned int*)PLLETN_WOW_DBG_reg)=data)
#define  get_PLLETN_WOW_DBG_reg                                                  (*((volatile unsigned int*)PLLETN_WOW_DBG_reg))
#define  PLLETN_WOW_DBG_iso_dbg_en_shift                                         (4)
#define  PLLETN_WOW_DBG_sel_xtal25m_cen_l_shift                                  (3)
#define  PLLETN_WOW_DBG_etn_ocd_mode_shift                                       (2)
#define  PLLETN_WOW_DBG_mdcmdio_dbg_shift                                        (1)
#define  PLLETN_WOW_DBG_mac_phy_dbg_sel_shift                                    (0)
#define  PLLETN_WOW_DBG_iso_dbg_en_mask                                          (0x00000010)
#define  PLLETN_WOW_DBG_sel_xtal25m_cen_l_mask                                   (0x00000008)
#define  PLLETN_WOW_DBG_etn_ocd_mode_mask                                        (0x00000004)
#define  PLLETN_WOW_DBG_mdcmdio_dbg_mask                                         (0x00000002)
#define  PLLETN_WOW_DBG_mac_phy_dbg_sel_mask                                     (0x00000001)
#define  PLLETN_WOW_DBG_iso_dbg_en(data)                                         (0x00000010&((data)<<4))
#define  PLLETN_WOW_DBG_sel_xtal25m_cen_l(data)                                  (0x00000008&((data)<<3))
#define  PLLETN_WOW_DBG_etn_ocd_mode(data)                                       (0x00000004&((data)<<2))
#define  PLLETN_WOW_DBG_mdcmdio_dbg(data)                                        (0x00000002&((data)<<1))
#define  PLLETN_WOW_DBG_mac_phy_dbg_sel(data)                                    (0x00000001&(data))
#define  PLLETN_WOW_DBG_get_iso_dbg_en(data)                                     ((0x00000010&(data))>>4)
#define  PLLETN_WOW_DBG_get_sel_xtal25m_cen_l(data)                              ((0x00000008&(data))>>3)
#define  PLLETN_WOW_DBG_get_etn_ocd_mode(data)                                   ((0x00000004&(data))>>2)
#define  PLLETN_WOW_DBG_get_mdcmdio_dbg(data)                                    ((0x00000002&(data))>>1)
#define  PLLETN_WOW_DBG_get_mac_phy_dbg_sel(data)                                (0x00000001&(data))

#define  PLLETN_SYS_PLL_ETN1                                                     0x18016C18
#define  PLLETN_SYS_PLL_ETN1_reg_addr                                            "0xB8016C18"
#define  PLLETN_SYS_PLL_ETN1_reg                                                 0xB8016C18
#define  PLLETN_SYS_PLL_ETN1_inst_addr                                           "0x0004"
#define  set_PLLETN_SYS_PLL_ETN1_reg(data)                                       (*((volatile unsigned int*)PLLETN_SYS_PLL_ETN1_reg)=data)
#define  get_PLLETN_SYS_PLL_ETN1_reg                                             (*((volatile unsigned int*)PLLETN_SYS_PLL_ETN1_reg))
#define  PLLETN_SYS_PLL_ETN1_plletn_tielalf_shift                                (24)
#define  PLLETN_SYS_PLL_ETN1_plletn_pow_shift                                    (23)
#define  PLLETN_SYS_PLL_ETN1_plletn_powldo_shift                                 (22)
#define  PLLETN_SYS_PLL_ETN1_plletn_tielalf_mask                                 (0x01000000)
#define  PLLETN_SYS_PLL_ETN1_plletn_pow_mask                                     (0x00800000)
#define  PLLETN_SYS_PLL_ETN1_plletn_powldo_mask                                  (0x00400000)
#define  PLLETN_SYS_PLL_ETN1_plletn_tielalf(data)                                (0x01000000&((data)<<24))
#define  PLLETN_SYS_PLL_ETN1_plletn_pow(data)                                    (0x00800000&((data)<<23))
#define  PLLETN_SYS_PLL_ETN1_plletn_powldo(data)                                 (0x00400000&((data)<<22))
#define  PLLETN_SYS_PLL_ETN1_get_plletn_tielalf(data)                            ((0x01000000&(data))>>24)
#define  PLLETN_SYS_PLL_ETN1_get_plletn_pow(data)                                ((0x00800000&(data))>>23)
#define  PLLETN_SYS_PLL_ETN1_get_plletn_powldo(data)                             ((0x00400000&(data))>>22)

#define  PLLETN_INIT_AUTOLOAD_DONE                                               0x18016C1C
#define  PLLETN_INIT_AUTOLOAD_DONE_reg_addr                                      "0xB8016C1C"
#define  PLLETN_INIT_AUTOLOAD_DONE_reg                                           0xB8016C1C
#define  PLLETN_INIT_AUTOLOAD_DONE_inst_addr                                     "0x0005"
#define  set_PLLETN_INIT_AUTOLOAD_DONE_reg(data)                                 (*((volatile unsigned int*)PLLETN_INIT_AUTOLOAD_DONE_reg)=data)
#define  get_PLLETN_INIT_AUTOLOAD_DONE_reg                                       (*((volatile unsigned int*)PLLETN_INIT_AUTOLOAD_DONE_reg))
#define  PLLETN_INIT_AUTOLOAD_DONE_init_autoload_done_shift                      (0)
#define  PLLETN_INIT_AUTOLOAD_DONE_init_autoload_done_mask                       (0x00000001)
#define  PLLETN_INIT_AUTOLOAD_DONE_init_autoload_done(data)                      (0x00000001&(data))
#define  PLLETN_INIT_AUTOLOAD_DONE_get_init_autoload_done(data)                  (0x00000001&(data))

#define  PLLETN_PHY_POR_THRESHOLD                                                0x18016C20
#define  PLLETN_PHY_POR_THRESHOLD_reg_addr                                       "0xB8016C20"
#define  PLLETN_PHY_POR_THRESHOLD_reg                                            0xB8016C20
#define  PLLETN_PHY_POR_THRESHOLD_inst_addr                                      "0x0006"
#define  set_PLLETN_PHY_POR_THRESHOLD_reg(data)                                  (*((volatile unsigned int*)PLLETN_PHY_POR_THRESHOLD_reg)=data)
#define  get_PLLETN_PHY_POR_THRESHOLD_reg                                        (*((volatile unsigned int*)PLLETN_PHY_POR_THRESHOLD_reg))
#define  PLLETN_PHY_POR_THRESHOLD_avth_por_shift                                 (2)
#define  PLLETN_PHY_POR_THRESHOLD_dvth_por_shift                                 (0)
#define  PLLETN_PHY_POR_THRESHOLD_avth_por_mask                                  (0x0000000C)
#define  PLLETN_PHY_POR_THRESHOLD_dvth_por_mask                                  (0x00000003)
#define  PLLETN_PHY_POR_THRESHOLD_avth_por(data)                                 (0x0000000C&((data)<<2))
#define  PLLETN_PHY_POR_THRESHOLD_dvth_por(data)                                 (0x00000003&(data))
#define  PLLETN_PHY_POR_THRESHOLD_get_avth_por(data)                             ((0x0000000C&(data))>>2)
#define  PLLETN_PHY_POR_THRESHOLD_get_dvth_por(data)                             (0x00000003&(data))

#define  PLLETN_PHY_POR_STATUS                                                   0x18016C24
#define  PLLETN_PHY_POR_STATUS_reg_addr                                          "0xB8016C24"
#define  PLLETN_PHY_POR_STATUS_reg                                               0xB8016C24
#define  PLLETN_PHY_POR_STATUS_inst_addr                                         "0x0007"
#define  set_PLLETN_PHY_POR_STATUS_reg(data)                                     (*((volatile unsigned int*)PLLETN_PHY_POR_STATUS_reg)=data)
#define  get_PLLETN_PHY_POR_STATUS_reg                                           (*((volatile unsigned int*)PLLETN_PHY_POR_STATUS_reg))
#define  PLLETN_PHY_POR_STATUS_dbg_av_cen_l_shift                                (5)
#define  PLLETN_PHY_POR_STATUS_dbg_dv_cen_l_shift                                (4)
#define  PLLETN_PHY_POR_STATUS_av_cen_detect_shift                               (2)
#define  PLLETN_PHY_POR_STATUS_dv_cen_detect_shift                               (1)
#define  PLLETN_PHY_POR_STATUS_por_detect_shift                                  (0)
#define  PLLETN_PHY_POR_STATUS_dbg_av_cen_l_mask                                 (0x00000020)
#define  PLLETN_PHY_POR_STATUS_dbg_dv_cen_l_mask                                 (0x00000010)
#define  PLLETN_PHY_POR_STATUS_av_cen_detect_mask                                (0x00000004)
#define  PLLETN_PHY_POR_STATUS_dv_cen_detect_mask                                (0x00000002)
#define  PLLETN_PHY_POR_STATUS_por_detect_mask                                   (0x00000001)
#define  PLLETN_PHY_POR_STATUS_dbg_av_cen_l(data)                                (0x00000020&((data)<<5))
#define  PLLETN_PHY_POR_STATUS_dbg_dv_cen_l(data)                                (0x00000010&((data)<<4))
#define  PLLETN_PHY_POR_STATUS_av_cen_detect(data)                               (0x00000004&((data)<<2))
#define  PLLETN_PHY_POR_STATUS_dv_cen_detect(data)                               (0x00000002&((data)<<1))
#define  PLLETN_PHY_POR_STATUS_por_detect(data)                                  (0x00000001&(data))
#define  PLLETN_PHY_POR_STATUS_get_dbg_av_cen_l(data)                            ((0x00000020&(data))>>5)
#define  PLLETN_PHY_POR_STATUS_get_dbg_dv_cen_l(data)                            ((0x00000010&(data))>>4)
#define  PLLETN_PHY_POR_STATUS_get_av_cen_detect(data)                           ((0x00000004&(data))>>2)
#define  PLLETN_PHY_POR_STATUS_get_dv_cen_detect(data)                           ((0x00000002&(data))>>1)
#define  PLLETN_PHY_POR_STATUS_get_por_detect(data)                              (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======PLLETN register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  dummy18016c00_4:1;
        RBus_UInt32  rstn_getn_phy:1;
        RBus_UInt32  rstn_getn_mac:1;
        RBus_UInt32  rstn_getn_sys:1;
        RBus_UInt32  write_data:1;
    };
}plletn_getn_rst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  res2:1;
        RBus_UInt32  clken_getn_mac:1;
        RBus_UInt32  clken_getn_sys:1;
        RBus_UInt32  write_data:1;
    };
}plletn_getn_clken_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18016c10_31:1;
        RBus_UInt32  res1:27;
        RBus_UInt32  res2:2;
        RBus_UInt32  wow_x27_clksel:1;
        RBus_UInt32  wow_gmac_clksel:1;
    };
}plletn_wow_clk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  iso_dbg_en:1;
        RBus_UInt32  sel_xtal25m_cen_l:1;
        RBus_UInt32  etn_ocd_mode:1;
        RBus_UInt32  mdcmdio_dbg:1;
        RBus_UInt32  mac_phy_dbg_sel:1;
    };
}plletn_wow_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  plletn_tielalf:1;
        RBus_UInt32  plletn_pow:1;
        RBus_UInt32  plletn_powldo:1;
        RBus_UInt32  res2:22;
    };
}plletn_sys_pll_etn1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  init_autoload_done:1;
    };
}plletn_init_autoload_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  avth_por:2;
        RBus_UInt32  dvth_por:2;
    };
}plletn_phy_por_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  dbg_av_cen_l:1;
        RBus_UInt32  dbg_dv_cen_l:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  av_cen_detect:1;
        RBus_UInt32  dv_cen_detect:1;
        RBus_UInt32  por_detect:1;
    };
}plletn_phy_por_status_RBUS;

#else //apply LITTLE_ENDIAN

//======PLLETN register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  rstn_getn_sys:1;
        RBus_UInt32  rstn_getn_mac:1;
        RBus_UInt32  rstn_getn_phy:1;
        RBus_UInt32  dummy18016c00_4:1;
        RBus_UInt32  res1:27;
    };
}plletn_getn_rst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  clken_getn_sys:1;
        RBus_UInt32  clken_getn_mac:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:28;
    };
}plletn_getn_clken_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wow_gmac_clksel:1;
        RBus_UInt32  wow_x27_clksel:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  res2:27;
        RBus_UInt32  dummy18016c10_31:1;
    };
}plletn_wow_clk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mac_phy_dbg_sel:1;
        RBus_UInt32  mdcmdio_dbg:1;
        RBus_UInt32  etn_ocd_mode:1;
        RBus_UInt32  sel_xtal25m_cen_l:1;
        RBus_UInt32  iso_dbg_en:1;
        RBus_UInt32  res1:27;
    };
}plletn_wow_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  plletn_powldo:1;
        RBus_UInt32  plletn_pow:1;
        RBus_UInt32  plletn_tielalf:1;
        RBus_UInt32  res2:7;
    };
}plletn_sys_pll_etn1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  init_autoload_done:1;
        RBus_UInt32  res1:31;
    };
}plletn_init_autoload_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dvth_por:2;
        RBus_UInt32  avth_por:2;
        RBus_UInt32  res1:28;
    };
}plletn_phy_por_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  por_detect:1;
        RBus_UInt32  dv_cen_detect:1;
        RBus_UInt32  av_cen_detect:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  dbg_dv_cen_l:1;
        RBus_UInt32  dbg_av_cen_l:1;
        RBus_UInt32  res2:26;
    };
}plletn_phy_por_status_RBUS;




#endif 


#endif 
