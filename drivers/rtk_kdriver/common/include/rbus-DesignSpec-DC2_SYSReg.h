/**
* @file rbusMagellan2-DesignSpec-DC2_SYSReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015-2-5
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_MAGELLAN2_DESIGNSPEC_DC2_SYS_REG_H_
#define _RBUS_MAGELLAN2_DESIGNSPEC_DC2_SYS_REG_H_

#include "rbus_types.h"



//  MAGELLAN2-DESIGNSPEC-DC2_SYS Register Address



#define  DC2_PICT_SET_VADDR                                  	(0xb8003000)
#define  DC2_SYS_MISC_VADDR                                  	(0xb8003004)
#define  DC2_PIC_OFFSET_X_DETECTION_VADDR                    	(0xb8003010)
#define  DC2_PICT_SET_OFFSET_VADDR                           	(0xb8003020)
#define  DC2_REQ_STATUS_VADDR                                	(0xb8003024)
#define  DC2_SYS_MISC2_VADDR                                 	(0xb8003028)
#define  DC2_SYS_MISC3_VADDR                                 	(0xb800302c)
#define  DC2_SFMODE0_VADDR                                   	(0xb8003040)
#define  DC2_SFMODE1_VADDR                                   	(0xb8003044)
#define  DC2_SFMODE2_VADDR                                   	(0xb8003048)
#define  DC2_SFMODE3_VADDR                                   	(0xb800304c)
#define  DC2_SFMODE_CMP0_VADDR                               	(0xb8003050)
#define  DC2_SFMODE_CMP1_VADDR                               	(0xb8003054)
#define  DC2_SFMODE_CMP2_VADDR                               	(0xb8003058)
#define  DC2_SFMODE_CMP3_VADDR                               	(0xb800305c)
#define  DC2_DEBUG_SYS_VADDR                                   (0xb8003060)
#define  DC2_DEBUG_STATUS_VADDR                              	(0xb8003064)
#define  DC2_PRIORITY_CTRL0_VADDR                            	(0xb8003080)
#define  DC2_PRIORITY_CTRL1_VADDR                            	(0xb8003084)
#define  DC2_PRIORITY_CTRL2_VADDR                            	(0xb8003088)
#define  DC2_PRIORITY_CTRL3_VADDR                            	(0xb800308c)
#define  DC2_PRIORITY_CTRL4_VADDR                            	(0xb8003090)
#define  DC2_PRIORITY_CTRL5_VADDR                            	(0xb8003094)
#define  DC2_PRIORITY_CTRL6_VADDR                            	(0xb8003098)
#define  DC2_PRIORITY_CTRL7_VADDR                            	(0xb800309c)
#define  DC2_PRIORITY_CTRL8_VADDR                            	(0xb80030a0)
#define  DC2_PRIORITY_CTRL9_VADDR                            	(0xb80030a4)
#define  DC2_PRIORITY_CTRLA_VADDR                            	(0xb80030a8)
#define  DC2_PRIORITY_CTRLB_VADDR                            	(0xb80030ac)
#define  DC2_PRIORITY_CTRL_HIE_VADDR                         	(0xb80030b0)
#define  DC2_PRIORITY_CTRL_SCPU_VADDR                        	(0xb80030c0)
#define  DC2_CLIENT_MASK_VADDR                               	(0xb80030d0)
#define  DC2_PC_CTRL_VADDR                                   	(0xb8003100)
#define  DC2_PC_TOTA_MON_NUM_VADDR                           	(0xb8003104)
#define  DC2_PC_TOTA_ACK_NUM_VADDR                           	(0xb8003108)
#define  DC2_PC_TOTA_IDL_NUM_VADDR                           	(0xb800310c)
#define  DC2_PC_SYSH_PROG_CTRL_VADDR                         	(0xb8003110)
#define  DC2_PC_SYS_PROG_CTRL1_VADDR                         	(0xb8003120)
#define  DC2_PC_SYSH_PROG_0_ACC_LAT_VADDR                    	(0xb8003130)
#define  DC2_PC_SYSH_PROG_0_MAX_LAT_VADDR                    	(0xb8003134)
#define  DC2_PC_SYSH_PROG_0_REQ_NUM_VADDR                    	(0xb8003138)
#define  DC2_PC_SYSH_PROG_0_ACK_NUM_VADDR                    	(0xb800313c)
#define  DC2_PC_SYSH_PROG_1_ACC_LAT_VADDR                    	(0xb8003140)
#define  DC2_PC_SYSH_PROG_1_MAX_LAT_VADDR                    	(0xb8003144)
#define  DC2_PC_SYSH_PROG_1_REQ_NUM_VADDR                    	(0xb8003148)
#define  DC2_PC_SYSH_PROG_1_ACK_NUM_VADDR                    	(0xb800314c)
#define  DC2_PC_SYSH_PROG_2_ACC_LAT_VADDR                    	(0xb8003150)
#define  DC2_PC_SYSH_PROG_2_MAX_LAT_VADDR                    	(0xb8003154)
#define  DC2_PC_SYSH_PROG_2_REQ_NUM_VADDR                    	(0xb8003158)
#define  DC2_PC_SYSH_PROG_2_ACK_NUM_VADDR                    	(0xb800315c)
#define  DC2_PC_SYSH_PROG_0_VADDR                            	(0xb8003190)
#define  DC2_PC_SYSH_PROG_1_VADDR                            	(0xb8003194)
#define  DC2_PC_SYSH_PROG_2_VADDR                            	(0xb8003198)
#define  DC2_BIST_MODE_VADDR                                 	(0xb80031c0)
#define  DC2_BIST_DONE_VADDR                                 	(0xb80031c4)
#define  DC2_BIST_FAIL_VADDR                                 	(0xb80031c8)
#define  DC2_BIST_DRF_VADDR                                  	(0xb80031cc)
#define  DC2_BIST_RESUME_VADDR                               	(0xb80031d0)
#define  DC2_BIST0_DRF_DONE_VADDR                            	(0xb80031d4)
#define  DC2_BIST_DRF_PAUSE_VADDR                            	(0xb80031d8)
#define  DC2_BIST_DRF_FAIL_VADDR                             	(0xb80031dc)
#define  DC2_BIST_DETAIL_VADDR                               	(0xb80031e0)
#define  DC2_BIST_RM_VADDR                                   	(0xb80031e4)
#define  DC2_DUMMY_REG0_VADDR                                	(0xb80031f0)
#define  DC2_DUMMY_REG1_VADDR                                	(0xb80031f4)
#define  DC2_DUMMY_REG2_VADDR                                	(0xb80031f8)
#define  DC2_DUMMY_REG3_VADDR                                	(0xb80031fc)
#define  DC2_MT_TYPE_VADDR                                   	(0xb8003200)
#define  DC2_MT_SADDR_VADDR                                  	(0xb8003210)
#define  DC2_MT_EADDR_VADDR                                  	(0xb8003220)
#define  DC2_MT_MODE_VADDR                                   	(0xb8003240)
#define  DC2_MT_TABLE_VADDR                                  	(0xb8003260)
#define  DC2_MT_ADDCMD_HI_VADDR                              	(0xb8003280)
#define  DC2_MT_ADDCMD_LO_VADDR                              	(0xb80032a0)
#define  DC2_MT_ADDCMD_SA_VADDR                              	(0xb80032b0)
#define  DC2_MT_MISC_VADDR                                   	(0xb80032c0)
#define  DC2_EC_CTRL_VADDR                                   	(0xb80032d0)
#define  DC2_EC_ADDCMD_HI_VADDR                              	(0xb80032d4)
#define  DC2_EC_ADDCMD_LO_VADDR                              	(0xb80032d8)
#define  DC2_RD_TAG_CHECK_VADDR                              	(0xb80032dc)
#define  DC2_INT_ENABLE_VADDR                                	(0xb80032e8)
#define  DC2_INT_STATUS_VADDR                                	(0xb80032ec)
#define  DC2_BW_CTRL_VADDR                                     (0xb8003300)
#define  DC2_BW_TIMER_THRESHOLD_VADDR                          (0xb8003304)
#define  DC2_BW_REQUEST_THRESHOLD_VADDR                        (0xb8003334)
#define  DC2_SYS2_MUX_VADDR                                  	(0xb8003400)
#define  DC2_MT_ADDCMD_HI_SYS2_VADDR                         	(0xb8003410)
#define  DC2_MT_ADDCMD_LO_SYS2_VADDR                         	(0xb8003420)
#define  DC2_MT_ADDCMD_SA_SYS2_VADDR                         	(0xb8003430)
#define  DC2_EC_ADDCMD_HI_SYS2_VADDR                         	(0xb8003440)
#define  DC2_EC_ADDCMD_LO_SYS2_VADDR                         	(0xb8003444)
#define  DC2_INT_ENABLE_SYS2_VADDR                           	(0xb800344c)
#define  DC2_INT_STATUS_SYS2_VADDR                           	(0xb8003450)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======MAGELLAN2-DESIGNSPEC-DC2_SYS register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  pict_width_scale:6;
        RBus_UInt32  pict_init_page:17;
    };
}dc2_pict_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dram_8g_used:1;
        RBus_UInt32  dram_4g_used:1;
        RBus_UInt32  ddr3_512_used:1;
        RBus_UInt32  dram_2g_used:1;
        RBus_UInt32  pre_arb_scheme_sel:1;
        RBus_UInt32  arb_mask_all_en:1;
        RBus_UInt32  ddr3_mapping_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  self_lookback_mode:1;
        RBus_UInt32  mem_num:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  page_size:2;
        RBus_UInt32  res4:6;
        RBus_UInt32  max_bl_size:1;
        RBus_UInt32  en_max_bl_limit:1;
        RBus_UInt32  small_dram_4g:1;
        RBus_UInt32  small_dram_2g:1;
        RBus_UInt32  small_dram_1g:1;
        RBus_UInt32  small_dram_512m:1;
        RBus_UInt32  res5:3;
        RBus_UInt32  en_2ddr_diff_size:1;
    };
}dc2_sys_misc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  enable:1;
    };
}dc2_pic_offset_x_detection_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pict_set_num:8;
        RBus_UInt32  pict_offset_rd:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  pict_set_wide:1;
        RBus_UInt32  pict_set_offset_y:10;
        RBus_UInt32  pict_set_offset_x:10;
    };
}dc2_pict_set_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  req_pending:1;
        RBus_UInt32  req_id:12;
    };
}dc2_req_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pre_arb_merge:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  qfifo_cnt_full_threshold:5;
        RBus_UInt32  full_cmd_count:4;
        RBus_UInt32  pre_tra_rd_cnt:10;
        RBus_UInt32  pre_tra_wr_cnt:10;
    };
}dc2_sys_misc2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  wfifo_cnt_full_threshold:6;
        RBus_UInt32  res2:4;
        RBus_UInt32  gde2_cmd_queue_flush:1;
        RBus_UInt32  gde2_cmd_grp_disable:1;
        RBus_UInt32  ve2_cmd_queue_flush:1;
        RBus_UInt32  ve2_cmd_grp_disable:1;
        RBus_UInt32  res3:6;
        RBus_UInt32  ve_cmd_queue_flush:1;
        RBus_UInt32  ve_cmd_grp_disable:1;
        RBus_UInt32  tvsb4_cmd_queue_flush:1;
        RBus_UInt32  tvsb4_cmd_grp_disable:1;
        RBus_UInt32  tvsb3_cmd_queue_flush:1;
        RBus_UInt32  tvsb3_cmd_grp_disable:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  enable_arb_delay_by_tv_sb1_grant:1;
        RBus_UInt32  gde_cmd_queue_flush:1;
        RBus_UInt32  gde_cmd_grp_disable:1;
    };
}dc2_sys_misc3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_pattern0:32;
    };
}dc2_sfmode0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_pattern1:32;
    };
}dc2_sfmode1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_pattern2:32;
    };
}dc2_sfmode2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_pattern3:32;
    };
}dc2_sfmode3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_cmp_rlt0:32;
    };
}dc2_sfmode_cmp0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_cmp_rlt1:32;
    };
}dc2_sfmode_cmp1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_cmp_rlt2:32;
    };
}dc2_sfmode_cmp2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_cmp_rlt3:32;
    };
}dc2_sfmode_cmp3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  debug_sys2:1;
        RBus_UInt32  debug_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  debug_sel_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  debug_sel_0:6;
    };
}dc2_debug_SYS_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  write_cmd_fifo_1_underflow:1;
        RBus_UInt32  write_cmd_fifo_0_underflow:1;
        RBus_UInt32  read_cmd_fifo_2_underflow:1;
        RBus_UInt32  read_cmd_fifo_1_underflow:1;
        RBus_UInt32  read_cmd_fifo_0_underflow:1;
        RBus_UInt32  write_cmd_fifo_1_overflow:1;
        RBus_UInt32  write_cmd_fifo_0_overflow:1;
        RBus_UInt32  read_cmd_fifo_2_overflow:1;
        RBus_UInt32  read_cmd_fifo_1_overflow:1;
        RBus_UInt32  read_cmd_fifo_0_overflow:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  exsram_fifo_underflow:1;
        RBus_UInt32  exsram_fifo_overflow:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  write_fifo_1_underflow:1;
        RBus_UInt32  write_fifo_0_underflow:1;
        RBus_UInt32  read_fifo_2_underflow:1;
        RBus_UInt32  read_fifo_1_underflow:1;
        RBus_UInt32  read_fifo_0_underflow:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  write_fifo_1_overflow:1;
        RBus_UInt32  write_fifo_0_overflow:1;
        RBus_UInt32  read_fifo_2_overflow:1;
        RBus_UInt32  read_fifo_1_overflow:1;
        RBus_UInt32  read_fifo_0_overflow:1;
    };
}dc2_debug_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  c0_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  c0_latcnt_beg:8;
    };
}dc2_priority_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  c1_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  c1_latcnt_beg:8;
    };
}dc2_priority_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  c2_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  c2_latcnt_beg:8;
    };
}dc2_priority_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  c3_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  c3_latcnt_beg:8;
    };
}dc2_priority_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  c4_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  c4_latcnt_beg:8;
    };
}dc2_priority_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  c5_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  c5_latcnt_beg:8;
    };
}dc2_priority_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  c6_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  c6_latcnt_beg:8;
    };
}dc2_priority_ctrl6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  c7_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  c7_latcnt_beg:8;
    };
}dc2_priority_ctrl7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  c8_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  c8_latcnt_beg:8;
    };
}dc2_priority_ctrl8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  c9_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  c9_latcnt_beg:8;
    };
}dc2_priority_ctrl9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ca_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  ca_latcnt_beg:8;
    };
}dc2_priority_ctrla_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cb_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  cb_latcnt_beg:8;
    };
}dc2_priority_ctrlb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  gpu_lat_new:1;
        RBus_UInt32  hie_cmp_dis:12;
        RBus_UInt32  res2:8;
        RBus_UInt32  latcnt_period:8;
    };
}dc2_priority_ctrl_hie_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  scpu_latcnt:8;
    };
}dc2_priority_ctrl_scpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  req_mask_index:12;
    };
}dc2_client_mask_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  pc_go:1;
    };
}dc2_pc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_tota_mon_num:32;
    };
}dc2_pc_tota_mon_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_tota_ack_num:32;
    };
}dc2_pc_tota_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_tota_idl_num:32;
    };
}dc2_pc_tota_idl_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  write_en_3:1;
        RBus_UInt32  pc_sysh_prog2_sel:7;
        RBus_UInt32  write_en_2:1;
        RBus_UInt32  pc_sysh_prog1_sel:7;
        RBus_UInt32  write_en_1:1;
        RBus_UInt32  pc_sysh_prog0_sel:7;
    };
}dc2_pc_sysh_prog_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  pc_sysh_prog2_req_occur:1;
        RBus_UInt32  pc_sysh_prog1_req_occur:1;
        RBus_UInt32  pc_sysh_prog0_req_occur:1;
        RBus_UInt32  res2:4;
    };
}dc2_pc_sys_prog_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog0_acc_lat:32;
    };
}dc2_pc_sysh_prog_0_acc_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sysh_prog0_max_lat:16;
    };
}dc2_pc_sysh_prog_0_max_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sysh_prog0_req_num:24;
    };
}dc2_pc_sysh_prog_0_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog0_ack_num:32;
    };
}dc2_pc_sysh_prog_0_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog1_acc_lat:32;
    };
}dc2_pc_sysh_prog_1_acc_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sysh_prog1_max_lat:16;
    };
}dc2_pc_sysh_prog_1_max_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sysh_prog1_req_num:24;
    };
}dc2_pc_sysh_prog_1_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog1_ack_num:32;
    };
}dc2_pc_sysh_prog_1_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog2_acc_lat:32;
    };
}dc2_pc_sysh_prog_2_acc_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sysh_prog2_max_lat:16;
    };
}dc2_pc_sysh_prog_2_max_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sysh_prog2_req_num:24;
    };
}dc2_pc_sysh_prog_2_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog2_ack_num:32;
    };
}dc2_pc_sysh_prog_2_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sysh0_hitend_cnt:16;
    };
}dc2_pc_sysh_prog_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sysh1_hitend_cnt:16;
    };
}dc2_pc_sysh_prog_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sysh2_hitend_cnt:16;
    };
}dc2_pc_sysh_prog_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  res2:3;
        RBus_UInt32  dc2_bist_mode_pict0:1;
        RBus_UInt32  res3:1;
    };
}dc2_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  dc2_bist_done_pict0:1;
        RBus_UInt32  res2:1;
    };
}dc2_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  dc2_bist_fail_group_pict0:1;
        RBus_UInt32  res2:1;
    };
}dc2_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  dc2_drf_mode_pict0:1;
        RBus_UInt32  res2:1;
    };
}dc2_bist_drf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  dc2_drf_resume_pict0:1;
        RBus_UInt32  res2:1;
    };
}dc2_bist_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  dc2_drf_done_pict0:1;
        RBus_UInt32  res2:1;
    };
}dc2_bist0_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  dc2_drf_pause_pict0:1;
        RBus_UInt32  res2:1;
    };
}dc2_bist_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  dc2_drf_fail_group_pict0:1;
        RBus_UInt32  res2:1;
    };
}dc2_bist_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  dc2_drf_pict_fail0:1;
        RBus_UInt32  dc2_bist_pict_fail0:1;
        RBus_UInt32  res4:4;
    };
}dc2_bist_detail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  res2:3;
        RBus_UInt32  rme:1;
        RBus_UInt32  rm_3:1;
        RBus_UInt32  rm_2:1;
        RBus_UInt32  rm_1:1;
        RBus_UInt32  rm_0:1;
    };
}dc2_bist_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_reg0:32;
    };
}dc2_dummy_reg0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_reg1:32;
    };
}dc2_dummy_reg1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_reg2:32;
    };
}dc2_dummy_reg2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_reg3:32;
    };
}dc2_dummy_reg3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mem_type:2;
        RBus_UInt32  res1:30;
    };
}dc2_mt_type_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  saddr:26;
        RBus_UInt32  res2:5;
    };
}dc2_mt_saddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  eaddr:26;
        RBus_UInt32  res2:5;
    };
}dc2_mt_eaddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  mode:2;
    };
}dc2_mt_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  module_id_0:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  module_id_1:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  module_id_2:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  module_id_3:7;
    };
}dc2_mt_table_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  access_type_0:2;
        RBus_UInt32  access_type_1:2;
        RBus_UInt32  access_type_2:2;
        RBus_UInt32  access_type_3:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  ever_trap:1;
        RBus_UInt32  module_id:7;
        RBus_UInt32  addcmd:14;
    };
}dc2_mt_addcmd_hi_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd:32;
    };
}dc2_mt_addcmd_lo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  trap_seq_sa:32;
    };
}dc2_mt_addcmd_sa_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  enable_block_info:1;
        RBus_UInt32  disable_cross_range_check:1;
    };
}dc2_mt_misc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  error_cmd_swap_addr:27;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  error_cmd_swap_en:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  error_cmd_detection_en:1;
    };
}dc2_ec_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  error_cmd_ever_trap:1;
        RBus_UInt32  trap_case:8;
        RBus_UInt32  addcmd_hi:22;
    };
}dc2_ec_addcmd_hi_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd_lo:32;
    };
}dc2_ec_addcmd_lo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  tag_check_en:1;
    };
}dc2_rd_tag_check_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  pic_offset_x_odd_int_en:1;
        RBus_UInt32  rd_tag_mismatch_int_en:1;
        RBus_UInt32  err_seq_sa_odd_int_en:1;
        RBus_UInt32  err_seq_bl_zero_int_en:1;
        RBus_UInt32  err_seq_bl_odd_int_en:1;
        RBus_UInt32  err_blk_8x2_on_64_int_en:1;
        RBus_UInt32  err_blk_size_exceed_int_en:1;
        RBus_UInt32  err_blk_h_zero_int_en:1;
        RBus_UInt32  err_blk_w_zero_int_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  mt_3_mod3_int_en:1;
        RBus_UInt32  mt_3_mod2_int_en:1;
        RBus_UInt32  mt_3_mod1_int_en:1;
        RBus_UInt32  mt_2_mod3_int_en:1;
        RBus_UInt32  mt_2_mod2_int_en:1;
        RBus_UInt32  mt_2_mod1_int_en:1;
        RBus_UInt32  mt_1_mod3_int_en:1;
        RBus_UInt32  mt_1_mod2_int_en:1;
        RBus_UInt32  mt_1_mod1_int_en:1;
        RBus_UInt32  mt_0_mod3_int_en:1;
        RBus_UInt32  mt_0_mod2_int_en:1;
        RBus_UInt32  mt_0_mod1_int_en:1;
        RBus_UInt32  write_data:1;
    };
}dc2_int_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  pic_offset_x_odd_int:1;
        RBus_UInt32  rd_tag_mismatch_int:1;
        RBus_UInt32  err_seq_sa_odd_int:1;
        RBus_UInt32  err_seq_bl_zero_int:1;
        RBus_UInt32  err_seq_bl_odd_int:1;
        RBus_UInt32  err_blk_8x2_on_64_int:1;
        RBus_UInt32  err_blk_size_exceed_int:1;
        RBus_UInt32  err_blk_h_zero_int:1;
        RBus_UInt32  err_blk_w_zero_int:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  mt_3_mod3_int:1;
        RBus_UInt32  mt_3_mod2_int:1;
        RBus_UInt32  mt_3_mod1_int:1;
        RBus_UInt32  mt_2_mod3_int:1;
        RBus_UInt32  mt_2_mod2_int:1;
        RBus_UInt32  mt_2_mod1_int:1;
        RBus_UInt32  mt_1_mod3_int:1;
        RBus_UInt32  mt_1_mod2_int:1;
        RBus_UInt32  mt_1_mod1_int:1;
        RBus_UInt32  mt_0_mod3_int:1;
        RBus_UInt32  mt_0_mod2_int:1;
        RBus_UInt32  mt_0_mod1_int:1;
        RBus_UInt32  write_data:1;
    };
}dc2_int_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  bw_en:12;
    };
}dc2_bw_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  value:32;
    };
}dc2_bw_timer_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  value:24;
    };
}dc2_bw_request_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_tra_rd_cnt:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_tra_wr_cnt:10;
        RBus_UInt32  res3:6;
        RBus_UInt32  tv_sb4_mux:1;
        RBus_UInt32  tv_sb2_mux:1;
    };
}dc2_sys2_mux_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  ever_trap:1;
        RBus_UInt32  module_id:7;
        RBus_UInt32  addcmd:14;
    };
}dc2_mt_addcmd_hi_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd:32;
    };
}dc2_mt_addcmd_lo_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  trap_seq_sa:32;
    };
}dc2_mt_addcmd_sa_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  error_cmd_ever_trap:1;
        RBus_UInt32  trap_case:8;
        RBus_UInt32  addcmd_hi:22;
    };
}dc2_ec_addcmd_hi_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd_lo:32;
    };
}dc2_ec_addcmd_lo_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  rd_tag_mismatch_int_en:1;
        RBus_UInt32  err_seq_sa_odd_int_en:1;
        RBus_UInt32  err_seq_bl_zero_int_en:1;
        RBus_UInt32  err_seq_bl_odd_int_en:1;
        RBus_UInt32  err_blk_8x2_on_64_int_en:1;
        RBus_UInt32  err_blk_size_exceed_int_en:1;
        RBus_UInt32  err_blk_h_zero_int_en:1;
        RBus_UInt32  err_blk_w_zero_int_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  mt_3_mod3_int_en:1;
        RBus_UInt32  mt_3_mod2_int_en:1;
        RBus_UInt32  mt_3_mod1_int_en:1;
        RBus_UInt32  mt_2_mod3_int_en:1;
        RBus_UInt32  mt_2_mod2_int_en:1;
        RBus_UInt32  mt_2_mod1_int_en:1;
        RBus_UInt32  mt_1_mod3_int_en:1;
        RBus_UInt32  mt_1_mod2_int_en:1;
        RBus_UInt32  mt_1_mod1_int_en:1;
        RBus_UInt32  mt_0_mod3_int_en:1;
        RBus_UInt32  mt_0_mod2_int_en:1;
        RBus_UInt32  mt_0_mod1_int_en:1;
        RBus_UInt32  write_data:1;
    };
}dc2_int_enable_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  rd_tag_mismatch_int:1;
        RBus_UInt32  err_seq_sa_odd_int:1;
        RBus_UInt32  err_seq_bl_zero_int:1;
        RBus_UInt32  err_seq_bl_odd_int:1;
        RBus_UInt32  err_blk_8x2_on_64_int:1;
        RBus_UInt32  err_blk_size_exceed_int:1;
        RBus_UInt32  err_blk_h_zero_int:1;
        RBus_UInt32  err_blk_w_zero_int:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  mt_3_mod3_int:1;
        RBus_UInt32  mt_3_mod2_int:1;
        RBus_UInt32  mt_3_mod1_int:1;
        RBus_UInt32  mt_2_mod3_int:1;
        RBus_UInt32  mt_2_mod2_int:1;
        RBus_UInt32  mt_2_mod1_int:1;
        RBus_UInt32  mt_1_mod3_int:1;
        RBus_UInt32  mt_1_mod2_int:1;
        RBus_UInt32  mt_1_mod1_int:1;
        RBus_UInt32  mt_0_mod3_int:1;
        RBus_UInt32  mt_0_mod2_int:1;
        RBus_UInt32  mt_0_mod1_int:1;
        RBus_UInt32  write_data:1;
    };
}dc2_int_status_sys2_RBUS;

#else //apply LITTLE_ENDIAN

//======MAGELLAN2-DESIGNSPEC-dc2_SYS register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pict_init_page:17;
        RBus_UInt32  pict_width_scale:6;
        RBus_UInt32  res1:9;
    };
}dc2_pict_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  en_2ddr_diff_size:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  small_dram_512m:1;
        RBus_UInt32  small_dram_1g:1;
        RBus_UInt32  small_dram_2g:1;
        RBus_UInt32  small_dram_4g:1;
        RBus_UInt32  en_max_bl_limit:1;
        RBus_UInt32  max_bl_size:1;
        RBus_UInt32  res2:6;
        RBus_UInt32  page_size:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  mem_num:1;
        RBus_UInt32  self_lookback_mode:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  ddr3_mapping_en:1;
        RBus_UInt32  arb_mask_all_en:1;
        RBus_UInt32  pre_arb_scheme_sel:1;
        RBus_UInt32  dram_2g_used:1;
        RBus_UInt32  ddr3_512_used:1;
        RBus_UInt32  dram_4g_used:1;
        RBus_UInt32  dram_8g_used:1;
        RBus_UInt32  res5:3;
    };
}dc2_sys_misc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  enable:1;
        RBus_UInt32  res1:31;
    };
}dc2_pic_offset_x_detection_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pict_set_offset_x:10;
        RBus_UInt32  pict_set_offset_y:10;
        RBus_UInt32  pict_set_wide:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  pict_offset_rd:1;
        RBus_UInt32  pict_set_num:8;
    };
}dc2_pict_set_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  req_id:12;
        RBus_UInt32  req_pending:1;
        RBus_UInt32  res1:19;
    };
}dc2_req_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pre_tra_wr_cnt:10;
        RBus_UInt32  pre_tra_rd_cnt:10;
        RBus_UInt32  full_cmd_count:4;
        RBus_UInt32  qfifo_cnt_full_threshold:5;
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_arb_merge:1;
    };
}dc2_sys_misc2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gde_cmd_grp_disable:1;
        RBus_UInt32  gde_cmd_queue_flush:1;
        RBus_UInt32  enable_arb_delay_by_tv_sb1_grant:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  tvsb3_cmd_grp_disable:1;
        RBus_UInt32  tvsb3_cmd_queue_flush:1;
        RBus_UInt32  tvsb4_cmd_grp_disable:1;
        RBus_UInt32  tvsb4_cmd_queue_flush:1;
        RBus_UInt32  ve_cmd_grp_disable:1;
        RBus_UInt32  ve_cmd_queue_flush:1;
        RBus_UInt32  res2:6;
        RBus_UInt32  ve2_cmd_grp_disable:1;
        RBus_UInt32  ve2_cmd_queue_flush:1;
        RBus_UInt32  gde2_cmd_grp_disable:1;
        RBus_UInt32  gde2_cmd_queue_flush:1;
        RBus_UInt32  res3:4;
        RBus_UInt32  wfifo_cnt_full_threshold:6;
        RBus_UInt32  res4:2;
    };
}dc2_sys_misc3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_pattern0:32;
    };
}dc2_sfmode0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_pattern1:32;
    };
}dc2_sfmode1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_pattern2:32;
    };
}dc2_sfmode2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_pattern3:32;
    };
}dc2_sfmode3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_cmp_rlt0:32;
    };
}dc2_sfmode_cmp0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_cmp_rlt1:32;
    };
}dc2_sfmode_cmp1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_cmp_rlt2:32;
    };
}dc2_sfmode_cmp2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_cmp_rlt3:32;
    };
}dc2_sfmode_cmp3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  debug_sel_0:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  debug_sel_1:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  debug_en:1;
        RBus_UInt32  debug_sys2:1;
        RBus_UInt32  res3:14;
    };
}dc2_debug_SYS_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_fifo_0_overflow:1;
        RBus_UInt32  read_fifo_1_overflow:1;
        RBus_UInt32  read_fifo_2_overflow:1;
        RBus_UInt32  write_fifo_0_overflow:1;
        RBus_UInt32  write_fifo_1_overflow:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  read_fifo_0_underflow:1;
        RBus_UInt32  read_fifo_1_underflow:1;
        RBus_UInt32  read_fifo_2_underflow:1;
        RBus_UInt32  write_fifo_0_underflow:1;
        RBus_UInt32  write_fifo_1_underflow:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  exsram_fifo_overflow:1;
        RBus_UInt32  exsram_fifo_underflow:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  read_cmd_fifo_0_overflow:1;
        RBus_UInt32  read_cmd_fifo_1_overflow:1;
        RBus_UInt32  read_cmd_fifo_2_overflow:1;
        RBus_UInt32  write_cmd_fifo_0_overflow:1;
        RBus_UInt32  write_cmd_fifo_1_overflow:1;
        RBus_UInt32  read_cmd_fifo_0_underflow:1;
        RBus_UInt32  read_cmd_fifo_1_underflow:1;
        RBus_UInt32  read_cmd_fifo_2_underflow:1;
        RBus_UInt32  write_cmd_fifo_0_underflow:1;
        RBus_UInt32  write_cmd_fifo_1_underflow:1;
        RBus_UInt32  res4:2;
    };
}dc2_debug_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c0_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  c0_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}dc2_priority_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c1_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  c1_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}dc2_priority_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c2_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  c2_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}dc2_priority_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c3_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  c3_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}dc2_priority_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c4_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  c4_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}dc2_priority_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c5_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  c5_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}dc2_priority_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c6_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  c6_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}dc2_priority_ctrl6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c7_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  c7_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}dc2_priority_ctrl7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c8_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  c8_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}dc2_priority_ctrl8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c9_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  c9_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}dc2_priority_ctrl9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ca_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  ca_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}dc2_priority_ctrla_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cb_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  cb_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}dc2_priority_ctrlb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  latcnt_period:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  hie_cmp_dis:12;
        RBus_UInt32  gpu_lat_new:1;
        RBus_UInt32  res2:3;
    };
}dc2_priority_ctrl_hie_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scpu_latcnt:8;
        RBus_UInt32  res1:24;
    };
}dc2_priority_ctrl_scpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  req_mask_index:12;
        RBus_UInt32  res1:20;
    };
}dc2_client_mask_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_go:1;
        RBus_UInt32  res1:31;
    };
}dc2_pc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_tota_mon_num:32;
    };
}dc2_pc_tota_mon_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_tota_ack_num:32;
    };
}dc2_pc_tota_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_tota_idl_num:32;
    };
}dc2_pc_tota_idl_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_sysh_prog0_sel:7;
        RBus_UInt32  write_en_1:1;
        RBus_UInt32  pc_sysh_prog1_sel:7;
        RBus_UInt32  write_en_2:1;
        RBus_UInt32  pc_sysh_prog2_sel:7;
        RBus_UInt32  write_en_3:1;
        RBus_UInt32  res1:8;
    };
}dc2_pc_sysh_prog_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  pc_sysh_prog0_req_occur:1;
        RBus_UInt32  pc_sysh_prog1_req_occur:1;
        RBus_UInt32  pc_sysh_prog2_req_occur:1;
        RBus_UInt32  res2:25;
    };
}dc2_pc_sys_prog_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog0_acc_lat:32;
    };
}dc2_pc_sysh_prog_0_acc_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog0_max_lat:16;
        RBus_UInt32  res1:16;
    };
}dc2_pc_sysh_prog_0_max_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog0_req_num:24;
        RBus_UInt32  res1:8;
    };
}dc2_pc_sysh_prog_0_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog0_ack_num:32;
    };
}dc2_pc_sysh_prog_0_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog1_acc_lat:32;
    };
}dc2_pc_sysh_prog_1_acc_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog1_max_lat:16;
        RBus_UInt32  res1:16;
    };
}dc2_pc_sysh_prog_1_max_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog1_req_num:24;
        RBus_UInt32  res1:8;
    };
}dc2_pc_sysh_prog_1_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog1_ack_num:32;
    };
}dc2_pc_sysh_prog_1_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog2_acc_lat:32;
    };
}dc2_pc_sysh_prog_2_acc_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog2_max_lat:16;
        RBus_UInt32  res1:16;
    };
}dc2_pc_sysh_prog_2_max_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog2_req_num:24;
        RBus_UInt32  res1:8;
    };
}dc2_pc_sysh_prog_2_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog2_ack_num:32;
    };
}dc2_pc_sysh_prog_2_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh0_hitend_cnt:16;
        RBus_UInt32  res1:16;
    };
}dc2_pc_sysh_prog_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh1_hitend_cnt:16;
        RBus_UInt32  res1:16;
    };
}dc2_pc_sysh_prog_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh2_hitend_cnt:16;
        RBus_UInt32  res1:16;
    };
}dc2_pc_sysh_prog_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dc2_bist_mode_pict0:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  res3:27;
    };
}dc2_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dc2_bist_done_pict0:1;
        RBus_UInt32  res2:30;
    };
}dc2_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dc2_bist_fail_group_pict0:1;
        RBus_UInt32  res2:30;
    };
}dc2_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dc2_drf_mode_pict0:1;
        RBus_UInt32  res2:30;
    };
}dc2_bist_drf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dc2_drf_resume_pict0:1;
        RBus_UInt32  res2:30;
    };
}dc2_bist_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dc2_drf_done_pict0:1;
        RBus_UInt32  res2:30;
    };
}dc2_bist0_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dc2_drf_pause_pict0:1;
        RBus_UInt32  res2:30;
    };
}dc2_bist_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dc2_drf_fail_group_pict0:1;
        RBus_UInt32  res2:30;
    };
}dc2_bist_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dc2_bist_pict_fail0:1;
        RBus_UInt32  dc2_drf_pict_fail0:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:24;
    };
}dc2_bist_detail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_0:1;
        RBus_UInt32  rm_1:1;
        RBus_UInt32  rm_2:1;
        RBus_UInt32  rm_3:1;
        RBus_UInt32  rme:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  res2:24;
    };
}dc2_bist_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_reg0:32;
    };
}dc2_dummy_reg0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_reg1:32;
    };
}dc2_dummy_reg1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_reg2:32;
    };
}dc2_dummy_reg2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_reg3:32;
    };
}dc2_dummy_reg3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  mem_type:2;
    };
}dc2_mt_type_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  saddr:26;
        RBus_UInt32  res2:1;
    };
}dc2_mt_saddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  eaddr:26;
        RBus_UInt32  res2:1;
    };
}dc2_mt_eaddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mode:2;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  res1:29;
    };
}dc2_mt_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  module_id_3:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  module_id_2:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  module_id_1:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  module_id_0:7;
        RBus_UInt32  res4:1;
    };
}dc2_mt_table_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd:14;
        RBus_UInt32  module_id:7;
        RBus_UInt32  ever_trap:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  access_type_3:2;
        RBus_UInt32  access_type_2:2;
        RBus_UInt32  access_type_1:2;
        RBus_UInt32  access_type_0:2;
    };
}dc2_mt_addcmd_hi_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd:32;
    };
}dc2_mt_addcmd_lo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  trap_seq_sa:32;
    };
}dc2_mt_addcmd_sa_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disable_cross_range_check:1;
        RBus_UInt32  enable_block_info:1;
        RBus_UInt32  res1:30;
    };
}dc2_mt_misc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  error_cmd_detection_en:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  error_cmd_swap_en:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  error_cmd_swap_addr:27;
        RBus_UInt32  write_enable3:1;
    };
}dc2_ec_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd_hi:22;
        RBus_UInt32  trap_case:8;
        RBus_UInt32  error_cmd_ever_trap:1;
        RBus_UInt32  res1:1;
    };
}dc2_ec_addcmd_hi_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd_lo:32;
    };
}dc2_ec_addcmd_lo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tag_check_en:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:25;
    };
}dc2_rd_tag_check_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  mt_0_mod1_int_en:1;
        RBus_UInt32  mt_0_mod2_int_en:1;
        RBus_UInt32  mt_0_mod3_int_en:1;
        RBus_UInt32  mt_1_mod1_int_en:1;
        RBus_UInt32  mt_1_mod2_int_en:1;
        RBus_UInt32  mt_1_mod3_int_en:1;
        RBus_UInt32  mt_2_mod1_int_en:1;
        RBus_UInt32  mt_2_mod2_int_en:1;
        RBus_UInt32  mt_2_mod3_int_en:1;
        RBus_UInt32  mt_3_mod1_int_en:1;
        RBus_UInt32  mt_3_mod2_int_en:1;
        RBus_UInt32  mt_3_mod3_int_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  err_blk_w_zero_int_en:1;
        RBus_UInt32  err_blk_h_zero_int_en:1;
        RBus_UInt32  err_blk_size_exceed_int_en:1;
        RBus_UInt32  err_blk_8x2_on_64_int_en:1;
        RBus_UInt32  err_seq_bl_odd_int_en:1;
        RBus_UInt32  err_seq_bl_zero_int_en:1;
        RBus_UInt32  err_seq_sa_odd_int_en:1;
        RBus_UInt32  rd_tag_mismatch_int_en:1;
        RBus_UInt32  pic_offset_x_odd_int_en:1;
        RBus_UInt32  res2:7;
    };
}dc2_int_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  mt_0_mod1_int:1;
        RBus_UInt32  mt_0_mod2_int:1;
        RBus_UInt32  mt_0_mod3_int:1;
        RBus_UInt32  mt_1_mod1_int:1;
        RBus_UInt32  mt_1_mod2_int:1;
        RBus_UInt32  mt_1_mod3_int:1;
        RBus_UInt32  mt_2_mod1_int:1;
        RBus_UInt32  mt_2_mod2_int:1;
        RBus_UInt32  mt_2_mod3_int:1;
        RBus_UInt32  mt_3_mod1_int:1;
        RBus_UInt32  mt_3_mod2_int:1;
        RBus_UInt32  mt_3_mod3_int:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  err_blk_w_zero_int:1;
        RBus_UInt32  err_blk_h_zero_int:1;
        RBus_UInt32  err_blk_size_exceed_int:1;
        RBus_UInt32  err_blk_8x2_on_64_int:1;
        RBus_UInt32  err_seq_bl_odd_int:1;
        RBus_UInt32  err_seq_bl_zero_int:1;
        RBus_UInt32  err_seq_sa_odd_int:1;
        RBus_UInt32  rd_tag_mismatch_int:1;
        RBus_UInt32  pic_offset_x_odd_int:1;
        RBus_UInt32  res2:7;
    };
}dc2_int_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bw_en:12;
        RBus_UInt32  res1:20;
    };
}dc2_bw_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  value:32;
    };
}dc2_bw_timer_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  value:24;
        RBus_UInt32  res1:8;
    };
}dc2_bw_request_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tv_sb2_mux:1;
        RBus_UInt32  tv_sb4_mux:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  pre_tra_wr_cnt:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_tra_rd_cnt:10;
        RBus_UInt32  res3:2;
    };
}dc2_sys2_mux_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd:14;
        RBus_UInt32  module_id:7;
        RBus_UInt32  ever_trap:1;
        RBus_UInt32  res1:10;
    };
}dc2_mt_addcmd_hi_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd:32;
    };
}dc2_mt_addcmd_lo_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  trap_seq_sa:32;
    };
}dc2_mt_addcmd_sa_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd_hi:22;
        RBus_UInt32  trap_case:8;
        RBus_UInt32  error_cmd_ever_trap:1;
        RBus_UInt32  res1:1;
    };
}dc2_ec_addcmd_hi_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd_lo:32;
    };
}dc2_ec_addcmd_lo_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  mt_0_mod1_int_en:1;
        RBus_UInt32  mt_0_mod2_int_en:1;
        RBus_UInt32  mt_0_mod3_int_en:1;
        RBus_UInt32  mt_1_mod1_int_en:1;
        RBus_UInt32  mt_1_mod2_int_en:1;
        RBus_UInt32  mt_1_mod3_int_en:1;
        RBus_UInt32  mt_2_mod1_int_en:1;
        RBus_UInt32  mt_2_mod2_int_en:1;
        RBus_UInt32  mt_2_mod3_int_en:1;
        RBus_UInt32  mt_3_mod1_int_en:1;
        RBus_UInt32  mt_3_mod2_int_en:1;
        RBus_UInt32  mt_3_mod3_int_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  err_blk_w_zero_int_en:1;
        RBus_UInt32  err_blk_h_zero_int_en:1;
        RBus_UInt32  err_blk_size_exceed_int_en:1;
        RBus_UInt32  err_blk_8x2_on_64_int_en:1;
        RBus_UInt32  err_seq_bl_odd_int_en:1;
        RBus_UInt32  err_seq_bl_zero_int_en:1;
        RBus_UInt32  err_seq_sa_odd_int_en:1;
        RBus_UInt32  rd_tag_mismatch_int_en:1;
        RBus_UInt32  res2:8;
    };
}dc2_int_enable_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  mt_0_mod1_int:1;
        RBus_UInt32  mt_0_mod2_int:1;
        RBus_UInt32  mt_0_mod3_int:1;
        RBus_UInt32  mt_1_mod1_int:1;
        RBus_UInt32  mt_1_mod2_int:1;
        RBus_UInt32  mt_1_mod3_int:1;
        RBus_UInt32  mt_2_mod1_int:1;
        RBus_UInt32  mt_2_mod2_int:1;
        RBus_UInt32  mt_2_mod3_int:1;
        RBus_UInt32  mt_3_mod1_int:1;
        RBus_UInt32  mt_3_mod2_int:1;
        RBus_UInt32  mt_3_mod3_int:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  err_blk_w_zero_int:1;
        RBus_UInt32  err_blk_h_zero_int:1;
        RBus_UInt32  err_blk_size_exceed_int:1;
        RBus_UInt32  err_blk_8x2_on_64_int:1;
        RBus_UInt32  err_seq_bl_odd_int:1;
        RBus_UInt32  err_seq_bl_zero_int:1;
        RBus_UInt32  err_seq_sa_odd_int:1;
        RBus_UInt32  rd_tag_mismatch_int:1;
        RBus_UInt32  res2:8;
    };
}dc2_int_status_sys2_RBUS;




#endif 


#endif 
