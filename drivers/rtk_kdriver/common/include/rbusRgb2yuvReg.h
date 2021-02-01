/**
* @file rbusRgb2yuvReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015/2/12
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_RGB2YUV_REG_H_
#define _RBUS_RGB2YUV_REG_H_

#include "rbusTypes.h"



//  RGB2YUV Register Address



#define  RGB2YUV_ICH1_RGB2YUV_CTRL_VADDR                    	(0xb8023000)
#define  RGB2YUV_ICH2_RGB2YUV_CTRL_VADDR                    	(0xb8023004)
#define  RGB2YUV_TAB1_M11_M12_VADDR                         	(0xb8023008)
#define  RGB2YUV_TAB1_M13_M21_VADDR                         	(0xb802300c)
#define  RGB2YUV_TAB1_M22_M23_VADDR                         	(0xb8023010)
#define  RGB2YUV_TAB1_M31_M32_VADDR                         	(0xb8023014)
#define  RGB2YUV_TAB1_M33_YGAIN_VADDR                       	(0xb8023018)
#define  RGB2YUV_TAB1_YO_VADDR                              	(0xb802301c)
#define  RGB2YUV_TAB2_M11_M12_VADDR                         	(0xb8023020)
#define  RGB2YUV_TAB2_M13_M21_VADDR                         	(0xb8023024)
#define  RGB2YUV_TAB2_M22_M23_VADDR                         	(0xb8023028)
#define  RGB2YUV_TAB2_M31_M32_VADDR                         	(0xb802302c)
#define  RGB2YUV_TAB2_M33_Y_GAIN_VADDR                      	(0xb8023030)
#define  RGB2YUV_TAB2_YO_VADDR                              	(0xb8023034)
#define  RGB2YUV_ICH1_422TO444_CTRL_VADDR                   	(0xb8023038)
#define  RGB2YUV_ICH2_422TO444_CTRL_VADDR                   	(0xb802303c)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======RGB2YUV register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
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
        RBus_UInt32  sel_table:1;
        RBus_UInt32  en_rgb2yuv:2;
    };
}rgb2yuv_ich1_rgb2yuv_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  err_dif_bits:3;
        RBus_UInt32  err_dif_enable:1;
        RBus_UInt32  rgb_in_offset:1;
        RBus_UInt32  res2:1;
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
}rgb2yuv_ich2_rgb2yuv_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  m12:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  m11:15;
    };
}rgb2yuv_tab1_m11_m12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  m21:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  m13:15;
    };
}rgb2yuv_tab1_m13_m21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  m23:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  m22:15;
    };
}rgb2yuv_tab1_m22_m23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  m32:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  m31:15;
    };
}rgb2yuv_tab1_m31_m32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  y_gain:9;
        RBus_UInt32  res2:1;
        RBus_UInt32  m33:15;
    };
}rgb2yuv_tab1_m33_ygain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  yo_odd:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  yo_even:13;
    };
}rgb2yuv_tab1_yo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  m12:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  m11:15;
    };
}rgb2yuv_tab2_m11_m12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  m21:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  m13:15;
    };
}rgb2yuv_tab2_m13_m21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  m23:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  m22:15;
    };
}rgb2yuv_tab2_m22_m23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  m32:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  m31:15;
    };
}rgb2yuv_tab2_m31_m32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  y_gain:9;
        RBus_UInt32  res2:1;
        RBus_UInt32  m33:15;
    };
}rgb2yuv_tab2_m33_y_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  yo_odd:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  yo_even:13;
    };
}rgb2yuv_tab2_yo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  cr_dly_cb:1;
        RBus_UInt32  dup:1;
        RBus_UInt32  en_422to444:1;
    };
}rgb2yuv_ich1_422to444_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  cr_dly_cb:1;
        RBus_UInt32  dup:1;
        RBus_UInt32  en_422to444:1;
    };
}rgb2yuv_ich2_422to444_ctrl_RBUS;

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
        RBus_UInt32  rgb_in_offset:1;
        RBus_UInt32  err_dif_enable:1;
        RBus_UInt32  err_dif_bits:3;
        RBus_UInt32  res1:16;
    };
}rgb2yuv_ich1_rgb2yuv_ctrl_RBUS;

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
        RBus_UInt32  res1:1;
        RBus_UInt32  rgb_in_offset:1;
        RBus_UInt32  err_dif_enable:1;
        RBus_UInt32  err_dif_bits:3;
        RBus_UInt32  res2:15;
    };
}rgb2yuv_ich2_rgb2yuv_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m11:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  m12:15;
        RBus_UInt32  res2:1;
    };
}rgb2yuv_tab1_m11_m12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m13:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  m21:15;
        RBus_UInt32  res2:1;
    };
}rgb2yuv_tab1_m13_m21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m22:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  m23:15;
        RBus_UInt32  res2:1;
    };
}rgb2yuv_tab1_m22_m23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m31:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  m32:15;
        RBus_UInt32  res2:1;
    };
}rgb2yuv_tab1_m31_m32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m33:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  y_gain:9;
        RBus_UInt32  res2:7;
    };
}rgb2yuv_tab1_m33_ygain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  yo_even:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  yo_odd:13;
        RBus_UInt32  res2:3;
    };
}rgb2yuv_tab1_yo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m11:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  m12:15;
        RBus_UInt32  res2:1;
    };
}rgb2yuv_tab2_m11_m12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m13:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  m21:15;
        RBus_UInt32  res2:1;
    };
}rgb2yuv_tab2_m13_m21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m22:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  m23:15;
        RBus_UInt32  res2:1;
    };
}rgb2yuv_tab2_m22_m23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m31:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  m32:15;
        RBus_UInt32  res2:1;
    };
}rgb2yuv_tab2_m31_m32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m33:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  y_gain:9;
        RBus_UInt32  res2:7;
    };
}rgb2yuv_tab2_m33_y_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  yo_even:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  yo_odd:13;
        RBus_UInt32  res2:3;
    };
}rgb2yuv_tab2_yo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  en_422to444:1;
        RBus_UInt32  dup:1;
        RBus_UInt32  cr_dly_cb:1;
        RBus_UInt32  res1:29;
    };
}rgb2yuv_ich1_422to444_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  en_422to444:1;
        RBus_UInt32  dup:1;
        RBus_UInt32  cr_dly_cb:1;
        RBus_UInt32  res1:29;
    };
}rgb2yuv_ich2_422to444_ctrl_RBUS;




#endif 


#endif 
