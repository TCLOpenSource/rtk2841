/**
* @file rbusOsdFontReg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2008/1/2
* @version 1.1
* @ingroup model_rbus
*
*/

#ifndef _RBUS_OSDFONT_REG_H_
#define _RBUS_OSDFONT_REG_H_

#include "rbusTypes.h"




// OSDFONT Register Address
#define OSDFONT_OSD_F_PALETTE_ADDR                 (0x18005400)
#define OSDFONT_OSD_F_PALETTE_DATA_ADDR            (0x18005404)
#define OSDFONT_OSD_F_ADDR_ADDR                    (0x18005408)
#define OSDFONT_OSD_F_DATA_ADDR                    (0x1800540c)
#define OSDFONT_OSD_F_BIST_ADDR                    (0x18005410)
#define OSDFONT_OSD_F_BASE_ADDR_ADDR               (0x18005414)
#define OSDFONT_OSD_F_BISR_ADDR                    (0x18005418)
#define OSDFONT_OSD_WIN_PAT_ADDR_ADDR              (0x18005420)
#define OSDFONT_OSD_WIN_PAT_DATA_ADDR              (0x18005424)
#define OSDFONT_OSD_W0_FUNCS_ADDR                  (0x18005430)
#define OSDFONT_OSD_W0_START_POS_ADDR              (0x18005434)
#define OSDFONT_OSD_W0_END_POS_ADDR                (0x18005438)
#define OSDFONT_OSD_W0_CTRL_ADDR                   (0x1800543c)
#define OSDFONT_OSD_W0_GRADIENT_ADDR               (0x180054b0)
#define OSDFONT_OSD_W0_PAT_CTRL_ADDR               (0x180054c0)
#define OSDFONT_OSD_W0_PAT_COLOR_ADDR              (0x180054c4)
#define OSDFONT_OSD_W1_FUNCS_ADDR                  (0x18005440)
#define OSDFONT_OSD_W1_START_POS_ADDR              (0x18005444)
#define OSDFONT_OSD_W1_END_POS_ADDR                (0x18005448)
#define OSDFONT_OSD_W1_CTRL_ADDR                   (0x1800544c)
#define OSDFONT_OSD_W2_FUNCS_ADDR                  (0x18005450)
#define OSDFONT_OSD_W2_START_POS_ADDR              (0x18005454)
#define OSDFONT_OSD_W2_END_POS_ADDR                (0x18005458)
#define OSDFONT_OSD_W2_CTRL_ADDR                   (0x1800545c)
#define OSDFONT_OSD_W3_FUNCS_ADDR                  (0x18005460)
#define OSDFONT_OSD_W3_START_POS_ADDR              (0x18005464)
#define OSDFONT_OSD_W3_END_POS_ADDR                (0x18005468)
#define OSDFONT_OSD_W3_CTRL_ADDR                   (0x1800546c)
#define OSDFONT_OSD_W4_FUNCS_ADDR                  (0x18005470)
#define OSDFONT_OSD_W4_START_POS_ADDR              (0x18005474)
#define OSDFONT_OSD_W4_END_POS_ADDR                (0x18005478)
#define OSDFONT_OSD_W4_CTRL_ADDR                   (0x1800547c)
#define OSDFONT_OSD_W5_FUNCS_ADDR                  (0x18005480)
#define OSDFONT_OSD_W5_START_POS_ADDR              (0x18005484)
#define OSDFONT_OSD_W5_END_POS_ADDR                (0x18005488)
#define OSDFONT_OSD_W5_CTRL_ADDR                   (0x1800548c)
#define OSDFONT_OSD_W5_GRADIENT_ADDR               (0x180054b4)
#define OSDFONT_OSD_W6_FUNCS_ADDR                  (0x18005490)
#define OSDFONT_OSD_W6_START_POS_ADDR              (0x18005494)
#define OSDFONT_OSD_W6_END_POS_ADDR                (0x18005498)
#define OSDFONT_OSD_W6_CTRL_ADDR                   (0x1800549c)
#define OSDFONT_OSD_W6_GRADIENT_ADDR               (0x180054b8)
#define OSDFONT_OSD_W7_FUNCS_ADDR                  (0x180054a0)
#define OSDFONT_OSD_W7_START_POS_ADDR              (0x180054a4)
#define OSDFONT_OSD_W7_END_POS_ADDR                (0x180054a8)
#define OSDFONT_OSD_W7_CTRL_ADDR                   (0x180054ac)
#define OSDFONT_OSD_W7_GRADIENT_ADDR               (0x180054bc)
#define OSDFONT_OSD_W7_PAT_CTRL_ADDR               (0x180054c8)
#define OSDFONT_OSD_W7_PAT_COLOR_ADDR              (0x180054cc)
#define OSDFONT_OSD_FRAME_DELAY_ADDR               (0x180054f0)
#define OSDFONT_OSD_F_CTRL_ADDR                    (0x180054f4)
#define OSDFONT_OSD_ALPHA_BLEND_ADDR               (0x180054f8)

#define OSDFONT_OSD_F_PALETTE_VADDR                (0xb8005400)
#define OSDFONT_OSD_F_PALETTE_DATA_VADDR           (0xb8005404)
#define OSDFONT_OSD_F_ADDR_VADDR                   (0xb8005408)
#define OSDFONT_OSD_F_DATA_VADDR                   (0xb800540c)
#define OSDFONT_OSD_F_BIST_VADDR                   (0xb8005410)
#define OSDFONT_OSD_F_BASE_ADDR_VADDR              (0xb8005414)
#define OSDFONT_OSD_F_BISR_VADDR                   (0xb8005418)
#define OSDFONT_OSD_WIN_PAT_ADDR_VADDR             (0xb8005420)
#define OSDFONT_OSD_WIN_PAT_DATA_VADDR             (0xb8005424)
#define OSDFONT_OSD_W0_FUNCS_VADDR                 (0xb8005430)
#define OSDFONT_OSD_W0_START_POS_VADDR             (0xb8005434)
#define OSDFONT_OSD_W0_END_POS_VADDR               (0xb8005438)
#define OSDFONT_OSD_W0_CTRL_VADDR                  (0xb800543c)
#define OSDFONT_OSD_W0_GRADIENT_VADDR              (0xb80054b0)
#define OSDFONT_OSD_W0_PAT_CTRL_VADDR              (0xb80054c0)
#define OSDFONT_OSD_W0_PAT_COLOR_VADDR             (0xb80054c4)
#define OSDFONT_OSD_W1_FUNCS_VADDR                 (0xb8005440)
#define OSDFONT_OSD_W1_START_POS_VADDR             (0xb8005444)
#define OSDFONT_OSD_W1_END_POS_VADDR               (0xb8005448)
#define OSDFONT_OSD_W1_CTRL_VADDR                  (0xb800544c)
#define OSDFONT_OSD_W2_FUNCS_VADDR                 (0xb8005450)
#define OSDFONT_OSD_W2_START_POS_VADDR             (0xb8005454)
#define OSDFONT_OSD_W2_END_POS_VADDR               (0xb8005458)
#define OSDFONT_OSD_W2_CTRL_VADDR                  (0xb800545c)
#define OSDFONT_OSD_W3_FUNCS_VADDR                 (0xb8005460)
#define OSDFONT_OSD_W3_START_POS_VADDR             (0xb8005464)
#define OSDFONT_OSD_W3_END_POS_VADDR               (0xb8005468)
#define OSDFONT_OSD_W3_CTRL_VADDR                  (0xb800546c)
#define OSDFONT_OSD_W4_FUNCS_VADDR                 (0xb8005470)
#define OSDFONT_OSD_W4_START_POS_VADDR             (0xb8005474)
#define OSDFONT_OSD_W4_END_POS_VADDR               (0xb8005478)
#define OSDFONT_OSD_W4_CTRL_VADDR                  (0xb800547c)
#define OSDFONT_OSD_W5_FUNCS_VADDR                 (0xb8005480)
#define OSDFONT_OSD_W5_START_POS_VADDR             (0xb8005484)
#define OSDFONT_OSD_W5_END_POS_VADDR               (0xb8005488)
#define OSDFONT_OSD_W5_CTRL_VADDR                  (0xb800548c)
#define OSDFONT_OSD_W5_GRADIENT_VADDR              (0xb80054b4)
#define OSDFONT_OSD_W6_FUNCS_VADDR                 (0xb8005490)
#define OSDFONT_OSD_W6_START_POS_VADDR             (0xb8005494)
#define OSDFONT_OSD_W6_END_POS_VADDR               (0xb8005498)
#define OSDFONT_OSD_W6_CTRL_VADDR                  (0xb800549c)
#define OSDFONT_OSD_W6_GRADIENT_VADDR              (0xb80054b8)
#define OSDFONT_OSD_W7_FUNCS_VADDR                 (0xb80054a0)
#define OSDFONT_OSD_W7_START_POS_VADDR             (0xb80054a4)
#define OSDFONT_OSD_W7_END_POS_VADDR               (0xb80054a8)
#define OSDFONT_OSD_W7_CTRL_VADDR                  (0xb80054ac)
#define OSDFONT_OSD_W7_GRADIENT_VADDR              (0xb80054bc)
#define OSDFONT_OSD_W7_PAT_CTRL_VADDR              (0xb80054c8)
#define OSDFONT_OSD_W7_PAT_COLOR_VADDR             (0xb80054cc)
#define OSDFONT_OSD_FRAME_DELAY_VADDR              (0xb80054f0)
#define OSDFONT_OSD_F_CTRL_VADDR                   (0xb80054f4)
#define OSDFONT_OSD_ALPHA_BLEND_VADDR              (0xb80054f8)




#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======OSDFONT register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  osd_f_bist_priod:1;
        RBus_UInt32  osd_f_bist_ok:1;
        RBus_UInt32  osd_f_bist_en:1;
        RBus_UInt32  osd_f_plaette_en:1;
        RBus_UInt32  osd_f_lut_index:7;
    };
}osd_f_palette_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  osd_f_lut_data:24;
    };
}osd_f_palette_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  osd_f_addr:12;
    };
}osd_f_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  osd_f_data:24;
    };
}osd_f_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  osd_f_host_w_status:1;
        RBus_UInt32  osd_f_dbuff_w_status:1;
        RBus_UInt32  osd_f_dbuff_auto_load:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  osd_f_dbuffer_num:2;
        RBus_UInt32  osd_sram_dat:24;
    };
}osd_f_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  osd_f_font_table_baddr:12;
        RBus_UInt32  osd_f_char_cmd_baddr:12;
    };
}osd_f_base_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bisr_pwr_rst:1;
        RBus_UInt32  bisr_so_1:11;
        RBus_UInt32  bisr_so_0:11;
        RBus_UInt32  res1:2;
        RBus_UInt32  bisr_fail_1:1;
        RBus_UInt32  bisr_fail_0:1;
        RBus_UInt32  hold_remap:1;
        RBus_UInt32  bisr_repaired:1;
        RBus_UInt32  bisr_done:1;
        RBus_UInt32  bisr_soft_rst:1;
        RBus_UInt32  bisr_soft_run:1;
    };
}osd_f_bisr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  win_pat_data_en:1;
        RBus_UInt32  win_pat_bist_period:1;
        RBus_UInt32  win_pat_bist_status:1;
        RBus_UInt32  win_pat_bist_enable:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  win_pat_addr:8;
    };
}osd_win_pat_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  win_pat_data:8;
    };
}osd_win_pat_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  w0_r_gradient:1;
        RBus_UInt32  w0_g_gradient:1;
        RBus_UInt32  w0_b_gradient:1;
        RBus_UInt32  w0_gradient_step:2;
        RBus_UInt32  w0_r_gradient_en:1;
        RBus_UInt32  w0_g_gradient_en:1;
        RBus_UInt32  w0_b_gradient_en:1;
        RBus_UInt32  w0_shadow_color:4;
        RBus_UInt32  w0_border_color:4;
        RBus_UInt32  w0_gradient_factor:2;
        RBus_UInt32  w0_shadow_border_3d_width:3;
        RBus_UInt32  w0_shadow_border_height:3;
    };
}osd_w0_funcs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  w0_start_v:11;
        RBus_UInt32  w0_start_h:11;
        RBus_UInt32  res2:2;
    };
}osd_w0_start_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  w0_end_v:11;
        RBus_UInt32  w0_end_h:11;
        RBus_UInt32  res2:2;
    };
}osd_w0_end_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  w0_gradient_enable:1;
        RBus_UInt32  w0_gradient_direction:1;
        RBus_UInt32  w0_shadow_border_3d_en:1;
        RBus_UInt32  w0_type:3;
        RBus_UInt32  w0_enable:1;
        RBus_UInt32  w0_gradient_type:1;
        RBus_UInt32  w0_level_size:3;
        RBus_UInt32  w0_color_index:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  w0_lut_index:3;
        RBus_UInt32  res3:4;
    };
}osd_w0_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  w0_gradient2_start:11;
        RBus_UInt32  w0_gradient2_end:11;
        RBus_UInt32  res2:2;
    };
}osd_w0_gradient_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  w0_pattern:1;
        RBus_UInt32  w0_pat_v_line:8;
        RBus_UInt32  w0_pat_h_pixel:8;
    };
}osd_w0_pat_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  w0_pat_r:8;
        RBus_UInt32  w0_pat_g:8;
        RBus_UInt32  w0_pat_b:8;
    };
}osd_w0_pat_color_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  w1_shadow_color:4;
        RBus_UInt32  w1_border_color:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  w1_shadow_border_3d_width:3;
        RBus_UInt32  w1_shadow_border_height:3;
    };
}osd_w1_funcs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  w1_start_v:11;
        RBus_UInt32  w1_start_h:11;
        RBus_UInt32  res2:2;
    };
}osd_w1_start_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  w1_end_v:11;
        RBus_UInt32  w1_end_h:11;
        RBus_UInt32  res2:2;
    };
}osd_w1_end_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  w1_shadow_border_3d_en:1;
        RBus_UInt32  w1_type:3;
        RBus_UInt32  w1_enable:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  w1_color_index:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  w1_lut_index:3;
        RBus_UInt32  res4:4;
    };
}osd_w1_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  w2_shadow_color:4;
        RBus_UInt32  w2_border_color:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  w2_shadow_border_3d_width:3;
        RBus_UInt32  w2_shadow_border_height:3;
    };
}osd_w2_funcs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  w2_start_v:11;
        RBus_UInt32  w2_start_h:11;
        RBus_UInt32  res2:2;
    };
}osd_w2_start_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  w2_end_v:11;
        RBus_UInt32  w2_end_h:11;
        RBus_UInt32  res2:2;
    };
}osd_w2_end_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  w2_shadow_border_3d_en:1;
        RBus_UInt32  w2_type:3;
        RBus_UInt32  w2_enable:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  w2_color_index:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  w2_lut_index:3;
        RBus_UInt32  res4:4;
    };
}osd_w2_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  w3_shadow_color:4;
        RBus_UInt32  w3_border_color:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  w3_shadow_border_3d_width:3;
        RBus_UInt32  w3_shadow_border_height:3;
    };
}osd_w3_funcs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  w3_start_v:11;
        RBus_UInt32  w3_start_h:11;
        RBus_UInt32  res2:2;
    };
}osd_w3_start_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  w3_end_v:11;
        RBus_UInt32  w3_end_h:11;
        RBus_UInt32  res2:2;
    };
}osd_w3_end_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  w3_shadow_border_3d_en:1;
        RBus_UInt32  w3_type:3;
        RBus_UInt32  w3_enable:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  w3_color_index:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  w3_lut_index:3;
        RBus_UInt32  res4:4;
    };
}osd_w3_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  w4_shadow_color:4;
        RBus_UInt32  w4_border_color:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  w4_shadow_border_3d_width:3;
        RBus_UInt32  w4_shadow_border_height:3;
    };
}osd_w4_funcs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  w4_start_v:11;
        RBus_UInt32  w4_start_h:11;
        RBus_UInt32  res2:2;
    };
}osd_w4_start_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  w4_end_v:11;
        RBus_UInt32  w4_end_h:11;
        RBus_UInt32  res2:2;
    };
}osd_w4_end_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  w4_shadow_border_3d_en:1;
        RBus_UInt32  w4_type:3;
        RBus_UInt32  w4_enable:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  w4_color_index:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  w4_lut_index:3;
        RBus_UInt32  res4:4;
    };
}osd_w4_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  w5_r_gradient:1;
        RBus_UInt32  w5_g_gradient:1;
        RBus_UInt32  w5_b_gradient:1;
        RBus_UInt32  w5_gradient_step:2;
        RBus_UInt32  w5_r_gradient_en:1;
        RBus_UInt32  w5_g_gradient_en:1;
        RBus_UInt32  w5_b_gradient_en:1;
        RBus_UInt32  w5_shadow_color:4;
        RBus_UInt32  w5_border_color:4;
        RBus_UInt32  w5_gradient_factor:2;
        RBus_UInt32  w5_shadow_border_3d_width:3;
        RBus_UInt32  w5_shadow_border_height:3;
    };
}osd_w5_funcs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  w5_start_v:11;
        RBus_UInt32  w5_start_h:11;
        RBus_UInt32  res2:2;
    };
}osd_w5_start_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  w5_end_v:11;
        RBus_UInt32  w5_end_h:11;
        RBus_UInt32  res2:2;
    };
}osd_w5_end_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  w5_gradient_enable:1;
        RBus_UInt32  w5_gradient_direction:1;
        RBus_UInt32  w5_shadow_border_3d_en:1;
        RBus_UInt32  w5_type:3;
        RBus_UInt32  w5_enable:1;
        RBus_UInt32  w5_gradient_type:1;
        RBus_UInt32  w5_level_size:3;
        RBus_UInt32  w5_color_index:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  w5_lut_index:3;
        RBus_UInt32  res3:4;
    };
}osd_w5_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  w5_gradient2_start:11;
        RBus_UInt32  w5_gradient2_end:11;
        RBus_UInt32  res2:2;
    };
}osd_w5_gradient_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  w6_r_gradient:1;
        RBus_UInt32  w6_g_gradient:1;
        RBus_UInt32  w6_b_gradient:1;
        RBus_UInt32  w6_gradient_step:2;
        RBus_UInt32  w6_r_gradient_en:1;
        RBus_UInt32  w6_g_gradient_en:1;
        RBus_UInt32  w6_b_gradient_en:1;
        RBus_UInt32  w6_shadow_color:4;
        RBus_UInt32  w6_border_color:4;
        RBus_UInt32  w6_gradient_factor:2;
        RBus_UInt32  w6_shadow_border_3d_width:3;
        RBus_UInt32  w6_shadow_border_height:3;
    };
}osd_w6_funcs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  w6_start_v:11;
        RBus_UInt32  w6_start_h:11;
        RBus_UInt32  res2:2;
    };
}osd_w6_start_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  w6_end_v:11;
        RBus_UInt32  w6_end_h:11;
        RBus_UInt32  res2:2;
    };
}osd_w6_end_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  w6_gradient_enable:1;
        RBus_UInt32  w6_gradient_direction:1;
        RBus_UInt32  w6_shadow_border_3d_en:1;
        RBus_UInt32  w6_type:3;
        RBus_UInt32  w6_enable:1;
        RBus_UInt32  w6_gradient_type:1;
        RBus_UInt32  w6_level_size:3;
        RBus_UInt32  w6_color_index:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  w6_lut_index:3;
        RBus_UInt32  res3:4;
    };
}osd_w6_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  w6_gradient2_start:11;
        RBus_UInt32  w6_gradient2_end:11;
        RBus_UInt32  res2:2;
    };
}osd_w6_gradient_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  w7_r_gradient:1;
        RBus_UInt32  w7_g_gradient:1;
        RBus_UInt32  w7_b_gradient:1;
        RBus_UInt32  w7_gradient_step:2;
        RBus_UInt32  w7_r_gradient_en:1;
        RBus_UInt32  w7_g_gradient_en:1;
        RBus_UInt32  w7_b_gradient_en:1;
        RBus_UInt32  w7_shadow_color:4;
        RBus_UInt32  w7_border_color:4;
        RBus_UInt32  w7_gradient_factor:2;
        RBus_UInt32  w7_shadow_border_3d_width:3;
        RBus_UInt32  w7_shadow_border_height:3;
    };
}osd_w7_funcs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  w7_start_v:11;
        RBus_UInt32  w7_start_h:11;
        RBus_UInt32  res2:2;
    };
}osd_w7_start_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  w7_end_v:11;
        RBus_UInt32  w7_end_h:11;
        RBus_UInt32  res2:2;
    };
}osd_w7_end_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  w7_gradient_enable:1;
        RBus_UInt32  w7_gradient_direction:1;
        RBus_UInt32  w7_shadow_border_3d_en:1;
        RBus_UInt32  w7_type:3;
        RBus_UInt32  w7_enable:1;
        RBus_UInt32  w7_gradient_type:1;
        RBus_UInt32  w7_level_size:3;
        RBus_UInt32  w7_color_index:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  w7_lut_index:3;
        RBus_UInt32  res3:4;
    };
}osd_w7_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  w7_gradient2_start:11;
        RBus_UInt32  w7_gradient2_end:11;
        RBus_UInt32  res2:2;
    };
}osd_w7_gradient_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  w7_pattern:1;
        RBus_UInt32  w7_pat_v_line:8;
        RBus_UInt32  w7_pat_h_pixel:8;
    };
}osd_w7_pat_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  w7_pat_r:8;
        RBus_UInt32  w7_pat_g:8;
        RBus_UInt32  w7_pat_b:8;
    };
}osd_w7_pat_color_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  frame_h_delay:12;
        RBus_UInt32  res2:1;
        RBus_UInt32  frame_v_delay:11;
    };
}osd_frame_delay_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  global_clk_on:1;
        RBus_UInt32  frame_blinking_en:1;
        RBus_UInt32  frame_smaller_char:2;
        RBus_UInt32  font_rotate:1;
        RBus_UInt32  osd_en:1;
    };
}osd_f_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  font_download_swap:2;
        RBus_UInt32  res2:6;
        RBus_UInt32  char_shadow_border_color:4;
        RBus_UInt32  frame_blending_en:1;
        RBus_UInt32  frame_blending_type:1;
        RBus_UInt32  frame_double_width:1;
        RBus_UInt32  frame_double_height:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  w7_fade_en:1;
        RBus_UInt32  w7_mask_area:1;
        RBus_UInt32  res4:5;
    };
}osd_alpha_blend_RBUS;





#else //apply LITTLE_ENDIAN


//======OSDFONT register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_f_lut_index:7;
        RBus_UInt32  osd_f_plaette_en:1;
        RBus_UInt32  osd_f_bist_en:1;
        RBus_UInt32  osd_f_bist_ok:1;
        RBus_UInt32  osd_f_bist_priod:1;
        RBus_UInt32  res1:21;
    };
}osd_f_palette_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_f_lut_data:24;
        RBus_UInt32  res1:8;
    };
}osd_f_palette_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_f_addr:12;
        RBus_UInt32  res1:20;
    };
}osd_f_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_f_data:24;
        RBus_UInt32  res1:8;
    };
}osd_f_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_sram_dat:24;
        RBus_UInt32  osd_f_dbuffer_num:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  osd_f_dbuff_auto_load:1;
        RBus_UInt32  osd_f_dbuff_w_status:1;
        RBus_UInt32  osd_f_host_w_status:1;
        RBus_UInt32  res1:2;
    };
}osd_f_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_f_char_cmd_baddr:12;
        RBus_UInt32  osd_f_font_table_baddr:12;
        RBus_UInt32  res1:8;
    };
}osd_f_base_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bisr_soft_run:1;
        RBus_UInt32  bisr_soft_rst:1;
        RBus_UInt32  bisr_done:1;
        RBus_UInt32  bisr_repaired:1;
        RBus_UInt32  hold_remap:1;
        RBus_UInt32  bisr_fail_0:1;
        RBus_UInt32  bisr_fail_1:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  bisr_so_0:11;
        RBus_UInt32  bisr_so_1:11;
        RBus_UInt32  bisr_pwr_rst:1;
    };
}osd_f_bisr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  win_pat_addr:8;
        RBus_UInt32  res2:4;
        RBus_UInt32  win_pat_bist_enable:1;
        RBus_UInt32  win_pat_bist_status:1;
        RBus_UInt32  win_pat_bist_period:1;
        RBus_UInt32  win_pat_data_en:1;
        RBus_UInt32  res1:16;
    };
}osd_win_pat_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  win_pat_data:8;
        RBus_UInt32  res1:24;
    };
}osd_win_pat_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  w0_shadow_border_height:3;
        RBus_UInt32  w0_shadow_border_3d_width:3;
        RBus_UInt32  w0_gradient_factor:2;
        RBus_UInt32  w0_border_color:4;
        RBus_UInt32  w0_shadow_color:4;
        RBus_UInt32  w0_b_gradient_en:1;
        RBus_UInt32  w0_g_gradient_en:1;
        RBus_UInt32  w0_r_gradient_en:1;
        RBus_UInt32  w0_gradient_step:2;
        RBus_UInt32  w0_b_gradient:1;
        RBus_UInt32  w0_g_gradient:1;
        RBus_UInt32  w0_r_gradient:1;
        RBus_UInt32  res1:8;
    };
}osd_w0_funcs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:2;
        RBus_UInt32  w0_start_h:11;
        RBus_UInt32  w0_start_v:11;
        RBus_UInt32  res1:8;
    };
}osd_w0_start_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:2;
        RBus_UInt32  w0_end_h:11;
        RBus_UInt32  w0_end_v:11;
        RBus_UInt32  res1:8;
    };
}osd_w0_end_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res3:4;
        RBus_UInt32  w0_lut_index:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  w0_color_index:4;
        RBus_UInt32  w0_level_size:3;
        RBus_UInt32  w0_gradient_type:1;
        RBus_UInt32  w0_enable:1;
        RBus_UInt32  w0_type:3;
        RBus_UInt32  w0_shadow_border_3d_en:1;
        RBus_UInt32  w0_gradient_direction:1;
        RBus_UInt32  w0_gradient_enable:1;
        RBus_UInt32  res1:9;
    };
}osd_w0_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:2;
        RBus_UInt32  w0_gradient2_end:11;
        RBus_UInt32  w0_gradient2_start:11;
        RBus_UInt32  res1:8;
    };
}osd_w0_gradient_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  w0_pat_h_pixel:8;
        RBus_UInt32  w0_pat_v_line:8;
        RBus_UInt32  w0_pattern:1;
        RBus_UInt32  res1:15;
    };
}osd_w0_pat_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  w0_pat_b:8;
        RBus_UInt32  w0_pat_g:8;
        RBus_UInt32  w0_pat_r:8;
        RBus_UInt32  res1:8;
    };
}osd_w0_pat_color_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  w1_shadow_border_height:3;
        RBus_UInt32  w1_shadow_border_3d_width:3;
        RBus_UInt32  res2:2;
        RBus_UInt32  w1_border_color:4;
        RBus_UInt32  w1_shadow_color:4;
        RBus_UInt32  res1:16;
    };
}osd_w1_funcs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:2;
        RBus_UInt32  w1_start_h:11;
        RBus_UInt32  w1_start_v:11;
        RBus_UInt32  res1:8;
    };
}osd_w1_start_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:2;
        RBus_UInt32  w1_end_h:11;
        RBus_UInt32  w1_end_v:11;
        RBus_UInt32  res1:8;
    };
}osd_w1_end_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res4:4;
        RBus_UInt32  w1_lut_index:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  w1_color_index:4;
        RBus_UInt32  res2:4;
        RBus_UInt32  w1_enable:1;
        RBus_UInt32  w1_type:3;
        RBus_UInt32  w1_shadow_border_3d_en:1;
        RBus_UInt32  res1:11;
    };
}osd_w1_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  w2_shadow_border_height:3;
        RBus_UInt32  w2_shadow_border_3d_width:3;
        RBus_UInt32  res2:2;
        RBus_UInt32  w2_border_color:4;
        RBus_UInt32  w2_shadow_color:4;
        RBus_UInt32  res1:16;
    };
}osd_w2_funcs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:2;
        RBus_UInt32  w2_start_h:11;
        RBus_UInt32  w2_start_v:11;
        RBus_UInt32  res1:8;
    };
}osd_w2_start_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:2;
        RBus_UInt32  w2_end_h:11;
        RBus_UInt32  w2_end_v:11;
        RBus_UInt32  res1:8;
    };
}osd_w2_end_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res4:4;
        RBus_UInt32  w2_lut_index:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  w2_color_index:4;
        RBus_UInt32  res2:4;
        RBus_UInt32  w2_enable:1;
        RBus_UInt32  w2_type:3;
        RBus_UInt32  w2_shadow_border_3d_en:1;
        RBus_UInt32  res1:11;
    };
}osd_w2_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  w3_shadow_border_height:3;
        RBus_UInt32  w3_shadow_border_3d_width:3;
        RBus_UInt32  res2:2;
        RBus_UInt32  w3_border_color:4;
        RBus_UInt32  w3_shadow_color:4;
        RBus_UInt32  res1:16;
    };
}osd_w3_funcs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:2;
        RBus_UInt32  w3_start_h:11;
        RBus_UInt32  w3_start_v:11;
        RBus_UInt32  res1:8;
    };
}osd_w3_start_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:2;
        RBus_UInt32  w3_end_h:11;
        RBus_UInt32  w3_end_v:11;
        RBus_UInt32  res1:8;
    };
}osd_w3_end_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res4:4;
        RBus_UInt32  w3_lut_index:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  w3_color_index:4;
        RBus_UInt32  res2:4;
        RBus_UInt32  w3_enable:1;
        RBus_UInt32  w3_type:3;
        RBus_UInt32  w3_shadow_border_3d_en:1;
        RBus_UInt32  res1:11;
    };
}osd_w3_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  w4_shadow_border_height:3;
        RBus_UInt32  w4_shadow_border_3d_width:3;
        RBus_UInt32  res2:2;
        RBus_UInt32  w4_border_color:4;
        RBus_UInt32  w4_shadow_color:4;
        RBus_UInt32  res1:16;
    };
}osd_w4_funcs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:2;
        RBus_UInt32  w4_start_h:11;
        RBus_UInt32  w4_start_v:11;
        RBus_UInt32  res1:8;
    };
}osd_w4_start_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:2;
        RBus_UInt32  w4_end_h:11;
        RBus_UInt32  w4_end_v:11;
        RBus_UInt32  res1:8;
    };
}osd_w4_end_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res4:4;
        RBus_UInt32  w4_lut_index:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  w4_color_index:4;
        RBus_UInt32  res2:4;
        RBus_UInt32  w4_enable:1;
        RBus_UInt32  w4_type:3;
        RBus_UInt32  w4_shadow_border_3d_en:1;
        RBus_UInt32  res1:11;
    };
}osd_w4_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  w5_shadow_border_height:3;
        RBus_UInt32  w5_shadow_border_3d_width:3;
        RBus_UInt32  w5_gradient_factor:2;
        RBus_UInt32  w5_border_color:4;
        RBus_UInt32  w5_shadow_color:4;
        RBus_UInt32  w5_b_gradient_en:1;
        RBus_UInt32  w5_g_gradient_en:1;
        RBus_UInt32  w5_r_gradient_en:1;
        RBus_UInt32  w5_gradient_step:2;
        RBus_UInt32  w5_b_gradient:1;
        RBus_UInt32  w5_g_gradient:1;
        RBus_UInt32  w5_r_gradient:1;
        RBus_UInt32  res1:8;
    };
}osd_w5_funcs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:2;
        RBus_UInt32  w5_start_h:11;
        RBus_UInt32  w5_start_v:11;
        RBus_UInt32  res1:8;
    };
}osd_w5_start_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:2;
        RBus_UInt32  w5_end_h:11;
        RBus_UInt32  w5_end_v:11;
        RBus_UInt32  res1:8;
    };
}osd_w5_end_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res3:4;
        RBus_UInt32  w5_lut_index:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  w5_color_index:4;
        RBus_UInt32  w5_level_size:3;
        RBus_UInt32  w5_gradient_type:1;
        RBus_UInt32  w5_enable:1;
        RBus_UInt32  w5_type:3;
        RBus_UInt32  w5_shadow_border_3d_en:1;
        RBus_UInt32  w5_gradient_direction:1;
        RBus_UInt32  w5_gradient_enable:1;
        RBus_UInt32  res1:9;
    };
}osd_w5_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:2;
        RBus_UInt32  w5_gradient2_end:11;
        RBus_UInt32  w5_gradient2_start:11;
        RBus_UInt32  res1:8;
    };
}osd_w5_gradient_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  w6_shadow_border_height:3;
        RBus_UInt32  w6_shadow_border_3d_width:3;
        RBus_UInt32  w6_gradient_factor:2;
        RBus_UInt32  w6_border_color:4;
        RBus_UInt32  w6_shadow_color:4;
        RBus_UInt32  w6_b_gradient_en:1;
        RBus_UInt32  w6_g_gradient_en:1;
        RBus_UInt32  w6_r_gradient_en:1;
        RBus_UInt32  w6_gradient_step:2;
        RBus_UInt32  w6_b_gradient:1;
        RBus_UInt32  w6_g_gradient:1;
        RBus_UInt32  w6_r_gradient:1;
        RBus_UInt32  res1:8;
    };
}osd_w6_funcs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:2;
        RBus_UInt32  w6_start_h:11;
        RBus_UInt32  w6_start_v:11;
        RBus_UInt32  res1:8;
    };
}osd_w6_start_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:2;
        RBus_UInt32  w6_end_h:11;
        RBus_UInt32  w6_end_v:11;
        RBus_UInt32  res1:8;
    };
}osd_w6_end_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res3:4;
        RBus_UInt32  w6_lut_index:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  w6_color_index:4;
        RBus_UInt32  w6_level_size:3;
        RBus_UInt32  w6_gradient_type:1;
        RBus_UInt32  w6_enable:1;
        RBus_UInt32  w6_type:3;
        RBus_UInt32  w6_shadow_border_3d_en:1;
        RBus_UInt32  w6_gradient_direction:1;
        RBus_UInt32  w6_gradient_enable:1;
        RBus_UInt32  res1:9;
    };
}osd_w6_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:2;
        RBus_UInt32  w6_gradient2_end:11;
        RBus_UInt32  w6_gradient2_start:11;
        RBus_UInt32  res1:8;
    };
}osd_w6_gradient_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  w7_shadow_border_height:3;
        RBus_UInt32  w7_shadow_border_3d_width:3;
        RBus_UInt32  w7_gradient_factor:2;
        RBus_UInt32  w7_border_color:4;
        RBus_UInt32  w7_shadow_color:4;
        RBus_UInt32  w7_b_gradient_en:1;
        RBus_UInt32  w7_g_gradient_en:1;
        RBus_UInt32  w7_r_gradient_en:1;
        RBus_UInt32  w7_gradient_step:2;
        RBus_UInt32  w7_b_gradient:1;
        RBus_UInt32  w7_g_gradient:1;
        RBus_UInt32  w7_r_gradient:1;
        RBus_UInt32  res1:8;
    };
}osd_w7_funcs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:2;
        RBus_UInt32  w7_start_h:11;
        RBus_UInt32  w7_start_v:11;
        RBus_UInt32  res1:8;
    };
}osd_w7_start_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:2;
        RBus_UInt32  w7_end_h:11;
        RBus_UInt32  w7_end_v:11;
        RBus_UInt32  res1:8;
    };
}osd_w7_end_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res3:4;
        RBus_UInt32  w7_lut_index:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  w7_color_index:4;
        RBus_UInt32  w7_level_size:3;
        RBus_UInt32  w7_gradient_type:1;
        RBus_UInt32  w7_enable:1;
        RBus_UInt32  w7_type:3;
        RBus_UInt32  w7_shadow_border_3d_en:1;
        RBus_UInt32  w7_gradient_direction:1;
        RBus_UInt32  w7_gradient_enable:1;
        RBus_UInt32  res1:9;
    };
}osd_w7_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:2;
        RBus_UInt32  w7_gradient2_end:11;
        RBus_UInt32  w7_gradient2_start:11;
        RBus_UInt32  res1:8;
    };
}osd_w7_gradient_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  w7_pat_h_pixel:8;
        RBus_UInt32  w7_pat_v_line:8;
        RBus_UInt32  w7_pattern:1;
        RBus_UInt32  res1:15;
    };
}osd_w7_pat_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  w7_pat_b:8;
        RBus_UInt32  w7_pat_g:8;
        RBus_UInt32  w7_pat_r:8;
        RBus_UInt32  res1:8;
    };
}osd_w7_pat_color_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  frame_v_delay:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  frame_h_delay:12;
        RBus_UInt32  res1:8;
    };
}osd_frame_delay_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_en:1;
        RBus_UInt32  font_rotate:1;
        RBus_UInt32  frame_smaller_char:2;
        RBus_UInt32  frame_blinking_en:1;
        RBus_UInt32  global_clk_on:1;
        RBus_UInt32  res1:26;
    };
}osd_f_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res4:5;
        RBus_UInt32  w7_mask_area:1;
        RBus_UInt32  w7_fade_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  frame_double_height:1;
        RBus_UInt32  frame_double_width:1;
        RBus_UInt32  frame_blending_type:1;
        RBus_UInt32  frame_blending_en:1;
        RBus_UInt32  char_shadow_border_color:4;
        RBus_UInt32  res2:6;
        RBus_UInt32  font_download_swap:2;
        RBus_UInt32  res1:8;
    };
}osd_alpha_blend_RBUS;


#endif







#endif //_RBUS_OSDFONT_REG_H_

