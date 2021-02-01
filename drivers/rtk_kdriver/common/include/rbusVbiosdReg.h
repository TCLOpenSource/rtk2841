/**
* @file rbusVbiosdReg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2008/1/4
* @version 1.1
* @ingroup model_rbus
*
*/

#ifndef _RBUS_VBIOSD_REG_H_
#define _RBUS_VBIOSD_REG_H_

#include "rbus/rbusTypes.h"




// VBIOSD Register Address
#define VBIOSD_OSD_V_POSITION_ADDR                 (0x18005200)
#define VBIOSD_OSD_V_ROW_ADDR                      (0x18005204)
#define VBIOSD_OSD_V_LINE_ADDR                     (0x18005208)
#define VBIOSD_OVL_V_CTRL_ADDR                     (0x1800520c)
#define VBIOSD_OSD_V_COLOR0_ADDR                   (0x18005210)
#define VBIOSD_OSD_V_COLOR1_ADDR                   (0x18005214)
#define VBIOSD_OSD_V_COLOR2_ADDR                   (0x18005218)
#define VBIOSD_OSD_V_COLOR3_ADDR                   (0x1800521c)
#define VBIOSD_OSD_V_COLOR4_ADDR                   (0x18005220)
#define VBIOSD_OSD_V_COLOR5_ADDR                   (0x18005224)
#define VBIOSD_OSD_V_COLOR6_ADDR                   (0x18005228)
#define VBIOSD_OSD_V_COLOR7_ADDR                   (0x1800522c)
#define VBIOSD_OSD_V_COLOR8_ADDR                   (0x18005230)
#define VBIOSD_OSD_V_COLOR9_ADDR                   (0x18005234)
#define VBIOSD_OSD_V_COLOR10_ADDR                  (0x18005238)
#define VBIOSD_OSD_V_COLOR11_ADDR                  (0x1800523c)
#define VBIOSD_OSD_V_COLOR12_ADDR                  (0x18005240)
#define VBIOSD_OSD_V_COLOR13_ADDR                  (0x18005244)
#define VBIOSD_OSD_V_COLOR14_ADDR                  (0x18005248)
#define VBIOSD_OSD_V_COLOR15_ADDR                  (0x1800524c)
#define VBIOSD_OSD_V_FONT_ADDR_ADDR                (0x18005250)
#define VBIOSD_OSD_V_FIFO_ADDR                     (0x18005254)
#define VBIOSD_OSD_V_MEM_START_ADDR                (0x18005258)
#define VBIOSD_OSD_V_BIST_STATUS_ADDR              (0x1800525c)

#define VBIOSD_OSD_V_POSITION_VADDR                (0xb8005200)
#define VBIOSD_OSD_V_ROW_VADDR                     (0xb8005204)
#define VBIOSD_OSD_V_LINE_VADDR                    (0xb8005208)
#define VBIOSD_OVL_V_CTRL_VADDR                    (0xb800520c)
#define VBIOSD_OSD_V_COLOR0_VADDR                  (0xb8005210)
#define VBIOSD_OSD_V_COLOR1_VADDR                  (0xb8005214)
#define VBIOSD_OSD_V_COLOR2_VADDR                  (0xb8005218)
#define VBIOSD_OSD_V_COLOR3_VADDR                  (0xb800521c)
#define VBIOSD_OSD_V_COLOR4_VADDR                  (0xb8005220)
#define VBIOSD_OSD_V_COLOR5_VADDR                  (0xb8005224)
#define VBIOSD_OSD_V_COLOR6_VADDR                  (0xb8005228)
#define VBIOSD_OSD_V_COLOR7_VADDR                  (0xb800522c)
#define VBIOSD_OSD_V_COLOR8_VADDR                  (0xb8005230)
#define VBIOSD_OSD_V_COLOR9_VADDR                  (0xb8005234)
#define VBIOSD_OSD_V_COLOR10_VADDR                 (0xb8005238)
#define VBIOSD_OSD_V_COLOR11_VADDR                 (0xb800523c)
#define VBIOSD_OSD_V_COLOR12_VADDR                 (0xb8005240)
#define VBIOSD_OSD_V_COLOR13_VADDR                 (0xb8005244)
#define VBIOSD_OSD_V_COLOR14_VADDR                 (0xb8005248)
#define VBIOSD_OSD_V_COLOR15_VADDR                 (0xb800524c)
#define VBIOSD_OSD_V_FONT_ADDR_VADDR               (0xb8005250)
#define VBIOSD_OSD_V_FIFO_VADDR                    (0xb8005254)
#define VBIOSD_OSD_V_MEM_START_VADDR               (0xb8005258)
#define VBIOSD_OSD_V_BIST_STATUS_VADDR             (0xb800525c)




#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======VBIOSD register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  osd_vbi_v:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  osd_vbi_h:12;
    };
}osd_v_position_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  null_reg:12;
        RBus_UInt32  total_rows_mem:2;
        RBus_UInt32  total_b_one_row:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  osd_v_en_row:6;
        RBus_UInt32  res2:1;
        RBus_UInt32  auto_turn_off:1;
        RBus_UInt32  osd_v_start_row:6;
    };
}osd_v_row_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  osd_v_en_line_num:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  osd_v_en_line_start:12;
    };
}osd_v_line_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  osd_v_enable:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  up_row_more_line:2;
        RBus_UInt32  osd_v_h_zoom:2;
        RBus_UInt32  osd_v_v_zoom:2;
    };
}ovl_v_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  osd_v_color0_r:8;
        RBus_UInt32  osd_v_color0_g:8;
        RBus_UInt32  osd_v_color0_b:8;
    };
}osd_v_color0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  osd_v_color1_r:8;
        RBus_UInt32  osd_v_color1_g:8;
        RBus_UInt32  osd_v_color1_b:8;
    };
}osd_v_color1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  osd_v_color2_r:8;
        RBus_UInt32  osd_v_color2_g:8;
        RBus_UInt32  osd_v_color2_b:8;
    };
}osd_v_color2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  osd_v_color3_r:8;
        RBus_UInt32  osd_v_color3_g:8;
        RBus_UInt32  osd_v_color3_b:8;
    };
}osd_v_color3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  osd_v_color4_r:8;
        RBus_UInt32  osd_v_color4_g:8;
        RBus_UInt32  osd_v_color4_b:8;
    };
}osd_v_color4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  osd_v_color5_r:8;
        RBus_UInt32  osd_v_color5_g:8;
        RBus_UInt32  osd_v_color5_b:8;
    };
}osd_v_color5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  osd_v_color6_r:8;
        RBus_UInt32  osd_v_color6_g:8;
        RBus_UInt32  osd_v_color6_b:8;
    };
}osd_v_color6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  osd_v_color7_r:8;
        RBus_UInt32  osd_v_color7_g:8;
        RBus_UInt32  osd_v_color7_b:8;
    };
}osd_v_color7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  osd_v_color8_r:8;
        RBus_UInt32  osd_v_color8_g:8;
        RBus_UInt32  osd_v_color8_b:8;
    };
}osd_v_color8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  osd_v_color9_r:8;
        RBus_UInt32  osd_v_color9_g:8;
        RBus_UInt32  osd_v_color9_b:8;
    };
}osd_v_color9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  osd_v_color10_r:8;
        RBus_UInt32  osd_v_color10_g:8;
        RBus_UInt32  osd_v_color10_b:8;
    };
}osd_v_color10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  osd_v_color11_r:8;
        RBus_UInt32  osd_v_color11_g:8;
        RBus_UInt32  osd_v_color11_b:8;
    };
}osd_v_color11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  osd_v_color12_r:8;
        RBus_UInt32  osd_v_color12_g:8;
        RBus_UInt32  osd_v_color12_b:8;
    };
}osd_v_color12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  osd_v_color13_r:8;
        RBus_UInt32  osd_v_color13_g:8;
        RBus_UInt32  osd_v_color13_b:8;
    };
}osd_v_color13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  osd_v_color14_r:8;
        RBus_UInt32  osd_v_color14_g:8;
        RBus_UInt32  osd_v_color14_b:8;
    };
}osd_v_color14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  osd_v_color15_r:8;
        RBus_UInt32  osd_v_color15_g:8;
        RBus_UInt32  osd_v_color15_b:8;
    };
}osd_v_color15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  osd_v_font_addr:12;
    };
}osd_v_font_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  osd_v_mem_rem:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  osd_v_mem_r_len:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  osd_v_mem_r_num:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  osd_v_w:6;
    };
}osd_v_fifo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  osd_v_mem_st:23;
    };
}osd_v_mem_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  osd_v__bist_period:1;
        RBus_UInt32  osd_v_bist_ok:1;
        RBus_UInt32  osd_v_bist_en:1;
        RBus_UInt32  osd_v_clr_flags:1;
        RBus_UInt32  osd_v_fifo_full:1;
        RBus_UInt32  osd_v_fifo_empty:1;
        RBus_UInt32  osd_v_fifo_overflow:1;
        RBus_UInt32  osd_v_fifo_underflow:1;
    };
}osd_v_bist_status_RBUS;





#else //apply LITTLE_ENDIAN


//======VBIOSD register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_vbi_h:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  osd_vbi_v:12;
        RBus_UInt32  res1:4;
    };
}osd_v_position_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_v_start_row:6;
        RBus_UInt32  auto_turn_off:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  osd_v_en_row:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  total_b_one_row:2;
        RBus_UInt32  total_rows_mem:2;
        RBus_UInt32  null_reg:12;
    };
}osd_v_row_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_v_en_line_start:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  osd_v_en_line_num:12;
        RBus_UInt32  res1:4;
    };
}osd_v_line_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_v_v_zoom:2;
        RBus_UInt32  osd_v_h_zoom:2;
        RBus_UInt32  up_row_more_line:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  osd_v_enable:1;
        RBus_UInt32  res1:24;
    };
}ovl_v_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_v_color0_b:8;
        RBus_UInt32  osd_v_color0_g:8;
        RBus_UInt32  osd_v_color0_r:8;
        RBus_UInt32  res1:8;
    };
}osd_v_color0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_v_color1_b:8;
        RBus_UInt32  osd_v_color1_g:8;
        RBus_UInt32  osd_v_color1_r:8;
        RBus_UInt32  res1:8;
    };
}osd_v_color1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_v_color2_b:8;
        RBus_UInt32  osd_v_color2_g:8;
        RBus_UInt32  osd_v_color2_r:8;
        RBus_UInt32  res1:8;
    };
}osd_v_color2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_v_color3_b:8;
        RBus_UInt32  osd_v_color3_g:8;
        RBus_UInt32  osd_v_color3_r:8;
        RBus_UInt32  res1:8;
    };
}osd_v_color3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_v_color4_b:8;
        RBus_UInt32  osd_v_color4_g:8;
        RBus_UInt32  osd_v_color4_r:8;
        RBus_UInt32  res1:8;
    };
}osd_v_color4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_v_color5_b:8;
        RBus_UInt32  osd_v_color5_g:8;
        RBus_UInt32  osd_v_color5_r:8;
        RBus_UInt32  res1:8;
    };
}osd_v_color5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_v_color6_b:8;
        RBus_UInt32  osd_v_color6_g:8;
        RBus_UInt32  osd_v_color6_r:8;
        RBus_UInt32  res1:8;
    };
}osd_v_color6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_v_color7_b:8;
        RBus_UInt32  osd_v_color7_g:8;
        RBus_UInt32  osd_v_color7_r:8;
        RBus_UInt32  res1:8;
    };
}osd_v_color7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_v_color8_b:8;
        RBus_UInt32  osd_v_color8_g:8;
        RBus_UInt32  osd_v_color8_r:8;
        RBus_UInt32  res1:8;
    };
}osd_v_color8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_v_color9_b:8;
        RBus_UInt32  osd_v_color9_g:8;
        RBus_UInt32  osd_v_color9_r:8;
        RBus_UInt32  res1:8;
    };
}osd_v_color9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_v_color10_b:8;
        RBus_UInt32  osd_v_color10_g:8;
        RBus_UInt32  osd_v_color10_r:8;
        RBus_UInt32  res1:8;
    };
}osd_v_color10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_v_color11_b:8;
        RBus_UInt32  osd_v_color11_g:8;
        RBus_UInt32  osd_v_color11_r:8;
        RBus_UInt32  res1:8;
    };
}osd_v_color11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_v_color12_b:8;
        RBus_UInt32  osd_v_color12_g:8;
        RBus_UInt32  osd_v_color12_r:8;
        RBus_UInt32  res1:8;
    };
}osd_v_color12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_v_color13_b:8;
        RBus_UInt32  osd_v_color13_g:8;
        RBus_UInt32  osd_v_color13_r:8;
        RBus_UInt32  res1:8;
    };
}osd_v_color13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_v_color14_b:8;
        RBus_UInt32  osd_v_color14_g:8;
        RBus_UInt32  osd_v_color14_r:8;
        RBus_UInt32  res1:8;
    };
}osd_v_color14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_v_color15_b:8;
        RBus_UInt32  osd_v_color15_g:8;
        RBus_UInt32  osd_v_color15_r:8;
        RBus_UInt32  res1:8;
    };
}osd_v_color15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_v_font_addr:12;
        RBus_UInt32  res1:20;
    };
}osd_v_font_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_v_w:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  osd_v_mem_r_num:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  osd_v_mem_r_len:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  osd_v_mem_rem:6;
        RBus_UInt32  res1:2;
    };
}osd_v_fifo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_v_mem_st:23;
        RBus_UInt32  res1:9;
    };
}osd_v_mem_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_v_fifo_underflow:1;
        RBus_UInt32  osd_v_fifo_overflow:1;
        RBus_UInt32  osd_v_fifo_empty:1;
        RBus_UInt32  osd_v_fifo_full:1;
        RBus_UInt32  osd_v_clr_flags:1;
        RBus_UInt32  osd_v_bist_en:1;
        RBus_UInt32  osd_v_bist_ok:1;
        RBus_UInt32  osd_v__bist_period:1;
        RBus_UInt32  res1:24;
    };
}osd_v_bist_status_RBUS;


#endif







#endif //_RBUS_VBIOSD_REG_H_

