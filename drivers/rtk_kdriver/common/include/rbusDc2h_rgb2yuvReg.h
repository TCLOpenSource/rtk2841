/**
* @file rbusDc2h_rgb2yuvReg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2014-5-8
* @version 802
* @ingroup model_rbus
*
*/

#ifndef _RBUS_DC2H_RGB2YUV_REG_H_
#define _RBUS_DC2H_RGB2YUV_REG_H_

#include "rbus/rbusTypes.h"




// DC2H_RGB2YUV Register Address

#define DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_VADDR       (0xb8029c00)
#define DC2H_RGB2YUV_DC2H_TAB1_M11_M12_VADDR       (0xb8029c04)
#define DC2H_RGB2YUV_DC2H_TAB1_M13_M21_VADDR       (0xb8029c08)
#define DC2H_RGB2YUV_DC2H_TAB1_M22_M23_VADDR       (0xb8029c0c)
#define DC2H_RGB2YUV_DC2H_TAB1_M31_M32_VADDR       (0xb8029c10)
#define DC2H_RGB2YUV_DC2H_TAB1_M33_Y_GAIN_VADDR    (0xb8029c14)
#define DC2H_RGB2YUV_DC2H_TAB1_YO_VADDR            (0xb8029c18)
#define DC2H_RGB2YUV_DC2H_3DMASKTO2D_CTRL_VADDR    (0xb8029c80)




#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======DC2H_RGB2YUV register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  dc2h_in_sel:3;
        RBus_UInt32  err_dif_bits:3;
        RBus_UInt32  err_dif_enable:1;
        RBus_UInt32  rgb_in_offset:1;
        RBus_UInt32  sel_2x_gain:1;
        RBus_UInt32  sel_y_gain:1;
        RBus_UInt32  matrix_bypass:1;
        RBus_UInt32  sel_uv_off:1;
        RBus_UInt32  set_uv_out_offset:1;
        RBus_UInt32  set_r_in_offset:1;
        RBus_UInt32  sel_rgb:1;
        RBus_UInt32  sel_sign:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  en_rgb2yuv:2;
    };
}dc2h_rgb2yuv_CTRL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  m12:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  m11:15;
    };
}dc2h_tab1_M11_M12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  m21:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  m13:15;
    };
}dc2h_tab1_M13_M21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  m23:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  m22:15;
    };
}dc2h_tab1_M22_M23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  m32:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  m31:15;
    };
}dc2h_tab1_M31_M32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  yo_gain:9;
        RBus_UInt32  res2:1;
        RBus_UInt32  m33:15;
    };
}dc2h_tab1_M33_Y_Gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  yo_odd:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  yo_even:13;
    };
}dc2h_tab1_Yo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  dc2h_3dmaskto2d_3dformat:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  dc2h_3dmaskto2d_mode:1;
        RBus_UInt32  dc2h_3dmaskto2d_en:1;
    };
}dc2h_3dmaskto2d_ctrl_RBUS;





#else //apply LITTLE_ENDIAN


//======DC2H_RGB2YUV register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  en_rgb2yuv:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  sel_sign:1;
        RBus_UInt32  sel_rgb:1;
        RBus_UInt32  set_r_in_offset:1;
        RBus_UInt32  set_uv_out_offset:1;
        RBus_UInt32  sel_uv_off:1;
        RBus_UInt32  matrix_bypass:1;
        RBus_UInt32  sel_y_gain:1;
        RBus_UInt32  sel_2x_gain:1;
        RBus_UInt32  rgb_in_offset:1;
        RBus_UInt32  err_dif_enable:1;
        RBus_UInt32  err_dif_bits:3;
        RBus_UInt32  dc2h_in_sel:3;
        RBus_UInt32  res1:13;
    };
}dc2h_rgb2yuv_CTRL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m11:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  m12:15;
        RBus_UInt32  res1:1;
    };
}dc2h_tab1_M11_M12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m13:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  m21:15;
        RBus_UInt32  res1:1;
    };
}dc2h_tab1_M13_M21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m22:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  m23:15;
        RBus_UInt32  res1:1;
    };
}dc2h_tab1_M22_M23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m31:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  m32:15;
        RBus_UInt32  res1:1;
    };
}dc2h_tab1_M31_M32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m33:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  yo_gain:9;
        RBus_UInt32  res1:7;
    };
}dc2h_tab1_M33_Y_Gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  yo_even:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  yo_odd:13;
        RBus_UInt32  res1:3;
    };
}dc2h_tab1_Yo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc2h_3dmaskto2d_en:1;
        RBus_UInt32  dc2h_3dmaskto2d_mode:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  dc2h_3dmaskto2d_3dformat:2;
        RBus_UInt32  res1:26;
    };
}dc2h_3dmaskto2d_ctrl_RBUS;


#endif







#endif //_RBUS_DC2H_RGB2YUV_REG_H_

