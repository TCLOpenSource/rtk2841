/**
* @file rbusIso_offReg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2013/11/13
* @version 802
* @ingroup model_rbus
*
*/

#ifndef _RBUS_ISO_OFF_REG_H_
#define _RBUS_ISO_OFF_REG_H_

#include "rbusTypes.h"




// ISO_OFF Register Address

#define ISO_OFF_IR_SF_VADDR                        (0xb8062408)
#define ISO_OFF_IR_CR_VADDR                        (0xb8062410)
#define ISO_OFF_IR_SR_VADDR                        (0xb8062418)
#define ISO_OFF_IR_RAW_CTRL_VADDR                  (0xb806241c)
#define ISO_OFF_IR_RAW_FF_VADDR                    (0xb8062420)
#define ISO_OFF_IR_RAW_SAMPLE_TIME_VADDR           (0xb8062424)
#define ISO_OFF_IR_RAW_WL_VADDR                    (0xb8062428)
#define ISO_OFF_IR_RAW_DEB_VADDR                   (0xb806242c)
#define ISO_OFF_IR_RAW_SF_VADDR                    (0xb8062440)




#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======ISO_OFF register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  irfd:16;
    };
}ir_off_sf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  raw_fifo_ov_en:1;
        RBus_UInt32  raw_fifo_val_en:1;
        RBus_UInt32  raw_en:1;
        RBus_UInt32  res2:12;
    };
}ir_off_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  raw_fifo_ov:1;
        RBus_UInt32  raw_fifo_val:1;
        RBus_UInt32  res2:2;
    };
}ir_off_sr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  stop_sample:1;
        RBus_UInt32  stop_time:16;
        RBus_UInt32  fifo_thr:8;
    };
}ir_off_raw_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  raw_fifo_rdata:32;
    };
}ir_off_raw_ff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sample_time_cnt:16;
    };
}ir_off_raw_sample_time_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  raw_fifo_wl:8;
    };
}ir_off_raw_wl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  irraw_deb_len:8;
        RBus_UInt32  irraw_deb_clk:16;
    };
}ir_off_raw_deb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  irrawfd:16;
    };
}ir_off_raw_sf_RBUS;





#else //apply LITTLE_ENDIAN


//======ISO_OFF register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  irfd:16;
        RBus_UInt32  res1:16;
    };
}ir_off_sf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:12;
        RBus_UInt32  raw_en:1;
        RBus_UInt32  raw_fifo_val_en:1;
        RBus_UInt32  raw_fifo_ov_en:1;
        RBus_UInt32  res1:17;
    };
}ir_off_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:2;
        RBus_UInt32  raw_fifo_val:1;
        RBus_UInt32  raw_fifo_ov:1;
        RBus_UInt32  res1:28;
    };
}ir_off_sr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fifo_thr:8;
        RBus_UInt32  stop_time:16;
        RBus_UInt32  stop_sample:1;
        RBus_UInt32  res1:7;
    };
}ir_off_raw_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  raw_fifo_rdata:32;
    };
}ir_off_raw_ff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sample_time_cnt:16;
        RBus_UInt32  res1:16;
    };
}ir_off_raw_sample_time_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  raw_fifo_wl:8;
        RBus_UInt32  res1:24;
    };
}ir_off_raw_wl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  irraw_deb_clk:16;
        RBus_UInt32  irraw_deb_len:8;
        RBus_UInt32  res1:8;
    };
}ir_off_raw_deb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  irrawfd:16;
        RBus_UInt32  res1:16;
    };
}ir_off_raw_sf_RBUS;


#endif







#endif //_RBUS_ISO_OFF_REG_H_

