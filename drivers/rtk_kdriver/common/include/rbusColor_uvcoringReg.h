/**
* @file rbusColor_uvcoringReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015/2/12
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_COLOR_UVCORING_REG_H_
#define _RBUS_COLOR_UVCORING_REG_H_

#include "rbusTypes.h"



//  COLOR_UVCORING Register Address



#define  COLOR_UVCORING_UVC_CONTROL_VADDR                   	(0xb802ab00)
#define  COLOR_UVCORING_UVC_GLOBAL_U_VADDR                  	(0xb802ab04)
#define  COLOR_UVCORING_UVC_GLOBAL_V_VADDR                  	(0xb802ab08)
#define  COLOR_UVCORING_UVC_SKIN_U_VADDR                    	(0xb802ab0c)
#define  COLOR_UVCORING_UVC_SKIN_V_VADDR                    	(0xb802ab10)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======COLOR_UVCORING register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802ab00_31_28:4;
        RBus_UInt32  uvc_yslope:10;
        RBus_UInt32  uvc_y0:10;
        RBus_UInt32  uvc_qdrt4_en:1;
        RBus_UInt32  uvc_qdrt3_en:1;
        RBus_UInt32  uvc_qdrt2_en:1;
        RBus_UInt32  uvc_qdrt1_en:1;
        RBus_UInt32  uvc_skin_sel:1;
        RBus_UInt32  uvc_overlay_sel:1;
        RBus_UInt32  uvc_sub_en:1;
        RBus_UInt32  uvc_main_en:1;
    };
}color_uvcoring_uvc_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uvc_u_slope2_g:8;
        RBus_UInt32  res1:2;
        RBus_UInt32  uvc_u_thd2_g:6;
        RBus_UInt32  uvc_u_slope1_g:8;
        RBus_UInt32  res2:2;
        RBus_UInt32  uvc_u_thd1_g:6;
    };
}color_uvcoring_uvc_global_u_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uvc_v_slope2_g:8;
        RBus_UInt32  res1:2;
        RBus_UInt32  uvc_v_thd2_g:6;
        RBus_UInt32  uvc_v_slope1_g:8;
        RBus_UInt32  res2:2;
        RBus_UInt32  uvc_v_thd1_g:6;
    };
}color_uvcoring_uvc_global_v_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uvc_u_slope2_sk:8;
        RBus_UInt32  res1:2;
        RBus_UInt32  uvc_u_thd2_sk:6;
        RBus_UInt32  uvc_u_slope1_sk:8;
        RBus_UInt32  res2:2;
        RBus_UInt32  uvc_u_thd1_sk:6;
    };
}color_uvcoring_uvc_skin_u_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uvc_v_slope2_sk:8;
        RBus_UInt32  res1:2;
        RBus_UInt32  uvc_v_thd2_sk:6;
        RBus_UInt32  uvc_v_slope1_sk:8;
        RBus_UInt32  res2:2;
        RBus_UInt32  uvc_v_thd1_sk:6;
    };
}color_uvcoring_uvc_skin_v_RBUS;

#else //apply LITTLE_ENDIAN

//======COLOR_UVCORING register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uvc_main_en:1;
        RBus_UInt32  uvc_sub_en:1;
        RBus_UInt32  uvc_overlay_sel:1;
        RBus_UInt32  uvc_skin_sel:1;
        RBus_UInt32  uvc_qdrt1_en:1;
        RBus_UInt32  uvc_qdrt2_en:1;
        RBus_UInt32  uvc_qdrt3_en:1;
        RBus_UInt32  uvc_qdrt4_en:1;
        RBus_UInt32  uvc_y0:10;
        RBus_UInt32  uvc_yslope:10;
        RBus_UInt32  dummy1802ab00_31:4;
    };
}color_uvcoring_uvc_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uvc_u_thd1_g:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  uvc_u_slope1_g:8;
        RBus_UInt32  uvc_u_thd2_g:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  uvc_u_slope2_g:8;
    };
}color_uvcoring_uvc_global_u_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uvc_v_thd1_g:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  uvc_v_slope1_g:8;
        RBus_UInt32  uvc_v_thd2_g:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  uvc_v_slope2_g:8;
    };
}color_uvcoring_uvc_global_v_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uvc_u_thd1_sk:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  uvc_u_slope1_sk:8;
        RBus_UInt32  uvc_u_thd2_sk:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  uvc_u_slope2_sk:8;
    };
}color_uvcoring_uvc_skin_u_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uvc_v_thd1_sk:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  uvc_v_slope1_sk:8;
        RBus_UInt32  uvc_v_thd2_sk:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  uvc_v_slope2_sk:8;
    };
}color_uvcoring_uvc_skin_v_RBUS;




#endif 


#endif 
