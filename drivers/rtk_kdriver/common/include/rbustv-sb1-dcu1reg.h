/**
* @file rbusTV-SB1-DCU1Reg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2014-7-11
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_TV_SB1_DCU1_REG_H_
#define _RBUS_TV_SB1_DCU1_REG_H_

#include "rbusTypes.h"



//  TV-SB1-DCU1 Register Address



#define  BUS_TV_SB1_DCU1_ARB_CR_VADDR                      	(0xb801c300)
#define  BUS_TV_SB1_DCU1_LATCNT_CR1_VADDR                  	(0xb801c310)
#define  BUS_TV_SB1_DCU1_LATCNT_CR2_VADDR                  	(0xb801c314)
#define  BUS_TV_SB1_DCU1_LATCNT_CR3_VADDR                  	(0xb801c318)
#define  BUS_TV_SB1_DCU1_LATCNT_CR4_VADDR                  	(0xb801c31c)
#define  BUS_TV_SB1_DCU1_LATCNT_CR5_VADDR                  	(0xb801c320)
#define  BUS_TV_SB1_DCU1_LATCNT_CR6_VADDR                  	(0xb801c324)
#define  BUS_TV_SB1_DCU1_PC_CTRL_VADDR                     	(0xb801c350)
#define  BUS_TV_SB1_DCU1_PC_TOTA_MON_NUM_VADDR             	(0xb801c354)
#define  BUS_TV_SB1_DCU1_PC_TOTA_ACK_NUM_VADDR             	(0xb801c358)
#define  BUS_TV_SB1_DCU1_PC_TOTA_IDL_NUM_VADDR             	(0xb801c35c)
#define  BUS_TV_SB1_DCU1_PC_PROG_CTRL1_VADDR               	(0xb801c360)
#define  BUS_TV_SB1_DCU1_PC_PROG_CTRL2_VADDR               	(0xb801c364)
#define  BUS_TV_SB1_DCU1_PC_PROG_0_CHANNEL_SEL_VADDR       	(0xb801c368)
#define  BUS_TV_SB1_DCU1_PC_PROG_0_ACC_LAT_VADDR           	(0xb801c36c)
#define  BUS_TV_SB1_DCU1_PC_PROG_0_MAX_LAT_VADDR           	(0xb801c370)
#define  BUS_TV_SB1_DCU1_PC_PROG_0_REQ_NUM_VADDR           	(0xb801c374)
#define  BUS_TV_SB1_DCU1_PC_PROG_0_ACK_NUM_VADDR           	(0xb801c378)
#define  BUS_TV_SB1_DCU1_PC_PROG_0_HITEND_VADDR            	(0xb801c37c)
#define  BUS_TV_SB1_DCU1_ARB_CNTR_SET1_VADDR               	(0xb801c380)
#define  BUS_TV_SB1_DCU1_ARB_CNTR_SET2_VADDR               	(0xb801c384)
#define  BUS_TV_SB1_DCU1_ARB_CNTR_SET3_VADDR               	(0xb801c388)
#define  BUS_TV_SB1_DCU1_ARB_CNTR_SET4_VADDR               	(0xb801c38c)
#define  BUS_TV_SB1_DCU1_ARB_CNTR_SET5_VADDR               	(0xb801c390)
#define  BUS_TV_SB1_DCU1_ARB_CNTR_SET6_VADDR               	(0xb801c394)
#define  BUS_TV_SB1_DCU1_REQ_CR_VADDR                      	(0xb801c3a0)
#define  BUS_TV_SB1_DCU1_ARB_SR1_VADDR                     	(0xb801c3b0)
#define  BUS_TV_SB1_DCU1_ARB_SR2_VADDR                     	(0xb801c3b4)
#define  BUS_TV_SB1_DCU1_LOW_LATCNT_CR1_VADDR              	(0xb801c3b8)
#define  BUS_TV_SB1_DCU1_LOW_LATCNT_CR2_VADDR              	(0xb801c3bc)
#define  BUS_TV_SB1_DCU1_LOW_LATCNT_CR3_VADDR              	(0xb801c3c0)
#define  BUS_TV_SB1_DCU1_DEBUG_VADDR                       	(0xb801c3cc)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======TV-SB1-DCU1 register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  cnt_src_sel:6;
        RBus_UInt32  time_step:4;
        RBus_UInt32  res2:6;
        RBus_UInt32  arb_en:6;
    };
}bus_tv_sb1_dcu1_arb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  client0_latcnt_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  client0_latcnt_beg:12;
    };
}bus_tv_sb1_dcu1_latcnt_cr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  client1_latcnt_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  client1_latcnt_beg:12;
    };
}bus_tv_sb1_dcu1_latcnt_cr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  client2_latcnt_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  client2_latcnt_beg:12;
    };
}bus_tv_sb1_dcu1_latcnt_cr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  client3_latcnt_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  client3_latcnt_beg:12;
    };
}bus_tv_sb1_dcu1_latcnt_cr4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  client4_latcnt_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  client4_latcnt_beg:12;
    };
}bus_tv_sb1_dcu1_latcnt_cr5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  client5_latcnt_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  client5_latcnt_beg:12;
    };
}bus_tv_sb1_dcu1_latcnt_cr6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  pc_go:1;
    };
}bus_tv_sb1_dcu1_pc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_tota_mon_num:32;
    };
}bus_tv_sb1_dcu1_pc_tota_mon_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_tota_ack_num:32;
    };
}bus_tv_sb1_dcu1_pc_tota_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_tota_idl_num:32;
    };
}bus_tv_sb1_dcu1_pc_tota_idl_num_RBUS;

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
}bus_tv_sb1_dcu1_pc_prog_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  pc_prog2_req_occur:1;
        RBus_UInt32  pc_prog1_req_occur:1;
        RBus_UInt32  pc_prog0_req_occur:1;
    };
}bus_tv_sb1_dcu1_pc_prog_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  prog_channel_sel:2;
    };
}bus_tv_sb1_dcu1_pc_prog_0_channel_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prog_acc_lat:32;
    };
}bus_tv_sb1_dcu1_pc_prog_0_acc_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  prog_max_lat:16;
    };
}bus_tv_sb1_dcu1_pc_prog_0_max_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  prog_req_num:24;
    };
}bus_tv_sb1_dcu1_pc_prog_0_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prog_ack_num:32;
    };
}bus_tv_sb1_dcu1_pc_prog_0_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  prog_hitend_cnt:16;
    };
}bus_tv_sb1_dcu1_pc_prog_0_hitend_RBUS;

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
}bus_tv_sb1_dcu1_arb_cntr_set1_RBUS;

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
}bus_tv_sb1_dcu1_arb_cntr_set2_RBUS;

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
}bus_tv_sb1_dcu1_arb_cntr_set3_RBUS;

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
}bus_tv_sb1_dcu1_arb_cntr_set4_RBUS;

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
}bus_tv_sb1_dcu1_arb_cntr_set5_RBUS;

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
}bus_tv_sb1_dcu1_arb_cntr_set6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  max_count:4;
        RBus_UInt32  res2:8;
        RBus_UInt32  off_time:8;
    };
}bus_tv_sb1_dcu1_req_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  sb_req:6;
        RBus_UInt32  res2:4;
        RBus_UInt32  sb_gnt:6;
        RBus_UInt32  win_latcnt:12;
    };
}bus_tv_sb1_dcu1_arb_sr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  low_lvl_ie:6;
        RBus_UInt32  res2:10;
        RBus_UInt32  low_lvl_ip:6;
    };
}bus_tv_sb1_dcu1_arb_sr2_RBUS;

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
}bus_tv_sb1_dcu1_low_latcnt_cr1_RBUS;

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
}bus_tv_sb1_dcu1_low_latcnt_cr2_RBUS;

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
}bus_tv_sb1_dcu1_low_latcnt_cr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  sb_debug_mode:4;
    };
}bus_tv_sb1_dcu1_debug_RBUS;

#else //apply LITTLE_ENDIAN

//======TV-SB1-DCU1 register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  arb_en:6;
        RBus_UInt32  res1:6;
        RBus_UInt32  time_step:4;
        RBus_UInt32  cnt_src_sel:6;
        RBus_UInt32  res2:10;
    };
}bus_tv_sb1_dcu1_arb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client0_latcnt_beg:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  client0_latcnt_end:12;
        RBus_UInt32  res2:4;
    };
}bus_tv_sb1_dcu1_latcnt_cr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client1_latcnt_beg:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  client1_latcnt_end:12;
        RBus_UInt32  res2:4;
    };
}bus_tv_sb1_dcu1_latcnt_cr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client2_latcnt_beg:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  client2_latcnt_end:12;
        RBus_UInt32  res2:4;
    };
}bus_tv_sb1_dcu1_latcnt_cr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client3_latcnt_beg:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  client3_latcnt_end:12;
        RBus_UInt32  res2:4;
    };
}bus_tv_sb1_dcu1_latcnt_cr4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client4_latcnt_beg:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  client4_latcnt_end:12;
        RBus_UInt32  res2:4;
    };
}bus_tv_sb1_dcu1_latcnt_cr5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client5_latcnt_beg:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  client5_latcnt_end:12;
        RBus_UInt32  res2:4;
    };
}bus_tv_sb1_dcu1_latcnt_cr6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_go:1;
        RBus_UInt32  res1:31;
    };
}bus_tv_sb1_dcu1_pc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_tota_mon_num:32;
    };
}bus_tv_sb1_dcu1_pc_tota_mon_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_tota_ack_num:32;
    };
}bus_tv_sb1_dcu1_pc_tota_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_tota_idl_num:32;
    };
}bus_tv_sb1_dcu1_pc_tota_idl_num_RBUS;

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
}bus_tv_sb1_dcu1_pc_prog_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_prog0_req_occur:1;
        RBus_UInt32  pc_prog1_req_occur:1;
        RBus_UInt32  pc_prog2_req_occur:1;
        RBus_UInt32  res1:29;
    };
}bus_tv_sb1_dcu1_pc_prog_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prog_channel_sel:2;
        RBus_UInt32  res1:30;
    };
}bus_tv_sb1_dcu1_pc_prog_0_channel_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prog_acc_lat:32;
    };
}bus_tv_sb1_dcu1_pc_prog_0_acc_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prog_max_lat:16;
        RBus_UInt32  res1:16;
    };
}bus_tv_sb1_dcu1_pc_prog_0_max_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prog_req_num:24;
        RBus_UInt32  res1:8;
    };
}bus_tv_sb1_dcu1_pc_prog_0_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prog_ack_num:32;
    };
}bus_tv_sb1_dcu1_pc_prog_0_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prog_hitend_cnt:16;
        RBus_UInt32  res1:16;
    };
}bus_tv_sb1_dcu1_pc_prog_0_hitend_RBUS;

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
}bus_tv_sb1_dcu1_arb_cntr_set1_RBUS;

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
}bus_tv_sb1_dcu1_arb_cntr_set2_RBUS;

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
}bus_tv_sb1_dcu1_arb_cntr_set3_RBUS;

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
}bus_tv_sb1_dcu1_arb_cntr_set4_RBUS;

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
}bus_tv_sb1_dcu1_arb_cntr_set5_RBUS;

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
}bus_tv_sb1_dcu1_arb_cntr_set6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  off_time:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  max_count:4;
        RBus_UInt32  res2:12;
    };
}bus_tv_sb1_dcu1_req_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  win_latcnt:12;
        RBus_UInt32  sb_gnt:6;
        RBus_UInt32  res1:4;
        RBus_UInt32  sb_req:6;
        RBus_UInt32  res2:4;
    };
}bus_tv_sb1_dcu1_arb_sr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  low_lvl_ip:6;
        RBus_UInt32  res1:10;
        RBus_UInt32  low_lvl_ie:6;
        RBus_UInt32  res2:10;
    };
}bus_tv_sb1_dcu1_arb_sr2_RBUS;

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
}bus_tv_sb1_dcu1_low_latcnt_cr1_RBUS;

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
}bus_tv_sb1_dcu1_low_latcnt_cr2_RBUS;

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
}bus_tv_sb1_dcu1_low_latcnt_cr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb_debug_mode:4;
        RBus_UInt32  res1:28;
    };
}bus_tv_sb1_dcu1_debug_RBUS;




#endif 


#endif 
