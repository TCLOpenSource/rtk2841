/**
* @file rbusColor_dlctiReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015/2/12
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_COLOR_DLCTI_REG_H_
#define _RBUS_COLOR_DLCTI_REG_H_

#include "rbusTypes.h"



//  COLOR_DLCTI Register Address



#define  COLOR_DLCTI_DM_DLTI_OPTIONS_VADDR                  	(0xb802a00c)
#define  COLOR_DLCTI_DM_DLTI_VALUE_VADDR                    	(0xb802a010)
#define  COLOR_DLCTI_DS_DCTI_OPTIONS_VADDR                  	(0xb802a028)
#define  COLOR_DLCTI_DS_DCTI_1ST_VALUE_VADDR                	(0xb802a02c)
#define  COLOR_DLCTI_DS_DCTI_2ND_VALUE_VADDR                	(0xb802a030)
#define  COLOR_DLCTI_UV_DELAY_VADDR                         	(0xb802a034)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======COLOR_DLCTI register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}color_dlcti_dm_dlti_options_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}color_dlcti_dm_dlti_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  prevent_pe:1;
        RBus_UInt32  enabled:1;
    };
}color_dlcti_ds_dcti_options_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  th_value:6;
        RBus_UInt32  gain_value:5;
    };
}color_dlcti_ds_dcti_1st_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  th_value:6;
        RBus_UInt32  gain_value:5;
    };
}color_dlcti_ds_dcti_2nd_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  u_delay:4;
        RBus_UInt32  v_delay:4;
        RBus_UInt32  uv_delay_en:1;
    };
}color_dlcti_uv_delay_RBUS;

#else //apply LITTLE_ENDIAN

//======COLOR_DLCTI register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}color_dlcti_dm_dlti_options_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}color_dlcti_dm_dlti_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  enabled:1;
        RBus_UInt32  prevent_pe:1;
        RBus_UInt32  res1:30;
    };
}color_dlcti_ds_dcti_options_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gain_value:5;
        RBus_UInt32  th_value:6;
        RBus_UInt32  res1:21;
    };
}color_dlcti_ds_dcti_1st_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gain_value:5;
        RBus_UInt32  th_value:6;
        RBus_UInt32  res1:21;
    };
}color_dlcti_ds_dcti_2nd_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uv_delay_en:1;
        RBus_UInt32  v_delay:4;
        RBus_UInt32  u_delay:4;
        RBus_UInt32  res1:23;
    };
}color_dlcti_uv_delay_RBUS;




#endif 


#endif 
