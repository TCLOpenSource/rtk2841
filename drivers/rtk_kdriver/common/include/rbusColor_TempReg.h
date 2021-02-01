/**
* @file rbusColor_TempReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015/2/12
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_COLOR_TEMP_REG_H_
#define _RBUS_COLOR_TEMP_REG_H_

#include "rbusTypes.h"



//  COLOR_TEMP Register Address



#define  COLOR_TEMP_COLOR_TEMP_CTRL_VADDR                   	(0xb802c400)
#define  COLOR_TEMP_COLOR_TEMP_CONTRAST_0_VADDR             	(0xb802c404)
#define  COLOR_TEMP_COLOR_TEMP_CONTRAST_1_VADDR             	(0xb802c408)
#define  COLOR_TEMP_COLOR_TEMP_BRIGHTNESS_0_VADDR           	(0xb802c40c)
#define  COLOR_TEMP_COLOR_TEMP_BRIGHTNESS_1_VADDR           	(0xb802c410)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======COLOR_TEMP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  color_temp_en:1;
    };
}color_temp_color_temp_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  contrast_g:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  contrast_r:12;
    };
}color_temp_color_temp_contrast_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  contrast_b:12;
    };
}color_temp_color_temp_contrast_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  bright_g:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  bright_r:12;
    };
}color_temp_color_temp_brightness_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  bright_b:12;
    };
}color_temp_color_temp_brightness_1_RBUS;

#else //apply LITTLE_ENDIAN

//======COLOR_TEMP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  color_temp_en:1;
        RBus_UInt32  res1:31;
    };
}color_temp_color_temp_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  contrast_r:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  contrast_g:12;
        RBus_UInt32  res2:4;
    };
}color_temp_color_temp_contrast_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  contrast_b:12;
        RBus_UInt32  res1:20;
    };
}color_temp_color_temp_contrast_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bright_r:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  bright_g:12;
        RBus_UInt32  res2:4;
    };
}color_temp_color_temp_brightness_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bright_b:12;
        RBus_UInt32  res1:20;
    };
}color_temp_color_temp_brightness_1_RBUS;




#endif 


#endif 
