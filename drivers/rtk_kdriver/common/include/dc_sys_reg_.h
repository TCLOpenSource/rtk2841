/**************************************************************
// Spec Version                  : 0.25
// Parser Version                : DVR_Parser_6.11(120105)
// CModelGen Version             : 5.1 2012.01.05
// Naming Rule                   :  Module_Register_Name
// Naming Rule                   : Module_Register_Name_reg
// Parse Option                  : Only Parse _op1
// Parse Address Region          : All Address Region
// Decode bit number             : 12 bits
// Firmware Header Generate Date : 2014/7/10 20:10:1
***************************************************************/


#ifndef _REG_H_INCLUDED_
#define _REG_H_INCLUDED_
#ifdef  _USE_STRUCT
typedef struct
{
unsigned int     reserved_0:9;
unsigned int     pict_width_scale:6;
unsigned int     pict_init_page:17;
}DC_PICT_SET;

typedef struct
{
unsigned int     reserved_0:3;
unsigned int     dram_8g_used:1;
unsigned int     dram_4g_used:1;
unsigned int     ddr3_512_used:1;
unsigned int     dram_2g_used:1;
unsigned int     pre_arb_scheme_sel:1;
unsigned int     arb_mask_all_en:1;
unsigned int     ddr3_mapping_en:1;
unsigned int     reserved_1:1;
unsigned int     self_lookback_mode:1;
unsigned int     mem_num:1;
unsigned int     reserved_2:1;
unsigned int     page_size:2;
unsigned int     reserved_3:6;
unsigned int     max_bl_size:1;
unsigned int     en_max_bl_limit:1;
unsigned int     small_dram_4g:1;
unsigned int     small_dram_2g:1;
unsigned int     small_dram_1g:1;
unsigned int     small_dram_512m:1;
unsigned int     reserved_4:3;
unsigned int     en_2ddr_diff_size:1;
}MISC;

typedef struct
{
unsigned int     reserved_0:31;
unsigned int     enable:1;
}DC_PIC_OFFSET_X_DETECTION;

typedef struct
{
unsigned int     pict_set_num:8;
unsigned int     pict_offset_rd:1;
unsigned int     reserved_0:2;
unsigned int     pict_set_wide:1;
unsigned int     pict_set_offset_y:10;
unsigned int     pict_set_offset_x:10;
}DC_PICT_SET_OFFSET;

typedef struct
{
unsigned int     reserved_0:19;
unsigned int     req_pending:1;
unsigned int     req_id:12;
}DC_REQ_STATUS;

typedef struct
{
unsigned int     pre_arb_merge:1;
unsigned int     reserved_0:2;
unsigned int     qfifo_cnt_full_threshold:5;
unsigned int     full_cmd_count:4;
unsigned int     pre_tra_rd_cnt:10;
unsigned int     pre_tra_wr_cnt:10;
}MISC2;

typedef struct
{
unsigned int     reserved_0:2;
unsigned int     wfifo_cnt_full_threshold:6;
unsigned int     reserved_1:4;
unsigned int     gde2_cmd_queue_flush:1;
unsigned int     gde2_cmd_grp_disable:1;
unsigned int     ve2_cmd_queue_flush:1;
unsigned int     ve2_cmd_grp_disable:1;
unsigned int     reserved_2:6;
unsigned int     ve_cmd_queue_flush:1;
unsigned int     ve_cmd_grp_disable:1;
unsigned int     tvsb4_cmd_queue_flush:1;
unsigned int     tvsb4_cmd_grp_disable:1;
unsigned int     tvsb3_cmd_queue_flush:1;
unsigned int     tvsb3_cmd_grp_disable:1;
unsigned int     reserved_3:1;
unsigned int     enable_arb_delay_by_tv_sb1_grant:1;
unsigned int     gde_cmd_queue_flush:1;
unsigned int     gde_cmd_grp_disable:1;
}MISC3;

typedef struct
{
unsigned int     sfmode_pattern0:32;
}DC_SFMODE0;

typedef struct
{
unsigned int     sfmode_pattern1:32;
}DC_SFMODE1;

typedef struct
{
unsigned int     sfmode_pattern2:32;
}DC_SFMODE2;

typedef struct
{
unsigned int     sfmode_pattern3:32;
}DC_SFMODE3;

typedef struct
{
unsigned int     sfmode_cmp_rlt0:32;
}DC_SFMODE_CMP0;

typedef struct
{
unsigned int     sfmode_cmp_rlt1:32;
}DC_SFMODE_CMP1;

typedef struct
{
unsigned int     sfmode_cmp_rlt2:32;
}DC_SFMODE_CMP2;

typedef struct
{
unsigned int     sfmode_cmp_rlt3:32;
}DC_SFMODE_CMP3;

typedef struct
{
unsigned int     reserved_0:14;
unsigned int     Debug_sys2:1;
unsigned int     Debug_en:1;
unsigned int     reserved_1:2;
unsigned int     Debug_sel_1:6;
unsigned int     reserved_2:2;
unsigned int     Debug_sel_0:6;
}DC_DEBUG;

typedef struct
{
unsigned int     reserved_0:2;
unsigned int     write_cmd_fifo_1_underflow:1;
unsigned int     write_cmd_fifo_0_underflow:1;
unsigned int     read_cmd_fifo_2_underflow:1;
unsigned int     read_cmd_fifo_1_underflow:1;
unsigned int     read_cmd_fifo_0_underflow:1;
unsigned int     write_cmd_fifo_1_overflow:1;
unsigned int     write_cmd_fifo_0_overflow:1;
unsigned int     read_cmd_fifo_2_overflow:1;
unsigned int     read_cmd_fifo_1_overflow:1;
unsigned int     read_cmd_fifo_0_overflow:1;
unsigned int     reserved_1:2;
unsigned int     exsram_fifo_underflow:1;
unsigned int     exsram_fifo_overflow:1;
unsigned int     reserved_2:3;
unsigned int     write_fifo_1_underflow:1;
unsigned int     write_fifo_0_underflow:1;
unsigned int     read_fifo_2_underflow:1;
unsigned int     read_fifo_1_underflow:1;
unsigned int     read_fifo_0_underflow:1;
unsigned int     reserved_3:3;
unsigned int     write_fifo_1_overflow:1;
unsigned int     write_fifo_0_overflow:1;
unsigned int     read_fifo_2_overflow:1;
unsigned int     read_fifo_1_overflow:1;
unsigned int     read_fifo_0_overflow:1;
}DC_DEBUG_STATUS;

typedef struct
{
unsigned int     reserved_0:8;
unsigned int     C0_LATCNT_END:8;
unsigned int     reserved_1:8;
unsigned int     C0_LATCNT_BEG:8;
}DC_PRIORITY_CTRL0;

typedef struct
{
unsigned int     reserved_0:8;
unsigned int     C1_LATCNT_END:8;
unsigned int     reserved_1:8;
unsigned int     C1_LATCNT_BEG:8;
}DC_PRIORITY_CTRL1;

typedef struct
{
unsigned int     reserved_0:8;
unsigned int     C2_LATCNT_END:8;
unsigned int     reserved_1:8;
unsigned int     C2_LATCNT_BEG:8;
}DC_PRIORITY_CTRL2;

typedef struct
{
unsigned int     reserved_0:8;
unsigned int     C3_LATCNT_END:8;
unsigned int     reserved_1:8;
unsigned int     C3_LATCNT_BEG:8;
}DC_PRIORITY_CTRL3;

typedef struct
{
unsigned int     reserved_0:8;
unsigned int     C4_LATCNT_END:8;
unsigned int     reserved_1:8;
unsigned int     C4_LATCNT_BEG:8;
}DC_PRIORITY_CTRL4;

typedef struct
{
unsigned int     reserved_0:8;
unsigned int     C5_LATCNT_END:8;
unsigned int     reserved_1:8;
unsigned int     C5_LATCNT_BEG:8;
}DC_PRIORITY_CTRL5;

typedef struct
{
unsigned int     reserved_0:8;
unsigned int     C6_LATCNT_END:8;
unsigned int     reserved_1:8;
unsigned int     C6_LATCNT_BEG:8;
}DC_PRIORITY_CTRL6;

typedef struct
{
unsigned int     reserved_0:8;
unsigned int     C7_LATCNT_END:8;
unsigned int     reserved_1:8;
unsigned int     C7_LATCNT_BEG:8;
}DC_PRIORITY_CTRL7;

typedef struct
{
unsigned int     reserved_0:8;
unsigned int     C8_LATCNT_END:8;
unsigned int     reserved_1:8;
unsigned int     C8_LATCNT_BEG:8;
}DC_PRIORITY_CTRL8;

typedef struct
{
unsigned int     reserved_0:8;
unsigned int     C9_LATCNT_END:8;
unsigned int     reserved_1:8;
unsigned int     C9_LATCNT_BEG:8;
}DC_PRIORITY_CTRL9;

typedef struct
{
unsigned int     reserved_0:8;
unsigned int     CA_LATCNT_END:8;
unsigned int     reserved_1:8;
unsigned int     CA_LATCNT_BEG:8;
}DC_PRIORITY_CTRLA;

typedef struct
{
unsigned int     reserved_0:8;
unsigned int     CB_LATCNT_END:8;
unsigned int     reserved_1:8;
unsigned int     CB_LATCNT_BEG:8;
}DC_PRIORITY_CTRLB;

typedef struct
{
unsigned int     reserved_0:3;
unsigned int     GPU_LAT_NEW:1;
unsigned int     HIE_CMP_DIS:12;
unsigned int     reserved_1:8;
unsigned int     LATCNT_PERIOD:8;
}DC_PRIORITY_CTRL_HIE;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     SCPU_LATCNT:8;
}DC_PRIORITY_CTRL_SCPU;

typedef struct
{
unsigned int     reserved_0:20;
unsigned int     req_mask_index:12;
}DC_CLIENT_MASK;

typedef struct
{
unsigned int     reserved_0:31;
unsigned int     pc_go:1;
}DC_PC_CTRL;

typedef struct
{
unsigned int     pc_tota_mon_num:32;
}DC_PC_TOTA_MON_NUM;

typedef struct
{
unsigned int     pc_tota_ack_num:32;
}DC_PC_TOTA_ACK_NUM;

typedef struct
{
unsigned int     pc_tota_idl_num:32;
}DC_PC_TOTA_IDL_NUM;

typedef struct
{
unsigned int     reserved_0:8;
unsigned int     write_en_3:1;
unsigned int     pc_sysh_prog2_sel:7;
unsigned int     write_en_2:1;
unsigned int     pc_sysh_prog1_sel:7;
unsigned int     write_en_1:1;
unsigned int     pc_sysh_prog0_sel:7;
}DC_PC_SYSH_PROG_CTRL;

typedef struct
{
unsigned int     reserved_0:25;
unsigned int     pc_sysh_prog2_req_occur:1;
unsigned int     pc_sysh_prog1_req_occur:1;
unsigned int     pc_sysh_prog0_req_occur:1;
unsigned int     reserved_1:4;
}DC_PC_SYS_PROG_CTRL1;

typedef struct
{
unsigned int     sysh_prog0_acc_lat:32;
}DC_PC_SYSH_PROG_0_ACC_LAT;

typedef struct
{
unsigned int     reserved_0:16;
unsigned int     sysh_prog0_max_lat:16;
}DC_PC_SYSH_PROG_0_MAX_LAT;

typedef struct
{
unsigned int     reserved_0:8;
unsigned int     sysh_prog0_req_num:24;
}DC_PC_SYSH_PROG_0_REQ_NUM;

typedef struct
{
unsigned int     sysh_prog0_ack_num:32;
}DC_PC_SYSH_PROG_0_ACK_NUM;

typedef struct
{
unsigned int     sysh_prog1_acc_lat:32;
}DC_PC_SYSH_PROG_1_ACC_LAT;

typedef struct
{
unsigned int     reserved_0:16;
unsigned int     sysh_prog1_max_lat:16;
}DC_PC_SYSH_PROG_1_MAX_LAT;

typedef struct
{
unsigned int     reserved_0:8;
unsigned int     sysh_prog1_req_num:24;
}DC_PC_SYSH_PROG_1_REQ_NUM;

typedef struct
{
unsigned int     sysh_prog1_ack_num:32;
}DC_PC_SYSH_PROG_1_ACK_NUM;

typedef struct
{
unsigned int     sysh_prog2_acc_lat:32;
}DC_PC_SYSH_PROG_2_ACC_LAT;

typedef struct
{
unsigned int     reserved_0:16;
unsigned int     sysh_prog2_max_lat:16;
}DC_PC_SYSH_PROG_2_MAX_LAT;

typedef struct
{
unsigned int     reserved_0:8;
unsigned int     sysh_prog2_req_num:24;
}DC_PC_SYSH_PROG_2_REQ_NUM;

typedef struct
{
unsigned int     sysh_prog2_ack_num:32;
}DC_PC_SYSH_PROG_2_ACK_NUM;

typedef struct
{
unsigned int     reserved_0:16;
unsigned int     sysh0_hitend_cnt:16;
}DC_PC_SYSH_PROG_0;

typedef struct
{
unsigned int     reserved_0:16;
unsigned int     sysh1_hitend_cnt:16;
}DC_PC_SYSH_PROG_1;

typedef struct
{
unsigned int     reserved_0:16;
unsigned int     sysh2_hitend_cnt:16;
}DC_PC_SYSH_PROG_2;

typedef struct
{
unsigned int     reserved_0:27;
unsigned int     reserved_1:3;
unsigned int     DC_BIST_MODE_PICT0:1;
unsigned int     reserved_2:1;
}DC_BIST_MODE;

typedef struct
{
unsigned int     reserved_0:30;
unsigned int     DC_BIST_DONE_PICT0:1;
unsigned int     reserved_1:1;
}DC_BIST_DONE;

typedef struct
{
unsigned int     reserved_0:30;
unsigned int     DC_BIST_FAIL_GROUP_PICT0:1;
unsigned int     reserved_1:1;
}DC_BIST_FAIL;

typedef struct
{
unsigned int     reserved_0:30;
unsigned int     DC_DRF_MODE_PICT0:1;
unsigned int     reserved_1:1;
}DC_BIST_DRF;

typedef struct
{
unsigned int     reserved_0:30;
unsigned int     DC_DRF_RESUME_PICT0:1;
unsigned int     reserved_1:1;
}DC_BIST_RESUME;

typedef struct
{
unsigned int     reserved_0:30;
unsigned int     DC_DRF_DONE_PICT0:1;
unsigned int     reserved_1:1;
}DC_BIST0_DRF_DONE;

typedef struct
{
unsigned int     reserved_0:30;
unsigned int     DC_DRF_PAUSE_PICT0:1;
unsigned int     reserved_1:1;
}DC_BIST_DRF_PAUSE;

typedef struct
{
unsigned int     reserved_0:30;
unsigned int     DC_DRF_FAIL_GROUP_PICT0:1;
unsigned int     reserved_1:1;
}DC_BIST_DRF_FAIL;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     reserved_1:1;
unsigned int     reserved_2:1;
unsigned int     DC_DRF_PICT_FAIL0:1;
unsigned int     DC_BIST_PICT_FAIL0:1;
unsigned int     reserved_3:4;
}DC_BIST_DETAIL;

typedef struct
{
unsigned int     reserved_0:24;
unsigned int     reserved_1:3;
unsigned int     RME:1;
unsigned int     RM_3:1;
unsigned int     RM_2:1;
unsigned int     RM_1:1;
unsigned int     RM_0:1;
}DC_BIST_RM;

typedef struct
{
unsigned int     dummy_reg0:32;
}DC_DUMMY_REG0;

typedef struct
{
unsigned int     dummy_reg1:32;
}DC_DUMMY_REG1;

typedef struct
{
unsigned int     dummy_reg2:32;
}DC_DUMMY_REG2;

typedef struct
{
unsigned int     dummy_reg3:32;
}DC_DUMMY_REG3;

typedef struct
{
unsigned int     mem_type:2;
unsigned int     reserved_0:30;
}DC_MT_TYPE;

typedef struct
{
unsigned int     reserved_0:1;
unsigned int     saddr:26;
unsigned int     reserved_1:5;
}DC_MT_SADDR;

typedef struct
{
unsigned int     reserved_0:1;
unsigned int     eaddr:26;
unsigned int     reserved_1:5;
}DC_MT_EADDR;

typedef struct
{
unsigned int     reserved_0:29;
unsigned int     write_enable5:1;
unsigned int     mode:2;
}DC_MT_MODE;

typedef struct
{
unsigned int     reserved_0:1;
unsigned int     module_ID_0:7;
unsigned int     reserved_1:1;
unsigned int     module_ID_1:7;
unsigned int     reserved_2:1;
unsigned int     module_ID_2:7;
unsigned int     reserved_3:1;
unsigned int     module_ID_3:7;
}DC_MT_TABLE;

typedef struct
{
unsigned int     access_type_0:2;
unsigned int     access_type_1:2;
unsigned int     access_type_2:2;
unsigned int     access_type_3:2;
unsigned int     reserved_0:2;
unsigned int     ever_trap:1;
unsigned int     module_ID:7;
unsigned int     addcmd:14;
}DC_MT_ADDCMD_HI;

typedef struct
{
unsigned int     addcmd:32;
}DC_MT_ADDCMD_LO;

typedef struct
{
unsigned int     trap_seq_sa:32;
}DC_MT_ADDCMD_SA;

typedef struct
{
unsigned int     reserved_0:30;
unsigned int     enable_block_info:1;
unsigned int     disable_cross_range_check:1;
}DC_MT_MISC;

typedef struct
{
unsigned int     write_enable3:1;
unsigned int     error_cmd_swap_addr:27;
unsigned int     write_enable2:1;
unsigned int     error_cmd_swap_en:1;
unsigned int     write_enable1:1;
unsigned int     error_cmd_detection_en:1;
}DC_EC_CTRL;

typedef struct
{
unsigned int     reserved_0:1;
unsigned int     error_cmd_ever_trap:1;
unsigned int     trap_case:8;
unsigned int     Addcmd_hi:22;
}DC_EC_ADDCMD_HI;

typedef struct
{
unsigned int     Addcmd_lo:32;
}DC_EC_ADDCMD_LO;

typedef struct
{
unsigned int     reserved_0:25;
unsigned int     reserved_1:1;
unsigned int     reserved_2:2;
unsigned int     reserved_3:1;
unsigned int     reserved_4:1;
unsigned int     write_enable1:1;
unsigned int     tag_check_en:1;
}DC_RD_TAG_CHECK;

typedef struct
{
unsigned int     reserved_0:7;
unsigned int     pic_offset_x_odd_int_en:1;
unsigned int     rd_tag_mismatch_int_en:1;
unsigned int     err_seq_sa_odd_int_en:1;
unsigned int     err_seq_bl_zero_int_en:1;
unsigned int     err_seq_bl_odd_int_en:1;
unsigned int     err_blk_8x2_on_64_int_en:1;
unsigned int     err_blk_size_exceed_int_en:1;
unsigned int     err_blk_h_zero_int_en:1;
unsigned int     err_blk_w_zero_int_en:1;
unsigned int     reserved_1:3;
unsigned int     mt_3_mod3_int_en:1;
unsigned int     mt_3_mod2_int_en:1;
unsigned int     mt_3_mod1_int_en:1;
unsigned int     mt_2_mod3_int_en:1;
unsigned int     mt_2_mod2_int_en:1;
unsigned int     mt_2_mod1_int_en:1;
unsigned int     mt_1_mod3_int_en:1;
unsigned int     mt_1_mod2_int_en:1;
unsigned int     mt_1_mod1_int_en:1;
unsigned int     mt_0_mod3_int_en:1;
unsigned int     mt_0_mod2_int_en:1;
unsigned int     mt_0_mod1_int_en:1;
unsigned int     write_data:1;
}DC_INT_ENABLE;

typedef struct
{
unsigned int     reserved_0:7;
unsigned int     pic_offset_x_odd_int:1;
unsigned int     rd_tag_mismatch_int:1;
unsigned int     err_seq_sa_odd_int:1;
unsigned int     err_seq_bl_zero_int:1;
unsigned int     err_seq_bl_odd_int:1;
unsigned int     err_blk_8x2_on_64_int:1;
unsigned int     err_blk_size_exceed_int:1;
unsigned int     err_blk_h_zero_int:1;
unsigned int     err_blk_w_zero_int:1;
unsigned int     reserved_1:3;
unsigned int     mt_3_mod3_int:1;
unsigned int     mt_3_mod2_int:1;
unsigned int     mt_3_mod1_int:1;
unsigned int     mt_2_mod3_int:1;
unsigned int     mt_2_mod2_int:1;
unsigned int     mt_2_mod1_int:1;
unsigned int     mt_1_mod3_int:1;
unsigned int     mt_1_mod2_int:1;
unsigned int     mt_1_mod1_int:1;
unsigned int     mt_0_mod3_int:1;
unsigned int     mt_0_mod2_int:1;
unsigned int     mt_0_mod1_int:1;
unsigned int     write_data:1;
}DC_INT_STATUS;

typedef struct
{
unsigned int     reserved_0:20;
unsigned int     bw_en:12;
}BW_CTRL;

typedef struct
{
unsigned int     value:32;
}BW_TIMER_THRESHOLD;

typedef struct
{
unsigned int     reserved_0:8;
unsigned int     value:24;
}BW_REQUEST_THRESHOLD;

typedef struct
{
unsigned int     reserved_0:2;
unsigned int     pre_tra_rd_cnt:10;
unsigned int     reserved_1:2;
unsigned int     pre_tra_wr_cnt:10;
unsigned int     reserved_2:6;
unsigned int     tv_sb4_mux:1;
unsigned int     tv_sb2_mux:1;
}DC_SYS2_MUX;

typedef struct
{
unsigned int     reserved_0:10;
unsigned int     ever_trap:1;
unsigned int     module_ID:7;
unsigned int     addcmd:14;
}DC_MT_ADDCMD_HI_SYS2;

typedef struct
{
unsigned int     addcmd:32;
}DC_MT_ADDCMD_LO_SYS2;

typedef struct
{
unsigned int     trap_seq_sa:32;
}DC_MT_ADDCMD_SA_SYS2;

typedef struct
{
unsigned int     reserved_0:1;
unsigned int     error_cmd_ever_trap:1;
unsigned int     trap_case:8;
unsigned int     Addcmd_hi:22;
}DC_EC_ADDCMD_HI_SYS2;

typedef struct
{
unsigned int     Addcmd_lo:32;
}DC_EC_ADDCMD_LO_SYS2;

typedef struct
{
unsigned int     reserved_0:8;
unsigned int     rd_tag_mismatch_int_en:1;
unsigned int     err_seq_sa_odd_int_en:1;
unsigned int     err_seq_bl_zero_int_en:1;
unsigned int     err_seq_bl_odd_int_en:1;
unsigned int     err_blk_8x2_on_64_int_en:1;
unsigned int     err_blk_size_exceed_int_en:1;
unsigned int     err_blk_h_zero_int_en:1;
unsigned int     err_blk_w_zero_int_en:1;
unsigned int     reserved_1:3;
unsigned int     mt_3_mod3_int_en:1;
unsigned int     mt_3_mod2_int_en:1;
unsigned int     mt_3_mod1_int_en:1;
unsigned int     mt_2_mod3_int_en:1;
unsigned int     mt_2_mod2_int_en:1;
unsigned int     mt_2_mod1_int_en:1;
unsigned int     mt_1_mod3_int_en:1;
unsigned int     mt_1_mod2_int_en:1;
unsigned int     mt_1_mod1_int_en:1;
unsigned int     mt_0_mod3_int_en:1;
unsigned int     mt_0_mod2_int_en:1;
unsigned int     mt_0_mod1_int_en:1;
unsigned int     write_data:1;
}DC_INT_ENABLE_SYS2;

typedef struct
{
unsigned int     reserved_0:8;
unsigned int     rd_tag_mismatch_int:1;
unsigned int     err_seq_sa_odd_int:1;
unsigned int     err_seq_bl_zero_int:1;
unsigned int     err_seq_bl_odd_int:1;
unsigned int     err_blk_8x2_on_64_int:1;
unsigned int     err_blk_size_exceed_int:1;
unsigned int     err_blk_h_zero_int:1;
unsigned int     err_blk_w_zero_int:1;
unsigned int     reserved_1:3;
unsigned int     mt_3_mod3_int:1;
unsigned int     mt_3_mod2_int:1;
unsigned int     mt_3_mod1_int:1;
unsigned int     mt_2_mod3_int:1;
unsigned int     mt_2_mod2_int:1;
unsigned int     mt_2_mod1_int:1;
unsigned int     mt_1_mod3_int:1;
unsigned int     mt_1_mod2_int:1;
unsigned int     mt_1_mod1_int:1;
unsigned int     mt_0_mod3_int:1;
unsigned int     mt_0_mod2_int:1;
unsigned int     mt_0_mod1_int:1;
unsigned int     write_data:1;
}DC_INT_STATUS_SYS2;

typedef struct
{
unsigned int     reserved_0:30;
unsigned int     disable_2nd_channel:1;
unsigned int     full_transfer:1;
}DC_64_WRITE_BUF_CTRL;

typedef struct
{
unsigned int     reserved_0:8;
unsigned int     sync_cmd_cnt_threshold:3;
unsigned int     cmd_buf_threshold:4;
unsigned int     disable_2nd_channel:1;
unsigned int     ever_full:1;
unsigned int     ever_reach_threshold:1;
unsigned int     max_buf_level:7;
unsigned int     grant_stop_level:7;
}DC_64_READ_BUF_CTRL;

typedef struct
{
unsigned int     reserved_0:31;
unsigned int     error_bl_zero_swap:1;
}DC_64_ERROR_CTRL;

typedef struct
{
unsigned int     reserved_0:8;
unsigned int     THIRD_64BIT_WRAPPER_LATCNT:8;
unsigned int     reserved_1:8;
unsigned int     SECOND_64BIT_WRAPPER_LATCNT:8;
}DC_PRIORITY_CTRL_64BIT;

typedef struct
{
unsigned int     reserved_0:29;
unsigned int     DC_BIST_MODE_WRAP2:1;
unsigned int     DC_BIST_MODE_WRAP1:1;
unsigned int     DC_BIST_MODE_WRAP0:1;
}DC_64_BIST_MODE;

typedef struct
{
unsigned int     reserved_0:29;
unsigned int     DC_BIST_DONE_WRAP2:1;
unsigned int     DC_BIST_DONE_WRAP1:1;
unsigned int     DC_BIST_DONE_WRAP0:1;
}DC_64_BIST_DONE;

typedef struct
{
unsigned int     reserved_0:29;
unsigned int     DC_BIST_FAIL_GROUP_WRAP2:1;
unsigned int     DC_BIST_FAIL_GROUP_WRAP1:1;
unsigned int     DC_BIST_FAIL_GROUP_WRAP0:1;
}DC_64_BIST_FAIL;

typedef struct
{
unsigned int     reserved_0:29;
unsigned int     DC_DRF_MODE_WRAP2:1;
unsigned int     DC_DRF_MODE_WRAP1:1;
unsigned int     DC_DRF_MODE_WRAP0:1;
}DC_64_DRF;

typedef struct
{
unsigned int     reserved_0:29;
unsigned int     DC_DRF_RESUME_WRAP2:1;
unsigned int     DC_DRF_RESUME_WRAP1:1;
unsigned int     DC_DRF_RESUME_WRAP0:1;
}DC_64_DRF_RESUME;

typedef struct
{
unsigned int     reserved_0:29;
unsigned int     DC_DRF_DONE_WRAP2:1;
unsigned int     DC_DRF_DONE_WRAP1:1;
unsigned int     DC_DRF_DONE_WRAP0:1;
}DC_64_DRF_DONE;

typedef struct
{
unsigned int     reserved_0:29;
unsigned int     DC_DRF_PAUSE_WRAP2:1;
unsigned int     DC_DRF_PAUSE_WRAP1:1;
unsigned int     DC_DRF_PAUSE_WRAP0:1;
}DC_64_DRF_PAUSE;

typedef struct
{
unsigned int     reserved_0:29;
unsigned int     DC_DRF_FAIL_GROUP_WRAP2:1;
unsigned int     DC_DRF_FAIL_GROUP_WRAP1:1;
unsigned int     DC_DRF_FAIL_GROUP_WRAP0:1;
}DC_64_DRF_FAIL;

typedef struct
{
unsigned int     reserved_0:20;
unsigned int     DC_DRF_WRAP2_FAIL_1:1;
unsigned int     DC_DRF_WRAP2_FAIL_0:1;
unsigned int     DC_BIST_WRAP2_FAIL_1:1;
unsigned int     DC_BIST_WRAP2_FAIL_0:1;
unsigned int     DC_DRF_WRAP1_FAIL_1:1;
unsigned int     DC_DRF_WRAP1_FAIL_0:1;
unsigned int     DC_BIST_WRAP1_FAIL_1:1;
unsigned int     DC_BIST_WRAP1_FAIL_0:1;
unsigned int     DC_DRF_WRAP0_FAIL_1:1;
unsigned int     DC_DRF_WRAP0_FAIL_0:1;
unsigned int     DC_BIST_WRAP0_FAIL_1:1;
unsigned int     DC_BIST_WRAP0_FAIL_0:1;
}DC_64_BIST_DETAIL;

typedef struct
{
unsigned int     reserved_0:11;
unsigned int     RMEA:1;
unsigned int     RMA:4;
unsigned int     reserved_1:3;
unsigned int     RMEB:1;
unsigned int     RMB:4;
unsigned int     reserved_2:8;
}DC_64_BIST_RM;

typedef struct
{
unsigned int     reserved_0:31;
unsigned int     pc_go:1;
}DC_64_PC_CTRL;

typedef struct
{
unsigned int     reserved_0:8;
unsigned int     write_en_3:1;
unsigned int     pc_sys_prog2_sel:7;
unsigned int     write_en_2:1;
unsigned int     pc_sys_prog1_sel:7;
unsigned int     write_en_1:1;
unsigned int     pc_sys_prog0_sel:7;
}DC_PC_SYS_PROG_CTRL;

typedef struct
{
unsigned int     reserved_0:28;
unsigned int     reserved_1:1;
unsigned int     pc_sys_prog2_req_occur:1;
unsigned int     pc_sys_prog1_req_occur:1;
unsigned int     pc_sys_prog0_req_occur:1;
}DC_64_PC_SYS_PROG_CTRL1;

typedef struct
{
unsigned int     sys_prog0_acc_lat:32;
}DC_PC_SYS_PROG_0_ACC_LAT;

typedef struct
{
unsigned int     reserved_0:16;
unsigned int     sys_prog0_max_lat:16;
}DC_PC_SYS_PROG_0_MAX_LAT;

typedef struct
{
unsigned int     reserved_0:8;
unsigned int     sys_prog0_req_num:24;
}DC_PC_SYS_PROG_0_REQ_NUM;

typedef struct
{
unsigned int     sys_prog0_ack_num:32;
}DC_PC_SYS_PROG_0_ACK_NUM;

typedef struct
{
unsigned int     sys_prog1_acc_lat:32;
}DC_PC_SYS_PROG_1_ACC_LAT;

typedef struct
{
unsigned int     reserved_0:16;
unsigned int     sys_prog1_max_lat:16;
}DC_PC_SYS_PROG_1_MAX_LAT;

typedef struct
{
unsigned int     reserved_0:8;
unsigned int     sys_prog1_req_num:24;
}DC_PC_SYS_PROG_1_REQ_NUM;

typedef struct
{
unsigned int     sys_prog1_ack_num:32;
}DC_PC_SYS_PROG_1_ACK_NUM;

typedef struct
{
unsigned int     sys_prog2_acc_lat:32;
}DC_PC_SYS_PROG_2_ACC_LAT;

typedef struct
{
unsigned int     reserved_0:16;
unsigned int     sys_prog2_max_lat:16;
}DC_PC_SYS_PROG_2_MAX_LAT;

typedef struct
{
unsigned int     reserved_0:8;
unsigned int     sys_prog2_req_num:24;
}DC_PC_SYS_PROG_2_REQ_NUM;

typedef struct
{
unsigned int     sys_prog2_ack_num:32;
}DC_PC_SYS_PROG_2_ACK_NUM;

typedef struct
{
unsigned int     reserved_0:16;
unsigned int     sys0_hitend_cnt:16;
}DC_PC_SYS_PROG_0;

typedef struct
{
unsigned int     reserved_0:16;
unsigned int     sys1_hitend_cnt:16;
}DC_PC_SYS_PROG_1;

typedef struct
{
unsigned int     reserved_0:16;
unsigned int     sys2_hitend_cnt:16;
}DC_PC_SYS_PROG_2;

typedef struct
{
unsigned int     reserved_0:31;
unsigned int     enable:1;
}EXSRAM_CTRL;

typedef struct
{
unsigned int     reserved_0:31;
unsigned int     global_scramble_en:1;
}DC_GLOBAL_SCRAMBLE_CTRL;

typedef struct
{
unsigned int     key1:16;
unsigned int     key0:16;
}DC_MEM_SCRAMBLE_GLOBAL_0;

typedef struct
{
unsigned int     key3:16;
unsigned int     key2:16;
}DC_MEM_SCRAMBLE_GLOBAL_1;

typedef struct
{
unsigned int     key5:16;
unsigned int     key4:16;
}DC_MEM_SCRAMBLE_GLOBAL_2;

typedef struct
{
unsigned int     key7:16;
unsigned int     key6:16;
}DC_MEM_SCRAMBLE_GLOBAL_3;

typedef struct
{
unsigned int     key9:16;
unsigned int     key8:16;
}DC_MEM_SCRAMBLE_GLOBAL_4;

typedef struct
{
unsigned int     keyB:16;
unsigned int     keyA:16;
}DC_MEM_SCRAMBLE_GLOBAL_5;

typedef struct
{
unsigned int     keyD:16;
unsigned int     keyC:16;
}DC_MEM_SCRAMBLE_GLOBAL_6;

typedef struct
{
unsigned int     reserved_0:7;
unsigned int     osd1_protect_3_en:1;
unsigned int     reserved_1:4;
unsigned int     protect_3_en:1;
unsigned int     protect_2_en:1;
unsigned int     protect_1_en:1;
unsigned int     protect_0_en:1;
unsigned int     reserved_2:12;
unsigned int     protect_3_scramble_en:1;
unsigned int     protect_2_scramble_en:1;
unsigned int     protect_1_scramble_en:1;
unsigned int     protect_0_scramble_en:1;
}DC_MEM_PROTECT_CTRL;

typedef struct
{
unsigned int     addr:20;
unsigned int     reserved_0:10;
unsigned int     y_limit:1;
unsigned int     reserved_1:1;
}DC_SECURE_MAX;

typedef struct
{
unsigned int     addr:20;
unsigned int     reserved_0:12;
}DC_MEM_PROTECT_START;

typedef struct
{
unsigned int     addr:20;
unsigned int     reserved_0:12;
}DC_MEM_PROTECT_END;

typedef struct
{
unsigned int     reserved_0:27;
unsigned int     tp_kc:1;
unsigned int     emmc_kc:1;
unsigned int     nf_kc:1;
unsigned int     cp_kc:1;
unsigned int     md_kc:1;
}DC_KCPU_REGION;

typedef struct
{
unsigned int     reserved_0:8;
unsigned int     content_7_en:1;
unsigned int     content_6_en:1;
unsigned int     content_5_en:1;
unsigned int     content_4_en:1;
unsigned int     content_3_en:1;
unsigned int     content_2_en:1;
unsigned int     content_1_en:1;
unsigned int     content_0_en:1;
unsigned int     reserved_1:8;
unsigned int     scramble_7_en:1;
unsigned int     scramble_6_en:1;
unsigned int     scramble_5_en:1;
unsigned int     scramble_4_en:1;
unsigned int     scramble_3_en:1;
unsigned int     scramble_2_en:1;
unsigned int     scramble_1_en:1;
unsigned int     scramble_0_en:1;
}DC_MEM_CONTENT_CTRL;

typedef struct
{
unsigned int     reserved_0:18;
unsigned int     tp_kc:1;
unsigned int     emmc_kc:1;
unsigned int     acpu:2;
unsigned int     vcpu:2;
unsigned int     nf_kc:1;
unsigned int     ve:1;
unsigned int     vde:1;
unsigned int     ade:1;
unsigned int     ae:1;
unsigned int     md_kc:1;
unsigned int     cp_kc:1;
unsigned int     md_vc:1;
}DC_SCRAMBLE_ACCESS;

typedef struct
{
unsigned int     addr:20;
unsigned int     reserved_0:12;
}DC_MEM_SCRAMBLE_START;

typedef struct
{
unsigned int     addr:20;
unsigned int     reserved_0:12;
}DC_MEM_SCRAMBLE_END;

typedef struct
{
unsigned int     key1:16;
unsigned int     key0:16;
}DC_MEM_SCRAMBLE_BUF_CUR0;

typedef struct
{
unsigned int     key3:16;
unsigned int     key2:16;
}DC_MEM_SCRAMBLE_BUF_CUR1;

typedef struct
{
unsigned int     key5:16;
unsigned int     key4:16;
}DC_MEM_SCRAMBLE_BUF_CUR2;

typedef struct
{
unsigned int     key7:16;
unsigned int     key6:16;
}DC_MEM_SCRAMBLE_BUF_CUR3;

typedef struct
{
unsigned int     key9:16;
unsigned int     key8:16;
}DC_MEM_SCRAMBLE_BUF_CUR4;

typedef struct
{
unsigned int     keyB:16;
unsigned int     keyA:16;
}DC_MEM_SCRAMBLE_BUF_CUR5;

typedef struct
{
unsigned int     keyD:16;
unsigned int     keyC:16;
}DC_MEM_SCRAMBLE_BUF_CUR6;

typedef struct
{
unsigned int     key1:16;
unsigned int     key0:16;
}DC_MEM_SCRAMBLE_BUF_PRE0;

typedef struct
{
unsigned int     key3:16;
unsigned int     key2:16;
}DC_MEM_SCRAMBLE_BUF_PRE1;

typedef struct
{
unsigned int     key5:16;
unsigned int     key4:16;
}DC_MEM_SCRAMBLE_BUF_PRE2;

typedef struct
{
unsigned int     key7:16;
unsigned int     key6:16;
}DC_MEM_SCRAMBLE_BUF_PRE3;

typedef struct
{
unsigned int     key9:16;
unsigned int     key8:16;
}DC_MEM_SCRAMBLE_BUF_PRE4;

typedef struct
{
unsigned int     keyB:16;
unsigned int     keyA:16;
}DC_MEM_SCRAMBLE_BUF_PRE5;

typedef struct
{
unsigned int     keyD:16;
unsigned int     keyC:16;
}DC_MEM_SCRAMBLE_BUF_PRE6;

typedef struct
{
unsigned int     key1:16;
unsigned int     key0:16;
}DC_MEM_SCRAMBLE_BUF_UP0;

typedef struct
{
unsigned int     key3:16;
unsigned int     key2:16;
}DC_MEM_SCRAMBLE_BUF_UP1;

typedef struct
{
unsigned int     key5:16;
unsigned int     key4:16;
}DC_MEM_SCRAMBLE_BUF_UP2;

typedef struct
{
unsigned int     key7:16;
unsigned int     key6:16;
}DC_MEM_SCRAMBLE_BUF_UP3;

typedef struct
{
unsigned int     key9:16;
unsigned int     key8:16;
}DC_MEM_SCRAMBLE_BUF_UP4;

typedef struct
{
unsigned int     keyB:16;
unsigned int     keyA:16;
}DC_MEM_SCRAMBLE_BUF_UP5;

typedef struct
{
unsigned int     keyD:16;
unsigned int     keyC:16;
}DC_MEM_SCRAMBLE_BUF_UP6;

typedef struct
{
unsigned int     reserved_0:14;
unsigned int     display_1_en:1;
unsigned int     display_0_en:1;
unsigned int     reserved_1:14;
unsigned int     display_1_scramble_en:1;
unsigned int     display_0_scramble_en:1;
}DC_MEM_DISPLAY_CTRL;

typedef struct
{
unsigned int     addr:20;
unsigned int     reserved_0:12;
}DC_DISPLAY_START;

typedef struct
{
unsigned int     addr:20;
unsigned int     reserved_0:12;
}DC_DISPLAY_END;

typedef struct
{
unsigned int     reserved_0:20;
unsigned int     me:1;
unsigned int     osd1:1;
unsigned int     osd2:1;
unsigned int     subtitle:1;
unsigned int     vcpu:2;
unsigned int     ve:1;
unsigned int     vde:1;
unsigned int     gpu:1;
unsigned int     md_kc:1;
unsigned int     cp_kc:1;
unsigned int     md_vc:1;
}DC_DISPLAY_ACCESS;

typedef struct
{
unsigned int     display_touch_other_en:1;
unsigned int     display1_touch_en:1;
unsigned int     display0_touch_en:1;
unsigned int     blk_over_max_secure_addr_int_en:1;
unsigned int     seq_over_max_secure_addr_int_en:1;
unsigned int     blk_y_overflow_int_en:1;
unsigned int     blk_x_overflow_int_en:1;
unsigned int     content7_blk_touch_int_en:1;
unsigned int     content7_seq_touch_int_en:1;
unsigned int     content6_blk_touch_int_en:1;
unsigned int     content6_seq_touch_int_en:1;
unsigned int     content5_blk_touch_int_en:1;
unsigned int     content5_seq_touch_int_en:1;
unsigned int     content4_blk_touch_int_en:1;
unsigned int     content4_seq_touch_int_en:1;
unsigned int     content3_blk_touch_int_en:1;
unsigned int     content3_seq_touch_int_en:1;
unsigned int     content2_blk_touch_int_en:1;
unsigned int     content2_seq_touch_int_en:1;
unsigned int     content1_blk_touch_int_en:1;
unsigned int     content1_seq_touch_int_en:1;
unsigned int     content0_blk_touch_int_en:1;
unsigned int     content0_seq_touch_int_en:1;
unsigned int     protect3_blk_picset_touch_int_en:1;
unsigned int     protect3_seq_touch_int_en:1;
unsigned int     protect2_blk_picset_touch_int_en:1;
unsigned int     protect2_seq_touch_int_en:1;
unsigned int     protect1_blk_picset_touch_int_en:1;
unsigned int     protect1_seq_touch_int_en:1;
unsigned int     protect0_blk_picset_touch_int_en:1;
unsigned int     protect0_seq_touch_int_en:1;
unsigned int     write_data:1;
}DC_SECURE_INT_ENABLE;

typedef struct
{
unsigned int     display_touch_other_int:1;
unsigned int     display1_touch_int:1;
unsigned int     display0_touch_int:1;
unsigned int     blk_over_max_secure_addr_int:1;
unsigned int     seq_over_max_secure_addr_int:1;
unsigned int     blk_y_overflow_int:1;
unsigned int     blk_x_overflow_int:1;
unsigned int     content7_blk_touch_int:1;
unsigned int     content7_seq_touch_int:1;
unsigned int     content6_blk_touch_int:1;
unsigned int     content6_seq_touch_int:1;
unsigned int     content5_blk_touch_int:1;
unsigned int     content5_seq_touch_int:1;
unsigned int     content4_blk_touch_int:1;
unsigned int     content4_seq_touch_int:1;
unsigned int     content3_blk_touch_int:1;
unsigned int     content3_seq_touch_int:1;
unsigned int     content2_blk_touch_int:1;
unsigned int     content2_seq_touch_int:1;
unsigned int     content1_blk_touch_int:1;
unsigned int     content1_seq_touch_int:1;
unsigned int     content0_blk_touch_int:1;
unsigned int     content0_seq_touch_int:1;
unsigned int     protect3_blk_picset_touch_int:1;
unsigned int     protect3_seq_touch_int:1;
unsigned int     protect2_blk_picset_touch_int:1;
unsigned int     protect2_seq_touch_int:1;
unsigned int     protect1_blk_picset_touch_int:1;
unsigned int     protect1_seq_touch_int:1;
unsigned int     protect0_blk_picset_touch_int:1;
unsigned int     protect0_seq_touch_int:1;
unsigned int     write_data:1;
}DC_SECURE_INT_STATUS;

typedef struct
{
unsigned int     reserved_0:1;
unsigned int     reserved_1:7;
unsigned int     reserved_2:1;
unsigned int     blk_error_pic_index:7;
unsigned int     reserved_3:1;
unsigned int     seq_read_error_id:7;
unsigned int     reserved_4:1;
unsigned int     seq_write_error_id:7;
}DC_SECURE_ERROR_INFO;

typedef struct
{
unsigned int     reserved_0:23;
unsigned int     content7_key_updated_int_en:1;
unsigned int     content6_key_updated_int_en:1;
unsigned int     content5_key_updated_int_en:1;
unsigned int     content4_key_updated_int_en:1;
unsigned int     content3_key_updated_int_en:1;
unsigned int     content2_key_updated_int_en:1;
unsigned int     content1_key_updated_int_en:1;
unsigned int     content0_key_updated_int_en:1;
unsigned int     write_data:1;
}DC_SECURE_KEY_INT_ENABLE;

typedef struct
{
unsigned int     reserved_0:23;
unsigned int     content7_key_updated_int:1;
unsigned int     content6_key_updated_int:1;
unsigned int     content5_key_updated_int:1;
unsigned int     content4_key_updated_int:1;
unsigned int     content3_key_updated_int:1;
unsigned int     content2_key_updated_int:1;
unsigned int     content1_key_updated_int:1;
unsigned int     content0_key_updated_int:1;
unsigned int     write_data:1;
}DC_SECURE_KEY_INT_STATUS;

typedef struct
{
unsigned int     display_touch_other_en:1;
unsigned int     display1_touch_en:1;
unsigned int     display0_touch_en:1;
unsigned int     reserved_0:1;
unsigned int     seq_over_max_secure_addr_int_en:1;
unsigned int     blk_y_overflow_int_en:1;
unsigned int     blk_x_overflow_int_en:1;
unsigned int     reserved_1:1;
unsigned int     content7_seq_touch_int_en:1;
unsigned int     reserved_2:1;
unsigned int     content6_seq_touch_int_en:1;
unsigned int     reserved_3:1;
unsigned int     content5_seq_touch_int_en:1;
unsigned int     reserved_4:1;
unsigned int     content4_seq_touch_int_en:1;
unsigned int     reserved_5:1;
unsigned int     content3_seq_touch_int_en:1;
unsigned int     reserved_6:1;
unsigned int     content2_seq_touch_int_en:1;
unsigned int     reserved_7:1;
unsigned int     content1_seq_touch_int_en:1;
unsigned int     reserved_8:1;
unsigned int     content0_seq_touch_int_en:1;
unsigned int     reserved_9:1;
unsigned int     protect3_seq_touch_int_en:1;
unsigned int     reserved_10:1;
unsigned int     protect2_seq_touch_int_en:1;
unsigned int     reserved_11:1;
unsigned int     protect1_seq_touch_int_en:1;
unsigned int     reserved_12:1;
unsigned int     protect0_seq_touch_int_en:1;
unsigned int     write_data:1;
}DC_SECURE_INT_ENABLE_SYS2;

typedef struct
{
unsigned int     display_touch_other_int:1;
unsigned int     display1_touch_int:1;
unsigned int     display0_touch_int:1;
unsigned int     reserved_0:1;
unsigned int     seq_over_max_secure_addr_int:1;
unsigned int     blk_y_overflow_int:1;
unsigned int     blk_x_overflow_int:1;
unsigned int     reserved_1:1;
unsigned int     content7_seq_touch_int:1;
unsigned int     reserved_2:1;
unsigned int     content6_seq_touch_int:1;
unsigned int     reserved_3:1;
unsigned int     content5_seq_touch_int:1;
unsigned int     reserved_4:1;
unsigned int     content4_seq_touch_int:1;
unsigned int     reserved_5:1;
unsigned int     content3_seq_touch_int:1;
unsigned int     reserved_6:1;
unsigned int     content2_seq_touch_int:1;
unsigned int     reserved_7:1;
unsigned int     content1_seq_touch_int:1;
unsigned int     reserved_8:1;
unsigned int     content0_seq_touch_int:1;
unsigned int     reserved_9:1;
unsigned int     protect3_seq_touch_int:1;
unsigned int     reserved_10:1;
unsigned int     protect2_seq_touch_int:1;
unsigned int     reserved_11:1;
unsigned int     protect1_seq_touch_int:1;
unsigned int     reserved_12:1;
unsigned int     protect0_seq_touch_int:1;
unsigned int     write_data:1;
}DC_SECURE_INT_STATUS_SYS2;

typedef struct
{
unsigned int     reserved_0:9;
unsigned int     reserved_1:7;
unsigned int     reserved_2:1;
unsigned int     seq_read_error_id:7;
unsigned int     reserved_3:1;
unsigned int     seq_write_error_id:7;
}DC_SECURE_ERROR_INFO_SYS2;

#endif

#define DC_PICT_SET                                                           0x18007000
#define DC_PICT_SET_reg_addr                                                  "0xB8007000"
#define DC_PICT_SET_reg                                                       0xB8007000
#define set_DC_PICT_SET_reg(data)   (*((volatile unsigned int*) DC_PICT_SET_reg)=data)
#define get_DC_PICT_SET_reg   (*((volatile unsigned int*) DC_PICT_SET_reg))
#define DC_PICT_SET_inst_adr                                                  "0x0000"
#define DC_PICT_SET_inst                                                      0x0000
#define DC_PICT_SET_pict_width_scale_shift                                    (17)
#define DC_PICT_SET_pict_width_scale_mask                                     (0x007E0000)
#define DC_PICT_SET_pict_width_scale(data)                                    (0x007E0000&((data)<<17))
#define DC_PICT_SET_pict_width_scale_src(data)                                ((0x007E0000&(data))>>17)
#define DC_PICT_SET_get_pict_width_scale(data)                                ((0x007E0000&(data))>>17)
#define DC_PICT_SET_pict_init_page_shift                                      (0)
#define DC_PICT_SET_pict_init_page_mask                                       (0x0001FFFF)
#define DC_PICT_SET_pict_init_page(data)                                      (0x0001FFFF&((data)<<0))
#define DC_PICT_SET_pict_init_page_src(data)                                  ((0x0001FFFF&(data))>>0)
#define DC_PICT_SET_get_pict_init_page(data)                                  ((0x0001FFFF&(data))>>0)


#define DC_SYS_MISC                                                           0x18007004
#define DC_SYS_MISC_reg_addr                                                  "0xB8007004"
#define DC_SYS_MISC_reg                                                       0xB8007004
#define set_DC_SYS_MISC_reg(data)   (*((volatile unsigned int*) DC_SYS_MISC_reg)=data)
#define get_DC_SYS_MISC_reg   (*((volatile unsigned int*) DC_SYS_MISC_reg))
#define DC_SYS_MISC_inst_adr                                                  "0x0001"
#define DC_SYS_MISC_inst                                                      0x0001
#define DC_SYS_MISC_dram_8g_used_shift                                        (28)
#define DC_SYS_MISC_dram_8g_used_mask                                         (0x10000000)
#define DC_SYS_MISC_dram_8g_used(data)                                        (0x10000000&((data)<<28))
#define DC_SYS_MISC_dram_8g_used_src(data)                                    ((0x10000000&(data))>>28)
#define DC_SYS_MISC_get_dram_8g_used(data)                                    ((0x10000000&(data))>>28)
#define DC_SYS_MISC_dram_4g_used_shift                                        (27)
#define DC_SYS_MISC_dram_4g_used_mask                                         (0x08000000)
#define DC_SYS_MISC_dram_4g_used(data)                                        (0x08000000&((data)<<27))
#define DC_SYS_MISC_dram_4g_used_src(data)                                    ((0x08000000&(data))>>27)
#define DC_SYS_MISC_get_dram_4g_used(data)                                    ((0x08000000&(data))>>27)
#define DC_SYS_MISC_ddr3_512_used_shift                                       (26)
#define DC_SYS_MISC_ddr3_512_used_mask                                        (0x04000000)
#define DC_SYS_MISC_ddr3_512_used(data)                                       (0x04000000&((data)<<26))
#define DC_SYS_MISC_ddr3_512_used_src(data)                                   ((0x04000000&(data))>>26)
#define DC_SYS_MISC_get_ddr3_512_used(data)                                   ((0x04000000&(data))>>26)
#define DC_SYS_MISC_dram_2g_used_shift                                        (25)
#define DC_SYS_MISC_dram_2g_used_mask                                         (0x02000000)
#define DC_SYS_MISC_dram_2g_used(data)                                        (0x02000000&((data)<<25))
#define DC_SYS_MISC_dram_2g_used_src(data)                                    ((0x02000000&(data))>>25)
#define DC_SYS_MISC_get_dram_2g_used(data)                                    ((0x02000000&(data))>>25)
#define DC_SYS_MISC_pre_arb_scheme_sel_shift                                  (24)
#define DC_SYS_MISC_pre_arb_scheme_sel_mask                                   (0x01000000)
#define DC_SYS_MISC_pre_arb_scheme_sel(data)                                  (0x01000000&((data)<<24))
#define DC_SYS_MISC_pre_arb_scheme_sel_src(data)                              ((0x01000000&(data))>>24)
#define DC_SYS_MISC_get_pre_arb_scheme_sel(data)                              ((0x01000000&(data))>>24)
#define DC_SYS_MISC_arb_mask_all_en_shift                                     (23)
#define DC_SYS_MISC_arb_mask_all_en_mask                                      (0x00800000)
#define DC_SYS_MISC_arb_mask_all_en(data)                                     (0x00800000&((data)<<23))
#define DC_SYS_MISC_arb_mask_all_en_src(data)                                 ((0x00800000&(data))>>23)
#define DC_SYS_MISC_get_arb_mask_all_en(data)                                 ((0x00800000&(data))>>23)
#define DC_SYS_MISC_ddr3_mapping_en_shift                                     (22)
#define DC_SYS_MISC_ddr3_mapping_en_mask                                      (0x00400000)
#define DC_SYS_MISC_ddr3_mapping_en(data)                                     (0x00400000&((data)<<22))
#define DC_SYS_MISC_ddr3_mapping_en_src(data)                                 ((0x00400000&(data))>>22)
#define DC_SYS_MISC_get_ddr3_mapping_en(data)                                 ((0x00400000&(data))>>22)
#define DC_SYS_MISC_self_lookback_mode_shift                                  (20)
#define DC_SYS_MISC_self_lookback_mode_mask                                   (0x00100000)
#define DC_SYS_MISC_self_lookback_mode(data)                                  (0x00100000&((data)<<20))
#define DC_SYS_MISC_self_lookback_mode_src(data)                              ((0x00100000&(data))>>20)
#define DC_SYS_MISC_get_self_lookback_mode(data)                              ((0x00100000&(data))>>20)
#define DC_SYS_MISC_mem_num_shift                                             (19)
#define DC_SYS_MISC_mem_num_mask                                              (0x00080000)
#define DC_SYS_MISC_mem_num(data)                                             (0x00080000&((data)<<19))
#define DC_SYS_MISC_mem_num_src(data)                                         ((0x00080000&(data))>>19)
#define DC_SYS_MISC_get_mem_num(data)                                         ((0x00080000&(data))>>19)
#define DC_SYS_MISC_page_size_shift                                           (16)
#define DC_SYS_MISC_page_size_mask                                            (0x00030000)
#define DC_SYS_MISC_page_size(data)                                           (0x00030000&((data)<<16))
#define DC_SYS_MISC_page_size_src(data)                                       ((0x00030000&(data))>>16)
#define DC_SYS_MISC_get_page_size(data)                                       ((0x00030000&(data))>>16)
#define DC_SYS_MISC_max_bl_size_shift                                         (9)
#define DC_SYS_MISC_max_bl_size_mask                                          (0x00000200)
#define DC_SYS_MISC_max_bl_size(data)                                         (0x00000200&((data)<<9))
#define DC_SYS_MISC_max_bl_size_src(data)                                     ((0x00000200&(data))>>9)
#define DC_SYS_MISC_get_max_bl_size(data)                                     ((0x00000200&(data))>>9)
#define DC_SYS_MISC_en_max_bl_limit_shift                                     (8)
#define DC_SYS_MISC_en_max_bl_limit_mask                                      (0x00000100)
#define DC_SYS_MISC_en_max_bl_limit(data)                                     (0x00000100&((data)<<8))
#define DC_SYS_MISC_en_max_bl_limit_src(data)                                 ((0x00000100&(data))>>8)
#define DC_SYS_MISC_get_en_max_bl_limit(data)                                 ((0x00000100&(data))>>8)
#define DC_SYS_MISC_small_dram_4g_shift                                       (7)
#define DC_SYS_MISC_small_dram_4g_mask                                        (0x00000080)
#define DC_SYS_MISC_small_dram_4g(data)                                       (0x00000080&((data)<<7))
#define DC_SYS_MISC_small_dram_4g_src(data)                                   ((0x00000080&(data))>>7)
#define DC_SYS_MISC_get_small_dram_4g(data)                                   ((0x00000080&(data))>>7)
#define DC_SYS_MISC_small_dram_2g_shift                                       (6)
#define DC_SYS_MISC_small_dram_2g_mask                                        (0x00000040)
#define DC_SYS_MISC_small_dram_2g(data)                                       (0x00000040&((data)<<6))
#define DC_SYS_MISC_small_dram_2g_src(data)                                   ((0x00000040&(data))>>6)
#define DC_SYS_MISC_get_small_dram_2g(data)                                   ((0x00000040&(data))>>6)
#define DC_SYS_MISC_small_dram_1g_shift                                       (5)
#define DC_SYS_MISC_small_dram_1g_mask                                        (0x00000020)
#define DC_SYS_MISC_small_dram_1g(data)                                       (0x00000020&((data)<<5))
#define DC_SYS_MISC_small_dram_1g_src(data)                                   ((0x00000020&(data))>>5)
#define DC_SYS_MISC_get_small_dram_1g(data)                                   ((0x00000020&(data))>>5)
#define DC_SYS_MISC_small_dram_512m_shift                                     (4)
#define DC_SYS_MISC_small_dram_512m_mask                                      (0x00000010)
#define DC_SYS_MISC_small_dram_512m(data)                                     (0x00000010&((data)<<4))
#define DC_SYS_MISC_small_dram_512m_src(data)                                 ((0x00000010&(data))>>4)
#define DC_SYS_MISC_get_small_dram_512m(data)                                 ((0x00000010&(data))>>4)
#define DC_SYS_MISC_en_2ddr_diff_size_shift                                   (0)
#define DC_SYS_MISC_en_2ddr_diff_size_mask                                    (0x00000001)
#define DC_SYS_MISC_en_2ddr_diff_size(data)                                   (0x00000001&((data)<<0))
#define DC_SYS_MISC_en_2ddr_diff_size_src(data)                               ((0x00000001&(data))>>0)
#define DC_SYS_MISC_get_en_2ddr_diff_size(data)                               ((0x00000001&(data))>>0)


#define DC_PIC_OFFSET_X_DETECTION                                             0x18007010
#define DC_PIC_OFFSET_X_DETECTION_reg_addr                                    "0xB8007010"
#define DC_PIC_OFFSET_X_DETECTION_reg                                         0xB8007010
#define set_DC_PIC_OFFSET_X_DETECTION_reg(data)   (*((volatile unsigned int*) DC_PIC_OFFSET_X_DETECTION_reg)=data)
#define get_DC_PIC_OFFSET_X_DETECTION_reg   (*((volatile unsigned int*) DC_PIC_OFFSET_X_DETECTION_reg))
#define DC_PIC_OFFSET_X_DETECTION_inst_adr                                    "0x0004"
#define DC_PIC_OFFSET_X_DETECTION_inst                                        0x0004
#define DC_PIC_OFFSET_X_DETECTION_enable_shift                                (0)
#define DC_PIC_OFFSET_X_DETECTION_enable_mask                                 (0x00000001)
#define DC_PIC_OFFSET_X_DETECTION_enable(data)                                (0x00000001&((data)<<0))
#define DC_PIC_OFFSET_X_DETECTION_enable_src(data)                            ((0x00000001&(data))>>0)
#define DC_PIC_OFFSET_X_DETECTION_get_enable(data)                            ((0x00000001&(data))>>0)


#define DC_PICT_SET_OFFSET                                                    0x18007020
#define DC_PICT_SET_OFFSET_reg_addr                                           "0xB8007020"
#define DC_PICT_SET_OFFSET_reg                                                0xB8007020
#define set_DC_PICT_SET_OFFSET_reg(data)   (*((volatile unsigned int*) DC_PICT_SET_OFFSET_reg)=data)
#define get_DC_PICT_SET_OFFSET_reg   (*((volatile unsigned int*) DC_PICT_SET_OFFSET_reg))
#define DC_PICT_SET_OFFSET_inst_adr                                           "0x0008"
#define DC_PICT_SET_OFFSET_inst                                               0x0008
#define DC_PICT_SET_OFFSET_pict_set_num_shift                                 (24)
#define DC_PICT_SET_OFFSET_pict_set_num_mask                                  (0xFF000000)
#define DC_PICT_SET_OFFSET_pict_set_num(data)                                 (0xFF000000&((data)<<24))
#define DC_PICT_SET_OFFSET_pict_set_num_src(data)                             ((0xFF000000&(data))>>24)
#define DC_PICT_SET_OFFSET_get_pict_set_num(data)                             ((0xFF000000&(data))>>24)
#define DC_PICT_SET_OFFSET_pict_offset_rd_shift                               (23)
#define DC_PICT_SET_OFFSET_pict_offset_rd_mask                                (0x00800000)
#define DC_PICT_SET_OFFSET_pict_offset_rd(data)                               (0x00800000&((data)<<23))
#define DC_PICT_SET_OFFSET_pict_offset_rd_src(data)                           ((0x00800000&(data))>>23)
#define DC_PICT_SET_OFFSET_get_pict_offset_rd(data)                           ((0x00800000&(data))>>23)
#define DC_PICT_SET_OFFSET_pict_set_wide_shift                                (20)
#define DC_PICT_SET_OFFSET_pict_set_wide_mask                                 (0x00100000)
#define DC_PICT_SET_OFFSET_pict_set_wide(data)                                (0x00100000&((data)<<20))
#define DC_PICT_SET_OFFSET_pict_set_wide_src(data)                            ((0x00100000&(data))>>20)
#define DC_PICT_SET_OFFSET_get_pict_set_wide(data)                            ((0x00100000&(data))>>20)
#define DC_PICT_SET_OFFSET_pict_set_offset_y_shift                            (10)
#define DC_PICT_SET_OFFSET_pict_set_offset_y_mask                             (0x000FFC00)
#define DC_PICT_SET_OFFSET_pict_set_offset_y(data)                            (0x000FFC00&((data)<<10))
#define DC_PICT_SET_OFFSET_pict_set_offset_y_src(data)                        ((0x000FFC00&(data))>>10)
#define DC_PICT_SET_OFFSET_get_pict_set_offset_y(data)                        ((0x000FFC00&(data))>>10)
#define DC_PICT_SET_OFFSET_pict_set_offset_x_shift                            (0)
#define DC_PICT_SET_OFFSET_pict_set_offset_x_mask                             (0x000003FF)
#define DC_PICT_SET_OFFSET_pict_set_offset_x(data)                            (0x000003FF&((data)<<0))
#define DC_PICT_SET_OFFSET_pict_set_offset_x_src(data)                        ((0x000003FF&(data))>>0)
#define DC_PICT_SET_OFFSET_get_pict_set_offset_x(data)                        ((0x000003FF&(data))>>0)


#define DC_REQ_STATUS                                                         0x18007024
#define DC_REQ_STATUS_reg_addr                                                "0xB8007024"
#define DC_REQ_STATUS_reg                                                     0xB8007024
#define set_DC_REQ_STATUS_reg(data)   (*((volatile unsigned int*) DC_REQ_STATUS_reg)=data)
#define get_DC_REQ_STATUS_reg   (*((volatile unsigned int*) DC_REQ_STATUS_reg))
#define DC_REQ_STATUS_inst_adr                                                "0x0009"
#define DC_REQ_STATUS_inst                                                    0x0009
#define DC_REQ_STATUS_req_pending_shift                                       (12)
#define DC_REQ_STATUS_req_pending_mask                                        (0x00001000)
#define DC_REQ_STATUS_req_pending(data)                                       (0x00001000&((data)<<12))
#define DC_REQ_STATUS_req_pending_src(data)                                   ((0x00001000&(data))>>12)
#define DC_REQ_STATUS_get_req_pending(data)                                   ((0x00001000&(data))>>12)
#define DC_REQ_STATUS_req_id_shift                                            (0)
#define DC_REQ_STATUS_req_id_mask                                             (0x00000FFF)
#define DC_REQ_STATUS_req_id(data)                                            (0x00000FFF&((data)<<0))
#define DC_REQ_STATUS_req_id_src(data)                                        ((0x00000FFF&(data))>>0)
#define DC_REQ_STATUS_get_req_id(data)                                        ((0x00000FFF&(data))>>0)


#define MISC2                                                          0x18007028
#define MISC2_reg_addr                                                 "0xB8007028"
#define MISC2_reg                                                      0xB8007028
#define set_MISC2_reg(data)   (*((volatile unsigned int*) MISC2_reg)=data)
#define get_MISC2_reg   (*((volatile unsigned int*) MISC2_reg))
#define MISC2_inst_adr                                                 "0x000A"
#define MISC2_inst                                                     0x000A
#define MISC2_pre_arb_merge_shift                                      (31)
#define MISC2_pre_arb_merge_mask                                       (0x80000000)
#define MISC2_pre_arb_merge(data)                                      (0x80000000&((data)<<31))
#define MISC2_pre_arb_merge_src(data)                                  ((0x80000000&(data))>>31)
#define MISC2_get_pre_arb_merge(data)                                  ((0x80000000&(data))>>31)
#define MISC2_qfifo_cnt_full_threshold_shift                           (24)
#define MISC2_qfifo_cnt_full_threshold_mask                            (0x1F000000)
#define MISC2_qfifo_cnt_full_threshold(data)                           (0x1F000000&((data)<<24))
#define MISC2_qfifo_cnt_full_threshold_src(data)                       ((0x1F000000&(data))>>24)
#define MISC2_get_qfifo_cnt_full_threshold(data)                       ((0x1F000000&(data))>>24)
#define MISC2_full_cmd_count_shift                                     (20)
#define MISC2_full_cmd_count_mask                                      (0x00F00000)
#define MISC2_full_cmd_count(data)                                     (0x00F00000&((data)<<20))
#define MISC2_full_cmd_count_src(data)                                 ((0x00F00000&(data))>>20)
#define MISC2_get_full_cmd_count(data)                                 ((0x00F00000&(data))>>20)
#define MISC2_pre_tra_rd_cnt_shift                                     (10)
#define MISC2_pre_tra_rd_cnt_mask                                      (0x000FFC00)
#define MISC2_pre_tra_rd_cnt(data)                                     (0x000FFC00&((data)<<10))
#define MISC2_pre_tra_rd_cnt_src(data)                                 ((0x000FFC00&(data))>>10)
#define MISC2_get_pre_tra_rd_cnt(data)                                 ((0x000FFC00&(data))>>10)
#define MISC2_pre_tra_wr_cnt_shift                                     (0)
#define MISC2_pre_tra_wr_cnt_mask                                      (0x000003FF)
#define MISC2_pre_tra_wr_cnt(data)                                     (0x000003FF&((data)<<0))
#define MISC2_pre_tra_wr_cnt_src(data)                                 ((0x000003FF&(data))>>0)
#define MISC2_get_pre_tra_wr_cnt(data)                                 ((0x000003FF&(data))>>0)


#define MISC3                                                          0x1800702C
#define MISC3_reg_addr                                                 "0xB800702C"
#define MISC3_reg                                                      0xB800702C
#define set_MISC3_reg(data)   (*((volatile unsigned int*) MISC3_reg)=data)
#define get_MISC3_reg   (*((volatile unsigned int*) MISC3_reg))
#define MISC3_inst_adr                                                 "0x000B"
#define MISC3_inst                                                     0x000B
#define MISC3_wfifo_cnt_full_threshold_shift                           (24)
#define MISC3_wfifo_cnt_full_threshold_mask                            (0x3F000000)
#define MISC3_wfifo_cnt_full_threshold(data)                           (0x3F000000&((data)<<24))
#define MISC3_wfifo_cnt_full_threshold_src(data)                       ((0x3F000000&(data))>>24)
#define MISC3_get_wfifo_cnt_full_threshold(data)                       ((0x3F000000&(data))>>24)
#define MISC3_gde2_cmd_queue_flush_shift                               (19)
#define MISC3_gde2_cmd_queue_flush_mask                                (0x00080000)
#define MISC3_gde2_cmd_queue_flush(data)                               (0x00080000&((data)<<19))
#define MISC3_gde2_cmd_queue_flush_src(data)                           ((0x00080000&(data))>>19)
#define MISC3_get_gde2_cmd_queue_flush(data)                           ((0x00080000&(data))>>19)
#define MISC3_gde2_cmd_grp_disable_shift                               (18)
#define MISC3_gde2_cmd_grp_disable_mask                                (0x00040000)
#define MISC3_gde2_cmd_grp_disable(data)                               (0x00040000&((data)<<18))
#define MISC3_gde2_cmd_grp_disable_src(data)                           ((0x00040000&(data))>>18)
#define MISC3_get_gde2_cmd_grp_disable(data)                           ((0x00040000&(data))>>18)
#define MISC3_ve2_cmd_queue_flush_shift                                (17)
#define MISC3_ve2_cmd_queue_flush_mask                                 (0x00020000)
#define MISC3_ve2_cmd_queue_flush(data)                                (0x00020000&((data)<<17))
#define MISC3_ve2_cmd_queue_flush_src(data)                            ((0x00020000&(data))>>17)
#define MISC3_get_ve2_cmd_queue_flush(data)                            ((0x00020000&(data))>>17)
#define MISC3_ve2_cmd_grp_disable_shift                                (16)
#define MISC3_ve2_cmd_grp_disable_mask                                 (0x00010000)
#define MISC3_ve2_cmd_grp_disable(data)                                (0x00010000&((data)<<16))
#define MISC3_ve2_cmd_grp_disable_src(data)                            ((0x00010000&(data))>>16)
#define MISC3_get_ve2_cmd_grp_disable(data)                            ((0x00010000&(data))>>16)
#define MISC3_ve_cmd_queue_flush_shift                                 (9)
#define MISC3_ve_cmd_queue_flush_mask                                  (0x00000200)
#define MISC3_ve_cmd_queue_flush(data)                                 (0x00000200&((data)<<9))
#define MISC3_ve_cmd_queue_flush_src(data)                             ((0x00000200&(data))>>9)
#define MISC3_get_ve_cmd_queue_flush(data)                             ((0x00000200&(data))>>9)
#define MISC3_ve_cmd_grp_disable_shift                                 (8)
#define MISC3_ve_cmd_grp_disable_mask                                  (0x00000100)
#define MISC3_ve_cmd_grp_disable(data)                                 (0x00000100&((data)<<8))
#define MISC3_ve_cmd_grp_disable_src(data)                             ((0x00000100&(data))>>8)
#define MISC3_get_ve_cmd_grp_disable(data)                             ((0x00000100&(data))>>8)
#define MISC3_tvsb4_cmd_queue_flush_shift                              (7)
#define MISC3_tvsb4_cmd_queue_flush_mask                               (0x00000080)
#define MISC3_tvsb4_cmd_queue_flush(data)                              (0x00000080&((data)<<7))
#define MISC3_tvsb4_cmd_queue_flush_src(data)                          ((0x00000080&(data))>>7)
#define MISC3_get_tvsb4_cmd_queue_flush(data)                          ((0x00000080&(data))>>7)
#define MISC3_tvsb4_cmd_grp_disable_shift                              (6)
#define MISC3_tvsb4_cmd_grp_disable_mask                               (0x00000040)
#define MISC3_tvsb4_cmd_grp_disable(data)                              (0x00000040&((data)<<6))
#define MISC3_tvsb4_cmd_grp_disable_src(data)                          ((0x00000040&(data))>>6)
#define MISC3_get_tvsb4_cmd_grp_disable(data)                          ((0x00000040&(data))>>6)
#define MISC3_tvsb3_cmd_queue_flush_shift                              (5)
#define MISC3_tvsb3_cmd_queue_flush_mask                               (0x00000020)
#define MISC3_tvsb3_cmd_queue_flush(data)                              (0x00000020&((data)<<5))
#define MISC3_tvsb3_cmd_queue_flush_src(data)                          ((0x00000020&(data))>>5)
#define MISC3_get_tvsb3_cmd_queue_flush(data)                          ((0x00000020&(data))>>5)
#define MISC3_tvsb3_cmd_grp_disable_shift                              (4)
#define MISC3_tvsb3_cmd_grp_disable_mask                               (0x00000010)
#define MISC3_tvsb3_cmd_grp_disable(data)                              (0x00000010&((data)<<4))
#define MISC3_tvsb3_cmd_grp_disable_src(data)                          ((0x00000010&(data))>>4)
#define MISC3_get_tvsb3_cmd_grp_disable(data)                          ((0x00000010&(data))>>4)
#define MISC3_enable_arb_delay_by_tv_sb1_grant_shift                   (2)
#define MISC3_enable_arb_delay_by_tv_sb1_grant_mask                    (0x00000004)
#define MISC3_enable_arb_delay_by_tv_sb1_grant(data)                   (0x00000004&((data)<<2))
#define MISC3_enable_arb_delay_by_tv_sb1_grant_src(data)               ((0x00000004&(data))>>2)
#define MISC3_get_enable_arb_delay_by_tv_sb1_grant(data)               ((0x00000004&(data))>>2)
#define MISC3_gde_cmd_queue_flush_shift                                (1)
#define MISC3_gde_cmd_queue_flush_mask                                 (0x00000002)
#define MISC3_gde_cmd_queue_flush(data)                                (0x00000002&((data)<<1))
#define MISC3_gde_cmd_queue_flush_src(data)                            ((0x00000002&(data))>>1)
#define MISC3_get_gde_cmd_queue_flush(data)                            ((0x00000002&(data))>>1)
#define MISC3_gde_cmd_grp_disable_shift                                (0)
#define MISC3_gde_cmd_grp_disable_mask                                 (0x00000001)
#define MISC3_gde_cmd_grp_disable(data)                                (0x00000001&((data)<<0))
#define MISC3_gde_cmd_grp_disable_src(data)                            ((0x00000001&(data))>>0)
#define MISC3_get_gde_cmd_grp_disable(data)                            ((0x00000001&(data))>>0)


#define DC_SFMODE0                                                            0x18007040
#define DC_SFMODE0_reg_addr                                                   "0xB8007040"
#define DC_SFMODE0_reg                                                        0xB8007040
#define set_DC_SFMODE0_reg(data)   (*((volatile unsigned int*) DC_SFMODE0_reg)=data)
#define get_DC_SFMODE0_reg   (*((volatile unsigned int*) DC_SFMODE0_reg))
#define DC_SFMODE0_inst_adr                                                   "0x0010"
#define DC_SFMODE0_inst                                                       0x0010
#define DC_SFMODE0_sfmode_pattern0_shift                                      (0)
#define DC_SFMODE0_sfmode_pattern0_mask                                       (0xFFFFFFFF)
#define DC_SFMODE0_sfmode_pattern0(data)                                      (0xFFFFFFFF&((data)<<0))
#define DC_SFMODE0_sfmode_pattern0_src(data)                                  ((0xFFFFFFFF&(data))>>0)
#define DC_SFMODE0_get_sfmode_pattern0(data)                                  ((0xFFFFFFFF&(data))>>0)


#define DC_SFMODE1                                                            0x18007044
#define DC_SFMODE1_reg_addr                                                   "0xB8007044"
#define DC_SFMODE1_reg                                                        0xB8007044
#define set_DC_SFMODE1_reg(data)   (*((volatile unsigned int*) DC_SFMODE1_reg)=data)
#define get_DC_SFMODE1_reg   (*((volatile unsigned int*) DC_SFMODE1_reg))
#define DC_SFMODE1_inst_adr                                                   "0x0011"
#define DC_SFMODE1_inst                                                       0x0011
#define DC_SFMODE1_sfmode_pattern1_shift                                      (0)
#define DC_SFMODE1_sfmode_pattern1_mask                                       (0xFFFFFFFF)
#define DC_SFMODE1_sfmode_pattern1(data)                                      (0xFFFFFFFF&((data)<<0))
#define DC_SFMODE1_sfmode_pattern1_src(data)                                  ((0xFFFFFFFF&(data))>>0)
#define DC_SFMODE1_get_sfmode_pattern1(data)                                  ((0xFFFFFFFF&(data))>>0)


#define DC_SFMODE2                                                            0x18007048
#define DC_SFMODE2_reg_addr                                                   "0xB8007048"
#define DC_SFMODE2_reg                                                        0xB8007048
#define set_DC_SFMODE2_reg(data)   (*((volatile unsigned int*) DC_SFMODE2_reg)=data)
#define get_DC_SFMODE2_reg   (*((volatile unsigned int*) DC_SFMODE2_reg))
#define DC_SFMODE2_inst_adr                                                   "0x0012"
#define DC_SFMODE2_inst                                                       0x0012
#define DC_SFMODE2_sfmode_pattern2_shift                                      (0)
#define DC_SFMODE2_sfmode_pattern2_mask                                       (0xFFFFFFFF)
#define DC_SFMODE2_sfmode_pattern2(data)                                      (0xFFFFFFFF&((data)<<0))
#define DC_SFMODE2_sfmode_pattern2_src(data)                                  ((0xFFFFFFFF&(data))>>0)
#define DC_SFMODE2_get_sfmode_pattern2(data)                                  ((0xFFFFFFFF&(data))>>0)


#define DC_SFMODE3                                                            0x1800704C
#define DC_SFMODE3_reg_addr                                                   "0xB800704C"
#define DC_SFMODE3_reg                                                        0xB800704C
#define set_DC_SFMODE3_reg(data)   (*((volatile unsigned int*) DC_SFMODE3_reg)=data)
#define get_DC_SFMODE3_reg   (*((volatile unsigned int*) DC_SFMODE3_reg))
#define DC_SFMODE3_inst_adr                                                   "0x0013"
#define DC_SFMODE3_inst                                                       0x0013
#define DC_SFMODE3_sfmode_pattern3_shift                                      (0)
#define DC_SFMODE3_sfmode_pattern3_mask                                       (0xFFFFFFFF)
#define DC_SFMODE3_sfmode_pattern3(data)                                      (0xFFFFFFFF&((data)<<0))
#define DC_SFMODE3_sfmode_pattern3_src(data)                                  ((0xFFFFFFFF&(data))>>0)
#define DC_SFMODE3_get_sfmode_pattern3(data)                                  ((0xFFFFFFFF&(data))>>0)


#define DC_SFMODE_CMP0                                                        0x18007050
#define DC_SFMODE_CMP0_reg_addr                                               "0xB8007050"
#define DC_SFMODE_CMP0_reg                                                    0xB8007050
#define set_DC_SFMODE_CMP0_reg(data)   (*((volatile unsigned int*) DC_SFMODE_CMP0_reg)=data)
#define get_DC_SFMODE_CMP0_reg   (*((volatile unsigned int*) DC_SFMODE_CMP0_reg))
#define DC_SFMODE_CMP0_inst_adr                                               "0x0014"
#define DC_SFMODE_CMP0_inst                                                   0x0014
#define DC_SFMODE_CMP0_sfmode_cmp_rlt0_shift                                  (0)
#define DC_SFMODE_CMP0_sfmode_cmp_rlt0_mask                                   (0xFFFFFFFF)
#define DC_SFMODE_CMP0_sfmode_cmp_rlt0(data)                                  (0xFFFFFFFF&((data)<<0))
#define DC_SFMODE_CMP0_sfmode_cmp_rlt0_src(data)                              ((0xFFFFFFFF&(data))>>0)
#define DC_SFMODE_CMP0_get_sfmode_cmp_rlt0(data)                              ((0xFFFFFFFF&(data))>>0)


#define DC_SFMODE_CMP1                                                        0x18007054
#define DC_SFMODE_CMP1_reg_addr                                               "0xB8007054"
#define DC_SFMODE_CMP1_reg                                                    0xB8007054
#define set_DC_SFMODE_CMP1_reg(data)   (*((volatile unsigned int*) DC_SFMODE_CMP1_reg)=data)
#define get_DC_SFMODE_CMP1_reg   (*((volatile unsigned int*) DC_SFMODE_CMP1_reg))
#define DC_SFMODE_CMP1_inst_adr                                               "0x0015"
#define DC_SFMODE_CMP1_inst                                                   0x0015
#define DC_SFMODE_CMP1_sfmode_cmp_rlt1_shift                                  (0)
#define DC_SFMODE_CMP1_sfmode_cmp_rlt1_mask                                   (0xFFFFFFFF)
#define DC_SFMODE_CMP1_sfmode_cmp_rlt1(data)                                  (0xFFFFFFFF&((data)<<0))
#define DC_SFMODE_CMP1_sfmode_cmp_rlt1_src(data)                              ((0xFFFFFFFF&(data))>>0)
#define DC_SFMODE_CMP1_get_sfmode_cmp_rlt1(data)                              ((0xFFFFFFFF&(data))>>0)


#define DC_SFMODE_CMP2                                                        0x18007058
#define DC_SFMODE_CMP2_reg_addr                                               "0xB8007058"
#define DC_SFMODE_CMP2_reg                                                    0xB8007058
#define set_DC_SFMODE_CMP2_reg(data)   (*((volatile unsigned int*) DC_SFMODE_CMP2_reg)=data)
#define get_DC_SFMODE_CMP2_reg   (*((volatile unsigned int*) DC_SFMODE_CMP2_reg))
#define DC_SFMODE_CMP2_inst_adr                                               "0x0016"
#define DC_SFMODE_CMP2_inst                                                   0x0016
#define DC_SFMODE_CMP2_sfmode_cmp_rlt2_shift                                  (0)
#define DC_SFMODE_CMP2_sfmode_cmp_rlt2_mask                                   (0xFFFFFFFF)
#define DC_SFMODE_CMP2_sfmode_cmp_rlt2(data)                                  (0xFFFFFFFF&((data)<<0))
#define DC_SFMODE_CMP2_sfmode_cmp_rlt2_src(data)                              ((0xFFFFFFFF&(data))>>0)
#define DC_SFMODE_CMP2_get_sfmode_cmp_rlt2(data)                              ((0xFFFFFFFF&(data))>>0)


#define DC_SFMODE_CMP3                                                        0x1800705C
#define DC_SFMODE_CMP3_reg_addr                                               "0xB800705C"
#define DC_SFMODE_CMP3_reg                                                    0xB800705C
#define set_DC_SFMODE_CMP3_reg(data)   (*((volatile unsigned int*) DC_SFMODE_CMP3_reg)=data)
#define get_DC_SFMODE_CMP3_reg   (*((volatile unsigned int*) DC_SFMODE_CMP3_reg))
#define DC_SFMODE_CMP3_inst_adr                                               "0x0017"
#define DC_SFMODE_CMP3_inst                                                   0x0017
#define DC_SFMODE_CMP3_sfmode_cmp_rlt3_shift                                  (0)
#define DC_SFMODE_CMP3_sfmode_cmp_rlt3_mask                                   (0xFFFFFFFF)
#define DC_SFMODE_CMP3_sfmode_cmp_rlt3(data)                                  (0xFFFFFFFF&((data)<<0))
#define DC_SFMODE_CMP3_sfmode_cmp_rlt3_src(data)                              ((0xFFFFFFFF&(data))>>0)
#define DC_SFMODE_CMP3_get_sfmode_cmp_rlt3(data)                              ((0xFFFFFFFF&(data))>>0)


#define DC_DEBUG                                                              0x18007060
#define DC_DEBUG_reg_addr                                                     "0xB8007060"
#define DC_DEBUG_reg                                                          0xB8007060
#define set_DC_DEBUG_reg(data)   (*((volatile unsigned int*) DC_DEBUG_reg)=data)
#define get_DC_DEBUG_reg   (*((volatile unsigned int*) DC_DEBUG_reg))
#define DC_DEBUG_inst_adr                                                     "0x0018"
#define DC_DEBUG_inst                                                         0x0018
#define DC_DEBUG_Debug_sys2_shift                                             (17)
#define DC_DEBUG_Debug_sys2_mask                                              (0x00020000)
#define DC_DEBUG_Debug_sys2(data)                                             (0x00020000&((data)<<17))
#define DC_DEBUG_Debug_sys2_src(data)                                         ((0x00020000&(data))>>17)
#define DC_DEBUG_get_Debug_sys2(data)                                         ((0x00020000&(data))>>17)
#define DC_DEBUG_Debug_en_shift                                               (16)
#define DC_DEBUG_Debug_en_mask                                                (0x00010000)
#define DC_DEBUG_Debug_en(data)                                               (0x00010000&((data)<<16))
#define DC_DEBUG_Debug_en_src(data)                                           ((0x00010000&(data))>>16)
#define DC_DEBUG_get_Debug_en(data)                                           ((0x00010000&(data))>>16)
#define DC_DEBUG_Debug_sel_1_shift                                            (8)
#define DC_DEBUG_Debug_sel_1_mask                                             (0x00003F00)
#define DC_DEBUG_Debug_sel_1(data)                                            (0x00003F00&((data)<<8))
#define DC_DEBUG_Debug_sel_1_src(data)                                        ((0x00003F00&(data))>>8)
#define DC_DEBUG_get_Debug_sel_1(data)                                        ((0x00003F00&(data))>>8)
#define DC_DEBUG_Debug_sel_0_shift                                            (0)
#define DC_DEBUG_Debug_sel_0_mask                                             (0x0000003F)
#define DC_DEBUG_Debug_sel_0(data)                                            (0x0000003F&((data)<<0))
#define DC_DEBUG_Debug_sel_0_src(data)                                        ((0x0000003F&(data))>>0)
#define DC_DEBUG_get_Debug_sel_0(data)                                        ((0x0000003F&(data))>>0)


#define DC_DEBUG_STATUS                                                       0x18007064
#define DC_DEBUG_STATUS_reg_addr                                              "0xB8007064"
#define DC_DEBUG_STATUS_reg                                                   0xB8007064
#define set_DC_DEBUG_STATUS_reg(data)   (*((volatile unsigned int*) DC_DEBUG_STATUS_reg)=data)
#define get_DC_DEBUG_STATUS_reg   (*((volatile unsigned int*) DC_DEBUG_STATUS_reg))
#define DC_DEBUG_STATUS_inst_adr                                              "0x0019"
#define DC_DEBUG_STATUS_inst                                                  0x0019
#define DC_DEBUG_STATUS_write_cmd_fifo_1_underflow_shift                      (29)
#define DC_DEBUG_STATUS_write_cmd_fifo_1_underflow_mask                       (0x20000000)
#define DC_DEBUG_STATUS_write_cmd_fifo_1_underflow(data)                      (0x20000000&((data)<<29))
#define DC_DEBUG_STATUS_write_cmd_fifo_1_underflow_src(data)                  ((0x20000000&(data))>>29)
#define DC_DEBUG_STATUS_get_write_cmd_fifo_1_underflow(data)                  ((0x20000000&(data))>>29)
#define DC_DEBUG_STATUS_write_cmd_fifo_0_underflow_shift                      (28)
#define DC_DEBUG_STATUS_write_cmd_fifo_0_underflow_mask                       (0x10000000)
#define DC_DEBUG_STATUS_write_cmd_fifo_0_underflow(data)                      (0x10000000&((data)<<28))
#define DC_DEBUG_STATUS_write_cmd_fifo_0_underflow_src(data)                  ((0x10000000&(data))>>28)
#define DC_DEBUG_STATUS_get_write_cmd_fifo_0_underflow(data)                  ((0x10000000&(data))>>28)
#define DC_DEBUG_STATUS_read_cmd_fifo_2_underflow_shift                       (27)
#define DC_DEBUG_STATUS_read_cmd_fifo_2_underflow_mask                        (0x08000000)
#define DC_DEBUG_STATUS_read_cmd_fifo_2_underflow(data)                       (0x08000000&((data)<<27))
#define DC_DEBUG_STATUS_read_cmd_fifo_2_underflow_src(data)                   ((0x08000000&(data))>>27)
#define DC_DEBUG_STATUS_get_read_cmd_fifo_2_underflow(data)                   ((0x08000000&(data))>>27)
#define DC_DEBUG_STATUS_read_cmd_fifo_1_underflow_shift                       (26)
#define DC_DEBUG_STATUS_read_cmd_fifo_1_underflow_mask                        (0x04000000)
#define DC_DEBUG_STATUS_read_cmd_fifo_1_underflow(data)                       (0x04000000&((data)<<26))
#define DC_DEBUG_STATUS_read_cmd_fifo_1_underflow_src(data)                   ((0x04000000&(data))>>26)
#define DC_DEBUG_STATUS_get_read_cmd_fifo_1_underflow(data)                   ((0x04000000&(data))>>26)
#define DC_DEBUG_STATUS_read_cmd_fifo_0_underflow_shift                       (25)
#define DC_DEBUG_STATUS_read_cmd_fifo_0_underflow_mask                        (0x02000000)
#define DC_DEBUG_STATUS_read_cmd_fifo_0_underflow(data)                       (0x02000000&((data)<<25))
#define DC_DEBUG_STATUS_read_cmd_fifo_0_underflow_src(data)                   ((0x02000000&(data))>>25)
#define DC_DEBUG_STATUS_get_read_cmd_fifo_0_underflow(data)                   ((0x02000000&(data))>>25)
#define DC_DEBUG_STATUS_write_cmd_fifo_1_overflow_shift                       (24)
#define DC_DEBUG_STATUS_write_cmd_fifo_1_overflow_mask                        (0x01000000)
#define DC_DEBUG_STATUS_write_cmd_fifo_1_overflow(data)                       (0x01000000&((data)<<24))
#define DC_DEBUG_STATUS_write_cmd_fifo_1_overflow_src(data)                   ((0x01000000&(data))>>24)
#define DC_DEBUG_STATUS_get_write_cmd_fifo_1_overflow(data)                   ((0x01000000&(data))>>24)
#define DC_DEBUG_STATUS_write_cmd_fifo_0_overflow_shift                       (23)
#define DC_DEBUG_STATUS_write_cmd_fifo_0_overflow_mask                        (0x00800000)
#define DC_DEBUG_STATUS_write_cmd_fifo_0_overflow(data)                       (0x00800000&((data)<<23))
#define DC_DEBUG_STATUS_write_cmd_fifo_0_overflow_src(data)                   ((0x00800000&(data))>>23)
#define DC_DEBUG_STATUS_get_write_cmd_fifo_0_overflow(data)                   ((0x00800000&(data))>>23)
#define DC_DEBUG_STATUS_read_cmd_fifo_2_overflow_shift                        (22)
#define DC_DEBUG_STATUS_read_cmd_fifo_2_overflow_mask                         (0x00400000)
#define DC_DEBUG_STATUS_read_cmd_fifo_2_overflow(data)                        (0x00400000&((data)<<22))
#define DC_DEBUG_STATUS_read_cmd_fifo_2_overflow_src(data)                    ((0x00400000&(data))>>22)
#define DC_DEBUG_STATUS_get_read_cmd_fifo_2_overflow(data)                    ((0x00400000&(data))>>22)
#define DC_DEBUG_STATUS_read_cmd_fifo_1_overflow_shift                        (21)
#define DC_DEBUG_STATUS_read_cmd_fifo_1_overflow_mask                         (0x00200000)
#define DC_DEBUG_STATUS_read_cmd_fifo_1_overflow(data)                        (0x00200000&((data)<<21))
#define DC_DEBUG_STATUS_read_cmd_fifo_1_overflow_src(data)                    ((0x00200000&(data))>>21)
#define DC_DEBUG_STATUS_get_read_cmd_fifo_1_overflow(data)                    ((0x00200000&(data))>>21)
#define DC_DEBUG_STATUS_read_cmd_fifo_0_overflow_shift                        (20)
#define DC_DEBUG_STATUS_read_cmd_fifo_0_overflow_mask                         (0x00100000)
#define DC_DEBUG_STATUS_read_cmd_fifo_0_overflow(data)                        (0x00100000&((data)<<20))
#define DC_DEBUG_STATUS_read_cmd_fifo_0_overflow_src(data)                    ((0x00100000&(data))>>20)
#define DC_DEBUG_STATUS_get_read_cmd_fifo_0_overflow(data)                    ((0x00100000&(data))>>20)
#define DC_DEBUG_STATUS_exsram_fifo_underflow_shift                           (17)
#define DC_DEBUG_STATUS_exsram_fifo_underflow_mask                            (0x00020000)
#define DC_DEBUG_STATUS_exsram_fifo_underflow(data)                           (0x00020000&((data)<<17))
#define DC_DEBUG_STATUS_exsram_fifo_underflow_src(data)                       ((0x00020000&(data))>>17)
#define DC_DEBUG_STATUS_get_exsram_fifo_underflow(data)                       ((0x00020000&(data))>>17)
#define DC_DEBUG_STATUS_exsram_fifo_overflow_shift                            (16)
#define DC_DEBUG_STATUS_exsram_fifo_overflow_mask                             (0x00010000)
#define DC_DEBUG_STATUS_exsram_fifo_overflow(data)                            (0x00010000&((data)<<16))
#define DC_DEBUG_STATUS_exsram_fifo_overflow_src(data)                        ((0x00010000&(data))>>16)
#define DC_DEBUG_STATUS_get_exsram_fifo_overflow(data)                        ((0x00010000&(data))>>16)
#define DC_DEBUG_STATUS_write_fifo_1_underflow_shift                          (12)
#define DC_DEBUG_STATUS_write_fifo_1_underflow_mask                           (0x00001000)
#define DC_DEBUG_STATUS_write_fifo_1_underflow(data)                          (0x00001000&((data)<<12))
#define DC_DEBUG_STATUS_write_fifo_1_underflow_src(data)                      ((0x00001000&(data))>>12)
#define DC_DEBUG_STATUS_get_write_fifo_1_underflow(data)                      ((0x00001000&(data))>>12)
#define DC_DEBUG_STATUS_write_fifo_0_underflow_shift                          (11)
#define DC_DEBUG_STATUS_write_fifo_0_underflow_mask                           (0x00000800)
#define DC_DEBUG_STATUS_write_fifo_0_underflow(data)                          (0x00000800&((data)<<11))
#define DC_DEBUG_STATUS_write_fifo_0_underflow_src(data)                      ((0x00000800&(data))>>11)
#define DC_DEBUG_STATUS_get_write_fifo_0_underflow(data)                      ((0x00000800&(data))>>11)
#define DC_DEBUG_STATUS_read_fifo_2_underflow_shift                           (10)
#define DC_DEBUG_STATUS_read_fifo_2_underflow_mask                            (0x00000400)
#define DC_DEBUG_STATUS_read_fifo_2_underflow(data)                           (0x00000400&((data)<<10))
#define DC_DEBUG_STATUS_read_fifo_2_underflow_src(data)                       ((0x00000400&(data))>>10)
#define DC_DEBUG_STATUS_get_read_fifo_2_underflow(data)                       ((0x00000400&(data))>>10)
#define DC_DEBUG_STATUS_read_fifo_1_underflow_shift                           (9)
#define DC_DEBUG_STATUS_read_fifo_1_underflow_mask                            (0x00000200)
#define DC_DEBUG_STATUS_read_fifo_1_underflow(data)                           (0x00000200&((data)<<9))
#define DC_DEBUG_STATUS_read_fifo_1_underflow_src(data)                       ((0x00000200&(data))>>9)
#define DC_DEBUG_STATUS_get_read_fifo_1_underflow(data)                       ((0x00000200&(data))>>9)
#define DC_DEBUG_STATUS_read_fifo_0_underflow_shift                           (8)
#define DC_DEBUG_STATUS_read_fifo_0_underflow_mask                            (0x00000100)
#define DC_DEBUG_STATUS_read_fifo_0_underflow(data)                           (0x00000100&((data)<<8))
#define DC_DEBUG_STATUS_read_fifo_0_underflow_src(data)                       ((0x00000100&(data))>>8)
#define DC_DEBUG_STATUS_get_read_fifo_0_underflow(data)                       ((0x00000100&(data))>>8)
#define DC_DEBUG_STATUS_write_fifo_1_overflow_shift                           (4)
#define DC_DEBUG_STATUS_write_fifo_1_overflow_mask                            (0x00000010)
#define DC_DEBUG_STATUS_write_fifo_1_overflow(data)                           (0x00000010&((data)<<4))
#define DC_DEBUG_STATUS_write_fifo_1_overflow_src(data)                       ((0x00000010&(data))>>4)
#define DC_DEBUG_STATUS_get_write_fifo_1_overflow(data)                       ((0x00000010&(data))>>4)
#define DC_DEBUG_STATUS_write_fifo_0_overflow_shift                           (3)
#define DC_DEBUG_STATUS_write_fifo_0_overflow_mask                            (0x00000008)
#define DC_DEBUG_STATUS_write_fifo_0_overflow(data)                           (0x00000008&((data)<<3))
#define DC_DEBUG_STATUS_write_fifo_0_overflow_src(data)                       ((0x00000008&(data))>>3)
#define DC_DEBUG_STATUS_get_write_fifo_0_overflow(data)                       ((0x00000008&(data))>>3)
#define DC_DEBUG_STATUS_read_fifo_2_overflow_shift                            (2)
#define DC_DEBUG_STATUS_read_fifo_2_overflow_mask                             (0x00000004)
#define DC_DEBUG_STATUS_read_fifo_2_overflow(data)                            (0x00000004&((data)<<2))
#define DC_DEBUG_STATUS_read_fifo_2_overflow_src(data)                        ((0x00000004&(data))>>2)
#define DC_DEBUG_STATUS_get_read_fifo_2_overflow(data)                        ((0x00000004&(data))>>2)
#define DC_DEBUG_STATUS_read_fifo_1_overflow_shift                            (1)
#define DC_DEBUG_STATUS_read_fifo_1_overflow_mask                             (0x00000002)
#define DC_DEBUG_STATUS_read_fifo_1_overflow(data)                            (0x00000002&((data)<<1))
#define DC_DEBUG_STATUS_read_fifo_1_overflow_src(data)                        ((0x00000002&(data))>>1)
#define DC_DEBUG_STATUS_get_read_fifo_1_overflow(data)                        ((0x00000002&(data))>>1)
#define DC_DEBUG_STATUS_read_fifo_0_overflow_shift                            (0)
#define DC_DEBUG_STATUS_read_fifo_0_overflow_mask                             (0x00000001)
#define DC_DEBUG_STATUS_read_fifo_0_overflow(data)                            (0x00000001&((data)<<0))
#define DC_DEBUG_STATUS_read_fifo_0_overflow_src(data)                        ((0x00000001&(data))>>0)
#define DC_DEBUG_STATUS_get_read_fifo_0_overflow(data)                        ((0x00000001&(data))>>0)


#define DC_PRIORITY_CTRL0                                                     0x18007080
#define DC_PRIORITY_CTRL0_reg_addr                                            "0xB8007080"
#define DC_PRIORITY_CTRL0_reg                                                 0xB8007080
#define set_DC_PRIORITY_CTRL0_reg(data)   (*((volatile unsigned int*) DC_PRIORITY_CTRL0_reg)=data)
#define get_DC_PRIORITY_CTRL0_reg   (*((volatile unsigned int*) DC_PRIORITY_CTRL0_reg))
#define DC_PRIORITY_CTRL0_inst_adr                                            "0x0020"
#define DC_PRIORITY_CTRL0_inst                                                0x0020
#define DC_PRIORITY_CTRL0_C0_LATCNT_END_shift                                 (16)
#define DC_PRIORITY_CTRL0_C0_LATCNT_END_mask                                  (0x00FF0000)
#define DC_PRIORITY_CTRL0_C0_LATCNT_END(data)                                 (0x00FF0000&((data)<<16))
#define DC_PRIORITY_CTRL0_C0_LATCNT_END_src(data)                             ((0x00FF0000&(data))>>16)
#define DC_PRIORITY_CTRL0_get_C0_LATCNT_END(data)                             ((0x00FF0000&(data))>>16)
#define DC_PRIORITY_CTRL0_C0_LATCNT_BEG_shift                                 (0)
#define DC_PRIORITY_CTRL0_C0_LATCNT_BEG_mask                                  (0x000000FF)
#define DC_PRIORITY_CTRL0_C0_LATCNT_BEG(data)                                 (0x000000FF&((data)<<0))
#define DC_PRIORITY_CTRL0_C0_LATCNT_BEG_src(data)                             ((0x000000FF&(data))>>0)
#define DC_PRIORITY_CTRL0_get_C0_LATCNT_BEG(data)                             ((0x000000FF&(data))>>0)


#define DC_PRIORITY_CTRL1                                                     0x18007084
#define DC_PRIORITY_CTRL1_reg_addr                                            "0xB8007084"
#define DC_PRIORITY_CTRL1_reg                                                 0xB8007084
#define set_DC_PRIORITY_CTRL1_reg(data)   (*((volatile unsigned int*) DC_PRIORITY_CTRL1_reg)=data)
#define get_DC_PRIORITY_CTRL1_reg   (*((volatile unsigned int*) DC_PRIORITY_CTRL1_reg))
#define DC_PRIORITY_CTRL1_inst_adr                                            "0x0021"
#define DC_PRIORITY_CTRL1_inst                                                0x0021
#define DC_PRIORITY_CTRL1_C1_LATCNT_END_shift                                 (16)
#define DC_PRIORITY_CTRL1_C1_LATCNT_END_mask                                  (0x00FF0000)
#define DC_PRIORITY_CTRL1_C1_LATCNT_END(data)                                 (0x00FF0000&((data)<<16))
#define DC_PRIORITY_CTRL1_C1_LATCNT_END_src(data)                             ((0x00FF0000&(data))>>16)
#define DC_PRIORITY_CTRL1_get_C1_LATCNT_END(data)                             ((0x00FF0000&(data))>>16)
#define DC_PRIORITY_CTRL1_C1_LATCNT_BEG_shift                                 (0)
#define DC_PRIORITY_CTRL1_C1_LATCNT_BEG_mask                                  (0x000000FF)
#define DC_PRIORITY_CTRL1_C1_LATCNT_BEG(data)                                 (0x000000FF&((data)<<0))
#define DC_PRIORITY_CTRL1_C1_LATCNT_BEG_src(data)                             ((0x000000FF&(data))>>0)
#define DC_PRIORITY_CTRL1_get_C1_LATCNT_BEG(data)                             ((0x000000FF&(data))>>0)


#define DC_PRIORITY_CTRL2                                                     0x18007088
#define DC_PRIORITY_CTRL2_reg_addr                                            "0xB8007088"
#define DC_PRIORITY_CTRL2_reg                                                 0xB8007088
#define set_DC_PRIORITY_CTRL2_reg(data)   (*((volatile unsigned int*) DC_PRIORITY_CTRL2_reg)=data)
#define get_DC_PRIORITY_CTRL2_reg   (*((volatile unsigned int*) DC_PRIORITY_CTRL2_reg))
#define DC_PRIORITY_CTRL2_inst_adr                                            "0x0022"
#define DC_PRIORITY_CTRL2_inst                                                0x0022
#define DC_PRIORITY_CTRL2_C2_LATCNT_END_shift                                 (16)
#define DC_PRIORITY_CTRL2_C2_LATCNT_END_mask                                  (0x00FF0000)
#define DC_PRIORITY_CTRL2_C2_LATCNT_END(data)                                 (0x00FF0000&((data)<<16))
#define DC_PRIORITY_CTRL2_C2_LATCNT_END_src(data)                             ((0x00FF0000&(data))>>16)
#define DC_PRIORITY_CTRL2_get_C2_LATCNT_END(data)                             ((0x00FF0000&(data))>>16)
#define DC_PRIORITY_CTRL2_C2_LATCNT_BEG_shift                                 (0)
#define DC_PRIORITY_CTRL2_C2_LATCNT_BEG_mask                                  (0x000000FF)
#define DC_PRIORITY_CTRL2_C2_LATCNT_BEG(data)                                 (0x000000FF&((data)<<0))
#define DC_PRIORITY_CTRL2_C2_LATCNT_BEG_src(data)                             ((0x000000FF&(data))>>0)
#define DC_PRIORITY_CTRL2_get_C2_LATCNT_BEG(data)                             ((0x000000FF&(data))>>0)


#define DC_PRIORITY_CTRL3                                                     0x1800708C
#define DC_PRIORITY_CTRL3_reg_addr                                            "0xB800708C"
#define DC_PRIORITY_CTRL3_reg                                                 0xB800708C
#define set_DC_PRIORITY_CTRL3_reg(data)   (*((volatile unsigned int*) DC_PRIORITY_CTRL3_reg)=data)
#define get_DC_PRIORITY_CTRL3_reg   (*((volatile unsigned int*) DC_PRIORITY_CTRL3_reg))
#define DC_PRIORITY_CTRL3_inst_adr                                            "0x0023"
#define DC_PRIORITY_CTRL3_inst                                                0x0023
#define DC_PRIORITY_CTRL3_C3_LATCNT_END_shift                                 (16)
#define DC_PRIORITY_CTRL3_C3_LATCNT_END_mask                                  (0x00FF0000)
#define DC_PRIORITY_CTRL3_C3_LATCNT_END(data)                                 (0x00FF0000&((data)<<16))
#define DC_PRIORITY_CTRL3_C3_LATCNT_END_src(data)                             ((0x00FF0000&(data))>>16)
#define DC_PRIORITY_CTRL3_get_C3_LATCNT_END(data)                             ((0x00FF0000&(data))>>16)
#define DC_PRIORITY_CTRL3_C3_LATCNT_BEG_shift                                 (0)
#define DC_PRIORITY_CTRL3_C3_LATCNT_BEG_mask                                  (0x000000FF)
#define DC_PRIORITY_CTRL3_C3_LATCNT_BEG(data)                                 (0x000000FF&((data)<<0))
#define DC_PRIORITY_CTRL3_C3_LATCNT_BEG_src(data)                             ((0x000000FF&(data))>>0)
#define DC_PRIORITY_CTRL3_get_C3_LATCNT_BEG(data)                             ((0x000000FF&(data))>>0)


#define DC_PRIORITY_CTRL4                                                     0x18007090
#define DC_PRIORITY_CTRL4_reg_addr                                            "0xB8007090"
#define DC_PRIORITY_CTRL4_reg                                                 0xB8007090
#define set_DC_PRIORITY_CTRL4_reg(data)   (*((volatile unsigned int*) DC_PRIORITY_CTRL4_reg)=data)
#define get_DC_PRIORITY_CTRL4_reg   (*((volatile unsigned int*) DC_PRIORITY_CTRL4_reg))
#define DC_PRIORITY_CTRL4_inst_adr                                            "0x0024"
#define DC_PRIORITY_CTRL4_inst                                                0x0024
#define DC_PRIORITY_CTRL4_C4_LATCNT_END_shift                                 (16)
#define DC_PRIORITY_CTRL4_C4_LATCNT_END_mask                                  (0x00FF0000)
#define DC_PRIORITY_CTRL4_C4_LATCNT_END(data)                                 (0x00FF0000&((data)<<16))
#define DC_PRIORITY_CTRL4_C4_LATCNT_END_src(data)                             ((0x00FF0000&(data))>>16)
#define DC_PRIORITY_CTRL4_get_C4_LATCNT_END(data)                             ((0x00FF0000&(data))>>16)
#define DC_PRIORITY_CTRL4_C4_LATCNT_BEG_shift                                 (0)
#define DC_PRIORITY_CTRL4_C4_LATCNT_BEG_mask                                  (0x000000FF)
#define DC_PRIORITY_CTRL4_C4_LATCNT_BEG(data)                                 (0x000000FF&((data)<<0))
#define DC_PRIORITY_CTRL4_C4_LATCNT_BEG_src(data)                             ((0x000000FF&(data))>>0)
#define DC_PRIORITY_CTRL4_get_C4_LATCNT_BEG(data)                             ((0x000000FF&(data))>>0)


#define DC_PRIORITY_CTRL5                                                     0x18007094
#define DC_PRIORITY_CTRL5_reg_addr                                            "0xB8007094"
#define DC_PRIORITY_CTRL5_reg                                                 0xB8007094
#define set_DC_PRIORITY_CTRL5_reg(data)   (*((volatile unsigned int*) DC_PRIORITY_CTRL5_reg)=data)
#define get_DC_PRIORITY_CTRL5_reg   (*((volatile unsigned int*) DC_PRIORITY_CTRL5_reg))
#define DC_PRIORITY_CTRL5_inst_adr                                            "0x0025"
#define DC_PRIORITY_CTRL5_inst                                                0x0025
#define DC_PRIORITY_CTRL5_C5_LATCNT_END_shift                                 (16)
#define DC_PRIORITY_CTRL5_C5_LATCNT_END_mask                                  (0x00FF0000)
#define DC_PRIORITY_CTRL5_C5_LATCNT_END(data)                                 (0x00FF0000&((data)<<16))
#define DC_PRIORITY_CTRL5_C5_LATCNT_END_src(data)                             ((0x00FF0000&(data))>>16)
#define DC_PRIORITY_CTRL5_get_C5_LATCNT_END(data)                             ((0x00FF0000&(data))>>16)
#define DC_PRIORITY_CTRL5_C5_LATCNT_BEG_shift                                 (0)
#define DC_PRIORITY_CTRL5_C5_LATCNT_BEG_mask                                  (0x000000FF)
#define DC_PRIORITY_CTRL5_C5_LATCNT_BEG(data)                                 (0x000000FF&((data)<<0))
#define DC_PRIORITY_CTRL5_C5_LATCNT_BEG_src(data)                             ((0x000000FF&(data))>>0)
#define DC_PRIORITY_CTRL5_get_C5_LATCNT_BEG(data)                             ((0x000000FF&(data))>>0)


#define DC_PRIORITY_CTRL6                                                     0x18007098
#define DC_PRIORITY_CTRL6_reg_addr                                            "0xB8007098"
#define DC_PRIORITY_CTRL6_reg                                                 0xB8007098
#define set_DC_PRIORITY_CTRL6_reg(data)   (*((volatile unsigned int*) DC_PRIORITY_CTRL6_reg)=data)
#define get_DC_PRIORITY_CTRL6_reg   (*((volatile unsigned int*) DC_PRIORITY_CTRL6_reg))
#define DC_PRIORITY_CTRL6_inst_adr                                            "0x0026"
#define DC_PRIORITY_CTRL6_inst                                                0x0026
#define DC_PRIORITY_CTRL6_C6_LATCNT_END_shift                                 (16)
#define DC_PRIORITY_CTRL6_C6_LATCNT_END_mask                                  (0x00FF0000)
#define DC_PRIORITY_CTRL6_C6_LATCNT_END(data)                                 (0x00FF0000&((data)<<16))
#define DC_PRIORITY_CTRL6_C6_LATCNT_END_src(data)                             ((0x00FF0000&(data))>>16)
#define DC_PRIORITY_CTRL6_get_C6_LATCNT_END(data)                             ((0x00FF0000&(data))>>16)
#define DC_PRIORITY_CTRL6_C6_LATCNT_BEG_shift                                 (0)
#define DC_PRIORITY_CTRL6_C6_LATCNT_BEG_mask                                  (0x000000FF)
#define DC_PRIORITY_CTRL6_C6_LATCNT_BEG(data)                                 (0x000000FF&((data)<<0))
#define DC_PRIORITY_CTRL6_C6_LATCNT_BEG_src(data)                             ((0x000000FF&(data))>>0)
#define DC_PRIORITY_CTRL6_get_C6_LATCNT_BEG(data)                             ((0x000000FF&(data))>>0)


#define DC_PRIORITY_CTRL7                                                     0x1800709C
#define DC_PRIORITY_CTRL7_reg_addr                                            "0xB800709C"
#define DC_PRIORITY_CTRL7_reg                                                 0xB800709C
#define set_DC_PRIORITY_CTRL7_reg(data)   (*((volatile unsigned int*) DC_PRIORITY_CTRL7_reg)=data)
#define get_DC_PRIORITY_CTRL7_reg   (*((volatile unsigned int*) DC_PRIORITY_CTRL7_reg))
#define DC_PRIORITY_CTRL7_inst_adr                                            "0x0027"
#define DC_PRIORITY_CTRL7_inst                                                0x0027
#define DC_PRIORITY_CTRL7_C7_LATCNT_END_shift                                 (16)
#define DC_PRIORITY_CTRL7_C7_LATCNT_END_mask                                  (0x00FF0000)
#define DC_PRIORITY_CTRL7_C7_LATCNT_END(data)                                 (0x00FF0000&((data)<<16))
#define DC_PRIORITY_CTRL7_C7_LATCNT_END_src(data)                             ((0x00FF0000&(data))>>16)
#define DC_PRIORITY_CTRL7_get_C7_LATCNT_END(data)                             ((0x00FF0000&(data))>>16)
#define DC_PRIORITY_CTRL7_C7_LATCNT_BEG_shift                                 (0)
#define DC_PRIORITY_CTRL7_C7_LATCNT_BEG_mask                                  (0x000000FF)
#define DC_PRIORITY_CTRL7_C7_LATCNT_BEG(data)                                 (0x000000FF&((data)<<0))
#define DC_PRIORITY_CTRL7_C7_LATCNT_BEG_src(data)                             ((0x000000FF&(data))>>0)
#define DC_PRIORITY_CTRL7_get_C7_LATCNT_BEG(data)                             ((0x000000FF&(data))>>0)


#define DC_PRIORITY_CTRL8                                                     0x180070A0
#define DC_PRIORITY_CTRL8_reg_addr                                            "0xB80070A0"
#define DC_PRIORITY_CTRL8_reg                                                 0xB80070A0
#define set_DC_PRIORITY_CTRL8_reg(data)   (*((volatile unsigned int*) DC_PRIORITY_CTRL8_reg)=data)
#define get_DC_PRIORITY_CTRL8_reg   (*((volatile unsigned int*) DC_PRIORITY_CTRL8_reg))
#define DC_PRIORITY_CTRL8_inst_adr                                            "0x0028"
#define DC_PRIORITY_CTRL8_inst                                                0x0028
#define DC_PRIORITY_CTRL8_C8_LATCNT_END_shift                                 (16)
#define DC_PRIORITY_CTRL8_C8_LATCNT_END_mask                                  (0x00FF0000)
#define DC_PRIORITY_CTRL8_C8_LATCNT_END(data)                                 (0x00FF0000&((data)<<16))
#define DC_PRIORITY_CTRL8_C8_LATCNT_END_src(data)                             ((0x00FF0000&(data))>>16)
#define DC_PRIORITY_CTRL8_get_C8_LATCNT_END(data)                             ((0x00FF0000&(data))>>16)
#define DC_PRIORITY_CTRL8_C8_LATCNT_BEG_shift                                 (0)
#define DC_PRIORITY_CTRL8_C8_LATCNT_BEG_mask                                  (0x000000FF)
#define DC_PRIORITY_CTRL8_C8_LATCNT_BEG(data)                                 (0x000000FF&((data)<<0))
#define DC_PRIORITY_CTRL8_C8_LATCNT_BEG_src(data)                             ((0x000000FF&(data))>>0)
#define DC_PRIORITY_CTRL8_get_C8_LATCNT_BEG(data)                             ((0x000000FF&(data))>>0)


#define DC_PRIORITY_CTRL9                                                     0x180070A4
#define DC_PRIORITY_CTRL9_reg_addr                                            "0xB80070A4"
#define DC_PRIORITY_CTRL9_reg                                                 0xB80070A4
#define set_DC_PRIORITY_CTRL9_reg(data)   (*((volatile unsigned int*) DC_PRIORITY_CTRL9_reg)=data)
#define get_DC_PRIORITY_CTRL9_reg   (*((volatile unsigned int*) DC_PRIORITY_CTRL9_reg))
#define DC_PRIORITY_CTRL9_inst_adr                                            "0x0029"
#define DC_PRIORITY_CTRL9_inst                                                0x0029
#define DC_PRIORITY_CTRL9_C9_LATCNT_END_shift                                 (16)
#define DC_PRIORITY_CTRL9_C9_LATCNT_END_mask                                  (0x00FF0000)
#define DC_PRIORITY_CTRL9_C9_LATCNT_END(data)                                 (0x00FF0000&((data)<<16))
#define DC_PRIORITY_CTRL9_C9_LATCNT_END_src(data)                             ((0x00FF0000&(data))>>16)
#define DC_PRIORITY_CTRL9_get_C9_LATCNT_END(data)                             ((0x00FF0000&(data))>>16)
#define DC_PRIORITY_CTRL9_C9_LATCNT_BEG_shift                                 (0)
#define DC_PRIORITY_CTRL9_C9_LATCNT_BEG_mask                                  (0x000000FF)
#define DC_PRIORITY_CTRL9_C9_LATCNT_BEG(data)                                 (0x000000FF&((data)<<0))
#define DC_PRIORITY_CTRL9_C9_LATCNT_BEG_src(data)                             ((0x000000FF&(data))>>0)
#define DC_PRIORITY_CTRL9_get_C9_LATCNT_BEG(data)                             ((0x000000FF&(data))>>0)


#define DC_PRIORITY_CTRLA                                                     0x180070A8
#define DC_PRIORITY_CTRLA_reg_addr                                            "0xB80070A8"
#define DC_PRIORITY_CTRLA_reg                                                 0xB80070A8
#define set_DC_PRIORITY_CTRLA_reg(data)   (*((volatile unsigned int*) DC_PRIORITY_CTRLA_reg)=data)
#define get_DC_PRIORITY_CTRLA_reg   (*((volatile unsigned int*) DC_PRIORITY_CTRLA_reg))
#define DC_PRIORITY_CTRLA_inst_adr                                            "0x002A"
#define DC_PRIORITY_CTRLA_inst                                                0x002A
#define DC_PRIORITY_CTRLA_CA_LATCNT_END_shift                                 (16)
#define DC_PRIORITY_CTRLA_CA_LATCNT_END_mask                                  (0x00FF0000)
#define DC_PRIORITY_CTRLA_CA_LATCNT_END(data)                                 (0x00FF0000&((data)<<16))
#define DC_PRIORITY_CTRLA_CA_LATCNT_END_src(data)                             ((0x00FF0000&(data))>>16)
#define DC_PRIORITY_CTRLA_get_CA_LATCNT_END(data)                             ((0x00FF0000&(data))>>16)
#define DC_PRIORITY_CTRLA_CA_LATCNT_BEG_shift                                 (0)
#define DC_PRIORITY_CTRLA_CA_LATCNT_BEG_mask                                  (0x000000FF)
#define DC_PRIORITY_CTRLA_CA_LATCNT_BEG(data)                                 (0x000000FF&((data)<<0))
#define DC_PRIORITY_CTRLA_CA_LATCNT_BEG_src(data)                             ((0x000000FF&(data))>>0)
#define DC_PRIORITY_CTRLA_get_CA_LATCNT_BEG(data)                             ((0x000000FF&(data))>>0)


#define DC_PRIORITY_CTRLB                                                     0x180070AC
#define DC_PRIORITY_CTRLB_reg_addr                                            "0xB80070AC"
#define DC_PRIORITY_CTRLB_reg                                                 0xB80070AC
#define set_DC_PRIORITY_CTRLB_reg(data)   (*((volatile unsigned int*) DC_PRIORITY_CTRLB_reg)=data)
#define get_DC_PRIORITY_CTRLB_reg   (*((volatile unsigned int*) DC_PRIORITY_CTRLB_reg))
#define DC_PRIORITY_CTRLB_inst_adr                                            "0x002B"
#define DC_PRIORITY_CTRLB_inst                                                0x002B
#define DC_PRIORITY_CTRLB_CB_LATCNT_END_shift                                 (16)
#define DC_PRIORITY_CTRLB_CB_LATCNT_END_mask                                  (0x00FF0000)
#define DC_PRIORITY_CTRLB_CB_LATCNT_END(data)                                 (0x00FF0000&((data)<<16))
#define DC_PRIORITY_CTRLB_CB_LATCNT_END_src(data)                             ((0x00FF0000&(data))>>16)
#define DC_PRIORITY_CTRLB_get_CB_LATCNT_END(data)                             ((0x00FF0000&(data))>>16)
#define DC_PRIORITY_CTRLB_CB_LATCNT_BEG_shift                                 (0)
#define DC_PRIORITY_CTRLB_CB_LATCNT_BEG_mask                                  (0x000000FF)
#define DC_PRIORITY_CTRLB_CB_LATCNT_BEG(data)                                 (0x000000FF&((data)<<0))
#define DC_PRIORITY_CTRLB_CB_LATCNT_BEG_src(data)                             ((0x000000FF&(data))>>0)
#define DC_PRIORITY_CTRLB_get_CB_LATCNT_BEG(data)                             ((0x000000FF&(data))>>0)


#define DC_PRIORITY_CTRL_HIE                                                  0x180070B0
#define DC_PRIORITY_CTRL_HIE_reg_addr                                         "0xB80070B0"
#define DC_PRIORITY_CTRL_HIE_reg                                              0xB80070B0
#define set_DC_PRIORITY_CTRL_HIE_reg(data)   (*((volatile unsigned int*) DC_PRIORITY_CTRL_HIE_reg)=data)
#define get_DC_PRIORITY_CTRL_HIE_reg   (*((volatile unsigned int*) DC_PRIORITY_CTRL_HIE_reg))
#define DC_PRIORITY_CTRL_HIE_inst_adr                                         "0x002C"
#define DC_PRIORITY_CTRL_HIE_inst                                             0x002C
#define DC_PRIORITY_CTRL_HIE_GPU_LAT_NEW_shift                                (28)
#define DC_PRIORITY_CTRL_HIE_GPU_LAT_NEW_mask                                 (0x10000000)
#define DC_PRIORITY_CTRL_HIE_GPU_LAT_NEW(data)                                (0x10000000&((data)<<28))
#define DC_PRIORITY_CTRL_HIE_GPU_LAT_NEW_src(data)                            ((0x10000000&(data))>>28)
#define DC_PRIORITY_CTRL_HIE_get_GPU_LAT_NEW(data)                            ((0x10000000&(data))>>28)
#define DC_PRIORITY_CTRL_HIE_HIE_CMP_DIS_shift                                (16)
#define DC_PRIORITY_CTRL_HIE_HIE_CMP_DIS_mask                                 (0x0FFF0000)
#define DC_PRIORITY_CTRL_HIE_HIE_CMP_DIS(data)                                (0x0FFF0000&((data)<<16))
#define DC_PRIORITY_CTRL_HIE_HIE_CMP_DIS_src(data)                            ((0x0FFF0000&(data))>>16)
#define DC_PRIORITY_CTRL_HIE_get_HIE_CMP_DIS(data)                            ((0x0FFF0000&(data))>>16)
#define DC_PRIORITY_CTRL_HIE_LATCNT_PERIOD_shift                              (0)
#define DC_PRIORITY_CTRL_HIE_LATCNT_PERIOD_mask                               (0x000000FF)
#define DC_PRIORITY_CTRL_HIE_LATCNT_PERIOD(data)                              (0x000000FF&((data)<<0))
#define DC_PRIORITY_CTRL_HIE_LATCNT_PERIOD_src(data)                          ((0x000000FF&(data))>>0)
#define DC_PRIORITY_CTRL_HIE_get_LATCNT_PERIOD(data)                          ((0x000000FF&(data))>>0)


#define DC_PRIORITY_CTRL_SCPU                                                 0x180070C0
#define DC_PRIORITY_CTRL_SCPU_reg_addr                                        "0xB80070C0"
#define DC_PRIORITY_CTRL_SCPU_reg                                             0xB80070C0
#define set_DC_PRIORITY_CTRL_SCPU_reg(data)   (*((volatile unsigned int*) DC_PRIORITY_CTRL_SCPU_reg)=data)
#define get_DC_PRIORITY_CTRL_SCPU_reg   (*((volatile unsigned int*) DC_PRIORITY_CTRL_SCPU_reg))
#define DC_PRIORITY_CTRL_SCPU_inst_adr                                        "0x0030"
#define DC_PRIORITY_CTRL_SCPU_inst                                            0x0030
#define DC_PRIORITY_CTRL_SCPU_SCPU_LATCNT_shift                               (0)
#define DC_PRIORITY_CTRL_SCPU_SCPU_LATCNT_mask                                (0x000000FF)
#define DC_PRIORITY_CTRL_SCPU_SCPU_LATCNT(data)                               (0x000000FF&((data)<<0))
#define DC_PRIORITY_CTRL_SCPU_SCPU_LATCNT_src(data)                           ((0x000000FF&(data))>>0)
#define DC_PRIORITY_CTRL_SCPU_get_SCPU_LATCNT(data)                           ((0x000000FF&(data))>>0)


#define DC_CLIENT_MASK                                                        0x180070D0
#define DC_CLIENT_MASK_reg_addr                                               "0xB80070D0"
#define DC_CLIENT_MASK_reg                                                    0xB80070D0
#define set_DC_CLIENT_MASK_reg(data)   (*((volatile unsigned int*) DC_CLIENT_MASK_reg)=data)
#define get_DC_CLIENT_MASK_reg   (*((volatile unsigned int*) DC_CLIENT_MASK_reg))
#define DC_CLIENT_MASK_inst_adr                                               "0x0034"
#define DC_CLIENT_MASK_inst                                                   0x0034
#define DC_CLIENT_MASK_req_mask_index_shift                                   (0)
#define DC_CLIENT_MASK_req_mask_index_mask                                    (0x00000FFF)
#define DC_CLIENT_MASK_req_mask_index(data)                                   (0x00000FFF&((data)<<0))
#define DC_CLIENT_MASK_req_mask_index_src(data)                               ((0x00000FFF&(data))>>0)
#define DC_CLIENT_MASK_get_req_mask_index(data)                               ((0x00000FFF&(data))>>0)


#define DC_PC_CTRL                                                            0x18007100
#define DC_PC_CTRL_reg_addr                                                   "0xB8007100"
#define DC_PC_CTRL_reg                                                        0xB8007100
#define set_DC_PC_CTRL_reg(data)   (*((volatile unsigned int*) DC_PC_CTRL_reg)=data)
#define get_DC_PC_CTRL_reg   (*((volatile unsigned int*) DC_PC_CTRL_reg))
#define DC_PC_CTRL_inst_adr                                                   "0x0040"
#define DC_PC_CTRL_inst                                                       0x0040
#define DC_PC_CTRL_pc_go_shift                                                (0)
#define DC_PC_CTRL_pc_go_mask                                                 (0x00000001)
#define DC_PC_CTRL_pc_go(data)                                                (0x00000001&((data)<<0))
#define DC_PC_CTRL_pc_go_src(data)                                            ((0x00000001&(data))>>0)
#define DC_PC_CTRL_get_pc_go(data)                                            ((0x00000001&(data))>>0)


#define DC_PC_TOTA_MON_NUM                                                    0x18007104
#define DC_PC_TOTA_MON_NUM_reg_addr                                           "0xB8007104"
#define DC_PC_TOTA_MON_NUM_reg                                                0xB8007104
#define set_DC_PC_TOTA_MON_NUM_reg(data)   (*((volatile unsigned int*) DC_PC_TOTA_MON_NUM_reg)=data)
#define get_DC_PC_TOTA_MON_NUM_reg   (*((volatile unsigned int*) DC_PC_TOTA_MON_NUM_reg))
#define DC_PC_TOTA_MON_NUM_inst_adr                                           "0x0041"
#define DC_PC_TOTA_MON_NUM_inst                                               0x0041
#define DC_PC_TOTA_MON_NUM_pc_tota_mon_num_shift                              (0)
#define DC_PC_TOTA_MON_NUM_pc_tota_mon_num_mask                               (0xFFFFFFFF)
#define DC_PC_TOTA_MON_NUM_pc_tota_mon_num(data)                              (0xFFFFFFFF&((data)<<0))
#define DC_PC_TOTA_MON_NUM_pc_tota_mon_num_src(data)                          ((0xFFFFFFFF&(data))>>0)
#define DC_PC_TOTA_MON_NUM_get_pc_tota_mon_num(data)                          ((0xFFFFFFFF&(data))>>0)


#define DC_PC_TOTA_ACK_NUM                                                    0x18007108
#define DC_PC_TOTA_ACK_NUM_reg_addr                                           "0xB8007108"
#define DC_PC_TOTA_ACK_NUM_reg                                                0xB8007108
#define set_DC_PC_TOTA_ACK_NUM_reg(data)   (*((volatile unsigned int*) DC_PC_TOTA_ACK_NUM_reg)=data)
#define get_DC_PC_TOTA_ACK_NUM_reg   (*((volatile unsigned int*) DC_PC_TOTA_ACK_NUM_reg))
#define DC_PC_TOTA_ACK_NUM_inst_adr                                           "0x0042"
#define DC_PC_TOTA_ACK_NUM_inst                                               0x0042
#define DC_PC_TOTA_ACK_NUM_pc_tota_ack_num_shift                              (0)
#define DC_PC_TOTA_ACK_NUM_pc_tota_ack_num_mask                               (0xFFFFFFFF)
#define DC_PC_TOTA_ACK_NUM_pc_tota_ack_num(data)                              (0xFFFFFFFF&((data)<<0))
#define DC_PC_TOTA_ACK_NUM_pc_tota_ack_num_src(data)                          ((0xFFFFFFFF&(data))>>0)
#define DC_PC_TOTA_ACK_NUM_get_pc_tota_ack_num(data)                          ((0xFFFFFFFF&(data))>>0)


#define DC_PC_TOTA_IDL_NUM                                                    0x1800710C
#define DC_PC_TOTA_IDL_NUM_reg_addr                                           "0xB800710C"
#define DC_PC_TOTA_IDL_NUM_reg                                                0xB800710C
#define set_DC_PC_TOTA_IDL_NUM_reg(data)   (*((volatile unsigned int*) DC_PC_TOTA_IDL_NUM_reg)=data)
#define get_DC_PC_TOTA_IDL_NUM_reg   (*((volatile unsigned int*) DC_PC_TOTA_IDL_NUM_reg))
#define DC_PC_TOTA_IDL_NUM_inst_adr                                           "0x0043"
#define DC_PC_TOTA_IDL_NUM_inst                                               0x0043
#define DC_PC_TOTA_IDL_NUM_pc_tota_idl_num_shift                              (0)
#define DC_PC_TOTA_IDL_NUM_pc_tota_idl_num_mask                               (0xFFFFFFFF)
#define DC_PC_TOTA_IDL_NUM_pc_tota_idl_num(data)                              (0xFFFFFFFF&((data)<<0))
#define DC_PC_TOTA_IDL_NUM_pc_tota_idl_num_src(data)                          ((0xFFFFFFFF&(data))>>0)
#define DC_PC_TOTA_IDL_NUM_get_pc_tota_idl_num(data)                          ((0xFFFFFFFF&(data))>>0)


#define DC_PC_SYSH_PROG_CTRL                                                  0x18007110
#define DC_PC_SYSH_PROG_CTRL_reg_addr                                         "0xB8007110"
#define DC_PC_SYSH_PROG_CTRL_reg                                              0xB8007110
#define set_DC_PC_SYSH_PROG_CTRL_reg(data)   (*((volatile unsigned int*) DC_PC_SYSH_PROG_CTRL_reg)=data)
#define get_DC_PC_SYSH_PROG_CTRL_reg   (*((volatile unsigned int*) DC_PC_SYSH_PROG_CTRL_reg))
#define DC_PC_SYSH_PROG_CTRL_inst_adr                                         "0x0044"
#define DC_PC_SYSH_PROG_CTRL_inst                                             0x0044
#define DC_PC_SYSH_PROG_CTRL_write_en_3_shift                                 (23)
#define DC_PC_SYSH_PROG_CTRL_write_en_3_mask                                  (0x00800000)
#define DC_PC_SYSH_PROG_CTRL_write_en_3(data)                                 (0x00800000&((data)<<23))
#define DC_PC_SYSH_PROG_CTRL_write_en_3_src(data)                             ((0x00800000&(data))>>23)
#define DC_PC_SYSH_PROG_CTRL_get_write_en_3(data)                             ((0x00800000&(data))>>23)
#define DC_PC_SYSH_PROG_CTRL_pc_sysh_prog2_sel_shift                          (16)
#define DC_PC_SYSH_PROG_CTRL_pc_sysh_prog2_sel_mask                           (0x007F0000)
#define DC_PC_SYSH_PROG_CTRL_pc_sysh_prog2_sel(data)                          (0x007F0000&((data)<<16))
#define DC_PC_SYSH_PROG_CTRL_pc_sysh_prog2_sel_src(data)                      ((0x007F0000&(data))>>16)
#define DC_PC_SYSH_PROG_CTRL_get_pc_sysh_prog2_sel(data)                      ((0x007F0000&(data))>>16)
#define DC_PC_SYSH_PROG_CTRL_write_en_2_shift                                 (15)
#define DC_PC_SYSH_PROG_CTRL_write_en_2_mask                                  (0x00008000)
#define DC_PC_SYSH_PROG_CTRL_write_en_2(data)                                 (0x00008000&((data)<<15))
#define DC_PC_SYSH_PROG_CTRL_write_en_2_src(data)                             ((0x00008000&(data))>>15)
#define DC_PC_SYSH_PROG_CTRL_get_write_en_2(data)                             ((0x00008000&(data))>>15)
#define DC_PC_SYSH_PROG_CTRL_pc_sysh_prog1_sel_shift                          (8)
#define DC_PC_SYSH_PROG_CTRL_pc_sysh_prog1_sel_mask                           (0x00007F00)
#define DC_PC_SYSH_PROG_CTRL_pc_sysh_prog1_sel(data)                          (0x00007F00&((data)<<8))
#define DC_PC_SYSH_PROG_CTRL_pc_sysh_prog1_sel_src(data)                      ((0x00007F00&(data))>>8)
#define DC_PC_SYSH_PROG_CTRL_get_pc_sysh_prog1_sel(data)                      ((0x00007F00&(data))>>8)
#define DC_PC_SYSH_PROG_CTRL_write_en_1_shift                                 (7)
#define DC_PC_SYSH_PROG_CTRL_write_en_1_mask                                  (0x00000080)
#define DC_PC_SYSH_PROG_CTRL_write_en_1(data)                                 (0x00000080&((data)<<7))
#define DC_PC_SYSH_PROG_CTRL_write_en_1_src(data)                             ((0x00000080&(data))>>7)
#define DC_PC_SYSH_PROG_CTRL_get_write_en_1(data)                             ((0x00000080&(data))>>7)
#define DC_PC_SYSH_PROG_CTRL_pc_sysh_prog0_sel_shift                          (0)
#define DC_PC_SYSH_PROG_CTRL_pc_sysh_prog0_sel_mask                           (0x0000007F)
#define DC_PC_SYSH_PROG_CTRL_pc_sysh_prog0_sel(data)                          (0x0000007F&((data)<<0))
#define DC_PC_SYSH_PROG_CTRL_pc_sysh_prog0_sel_src(data)                      ((0x0000007F&(data))>>0)
#define DC_PC_SYSH_PROG_CTRL_get_pc_sysh_prog0_sel(data)                      ((0x0000007F&(data))>>0)


#define DC_PC_SYS_PROG_CTRL1                                                  0x18007120
#define DC_PC_SYS_PROG_CTRL1_reg_addr                                         "0xB8007120"
#define DC_PC_SYS_PROG_CTRL1_reg                                              0xB8007120
#define set_DC_PC_SYS_PROG_CTRL1_reg(data)   (*((volatile unsigned int*) DC_PC_SYS_PROG_CTRL1_reg)=data)
#define get_DC_PC_SYS_PROG_CTRL1_reg   (*((volatile unsigned int*) DC_PC_SYS_PROG_CTRL1_reg))
#define DC_PC_SYS_PROG_CTRL1_inst_adr                                         "0x0048"
#define DC_PC_SYS_PROG_CTRL1_inst                                             0x0048
#define DC_PC_SYS_PROG_CTRL1_pc_sysh_prog2_req_occur_shift                    (6)
#define DC_PC_SYS_PROG_CTRL1_pc_sysh_prog2_req_occur_mask                     (0x00000040)
#define DC_PC_SYS_PROG_CTRL1_pc_sysh_prog2_req_occur(data)                    (0x00000040&((data)<<6))
#define DC_PC_SYS_PROG_CTRL1_pc_sysh_prog2_req_occur_src(data)                ((0x00000040&(data))>>6)
#define DC_PC_SYS_PROG_CTRL1_get_pc_sysh_prog2_req_occur(data)                ((0x00000040&(data))>>6)
#define DC_PC_SYS_PROG_CTRL1_pc_sysh_prog1_req_occur_shift                    (5)
#define DC_PC_SYS_PROG_CTRL1_pc_sysh_prog1_req_occur_mask                     (0x00000020)
#define DC_PC_SYS_PROG_CTRL1_pc_sysh_prog1_req_occur(data)                    (0x00000020&((data)<<5))
#define DC_PC_SYS_PROG_CTRL1_pc_sysh_prog1_req_occur_src(data)                ((0x00000020&(data))>>5)
#define DC_PC_SYS_PROG_CTRL1_get_pc_sysh_prog1_req_occur(data)                ((0x00000020&(data))>>5)
#define DC_PC_SYS_PROG_CTRL1_pc_sysh_prog0_req_occur_shift                    (4)
#define DC_PC_SYS_PROG_CTRL1_pc_sysh_prog0_req_occur_mask                     (0x00000010)
#define DC_PC_SYS_PROG_CTRL1_pc_sysh_prog0_req_occur(data)                    (0x00000010&((data)<<4))
#define DC_PC_SYS_PROG_CTRL1_pc_sysh_prog0_req_occur_src(data)                ((0x00000010&(data))>>4)
#define DC_PC_SYS_PROG_CTRL1_get_pc_sysh_prog0_req_occur(data)                ((0x00000010&(data))>>4)


#define DC_PC_SYSH_PROG_0_ACC_LAT                                             0x18007130
#define DC_PC_SYSH_PROG_0_ACC_LAT_reg_addr                                    "0xB8007130"
#define DC_PC_SYSH_PROG_0_ACC_LAT_reg                                         0xB8007130
#define set_DC_PC_SYSH_PROG_0_ACC_LAT_reg(data)   (*((volatile unsigned int*) DC_PC_SYSH_PROG_0_ACC_LAT_reg)=data)
#define get_DC_PC_SYSH_PROG_0_ACC_LAT_reg   (*((volatile unsigned int*) DC_PC_SYSH_PROG_0_ACC_LAT_reg))
#define DC_PC_SYSH_PROG_0_ACC_LAT_inst_adr                                    "0x004C"
#define DC_PC_SYSH_PROG_0_ACC_LAT_inst                                        0x004C
#define DC_PC_SYSH_PROG_0_ACC_LAT_sysh_prog0_acc_lat_shift                    (0)
#define DC_PC_SYSH_PROG_0_ACC_LAT_sysh_prog0_acc_lat_mask                     (0xFFFFFFFF)
#define DC_PC_SYSH_PROG_0_ACC_LAT_sysh_prog0_acc_lat(data)                    (0xFFFFFFFF&((data)<<0))
#define DC_PC_SYSH_PROG_0_ACC_LAT_sysh_prog0_acc_lat_src(data)                ((0xFFFFFFFF&(data))>>0)
#define DC_PC_SYSH_PROG_0_ACC_LAT_get_sysh_prog0_acc_lat(data)                ((0xFFFFFFFF&(data))>>0)


#define DC_PC_SYSH_PROG_0_MAX_LAT                                             0x18007134
#define DC_PC_SYSH_PROG_0_MAX_LAT_reg_addr                                    "0xB8007134"
#define DC_PC_SYSH_PROG_0_MAX_LAT_reg                                         0xB8007134
#define set_DC_PC_SYSH_PROG_0_MAX_LAT_reg(data)   (*((volatile unsigned int*) DC_PC_SYSH_PROG_0_MAX_LAT_reg)=data)
#define get_DC_PC_SYSH_PROG_0_MAX_LAT_reg   (*((volatile unsigned int*) DC_PC_SYSH_PROG_0_MAX_LAT_reg))
#define DC_PC_SYSH_PROG_0_MAX_LAT_inst_adr                                    "0x004D"
#define DC_PC_SYSH_PROG_0_MAX_LAT_inst                                        0x004D
#define DC_PC_SYSH_PROG_0_MAX_LAT_sysh_prog0_max_lat_shift                    (0)
#define DC_PC_SYSH_PROG_0_MAX_LAT_sysh_prog0_max_lat_mask                     (0x0000FFFF)
#define DC_PC_SYSH_PROG_0_MAX_LAT_sysh_prog0_max_lat(data)                    (0x0000FFFF&((data)<<0))
#define DC_PC_SYSH_PROG_0_MAX_LAT_sysh_prog0_max_lat_src(data)                ((0x0000FFFF&(data))>>0)
#define DC_PC_SYSH_PROG_0_MAX_LAT_get_sysh_prog0_max_lat(data)                ((0x0000FFFF&(data))>>0)


#define DC_PC_SYSH_PROG_0_REQ_NUM                                             0x18007138
#define DC_PC_SYSH_PROG_0_REQ_NUM_reg_addr                                    "0xB8007138"
#define DC_PC_SYSH_PROG_0_REQ_NUM_reg                                         0xB8007138
#define set_DC_PC_SYSH_PROG_0_REQ_NUM_reg(data)   (*((volatile unsigned int*) DC_PC_SYSH_PROG_0_REQ_NUM_reg)=data)
#define get_DC_PC_SYSH_PROG_0_REQ_NUM_reg   (*((volatile unsigned int*) DC_PC_SYSH_PROG_0_REQ_NUM_reg))
#define DC_PC_SYSH_PROG_0_REQ_NUM_inst_adr                                    "0x004E"
#define DC_PC_SYSH_PROG_0_REQ_NUM_inst                                        0x004E
#define DC_PC_SYSH_PROG_0_REQ_NUM_sysh_prog0_req_num_shift                    (0)
#define DC_PC_SYSH_PROG_0_REQ_NUM_sysh_prog0_req_num_mask                     (0x00FFFFFF)
#define DC_PC_SYSH_PROG_0_REQ_NUM_sysh_prog0_req_num(data)                    (0x00FFFFFF&((data)<<0))
#define DC_PC_SYSH_PROG_0_REQ_NUM_sysh_prog0_req_num_src(data)                ((0x00FFFFFF&(data))>>0)
#define DC_PC_SYSH_PROG_0_REQ_NUM_get_sysh_prog0_req_num(data)                ((0x00FFFFFF&(data))>>0)


#define DC_PC_SYSH_PROG_0_ACK_NUM                                             0x1800713C
#define DC_PC_SYSH_PROG_0_ACK_NUM_reg_addr                                    "0xB800713C"
#define DC_PC_SYSH_PROG_0_ACK_NUM_reg                                         0xB800713C
#define set_DC_PC_SYSH_PROG_0_ACK_NUM_reg(data)   (*((volatile unsigned int*) DC_PC_SYSH_PROG_0_ACK_NUM_reg)=data)
#define get_DC_PC_SYSH_PROG_0_ACK_NUM_reg   (*((volatile unsigned int*) DC_PC_SYSH_PROG_0_ACK_NUM_reg))
#define DC_PC_SYSH_PROG_0_ACK_NUM_inst_adr                                    "0x004F"
#define DC_PC_SYSH_PROG_0_ACK_NUM_inst                                        0x004F
#define DC_PC_SYSH_PROG_0_ACK_NUM_sysh_prog0_ack_num_shift                    (0)
#define DC_PC_SYSH_PROG_0_ACK_NUM_sysh_prog0_ack_num_mask                     (0xFFFFFFFF)
#define DC_PC_SYSH_PROG_0_ACK_NUM_sysh_prog0_ack_num(data)                    (0xFFFFFFFF&((data)<<0))
#define DC_PC_SYSH_PROG_0_ACK_NUM_sysh_prog0_ack_num_src(data)                ((0xFFFFFFFF&(data))>>0)
#define DC_PC_SYSH_PROG_0_ACK_NUM_get_sysh_prog0_ack_num(data)                ((0xFFFFFFFF&(data))>>0)


#define DC_PC_SYSH_PROG_1_ACC_LAT                                             0x18007140
#define DC_PC_SYSH_PROG_1_ACC_LAT_reg_addr                                    "0xB8007140"
#define DC_PC_SYSH_PROG_1_ACC_LAT_reg                                         0xB8007140
#define set_DC_PC_SYSH_PROG_1_ACC_LAT_reg(data)   (*((volatile unsigned int*) DC_PC_SYSH_PROG_1_ACC_LAT_reg)=data)
#define get_DC_PC_SYSH_PROG_1_ACC_LAT_reg   (*((volatile unsigned int*) DC_PC_SYSH_PROG_1_ACC_LAT_reg))
#define DC_PC_SYSH_PROG_1_ACC_LAT_inst_adr                                    "0x0050"
#define DC_PC_SYSH_PROG_1_ACC_LAT_inst                                        0x0050
#define DC_PC_SYSH_PROG_1_ACC_LAT_sysh_prog1_acc_lat_shift                    (0)
#define DC_PC_SYSH_PROG_1_ACC_LAT_sysh_prog1_acc_lat_mask                     (0xFFFFFFFF)
#define DC_PC_SYSH_PROG_1_ACC_LAT_sysh_prog1_acc_lat(data)                    (0xFFFFFFFF&((data)<<0))
#define DC_PC_SYSH_PROG_1_ACC_LAT_sysh_prog1_acc_lat_src(data)                ((0xFFFFFFFF&(data))>>0)
#define DC_PC_SYSH_PROG_1_ACC_LAT_get_sysh_prog1_acc_lat(data)                ((0xFFFFFFFF&(data))>>0)


#define DC_PC_SYSH_PROG_1_MAX_LAT                                             0x18007144
#define DC_PC_SYSH_PROG_1_MAX_LAT_reg_addr                                    "0xB8007144"
#define DC_PC_SYSH_PROG_1_MAX_LAT_reg                                         0xB8007144
#define set_DC_PC_SYSH_PROG_1_MAX_LAT_reg(data)   (*((volatile unsigned int*) DC_PC_SYSH_PROG_1_MAX_LAT_reg)=data)
#define get_DC_PC_SYSH_PROG_1_MAX_LAT_reg   (*((volatile unsigned int*) DC_PC_SYSH_PROG_1_MAX_LAT_reg))
#define DC_PC_SYSH_PROG_1_MAX_LAT_inst_adr                                    "0x0051"
#define DC_PC_SYSH_PROG_1_MAX_LAT_inst                                        0x0051
#define DC_PC_SYSH_PROG_1_MAX_LAT_sysh_prog1_max_lat_shift                    (0)
#define DC_PC_SYSH_PROG_1_MAX_LAT_sysh_prog1_max_lat_mask                     (0x0000FFFF)
#define DC_PC_SYSH_PROG_1_MAX_LAT_sysh_prog1_max_lat(data)                    (0x0000FFFF&((data)<<0))
#define DC_PC_SYSH_PROG_1_MAX_LAT_sysh_prog1_max_lat_src(data)                ((0x0000FFFF&(data))>>0)
#define DC_PC_SYSH_PROG_1_MAX_LAT_get_sysh_prog1_max_lat(data)                ((0x0000FFFF&(data))>>0)


#define DC_PC_SYSH_PROG_1_REQ_NUM                                             0x18007148
#define DC_PC_SYSH_PROG_1_REQ_NUM_reg_addr                                    "0xB8007148"
#define DC_PC_SYSH_PROG_1_REQ_NUM_reg                                         0xB8007148
#define set_DC_PC_SYSH_PROG_1_REQ_NUM_reg(data)   (*((volatile unsigned int*) DC_PC_SYSH_PROG_1_REQ_NUM_reg)=data)
#define get_DC_PC_SYSH_PROG_1_REQ_NUM_reg   (*((volatile unsigned int*) DC_PC_SYSH_PROG_1_REQ_NUM_reg))
#define DC_PC_SYSH_PROG_1_REQ_NUM_inst_adr                                    "0x0052"
#define DC_PC_SYSH_PROG_1_REQ_NUM_inst                                        0x0052
#define DC_PC_SYSH_PROG_1_REQ_NUM_sysh_prog1_req_num_shift                    (0)
#define DC_PC_SYSH_PROG_1_REQ_NUM_sysh_prog1_req_num_mask                     (0x00FFFFFF)
#define DC_PC_SYSH_PROG_1_REQ_NUM_sysh_prog1_req_num(data)                    (0x00FFFFFF&((data)<<0))
#define DC_PC_SYSH_PROG_1_REQ_NUM_sysh_prog1_req_num_src(data)                ((0x00FFFFFF&(data))>>0)
#define DC_PC_SYSH_PROG_1_REQ_NUM_get_sysh_prog1_req_num(data)                ((0x00FFFFFF&(data))>>0)


#define DC_PC_SYSH_PROG_1_ACK_NUM                                             0x1800714C
#define DC_PC_SYSH_PROG_1_ACK_NUM_reg_addr                                    "0xB800714C"
#define DC_PC_SYSH_PROG_1_ACK_NUM_reg                                         0xB800714C
#define set_DC_PC_SYSH_PROG_1_ACK_NUM_reg(data)   (*((volatile unsigned int*) DC_PC_SYSH_PROG_1_ACK_NUM_reg)=data)
#define get_DC_PC_SYSH_PROG_1_ACK_NUM_reg   (*((volatile unsigned int*) DC_PC_SYSH_PROG_1_ACK_NUM_reg))
#define DC_PC_SYSH_PROG_1_ACK_NUM_inst_adr                                    "0x0053"
#define DC_PC_SYSH_PROG_1_ACK_NUM_inst                                        0x0053
#define DC_PC_SYSH_PROG_1_ACK_NUM_sysh_prog1_ack_num_shift                    (0)
#define DC_PC_SYSH_PROG_1_ACK_NUM_sysh_prog1_ack_num_mask                     (0xFFFFFFFF)
#define DC_PC_SYSH_PROG_1_ACK_NUM_sysh_prog1_ack_num(data)                    (0xFFFFFFFF&((data)<<0))
#define DC_PC_SYSH_PROG_1_ACK_NUM_sysh_prog1_ack_num_src(data)                ((0xFFFFFFFF&(data))>>0)
#define DC_PC_SYSH_PROG_1_ACK_NUM_get_sysh_prog1_ack_num(data)                ((0xFFFFFFFF&(data))>>0)


#define DC_PC_SYSH_PROG_2_ACC_LAT                                             0x18007150
#define DC_PC_SYSH_PROG_2_ACC_LAT_reg_addr                                    "0xB8007150"
#define DC_PC_SYSH_PROG_2_ACC_LAT_reg                                         0xB8007150
#define set_DC_PC_SYSH_PROG_2_ACC_LAT_reg(data)   (*((volatile unsigned int*) DC_PC_SYSH_PROG_2_ACC_LAT_reg)=data)
#define get_DC_PC_SYSH_PROG_2_ACC_LAT_reg   (*((volatile unsigned int*) DC_PC_SYSH_PROG_2_ACC_LAT_reg))
#define DC_PC_SYSH_PROG_2_ACC_LAT_inst_adr                                    "0x0054"
#define DC_PC_SYSH_PROG_2_ACC_LAT_inst                                        0x0054
#define DC_PC_SYSH_PROG_2_ACC_LAT_sysh_prog2_acc_lat_shift                    (0)
#define DC_PC_SYSH_PROG_2_ACC_LAT_sysh_prog2_acc_lat_mask                     (0xFFFFFFFF)
#define DC_PC_SYSH_PROG_2_ACC_LAT_sysh_prog2_acc_lat(data)                    (0xFFFFFFFF&((data)<<0))
#define DC_PC_SYSH_PROG_2_ACC_LAT_sysh_prog2_acc_lat_src(data)                ((0xFFFFFFFF&(data))>>0)
#define DC_PC_SYSH_PROG_2_ACC_LAT_get_sysh_prog2_acc_lat(data)                ((0xFFFFFFFF&(data))>>0)


#define DC_PC_SYSH_PROG_2_MAX_LAT                                             0x18007154
#define DC_PC_SYSH_PROG_2_MAX_LAT_reg_addr                                    "0xB8007154"
#define DC_PC_SYSH_PROG_2_MAX_LAT_reg                                         0xB8007154
#define set_DC_PC_SYSH_PROG_2_MAX_LAT_reg(data)   (*((volatile unsigned int*) DC_PC_SYSH_PROG_2_MAX_LAT_reg)=data)
#define get_DC_PC_SYSH_PROG_2_MAX_LAT_reg   (*((volatile unsigned int*) DC_PC_SYSH_PROG_2_MAX_LAT_reg))
#define DC_PC_SYSH_PROG_2_MAX_LAT_inst_adr                                    "0x0055"
#define DC_PC_SYSH_PROG_2_MAX_LAT_inst                                        0x0055
#define DC_PC_SYSH_PROG_2_MAX_LAT_sysh_prog2_max_lat_shift                    (0)
#define DC_PC_SYSH_PROG_2_MAX_LAT_sysh_prog2_max_lat_mask                     (0x0000FFFF)
#define DC_PC_SYSH_PROG_2_MAX_LAT_sysh_prog2_max_lat(data)                    (0x0000FFFF&((data)<<0))
#define DC_PC_SYSH_PROG_2_MAX_LAT_sysh_prog2_max_lat_src(data)                ((0x0000FFFF&(data))>>0)
#define DC_PC_SYSH_PROG_2_MAX_LAT_get_sysh_prog2_max_lat(data)                ((0x0000FFFF&(data))>>0)


#define DC_PC_SYSH_PROG_2_REQ_NUM                                             0x18007158
#define DC_PC_SYSH_PROG_2_REQ_NUM_reg_addr                                    "0xB8007158"
#define DC_PC_SYSH_PROG_2_REQ_NUM_reg                                         0xB8007158
#define set_DC_PC_SYSH_PROG_2_REQ_NUM_reg(data)   (*((volatile unsigned int*) DC_PC_SYSH_PROG_2_REQ_NUM_reg)=data)
#define get_DC_PC_SYSH_PROG_2_REQ_NUM_reg   (*((volatile unsigned int*) DC_PC_SYSH_PROG_2_REQ_NUM_reg))
#define DC_PC_SYSH_PROG_2_REQ_NUM_inst_adr                                    "0x0056"
#define DC_PC_SYSH_PROG_2_REQ_NUM_inst                                        0x0056
#define DC_PC_SYSH_PROG_2_REQ_NUM_sysh_prog2_req_num_shift                    (0)
#define DC_PC_SYSH_PROG_2_REQ_NUM_sysh_prog2_req_num_mask                     (0x00FFFFFF)
#define DC_PC_SYSH_PROG_2_REQ_NUM_sysh_prog2_req_num(data)                    (0x00FFFFFF&((data)<<0))
#define DC_PC_SYSH_PROG_2_REQ_NUM_sysh_prog2_req_num_src(data)                ((0x00FFFFFF&(data))>>0)
#define DC_PC_SYSH_PROG_2_REQ_NUM_get_sysh_prog2_req_num(data)                ((0x00FFFFFF&(data))>>0)


#define DC_PC_SYSH_PROG_2_ACK_NUM                                             0x1800715C
#define DC_PC_SYSH_PROG_2_ACK_NUM_reg_addr                                    "0xB800715C"
#define DC_PC_SYSH_PROG_2_ACK_NUM_reg                                         0xB800715C
#define set_DC_PC_SYSH_PROG_2_ACK_NUM_reg(data)   (*((volatile unsigned int*) DC_PC_SYSH_PROG_2_ACK_NUM_reg)=data)
#define get_DC_PC_SYSH_PROG_2_ACK_NUM_reg   (*((volatile unsigned int*) DC_PC_SYSH_PROG_2_ACK_NUM_reg))
#define DC_PC_SYSH_PROG_2_ACK_NUM_inst_adr                                    "0x0057"
#define DC_PC_SYSH_PROG_2_ACK_NUM_inst                                        0x0057
#define DC_PC_SYSH_PROG_2_ACK_NUM_sysh_prog2_ack_num_shift                    (0)
#define DC_PC_SYSH_PROG_2_ACK_NUM_sysh_prog2_ack_num_mask                     (0xFFFFFFFF)
#define DC_PC_SYSH_PROG_2_ACK_NUM_sysh_prog2_ack_num(data)                    (0xFFFFFFFF&((data)<<0))
#define DC_PC_SYSH_PROG_2_ACK_NUM_sysh_prog2_ack_num_src(data)                ((0xFFFFFFFF&(data))>>0)
#define DC_PC_SYSH_PROG_2_ACK_NUM_get_sysh_prog2_ack_num(data)                ((0xFFFFFFFF&(data))>>0)


#define DC_PC_SYSH_PROG_0                                                     0x18007190
#define DC_PC_SYSH_PROG_0_reg_addr                                            "0xB8007190"
#define DC_PC_SYSH_PROG_0_reg                                                 0xB8007190
#define set_DC_PC_SYSH_PROG_0_reg(data)   (*((volatile unsigned int*) DC_PC_SYSH_PROG_0_reg)=data)
#define get_DC_PC_SYSH_PROG_0_reg   (*((volatile unsigned int*) DC_PC_SYSH_PROG_0_reg))
#define DC_PC_SYSH_PROG_0_inst_adr                                            "0x0064"
#define DC_PC_SYSH_PROG_0_inst                                                0x0064
#define DC_PC_SYSH_PROG_0_sysh0_hitend_cnt_shift                              (0)
#define DC_PC_SYSH_PROG_0_sysh0_hitend_cnt_mask                               (0x0000FFFF)
#define DC_PC_SYSH_PROG_0_sysh0_hitend_cnt(data)                              (0x0000FFFF&((data)<<0))
#define DC_PC_SYSH_PROG_0_sysh0_hitend_cnt_src(data)                          ((0x0000FFFF&(data))>>0)
#define DC_PC_SYSH_PROG_0_get_sysh0_hitend_cnt(data)                          ((0x0000FFFF&(data))>>0)


#define DC_PC_SYSH_PROG_1                                                     0x18007194
#define DC_PC_SYSH_PROG_1_reg_addr                                            "0xB8007194"
#define DC_PC_SYSH_PROG_1_reg                                                 0xB8007194
#define set_DC_PC_SYSH_PROG_1_reg(data)   (*((volatile unsigned int*) DC_PC_SYSH_PROG_1_reg)=data)
#define get_DC_PC_SYSH_PROG_1_reg   (*((volatile unsigned int*) DC_PC_SYSH_PROG_1_reg))
#define DC_PC_SYSH_PROG_1_inst_adr                                            "0x0065"
#define DC_PC_SYSH_PROG_1_inst                                                0x0065
#define DC_PC_SYSH_PROG_1_sysh1_hitend_cnt_shift                              (0)
#define DC_PC_SYSH_PROG_1_sysh1_hitend_cnt_mask                               (0x0000FFFF)
#define DC_PC_SYSH_PROG_1_sysh1_hitend_cnt(data)                              (0x0000FFFF&((data)<<0))
#define DC_PC_SYSH_PROG_1_sysh1_hitend_cnt_src(data)                          ((0x0000FFFF&(data))>>0)
#define DC_PC_SYSH_PROG_1_get_sysh1_hitend_cnt(data)                          ((0x0000FFFF&(data))>>0)


#define DC_PC_SYSH_PROG_2                                                     0x18007198
#define DC_PC_SYSH_PROG_2_reg_addr                                            "0xB8007198"
#define DC_PC_SYSH_PROG_2_reg                                                 0xB8007198
#define set_DC_PC_SYSH_PROG_2_reg(data)   (*((volatile unsigned int*) DC_PC_SYSH_PROG_2_reg)=data)
#define get_DC_PC_SYSH_PROG_2_reg   (*((volatile unsigned int*) DC_PC_SYSH_PROG_2_reg))
#define DC_PC_SYSH_PROG_2_inst_adr                                            "0x0066"
#define DC_PC_SYSH_PROG_2_inst                                                0x0066
#define DC_PC_SYSH_PROG_2_sysh2_hitend_cnt_shift                              (0)
#define DC_PC_SYSH_PROG_2_sysh2_hitend_cnt_mask                               (0x0000FFFF)
#define DC_PC_SYSH_PROG_2_sysh2_hitend_cnt(data)                              (0x0000FFFF&((data)<<0))
#define DC_PC_SYSH_PROG_2_sysh2_hitend_cnt_src(data)                          ((0x0000FFFF&(data))>>0)
#define DC_PC_SYSH_PROG_2_get_sysh2_hitend_cnt(data)                          ((0x0000FFFF&(data))>>0)


#define DC_BIST_MODE                                                          0x180071C0
#define DC_BIST_MODE_reg_addr                                                 "0xB80071C0"
#define DC_BIST_MODE_reg                                                      0xB80071C0
#define set_DC_BIST_MODE_reg(data)   (*((volatile unsigned int*) DC_BIST_MODE_reg)=data)
#define get_DC_BIST_MODE_reg   (*((volatile unsigned int*) DC_BIST_MODE_reg))
#define DC_BIST_MODE_inst_adr                                                 "0x0070"
#define DC_BIST_MODE_inst                                                     0x0070
#define DC_BIST_MODE_DC_BIST_MODE_PICT0_shift                                 (1)
#define DC_BIST_MODE_DC_BIST_MODE_PICT0_mask                                  (0x00000002)
#define DC_BIST_MODE_DC_BIST_MODE_PICT0(data)                                 (0x00000002&((data)<<1))
#define DC_BIST_MODE_DC_BIST_MODE_PICT0_src(data)                             ((0x00000002&(data))>>1)
#define DC_BIST_MODE_get_DC_BIST_MODE_PICT0(data)                             ((0x00000002&(data))>>1)


#define DC_BIST_DONE                                                          0x180071C4
#define DC_BIST_DONE_reg_addr                                                 "0xB80071C4"
#define DC_BIST_DONE_reg                                                      0xB80071C4
#define set_DC_BIST_DONE_reg(data)   (*((volatile unsigned int*) DC_BIST_DONE_reg)=data)
#define get_DC_BIST_DONE_reg   (*((volatile unsigned int*) DC_BIST_DONE_reg))
#define DC_BIST_DONE_inst_adr                                                 "0x0071"
#define DC_BIST_DONE_inst                                                     0x0071
#define DC_BIST_DONE_DC_BIST_DONE_PICT0_shift                                 (1)
#define DC_BIST_DONE_DC_BIST_DONE_PICT0_mask                                  (0x00000002)
#define DC_BIST_DONE_DC_BIST_DONE_PICT0(data)                                 (0x00000002&((data)<<1))
#define DC_BIST_DONE_DC_BIST_DONE_PICT0_src(data)                             ((0x00000002&(data))>>1)
#define DC_BIST_DONE_get_DC_BIST_DONE_PICT0(data)                             ((0x00000002&(data))>>1)


#define DC_BIST_FAIL                                                          0x180071C8
#define DC_BIST_FAIL_reg_addr                                                 "0xB80071C8"
#define DC_BIST_FAIL_reg                                                      0xB80071C8
#define set_DC_BIST_FAIL_reg(data)   (*((volatile unsigned int*) DC_BIST_FAIL_reg)=data)
#define get_DC_BIST_FAIL_reg   (*((volatile unsigned int*) DC_BIST_FAIL_reg))
#define DC_BIST_FAIL_inst_adr                                                 "0x0072"
#define DC_BIST_FAIL_inst                                                     0x0072
#define DC_BIST_FAIL_DC_BIST_FAIL_GROUP_PICT0_shift                           (1)
#define DC_BIST_FAIL_DC_BIST_FAIL_GROUP_PICT0_mask                            (0x00000002)
#define DC_BIST_FAIL_DC_BIST_FAIL_GROUP_PICT0(data)                           (0x00000002&((data)<<1))
#define DC_BIST_FAIL_DC_BIST_FAIL_GROUP_PICT0_src(data)                       ((0x00000002&(data))>>1)
#define DC_BIST_FAIL_get_DC_BIST_FAIL_GROUP_PICT0(data)                       ((0x00000002&(data))>>1)


#define DC_BIST_DRF                                                           0x180071CC
#define DC_BIST_DRF_reg_addr                                                  "0xB80071CC"
#define DC_BIST_DRF_reg                                                       0xB80071CC
#define set_DC_BIST_DRF_reg(data)   (*((volatile unsigned int*) DC_BIST_DRF_reg)=data)
#define get_DC_BIST_DRF_reg   (*((volatile unsigned int*) DC_BIST_DRF_reg))
#define DC_BIST_DRF_inst_adr                                                  "0x0073"
#define DC_BIST_DRF_inst                                                      0x0073
#define DC_BIST_DRF_DC_DRF_MODE_PICT0_shift                                   (1)
#define DC_BIST_DRF_DC_DRF_MODE_PICT0_mask                                    (0x00000002)
#define DC_BIST_DRF_DC_DRF_MODE_PICT0(data)                                   (0x00000002&((data)<<1))
#define DC_BIST_DRF_DC_DRF_MODE_PICT0_src(data)                               ((0x00000002&(data))>>1)
#define DC_BIST_DRF_get_DC_DRF_MODE_PICT0(data)                               ((0x00000002&(data))>>1)


#define DC_BIST_RESUME                                                        0x180071D0
#define DC_BIST_RESUME_reg_addr                                               "0xB80071D0"
#define DC_BIST_RESUME_reg                                                    0xB80071D0
#define set_DC_BIST_RESUME_reg(data)   (*((volatile unsigned int*) DC_BIST_RESUME_reg)=data)
#define get_DC_BIST_RESUME_reg   (*((volatile unsigned int*) DC_BIST_RESUME_reg))
#define DC_BIST_RESUME_inst_adr                                               "0x0074"
#define DC_BIST_RESUME_inst                                                   0x0074
#define DC_BIST_RESUME_DC_DRF_RESUME_PICT0_shift                              (1)
#define DC_BIST_RESUME_DC_DRF_RESUME_PICT0_mask                               (0x00000002)
#define DC_BIST_RESUME_DC_DRF_RESUME_PICT0(data)                              (0x00000002&((data)<<1))
#define DC_BIST_RESUME_DC_DRF_RESUME_PICT0_src(data)                          ((0x00000002&(data))>>1)
#define DC_BIST_RESUME_get_DC_DRF_RESUME_PICT0(data)                          ((0x00000002&(data))>>1)


#define DC_BIST0_DRF_DONE                                                     0x180071D4
#define DC_BIST0_DRF_DONE_reg_addr                                            "0xB80071D4"
#define DC_BIST0_DRF_DONE_reg                                                 0xB80071D4
#define set_DC_BIST0_DRF_DONE_reg(data)   (*((volatile unsigned int*) DC_BIST0_DRF_DONE_reg)=data)
#define get_DC_BIST0_DRF_DONE_reg   (*((volatile unsigned int*) DC_BIST0_DRF_DONE_reg))
#define DC_BIST0_DRF_DONE_inst_adr                                            "0x0075"
#define DC_BIST0_DRF_DONE_inst                                                0x0075
#define DC_BIST0_DRF_DONE_DC_DRF_DONE_PICT0_shift                             (1)
#define DC_BIST0_DRF_DONE_DC_DRF_DONE_PICT0_mask                              (0x00000002)
#define DC_BIST0_DRF_DONE_DC_DRF_DONE_PICT0(data)                             (0x00000002&((data)<<1))
#define DC_BIST0_DRF_DONE_DC_DRF_DONE_PICT0_src(data)                         ((0x00000002&(data))>>1)
#define DC_BIST0_DRF_DONE_get_DC_DRF_DONE_PICT0(data)                         ((0x00000002&(data))>>1)


#define DC_BIST_DRF_PAUSE                                                     0x180071D8
#define DC_BIST_DRF_PAUSE_reg_addr                                            "0xB80071D8"
#define DC_BIST_DRF_PAUSE_reg                                                 0xB80071D8
#define set_DC_BIST_DRF_PAUSE_reg(data)   (*((volatile unsigned int*) DC_BIST_DRF_PAUSE_reg)=data)
#define get_DC_BIST_DRF_PAUSE_reg   (*((volatile unsigned int*) DC_BIST_DRF_PAUSE_reg))
#define DC_BIST_DRF_PAUSE_inst_adr                                            "0x0076"
#define DC_BIST_DRF_PAUSE_inst                                                0x0076
#define DC_BIST_DRF_PAUSE_DC_DRF_PAUSE_PICT0_shift                            (1)
#define DC_BIST_DRF_PAUSE_DC_DRF_PAUSE_PICT0_mask                             (0x00000002)
#define DC_BIST_DRF_PAUSE_DC_DRF_PAUSE_PICT0(data)                            (0x00000002&((data)<<1))
#define DC_BIST_DRF_PAUSE_DC_DRF_PAUSE_PICT0_src(data)                        ((0x00000002&(data))>>1)
#define DC_BIST_DRF_PAUSE_get_DC_DRF_PAUSE_PICT0(data)                        ((0x00000002&(data))>>1)


#define DC_BIST_DRF_FAIL                                                      0x180071DC
#define DC_BIST_DRF_FAIL_reg_addr                                             "0xB80071DC"
#define DC_BIST_DRF_FAIL_reg                                                  0xB80071DC
#define set_DC_BIST_DRF_FAIL_reg(data)   (*((volatile unsigned int*) DC_BIST_DRF_FAIL_reg)=data)
#define get_DC_BIST_DRF_FAIL_reg   (*((volatile unsigned int*) DC_BIST_DRF_FAIL_reg))
#define DC_BIST_DRF_FAIL_inst_adr                                             "0x0077"
#define DC_BIST_DRF_FAIL_inst                                                 0x0077
#define DC_BIST_DRF_FAIL_DC_DRF_FAIL_GROUP_PICT0_shift                        (1)
#define DC_BIST_DRF_FAIL_DC_DRF_FAIL_GROUP_PICT0_mask                         (0x00000002)
#define DC_BIST_DRF_FAIL_DC_DRF_FAIL_GROUP_PICT0(data)                        (0x00000002&((data)<<1))
#define DC_BIST_DRF_FAIL_DC_DRF_FAIL_GROUP_PICT0_src(data)                    ((0x00000002&(data))>>1)
#define DC_BIST_DRF_FAIL_get_DC_DRF_FAIL_GROUP_PICT0(data)                    ((0x00000002&(data))>>1)


#define DC_BIST_DETAIL                                                        0x180071E0
#define DC_BIST_DETAIL_reg_addr                                               "0xB80071E0"
#define DC_BIST_DETAIL_reg                                                    0xB80071E0
#define set_DC_BIST_DETAIL_reg(data)   (*((volatile unsigned int*) DC_BIST_DETAIL_reg)=data)
#define get_DC_BIST_DETAIL_reg   (*((volatile unsigned int*) DC_BIST_DETAIL_reg))
#define DC_BIST_DETAIL_inst_adr                                               "0x0078"
#define DC_BIST_DETAIL_inst                                                   0x0078
#define DC_BIST_DETAIL_DC_DRF_PICT_FAIL0_shift                                (5)
#define DC_BIST_DETAIL_DC_DRF_PICT_FAIL0_mask                                 (0x00000020)
#define DC_BIST_DETAIL_DC_DRF_PICT_FAIL0(data)                                (0x00000020&((data)<<5))
#define DC_BIST_DETAIL_DC_DRF_PICT_FAIL0_src(data)                            ((0x00000020&(data))>>5)
#define DC_BIST_DETAIL_get_DC_DRF_PICT_FAIL0(data)                            ((0x00000020&(data))>>5)
#define DC_BIST_DETAIL_DC_BIST_PICT_FAIL0_shift                               (4)
#define DC_BIST_DETAIL_DC_BIST_PICT_FAIL0_mask                                (0x00000010)
#define DC_BIST_DETAIL_DC_BIST_PICT_FAIL0(data)                               (0x00000010&((data)<<4))
#define DC_BIST_DETAIL_DC_BIST_PICT_FAIL0_src(data)                           ((0x00000010&(data))>>4)
#define DC_BIST_DETAIL_get_DC_BIST_PICT_FAIL0(data)                           ((0x00000010&(data))>>4)


#define DC_BIST_RM                                                            0x180071E4
#define DC_BIST_RM_reg_addr                                                   "0xB80071E4"
#define DC_BIST_RM_reg                                                        0xB80071E4
#define set_DC_BIST_RM_reg(data)   (*((volatile unsigned int*) DC_BIST_RM_reg)=data)
#define get_DC_BIST_RM_reg   (*((volatile unsigned int*) DC_BIST_RM_reg))
#define DC_BIST_RM_inst_adr                                                   "0x0079"
#define DC_BIST_RM_inst                                                       0x0079
#define DC_BIST_RM_RME_shift                                                  (4)
#define DC_BIST_RM_RME_mask                                                   (0x00000010)
#define DC_BIST_RM_RME(data)                                                  (0x00000010&((data)<<4))
#define DC_BIST_RM_RME_src(data)                                              ((0x00000010&(data))>>4)
#define DC_BIST_RM_get_RME(data)                                              ((0x00000010&(data))>>4)
#define DC_BIST_RM_RM_3_shift                                                 (3)
#define DC_BIST_RM_RM_3_mask                                                  (0x00000008)
#define DC_BIST_RM_RM_3(data)                                                 (0x00000008&((data)<<3))
#define DC_BIST_RM_RM_3_src(data)                                             ((0x00000008&(data))>>3)
#define DC_BIST_RM_get_RM_3(data)                                             ((0x00000008&(data))>>3)
#define DC_BIST_RM_RM_2_shift                                                 (2)
#define DC_BIST_RM_RM_2_mask                                                  (0x00000004)
#define DC_BIST_RM_RM_2(data)                                                 (0x00000004&((data)<<2))
#define DC_BIST_RM_RM_2_src(data)                                             ((0x00000004&(data))>>2)
#define DC_BIST_RM_get_RM_2(data)                                             ((0x00000004&(data))>>2)
#define DC_BIST_RM_RM_1_shift                                                 (1)
#define DC_BIST_RM_RM_1_mask                                                  (0x00000002)
#define DC_BIST_RM_RM_1(data)                                                 (0x00000002&((data)<<1))
#define DC_BIST_RM_RM_1_src(data)                                             ((0x00000002&(data))>>1)
#define DC_BIST_RM_get_RM_1(data)                                             ((0x00000002&(data))>>1)
#define DC_BIST_RM_RM_0_shift                                                 (0)
#define DC_BIST_RM_RM_0_mask                                                  (0x00000001)
#define DC_BIST_RM_RM_0(data)                                                 (0x00000001&((data)<<0))
#define DC_BIST_RM_RM_0_src(data)                                             ((0x00000001&(data))>>0)
#define DC_BIST_RM_get_RM_0(data)                                             ((0x00000001&(data))>>0)


#define DC_DUMMY_REG0                                                         0x180071F0
#define DC_DUMMY_REG0_reg_addr                                                "0xB80071F0"
#define DC_DUMMY_REG0_reg                                                     0xB80071F0
#define set_DC_DUMMY_REG0_reg(data)   (*((volatile unsigned int*) DC_DUMMY_REG0_reg)=data)
#define get_DC_DUMMY_REG0_reg   (*((volatile unsigned int*) DC_DUMMY_REG0_reg))
#define DC_DUMMY_REG0_inst_adr                                                "0x007C"
#define DC_DUMMY_REG0_inst                                                    0x007C
#define DC_DUMMY_REG0_dummy_reg0_shift                                        (0)
#define DC_DUMMY_REG0_dummy_reg0_mask                                         (0xFFFFFFFF)
#define DC_DUMMY_REG0_dummy_reg0(data)                                        (0xFFFFFFFF&((data)<<0))
#define DC_DUMMY_REG0_dummy_reg0_src(data)                                    ((0xFFFFFFFF&(data))>>0)
#define DC_DUMMY_REG0_get_dummy_reg0(data)                                    ((0xFFFFFFFF&(data))>>0)


#define DC_DUMMY_REG1                                                         0x180071F4
#define DC_DUMMY_REG1_reg_addr                                                "0xB80071F4"
#define DC_DUMMY_REG1_reg                                                     0xB80071F4
#define set_DC_DUMMY_REG1_reg(data)   (*((volatile unsigned int*) DC_DUMMY_REG1_reg)=data)
#define get_DC_DUMMY_REG1_reg   (*((volatile unsigned int*) DC_DUMMY_REG1_reg))
#define DC_DUMMY_REG1_inst_adr                                                "0x007D"
#define DC_DUMMY_REG1_inst                                                    0x007D
#define DC_DUMMY_REG1_dummy_reg1_shift                                        (0)
#define DC_DUMMY_REG1_dummy_reg1_mask                                         (0xFFFFFFFF)
#define DC_DUMMY_REG1_dummy_reg1(data)                                        (0xFFFFFFFF&((data)<<0))
#define DC_DUMMY_REG1_dummy_reg1_src(data)                                    ((0xFFFFFFFF&(data))>>0)
#define DC_DUMMY_REG1_get_dummy_reg1(data)                                    ((0xFFFFFFFF&(data))>>0)


#define DC_DUMMY_REG2                                                         0x180071F8
#define DC_DUMMY_REG2_reg_addr                                                "0xB80071F8"
#define DC_DUMMY_REG2_reg                                                     0xB80071F8
#define set_DC_DUMMY_REG2_reg(data)   (*((volatile unsigned int*) DC_DUMMY_REG2_reg)=data)
#define get_DC_DUMMY_REG2_reg   (*((volatile unsigned int*) DC_DUMMY_REG2_reg))
#define DC_DUMMY_REG2_inst_adr                                                "0x007E"
#define DC_DUMMY_REG2_inst                                                    0x007E
#define DC_DUMMY_REG2_dummy_reg2_shift                                        (0)
#define DC_DUMMY_REG2_dummy_reg2_mask                                         (0xFFFFFFFF)
#define DC_DUMMY_REG2_dummy_reg2(data)                                        (0xFFFFFFFF&((data)<<0))
#define DC_DUMMY_REG2_dummy_reg2_src(data)                                    ((0xFFFFFFFF&(data))>>0)
#define DC_DUMMY_REG2_get_dummy_reg2(data)                                    ((0xFFFFFFFF&(data))>>0)


#define DC_DUMMY_REG3                                                         0x180071FC
#define DC_DUMMY_REG3_reg_addr                                                "0xB80071FC"
#define DC_DUMMY_REG3_reg                                                     0xB80071FC
#define set_DC_DUMMY_REG3_reg(data)   (*((volatile unsigned int*) DC_DUMMY_REG3_reg)=data)
#define get_DC_DUMMY_REG3_reg   (*((volatile unsigned int*) DC_DUMMY_REG3_reg))
#define DC_DUMMY_REG3_inst_adr                                                "0x007F"
#define DC_DUMMY_REG3_inst                                                    0x007F
#define DC_DUMMY_REG3_dummy_reg3_shift                                        (0)
#define DC_DUMMY_REG3_dummy_reg3_mask                                         (0xFFFFFFFF)
#define DC_DUMMY_REG3_dummy_reg3(data)                                        (0xFFFFFFFF&((data)<<0))
#define DC_DUMMY_REG3_dummy_reg3_src(data)                                    ((0xFFFFFFFF&(data))>>0)
#define DC_DUMMY_REG3_get_dummy_reg3(data)                                    ((0xFFFFFFFF&(data))>>0)


#define DC_MT_TYPE_0                                                          0x18007200
#define DC_MT_TYPE_1                                                          0x18007204
#define DC_MT_TYPE_2                                                          0x18007208
#define DC_MT_TYPE_3                                                          0x1800720C
#define DC_MT_TYPE_0_reg_addr                                                 "0xB8007200"
#define DC_MT_TYPE_1_reg_addr                                                 "0xB8007204"
#define DC_MT_TYPE_2_reg_addr                                                 "0xB8007208"
#define DC_MT_TYPE_3_reg_addr                                                 "0xB800720C"
#define DC_MT_TYPE_0_reg                                                      0xB8007200
#define DC_MT_TYPE_1_reg                                                      0xB8007204
#define DC_MT_TYPE_2_reg                                                      0xB8007208
#define DC_MT_TYPE_3_reg                                                      0xB800720C
#define set_DC_MT_TYPE_0_reg(data)   (*((volatile unsigned int*) DC_MT_TYPE_0_reg)=data)
#define set_DC_MT_TYPE_1_reg(data)   (*((volatile unsigned int*) DC_MT_TYPE_1_reg)=data)
#define set_DC_MT_TYPE_2_reg(data)   (*((volatile unsigned int*) DC_MT_TYPE_2_reg)=data)
#define set_DC_MT_TYPE_3_reg(data)   (*((volatile unsigned int*) DC_MT_TYPE_3_reg)=data)
#define get_DC_MT_TYPE_0_reg   (*((volatile unsigned int*) DC_MT_TYPE_0_reg))
#define get_DC_MT_TYPE_1_reg   (*((volatile unsigned int*) DC_MT_TYPE_1_reg))
#define get_DC_MT_TYPE_2_reg   (*((volatile unsigned int*) DC_MT_TYPE_2_reg))
#define get_DC_MT_TYPE_3_reg   (*((volatile unsigned int*) DC_MT_TYPE_3_reg))
#define DC_MT_TYPE_0_inst_adr                                                 "0x0080"
#define DC_MT_TYPE_1_inst_adr                                                 "0x0081"
#define DC_MT_TYPE_2_inst_adr                                                 "0x0082"
#define DC_MT_TYPE_3_inst_adr                                                 "0x0083"
#define DC_MT_TYPE_0_inst                                                     0x0080
#define DC_MT_TYPE_1_inst                                                     0x0081
#define DC_MT_TYPE_2_inst                                                     0x0082
#define DC_MT_TYPE_3_inst                                                     0x0083
#define DC_MT_TYPE_mem_type_shift                                             (30)
#define DC_MT_TYPE_mem_type_mask                                              (0xC0000000)
#define DC_MT_TYPE_mem_type(data)                                             (0xC0000000&((data)<<30))
#define DC_MT_TYPE_mem_type_src(data)                                         ((0xC0000000&(data))>>30)
#define DC_MT_TYPE_get_mem_type(data)                                         ((0xC0000000&(data))>>30)


#define DC_MT_SADDR_0                                                         0x18007210
#define DC_MT_SADDR_1                                                         0x18007214
#define DC_MT_SADDR_2                                                         0x18007218
#define DC_MT_SADDR_3                                                         0x1800721C
#define DC_MT_SADDR_0_reg_addr                                                "0xB8007210"
#define DC_MT_SADDR_1_reg_addr                                                "0xB8007214"
#define DC_MT_SADDR_2_reg_addr                                                "0xB8007218"
#define DC_MT_SADDR_3_reg_addr                                                "0xB800721C"
#define DC_MT_SADDR_0_reg                                                     0xB8007210
#define DC_MT_SADDR_1_reg                                                     0xB8007214
#define DC_MT_SADDR_2_reg                                                     0xB8007218
#define DC_MT_SADDR_3_reg                                                     0xB800721C
#define set_DC_MT_SADDR_0_reg(data)   (*((volatile unsigned int*) DC_MT_SADDR_0_reg)=data)
#define set_DC_MT_SADDR_1_reg(data)   (*((volatile unsigned int*) DC_MT_SADDR_1_reg)=data)
#define set_DC_MT_SADDR_2_reg(data)   (*((volatile unsigned int*) DC_MT_SADDR_2_reg)=data)
#define set_DC_MT_SADDR_3_reg(data)   (*((volatile unsigned int*) DC_MT_SADDR_3_reg)=data)
#define get_DC_MT_SADDR_0_reg   (*((volatile unsigned int*) DC_MT_SADDR_0_reg))
#define get_DC_MT_SADDR_1_reg   (*((volatile unsigned int*) DC_MT_SADDR_1_reg))
#define get_DC_MT_SADDR_2_reg   (*((volatile unsigned int*) DC_MT_SADDR_2_reg))
#define get_DC_MT_SADDR_3_reg   (*((volatile unsigned int*) DC_MT_SADDR_3_reg))
#define DC_MT_SADDR_0_inst_adr                                                "0x0084"
#define DC_MT_SADDR_1_inst_adr                                                "0x0085"
#define DC_MT_SADDR_2_inst_adr                                                "0x0086"
#define DC_MT_SADDR_3_inst_adr                                                "0x0087"
#define DC_MT_SADDR_0_inst                                                    0x0084
#define DC_MT_SADDR_1_inst                                                    0x0085
#define DC_MT_SADDR_2_inst                                                    0x0086
#define DC_MT_SADDR_3_inst                                                    0x0087
#define DC_MT_SADDR_saddr_shift                                               (5)
#define DC_MT_SADDR_saddr_mask                                                (0x7FFFFFE0)
#define DC_MT_SADDR_saddr(data)                                               (0x7FFFFFE0&((data)<<5))
#define DC_MT_SADDR_saddr_src(data)                                           ((0x7FFFFFE0&(data))>>5)
#define DC_MT_SADDR_get_saddr(data)                                           ((0x7FFFFFE0&(data))>>5)


#define DC_MT_EADDR_0                                                         0x18007220
#define DC_MT_EADDR_1                                                         0x18007224
#define DC_MT_EADDR_2                                                         0x18007228
#define DC_MT_EADDR_3                                                         0x1800722C
#define DC_MT_EADDR_0_reg_addr                                                "0xB8007220"
#define DC_MT_EADDR_1_reg_addr                                                "0xB8007224"
#define DC_MT_EADDR_2_reg_addr                                                "0xB8007228"
#define DC_MT_EADDR_3_reg_addr                                                "0xB800722C"
#define DC_MT_EADDR_0_reg                                                     0xB8007220
#define DC_MT_EADDR_1_reg                                                     0xB8007224
#define DC_MT_EADDR_2_reg                                                     0xB8007228
#define DC_MT_EADDR_3_reg                                                     0xB800722C
#define set_DC_MT_EADDR_0_reg(data)   (*((volatile unsigned int*) DC_MT_EADDR_0_reg)=data)
#define set_DC_MT_EADDR_1_reg(data)   (*((volatile unsigned int*) DC_MT_EADDR_1_reg)=data)
#define set_DC_MT_EADDR_2_reg(data)   (*((volatile unsigned int*) DC_MT_EADDR_2_reg)=data)
#define set_DC_MT_EADDR_3_reg(data)   (*((volatile unsigned int*) DC_MT_EADDR_3_reg)=data)
#define get_DC_MT_EADDR_0_reg   (*((volatile unsigned int*) DC_MT_EADDR_0_reg))
#define get_DC_MT_EADDR_1_reg   (*((volatile unsigned int*) DC_MT_EADDR_1_reg))
#define get_DC_MT_EADDR_2_reg   (*((volatile unsigned int*) DC_MT_EADDR_2_reg))
#define get_DC_MT_EADDR_3_reg   (*((volatile unsigned int*) DC_MT_EADDR_3_reg))
#define DC_MT_EADDR_0_inst_adr                                                "0x0088"
#define DC_MT_EADDR_1_inst_adr                                                "0x0089"
#define DC_MT_EADDR_2_inst_adr                                                "0x008A"
#define DC_MT_EADDR_3_inst_adr                                                "0x008B"
#define DC_MT_EADDR_0_inst                                                    0x0088
#define DC_MT_EADDR_1_inst                                                    0x0089
#define DC_MT_EADDR_2_inst                                                    0x008A
#define DC_MT_EADDR_3_inst                                                    0x008B
#define DC_MT_EADDR_eaddr_shift                                               (5)
#define DC_MT_EADDR_eaddr_mask                                                (0x7FFFFFE0)
#define DC_MT_EADDR_eaddr(data)                                               (0x7FFFFFE0&((data)<<5))
#define DC_MT_EADDR_eaddr_src(data)                                           ((0x7FFFFFE0&(data))>>5)
#define DC_MT_EADDR_get_eaddr(data)                                           ((0x7FFFFFE0&(data))>>5)


#define DC_MT_MODE_0                                                          0x18007240
#define DC_MT_MODE_1                                                          0x18007244
#define DC_MT_MODE_2                                                          0x18007248
#define DC_MT_MODE_3                                                          0x1800724C
#define DC_MT_MODE_0_reg_addr                                                 "0xB8007240"
#define DC_MT_MODE_1_reg_addr                                                 "0xB8007244"
#define DC_MT_MODE_2_reg_addr                                                 "0xB8007248"
#define DC_MT_MODE_3_reg_addr                                                 "0xB800724C"
#define DC_MT_MODE_0_reg                                                      0xB8007240
#define DC_MT_MODE_1_reg                                                      0xB8007244
#define DC_MT_MODE_2_reg                                                      0xB8007248
#define DC_MT_MODE_3_reg                                                      0xB800724C
#define set_DC_MT_MODE_0_reg(data)   (*((volatile unsigned int*) DC_MT_MODE_0_reg)=data)
#define set_DC_MT_MODE_1_reg(data)   (*((volatile unsigned int*) DC_MT_MODE_1_reg)=data)
#define set_DC_MT_MODE_2_reg(data)   (*((volatile unsigned int*) DC_MT_MODE_2_reg)=data)
#define set_DC_MT_MODE_3_reg(data)   (*((volatile unsigned int*) DC_MT_MODE_3_reg)=data)
#define get_DC_MT_MODE_0_reg   (*((volatile unsigned int*) DC_MT_MODE_0_reg))
#define get_DC_MT_MODE_1_reg   (*((volatile unsigned int*) DC_MT_MODE_1_reg))
#define get_DC_MT_MODE_2_reg   (*((volatile unsigned int*) DC_MT_MODE_2_reg))
#define get_DC_MT_MODE_3_reg   (*((volatile unsigned int*) DC_MT_MODE_3_reg))
#define DC_MT_MODE_0_inst_adr                                                 "0x0090"
#define DC_MT_MODE_1_inst_adr                                                 "0x0091"
#define DC_MT_MODE_2_inst_adr                                                 "0x0092"
#define DC_MT_MODE_3_inst_adr                                                 "0x0093"
#define DC_MT_MODE_0_inst                                                     0x0090
#define DC_MT_MODE_1_inst                                                     0x0091
#define DC_MT_MODE_2_inst                                                     0x0092
#define DC_MT_MODE_3_inst                                                     0x0093
#define DC_MT_MODE_write_enable5_shift                                        (2)
#define DC_MT_MODE_write_enable5_mask                                         (0x00000004)
#define DC_MT_MODE_write_enable5(data)                                        (0x00000004&((data)<<2))
#define DC_MT_MODE_write_enable5_src(data)                                    ((0x00000004&(data))>>2)
#define DC_MT_MODE_get_write_enable5(data)                                    ((0x00000004&(data))>>2)
#define DC_MT_MODE_mode_shift                                                 (0)
#define DC_MT_MODE_mode_mask                                                  (0x00000003)
#define DC_MT_MODE_mode(data)                                                 (0x00000003&((data)<<0))
#define DC_MT_MODE_mode_src(data)                                             ((0x00000003&(data))>>0)
#define DC_MT_MODE_get_mode(data)                                             ((0x00000003&(data))>>0)


#define DC_MT_TABLE_0                                                         0x18007260
#define DC_MT_TABLE_1                                                         0x18007264
#define DC_MT_TABLE_2                                                         0x18007268
#define DC_MT_TABLE_3                                                         0x1800726C
#define DC_MT_TABLE_0_reg_addr                                                "0xB8007260"
#define DC_MT_TABLE_1_reg_addr                                                "0xB8007264"
#define DC_MT_TABLE_2_reg_addr                                                "0xB8007268"
#define DC_MT_TABLE_3_reg_addr                                                "0xB800726C"
#define DC_MT_TABLE_0_reg                                                     0xB8007260
#define DC_MT_TABLE_1_reg                                                     0xB8007264
#define DC_MT_TABLE_2_reg                                                     0xB8007268
#define DC_MT_TABLE_3_reg                                                     0xB800726C
#define set_DC_MT_TABLE_0_reg(data)   (*((volatile unsigned int*) DC_MT_TABLE_0_reg)=data)
#define set_DC_MT_TABLE_1_reg(data)   (*((volatile unsigned int*) DC_MT_TABLE_1_reg)=data)
#define set_DC_MT_TABLE_2_reg(data)   (*((volatile unsigned int*) DC_MT_TABLE_2_reg)=data)
#define set_DC_MT_TABLE_3_reg(data)   (*((volatile unsigned int*) DC_MT_TABLE_3_reg)=data)
#define get_DC_MT_TABLE_0_reg   (*((volatile unsigned int*) DC_MT_TABLE_0_reg))
#define get_DC_MT_TABLE_1_reg   (*((volatile unsigned int*) DC_MT_TABLE_1_reg))
#define get_DC_MT_TABLE_2_reg   (*((volatile unsigned int*) DC_MT_TABLE_2_reg))
#define get_DC_MT_TABLE_3_reg   (*((volatile unsigned int*) DC_MT_TABLE_3_reg))
#define DC_MT_TABLE_0_inst_adr                                                "0x0098"
#define DC_MT_TABLE_1_inst_adr                                                "0x0099"
#define DC_MT_TABLE_2_inst_adr                                                "0x009A"
#define DC_MT_TABLE_3_inst_adr                                                "0x009B"
#define DC_MT_TABLE_0_inst                                                    0x0098
#define DC_MT_TABLE_1_inst                                                    0x0099
#define DC_MT_TABLE_2_inst                                                    0x009A
#define DC_MT_TABLE_3_inst                                                    0x009B
#define DC_MT_TABLE_module_ID_0_shift                                         (24)
#define DC_MT_TABLE_module_ID_0_mask                                          (0x7F000000)
#define DC_MT_TABLE_module_ID_0(data)                                         (0x7F000000&((data)<<24))
#define DC_MT_TABLE_module_ID_0_src(data)                                     ((0x7F000000&(data))>>24)
#define DC_MT_TABLE_get_module_ID_0(data)                                     ((0x7F000000&(data))>>24)
#define DC_MT_TABLE_module_ID_1_shift                                         (16)
#define DC_MT_TABLE_module_ID_1_mask                                          (0x007F0000)
#define DC_MT_TABLE_module_ID_1(data)                                         (0x007F0000&((data)<<16))
#define DC_MT_TABLE_module_ID_1_src(data)                                     ((0x007F0000&(data))>>16)
#define DC_MT_TABLE_get_module_ID_1(data)                                     ((0x007F0000&(data))>>16)
#define DC_MT_TABLE_module_ID_2_shift                                         (8)
#define DC_MT_TABLE_module_ID_2_mask                                          (0x00007F00)
#define DC_MT_TABLE_module_ID_2(data)                                         (0x00007F00&((data)<<8))
#define DC_MT_TABLE_module_ID_2_src(data)                                     ((0x00007F00&(data))>>8)
#define DC_MT_TABLE_get_module_ID_2(data)                                     ((0x00007F00&(data))>>8)
#define DC_MT_TABLE_module_ID_3_shift                                         (0)
#define DC_MT_TABLE_module_ID_3_mask                                          (0x0000007F)
#define DC_MT_TABLE_module_ID_3(data)                                         (0x0000007F&((data)<<0))
#define DC_MT_TABLE_module_ID_3_src(data)                                     ((0x0000007F&(data))>>0)
#define DC_MT_TABLE_get_module_ID_3(data)                                     ((0x0000007F&(data))>>0)


#define DC_MT_ADDCMD_HI_0                                                     0x18007280
#define DC_MT_ADDCMD_HI_1                                                     0x18007284
#define DC_MT_ADDCMD_HI_2                                                     0x18007288
#define DC_MT_ADDCMD_HI_3                                                     0x1800728C
#define DC_MT_ADDCMD_HI_0_reg_addr                                            "0xB8007280"
#define DC_MT_ADDCMD_HI_1_reg_addr                                            "0xB8007284"
#define DC_MT_ADDCMD_HI_2_reg_addr                                            "0xB8007288"
#define DC_MT_ADDCMD_HI_3_reg_addr                                            "0xB800728C"
#define DC_MT_ADDCMD_HI_0_reg                                                 0xB8007280
#define DC_MT_ADDCMD_HI_1_reg                                                 0xB8007284
#define DC_MT_ADDCMD_HI_2_reg                                                 0xB8007288
#define DC_MT_ADDCMD_HI_3_reg                                                 0xB800728C
#define set_DC_MT_ADDCMD_HI_0_reg(data)   (*((volatile unsigned int*) DC_MT_ADDCMD_HI_0_reg)=data)
#define set_DC_MT_ADDCMD_HI_1_reg(data)   (*((volatile unsigned int*) DC_MT_ADDCMD_HI_1_reg)=data)
#define set_DC_MT_ADDCMD_HI_2_reg(data)   (*((volatile unsigned int*) DC_MT_ADDCMD_HI_2_reg)=data)
#define set_DC_MT_ADDCMD_HI_3_reg(data)   (*((volatile unsigned int*) DC_MT_ADDCMD_HI_3_reg)=data)
#define get_DC_MT_ADDCMD_HI_0_reg   (*((volatile unsigned int*) DC_MT_ADDCMD_HI_0_reg))
#define get_DC_MT_ADDCMD_HI_1_reg   (*((volatile unsigned int*) DC_MT_ADDCMD_HI_1_reg))
#define get_DC_MT_ADDCMD_HI_2_reg   (*((volatile unsigned int*) DC_MT_ADDCMD_HI_2_reg))
#define get_DC_MT_ADDCMD_HI_3_reg   (*((volatile unsigned int*) DC_MT_ADDCMD_HI_3_reg))
#define DC_MT_ADDCMD_HI_0_inst_adr                                            "0x00A0"
#define DC_MT_ADDCMD_HI_1_inst_adr                                            "0x00A1"
#define DC_MT_ADDCMD_HI_2_inst_adr                                            "0x00A2"
#define DC_MT_ADDCMD_HI_3_inst_adr                                            "0x00A3"
#define DC_MT_ADDCMD_HI_0_inst                                                0x00A0
#define DC_MT_ADDCMD_HI_1_inst                                                0x00A1
#define DC_MT_ADDCMD_HI_2_inst                                                0x00A2
#define DC_MT_ADDCMD_HI_3_inst                                                0x00A3
#define DC_MT_ADDCMD_HI_access_type_0_shift                                   (30)
#define DC_MT_ADDCMD_HI_access_type_0_mask                                    (0xC0000000)
#define DC_MT_ADDCMD_HI_access_type_0(data)                                   (0xC0000000&((data)<<30))
#define DC_MT_ADDCMD_HI_access_type_0_src(data)                               ((0xC0000000&(data))>>30)
#define DC_MT_ADDCMD_HI_get_access_type_0(data)                               ((0xC0000000&(data))>>30)
#define DC_MT_ADDCMD_HI_access_type_1_shift                                   (28)
#define DC_MT_ADDCMD_HI_access_type_1_mask                                    (0x30000000)
#define DC_MT_ADDCMD_HI_access_type_1(data)                                   (0x30000000&((data)<<28))
#define DC_MT_ADDCMD_HI_access_type_1_src(data)                               ((0x30000000&(data))>>28)
#define DC_MT_ADDCMD_HI_get_access_type_1(data)                               ((0x30000000&(data))>>28)
#define DC_MT_ADDCMD_HI_access_type_2_shift                                   (26)
#define DC_MT_ADDCMD_HI_access_type_2_mask                                    (0x0C000000)
#define DC_MT_ADDCMD_HI_access_type_2(data)                                   (0x0C000000&((data)<<26))
#define DC_MT_ADDCMD_HI_access_type_2_src(data)                               ((0x0C000000&(data))>>26)
#define DC_MT_ADDCMD_HI_get_access_type_2(data)                               ((0x0C000000&(data))>>26)
#define DC_MT_ADDCMD_HI_access_type_3_shift                                   (24)
#define DC_MT_ADDCMD_HI_access_type_3_mask                                    (0x03000000)
#define DC_MT_ADDCMD_HI_access_type_3(data)                                   (0x03000000&((data)<<24))
#define DC_MT_ADDCMD_HI_access_type_3_src(data)                               ((0x03000000&(data))>>24)
#define DC_MT_ADDCMD_HI_get_access_type_3(data)                               ((0x03000000&(data))>>24)
#define DC_MT_ADDCMD_HI_ever_trap_shift                                       (21)
#define DC_MT_ADDCMD_HI_ever_trap_mask                                        (0x00200000)
#define DC_MT_ADDCMD_HI_ever_trap(data)                                       (0x00200000&((data)<<21))
#define DC_MT_ADDCMD_HI_ever_trap_src(data)                                   ((0x00200000&(data))>>21)
#define DC_MT_ADDCMD_HI_get_ever_trap(data)                                   ((0x00200000&(data))>>21)
#define DC_MT_ADDCMD_HI_module_ID_shift                                       (14)
#define DC_MT_ADDCMD_HI_module_ID_mask                                        (0x001FC000)
#define DC_MT_ADDCMD_HI_module_ID(data)                                       (0x001FC000&((data)<<14))
#define DC_MT_ADDCMD_HI_module_ID_src(data)                                   ((0x001FC000&(data))>>14)
#define DC_MT_ADDCMD_HI_get_module_ID(data)                                   ((0x001FC000&(data))>>14)
#define DC_MT_ADDCMD_HI_addcmd_shift                                          (0)
#define DC_MT_ADDCMD_HI_addcmd_mask                                           (0x00003FFF)
#define DC_MT_ADDCMD_HI_addcmd(data)                                          (0x00003FFF&((data)<<0))
#define DC_MT_ADDCMD_HI_addcmd_src(data)                                      ((0x00003FFF&(data))>>0)
#define DC_MT_ADDCMD_HI_get_addcmd(data)                                      ((0x00003FFF&(data))>>0)


#define DC_MT_ADDCMD_LO_0                                                     0x180072A0
#define DC_MT_ADDCMD_LO_1                                                     0x180072A4
#define DC_MT_ADDCMD_LO_2                                                     0x180072A8
#define DC_MT_ADDCMD_LO_3                                                     0x180072AC
#define DC_MT_ADDCMD_LO_0_reg_addr                                            "0xB80072A0"
#define DC_MT_ADDCMD_LO_1_reg_addr                                            "0xB80072A4"
#define DC_MT_ADDCMD_LO_2_reg_addr                                            "0xB80072A8"
#define DC_MT_ADDCMD_LO_3_reg_addr                                            "0xB80072AC"
#define DC_MT_ADDCMD_LO_0_reg                                                 0xB80072A0
#define DC_MT_ADDCMD_LO_1_reg                                                 0xB80072A4
#define DC_MT_ADDCMD_LO_2_reg                                                 0xB80072A8
#define DC_MT_ADDCMD_LO_3_reg                                                 0xB80072AC
#define set_DC_MT_ADDCMD_LO_0_reg(data)   (*((volatile unsigned int*) DC_MT_ADDCMD_LO_0_reg)=data)
#define set_DC_MT_ADDCMD_LO_1_reg(data)   (*((volatile unsigned int*) DC_MT_ADDCMD_LO_1_reg)=data)
#define set_DC_MT_ADDCMD_LO_2_reg(data)   (*((volatile unsigned int*) DC_MT_ADDCMD_LO_2_reg)=data)
#define set_DC_MT_ADDCMD_LO_3_reg(data)   (*((volatile unsigned int*) DC_MT_ADDCMD_LO_3_reg)=data)
#define get_DC_MT_ADDCMD_LO_0_reg   (*((volatile unsigned int*) DC_MT_ADDCMD_LO_0_reg))
#define get_DC_MT_ADDCMD_LO_1_reg   (*((volatile unsigned int*) DC_MT_ADDCMD_LO_1_reg))
#define get_DC_MT_ADDCMD_LO_2_reg   (*((volatile unsigned int*) DC_MT_ADDCMD_LO_2_reg))
#define get_DC_MT_ADDCMD_LO_3_reg   (*((volatile unsigned int*) DC_MT_ADDCMD_LO_3_reg))
#define DC_MT_ADDCMD_LO_0_inst_adr                                            "0x00A8"
#define DC_MT_ADDCMD_LO_1_inst_adr                                            "0x00A9"
#define DC_MT_ADDCMD_LO_2_inst_adr                                            "0x00AA"
#define DC_MT_ADDCMD_LO_3_inst_adr                                            "0x00AB"
#define DC_MT_ADDCMD_LO_0_inst                                                0x00A8
#define DC_MT_ADDCMD_LO_1_inst                                                0x00A9
#define DC_MT_ADDCMD_LO_2_inst                                                0x00AA
#define DC_MT_ADDCMD_LO_3_inst                                                0x00AB
#define DC_MT_ADDCMD_LO_addcmd_shift                                          (0)
#define DC_MT_ADDCMD_LO_addcmd_mask                                           (0xFFFFFFFF)
#define DC_MT_ADDCMD_LO_addcmd(data)                                          (0xFFFFFFFF&((data)<<0))
#define DC_MT_ADDCMD_LO_addcmd_src(data)                                      ((0xFFFFFFFF&(data))>>0)
#define DC_MT_ADDCMD_LO_get_addcmd(data)                                      ((0xFFFFFFFF&(data))>>0)


#define DC_MT_ADDCMD_SA_0                                                     0x180072B0
#define DC_MT_ADDCMD_SA_1                                                     0x180072B4
#define DC_MT_ADDCMD_SA_2                                                     0x180072B8
#define DC_MT_ADDCMD_SA_3                                                     0x180072BC
#define DC_MT_ADDCMD_SA_0_reg_addr                                            "0xB80072B0"
#define DC_MT_ADDCMD_SA_1_reg_addr                                            "0xB80072B4"
#define DC_MT_ADDCMD_SA_2_reg_addr                                            "0xB80072B8"
#define DC_MT_ADDCMD_SA_3_reg_addr                                            "0xB80072BC"
#define DC_MT_ADDCMD_SA_0_reg                                                 0xB80072B0
#define DC_MT_ADDCMD_SA_1_reg                                                 0xB80072B4
#define DC_MT_ADDCMD_SA_2_reg                                                 0xB80072B8
#define DC_MT_ADDCMD_SA_3_reg                                                 0xB80072BC
#define set_DC_MT_ADDCMD_SA_0_reg(data)   (*((volatile unsigned int*) DC_MT_ADDCMD_SA_0_reg)=data)
#define set_DC_MT_ADDCMD_SA_1_reg(data)   (*((volatile unsigned int*) DC_MT_ADDCMD_SA_1_reg)=data)
#define set_DC_MT_ADDCMD_SA_2_reg(data)   (*((volatile unsigned int*) DC_MT_ADDCMD_SA_2_reg)=data)
#define set_DC_MT_ADDCMD_SA_3_reg(data)   (*((volatile unsigned int*) DC_MT_ADDCMD_SA_3_reg)=data)
#define get_DC_MT_ADDCMD_SA_0_reg   (*((volatile unsigned int*) DC_MT_ADDCMD_SA_0_reg))
#define get_DC_MT_ADDCMD_SA_1_reg   (*((volatile unsigned int*) DC_MT_ADDCMD_SA_1_reg))
#define get_DC_MT_ADDCMD_SA_2_reg   (*((volatile unsigned int*) DC_MT_ADDCMD_SA_2_reg))
#define get_DC_MT_ADDCMD_SA_3_reg   (*((volatile unsigned int*) DC_MT_ADDCMD_SA_3_reg))
#define DC_MT_ADDCMD_SA_0_inst_adr                                            "0x00AC"
#define DC_MT_ADDCMD_SA_1_inst_adr                                            "0x00AD"
#define DC_MT_ADDCMD_SA_2_inst_adr                                            "0x00AE"
#define DC_MT_ADDCMD_SA_3_inst_adr                                            "0x00AF"
#define DC_MT_ADDCMD_SA_0_inst                                                0x00AC
#define DC_MT_ADDCMD_SA_1_inst                                                0x00AD
#define DC_MT_ADDCMD_SA_2_inst                                                0x00AE
#define DC_MT_ADDCMD_SA_3_inst                                                0x00AF
#define DC_MT_ADDCMD_SA_trap_seq_sa_shift                                     (0)
#define DC_MT_ADDCMD_SA_trap_seq_sa_mask                                      (0xFFFFFFFF)
#define DC_MT_ADDCMD_SA_trap_seq_sa(data)                                     (0xFFFFFFFF&((data)<<0))
#define DC_MT_ADDCMD_SA_trap_seq_sa_src(data)                                 ((0xFFFFFFFF&(data))>>0)
#define DC_MT_ADDCMD_SA_get_trap_seq_sa(data)                                 ((0xFFFFFFFF&(data))>>0)


#define DC_MT_MISC                                                            0x180072C0
#define DC_MT_MISC_reg_addr                                                   "0xB80072C0"
#define DC_MT_MISC_reg                                                        0xB80072C0
#define set_DC_MT_MISC_reg(data)   (*((volatile unsigned int*) DC_MT_MISC_reg)=data)
#define get_DC_MT_MISC_reg   (*((volatile unsigned int*) DC_MT_MISC_reg))
#define DC_MT_MISC_inst_adr                                                   "0x00B0"
#define DC_MT_MISC_inst                                                       0x00B0
#define DC_MT_MISC_enable_block_info_shift                                    (1)
#define DC_MT_MISC_enable_block_info_mask                                     (0x00000002)
#define DC_MT_MISC_enable_block_info(data)                                    (0x00000002&((data)<<1))
#define DC_MT_MISC_enable_block_info_src(data)                                ((0x00000002&(data))>>1)
#define DC_MT_MISC_get_enable_block_info(data)                                ((0x00000002&(data))>>1)
#define DC_MT_MISC_disable_cross_range_check_shift                            (0)
#define DC_MT_MISC_disable_cross_range_check_mask                             (0x00000001)
#define DC_MT_MISC_disable_cross_range_check(data)                            (0x00000001&((data)<<0))
#define DC_MT_MISC_disable_cross_range_check_src(data)                        ((0x00000001&(data))>>0)
#define DC_MT_MISC_get_disable_cross_range_check(data)                        ((0x00000001&(data))>>0)


#define DC_EC_CTRL                                                            0x180072D0
#define DC_EC_CTRL_reg_addr                                                   "0xB80072D0"
#define DC_EC_CTRL_reg                                                        0xB80072D0
#define set_DC_EC_CTRL_reg(data)   (*((volatile unsigned int*) DC_EC_CTRL_reg)=data)
#define get_DC_EC_CTRL_reg   (*((volatile unsigned int*) DC_EC_CTRL_reg))
#define DC_EC_CTRL_inst_adr                                                   "0x00B4"
#define DC_EC_CTRL_inst                                                       0x00B4
#define DC_EC_CTRL_write_enable3_shift                                        (31)
#define DC_EC_CTRL_write_enable3_mask                                         (0x80000000)
#define DC_EC_CTRL_write_enable3(data)                                        (0x80000000&((data)<<31))
#define DC_EC_CTRL_write_enable3_src(data)                                    ((0x80000000&(data))>>31)
#define DC_EC_CTRL_get_write_enable3(data)                                    ((0x80000000&(data))>>31)
#define DC_EC_CTRL_error_cmd_swap_addr_shift                                  (4)
#define DC_EC_CTRL_error_cmd_swap_addr_mask                                   (0x7FFFFFF0)
#define DC_EC_CTRL_error_cmd_swap_addr(data)                                  (0x7FFFFFF0&((data)<<4))
#define DC_EC_CTRL_error_cmd_swap_addr_src(data)                              ((0x7FFFFFF0&(data))>>4)
#define DC_EC_CTRL_get_error_cmd_swap_addr(data)                              ((0x7FFFFFF0&(data))>>4)
#define DC_EC_CTRL_write_enable2_shift                                        (3)
#define DC_EC_CTRL_write_enable2_mask                                         (0x00000008)
#define DC_EC_CTRL_write_enable2(data)                                        (0x00000008&((data)<<3))
#define DC_EC_CTRL_write_enable2_src(data)                                    ((0x00000008&(data))>>3)
#define DC_EC_CTRL_get_write_enable2(data)                                    ((0x00000008&(data))>>3)
#define DC_EC_CTRL_error_cmd_swap_en_shift                                    (2)
#define DC_EC_CTRL_error_cmd_swap_en_mask                                     (0x00000004)
#define DC_EC_CTRL_error_cmd_swap_en(data)                                    (0x00000004&((data)<<2))
#define DC_EC_CTRL_error_cmd_swap_en_src(data)                                ((0x00000004&(data))>>2)
#define DC_EC_CTRL_get_error_cmd_swap_en(data)                                ((0x00000004&(data))>>2)
#define DC_EC_CTRL_write_enable1_shift                                        (1)
#define DC_EC_CTRL_write_enable1_mask                                         (0x00000002)
#define DC_EC_CTRL_write_enable1(data)                                        (0x00000002&((data)<<1))
#define DC_EC_CTRL_write_enable1_src(data)                                    ((0x00000002&(data))>>1)
#define DC_EC_CTRL_get_write_enable1(data)                                    ((0x00000002&(data))>>1)
#define DC_EC_CTRL_error_cmd_detection_en_shift                               (0)
#define DC_EC_CTRL_error_cmd_detection_en_mask                                (0x00000001)
#define DC_EC_CTRL_error_cmd_detection_en(data)                               (0x00000001&((data)<<0))
#define DC_EC_CTRL_error_cmd_detection_en_src(data)                           ((0x00000001&(data))>>0)
#define DC_EC_CTRL_get_error_cmd_detection_en(data)                           ((0x00000001&(data))>>0)


#define DC_EC_ADDCMD_HI                                                       0x180072D4
#define DC_EC_ADDCMD_HI_reg_addr                                              "0xB80072D4"
#define DC_EC_ADDCMD_HI_reg                                                   0xB80072D4
#define set_DC_EC_ADDCMD_HI_reg(data)   (*((volatile unsigned int*) DC_EC_ADDCMD_HI_reg)=data)
#define get_DC_EC_ADDCMD_HI_reg   (*((volatile unsigned int*) DC_EC_ADDCMD_HI_reg))
#define DC_EC_ADDCMD_HI_inst_adr                                              "0x00B5"
#define DC_EC_ADDCMD_HI_inst                                                  0x00B5
#define DC_EC_ADDCMD_HI_error_cmd_ever_trap_shift                             (30)
#define DC_EC_ADDCMD_HI_error_cmd_ever_trap_mask                              (0x40000000)
#define DC_EC_ADDCMD_HI_error_cmd_ever_trap(data)                             (0x40000000&((data)<<30))
#define DC_EC_ADDCMD_HI_error_cmd_ever_trap_src(data)                         ((0x40000000&(data))>>30)
#define DC_EC_ADDCMD_HI_get_error_cmd_ever_trap(data)                         ((0x40000000&(data))>>30)
#define DC_EC_ADDCMD_HI_trap_case_shift                                       (22)
#define DC_EC_ADDCMD_HI_trap_case_mask                                        (0x3FC00000)
#define DC_EC_ADDCMD_HI_trap_case(data)                                       (0x3FC00000&((data)<<22))
#define DC_EC_ADDCMD_HI_trap_case_src(data)                                   ((0x3FC00000&(data))>>22)
#define DC_EC_ADDCMD_HI_get_trap_case(data)                                   ((0x3FC00000&(data))>>22)
#define DC_EC_ADDCMD_HI_Addcmd_hi_shift                                       (0)
#define DC_EC_ADDCMD_HI_Addcmd_hi_mask                                        (0x003FFFFF)
#define DC_EC_ADDCMD_HI_Addcmd_hi(data)                                       (0x003FFFFF&((data)<<0))
#define DC_EC_ADDCMD_HI_Addcmd_hi_src(data)                                   ((0x003FFFFF&(data))>>0)
#define DC_EC_ADDCMD_HI_get_Addcmd_hi(data)                                   ((0x003FFFFF&(data))>>0)


#define DC_EC_ADDCMD_LO                                                       0x180072D8
#define DC_EC_ADDCMD_LO_reg_addr                                              "0xB80072D8"
#define DC_EC_ADDCMD_LO_reg                                                   0xB80072D8
#define set_DC_EC_ADDCMD_LO_reg(data)   (*((volatile unsigned int*) DC_EC_ADDCMD_LO_reg)=data)
#define get_DC_EC_ADDCMD_LO_reg   (*((volatile unsigned int*) DC_EC_ADDCMD_LO_reg))
#define DC_EC_ADDCMD_LO_inst_adr                                              "0x00B6"
#define DC_EC_ADDCMD_LO_inst                                                  0x00B6
#define DC_EC_ADDCMD_LO_Addcmd_lo_shift                                       (0)
#define DC_EC_ADDCMD_LO_Addcmd_lo_mask                                        (0xFFFFFFFF)
#define DC_EC_ADDCMD_LO_Addcmd_lo(data)                                       (0xFFFFFFFF&((data)<<0))
#define DC_EC_ADDCMD_LO_Addcmd_lo_src(data)                                   ((0xFFFFFFFF&(data))>>0)
#define DC_EC_ADDCMD_LO_get_Addcmd_lo(data)                                   ((0xFFFFFFFF&(data))>>0)


#define DC_RD_TAG_CHECK                                                       0x180072DC
#define DC_RD_TAG_CHECK_reg_addr                                              "0xB80072DC"
#define DC_RD_TAG_CHECK_reg                                                   0xB80072DC
#define set_DC_RD_TAG_CHECK_reg(data)   (*((volatile unsigned int*) DC_RD_TAG_CHECK_reg)=data)
#define get_DC_RD_TAG_CHECK_reg   (*((volatile unsigned int*) DC_RD_TAG_CHECK_reg))
#define DC_RD_TAG_CHECK_inst_adr                                              "0x00B7"
#define DC_RD_TAG_CHECK_inst                                                  0x00B7
#define DC_RD_TAG_CHECK_write_enable1_shift                                   (1)
#define DC_RD_TAG_CHECK_write_enable1_mask                                    (0x00000002)
#define DC_RD_TAG_CHECK_write_enable1(data)                                   (0x00000002&((data)<<1))
#define DC_RD_TAG_CHECK_write_enable1_src(data)                               ((0x00000002&(data))>>1)
#define DC_RD_TAG_CHECK_get_write_enable1(data)                               ((0x00000002&(data))>>1)
#define DC_RD_TAG_CHECK_tag_check_en_shift                                    (0)
#define DC_RD_TAG_CHECK_tag_check_en_mask                                     (0x00000001)
#define DC_RD_TAG_CHECK_tag_check_en(data)                                    (0x00000001&((data)<<0))
#define DC_RD_TAG_CHECK_tag_check_en_src(data)                                ((0x00000001&(data))>>0)
#define DC_RD_TAG_CHECK_get_tag_check_en(data)                                ((0x00000001&(data))>>0)


#define DC_INT_ENABLE                                                         0x180072E8
#define DC_INT_ENABLE_reg_addr                                                "0xB80072E8"
#define DC_INT_ENABLE_reg                                                     0xB80072E8
#define set_DC_INT_ENABLE_reg(data)   (*((volatile unsigned int*) DC_INT_ENABLE_reg)=data)
#define get_DC_INT_ENABLE_reg   (*((volatile unsigned int*) DC_INT_ENABLE_reg))
#define DC_INT_ENABLE_inst_adr                                                "0x00BA"
#define DC_INT_ENABLE_inst                                                    0x00BA
#define DC_INT_ENABLE_pic_offset_x_odd_int_en_shift                           (24)
#define DC_INT_ENABLE_pic_offset_x_odd_int_en_mask                            (0x01000000)
#define DC_INT_ENABLE_pic_offset_x_odd_int_en(data)                           (0x01000000&((data)<<24))
#define DC_INT_ENABLE_pic_offset_x_odd_int_en_src(data)                       ((0x01000000&(data))>>24)
#define DC_INT_ENABLE_get_pic_offset_x_odd_int_en(data)                       ((0x01000000&(data))>>24)
#define DC_INT_ENABLE_rd_tag_mismatch_int_en_shift                            (23)
#define DC_INT_ENABLE_rd_tag_mismatch_int_en_mask                             (0x00800000)
#define DC_INT_ENABLE_rd_tag_mismatch_int_en(data)                            (0x00800000&((data)<<23))
#define DC_INT_ENABLE_rd_tag_mismatch_int_en_src(data)                        ((0x00800000&(data))>>23)
#define DC_INT_ENABLE_get_rd_tag_mismatch_int_en(data)                        ((0x00800000&(data))>>23)
#define DC_INT_ENABLE_err_seq_sa_odd_int_en_shift                             (22)
#define DC_INT_ENABLE_err_seq_sa_odd_int_en_mask                              (0x00400000)
#define DC_INT_ENABLE_err_seq_sa_odd_int_en(data)                             (0x00400000&((data)<<22))
#define DC_INT_ENABLE_err_seq_sa_odd_int_en_src(data)                         ((0x00400000&(data))>>22)
#define DC_INT_ENABLE_get_err_seq_sa_odd_int_en(data)                         ((0x00400000&(data))>>22)
#define DC_INT_ENABLE_err_seq_bl_zero_int_en_shift                            (21)
#define DC_INT_ENABLE_err_seq_bl_zero_int_en_mask                             (0x00200000)
#define DC_INT_ENABLE_err_seq_bl_zero_int_en(data)                            (0x00200000&((data)<<21))
#define DC_INT_ENABLE_err_seq_bl_zero_int_en_src(data)                        ((0x00200000&(data))>>21)
#define DC_INT_ENABLE_get_err_seq_bl_zero_int_en(data)                        ((0x00200000&(data))>>21)
#define DC_INT_ENABLE_err_seq_bl_odd_int_en_shift                             (20)
#define DC_INT_ENABLE_err_seq_bl_odd_int_en_mask                              (0x00100000)
#define DC_INT_ENABLE_err_seq_bl_odd_int_en(data)                             (0x00100000&((data)<<20))
#define DC_INT_ENABLE_err_seq_bl_odd_int_en_src(data)                         ((0x00100000&(data))>>20)
#define DC_INT_ENABLE_get_err_seq_bl_odd_int_en(data)                         ((0x00100000&(data))>>20)
#define DC_INT_ENABLE_err_blk_8x2_on_64_int_en_shift                          (19)
#define DC_INT_ENABLE_err_blk_8x2_on_64_int_en_mask                           (0x00080000)
#define DC_INT_ENABLE_err_blk_8x2_on_64_int_en(data)                          (0x00080000&((data)<<19))
#define DC_INT_ENABLE_err_blk_8x2_on_64_int_en_src(data)                      ((0x00080000&(data))>>19)
#define DC_INT_ENABLE_get_err_blk_8x2_on_64_int_en(data)                      ((0x00080000&(data))>>19)
#define DC_INT_ENABLE_err_blk_size_exceed_int_en_shift                        (18)
#define DC_INT_ENABLE_err_blk_size_exceed_int_en_mask                         (0x00040000)
#define DC_INT_ENABLE_err_blk_size_exceed_int_en(data)                        (0x00040000&((data)<<18))
#define DC_INT_ENABLE_err_blk_size_exceed_int_en_src(data)                    ((0x00040000&(data))>>18)
#define DC_INT_ENABLE_get_err_blk_size_exceed_int_en(data)                    ((0x00040000&(data))>>18)
#define DC_INT_ENABLE_err_blk_h_zero_int_en_shift                             (17)
#define DC_INT_ENABLE_err_blk_h_zero_int_en_mask                              (0x00020000)
#define DC_INT_ENABLE_err_blk_h_zero_int_en(data)                             (0x00020000&((data)<<17))
#define DC_INT_ENABLE_err_blk_h_zero_int_en_src(data)                         ((0x00020000&(data))>>17)
#define DC_INT_ENABLE_get_err_blk_h_zero_int_en(data)                         ((0x00020000&(data))>>17)
#define DC_INT_ENABLE_err_blk_w_zero_int_en_shift                             (16)
#define DC_INT_ENABLE_err_blk_w_zero_int_en_mask                              (0x00010000)
#define DC_INT_ENABLE_err_blk_w_zero_int_en(data)                             (0x00010000&((data)<<16))
#define DC_INT_ENABLE_err_blk_w_zero_int_en_src(data)                         ((0x00010000&(data))>>16)
#define DC_INT_ENABLE_get_err_blk_w_zero_int_en(data)                         ((0x00010000&(data))>>16)
#define DC_INT_ENABLE_mt_3_mod3_int_en_shift                                  (12)
#define DC_INT_ENABLE_mt_3_mod3_int_en_mask                                   (0x00001000)
#define DC_INT_ENABLE_mt_3_mod3_int_en(data)                                  (0x00001000&((data)<<12))
#define DC_INT_ENABLE_mt_3_mod3_int_en_src(data)                              ((0x00001000&(data))>>12)
#define DC_INT_ENABLE_get_mt_3_mod3_int_en(data)                              ((0x00001000&(data))>>12)
#define DC_INT_ENABLE_mt_3_mod2_int_en_shift                                  (11)
#define DC_INT_ENABLE_mt_3_mod2_int_en_mask                                   (0x00000800)
#define DC_INT_ENABLE_mt_3_mod2_int_en(data)                                  (0x00000800&((data)<<11))
#define DC_INT_ENABLE_mt_3_mod2_int_en_src(data)                              ((0x00000800&(data))>>11)
#define DC_INT_ENABLE_get_mt_3_mod2_int_en(data)                              ((0x00000800&(data))>>11)
#define DC_INT_ENABLE_mt_3_mod1_int_en_shift                                  (10)
#define DC_INT_ENABLE_mt_3_mod1_int_en_mask                                   (0x00000400)
#define DC_INT_ENABLE_mt_3_mod1_int_en(data)                                  (0x00000400&((data)<<10))
#define DC_INT_ENABLE_mt_3_mod1_int_en_src(data)                              ((0x00000400&(data))>>10)
#define DC_INT_ENABLE_get_mt_3_mod1_int_en(data)                              ((0x00000400&(data))>>10)
#define DC_INT_ENABLE_mt_2_mod3_int_en_shift                                  (9)
#define DC_INT_ENABLE_mt_2_mod3_int_en_mask                                   (0x00000200)
#define DC_INT_ENABLE_mt_2_mod3_int_en(data)                                  (0x00000200&((data)<<9))
#define DC_INT_ENABLE_mt_2_mod3_int_en_src(data)                              ((0x00000200&(data))>>9)
#define DC_INT_ENABLE_get_mt_2_mod3_int_en(data)                              ((0x00000200&(data))>>9)
#define DC_INT_ENABLE_mt_2_mod2_int_en_shift                                  (8)
#define DC_INT_ENABLE_mt_2_mod2_int_en_mask                                   (0x00000100)
#define DC_INT_ENABLE_mt_2_mod2_int_en(data)                                  (0x00000100&((data)<<8))
#define DC_INT_ENABLE_mt_2_mod2_int_en_src(data)                              ((0x00000100&(data))>>8)
#define DC_INT_ENABLE_get_mt_2_mod2_int_en(data)                              ((0x00000100&(data))>>8)
#define DC_INT_ENABLE_mt_2_mod1_int_en_shift                                  (7)
#define DC_INT_ENABLE_mt_2_mod1_int_en_mask                                   (0x00000080)
#define DC_INT_ENABLE_mt_2_mod1_int_en(data)                                  (0x00000080&((data)<<7))
#define DC_INT_ENABLE_mt_2_mod1_int_en_src(data)                              ((0x00000080&(data))>>7)
#define DC_INT_ENABLE_get_mt_2_mod1_int_en(data)                              ((0x00000080&(data))>>7)
#define DC_INT_ENABLE_mt_1_mod3_int_en_shift                                  (6)
#define DC_INT_ENABLE_mt_1_mod3_int_en_mask                                   (0x00000040)
#define DC_INT_ENABLE_mt_1_mod3_int_en(data)                                  (0x00000040&((data)<<6))
#define DC_INT_ENABLE_mt_1_mod3_int_en_src(data)                              ((0x00000040&(data))>>6)
#define DC_INT_ENABLE_get_mt_1_mod3_int_en(data)                              ((0x00000040&(data))>>6)
#define DC_INT_ENABLE_mt_1_mod2_int_en_shift                                  (5)
#define DC_INT_ENABLE_mt_1_mod2_int_en_mask                                   (0x00000020)
#define DC_INT_ENABLE_mt_1_mod2_int_en(data)                                  (0x00000020&((data)<<5))
#define DC_INT_ENABLE_mt_1_mod2_int_en_src(data)                              ((0x00000020&(data))>>5)
#define DC_INT_ENABLE_get_mt_1_mod2_int_en(data)                              ((0x00000020&(data))>>5)
#define DC_INT_ENABLE_mt_1_mod1_int_en_shift                                  (4)
#define DC_INT_ENABLE_mt_1_mod1_int_en_mask                                   (0x00000010)
#define DC_INT_ENABLE_mt_1_mod1_int_en(data)                                  (0x00000010&((data)<<4))
#define DC_INT_ENABLE_mt_1_mod1_int_en_src(data)                              ((0x00000010&(data))>>4)
#define DC_INT_ENABLE_get_mt_1_mod1_int_en(data)                              ((0x00000010&(data))>>4)
#define DC_INT_ENABLE_mt_0_mod3_int_en_shift                                  (3)
#define DC_INT_ENABLE_mt_0_mod3_int_en_mask                                   (0x00000008)
#define DC_INT_ENABLE_mt_0_mod3_int_en(data)                                  (0x00000008&((data)<<3))
#define DC_INT_ENABLE_mt_0_mod3_int_en_src(data)                              ((0x00000008&(data))>>3)
#define DC_INT_ENABLE_get_mt_0_mod3_int_en(data)                              ((0x00000008&(data))>>3)
#define DC_INT_ENABLE_mt_0_mod2_int_en_shift                                  (2)
#define DC_INT_ENABLE_mt_0_mod2_int_en_mask                                   (0x00000004)
#define DC_INT_ENABLE_mt_0_mod2_int_en(data)                                  (0x00000004&((data)<<2))
#define DC_INT_ENABLE_mt_0_mod2_int_en_src(data)                              ((0x00000004&(data))>>2)
#define DC_INT_ENABLE_get_mt_0_mod2_int_en(data)                              ((0x00000004&(data))>>2)
#define DC_INT_ENABLE_mt_0_mod1_int_en_shift                                  (1)
#define DC_INT_ENABLE_mt_0_mod1_int_en_mask                                   (0x00000002)
#define DC_INT_ENABLE_mt_0_mod1_int_en(data)                                  (0x00000002&((data)<<1))
#define DC_INT_ENABLE_mt_0_mod1_int_en_src(data)                              ((0x00000002&(data))>>1)
#define DC_INT_ENABLE_get_mt_0_mod1_int_en(data)                              ((0x00000002&(data))>>1)
#define DC_INT_ENABLE_write_data_shift                                        (0)
#define DC_INT_ENABLE_write_data_mask                                         (0x00000001)
#define DC_INT_ENABLE_write_data(data)                                        (0x00000001&((data)<<0))
#define DC_INT_ENABLE_write_data_src(data)                                    ((0x00000001&(data))>>0)
#define DC_INT_ENABLE_get_write_data(data)                                    ((0x00000001&(data))>>0)


#define DC_INT_STATUS                                                         0x180072EC
#define DC_INT_STATUS_reg_addr                                                "0xB80072EC"
#define DC_INT_STATUS_reg                                                     0xB80072EC
#define set_DC_INT_STATUS_reg(data)   (*((volatile unsigned int*) DC_INT_STATUS_reg)=data)
#define get_DC_INT_STATUS_reg   (*((volatile unsigned int*) DC_INT_STATUS_reg))
#define DC_INT_STATUS_inst_adr                                                "0x00BB"
#define DC_INT_STATUS_inst                                                    0x00BB
#define DC_INT_STATUS_pic_offset_x_odd_int_shift                              (24)
#define DC_INT_STATUS_pic_offset_x_odd_int_mask                               (0x01000000)
#define DC_INT_STATUS_pic_offset_x_odd_int(data)                              (0x01000000&((data)<<24))
#define DC_INT_STATUS_pic_offset_x_odd_int_src(data)                          ((0x01000000&(data))>>24)
#define DC_INT_STATUS_get_pic_offset_x_odd_int(data)                          ((0x01000000&(data))>>24)
#define DC_INT_STATUS_rd_tag_mismatch_int_shift                               (23)
#define DC_INT_STATUS_rd_tag_mismatch_int_mask                                (0x00800000)
#define DC_INT_STATUS_rd_tag_mismatch_int(data)                               (0x00800000&((data)<<23))
#define DC_INT_STATUS_rd_tag_mismatch_int_src(data)                           ((0x00800000&(data))>>23)
#define DC_INT_STATUS_get_rd_tag_mismatch_int(data)                           ((0x00800000&(data))>>23)
#define DC_INT_STATUS_err_seq_sa_odd_int_shift                                (22)
#define DC_INT_STATUS_err_seq_sa_odd_int_mask                                 (0x00400000)
#define DC_INT_STATUS_err_seq_sa_odd_int(data)                                (0x00400000&((data)<<22))
#define DC_INT_STATUS_err_seq_sa_odd_int_src(data)                            ((0x00400000&(data))>>22)
#define DC_INT_STATUS_get_err_seq_sa_odd_int(data)                            ((0x00400000&(data))>>22)
#define DC_INT_STATUS_err_seq_bl_zero_int_shift                               (21)
#define DC_INT_STATUS_err_seq_bl_zero_int_mask                                (0x00200000)
#define DC_INT_STATUS_err_seq_bl_zero_int(data)                               (0x00200000&((data)<<21))
#define DC_INT_STATUS_err_seq_bl_zero_int_src(data)                           ((0x00200000&(data))>>21)
#define DC_INT_STATUS_get_err_seq_bl_zero_int(data)                           ((0x00200000&(data))>>21)
#define DC_INT_STATUS_err_seq_bl_odd_int_shift                                (20)
#define DC_INT_STATUS_err_seq_bl_odd_int_mask                                 (0x00100000)
#define DC_INT_STATUS_err_seq_bl_odd_int(data)                                (0x00100000&((data)<<20))
#define DC_INT_STATUS_err_seq_bl_odd_int_src(data)                            ((0x00100000&(data))>>20)
#define DC_INT_STATUS_get_err_seq_bl_odd_int(data)                            ((0x00100000&(data))>>20)
#define DC_INT_STATUS_err_blk_8x2_on_64_int_shift                             (19)
#define DC_INT_STATUS_err_blk_8x2_on_64_int_mask                              (0x00080000)
#define DC_INT_STATUS_err_blk_8x2_on_64_int(data)                             (0x00080000&((data)<<19))
#define DC_INT_STATUS_err_blk_8x2_on_64_int_src(data)                         ((0x00080000&(data))>>19)
#define DC_INT_STATUS_get_err_blk_8x2_on_64_int(data)                         ((0x00080000&(data))>>19)
#define DC_INT_STATUS_err_blk_size_exceed_int_shift                           (18)
#define DC_INT_STATUS_err_blk_size_exceed_int_mask                            (0x00040000)
#define DC_INT_STATUS_err_blk_size_exceed_int(data)                           (0x00040000&((data)<<18))
#define DC_INT_STATUS_err_blk_size_exceed_int_src(data)                       ((0x00040000&(data))>>18)
#define DC_INT_STATUS_get_err_blk_size_exceed_int(data)                       ((0x00040000&(data))>>18)
#define DC_INT_STATUS_err_blk_h_zero_int_shift                                (17)
#define DC_INT_STATUS_err_blk_h_zero_int_mask                                 (0x00020000)
#define DC_INT_STATUS_err_blk_h_zero_int(data)                                (0x00020000&((data)<<17))
#define DC_INT_STATUS_err_blk_h_zero_int_src(data)                            ((0x00020000&(data))>>17)
#define DC_INT_STATUS_get_err_blk_h_zero_int(data)                            ((0x00020000&(data))>>17)
#define DC_INT_STATUS_err_blk_w_zero_int_shift                                (16)
#define DC_INT_STATUS_err_blk_w_zero_int_mask                                 (0x00010000)
#define DC_INT_STATUS_err_blk_w_zero_int(data)                                (0x00010000&((data)<<16))
#define DC_INT_STATUS_err_blk_w_zero_int_src(data)                            ((0x00010000&(data))>>16)
#define DC_INT_STATUS_get_err_blk_w_zero_int(data)                            ((0x00010000&(data))>>16)
#define DC_INT_STATUS_mt_3_mod3_int_shift                                     (12)
#define DC_INT_STATUS_mt_3_mod3_int_mask                                      (0x00001000)
#define DC_INT_STATUS_mt_3_mod3_int(data)                                     (0x00001000&((data)<<12))
#define DC_INT_STATUS_mt_3_mod3_int_src(data)                                 ((0x00001000&(data))>>12)
#define DC_INT_STATUS_get_mt_3_mod3_int(data)                                 ((0x00001000&(data))>>12)
#define DC_INT_STATUS_mt_3_mod2_int_shift                                     (11)
#define DC_INT_STATUS_mt_3_mod2_int_mask                                      (0x00000800)
#define DC_INT_STATUS_mt_3_mod2_int(data)                                     (0x00000800&((data)<<11))
#define DC_INT_STATUS_mt_3_mod2_int_src(data)                                 ((0x00000800&(data))>>11)
#define DC_INT_STATUS_get_mt_3_mod2_int(data)                                 ((0x00000800&(data))>>11)
#define DC_INT_STATUS_mt_3_mod1_int_shift                                     (10)
#define DC_INT_STATUS_mt_3_mod1_int_mask                                      (0x00000400)
#define DC_INT_STATUS_mt_3_mod1_int(data)                                     (0x00000400&((data)<<10))
#define DC_INT_STATUS_mt_3_mod1_int_src(data)                                 ((0x00000400&(data))>>10)
#define DC_INT_STATUS_get_mt_3_mod1_int(data)                                 ((0x00000400&(data))>>10)
#define DC_INT_STATUS_mt_2_mod3_int_shift                                     (9)
#define DC_INT_STATUS_mt_2_mod3_int_mask                                      (0x00000200)
#define DC_INT_STATUS_mt_2_mod3_int(data)                                     (0x00000200&((data)<<9))
#define DC_INT_STATUS_mt_2_mod3_int_src(data)                                 ((0x00000200&(data))>>9)
#define DC_INT_STATUS_get_mt_2_mod3_int(data)                                 ((0x00000200&(data))>>9)
#define DC_INT_STATUS_mt_2_mod2_int_shift                                     (8)
#define DC_INT_STATUS_mt_2_mod2_int_mask                                      (0x00000100)
#define DC_INT_STATUS_mt_2_mod2_int(data)                                     (0x00000100&((data)<<8))
#define DC_INT_STATUS_mt_2_mod2_int_src(data)                                 ((0x00000100&(data))>>8)
#define DC_INT_STATUS_get_mt_2_mod2_int(data)                                 ((0x00000100&(data))>>8)
#define DC_INT_STATUS_mt_2_mod1_int_shift                                     (7)
#define DC_INT_STATUS_mt_2_mod1_int_mask                                      (0x00000080)
#define DC_INT_STATUS_mt_2_mod1_int(data)                                     (0x00000080&((data)<<7))
#define DC_INT_STATUS_mt_2_mod1_int_src(data)                                 ((0x00000080&(data))>>7)
#define DC_INT_STATUS_get_mt_2_mod1_int(data)                                 ((0x00000080&(data))>>7)
#define DC_INT_STATUS_mt_1_mod3_int_shift                                     (6)
#define DC_INT_STATUS_mt_1_mod3_int_mask                                      (0x00000040)
#define DC_INT_STATUS_mt_1_mod3_int(data)                                     (0x00000040&((data)<<6))
#define DC_INT_STATUS_mt_1_mod3_int_src(data)                                 ((0x00000040&(data))>>6)
#define DC_INT_STATUS_get_mt_1_mod3_int(data)                                 ((0x00000040&(data))>>6)
#define DC_INT_STATUS_mt_1_mod2_int_shift                                     (5)
#define DC_INT_STATUS_mt_1_mod2_int_mask                                      (0x00000020)
#define DC_INT_STATUS_mt_1_mod2_int(data)                                     (0x00000020&((data)<<5))
#define DC_INT_STATUS_mt_1_mod2_int_src(data)                                 ((0x00000020&(data))>>5)
#define DC_INT_STATUS_get_mt_1_mod2_int(data)                                 ((0x00000020&(data))>>5)
#define DC_INT_STATUS_mt_1_mod1_int_shift                                     (4)
#define DC_INT_STATUS_mt_1_mod1_int_mask                                      (0x00000010)
#define DC_INT_STATUS_mt_1_mod1_int(data)                                     (0x00000010&((data)<<4))
#define DC_INT_STATUS_mt_1_mod1_int_src(data)                                 ((0x00000010&(data))>>4)
#define DC_INT_STATUS_get_mt_1_mod1_int(data)                                 ((0x00000010&(data))>>4)
#define DC_INT_STATUS_mt_0_mod3_int_shift                                     (3)
#define DC_INT_STATUS_mt_0_mod3_int_mask                                      (0x00000008)
#define DC_INT_STATUS_mt_0_mod3_int(data)                                     (0x00000008&((data)<<3))
#define DC_INT_STATUS_mt_0_mod3_int_src(data)                                 ((0x00000008&(data))>>3)
#define DC_INT_STATUS_get_mt_0_mod3_int(data)                                 ((0x00000008&(data))>>3)
#define DC_INT_STATUS_mt_0_mod2_int_shift                                     (2)
#define DC_INT_STATUS_mt_0_mod2_int_mask                                      (0x00000004)
#define DC_INT_STATUS_mt_0_mod2_int(data)                                     (0x00000004&((data)<<2))
#define DC_INT_STATUS_mt_0_mod2_int_src(data)                                 ((0x00000004&(data))>>2)
#define DC_INT_STATUS_get_mt_0_mod2_int(data)                                 ((0x00000004&(data))>>2)
#define DC_INT_STATUS_mt_0_mod1_int_shift                                     (1)
#define DC_INT_STATUS_mt_0_mod1_int_mask                                      (0x00000002)
#define DC_INT_STATUS_mt_0_mod1_int(data)                                     (0x00000002&((data)<<1))
#define DC_INT_STATUS_mt_0_mod1_int_src(data)                                 ((0x00000002&(data))>>1)
#define DC_INT_STATUS_get_mt_0_mod1_int(data)                                 ((0x00000002&(data))>>1)
#define DC_INT_STATUS_write_data_shift                                        (0)
#define DC_INT_STATUS_write_data_mask                                         (0x00000001)
#define DC_INT_STATUS_write_data(data)                                        (0x00000001&((data)<<0))
#define DC_INT_STATUS_write_data_src(data)                                    ((0x00000001&(data))>>0)
#define DC_INT_STATUS_get_write_data(data)                                    ((0x00000001&(data))>>0)


#define BW_CTRL                                                               0x18007300
#define BW_CTRL_reg_addr                                                      "0xB8007300"
#define BW_CTRL_reg                                                           0xB8007300
#define set_BW_CTRL_reg(data)   (*((volatile unsigned int*) BW_CTRL_reg)=data)
#define get_BW_CTRL_reg   (*((volatile unsigned int*) BW_CTRL_reg))
#define BW_CTRL_inst_adr                                                      "0x00C0"
#define BW_CTRL_inst                                                          0x00C0
#define BW_CTRL_bw_en_shift                                                   (0)
#define BW_CTRL_bw_en_mask                                                    (0x00000FFF)
#define BW_CTRL_bw_en(data)                                                   (0x00000FFF&((data)<<0))
#define BW_CTRL_bw_en_src(data)                                               ((0x00000FFF&(data))>>0)
#define BW_CTRL_get_bw_en(data)                                               ((0x00000FFF&(data))>>0)


#define BW_TIMER_THRESHOLD_0                                                  0x18007304
#define BW_TIMER_THRESHOLD_1                                                  0x18007308
#define BW_TIMER_THRESHOLD_2                                                  0x1800730C
#define BW_TIMER_THRESHOLD_3                                                  0x18007310
#define BW_TIMER_THRESHOLD_4                                                  0x18007314
#define BW_TIMER_THRESHOLD_5                                                  0x18007318
#define BW_TIMER_THRESHOLD_6                                                  0x1800731C
#define BW_TIMER_THRESHOLD_7                                                  0x18007320
#define BW_TIMER_THRESHOLD_8                                                  0x18007324
#define BW_TIMER_THRESHOLD_9                                                  0x18007328
#define BW_TIMER_THRESHOLD_10                                                  0x1800732C
#define BW_TIMER_THRESHOLD_11                                                  0x18007330
#define BW_TIMER_THRESHOLD_0_reg_addr                                         "0xB8007304"
#define BW_TIMER_THRESHOLD_1_reg_addr                                         "0xB8007308"
#define BW_TIMER_THRESHOLD_2_reg_addr                                         "0xB800730C"
#define BW_TIMER_THRESHOLD_3_reg_addr                                         "0xB8007310"
#define BW_TIMER_THRESHOLD_4_reg_addr                                         "0xB8007314"
#define BW_TIMER_THRESHOLD_5_reg_addr                                         "0xB8007318"
#define BW_TIMER_THRESHOLD_6_reg_addr                                         "0xB800731C"
#define BW_TIMER_THRESHOLD_7_reg_addr                                         "0xB8007320"
#define BW_TIMER_THRESHOLD_8_reg_addr                                         "0xB8007324"
#define BW_TIMER_THRESHOLD_9_reg_addr                                         "0xB8007328"
#define BW_TIMER_THRESHOLD_10_reg_addr                                         "0xB800732C"
#define BW_TIMER_THRESHOLD_11_reg_addr                                         "0xB8007330"
#define BW_TIMER_THRESHOLD_0_reg                                              0xB8007304
#define BW_TIMER_THRESHOLD_1_reg                                              0xB8007308
#define BW_TIMER_THRESHOLD_2_reg                                              0xB800730C
#define BW_TIMER_THRESHOLD_3_reg                                              0xB8007310
#define BW_TIMER_THRESHOLD_4_reg                                              0xB8007314
#define BW_TIMER_THRESHOLD_5_reg                                              0xB8007318
#define BW_TIMER_THRESHOLD_6_reg                                              0xB800731C
#define BW_TIMER_THRESHOLD_7_reg                                              0xB8007320
#define BW_TIMER_THRESHOLD_8_reg                                              0xB8007324
#define BW_TIMER_THRESHOLD_9_reg                                              0xB8007328
#define BW_TIMER_THRESHOLD_10_reg                                              0xB800732C
#define BW_TIMER_THRESHOLD_11_reg                                              0xB8007330
#define set_BW_TIMER_THRESHOLD_0_reg(data)   (*((volatile unsigned int*) BW_TIMER_THRESHOLD_0_reg)=data)
#define set_BW_TIMER_THRESHOLD_1_reg(data)   (*((volatile unsigned int*) BW_TIMER_THRESHOLD_1_reg)=data)
#define set_BW_TIMER_THRESHOLD_2_reg(data)   (*((volatile unsigned int*) BW_TIMER_THRESHOLD_2_reg)=data)
#define set_BW_TIMER_THRESHOLD_3_reg(data)   (*((volatile unsigned int*) BW_TIMER_THRESHOLD_3_reg)=data)
#define set_BW_TIMER_THRESHOLD_4_reg(data)   (*((volatile unsigned int*) BW_TIMER_THRESHOLD_4_reg)=data)
#define set_BW_TIMER_THRESHOLD_5_reg(data)   (*((volatile unsigned int*) BW_TIMER_THRESHOLD_5_reg)=data)
#define set_BW_TIMER_THRESHOLD_6_reg(data)   (*((volatile unsigned int*) BW_TIMER_THRESHOLD_6_reg)=data)
#define set_BW_TIMER_THRESHOLD_7_reg(data)   (*((volatile unsigned int*) BW_TIMER_THRESHOLD_7_reg)=data)
#define set_BW_TIMER_THRESHOLD_8_reg(data)   (*((volatile unsigned int*) BW_TIMER_THRESHOLD_8_reg)=data)
#define set_BW_TIMER_THRESHOLD_9_reg(data)   (*((volatile unsigned int*) BW_TIMER_THRESHOLD_9_reg)=data)
#define set_BW_TIMER_THRESHOLD_10_reg(data)   (*((volatile unsigned int*) BW_TIMER_THRESHOLD_10_reg)=data)
#define set_BW_TIMER_THRESHOLD_11_reg(data)   (*((volatile unsigned int*) BW_TIMER_THRESHOLD_11_reg)=data)
#define get_BW_TIMER_THRESHOLD_0_reg   (*((volatile unsigned int*) BW_TIMER_THRESHOLD_0_reg))
#define get_BW_TIMER_THRESHOLD_1_reg   (*((volatile unsigned int*) BW_TIMER_THRESHOLD_1_reg))
#define get_BW_TIMER_THRESHOLD_2_reg   (*((volatile unsigned int*) BW_TIMER_THRESHOLD_2_reg))
#define get_BW_TIMER_THRESHOLD_3_reg   (*((volatile unsigned int*) BW_TIMER_THRESHOLD_3_reg))
#define get_BW_TIMER_THRESHOLD_4_reg   (*((volatile unsigned int*) BW_TIMER_THRESHOLD_4_reg))
#define get_BW_TIMER_THRESHOLD_5_reg   (*((volatile unsigned int*) BW_TIMER_THRESHOLD_5_reg))
#define get_BW_TIMER_THRESHOLD_6_reg   (*((volatile unsigned int*) BW_TIMER_THRESHOLD_6_reg))
#define get_BW_TIMER_THRESHOLD_7_reg   (*((volatile unsigned int*) BW_TIMER_THRESHOLD_7_reg))
#define get_BW_TIMER_THRESHOLD_8_reg   (*((volatile unsigned int*) BW_TIMER_THRESHOLD_8_reg))
#define get_BW_TIMER_THRESHOLD_9_reg   (*((volatile unsigned int*) BW_TIMER_THRESHOLD_9_reg))
#define get_BW_TIMER_THRESHOLD_10_reg   (*((volatile unsigned int*) BW_TIMER_THRESHOLD_10_reg))
#define get_BW_TIMER_THRESHOLD_11_reg   (*((volatile unsigned int*) BW_TIMER_THRESHOLD_11_reg))
#define BW_TIMER_THRESHOLD_0_inst_adr                                         "0x00C1"
#define BW_TIMER_THRESHOLD_1_inst_adr                                         "0x00C2"
#define BW_TIMER_THRESHOLD_2_inst_adr                                         "0x00C3"
#define BW_TIMER_THRESHOLD_3_inst_adr                                         "0x00C4"
#define BW_TIMER_THRESHOLD_4_inst_adr                                         "0x00C5"
#define BW_TIMER_THRESHOLD_5_inst_adr                                         "0x00C6"
#define BW_TIMER_THRESHOLD_6_inst_adr                                         "0x00C7"
#define BW_TIMER_THRESHOLD_7_inst_adr                                         "0x00C8"
#define BW_TIMER_THRESHOLD_8_inst_adr                                         "0x00C9"
#define BW_TIMER_THRESHOLD_9_inst_adr                                         "0x00CA"
#define BW_TIMER_THRESHOLD_10_inst_adr                                         "0x00CB"
#define BW_TIMER_THRESHOLD_11_inst_adr                                         "0x00CC"
#define BW_TIMER_THRESHOLD_0_inst                                             0x00C1
#define BW_TIMER_THRESHOLD_1_inst                                             0x00C2
#define BW_TIMER_THRESHOLD_2_inst                                             0x00C3
#define BW_TIMER_THRESHOLD_3_inst                                             0x00C4
#define BW_TIMER_THRESHOLD_4_inst                                             0x00C5
#define BW_TIMER_THRESHOLD_5_inst                                             0x00C6
#define BW_TIMER_THRESHOLD_6_inst                                             0x00C7
#define BW_TIMER_THRESHOLD_7_inst                                             0x00C8
#define BW_TIMER_THRESHOLD_8_inst                                             0x00C9
#define BW_TIMER_THRESHOLD_9_inst                                             0x00CA
#define BW_TIMER_THRESHOLD_10_inst                                             0x00CB
#define BW_TIMER_THRESHOLD_11_inst                                             0x00CC
#define BW_TIMER_THRESHOLD_value_shift                                        (0)
#define BW_TIMER_THRESHOLD_value_mask                                         (0xFFFFFFFF)
#define BW_TIMER_THRESHOLD_value(data)                                        (0xFFFFFFFF&((data)<<0))
#define BW_TIMER_THRESHOLD_value_src(data)                                    ((0xFFFFFFFF&(data))>>0)
#define BW_TIMER_THRESHOLD_get_value(data)                                    ((0xFFFFFFFF&(data))>>0)


#define BW_REQUEST_THRESHOLD_0                                                0x18007334
#define BW_REQUEST_THRESHOLD_1                                                0x18007338
#define BW_REQUEST_THRESHOLD_2                                                0x1800733C
#define BW_REQUEST_THRESHOLD_3                                                0x18007340
#define BW_REQUEST_THRESHOLD_4                                                0x18007344
#define BW_REQUEST_THRESHOLD_5                                                0x18007348
#define BW_REQUEST_THRESHOLD_6                                                0x1800734C
#define BW_REQUEST_THRESHOLD_7                                                0x18007350
#define BW_REQUEST_THRESHOLD_8                                                0x18007354
#define BW_REQUEST_THRESHOLD_9                                                0x18007358
#define BW_REQUEST_THRESHOLD_10                                                0x1800735C
#define BW_REQUEST_THRESHOLD_11                                                0x18007360
#define BW_REQUEST_THRESHOLD_0_reg_addr                                       "0xB8007334"
#define BW_REQUEST_THRESHOLD_1_reg_addr                                       "0xB8007338"
#define BW_REQUEST_THRESHOLD_2_reg_addr                                       "0xB800733C"
#define BW_REQUEST_THRESHOLD_3_reg_addr                                       "0xB8007340"
#define BW_REQUEST_THRESHOLD_4_reg_addr                                       "0xB8007344"
#define BW_REQUEST_THRESHOLD_5_reg_addr                                       "0xB8007348"
#define BW_REQUEST_THRESHOLD_6_reg_addr                                       "0xB800734C"
#define BW_REQUEST_THRESHOLD_7_reg_addr                                       "0xB8007350"
#define BW_REQUEST_THRESHOLD_8_reg_addr                                       "0xB8007354"
#define BW_REQUEST_THRESHOLD_9_reg_addr                                       "0xB8007358"
#define BW_REQUEST_THRESHOLD_10_reg_addr                                       "0xB800735C"
#define BW_REQUEST_THRESHOLD_11_reg_addr                                       "0xB8007360"
#define BW_REQUEST_THRESHOLD_0_reg                                            0xB8007334
#define BW_REQUEST_THRESHOLD_1_reg                                            0xB8007338
#define BW_REQUEST_THRESHOLD_2_reg                                            0xB800733C
#define BW_REQUEST_THRESHOLD_3_reg                                            0xB8007340
#define BW_REQUEST_THRESHOLD_4_reg                                            0xB8007344
#define BW_REQUEST_THRESHOLD_5_reg                                            0xB8007348
#define BW_REQUEST_THRESHOLD_6_reg                                            0xB800734C
#define BW_REQUEST_THRESHOLD_7_reg                                            0xB8007350
#define BW_REQUEST_THRESHOLD_8_reg                                            0xB8007354
#define BW_REQUEST_THRESHOLD_9_reg                                            0xB8007358
#define BW_REQUEST_THRESHOLD_10_reg                                            0xB800735C
#define BW_REQUEST_THRESHOLD_11_reg                                            0xB8007360
#define set_BW_REQUEST_THRESHOLD_0_reg(data)   (*((volatile unsigned int*) BW_REQUEST_THRESHOLD_0_reg)=data)
#define set_BW_REQUEST_THRESHOLD_1_reg(data)   (*((volatile unsigned int*) BW_REQUEST_THRESHOLD_1_reg)=data)
#define set_BW_REQUEST_THRESHOLD_2_reg(data)   (*((volatile unsigned int*) BW_REQUEST_THRESHOLD_2_reg)=data)
#define set_BW_REQUEST_THRESHOLD_3_reg(data)   (*((volatile unsigned int*) BW_REQUEST_THRESHOLD_3_reg)=data)
#define set_BW_REQUEST_THRESHOLD_4_reg(data)   (*((volatile unsigned int*) BW_REQUEST_THRESHOLD_4_reg)=data)
#define set_BW_REQUEST_THRESHOLD_5_reg(data)   (*((volatile unsigned int*) BW_REQUEST_THRESHOLD_5_reg)=data)
#define set_BW_REQUEST_THRESHOLD_6_reg(data)   (*((volatile unsigned int*) BW_REQUEST_THRESHOLD_6_reg)=data)
#define set_BW_REQUEST_THRESHOLD_7_reg(data)   (*((volatile unsigned int*) BW_REQUEST_THRESHOLD_7_reg)=data)
#define set_BW_REQUEST_THRESHOLD_8_reg(data)   (*((volatile unsigned int*) BW_REQUEST_THRESHOLD_8_reg)=data)
#define set_BW_REQUEST_THRESHOLD_9_reg(data)   (*((volatile unsigned int*) BW_REQUEST_THRESHOLD_9_reg)=data)
#define set_BW_REQUEST_THRESHOLD_10_reg(data)   (*((volatile unsigned int*) BW_REQUEST_THRESHOLD_10_reg)=data)
#define set_BW_REQUEST_THRESHOLD_11_reg(data)   (*((volatile unsigned int*) BW_REQUEST_THRESHOLD_11_reg)=data)
#define get_BW_REQUEST_THRESHOLD_0_reg   (*((volatile unsigned int*) BW_REQUEST_THRESHOLD_0_reg))
#define get_BW_REQUEST_THRESHOLD_1_reg   (*((volatile unsigned int*) BW_REQUEST_THRESHOLD_1_reg))
#define get_BW_REQUEST_THRESHOLD_2_reg   (*((volatile unsigned int*) BW_REQUEST_THRESHOLD_2_reg))
#define get_BW_REQUEST_THRESHOLD_3_reg   (*((volatile unsigned int*) BW_REQUEST_THRESHOLD_3_reg))
#define get_BW_REQUEST_THRESHOLD_4_reg   (*((volatile unsigned int*) BW_REQUEST_THRESHOLD_4_reg))
#define get_BW_REQUEST_THRESHOLD_5_reg   (*((volatile unsigned int*) BW_REQUEST_THRESHOLD_5_reg))
#define get_BW_REQUEST_THRESHOLD_6_reg   (*((volatile unsigned int*) BW_REQUEST_THRESHOLD_6_reg))
#define get_BW_REQUEST_THRESHOLD_7_reg   (*((volatile unsigned int*) BW_REQUEST_THRESHOLD_7_reg))
#define get_BW_REQUEST_THRESHOLD_8_reg   (*((volatile unsigned int*) BW_REQUEST_THRESHOLD_8_reg))
#define get_BW_REQUEST_THRESHOLD_9_reg   (*((volatile unsigned int*) BW_REQUEST_THRESHOLD_9_reg))
#define get_BW_REQUEST_THRESHOLD_10_reg   (*((volatile unsigned int*) BW_REQUEST_THRESHOLD_10_reg))
#define get_BW_REQUEST_THRESHOLD_11_reg   (*((volatile unsigned int*) BW_REQUEST_THRESHOLD_11_reg))
#define BW_REQUEST_THRESHOLD_0_inst_adr                                       "0x00CD"
#define BW_REQUEST_THRESHOLD_1_inst_adr                                       "0x00CE"
#define BW_REQUEST_THRESHOLD_2_inst_adr                                       "0x00CF"
#define BW_REQUEST_THRESHOLD_3_inst_adr                                       "0x00D0"
#define BW_REQUEST_THRESHOLD_4_inst_adr                                       "0x00D1"
#define BW_REQUEST_THRESHOLD_5_inst_adr                                       "0x00D2"
#define BW_REQUEST_THRESHOLD_6_inst_adr                                       "0x00D3"
#define BW_REQUEST_THRESHOLD_7_inst_adr                                       "0x00D4"
#define BW_REQUEST_THRESHOLD_8_inst_adr                                       "0x00D5"
#define BW_REQUEST_THRESHOLD_9_inst_adr                                       "0x00D6"
#define BW_REQUEST_THRESHOLD_10_inst_adr                                       "0x00D7"
#define BW_REQUEST_THRESHOLD_11_inst_adr                                       "0x00D8"
#define BW_REQUEST_THRESHOLD_0_inst                                           0x00CD
#define BW_REQUEST_THRESHOLD_1_inst                                           0x00CE
#define BW_REQUEST_THRESHOLD_2_inst                                           0x00CF
#define BW_REQUEST_THRESHOLD_3_inst                                           0x00D0
#define BW_REQUEST_THRESHOLD_4_inst                                           0x00D1
#define BW_REQUEST_THRESHOLD_5_inst                                           0x00D2
#define BW_REQUEST_THRESHOLD_6_inst                                           0x00D3
#define BW_REQUEST_THRESHOLD_7_inst                                           0x00D4
#define BW_REQUEST_THRESHOLD_8_inst                                           0x00D5
#define BW_REQUEST_THRESHOLD_9_inst                                           0x00D6
#define BW_REQUEST_THRESHOLD_10_inst                                           0x00D7
#define BW_REQUEST_THRESHOLD_11_inst                                           0x00D8
#define BW_REQUEST_THRESHOLD_value_shift                                      (0)
#define BW_REQUEST_THRESHOLD_value_mask                                       (0x00FFFFFF)
#define BW_REQUEST_THRESHOLD_value(data)                                      (0x00FFFFFF&((data)<<0))
#define BW_REQUEST_THRESHOLD_value_src(data)                                  ((0x00FFFFFF&(data))>>0)
#define BW_REQUEST_THRESHOLD_get_value(data)                                  ((0x00FFFFFF&(data))>>0)


#define DC_SYS2_MUX                                                           0x18007400
#define DC_SYS2_MUX_reg_addr                                                  "0xB8007400"
#define DC_SYS2_MUX_reg                                                       0xB8007400
#define set_DC_SYS2_MUX_reg(data)   (*((volatile unsigned int*) DC_SYS2_MUX_reg)=data)
#define get_DC_SYS2_MUX_reg   (*((volatile unsigned int*) DC_SYS2_MUX_reg))
#define DC_SYS2_MUX_inst_adr                                                  "0x0000"
#define DC_SYS2_MUX_inst                                                      0x0000
#define DC_SYS2_MUX_pre_tra_rd_cnt_shift                                      (20)
#define DC_SYS2_MUX_pre_tra_rd_cnt_mask                                       (0x3FF00000)
#define DC_SYS2_MUX_pre_tra_rd_cnt(data)                                      (0x3FF00000&((data)<<20))
#define DC_SYS2_MUX_pre_tra_rd_cnt_src(data)                                  ((0x3FF00000&(data))>>20)
#define DC_SYS2_MUX_get_pre_tra_rd_cnt(data)                                  ((0x3FF00000&(data))>>20)
#define DC_SYS2_MUX_pre_tra_wr_cnt_shift                                      (8)
#define DC_SYS2_MUX_pre_tra_wr_cnt_mask                                       (0x0003FF00)
#define DC_SYS2_MUX_pre_tra_wr_cnt(data)                                      (0x0003FF00&((data)<<8))
#define DC_SYS2_MUX_pre_tra_wr_cnt_src(data)                                  ((0x0003FF00&(data))>>8)
#define DC_SYS2_MUX_get_pre_tra_wr_cnt(data)                                  ((0x0003FF00&(data))>>8)
#define DC_SYS2_MUX_tv_sb4_mux_shift                                          (1)
#define DC_SYS2_MUX_tv_sb4_mux_mask                                           (0x00000002)
#define DC_SYS2_MUX_tv_sb4_mux(data)                                          (0x00000002&((data)<<1))
#define DC_SYS2_MUX_tv_sb4_mux_src(data)                                      ((0x00000002&(data))>>1)
#define DC_SYS2_MUX_get_tv_sb4_mux(data)                                      ((0x00000002&(data))>>1)
#define DC_SYS2_MUX_tv_sb2_mux_shift                                          (0)
#define DC_SYS2_MUX_tv_sb2_mux_mask                                           (0x00000001)
#define DC_SYS2_MUX_tv_sb2_mux(data)                                          (0x00000001&((data)<<0))
#define DC_SYS2_MUX_tv_sb2_mux_src(data)                                      ((0x00000001&(data))>>0)
#define DC_SYS2_MUX_get_tv_sb2_mux(data)                                      ((0x00000001&(data))>>0)


#define DC_MT_ADDCMD_HI_SYS2_0                                                0x18007410
#define DC_MT_ADDCMD_HI_SYS2_1                                                0x18007414
#define DC_MT_ADDCMD_HI_SYS2_2                                                0x18007418
#define DC_MT_ADDCMD_HI_SYS2_3                                                0x1800741C
#define DC_MT_ADDCMD_HI_SYS2_0_reg_addr                                       "0xB8007410"
#define DC_MT_ADDCMD_HI_SYS2_1_reg_addr                                       "0xB8007414"
#define DC_MT_ADDCMD_HI_SYS2_2_reg_addr                                       "0xB8007418"
#define DC_MT_ADDCMD_HI_SYS2_3_reg_addr                                       "0xB800741C"
#define DC_MT_ADDCMD_HI_SYS2_0_reg                                            0xB8007410
#define DC_MT_ADDCMD_HI_SYS2_1_reg                                            0xB8007414
#define DC_MT_ADDCMD_HI_SYS2_2_reg                                            0xB8007418
#define DC_MT_ADDCMD_HI_SYS2_3_reg                                            0xB800741C
#define set_DC_MT_ADDCMD_HI_SYS2_0_reg(data)   (*((volatile unsigned int*) DC_MT_ADDCMD_HI_SYS2_0_reg)=data)
#define set_DC_MT_ADDCMD_HI_SYS2_1_reg(data)   (*((volatile unsigned int*) DC_MT_ADDCMD_HI_SYS2_1_reg)=data)
#define set_DC_MT_ADDCMD_HI_SYS2_2_reg(data)   (*((volatile unsigned int*) DC_MT_ADDCMD_HI_SYS2_2_reg)=data)
#define set_DC_MT_ADDCMD_HI_SYS2_3_reg(data)   (*((volatile unsigned int*) DC_MT_ADDCMD_HI_SYS2_3_reg)=data)
#define get_DC_MT_ADDCMD_HI_SYS2_0_reg   (*((volatile unsigned int*) DC_MT_ADDCMD_HI_SYS2_0_reg))
#define get_DC_MT_ADDCMD_HI_SYS2_1_reg   (*((volatile unsigned int*) DC_MT_ADDCMD_HI_SYS2_1_reg))
#define get_DC_MT_ADDCMD_HI_SYS2_2_reg   (*((volatile unsigned int*) DC_MT_ADDCMD_HI_SYS2_2_reg))
#define get_DC_MT_ADDCMD_HI_SYS2_3_reg   (*((volatile unsigned int*) DC_MT_ADDCMD_HI_SYS2_3_reg))
#define DC_MT_ADDCMD_HI_SYS2_0_inst_adr                                       "0x0004"
#define DC_MT_ADDCMD_HI_SYS2_1_inst_adr                                       "0x0005"
#define DC_MT_ADDCMD_HI_SYS2_2_inst_adr                                       "0x0006"
#define DC_MT_ADDCMD_HI_SYS2_3_inst_adr                                       "0x0007"
#define DC_MT_ADDCMD_HI_SYS2_0_inst                                           0x0004
#define DC_MT_ADDCMD_HI_SYS2_1_inst                                           0x0005
#define DC_MT_ADDCMD_HI_SYS2_2_inst                                           0x0006
#define DC_MT_ADDCMD_HI_SYS2_3_inst                                           0x0007
#define DC_MT_ADDCMD_HI_SYS2_ever_trap_shift                                  (21)
#define DC_MT_ADDCMD_HI_SYS2_ever_trap_mask                                   (0x00200000)
#define DC_MT_ADDCMD_HI_SYS2_ever_trap(data)                                  (0x00200000&((data)<<21))
#define DC_MT_ADDCMD_HI_SYS2_ever_trap_src(data)                              ((0x00200000&(data))>>21)
#define DC_MT_ADDCMD_HI_SYS2_get_ever_trap(data)                              ((0x00200000&(data))>>21)
#define DC_MT_ADDCMD_HI_SYS2_module_ID_shift                                  (14)
#define DC_MT_ADDCMD_HI_SYS2_module_ID_mask                                   (0x001FC000)
#define DC_MT_ADDCMD_HI_SYS2_module_ID(data)                                  (0x001FC000&((data)<<14))
#define DC_MT_ADDCMD_HI_SYS2_module_ID_src(data)                              ((0x001FC000&(data))>>14)
#define DC_MT_ADDCMD_HI_SYS2_get_module_ID(data)                              ((0x001FC000&(data))>>14)
#define DC_MT_ADDCMD_HI_SYS2_addcmd_shift                                     (0)
#define DC_MT_ADDCMD_HI_SYS2_addcmd_mask                                      (0x00003FFF)
#define DC_MT_ADDCMD_HI_SYS2_addcmd(data)                                     (0x00003FFF&((data)<<0))
#define DC_MT_ADDCMD_HI_SYS2_addcmd_src(data)                                 ((0x00003FFF&(data))>>0)
#define DC_MT_ADDCMD_HI_SYS2_get_addcmd(data)                                 ((0x00003FFF&(data))>>0)


#define DC_MT_ADDCMD_LO_SYS2_0                                                0x18007420
#define DC_MT_ADDCMD_LO_SYS2_1                                                0x18007424
#define DC_MT_ADDCMD_LO_SYS2_2                                                0x18007428
#define DC_MT_ADDCMD_LO_SYS2_3                                                0x1800742C
#define DC_MT_ADDCMD_LO_SYS2_0_reg_addr                                       "0xB8007420"
#define DC_MT_ADDCMD_LO_SYS2_1_reg_addr                                       "0xB8007424"
#define DC_MT_ADDCMD_LO_SYS2_2_reg_addr                                       "0xB8007428"
#define DC_MT_ADDCMD_LO_SYS2_3_reg_addr                                       "0xB800742C"
#define DC_MT_ADDCMD_LO_SYS2_0_reg                                            0xB8007420
#define DC_MT_ADDCMD_LO_SYS2_1_reg                                            0xB8007424
#define DC_MT_ADDCMD_LO_SYS2_2_reg                                            0xB8007428
#define DC_MT_ADDCMD_LO_SYS2_3_reg                                            0xB800742C
#define set_DC_MT_ADDCMD_LO_SYS2_0_reg(data)   (*((volatile unsigned int*) DC_MT_ADDCMD_LO_SYS2_0_reg)=data)
#define set_DC_MT_ADDCMD_LO_SYS2_1_reg(data)   (*((volatile unsigned int*) DC_MT_ADDCMD_LO_SYS2_1_reg)=data)
#define set_DC_MT_ADDCMD_LO_SYS2_2_reg(data)   (*((volatile unsigned int*) DC_MT_ADDCMD_LO_SYS2_2_reg)=data)
#define set_DC_MT_ADDCMD_LO_SYS2_3_reg(data)   (*((volatile unsigned int*) DC_MT_ADDCMD_LO_SYS2_3_reg)=data)
#define get_DC_MT_ADDCMD_LO_SYS2_0_reg   (*((volatile unsigned int*) DC_MT_ADDCMD_LO_SYS2_0_reg))
#define get_DC_MT_ADDCMD_LO_SYS2_1_reg   (*((volatile unsigned int*) DC_MT_ADDCMD_LO_SYS2_1_reg))
#define get_DC_MT_ADDCMD_LO_SYS2_2_reg   (*((volatile unsigned int*) DC_MT_ADDCMD_LO_SYS2_2_reg))
#define get_DC_MT_ADDCMD_LO_SYS2_3_reg   (*((volatile unsigned int*) DC_MT_ADDCMD_LO_SYS2_3_reg))
#define DC_MT_ADDCMD_LO_SYS2_0_inst_adr                                       "0x0008"
#define DC_MT_ADDCMD_LO_SYS2_1_inst_adr                                       "0x0009"
#define DC_MT_ADDCMD_LO_SYS2_2_inst_adr                                       "0x000A"
#define DC_MT_ADDCMD_LO_SYS2_3_inst_adr                                       "0x000B"
#define DC_MT_ADDCMD_LO_SYS2_0_inst                                           0x0008
#define DC_MT_ADDCMD_LO_SYS2_1_inst                                           0x0009
#define DC_MT_ADDCMD_LO_SYS2_2_inst                                           0x000A
#define DC_MT_ADDCMD_LO_SYS2_3_inst                                           0x000B
#define DC_MT_ADDCMD_LO_SYS2_addcmd_shift                                     (0)
#define DC_MT_ADDCMD_LO_SYS2_addcmd_mask                                      (0xFFFFFFFF)
#define DC_MT_ADDCMD_LO_SYS2_addcmd(data)                                     (0xFFFFFFFF&((data)<<0))
#define DC_MT_ADDCMD_LO_SYS2_addcmd_src(data)                                 ((0xFFFFFFFF&(data))>>0)
#define DC_MT_ADDCMD_LO_SYS2_get_addcmd(data)                                 ((0xFFFFFFFF&(data))>>0)


#define DC_MT_ADDCMD_SA_SYS2_0                                                0x18007430
#define DC_MT_ADDCMD_SA_SYS2_1                                                0x18007434
#define DC_MT_ADDCMD_SA_SYS2_2                                                0x18007438
#define DC_MT_ADDCMD_SA_SYS2_3                                                0x1800743C
#define DC_MT_ADDCMD_SA_SYS2_0_reg_addr                                       "0xB8007430"
#define DC_MT_ADDCMD_SA_SYS2_1_reg_addr                                       "0xB8007434"
#define DC_MT_ADDCMD_SA_SYS2_2_reg_addr                                       "0xB8007438"
#define DC_MT_ADDCMD_SA_SYS2_3_reg_addr                                       "0xB800743C"
#define DC_MT_ADDCMD_SA_SYS2_0_reg                                            0xB8007430
#define DC_MT_ADDCMD_SA_SYS2_1_reg                                            0xB8007434
#define DC_MT_ADDCMD_SA_SYS2_2_reg                                            0xB8007438
#define DC_MT_ADDCMD_SA_SYS2_3_reg                                            0xB800743C
#define set_DC_MT_ADDCMD_SA_SYS2_0_reg(data)   (*((volatile unsigned int*) DC_MT_ADDCMD_SA_SYS2_0_reg)=data)
#define set_DC_MT_ADDCMD_SA_SYS2_1_reg(data)   (*((volatile unsigned int*) DC_MT_ADDCMD_SA_SYS2_1_reg)=data)
#define set_DC_MT_ADDCMD_SA_SYS2_2_reg(data)   (*((volatile unsigned int*) DC_MT_ADDCMD_SA_SYS2_2_reg)=data)
#define set_DC_MT_ADDCMD_SA_SYS2_3_reg(data)   (*((volatile unsigned int*) DC_MT_ADDCMD_SA_SYS2_3_reg)=data)
#define get_DC_MT_ADDCMD_SA_SYS2_0_reg   (*((volatile unsigned int*) DC_MT_ADDCMD_SA_SYS2_0_reg))
#define get_DC_MT_ADDCMD_SA_SYS2_1_reg   (*((volatile unsigned int*) DC_MT_ADDCMD_SA_SYS2_1_reg))
#define get_DC_MT_ADDCMD_SA_SYS2_2_reg   (*((volatile unsigned int*) DC_MT_ADDCMD_SA_SYS2_2_reg))
#define get_DC_MT_ADDCMD_SA_SYS2_3_reg   (*((volatile unsigned int*) DC_MT_ADDCMD_SA_SYS2_3_reg))
#define DC_MT_ADDCMD_SA_SYS2_0_inst_adr                                       "0x000C"
#define DC_MT_ADDCMD_SA_SYS2_1_inst_adr                                       "0x000D"
#define DC_MT_ADDCMD_SA_SYS2_2_inst_adr                                       "0x000E"
#define DC_MT_ADDCMD_SA_SYS2_3_inst_adr                                       "0x000F"
#define DC_MT_ADDCMD_SA_SYS2_0_inst                                           0x000C
#define DC_MT_ADDCMD_SA_SYS2_1_inst                                           0x000D
#define DC_MT_ADDCMD_SA_SYS2_2_inst                                           0x000E
#define DC_MT_ADDCMD_SA_SYS2_3_inst                                           0x000F
#define DC_MT_ADDCMD_SA_SYS2_trap_seq_sa_shift                                (0)
#define DC_MT_ADDCMD_SA_SYS2_trap_seq_sa_mask                                 (0xFFFFFFFF)
#define DC_MT_ADDCMD_SA_SYS2_trap_seq_sa(data)                                (0xFFFFFFFF&((data)<<0))
#define DC_MT_ADDCMD_SA_SYS2_trap_seq_sa_src(data)                            ((0xFFFFFFFF&(data))>>0)
#define DC_MT_ADDCMD_SA_SYS2_get_trap_seq_sa(data)                            ((0xFFFFFFFF&(data))>>0)


#define DC_EC_ADDCMD_HI_SYS2                                                  0x18007440
#define DC_EC_ADDCMD_HI_SYS2_reg_addr                                         "0xB8007440"
#define DC_EC_ADDCMD_HI_SYS2_reg                                              0xB8007440
#define set_DC_EC_ADDCMD_HI_SYS2_reg(data)   (*((volatile unsigned int*) DC_EC_ADDCMD_HI_SYS2_reg)=data)
#define get_DC_EC_ADDCMD_HI_SYS2_reg   (*((volatile unsigned int*) DC_EC_ADDCMD_HI_SYS2_reg))
#define DC_EC_ADDCMD_HI_SYS2_inst_adr                                         "0x0010"
#define DC_EC_ADDCMD_HI_SYS2_inst                                             0x0010
#define DC_EC_ADDCMD_HI_SYS2_error_cmd_ever_trap_shift                        (30)
#define DC_EC_ADDCMD_HI_SYS2_error_cmd_ever_trap_mask                         (0x40000000)
#define DC_EC_ADDCMD_HI_SYS2_error_cmd_ever_trap(data)                        (0x40000000&((data)<<30))
#define DC_EC_ADDCMD_HI_SYS2_error_cmd_ever_trap_src(data)                    ((0x40000000&(data))>>30)
#define DC_EC_ADDCMD_HI_SYS2_get_error_cmd_ever_trap(data)                    ((0x40000000&(data))>>30)
#define DC_EC_ADDCMD_HI_SYS2_trap_case_shift                                  (22)
#define DC_EC_ADDCMD_HI_SYS2_trap_case_mask                                   (0x3FC00000)
#define DC_EC_ADDCMD_HI_SYS2_trap_case(data)                                  (0x3FC00000&((data)<<22))
#define DC_EC_ADDCMD_HI_SYS2_trap_case_src(data)                              ((0x3FC00000&(data))>>22)
#define DC_EC_ADDCMD_HI_SYS2_get_trap_case(data)                              ((0x3FC00000&(data))>>22)
#define DC_EC_ADDCMD_HI_SYS2_Addcmd_hi_shift                                  (0)
#define DC_EC_ADDCMD_HI_SYS2_Addcmd_hi_mask                                   (0x003FFFFF)
#define DC_EC_ADDCMD_HI_SYS2_Addcmd_hi(data)                                  (0x003FFFFF&((data)<<0))
#define DC_EC_ADDCMD_HI_SYS2_Addcmd_hi_src(data)                              ((0x003FFFFF&(data))>>0)
#define DC_EC_ADDCMD_HI_SYS2_get_Addcmd_hi(data)                              ((0x003FFFFF&(data))>>0)


#define DC_EC_ADDCMD_LO_SYS2                                                  0x18007444
#define DC_EC_ADDCMD_LO_SYS2_reg_addr                                         "0xB8007444"
#define DC_EC_ADDCMD_LO_SYS2_reg                                              0xB8007444
#define set_DC_EC_ADDCMD_LO_SYS2_reg(data)   (*((volatile unsigned int*) DC_EC_ADDCMD_LO_SYS2_reg)=data)
#define get_DC_EC_ADDCMD_LO_SYS2_reg   (*((volatile unsigned int*) DC_EC_ADDCMD_LO_SYS2_reg))
#define DC_EC_ADDCMD_LO_SYS2_inst_adr                                         "0x0011"
#define DC_EC_ADDCMD_LO_SYS2_inst                                             0x0011
#define DC_EC_ADDCMD_LO_SYS2_Addcmd_lo_shift                                  (0)
#define DC_EC_ADDCMD_LO_SYS2_Addcmd_lo_mask                                   (0xFFFFFFFF)
#define DC_EC_ADDCMD_LO_SYS2_Addcmd_lo(data)                                  (0xFFFFFFFF&((data)<<0))
#define DC_EC_ADDCMD_LO_SYS2_Addcmd_lo_src(data)                              ((0xFFFFFFFF&(data))>>0)
#define DC_EC_ADDCMD_LO_SYS2_get_Addcmd_lo(data)                              ((0xFFFFFFFF&(data))>>0)


#define DC_INT_ENABLE_SYS2                                                    0x1800744C
#define DC_INT_ENABLE_SYS2_reg_addr                                           "0xB800744C"
#define DC_INT_ENABLE_SYS2_reg                                                0xB800744C
#define set_DC_INT_ENABLE_SYS2_reg(data)   (*((volatile unsigned int*) DC_INT_ENABLE_SYS2_reg)=data)
#define get_DC_INT_ENABLE_SYS2_reg   (*((volatile unsigned int*) DC_INT_ENABLE_SYS2_reg))
#define DC_INT_ENABLE_SYS2_inst_adr                                           "0x0013"
#define DC_INT_ENABLE_SYS2_inst                                               0x0013
#define DC_INT_ENABLE_SYS2_rd_tag_mismatch_int_en_shift                       (23)
#define DC_INT_ENABLE_SYS2_rd_tag_mismatch_int_en_mask                        (0x00800000)
#define DC_INT_ENABLE_SYS2_rd_tag_mismatch_int_en(data)                       (0x00800000&((data)<<23))
#define DC_INT_ENABLE_SYS2_rd_tag_mismatch_int_en_src(data)                   ((0x00800000&(data))>>23)
#define DC_INT_ENABLE_SYS2_get_rd_tag_mismatch_int_en(data)                   ((0x00800000&(data))>>23)
#define DC_INT_ENABLE_SYS2_err_seq_sa_odd_int_en_shift                        (22)
#define DC_INT_ENABLE_SYS2_err_seq_sa_odd_int_en_mask                         (0x00400000)
#define DC_INT_ENABLE_SYS2_err_seq_sa_odd_int_en(data)                        (0x00400000&((data)<<22))
#define DC_INT_ENABLE_SYS2_err_seq_sa_odd_int_en_src(data)                    ((0x00400000&(data))>>22)
#define DC_INT_ENABLE_SYS2_get_err_seq_sa_odd_int_en(data)                    ((0x00400000&(data))>>22)
#define DC_INT_ENABLE_SYS2_err_seq_bl_zero_int_en_shift                       (21)
#define DC_INT_ENABLE_SYS2_err_seq_bl_zero_int_en_mask                        (0x00200000)
#define DC_INT_ENABLE_SYS2_err_seq_bl_zero_int_en(data)                       (0x00200000&((data)<<21))
#define DC_INT_ENABLE_SYS2_err_seq_bl_zero_int_en_src(data)                   ((0x00200000&(data))>>21)
#define DC_INT_ENABLE_SYS2_get_err_seq_bl_zero_int_en(data)                   ((0x00200000&(data))>>21)
#define DC_INT_ENABLE_SYS2_err_seq_bl_odd_int_en_shift                        (20)
#define DC_INT_ENABLE_SYS2_err_seq_bl_odd_int_en_mask                         (0x00100000)
#define DC_INT_ENABLE_SYS2_err_seq_bl_odd_int_en(data)                        (0x00100000&((data)<<20))
#define DC_INT_ENABLE_SYS2_err_seq_bl_odd_int_en_src(data)                    ((0x00100000&(data))>>20)
#define DC_INT_ENABLE_SYS2_get_err_seq_bl_odd_int_en(data)                    ((0x00100000&(data))>>20)
#define DC_INT_ENABLE_SYS2_err_blk_8x2_on_64_int_en_shift                     (19)
#define DC_INT_ENABLE_SYS2_err_blk_8x2_on_64_int_en_mask                      (0x00080000)
#define DC_INT_ENABLE_SYS2_err_blk_8x2_on_64_int_en(data)                     (0x00080000&((data)<<19))
#define DC_INT_ENABLE_SYS2_err_blk_8x2_on_64_int_en_src(data)                 ((0x00080000&(data))>>19)
#define DC_INT_ENABLE_SYS2_get_err_blk_8x2_on_64_int_en(data)                 ((0x00080000&(data))>>19)
#define DC_INT_ENABLE_SYS2_err_blk_size_exceed_int_en_shift                   (18)
#define DC_INT_ENABLE_SYS2_err_blk_size_exceed_int_en_mask                    (0x00040000)
#define DC_INT_ENABLE_SYS2_err_blk_size_exceed_int_en(data)                   (0x00040000&((data)<<18))
#define DC_INT_ENABLE_SYS2_err_blk_size_exceed_int_en_src(data)               ((0x00040000&(data))>>18)
#define DC_INT_ENABLE_SYS2_get_err_blk_size_exceed_int_en(data)               ((0x00040000&(data))>>18)
#define DC_INT_ENABLE_SYS2_err_blk_h_zero_int_en_shift                        (17)
#define DC_INT_ENABLE_SYS2_err_blk_h_zero_int_en_mask                         (0x00020000)
#define DC_INT_ENABLE_SYS2_err_blk_h_zero_int_en(data)                        (0x00020000&((data)<<17))
#define DC_INT_ENABLE_SYS2_err_blk_h_zero_int_en_src(data)                    ((0x00020000&(data))>>17)
#define DC_INT_ENABLE_SYS2_get_err_blk_h_zero_int_en(data)                    ((0x00020000&(data))>>17)
#define DC_INT_ENABLE_SYS2_err_blk_w_zero_int_en_shift                        (16)
#define DC_INT_ENABLE_SYS2_err_blk_w_zero_int_en_mask                         (0x00010000)
#define DC_INT_ENABLE_SYS2_err_blk_w_zero_int_en(data)                        (0x00010000&((data)<<16))
#define DC_INT_ENABLE_SYS2_err_blk_w_zero_int_en_src(data)                    ((0x00010000&(data))>>16)
#define DC_INT_ENABLE_SYS2_get_err_blk_w_zero_int_en(data)                    ((0x00010000&(data))>>16)
#define DC_INT_ENABLE_SYS2_mt_3_mod3_int_en_shift                             (12)
#define DC_INT_ENABLE_SYS2_mt_3_mod3_int_en_mask                              (0x00001000)
#define DC_INT_ENABLE_SYS2_mt_3_mod3_int_en(data)                             (0x00001000&((data)<<12))
#define DC_INT_ENABLE_SYS2_mt_3_mod3_int_en_src(data)                         ((0x00001000&(data))>>12)
#define DC_INT_ENABLE_SYS2_get_mt_3_mod3_int_en(data)                         ((0x00001000&(data))>>12)
#define DC_INT_ENABLE_SYS2_mt_3_mod2_int_en_shift                             (11)
#define DC_INT_ENABLE_SYS2_mt_3_mod2_int_en_mask                              (0x00000800)
#define DC_INT_ENABLE_SYS2_mt_3_mod2_int_en(data)                             (0x00000800&((data)<<11))
#define DC_INT_ENABLE_SYS2_mt_3_mod2_int_en_src(data)                         ((0x00000800&(data))>>11)
#define DC_INT_ENABLE_SYS2_get_mt_3_mod2_int_en(data)                         ((0x00000800&(data))>>11)
#define DC_INT_ENABLE_SYS2_mt_3_mod1_int_en_shift                             (10)
#define DC_INT_ENABLE_SYS2_mt_3_mod1_int_en_mask                              (0x00000400)
#define DC_INT_ENABLE_SYS2_mt_3_mod1_int_en(data)                             (0x00000400&((data)<<10))
#define DC_INT_ENABLE_SYS2_mt_3_mod1_int_en_src(data)                         ((0x00000400&(data))>>10)
#define DC_INT_ENABLE_SYS2_get_mt_3_mod1_int_en(data)                         ((0x00000400&(data))>>10)
#define DC_INT_ENABLE_SYS2_mt_2_mod3_int_en_shift                             (9)
#define DC_INT_ENABLE_SYS2_mt_2_mod3_int_en_mask                              (0x00000200)
#define DC_INT_ENABLE_SYS2_mt_2_mod3_int_en(data)                             (0x00000200&((data)<<9))
#define DC_INT_ENABLE_SYS2_mt_2_mod3_int_en_src(data)                         ((0x00000200&(data))>>9)
#define DC_INT_ENABLE_SYS2_get_mt_2_mod3_int_en(data)                         ((0x00000200&(data))>>9)
#define DC_INT_ENABLE_SYS2_mt_2_mod2_int_en_shift                             (8)
#define DC_INT_ENABLE_SYS2_mt_2_mod2_int_en_mask                              (0x00000100)
#define DC_INT_ENABLE_SYS2_mt_2_mod2_int_en(data)                             (0x00000100&((data)<<8))
#define DC_INT_ENABLE_SYS2_mt_2_mod2_int_en_src(data)                         ((0x00000100&(data))>>8)
#define DC_INT_ENABLE_SYS2_get_mt_2_mod2_int_en(data)                         ((0x00000100&(data))>>8)
#define DC_INT_ENABLE_SYS2_mt_2_mod1_int_en_shift                             (7)
#define DC_INT_ENABLE_SYS2_mt_2_mod1_int_en_mask                              (0x00000080)
#define DC_INT_ENABLE_SYS2_mt_2_mod1_int_en(data)                             (0x00000080&((data)<<7))
#define DC_INT_ENABLE_SYS2_mt_2_mod1_int_en_src(data)                         ((0x00000080&(data))>>7)
#define DC_INT_ENABLE_SYS2_get_mt_2_mod1_int_en(data)                         ((0x00000080&(data))>>7)
#define DC_INT_ENABLE_SYS2_mt_1_mod3_int_en_shift                             (6)
#define DC_INT_ENABLE_SYS2_mt_1_mod3_int_en_mask                              (0x00000040)
#define DC_INT_ENABLE_SYS2_mt_1_mod3_int_en(data)                             (0x00000040&((data)<<6))
#define DC_INT_ENABLE_SYS2_mt_1_mod3_int_en_src(data)                         ((0x00000040&(data))>>6)
#define DC_INT_ENABLE_SYS2_get_mt_1_mod3_int_en(data)                         ((0x00000040&(data))>>6)
#define DC_INT_ENABLE_SYS2_mt_1_mod2_int_en_shift                             (5)
#define DC_INT_ENABLE_SYS2_mt_1_mod2_int_en_mask                              (0x00000020)
#define DC_INT_ENABLE_SYS2_mt_1_mod2_int_en(data)                             (0x00000020&((data)<<5))
#define DC_INT_ENABLE_SYS2_mt_1_mod2_int_en_src(data)                         ((0x00000020&(data))>>5)
#define DC_INT_ENABLE_SYS2_get_mt_1_mod2_int_en(data)                         ((0x00000020&(data))>>5)
#define DC_INT_ENABLE_SYS2_mt_1_mod1_int_en_shift                             (4)
#define DC_INT_ENABLE_SYS2_mt_1_mod1_int_en_mask                              (0x00000010)
#define DC_INT_ENABLE_SYS2_mt_1_mod1_int_en(data)                             (0x00000010&((data)<<4))
#define DC_INT_ENABLE_SYS2_mt_1_mod1_int_en_src(data)                         ((0x00000010&(data))>>4)
#define DC_INT_ENABLE_SYS2_get_mt_1_mod1_int_en(data)                         ((0x00000010&(data))>>4)
#define DC_INT_ENABLE_SYS2_mt_0_mod3_int_en_shift                             (3)
#define DC_INT_ENABLE_SYS2_mt_0_mod3_int_en_mask                              (0x00000008)
#define DC_INT_ENABLE_SYS2_mt_0_mod3_int_en(data)                             (0x00000008&((data)<<3))
#define DC_INT_ENABLE_SYS2_mt_0_mod3_int_en_src(data)                         ((0x00000008&(data))>>3)
#define DC_INT_ENABLE_SYS2_get_mt_0_mod3_int_en(data)                         ((0x00000008&(data))>>3)
#define DC_INT_ENABLE_SYS2_mt_0_mod2_int_en_shift                             (2)
#define DC_INT_ENABLE_SYS2_mt_0_mod2_int_en_mask                              (0x00000004)
#define DC_INT_ENABLE_SYS2_mt_0_mod2_int_en(data)                             (0x00000004&((data)<<2))
#define DC_INT_ENABLE_SYS2_mt_0_mod2_int_en_src(data)                         ((0x00000004&(data))>>2)
#define DC_INT_ENABLE_SYS2_get_mt_0_mod2_int_en(data)                         ((0x00000004&(data))>>2)
#define DC_INT_ENABLE_SYS2_mt_0_mod1_int_en_shift                             (1)
#define DC_INT_ENABLE_SYS2_mt_0_mod1_int_en_mask                              (0x00000002)
#define DC_INT_ENABLE_SYS2_mt_0_mod1_int_en(data)                             (0x00000002&((data)<<1))
#define DC_INT_ENABLE_SYS2_mt_0_mod1_int_en_src(data)                         ((0x00000002&(data))>>1)
#define DC_INT_ENABLE_SYS2_get_mt_0_mod1_int_en(data)                         ((0x00000002&(data))>>1)
#define DC_INT_ENABLE_SYS2_write_data_shift                                   (0)
#define DC_INT_ENABLE_SYS2_write_data_mask                                    (0x00000001)
#define DC_INT_ENABLE_SYS2_write_data(data)                                   (0x00000001&((data)<<0))
#define DC_INT_ENABLE_SYS2_write_data_src(data)                               ((0x00000001&(data))>>0)
#define DC_INT_ENABLE_SYS2_get_write_data(data)                               ((0x00000001&(data))>>0)


#define DC_INT_STATUS_SYS2                                                    0x18007450
#define DC_INT_STATUS_SYS2_reg_addr                                           "0xB8007450"
#define DC_INT_STATUS_SYS2_reg                                                0xB8007450
#define set_DC_INT_STATUS_SYS2_reg(data)   (*((volatile unsigned int*) DC_INT_STATUS_SYS2_reg)=data)
#define get_DC_INT_STATUS_SYS2_reg   (*((volatile unsigned int*) DC_INT_STATUS_SYS2_reg))
#define DC_INT_STATUS_SYS2_inst_adr                                           "0x0014"
#define DC_INT_STATUS_SYS2_inst                                               0x0014
#define DC_INT_STATUS_SYS2_rd_tag_mismatch_int_shift                          (23)
#define DC_INT_STATUS_SYS2_rd_tag_mismatch_int_mask                           (0x00800000)
#define DC_INT_STATUS_SYS2_rd_tag_mismatch_int(data)                          (0x00800000&((data)<<23))
#define DC_INT_STATUS_SYS2_rd_tag_mismatch_int_src(data)                      ((0x00800000&(data))>>23)
#define DC_INT_STATUS_SYS2_get_rd_tag_mismatch_int(data)                      ((0x00800000&(data))>>23)
#define DC_INT_STATUS_SYS2_err_seq_sa_odd_int_shift                           (22)
#define DC_INT_STATUS_SYS2_err_seq_sa_odd_int_mask                            (0x00400000)
#define DC_INT_STATUS_SYS2_err_seq_sa_odd_int(data)                           (0x00400000&((data)<<22))
#define DC_INT_STATUS_SYS2_err_seq_sa_odd_int_src(data)                       ((0x00400000&(data))>>22)
#define DC_INT_STATUS_SYS2_get_err_seq_sa_odd_int(data)                       ((0x00400000&(data))>>22)
#define DC_INT_STATUS_SYS2_err_seq_bl_zero_int_shift                          (21)
#define DC_INT_STATUS_SYS2_err_seq_bl_zero_int_mask                           (0x00200000)
#define DC_INT_STATUS_SYS2_err_seq_bl_zero_int(data)                          (0x00200000&((data)<<21))
#define DC_INT_STATUS_SYS2_err_seq_bl_zero_int_src(data)                      ((0x00200000&(data))>>21)
#define DC_INT_STATUS_SYS2_get_err_seq_bl_zero_int(data)                      ((0x00200000&(data))>>21)
#define DC_INT_STATUS_SYS2_err_seq_bl_odd_int_shift                           (20)
#define DC_INT_STATUS_SYS2_err_seq_bl_odd_int_mask                            (0x00100000)
#define DC_INT_STATUS_SYS2_err_seq_bl_odd_int(data)                           (0x00100000&((data)<<20))
#define DC_INT_STATUS_SYS2_err_seq_bl_odd_int_src(data)                       ((0x00100000&(data))>>20)
#define DC_INT_STATUS_SYS2_get_err_seq_bl_odd_int(data)                       ((0x00100000&(data))>>20)
#define DC_INT_STATUS_SYS2_err_blk_8x2_on_64_int_shift                        (19)
#define DC_INT_STATUS_SYS2_err_blk_8x2_on_64_int_mask                         (0x00080000)
#define DC_INT_STATUS_SYS2_err_blk_8x2_on_64_int(data)                        (0x00080000&((data)<<19))
#define DC_INT_STATUS_SYS2_err_blk_8x2_on_64_int_src(data)                    ((0x00080000&(data))>>19)
#define DC_INT_STATUS_SYS2_get_err_blk_8x2_on_64_int(data)                    ((0x00080000&(data))>>19)
#define DC_INT_STATUS_SYS2_err_blk_size_exceed_int_shift                      (18)
#define DC_INT_STATUS_SYS2_err_blk_size_exceed_int_mask                       (0x00040000)
#define DC_INT_STATUS_SYS2_err_blk_size_exceed_int(data)                      (0x00040000&((data)<<18))
#define DC_INT_STATUS_SYS2_err_blk_size_exceed_int_src(data)                  ((0x00040000&(data))>>18)
#define DC_INT_STATUS_SYS2_get_err_blk_size_exceed_int(data)                  ((0x00040000&(data))>>18)
#define DC_INT_STATUS_SYS2_err_blk_h_zero_int_shift                           (17)
#define DC_INT_STATUS_SYS2_err_blk_h_zero_int_mask                            (0x00020000)
#define DC_INT_STATUS_SYS2_err_blk_h_zero_int(data)                           (0x00020000&((data)<<17))
#define DC_INT_STATUS_SYS2_err_blk_h_zero_int_src(data)                       ((0x00020000&(data))>>17)
#define DC_INT_STATUS_SYS2_get_err_blk_h_zero_int(data)                       ((0x00020000&(data))>>17)
#define DC_INT_STATUS_SYS2_err_blk_w_zero_int_shift                           (16)
#define DC_INT_STATUS_SYS2_err_blk_w_zero_int_mask                            (0x00010000)
#define DC_INT_STATUS_SYS2_err_blk_w_zero_int(data)                           (0x00010000&((data)<<16))
#define DC_INT_STATUS_SYS2_err_blk_w_zero_int_src(data)                       ((0x00010000&(data))>>16)
#define DC_INT_STATUS_SYS2_get_err_blk_w_zero_int(data)                       ((0x00010000&(data))>>16)
#define DC_INT_STATUS_SYS2_mt_3_mod3_int_shift                                (12)
#define DC_INT_STATUS_SYS2_mt_3_mod3_int_mask                                 (0x00001000)
#define DC_INT_STATUS_SYS2_mt_3_mod3_int(data)                                (0x00001000&((data)<<12))
#define DC_INT_STATUS_SYS2_mt_3_mod3_int_src(data)                            ((0x00001000&(data))>>12)
#define DC_INT_STATUS_SYS2_get_mt_3_mod3_int(data)                            ((0x00001000&(data))>>12)
#define DC_INT_STATUS_SYS2_mt_3_mod2_int_shift                                (11)
#define DC_INT_STATUS_SYS2_mt_3_mod2_int_mask                                 (0x00000800)
#define DC_INT_STATUS_SYS2_mt_3_mod2_int(data)                                (0x00000800&((data)<<11))
#define DC_INT_STATUS_SYS2_mt_3_mod2_int_src(data)                            ((0x00000800&(data))>>11)
#define DC_INT_STATUS_SYS2_get_mt_3_mod2_int(data)                            ((0x00000800&(data))>>11)
#define DC_INT_STATUS_SYS2_mt_3_mod1_int_shift                                (10)
#define DC_INT_STATUS_SYS2_mt_3_mod1_int_mask                                 (0x00000400)
#define DC_INT_STATUS_SYS2_mt_3_mod1_int(data)                                (0x00000400&((data)<<10))
#define DC_INT_STATUS_SYS2_mt_3_mod1_int_src(data)                            ((0x00000400&(data))>>10)
#define DC_INT_STATUS_SYS2_get_mt_3_mod1_int(data)                            ((0x00000400&(data))>>10)
#define DC_INT_STATUS_SYS2_mt_2_mod3_int_shift                                (9)
#define DC_INT_STATUS_SYS2_mt_2_mod3_int_mask                                 (0x00000200)
#define DC_INT_STATUS_SYS2_mt_2_mod3_int(data)                                (0x00000200&((data)<<9))
#define DC_INT_STATUS_SYS2_mt_2_mod3_int_src(data)                            ((0x00000200&(data))>>9)
#define DC_INT_STATUS_SYS2_get_mt_2_mod3_int(data)                            ((0x00000200&(data))>>9)
#define DC_INT_STATUS_SYS2_mt_2_mod2_int_shift                                (8)
#define DC_INT_STATUS_SYS2_mt_2_mod2_int_mask                                 (0x00000100)
#define DC_INT_STATUS_SYS2_mt_2_mod2_int(data)                                (0x00000100&((data)<<8))
#define DC_INT_STATUS_SYS2_mt_2_mod2_int_src(data)                            ((0x00000100&(data))>>8)
#define DC_INT_STATUS_SYS2_get_mt_2_mod2_int(data)                            ((0x00000100&(data))>>8)
#define DC_INT_STATUS_SYS2_mt_2_mod1_int_shift                                (7)
#define DC_INT_STATUS_SYS2_mt_2_mod1_int_mask                                 (0x00000080)
#define DC_INT_STATUS_SYS2_mt_2_mod1_int(data)                                (0x00000080&((data)<<7))
#define DC_INT_STATUS_SYS2_mt_2_mod1_int_src(data)                            ((0x00000080&(data))>>7)
#define DC_INT_STATUS_SYS2_get_mt_2_mod1_int(data)                            ((0x00000080&(data))>>7)
#define DC_INT_STATUS_SYS2_mt_1_mod3_int_shift                                (6)
#define DC_INT_STATUS_SYS2_mt_1_mod3_int_mask                                 (0x00000040)
#define DC_INT_STATUS_SYS2_mt_1_mod3_int(data)                                (0x00000040&((data)<<6))
#define DC_INT_STATUS_SYS2_mt_1_mod3_int_src(data)                            ((0x00000040&(data))>>6)
#define DC_INT_STATUS_SYS2_get_mt_1_mod3_int(data)                            ((0x00000040&(data))>>6)
#define DC_INT_STATUS_SYS2_mt_1_mod2_int_shift                                (5)
#define DC_INT_STATUS_SYS2_mt_1_mod2_int_mask                                 (0x00000020)
#define DC_INT_STATUS_SYS2_mt_1_mod2_int(data)                                (0x00000020&((data)<<5))
#define DC_INT_STATUS_SYS2_mt_1_mod2_int_src(data)                            ((0x00000020&(data))>>5)
#define DC_INT_STATUS_SYS2_get_mt_1_mod2_int(data)                            ((0x00000020&(data))>>5)
#define DC_INT_STATUS_SYS2_mt_1_mod1_int_shift                                (4)
#define DC_INT_STATUS_SYS2_mt_1_mod1_int_mask                                 (0x00000010)
#define DC_INT_STATUS_SYS2_mt_1_mod1_int(data)                                (0x00000010&((data)<<4))
#define DC_INT_STATUS_SYS2_mt_1_mod1_int_src(data)                            ((0x00000010&(data))>>4)
#define DC_INT_STATUS_SYS2_get_mt_1_mod1_int(data)                            ((0x00000010&(data))>>4)
#define DC_INT_STATUS_SYS2_mt_0_mod3_int_shift                                (3)
#define DC_INT_STATUS_SYS2_mt_0_mod3_int_mask                                 (0x00000008)
#define DC_INT_STATUS_SYS2_mt_0_mod3_int(data)                                (0x00000008&((data)<<3))
#define DC_INT_STATUS_SYS2_mt_0_mod3_int_src(data)                            ((0x00000008&(data))>>3)
#define DC_INT_STATUS_SYS2_get_mt_0_mod3_int(data)                            ((0x00000008&(data))>>3)
#define DC_INT_STATUS_SYS2_mt_0_mod2_int_shift                                (2)
#define DC_INT_STATUS_SYS2_mt_0_mod2_int_mask                                 (0x00000004)
#define DC_INT_STATUS_SYS2_mt_0_mod2_int(data)                                (0x00000004&((data)<<2))
#define DC_INT_STATUS_SYS2_mt_0_mod2_int_src(data)                            ((0x00000004&(data))>>2)
#define DC_INT_STATUS_SYS2_get_mt_0_mod2_int(data)                            ((0x00000004&(data))>>2)
#define DC_INT_STATUS_SYS2_mt_0_mod1_int_shift                                (1)
#define DC_INT_STATUS_SYS2_mt_0_mod1_int_mask                                 (0x00000002)
#define DC_INT_STATUS_SYS2_mt_0_mod1_int(data)                                (0x00000002&((data)<<1))
#define DC_INT_STATUS_SYS2_mt_0_mod1_int_src(data)                            ((0x00000002&(data))>>1)
#define DC_INT_STATUS_SYS2_get_mt_0_mod1_int(data)                            ((0x00000002&(data))>>1)
#define DC_INT_STATUS_SYS2_write_data_shift                                   (0)
#define DC_INT_STATUS_SYS2_write_data_mask                                    (0x00000001)
#define DC_INT_STATUS_SYS2_write_data(data)                                   (0x00000001&((data)<<0))
#define DC_INT_STATUS_SYS2_write_data_src(data)                               ((0x00000001&(data))>>0)
#define DC_INT_STATUS_SYS2_get_write_data(data)                               ((0x00000001&(data))>>0)


#define DC_64_WRITE_BUF_CTRL                                                  0x18007008
#define DC_64_WRITE_BUF_CTRL_reg_addr                                         "0xB8007008"
#define DC_64_WRITE_BUF_CTRL_reg                                              0xB8007008
#define set_DC_64_WRITE_BUF_CTRL_reg(data)   (*((volatile unsigned int*) DC_64_WRITE_BUF_CTRL_reg)=data)
#define get_DC_64_WRITE_BUF_CTRL_reg   (*((volatile unsigned int*) DC_64_WRITE_BUF_CTRL_reg))
#define DC_64_WRITE_BUF_CTRL_inst_adr                                         "0x0002"
#define DC_64_WRITE_BUF_CTRL_inst                                             0x0002
#define DC_64_WRITE_BUF_CTRL_disable_2nd_channel_shift                        (1)
#define DC_64_WRITE_BUF_CTRL_disable_2nd_channel_mask                         (0x00000002)
#define DC_64_WRITE_BUF_CTRL_disable_2nd_channel(data)                        (0x00000002&((data)<<1))
#define DC_64_WRITE_BUF_CTRL_disable_2nd_channel_src(data)                    ((0x00000002&(data))>>1)
#define DC_64_WRITE_BUF_CTRL_get_disable_2nd_channel(data)                    ((0x00000002&(data))>>1)
#define DC_64_WRITE_BUF_CTRL_full_transfer_shift                              (0)
#define DC_64_WRITE_BUF_CTRL_full_transfer_mask                               (0x00000001)
#define DC_64_WRITE_BUF_CTRL_full_transfer(data)                              (0x00000001&((data)<<0))
#define DC_64_WRITE_BUF_CTRL_full_transfer_src(data)                          ((0x00000001&(data))>>0)
#define DC_64_WRITE_BUF_CTRL_get_full_transfer(data)                          ((0x00000001&(data))>>0)


#define DC_64_READ_BUF_CTRL                                                   0x1800700C
#define DC_64_READ_BUF_CTRL_reg_addr                                          "0xB800700C"
#define DC_64_READ_BUF_CTRL_reg                                               0xB800700C
#define set_DC_64_READ_BUF_CTRL_reg(data)   (*((volatile unsigned int*) DC_64_READ_BUF_CTRL_reg)=data)
#define get_DC_64_READ_BUF_CTRL_reg   (*((volatile unsigned int*) DC_64_READ_BUF_CTRL_reg))
#define DC_64_READ_BUF_CTRL_inst_adr                                          "0x0003"
#define DC_64_READ_BUF_CTRL_inst                                              0x0003
#define DC_64_READ_BUF_CTRL_sync_cmd_cnt_threshold_shift                      (21)
#define DC_64_READ_BUF_CTRL_sync_cmd_cnt_threshold_mask                       (0x00E00000)
#define DC_64_READ_BUF_CTRL_sync_cmd_cnt_threshold(data)                      (0x00E00000&((data)<<21))
#define DC_64_READ_BUF_CTRL_sync_cmd_cnt_threshold_src(data)                  ((0x00E00000&(data))>>21)
#define DC_64_READ_BUF_CTRL_get_sync_cmd_cnt_threshold(data)                  ((0x00E00000&(data))>>21)
#define DC_64_READ_BUF_CTRL_cmd_buf_threshold_shift                           (17)
#define DC_64_READ_BUF_CTRL_cmd_buf_threshold_mask                            (0x001E0000)
#define DC_64_READ_BUF_CTRL_cmd_buf_threshold(data)                           (0x001E0000&((data)<<17))
#define DC_64_READ_BUF_CTRL_cmd_buf_threshold_src(data)                       ((0x001E0000&(data))>>17)
#define DC_64_READ_BUF_CTRL_get_cmd_buf_threshold(data)                       ((0x001E0000&(data))>>17)
#define DC_64_READ_BUF_CTRL_disable_2nd_channel_shift                         (16)
#define DC_64_READ_BUF_CTRL_disable_2nd_channel_mask                          (0x00010000)
#define DC_64_READ_BUF_CTRL_disable_2nd_channel(data)                         (0x00010000&((data)<<16))
#define DC_64_READ_BUF_CTRL_disable_2nd_channel_src(data)                     ((0x00010000&(data))>>16)
#define DC_64_READ_BUF_CTRL_get_disable_2nd_channel(data)                     ((0x00010000&(data))>>16)
#define DC_64_READ_BUF_CTRL_ever_full_shift                                   (15)
#define DC_64_READ_BUF_CTRL_ever_full_mask                                    (0x00008000)
#define DC_64_READ_BUF_CTRL_ever_full(data)                                   (0x00008000&((data)<<15))
#define DC_64_READ_BUF_CTRL_ever_full_src(data)                               ((0x00008000&(data))>>15)
#define DC_64_READ_BUF_CTRL_get_ever_full(data)                               ((0x00008000&(data))>>15)
#define DC_64_READ_BUF_CTRL_ever_reach_threshold_shift                        (14)
#define DC_64_READ_BUF_CTRL_ever_reach_threshold_mask                         (0x00004000)
#define DC_64_READ_BUF_CTRL_ever_reach_threshold(data)                        (0x00004000&((data)<<14))
#define DC_64_READ_BUF_CTRL_ever_reach_threshold_src(data)                    ((0x00004000&(data))>>14)
#define DC_64_READ_BUF_CTRL_get_ever_reach_threshold(data)                    ((0x00004000&(data))>>14)
#define DC_64_READ_BUF_CTRL_max_buf_level_shift                               (7)
#define DC_64_READ_BUF_CTRL_max_buf_level_mask                                (0x00003F80)
#define DC_64_READ_BUF_CTRL_max_buf_level(data)                               (0x00003F80&((data)<<7))
#define DC_64_READ_BUF_CTRL_max_buf_level_src(data)                           ((0x00003F80&(data))>>7)
#define DC_64_READ_BUF_CTRL_get_max_buf_level(data)                           ((0x00003F80&(data))>>7)
#define DC_64_READ_BUF_CTRL_grant_stop_level_shift                            (0)
#define DC_64_READ_BUF_CTRL_grant_stop_level_mask                             (0x0000007F)
#define DC_64_READ_BUF_CTRL_grant_stop_level(data)                            (0x0000007F&((data)<<0))
#define DC_64_READ_BUF_CTRL_grant_stop_level_src(data)                        ((0x0000007F&(data))>>0)
#define DC_64_READ_BUF_CTRL_get_grant_stop_level(data)                        ((0x0000007F&(data))>>0)


#define DC_64_ERROR_CTRL                                                      0x18007014
#define DC_64_ERROR_CTRL_reg_addr                                             "0xB8007014"
#define DC_64_ERROR_CTRL_reg                                                  0xB8007014
#define set_DC_64_ERROR_CTRL_reg(data)   (*((volatile unsigned int*) DC_64_ERROR_CTRL_reg)=data)
#define get_DC_64_ERROR_CTRL_reg   (*((volatile unsigned int*) DC_64_ERROR_CTRL_reg))
#define DC_64_ERROR_CTRL_inst_adr                                             "0x0005"
#define DC_64_ERROR_CTRL_inst                                                 0x0005
#define DC_64_ERROR_CTRL_error_bl_zero_swap_shift                             (0)
#define DC_64_ERROR_CTRL_error_bl_zero_swap_mask                              (0x00000001)
#define DC_64_ERROR_CTRL_error_bl_zero_swap(data)                             (0x00000001&((data)<<0))
#define DC_64_ERROR_CTRL_error_bl_zero_swap_src(data)                         ((0x00000001&(data))>>0)
#define DC_64_ERROR_CTRL_get_error_bl_zero_swap(data)                         ((0x00000001&(data))>>0)


#define DC_PRIORITY_CTRL_64BIT                                                0x180070C4
#define DC_PRIORITY_CTRL_64BIT_reg_addr                                       "0xB80070C4"
#define DC_PRIORITY_CTRL_64BIT_reg                                            0xB80070C4
#define set_DC_PRIORITY_CTRL_64BIT_reg(data)   (*((volatile unsigned int*) DC_PRIORITY_CTRL_64BIT_reg)=data)
#define get_DC_PRIORITY_CTRL_64BIT_reg   (*((volatile unsigned int*) DC_PRIORITY_CTRL_64BIT_reg))
#define DC_PRIORITY_CTRL_64BIT_inst_adr                                       "0x0031"
#define DC_PRIORITY_CTRL_64BIT_inst                                           0x0031
#define DC_PRIORITY_CTRL_64BIT_THIRD_64BIT_WRAPPER_LATCNT_shift               (16)
#define DC_PRIORITY_CTRL_64BIT_THIRD_64BIT_WRAPPER_LATCNT_mask                (0x00FF0000)
#define DC_PRIORITY_CTRL_64BIT_THIRD_64BIT_WRAPPER_LATCNT(data)               (0x00FF0000&((data)<<16))
#define DC_PRIORITY_CTRL_64BIT_THIRD_64BIT_WRAPPER_LATCNT_src(data)           ((0x00FF0000&(data))>>16)
#define DC_PRIORITY_CTRL_64BIT_get_THIRD_64BIT_WRAPPER_LATCNT(data)           ((0x00FF0000&(data))>>16)
#define DC_PRIORITY_CTRL_64BIT_SECOND_64BIT_WRAPPER_LATCNT_shift              (0)
#define DC_PRIORITY_CTRL_64BIT_SECOND_64BIT_WRAPPER_LATCNT_mask               (0x000000FF)
#define DC_PRIORITY_CTRL_64BIT_SECOND_64BIT_WRAPPER_LATCNT(data)              (0x000000FF&((data)<<0))
#define DC_PRIORITY_CTRL_64BIT_SECOND_64BIT_WRAPPER_LATCNT_src(data)          ((0x000000FF&(data))>>0)
#define DC_PRIORITY_CTRL_64BIT_get_SECOND_64BIT_WRAPPER_LATCNT(data)          ((0x000000FF&(data))>>0)


#define DC_64_BIST_MODE                                                       0x18007B00
#define DC_64_BIST_MODE_reg_addr                                              "0xB8007B00"
#define DC_64_BIST_MODE_reg                                                   0xB8007B00
#define set_DC_64_BIST_MODE_reg(data)   (*((volatile unsigned int*) DC_64_BIST_MODE_reg)=data)
#define get_DC_64_BIST_MODE_reg   (*((volatile unsigned int*) DC_64_BIST_MODE_reg))
#define DC_64_BIST_MODE_inst_adr                                              "0x00C0"
#define DC_64_BIST_MODE_inst                                                  0x00C0
#define DC_64_BIST_MODE_DC_BIST_MODE_WRAP2_shift                              (2)
#define DC_64_BIST_MODE_DC_BIST_MODE_WRAP2_mask                               (0x00000004)
#define DC_64_BIST_MODE_DC_BIST_MODE_WRAP2(data)                              (0x00000004&((data)<<2))
#define DC_64_BIST_MODE_DC_BIST_MODE_WRAP2_src(data)                          ((0x00000004&(data))>>2)
#define DC_64_BIST_MODE_get_DC_BIST_MODE_WRAP2(data)                          ((0x00000004&(data))>>2)
#define DC_64_BIST_MODE_DC_BIST_MODE_WRAP1_shift                              (1)
#define DC_64_BIST_MODE_DC_BIST_MODE_WRAP1_mask                               (0x00000002)
#define DC_64_BIST_MODE_DC_BIST_MODE_WRAP1(data)                              (0x00000002&((data)<<1))
#define DC_64_BIST_MODE_DC_BIST_MODE_WRAP1_src(data)                          ((0x00000002&(data))>>1)
#define DC_64_BIST_MODE_get_DC_BIST_MODE_WRAP1(data)                          ((0x00000002&(data))>>1)
#define DC_64_BIST_MODE_DC_BIST_MODE_WRAP0_shift                              (0)
#define DC_64_BIST_MODE_DC_BIST_MODE_WRAP0_mask                               (0x00000001)
#define DC_64_BIST_MODE_DC_BIST_MODE_WRAP0(data)                              (0x00000001&((data)<<0))
#define DC_64_BIST_MODE_DC_BIST_MODE_WRAP0_src(data)                          ((0x00000001&(data))>>0)
#define DC_64_BIST_MODE_get_DC_BIST_MODE_WRAP0(data)                          ((0x00000001&(data))>>0)


#define DC_64_BIST_DONE                                                       0x18007B04
#define DC_64_BIST_DONE_reg_addr                                              "0xB8007B04"
#define DC_64_BIST_DONE_reg                                                   0xB8007B04
#define set_DC_64_BIST_DONE_reg(data)   (*((volatile unsigned int*) DC_64_BIST_DONE_reg)=data)
#define get_DC_64_BIST_DONE_reg   (*((volatile unsigned int*) DC_64_BIST_DONE_reg))
#define DC_64_BIST_DONE_inst_adr                                              "0x00C1"
#define DC_64_BIST_DONE_inst                                                  0x00C1
#define DC_64_BIST_DONE_DC_BIST_DONE_WRAP2_shift                              (2)
#define DC_64_BIST_DONE_DC_BIST_DONE_WRAP2_mask                               (0x00000004)
#define DC_64_BIST_DONE_DC_BIST_DONE_WRAP2(data)                              (0x00000004&((data)<<2))
#define DC_64_BIST_DONE_DC_BIST_DONE_WRAP2_src(data)                          ((0x00000004&(data))>>2)
#define DC_64_BIST_DONE_get_DC_BIST_DONE_WRAP2(data)                          ((0x00000004&(data))>>2)
#define DC_64_BIST_DONE_DC_BIST_DONE_WRAP1_shift                              (1)
#define DC_64_BIST_DONE_DC_BIST_DONE_WRAP1_mask                               (0x00000002)
#define DC_64_BIST_DONE_DC_BIST_DONE_WRAP1(data)                              (0x00000002&((data)<<1))
#define DC_64_BIST_DONE_DC_BIST_DONE_WRAP1_src(data)                          ((0x00000002&(data))>>1)
#define DC_64_BIST_DONE_get_DC_BIST_DONE_WRAP1(data)                          ((0x00000002&(data))>>1)
#define DC_64_BIST_DONE_DC_BIST_DONE_WRAP0_shift                              (0)
#define DC_64_BIST_DONE_DC_BIST_DONE_WRAP0_mask                               (0x00000001)
#define DC_64_BIST_DONE_DC_BIST_DONE_WRAP0(data)                              (0x00000001&((data)<<0))
#define DC_64_BIST_DONE_DC_BIST_DONE_WRAP0_src(data)                          ((0x00000001&(data))>>0)
#define DC_64_BIST_DONE_get_DC_BIST_DONE_WRAP0(data)                          ((0x00000001&(data))>>0)


#define DC_64_BIST_FAIL                                                       0x18007B08
#define DC_64_BIST_FAIL_reg_addr                                              "0xB8007B08"
#define DC_64_BIST_FAIL_reg                                                   0xB8007B08
#define set_DC_64_BIST_FAIL_reg(data)   (*((volatile unsigned int*) DC_64_BIST_FAIL_reg)=data)
#define get_DC_64_BIST_FAIL_reg   (*((volatile unsigned int*) DC_64_BIST_FAIL_reg))
#define DC_64_BIST_FAIL_inst_adr                                              "0x00C2"
#define DC_64_BIST_FAIL_inst                                                  0x00C2
#define DC_64_BIST_FAIL_DC_BIST_FAIL_GROUP_WRAP2_shift                        (2)
#define DC_64_BIST_FAIL_DC_BIST_FAIL_GROUP_WRAP2_mask                         (0x00000004)
#define DC_64_BIST_FAIL_DC_BIST_FAIL_GROUP_WRAP2(data)                        (0x00000004&((data)<<2))
#define DC_64_BIST_FAIL_DC_BIST_FAIL_GROUP_WRAP2_src(data)                    ((0x00000004&(data))>>2)
#define DC_64_BIST_FAIL_get_DC_BIST_FAIL_GROUP_WRAP2(data)                    ((0x00000004&(data))>>2)
#define DC_64_BIST_FAIL_DC_BIST_FAIL_GROUP_WRAP1_shift                        (1)
#define DC_64_BIST_FAIL_DC_BIST_FAIL_GROUP_WRAP1_mask                         (0x00000002)
#define DC_64_BIST_FAIL_DC_BIST_FAIL_GROUP_WRAP1(data)                        (0x00000002&((data)<<1))
#define DC_64_BIST_FAIL_DC_BIST_FAIL_GROUP_WRAP1_src(data)                    ((0x00000002&(data))>>1)
#define DC_64_BIST_FAIL_get_DC_BIST_FAIL_GROUP_WRAP1(data)                    ((0x00000002&(data))>>1)
#define DC_64_BIST_FAIL_DC_BIST_FAIL_GROUP_WRAP0_shift                        (0)
#define DC_64_BIST_FAIL_DC_BIST_FAIL_GROUP_WRAP0_mask                         (0x00000001)
#define DC_64_BIST_FAIL_DC_BIST_FAIL_GROUP_WRAP0(data)                        (0x00000001&((data)<<0))
#define DC_64_BIST_FAIL_DC_BIST_FAIL_GROUP_WRAP0_src(data)                    ((0x00000001&(data))>>0)
#define DC_64_BIST_FAIL_get_DC_BIST_FAIL_GROUP_WRAP0(data)                    ((0x00000001&(data))>>0)


#define DC_64_DRF                                                             0x18007B0C
#define DC_64_DRF_reg_addr                                                    "0xB8007B0C"
#define DC_64_DRF_reg                                                         0xB8007B0C
#define set_DC_64_DRF_reg(data)   (*((volatile unsigned int*) DC_64_DRF_reg)=data)
#define get_DC_64_DRF_reg   (*((volatile unsigned int*) DC_64_DRF_reg))
#define DC_64_DRF_inst_adr                                                    "0x00C3"
#define DC_64_DRF_inst                                                        0x00C3
#define DC_64_DRF_DC_DRF_MODE_WRAP2_shift                                     (2)
#define DC_64_DRF_DC_DRF_MODE_WRAP2_mask                                      (0x00000004)
#define DC_64_DRF_DC_DRF_MODE_WRAP2(data)                                     (0x00000004&((data)<<2))
#define DC_64_DRF_DC_DRF_MODE_WRAP2_src(data)                                 ((0x00000004&(data))>>2)
#define DC_64_DRF_get_DC_DRF_MODE_WRAP2(data)                                 ((0x00000004&(data))>>2)
#define DC_64_DRF_DC_DRF_MODE_WRAP1_shift                                     (1)
#define DC_64_DRF_DC_DRF_MODE_WRAP1_mask                                      (0x00000002)
#define DC_64_DRF_DC_DRF_MODE_WRAP1(data)                                     (0x00000002&((data)<<1))
#define DC_64_DRF_DC_DRF_MODE_WRAP1_src(data)                                 ((0x00000002&(data))>>1)
#define DC_64_DRF_get_DC_DRF_MODE_WRAP1(data)                                 ((0x00000002&(data))>>1)
#define DC_64_DRF_DC_DRF_MODE_WRAP0_shift                                     (0)
#define DC_64_DRF_DC_DRF_MODE_WRAP0_mask                                      (0x00000001)
#define DC_64_DRF_DC_DRF_MODE_WRAP0(data)                                     (0x00000001&((data)<<0))
#define DC_64_DRF_DC_DRF_MODE_WRAP0_src(data)                                 ((0x00000001&(data))>>0)
#define DC_64_DRF_get_DC_DRF_MODE_WRAP0(data)                                 ((0x00000001&(data))>>0)


#define DC_64_DRF_RESUME                                                      0x18007B10
#define DC_64_DRF_RESUME_reg_addr                                             "0xB8007B10"
#define DC_64_DRF_RESUME_reg                                                  0xB8007B10
#define set_DC_64_DRF_RESUME_reg(data)   (*((volatile unsigned int*) DC_64_DRF_RESUME_reg)=data)
#define get_DC_64_DRF_RESUME_reg   (*((volatile unsigned int*) DC_64_DRF_RESUME_reg))
#define DC_64_DRF_RESUME_inst_adr                                             "0x00C4"
#define DC_64_DRF_RESUME_inst                                                 0x00C4
#define DC_64_DRF_RESUME_DC_DRF_RESUME_WRAP2_shift                            (2)
#define DC_64_DRF_RESUME_DC_DRF_RESUME_WRAP2_mask                             (0x00000004)
#define DC_64_DRF_RESUME_DC_DRF_RESUME_WRAP2(data)                            (0x00000004&((data)<<2))
#define DC_64_DRF_RESUME_DC_DRF_RESUME_WRAP2_src(data)                        ((0x00000004&(data))>>2)
#define DC_64_DRF_RESUME_get_DC_DRF_RESUME_WRAP2(data)                        ((0x00000004&(data))>>2)
#define DC_64_DRF_RESUME_DC_DRF_RESUME_WRAP1_shift                            (1)
#define DC_64_DRF_RESUME_DC_DRF_RESUME_WRAP1_mask                             (0x00000002)
#define DC_64_DRF_RESUME_DC_DRF_RESUME_WRAP1(data)                            (0x00000002&((data)<<1))
#define DC_64_DRF_RESUME_DC_DRF_RESUME_WRAP1_src(data)                        ((0x00000002&(data))>>1)
#define DC_64_DRF_RESUME_get_DC_DRF_RESUME_WRAP1(data)                        ((0x00000002&(data))>>1)
#define DC_64_DRF_RESUME_DC_DRF_RESUME_WRAP0_shift                            (0)
#define DC_64_DRF_RESUME_DC_DRF_RESUME_WRAP0_mask                             (0x00000001)
#define DC_64_DRF_RESUME_DC_DRF_RESUME_WRAP0(data)                            (0x00000001&((data)<<0))
#define DC_64_DRF_RESUME_DC_DRF_RESUME_WRAP0_src(data)                        ((0x00000001&(data))>>0)
#define DC_64_DRF_RESUME_get_DC_DRF_RESUME_WRAP0(data)                        ((0x00000001&(data))>>0)


#define DC_64_DRF_DONE                                                        0x18007B14
#define DC_64_DRF_DONE_reg_addr                                               "0xB8007B14"
#define DC_64_DRF_DONE_reg                                                    0xB8007B14
#define set_DC_64_DRF_DONE_reg(data)   (*((volatile unsigned int*) DC_64_DRF_DONE_reg)=data)
#define get_DC_64_DRF_DONE_reg   (*((volatile unsigned int*) DC_64_DRF_DONE_reg))
#define DC_64_DRF_DONE_inst_adr                                               "0x00C5"
#define DC_64_DRF_DONE_inst                                                   0x00C5
#define DC_64_DRF_DONE_DC_DRF_DONE_WRAP2_shift                                (2)
#define DC_64_DRF_DONE_DC_DRF_DONE_WRAP2_mask                                 (0x00000004)
#define DC_64_DRF_DONE_DC_DRF_DONE_WRAP2(data)                                (0x00000004&((data)<<2))
#define DC_64_DRF_DONE_DC_DRF_DONE_WRAP2_src(data)                            ((0x00000004&(data))>>2)
#define DC_64_DRF_DONE_get_DC_DRF_DONE_WRAP2(data)                            ((0x00000004&(data))>>2)
#define DC_64_DRF_DONE_DC_DRF_DONE_WRAP1_shift                                (1)
#define DC_64_DRF_DONE_DC_DRF_DONE_WRAP1_mask                                 (0x00000002)
#define DC_64_DRF_DONE_DC_DRF_DONE_WRAP1(data)                                (0x00000002&((data)<<1))
#define DC_64_DRF_DONE_DC_DRF_DONE_WRAP1_src(data)                            ((0x00000002&(data))>>1)
#define DC_64_DRF_DONE_get_DC_DRF_DONE_WRAP1(data)                            ((0x00000002&(data))>>1)
#define DC_64_DRF_DONE_DC_DRF_DONE_WRAP0_shift                                (0)
#define DC_64_DRF_DONE_DC_DRF_DONE_WRAP0_mask                                 (0x00000001)
#define DC_64_DRF_DONE_DC_DRF_DONE_WRAP0(data)                                (0x00000001&((data)<<0))
#define DC_64_DRF_DONE_DC_DRF_DONE_WRAP0_src(data)                            ((0x00000001&(data))>>0)
#define DC_64_DRF_DONE_get_DC_DRF_DONE_WRAP0(data)                            ((0x00000001&(data))>>0)


#define DC_64_DRF_PAUSE                                                       0x18007B18
#define DC_64_DRF_PAUSE_reg_addr                                              "0xB8007B18"
#define DC_64_DRF_PAUSE_reg                                                   0xB8007B18
#define set_DC_64_DRF_PAUSE_reg(data)   (*((volatile unsigned int*) DC_64_DRF_PAUSE_reg)=data)
#define get_DC_64_DRF_PAUSE_reg   (*((volatile unsigned int*) DC_64_DRF_PAUSE_reg))
#define DC_64_DRF_PAUSE_inst_adr                                              "0x00C6"
#define DC_64_DRF_PAUSE_inst                                                  0x00C6
#define DC_64_DRF_PAUSE_DC_DRF_PAUSE_WRAP2_shift                              (2)
#define DC_64_DRF_PAUSE_DC_DRF_PAUSE_WRAP2_mask                               (0x00000004)
#define DC_64_DRF_PAUSE_DC_DRF_PAUSE_WRAP2(data)                              (0x00000004&((data)<<2))
#define DC_64_DRF_PAUSE_DC_DRF_PAUSE_WRAP2_src(data)                          ((0x00000004&(data))>>2)
#define DC_64_DRF_PAUSE_get_DC_DRF_PAUSE_WRAP2(data)                          ((0x00000004&(data))>>2)
#define DC_64_DRF_PAUSE_DC_DRF_PAUSE_WRAP1_shift                              (1)
#define DC_64_DRF_PAUSE_DC_DRF_PAUSE_WRAP1_mask                               (0x00000002)
#define DC_64_DRF_PAUSE_DC_DRF_PAUSE_WRAP1(data)                              (0x00000002&((data)<<1))
#define DC_64_DRF_PAUSE_DC_DRF_PAUSE_WRAP1_src(data)                          ((0x00000002&(data))>>1)
#define DC_64_DRF_PAUSE_get_DC_DRF_PAUSE_WRAP1(data)                          ((0x00000002&(data))>>1)
#define DC_64_DRF_PAUSE_DC_DRF_PAUSE_WRAP0_shift                              (0)
#define DC_64_DRF_PAUSE_DC_DRF_PAUSE_WRAP0_mask                               (0x00000001)
#define DC_64_DRF_PAUSE_DC_DRF_PAUSE_WRAP0(data)                              (0x00000001&((data)<<0))
#define DC_64_DRF_PAUSE_DC_DRF_PAUSE_WRAP0_src(data)                          ((0x00000001&(data))>>0)
#define DC_64_DRF_PAUSE_get_DC_DRF_PAUSE_WRAP0(data)                          ((0x00000001&(data))>>0)


#define DC_64_DRF_FAIL                                                        0x18007B1C
#define DC_64_DRF_FAIL_reg_addr                                               "0xB8007B1C"
#define DC_64_DRF_FAIL_reg                                                    0xB8007B1C
#define set_DC_64_DRF_FAIL_reg(data)   (*((volatile unsigned int*) DC_64_DRF_FAIL_reg)=data)
#define get_DC_64_DRF_FAIL_reg   (*((volatile unsigned int*) DC_64_DRF_FAIL_reg))
#define DC_64_DRF_FAIL_inst_adr                                               "0x00C7"
#define DC_64_DRF_FAIL_inst                                                   0x00C7
#define DC_64_DRF_FAIL_DC_DRF_FAIL_GROUP_WRAP2_shift                          (2)
#define DC_64_DRF_FAIL_DC_DRF_FAIL_GROUP_WRAP2_mask                           (0x00000004)
#define DC_64_DRF_FAIL_DC_DRF_FAIL_GROUP_WRAP2(data)                          (0x00000004&((data)<<2))
#define DC_64_DRF_FAIL_DC_DRF_FAIL_GROUP_WRAP2_src(data)                      ((0x00000004&(data))>>2)
#define DC_64_DRF_FAIL_get_DC_DRF_FAIL_GROUP_WRAP2(data)                      ((0x00000004&(data))>>2)
#define DC_64_DRF_FAIL_DC_DRF_FAIL_GROUP_WRAP1_shift                          (1)
#define DC_64_DRF_FAIL_DC_DRF_FAIL_GROUP_WRAP1_mask                           (0x00000002)
#define DC_64_DRF_FAIL_DC_DRF_FAIL_GROUP_WRAP1(data)                          (0x00000002&((data)<<1))
#define DC_64_DRF_FAIL_DC_DRF_FAIL_GROUP_WRAP1_src(data)                      ((0x00000002&(data))>>1)
#define DC_64_DRF_FAIL_get_DC_DRF_FAIL_GROUP_WRAP1(data)                      ((0x00000002&(data))>>1)
#define DC_64_DRF_FAIL_DC_DRF_FAIL_GROUP_WRAP0_shift                          (0)
#define DC_64_DRF_FAIL_DC_DRF_FAIL_GROUP_WRAP0_mask                           (0x00000001)
#define DC_64_DRF_FAIL_DC_DRF_FAIL_GROUP_WRAP0(data)                          (0x00000001&((data)<<0))
#define DC_64_DRF_FAIL_DC_DRF_FAIL_GROUP_WRAP0_src(data)                      ((0x00000001&(data))>>0)
#define DC_64_DRF_FAIL_get_DC_DRF_FAIL_GROUP_WRAP0(data)                      ((0x00000001&(data))>>0)


#define DC_64_BIST_DETAIL                                                     0x18007B20
#define DC_64_BIST_DETAIL_reg_addr                                            "0xB8007B20"
#define DC_64_BIST_DETAIL_reg                                                 0xB8007B20
#define set_DC_64_BIST_DETAIL_reg(data)   (*((volatile unsigned int*) DC_64_BIST_DETAIL_reg)=data)
#define get_DC_64_BIST_DETAIL_reg   (*((volatile unsigned int*) DC_64_BIST_DETAIL_reg))
#define DC_64_BIST_DETAIL_inst_adr                                            "0x00C8"
#define DC_64_BIST_DETAIL_inst                                                0x00C8
#define DC_64_BIST_DETAIL_DC_DRF_WRAP2_FAIL_1_shift                           (11)
#define DC_64_BIST_DETAIL_DC_DRF_WRAP2_FAIL_1_mask                            (0x00000800)
#define DC_64_BIST_DETAIL_DC_DRF_WRAP2_FAIL_1(data)                           (0x00000800&((data)<<11))
#define DC_64_BIST_DETAIL_DC_DRF_WRAP2_FAIL_1_src(data)                       ((0x00000800&(data))>>11)
#define DC_64_BIST_DETAIL_get_DC_DRF_WRAP2_FAIL_1(data)                       ((0x00000800&(data))>>11)
#define DC_64_BIST_DETAIL_DC_DRF_WRAP2_FAIL_0_shift                           (10)
#define DC_64_BIST_DETAIL_DC_DRF_WRAP2_FAIL_0_mask                            (0x00000400)
#define DC_64_BIST_DETAIL_DC_DRF_WRAP2_FAIL_0(data)                           (0x00000400&((data)<<10))
#define DC_64_BIST_DETAIL_DC_DRF_WRAP2_FAIL_0_src(data)                       ((0x00000400&(data))>>10)
#define DC_64_BIST_DETAIL_get_DC_DRF_WRAP2_FAIL_0(data)                       ((0x00000400&(data))>>10)
#define DC_64_BIST_DETAIL_DC_BIST_WRAP2_FAIL_1_shift                          (9)
#define DC_64_BIST_DETAIL_DC_BIST_WRAP2_FAIL_1_mask                           (0x00000200)
#define DC_64_BIST_DETAIL_DC_BIST_WRAP2_FAIL_1(data)                          (0x00000200&((data)<<9))
#define DC_64_BIST_DETAIL_DC_BIST_WRAP2_FAIL_1_src(data)                      ((0x00000200&(data))>>9)
#define DC_64_BIST_DETAIL_get_DC_BIST_WRAP2_FAIL_1(data)                      ((0x00000200&(data))>>9)
#define DC_64_BIST_DETAIL_DC_BIST_WRAP2_FAIL_0_shift                          (8)
#define DC_64_BIST_DETAIL_DC_BIST_WRAP2_FAIL_0_mask                           (0x00000100)
#define DC_64_BIST_DETAIL_DC_BIST_WRAP2_FAIL_0(data)                          (0x00000100&((data)<<8))
#define DC_64_BIST_DETAIL_DC_BIST_WRAP2_FAIL_0_src(data)                      ((0x00000100&(data))>>8)
#define DC_64_BIST_DETAIL_get_DC_BIST_WRAP2_FAIL_0(data)                      ((0x00000100&(data))>>8)
#define DC_64_BIST_DETAIL_DC_DRF_WRAP1_FAIL_1_shift                           (7)
#define DC_64_BIST_DETAIL_DC_DRF_WRAP1_FAIL_1_mask                            (0x00000080)
#define DC_64_BIST_DETAIL_DC_DRF_WRAP1_FAIL_1(data)                           (0x00000080&((data)<<7))
#define DC_64_BIST_DETAIL_DC_DRF_WRAP1_FAIL_1_src(data)                       ((0x00000080&(data))>>7)
#define DC_64_BIST_DETAIL_get_DC_DRF_WRAP1_FAIL_1(data)                       ((0x00000080&(data))>>7)
#define DC_64_BIST_DETAIL_DC_DRF_WRAP1_FAIL_0_shift                           (6)
#define DC_64_BIST_DETAIL_DC_DRF_WRAP1_FAIL_0_mask                            (0x00000040)
#define DC_64_BIST_DETAIL_DC_DRF_WRAP1_FAIL_0(data)                           (0x00000040&((data)<<6))
#define DC_64_BIST_DETAIL_DC_DRF_WRAP1_FAIL_0_src(data)                       ((0x00000040&(data))>>6)
#define DC_64_BIST_DETAIL_get_DC_DRF_WRAP1_FAIL_0(data)                       ((0x00000040&(data))>>6)
#define DC_64_BIST_DETAIL_DC_BIST_WRAP1_FAIL_1_shift                          (5)
#define DC_64_BIST_DETAIL_DC_BIST_WRAP1_FAIL_1_mask                           (0x00000020)
#define DC_64_BIST_DETAIL_DC_BIST_WRAP1_FAIL_1(data)                          (0x00000020&((data)<<5))
#define DC_64_BIST_DETAIL_DC_BIST_WRAP1_FAIL_1_src(data)                      ((0x00000020&(data))>>5)
#define DC_64_BIST_DETAIL_get_DC_BIST_WRAP1_FAIL_1(data)                      ((0x00000020&(data))>>5)
#define DC_64_BIST_DETAIL_DC_BIST_WRAP1_FAIL_0_shift                          (4)
#define DC_64_BIST_DETAIL_DC_BIST_WRAP1_FAIL_0_mask                           (0x00000010)
#define DC_64_BIST_DETAIL_DC_BIST_WRAP1_FAIL_0(data)                          (0x00000010&((data)<<4))
#define DC_64_BIST_DETAIL_DC_BIST_WRAP1_FAIL_0_src(data)                      ((0x00000010&(data))>>4)
#define DC_64_BIST_DETAIL_get_DC_BIST_WRAP1_FAIL_0(data)                      ((0x00000010&(data))>>4)
#define DC_64_BIST_DETAIL_DC_DRF_WRAP0_FAIL_1_shift                           (3)
#define DC_64_BIST_DETAIL_DC_DRF_WRAP0_FAIL_1_mask                            (0x00000008)
#define DC_64_BIST_DETAIL_DC_DRF_WRAP0_FAIL_1(data)                           (0x00000008&((data)<<3))
#define DC_64_BIST_DETAIL_DC_DRF_WRAP0_FAIL_1_src(data)                       ((0x00000008&(data))>>3)
#define DC_64_BIST_DETAIL_get_DC_DRF_WRAP0_FAIL_1(data)                       ((0x00000008&(data))>>3)
#define DC_64_BIST_DETAIL_DC_DRF_WRAP0_FAIL_0_shift                           (2)
#define DC_64_BIST_DETAIL_DC_DRF_WRAP0_FAIL_0_mask                            (0x00000004)
#define DC_64_BIST_DETAIL_DC_DRF_WRAP0_FAIL_0(data)                           (0x00000004&((data)<<2))
#define DC_64_BIST_DETAIL_DC_DRF_WRAP0_FAIL_0_src(data)                       ((0x00000004&(data))>>2)
#define DC_64_BIST_DETAIL_get_DC_DRF_WRAP0_FAIL_0(data)                       ((0x00000004&(data))>>2)
#define DC_64_BIST_DETAIL_DC_BIST_WRAP0_FAIL_1_shift                          (1)
#define DC_64_BIST_DETAIL_DC_BIST_WRAP0_FAIL_1_mask                           (0x00000002)
#define DC_64_BIST_DETAIL_DC_BIST_WRAP0_FAIL_1(data)                          (0x00000002&((data)<<1))
#define DC_64_BIST_DETAIL_DC_BIST_WRAP0_FAIL_1_src(data)                      ((0x00000002&(data))>>1)
#define DC_64_BIST_DETAIL_get_DC_BIST_WRAP0_FAIL_1(data)                      ((0x00000002&(data))>>1)
#define DC_64_BIST_DETAIL_DC_BIST_WRAP0_FAIL_0_shift                          (0)
#define DC_64_BIST_DETAIL_DC_BIST_WRAP0_FAIL_0_mask                           (0x00000001)
#define DC_64_BIST_DETAIL_DC_BIST_WRAP0_FAIL_0(data)                          (0x00000001&((data)<<0))
#define DC_64_BIST_DETAIL_DC_BIST_WRAP0_FAIL_0_src(data)                      ((0x00000001&(data))>>0)
#define DC_64_BIST_DETAIL_get_DC_BIST_WRAP0_FAIL_0(data)                      ((0x00000001&(data))>>0)


#define DC_64_BIST_RM                                                         0x18007B24
#define DC_64_BIST_RM_reg_addr                                                "0xB8007B24"
#define DC_64_BIST_RM_reg                                                     0xB8007B24
#define set_DC_64_BIST_RM_reg(data)   (*((volatile unsigned int*) DC_64_BIST_RM_reg)=data)
#define get_DC_64_BIST_RM_reg   (*((volatile unsigned int*) DC_64_BIST_RM_reg))
#define DC_64_BIST_RM_inst_adr                                                "0x00C9"
#define DC_64_BIST_RM_inst                                                    0x00C9
#define DC_64_BIST_RM_RMEA_shift                                              (20)
#define DC_64_BIST_RM_RMEA_mask                                               (0x00100000)
#define DC_64_BIST_RM_RMEA(data)                                              (0x00100000&((data)<<20))
#define DC_64_BIST_RM_RMEA_src(data)                                          ((0x00100000&(data))>>20)
#define DC_64_BIST_RM_get_RMEA(data)                                          ((0x00100000&(data))>>20)
#define DC_64_BIST_RM_RMA_shift                                               (16)
#define DC_64_BIST_RM_RMA_mask                                                (0x000F0000)
#define DC_64_BIST_RM_RMA(data)                                               (0x000F0000&((data)<<16))
#define DC_64_BIST_RM_RMA_src(data)                                           ((0x000F0000&(data))>>16)
#define DC_64_BIST_RM_get_RMA(data)                                           ((0x000F0000&(data))>>16)
#define DC_64_BIST_RM_RMEB_shift                                              (12)
#define DC_64_BIST_RM_RMEB_mask                                               (0x00001000)
#define DC_64_BIST_RM_RMEB(data)                                              (0x00001000&((data)<<12))
#define DC_64_BIST_RM_RMEB_src(data)                                          ((0x00001000&(data))>>12)
#define DC_64_BIST_RM_get_RMEB(data)                                          ((0x00001000&(data))>>12)
#define DC_64_BIST_RM_RMB_shift                                               (8)
#define DC_64_BIST_RM_RMB_mask                                                (0x00000F00)
#define DC_64_BIST_RM_RMB(data)                                               (0x00000F00&((data)<<8))
#define DC_64_BIST_RM_RMB_src(data)                                           ((0x00000F00&(data))>>8)
#define DC_64_BIST_RM_get_RMB(data)                                           ((0x00000F00&(data))>>8)


#define DC_64_PC_CTRL                                                         0x180071B0
#define DC_64_PC_CTRL_reg_addr                                                "0xB80071B0"
#define DC_64_PC_CTRL_reg                                                     0xB80071B0
#define set_DC_64_PC_CTRL_reg(data)   (*((volatile unsigned int*) DC_64_PC_CTRL_reg)=data)
#define get_DC_64_PC_CTRL_reg   (*((volatile unsigned int*) DC_64_PC_CTRL_reg))
#define DC_64_PC_CTRL_inst_adr                                                "0x006C"
#define DC_64_PC_CTRL_inst                                                    0x006C
#define DC_64_PC_CTRL_pc_go_shift                                             (0)
#define DC_64_PC_CTRL_pc_go_mask                                              (0x00000001)
#define DC_64_PC_CTRL_pc_go(data)                                             (0x00000001&((data)<<0))
#define DC_64_PC_CTRL_pc_go_src(data)                                         ((0x00000001&(data))>>0)
#define DC_64_PC_CTRL_get_pc_go(data)                                         ((0x00000001&(data))>>0)


#define DC_PC_SYS_PROG_CTRL                                                   0x18007114
#define DC_PC_SYS_PROG_CTRL_reg_addr                                          "0xB8007114"
#define DC_PC_SYS_PROG_CTRL_reg                                               0xB8007114
#define set_DC_PC_SYS_PROG_CTRL_reg(data)   (*((volatile unsigned int*) DC_PC_SYS_PROG_CTRL_reg)=data)
#define get_DC_PC_SYS_PROG_CTRL_reg   (*((volatile unsigned int*) DC_PC_SYS_PROG_CTRL_reg))
#define DC_PC_SYS_PROG_CTRL_inst_adr                                          "0x0045"
#define DC_PC_SYS_PROG_CTRL_inst                                              0x0045
#define DC_PC_SYS_PROG_CTRL_write_en_3_shift                                  (23)
#define DC_PC_SYS_PROG_CTRL_write_en_3_mask                                   (0x00800000)
#define DC_PC_SYS_PROG_CTRL_write_en_3(data)                                  (0x00800000&((data)<<23))
#define DC_PC_SYS_PROG_CTRL_write_en_3_src(data)                              ((0x00800000&(data))>>23)
#define DC_PC_SYS_PROG_CTRL_get_write_en_3(data)                              ((0x00800000&(data))>>23)
#define DC_PC_SYS_PROG_CTRL_pc_sys_prog2_sel_shift                            (16)
#define DC_PC_SYS_PROG_CTRL_pc_sys_prog2_sel_mask                             (0x007F0000)
#define DC_PC_SYS_PROG_CTRL_pc_sys_prog2_sel(data)                            (0x007F0000&((data)<<16))
#define DC_PC_SYS_PROG_CTRL_pc_sys_prog2_sel_src(data)                        ((0x007F0000&(data))>>16)
#define DC_PC_SYS_PROG_CTRL_get_pc_sys_prog2_sel(data)                        ((0x007F0000&(data))>>16)
#define DC_PC_SYS_PROG_CTRL_write_en_2_shift                                  (15)
#define DC_PC_SYS_PROG_CTRL_write_en_2_mask                                   (0x00008000)
#define DC_PC_SYS_PROG_CTRL_write_en_2(data)                                  (0x00008000&((data)<<15))
#define DC_PC_SYS_PROG_CTRL_write_en_2_src(data)                              ((0x00008000&(data))>>15)
#define DC_PC_SYS_PROG_CTRL_get_write_en_2(data)                              ((0x00008000&(data))>>15)
#define DC_PC_SYS_PROG_CTRL_pc_sys_prog1_sel_shift                            (8)
#define DC_PC_SYS_PROG_CTRL_pc_sys_prog1_sel_mask                             (0x00007F00)
#define DC_PC_SYS_PROG_CTRL_pc_sys_prog1_sel(data)                            (0x00007F00&((data)<<8))
#define DC_PC_SYS_PROG_CTRL_pc_sys_prog1_sel_src(data)                        ((0x00007F00&(data))>>8)
#define DC_PC_SYS_PROG_CTRL_get_pc_sys_prog1_sel(data)                        ((0x00007F00&(data))>>8)
#define DC_PC_SYS_PROG_CTRL_write_en_1_shift                                  (7)
#define DC_PC_SYS_PROG_CTRL_write_en_1_mask                                   (0x00000080)
#define DC_PC_SYS_PROG_CTRL_write_en_1(data)                                  (0x00000080&((data)<<7))
#define DC_PC_SYS_PROG_CTRL_write_en_1_src(data)                              ((0x00000080&(data))>>7)
#define DC_PC_SYS_PROG_CTRL_get_write_en_1(data)                              ((0x00000080&(data))>>7)
#define DC_PC_SYS_PROG_CTRL_pc_sys_prog0_sel_shift                            (0)
#define DC_PC_SYS_PROG_CTRL_pc_sys_prog0_sel_mask                             (0x0000007F)
#define DC_PC_SYS_PROG_CTRL_pc_sys_prog0_sel(data)                            (0x0000007F&((data)<<0))
#define DC_PC_SYS_PROG_CTRL_pc_sys_prog0_sel_src(data)                        ((0x0000007F&(data))>>0)
#define DC_PC_SYS_PROG_CTRL_get_pc_sys_prog0_sel(data)                        ((0x0000007F&(data))>>0)


#define DC_64_PC_SYS_PROG_CTRL1                                               0x180071B4
#define DC_64_PC_SYS_PROG_CTRL1_reg_addr                                      "0xB80071B4"
#define DC_64_PC_SYS_PROG_CTRL1_reg                                           0xB80071B4
#define set_DC_64_PC_SYS_PROG_CTRL1_reg(data)   (*((volatile unsigned int*) DC_64_PC_SYS_PROG_CTRL1_reg)=data)
#define get_DC_64_PC_SYS_PROG_CTRL1_reg   (*((volatile unsigned int*) DC_64_PC_SYS_PROG_CTRL1_reg))
#define DC_64_PC_SYS_PROG_CTRL1_inst_adr                                      "0x006D"
#define DC_64_PC_SYS_PROG_CTRL1_inst                                          0x006D
#define DC_64_PC_SYS_PROG_CTRL1_pc_sys_prog2_req_occur_shift                  (2)
#define DC_64_PC_SYS_PROG_CTRL1_pc_sys_prog2_req_occur_mask                   (0x00000004)
#define DC_64_PC_SYS_PROG_CTRL1_pc_sys_prog2_req_occur(data)                  (0x00000004&((data)<<2))
#define DC_64_PC_SYS_PROG_CTRL1_pc_sys_prog2_req_occur_src(data)              ((0x00000004&(data))>>2)
#define DC_64_PC_SYS_PROG_CTRL1_get_pc_sys_prog2_req_occur(data)              ((0x00000004&(data))>>2)
#define DC_64_PC_SYS_PROG_CTRL1_pc_sys_prog1_req_occur_shift                  (1)
#define DC_64_PC_SYS_PROG_CTRL1_pc_sys_prog1_req_occur_mask                   (0x00000002)
#define DC_64_PC_SYS_PROG_CTRL1_pc_sys_prog1_req_occur(data)                  (0x00000002&((data)<<1))
#define DC_64_PC_SYS_PROG_CTRL1_pc_sys_prog1_req_occur_src(data)              ((0x00000002&(data))>>1)
#define DC_64_PC_SYS_PROG_CTRL1_get_pc_sys_prog1_req_occur(data)              ((0x00000002&(data))>>1)
#define DC_64_PC_SYS_PROG_CTRL1_pc_sys_prog0_req_occur_shift                  (0)
#define DC_64_PC_SYS_PROG_CTRL1_pc_sys_prog0_req_occur_mask                   (0x00000001)
#define DC_64_PC_SYS_PROG_CTRL1_pc_sys_prog0_req_occur(data)                  (0x00000001&((data)<<0))
#define DC_64_PC_SYS_PROG_CTRL1_pc_sys_prog0_req_occur_src(data)              ((0x00000001&(data))>>0)
#define DC_64_PC_SYS_PROG_CTRL1_get_pc_sys_prog0_req_occur(data)              ((0x00000001&(data))>>0)


#define DC_PC_SYS_PROG_0_ACC_LAT                                              0x18007160
#define DC_PC_SYS_PROG_0_ACC_LAT_reg_addr                                     "0xB8007160"
#define DC_PC_SYS_PROG_0_ACC_LAT_reg                                          0xB8007160
#define set_DC_PC_SYS_PROG_0_ACC_LAT_reg(data)   (*((volatile unsigned int*) DC_PC_SYS_PROG_0_ACC_LAT_reg)=data)
#define get_DC_PC_SYS_PROG_0_ACC_LAT_reg   (*((volatile unsigned int*) DC_PC_SYS_PROG_0_ACC_LAT_reg))
#define DC_PC_SYS_PROG_0_ACC_LAT_inst_adr                                     "0x0058"
#define DC_PC_SYS_PROG_0_ACC_LAT_inst                                         0x0058
#define DC_PC_SYS_PROG_0_ACC_LAT_sys_prog0_acc_lat_shift                      (0)
#define DC_PC_SYS_PROG_0_ACC_LAT_sys_prog0_acc_lat_mask                       (0xFFFFFFFF)
#define DC_PC_SYS_PROG_0_ACC_LAT_sys_prog0_acc_lat(data)                      (0xFFFFFFFF&((data)<<0))
#define DC_PC_SYS_PROG_0_ACC_LAT_sys_prog0_acc_lat_src(data)                  ((0xFFFFFFFF&(data))>>0)
#define DC_PC_SYS_PROG_0_ACC_LAT_get_sys_prog0_acc_lat(data)                  ((0xFFFFFFFF&(data))>>0)


#define DC_PC_SYS_PROG_0_MAX_LAT                                              0x18007164
#define DC_PC_SYS_PROG_0_MAX_LAT_reg_addr                                     "0xB8007164"
#define DC_PC_SYS_PROG_0_MAX_LAT_reg                                          0xB8007164
#define set_DC_PC_SYS_PROG_0_MAX_LAT_reg(data)   (*((volatile unsigned int*) DC_PC_SYS_PROG_0_MAX_LAT_reg)=data)
#define get_DC_PC_SYS_PROG_0_MAX_LAT_reg   (*((volatile unsigned int*) DC_PC_SYS_PROG_0_MAX_LAT_reg))
#define DC_PC_SYS_PROG_0_MAX_LAT_inst_adr                                     "0x0059"
#define DC_PC_SYS_PROG_0_MAX_LAT_inst                                         0x0059
#define DC_PC_SYS_PROG_0_MAX_LAT_sys_prog0_max_lat_shift                      (0)
#define DC_PC_SYS_PROG_0_MAX_LAT_sys_prog0_max_lat_mask                       (0x0000FFFF)
#define DC_PC_SYS_PROG_0_MAX_LAT_sys_prog0_max_lat(data)                      (0x0000FFFF&((data)<<0))
#define DC_PC_SYS_PROG_0_MAX_LAT_sys_prog0_max_lat_src(data)                  ((0x0000FFFF&(data))>>0)
#define DC_PC_SYS_PROG_0_MAX_LAT_get_sys_prog0_max_lat(data)                  ((0x0000FFFF&(data))>>0)


#define DC_PC_SYS_PROG_0_REQ_NUM                                              0x18007168
#define DC_PC_SYS_PROG_0_REQ_NUM_reg_addr                                     "0xB8007168"
#define DC_PC_SYS_PROG_0_REQ_NUM_reg                                          0xB8007168
#define set_DC_PC_SYS_PROG_0_REQ_NUM_reg(data)   (*((volatile unsigned int*) DC_PC_SYS_PROG_0_REQ_NUM_reg)=data)
#define get_DC_PC_SYS_PROG_0_REQ_NUM_reg   (*((volatile unsigned int*) DC_PC_SYS_PROG_0_REQ_NUM_reg))
#define DC_PC_SYS_PROG_0_REQ_NUM_inst_adr                                     "0x005A"
#define DC_PC_SYS_PROG_0_REQ_NUM_inst                                         0x005A
#define DC_PC_SYS_PROG_0_REQ_NUM_sys_prog0_req_num_shift                      (0)
#define DC_PC_SYS_PROG_0_REQ_NUM_sys_prog0_req_num_mask                       (0x00FFFFFF)
#define DC_PC_SYS_PROG_0_REQ_NUM_sys_prog0_req_num(data)                      (0x00FFFFFF&((data)<<0))
#define DC_PC_SYS_PROG_0_REQ_NUM_sys_prog0_req_num_src(data)                  ((0x00FFFFFF&(data))>>0)
#define DC_PC_SYS_PROG_0_REQ_NUM_get_sys_prog0_req_num(data)                  ((0x00FFFFFF&(data))>>0)


#define DC_PC_SYS_PROG_0_ACK_NUM                                              0x1800716C
#define DC_PC_SYS_PROG_0_ACK_NUM_reg_addr                                     "0xB800716C"
#define DC_PC_SYS_PROG_0_ACK_NUM_reg                                          0xB800716C
#define set_DC_PC_SYS_PROG_0_ACK_NUM_reg(data)   (*((volatile unsigned int*) DC_PC_SYS_PROG_0_ACK_NUM_reg)=data)
#define get_DC_PC_SYS_PROG_0_ACK_NUM_reg   (*((volatile unsigned int*) DC_PC_SYS_PROG_0_ACK_NUM_reg))
#define DC_PC_SYS_PROG_0_ACK_NUM_inst_adr                                     "0x005B"
#define DC_PC_SYS_PROG_0_ACK_NUM_inst                                         0x005B
#define DC_PC_SYS_PROG_0_ACK_NUM_sys_prog0_ack_num_shift                      (0)
#define DC_PC_SYS_PROG_0_ACK_NUM_sys_prog0_ack_num_mask                       (0xFFFFFFFF)
#define DC_PC_SYS_PROG_0_ACK_NUM_sys_prog0_ack_num(data)                      (0xFFFFFFFF&((data)<<0))
#define DC_PC_SYS_PROG_0_ACK_NUM_sys_prog0_ack_num_src(data)                  ((0xFFFFFFFF&(data))>>0)
#define DC_PC_SYS_PROG_0_ACK_NUM_get_sys_prog0_ack_num(data)                  ((0xFFFFFFFF&(data))>>0)


#define DC_PC_SYS_PROG_1_ACC_LAT                                              0x18007170
#define DC_PC_SYS_PROG_1_ACC_LAT_reg_addr                                     "0xB8007170"
#define DC_PC_SYS_PROG_1_ACC_LAT_reg                                          0xB8007170
#define set_DC_PC_SYS_PROG_1_ACC_LAT_reg(data)   (*((volatile unsigned int*) DC_PC_SYS_PROG_1_ACC_LAT_reg)=data)
#define get_DC_PC_SYS_PROG_1_ACC_LAT_reg   (*((volatile unsigned int*) DC_PC_SYS_PROG_1_ACC_LAT_reg))
#define DC_PC_SYS_PROG_1_ACC_LAT_inst_adr                                     "0x005C"
#define DC_PC_SYS_PROG_1_ACC_LAT_inst                                         0x005C
#define DC_PC_SYS_PROG_1_ACC_LAT_sys_prog1_acc_lat_shift                      (0)
#define DC_PC_SYS_PROG_1_ACC_LAT_sys_prog1_acc_lat_mask                       (0xFFFFFFFF)
#define DC_PC_SYS_PROG_1_ACC_LAT_sys_prog1_acc_lat(data)                      (0xFFFFFFFF&((data)<<0))
#define DC_PC_SYS_PROG_1_ACC_LAT_sys_prog1_acc_lat_src(data)                  ((0xFFFFFFFF&(data))>>0)
#define DC_PC_SYS_PROG_1_ACC_LAT_get_sys_prog1_acc_lat(data)                  ((0xFFFFFFFF&(data))>>0)


#define DC_PC_SYS_PROG_1_MAX_LAT                                              0x18007174
#define DC_PC_SYS_PROG_1_MAX_LAT_reg_addr                                     "0xB8007174"
#define DC_PC_SYS_PROG_1_MAX_LAT_reg                                          0xB8007174
#define set_DC_PC_SYS_PROG_1_MAX_LAT_reg(data)   (*((volatile unsigned int*) DC_PC_SYS_PROG_1_MAX_LAT_reg)=data)
#define get_DC_PC_SYS_PROG_1_MAX_LAT_reg   (*((volatile unsigned int*) DC_PC_SYS_PROG_1_MAX_LAT_reg))
#define DC_PC_SYS_PROG_1_MAX_LAT_inst_adr                                     "0x005D"
#define DC_PC_SYS_PROG_1_MAX_LAT_inst                                         0x005D
#define DC_PC_SYS_PROG_1_MAX_LAT_sys_prog1_max_lat_shift                      (0)
#define DC_PC_SYS_PROG_1_MAX_LAT_sys_prog1_max_lat_mask                       (0x0000FFFF)
#define DC_PC_SYS_PROG_1_MAX_LAT_sys_prog1_max_lat(data)                      (0x0000FFFF&((data)<<0))
#define DC_PC_SYS_PROG_1_MAX_LAT_sys_prog1_max_lat_src(data)                  ((0x0000FFFF&(data))>>0)
#define DC_PC_SYS_PROG_1_MAX_LAT_get_sys_prog1_max_lat(data)                  ((0x0000FFFF&(data))>>0)


#define DC_PC_SYS_PROG_1_REQ_NUM                                              0x18007178
#define DC_PC_SYS_PROG_1_REQ_NUM_reg_addr                                     "0xB8007178"
#define DC_PC_SYS_PROG_1_REQ_NUM_reg                                          0xB8007178
#define set_DC_PC_SYS_PROG_1_REQ_NUM_reg(data)   (*((volatile unsigned int*) DC_PC_SYS_PROG_1_REQ_NUM_reg)=data)
#define get_DC_PC_SYS_PROG_1_REQ_NUM_reg   (*((volatile unsigned int*) DC_PC_SYS_PROG_1_REQ_NUM_reg))
#define DC_PC_SYS_PROG_1_REQ_NUM_inst_adr                                     "0x005E"
#define DC_PC_SYS_PROG_1_REQ_NUM_inst                                         0x005E
#define DC_PC_SYS_PROG_1_REQ_NUM_sys_prog1_req_num_shift                      (0)
#define DC_PC_SYS_PROG_1_REQ_NUM_sys_prog1_req_num_mask                       (0x00FFFFFF)
#define DC_PC_SYS_PROG_1_REQ_NUM_sys_prog1_req_num(data)                      (0x00FFFFFF&((data)<<0))
#define DC_PC_SYS_PROG_1_REQ_NUM_sys_prog1_req_num_src(data)                  ((0x00FFFFFF&(data))>>0)
#define DC_PC_SYS_PROG_1_REQ_NUM_get_sys_prog1_req_num(data)                  ((0x00FFFFFF&(data))>>0)


#define DC_PC_SYS_PROG_1_ACK_NUM                                              0x1800717C
#define DC_PC_SYS_PROG_1_ACK_NUM_reg_addr                                     "0xB800717C"
#define DC_PC_SYS_PROG_1_ACK_NUM_reg                                          0xB800717C
#define set_DC_PC_SYS_PROG_1_ACK_NUM_reg(data)   (*((volatile unsigned int*) DC_PC_SYS_PROG_1_ACK_NUM_reg)=data)
#define get_DC_PC_SYS_PROG_1_ACK_NUM_reg   (*((volatile unsigned int*) DC_PC_SYS_PROG_1_ACK_NUM_reg))
#define DC_PC_SYS_PROG_1_ACK_NUM_inst_adr                                     "0x005F"
#define DC_PC_SYS_PROG_1_ACK_NUM_inst                                         0x005F
#define DC_PC_SYS_PROG_1_ACK_NUM_sys_prog1_ack_num_shift                      (0)
#define DC_PC_SYS_PROG_1_ACK_NUM_sys_prog1_ack_num_mask                       (0xFFFFFFFF)
#define DC_PC_SYS_PROG_1_ACK_NUM_sys_prog1_ack_num(data)                      (0xFFFFFFFF&((data)<<0))
#define DC_PC_SYS_PROG_1_ACK_NUM_sys_prog1_ack_num_src(data)                  ((0xFFFFFFFF&(data))>>0)
#define DC_PC_SYS_PROG_1_ACK_NUM_get_sys_prog1_ack_num(data)                  ((0xFFFFFFFF&(data))>>0)


#define DC_PC_SYS_PROG_2_ACC_LAT                                              0x18007180
#define DC_PC_SYS_PROG_2_ACC_LAT_reg_addr                                     "0xB8007180"
#define DC_PC_SYS_PROG_2_ACC_LAT_reg                                          0xB8007180
#define set_DC_PC_SYS_PROG_2_ACC_LAT_reg(data)   (*((volatile unsigned int*) DC_PC_SYS_PROG_2_ACC_LAT_reg)=data)
#define get_DC_PC_SYS_PROG_2_ACC_LAT_reg   (*((volatile unsigned int*) DC_PC_SYS_PROG_2_ACC_LAT_reg))
#define DC_PC_SYS_PROG_2_ACC_LAT_inst_adr                                     "0x0060"
#define DC_PC_SYS_PROG_2_ACC_LAT_inst                                         0x0060
#define DC_PC_SYS_PROG_2_ACC_LAT_sys_prog2_acc_lat_shift                      (0)
#define DC_PC_SYS_PROG_2_ACC_LAT_sys_prog2_acc_lat_mask                       (0xFFFFFFFF)
#define DC_PC_SYS_PROG_2_ACC_LAT_sys_prog2_acc_lat(data)                      (0xFFFFFFFF&((data)<<0))
#define DC_PC_SYS_PROG_2_ACC_LAT_sys_prog2_acc_lat_src(data)                  ((0xFFFFFFFF&(data))>>0)
#define DC_PC_SYS_PROG_2_ACC_LAT_get_sys_prog2_acc_lat(data)                  ((0xFFFFFFFF&(data))>>0)


#define DC_PC_SYS_PROG_2_MAX_LAT                                              0x18007184
#define DC_PC_SYS_PROG_2_MAX_LAT_reg_addr                                     "0xB8007184"
#define DC_PC_SYS_PROG_2_MAX_LAT_reg                                          0xB8007184
#define set_DC_PC_SYS_PROG_2_MAX_LAT_reg(data)   (*((volatile unsigned int*) DC_PC_SYS_PROG_2_MAX_LAT_reg)=data)
#define get_DC_PC_SYS_PROG_2_MAX_LAT_reg   (*((volatile unsigned int*) DC_PC_SYS_PROG_2_MAX_LAT_reg))
#define DC_PC_SYS_PROG_2_MAX_LAT_inst_adr                                     "0x0061"
#define DC_PC_SYS_PROG_2_MAX_LAT_inst                                         0x0061
#define DC_PC_SYS_PROG_2_MAX_LAT_sys_prog2_max_lat_shift                      (0)
#define DC_PC_SYS_PROG_2_MAX_LAT_sys_prog2_max_lat_mask                       (0x0000FFFF)
#define DC_PC_SYS_PROG_2_MAX_LAT_sys_prog2_max_lat(data)                      (0x0000FFFF&((data)<<0))
#define DC_PC_SYS_PROG_2_MAX_LAT_sys_prog2_max_lat_src(data)                  ((0x0000FFFF&(data))>>0)
#define DC_PC_SYS_PROG_2_MAX_LAT_get_sys_prog2_max_lat(data)                  ((0x0000FFFF&(data))>>0)


#define DC_PC_SYS_PROG_2_REQ_NUM                                              0x18007188
#define DC_PC_SYS_PROG_2_REQ_NUM_reg_addr                                     "0xB8007188"
#define DC_PC_SYS_PROG_2_REQ_NUM_reg                                          0xB8007188
#define set_DC_PC_SYS_PROG_2_REQ_NUM_reg(data)   (*((volatile unsigned int*) DC_PC_SYS_PROG_2_REQ_NUM_reg)=data)
#define get_DC_PC_SYS_PROG_2_REQ_NUM_reg   (*((volatile unsigned int*) DC_PC_SYS_PROG_2_REQ_NUM_reg))
#define DC_PC_SYS_PROG_2_REQ_NUM_inst_adr                                     "0x0062"
#define DC_PC_SYS_PROG_2_REQ_NUM_inst                                         0x0062
#define DC_PC_SYS_PROG_2_REQ_NUM_sys_prog2_req_num_shift                      (0)
#define DC_PC_SYS_PROG_2_REQ_NUM_sys_prog2_req_num_mask                       (0x00FFFFFF)
#define DC_PC_SYS_PROG_2_REQ_NUM_sys_prog2_req_num(data)                      (0x00FFFFFF&((data)<<0))
#define DC_PC_SYS_PROG_2_REQ_NUM_sys_prog2_req_num_src(data)                  ((0x00FFFFFF&(data))>>0)
#define DC_PC_SYS_PROG_2_REQ_NUM_get_sys_prog2_req_num(data)                  ((0x00FFFFFF&(data))>>0)


#define DC_PC_SYS_PROG_2_ACK_NUM                                              0x1800718C
#define DC_PC_SYS_PROG_2_ACK_NUM_reg_addr                                     "0xB800718C"
#define DC_PC_SYS_PROG_2_ACK_NUM_reg                                          0xB800718C
#define set_DC_PC_SYS_PROG_2_ACK_NUM_reg(data)   (*((volatile unsigned int*) DC_PC_SYS_PROG_2_ACK_NUM_reg)=data)
#define get_DC_PC_SYS_PROG_2_ACK_NUM_reg   (*((volatile unsigned int*) DC_PC_SYS_PROG_2_ACK_NUM_reg))
#define DC_PC_SYS_PROG_2_ACK_NUM_inst_adr                                     "0x0063"
#define DC_PC_SYS_PROG_2_ACK_NUM_inst                                         0x0063
#define DC_PC_SYS_PROG_2_ACK_NUM_sys_prog2_ack_num_shift                      (0)
#define DC_PC_SYS_PROG_2_ACK_NUM_sys_prog2_ack_num_mask                       (0xFFFFFFFF)
#define DC_PC_SYS_PROG_2_ACK_NUM_sys_prog2_ack_num(data)                      (0xFFFFFFFF&((data)<<0))
#define DC_PC_SYS_PROG_2_ACK_NUM_sys_prog2_ack_num_src(data)                  ((0xFFFFFFFF&(data))>>0)
#define DC_PC_SYS_PROG_2_ACK_NUM_get_sys_prog2_ack_num(data)                  ((0xFFFFFFFF&(data))>>0)


#define DC_PC_SYS_PROG_0                                                      0x180071A0
#define DC_PC_SYS_PROG_0_reg_addr                                             "0xB80071A0"
#define DC_PC_SYS_PROG_0_reg                                                  0xB80071A0
#define set_DC_PC_SYS_PROG_0_reg(data)   (*((volatile unsigned int*) DC_PC_SYS_PROG_0_reg)=data)
#define get_DC_PC_SYS_PROG_0_reg   (*((volatile unsigned int*) DC_PC_SYS_PROG_0_reg))
#define DC_PC_SYS_PROG_0_inst_adr                                             "0x0068"
#define DC_PC_SYS_PROG_0_inst                                                 0x0068
#define DC_PC_SYS_PROG_0_sys0_hitend_cnt_shift                                (0)
#define DC_PC_SYS_PROG_0_sys0_hitend_cnt_mask                                 (0x0000FFFF)
#define DC_PC_SYS_PROG_0_sys0_hitend_cnt(data)                                (0x0000FFFF&((data)<<0))
#define DC_PC_SYS_PROG_0_sys0_hitend_cnt_src(data)                            ((0x0000FFFF&(data))>>0)
#define DC_PC_SYS_PROG_0_get_sys0_hitend_cnt(data)                            ((0x0000FFFF&(data))>>0)


#define DC_PC_SYS_PROG_1                                                      0x180071A4
#define DC_PC_SYS_PROG_1_reg_addr                                             "0xB80071A4"
#define DC_PC_SYS_PROG_1_reg                                                  0xB80071A4
#define set_DC_PC_SYS_PROG_1_reg(data)   (*((volatile unsigned int*) DC_PC_SYS_PROG_1_reg)=data)
#define get_DC_PC_SYS_PROG_1_reg   (*((volatile unsigned int*) DC_PC_SYS_PROG_1_reg))
#define DC_PC_SYS_PROG_1_inst_adr                                             "0x0069"
#define DC_PC_SYS_PROG_1_inst                                                 0x0069
#define DC_PC_SYS_PROG_1_sys1_hitend_cnt_shift                                (0)
#define DC_PC_SYS_PROG_1_sys1_hitend_cnt_mask                                 (0x0000FFFF)
#define DC_PC_SYS_PROG_1_sys1_hitend_cnt(data)                                (0x0000FFFF&((data)<<0))
#define DC_PC_SYS_PROG_1_sys1_hitend_cnt_src(data)                            ((0x0000FFFF&(data))>>0)
#define DC_PC_SYS_PROG_1_get_sys1_hitend_cnt(data)                            ((0x0000FFFF&(data))>>0)


#define DC_PC_SYS_PROG_2                                                      0x180071A8
#define DC_PC_SYS_PROG_2_reg_addr                                             "0xB80071A8"
#define DC_PC_SYS_PROG_2_reg                                                  0xB80071A8
#define set_DC_PC_SYS_PROG_2_reg(data)   (*((volatile unsigned int*) DC_PC_SYS_PROG_2_reg)=data)
#define get_DC_PC_SYS_PROG_2_reg   (*((volatile unsigned int*) DC_PC_SYS_PROG_2_reg))
#define DC_PC_SYS_PROG_2_inst_adr                                             "0x006A"
#define DC_PC_SYS_PROG_2_inst                                                 0x006A
#define DC_PC_SYS_PROG_2_sys2_hitend_cnt_shift                                (0)
#define DC_PC_SYS_PROG_2_sys2_hitend_cnt_mask                                 (0x0000FFFF)
#define DC_PC_SYS_PROG_2_sys2_hitend_cnt(data)                                (0x0000FFFF&((data)<<0))
#define DC_PC_SYS_PROG_2_sys2_hitend_cnt_src(data)                            ((0x0000FFFF&(data))>>0)
#define DC_PC_SYS_PROG_2_get_sys2_hitend_cnt(data)                            ((0x0000FFFF&(data))>>0)


#define EXSRAM_CTRL                                                           0x18007500
#define EXSRAM_CTRL_reg_addr                                                  "0xB8007500"
#define EXSRAM_CTRL_reg                                                       0xB8007500
#define set_EXSRAM_CTRL_reg(data)   (*((volatile unsigned int*) EXSRAM_CTRL_reg)=data)
#define get_EXSRAM_CTRL_reg   (*((volatile unsigned int*) EXSRAM_CTRL_reg))
#define EXSRAM_CTRL_inst_adr                                                  "0x0040"
#define EXSRAM_CTRL_inst                                                      0x0040
#define EXSRAM_CTRL_enable_shift                                              (0)
#define EXSRAM_CTRL_enable_mask                                               (0x00000001)
#define EXSRAM_CTRL_enable(data)                                              (0x00000001&((data)<<0))
#define EXSRAM_CTRL_enable_src(data)                                          ((0x00000001&(data))>>0)
#define EXSRAM_CTRL_get_enable(data)                                          ((0x00000001&(data))>>0)


#define DC_GLOBAL_SCRAMBLE_CTRL                                               0x18007510
#define DC_GLOBAL_SCRAMBLE_CTRL_reg_addr                                      "0xB8007510"
#define DC_GLOBAL_SCRAMBLE_CTRL_reg                                           0xB8007510
#define set_DC_GLOBAL_SCRAMBLE_CTRL_reg(data)   (*((volatile unsigned int*) DC_GLOBAL_SCRAMBLE_CTRL_reg)=data)
#define get_DC_GLOBAL_SCRAMBLE_CTRL_reg   (*((volatile unsigned int*) DC_GLOBAL_SCRAMBLE_CTRL_reg))
#define DC_GLOBAL_SCRAMBLE_CTRL_inst_adr                                      "0x0044"
#define DC_GLOBAL_SCRAMBLE_CTRL_inst                                          0x0044
#define DC_GLOBAL_SCRAMBLE_CTRL_global_scramble_en_shift                      (0)
#define DC_GLOBAL_SCRAMBLE_CTRL_global_scramble_en_mask                       (0x00000001)
#define DC_GLOBAL_SCRAMBLE_CTRL_global_scramble_en(data)                      (0x00000001&((data)<<0))
#define DC_GLOBAL_SCRAMBLE_CTRL_global_scramble_en_src(data)                  ((0x00000001&(data))>>0)
#define DC_GLOBAL_SCRAMBLE_CTRL_get_global_scramble_en(data)                  ((0x00000001&(data))>>0)


#define DC_MEM_SCRAMBLE_GLOBAL_0                                              0x18007514
#define DC_MEM_SCRAMBLE_GLOBAL_0_reg_addr                                     "0xB8007514"
#define DC_MEM_SCRAMBLE_GLOBAL_0_reg                                          0xB8007514
#define set_DC_MEM_SCRAMBLE_GLOBAL_0_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_GLOBAL_0_reg)=data)
#define get_DC_MEM_SCRAMBLE_GLOBAL_0_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_GLOBAL_0_reg))
#define DC_MEM_SCRAMBLE_GLOBAL_0_inst_adr                                     "0x0045"
#define DC_MEM_SCRAMBLE_GLOBAL_0_inst                                         0x0045
#define DC_MEM_SCRAMBLE_GLOBAL_0_key1_shift                                   (16)
#define DC_MEM_SCRAMBLE_GLOBAL_0_key1_mask                                    (0xFFFF0000)
#define DC_MEM_SCRAMBLE_GLOBAL_0_key1(data)                                   (0xFFFF0000&((data)<<16))
#define DC_MEM_SCRAMBLE_GLOBAL_0_key1_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_GLOBAL_0_get_key1(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_GLOBAL_0_key0_shift                                   (0)
#define DC_MEM_SCRAMBLE_GLOBAL_0_key0_mask                                    (0x0000FFFF)
#define DC_MEM_SCRAMBLE_GLOBAL_0_key0(data)                                   (0x0000FFFF&((data)<<0))
#define DC_MEM_SCRAMBLE_GLOBAL_0_key0_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC_MEM_SCRAMBLE_GLOBAL_0_get_key0(data)                               ((0x0000FFFF&(data))>>0)


#define DC_MEM_SCRAMBLE_GLOBAL_1                                              0x18007518
#define DC_MEM_SCRAMBLE_GLOBAL_1_reg_addr                                     "0xB8007518"
#define DC_MEM_SCRAMBLE_GLOBAL_1_reg                                          0xB8007518
#define set_DC_MEM_SCRAMBLE_GLOBAL_1_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_GLOBAL_1_reg)=data)
#define get_DC_MEM_SCRAMBLE_GLOBAL_1_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_GLOBAL_1_reg))
#define DC_MEM_SCRAMBLE_GLOBAL_1_inst_adr                                     "0x0046"
#define DC_MEM_SCRAMBLE_GLOBAL_1_inst                                         0x0046
#define DC_MEM_SCRAMBLE_GLOBAL_1_key3_shift                                   (16)
#define DC_MEM_SCRAMBLE_GLOBAL_1_key3_mask                                    (0xFFFF0000)
#define DC_MEM_SCRAMBLE_GLOBAL_1_key3(data)                                   (0xFFFF0000&((data)<<16))
#define DC_MEM_SCRAMBLE_GLOBAL_1_key3_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_GLOBAL_1_get_key3(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_GLOBAL_1_key2_shift                                   (0)
#define DC_MEM_SCRAMBLE_GLOBAL_1_key2_mask                                    (0x0000FFFF)
#define DC_MEM_SCRAMBLE_GLOBAL_1_key2(data)                                   (0x0000FFFF&((data)<<0))
#define DC_MEM_SCRAMBLE_GLOBAL_1_key2_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC_MEM_SCRAMBLE_GLOBAL_1_get_key2(data)                               ((0x0000FFFF&(data))>>0)


#define DC_MEM_SCRAMBLE_GLOBAL_2                                              0x1800751C
#define DC_MEM_SCRAMBLE_GLOBAL_2_reg_addr                                     "0xB800751C"
#define DC_MEM_SCRAMBLE_GLOBAL_2_reg                                          0xB800751C
#define set_DC_MEM_SCRAMBLE_GLOBAL_2_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_GLOBAL_2_reg)=data)
#define get_DC_MEM_SCRAMBLE_GLOBAL_2_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_GLOBAL_2_reg))
#define DC_MEM_SCRAMBLE_GLOBAL_2_inst_adr                                     "0x0047"
#define DC_MEM_SCRAMBLE_GLOBAL_2_inst                                         0x0047
#define DC_MEM_SCRAMBLE_GLOBAL_2_key5_shift                                   (16)
#define DC_MEM_SCRAMBLE_GLOBAL_2_key5_mask                                    (0xFFFF0000)
#define DC_MEM_SCRAMBLE_GLOBAL_2_key5(data)                                   (0xFFFF0000&((data)<<16))
#define DC_MEM_SCRAMBLE_GLOBAL_2_key5_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_GLOBAL_2_get_key5(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_GLOBAL_2_key4_shift                                   (0)
#define DC_MEM_SCRAMBLE_GLOBAL_2_key4_mask                                    (0x0000FFFF)
#define DC_MEM_SCRAMBLE_GLOBAL_2_key4(data)                                   (0x0000FFFF&((data)<<0))
#define DC_MEM_SCRAMBLE_GLOBAL_2_key4_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC_MEM_SCRAMBLE_GLOBAL_2_get_key4(data)                               ((0x0000FFFF&(data))>>0)


#define DC_MEM_SCRAMBLE_GLOBAL_3                                              0x18007520
#define DC_MEM_SCRAMBLE_GLOBAL_3_reg_addr                                     "0xB8007520"
#define DC_MEM_SCRAMBLE_GLOBAL_3_reg                                          0xB8007520
#define set_DC_MEM_SCRAMBLE_GLOBAL_3_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_GLOBAL_3_reg)=data)
#define get_DC_MEM_SCRAMBLE_GLOBAL_3_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_GLOBAL_3_reg))
#define DC_MEM_SCRAMBLE_GLOBAL_3_inst_adr                                     "0x0048"
#define DC_MEM_SCRAMBLE_GLOBAL_3_inst                                         0x0048
#define DC_MEM_SCRAMBLE_GLOBAL_3_key7_shift                                   (16)
#define DC_MEM_SCRAMBLE_GLOBAL_3_key7_mask                                    (0xFFFF0000)
#define DC_MEM_SCRAMBLE_GLOBAL_3_key7(data)                                   (0xFFFF0000&((data)<<16))
#define DC_MEM_SCRAMBLE_GLOBAL_3_key7_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_GLOBAL_3_get_key7(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_GLOBAL_3_key6_shift                                   (0)
#define DC_MEM_SCRAMBLE_GLOBAL_3_key6_mask                                    (0x0000FFFF)
#define DC_MEM_SCRAMBLE_GLOBAL_3_key6(data)                                   (0x0000FFFF&((data)<<0))
#define DC_MEM_SCRAMBLE_GLOBAL_3_key6_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC_MEM_SCRAMBLE_GLOBAL_3_get_key6(data)                               ((0x0000FFFF&(data))>>0)


#define DC_MEM_SCRAMBLE_GLOBAL_4                                              0x18007524
#define DC_MEM_SCRAMBLE_GLOBAL_4_reg_addr                                     "0xB8007524"
#define DC_MEM_SCRAMBLE_GLOBAL_4_reg                                          0xB8007524
#define set_DC_MEM_SCRAMBLE_GLOBAL_4_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_GLOBAL_4_reg)=data)
#define get_DC_MEM_SCRAMBLE_GLOBAL_4_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_GLOBAL_4_reg))
#define DC_MEM_SCRAMBLE_GLOBAL_4_inst_adr                                     "0x0049"
#define DC_MEM_SCRAMBLE_GLOBAL_4_inst                                         0x0049
#define DC_MEM_SCRAMBLE_GLOBAL_4_key9_shift                                   (16)
#define DC_MEM_SCRAMBLE_GLOBAL_4_key9_mask                                    (0xFFFF0000)
#define DC_MEM_SCRAMBLE_GLOBAL_4_key9(data)                                   (0xFFFF0000&((data)<<16))
#define DC_MEM_SCRAMBLE_GLOBAL_4_key9_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_GLOBAL_4_get_key9(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_GLOBAL_4_key8_shift                                   (0)
#define DC_MEM_SCRAMBLE_GLOBAL_4_key8_mask                                    (0x0000FFFF)
#define DC_MEM_SCRAMBLE_GLOBAL_4_key8(data)                                   (0x0000FFFF&((data)<<0))
#define DC_MEM_SCRAMBLE_GLOBAL_4_key8_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC_MEM_SCRAMBLE_GLOBAL_4_get_key8(data)                               ((0x0000FFFF&(data))>>0)


#define DC_MEM_SCRAMBLE_GLOBAL_5                                              0x18007528
#define DC_MEM_SCRAMBLE_GLOBAL_5_reg_addr                                     "0xB8007528"
#define DC_MEM_SCRAMBLE_GLOBAL_5_reg                                          0xB8007528
#define set_DC_MEM_SCRAMBLE_GLOBAL_5_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_GLOBAL_5_reg)=data)
#define get_DC_MEM_SCRAMBLE_GLOBAL_5_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_GLOBAL_5_reg))
#define DC_MEM_SCRAMBLE_GLOBAL_5_inst_adr                                     "0x004A"
#define DC_MEM_SCRAMBLE_GLOBAL_5_inst                                         0x004A
#define DC_MEM_SCRAMBLE_GLOBAL_5_keyB_shift                                   (16)
#define DC_MEM_SCRAMBLE_GLOBAL_5_keyB_mask                                    (0xFFFF0000)
#define DC_MEM_SCRAMBLE_GLOBAL_5_keyB(data)                                   (0xFFFF0000&((data)<<16))
#define DC_MEM_SCRAMBLE_GLOBAL_5_keyB_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_GLOBAL_5_get_keyB(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_GLOBAL_5_keyA_shift                                   (0)
#define DC_MEM_SCRAMBLE_GLOBAL_5_keyA_mask                                    (0x0000FFFF)
#define DC_MEM_SCRAMBLE_GLOBAL_5_keyA(data)                                   (0x0000FFFF&((data)<<0))
#define DC_MEM_SCRAMBLE_GLOBAL_5_keyA_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC_MEM_SCRAMBLE_GLOBAL_5_get_keyA(data)                               ((0x0000FFFF&(data))>>0)


#define DC_MEM_SCRAMBLE_GLOBAL_6                                              0x1800752C
#define DC_MEM_SCRAMBLE_GLOBAL_6_reg_addr                                     "0xB800752C"
#define DC_MEM_SCRAMBLE_GLOBAL_6_reg                                          0xB800752C
#define set_DC_MEM_SCRAMBLE_GLOBAL_6_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_GLOBAL_6_reg)=data)
#define get_DC_MEM_SCRAMBLE_GLOBAL_6_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_GLOBAL_6_reg))
#define DC_MEM_SCRAMBLE_GLOBAL_6_inst_adr                                     "0x004B"
#define DC_MEM_SCRAMBLE_GLOBAL_6_inst                                         0x004B
#define DC_MEM_SCRAMBLE_GLOBAL_6_keyD_shift                                   (16)
#define DC_MEM_SCRAMBLE_GLOBAL_6_keyD_mask                                    (0xFFFF0000)
#define DC_MEM_SCRAMBLE_GLOBAL_6_keyD(data)                                   (0xFFFF0000&((data)<<16))
#define DC_MEM_SCRAMBLE_GLOBAL_6_keyD_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_GLOBAL_6_get_keyD(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_GLOBAL_6_keyC_shift                                   (0)
#define DC_MEM_SCRAMBLE_GLOBAL_6_keyC_mask                                    (0x0000FFFF)
#define DC_MEM_SCRAMBLE_GLOBAL_6_keyC(data)                                   (0x0000FFFF&((data)<<0))
#define DC_MEM_SCRAMBLE_GLOBAL_6_keyC_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC_MEM_SCRAMBLE_GLOBAL_6_get_keyC(data)                               ((0x0000FFFF&(data))>>0)


#define DC_MEM_PROTECT_CTRL                                                   0x18007540
#define DC_MEM_PROTECT_CTRL_reg_addr                                          "0xB8007540"
#define DC_MEM_PROTECT_CTRL_reg                                               0xB8007540
#define set_DC_MEM_PROTECT_CTRL_reg(data)   (*((volatile unsigned int*) DC_MEM_PROTECT_CTRL_reg)=data)
#define get_DC_MEM_PROTECT_CTRL_reg   (*((volatile unsigned int*) DC_MEM_PROTECT_CTRL_reg))
#define DC_MEM_PROTECT_CTRL_inst_adr                                          "0x0050"
#define DC_MEM_PROTECT_CTRL_inst                                              0x0050
#define DC_MEM_PROTECT_CTRL_osd1_protect_3_en_shift                           (24)
#define DC_MEM_PROTECT_CTRL_osd1_protect_3_en_mask                            (0x01000000)
#define DC_MEM_PROTECT_CTRL_osd1_protect_3_en(data)                           (0x01000000&((data)<<24))
#define DC_MEM_PROTECT_CTRL_osd1_protect_3_en_src(data)                       ((0x01000000&(data))>>24)
#define DC_MEM_PROTECT_CTRL_get_osd1_protect_3_en(data)                       ((0x01000000&(data))>>24)
#define DC_MEM_PROTECT_CTRL_protect_3_en_shift                                (19)
#define DC_MEM_PROTECT_CTRL_protect_3_en_mask                                 (0x00080000)
#define DC_MEM_PROTECT_CTRL_protect_3_en(data)                                (0x00080000&((data)<<19))
#define DC_MEM_PROTECT_CTRL_protect_3_en_src(data)                            ((0x00080000&(data))>>19)
#define DC_MEM_PROTECT_CTRL_get_protect_3_en(data)                            ((0x00080000&(data))>>19)
#define DC_MEM_PROTECT_CTRL_protect_2_en_shift                                (18)
#define DC_MEM_PROTECT_CTRL_protect_2_en_mask                                 (0x00040000)
#define DC_MEM_PROTECT_CTRL_protect_2_en(data)                                (0x00040000&((data)<<18))
#define DC_MEM_PROTECT_CTRL_protect_2_en_src(data)                            ((0x00040000&(data))>>18)
#define DC_MEM_PROTECT_CTRL_get_protect_2_en(data)                            ((0x00040000&(data))>>18)
#define DC_MEM_PROTECT_CTRL_protect_1_en_shift                                (17)
#define DC_MEM_PROTECT_CTRL_protect_1_en_mask                                 (0x00020000)
#define DC_MEM_PROTECT_CTRL_protect_1_en(data)                                (0x00020000&((data)<<17))
#define DC_MEM_PROTECT_CTRL_protect_1_en_src(data)                            ((0x00020000&(data))>>17)
#define DC_MEM_PROTECT_CTRL_get_protect_1_en(data)                            ((0x00020000&(data))>>17)
#define DC_MEM_PROTECT_CTRL_protect_0_en_shift                                (16)
#define DC_MEM_PROTECT_CTRL_protect_0_en_mask                                 (0x00010000)
#define DC_MEM_PROTECT_CTRL_protect_0_en(data)                                (0x00010000&((data)<<16))
#define DC_MEM_PROTECT_CTRL_protect_0_en_src(data)                            ((0x00010000&(data))>>16)
#define DC_MEM_PROTECT_CTRL_get_protect_0_en(data)                            ((0x00010000&(data))>>16)
#define DC_MEM_PROTECT_CTRL_protect_3_scramble_en_shift                       (3)
#define DC_MEM_PROTECT_CTRL_protect_3_scramble_en_mask                        (0x00000008)
#define DC_MEM_PROTECT_CTRL_protect_3_scramble_en(data)                       (0x00000008&((data)<<3))
#define DC_MEM_PROTECT_CTRL_protect_3_scramble_en_src(data)                   ((0x00000008&(data))>>3)
#define DC_MEM_PROTECT_CTRL_get_protect_3_scramble_en(data)                   ((0x00000008&(data))>>3)
#define DC_MEM_PROTECT_CTRL_protect_2_scramble_en_shift                       (2)
#define DC_MEM_PROTECT_CTRL_protect_2_scramble_en_mask                        (0x00000004)
#define DC_MEM_PROTECT_CTRL_protect_2_scramble_en(data)                       (0x00000004&((data)<<2))
#define DC_MEM_PROTECT_CTRL_protect_2_scramble_en_src(data)                   ((0x00000004&(data))>>2)
#define DC_MEM_PROTECT_CTRL_get_protect_2_scramble_en(data)                   ((0x00000004&(data))>>2)
#define DC_MEM_PROTECT_CTRL_protect_1_scramble_en_shift                       (1)
#define DC_MEM_PROTECT_CTRL_protect_1_scramble_en_mask                        (0x00000002)
#define DC_MEM_PROTECT_CTRL_protect_1_scramble_en(data)                       (0x00000002&((data)<<1))
#define DC_MEM_PROTECT_CTRL_protect_1_scramble_en_src(data)                   ((0x00000002&(data))>>1)
#define DC_MEM_PROTECT_CTRL_get_protect_1_scramble_en(data)                   ((0x00000002&(data))>>1)
#define DC_MEM_PROTECT_CTRL_protect_0_scramble_en_shift                       (0)
#define DC_MEM_PROTECT_CTRL_protect_0_scramble_en_mask                        (0x00000001)
#define DC_MEM_PROTECT_CTRL_protect_0_scramble_en(data)                       (0x00000001&((data)<<0))
#define DC_MEM_PROTECT_CTRL_protect_0_scramble_en_src(data)                   ((0x00000001&(data))>>0)
#define DC_MEM_PROTECT_CTRL_get_protect_0_scramble_en(data)                   ((0x00000001&(data))>>0)


#define DC_SECURE_MAX                                                         0x18007544
#define DC_SECURE_MAX_reg_addr                                                "0xB8007544"
#define DC_SECURE_MAX_reg                                                     0xB8007544
#define set_DC_SECURE_MAX_reg(data)   (*((volatile unsigned int*) DC_SECURE_MAX_reg)=data)
#define get_DC_SECURE_MAX_reg   (*((volatile unsigned int*) DC_SECURE_MAX_reg))
#define DC_SECURE_MAX_inst_adr                                                "0x0051"
#define DC_SECURE_MAX_inst                                                    0x0051
#define DC_SECURE_MAX_addr_shift                                              (12)
#define DC_SECURE_MAX_addr_mask                                               (0xFFFFF000)
#define DC_SECURE_MAX_addr(data)                                              (0xFFFFF000&((data)<<12))
#define DC_SECURE_MAX_addr_src(data)                                          ((0xFFFFF000&(data))>>12)
#define DC_SECURE_MAX_get_addr(data)                                          ((0xFFFFF000&(data))>>12)
#define DC_SECURE_MAX_y_limit_shift                                           (1)
#define DC_SECURE_MAX_y_limit_mask                                            (0x00000002)
#define DC_SECURE_MAX_y_limit(data)                                           (0x00000002&((data)<<1))
#define DC_SECURE_MAX_y_limit_src(data)                                       ((0x00000002&(data))>>1)
#define DC_SECURE_MAX_get_y_limit(data)                                       ((0x00000002&(data))>>1)


#define DC_MEM_PROTECT_START_0                                                0x18007550
#define DC_MEM_PROTECT_START_1                                                0x18007554
#define DC_MEM_PROTECT_START_2                                                0x18007558
#define DC_MEM_PROTECT_START_3                                                0x1800755C
#define DC_MEM_PROTECT_START_0_reg_addr                                       "0xB8007550"
#define DC_MEM_PROTECT_START_1_reg_addr                                       "0xB8007554"
#define DC_MEM_PROTECT_START_2_reg_addr                                       "0xB8007558"
#define DC_MEM_PROTECT_START_3_reg_addr                                       "0xB800755C"
#define DC_MEM_PROTECT_START_0_reg                                            0xB8007550
#define DC_MEM_PROTECT_START_1_reg                                            0xB8007554
#define DC_MEM_PROTECT_START_2_reg                                            0xB8007558
#define DC_MEM_PROTECT_START_3_reg                                            0xB800755C
#define set_DC_MEM_PROTECT_START_0_reg(data)   (*((volatile unsigned int*) DC_MEM_PROTECT_START_0_reg)=data)
#define set_DC_MEM_PROTECT_START_1_reg(data)   (*((volatile unsigned int*) DC_MEM_PROTECT_START_1_reg)=data)
#define set_DC_MEM_PROTECT_START_2_reg(data)   (*((volatile unsigned int*) DC_MEM_PROTECT_START_2_reg)=data)
#define set_DC_MEM_PROTECT_START_3_reg(data)   (*((volatile unsigned int*) DC_MEM_PROTECT_START_3_reg)=data)
#define get_DC_MEM_PROTECT_START_0_reg   (*((volatile unsigned int*) DC_MEM_PROTECT_START_0_reg))
#define get_DC_MEM_PROTECT_START_1_reg   (*((volatile unsigned int*) DC_MEM_PROTECT_START_1_reg))
#define get_DC_MEM_PROTECT_START_2_reg   (*((volatile unsigned int*) DC_MEM_PROTECT_START_2_reg))
#define get_DC_MEM_PROTECT_START_3_reg   (*((volatile unsigned int*) DC_MEM_PROTECT_START_3_reg))
#define DC_MEM_PROTECT_START_0_inst_adr                                       "0x0054"
#define DC_MEM_PROTECT_START_1_inst_adr                                       "0x0055"
#define DC_MEM_PROTECT_START_2_inst_adr                                       "0x0056"
#define DC_MEM_PROTECT_START_3_inst_adr                                       "0x0057"
#define DC_MEM_PROTECT_START_0_inst                                           0x0054
#define DC_MEM_PROTECT_START_1_inst                                           0x0055
#define DC_MEM_PROTECT_START_2_inst                                           0x0056
#define DC_MEM_PROTECT_START_3_inst                                           0x0057
#define DC_MEM_PROTECT_START_addr_shift                                       (12)
#define DC_MEM_PROTECT_START_addr_mask                                        (0xFFFFF000)
#define DC_MEM_PROTECT_START_addr(data)                                       (0xFFFFF000&((data)<<12))
#define DC_MEM_PROTECT_START_addr_src(data)                                   ((0xFFFFF000&(data))>>12)
#define DC_MEM_PROTECT_START_get_addr(data)                                   ((0xFFFFF000&(data))>>12)


#define DC_MEM_PROTECT_END_0                                                  0x18007560
#define DC_MEM_PROTECT_END_1                                                  0x18007564
#define DC_MEM_PROTECT_END_2                                                  0x18007568
#define DC_MEM_PROTECT_END_3                                                  0x1800756C
#define DC_MEM_PROTECT_END_0_reg_addr                                         "0xB8007560"
#define DC_MEM_PROTECT_END_1_reg_addr                                         "0xB8007564"
#define DC_MEM_PROTECT_END_2_reg_addr                                         "0xB8007568"
#define DC_MEM_PROTECT_END_3_reg_addr                                         "0xB800756C"
#define DC_MEM_PROTECT_END_0_reg                                              0xB8007560
#define DC_MEM_PROTECT_END_1_reg                                              0xB8007564
#define DC_MEM_PROTECT_END_2_reg                                              0xB8007568
#define DC_MEM_PROTECT_END_3_reg                                              0xB800756C
#define set_DC_MEM_PROTECT_END_0_reg(data)   (*((volatile unsigned int*) DC_MEM_PROTECT_END_0_reg)=data)
#define set_DC_MEM_PROTECT_END_1_reg(data)   (*((volatile unsigned int*) DC_MEM_PROTECT_END_1_reg)=data)
#define set_DC_MEM_PROTECT_END_2_reg(data)   (*((volatile unsigned int*) DC_MEM_PROTECT_END_2_reg)=data)
#define set_DC_MEM_PROTECT_END_3_reg(data)   (*((volatile unsigned int*) DC_MEM_PROTECT_END_3_reg)=data)
#define get_DC_MEM_PROTECT_END_0_reg   (*((volatile unsigned int*) DC_MEM_PROTECT_END_0_reg))
#define get_DC_MEM_PROTECT_END_1_reg   (*((volatile unsigned int*) DC_MEM_PROTECT_END_1_reg))
#define get_DC_MEM_PROTECT_END_2_reg   (*((volatile unsigned int*) DC_MEM_PROTECT_END_2_reg))
#define get_DC_MEM_PROTECT_END_3_reg   (*((volatile unsigned int*) DC_MEM_PROTECT_END_3_reg))
#define DC_MEM_PROTECT_END_0_inst_adr                                         "0x0058"
#define DC_MEM_PROTECT_END_1_inst_adr                                         "0x0059"
#define DC_MEM_PROTECT_END_2_inst_adr                                         "0x005A"
#define DC_MEM_PROTECT_END_3_inst_adr                                         "0x005B"
#define DC_MEM_PROTECT_END_0_inst                                             0x0058
#define DC_MEM_PROTECT_END_1_inst                                             0x0059
#define DC_MEM_PROTECT_END_2_inst                                             0x005A
#define DC_MEM_PROTECT_END_3_inst                                             0x005B
#define DC_MEM_PROTECT_END_addr_shift                                         (12)
#define DC_MEM_PROTECT_END_addr_mask                                          (0xFFFFF000)
#define DC_MEM_PROTECT_END_addr(data)                                         (0xFFFFF000&((data)<<12))
#define DC_MEM_PROTECT_END_addr_src(data)                                     ((0xFFFFF000&(data))>>12)
#define DC_MEM_PROTECT_END_get_addr(data)                                     ((0xFFFFF000&(data))>>12)


#define DC_KCPU_REGION_0                                                      0x18007570
#define DC_KCPU_REGION_1                                                      0x18007574
#define DC_KCPU_REGION_2                                                      0x18007578
#define DC_KCPU_REGION_3                                                      0x1800757C
#define DC_KCPU_REGION_0_reg_addr                                             "0xB8007570"
#define DC_KCPU_REGION_1_reg_addr                                             "0xB8007574"
#define DC_KCPU_REGION_2_reg_addr                                             "0xB8007578"
#define DC_KCPU_REGION_3_reg_addr                                             "0xB800757C"
#define DC_KCPU_REGION_0_reg                                                  0xB8007570
#define DC_KCPU_REGION_1_reg                                                  0xB8007574
#define DC_KCPU_REGION_2_reg                                                  0xB8007578
#define DC_KCPU_REGION_3_reg                                                  0xB800757C
#define set_DC_KCPU_REGION_0_reg(data)   (*((volatile unsigned int*) DC_KCPU_REGION_0_reg)=data)
#define set_DC_KCPU_REGION_1_reg(data)   (*((volatile unsigned int*) DC_KCPU_REGION_1_reg)=data)
#define set_DC_KCPU_REGION_2_reg(data)   (*((volatile unsigned int*) DC_KCPU_REGION_2_reg)=data)
#define set_DC_KCPU_REGION_3_reg(data)   (*((volatile unsigned int*) DC_KCPU_REGION_3_reg)=data)
#define get_DC_KCPU_REGION_0_reg   (*((volatile unsigned int*) DC_KCPU_REGION_0_reg))
#define get_DC_KCPU_REGION_1_reg   (*((volatile unsigned int*) DC_KCPU_REGION_1_reg))
#define get_DC_KCPU_REGION_2_reg   (*((volatile unsigned int*) DC_KCPU_REGION_2_reg))
#define get_DC_KCPU_REGION_3_reg   (*((volatile unsigned int*) DC_KCPU_REGION_3_reg))
#define DC_KCPU_REGION_0_inst_adr                                             "0x005C"
#define DC_KCPU_REGION_1_inst_adr                                             "0x005D"
#define DC_KCPU_REGION_2_inst_adr                                             "0x005E"
#define DC_KCPU_REGION_3_inst_adr                                             "0x005F"
#define DC_KCPU_REGION_0_inst                                                 0x005C
#define DC_KCPU_REGION_1_inst                                                 0x005D
#define DC_KCPU_REGION_2_inst                                                 0x005E
#define DC_KCPU_REGION_3_inst                                                 0x005F
#define DC_KCPU_REGION_tp_kc_shift                                            (4)
#define DC_KCPU_REGION_tp_kc_mask                                             (0x00000010)
#define DC_KCPU_REGION_tp_kc(data)                                            (0x00000010&((data)<<4))
#define DC_KCPU_REGION_tp_kc_src(data)                                        ((0x00000010&(data))>>4)
#define DC_KCPU_REGION_get_tp_kc(data)                                        ((0x00000010&(data))>>4)
#define DC_KCPU_REGION_emmc_kc_shift                                          (3)
#define DC_KCPU_REGION_emmc_kc_mask                                           (0x00000008)
#define DC_KCPU_REGION_emmc_kc(data)                                          (0x00000008&((data)<<3))
#define DC_KCPU_REGION_emmc_kc_src(data)                                      ((0x00000008&(data))>>3)
#define DC_KCPU_REGION_get_emmc_kc(data)                                      ((0x00000008&(data))>>3)
#define DC_KCPU_REGION_nf_kc_shift                                            (2)
#define DC_KCPU_REGION_nf_kc_mask                                             (0x00000004)
#define DC_KCPU_REGION_nf_kc(data)                                            (0x00000004&((data)<<2))
#define DC_KCPU_REGION_nf_kc_src(data)                                        ((0x00000004&(data))>>2)
#define DC_KCPU_REGION_get_nf_kc(data)                                        ((0x00000004&(data))>>2)
#define DC_KCPU_REGION_cp_kc_shift                                            (1)
#define DC_KCPU_REGION_cp_kc_mask                                             (0x00000002)
#define DC_KCPU_REGION_cp_kc(data)                                            (0x00000002&((data)<<1))
#define DC_KCPU_REGION_cp_kc_src(data)                                        ((0x00000002&(data))>>1)
#define DC_KCPU_REGION_get_cp_kc(data)                                        ((0x00000002&(data))>>1)
#define DC_KCPU_REGION_md_kc_shift                                            (0)
#define DC_KCPU_REGION_md_kc_mask                                             (0x00000001)
#define DC_KCPU_REGION_md_kc(data)                                            (0x00000001&((data)<<0))
#define DC_KCPU_REGION_md_kc_src(data)                                        ((0x00000001&(data))>>0)
#define DC_KCPU_REGION_get_md_kc(data)                                        ((0x00000001&(data))>>0)


#define DC_MEM_CONTENT_CTRL                                                   0x180075E0
#define DC_MEM_CONTENT_CTRL_reg_addr                                          "0xB80075E0"
#define DC_MEM_CONTENT_CTRL_reg                                               0xB80075E0
#define set_DC_MEM_CONTENT_CTRL_reg(data)   (*((volatile unsigned int*) DC_MEM_CONTENT_CTRL_reg)=data)
#define get_DC_MEM_CONTENT_CTRL_reg   (*((volatile unsigned int*) DC_MEM_CONTENT_CTRL_reg))
#define DC_MEM_CONTENT_CTRL_inst_adr                                          "0x0078"
#define DC_MEM_CONTENT_CTRL_inst                                              0x0078
#define DC_MEM_CONTENT_CTRL_content_7_en_shift                                (23)
#define DC_MEM_CONTENT_CTRL_content_7_en_mask                                 (0x00800000)
#define DC_MEM_CONTENT_CTRL_content_7_en(data)                                (0x00800000&((data)<<23))
#define DC_MEM_CONTENT_CTRL_content_7_en_src(data)                            ((0x00800000&(data))>>23)
#define DC_MEM_CONTENT_CTRL_get_content_7_en(data)                            ((0x00800000&(data))>>23)
#define DC_MEM_CONTENT_CTRL_content_6_en_shift                                (22)
#define DC_MEM_CONTENT_CTRL_content_6_en_mask                                 (0x00400000)
#define DC_MEM_CONTENT_CTRL_content_6_en(data)                                (0x00400000&((data)<<22))
#define DC_MEM_CONTENT_CTRL_content_6_en_src(data)                            ((0x00400000&(data))>>22)
#define DC_MEM_CONTENT_CTRL_get_content_6_en(data)                            ((0x00400000&(data))>>22)
#define DC_MEM_CONTENT_CTRL_content_5_en_shift                                (21)
#define DC_MEM_CONTENT_CTRL_content_5_en_mask                                 (0x00200000)
#define DC_MEM_CONTENT_CTRL_content_5_en(data)                                (0x00200000&((data)<<21))
#define DC_MEM_CONTENT_CTRL_content_5_en_src(data)                            ((0x00200000&(data))>>21)
#define DC_MEM_CONTENT_CTRL_get_content_5_en(data)                            ((0x00200000&(data))>>21)
#define DC_MEM_CONTENT_CTRL_content_4_en_shift                                (20)
#define DC_MEM_CONTENT_CTRL_content_4_en_mask                                 (0x00100000)
#define DC_MEM_CONTENT_CTRL_content_4_en(data)                                (0x00100000&((data)<<20))
#define DC_MEM_CONTENT_CTRL_content_4_en_src(data)                            ((0x00100000&(data))>>20)
#define DC_MEM_CONTENT_CTRL_get_content_4_en(data)                            ((0x00100000&(data))>>20)
#define DC_MEM_CONTENT_CTRL_content_3_en_shift                                (19)
#define DC_MEM_CONTENT_CTRL_content_3_en_mask                                 (0x00080000)
#define DC_MEM_CONTENT_CTRL_content_3_en(data)                                (0x00080000&((data)<<19))
#define DC_MEM_CONTENT_CTRL_content_3_en_src(data)                            ((0x00080000&(data))>>19)
#define DC_MEM_CONTENT_CTRL_get_content_3_en(data)                            ((0x00080000&(data))>>19)
#define DC_MEM_CONTENT_CTRL_content_2_en_shift                                (18)
#define DC_MEM_CONTENT_CTRL_content_2_en_mask                                 (0x00040000)
#define DC_MEM_CONTENT_CTRL_content_2_en(data)                                (0x00040000&((data)<<18))
#define DC_MEM_CONTENT_CTRL_content_2_en_src(data)                            ((0x00040000&(data))>>18)
#define DC_MEM_CONTENT_CTRL_get_content_2_en(data)                            ((0x00040000&(data))>>18)
#define DC_MEM_CONTENT_CTRL_content_1_en_shift                                (17)
#define DC_MEM_CONTENT_CTRL_content_1_en_mask                                 (0x00020000)
#define DC_MEM_CONTENT_CTRL_content_1_en(data)                                (0x00020000&((data)<<17))
#define DC_MEM_CONTENT_CTRL_content_1_en_src(data)                            ((0x00020000&(data))>>17)
#define DC_MEM_CONTENT_CTRL_get_content_1_en(data)                            ((0x00020000&(data))>>17)
#define DC_MEM_CONTENT_CTRL_content_0_en_shift                                (16)
#define DC_MEM_CONTENT_CTRL_content_0_en_mask                                 (0x00010000)
#define DC_MEM_CONTENT_CTRL_content_0_en(data)                                (0x00010000&((data)<<16))
#define DC_MEM_CONTENT_CTRL_content_0_en_src(data)                            ((0x00010000&(data))>>16)
#define DC_MEM_CONTENT_CTRL_get_content_0_en(data)                            ((0x00010000&(data))>>16)
#define DC_MEM_CONTENT_CTRL_scramble_7_en_shift                               (7)
#define DC_MEM_CONTENT_CTRL_scramble_7_en_mask                                (0x00000080)
#define DC_MEM_CONTENT_CTRL_scramble_7_en(data)                               (0x00000080&((data)<<7))
#define DC_MEM_CONTENT_CTRL_scramble_7_en_src(data)                           ((0x00000080&(data))>>7)
#define DC_MEM_CONTENT_CTRL_get_scramble_7_en(data)                           ((0x00000080&(data))>>7)
#define DC_MEM_CONTENT_CTRL_scramble_6_en_shift                               (6)
#define DC_MEM_CONTENT_CTRL_scramble_6_en_mask                                (0x00000040)
#define DC_MEM_CONTENT_CTRL_scramble_6_en(data)                               (0x00000040&((data)<<6))
#define DC_MEM_CONTENT_CTRL_scramble_6_en_src(data)                           ((0x00000040&(data))>>6)
#define DC_MEM_CONTENT_CTRL_get_scramble_6_en(data)                           ((0x00000040&(data))>>6)
#define DC_MEM_CONTENT_CTRL_scramble_5_en_shift                               (5)
#define DC_MEM_CONTENT_CTRL_scramble_5_en_mask                                (0x00000020)
#define DC_MEM_CONTENT_CTRL_scramble_5_en(data)                               (0x00000020&((data)<<5))
#define DC_MEM_CONTENT_CTRL_scramble_5_en_src(data)                           ((0x00000020&(data))>>5)
#define DC_MEM_CONTENT_CTRL_get_scramble_5_en(data)                           ((0x00000020&(data))>>5)
#define DC_MEM_CONTENT_CTRL_scramble_4_en_shift                               (4)
#define DC_MEM_CONTENT_CTRL_scramble_4_en_mask                                (0x00000010)
#define DC_MEM_CONTENT_CTRL_scramble_4_en(data)                               (0x00000010&((data)<<4))
#define DC_MEM_CONTENT_CTRL_scramble_4_en_src(data)                           ((0x00000010&(data))>>4)
#define DC_MEM_CONTENT_CTRL_get_scramble_4_en(data)                           ((0x00000010&(data))>>4)
#define DC_MEM_CONTENT_CTRL_scramble_3_en_shift                               (3)
#define DC_MEM_CONTENT_CTRL_scramble_3_en_mask                                (0x00000008)
#define DC_MEM_CONTENT_CTRL_scramble_3_en(data)                               (0x00000008&((data)<<3))
#define DC_MEM_CONTENT_CTRL_scramble_3_en_src(data)                           ((0x00000008&(data))>>3)
#define DC_MEM_CONTENT_CTRL_get_scramble_3_en(data)                           ((0x00000008&(data))>>3)
#define DC_MEM_CONTENT_CTRL_scramble_2_en_shift                               (2)
#define DC_MEM_CONTENT_CTRL_scramble_2_en_mask                                (0x00000004)
#define DC_MEM_CONTENT_CTRL_scramble_2_en(data)                               (0x00000004&((data)<<2))
#define DC_MEM_CONTENT_CTRL_scramble_2_en_src(data)                           ((0x00000004&(data))>>2)
#define DC_MEM_CONTENT_CTRL_get_scramble_2_en(data)                           ((0x00000004&(data))>>2)
#define DC_MEM_CONTENT_CTRL_scramble_1_en_shift                               (1)
#define DC_MEM_CONTENT_CTRL_scramble_1_en_mask                                (0x00000002)
#define DC_MEM_CONTENT_CTRL_scramble_1_en(data)                               (0x00000002&((data)<<1))
#define DC_MEM_CONTENT_CTRL_scramble_1_en_src(data)                           ((0x00000002&(data))>>1)
#define DC_MEM_CONTENT_CTRL_get_scramble_1_en(data)                           ((0x00000002&(data))>>1)
#define DC_MEM_CONTENT_CTRL_scramble_0_en_shift                               (0)
#define DC_MEM_CONTENT_CTRL_scramble_0_en_mask                                (0x00000001)
#define DC_MEM_CONTENT_CTRL_scramble_0_en(data)                               (0x00000001&((data)<<0))
#define DC_MEM_CONTENT_CTRL_scramble_0_en_src(data)                           ((0x00000001&(data))>>0)
#define DC_MEM_CONTENT_CTRL_get_scramble_0_en(data)                           ((0x00000001&(data))>>0)


#define DC_SCRAMBLE_ACCESS_0                                                  0x18007600
#define DC_SCRAMBLE_ACCESS_1                                                  0x18007604
#define DC_SCRAMBLE_ACCESS_2                                                  0x18007608
#define DC_SCRAMBLE_ACCESS_3                                                  0x1800760C
#define DC_SCRAMBLE_ACCESS_4                                                  0x18007610
#define DC_SCRAMBLE_ACCESS_5                                                  0x18007614
#define DC_SCRAMBLE_ACCESS_6                                                  0x18007618
#define DC_SCRAMBLE_ACCESS_7                                                  0x1800761C
#define DC_SCRAMBLE_ACCESS_0_reg_addr                                         "0xB8007600"
#define DC_SCRAMBLE_ACCESS_1_reg_addr                                         "0xB8007604"
#define DC_SCRAMBLE_ACCESS_2_reg_addr                                         "0xB8007608"
#define DC_SCRAMBLE_ACCESS_3_reg_addr                                         "0xB800760C"
#define DC_SCRAMBLE_ACCESS_4_reg_addr                                         "0xB8007610"
#define DC_SCRAMBLE_ACCESS_5_reg_addr                                         "0xB8007614"
#define DC_SCRAMBLE_ACCESS_6_reg_addr                                         "0xB8007618"
#define DC_SCRAMBLE_ACCESS_7_reg_addr                                         "0xB800761C"
#define DC_SCRAMBLE_ACCESS_0_reg                                              0xB8007600
#define DC_SCRAMBLE_ACCESS_1_reg                                              0xB8007604
#define DC_SCRAMBLE_ACCESS_2_reg                                              0xB8007608
#define DC_SCRAMBLE_ACCESS_3_reg                                              0xB800760C
#define DC_SCRAMBLE_ACCESS_4_reg                                              0xB8007610
#define DC_SCRAMBLE_ACCESS_5_reg                                              0xB8007614
#define DC_SCRAMBLE_ACCESS_6_reg                                              0xB8007618
#define DC_SCRAMBLE_ACCESS_7_reg                                              0xB800761C
#define set_DC_SCRAMBLE_ACCESS_0_reg(data)   (*((volatile unsigned int*) DC_SCRAMBLE_ACCESS_0_reg)=data)
#define set_DC_SCRAMBLE_ACCESS_1_reg(data)   (*((volatile unsigned int*) DC_SCRAMBLE_ACCESS_1_reg)=data)
#define set_DC_SCRAMBLE_ACCESS_2_reg(data)   (*((volatile unsigned int*) DC_SCRAMBLE_ACCESS_2_reg)=data)
#define set_DC_SCRAMBLE_ACCESS_3_reg(data)   (*((volatile unsigned int*) DC_SCRAMBLE_ACCESS_3_reg)=data)
#define set_DC_SCRAMBLE_ACCESS_4_reg(data)   (*((volatile unsigned int*) DC_SCRAMBLE_ACCESS_4_reg)=data)
#define set_DC_SCRAMBLE_ACCESS_5_reg(data)   (*((volatile unsigned int*) DC_SCRAMBLE_ACCESS_5_reg)=data)
#define set_DC_SCRAMBLE_ACCESS_6_reg(data)   (*((volatile unsigned int*) DC_SCRAMBLE_ACCESS_6_reg)=data)
#define set_DC_SCRAMBLE_ACCESS_7_reg(data)   (*((volatile unsigned int*) DC_SCRAMBLE_ACCESS_7_reg)=data)
#define get_DC_SCRAMBLE_ACCESS_0_reg   (*((volatile unsigned int*) DC_SCRAMBLE_ACCESS_0_reg))
#define get_DC_SCRAMBLE_ACCESS_1_reg   (*((volatile unsigned int*) DC_SCRAMBLE_ACCESS_1_reg))
#define get_DC_SCRAMBLE_ACCESS_2_reg   (*((volatile unsigned int*) DC_SCRAMBLE_ACCESS_2_reg))
#define get_DC_SCRAMBLE_ACCESS_3_reg   (*((volatile unsigned int*) DC_SCRAMBLE_ACCESS_3_reg))
#define get_DC_SCRAMBLE_ACCESS_4_reg   (*((volatile unsigned int*) DC_SCRAMBLE_ACCESS_4_reg))
#define get_DC_SCRAMBLE_ACCESS_5_reg   (*((volatile unsigned int*) DC_SCRAMBLE_ACCESS_5_reg))
#define get_DC_SCRAMBLE_ACCESS_6_reg   (*((volatile unsigned int*) DC_SCRAMBLE_ACCESS_6_reg))
#define get_DC_SCRAMBLE_ACCESS_7_reg   (*((volatile unsigned int*) DC_SCRAMBLE_ACCESS_7_reg))
#define DC_SCRAMBLE_ACCESS_0_inst_adr                                         "0x0080"
#define DC_SCRAMBLE_ACCESS_1_inst_adr                                         "0x0081"
#define DC_SCRAMBLE_ACCESS_2_inst_adr                                         "0x0082"
#define DC_SCRAMBLE_ACCESS_3_inst_adr                                         "0x0083"
#define DC_SCRAMBLE_ACCESS_4_inst_adr                                         "0x0084"
#define DC_SCRAMBLE_ACCESS_5_inst_adr                                         "0x0085"
#define DC_SCRAMBLE_ACCESS_6_inst_adr                                         "0x0086"
#define DC_SCRAMBLE_ACCESS_7_inst_adr                                         "0x0087"
#define DC_SCRAMBLE_ACCESS_0_inst                                             0x0080
#define DC_SCRAMBLE_ACCESS_1_inst                                             0x0081
#define DC_SCRAMBLE_ACCESS_2_inst                                             0x0082
#define DC_SCRAMBLE_ACCESS_3_inst                                             0x0083
#define DC_SCRAMBLE_ACCESS_4_inst                                             0x0084
#define DC_SCRAMBLE_ACCESS_5_inst                                             0x0085
#define DC_SCRAMBLE_ACCESS_6_inst                                             0x0086
#define DC_SCRAMBLE_ACCESS_7_inst                                             0x0087
#define DC_SCRAMBLE_ACCESS_tp_kc_shift                                        (13)
#define DC_SCRAMBLE_ACCESS_tp_kc_mask                                         (0x00002000)
#define DC_SCRAMBLE_ACCESS_tp_kc(data)                                        (0x00002000&((data)<<13))
#define DC_SCRAMBLE_ACCESS_tp_kc_src(data)                                    ((0x00002000&(data))>>13)
#define DC_SCRAMBLE_ACCESS_get_tp_kc(data)                                    ((0x00002000&(data))>>13)
#define DC_SCRAMBLE_ACCESS_emmc_kc_shift                                      (12)
#define DC_SCRAMBLE_ACCESS_emmc_kc_mask                                       (0x00001000)
#define DC_SCRAMBLE_ACCESS_emmc_kc(data)                                      (0x00001000&((data)<<12))
#define DC_SCRAMBLE_ACCESS_emmc_kc_src(data)                                  ((0x00001000&(data))>>12)
#define DC_SCRAMBLE_ACCESS_get_emmc_kc(data)                                  ((0x00001000&(data))>>12)
#define DC_SCRAMBLE_ACCESS_acpu_shift                                         (10)
#define DC_SCRAMBLE_ACCESS_acpu_mask                                          (0x00000C00)
#define DC_SCRAMBLE_ACCESS_acpu(data)                                         (0x00000C00&((data)<<10))
#define DC_SCRAMBLE_ACCESS_acpu_src(data)                                     ((0x00000C00&(data))>>10)
#define DC_SCRAMBLE_ACCESS_get_acpu(data)                                     ((0x00000C00&(data))>>10)
#define DC_SCRAMBLE_ACCESS_vcpu_shift                                         (8)
#define DC_SCRAMBLE_ACCESS_vcpu_mask                                          (0x00000300)
#define DC_SCRAMBLE_ACCESS_vcpu(data)                                         (0x00000300&((data)<<8))
#define DC_SCRAMBLE_ACCESS_vcpu_src(data)                                     ((0x00000300&(data))>>8)
#define DC_SCRAMBLE_ACCESS_get_vcpu(data)                                     ((0x00000300&(data))>>8)
#define DC_SCRAMBLE_ACCESS_nf_kc_shift                                        (7)
#define DC_SCRAMBLE_ACCESS_nf_kc_mask                                         (0x00000080)
#define DC_SCRAMBLE_ACCESS_nf_kc(data)                                        (0x00000080&((data)<<7))
#define DC_SCRAMBLE_ACCESS_nf_kc_src(data)                                    ((0x00000080&(data))>>7)
#define DC_SCRAMBLE_ACCESS_get_nf_kc(data)                                    ((0x00000080&(data))>>7)
#define DC_SCRAMBLE_ACCESS_ve_shift                                           (6)
#define DC_SCRAMBLE_ACCESS_ve_mask                                            (0x00000040)
#define DC_SCRAMBLE_ACCESS_ve(data)                                           (0x00000040&((data)<<6))
#define DC_SCRAMBLE_ACCESS_ve_src(data)                                       ((0x00000040&(data))>>6)
#define DC_SCRAMBLE_ACCESS_get_ve(data)                                       ((0x00000040&(data))>>6)
#define DC_SCRAMBLE_ACCESS_vde_shift                                          (5)
#define DC_SCRAMBLE_ACCESS_vde_mask                                           (0x00000020)
#define DC_SCRAMBLE_ACCESS_vde(data)                                          (0x00000020&((data)<<5))
#define DC_SCRAMBLE_ACCESS_vde_src(data)                                      ((0x00000020&(data))>>5)
#define DC_SCRAMBLE_ACCESS_get_vde(data)                                      ((0x00000020&(data))>>5)
#define DC_SCRAMBLE_ACCESS_ade_shift                                          (4)
#define DC_SCRAMBLE_ACCESS_ade_mask                                           (0x00000010)
#define DC_SCRAMBLE_ACCESS_ade(data)                                          (0x00000010&((data)<<4))
#define DC_SCRAMBLE_ACCESS_ade_src(data)                                      ((0x00000010&(data))>>4)
#define DC_SCRAMBLE_ACCESS_get_ade(data)                                      ((0x00000010&(data))>>4)
#define DC_SCRAMBLE_ACCESS_ae_shift                                           (3)
#define DC_SCRAMBLE_ACCESS_ae_mask                                            (0x00000008)
#define DC_SCRAMBLE_ACCESS_ae(data)                                           (0x00000008&((data)<<3))
#define DC_SCRAMBLE_ACCESS_ae_src(data)                                       ((0x00000008&(data))>>3)
#define DC_SCRAMBLE_ACCESS_get_ae(data)                                       ((0x00000008&(data))>>3)
#define DC_SCRAMBLE_ACCESS_md_kc_shift                                        (2)
#define DC_SCRAMBLE_ACCESS_md_kc_mask                                         (0x00000004)
#define DC_SCRAMBLE_ACCESS_md_kc(data)                                        (0x00000004&((data)<<2))
#define DC_SCRAMBLE_ACCESS_md_kc_src(data)                                    ((0x00000004&(data))>>2)
#define DC_SCRAMBLE_ACCESS_get_md_kc(data)                                    ((0x00000004&(data))>>2)
#define DC_SCRAMBLE_ACCESS_cp_kc_shift                                        (1)
#define DC_SCRAMBLE_ACCESS_cp_kc_mask                                         (0x00000002)
#define DC_SCRAMBLE_ACCESS_cp_kc(data)                                        (0x00000002&((data)<<1))
#define DC_SCRAMBLE_ACCESS_cp_kc_src(data)                                    ((0x00000002&(data))>>1)
#define DC_SCRAMBLE_ACCESS_get_cp_kc(data)                                    ((0x00000002&(data))>>1)
#define DC_SCRAMBLE_ACCESS_md_vc_shift                                        (0)
#define DC_SCRAMBLE_ACCESS_md_vc_mask                                         (0x00000001)
#define DC_SCRAMBLE_ACCESS_md_vc(data)                                        (0x00000001&((data)<<0))
#define DC_SCRAMBLE_ACCESS_md_vc_src(data)                                    ((0x00000001&(data))>>0)
#define DC_SCRAMBLE_ACCESS_get_md_vc(data)                                    ((0x00000001&(data))>>0)


#define DC_MEM_SCRAMBLE_START_0                                               0x18007620
#define DC_MEM_SCRAMBLE_START_1                                               0x18007624
#define DC_MEM_SCRAMBLE_START_2                                               0x18007628
#define DC_MEM_SCRAMBLE_START_3                                               0x1800762C
#define DC_MEM_SCRAMBLE_START_4                                               0x18007630
#define DC_MEM_SCRAMBLE_START_5                                               0x18007634
#define DC_MEM_SCRAMBLE_START_6                                               0x18007638
#define DC_MEM_SCRAMBLE_START_7                                               0x1800763C
#define DC_MEM_SCRAMBLE_START_0_reg_addr                                      "0xB8007620"
#define DC_MEM_SCRAMBLE_START_1_reg_addr                                      "0xB8007624"
#define DC_MEM_SCRAMBLE_START_2_reg_addr                                      "0xB8007628"
#define DC_MEM_SCRAMBLE_START_3_reg_addr                                      "0xB800762C"
#define DC_MEM_SCRAMBLE_START_4_reg_addr                                      "0xB8007630"
#define DC_MEM_SCRAMBLE_START_5_reg_addr                                      "0xB8007634"
#define DC_MEM_SCRAMBLE_START_6_reg_addr                                      "0xB8007638"
#define DC_MEM_SCRAMBLE_START_7_reg_addr                                      "0xB800763C"
#define DC_MEM_SCRAMBLE_START_0_reg                                           0xB8007620
#define DC_MEM_SCRAMBLE_START_1_reg                                           0xB8007624
#define DC_MEM_SCRAMBLE_START_2_reg                                           0xB8007628
#define DC_MEM_SCRAMBLE_START_3_reg                                           0xB800762C
#define DC_MEM_SCRAMBLE_START_4_reg                                           0xB8007630
#define DC_MEM_SCRAMBLE_START_5_reg                                           0xB8007634
#define DC_MEM_SCRAMBLE_START_6_reg                                           0xB8007638
#define DC_MEM_SCRAMBLE_START_7_reg                                           0xB800763C
#define set_DC_MEM_SCRAMBLE_START_0_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_START_0_reg)=data)
#define set_DC_MEM_SCRAMBLE_START_1_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_START_1_reg)=data)
#define set_DC_MEM_SCRAMBLE_START_2_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_START_2_reg)=data)
#define set_DC_MEM_SCRAMBLE_START_3_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_START_3_reg)=data)
#define set_DC_MEM_SCRAMBLE_START_4_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_START_4_reg)=data)
#define set_DC_MEM_SCRAMBLE_START_5_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_START_5_reg)=data)
#define set_DC_MEM_SCRAMBLE_START_6_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_START_6_reg)=data)
#define set_DC_MEM_SCRAMBLE_START_7_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_START_7_reg)=data)
#define get_DC_MEM_SCRAMBLE_START_0_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_START_0_reg))
#define get_DC_MEM_SCRAMBLE_START_1_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_START_1_reg))
#define get_DC_MEM_SCRAMBLE_START_2_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_START_2_reg))
#define get_DC_MEM_SCRAMBLE_START_3_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_START_3_reg))
#define get_DC_MEM_SCRAMBLE_START_4_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_START_4_reg))
#define get_DC_MEM_SCRAMBLE_START_5_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_START_5_reg))
#define get_DC_MEM_SCRAMBLE_START_6_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_START_6_reg))
#define get_DC_MEM_SCRAMBLE_START_7_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_START_7_reg))
#define DC_MEM_SCRAMBLE_START_0_inst_adr                                      "0x0088"
#define DC_MEM_SCRAMBLE_START_1_inst_adr                                      "0x0089"
#define DC_MEM_SCRAMBLE_START_2_inst_adr                                      "0x008A"
#define DC_MEM_SCRAMBLE_START_3_inst_adr                                      "0x008B"
#define DC_MEM_SCRAMBLE_START_4_inst_adr                                      "0x008C"
#define DC_MEM_SCRAMBLE_START_5_inst_adr                                      "0x008D"
#define DC_MEM_SCRAMBLE_START_6_inst_adr                                      "0x008E"
#define DC_MEM_SCRAMBLE_START_7_inst_adr                                      "0x008F"
#define DC_MEM_SCRAMBLE_START_0_inst                                          0x0088
#define DC_MEM_SCRAMBLE_START_1_inst                                          0x0089
#define DC_MEM_SCRAMBLE_START_2_inst                                          0x008A
#define DC_MEM_SCRAMBLE_START_3_inst                                          0x008B
#define DC_MEM_SCRAMBLE_START_4_inst                                          0x008C
#define DC_MEM_SCRAMBLE_START_5_inst                                          0x008D
#define DC_MEM_SCRAMBLE_START_6_inst                                          0x008E
#define DC_MEM_SCRAMBLE_START_7_inst                                          0x008F
#define DC_MEM_SCRAMBLE_START_addr_shift                                      (12)
#define DC_MEM_SCRAMBLE_START_addr_mask                                       (0xFFFFF000)
#define DC_MEM_SCRAMBLE_START_addr(data)                                      (0xFFFFF000&((data)<<12))
#define DC_MEM_SCRAMBLE_START_addr_src(data)                                  ((0xFFFFF000&(data))>>12)
#define DC_MEM_SCRAMBLE_START_get_addr(data)                                  ((0xFFFFF000&(data))>>12)


#define DC_MEM_SCRAMBLE_END_0                                                 0x18007640
#define DC_MEM_SCRAMBLE_END_1                                                 0x18007644
#define DC_MEM_SCRAMBLE_END_2                                                 0x18007648
#define DC_MEM_SCRAMBLE_END_3                                                 0x1800764C
#define DC_MEM_SCRAMBLE_END_4                                                 0x18007650
#define DC_MEM_SCRAMBLE_END_5                                                 0x18007654
#define DC_MEM_SCRAMBLE_END_6                                                 0x18007658
#define DC_MEM_SCRAMBLE_END_7                                                 0x1800765C
#define DC_MEM_SCRAMBLE_END_0_reg_addr                                        "0xB8007640"
#define DC_MEM_SCRAMBLE_END_1_reg_addr                                        "0xB8007644"
#define DC_MEM_SCRAMBLE_END_2_reg_addr                                        "0xB8007648"
#define DC_MEM_SCRAMBLE_END_3_reg_addr                                        "0xB800764C"
#define DC_MEM_SCRAMBLE_END_4_reg_addr                                        "0xB8007650"
#define DC_MEM_SCRAMBLE_END_5_reg_addr                                        "0xB8007654"
#define DC_MEM_SCRAMBLE_END_6_reg_addr                                        "0xB8007658"
#define DC_MEM_SCRAMBLE_END_7_reg_addr                                        "0xB800765C"
#define DC_MEM_SCRAMBLE_END_0_reg                                             0xB8007640
#define DC_MEM_SCRAMBLE_END_1_reg                                             0xB8007644
#define DC_MEM_SCRAMBLE_END_2_reg                                             0xB8007648
#define DC_MEM_SCRAMBLE_END_3_reg                                             0xB800764C
#define DC_MEM_SCRAMBLE_END_4_reg                                             0xB8007650
#define DC_MEM_SCRAMBLE_END_5_reg                                             0xB8007654
#define DC_MEM_SCRAMBLE_END_6_reg                                             0xB8007658
#define DC_MEM_SCRAMBLE_END_7_reg                                             0xB800765C
#define set_DC_MEM_SCRAMBLE_END_0_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_END_0_reg)=data)
#define set_DC_MEM_SCRAMBLE_END_1_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_END_1_reg)=data)
#define set_DC_MEM_SCRAMBLE_END_2_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_END_2_reg)=data)
#define set_DC_MEM_SCRAMBLE_END_3_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_END_3_reg)=data)
#define set_DC_MEM_SCRAMBLE_END_4_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_END_4_reg)=data)
#define set_DC_MEM_SCRAMBLE_END_5_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_END_5_reg)=data)
#define set_DC_MEM_SCRAMBLE_END_6_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_END_6_reg)=data)
#define set_DC_MEM_SCRAMBLE_END_7_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_END_7_reg)=data)
#define get_DC_MEM_SCRAMBLE_END_0_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_END_0_reg))
#define get_DC_MEM_SCRAMBLE_END_1_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_END_1_reg))
#define get_DC_MEM_SCRAMBLE_END_2_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_END_2_reg))
#define get_DC_MEM_SCRAMBLE_END_3_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_END_3_reg))
#define get_DC_MEM_SCRAMBLE_END_4_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_END_4_reg))
#define get_DC_MEM_SCRAMBLE_END_5_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_END_5_reg))
#define get_DC_MEM_SCRAMBLE_END_6_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_END_6_reg))
#define get_DC_MEM_SCRAMBLE_END_7_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_END_7_reg))
#define DC_MEM_SCRAMBLE_END_0_inst_adr                                        "0x0090"
#define DC_MEM_SCRAMBLE_END_1_inst_adr                                        "0x0091"
#define DC_MEM_SCRAMBLE_END_2_inst_adr                                        "0x0092"
#define DC_MEM_SCRAMBLE_END_3_inst_adr                                        "0x0093"
#define DC_MEM_SCRAMBLE_END_4_inst_adr                                        "0x0094"
#define DC_MEM_SCRAMBLE_END_5_inst_adr                                        "0x0095"
#define DC_MEM_SCRAMBLE_END_6_inst_adr                                        "0x0096"
#define DC_MEM_SCRAMBLE_END_7_inst_adr                                        "0x0097"
#define DC_MEM_SCRAMBLE_END_0_inst                                            0x0090
#define DC_MEM_SCRAMBLE_END_1_inst                                            0x0091
#define DC_MEM_SCRAMBLE_END_2_inst                                            0x0092
#define DC_MEM_SCRAMBLE_END_3_inst                                            0x0093
#define DC_MEM_SCRAMBLE_END_4_inst                                            0x0094
#define DC_MEM_SCRAMBLE_END_5_inst                                            0x0095
#define DC_MEM_SCRAMBLE_END_6_inst                                            0x0096
#define DC_MEM_SCRAMBLE_END_7_inst                                            0x0097
#define DC_MEM_SCRAMBLE_END_addr_shift                                        (12)
#define DC_MEM_SCRAMBLE_END_addr_mask                                         (0xFFFFF000)
#define DC_MEM_SCRAMBLE_END_addr(data)                                        (0xFFFFF000&((data)<<12))
#define DC_MEM_SCRAMBLE_END_addr_src(data)                                    ((0xFFFFF000&(data))>>12)
#define DC_MEM_SCRAMBLE_END_get_addr(data)                                    ((0xFFFFF000&(data))>>12)


#define DC_MEM_SCRAMBLE_BUF_CUR0_0                                            0x18007660
#define DC_MEM_SCRAMBLE_BUF_CUR0_1                                            0x18007664
#define DC_MEM_SCRAMBLE_BUF_CUR0_2                                            0x18007668
#define DC_MEM_SCRAMBLE_BUF_CUR0_3                                            0x1800766C
#define DC_MEM_SCRAMBLE_BUF_CUR0_4                                            0x18007670
#define DC_MEM_SCRAMBLE_BUF_CUR0_5                                            0x18007674
#define DC_MEM_SCRAMBLE_BUF_CUR0_6                                            0x18007678
#define DC_MEM_SCRAMBLE_BUF_CUR0_7                                            0x1800767C
#define DC_MEM_SCRAMBLE_BUF_CUR0_0_reg_addr                                   "0xB8007660"
#define DC_MEM_SCRAMBLE_BUF_CUR0_1_reg_addr                                   "0xB8007664"
#define DC_MEM_SCRAMBLE_BUF_CUR0_2_reg_addr                                   "0xB8007668"
#define DC_MEM_SCRAMBLE_BUF_CUR0_3_reg_addr                                   "0xB800766C"
#define DC_MEM_SCRAMBLE_BUF_CUR0_4_reg_addr                                   "0xB8007670"
#define DC_MEM_SCRAMBLE_BUF_CUR0_5_reg_addr                                   "0xB8007674"
#define DC_MEM_SCRAMBLE_BUF_CUR0_6_reg_addr                                   "0xB8007678"
#define DC_MEM_SCRAMBLE_BUF_CUR0_7_reg_addr                                   "0xB800767C"
#define DC_MEM_SCRAMBLE_BUF_CUR0_0_reg                                        0xB8007660
#define DC_MEM_SCRAMBLE_BUF_CUR0_1_reg                                        0xB8007664
#define DC_MEM_SCRAMBLE_BUF_CUR0_2_reg                                        0xB8007668
#define DC_MEM_SCRAMBLE_BUF_CUR0_3_reg                                        0xB800766C
#define DC_MEM_SCRAMBLE_BUF_CUR0_4_reg                                        0xB8007670
#define DC_MEM_SCRAMBLE_BUF_CUR0_5_reg                                        0xB8007674
#define DC_MEM_SCRAMBLE_BUF_CUR0_6_reg                                        0xB8007678
#define DC_MEM_SCRAMBLE_BUF_CUR0_7_reg                                        0xB800767C
#define set_DC_MEM_SCRAMBLE_BUF_CUR0_0_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR0_0_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR0_1_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR0_1_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR0_2_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR0_2_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR0_3_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR0_3_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR0_4_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR0_4_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR0_5_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR0_5_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR0_6_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR0_6_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR0_7_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR0_7_reg)=data)
#define get_DC_MEM_SCRAMBLE_BUF_CUR0_0_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR0_0_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR0_1_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR0_1_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR0_2_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR0_2_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR0_3_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR0_3_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR0_4_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR0_4_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR0_5_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR0_5_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR0_6_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR0_6_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR0_7_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR0_7_reg))
#define DC_MEM_SCRAMBLE_BUF_CUR0_0_inst_adr                                   "0x0098"
#define DC_MEM_SCRAMBLE_BUF_CUR0_1_inst_adr                                   "0x0099"
#define DC_MEM_SCRAMBLE_BUF_CUR0_2_inst_adr                                   "0x009A"
#define DC_MEM_SCRAMBLE_BUF_CUR0_3_inst_adr                                   "0x009B"
#define DC_MEM_SCRAMBLE_BUF_CUR0_4_inst_adr                                   "0x009C"
#define DC_MEM_SCRAMBLE_BUF_CUR0_5_inst_adr                                   "0x009D"
#define DC_MEM_SCRAMBLE_BUF_CUR0_6_inst_adr                                   "0x009E"
#define DC_MEM_SCRAMBLE_BUF_CUR0_7_inst_adr                                   "0x009F"
#define DC_MEM_SCRAMBLE_BUF_CUR0_0_inst                                       0x0098
#define DC_MEM_SCRAMBLE_BUF_CUR0_1_inst                                       0x0099
#define DC_MEM_SCRAMBLE_BUF_CUR0_2_inst                                       0x009A
#define DC_MEM_SCRAMBLE_BUF_CUR0_3_inst                                       0x009B
#define DC_MEM_SCRAMBLE_BUF_CUR0_4_inst                                       0x009C
#define DC_MEM_SCRAMBLE_BUF_CUR0_5_inst                                       0x009D
#define DC_MEM_SCRAMBLE_BUF_CUR0_6_inst                                       0x009E
#define DC_MEM_SCRAMBLE_BUF_CUR0_7_inst                                       0x009F
#define DC_MEM_SCRAMBLE_BUF_CUR0_key1_shift                                   (16)
#define DC_MEM_SCRAMBLE_BUF_CUR0_key1_mask                                    (0xFFFF0000)
#define DC_MEM_SCRAMBLE_BUF_CUR0_key1(data)                                   (0xFFFF0000&((data)<<16))
#define DC_MEM_SCRAMBLE_BUF_CUR0_key1_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_CUR0_get_key1(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_CUR0_key0_shift                                   (0)
#define DC_MEM_SCRAMBLE_BUF_CUR0_key0_mask                                    (0x0000FFFF)
#define DC_MEM_SCRAMBLE_BUF_CUR0_key0(data)                                   (0x0000FFFF&((data)<<0))
#define DC_MEM_SCRAMBLE_BUF_CUR0_key0_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC_MEM_SCRAMBLE_BUF_CUR0_get_key0(data)                               ((0x0000FFFF&(data))>>0)


#define DC_MEM_SCRAMBLE_BUF_CUR1_0                                            0x18007680
#define DC_MEM_SCRAMBLE_BUF_CUR1_1                                            0x18007684
#define DC_MEM_SCRAMBLE_BUF_CUR1_2                                            0x18007688
#define DC_MEM_SCRAMBLE_BUF_CUR1_3                                            0x1800768C
#define DC_MEM_SCRAMBLE_BUF_CUR1_4                                            0x18007690
#define DC_MEM_SCRAMBLE_BUF_CUR1_5                                            0x18007694
#define DC_MEM_SCRAMBLE_BUF_CUR1_6                                            0x18007698
#define DC_MEM_SCRAMBLE_BUF_CUR1_7                                            0x1800769C
#define DC_MEM_SCRAMBLE_BUF_CUR1_0_reg_addr                                   "0xB8007680"
#define DC_MEM_SCRAMBLE_BUF_CUR1_1_reg_addr                                   "0xB8007684"
#define DC_MEM_SCRAMBLE_BUF_CUR1_2_reg_addr                                   "0xB8007688"
#define DC_MEM_SCRAMBLE_BUF_CUR1_3_reg_addr                                   "0xB800768C"
#define DC_MEM_SCRAMBLE_BUF_CUR1_4_reg_addr                                   "0xB8007690"
#define DC_MEM_SCRAMBLE_BUF_CUR1_5_reg_addr                                   "0xB8007694"
#define DC_MEM_SCRAMBLE_BUF_CUR1_6_reg_addr                                   "0xB8007698"
#define DC_MEM_SCRAMBLE_BUF_CUR1_7_reg_addr                                   "0xB800769C"
#define DC_MEM_SCRAMBLE_BUF_CUR1_0_reg                                        0xB8007680
#define DC_MEM_SCRAMBLE_BUF_CUR1_1_reg                                        0xB8007684
#define DC_MEM_SCRAMBLE_BUF_CUR1_2_reg                                        0xB8007688
#define DC_MEM_SCRAMBLE_BUF_CUR1_3_reg                                        0xB800768C
#define DC_MEM_SCRAMBLE_BUF_CUR1_4_reg                                        0xB8007690
#define DC_MEM_SCRAMBLE_BUF_CUR1_5_reg                                        0xB8007694
#define DC_MEM_SCRAMBLE_BUF_CUR1_6_reg                                        0xB8007698
#define DC_MEM_SCRAMBLE_BUF_CUR1_7_reg                                        0xB800769C
#define set_DC_MEM_SCRAMBLE_BUF_CUR1_0_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR1_0_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR1_1_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR1_1_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR1_2_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR1_2_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR1_3_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR1_3_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR1_4_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR1_4_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR1_5_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR1_5_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR1_6_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR1_6_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR1_7_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR1_7_reg)=data)
#define get_DC_MEM_SCRAMBLE_BUF_CUR1_0_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR1_0_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR1_1_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR1_1_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR1_2_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR1_2_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR1_3_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR1_3_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR1_4_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR1_4_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR1_5_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR1_5_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR1_6_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR1_6_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR1_7_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR1_7_reg))
#define DC_MEM_SCRAMBLE_BUF_CUR1_0_inst_adr                                   "0x00A0"
#define DC_MEM_SCRAMBLE_BUF_CUR1_1_inst_adr                                   "0x00A1"
#define DC_MEM_SCRAMBLE_BUF_CUR1_2_inst_adr                                   "0x00A2"
#define DC_MEM_SCRAMBLE_BUF_CUR1_3_inst_adr                                   "0x00A3"
#define DC_MEM_SCRAMBLE_BUF_CUR1_4_inst_adr                                   "0x00A4"
#define DC_MEM_SCRAMBLE_BUF_CUR1_5_inst_adr                                   "0x00A5"
#define DC_MEM_SCRAMBLE_BUF_CUR1_6_inst_adr                                   "0x00A6"
#define DC_MEM_SCRAMBLE_BUF_CUR1_7_inst_adr                                   "0x00A7"
#define DC_MEM_SCRAMBLE_BUF_CUR1_0_inst                                       0x00A0
#define DC_MEM_SCRAMBLE_BUF_CUR1_1_inst                                       0x00A1
#define DC_MEM_SCRAMBLE_BUF_CUR1_2_inst                                       0x00A2
#define DC_MEM_SCRAMBLE_BUF_CUR1_3_inst                                       0x00A3
#define DC_MEM_SCRAMBLE_BUF_CUR1_4_inst                                       0x00A4
#define DC_MEM_SCRAMBLE_BUF_CUR1_5_inst                                       0x00A5
#define DC_MEM_SCRAMBLE_BUF_CUR1_6_inst                                       0x00A6
#define DC_MEM_SCRAMBLE_BUF_CUR1_7_inst                                       0x00A7
#define DC_MEM_SCRAMBLE_BUF_CUR1_key3_shift                                   (16)
#define DC_MEM_SCRAMBLE_BUF_CUR1_key3_mask                                    (0xFFFF0000)
#define DC_MEM_SCRAMBLE_BUF_CUR1_key3(data)                                   (0xFFFF0000&((data)<<16))
#define DC_MEM_SCRAMBLE_BUF_CUR1_key3_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_CUR1_get_key3(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_CUR1_key2_shift                                   (0)
#define DC_MEM_SCRAMBLE_BUF_CUR1_key2_mask                                    (0x0000FFFF)
#define DC_MEM_SCRAMBLE_BUF_CUR1_key2(data)                                   (0x0000FFFF&((data)<<0))
#define DC_MEM_SCRAMBLE_BUF_CUR1_key2_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC_MEM_SCRAMBLE_BUF_CUR1_get_key2(data)                               ((0x0000FFFF&(data))>>0)


#define DC_MEM_SCRAMBLE_BUF_CUR2_0                                            0x180076A0
#define DC_MEM_SCRAMBLE_BUF_CUR2_1                                            0x180076A4
#define DC_MEM_SCRAMBLE_BUF_CUR2_2                                            0x180076A8
#define DC_MEM_SCRAMBLE_BUF_CUR2_3                                            0x180076AC
#define DC_MEM_SCRAMBLE_BUF_CUR2_4                                            0x180076B0
#define DC_MEM_SCRAMBLE_BUF_CUR2_5                                            0x180076B4
#define DC_MEM_SCRAMBLE_BUF_CUR2_6                                            0x180076B8
#define DC_MEM_SCRAMBLE_BUF_CUR2_7                                            0x180076BC
#define DC_MEM_SCRAMBLE_BUF_CUR2_0_reg_addr                                   "0xB80076A0"
#define DC_MEM_SCRAMBLE_BUF_CUR2_1_reg_addr                                   "0xB80076A4"
#define DC_MEM_SCRAMBLE_BUF_CUR2_2_reg_addr                                   "0xB80076A8"
#define DC_MEM_SCRAMBLE_BUF_CUR2_3_reg_addr                                   "0xB80076AC"
#define DC_MEM_SCRAMBLE_BUF_CUR2_4_reg_addr                                   "0xB80076B0"
#define DC_MEM_SCRAMBLE_BUF_CUR2_5_reg_addr                                   "0xB80076B4"
#define DC_MEM_SCRAMBLE_BUF_CUR2_6_reg_addr                                   "0xB80076B8"
#define DC_MEM_SCRAMBLE_BUF_CUR2_7_reg_addr                                   "0xB80076BC"
#define DC_MEM_SCRAMBLE_BUF_CUR2_0_reg                                        0xB80076A0
#define DC_MEM_SCRAMBLE_BUF_CUR2_1_reg                                        0xB80076A4
#define DC_MEM_SCRAMBLE_BUF_CUR2_2_reg                                        0xB80076A8
#define DC_MEM_SCRAMBLE_BUF_CUR2_3_reg                                        0xB80076AC
#define DC_MEM_SCRAMBLE_BUF_CUR2_4_reg                                        0xB80076B0
#define DC_MEM_SCRAMBLE_BUF_CUR2_5_reg                                        0xB80076B4
#define DC_MEM_SCRAMBLE_BUF_CUR2_6_reg                                        0xB80076B8
#define DC_MEM_SCRAMBLE_BUF_CUR2_7_reg                                        0xB80076BC
#define set_DC_MEM_SCRAMBLE_BUF_CUR2_0_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR2_0_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR2_1_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR2_1_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR2_2_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR2_2_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR2_3_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR2_3_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR2_4_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR2_4_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR2_5_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR2_5_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR2_6_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR2_6_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR2_7_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR2_7_reg)=data)
#define get_DC_MEM_SCRAMBLE_BUF_CUR2_0_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR2_0_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR2_1_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR2_1_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR2_2_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR2_2_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR2_3_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR2_3_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR2_4_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR2_4_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR2_5_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR2_5_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR2_6_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR2_6_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR2_7_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR2_7_reg))
#define DC_MEM_SCRAMBLE_BUF_CUR2_0_inst_adr                                   "0x00A8"
#define DC_MEM_SCRAMBLE_BUF_CUR2_1_inst_adr                                   "0x00A9"
#define DC_MEM_SCRAMBLE_BUF_CUR2_2_inst_adr                                   "0x00AA"
#define DC_MEM_SCRAMBLE_BUF_CUR2_3_inst_adr                                   "0x00AB"
#define DC_MEM_SCRAMBLE_BUF_CUR2_4_inst_adr                                   "0x00AC"
#define DC_MEM_SCRAMBLE_BUF_CUR2_5_inst_adr                                   "0x00AD"
#define DC_MEM_SCRAMBLE_BUF_CUR2_6_inst_adr                                   "0x00AE"
#define DC_MEM_SCRAMBLE_BUF_CUR2_7_inst_adr                                   "0x00AF"
#define DC_MEM_SCRAMBLE_BUF_CUR2_0_inst                                       0x00A8
#define DC_MEM_SCRAMBLE_BUF_CUR2_1_inst                                       0x00A9
#define DC_MEM_SCRAMBLE_BUF_CUR2_2_inst                                       0x00AA
#define DC_MEM_SCRAMBLE_BUF_CUR2_3_inst                                       0x00AB
#define DC_MEM_SCRAMBLE_BUF_CUR2_4_inst                                       0x00AC
#define DC_MEM_SCRAMBLE_BUF_CUR2_5_inst                                       0x00AD
#define DC_MEM_SCRAMBLE_BUF_CUR2_6_inst                                       0x00AE
#define DC_MEM_SCRAMBLE_BUF_CUR2_7_inst                                       0x00AF
#define DC_MEM_SCRAMBLE_BUF_CUR2_key5_shift                                   (16)
#define DC_MEM_SCRAMBLE_BUF_CUR2_key5_mask                                    (0xFFFF0000)
#define DC_MEM_SCRAMBLE_BUF_CUR2_key5(data)                                   (0xFFFF0000&((data)<<16))
#define DC_MEM_SCRAMBLE_BUF_CUR2_key5_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_CUR2_get_key5(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_CUR2_key4_shift                                   (0)
#define DC_MEM_SCRAMBLE_BUF_CUR2_key4_mask                                    (0x0000FFFF)
#define DC_MEM_SCRAMBLE_BUF_CUR2_key4(data)                                   (0x0000FFFF&((data)<<0))
#define DC_MEM_SCRAMBLE_BUF_CUR2_key4_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC_MEM_SCRAMBLE_BUF_CUR2_get_key4(data)                               ((0x0000FFFF&(data))>>0)


#define DC_MEM_SCRAMBLE_BUF_CUR3_0                                            0x180076C0
#define DC_MEM_SCRAMBLE_BUF_CUR3_1                                            0x180076C4
#define DC_MEM_SCRAMBLE_BUF_CUR3_2                                            0x180076C8
#define DC_MEM_SCRAMBLE_BUF_CUR3_3                                            0x180076CC
#define DC_MEM_SCRAMBLE_BUF_CUR3_4                                            0x180076D0
#define DC_MEM_SCRAMBLE_BUF_CUR3_5                                            0x180076D4
#define DC_MEM_SCRAMBLE_BUF_CUR3_6                                            0x180076D8
#define DC_MEM_SCRAMBLE_BUF_CUR3_7                                            0x180076DC
#define DC_MEM_SCRAMBLE_BUF_CUR3_0_reg_addr                                   "0xB80076C0"
#define DC_MEM_SCRAMBLE_BUF_CUR3_1_reg_addr                                   "0xB80076C4"
#define DC_MEM_SCRAMBLE_BUF_CUR3_2_reg_addr                                   "0xB80076C8"
#define DC_MEM_SCRAMBLE_BUF_CUR3_3_reg_addr                                   "0xB80076CC"
#define DC_MEM_SCRAMBLE_BUF_CUR3_4_reg_addr                                   "0xB80076D0"
#define DC_MEM_SCRAMBLE_BUF_CUR3_5_reg_addr                                   "0xB80076D4"
#define DC_MEM_SCRAMBLE_BUF_CUR3_6_reg_addr                                   "0xB80076D8"
#define DC_MEM_SCRAMBLE_BUF_CUR3_7_reg_addr                                   "0xB80076DC"
#define DC_MEM_SCRAMBLE_BUF_CUR3_0_reg                                        0xB80076C0
#define DC_MEM_SCRAMBLE_BUF_CUR3_1_reg                                        0xB80076C4
#define DC_MEM_SCRAMBLE_BUF_CUR3_2_reg                                        0xB80076C8
#define DC_MEM_SCRAMBLE_BUF_CUR3_3_reg                                        0xB80076CC
#define DC_MEM_SCRAMBLE_BUF_CUR3_4_reg                                        0xB80076D0
#define DC_MEM_SCRAMBLE_BUF_CUR3_5_reg                                        0xB80076D4
#define DC_MEM_SCRAMBLE_BUF_CUR3_6_reg                                        0xB80076D8
#define DC_MEM_SCRAMBLE_BUF_CUR3_7_reg                                        0xB80076DC
#define set_DC_MEM_SCRAMBLE_BUF_CUR3_0_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR3_0_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR3_1_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR3_1_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR3_2_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR3_2_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR3_3_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR3_3_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR3_4_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR3_4_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR3_5_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR3_5_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR3_6_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR3_6_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR3_7_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR3_7_reg)=data)
#define get_DC_MEM_SCRAMBLE_BUF_CUR3_0_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR3_0_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR3_1_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR3_1_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR3_2_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR3_2_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR3_3_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR3_3_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR3_4_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR3_4_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR3_5_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR3_5_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR3_6_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR3_6_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR3_7_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR3_7_reg))
#define DC_MEM_SCRAMBLE_BUF_CUR3_0_inst_adr                                   "0x00B0"
#define DC_MEM_SCRAMBLE_BUF_CUR3_1_inst_adr                                   "0x00B1"
#define DC_MEM_SCRAMBLE_BUF_CUR3_2_inst_adr                                   "0x00B2"
#define DC_MEM_SCRAMBLE_BUF_CUR3_3_inst_adr                                   "0x00B3"
#define DC_MEM_SCRAMBLE_BUF_CUR3_4_inst_adr                                   "0x00B4"
#define DC_MEM_SCRAMBLE_BUF_CUR3_5_inst_adr                                   "0x00B5"
#define DC_MEM_SCRAMBLE_BUF_CUR3_6_inst_adr                                   "0x00B6"
#define DC_MEM_SCRAMBLE_BUF_CUR3_7_inst_adr                                   "0x00B7"
#define DC_MEM_SCRAMBLE_BUF_CUR3_0_inst                                       0x00B0
#define DC_MEM_SCRAMBLE_BUF_CUR3_1_inst                                       0x00B1
#define DC_MEM_SCRAMBLE_BUF_CUR3_2_inst                                       0x00B2
#define DC_MEM_SCRAMBLE_BUF_CUR3_3_inst                                       0x00B3
#define DC_MEM_SCRAMBLE_BUF_CUR3_4_inst                                       0x00B4
#define DC_MEM_SCRAMBLE_BUF_CUR3_5_inst                                       0x00B5
#define DC_MEM_SCRAMBLE_BUF_CUR3_6_inst                                       0x00B6
#define DC_MEM_SCRAMBLE_BUF_CUR3_7_inst                                       0x00B7
#define DC_MEM_SCRAMBLE_BUF_CUR3_key7_shift                                   (16)
#define DC_MEM_SCRAMBLE_BUF_CUR3_key7_mask                                    (0xFFFF0000)
#define DC_MEM_SCRAMBLE_BUF_CUR3_key7(data)                                   (0xFFFF0000&((data)<<16))
#define DC_MEM_SCRAMBLE_BUF_CUR3_key7_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_CUR3_get_key7(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_CUR3_key6_shift                                   (0)
#define DC_MEM_SCRAMBLE_BUF_CUR3_key6_mask                                    (0x0000FFFF)
#define DC_MEM_SCRAMBLE_BUF_CUR3_key6(data)                                   (0x0000FFFF&((data)<<0))
#define DC_MEM_SCRAMBLE_BUF_CUR3_key6_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC_MEM_SCRAMBLE_BUF_CUR3_get_key6(data)                               ((0x0000FFFF&(data))>>0)


#define DC_MEM_SCRAMBLE_BUF_CUR4_0                                            0x180076E0
#define DC_MEM_SCRAMBLE_BUF_CUR4_1                                            0x180076E4
#define DC_MEM_SCRAMBLE_BUF_CUR4_2                                            0x180076E8
#define DC_MEM_SCRAMBLE_BUF_CUR4_3                                            0x180076EC
#define DC_MEM_SCRAMBLE_BUF_CUR4_4                                            0x180076F0
#define DC_MEM_SCRAMBLE_BUF_CUR4_5                                            0x180076F4
#define DC_MEM_SCRAMBLE_BUF_CUR4_6                                            0x180076F8
#define DC_MEM_SCRAMBLE_BUF_CUR4_7                                            0x180076FC
#define DC_MEM_SCRAMBLE_BUF_CUR4_0_reg_addr                                   "0xB80076E0"
#define DC_MEM_SCRAMBLE_BUF_CUR4_1_reg_addr                                   "0xB80076E4"
#define DC_MEM_SCRAMBLE_BUF_CUR4_2_reg_addr                                   "0xB80076E8"
#define DC_MEM_SCRAMBLE_BUF_CUR4_3_reg_addr                                   "0xB80076EC"
#define DC_MEM_SCRAMBLE_BUF_CUR4_4_reg_addr                                   "0xB80076F0"
#define DC_MEM_SCRAMBLE_BUF_CUR4_5_reg_addr                                   "0xB80076F4"
#define DC_MEM_SCRAMBLE_BUF_CUR4_6_reg_addr                                   "0xB80076F8"
#define DC_MEM_SCRAMBLE_BUF_CUR4_7_reg_addr                                   "0xB80076FC"
#define DC_MEM_SCRAMBLE_BUF_CUR4_0_reg                                        0xB80076E0
#define DC_MEM_SCRAMBLE_BUF_CUR4_1_reg                                        0xB80076E4
#define DC_MEM_SCRAMBLE_BUF_CUR4_2_reg                                        0xB80076E8
#define DC_MEM_SCRAMBLE_BUF_CUR4_3_reg                                        0xB80076EC
#define DC_MEM_SCRAMBLE_BUF_CUR4_4_reg                                        0xB80076F0
#define DC_MEM_SCRAMBLE_BUF_CUR4_5_reg                                        0xB80076F4
#define DC_MEM_SCRAMBLE_BUF_CUR4_6_reg                                        0xB80076F8
#define DC_MEM_SCRAMBLE_BUF_CUR4_7_reg                                        0xB80076FC
#define set_DC_MEM_SCRAMBLE_BUF_CUR4_0_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR4_0_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR4_1_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR4_1_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR4_2_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR4_2_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR4_3_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR4_3_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR4_4_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR4_4_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR4_5_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR4_5_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR4_6_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR4_6_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR4_7_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR4_7_reg)=data)
#define get_DC_MEM_SCRAMBLE_BUF_CUR4_0_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR4_0_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR4_1_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR4_1_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR4_2_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR4_2_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR4_3_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR4_3_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR4_4_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR4_4_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR4_5_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR4_5_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR4_6_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR4_6_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR4_7_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR4_7_reg))
#define DC_MEM_SCRAMBLE_BUF_CUR4_0_inst_adr                                   "0x00B8"
#define DC_MEM_SCRAMBLE_BUF_CUR4_1_inst_adr                                   "0x00B9"
#define DC_MEM_SCRAMBLE_BUF_CUR4_2_inst_adr                                   "0x00BA"
#define DC_MEM_SCRAMBLE_BUF_CUR4_3_inst_adr                                   "0x00BB"
#define DC_MEM_SCRAMBLE_BUF_CUR4_4_inst_adr                                   "0x00BC"
#define DC_MEM_SCRAMBLE_BUF_CUR4_5_inst_adr                                   "0x00BD"
#define DC_MEM_SCRAMBLE_BUF_CUR4_6_inst_adr                                   "0x00BE"
#define DC_MEM_SCRAMBLE_BUF_CUR4_7_inst_adr                                   "0x00BF"
#define DC_MEM_SCRAMBLE_BUF_CUR4_0_inst                                       0x00B8
#define DC_MEM_SCRAMBLE_BUF_CUR4_1_inst                                       0x00B9
#define DC_MEM_SCRAMBLE_BUF_CUR4_2_inst                                       0x00BA
#define DC_MEM_SCRAMBLE_BUF_CUR4_3_inst                                       0x00BB
#define DC_MEM_SCRAMBLE_BUF_CUR4_4_inst                                       0x00BC
#define DC_MEM_SCRAMBLE_BUF_CUR4_5_inst                                       0x00BD
#define DC_MEM_SCRAMBLE_BUF_CUR4_6_inst                                       0x00BE
#define DC_MEM_SCRAMBLE_BUF_CUR4_7_inst                                       0x00BF
#define DC_MEM_SCRAMBLE_BUF_CUR4_key9_shift                                   (16)
#define DC_MEM_SCRAMBLE_BUF_CUR4_key9_mask                                    (0xFFFF0000)
#define DC_MEM_SCRAMBLE_BUF_CUR4_key9(data)                                   (0xFFFF0000&((data)<<16))
#define DC_MEM_SCRAMBLE_BUF_CUR4_key9_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_CUR4_get_key9(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_CUR4_key8_shift                                   (0)
#define DC_MEM_SCRAMBLE_BUF_CUR4_key8_mask                                    (0x0000FFFF)
#define DC_MEM_SCRAMBLE_BUF_CUR4_key8(data)                                   (0x0000FFFF&((data)<<0))
#define DC_MEM_SCRAMBLE_BUF_CUR4_key8_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC_MEM_SCRAMBLE_BUF_CUR4_get_key8(data)                               ((0x0000FFFF&(data))>>0)


#define DC_MEM_SCRAMBLE_BUF_CUR5_0                                            0x18007700
#define DC_MEM_SCRAMBLE_BUF_CUR5_1                                            0x18007704
#define DC_MEM_SCRAMBLE_BUF_CUR5_2                                            0x18007708
#define DC_MEM_SCRAMBLE_BUF_CUR5_3                                            0x1800770C
#define DC_MEM_SCRAMBLE_BUF_CUR5_4                                            0x18007710
#define DC_MEM_SCRAMBLE_BUF_CUR5_5                                            0x18007714
#define DC_MEM_SCRAMBLE_BUF_CUR5_6                                            0x18007718
#define DC_MEM_SCRAMBLE_BUF_CUR5_7                                            0x1800771C
#define DC_MEM_SCRAMBLE_BUF_CUR5_0_reg_addr                                   "0xB8007700"
#define DC_MEM_SCRAMBLE_BUF_CUR5_1_reg_addr                                   "0xB8007704"
#define DC_MEM_SCRAMBLE_BUF_CUR5_2_reg_addr                                   "0xB8007708"
#define DC_MEM_SCRAMBLE_BUF_CUR5_3_reg_addr                                   "0xB800770C"
#define DC_MEM_SCRAMBLE_BUF_CUR5_4_reg_addr                                   "0xB8007710"
#define DC_MEM_SCRAMBLE_BUF_CUR5_5_reg_addr                                   "0xB8007714"
#define DC_MEM_SCRAMBLE_BUF_CUR5_6_reg_addr                                   "0xB8007718"
#define DC_MEM_SCRAMBLE_BUF_CUR5_7_reg_addr                                   "0xB800771C"
#define DC_MEM_SCRAMBLE_BUF_CUR5_0_reg                                        0xB8007700
#define DC_MEM_SCRAMBLE_BUF_CUR5_1_reg                                        0xB8007704
#define DC_MEM_SCRAMBLE_BUF_CUR5_2_reg                                        0xB8007708
#define DC_MEM_SCRAMBLE_BUF_CUR5_3_reg                                        0xB800770C
#define DC_MEM_SCRAMBLE_BUF_CUR5_4_reg                                        0xB8007710
#define DC_MEM_SCRAMBLE_BUF_CUR5_5_reg                                        0xB8007714
#define DC_MEM_SCRAMBLE_BUF_CUR5_6_reg                                        0xB8007718
#define DC_MEM_SCRAMBLE_BUF_CUR5_7_reg                                        0xB800771C
#define set_DC_MEM_SCRAMBLE_BUF_CUR5_0_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR5_0_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR5_1_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR5_1_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR5_2_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR5_2_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR5_3_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR5_3_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR5_4_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR5_4_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR5_5_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR5_5_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR5_6_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR5_6_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR5_7_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR5_7_reg)=data)
#define get_DC_MEM_SCRAMBLE_BUF_CUR5_0_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR5_0_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR5_1_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR5_1_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR5_2_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR5_2_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR5_3_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR5_3_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR5_4_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR5_4_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR5_5_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR5_5_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR5_6_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR5_6_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR5_7_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR5_7_reg))
#define DC_MEM_SCRAMBLE_BUF_CUR5_0_inst_adr                                   "0x00C0"
#define DC_MEM_SCRAMBLE_BUF_CUR5_1_inst_adr                                   "0x00C1"
#define DC_MEM_SCRAMBLE_BUF_CUR5_2_inst_adr                                   "0x00C2"
#define DC_MEM_SCRAMBLE_BUF_CUR5_3_inst_adr                                   "0x00C3"
#define DC_MEM_SCRAMBLE_BUF_CUR5_4_inst_adr                                   "0x00C4"
#define DC_MEM_SCRAMBLE_BUF_CUR5_5_inst_adr                                   "0x00C5"
#define DC_MEM_SCRAMBLE_BUF_CUR5_6_inst_adr                                   "0x00C6"
#define DC_MEM_SCRAMBLE_BUF_CUR5_7_inst_adr                                   "0x00C7"
#define DC_MEM_SCRAMBLE_BUF_CUR5_0_inst                                       0x00C0
#define DC_MEM_SCRAMBLE_BUF_CUR5_1_inst                                       0x00C1
#define DC_MEM_SCRAMBLE_BUF_CUR5_2_inst                                       0x00C2
#define DC_MEM_SCRAMBLE_BUF_CUR5_3_inst                                       0x00C3
#define DC_MEM_SCRAMBLE_BUF_CUR5_4_inst                                       0x00C4
#define DC_MEM_SCRAMBLE_BUF_CUR5_5_inst                                       0x00C5
#define DC_MEM_SCRAMBLE_BUF_CUR5_6_inst                                       0x00C6
#define DC_MEM_SCRAMBLE_BUF_CUR5_7_inst                                       0x00C7
#define DC_MEM_SCRAMBLE_BUF_CUR5_keyB_shift                                   (16)
#define DC_MEM_SCRAMBLE_BUF_CUR5_keyB_mask                                    (0xFFFF0000)
#define DC_MEM_SCRAMBLE_BUF_CUR5_keyB(data)                                   (0xFFFF0000&((data)<<16))
#define DC_MEM_SCRAMBLE_BUF_CUR5_keyB_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_CUR5_get_keyB(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_CUR5_keyA_shift                                   (0)
#define DC_MEM_SCRAMBLE_BUF_CUR5_keyA_mask                                    (0x0000FFFF)
#define DC_MEM_SCRAMBLE_BUF_CUR5_keyA(data)                                   (0x0000FFFF&((data)<<0))
#define DC_MEM_SCRAMBLE_BUF_CUR5_keyA_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC_MEM_SCRAMBLE_BUF_CUR5_get_keyA(data)                               ((0x0000FFFF&(data))>>0)


#define DC_MEM_SCRAMBLE_BUF_CUR6_0                                            0x18007720
#define DC_MEM_SCRAMBLE_BUF_CUR6_1                                            0x18007724
#define DC_MEM_SCRAMBLE_BUF_CUR6_2                                            0x18007728
#define DC_MEM_SCRAMBLE_BUF_CUR6_3                                            0x1800772C
#define DC_MEM_SCRAMBLE_BUF_CUR6_4                                            0x18007730
#define DC_MEM_SCRAMBLE_BUF_CUR6_5                                            0x18007734
#define DC_MEM_SCRAMBLE_BUF_CUR6_6                                            0x18007738
#define DC_MEM_SCRAMBLE_BUF_CUR6_7                                            0x1800773C
#define DC_MEM_SCRAMBLE_BUF_CUR6_0_reg_addr                                   "0xB8007720"
#define DC_MEM_SCRAMBLE_BUF_CUR6_1_reg_addr                                   "0xB8007724"
#define DC_MEM_SCRAMBLE_BUF_CUR6_2_reg_addr                                   "0xB8007728"
#define DC_MEM_SCRAMBLE_BUF_CUR6_3_reg_addr                                   "0xB800772C"
#define DC_MEM_SCRAMBLE_BUF_CUR6_4_reg_addr                                   "0xB8007730"
#define DC_MEM_SCRAMBLE_BUF_CUR6_5_reg_addr                                   "0xB8007734"
#define DC_MEM_SCRAMBLE_BUF_CUR6_6_reg_addr                                   "0xB8007738"
#define DC_MEM_SCRAMBLE_BUF_CUR6_7_reg_addr                                   "0xB800773C"
#define DC_MEM_SCRAMBLE_BUF_CUR6_0_reg                                        0xB8007720
#define DC_MEM_SCRAMBLE_BUF_CUR6_1_reg                                        0xB8007724
#define DC_MEM_SCRAMBLE_BUF_CUR6_2_reg                                        0xB8007728
#define DC_MEM_SCRAMBLE_BUF_CUR6_3_reg                                        0xB800772C
#define DC_MEM_SCRAMBLE_BUF_CUR6_4_reg                                        0xB8007730
#define DC_MEM_SCRAMBLE_BUF_CUR6_5_reg                                        0xB8007734
#define DC_MEM_SCRAMBLE_BUF_CUR6_6_reg                                        0xB8007738
#define DC_MEM_SCRAMBLE_BUF_CUR6_7_reg                                        0xB800773C
#define set_DC_MEM_SCRAMBLE_BUF_CUR6_0_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR6_0_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR6_1_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR6_1_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR6_2_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR6_2_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR6_3_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR6_3_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR6_4_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR6_4_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR6_5_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR6_5_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR6_6_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR6_6_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_CUR6_7_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR6_7_reg)=data)
#define get_DC_MEM_SCRAMBLE_BUF_CUR6_0_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR6_0_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR6_1_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR6_1_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR6_2_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR6_2_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR6_3_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR6_3_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR6_4_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR6_4_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR6_5_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR6_5_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR6_6_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR6_6_reg))
#define get_DC_MEM_SCRAMBLE_BUF_CUR6_7_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_CUR6_7_reg))
#define DC_MEM_SCRAMBLE_BUF_CUR6_0_inst_adr                                   "0x00C8"
#define DC_MEM_SCRAMBLE_BUF_CUR6_1_inst_adr                                   "0x00C9"
#define DC_MEM_SCRAMBLE_BUF_CUR6_2_inst_adr                                   "0x00CA"
#define DC_MEM_SCRAMBLE_BUF_CUR6_3_inst_adr                                   "0x00CB"
#define DC_MEM_SCRAMBLE_BUF_CUR6_4_inst_adr                                   "0x00CC"
#define DC_MEM_SCRAMBLE_BUF_CUR6_5_inst_adr                                   "0x00CD"
#define DC_MEM_SCRAMBLE_BUF_CUR6_6_inst_adr                                   "0x00CE"
#define DC_MEM_SCRAMBLE_BUF_CUR6_7_inst_adr                                   "0x00CF"
#define DC_MEM_SCRAMBLE_BUF_CUR6_0_inst                                       0x00C8
#define DC_MEM_SCRAMBLE_BUF_CUR6_1_inst                                       0x00C9
#define DC_MEM_SCRAMBLE_BUF_CUR6_2_inst                                       0x00CA
#define DC_MEM_SCRAMBLE_BUF_CUR6_3_inst                                       0x00CB
#define DC_MEM_SCRAMBLE_BUF_CUR6_4_inst                                       0x00CC
#define DC_MEM_SCRAMBLE_BUF_CUR6_5_inst                                       0x00CD
#define DC_MEM_SCRAMBLE_BUF_CUR6_6_inst                                       0x00CE
#define DC_MEM_SCRAMBLE_BUF_CUR6_7_inst                                       0x00CF
#define DC_MEM_SCRAMBLE_BUF_CUR6_keyD_shift                                   (16)
#define DC_MEM_SCRAMBLE_BUF_CUR6_keyD_mask                                    (0xFFFF0000)
#define DC_MEM_SCRAMBLE_BUF_CUR6_keyD(data)                                   (0xFFFF0000&((data)<<16))
#define DC_MEM_SCRAMBLE_BUF_CUR6_keyD_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_CUR6_get_keyD(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_CUR6_keyC_shift                                   (0)
#define DC_MEM_SCRAMBLE_BUF_CUR6_keyC_mask                                    (0x0000FFFF)
#define DC_MEM_SCRAMBLE_BUF_CUR6_keyC(data)                                   (0x0000FFFF&((data)<<0))
#define DC_MEM_SCRAMBLE_BUF_CUR6_keyC_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC_MEM_SCRAMBLE_BUF_CUR6_get_keyC(data)                               ((0x0000FFFF&(data))>>0)


#define DC_MEM_SCRAMBLE_BUF_PRE0_0                                            0x18007740
#define DC_MEM_SCRAMBLE_BUF_PRE0_1                                            0x18007744
#define DC_MEM_SCRAMBLE_BUF_PRE0_2                                            0x18007748
#define DC_MEM_SCRAMBLE_BUF_PRE0_3                                            0x1800774C
#define DC_MEM_SCRAMBLE_BUF_PRE0_4                                            0x18007750
#define DC_MEM_SCRAMBLE_BUF_PRE0_5                                            0x18007754
#define DC_MEM_SCRAMBLE_BUF_PRE0_6                                            0x18007758
#define DC_MEM_SCRAMBLE_BUF_PRE0_7                                            0x1800775C
#define DC_MEM_SCRAMBLE_BUF_PRE0_0_reg_addr                                   "0xB8007740"
#define DC_MEM_SCRAMBLE_BUF_PRE0_1_reg_addr                                   "0xB8007744"
#define DC_MEM_SCRAMBLE_BUF_PRE0_2_reg_addr                                   "0xB8007748"
#define DC_MEM_SCRAMBLE_BUF_PRE0_3_reg_addr                                   "0xB800774C"
#define DC_MEM_SCRAMBLE_BUF_PRE0_4_reg_addr                                   "0xB8007750"
#define DC_MEM_SCRAMBLE_BUF_PRE0_5_reg_addr                                   "0xB8007754"
#define DC_MEM_SCRAMBLE_BUF_PRE0_6_reg_addr                                   "0xB8007758"
#define DC_MEM_SCRAMBLE_BUF_PRE0_7_reg_addr                                   "0xB800775C"
#define DC_MEM_SCRAMBLE_BUF_PRE0_0_reg                                        0xB8007740
#define DC_MEM_SCRAMBLE_BUF_PRE0_1_reg                                        0xB8007744
#define DC_MEM_SCRAMBLE_BUF_PRE0_2_reg                                        0xB8007748
#define DC_MEM_SCRAMBLE_BUF_PRE0_3_reg                                        0xB800774C
#define DC_MEM_SCRAMBLE_BUF_PRE0_4_reg                                        0xB8007750
#define DC_MEM_SCRAMBLE_BUF_PRE0_5_reg                                        0xB8007754
#define DC_MEM_SCRAMBLE_BUF_PRE0_6_reg                                        0xB8007758
#define DC_MEM_SCRAMBLE_BUF_PRE0_7_reg                                        0xB800775C
#define set_DC_MEM_SCRAMBLE_BUF_PRE0_0_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE0_0_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE0_1_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE0_1_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE0_2_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE0_2_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE0_3_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE0_3_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE0_4_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE0_4_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE0_5_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE0_5_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE0_6_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE0_6_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE0_7_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE0_7_reg)=data)
#define get_DC_MEM_SCRAMBLE_BUF_PRE0_0_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE0_0_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE0_1_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE0_1_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE0_2_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE0_2_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE0_3_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE0_3_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE0_4_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE0_4_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE0_5_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE0_5_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE0_6_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE0_6_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE0_7_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE0_7_reg))
#define DC_MEM_SCRAMBLE_BUF_PRE0_0_inst_adr                                   "0x00D0"
#define DC_MEM_SCRAMBLE_BUF_PRE0_1_inst_adr                                   "0x00D1"
#define DC_MEM_SCRAMBLE_BUF_PRE0_2_inst_adr                                   "0x00D2"
#define DC_MEM_SCRAMBLE_BUF_PRE0_3_inst_adr                                   "0x00D3"
#define DC_MEM_SCRAMBLE_BUF_PRE0_4_inst_adr                                   "0x00D4"
#define DC_MEM_SCRAMBLE_BUF_PRE0_5_inst_adr                                   "0x00D5"
#define DC_MEM_SCRAMBLE_BUF_PRE0_6_inst_adr                                   "0x00D6"
#define DC_MEM_SCRAMBLE_BUF_PRE0_7_inst_adr                                   "0x00D7"
#define DC_MEM_SCRAMBLE_BUF_PRE0_0_inst                                       0x00D0
#define DC_MEM_SCRAMBLE_BUF_PRE0_1_inst                                       0x00D1
#define DC_MEM_SCRAMBLE_BUF_PRE0_2_inst                                       0x00D2
#define DC_MEM_SCRAMBLE_BUF_PRE0_3_inst                                       0x00D3
#define DC_MEM_SCRAMBLE_BUF_PRE0_4_inst                                       0x00D4
#define DC_MEM_SCRAMBLE_BUF_PRE0_5_inst                                       0x00D5
#define DC_MEM_SCRAMBLE_BUF_PRE0_6_inst                                       0x00D6
#define DC_MEM_SCRAMBLE_BUF_PRE0_7_inst                                       0x00D7
#define DC_MEM_SCRAMBLE_BUF_PRE0_key1_shift                                   (16)
#define DC_MEM_SCRAMBLE_BUF_PRE0_key1_mask                                    (0xFFFF0000)
#define DC_MEM_SCRAMBLE_BUF_PRE0_key1(data)                                   (0xFFFF0000&((data)<<16))
#define DC_MEM_SCRAMBLE_BUF_PRE0_key1_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_PRE0_get_key1(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_PRE0_key0_shift                                   (0)
#define DC_MEM_SCRAMBLE_BUF_PRE0_key0_mask                                    (0x0000FFFF)
#define DC_MEM_SCRAMBLE_BUF_PRE0_key0(data)                                   (0x0000FFFF&((data)<<0))
#define DC_MEM_SCRAMBLE_BUF_PRE0_key0_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC_MEM_SCRAMBLE_BUF_PRE0_get_key0(data)                               ((0x0000FFFF&(data))>>0)


#define DC_MEM_SCRAMBLE_BUF_PRE1_0                                            0x18007760
#define DC_MEM_SCRAMBLE_BUF_PRE1_1                                            0x18007764
#define DC_MEM_SCRAMBLE_BUF_PRE1_2                                            0x18007768
#define DC_MEM_SCRAMBLE_BUF_PRE1_3                                            0x1800776C
#define DC_MEM_SCRAMBLE_BUF_PRE1_4                                            0x18007770
#define DC_MEM_SCRAMBLE_BUF_PRE1_5                                            0x18007774
#define DC_MEM_SCRAMBLE_BUF_PRE1_6                                            0x18007778
#define DC_MEM_SCRAMBLE_BUF_PRE1_7                                            0x1800777C
#define DC_MEM_SCRAMBLE_BUF_PRE1_0_reg_addr                                   "0xB8007760"
#define DC_MEM_SCRAMBLE_BUF_PRE1_1_reg_addr                                   "0xB8007764"
#define DC_MEM_SCRAMBLE_BUF_PRE1_2_reg_addr                                   "0xB8007768"
#define DC_MEM_SCRAMBLE_BUF_PRE1_3_reg_addr                                   "0xB800776C"
#define DC_MEM_SCRAMBLE_BUF_PRE1_4_reg_addr                                   "0xB8007770"
#define DC_MEM_SCRAMBLE_BUF_PRE1_5_reg_addr                                   "0xB8007774"
#define DC_MEM_SCRAMBLE_BUF_PRE1_6_reg_addr                                   "0xB8007778"
#define DC_MEM_SCRAMBLE_BUF_PRE1_7_reg_addr                                   "0xB800777C"
#define DC_MEM_SCRAMBLE_BUF_PRE1_0_reg                                        0xB8007760
#define DC_MEM_SCRAMBLE_BUF_PRE1_1_reg                                        0xB8007764
#define DC_MEM_SCRAMBLE_BUF_PRE1_2_reg                                        0xB8007768
#define DC_MEM_SCRAMBLE_BUF_PRE1_3_reg                                        0xB800776C
#define DC_MEM_SCRAMBLE_BUF_PRE1_4_reg                                        0xB8007770
#define DC_MEM_SCRAMBLE_BUF_PRE1_5_reg                                        0xB8007774
#define DC_MEM_SCRAMBLE_BUF_PRE1_6_reg                                        0xB8007778
#define DC_MEM_SCRAMBLE_BUF_PRE1_7_reg                                        0xB800777C
#define set_DC_MEM_SCRAMBLE_BUF_PRE1_0_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE1_0_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE1_1_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE1_1_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE1_2_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE1_2_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE1_3_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE1_3_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE1_4_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE1_4_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE1_5_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE1_5_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE1_6_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE1_6_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE1_7_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE1_7_reg)=data)
#define get_DC_MEM_SCRAMBLE_BUF_PRE1_0_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE1_0_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE1_1_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE1_1_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE1_2_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE1_2_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE1_3_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE1_3_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE1_4_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE1_4_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE1_5_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE1_5_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE1_6_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE1_6_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE1_7_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE1_7_reg))
#define DC_MEM_SCRAMBLE_BUF_PRE1_0_inst_adr                                   "0x00D8"
#define DC_MEM_SCRAMBLE_BUF_PRE1_1_inst_adr                                   "0x00D9"
#define DC_MEM_SCRAMBLE_BUF_PRE1_2_inst_adr                                   "0x00DA"
#define DC_MEM_SCRAMBLE_BUF_PRE1_3_inst_adr                                   "0x00DB"
#define DC_MEM_SCRAMBLE_BUF_PRE1_4_inst_adr                                   "0x00DC"
#define DC_MEM_SCRAMBLE_BUF_PRE1_5_inst_adr                                   "0x00DD"
#define DC_MEM_SCRAMBLE_BUF_PRE1_6_inst_adr                                   "0x00DE"
#define DC_MEM_SCRAMBLE_BUF_PRE1_7_inst_adr                                   "0x00DF"
#define DC_MEM_SCRAMBLE_BUF_PRE1_0_inst                                       0x00D8
#define DC_MEM_SCRAMBLE_BUF_PRE1_1_inst                                       0x00D9
#define DC_MEM_SCRAMBLE_BUF_PRE1_2_inst                                       0x00DA
#define DC_MEM_SCRAMBLE_BUF_PRE1_3_inst                                       0x00DB
#define DC_MEM_SCRAMBLE_BUF_PRE1_4_inst                                       0x00DC
#define DC_MEM_SCRAMBLE_BUF_PRE1_5_inst                                       0x00DD
#define DC_MEM_SCRAMBLE_BUF_PRE1_6_inst                                       0x00DE
#define DC_MEM_SCRAMBLE_BUF_PRE1_7_inst                                       0x00DF
#define DC_MEM_SCRAMBLE_BUF_PRE1_key3_shift                                   (16)
#define DC_MEM_SCRAMBLE_BUF_PRE1_key3_mask                                    (0xFFFF0000)
#define DC_MEM_SCRAMBLE_BUF_PRE1_key3(data)                                   (0xFFFF0000&((data)<<16))
#define DC_MEM_SCRAMBLE_BUF_PRE1_key3_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_PRE1_get_key3(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_PRE1_key2_shift                                   (0)
#define DC_MEM_SCRAMBLE_BUF_PRE1_key2_mask                                    (0x0000FFFF)
#define DC_MEM_SCRAMBLE_BUF_PRE1_key2(data)                                   (0x0000FFFF&((data)<<0))
#define DC_MEM_SCRAMBLE_BUF_PRE1_key2_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC_MEM_SCRAMBLE_BUF_PRE1_get_key2(data)                               ((0x0000FFFF&(data))>>0)


#define DC_MEM_SCRAMBLE_BUF_PRE2_0                                            0x18007780
#define DC_MEM_SCRAMBLE_BUF_PRE2_1                                            0x18007784
#define DC_MEM_SCRAMBLE_BUF_PRE2_2                                            0x18007788
#define DC_MEM_SCRAMBLE_BUF_PRE2_3                                            0x1800778C
#define DC_MEM_SCRAMBLE_BUF_PRE2_4                                            0x18007790
#define DC_MEM_SCRAMBLE_BUF_PRE2_5                                            0x18007794
#define DC_MEM_SCRAMBLE_BUF_PRE2_6                                            0x18007798
#define DC_MEM_SCRAMBLE_BUF_PRE2_7                                            0x1800779C
#define DC_MEM_SCRAMBLE_BUF_PRE2_0_reg_addr                                   "0xB8007780"
#define DC_MEM_SCRAMBLE_BUF_PRE2_1_reg_addr                                   "0xB8007784"
#define DC_MEM_SCRAMBLE_BUF_PRE2_2_reg_addr                                   "0xB8007788"
#define DC_MEM_SCRAMBLE_BUF_PRE2_3_reg_addr                                   "0xB800778C"
#define DC_MEM_SCRAMBLE_BUF_PRE2_4_reg_addr                                   "0xB8007790"
#define DC_MEM_SCRAMBLE_BUF_PRE2_5_reg_addr                                   "0xB8007794"
#define DC_MEM_SCRAMBLE_BUF_PRE2_6_reg_addr                                   "0xB8007798"
#define DC_MEM_SCRAMBLE_BUF_PRE2_7_reg_addr                                   "0xB800779C"
#define DC_MEM_SCRAMBLE_BUF_PRE2_0_reg                                        0xB8007780
#define DC_MEM_SCRAMBLE_BUF_PRE2_1_reg                                        0xB8007784
#define DC_MEM_SCRAMBLE_BUF_PRE2_2_reg                                        0xB8007788
#define DC_MEM_SCRAMBLE_BUF_PRE2_3_reg                                        0xB800778C
#define DC_MEM_SCRAMBLE_BUF_PRE2_4_reg                                        0xB8007790
#define DC_MEM_SCRAMBLE_BUF_PRE2_5_reg                                        0xB8007794
#define DC_MEM_SCRAMBLE_BUF_PRE2_6_reg                                        0xB8007798
#define DC_MEM_SCRAMBLE_BUF_PRE2_7_reg                                        0xB800779C
#define set_DC_MEM_SCRAMBLE_BUF_PRE2_0_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE2_0_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE2_1_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE2_1_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE2_2_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE2_2_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE2_3_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE2_3_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE2_4_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE2_4_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE2_5_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE2_5_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE2_6_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE2_6_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE2_7_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE2_7_reg)=data)
#define get_DC_MEM_SCRAMBLE_BUF_PRE2_0_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE2_0_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE2_1_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE2_1_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE2_2_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE2_2_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE2_3_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE2_3_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE2_4_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE2_4_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE2_5_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE2_5_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE2_6_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE2_6_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE2_7_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE2_7_reg))
#define DC_MEM_SCRAMBLE_BUF_PRE2_0_inst_adr                                   "0x00E0"
#define DC_MEM_SCRAMBLE_BUF_PRE2_1_inst_adr                                   "0x00E1"
#define DC_MEM_SCRAMBLE_BUF_PRE2_2_inst_adr                                   "0x00E2"
#define DC_MEM_SCRAMBLE_BUF_PRE2_3_inst_adr                                   "0x00E3"
#define DC_MEM_SCRAMBLE_BUF_PRE2_4_inst_adr                                   "0x00E4"
#define DC_MEM_SCRAMBLE_BUF_PRE2_5_inst_adr                                   "0x00E5"
#define DC_MEM_SCRAMBLE_BUF_PRE2_6_inst_adr                                   "0x00E6"
#define DC_MEM_SCRAMBLE_BUF_PRE2_7_inst_adr                                   "0x00E7"
#define DC_MEM_SCRAMBLE_BUF_PRE2_0_inst                                       0x00E0
#define DC_MEM_SCRAMBLE_BUF_PRE2_1_inst                                       0x00E1
#define DC_MEM_SCRAMBLE_BUF_PRE2_2_inst                                       0x00E2
#define DC_MEM_SCRAMBLE_BUF_PRE2_3_inst                                       0x00E3
#define DC_MEM_SCRAMBLE_BUF_PRE2_4_inst                                       0x00E4
#define DC_MEM_SCRAMBLE_BUF_PRE2_5_inst                                       0x00E5
#define DC_MEM_SCRAMBLE_BUF_PRE2_6_inst                                       0x00E6
#define DC_MEM_SCRAMBLE_BUF_PRE2_7_inst                                       0x00E7
#define DC_MEM_SCRAMBLE_BUF_PRE2_key5_shift                                   (16)
#define DC_MEM_SCRAMBLE_BUF_PRE2_key5_mask                                    (0xFFFF0000)
#define DC_MEM_SCRAMBLE_BUF_PRE2_key5(data)                                   (0xFFFF0000&((data)<<16))
#define DC_MEM_SCRAMBLE_BUF_PRE2_key5_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_PRE2_get_key5(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_PRE2_key4_shift                                   (0)
#define DC_MEM_SCRAMBLE_BUF_PRE2_key4_mask                                    (0x0000FFFF)
#define DC_MEM_SCRAMBLE_BUF_PRE2_key4(data)                                   (0x0000FFFF&((data)<<0))
#define DC_MEM_SCRAMBLE_BUF_PRE2_key4_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC_MEM_SCRAMBLE_BUF_PRE2_get_key4(data)                               ((0x0000FFFF&(data))>>0)


#define DC_MEM_SCRAMBLE_BUF_PRE3_0                                            0x180077A0
#define DC_MEM_SCRAMBLE_BUF_PRE3_1                                            0x180077A4
#define DC_MEM_SCRAMBLE_BUF_PRE3_2                                            0x180077A8
#define DC_MEM_SCRAMBLE_BUF_PRE3_3                                            0x180077AC
#define DC_MEM_SCRAMBLE_BUF_PRE3_4                                            0x180077B0
#define DC_MEM_SCRAMBLE_BUF_PRE3_5                                            0x180077B4
#define DC_MEM_SCRAMBLE_BUF_PRE3_6                                            0x180077B8
#define DC_MEM_SCRAMBLE_BUF_PRE3_7                                            0x180077BC
#define DC_MEM_SCRAMBLE_BUF_PRE3_0_reg_addr                                   "0xB80077A0"
#define DC_MEM_SCRAMBLE_BUF_PRE3_1_reg_addr                                   "0xB80077A4"
#define DC_MEM_SCRAMBLE_BUF_PRE3_2_reg_addr                                   "0xB80077A8"
#define DC_MEM_SCRAMBLE_BUF_PRE3_3_reg_addr                                   "0xB80077AC"
#define DC_MEM_SCRAMBLE_BUF_PRE3_4_reg_addr                                   "0xB80077B0"
#define DC_MEM_SCRAMBLE_BUF_PRE3_5_reg_addr                                   "0xB80077B4"
#define DC_MEM_SCRAMBLE_BUF_PRE3_6_reg_addr                                   "0xB80077B8"
#define DC_MEM_SCRAMBLE_BUF_PRE3_7_reg_addr                                   "0xB80077BC"
#define DC_MEM_SCRAMBLE_BUF_PRE3_0_reg                                        0xB80077A0
#define DC_MEM_SCRAMBLE_BUF_PRE3_1_reg                                        0xB80077A4
#define DC_MEM_SCRAMBLE_BUF_PRE3_2_reg                                        0xB80077A8
#define DC_MEM_SCRAMBLE_BUF_PRE3_3_reg                                        0xB80077AC
#define DC_MEM_SCRAMBLE_BUF_PRE3_4_reg                                        0xB80077B0
#define DC_MEM_SCRAMBLE_BUF_PRE3_5_reg                                        0xB80077B4
#define DC_MEM_SCRAMBLE_BUF_PRE3_6_reg                                        0xB80077B8
#define DC_MEM_SCRAMBLE_BUF_PRE3_7_reg                                        0xB80077BC
#define set_DC_MEM_SCRAMBLE_BUF_PRE3_0_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE3_0_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE3_1_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE3_1_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE3_2_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE3_2_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE3_3_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE3_3_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE3_4_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE3_4_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE3_5_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE3_5_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE3_6_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE3_6_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE3_7_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE3_7_reg)=data)
#define get_DC_MEM_SCRAMBLE_BUF_PRE3_0_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE3_0_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE3_1_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE3_1_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE3_2_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE3_2_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE3_3_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE3_3_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE3_4_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE3_4_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE3_5_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE3_5_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE3_6_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE3_6_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE3_7_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE3_7_reg))
#define DC_MEM_SCRAMBLE_BUF_PRE3_0_inst_adr                                   "0x00E8"
#define DC_MEM_SCRAMBLE_BUF_PRE3_1_inst_adr                                   "0x00E9"
#define DC_MEM_SCRAMBLE_BUF_PRE3_2_inst_adr                                   "0x00EA"
#define DC_MEM_SCRAMBLE_BUF_PRE3_3_inst_adr                                   "0x00EB"
#define DC_MEM_SCRAMBLE_BUF_PRE3_4_inst_adr                                   "0x00EC"
#define DC_MEM_SCRAMBLE_BUF_PRE3_5_inst_adr                                   "0x00ED"
#define DC_MEM_SCRAMBLE_BUF_PRE3_6_inst_adr                                   "0x00EE"
#define DC_MEM_SCRAMBLE_BUF_PRE3_7_inst_adr                                   "0x00EF"
#define DC_MEM_SCRAMBLE_BUF_PRE3_0_inst                                       0x00E8
#define DC_MEM_SCRAMBLE_BUF_PRE3_1_inst                                       0x00E9
#define DC_MEM_SCRAMBLE_BUF_PRE3_2_inst                                       0x00EA
#define DC_MEM_SCRAMBLE_BUF_PRE3_3_inst                                       0x00EB
#define DC_MEM_SCRAMBLE_BUF_PRE3_4_inst                                       0x00EC
#define DC_MEM_SCRAMBLE_BUF_PRE3_5_inst                                       0x00ED
#define DC_MEM_SCRAMBLE_BUF_PRE3_6_inst                                       0x00EE
#define DC_MEM_SCRAMBLE_BUF_PRE3_7_inst                                       0x00EF
#define DC_MEM_SCRAMBLE_BUF_PRE3_key7_shift                                   (16)
#define DC_MEM_SCRAMBLE_BUF_PRE3_key7_mask                                    (0xFFFF0000)
#define DC_MEM_SCRAMBLE_BUF_PRE3_key7(data)                                   (0xFFFF0000&((data)<<16))
#define DC_MEM_SCRAMBLE_BUF_PRE3_key7_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_PRE3_get_key7(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_PRE3_key6_shift                                   (0)
#define DC_MEM_SCRAMBLE_BUF_PRE3_key6_mask                                    (0x0000FFFF)
#define DC_MEM_SCRAMBLE_BUF_PRE3_key6(data)                                   (0x0000FFFF&((data)<<0))
#define DC_MEM_SCRAMBLE_BUF_PRE3_key6_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC_MEM_SCRAMBLE_BUF_PRE3_get_key6(data)                               ((0x0000FFFF&(data))>>0)


#define DC_MEM_SCRAMBLE_BUF_PRE4_0                                            0x180077C0
#define DC_MEM_SCRAMBLE_BUF_PRE4_1                                            0x180077C4
#define DC_MEM_SCRAMBLE_BUF_PRE4_2                                            0x180077C8
#define DC_MEM_SCRAMBLE_BUF_PRE4_3                                            0x180077CC
#define DC_MEM_SCRAMBLE_BUF_PRE4_4                                            0x180077D0
#define DC_MEM_SCRAMBLE_BUF_PRE4_5                                            0x180077D4
#define DC_MEM_SCRAMBLE_BUF_PRE4_6                                            0x180077D8
#define DC_MEM_SCRAMBLE_BUF_PRE4_7                                            0x180077DC
#define DC_MEM_SCRAMBLE_BUF_PRE4_0_reg_addr                                   "0xB80077C0"
#define DC_MEM_SCRAMBLE_BUF_PRE4_1_reg_addr                                   "0xB80077C4"
#define DC_MEM_SCRAMBLE_BUF_PRE4_2_reg_addr                                   "0xB80077C8"
#define DC_MEM_SCRAMBLE_BUF_PRE4_3_reg_addr                                   "0xB80077CC"
#define DC_MEM_SCRAMBLE_BUF_PRE4_4_reg_addr                                   "0xB80077D0"
#define DC_MEM_SCRAMBLE_BUF_PRE4_5_reg_addr                                   "0xB80077D4"
#define DC_MEM_SCRAMBLE_BUF_PRE4_6_reg_addr                                   "0xB80077D8"
#define DC_MEM_SCRAMBLE_BUF_PRE4_7_reg_addr                                   "0xB80077DC"
#define DC_MEM_SCRAMBLE_BUF_PRE4_0_reg                                        0xB80077C0
#define DC_MEM_SCRAMBLE_BUF_PRE4_1_reg                                        0xB80077C4
#define DC_MEM_SCRAMBLE_BUF_PRE4_2_reg                                        0xB80077C8
#define DC_MEM_SCRAMBLE_BUF_PRE4_3_reg                                        0xB80077CC
#define DC_MEM_SCRAMBLE_BUF_PRE4_4_reg                                        0xB80077D0
#define DC_MEM_SCRAMBLE_BUF_PRE4_5_reg                                        0xB80077D4
#define DC_MEM_SCRAMBLE_BUF_PRE4_6_reg                                        0xB80077D8
#define DC_MEM_SCRAMBLE_BUF_PRE4_7_reg                                        0xB80077DC
#define set_DC_MEM_SCRAMBLE_BUF_PRE4_0_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE4_0_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE4_1_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE4_1_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE4_2_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE4_2_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE4_3_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE4_3_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE4_4_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE4_4_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE4_5_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE4_5_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE4_6_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE4_6_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE4_7_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE4_7_reg)=data)
#define get_DC_MEM_SCRAMBLE_BUF_PRE4_0_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE4_0_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE4_1_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE4_1_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE4_2_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE4_2_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE4_3_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE4_3_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE4_4_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE4_4_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE4_5_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE4_5_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE4_6_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE4_6_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE4_7_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE4_7_reg))
#define DC_MEM_SCRAMBLE_BUF_PRE4_0_inst_adr                                   "0x00F0"
#define DC_MEM_SCRAMBLE_BUF_PRE4_1_inst_adr                                   "0x00F1"
#define DC_MEM_SCRAMBLE_BUF_PRE4_2_inst_adr                                   "0x00F2"
#define DC_MEM_SCRAMBLE_BUF_PRE4_3_inst_adr                                   "0x00F3"
#define DC_MEM_SCRAMBLE_BUF_PRE4_4_inst_adr                                   "0x00F4"
#define DC_MEM_SCRAMBLE_BUF_PRE4_5_inst_adr                                   "0x00F5"
#define DC_MEM_SCRAMBLE_BUF_PRE4_6_inst_adr                                   "0x00F6"
#define DC_MEM_SCRAMBLE_BUF_PRE4_7_inst_adr                                   "0x00F7"
#define DC_MEM_SCRAMBLE_BUF_PRE4_0_inst                                       0x00F0
#define DC_MEM_SCRAMBLE_BUF_PRE4_1_inst                                       0x00F1
#define DC_MEM_SCRAMBLE_BUF_PRE4_2_inst                                       0x00F2
#define DC_MEM_SCRAMBLE_BUF_PRE4_3_inst                                       0x00F3
#define DC_MEM_SCRAMBLE_BUF_PRE4_4_inst                                       0x00F4
#define DC_MEM_SCRAMBLE_BUF_PRE4_5_inst                                       0x00F5
#define DC_MEM_SCRAMBLE_BUF_PRE4_6_inst                                       0x00F6
#define DC_MEM_SCRAMBLE_BUF_PRE4_7_inst                                       0x00F7
#define DC_MEM_SCRAMBLE_BUF_PRE4_key9_shift                                   (16)
#define DC_MEM_SCRAMBLE_BUF_PRE4_key9_mask                                    (0xFFFF0000)
#define DC_MEM_SCRAMBLE_BUF_PRE4_key9(data)                                   (0xFFFF0000&((data)<<16))
#define DC_MEM_SCRAMBLE_BUF_PRE4_key9_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_PRE4_get_key9(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_PRE4_key8_shift                                   (0)
#define DC_MEM_SCRAMBLE_BUF_PRE4_key8_mask                                    (0x0000FFFF)
#define DC_MEM_SCRAMBLE_BUF_PRE4_key8(data)                                   (0x0000FFFF&((data)<<0))
#define DC_MEM_SCRAMBLE_BUF_PRE4_key8_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC_MEM_SCRAMBLE_BUF_PRE4_get_key8(data)                               ((0x0000FFFF&(data))>>0)


#define DC_MEM_SCRAMBLE_BUF_PRE5_0                                            0x180077E0
#define DC_MEM_SCRAMBLE_BUF_PRE5_1                                            0x180077E4
#define DC_MEM_SCRAMBLE_BUF_PRE5_2                                            0x180077E8
#define DC_MEM_SCRAMBLE_BUF_PRE5_3                                            0x180077EC
#define DC_MEM_SCRAMBLE_BUF_PRE5_4                                            0x180077F0
#define DC_MEM_SCRAMBLE_BUF_PRE5_5                                            0x180077F4
#define DC_MEM_SCRAMBLE_BUF_PRE5_6                                            0x180077F8
#define DC_MEM_SCRAMBLE_BUF_PRE5_7                                            0x180077FC
#define DC_MEM_SCRAMBLE_BUF_PRE5_0_reg_addr                                   "0xB80077E0"
#define DC_MEM_SCRAMBLE_BUF_PRE5_1_reg_addr                                   "0xB80077E4"
#define DC_MEM_SCRAMBLE_BUF_PRE5_2_reg_addr                                   "0xB80077E8"
#define DC_MEM_SCRAMBLE_BUF_PRE5_3_reg_addr                                   "0xB80077EC"
#define DC_MEM_SCRAMBLE_BUF_PRE5_4_reg_addr                                   "0xB80077F0"
#define DC_MEM_SCRAMBLE_BUF_PRE5_5_reg_addr                                   "0xB80077F4"
#define DC_MEM_SCRAMBLE_BUF_PRE5_6_reg_addr                                   "0xB80077F8"
#define DC_MEM_SCRAMBLE_BUF_PRE5_7_reg_addr                                   "0xB80077FC"
#define DC_MEM_SCRAMBLE_BUF_PRE5_0_reg                                        0xB80077E0
#define DC_MEM_SCRAMBLE_BUF_PRE5_1_reg                                        0xB80077E4
#define DC_MEM_SCRAMBLE_BUF_PRE5_2_reg                                        0xB80077E8
#define DC_MEM_SCRAMBLE_BUF_PRE5_3_reg                                        0xB80077EC
#define DC_MEM_SCRAMBLE_BUF_PRE5_4_reg                                        0xB80077F0
#define DC_MEM_SCRAMBLE_BUF_PRE5_5_reg                                        0xB80077F4
#define DC_MEM_SCRAMBLE_BUF_PRE5_6_reg                                        0xB80077F8
#define DC_MEM_SCRAMBLE_BUF_PRE5_7_reg                                        0xB80077FC
#define set_DC_MEM_SCRAMBLE_BUF_PRE5_0_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE5_0_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE5_1_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE5_1_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE5_2_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE5_2_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE5_3_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE5_3_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE5_4_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE5_4_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE5_5_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE5_5_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE5_6_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE5_6_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE5_7_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE5_7_reg)=data)
#define get_DC_MEM_SCRAMBLE_BUF_PRE5_0_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE5_0_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE5_1_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE5_1_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE5_2_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE5_2_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE5_3_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE5_3_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE5_4_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE5_4_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE5_5_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE5_5_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE5_6_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE5_6_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE5_7_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE5_7_reg))
#define DC_MEM_SCRAMBLE_BUF_PRE5_0_inst_adr                                   "0x00F8"
#define DC_MEM_SCRAMBLE_BUF_PRE5_1_inst_adr                                   "0x00F9"
#define DC_MEM_SCRAMBLE_BUF_PRE5_2_inst_adr                                   "0x00FA"
#define DC_MEM_SCRAMBLE_BUF_PRE5_3_inst_adr                                   "0x00FB"
#define DC_MEM_SCRAMBLE_BUF_PRE5_4_inst_adr                                   "0x00FC"
#define DC_MEM_SCRAMBLE_BUF_PRE5_5_inst_adr                                   "0x00FD"
#define DC_MEM_SCRAMBLE_BUF_PRE5_6_inst_adr                                   "0x00FE"
#define DC_MEM_SCRAMBLE_BUF_PRE5_7_inst_adr                                   "0x00FF"
#define DC_MEM_SCRAMBLE_BUF_PRE5_0_inst                                       0x00F8
#define DC_MEM_SCRAMBLE_BUF_PRE5_1_inst                                       0x00F9
#define DC_MEM_SCRAMBLE_BUF_PRE5_2_inst                                       0x00FA
#define DC_MEM_SCRAMBLE_BUF_PRE5_3_inst                                       0x00FB
#define DC_MEM_SCRAMBLE_BUF_PRE5_4_inst                                       0x00FC
#define DC_MEM_SCRAMBLE_BUF_PRE5_5_inst                                       0x00FD
#define DC_MEM_SCRAMBLE_BUF_PRE5_6_inst                                       0x00FE
#define DC_MEM_SCRAMBLE_BUF_PRE5_7_inst                                       0x00FF
#define DC_MEM_SCRAMBLE_BUF_PRE5_keyB_shift                                   (16)
#define DC_MEM_SCRAMBLE_BUF_PRE5_keyB_mask                                    (0xFFFF0000)
#define DC_MEM_SCRAMBLE_BUF_PRE5_keyB(data)                                   (0xFFFF0000&((data)<<16))
#define DC_MEM_SCRAMBLE_BUF_PRE5_keyB_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_PRE5_get_keyB(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_PRE5_keyA_shift                                   (0)
#define DC_MEM_SCRAMBLE_BUF_PRE5_keyA_mask                                    (0x0000FFFF)
#define DC_MEM_SCRAMBLE_BUF_PRE5_keyA(data)                                   (0x0000FFFF&((data)<<0))
#define DC_MEM_SCRAMBLE_BUF_PRE5_keyA_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC_MEM_SCRAMBLE_BUF_PRE5_get_keyA(data)                               ((0x0000FFFF&(data))>>0)


#define DC_MEM_SCRAMBLE_BUF_PRE6_0                                            0x18007800
#define DC_MEM_SCRAMBLE_BUF_PRE6_1                                            0x18007804
#define DC_MEM_SCRAMBLE_BUF_PRE6_2                                            0x18007808
#define DC_MEM_SCRAMBLE_BUF_PRE6_3                                            0x1800780C
#define DC_MEM_SCRAMBLE_BUF_PRE6_4                                            0x18007810
#define DC_MEM_SCRAMBLE_BUF_PRE6_5                                            0x18007814
#define DC_MEM_SCRAMBLE_BUF_PRE6_6                                            0x18007818
#define DC_MEM_SCRAMBLE_BUF_PRE6_7                                            0x1800781C
#define DC_MEM_SCRAMBLE_BUF_PRE6_0_reg_addr                                   "0xB8007800"
#define DC_MEM_SCRAMBLE_BUF_PRE6_1_reg_addr                                   "0xB8007804"
#define DC_MEM_SCRAMBLE_BUF_PRE6_2_reg_addr                                   "0xB8007808"
#define DC_MEM_SCRAMBLE_BUF_PRE6_3_reg_addr                                   "0xB800780C"
#define DC_MEM_SCRAMBLE_BUF_PRE6_4_reg_addr                                   "0xB8007810"
#define DC_MEM_SCRAMBLE_BUF_PRE6_5_reg_addr                                   "0xB8007814"
#define DC_MEM_SCRAMBLE_BUF_PRE6_6_reg_addr                                   "0xB8007818"
#define DC_MEM_SCRAMBLE_BUF_PRE6_7_reg_addr                                   "0xB800781C"
#define DC_MEM_SCRAMBLE_BUF_PRE6_0_reg                                        0xB8007800
#define DC_MEM_SCRAMBLE_BUF_PRE6_1_reg                                        0xB8007804
#define DC_MEM_SCRAMBLE_BUF_PRE6_2_reg                                        0xB8007808
#define DC_MEM_SCRAMBLE_BUF_PRE6_3_reg                                        0xB800780C
#define DC_MEM_SCRAMBLE_BUF_PRE6_4_reg                                        0xB8007810
#define DC_MEM_SCRAMBLE_BUF_PRE6_5_reg                                        0xB8007814
#define DC_MEM_SCRAMBLE_BUF_PRE6_6_reg                                        0xB8007818
#define DC_MEM_SCRAMBLE_BUF_PRE6_7_reg                                        0xB800781C
#define set_DC_MEM_SCRAMBLE_BUF_PRE6_0_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE6_0_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE6_1_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE6_1_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE6_2_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE6_2_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE6_3_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE6_3_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE6_4_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE6_4_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE6_5_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE6_5_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE6_6_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE6_6_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_PRE6_7_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE6_7_reg)=data)
#define get_DC_MEM_SCRAMBLE_BUF_PRE6_0_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE6_0_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE6_1_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE6_1_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE6_2_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE6_2_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE6_3_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE6_3_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE6_4_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE6_4_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE6_5_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE6_5_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE6_6_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE6_6_reg))
#define get_DC_MEM_SCRAMBLE_BUF_PRE6_7_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_PRE6_7_reg))
#define DC_MEM_SCRAMBLE_BUF_PRE6_0_inst_adr                                   "0x0000"
#define DC_MEM_SCRAMBLE_BUF_PRE6_1_inst_adr                                   "0x0001"
#define DC_MEM_SCRAMBLE_BUF_PRE6_2_inst_adr                                   "0x0002"
#define DC_MEM_SCRAMBLE_BUF_PRE6_3_inst_adr                                   "0x0003"
#define DC_MEM_SCRAMBLE_BUF_PRE6_4_inst_adr                                   "0x0004"
#define DC_MEM_SCRAMBLE_BUF_PRE6_5_inst_adr                                   "0x0005"
#define DC_MEM_SCRAMBLE_BUF_PRE6_6_inst_adr                                   "0x0006"
#define DC_MEM_SCRAMBLE_BUF_PRE6_7_inst_adr                                   "0x0007"
#define DC_MEM_SCRAMBLE_BUF_PRE6_0_inst                                       0x0000
#define DC_MEM_SCRAMBLE_BUF_PRE6_1_inst                                       0x0001
#define DC_MEM_SCRAMBLE_BUF_PRE6_2_inst                                       0x0002
#define DC_MEM_SCRAMBLE_BUF_PRE6_3_inst                                       0x0003
#define DC_MEM_SCRAMBLE_BUF_PRE6_4_inst                                       0x0004
#define DC_MEM_SCRAMBLE_BUF_PRE6_5_inst                                       0x0005
#define DC_MEM_SCRAMBLE_BUF_PRE6_6_inst                                       0x0006
#define DC_MEM_SCRAMBLE_BUF_PRE6_7_inst                                       0x0007
#define DC_MEM_SCRAMBLE_BUF_PRE6_keyD_shift                                   (16)
#define DC_MEM_SCRAMBLE_BUF_PRE6_keyD_mask                                    (0xFFFF0000)
#define DC_MEM_SCRAMBLE_BUF_PRE6_keyD(data)                                   (0xFFFF0000&((data)<<16))
#define DC_MEM_SCRAMBLE_BUF_PRE6_keyD_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_PRE6_get_keyD(data)                               ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_PRE6_keyC_shift                                   (0)
#define DC_MEM_SCRAMBLE_BUF_PRE6_keyC_mask                                    (0x0000FFFF)
#define DC_MEM_SCRAMBLE_BUF_PRE6_keyC(data)                                   (0x0000FFFF&((data)<<0))
#define DC_MEM_SCRAMBLE_BUF_PRE6_keyC_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC_MEM_SCRAMBLE_BUF_PRE6_get_keyC(data)                               ((0x0000FFFF&(data))>>0)


#define DC_MEM_SCRAMBLE_BUF_UP0_0                                             0x18007820
#define DC_MEM_SCRAMBLE_BUF_UP0_1                                             0x18007824
#define DC_MEM_SCRAMBLE_BUF_UP0_2                                             0x18007828
#define DC_MEM_SCRAMBLE_BUF_UP0_3                                             0x1800782C
#define DC_MEM_SCRAMBLE_BUF_UP0_4                                             0x18007830
#define DC_MEM_SCRAMBLE_BUF_UP0_5                                             0x18007834
#define DC_MEM_SCRAMBLE_BUF_UP0_6                                             0x18007838
#define DC_MEM_SCRAMBLE_BUF_UP0_7                                             0x1800783C
#define DC_MEM_SCRAMBLE_BUF_UP0_0_reg_addr                                    "0xB8007820"
#define DC_MEM_SCRAMBLE_BUF_UP0_1_reg_addr                                    "0xB8007824"
#define DC_MEM_SCRAMBLE_BUF_UP0_2_reg_addr                                    "0xB8007828"
#define DC_MEM_SCRAMBLE_BUF_UP0_3_reg_addr                                    "0xB800782C"
#define DC_MEM_SCRAMBLE_BUF_UP0_4_reg_addr                                    "0xB8007830"
#define DC_MEM_SCRAMBLE_BUF_UP0_5_reg_addr                                    "0xB8007834"
#define DC_MEM_SCRAMBLE_BUF_UP0_6_reg_addr                                    "0xB8007838"
#define DC_MEM_SCRAMBLE_BUF_UP0_7_reg_addr                                    "0xB800783C"
#define DC_MEM_SCRAMBLE_BUF_UP0_0_reg                                         0xB8007820
#define DC_MEM_SCRAMBLE_BUF_UP0_1_reg                                         0xB8007824
#define DC_MEM_SCRAMBLE_BUF_UP0_2_reg                                         0xB8007828
#define DC_MEM_SCRAMBLE_BUF_UP0_3_reg                                         0xB800782C
#define DC_MEM_SCRAMBLE_BUF_UP0_4_reg                                         0xB8007830
#define DC_MEM_SCRAMBLE_BUF_UP0_5_reg                                         0xB8007834
#define DC_MEM_SCRAMBLE_BUF_UP0_6_reg                                         0xB8007838
#define DC_MEM_SCRAMBLE_BUF_UP0_7_reg                                         0xB800783C
#define set_DC_MEM_SCRAMBLE_BUF_UP0_0_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP0_0_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP0_1_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP0_1_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP0_2_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP0_2_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP0_3_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP0_3_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP0_4_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP0_4_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP0_5_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP0_5_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP0_6_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP0_6_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP0_7_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP0_7_reg)=data)
#define get_DC_MEM_SCRAMBLE_BUF_UP0_0_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP0_0_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP0_1_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP0_1_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP0_2_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP0_2_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP0_3_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP0_3_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP0_4_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP0_4_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP0_5_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP0_5_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP0_6_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP0_6_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP0_7_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP0_7_reg))
#define DC_MEM_SCRAMBLE_BUF_UP0_0_inst_adr                                    "0x0008"
#define DC_MEM_SCRAMBLE_BUF_UP0_1_inst_adr                                    "0x0009"
#define DC_MEM_SCRAMBLE_BUF_UP0_2_inst_adr                                    "0x000A"
#define DC_MEM_SCRAMBLE_BUF_UP0_3_inst_adr                                    "0x000B"
#define DC_MEM_SCRAMBLE_BUF_UP0_4_inst_adr                                    "0x000C"
#define DC_MEM_SCRAMBLE_BUF_UP0_5_inst_adr                                    "0x000D"
#define DC_MEM_SCRAMBLE_BUF_UP0_6_inst_adr                                    "0x000E"
#define DC_MEM_SCRAMBLE_BUF_UP0_7_inst_adr                                    "0x000F"
#define DC_MEM_SCRAMBLE_BUF_UP0_0_inst                                        0x0008
#define DC_MEM_SCRAMBLE_BUF_UP0_1_inst                                        0x0009
#define DC_MEM_SCRAMBLE_BUF_UP0_2_inst                                        0x000A
#define DC_MEM_SCRAMBLE_BUF_UP0_3_inst                                        0x000B
#define DC_MEM_SCRAMBLE_BUF_UP0_4_inst                                        0x000C
#define DC_MEM_SCRAMBLE_BUF_UP0_5_inst                                        0x000D
#define DC_MEM_SCRAMBLE_BUF_UP0_6_inst                                        0x000E
#define DC_MEM_SCRAMBLE_BUF_UP0_7_inst                                        0x000F
#define DC_MEM_SCRAMBLE_BUF_UP0_key1_shift                                    (16)
#define DC_MEM_SCRAMBLE_BUF_UP0_key1_mask                                     (0xFFFF0000)
#define DC_MEM_SCRAMBLE_BUF_UP0_key1(data)                                    (0xFFFF0000&((data)<<16))
#define DC_MEM_SCRAMBLE_BUF_UP0_key1_src(data)                                ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_UP0_get_key1(data)                                ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_UP0_key0_shift                                    (0)
#define DC_MEM_SCRAMBLE_BUF_UP0_key0_mask                                     (0x0000FFFF)
#define DC_MEM_SCRAMBLE_BUF_UP0_key0(data)                                    (0x0000FFFF&((data)<<0))
#define DC_MEM_SCRAMBLE_BUF_UP0_key0_src(data)                                ((0x0000FFFF&(data))>>0)
#define DC_MEM_SCRAMBLE_BUF_UP0_get_key0(data)                                ((0x0000FFFF&(data))>>0)


#define DC_MEM_SCRAMBLE_BUF_UP1_0                                             0x18007840
#define DC_MEM_SCRAMBLE_BUF_UP1_1                                             0x18007844
#define DC_MEM_SCRAMBLE_BUF_UP1_2                                             0x18007848
#define DC_MEM_SCRAMBLE_BUF_UP1_3                                             0x1800784C
#define DC_MEM_SCRAMBLE_BUF_UP1_4                                             0x18007850
#define DC_MEM_SCRAMBLE_BUF_UP1_5                                             0x18007854
#define DC_MEM_SCRAMBLE_BUF_UP1_6                                             0x18007858
#define DC_MEM_SCRAMBLE_BUF_UP1_7                                             0x1800785C
#define DC_MEM_SCRAMBLE_BUF_UP1_0_reg_addr                                    "0xB8007840"
#define DC_MEM_SCRAMBLE_BUF_UP1_1_reg_addr                                    "0xB8007844"
#define DC_MEM_SCRAMBLE_BUF_UP1_2_reg_addr                                    "0xB8007848"
#define DC_MEM_SCRAMBLE_BUF_UP1_3_reg_addr                                    "0xB800784C"
#define DC_MEM_SCRAMBLE_BUF_UP1_4_reg_addr                                    "0xB8007850"
#define DC_MEM_SCRAMBLE_BUF_UP1_5_reg_addr                                    "0xB8007854"
#define DC_MEM_SCRAMBLE_BUF_UP1_6_reg_addr                                    "0xB8007858"
#define DC_MEM_SCRAMBLE_BUF_UP1_7_reg_addr                                    "0xB800785C"
#define DC_MEM_SCRAMBLE_BUF_UP1_0_reg                                         0xB8007840
#define DC_MEM_SCRAMBLE_BUF_UP1_1_reg                                         0xB8007844
#define DC_MEM_SCRAMBLE_BUF_UP1_2_reg                                         0xB8007848
#define DC_MEM_SCRAMBLE_BUF_UP1_3_reg                                         0xB800784C
#define DC_MEM_SCRAMBLE_BUF_UP1_4_reg                                         0xB8007850
#define DC_MEM_SCRAMBLE_BUF_UP1_5_reg                                         0xB8007854
#define DC_MEM_SCRAMBLE_BUF_UP1_6_reg                                         0xB8007858
#define DC_MEM_SCRAMBLE_BUF_UP1_7_reg                                         0xB800785C
#define set_DC_MEM_SCRAMBLE_BUF_UP1_0_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP1_0_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP1_1_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP1_1_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP1_2_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP1_2_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP1_3_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP1_3_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP1_4_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP1_4_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP1_5_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP1_5_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP1_6_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP1_6_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP1_7_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP1_7_reg)=data)
#define get_DC_MEM_SCRAMBLE_BUF_UP1_0_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP1_0_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP1_1_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP1_1_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP1_2_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP1_2_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP1_3_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP1_3_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP1_4_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP1_4_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP1_5_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP1_5_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP1_6_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP1_6_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP1_7_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP1_7_reg))
#define DC_MEM_SCRAMBLE_BUF_UP1_0_inst_adr                                    "0x0010"
#define DC_MEM_SCRAMBLE_BUF_UP1_1_inst_adr                                    "0x0011"
#define DC_MEM_SCRAMBLE_BUF_UP1_2_inst_adr                                    "0x0012"
#define DC_MEM_SCRAMBLE_BUF_UP1_3_inst_adr                                    "0x0013"
#define DC_MEM_SCRAMBLE_BUF_UP1_4_inst_adr                                    "0x0014"
#define DC_MEM_SCRAMBLE_BUF_UP1_5_inst_adr                                    "0x0015"
#define DC_MEM_SCRAMBLE_BUF_UP1_6_inst_adr                                    "0x0016"
#define DC_MEM_SCRAMBLE_BUF_UP1_7_inst_adr                                    "0x0017"
#define DC_MEM_SCRAMBLE_BUF_UP1_0_inst                                        0x0010
#define DC_MEM_SCRAMBLE_BUF_UP1_1_inst                                        0x0011
#define DC_MEM_SCRAMBLE_BUF_UP1_2_inst                                        0x0012
#define DC_MEM_SCRAMBLE_BUF_UP1_3_inst                                        0x0013
#define DC_MEM_SCRAMBLE_BUF_UP1_4_inst                                        0x0014
#define DC_MEM_SCRAMBLE_BUF_UP1_5_inst                                        0x0015
#define DC_MEM_SCRAMBLE_BUF_UP1_6_inst                                        0x0016
#define DC_MEM_SCRAMBLE_BUF_UP1_7_inst                                        0x0017
#define DC_MEM_SCRAMBLE_BUF_UP1_key3_shift                                    (16)
#define DC_MEM_SCRAMBLE_BUF_UP1_key3_mask                                     (0xFFFF0000)
#define DC_MEM_SCRAMBLE_BUF_UP1_key3(data)                                    (0xFFFF0000&((data)<<16))
#define DC_MEM_SCRAMBLE_BUF_UP1_key3_src(data)                                ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_UP1_get_key3(data)                                ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_UP1_key2_shift                                    (0)
#define DC_MEM_SCRAMBLE_BUF_UP1_key2_mask                                     (0x0000FFFF)
#define DC_MEM_SCRAMBLE_BUF_UP1_key2(data)                                    (0x0000FFFF&((data)<<0))
#define DC_MEM_SCRAMBLE_BUF_UP1_key2_src(data)                                ((0x0000FFFF&(data))>>0)
#define DC_MEM_SCRAMBLE_BUF_UP1_get_key2(data)                                ((0x0000FFFF&(data))>>0)


#define DC_MEM_SCRAMBLE_BUF_UP2_0                                             0x18007860
#define DC_MEM_SCRAMBLE_BUF_UP2_1                                             0x18007864
#define DC_MEM_SCRAMBLE_BUF_UP2_2                                             0x18007868
#define DC_MEM_SCRAMBLE_BUF_UP2_3                                             0x1800786C
#define DC_MEM_SCRAMBLE_BUF_UP2_4                                             0x18007870
#define DC_MEM_SCRAMBLE_BUF_UP2_5                                             0x18007874
#define DC_MEM_SCRAMBLE_BUF_UP2_6                                             0x18007878
#define DC_MEM_SCRAMBLE_BUF_UP2_7                                             0x1800787C
#define DC_MEM_SCRAMBLE_BUF_UP2_0_reg_addr                                    "0xB8007860"
#define DC_MEM_SCRAMBLE_BUF_UP2_1_reg_addr                                    "0xB8007864"
#define DC_MEM_SCRAMBLE_BUF_UP2_2_reg_addr                                    "0xB8007868"
#define DC_MEM_SCRAMBLE_BUF_UP2_3_reg_addr                                    "0xB800786C"
#define DC_MEM_SCRAMBLE_BUF_UP2_4_reg_addr                                    "0xB8007870"
#define DC_MEM_SCRAMBLE_BUF_UP2_5_reg_addr                                    "0xB8007874"
#define DC_MEM_SCRAMBLE_BUF_UP2_6_reg_addr                                    "0xB8007878"
#define DC_MEM_SCRAMBLE_BUF_UP2_7_reg_addr                                    "0xB800787C"
#define DC_MEM_SCRAMBLE_BUF_UP2_0_reg                                         0xB8007860
#define DC_MEM_SCRAMBLE_BUF_UP2_1_reg                                         0xB8007864
#define DC_MEM_SCRAMBLE_BUF_UP2_2_reg                                         0xB8007868
#define DC_MEM_SCRAMBLE_BUF_UP2_3_reg                                         0xB800786C
#define DC_MEM_SCRAMBLE_BUF_UP2_4_reg                                         0xB8007870
#define DC_MEM_SCRAMBLE_BUF_UP2_5_reg                                         0xB8007874
#define DC_MEM_SCRAMBLE_BUF_UP2_6_reg                                         0xB8007878
#define DC_MEM_SCRAMBLE_BUF_UP2_7_reg                                         0xB800787C
#define set_DC_MEM_SCRAMBLE_BUF_UP2_0_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP2_0_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP2_1_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP2_1_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP2_2_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP2_2_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP2_3_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP2_3_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP2_4_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP2_4_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP2_5_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP2_5_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP2_6_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP2_6_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP2_7_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP2_7_reg)=data)
#define get_DC_MEM_SCRAMBLE_BUF_UP2_0_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP2_0_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP2_1_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP2_1_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP2_2_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP2_2_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP2_3_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP2_3_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP2_4_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP2_4_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP2_5_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP2_5_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP2_6_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP2_6_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP2_7_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP2_7_reg))
#define DC_MEM_SCRAMBLE_BUF_UP2_0_inst_adr                                    "0x0018"
#define DC_MEM_SCRAMBLE_BUF_UP2_1_inst_adr                                    "0x0019"
#define DC_MEM_SCRAMBLE_BUF_UP2_2_inst_adr                                    "0x001A"
#define DC_MEM_SCRAMBLE_BUF_UP2_3_inst_adr                                    "0x001B"
#define DC_MEM_SCRAMBLE_BUF_UP2_4_inst_adr                                    "0x001C"
#define DC_MEM_SCRAMBLE_BUF_UP2_5_inst_adr                                    "0x001D"
#define DC_MEM_SCRAMBLE_BUF_UP2_6_inst_adr                                    "0x001E"
#define DC_MEM_SCRAMBLE_BUF_UP2_7_inst_adr                                    "0x001F"
#define DC_MEM_SCRAMBLE_BUF_UP2_0_inst                                        0x0018
#define DC_MEM_SCRAMBLE_BUF_UP2_1_inst                                        0x0019
#define DC_MEM_SCRAMBLE_BUF_UP2_2_inst                                        0x001A
#define DC_MEM_SCRAMBLE_BUF_UP2_3_inst                                        0x001B
#define DC_MEM_SCRAMBLE_BUF_UP2_4_inst                                        0x001C
#define DC_MEM_SCRAMBLE_BUF_UP2_5_inst                                        0x001D
#define DC_MEM_SCRAMBLE_BUF_UP2_6_inst                                        0x001E
#define DC_MEM_SCRAMBLE_BUF_UP2_7_inst                                        0x001F
#define DC_MEM_SCRAMBLE_BUF_UP2_key5_shift                                    (16)
#define DC_MEM_SCRAMBLE_BUF_UP2_key5_mask                                     (0xFFFF0000)
#define DC_MEM_SCRAMBLE_BUF_UP2_key5(data)                                    (0xFFFF0000&((data)<<16))
#define DC_MEM_SCRAMBLE_BUF_UP2_key5_src(data)                                ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_UP2_get_key5(data)                                ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_UP2_key4_shift                                    (0)
#define DC_MEM_SCRAMBLE_BUF_UP2_key4_mask                                     (0x0000FFFF)
#define DC_MEM_SCRAMBLE_BUF_UP2_key4(data)                                    (0x0000FFFF&((data)<<0))
#define DC_MEM_SCRAMBLE_BUF_UP2_key4_src(data)                                ((0x0000FFFF&(data))>>0)
#define DC_MEM_SCRAMBLE_BUF_UP2_get_key4(data)                                ((0x0000FFFF&(data))>>0)


#define DC_MEM_SCRAMBLE_BUF_UP3_0                                             0x18007880
#define DC_MEM_SCRAMBLE_BUF_UP3_1                                             0x18007884
#define DC_MEM_SCRAMBLE_BUF_UP3_2                                             0x18007888
#define DC_MEM_SCRAMBLE_BUF_UP3_3                                             0x1800788C
#define DC_MEM_SCRAMBLE_BUF_UP3_4                                             0x18007890
#define DC_MEM_SCRAMBLE_BUF_UP3_5                                             0x18007894
#define DC_MEM_SCRAMBLE_BUF_UP3_6                                             0x18007898
#define DC_MEM_SCRAMBLE_BUF_UP3_7                                             0x1800789C
#define DC_MEM_SCRAMBLE_BUF_UP3_0_reg_addr                                    "0xB8007880"
#define DC_MEM_SCRAMBLE_BUF_UP3_1_reg_addr                                    "0xB8007884"
#define DC_MEM_SCRAMBLE_BUF_UP3_2_reg_addr                                    "0xB8007888"
#define DC_MEM_SCRAMBLE_BUF_UP3_3_reg_addr                                    "0xB800788C"
#define DC_MEM_SCRAMBLE_BUF_UP3_4_reg_addr                                    "0xB8007890"
#define DC_MEM_SCRAMBLE_BUF_UP3_5_reg_addr                                    "0xB8007894"
#define DC_MEM_SCRAMBLE_BUF_UP3_6_reg_addr                                    "0xB8007898"
#define DC_MEM_SCRAMBLE_BUF_UP3_7_reg_addr                                    "0xB800789C"
#define DC_MEM_SCRAMBLE_BUF_UP3_0_reg                                         0xB8007880
#define DC_MEM_SCRAMBLE_BUF_UP3_1_reg                                         0xB8007884
#define DC_MEM_SCRAMBLE_BUF_UP3_2_reg                                         0xB8007888
#define DC_MEM_SCRAMBLE_BUF_UP3_3_reg                                         0xB800788C
#define DC_MEM_SCRAMBLE_BUF_UP3_4_reg                                         0xB8007890
#define DC_MEM_SCRAMBLE_BUF_UP3_5_reg                                         0xB8007894
#define DC_MEM_SCRAMBLE_BUF_UP3_6_reg                                         0xB8007898
#define DC_MEM_SCRAMBLE_BUF_UP3_7_reg                                         0xB800789C
#define set_DC_MEM_SCRAMBLE_BUF_UP3_0_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP3_0_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP3_1_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP3_1_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP3_2_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP3_2_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP3_3_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP3_3_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP3_4_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP3_4_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP3_5_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP3_5_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP3_6_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP3_6_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP3_7_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP3_7_reg)=data)
#define get_DC_MEM_SCRAMBLE_BUF_UP3_0_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP3_0_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP3_1_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP3_1_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP3_2_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP3_2_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP3_3_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP3_3_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP3_4_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP3_4_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP3_5_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP3_5_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP3_6_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP3_6_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP3_7_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP3_7_reg))
#define DC_MEM_SCRAMBLE_BUF_UP3_0_inst_adr                                    "0x0020"
#define DC_MEM_SCRAMBLE_BUF_UP3_1_inst_adr                                    "0x0021"
#define DC_MEM_SCRAMBLE_BUF_UP3_2_inst_adr                                    "0x0022"
#define DC_MEM_SCRAMBLE_BUF_UP3_3_inst_adr                                    "0x0023"
#define DC_MEM_SCRAMBLE_BUF_UP3_4_inst_adr                                    "0x0024"
#define DC_MEM_SCRAMBLE_BUF_UP3_5_inst_adr                                    "0x0025"
#define DC_MEM_SCRAMBLE_BUF_UP3_6_inst_adr                                    "0x0026"
#define DC_MEM_SCRAMBLE_BUF_UP3_7_inst_adr                                    "0x0027"
#define DC_MEM_SCRAMBLE_BUF_UP3_0_inst                                        0x0020
#define DC_MEM_SCRAMBLE_BUF_UP3_1_inst                                        0x0021
#define DC_MEM_SCRAMBLE_BUF_UP3_2_inst                                        0x0022
#define DC_MEM_SCRAMBLE_BUF_UP3_3_inst                                        0x0023
#define DC_MEM_SCRAMBLE_BUF_UP3_4_inst                                        0x0024
#define DC_MEM_SCRAMBLE_BUF_UP3_5_inst                                        0x0025
#define DC_MEM_SCRAMBLE_BUF_UP3_6_inst                                        0x0026
#define DC_MEM_SCRAMBLE_BUF_UP3_7_inst                                        0x0027
#define DC_MEM_SCRAMBLE_BUF_UP3_key7_shift                                    (16)
#define DC_MEM_SCRAMBLE_BUF_UP3_key7_mask                                     (0xFFFF0000)
#define DC_MEM_SCRAMBLE_BUF_UP3_key7(data)                                    (0xFFFF0000&((data)<<16))
#define DC_MEM_SCRAMBLE_BUF_UP3_key7_src(data)                                ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_UP3_get_key7(data)                                ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_UP3_key6_shift                                    (0)
#define DC_MEM_SCRAMBLE_BUF_UP3_key6_mask                                     (0x0000FFFF)
#define DC_MEM_SCRAMBLE_BUF_UP3_key6(data)                                    (0x0000FFFF&((data)<<0))
#define DC_MEM_SCRAMBLE_BUF_UP3_key6_src(data)                                ((0x0000FFFF&(data))>>0)
#define DC_MEM_SCRAMBLE_BUF_UP3_get_key6(data)                                ((0x0000FFFF&(data))>>0)


#define DC_MEM_SCRAMBLE_BUF_UP4_0                                             0x180078A0
#define DC_MEM_SCRAMBLE_BUF_UP4_1                                             0x180078A4
#define DC_MEM_SCRAMBLE_BUF_UP4_2                                             0x180078A8
#define DC_MEM_SCRAMBLE_BUF_UP4_3                                             0x180078AC
#define DC_MEM_SCRAMBLE_BUF_UP4_4                                             0x180078B0
#define DC_MEM_SCRAMBLE_BUF_UP4_5                                             0x180078B4
#define DC_MEM_SCRAMBLE_BUF_UP4_6                                             0x180078B8
#define DC_MEM_SCRAMBLE_BUF_UP4_7                                             0x180078BC
#define DC_MEM_SCRAMBLE_BUF_UP4_0_reg_addr                                    "0xB80078A0"
#define DC_MEM_SCRAMBLE_BUF_UP4_1_reg_addr                                    "0xB80078A4"
#define DC_MEM_SCRAMBLE_BUF_UP4_2_reg_addr                                    "0xB80078A8"
#define DC_MEM_SCRAMBLE_BUF_UP4_3_reg_addr                                    "0xB80078AC"
#define DC_MEM_SCRAMBLE_BUF_UP4_4_reg_addr                                    "0xB80078B0"
#define DC_MEM_SCRAMBLE_BUF_UP4_5_reg_addr                                    "0xB80078B4"
#define DC_MEM_SCRAMBLE_BUF_UP4_6_reg_addr                                    "0xB80078B8"
#define DC_MEM_SCRAMBLE_BUF_UP4_7_reg_addr                                    "0xB80078BC"
#define DC_MEM_SCRAMBLE_BUF_UP4_0_reg                                         0xB80078A0
#define DC_MEM_SCRAMBLE_BUF_UP4_1_reg                                         0xB80078A4
#define DC_MEM_SCRAMBLE_BUF_UP4_2_reg                                         0xB80078A8
#define DC_MEM_SCRAMBLE_BUF_UP4_3_reg                                         0xB80078AC
#define DC_MEM_SCRAMBLE_BUF_UP4_4_reg                                         0xB80078B0
#define DC_MEM_SCRAMBLE_BUF_UP4_5_reg                                         0xB80078B4
#define DC_MEM_SCRAMBLE_BUF_UP4_6_reg                                         0xB80078B8
#define DC_MEM_SCRAMBLE_BUF_UP4_7_reg                                         0xB80078BC
#define set_DC_MEM_SCRAMBLE_BUF_UP4_0_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP4_0_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP4_1_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP4_1_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP4_2_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP4_2_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP4_3_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP4_3_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP4_4_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP4_4_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP4_5_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP4_5_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP4_6_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP4_6_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP4_7_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP4_7_reg)=data)
#define get_DC_MEM_SCRAMBLE_BUF_UP4_0_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP4_0_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP4_1_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP4_1_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP4_2_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP4_2_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP4_3_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP4_3_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP4_4_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP4_4_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP4_5_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP4_5_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP4_6_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP4_6_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP4_7_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP4_7_reg))
#define DC_MEM_SCRAMBLE_BUF_UP4_0_inst_adr                                    "0x0028"
#define DC_MEM_SCRAMBLE_BUF_UP4_1_inst_adr                                    "0x0029"
#define DC_MEM_SCRAMBLE_BUF_UP4_2_inst_adr                                    "0x002A"
#define DC_MEM_SCRAMBLE_BUF_UP4_3_inst_adr                                    "0x002B"
#define DC_MEM_SCRAMBLE_BUF_UP4_4_inst_adr                                    "0x002C"
#define DC_MEM_SCRAMBLE_BUF_UP4_5_inst_adr                                    "0x002D"
#define DC_MEM_SCRAMBLE_BUF_UP4_6_inst_adr                                    "0x002E"
#define DC_MEM_SCRAMBLE_BUF_UP4_7_inst_adr                                    "0x002F"
#define DC_MEM_SCRAMBLE_BUF_UP4_0_inst                                        0x0028
#define DC_MEM_SCRAMBLE_BUF_UP4_1_inst                                        0x0029
#define DC_MEM_SCRAMBLE_BUF_UP4_2_inst                                        0x002A
#define DC_MEM_SCRAMBLE_BUF_UP4_3_inst                                        0x002B
#define DC_MEM_SCRAMBLE_BUF_UP4_4_inst                                        0x002C
#define DC_MEM_SCRAMBLE_BUF_UP4_5_inst                                        0x002D
#define DC_MEM_SCRAMBLE_BUF_UP4_6_inst                                        0x002E
#define DC_MEM_SCRAMBLE_BUF_UP4_7_inst                                        0x002F
#define DC_MEM_SCRAMBLE_BUF_UP4_key9_shift                                    (16)
#define DC_MEM_SCRAMBLE_BUF_UP4_key9_mask                                     (0xFFFF0000)
#define DC_MEM_SCRAMBLE_BUF_UP4_key9(data)                                    (0xFFFF0000&((data)<<16))
#define DC_MEM_SCRAMBLE_BUF_UP4_key9_src(data)                                ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_UP4_get_key9(data)                                ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_UP4_key8_shift                                    (0)
#define DC_MEM_SCRAMBLE_BUF_UP4_key8_mask                                     (0x0000FFFF)
#define DC_MEM_SCRAMBLE_BUF_UP4_key8(data)                                    (0x0000FFFF&((data)<<0))
#define DC_MEM_SCRAMBLE_BUF_UP4_key8_src(data)                                ((0x0000FFFF&(data))>>0)
#define DC_MEM_SCRAMBLE_BUF_UP4_get_key8(data)                                ((0x0000FFFF&(data))>>0)


#define DC_MEM_SCRAMBLE_BUF_UP5_0                                             0x180078C0
#define DC_MEM_SCRAMBLE_BUF_UP5_1                                             0x180078C4
#define DC_MEM_SCRAMBLE_BUF_UP5_2                                             0x180078C8
#define DC_MEM_SCRAMBLE_BUF_UP5_3                                             0x180078CC
#define DC_MEM_SCRAMBLE_BUF_UP5_4                                             0x180078D0
#define DC_MEM_SCRAMBLE_BUF_UP5_5                                             0x180078D4
#define DC_MEM_SCRAMBLE_BUF_UP5_6                                             0x180078D8
#define DC_MEM_SCRAMBLE_BUF_UP5_7                                             0x180078DC
#define DC_MEM_SCRAMBLE_BUF_UP5_0_reg_addr                                    "0xB80078C0"
#define DC_MEM_SCRAMBLE_BUF_UP5_1_reg_addr                                    "0xB80078C4"
#define DC_MEM_SCRAMBLE_BUF_UP5_2_reg_addr                                    "0xB80078C8"
#define DC_MEM_SCRAMBLE_BUF_UP5_3_reg_addr                                    "0xB80078CC"
#define DC_MEM_SCRAMBLE_BUF_UP5_4_reg_addr                                    "0xB80078D0"
#define DC_MEM_SCRAMBLE_BUF_UP5_5_reg_addr                                    "0xB80078D4"
#define DC_MEM_SCRAMBLE_BUF_UP5_6_reg_addr                                    "0xB80078D8"
#define DC_MEM_SCRAMBLE_BUF_UP5_7_reg_addr                                    "0xB80078DC"
#define DC_MEM_SCRAMBLE_BUF_UP5_0_reg                                         0xB80078C0
#define DC_MEM_SCRAMBLE_BUF_UP5_1_reg                                         0xB80078C4
#define DC_MEM_SCRAMBLE_BUF_UP5_2_reg                                         0xB80078C8
#define DC_MEM_SCRAMBLE_BUF_UP5_3_reg                                         0xB80078CC
#define DC_MEM_SCRAMBLE_BUF_UP5_4_reg                                         0xB80078D0
#define DC_MEM_SCRAMBLE_BUF_UP5_5_reg                                         0xB80078D4
#define DC_MEM_SCRAMBLE_BUF_UP5_6_reg                                         0xB80078D8
#define DC_MEM_SCRAMBLE_BUF_UP5_7_reg                                         0xB80078DC
#define set_DC_MEM_SCRAMBLE_BUF_UP5_0_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP5_0_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP5_1_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP5_1_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP5_2_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP5_2_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP5_3_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP5_3_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP5_4_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP5_4_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP5_5_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP5_5_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP5_6_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP5_6_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP5_7_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP5_7_reg)=data)
#define get_DC_MEM_SCRAMBLE_BUF_UP5_0_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP5_0_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP5_1_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP5_1_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP5_2_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP5_2_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP5_3_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP5_3_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP5_4_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP5_4_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP5_5_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP5_5_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP5_6_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP5_6_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP5_7_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP5_7_reg))
#define DC_MEM_SCRAMBLE_BUF_UP5_0_inst_adr                                    "0x0030"
#define DC_MEM_SCRAMBLE_BUF_UP5_1_inst_adr                                    "0x0031"
#define DC_MEM_SCRAMBLE_BUF_UP5_2_inst_adr                                    "0x0032"
#define DC_MEM_SCRAMBLE_BUF_UP5_3_inst_adr                                    "0x0033"
#define DC_MEM_SCRAMBLE_BUF_UP5_4_inst_adr                                    "0x0034"
#define DC_MEM_SCRAMBLE_BUF_UP5_5_inst_adr                                    "0x0035"
#define DC_MEM_SCRAMBLE_BUF_UP5_6_inst_adr                                    "0x0036"
#define DC_MEM_SCRAMBLE_BUF_UP5_7_inst_adr                                    "0x0037"
#define DC_MEM_SCRAMBLE_BUF_UP5_0_inst                                        0x0030
#define DC_MEM_SCRAMBLE_BUF_UP5_1_inst                                        0x0031
#define DC_MEM_SCRAMBLE_BUF_UP5_2_inst                                        0x0032
#define DC_MEM_SCRAMBLE_BUF_UP5_3_inst                                        0x0033
#define DC_MEM_SCRAMBLE_BUF_UP5_4_inst                                        0x0034
#define DC_MEM_SCRAMBLE_BUF_UP5_5_inst                                        0x0035
#define DC_MEM_SCRAMBLE_BUF_UP5_6_inst                                        0x0036
#define DC_MEM_SCRAMBLE_BUF_UP5_7_inst                                        0x0037
#define DC_MEM_SCRAMBLE_BUF_UP5_keyB_shift                                    (16)
#define DC_MEM_SCRAMBLE_BUF_UP5_keyB_mask                                     (0xFFFF0000)
#define DC_MEM_SCRAMBLE_BUF_UP5_keyB(data)                                    (0xFFFF0000&((data)<<16))
#define DC_MEM_SCRAMBLE_BUF_UP5_keyB_src(data)                                ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_UP5_get_keyB(data)                                ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_UP5_keyA_shift                                    (0)
#define DC_MEM_SCRAMBLE_BUF_UP5_keyA_mask                                     (0x0000FFFF)
#define DC_MEM_SCRAMBLE_BUF_UP5_keyA(data)                                    (0x0000FFFF&((data)<<0))
#define DC_MEM_SCRAMBLE_BUF_UP5_keyA_src(data)                                ((0x0000FFFF&(data))>>0)
#define DC_MEM_SCRAMBLE_BUF_UP5_get_keyA(data)                                ((0x0000FFFF&(data))>>0)


#define DC_MEM_SCRAMBLE_BUF_UP6_0                                             0x180078E0
#define DC_MEM_SCRAMBLE_BUF_UP6_1                                             0x180078E4
#define DC_MEM_SCRAMBLE_BUF_UP6_2                                             0x180078E8
#define DC_MEM_SCRAMBLE_BUF_UP6_3                                             0x180078EC
#define DC_MEM_SCRAMBLE_BUF_UP6_4                                             0x180078F0
#define DC_MEM_SCRAMBLE_BUF_UP6_5                                             0x180078F4
#define DC_MEM_SCRAMBLE_BUF_UP6_6                                             0x180078F8
#define DC_MEM_SCRAMBLE_BUF_UP6_7                                             0x180078FC
#define DC_MEM_SCRAMBLE_BUF_UP6_0_reg_addr                                    "0xB80078E0"
#define DC_MEM_SCRAMBLE_BUF_UP6_1_reg_addr                                    "0xB80078E4"
#define DC_MEM_SCRAMBLE_BUF_UP6_2_reg_addr                                    "0xB80078E8"
#define DC_MEM_SCRAMBLE_BUF_UP6_3_reg_addr                                    "0xB80078EC"
#define DC_MEM_SCRAMBLE_BUF_UP6_4_reg_addr                                    "0xB80078F0"
#define DC_MEM_SCRAMBLE_BUF_UP6_5_reg_addr                                    "0xB80078F4"
#define DC_MEM_SCRAMBLE_BUF_UP6_6_reg_addr                                    "0xB80078F8"
#define DC_MEM_SCRAMBLE_BUF_UP6_7_reg_addr                                    "0xB80078FC"
#define DC_MEM_SCRAMBLE_BUF_UP6_0_reg                                         0xB80078E0
#define DC_MEM_SCRAMBLE_BUF_UP6_1_reg                                         0xB80078E4
#define DC_MEM_SCRAMBLE_BUF_UP6_2_reg                                         0xB80078E8
#define DC_MEM_SCRAMBLE_BUF_UP6_3_reg                                         0xB80078EC
#define DC_MEM_SCRAMBLE_BUF_UP6_4_reg                                         0xB80078F0
#define DC_MEM_SCRAMBLE_BUF_UP6_5_reg                                         0xB80078F4
#define DC_MEM_SCRAMBLE_BUF_UP6_6_reg                                         0xB80078F8
#define DC_MEM_SCRAMBLE_BUF_UP6_7_reg                                         0xB80078FC
#define set_DC_MEM_SCRAMBLE_BUF_UP6_0_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP6_0_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP6_1_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP6_1_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP6_2_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP6_2_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP6_3_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP6_3_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP6_4_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP6_4_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP6_5_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP6_5_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP6_6_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP6_6_reg)=data)
#define set_DC_MEM_SCRAMBLE_BUF_UP6_7_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP6_7_reg)=data)
#define get_DC_MEM_SCRAMBLE_BUF_UP6_0_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP6_0_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP6_1_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP6_1_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP6_2_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP6_2_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP6_3_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP6_3_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP6_4_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP6_4_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP6_5_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP6_5_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP6_6_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP6_6_reg))
#define get_DC_MEM_SCRAMBLE_BUF_UP6_7_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_BUF_UP6_7_reg))
#define DC_MEM_SCRAMBLE_BUF_UP6_0_inst_adr                                    "0x0038"
#define DC_MEM_SCRAMBLE_BUF_UP6_1_inst_adr                                    "0x0039"
#define DC_MEM_SCRAMBLE_BUF_UP6_2_inst_adr                                    "0x003A"
#define DC_MEM_SCRAMBLE_BUF_UP6_3_inst_adr                                    "0x003B"
#define DC_MEM_SCRAMBLE_BUF_UP6_4_inst_adr                                    "0x003C"
#define DC_MEM_SCRAMBLE_BUF_UP6_5_inst_adr                                    "0x003D"
#define DC_MEM_SCRAMBLE_BUF_UP6_6_inst_adr                                    "0x003E"
#define DC_MEM_SCRAMBLE_BUF_UP6_7_inst_adr                                    "0x003F"
#define DC_MEM_SCRAMBLE_BUF_UP6_0_inst                                        0x0038
#define DC_MEM_SCRAMBLE_BUF_UP6_1_inst                                        0x0039
#define DC_MEM_SCRAMBLE_BUF_UP6_2_inst                                        0x003A
#define DC_MEM_SCRAMBLE_BUF_UP6_3_inst                                        0x003B
#define DC_MEM_SCRAMBLE_BUF_UP6_4_inst                                        0x003C
#define DC_MEM_SCRAMBLE_BUF_UP6_5_inst                                        0x003D
#define DC_MEM_SCRAMBLE_BUF_UP6_6_inst                                        0x003E
#define DC_MEM_SCRAMBLE_BUF_UP6_7_inst                                        0x003F
#define DC_MEM_SCRAMBLE_BUF_UP6_keyD_shift                                    (16)
#define DC_MEM_SCRAMBLE_BUF_UP6_keyD_mask                                     (0xFFFF0000)
#define DC_MEM_SCRAMBLE_BUF_UP6_keyD(data)                                    (0xFFFF0000&((data)<<16))
#define DC_MEM_SCRAMBLE_BUF_UP6_keyD_src(data)                                ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_UP6_get_keyD(data)                                ((0xFFFF0000&(data))>>16)
#define DC_MEM_SCRAMBLE_BUF_UP6_keyC_shift                                    (0)
#define DC_MEM_SCRAMBLE_BUF_UP6_keyC_mask                                     (0x0000FFFF)
#define DC_MEM_SCRAMBLE_BUF_UP6_keyC(data)                                    (0x0000FFFF&((data)<<0))
#define DC_MEM_SCRAMBLE_BUF_UP6_keyC_src(data)                                ((0x0000FFFF&(data))>>0)
#define DC_MEM_SCRAMBLE_BUF_UP6_get_keyC(data)                                ((0x0000FFFF&(data))>>0)


#define DC_MEM_DISPLAY_CTRL                                                   0x18007580
#define DC_MEM_DISPLAY_CTRL_reg_addr                                          "0xB8007580"
#define DC_MEM_DISPLAY_CTRL_reg                                               0xB8007580
#define set_DC_MEM_DISPLAY_CTRL_reg(data)   (*((volatile unsigned int*) DC_MEM_DISPLAY_CTRL_reg)=data)
#define get_DC_MEM_DISPLAY_CTRL_reg   (*((volatile unsigned int*) DC_MEM_DISPLAY_CTRL_reg))
#define DC_MEM_DISPLAY_CTRL_inst_adr                                          "0x0060"
#define DC_MEM_DISPLAY_CTRL_inst                                              0x0060
#define DC_MEM_DISPLAY_CTRL_display_1_en_shift                                (17)
#define DC_MEM_DISPLAY_CTRL_display_1_en_mask                                 (0x00020000)
#define DC_MEM_DISPLAY_CTRL_display_1_en(data)                                (0x00020000&((data)<<17))
#define DC_MEM_DISPLAY_CTRL_display_1_en_src(data)                            ((0x00020000&(data))>>17)
#define DC_MEM_DISPLAY_CTRL_get_display_1_en(data)                            ((0x00020000&(data))>>17)
#define DC_MEM_DISPLAY_CTRL_display_0_en_shift                                (16)
#define DC_MEM_DISPLAY_CTRL_display_0_en_mask                                 (0x00010000)
#define DC_MEM_DISPLAY_CTRL_display_0_en(data)                                (0x00010000&((data)<<16))
#define DC_MEM_DISPLAY_CTRL_display_0_en_src(data)                            ((0x00010000&(data))>>16)
#define DC_MEM_DISPLAY_CTRL_get_display_0_en(data)                            ((0x00010000&(data))>>16)
#define DC_MEM_DISPLAY_CTRL_display_1_scramble_en_shift                       (1)
#define DC_MEM_DISPLAY_CTRL_display_1_scramble_en_mask                        (0x00000002)
#define DC_MEM_DISPLAY_CTRL_display_1_scramble_en(data)                       (0x00000002&((data)<<1))
#define DC_MEM_DISPLAY_CTRL_display_1_scramble_en_src(data)                   ((0x00000002&(data))>>1)
#define DC_MEM_DISPLAY_CTRL_get_display_1_scramble_en(data)                   ((0x00000002&(data))>>1)
#define DC_MEM_DISPLAY_CTRL_display_0_scramble_en_shift                       (0)
#define DC_MEM_DISPLAY_CTRL_display_0_scramble_en_mask                        (0x00000001)
#define DC_MEM_DISPLAY_CTRL_display_0_scramble_en(data)                       (0x00000001&((data)<<0))
#define DC_MEM_DISPLAY_CTRL_display_0_scramble_en_src(data)                   ((0x00000001&(data))>>0)
#define DC_MEM_DISPLAY_CTRL_get_display_0_scramble_en(data)                   ((0x00000001&(data))>>0)


#define DC_DISPLAY_START_0                                                    0x18007588
#define DC_DISPLAY_START_1                                                    0x1800758C
#define DC_DISPLAY_START_0_reg_addr                                           "0xB8007588"
#define DC_DISPLAY_START_1_reg_addr                                           "0xB800758C"
#define DC_DISPLAY_START_0_reg                                                0xB8007588
#define DC_DISPLAY_START_1_reg                                                0xB800758C
#define set_DC_DISPLAY_START_0_reg(data)   (*((volatile unsigned int*) DC_DISPLAY_START_0_reg)=data)
#define set_DC_DISPLAY_START_1_reg(data)   (*((volatile unsigned int*) DC_DISPLAY_START_1_reg)=data)
#define get_DC_DISPLAY_START_0_reg   (*((volatile unsigned int*) DC_DISPLAY_START_0_reg))
#define get_DC_DISPLAY_START_1_reg   (*((volatile unsigned int*) DC_DISPLAY_START_1_reg))
#define DC_DISPLAY_START_0_inst_adr                                           "0x0062"
#define DC_DISPLAY_START_1_inst_adr                                           "0x0063"
#define DC_DISPLAY_START_0_inst                                               0x0062
#define DC_DISPLAY_START_1_inst                                               0x0063
#define DC_DISPLAY_START_addr_shift                                           (12)
#define DC_DISPLAY_START_addr_mask                                            (0xFFFFF000)
#define DC_DISPLAY_START_addr(data)                                           (0xFFFFF000&((data)<<12))
#define DC_DISPLAY_START_addr_src(data)                                       ((0xFFFFF000&(data))>>12)
#define DC_DISPLAY_START_get_addr(data)                                       ((0xFFFFF000&(data))>>12)


#define DC_DISPLAY_END_0                                                      0x18007590
#define DC_DISPLAY_END_1                                                      0x18007594
#define DC_DISPLAY_END_0_reg_addr                                             "0xB8007590"
#define DC_DISPLAY_END_1_reg_addr                                             "0xB8007594"
#define DC_DISPLAY_END_0_reg                                                  0xB8007590
#define DC_DISPLAY_END_1_reg                                                  0xB8007594
#define set_DC_DISPLAY_END_0_reg(data)   (*((volatile unsigned int*) DC_DISPLAY_END_0_reg)=data)
#define set_DC_DISPLAY_END_1_reg(data)   (*((volatile unsigned int*) DC_DISPLAY_END_1_reg)=data)
#define get_DC_DISPLAY_END_0_reg   (*((volatile unsigned int*) DC_DISPLAY_END_0_reg))
#define get_DC_DISPLAY_END_1_reg   (*((volatile unsigned int*) DC_DISPLAY_END_1_reg))
#define DC_DISPLAY_END_0_inst_adr                                             "0x0064"
#define DC_DISPLAY_END_1_inst_adr                                             "0x0065"
#define DC_DISPLAY_END_0_inst                                                 0x0064
#define DC_DISPLAY_END_1_inst                                                 0x0065
#define DC_DISPLAY_END_addr_shift                                             (12)
#define DC_DISPLAY_END_addr_mask                                              (0xFFFFF000)
#define DC_DISPLAY_END_addr(data)                                             (0xFFFFF000&((data)<<12))
#define DC_DISPLAY_END_addr_src(data)                                         ((0xFFFFF000&(data))>>12)
#define DC_DISPLAY_END_get_addr(data)                                         ((0xFFFFF000&(data))>>12)


#define DC_DISPLAY_ACCESS_0                                                   0x18007598
#define DC_DISPLAY_ACCESS_1                                                   0x1800759C
#define DC_DISPLAY_ACCESS_0_reg_addr                                          "0xB8007598"
#define DC_DISPLAY_ACCESS_1_reg_addr                                          "0xB800759C"
#define DC_DISPLAY_ACCESS_0_reg                                               0xB8007598
#define DC_DISPLAY_ACCESS_1_reg                                               0xB800759C
#define set_DC_DISPLAY_ACCESS_0_reg(data)   (*((volatile unsigned int*) DC_DISPLAY_ACCESS_0_reg)=data)
#define set_DC_DISPLAY_ACCESS_1_reg(data)   (*((volatile unsigned int*) DC_DISPLAY_ACCESS_1_reg)=data)
#define get_DC_DISPLAY_ACCESS_0_reg   (*((volatile unsigned int*) DC_DISPLAY_ACCESS_0_reg))
#define get_DC_DISPLAY_ACCESS_1_reg   (*((volatile unsigned int*) DC_DISPLAY_ACCESS_1_reg))
#define DC_DISPLAY_ACCESS_0_inst_adr                                          "0x0066"
#define DC_DISPLAY_ACCESS_1_inst_adr                                          "0x0067"
#define DC_DISPLAY_ACCESS_0_inst                                              0x0066
#define DC_DISPLAY_ACCESS_1_inst                                              0x0067
#define DC_DISPLAY_ACCESS_me_shift                                            (11)
#define DC_DISPLAY_ACCESS_me_mask                                             (0x00000800)
#define DC_DISPLAY_ACCESS_me(data)                                            (0x00000800&((data)<<11))
#define DC_DISPLAY_ACCESS_me_src(data)                                        ((0x00000800&(data))>>11)
#define DC_DISPLAY_ACCESS_get_me(data)                                        ((0x00000800&(data))>>11)
#define DC_DISPLAY_ACCESS_osd1_shift                                          (10)
#define DC_DISPLAY_ACCESS_osd1_mask                                           (0x00000400)
#define DC_DISPLAY_ACCESS_osd1(data)                                          (0x00000400&((data)<<10))
#define DC_DISPLAY_ACCESS_osd1_src(data)                                      ((0x00000400&(data))>>10)
#define DC_DISPLAY_ACCESS_get_osd1(data)                                      ((0x00000400&(data))>>10)
#define DC_DISPLAY_ACCESS_osd2_shift                                          (9)
#define DC_DISPLAY_ACCESS_osd2_mask                                           (0x00000200)
#define DC_DISPLAY_ACCESS_osd2(data)                                          (0x00000200&((data)<<9))
#define DC_DISPLAY_ACCESS_osd2_src(data)                                      ((0x00000200&(data))>>9)
#define DC_DISPLAY_ACCESS_get_osd2(data)                                      ((0x00000200&(data))>>9)
#define DC_DISPLAY_ACCESS_subtitle_shift                                      (8)
#define DC_DISPLAY_ACCESS_subtitle_mask                                       (0x00000100)
#define DC_DISPLAY_ACCESS_subtitle(data)                                      (0x00000100&((data)<<8))
#define DC_DISPLAY_ACCESS_subtitle_src(data)                                  ((0x00000100&(data))>>8)
#define DC_DISPLAY_ACCESS_get_subtitle(data)                                  ((0x00000100&(data))>>8)
#define DC_DISPLAY_ACCESS_vcpu_shift                                          (6)
#define DC_DISPLAY_ACCESS_vcpu_mask                                           (0x000000C0)
#define DC_DISPLAY_ACCESS_vcpu(data)                                          (0x000000C0&((data)<<6))
#define DC_DISPLAY_ACCESS_vcpu_src(data)                                      ((0x000000C0&(data))>>6)
#define DC_DISPLAY_ACCESS_get_vcpu(data)                                      ((0x000000C0&(data))>>6)
#define DC_DISPLAY_ACCESS_ve_shift                                            (5)
#define DC_DISPLAY_ACCESS_ve_mask                                             (0x00000020)
#define DC_DISPLAY_ACCESS_ve(data)                                            (0x00000020&((data)<<5))
#define DC_DISPLAY_ACCESS_ve_src(data)                                        ((0x00000020&(data))>>5)
#define DC_DISPLAY_ACCESS_get_ve(data)                                        ((0x00000020&(data))>>5)
#define DC_DISPLAY_ACCESS_vde_shift                                           (4)
#define DC_DISPLAY_ACCESS_vde_mask                                            (0x00000010)
#define DC_DISPLAY_ACCESS_vde(data)                                           (0x00000010&((data)<<4))
#define DC_DISPLAY_ACCESS_vde_src(data)                                       ((0x00000010&(data))>>4)
#define DC_DISPLAY_ACCESS_get_vde(data)                                       ((0x00000010&(data))>>4)
#define DC_DISPLAY_ACCESS_gpu_shift                                           (3)
#define DC_DISPLAY_ACCESS_gpu_mask                                            (0x00000008)
#define DC_DISPLAY_ACCESS_gpu(data)                                           (0x00000008&((data)<<3))
#define DC_DISPLAY_ACCESS_gpu_src(data)                                       ((0x00000008&(data))>>3)
#define DC_DISPLAY_ACCESS_get_gpu(data)                                       ((0x00000008&(data))>>3)
#define DC_DISPLAY_ACCESS_md_kc_shift                                         (2)
#define DC_DISPLAY_ACCESS_md_kc_mask                                          (0x00000004)
#define DC_DISPLAY_ACCESS_md_kc(data)                                         (0x00000004&((data)<<2))
#define DC_DISPLAY_ACCESS_md_kc_src(data)                                     ((0x00000004&(data))>>2)
#define DC_DISPLAY_ACCESS_get_md_kc(data)                                     ((0x00000004&(data))>>2)
#define DC_DISPLAY_ACCESS_cp_kc_shift                                         (1)
#define DC_DISPLAY_ACCESS_cp_kc_mask                                          (0x00000002)
#define DC_DISPLAY_ACCESS_cp_kc(data)                                         (0x00000002&((data)<<1))
#define DC_DISPLAY_ACCESS_cp_kc_src(data)                                     ((0x00000002&(data))>>1)
#define DC_DISPLAY_ACCESS_get_cp_kc(data)                                     ((0x00000002&(data))>>1)
#define DC_DISPLAY_ACCESS_md_vc_shift                                         (0)
#define DC_DISPLAY_ACCESS_md_vc_mask                                          (0x00000001)
#define DC_DISPLAY_ACCESS_md_vc(data)                                         (0x00000001&((data)<<0))
#define DC_DISPLAY_ACCESS_md_vc_src(data)                                     ((0x00000001&(data))>>0)
#define DC_DISPLAY_ACCESS_get_md_vc(data)                                     ((0x00000001&(data))>>0)


#define DC_SECURE_INT_ENABLE                                                  0x180075A0
#define DC_SECURE_INT_ENABLE_reg_addr                                         "0xB80075A0"
#define DC_SECURE_INT_ENABLE_reg                                              0xB80075A0
#define set_DC_SECURE_INT_ENABLE_reg(data)   (*((volatile unsigned int*) DC_SECURE_INT_ENABLE_reg)=data)
#define get_DC_SECURE_INT_ENABLE_reg   (*((volatile unsigned int*) DC_SECURE_INT_ENABLE_reg))
#define DC_SECURE_INT_ENABLE_inst_adr                                         "0x0068"
#define DC_SECURE_INT_ENABLE_inst                                             0x0068
#define DC_SECURE_INT_ENABLE_display_touch_other_en_shift                     (31)
#define DC_SECURE_INT_ENABLE_display_touch_other_en_mask                      (0x80000000)
#define DC_SECURE_INT_ENABLE_display_touch_other_en(data)                     (0x80000000&((data)<<31))
#define DC_SECURE_INT_ENABLE_display_touch_other_en_src(data)                 ((0x80000000&(data))>>31)
#define DC_SECURE_INT_ENABLE_get_display_touch_other_en(data)                 ((0x80000000&(data))>>31)
#define DC_SECURE_INT_ENABLE_display1_touch_en_shift                          (30)
#define DC_SECURE_INT_ENABLE_display1_touch_en_mask                           (0x40000000)
#define DC_SECURE_INT_ENABLE_display1_touch_en(data)                          (0x40000000&((data)<<30))
#define DC_SECURE_INT_ENABLE_display1_touch_en_src(data)                      ((0x40000000&(data))>>30)
#define DC_SECURE_INT_ENABLE_get_display1_touch_en(data)                      ((0x40000000&(data))>>30)
#define DC_SECURE_INT_ENABLE_display0_touch_en_shift                          (29)
#define DC_SECURE_INT_ENABLE_display0_touch_en_mask                           (0x20000000)
#define DC_SECURE_INT_ENABLE_display0_touch_en(data)                          (0x20000000&((data)<<29))
#define DC_SECURE_INT_ENABLE_display0_touch_en_src(data)                      ((0x20000000&(data))>>29)
#define DC_SECURE_INT_ENABLE_get_display0_touch_en(data)                      ((0x20000000&(data))>>29)
#define DC_SECURE_INT_ENABLE_blk_over_max_secure_addr_int_en_shift            (28)
#define DC_SECURE_INT_ENABLE_blk_over_max_secure_addr_int_en_mask             (0x10000000)
#define DC_SECURE_INT_ENABLE_blk_over_max_secure_addr_int_en(data)            (0x10000000&((data)<<28))
#define DC_SECURE_INT_ENABLE_blk_over_max_secure_addr_int_en_src(data)        ((0x10000000&(data))>>28)
#define DC_SECURE_INT_ENABLE_get_blk_over_max_secure_addr_int_en(data)        ((0x10000000&(data))>>28)
#define DC_SECURE_INT_ENABLE_seq_over_max_secure_addr_int_en_shift            (27)
#define DC_SECURE_INT_ENABLE_seq_over_max_secure_addr_int_en_mask             (0x08000000)
#define DC_SECURE_INT_ENABLE_seq_over_max_secure_addr_int_en(data)            (0x08000000&((data)<<27))
#define DC_SECURE_INT_ENABLE_seq_over_max_secure_addr_int_en_src(data)        ((0x08000000&(data))>>27)
#define DC_SECURE_INT_ENABLE_get_seq_over_max_secure_addr_int_en(data)        ((0x08000000&(data))>>27)
#define DC_SECURE_INT_ENABLE_blk_y_overflow_int_en_shift                      (26)
#define DC_SECURE_INT_ENABLE_blk_y_overflow_int_en_mask                       (0x04000000)
#define DC_SECURE_INT_ENABLE_blk_y_overflow_int_en(data)                      (0x04000000&((data)<<26))
#define DC_SECURE_INT_ENABLE_blk_y_overflow_int_en_src(data)                  ((0x04000000&(data))>>26)
#define DC_SECURE_INT_ENABLE_get_blk_y_overflow_int_en(data)                  ((0x04000000&(data))>>26)
#define DC_SECURE_INT_ENABLE_blk_x_overflow_int_en_shift                      (25)
#define DC_SECURE_INT_ENABLE_blk_x_overflow_int_en_mask                       (0x02000000)
#define DC_SECURE_INT_ENABLE_blk_x_overflow_int_en(data)                      (0x02000000&((data)<<25))
#define DC_SECURE_INT_ENABLE_blk_x_overflow_int_en_src(data)                  ((0x02000000&(data))>>25)
#define DC_SECURE_INT_ENABLE_get_blk_x_overflow_int_en(data)                  ((0x02000000&(data))>>25)
#define DC_SECURE_INT_ENABLE_content7_blk_touch_int_en_shift                  (24)
#define DC_SECURE_INT_ENABLE_content7_blk_touch_int_en_mask                   (0x01000000)
#define DC_SECURE_INT_ENABLE_content7_blk_touch_int_en(data)                  (0x01000000&((data)<<24))
#define DC_SECURE_INT_ENABLE_content7_blk_touch_int_en_src(data)              ((0x01000000&(data))>>24)
#define DC_SECURE_INT_ENABLE_get_content7_blk_touch_int_en(data)              ((0x01000000&(data))>>24)
#define DC_SECURE_INT_ENABLE_content7_seq_touch_int_en_shift                  (23)
#define DC_SECURE_INT_ENABLE_content7_seq_touch_int_en_mask                   (0x00800000)
#define DC_SECURE_INT_ENABLE_content7_seq_touch_int_en(data)                  (0x00800000&((data)<<23))
#define DC_SECURE_INT_ENABLE_content7_seq_touch_int_en_src(data)              ((0x00800000&(data))>>23)
#define DC_SECURE_INT_ENABLE_get_content7_seq_touch_int_en(data)              ((0x00800000&(data))>>23)
#define DC_SECURE_INT_ENABLE_content6_blk_touch_int_en_shift                  (22)
#define DC_SECURE_INT_ENABLE_content6_blk_touch_int_en_mask                   (0x00400000)
#define DC_SECURE_INT_ENABLE_content6_blk_touch_int_en(data)                  (0x00400000&((data)<<22))
#define DC_SECURE_INT_ENABLE_content6_blk_touch_int_en_src(data)              ((0x00400000&(data))>>22)
#define DC_SECURE_INT_ENABLE_get_content6_blk_touch_int_en(data)              ((0x00400000&(data))>>22)
#define DC_SECURE_INT_ENABLE_content6_seq_touch_int_en_shift                  (21)
#define DC_SECURE_INT_ENABLE_content6_seq_touch_int_en_mask                   (0x00200000)
#define DC_SECURE_INT_ENABLE_content6_seq_touch_int_en(data)                  (0x00200000&((data)<<21))
#define DC_SECURE_INT_ENABLE_content6_seq_touch_int_en_src(data)              ((0x00200000&(data))>>21)
#define DC_SECURE_INT_ENABLE_get_content6_seq_touch_int_en(data)              ((0x00200000&(data))>>21)
#define DC_SECURE_INT_ENABLE_content5_blk_touch_int_en_shift                  (20)
#define DC_SECURE_INT_ENABLE_content5_blk_touch_int_en_mask                   (0x00100000)
#define DC_SECURE_INT_ENABLE_content5_blk_touch_int_en(data)                  (0x00100000&((data)<<20))
#define DC_SECURE_INT_ENABLE_content5_blk_touch_int_en_src(data)              ((0x00100000&(data))>>20)
#define DC_SECURE_INT_ENABLE_get_content5_blk_touch_int_en(data)              ((0x00100000&(data))>>20)
#define DC_SECURE_INT_ENABLE_content5_seq_touch_int_en_shift                  (19)
#define DC_SECURE_INT_ENABLE_content5_seq_touch_int_en_mask                   (0x00080000)
#define DC_SECURE_INT_ENABLE_content5_seq_touch_int_en(data)                  (0x00080000&((data)<<19))
#define DC_SECURE_INT_ENABLE_content5_seq_touch_int_en_src(data)              ((0x00080000&(data))>>19)
#define DC_SECURE_INT_ENABLE_get_content5_seq_touch_int_en(data)              ((0x00080000&(data))>>19)
#define DC_SECURE_INT_ENABLE_content4_blk_touch_int_en_shift                  (18)
#define DC_SECURE_INT_ENABLE_content4_blk_touch_int_en_mask                   (0x00040000)
#define DC_SECURE_INT_ENABLE_content4_blk_touch_int_en(data)                  (0x00040000&((data)<<18))
#define DC_SECURE_INT_ENABLE_content4_blk_touch_int_en_src(data)              ((0x00040000&(data))>>18)
#define DC_SECURE_INT_ENABLE_get_content4_blk_touch_int_en(data)              ((0x00040000&(data))>>18)
#define DC_SECURE_INT_ENABLE_content4_seq_touch_int_en_shift                  (17)
#define DC_SECURE_INT_ENABLE_content4_seq_touch_int_en_mask                   (0x00020000)
#define DC_SECURE_INT_ENABLE_content4_seq_touch_int_en(data)                  (0x00020000&((data)<<17))
#define DC_SECURE_INT_ENABLE_content4_seq_touch_int_en_src(data)              ((0x00020000&(data))>>17)
#define DC_SECURE_INT_ENABLE_get_content4_seq_touch_int_en(data)              ((0x00020000&(data))>>17)
#define DC_SECURE_INT_ENABLE_content3_blk_touch_int_en_shift                  (16)
#define DC_SECURE_INT_ENABLE_content3_blk_touch_int_en_mask                   (0x00010000)
#define DC_SECURE_INT_ENABLE_content3_blk_touch_int_en(data)                  (0x00010000&((data)<<16))
#define DC_SECURE_INT_ENABLE_content3_blk_touch_int_en_src(data)              ((0x00010000&(data))>>16)
#define DC_SECURE_INT_ENABLE_get_content3_blk_touch_int_en(data)              ((0x00010000&(data))>>16)
#define DC_SECURE_INT_ENABLE_content3_seq_touch_int_en_shift                  (15)
#define DC_SECURE_INT_ENABLE_content3_seq_touch_int_en_mask                   (0x00008000)
#define DC_SECURE_INT_ENABLE_content3_seq_touch_int_en(data)                  (0x00008000&((data)<<15))
#define DC_SECURE_INT_ENABLE_content3_seq_touch_int_en_src(data)              ((0x00008000&(data))>>15)
#define DC_SECURE_INT_ENABLE_get_content3_seq_touch_int_en(data)              ((0x00008000&(data))>>15)
#define DC_SECURE_INT_ENABLE_content2_blk_touch_int_en_shift                  (14)
#define DC_SECURE_INT_ENABLE_content2_blk_touch_int_en_mask                   (0x00004000)
#define DC_SECURE_INT_ENABLE_content2_blk_touch_int_en(data)                  (0x00004000&((data)<<14))
#define DC_SECURE_INT_ENABLE_content2_blk_touch_int_en_src(data)              ((0x00004000&(data))>>14)
#define DC_SECURE_INT_ENABLE_get_content2_blk_touch_int_en(data)              ((0x00004000&(data))>>14)
#define DC_SECURE_INT_ENABLE_content2_seq_touch_int_en_shift                  (13)
#define DC_SECURE_INT_ENABLE_content2_seq_touch_int_en_mask                   (0x00002000)
#define DC_SECURE_INT_ENABLE_content2_seq_touch_int_en(data)                  (0x00002000&((data)<<13))
#define DC_SECURE_INT_ENABLE_content2_seq_touch_int_en_src(data)              ((0x00002000&(data))>>13)
#define DC_SECURE_INT_ENABLE_get_content2_seq_touch_int_en(data)              ((0x00002000&(data))>>13)
#define DC_SECURE_INT_ENABLE_content1_blk_touch_int_en_shift                  (12)
#define DC_SECURE_INT_ENABLE_content1_blk_touch_int_en_mask                   (0x00001000)
#define DC_SECURE_INT_ENABLE_content1_blk_touch_int_en(data)                  (0x00001000&((data)<<12))
#define DC_SECURE_INT_ENABLE_content1_blk_touch_int_en_src(data)              ((0x00001000&(data))>>12)
#define DC_SECURE_INT_ENABLE_get_content1_blk_touch_int_en(data)              ((0x00001000&(data))>>12)
#define DC_SECURE_INT_ENABLE_content1_seq_touch_int_en_shift                  (11)
#define DC_SECURE_INT_ENABLE_content1_seq_touch_int_en_mask                   (0x00000800)
#define DC_SECURE_INT_ENABLE_content1_seq_touch_int_en(data)                  (0x00000800&((data)<<11))
#define DC_SECURE_INT_ENABLE_content1_seq_touch_int_en_src(data)              ((0x00000800&(data))>>11)
#define DC_SECURE_INT_ENABLE_get_content1_seq_touch_int_en(data)              ((0x00000800&(data))>>11)
#define DC_SECURE_INT_ENABLE_content0_blk_touch_int_en_shift                  (10)
#define DC_SECURE_INT_ENABLE_content0_blk_touch_int_en_mask                   (0x00000400)
#define DC_SECURE_INT_ENABLE_content0_blk_touch_int_en(data)                  (0x00000400&((data)<<10))
#define DC_SECURE_INT_ENABLE_content0_blk_touch_int_en_src(data)              ((0x00000400&(data))>>10)
#define DC_SECURE_INT_ENABLE_get_content0_blk_touch_int_en(data)              ((0x00000400&(data))>>10)
#define DC_SECURE_INT_ENABLE_content0_seq_touch_int_en_shift                  (9)
#define DC_SECURE_INT_ENABLE_content0_seq_touch_int_en_mask                   (0x00000200)
#define DC_SECURE_INT_ENABLE_content0_seq_touch_int_en(data)                  (0x00000200&((data)<<9))
#define DC_SECURE_INT_ENABLE_content0_seq_touch_int_en_src(data)              ((0x00000200&(data))>>9)
#define DC_SECURE_INT_ENABLE_get_content0_seq_touch_int_en(data)              ((0x00000200&(data))>>9)
#define DC_SECURE_INT_ENABLE_protect3_blk_picset_touch_int_en_shift           (8)
#define DC_SECURE_INT_ENABLE_protect3_blk_picset_touch_int_en_mask            (0x00000100)
#define DC_SECURE_INT_ENABLE_protect3_blk_picset_touch_int_en(data)           (0x00000100&((data)<<8))
#define DC_SECURE_INT_ENABLE_protect3_blk_picset_touch_int_en_src(data)       ((0x00000100&(data))>>8)
#define DC_SECURE_INT_ENABLE_get_protect3_blk_picset_touch_int_en(data)       ((0x00000100&(data))>>8)
#define DC_SECURE_INT_ENABLE_protect3_seq_touch_int_en_shift                  (7)
#define DC_SECURE_INT_ENABLE_protect3_seq_touch_int_en_mask                   (0x00000080)
#define DC_SECURE_INT_ENABLE_protect3_seq_touch_int_en(data)                  (0x00000080&((data)<<7))
#define DC_SECURE_INT_ENABLE_protect3_seq_touch_int_en_src(data)              ((0x00000080&(data))>>7)
#define DC_SECURE_INT_ENABLE_get_protect3_seq_touch_int_en(data)              ((0x00000080&(data))>>7)
#define DC_SECURE_INT_ENABLE_protect2_blk_picset_touch_int_en_shift           (6)
#define DC_SECURE_INT_ENABLE_protect2_blk_picset_touch_int_en_mask            (0x00000040)
#define DC_SECURE_INT_ENABLE_protect2_blk_picset_touch_int_en(data)           (0x00000040&((data)<<6))
#define DC_SECURE_INT_ENABLE_protect2_blk_picset_touch_int_en_src(data)       ((0x00000040&(data))>>6)
#define DC_SECURE_INT_ENABLE_get_protect2_blk_picset_touch_int_en(data)       ((0x00000040&(data))>>6)
#define DC_SECURE_INT_ENABLE_protect2_seq_touch_int_en_shift                  (5)
#define DC_SECURE_INT_ENABLE_protect2_seq_touch_int_en_mask                   (0x00000020)
#define DC_SECURE_INT_ENABLE_protect2_seq_touch_int_en(data)                  (0x00000020&((data)<<5))
#define DC_SECURE_INT_ENABLE_protect2_seq_touch_int_en_src(data)              ((0x00000020&(data))>>5)
#define DC_SECURE_INT_ENABLE_get_protect2_seq_touch_int_en(data)              ((0x00000020&(data))>>5)
#define DC_SECURE_INT_ENABLE_protect1_blk_picset_touch_int_en_shift           (4)
#define DC_SECURE_INT_ENABLE_protect1_blk_picset_touch_int_en_mask            (0x00000010)
#define DC_SECURE_INT_ENABLE_protect1_blk_picset_touch_int_en(data)           (0x00000010&((data)<<4))
#define DC_SECURE_INT_ENABLE_protect1_blk_picset_touch_int_en_src(data)       ((0x00000010&(data))>>4)
#define DC_SECURE_INT_ENABLE_get_protect1_blk_picset_touch_int_en(data)       ((0x00000010&(data))>>4)
#define DC_SECURE_INT_ENABLE_protect1_seq_touch_int_en_shift                  (3)
#define DC_SECURE_INT_ENABLE_protect1_seq_touch_int_en_mask                   (0x00000008)
#define DC_SECURE_INT_ENABLE_protect1_seq_touch_int_en(data)                  (0x00000008&((data)<<3))
#define DC_SECURE_INT_ENABLE_protect1_seq_touch_int_en_src(data)              ((0x00000008&(data))>>3)
#define DC_SECURE_INT_ENABLE_get_protect1_seq_touch_int_en(data)              ((0x00000008&(data))>>3)
#define DC_SECURE_INT_ENABLE_protect0_blk_picset_touch_int_en_shift           (2)
#define DC_SECURE_INT_ENABLE_protect0_blk_picset_touch_int_en_mask            (0x00000004)
#define DC_SECURE_INT_ENABLE_protect0_blk_picset_touch_int_en(data)           (0x00000004&((data)<<2))
#define DC_SECURE_INT_ENABLE_protect0_blk_picset_touch_int_en_src(data)       ((0x00000004&(data))>>2)
#define DC_SECURE_INT_ENABLE_get_protect0_blk_picset_touch_int_en(data)       ((0x00000004&(data))>>2)
#define DC_SECURE_INT_ENABLE_protect0_seq_touch_int_en_shift                  (1)
#define DC_SECURE_INT_ENABLE_protect0_seq_touch_int_en_mask                   (0x00000002)
#define DC_SECURE_INT_ENABLE_protect0_seq_touch_int_en(data)                  (0x00000002&((data)<<1))
#define DC_SECURE_INT_ENABLE_protect0_seq_touch_int_en_src(data)              ((0x00000002&(data))>>1)
#define DC_SECURE_INT_ENABLE_get_protect0_seq_touch_int_en(data)              ((0x00000002&(data))>>1)
#define DC_SECURE_INT_ENABLE_write_data_shift                                 (0)
#define DC_SECURE_INT_ENABLE_write_data_mask                                  (0x00000001)
#define DC_SECURE_INT_ENABLE_write_data(data)                                 (0x00000001&((data)<<0))
#define DC_SECURE_INT_ENABLE_write_data_src(data)                             ((0x00000001&(data))>>0)
#define DC_SECURE_INT_ENABLE_get_write_data(data)                             ((0x00000001&(data))>>0)


#define DC_SECURE_INT_STATUS                                                  0x180075A4
#define DC_SECURE_INT_STATUS_reg_addr                                         "0xB80075A4"
#define DC_SECURE_INT_STATUS_reg                                              0xB80075A4
#define set_DC_SECURE_INT_STATUS_reg(data)   (*((volatile unsigned int*) DC_SECURE_INT_STATUS_reg)=data)
#define get_DC_SECURE_INT_STATUS_reg   (*((volatile unsigned int*) DC_SECURE_INT_STATUS_reg))
#define DC_SECURE_INT_STATUS_inst_adr                                         "0x0069"
#define DC_SECURE_INT_STATUS_inst                                             0x0069
#define DC_SECURE_INT_STATUS_display_touch_other_int_shift                    (31)
#define DC_SECURE_INT_STATUS_display_touch_other_int_mask                     (0x80000000)
#define DC_SECURE_INT_STATUS_display_touch_other_int(data)                    (0x80000000&((data)<<31))
#define DC_SECURE_INT_STATUS_display_touch_other_int_src(data)                ((0x80000000&(data))>>31)
#define DC_SECURE_INT_STATUS_get_display_touch_other_int(data)                ((0x80000000&(data))>>31)
#define DC_SECURE_INT_STATUS_display1_touch_int_shift                         (30)
#define DC_SECURE_INT_STATUS_display1_touch_int_mask                          (0x40000000)
#define DC_SECURE_INT_STATUS_display1_touch_int(data)                         (0x40000000&((data)<<30))
#define DC_SECURE_INT_STATUS_display1_touch_int_src(data)                     ((0x40000000&(data))>>30)
#define DC_SECURE_INT_STATUS_get_display1_touch_int(data)                     ((0x40000000&(data))>>30)
#define DC_SECURE_INT_STATUS_display0_touch_int_shift                         (29)
#define DC_SECURE_INT_STATUS_display0_touch_int_mask                          (0x20000000)
#define DC_SECURE_INT_STATUS_display0_touch_int(data)                         (0x20000000&((data)<<29))
#define DC_SECURE_INT_STATUS_display0_touch_int_src(data)                     ((0x20000000&(data))>>29)
#define DC_SECURE_INT_STATUS_get_display0_touch_int(data)                     ((0x20000000&(data))>>29)
#define DC_SECURE_INT_STATUS_blk_over_max_secure_addr_int_shift               (28)
#define DC_SECURE_INT_STATUS_blk_over_max_secure_addr_int_mask                (0x10000000)
#define DC_SECURE_INT_STATUS_blk_over_max_secure_addr_int(data)               (0x10000000&((data)<<28))
#define DC_SECURE_INT_STATUS_blk_over_max_secure_addr_int_src(data)           ((0x10000000&(data))>>28)
#define DC_SECURE_INT_STATUS_get_blk_over_max_secure_addr_int(data)           ((0x10000000&(data))>>28)
#define DC_SECURE_INT_STATUS_seq_over_max_secure_addr_int_shift               (27)
#define DC_SECURE_INT_STATUS_seq_over_max_secure_addr_int_mask                (0x08000000)
#define DC_SECURE_INT_STATUS_seq_over_max_secure_addr_int(data)               (0x08000000&((data)<<27))
#define DC_SECURE_INT_STATUS_seq_over_max_secure_addr_int_src(data)           ((0x08000000&(data))>>27)
#define DC_SECURE_INT_STATUS_get_seq_over_max_secure_addr_int(data)           ((0x08000000&(data))>>27)
#define DC_SECURE_INT_STATUS_blk_y_overflow_int_shift                         (26)
#define DC_SECURE_INT_STATUS_blk_y_overflow_int_mask                          (0x04000000)
#define DC_SECURE_INT_STATUS_blk_y_overflow_int(data)                         (0x04000000&((data)<<26))
#define DC_SECURE_INT_STATUS_blk_y_overflow_int_src(data)                     ((0x04000000&(data))>>26)
#define DC_SECURE_INT_STATUS_get_blk_y_overflow_int(data)                     ((0x04000000&(data))>>26)
#define DC_SECURE_INT_STATUS_blk_x_overflow_int_shift                         (25)
#define DC_SECURE_INT_STATUS_blk_x_overflow_int_mask                          (0x02000000)
#define DC_SECURE_INT_STATUS_blk_x_overflow_int(data)                         (0x02000000&((data)<<25))
#define DC_SECURE_INT_STATUS_blk_x_overflow_int_src(data)                     ((0x02000000&(data))>>25)
#define DC_SECURE_INT_STATUS_get_blk_x_overflow_int(data)                     ((0x02000000&(data))>>25)
#define DC_SECURE_INT_STATUS_content7_blk_touch_int_shift                     (24)
#define DC_SECURE_INT_STATUS_content7_blk_touch_int_mask                      (0x01000000)
#define DC_SECURE_INT_STATUS_content7_blk_touch_int(data)                     (0x01000000&((data)<<24))
#define DC_SECURE_INT_STATUS_content7_blk_touch_int_src(data)                 ((0x01000000&(data))>>24)
#define DC_SECURE_INT_STATUS_get_content7_blk_touch_int(data)                 ((0x01000000&(data))>>24)
#define DC_SECURE_INT_STATUS_content7_seq_touch_int_shift                     (23)
#define DC_SECURE_INT_STATUS_content7_seq_touch_int_mask                      (0x00800000)
#define DC_SECURE_INT_STATUS_content7_seq_touch_int(data)                     (0x00800000&((data)<<23))
#define DC_SECURE_INT_STATUS_content7_seq_touch_int_src(data)                 ((0x00800000&(data))>>23)
#define DC_SECURE_INT_STATUS_get_content7_seq_touch_int(data)                 ((0x00800000&(data))>>23)
#define DC_SECURE_INT_STATUS_content6_blk_touch_int_shift                     (22)
#define DC_SECURE_INT_STATUS_content6_blk_touch_int_mask                      (0x00400000)
#define DC_SECURE_INT_STATUS_content6_blk_touch_int(data)                     (0x00400000&((data)<<22))
#define DC_SECURE_INT_STATUS_content6_blk_touch_int_src(data)                 ((0x00400000&(data))>>22)
#define DC_SECURE_INT_STATUS_get_content6_blk_touch_int(data)                 ((0x00400000&(data))>>22)
#define DC_SECURE_INT_STATUS_content6_seq_touch_int_shift                     (21)
#define DC_SECURE_INT_STATUS_content6_seq_touch_int_mask                      (0x00200000)
#define DC_SECURE_INT_STATUS_content6_seq_touch_int(data)                     (0x00200000&((data)<<21))
#define DC_SECURE_INT_STATUS_content6_seq_touch_int_src(data)                 ((0x00200000&(data))>>21)
#define DC_SECURE_INT_STATUS_get_content6_seq_touch_int(data)                 ((0x00200000&(data))>>21)
#define DC_SECURE_INT_STATUS_content5_blk_touch_int_shift                     (20)
#define DC_SECURE_INT_STATUS_content5_blk_touch_int_mask                      (0x00100000)
#define DC_SECURE_INT_STATUS_content5_blk_touch_int(data)                     (0x00100000&((data)<<20))
#define DC_SECURE_INT_STATUS_content5_blk_touch_int_src(data)                 ((0x00100000&(data))>>20)
#define DC_SECURE_INT_STATUS_get_content5_blk_touch_int(data)                 ((0x00100000&(data))>>20)
#define DC_SECURE_INT_STATUS_content5_seq_touch_int_shift                     (19)
#define DC_SECURE_INT_STATUS_content5_seq_touch_int_mask                      (0x00080000)
#define DC_SECURE_INT_STATUS_content5_seq_touch_int(data)                     (0x00080000&((data)<<19))
#define DC_SECURE_INT_STATUS_content5_seq_touch_int_src(data)                 ((0x00080000&(data))>>19)
#define DC_SECURE_INT_STATUS_get_content5_seq_touch_int(data)                 ((0x00080000&(data))>>19)
#define DC_SECURE_INT_STATUS_content4_blk_touch_int_shift                     (18)
#define DC_SECURE_INT_STATUS_content4_blk_touch_int_mask                      (0x00040000)
#define DC_SECURE_INT_STATUS_content4_blk_touch_int(data)                     (0x00040000&((data)<<18))
#define DC_SECURE_INT_STATUS_content4_blk_touch_int_src(data)                 ((0x00040000&(data))>>18)
#define DC_SECURE_INT_STATUS_get_content4_blk_touch_int(data)                 ((0x00040000&(data))>>18)
#define DC_SECURE_INT_STATUS_content4_seq_touch_int_shift                     (17)
#define DC_SECURE_INT_STATUS_content4_seq_touch_int_mask                      (0x00020000)
#define DC_SECURE_INT_STATUS_content4_seq_touch_int(data)                     (0x00020000&((data)<<17))
#define DC_SECURE_INT_STATUS_content4_seq_touch_int_src(data)                 ((0x00020000&(data))>>17)
#define DC_SECURE_INT_STATUS_get_content4_seq_touch_int(data)                 ((0x00020000&(data))>>17)
#define DC_SECURE_INT_STATUS_content3_blk_touch_int_shift                     (16)
#define DC_SECURE_INT_STATUS_content3_blk_touch_int_mask                      (0x00010000)
#define DC_SECURE_INT_STATUS_content3_blk_touch_int(data)                     (0x00010000&((data)<<16))
#define DC_SECURE_INT_STATUS_content3_blk_touch_int_src(data)                 ((0x00010000&(data))>>16)
#define DC_SECURE_INT_STATUS_get_content3_blk_touch_int(data)                 ((0x00010000&(data))>>16)
#define DC_SECURE_INT_STATUS_content3_seq_touch_int_shift                     (15)
#define DC_SECURE_INT_STATUS_content3_seq_touch_int_mask                      (0x00008000)
#define DC_SECURE_INT_STATUS_content3_seq_touch_int(data)                     (0x00008000&((data)<<15))
#define DC_SECURE_INT_STATUS_content3_seq_touch_int_src(data)                 ((0x00008000&(data))>>15)
#define DC_SECURE_INT_STATUS_get_content3_seq_touch_int(data)                 ((0x00008000&(data))>>15)
#define DC_SECURE_INT_STATUS_content2_blk_touch_int_shift                     (14)
#define DC_SECURE_INT_STATUS_content2_blk_touch_int_mask                      (0x00004000)
#define DC_SECURE_INT_STATUS_content2_blk_touch_int(data)                     (0x00004000&((data)<<14))
#define DC_SECURE_INT_STATUS_content2_blk_touch_int_src(data)                 ((0x00004000&(data))>>14)
#define DC_SECURE_INT_STATUS_get_content2_blk_touch_int(data)                 ((0x00004000&(data))>>14)
#define DC_SECURE_INT_STATUS_content2_seq_touch_int_shift                     (13)
#define DC_SECURE_INT_STATUS_content2_seq_touch_int_mask                      (0x00002000)
#define DC_SECURE_INT_STATUS_content2_seq_touch_int(data)                     (0x00002000&((data)<<13))
#define DC_SECURE_INT_STATUS_content2_seq_touch_int_src(data)                 ((0x00002000&(data))>>13)
#define DC_SECURE_INT_STATUS_get_content2_seq_touch_int(data)                 ((0x00002000&(data))>>13)
#define DC_SECURE_INT_STATUS_content1_blk_touch_int_shift                     (12)
#define DC_SECURE_INT_STATUS_content1_blk_touch_int_mask                      (0x00001000)
#define DC_SECURE_INT_STATUS_content1_blk_touch_int(data)                     (0x00001000&((data)<<12))
#define DC_SECURE_INT_STATUS_content1_blk_touch_int_src(data)                 ((0x00001000&(data))>>12)
#define DC_SECURE_INT_STATUS_get_content1_blk_touch_int(data)                 ((0x00001000&(data))>>12)
#define DC_SECURE_INT_STATUS_content1_seq_touch_int_shift                     (11)
#define DC_SECURE_INT_STATUS_content1_seq_touch_int_mask                      (0x00000800)
#define DC_SECURE_INT_STATUS_content1_seq_touch_int(data)                     (0x00000800&((data)<<11))
#define DC_SECURE_INT_STATUS_content1_seq_touch_int_src(data)                 ((0x00000800&(data))>>11)
#define DC_SECURE_INT_STATUS_get_content1_seq_touch_int(data)                 ((0x00000800&(data))>>11)
#define DC_SECURE_INT_STATUS_content0_blk_touch_int_shift                     (10)
#define DC_SECURE_INT_STATUS_content0_blk_touch_int_mask                      (0x00000400)
#define DC_SECURE_INT_STATUS_content0_blk_touch_int(data)                     (0x00000400&((data)<<10))
#define DC_SECURE_INT_STATUS_content0_blk_touch_int_src(data)                 ((0x00000400&(data))>>10)
#define DC_SECURE_INT_STATUS_get_content0_blk_touch_int(data)                 ((0x00000400&(data))>>10)
#define DC_SECURE_INT_STATUS_content0_seq_touch_int_shift                     (9)
#define DC_SECURE_INT_STATUS_content0_seq_touch_int_mask                      (0x00000200)
#define DC_SECURE_INT_STATUS_content0_seq_touch_int(data)                     (0x00000200&((data)<<9))
#define DC_SECURE_INT_STATUS_content0_seq_touch_int_src(data)                 ((0x00000200&(data))>>9)
#define DC_SECURE_INT_STATUS_get_content0_seq_touch_int(data)                 ((0x00000200&(data))>>9)
#define DC_SECURE_INT_STATUS_protect3_blk_picset_touch_int_shift              (8)
#define DC_SECURE_INT_STATUS_protect3_blk_picset_touch_int_mask               (0x00000100)
#define DC_SECURE_INT_STATUS_protect3_blk_picset_touch_int(data)              (0x00000100&((data)<<8))
#define DC_SECURE_INT_STATUS_protect3_blk_picset_touch_int_src(data)          ((0x00000100&(data))>>8)
#define DC_SECURE_INT_STATUS_get_protect3_blk_picset_touch_int(data)          ((0x00000100&(data))>>8)
#define DC_SECURE_INT_STATUS_protect3_seq_touch_int_shift                     (7)
#define DC_SECURE_INT_STATUS_protect3_seq_touch_int_mask                      (0x00000080)
#define DC_SECURE_INT_STATUS_protect3_seq_touch_int(data)                     (0x00000080&((data)<<7))
#define DC_SECURE_INT_STATUS_protect3_seq_touch_int_src(data)                 ((0x00000080&(data))>>7)
#define DC_SECURE_INT_STATUS_get_protect3_seq_touch_int(data)                 ((0x00000080&(data))>>7)
#define DC_SECURE_INT_STATUS_protect2_blk_picset_touch_int_shift              (6)
#define DC_SECURE_INT_STATUS_protect2_blk_picset_touch_int_mask               (0x00000040)
#define DC_SECURE_INT_STATUS_protect2_blk_picset_touch_int(data)              (0x00000040&((data)<<6))
#define DC_SECURE_INT_STATUS_protect2_blk_picset_touch_int_src(data)          ((0x00000040&(data))>>6)
#define DC_SECURE_INT_STATUS_get_protect2_blk_picset_touch_int(data)          ((0x00000040&(data))>>6)
#define DC_SECURE_INT_STATUS_protect2_seq_touch_int_shift                     (5)
#define DC_SECURE_INT_STATUS_protect2_seq_touch_int_mask                      (0x00000020)
#define DC_SECURE_INT_STATUS_protect2_seq_touch_int(data)                     (0x00000020&((data)<<5))
#define DC_SECURE_INT_STATUS_protect2_seq_touch_int_src(data)                 ((0x00000020&(data))>>5)
#define DC_SECURE_INT_STATUS_get_protect2_seq_touch_int(data)                 ((0x00000020&(data))>>5)
#define DC_SECURE_INT_STATUS_protect1_blk_picset_touch_int_shift              (4)
#define DC_SECURE_INT_STATUS_protect1_blk_picset_touch_int_mask               (0x00000010)
#define DC_SECURE_INT_STATUS_protect1_blk_picset_touch_int(data)              (0x00000010&((data)<<4))
#define DC_SECURE_INT_STATUS_protect1_blk_picset_touch_int_src(data)          ((0x00000010&(data))>>4)
#define DC_SECURE_INT_STATUS_get_protect1_blk_picset_touch_int(data)          ((0x00000010&(data))>>4)
#define DC_SECURE_INT_STATUS_protect1_seq_touch_int_shift                     (3)
#define DC_SECURE_INT_STATUS_protect1_seq_touch_int_mask                      (0x00000008)
#define DC_SECURE_INT_STATUS_protect1_seq_touch_int(data)                     (0x00000008&((data)<<3))
#define DC_SECURE_INT_STATUS_protect1_seq_touch_int_src(data)                 ((0x00000008&(data))>>3)
#define DC_SECURE_INT_STATUS_get_protect1_seq_touch_int(data)                 ((0x00000008&(data))>>3)
#define DC_SECURE_INT_STATUS_protect0_blk_picset_touch_int_shift              (2)
#define DC_SECURE_INT_STATUS_protect0_blk_picset_touch_int_mask               (0x00000004)
#define DC_SECURE_INT_STATUS_protect0_blk_picset_touch_int(data)              (0x00000004&((data)<<2))
#define DC_SECURE_INT_STATUS_protect0_blk_picset_touch_int_src(data)          ((0x00000004&(data))>>2)
#define DC_SECURE_INT_STATUS_get_protect0_blk_picset_touch_int(data)          ((0x00000004&(data))>>2)
#define DC_SECURE_INT_STATUS_protect0_seq_touch_int_shift                     (1)
#define DC_SECURE_INT_STATUS_protect0_seq_touch_int_mask                      (0x00000002)
#define DC_SECURE_INT_STATUS_protect0_seq_touch_int(data)                     (0x00000002&((data)<<1))
#define DC_SECURE_INT_STATUS_protect0_seq_touch_int_src(data)                 ((0x00000002&(data))>>1)
#define DC_SECURE_INT_STATUS_get_protect0_seq_touch_int(data)                 ((0x00000002&(data))>>1)
#define DC_SECURE_INT_STATUS_write_data_shift                                 (0)
#define DC_SECURE_INT_STATUS_write_data_mask                                  (0x00000001)
#define DC_SECURE_INT_STATUS_write_data(data)                                 (0x00000001&((data)<<0))
#define DC_SECURE_INT_STATUS_write_data_src(data)                             ((0x00000001&(data))>>0)
#define DC_SECURE_INT_STATUS_get_write_data(data)                             ((0x00000001&(data))>>0)


#define DC_SECURE_ERROR_INFO                                                  0x180075A8
#define DC_SECURE_ERROR_INFO_reg_addr                                         "0xB80075A8"
#define DC_SECURE_ERROR_INFO_reg                                              0xB80075A8
#define set_DC_SECURE_ERROR_INFO_reg(data)   (*((volatile unsigned int*) DC_SECURE_ERROR_INFO_reg)=data)
#define get_DC_SECURE_ERROR_INFO_reg   (*((volatile unsigned int*) DC_SECURE_ERROR_INFO_reg))
#define DC_SECURE_ERROR_INFO_inst_adr                                         "0x006A"
#define DC_SECURE_ERROR_INFO_inst                                             0x006A
#define DC_SECURE_ERROR_INFO_blk_error_pic_index_shift                        (16)
#define DC_SECURE_ERROR_INFO_blk_error_pic_index_mask                         (0x007F0000)
#define DC_SECURE_ERROR_INFO_blk_error_pic_index(data)                        (0x007F0000&((data)<<16))
#define DC_SECURE_ERROR_INFO_blk_error_pic_index_src(data)                    ((0x007F0000&(data))>>16)
#define DC_SECURE_ERROR_INFO_get_blk_error_pic_index(data)                    ((0x007F0000&(data))>>16)
#define DC_SECURE_ERROR_INFO_seq_read_error_id_shift                          (8)
#define DC_SECURE_ERROR_INFO_seq_read_error_id_mask                           (0x00007F00)
#define DC_SECURE_ERROR_INFO_seq_read_error_id(data)                          (0x00007F00&((data)<<8))
#define DC_SECURE_ERROR_INFO_seq_read_error_id_src(data)                      ((0x00007F00&(data))>>8)
#define DC_SECURE_ERROR_INFO_get_seq_read_error_id(data)                      ((0x00007F00&(data))>>8)
#define DC_SECURE_ERROR_INFO_seq_write_error_id_shift                         (0)
#define DC_SECURE_ERROR_INFO_seq_write_error_id_mask                          (0x0000007F)
#define DC_SECURE_ERROR_INFO_seq_write_error_id(data)                         (0x0000007F&((data)<<0))
#define DC_SECURE_ERROR_INFO_seq_write_error_id_src(data)                     ((0x0000007F&(data))>>0)
#define DC_SECURE_ERROR_INFO_get_seq_write_error_id(data)                     ((0x0000007F&(data))>>0)


#define DC_SECURE_KEY_INT_ENABLE                                              0x180075AC
#define DC_SECURE_KEY_INT_ENABLE_reg_addr                                     "0xB80075AC"
#define DC_SECURE_KEY_INT_ENABLE_reg                                          0xB80075AC
#define set_DC_SECURE_KEY_INT_ENABLE_reg(data)   (*((volatile unsigned int*) DC_SECURE_KEY_INT_ENABLE_reg)=data)
#define get_DC_SECURE_KEY_INT_ENABLE_reg   (*((volatile unsigned int*) DC_SECURE_KEY_INT_ENABLE_reg))
#define DC_SECURE_KEY_INT_ENABLE_inst_adr                                     "0x006B"
#define DC_SECURE_KEY_INT_ENABLE_inst                                         0x006B
#define DC_SECURE_KEY_INT_ENABLE_content7_key_updated_int_en_shift            (8)
#define DC_SECURE_KEY_INT_ENABLE_content7_key_updated_int_en_mask             (0x00000100)
#define DC_SECURE_KEY_INT_ENABLE_content7_key_updated_int_en(data)            (0x00000100&((data)<<8))
#define DC_SECURE_KEY_INT_ENABLE_content7_key_updated_int_en_src(data)        ((0x00000100&(data))>>8)
#define DC_SECURE_KEY_INT_ENABLE_get_content7_key_updated_int_en(data)        ((0x00000100&(data))>>8)
#define DC_SECURE_KEY_INT_ENABLE_content6_key_updated_int_en_shift            (7)
#define DC_SECURE_KEY_INT_ENABLE_content6_key_updated_int_en_mask             (0x00000080)
#define DC_SECURE_KEY_INT_ENABLE_content6_key_updated_int_en(data)            (0x00000080&((data)<<7))
#define DC_SECURE_KEY_INT_ENABLE_content6_key_updated_int_en_src(data)        ((0x00000080&(data))>>7)
#define DC_SECURE_KEY_INT_ENABLE_get_content6_key_updated_int_en(data)        ((0x00000080&(data))>>7)
#define DC_SECURE_KEY_INT_ENABLE_content5_key_updated_int_en_shift            (6)
#define DC_SECURE_KEY_INT_ENABLE_content5_key_updated_int_en_mask             (0x00000040)
#define DC_SECURE_KEY_INT_ENABLE_content5_key_updated_int_en(data)            (0x00000040&((data)<<6))
#define DC_SECURE_KEY_INT_ENABLE_content5_key_updated_int_en_src(data)        ((0x00000040&(data))>>6)
#define DC_SECURE_KEY_INT_ENABLE_get_content5_key_updated_int_en(data)        ((0x00000040&(data))>>6)
#define DC_SECURE_KEY_INT_ENABLE_content4_key_updated_int_en_shift            (5)
#define DC_SECURE_KEY_INT_ENABLE_content4_key_updated_int_en_mask             (0x00000020)
#define DC_SECURE_KEY_INT_ENABLE_content4_key_updated_int_en(data)            (0x00000020&((data)<<5))
#define DC_SECURE_KEY_INT_ENABLE_content4_key_updated_int_en_src(data)        ((0x00000020&(data))>>5)
#define DC_SECURE_KEY_INT_ENABLE_get_content4_key_updated_int_en(data)        ((0x00000020&(data))>>5)
#define DC_SECURE_KEY_INT_ENABLE_content3_key_updated_int_en_shift            (4)
#define DC_SECURE_KEY_INT_ENABLE_content3_key_updated_int_en_mask             (0x00000010)
#define DC_SECURE_KEY_INT_ENABLE_content3_key_updated_int_en(data)            (0x00000010&((data)<<4))
#define DC_SECURE_KEY_INT_ENABLE_content3_key_updated_int_en_src(data)        ((0x00000010&(data))>>4)
#define DC_SECURE_KEY_INT_ENABLE_get_content3_key_updated_int_en(data)        ((0x00000010&(data))>>4)
#define DC_SECURE_KEY_INT_ENABLE_content2_key_updated_int_en_shift            (3)
#define DC_SECURE_KEY_INT_ENABLE_content2_key_updated_int_en_mask             (0x00000008)
#define DC_SECURE_KEY_INT_ENABLE_content2_key_updated_int_en(data)            (0x00000008&((data)<<3))
#define DC_SECURE_KEY_INT_ENABLE_content2_key_updated_int_en_src(data)        ((0x00000008&(data))>>3)
#define DC_SECURE_KEY_INT_ENABLE_get_content2_key_updated_int_en(data)        ((0x00000008&(data))>>3)
#define DC_SECURE_KEY_INT_ENABLE_content1_key_updated_int_en_shift            (2)
#define DC_SECURE_KEY_INT_ENABLE_content1_key_updated_int_en_mask             (0x00000004)
#define DC_SECURE_KEY_INT_ENABLE_content1_key_updated_int_en(data)            (0x00000004&((data)<<2))
#define DC_SECURE_KEY_INT_ENABLE_content1_key_updated_int_en_src(data)        ((0x00000004&(data))>>2)
#define DC_SECURE_KEY_INT_ENABLE_get_content1_key_updated_int_en(data)        ((0x00000004&(data))>>2)
#define DC_SECURE_KEY_INT_ENABLE_content0_key_updated_int_en_shift            (1)
#define DC_SECURE_KEY_INT_ENABLE_content0_key_updated_int_en_mask             (0x00000002)
#define DC_SECURE_KEY_INT_ENABLE_content0_key_updated_int_en(data)            (0x00000002&((data)<<1))
#define DC_SECURE_KEY_INT_ENABLE_content0_key_updated_int_en_src(data)        ((0x00000002&(data))>>1)
#define DC_SECURE_KEY_INT_ENABLE_get_content0_key_updated_int_en(data)        ((0x00000002&(data))>>1)
#define DC_SECURE_KEY_INT_ENABLE_write_data_shift                             (0)
#define DC_SECURE_KEY_INT_ENABLE_write_data_mask                              (0x00000001)
#define DC_SECURE_KEY_INT_ENABLE_write_data(data)                             (0x00000001&((data)<<0))
#define DC_SECURE_KEY_INT_ENABLE_write_data_src(data)                         ((0x00000001&(data))>>0)
#define DC_SECURE_KEY_INT_ENABLE_get_write_data(data)                         ((0x00000001&(data))>>0)


#define DC_SECURE_KEY_INT_STATUS                                              0x180075B0
#define DC_SECURE_KEY_INT_STATUS_reg_addr                                     "0xB80075B0"
#define DC_SECURE_KEY_INT_STATUS_reg                                          0xB80075B0
#define set_DC_SECURE_KEY_INT_STATUS_reg(data)   (*((volatile unsigned int*) DC_SECURE_KEY_INT_STATUS_reg)=data)
#define get_DC_SECURE_KEY_INT_STATUS_reg   (*((volatile unsigned int*) DC_SECURE_KEY_INT_STATUS_reg))
#define DC_SECURE_KEY_INT_STATUS_inst_adr                                     "0x006C"
#define DC_SECURE_KEY_INT_STATUS_inst                                         0x006C
#define DC_SECURE_KEY_INT_STATUS_content7_key_updated_int_shift               (8)
#define DC_SECURE_KEY_INT_STATUS_content7_key_updated_int_mask                (0x00000100)
#define DC_SECURE_KEY_INT_STATUS_content7_key_updated_int(data)               (0x00000100&((data)<<8))
#define DC_SECURE_KEY_INT_STATUS_content7_key_updated_int_src(data)           ((0x00000100&(data))>>8)
#define DC_SECURE_KEY_INT_STATUS_get_content7_key_updated_int(data)           ((0x00000100&(data))>>8)
#define DC_SECURE_KEY_INT_STATUS_content6_key_updated_int_shift               (7)
#define DC_SECURE_KEY_INT_STATUS_content6_key_updated_int_mask                (0x00000080)
#define DC_SECURE_KEY_INT_STATUS_content6_key_updated_int(data)               (0x00000080&((data)<<7))
#define DC_SECURE_KEY_INT_STATUS_content6_key_updated_int_src(data)           ((0x00000080&(data))>>7)
#define DC_SECURE_KEY_INT_STATUS_get_content6_key_updated_int(data)           ((0x00000080&(data))>>7)
#define DC_SECURE_KEY_INT_STATUS_content5_key_updated_int_shift               (6)
#define DC_SECURE_KEY_INT_STATUS_content5_key_updated_int_mask                (0x00000040)
#define DC_SECURE_KEY_INT_STATUS_content5_key_updated_int(data)               (0x00000040&((data)<<6))
#define DC_SECURE_KEY_INT_STATUS_content5_key_updated_int_src(data)           ((0x00000040&(data))>>6)
#define DC_SECURE_KEY_INT_STATUS_get_content5_key_updated_int(data)           ((0x00000040&(data))>>6)
#define DC_SECURE_KEY_INT_STATUS_content4_key_updated_int_shift               (5)
#define DC_SECURE_KEY_INT_STATUS_content4_key_updated_int_mask                (0x00000020)
#define DC_SECURE_KEY_INT_STATUS_content4_key_updated_int(data)               (0x00000020&((data)<<5))
#define DC_SECURE_KEY_INT_STATUS_content4_key_updated_int_src(data)           ((0x00000020&(data))>>5)
#define DC_SECURE_KEY_INT_STATUS_get_content4_key_updated_int(data)           ((0x00000020&(data))>>5)
#define DC_SECURE_KEY_INT_STATUS_content3_key_updated_int_shift               (4)
#define DC_SECURE_KEY_INT_STATUS_content3_key_updated_int_mask                (0x00000010)
#define DC_SECURE_KEY_INT_STATUS_content3_key_updated_int(data)               (0x00000010&((data)<<4))
#define DC_SECURE_KEY_INT_STATUS_content3_key_updated_int_src(data)           ((0x00000010&(data))>>4)
#define DC_SECURE_KEY_INT_STATUS_get_content3_key_updated_int(data)           ((0x00000010&(data))>>4)
#define DC_SECURE_KEY_INT_STATUS_content2_key_updated_int_shift               (3)
#define DC_SECURE_KEY_INT_STATUS_content2_key_updated_int_mask                (0x00000008)
#define DC_SECURE_KEY_INT_STATUS_content2_key_updated_int(data)               (0x00000008&((data)<<3))
#define DC_SECURE_KEY_INT_STATUS_content2_key_updated_int_src(data)           ((0x00000008&(data))>>3)
#define DC_SECURE_KEY_INT_STATUS_get_content2_key_updated_int(data)           ((0x00000008&(data))>>3)
#define DC_SECURE_KEY_INT_STATUS_content1_key_updated_int_shift               (2)
#define DC_SECURE_KEY_INT_STATUS_content1_key_updated_int_mask                (0x00000004)
#define DC_SECURE_KEY_INT_STATUS_content1_key_updated_int(data)               (0x00000004&((data)<<2))
#define DC_SECURE_KEY_INT_STATUS_content1_key_updated_int_src(data)           ((0x00000004&(data))>>2)
#define DC_SECURE_KEY_INT_STATUS_get_content1_key_updated_int(data)           ((0x00000004&(data))>>2)
#define DC_SECURE_KEY_INT_STATUS_content0_key_updated_int_shift               (1)
#define DC_SECURE_KEY_INT_STATUS_content0_key_updated_int_mask                (0x00000002)
#define DC_SECURE_KEY_INT_STATUS_content0_key_updated_int(data)               (0x00000002&((data)<<1))
#define DC_SECURE_KEY_INT_STATUS_content0_key_updated_int_src(data)           ((0x00000002&(data))>>1)
#define DC_SECURE_KEY_INT_STATUS_get_content0_key_updated_int(data)           ((0x00000002&(data))>>1)
#define DC_SECURE_KEY_INT_STATUS_write_data_shift                             (0)
#define DC_SECURE_KEY_INT_STATUS_write_data_mask                              (0x00000001)
#define DC_SECURE_KEY_INT_STATUS_write_data(data)                             (0x00000001&((data)<<0))
#define DC_SECURE_KEY_INT_STATUS_write_data_src(data)                         ((0x00000001&(data))>>0)
#define DC_SECURE_KEY_INT_STATUS_get_write_data(data)                         ((0x00000001&(data))>>0)


#define DC_SECURE_INT_ENABLE_SYS2                                             0x180075B4
#define DC_SECURE_INT_ENABLE_SYS2_reg_addr                                    "0xB80075B4"
#define DC_SECURE_INT_ENABLE_SYS2_reg                                         0xB80075B4
#define set_DC_SECURE_INT_ENABLE_SYS2_reg(data)   (*((volatile unsigned int*) DC_SECURE_INT_ENABLE_SYS2_reg)=data)
#define get_DC_SECURE_INT_ENABLE_SYS2_reg   (*((volatile unsigned int*) DC_SECURE_INT_ENABLE_SYS2_reg))
#define DC_SECURE_INT_ENABLE_SYS2_inst_adr                                    "0x006D"
#define DC_SECURE_INT_ENABLE_SYS2_inst                                        0x006D
#define DC_SECURE_INT_ENABLE_SYS2_display_touch_other_en_shift                (31)
#define DC_SECURE_INT_ENABLE_SYS2_display_touch_other_en_mask                 (0x80000000)
#define DC_SECURE_INT_ENABLE_SYS2_display_touch_other_en(data)                (0x80000000&((data)<<31))
#define DC_SECURE_INT_ENABLE_SYS2_display_touch_other_en_src(data)            ((0x80000000&(data))>>31)
#define DC_SECURE_INT_ENABLE_SYS2_get_display_touch_other_en(data)            ((0x80000000&(data))>>31)
#define DC_SECURE_INT_ENABLE_SYS2_display1_touch_en_shift                     (30)
#define DC_SECURE_INT_ENABLE_SYS2_display1_touch_en_mask                      (0x40000000)
#define DC_SECURE_INT_ENABLE_SYS2_display1_touch_en(data)                     (0x40000000&((data)<<30))
#define DC_SECURE_INT_ENABLE_SYS2_display1_touch_en_src(data)                 ((0x40000000&(data))>>30)
#define DC_SECURE_INT_ENABLE_SYS2_get_display1_touch_en(data)                 ((0x40000000&(data))>>30)
#define DC_SECURE_INT_ENABLE_SYS2_display0_touch_en_shift                     (29)
#define DC_SECURE_INT_ENABLE_SYS2_display0_touch_en_mask                      (0x20000000)
#define DC_SECURE_INT_ENABLE_SYS2_display0_touch_en(data)                     (0x20000000&((data)<<29))
#define DC_SECURE_INT_ENABLE_SYS2_display0_touch_en_src(data)                 ((0x20000000&(data))>>29)
#define DC_SECURE_INT_ENABLE_SYS2_get_display0_touch_en(data)                 ((0x20000000&(data))>>29)
#define DC_SECURE_INT_ENABLE_SYS2_seq_over_max_secure_addr_int_en_shift       (27)
#define DC_SECURE_INT_ENABLE_SYS2_seq_over_max_secure_addr_int_en_mask        (0x08000000)
#define DC_SECURE_INT_ENABLE_SYS2_seq_over_max_secure_addr_int_en(data)       (0x08000000&((data)<<27))
#define DC_SECURE_INT_ENABLE_SYS2_seq_over_max_secure_addr_int_en_src(data)   ((0x08000000&(data))>>27)
#define DC_SECURE_INT_ENABLE_SYS2_get_seq_over_max_secure_addr_int_en(data)   ((0x08000000&(data))>>27)
#define DC_SECURE_INT_ENABLE_SYS2_blk_y_overflow_int_en_shift                 (26)
#define DC_SECURE_INT_ENABLE_SYS2_blk_y_overflow_int_en_mask                  (0x04000000)
#define DC_SECURE_INT_ENABLE_SYS2_blk_y_overflow_int_en(data)                 (0x04000000&((data)<<26))
#define DC_SECURE_INT_ENABLE_SYS2_blk_y_overflow_int_en_src(data)             ((0x04000000&(data))>>26)
#define DC_SECURE_INT_ENABLE_SYS2_get_blk_y_overflow_int_en(data)             ((0x04000000&(data))>>26)
#define DC_SECURE_INT_ENABLE_SYS2_blk_x_overflow_int_en_shift                 (25)
#define DC_SECURE_INT_ENABLE_SYS2_blk_x_overflow_int_en_mask                  (0x02000000)
#define DC_SECURE_INT_ENABLE_SYS2_blk_x_overflow_int_en(data)                 (0x02000000&((data)<<25))
#define DC_SECURE_INT_ENABLE_SYS2_blk_x_overflow_int_en_src(data)             ((0x02000000&(data))>>25)
#define DC_SECURE_INT_ENABLE_SYS2_get_blk_x_overflow_int_en(data)             ((0x02000000&(data))>>25)
#define DC_SECURE_INT_ENABLE_SYS2_content7_seq_touch_int_en_shift             (23)
#define DC_SECURE_INT_ENABLE_SYS2_content7_seq_touch_int_en_mask              (0x00800000)
#define DC_SECURE_INT_ENABLE_SYS2_content7_seq_touch_int_en(data)             (0x00800000&((data)<<23))
#define DC_SECURE_INT_ENABLE_SYS2_content7_seq_touch_int_en_src(data)         ((0x00800000&(data))>>23)
#define DC_SECURE_INT_ENABLE_SYS2_get_content7_seq_touch_int_en(data)         ((0x00800000&(data))>>23)
#define DC_SECURE_INT_ENABLE_SYS2_content6_seq_touch_int_en_shift             (21)
#define DC_SECURE_INT_ENABLE_SYS2_content6_seq_touch_int_en_mask              (0x00200000)
#define DC_SECURE_INT_ENABLE_SYS2_content6_seq_touch_int_en(data)             (0x00200000&((data)<<21))
#define DC_SECURE_INT_ENABLE_SYS2_content6_seq_touch_int_en_src(data)         ((0x00200000&(data))>>21)
#define DC_SECURE_INT_ENABLE_SYS2_get_content6_seq_touch_int_en(data)         ((0x00200000&(data))>>21)
#define DC_SECURE_INT_ENABLE_SYS2_content5_seq_touch_int_en_shift             (19)
#define DC_SECURE_INT_ENABLE_SYS2_content5_seq_touch_int_en_mask              (0x00080000)
#define DC_SECURE_INT_ENABLE_SYS2_content5_seq_touch_int_en(data)             (0x00080000&((data)<<19))
#define DC_SECURE_INT_ENABLE_SYS2_content5_seq_touch_int_en_src(data)         ((0x00080000&(data))>>19)
#define DC_SECURE_INT_ENABLE_SYS2_get_content5_seq_touch_int_en(data)         ((0x00080000&(data))>>19)
#define DC_SECURE_INT_ENABLE_SYS2_content4_seq_touch_int_en_shift             (17)
#define DC_SECURE_INT_ENABLE_SYS2_content4_seq_touch_int_en_mask              (0x00020000)
#define DC_SECURE_INT_ENABLE_SYS2_content4_seq_touch_int_en(data)             (0x00020000&((data)<<17))
#define DC_SECURE_INT_ENABLE_SYS2_content4_seq_touch_int_en_src(data)         ((0x00020000&(data))>>17)
#define DC_SECURE_INT_ENABLE_SYS2_get_content4_seq_touch_int_en(data)         ((0x00020000&(data))>>17)
#define DC_SECURE_INT_ENABLE_SYS2_content3_seq_touch_int_en_shift             (15)
#define DC_SECURE_INT_ENABLE_SYS2_content3_seq_touch_int_en_mask              (0x00008000)
#define DC_SECURE_INT_ENABLE_SYS2_content3_seq_touch_int_en(data)             (0x00008000&((data)<<15))
#define DC_SECURE_INT_ENABLE_SYS2_content3_seq_touch_int_en_src(data)         ((0x00008000&(data))>>15)
#define DC_SECURE_INT_ENABLE_SYS2_get_content3_seq_touch_int_en(data)         ((0x00008000&(data))>>15)
#define DC_SECURE_INT_ENABLE_SYS2_content2_seq_touch_int_en_shift             (13)
#define DC_SECURE_INT_ENABLE_SYS2_content2_seq_touch_int_en_mask              (0x00002000)
#define DC_SECURE_INT_ENABLE_SYS2_content2_seq_touch_int_en(data)             (0x00002000&((data)<<13))
#define DC_SECURE_INT_ENABLE_SYS2_content2_seq_touch_int_en_src(data)         ((0x00002000&(data))>>13)
#define DC_SECURE_INT_ENABLE_SYS2_get_content2_seq_touch_int_en(data)         ((0x00002000&(data))>>13)
#define DC_SECURE_INT_ENABLE_SYS2_content1_seq_touch_int_en_shift             (11)
#define DC_SECURE_INT_ENABLE_SYS2_content1_seq_touch_int_en_mask              (0x00000800)
#define DC_SECURE_INT_ENABLE_SYS2_content1_seq_touch_int_en(data)             (0x00000800&((data)<<11))
#define DC_SECURE_INT_ENABLE_SYS2_content1_seq_touch_int_en_src(data)         ((0x00000800&(data))>>11)
#define DC_SECURE_INT_ENABLE_SYS2_get_content1_seq_touch_int_en(data)         ((0x00000800&(data))>>11)
#define DC_SECURE_INT_ENABLE_SYS2_content0_seq_touch_int_en_shift             (9)
#define DC_SECURE_INT_ENABLE_SYS2_content0_seq_touch_int_en_mask              (0x00000200)
#define DC_SECURE_INT_ENABLE_SYS2_content0_seq_touch_int_en(data)             (0x00000200&((data)<<9))
#define DC_SECURE_INT_ENABLE_SYS2_content0_seq_touch_int_en_src(data)         ((0x00000200&(data))>>9)
#define DC_SECURE_INT_ENABLE_SYS2_get_content0_seq_touch_int_en(data)         ((0x00000200&(data))>>9)
#define DC_SECURE_INT_ENABLE_SYS2_protect3_seq_touch_int_en_shift             (7)
#define DC_SECURE_INT_ENABLE_SYS2_protect3_seq_touch_int_en_mask              (0x00000080)
#define DC_SECURE_INT_ENABLE_SYS2_protect3_seq_touch_int_en(data)             (0x00000080&((data)<<7))
#define DC_SECURE_INT_ENABLE_SYS2_protect3_seq_touch_int_en_src(data)         ((0x00000080&(data))>>7)
#define DC_SECURE_INT_ENABLE_SYS2_get_protect3_seq_touch_int_en(data)         ((0x00000080&(data))>>7)
#define DC_SECURE_INT_ENABLE_SYS2_protect2_seq_touch_int_en_shift             (5)
#define DC_SECURE_INT_ENABLE_SYS2_protect2_seq_touch_int_en_mask              (0x00000020)
#define DC_SECURE_INT_ENABLE_SYS2_protect2_seq_touch_int_en(data)             (0x00000020&((data)<<5))
#define DC_SECURE_INT_ENABLE_SYS2_protect2_seq_touch_int_en_src(data)         ((0x00000020&(data))>>5)
#define DC_SECURE_INT_ENABLE_SYS2_get_protect2_seq_touch_int_en(data)         ((0x00000020&(data))>>5)
#define DC_SECURE_INT_ENABLE_SYS2_protect1_seq_touch_int_en_shift             (3)
#define DC_SECURE_INT_ENABLE_SYS2_protect1_seq_touch_int_en_mask              (0x00000008)
#define DC_SECURE_INT_ENABLE_SYS2_protect1_seq_touch_int_en(data)             (0x00000008&((data)<<3))
#define DC_SECURE_INT_ENABLE_SYS2_protect1_seq_touch_int_en_src(data)         ((0x00000008&(data))>>3)
#define DC_SECURE_INT_ENABLE_SYS2_get_protect1_seq_touch_int_en(data)         ((0x00000008&(data))>>3)
#define DC_SECURE_INT_ENABLE_SYS2_protect0_seq_touch_int_en_shift             (1)
#define DC_SECURE_INT_ENABLE_SYS2_protect0_seq_touch_int_en_mask              (0x00000002)
#define DC_SECURE_INT_ENABLE_SYS2_protect0_seq_touch_int_en(data)             (0x00000002&((data)<<1))
#define DC_SECURE_INT_ENABLE_SYS2_protect0_seq_touch_int_en_src(data)         ((0x00000002&(data))>>1)
#define DC_SECURE_INT_ENABLE_SYS2_get_protect0_seq_touch_int_en(data)         ((0x00000002&(data))>>1)
#define DC_SECURE_INT_ENABLE_SYS2_write_data_shift                            (0)
#define DC_SECURE_INT_ENABLE_SYS2_write_data_mask                             (0x00000001)
#define DC_SECURE_INT_ENABLE_SYS2_write_data(data)                            (0x00000001&((data)<<0))
#define DC_SECURE_INT_ENABLE_SYS2_write_data_src(data)                        ((0x00000001&(data))>>0)
#define DC_SECURE_INT_ENABLE_SYS2_get_write_data(data)                        ((0x00000001&(data))>>0)


#define DC_SECURE_INT_STATUS_SYS2                                             0x180075B8
#define DC_SECURE_INT_STATUS_SYS2_reg_addr                                    "0xB80075B8"
#define DC_SECURE_INT_STATUS_SYS2_reg                                         0xB80075B8
#define set_DC_SECURE_INT_STATUS_SYS2_reg(data)   (*((volatile unsigned int*) DC_SECURE_INT_STATUS_SYS2_reg)=data)
#define get_DC_SECURE_INT_STATUS_SYS2_reg   (*((volatile unsigned int*) DC_SECURE_INT_STATUS_SYS2_reg))
#define DC_SECURE_INT_STATUS_SYS2_inst_adr                                    "0x006E"
#define DC_SECURE_INT_STATUS_SYS2_inst                                        0x006E
#define DC_SECURE_INT_STATUS_SYS2_display_touch_other_int_shift               (31)
#define DC_SECURE_INT_STATUS_SYS2_display_touch_other_int_mask                (0x80000000)
#define DC_SECURE_INT_STATUS_SYS2_display_touch_other_int(data)               (0x80000000&((data)<<31))
#define DC_SECURE_INT_STATUS_SYS2_display_touch_other_int_src(data)           ((0x80000000&(data))>>31)
#define DC_SECURE_INT_STATUS_SYS2_get_display_touch_other_int(data)           ((0x80000000&(data))>>31)
#define DC_SECURE_INT_STATUS_SYS2_display1_touch_int_shift                    (30)
#define DC_SECURE_INT_STATUS_SYS2_display1_touch_int_mask                     (0x40000000)
#define DC_SECURE_INT_STATUS_SYS2_display1_touch_int(data)                    (0x40000000&((data)<<30))
#define DC_SECURE_INT_STATUS_SYS2_display1_touch_int_src(data)                ((0x40000000&(data))>>30)
#define DC_SECURE_INT_STATUS_SYS2_get_display1_touch_int(data)                ((0x40000000&(data))>>30)
#define DC_SECURE_INT_STATUS_SYS2_display0_touch_int_shift                    (29)
#define DC_SECURE_INT_STATUS_SYS2_display0_touch_int_mask                     (0x20000000)
#define DC_SECURE_INT_STATUS_SYS2_display0_touch_int(data)                    (0x20000000&((data)<<29))
#define DC_SECURE_INT_STATUS_SYS2_display0_touch_int_src(data)                ((0x20000000&(data))>>29)
#define DC_SECURE_INT_STATUS_SYS2_get_display0_touch_int(data)                ((0x20000000&(data))>>29)
#define DC_SECURE_INT_STATUS_SYS2_seq_over_max_secure_addr_int_shift          (27)
#define DC_SECURE_INT_STATUS_SYS2_seq_over_max_secure_addr_int_mask           (0x08000000)
#define DC_SECURE_INT_STATUS_SYS2_seq_over_max_secure_addr_int(data)          (0x08000000&((data)<<27))
#define DC_SECURE_INT_STATUS_SYS2_seq_over_max_secure_addr_int_src(data)      ((0x08000000&(data))>>27)
#define DC_SECURE_INT_STATUS_SYS2_get_seq_over_max_secure_addr_int(data)      ((0x08000000&(data))>>27)
#define DC_SECURE_INT_STATUS_SYS2_blk_y_overflow_int_shift                    (26)
#define DC_SECURE_INT_STATUS_SYS2_blk_y_overflow_int_mask                     (0x04000000)
#define DC_SECURE_INT_STATUS_SYS2_blk_y_overflow_int(data)                    (0x04000000&((data)<<26))
#define DC_SECURE_INT_STATUS_SYS2_blk_y_overflow_int_src(data)                ((0x04000000&(data))>>26)
#define DC_SECURE_INT_STATUS_SYS2_get_blk_y_overflow_int(data)                ((0x04000000&(data))>>26)
#define DC_SECURE_INT_STATUS_SYS2_blk_x_overflow_int_shift                    (25)
#define DC_SECURE_INT_STATUS_SYS2_blk_x_overflow_int_mask                     (0x02000000)
#define DC_SECURE_INT_STATUS_SYS2_blk_x_overflow_int(data)                    (0x02000000&((data)<<25))
#define DC_SECURE_INT_STATUS_SYS2_blk_x_overflow_int_src(data)                ((0x02000000&(data))>>25)
#define DC_SECURE_INT_STATUS_SYS2_get_blk_x_overflow_int(data)                ((0x02000000&(data))>>25)
#define DC_SECURE_INT_STATUS_SYS2_content7_seq_touch_int_shift                (23)
#define DC_SECURE_INT_STATUS_SYS2_content7_seq_touch_int_mask                 (0x00800000)
#define DC_SECURE_INT_STATUS_SYS2_content7_seq_touch_int(data)                (0x00800000&((data)<<23))
#define DC_SECURE_INT_STATUS_SYS2_content7_seq_touch_int_src(data)            ((0x00800000&(data))>>23)
#define DC_SECURE_INT_STATUS_SYS2_get_content7_seq_touch_int(data)            ((0x00800000&(data))>>23)
#define DC_SECURE_INT_STATUS_SYS2_content6_seq_touch_int_shift                (21)
#define DC_SECURE_INT_STATUS_SYS2_content6_seq_touch_int_mask                 (0x00200000)
#define DC_SECURE_INT_STATUS_SYS2_content6_seq_touch_int(data)                (0x00200000&((data)<<21))
#define DC_SECURE_INT_STATUS_SYS2_content6_seq_touch_int_src(data)            ((0x00200000&(data))>>21)
#define DC_SECURE_INT_STATUS_SYS2_get_content6_seq_touch_int(data)            ((0x00200000&(data))>>21)
#define DC_SECURE_INT_STATUS_SYS2_content5_seq_touch_int_shift                (19)
#define DC_SECURE_INT_STATUS_SYS2_content5_seq_touch_int_mask                 (0x00080000)
#define DC_SECURE_INT_STATUS_SYS2_content5_seq_touch_int(data)                (0x00080000&((data)<<19))
#define DC_SECURE_INT_STATUS_SYS2_content5_seq_touch_int_src(data)            ((0x00080000&(data))>>19)
#define DC_SECURE_INT_STATUS_SYS2_get_content5_seq_touch_int(data)            ((0x00080000&(data))>>19)
#define DC_SECURE_INT_STATUS_SYS2_content4_seq_touch_int_shift                (17)
#define DC_SECURE_INT_STATUS_SYS2_content4_seq_touch_int_mask                 (0x00020000)
#define DC_SECURE_INT_STATUS_SYS2_content4_seq_touch_int(data)                (0x00020000&((data)<<17))
#define DC_SECURE_INT_STATUS_SYS2_content4_seq_touch_int_src(data)            ((0x00020000&(data))>>17)
#define DC_SECURE_INT_STATUS_SYS2_get_content4_seq_touch_int(data)            ((0x00020000&(data))>>17)
#define DC_SECURE_INT_STATUS_SYS2_content3_seq_touch_int_shift                (15)
#define DC_SECURE_INT_STATUS_SYS2_content3_seq_touch_int_mask                 (0x00008000)
#define DC_SECURE_INT_STATUS_SYS2_content3_seq_touch_int(data)                (0x00008000&((data)<<15))
#define DC_SECURE_INT_STATUS_SYS2_content3_seq_touch_int_src(data)            ((0x00008000&(data))>>15)
#define DC_SECURE_INT_STATUS_SYS2_get_content3_seq_touch_int(data)            ((0x00008000&(data))>>15)
#define DC_SECURE_INT_STATUS_SYS2_content2_seq_touch_int_shift                (13)
#define DC_SECURE_INT_STATUS_SYS2_content2_seq_touch_int_mask                 (0x00002000)
#define DC_SECURE_INT_STATUS_SYS2_content2_seq_touch_int(data)                (0x00002000&((data)<<13))
#define DC_SECURE_INT_STATUS_SYS2_content2_seq_touch_int_src(data)            ((0x00002000&(data))>>13)
#define DC_SECURE_INT_STATUS_SYS2_get_content2_seq_touch_int(data)            ((0x00002000&(data))>>13)
#define DC_SECURE_INT_STATUS_SYS2_content1_seq_touch_int_shift                (11)
#define DC_SECURE_INT_STATUS_SYS2_content1_seq_touch_int_mask                 (0x00000800)
#define DC_SECURE_INT_STATUS_SYS2_content1_seq_touch_int(data)                (0x00000800&((data)<<11))
#define DC_SECURE_INT_STATUS_SYS2_content1_seq_touch_int_src(data)            ((0x00000800&(data))>>11)
#define DC_SECURE_INT_STATUS_SYS2_get_content1_seq_touch_int(data)            ((0x00000800&(data))>>11)
#define DC_SECURE_INT_STATUS_SYS2_content0_seq_touch_int_shift                (9)
#define DC_SECURE_INT_STATUS_SYS2_content0_seq_touch_int_mask                 (0x00000200)
#define DC_SECURE_INT_STATUS_SYS2_content0_seq_touch_int(data)                (0x00000200&((data)<<9))
#define DC_SECURE_INT_STATUS_SYS2_content0_seq_touch_int_src(data)            ((0x00000200&(data))>>9)
#define DC_SECURE_INT_STATUS_SYS2_get_content0_seq_touch_int(data)            ((0x00000200&(data))>>9)
#define DC_SECURE_INT_STATUS_SYS2_protect3_seq_touch_int_shift                (7)
#define DC_SECURE_INT_STATUS_SYS2_protect3_seq_touch_int_mask                 (0x00000080)
#define DC_SECURE_INT_STATUS_SYS2_protect3_seq_touch_int(data)                (0x00000080&((data)<<7))
#define DC_SECURE_INT_STATUS_SYS2_protect3_seq_touch_int_src(data)            ((0x00000080&(data))>>7)
#define DC_SECURE_INT_STATUS_SYS2_get_protect3_seq_touch_int(data)            ((0x00000080&(data))>>7)
#define DC_SECURE_INT_STATUS_SYS2_protect2_seq_touch_int_shift                (5)
#define DC_SECURE_INT_STATUS_SYS2_protect2_seq_touch_int_mask                 (0x00000020)
#define DC_SECURE_INT_STATUS_SYS2_protect2_seq_touch_int(data)                (0x00000020&((data)<<5))
#define DC_SECURE_INT_STATUS_SYS2_protect2_seq_touch_int_src(data)            ((0x00000020&(data))>>5)
#define DC_SECURE_INT_STATUS_SYS2_get_protect2_seq_touch_int(data)            ((0x00000020&(data))>>5)
#define DC_SECURE_INT_STATUS_SYS2_protect1_seq_touch_int_shift                (3)
#define DC_SECURE_INT_STATUS_SYS2_protect1_seq_touch_int_mask                 (0x00000008)
#define DC_SECURE_INT_STATUS_SYS2_protect1_seq_touch_int(data)                (0x00000008&((data)<<3))
#define DC_SECURE_INT_STATUS_SYS2_protect1_seq_touch_int_src(data)            ((0x00000008&(data))>>3)
#define DC_SECURE_INT_STATUS_SYS2_get_protect1_seq_touch_int(data)            ((0x00000008&(data))>>3)
#define DC_SECURE_INT_STATUS_SYS2_protect0_seq_touch_int_shift                (1)
#define DC_SECURE_INT_STATUS_SYS2_protect0_seq_touch_int_mask                 (0x00000002)
#define DC_SECURE_INT_STATUS_SYS2_protect0_seq_touch_int(data)                (0x00000002&((data)<<1))
#define DC_SECURE_INT_STATUS_SYS2_protect0_seq_touch_int_src(data)            ((0x00000002&(data))>>1)
#define DC_SECURE_INT_STATUS_SYS2_get_protect0_seq_touch_int(data)            ((0x00000002&(data))>>1)
#define DC_SECURE_INT_STATUS_SYS2_write_data_shift                            (0)
#define DC_SECURE_INT_STATUS_SYS2_write_data_mask                             (0x00000001)
#define DC_SECURE_INT_STATUS_SYS2_write_data(data)                            (0x00000001&((data)<<0))
#define DC_SECURE_INT_STATUS_SYS2_write_data_src(data)                        ((0x00000001&(data))>>0)
#define DC_SECURE_INT_STATUS_SYS2_get_write_data(data)                        ((0x00000001&(data))>>0)


#define DC_SECURE_ERROR_INFO_SYS2                                             0x180075BC
#define DC_SECURE_ERROR_INFO_SYS2_reg_addr                                    "0xB80075BC"
#define DC_SECURE_ERROR_INFO_SYS2_reg                                         0xB80075BC
#define set_DC_SECURE_ERROR_INFO_SYS2_reg(data)   (*((volatile unsigned int*) DC_SECURE_ERROR_INFO_SYS2_reg)=data)
#define get_DC_SECURE_ERROR_INFO_SYS2_reg   (*((volatile unsigned int*) DC_SECURE_ERROR_INFO_SYS2_reg))
#define DC_SECURE_ERROR_INFO_SYS2_inst_adr                                    "0x006F"
#define DC_SECURE_ERROR_INFO_SYS2_inst                                        0x006F
#define DC_SECURE_ERROR_INFO_SYS2_seq_read_error_id_shift                     (8)
#define DC_SECURE_ERROR_INFO_SYS2_seq_read_error_id_mask                      (0x00007F00)
#define DC_SECURE_ERROR_INFO_SYS2_seq_read_error_id(data)                     (0x00007F00&((data)<<8))
#define DC_SECURE_ERROR_INFO_SYS2_seq_read_error_id_src(data)                 ((0x00007F00&(data))>>8)
#define DC_SECURE_ERROR_INFO_SYS2_get_seq_read_error_id(data)                 ((0x00007F00&(data))>>8)
#define DC_SECURE_ERROR_INFO_SYS2_seq_write_error_id_shift                    (0)
#define DC_SECURE_ERROR_INFO_SYS2_seq_write_error_id_mask                     (0x0000007F)
#define DC_SECURE_ERROR_INFO_SYS2_seq_write_error_id(data)                    (0x0000007F&((data)<<0))
#define DC_SECURE_ERROR_INFO_SYS2_seq_write_error_id_src(data)                ((0x0000007F&(data))>>0)
#define DC_SECURE_ERROR_INFO_SYS2_get_seq_write_error_id(data)                ((0x0000007F&(data))>>0)


#endif
