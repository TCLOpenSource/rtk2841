/**
* @file rbusOsdCurReg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2008/1/8
* @version 1.1
* @ingroup model_rbus
*
*/

#ifndef _RBUS_OSDCUR_REG_H_
#define _RBUS_OSDCUR_REG_H_

#include "rbus/rbusTypes.h"




// OSDCUR Register Address
#define OSDCUR_OSD_C_POSITION_ADDR                 (0x18005300)
#define OSDCUR_OSD_C_CTRL_ADDR                     (0x18005304)
#define OSDCUR_OSD_C_FRAME_COUNT_ADDR              (0x18005308)
#define OSDCUR_OSD_C_ACCESS_DATA1_ADDR             (0x1800530c)
#define OSDCUR_OSD_C_ACCESS_DATA2_ADDR             (0x18005310)
#define OSDCUR_OSD_C_COLOR0_ADDR                   (0x18005314)
#define OSDCUR_OSD_C_COLOR1_ADDR                   (0x18005318)
#define OSDCUR_OSD_C_COLOR2_ADDR                   (0x1800531c)
#define OSDCUR_OSD_C_COLOR3_ADDR                   (0x18005320)
#define OSDCUR_OSD_C_PIXEL_CTRL_ADDR               (0x18005324)
#define OSDCUR_OSD_C_PIXEL_ADDRESS_ADDR            (0x18005328)
#define OSDCUR_OSD_C_PIXEL_DATA_ADDR               (0x1800532c)

#define OSDCUR_OSD_C_POSITION_VADDR                (0xb8005300)
#define OSDCUR_OSD_C_CTRL_VADDR                    (0xb8005304)
#define OSDCUR_OSD_C_FRAME_COUNT_VADDR             (0xb8005308)
#define OSDCUR_OSD_C_ACCESS_DATA1_VADDR            (0xb800530c)
#define OSDCUR_OSD_C_ACCESS_DATA2_VADDR            (0xb8005310)
#define OSDCUR_OSD_C_COLOR0_VADDR                  (0xb8005314)
#define OSDCUR_OSD_C_COLOR1_VADDR                  (0xb8005318)
#define OSDCUR_OSD_C_COLOR2_VADDR                  (0xb800531c)
#define OSDCUR_OSD_C_COLOR3_VADDR                  (0xb8005320)
#define OSDCUR_OSD_C_PIXEL_CTRL_VADDR              (0xb8005324)
#define OSDCUR_OSD_C_PIXEL_ADDRESS_VADDR           (0xb8005328)
#define OSDCUR_OSD_C_PIXEL_DATA_VADDR              (0xb800532c)




#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======OSDCUR register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  osd_c_v:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  osd_c_h:12;
    };
}osd_c_position_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  sequency_in_read_out:4;
        RBus_UInt32  osd_c_buffer:1;
        RBus_UInt32  osd_c_hflip:1;
        RBus_UInt32  osd_c_vflip:1;
        RBus_UInt32  osd_c_rotate_r:1;
        RBus_UInt32  osd_c_h_zoom:2;
        RBus_UInt32  osd_c_v_zoom:2;
    };
}osd_c_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  osd_c_counter_period_r:8;
        RBus_UInt32  osd_c_counter_period:8;
        RBus_UInt32  osd_c_counter_return:1;
        RBus_UInt32  null_reg:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  osd_c_counter_en:1;
        RBus_UInt32  osd_c_buffer_auto_switch:1;
        RBus_UInt32  osd_c_en:1;
    };
}osd_c_frame_count_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_c_buff_sel_7:1;
        RBus_UInt32  osd_c_hflip_7:1;
        RBus_UInt32  osd_c_vflip_7:1;
        RBus_UInt32  osd_c_rotate_r_7:1;
        RBus_UInt32  osd_c_buff_sel_6:1;
        RBus_UInt32  osd_c_hflip_6:1;
        RBus_UInt32  osd_c_vflip_6:1;
        RBus_UInt32  osd_c_rotate_r_6:1;
        RBus_UInt32  osd_c_buff_sel_5:1;
        RBus_UInt32  osd_c_hflip_5:1;
        RBus_UInt32  osd_c_vflip_5:1;
        RBus_UInt32  osd_c_rotate_r_5:1;
        RBus_UInt32  osd_c_buff_sel_4:1;
        RBus_UInt32  osd_c_hflip_4:1;
        RBus_UInt32  osd_c_vflip_4:1;
        RBus_UInt32  osd_c_rotate_r_4:1;
        RBus_UInt32  osd_c_buff_sel_3:1;
        RBus_UInt32  osd_c_hflip_3:1;
        RBus_UInt32  osd_c_vflip_3:1;
        RBus_UInt32  osd_c_rotate_r_3:1;
        RBus_UInt32  osd_c_buff_sel_2:1;
        RBus_UInt32  osd_c_hflip_2:1;
        RBus_UInt32  osd_c_vflip_2:1;
        RBus_UInt32  osd_c_rotate_r_2:1;
        RBus_UInt32  osd_c_buff_sel_1:1;
        RBus_UInt32  osd_c_hflip_1:1;
        RBus_UInt32  osd_c_vflip_1:1;
        RBus_UInt32  osd_c_rotate_r_1:1;
        RBus_UInt32  osd_c_buff_sel_0:1;
        RBus_UInt32  osd_c_hflip_0:1;
        RBus_UInt32  osd_c_vflip_0:1;
        RBus_UInt32  osd_c_rotate_r_0:1;
    };
}osd_c_access_data1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_c_buff_sel_15:1;
        RBus_UInt32  osd_c_hflip_15:1;
        RBus_UInt32  osd_c_vflip_15:1;
        RBus_UInt32  osd_c_rotate_r_15:1;
        RBus_UInt32  osd_c_buff_sel_14:1;
        RBus_UInt32  osd_c_hflip_14:1;
        RBus_UInt32  osd_c_vflip_14:1;
        RBus_UInt32  osd_c_rotate_r_14:1;
        RBus_UInt32  osd_c_buff_sel_13:1;
        RBus_UInt32  osd_c_hflip_13:1;
        RBus_UInt32  osd_c_vflip_13:1;
        RBus_UInt32  osd_c_rotate_r_13:1;
        RBus_UInt32  osd_c_buff_sel_12:1;
        RBus_UInt32  osd_c_hflip_12:1;
        RBus_UInt32  osd_c_vflip_12:1;
        RBus_UInt32  osd_c_rotate_r_12:1;
        RBus_UInt32  osd_c_buff_sel_11:1;
        RBus_UInt32  osd_c_hflip_11:1;
        RBus_UInt32  osd_c_vflip_11:1;
        RBus_UInt32  osd_c_rotate_r_11:1;
        RBus_UInt32  osd_c_buff_sel_10:1;
        RBus_UInt32  osd_c_hflip_10:1;
        RBus_UInt32  osd_c_vflip_10:1;
        RBus_UInt32  osd_c_rotate_r_10:1;
        RBus_UInt32  osd_c_buff_sel_9:1;
        RBus_UInt32  osd_c_hflip_9:1;
        RBus_UInt32  osd_c_vflip_9:1;
        RBus_UInt32  osd_c_rotate_r_9:1;
        RBus_UInt32  osd_c_buff_sel_8:1;
        RBus_UInt32  osd_c_hflip_8:1;
        RBus_UInt32  osd_c_vflip_8:1;
        RBus_UInt32  osd_c_rotate_r_8:1;
    };
}osd_c_access_data2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  osd_c_color0_r:8;
        RBus_UInt32  osd_c_color0_g:8;
        RBus_UInt32  osd_c_color0_b:8;
    };
}osd_c_color0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  osd_c_color1_r:8;
        RBus_UInt32  osd_c_color1_g:8;
        RBus_UInt32  osd_c_color1_b:8;
    };
}osd_c_color1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  osd_c_color2_r:8;
        RBus_UInt32  osd_c_color2_g:8;
        RBus_UInt32  osd_c_color2_b:8;
    };
}osd_c_color2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  osd_c_color3_r:8;
        RBus_UInt32  osd_c_color3_g:8;
        RBus_UInt32  osd_c_color3_b:8;
    };
}osd_c_color3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  osd_c_transparent_color:1;
        RBus_UInt32  osd_c_pixel_acc_en:1;
        RBus_UInt32  osd_c_pixel_buff_sel:1;
        RBus_UInt32  os_c_blink_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  osd_c_bist_period:1;
        RBus_UInt32  osd_c_bist_ok:1;
        RBus_UInt32  osd_c_bist_en:1;
        RBus_UInt32  osd_c_end:1;
    };
}osd_c_pixel_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  osd_c_pixel_addr:8;
    };
}osd_c_pixel_address_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_c_pixel_data:32;
    };
}osd_c_pixel_data_RBUS;





#else //apply LITTLE_ENDIAN


//======OSDCUR register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_c_h:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  osd_c_v:12;
        RBus_UInt32  res1:4;
    };
}osd_c_position_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_c_v_zoom:2;
        RBus_UInt32  osd_c_h_zoom:2;
        RBus_UInt32  osd_c_rotate_r:1;
        RBus_UInt32  osd_c_vflip:1;
        RBus_UInt32  osd_c_hflip:1;
        RBus_UInt32  osd_c_buffer:1;
        RBus_UInt32  sequency_in_read_out:4;
        RBus_UInt32  res1:20;
    };
}osd_c_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_c_en:1;
        RBus_UInt32  osd_c_buffer_auto_switch:1;
        RBus_UInt32  osd_c_counter_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  null_reg:3;
        RBus_UInt32  osd_c_counter_return:1;
        RBus_UInt32  osd_c_counter_period:8;
        RBus_UInt32  osd_c_counter_period_r:8;
        RBus_UInt32  res1:8;
    };
}osd_c_frame_count_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_c_rotate_r_0:1;
        RBus_UInt32  osd_c_vflip_0:1;
        RBus_UInt32  osd_c_hflip_0:1;
        RBus_UInt32  osd_c_buff_sel_0:1;
        RBus_UInt32  osd_c_rotate_r_1:1;
        RBus_UInt32  osd_c_vflip_1:1;
        RBus_UInt32  osd_c_hflip_1:1;
        RBus_UInt32  osd_c_buff_sel_1:1;
        RBus_UInt32  osd_c_rotate_r_2:1;
        RBus_UInt32  osd_c_vflip_2:1;
        RBus_UInt32  osd_c_hflip_2:1;
        RBus_UInt32  osd_c_buff_sel_2:1;
        RBus_UInt32  osd_c_rotate_r_3:1;
        RBus_UInt32  osd_c_vflip_3:1;
        RBus_UInt32  osd_c_hflip_3:1;
        RBus_UInt32  osd_c_buff_sel_3:1;
        RBus_UInt32  osd_c_rotate_r_4:1;
        RBus_UInt32  osd_c_vflip_4:1;
        RBus_UInt32  osd_c_hflip_4:1;
        RBus_UInt32  osd_c_buff_sel_4:1;
        RBus_UInt32  osd_c_rotate_r_5:1;
        RBus_UInt32  osd_c_vflip_5:1;
        RBus_UInt32  osd_c_hflip_5:1;
        RBus_UInt32  osd_c_buff_sel_5:1;
        RBus_UInt32  osd_c_rotate_r_6:1;
        RBus_UInt32  osd_c_vflip_6:1;
        RBus_UInt32  osd_c_hflip_6:1;
        RBus_UInt32  osd_c_buff_sel_6:1;
        RBus_UInt32  osd_c_rotate_r_7:1;
        RBus_UInt32  osd_c_vflip_7:1;
        RBus_UInt32  osd_c_hflip_7:1;
        RBus_UInt32  osd_c_buff_sel_7:1;
    };
}osd_c_access_data1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_c_rotate_r_8:1;
        RBus_UInt32  osd_c_vflip_8:1;
        RBus_UInt32  osd_c_hflip_8:1;
        RBus_UInt32  osd_c_buff_sel_8:1;
        RBus_UInt32  osd_c_rotate_r_9:1;
        RBus_UInt32  osd_c_vflip_9:1;
        RBus_UInt32  osd_c_hflip_9:1;
        RBus_UInt32  osd_c_buff_sel_9:1;
        RBus_UInt32  osd_c_rotate_r_10:1;
        RBus_UInt32  osd_c_vflip_10:1;
        RBus_UInt32  osd_c_hflip_10:1;
        RBus_UInt32  osd_c_buff_sel_10:1;
        RBus_UInt32  osd_c_rotate_r_11:1;
        RBus_UInt32  osd_c_vflip_11:1;
        RBus_UInt32  osd_c_hflip_11:1;
        RBus_UInt32  osd_c_buff_sel_11:1;
        RBus_UInt32  osd_c_rotate_r_12:1;
        RBus_UInt32  osd_c_vflip_12:1;
        RBus_UInt32  osd_c_hflip_12:1;
        RBus_UInt32  osd_c_buff_sel_12:1;
        RBus_UInt32  osd_c_rotate_r_13:1;
        RBus_UInt32  osd_c_vflip_13:1;
        RBus_UInt32  osd_c_hflip_13:1;
        RBus_UInt32  osd_c_buff_sel_13:1;
        RBus_UInt32  osd_c_rotate_r_14:1;
        RBus_UInt32  osd_c_vflip_14:1;
        RBus_UInt32  osd_c_hflip_14:1;
        RBus_UInt32  osd_c_buff_sel_14:1;
        RBus_UInt32  osd_c_rotate_r_15:1;
        RBus_UInt32  osd_c_vflip_15:1;
        RBus_UInt32  osd_c_hflip_15:1;
        RBus_UInt32  osd_c_buff_sel_15:1;
    };
}osd_c_access_data2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_c_color0_b:8;
        RBus_UInt32  osd_c_color0_g:8;
        RBus_UInt32  osd_c_color0_r:8;
        RBus_UInt32  res1:8;
    };
}osd_c_color0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_c_color1_b:8;
        RBus_UInt32  osd_c_color1_g:8;
        RBus_UInt32  osd_c_color1_r:8;
        RBus_UInt32  res1:8;
    };
}osd_c_color1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_c_color2_b:8;
        RBus_UInt32  osd_c_color2_g:8;
        RBus_UInt32  osd_c_color2_r:8;
        RBus_UInt32  res1:8;
    };
}osd_c_color2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_c_color3_b:8;
        RBus_UInt32  osd_c_color3_g:8;
        RBus_UInt32  osd_c_color3_r:8;
        RBus_UInt32  res1:8;
    };
}osd_c_color3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_c_end:1;
        RBus_UInt32  osd_c_bist_en:1;
        RBus_UInt32  osd_c_bist_ok:1;
        RBus_UInt32  osd_c_bist_period:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  os_c_blink_en:1;
        RBus_UInt32  osd_c_pixel_buff_sel:1;
        RBus_UInt32  osd_c_pixel_acc_en:1;
        RBus_UInt32  osd_c_transparent_color:1;
        RBus_UInt32  res1:23;
    };
}osd_c_pixel_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_c_pixel_addr:8;
        RBus_UInt32  res1:24;
    };
}osd_c_pixel_address_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_c_pixel_data:32;
    };
}osd_c_pixel_data_RBUS;


#endif







#endif //_RBUS_OSDCUR_REG_H_

