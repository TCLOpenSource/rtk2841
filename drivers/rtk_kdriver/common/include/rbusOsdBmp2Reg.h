/**
* @file rbusOsdBmp2Reg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2008/1/3
* @version 1.1
* @ingroup model_rbus
*
*/

#ifndef _RBUS_OSDBMP2_REG_H_
#define _RBUS_OSDBMP2_REG_H_

#include "rbusTypes.h"




// OSDBMP2 Register Address
#define OSDBMP2_OSD_B2_POSITION_ADDR               (0x18005600)
#define OSDBMP2_OSD_B2_CTRL_ADDR                   (0x18005604)
#define OSDBMP2_OSD_B2_PALETTE_DATA_ADDR           (0x18005608)
#define OSDBMP2_OSD_B2_FIFO_ADDR                   (0x1800560c)
#define OSDBMP2_OSD_B2_MEM_ADDR                    (0x18005610)
#define OSDBMP2_OSD_B2_BIST_STATUS_ADDR            (0x18005614)

#define OSDBMP2_OSD_B2_POSITION_VADDR              (0xb8005600)
#define OSDBMP2_OSD_B2_CTRL_VADDR                  (0xb8005604)
#define OSDBMP2_OSD_B2_PALETTE_DATA_VADDR          (0xb8005608)
#define OSDBMP2_OSD_B2_FIFO_VADDR                  (0xb800560c)
#define OSDBMP2_OSD_B2_MEM_VADDR                   (0xb8005610)
#define OSDBMP2_OSD_B2_BIST_STATUS_VADDR           (0xb8005614)




#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======OSDBMP2 register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  osd_b2_v:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  osd_b2_h:12;
    };
}osd_b2_position_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  osd_b2_frame_end:1;
        RBus_UInt32  osd_b2_palette_index:8;
        RBus_UInt32  osd_b2_enable:1;
        RBus_UInt32  osd_b2_palette_en:1;
        RBus_UInt32  osd_b2_f_b_ble:2;
        RBus_UInt32  osd_b2_lut_bist_period:1;
        RBus_UInt32  osd_b2_lut_bist_ok:1;
        RBus_UInt32  osd_b2_lut_bist_en:1;
        RBus_UInt32  osd_b2_suicide:1;
    };
}osd_b2_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  osd_b2_color_data:24;
    };
}osd_b2_palette_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  osd_b2_mem_remain:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  osd_b2_mem_length:6;
        RBus_UInt32  osd_b2_read_num:8;
        RBus_UInt32  res3:2;
        RBus_UInt32  osd_b2_mem_w:6;
    };
}osd_b2_fifo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  null_reg:5;
        RBus_UInt32  osd_b2_mem_start:24;
        RBus_UInt32  res1:3;
    };
}osd_b2_mem_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  osd_b2_bist_period:1;
        RBus_UInt32  osd_b2_bist_ok:1;
        RBus_UInt32  osd_b2_bist_en:1;
        RBus_UInt32  osd_b2_clr_flags:1;
        RBus_UInt32  osd_b2_fifo_full:1;
        RBus_UInt32  osd_b2_fifo_empty:1;
        RBus_UInt32  osd_b2_fifo_overflow:1;
        RBus_UInt32  osd_b2_fifo_underflow:1;
    };
}osd_b2_bist_status_RBUS;





#else //apply LITTLE_ENDIAN


//======OSDBMP2 register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_b2_h:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  osd_b2_v:12;
        RBus_UInt32  res1:4;
    };
}osd_b2_position_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_b2_suicide:1;
        RBus_UInt32  osd_b2_lut_bist_en:1;
        RBus_UInt32  osd_b2_lut_bist_ok:1;
        RBus_UInt32  osd_b2_lut_bist_period:1;
        RBus_UInt32  osd_b2_f_b_ble:2;
        RBus_UInt32  osd_b2_palette_en:1;
        RBus_UInt32  osd_b2_enable:1;
        RBus_UInt32  osd_b2_palette_index:8;
        RBus_UInt32  osd_b2_frame_end:1;
        RBus_UInt32  res1:15;
    };
}osd_b2_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_b2_color_data:24;
        RBus_UInt32  res1:8;
    };
}osd_b2_palette_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_b2_mem_w:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  osd_b2_read_num:8;
        RBus_UInt32  osd_b2_mem_length:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  osd_b2_mem_remain:6;
        RBus_UInt32  res1:2;
    };
}osd_b2_fifo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  osd_b2_mem_start:24;
        RBus_UInt32  null_reg:5;
    };
}osd_b2_mem_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_b2_fifo_underflow:1;
        RBus_UInt32  osd_b2_fifo_overflow:1;
        RBus_UInt32  osd_b2_fifo_empty:1;
        RBus_UInt32  osd_b2_fifo_full:1;
        RBus_UInt32  osd_b2_clr_flags:1;
        RBus_UInt32  osd_b2_bist_en:1;
        RBus_UInt32  osd_b2_bist_ok:1;
        RBus_UInt32  osd_b2_bist_period:1;
        RBus_UInt32  res1:24;
    };
}osd_b2_bist_status_RBUS;


#endif







#endif //_RBUS_OSDBMP2_REG_H_

