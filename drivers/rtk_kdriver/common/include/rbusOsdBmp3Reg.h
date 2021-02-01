/**
* @file rbusOsdBmp3Reg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2008/1/3
* @version 1.1
* @ingroup model_rbus
*
*/

#ifndef _RBUS_OSDBMP3_REG_H_
#define _RBUS_OSDBMP3_REG_H_

#include "rbus/rbusTypes.h"




// OSDBMP3 Register Address
#define OSDBMP3_OSD_B3_POSITION_ADDR               (0x18005700)
#define OSDBMP3_OSD_B3_CTRL_ADDR                   (0x18005704)
#define OSDBMP3_OSD_B3_PALETTE_DATA_ADDR           (0x18005708)
#define OSDBMP3_OSD_B3_FIFO_ADDR                   (0x1800570c)
#define OSDBMP3_OSD_B3_MEM_ADDR                    (0x18005710)
#define OSDBMP3_OSD_B3_BIST_STATUS_ADDR            (0x18005714)

#define OSDBMP3_OSD_B3_POSITION_VADDR              (0xb8005700)
#define OSDBMP3_OSD_B3_CTRL_VADDR                  (0xb8005704)
#define OSDBMP3_OSD_B3_PALETTE_DATA_VADDR          (0xb8005708)
#define OSDBMP3_OSD_B3_FIFO_VADDR                  (0xb800570c)
#define OSDBMP3_OSD_B3_MEM_VADDR                   (0xb8005710)
#define OSDBMP3_OSD_B3_BIST_STATUS_VADDR           (0xb8005714)




#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======OSDBMP3 register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  osd_b3_v:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  osd_b3_h:12;
    };
}osd_b3_position_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  osd_b3_frame_end:1;
        RBus_UInt32  osd_b3_palette_index:8;
        RBus_UInt32  osd_b3_enable:1;
        RBus_UInt32  osd_b3_palette_en:1;
        RBus_UInt32  osd_b3_f_b_ble:2;
        RBus_UInt32  osd_b3_lut_bist_period:1;
        RBus_UInt32  osd_b3_lut_bist_ok:1;
        RBus_UInt32  osd_b3_lut_bist_en:1;
        RBus_UInt32  osd_b3_suicide:1;
    };
}osd_b3_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  osd_b3_color_data:24;
    };
}osd_b3_palette_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  osd_b3_mem_remain:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  osd_b3_mem_length:6;
        RBus_UInt32  osd_b3_read_num:8;
        RBus_UInt32  res3:2;
        RBus_UInt32  osd_b3_mem_w:6;
    };
}osd_b3_fifo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  null_reg:5;
        RBus_UInt32  osd_b3_mem_start:24;
        RBus_UInt32  res1:3;
    };
}osd_b3_mem_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  osd_b3_bist_period:1;
        RBus_UInt32  osd_b3_bist_ok:1;
        RBus_UInt32  osd_b3_bist_en:1;
        RBus_UInt32  osd_b3_clr_flags:1;
        RBus_UInt32  osd_b3_fifo_full:1;
        RBus_UInt32  osd_b3_fifo_empty:1;
        RBus_UInt32  osd_b3_fifo_overflow:1;
        RBus_UInt32  osd_b3_fifo_underflow:1;
    };
}osd_b3_bist_status_RBUS;





#else //apply LITTLE_ENDIAN


//======OSDBMP3 register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_b3_h:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  osd_b3_v:12;
        RBus_UInt32  res1:4;
    };
}osd_b3_position_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_b3_suicide:1;
        RBus_UInt32  osd_b3_lut_bist_en:1;
        RBus_UInt32  osd_b3_lut_bist_ok:1;
        RBus_UInt32  osd_b3_lut_bist_period:1;
        RBus_UInt32  osd_b3_f_b_ble:2;
        RBus_UInt32  osd_b3_palette_en:1;
        RBus_UInt32  osd_b3_enable:1;
        RBus_UInt32  osd_b3_palette_index:8;
        RBus_UInt32  osd_b3_frame_end:1;
        RBus_UInt32  res1:15;
    };
}osd_b3_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_b3_color_data:24;
        RBus_UInt32  res1:8;
    };
}osd_b3_palette_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_b3_mem_w:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  osd_b3_read_num:8;
        RBus_UInt32  osd_b3_mem_length:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  osd_b3_mem_remain:6;
        RBus_UInt32  res1:2;
    };
}osd_b3_fifo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  osd_b3_mem_start:24;
        RBus_UInt32  null_reg:5;
    };
}osd_b3_mem_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_b3_fifo_underflow:1;
        RBus_UInt32  osd_b3_fifo_overflow:1;
        RBus_UInt32  osd_b3_fifo_empty:1;
        RBus_UInt32  osd_b3_fifo_full:1;
        RBus_UInt32  osd_b3_clr_flags:1;
        RBus_UInt32  osd_b3_bist_en:1;
        RBus_UInt32  osd_b3_bist_ok:1;
        RBus_UInt32  osd_b3_bist_period:1;
        RBus_UInt32  res1:24;
    };
}osd_b3_bist_status_RBUS;


#endif







#endif //_RBUS_OSDBMP3_REG_H_

