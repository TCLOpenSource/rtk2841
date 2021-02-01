/**
* @file rbusOsdBmpReg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2008/4/25
* @version 1.1
* @ingroup model_rbus
*
*/

#ifndef _RBUS_OSDBMP_REG_H_
#define _RBUS_OSDBMP_REG_H_

#include "rbusTypes.h"




// OSDBMP Register Address
#define OSDBMP_OSD_B_POSITION_ADDR                 (0x18048200)
#define OSDBMP_OSD_B_CTRL_ADDR                     (0x18048204)
#define OSDBMP_OSD_B_PALETTE_DATA_ADDR             (0x18048208)
#define OSDBMP_OSD_B_FIFO_ADDR                     (0x1804820c)
#define OSDBMP_OSD_B_MEM_ADDR                      (0x18048210)
#define OSDBMP_OSD_B_BIST_STATUS_ADDR              (0x18048214)

#define OSDBMP_OSD_B_POSITION_VADDR                (0xb8048200)
#define OSDBMP_OSD_B_CTRL_VADDR                    (0xb8048204)
#define OSDBMP_OSD_B_PALETTE_DATA_VADDR            (0xb8048208)
#define OSDBMP_OSD_B_FIFO_VADDR                    (0xb804820c)
#define OSDBMP_OSD_B_MEM_VADDR                     (0xb8048210)
#define OSDBMP_OSD_B_BIST_STATUS_VADDR             (0xb8048214)




#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======OSDBMP register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  osd_b_v:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  osd_b_h:12;
    };
}osd_b_position_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  frame_blinking_en:1;
        RBus_UInt32  osd_b_frame_end:1;
        RBus_UInt32  osd_b_palette_index:8;
        RBus_UInt32  osd_b_enable:1;
        RBus_UInt32  osd_b_palette_en:1;
        RBus_UInt32  osd_b_f_b_ble:2;
        RBus_UInt32  osd_b_lut_bist_period:1;
        RBus_UInt32  osd_b_lut_bist_ok:1;
        RBus_UInt32  osd_b_lut_bist_en:1;
        RBus_UInt32  osd_b_suicide:1;
    };
}osd_b_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  osd_b_color_data:24;
    };
}osd_b_palette_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  osd_b_mem_remain:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  osd_b_mem_length:7;
        RBus_UInt32  osd_b_read_num:8;
        RBus_UInt32  res3:1;
        RBus_UInt32  osd_b_mem_w:7;
    };
}osd_b_fifo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  null_reg:5;
        RBus_UInt32  osd_b_mem_start:24;
        RBus_UInt32  res1:3;
    };
}osd_b_mem_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  osd_b_bist_period:1;
        RBus_UInt32  osd_b_bist_ok:1;
        RBus_UInt32  osd_b_bist_en:1;
        RBus_UInt32  osd_b_clr_flags:1;
        RBus_UInt32  osd_b_fifo_full:1;
        RBus_UInt32  osd_b_fifo_empty:1;
        RBus_UInt32  osd_b_fifo_overflow:1;
        RBus_UInt32  osd_b_fifo_underflow:1;
    };
}osd_b_bist_status_RBUS;





#else //apply LITTLE_ENDIAN


//======OSDBMP register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_b_h:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  osd_b_v:12;
        RBus_UInt32  res1:4;
    };
}osd_b_position_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_b_suicide:1;
        RBus_UInt32  osd_b_lut_bist_en:1;
        RBus_UInt32  osd_b_lut_bist_ok:1;
        RBus_UInt32  osd_b_lut_bist_period:1;
        RBus_UInt32  osd_b_f_b_ble:2;
        RBus_UInt32  osd_b_palette_en:1;
        RBus_UInt32  osd_b_enable:1;
        RBus_UInt32  osd_b_palette_index:8;
        RBus_UInt32  osd_b_frame_end:1;
        RBus_UInt32  frame_blinking_en:1;
        RBus_UInt32  res1:14;
    };
}osd_b_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_b_color_data:24;
        RBus_UInt32  res1:8;
    };
}osd_b_palette_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_b_mem_w:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  osd_b_read_num:8;
        RBus_UInt32  osd_b_mem_length:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  osd_b_mem_remain:7;
        RBus_UInt32  res1:1;
    };
}osd_b_fifo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  osd_b_mem_start:24;
        RBus_UInt32  null_reg:5;
    };
}osd_b_mem_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_b_fifo_underflow:1;
        RBus_UInt32  osd_b_fifo_overflow:1;
        RBus_UInt32  osd_b_fifo_empty:1;
        RBus_UInt32  osd_b_fifo_full:1;
        RBus_UInt32  osd_b_clr_flags:1;
        RBus_UInt32  osd_b_bist_en:1;
        RBus_UInt32  osd_b_bist_ok:1;
        RBus_UInt32  osd_b_bist_period:1;
        RBus_UInt32  res1:24;
    };
}osd_b_bist_status_RBUS;


#endif







#endif //_RBUS_OSDBMP_REG_H_

