/**
* @file rbusMFifoReg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2006/11/3
* @version 1.1
* @ingroup model_rbus
*
*/

#ifndef _RBUS_MFIFO_REG_H_
#define _RBUS_MFIFO_REG_H_

#include "rbus/rbusTypes.h"




// MFIFO Register Address
#define MFIFO_DDR_CH1FIFOSTATUS_ADDR               (0x18080100)
#define MFIFO_DDR_MAINFIFOSTATUS_ADDR              (0x18080104)
#define MFIFO_DDR_ADDR_ADDR                        (0x18080108)
#define MFIFO_DDRDAT0_ADDR                         (0x1808011c)
#define MFIFO_DDRDAT1_ADDR                         (0x18080120)
#define MFIFO_DDRDAT2_ADDR                         (0x18080124)
#define MFIFO_DDRDAT3_ADDR                         (0x18080128)
#define MFIFO_DDRDAT4_ADDR                         (0x1808012c)
#define MFIFO_DDRDAT5_ADDR                         (0x18080130)
#define MFIFO_DDRDAT6_ADDR                         (0x18080134)
#define MFIFO_DDRDAT7_ADDR                         (0x18080138)




#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======MFIFO register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  in1bistdoing:1;
        RBus_UInt32  in1biststatus:1;
        RBus_UInt32  in1bistenable:1;
        RBus_UInt32  in1clearstatus:1;
        RBus_UInt32  in1fifofull:1;
        RBus_UInt32  in1fifoempty:1;
        RBus_UInt32  in1fifoof:1;
        RBus_UInt32  in1fifouf:1;
        RBus_UInt32  in2bistdoing:1;
        RBus_UInt32  in2biststatus:1;
        RBus_UInt32  in2bistenable:1;
        RBus_UInt32  in2clearstatus:1;
        RBus_UInt32  in2fifofull:1;
        RBus_UInt32  in2fifoempty:1;
        RBus_UInt32  in2fifoof:1;
        RBus_UInt32  in2fifouf:1;
    };
}ddr_ch1fifostatus_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  mainbistdoing:1;
        RBus_UInt32  mainbiststatus:1;
        RBus_UInt32  mainbistenable:1;
        RBus_UInt32  mainclearstatus:1;
        RBus_UInt32  mainfifofull:1;
        RBus_UInt32  mainfifoempty:1;
        RBus_UInt32  mainfifoof:1;
        RBus_UInt32  mainfifouf:1;
        RBus_UInt32  subbistdoing:1;
        RBus_UInt32  subbiststatus:1;
        RBus_UInt32  subbistenable:1;
        RBus_UInt32  subclearstatus:1;
        RBus_UInt32  subfifofull:1;
        RBus_UInt32  subfifoempty:1;
        RBus_UInt32  subfifoof:1;
        RBus_UInt32  subfifouf:1;
        RBus_UInt32  clearstatus:1;
        RBus_UInt32  fifofull:1;
        RBus_UInt32  fifoempty:1;
        RBus_UInt32  fifoof:1;
        RBus_UInt32  fifouf:1;
    };
}ddr_mainfifostatus_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  addr:23;
        RBus_UInt32  accesscmd:3;
    };
}ddr_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  buf:32;
    };
}ddrdat0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  buf:32;
    };
}ddrdat1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  buf:32;
    };
}ddrdat2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  buf:32;
    };
}ddrdat3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  buf:32;
    };
}ddrdat4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  buf:32;
    };
}ddrdat5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  buf:32;
    };
}ddrdat6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  buf:32;
    };
}ddrdat7_RBUS;





#else //apply LITTLE_ENDIAN


//======MFIFO register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in2fifouf:1;
        RBus_UInt32  in2fifoof:1;
        RBus_UInt32  in2fifoempty:1;
        RBus_UInt32  in2fifofull:1;
        RBus_UInt32  in2clearstatus:1;
        RBus_UInt32  in2bistenable:1;
        RBus_UInt32  in2biststatus:1;
        RBus_UInt32  in2bistdoing:1;
        RBus_UInt32  in1fifouf:1;
        RBus_UInt32  in1fifoof:1;
        RBus_UInt32  in1fifoempty:1;
        RBus_UInt32  in1fifofull:1;
        RBus_UInt32  in1clearstatus:1;
        RBus_UInt32  in1bistenable:1;
        RBus_UInt32  in1biststatus:1;
        RBus_UInt32  in1bistdoing:1;
        RBus_UInt32  res1:16;
    };
}ddr_ch1fifostatus_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fifouf:1;
        RBus_UInt32  fifoof:1;
        RBus_UInt32  fifoempty:1;
        RBus_UInt32  fifofull:1;
        RBus_UInt32  clearstatus:1;
        RBus_UInt32  subfifouf:1;
        RBus_UInt32  subfifoof:1;
        RBus_UInt32  subfifoempty:1;
        RBus_UInt32  subfifofull:1;
        RBus_UInt32  subclearstatus:1;
        RBus_UInt32  subbistenable:1;
        RBus_UInt32  subbiststatus:1;
        RBus_UInt32  subbistdoing:1;
        RBus_UInt32  mainfifouf:1;
        RBus_UInt32  mainfifoof:1;
        RBus_UInt32  mainfifoempty:1;
        RBus_UInt32  mainfifofull:1;
        RBus_UInt32  mainclearstatus:1;
        RBus_UInt32  mainbistenable:1;
        RBus_UInt32  mainbiststatus:1;
        RBus_UInt32  mainbistdoing:1;
        RBus_UInt32  res1:11;
    };
}ddr_mainfifostatus_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  accesscmd:3;
        RBus_UInt32  addr:23;
        RBus_UInt32  res1:6;
    };
}ddr_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  buf:32;
    };
}ddrdat0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  buf:32;
    };
}ddrdat1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  buf:32;
    };
}ddrdat2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  buf:32;
    };
}ddrdat3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  buf:32;
    };
}ddrdat4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  buf:32;
    };
}ddrdat5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  buf:32;
    };
}ddrdat6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  buf:32;
    };
}ddrdat7_RBUS;


#endif







#endif //_RBUS_MFIFO_REG_H_

