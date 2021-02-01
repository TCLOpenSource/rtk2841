/**
* @file rbusBridgeReg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2007/7/5
* @version 1.1
* @ingroup model_rbus
*
*/

#ifndef _RBUS_BRIDGE_REG_H_
#define _RBUS_BRIDGE_REG_H_

#include "rbus/rbusTypes.h"




// BRIDGE Register Address
#define BRIDGE_SB3_ARB_CR_ADDR                   (0x1801d100)
#define BRIDGE_SB3_LATCNT_CR1_ADDR               (0x1801d110)
#define BRIDGE_SB3_LATCNT_CR2_ADDR               (0x1801d114)
#define BRIDGE_SB3_LATCNT_CR3_ADDR               (0x1801d118)
#define BRIDGE_SB3_LATCNT_CR4_ADDR               (0x1801d11c)
#define BRIDGE_SB3_LATCNT_CR5_ADDR               (0x1801d120)
#define BRIDGE_SB3_LATCNT_CR6_ADDR               (0x1801d124)
#define BRIDGE_SB3_LATCNT_CR7_ADDR               (0x1801d128)
#define BRIDGE_SB3_LATCNT_CR8_ADDR               (0x1801d12c)
#define BRIDGE_SB3_LATCNT_CR9_ADDR               (0x1801d130)
#define BRIDGE_SB3_WDRR_CR1_ADDR                 (0x1801d140)
#define BRIDGE_SB3_WDRR_CR2_ADDR                 (0x1801d144)
#define BRIDGE_SB3_WDRR_CR3_ADDR                 (0x1801d148)
#define BRIDGE_SB3_WDRR_CR4_ADDR                 (0x1801d14c)
#define BRIDGE_SB3_WDRR_CR5_ADDR                 (0x1801d150)
#define BRIDGE_SB3_WDRR_CR6_ADDR                 (0x1801d154)
#define BRIDGE_SB3_WDRR_CR7_ADDR                 (0x1801d158)
#define BRIDGE_SB3_WDRR_CR8_ADDR                 (0x1801d15c)
#define BRIDGE_SB3_WDRR_CR9_ADDR                 (0x1801d160)
#define BRIDGE_SB3_ARB_CNTR_SET1_ADDR            (0x1801d170)
#define BRIDGE_SB3_ARB_CNTR_SET2_ADDR            (0x1801d174)
#define BRIDGE_SB3_ARB_CNTR_SET3_ADDR            (0x1801d178)
#define BRIDGE_SB3_ARB_CNTR_SET4_ADDR            (0x1801d17c)
#define BRIDGE_SB3_ARB_CNTR_SET5_ADDR            (0x1801d180)
#define BRIDGE_SB3_ARB_CNTR_SET6_ADDR            (0x1801d184)
#define BRIDGE_SB3_ARB_CNTR_SET7_ADDR            (0x1801d188)
#define BRIDGE_SB3_ARB_CNTR_SET8_ADDR            (0x1801d18c)
#define BRIDGE_SB3_ARB_CNTR_SET9_ADDR            (0x1801d190)
#define BRIDGE_SB3_REQ_CR_ADDR                   (0x1801d1a0)
#define BRIDGE_SB3_ARB_SR1_ADDR                  (0x1801d1b0)
#define BRIDGE_SB3_ARB_SR2_ADDR                  (0x1801d1b4)

#define BRIDGE_SB3_ARB_CR_VADDR                  (0xb801d100)
#define BRIDGE_SB3_LATCNT_CR1_VADDR              (0xb801d110)
#define BRIDGE_SB3_LATCNT_CR2_VADDR              (0xb801d114)
#define BRIDGE_SB3_LATCNT_CR3_VADDR              (0xb801d118)
#define BRIDGE_SB3_LATCNT_CR4_VADDR              (0xb801d11c)
#define BRIDGE_SB3_LATCNT_CR5_VADDR              (0xb801d120)
#define BRIDGE_SB3_LATCNT_CR6_VADDR              (0xb801d124)
#define BRIDGE_SB3_LATCNT_CR7_VADDR              (0xb801d128)
#define BRIDGE_SB3_LATCNT_CR8_VADDR              (0xb801d12c)
#define BRIDGE_SB3_LATCNT_CR9_VADDR              (0xb801d130)
#define BRIDGE_SB3_WDRR_CR1_VADDR                (0xb801d140)
#define BRIDGE_SB3_WDRR_CR2_VADDR                (0xb801d144)
#define BRIDGE_SB3_WDRR_CR3_VADDR                (0xb801d148)
#define BRIDGE_SB3_WDRR_CR4_VADDR                (0xb801d14c)
#define BRIDGE_SB3_WDRR_CR5_VADDR                (0xb801d150)
#define BRIDGE_SB3_WDRR_CR6_VADDR                (0xb801d154)
#define BRIDGE_SB3_WDRR_CR7_VADDR                (0xb801d158)
#define BRIDGE_SB3_WDRR_CR8_VADDR                (0xb801d15c)
#define BRIDGE_SB3_WDRR_CR9_VADDR                (0xb801d160)
#define BRIDGE_SB3_ARB_CNTR_SET1_VADDR           (0xb801d170)
#define BRIDGE_SB3_ARB_CNTR_SET2_VADDR           (0xb801d174)
#define BRIDGE_SB3_ARB_CNTR_SET3_VADDR           (0xb801d178)
#define BRIDGE_SB3_ARB_CNTR_SET4_VADDR           (0xb801d17c)
#define BRIDGE_SB3_ARB_CNTR_SET5_VADDR           (0xb801d180)
#define BRIDGE_SB3_ARB_CNTR_SET6_VADDR           (0xb801d184)
#define BRIDGE_SB3_ARB_CNTR_SET7_VADDR           (0xb801d188)
#define BRIDGE_SB3_ARB_CNTR_SET8_VADDR           (0xb801d18c)
#define BRIDGE_SB3_ARB_CNTR_SET9_VADDR           (0xb801d190)
#define BRIDGE_SB3_REQ_CR_VADDR                  (0xb801d1a0)
#define BRIDGE_SB3_ARB_SR1_VADDR                 (0xb801d1b0)
#define BRIDGE_SB3_ARB_SR2_VADDR                 (0xb801d1b4)




#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======BRIDGE register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dec_mode:1;
        RBus_UInt32  res1:12;
        RBus_UInt32  cnt_src_sel:3;
        RBus_UInt32  time_step:4;
        RBus_UInt32  res2:9;
        RBus_UInt32  arb_en:3;
    };
}sb0_arb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  vdec_latcnt_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  vdec_latcnt_beg:12;
    };
}sb0_latcnt_cr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  vbi_latcnt_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  vbi_latcnt_beg:12;
    };
}sb0_latcnt_cr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  vi_latcnt_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  vi_latcnt_beg:12;
    };
}sb0_latcnt_cr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  vdec_credit_val:12;
        RBus_UInt32  vdec_deficit_val:8;
        RBus_UInt32  vdec_elapse_val:8;
    };
}sb0_wdrr_cr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  vbi_credit_val:12;
        RBus_UInt32  vbi_deficit_val:8;
        RBus_UInt32  vbi_elapse_val:8;
    };
}sb0_wdrr_cr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  vi_credit_val:12;
        RBus_UInt32  vi_deficit_val:8;
        RBus_UInt32  vi_elapse_val:8;
    };
}sb0_wdrr_cr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vdec_cntr_val_set:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  vdec_cntr_val:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  vdec_low_lvl_val:12;
    };
}sb0_arb_cntr_set1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vbi_cntr_val_set:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  vbi_cntr_val:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  vbi_low_lvl_val:12;
    };
}sb0_arb_cntr_set2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vi_cntr_val_set:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  vi_cntr_val:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  vi_low_lvl_val:12;
    };
}sb0_arb_cntr_set3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  max_count:4;
        RBus_UInt32  res2:8;
        RBus_UInt32  off_time:8;
    };
}sb0_req_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  win_latcnt:12;
    };
}sb0_arb_sr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  low_lvl_ie:3;
        RBus_UInt32  res2:13;
        RBus_UInt32  low_lvl_ip:3;
    };
}sb0_arb_sr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dec_mode:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  cnt_src_sel:9;
        RBus_UInt32  time_step:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  arb_en:9;
    };
}sb3_arb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  xcdim_latcnt_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  xcdim_latcnt_beg:12;
    };
}sb3_latcnt_cr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  gdmaosd_latcnt_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  gdmaosd_latcnt_beg:12;
    };
}sb3_latcnt_cr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  disdisps_latcnt_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  disdisps_latcnt_beg:12;
    };
}sb3_latcnt_cr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  discaps_latcnt_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  discaps_latcnt_beg:12;
    };
}sb3_latcnt_cr4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  vo_latcnt_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  vo_latcnt_beg:12;
    };
}sb3_latcnt_cr5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  gdmasub1_latcnt_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  gdmasub1_latcnt_beg:12;
    };
}sb3_latcnt_cr6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  gibi_latcnt_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  gibi_latcnt_beg:12;
    };
}sb3_latcnt_cr7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  memc_latcnt_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  memc_latcnt_beg:12;
    };
}sb3_latcnt_cr8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  gdmasub2_latcnt_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  gdmasub2_latcnt_beg:12;
    };
}sb3_latcnt_cr9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  xcdim_credit_val:12;
        RBus_UInt32  xcdim_deficit_val:8;
        RBus_UInt32  xcdim_elapse_val:8;
    };
}sb3_wdrr_cr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  gdmaosd_credit_val:12;
        RBus_UInt32  gdmaosd_deficit_val:8;
        RBus_UInt32  gdmaosd_elapse_val:8;
    };
}sb3_wdrr_cr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  disdisps_credit_val:12;
        RBus_UInt32  disdisps_deficit_val:8;
        RBus_UInt32  disdisps_elapse_val:8;
    };
}sb3_wdrr_cr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  discaps_credit_val:12;
        RBus_UInt32  discaps_deficit_val:8;
        RBus_UInt32  discaps_elapse_val:8;
    };
}sb3_wdrr_cr4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  vo_credit_val:12;
        RBus_UInt32  vo_deficit_val:8;
        RBus_UInt32  vo_elapse_val:8;
    };
}sb3_wdrr_cr5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  gdmasub1_credit_val:12;
        RBus_UInt32  gdmasub1_deficit_val:8;
        RBus_UInt32  gdmasub1_elapse_val:8;
    };
}sb3_wdrr_cr6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  gibi_credit_val:12;
        RBus_UInt32  gibi_deficit_val:8;
        RBus_UInt32  gibi_elapse_val:8;
    };
}sb3_wdrr_cr7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  memc_credit_val:12;
        RBus_UInt32  memc_deficit_val:8;
        RBus_UInt32  memc_elapse_val:8;
    };
}sb3_wdrr_cr8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  gdmasub2_credit_val:12;
        RBus_UInt32  gdmasub1_deficit_val:8;
        RBus_UInt32  gdmasub2_elapse_val:8;
    };
}sb3_wdrr_cr9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  xcdim_cntr_val_set:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  xcdim_cntr_val:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  xcdim_low_lvl_val:12;
    };
}sb3_arb_cntr_set1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gdmaosd_cntr_val_set:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  gdmaosd_cntr_val:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  gdmaosd_low_lvl_val:12;
    };
}sb3_arb_cntr_set2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disdisps_cntr_val_set:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  disdisps_cntr_val:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  disdisps_low_lvl_val:12;
    };
}sb3_arb_cntr_set3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  discaps_cntr_val_set:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  discaps_cntr_val:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  discaps_low_lvl_val:12;
    };
}sb3_arb_cntr_set4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vo_cntr_val_set:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  vo_cntr_val:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  vo_low_lvl_val:12;
    };
}sb3_arb_cntr_set5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gdmasub1_cntr_val_set:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  gdmasub1_cntr_val:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  gdmasub1_low_lvl_val:12;
    };
}sb3_arb_cntr_set6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gibi_cntr_val_set:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  gibi_cntr_val:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  gibi_low_lvl_val:12;
    };
}sb3_arb_cntr_set7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  memc_cntr_val_set:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  memc_cntr_val:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  memc_low_lvl_val:12;
    };
}sb3_arb_cntr_set8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gdmasub2_cntr_val_set:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  gdmasub2_cntr_val:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  gdmasub2_low_lvl_val:12;
    };
}sb3_arb_cntr_set9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  max_count:4;
        RBus_UInt32  res2:8;
        RBus_UInt32  off_time:8;
    };
}sb3_req_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  win_latcnt:12;
    };
}sb3_arb_sr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  low_lvl_ie:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  low_lvl_ip:9;
    };
}sb3_arb_sr2_RBUS;





#else //apply LITTLE_ENDIAN


//======BRIDGE register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  arb_en:3;
        RBus_UInt32  res2:9;
        RBus_UInt32  time_step:4;
        RBus_UInt32  cnt_src_sel:3;
        RBus_UInt32  res1:12;
        RBus_UInt32  dec_mode:1;
    };
}sb0_arb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vdec_latcnt_beg:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  vdec_latcnt_end:12;
        RBus_UInt32  res1:4;
    };
}sb0_latcnt_cr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vbi_latcnt_beg:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  vbi_latcnt_end:12;
        RBus_UInt32  res1:4;
    };
}sb0_latcnt_cr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vi_latcnt_beg:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  vi_latcnt_end:12;
        RBus_UInt32  res1:4;
    };
}sb0_latcnt_cr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vdec_elapse_val:8;
        RBus_UInt32  vdec_deficit_val:8;
        RBus_UInt32  vdec_credit_val:12;
        RBus_UInt32  res1:4;
    };
}sb0_wdrr_cr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vbi_elapse_val:8;
        RBus_UInt32  vbi_deficit_val:8;
        RBus_UInt32  vbi_credit_val:12;
        RBus_UInt32  res1:4;
    };
}sb0_wdrr_cr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vi_elapse_val:8;
        RBus_UInt32  vi_deficit_val:8;
        RBus_UInt32  vi_credit_val:12;
        RBus_UInt32  res1:4;
    };
}sb0_wdrr_cr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vdec_low_lvl_val:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  vdec_cntr_val:12;
        RBus_UInt32  res1:3;
        RBus_UInt32  vdec_cntr_val_set:1;
    };
}sb0_arb_cntr_set1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vbi_low_lvl_val:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  vbi_cntr_val:12;
        RBus_UInt32  res1:3;
        RBus_UInt32  vbi_cntr_val_set:1;
    };
}sb0_arb_cntr_set2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vi_low_lvl_val:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  vi_cntr_val:12;
        RBus_UInt32  res1:3;
        RBus_UInt32  vi_cntr_val_set:1;
    };
}sb0_arb_cntr_set3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  off_time:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  max_count:4;
        RBus_UInt32  res1:12;
    };
}sb0_req_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  win_latcnt:12;
        RBus_UInt32  res1:20;
    };
}sb0_arb_sr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  low_lvl_ip:3;
        RBus_UInt32  res2:13;
        RBus_UInt32  low_lvl_ie:3;
        RBus_UInt32  res1:13;
    };
}sb0_arb_sr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  arb_en:9;
        RBus_UInt32  res2:3;
        RBus_UInt32  time_step:4;
        RBus_UInt32  cnt_src_sel:9;
        RBus_UInt32  res1:6;
        RBus_UInt32  dec_mode:1;
    };
}sb3_arb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  xcdim_latcnt_beg:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  xcdim_latcnt_end:12;
        RBus_UInt32  res1:4;
    };
}sb3_latcnt_cr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gdmaosd_latcnt_beg:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  gdmaosd_latcnt_end:12;
        RBus_UInt32  res1:4;
    };
}sb3_latcnt_cr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disdisps_latcnt_beg:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  disdisps_latcnt_end:12;
        RBus_UInt32  res1:4;
    };
}sb3_latcnt_cr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  discaps_latcnt_beg:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  discaps_latcnt_end:12;
        RBus_UInt32  res1:4;
    };
}sb3_latcnt_cr4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vo_latcnt_beg:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  vo_latcnt_end:12;
        RBus_UInt32  res1:4;
    };
}sb3_latcnt_cr5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gdmasub1_latcnt_beg:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  gdmasub1_latcnt_end:12;
        RBus_UInt32  res1:4;
    };
}sb3_latcnt_cr6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gibi_latcnt_beg:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  gibi_latcnt_end:12;
        RBus_UInt32  res1:4;
    };
}sb3_latcnt_cr7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  memc_latcnt_beg:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  memc_latcnt_end:12;
        RBus_UInt32  res1:4;
    };
}sb3_latcnt_cr8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gdmasub2_latcnt_beg:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  gdmasub2_latcnt_end:12;
        RBus_UInt32  res1:4;
    };
}sb3_latcnt_cr9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  xcdim_elapse_val:8;
        RBus_UInt32  xcdim_deficit_val:8;
        RBus_UInt32  xcdim_credit_val:12;
        RBus_UInt32  res1:4;
    };
}sb3_wdrr_cr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gdmaosd_elapse_val:8;
        RBus_UInt32  gdmaosd_deficit_val:8;
        RBus_UInt32  gdmaosd_credit_val:12;
        RBus_UInt32  res1:4;
    };
}sb3_wdrr_cr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disdisps_elapse_val:8;
        RBus_UInt32  disdisps_deficit_val:8;
        RBus_UInt32  disdisps_credit_val:12;
        RBus_UInt32  res1:4;
    };
}sb3_wdrr_cr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  discaps_elapse_val:8;
        RBus_UInt32  discaps_deficit_val:8;
        RBus_UInt32  discaps_credit_val:12;
        RBus_UInt32  res1:4;
    };
}sb3_wdrr_cr4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vo_elapse_val:8;
        RBus_UInt32  vo_deficit_val:8;
        RBus_UInt32  vo_credit_val:12;
        RBus_UInt32  res1:4;
    };
}sb3_wdrr_cr5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gdmasub1_elapse_val:8;
        RBus_UInt32  gdmasub1_deficit_val:8;
        RBus_UInt32  gdmasub1_credit_val:12;
        RBus_UInt32  res1:4;
    };
}sb3_wdrr_cr6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gibi_elapse_val:8;
        RBus_UInt32  gibi_deficit_val:8;
        RBus_UInt32  gibi_credit_val:12;
        RBus_UInt32  res1:4;
    };
}sb3_wdrr_cr7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  memc_elapse_val:8;
        RBus_UInt32  memc_deficit_val:8;
        RBus_UInt32  memc_credit_val:12;
        RBus_UInt32  res1:4;
    };
}sb3_wdrr_cr8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gdmasub2_elapse_val:8;
        RBus_UInt32  gdmasub1_deficit_val:8;
        RBus_UInt32  gdmasub2_credit_val:12;
        RBus_UInt32  res1:4;
    };
}sb3_wdrr_cr9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  xcdim_low_lvl_val:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  xcdim_cntr_val:12;
        RBus_UInt32  res1:3;
        RBus_UInt32  xcdim_cntr_val_set:1;
    };
}sb3_arb_cntr_set1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gdmaosd_low_lvl_val:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  gdmaosd_cntr_val:12;
        RBus_UInt32  res1:3;
        RBus_UInt32  gdmaosd_cntr_val_set:1;
    };
}sb3_arb_cntr_set2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disdisps_low_lvl_val:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  disdisps_cntr_val:12;
        RBus_UInt32  res1:3;
        RBus_UInt32  disdisps_cntr_val_set:1;
    };
}sb3_arb_cntr_set3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  discaps_low_lvl_val:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  discaps_cntr_val:12;
        RBus_UInt32  res1:3;
        RBus_UInt32  discaps_cntr_val_set:1;
    };
}sb3_arb_cntr_set4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vo_low_lvl_val:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  vo_cntr_val:12;
        RBus_UInt32  res1:3;
        RBus_UInt32  vo_cntr_val_set:1;
    };
}sb3_arb_cntr_set5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gdmasub1_low_lvl_val:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  gdmasub1_cntr_val:12;
        RBus_UInt32  res1:3;
        RBus_UInt32  gdmasub1_cntr_val_set:1;
    };
}sb3_arb_cntr_set6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gibi_low_lvl_val:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  gibi_cntr_val:12;
        RBus_UInt32  res1:3;
        RBus_UInt32  gibi_cntr_val_set:1;
    };
}sb3_arb_cntr_set7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  memc_low_lvl_val:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  memc_cntr_val:12;
        RBus_UInt32  res1:3;
        RBus_UInt32  memc_cntr_val_set:1;
    };
}sb3_arb_cntr_set8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gdmasub2_low_lvl_val:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  gdmasub2_cntr_val:12;
        RBus_UInt32  res1:3;
        RBus_UInt32  gdmasub2_cntr_val_set:1;
    };
}sb3_arb_cntr_set9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  off_time:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  max_count:4;
        RBus_UInt32  res1:12;
    };
}sb3_req_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  win_latcnt:12;
        RBus_UInt32  res1:20;
    };
}sb3_arb_sr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  low_lvl_ip:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  low_lvl_ie:9;
        RBus_UInt32  res1:7;
    };
}sb3_arb_sr2_RBUS;


#endif







#endif //_RBUS_BRIDGE_REG_H_

