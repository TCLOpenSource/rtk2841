/**
* @file rbusPif_rgb2yuvReg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2010/9/16
* @version 1.1
* @ingroup model_rbus
*
*/

#ifndef _RBUS_PIF_RGB2YUV_REG_H_
#define _RBUS_PIF_RGB2YUV_REG_H_

#include "rbusTypes.h"




// PIF_RGB2YUV Register Address
#define PIF_RGB2YUV_PIF_RGB2YUV_CTRL_ADDR          (0x1802d250)
#define PIF_RGB2YUV_PIF_TAB1_M1_ADDR               (0x1802d254)
#define PIF_RGB2YUV_PIF_TAB1_M2_ADDR               (0x1802d258)
#define PIF_RGB2YUV_PIF_TAB1_M3_ADDR               (0x1802d25c)
#define PIF_RGB2YUV_PIF_TAB1_YO_AND_Y_GAIN_ADDR    (0x1802d260)
#define PIF_RGB2YUV_PIF_444TO422_CTRL_ADDR         (0x1802d264)

#define PIF_RGB2YUV_PIF_RGB2YUV_CTRL_VADDR         (0xb802d250)
#define PIF_RGB2YUV_PIF_TAB1_M1_VADDR              (0xb802d254)
#define PIF_RGB2YUV_PIF_TAB1_M2_VADDR              (0xb802d258)
#define PIF_RGB2YUV_PIF_TAB1_M3_VADDR              (0xb802d25c)
#define PIF_RGB2YUV_PIF_TAB1_YO_AND_Y_GAIN_VADDR   (0xb802d260)
#define PIF_RGB2YUV_PIF_444TO422_CTRL_VADDR        (0xb802d264)




#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======PIF_RGB2YUV register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  sel_2x_gain:1;
        RBus_UInt32  sel_y_gain:1;
        RBus_UInt32  matrix_bypass:1;
        RBus_UInt32  sel_uv_off:1;
        RBus_UInt32  set_uv_out_offset:1;
        RBus_UInt32  set_r_in_offset:1;
        RBus_UInt32  sel_rgb:1;
        RBus_UInt32  sel_sign:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  pif_en_rgb2yuv:2;
    };
}pif_RGB2YUV_CTRL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m13:11;
        RBus_UInt32  m12:10;
        RBus_UInt32  m11:11;
    };
}pif_tab1_M1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  m23:9;
        RBus_UInt32  m22:10;
        RBus_UInt32  m21:10;
    };
}pif_tab1_M2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  m33:10;
        RBus_UInt32  m32:11;
        RBus_UInt32  m31:10;
    };
}pif_tab1_M3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  y_gain:9;
        RBus_UInt32  res2:11;
        RBus_UInt32  yo:11;
    };
}pif_tab1_Yo_and_Y_Gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  pif_cr_dly_cb:1;
        RBus_UInt32  pif_drop:1;
        RBus_UInt32  pif_444to422_en:1;
    };
}pif_444to422_CTRL_RBUS;





#else //apply LITTLE_ENDIAN


//======PIF_RGB2YUV register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_en_rgb2yuv:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  sel_sign:1;
        RBus_UInt32  sel_rgb:1;
        RBus_UInt32  set_r_in_offset:1;
        RBus_UInt32  set_uv_out_offset:1;
        RBus_UInt32  sel_uv_off:1;
        RBus_UInt32  matrix_bypass:1;
        RBus_UInt32  sel_y_gain:1;
        RBus_UInt32  sel_2x_gain:1;
        RBus_UInt32  res1:21;
    };
}pif_RGB2YUV_CTRL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m11:11;
        RBus_UInt32  m12:10;
        RBus_UInt32  m13:11;
    };
}pif_tab1_M1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m21:10;
        RBus_UInt32  m22:10;
        RBus_UInt32  m23:9;
        RBus_UInt32  res1:3;
    };
}pif_tab1_M2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m31:10;
        RBus_UInt32  m32:11;
        RBus_UInt32  m33:10;
        RBus_UInt32  res1:1;
    };
}pif_tab1_M3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  yo:11;
        RBus_UInt32  res2:11;
        RBus_UInt32  y_gain:9;
        RBus_UInt32  res1:1;
    };
}pif_tab1_Yo_and_Y_Gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pif_444to422_en:1;
        RBus_UInt32  pif_drop:1;
        RBus_UInt32  pif_cr_dly_cb:1;
        RBus_UInt32  res1:29;
    };
}pif_444to422_CTRL_RBUS;


#endif







#endif //_RBUS_PIF_RGB2YUV_REG_H_

