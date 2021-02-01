/**
* @file Mac5-DesignSpec-IMD_smooth_toggle_double_buffer_detail_register
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_SMOOTH_TOGGLE_DETAIL_REG_H_
#define _RBUS_SMOOTH_TOGGLE_DETAIL_REG_H_

#include "rbus_types.h"



//  SMOOTH_TOGGLE_DETAIL Register Address
#define  SMOOTH_TOGGLE_DETAIL_ICH2_UZD_Initial_Value                             0x18025410
#define  SMOOTH_TOGGLE_DETAIL_ICH2_UZD_Initial_Value_reg_addr                    "0xB8025410"
#define  SMOOTH_TOGGLE_DETAIL_ICH2_UZD_Initial_Value_reg                         0xB8025410
#define  SMOOTH_TOGGLE_DETAIL_ICH2_UZD_Initial_Value_inst_addr                   "0x0000"
#define  set_SMOOTH_TOGGLE_DETAIL_ICH2_UZD_Initial_Value_reg(data)               (*((volatile unsigned int*)SMOOTH_TOGGLE_DETAIL_ICH2_UZD_Initial_Value_reg)=data)
#define  get_SMOOTH_TOGGLE_DETAIL_ICH2_UZD_Initial_Value_reg                     (*((volatile unsigned int*)SMOOTH_TOGGLE_DETAIL_ICH2_UZD_Initial_Value_reg))
#define  SMOOTH_TOGGLE_DETAIL_ICH2_UZD_Initial_Value_hor_ini_shift               (8)
#define  SMOOTH_TOGGLE_DETAIL_ICH2_UZD_Initial_Value_ver_ini_shift               (0)
#define  SMOOTH_TOGGLE_DETAIL_ICH2_UZD_Initial_Value_hor_ini_mask                (0x0000FF00)
#define  SMOOTH_TOGGLE_DETAIL_ICH2_UZD_Initial_Value_ver_ini_mask                (0x000000FF)
#define  SMOOTH_TOGGLE_DETAIL_ICH2_UZD_Initial_Value_hor_ini(data)               (0x0000FF00&((data)<<8))
#define  SMOOTH_TOGGLE_DETAIL_ICH2_UZD_Initial_Value_ver_ini(data)               (0x000000FF&(data))
#define  SMOOTH_TOGGLE_DETAIL_ICH2_UZD_Initial_Value_get_hor_ini(data)           ((0x0000FF00&(data))>>8)
#define  SMOOTH_TOGGLE_DETAIL_ICH2_UZD_Initial_Value_get_ver_ini(data)           (0x000000FF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======SMOOTH_TOGGLE_DETAIL register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  hor_ini:8;
        RBus_UInt32  ver_ini:8;
    };
}smooth_toggle_detail_ich2_uzd_initial_value_RBUS;

#else //apply LITTLE_ENDIAN

//======SMOOTH_TOGGLE_DETAIL register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_ini:8;
        RBus_UInt32  hor_ini:8;
        RBus_UInt32  res1:16;
    };
}smooth_toggle_detail_ich2_uzd_initial_value_RBUS;




#endif 


#endif 
