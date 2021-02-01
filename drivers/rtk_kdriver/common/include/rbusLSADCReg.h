/**
* @file rbusMISC_LSADCReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2014-7-11
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_MISC_LSADC_REG_H_
#define _RBUS_MISC_LSADC_REG_H_

#include "rbusTypes.h"



//  MISC_LSADC Register Address



#define  ST_PAD0_VADDR                                      	(0xb8061500)
#define  ST_PAD1_VADDR                                      	(0xb8061504)
#define  ST_PAD2_VADDR                                      	(0xb8061508)
#define  ST_PAD3_VADDR                                      	(0xb806150c)
#define  ST_PAD4_VADDR                                      	(0xb8061510)
#define  ST_PAD5_VADDR                                      	(0xb8061514)
#define  ST_PAD6_VADDR                                      	(0xb8061518)
#define  ST_PAD7_VADDR                                      	(0xb806151c)
#define  ST_LSADC_CTRL_VADDR                                	(0xb8061520)
#define  ST_LSADC_STATUS_VADDR                              	(0xb8061524)
#define  ST_LSADC_ANALOG_CTRL_VADDR                         	(0xb8061528)
#define  ST_LSADC_PERI_TOP_DEBUG_VADDR                      	(0xb806152c)
#define  LSADC_PAD5_LEVEL_SET0_VADDR                        	(0xb8061530)
#define  LSADC_PAD5_LEVEL_SET1_VADDR                        	(0xb8061534)
#define  LSADC_PAD5_LEVEL_SET2_VADDR                        	(0xb8061538)
#define  LSADC_PAD5_LEVEL_SET3_VADDR                        	(0xb806153c)
#define  LSADC_PAD5_LEVEL_SET4_VADDR                        	(0xb8061540)
#define  LSADC_PAD5_LEVEL_SET5_VADDR                        	(0xb8061544)
#define  LSADC_PAD6_LEVEL_SET0_VADDR                        	(0xb8061548)
#define  LSADC_PAD6_LEVEL_SET1_VADDR                        	(0xb806154c)
#define  LSADC_PAD6_LEVEL_SET2_VADDR                        	(0xb8061550)
#define  LSADC_PAD6_LEVEL_SET3_VADDR                        	(0xb8061554)
#define  LSADC_PAD6_LEVEL_SET4_VADDR                        	(0xb8061558)
#define  LSADC_PAD6_LEVEL_SET5_VADDR                        	(0xb806155c)
#define  LSADC_PAD7_LEVEL_SET0_VADDR                        	(0xb8061560)
#define  LSADC_PAD7_LEVEL_SET1_VADDR                        	(0xb8061564)
#define  LSADC_PAD7_LEVEL_SET2_VADDR                        	(0xb8061568)
#define  LSADC_PAD7_LEVEL_SET3_VADDR                        	(0xb806156c)
#define  LSADC_PAD7_LEVEL_SET4_VADDR                        	(0xb8061570)
#define  LSADC_PAD7_LEVEL_SET5_VADDR                        	(0xb8061574)
#define  LSADC_INT_PAD5_VADDR                               	(0xb8061578)
#define  LSADC_INT_PAD6_VADDR                               	(0xb806157c)
#define  LSADC_INT_PAD7_VADDR                               	(0xb8061580)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======MACARTHUR3-DESIGNSPEC-MISC_LSADC register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pad0_active:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  pad0_thred:8;
        RBus_UInt32  pad0_sw:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  pad0_ctrl:1;
        RBus_UInt32  adc_val0:8;
    };
}st_pad0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pad1_active:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  pad1_thred:8;
        RBus_UInt32  pad1_sw:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  pad1_ctrl:1;
        RBus_UInt32  _5_0:8;
    };
}st_pad1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pad2_active:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  pad2_thred:8;
        RBus_UInt32  pad2_sw:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  pad2_ctrl:1;
        RBus_UInt32  adc_val2:8;
    };
}st_pad2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pad3_active:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  pad3_thred:8;
        RBus_UInt32  pad3_sw:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  pad3_ctrl:1;
        RBus_UInt32  adc_val3:8;
    };
}st_pad3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pad4_active:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  pad4_thred:8;
        RBus_UInt32  pad4_sw:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  pad4_ctrl:1;
        RBus_UInt32  adc_val4:8;
    };
}st_pad4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pad5_active:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  pad5_thred:8;
        RBus_UInt32  pad5_sw:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  pad5_ctrl:1;
        RBus_UInt32  adc_val5:8;
    };
}st_pad5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pad6_active:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  pad6_thred:8;
        RBus_UInt32  pad6_sw:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  pad6_ctrl:1;
        RBus_UInt32  adc_val6:8;
    };
}st_pad6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pad7_active:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  pad7_thred:8;
        RBus_UInt32  pad7_sw:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  pad7_ctrl:1;
        RBus_UInt32  adc_val7:8;
    };
}st_pad7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sel_wait:4;
        RBus_UInt32  sel_adc_ck:4;
        RBus_UInt32  debounce_cnt:4;
        RBus_UInt32  res1:4;
        RBus_UInt32  dout_test_in:8;
        RBus_UInt32  res2:6;
        RBus_UInt32  test_en:1;
        RBus_UInt32  enable:1;
    };
}st_lsadc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  irq_en:8;
        RBus_UInt32  pad_cnt:4;
        RBus_UInt32  adc_busy:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  pad_ctrl:5;
        RBus_UInt32  res2:4;
        RBus_UInt32  pad7_status:1;
        RBus_UInt32  pad6_status:1;
        RBus_UInt32  pad5_status:1;
        RBus_UInt32  pad4_status:1;
        RBus_UInt32  pad3_status:1;
        RBus_UInt32  pad2_status:1;
        RBus_UInt32  pad1_status:1;
        RBus_UInt32  pad0_status:1;
    };
}st_lsadc_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  jd_sbias:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  jd_adsbias:2;
        RBus_UInt32  jd_dummy:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  jd_svr:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  jd_adcksel:1;
        RBus_UInt32  res5:3;
        RBus_UInt32  jd_power:1;
    };
}st_lsadc_analog_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  lsadc_2_ifd_data_sel:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:7;
        RBus_UInt32  peri_top_debug:8;
    };
}st_lsadc_peri_top_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  level_0_top_bound:8;
        RBus_UInt32  level_0_low_bound:8;
        RBus_UInt32  block0_en:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  int_en0:1;
        RBus_UInt32  int_pending_bit0:1;
    };
}lsadc_pad5_level_set0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  level_1_top_bound:8;
        RBus_UInt32  level_0_low_bound:8;
        RBus_UInt32  block1_en:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  int_en1:1;
        RBus_UInt32  int_pending_bit1:1;
    };
}lsadc_pad5_level_set1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  level_2_top_bound:8;
        RBus_UInt32  level_2_low_bound:8;
        RBus_UInt32  block2_en:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  int_en2:1;
        RBus_UInt32  int_pending_bit2:1;
    };
}lsadc_pad5_level_set2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  level_3_top_bound:8;
        RBus_UInt32  level_3_low_bound:8;
        RBus_UInt32  block3_en:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  int_en3:1;
        RBus_UInt32  int_pending_bit3:1;
    };
}lsadc_pad5_level_set3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  level_4_top_bound:8;
        RBus_UInt32  level_4_low_bound:8;
        RBus_UInt32  block4_en:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  int_en4:1;
        RBus_UInt32  int_pending_bit4:1;
    };
}lsadc_pad5_level_set4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  level_5_top_bound:8;
        RBus_UInt32  level_5_low_bound:8;
        RBus_UInt32  block5_en:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  int_en5:1;
        RBus_UInt32  int_pending_bit5:1;
    };
}lsadc_pad5_level_set5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  level_0_top_bound:8;
        RBus_UInt32  level_0_low_bound:8;
        RBus_UInt32  block0_en:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  int_en0:1;
        RBus_UInt32  int_pending_bit0:1;
    };
}lsadc_pad6_level_set0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  level_1_top_bound:8;
        RBus_UInt32  level_0_low_bound:8;
        RBus_UInt32  block1_en:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  int_en1:1;
        RBus_UInt32  int_pending_bit1:1;
    };
}lsadc_pad6_level_set1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  level_2_top_bound:8;
        RBus_UInt32  level_2_low_bound:8;
        RBus_UInt32  block2_en:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  int_en2:1;
        RBus_UInt32  int_pending_bit2:1;
    };
}lsadc_pad6_level_set2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  level_3_top_bound:8;
        RBus_UInt32  level_3_low_bound:8;
        RBus_UInt32  block3_en:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  int_en3:1;
        RBus_UInt32  int_pending_bit3:1;
    };
}lsadc_pad6_level_set3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  level_4_top_bound:8;
        RBus_UInt32  level_4_low_bound:8;
        RBus_UInt32  block4_en:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  int_en4:1;
        RBus_UInt32  int_pending_bit4:1;
    };
}lsadc_pad6_level_set4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  level_5_top_bound:8;
        RBus_UInt32  level_5_low_bound:8;
        RBus_UInt32  block5_en:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  int_en5:1;
        RBus_UInt32  int_pending_bit5:1;
    };
}lsadc_pad6_level_set5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  level_0_top_bound:8;
        RBus_UInt32  level_0_low_bound:8;
        RBus_UInt32  block0_en:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  int_en0:1;
        RBus_UInt32  int_pending_bit0:1;
    };
}lsadc_pad7_level_set0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  level_1_top_bound:8;
        RBus_UInt32  level_0_low_bound:8;
        RBus_UInt32  block1_en:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  int_en1:1;
        RBus_UInt32  int_pending_bit1:1;
    };
}lsadc_pad7_level_set1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  level_2_top_bound:8;
        RBus_UInt32  level_2_low_bound:8;
        RBus_UInt32  block2_en:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  int_en2:1;
        RBus_UInt32  int_pending_bit2:1;
    };
}lsadc_pad7_level_set2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  level_3_top_bound:8;
        RBus_UInt32  level_3_low_bound:8;
        RBus_UInt32  block3_en:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  int_en3:1;
        RBus_UInt32  int_pending_bit3:1;
    };
}lsadc_pad7_level_set3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  level_4_top_bound:8;
        RBus_UInt32  level_4_low_bound:8;
        RBus_UInt32  block4_en:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  int_en4:1;
        RBus_UInt32  int_pending_bit4:1;
    };
}lsadc_pad7_level_set4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  level_5_top_bound:8;
        RBus_UInt32  level_5_low_bound:8;
        RBus_UInt32  block5_en:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  int_en5:1;
        RBus_UInt32  int_pending_bit5:1;
    };
}lsadc_pad7_level_set5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  res2:2;
        RBus_UInt32  adc_value5_latch:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  int_latch_set5_status:1;
        RBus_UInt32  int_latch_set4_status:1;
        RBus_UInt32  int_latch_set3_status:1;
        RBus_UInt32  int_latch_set2_status:1;
        RBus_UInt32  int_latch_set1_status:1;
        RBus_UInt32  int_latch_set0_status:1;
    };
}lsadc_int_pad5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  res2:2;
        RBus_UInt32  adc_value6_latch:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  int_latch_set5_status:1;
        RBus_UInt32  int_latch_set4_status:1;
        RBus_UInt32  int_latch_set3_status:1;
        RBus_UInt32  int_latch_set2_status:1;
        RBus_UInt32  int_latch_set1_status:1;
        RBus_UInt32  int_latch_set0_status:1;
    };
}lsadc_int_pad6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  res2:2;
        RBus_UInt32  adc_value7_latch:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  int_latch_set5_status:1;
        RBus_UInt32  int_latch_set4_status:1;
        RBus_UInt32  int_latch_set3_status:1;
        RBus_UInt32  int_latch_set2_status:1;
        RBus_UInt32  int_latch_set1_status:1;
        RBus_UInt32  int_latch_set0_status:1;
    };
}lsadc_int_pad7_RBUS;

#else //apply LITTLE_ENDIAN

//======MACARTHUR3-DESIGNSPEC-MISC_LSADC register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_val0:8;
        RBus_UInt32  pad0_ctrl:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  pad0_sw:4;
        RBus_UInt32  pad0_thred:8;
        RBus_UInt32  res2:7;
        RBus_UInt32  pad0_active:1;
    };
}st_pad0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  _5_0:8;
        RBus_UInt32  pad1_ctrl:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  pad1_sw:4;
        RBus_UInt32  pad1_thred:8;
        RBus_UInt32  res2:7;
        RBus_UInt32  pad1_active:1;
    };
}st_pad1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_val2:8;
        RBus_UInt32  pad2_ctrl:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  pad2_sw:4;
        RBus_UInt32  pad2_thred:8;
        RBus_UInt32  res2:7;
        RBus_UInt32  pad2_active:1;
    };
}st_pad2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_val3:8;
        RBus_UInt32  pad3_ctrl:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  pad3_sw:4;
        RBus_UInt32  pad3_thred:8;
        RBus_UInt32  res2:7;
        RBus_UInt32  pad3_active:1;
    };
}st_pad3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_val4:8;
        RBus_UInt32  pad4_ctrl:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  pad4_sw:4;
        RBus_UInt32  pad4_thred:8;
        RBus_UInt32  res2:7;
        RBus_UInt32  pad4_active:1;
    };
}st_pad4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_val5:8;
        RBus_UInt32  pad5_ctrl:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  pad5_sw:4;
        RBus_UInt32  pad5_thred:8;
        RBus_UInt32  res2:7;
        RBus_UInt32  pad5_active:1;
    };
}st_pad5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_val6:8;
        RBus_UInt32  pad6_ctrl:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  pad6_sw:4;
        RBus_UInt32  pad6_thred:8;
        RBus_UInt32  res2:7;
        RBus_UInt32  pad6_active:1;
    };
}st_pad6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_val7:8;
        RBus_UInt32  pad7_ctrl:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  pad7_sw:4;
        RBus_UInt32  pad7_thred:8;
        RBus_UInt32  res2:7;
        RBus_UInt32  pad7_active:1;
    };
}st_pad7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  enable:1;
        RBus_UInt32  test_en:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  dout_test_in:8;
        RBus_UInt32  res2:4;
        RBus_UInt32  debounce_cnt:4;
        RBus_UInt32  sel_adc_ck:4;
        RBus_UInt32  sel_wait:4;
    };
}st_lsadc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pad0_status:1;
        RBus_UInt32  pad1_status:1;
        RBus_UInt32  pad2_status:1;
        RBus_UInt32  pad3_status:1;
        RBus_UInt32  pad4_status:1;
        RBus_UInt32  pad5_status:1;
        RBus_UInt32  pad6_status:1;
        RBus_UInt32  pad7_status:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  pad_ctrl:5;
        RBus_UInt32  res2:2;
        RBus_UInt32  adc_busy:1;
        RBus_UInt32  pad_cnt:4;
        RBus_UInt32  irq_en:8;
    };
}st_lsadc_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  jd_power:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  jd_adcksel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  jd_svr:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  jd_dummy:2;
        RBus_UInt32  jd_adsbias:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  jd_sbias:2;
        RBus_UInt32  res5:14;
    };
}st_lsadc_analog_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  peri_top_debug:8;
        RBus_UInt32  res1:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  lsadc_2_ifd_data_sel:3;
        RBus_UInt32  res3:13;
    };
}st_lsadc_peri_top_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_pending_bit0:1;
        RBus_UInt32  int_en0:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  block0_en:1;
        RBus_UInt32  level_0_low_bound:8;
        RBus_UInt32  level_0_top_bound:8;
    };
}lsadc_pad5_level_set0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_pending_bit1:1;
        RBus_UInt32  int_en1:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  block1_en:1;
        RBus_UInt32  level_0_low_bound:8;
        RBus_UInt32  level_1_top_bound:8;
    };
}lsadc_pad5_level_set1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_pending_bit2:1;
        RBus_UInt32  int_en2:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  block2_en:1;
        RBus_UInt32  level_2_low_bound:8;
        RBus_UInt32  level_2_top_bound:8;
    };
}lsadc_pad5_level_set2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_pending_bit3:1;
        RBus_UInt32  int_en3:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  block3_en:1;
        RBus_UInt32  level_3_low_bound:8;
        RBus_UInt32  level_3_top_bound:8;
    };
}lsadc_pad5_level_set3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_pending_bit4:1;
        RBus_UInt32  int_en4:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  block4_en:1;
        RBus_UInt32  level_4_low_bound:8;
        RBus_UInt32  level_4_top_bound:8;
    };
}lsadc_pad5_level_set4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_pending_bit5:1;
        RBus_UInt32  int_en5:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  block5_en:1;
        RBus_UInt32  level_5_low_bound:8;
        RBus_UInt32  level_5_top_bound:8;
    };
}lsadc_pad5_level_set5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_pending_bit0:1;
        RBus_UInt32  int_en0:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  block0_en:1;
        RBus_UInt32  level_0_low_bound:8;
        RBus_UInt32  level_0_top_bound:8;
    };
}lsadc_pad6_level_set0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_pending_bit1:1;
        RBus_UInt32  int_en1:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  block1_en:1;
        RBus_UInt32  level_0_low_bound:8;
        RBus_UInt32  level_1_top_bound:8;
    };
}lsadc_pad6_level_set1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_pending_bit2:1;
        RBus_UInt32  int_en2:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  block2_en:1;
        RBus_UInt32  level_2_low_bound:8;
        RBus_UInt32  level_2_top_bound:8;
    };
}lsadc_pad6_level_set2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_pending_bit3:1;
        RBus_UInt32  int_en3:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  block3_en:1;
        RBus_UInt32  level_3_low_bound:8;
        RBus_UInt32  level_3_top_bound:8;
    };
}lsadc_pad6_level_set3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_pending_bit4:1;
        RBus_UInt32  int_en4:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  block4_en:1;
        RBus_UInt32  level_4_low_bound:8;
        RBus_UInt32  level_4_top_bound:8;
    };
}lsadc_pad6_level_set4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_pending_bit5:1;
        RBus_UInt32  int_en5:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  block5_en:1;
        RBus_UInt32  level_5_low_bound:8;
        RBus_UInt32  level_5_top_bound:8;
    };
}lsadc_pad6_level_set5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_pending_bit0:1;
        RBus_UInt32  int_en0:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  block0_en:1;
        RBus_UInt32  level_0_low_bound:8;
        RBus_UInt32  level_0_top_bound:8;
    };
}lsadc_pad7_level_set0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_pending_bit1:1;
        RBus_UInt32  int_en1:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  block1_en:1;
        RBus_UInt32  level_0_low_bound:8;
        RBus_UInt32  level_1_top_bound:8;
    };
}lsadc_pad7_level_set1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_pending_bit2:1;
        RBus_UInt32  int_en2:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  block2_en:1;
        RBus_UInt32  level_2_low_bound:8;
        RBus_UInt32  level_2_top_bound:8;
    };
}lsadc_pad7_level_set2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_pending_bit3:1;
        RBus_UInt32  int_en3:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  block3_en:1;
        RBus_UInt32  level_3_low_bound:8;
        RBus_UInt32  level_3_top_bound:8;
    };
}lsadc_pad7_level_set3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_pending_bit4:1;
        RBus_UInt32  int_en4:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  block4_en:1;
        RBus_UInt32  level_4_low_bound:8;
        RBus_UInt32  level_4_top_bound:8;
    };
}lsadc_pad7_level_set4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_pending_bit5:1;
        RBus_UInt32  int_en5:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  block5_en:1;
        RBus_UInt32  level_5_low_bound:8;
        RBus_UInt32  level_5_top_bound:8;
    };
}lsadc_pad7_level_set5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_latch_set0_status:1;
        RBus_UInt32  int_latch_set1_status:1;
        RBus_UInt32  int_latch_set2_status:1;
        RBus_UInt32  int_latch_set3_status:1;
        RBus_UInt32  int_latch_set4_status:1;
        RBus_UInt32  int_latch_set5_status:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  adc_value5_latch:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  res3:16;
    };
}lsadc_int_pad5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_latch_set0_status:1;
        RBus_UInt32  int_latch_set1_status:1;
        RBus_UInt32  int_latch_set2_status:1;
        RBus_UInt32  int_latch_set3_status:1;
        RBus_UInt32  int_latch_set4_status:1;
        RBus_UInt32  int_latch_set5_status:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  adc_value6_latch:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  res3:16;
    };
}lsadc_int_pad6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_latch_set0_status:1;
        RBus_UInt32  int_latch_set1_status:1;
        RBus_UInt32  int_latch_set2_status:1;
        RBus_UInt32  int_latch_set3_status:1;
        RBus_UInt32  int_latch_set4_status:1;
        RBus_UInt32  int_latch_set5_status:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  adc_value7_latch:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  res3:16;
    };
}lsadc_int_pad7_RBUS;




#endif 


#endif 
