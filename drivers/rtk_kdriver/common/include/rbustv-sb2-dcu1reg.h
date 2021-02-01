/**
* @file rbusTV-SB2-DCU1Reg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2014-7-11
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUSTV_SB2_DCU1_REG_H_
#define _RBUSTV_SB2_DCU1_REG_H_

#include "rbusTypes.h"



//  TV-SB2-DCU1 Register Address



#define  BUS_TV_SB2_DCU1_ARB_CR0_VADDR                     	(0xb801c500)
#define  BUS_TV_SB2_DCU1_ARB_CR1_VADDR                     	(0xb801c504)
#define  BUS_TV_SB2_DCU1_LATCNT_CR1_VADDR                  	(0xb801c508)
#define  BUS_TV_SB2_DCU1_LATCNT_CR2_VADDR                  	(0xb801c50c)
#define  BUS_TV_SB2_DCU1_LATCNT_CR3_VADDR                  	(0xb801c510)
#define  BUS_TV_SB2_DCU1_LATCNT_CR4_VADDR                  	(0xb801c514)
#define  BUS_TV_SB2_DCU1_LATCNT_CR5_VADDR                  	(0xb801c518)
#define  BUS_TV_SB2_DCU1_LATCNT_CR6_VADDR                  	(0xb801c51c)
#define  BUS_TV_SB2_DCU1_LATCNT_CR7_VADDR                  	(0xb801c520)
#define  BUS_TV_SB2_DCU1_LATCNT_CR8_VADDR                  	(0xb801c524)
#define  BUS_TV_SB2_DCU1_LATCNT_CR9_VADDR                  	(0xb801c528)
#define  BUS_TV_SB2_DCU1_LATCNT_CR10_VADDR                 	(0xb801c52c)
#define  BUS_TV_SB2_DCU1_LATCNT_CR11_VADDR                 	(0xb801c530)
#define  BUS_TV_SB2_DCU1_LATCNT_CR12_VADDR                 	(0xb801c534)
#define  BUS_TV_SB2_DCU1_PC_CTRL_VADDR                     	(0xb801c550)
#define  BUS_TV_SB2_DCU1_PC_TOTA_MON_NUM_VADDR             	(0xb801c554)
#define  BUS_TV_SB2_DCU1_PC_TOTA_ACK_NUM_VADDR             	(0xb801c558)
#define  BUS_TV_SB2_DCU1_PC_TOTA_IDL_NUM_VADDR             	(0xb801c55c)
#define  BUS_TV_SB2_DCU1_PC_PROG_CTRL1_VADDR               	(0xb801c560)
#define  BUS_TV_SB2_DCU1_PC_PROG_CTRL2_VADDR               	(0xb801c564)
#define  BUS_TV_SB2_DCU1_PC_PROG_0_CHANNEL_SEL_VADDR       	(0xb801c568)
#define  BUS_TV_SB2_DCU1_PC_PROG_0_ACC_LAT_VADDR           	(0xb801c56c)
#define  BUS_TV_SB2_DCU1_PC_PROG_0_MAX_LAT_VADDR           	(0xb801c570)
#define  BUS_TV_SB2_DCU1_PC_PROG_0_REQ_NUM_VADDR           	(0xb801c574)
#define  BUS_TV_SB2_DCU1_PC_PROG_0_ACK_NUM_VADDR           	(0xb801c578)
#define  BUS_TV_SB2_DCU1_PC_PROG_0_HITEND_VADDR            	(0xb801c57c)
#define  BUS_TV_SB2_DCU1_ARB_CNTR_SET1_VADDR               	(0xb801c580)
#define  BUS_TV_SB2_DCU1_ARB_CNTR_SET2_VADDR               	(0xb801c584)
#define  BUS_TV_SB2_DCU1_ARB_CNTR_SET3_VADDR               	(0xb801c588)
#define  BUS_TV_SB2_DCU1_ARB_CNTR_SET4_VADDR               	(0xb801c58c)
#define  BUS_TV_SB2_DCU1_ARB_CNTR_SET5_VADDR               	(0xb801c590)
#define  BUS_TV_SB2_DCU1_ARB_CNTR_SET6_VADDR               	(0xb801c594)
#define  BUS_TV_SB2_DCU1_ARB_CNTR_SET7_VADDR               	(0xb801c598)
#define  BUS_TV_SB2_DCU1_ARB_CNTR_SET8_VADDR               	(0xb801c59c)
#define  BUS_TV_SB2_DCU1_ARB_CNTR_SET9_VADDR               	(0xb801c5a0)
#define  BUS_TV_SB2_DCU1_ARB_CNTR_SET10_VADDR              	(0xb801c5a4)
#define  BUS_TV_SB2_DCU1_ARB_CNTR_SET11_VADDR              	(0xb801c5a8)
#define  BUS_TV_SB2_DCU1_ARB_CNTR_SET12_VADDR              	(0xb801c5ac)
#define  BUS_TV_SB2_DCU1_ARB_SR0_VADDR                     	(0xb801c5c8)
#define  BUS_TV_SB2_DCU1_ARB_SR1_VADDR                     	(0xb801c5cc)
#define  BUS_TV_SB2_DCU1_ARB_SR2_VADDR                     	(0xb801c5d0)
#define  BUS_TV_SB2_DCU1_LOW_LATCNT_CR1_VADDR              	(0xb801c5d4)
#define  BUS_TV_SB2_DCU1_LOW_LATCNT_CR2_VADDR              	(0xb801c5d8)
#define  BUS_TV_SB2_DCU1_LOW_LATCNT_CR3_VADDR              	(0xb801c5dc)
#define  BUS_TV_SB2_DCU1_LOW_LATCNT_CR4_VADDR              	(0xb801c5e0)
#define  BUS_TV_SB2_DCU1_LOW_LATCNT_CR5_VADDR              	(0xb801c5e4)
#define  BUS_TV_SB2_DCU1_LOW_LATCNT_CR6_VADDR              	(0xb801c5f0)
#define  BUS_TV_SB2_DCU1_DEBUG_VADDR                       	(0xb801c5f4)
#define  BUS_TV_SB2_DCU1_UNDER_LEVEL_ARB_CR_VADDR          	(0xb801c5f8)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======TV-SB2-DCU1 register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  time_step:4;
    };
}bus_tv_sb2_dcu1_arb_cr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  cnt_src_sel:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  arb_en:12;
    };
}bus_tv_sb2_dcu1_arb_cr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  client0_latcnt_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  client0_latcnt_beg:12;
    };
}bus_tv_sb2_dcu1_latcnt_cr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  client1_latcnt_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  client1_latcnt_beg:12;
    };
}bus_tv_sb2_dcu1_latcnt_cr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  client2_latcnt_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  client2_latcnt_beg:12;
    };
}bus_tv_sb2_dcu1_latcnt_cr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  client3_latcnt_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  client3_latcnt_beg:12;
    };
}bus_tv_sb2_dcu1_latcnt_cr4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  client4_latcnt_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  client4_latcnt_beg:12;
    };
}bus_tv_sb2_dcu1_latcnt_cr5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  client5_latcnt_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  client5_latcnt_beg:12;
    };
}bus_tv_sb2_dcu1_latcnt_cr6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  client6_latcnt_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  client6_latcnt_beg:12;
    };
}bus_tv_sb2_dcu1_latcnt_cr7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  client7_latcnt_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  client7_latcnt_beg:12;
    };
}bus_tv_sb2_dcu1_latcnt_cr8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  client8_latcnt_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  client8_latcnt_beg:12;
    };
}bus_tv_sb2_dcu1_latcnt_cr9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  client9_latcnt_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  client9_latcnt_beg:12;
    };
}bus_tv_sb2_dcu1_latcnt_cr10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  client10_latcnt_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  client10_latcnt_beg:12;
    };
}bus_tv_sb2_dcu1_latcnt_cr11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  client11_latcnt_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  client11_latcnt_beg:12;
    };
}bus_tv_sb2_dcu1_latcnt_cr12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  pc_go:1;
    };
}bus_tv_sb2_dcu1_pc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_tota_mon_num:32;
    };
}bus_tv_sb2_dcu1_pc_tota_mon_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_tota_ack_num:32;
    };
}bus_tv_sb2_dcu1_pc_tota_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_tota_idl_num:32;
    };
}bus_tv_sb2_dcu1_pc_tota_idl_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  write_en_3:1;
        RBus_UInt32  pc_prog2_sel:7;
        RBus_UInt32  write_en_2:1;
        RBus_UInt32  pc_prog1_sel:7;
        RBus_UInt32  write_en_1:1;
        RBus_UInt32  pc_prog0_sel:7;
    };
}bus_tv_sb2_dcu1_pc_prog_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  pc_prog2_req_occur:1;
        RBus_UInt32  pc_prog1_req_occur:1;
        RBus_UInt32  pc_prog0_req_occur:1;
    };
}bus_tv_sb2_dcu1_pc_prog_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  prog_channel_sel:2;
    };
}bus_tv_sb2_dcu1_pc_prog_0_channel_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prog_acc_lat:32;
    };
}bus_tv_sb2_dcu1_pc_prog_0_acc_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  prog_max_lat:16;
    };
}bus_tv_sb2_dcu1_pc_prog_0_max_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  prog_req_num:24;
    };
}bus_tv_sb2_dcu1_pc_prog_0_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prog_ack_num:32;
    };
}bus_tv_sb2_dcu1_pc_prog_0_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  prog_hitend_cnt:16;
    };
}bus_tv_sb2_dcu1_pc_prog_0_hitend_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client0_cntr_val_set:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  client0_cntr_val:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  res3:12;
    };
}bus_tv_sb2_dcu1_arb_cntr_set1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client1_cntr_val_set:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  client1_cntr_val:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  res3:12;
    };
}bus_tv_sb2_dcu1_arb_cntr_set2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client2_cntr_val_set:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  client2_cntr_val:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  res3:12;
    };
}bus_tv_sb2_dcu1_arb_cntr_set3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client3_cntr_val_set:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  client3_cntr_val:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  res3:12;
    };
}bus_tv_sb2_dcu1_arb_cntr_set4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client4_cntr_val_set:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  client4_cntr_val:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  res3:12;
    };
}bus_tv_sb2_dcu1_arb_cntr_set5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client5_cntr_val_set:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  client5_cntr_val:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  res3:12;
    };
}bus_tv_sb2_dcu1_arb_cntr_set6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client6_cntr_val_set:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  client6_cntr_val:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  res3:12;
    };
}bus_tv_sb2_dcu1_arb_cntr_set7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client7_cntr_val_set:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  client7_cntr_val:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  res3:12;
    };
}bus_tv_sb2_dcu1_arb_cntr_set8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client8_cntr_val_set:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  client8_cntr_val:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  res3:12;
    };
}bus_tv_sb2_dcu1_arb_cntr_set9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client9_cntr_val_set:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  client9_cntr_val:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  res3:12;
    };
}bus_tv_sb2_dcu1_arb_cntr_set10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client10_cntr_val_set:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  client10_cntr_val:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  res3:12;
    };
}bus_tv_sb2_dcu1_arb_cntr_set11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client11_cntr_val_set:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  client11_cntr_val:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  res3:12;
    };
}bus_tv_sb2_dcu1_arb_cntr_set12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  sb_req:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  sb_gnt:12;
    };
}bus_tv_sb2_dcu1_arb_sr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  win_latcnt:12;
    };
}bus_tv_sb2_dcu1_arb_sr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  low_lvl_ie:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  low_lvl_ip:12;
    };
}bus_tv_sb2_dcu1_arb_sr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client1_low_latcnt_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  client1_low_latcnt:12;
        RBus_UInt32  client0_low_latcnt_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  client0_low_latcnt:12;
    };
}bus_tv_sb2_dcu1_low_latcnt_cr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client3_low_latcnt_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  client3_low_latcnt:12;
        RBus_UInt32  client2_low_latcnt_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  client2_low_latcnt:12;
    };
}bus_tv_sb2_dcu1_low_latcnt_cr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client5_low_latcnt_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  client5_low_latcnt:12;
        RBus_UInt32  client4_low_latcnt_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  client4_low_latcnt:12;
    };
}bus_tv_sb2_dcu1_low_latcnt_cr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client7_low_latcnt_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  client7_low_latcnt:12;
        RBus_UInt32  client6_low_latcnt_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  client6_low_latcnt:12;
    };
}bus_tv_sb2_dcu1_low_latcnt_cr4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client9_low_latcnt_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  client9_low_latcnt:12;
        RBus_UInt32  client8_low_latcnt_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  client8_low_latcnt:12;
    };
}bus_tv_sb2_dcu1_low_latcnt_cr5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client11_low_latcnt_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  client11_low_latcnt:12;
        RBus_UInt32  client10_low_latcnt_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  client10_low_latcnt:12;
    };
}bus_tv_sb2_dcu1_low_latcnt_cr6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  sb_debug_mode:4;
    };
}bus_tv_sb2_dcu1_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  under_keep_cycle:3;
        RBus_UInt32  under_level:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  under_level_arb_en:12;
    };
}bus_tv_sb2_dcu1_under_level_arb_cr_RBUS;

#else //apply LITTLE_ENDIAN

//======TV-SB2-DCU1 register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  time_step:4;
        RBus_UInt32  res1:28;
    };
}bus_tv_sb2_dcu1_arb_cr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  arb_en:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  cnt_src_sel:12;
        RBus_UInt32  res2:4;
    };
}bus_tv_sb2_dcu1_arb_cr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client0_latcnt_beg:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  client0_latcnt_end:12;
        RBus_UInt32  res2:4;
    };
}bus_tv_sb2_dcu1_latcnt_cr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client1_latcnt_beg:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  client1_latcnt_end:12;
        RBus_UInt32  res2:4;
    };
}bus_tv_sb2_dcu1_latcnt_cr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client2_latcnt_beg:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  client2_latcnt_end:12;
        RBus_UInt32  res2:4;
    };
}bus_tv_sb2_dcu1_latcnt_cr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client3_latcnt_beg:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  client3_latcnt_end:12;
        RBus_UInt32  res2:4;
    };
}bus_tv_sb2_dcu1_latcnt_cr4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client4_latcnt_beg:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  client4_latcnt_end:12;
        RBus_UInt32  res2:4;
    };
}bus_tv_sb2_dcu1_latcnt_cr5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client5_latcnt_beg:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  client5_latcnt_end:12;
        RBus_UInt32  res2:4;
    };
}bus_tv_sb2_dcu1_latcnt_cr6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client6_latcnt_beg:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  client6_latcnt_end:12;
        RBus_UInt32  res2:4;
    };
}bus_tv_sb2_dcu1_latcnt_cr7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client7_latcnt_beg:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  client7_latcnt_end:12;
        RBus_UInt32  res2:4;
    };
}bus_tv_sb2_dcu1_latcnt_cr8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client8_latcnt_beg:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  client8_latcnt_end:12;
        RBus_UInt32  res2:4;
    };
}bus_tv_sb2_dcu1_latcnt_cr9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client9_latcnt_beg:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  client9_latcnt_end:12;
        RBus_UInt32  res2:4;
    };
}bus_tv_sb2_dcu1_latcnt_cr10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client10_latcnt_beg:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  client10_latcnt_end:12;
        RBus_UInt32  res2:4;
    };
}bus_tv_sb2_dcu1_latcnt_cr11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client11_latcnt_beg:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  client11_latcnt_end:12;
        RBus_UInt32  res2:4;
    };
}bus_tv_sb2_dcu1_latcnt_cr12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_go:1;
        RBus_UInt32  res1:31;
    };
}bus_tv_sb2_dcu1_pc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_tota_mon_num:32;
    };
}bus_tv_sb2_dcu1_pc_tota_mon_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_tota_ack_num:32;
    };
}bus_tv_sb2_dcu1_pc_tota_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_tota_idl_num:32;
    };
}bus_tv_sb2_dcu1_pc_tota_idl_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_prog0_sel:7;
        RBus_UInt32  write_en_1:1;
        RBus_UInt32  pc_prog1_sel:7;
        RBus_UInt32  write_en_2:1;
        RBus_UInt32  pc_prog2_sel:7;
        RBus_UInt32  write_en_3:1;
        RBus_UInt32  res1:8;
    };
}bus_tv_sb2_dcu1_pc_prog_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_prog0_req_occur:1;
        RBus_UInt32  pc_prog1_req_occur:1;
        RBus_UInt32  pc_prog2_req_occur:1;
        RBus_UInt32  res1:29;
    };
}bus_tv_sb2_dcu1_pc_prog_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prog_channel_sel:2;
        RBus_UInt32  res1:30;
    };
}bus_tv_sb2_dcu1_pc_prog_0_channel_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prog_acc_lat:32;
    };
}bus_tv_sb2_dcu1_pc_prog_0_acc_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prog_max_lat:16;
        RBus_UInt32  res1:16;
    };
}bus_tv_sb2_dcu1_pc_prog_0_max_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prog_req_num:24;
        RBus_UInt32  res1:8;
    };
}bus_tv_sb2_dcu1_pc_prog_0_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prog_ack_num:32;
    };
}bus_tv_sb2_dcu1_pc_prog_0_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prog_hitend_cnt:16;
        RBus_UInt32  res1:16;
    };
}bus_tv_sb2_dcu1_pc_prog_0_hitend_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  client0_cntr_val:12;
        RBus_UInt32  res3:3;
        RBus_UInt32  client0_cntr_val_set:1;
    };
}bus_tv_sb2_dcu1_arb_cntr_set1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  client1_cntr_val:12;
        RBus_UInt32  res3:3;
        RBus_UInt32  client1_cntr_val_set:1;
    };
}bus_tv_sb2_dcu1_arb_cntr_set2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  client2_cntr_val:12;
        RBus_UInt32  res3:3;
        RBus_UInt32  client2_cntr_val_set:1;
    };
}bus_tv_sb2_dcu1_arb_cntr_set3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  client3_cntr_val:12;
        RBus_UInt32  res3:3;
        RBus_UInt32  client3_cntr_val_set:1;
    };
}bus_tv_sb2_dcu1_arb_cntr_set4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  client4_cntr_val:12;
        RBus_UInt32  res3:3;
        RBus_UInt32  client4_cntr_val_set:1;
    };
}bus_tv_sb2_dcu1_arb_cntr_set5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  client5_cntr_val:12;
        RBus_UInt32  res3:3;
        RBus_UInt32  client5_cntr_val_set:1;
    };
}bus_tv_sb2_dcu1_arb_cntr_set6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  client6_cntr_val:12;
        RBus_UInt32  res3:3;
        RBus_UInt32  client6_cntr_val_set:1;
    };
}bus_tv_sb2_dcu1_arb_cntr_set7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  client7_cntr_val:12;
        RBus_UInt32  res3:3;
        RBus_UInt32  client7_cntr_val_set:1;
    };
}bus_tv_sb2_dcu1_arb_cntr_set8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  client8_cntr_val:12;
        RBus_UInt32  res3:3;
        RBus_UInt32  client8_cntr_val_set:1;
    };
}bus_tv_sb2_dcu1_arb_cntr_set9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  client9_cntr_val:12;
        RBus_UInt32  res3:3;
        RBus_UInt32  client9_cntr_val_set:1;
    };
}bus_tv_sb2_dcu1_arb_cntr_set10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  client10_cntr_val:12;
        RBus_UInt32  res3:3;
        RBus_UInt32  client10_cntr_val_set:1;
    };
}bus_tv_sb2_dcu1_arb_cntr_set11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  client11_cntr_val:12;
        RBus_UInt32  res3:3;
        RBus_UInt32  client11_cntr_val_set:1;
    };
}bus_tv_sb2_dcu1_arb_cntr_set12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb_gnt:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  sb_req:12;
        RBus_UInt32  res2:4;
    };
}bus_tv_sb2_dcu1_arb_sr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  win_latcnt:12;
        RBus_UInt32  res1:20;
    };
}bus_tv_sb2_dcu1_arb_sr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  low_lvl_ip:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  low_lvl_ie:12;
        RBus_UInt32  res2:4;
    };
}bus_tv_sb2_dcu1_arb_sr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client0_low_latcnt:12;
        RBus_UInt32  res1:3;
        RBus_UInt32  client0_low_latcnt_en:1;
        RBus_UInt32  client1_low_latcnt:12;
        RBus_UInt32  res2:3;
        RBus_UInt32  client1_low_latcnt_en:1;
    };
}bus_tv_sb2_dcu1_low_latcnt_cr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client2_low_latcnt:12;
        RBus_UInt32  res1:3;
        RBus_UInt32  client2_low_latcnt_en:1;
        RBus_UInt32  client3_low_latcnt:12;
        RBus_UInt32  res2:3;
        RBus_UInt32  client3_low_latcnt_en:1;
    };
}bus_tv_sb2_dcu1_low_latcnt_cr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client4_low_latcnt:12;
        RBus_UInt32  res1:3;
        RBus_UInt32  client4_low_latcnt_en:1;
        RBus_UInt32  client5_low_latcnt:12;
        RBus_UInt32  res2:3;
        RBus_UInt32  client5_low_latcnt_en:1;
    };
}bus_tv_sb2_dcu1_low_latcnt_cr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client6_low_latcnt:12;
        RBus_UInt32  res1:3;
        RBus_UInt32  client6_low_latcnt_en:1;
        RBus_UInt32  client7_low_latcnt:12;
        RBus_UInt32  res2:3;
        RBus_UInt32  client7_low_latcnt_en:1;
    };
}bus_tv_sb2_dcu1_low_latcnt_cr4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client8_low_latcnt:12;
        RBus_UInt32  res1:3;
        RBus_UInt32  client8_low_latcnt_en:1;
        RBus_UInt32  client9_low_latcnt:12;
        RBus_UInt32  res2:3;
        RBus_UInt32  client9_low_latcnt_en:1;
    };
}bus_tv_sb2_dcu1_low_latcnt_cr5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client10_low_latcnt:12;
        RBus_UInt32  res1:3;
        RBus_UInt32  client10_low_latcnt_en:1;
        RBus_UInt32  client11_low_latcnt:12;
        RBus_UInt32  res2:3;
        RBus_UInt32  client11_low_latcnt_en:1;
    };
}bus_tv_sb2_dcu1_low_latcnt_cr6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb_debug_mode:4;
        RBus_UInt32  res1:28;
    };
}bus_tv_sb2_dcu1_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  under_level_arb_en:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  under_level:12;
        RBus_UInt32  under_keep_cycle:3;
        RBus_UInt32  res2:1;
    };
}bus_tv_sb2_dcu1_under_level_arb_cr_RBUS;




#endif 


#endif 
