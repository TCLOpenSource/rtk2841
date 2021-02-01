/**
* @file rbusMHLReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2014/7/24
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_MHL_REG_H_
#define _RBUS_MHL_REG_H_

#include "rbusTypes.h"



//  CBUS1 Register Address



#define  CBUS1_CBUS_STANDBY_00_VADDR                        	(0xb8062b00)
#define  CBUS1_CBUS_STANDBY_01_VADDR                        	(0xb8062b04)
#define  CBUS1_CBUS_STANDBY_02_VADDR                        	(0xb8062b08)
#define  CBUS1_CBUS_STANDBY_04_VADDR                        	(0xb8062b10)
#define  CBUS1_CBUS_STANDBY_05_VADDR                        	(0xb8062b14)
#define  CBUS1_CBUS_STANDBY_06_VADDR                        	(0xb8062b18)
#define  CBUS1_CBUS_STANDBY_07_VADDR                        	(0xb8062b1c)
#define  CBUS1_CBUS_STANDBY_08_VADDR                        	(0xb8062b20)
#define  CBUS1_CBUS_STANDBY_09_VADDR                        	(0xb8062b24)
#define  CBUS1_CBUS_PHY_0_VADDR                             	(0xb8062b30)
#define  CBUS1_CBUS_PHY_1_VADDR                             	(0xb8062b34)
#define  CBUS1_CBUS_PHY_2_VADDR                             	(0xb8062b38)
#define  CBUS1_CBUS_PHY_3_VADDR                             	(0xb8062b3c)
#define  CBUS1_MSC_REG_00_VADDR                             	(0xb800a000)
#define  CBUS1_MSC_REG_01_VADDR                             	(0xb800a004)
#define  CBUS1_MSC_REG_02_VADDR                             	(0xb800a008)
#define  CBUS1_MSC_REG_03_VADDR                             	(0xb800a00c)
#define  CBUS1_MSC_REG_04_VADDR                             	(0xb800a010)
#define  CBUS1_MSC_REG_05_VADDR                             	(0xb800a014)
#define  CBUS1_MSC_REG_06_VADDR                             	(0xb800a018)
#define  CBUS1_MSC_REG_07_VADDR                             	(0xb800a01c)
#define  CBUS1_MSC_REG_08_VADDR                             	(0xb800a020)
#define  CBUS1_MSC_REG_09_VADDR                             	(0xb800a024)
#define  CBUS1_MSC_REG_0A_VADDR                             	(0xb800a028)
#define  CBUS1_MSC_REG_0B_VADDR                             	(0xb800a02c)
#define  CBUS1_MSC_REG_0C_VADDR                             	(0xb800a030)
#define  CBUS1_MSC_REG_0D_VADDR                             	(0xb800a034)
#define  CBUS1_MSC_REG_0E_VADDR                             	(0xb800a038)
#define  CBUS1_MSC_REG_0F_VADDR                             	(0xb800a03c)
#define  CBUS1_MSC_REG_20_VADDR                             	(0xb800a080)
#define  CBUS1_MSC_REG_21_VADDR                             	(0xb800a084)
#define  CBUS1_MSC_REG_22_VADDR                             	(0xb800a088)
#define  CBUS1_MSC_REG_23_VADDR                             	(0xb800a08c)
#define  CBUS1_MSC_REG_24_VADDR                             	(0xb800a090)
#define  CBUS1_MSC_REG_25_VADDR                             	(0xb800a094)
#define  CBUS1_MSC_REG_26_VADDR                             	(0xb800a098)
#define  CBUS1_MSC_REG_27_VADDR                             	(0xb800a09c)
#define  CBUS1_MSC_REG_30_VADDR                             	(0xb800a0c0)
#define  CBUS1_MSC_REG_31_VADDR                             	(0xb800a0c4)
#define  CBUS1_MSC_REG_32_VADDR                             	(0xb800a0c8)
#define  CBUS1_MSC_REG_33_VADDR                             	(0xb800a0cc)
#define  CBUS1_MSC_REG_34_VADDR                             	(0xb800a0d0)
#define  CBUS1_MSC_REG_35_VADDR                             	(0xb800a0d4)
#define  CBUS1_MSC_REG_36_VADDR                             	(0xb800a0d8)
#define  CBUS1_MSC_REG_37_VADDR                             	(0xb800a0dc)
#define  CBUS1_MSC_REG_40_VADDR                             	(0xb800a100)
#define  CBUS1_MSC_REG_41_VADDR                             	(0xb800a104)
#define  CBUS1_MSC_REG_42_VADDR                             	(0xb800a108)
#define  CBUS1_MSC_REG_43_VADDR                             	(0xb800a10c)
#define  CBUS1_MSC_REG_44_VADDR                             	(0xb800a110)
#define  CBUS1_MSC_REG_45_VADDR                             	(0xb800a114)
#define  CBUS1_MSC_REG_46_VADDR                             	(0xb800a118)
#define  CBUS1_MSC_REG_47_VADDR                             	(0xb800a11c)
#define  CBUS1_MSC_REG_48_VADDR                             	(0xb800a120)
#define  CBUS1_MSC_REG_49_VADDR                             	(0xb800a124)
#define  CBUS1_MSC_REG_4A_VADDR                             	(0xb800a128)
#define  CBUS1_MSC_REG_4B_VADDR                             	(0xb800a12c)
#define  CBUS1_MSC_REG_4C_VADDR                             	(0xb800a130)
#define  CBUS1_MSC_REG_4D_VADDR                             	(0xb800a134)
#define  CBUS1_MSC_REG_4E_VADDR                             	(0xb800a138)
#define  CBUS1_MSC_REG_4F_VADDR                             	(0xb800a13c)
#define  CBUS1_MSC_REG_50_VADDR                             	(0xb800a140)
#define  CBUS1_MSC_REG_51_VADDR                             	(0xb800a144)
#define  CBUS1_MSC_REG_52_VADDR                             	(0xb800a148)
#define  CBUS1_MSC_REG_53_VADDR                             	(0xb800a14c)
#define  CBUS1_MSC_REG_54_VADDR                             	(0xb800a150)
#define  CBUS1_MSC_REG_55_VADDR                             	(0xb800a154)
#define  CBUS1_MSC_REG_56_VADDR                             	(0xb800a158)
#define  CBUS1_MSC_REG_57_VADDR                             	(0xb800a15c)
#define  CBUS1_MSC_REG_58_VADDR                             	(0xb800a160)
#define  CBUS1_MSC_REG_59_VADDR                             	(0xb800a164)
#define  CBUS1_MSC_REG_5A_VADDR                             	(0xb800a168)
#define  CBUS1_MSC_REG_5B_VADDR                             	(0xb800a16c)
#define  CBUS1_MSC_REG_5C_VADDR                             	(0xb800a170)
#define  CBUS1_MSC_REG_5D_VADDR                             	(0xb800a174)
#define  CBUS1_MSC_REG_5E_VADDR                             	(0xb800a178)
#define  CBUS1_MSC_REG_5F_VADDR                             	(0xb800a17c)
#define  CBUS1_CBUS_LINK_00_VADDR                           	(0xb800a200)
#define  CBUS1_CBUS_LINK_01_VADDR                           	(0xb800a204)
#define  CBUS1_CBUS_LINK_02_VADDR                           	(0xb800a208)
#define  CBUS1_CBUS_LINK_03_VADDR                           	(0xb800a20c)
#define  CBUS1_CBUS_LINK_04_VADDR                           	(0xb800a210)
#define  CBUS1_CBUS_LINK_05_VADDR                           	(0xb800a214)
#define  CBUS1_CBUS_LINK_06_VADDR                           	(0xb800a218)
#define  CBUS1_CBUS_LINK_07_VADDR                           	(0xb800a21c)
#define  CBUS1_CBUS_LINK_08_VADDR                           	(0xb800a220)
#define  CBUS1_CBUS_LINK_09_VADDR                           	(0xb800a224)
#define  CBUS1_CBUS_LINK_0A_VADDR                           	(0xb800a228)
#define  CBUS1_CBUS_LINK_0B_VADDR                           	(0xb800a22c)
#define  CBUS1_CBUS_LINK_0C_VADDR                           	(0xb800a230)
#define  CBUS1_CBUS_LINK_0D_VADDR                           	(0xb800a234)
#define  CBUS1_CBUS_LINK_0E_VADDR                           	(0xb800a238)
#define  CBUS1_CBUS_LINK_0F_VADDR                           	(0xb800a23c)
#define  CBUS1_CBUS_LINK_10_VADDR                           	(0xb800a240)
#define  CBUS1_CBUS_LINK_11_VADDR                           	(0xb800a244)
#define  CBUS1_CBUS_LINK_12_VADDR                           	(0xb800a248)
#define  CBUS1_CBUS_LINK_13_VADDR                           	(0xb800a24c)
#define  CBUS1_CBUS_LINK_14_VADDR                           	(0xb800a250)
#define  CBUS1_CBUS_MSC_00_VADDR                            	(0xb800a260)
#define  CBUS1_CBUS_MSC_01_VADDR                            	(0xb800a264)
#define  CBUS1_CBUS_MSC_02_VADDR                            	(0xb800a268)
#define  CBUS1_CBUS_MSC_03_VADDR                            	(0xb800a26c)
#define  CBUS1_CBUS_MSC_04_VADDR                            	(0xb800a270)
#define  CBUS1_CBUS_MSC_05_VADDR                            	(0xb800a274)
#define  CBUS1_CBUS_MSC_06_VADDR                            	(0xb800a278)
#define  CBUS1_CBUS_MSC_07_VADDR                            	(0xb800a27c)
#define  CBUS1_CBUS_MSC_08_VADDR                            	(0xb800a280)
#define  CBUS1_CBUS_MSC_09_VADDR                            	(0xb800a284)
#define  CBUS1_CBUS_MSC_0A_VADDR                            	(0xb800a288)
#define  CBUS1_CBUS_MSC_0B_VADDR                            	(0xb800a28c)
#define  CBUS1_CBUS_MSC_0C_VADDR                            	(0xb800a290)
#define  CBUS1_CBUS_MSC_0D_VADDR                            	(0xb800a294)
#define  CBUS1_CBUS_MSC_0E_VADDR                            	(0xb800a298)
#define  CBUS1_CBUS_MSC_0F_VADDR                            	(0xb800a29c)
#define  CBUS1_CBUS_MSC_10_VADDR                            	(0xb800a2a0)
#define  CBUS1_CBUS_MSC_11_VADDR                            	(0xb800a2a4)
#define  CBUS1_CBUS_MSC_12_VADDR                            	(0xb800a2a8)
#define  CBUS1_CBUS_MSC_13_VADDR                            	(0xb800a2ac)
#define  CBUS1_CBUS_MSC_14_VADDR                            	(0xb800a2b0)
#define  CBUS1_CBUS_MSC_15_VADDR                            	(0xb800a2b4)
#define  CBUS1_CBUS_MSC_16_VADDR                            	(0xb800a2b8)
#define  CBUS1_CBUS_MSC_17_VADDR                            	(0xb800a2bc)
#define  CBUS1_CBUS_MSC_18_VADDR                            	(0xb800a2c0)
#define  CBUS1_CBUS_MSC_19_VADDR                            	(0xb800a2c4)
#define  CBUS1_CBUS_MSC_1A_VADDR                            	(0xb800a2c8)
#define  CBUS1_CBUS_MSC_1B_VADDR                            	(0xb800a2cc)
#define  CBUS1_CBUS_MSC_1C_VADDR                            	(0xb800a2d0)
#define  CBUS1_CBUS_MSC_1D_VADDR                            	(0xb800a2d4)
#define  CBUS1_CBUS_MSC_1E_VADDR                            	(0xb800a2d8)
#define  CBUS1_CBUS_MSC_1F_VADDR                            	(0xb800a2dc)
#define  CBUS1_CBUS_MSC_20_VADDR                            	(0xb800a2e0)
#define  CBUS1_CBUS_MSC_21_VADDR                            	(0xb800a2e4)
#define  CBUS1_CBUS_MSC_22_VADDR                            	(0xb800a2e8)
#define  CBUS1_FW0_REQ_00_VADDR                             	(0xb800a300)
#define  CBUS1_FW0_REQ_01_VADDR                             	(0xb800a304)
#define  CBUS1_FW0_REQ_02_VADDR                             	(0xb800a308)
#define  CBUS1_FW0_REQ_03_VADDR                             	(0xb800a30c)
#define  CBUS1_FW0_REQ_04_VADDR                             	(0xb800a310)
#define  CBUS1_FW0_REQ_05_VADDR                             	(0xb800a314)
#define  CBUS1_FW0_REQ_06_VADDR                             	(0xb800a318)
#define  CBUS1_FW0_REQ_07_VADDR                             	(0xb800a31c)
#define  CBUS1_FW0_REQ_08_VADDR                             	(0xb800a320)
#define  CBUS1_CBUS_DDC_00_VADDR                            	(0xb800a3c0)
#define  CBUS1_CBUS_DDC_01_VADDR                            	(0xb800a3c4)
#define  CBUS1_CBUS_DDC_02_VADDR                            	(0xb800a3c8)
#define  CBUS1_CBUS_DDC_03_VADDR                            	(0xb800a3cc)
#define  CBUS1_CBUS_DDC_04_VADDR                            	(0xb800a3d0)
#define  CBUS1_CBUS_DDC_05_VADDR                            	(0xb800a3d4)
#define  CBUS1_CBUS_DDC_06_VADDR                            	(0xb800a3d8)
#define  CBUS1_CBUS_WDOG_VADDR                              	(0xb800a3e0)
#define  CBUS1_CBUS_INT_INDEX_VADDR                         	(0xb800a3e4)
#define  CBUS1_CBUS_TEST_VADDR                              	(0xb800a3e8)
#define  CBUS1_CBUS_DUMMY0_VADDR                            	(0xb800a3ec)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======CBUS1 register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  wake_pulse_det:1;
        RBus_UInt32  dis_pulse_det:1;
        RBus_UInt32  wake_irq_en:1;
        RBus_UInt32  dis_irq_en:1;
    };
}cbus1_cbus_standby_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  clk_1m_div:4;
        RBus_UInt32  clk_1k_div:10;
    };
}cbus1_cbus_standby_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dis_deb_lv:3;
        RBus_UInt32  deb_lv:3;
        RBus_UInt32  disconn:2;
    };
}cbus1_cbus_standby_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  wake_offset_low2:5;
        RBus_UInt32  wake_offset_low:5;
        RBus_UInt32  wake_cnt:3;
        RBus_UInt32  wake_offset:5;
        RBus_UInt32  cbus_disconn:1;
        RBus_UInt32  disconn_irq_en:1;
    };
}cbus1_cbus_standby_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dis_upper:4;
        RBus_UInt32  dis_lower:3;
        RBus_UInt32  wake_eco_en:1;
    };
}cbus1_cbus_standby_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  wake_num:3;
        RBus_UInt32  dis_num:5;
    };
}cbus1_cbus_standby_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cbus_imp_auto:1;
        RBus_UInt32  bypass_mode:1;
        RBus_UInt32  sink_fsm_st:3;
        RBus_UInt32  cbus_100k_en:1;
        RBus_UInt32  cbus_1k_en:1;
        RBus_UInt32  cbus_in_sig:1;
    };
}cbus1_cbus_standby_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  goto_sink1_pos:1;
        RBus_UInt32  goto_float:1;
        RBus_UInt32  goto_sink1:1;
        RBus_UInt32  cable_det:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  dbg_sel_phy:1;
    };
}cbus1_cbus_standby_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ctrl_09_resv:32;
    };
}cbus1_cbus_standby_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  cbus_sr:1;
        RBus_UInt32  cbus_smt:1;
        RBus_UInt32  cbus_pu:1;
        RBus_UInt32  cbus_pd:1;
        RBus_UInt32  cbus_i:1;
        RBus_UInt32  cbus_e2:1;
        RBus_UInt32  cbus_e:1;
    };
}cbus1_cbus_phy_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adjr_1k:4;
        RBus_UInt32  adjr_100k:5;
        RBus_UInt32  auto_k_1k:1;
        RBus_UInt32  auto_k_100k:1;
        RBus_UInt32  en_res_cal_cbus:1;
        RBus_UInt32  sel_cbus0_input_high:2;
        RBus_UInt32  sel_cbus0_input_low:2;
        RBus_UInt32  sel_cbus_0_driving:3;
        RBus_UInt32  sel_vref_ldo:2;
        RBus_UInt32  trim_ldo_cbus:4;
        RBus_UInt32  triming_mode:1;
        RBus_UInt32  en_cbus:1;
        RBus_UInt32  en_cmp_cbus:1;
        RBus_UInt32  en_driver_cbus:1;
        RBus_UInt32  en_ldo_cbus:1;
        RBus_UInt32  psm_cbus:1;
        RBus_UInt32  sel_cbusb_gpio:1;
    };
}cbus1_cbus_phy_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  cbus_o:1;
    };
}cbus1_cbus_phy_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  sel_phy_soft_rst_n:1;
        RBus_UInt32  cbus_res_tst:10;
        RBus_UInt32  res_ok:1;
    };
}cbus1_cbus_phy_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dev_state:8;
    };
}cbus1_msc_reg_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  mhl_ver:8;
    };
}cbus1_msc_reg_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dev_cat:1;
        RBus_UInt32  plim:2;
        RBus_UInt32  pow:1;
        RBus_UInt32  dev_type:4;
    };
}cbus1_msc_reg_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  adop_id_h:8;
    };
}cbus1_msc_reg_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  adop_id_l:8;
    };
}cbus1_msc_reg_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  vid_link_md:2;
        RBus_UInt32  supp_vga:1;
        RBus_UInt32  supp_islands:1;
        RBus_UInt32  supp_ppixel:1;
        RBus_UInt32  supp_yuv422:1;
        RBus_UInt32  supp_yuv444:1;
        RBus_UInt32  supp_rgb444:1;
    };
}cbus1_msc_reg_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  aud_link_md:6;
        RBus_UInt32  aud_8ch:1;
        RBus_UInt32  aud_2ch:1;
    };
}cbus1_msc_reg_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  supp_vt:1;
        RBus_UInt32  video_type:3;
        RBus_UInt32  vt_game:1;
        RBus_UInt32  vt_cinema:1;
        RBus_UInt32  vt_photo:1;
        RBus_UInt32  vt_graphics:1;
    };
}cbus1_msc_reg_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ld_gui:1;
        RBus_UInt32  ld_speaker:1;
        RBus_UInt32  ld_record:1;
        RBus_UInt32  ld_tuner:1;
        RBus_UInt32  ld_media:1;
        RBus_UInt32  ld_audio:1;
        RBus_UInt32  ld_video:1;
        RBus_UInt32  ld_display:1;
    };
}cbus1_msc_reg_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  bandwid:8;
    };
}cbus1_msc_reg_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  feature_flag:3;
        RBus_UInt32  ucp_recv_supp:1;
        RBus_UInt32  ucp_send_supp:1;
        RBus_UInt32  sp_supp:1;
        RBus_UInt32  rap_supp:1;
        RBus_UInt32  rcp_supp:1;
    };
}cbus1_msc_reg_0a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  device_id_h:8;
    };
}cbus1_msc_reg_0b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  device_id_l:8;
    };
}cbus1_msc_reg_0c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  scr_size:8;
    };
}cbus1_msc_reg_0d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  stat_size:4;
        RBus_UInt32  int_size:4;
    };
}cbus1_msc_reg_0e_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cap_0f:8;
    };
}cbus1_msc_reg_0f_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  rchg_int_7:1;
        RBus_UInt32  rchg_int_6:1;
        RBus_UInt32  rchg_int_5:1;
        RBus_UInt32  cbus_3d_req:1;
        RBus_UInt32  grt_wrt:1;
        RBus_UInt32  req_wrt:1;
        RBus_UInt32  dscr_chg:1;
        RBus_UInt32  dcap_chg:1;
    };
}cbus1_msc_reg_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dchg_int_7:1;
        RBus_UInt32  dchg_int_6:1;
        RBus_UInt32  dchg_int_5:1;
        RBus_UInt32  dchg_int_4:1;
        RBus_UInt32  dchg_int_3:1;
        RBus_UInt32  dchg_int_2:1;
        RBus_UInt32  edid_chg:1;
        RBus_UInt32  dchg_int_0:1;
    };
}cbus1_msc_reg_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  chg22_7:1;
        RBus_UInt32  chg22_6:1;
        RBus_UInt32  chg22_5:1;
        RBus_UInt32  chg22_4:1;
        RBus_UInt32  chg22_3:1;
        RBus_UInt32  chg22_2:1;
        RBus_UInt32  chg22_1:1;
        RBus_UInt32  chg22_0:1;
    };
}cbus1_msc_reg_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  chg23_7:1;
        RBus_UInt32  chg23_6:1;
        RBus_UInt32  chg23_5:1;
        RBus_UInt32  chg23_4:1;
        RBus_UInt32  chg23_3:1;
        RBus_UInt32  chg23_2:1;
        RBus_UInt32  chg23_1:1;
        RBus_UInt32  chg23_0:1;
    };
}cbus1_msc_reg_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  chg24_7:1;
        RBus_UInt32  chg24_6:1;
        RBus_UInt32  chg24_5:1;
        RBus_UInt32  chg24_4:1;
        RBus_UInt32  chg24_3:1;
        RBus_UInt32  chg24_2:1;
        RBus_UInt32  chg24_1:1;
        RBus_UInt32  chg24_0:1;
    };
}cbus1_msc_reg_24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  chg25_7:1;
        RBus_UInt32  chg25_6:1;
        RBus_UInt32  chg25_5:1;
        RBus_UInt32  chg25_4:1;
        RBus_UInt32  chg25_3:1;
        RBus_UInt32  chg25_2:1;
        RBus_UInt32  chg25_1:1;
        RBus_UInt32  chg25_0:1;
    };
}cbus1_msc_reg_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  chg26_7:1;
        RBus_UInt32  chg26_6:1;
        RBus_UInt32  chg26_5:1;
        RBus_UInt32  chg26_4:1;
        RBus_UInt32  chg26_3:1;
        RBus_UInt32  chg26_2:1;
        RBus_UInt32  chg26_1:1;
        RBus_UInt32  chg26_0:1;
    };
}cbus1_msc_reg_26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  chg27_7:1;
        RBus_UInt32  chg27_6:1;
        RBus_UInt32  chg27_5:1;
        RBus_UInt32  chg27_4:1;
        RBus_UInt32  chg27_3:1;
        RBus_UInt32  chg27_2:1;
        RBus_UInt32  chg27_1:1;
        RBus_UInt32  chg27_0:1;
    };
}cbus1_msc_reg_27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  conn_rdy:7;
        RBus_UInt32  dcap_rdy:1;
    };
}cbus1_msc_reg_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  link_mode:3;
        RBus_UInt32  muted:1;
        RBus_UInt32  path_en:1;
        RBus_UInt32  clk_mode:3;
    };
}cbus1_msc_reg_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  stat_32:8;
    };
}cbus1_msc_reg_32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  stat_33:8;
    };
}cbus1_msc_reg_33_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  stat_34:8;
    };
}cbus1_msc_reg_34_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  stat_35:8;
    };
}cbus1_msc_reg_35_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  stat_36:8;
    };
}cbus1_msc_reg_36_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  stat_37:8;
    };
}cbus1_msc_reg_37_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  scratch_40:8;
    };
}cbus1_msc_reg_40_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  scratch_41:8;
    };
}cbus1_msc_reg_41_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  scratch_42:8;
    };
}cbus1_msc_reg_42_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  scratch_43:8;
    };
}cbus1_msc_reg_43_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  scratch_44:8;
    };
}cbus1_msc_reg_44_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  scratch_45:8;
    };
}cbus1_msc_reg_45_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  scratch_46:8;
    };
}cbus1_msc_reg_46_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  scratch_47:8;
    };
}cbus1_msc_reg_47_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  scratch_48:8;
    };
}cbus1_msc_reg_48_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  scratch_49:8;
    };
}cbus1_msc_reg_49_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  scratch_4a:8;
    };
}cbus1_msc_reg_4a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  scratch_4b:8;
    };
}cbus1_msc_reg_4b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  scratch_4c:8;
    };
}cbus1_msc_reg_4c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  scratch_4d:8;
    };
}cbus1_msc_reg_4d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  scratch_4e:8;
    };
}cbus1_msc_reg_4e_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  scratch_4f:8;
    };
}cbus1_msc_reg_4f_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  scratch_50:8;
    };
}cbus1_msc_reg_50_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  scratch_51:8;
    };
}cbus1_msc_reg_51_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  scratch_52:8;
    };
}cbus1_msc_reg_52_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  scratch_53:8;
    };
}cbus1_msc_reg_53_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  scratch_54:8;
    };
}cbus1_msc_reg_54_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  scratch_55:8;
    };
}cbus1_msc_reg_55_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  scratch_56:8;
    };
}cbus1_msc_reg_56_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  scratch_57:8;
    };
}cbus1_msc_reg_57_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  scratch_58:8;
    };
}cbus1_msc_reg_58_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  scratch_59:8;
    };
}cbus1_msc_reg_59_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  scratch_5a:8;
    };
}cbus1_msc_reg_5a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  scratch_5b:8;
    };
}cbus1_msc_reg_5b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  scratch_5c:8;
    };
}cbus1_msc_reg_5c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  scratch_5d:8;
    };
}cbus1_msc_reg_5d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  scratch_5e:8;
    };
}cbus1_msc_reg_5e_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  scratch_5f:8;
    };
}cbus1_msc_reg_5f_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  sync0_hb_8_0:9;
        RBus_UInt32  sync0_lb_8_0:9;
    };
}cbus1_cbus_link_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sync1_hb_7_0:8;
        RBus_UInt32  sync1_lb_7_0:8;
    };
}cbus1_cbus_link_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sync_bit_time:8;
    };
}cbus1_cbus_link_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  abs_thres_en:1;
        RBus_UInt32  abs_threshold:8;
    };
}cbus1_cbus_link_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  parity_time:8;
    };
}cbus1_cbus_link_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  parity_fail:1;
        RBus_UInt32  parity_irq_en:1;
        RBus_UInt32  ctrl_16_resv:1;
        RBus_UInt32  parity_limit:5;
    };
}cbus1_cbus_link_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  ack_fall:7;
    };
}cbus1_cbus_link_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  ack_0:7;
    };
}cbus1_cbus_link_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  tx_bit_time:8;
    };
}cbus1_cbus_link_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  chk_win_up:3;
        RBus_UInt32  chk_win_lo:2;
        RBus_UInt32  fast_reply_en:1;
        RBus_UInt32  ctrl_1b_resv:2;
    };
}cbus1_cbus_link_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  res2:1;
        RBus_UInt32  tx_ack_fal:7;
    };
}cbus1_cbus_link_0a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  tx_ack_low_hb:7;
    };
}cbus1_cbus_link_0b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  tx_ack_low_lb:7;
    };
}cbus1_cbus_link_0c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  retry_lv:3;
        RBus_UInt32  retry_flag:1;
        RBus_UInt32  ctrl_1f_resv:4;
    };
}cbus1_cbus_link_0d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  drv_str:2;
        RBus_UInt32  drv_hi_cbus:6;
    };
}cbus1_cbus_link_0e_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  wait:4;
        RBus_UInt32  req_opp_int:2;
    };
}cbus1_cbus_link_0f_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  req_opp_flt:8;
    };
}cbus1_cbus_link_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  req_cont:8;
    };
}cbus1_cbus_link_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  req_hold:4;
        RBus_UInt32  resp_hold:4;
    };
}cbus1_cbus_link_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  glob_time:2;
        RBus_UInt32  link_time:5;
        RBus_UInt32  link_err:1;
    };
}cbus1_cbus_link_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  chk_point:6;
        RBus_UInt32  chk_err:1;
        RBus_UInt32  avoid_conf:1;
    };
}cbus1_cbus_link_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  mcumsc_en:1;
        RBus_UInt32  msc_wait_arb:1;
        RBus_UInt32  ctrl_28_resv:4;
    };
}cbus1_cbus_msc_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  na_msc_cmd:8;
    };
}cbus1_cbus_msc_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  na_msc_offset:8;
    };
}cbus1_cbus_msc_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  rx_fifo_full:1;
        RBus_UInt32  rx_fifo_empty:1;
        RBus_UInt32  rx_fifo_clr:1;
        RBus_UInt32  na_rx_len:5;
    };
}cbus1_cbus_msc_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  rx_fifo_data:8;
    };
}cbus1_cbus_msc_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  fwdef_cmd_rev:8;
    };
}cbus1_cbus_msc_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ucp_irq:1;
        RBus_UInt32  ucpk_irq:1;
        RBus_UInt32  ucpe_irq:1;
        RBus_UInt32  dcap_rdy_chg:1;
        RBus_UInt32  muted_chg:1;
        RBus_UInt32  path_en_chg:1;
        RBus_UInt32  clk_mode_chg:1;
        RBus_UInt32  msge_irq:1;
        RBus_UInt32  rcp_irq:1;
        RBus_UInt32  rcpk_irq:1;
        RBus_UInt32  rcpe_irq:1;
        RBus_UInt32  rap_irq:1;
        RBus_UInt32  rapk_irq:1;
        RBus_UInt32  msg_sub_irq:1;
        RBus_UInt32  wr_stat_irq:1;
        RBus_UInt32  rd_devcap_irq:1;
        RBus_UInt32  get_stat_irq:1;
        RBus_UInt32  get_id_irq:1;
        RBus_UInt32  get_msg_irq:1;
        RBus_UInt32  sc1_err_irq:1;
        RBus_UInt32  ddc_err_irq:1;
        RBus_UInt32  msc_err_irq:1;
        RBus_UInt32  wr_burst_irq:1;
        RBus_UInt32  sc3_err_irq:1;
        RBus_UInt32  fwdef_cmd_irq:1;
        RBus_UInt32  allmsc_cmd_irq:1;
        RBus_UInt32  abort_res_irq:1;
        RBus_UInt32  abort_req_irq:1;
        RBus_UInt32  ddc_abort_irq:1;
    };
}cbus1_cbus_msc_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ucp_irq_en:1;
        RBus_UInt32  ucpk_irq_en:1;
        RBus_UInt32  ucpe_irq_en:1;
        RBus_UInt32  dcap_rdy_irq_en:1;
        RBus_UInt32  muted_chg_irq_en:1;
        RBus_UInt32  path_en_irq_en:1;
        RBus_UInt32  clk_mode_irq_en:1;
        RBus_UInt32  msge_irq_en:1;
        RBus_UInt32  rcp_irq_en:1;
        RBus_UInt32  rcpk_irq_en:1;
        RBus_UInt32  rcpe_irq_en:1;
        RBus_UInt32  rap_irq_en:1;
        RBus_UInt32  rapk_irq_en:1;
        RBus_UInt32  msg_sub_irq_en:1;
        RBus_UInt32  wr_stat_irq_en:1;
        RBus_UInt32  rd_devcap_irq_en:1;
        RBus_UInt32  get_stat_irq_en:1;
        RBus_UInt32  get_id_irq_en:1;
        RBus_UInt32  get_msg_irq_en:1;
        RBus_UInt32  sc1_err_irq_en:1;
        RBus_UInt32  ddc_err_irq_en:1;
        RBus_UInt32  msc_err_irq_en:1;
        RBus_UInt32  wr_burst_irq_en:1;
        RBus_UInt32  sc3_err_irq_en:1;
        RBus_UInt32  fwdef_cmd_irq_en:1;
        RBus_UInt32  allmsc_cmd_irq_en:1;
        RBus_UInt32  abort_res_irq_en:1;
        RBus_UInt32  abort_req_irq_en:1;
        RBus_UInt32  ddc_abort_irq_en:1;
    };
}cbus1_cbus_msc_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rchg_irq_en:3;
        RBus_UInt32  cbus_3d_req_irq_en:1;
        RBus_UInt32  grt_irq_en:1;
        RBus_UInt32  req_irq_en:1;
        RBus_UInt32  dscr_irq_en:1;
        RBus_UInt32  dcap_irq_en:1;
        RBus_UInt32  dchg_bit7_irq_en:1;
        RBus_UInt32  dchg_bit6_irq_en:1;
        RBus_UInt32  dchg_bit5_irq_en:1;
        RBus_UInt32  dchg_bit4_irq_en:1;
        RBus_UInt32  dchg_bit3_irq_en:1;
        RBus_UInt32  dchg_bit2_irq_en:1;
        RBus_UInt32  edid_irq_en:1;
        RBus_UInt32  dchg_bit0_irq_en:1;
        RBus_UInt32  chg22_irq_en:8;
        RBus_UInt32  chg23_irq_en:8;
    };
}cbus1_cbus_msc_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chg24_irq_en:8;
        RBus_UInt32  chg25_irq_en:8;
        RBus_UInt32  chg26_irq_en:8;
        RBus_UInt32  chg27_irq_en:8;
    };
}cbus1_cbus_msc_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  msc_err_code:8;
    };
}cbus1_cbus_msc_0a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  rcp_reply_abort:1;
        RBus_UInt32  rcp_reply_nack:1;
        RBus_UInt32  vendor_id:8;
    };
}cbus1_cbus_msc_0b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  msg_cmd:8;
    };
}cbus1_cbus_msc_0c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  msg_dat:8;
    };
}cbus1_cbus_msc_0d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  msge_rcv:8;
    };
}cbus1_cbus_msc_0e_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  rcp_rcv:8;
    };
}cbus1_cbus_msc_0f_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  rcpk_rcv:8;
    };
}cbus1_cbus_msc_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  rcpe_rcv:8;
    };
}cbus1_cbus_msc_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  rap_rcv:8;
    };
}cbus1_cbus_msc_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  rapk_rcv:8;
    };
}cbus1_cbus_msc_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  burst_timeout:1;
        RBus_UInt32  wb_id_chk:1;
        RBus_UInt32  burst_wait:4;
    };
}cbus1_cbus_msc_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  adop_idh_rcv:8;
        RBus_UInt32  adop_idl_rcv:8;
    };
}cbus1_cbus_msc_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  auto_handshake:1;
        RBus_UInt32  insert_id:1;
        RBus_UInt32  wb_byte_num0:6;
        RBus_UInt32  wb_byte_num1:6;
        RBus_UInt32  adop_txid_h:8;
        RBus_UInt32  adop_txid_l:8;
    };
}cbus1_cbus_msc_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  que_fsm_clr:1;
        RBus_UInt32  sch_fsm_clr:1;
        RBus_UInt32  spi_fsm_clr:1;
    };
}cbus1_cbus_msc_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  que_fsm:4;
        RBus_UInt32  sch_fsm:4;
        RBus_UInt32  spi_fsm:4;
    };
}cbus1_cbus_msc_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cap_offset:8;
    };
}cbus1_cbus_msc_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  int_offset:8;
    };
}cbus1_cbus_msc_1a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sta_offset:8;
    };
}cbus1_cbus_msc_1b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  scr_offset:8;
    };
}cbus1_cbus_msc_1c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  ddc_err_force:1;
        RBus_UInt32  msc_err_force:1;
    };
}cbus1_cbus_msc_1d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ddc_err_fw:8;
    };
}cbus1_cbus_msc_1e_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  msc_err_fw:8;
    };
}cbus1_cbus_msc_1f_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ucp_rcv:8;
    };
}cbus1_cbus_msc_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ucpk_rcv:8;
    };
}cbus1_cbus_msc_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ucpe_rcv:8;
    };
}cbus1_cbus_msc_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  fw0_req:1;
        RBus_UInt32  fw0_fifo_clr:1;
        RBus_UInt32  fw0_fifo_full:1;
        RBus_UInt32  fw0_fifo_empty:1;
        RBus_UInt32  fw0_tx_case:3;
        RBus_UInt32  fw0_head:2;
    };
}cbus1_fw0_req_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  fw0_cmd1:8;
    };
}cbus1_fw0_req_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  fw0_cmd2:8;
    };
}cbus1_fw0_req_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  fw0_offset:8;
    };
}cbus1_fw0_req_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  fw0_data:8;
    };
}cbus1_fw0_req_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  fw0_rty_ovr:1;
        RBus_UInt32  fw0_fin:1;
        RBus_UInt32  fw0_cmd_event:1;
        RBus_UInt32  fw0_data_event:1;
        RBus_UInt32  fw0_rcv_err:1;
        RBus_UInt32  fw0_fin_irq_en:1;
        RBus_UInt32  fw0_cmd_irq_en:1;
        RBus_UInt32  fw0_data_irq_en:1;
        RBus_UInt32  fw0_wait_case:2;
    };
}cbus1_fw0_req_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  fw0_cmd_rcv:8;
    };
}cbus1_fw0_req_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  fw0_data_rcv:8;
    };
}cbus1_fw0_req_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  fw0_rd_en:1;
        RBus_UInt32  fw0_fifo_len:5;
        RBus_UInt32  fw0_rdata:8;
    };
}cbus1_fw0_req_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ddc_err_code:8;
    };
}cbus1_cbus_ddc_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  iic_ck_tgt:8;
    };
}cbus1_cbus_ddc_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  mcuddc_en:1;
        RBus_UInt32  ddc_prior_dis:1;
        RBus_UInt32  ddc_cmd_event:1;
        RBus_UInt32  ddc_data_event:1;
        RBus_UInt32  ddc_cmd_irq_en:1;
        RBus_UInt32  ddc_data_irq_en:1;
        RBus_UInt32  ddc_req_ctrl:1;
        RBus_UInt32  ddc_req:1;
    };
}cbus1_cbus_ddc_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ddc_rcv_cmd:8;
    };
}cbus1_cbus_ddc_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ddc_rcv_data:8;
    };
}cbus1_cbus_ddc_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ddc_data_fw:8;
    };
}cbus1_cbus_ddc_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  ddc_eof_irq:1;
        RBus_UInt32  ddc_eof_irq_en:1;
        RBus_UInt32  ddcrd_rst_en:1;
        RBus_UInt32  ddcrd_new_md:1;
    };
}cbus1_cbus_ddc_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  clk_mod_vwd:1;
        RBus_UInt32  clk_mod_awd:1;
        RBus_UInt32  mute_en_vwd:1;
        RBus_UInt32  mute_en_awd:1;
        RBus_UInt32  path_en_off_vwd:1;
        RBus_UInt32  path_en_off_awd:1;
    };
}cbus1_cbus_wdog_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  arbiter_irq:1;
        RBus_UInt32  ddc_irq:1;
        RBus_UInt32  msc_ch_irq:1;
        RBus_UInt32  msc_int_irq:1;
        RBus_UInt32  msc_stat_irq:1;
        RBus_UInt32  ctrl_01_resv:1;
    };
}cbus1_cbus_int_index_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cbus_test_md:2;
        RBus_UInt32  fw_out:1;
        RBus_UInt32  dbg_sel:3;
        RBus_UInt32  res2:2;
    };
}cbus1_cbus_test_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cbus_dummy0:32;
    };
}cbus1_cbus_dummy0_RBUS;

#else //apply LITTLE_ENDIAN

//======CBUS1 register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dis_irq_en:1;
        RBus_UInt32  wake_irq_en:1;
        RBus_UInt32  dis_pulse_det:1;
        RBus_UInt32  wake_pulse_det:1;
        RBus_UInt32  res1:28;
    };
}cbus1_cbus_standby_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clk_1k_div:10;
        RBus_UInt32  clk_1m_div:4;
        RBus_UInt32  res1:18;
    };
}cbus1_cbus_standby_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disconn:2;
        RBus_UInt32  deb_lv:3;
        RBus_UInt32  dis_deb_lv:3;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_standby_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disconn_irq_en:1;
        RBus_UInt32  cbus_disconn:1;
        RBus_UInt32  wake_offset:5;
        RBus_UInt32  wake_cnt:3;
        RBus_UInt32  wake_offset_low:5;
        RBus_UInt32  wake_offset_low2:5;
        RBus_UInt32  res1:12;
    };
}cbus1_cbus_standby_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wake_eco_en:1;
        RBus_UInt32  dis_lower:3;
        RBus_UInt32  dis_upper:4;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_standby_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dis_num:5;
        RBus_UInt32  wake_num:3;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_standby_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cbus_in_sig:1;
        RBus_UInt32  cbus_1k_en:1;
        RBus_UInt32  cbus_100k_en:1;
        RBus_UInt32  sink_fsm_st:3;
        RBus_UInt32  bypass_mode:1;
        RBus_UInt32  cbus_imp_auto:1;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_standby_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg_sel_phy:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  cable_det:1;
        RBus_UInt32  goto_sink1:1;
        RBus_UInt32  goto_float:1;
        RBus_UInt32  goto_sink1_pos:1;
        RBus_UInt32  res2:26;
    };
}cbus1_cbus_standby_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ctrl_09_resv:32;
    };
}cbus1_cbus_standby_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cbus_e:1;
        RBus_UInt32  cbus_e2:1;
        RBus_UInt32  cbus_i:1;
        RBus_UInt32  cbus_pd:1;
        RBus_UInt32  cbus_pu:1;
        RBus_UInt32  cbus_smt:1;
        RBus_UInt32  cbus_sr:1;
        RBus_UInt32  res1:25;
    };
}cbus1_cbus_phy_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sel_cbusb_gpio:1;
        RBus_UInt32  psm_cbus:1;
        RBus_UInt32  en_ldo_cbus:1;
        RBus_UInt32  en_driver_cbus:1;
        RBus_UInt32  en_cmp_cbus:1;
        RBus_UInt32  en_cbus:1;
        RBus_UInt32  triming_mode:1;
        RBus_UInt32  trim_ldo_cbus:4;
        RBus_UInt32  sel_vref_ldo:2;
        RBus_UInt32  sel_cbus_0_driving:3;
        RBus_UInt32  sel_cbus0_input_low:2;
        RBus_UInt32  sel_cbus0_input_high:2;
        RBus_UInt32  en_res_cal_cbus:1;
        RBus_UInt32  auto_k_100k:1;
        RBus_UInt32  auto_k_1k:1;
        RBus_UInt32  adjr_100k:5;
        RBus_UInt32  adjr_1k:4;
    };
}cbus1_cbus_phy_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cbus_o:1;
        RBus_UInt32  res1:31;
    };
}cbus1_cbus_phy_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res_ok:1;
        RBus_UInt32  cbus_res_tst:10;
        RBus_UInt32  sel_phy_soft_rst_n:1;
        RBus_UInt32  res1:20;
    };
}cbus1_cbus_phy_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dev_state:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mhl_ver:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dev_type:4;
        RBus_UInt32  pow:1;
        RBus_UInt32  plim:2;
        RBus_UInt32  dev_cat:1;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adop_id_h:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adop_id_l:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  supp_rgb444:1;
        RBus_UInt32  supp_yuv444:1;
        RBus_UInt32  supp_yuv422:1;
        RBus_UInt32  supp_ppixel:1;
        RBus_UInt32  supp_islands:1;
        RBus_UInt32  supp_vga:1;
        RBus_UInt32  vid_link_md:2;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  aud_2ch:1;
        RBus_UInt32  aud_8ch:1;
        RBus_UInt32  aud_link_md:6;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vt_graphics:1;
        RBus_UInt32  vt_photo:1;
        RBus_UInt32  vt_cinema:1;
        RBus_UInt32  vt_game:1;
        RBus_UInt32  video_type:3;
        RBus_UInt32  supp_vt:1;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_display:1;
        RBus_UInt32  ld_video:1;
        RBus_UInt32  ld_audio:1;
        RBus_UInt32  ld_media:1;
        RBus_UInt32  ld_tuner:1;
        RBus_UInt32  ld_record:1;
        RBus_UInt32  ld_speaker:1;
        RBus_UInt32  ld_gui:1;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bandwid:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rcp_supp:1;
        RBus_UInt32  rap_supp:1;
        RBus_UInt32  sp_supp:1;
        RBus_UInt32  ucp_send_supp:1;
        RBus_UInt32  ucp_recv_supp:1;
        RBus_UInt32  feature_flag:3;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_0a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  device_id_h:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_0b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  device_id_l:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_0c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scr_size:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_0d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_size:4;
        RBus_UInt32  stat_size:4;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_0e_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_0f:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_0f_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dcap_chg:1;
        RBus_UInt32  dscr_chg:1;
        RBus_UInt32  req_wrt:1;
        RBus_UInt32  grt_wrt:1;
        RBus_UInt32  cbus_3d_req:1;
        RBus_UInt32  rchg_int_5:1;
        RBus_UInt32  rchg_int_6:1;
        RBus_UInt32  rchg_int_7:1;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dchg_int_0:1;
        RBus_UInt32  edid_chg:1;
        RBus_UInt32  dchg_int_2:1;
        RBus_UInt32  dchg_int_3:1;
        RBus_UInt32  dchg_int_4:1;
        RBus_UInt32  dchg_int_5:1;
        RBus_UInt32  dchg_int_6:1;
        RBus_UInt32  dchg_int_7:1;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chg22_0:1;
        RBus_UInt32  chg22_1:1;
        RBus_UInt32  chg22_2:1;
        RBus_UInt32  chg22_3:1;
        RBus_UInt32  chg22_4:1;
        RBus_UInt32  chg22_5:1;
        RBus_UInt32  chg22_6:1;
        RBus_UInt32  chg22_7:1;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chg23_0:1;
        RBus_UInt32  chg23_1:1;
        RBus_UInt32  chg23_2:1;
        RBus_UInt32  chg23_3:1;
        RBus_UInt32  chg23_4:1;
        RBus_UInt32  chg23_5:1;
        RBus_UInt32  chg23_6:1;
        RBus_UInt32  chg23_7:1;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chg24_0:1;
        RBus_UInt32  chg24_1:1;
        RBus_UInt32  chg24_2:1;
        RBus_UInt32  chg24_3:1;
        RBus_UInt32  chg24_4:1;
        RBus_UInt32  chg24_5:1;
        RBus_UInt32  chg24_6:1;
        RBus_UInt32  chg24_7:1;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chg25_0:1;
        RBus_UInt32  chg25_1:1;
        RBus_UInt32  chg25_2:1;
        RBus_UInt32  chg25_3:1;
        RBus_UInt32  chg25_4:1;
        RBus_UInt32  chg25_5:1;
        RBus_UInt32  chg25_6:1;
        RBus_UInt32  chg25_7:1;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chg26_0:1;
        RBus_UInt32  chg26_1:1;
        RBus_UInt32  chg26_2:1;
        RBus_UInt32  chg26_3:1;
        RBus_UInt32  chg26_4:1;
        RBus_UInt32  chg26_5:1;
        RBus_UInt32  chg26_6:1;
        RBus_UInt32  chg26_7:1;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chg27_0:1;
        RBus_UInt32  chg27_1:1;
        RBus_UInt32  chg27_2:1;
        RBus_UInt32  chg27_3:1;
        RBus_UInt32  chg27_4:1;
        RBus_UInt32  chg27_5:1;
        RBus_UInt32  chg27_6:1;
        RBus_UInt32  chg27_7:1;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dcap_rdy:1;
        RBus_UInt32  conn_rdy:7;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clk_mode:3;
        RBus_UInt32  path_en:1;
        RBus_UInt32  muted:1;
        RBus_UInt32  link_mode:3;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stat_32:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stat_33:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_33_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stat_34:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_34_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stat_35:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_35_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stat_36:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_36_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stat_37:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_37_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scratch_40:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_40_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scratch_41:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_41_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scratch_42:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_42_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scratch_43:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_43_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scratch_44:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_44_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scratch_45:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_45_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scratch_46:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_46_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scratch_47:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_47_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scratch_48:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_48_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scratch_49:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_49_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scratch_4a:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_4a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scratch_4b:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_4b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scratch_4c:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_4c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scratch_4d:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_4d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scratch_4e:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_4e_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scratch_4f:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_4f_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scratch_50:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_50_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scratch_51:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_51_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scratch_52:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_52_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scratch_53:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_53_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scratch_54:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_54_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scratch_55:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_55_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scratch_56:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_56_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scratch_57:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_57_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scratch_58:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_58_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scratch_59:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_59_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scratch_5a:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_5a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scratch_5b:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_5b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scratch_5c:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_5c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scratch_5d:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_5d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scratch_5e:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_5e_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scratch_5f:8;
        RBus_UInt32  res1:24;
    };
}cbus1_msc_reg_5f_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sync0_lb_8_0:9;
        RBus_UInt32  sync0_hb_8_0:9;
        RBus_UInt32  res1:14;
    };
}cbus1_cbus_link_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sync1_lb_7_0:8;
        RBus_UInt32  sync1_hb_7_0:8;
        RBus_UInt32  res1:16;
    };
}cbus1_cbus_link_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sync_bit_time:8;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_link_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  abs_threshold:8;
        RBus_UInt32  abs_thres_en:1;
        RBus_UInt32  res1:23;
    };
}cbus1_cbus_link_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  parity_time:8;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_link_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  parity_limit:5;
        RBus_UInt32  ctrl_16_resv:1;
        RBus_UInt32  parity_irq_en:1;
        RBus_UInt32  parity_fail:1;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_link_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ack_fall:7;
        RBus_UInt32  res1:25;
    };
}cbus1_cbus_link_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ack_0:7;
        RBus_UInt32  res1:25;
    };
}cbus1_cbus_link_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx_bit_time:8;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_link_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ctrl_1b_resv:2;
        RBus_UInt32  fast_reply_en:1;
        RBus_UInt32  chk_win_lo:2;
        RBus_UInt32  chk_win_up:3;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_link_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx_ack_fal:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:24;
    };
}cbus1_cbus_link_0a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx_ack_low_hb:7;
        RBus_UInt32  res1:25;
    };
}cbus1_cbus_link_0b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx_ack_low_lb:7;
        RBus_UInt32  res1:25;
    };
}cbus1_cbus_link_0c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ctrl_1f_resv:4;
        RBus_UInt32  retry_flag:1;
        RBus_UInt32  retry_lv:3;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_link_0d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drv_hi_cbus:6;
        RBus_UInt32  drv_str:2;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_link_0e_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  req_opp_int:2;
        RBus_UInt32  wait:4;
        RBus_UInt32  res1:26;
    };
}cbus1_cbus_link_0f_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  req_opp_flt:8;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_link_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  req_cont:8;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_link_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  resp_hold:4;
        RBus_UInt32  req_hold:4;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_link_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  link_err:1;
        RBus_UInt32  link_time:5;
        RBus_UInt32  glob_time:2;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_link_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avoid_conf:1;
        RBus_UInt32  chk_err:1;
        RBus_UInt32  chk_point:6;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_link_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ctrl_28_resv:4;
        RBus_UInt32  msc_wait_arb:1;
        RBus_UInt32  mcumsc_en:1;
        RBus_UInt32  res1:26;
    };
}cbus1_cbus_msc_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  na_msc_cmd:8;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_msc_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  na_msc_offset:8;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_msc_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  na_rx_len:5;
        RBus_UInt32  rx_fifo_clr:1;
        RBus_UInt32  rx_fifo_empty:1;
        RBus_UInt32  rx_fifo_full:1;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_msc_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rx_fifo_data:8;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_msc_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fwdef_cmd_rev:8;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_msc_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ddc_abort_irq:1;
        RBus_UInt32  abort_req_irq:1;
        RBus_UInt32  abort_res_irq:1;
        RBus_UInt32  allmsc_cmd_irq:1;
        RBus_UInt32  fwdef_cmd_irq:1;
        RBus_UInt32  sc3_err_irq:1;
        RBus_UInt32  wr_burst_irq:1;
        RBus_UInt32  msc_err_irq:1;
        RBus_UInt32  ddc_err_irq:1;
        RBus_UInt32  sc1_err_irq:1;
        RBus_UInt32  get_msg_irq:1;
        RBus_UInt32  get_id_irq:1;
        RBus_UInt32  get_stat_irq:1;
        RBus_UInt32  rd_devcap_irq:1;
        RBus_UInt32  wr_stat_irq:1;
        RBus_UInt32  msg_sub_irq:1;
        RBus_UInt32  rapk_irq:1;
        RBus_UInt32  rap_irq:1;
        RBus_UInt32  rcpe_irq:1;
        RBus_UInt32  rcpk_irq:1;
        RBus_UInt32  rcp_irq:1;
        RBus_UInt32  msge_irq:1;
        RBus_UInt32  clk_mode_chg:1;
        RBus_UInt32  path_en_chg:1;
        RBus_UInt32  muted_chg:1;
        RBus_UInt32  dcap_rdy_chg:1;
        RBus_UInt32  ucpe_irq:1;
        RBus_UInt32  ucpk_irq:1;
        RBus_UInt32  ucp_irq:1;
        RBus_UInt32  res1:3;
    };
}cbus1_cbus_msc_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ddc_abort_irq_en:1;
        RBus_UInt32  abort_req_irq_en:1;
        RBus_UInt32  abort_res_irq_en:1;
        RBus_UInt32  allmsc_cmd_irq_en:1;
        RBus_UInt32  fwdef_cmd_irq_en:1;
        RBus_UInt32  sc3_err_irq_en:1;
        RBus_UInt32  wr_burst_irq_en:1;
        RBus_UInt32  msc_err_irq_en:1;
        RBus_UInt32  ddc_err_irq_en:1;
        RBus_UInt32  sc1_err_irq_en:1;
        RBus_UInt32  get_msg_irq_en:1;
        RBus_UInt32  get_id_irq_en:1;
        RBus_UInt32  get_stat_irq_en:1;
        RBus_UInt32  rd_devcap_irq_en:1;
        RBus_UInt32  wr_stat_irq_en:1;
        RBus_UInt32  msg_sub_irq_en:1;
        RBus_UInt32  rapk_irq_en:1;
        RBus_UInt32  rap_irq_en:1;
        RBus_UInt32  rcpe_irq_en:1;
        RBus_UInt32  rcpk_irq_en:1;
        RBus_UInt32  rcp_irq_en:1;
        RBus_UInt32  msge_irq_en:1;
        RBus_UInt32  clk_mode_irq_en:1;
        RBus_UInt32  path_en_irq_en:1;
        RBus_UInt32  muted_chg_irq_en:1;
        RBus_UInt32  dcap_rdy_irq_en:1;
        RBus_UInt32  ucpe_irq_en:1;
        RBus_UInt32  ucpk_irq_en:1;
        RBus_UInt32  ucp_irq_en:1;
        RBus_UInt32  res1:3;
    };
}cbus1_cbus_msc_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chg23_irq_en:8;
        RBus_UInt32  chg22_irq_en:8;
        RBus_UInt32  dchg_bit0_irq_en:1;
        RBus_UInt32  edid_irq_en:1;
        RBus_UInt32  dchg_bit2_irq_en:1;
        RBus_UInt32  dchg_bit3_irq_en:1;
        RBus_UInt32  dchg_bit4_irq_en:1;
        RBus_UInt32  dchg_bit5_irq_en:1;
        RBus_UInt32  dchg_bit6_irq_en:1;
        RBus_UInt32  dchg_bit7_irq_en:1;
        RBus_UInt32  dcap_irq_en:1;
        RBus_UInt32  dscr_irq_en:1;
        RBus_UInt32  req_irq_en:1;
        RBus_UInt32  grt_irq_en:1;
        RBus_UInt32  cbus_3d_req_irq_en:1;
        RBus_UInt32  rchg_irq_en:3;
    };
}cbus1_cbus_msc_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chg27_irq_en:8;
        RBus_UInt32  chg26_irq_en:8;
        RBus_UInt32  chg25_irq_en:8;
        RBus_UInt32  chg24_irq_en:8;
    };
}cbus1_cbus_msc_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  msc_err_code:8;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_msc_0a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vendor_id:8;
        RBus_UInt32  rcp_reply_nack:1;
        RBus_UInt32  rcp_reply_abort:1;
        RBus_UInt32  res1:22;
    };
}cbus1_cbus_msc_0b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  msg_cmd:8;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_msc_0c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  msg_dat:8;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_msc_0d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  msge_rcv:8;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_msc_0e_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rcp_rcv:8;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_msc_0f_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rcpk_rcv:8;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_msc_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rcpe_rcv:8;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_msc_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rap_rcv:8;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_msc_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rapk_rcv:8;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_msc_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  burst_wait:4;
        RBus_UInt32  wb_id_chk:1;
        RBus_UInt32  burst_timeout:1;
        RBus_UInt32  res1:26;
    };
}cbus1_cbus_msc_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adop_idl_rcv:8;
        RBus_UInt32  adop_idh_rcv:8;
        RBus_UInt32  res1:16;
    };
}cbus1_cbus_msc_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adop_txid_l:8;
        RBus_UInt32  adop_txid_h:8;
        RBus_UInt32  wb_byte_num1:6;
        RBus_UInt32  wb_byte_num0:6;
        RBus_UInt32  insert_id:1;
        RBus_UInt32  auto_handshake:1;
        RBus_UInt32  res1:2;
    };
}cbus1_cbus_msc_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  spi_fsm_clr:1;
        RBus_UInt32  sch_fsm_clr:1;
        RBus_UInt32  que_fsm_clr:1;
        RBus_UInt32  res1:29;
    };
}cbus1_cbus_msc_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  spi_fsm:4;
        RBus_UInt32  sch_fsm:4;
        RBus_UInt32  que_fsm:4;
        RBus_UInt32  res1:20;
    };
}cbus1_cbus_msc_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_offset:8;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_msc_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_offset:8;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_msc_1a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sta_offset:8;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_msc_1b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scr_offset:8;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_msc_1c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  msc_err_force:1;
        RBus_UInt32  ddc_err_force:1;
        RBus_UInt32  res1:30;
    };
}cbus1_cbus_msc_1d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ddc_err_fw:8;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_msc_1e_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  msc_err_fw:8;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_msc_1f_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ucp_rcv:8;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_msc_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ucpk_rcv:8;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_msc_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ucpe_rcv:8;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_msc_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fw0_head:2;
        RBus_UInt32  fw0_tx_case:3;
        RBus_UInt32  fw0_fifo_empty:1;
        RBus_UInt32  fw0_fifo_full:1;
        RBus_UInt32  fw0_fifo_clr:1;
        RBus_UInt32  fw0_req:1;
        RBus_UInt32  res1:23;
    };
}cbus1_fw0_req_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fw0_cmd1:8;
        RBus_UInt32  res1:24;
    };
}cbus1_fw0_req_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fw0_cmd2:8;
        RBus_UInt32  res1:24;
    };
}cbus1_fw0_req_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fw0_offset:8;
        RBus_UInt32  res1:24;
    };
}cbus1_fw0_req_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fw0_data:8;
        RBus_UInt32  res1:24;
    };
}cbus1_fw0_req_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fw0_wait_case:2;
        RBus_UInt32  fw0_data_irq_en:1;
        RBus_UInt32  fw0_cmd_irq_en:1;
        RBus_UInt32  fw0_fin_irq_en:1;
        RBus_UInt32  fw0_rcv_err:1;
        RBus_UInt32  fw0_data_event:1;
        RBus_UInt32  fw0_cmd_event:1;
        RBus_UInt32  fw0_fin:1;
        RBus_UInt32  fw0_rty_ovr:1;
        RBus_UInt32  res1:22;
    };
}cbus1_fw0_req_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fw0_cmd_rcv:8;
        RBus_UInt32  res1:24;
    };
}cbus1_fw0_req_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fw0_data_rcv:8;
        RBus_UInt32  res1:24;
    };
}cbus1_fw0_req_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fw0_rdata:8;
        RBus_UInt32  fw0_fifo_len:5;
        RBus_UInt32  fw0_rd_en:1;
        RBus_UInt32  res1:18;
    };
}cbus1_fw0_req_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ddc_err_code:8;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_ddc_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  iic_ck_tgt:8;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_ddc_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ddc_req:1;
        RBus_UInt32  ddc_req_ctrl:1;
        RBus_UInt32  ddc_data_irq_en:1;
        RBus_UInt32  ddc_cmd_irq_en:1;
        RBus_UInt32  ddc_data_event:1;
        RBus_UInt32  ddc_cmd_event:1;
        RBus_UInt32  ddc_prior_dis:1;
        RBus_UInt32  mcuddc_en:1;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_ddc_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ddc_rcv_cmd:8;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_ddc_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ddc_rcv_data:8;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_ddc_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ddc_data_fw:8;
        RBus_UInt32  res1:24;
    };
}cbus1_cbus_ddc_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ddcrd_new_md:1;
        RBus_UInt32  ddcrd_rst_en:1;
        RBus_UInt32  ddc_eof_irq_en:1;
        RBus_UInt32  ddc_eof_irq:1;
        RBus_UInt32  res1:28;
    };
}cbus1_cbus_ddc_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  path_en_off_awd:1;
        RBus_UInt32  path_en_off_vwd:1;
        RBus_UInt32  mute_en_awd:1;
        RBus_UInt32  mute_en_vwd:1;
        RBus_UInt32  clk_mod_awd:1;
        RBus_UInt32  clk_mod_vwd:1;
        RBus_UInt32  res1:26;
    };
}cbus1_cbus_wdog_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ctrl_01_resv:1;
        RBus_UInt32  msc_stat_irq:1;
        RBus_UInt32  msc_int_irq:1;
        RBus_UInt32  msc_ch_irq:1;
        RBus_UInt32  ddc_irq:1;
        RBus_UInt32  arbiter_irq:1;
        RBus_UInt32  res1:26;
    };
}cbus1_cbus_int_index_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  dbg_sel:3;
        RBus_UInt32  fw_out:1;
        RBus_UInt32  cbus_test_md:2;
        RBus_UInt32  res2:24;
    };
}cbus1_cbus_test_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cbus_dummy0:32;
    };
}cbus1_cbus_dummy0_RBUS;




#endif 

//  MHL Register Address



#define  MHL_MHL_DAL_CTRL_VADDR                             	(0xb800d600)
#define  MHL_MHL_DAL_STATUS_VADDR                           	(0xb800d604)
#define  MHL_MHL_MD_CTRL_VADDR                              	(0xb800d608)
#define  MHL_MHL_MD_THRESHOLD_VADDR                         	(0xb800d60c)
#define  MHL_MHL_MD_CNT_VADDR                               	(0xb800d610)
#define  MHL_MHL_DEMUX_CTRL_VADDR                           	(0xb800d614)
#define  MHL_MHL_STATUS_VADDR                               	(0xb800d618)
#define  MHL_MHL_CH_CR_VADDR                                	(0xb800d61c)
#define  MHL_MHL_CH_SR_VADDR                                	(0xb800d620)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======MHL register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clk25xinv_r:1;
        RBus_UInt32  clk25xinv_g:1;
        RBus_UInt32  clk25xinv_b:1;
        RBus_UInt32  mhl_de_sel:1;
        RBus_UInt32  mhl_tran_err_thrd:4;
        RBus_UInt32  mhl_neg_de_err_thrd:4;
        RBus_UInt32  mhl_pos_de_err_thrd:4;
        RBus_UInt32  b_r_ch_sel:1;
        RBus_UInt32  mhl_neg_de_lowbd:7;
        RBus_UInt32  mhl_rclkinv:1;
        RBus_UInt32  mhl_bclkinv:1;
        RBus_UInt32  mhl_pos_de_lowbd:6;
    };
}mhl_mhl_dal_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  mhl_de_glitch_cycle:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  mhl_ver_1_2:1;
        RBus_UInt32  mhl_de_glitch_en:1;
        RBus_UInt32  pn_swap:1;
    };
}mhl_mhl_dal_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  mhl_mode_err_wd:1;
        RBus_UInt32  mhl_mode_err_int:1;
        RBus_UInt32  mhl_mode:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  mhl_mode_det_per_sel:1;
        RBus_UInt32  mhl_mode_det_per:16;
        RBus_UInt32  mhl_mode_det:2;
        RBus_UInt32  mhl_mode_det_cont:1;
        RBus_UInt32  mhl_mode_det_start:1;
    };
}mhl_mhl_md_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  threshold_pp:16;
        RBus_UInt32  threshold_24bits:16;
    };
}mhl_mhl_md_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  det_cnt_pp:16;
        RBus_UInt32  det_cnt_24bit:16;
    };
}mhl_mhl_md_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  video_wd_en:1;
        RBus_UInt32  audio_wd_en:1;
        RBus_UInt32  ch_bound_chg_wd_en:1;
        RBus_UInt32  ch_bound_chg_int_en:1;
        RBus_UInt32  ch_bound_chg_det:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  demux_sel:3;
        RBus_UInt32  dvi_ch_sync:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  mhl_pp_en:1;
        RBus_UInt32  mhl_en:1;
    };
}mhl_mhl_demux_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  ch_bound_chg:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  mhl_mode_err:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  non_ctrl_glitch_occ_flag:1;
        RBus_UInt32  ctrl_glitch_occr_flag:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  mhl_tran_err_flag:1;
        RBus_UInt32  mhl_pos_de_err_flag:1;
        RBus_UInt32  mhl_neg_de_err_flag:1;
    };
}mhl_mhl_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  mhl_ch1_cr_flush:1;
        RBus_UInt32  mhl_ch1_cr_afifo_en:1;
        RBus_UInt32  dummy1800d61c_15_2:14;
        RBus_UInt32  mhl_ch0_cr_flush:1;
        RBus_UInt32  mhl_ch0_cr_afifo_en:1;
    };
}mhl_mhl_ch_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  mhl_ch1_sr_wrclk_det_timeout_flag:1;
        RBus_UInt32  mhl_ch1_sr_rwclk_det_timeout_flag:1;
        RBus_UInt32  mhl_ch1_sr_wovflow_flag:1;
        RBus_UInt32  mhl_ch1_sr_rudflow_flag:1;
        RBus_UInt32  mhl_ch1_sr_rflush_flag:1;
        RBus_UInt32  dummy1800d620_15_5:11;
        RBus_UInt32  mhl_ch0_sr_wrclk_det_timeout_flag:1;
        RBus_UInt32  mhl_ch0_sr_rwclk_det_timeout_flag:1;
        RBus_UInt32  mhl_ch0_sr_wovflow_flag:1;
        RBus_UInt32  mhl_ch0_sr_rudflow_flag:1;
        RBus_UInt32  mhl_ch0_sr_rflush_flag:1;
    };
}mhl_mhl_ch_sr_RBUS;

#else //apply LITTLE_ENDIAN

//======MHL register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mhl_pos_de_lowbd:6;
        RBus_UInt32  mhl_bclkinv:1;
        RBus_UInt32  mhl_rclkinv:1;
        RBus_UInt32  mhl_neg_de_lowbd:7;
        RBus_UInt32  b_r_ch_sel:1;
        RBus_UInt32  mhl_pos_de_err_thrd:4;
        RBus_UInt32  mhl_neg_de_err_thrd:4;
        RBus_UInt32  mhl_tran_err_thrd:4;
        RBus_UInt32  mhl_de_sel:1;
        RBus_UInt32  clk25xinv_b:1;
        RBus_UInt32  clk25xinv_g:1;
        RBus_UInt32  clk25xinv_r:1;
    };
}mhl_mhl_dal_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pn_swap:1;
        RBus_UInt32  mhl_de_glitch_en:1;
        RBus_UInt32  mhl_ver_1_2:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  mhl_de_glitch_cycle:4;
        RBus_UInt32  res2:24;
    };
}mhl_mhl_dal_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mhl_mode_det_start:1;
        RBus_UInt32  mhl_mode_det_cont:1;
        RBus_UInt32  mhl_mode_det:2;
        RBus_UInt32  mhl_mode_det_per:16;
        RBus_UInt32  mhl_mode_det_per_sel:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  mhl_mode:1;
        RBus_UInt32  mhl_mode_err_int:1;
        RBus_UInt32  mhl_mode_err_wd:1;
        RBus_UInt32  res2:5;
    };
}mhl_mhl_md_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  threshold_24bits:16;
        RBus_UInt32  threshold_pp:16;
    };
}mhl_mhl_md_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  det_cnt_24bit:16;
        RBus_UInt32  det_cnt_pp:16;
    };
}mhl_mhl_md_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mhl_en:1;
        RBus_UInt32  mhl_pp_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  dvi_ch_sync:1;
        RBus_UInt32  demux_sel:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  ch_bound_chg_det:1;
        RBus_UInt32  ch_bound_chg_int_en:1;
        RBus_UInt32  ch_bound_chg_wd_en:1;
        RBus_UInt32  audio_wd_en:1;
        RBus_UInt32  video_wd_en:1;
        RBus_UInt32  res3:19;
    };
}mhl_mhl_demux_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mhl_neg_de_err_flag:1;
        RBus_UInt32  mhl_pos_de_err_flag:1;
        RBus_UInt32  mhl_tran_err_flag:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  ctrl_glitch_occr_flag:1;
        RBus_UInt32  non_ctrl_glitch_occ_flag:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  mhl_mode_err:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  ch_bound_chg:1;
        RBus_UInt32  res4:19;
    };
}mhl_mhl_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mhl_ch0_cr_afifo_en:1;
        RBus_UInt32  mhl_ch0_cr_flush:1;
        RBus_UInt32  dummy1800d61c_15:14;
        RBus_UInt32  mhl_ch1_cr_afifo_en:1;
        RBus_UInt32  mhl_ch1_cr_flush:1;
        RBus_UInt32  res1:14;
    };
}mhl_mhl_ch_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mhl_ch0_sr_rflush_flag:1;
        RBus_UInt32  mhl_ch0_sr_rudflow_flag:1;
        RBus_UInt32  mhl_ch0_sr_wovflow_flag:1;
        RBus_UInt32  mhl_ch0_sr_rwclk_det_timeout_flag:1;
        RBus_UInt32  mhl_ch0_sr_wrclk_det_timeout_flag:1;
        RBus_UInt32  dummy1800d620_15:11;
        RBus_UInt32  mhl_ch1_sr_rflush_flag:1;
        RBus_UInt32  mhl_ch1_sr_rudflow_flag:1;
        RBus_UInt32  mhl_ch1_sr_wovflow_flag:1;
        RBus_UInt32  mhl_ch1_sr_rwclk_det_timeout_flag:1;
        RBus_UInt32  mhl_ch1_sr_wrclk_det_timeout_flag:1;
        RBus_UInt32  res1:11;
    };
}mhl_mhl_ch_sr_RBUS;




#endif 


#define  CBUS_STANDBY_00                                                        0x18062B00
#define  CBUS_STANDBY_00_reg_addr                                               "0xB8062B00"
#define  CBUS_STANDBY_00_reg                                                    0xB8062B00
#define  CBUS_STANDBY_00_inst_addr                                              "0x0000"
#define  CBUS_STANDBY_00_inst                                                   0x0000
#define CBUS_STANDBY_00_wake_pulse_det_shift                          (3)
#define CBUS_STANDBY_00_dis_pulse_det_shift                           (2)
#define CBUS_STANDBY_00_wake_irq_en_shift                             (1)
#define CBUS_STANDBY_00_dis_irq_en_shift                              (0)
#define CBUS_STANDBY_00_wake_pulse_det_mask                           (0x00000008)
#define CBUS_STANDBY_00_dis_pulse_det_mask                            (0x00000004)
#define CBUS_STANDBY_00_wake_irq_en_mask                              (0x00000002)
#define CBUS_STANDBY_00_dis_irq_en_mask                               (0x00000001)
#define CBUS_STANDBY_00_wake_pulse_det(data)                          (0x00000008&((data)<<3))
#define CBUS_STANDBY_00_dis_pulse_det(data)                           (0x00000004&((data)<<2))
#define CBUS_STANDBY_00_wake_irq_en(data)                             (0x00000002&((data)<<1))
#define CBUS_STANDBY_00_dis_irq_en(data)                              (0x00000001&(data))
#define CBUS_STANDBY_00_get_wake_pulse_det(data)                      ((0x00000008&(data))>>3)
#define CBUS_STANDBY_00_get_dis_pulse_det(data)                       ((0x00000004&(data))>>2)
#define CBUS_STANDBY_00_get_wake_irq_en(data)                         ((0x00000002&(data))>>1)
#define CBUS_STANDBY_00_get_dis_irq_en(data)                          (0x00000001&(data))

#define  CBUS_STANDBY_01                                                        0x18062B04
#define  CBUS_STANDBY_01_reg_addr                                               "0xB8062B04"
#define  CBUS_STANDBY_01_reg                                                    0xB8062B04
#define  CBUS_STANDBY_01_inst_addr                                              "0x0001"
#define  CBUS_STANDBY_01_inst                                                   0x0001
#define CBUS_STANDBY_01_clk_1m_div_shift                              (10)
#define CBUS_STANDBY_01_clk_1k_div_shift                              (0)
#define CBUS_STANDBY_01_clk_1m_div_mask                               (0x00003C00)
#define CBUS_STANDBY_01_clk_1k_div_mask                               (0x000003FF)
#define CBUS_STANDBY_01_clk_1m_div(data)                              (0x00003C00&((data)<<10))
#define CBUS_STANDBY_01_clk_1k_div(data)                              (0x000003FF&(data))
#define CBUS_STANDBY_01_get_clk_1m_div(data)                          ((0x00003C00&(data))>>10)
#define CBUS_STANDBY_01_get_clk_1k_div(data)                          (0x000003FF&(data))

#define  CBUS_STANDBY_02                                                        0x18062B08
#define  CBUS_STANDBY_02_reg_addr                                               "0xB8062B08"
#define  CBUS_STANDBY_02_reg                                                    0xB8062B08
#define  CBUS_STANDBY_02_inst_addr                                              "0x0002"
#define  CBUS_STANDBY_02_inst                                                   0x0002
#define CBUS_STANDBY_02_dis_deb_lv_shift                              (5)
#define CBUS_STANDBY_02_deb_lv_shift                                  (2)
#define CBUS_STANDBY_02_disconn_shift                                 (0)
#define CBUS_STANDBY_02_dis_deb_lv_mask                               (0x000000E0)
#define CBUS_STANDBY_02_deb_lv_mask                                   (0x0000001C)
#define CBUS_STANDBY_02_disconn_mask                                  (0x00000003)
#define CBUS_STANDBY_02_dis_deb_lv(data)                              (0x000000E0&((data)<<5))
#define CBUS_STANDBY_02_deb_lv(data)                                  (0x0000001C&((data)<<2))
#define CBUS_STANDBY_02_disconn(data)                                 (0x00000003&(data))
#define CBUS_STANDBY_02_get_dis_deb_lv(data)                          ((0x000000E0&(data))>>5)
#define CBUS_STANDBY_02_get_deb_lv(data)                              ((0x0000001C&(data))>>2)
#define CBUS_STANDBY_02_get_disconn(data)                             (0x00000003&(data))

#define  CBUS_STANDBY_04                                                        0x18062B10
#define  CBUS_STANDBY_04_reg_addr                                               "0xB8062B10"
#define  CBUS_STANDBY_04_reg                                                    0xB8062B10
#define  CBUS_STANDBY_04_inst_addr                                              "0x0003"
#define  CBUS_STANDBY_04_inst                                                   0x0003
#define  CBUS_STANDBY_04_wake_offset_low2_shift                                 (15)
#define  CBUS_STANDBY_04_wake_offset_low_shift                                  (10)
#define  CBUS_STANDBY_04_wake_cnt_shift                                         (7)
#define CBUS_STANDBY_04_wake_offset_shift                             (2)
#define CBUS_STANDBY_04_cbus_disconn_shift                            (1)
#define CBUS_STANDBY_04_disconn_irq_en_shift                          (0)
#define  CBUS_STANDBY_04_wake_offset_low2_mask                                  (0x000F8000)
#define  CBUS_STANDBY_04_wake_offset_low_mask                                   (0x00007C00)
#define  CBUS_STANDBY_04_wake_cnt_mask                                          (0x00000380)
#define  CBUS_STANDBY_04_wake_offset_mask                                       (0x0000007C)
#define CBUS_STANDBY_04_cbus_disconn_mask                             (0x00000002)
#define CBUS_STANDBY_04_disconn_irq_en_mask                           (0x00000001)
#define  CBUS_STANDBY_04_wake_offset_low2(data)                                 (0x000F8000&((data)<<15))
#define  CBUS_STANDBY_04_wake_offset_low(data)                                  (0x00007C00&((data)<<10))
#define  CBUS_STANDBY_04_wake_cnt(data)                                         (0x00000380&((data)<<7))
#define  CBUS_STANDBY_04_wake_offset(data)                                      (0x0000007C&((data)<<2))
#define CBUS_STANDBY_04_cbus_disconn(data)                            (0x00000002&((data)<<1))
#define CBUS_STANDBY_04_disconn_irq_en(data)                          (0x00000001&(data))
#define  CBUS_STANDBY_04_get_wake_offset_low2(data)                             ((0x000F8000&(data))>>15)
#define  CBUS_STANDBY_04_get_wake_offset_low(data)                              ((0x00007C00&(data))>>10)
#define  CBUS_STANDBY_04_get_wake_cnt(data)                                     ((0x00000380&(data))>>7)
#define  CBUS_STANDBY_04_get_wake_offset(data)                                  ((0x0000007C&(data))>>2)
#define CBUS_STANDBY_04_get_cbus_disconn(data)                        ((0x00000002&(data))>>1)
#define CBUS_STANDBY_04_get_disconn_irq_en(data)                      (0x00000001&(data))

#define  CBUS_STANDBY_05                                                        0x18062B14
#define  CBUS_STANDBY_05_reg_addr                                               "0xB8062B14"
#define  CBUS_STANDBY_05_reg                                                    0xB8062B14
#define  CBUS_STANDBY_05_inst_addr                                              "0x0004"
#define  CBUS_STANDBY_05_inst                                                   0x0004
#define CBUS_STANDBY_05_dis_upper_shift                               (4)
#define CBUS_STANDBY_05_dis_lower_shift                               (1)
#define CBUS_STANDBY_05_wake_eco_en_shift                             (0)
#define CBUS_STANDBY_05_dis_upper_mask                                (0x000000F0)
#define CBUS_STANDBY_05_dis_lower_mask                                (0x0000000E)
#define CBUS_STANDBY_05_wake_eco_en_mask                              (0x00000001)
#define CBUS_STANDBY_05_dis_upper(data)                               (0x000000F0&((data)<<4))
#define CBUS_STANDBY_05_dis_lower(data)                               (0x0000000E&((data)<<1))
#define CBUS_STANDBY_05_wake_eco_en(data)                             (0x00000001&(data))
#define CBUS_STANDBY_05_get_dis_upper(data)                           ((0x000000F0&(data))>>4)
#define CBUS_STANDBY_05_get_dis_lower(data)                           ((0x0000000E&(data))>>1)
#define CBUS_STANDBY_05_get_wake_eco_en(data)                         (0x00000001&(data))

#define  CBUS_STANDBY_06                                                        0x18062B18
#define  CBUS_STANDBY_06_reg_addr                                               "0xB8062B18"
#define  CBUS_STANDBY_06_reg                                                    0xB8062B18
#define  CBUS_STANDBY_06_inst_addr                                              "0x0005"
#define  CBUS_STANDBY_06_inst                                                   0x0005
#define CBUS_STANDBY_06_wake_num_shift                                (5)
#define CBUS_STANDBY_06_dis_num_shift                                 (0)
#define CBUS_STANDBY_06_wake_num_mask                                 (0x000000E0)
#define CBUS_STANDBY_06_dis_num_mask                                  (0x0000001F)
#define CBUS_STANDBY_06_wake_num(data)                                (0x000000E0&((data)<<5))
#define CBUS_STANDBY_06_dis_num(data)                                 (0x0000001F&(data))
#define CBUS_STANDBY_06_get_wake_num(data)                            ((0x000000E0&(data))>>5)
#define CBUS_STANDBY_06_get_dis_num(data)                             (0x0000001F&(data))

#define  CBUS_STANDBY_07                                                        0x18062B1C
#define  CBUS_STANDBY_07_reg_addr                                               "0xB8062B1C"
#define  CBUS_STANDBY_07_reg                                                    0xB8062B1C
#define  CBUS_STANDBY_07_inst_addr                                              "0x0006"
#define  CBUS_STANDBY_07_inst                                                   0x0006
#define CBUS_STANDBY_07_cbus_imp_auto_shift                           (7)
#define CBUS_STANDBY_07_bypass_mode_shift                             (6)
#define CBUS_STANDBY_07_sink_fsm_st_shift                             (3)
#define CBUS_STANDBY_07_cbus_100k_en_shift                            (2)
#define CBUS_STANDBY_07_cbus_1k_en_shift                              (1)
#define CBUS_STANDBY_07_cbus_in_sig_shift                             (0)
#define CBUS_STANDBY_07_cbus_imp_auto_mask                            (0x00000080)
#define CBUS_STANDBY_07_bypass_mode_mask                              (0x00000040)
#define CBUS_STANDBY_07_sink_fsm_st_mask                              (0x00000038)
#define CBUS_STANDBY_07_cbus_100k_en_mask                             (0x00000004)
#define CBUS_STANDBY_07_cbus_1k_en_mask                               (0x00000002)
#define CBUS_STANDBY_07_cbus_in_sig_mask                              (0x00000001)
#define CBUS_STANDBY_07_cbus_imp_auto(data)                           (0x00000080&((data)<<7))
#define CBUS_STANDBY_07_bypass_mode(data)                             (0x00000040&((data)<<6))
#define CBUS_STANDBY_07_sink_fsm_st(data)                             (0x00000038&((data)<<3))
#define CBUS_STANDBY_07_cbus_100k_en(data)                            (0x00000004&((data)<<2))
#define CBUS_STANDBY_07_cbus_1k_en(data)                              (0x00000002&((data)<<1))
#define CBUS_STANDBY_07_cbus_in_sig(data)                             (0x00000001&(data))
#define CBUS_STANDBY_07_get_cbus_imp_auto(data)                       ((0x00000080&(data))>>7)
#define CBUS_STANDBY_07_get_bypass_mode(data)                         ((0x00000040&(data))>>6)
#define CBUS_STANDBY_07_get_sink_fsm_st(data)                         ((0x00000038&(data))>>3)
#define CBUS_STANDBY_07_get_cbus_100k_en(data)                        ((0x00000004&(data))>>2)
#define CBUS_STANDBY_07_get_cbus_1k_en(data)                          ((0x00000002&(data))>>1)
#define CBUS_STANDBY_07_get_cbus_in_sig(data)                         (0x00000001&(data))

#define  CBUS_STANDBY_08                                                        0x18062B20
#define  CBUS_STANDBY_08_reg_addr                                               "0xB8062B20"
#define  CBUS_STANDBY_08_reg                                                    0xB8062B20
#define  CBUS_STANDBY_08_inst_addr                                              "0x0007"
#define  CBUS_STANDBY_08_inst                                                   0x0007
#define CBUS_STANDBY_08_goto_sink1_pos_shift                          (5)
#define CBUS_STANDBY_08_goto_float_shift                              (4)
#define CBUS_STANDBY_08_goto_sink1_shift                              (3)
#define CBUS_STANDBY_08_cable_det_shift                               (2)
#define CBUS_STANDBY_08_dbg_sel_phy_shift                             (0)
#define CBUS_STANDBY_08_goto_sink1_pos_mask                           (0x00000020)
#define CBUS_STANDBY_08_goto_float_mask                               (0x00000010)
#define CBUS_STANDBY_08_goto_sink1_mask                               (0x00000008)
#define CBUS_STANDBY_08_cable_det_mask                                (0x00000004)
#define CBUS_STANDBY_08_dbg_sel_phy_mask                              (0x00000001)
#define CBUS_STANDBY_08_goto_sink1_pos(data)                          (0x00000020&((data)<<5))
#define CBUS_STANDBY_08_goto_float(data)                              (0x00000010&((data)<<4))
#define CBUS_STANDBY_08_goto_sink1(data)                              (0x00000008&((data)<<3))
#define CBUS_STANDBY_08_cable_det(data)                               (0x00000004&((data)<<2))
#define CBUS_STANDBY_08_dbg_sel_phy(data)                             (0x00000001&(data))
#define CBUS_STANDBY_08_get_goto_sink1_pos(data)                      ((0x00000020&(data))>>5)
#define CBUS_STANDBY_08_get_goto_float(data)                          ((0x00000010&(data))>>4)
#define CBUS_STANDBY_08_get_goto_sink1(data)                          ((0x00000008&(data))>>3)
#define CBUS_STANDBY_08_get_cable_det(data)                           ((0x00000004&(data))>>2)
#define CBUS_STANDBY_08_get_dbg_sel_phy(data)                         (0x00000001&(data))

#define  CBUS_STANDBY_09                                                        0x18062B24
#define  CBUS_STANDBY_09_reg_addr                                               "0xB8062B24"
#define  CBUS_STANDBY_09_reg                                                    0xB8062B24
#define  CBUS_STANDBY_09_inst_addr                                              "0x0008"
#define  CBUS_STANDBY_09_inst                                                   0x0008
#define CBUS_STANDBY_09_ctrl_09_resv_shift                            (0)
#define CBUS_STANDBY_09_ctrl_09_resv_mask                             (0xFFFFFFFF)
#define CBUS_STANDBY_09_ctrl_09_resv(data)                            (0xFFFFFFFF&(data))
#define CBUS_STANDBY_09_get_ctrl_09_resv(data)                        (0xFFFFFFFF&(data))

#define  CBUS_PHY_0                                                             0x18062B30
#define  CBUS_PHY_0_reg_addr                                                    "0xB8062B30"
#define  CBUS_PHY_0_reg                                                         0xB8062B30
#define  CBUS_PHY_0_inst_addr                                                   "0x0009"
#define  CBUS_PHY_0_inst                                                        0x0009
#define CBUS_PHY_0_cbus_sr_shift                                      (6)
#define CBUS_PHY_0_cbus_smt_shift                                     (5)
#define CBUS_PHY_0_cbus_pu_shift                                      (4)
#define CBUS_PHY_0_cbus_pd_shift                                      (3)
#define CBUS_PHY_0_cbus_i_shift                                       (2)
#define CBUS_PHY_0_cbus_e2_shift                                      (1)
#define CBUS_PHY_0_cbus_e_shift                                       (0)
#define CBUS_PHY_0_cbus_sr_mask                                       (0x00000040)
#define CBUS_PHY_0_cbus_smt_mask                                      (0x00000020)
#define CBUS_PHY_0_cbus_pu_mask                                       (0x00000010)
#define CBUS_PHY_0_cbus_pd_mask                                       (0x00000008)
#define CBUS_PHY_0_cbus_i_mask                                        (0x00000004)
#define CBUS_PHY_0_cbus_e2_mask                                       (0x00000002)
#define CBUS_PHY_0_cbus_e_mask                                        (0x00000001)
#define CBUS_PHY_0_cbus_sr(data)                                      (0x00000040&((data)<<6))
#define CBUS_PHY_0_cbus_smt(data)                                     (0x00000020&((data)<<5))
#define CBUS_PHY_0_cbus_pu(data)                                      (0x00000010&((data)<<4))
#define CBUS_PHY_0_cbus_pd(data)                                      (0x00000008&((data)<<3))
#define CBUS_PHY_0_cbus_i(data)                                       (0x00000004&((data)<<2))
#define CBUS_PHY_0_cbus_e2(data)                                      (0x00000002&((data)<<1))
#define CBUS_PHY_0_cbus_e(data)                                       (0x00000001&(data))
#define CBUS_PHY_0_get_cbus_sr(data)                                  ((0x00000040&(data))>>6)
#define CBUS_PHY_0_get_cbus_smt(data)                                 ((0x00000020&(data))>>5)
#define CBUS_PHY_0_get_cbus_pu(data)                                  ((0x00000010&(data))>>4)
#define CBUS_PHY_0_get_cbus_pd(data)                                  ((0x00000008&(data))>>3)
#define CBUS_PHY_0_get_cbus_i(data)                                   ((0x00000004&(data))>>2)
#define CBUS_PHY_0_get_cbus_e2(data)                                  ((0x00000002&(data))>>1)
#define CBUS_PHY_0_get_cbus_e(data)                                   (0x00000001&(data))

#define  CBUS_PHY_1                                                             0x18062B34
#define  CBUS_PHY_1_reg_addr                                                    "0xB8062B34"
#define  CBUS_PHY_1_reg                                                         0xB8062B34
#define  CBUS_PHY_1_inst_addr                                                   "0x000A"
#define  CBUS_PHY_1_inst                                                        0x000A
#define CBUS_PHY_1_adjr_1k_shift                                      (28)
#define CBUS_PHY_1_adjr_100k_shift                                    (23)
#define CBUS_PHY_1_auto_k_1k_shift                                    (22)
#define CBUS_PHY_1_auto_k_100k_shift                                  (21)
#define CBUS_PHY_1_en_res_cal_cbus_shift                              (20)
#define CBUS_PHY_1_sel_cbus0_input_high_shift                         (18)
#define CBUS_PHY_1_sel_cbus0_input_low_shift                          (16)
#define CBUS_PHY_1_sel_cbus_0_driving_shift                           (13)
#define CBUS_PHY_1_sel_vref_ldo_shift                                 (11)
#define CBUS_PHY_1_trim_ldo_cbus_shift                                (7)
#define CBUS_PHY_1_triming_mode_shift                                 (6)
#define CBUS_PHY_1_en_cbus_shift                                      (5)
#define CBUS_PHY_1_en_cmp_cbus_shift                                  (4)
#define CBUS_PHY_1_en_driver_cbus_shift                               (3)
#define CBUS_PHY_1_en_ldo_cbus_shift                                  (2)
#define CBUS_PHY_1_psm_cbus_shift                                     (1)
#define CBUS_PHY_1_sel_cbusb_gpio_shift                               (0)
#define CBUS_PHY_1_adjr_1k_mask                                       (0xF0000000)
#define CBUS_PHY_1_adjr_100k_mask                                     (0x0F800000)
#define CBUS_PHY_1_auto_k_1k_mask                                     (0x00400000)
#define CBUS_PHY_1_auto_k_100k_mask                                   (0x00200000)
#define CBUS_PHY_1_en_res_cal_cbus_mask                               (0x00100000)
#define CBUS_PHY_1_sel_cbus0_input_high_mask                          (0x000C0000)
#define CBUS_PHY_1_sel_cbus0_input_low_mask                           (0x00030000)
#define CBUS_PHY_1_sel_cbus_0_driving_mask                            (0x0000E000)
#define CBUS_PHY_1_sel_vref_ldo_mask                                  (0x00001800)
#define CBUS_PHY_1_trim_ldo_cbus_mask                                 (0x00000780)
#define CBUS_PHY_1_triming_mode_mask                                  (0x00000040)
#define CBUS_PHY_1_en_cbus_mask                                       (0x00000020)
#define CBUS_PHY_1_en_cmp_cbus_mask                                   (0x00000010)
#define CBUS_PHY_1_en_driver_cbus_mask                                (0x00000008)
#define CBUS_PHY_1_en_ldo_cbus_mask                                   (0x00000004)
#define CBUS_PHY_1_psm_cbus_mask                                      (0x00000002)
#define CBUS_PHY_1_sel_cbusb_gpio_mask                                (0x00000001)
#define CBUS_PHY_1_adjr_1k(data)                                      (0xF0000000&((data)<<28))
#define CBUS_PHY_1_adjr_100k(data)                                    (0x0F800000&((data)<<23))
#define CBUS_PHY_1_auto_k_1k(data)                                    (0x00400000&((data)<<22))
#define CBUS_PHY_1_auto_k_100k(data)                                  (0x00200000&((data)<<21))
#define CBUS_PHY_1_en_res_cal_cbus(data)                              (0x00100000&((data)<<20))
#define CBUS_PHY_1_sel_cbus0_input_high(data)                         (0x000C0000&((data)<<18))
#define CBUS_PHY_1_sel_cbus0_input_low(data)                          (0x00030000&((data)<<16))
#define CBUS_PHY_1_sel_cbus_0_driving(data)                           (0x0000E000&((data)<<13))
#define CBUS_PHY_1_sel_vref_ldo(data)                                 (0x00001800&((data)<<11))
#define CBUS_PHY_1_trim_ldo_cbus(data)                                (0x00000780&((data)<<7))
#define CBUS_PHY_1_triming_mode(data)                                 (0x00000040&((data)<<6))
#define CBUS_PHY_1_en_cbus(data)                                      (0x00000020&((data)<<5))
#define CBUS_PHY_1_en_cmp_cbus(data)                                  (0x00000010&((data)<<4))
#define CBUS_PHY_1_en_driver_cbus(data)                               (0x00000008&((data)<<3))
#define CBUS_PHY_1_en_ldo_cbus(data)                                  (0x00000004&((data)<<2))
#define CBUS_PHY_1_psm_cbus(data)                                     (0x00000002&((data)<<1))
#define CBUS_PHY_1_sel_cbusb_gpio(data)                               (0x00000001&(data))
#define CBUS_PHY_1_get_adjr_1k(data)                                  ((0xF0000000&(data))>>28)
#define CBUS_PHY_1_get_adjr_100k(data)                                ((0x0F800000&(data))>>23)
#define CBUS_PHY_1_get_auto_k_1k(data)                                ((0x00400000&(data))>>22)
#define CBUS_PHY_1_get_auto_k_100k(data)                              ((0x00200000&(data))>>21)
#define CBUS_PHY_1_get_en_res_cal_cbus(data)                          ((0x00100000&(data))>>20)
#define CBUS_PHY_1_get_sel_cbus0_input_high(data)                     ((0x000C0000&(data))>>18)
#define CBUS_PHY_1_get_sel_cbus0_input_low(data)                      ((0x00030000&(data))>>16)
#define CBUS_PHY_1_get_sel_cbus_0_driving(data)                       ((0x0000E000&(data))>>13)
#define CBUS_PHY_1_get_sel_vref_ldo(data)                             ((0x00001800&(data))>>11)
#define CBUS_PHY_1_get_trim_ldo_cbus(data)                            ((0x00000780&(data))>>7)
#define CBUS_PHY_1_get_triming_mode(data)                             ((0x00000040&(data))>>6)
#define CBUS_PHY_1_get_en_cbus(data)                                  ((0x00000020&(data))>>5)
#define CBUS_PHY_1_get_en_cmp_cbus(data)                              ((0x00000010&(data))>>4)
#define CBUS_PHY_1_get_en_driver_cbus(data)                           ((0x00000008&(data))>>3)
#define CBUS_PHY_1_get_en_ldo_cbus(data)                              ((0x00000004&(data))>>2)
#define CBUS_PHY_1_get_psm_cbus(data)                                 ((0x00000002&(data))>>1)
#define CBUS_PHY_1_get_sel_cbusb_gpio(data)                           (0x00000001&(data))

#define  CBUS_PHY_2                                                             0x18062B38
#define  CBUS_PHY_2_reg_addr                                                    "0xB8062B38"
#define  CBUS_PHY_2_reg                                                         0xB8062B38
#define  CBUS_PHY_2_inst_addr                                                   "0x000B"
#define  CBUS_PHY_2_inst                                                        0x000B
#define CBUS_PHY_2_cbus_o_shift                                       (0)
#define CBUS_PHY_2_cbus_o_mask                                        (0x00000001)
#define CBUS_PHY_2_cbus_o(data)                                       (0x00000001&(data))
#define CBUS_PHY_2_get_cbus_o(data)                                   (0x00000001&(data))

#define  CBUS_PHY_3                                                             0x18062B3C
#define  CBUS_PHY_3_reg_addr                                                    "0xB8062B3C"
#define  CBUS_PHY_3_reg                                                         0xB8062B3C
#define  CBUS_PHY_3_inst_addr                                                   "0x000C"
#define  CBUS_PHY_3_inst                                                        0x000C
#define CBUS_PHY_3_sel_phy_soft_rst_n_shift                           (11)
#define CBUS_PHY_3_cbus_res_tst_shift                                 (1)
#define CBUS_PHY_3_res_ok_shift                                       (0)
#define CBUS_PHY_3_sel_phy_soft_rst_n_mask                            (0x00000800)
#define CBUS_PHY_3_cbus_res_tst_mask                                  (0x000007FE)
#define CBUS_PHY_3_res_ok_mask                                        (0x00000001)
#define CBUS_PHY_3_sel_phy_soft_rst_n(data)                           (0x00000800&((data)<<11))
#define CBUS_PHY_3_cbus_res_tst(data)                                 (0x000007FE&((data)<<1))
#define CBUS_PHY_3_res_ok(data)                                       (0x00000001&(data))
#define CBUS_PHY_3_get_sel_phy_soft_rst_n(data)                       ((0x00000800&(data))>>11)
#define CBUS_PHY_3_get_cbus_res_tst(data)                             ((0x000007FE&(data))>>1)
#define CBUS_PHY_3_get_res_ok(data)                                   (0x00000001&(data))


#define CBUS_PHY0_reg                                                0xb8062c1c
#define CBUS_PHY0_EN_BIAS	(_BIT6)
#define  MSC_REG_00                                                             0x1800A000
#define  MSC_REG_00_reg_addr                                                    "0xB800A000"
#define  MSC_REG_00_reg                                                         0xB800A000
#define  MSC_REG_00_inst_addr                                                   "0x000D"
#define  MSC_REG_00_inst                                                        0x000D
#define MSC_REG_00_dev_state_shift                                    (0)
#define MSC_REG_00_dev_state_mask                                     (0x000000FF)
#define MSC_REG_00_dev_state(data)                                    (0x000000FF&(data))
#define MSC_REG_00_get_dev_state(data)                                (0x000000FF&(data))

#define  MSC_REG_01                                                             0x1800A004
#define  MSC_REG_01_reg_addr                                                    "0xB800A004"
#define  MSC_REG_01_reg                                                         0xB800A004
#define  MSC_REG_01_inst_addr                                                   "0x000E"
#define  MSC_REG_01_inst                                                        0x000E
#define MSC_REG_01_mhl_ver_shift                                      (0)
#define MSC_REG_01_mhl_ver_mask                                       (0x000000FF)
#define MSC_REG_01_mhl_ver(data)                                      (0x000000FF&(data))
#define MSC_REG_01_get_mhl_ver(data)                                  (0x000000FF&(data))

#define  MSC_REG_02                                                             0x1800A008
#define  MSC_REG_02_reg_addr                                                    "0xB800A008"
#define  MSC_REG_02_reg                                                         0xB800A008
#define  MSC_REG_02_inst_addr                                                   "0x000F"
#define  MSC_REG_02_inst                                                        0x000F
#define MSC_REG_02_dev_cat_shift                                      (7)
#define MSC_REG_02_plim_shift                                         (5)
#define MSC_REG_02_pow_shift                                          (4)
#define MSC_REG_02_dev_type_shift                                     (0)
#define MSC_REG_02_dev_cat_mask                                       (0x00000080)
#define MSC_REG_02_plim_mask                                          (0x00000060)
#define MSC_REG_02_pow_mask                                           (0x00000010)
#define MSC_REG_02_dev_type_mask                                      (0x0000000F)
#define MSC_REG_02_dev_cat(data)                                      (0x00000080&((data)<<7))
#define MSC_REG_02_plim(data)                                         (0x00000060&((data)<<5))
#define MSC_REG_02_pow(data)                                          (0x00000010&((data)<<4))
#define MSC_REG_02_dev_type(data)                                     (0x0000000F&(data))
#define MSC_REG_02_get_dev_cat(data)                                  ((0x00000080&(data))>>7)
#define MSC_REG_02_get_plim(data)                                     ((0x00000060&(data))>>5)
#define MSC_REG_02_get_pow(data)                                      ((0x00000010&(data))>>4)
#define MSC_REG_02_get_dev_type(data)                                 (0x0000000F&(data))

#define  MSC_REG_03                                                             0x1800A00C
#define  MSC_REG_03_reg_addr                                                    "0xB800A00C"
#define  MSC_REG_03_reg                                                         0xB800A00C
#define  MSC_REG_03_inst_addr                                                   "0x0010"
#define  MSC_REG_03_inst                                                        0x0010
#define MSC_REG_03_adop_id_h_shift                                    (0)
#define MSC_REG_03_adop_id_h_mask                                     (0x000000FF)
#define MSC_REG_03_adop_id_h(data)                                    (0x000000FF&(data))
#define MSC_REG_03_get_adop_id_h(data)                                (0x000000FF&(data))

#define  MSC_REG_04                                                             0x1800A010
#define  MSC_REG_04_reg_addr                                                    "0xB800A010"
#define  MSC_REG_04_reg                                                         0xB800A010
#define  MSC_REG_04_inst_addr                                                   "0x0011"
#define  MSC_REG_04_inst                                                        0x0011
#define MSC_REG_04_adop_id_l_shift                                    (0)
#define MSC_REG_04_adop_id_l_mask                                     (0x000000FF)
#define MSC_REG_04_adop_id_l(data)                                    (0x000000FF&(data))
#define MSC_REG_04_get_adop_id_l(data)                                (0x000000FF&(data))

#define  MSC_REG_05                                                             0x1800A014
#define  MSC_REG_05_reg_addr                                                    "0xB800A014"
#define  MSC_REG_05_reg                                                         0xB800A014
#define  MSC_REG_05_inst_addr                                                   "0x0012"
#define  MSC_REG_05_inst                                                        0x0012
#define MSC_REG_05_vid_link_md_shift                                  (6)
#define MSC_REG_05_supp_vga_shift                                     (5)
#define MSC_REG_05_supp_islands_shift                                 (4)
#define MSC_REG_05_supp_ppixel_shift                                  (3)
#define MSC_REG_05_supp_yuv422_shift                                  (2)
#define MSC_REG_05_supp_yuv444_shift                                  (1)
#define MSC_REG_05_supp_rgb444_shift                                  (0)
#define MSC_REG_05_vid_link_md_mask                                   (0x000000C0)
#define MSC_REG_05_supp_vga_mask                                      (0x00000020)
#define MSC_REG_05_supp_islands_mask                                  (0x00000010)
#define MSC_REG_05_supp_ppixel_mask                                   (0x00000008)
#define MSC_REG_05_supp_yuv422_mask                                   (0x00000004)
#define MSC_REG_05_supp_yuv444_mask                                   (0x00000002)
#define MSC_REG_05_supp_rgb444_mask                                   (0x00000001)
#define MSC_REG_05_vid_link_md(data)                                  (0x000000C0&((data)<<6))
#define MSC_REG_05_supp_vga(data)                                     (0x00000020&((data)<<5))
#define MSC_REG_05_supp_islands(data)                                 (0x00000010&((data)<<4))
#define MSC_REG_05_supp_ppixel(data)                                  (0x00000008&((data)<<3))
#define MSC_REG_05_supp_yuv422(data)                                  (0x00000004&((data)<<2))
#define MSC_REG_05_supp_yuv444(data)                                  (0x00000002&((data)<<1))
#define MSC_REG_05_supp_rgb444(data)                                  (0x00000001&(data))
#define MSC_REG_05_get_vid_link_md(data)                              ((0x000000C0&(data))>>6)
#define MSC_REG_05_get_supp_vga(data)                                 ((0x00000020&(data))>>5)
#define MSC_REG_05_get_supp_islands(data)                             ((0x00000010&(data))>>4)
#define MSC_REG_05_get_supp_ppixel(data)                              ((0x00000008&(data))>>3)
#define MSC_REG_05_get_supp_yuv422(data)                              ((0x00000004&(data))>>2)
#define MSC_REG_05_get_supp_yuv444(data)                              ((0x00000002&(data))>>1)
#define MSC_REG_05_get_supp_rgb444(data)                              (0x00000001&(data))

#define  MSC_REG_06                                                             0x1800A018
#define  MSC_REG_06_reg_addr                                                    "0xB800A018"
#define  MSC_REG_06_reg                                                         0xB800A018
#define  MSC_REG_06_inst_addr                                                   "0x0013"
#define  MSC_REG_06_inst                                                        0x0013
#define MSC_REG_06_aud_link_md_shift                                  (2)
#define MSC_REG_06_aud_8ch_shift                                      (1)
#define MSC_REG_06_aud_2ch_shift                                      (0)
#define MSC_REG_06_aud_link_md_mask                                   (0x000000FC)
#define MSC_REG_06_aud_8ch_mask                                       (0x00000002)
#define MSC_REG_06_aud_2ch_mask                                       (0x00000001)
#define MSC_REG_06_aud_link_md(data)                                  (0x000000FC&((data)<<2))
#define MSC_REG_06_aud_8ch(data)                                      (0x00000002&((data)<<1))
#define MSC_REG_06_aud_2ch(data)                                      (0x00000001&(data))
#define MSC_REG_06_get_aud_link_md(data)                              ((0x000000FC&(data))>>2)
#define MSC_REG_06_get_aud_8ch(data)                                  ((0x00000002&(data))>>1)
#define MSC_REG_06_get_aud_2ch(data)                                  (0x00000001&(data))

#define  MSC_REG_07                                                             0x1800A01C
#define  MSC_REG_07_reg_addr                                                    "0xB800A01C"
#define  MSC_REG_07_reg                                                         0xB800A01C
#define  MSC_REG_07_inst_addr                                                   "0x0014"
#define  MSC_REG_07_inst                                                        0x0014
#define MSC_REG_07_supp_vt_shift                                      (7)
#define MSC_REG_07_video_type_shift                                   (4)
#define MSC_REG_07_vt_game_shift                                      (3)
#define MSC_REG_07_vt_cinema_shift                                    (2)
#define MSC_REG_07_vt_photo_shift                                     (1)
#define MSC_REG_07_vt_graphics_shift                                  (0)
#define MSC_REG_07_supp_vt_mask                                       (0x00000080)
#define MSC_REG_07_video_type_mask                                    (0x00000070)
#define MSC_REG_07_vt_game_mask                                       (0x00000008)
#define MSC_REG_07_vt_cinema_mask                                     (0x00000004)
#define MSC_REG_07_vt_photo_mask                                      (0x00000002)
#define MSC_REG_07_vt_graphics_mask                                   (0x00000001)
#define MSC_REG_07_supp_vt(data)                                      (0x00000080&((data)<<7))
#define MSC_REG_07_video_type(data)                                   (0x00000070&((data)<<4))
#define MSC_REG_07_vt_game(data)                                      (0x00000008&((data)<<3))
#define MSC_REG_07_vt_cinema(data)                                    (0x00000004&((data)<<2))
#define MSC_REG_07_vt_photo(data)                                     (0x00000002&((data)<<1))
#define MSC_REG_07_vt_graphics(data)                                  (0x00000001&(data))
#define MSC_REG_07_get_supp_vt(data)                                  ((0x00000080&(data))>>7)
#define MSC_REG_07_get_video_type(data)                               ((0x00000070&(data))>>4)
#define MSC_REG_07_get_vt_game(data)                                  ((0x00000008&(data))>>3)
#define MSC_REG_07_get_vt_cinema(data)                                ((0x00000004&(data))>>2)
#define MSC_REG_07_get_vt_photo(data)                                 ((0x00000002&(data))>>1)
#define MSC_REG_07_get_vt_graphics(data)                              (0x00000001&(data))

#define  MSC_REG_08                                                             0x1800A020
#define  MSC_REG_08_reg_addr                                                    "0xB800A020"
#define  MSC_REG_08_reg                                                         0xB800A020
#define  MSC_REG_08_inst_addr                                                   "0x0015"
#define  MSC_REG_08_inst                                                        0x0015
#define MSC_REG_08_ld_gui_shift                                       (7)
#define MSC_REG_08_ld_speaker_shift                                   (6)
#define MSC_REG_08_ld_record_shift                                    (5)
#define MSC_REG_08_ld_tuner_shift                                     (4)
#define MSC_REG_08_ld_media_shift                                     (3)
#define MSC_REG_08_ld_audio_shift                                     (2)
#define MSC_REG_08_ld_video_shift                                     (1)
#define MSC_REG_08_ld_display_shift                                   (0)
#define MSC_REG_08_ld_gui_mask                                        (0x00000080)
#define MSC_REG_08_ld_speaker_mask                                    (0x00000040)
#define MSC_REG_08_ld_record_mask                                     (0x00000020)
#define MSC_REG_08_ld_tuner_mask                                      (0x00000010)
#define MSC_REG_08_ld_media_mask                                      (0x00000008)
#define MSC_REG_08_ld_audio_mask                                      (0x00000004)
#define MSC_REG_08_ld_video_mask                                      (0x00000002)
#define MSC_REG_08_ld_display_mask                                    (0x00000001)
#define MSC_REG_08_ld_gui(data)                                       (0x00000080&((data)<<7))
#define MSC_REG_08_ld_speaker(data)                                   (0x00000040&((data)<<6))
#define MSC_REG_08_ld_record(data)                                    (0x00000020&((data)<<5))
#define MSC_REG_08_ld_tuner(data)                                     (0x00000010&((data)<<4))
#define MSC_REG_08_ld_media(data)                                     (0x00000008&((data)<<3))
#define MSC_REG_08_ld_audio(data)                                     (0x00000004&((data)<<2))
#define MSC_REG_08_ld_video(data)                                     (0x00000002&((data)<<1))
#define MSC_REG_08_ld_display(data)                                   (0x00000001&(data))
#define MSC_REG_08_get_ld_gui(data)                                   ((0x00000080&(data))>>7)
#define MSC_REG_08_get_ld_speaker(data)                               ((0x00000040&(data))>>6)
#define MSC_REG_08_get_ld_record(data)                                ((0x00000020&(data))>>5)
#define MSC_REG_08_get_ld_tuner(data)                                 ((0x00000010&(data))>>4)
#define MSC_REG_08_get_ld_media(data)                                 ((0x00000008&(data))>>3)
#define MSC_REG_08_get_ld_audio(data)                                 ((0x00000004&(data))>>2)
#define MSC_REG_08_get_ld_video(data)                                 ((0x00000002&(data))>>1)
#define MSC_REG_08_get_ld_display(data)                               (0x00000001&(data))

#define  MSC_REG_09                                                             0x1800A024
#define  MSC_REG_09_reg_addr                                                    "0xB800A024"
#define  MSC_REG_09_reg                                                         0xB800A024
#define  MSC_REG_09_inst_addr                                                   "0x0016"
#define  MSC_REG_09_inst                                                        0x0016
#define MSC_REG_09_bandwid_shift                                      (0)
#define MSC_REG_09_bandwid_mask                                       (0x000000FF)
#define MSC_REG_09_bandwid(data)                                      (0x000000FF&(data))
#define MSC_REG_09_get_bandwid(data)                                  (0x000000FF&(data))

#define  MSC_REG_0A                                                             0x1800A028
#define  MSC_REG_0A_reg_addr                                                    "0xB800A028"
#define  MSC_REG_0A_reg                                                         0xB800A028
#define  MSC_REG_0A_inst_addr                                                   "0x0017"
#define  MSC_REG_0A_inst                                                        0x0017
#define MSC_REG_0A_feature_flag_shift                                 (5)
#define MSC_REG_0A_ucp_recv_supp_shift                                (4)
#define MSC_REG_0A_ucp_send_supp_shift                                (3)
#define MSC_REG_0A_sp_supp_shift                                      (2)
#define MSC_REG_0A_rap_supp_shift                                     (1)
#define MSC_REG_0A_rcp_supp_shift                                     (0)
#define MSC_REG_0A_feature_flag_mask                                  (0x000000E0)
#define MSC_REG_0A_ucp_recv_supp_mask                                 (0x00000010)
#define MSC_REG_0A_ucp_send_supp_mask                                 (0x00000008)
#define MSC_REG_0A_sp_supp_mask                                       (0x00000004)
#define MSC_REG_0A_rap_supp_mask                                      (0x00000002)
#define MSC_REG_0A_rcp_supp_mask                                      (0x00000001)
#define MSC_REG_0A_feature_flag(data)                                 (0x000000E0&((data)<<5))
#define MSC_REG_0A_ucp_recv_supp(data)                                (0x00000010&((data)<<4))
#define MSC_REG_0A_ucp_send_supp(data)                                (0x00000008&((data)<<3))
#define MSC_REG_0A_sp_supp(data)                                      (0x00000004&((data)<<2))
#define MSC_REG_0A_rap_supp(data)                                     (0x00000002&((data)<<1))
#define MSC_REG_0A_rcp_supp(data)                                     (0x00000001&(data))
#define MSC_REG_0A_get_feature_flag(data)                             ((0x000000E0&(data))>>5)
#define MSC_REG_0A_get_ucp_recv_supp(data)                            ((0x00000010&(data))>>4)
#define MSC_REG_0A_get_ucp_send_supp(data)                            ((0x00000008&(data))>>3)
#define MSC_REG_0A_get_sp_supp(data)                                  ((0x00000004&(data))>>2)
#define MSC_REG_0A_get_rap_supp(data)                                 ((0x00000002&(data))>>1)
#define MSC_REG_0A_get_rcp_supp(data)                                 (0x00000001&(data))

#define  MSC_REG_0B                                                             0x1800A02C
#define  MSC_REG_0B_reg_addr                                                    "0xB800A02C"
#define  MSC_REG_0B_reg                                                         0xB800A02C
#define  MSC_REG_0B_inst_addr                                                   "0x0018"
#define  MSC_REG_0B_inst                                                        0x0018
#define MSC_REG_0B_device_id_h_shift                                  (0)
#define MSC_REG_0B_device_id_h_mask                                   (0x000000FF)
#define MSC_REG_0B_device_id_h(data)                                  (0x000000FF&(data))
#define MSC_REG_0B_get_device_id_h(data)                              (0x000000FF&(data))

#define  MSC_REG_0C                                                             0x1800A030
#define  MSC_REG_0C_reg_addr                                                    "0xB800A030"
#define  MSC_REG_0C_reg                                                         0xB800A030
#define  MSC_REG_0C_inst_addr                                                   "0x0019"
#define  MSC_REG_0C_inst                                                        0x0019
#define MSC_REG_0C_device_id_l_shift                                  (0)
#define MSC_REG_0C_device_id_l_mask                                   (0x000000FF)
#define MSC_REG_0C_device_id_l(data)                                  (0x000000FF&(data))
#define MSC_REG_0C_get_device_id_l(data)                              (0x000000FF&(data))

#define  MSC_REG_0D                                                             0x1800A034
#define  MSC_REG_0D_reg_addr                                                    "0xB800A034"
#define  MSC_REG_0D_reg                                                         0xB800A034
#define  MSC_REG_0D_inst_addr                                                   "0x001A"
#define  MSC_REG_0D_inst                                                        0x001A
#define MSC_REG_0D_scr_size_shift                                     (0)
#define MSC_REG_0D_scr_size_mask                                      (0x000000FF)
#define MSC_REG_0D_scr_size(data)                                     (0x000000FF&(data))
#define MSC_REG_0D_get_scr_size(data)                                 (0x000000FF&(data))

#define  MSC_REG_0E                                                             0x1800A038
#define  MSC_REG_0E_reg_addr                                                    "0xB800A038"
#define  MSC_REG_0E_reg                                                         0xB800A038
#define  MSC_REG_0E_inst_addr                                                   "0x001B"
#define  MSC_REG_0E_inst                                                        0x001B
#define MSC_REG_0E_stat_size_shift                                    (4)
#define MSC_REG_0E_int_size_shift                                     (0)
#define MSC_REG_0E_stat_size_mask                                     (0x000000F0)
#define MSC_REG_0E_int_size_mask                                      (0x0000000F)
#define MSC_REG_0E_stat_size(data)                                    (0x000000F0&((data)<<4))
#define MSC_REG_0E_int_size(data)                                     (0x0000000F&(data))
#define MSC_REG_0E_get_stat_size(data)                                ((0x000000F0&(data))>>4)
#define MSC_REG_0E_get_int_size(data)                                 (0x0000000F&(data))

#define  MSC_REG_0F                                                             0x1800A03C
#define  MSC_REG_0F_reg_addr                                                    "0xB800A03C"
#define  MSC_REG_0F_reg                                                         0xB800A03C
#define  MSC_REG_0F_inst_addr                                                   "0x001C"
#define  MSC_REG_0F_inst                                                        0x001C
#define MSC_REG_0F_cap_0f_shift                                       (0)
#define MSC_REG_0F_cap_0f_mask                                        (0x000000FF)
#define MSC_REG_0F_cap_0f(data)                                       (0x000000FF&(data))
#define MSC_REG_0F_get_cap_0f(data)                                   (0x000000FF&(data))

#define  MSC_REG_20                                                             0x1800A080
#define  MSC_REG_20_reg_addr                                                    "0xB800A080"
#define  MSC_REG_20_reg                                                         0xB800A080
#define  MSC_REG_20_inst_addr                                                   "0x001D"
#define  MSC_REG_20_inst                                                        0x001D
#define MSC_REG_20_rchg_int_7_shift                                   (7)
#define MSC_REG_20_rchg_int_6_shift                                   (6)
#define MSC_REG_20_rchg_int_5_shift                                   (5)
#define MSC_REG_20_cbus_3d_req_shift                                  (4)
#define MSC_REG_20_grt_wrt_shift                                      (3)
#define MSC_REG_20_req_wrt_shift                                      (2)
#define MSC_REG_20_dscr_chg_shift                                     (1)
#define MSC_REG_20_dcap_chg_shift                                     (0)
#define MSC_REG_20_rchg_int_7_mask                                    (0x00000080)
#define MSC_REG_20_rchg_int_6_mask                                    (0x00000040)
#define MSC_REG_20_rchg_int_5_mask                                    (0x00000020)
#define MSC_REG_20_cbus_3d_req_mask                                   (0x00000010)
#define MSC_REG_20_grt_wrt_mask                                       (0x00000008)
#define MSC_REG_20_req_wrt_mask                                       (0x00000004)
#define MSC_REG_20_dscr_chg_mask                                      (0x00000002)
#define MSC_REG_20_dcap_chg_mask                                      (0x00000001)
#define MSC_REG_20_rchg_int_7(data)                                   (0x00000080&((data)<<7))
#define MSC_REG_20_rchg_int_6(data)                                   (0x00000040&((data)<<6))
#define MSC_REG_20_rchg_int_5(data)                                   (0x00000020&((data)<<5))
#define MSC_REG_20_cbus_3d_req(data)                                  (0x00000010&((data)<<4))
#define MSC_REG_20_grt_wrt(data)                                      (0x00000008&((data)<<3))
#define MSC_REG_20_req_wrt(data)                                      (0x00000004&((data)<<2))
#define MSC_REG_20_dscr_chg(data)                                     (0x00000002&((data)<<1))
#define MSC_REG_20_dcap_chg(data)                                     (0x00000001&(data))
#define MSC_REG_20_get_rchg_int_7(data)                               ((0x00000080&(data))>>7)
#define MSC_REG_20_get_rchg_int_6(data)                               ((0x00000040&(data))>>6)
#define MSC_REG_20_get_rchg_int_5(data)                               ((0x00000020&(data))>>5)
#define MSC_REG_20_get_cbus_3d_req(data)                              ((0x00000010&(data))>>4)
#define MSC_REG_20_get_grt_wrt(data)                                  ((0x00000008&(data))>>3)
#define MSC_REG_20_get_req_wrt(data)                                  ((0x00000004&(data))>>2)
#define MSC_REG_20_get_dscr_chg(data)                                 ((0x00000002&(data))>>1)
#define MSC_REG_20_get_dcap_chg(data)                                 (0x00000001&(data))

#define  MSC_REG_21                                                             0x1800A084
#define  MSC_REG_21_reg_addr                                                    "0xB800A084"
#define  MSC_REG_21_reg                                                         0xB800A084
#define  MSC_REG_21_inst_addr                                                   "0x001E"
#define  MSC_REG_21_inst                                                        0x001E
#define MSC_REG_21_dchg_int_7_shift                                   (7)
#define MSC_REG_21_dchg_int_6_shift                                   (6)
#define MSC_REG_21_dchg_int_5_shift                                   (5)
#define MSC_REG_21_dchg_int_4_shift                                   (4)
#define MSC_REG_21_dchg_int_3_shift                                   (3)
#define MSC_REG_21_dchg_int_2_shift                                   (2)
#define MSC_REG_21_edid_chg_shift                                     (1)
#define MSC_REG_21_dchg_int_0_shift                                   (0)
#define MSC_REG_21_dchg_int_7_mask                                    (0x00000080)
#define MSC_REG_21_dchg_int_6_mask                                    (0x00000040)
#define MSC_REG_21_dchg_int_5_mask                                    (0x00000020)
#define MSC_REG_21_dchg_int_4_mask                                    (0x00000010)
#define MSC_REG_21_dchg_int_3_mask                                    (0x00000008)
#define MSC_REG_21_dchg_int_2_mask                                    (0x00000004)
#define MSC_REG_21_edid_chg_mask                                      (0x00000002)
#define MSC_REG_21_dchg_int_0_mask                                    (0x00000001)
#define MSC_REG_21_dchg_int_7(data)                                   (0x00000080&((data)<<7))
#define MSC_REG_21_dchg_int_6(data)                                   (0x00000040&((data)<<6))
#define MSC_REG_21_dchg_int_5(data)                                   (0x00000020&((data)<<5))
#define MSC_REG_21_dchg_int_4(data)                                   (0x00000010&((data)<<4))
#define MSC_REG_21_dchg_int_3(data)                                   (0x00000008&((data)<<3))
#define MSC_REG_21_dchg_int_2(data)                                   (0x00000004&((data)<<2))
#define MSC_REG_21_edid_chg(data)                                     (0x00000002&((data)<<1))
#define MSC_REG_21_dchg_int_0(data)                                   (0x00000001&(data))
#define MSC_REG_21_get_dchg_int_7(data)                               ((0x00000080&(data))>>7)
#define MSC_REG_21_get_dchg_int_6(data)                               ((0x00000040&(data))>>6)
#define MSC_REG_21_get_dchg_int_5(data)                               ((0x00000020&(data))>>5)
#define MSC_REG_21_get_dchg_int_4(data)                               ((0x00000010&(data))>>4)
#define MSC_REG_21_get_dchg_int_3(data)                               ((0x00000008&(data))>>3)
#define MSC_REG_21_get_dchg_int_2(data)                               ((0x00000004&(data))>>2)
#define MSC_REG_21_get_edid_chg(data)                                 ((0x00000002&(data))>>1)
#define MSC_REG_21_get_dchg_int_0(data)                               (0x00000001&(data))

#define  MSC_REG_22                                                             0x1800A088
#define  MSC_REG_22_reg_addr                                                    "0xB800A088"
#define  MSC_REG_22_reg                                                         0xB800A088
#define  MSC_REG_22_inst_addr                                                   "0x001F"
#define  MSC_REG_22_inst                                                        0x001F
#define MSC_REG_22_chg22_7_shift                                      (7)
#define MSC_REG_22_chg22_6_shift                                      (6)
#define MSC_REG_22_chg22_5_shift                                      (5)
#define MSC_REG_22_chg22_4_shift                                      (4)
#define MSC_REG_22_chg22_3_shift                                      (3)
#define MSC_REG_22_chg22_2_shift                                      (2)
#define MSC_REG_22_chg22_1_shift                                      (1)
#define MSC_REG_22_chg22_0_shift                                      (0)
#define MSC_REG_22_chg22_7_mask                                       (0x00000080)
#define MSC_REG_22_chg22_6_mask                                       (0x00000040)
#define MSC_REG_22_chg22_5_mask                                       (0x00000020)
#define MSC_REG_22_chg22_4_mask                                       (0x00000010)
#define MSC_REG_22_chg22_3_mask                                       (0x00000008)
#define MSC_REG_22_chg22_2_mask                                       (0x00000004)
#define MSC_REG_22_chg22_1_mask                                       (0x00000002)
#define MSC_REG_22_chg22_0_mask                                       (0x00000001)
#define MSC_REG_22_chg22_7(data)                                      (0x00000080&((data)<<7))
#define MSC_REG_22_chg22_6(data)                                      (0x00000040&((data)<<6))
#define MSC_REG_22_chg22_5(data)                                      (0x00000020&((data)<<5))
#define MSC_REG_22_chg22_4(data)                                      (0x00000010&((data)<<4))
#define MSC_REG_22_chg22_3(data)                                      (0x00000008&((data)<<3))
#define MSC_REG_22_chg22_2(data)                                      (0x00000004&((data)<<2))
#define MSC_REG_22_chg22_1(data)                                      (0x00000002&((data)<<1))
#define MSC_REG_22_chg22_0(data)                                      (0x00000001&(data))
#define MSC_REG_22_get_chg22_7(data)                                  ((0x00000080&(data))>>7)
#define MSC_REG_22_get_chg22_6(data)                                  ((0x00000040&(data))>>6)
#define MSC_REG_22_get_chg22_5(data)                                  ((0x00000020&(data))>>5)
#define MSC_REG_22_get_chg22_4(data)                                  ((0x00000010&(data))>>4)
#define MSC_REG_22_get_chg22_3(data)                                  ((0x00000008&(data))>>3)
#define MSC_REG_22_get_chg22_2(data)                                  ((0x00000004&(data))>>2)
#define MSC_REG_22_get_chg22_1(data)                                  ((0x00000002&(data))>>1)
#define MSC_REG_22_get_chg22_0(data)                                  (0x00000001&(data))

#define  MSC_REG_23                                                             0x1800A08C
#define  MSC_REG_23_reg_addr                                                    "0xB800A08C"
#define  MSC_REG_23_reg                                                         0xB800A08C
#define  MSC_REG_23_inst_addr                                                   "0x0020"
#define  MSC_REG_23_inst                                                        0x0020
#define MSC_REG_23_chg23_7_shift                                      (7)
#define MSC_REG_23_chg23_6_shift                                      (6)
#define MSC_REG_23_chg23_5_shift                                      (5)
#define MSC_REG_23_chg23_4_shift                                      (4)
#define MSC_REG_23_chg23_3_shift                                      (3)
#define MSC_REG_23_chg23_2_shift                                      (2)
#define MSC_REG_23_chg23_1_shift                                      (1)
#define MSC_REG_23_chg23_0_shift                                      (0)
#define MSC_REG_23_chg23_7_mask                                       (0x00000080)
#define MSC_REG_23_chg23_6_mask                                       (0x00000040)
#define MSC_REG_23_chg23_5_mask                                       (0x00000020)
#define MSC_REG_23_chg23_4_mask                                       (0x00000010)
#define MSC_REG_23_chg23_3_mask                                       (0x00000008)
#define MSC_REG_23_chg23_2_mask                                       (0x00000004)
#define MSC_REG_23_chg23_1_mask                                       (0x00000002)
#define MSC_REG_23_chg23_0_mask                                       (0x00000001)
#define MSC_REG_23_chg23_7(data)                                      (0x00000080&((data)<<7))
#define MSC_REG_23_chg23_6(data)                                      (0x00000040&((data)<<6))
#define MSC_REG_23_chg23_5(data)                                      (0x00000020&((data)<<5))
#define MSC_REG_23_chg23_4(data)                                      (0x00000010&((data)<<4))
#define MSC_REG_23_chg23_3(data)                                      (0x00000008&((data)<<3))
#define MSC_REG_23_chg23_2(data)                                      (0x00000004&((data)<<2))
#define MSC_REG_23_chg23_1(data)                                      (0x00000002&((data)<<1))
#define MSC_REG_23_chg23_0(data)                                      (0x00000001&(data))
#define MSC_REG_23_get_chg23_7(data)                                  ((0x00000080&(data))>>7)
#define MSC_REG_23_get_chg23_6(data)                                  ((0x00000040&(data))>>6)
#define MSC_REG_23_get_chg23_5(data)                                  ((0x00000020&(data))>>5)
#define MSC_REG_23_get_chg23_4(data)                                  ((0x00000010&(data))>>4)
#define MSC_REG_23_get_chg23_3(data)                                  ((0x00000008&(data))>>3)
#define MSC_REG_23_get_chg23_2(data)                                  ((0x00000004&(data))>>2)
#define MSC_REG_23_get_chg23_1(data)                                  ((0x00000002&(data))>>1)
#define MSC_REG_23_get_chg23_0(data)                                  (0x00000001&(data))

#define  MSC_REG_24                                                             0x1800A090
#define  MSC_REG_24_reg_addr                                                    "0xB800A090"
#define  MSC_REG_24_reg                                                         0xB800A090
#define  MSC_REG_24_inst_addr                                                   "0x0021"
#define  MSC_REG_24_inst                                                        0x0021
#define MSC_REG_24_chg24_7_shift                                      (7)
#define MSC_REG_24_chg24_6_shift                                      (6)
#define MSC_REG_24_chg24_5_shift                                      (5)
#define MSC_REG_24_chg24_4_shift                                      (4)
#define MSC_REG_24_chg24_3_shift                                      (3)
#define MSC_REG_24_chg24_2_shift                                      (2)
#define MSC_REG_24_chg24_1_shift                                      (1)
#define MSC_REG_24_chg24_0_shift                                      (0)
#define MSC_REG_24_chg24_7_mask                                       (0x00000080)
#define MSC_REG_24_chg24_6_mask                                       (0x00000040)
#define MSC_REG_24_chg24_5_mask                                       (0x00000020)
#define MSC_REG_24_chg24_4_mask                                       (0x00000010)
#define MSC_REG_24_chg24_3_mask                                       (0x00000008)
#define MSC_REG_24_chg24_2_mask                                       (0x00000004)
#define MSC_REG_24_chg24_1_mask                                       (0x00000002)
#define MSC_REG_24_chg24_0_mask                                       (0x00000001)
#define MSC_REG_24_chg24_7(data)                                      (0x00000080&((data)<<7))
#define MSC_REG_24_chg24_6(data)                                      (0x00000040&((data)<<6))
#define MSC_REG_24_chg24_5(data)                                      (0x00000020&((data)<<5))
#define MSC_REG_24_chg24_4(data)                                      (0x00000010&((data)<<4))
#define MSC_REG_24_chg24_3(data)                                      (0x00000008&((data)<<3))
#define MSC_REG_24_chg24_2(data)                                      (0x00000004&((data)<<2))
#define MSC_REG_24_chg24_1(data)                                      (0x00000002&((data)<<1))
#define MSC_REG_24_chg24_0(data)                                      (0x00000001&(data))
#define MSC_REG_24_get_chg24_7(data)                                  ((0x00000080&(data))>>7)
#define MSC_REG_24_get_chg24_6(data)                                  ((0x00000040&(data))>>6)
#define MSC_REG_24_get_chg24_5(data)                                  ((0x00000020&(data))>>5)
#define MSC_REG_24_get_chg24_4(data)                                  ((0x00000010&(data))>>4)
#define MSC_REG_24_get_chg24_3(data)                                  ((0x00000008&(data))>>3)
#define MSC_REG_24_get_chg24_2(data)                                  ((0x00000004&(data))>>2)
#define MSC_REG_24_get_chg24_1(data)                                  ((0x00000002&(data))>>1)
#define MSC_REG_24_get_chg24_0(data)                                  (0x00000001&(data))

#define  MSC_REG_25                                                             0x1800A094
#define  MSC_REG_25_reg_addr                                                    "0xB800A094"
#define  MSC_REG_25_reg                                                         0xB800A094
#define  MSC_REG_25_inst_addr                                                   "0x0022"
#define  MSC_REG_25_inst                                                        0x0022
#define MSC_REG_25_chg25_7_shift                                      (7)
#define MSC_REG_25_chg25_6_shift                                      (6)
#define MSC_REG_25_chg25_5_shift                                      (5)
#define MSC_REG_25_chg25_4_shift                                      (4)
#define MSC_REG_25_chg25_3_shift                                      (3)
#define MSC_REG_25_chg25_2_shift                                      (2)
#define MSC_REG_25_chg25_1_shift                                      (1)
#define MSC_REG_25_chg25_0_shift                                      (0)
#define MSC_REG_25_chg25_7_mask                                       (0x00000080)
#define MSC_REG_25_chg25_6_mask                                       (0x00000040)
#define MSC_REG_25_chg25_5_mask                                       (0x00000020)
#define MSC_REG_25_chg25_4_mask                                       (0x00000010)
#define MSC_REG_25_chg25_3_mask                                       (0x00000008)
#define MSC_REG_25_chg25_2_mask                                       (0x00000004)
#define MSC_REG_25_chg25_1_mask                                       (0x00000002)
#define MSC_REG_25_chg25_0_mask                                       (0x00000001)
#define MSC_REG_25_chg25_7(data)                                      (0x00000080&((data)<<7))
#define MSC_REG_25_chg25_6(data)                                      (0x00000040&((data)<<6))
#define MSC_REG_25_chg25_5(data)                                      (0x00000020&((data)<<5))
#define MSC_REG_25_chg25_4(data)                                      (0x00000010&((data)<<4))
#define MSC_REG_25_chg25_3(data)                                      (0x00000008&((data)<<3))
#define MSC_REG_25_chg25_2(data)                                      (0x00000004&((data)<<2))
#define MSC_REG_25_chg25_1(data)                                      (0x00000002&((data)<<1))
#define MSC_REG_25_chg25_0(data)                                      (0x00000001&(data))
#define MSC_REG_25_get_chg25_7(data)                                  ((0x00000080&(data))>>7)
#define MSC_REG_25_get_chg25_6(data)                                  ((0x00000040&(data))>>6)
#define MSC_REG_25_get_chg25_5(data)                                  ((0x00000020&(data))>>5)
#define MSC_REG_25_get_chg25_4(data)                                  ((0x00000010&(data))>>4)
#define MSC_REG_25_get_chg25_3(data)                                  ((0x00000008&(data))>>3)
#define MSC_REG_25_get_chg25_2(data)                                  ((0x00000004&(data))>>2)
#define MSC_REG_25_get_chg25_1(data)                                  ((0x00000002&(data))>>1)
#define MSC_REG_25_get_chg25_0(data)                                  (0x00000001&(data))

#define  MSC_REG_26                                                             0x1800A098
#define  MSC_REG_26_reg_addr                                                    "0xB800A098"
#define  MSC_REG_26_reg                                                         0xB800A098
#define  MSC_REG_26_inst_addr                                                   "0x0023"
#define  MSC_REG_26_inst                                                        0x0023
#define MSC_REG_26_chg26_7_shift                                      (7)
#define MSC_REG_26_chg26_6_shift                                      (6)
#define MSC_REG_26_chg26_5_shift                                      (5)
#define MSC_REG_26_chg26_4_shift                                      (4)
#define MSC_REG_26_chg26_3_shift                                      (3)
#define MSC_REG_26_chg26_2_shift                                      (2)
#define MSC_REG_26_chg26_1_shift                                      (1)
#define MSC_REG_26_chg26_0_shift                                      (0)
#define MSC_REG_26_chg26_7_mask                                       (0x00000080)
#define MSC_REG_26_chg26_6_mask                                       (0x00000040)
#define MSC_REG_26_chg26_5_mask                                       (0x00000020)
#define MSC_REG_26_chg26_4_mask                                       (0x00000010)
#define MSC_REG_26_chg26_3_mask                                       (0x00000008)
#define MSC_REG_26_chg26_2_mask                                       (0x00000004)
#define MSC_REG_26_chg26_1_mask                                       (0x00000002)
#define MSC_REG_26_chg26_0_mask                                       (0x00000001)
#define MSC_REG_26_chg26_7(data)                                      (0x00000080&((data)<<7))
#define MSC_REG_26_chg26_6(data)                                      (0x00000040&((data)<<6))
#define MSC_REG_26_chg26_5(data)                                      (0x00000020&((data)<<5))
#define MSC_REG_26_chg26_4(data)                                      (0x00000010&((data)<<4))
#define MSC_REG_26_chg26_3(data)                                      (0x00000008&((data)<<3))
#define MSC_REG_26_chg26_2(data)                                      (0x00000004&((data)<<2))
#define MSC_REG_26_chg26_1(data)                                      (0x00000002&((data)<<1))
#define MSC_REG_26_chg26_0(data)                                      (0x00000001&(data))
#define MSC_REG_26_get_chg26_7(data)                                  ((0x00000080&(data))>>7)
#define MSC_REG_26_get_chg26_6(data)                                  ((0x00000040&(data))>>6)
#define MSC_REG_26_get_chg26_5(data)                                  ((0x00000020&(data))>>5)
#define MSC_REG_26_get_chg26_4(data)                                  ((0x00000010&(data))>>4)
#define MSC_REG_26_get_chg26_3(data)                                  ((0x00000008&(data))>>3)
#define MSC_REG_26_get_chg26_2(data)                                  ((0x00000004&(data))>>2)
#define MSC_REG_26_get_chg26_1(data)                                  ((0x00000002&(data))>>1)
#define MSC_REG_26_get_chg26_0(data)                                  (0x00000001&(data))

#define  MSC_REG_27                                                             0x1800A09C
#define  MSC_REG_27_reg_addr                                                    "0xB800A09C"
#define  MSC_REG_27_reg                                                         0xB800A09C
#define  MSC_REG_27_inst_addr                                                   "0x0024"
#define  MSC_REG_27_inst                                                        0x0024
#define MSC_REG_27_chg27_7_shift                                      (7)
#define MSC_REG_27_chg27_6_shift                                      (6)
#define MSC_REG_27_chg27_5_shift                                      (5)
#define MSC_REG_27_chg27_4_shift                                      (4)
#define MSC_REG_27_chg27_3_shift                                      (3)
#define MSC_REG_27_chg27_2_shift                                      (2)
#define MSC_REG_27_chg27_1_shift                                      (1)
#define MSC_REG_27_chg27_0_shift                                      (0)
#define MSC_REG_27_chg27_7_mask                                       (0x00000080)
#define MSC_REG_27_chg27_6_mask                                       (0x00000040)
#define MSC_REG_27_chg27_5_mask                                       (0x00000020)
#define MSC_REG_27_chg27_4_mask                                       (0x00000010)
#define MSC_REG_27_chg27_3_mask                                       (0x00000008)
#define MSC_REG_27_chg27_2_mask                                       (0x00000004)
#define MSC_REG_27_chg27_1_mask                                       (0x00000002)
#define MSC_REG_27_chg27_0_mask                                       (0x00000001)
#define MSC_REG_27_chg27_7(data)                                      (0x00000080&((data)<<7))
#define MSC_REG_27_chg27_6(data)                                      (0x00000040&((data)<<6))
#define MSC_REG_27_chg27_5(data)                                      (0x00000020&((data)<<5))
#define MSC_REG_27_chg27_4(data)                                      (0x00000010&((data)<<4))
#define MSC_REG_27_chg27_3(data)                                      (0x00000008&((data)<<3))
#define MSC_REG_27_chg27_2(data)                                      (0x00000004&((data)<<2))
#define MSC_REG_27_chg27_1(data)                                      (0x00000002&((data)<<1))
#define MSC_REG_27_chg27_0(data)                                      (0x00000001&(data))
#define MSC_REG_27_get_chg27_7(data)                                  ((0x00000080&(data))>>7)
#define MSC_REG_27_get_chg27_6(data)                                  ((0x00000040&(data))>>6)
#define MSC_REG_27_get_chg27_5(data)                                  ((0x00000020&(data))>>5)
#define MSC_REG_27_get_chg27_4(data)                                  ((0x00000010&(data))>>4)
#define MSC_REG_27_get_chg27_3(data)                                  ((0x00000008&(data))>>3)
#define MSC_REG_27_get_chg27_2(data)                                  ((0x00000004&(data))>>2)
#define MSC_REG_27_get_chg27_1(data)                                  ((0x00000002&(data))>>1)
#define MSC_REG_27_get_chg27_0(data)                                  (0x00000001&(data))

#define  MSC_REG_30                                                             0x1800A0C0
#define  MSC_REG_30_reg_addr                                                    "0xB800A0C0"
#define  MSC_REG_30_reg                                                         0xB800A0C0
#define  MSC_REG_30_inst_addr                                                   "0x0025"
#define  MSC_REG_30_inst                                                        0x0025
#define MSC_REG_30_conn_rdy_shift                                     (1)
#define MSC_REG_30_dcap_rdy_shift                                     (0)
#define MSC_REG_30_conn_rdy_mask                                      (0x000000FE)
#define MSC_REG_30_dcap_rdy_mask                                      (0x00000001)
#define MSC_REG_30_conn_rdy(data)                                     (0x000000FE&((data)<<1))
#define MSC_REG_30_dcap_rdy(data)                                     (0x00000001&(data))
#define MSC_REG_30_get_conn_rdy(data)                                 ((0x000000FE&(data))>>1)
#define MSC_REG_30_get_dcap_rdy(data)                                 (0x00000001&(data))

#define  MSC_REG_31                                                             0x1800A0C4
#define  MSC_REG_31_reg_addr                                                    "0xB800A0C4"
#define  MSC_REG_31_reg                                                         0xB800A0C4
#define  MSC_REG_31_inst_addr                                                   "0x0026"
#define  MSC_REG_31_inst                                                        0x0026
#define MSC_REG_31_link_mode_shift                                    (5)
#define MSC_REG_31_muted_shift                                        (4)
#define MSC_REG_31_path_en_shift                                      (3)
#define MSC_REG_31_clk_mode_shift                                     (0)
#define MSC_REG_31_link_mode_mask                                     (0x000000E0)
#define MSC_REG_31_muted_mask                                         (0x00000010)
#define MSC_REG_31_path_en_mask                                       (0x00000008)
#define MSC_REG_31_clk_mode_mask                                      (0x00000007)
#define MSC_REG_31_link_mode(data)                                    (0x000000E0&((data)<<5))
#define MSC_REG_31_muted(data)                                        (0x00000010&((data)<<4))
#define MSC_REG_31_path_en(data)                                      (0x00000008&((data)<<3))
#define MSC_REG_31_clk_mode(data)                                     (0x00000007&(data))
#define MSC_REG_31_get_link_mode(data)                                ((0x000000E0&(data))>>5)
#define MSC_REG_31_get_muted(data)                                    ((0x00000010&(data))>>4)
#define MSC_REG_31_get_path_en(data)                                  ((0x00000008&(data))>>3)
#define MSC_REG_31_get_clk_mode(data)                                 (0x00000007&(data))

#define  MSC_REG_32                                                             0x1800A0C8
#define  MSC_REG_32_reg_addr                                                    "0xB800A0C8"
#define  MSC_REG_32_reg                                                         0xB800A0C8
#define  MSC_REG_32_inst_addr                                                   "0x0027"
#define  MSC_REG_32_inst                                                        0x0027
#define MSC_REG_32_stat_32_shift                                      (0)
#define MSC_REG_32_stat_32_mask                                       (0x000000FF)
#define MSC_REG_32_stat_32(data)                                      (0x000000FF&(data))
#define MSC_REG_32_get_stat_32(data)                                  (0x000000FF&(data))

#define  MSC_REG_33                                                             0x1800A0CC
#define  MSC_REG_33_reg_addr                                                    "0xB800A0CC"
#define  MSC_REG_33_reg                                                         0xB800A0CC
#define  MSC_REG_33_inst_addr                                                   "0x0028"
#define  MSC_REG_33_inst                                                        0x0028
#define MSC_REG_33_stat_33_shift                                      (0)
#define MSC_REG_33_stat_33_mask                                       (0x000000FF)
#define MSC_REG_33_stat_33(data)                                      (0x000000FF&(data))
#define MSC_REG_33_get_stat_33(data)                                  (0x000000FF&(data))

#define  MSC_REG_34                                                             0x1800A0D0
#define  MSC_REG_34_reg_addr                                                    "0xB800A0D0"
#define  MSC_REG_34_reg                                                         0xB800A0D0
#define  MSC_REG_34_inst_addr                                                   "0x0029"
#define  MSC_REG_34_inst                                                        0x0029
#define MSC_REG_34_stat_34_shift                                      (0)
#define MSC_REG_34_stat_34_mask                                       (0x000000FF)
#define MSC_REG_34_stat_34(data)                                      (0x000000FF&(data))
#define MSC_REG_34_get_stat_34(data)                                  (0x000000FF&(data))

#define  MSC_REG_35                                                             0x1800A0D4
#define  MSC_REG_35_reg_addr                                                    "0xB800A0D4"
#define  MSC_REG_35_reg                                                         0xB800A0D4
#define  MSC_REG_35_inst_addr                                                   "0x002A"
#define  MSC_REG_35_inst                                                        0x002A
#define MSC_REG_35_stat_35_shift                                      (0)
#define MSC_REG_35_stat_35_mask                                       (0x000000FF)
#define MSC_REG_35_stat_35(data)                                      (0x000000FF&(data))
#define MSC_REG_35_get_stat_35(data)                                  (0x000000FF&(data))

#define  MSC_REG_36                                                             0x1800A0D8
#define  MSC_REG_36_reg_addr                                                    "0xB800A0D8"
#define  MSC_REG_36_reg                                                         0xB800A0D8
#define  MSC_REG_36_inst_addr                                                   "0x002B"
#define  MSC_REG_36_inst                                                        0x002B
#define MSC_REG_36_stat_36_shift                                      (0)
#define MSC_REG_36_stat_36_mask                                       (0x000000FF)
#define MSC_REG_36_stat_36(data)                                      (0x000000FF&(data))
#define MSC_REG_36_get_stat_36(data)                                  (0x000000FF&(data))

#define  MSC_REG_37                                                             0x1800A0DC
#define  MSC_REG_37_reg_addr                                                    "0xB800A0DC"
#define  MSC_REG_37_reg                                                         0xB800A0DC
#define  MSC_REG_37_inst_addr                                                   "0x002C"
#define  MSC_REG_37_inst                                                        0x002C
#define MSC_REG_37_stat_37_shift                                      (0)
#define MSC_REG_37_stat_37_mask                                       (0x000000FF)
#define MSC_REG_37_stat_37(data)                                      (0x000000FF&(data))
#define MSC_REG_37_get_stat_37(data)                                  (0x000000FF&(data))

#define  MSC_REG_40                                                             0x1800A100
#define  MSC_REG_40_reg_addr                                                    "0xB800A100"
#define  MSC_REG_40_reg                                                         0xB800A100
#define  MSC_REG_40_inst_addr                                                   "0x002D"
#define  MSC_REG_40_inst                                                        0x002D
#define MSC_REG_40_scratch_40_shift                                   (0)
#define MSC_REG_40_scratch_40_mask                                    (0x000000FF)
#define MSC_REG_40_scratch_40(data)                                   (0x000000FF&(data))
#define MSC_REG_40_get_scratch_40(data)                               (0x000000FF&(data))

#define  MSC_REG_41                                                             0x1800A104
#define  MSC_REG_41_reg_addr                                                    "0xB800A104"
#define  MSC_REG_41_reg                                                         0xB800A104
#define  MSC_REG_41_inst_addr                                                   "0x002E"
#define  MSC_REG_41_inst                                                        0x002E
#define MSC_REG_41_scratch_41_shift                                   (0)
#define MSC_REG_41_scratch_41_mask                                    (0x000000FF)
#define MSC_REG_41_scratch_41(data)                                   (0x000000FF&(data))
#define MSC_REG_41_get_scratch_41(data)                               (0x000000FF&(data))

#define  MSC_REG_42                                                             0x1800A108
#define  MSC_REG_42_reg_addr                                                    "0xB800A108"
#define  MSC_REG_42_reg                                                         0xB800A108
#define  MSC_REG_42_inst_addr                                                   "0x002F"
#define  MSC_REG_42_inst                                                        0x002F
#define MSC_REG_42_scratch_42_shift                                   (0)
#define MSC_REG_42_scratch_42_mask                                    (0x000000FF)
#define MSC_REG_42_scratch_42(data)                                   (0x000000FF&(data))
#define MSC_REG_42_get_scratch_42(data)                               (0x000000FF&(data))

#define  MSC_REG_43                                                             0x1800A10C
#define  MSC_REG_43_reg_addr                                                    "0xB800A10C"
#define  MSC_REG_43_reg                                                         0xB800A10C
#define  MSC_REG_43_inst_addr                                                   "0x0030"
#define  MSC_REG_43_inst                                                        0x0030
#define MSC_REG_43_scratch_43_shift                                   (0)
#define MSC_REG_43_scratch_43_mask                                    (0x000000FF)
#define MSC_REG_43_scratch_43(data)                                   (0x000000FF&(data))
#define MSC_REG_43_get_scratch_43(data)                               (0x000000FF&(data))

#define  MSC_REG_44                                                             0x1800A110
#define  MSC_REG_44_reg_addr                                                    "0xB800A110"
#define  MSC_REG_44_reg                                                         0xB800A110
#define  MSC_REG_44_inst_addr                                                   "0x0031"
#define  MSC_REG_44_inst                                                        0x0031
#define MSC_REG_44_scratch_44_shift                                   (0)
#define MSC_REG_44_scratch_44_mask                                    (0x000000FF)
#define MSC_REG_44_scratch_44(data)                                   (0x000000FF&(data))
#define MSC_REG_44_get_scratch_44(data)                               (0x000000FF&(data))

#define  MSC_REG_45                                                             0x1800A114
#define  MSC_REG_45_reg_addr                                                    "0xB800A114"
#define  MSC_REG_45_reg                                                         0xB800A114
#define  MSC_REG_45_inst_addr                                                   "0x0032"
#define  MSC_REG_45_inst                                                        0x0032
#define MSC_REG_45_scratch_45_shift                                   (0)
#define MSC_REG_45_scratch_45_mask                                    (0x000000FF)
#define MSC_REG_45_scratch_45(data)                                   (0x000000FF&(data))
#define MSC_REG_45_get_scratch_45(data)                               (0x000000FF&(data))

#define  MSC_REG_46                                                             0x1800A118
#define  MSC_REG_46_reg_addr                                                    "0xB800A118"
#define  MSC_REG_46_reg                                                         0xB800A118
#define  MSC_REG_46_inst_addr                                                   "0x0033"
#define  MSC_REG_46_inst                                                        0x0033
#define MSC_REG_46_scratch_46_shift                                   (0)
#define MSC_REG_46_scratch_46_mask                                    (0x000000FF)
#define MSC_REG_46_scratch_46(data)                                   (0x000000FF&(data))
#define MSC_REG_46_get_scratch_46(data)                               (0x000000FF&(data))

#define  MSC_REG_47                                                             0x1800A11C
#define  MSC_REG_47_reg_addr                                                    "0xB800A11C"
#define  MSC_REG_47_reg                                                         0xB800A11C
#define  MSC_REG_47_inst_addr                                                   "0x0034"
#define  MSC_REG_47_inst                                                        0x0034
#define MSC_REG_47_scratch_47_shift                                   (0)
#define MSC_REG_47_scratch_47_mask                                    (0x000000FF)
#define MSC_REG_47_scratch_47(data)                                   (0x000000FF&(data))
#define MSC_REG_47_get_scratch_47(data)                               (0x000000FF&(data))

#define  MSC_REG_48                                                             0x1800A120
#define  MSC_REG_48_reg_addr                                                    "0xB800A120"
#define  MSC_REG_48_reg                                                         0xB800A120
#define  MSC_REG_48_inst_addr                                                   "0x0035"
#define  MSC_REG_48_inst                                                        0x0035
#define MSC_REG_48_scratch_48_shift                                   (0)
#define MSC_REG_48_scratch_48_mask                                    (0x000000FF)
#define MSC_REG_48_scratch_48(data)                                   (0x000000FF&(data))
#define MSC_REG_48_get_scratch_48(data)                               (0x000000FF&(data))

#define  MSC_REG_49                                                             0x1800A124
#define  MSC_REG_49_reg_addr                                                    "0xB800A124"
#define  MSC_REG_49_reg                                                         0xB800A124
#define  MSC_REG_49_inst_addr                                                   "0x0036"
#define  MSC_REG_49_inst                                                        0x0036
#define MSC_REG_49_scratch_49_shift                                   (0)
#define MSC_REG_49_scratch_49_mask                                    (0x000000FF)
#define MSC_REG_49_scratch_49(data)                                   (0x000000FF&(data))
#define MSC_REG_49_get_scratch_49(data)                               (0x000000FF&(data))

#define  MSC_REG_4A                                                             0x1800A128
#define  MSC_REG_4A_reg_addr                                                    "0xB800A128"
#define  MSC_REG_4A_reg                                                         0xB800A128
#define  MSC_REG_4A_inst_addr                                                   "0x0037"
#define  MSC_REG_4A_inst                                                        0x0037
#define MSC_REG_4A_scratch_4a_shift                                   (0)
#define MSC_REG_4A_scratch_4a_mask                                    (0x000000FF)
#define MSC_REG_4A_scratch_4a(data)                                   (0x000000FF&(data))
#define MSC_REG_4A_get_scratch_4a(data)                               (0x000000FF&(data))

#define  MSC_REG_4B                                                             0x1800A12C
#define  MSC_REG_4B_reg_addr                                                    "0xB800A12C"
#define  MSC_REG_4B_reg                                                         0xB800A12C
#define  MSC_REG_4B_inst_addr                                                   "0x0038"
#define  MSC_REG_4B_inst                                                        0x0038
#define MSC_REG_4B_scratch_4b_shift                                   (0)
#define MSC_REG_4B_scratch_4b_mask                                    (0x000000FF)
#define MSC_REG_4B_scratch_4b(data)                                   (0x000000FF&(data))
#define MSC_REG_4B_get_scratch_4b(data)                               (0x000000FF&(data))

#define  MSC_REG_4C                                                             0x1800A130
#define  MSC_REG_4C_reg_addr                                                    "0xB800A130"
#define  MSC_REG_4C_reg                                                         0xB800A130
#define  MSC_REG_4C_inst_addr                                                   "0x0039"
#define  MSC_REG_4C_inst                                                        0x0039
#define MSC_REG_4C_scratch_4c_shift                                   (0)
#define MSC_REG_4C_scratch_4c_mask                                    (0x000000FF)
#define MSC_REG_4C_scratch_4c(data)                                   (0x000000FF&(data))
#define MSC_REG_4C_get_scratch_4c(data)                               (0x000000FF&(data))

#define  MSC_REG_4D                                                             0x1800A134
#define  MSC_REG_4D_reg_addr                                                    "0xB800A134"
#define  MSC_REG_4D_reg                                                         0xB800A134
#define  MSC_REG_4D_inst_addr                                                   "0x003A"
#define  MSC_REG_4D_inst                                                        0x003A
#define MSC_REG_4D_scratch_4d_shift                                   (0)
#define MSC_REG_4D_scratch_4d_mask                                    (0x000000FF)
#define MSC_REG_4D_scratch_4d(data)                                   (0x000000FF&(data))
#define MSC_REG_4D_get_scratch_4d(data)                               (0x000000FF&(data))

#define  MSC_REG_4E                                                             0x1800A138
#define  MSC_REG_4E_reg_addr                                                    "0xB800A138"
#define  MSC_REG_4E_reg                                                         0xB800A138
#define  MSC_REG_4E_inst_addr                                                   "0x003B"
#define  MSC_REG_4E_inst                                                        0x003B
#define MSC_REG_4E_scratch_4e_shift                                   (0)
#define MSC_REG_4E_scratch_4e_mask                                    (0x000000FF)
#define MSC_REG_4E_scratch_4e(data)                                   (0x000000FF&(data))
#define MSC_REG_4E_get_scratch_4e(data)                               (0x000000FF&(data))

#define  MSC_REG_4F                                                             0x1800A13C
#define  MSC_REG_4F_reg_addr                                                    "0xB800A13C"
#define  MSC_REG_4F_reg                                                         0xB800A13C
#define  MSC_REG_4F_inst_addr                                                   "0x003C"
#define  MSC_REG_4F_inst                                                        0x003C
#define MSC_REG_4F_scratch_4f_shift                                   (0)
#define MSC_REG_4F_scratch_4f_mask                                    (0x000000FF)
#define MSC_REG_4F_scratch_4f(data)                                   (0x000000FF&(data))
#define MSC_REG_4F_get_scratch_4f(data)                               (0x000000FF&(data))

#define  MSC_REG_50                                                             0x1800A140
#define  MSC_REG_50_reg_addr                                                    "0xB800A140"
#define  MSC_REG_50_reg                                                         0xB800A140
#define  MSC_REG_50_inst_addr                                                   "0x003D"
#define  MSC_REG_50_inst                                                        0x003D
#define MSC_REG_50_scratch_50_shift                                   (0)
#define MSC_REG_50_scratch_50_mask                                    (0x000000FF)
#define MSC_REG_50_scratch_50(data)                                   (0x000000FF&(data))
#define MSC_REG_50_get_scratch_50(data)                               (0x000000FF&(data))

#define  MSC_REG_51                                                             0x1800A144
#define  MSC_REG_51_reg_addr                                                    "0xB800A144"
#define  MSC_REG_51_reg                                                         0xB800A144
#define  MSC_REG_51_inst_addr                                                   "0x003E"
#define  MSC_REG_51_inst                                                        0x003E
#define MSC_REG_51_scratch_51_shift                                   (0)
#define MSC_REG_51_scratch_51_mask                                    (0x000000FF)
#define MSC_REG_51_scratch_51(data)                                   (0x000000FF&(data))
#define MSC_REG_51_get_scratch_51(data)                               (0x000000FF&(data))

#define  MSC_REG_52                                                             0x1800A148
#define  MSC_REG_52_reg_addr                                                    "0xB800A148"
#define  MSC_REG_52_reg                                                         0xB800A148
#define  MSC_REG_52_inst_addr                                                   "0x003F"
#define  MSC_REG_52_inst                                                        0x003F
#define MSC_REG_52_scratch_52_shift                                   (0)
#define MSC_REG_52_scratch_52_mask                                    (0x000000FF)
#define MSC_REG_52_scratch_52(data)                                   (0x000000FF&(data))
#define MSC_REG_52_get_scratch_52(data)                               (0x000000FF&(data))

#define  MSC_REG_53                                                             0x1800A14C
#define  MSC_REG_53_reg_addr                                                    "0xB800A14C"
#define  MSC_REG_53_reg                                                         0xB800A14C
#define  MSC_REG_53_inst_addr                                                   "0x0040"
#define  MSC_REG_53_inst                                                        0x0040
#define MSC_REG_53_scratch_53_shift                                   (0)
#define MSC_REG_53_scratch_53_mask                                    (0x000000FF)
#define MSC_REG_53_scratch_53(data)                                   (0x000000FF&(data))
#define MSC_REG_53_get_scratch_53(data)                               (0x000000FF&(data))

#define  MSC_REG_54                                                             0x1800A150
#define  MSC_REG_54_reg_addr                                                    "0xB800A150"
#define  MSC_REG_54_reg                                                         0xB800A150
#define  MSC_REG_54_inst_addr                                                   "0x0041"
#define  MSC_REG_54_inst                                                        0x0041
#define MSC_REG_54_scratch_54_shift                                   (0)
#define MSC_REG_54_scratch_54_mask                                    (0x000000FF)
#define MSC_REG_54_scratch_54(data)                                   (0x000000FF&(data))
#define MSC_REG_54_get_scratch_54(data)                               (0x000000FF&(data))

#define  MSC_REG_55                                                             0x1800A154
#define  MSC_REG_55_reg_addr                                                    "0xB800A154"
#define  MSC_REG_55_reg                                                         0xB800A154
#define  MSC_REG_55_inst_addr                                                   "0x0042"
#define  MSC_REG_55_inst                                                        0x0042
#define MSC_REG_55_scratch_55_shift                                   (0)
#define MSC_REG_55_scratch_55_mask                                    (0x000000FF)
#define MSC_REG_55_scratch_55(data)                                   (0x000000FF&(data))
#define MSC_REG_55_get_scratch_55(data)                               (0x000000FF&(data))

#define  MSC_REG_56                                                             0x1800A158
#define  MSC_REG_56_reg_addr                                                    "0xB800A158"
#define  MSC_REG_56_reg                                                         0xB800A158
#define  MSC_REG_56_inst_addr                                                   "0x0043"
#define  MSC_REG_56_inst                                                        0x0043
#define MSC_REG_56_scratch_56_shift                                   (0)
#define MSC_REG_56_scratch_56_mask                                    (0x000000FF)
#define MSC_REG_56_scratch_56(data)                                   (0x000000FF&(data))
#define MSC_REG_56_get_scratch_56(data)                               (0x000000FF&(data))

#define  MSC_REG_57                                                             0x1800A15C
#define  MSC_REG_57_reg_addr                                                    "0xB800A15C"
#define  MSC_REG_57_reg                                                         0xB800A15C
#define  MSC_REG_57_inst_addr                                                   "0x0044"
#define  MSC_REG_57_inst                                                        0x0044
#define MSC_REG_57_scratch_57_shift                                   (0)
#define MSC_REG_57_scratch_57_mask                                    (0x000000FF)
#define MSC_REG_57_scratch_57(data)                                   (0x000000FF&(data))
#define MSC_REG_57_get_scratch_57(data)                               (0x000000FF&(data))

#define  MSC_REG_58                                                             0x1800A160
#define  MSC_REG_58_reg_addr                                                    "0xB800A160"
#define  MSC_REG_58_reg                                                         0xB800A160
#define  MSC_REG_58_inst_addr                                                   "0x0045"
#define  MSC_REG_58_inst                                                        0x0045
#define MSC_REG_58_scratch_58_shift                                   (0)
#define MSC_REG_58_scratch_58_mask                                    (0x000000FF)
#define MSC_REG_58_scratch_58(data)                                   (0x000000FF&(data))
#define MSC_REG_58_get_scratch_58(data)                               (0x000000FF&(data))

#define  MSC_REG_59                                                             0x1800A164
#define  MSC_REG_59_reg_addr                                                    "0xB800A164"
#define  MSC_REG_59_reg                                                         0xB800A164
#define  MSC_REG_59_inst_addr                                                   "0x0046"
#define  MSC_REG_59_inst                                                        0x0046
#define MSC_REG_59_scratch_59_shift                                   (0)
#define MSC_REG_59_scratch_59_mask                                    (0x000000FF)
#define MSC_REG_59_scratch_59(data)                                   (0x000000FF&(data))
#define MSC_REG_59_get_scratch_59(data)                               (0x000000FF&(data))

#define  MSC_REG_5A                                                             0x1800A168
#define  MSC_REG_5A_reg_addr                                                    "0xB800A168"
#define  MSC_REG_5A_reg                                                         0xB800A168
#define  MSC_REG_5A_inst_addr                                                   "0x0047"
#define  MSC_REG_5A_inst                                                        0x0047
#define MSC_REG_5A_scratch_5a_shift                                   (0)
#define MSC_REG_5A_scratch_5a_mask                                    (0x000000FF)
#define MSC_REG_5A_scratch_5a(data)                                   (0x000000FF&(data))
#define MSC_REG_5A_get_scratch_5a(data)                               (0x000000FF&(data))

#define  MSC_REG_5B                                                             0x1800A16C
#define  MSC_REG_5B_reg_addr                                                    "0xB800A16C"
#define  MSC_REG_5B_reg                                                         0xB800A16C
#define  MSC_REG_5B_inst_addr                                                   "0x0048"
#define  MSC_REG_5B_inst                                                        0x0048
#define MSC_REG_5B_scratch_5b_shift                                   (0)
#define MSC_REG_5B_scratch_5b_mask                                    (0x000000FF)
#define MSC_REG_5B_scratch_5b(data)                                   (0x000000FF&(data))
#define MSC_REG_5B_get_scratch_5b(data)                               (0x000000FF&(data))

#define  MSC_REG_5C                                                             0x1800A170
#define  MSC_REG_5C_reg_addr                                                    "0xB800A170"
#define  MSC_REG_5C_reg                                                         0xB800A170
#define  MSC_REG_5C_inst_addr                                                   "0x0049"
#define  MSC_REG_5C_inst                                                        0x0049
#define MSC_REG_5C_scratch_5c_shift                                   (0)
#define MSC_REG_5C_scratch_5c_mask                                    (0x000000FF)
#define MSC_REG_5C_scratch_5c(data)                                   (0x000000FF&(data))
#define MSC_REG_5C_get_scratch_5c(data)                               (0x000000FF&(data))

#define  MSC_REG_5D                                                             0x1800A174
#define  MSC_REG_5D_reg_addr                                                    "0xB800A174"
#define  MSC_REG_5D_reg                                                         0xB800A174
#define  MSC_REG_5D_inst_addr                                                   "0x004A"
#define  MSC_REG_5D_inst                                                        0x004A
#define MSC_REG_5D_scratch_5d_shift                                   (0)
#define MSC_REG_5D_scratch_5d_mask                                    (0x000000FF)
#define MSC_REG_5D_scratch_5d(data)                                   (0x000000FF&(data))
#define MSC_REG_5D_get_scratch_5d(data)                               (0x000000FF&(data))

#define  MSC_REG_5E                                                             0x1800A178
#define  MSC_REG_5E_reg_addr                                                    "0xB800A178"
#define  MSC_REG_5E_reg                                                         0xB800A178
#define  MSC_REG_5E_inst_addr                                                   "0x004B"
#define  MSC_REG_5E_inst                                                        0x004B
#define MSC_REG_5E_scratch_5e_shift                                   (0)
#define MSC_REG_5E_scratch_5e_mask                                    (0x000000FF)
#define MSC_REG_5E_scratch_5e(data)                                   (0x000000FF&(data))
#define MSC_REG_5E_get_scratch_5e(data)                               (0x000000FF&(data))

#define  MSC_REG_5F                                                             0x1800A17C
#define  MSC_REG_5F_reg_addr                                                    "0xB800A17C"
#define  MSC_REG_5F_reg                                                         0xB800A17C
#define  MSC_REG_5F_inst_addr                                                   "0x004C"
#define  MSC_REG_5F_inst                                                        0x004C
#define MSC_REG_5F_scratch_5f_shift                                   (0)
#define MSC_REG_5F_scratch_5f_mask                                    (0x000000FF)
#define MSC_REG_5F_scratch_5f(data)                                   (0x000000FF&(data))
#define MSC_REG_5F_get_scratch_5f(data)                               (0x000000FF&(data))

#define CBUS_LINK_00                                                  0x1800A200
#define CBUS_LINK_00_reg_addr                                         "0xB800A200"
#define CBUS_LINK_00_reg                                              0xB800A200
#define CBUS_LINK_00_inst_addr                                        "0x004D"
#define CBUS_LINK_00_inst                                             0x004D
#define CBUS_LINK_00_sync0_hb_shift                                   (9)
#define CBUS_LINK_00_sync0_lb_shift                                   (0)
#define CBUS_LINK_00_sync0_hb_mask                                    (0x0003FE00)
#define CBUS_LINK_00_sync0_lb_mask                                    (0x000001FF)
#define CBUS_LINK_00_sync0_hb(data)                                   (0x0003FE00&((data)<<9))
#define CBUS_LINK_00_sync0_lb(data)                                   (0x000001FF&(data))
#define CBUS_LINK_00_get_sync0_hb(data)                               ((0x0003FE00&(data))>>9)
#define CBUS_LINK_00_get_sync0_lb(data)                               (0x000001FF&(data))


#define CBUS_LINK_01                                                  0x1800A204
#define CBUS_LINK_01_reg_addr                                         "0xB800A204"
#define CBUS_LINK_01_reg                                              0xB800A204
#define CBUS_LINK_01_inst_addr                                        "0x004E"
#define CBUS_LINK_01_inst                                             0x004E
#define CBUS_LINK_01_sync1_hb_shift                                   (8)
#define CBUS_LINK_01_sync1_lb_shift                                   (0)
#define CBUS_LINK_01_sync1_hb_mask                                    (0x0000FF00)
#define CBUS_LINK_01_sync1_lb_mask                                    (0x000000FF)
#define CBUS_LINK_01_sync1_hb(data)                                   (0x0000FF00&((data)<<8))
#define CBUS_LINK_01_sync1_lb(data)                                   (0x000000FF&(data))
#define CBUS_LINK_01_get_sync1_hb(data)                               ((0x0000FF00&(data))>>8)
#define CBUS_LINK_01_get_sync1_lb(data)                               (0x000000FF&(data))

#define  CBUS_LINK_02                                                           0x1800A208
#define  CBUS_LINK_02_reg_addr                                                  "0xB800A208"
#define  CBUS_LINK_02_reg                                                       0xB800A208
#define  CBUS_LINK_02_inst_addr                                                 "0x004F"
#define  CBUS_LINK_02_inst                                                      0x004F
#define CBUS_LINK_02_sync_bit_time_shift                              (0)
#define CBUS_LINK_02_sync_bit_time_mask                               (0x000000FF)
#define CBUS_LINK_02_sync_bit_time(data)                              (0x000000FF&(data))
#define CBUS_LINK_02_get_sync_bit_time(data)                          (0x000000FF&(data))

#define  CBUS_LINK_03                                                           0x1800A20C
#define  CBUS_LINK_03_reg_addr                                                  "0xB800A20C"
#define  CBUS_LINK_03_reg                                                       0xB800A20C
#define  CBUS_LINK_03_inst_addr                                                 "0x0050"
#define  CBUS_LINK_03_inst                                                      0x0050
#define CBUS_LINK_03_abs_thres_en_shift                               (8)
#define CBUS_LINK_03_abs_threshold_shift                              (0)
#define CBUS_LINK_03_abs_thres_en_mask                                (0x00000100)
#define CBUS_LINK_03_abs_threshold_mask                               (0x000000FF)
#define CBUS_LINK_03_abs_thres_en(data)                               (0x00000100&((data)<<8))
#define CBUS_LINK_03_abs_threshold(data)                              (0x000000FF&(data))
#define CBUS_LINK_03_get_abs_thres_en(data)                           ((0x00000100&(data))>>8)
#define CBUS_LINK_03_get_abs_threshold(data)                          (0x000000FF&(data))

#define  CBUS_LINK_04                                                           0x1800A210
#define  CBUS_LINK_04_reg_addr                                                  "0xB800A210"
#define  CBUS_LINK_04_reg                                                       0xB800A210
#define  CBUS_LINK_04_inst_addr                                                 "0x0051"
#define  CBUS_LINK_04_inst                                                      0x0051
#define CBUS_LINK_04_parity_time_shift                                (0)
#define CBUS_LINK_04_parity_time_mask                                 (0x000000FF)
#define CBUS_LINK_04_parity_time(data)                                (0x000000FF&(data))
#define CBUS_LINK_04_get_parity_time(data)                            (0x000000FF&(data))

#define  CBUS_LINK_05                                                           0x1800A214
#define  CBUS_LINK_05_reg_addr                                                  "0xB800A214"
#define  CBUS_LINK_05_reg                                                       0xB800A214
#define  CBUS_LINK_05_inst_addr                                                 "0x0052"
#define  CBUS_LINK_05_inst                                                      0x0052
#define CBUS_LINK_05_parity_fail_shift                                (7)
#define CBUS_LINK_05_parity_irq_en_shift                              (6)
#define CBUS_LINK_05_ctrl_16_resv_shift                               (5)
#define CBUS_LINK_05_parity_limit_shift                               (0)
#define CBUS_LINK_05_parity_fail_mask                                 (0x00000080)
#define CBUS_LINK_05_parity_irq_en_mask                               (0x00000040)
#define CBUS_LINK_05_ctrl_16_resv_mask                                (0x00000020)
#define CBUS_LINK_05_parity_limit_mask                                (0x0000001F)
#define CBUS_LINK_05_parity_fail(data)                                (0x00000080&((data)<<7))
#define CBUS_LINK_05_parity_irq_en(data)                              (0x00000040&((data)<<6))
#define CBUS_LINK_05_ctrl_16_resv(data)                               (0x00000020&((data)<<5))
#define CBUS_LINK_05_parity_limit(data)                               (0x0000001F&(data))
#define CBUS_LINK_05_get_parity_fail(data)                            ((0x00000080&(data))>>7)
#define CBUS_LINK_05_get_parity_irq_en(data)                          ((0x00000040&(data))>>6)
#define CBUS_LINK_05_get_ctrl_16_resv(data)                           ((0x00000020&(data))>>5)
#define CBUS_LINK_05_get_parity_limit(data)                           (0x0000001F&(data))

#define  CBUS_LINK_06                                                           0x1800A218
#define  CBUS_LINK_06_reg_addr                                                  "0xB800A218"
#define  CBUS_LINK_06_reg                                                       0xB800A218
#define  CBUS_LINK_06_inst_addr                                                 "0x0053"
#define  CBUS_LINK_06_inst                                                      0x0053
#define CBUS_LINK_06_ack_fall_shift                                   (0)
#define CBUS_LINK_06_ack_fall_mask                                    (0x0000007F)
#define CBUS_LINK_06_ack_fall(data)                                   (0x0000007F&(data))
#define CBUS_LINK_06_get_ack_fall(data)                               (0x0000007F&(data))

#define  CBUS_LINK_07                                                           0x1800A21C
#define  CBUS_LINK_07_reg_addr                                                  "0xB800A21C"
#define  CBUS_LINK_07_reg                                                       0xB800A21C
#define  CBUS_LINK_07_inst_addr                                                 "0x0054"
#define  CBUS_LINK_07_inst                                                      0x0054
#define CBUS_LINK_07_ack_0_shift                                      (0)
#define CBUS_LINK_07_ack_0_mask                                       (0x0000007F)
#define CBUS_LINK_07_ack_0(data)                                      (0x0000007F&(data))
#define CBUS_LINK_07_get_ack_0(data)                                  (0x0000007F&(data))

#define  CBUS_LINK_08                                                           0x1800A220
#define  CBUS_LINK_08_reg_addr                                                  "0xB800A220"
#define  CBUS_LINK_08_reg                                                       0xB800A220
#define  CBUS_LINK_08_inst_addr                                                 "0x0055"
#define  CBUS_LINK_08_inst                                                      0x0055
#define CBUS_LINK_08_tx_bit_time_shift                                (0)
#define CBUS_LINK_08_tx_bit_time_mask                                 (0x000000FF)
#define CBUS_LINK_08_tx_bit_time(data)                                (0x000000FF&(data))
#define CBUS_LINK_08_get_tx_bit_time(data)                            (0x000000FF&(data))

#define  CBUS_LINK_09                                                           0x1800A224
#define  CBUS_LINK_09_reg_addr                                                  "0xB800A224"
#define  CBUS_LINK_09_reg                                                       0xB800A224
#define  CBUS_LINK_09_inst_addr                                                 "0x0056"
#define  CBUS_LINK_09_inst                                                      0x0056
#define CBUS_LINK_09_chk_win_up_shift                                 (5)
#define CBUS_LINK_09_chk_win_lo_shift                                 (3)
#define CBUS_LINK_09_fast_reply_en_shift                              (2)
#define CBUS_LINK_09_ctrl_1b_resv_shift                               (0)
#define CBUS_LINK_09_chk_win_up_mask                                  (0x000000E0)
#define CBUS_LINK_09_chk_win_lo_mask                                  (0x00000018)
#define CBUS_LINK_09_fast_reply_en_mask                               (0x00000004)
#define CBUS_LINK_09_ctrl_1b_resv_mask                                (0x00000003)
#define CBUS_LINK_09_chk_win_up(data)                                 (0x000000E0&((data)<<5))
#define CBUS_LINK_09_chk_win_lo(data)                                 (0x00000018&((data)<<3))
#define CBUS_LINK_09_fast_reply_en(data)                              (0x00000004&((data)<<2))
#define CBUS_LINK_09_ctrl_1b_resv(data)                               (0x00000003&(data))
#define CBUS_LINK_09_get_chk_win_up(data)                             ((0x000000E0&(data))>>5)
#define CBUS_LINK_09_get_chk_win_lo(data)                             ((0x00000018&(data))>>3)
#define CBUS_LINK_09_get_fast_reply_en(data)                          ((0x00000004&(data))>>2)
#define CBUS_LINK_09_get_ctrl_1b_resv(data)                           (0x00000003&(data))

#define  CBUS_LINK_0A                                                           0x1800A228
#define  CBUS_LINK_0A_reg_addr                                                  "0xB800A228"
#define  CBUS_LINK_0A_reg                                                       0xB800A228
#define  CBUS_LINK_0A_inst_addr                                                 "0x0057"
#define  CBUS_LINK_0A_inst                                                      0x0057
#define CBUS_LINK_0A_tx_ack_fal_shift                                 (0)
#define CBUS_LINK_0A_tx_ack_fal_mask                                  (0x0000007F)
#define CBUS_LINK_0A_tx_ack_fal(data)                                 (0x0000007F&(data))
#define CBUS_LINK_0A_get_tx_ack_fal(data)                             (0x0000007F&(data))

#define  CBUS_LINK_0B                                                           0x1800A22C
#define  CBUS_LINK_0B_reg_addr                                                  "0xB800A22C"
#define  CBUS_LINK_0B_reg                                                       0xB800A22C
#define  CBUS_LINK_0B_inst_addr                                                 "0x0058"
#define  CBUS_LINK_0B_inst                                                      0x0058
#define CBUS_LINK_0B_tx_ack_low_hb_shift                              (0)
#define CBUS_LINK_0B_tx_ack_low_hb_mask                               (0x0000007F)
#define CBUS_LINK_0B_tx_ack_low_hb(data)                              (0x0000007F&(data))
#define CBUS_LINK_0B_get_tx_ack_low_hb(data)                          (0x0000007F&(data))

#define  CBUS_LINK_0C                                                           0x1800A230
#define  CBUS_LINK_0C_reg_addr                                                  "0xB800A230"
#define  CBUS_LINK_0C_reg                                                       0xB800A230
#define  CBUS_LINK_0C_inst_addr                                                 "0x0059"
#define  CBUS_LINK_0C_inst                                                      0x0059
#define CBUS_LINK_0C_tx_ack_low_lb_shift                              (0)
#define CBUS_LINK_0C_tx_ack_low_lb_mask                               (0x0000007F)
#define CBUS_LINK_0C_tx_ack_low_lb(data)                              (0x0000007F&(data))
#define CBUS_LINK_0C_get_tx_ack_low_lb(data)                          (0x0000007F&(data))

#define  CBUS_LINK_0D                                                           0x1800A234
#define  CBUS_LINK_0D_reg_addr                                                  "0xB800A234"
#define  CBUS_LINK_0D_reg                                                       0xB800A234
#define  CBUS_LINK_0D_inst_addr                                                 "0x005A"
#define  CBUS_LINK_0D_inst                                                      0x005A
#define CBUS_LINK_0D_retry_lv_shift                                   (5)
#define CBUS_LINK_0D_retry_flag_shift                                 (4)
#define CBUS_LINK_0D_ctrl_1f_resv_shift                               (0)
#define CBUS_LINK_0D_retry_lv_mask                                    (0x000000E0)
#define CBUS_LINK_0D_retry_flag_mask                                  (0x00000010)
#define CBUS_LINK_0D_ctrl_1f_resv_mask                                (0x0000000F)
#define CBUS_LINK_0D_retry_lv(data)                                   (0x000000E0&((data)<<5))
#define CBUS_LINK_0D_retry_flag(data)                                 (0x00000010&((data)<<4))
#define CBUS_LINK_0D_ctrl_1f_resv(data)                               (0x0000000F&(data))
#define CBUS_LINK_0D_get_retry_lv(data)                               ((0x000000E0&(data))>>5)
#define CBUS_LINK_0D_get_retry_flag(data)                             ((0x00000010&(data))>>4)
#define CBUS_LINK_0D_get_ctrl_1f_resv(data)                           (0x0000000F&(data))

#define  CBUS_LINK_0E                                                           0x1800A238
#define  CBUS_LINK_0E_reg_addr                                                  "0xB800A238"
#define  CBUS_LINK_0E_reg                                                       0xB800A238
#define  CBUS_LINK_0E_inst_addr                                                 "0x005B"
#define  CBUS_LINK_0E_inst                                                      0x005B
#define CBUS_LINK_0E_drv_str_shift                                    (6)
#define CBUS_LINK_0E_drv_hi_cbus_shift                                (0)
#define CBUS_LINK_0E_drv_str_mask                                     (0x000000C0)
#define CBUS_LINK_0E_drv_hi_cbus_mask                                 (0x0000003F)
#define CBUS_LINK_0E_drv_str(data)                                    (0x000000C0&((data)<<6))
#define CBUS_LINK_0E_drv_hi_cbus(data)                                (0x0000003F&(data))
#define CBUS_LINK_0E_get_drv_str(data)                                ((0x000000C0&(data))>>6)
#define CBUS_LINK_0E_get_drv_hi_cbus(data)                            (0x0000003F&(data))

#define  CBUS_LINK_0F                                                           0x1800A23C
#define  CBUS_LINK_0F_reg_addr                                                  "0xB800A23C"
#define  CBUS_LINK_0F_reg                                                       0xB800A23C
#define  CBUS_LINK_0F_inst_addr                                                 "0x005C"
#define  CBUS_LINK_0F_inst                                                      0x005C
#define CBUS_LINK_0F_wait_shift                                       (2)
#define CBUS_LINK_0F_req_opp_int_shift                                (0)
#define CBUS_LINK_0F_wait_mask                                        (0x0000003C)
#define CBUS_LINK_0F_req_opp_int_mask                                 (0x00000003)
#define CBUS_LINK_0F_wait(data)                                       (0x0000003C&((data)<<2))
#define CBUS_LINK_0F_req_opp_int(data)                                (0x00000003&(data))
#define CBUS_LINK_0F_get_wait(data)                                   ((0x0000003C&(data))>>2)
#define CBUS_LINK_0F_get_req_opp_int(data)                            (0x00000003&(data))

#define  CBUS_LINK_10                                                           0x1800A240
#define  CBUS_LINK_10_reg_addr                                                  "0xB800A240"
#define  CBUS_LINK_10_reg                                                       0xB800A240
#define  CBUS_LINK_10_inst_addr                                                 "0x005D"
#define  CBUS_LINK_10_inst                                                      0x005D
#define CBUS_LINK_10_req_opp_flt_shift                                (0)
#define CBUS_LINK_10_req_opp_flt_mask                                 (0x000000FF)
#define CBUS_LINK_10_req_opp_flt(data)                                (0x000000FF&(data))
#define CBUS_LINK_10_get_req_opp_flt(data)                            (0x000000FF&(data))

#define  CBUS_LINK_11                                                           0x1800A244
#define  CBUS_LINK_11_reg_addr                                                  "0xB800A244"
#define  CBUS_LINK_11_reg                                                       0xB800A244
#define  CBUS_LINK_11_inst_addr                                                 "0x005E"
#define  CBUS_LINK_11_inst                                                      0x005E
#define CBUS_LINK_11_req_cont_shift                                   (0)
#define CBUS_LINK_11_req_cont_mask                                    (0x000000FF)
#define CBUS_LINK_11_req_cont(data)                                   (0x000000FF&(data))
#define CBUS_LINK_11_get_req_cont(data)                               (0x000000FF&(data))

#define  CBUS_LINK_12                                                           0x1800A248
#define  CBUS_LINK_12_reg_addr                                                  "0xB800A248"
#define  CBUS_LINK_12_reg                                                       0xB800A248
#define  CBUS_LINK_12_inst_addr                                                 "0x005F"
#define  CBUS_LINK_12_inst                                                      0x005F
#define CBUS_LINK_12_req_hold_shift                                   (4)
#define CBUS_LINK_12_resp_hold_shift                                  (0)
#define CBUS_LINK_12_req_hold_mask                                    (0x000000F0)
#define CBUS_LINK_12_resp_hold_mask                                   (0x0000000F)
#define CBUS_LINK_12_req_hold(data)                                   (0x000000F0&((data)<<4))
#define CBUS_LINK_12_resp_hold(data)                                  (0x0000000F&(data))
#define CBUS_LINK_12_get_req_hold(data)                               ((0x000000F0&(data))>>4)
#define CBUS_LINK_12_get_resp_hold(data)                              (0x0000000F&(data))

#define  CBUS_LINK_13                                                           0x1800A24C
#define  CBUS_LINK_13_reg_addr                                                  "0xB800A24C"
#define  CBUS_LINK_13_reg                                                       0xB800A24C
#define  CBUS_LINK_13_inst_addr                                                 "0x0060"
#define  CBUS_LINK_13_inst                                                      0x0060
#define CBUS_LINK_13_glob_time_shift                                  (6)
#define CBUS_LINK_13_link_time_shift                                  (1)
#define CBUS_LINK_13_link_err_shift                                   (0)
#define CBUS_LINK_13_glob_time_mask                                   (0x000000C0)
#define CBUS_LINK_13_link_time_mask                                   (0x0000003E)
#define CBUS_LINK_13_link_err_mask                                    (0x00000001)
#define CBUS_LINK_13_glob_time(data)                                  (0x000000C0&((data)<<6))
#define CBUS_LINK_13_link_time(data)                                  (0x0000003E&((data)<<1))
#define CBUS_LINK_13_link_err(data)                                   (0x00000001&(data))
#define CBUS_LINK_13_get_glob_time(data)                              ((0x000000C0&(data))>>6)
#define CBUS_LINK_13_get_link_time(data)                              ((0x0000003E&(data))>>1)
#define CBUS_LINK_13_get_link_err(data)                               (0x00000001&(data))

#define  CBUS_LINK_14                                                           0x1800A250
#define  CBUS_LINK_14_reg_addr                                                  "0xB800A250"
#define  CBUS_LINK_14_reg                                                       0xB800A250
#define  CBUS_LINK_14_inst_addr                                                 "0x0061"
#define  CBUS_LINK_14_inst                                                      0x0061
#define CBUS_LINK_14_chk_point_shift                                  (2)
#define CBUS_LINK_14_chk_err_shift                                    (1)
#define CBUS_LINK_14_avoid_conf_shift                                 (0)
#define CBUS_LINK_14_chk_point_mask                                   (0x000000FC)
#define CBUS_LINK_14_chk_err_mask                                     (0x00000002)
#define CBUS_LINK_14_avoid_conf_mask                                  (0x00000001)
#define CBUS_LINK_14_chk_point(data)                                  (0x000000FC&((data)<<2))
#define CBUS_LINK_14_chk_err(data)                                    (0x00000002&((data)<<1))
#define CBUS_LINK_14_avoid_conf(data)                                 (0x00000001&(data))
#define CBUS_LINK_14_get_chk_point(data)                              ((0x000000FC&(data))>>2)
#define CBUS_LINK_14_get_chk_err(data)                                ((0x00000002&(data))>>1)
#define CBUS_LINK_14_get_avoid_conf(data)                             (0x00000001&(data))

#define  CBUS_MSC_00                                                            0x1800A260
#define  CBUS_MSC_00_reg_addr                                                   "0xB800A260"
#define  CBUS_MSC_00_reg                                                        0xB800A260
#define  CBUS_MSC_00_inst_addr                                                  "0x0062"
#define  CBUS_MSC_00_inst                                                       0x0062
#define CBUS_MSC_00_mcumsc_en_shift                                   (5)
#define CBUS_MSC_00_msc_wait_arb_shift                                (4)
#define CBUS_MSC_00_ctrl_28_resv_shift                                (0)
#define CBUS_MSC_00_mcumsc_en_mask                                    (0x00000020)
#define CBUS_MSC_00_msc_wait_arb_mask                                 (0x00000010)
#define CBUS_MSC_00_ctrl_28_resv_mask                                 (0x0000000F)
#define CBUS_MSC_00_mcumsc_en(data)                                   (0x00000020&((data)<<5))
#define CBUS_MSC_00_msc_wait_arb(data)                                (0x00000010&((data)<<4))
#define CBUS_MSC_00_ctrl_28_resv(data)                                (0x0000000F&(data))
#define CBUS_MSC_00_get_mcumsc_en(data)                               ((0x00000020&(data))>>5)
#define CBUS_MSC_00_get_msc_wait_arb(data)                            ((0x00000010&(data))>>4)
#define CBUS_MSC_00_get_ctrl_28_resv(data)                            (0x0000000F&(data))

#define  CBUS_MSC_01                                                            0x1800A264
#define  CBUS_MSC_01_reg_addr                                                   "0xB800A264"
#define  CBUS_MSC_01_reg                                                        0xB800A264
#define  CBUS_MSC_01_inst_addr                                                  "0x0063"
#define  CBUS_MSC_01_inst                                                       0x0063
#define CBUS_MSC_01_na_msc_cmd_shift                                  (0)
#define CBUS_MSC_01_na_msc_cmd_mask                                   (0x000000FF)
#define CBUS_MSC_01_na_msc_cmd(data)                                  (0x000000FF&(data))
#define CBUS_MSC_01_get_na_msc_cmd(data)                              (0x000000FF&(data))

#define  CBUS_MSC_02                                                            0x1800A268
#define  CBUS_MSC_02_reg_addr                                                   "0xB800A268"
#define  CBUS_MSC_02_reg                                                        0xB800A268
#define  CBUS_MSC_02_inst_addr                                                  "0x0064"
#define  CBUS_MSC_02_inst                                                       0x0064
#define CBUS_MSC_02_na_msc_offset_shift                               (0)
#define CBUS_MSC_02_na_msc_offset_mask                                (0x000000FF)
#define CBUS_MSC_02_na_msc_offset(data)                               (0x000000FF&(data))
#define CBUS_MSC_02_get_na_msc_offset(data)                           (0x000000FF&(data))

#define  CBUS_MSC_03                                                            0x1800A26C
#define  CBUS_MSC_03_reg_addr                                                   "0xB800A26C"
#define  CBUS_MSC_03_reg                                                        0xB800A26C
#define  CBUS_MSC_03_inst_addr                                                  "0x0065"
#define  CBUS_MSC_03_inst                                                       0x0065
#define CBUS_MSC_03_rx_fifo_full_shift                                (7)
#define CBUS_MSC_03_rx_fifo_empty_shift                               (6)
#define CBUS_MSC_03_rx_fifo_clr_shift                                 (5)
#define CBUS_MSC_03_na_rx_len_shift                                   (0)
#define CBUS_MSC_03_rx_fifo_full_mask                                 (0x00000080)
#define CBUS_MSC_03_rx_fifo_empty_mask                                (0x00000040)
#define CBUS_MSC_03_rx_fifo_clr_mask                                  (0x00000020)
#define CBUS_MSC_03_na_rx_len_mask                                    (0x0000001F)
#define CBUS_MSC_03_rx_fifo_full(data)                                (0x00000080&((data)<<7))
#define CBUS_MSC_03_rx_fifo_empty(data)                               (0x00000040&((data)<<6))
#define CBUS_MSC_03_rx_fifo_clr(data)                                 (0x00000020&((data)<<5))
#define CBUS_MSC_03_na_rx_len(data)                                   (0x0000001F&(data))
#define CBUS_MSC_03_get_rx_fifo_full(data)                            ((0x00000080&(data))>>7)
#define CBUS_MSC_03_get_rx_fifo_empty(data)                           ((0x00000040&(data))>>6)
#define CBUS_MSC_03_get_rx_fifo_clr(data)                             ((0x00000020&(data))>>5)
#define CBUS_MSC_03_get_na_rx_len(data)                               (0x0000001F&(data))

#define  CBUS_MSC_04                                                            0x1800A270
#define  CBUS_MSC_04_reg_addr                                                   "0xB800A270"
#define  CBUS_MSC_04_reg                                                        0xB800A270
#define  CBUS_MSC_04_inst_addr                                                  "0x0066"
#define  CBUS_MSC_04_inst                                                       0x0066
#define CBUS_MSC_04_rx_fifo_data_shift                                (0)
#define CBUS_MSC_04_rx_fifo_data_mask                                 (0x000000FF)
#define CBUS_MSC_04_rx_fifo_data(data)                                (0x000000FF&(data))
#define CBUS_MSC_04_get_rx_fifo_data(data)                            (0x000000FF&(data))

#define  CBUS_MSC_05                                                            0x1800A274
#define  CBUS_MSC_05_reg_addr                                                   "0xB800A274"
#define  CBUS_MSC_05_reg                                                        0xB800A274
#define  CBUS_MSC_05_inst_addr                                                  "0x0067"
#define  CBUS_MSC_05_inst                                                       0x0067
#define CBUS_MSC_05_fwdef_cmd_rev_shift                               (0)
#define CBUS_MSC_05_fwdef_cmd_rev_mask                                (0x000000FF)
#define CBUS_MSC_05_fwdef_cmd_rev(data)                               (0x000000FF&(data))
#define CBUS_MSC_05_get_fwdef_cmd_rev(data)                           (0x000000FF&(data))

#define  CBUS_MSC_06                                                            0x1800A278
#define  CBUS_MSC_06_reg_addr                                                   "0xB800A278"
#define  CBUS_MSC_06_reg                                                        0xB800A278
#define  CBUS_MSC_06_inst_addr                                                  "0x0068"
#define  CBUS_MSC_06_inst                                                       0x0068
#define CBUS_MSC_06_ucp_irq_shift                                     (28)
#define CBUS_MSC_06_ucpk_irq_shift                                    (27)
#define CBUS_MSC_06_ucpe_irq_shift                                    (26)
#define CBUS_MSC_06_dcap_rdy_chg_shift                                (25)
#define CBUS_MSC_06_muted_chg_shift                                   (24)
#define CBUS_MSC_06_path_en_chg_shift                                 (23)
#define CBUS_MSC_06_clk_mode_chg_shift                                (22)
#define CBUS_MSC_06_msge_irq_shift                                    (21)
#define CBUS_MSC_06_rcp_irq_shift                                     (20)
#define CBUS_MSC_06_rcpk_irq_shift                                    (19)
#define CBUS_MSC_06_rcpe_irq_shift                                    (18)
#define CBUS_MSC_06_rap_irq_shift                                     (17)
#define CBUS_MSC_06_rapk_irq_shift                                    (16)
#define CBUS_MSC_06_msg_sub_irq_shift                                 (15)
#define CBUS_MSC_06_wr_stat_irq_shift                                 (14)
#define CBUS_MSC_06_rd_devcap_irq_shift                               (13)
#define CBUS_MSC_06_get_stat_irq_shift                                (12)
#define CBUS_MSC_06_get_id_irq_shift                                  (11)
#define CBUS_MSC_06_get_msg_irq_shift                                 (10)
#define CBUS_MSC_06_sc1_err_irq_shift                                 (9)
#define CBUS_MSC_06_ddc_err_irq_shift                                 (8)
#define CBUS_MSC_06_msc_err_irq_shift                                 (7)
#define CBUS_MSC_06_wr_burst_irq_shift                                (6)
#define CBUS_MSC_06_sc3_err_irq_shift                                 (5)
#define CBUS_MSC_06_fwdef_cmd_irq_shift                               (4)
#define CBUS_MSC_06_allmsc_cmd_irq_shift                              (3)
#define CBUS_MSC_06_abort_res_irq_shift                               (2)
#define CBUS_MSC_06_abort_req_irq_shift                               (1)
#define CBUS_MSC_06_ddc_abort_irq_shift                               (0)
#define CBUS_MSC_06_ucp_irq_mask                                      (0x10000000)
#define CBUS_MSC_06_ucpk_irq_mask                                     (0x08000000)
#define CBUS_MSC_06_ucpe_irq_mask                                     (0x04000000)
#define CBUS_MSC_06_dcap_rdy_chg_mask                                 (0x02000000)
#define CBUS_MSC_06_muted_chg_mask                                    (0x01000000)
#define CBUS_MSC_06_path_en_chg_mask                                  (0x00800000)
#define CBUS_MSC_06_clk_mode_chg_mask                                 (0x00400000)
#define CBUS_MSC_06_msge_irq_mask                                     (0x00200000)
#define CBUS_MSC_06_rcp_irq_mask                                      (0x00100000)
#define CBUS_MSC_06_rcpk_irq_mask                                     (0x00080000)
#define CBUS_MSC_06_rcpe_irq_mask                                     (0x00040000)
#define CBUS_MSC_06_rap_irq_mask                                      (0x00020000)
#define CBUS_MSC_06_rapk_irq_mask                                     (0x00010000)
#define CBUS_MSC_06_msg_sub_irq_mask                                  (0x00008000)
#define CBUS_MSC_06_wr_stat_irq_mask                                  (0x00004000)
#define CBUS_MSC_06_rd_devcap_irq_mask                                (0x00002000)
#define CBUS_MSC_06_get_stat_irq_mask                                 (0x00001000)
#define CBUS_MSC_06_get_id_irq_mask                                   (0x00000800)
#define CBUS_MSC_06_get_msg_irq_mask                                  (0x00000400)
#define CBUS_MSC_06_sc1_err_irq_mask                                  (0x00000200)
#define CBUS_MSC_06_ddc_err_irq_mask                                  (0x00000100)
#define CBUS_MSC_06_msc_err_irq_mask                                  (0x00000080)
#define CBUS_MSC_06_wr_burst_irq_mask                                 (0x00000040)
#define CBUS_MSC_06_sc3_err_irq_mask                                  (0x00000020)
#define CBUS_MSC_06_fwdef_cmd_irq_mask                                (0x00000010)
#define CBUS_MSC_06_allmsc_cmd_irq_mask                               (0x00000008)
#define CBUS_MSC_06_abort_res_irq_mask                                (0x00000004)
#define CBUS_MSC_06_abort_req_irq_mask                                (0x00000002)
#define CBUS_MSC_06_ddc_abort_irq_mask                                (0x00000001)
#define CBUS_MSC_06_ucp_irq(data)                                     (0x10000000&((data)<<28))
#define CBUS_MSC_06_ucpk_irq(data)                                    (0x08000000&((data)<<27))
#define CBUS_MSC_06_ucpe_irq(data)                                    (0x04000000&((data)<<26))
#define CBUS_MSC_06_dcap_rdy_chg(data)                                (0x02000000&((data)<<25))
#define CBUS_MSC_06_muted_chg(data)                                   (0x01000000&((data)<<24))
#define CBUS_MSC_06_path_en_chg(data)                                 (0x00800000&((data)<<23))
#define CBUS_MSC_06_clk_mode_chg(data)                                (0x00400000&((data)<<22))
#define CBUS_MSC_06_msge_irq(data)                                    (0x00200000&((data)<<21))
#define CBUS_MSC_06_rcp_irq(data)                                     (0x00100000&((data)<<20))
#define CBUS_MSC_06_rcpk_irq(data)                                    (0x00080000&((data)<<19))
#define CBUS_MSC_06_rcpe_irq(data)                                    (0x00040000&((data)<<18))
#define CBUS_MSC_06_rap_irq(data)                                     (0x00020000&((data)<<17))
#define CBUS_MSC_06_rapk_irq(data)                                    (0x00010000&((data)<<16))
#define CBUS_MSC_06_msg_sub_irq(data)                                 (0x00008000&((data)<<15))
#define CBUS_MSC_06_wr_stat_irq(data)                                 (0x00004000&((data)<<14))
#define CBUS_MSC_06_rd_devcap_irq(data)                               (0x00002000&((data)<<13))
#define CBUS_MSC_06_get_stat_irq(data)                                (0x00001000&((data)<<12))
#define CBUS_MSC_06_get_id_irq(data)                                  (0x00000800&((data)<<11))
#define CBUS_MSC_06_get_msg_irq(data)                                 (0x00000400&((data)<<10))
#define CBUS_MSC_06_sc1_err_irq(data)                                 (0x00000200&((data)<<9))
#define CBUS_MSC_06_ddc_err_irq(data)                                 (0x00000100&((data)<<8))
#define CBUS_MSC_06_msc_err_irq(data)                                 (0x00000080&((data)<<7))
#define CBUS_MSC_06_wr_burst_irq(data)                                (0x00000040&((data)<<6))
#define CBUS_MSC_06_sc3_err_irq(data)                                 (0x00000020&((data)<<5))
#define CBUS_MSC_06_fwdef_cmd_irq(data)                               (0x00000010&((data)<<4))
#define CBUS_MSC_06_allmsc_cmd_irq(data)                              (0x00000008&((data)<<3))
#define CBUS_MSC_06_abort_res_irq(data)                               (0x00000004&((data)<<2))
#define CBUS_MSC_06_abort_req_irq(data)                               (0x00000002&((data)<<1))
#define CBUS_MSC_06_ddc_abort_irq(data)                               (0x00000001&(data))
#define CBUS_MSC_06_get_ucp_irq(data)                                 ((0x10000000&(data))>>28)
#define CBUS_MSC_06_get_ucpk_irq(data)                                ((0x08000000&(data))>>27)
#define CBUS_MSC_06_get_ucpe_irq(data)                                ((0x04000000&(data))>>26)
#define CBUS_MSC_06_get_dcap_rdy_chg(data)                            ((0x02000000&(data))>>25)
#define CBUS_MSC_06_get_muted_chg(data)                               ((0x01000000&(data))>>24)
#define CBUS_MSC_06_get_path_en_chg(data)                             ((0x00800000&(data))>>23)
#define CBUS_MSC_06_get_clk_mode_chg(data)                            ((0x00400000&(data))>>22)
#define CBUS_MSC_06_get_msge_irq(data)                                ((0x00200000&(data))>>21)
#define CBUS_MSC_06_get_rcp_irq(data)                                 ((0x00100000&(data))>>20)
#define CBUS_MSC_06_get_rcpk_irq(data)                                ((0x00080000&(data))>>19)
#define CBUS_MSC_06_get_rcpe_irq(data)                                ((0x00040000&(data))>>18)
#define CBUS_MSC_06_get_rap_irq(data)                                 ((0x00020000&(data))>>17)
#define CBUS_MSC_06_get_rapk_irq(data)                                ((0x00010000&(data))>>16)
#define CBUS_MSC_06_get_msg_sub_irq(data)                             ((0x00008000&(data))>>15)
#define CBUS_MSC_06_get_wr_stat_irq(data)                             ((0x00004000&(data))>>14)
#define CBUS_MSC_06_get_rd_devcap_irq(data)                           ((0x00002000&(data))>>13)
#define CBUS_MSC_06_get_get_stat_irq(data)                            ((0x00001000&(data))>>12)
#define CBUS_MSC_06_get_get_id_irq(data)                              ((0x00000800&(data))>>11)
#define CBUS_MSC_06_get_get_msg_irq(data)                             ((0x00000400&(data))>>10)
#define CBUS_MSC_06_get_sc1_err_irq(data)                             ((0x00000200&(data))>>9)
#define CBUS_MSC_06_get_ddc_err_irq(data)                             ((0x00000100&(data))>>8)
#define CBUS_MSC_06_get_msc_err_irq(data)                             ((0x00000080&(data))>>7)
#define CBUS_MSC_06_get_wr_burst_irq(data)                            ((0x00000040&(data))>>6)
#define CBUS_MSC_06_get_sc3_err_irq(data)                             ((0x00000020&(data))>>5)
#define CBUS_MSC_06_get_fwdef_cmd_irq(data)                           ((0x00000010&(data))>>4)
#define CBUS_MSC_06_get_allmsc_cmd_irq(data)                          ((0x00000008&(data))>>3)
#define CBUS_MSC_06_get_abort_res_irq(data)                           ((0x00000004&(data))>>2)
#define CBUS_MSC_06_get_abort_req_irq(data)                           ((0x00000002&(data))>>1)
#define CBUS_MSC_06_get_ddc_abort_irq(data)                           (0x00000001&(data))

#define  CBUS_MSC_07                                                            0x1800A27C
#define  CBUS_MSC_07_reg_addr                                                   "0xB800A27C"
#define  CBUS_MSC_07_reg                                                        0xB800A27C
#define  CBUS_MSC_07_inst_addr                                                  "0x0069"
#define  CBUS_MSC_07_inst                                                       0x0069
#define CBUS_MSC_07_ucp_irq_en_shift                                  (28)
#define CBUS_MSC_07_ucpk_irq_en_shift                                 (27)
#define CBUS_MSC_07_ucpe_irq_en_shift                                 (26)
#define CBUS_MSC_07_dcap_rdy_irq_en_shift                             (25)
#define CBUS_MSC_07_muted_chg_irq_en_shift                            (24)
#define CBUS_MSC_07_path_en_irq_en_shift                              (23)
#define CBUS_MSC_07_clk_mode_irq_en_shift                             (22)
#define CBUS_MSC_07_msge_irq_en_shift                                 (21)
#define CBUS_MSC_07_rcp_irq_en_shift                                  (20)
#define CBUS_MSC_07_rcpk_irq_en_shift                                 (19)
#define CBUS_MSC_07_rcpe_irq_en_shift                                 (18)
#define CBUS_MSC_07_rap_irq_en_shift                                  (17)
#define CBUS_MSC_07_rapk_irq_en_shift                                 (16)
#define CBUS_MSC_07_msg_sub_irq_en_shift                              (15)
#define CBUS_MSC_07_wr_stat_irq_en_shift                              (14)
#define CBUS_MSC_07_rd_devcap_irq_en_shift                            (13)
#define CBUS_MSC_07_get_stat_irq_en_shift                             (12)
#define CBUS_MSC_07_get_id_irq_en_shift                               (11)
#define CBUS_MSC_07_get_msg_irq_en_shift                              (10)
#define CBUS_MSC_07_sc1_err_irq_en_shift                              (9)
#define CBUS_MSC_07_ddc_err_irq_en_shift                              (8)
#define CBUS_MSC_07_msc_err_irq_en_shift                              (7)
#define CBUS_MSC_07_wr_burst_irq_en_shift                             (6)
#define CBUS_MSC_07_sc3_err_irq_en_shift                              (5)
#define CBUS_MSC_07_fwdef_cmd_irq_en_shift                            (4)
#define CBUS_MSC_07_allmsc_cmd_irq_en_shift                           (3)
#define CBUS_MSC_07_abort_res_irq_en_shift                            (2)
#define CBUS_MSC_07_abort_req_irq_en_shift                            (1)
#define CBUS_MSC_07_ddc_abort_irq_en_shift                            (0)
#define CBUS_MSC_07_ucp_irq_en_mask                                   (0x10000000)
#define CBUS_MSC_07_ucpk_irq_en_mask                                  (0x08000000)
#define CBUS_MSC_07_ucpe_irq_en_mask                                  (0x04000000)
#define CBUS_MSC_07_dcap_rdy_irq_en_mask                              (0x02000000)
#define CBUS_MSC_07_muted_chg_irq_en_mask                             (0x01000000)
#define CBUS_MSC_07_path_en_irq_en_mask                               (0x00800000)
#define CBUS_MSC_07_clk_mode_irq_en_mask                              (0x00400000)
#define CBUS_MSC_07_msge_irq_en_mask                                  (0x00200000)
#define CBUS_MSC_07_rcp_irq_en_mask                                   (0x00100000)
#define CBUS_MSC_07_rcpk_irq_en_mask                                  (0x00080000)
#define CBUS_MSC_07_rcpe_irq_en_mask                                  (0x00040000)
#define CBUS_MSC_07_rap_irq_en_mask                                   (0x00020000)
#define CBUS_MSC_07_rapk_irq_en_mask                                  (0x00010000)
#define CBUS_MSC_07_msg_sub_irq_en_mask                               (0x00008000)
#define CBUS_MSC_07_wr_stat_irq_en_mask                               (0x00004000)
#define CBUS_MSC_07_rd_devcap_irq_en_mask                             (0x00002000)
#define CBUS_MSC_07_get_stat_irq_en_mask                              (0x00001000)
#define CBUS_MSC_07_get_id_irq_en_mask                                (0x00000800)
#define CBUS_MSC_07_get_msg_irq_en_mask                               (0x00000400)
#define CBUS_MSC_07_sc1_err_irq_en_mask                               (0x00000200)
#define CBUS_MSC_07_ddc_err_irq_en_mask                               (0x00000100)
#define CBUS_MSC_07_msc_err_irq_en_mask                               (0x00000080)
#define CBUS_MSC_07_wr_burst_irq_en_mask                              (0x00000040)
#define CBUS_MSC_07_sc3_err_irq_en_mask                               (0x00000020)
#define CBUS_MSC_07_fwdef_cmd_irq_en_mask                             (0x00000010)
#define CBUS_MSC_07_allmsc_cmd_irq_en_mask                            (0x00000008)
#define CBUS_MSC_07_abort_res_irq_en_mask                             (0x00000004)
#define CBUS_MSC_07_abort_req_irq_en_mask                             (0x00000002)
#define CBUS_MSC_07_ddc_abort_irq_en_mask                             (0x00000001)
#define CBUS_MSC_07_ucp_irq_en(data)                                  (0x10000000&((data)<<28))
#define CBUS_MSC_07_ucpk_irq_en(data)                                 (0x08000000&((data)<<27))
#define CBUS_MSC_07_ucpe_irq_en(data)                                 (0x04000000&((data)<<26))
#define CBUS_MSC_07_dcap_rdy_irq_en(data)                             (0x02000000&((data)<<25))
#define CBUS_MSC_07_muted_chg_irq_en(data)                            (0x01000000&((data)<<24))
#define CBUS_MSC_07_path_en_irq_en(data)                              (0x00800000&((data)<<23))
#define CBUS_MSC_07_clk_mode_irq_en(data)                             (0x00400000&((data)<<22))
#define CBUS_MSC_07_msge_irq_en(data)                                 (0x00200000&((data)<<21))
#define CBUS_MSC_07_rcp_irq_en(data)                                  (0x00100000&((data)<<20))
#define CBUS_MSC_07_rcpk_irq_en(data)                                 (0x00080000&((data)<<19))
#define CBUS_MSC_07_rcpe_irq_en(data)                                 (0x00040000&((data)<<18))
#define CBUS_MSC_07_rap_irq_en(data)                                  (0x00020000&((data)<<17))
#define CBUS_MSC_07_rapk_irq_en(data)                                 (0x00010000&((data)<<16))
#define CBUS_MSC_07_msg_sub_irq_en(data)                              (0x00008000&((data)<<15))
#define CBUS_MSC_07_wr_stat_irq_en(data)                              (0x00004000&((data)<<14))
#define CBUS_MSC_07_rd_devcap_irq_en(data)                            (0x00002000&((data)<<13))
#define CBUS_MSC_07_get_stat_irq_en(data)                             (0x00001000&((data)<<12))
#define CBUS_MSC_07_get_id_irq_en(data)                               (0x00000800&((data)<<11))
#define CBUS_MSC_07_get_msg_irq_en(data)                              (0x00000400&((data)<<10))
#define CBUS_MSC_07_sc1_err_irq_en(data)                              (0x00000200&((data)<<9))
#define CBUS_MSC_07_ddc_err_irq_en(data)                              (0x00000100&((data)<<8))
#define CBUS_MSC_07_msc_err_irq_en(data)                              (0x00000080&((data)<<7))
#define CBUS_MSC_07_wr_burst_irq_en(data)                             (0x00000040&((data)<<6))
#define CBUS_MSC_07_sc3_err_irq_en(data)                              (0x00000020&((data)<<5))
#define CBUS_MSC_07_fwdef_cmd_irq_en(data)                            (0x00000010&((data)<<4))
#define CBUS_MSC_07_allmsc_cmd_irq_en(data)                           (0x00000008&((data)<<3))
#define CBUS_MSC_07_abort_res_irq_en(data)                            (0x00000004&((data)<<2))
#define CBUS_MSC_07_abort_req_irq_en(data)                            (0x00000002&((data)<<1))
#define CBUS_MSC_07_ddc_abort_irq_en(data)                            (0x00000001&(data))
#define CBUS_MSC_07_get_ucp_irq_en(data)                              ((0x10000000&(data))>>28)
#define CBUS_MSC_07_get_ucpk_irq_en(data)                             ((0x08000000&(data))>>27)
#define CBUS_MSC_07_get_ucpe_irq_en(data)                             ((0x04000000&(data))>>26)
#define CBUS_MSC_07_get_dcap_rdy_irq_en(data)                         ((0x02000000&(data))>>25)
#define CBUS_MSC_07_get_muted_chg_irq_en(data)                        ((0x01000000&(data))>>24)
#define CBUS_MSC_07_get_path_en_irq_en(data)                          ((0x00800000&(data))>>23)
#define CBUS_MSC_07_get_clk_mode_irq_en(data)                         ((0x00400000&(data))>>22)
#define CBUS_MSC_07_get_msge_irq_en(data)                             ((0x00200000&(data))>>21)
#define CBUS_MSC_07_get_rcp_irq_en(data)                              ((0x00100000&(data))>>20)
#define CBUS_MSC_07_get_rcpk_irq_en(data)                             ((0x00080000&(data))>>19)
#define CBUS_MSC_07_get_rcpe_irq_en(data)                             ((0x00040000&(data))>>18)
#define CBUS_MSC_07_get_rap_irq_en(data)                              ((0x00020000&(data))>>17)
#define CBUS_MSC_07_get_rapk_irq_en(data)                             ((0x00010000&(data))>>16)
#define CBUS_MSC_07_get_msg_sub_irq_en(data)                          ((0x00008000&(data))>>15)
#define CBUS_MSC_07_get_wr_stat_irq_en(data)                          ((0x00004000&(data))>>14)
#define CBUS_MSC_07_get_rd_devcap_irq_en(data)                        ((0x00002000&(data))>>13)
#define CBUS_MSC_07_get_get_stat_irq_en(data)                         ((0x00001000&(data))>>12)
#define CBUS_MSC_07_get_get_id_irq_en(data)                           ((0x00000800&(data))>>11)
#define CBUS_MSC_07_get_get_msg_irq_en(data)                          ((0x00000400&(data))>>10)
#define CBUS_MSC_07_get_sc1_err_irq_en(data)                          ((0x00000200&(data))>>9)
#define CBUS_MSC_07_get_ddc_err_irq_en(data)                          ((0x00000100&(data))>>8)
#define CBUS_MSC_07_get_msc_err_irq_en(data)                          ((0x00000080&(data))>>7)
#define CBUS_MSC_07_get_wr_burst_irq_en(data)                         ((0x00000040&(data))>>6)
#define CBUS_MSC_07_get_sc3_err_irq_en(data)                          ((0x00000020&(data))>>5)
#define CBUS_MSC_07_get_fwdef_cmd_irq_en(data)                        ((0x00000010&(data))>>4)
#define CBUS_MSC_07_get_allmsc_cmd_irq_en(data)                       ((0x00000008&(data))>>3)
#define CBUS_MSC_07_get_abort_res_irq_en(data)                        ((0x00000004&(data))>>2)
#define CBUS_MSC_07_get_abort_req_irq_en(data)                        ((0x00000002&(data))>>1)
#define CBUS_MSC_07_get_ddc_abort_irq_en(data)                        (0x00000001&(data))

#define  CBUS_MSC_08                                                            0x1800A280
#define  CBUS_MSC_08_reg_addr                                                   "0xB800A280"
#define  CBUS_MSC_08_reg                                                        0xB800A280
#define  CBUS_MSC_08_inst_addr                                                  "0x006A"
#define  CBUS_MSC_08_inst                                                       0x006A
#define CBUS_MSC_08_rchg_irq_en_shift                                 (29)
#define CBUS_MSC_08_cbus_3d_req_irq_en_shift                          (28)
#define CBUS_MSC_08_grt_irq_en_shift                                  (27)
#define CBUS_MSC_08_req_irq_en_shift                                  (26)
#define CBUS_MSC_08_dscr_irq_en_shift                                 (25)
#define CBUS_MSC_08_dcap_irq_en_shift                                 (24)
#define CBUS_MSC_08_dchg_bit7_irq_en_shift                            (23)
#define CBUS_MSC_08_dchg_bit6_irq_en_shift                            (22)
#define CBUS_MSC_08_dchg_bit5_irq_en_shift                            (21)
#define CBUS_MSC_08_dchg_bit4_irq_en_shift                            (20)
#define CBUS_MSC_08_dchg_bit3_irq_en_shift                            (19)
#define CBUS_MSC_08_dchg_bit2_irq_en_shift                            (18)
#define CBUS_MSC_08_edid_irq_en_shift                                 (17)
#define CBUS_MSC_08_dchg_bit0_irq_en_shift                            (16)
#define CBUS_MSC_08_chg22_irq_en_shift                                (8)
#define CBUS_MSC_08_chg23_irq_en_shift                                (0)
#define CBUS_MSC_08_rchg_irq_en_mask                                  (0xE0000000)
#define CBUS_MSC_08_cbus_3d_req_irq_en_mask                           (0x10000000)
#define CBUS_MSC_08_grt_irq_en_mask                                   (0x08000000)
#define CBUS_MSC_08_req_irq_en_mask                                   (0x04000000)
#define CBUS_MSC_08_dscr_irq_en_mask                                  (0x02000000)
#define CBUS_MSC_08_dcap_irq_en_mask                                  (0x01000000)
#define CBUS_MSC_08_dchg_bit7_irq_en_mask                             (0x00800000)
#define CBUS_MSC_08_dchg_bit6_irq_en_mask                             (0x00400000)
#define CBUS_MSC_08_dchg_bit5_irq_en_mask                             (0x00200000)
#define CBUS_MSC_08_dchg_bit4_irq_en_mask                             (0x00100000)
#define CBUS_MSC_08_dchg_bit3_irq_en_mask                             (0x00080000)
#define CBUS_MSC_08_dchg_bit2_irq_en_mask                             (0x00040000)
#define CBUS_MSC_08_edid_irq_en_mask                                  (0x00020000)
#define CBUS_MSC_08_dchg_bit0_irq_en_mask                             (0x00010000)
#define CBUS_MSC_08_chg22_irq_en_mask                                 (0x0000FF00)
#define CBUS_MSC_08_chg23_irq_en_mask                                 (0x000000FF)
#define CBUS_MSC_08_rchg_irq_en(data)                                 (0xE0000000&((data)<<29))
#define CBUS_MSC_08_cbus_3d_req_irq_en(data)                          (0x10000000&((data)<<28))
#define CBUS_MSC_08_grt_irq_en(data)                                  (0x08000000&((data)<<27))
#define CBUS_MSC_08_req_irq_en(data)                                  (0x04000000&((data)<<26))
#define CBUS_MSC_08_dscr_irq_en(data)                                 (0x02000000&((data)<<25))
#define CBUS_MSC_08_dcap_irq_en(data)                                 (0x01000000&((data)<<24))
#define CBUS_MSC_08_dchg_bit7_irq_en(data)                            (0x00800000&((data)<<23))
#define CBUS_MSC_08_dchg_bit6_irq_en(data)                            (0x00400000&((data)<<22))
#define CBUS_MSC_08_dchg_bit5_irq_en(data)                            (0x00200000&((data)<<21))
#define CBUS_MSC_08_dchg_bit4_irq_en(data)                            (0x00100000&((data)<<20))
#define CBUS_MSC_08_dchg_bit3_irq_en(data)                            (0x00080000&((data)<<19))
#define CBUS_MSC_08_dchg_bit2_irq_en(data)                            (0x00040000&((data)<<18))
#define CBUS_MSC_08_edid_irq_en(data)                                 (0x00020000&((data)<<17))
#define CBUS_MSC_08_dchg_bit0_irq_en(data)                            (0x00010000&((data)<<16))
#define CBUS_MSC_08_chg22_irq_en(data)                                (0x0000FF00&((data)<<8))
#define CBUS_MSC_08_chg23_irq_en(data)                                (0x000000FF&(data))
#define CBUS_MSC_08_get_rchg_irq_en(data)                             ((0xE0000000&(data))>>29)
#define CBUS_MSC_08_get_cbus_3d_req_irq_en(data)                      ((0x10000000&(data))>>28)
#define CBUS_MSC_08_get_grt_irq_en(data)                              ((0x08000000&(data))>>27)
#define CBUS_MSC_08_get_req_irq_en(data)                              ((0x04000000&(data))>>26)
#define CBUS_MSC_08_get_dscr_irq_en(data)                             ((0x02000000&(data))>>25)
#define CBUS_MSC_08_get_dcap_irq_en(data)                             ((0x01000000&(data))>>24)
#define CBUS_MSC_08_get_dchg_bit7_irq_en(data)                        ((0x00800000&(data))>>23)
#define CBUS_MSC_08_get_dchg_bit6_irq_en(data)                        ((0x00400000&(data))>>22)
#define CBUS_MSC_08_get_dchg_bit5_irq_en(data)                        ((0x00200000&(data))>>21)
#define CBUS_MSC_08_get_dchg_bit4_irq_en(data)                        ((0x00100000&(data))>>20)
#define CBUS_MSC_08_get_dchg_bit3_irq_en(data)                        ((0x00080000&(data))>>19)
#define CBUS_MSC_08_get_dchg_bit2_irq_en(data)                        ((0x00040000&(data))>>18)
#define CBUS_MSC_08_get_edid_irq_en(data)                             ((0x00020000&(data))>>17)
#define CBUS_MSC_08_get_dchg_bit0_irq_en(data)                        ((0x00010000&(data))>>16)
#define CBUS_MSC_08_get_chg22_irq_en(data)                            ((0x0000FF00&(data))>>8)
#define CBUS_MSC_08_get_chg23_irq_en(data)                            (0x000000FF&(data))

#define  CBUS_MSC_09                                                            0x1800A284
#define  CBUS_MSC_09_reg_addr                                                   "0xB800A284"
#define  CBUS_MSC_09_reg                                                        0xB800A284
#define  CBUS_MSC_09_inst_addr                                                  "0x006B"
#define  CBUS_MSC_09_inst                                                       0x006B
#define CBUS_MSC_09_chg24_irq_en_shift                                (24)
#define CBUS_MSC_09_chg25_irq_en_shift                                (16)
#define CBUS_MSC_09_chg26_irq_en_shift                                (8)
#define CBUS_MSC_09_chg27_irq_en_shift                                (0)
#define CBUS_MSC_09_chg24_irq_en_mask                                 (0xFF000000)
#define CBUS_MSC_09_chg25_irq_en_mask                                 (0x00FF0000)
#define CBUS_MSC_09_chg26_irq_en_mask                                 (0x0000FF00)
#define CBUS_MSC_09_chg27_irq_en_mask                                 (0x000000FF)
#define CBUS_MSC_09_chg24_irq_en(data)                                (0xFF000000&((data)<<24))
#define CBUS_MSC_09_chg25_irq_en(data)                                (0x00FF0000&((data)<<16))
#define CBUS_MSC_09_chg26_irq_en(data)                                (0x0000FF00&((data)<<8))
#define CBUS_MSC_09_chg27_irq_en(data)                                (0x000000FF&(data))
#define CBUS_MSC_09_get_chg24_irq_en(data)                            ((0xFF000000&(data))>>24)
#define CBUS_MSC_09_get_chg25_irq_en(data)                            ((0x00FF0000&(data))>>16)
#define CBUS_MSC_09_get_chg26_irq_en(data)                            ((0x0000FF00&(data))>>8)
#define CBUS_MSC_09_get_chg27_irq_en(data)                            (0x000000FF&(data))

#define  CBUS_MSC_0A                                                            0x1800A288
#define  CBUS_MSC_0A_reg_addr                                                   "0xB800A288"
#define  CBUS_MSC_0A_reg                                                        0xB800A288
#define  CBUS_MSC_0A_inst_addr                                                  "0x006C"
#define  CBUS_MSC_0A_inst                                                       0x006C
#define CBUS_MSC_0A_msc_err_code_shift                                (0)
#define CBUS_MSC_0A_msc_err_code_mask                                 (0x000000FF)
#define CBUS_MSC_0A_msc_err_code(data)                                (0x000000FF&(data))
#define CBUS_MSC_0A_get_msc_err_code(data)                            (0x000000FF&(data))

#define  CBUS_MSC_0B                                                            0x1800A28C
#define  CBUS_MSC_0B_reg_addr                                                   "0xB800A28C"
#define  CBUS_MSC_0B_reg                                                        0xB800A28C
#define  CBUS_MSC_0B_inst_addr                                                  "0x006D"
#define  CBUS_MSC_0B_inst                                                       0x006D
#define CBUS_MSC_0B_rcp_reply_abort_shift                             (9)
#define CBUS_MSC_0B_rcp_reply_nack_shift                              (8)
#define CBUS_MSC_0B_vendor_id_shift                                   (0)
#define CBUS_MSC_0B_rcp_reply_abort_mask                              (0x00000200)
#define CBUS_MSC_0B_rcp_reply_nack_mask                               (0x00000100)
#define CBUS_MSC_0B_vendor_id_mask                                    (0x000000FF)
#define CBUS_MSC_0B_rcp_reply_abort(data)                             (0x00000200&((data)<<9))
#define CBUS_MSC_0B_rcp_reply_nack(data)                              (0x00000100&((data)<<8))
#define CBUS_MSC_0B_vendor_id(data)                                   (0x000000FF&(data))
#define CBUS_MSC_0B_get_rcp_reply_abort(data)                         ((0x00000200&(data))>>9)
#define CBUS_MSC_0B_get_rcp_reply_nack(data)                          ((0x00000100&(data))>>8)
#define CBUS_MSC_0B_get_vendor_id(data)                               (0x000000FF&(data))

#define  CBUS_MSC_0C                                                            0x1800A290
#define  CBUS_MSC_0C_reg_addr                                                   "0xB800A290"
#define  CBUS_MSC_0C_reg                                                        0xB800A290
#define  CBUS_MSC_0C_inst_addr                                                  "0x006E"
#define  CBUS_MSC_0C_inst                                                       0x006E
#define CBUS_MSC_0C_msg_cmd_shift                                     (0)
#define CBUS_MSC_0C_msg_cmd_mask                                      (0x000000FF)
#define CBUS_MSC_0C_msg_cmd(data)                                     (0x000000FF&(data))
#define CBUS_MSC_0C_get_msg_cmd(data)                                 (0x000000FF&(data))

#define  CBUS_MSC_0D                                                            0x1800A294
#define  CBUS_MSC_0D_reg_addr                                                   "0xB800A294"
#define  CBUS_MSC_0D_reg                                                        0xB800A294
#define  CBUS_MSC_0D_inst_addr                                                  "0x006F"
#define  CBUS_MSC_0D_inst                                                       0x006F
#define CBUS_MSC_0D_msg_dat_shift                                     (0)
#define CBUS_MSC_0D_msg_dat_mask                                      (0x000000FF)
#define CBUS_MSC_0D_msg_dat(data)                                     (0x000000FF&(data))
#define CBUS_MSC_0D_get_msg_dat(data)                                 (0x000000FF&(data))

#define  CBUS_MSC_0E                                                            0x1800A298
#define  CBUS_MSC_0E_reg_addr                                                   "0xB800A298"
#define  CBUS_MSC_0E_reg                                                        0xB800A298
#define  CBUS_MSC_0E_inst_addr                                                  "0x0070"
#define  CBUS_MSC_0E_inst                                                       0x0070
#define CBUS_MSC_0E_msge_rcv_shift                                    (0)
#define CBUS_MSC_0E_msge_rcv_mask                                     (0x000000FF)
#define CBUS_MSC_0E_msge_rcv(data)                                    (0x000000FF&(data))
#define CBUS_MSC_0E_get_msge_rcv(data)                                (0x000000FF&(data))

#define  CBUS_MSC_0F                                                            0x1800A29C
#define  CBUS_MSC_0F_reg_addr                                                   "0xB800A29C"
#define  CBUS_MSC_0F_reg                                                        0xB800A29C
#define  CBUS_MSC_0F_inst_addr                                                  "0x0071"
#define  CBUS_MSC_0F_inst                                                       0x0071
#define CBUS_MSC_0F_rcp_rcv_shift                                     (0)
#define CBUS_MSC_0F_rcp_rcv_mask                                      (0x000000FF)
#define CBUS_MSC_0F_rcp_rcv(data)                                     (0x000000FF&(data))
#define CBUS_MSC_0F_get_rcp_rcv(data)                                 (0x000000FF&(data))

#define  CBUS_MSC_10                                                            0x1800A2A0
#define  CBUS_MSC_10_reg_addr                                                   "0xB800A2A0"
#define  CBUS_MSC_10_reg                                                        0xB800A2A0
#define  CBUS_MSC_10_inst_addr                                                  "0x0072"
#define  CBUS_MSC_10_inst                                                       0x0072
#define CBUS_MSC_10_rcpk_rcv_shift                                    (0)
#define CBUS_MSC_10_rcpk_rcv_mask                                     (0x000000FF)
#define CBUS_MSC_10_rcpk_rcv(data)                                    (0x000000FF&(data))
#define CBUS_MSC_10_get_rcpk_rcv(data)                                (0x000000FF&(data))

#define  CBUS_MSC_11                                                            0x1800A2A4
#define  CBUS_MSC_11_reg_addr                                                   "0xB800A2A4"
#define  CBUS_MSC_11_reg                                                        0xB800A2A4
#define  CBUS_MSC_11_inst_addr                                                  "0x0073"
#define  CBUS_MSC_11_inst                                                       0x0073
#define CBUS_MSC_11_rcpe_rcv_shift                                    (0)
#define CBUS_MSC_11_rcpe_rcv_mask                                     (0x000000FF)
#define CBUS_MSC_11_rcpe_rcv(data)                                    (0x000000FF&(data))
#define CBUS_MSC_11_get_rcpe_rcv(data)                                (0x000000FF&(data))

#define  CBUS_MSC_12                                                            0x1800A2A8
#define  CBUS_MSC_12_reg_addr                                                   "0xB800A2A8"
#define  CBUS_MSC_12_reg                                                        0xB800A2A8
#define  CBUS_MSC_12_inst_addr                                                  "0x0074"
#define  CBUS_MSC_12_inst                                                       0x0074
#define CBUS_MSC_12_rap_rcv_shift                                     (0)
#define CBUS_MSC_12_rap_rcv_mask                                      (0x000000FF)
#define CBUS_MSC_12_rap_rcv(data)                                     (0x000000FF&(data))
#define CBUS_MSC_12_get_rap_rcv(data)                                 (0x000000FF&(data))

#define  CBUS_MSC_13                                                            0x1800A2AC
#define  CBUS_MSC_13_reg_addr                                                   "0xB800A2AC"
#define  CBUS_MSC_13_reg                                                        0xB800A2AC
#define  CBUS_MSC_13_inst_addr                                                  "0x0075"
#define  CBUS_MSC_13_inst                                                       0x0075
#define CBUS_MSC_13_rapk_rcv_shift                                    (0)
#define CBUS_MSC_13_rapk_rcv_mask                                     (0x000000FF)
#define CBUS_MSC_13_rapk_rcv(data)                                    (0x000000FF&(data))
#define CBUS_MSC_13_get_rapk_rcv(data)                                (0x000000FF&(data))

#define  CBUS_MSC_14                                                            0x1800A2B0
#define  CBUS_MSC_14_reg_addr                                                   "0xB800A2B0"
#define  CBUS_MSC_14_reg                                                        0xB800A2B0
#define  CBUS_MSC_14_inst_addr                                                  "0x0076"
#define  CBUS_MSC_14_inst                                                       0x0076
#define CBUS_MSC_14_burst_timeout_shift                               (5)
#define CBUS_MSC_14_wb_id_chk_shift                                   (4)
#define CBUS_MSC_14_burst_wait_shift                                  (0)
#define CBUS_MSC_14_burst_timeout_mask                                (0x00000020)
#define CBUS_MSC_14_wb_id_chk_mask                                    (0x00000010)
#define CBUS_MSC_14_burst_wait_mask                                   (0x0000000F)
#define CBUS_MSC_14_burst_timeout(data)                               (0x00000020&((data)<<5))
#define CBUS_MSC_14_wb_id_chk(data)                                   (0x00000010&((data)<<4))
#define CBUS_MSC_14_burst_wait(data)                                  (0x0000000F&(data))
#define CBUS_MSC_14_get_burst_timeout(data)                           ((0x00000020&(data))>>5)
#define CBUS_MSC_14_get_wb_id_chk(data)                               ((0x00000010&(data))>>4)
#define CBUS_MSC_14_get_burst_wait(data)                              (0x0000000F&(data))

#define  CBUS_MSC_15                                                            0x1800A2B4
#define  CBUS_MSC_15_reg_addr                                                   "0xB800A2B4"
#define  CBUS_MSC_15_reg                                                        0xB800A2B4
#define  CBUS_MSC_15_inst_addr                                                  "0x0077"
#define  CBUS_MSC_15_inst                                                       0x0077
#define CBUS_MSC_15_adop_idh_rcv_shift                                (8)
#define CBUS_MSC_15_adop_idl_rcv_shift                                (0)
#define CBUS_MSC_15_adop_idh_rcv_mask                                 (0x0000FF00)
#define CBUS_MSC_15_adop_idl_rcv_mask                                 (0x000000FF)
#define CBUS_MSC_15_adop_idh_rcv(data)                                (0x0000FF00&((data)<<8))
#define CBUS_MSC_15_adop_idl_rcv(data)                                (0x000000FF&(data))
#define CBUS_MSC_15_get_adop_idh_rcv(data)                            ((0x0000FF00&(data))>>8)
#define CBUS_MSC_15_get_adop_idl_rcv(data)                            (0x000000FF&(data))

#define  CBUS_MSC_16                                                            0x1800A2B8
#define  CBUS_MSC_16_reg_addr                                                   "0xB800A2B8"
#define  CBUS_MSC_16_reg                                                        0xB800A2B8
#define  CBUS_MSC_16_inst_addr                                                  "0x0078"
#define  CBUS_MSC_16_inst                                                       0x0078
#define CBUS_MSC_16_auto_handshake_shift                              (29)
#define CBUS_MSC_16_insert_id_shift                                   (28)
#define CBUS_MSC_16_wb_byte_num0_shift                                (22)
#define CBUS_MSC_16_wb_byte_num1_shift                                (16)
#define CBUS_MSC_16_adop_txid_h_shift                                 (8)
#define CBUS_MSC_16_adop_txid_l_shift                                 (0)
#define CBUS_MSC_16_auto_handshake_mask                               (0x20000000)
#define CBUS_MSC_16_insert_id_mask                                    (0x10000000)
#define CBUS_MSC_16_wb_byte_num0_mask                                 (0x0FC00000)
#define CBUS_MSC_16_wb_byte_num1_mask                                 (0x003F0000)
#define CBUS_MSC_16_adop_txid_h_mask                                  (0x0000FF00)
#define CBUS_MSC_16_adop_txid_l_mask                                  (0x000000FF)
#define CBUS_MSC_16_auto_handshake(data)                              (0x20000000&((data)<<29))
#define CBUS_MSC_16_insert_id(data)                                   (0x10000000&((data)<<28))
#define CBUS_MSC_16_wb_byte_num0(data)                                (0x0FC00000&((data)<<22))
#define CBUS_MSC_16_wb_byte_num1(data)                                (0x003F0000&((data)<<16))
#define CBUS_MSC_16_adop_txid_h(data)                                 (0x0000FF00&((data)<<8))
#define CBUS_MSC_16_adop_txid_l(data)                                 (0x000000FF&(data))
#define CBUS_MSC_16_get_auto_handshake(data)                          ((0x20000000&(data))>>29)
#define CBUS_MSC_16_get_insert_id(data)                               ((0x10000000&(data))>>28)
#define CBUS_MSC_16_get_wb_byte_num0(data)                            ((0x0FC00000&(data))>>22)
#define CBUS_MSC_16_get_wb_byte_num1(data)                            ((0x003F0000&(data))>>16)
#define CBUS_MSC_16_get_adop_txid_h(data)                             ((0x0000FF00&(data))>>8)
#define CBUS_MSC_16_get_adop_txid_l(data)                             (0x000000FF&(data))

#define  CBUS_MSC_17                                                            0x1800A2BC
#define  CBUS_MSC_17_reg_addr                                                   "0xB800A2BC"
#define  CBUS_MSC_17_reg                                                        0xB800A2BC
#define  CBUS_MSC_17_inst_addr                                                  "0x0079"
#define  CBUS_MSC_17_inst                                                       0x0079
#define CBUS_MSC_17_que_fsm_clr_shift                                 (2)
#define CBUS_MSC_17_sch_fsm_clr_shift                                 (1)
#define CBUS_MSC_17_spi_fsm_clr_shift                                 (0)
#define CBUS_MSC_17_que_fsm_clr_mask                                  (0x00000004)
#define CBUS_MSC_17_sch_fsm_clr_mask                                  (0x00000002)
#define CBUS_MSC_17_spi_fsm_clr_mask                                  (0x00000001)
#define CBUS_MSC_17_que_fsm_clr(data)                                 (0x00000004&((data)<<2))
#define CBUS_MSC_17_sch_fsm_clr(data)                                 (0x00000002&((data)<<1))
#define CBUS_MSC_17_spi_fsm_clr(data)                                 (0x00000001&(data))
#define CBUS_MSC_17_get_que_fsm_clr(data)                             ((0x00000004&(data))>>2)
#define CBUS_MSC_17_get_sch_fsm_clr(data)                             ((0x00000002&(data))>>1)
#define CBUS_MSC_17_get_spi_fsm_clr(data)                             (0x00000001&(data))

#define  CBUS_MSC_18                                                            0x1800A2C0
#define  CBUS_MSC_18_reg_addr                                                   "0xB800A2C0"
#define  CBUS_MSC_18_reg                                                        0xB800A2C0
#define  CBUS_MSC_18_inst_addr                                                  "0x007A"
#define  CBUS_MSC_18_inst                                                       0x007A
#define CBUS_MSC_18_que_fsm_shift                                     (8)
#define CBUS_MSC_18_sch_fsm_shift                                     (4)
#define CBUS_MSC_18_spi_fsm_shift                                     (0)
#define CBUS_MSC_18_que_fsm_mask                                      (0x00000F00)
#define CBUS_MSC_18_sch_fsm_mask                                      (0x000000F0)
#define CBUS_MSC_18_spi_fsm_mask                                      (0x0000000F)
#define CBUS_MSC_18_que_fsm(data)                                     (0x00000F00&((data)<<8))
#define CBUS_MSC_18_sch_fsm(data)                                     (0x000000F0&((data)<<4))
#define CBUS_MSC_18_spi_fsm(data)                                     (0x0000000F&(data))
#define CBUS_MSC_18_get_que_fsm(data)                                 ((0x00000F00&(data))>>8)
#define CBUS_MSC_18_get_sch_fsm(data)                                 ((0x000000F0&(data))>>4)
#define CBUS_MSC_18_get_spi_fsm(data)                                 (0x0000000F&(data))

#define  CBUS_MSC_19                                                            0x1800A2C4
#define  CBUS_MSC_19_reg_addr                                                   "0xB800A2C4"
#define  CBUS_MSC_19_reg                                                        0xB800A2C4
#define  CBUS_MSC_19_inst_addr                                                  "0x007B"
#define  CBUS_MSC_19_inst                                                       0x007B
#define CBUS_MSC_19_cap_offset_shift                                  (0)
#define CBUS_MSC_19_cap_offset_mask                                   (0x000000FF)
#define CBUS_MSC_19_cap_offset(data)                                  (0x000000FF&(data))
#define CBUS_MSC_19_get_cap_offset(data)                              (0x000000FF&(data))

#define  CBUS_MSC_1A                                                            0x1800A2C8
#define  CBUS_MSC_1A_reg_addr                                                   "0xB800A2C8"
#define  CBUS_MSC_1A_reg                                                        0xB800A2C8
#define  CBUS_MSC_1A_inst_addr                                                  "0x007C"
#define  CBUS_MSC_1A_inst                                                       0x007C
#define CBUS_MSC_1A_int_offset_shift                                  (0)
#define CBUS_MSC_1A_int_offset_mask                                   (0x000000FF)
#define CBUS_MSC_1A_int_offset(data)                                  (0x000000FF&(data))
#define CBUS_MSC_1A_get_int_offset(data)                              (0x000000FF&(data))

#define  CBUS_MSC_1B                                                            0x1800A2CC
#define  CBUS_MSC_1B_reg_addr                                                   "0xB800A2CC"
#define  CBUS_MSC_1B_reg                                                        0xB800A2CC
#define  CBUS_MSC_1B_inst_addr                                                  "0x007D"
#define  CBUS_MSC_1B_inst                                                       0x007D
#define CBUS_MSC_1B_sta_offset_shift                                  (0)
#define CBUS_MSC_1B_sta_offset_mask                                   (0x000000FF)
#define CBUS_MSC_1B_sta_offset(data)                                  (0x000000FF&(data))
#define CBUS_MSC_1B_get_sta_offset(data)                              (0x000000FF&(data))

#define  CBUS_MSC_1C                                                            0x1800A2D0
#define  CBUS_MSC_1C_reg_addr                                                   "0xB800A2D0"
#define  CBUS_MSC_1C_reg                                                        0xB800A2D0
#define  CBUS_MSC_1C_inst_addr                                                  "0x007E"
#define  CBUS_MSC_1C_inst                                                       0x007E
#define CBUS_MSC_1C_scr_offset_shift                                  (0)
#define CBUS_MSC_1C_scr_offset_mask                                   (0x000000FF)
#define CBUS_MSC_1C_scr_offset(data)                                  (0x000000FF&(data))
#define CBUS_MSC_1C_get_scr_offset(data)                              (0x000000FF&(data))

#define  CBUS_MSC_1D                                                            0x1800A2D4
#define  CBUS_MSC_1D_reg_addr                                                   "0xB800A2D4"
#define  CBUS_MSC_1D_reg                                                        0xB800A2D4
#define  CBUS_MSC_1D_inst_addr                                                  "0x007F"
#define  CBUS_MSC_1D_inst                                                       0x007F
#define CBUS_MSC_1D_ddc_err_force_shift                               (1)
#define CBUS_MSC_1D_msc_err_force_shift                               (0)
#define CBUS_MSC_1D_ddc_err_force_mask                                (0x00000002)
#define CBUS_MSC_1D_msc_err_force_mask                                (0x00000001)
#define CBUS_MSC_1D_ddc_err_force(data)                               (0x00000002&((data)<<1))
#define CBUS_MSC_1D_msc_err_force(data)                               (0x00000001&(data))
#define CBUS_MSC_1D_get_ddc_err_force(data)                           ((0x00000002&(data))>>1)
#define CBUS_MSC_1D_get_msc_err_force(data)                           (0x00000001&(data))

#define  CBUS_MSC_1E                                                            0x1800A2D8
#define  CBUS_MSC_1E_reg_addr                                                   "0xB800A2D8"
#define  CBUS_MSC_1E_reg                                                        0xB800A2D8
#define  CBUS_MSC_1E_inst_addr                                                  "0x0080"
#define  CBUS_MSC_1E_inst                                                       0x0080
#define CBUS_MSC_1E_ddc_err_fw_shift                                  (0)
#define CBUS_MSC_1E_ddc_err_fw_mask                                   (0x000000FF)
#define CBUS_MSC_1E_ddc_err_fw(data)                                  (0x000000FF&(data))
#define CBUS_MSC_1E_get_ddc_err_fw(data)                              (0x000000FF&(data))

#define  CBUS_MSC_1F                                                            0x1800A2DC
#define  CBUS_MSC_1F_reg_addr                                                   "0xB800A2DC"
#define  CBUS_MSC_1F_reg                                                        0xB800A2DC
#define  CBUS_MSC_1F_inst_addr                                                  "0x0081"
#define  CBUS_MSC_1F_inst                                                       0x0081
#define CBUS_MSC_1F_msc_err_fw_shift                                  (0)
#define CBUS_MSC_1F_msc_err_fw_mask                                   (0x000000FF)
#define CBUS_MSC_1F_msc_err_fw(data)                                  (0x000000FF&(data))
#define CBUS_MSC_1F_get_msc_err_fw(data)                              (0x000000FF&(data))

#define  CBUS_MSC_20                                                            0x1800A2E0
#define  CBUS_MSC_20_reg_addr                                                   "0xB800A2E0"
#define  CBUS_MSC_20_reg                                                        0xB800A2E0
#define  CBUS_MSC_20_inst_addr                                                  "0x0082"
#define  CBUS_MSC_20_inst                                                       0x0082
#define CBUS_MSC_20_ucp_rcv_shift                                     (0)
#define CBUS_MSC_20_ucp_rcv_mask                                      (0x000000FF)
#define CBUS_MSC_20_ucp_rcv(data)                                     (0x000000FF&(data))
#define CBUS_MSC_20_get_ucp_rcv(data)                                 (0x000000FF&(data))

#define  CBUS_MSC_21                                                            0x1800A2E4
#define  CBUS_MSC_21_reg_addr                                                   "0xB800A2E4"
#define  CBUS_MSC_21_reg                                                        0xB800A2E4
#define  CBUS_MSC_21_inst_addr                                                  "0x0083"
#define  CBUS_MSC_21_inst                                                       0x0083
#define CBUS_MSC_21_ucpk_rcv_shift                                    (0)
#define CBUS_MSC_21_ucpk_rcv_mask                                     (0x000000FF)
#define CBUS_MSC_21_ucpk_rcv(data)                                    (0x000000FF&(data))
#define CBUS_MSC_21_get_ucpk_rcv(data)                                (0x000000FF&(data))

#define  CBUS_MSC_22                                                            0x1800A2E8
#define  CBUS_MSC_22_reg_addr                                                   "0xB800A2E8"
#define  CBUS_MSC_22_reg                                                        0xB800A2E8
#define  CBUS_MSC_22_inst_addr                                                  "0x0084"
#define  CBUS_MSC_22_inst                                                       0x0084
#define CBUS_MSC_22_ucpe_rcv_shift                                    (0)
#define CBUS_MSC_22_ucpe_rcv_mask                                     (0x000000FF)
#define CBUS_MSC_22_ucpe_rcv(data)                                    (0x000000FF&(data))
#define CBUS_MSC_22_get_ucpe_rcv(data)                                (0x000000FF&(data))

#define  FW0_REQ_00                                                             0x1800A300
#define  FW0_REQ_00_reg_addr                                                    "0xB800A300"
#define  FW0_REQ_00_reg                                                         0xB800A300
#define  FW0_REQ_00_inst_addr                                                   "0x0085"
#define  FW0_REQ_00_inst                                                        0x0085
#define FW0_REQ_00_fw0_req_shift                                      (8)
#define FW0_REQ_00_fw0_fifo_clr_shift                                 (7)
#define FW0_REQ_00_fw0_fifo_full_shift                                (6)
#define FW0_REQ_00_fw0_fifo_empty_shift                               (5)
#define FW0_REQ_00_fw0_tx_case_shift                                  (2)
#define FW0_REQ_00_fw0_head_shift                                     (0)
#define FW0_REQ_00_fw0_req_mask                                       (0x00000100)
#define FW0_REQ_00_fw0_fifo_clr_mask                                  (0x00000080)
#define FW0_REQ_00_fw0_fifo_full_mask                                 (0x00000040)
#define FW0_REQ_00_fw0_fifo_empty_mask                                (0x00000020)
#define FW0_REQ_00_fw0_tx_case_mask                                   (0x0000001C)
#define FW0_REQ_00_fw0_head_mask                                      (0x00000003)
#define FW0_REQ_00_fw0_req(data)                                      (0x00000100&((data)<<8))
#define FW0_REQ_00_fw0_fifo_clr(data)                                 (0x00000080&((data)<<7))
#define FW0_REQ_00_fw0_fifo_full(data)                                (0x00000040&((data)<<6))
#define FW0_REQ_00_fw0_fifo_empty(data)                               (0x00000020&((data)<<5))
#define FW0_REQ_00_fw0_tx_case(data)                                  (0x0000001C&((data)<<2))
#define FW0_REQ_00_fw0_head(data)                                     (0x00000003&(data))
#define FW0_REQ_00_get_fw0_req(data)                                  ((0x00000100&(data))>>8)
#define FW0_REQ_00_get_fw0_fifo_clr(data)                             ((0x00000080&(data))>>7)
#define FW0_REQ_00_get_fw0_fifo_full(data)                            ((0x00000040&(data))>>6)
#define FW0_REQ_00_get_fw0_fifo_empty(data)                           ((0x00000020&(data))>>5)
#define FW0_REQ_00_get_fw0_tx_case(data)                              ((0x0000001C&(data))>>2)
#define FW0_REQ_00_get_fw0_head(data)                                 (0x00000003&(data))

#define  FW0_REQ_01                                                             0x1800A304
#define  FW0_REQ_01_reg_addr                                                    "0xB800A304"
#define  FW0_REQ_01_reg                                                         0xB800A304
#define  FW0_REQ_01_inst_addr                                                   "0x0086"
#define  FW0_REQ_01_inst                                                        0x0086
#define FW0_REQ_01_fw0_cmd1_shift                                     (0)
#define FW0_REQ_01_fw0_cmd1_mask                                      (0x000000FF)
#define FW0_REQ_01_fw0_cmd1(data)                                     (0x000000FF&(data))
#define FW0_REQ_01_get_fw0_cmd1(data)                                 (0x000000FF&(data))

#define  FW0_REQ_02                                                             0x1800A308
#define  FW0_REQ_02_reg_addr                                                    "0xB800A308"
#define  FW0_REQ_02_reg                                                         0xB800A308
#define  FW0_REQ_02_inst_addr                                                   "0x0087"
#define  FW0_REQ_02_inst                                                        0x0087
#define FW0_REQ_02_fw0_cmd2_shift                                     (0)
#define FW0_REQ_02_fw0_cmd2_mask                                      (0x000000FF)
#define FW0_REQ_02_fw0_cmd2(data)                                     (0x000000FF&(data))
#define FW0_REQ_02_get_fw0_cmd2(data)                                 (0x000000FF&(data))

#define  FW0_REQ_03                                                             0x1800A30C
#define  FW0_REQ_03_reg_addr                                                    "0xB800A30C"
#define  FW0_REQ_03_reg                                                         0xB800A30C
#define  FW0_REQ_03_inst_addr                                                   "0x0088"
#define  FW0_REQ_03_inst                                                        0x0088
#define FW0_REQ_03_fw0_offset_shift                                   (0)
#define FW0_REQ_03_fw0_offset_mask                                    (0x000000FF)
#define FW0_REQ_03_fw0_offset(data)                                   (0x000000FF&(data))
#define FW0_REQ_03_get_fw0_offset(data)                               (0x000000FF&(data))

#define  FW0_REQ_04                                                             0x1800A310
#define  FW0_REQ_04_reg_addr                                                    "0xB800A310"
#define  FW0_REQ_04_reg                                                         0xB800A310
#define  FW0_REQ_04_inst_addr                                                   "0x0089"
#define  FW0_REQ_04_inst                                                        0x0089
#define FW0_REQ_04_fw0_data_shift                                     (0)
#define FW0_REQ_04_fw0_data_mask                                      (0x000000FF)
#define FW0_REQ_04_fw0_data(data)                                     (0x000000FF&(data))
#define FW0_REQ_04_get_fw0_data(data)                                 (0x000000FF&(data))

#define  FW0_REQ_05                                                             0x1800A314
#define  FW0_REQ_05_reg_addr                                                    "0xB800A314"
#define  FW0_REQ_05_reg                                                         0xB800A314
#define  FW0_REQ_05_inst_addr                                                   "0x008A"
#define  FW0_REQ_05_inst                                                        0x008A
#define FW0_REQ_05_fw0_rty_ovr_shift                                  (9)
#define FW0_REQ_05_fw0_fin_shift                                      (8)
#define FW0_REQ_05_fw0_cmd_event_shift                                (7)
#define FW0_REQ_05_fw0_data_event_shift                               (6)
#define FW0_REQ_05_fw0_rcv_err_shift                                  (5)
#define FW0_REQ_05_fw0_fin_irq_en_shift                               (4)
#define FW0_REQ_05_fw0_cmd_irq_en_shift                               (3)
#define FW0_REQ_05_fw0_data_irq_en_shift                              (2)
#define FW0_REQ_05_fw0_wait_case_shift                                (0)
#define FW0_REQ_05_fw0_rty_ovr_mask                                   (0x00000200)
#define FW0_REQ_05_fw0_fin_mask                                       (0x00000100)
#define FW0_REQ_05_fw0_cmd_event_mask                                 (0x00000080)
#define FW0_REQ_05_fw0_data_event_mask                                (0x00000040)
#define FW0_REQ_05_fw0_rcv_err_mask                                   (0x00000020)
#define FW0_REQ_05_fw0_fin_irq_en_mask                                (0x00000010)
#define FW0_REQ_05_fw0_cmd_irq_en_mask                                (0x00000008)
#define FW0_REQ_05_fw0_data_irq_en_mask                               (0x00000004)
#define FW0_REQ_05_fw0_wait_case_mask                                 (0x00000003)
#define FW0_REQ_05_fw0_rty_ovr(data)                                  (0x00000200&((data)<<9))
#define FW0_REQ_05_fw0_fin(data)                                      (0x00000100&((data)<<8))
#define FW0_REQ_05_fw0_cmd_event(data)                                (0x00000080&((data)<<7))
#define FW0_REQ_05_fw0_data_event(data)                               (0x00000040&((data)<<6))
#define FW0_REQ_05_fw0_rcv_err(data)                                  (0x00000020&((data)<<5))
#define FW0_REQ_05_fw0_fin_irq_en(data)                               (0x00000010&((data)<<4))
#define FW0_REQ_05_fw0_cmd_irq_en(data)                               (0x00000008&((data)<<3))
#define FW0_REQ_05_fw0_data_irq_en(data)                              (0x00000004&((data)<<2))
#define FW0_REQ_05_fw0_wait_case(data)                                (0x00000003&(data))
#define FW0_REQ_05_get_fw0_rty_ovr(data)                              ((0x00000200&(data))>>9)
#define FW0_REQ_05_get_fw0_fin(data)                                  ((0x00000100&(data))>>8)
#define FW0_REQ_05_get_fw0_cmd_event(data)                            ((0x00000080&(data))>>7)
#define FW0_REQ_05_get_fw0_data_event(data)                           ((0x00000040&(data))>>6)
#define FW0_REQ_05_get_fw0_rcv_err(data)                              ((0x00000020&(data))>>5)
#define FW0_REQ_05_get_fw0_fin_irq_en(data)                           ((0x00000010&(data))>>4)
#define FW0_REQ_05_get_fw0_cmd_irq_en(data)                           ((0x00000008&(data))>>3)
#define FW0_REQ_05_get_fw0_data_irq_en(data)                          ((0x00000004&(data))>>2)
#define FW0_REQ_05_get_fw0_wait_case(data)                            (0x00000003&(data))

#define  FW0_REQ_06                                                             0x1800A318
#define  FW0_REQ_06_reg_addr                                                    "0xB800A318"
#define  FW0_REQ_06_reg                                                         0xB800A318
#define  FW0_REQ_06_inst_addr                                                   "0x008B"
#define  FW0_REQ_06_inst                                                        0x008B
#define FW0_REQ_06_fw0_cmd_rcv_shift                                  (0)
#define FW0_REQ_06_fw0_cmd_rcv_mask                                   (0x000000FF)
#define FW0_REQ_06_fw0_cmd_rcv(data)                                  (0x000000FF&(data))
#define FW0_REQ_06_get_fw0_cmd_rcv(data)                              (0x000000FF&(data))

#define  FW0_REQ_07                                                             0x1800A31C
#define  FW0_REQ_07_reg_addr                                                    "0xB800A31C"
#define  FW0_REQ_07_reg                                                         0xB800A31C
#define  FW0_REQ_07_inst_addr                                                   "0x008C"
#define  FW0_REQ_07_inst                                                        0x008C
#define FW0_REQ_07_fw0_data_rcv_shift                                 (0)
#define FW0_REQ_07_fw0_data_rcv_mask                                  (0x000000FF)
#define FW0_REQ_07_fw0_data_rcv(data)                                 (0x000000FF&(data))
#define FW0_REQ_07_get_fw0_data_rcv(data)                             (0x000000FF&(data))

#define  FW0_REQ_08                                                             0x1800A320
#define  FW0_REQ_08_reg_addr                                                    "0xB800A320"
#define  FW0_REQ_08_reg                                                         0xB800A320
#define  FW0_REQ_08_inst_addr                                                   "0x008D"
#define  FW0_REQ_08_inst                                                        0x008D
#define FW0_REQ_08_fw0_rd_en_shift                                    (13)
#define FW0_REQ_08_fw0_fifo_len_shift                                 (8)
#define FW0_REQ_08_fw0_rdata_shift                                    (0)
#define FW0_REQ_08_fw0_rd_en_mask                                     (0x00002000)
#define FW0_REQ_08_fw0_fifo_len_mask                                  (0x00001F00)
#define FW0_REQ_08_fw0_rdata_mask                                     (0x000000FF)
#define FW0_REQ_08_fw0_rd_en(data)                                    (0x00002000&((data)<<13))
#define FW0_REQ_08_fw0_fifo_len(data)                                 (0x00001F00&((data)<<8))
#define FW0_REQ_08_fw0_rdata(data)                                    (0x000000FF&(data))
#define FW0_REQ_08_get_fw0_rd_en(data)                                ((0x00002000&(data))>>13)
#define FW0_REQ_08_get_fw0_fifo_len(data)                             ((0x00001F00&(data))>>8)
#define FW0_REQ_08_get_fw0_rdata(data)                                (0x000000FF&(data))


#define FW1_REQ_00                                                    0x1806d340
#define FW1_REQ_00_reg_addr                                           "0xb806d340"
#define FW1_REQ_00_reg                                                0xb806d340
#define FW1_REQ_00_inst_addr                                          "0x00D0"
#define FW1_REQ_00_inst                                               0x00D0
#define FW1_REQ_00_fw1_req_shift                                      (8)
#define FW1_REQ_00_fw1_fifo_clr_shift                                 (7)
#define FW1_REQ_00_fw1_fifo_full_shift                                (6)
#define FW1_REQ_00_fw1_fifo_empty_shift                               (5)
#define FW1_REQ_00_fw1_tx_case_shift                                  (2)
#define FW1_REQ_00_fw1_head_shift                                     (0)
#define FW1_REQ_00_fw1_req_mask                                       (0x00000100)
#define FW1_REQ_00_fw1_fifo_clr_mask                                  (0x00000080)
#define FW1_REQ_00_fw1_fifo_full_mask                                 (0x00000040)
#define FW1_REQ_00_fw1_fifo_empty_mask                                (0x00000020)
#define FW1_REQ_00_fw1_tx_case_mask                                   (0x0000001C)
#define FW1_REQ_00_fw1_head_mask                                      (0x00000003)
#define FW1_REQ_00_fw1_req(data)                                      (0x00000100&((data)<<8))
#define FW1_REQ_00_fw1_fifo_clr(data)                                 (0x00000080&((data)<<7))
#define FW1_REQ_00_fw1_fifo_full(data)                                (0x00000040&((data)<<6))
#define FW1_REQ_00_fw1_fifo_empty(data)                               (0x00000020&((data)<<5))
#define FW1_REQ_00_fw1_tx_case(data)                                  (0x0000001C&((data)<<2))
#define FW1_REQ_00_fw1_head(data)                                     (0x00000003&(data))
#define FW1_REQ_00_get_fw1_req(data)                                  ((0x00000100&(data))>>8)
#define FW1_REQ_00_get_fw1_fifo_clr(data)                             ((0x00000080&(data))>>7)
#define FW1_REQ_00_get_fw1_fifo_full(data)                            ((0x00000040&(data))>>6)
#define FW1_REQ_00_get_fw1_fifo_empty(data)                           ((0x00000020&(data))>>5)
#define FW1_REQ_00_get_fw1_tx_case(data)                              ((0x0000001C&(data))>>2)
#define FW1_REQ_00_get_fw1_head(data)                                 (0x00000003&(data))


#define FW1_REQ_01                                                    0x1806d344
#define FW1_REQ_01_reg_addr                                           "0xb806d344"
#define FW1_REQ_01_reg                                                0xb806d344
#define FW1_REQ_01_inst_addr                                          "0x00D1"
#define FW1_REQ_01_inst                                               0x00D1
#define FW1_REQ_01_fw1_cmd1_shift                                     (0)
#define FW1_REQ_01_fw1_cmd1_mask                                      (0x000000FF)
#define FW1_REQ_01_fw1_cmd1(data)                                     (0x000000FF&(data))
#define FW1_REQ_01_get_fw1_cmd1(data)                                 (0x000000FF&(data))


#define FW1_REQ_02                                                    0x1806d348
#define FW1_REQ_02_reg_addr                                           "0xb806d348"
#define FW1_REQ_02_reg                                                0xb806d348
#define FW1_REQ_02_inst_addr                                          "0x00D2"
#define FW1_REQ_02_inst                                               0x00D2
#define FW1_REQ_02_fw1_cmd2_shift                                     (0)
#define FW1_REQ_02_fw1_cmd2_mask                                      (0x000000FF)
#define FW1_REQ_02_fw1_cmd2(data)                                     (0x000000FF&(data))
#define FW1_REQ_02_get_fw1_cmd2(data)                                 (0x000000FF&(data))


#define FW1_REQ_03                                                    0x1806d34c
#define FW1_REQ_03_reg_addr                                           "0xb806d34c"
#define FW1_REQ_03_reg                                                0xb806d34c
#define FW1_REQ_03_inst_addr                                          "0x00D3"
#define FW1_REQ_03_inst                                               0x00D3
#define FW1_REQ_03_fw1_offset_shift                                   (0)
#define FW1_REQ_03_fw1_offset_mask                                    (0x000000FF)
#define FW1_REQ_03_fw1_offset(data)                                   (0x000000FF&(data))
#define FW1_REQ_03_get_fw1_offset(data)                               (0x000000FF&(data))


#define FW1_REQ_04                                                    0x1806d350
#define FW1_REQ_04_reg_addr                                           "0xb806d350"
#define FW1_REQ_04_reg                                                0xb806d350
#define FW1_REQ_04_inst_addr                                          "0x00D4"
#define FW1_REQ_04_inst                                               0x00D4
#define FW1_REQ_04_fw1_data_shift                                     (0)
#define FW1_REQ_04_fw1_data_mask                                      (0x000000FF)
#define FW1_REQ_04_fw1_data(data)                                     (0x000000FF&(data))
#define FW1_REQ_04_get_fw1_data(data)                                 (0x000000FF&(data))


#define FW1_REQ_05                                                    0x1806d354
#define FW1_REQ_05_reg_addr                                           "0xb806d354"
#define FW1_REQ_05_reg                                                0xb806d354
#define FW1_REQ_05_inst_addr                                          "0x00D5"
#define FW1_REQ_05_inst                                               0x00D5
#define FW1_REQ_05_fw1_rty_ovr_shift                                  (9)
#define FW1_REQ_05_fw1_fin_shift                                      (8)
#define FW1_REQ_05_fw1_cmd_event_shift                                (7)
#define FW1_REQ_05_fw1_data_event_shift                               (6)
#define FW1_REQ_05_fw1_rcv_err_shift                                  (5)
#define FW1_REQ_05_fw1_fin_irq_en_shift                               (4)
#define FW1_REQ_05_fw1_cmd_irq_en_shift                               (3)
#define FW1_REQ_05_fw1_data_irq_en_shift                              (2)
#define FW1_REQ_05_fw1_wait_case_shift                                (0)
#define FW1_REQ_05_fw1_rty_ovr_mask                                   (0x00000200)
#define FW1_REQ_05_fw1_fin_mask                                       (0x00000100)
#define FW1_REQ_05_fw1_cmd_event_mask                                 (0x00000080)
#define FW1_REQ_05_fw1_data_event_mask                                (0x00000040)
#define FW1_REQ_05_fw1_rcv_err_mask                                   (0x00000020)
#define FW1_REQ_05_fw1_fin_irq_en_mask                                (0x00000010)
#define FW1_REQ_05_fw1_cmd_irq_en_mask                                (0x00000008)
#define FW1_REQ_05_fw1_data_irq_en_mask                               (0x00000004)
#define FW1_REQ_05_fw1_wait_case_mask                                 (0x00000003)
#define FW1_REQ_05_fw1_rty_ovr(data)                                  (0x00000200&((data)<<9))
#define FW1_REQ_05_fw1_fin(data)                                      (0x00000100&((data)<<8))
#define FW1_REQ_05_fw1_cmd_event(data)                                (0x00000080&((data)<<7))
#define FW1_REQ_05_fw1_data_event(data)                               (0x00000040&((data)<<6))
#define FW1_REQ_05_fw1_rcv_err(data)                                  (0x00000020&((data)<<5))
#define FW1_REQ_05_fw1_fin_irq_en(data)                               (0x00000010&((data)<<4))
#define FW1_REQ_05_fw1_cmd_irq_en(data)                               (0x00000008&((data)<<3))
#define FW1_REQ_05_fw1_data_irq_en(data)                              (0x00000004&((data)<<2))
#define FW1_REQ_05_fw1_wait_case(data)                                (0x00000003&(data))
#define FW1_REQ_05_get_fw1_rty_ovr(data)                              ((0x00000200&(data))>>9)
#define FW1_REQ_05_get_fw1_fin(data)                                  ((0x00000100&(data))>>8)
#define FW1_REQ_05_get_fw1_cmd_event(data)                            ((0x00000080&(data))>>7)
#define FW1_REQ_05_get_fw1_data_event(data)                           ((0x00000040&(data))>>6)
#define FW1_REQ_05_get_fw1_rcv_err(data)                              ((0x00000020&(data))>>5)
#define FW1_REQ_05_get_fw1_fin_irq_en(data)                           ((0x00000010&(data))>>4)
#define FW1_REQ_05_get_fw1_cmd_irq_en(data)                           ((0x00000008&(data))>>3)
#define FW1_REQ_05_get_fw1_data_irq_en(data)                          ((0x00000004&(data))>>2)
#define FW1_REQ_05_get_fw1_wait_case(data)                            (0x00000003&(data))


#define FW1_REQ_06                                                    0x1806d358
#define FW1_REQ_06_reg_addr                                           "0xb806d358"
#define FW1_REQ_06_reg                                                0xb806d358
#define FW1_REQ_06_inst_addr                                          "0x00D6"
#define FW1_REQ_06_inst                                               0x00D6
#define FW1_REQ_06_fw1_cmd_rcv_shift                                  (0)
#define FW1_REQ_06_fw1_cmd_rcv_mask                                   (0x000000FF)
#define FW1_REQ_06_fw1_cmd_rcv(data)                                  (0x000000FF&(data))
#define FW1_REQ_06_get_fw1_cmd_rcv(data)                              (0x000000FF&(data))


#define FW1_REQ_07                                                    0x1806d35c
#define FW1_REQ_07_reg_addr                                           "0xb806d35c"
#define FW1_REQ_07_reg                                                0xb806d35c
#define FW1_REQ_07_inst_addr                                          "0x00D7"
#define FW1_REQ_07_inst                                               0x00D7
#define FW1_REQ_07_fw1_data_rcv_shift                                 (0)
#define FW1_REQ_07_fw1_data_rcv_mask                                  (0x000000FF)
#define FW1_REQ_07_fw1_data_rcv(data)                                 (0x000000FF&(data))
#define FW1_REQ_07_get_fw1_data_rcv(data)                             (0x000000FF&(data))


#define FW1_REQ_08                                                    0x1806d360
#define FW1_REQ_08_reg_addr                                           "0xb806d360"
#define FW1_REQ_08_reg                                                0xb806d360
#define FW1_REQ_08_inst_addr                                          "0x00D8"
#define FW1_REQ_08_inst                                               0x00D8
#define FW1_REQ_08_fw1_rd_en_shift                                    (13)
#define FW1_REQ_08_fw1_fifo_len_shift                                 (8)
#define FW1_REQ_08_fw1_rdata_shift                                    (0)
#define FW1_REQ_08_fw1_rd_en_mask                                     (0x00002000)
#define FW1_REQ_08_fw1_fifo_len_mask                                  (0x00001F00)
#define FW1_REQ_08_fw1_rdata_mask                                     (0x000000FF)
#define FW1_REQ_08_fw1_rd_en(data)                                    (0x00002000&((data)<<13))
#define FW1_REQ_08_fw1_fifo_len(data)                                 (0x00001F00&((data)<<8))
#define FW1_REQ_08_fw1_rdata(data)                                    (0x000000FF&(data))
#define FW1_REQ_08_get_fw1_rd_en(data)                                ((0x00002000&(data))>>13)
#define FW1_REQ_08_get_fw1_fifo_len(data)                             ((0x00001F00&(data))>>8)
#define FW1_REQ_08_get_fw1_rdata(data)                                (0x000000FF&(data))


#define FW2_REQ_00                                                    0x1806d380
#define FW2_REQ_00_reg_addr                                           "0xb806d380"
#define FW2_REQ_00_reg                                                0xb806d380
#define FW2_REQ_00_inst_addr                                          "0x00E0"
#define FW2_REQ_00_inst                                               0x00E0
#define FW2_REQ_00_fw2_req_shift                                      (8)
#define FW2_REQ_00_fw2_fifo_clr_shift                                 (7)
#define FW2_REQ_00_fw2_fifo_full_shift                                (6)
#define FW2_REQ_00_fw2_fifo_empty_shift                               (5)
#define FW2_REQ_00_fw2_tx_case_shift                                  (2)
#define FW2_REQ_00_fw2_head_shift                                     (0)
#define FW2_REQ_00_fw2_req_mask                                       (0x00000100)
#define FW2_REQ_00_fw2_fifo_clr_mask                                  (0x00000080)
#define FW2_REQ_00_fw2_fifo_full_mask                                 (0x00000040)
#define FW2_REQ_00_fw2_fifo_empty_mask                                (0x00000020)
#define FW2_REQ_00_fw2_tx_case_mask                                   (0x0000001C)
#define FW2_REQ_00_fw2_head_mask                                      (0x00000003)
#define FW2_REQ_00_fw2_req(data)                                      (0x00000100&((data)<<8))
#define FW2_REQ_00_fw2_fifo_clr(data)                                 (0x00000080&((data)<<7))
#define FW2_REQ_00_fw2_fifo_full(data)                                (0x00000040&((data)<<6))
#define FW2_REQ_00_fw2_fifo_empty(data)                               (0x00000020&((data)<<5))
#define FW2_REQ_00_fw2_tx_case(data)                                  (0x0000001C&((data)<<2))
#define FW2_REQ_00_fw2_head(data)                                     (0x00000003&(data))
#define FW2_REQ_00_get_fw2_req(data)                                  ((0x00000100&(data))>>8)
#define FW2_REQ_00_get_fw2_fifo_clr(data)                             ((0x00000080&(data))>>7)
#define FW2_REQ_00_get_fw2_fifo_full(data)                            ((0x00000040&(data))>>6)
#define FW2_REQ_00_get_fw2_fifo_empty(data)                           ((0x00000020&(data))>>5)
#define FW2_REQ_00_get_fw2_tx_case(data)                              ((0x0000001C&(data))>>2)
#define FW2_REQ_00_get_fw2_head(data)                                 (0x00000003&(data))


#define FW2_REQ_01                                                    0x1806d384
#define FW2_REQ_01_reg_addr                                           "0xb806d384"
#define FW2_REQ_01_reg                                                0xb806d384
#define FW2_REQ_01_inst_addr                                          "0x00E1"
#define FW2_REQ_01_inst                                               0x00E1
#define FW2_REQ_01_fw2_cmd1_shift                                     (0)
#define FW2_REQ_01_fw2_cmd1_mask                                      (0x000000FF)
#define FW2_REQ_01_fw2_cmd1(data)                                     (0x000000FF&(data))
#define FW2_REQ_01_get_fw2_cmd1(data)                                 (0x000000FF&(data))


#define FW2_REQ_02                                                    0x1806d388
#define FW2_REQ_02_reg_addr                                           "0xb806d388"
#define FW2_REQ_02_reg                                                0xb806d388
#define FW2_REQ_02_inst_addr                                          "0x00E2"
#define FW2_REQ_02_inst                                               0x00E2
#define FW2_REQ_02_fw2_cmd2_shift                                     (0)
#define FW2_REQ_02_fw2_cmd2_mask                                      (0x000000FF)
#define FW2_REQ_02_fw2_cmd2(data)                                     (0x000000FF&(data))
#define FW2_REQ_02_get_fw2_cmd2(data)                                 (0x000000FF&(data))


#define FW2_REQ_03                                                    0x1806d38c
#define FW2_REQ_03_reg_addr                                           "0xb806d38c"
#define FW2_REQ_03_reg                                                0xb806d38c
#define FW2_REQ_03_inst_addr                                          "0x00E3"
#define FW2_REQ_03_inst                                               0x00E3
#define FW2_REQ_03_fw2_offset_shift                                   (0)
#define FW2_REQ_03_fw2_offset_mask                                    (0x000000FF)
#define FW2_REQ_03_fw2_offset(data)                                   (0x000000FF&(data))
#define FW2_REQ_03_get_fw2_offset(data)                               (0x000000FF&(data))


#define FW2_REQ_04                                                    0x1806d390
#define FW2_REQ_04_reg_addr                                           "0xb806d390"
#define FW2_REQ_04_reg                                                0xb806d390
#define FW2_REQ_04_inst_addr                                          "0x00E4"
#define FW2_REQ_04_inst                                               0x00E4
#define FW2_REQ_04_fw2_data_shift                                     (0)
#define FW2_REQ_04_fw2_data_mask                                      (0x000000FF)
#define FW2_REQ_04_fw2_data(data)                                     (0x000000FF&(data))
#define FW2_REQ_04_get_fw2_data(data)                                 (0x000000FF&(data))


#define FW2_REQ_05                                                    0x1806d394
#define FW2_REQ_05_reg_addr                                           "0xb806d394"
#define FW2_REQ_05_reg                                                0xb806d394
#define FW2_REQ_05_inst_addr                                          "0x00E5"
#define FW2_REQ_05_inst                                               0x00E5
#define FW2_REQ_05_fw2_rty_ovr_shift                                  (9)
#define FW2_REQ_05_fw2_fin_shift                                      (8)
#define FW2_REQ_05_fw2_cmd_event_shift                                (7)
#define FW2_REQ_05_fw2_data_event_shift                               (6)
#define FW2_REQ_05_fw2_rcv_err_shift                                  (5)
#define FW2_REQ_05_fw2_fin_irq_en_shift                               (4)
#define FW2_REQ_05_fw2_cmd_irq_en_shift                               (3)
#define FW2_REQ_05_fw2_data_irq_en_shift                              (2)
#define FW2_REQ_05_fw2_wait_case_shift                                (0)
#define FW2_REQ_05_fw2_rty_ovr_mask                                   (0x00000200)
#define FW2_REQ_05_fw2_fin_mask                                       (0x00000100)
#define FW2_REQ_05_fw2_cmd_event_mask                                 (0x00000080)
#define FW2_REQ_05_fw2_data_event_mask                                (0x00000040)
#define FW2_REQ_05_fw2_rcv_err_mask                                   (0x00000020)
#define FW2_REQ_05_fw2_fin_irq_en_mask                                (0x00000010)
#define FW2_REQ_05_fw2_cmd_irq_en_mask                                (0x00000008)
#define FW2_REQ_05_fw2_data_irq_en_mask                               (0x00000004)
#define FW2_REQ_05_fw2_wait_case_mask                                 (0x00000003)
#define FW2_REQ_05_fw2_rty_ovr(data)                                  (0x00000200&((data)<<9))
#define FW2_REQ_05_fw2_fin(data)                                      (0x00000100&((data)<<8))
#define FW2_REQ_05_fw2_cmd_event(data)                                (0x00000080&((data)<<7))
#define FW2_REQ_05_fw2_data_event(data)                               (0x00000040&((data)<<6))
#define FW2_REQ_05_fw2_rcv_err(data)                                  (0x00000020&((data)<<5))
#define FW2_REQ_05_fw2_fin_irq_en(data)                               (0x00000010&((data)<<4))
#define FW2_REQ_05_fw2_cmd_irq_en(data)                               (0x00000008&((data)<<3))
#define FW2_REQ_05_fw2_data_irq_en(data)                              (0x00000004&((data)<<2))
#define FW2_REQ_05_fw2_wait_case(data)                                (0x00000003&(data))
#define FW2_REQ_05_get_fw2_rty_ovr(data)                              ((0x00000200&(data))>>9)
#define FW2_REQ_05_get_fw2_fin(data)                                  ((0x00000100&(data))>>8)
#define FW2_REQ_05_get_fw2_cmd_event(data)                            ((0x00000080&(data))>>7)
#define FW2_REQ_05_get_fw2_data_event(data)                           ((0x00000040&(data))>>6)
#define FW2_REQ_05_get_fw2_rcv_err(data)                              ((0x00000020&(data))>>5)
#define FW2_REQ_05_get_fw2_fin_irq_en(data)                           ((0x00000010&(data))>>4)
#define FW2_REQ_05_get_fw2_cmd_irq_en(data)                           ((0x00000008&(data))>>3)
#define FW2_REQ_05_get_fw2_data_irq_en(data)                          ((0x00000004&(data))>>2)
#define FW2_REQ_05_get_fw2_wait_case(data)                            (0x00000003&(data))


#define FW2_REQ_06                                                    0x1806d398
#define FW2_REQ_06_reg_addr                                           "0xb806d398"
#define FW2_REQ_06_reg                                                0xb806d398
#define FW2_REQ_06_inst_addr                                          "0x00E6"
#define FW2_REQ_06_inst                                               0x00E6
#define FW2_REQ_06_fw2_cmd_rcv_shift                                  (0)
#define FW2_REQ_06_fw2_cmd_rcv_mask                                   (0x000000FF)
#define FW2_REQ_06_fw2_cmd_rcv(data)                                  (0x000000FF&(data))
#define FW2_REQ_06_get_fw2_cmd_rcv(data)                              (0x000000FF&(data))


#define FW2_REQ_07                                                    0x1806d39c
#define FW2_REQ_07_reg_addr                                           "0xb806d39c"
#define FW2_REQ_07_reg                                                0xb806d39c
#define FW2_REQ_07_inst_addr                                          "0x00E7"
#define FW2_REQ_07_inst                                               0x00E7
#define FW2_REQ_07_fw2_data_rcv_shift                                 (0)
#define FW2_REQ_07_fw2_data_rcv_mask                                  (0x000000FF)
#define FW2_REQ_07_fw2_data_rcv(data)                                 (0x000000FF&(data))
#define FW2_REQ_07_get_fw2_data_rcv(data)                             (0x000000FF&(data))


#define FW2_REQ_08                                                    0x1806d3a0
#define FW2_REQ_08_reg_addr                                           "0xb806d3a0"
#define FW2_REQ_08_reg                                                0xb806d3a0
#define FW2_REQ_08_inst_addr                                          "0x00E8"
#define FW2_REQ_08_inst                                               0x00E8
#define FW2_REQ_08_fw2_rd_en_shift                                    (13)
#define FW2_REQ_08_fw2_fifo_len_shift                                 (8)
#define FW2_REQ_08_fw2_rdata_shift                                    (0)
#define FW2_REQ_08_fw2_rd_en_mask                                     (0x00002000)
#define FW2_REQ_08_fw2_fifo_len_mask                                  (0x00001F00)
#define FW2_REQ_08_fw2_rdata_mask                                     (0x000000FF)
#define FW2_REQ_08_fw2_rd_en(data)                                    (0x00002000&((data)<<13))
#define FW2_REQ_08_fw2_fifo_len(data)                                 (0x00001F00&((data)<<8))
#define FW2_REQ_08_fw2_rdata(data)                                    (0x000000FF&(data))
#define FW2_REQ_08_get_fw2_rd_en(data)                                ((0x00002000&(data))>>13)
#define FW2_REQ_08_get_fw2_fifo_len(data)                             ((0x00001F00&(data))>>8)
#define FW2_REQ_08_get_fw2_rdata(data)                                (0x000000FF&(data))


#define CBUS_DDC_00                                                   0x1800A3C0
#define CBUS_DDC_00_reg_addr                                          "0xB800A3C0"
#define CBUS_DDC_00_reg                                               0xB800A3C0
#define  CBUS_DDC_00_inst_addr                                                  "0x008E"
#define  CBUS_DDC_00_inst                                                       0x008E
#define CBUS_DDC_00_ddc_err_code_shift                                (0)
#define CBUS_DDC_00_ddc_err_code_mask                                 (0x000000FF)
#define CBUS_DDC_00_ddc_err_code(data)                                (0x000000FF&(data))
#define CBUS_DDC_00_get_ddc_err_code(data)                            (0x000000FF&(data))

#define  CBUS_DDC_01                                                            0x1800A3C4
#define  CBUS_DDC_01_reg_addr                                                   "0xB800A3C4"
#define  CBUS_DDC_01_reg                                                        0xB800A3C4
#define  CBUS_DDC_01_inst_addr                                                  "0x008F"
#define  CBUS_DDC_01_inst                                                       0x008F
#define CBUS_DDC_01_iic_ck_tgt_shift                                  (0)
#define CBUS_DDC_01_iic_ck_tgt_mask                                   (0x000000FF)
#define CBUS_DDC_01_iic_ck_tgt(data)                                  (0x000000FF&(data))
#define CBUS_DDC_01_get_iic_ck_tgt(data)                              (0x000000FF&(data))

#define  CBUS_DDC_02                                                            0x1800A3C8
#define  CBUS_DDC_02_reg_addr                                                   "0xB800A3C8"
#define  CBUS_DDC_02_reg                                                        0xB800A3C8
#define  CBUS_DDC_02_inst_addr                                                  "0x0090"
#define  CBUS_DDC_02_inst                                                       0x0090
#define CBUS_DDC_02_mcuddc_en_shift                                   (7)
#define CBUS_DDC_02_ddc_prior_dis_shift                               (6)
#define CBUS_DDC_02_ddc_cmd_event_shift                               (5)
#define CBUS_DDC_02_ddc_data_event_shift                              (4)
#define CBUS_DDC_02_ddc_cmd_irq_en_shift                              (3)
#define CBUS_DDC_02_ddc_data_irq_en_shift                             (2)
#define CBUS_DDC_02_ddc_req_ctrl_shift                                (1)
#define CBUS_DDC_02_ddc_req_shift                                     (0)
#define CBUS_DDC_02_mcuddc_en_mask                                    (0x00000080)
#define CBUS_DDC_02_ddc_prior_dis_mask                                (0x00000040)
#define CBUS_DDC_02_ddc_cmd_event_mask                                (0x00000020)
#define CBUS_DDC_02_ddc_data_event_mask                               (0x00000010)
#define CBUS_DDC_02_ddc_cmd_irq_en_mask                               (0x00000008)
#define CBUS_DDC_02_ddc_data_irq_en_mask                              (0x00000004)
#define CBUS_DDC_02_ddc_req_ctrl_mask                                 (0x00000002)
#define CBUS_DDC_02_ddc_req_mask                                      (0x00000001)
#define CBUS_DDC_02_mcuddc_en(data)                                   (0x00000080&((data)<<7))
#define CBUS_DDC_02_ddc_prior_dis(data)                               (0x00000040&((data)<<6))
#define CBUS_DDC_02_ddc_cmd_event(data)                               (0x00000020&((data)<<5))
#define CBUS_DDC_02_ddc_data_event(data)                              (0x00000010&((data)<<4))
#define CBUS_DDC_02_ddc_cmd_irq_en(data)                              (0x00000008&((data)<<3))
#define CBUS_DDC_02_ddc_data_irq_en(data)                             (0x00000004&((data)<<2))
#define CBUS_DDC_02_ddc_req_ctrl(data)                                (0x00000002&((data)<<1))
#define CBUS_DDC_02_ddc_req(data)                                     (0x00000001&(data))
#define CBUS_DDC_02_get_mcuddc_en(data)                               ((0x00000080&(data))>>7)
#define CBUS_DDC_02_get_ddc_prior_dis(data)                           ((0x00000040&(data))>>6)
#define CBUS_DDC_02_get_ddc_cmd_event(data)                           ((0x00000020&(data))>>5)
#define CBUS_DDC_02_get_ddc_data_event(data)                          ((0x00000010&(data))>>4)
#define CBUS_DDC_02_get_ddc_cmd_irq_en(data)                          ((0x00000008&(data))>>3)
#define CBUS_DDC_02_get_ddc_data_irq_en(data)                         ((0x00000004&(data))>>2)
#define CBUS_DDC_02_get_ddc_req_ctrl(data)                            ((0x00000002&(data))>>1)
#define CBUS_DDC_02_get_ddc_req(data)                                 (0x00000001&(data))

#define  CBUS_DDC_03                                                            0x1800A3CC
#define  CBUS_DDC_03_reg_addr                                                   "0xB800A3CC"
#define  CBUS_DDC_03_reg                                                        0xB800A3CC
#define  CBUS_DDC_03_inst_addr                                                  "0x0091"
#define  CBUS_DDC_03_inst                                                       0x0091
#define CBUS_DDC_03_ddc_rcv_cmd_shift                                 (0)
#define CBUS_DDC_03_ddc_rcv_cmd_mask                                  (0x000000FF)
#define CBUS_DDC_03_ddc_rcv_cmd(data)                                 (0x000000FF&(data))
#define CBUS_DDC_03_get_ddc_rcv_cmd(data)                             (0x000000FF&(data))

#define  CBUS_DDC_04                                                            0x1800A3D0
#define  CBUS_DDC_04_reg_addr                                                   "0xB800A3D0"
#define  CBUS_DDC_04_reg                                                        0xB800A3D0
#define  CBUS_DDC_04_inst_addr                                                  "0x0092"
#define  CBUS_DDC_04_inst                                                       0x0092
#define CBUS_DDC_04_ddc_rcv_data_shift                                (0)
#define CBUS_DDC_04_ddc_rcv_data_mask                                 (0x000000FF)
#define CBUS_DDC_04_ddc_rcv_data(data)                                (0x000000FF&(data))
#define CBUS_DDC_04_get_ddc_rcv_data(data)                            (0x000000FF&(data))

#define  CBUS_DDC_05                                                            0x1800A3D4
#define  CBUS_DDC_05_reg_addr                                                   "0xB800A3D4"
#define  CBUS_DDC_05_reg                                                        0xB800A3D4
#define  CBUS_DDC_05_inst_addr                                                  "0x0093"
#define  CBUS_DDC_05_inst                                                       0x0093
#define CBUS_DDC_05_ddc_data_fw_shift                                 (0)
#define CBUS_DDC_05_ddc_data_fw_mask                                  (0x000000FF)
#define CBUS_DDC_05_ddc_data_fw(data)                                 (0x000000FF&(data))
#define CBUS_DDC_05_get_ddc_data_fw(data)                             (0x000000FF&(data))

#define  CBUS_DDC_06                                                            0x1800A3D8
#define  CBUS_DDC_06_reg_addr                                                   "0xB800A3D8"
#define  CBUS_DDC_06_reg                                                        0xB800A3D8
#define  CBUS_DDC_06_inst_addr                                                  "0x0094"
#define  CBUS_DDC_06_inst                                                       0x0094
#define CBUS_DDC_06_ddc_eof_irq_shift                                 (3)
#define CBUS_DDC_06_ddc_eof_irq_en_shift                              (2)
#define CBUS_DDC_06_ddcrd_rst_en_shift                                (1)
#define CBUS_DDC_06_ddcrd_new_md_shift                                (0)
#define CBUS_DDC_06_ddc_eof_irq_mask                                  (0x00000008)
#define CBUS_DDC_06_ddc_eof_irq_en_mask                               (0x00000004)
#define CBUS_DDC_06_ddcrd_rst_en_mask                                 (0x00000002)
#define CBUS_DDC_06_ddcrd_new_md_mask                                 (0x00000001)
#define CBUS_DDC_06_ddc_eof_irq(data)                                 (0x00000008&((data)<<3))
#define CBUS_DDC_06_ddc_eof_irq_en(data)                              (0x00000004&((data)<<2))
#define CBUS_DDC_06_ddcrd_rst_en(data)                                (0x00000002&((data)<<1))
#define CBUS_DDC_06_ddcrd_new_md(data)                                (0x00000001&(data))
#define CBUS_DDC_06_get_ddc_eof_irq(data)                             ((0x00000008&(data))>>3)
#define CBUS_DDC_06_get_ddc_eof_irq_en(data)                          ((0x00000004&(data))>>2)
#define CBUS_DDC_06_get_ddcrd_rst_en(data)                            ((0x00000002&(data))>>1)
#define CBUS_DDC_06_get_ddcrd_new_md(data)                            (0x00000001&(data))

#define  CBUS_WDOG                                                              0x1800A3E0
#define  CBUS_WDOG_reg_addr                                                     "0xB800A3E0"
#define  CBUS_WDOG_reg                                                          0xB800A3E0
#define  CBUS_WDOG_inst_addr                                                    "0x0095"
#define  CBUS_WDOG_inst                                                         0x0095
#define CBUS_WDOG_clk_mod_vwd_shift                                   (5)
#define CBUS_WDOG_clk_mod_awd_shift                                   (4)
#define CBUS_WDOG_mute_en_vwd_shift                                   (3)
#define CBUS_WDOG_mute_en_awd_shift                                   (2)
#define CBUS_WDOG_path_en_off_vwd_shift                               (1)
#define CBUS_WDOG_path_en_off_awd_shift                               (0)
#define CBUS_WDOG_clk_mod_vwd_mask                                    (0x00000020)
#define CBUS_WDOG_clk_mod_awd_mask                                    (0x00000010)
#define CBUS_WDOG_mute_en_vwd_mask                                    (0x00000008)
#define CBUS_WDOG_mute_en_awd_mask                                    (0x00000004)
#define CBUS_WDOG_path_en_off_vwd_mask                                (0x00000002)
#define CBUS_WDOG_path_en_off_awd_mask                                (0x00000001)
#define CBUS_WDOG_clk_mod_vwd(data)                                   (0x00000020&((data)<<5))
#define CBUS_WDOG_clk_mod_awd(data)                                   (0x00000010&((data)<<4))
#define CBUS_WDOG_mute_en_vwd(data)                                   (0x00000008&((data)<<3))
#define CBUS_WDOG_mute_en_awd(data)                                   (0x00000004&((data)<<2))
#define CBUS_WDOG_path_en_off_vwd(data)                               (0x00000002&((data)<<1))
#define CBUS_WDOG_path_en_off_awd(data)                               (0x00000001&(data))
#define CBUS_WDOG_get_clk_mod_vwd(data)                               ((0x00000020&(data))>>5)
#define CBUS_WDOG_get_clk_mod_awd(data)                               ((0x00000010&(data))>>4)
#define CBUS_WDOG_get_mute_en_vwd(data)                               ((0x00000008&(data))>>3)
#define CBUS_WDOG_get_mute_en_awd(data)                               ((0x00000004&(data))>>2)
#define CBUS_WDOG_get_path_en_off_vwd(data)                           ((0x00000002&(data))>>1)
#define CBUS_WDOG_get_path_en_off_awd(data)                           (0x00000001&(data))

#define  CBUS_INT_INDEX                                                         0x1800A3E4
#define  CBUS_INT_INDEX_reg_addr                                                "0xB800A3E4"
#define  CBUS_INT_INDEX_reg                                                     0xB800A3E4
#define  CBUS_INT_INDEX_inst_addr                                               "0x0096"
#define  CBUS_INT_INDEX_inst                                                    0x0096
#define CBUS_INT_INDEX_arbiter_irq_shift                              (5)
#define CBUS_INT_INDEX_ddc_irq_shift                                  (4)
#define CBUS_INT_INDEX_msc_ch_irq_shift                               (3)
#define CBUS_INT_INDEX_msc_int_irq_shift                              (2)
#define CBUS_INT_INDEX_msc_stat_irq_shift                             (1)
#define CBUS_INT_INDEX_ctrl_01_resv_shift                             (0)
#define CBUS_INT_INDEX_arbiter_irq_mask                               (0x00000020)
#define CBUS_INT_INDEX_ddc_irq_mask                                   (0x00000010)
#define CBUS_INT_INDEX_msc_ch_irq_mask                                (0x00000008)
#define CBUS_INT_INDEX_msc_int_irq_mask                               (0x00000004)
#define CBUS_INT_INDEX_msc_stat_irq_mask                              (0x00000002)
#define CBUS_INT_INDEX_ctrl_01_resv_mask                              (0x00000001)
#define CBUS_INT_INDEX_arbiter_irq(data)                              (0x00000020&((data)<<5))
#define CBUS_INT_INDEX_ddc_irq(data)                                  (0x00000010&((data)<<4))
#define CBUS_INT_INDEX_msc_ch_irq(data)                               (0x00000008&((data)<<3))
#define CBUS_INT_INDEX_msc_int_irq(data)                              (0x00000004&((data)<<2))
#define CBUS_INT_INDEX_msc_stat_irq(data)                             (0x00000002&((data)<<1))
#define CBUS_INT_INDEX_ctrl_01_resv(data)                             (0x00000001&(data))
#define CBUS_INT_INDEX_get_arbiter_irq(data)                          ((0x00000020&(data))>>5)
#define CBUS_INT_INDEX_get_ddc_irq(data)                              ((0x00000010&(data))>>4)
#define CBUS_INT_INDEX_get_msc_ch_irq(data)                           ((0x00000008&(data))>>3)
#define CBUS_INT_INDEX_get_msc_int_irq(data)                          ((0x00000004&(data))>>2)
#define CBUS_INT_INDEX_get_msc_stat_irq(data)                         ((0x00000002&(data))>>1)
#define CBUS_INT_INDEX_get_ctrl_01_resv(data)                         (0x00000001&(data))

#define  CBUS_TEST                                                              0x1800A3E8
#define  CBUS_TEST_reg_addr                                                     "0xB800A3E8"
#define  CBUS_TEST_reg                                                          0xB800A3E8
#define  CBUS_TEST_inst_addr                                                    "0x0097"
#define  CBUS_TEST_inst                                                         0x0097
#define CBUS_TEST_cbus_test_md_shift                                  (6)
#define CBUS_TEST_fw_out_shift                                        (5)
#define CBUS_TEST_dbg_sel_shift                                       (2)
#define CBUS_TEST_cbus_test_md_mask                                   (0x000000C0)
#define CBUS_TEST_fw_out_mask                                         (0x00000020)
#define CBUS_TEST_dbg_sel_mask                                        (0x0000001C)
#define CBUS_TEST_cbus_test_md(data)                                  (0x000000C0&((data)<<6))
#define CBUS_TEST_fw_out(data)                                        (0x00000020&((data)<<5))
#define CBUS_TEST_dbg_sel(data)                                       (0x0000001C&((data)<<2))
#define CBUS_TEST_get_cbus_test_md(data)                              ((0x000000C0&(data))>>6)
#define CBUS_TEST_get_fw_out(data)                                    ((0x00000020&(data))>>5)
#define CBUS_TEST_get_dbg_sel(data)                                   ((0x0000001C&(data))>>2)

#define  CBUS_DUMMY0                                                            0x1800A3EC
#define  CBUS_DUMMY0_reg_addr                                                   "0xB800A3EC"
#define  CBUS_DUMMY0_reg                                                        0xB800A3EC
#define  CBUS_DUMMY0_inst_addr                                                  "0x0098"
#define  CBUS_DUMMY0_inst                                                       0x0098
#define CBUS_DUMMY0_cbus_dummy0_shift                                 (0)
#define CBUS_DUMMY0_cbus_dummy0_mask                                  (0xFFFFFFFF)
#define CBUS_DUMMY0_cbus_dummy0(data)                                 (0xFFFFFFFF&(data))
#define CBUS_DUMMY0_get_cbus_dummy0(data)                             (0xFFFFFFFF&(data))

//*******************************************************************************
//End of Cbus Reg 
//*******************************************************************************

//*******************************************************************************
//START OF MHL REG
//*******************************************************************************


#define MHL_DAL_CTRL                                                  0x1800D600
#define MHL_DAL_CTRL_reg_addr                                         "0xB800D600"
#define MHL_DAL_CTRL_reg                                              0xB800D600
#define  MHL_DAL_CTRL_inst_addr                                                 "0x0000"
#define  MHL_DAL_CTRL_inst                                                      0x0000
#define  MHL_DAL_CTRL_clk25xinv_r_shift                                         (31)
#define  MHL_DAL_CTRL_clk25xinv_g_shift                                         (30)
#define  MHL_DAL_CTRL_clk25xinv_b_shift                                         (29)
#define MHL_DAL_CTRL_mhl_de_sel_shift                                 (28)
#define MHL_DAL_CTRL_mhl_tran_err_thrd_shift                          (24)
#define MHL_DAL_CTRL_mhl_neg_de_err_thrd_shift                        (20)
#define MHL_DAL_CTRL_mhl_pos_de_err_thrd_shift                        (16)
#define MHL_DAL_CTRL_b_r_ch_sel_shift                                 (15)
#define MHL_DAL_CTRL_mhl_neg_de_lowbd_shift                           (8)
#define  MHL_DAL_CTRL_mhl_rclkinv_shift                                         (7)
#define  MHL_DAL_CTRL_mhl_bclkinv_shift                                         (6)
#define MHL_DAL_CTRL_mhl_pos_de_lowbd_shift                           (0)
#define  MHL_DAL_CTRL_clk25xinv_r_mask                                          (0x80000000)
#define  MHL_DAL_CTRL_clk25xinv_g_mask                                          (0x40000000)
#define  MHL_DAL_CTRL_clk25xinv_b_mask                                          (0x20000000)
#define MHL_DAL_CTRL_mhl_de_sel_mask                                  (0x10000000)
#define MHL_DAL_CTRL_mhl_tran_err_thrd_mask                           (0x0F000000)
#define MHL_DAL_CTRL_mhl_neg_de_err_thrd_mask                         (0x00F00000)
#define MHL_DAL_CTRL_mhl_pos_de_err_thrd_mask                         (0x000F0000)
#define MHL_DAL_CTRL_b_r_ch_sel_mask                                  (0x00008000)
#define MHL_DAL_CTRL_mhl_neg_de_lowbd_mask                            (0x00007F00)
#define  MHL_DAL_CTRL_mhl_rclkinv_mask                                          (0x00000080)
#define  MHL_DAL_CTRL_mhl_bclkinv_mask                                          (0x00000040)
#define MHL_DAL_CTRL_mhl_pos_de_lowbd_mask                            (0x0000003F)
#define  MHL_DAL_CTRL_clk25xinv_r(data)                                         (0x80000000&((data)<<31))
#define  MHL_DAL_CTRL_clk25xinv_g(data)                                         (0x40000000&((data)<<30))
#define  MHL_DAL_CTRL_clk25xinv_b(data)                                         (0x20000000&((data)<<29))
#define MHL_DAL_CTRL_mhl_de_sel(data)                                 (0x10000000&((data)<<28))
#define MHL_DAL_CTRL_mhl_tran_err_thrd(data)                          (0x0F000000&((data)<<24))
#define MHL_DAL_CTRL_mhl_neg_de_err_thrd(data)                        (0x00F00000&((data)<<20))
#define MHL_DAL_CTRL_mhl_pos_de_err_thrd(data)                        (0x000F0000&((data)<<16))
#define MHL_DAL_CTRL_b_r_ch_sel(data)                                 (0x00008000&((data)<<15))
#define MHL_DAL_CTRL_mhl_neg_de_lowbd(data)                           (0x00007F00&((data)<<8))
#define  MHL_DAL_CTRL_mhl_rclkinv(data)                                         (0x00000080&((data)<<7))
#define  MHL_DAL_CTRL_mhl_bclkinv(data)                                         (0x00000040&((data)<<6))
#define MHL_DAL_CTRL_mhl_pos_de_lowbd(data)                           (0x0000003F&(data))
#define  MHL_DAL_CTRL_get_clk25xinv_r(data)                                     ((0x80000000&(data))>>31)
#define  MHL_DAL_CTRL_get_clk25xinv_g(data)                                     ((0x40000000&(data))>>30)
#define  MHL_DAL_CTRL_get_clk25xinv_b(data)                                     ((0x20000000&(data))>>29)
#define MHL_DAL_CTRL_get_mhl_de_sel(data)                             ((0x10000000&(data))>>28)
#define MHL_DAL_CTRL_get_mhl_tran_err_thrd(data)                      ((0x0F000000&(data))>>24)
#define MHL_DAL_CTRL_get_mhl_neg_de_err_thrd(data)                    ((0x00F00000&(data))>>20)
#define MHL_DAL_CTRL_get_mhl_pos_de_err_thrd(data)                    ((0x000F0000&(data))>>16)
#define MHL_DAL_CTRL_get_b_r_ch_sel(data)                             ((0x00008000&(data))>>15)
#define MHL_DAL_CTRL_get_mhl_neg_de_lowbd(data)                       ((0x00007F00&(data))>>8)
#define  MHL_DAL_CTRL_get_mhl_rclkinv(data)                                     ((0x00000080&(data))>>7)
#define  MHL_DAL_CTRL_get_mhl_bclkinv(data)                                     ((0x00000040&(data))>>6)
#define MHL_DAL_CTRL_get_mhl_pos_de_lowbd(data)                       (0x0000003F&(data))

#define  MHL_DAL_STATUS                                                         0x1800D604
#define  MHL_DAL_STATUS_reg_addr                                                "0xB800D604"
#define  MHL_DAL_STATUS_reg                                                     0xB800D604
#define  MHL_DAL_STATUS_inst_addr                                               "0x0001"
#define  MHL_DAL_STATUS_inst                                                    0x0001
#define MHL_DAL_STATUS_mhl_de_glitch_cycle_shift                      (4)
#define MHL_DAL_STATUS_mhl_ver_1_2_shift                              (2)
#define MHL_DAL_STATUS_mhl_de_glitch_en_shift                         (1)
#define MHL_DAL_STATUS_pn_swap_shift                                  (0)
#define MHL_DAL_STATUS_mhl_de_glitch_cycle_mask                       (0x000000F0)
#define MHL_DAL_STATUS_mhl_ver_1_2_mask                               (0x00000004)
#define MHL_DAL_STATUS_mhl_de_glitch_en_mask                          (0x00000002)
#define MHL_DAL_STATUS_pn_swap_mask                                   (0x00000001)
#define MHL_DAL_STATUS_mhl_de_glitch_cycle(data)                      (0x000000F0&((data)<<4))
#define MHL_DAL_STATUS_mhl_ver_1_2(data)                              (0x00000004&((data)<<2))
#define MHL_DAL_STATUS_mhl_de_glitch_en(data)                         (0x00000002&((data)<<1))
#define MHL_DAL_STATUS_pn_swap(data)                                  (0x00000001&(data))
#define MHL_DAL_STATUS_get_mhl_de_glitch_cycle(data)                  ((0x000000F0&(data))>>4)
#define MHL_DAL_STATUS_get_mhl_ver_1_2(data)                          ((0x00000004&(data))>>2)
#define MHL_DAL_STATUS_get_mhl_de_glitch_en(data)                     ((0x00000002&(data))>>1)
#define MHL_DAL_STATUS_get_pn_swap(data)                              (0x00000001&(data))

#define  MHL_MD_CTRL                                                            0x1800D608
#define  MHL_MD_CTRL_reg_addr                                                   "0xB800D608"
#define  MHL_MD_CTRL_reg                                                        0xB800D608
#define  MHL_MD_CTRL_inst_addr                                                  "0x0002"
#define  MHL_MD_CTRL_inst                                                       0x0002
#define MHL_MD_CTRL_mhl_mode_err_wd_shift                             (26)
#define MHL_MD_CTRL_mhl_mode_err_int_shift                            (25)
#define MHL_MD_CTRL_mhl_mode_shift                                    (24)
#define MHL_MD_CTRL_mhl_mode_det_per_sel_shift                        (20)
#define MHL_MD_CTRL_mhl_mode_det_per_shift                            (4)
#define MHL_MD_CTRL_mhl_mode_det_shift                                (2)
#define MHL_MD_CTRL_mhl_mode_det_cont_shift                           (1)
#define MHL_MD_CTRL_mhl_mode_det_start_shift                          (0)
#define MHL_MD_CTRL_mhl_mode_err_wd_mask                              (0x04000000)
#define MHL_MD_CTRL_mhl_mode_err_int_mask                             (0x02000000)
#define MHL_MD_CTRL_mhl_mode_mask                                     (0x01000000)
#define MHL_MD_CTRL_mhl_mode_det_per_sel_mask                         (0x00100000)
#define MHL_MD_CTRL_mhl_mode_det_per_mask                             (0x000FFFF0)
#define MHL_MD_CTRL_mhl_mode_det_mask                                 (0x0000000C)
#define MHL_MD_CTRL_mhl_mode_det_cont_mask                            (0x00000002)
#define MHL_MD_CTRL_mhl_mode_det_start_mask                           (0x00000001)
#define MHL_MD_CTRL_mhl_mode_err_wd(data)                             (0x04000000&((data)<<26))
#define MHL_MD_CTRL_mhl_mode_err_int(data)                            (0x02000000&((data)<<25))
#define MHL_MD_CTRL_mhl_mode(data)                                    (0x01000000&((data)<<24))
#define MHL_MD_CTRL_mhl_mode_det_per_sel(data)                        (0x00100000&((data)<<20))
#define MHL_MD_CTRL_mhl_mode_det_per(data)                            (0x000FFFF0&((data)<<4))
#define MHL_MD_CTRL_mhl_mode_det(data)                                (0x0000000C&((data)<<2))
#define MHL_MD_CTRL_mhl_mode_det_cont(data)                           (0x00000002&((data)<<1))
#define MHL_MD_CTRL_mhl_mode_det_start(data)                          (0x00000001&(data))
#define MHL_MD_CTRL_get_mhl_mode_err_wd(data)                         ((0x04000000&(data))>>26)
#define MHL_MD_CTRL_get_mhl_mode_err_int(data)                        ((0x02000000&(data))>>25)
#define MHL_MD_CTRL_get_mhl_mode(data)                                ((0x01000000&(data))>>24)
#define MHL_MD_CTRL_get_mhl_mode_det_per_sel(data)                    ((0x00100000&(data))>>20)
#define MHL_MD_CTRL_get_mhl_mode_det_per(data)                        ((0x000FFFF0&(data))>>4)
#define MHL_MD_CTRL_get_mhl_mode_det(data)                            ((0x0000000C&(data))>>2)
#define MHL_MD_CTRL_get_mhl_mode_det_cont(data)                       ((0x00000002&(data))>>1)
#define MHL_MD_CTRL_get_mhl_mode_det_start(data)                      (0x00000001&(data))

#define  MHL_MD_THRESHOLD                                                       0x1800D60C
#define  MHL_MD_THRESHOLD_reg_addr                                              "0xB800D60C"
#define  MHL_MD_THRESHOLD_reg                                                   0xB800D60C
#define  MHL_MD_THRESHOLD_inst_addr                                             "0x0003"
#define  MHL_MD_THRESHOLD_inst                                                  0x0003
#define MHL_MD_THRESHOLD_threshold_pp_shift                           (16)
#define MHL_MD_THRESHOLD_threshold_24bits_shift                       (0)
#define MHL_MD_THRESHOLD_threshold_pp_mask                            (0xFFFF0000)
#define MHL_MD_THRESHOLD_threshold_24bits_mask                        (0x0000FFFF)
#define MHL_MD_THRESHOLD_threshold_pp(data)                           (0xFFFF0000&((data)<<16))
#define MHL_MD_THRESHOLD_threshold_24bits(data)                       (0x0000FFFF&(data))
#define MHL_MD_THRESHOLD_get_threshold_pp(data)                       ((0xFFFF0000&(data))>>16)
#define MHL_MD_THRESHOLD_get_threshold_24bits(data)                   (0x0000FFFF&(data))

#define  MHL_MD_CNT                                                             0x1800D610
#define  MHL_MD_CNT_reg_addr                                                    "0xB800D610"
#define  MHL_MD_CNT_reg                                                         0xB800D610
#define  MHL_MD_CNT_inst_addr                                                   "0x0004"
#define  MHL_MD_CNT_inst                                                        0x0004
#define MHL_MD_CNT_det_cnt_pp_shift                                   (16)
#define MHL_MD_CNT_det_cnt_24bit_shift                                (0)
#define MHL_MD_CNT_det_cnt_pp_mask                                    (0xFFFF0000)
#define MHL_MD_CNT_det_cnt_24bit_mask                                 (0x0000FFFF)
#define MHL_MD_CNT_det_cnt_pp(data)                                   (0xFFFF0000&((data)<<16))
#define MHL_MD_CNT_det_cnt_24bit(data)                                (0x0000FFFF&(data))
#define MHL_MD_CNT_get_det_cnt_pp(data)                               ((0xFFFF0000&(data))>>16)
#define MHL_MD_CNT_get_det_cnt_24bit(data)                            (0x0000FFFF&(data))

#define  MHL_DEMUX_CTRL                                                         0x1800D614
#define  MHL_DEMUX_CTRL_reg_addr                                                "0xB800D614"
#define  MHL_DEMUX_CTRL_reg                                                     0xB800D614
#define  MHL_DEMUX_CTRL_inst_addr                                               "0x0005"
#define  MHL_DEMUX_CTRL_inst                                                    0x0005
#define MHL_DEMUX_CTRL_video_wd_en_shift                              (12)
#define MHL_DEMUX_CTRL_audio_wd_en_shift                              (11)
#define MHL_DEMUX_CTRL_ch_bound_chg_wd_en_shift                       (10)
#define MHL_DEMUX_CTRL_ch_bound_chg_int_en_shift                      (9)
#define MHL_DEMUX_CTRL_ch_bound_chg_det_shift                         (8)
#define MHL_DEMUX_CTRL_demux_sel_shift                                (4)
#define MHL_DEMUX_CTRL_dvi_ch_sync_shift                              (3)
#define MHL_DEMUX_CTRL_mhl_pp_en_shift                                (1)
#define MHL_DEMUX_CTRL_mhl_en_shift                                   (0)
#define MHL_DEMUX_CTRL_video_wd_en_mask                               (0x00001000)
#define MHL_DEMUX_CTRL_audio_wd_en_mask                               (0x00000800)
#define MHL_DEMUX_CTRL_ch_bound_chg_wd_en_mask                        (0x00000400)
#define MHL_DEMUX_CTRL_ch_bound_chg_int_en_mask                       (0x00000200)
#define MHL_DEMUX_CTRL_ch_bound_chg_det_mask                          (0x00000100)
#define MHL_DEMUX_CTRL_demux_sel_mask                                 (0x00000070)
#define MHL_DEMUX_CTRL_dvi_ch_sync_mask                               (0x00000008)
#define MHL_DEMUX_CTRL_mhl_pp_en_mask                                 (0x00000002)
#define MHL_DEMUX_CTRL_mhl_en_mask                                    (0x00000001)
#define MHL_DEMUX_CTRL_video_wd_en(data)                              (0x00001000&((data)<<12))
#define MHL_DEMUX_CTRL_audio_wd_en(data)                              (0x00000800&((data)<<11))
#define MHL_DEMUX_CTRL_ch_bound_chg_wd_en(data)                       (0x00000400&((data)<<10))
#define MHL_DEMUX_CTRL_ch_bound_chg_int_en(data)                      (0x00000200&((data)<<9))
#define MHL_DEMUX_CTRL_ch_bound_chg_det(data)                         (0x00000100&((data)<<8))
#define MHL_DEMUX_CTRL_demux_sel(data)                                (0x00000070&((data)<<4))
#define MHL_DEMUX_CTRL_dvi_ch_sync(data)                              (0x00000008&((data)<<3))
#define MHL_DEMUX_CTRL_mhl_pp_en(data)                                (0x00000002&((data)<<1))
#define MHL_DEMUX_CTRL_mhl_en(data)                                   (0x00000001&(data))
#define MHL_DEMUX_CTRL_get_video_wd_en(data)                          ((0x00001000&(data))>>12)
#define MHL_DEMUX_CTRL_get_audio_wd_en(data)                          ((0x00000800&(data))>>11)
#define MHL_DEMUX_CTRL_get_ch_bound_chg_wd_en(data)                   ((0x00000400&(data))>>10)
#define MHL_DEMUX_CTRL_get_ch_bound_chg_int_en(data)                  ((0x00000200&(data))>>9)
#define MHL_DEMUX_CTRL_get_ch_bound_chg_det(data)                     ((0x00000100&(data))>>8)
#define MHL_DEMUX_CTRL_get_demux_sel(data)                            ((0x00000070&(data))>>4)
#define MHL_DEMUX_CTRL_get_dvi_ch_sync(data)                          ((0x00000008&(data))>>3)
#define MHL_DEMUX_CTRL_get_mhl_pp_en(data)                            ((0x00000002&(data))>>1)
#define MHL_DEMUX_CTRL_get_mhl_en(data)                               (0x00000001&(data))

#define  MHL_STATUS                                                             0x1800D618
#define  MHL_STATUS_reg_addr                                                    "0xB800D618"
#define  MHL_STATUS_reg                                                         0xB800D618
#define  MHL_STATUS_inst_addr                                                   "0x0006"
#define  MHL_STATUS_inst                                                        0x0006
#define MHL_STATUS_ch_bound_chg_shift                                 (12)
#define MHL_STATUS_mhl_mode_err_shift                                 (8)
#define MHL_STATUS_non_ctrl_glitch_occ_flag_shift                     (5)
#define MHL_STATUS_ctrl_glitch_occr_flag_shift                        (4)
#define MHL_STATUS_mhl_tran_err_flag_shift                            (2)
#define MHL_STATUS_mhl_pos_de_err_flag_shift                          (1)
#define MHL_STATUS_mhl_neg_de_err_flag_shift                          (0)
#define MHL_STATUS_ch_bound_chg_mask                                  (0x00001000)
#define MHL_STATUS_mhl_mode_err_mask                                  (0x00000100)
#define MHL_STATUS_non_ctrl_glitch_occ_flag_mask                      (0x00000020)
#define MHL_STATUS_ctrl_glitch_occr_flag_mask                         (0x00000010)
#define MHL_STATUS_mhl_tran_err_flag_mask                             (0x00000004)
#define MHL_STATUS_mhl_pos_de_err_flag_mask                           (0x00000002)
#define MHL_STATUS_mhl_neg_de_err_flag_mask                           (0x00000001)
#define MHL_STATUS_ch_bound_chg(data)                                 (0x00001000&((data)<<12))
#define MHL_STATUS_mhl_mode_err(data)                                 (0x00000100&((data)<<8))
#define MHL_STATUS_non_ctrl_glitch_occ_flag(data)                     (0x00000020&((data)<<5))
#define MHL_STATUS_ctrl_glitch_occr_flag(data)                        (0x00000010&((data)<<4))
#define MHL_STATUS_mhl_tran_err_flag(data)                            (0x00000004&((data)<<2))
#define MHL_STATUS_mhl_pos_de_err_flag(data)                          (0x00000002&((data)<<1))
#define MHL_STATUS_mhl_neg_de_err_flag(data)                          (0x00000001&(data))
#define MHL_STATUS_get_ch_bound_chg(data)                             ((0x00001000&(data))>>12)
#define MHL_STATUS_get_mhl_mode_err(data)                             ((0x00000100&(data))>>8)
#define MHL_STATUS_get_non_ctrl_glitch_occ_flag(data)                 ((0x00000020&(data))>>5)
#define MHL_STATUS_get_ctrl_glitch_occr_flag(data)                    ((0x00000010&(data))>>4)
#define MHL_STATUS_get_mhl_tran_err_flag(data)                        ((0x00000004&(data))>>2)
#define MHL_STATUS_get_mhl_pos_de_err_flag(data)                      ((0x00000002&(data))>>1)
#define MHL_STATUS_get_mhl_neg_de_err_flag(data)                      (0x00000001&(data))

#define  MHL_CH_CR                                                              0x1800D61C
#define  MHL_CH_CR_reg_addr                                                     "0xB800D61C"
#define  MHL_CH_CR_reg                                                          0xB800D61C
#define  MHL_CH_CR_inst_addr                                                    "0x0007"
#define  MHL_CH_CR_inst                                                         0x0007
#define  MHL_CH_CR_mhl_ch1_cr_flush_shift                                       (17)
#define  MHL_CH_CR_mhl_ch1_cr_afifo_en_shift                                    (16)
#define  MHL_CH_CR_dummy_shift                                                  (2)
#define  MHL_CH_CR_mhl_ch0_cr_flush_shift                                       (1)
#define  MHL_CH_CR_mhl_ch0_cr_afifo_en_shift                                    (0)
#define  MHL_CH_CR_mhl_ch1_cr_flush_mask                                        (0x00020000)
#define  MHL_CH_CR_mhl_ch1_cr_afifo_en_mask                                     (0x00010000)
#define  MHL_CH_CR_dummy_mask                                                   (0x0000FFFC)
#define  MHL_CH_CR_mhl_ch0_cr_flush_mask                                        (0x00000002)
#define  MHL_CH_CR_mhl_ch0_cr_afifo_en_mask                                     (0x00000001)
#define  MHL_CH_CR_mhl_ch1_cr_flush(data)                                       (0x00020000&((data)<<17))
#define  MHL_CH_CR_mhl_ch1_cr_afifo_en(data)                                    (0x00010000&((data)<<16))
#define  MHL_CH_CR_dummy(data)                                                  (0x0000FFFC&((data)<<2))
#define  MHL_CH_CR_mhl_ch0_cr_flush(data)                                       (0x00000002&((data)<<1))
#define  MHL_CH_CR_mhl_ch0_cr_afifo_en(data)                                    (0x00000001&(data))
#define  MHL_CH_CR_get_mhl_ch1_cr_flush(data)                                   ((0x00020000&(data))>>17)
#define  MHL_CH_CR_get_mhl_ch1_cr_afifo_en(data)                                ((0x00010000&(data))>>16)
#define  MHL_CH_CR_get_dummy(data)                                              ((0x0000FFFC&(data))>>2)
#define  MHL_CH_CR_get_mhl_ch0_cr_flush(data)                                   ((0x00000002&(data))>>1)
#define  MHL_CH_CR_get_mhl_ch0_cr_afifo_en(data)                                (0x00000001&(data))

#define  MHL_CH_SR                                                              0x1800D620
#define  MHL_CH_SR_reg_addr                                                     "0xB800D620"
#define  MHL_CH_SR_reg                                                          0xB800D620
#define  MHL_CH_SR_inst_addr                                                    "0x0008"
#define  MHL_CH_SR_inst                                                         0x0008
#define  MHL_CH_SR_mhl_ch1_sr_wrclk_det_timeout_flag_shift                      (20)
#define  MHL_CH_SR_mhl_ch1_sr_rwclk_det_timeout_flag_shift                      (19)
#define  MHL_CH_SR_mhl_ch1_sr_wovflow_flag_shift                                (18)
#define  MHL_CH_SR_mhl_ch1_sr_rudflow_flag_shift                                (17)
#define  MHL_CH_SR_mhl_ch1_sr_rflush_flag_shift                                 (16)
#define  MHL_CH_SR_dummy_shift                                                  (5)
#define  MHL_CH_SR_mhl_ch0_sr_wrclk_det_timeout_flag_shift                      (4)
#define  MHL_CH_SR_mhl_ch0_sr_rwclk_det_timeout_flag_shift                      (3)
#define  MHL_CH_SR_mhl_ch0_sr_wovflow_flag_shift                                (2)
#define  MHL_CH_SR_mhl_ch0_sr_rudflow_flag_shift                                (1)
#define  MHL_CH_SR_mhl_ch0_sr_rflush_flag_shift                                 (0)
#define  MHL_CH_SR_mhl_ch1_sr_wrclk_det_timeout_flag_mask                       (0x00100000)
#define  MHL_CH_SR_mhl_ch1_sr_rwclk_det_timeout_flag_mask                       (0x00080000)
#define  MHL_CH_SR_mhl_ch1_sr_wovflow_flag_mask                                 (0x00040000)
#define  MHL_CH_SR_mhl_ch1_sr_rudflow_flag_mask                                 (0x00020000)
#define  MHL_CH_SR_mhl_ch1_sr_rflush_flag_mask                                  (0x00010000)
#define  MHL_CH_SR_dummy_mask                                                   (0x0000FFE0)
#define  MHL_CH_SR_mhl_ch0_sr_wrclk_det_timeout_flag_mask                       (0x00000010)
#define  MHL_CH_SR_mhl_ch0_sr_rwclk_det_timeout_flag_mask                       (0x00000008)
#define  MHL_CH_SR_mhl_ch0_sr_wovflow_flag_mask                                 (0x00000004)
#define  MHL_CH_SR_mhl_ch0_sr_rudflow_flag_mask                                 (0x00000002)
#define  MHL_CH_SR_mhl_ch0_sr_rflush_flag_mask                                  (0x00000001)
#define  MHL_CH_SR_mhl_ch1_sr_wrclk_det_timeout_flag(data)                      (0x00100000&((data)<<20))
#define  MHL_CH_SR_mhl_ch1_sr_rwclk_det_timeout_flag(data)                      (0x00080000&((data)<<19))
#define  MHL_CH_SR_mhl_ch1_sr_wovflow_flag(data)                                (0x00040000&((data)<<18))
#define  MHL_CH_SR_mhl_ch1_sr_rudflow_flag(data)                                (0x00020000&((data)<<17))
#define  MHL_CH_SR_mhl_ch1_sr_rflush_flag(data)                                 (0x00010000&((data)<<16))
#define  MHL_CH_SR_dummy(data)                                                  (0x0000FFE0&((data)<<5))
#define  MHL_CH_SR_mhl_ch0_sr_wrclk_det_timeout_flag(data)                      (0x00000010&((data)<<4))
#define  MHL_CH_SR_mhl_ch0_sr_rwclk_det_timeout_flag(data)                      (0x00000008&((data)<<3))
#define  MHL_CH_SR_mhl_ch0_sr_wovflow_flag(data)                                (0x00000004&((data)<<2))
#define  MHL_CH_SR_mhl_ch0_sr_rudflow_flag(data)                                (0x00000002&((data)<<1))
#define  MHL_CH_SR_mhl_ch0_sr_rflush_flag(data)                                 (0x00000001&(data))
#define  MHL_CH_SR_get_mhl_ch1_sr_wrclk_det_timeout_flag(data)                  ((0x00100000&(data))>>20)
#define  MHL_CH_SR_get_mhl_ch1_sr_rwclk_det_timeout_flag(data)                  ((0x00080000&(data))>>19)
#define  MHL_CH_SR_get_mhl_ch1_sr_wovflow_flag(data)                            ((0x00040000&(data))>>18)
#define  MHL_CH_SR_get_mhl_ch1_sr_rudflow_flag(data)                            ((0x00020000&(data))>>17)
#define  MHL_CH_SR_get_mhl_ch1_sr_rflush_flag(data)                             ((0x00010000&(data))>>16)
#define  MHL_CH_SR_get_dummy(data)                                              ((0x0000FFE0&(data))>>5)
#define  MHL_CH_SR_get_mhl_ch0_sr_wrclk_det_timeout_flag(data)                  ((0x00000010&(data))>>4)
#define  MHL_CH_SR_get_mhl_ch0_sr_rwclk_det_timeout_flag(data)                  ((0x00000008&(data))>>3)
#define  MHL_CH_SR_get_mhl_ch0_sr_wovflow_flag(data)                            ((0x00000004&(data))>>2)
#define  MHL_CH_SR_get_mhl_ch0_sr_rudflow_flag(data)                            ((0x00000002&(data))>>1)
#define  MHL_CH_SR_get_mhl_ch0_sr_rflush_flag(data)                             (0x00000001&(data))

#endif
