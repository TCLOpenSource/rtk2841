/**
* @file rbusSRGBReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015/2/12
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_SRGB_REG_H_
#define _RBUS_SRGB_REG_H_

#include "rbusTypes.h"



//  SRGB Register Address



#define  SRGB_SRGB_CTRL_VADDR                               	(0xb802c000)
#define  SRGB_SRGB_ACCESS_CTRL_VADDR                        	(0xb802c004)
#define  SRGB_SRGB_BIST_VADDR                               	(0xb802c008)
#define  SRGB_SRGB_ACCESS_PORT_VADDR                        	(0xb802c00c)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======SRGB register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  srgb_tab_addr:7;
        RBus_UInt32  res2:10;
        RBus_UInt32  srgb_tab_size_sel:1;
        RBus_UInt32  srgb_overlap:1;
        RBus_UInt32  srgb_s_tab_sel:2;
        RBus_UInt32  srgb_m_tab_sel:2;
    };
}srgb_srgb_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  srgb_rgb_sel:2;
        RBus_UInt32  srgb_tab_sel:1;
        RBus_UInt32  srgb_fifo_empty:1;
    };
}srgb_srgb_access_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  dummy1802c008_3_2:2;
        RBus_UInt32  res2:2;
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
        RBus_UInt32  srgb_s_tab_sel:2;
        RBus_UInt32  srgb_overlap:1;
        RBus_UInt32  srgb_tab_size_sel:1;
        RBus_UInt32  res1:10;
        RBus_UInt32  srgb_tab_addr:7;
        RBus_UInt32  res2:9;
    };
}srgb_srgb_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srgb_fifo_empty:1;
        RBus_UInt32  srgb_tab_sel:1;
        RBus_UInt32  srgb_rgb_sel:2;
        RBus_UInt32  res1:28;
    };
}srgb_srgb_access_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  dummy1802c008_3_2:2;
        RBus_UInt32  res2:28;
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
