/**
* @file Mac5-DesignSpec-D-Domain_Panel_Compensation
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_SRGB_REG_H_
#define _RBUS_SRGB_REG_H_

#include "rbus_types.h"



//  SRGB Register Address
#define  SRGB_sRGB_CTRL                                                          0x1802C000
#define  SRGB_sRGB_CTRL_reg_addr                                                 "0xB802C000"
#define  SRGB_sRGB_CTRL_reg                                                      0xB802C000
#define  SRGB_sRGB_CTRL_inst_addr                                                "0x0000"
#define  set_SRGB_sRGB_CTRL_reg(data)                                            (*((volatile unsigned int*)SRGB_sRGB_CTRL_reg)=data)
#define  get_SRGB_sRGB_CTRL_reg                                                  (*((volatile unsigned int*)SRGB_sRGB_CTRL_reg))
#define  SRGB_sRGB_CTRL_srgb_tab_addr_shift                                      (16)
#define  SRGB_sRGB_CTRL_srgb_m_tab_sel_shift                                     (0)
#define  SRGB_sRGB_CTRL_srgb_tab_addr_mask                                       (0x007F0000)
#define  SRGB_sRGB_CTRL_srgb_m_tab_sel_mask                                      (0x00000003)
#define  SRGB_sRGB_CTRL_srgb_tab_addr(data)                                      (0x007F0000&((data)<<16))
#define  SRGB_sRGB_CTRL_srgb_m_tab_sel(data)                                     (0x00000003&(data))
#define  SRGB_sRGB_CTRL_get_srgb_tab_addr(data)                                  ((0x007F0000&(data))>>16)
#define  SRGB_sRGB_CTRL_get_srgb_m_tab_sel(data)                                 (0x00000003&(data))

#define  SRGB_sRGB_Access_CTRL                                                   0x1802C004
#define  SRGB_sRGB_Access_CTRL_reg_addr                                          "0xB802C004"
#define  SRGB_sRGB_Access_CTRL_reg                                               0xB802C004
#define  SRGB_sRGB_Access_CTRL_inst_addr                                         "0x0001"
#define  set_SRGB_sRGB_Access_CTRL_reg(data)                                     (*((volatile unsigned int*)SRGB_sRGB_Access_CTRL_reg)=data)
#define  get_SRGB_sRGB_Access_CTRL_reg                                           (*((volatile unsigned int*)SRGB_sRGB_Access_CTRL_reg))
#define  SRGB_sRGB_Access_CTRL_srgb_rgb_sel_shift                                (2)
#define  SRGB_sRGB_Access_CTRL_srgb_fifo_empty_shift                             (0)
#define  SRGB_sRGB_Access_CTRL_srgb_rgb_sel_mask                                 (0x0000000C)
#define  SRGB_sRGB_Access_CTRL_srgb_fifo_empty_mask                              (0x00000001)
#define  SRGB_sRGB_Access_CTRL_srgb_rgb_sel(data)                                (0x0000000C&((data)<<2))
#define  SRGB_sRGB_Access_CTRL_srgb_fifo_empty(data)                             (0x00000001&(data))
#define  SRGB_sRGB_Access_CTRL_get_srgb_rgb_sel(data)                            ((0x0000000C&(data))>>2)
#define  SRGB_sRGB_Access_CTRL_get_srgb_fifo_empty(data)                         (0x00000001&(data))

#define  SRGB_sRGB_BIST                                                          0x1802C008
#define  SRGB_sRGB_BIST_reg_addr                                                 "0xB802C008"
#define  SRGB_sRGB_BIST_reg                                                      0xB802C008
#define  SRGB_sRGB_BIST_inst_addr                                                "0x0002"
#define  set_SRGB_sRGB_BIST_reg(data)                                            (*((volatile unsigned int*)SRGB_sRGB_BIST_reg)=data)
#define  get_SRGB_sRGB_BIST_reg                                                  (*((volatile unsigned int*)SRGB_sRGB_BIST_reg))
#define  SRGB_sRGB_BIST_dummy_31_0_shift                                         (0)
#define  SRGB_sRGB_BIST_dummy_31_0_mask                                          (0xFFFFFFFF)
#define  SRGB_sRGB_BIST_dummy_31_0(data)                                         (0xFFFFFFFF&(data))
#define  SRGB_sRGB_BIST_get_dummy_31_0(data)                                     (0xFFFFFFFF&(data))

#define  SRGB_sRGB_ACCESS_PORT                                                   0x1802C00C
#define  SRGB_sRGB_ACCESS_PORT_reg_addr                                          "0xB802C00C"
#define  SRGB_sRGB_ACCESS_PORT_reg                                               0xB802C00C
#define  SRGB_sRGB_ACCESS_PORT_inst_addr                                         "0x0003"
#define  set_SRGB_sRGB_ACCESS_PORT_reg(data)                                     (*((volatile unsigned int*)SRGB_sRGB_ACCESS_PORT_reg)=data)
#define  get_SRGB_sRGB_ACCESS_PORT_reg                                           (*((volatile unsigned int*)SRGB_sRGB_ACCESS_PORT_reg))
#define  SRGB_sRGB_ACCESS_PORT_srgb_index_shift                                  (10)
#define  SRGB_sRGB_ACCESS_PORT_srgb_gain_shift                                   (0)
#define  SRGB_sRGB_ACCESS_PORT_srgb_index_mask                                   (0x03FFFC00)
#define  SRGB_sRGB_ACCESS_PORT_srgb_gain_mask                                    (0x000003FF)
#define  SRGB_sRGB_ACCESS_PORT_srgb_index(data)                                  (0x03FFFC00&((data)<<10))
#define  SRGB_sRGB_ACCESS_PORT_srgb_gain(data)                                   (0x000003FF&(data))
#define  SRGB_sRGB_ACCESS_PORT_get_srgb_index(data)                              ((0x03FFFC00&(data))>>10)
#define  SRGB_sRGB_ACCESS_PORT_get_srgb_gain(data)                               (0x000003FF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======SRGB register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  srgb_tab_addr:7;
        RBus_UInt32  res2:14;
        RBus_UInt32  srgb_m_tab_sel:2;
    };
}srgb_srgb_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  srgb_rgb_sel:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  srgb_fifo_empty:1;
    };
}srgb_srgb_access_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802c008_31_0:32;
    };
}srgb_srgb_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  srgb_index:16;
        RBus_UInt32  srgb_gain:10;
    };
}srgb_srgb_access_port_RBUS;

#else //apply LITTLE_ENDIAN

//======SRGB register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srgb_m_tab_sel:2;
        RBus_UInt32  res1:14;
        RBus_UInt32  srgb_tab_addr:7;
        RBus_UInt32  res2:9;
    };
}srgb_srgb_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srgb_fifo_empty:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  srgb_rgb_sel:2;
        RBus_UInt32  res2:28;
    };
}srgb_srgb_access_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802c008_31_0:32;
    };
}srgb_srgb_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srgb_gain:10;
        RBus_UInt32  srgb_index:16;
        RBus_UInt32  res1:6;
    };
}srgb_srgb_access_port_RBUS;




#endif 


#endif 
