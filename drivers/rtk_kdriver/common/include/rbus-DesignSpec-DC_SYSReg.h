/**
* @file rbusMagellan2-DesignSpec-DC_SYSReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015-2-5
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_MAGELLAN2_DESIGNSPEC_DC_SYS_REG_H_
#define _RBUS_MAGELLAN2_DESIGNSPEC_DC_SYS_REG_H_

#include "rbus_types.h"



//  MAGELLAN2-DESIGNSPEC-DC_SYS Register Address



#define  DC_PICT_SET_VADDR                                  	(0xb8007000)
#define  DC_SYS_MISC_VADDR                                  	(0xb8007004)
#define  DC_PIC_OFFSET_X_DETECTION_VADDR                    	(0xb8007010)
#define  DC_PICT_SET_OFFSET_VADDR                           	(0xb8007020)
#define  DC_REQ_STATUS_VADDR                                	(0xb8007024)
#define  DC_SYS_MISC2_VADDR                                 	(0xb8007028)
#define  DC_SYS_MISC3_VADDR                                 	(0xb800702c)
#define  DC_SYS_MISC4_VADDR                                 	(0xb8007030)
#define  DC_SFMODE0_VADDR                                   	(0xb8007040)
#define  DC_SFMODE1_VADDR                                   	(0xb8007044)
#define  DC_SFMODE2_VADDR                                   	(0xb8007048)
#define  DC_SFMODE3_VADDR                                   	(0xb800704c)
#define  DC_SFMODE_CMP0_VADDR                               	(0xb8007050)
#define  DC_SFMODE_CMP1_VADDR                               	(0xb8007054)
#define  DC_SFMODE_CMP2_VADDR                               	(0xb8007058)
#define  DC_SFMODE_CMP3_VADDR                               	(0xb800705c)
#define  DC_DEBUG_CTRL_VADDR                                	(0xb8007060)
#define  DC_DEBUG_STATUS_VADDR                              	(0xb8007064)
#define  DC_DEBUG_OUT_VADDR                                 	(0xb8007068)
#define  DC_PRIORITY_CTRL0_VADDR                            	(0xb8007080)
#define  DC_PRIORITY_CTRL1_VADDR                            	(0xb8007084)
#define  DC_PRIORITY_CTRL2_VADDR                            	(0xb8007088)
#define  DC_PRIORITY_CTRL3_VADDR                            	(0xb800708c)
#define  DC_PRIORITY_CTRL4_VADDR                            	(0xb8007090)
#define  DC_PRIORITY_CTRL5_VADDR                            	(0xb8007094)
#define  DC_PRIORITY_CTRL6_VADDR                            	(0xb8007098)
#define  DC_PRIORITY_CTRL7_VADDR                            	(0xb800709c)
#define  DC_PRIORITY_CTRL8_VADDR                            	(0xb80070a0)
#define  DC_PRIORITY_CTRL9_VADDR                            	(0xb80070a4)
#define  DC_PRIORITY_CTRLA_VADDR                            	(0xb80070a8)
#define  DC_PRIORITY_CTRLB_VADDR                            	(0xb80070ac)
#define  DC_PRIORITY_CTRLC_VADDR                            	(0xb80070b0)
#define  DC_PRIORITY_CTRL_HIE_VADDR                         	(0xb80070b4)
#define  DC_CLIENT_MASK_VADDR                               	(0xb80070d0)
#define  DC_PC_CTRL_VADDR                                   	(0xb8007100)
#define  DC_PC_TOTA_MON_NUM_VADDR                           	(0xb8007104)
#define  DC_PC_TOTA_ACK_NUM_VADDR                           	(0xb8007108)
#define  DC_PC_TOTA_IDL_NUM_VADDR                           	(0xb800710c)
#define  DC_PC_SYSH_PROG_CTRL_VADDR                         	(0xb8007110)
#define  DC_PC_SYS_PROG_CTRL1_VADDR                         	(0xb8007120)
#define  DC_PC_SYSH_PROG_0_ACC_LAT_VADDR                    	(0xb8007130)
#define  DC_PC_SYSH_PROG_0_MAX_LAT_VADDR                    	(0xb8007134)
#define  DC_PC_SYSH_PROG_0_REQ_NUM_VADDR                    	(0xb8007138)
#define  DC_PC_SYSH_PROG_0_ACK_NUM_VADDR                    	(0xb800713c)
#define  DC_PC_SYSH_PROG_1_ACC_LAT_VADDR                    	(0xb8007140)
#define  DC_PC_SYSH_PROG_1_MAX_LAT_VADDR                    	(0xb8007144)
#define  DC_PC_SYSH_PROG_1_REQ_NUM_VADDR                    	(0xb8007148)
#define  DC_PC_SYSH_PROG_1_ACK_NUM_VADDR                    	(0xb800714c)
#define  DC_PC_SYSH_PROG_2_ACC_LAT_VADDR                    	(0xb8007150)
#define  DC_PC_SYSH_PROG_2_MAX_LAT_VADDR                    	(0xb8007154)
#define  DC_PC_SYSH_PROG_2_REQ_NUM_VADDR                    	(0xb8007158)
#define  DC_PC_SYSH_PROG_2_ACK_NUM_VADDR                    	(0xb800715c)
#define  DC_PC_SYSH_PROG_0_VADDR                            	(0xb8007190)
#define  DC_PC_SYSH_PROG_1_VADDR                            	(0xb8007194)
#define  DC_PC_SYSH_PROG_2_VADDR                            	(0xb8007198)
#define  DC_BIST_MODE_VADDR                                 	(0xb80071c0)
#define  DC_BIST_DONE_VADDR                                 	(0xb80071c4)
#define  DC_BIST_FAIL_VADDR                                 	(0xb80071c8)
#define  DC_BIST_DRF_VADDR                                  	(0xb80071cc)
#define  DC_BIST_RESUME_VADDR                               	(0xb80071d0)
#define  DC_BIST0_DRF_DONE_VADDR                            	(0xb80071d4)
#define  DC_BIST_DRF_PAUSE_VADDR                            	(0xb80071d8)
#define  DC_BIST_DRF_FAIL_VADDR                             	(0xb80071dc)
#define  DC_BIST_DETAIL_VADDR                               	(0xb80071e0)
#define  DC_BIST_RM_VADDR                                   	(0xb80071e4)
#define  DC_DUMMY_REG0_VADDR                                	(0xb80071f0)
#define  DC_DUMMY_REG1_VADDR                                	(0xb80071f4)
#define  DC_DUMMY_REG2_VADDR                                	(0xb80071f8)
#define  DC_DUMMY_REG3_VADDR                                	(0xb80071fc)
#define  DC_MT_TYPE_VADDR                                   	(0xb8007200)
#define  DC_MT_SADDR_VADDR                                  	(0xb8007210)
#define  DC_MT_EADDR_VADDR                                  	(0xb8007220)
#define  DC_MT_MODE_VADDR                                   	(0xb8007240)
#define  DC_MT_TABLE_VADDR                                  	(0xb8007260)
#define  DC_MT_ADDCMD_HI_VADDR                              	(0xb8007280)
#define  DC_MT_ADDCMD_LO_VADDR                              	(0xb80072a0)
#define  DC_MT_ADDCMD_SA_VADDR                              	(0xb80072b0)
#define  DC_MT_MISC_VADDR                                   	(0xb80072c0)
#define  DC_EC_CTRL_VADDR                                   	(0xb80072d0)
#define  DC_EC_ADDCMD_HI_VADDR                              	(0xb80072d4)
#define  DC_EC_ADDCMD_LO_VADDR                              	(0xb80072d8)
#define  DC_RD_TAG_CHECK_VADDR                              	(0xb80072dc)
#define  DC_INT_ENABLE_VADDR                                	(0xb80072e8)
#define  DC_INT_STATUS_VADDR                                	(0xb80072ec)
#define  BW_CTRL_VADDR                                      	(0xb8007300)
#define  BW_TIMER_THRESHOLD_VADDR                           	(0xb8007304)
#define  BW_REQUEST_THRESHOLD_VADDR                         	(0xb8007334)
#define  DC_SYS2_MUX_VADDR                                  	(0xb8007400)
#define  DC_MT_ADDCMD_HI_SYS2_VADDR                         	(0xb8007410)
#define  DC_MT_ADDCMD_LO_SYS2_VADDR                         	(0xb8007420)
#define  DC_MT_ADDCMD_SA_SYS2_VADDR                         	(0xb8007430)
#define  DC_EC_ADDCMD_HI_SYS2_VADDR                         	(0xb8007440)
#define  DC_EC_ADDCMD_LO_SYS2_VADDR                         	(0xb8007444)
#define  DC_INT_ENABLE_SYS2_VADDR                           	(0xb800744c)
#define  DC_INT_STATUS_SYS2_VADDR                           	(0xb8007450)
#define  DC_SYS3_MUX_VADDR                                  	(0xb8007480)
#define  DC_MT_ADDCMD_HI_SYS3_VADDR                         	(0xb8007490)
#define  DC_MT_ADDCMD_LO_SYS3_VADDR                         	(0xb80074a0)
#define  DC_MT_ADDCMD_SA_SYS3_VADDR                         	(0xb80074b0)
#define  DC_EC_ADDCMD_HI_SYS3_VADDR                         	(0xb80074c0)
#define  DC_EC_ADDCMD_LO_SYS3_VADDR                         	(0xb80074c4)
#define  DC_INT_ENABLE_SYS3_VADDR                           	(0xb80074cc)
#define  DC_INT_STATUS_SYS3_VADDR                           	(0xb80074d0)
#define  DC_MTEX_TYPE_VADDR                                 	(0xb8007600)
#define  DC_MTEX_SADDR_VADDR                                	(0xb8007610)
#define  DC_MTEX_EADDR_VADDR                                	(0xb8007620)
#define  DC_MTEX_MODE_VADDR                                 	(0xb8007640)
#define  DC_MTEX_TABLE0_VADDR                               	(0xb8007660)
#define  DC_MTEX_TABLE1_VADDR                               	(0xb8007670)
#define  DC_MTEX_ADDCMD_HI0_VADDR                           	(0xb8007680)
#define  DC_MTEX_ADDCMD_HI1_VADDR                           	(0xb8007690)
#define  DC_MTEX_ADDCMD_LO_VADDR                            	(0xb80076a0)
#define  DC_MTEX_ADDCMD_SA_VADDR                            	(0xb80076b0)
#define  DC_MTEX_ADDCMD_HI0_SYS2_VADDR                      	(0xb80076c0)
#define  DC_MTEX_ADDCMD_LO_SYS2_VADDR                       	(0xb80076d0)
#define  DC_MTEX_ADDCMD_SA_SYS2_VADDR                       	(0xb80076e0)
#define  DC_MTEX_ADDCMD_HI0_SYS3_VADDR                      	(0xb80076f0)
#define  DC_MTEX_ADDCMD_LO_SYS3_VADDR                       	(0xb8007700)
#define  DC_MTEX_ADDCMD_SA_SYS3_VADDR                       	(0xb8007710)
#define  DC_MTEX_INT_ENABLE_VADDR                           	(0xb8007720)
#define  DC_MTEX_INT_STATUS_VADDR                           	(0xb8007724)
#define  DC_MTEX_INT_ENABLE_SYS2_VADDR                      	(0xb8007730)
#define  DC_MTEX_INT_STATUS_SYS2_VADDR                      	(0xb8007734)
#define  DC_MTEX_INT_ENABLE_SYS3_VADDR                      	(0xb8007740)
#define  DC_MTEX_INT_STATUS_SYS3_VADDR                      	(0xb8007744)

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======MAGELLAN2-DESIGNSPEC-DC_SYS register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  pict_width_scale:6;
        RBus_UInt32  pict_init_page:17;
    };
}dc_pict_set_RBUS;

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
}dc_sys_misc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  enable:1;
    };
}dc_pic_offset_x_detection_RBUS;

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
}dc_pict_set_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  req_pending:1;
        RBus_UInt32  req_id:12;
    };
}dc_req_status_RBUS;

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
}dc_sys_misc2_RBUS;

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
}dc_sys_misc3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_pattern0:32;
    };
}dc_sfmode0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_pattern1:32;
    };
}dc_sfmode1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_pattern2:32;
    };
}dc_sfmode2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_pattern3:32;
    };
}dc_sfmode3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_cmp_rlt0:32;
    };
}dc_sfmode_cmp0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_cmp_rlt1:32;
    };
}dc_sfmode_cmp1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_cmp_rlt2:32;
    };
}dc_sfmode_cmp2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_cmp_rlt3:32;
    };
}dc_sfmode_cmp3_RBUS;

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
}dc_debug_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  c0_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  c0_latcnt_beg:8;
    };
}dc_priority_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  c1_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  c1_latcnt_beg:8;
    };
}dc_priority_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  c2_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  c2_latcnt_beg:8;
    };
}dc_priority_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  c3_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  c3_latcnt_beg:8;
    };
}dc_priority_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  c4_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  c4_latcnt_beg:8;
    };
}dc_priority_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  c5_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  c5_latcnt_beg:8;
    };
}dc_priority_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  c6_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  c6_latcnt_beg:8;
    };
}dc_priority_ctrl6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  c7_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  c7_latcnt_beg:8;
    };
}dc_priority_ctrl7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  c8_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  c8_latcnt_beg:8;
    };
}dc_priority_ctrl8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  c9_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  c9_latcnt_beg:8;
    };
}dc_priority_ctrl9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ca_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  ca_latcnt_beg:8;
    };
}dc_priority_ctrla_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cb_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  cb_latcnt_beg:8;
    };
}dc_priority_ctrlb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  req_mask_index:12;
    };
}dc_client_mask_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  pc_go:1;
    };
}dc_pc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_tota_mon_num:32;
    };
}dc_pc_tota_mon_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_tota_ack_num:32;
    };
}dc_pc_tota_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_tota_idl_num:32;
    };
}dc_pc_tota_idl_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  write_en_3:1;
        RBus_UInt32  pc_sysh_prog2_sel:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  write_en_2:1;
        RBus_UInt32  pc_sysh_prog1_sel:4;
        RBus_UInt32  res3:3;
        RBus_UInt32  write_en_1:1;
        RBus_UInt32  pc_sysh_prog0_sel:4;
        RBus_UInt32  res4:3;
    };
}dc_pc_sysh_prog_ctrl_RBUS;

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
}dc_pc_sys_prog_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog0_acc_lat:32;
    };
}dc_pc_sysh_prog_0_acc_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sysh_prog0_max_lat:16;
    };
}dc_pc_sysh_prog_0_max_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sysh_prog0_req_num:24;
    };
}dc_pc_sysh_prog_0_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog0_ack_num:32;
    };
}dc_pc_sysh_prog_0_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog1_acc_lat:32;
    };
}dc_pc_sysh_prog_1_acc_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sysh_prog1_max_lat:16;
    };
}dc_pc_sysh_prog_1_max_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sysh_prog1_req_num:24;
    };
}dc_pc_sysh_prog_1_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog1_ack_num:32;
    };
}dc_pc_sysh_prog_1_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog2_acc_lat:32;
    };
}dc_pc_sysh_prog_2_acc_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sysh_prog2_max_lat:16;
    };
}dc_pc_sysh_prog_2_max_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sysh_prog2_req_num:24;
    };
}dc_pc_sysh_prog_2_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog2_ack_num:32;
    };
}dc_pc_sysh_prog_2_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sysh0_hitend_cnt:16;
    };
}dc_pc_sysh_prog_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sysh1_hitend_cnt:16;
    };
}dc_pc_sysh_prog_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sysh2_hitend_cnt:16;
    };
}dc_pc_sysh_prog_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  res2:3;
        RBus_UInt32  dc_bist_mode_pict0:1;
        RBus_UInt32  res3:1;
    };
}dc_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  dc_bist_done_pict0:1;
        RBus_UInt32  res2:1;
    };
}dc_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  dc_bist_fail_group_pict0:1;
        RBus_UInt32  res2:1;
    };
}dc_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  dc_drf_mode_pict0:1;
        RBus_UInt32  res2:1;
    };
}dc_bist_drf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  dc_drf_resume_pict0:1;
        RBus_UInt32  res2:1;
    };
}dc_bist_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  dc_drf_done_pict0:1;
        RBus_UInt32  res2:1;
    };
}dc_bist0_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  dc_drf_pause_pict0:1;
        RBus_UInt32  res2:1;
    };
}dc_bist_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  dc_drf_fail_group_pict0:1;
        RBus_UInt32  res2:1;
    };
}dc_bist_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  dc_drf_pict_fail0:1;
        RBus_UInt32  dc_bist_pict_fail0:1;
        RBus_UInt32  res4:4;
    };
}dc_bist_detail_RBUS;

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
}dc_bist_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_reg0:32;
    };
}dc_dummy_reg0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_reg1:32;
    };
}dc_dummy_reg1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_reg2:32;
    };
}dc_dummy_reg2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_reg3:32;
    };
}dc_dummy_reg3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mem_type:2;
        RBus_UInt32  res1:30;
    };
}dc_mt_type_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  saddr:26;
        RBus_UInt32  res2:5;
    };
}dc_mt_saddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  eaddr:26;
        RBus_UInt32  res2:5;
    };
}dc_mt_eaddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  mode:2;
    };
}dc_mt_mode_RBUS;

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
}dc_mt_table_RBUS;

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
}dc_mt_addcmd_hi_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd:32;
    };
}dc_mt_addcmd_lo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  trap_seq_sa:32;
    };
}dc_mt_addcmd_sa_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  enable_block_info:1;
        RBus_UInt32  disable_cross_range_check:1;
    };
}dc_mt_misc_RBUS;

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
}dc_ec_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  error_cmd_ever_trap:1;
        RBus_UInt32  trap_case:8;
        RBus_UInt32  addcmd_hi:22;
    };
}dc_ec_addcmd_hi_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd_lo:32;
    };
}dc_ec_addcmd_lo_RBUS;

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
}dc_rd_tag_check_RBUS;

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
}dc_int_enable_RBUS;

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
}dc_int_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  bw_en:12;
    };
}bw_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  value:32;
    };
}bw_timer_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  value:24;
    };
}bw_request_threshold_RBUS;

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
}dc_sys2_mux_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  ever_trap:1;
        RBus_UInt32  module_id:7;
        RBus_UInt32  addcmd:14;
    };
}dc_mt_addcmd_hi_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd:32;
    };
}dc_mt_addcmd_lo_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  trap_seq_sa:32;
    };
}dc_mt_addcmd_sa_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  error_cmd_ever_trap:1;
        RBus_UInt32  trap_case:8;
        RBus_UInt32  addcmd_hi:22;
    };
}dc_ec_addcmd_hi_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd_lo:32;
    };
}dc_ec_addcmd_lo_sys2_RBUS;

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
}dc_int_enable_sys2_RBUS;

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
}dc_int_status_sys2_RBUS;

#else //apply LITTLE_ENDIAN

//======MAGELLAN2-DESIGNSPEC-DC_SYS register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pict_init_page:17;
        RBus_UInt32  pict_width_scale:6;
        RBus_UInt32  res1:9;
    };
}dc_pict_set_RBUS;

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
}dc_sys_misc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  enable:1;
        RBus_UInt32  res1:31;
    };
}dc_pic_offset_x_detection_RBUS;

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
}dc_pict_set_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  req_id:12;
        RBus_UInt32  req_pending:1;
        RBus_UInt32  res1:19;
    };
}dc_req_status_RBUS;

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
}dc_sys_misc2_RBUS;

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
}dc_sys_misc3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_pattern0:32;
    };
}dc_sfmode0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_pattern1:32;
    };
}dc_sfmode1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_pattern2:32;
    };
}dc_sfmode2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_pattern3:32;
    };
}dc_sfmode3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_cmp_rlt0:32;
    };
}dc_sfmode_cmp0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_cmp_rlt1:32;
    };
}dc_sfmode_cmp1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_cmp_rlt2:32;
    };
}dc_sfmode_cmp2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_cmp_rlt3:32;
    };
}dc_sfmode_cmp3_RBUS;

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
}dc_debug_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c0_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  c0_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}dc_priority_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c1_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  c1_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}dc_priority_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c2_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  c2_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}dc_priority_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c3_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  c3_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}dc_priority_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c4_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  c4_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}dc_priority_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c5_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  c5_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}dc_priority_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c6_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  c6_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}dc_priority_ctrl6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c7_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  c7_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}dc_priority_ctrl7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c8_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  c8_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}dc_priority_ctrl8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c9_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  c9_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}dc_priority_ctrl9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ca_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  ca_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}dc_priority_ctrla_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cb_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  cb_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}dc_priority_ctrlb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  req_mask_index:12;
        RBus_UInt32  res1:20;
    };
}dc_client_mask_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_go:1;
        RBus_UInt32  res1:31;
    };
}dc_pc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_tota_mon_num:32;
    };
}dc_pc_tota_mon_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_tota_ack_num:32;
    };
}dc_pc_tota_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_tota_idl_num:32;
    };
}dc_pc_tota_idl_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res4:3;
        RBus_UInt32  pc_sysh_prog0_sel:4;
        RBus_UInt32  write_en_1:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  pc_sysh_prog1_sel:4;
        RBus_UInt32  write_en_2:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  pc_sysh_prog2_sel:4;
        RBus_UInt32  write_en_3:1;
        RBus_UInt32  res1:8;
    };
}dc_pc_sysh_prog_ctrl_RBUS;

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
}dc_pc_sys_prog_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog0_acc_lat:32;
    };
}dc_pc_sysh_prog_0_acc_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog0_max_lat:16;
        RBus_UInt32  res1:16;
    };
}dc_pc_sysh_prog_0_max_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog0_req_num:24;
        RBus_UInt32  res1:8;
    };
}dc_pc_sysh_prog_0_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog0_ack_num:32;
    };
}dc_pc_sysh_prog_0_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog1_acc_lat:32;
    };
}dc_pc_sysh_prog_1_acc_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog1_max_lat:16;
        RBus_UInt32  res1:16;
    };
}dc_pc_sysh_prog_1_max_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog1_req_num:24;
        RBus_UInt32  res1:8;
    };
}dc_pc_sysh_prog_1_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog1_ack_num:32;
    };
}dc_pc_sysh_prog_1_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog2_acc_lat:32;
    };
}dc_pc_sysh_prog_2_acc_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog2_max_lat:16;
        RBus_UInt32  res1:16;
    };
}dc_pc_sysh_prog_2_max_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog2_req_num:24;
        RBus_UInt32  res1:8;
    };
}dc_pc_sysh_prog_2_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog2_ack_num:32;
    };
}dc_pc_sysh_prog_2_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh0_hitend_cnt:16;
        RBus_UInt32  res1:16;
    };
}dc_pc_sysh_prog_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh1_hitend_cnt:16;
        RBus_UInt32  res1:16;
    };
}dc_pc_sysh_prog_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh2_hitend_cnt:16;
        RBus_UInt32  res1:16;
    };
}dc_pc_sysh_prog_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dc_bist_mode_pict0:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  res3:27;
    };
}dc_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dc_bist_done_pict0:1;
        RBus_UInt32  res2:30;
    };
}dc_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dc_bist_fail_group_pict0:1;
        RBus_UInt32  res2:30;
    };
}dc_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dc_drf_mode_pict0:1;
        RBus_UInt32  res2:30;
    };
}dc_bist_drf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dc_drf_resume_pict0:1;
        RBus_UInt32  res2:30;
    };
}dc_bist_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dc_drf_done_pict0:1;
        RBus_UInt32  res2:30;
    };
}dc_bist0_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dc_drf_pause_pict0:1;
        RBus_UInt32  res2:30;
    };
}dc_bist_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dc_drf_fail_group_pict0:1;
        RBus_UInt32  res2:30;
    };
}dc_bist_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dc_bist_pict_fail0:1;
        RBus_UInt32  dc_drf_pict_fail0:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:24;
    };
}dc_bist_detail_RBUS;

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
}dc_bist_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_reg0:32;
    };
}dc_dummy_reg0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_reg1:32;
    };
}dc_dummy_reg1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_reg2:32;
    };
}dc_dummy_reg2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_reg3:32;
    };
}dc_dummy_reg3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  mem_type:2;
    };
}dc_mt_type_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  saddr:26;
        RBus_UInt32  res2:1;
    };
}dc_mt_saddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  eaddr:26;
        RBus_UInt32  res2:1;
    };
}dc_mt_eaddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mode:2;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  res1:29;
    };
}dc_mt_mode_RBUS;

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
}dc_mt_table_RBUS;

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
}dc_mt_addcmd_hi_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd:32;
    };
}dc_mt_addcmd_lo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  trap_seq_sa:32;
    };
}dc_mt_addcmd_sa_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disable_cross_range_check:1;
        RBus_UInt32  enable_block_info:1;
        RBus_UInt32  res1:30;
    };
}dc_mt_misc_RBUS;

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
}dc_ec_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd_hi:22;
        RBus_UInt32  trap_case:8;
        RBus_UInt32  error_cmd_ever_trap:1;
        RBus_UInt32  res1:1;
    };
}dc_ec_addcmd_hi_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd_lo:32;
    };
}dc_ec_addcmd_lo_RBUS;

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
}dc_rd_tag_check_RBUS;

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
}dc_int_enable_RBUS;

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
}dc_int_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bw_en:12;
        RBus_UInt32  res1:20;
    };
}bw_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  value:32;
    };
}bw_timer_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  value:24;
        RBus_UInt32  res1:8;
    };
}bw_request_threshold_RBUS;

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
}dc_sys2_mux_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd:14;
        RBus_UInt32  module_id:7;
        RBus_UInt32  ever_trap:1;
        RBus_UInt32  res1:10;
    };
}dc_mt_addcmd_hi_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd:32;
    };
}dc_mt_addcmd_lo_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  trap_seq_sa:32;
    };
}dc_mt_addcmd_sa_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd_hi:22;
        RBus_UInt32  trap_case:8;
        RBus_UInt32  error_cmd_ever_trap:1;
        RBus_UInt32  res1:1;
    };
}dc_ec_addcmd_hi_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd_lo:32;
    };
}dc_ec_addcmd_lo_sys2_RBUS;

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
}dc_int_enable_sys2_RBUS;

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
}dc_int_status_sys2_RBUS;




#endif 


#endif 
