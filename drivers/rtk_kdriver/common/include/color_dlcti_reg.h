/**
* @file Mac5-DesignSpec-D-Domain_DCTI_DLTI
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_COLOR_DLCTI_REG_H_
#define _RBUS_COLOR_DLCTI_REG_H_

#include "rbus_types.h"



//  COLOR_DLCTI Register Address
#define  COLOR_DLCTI_UV_Delay                                                    0x1802A034
#define  COLOR_DLCTI_UV_Delay_reg_addr                                           "0xB802A034"
#define  COLOR_DLCTI_UV_Delay_reg                                                0xB802A034
#define  COLOR_DLCTI_UV_Delay_inst_addr                                          "0x0000"
#define  set_COLOR_DLCTI_UV_Delay_reg(data)                                      (*((volatile unsigned int*)COLOR_DLCTI_UV_Delay_reg)=data)
#define  get_COLOR_DLCTI_UV_Delay_reg                                            (*((volatile unsigned int*)COLOR_DLCTI_UV_Delay_reg))
#define  COLOR_DLCTI_UV_Delay_u_delay_shift                                      (5)
#define  COLOR_DLCTI_UV_Delay_v_delay_shift                                      (1)
#define  COLOR_DLCTI_UV_Delay_uv_delay_en_shift                                  (0)
#define  COLOR_DLCTI_UV_Delay_u_delay_mask                                       (0x000001E0)
#define  COLOR_DLCTI_UV_Delay_v_delay_mask                                       (0x0000001E)
#define  COLOR_DLCTI_UV_Delay_uv_delay_en_mask                                   (0x00000001)
#define  COLOR_DLCTI_UV_Delay_u_delay(data)                                      (0x000001E0&((data)<<5))
#define  COLOR_DLCTI_UV_Delay_v_delay(data)                                      (0x0000001E&((data)<<1))
#define  COLOR_DLCTI_UV_Delay_uv_delay_en(data)                                  (0x00000001&(data))
#define  COLOR_DLCTI_UV_Delay_get_u_delay(data)                                  ((0x000001E0&(data))>>5)
#define  COLOR_DLCTI_UV_Delay_get_v_delay(data)                                  ((0x0000001E&(data))>>1)
#define  COLOR_DLCTI_UV_Delay_get_uv_delay_en(data)                              (0x00000001&(data))

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
        RBus_UInt32  uv_delay_en:1;
        RBus_UInt32  v_delay:4;
        RBus_UInt32  u_delay:4;
        RBus_UInt32  res1:23;
    };
}color_dlcti_uv_delay_RBUS;




#endif 


#endif 
