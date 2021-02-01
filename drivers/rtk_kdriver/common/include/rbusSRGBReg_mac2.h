/**
* @file rbusSRGBReg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2012/11/14
* @version 802
* @ingroup model_rbus
*
*/

#ifndef _RBUS_SRGB_REG_H_
#define _RBUS_SRGB_REG_H_

#include "rbus/rbusTypes.h"




// SRGB Register Address
#define SRGB_SRGB_CTRL_ADDR                        (0x1802c000)
#define SRGB_SRGB_ACCESS_CTRL_ADDR                 (0x1802c004)
#define SRGB_SRGB_BIST_ADDR                        (0x1802c008)
#define SRGB_SRGB_ACCESS_PORT_ADDR                 (0x1802c00c)

#define SRGB_SRGB_CTRL_VADDR                       (0xb802c000)
#define SRGB_SRGB_ACCESS_CTRL_VADDR                (0xb802c004)
#define SRGB_SRGB_BIST_VADDR                       (0xb802c008)
#define SRGB_SRGB_ACCESS_PORT_VADDR                (0xb802c00c)




#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======SRGB register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  srgb_swap:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  srgb_m_tab_sel:2;
    };
}srgb_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  srgb_rgb_sel:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  srgb_fifo_empty:1;
    };
}srgb_access_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  dummy1802c008_3_2:2;
        RBus_UInt32  res2:2;
    };
}srgb_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  srgb_index:14;
        RBus_UInt32  srgb_gain:10;
    };
}srgb_access_port_RBUS;





#else //apply LITTLE_ENDIAN


//======SRGB register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srgb_m_tab_sel:2;
        RBus_UInt32  res2:3;
        RBus_UInt32  srgb_swap:1;
        RBus_UInt32  res1:26;
    };
}srgb_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srgb_fifo_empty:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  srgb_rgb_sel:2;
        RBus_UInt32  res1:28;
    };
}srgb_access_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:2;
        RBus_UInt32  dummy1802c008_3_2:2;
        RBus_UInt32  res1:28;
    };
}srgb_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srgb_gain:10;
        RBus_UInt32  srgb_index:14;
        RBus_UInt32  res1:8;
    };
}srgb_access_port_RBUS;


#endif







#endif //_RBUS_SRGB_REG_H_

