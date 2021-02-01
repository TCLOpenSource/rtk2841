/**
* @file rbusPifReg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2011/7/4
* @version 1.1
* @ingroup model_rbus
*
*/

#ifndef _RBUS_PIF_REG_H_
#define _RBUS_PIF_REG_H_

#include "rbus/rbusTypes.h"




// PIF Register Address

#define PIF_LVDS_CTRL0_VADDR                       (0xb802d000)
#define PIF_LVDS_CTRL1_VADDR                       (0xb802d004)
#define PIF_RSDS3_CRC_CTRL_VADDR                   (0xb802d010)
#define PIF_RSDS3_CRC_RESULT_VADDR                 (0xb802d014)
#define PIF_RSDS3_CRC_R_RESULT_VADDR               (0xb802d018)
#define PIF_RSDS3_L_DES_CRC_VADDR                  (0xb802d020)
#define PIF_RSDS3_R_DES_CRC_VADDR                  (0xb802d024)
#define PIF_RSDS3_CRC_ERR_CNT_VADDR                (0xb802d028)
#define PIF_FORCE_BG_AT_DIF_VADDR                  (0xb802d02c)
#define PIF_TCON_CTRL_VADDR                        (0xb802d030)
#define PIF_TCON0_HSE_VADDR                        (0xb802d034)
#define PIF_TCON0_VSE_VADDR                        (0xb802d038)
#define PIF_TCON0_CTRL_VADDR                       (0xb802d03c)
#define PIF_TCON0_ACROSS_LINE_CONTROL3_ACROSS_FRAME_CONTROL_VADDR   (0xb802d040)
#define PIF_TCON0_ACROSS_FRAME_CONTROL_VADDR       (0xb802d044)
#define PIF_TCON1_HSE_VADDR                        (0xb802d048)
#define PIF_TCON1_VSE_VADDR                        (0xb802d04c)
#define PIF_TCON1_CTRL_VADDR                       (0xb802d050)
#define PIF_TCON1_ACROSS_LINE_CONTROL3_ACROSS_FRAME_CONTROL_VADDR   (0xb802d054)
#define PIF_TCON1_ACROSS_FRAME_CONTROL_VADDR       (0xb802d058)
#define PIF_TCON2_HSE_VADDR                        (0xb802d05c)
#define PIF_TCON2_VSE_VADDR                        (0xb802d060)
#define PIF_TCON2_CTRL_VADDR                       (0xb802d064)
#define PIF_TCON2_ACROSS_LINE_CONTROL3_ACROSS_FRAME_CONTROL_VADDR   (0xb802d068)
#define PIF_TCON2_ACROSS_FRAME_CONTROL_VADDR       (0xb802d06c)
#define PIF_TCON3_HSE_VADDR                        (0xb802d070)
#define PIF_TCON3_VSE_VADDR                        (0xb802d074)
#define PIF_TCON3_CTRL_VADDR                       (0xb802d078)
#define PIF_TCON3_ACROSS_LINE_CONTROL3_ACROSS_FRAME_CONTROL_VADDR   (0xb802d07c)
#define PIF_TCON3_ACROSS_FRAME_CONTROL_VADDR       (0xb802d080)
#define PIF_TCON4_HSE_VADDR                        (0xb802d084)
#define PIF_TCON4_VSE_VADDR                        (0xb802d088)
#define PIF_TCON4_CTRL_VADDR                       (0xb802d08c)
#define PIF_TCON4_ACROSS_LINE_CONTROL3_ACROSS_FRAME_CONTROL_VADDR   (0xb802d090)
#define PIF_TCON4_ACROSS_FRAME_CONTROL_VADDR       (0xb802d094)
#define PIF_TCON5_HSE_VADDR                        (0xb802d098)
#define PIF_TCON5_VSE_VADDR                        (0xb802d09c)
#define PIF_TCON5_CTRL_VADDR                       (0xb802d0a0)
#define PIF_TCON5_ACROSS_LINE_CONTROL3_ACROSS_FRAME_CONTROL_VADDR   (0xb802d0a4)
#define PIF_TCON5_ACROSS_FRAME_CONTROL_VADDR       (0xb802d0a8)
#define PIF_TCON6_HSE_VADDR                        (0xb802d0ac)
#define PIF_TCON6_VSE_VADDR                        (0xb802d0b0)
#define PIF_TCON6_CTRL_VADDR                       (0xb802d0b4)
#define PIF_TCON6_ACROSS_LINE_CONTROL3_ACROSS_FRAME_CONTROL_VADDR   (0xb802d0b8)
#define PIF_TCON6_ACROSS_FRAME_CONTROL_VADDR       (0xb802d0bc)
#define PIF_TCON7_HSE_VADDR                        (0xb802d0c0)
#define PIF_TCON7_VSE_VADDR                        (0xb802d0c4)
#define PIF_TCON7_CTRL_VADDR                       (0xb802d0c8)
#define PIF_TCON7_ACROSS_LINE_CONTROL3_ACROSS_FRAME_CONTROL_VADDR   (0xb802d0cc)
#define PIF_TCON7_ACROSS_FRAME_CONTROL_VADDR       (0xb802d0d0)
#define PIF_TCON8_HSE_VADDR                        (0xb802d0d4)
#define PIF_TCON8_VSE_VADDR                        (0xb802d0d8)
#define PIF_TCON8_CTRL_VADDR                       (0xb802d0dc)
#define PIF_TCON8_ACROSS_LINE_CONTROL3_ACROSS_FRAME_CONTROL_VADDR   (0xb802d0e0)
#define PIF_TCON8_ACROSS_FRAME_CONTROL_VADDR       (0xb802d0e4)
#define PIF_TCON9_HSE_VADDR                        (0xb802d0e8)
#define PIF_TCON9_VSE_VADDR                        (0xb802d0ec)
#define PIF_TCON9_CTRL_VADDR                       (0xb802d0f0)
#define PIF_TCON9_ACROSS_LINE_CONTROL3_ACROSS_FRAME_CONTROL_VADDR   (0xb802d0f4)
#define PIF_TCON9_ACROSS_FRAME_CONTROL_VADDR       (0xb802d0f8)
#define PIF_DOUBLE_BUFFER_CTRL0_VADDR              (0xb802d0fc)
#define PIF_TCON10_HSE_VADDR                       (0xb802d100)
#define PIF_TCON10_VSE_VADDR                       (0xb802d104)
#define PIF_TCON10_CTRL_VADDR                      (0xb802d108)
#define PIF_TCON10_ACROSS_LINE_CONTROL3_ACROSS_FRAME_CONTROL_VADDR  (0xb802d10c)
#define PIF_TCON10_ACROSS_FRAME_CONTROL_VADDR      (0xb802d110)
#define PIF_DOUBLE_BUFFER_CTRL1_VADDR              (0xb802d114)
#define PIF_TCON11_HSE_VADDR                       (0xb802d118)
#define PIF_TCON11_VSE_VADDR                       (0xb802d11c)
#define PIF_TCON11_CTRL_VADDR                      (0xb802d120)
#define PIF_TCON11_ACROSS_LINE_CONTROL3_ACROSS_FRAME_CONTROL_VADDR  (0xb802d124)
#define PIF_TCON11_ACROSS_FRAME_CONTROL_VADDR      (0xb802d128)
#define PIF_TCON12_HSE_VADDR                       (0xb802d12c)
#define PIF_TCON12_VSE_VADDR                       (0xb802d130)
#define PIF_TCON12_CTRL_VADDR                      (0xb802d134)
#define PIF_TCON12_ACROSS_LINE_CONTROL3_ACROSS_FRAME_CONTROL_VADDR  (0xb802d138)
#define PIF_TCON12_ACROSS_FRAME_CONTROL_VADDR      (0xb802d13c)
#define PIF_DOUBLE_BUFFER_CTRL2_VADDR              (0xb802d140)
#define PIF_TCON13_HSE_VADDR                       (0xb802d144)
#define PIF_TCON13_VSE_VADDR                       (0xb802d148)
#define PIF_TCON13_CTRL_VADDR                      (0xb802d14c)
#define PIF_TCON13_ACROSS_LINE_CONTROL3_ACROSS_FRAME_CONTROL_VADDR  (0xb802d150)
#define PIF_TCON13_ACROSS_FRAME_CONTROL_VADDR      (0xb802d154)
#define PIF_TCON14_HSE_VADDR                       (0xb802d158)
#define PIF_TCON14_VSE_VADDR                       (0xb802d15c)
#define PIF_TCON14_CTRL_VADDR                      (0xb802d160)
#define PIF_TCON14_ACROSS_LINE_CONTROL3_ACROSS_FRAME_CONTROL_VADDR  (0xb802d164)
#define PIF_TCON14_ACROSS_FRAME_CONTROL_VADDR      (0xb802d168)
#define PIF_TCON15_HSE_VADDR                       (0xb802d16c)
#define PIF_TCON15_VSE_VADDR                       (0xb802d170)
#define PIF_TCON15_CTRL_VADDR                      (0xb802d174)
#define PIF_TCON15_ACROSS_LINE_CONTROL3_ACROSS_FRAME_CONTROL_VADDR  (0xb802d178)
#define PIF_TCON15_ACROSS_FRAME_CONTROL_VADDR      (0xb802d17c)
#define PIF_TCON16_HSE_VADDR                       (0xb802d180)
#define PIF_TCON16_VSE_VADDR                       (0xb802d184)
#define PIF_TCON16_CTRL_VADDR                      (0xb802d188)
#define PIF_TCON16_ACROSS_LINE_CONTROL3_ACROSS_FRAME_CONTROL_VADDR  (0xb802d18c)
#define PIF_TCON16_ACROSS_FRAME_CONTROL_VADDR      (0xb802d190)
#define PIF_TCON17_HSE_VADDR                       (0xb802d194)
#define PIF_TCON17_VSE_VADDR                       (0xb802d198)
#define PIF_TCON17_CTRL_VADDR                      (0xb802d19c)
#define PIF_TCON17_ACROSS_LINE_CONTROL3_ACROSS_FRAME_CONTROL_VADDR  (0xb802d1a0)
#define PIF_TCON17_ACROSS_FRAME_CONTROL_VADDR      (0xb802d1a4)
#define PIF_TCON18_HSE_VADDR                       (0xb802d1a8)
#define PIF_TCON18_VSE_VADDR                       (0xb802d1ac)
#define PIF_TCON18_CTRL_VADDR                      (0xb802d1b0)
#define PIF_TCON18_ACROSS_LINE_CONTROL3_ACROSS_FRAME_CONTROL_VADDR  (0xb802d1b4)
#define PIF_TCON18_ACROSS_FRAME_CONTROL_VADDR      (0xb802d1b8)
#define PIF_TCON19_HSE_VADDR                       (0xb802d1bc)
#define PIF_TCON19_VSE_VADDR                       (0xb802d1c0)
#define PIF_TCON19_CTRL_VADDR                      (0xb802d1c4)
#define PIF_TCON19_ACROSS_LINE_CONTROL3_ACROSS_FRAME_CONTROL_VADDR  (0xb802d1c8)
#define PIF_TCON19_ACROSS_FRAME_CONTROL_VADDR      (0xb802d1cc)
#define PIF_MLVDS_CTRL0_VADDR                      (0xb802d200)
#define PIF_MLVDS_CTRL1_VADDR                      (0xb802d204)
#define PIF_MLVDS_CTRL2_VADDR                      (0xb802d208)
#define PIF_PATTERN_DETECT_WINDOW_H_INITIAL_START_WIDTH_VADDR       (0xb802d20c)
#define PIF_PATTERN_DETECT_WINDOW_V_INITIAL_START_HEIGHT_VADDR      (0xb802d210)
#define PIF_PATTERN_DETECT_CTRL_VADDR              (0xb802d214)
#define PIF_PAT_DET_SUM1_VADDR                     (0xb802d218)
#define PIF_PAT_DET_SUM2_VADDR                     (0xb802d21c)
#define PIF_PAT_DET_SUM3_VADDR                     (0xb802d220)
#define PIF_PAT_DET_SUM4_VADDR                     (0xb802d224)
#define PIF_PAT_DET_SUM5_VADDR                     (0xb802d228)
#define PIF_PAT_DET_SUM6_VADDR                     (0xb802d22c)
#define PIF_PAT_DET_SUM7_VADDR                     (0xb802d230)
#define PIF_PAT_DET_SUM8_VADDR                     (0xb802d234)
#define PIF_PAT_DET_TH1_VADDR                      (0xb802d238)
#define PIF_PAT_DET_TH2_VADDR                      (0xb802d23c)
#define PIF_PAT_DET_TH3_VADDR                      (0xb802d240)
#define PIF_PAT_DET_TH4_VADDR                      (0xb802d244)
#define PIF_PAT_DET_TH5_VADDR                      (0xb802d248)
#define PIF_PAT_DET_TH6_VADDR                      (0xb802d24c)
#define PIF_PAT_DET_TH7_VADDR                      (0xb802d250)
#define PIF_PAT_DET_TH8_VADDR                      (0xb802d254)
#define PIF_TCON0_NO_SSCG_SE_VADDR                 (0xb802d260)
#define PIF_TCON1_NO_SSCG_SE_VADDR                 (0xb802d264)
#define PIF_TCON2_NO_SSCG_SE_VADDR                 (0xb802d268)
#define PIF_TCON3_NO_SSCG_SE_VADDR                 (0xb802d26c)
#define PIF_TCON4_NO_SSCG_SE_VADDR                 (0xb802d270)
#define PIF_TCON5_NO_SSCG_SE_VADDR                 (0xb802d274)
#define PIF_TCON6_NO_SSCG_SE_VADDR                 (0xb802d278)
#define PIF_TCON7_NO_SSCG_SE_VADDR                 (0xb802d27c)
#define PIF_TCON8_NO_SSCG_SE_VADDR                 (0xb802d280)
#define PIF_TCON9_NO_SSCG_SE_VADDR                 (0xb802d284)
#define PIF_TCON10_NO_SSCG_SE_VADDR                (0xb802d288)
#define PIF_TCON11_NO_SSCG_SE_VADDR                (0xb802d28c)
#define PIF_TCON12_NO_SSCG_SE_VADDR                (0xb802d290)
#define PIF_TCON13_NO_SSCG_SE_VADDR                (0xb802d294)
#define PIF_TCON14_NO_SSCG_SE_VADDR                (0xb802d298)
#define PIF_TCON15_NO_SSCG_SE_VADDR                (0xb802d29c)
#define PIF_TCON16_NO_SSCG_SE_VADDR                (0xb802d2a0)
#define PIF_TCON17_NO_SSCG_SE_VADDR                (0xb802d2a4)
#define PIF_TCON18_NO_SSCG_SE_VADDR                (0xb802d2a8)
#define PIF_TCON19_NO_SSCG_SE_VADDR                (0xb802d2ac)




#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======PIF register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  zz_shift_last_sel_odd:2;
        RBus_UInt32  zz_shift_last_sel_even:2;
        RBus_UInt32  zz_shift_1st_sel_odd:2;
        RBus_UInt32  zz_shift_1st_sel_even:2;
        RBus_UInt32  zz_shift_sp_odd:2;
        RBus_UInt32  zz_shift_sp_even:2;
        RBus_UInt32  zz_shift_mode_odd:1;
        RBus_UInt32  zz_shift_mode_even:1;
        RBus_UInt32  dout_pre_rb_swap:1;
        RBus_UInt32  rsds_dummy:6;
        RBus_UInt32  lvds_pn_swap:1;
        RBus_UInt32  lvds_mirror:1;
        RBus_UInt32  lvds_map:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  ttl_en:1;
        RBus_UInt32  force_bg_dif_aport:1;
        RBus_UInt32  force_bg_dif_bport:1;
        RBus_UInt32  lvds_aport_en:1;
        RBus_UInt32  lvds_bport_en:1;
    };
}lvds_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_arsv1_sel:3;
        RBus_UInt32  lvds_arsv0_sel:3;
        RBus_UInt32  lvds_aden_sel:3;
        RBus_UInt32  lvds_avs_sel:3;
        RBus_UInt32  lvds_ahs_sel:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  lvds_brsv1_sel:3;
        RBus_UInt32  lvds_brsv0_sel:3;
        RBus_UInt32  lvds_bden_sel:3;
        RBus_UInt32  lvds_bvs_sel:3;
        RBus_UInt32  lvds_bhs_sel:3;
        RBus_UInt32  res2:1;
    };
}lvds_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  rsds3_crc_mode:1;
        RBus_UInt32  rsds3_crc_l_auto_cmp_en:1;
        RBus_UInt32  rsds3_crc_r_auto_cmp_en:1;
        RBus_UInt32  rsds3_crc_conti:1;
        RBus_UInt32  rsds3_crc_start:1;
    };
}rsds3_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rsds3_crc_result_0:32;
    };
}rsds3_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rsds3_crc_result_1:32;
    };
}rsds3_crc_r_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rsds3_l_des_crc:32;
    };
}rsds3_l_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rsds3_r_des_crc:32;
    };
}rsds3_r_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rsds3_l_crc_err_cnt:16;
        RBus_UInt32  rsds3_r_crc_err_cnt:16;
    };
}rsds3_crc_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  en_force_bg_dif:1;
        RBus_UInt32  range_force_bg_dif:1;
        RBus_UInt32  bg_dif_red:10;
        RBus_UInt32  bg_dif_grn:10;
        RBus_UInt32  bg_dif_blu:10;
    };
}force_bg_at_dif_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon19:1;
        RBus_UInt32  tcon18:1;
        RBus_UInt32  tcon17:1;
        RBus_UInt32  tcon16:1;
        RBus_UInt32  tcon15:1;
        RBus_UInt32  tcon14:1;
        RBus_UInt32  tcon13:1;
        RBus_UInt32  tcon12:1;
        RBus_UInt32  tcon11:1;
        RBus_UInt32  tcon10:1;
        RBus_UInt32  tcon9:1;
        RBus_UInt32  tcon8:1;
        RBus_UInt32  tcon7:1;
        RBus_UInt32  tcon6:1;
        RBus_UInt32  tcon5:1;
        RBus_UInt32  tcon4:1;
        RBus_UInt32  tcon3:1;
        RBus_UInt32  tcon2:1;
        RBus_UInt32  tcon1:1;
        RBus_UInt32  tcon0:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon_no_sscg_clk_sel:1;
        RBus_UInt32  tcon_sel_l_flag_delay:5;
        RBus_UInt32  tcon_across_frame_en:1;
        RBus_UInt32  tcon_en:1;
    };
}tcon_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon0_hstart:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon0_hend:13;
    };
}tcon0_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon0_vstart:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon0_vend:12;
    };
}tcon0_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  tcon0_sel:1;
        RBus_UInt32  tcon0_no_sscg_inv:1;
        RBus_UInt32  tcon0_l_flag_sel:3;
        RBus_UInt32  tcon0_frame_inv:1;
        RBus_UInt32  tcon0_across_ctrl3_reset:1;
        RBus_UInt32  tcon0_ctl_10_8:3;
        RBus_UInt32  tcon0_ctl_7:1;
        RBus_UInt32  tcon0_ctl_6:1;
        RBus_UInt32  tcon0_ctl_5:1;
        RBus_UInt32  tcon0_ctl_4:1;
        RBus_UInt32  tcon0_ctl_3:1;
        RBus_UInt32  tcon0_ctl_2_0:3;
    };
}tcon0_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon0_across_frame_int:1;
        RBus_UInt32  tcon0_across_ctrl3_rp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon0_across_ctrl3_hp:12;
    };
}tcon0_across_line_control3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon0_frame_offset:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon0_frame_period:12;
    };
}tcon0_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon1_hstart:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon1_hend:13;
    };
}tcon1_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon1_vstart:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon1_vend:12;
    };
}tcon1_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  tcon1_sel:1;
        RBus_UInt32  tcon1_no_sscg_inv:1;
        RBus_UInt32  tcon1_no_sscg_tog_rst:1;
        RBus_UInt32  tcon1_no_sscg_tog_en:1;
        RBus_UInt32  tcon1_no_sscg_ctl:3;
        RBus_UInt32  tcon1_l_flag_sel:3;
        RBus_UInt32  tcon1_frame_inv:1;
        RBus_UInt32  tcon1_across_ctrl3_reset:1;
        RBus_UInt32  tcon1_ctl_10_8:3;
        RBus_UInt32  tcon1_ctl_7:1;
        RBus_UInt32  tcon1_ctl_6:1;
        RBus_UInt32  tcon1_ctl_5:1;
        RBus_UInt32  tcon1_ctl_4:1;
        RBus_UInt32  tcon1_ctl_3:1;
        RBus_UInt32  tcon1_ctl_2_0:3;
    };
}tcon1_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon1_across_frame_int:1;
        RBus_UInt32  tcon1_across_ctrl3_rp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon1_across_ctrl3_hp:12;
    };
}tcon1_across_line_control3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon1_frame_offset:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon1_frame_period:12;
    };
}tcon1_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon2_hstart:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon2_hend:13;
    };
}tcon2_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon2_vstart:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon2_vend:12;
    };
}tcon2_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  tcon2_sel:1;
        RBus_UInt32  tcon2_no_sscg_inv:1;
        RBus_UInt32  tcon2_no_sscg_tog_rst:1;
        RBus_UInt32  tcon2_no_sscg_tog_en:1;
        RBus_UInt32  tcon2_no_sscg_ctl:3;
        RBus_UInt32  tcon2_l_flag_sel:3;
        RBus_UInt32  tcon2_frame_inv:1;
        RBus_UInt32  tcon2_across_ctrl3_reset:1;
        RBus_UInt32  tcon2_ctl_10_8:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  tcon2_dot_mask_2:1;
        RBus_UInt32  tcon2_dot_mask_1:1;
        RBus_UInt32  tcon2_dot_mask_0:1;
        RBus_UInt32  tcon2_ctl_7:1;
        RBus_UInt32  tcon2_ctl_6:1;
        RBus_UInt32  tcon2_ctl_5:1;
        RBus_UInt32  tcon2_ctl_4:1;
        RBus_UInt32  tcon2_ctl_3:1;
        RBus_UInt32  tcon2_ctl_2_0:3;
    };
}tcon2_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon2_across_frame_int:1;
        RBus_UInt32  tcon2_across_ctrl3_rp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon2_across_ctrl3_hp:12;
    };
}tcon2_across_line_control3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon2_frame_offset:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon2_frame_period:12;
    };
}tcon2_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon3_hstart:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon3_hend:13;
    };
}tcon3_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon3_vstart:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon3_vend:12;
    };
}tcon3_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  tcon3_sel:1;
        RBus_UInt32  tcon3_no_sscg_inv:1;
        RBus_UInt32  tcon3_no_sscg_tog_rst:1;
        RBus_UInt32  tcon3_no_sscg_tog_en:1;
        RBus_UInt32  tcon3_no_sscg_ctl:3;
        RBus_UInt32  tcon3_l_flag_sel:3;
        RBus_UInt32  tcon3_frame_inv:1;
        RBus_UInt32  tcon3_across_ctrl3_reset:1;
        RBus_UInt32  tcon3_ctl_10_8:3;
        RBus_UInt32  tcon3_ctl_7:1;
        RBus_UInt32  tcon3_ctl_6:1;
        RBus_UInt32  tcon3_ctl_5:1;
        RBus_UInt32  tcon3_ctl_4:1;
        RBus_UInt32  tcon3_ctl_3:1;
        RBus_UInt32  tcon3_ctl_2_0:3;
    };
}tcon3_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon3_across_frame_int:1;
        RBus_UInt32  tcon3_across_ctrl3_rp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon3_across_ctrl3_hp:12;
    };
}tcon3_across_line_control3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon3_frame_offset:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon3_frame_period:12;
    };
}tcon3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon4_hstart:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon4_hend:13;
    };
}tcon4_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon4_vstart:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon4_vend:12;
    };
}tcon4_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  tcon4_sel:1;
        RBus_UInt32  tcon4_no_sscg_inv:1;
        RBus_UInt32  tcon4_no_sscg_tog_rst:1;
        RBus_UInt32  tcon4_no_sscg_tog_en:1;
        RBus_UInt32  tcon4_no_sscg_ctl:3;
        RBus_UInt32  tcon4_l_flag_sel:3;
        RBus_UInt32  tcon4_frame_inv:1;
        RBus_UInt32  tcon4_across_ctrl3_reset:1;
        RBus_UInt32  tcon4_ctl_10_8:3;
        RBus_UInt32  tcon4_ctl_7:1;
        RBus_UInt32  tcon4_ctl_6:1;
        RBus_UInt32  tcon4_ctl_5:1;
        RBus_UInt32  tcon4_ctl_4:1;
        RBus_UInt32  tcon4_ctl_3:1;
        RBus_UInt32  tcon4_ctl_2_0:3;
    };
}tcon4_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon4_across_frame_int:1;
        RBus_UInt32  tcon4_across_ctrl3_rp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon4_across_ctrl3_hp:12;
    };
}tcon4_across_line_control3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon4_frame_offset:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon4_frame_period:12;
    };
}tcon4_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon5_hstart:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon5_hend:13;
    };
}tcon5_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon5_vstart:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon5_vend:12;
    };
}tcon5_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  tcon5_sel:1;
        RBus_UInt32  tcon5_no_sscg_inv:1;
        RBus_UInt32  tcon5_no_sscg_tog_rst:1;
        RBus_UInt32  tcon5_no_sscg_tog_en:1;
        RBus_UInt32  tcon5_no_sscg_ctl:3;
        RBus_UInt32  tcon5_l_flag_sel:3;
        RBus_UInt32  tcon5_frame_inv:1;
        RBus_UInt32  tcon5_across_ctrl3_reset:1;
        RBus_UInt32  tcon5_ctl_10_8:3;
        RBus_UInt32  tcon5_ctl_7:1;
        RBus_UInt32  tcon5_ctl_6:1;
        RBus_UInt32  tcon5_ctl_5:1;
        RBus_UInt32  tcon5_ctl_4:1;
        RBus_UInt32  tcon5_ctl_3:1;
        RBus_UInt32  tcon5_ctl_2_0:3;
    };
}tcon5_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon5_across_frame_int:1;
        RBus_UInt32  tcon5_across_ctrl3_rp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon5_across_ctrl3_hp:12;
    };
}tcon5_across_line_control3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon5_frame_offset:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon5_frame_period:12;
    };
}tcon5_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon6_hstart:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon6_hend:13;
    };
}tcon6_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon6_vstart:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon6_vend:12;
    };
}tcon6_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  tcon6_sel:1;
        RBus_UInt32  tcon6_no_sscg_inv:1;
        RBus_UInt32  tcon6_no_sscg_tog_rst:1;
        RBus_UInt32  tcon6_no_sscg_tog_en:1;
        RBus_UInt32  tcon6_no_sscg_ctl:3;
        RBus_UInt32  tcon6_l_flag_sel:3;
        RBus_UInt32  tcon6_frame_inv:1;
        RBus_UInt32  tcon6_across_ctrl3_reset:1;
        RBus_UInt32  tcon6_ctl_10_8:3;
        RBus_UInt32  tcon6_ctl_7:1;
        RBus_UInt32  tcon6_ctl_6:1;
        RBus_UInt32  tcon6_ctl_5:1;
        RBus_UInt32  tcon6_ctl_4:1;
        RBus_UInt32  tcon6_ctl_3:1;
        RBus_UInt32  tcon6_ctl_2_0:3;
    };
}tcon6_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon6_across_frame_int:1;
        RBus_UInt32  tcon6_across_ctrl3_rp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon6_across_ctrl3_hp:12;
    };
}tcon6_across_line_control3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon6_frame_offset:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon6_frame_period:12;
    };
}tcon6_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon7_hstart:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon7_hend:13;
    };
}tcon7_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon7_vstart:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon7_vend:12;
    };
}tcon7_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  tcon7_sel:1;
        RBus_UInt32  tcon7_no_sscg_inv:1;
        RBus_UInt32  tcon7_no_sscg_tog_rst:1;
        RBus_UInt32  tcon7_no_sscg_tog_en:1;
        RBus_UInt32  tcon7_no_sscg_ctl:3;
        RBus_UInt32  tcon7_l_flag_sel:3;
        RBus_UInt32  tcon7_frame_inv:1;
        RBus_UInt32  tcon7_across_ctrl3_reset:1;
        RBus_UInt32  tcon7_ctl_10_8:3;
        RBus_UInt32  tcon7_ctl_7:1;
        RBus_UInt32  tcon7_ctl_6:1;
        RBus_UInt32  tcon7_ctl_5:1;
        RBus_UInt32  tcon7_ctl_4:1;
        RBus_UInt32  tcon7_ctl_3:1;
        RBus_UInt32  tcon7_ctl_2_0:3;
    };
}tcon7_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon7_across_frame_int:1;
        RBus_UInt32  tcon7_across_ctrl3_rp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon7_across_ctrl3_hp:12;
    };
}tcon7_across_line_control3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon7_frame_offset:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon7_frame_period:12;
    };
}tcon7_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon8_hstart:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon8_hend:13;
    };
}tcon8_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon8_vstart:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon8_vend:12;
    };
}tcon8_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  tcon8_sel:1;
        RBus_UInt32  tcon8_no_sscg_inv:1;
        RBus_UInt32  tcon8_no_sscg_tog_rst:1;
        RBus_UInt32  tcon8_no_sscg_tog_en:1;
        RBus_UInt32  tcon8_no_sscg_ctl:3;
        RBus_UInt32  tcon8_l_flag_sel:3;
        RBus_UInt32  tcon8_frame_inv:1;
        RBus_UInt32  tcon8_across_ctrl3_reset:1;
        RBus_UInt32  tcon8_ctl_10_8:3;
        RBus_UInt32  tcon8_ctl_7:1;
        RBus_UInt32  tcon8_ctl_6:1;
        RBus_UInt32  tcon8_ctl_5:1;
        RBus_UInt32  tcon8_ctl_4:1;
        RBus_UInt32  tcon8_ctl_3:1;
        RBus_UInt32  tcon8_ctl_2_0:3;
    };
}tcon8_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon8_across_frame_int:1;
        RBus_UInt32  tcon8_across_ctrl3_rp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon8_across_ctrl3_hp:12;
    };
}tcon8_across_line_control3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon8_frame_offset:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon8_frame_period:12;
    };
}tcon8_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon9_hstart:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon9_hend:13;
    };
}tcon9_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon9_vstart:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon9_vend:12;
    };
}tcon9_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  tcon9_sel:1;
        RBus_UInt32  tcon9_no_sscg_inv:1;
        RBus_UInt32  tcon9_no_sscg_tog_rst:1;
        RBus_UInt32  tcon9_no_sscg_tog_en:1;
        RBus_UInt32  tcon9_no_sscg_ctl:3;
        RBus_UInt32  tcon9_l_flag_sel:3;
        RBus_UInt32  tcon9_frame_inv:1;
        RBus_UInt32  tcon9_across_ctrl3_reset:1;
        RBus_UInt32  tcon9_ctl_10_8:3;
        RBus_UInt32  tcon9_ctl_7:1;
        RBus_UInt32  tcon9_ctl_6:1;
        RBus_UInt32  tcon9_ctl_5:1;
        RBus_UInt32  tcon9_ctl_4:1;
        RBus_UInt32  tcon9_ctl_3:1;
        RBus_UInt32  tcon9_ctl_2_0:3;
    };
}tcon9_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon9_across_frame_int:1;
        RBus_UInt32  tcon9_across_ctrl3_rp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon9_across_ctrl3_hp:12;
    };
}tcon9_across_line_control3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon9_frame_offset:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon9_frame_period:12;
    };
}tcon9_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  dreg_dbuf0_en_n:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  dreg_dbuf0_set:1;
    };
}double_buffer_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon10_hstart:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon10_hend:13;
    };
}tcon10_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon10_vstart:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon10_vend:12;
    };
}tcon10_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  tcon10_sel:1;
        RBus_UInt32  tcon10_no_sscg_inv:1;
        RBus_UInt32  tcon10_no_sscg_tog_rst:1;
        RBus_UInt32  tcon10_no_sscg_tog_en:1;
        RBus_UInt32  tcon10_no_sscg_ctl:3;
        RBus_UInt32  tcon10_l_flag_sel:3;
        RBus_UInt32  tcon10_frame_inv:1;
        RBus_UInt32  tcon10_across_ctrl3_reset:1;
        RBus_UInt32  tcon10_ctl_10_8:3;
        RBus_UInt32  tcon10_ctl_7:1;
        RBus_UInt32  tcon10_ctl_6:1;
        RBus_UInt32  tcon10_ctl_5:1;
        RBus_UInt32  tcon10_ctl_4:1;
        RBus_UInt32  tcon10_ctl_3:1;
        RBus_UInt32  tcon10_ctl_2_0:3;
    };
}tcon10_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon10_across_frame_int:1;
        RBus_UInt32  tcon10_across_ctrl3_rp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon10_across_ctrl3_hp:12;
    };
}tcon10_across_line_control3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon10_frame_offset:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon10_frame_period:12;
    };
}tcon10_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  dreg_dbuf1_en_n:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  dreg_dbuf1_set:1;
    };
}double_buffer_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon11_hstart:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon11_hend:13;
    };
}tcon11_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon11_vstart:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon11_vend:12;
    };
}tcon11_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  tcon11_sel:1;
        RBus_UInt32  tcon11_no_sscg_inv:1;
        RBus_UInt32  tcon11_no_sscg_tog_rst:1;
        RBus_UInt32  tcon11_no_sscg_tog_en:1;
        RBus_UInt32  tcon11_no_sscg_ctl:3;
        RBus_UInt32  tcon11_l_flag_sel:3;
        RBus_UInt32  tcon11_frame_inv:1;
        RBus_UInt32  tcon11_across_ctrl3_reset:1;
        RBus_UInt32  tcon11_ctl_10_8:3;
        RBus_UInt32  tcon11_ctl_7:1;
        RBus_UInt32  tcon11_ctl_6:1;
        RBus_UInt32  tcon11_ctl_5:1;
        RBus_UInt32  tcon11_ctl_4:1;
        RBus_UInt32  tcon11_ctl_3:1;
        RBus_UInt32  tcon11_ctl_2_0:3;
    };
}tcon11_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon11_across_frame_int:1;
        RBus_UInt32  tcon11_across_ctrl3_rp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon11_across_ctrl3_hp:12;
    };
}tcon11_across_line_control3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon11_frame_offset:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon11_frame_period:12;
    };
}tcon11_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon12_hstart:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon12_hend:13;
    };
}tcon12_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon12_vstart:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon12_vend:12;
    };
}tcon12_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  tcon12_sel:1;
        RBus_UInt32  tcon12_no_sscg_inv:1;
        RBus_UInt32  tcon12_no_sscg_tog_rst:1;
        RBus_UInt32  tcon12_no_sscg_tog_en:1;
        RBus_UInt32  tcon12_no_sscg_ctl:3;
        RBus_UInt32  tcon12_l_flag_sel:3;
        RBus_UInt32  tcon12_frame_inv:1;
        RBus_UInt32  tcon12_across_ctrl3_reset:1;
        RBus_UInt32  tcon12_ctl_10_8:3;
        RBus_UInt32  tcon12_ctl_7:1;
        RBus_UInt32  tcon12_ctl_6:1;
        RBus_UInt32  tcon12_ctl_5:1;
        RBus_UInt32  tcon12_ctl_4:1;
        RBus_UInt32  tcon12_ctl_3:1;
        RBus_UInt32  tcon12_ctl_2_0:3;
    };
}tcon12_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon12_across_frame_int:1;
        RBus_UInt32  tcon12_across_ctrl3_rp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon12_across_ctrl3_hp:12;
    };
}tcon12_across_line_control3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon12_frame_offset:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon12_frame_period:12;
    };
}tcon12_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  dreg_dbuf2_en_n:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  dreg_dbuf2_set:1;
    };
}double_buffer_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon13_hstart:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon13_hend:13;
    };
}tcon13_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon13_vstart:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon13_vend:12;
    };
}tcon13_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  tcon13_sel:1;
        RBus_UInt32  tcon13_no_sscg_inv:1;
        RBus_UInt32  tcon13_no_sscg_tog_rst:1;
        RBus_UInt32  tcon13_no_sscg_tog_en:1;
        RBus_UInt32  tcon13_no_sscg_ctl:3;
        RBus_UInt32  tcon13_l_flag_sel:3;
        RBus_UInt32  tcon13_frame_inv:1;
        RBus_UInt32  tcon13_across_ctrl3_reset:1;
        RBus_UInt32  tcon13_ctl_10_8:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  tcon13_dot_mask_2:1;
        RBus_UInt32  tcon13_dot_mask_1:1;
        RBus_UInt32  tcon13_dot_mask_0:1;
        RBus_UInt32  tcon13_ctl_7:1;
        RBus_UInt32  tcon13_ctl_6:1;
        RBus_UInt32  tcon13_ctl_5:1;
        RBus_UInt32  tcon13_ctl_4:1;
        RBus_UInt32  tcon13_ctl_3:1;
        RBus_UInt32  tcon13_ctl_2_0:3;
    };
}tcon13_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon13_across_frame_int:1;
        RBus_UInt32  tcon13_across_ctrl3_rp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon13_across_ctrl3_hp:12;
    };
}tcon13_across_line_control3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon13_frame_offset:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon13_frame_period:12;
    };
}tcon13_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon14_hstart:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon14_hend:13;
    };
}tcon14_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon14_vstart:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon14_vend:12;
    };
}tcon14_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  tcon14_sel:1;
        RBus_UInt32  tcon14_no_sscg_inv:1;
        RBus_UInt32  tcon14_no_sscg_tog_rst:1;
        RBus_UInt32  tcon14_no_sscg_tog_en:1;
        RBus_UInt32  tcon14_no_sscg_ctl:3;
        RBus_UInt32  tcon14_l_flag_sel:3;
        RBus_UInt32  tcon14_frame_inv:1;
        RBus_UInt32  tcon14_across_ctrl3_reset:1;
        RBus_UInt32  tcon14_ctl_10_8:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  tcon14_dot_mask_2:1;
        RBus_UInt32  tcon14_dot_mask_1:1;
        RBus_UInt32  tcon14_dot_mask_0:1;
        RBus_UInt32  tcon14_ctl_7:1;
        RBus_UInt32  tcon14_ctl_6:1;
        RBus_UInt32  tcon14_ctl_5:1;
        RBus_UInt32  tcon14_ctl_4:1;
        RBus_UInt32  tcon14_ctl_3:1;
        RBus_UInt32  tcon14_ctl_2_0:3;
    };
}tcon14_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon14_across_frame_int:1;
        RBus_UInt32  tcon14_across_ctrl3_rp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon14_across_ctrl3_hp:12;
    };
}tcon14_across_line_control3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon14_frame_offset:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon14_frame_period:12;
    };
}tcon14_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon15_hstart:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon15_hend:13;
    };
}tcon15_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon15_vstart:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon15_vend:12;
    };
}tcon15_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  tcon15_sel:1;
        RBus_UInt32  tcon15_no_sscg_inv:1;
        RBus_UInt32  tcon15_no_sscg_tog_rst:1;
        RBus_UInt32  tcon15_no_sscg_tog_en:1;
        RBus_UInt32  tcon15_no_sscg_ctl:3;
        RBus_UInt32  tcon15_l_flag_sel:3;
        RBus_UInt32  tcon15_frame_inv:1;
        RBus_UInt32  tcon15_across_ctrl3_reset:1;
        RBus_UInt32  tcon15_ctl_10_8:3;
        RBus_UInt32  tcon15_ctl_7:1;
        RBus_UInt32  tcon15_ctl_6:1;
        RBus_UInt32  tcon15_ctl_5:1;
        RBus_UInt32  tcon15_ctl_4:1;
        RBus_UInt32  tcon15_ctl_3:1;
        RBus_UInt32  tcon15_ctl_2_0:3;
    };
}tcon15_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon15_across_frame_int:1;
        RBus_UInt32  tcon15_across_ctrl3_rp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon15_across_ctrl3_hp:12;
    };
}tcon15_across_line_control3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon15_frame_offset:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon15_frame_period:12;
    };
}tcon15_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon16_hstart:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon16_hend:13;
    };
}tcon16_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon16_vstart:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon16_vend:12;
    };
}tcon16_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  tcon16_sel:1;
        RBus_UInt32  tcon16_no_sscg_inv:1;
        RBus_UInt32  tcon16_no_sscg_tog_rst:1;
        RBus_UInt32  tcon16_no_sscg_tog_en:1;
        RBus_UInt32  tcon16_no_sscg_ctl:3;
        RBus_UInt32  tcon16_l_flag_sel:3;
        RBus_UInt32  tcon16_frame_inv:1;
        RBus_UInt32  tcon16_across_ctrl3_reset:1;
        RBus_UInt32  tcon16_ctl_10_8:3;
        RBus_UInt32  tcon16_ctl_7:1;
        RBus_UInt32  tcon16_ctl_6:1;
        RBus_UInt32  tcon16_ctl_5:1;
        RBus_UInt32  tcon16_ctl_4:1;
        RBus_UInt32  tcon16_ctl_3:1;
        RBus_UInt32  tcon16_ctl_2_0:3;
    };
}tcon16_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon16_across_frame_int:1;
        RBus_UInt32  tcon16_across_ctrl3_rp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon16_across_ctrl3_hp:12;
    };
}tcon16_across_line_control3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon16_frame_offset:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon16_frame_period:12;
    };
}tcon16_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon17_hstart:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon17_hend:13;
    };
}tcon17_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon17_vstart:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon17_vend:12;
    };
}tcon17_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  tcon17_sel:1;
        RBus_UInt32  tcon17_no_sscg_inv:1;
        RBus_UInt32  tcon17_no_sscg_tog_rst:1;
        RBus_UInt32  tcon17_no_sscg_tog_en:1;
        RBus_UInt32  tcon17_no_sscg_ctl:3;
        RBus_UInt32  tcon17_l_flag_sel:3;
        RBus_UInt32  tcon17_frame_inv:1;
        RBus_UInt32  tcon17_across_ctrl3_reset:1;
        RBus_UInt32  tcon17_ctl_10_8:3;
        RBus_UInt32  tcon17_ctl_7:1;
        RBus_UInt32  tcon17_ctl_6:1;
        RBus_UInt32  tcon17_ctl_5:1;
        RBus_UInt32  tcon17_ctl_4:1;
        RBus_UInt32  tcon17_ctl_3:1;
        RBus_UInt32  tcon17_ctl_2_0:3;
    };
}tcon17_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon17_across_frame_int:1;
        RBus_UInt32  tcon17_across_ctrl3_rp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon17_across_ctrl3_hp:12;
    };
}tcon17_across_line_control3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon17_frame_offset:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon17_frame_period:12;
    };
}tcon17_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon18_hstart:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon18_hend:13;
    };
}tcon18_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon18_vstart:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon18_vend:12;
    };
}tcon18_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  tcon18_sel:1;
        RBus_UInt32  tcon18_no_sscg_inv:1;
        RBus_UInt32  tcon18_no_sscg_tog_rst:1;
        RBus_UInt32  tcon18_no_sscg_tog_en:1;
        RBus_UInt32  tcon18_no_sscg_ctl:3;
        RBus_UInt32  tcon18_l_flag_sel:3;
        RBus_UInt32  tcon18_frame_inv:1;
        RBus_UInt32  tcon18_across_ctrl3_reset:1;
        RBus_UInt32  tcon18_ctl_10_8:3;
        RBus_UInt32  tcon18_ctl_7:1;
        RBus_UInt32  tcon18_ctl_6:1;
        RBus_UInt32  tcon18_ctl_5:1;
        RBus_UInt32  tcon18_ctl_4:1;
        RBus_UInt32  tcon18_ctl_3:1;
        RBus_UInt32  tcon18_ctl_2_0:3;
    };
}tcon18_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon18_across_frame_int:1;
        RBus_UInt32  tcon18_across_ctrl3_rp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon18_across_ctrl3_hp:12;
    };
}tcon18_across_line_control3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon18_frame_offset:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon18_frame_period:12;
    };
}tcon18_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon19_hstart:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon19_hend:13;
    };
}tcon19_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon19_vstart:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon19_vend:12;
    };
}tcon19_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  tcon19_sel:1;
        RBus_UInt32  tcon19_no_sscg_inv:1;
        RBus_UInt32  tcon19_no_sscg_tog_rst:1;
        RBus_UInt32  tcon19_no_sscg_tog_en:1;
        RBus_UInt32  tcon19_no_sscg_ctl:3;
        RBus_UInt32  tcon19_l_flag_sel:3;
        RBus_UInt32  tcon19_frame_inv:1;
        RBus_UInt32  tcon19_across_ctrl3_reset:1;
        RBus_UInt32  tcon19_ctl_10_8:3;
        RBus_UInt32  tcon19_ctl_7:1;
        RBus_UInt32  tcon19_ctl_6:1;
        RBus_UInt32  tcon19_ctl_5:1;
        RBus_UInt32  tcon19_ctl_4:1;
        RBus_UInt32  tcon19_ctl_3:1;
        RBus_UInt32  tcon19_ctl_2_0:3;
    };
}tcon19_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon19_across_frame_int:1;
        RBus_UInt32  tcon19_across_ctrl3_rp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon19_across_ctrl3_hp:12;
    };
}tcon19_across_line_control3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon19_frame_offset:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon19_frame_period:12;
    };
}tcon19_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_dh_den_sta_dummy:12;
        RBus_UInt32  pif_dh_den_end_dummy:8;
        RBus_UInt32  mlvds_signle:2;
        RBus_UInt32  mlvds_3_pair_mode:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  mlvds_en:1;
        RBus_UInt32  mlvds_dual:1;
        RBus_UInt32  mlvds_rl_swap:1;
        RBus_UInt32  mlvds_pn_swap:1;
        RBus_UInt32  mlvds_mirror:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  mlvds_mode:1;
    };
}mlvds_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon_sel:8;
        RBus_UInt32  tcon_delay_sel_7:2;
        RBus_UInt32  tcon_delay_sel_6:2;
        RBus_UInt32  tcon_delay_sel_5:2;
        RBus_UInt32  tcon_delay_sel_4:2;
        RBus_UInt32  tcon_delay_sel_3:2;
        RBus_UInt32  tcon_delay_sel_2:2;
        RBus_UInt32  tcon_delay_sel_1:2;
        RBus_UInt32  tcon_delay_sel_0:2;
        RBus_UInt32  mlvds_rst_tcon_en:1;
        RBus_UInt32  mlvds_map_inv:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  mlvds_rst_high:5;
    };
}mlvds_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mlvds_rst_low_region:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  mlvds_rck_inv:1;
        RBus_UInt32  mlvds_lck_inv:1;
        RBus_UInt32  mlvds_rst_low:24;
    };
}mlvds_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  pat_det_h_ini_sta:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  pat_det_width:12;
    };
}pattern_detect_window_h_initial_start_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  pat_det_v_ini_sta:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  pat_det_height:11;
    };
}pattern_detect_window_v_initial_start_height_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  spc_pt_1:1;
        RBus_UInt32  spc_pt_2:1;
        RBus_UInt32  spc_pt_3:1;
        RBus_UInt32  spc_pt_4:1;
        RBus_UInt32  spc_pt_5:1;
        RBus_UInt32  spc_pt_6:1;
        RBus_UInt32  spc_pt_7:1;
        RBus_UInt32  spc_pt_8:1;
        RBus_UInt32  pat_det_mode:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  pat_det_en:1;
        RBus_UInt32  pat_det_auto:1;
    };
}pattern_detect_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sum_line_1:24;
    };
}pat_det_sum1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sum_line_2:24;
    };
}pat_det_sum2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sum_line_3:24;
    };
}pat_det_sum3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sum_line_4:24;
    };
}pat_det_sum4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sum_line_5:24;
    };
}pat_det_sum5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sum_line_6:24;
    };
}pat_det_sum6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sum_line_7:24;
    };
}pat_det_sum7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sum_line_8:24;
    };
}pat_det_sum8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pat_th1:24;
    };
}pat_det_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pat_th2:24;
    };
}pat_det_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pat_th3:24;
    };
}pat_det_th3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pat_th4:24;
    };
}pat_det_th4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pat_th5:24;
    };
}pat_det_th5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pat_th6:24;
    };
}pat_det_th6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pat_th7:24;
    };
}pat_det_th7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pat_th8:24;
    };
}pat_det_th8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon0_no_sscg_start:16;
        RBus_UInt32  tcon0_no_sscg_end:16;
    };
}tcon0_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon1_no_sscg_start:16;
        RBus_UInt32  tcon1_no_sscg_end:16;
    };
}tcon1_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon2_no_sscg_start:16;
        RBus_UInt32  tcon2_no_sscg_end:16;
    };
}tcon2_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon3_no_sscg_start:16;
        RBus_UInt32  tcon3_no_sscg_end:16;
    };
}tcon3_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon4_no_sscg_start:16;
        RBus_UInt32  tcon4_no_sscg_end:16;
    };
}tcon4_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon5_no_sscg_start:16;
        RBus_UInt32  tcon5_no_sscg_end:16;
    };
}tcon5_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon6_no_sscg_start:16;
        RBus_UInt32  tcon6_no_sscg_end:16;
    };
}tcon6_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon7_no_sscg_start:16;
        RBus_UInt32  tcon7_no_sscg_end:16;
    };
}tcon7_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon8_no_sscg_start:16;
        RBus_UInt32  tcon8_no_sscg_end:16;
    };
}tcon8_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon9_no_sscg_start:16;
        RBus_UInt32  tcon9_no_sscg_end:16;
    };
}tcon9_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon10_no_sscg_start:16;
        RBus_UInt32  tcon10_no_sscg_end:16;
    };
}tcon10_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon11_no_sscg_start:16;
        RBus_UInt32  tcon11_no_sscg_end:16;
    };
}tcon11_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon12_no_sscg_start:16;
        RBus_UInt32  tcon12_no_sscg_end:16;
    };
}tcon12_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon13_no_sscg_start:16;
        RBus_UInt32  tcon13_no_sscg_end:16;
    };
}tcon13_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon14_no_sscg_start:16;
        RBus_UInt32  tcon14_no_sscg_end:16;
    };
}tcon14_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon15_no_sscg_start:16;
        RBus_UInt32  tcon15_no_sscg_end:16;
    };
}tcon15_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon16_no_sscg_start:16;
        RBus_UInt32  tcon16_no_sscg_end:16;
    };
}tcon16_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon17_no_sscg_start:16;
        RBus_UInt32  tcon17_no_sscg_end:16;
    };
}tcon17_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon18_no_sscg_start:16;
        RBus_UInt32  tcon18_no_sscg_end:16;
    };
}tcon18_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon19_no_sscg_start:16;
        RBus_UInt32  tcon19_no_sscg_end:16;
    };
}tcon19_no_sscg_se_RBUS;





#else //apply LITTLE_ENDIAN


//======PIF register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_bport_en:1;
        RBus_UInt32  lvds_aport_en:1;
        RBus_UInt32  force_bg_dif_bport:1;
        RBus_UInt32  force_bg_dif_aport:1;
        RBus_UInt32  ttl_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  lvds_map:1;
        RBus_UInt32  lvds_mirror:1;
        RBus_UInt32  lvds_pn_swap:1;
        RBus_UInt32  rsds_dummy:6;
        RBus_UInt32  dout_pre_rb_swap:1;
        RBus_UInt32  zz_shift_mode_even:1;
        RBus_UInt32  zz_shift_mode_odd:1;
        RBus_UInt32  zz_shift_sp_even:2;
        RBus_UInt32  zz_shift_sp_odd:2;
        RBus_UInt32  zz_shift_1st_sel_even:2;
        RBus_UInt32  zz_shift_1st_sel_odd:2;
        RBus_UInt32  zz_shift_last_sel_even:2;
        RBus_UInt32  zz_shift_last_sel_odd:2;
    };
}lvds_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:1;
        RBus_UInt32  lvds_bhs_sel:3;
        RBus_UInt32  lvds_bvs_sel:3;
        RBus_UInt32  lvds_bden_sel:3;
        RBus_UInt32  lvds_brsv0_sel:3;
        RBus_UInt32  lvds_brsv1_sel:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  lvds_ahs_sel:3;
        RBus_UInt32  lvds_avs_sel:3;
        RBus_UInt32  lvds_aden_sel:3;
        RBus_UInt32  lvds_arsv0_sel:3;
        RBus_UInt32  lvds_arsv1_sel:3;
    };
}lvds_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rsds3_crc_start:1;
        RBus_UInt32  rsds3_crc_conti:1;
        RBus_UInt32  rsds3_crc_r_auto_cmp_en:1;
        RBus_UInt32  rsds3_crc_l_auto_cmp_en:1;
        RBus_UInt32  rsds3_crc_mode:1;
        RBus_UInt32  res1:27;
    };
}rsds3_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rsds3_crc_result_0:32;
    };
}rsds3_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rsds3_crc_result_1:32;
    };
}rsds3_crc_r_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rsds3_l_des_crc:32;
    };
}rsds3_l_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rsds3_r_des_crc:32;
    };
}rsds3_r_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rsds3_r_crc_err_cnt:16;
        RBus_UInt32  rsds3_l_crc_err_cnt:16;
    };
}rsds3_crc_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bg_dif_blu:10;
        RBus_UInt32  bg_dif_grn:10;
        RBus_UInt32  bg_dif_red:10;
        RBus_UInt32  range_force_bg_dif:1;
        RBus_UInt32  en_force_bg_dif:1;
    };
}force_bg_at_dif_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon_en:1;
        RBus_UInt32  tcon_across_frame_en:1;
        RBus_UInt32  tcon_sel_l_flag_delay:5;
        RBus_UInt32  tcon_no_sscg_clk_sel:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon0:1;
        RBus_UInt32  tcon1:1;
        RBus_UInt32  tcon2:1;
        RBus_UInt32  tcon3:1;
        RBus_UInt32  tcon4:1;
        RBus_UInt32  tcon5:1;
        RBus_UInt32  tcon6:1;
        RBus_UInt32  tcon7:1;
        RBus_UInt32  tcon8:1;
        RBus_UInt32  tcon9:1;
        RBus_UInt32  tcon10:1;
        RBus_UInt32  tcon11:1;
        RBus_UInt32  tcon12:1;
        RBus_UInt32  tcon13:1;
        RBus_UInt32  tcon14:1;
        RBus_UInt32  tcon15:1;
        RBus_UInt32  tcon16:1;
        RBus_UInt32  tcon17:1;
        RBus_UInt32  tcon18:1;
        RBus_UInt32  tcon19:1;
    };
}tcon_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon0_hend:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon0_hstart:13;
        RBus_UInt32  res1:3;
    };
}tcon0_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon0_vend:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon0_vstart:12;
        RBus_UInt32  res1:4;
    };
}tcon0_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon0_ctl_2_0:3;
        RBus_UInt32  tcon0_ctl_3:1;
        RBus_UInt32  tcon0_ctl_4:1;
        RBus_UInt32  tcon0_ctl_5:1;
        RBus_UInt32  tcon0_ctl_6:1;
        RBus_UInt32  tcon0_ctl_7:1;
        RBus_UInt32  tcon0_ctl_10_8:3;
        RBus_UInt32  tcon0_across_ctrl3_reset:1;
        RBus_UInt32  tcon0_frame_inv:1;
        RBus_UInt32  tcon0_l_flag_sel:3;
        RBus_UInt32  tcon0_no_sscg_inv:1;
        RBus_UInt32  tcon0_sel:1;
        RBus_UInt32  res1:14;
    };
}tcon0_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon0_across_ctrl3_hp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon0_across_ctrl3_rp:12;
        RBus_UInt32  tcon0_across_frame_int:1;
        RBus_UInt32  res1:3;
    };
}tcon0_across_line_control3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon0_frame_period:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon0_frame_offset:12;
        RBus_UInt32  res1:4;
    };
}tcon0_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon1_hend:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon1_hstart:13;
        RBus_UInt32  res1:3;
    };
}tcon1_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon1_vend:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon1_vstart:12;
        RBus_UInt32  res1:4;
    };
}tcon1_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon1_ctl_2_0:3;
        RBus_UInt32  tcon1_ctl_3:1;
        RBus_UInt32  tcon1_ctl_4:1;
        RBus_UInt32  tcon1_ctl_5:1;
        RBus_UInt32  tcon1_ctl_6:1;
        RBus_UInt32  tcon1_ctl_7:1;
        RBus_UInt32  tcon1_ctl_10_8:3;
        RBus_UInt32  tcon1_across_ctrl3_reset:1;
        RBus_UInt32  tcon1_frame_inv:1;
        RBus_UInt32  tcon1_l_flag_sel:3;
        RBus_UInt32  tcon1_no_sscg_ctl:3;
        RBus_UInt32  tcon1_no_sscg_tog_en:1;
        RBus_UInt32  tcon1_no_sscg_tog_rst:1;
        RBus_UInt32  tcon1_no_sscg_inv:1;
        RBus_UInt32  tcon1_sel:1;
        RBus_UInt32  res1:9;
    };
}tcon1_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon1_across_ctrl3_hp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon1_across_ctrl3_rp:12;
        RBus_UInt32  tcon1_across_frame_int:1;
        RBus_UInt32  res1:3;
    };
}tcon1_across_line_control3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon1_frame_period:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon1_frame_offset:12;
        RBus_UInt32  res1:4;
    };
}tcon1_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon2_hend:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon2_hstart:13;
        RBus_UInt32  res1:3;
    };
}tcon2_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon2_vend:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon2_vstart:12;
        RBus_UInt32  res1:4;
    };
}tcon2_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon2_ctl_2_0:3;
        RBus_UInt32  tcon2_ctl_3:1;
        RBus_UInt32  tcon2_ctl_4:1;
        RBus_UInt32  tcon2_ctl_5:1;
        RBus_UInt32  tcon2_ctl_6:1;
        RBus_UInt32  tcon2_ctl_7:1;
        RBus_UInt32  tcon2_dot_mask_0:1;
        RBus_UInt32  tcon2_dot_mask_1:1;
        RBus_UInt32  tcon2_dot_mask_2:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  tcon2_ctl_10_8:3;
        RBus_UInt32  tcon2_across_ctrl3_reset:1;
        RBus_UInt32  tcon2_frame_inv:1;
        RBus_UInt32  tcon2_l_flag_sel:3;
        RBus_UInt32  tcon2_no_sscg_ctl:3;
        RBus_UInt32  tcon2_no_sscg_tog_en:1;
        RBus_UInt32  tcon2_no_sscg_tog_rst:1;
        RBus_UInt32  tcon2_no_sscg_inv:1;
        RBus_UInt32  tcon2_sel:1;
        RBus_UInt32  res1:5;
    };
}tcon2_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon2_across_ctrl3_hp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon2_across_ctrl3_rp:12;
        RBus_UInt32  tcon2_across_frame_int:1;
        RBus_UInt32  res1:3;
    };
}tcon2_across_line_control3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon2_frame_period:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon2_frame_offset:12;
        RBus_UInt32  res1:4;
    };
}tcon2_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon3_hend:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon3_hstart:13;
        RBus_UInt32  res1:3;
    };
}tcon3_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon3_vend:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon3_vstart:12;
        RBus_UInt32  res1:4;
    };
}tcon3_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon3_ctl_2_0:3;
        RBus_UInt32  tcon3_ctl_3:1;
        RBus_UInt32  tcon3_ctl_4:1;
        RBus_UInt32  tcon3_ctl_5:1;
        RBus_UInt32  tcon3_ctl_6:1;
        RBus_UInt32  tcon3_ctl_7:1;
        RBus_UInt32  tcon3_ctl_10_8:3;
        RBus_UInt32  tcon3_across_ctrl3_reset:1;
        RBus_UInt32  tcon3_frame_inv:1;
        RBus_UInt32  tcon3_l_flag_sel:3;
        RBus_UInt32  tcon3_no_sscg_ctl:3;
        RBus_UInt32  tcon3_no_sscg_tog_en:1;
        RBus_UInt32  tcon3_no_sscg_tog_rst:1;
        RBus_UInt32  tcon3_no_sscg_inv:1;
        RBus_UInt32  tcon3_sel:1;
        RBus_UInt32  res1:9;
    };
}tcon3_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon3_across_ctrl3_hp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon3_across_ctrl3_rp:12;
        RBus_UInt32  tcon3_across_frame_int:1;
        RBus_UInt32  res1:3;
    };
}tcon3_across_line_control3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon3_frame_period:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon3_frame_offset:12;
        RBus_UInt32  res1:4;
    };
}tcon3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon4_hend:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon4_hstart:13;
        RBus_UInt32  res1:3;
    };
}tcon4_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon4_vend:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon4_vstart:12;
        RBus_UInt32  res1:4;
    };
}tcon4_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon4_ctl_2_0:3;
        RBus_UInt32  tcon4_ctl_3:1;
        RBus_UInt32  tcon4_ctl_4:1;
        RBus_UInt32  tcon4_ctl_5:1;
        RBus_UInt32  tcon4_ctl_6:1;
        RBus_UInt32  tcon4_ctl_7:1;
        RBus_UInt32  tcon4_ctl_10_8:3;
        RBus_UInt32  tcon4_across_ctrl3_reset:1;
        RBus_UInt32  tcon4_frame_inv:1;
        RBus_UInt32  tcon4_l_flag_sel:3;
        RBus_UInt32  tcon4_no_sscg_ctl:3;
        RBus_UInt32  tcon4_no_sscg_tog_en:1;
        RBus_UInt32  tcon4_no_sscg_tog_rst:1;
        RBus_UInt32  tcon4_no_sscg_inv:1;
        RBus_UInt32  tcon4_sel:1;
        RBus_UInt32  res1:9;
    };
}tcon4_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon4_across_ctrl3_hp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon4_across_ctrl3_rp:12;
        RBus_UInt32  tcon4_across_frame_int:1;
        RBus_UInt32  res1:3;
    };
}tcon4_across_line_control3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon4_frame_period:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon4_frame_offset:12;
        RBus_UInt32  res1:4;
    };
}tcon4_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon5_hend:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon5_hstart:13;
        RBus_UInt32  res1:3;
    };
}tcon5_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon5_vend:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon5_vstart:12;
        RBus_UInt32  res1:4;
    };
}tcon5_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon5_ctl_2_0:3;
        RBus_UInt32  tcon5_ctl_3:1;
        RBus_UInt32  tcon5_ctl_4:1;
        RBus_UInt32  tcon5_ctl_5:1;
        RBus_UInt32  tcon5_ctl_6:1;
        RBus_UInt32  tcon5_ctl_7:1;
        RBus_UInt32  tcon5_ctl_10_8:3;
        RBus_UInt32  tcon5_across_ctrl3_reset:1;
        RBus_UInt32  tcon5_frame_inv:1;
        RBus_UInt32  tcon5_l_flag_sel:3;
        RBus_UInt32  tcon5_no_sscg_ctl:3;
        RBus_UInt32  tcon5_no_sscg_tog_en:1;
        RBus_UInt32  tcon5_no_sscg_tog_rst:1;
        RBus_UInt32  tcon5_no_sscg_inv:1;
        RBus_UInt32  tcon5_sel:1;
        RBus_UInt32  res1:9;
    };
}tcon5_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon5_across_ctrl3_hp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon5_across_ctrl3_rp:12;
        RBus_UInt32  tcon5_across_frame_int:1;
        RBus_UInt32  res1:3;
    };
}tcon5_across_line_control3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon5_frame_period:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon5_frame_offset:12;
        RBus_UInt32  res1:4;
    };
}tcon5_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon6_hend:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon6_hstart:13;
        RBus_UInt32  res1:3;
    };
}tcon6_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon6_vend:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon6_vstart:12;
        RBus_UInt32  res1:4;
    };
}tcon6_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon6_ctl_2_0:3;
        RBus_UInt32  tcon6_ctl_3:1;
        RBus_UInt32  tcon6_ctl_4:1;
        RBus_UInt32  tcon6_ctl_5:1;
        RBus_UInt32  tcon6_ctl_6:1;
        RBus_UInt32  tcon6_ctl_7:1;
        RBus_UInt32  tcon6_ctl_10_8:3;
        RBus_UInt32  tcon6_across_ctrl3_reset:1;
        RBus_UInt32  tcon6_frame_inv:1;
        RBus_UInt32  tcon6_l_flag_sel:3;
        RBus_UInt32  tcon6_no_sscg_ctl:3;
        RBus_UInt32  tcon6_no_sscg_tog_en:1;
        RBus_UInt32  tcon6_no_sscg_tog_rst:1;
        RBus_UInt32  tcon6_no_sscg_inv:1;
        RBus_UInt32  tcon6_sel:1;
        RBus_UInt32  res1:9;
    };
}tcon6_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon6_across_ctrl3_hp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon6_across_ctrl3_rp:12;
        RBus_UInt32  tcon6_across_frame_int:1;
        RBus_UInt32  res1:3;
    };
}tcon6_across_line_control3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon6_frame_period:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon6_frame_offset:12;
        RBus_UInt32  res1:4;
    };
}tcon6_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon7_hend:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon7_hstart:13;
        RBus_UInt32  res1:3;
    };
}tcon7_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon7_vend:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon7_vstart:12;
        RBus_UInt32  res1:4;
    };
}tcon7_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon7_ctl_2_0:3;
        RBus_UInt32  tcon7_ctl_3:1;
        RBus_UInt32  tcon7_ctl_4:1;
        RBus_UInt32  tcon7_ctl_5:1;
        RBus_UInt32  tcon7_ctl_6:1;
        RBus_UInt32  tcon7_ctl_7:1;
        RBus_UInt32  tcon7_ctl_10_8:3;
        RBus_UInt32  tcon7_across_ctrl3_reset:1;
        RBus_UInt32  tcon7_frame_inv:1;
        RBus_UInt32  tcon7_l_flag_sel:3;
        RBus_UInt32  tcon7_no_sscg_ctl:3;
        RBus_UInt32  tcon7_no_sscg_tog_en:1;
        RBus_UInt32  tcon7_no_sscg_tog_rst:1;
        RBus_UInt32  tcon7_no_sscg_inv:1;
        RBus_UInt32  tcon7_sel:1;
        RBus_UInt32  res1:9;
    };
}tcon7_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon7_across_ctrl3_hp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon7_across_ctrl3_rp:12;
        RBus_UInt32  tcon7_across_frame_int:1;
        RBus_UInt32  res1:3;
    };
}tcon7_across_line_control3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon7_frame_period:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon7_frame_offset:12;
        RBus_UInt32  res1:4;
    };
}tcon7_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon8_hend:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon8_hstart:13;
        RBus_UInt32  res1:3;
    };
}tcon8_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon8_vend:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon8_vstart:12;
        RBus_UInt32  res1:4;
    };
}tcon8_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon8_ctl_2_0:3;
        RBus_UInt32  tcon8_ctl_3:1;
        RBus_UInt32  tcon8_ctl_4:1;
        RBus_UInt32  tcon8_ctl_5:1;
        RBus_UInt32  tcon8_ctl_6:1;
        RBus_UInt32  tcon8_ctl_7:1;
        RBus_UInt32  tcon8_ctl_10_8:3;
        RBus_UInt32  tcon8_across_ctrl3_reset:1;
        RBus_UInt32  tcon8_frame_inv:1;
        RBus_UInt32  tcon8_l_flag_sel:3;
        RBus_UInt32  tcon8_no_sscg_ctl:3;
        RBus_UInt32  tcon8_no_sscg_tog_en:1;
        RBus_UInt32  tcon8_no_sscg_tog_rst:1;
        RBus_UInt32  tcon8_no_sscg_inv:1;
        RBus_UInt32  tcon8_sel:1;
        RBus_UInt32  res1:9;
    };
}tcon8_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon8_across_ctrl3_hp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon8_across_ctrl3_rp:12;
        RBus_UInt32  tcon8_across_frame_int:1;
        RBus_UInt32  res1:3;
    };
}tcon8_across_line_control3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon8_frame_period:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon8_frame_offset:12;
        RBus_UInt32  res1:4;
    };
}tcon8_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon9_hend:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon9_hstart:13;
        RBus_UInt32  res1:3;
    };
}tcon9_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon9_vend:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon9_vstart:12;
        RBus_UInt32  res1:4;
    };
}tcon9_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon9_ctl_2_0:3;
        RBus_UInt32  tcon9_ctl_3:1;
        RBus_UInt32  tcon9_ctl_4:1;
        RBus_UInt32  tcon9_ctl_5:1;
        RBus_UInt32  tcon9_ctl_6:1;
        RBus_UInt32  tcon9_ctl_7:1;
        RBus_UInt32  tcon9_ctl_10_8:3;
        RBus_UInt32  tcon9_across_ctrl3_reset:1;
        RBus_UInt32  tcon9_frame_inv:1;
        RBus_UInt32  tcon9_l_flag_sel:3;
        RBus_UInt32  tcon9_no_sscg_ctl:3;
        RBus_UInt32  tcon9_no_sscg_tog_en:1;
        RBus_UInt32  tcon9_no_sscg_tog_rst:1;
        RBus_UInt32  tcon9_no_sscg_inv:1;
        RBus_UInt32  tcon9_sel:1;
        RBus_UInt32  res1:9;
    };
}tcon9_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon9_across_ctrl3_hp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon9_across_ctrl3_rp:12;
        RBus_UInt32  tcon9_across_frame_int:1;
        RBus_UInt32  res1:3;
    };
}tcon9_across_line_control3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon9_frame_period:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon9_frame_offset:12;
        RBus_UInt32  res1:4;
    };
}tcon9_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dreg_dbuf0_set:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  dreg_dbuf0_en_n:1;
        RBus_UInt32  res1:29;
    };
}double_buffer_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon10_hend:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon10_hstart:13;
        RBus_UInt32  res1:3;
    };
}tcon10_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon10_vend:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon10_vstart:12;
        RBus_UInt32  res1:4;
    };
}tcon10_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon10_ctl_2_0:3;
        RBus_UInt32  tcon10_ctl_3:1;
        RBus_UInt32  tcon10_ctl_4:1;
        RBus_UInt32  tcon10_ctl_5:1;
        RBus_UInt32  tcon10_ctl_6:1;
        RBus_UInt32  tcon10_ctl_7:1;
        RBus_UInt32  tcon10_ctl_10_8:3;
        RBus_UInt32  tcon10_across_ctrl3_reset:1;
        RBus_UInt32  tcon10_frame_inv:1;
        RBus_UInt32  tcon10_l_flag_sel:3;
        RBus_UInt32  tcon10_no_sscg_ctl:3;
        RBus_UInt32  tcon10_no_sscg_tog_en:1;
        RBus_UInt32  tcon10_no_sscg_tog_rst:1;
        RBus_UInt32  tcon10_no_sscg_inv:1;
        RBus_UInt32  tcon10_sel:1;
        RBus_UInt32  res1:9;
    };
}tcon10_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon10_across_ctrl3_hp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon10_across_ctrl3_rp:12;
        RBus_UInt32  tcon10_across_frame_int:1;
        RBus_UInt32  res1:3;
    };
}tcon10_across_line_control3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon10_frame_period:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon10_frame_offset:12;
        RBus_UInt32  res1:4;
    };
}tcon10_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dreg_dbuf1_set:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  dreg_dbuf1_en_n:1;
        RBus_UInt32  res1:29;
    };
}double_buffer_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon11_hend:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon11_hstart:13;
        RBus_UInt32  res1:3;
    };
}tcon11_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon11_vend:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon11_vstart:12;
        RBus_UInt32  res1:4;
    };
}tcon11_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon11_ctl_2_0:3;
        RBus_UInt32  tcon11_ctl_3:1;
        RBus_UInt32  tcon11_ctl_4:1;
        RBus_UInt32  tcon11_ctl_5:1;
        RBus_UInt32  tcon11_ctl_6:1;
        RBus_UInt32  tcon11_ctl_7:1;
        RBus_UInt32  tcon11_ctl_10_8:3;
        RBus_UInt32  tcon11_across_ctrl3_reset:1;
        RBus_UInt32  tcon11_frame_inv:1;
        RBus_UInt32  tcon11_l_flag_sel:3;
        RBus_UInt32  tcon11_no_sscg_ctl:3;
        RBus_UInt32  tcon11_no_sscg_tog_en:1;
        RBus_UInt32  tcon11_no_sscg_tog_rst:1;
        RBus_UInt32  tcon11_no_sscg_inv:1;
        RBus_UInt32  tcon11_sel:1;
        RBus_UInt32  res1:9;
    };
}tcon11_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon11_across_ctrl3_hp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon11_across_ctrl3_rp:12;
        RBus_UInt32  tcon11_across_frame_int:1;
        RBus_UInt32  res1:3;
    };
}tcon11_across_line_control3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon11_frame_period:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon11_frame_offset:12;
        RBus_UInt32  res1:4;
    };
}tcon11_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon12_hend:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon12_hstart:13;
        RBus_UInt32  res1:3;
    };
}tcon12_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon12_vend:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon12_vstart:12;
        RBus_UInt32  res1:4;
    };
}tcon12_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon12_ctl_2_0:3;
        RBus_UInt32  tcon12_ctl_3:1;
        RBus_UInt32  tcon12_ctl_4:1;
        RBus_UInt32  tcon12_ctl_5:1;
        RBus_UInt32  tcon12_ctl_6:1;
        RBus_UInt32  tcon12_ctl_7:1;
        RBus_UInt32  tcon12_ctl_10_8:3;
        RBus_UInt32  tcon12_across_ctrl3_reset:1;
        RBus_UInt32  tcon12_frame_inv:1;
        RBus_UInt32  tcon12_l_flag_sel:3;
        RBus_UInt32  tcon12_no_sscg_ctl:3;
        RBus_UInt32  tcon12_no_sscg_tog_en:1;
        RBus_UInt32  tcon12_no_sscg_tog_rst:1;
        RBus_UInt32  tcon12_no_sscg_inv:1;
        RBus_UInt32  tcon12_sel:1;
        RBus_UInt32  res1:9;
    };
}tcon12_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon12_across_ctrl3_hp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon12_across_ctrl3_rp:12;
        RBus_UInt32  tcon12_across_frame_int:1;
        RBus_UInt32  res1:3;
    };
}tcon12_across_line_control3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon12_frame_period:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon12_frame_offset:12;
        RBus_UInt32  res1:4;
    };
}tcon12_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dreg_dbuf2_set:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  dreg_dbuf2_en_n:1;
        RBus_UInt32  res1:29;
    };
}double_buffer_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon13_hend:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon13_hstart:13;
        RBus_UInt32  res1:3;
    };
}tcon13_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon13_vend:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon13_vstart:12;
        RBus_UInt32  res1:4;
    };
}tcon13_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon13_ctl_2_0:3;
        RBus_UInt32  tcon13_ctl_3:1;
        RBus_UInt32  tcon13_ctl_4:1;
        RBus_UInt32  tcon13_ctl_5:1;
        RBus_UInt32  tcon13_ctl_6:1;
        RBus_UInt32  tcon13_ctl_7:1;
        RBus_UInt32  tcon13_dot_mask_0:1;
        RBus_UInt32  tcon13_dot_mask_1:1;
        RBus_UInt32  tcon13_dot_mask_2:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  tcon13_ctl_10_8:3;
        RBus_UInt32  tcon13_across_ctrl3_reset:1;
        RBus_UInt32  tcon13_frame_inv:1;
        RBus_UInt32  tcon13_l_flag_sel:3;
        RBus_UInt32  tcon13_no_sscg_ctl:3;
        RBus_UInt32  tcon13_no_sscg_tog_en:1;
        RBus_UInt32  tcon13_no_sscg_tog_rst:1;
        RBus_UInt32  tcon13_no_sscg_inv:1;
        RBus_UInt32  tcon13_sel:1;
        RBus_UInt32  res1:5;
    };
}tcon13_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon13_across_ctrl3_hp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon13_across_ctrl3_rp:12;
        RBus_UInt32  tcon13_across_frame_int:1;
        RBus_UInt32  res1:3;
    };
}tcon13_across_line_control3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon13_frame_period:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon13_frame_offset:12;
        RBus_UInt32  res1:4;
    };
}tcon13_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon14_hend:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon14_hstart:13;
        RBus_UInt32  res1:3;
    };
}tcon14_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon14_vend:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon14_vstart:12;
        RBus_UInt32  res1:4;
    };
}tcon14_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon14_ctl_2_0:3;
        RBus_UInt32  tcon14_ctl_3:1;
        RBus_UInt32  tcon14_ctl_4:1;
        RBus_UInt32  tcon14_ctl_5:1;
        RBus_UInt32  tcon14_ctl_6:1;
        RBus_UInt32  tcon14_ctl_7:1;
        RBus_UInt32  tcon14_dot_mask_0:1;
        RBus_UInt32  tcon14_dot_mask_1:1;
        RBus_UInt32  tcon14_dot_mask_2:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  tcon14_ctl_10_8:3;
        RBus_UInt32  tcon14_across_ctrl3_reset:1;
        RBus_UInt32  tcon14_frame_inv:1;
        RBus_UInt32  tcon14_l_flag_sel:3;
        RBus_UInt32  tcon14_no_sscg_ctl:3;
        RBus_UInt32  tcon14_no_sscg_tog_en:1;
        RBus_UInt32  tcon14_no_sscg_tog_rst:1;
        RBus_UInt32  tcon14_no_sscg_inv:1;
        RBus_UInt32  tcon14_sel:1;
        RBus_UInt32  res1:5;
    };
}tcon14_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon14_across_ctrl3_hp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon14_across_ctrl3_rp:12;
        RBus_UInt32  tcon14_across_frame_int:1;
        RBus_UInt32  res1:3;
    };
}tcon14_across_line_control3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon14_frame_period:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon14_frame_offset:12;
        RBus_UInt32  res1:4;
    };
}tcon14_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon15_hend:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon15_hstart:13;
        RBus_UInt32  res1:3;
    };
}tcon15_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon15_vend:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon15_vstart:12;
        RBus_UInt32  res1:4;
    };
}tcon15_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon15_ctl_2_0:3;
        RBus_UInt32  tcon15_ctl_3:1;
        RBus_UInt32  tcon15_ctl_4:1;
        RBus_UInt32  tcon15_ctl_5:1;
        RBus_UInt32  tcon15_ctl_6:1;
        RBus_UInt32  tcon15_ctl_7:1;
        RBus_UInt32  tcon15_ctl_10_8:3;
        RBus_UInt32  tcon15_across_ctrl3_reset:1;
        RBus_UInt32  tcon15_frame_inv:1;
        RBus_UInt32  tcon15_l_flag_sel:3;
        RBus_UInt32  tcon15_no_sscg_ctl:3;
        RBus_UInt32  tcon15_no_sscg_tog_en:1;
        RBus_UInt32  tcon15_no_sscg_tog_rst:1;
        RBus_UInt32  tcon15_no_sscg_inv:1;
        RBus_UInt32  tcon15_sel:1;
        RBus_UInt32  res1:9;
    };
}tcon15_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon15_across_ctrl3_hp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon15_across_ctrl3_rp:12;
        RBus_UInt32  tcon15_across_frame_int:1;
        RBus_UInt32  res1:3;
    };
}tcon15_across_line_control3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon15_frame_period:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon15_frame_offset:12;
        RBus_UInt32  res1:4;
    };
}tcon15_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon16_hend:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon16_hstart:13;
        RBus_UInt32  res1:3;
    };
}tcon16_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon16_vend:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon16_vstart:12;
        RBus_UInt32  res1:4;
    };
}tcon16_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon16_ctl_2_0:3;
        RBus_UInt32  tcon16_ctl_3:1;
        RBus_UInt32  tcon16_ctl_4:1;
        RBus_UInt32  tcon16_ctl_5:1;
        RBus_UInt32  tcon16_ctl_6:1;
        RBus_UInt32  tcon16_ctl_7:1;
        RBus_UInt32  tcon16_ctl_10_8:3;
        RBus_UInt32  tcon16_across_ctrl3_reset:1;
        RBus_UInt32  tcon16_frame_inv:1;
        RBus_UInt32  tcon16_l_flag_sel:3;
        RBus_UInt32  tcon16_no_sscg_ctl:3;
        RBus_UInt32  tcon16_no_sscg_tog_en:1;
        RBus_UInt32  tcon16_no_sscg_tog_rst:1;
        RBus_UInt32  tcon16_no_sscg_inv:1;
        RBus_UInt32  tcon16_sel:1;
        RBus_UInt32  res1:9;
    };
}tcon16_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon16_across_ctrl3_hp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon16_across_ctrl3_rp:12;
        RBus_UInt32  tcon16_across_frame_int:1;
        RBus_UInt32  res1:3;
    };
}tcon16_across_line_control3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon16_frame_period:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon16_frame_offset:12;
        RBus_UInt32  res1:4;
    };
}tcon16_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon17_hend:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon17_hstart:13;
        RBus_UInt32  res1:3;
    };
}tcon17_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon17_vend:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon17_vstart:12;
        RBus_UInt32  res1:4;
    };
}tcon17_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon17_ctl_2_0:3;
        RBus_UInt32  tcon17_ctl_3:1;
        RBus_UInt32  tcon17_ctl_4:1;
        RBus_UInt32  tcon17_ctl_5:1;
        RBus_UInt32  tcon17_ctl_6:1;
        RBus_UInt32  tcon17_ctl_7:1;
        RBus_UInt32  tcon17_ctl_10_8:3;
        RBus_UInt32  tcon17_across_ctrl3_reset:1;
        RBus_UInt32  tcon17_frame_inv:1;
        RBus_UInt32  tcon17_l_flag_sel:3;
        RBus_UInt32  tcon17_no_sscg_ctl:3;
        RBus_UInt32  tcon17_no_sscg_tog_en:1;
        RBus_UInt32  tcon17_no_sscg_tog_rst:1;
        RBus_UInt32  tcon17_no_sscg_inv:1;
        RBus_UInt32  tcon17_sel:1;
        RBus_UInt32  res1:9;
    };
}tcon17_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon17_across_ctrl3_hp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon17_across_ctrl3_rp:12;
        RBus_UInt32  tcon17_across_frame_int:1;
        RBus_UInt32  res1:3;
    };
}tcon17_across_line_control3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon17_frame_period:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon17_frame_offset:12;
        RBus_UInt32  res1:4;
    };
}tcon17_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon18_hend:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon18_hstart:13;
        RBus_UInt32  res1:3;
    };
}tcon18_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon18_vend:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon18_vstart:12;
        RBus_UInt32  res1:4;
    };
}tcon18_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon18_ctl_2_0:3;
        RBus_UInt32  tcon18_ctl_3:1;
        RBus_UInt32  tcon18_ctl_4:1;
        RBus_UInt32  tcon18_ctl_5:1;
        RBus_UInt32  tcon18_ctl_6:1;
        RBus_UInt32  tcon18_ctl_7:1;
        RBus_UInt32  tcon18_ctl_10_8:3;
        RBus_UInt32  tcon18_across_ctrl3_reset:1;
        RBus_UInt32  tcon18_frame_inv:1;
        RBus_UInt32  tcon18_l_flag_sel:3;
        RBus_UInt32  tcon18_no_sscg_ctl:3;
        RBus_UInt32  tcon18_no_sscg_tog_en:1;
        RBus_UInt32  tcon18_no_sscg_tog_rst:1;
        RBus_UInt32  tcon18_no_sscg_inv:1;
        RBus_UInt32  tcon18_sel:1;
        RBus_UInt32  res1:9;
    };
}tcon18_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon18_across_ctrl3_hp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon18_across_ctrl3_rp:12;
        RBus_UInt32  tcon18_across_frame_int:1;
        RBus_UInt32  res1:3;
    };
}tcon18_across_line_control3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon18_frame_period:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon18_frame_offset:12;
        RBus_UInt32  res1:4;
    };
}tcon18_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon19_hend:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon19_hstart:13;
        RBus_UInt32  res1:3;
    };
}tcon19_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon19_vend:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon19_vstart:12;
        RBus_UInt32  res1:4;
    };
}tcon19_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon19_ctl_2_0:3;
        RBus_UInt32  tcon19_ctl_3:1;
        RBus_UInt32  tcon19_ctl_4:1;
        RBus_UInt32  tcon19_ctl_5:1;
        RBus_UInt32  tcon19_ctl_6:1;
        RBus_UInt32  tcon19_ctl_7:1;
        RBus_UInt32  tcon19_ctl_10_8:3;
        RBus_UInt32  tcon19_across_ctrl3_reset:1;
        RBus_UInt32  tcon19_frame_inv:1;
        RBus_UInt32  tcon19_l_flag_sel:3;
        RBus_UInt32  tcon19_no_sscg_ctl:3;
        RBus_UInt32  tcon19_no_sscg_tog_en:1;
        RBus_UInt32  tcon19_no_sscg_tog_rst:1;
        RBus_UInt32  tcon19_no_sscg_inv:1;
        RBus_UInt32  tcon19_sel:1;
        RBus_UInt32  res1:9;
    };
}tcon19_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon19_across_ctrl3_hp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon19_across_ctrl3_rp:12;
        RBus_UInt32  tcon19_across_frame_int:1;
        RBus_UInt32  res1:3;
    };
}tcon19_across_line_control3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon19_frame_period:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon19_frame_offset:12;
        RBus_UInt32  res1:4;
    };
}tcon19_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mlvds_mode:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  mlvds_mirror:1;
        RBus_UInt32  mlvds_pn_swap:1;
        RBus_UInt32  mlvds_rl_swap:1;
        RBus_UInt32  mlvds_dual:1;
        RBus_UInt32  mlvds_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  mlvds_3_pair_mode:2;
        RBus_UInt32  mlvds_signle:2;
        RBus_UInt32  pif_dh_den_end_dummy:8;
        RBus_UInt32  pif_dh_den_sta_dummy:12;
    };
}mlvds_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mlvds_rst_high:5;
        RBus_UInt32  res1:1;
        RBus_UInt32  mlvds_map_inv:1;
        RBus_UInt32  mlvds_rst_tcon_en:1;
        RBus_UInt32  tcon_delay_sel_0:2;
        RBus_UInt32  tcon_delay_sel_1:2;
        RBus_UInt32  tcon_delay_sel_2:2;
        RBus_UInt32  tcon_delay_sel_3:2;
        RBus_UInt32  tcon_delay_sel_4:2;
        RBus_UInt32  tcon_delay_sel_5:2;
        RBus_UInt32  tcon_delay_sel_6:2;
        RBus_UInt32  tcon_delay_sel_7:2;
        RBus_UInt32  tcon_sel:8;
    };
}mlvds_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mlvds_rst_low:24;
        RBus_UInt32  mlvds_lck_inv:1;
        RBus_UInt32  mlvds_rck_inv:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  mlvds_rst_low_region:1;
    };
}mlvds_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_det_width:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  pat_det_h_ini_sta:12;
        RBus_UInt32  res1:4;
    };
}pattern_detect_window_h_initial_start_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_det_height:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  pat_det_v_ini_sta:11;
        RBus_UInt32  res1:5;
    };
}pattern_detect_window_v_initial_start_height_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_det_auto:1;
        RBus_UInt32  pat_det_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  pat_det_mode:1;
        RBus_UInt32  spc_pt_8:1;
        RBus_UInt32  spc_pt_7:1;
        RBus_UInt32  spc_pt_6:1;
        RBus_UInt32  spc_pt_5:1;
        RBus_UInt32  spc_pt_4:1;
        RBus_UInt32  spc_pt_3:1;
        RBus_UInt32  spc_pt_2:1;
        RBus_UInt32  spc_pt_1:1;
        RBus_UInt32  res1:20;
    };
}pattern_detect_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_1:24;
        RBus_UInt32  res1:8;
    };
}pat_det_sum1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_2:24;
        RBus_UInt32  res1:8;
    };
}pat_det_sum2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_3:24;
        RBus_UInt32  res1:8;
    };
}pat_det_sum3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_4:24;
        RBus_UInt32  res1:8;
    };
}pat_det_sum4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_5:24;
        RBus_UInt32  res1:8;
    };
}pat_det_sum5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_6:24;
        RBus_UInt32  res1:8;
    };
}pat_det_sum6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_7:24;
        RBus_UInt32  res1:8;
    };
}pat_det_sum7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_8:24;
        RBus_UInt32  res1:8;
    };
}pat_det_sum8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th1:24;
        RBus_UInt32  res1:8;
    };
}pat_det_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th2:24;
        RBus_UInt32  res1:8;
    };
}pat_det_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th3:24;
        RBus_UInt32  res1:8;
    };
}pat_det_th3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th4:24;
        RBus_UInt32  res1:8;
    };
}pat_det_th4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th5:24;
        RBus_UInt32  res1:8;
    };
}pat_det_th5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th6:24;
        RBus_UInt32  res1:8;
    };
}pat_det_th6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th7:24;
        RBus_UInt32  res1:8;
    };
}pat_det_th7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th8:24;
        RBus_UInt32  res1:8;
    };
}pat_det_th8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon0_no_sscg_end:16;
        RBus_UInt32  tcon0_no_sscg_start:16;
    };
}tcon0_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon1_no_sscg_end:16;
        RBus_UInt32  tcon1_no_sscg_start:16;
    };
}tcon1_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon2_no_sscg_end:16;
        RBus_UInt32  tcon2_no_sscg_start:16;
    };
}tcon2_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon3_no_sscg_end:16;
        RBus_UInt32  tcon3_no_sscg_start:16;
    };
}tcon3_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon4_no_sscg_end:16;
        RBus_UInt32  tcon4_no_sscg_start:16;
    };
}tcon4_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon5_no_sscg_end:16;
        RBus_UInt32  tcon5_no_sscg_start:16;
    };
}tcon5_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon6_no_sscg_end:16;
        RBus_UInt32  tcon6_no_sscg_start:16;
    };
}tcon6_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon7_no_sscg_end:16;
        RBus_UInt32  tcon7_no_sscg_start:16;
    };
}tcon7_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon8_no_sscg_end:16;
        RBus_UInt32  tcon8_no_sscg_start:16;
    };
}tcon8_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon9_no_sscg_end:16;
        RBus_UInt32  tcon9_no_sscg_start:16;
    };
}tcon9_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon10_no_sscg_end:16;
        RBus_UInt32  tcon10_no_sscg_start:16;
    };
}tcon10_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon11_no_sscg_end:16;
        RBus_UInt32  tcon11_no_sscg_start:16;
    };
}tcon11_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon12_no_sscg_end:16;
        RBus_UInt32  tcon12_no_sscg_start:16;
    };
}tcon12_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon13_no_sscg_end:16;
        RBus_UInt32  tcon13_no_sscg_start:16;
    };
}tcon13_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon14_no_sscg_end:16;
        RBus_UInt32  tcon14_no_sscg_start:16;
    };
}tcon14_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon15_no_sscg_end:16;
        RBus_UInt32  tcon15_no_sscg_start:16;
    };
}tcon15_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon16_no_sscg_end:16;
        RBus_UInt32  tcon16_no_sscg_start:16;
    };
}tcon16_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon17_no_sscg_end:16;
        RBus_UInt32  tcon17_no_sscg_start:16;
    };
}tcon17_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon18_no_sscg_end:16;
        RBus_UInt32  tcon18_no_sscg_start:16;
    };
}tcon18_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon19_no_sscg_end:16;
        RBus_UInt32  tcon19_no_sscg_start:16;
    };
}tcon19_no_sscg_se_RBUS;


#endif







#endif //_RBUS_PIF_REG_H_

