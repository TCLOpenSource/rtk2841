/**
* @file rbusRgb2yuvReg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2012-12-3
* @version 1.1
* @ingroup model_rbus
*
*/

#ifndef _RBUS_RGB2YUV_REG_H_
#define _RBUS_RGB2YUV_REG_H_

#include "rbus/rbusTypes.h"




// RGB2YUV Register Address
#define RGB2YUV_ICH1_RGB2YUV_CTRL_ADDR             (0x18023000)
#define RGB2YUV_TAB1_M1_ADDR                       (0x18023008)
#define RGB2YUV_TAB1_M2_ADDR                       (0x1802300c)
#define RGB2YUV_TAB1_M3_ADDR                       (0x18023010)
#define RGB2YUV_TAB1_YO_AND_Y_GAIN_ADDR            (0x18023014)
#define RGB2YUV_TAB2_M1_ADDR                       (0x18023018)
#define RGB2YUV_TAB2_M2_ADDR                       (0x1802301c)
#define RGB2YUV_TAB2_M3_ADDR                       (0x18023020)
#define RGB2YUV_TAB2_YO_AND_Y_GAIN_ADDR            (0x18023024)
#define RGB2YUV_ICH1_422TO444_CTRL_ADDR            (0x18023028)
#define RGB2YUV_C_CORING_DATA_1_I_ADDR             (0x18023030)
#define RGB2YUV_C_CORING_DATA_2_I_ADDR             (0x18023034)

#define RGB2YUV_ICH1_RGB2YUV_CTRL_VADDR            (0xb8023000)
#define RGB2YUV_TAB1_M1_VADDR                      (0xb8023008)
#define RGB2YUV_TAB1_M2_VADDR                      (0xb802300c)
#define RGB2YUV_TAB1_M3_VADDR                      (0xb8023010)
#define RGB2YUV_TAB1_YO_AND_Y_GAIN_VADDR           (0xb8023014)
#define RGB2YUV_TAB2_M1_VADDR                      (0xb8023018)
#define RGB2YUV_TAB2_M2_VADDR                      (0xb802301c)
#define RGB2YUV_TAB2_M3_VADDR                      (0xb8023020)
#define RGB2YUV_TAB2_YO_AND_Y_GAIN_VADDR           (0xb8023024)
#define RGB2YUV_ICH1_422TO444_CTRL_VADDR           (0xb8023028)
#define RGB2YUV_C_CORING_DATA_1_I_VADDR            (0xb8023030)
#define RGB2YUV_C_CORING_DATA_2_I_VADDR            (0xb8023034)




#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======RGB2YUV register structure define==========
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
        RBus_UInt32  sel_table:1;
        RBus_UInt32  en_rgb2yuv:2;
    };
}ich1_RGB2YUV_CTRL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m13:11;
        RBus_UInt32  m12:10;
        RBus_UInt32  m11:11;
    };
}tab1_M1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  m23:9;
        RBus_UInt32  m22:10;
        RBus_UInt32  m21:10;
    };
}tab1_M2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  m33:10;
        RBus_UInt32  m32:11;
        RBus_UInt32  m31:10;
    };
}tab1_M3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  y_gain:9;
        RBus_UInt32  yo_odd:11;
        RBus_UInt32  yo_even:11;
    };
}tab1_Yo_and_Y_Gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m13:11;
        RBus_UInt32  m12:10;
        RBus_UInt32  m11:11;
    };
}tab2_M1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  m23:9;
        RBus_UInt32  m22:10;
        RBus_UInt32  m21:10;
    };
}tab2_M2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  m33:10;
        RBus_UInt32  m32:11;
        RBus_UInt32  m31:10;
    };
}tab2_M3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  y_gain:9;
        RBus_UInt32  yo_odd:11;
        RBus_UInt32  yo_even:11;
    };
}tab2_Yo_and_Y_Gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  cr_dly_cb:1;
        RBus_UInt32  dup:1;
        RBus_UInt32  en_422to444:1;
    };
}ich1_422to444_CTRL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  i_m_mapping:10;
        RBus_UInt32  i_m_boundary:10;
        RBus_UInt32  i_m_threashold:10;
        RBus_UInt32  i_m_enable:1;
    };
}c_coring_data_1_I_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  i_m_slope1:7;
        RBus_UInt32  i_m_slope0:5;
        RBus_UInt32  i_m_condition_mode:1;
    };
}c_coring_data_2_I_RBUS;





#else //apply LITTLE_ENDIAN


//======RGB2YUV register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  en_rgb2yuv:2;
        RBus_UInt32  sel_table:1;
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
}ich1_RGB2YUV_CTRL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m11:11;
        RBus_UInt32  m12:10;
        RBus_UInt32  m13:11;
    };
}tab1_M1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m21:10;
        RBus_UInt32  m22:10;
        RBus_UInt32  m23:9;
        RBus_UInt32  res1:3;
    };
}tab1_M2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m31:10;
        RBus_UInt32  m32:11;
        RBus_UInt32  m33:10;
        RBus_UInt32  res1:1;
    };
}tab1_M3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  yo_even:11;
        RBus_UInt32  yo_odd:11;
        RBus_UInt32  y_gain:9;
        RBus_UInt32  res1:1;
    };
}tab1_Yo_and_Y_Gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m11:11;
        RBus_UInt32  m12:10;
        RBus_UInt32  m13:11;
    };
}tab2_M1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m21:10;
        RBus_UInt32  m22:10;
        RBus_UInt32  m23:9;
        RBus_UInt32  res1:3;
    };
}tab2_M2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m31:10;
        RBus_UInt32  m32:11;
        RBus_UInt32  m33:10;
        RBus_UInt32  res1:1;
    };
}tab2_M3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  yo_even:11;
        RBus_UInt32  yo_odd:11;
        RBus_UInt32  y_gain:9;
        RBus_UInt32  res1:1;
    };
}tab2_Yo_and_Y_Gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  en_422to444:1;
        RBus_UInt32  dup:1;
        RBus_UInt32  cr_dly_cb:1;
        RBus_UInt32  res1:29;
    };
}ich1_422to444_CTRL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_m_enable:1;
        RBus_UInt32  i_m_threashold:10;
        RBus_UInt32  i_m_boundary:10;
        RBus_UInt32  i_m_mapping:10;
        RBus_UInt32  res1:1;
    };
}c_coring_data_1_I_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_m_condition_mode:1;
        RBus_UInt32  i_m_slope0:5;
        RBus_UInt32  i_m_slope1:7;
        RBus_UInt32  res1:19;
    };
}c_coring_data_2_I_RBUS;


#endif







#endif //_RBUS_RGB2YUV_REG_H_


