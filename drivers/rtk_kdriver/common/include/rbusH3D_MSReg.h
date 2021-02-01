/**
* @file rbusH3d_msReg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2011/6/28
* @version 1.1
* @ingroup model_rbus
*
*/

#ifndef _RBUS_H3D_MS_REG_H_
#define _RBUS_H3D_MS_REG_H_

#include "rbus/rbusTypes.h"




// H3D_MS Register Address
#define H3D_MS_ONMS_CTRL_ADDR                      (0x18021300)
#define H3D_MS_ONMS_BLANK_PIXEL_VALUE_GET_0_ADDR   (0x18021304)
#define H3D_MS_ONMS_BLANK_PIXEL_VALUE_GET_1_ADDR   (0x18021308)
#define H3D_MS_ONMS_BLANK_PIXEL_VALUE_0_ADDR       (0x1802130c)
#define H3D_MS_ONMS_BLANK_PIXEL_VALUE_1_ADDR       (0x18021310)
#define H3D_MS_ONMS_FP_VACT12_ADDR                 (0x18021314)
#define H3D_MS_ONMS_FP_VACT34_ADDR                 (0x18021318)
#define H3D_MS_ONMS_FP_VACT_SPACE_ADDR             (0x1802131c)
#define H3D_MS_ONMS_BLANK_LINE_ADDR                (0x18021320)
#define H3D_MS_ONMS_ACTIVE_SPACE1_LINE_NUMBER_ADDR (0x18021324)
#define H3D_MS_ONMS_ACTIVE_SPACE2_LINE_NUMBER_ADDR (0x18021328)
#define H3D_MS_ONMS_ACTIVE_SPACE3_LINE_NUMBER_ADDR (0x1802132c)
#define H3D_MS_ONMS_VS_PERIOD_ADDR                 (0x18021330)
#define H3D_MS_ONMS_VSHS_HIGH_PERIOD_ADDR          (0x18021334)
#define H3D_MS_ONMS_HS_PERIOD_ADDR                 (0x18021338)
#define H3D_MS_ONMS_VACT_STA_ADDR                  (0x1802133c)
#define H3D_MS_ONMS_VACT_SPACE_MIN_VALUE_ADDR      (0x18021340)
#define H3D_MS_ONMS_VACT_SPACE1_MAX_INFO_ADDR      (0x18021344)
#define H3D_MS_ONMS_VACT_SPACE2_MAX_INFO_ADDR      (0x18021348)
#define H3D_MS_ONMS_VACT_SPACE3_MAX_INFO_ADDR      (0x1802134c)
#define H3D_MS_ONMS_VACT_SPACE1_MIN_INFO_ADDR      (0x18021350)
#define H3D_MS_ONMS_VACT_SPACE2_MIN_INFO_ADDR      (0x18021354)
#define H3D_MS_ONMS_VACT_SPACE3_MIN_INFO_ADDR      (0x18021358)
#define H3D_MS_ONMS_STATUS_ADDR                    (0x1802135c)
#define H3D_MS_ONMS_WATCHDOG_EN_ADDR               (0x18021360)
#define H3D_MS_ONMS_INTERRUPT_EN_ADDR              (0x18021364)
#define H3D_MS_ONMS_HACT_STA_ADDR                  (0x18021368)

#define H3D_MS_ONMS_CTRL_VADDR                     (0xb8021300)
#define H3D_MS_ONMS_BLANK_PIXEL_VALUE_GET_0_VADDR  (0xb8021304)
#define H3D_MS_ONMS_BLANK_PIXEL_VALUE_GET_1_VADDR  (0xb8021308)
#define H3D_MS_ONMS_BLANK_PIXEL_VALUE_0_VADDR      (0xb802130c)
#define H3D_MS_ONMS_BLANK_PIXEL_VALUE_1_VADDR      (0xb8021310)
#define H3D_MS_ONMS_FP_VACT12_VADDR                (0xb8021314)
#define H3D_MS_ONMS_FP_VACT34_VADDR                (0xb8021318)
#define H3D_MS_ONMS_FP_VACT_SPACE_VADDR            (0xb802131c)
#define H3D_MS_ONMS_BLANK_LINE_VADDR               (0xb8021320)
#define H3D_MS_ONMS_ACTIVE_SPACE1_LINE_NUMBER_VADDR  (0xb8021324)
#define H3D_MS_ONMS_ACTIVE_SPACE2_LINE_NUMBER_VADDR  (0xb8021328)
#define H3D_MS_ONMS_ACTIVE_SPACE3_LINE_NUMBER_VADDR  (0xb802132c)
#define H3D_MS_ONMS_VS_PERIOD_VADDR                (0xb8021330)
#define H3D_MS_ONMS_VSHS_HIGH_PERIOD_VADDR         (0xb8021334)
#define H3D_MS_ONMS_HS_PERIOD_VADDR                (0xb8021338)
#define H3D_MS_ONMS_VACT_STA_VADDR                 (0xb802133c)
#define H3D_MS_ONMS_VACT_SPACE_MIN_VALUE_VADDR     (0xb8021340)
#define H3D_MS_ONMS_VACT_SPACE1_MAX_INFO_VADDR     (0xb8021344)
#define H3D_MS_ONMS_VACT_SPACE2_MAX_INFO_VADDR     (0xb8021348)
#define H3D_MS_ONMS_VACT_SPACE3_MAX_INFO_VADDR     (0xb802134c)
#define H3D_MS_ONMS_VACT_SPACE1_MIN_INFO_VADDR     (0xb8021350)
#define H3D_MS_ONMS_VACT_SPACE2_MIN_INFO_VADDR     (0xb8021354)
#define H3D_MS_ONMS_VACT_SPACE3_MIN_INFO_VADDR     (0xb8021358)
#define H3D_MS_ONMS_STATUS_VADDR                   (0xb802135c)
#define H3D_MS_ONMS_WATCHDOG_EN_VADDR              (0xb8021360)
#define H3D_MS_ONMS_INTERRUPT_EN_VADDR             (0xb8021364)
#define H3D_MS_ONMS_HACT_STA_VADDR                 (0xb8021368)




#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======H3D_MS register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_ctrl:4;
        RBus_UInt32  pixel_get_en:1;
        RBus_UInt32  pixel_get_sel:2;
        RBus_UInt32  progressive:1;
        RBus_UInt32  vtotal_max_delta:4;
        RBus_UInt32  htotal_max_delta:4;
        RBus_UInt32  res1:3;
        RBus_UInt32  pixel_encoding:1;
        RBus_UInt32  vact_space_threshold:4;
        RBus_UInt32  vact_space_meas_en:1;
        RBus_UInt32  meas_to_sel:1;
        RBus_UInt32  sycms_clk:1;
        RBus_UInt32  vs_meas_inv:1;
        RBus_UInt32  hs_meas_inv:1;
        RBus_UInt32  popup_meas:1;
        RBus_UInt32  ms_conti:1;
        RBus_UInt32  start_ms:1;
    };
}onms_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  pixel_ok:1;
        RBus_UInt32  get_r_value:12;
        RBus_UInt32  get_g_value:12;
    };
}onms_blank_pixel_value_get_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  get_b_value:12;
    };
}onms_blank_pixel_value_get_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  active_r_value:12;
        RBus_UInt32  active_g_value:12;
    };
}onms_blank_pixel_value_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  active_b_value:12;
    };
}onms_blank_pixel_value_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  vact2:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  vact1:11;
    };
}onms_fp_vact12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  vact4:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  vact3:11;
    };
}onms_fp_vact34_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  fp_vact_space1:10;
        RBus_UInt32  fp_vact_space2:10;
        RBus_UInt32  fp_vact_space3:10;
    };
}onms_fp_vact_space_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  r_blank_line_start:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  l_blank_line_end:11;
    };
}onms_blank_line_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  vact_space1_end:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  vact_space1_start:10;
    };
}onms_active_space1_line_number_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  vact_space2_end:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  vact_space2_start:10;
    };
}onms_active_space2_line_number_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  vact_space3_end:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  vact_space3_start:10;
    };
}onms_active_space3_line_number_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  vtotalde:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  vtotal:12;
    };
}onms_vs_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  vs_high_period:12;
        RBus_UInt32  res2:3;
        RBus_UInt32  hs_high_period:13;
    };
}onms_vshs_high_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hact:13;
        RBus_UInt32  hact_fract:3;
        RBus_UInt32  htotal:13;
        RBus_UInt32  htotal_fract:3;
    };
}onms_hs_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  vblank_len:8;
        RBus_UInt32  res2:4;
        RBus_UInt32  vact_start:12;
    };
}onms_vact_sta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  vact_space3_min:10;
        RBus_UInt32  vact_space2_min:10;
        RBus_UInt32  vact_space1_min:10;
    };
}onms_vact_space_min_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  as1_max_end:10;
        RBus_UInt32  as1_max_start:10;
        RBus_UInt32  as1_max_diff:10;
    };
}onms_vact_space1_max_info_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  as2_max_end:10;
        RBus_UInt32  as2_max_start:10;
        RBus_UInt32  as2_max_diff:10;
    };
}onms_vact_space2_max_info_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  as3_max_end:10;
        RBus_UInt32  as3_max_start:10;
        RBus_UInt32  as3_max_diff:10;
    };
}onms_vact_space3_max_info_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  as1_min_end:10;
        RBus_UInt32  as1_min_start:10;
        RBus_UInt32  as1_min_diff:10;
    };
}onms_vact_space1_min_info_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  as2_min_end:10;
        RBus_UInt32  as2_min_start:10;
        RBus_UInt32  as2_min_diff:10;
    };
}onms_vact_space2_min_info_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  as3_min_end:10;
        RBus_UInt32  as3_min_start:10;
        RBus_UInt32  as3_min_diff:10;
    };
}onms_vact_space3_min_info_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  blk_2frame_en:1;
        RBus_UInt32  vs_pol_out:1;
        RBus_UInt32  hs_pol_out:1;
        RBus_UInt32  vs_per_over_range:1;
        RBus_UInt32  hs_per_over_range:1;
        RBus_UInt32  vs_per_timeout:1;
        RBus_UInt32  vs_high_timeout:1;
        RBus_UInt32  vs_per_overflow:1;
        RBus_UInt32  hs_per_overflow:1;
        RBus_UInt32  vs_pol_chg:1;
        RBus_UInt32  hs_pol_chg:1;
        RBus_UInt32  vtotalde_chg:1;
        RBus_UInt32  vtotal_chg:1;
        RBus_UInt32  hact_chg:1;
        RBus_UInt32  htotal_chg:1;
        RBus_UInt32  hs_active_pixel_var:1;
        RBus_UInt32  vact_space3_under_min:1;
        RBus_UInt32  vact_space2_under_min:1;
        RBus_UInt32  vact_space1_under_min:1;
    };
}onms_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  wd_vs_per_over_range:1;
        RBus_UInt32  wd_hs_per_over_range:1;
        RBus_UInt32  wd_vs_per_timeout:1;
        RBus_UInt32  wd_vs_high_timeout:1;
        RBus_UInt32  wd_vs_per_overflow:1;
        RBus_UInt32  wd_hs_per_overflow:1;
        RBus_UInt32  wd_vs_pol_chg:1;
        RBus_UInt32  wd_hs_pol_chg:1;
        RBus_UInt32  wd_vtotalde_chg:1;
        RBus_UInt32  wd_vtotal_chg:1;
        RBus_UInt32  wd_hact_chg:1;
        RBus_UInt32  wd_htotal_chg:1;
        RBus_UInt32  wd_hs_active_pixel_var:1;
        RBus_UInt32  wd_vact_space3_under_min:1;
        RBus_UInt32  wd_vact_space2_under_min:1;
        RBus_UInt32  wd_vact_space1_under_min:1;
    };
}onms_watchdog_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  ie_vs_per_over_range:1;
        RBus_UInt32  ie_hs_per_over_range:1;
        RBus_UInt32  ie_vs_per_timeout:1;
        RBus_UInt32  ie_vs_high_timeout:1;
        RBus_UInt32  ie_vs_per_overflow:1;
        RBus_UInt32  ie_hs_per_overflow:1;
        RBus_UInt32  ie_vs_pol_chg:1;
        RBus_UInt32  ie_hs_pol_chg:1;
        RBus_UInt32  ie_vtotalde_chg:1;
        RBus_UInt32  ie_vtotal_chg:1;
        RBus_UInt32  ie_hact_chg:1;
        RBus_UInt32  ie_htotal_chg:1;
        RBus_UInt32  ie_hs_active_pixel_var:1;
        RBus_UInt32  ie_vact_space3_under_min:1;
        RBus_UInt32  ie_vact_space2_under_min:1;
        RBus_UInt32  ie_vact_space1_under_min:1;
    };
}onms_interrupt_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  hact_start:13;
    };
}onms_hact_sta_RBUS;





#else //apply LITTLE_ENDIAN


//======H3D_MS register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  start_ms:1;
        RBus_UInt32  ms_conti:1;
        RBus_UInt32  popup_meas:1;
        RBus_UInt32  hs_meas_inv:1;
        RBus_UInt32  vs_meas_inv:1;
        RBus_UInt32  sycms_clk:1;
        RBus_UInt32  meas_to_sel:1;
        RBus_UInt32  vact_space_meas_en:1;
        RBus_UInt32  vact_space_threshold:4;
        RBus_UInt32  pixel_encoding:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  htotal_max_delta:4;
        RBus_UInt32  vtotal_max_delta:4;
        RBus_UInt32  progressive:1;
        RBus_UInt32  pixel_get_sel:2;
        RBus_UInt32  pixel_get_en:1;
        RBus_UInt32  dummy_ctrl:4;
    };
}onms_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  get_g_value:12;
        RBus_UInt32  get_r_value:12;
        RBus_UInt32  pixel_ok:1;
        RBus_UInt32  res1:7;
    };
}onms_blank_pixel_value_get_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  get_b_value:12;
        RBus_UInt32  res1:20;
    };
}onms_blank_pixel_value_get_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  active_g_value:12;
        RBus_UInt32  active_r_value:12;
        RBus_UInt32  res1:8;
    };
}onms_blank_pixel_value_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  active_b_value:12;
        RBus_UInt32  res1:20;
    };
}onms_blank_pixel_value_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vact1:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  vact2:11;
        RBus_UInt32  res1:5;
    };
}onms_fp_vact12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vact3:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  vact4:11;
        RBus_UInt32  res1:5;
    };
}onms_fp_vact34_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fp_vact_space3:10;
        RBus_UInt32  fp_vact_space2:10;
        RBus_UInt32  fp_vact_space1:10;
        RBus_UInt32  res1:2;
    };
}onms_fp_vact_space_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_blank_line_end:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  r_blank_line_start:11;
        RBus_UInt32  res1:5;
    };
}onms_blank_line_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vact_space1_start:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  vact_space1_end:10;
        RBus_UInt32  res1:6;
    };
}onms_active_space1_line_number_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vact_space2_start:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  vact_space2_end:10;
        RBus_UInt32  res1:6;
    };
}onms_active_space2_line_number_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vact_space3_start:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  vact_space3_end:10;
        RBus_UInt32  res1:6;
    };
}onms_active_space3_line_number_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vtotal:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  vtotalde:12;
        RBus_UInt32  res1:4;
    };
}onms_vs_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hs_high_period:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  vs_high_period:12;
        RBus_UInt32  res1:4;
    };
}onms_vshs_high_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  htotal_fract:3;
        RBus_UInt32  htotal:13;
        RBus_UInt32  hact_fract:3;
        RBus_UInt32  hact:13;
    };
}onms_hs_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vact_start:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  vblank_len:8;
        RBus_UInt32  res1:8;
    };
}onms_vact_sta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vact_space1_min:10;
        RBus_UInt32  vact_space2_min:10;
        RBus_UInt32  vact_space3_min:10;
        RBus_UInt32  res1:2;
    };
}onms_vact_space_min_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  as1_max_diff:10;
        RBus_UInt32  as1_max_start:10;
        RBus_UInt32  as1_max_end:10;
        RBus_UInt32  res1:2;
    };
}onms_vact_space1_max_info_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  as2_max_diff:10;
        RBus_UInt32  as2_max_start:10;
        RBus_UInt32  as2_max_end:10;
        RBus_UInt32  res1:2;
    };
}onms_vact_space2_max_info_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  as3_max_diff:10;
        RBus_UInt32  as3_max_start:10;
        RBus_UInt32  as3_max_end:10;
        RBus_UInt32  res1:2;
    };
}onms_vact_space3_max_info_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  as1_min_diff:10;
        RBus_UInt32  as1_min_start:10;
        RBus_UInt32  as1_min_end:10;
        RBus_UInt32  res1:2;
    };
}onms_vact_space1_min_info_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  as2_min_diff:10;
        RBus_UInt32  as2_min_start:10;
        RBus_UInt32  as2_min_end:10;
        RBus_UInt32  res1:2;
    };
}onms_vact_space2_min_info_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  as3_min_diff:10;
        RBus_UInt32  as3_min_start:10;
        RBus_UInt32  as3_min_end:10;
        RBus_UInt32  res1:2;
    };
}onms_vact_space3_min_info_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vact_space1_under_min:1;
        RBus_UInt32  vact_space2_under_min:1;
        RBus_UInt32  vact_space3_under_min:1;
        RBus_UInt32  hs_active_pixel_var:1;
        RBus_UInt32  htotal_chg:1;
        RBus_UInt32  hact_chg:1;
        RBus_UInt32  vtotal_chg:1;
        RBus_UInt32  vtotalde_chg:1;
        RBus_UInt32  hs_pol_chg:1;
        RBus_UInt32  vs_pol_chg:1;
        RBus_UInt32  hs_per_overflow:1;
        RBus_UInt32  vs_per_overflow:1;
        RBus_UInt32  vs_high_timeout:1;
        RBus_UInt32  vs_per_timeout:1;
        RBus_UInt32  hs_per_over_range:1;
        RBus_UInt32  vs_per_over_range:1;
        RBus_UInt32  hs_pol_out:1;
        RBus_UInt32  vs_pol_out:1;
        RBus_UInt32  blk_2frame_en:1;
        RBus_UInt32  res1:13;
    };
}onms_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wd_vact_space1_under_min:1;
        RBus_UInt32  wd_vact_space2_under_min:1;
        RBus_UInt32  wd_vact_space3_under_min:1;
        RBus_UInt32  wd_hs_active_pixel_var:1;
        RBus_UInt32  wd_htotal_chg:1;
        RBus_UInt32  wd_hact_chg:1;
        RBus_UInt32  wd_vtotal_chg:1;
        RBus_UInt32  wd_vtotalde_chg:1;
        RBus_UInt32  wd_hs_pol_chg:1;
        RBus_UInt32  wd_vs_pol_chg:1;
        RBus_UInt32  wd_hs_per_overflow:1;
        RBus_UInt32  wd_vs_per_overflow:1;
        RBus_UInt32  wd_vs_high_timeout:1;
        RBus_UInt32  wd_vs_per_timeout:1;
        RBus_UInt32  wd_hs_per_over_range:1;
        RBus_UInt32  wd_vs_per_over_range:1;
        RBus_UInt32  res1:16;
    };
}onms_watchdog_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ie_vact_space1_under_min:1;
        RBus_UInt32  ie_vact_space2_under_min:1;
        RBus_UInt32  ie_vact_space3_under_min:1;
        RBus_UInt32  ie_hs_active_pixel_var:1;
        RBus_UInt32  ie_htotal_chg:1;
        RBus_UInt32  ie_hact_chg:1;
        RBus_UInt32  ie_vtotal_chg:1;
        RBus_UInt32  ie_vtotalde_chg:1;
        RBus_UInt32  ie_hs_pol_chg:1;
        RBus_UInt32  ie_vs_pol_chg:1;
        RBus_UInt32  ie_hs_per_overflow:1;
        RBus_UInt32  ie_vs_per_overflow:1;
        RBus_UInt32  ie_vs_high_timeout:1;
        RBus_UInt32  ie_vs_per_timeout:1;
        RBus_UInt32  ie_hs_per_over_range:1;
        RBus_UInt32  ie_vs_per_over_range:1;
        RBus_UInt32  res1:16;
    };
}onms_interrupt_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hact_start:13;
        RBus_UInt32  res1:19;
    };
}onms_hact_sta_RBUS;


#endif







#endif //_RBUS_H3D_MS_REG_H_

