/**
* @file rbusRptgReg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2008/9/18
* @version 1.1
* @ingroup model_rbus
*
*/

#ifndef _RBUS_RPTG_REG_H_
#define _RBUS_RPTG_REG_H_




// RPTG Register Address
#define RPTG_RPTG_CR_ADDR                          (0x18005000)
#define RPTG_RPTG_TG0_ADDR                         (0x18005010)
#define RPTG_RPTG_TG1_ADDR                         (0x18005014)
#define RPTG_RPTG_TG2_ADDR                         (0x18005018)
#define RPTG_RPTG_TG3_ADDR                         (0x1800501c)
#define RPTG_RPTG_TG4_ADDR                         (0x18005020)
#define RPTG_RPTG_PIXELBUF_ADDR                    (0x18005030)

#define RPTG_RPTG_CR_VADDR                         (0xb8005000)
#define RPTG_RPTG_TG0_VADDR                        (0xb8005010)
#define RPTG_RPTG_TG1_VADDR                        (0xb8005014)
#define RPTG_RPTG_TG2_VADDR                        (0xb8005018)
#define RPTG_RPTG_TG3_VADDR                        (0xb800501c)
#define RPTG_RPTG_TG4_VADDR                        (0xb8005020)
#define RPTG_RPTG_PIXELBUF_VADDR                   (0xb8005030)




#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======RPTG register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  full:1;
        RBus_UInt32  empty:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  ovflow:1;
        RBus_UInt32  entde:1;
        RBus_UInt32  irq_en:1;
        RBus_UInt32  res3:10;
        RBus_UInt32  vs_polarity:1;
        RBus_UInt32  hs_polarity:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  rptg_en:1;
    };
}rptg_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  vs_width:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  hs_width:12;
    };
}rptg_tg0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vs_vstr:8;
        RBus_UInt32  vs_hstr:12;
        RBus_UInt32  hs_hstr:12;
    };
}rptg_tg1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  de_hbph:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  de_hfph:12;
    };
}rptg_tg2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  de_vbph:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  de_vfph:12;
    };
}rptg_tg3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  de_height:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  de_width:12;
    };
}rptg_tg4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pixel_wr_en:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  pixel_in:24;
    };
}rptg_pixelbuf_RBUS;





#else //apply LITTLE_ENDIAN


//======RPTG register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rptg_en:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  hs_polarity:1;
        RBus_UInt32  vs_polarity:1;
        RBus_UInt32  res3:10;
        RBus_UInt32  irq_en:1;
        RBus_UInt32  entde:1;
        RBus_UInt32  ovflow:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  empty:1;
        RBus_UInt32  full:1;
        RBus_UInt32  res1:10;
    };
}rptg_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hs_width:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  vs_width:12;
        RBus_UInt32  res1:4;
    };
}rptg_tg0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hs_hstr:12;
        RBus_UInt32  vs_hstr:12;
        RBus_UInt32  vs_vstr:8;
    };
}rptg_tg1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  de_hfph:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  de_hbph:12;
        RBus_UInt32  res1:4;
    };
}rptg_tg2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  de_vfph:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  de_vbph:12;
        RBus_UInt32  res1:4;
    };
}rptg_tg3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  de_width:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  de_height:12;
        RBus_UInt32  res1:4;
    };
}rptg_tg4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pixel_in:24;
        RBus_UInt32  res1:7;
        RBus_UInt32  pixel_wr_en:1;
    };
}rptg_pixelbuf_RBUS;


#endif







#endif //_RBUS_RPTG_REG_H_

