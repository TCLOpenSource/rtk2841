/**************************************************************
// Spec Version                  : 0.02
// Parser Version                : DVR_Parser_6.11(120105)
// CModelGen Version             : 5.1 2012.01.05
// Naming Rule                   :  Module_Register_Name
// Naming Rule                   : Module_Register_Name_reg
// Parse Option                  : Only Parse _op1
// Parse Address Region          : All Address Region 
// Decode bit number             : 12 bits
// Firmware Header Generate Date : 2014/12/8 14:15:4
***************************************************************/


#ifndef _DC2_SYS_REG_H_INCLUDED_
#define _DC2_SYS_REG_H_INCLUDED_
#ifdef  _DC2_SYS_USE_STRUCT
typedef struct 
{
unsigned int     reserved_0:9;
unsigned int     pict_width_scale:6;
unsigned int     pict_init_page:17;
}DC2_SYS_DC_PICT_SET;

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
}DC2_SYS_DC_SYS_MISC;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     enable:1;
}DC2_SYS_DC_PIC_OFFSET_X_DETECTION;

typedef struct 
{
unsigned int     pict_set_num:8;
unsigned int     pict_offset_rd:1;
unsigned int     reserved_0:2;
unsigned int     pict_set_wide:1;
unsigned int     pict_set_offset_y:10;
unsigned int     pict_set_offset_x:10;
}DC2_SYS_DC_PICT_SET_OFFSET;

typedef struct 
{
unsigned int     reserved_0:15;
unsigned int     req_pending:1;
unsigned int     reserved_1:3;
unsigned int     req_id:13;
}DC2_SYS_DC_REQ_STATUS;

typedef struct 
{
unsigned int     pre_arb_merge:1;
unsigned int     reserved_0:2;
unsigned int     qfifo_cnt_full_threshold:5;
unsigned int     full_cmd_count:4;
unsigned int     pre_tra_rd_cnt:10;
unsigned int     pre_tra_wr_cnt:10;
}DC2_SYS_DC_SYS_MISC2;

typedef struct 
{
unsigned int     reserved_0:2;
unsigned int     wfifo_cnt_full_threshold:6;
unsigned int     reserved_1:2;
unsigned int     memc_cmd_queue_flush:1;
unsigned int     memc_cmd_grp_disable:1;
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
}DC2_SYS_DC_SYS_MISC3;

typedef struct 
{
unsigned int     sfmode_pattern0:32;
}DC2_SYS_DC_SFMODE0;

typedef struct 
{
unsigned int     sfmode_pattern1:32;
}DC2_SYS_DC_SFMODE1;

typedef struct 
{
unsigned int     sfmode_pattern2:32;
}DC2_SYS_DC_SFMODE2;

typedef struct 
{
unsigned int     sfmode_pattern3:32;
}DC2_SYS_DC_SFMODE3;

typedef struct 
{
unsigned int     sfmode_cmp_rlt0:32;
}DC2_SYS_DC_SFMODE_CMP0;

typedef struct 
{
unsigned int     sfmode_cmp_rlt1:32;
}DC2_SYS_DC_SFMODE_CMP1;

typedef struct 
{
unsigned int     sfmode_cmp_rlt2:32;
}DC2_SYS_DC_SFMODE_CMP2;

typedef struct 
{
unsigned int     sfmode_cmp_rlt3:32;
}DC2_SYS_DC_SFMODE_CMP3;

typedef struct 
{
unsigned int     reserved_0:14;
unsigned int     Debug_sys2:1;
unsigned int     Debug_en:1;
unsigned int     reserved_1:2;
unsigned int     Debug_sel_1:6;
unsigned int     reserved_2:2;
unsigned int     Debug_sel_0:6;
}DC2_SYS_DC_DEBUG;

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
}DC2_SYS_DC_DEBUG_STATUS;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     C0_LATCNT_END:8;
unsigned int     reserved_1:8;
unsigned int     C0_LATCNT_BEG:8;
}DC2_SYS_DC_PRIORITY_CTRL0;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     C1_LATCNT_END:8;
unsigned int     reserved_1:8;
unsigned int     C1_LATCNT_BEG:8;
}DC2_SYS_DC_PRIORITY_CTRL1;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     C2_LATCNT_END:8;
unsigned int     reserved_1:8;
unsigned int     C2_LATCNT_BEG:8;
}DC2_SYS_DC_PRIORITY_CTRL2;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     C3_LATCNT_END:8;
unsigned int     reserved_1:8;
unsigned int     C3_LATCNT_BEG:8;
}DC2_SYS_DC_PRIORITY_CTRL3;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     C4_LATCNT_END:8;
unsigned int     reserved_1:8;
unsigned int     C4_LATCNT_BEG:8;
}DC2_SYS_DC_PRIORITY_CTRL4;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     C5_LATCNT_END:8;
unsigned int     reserved_1:8;
unsigned int     C5_LATCNT_BEG:8;
}DC2_SYS_DC_PRIORITY_CTRL5;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     C6_LATCNT_END:8;
unsigned int     reserved_1:8;
unsigned int     C6_LATCNT_BEG:8;
}DC2_SYS_DC_PRIORITY_CTRL6;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     C7_LATCNT_END:8;
unsigned int     reserved_1:8;
unsigned int     C7_LATCNT_BEG:8;
}DC2_SYS_DC_PRIORITY_CTRL7;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     C8_LATCNT_END:8;
unsigned int     reserved_1:8;
unsigned int     C8_LATCNT_BEG:8;
}DC2_SYS_DC_PRIORITY_CTRL8;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     C9_LATCNT_END:8;
unsigned int     reserved_1:8;
unsigned int     C9_LATCNT_BEG:8;
}DC2_SYS_DC_PRIORITY_CTRL9;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     CA_LATCNT_END:8;
unsigned int     reserved_1:8;
unsigned int     CA_LATCNT_BEG:8;
}DC2_SYS_DC_PRIORITY_CTRLA;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     CB_LATCNT_END:8;
unsigned int     reserved_1:8;
unsigned int     CB_LATCNT_BEG:8;
}DC2_SYS_DC_PRIORITY_CTRLB;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     CC_LATCNT_END:8;
unsigned int     reserved_1:8;
unsigned int     CC_LATCNT_BEG:8;
}DC2_SYS_DC_PRIORITY_CTRLC;

typedef struct 
{
unsigned int     GPU_LAT_NEW:1;
unsigned int     reserved_0:2;
unsigned int     HIE_CMP_DIS:13;
unsigned int     reserved_1:8;
unsigned int     LATCNT_PERIOD:8;
}DC2_SYS_DC_PRIORITY_CTRL_HIE;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     SCPU_LATCNT:8;
}DC2_SYS_DC_PRIORITY_CTRL_SCPU;

typedef struct 
{
unsigned int     reserved_0:19;
unsigned int     req_mask_index:13;
}DC2_SYS_DC_CLIENT_MASK;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     pc_go:1;
}DC2_SYS_DC_PC_CTRL;

typedef struct 
{
unsigned int     pc_tota_mon_num:32;
}DC2_SYS_DC_PC_TOTA_MON_NUM;

typedef struct 
{
unsigned int     pc_tota_ack_num:32;
}DC2_SYS_DC_PC_TOTA_ACK_NUM;

typedef struct 
{
unsigned int     pc_tota_idl_num:32;
}DC2_SYS_DC_PC_TOTA_IDL_NUM;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     write_en_3:1;
unsigned int     pc_sysh_prog2_sel:7;
unsigned int     write_en_2:1;
unsigned int     pc_sysh_prog1_sel:7;
unsigned int     write_en_1:1;
unsigned int     pc_sysh_prog0_sel:7;
}DC2_SYS_DC_PC_SYSH_PROG_CTRL;

typedef struct 
{
unsigned int     reserved_0:25;
unsigned int     pc_sysh_prog2_req_occur:1;
unsigned int     pc_sysh_prog1_req_occur:1;
unsigned int     pc_sysh_prog0_req_occur:1;
unsigned int     reserved_1:4;
}DC2_SYS_DC_PC_SYS_PROG_CTRL1;

typedef struct 
{
unsigned int     sysh_prog0_acc_lat:32;
}DC2_SYS_DC_PC_SYSH_PROG_0_ACC_LAT;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     sysh_prog0_max_lat:16;
}DC2_SYS_DC_PC_SYSH_PROG_0_MAX_LAT;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     sysh_prog0_req_num:24;
}DC2_SYS_DC_PC_SYSH_PROG_0_REQ_NUM;

typedef struct 
{
unsigned int     sysh_prog0_ack_num:32;
}DC2_SYS_DC_PC_SYSH_PROG_0_ACK_NUM;

typedef struct 
{
unsigned int     sysh_prog1_acc_lat:32;
}DC2_SYS_DC_PC_SYSH_PROG_1_ACC_LAT;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     sysh_prog1_max_lat:16;
}DC2_SYS_DC_PC_SYSH_PROG_1_MAX_LAT;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     sysh_prog1_req_num:24;
}DC2_SYS_DC_PC_SYSH_PROG_1_REQ_NUM;

typedef struct 
{
unsigned int     sysh_prog1_ack_num:32;
}DC2_SYS_DC_PC_SYSH_PROG_1_ACK_NUM;

typedef struct 
{
unsigned int     sysh_prog2_acc_lat:32;
}DC2_SYS_DC_PC_SYSH_PROG_2_ACC_LAT;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     sysh_prog2_max_lat:16;
}DC2_SYS_DC_PC_SYSH_PROG_2_MAX_LAT;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     sysh_prog2_req_num:24;
}DC2_SYS_DC_PC_SYSH_PROG_2_REQ_NUM;

typedef struct 
{
unsigned int     sysh_prog2_ack_num:32;
}DC2_SYS_DC_PC_SYSH_PROG_2_ACK_NUM;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     sysh0_hitend_cnt:16;
}DC2_SYS_DC_PC_SYSH_PROG_0;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     sysh1_hitend_cnt:16;
}DC2_SYS_DC_PC_SYSH_PROG_1;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     sysh2_hitend_cnt:16;
}DC2_SYS_DC_PC_SYSH_PROG_2;

typedef struct 
{
unsigned int     reserved_0:27;
unsigned int     reserved_1:3;
unsigned int     DC_BIST_MODE_PICT0:1;
unsigned int     reserved_2:1;
}DC2_SYS_DC_BIST_MODE;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     DC_BIST_DONE_PICT0:1;
unsigned int     reserved_1:1;
}DC2_SYS_DC_BIST_DONE;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     DC_BIST_FAIL_GROUP_PICT0:1;
unsigned int     reserved_1:1;
}DC2_SYS_DC_BIST_FAIL;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     DC_DRF_MODE_PICT0:1;
unsigned int     reserved_1:1;
}DC2_SYS_DC_BIST_DRF;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     DC_DRF_RESUME_PICT0:1;
unsigned int     reserved_1:1;
}DC2_SYS_DC_BIST_RESUME;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     DC_DRF_DONE_PICT0:1;
unsigned int     reserved_1:1;
}DC2_SYS_DC_BIST0_DRF_DONE;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     DC_DRF_PAUSE_PICT0:1;
unsigned int     reserved_1:1;
}DC2_SYS_DC_BIST_DRF_PAUSE;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     DC_DRF_FAIL_GROUP_PICT0:1;
unsigned int     reserved_1:1;
}DC2_SYS_DC_BIST_DRF_FAIL;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     reserved_1:1;
unsigned int     reserved_2:1;
unsigned int     DC_DRF_PICT_FAIL0:1;
unsigned int     DC_BIST_PICT_FAIL0:1;
unsigned int     reserved_3:4;
}DC2_SYS_DC_BIST_DETAIL;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     reserved_1:3;
unsigned int     RME:1;
unsigned int     RM_3:1;
unsigned int     RM_2:1;
unsigned int     RM_1:1;
unsigned int     RM_0:1;
}DC2_SYS_DC_BIST_RM;

typedef struct 
{
unsigned int     dummy_reg0:32;
}DC2_SYS_DC_DUMMY_REG0;

typedef struct 
{
unsigned int     dummy_reg1:32;
}DC2_SYS_DC_DUMMY_REG1;

typedef struct 
{
unsigned int     dummy_reg2:32;
}DC2_SYS_DC_DUMMY_REG2;

typedef struct 
{
unsigned int     dummy_reg3:32;
}DC2_SYS_DC_DUMMY_REG3;

typedef struct 
{
unsigned int     mem_type:2;
unsigned int     reserved_0:30;
}DC2_SYS_DC_MT_TYPE;

typedef struct 
{
unsigned int     reserved_0:1;
unsigned int     saddr:26;
unsigned int     reserved_1:5;
}DC2_SYS_DC_MT_SADDR;

typedef struct 
{
unsigned int     reserved_0:1;
unsigned int     eaddr:26;
unsigned int     reserved_1:5;
}DC2_SYS_DC_MT_EADDR;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     write_enable5:1;
unsigned int     mode:2;
}DC2_SYS_DC_MT_MODE;

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
}DC2_SYS_DC_MT_TABLE;

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
}DC2_SYS_DC_MT_ADDCMD_HI;

typedef struct 
{
unsigned int     addcmd:32;
}DC2_SYS_DC_MT_ADDCMD_LO;

typedef struct 
{
unsigned int     trap_seq_sa:32;
}DC2_SYS_DC_MT_ADDCMD_SA;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     enable_block_info:1;
unsigned int     disable_cross_range_check:1;
}DC2_SYS_DC_MT_MISC;

typedef struct 
{
unsigned int     write_enable3:1;
unsigned int     error_cmd_swap_addr:27;
unsigned int     write_enable2:1;
unsigned int     error_cmd_swap_en:1;
unsigned int     write_enable1:1;
unsigned int     error_cmd_detection_en:1;
}DC2_SYS_DC_EC_CTRL;

typedef struct 
{
unsigned int     reserved_0:1;
unsigned int     error_cmd_ever_trap:1;
unsigned int     trap_case:8;
unsigned int     Addcmd_hi:22;
}DC2_SYS_DC_EC_ADDCMD_HI;

typedef struct 
{
unsigned int     Addcmd_lo:32;
}DC2_SYS_DC_EC_ADDCMD_LO;

typedef struct 
{
unsigned int     reserved_0:25;
unsigned int     reserved_1:1;
unsigned int     reserved_2:2;
unsigned int     reserved_3:1;
unsigned int     reserved_4:1;
unsigned int     write_enable1:1;
unsigned int     tag_check_en:1;
}DC2_SYS_DC_RD_TAG_CHECK;

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
}DC2_SYS_DC_INT_ENABLE;

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
}DC2_SYS_DC_INT_STATUS;

typedef struct 
{
unsigned int     reserved_0:19;
unsigned int     bw_en:13;
}DC2_SYS_BW_CTRL;

typedef struct 
{
unsigned int     value:32;
}DC2_SYS_BW_TIMER_THRESHOLD;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     value:24;
}DC2_SYS_BW_REQUEST_THRESHOLD;

typedef struct 
{
unsigned int     reserved_0:2;
unsigned int     pre_tra_rd_cnt:10;
unsigned int     reserved_1:2;
unsigned int     pre_tra_wr_cnt:10;
unsigned int     reserved_2:3;
unsigned int     ve2_mux:1;
unsigned int     ve_mux:1;
unsigned int     memc_mux:1;
unsigned int     tv_sb4_mux:1;
unsigned int     tv_sb2_mux:1;
}DC2_SYS_DC_SYS2_MUX;

typedef struct 
{
unsigned int     reserved_0:10;
unsigned int     ever_trap:1;
unsigned int     module_ID:7;
unsigned int     addcmd:14;
}DC2_SYS_DC_MT_ADDCMD_HI_SYS2;

typedef struct 
{
unsigned int     addcmd:32;
}DC2_SYS_DC_MT_ADDCMD_LO_SYS2;

typedef struct 
{
unsigned int     trap_seq_sa:32;
}DC2_SYS_DC_MT_ADDCMD_SA_SYS2;

typedef struct 
{
unsigned int     reserved_0:1;
unsigned int     error_cmd_ever_trap:1;
unsigned int     trap_case:8;
unsigned int     Addcmd_hi:22;
}DC2_SYS_DC_EC_ADDCMD_HI_SYS2;

typedef struct 
{
unsigned int     Addcmd_lo:32;
}DC2_SYS_DC_EC_ADDCMD_LO_SYS2;

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
}DC2_SYS_DC_INT_ENABLE_SYS2;

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
}DC2_SYS_DC_INT_STATUS_SYS2;

typedef struct 
{
unsigned int     cmd_inorder:1;
unsigned int     cmd_zero_bl_bypass:1;
unsigned int     reserved_0:11;
unsigned int     wcmd_fifo_th:3;
unsigned int     reserved_1:5;
unsigned int     rcmd_fifo_th:3;
unsigned int     reserved_2:3;
unsigned int     wait_wdone_th:5;
}DC2_SYS_DC_64_CMD_CTRL;

typedef struct 
{
unsigned int     full_transfer:1;
unsigned int     reserved_0:17;
unsigned int     wdata_fifo_th:6;
unsigned int     reserved_1:2;
unsigned int     rdata_fifo_th:6;
}DC2_SYS_DC_64_BUF_CTRL;

typedef struct 
{
unsigned int     dummy:32;
}DC2_SYS_DC_64_DUMMY;

typedef struct 
{
unsigned int     dbg_en:1;
unsigned int     err_bl_zero:1;
unsigned int     err_blk_wxh_odd:1;
unsigned int     reserved_0:1;
unsigned int     max_wcmd_in_fifo:4;
unsigned int     max_rcmd_in_fifo:4;
unsigned int     max_wait_wdone:6;
unsigned int     max_wdata_in_fifo:7;
unsigned int     max_rdata_in_fifo:7;
}DC2_SYS_DC_64_ERR_STATUS_AIO;

typedef struct 
{
unsigned int     dbg_en:1;
unsigned int     err_bl_zero:1;
unsigned int     err_blk_wxh_odd:1;
unsigned int     reserved_0:1;
unsigned int     max_wcmd_in_fifo:4;
unsigned int     max_rcmd_in_fifo:4;
unsigned int     max_wait_wdone:6;
unsigned int     max_wdata_in_fifo:7;
unsigned int     max_rdata_in_fifo:7;
}DC2_SYS_DC_64_ERR_STATUS_SB1;

typedef struct 
{
unsigned int     dbg_en:1;
unsigned int     err_bl_zero:1;
unsigned int     err_blk_wxh_odd:1;
unsigned int     reserved_0:1;
unsigned int     max_wcmd_in_fifo:4;
unsigned int     max_rcmd_in_fifo:4;
unsigned int     max_wait_wdone:6;
unsigned int     max_wdata_in_fifo:7;
unsigned int     max_rdata_in_fifo:7;
}DC2_SYS_DC_64_ERR_STATUS_SB3;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     DC_BIST_MODE_WRAP2:1;
unsigned int     DC_BIST_MODE_WRAP1:1;
unsigned int     DC_BIST_MODE_WRAP0:1;
}DC2_SYS_DC_64_BIST_MODE;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     DC_BIST_DONE_WRAP2:1;
unsigned int     DC_BIST_DONE_WRAP1:1;
unsigned int     DC_BIST_DONE_WRAP0:1;
}DC2_SYS_DC_64_BIST_DONE;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     DC_BIST_FAIL_GROUP_WRAP2:1;
unsigned int     DC_BIST_FAIL_GROUP_WRAP1:1;
unsigned int     DC_BIST_FAIL_GROUP_WRAP0:1;
}DC2_SYS_DC_64_BIST_FAIL;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     DC_DRF_MODE_WRAP2:1;
unsigned int     DC_DRF_MODE_WRAP1:1;
unsigned int     DC_DRF_MODE_WRAP0:1;
}DC2_SYS_DC_64_DRF;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     DC_DRF_RESUME_WRAP2:1;
unsigned int     DC_DRF_RESUME_WRAP1:1;
unsigned int     DC_DRF_RESUME_WRAP0:1;
}DC2_SYS_DC_64_DRF_RESUME;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     DC_DRF_DONE_WRAP2:1;
unsigned int     DC_DRF_DONE_WRAP1:1;
unsigned int     DC_DRF_DONE_WRAP0:1;
}DC2_SYS_DC_64_DRF_DONE;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     DC_DRF_PAUSE_WRAP2:1;
unsigned int     DC_DRF_PAUSE_WRAP1:1;
unsigned int     DC_DRF_PAUSE_WRAP0:1;
}DC2_SYS_DC_64_DRF_PAUSE;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     DC_DRF_FAIL_GROUP_WRAP2:1;
unsigned int     DC_DRF_FAIL_GROUP_WRAP1:1;
unsigned int     DC_DRF_FAIL_GROUP_WRAP0:1;
}DC2_SYS_DC_64_DRF_FAIL;

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
}DC2_SYS_DC_64_BIST_DETAIL;

typedef struct 
{
unsigned int     reserved_0:11;
unsigned int     RMEA:1;
unsigned int     RMA:4;
unsigned int     reserved_1:3;
unsigned int     RMEB:1;
unsigned int     RMB:4;
unsigned int     reserved_2:8;
}DC2_SYS_DC_64_BIST_RM;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     pc_go:1;
}DC2_SYS_DC_64_PC_CTRL;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     write_en_3:1;
unsigned int     pc_sys_prog2_sel:7;
unsigned int     write_en_2:1;
unsigned int     pc_sys_prog1_sel:7;
unsigned int     write_en_1:1;
unsigned int     pc_sys_prog0_sel:7;
}DC2_SYS_DC_PC_SYS_PROG_CTRL;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     reserved_1:1;
unsigned int     pc_sys_prog2_req_occur:1;
unsigned int     pc_sys_prog1_req_occur:1;
unsigned int     pc_sys_prog0_req_occur:1;
}DC2_SYS_DC_64_PC_SYS_PROG_CTRL1;

typedef struct 
{
unsigned int     sys_prog0_acc_lat:32;
}DC2_SYS_DC_PC_SYS_PROG_0_ACC_LAT;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     sys_prog0_max_lat:16;
}DC2_SYS_DC_PC_SYS_PROG_0_MAX_LAT;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     sys_prog0_req_num:24;
}DC2_SYS_DC_PC_SYS_PROG_0_REQ_NUM;

typedef struct 
{
unsigned int     sys_prog0_ack_num:32;
}DC2_SYS_DC_PC_SYS_PROG_0_ACK_NUM;

typedef struct 
{
unsigned int     sys_prog1_acc_lat:32;
}DC2_SYS_DC_PC_SYS_PROG_1_ACC_LAT;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     sys_prog1_max_lat:16;
}DC2_SYS_DC_PC_SYS_PROG_1_MAX_LAT;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     sys_prog1_req_num:24;
}DC2_SYS_DC_PC_SYS_PROG_1_REQ_NUM;

typedef struct 
{
unsigned int     sys_prog1_ack_num:32;
}DC2_SYS_DC_PC_SYS_PROG_1_ACK_NUM;

typedef struct 
{
unsigned int     sys_prog2_acc_lat:32;
}DC2_SYS_DC_PC_SYS_PROG_2_ACC_LAT;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     sys_prog2_max_lat:16;
}DC2_SYS_DC_PC_SYS_PROG_2_MAX_LAT;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     sys_prog2_req_num:24;
}DC2_SYS_DC_PC_SYS_PROG_2_REQ_NUM;

typedef struct 
{
unsigned int     sys_prog2_ack_num:32;
}DC2_SYS_DC_PC_SYS_PROG_2_ACK_NUM;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     sys0_hitend_cnt:16;
}DC2_SYS_DC_PC_SYS_PROG_0;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     sys1_hitend_cnt:16;
}DC2_SYS_DC_PC_SYS_PROG_1;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     sys2_hitend_cnt:16;
}DC2_SYS_DC_PC_SYS_PROG_2;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     enable:1;
}DC2_SYS_EXSRAM_CTRL;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     global_scramble_en:1;
}DC2_SYS_DC_GLOBAL_SCRAMBLE_CTRL;

typedef struct 
{
unsigned int     key1:16;
unsigned int     key0:16;
}DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_0;

typedef struct 
{
unsigned int     key3:16;
unsigned int     key2:16;
}DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_1;

typedef struct 
{
unsigned int     key5:16;
unsigned int     key4:16;
}DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_2;

typedef struct 
{
unsigned int     key7:16;
unsigned int     key6:16;
}DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_3;

typedef struct 
{
unsigned int     key9:16;
unsigned int     key8:16;
}DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_4;

typedef struct 
{
unsigned int     keyB:16;
unsigned int     keyA:16;
}DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_5;

typedef struct 
{
unsigned int     keyD:16;
unsigned int     keyC:16;
}DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_6;

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
}DC2_SYS_DC_MEM_PROTECT_CTRL;

typedef struct 
{
unsigned int     addr:20;
unsigned int     reserved_0:10;
unsigned int     y_limit:1;
unsigned int     reserved_1:1;
}DC2_SYS_DC_SECURE_MAX;

typedef struct 
{
unsigned int     addr:20;
unsigned int     reserved_0:12;
}DC2_SYS_DC_MEM_PROTECT_START;

typedef struct 
{
unsigned int     addr:20;
unsigned int     reserved_0:12;
}DC2_SYS_DC_MEM_PROTECT_END;

typedef struct 
{
unsigned int     reserved_0:27;
unsigned int     tp_kc:1;
unsigned int     emmc_kc:1;
unsigned int     nf_kc:1;
unsigned int     cp_kc:1;
unsigned int     md_kc:1;
}DC2_SYS_DC_KCPU_REGION;

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
}DC2_SYS_DC_MEM_CONTENT_CTRL;

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
}DC2_SYS_DC_SCRAMBLE_ACCESS;

typedef struct 
{
unsigned int     addr:20;
unsigned int     reserved_0:12;
}DC2_SYS_DC_MEM_SCRAMBLE_START;

typedef struct 
{
unsigned int     addr:20;
unsigned int     reserved_0:12;
}DC2_SYS_DC_MEM_SCRAMBLE_END;

typedef struct 
{
unsigned int     key1:16;
unsigned int     key0:16;
}DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0;

typedef struct 
{
unsigned int     key3:16;
unsigned int     key2:16;
}DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1;

typedef struct 
{
unsigned int     key5:16;
unsigned int     key4:16;
}DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2;

typedef struct 
{
unsigned int     key7:16;
unsigned int     key6:16;
}DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3;

typedef struct 
{
unsigned int     key9:16;
unsigned int     key8:16;
}DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4;

typedef struct 
{
unsigned int     keyB:16;
unsigned int     keyA:16;
}DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5;

typedef struct 
{
unsigned int     keyD:16;
unsigned int     keyC:16;
}DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6;

typedef struct 
{
unsigned int     key1:16;
unsigned int     key0:16;
}DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0;

typedef struct 
{
unsigned int     key3:16;
unsigned int     key2:16;
}DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1;

typedef struct 
{
unsigned int     key5:16;
unsigned int     key4:16;
}DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2;

typedef struct 
{
unsigned int     key7:16;
unsigned int     key6:16;
}DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3;

typedef struct 
{
unsigned int     key9:16;
unsigned int     key8:16;
}DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4;

typedef struct 
{
unsigned int     keyB:16;
unsigned int     keyA:16;
}DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5;

typedef struct 
{
unsigned int     keyD:16;
unsigned int     keyC:16;
}DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6;

typedef struct 
{
unsigned int     key1:16;
unsigned int     key0:16;
}DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0;

typedef struct 
{
unsigned int     key3:16;
unsigned int     key2:16;
}DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1;

typedef struct 
{
unsigned int     key5:16;
unsigned int     key4:16;
}DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2;

typedef struct 
{
unsigned int     key7:16;
unsigned int     key6:16;
}DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3;

typedef struct 
{
unsigned int     key9:16;
unsigned int     key8:16;
}DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4;

typedef struct 
{
unsigned int     keyB:16;
unsigned int     keyA:16;
}DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5;

typedef struct 
{
unsigned int     keyD:16;
unsigned int     keyC:16;
}DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6;

typedef struct 
{
unsigned int     reserved_0:14;
unsigned int     display_1_en:1;
unsigned int     display_0_en:1;
unsigned int     reserved_1:14;
unsigned int     display_1_scramble_en:1;
unsigned int     display_0_scramble_en:1;
}DC2_SYS_DC_MEM_DISPLAY_CTRL;

typedef struct 
{
unsigned int     addr:20;
unsigned int     reserved_0:12;
}DC2_SYS_DC_DISPLAY_START;

typedef struct 
{
unsigned int     addr:20;
unsigned int     reserved_0:12;
}DC2_SYS_DC_DISPLAY_END;

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
}DC2_SYS_DC_DISPLAY_ACCESS;

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
}DC2_SYS_DC_SECURE_INT_ENABLE;

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
}DC2_SYS_DC_SECURE_INT_STATUS;

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
}DC2_SYS_DC_SECURE_ERROR_INFO;

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
}DC2_SYS_DC_SECURE_KEY_INT_ENABLE;

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
}DC2_SYS_DC_SECURE_KEY_INT_STATUS;

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
}DC2_SYS_DC_SECURE_INT_ENABLE_SYS2;

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
}DC2_SYS_DC_SECURE_INT_STATUS_SYS2;

typedef struct 
{
unsigned int     reserved_0:9;
unsigned int     reserved_1:7;
unsigned int     reserved_2:1;
unsigned int     seq_read_error_id:7;
unsigned int     reserved_3:1;
unsigned int     seq_write_error_id:7;
}DC2_SYS_DC_SECURE_ERROR_INFO_SYS2;

#endif

#define DC2_SYS_DC_PICT_SET                                                           0x18003000
#define DC2_SYS_DC_PICT_SET_reg_addr                                                  "0xB8003000"
#define DC2_SYS_DC_PICT_SET_reg                                                       0xB8003000
#define set_DC2_SYS_DC_PICT_SET_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PICT_SET_reg)=data)
#define get_DC2_SYS_DC_PICT_SET_reg   (*((volatile unsigned int*) DC2_SYS_DC_PICT_SET_reg))
#define DC2_SYS_DC_PICT_SET_inst_adr                                                  "0x0000"
#define DC2_SYS_DC_PICT_SET_inst                                                      0x0000
#define DC2_SYS_DC_PICT_SET_pict_width_scale_shift                                    (17)
#define DC2_SYS_DC_PICT_SET_pict_width_scale_mask                                     (0x007E0000)
#define DC2_SYS_DC_PICT_SET_pict_width_scale(data)                                    (0x007E0000&((data)<<17))
#define DC2_SYS_DC_PICT_SET_pict_width_scale_src(data)                                ((0x007E0000&(data))>>17)
#define DC2_SYS_DC_PICT_SET_get_pict_width_scale(data)                                ((0x007E0000&(data))>>17)
#define DC2_SYS_DC_PICT_SET_pict_init_page_shift                                      (0)
#define DC2_SYS_DC_PICT_SET_pict_init_page_mask                                       (0x0001FFFF)
#define DC2_SYS_DC_PICT_SET_pict_init_page(data)                                      (0x0001FFFF&((data)<<0))
#define DC2_SYS_DC_PICT_SET_pict_init_page_src(data)                                  ((0x0001FFFF&(data))>>0)
#define DC2_SYS_DC_PICT_SET_get_pict_init_page(data)                                  ((0x0001FFFF&(data))>>0)


#define DC2_SYS_DC_SYS_MISC                                                           0x18003004
#define DC2_SYS_DC_SYS_MISC_reg_addr                                                  "0xB8003004"
#define DC2_SYS_DC_SYS_MISC_reg                                                       0xB8003004
#define set_DC2_SYS_DC_SYS_MISC_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_SYS_MISC_reg)=data)
#define get_DC2_SYS_DC_SYS_MISC_reg   (*((volatile unsigned int*) DC2_SYS_DC_SYS_MISC_reg))
#define DC2_SYS_DC_SYS_MISC_inst_adr                                                  "0x0001"
#define DC2_SYS_DC_SYS_MISC_inst                                                      0x0001
#define DC2_SYS_DC_SYS_MISC_dram_8g_used_shift                                        (28)
#define DC2_SYS_DC_SYS_MISC_dram_8g_used_mask                                         (0x10000000)
#define DC2_SYS_DC_SYS_MISC_dram_8g_used(data)                                        (0x10000000&((data)<<28))
#define DC2_SYS_DC_SYS_MISC_dram_8g_used_src(data)                                    ((0x10000000&(data))>>28)
#define DC2_SYS_DC_SYS_MISC_get_dram_8g_used(data)                                    ((0x10000000&(data))>>28)
#define DC2_SYS_DC_SYS_MISC_dram_4g_used_shift                                        (27)
#define DC2_SYS_DC_SYS_MISC_dram_4g_used_mask                                         (0x08000000)
#define DC2_SYS_DC_SYS_MISC_dram_4g_used(data)                                        (0x08000000&((data)<<27))
#define DC2_SYS_DC_SYS_MISC_dram_4g_used_src(data)                                    ((0x08000000&(data))>>27)
#define DC2_SYS_DC_SYS_MISC_get_dram_4g_used(data)                                    ((0x08000000&(data))>>27)
#define DC2_SYS_DC_SYS_MISC_ddr3_512_used_shift                                       (26)
#define DC2_SYS_DC_SYS_MISC_ddr3_512_used_mask                                        (0x04000000)
#define DC2_SYS_DC_SYS_MISC_ddr3_512_used(data)                                       (0x04000000&((data)<<26))
#define DC2_SYS_DC_SYS_MISC_ddr3_512_used_src(data)                                   ((0x04000000&(data))>>26)
#define DC2_SYS_DC_SYS_MISC_get_ddr3_512_used(data)                                   ((0x04000000&(data))>>26)
#define DC2_SYS_DC_SYS_MISC_dram_2g_used_shift                                        (25)
#define DC2_SYS_DC_SYS_MISC_dram_2g_used_mask                                         (0x02000000)
#define DC2_SYS_DC_SYS_MISC_dram_2g_used(data)                                        (0x02000000&((data)<<25))
#define DC2_SYS_DC_SYS_MISC_dram_2g_used_src(data)                                    ((0x02000000&(data))>>25)
#define DC2_SYS_DC_SYS_MISC_get_dram_2g_used(data)                                    ((0x02000000&(data))>>25)
#define DC2_SYS_DC_SYS_MISC_pre_arb_scheme_sel_shift                                  (24)
#define DC2_SYS_DC_SYS_MISC_pre_arb_scheme_sel_mask                                   (0x01000000)
#define DC2_SYS_DC_SYS_MISC_pre_arb_scheme_sel(data)                                  (0x01000000&((data)<<24))
#define DC2_SYS_DC_SYS_MISC_pre_arb_scheme_sel_src(data)                              ((0x01000000&(data))>>24)
#define DC2_SYS_DC_SYS_MISC_get_pre_arb_scheme_sel(data)                              ((0x01000000&(data))>>24)
#define DC2_SYS_DC_SYS_MISC_arb_mask_all_en_shift                                     (23)
#define DC2_SYS_DC_SYS_MISC_arb_mask_all_en_mask                                      (0x00800000)
#define DC2_SYS_DC_SYS_MISC_arb_mask_all_en(data)                                     (0x00800000&((data)<<23))
#define DC2_SYS_DC_SYS_MISC_arb_mask_all_en_src(data)                                 ((0x00800000&(data))>>23)
#define DC2_SYS_DC_SYS_MISC_get_arb_mask_all_en(data)                                 ((0x00800000&(data))>>23)
#define DC2_SYS_DC_SYS_MISC_ddr3_mapping_en_shift                                     (22)
#define DC2_SYS_DC_SYS_MISC_ddr3_mapping_en_mask                                      (0x00400000)
#define DC2_SYS_DC_SYS_MISC_ddr3_mapping_en(data)                                     (0x00400000&((data)<<22))
#define DC2_SYS_DC_SYS_MISC_ddr3_mapping_en_src(data)                                 ((0x00400000&(data))>>22)
#define DC2_SYS_DC_SYS_MISC_get_ddr3_mapping_en(data)                                 ((0x00400000&(data))>>22)
#define DC2_SYS_DC_SYS_MISC_self_lookback_mode_shift                                  (20)
#define DC2_SYS_DC_SYS_MISC_self_lookback_mode_mask                                   (0x00100000)
#define DC2_SYS_DC_SYS_MISC_self_lookback_mode(data)                                  (0x00100000&((data)<<20))
#define DC2_SYS_DC_SYS_MISC_self_lookback_mode_src(data)                              ((0x00100000&(data))>>20)
#define DC2_SYS_DC_SYS_MISC_get_self_lookback_mode(data)                              ((0x00100000&(data))>>20)
#define DC2_SYS_DC_SYS_MISC_mem_num_shift                                             (19)
#define DC2_SYS_DC_SYS_MISC_mem_num_mask                                              (0x00080000)
#define DC2_SYS_DC_SYS_MISC_mem_num(data)                                             (0x00080000&((data)<<19))
#define DC2_SYS_DC_SYS_MISC_mem_num_src(data)                                         ((0x00080000&(data))>>19)
#define DC2_SYS_DC_SYS_MISC_get_mem_num(data)                                         ((0x00080000&(data))>>19)
#define DC2_SYS_DC_SYS_MISC_page_size_shift                                           (16)
#define DC2_SYS_DC_SYS_MISC_page_size_mask                                            (0x00030000)
#define DC2_SYS_DC_SYS_MISC_page_size(data)                                           (0x00030000&((data)<<16))
#define DC2_SYS_DC_SYS_MISC_page_size_src(data)                                       ((0x00030000&(data))>>16)
#define DC2_SYS_DC_SYS_MISC_get_page_size(data)                                       ((0x00030000&(data))>>16)
#define DC2_SYS_DC_SYS_MISC_max_bl_size_shift                                         (9)
#define DC2_SYS_DC_SYS_MISC_max_bl_size_mask                                          (0x00000200)
#define DC2_SYS_DC_SYS_MISC_max_bl_size(data)                                         (0x00000200&((data)<<9))
#define DC2_SYS_DC_SYS_MISC_max_bl_size_src(data)                                     ((0x00000200&(data))>>9)
#define DC2_SYS_DC_SYS_MISC_get_max_bl_size(data)                                     ((0x00000200&(data))>>9)
#define DC2_SYS_DC_SYS_MISC_en_max_bl_limit_shift                                     (8)
#define DC2_SYS_DC_SYS_MISC_en_max_bl_limit_mask                                      (0x00000100)
#define DC2_SYS_DC_SYS_MISC_en_max_bl_limit(data)                                     (0x00000100&((data)<<8))
#define DC2_SYS_DC_SYS_MISC_en_max_bl_limit_src(data)                                 ((0x00000100&(data))>>8)
#define DC2_SYS_DC_SYS_MISC_get_en_max_bl_limit(data)                                 ((0x00000100&(data))>>8)
#define DC2_SYS_DC_SYS_MISC_small_dram_4g_shift                                       (7)
#define DC2_SYS_DC_SYS_MISC_small_dram_4g_mask                                        (0x00000080)
#define DC2_SYS_DC_SYS_MISC_small_dram_4g(data)                                       (0x00000080&((data)<<7))
#define DC2_SYS_DC_SYS_MISC_small_dram_4g_src(data)                                   ((0x00000080&(data))>>7)
#define DC2_SYS_DC_SYS_MISC_get_small_dram_4g(data)                                   ((0x00000080&(data))>>7)
#define DC2_SYS_DC_SYS_MISC_small_dram_2g_shift                                       (6)
#define DC2_SYS_DC_SYS_MISC_small_dram_2g_mask                                        (0x00000040)
#define DC2_SYS_DC_SYS_MISC_small_dram_2g(data)                                       (0x00000040&((data)<<6))
#define DC2_SYS_DC_SYS_MISC_small_dram_2g_src(data)                                   ((0x00000040&(data))>>6)
#define DC2_SYS_DC_SYS_MISC_get_small_dram_2g(data)                                   ((0x00000040&(data))>>6)
#define DC2_SYS_DC_SYS_MISC_small_dram_1g_shift                                       (5)
#define DC2_SYS_DC_SYS_MISC_small_dram_1g_mask                                        (0x00000020)
#define DC2_SYS_DC_SYS_MISC_small_dram_1g(data)                                       (0x00000020&((data)<<5))
#define DC2_SYS_DC_SYS_MISC_small_dram_1g_src(data)                                   ((0x00000020&(data))>>5)
#define DC2_SYS_DC_SYS_MISC_get_small_dram_1g(data)                                   ((0x00000020&(data))>>5)
#define DC2_SYS_DC_SYS_MISC_small_dram_512m_shift                                     (4)
#define DC2_SYS_DC_SYS_MISC_small_dram_512m_mask                                      (0x00000010)
#define DC2_SYS_DC_SYS_MISC_small_dram_512m(data)                                     (0x00000010&((data)<<4))
#define DC2_SYS_DC_SYS_MISC_small_dram_512m_src(data)                                 ((0x00000010&(data))>>4)
#define DC2_SYS_DC_SYS_MISC_get_small_dram_512m(data)                                 ((0x00000010&(data))>>4)
#define DC2_SYS_DC_SYS_MISC_en_2ddr_diff_size_shift                                   (0)
#define DC2_SYS_DC_SYS_MISC_en_2ddr_diff_size_mask                                    (0x00000001)
#define DC2_SYS_DC_SYS_MISC_en_2ddr_diff_size(data)                                   (0x00000001&((data)<<0))
#define DC2_SYS_DC_SYS_MISC_en_2ddr_diff_size_src(data)                               ((0x00000001&(data))>>0)
#define DC2_SYS_DC_SYS_MISC_get_en_2ddr_diff_size(data)                               ((0x00000001&(data))>>0)


#define DC2_SYS_DC_PIC_OFFSET_X_DETECTION                                             0x18003010
#define DC2_SYS_DC_PIC_OFFSET_X_DETECTION_reg_addr                                    "0xB8003010"
#define DC2_SYS_DC_PIC_OFFSET_X_DETECTION_reg                                         0xB8003010
#define set_DC2_SYS_DC_PIC_OFFSET_X_DETECTION_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PIC_OFFSET_X_DETECTION_reg)=data)
#define get_DC2_SYS_DC_PIC_OFFSET_X_DETECTION_reg   (*((volatile unsigned int*) DC2_SYS_DC_PIC_OFFSET_X_DETECTION_reg))
#define DC2_SYS_DC_PIC_OFFSET_X_DETECTION_inst_adr                                    "0x0004"
#define DC2_SYS_DC_PIC_OFFSET_X_DETECTION_inst                                        0x0004
#define DC2_SYS_DC_PIC_OFFSET_X_DETECTION_enable_shift                                (0)
#define DC2_SYS_DC_PIC_OFFSET_X_DETECTION_enable_mask                                 (0x00000001)
#define DC2_SYS_DC_PIC_OFFSET_X_DETECTION_enable(data)                                (0x00000001&((data)<<0))
#define DC2_SYS_DC_PIC_OFFSET_X_DETECTION_enable_src(data)                            ((0x00000001&(data))>>0)
#define DC2_SYS_DC_PIC_OFFSET_X_DETECTION_get_enable(data)                            ((0x00000001&(data))>>0)


#define DC2_SYS_DC_PICT_SET_OFFSET                                                    0x18003020
#define DC2_SYS_DC_PICT_SET_OFFSET_reg_addr                                           "0xB8003020"
#define DC2_SYS_DC_PICT_SET_OFFSET_reg                                                0xB8003020
#define set_DC2_SYS_DC_PICT_SET_OFFSET_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PICT_SET_OFFSET_reg)=data)
#define get_DC2_SYS_DC_PICT_SET_OFFSET_reg   (*((volatile unsigned int*) DC2_SYS_DC_PICT_SET_OFFSET_reg))
#define DC2_SYS_DC_PICT_SET_OFFSET_inst_adr                                           "0x0008"
#define DC2_SYS_DC_PICT_SET_OFFSET_inst                                               0x0008
#define DC2_SYS_DC_PICT_SET_OFFSET_pict_set_num_shift                                 (24)
#define DC2_SYS_DC_PICT_SET_OFFSET_pict_set_num_mask                                  (0xFF000000)
#define DC2_SYS_DC_PICT_SET_OFFSET_pict_set_num(data)                                 (0xFF000000&((data)<<24))
#define DC2_SYS_DC_PICT_SET_OFFSET_pict_set_num_src(data)                             ((0xFF000000&(data))>>24)
#define DC2_SYS_DC_PICT_SET_OFFSET_get_pict_set_num(data)                             ((0xFF000000&(data))>>24)
#define DC2_SYS_DC_PICT_SET_OFFSET_pict_offset_rd_shift                               (23)
#define DC2_SYS_DC_PICT_SET_OFFSET_pict_offset_rd_mask                                (0x00800000)
#define DC2_SYS_DC_PICT_SET_OFFSET_pict_offset_rd(data)                               (0x00800000&((data)<<23))
#define DC2_SYS_DC_PICT_SET_OFFSET_pict_offset_rd_src(data)                           ((0x00800000&(data))>>23)
#define DC2_SYS_DC_PICT_SET_OFFSET_get_pict_offset_rd(data)                           ((0x00800000&(data))>>23)
#define DC2_SYS_DC_PICT_SET_OFFSET_pict_set_wide_shift                                (20)
#define DC2_SYS_DC_PICT_SET_OFFSET_pict_set_wide_mask                                 (0x00100000)
#define DC2_SYS_DC_PICT_SET_OFFSET_pict_set_wide(data)                                (0x00100000&((data)<<20))
#define DC2_SYS_DC_PICT_SET_OFFSET_pict_set_wide_src(data)                            ((0x00100000&(data))>>20)
#define DC2_SYS_DC_PICT_SET_OFFSET_get_pict_set_wide(data)                            ((0x00100000&(data))>>20)
#define DC2_SYS_DC_PICT_SET_OFFSET_pict_set_offset_y_shift                            (10)
#define DC2_SYS_DC_PICT_SET_OFFSET_pict_set_offset_y_mask                             (0x000FFC00)
#define DC2_SYS_DC_PICT_SET_OFFSET_pict_set_offset_y(data)                            (0x000FFC00&((data)<<10))
#define DC2_SYS_DC_PICT_SET_OFFSET_pict_set_offset_y_src(data)                        ((0x000FFC00&(data))>>10)
#define DC2_SYS_DC_PICT_SET_OFFSET_get_pict_set_offset_y(data)                        ((0x000FFC00&(data))>>10)
#define DC2_SYS_DC_PICT_SET_OFFSET_pict_set_offset_x_shift                            (0)
#define DC2_SYS_DC_PICT_SET_OFFSET_pict_set_offset_x_mask                             (0x000003FF)
#define DC2_SYS_DC_PICT_SET_OFFSET_pict_set_offset_x(data)                            (0x000003FF&((data)<<0))
#define DC2_SYS_DC_PICT_SET_OFFSET_pict_set_offset_x_src(data)                        ((0x000003FF&(data))>>0)
#define DC2_SYS_DC_PICT_SET_OFFSET_get_pict_set_offset_x(data)                        ((0x000003FF&(data))>>0)


#define DC2_SYS_DC_REQ_STATUS                                                         0x18003024
#define DC2_SYS_DC_REQ_STATUS_reg_addr                                                "0xB8003024"
#define DC2_SYS_DC_REQ_STATUS_reg                                                     0xB8003024
#define set_DC2_SYS_DC_REQ_STATUS_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_REQ_STATUS_reg)=data)
#define get_DC2_SYS_DC_REQ_STATUS_reg   (*((volatile unsigned int*) DC2_SYS_DC_REQ_STATUS_reg))
#define DC2_SYS_DC_REQ_STATUS_inst_adr                                                "0x0009"
#define DC2_SYS_DC_REQ_STATUS_inst                                                    0x0009
#define DC2_SYS_DC_REQ_STATUS_req_pending_shift                                       (16)
#define DC2_SYS_DC_REQ_STATUS_req_pending_mask                                        (0x00010000)
#define DC2_SYS_DC_REQ_STATUS_req_pending(data)                                       (0x00010000&((data)<<16))
#define DC2_SYS_DC_REQ_STATUS_req_pending_src(data)                                   ((0x00010000&(data))>>16)
#define DC2_SYS_DC_REQ_STATUS_get_req_pending(data)                                   ((0x00010000&(data))>>16)
#define DC2_SYS_DC_REQ_STATUS_req_id_shift                                            (0)
#define DC2_SYS_DC_REQ_STATUS_req_id_mask                                             (0x00001FFF)
#define DC2_SYS_DC_REQ_STATUS_req_id(data)                                            (0x00001FFF&((data)<<0))
#define DC2_SYS_DC_REQ_STATUS_req_id_src(data)                                        ((0x00001FFF&(data))>>0)
#define DC2_SYS_DC_REQ_STATUS_get_req_id(data)                                        ((0x00001FFF&(data))>>0)


#define DC2_SYS_DC_SYS_MISC2                                                          0x18003028
#define DC2_SYS_DC_SYS_MISC2_reg_addr                                                 "0xB8003028"
#define DC2_SYS_DC_SYS_MISC2_reg                                                      0xB8003028
#define set_DC2_SYS_DC_SYS_MISC2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_SYS_MISC2_reg)=data)
#define get_DC2_SYS_DC_SYS_MISC2_reg   (*((volatile unsigned int*) DC2_SYS_DC_SYS_MISC2_reg))
#define DC2_SYS_DC_SYS_MISC2_inst_adr                                                 "0x000A"
#define DC2_SYS_DC_SYS_MISC2_inst                                                     0x000A
#define DC2_SYS_DC_SYS_MISC2_pre_arb_merge_shift                                      (31)
#define DC2_SYS_DC_SYS_MISC2_pre_arb_merge_mask                                       (0x80000000)
#define DC2_SYS_DC_SYS_MISC2_pre_arb_merge(data)                                      (0x80000000&((data)<<31))
#define DC2_SYS_DC_SYS_MISC2_pre_arb_merge_src(data)                                  ((0x80000000&(data))>>31)
#define DC2_SYS_DC_SYS_MISC2_get_pre_arb_merge(data)                                  ((0x80000000&(data))>>31)
#define DC2_SYS_DC_SYS_MISC2_qfifo_cnt_full_threshold_shift                           (24)
#define DC2_SYS_DC_SYS_MISC2_qfifo_cnt_full_threshold_mask                            (0x1F000000)
#define DC2_SYS_DC_SYS_MISC2_qfifo_cnt_full_threshold(data)                           (0x1F000000&((data)<<24))
#define DC2_SYS_DC_SYS_MISC2_qfifo_cnt_full_threshold_src(data)                       ((0x1F000000&(data))>>24)
#define DC2_SYS_DC_SYS_MISC2_get_qfifo_cnt_full_threshold(data)                       ((0x1F000000&(data))>>24)
#define DC2_SYS_DC_SYS_MISC2_full_cmd_count_shift                                     (20)
#define DC2_SYS_DC_SYS_MISC2_full_cmd_count_mask                                      (0x00F00000)
#define DC2_SYS_DC_SYS_MISC2_full_cmd_count(data)                                     (0x00F00000&((data)<<20))
#define DC2_SYS_DC_SYS_MISC2_full_cmd_count_src(data)                                 ((0x00F00000&(data))>>20)
#define DC2_SYS_DC_SYS_MISC2_get_full_cmd_count(data)                                 ((0x00F00000&(data))>>20)
#define DC2_SYS_DC_SYS_MISC2_pre_tra_rd_cnt_shift                                     (10)
#define DC2_SYS_DC_SYS_MISC2_pre_tra_rd_cnt_mask                                      (0x000FFC00)
#define DC2_SYS_DC_SYS_MISC2_pre_tra_rd_cnt(data)                                     (0x000FFC00&((data)<<10))
#define DC2_SYS_DC_SYS_MISC2_pre_tra_rd_cnt_src(data)                                 ((0x000FFC00&(data))>>10)
#define DC2_SYS_DC_SYS_MISC2_get_pre_tra_rd_cnt(data)                                 ((0x000FFC00&(data))>>10)
#define DC2_SYS_DC_SYS_MISC2_pre_tra_wr_cnt_shift                                     (0)
#define DC2_SYS_DC_SYS_MISC2_pre_tra_wr_cnt_mask                                      (0x000003FF)
#define DC2_SYS_DC_SYS_MISC2_pre_tra_wr_cnt(data)                                     (0x000003FF&((data)<<0))
#define DC2_SYS_DC_SYS_MISC2_pre_tra_wr_cnt_src(data)                                 ((0x000003FF&(data))>>0)
#define DC2_SYS_DC_SYS_MISC2_get_pre_tra_wr_cnt(data)                                 ((0x000003FF&(data))>>0)


#define DC2_SYS_DC_SYS_MISC3                                                          0x1800302C
#define DC2_SYS_DC_SYS_MISC3_reg_addr                                                 "0xB800302C"
#define DC2_SYS_DC_SYS_MISC3_reg                                                      0xB800302C
#define set_DC2_SYS_DC_SYS_MISC3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_SYS_MISC3_reg)=data)
#define get_DC2_SYS_DC_SYS_MISC3_reg   (*((volatile unsigned int*) DC2_SYS_DC_SYS_MISC3_reg))
#define DC2_SYS_DC_SYS_MISC3_inst_adr                                                 "0x000B"
#define DC2_SYS_DC_SYS_MISC3_inst                                                     0x000B
#define DC2_SYS_DC_SYS_MISC3_wfifo_cnt_full_threshold_shift                           (24)
#define DC2_SYS_DC_SYS_MISC3_wfifo_cnt_full_threshold_mask                            (0x3F000000)
#define DC2_SYS_DC_SYS_MISC3_wfifo_cnt_full_threshold(data)                           (0x3F000000&((data)<<24))
#define DC2_SYS_DC_SYS_MISC3_wfifo_cnt_full_threshold_src(data)                       ((0x3F000000&(data))>>24)
#define DC2_SYS_DC_SYS_MISC3_get_wfifo_cnt_full_threshold(data)                       ((0x3F000000&(data))>>24)
#define DC2_SYS_DC_SYS_MISC3_memc_cmd_queue_flush_shift                               (21)
#define DC2_SYS_DC_SYS_MISC3_memc_cmd_queue_flush_mask                                (0x00200000)
#define DC2_SYS_DC_SYS_MISC3_memc_cmd_queue_flush(data)                               (0x00200000&((data)<<21))
#define DC2_SYS_DC_SYS_MISC3_memc_cmd_queue_flush_src(data)                           ((0x00200000&(data))>>21)
#define DC2_SYS_DC_SYS_MISC3_get_memc_cmd_queue_flush(data)                           ((0x00200000&(data))>>21)
#define DC2_SYS_DC_SYS_MISC3_memc_cmd_grp_disable_shift                               (20)
#define DC2_SYS_DC_SYS_MISC3_memc_cmd_grp_disable_mask                                (0x00100000)
#define DC2_SYS_DC_SYS_MISC3_memc_cmd_grp_disable(data)                               (0x00100000&((data)<<20))
#define DC2_SYS_DC_SYS_MISC3_memc_cmd_grp_disable_src(data)                           ((0x00100000&(data))>>20)
#define DC2_SYS_DC_SYS_MISC3_get_memc_cmd_grp_disable(data)                           ((0x00100000&(data))>>20)
#define DC2_SYS_DC_SYS_MISC3_gde2_cmd_queue_flush_shift                               (19)
#define DC2_SYS_DC_SYS_MISC3_gde2_cmd_queue_flush_mask                                (0x00080000)
#define DC2_SYS_DC_SYS_MISC3_gde2_cmd_queue_flush(data)                               (0x00080000&((data)<<19))
#define DC2_SYS_DC_SYS_MISC3_gde2_cmd_queue_flush_src(data)                           ((0x00080000&(data))>>19)
#define DC2_SYS_DC_SYS_MISC3_get_gde2_cmd_queue_flush(data)                           ((0x00080000&(data))>>19)
#define DC2_SYS_DC_SYS_MISC3_gde2_cmd_grp_disable_shift                               (18)
#define DC2_SYS_DC_SYS_MISC3_gde2_cmd_grp_disable_mask                                (0x00040000)
#define DC2_SYS_DC_SYS_MISC3_gde2_cmd_grp_disable(data)                               (0x00040000&((data)<<18))
#define DC2_SYS_DC_SYS_MISC3_gde2_cmd_grp_disable_src(data)                           ((0x00040000&(data))>>18)
#define DC2_SYS_DC_SYS_MISC3_get_gde2_cmd_grp_disable(data)                           ((0x00040000&(data))>>18)
#define DC2_SYS_DC_SYS_MISC3_ve2_cmd_queue_flush_shift                                (17)
#define DC2_SYS_DC_SYS_MISC3_ve2_cmd_queue_flush_mask                                 (0x00020000)
#define DC2_SYS_DC_SYS_MISC3_ve2_cmd_queue_flush(data)                                (0x00020000&((data)<<17))
#define DC2_SYS_DC_SYS_MISC3_ve2_cmd_queue_flush_src(data)                            ((0x00020000&(data))>>17)
#define DC2_SYS_DC_SYS_MISC3_get_ve2_cmd_queue_flush(data)                            ((0x00020000&(data))>>17)
#define DC2_SYS_DC_SYS_MISC3_ve2_cmd_grp_disable_shift                                (16)
#define DC2_SYS_DC_SYS_MISC3_ve2_cmd_grp_disable_mask                                 (0x00010000)
#define DC2_SYS_DC_SYS_MISC3_ve2_cmd_grp_disable(data)                                (0x00010000&((data)<<16))
#define DC2_SYS_DC_SYS_MISC3_ve2_cmd_grp_disable_src(data)                            ((0x00010000&(data))>>16)
#define DC2_SYS_DC_SYS_MISC3_get_ve2_cmd_grp_disable(data)                            ((0x00010000&(data))>>16)
#define DC2_SYS_DC_SYS_MISC3_ve_cmd_queue_flush_shift                                 (9)
#define DC2_SYS_DC_SYS_MISC3_ve_cmd_queue_flush_mask                                  (0x00000200)
#define DC2_SYS_DC_SYS_MISC3_ve_cmd_queue_flush(data)                                 (0x00000200&((data)<<9))
#define DC2_SYS_DC_SYS_MISC3_ve_cmd_queue_flush_src(data)                             ((0x00000200&(data))>>9)
#define DC2_SYS_DC_SYS_MISC3_get_ve_cmd_queue_flush(data)                             ((0x00000200&(data))>>9)
#define DC2_SYS_DC_SYS_MISC3_ve_cmd_grp_disable_shift                                 (8)
#define DC2_SYS_DC_SYS_MISC3_ve_cmd_grp_disable_mask                                  (0x00000100)
#define DC2_SYS_DC_SYS_MISC3_ve_cmd_grp_disable(data)                                 (0x00000100&((data)<<8))
#define DC2_SYS_DC_SYS_MISC3_ve_cmd_grp_disable_src(data)                             ((0x00000100&(data))>>8)
#define DC2_SYS_DC_SYS_MISC3_get_ve_cmd_grp_disable(data)                             ((0x00000100&(data))>>8)
#define DC2_SYS_DC_SYS_MISC3_tvsb4_cmd_queue_flush_shift                              (7)
#define DC2_SYS_DC_SYS_MISC3_tvsb4_cmd_queue_flush_mask                               (0x00000080)
#define DC2_SYS_DC_SYS_MISC3_tvsb4_cmd_queue_flush(data)                              (0x00000080&((data)<<7))
#define DC2_SYS_DC_SYS_MISC3_tvsb4_cmd_queue_flush_src(data)                          ((0x00000080&(data))>>7)
#define DC2_SYS_DC_SYS_MISC3_get_tvsb4_cmd_queue_flush(data)                          ((0x00000080&(data))>>7)
#define DC2_SYS_DC_SYS_MISC3_tvsb4_cmd_grp_disable_shift                              (6)
#define DC2_SYS_DC_SYS_MISC3_tvsb4_cmd_grp_disable_mask                               (0x00000040)
#define DC2_SYS_DC_SYS_MISC3_tvsb4_cmd_grp_disable(data)                              (0x00000040&((data)<<6))
#define DC2_SYS_DC_SYS_MISC3_tvsb4_cmd_grp_disable_src(data)                          ((0x00000040&(data))>>6)
#define DC2_SYS_DC_SYS_MISC3_get_tvsb4_cmd_grp_disable(data)                          ((0x00000040&(data))>>6)
#define DC2_SYS_DC_SYS_MISC3_tvsb3_cmd_queue_flush_shift                              (5)
#define DC2_SYS_DC_SYS_MISC3_tvsb3_cmd_queue_flush_mask                               (0x00000020)
#define DC2_SYS_DC_SYS_MISC3_tvsb3_cmd_queue_flush(data)                              (0x00000020&((data)<<5))
#define DC2_SYS_DC_SYS_MISC3_tvsb3_cmd_queue_flush_src(data)                          ((0x00000020&(data))>>5)
#define DC2_SYS_DC_SYS_MISC3_get_tvsb3_cmd_queue_flush(data)                          ((0x00000020&(data))>>5)
#define DC2_SYS_DC_SYS_MISC3_tvsb3_cmd_grp_disable_shift                              (4)
#define DC2_SYS_DC_SYS_MISC3_tvsb3_cmd_grp_disable_mask                               (0x00000010)
#define DC2_SYS_DC_SYS_MISC3_tvsb3_cmd_grp_disable(data)                              (0x00000010&((data)<<4))
#define DC2_SYS_DC_SYS_MISC3_tvsb3_cmd_grp_disable_src(data)                          ((0x00000010&(data))>>4)
#define DC2_SYS_DC_SYS_MISC3_get_tvsb3_cmd_grp_disable(data)                          ((0x00000010&(data))>>4)
#define DC2_SYS_DC_SYS_MISC3_enable_arb_delay_by_tv_sb1_grant_shift                   (2)
#define DC2_SYS_DC_SYS_MISC3_enable_arb_delay_by_tv_sb1_grant_mask                    (0x00000004)
#define DC2_SYS_DC_SYS_MISC3_enable_arb_delay_by_tv_sb1_grant(data)                   (0x00000004&((data)<<2))
#define DC2_SYS_DC_SYS_MISC3_enable_arb_delay_by_tv_sb1_grant_src(data)               ((0x00000004&(data))>>2)
#define DC2_SYS_DC_SYS_MISC3_get_enable_arb_delay_by_tv_sb1_grant(data)               ((0x00000004&(data))>>2)
#define DC2_SYS_DC_SYS_MISC3_gde_cmd_queue_flush_shift                                (1)
#define DC2_SYS_DC_SYS_MISC3_gde_cmd_queue_flush_mask                                 (0x00000002)
#define DC2_SYS_DC_SYS_MISC3_gde_cmd_queue_flush(data)                                (0x00000002&((data)<<1))
#define DC2_SYS_DC_SYS_MISC3_gde_cmd_queue_flush_src(data)                            ((0x00000002&(data))>>1)
#define DC2_SYS_DC_SYS_MISC3_get_gde_cmd_queue_flush(data)                            ((0x00000002&(data))>>1)
#define DC2_SYS_DC_SYS_MISC3_gde_cmd_grp_disable_shift                                (0)
#define DC2_SYS_DC_SYS_MISC3_gde_cmd_grp_disable_mask                                 (0x00000001)
#define DC2_SYS_DC_SYS_MISC3_gde_cmd_grp_disable(data)                                (0x00000001&((data)<<0))
#define DC2_SYS_DC_SYS_MISC3_gde_cmd_grp_disable_src(data)                            ((0x00000001&(data))>>0)
#define DC2_SYS_DC_SYS_MISC3_get_gde_cmd_grp_disable(data)                            ((0x00000001&(data))>>0)


#define DC2_SYS_DC_SFMODE0                                                            0x18003040
#define DC2_SYS_DC_SFMODE0_reg_addr                                                   "0xB8003040"
#define DC2_SYS_DC_SFMODE0_reg                                                        0xB8003040
#define set_DC2_SYS_DC_SFMODE0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_SFMODE0_reg)=data)
#define get_DC2_SYS_DC_SFMODE0_reg   (*((volatile unsigned int*) DC2_SYS_DC_SFMODE0_reg))
#define DC2_SYS_DC_SFMODE0_inst_adr                                                   "0x0010"
#define DC2_SYS_DC_SFMODE0_inst                                                       0x0010
#define DC2_SYS_DC_SFMODE0_sfmode_pattern0_shift                                      (0)
#define DC2_SYS_DC_SFMODE0_sfmode_pattern0_mask                                       (0xFFFFFFFF)
#define DC2_SYS_DC_SFMODE0_sfmode_pattern0(data)                                      (0xFFFFFFFF&((data)<<0))
#define DC2_SYS_DC_SFMODE0_sfmode_pattern0_src(data)                                  ((0xFFFFFFFF&(data))>>0)
#define DC2_SYS_DC_SFMODE0_get_sfmode_pattern0(data)                                  ((0xFFFFFFFF&(data))>>0)


#define DC2_SYS_DC_SFMODE1                                                            0x18003044
#define DC2_SYS_DC_SFMODE1_reg_addr                                                   "0xB8003044"
#define DC2_SYS_DC_SFMODE1_reg                                                        0xB8003044
#define set_DC2_SYS_DC_SFMODE1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_SFMODE1_reg)=data)
#define get_DC2_SYS_DC_SFMODE1_reg   (*((volatile unsigned int*) DC2_SYS_DC_SFMODE1_reg))
#define DC2_SYS_DC_SFMODE1_inst_adr                                                   "0x0011"
#define DC2_SYS_DC_SFMODE1_inst                                                       0x0011
#define DC2_SYS_DC_SFMODE1_sfmode_pattern1_shift                                      (0)
#define DC2_SYS_DC_SFMODE1_sfmode_pattern1_mask                                       (0xFFFFFFFF)
#define DC2_SYS_DC_SFMODE1_sfmode_pattern1(data)                                      (0xFFFFFFFF&((data)<<0))
#define DC2_SYS_DC_SFMODE1_sfmode_pattern1_src(data)                                  ((0xFFFFFFFF&(data))>>0)
#define DC2_SYS_DC_SFMODE1_get_sfmode_pattern1(data)                                  ((0xFFFFFFFF&(data))>>0)


#define DC2_SYS_DC_SFMODE2                                                            0x18003048
#define DC2_SYS_DC_SFMODE2_reg_addr                                                   "0xB8003048"
#define DC2_SYS_DC_SFMODE2_reg                                                        0xB8003048
#define set_DC2_SYS_DC_SFMODE2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_SFMODE2_reg)=data)
#define get_DC2_SYS_DC_SFMODE2_reg   (*((volatile unsigned int*) DC2_SYS_DC_SFMODE2_reg))
#define DC2_SYS_DC_SFMODE2_inst_adr                                                   "0x0012"
#define DC2_SYS_DC_SFMODE2_inst                                                       0x0012
#define DC2_SYS_DC_SFMODE2_sfmode_pattern2_shift                                      (0)
#define DC2_SYS_DC_SFMODE2_sfmode_pattern2_mask                                       (0xFFFFFFFF)
#define DC2_SYS_DC_SFMODE2_sfmode_pattern2(data)                                      (0xFFFFFFFF&((data)<<0))
#define DC2_SYS_DC_SFMODE2_sfmode_pattern2_src(data)                                  ((0xFFFFFFFF&(data))>>0)
#define DC2_SYS_DC_SFMODE2_get_sfmode_pattern2(data)                                  ((0xFFFFFFFF&(data))>>0)


#define DC2_SYS_DC_SFMODE3                                                            0x1800304C
#define DC2_SYS_DC_SFMODE3_reg_addr                                                   "0xB800304C"
#define DC2_SYS_DC_SFMODE3_reg                                                        0xB800304C
#define set_DC2_SYS_DC_SFMODE3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_SFMODE3_reg)=data)
#define get_DC2_SYS_DC_SFMODE3_reg   (*((volatile unsigned int*) DC2_SYS_DC_SFMODE3_reg))
#define DC2_SYS_DC_SFMODE3_inst_adr                                                   "0x0013"
#define DC2_SYS_DC_SFMODE3_inst                                                       0x0013
#define DC2_SYS_DC_SFMODE3_sfmode_pattern3_shift                                      (0)
#define DC2_SYS_DC_SFMODE3_sfmode_pattern3_mask                                       (0xFFFFFFFF)
#define DC2_SYS_DC_SFMODE3_sfmode_pattern3(data)                                      (0xFFFFFFFF&((data)<<0))
#define DC2_SYS_DC_SFMODE3_sfmode_pattern3_src(data)                                  ((0xFFFFFFFF&(data))>>0)
#define DC2_SYS_DC_SFMODE3_get_sfmode_pattern3(data)                                  ((0xFFFFFFFF&(data))>>0)


#define DC2_SYS_DC_SFMODE_CMP0                                                        0x18003050
#define DC2_SYS_DC_SFMODE_CMP0_reg_addr                                               "0xB8003050"
#define DC2_SYS_DC_SFMODE_CMP0_reg                                                    0xB8003050
#define set_DC2_SYS_DC_SFMODE_CMP0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_SFMODE_CMP0_reg)=data)
#define get_DC2_SYS_DC_SFMODE_CMP0_reg   (*((volatile unsigned int*) DC2_SYS_DC_SFMODE_CMP0_reg))
#define DC2_SYS_DC_SFMODE_CMP0_inst_adr                                               "0x0014"
#define DC2_SYS_DC_SFMODE_CMP0_inst                                                   0x0014
#define DC2_SYS_DC_SFMODE_CMP0_sfmode_cmp_rlt0_shift                                  (0)
#define DC2_SYS_DC_SFMODE_CMP0_sfmode_cmp_rlt0_mask                                   (0xFFFFFFFF)
#define DC2_SYS_DC_SFMODE_CMP0_sfmode_cmp_rlt0(data)                                  (0xFFFFFFFF&((data)<<0))
#define DC2_SYS_DC_SFMODE_CMP0_sfmode_cmp_rlt0_src(data)                              ((0xFFFFFFFF&(data))>>0)
#define DC2_SYS_DC_SFMODE_CMP0_get_sfmode_cmp_rlt0(data)                              ((0xFFFFFFFF&(data))>>0)


#define DC2_SYS_DC_SFMODE_CMP1                                                        0x18003054
#define DC2_SYS_DC_SFMODE_CMP1_reg_addr                                               "0xB8003054"
#define DC2_SYS_DC_SFMODE_CMP1_reg                                                    0xB8003054
#define set_DC2_SYS_DC_SFMODE_CMP1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_SFMODE_CMP1_reg)=data)
#define get_DC2_SYS_DC_SFMODE_CMP1_reg   (*((volatile unsigned int*) DC2_SYS_DC_SFMODE_CMP1_reg))
#define DC2_SYS_DC_SFMODE_CMP1_inst_adr                                               "0x0015"
#define DC2_SYS_DC_SFMODE_CMP1_inst                                                   0x0015
#define DC2_SYS_DC_SFMODE_CMP1_sfmode_cmp_rlt1_shift                                  (0)
#define DC2_SYS_DC_SFMODE_CMP1_sfmode_cmp_rlt1_mask                                   (0xFFFFFFFF)
#define DC2_SYS_DC_SFMODE_CMP1_sfmode_cmp_rlt1(data)                                  (0xFFFFFFFF&((data)<<0))
#define DC2_SYS_DC_SFMODE_CMP1_sfmode_cmp_rlt1_src(data)                              ((0xFFFFFFFF&(data))>>0)
#define DC2_SYS_DC_SFMODE_CMP1_get_sfmode_cmp_rlt1(data)                              ((0xFFFFFFFF&(data))>>0)


#define DC2_SYS_DC_SFMODE_CMP2                                                        0x18003058
#define DC2_SYS_DC_SFMODE_CMP2_reg_addr                                               "0xB8003058"
#define DC2_SYS_DC_SFMODE_CMP2_reg                                                    0xB8003058
#define set_DC2_SYS_DC_SFMODE_CMP2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_SFMODE_CMP2_reg)=data)
#define get_DC2_SYS_DC_SFMODE_CMP2_reg   (*((volatile unsigned int*) DC2_SYS_DC_SFMODE_CMP2_reg))
#define DC2_SYS_DC_SFMODE_CMP2_inst_adr                                               "0x0016"
#define DC2_SYS_DC_SFMODE_CMP2_inst                                                   0x0016
#define DC2_SYS_DC_SFMODE_CMP2_sfmode_cmp_rlt2_shift                                  (0)
#define DC2_SYS_DC_SFMODE_CMP2_sfmode_cmp_rlt2_mask                                   (0xFFFFFFFF)
#define DC2_SYS_DC_SFMODE_CMP2_sfmode_cmp_rlt2(data)                                  (0xFFFFFFFF&((data)<<0))
#define DC2_SYS_DC_SFMODE_CMP2_sfmode_cmp_rlt2_src(data)                              ((0xFFFFFFFF&(data))>>0)
#define DC2_SYS_DC_SFMODE_CMP2_get_sfmode_cmp_rlt2(data)                              ((0xFFFFFFFF&(data))>>0)


#define DC2_SYS_DC_SFMODE_CMP3                                                        0x1800305C
#define DC2_SYS_DC_SFMODE_CMP3_reg_addr                                               "0xB800305C"
#define DC2_SYS_DC_SFMODE_CMP3_reg                                                    0xB800305C
#define set_DC2_SYS_DC_SFMODE_CMP3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_SFMODE_CMP3_reg)=data)
#define get_DC2_SYS_DC_SFMODE_CMP3_reg   (*((volatile unsigned int*) DC2_SYS_DC_SFMODE_CMP3_reg))
#define DC2_SYS_DC_SFMODE_CMP3_inst_adr                                               "0x0017"
#define DC2_SYS_DC_SFMODE_CMP3_inst                                                   0x0017
#define DC2_SYS_DC_SFMODE_CMP3_sfmode_cmp_rlt3_shift                                  (0)
#define DC2_SYS_DC_SFMODE_CMP3_sfmode_cmp_rlt3_mask                                   (0xFFFFFFFF)
#define DC2_SYS_DC_SFMODE_CMP3_sfmode_cmp_rlt3(data)                                  (0xFFFFFFFF&((data)<<0))
#define DC2_SYS_DC_SFMODE_CMP3_sfmode_cmp_rlt3_src(data)                              ((0xFFFFFFFF&(data))>>0)
#define DC2_SYS_DC_SFMODE_CMP3_get_sfmode_cmp_rlt3(data)                              ((0xFFFFFFFF&(data))>>0)


#define DC2_SYS_DC_DEBUG                                                              0x18003060
#define DC2_SYS_DC_DEBUG_reg_addr                                                     "0xB8003060"
#define DC2_SYS_DC_DEBUG_reg                                                          0xB8003060
#define set_DC2_SYS_DC_DEBUG_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_DEBUG_reg)=data)
#define get_DC2_SYS_DC_DEBUG_reg   (*((volatile unsigned int*) DC2_SYS_DC_DEBUG_reg))
#define DC2_SYS_DC_DEBUG_inst_adr                                                     "0x0018"
#define DC2_SYS_DC_DEBUG_inst                                                         0x0018
#define DC2_SYS_DC_DEBUG_Debug_sys2_shift                                             (17)
#define DC2_SYS_DC_DEBUG_Debug_sys2_mask                                              (0x00020000)
#define DC2_SYS_DC_DEBUG_Debug_sys2(data)                                             (0x00020000&((data)<<17))
#define DC2_SYS_DC_DEBUG_Debug_sys2_src(data)                                         ((0x00020000&(data))>>17)
#define DC2_SYS_DC_DEBUG_get_Debug_sys2(data)                                         ((0x00020000&(data))>>17)
#define DC2_SYS_DC_DEBUG_Debug_en_shift                                               (16)
#define DC2_SYS_DC_DEBUG_Debug_en_mask                                                (0x00010000)
#define DC2_SYS_DC_DEBUG_Debug_en(data)                                               (0x00010000&((data)<<16))
#define DC2_SYS_DC_DEBUG_Debug_en_src(data)                                           ((0x00010000&(data))>>16)
#define DC2_SYS_DC_DEBUG_get_Debug_en(data)                                           ((0x00010000&(data))>>16)
#define DC2_SYS_DC_DEBUG_Debug_sel_1_shift                                            (8)
#define DC2_SYS_DC_DEBUG_Debug_sel_1_mask                                             (0x00003F00)
#define DC2_SYS_DC_DEBUG_Debug_sel_1(data)                                            (0x00003F00&((data)<<8))
#define DC2_SYS_DC_DEBUG_Debug_sel_1_src(data)                                        ((0x00003F00&(data))>>8)
#define DC2_SYS_DC_DEBUG_get_Debug_sel_1(data)                                        ((0x00003F00&(data))>>8)
#define DC2_SYS_DC_DEBUG_Debug_sel_0_shift                                            (0)
#define DC2_SYS_DC_DEBUG_Debug_sel_0_mask                                             (0x0000003F)
#define DC2_SYS_DC_DEBUG_Debug_sel_0(data)                                            (0x0000003F&((data)<<0))
#define DC2_SYS_DC_DEBUG_Debug_sel_0_src(data)                                        ((0x0000003F&(data))>>0)
#define DC2_SYS_DC_DEBUG_get_Debug_sel_0(data)                                        ((0x0000003F&(data))>>0)


#define DC2_SYS_DC_DEBUG_STATUS                                                       0x18003064
#define DC2_SYS_DC_DEBUG_STATUS_reg_addr                                              "0xB8003064"
#define DC2_SYS_DC_DEBUG_STATUS_reg                                                   0xB8003064
#define set_DC2_SYS_DC_DEBUG_STATUS_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_DEBUG_STATUS_reg)=data)
#define get_DC2_SYS_DC_DEBUG_STATUS_reg   (*((volatile unsigned int*) DC2_SYS_DC_DEBUG_STATUS_reg))
#define DC2_SYS_DC_DEBUG_STATUS_inst_adr                                              "0x0019"
#define DC2_SYS_DC_DEBUG_STATUS_inst                                                  0x0019
#define DC2_SYS_DC_DEBUG_STATUS_write_cmd_fifo_1_underflow_shift                      (29)
#define DC2_SYS_DC_DEBUG_STATUS_write_cmd_fifo_1_underflow_mask                       (0x20000000)
#define DC2_SYS_DC_DEBUG_STATUS_write_cmd_fifo_1_underflow(data)                      (0x20000000&((data)<<29))
#define DC2_SYS_DC_DEBUG_STATUS_write_cmd_fifo_1_underflow_src(data)                  ((0x20000000&(data))>>29)
#define DC2_SYS_DC_DEBUG_STATUS_get_write_cmd_fifo_1_underflow(data)                  ((0x20000000&(data))>>29)
#define DC2_SYS_DC_DEBUG_STATUS_write_cmd_fifo_0_underflow_shift                      (28)
#define DC2_SYS_DC_DEBUG_STATUS_write_cmd_fifo_0_underflow_mask                       (0x10000000)
#define DC2_SYS_DC_DEBUG_STATUS_write_cmd_fifo_0_underflow(data)                      (0x10000000&((data)<<28))
#define DC2_SYS_DC_DEBUG_STATUS_write_cmd_fifo_0_underflow_src(data)                  ((0x10000000&(data))>>28)
#define DC2_SYS_DC_DEBUG_STATUS_get_write_cmd_fifo_0_underflow(data)                  ((0x10000000&(data))>>28)
#define DC2_SYS_DC_DEBUG_STATUS_read_cmd_fifo_2_underflow_shift                       (27)
#define DC2_SYS_DC_DEBUG_STATUS_read_cmd_fifo_2_underflow_mask                        (0x08000000)
#define DC2_SYS_DC_DEBUG_STATUS_read_cmd_fifo_2_underflow(data)                       (0x08000000&((data)<<27))
#define DC2_SYS_DC_DEBUG_STATUS_read_cmd_fifo_2_underflow_src(data)                   ((0x08000000&(data))>>27)
#define DC2_SYS_DC_DEBUG_STATUS_get_read_cmd_fifo_2_underflow(data)                   ((0x08000000&(data))>>27)
#define DC2_SYS_DC_DEBUG_STATUS_read_cmd_fifo_1_underflow_shift                       (26)
#define DC2_SYS_DC_DEBUG_STATUS_read_cmd_fifo_1_underflow_mask                        (0x04000000)
#define DC2_SYS_DC_DEBUG_STATUS_read_cmd_fifo_1_underflow(data)                       (0x04000000&((data)<<26))
#define DC2_SYS_DC_DEBUG_STATUS_read_cmd_fifo_1_underflow_src(data)                   ((0x04000000&(data))>>26)
#define DC2_SYS_DC_DEBUG_STATUS_get_read_cmd_fifo_1_underflow(data)                   ((0x04000000&(data))>>26)
#define DC2_SYS_DC_DEBUG_STATUS_read_cmd_fifo_0_underflow_shift                       (25)
#define DC2_SYS_DC_DEBUG_STATUS_read_cmd_fifo_0_underflow_mask                        (0x02000000)
#define DC2_SYS_DC_DEBUG_STATUS_read_cmd_fifo_0_underflow(data)                       (0x02000000&((data)<<25))
#define DC2_SYS_DC_DEBUG_STATUS_read_cmd_fifo_0_underflow_src(data)                   ((0x02000000&(data))>>25)
#define DC2_SYS_DC_DEBUG_STATUS_get_read_cmd_fifo_0_underflow(data)                   ((0x02000000&(data))>>25)
#define DC2_SYS_DC_DEBUG_STATUS_write_cmd_fifo_1_overflow_shift                       (24)
#define DC2_SYS_DC_DEBUG_STATUS_write_cmd_fifo_1_overflow_mask                        (0x01000000)
#define DC2_SYS_DC_DEBUG_STATUS_write_cmd_fifo_1_overflow(data)                       (0x01000000&((data)<<24))
#define DC2_SYS_DC_DEBUG_STATUS_write_cmd_fifo_1_overflow_src(data)                   ((0x01000000&(data))>>24)
#define DC2_SYS_DC_DEBUG_STATUS_get_write_cmd_fifo_1_overflow(data)                   ((0x01000000&(data))>>24)
#define DC2_SYS_DC_DEBUG_STATUS_write_cmd_fifo_0_overflow_shift                       (23)
#define DC2_SYS_DC_DEBUG_STATUS_write_cmd_fifo_0_overflow_mask                        (0x00800000)
#define DC2_SYS_DC_DEBUG_STATUS_write_cmd_fifo_0_overflow(data)                       (0x00800000&((data)<<23))
#define DC2_SYS_DC_DEBUG_STATUS_write_cmd_fifo_0_overflow_src(data)                   ((0x00800000&(data))>>23)
#define DC2_SYS_DC_DEBUG_STATUS_get_write_cmd_fifo_0_overflow(data)                   ((0x00800000&(data))>>23)
#define DC2_SYS_DC_DEBUG_STATUS_read_cmd_fifo_2_overflow_shift                        (22)
#define DC2_SYS_DC_DEBUG_STATUS_read_cmd_fifo_2_overflow_mask                         (0x00400000)
#define DC2_SYS_DC_DEBUG_STATUS_read_cmd_fifo_2_overflow(data)                        (0x00400000&((data)<<22))
#define DC2_SYS_DC_DEBUG_STATUS_read_cmd_fifo_2_overflow_src(data)                    ((0x00400000&(data))>>22)
#define DC2_SYS_DC_DEBUG_STATUS_get_read_cmd_fifo_2_overflow(data)                    ((0x00400000&(data))>>22)
#define DC2_SYS_DC_DEBUG_STATUS_read_cmd_fifo_1_overflow_shift                        (21)
#define DC2_SYS_DC_DEBUG_STATUS_read_cmd_fifo_1_overflow_mask                         (0x00200000)
#define DC2_SYS_DC_DEBUG_STATUS_read_cmd_fifo_1_overflow(data)                        (0x00200000&((data)<<21))
#define DC2_SYS_DC_DEBUG_STATUS_read_cmd_fifo_1_overflow_src(data)                    ((0x00200000&(data))>>21)
#define DC2_SYS_DC_DEBUG_STATUS_get_read_cmd_fifo_1_overflow(data)                    ((0x00200000&(data))>>21)
#define DC2_SYS_DC_DEBUG_STATUS_read_cmd_fifo_0_overflow_shift                        (20)
#define DC2_SYS_DC_DEBUG_STATUS_read_cmd_fifo_0_overflow_mask                         (0x00100000)
#define DC2_SYS_DC_DEBUG_STATUS_read_cmd_fifo_0_overflow(data)                        (0x00100000&((data)<<20))
#define DC2_SYS_DC_DEBUG_STATUS_read_cmd_fifo_0_overflow_src(data)                    ((0x00100000&(data))>>20)
#define DC2_SYS_DC_DEBUG_STATUS_get_read_cmd_fifo_0_overflow(data)                    ((0x00100000&(data))>>20)
#define DC2_SYS_DC_DEBUG_STATUS_exsram_fifo_underflow_shift                           (17)
#define DC2_SYS_DC_DEBUG_STATUS_exsram_fifo_underflow_mask                            (0x00020000)
#define DC2_SYS_DC_DEBUG_STATUS_exsram_fifo_underflow(data)                           (0x00020000&((data)<<17))
#define DC2_SYS_DC_DEBUG_STATUS_exsram_fifo_underflow_src(data)                       ((0x00020000&(data))>>17)
#define DC2_SYS_DC_DEBUG_STATUS_get_exsram_fifo_underflow(data)                       ((0x00020000&(data))>>17)
#define DC2_SYS_DC_DEBUG_STATUS_exsram_fifo_overflow_shift                            (16)
#define DC2_SYS_DC_DEBUG_STATUS_exsram_fifo_overflow_mask                             (0x00010000)
#define DC2_SYS_DC_DEBUG_STATUS_exsram_fifo_overflow(data)                            (0x00010000&((data)<<16))
#define DC2_SYS_DC_DEBUG_STATUS_exsram_fifo_overflow_src(data)                        ((0x00010000&(data))>>16)
#define DC2_SYS_DC_DEBUG_STATUS_get_exsram_fifo_overflow(data)                        ((0x00010000&(data))>>16)
#define DC2_SYS_DC_DEBUG_STATUS_write_fifo_1_underflow_shift                          (12)
#define DC2_SYS_DC_DEBUG_STATUS_write_fifo_1_underflow_mask                           (0x00001000)
#define DC2_SYS_DC_DEBUG_STATUS_write_fifo_1_underflow(data)                          (0x00001000&((data)<<12))
#define DC2_SYS_DC_DEBUG_STATUS_write_fifo_1_underflow_src(data)                      ((0x00001000&(data))>>12)
#define DC2_SYS_DC_DEBUG_STATUS_get_write_fifo_1_underflow(data)                      ((0x00001000&(data))>>12)
#define DC2_SYS_DC_DEBUG_STATUS_write_fifo_0_underflow_shift                          (11)
#define DC2_SYS_DC_DEBUG_STATUS_write_fifo_0_underflow_mask                           (0x00000800)
#define DC2_SYS_DC_DEBUG_STATUS_write_fifo_0_underflow(data)                          (0x00000800&((data)<<11))
#define DC2_SYS_DC_DEBUG_STATUS_write_fifo_0_underflow_src(data)                      ((0x00000800&(data))>>11)
#define DC2_SYS_DC_DEBUG_STATUS_get_write_fifo_0_underflow(data)                      ((0x00000800&(data))>>11)
#define DC2_SYS_DC_DEBUG_STATUS_read_fifo_2_underflow_shift                           (10)
#define DC2_SYS_DC_DEBUG_STATUS_read_fifo_2_underflow_mask                            (0x00000400)
#define DC2_SYS_DC_DEBUG_STATUS_read_fifo_2_underflow(data)                           (0x00000400&((data)<<10))
#define DC2_SYS_DC_DEBUG_STATUS_read_fifo_2_underflow_src(data)                       ((0x00000400&(data))>>10)
#define DC2_SYS_DC_DEBUG_STATUS_get_read_fifo_2_underflow(data)                       ((0x00000400&(data))>>10)
#define DC2_SYS_DC_DEBUG_STATUS_read_fifo_1_underflow_shift                           (9)
#define DC2_SYS_DC_DEBUG_STATUS_read_fifo_1_underflow_mask                            (0x00000200)
#define DC2_SYS_DC_DEBUG_STATUS_read_fifo_1_underflow(data)                           (0x00000200&((data)<<9))
#define DC2_SYS_DC_DEBUG_STATUS_read_fifo_1_underflow_src(data)                       ((0x00000200&(data))>>9)
#define DC2_SYS_DC_DEBUG_STATUS_get_read_fifo_1_underflow(data)                       ((0x00000200&(data))>>9)
#define DC2_SYS_DC_DEBUG_STATUS_read_fifo_0_underflow_shift                           (8)
#define DC2_SYS_DC_DEBUG_STATUS_read_fifo_0_underflow_mask                            (0x00000100)
#define DC2_SYS_DC_DEBUG_STATUS_read_fifo_0_underflow(data)                           (0x00000100&((data)<<8))
#define DC2_SYS_DC_DEBUG_STATUS_read_fifo_0_underflow_src(data)                       ((0x00000100&(data))>>8)
#define DC2_SYS_DC_DEBUG_STATUS_get_read_fifo_0_underflow(data)                       ((0x00000100&(data))>>8)
#define DC2_SYS_DC_DEBUG_STATUS_write_fifo_1_overflow_shift                           (4)
#define DC2_SYS_DC_DEBUG_STATUS_write_fifo_1_overflow_mask                            (0x00000010)
#define DC2_SYS_DC_DEBUG_STATUS_write_fifo_1_overflow(data)                           (0x00000010&((data)<<4))
#define DC2_SYS_DC_DEBUG_STATUS_write_fifo_1_overflow_src(data)                       ((0x00000010&(data))>>4)
#define DC2_SYS_DC_DEBUG_STATUS_get_write_fifo_1_overflow(data)                       ((0x00000010&(data))>>4)
#define DC2_SYS_DC_DEBUG_STATUS_write_fifo_0_overflow_shift                           (3)
#define DC2_SYS_DC_DEBUG_STATUS_write_fifo_0_overflow_mask                            (0x00000008)
#define DC2_SYS_DC_DEBUG_STATUS_write_fifo_0_overflow(data)                           (0x00000008&((data)<<3))
#define DC2_SYS_DC_DEBUG_STATUS_write_fifo_0_overflow_src(data)                       ((0x00000008&(data))>>3)
#define DC2_SYS_DC_DEBUG_STATUS_get_write_fifo_0_overflow(data)                       ((0x00000008&(data))>>3)
#define DC2_SYS_DC_DEBUG_STATUS_read_fifo_2_overflow_shift                            (2)
#define DC2_SYS_DC_DEBUG_STATUS_read_fifo_2_overflow_mask                             (0x00000004)
#define DC2_SYS_DC_DEBUG_STATUS_read_fifo_2_overflow(data)                            (0x00000004&((data)<<2))
#define DC2_SYS_DC_DEBUG_STATUS_read_fifo_2_overflow_src(data)                        ((0x00000004&(data))>>2)
#define DC2_SYS_DC_DEBUG_STATUS_get_read_fifo_2_overflow(data)                        ((0x00000004&(data))>>2)
#define DC2_SYS_DC_DEBUG_STATUS_read_fifo_1_overflow_shift                            (1)
#define DC2_SYS_DC_DEBUG_STATUS_read_fifo_1_overflow_mask                             (0x00000002)
#define DC2_SYS_DC_DEBUG_STATUS_read_fifo_1_overflow(data)                            (0x00000002&((data)<<1))
#define DC2_SYS_DC_DEBUG_STATUS_read_fifo_1_overflow_src(data)                        ((0x00000002&(data))>>1)
#define DC2_SYS_DC_DEBUG_STATUS_get_read_fifo_1_overflow(data)                        ((0x00000002&(data))>>1)
#define DC2_SYS_DC_DEBUG_STATUS_read_fifo_0_overflow_shift                            (0)
#define DC2_SYS_DC_DEBUG_STATUS_read_fifo_0_overflow_mask                             (0x00000001)
#define DC2_SYS_DC_DEBUG_STATUS_read_fifo_0_overflow(data)                            (0x00000001&((data)<<0))
#define DC2_SYS_DC_DEBUG_STATUS_read_fifo_0_overflow_src(data)                        ((0x00000001&(data))>>0)
#define DC2_SYS_DC_DEBUG_STATUS_get_read_fifo_0_overflow(data)                        ((0x00000001&(data))>>0)


#define DC2_SYS_DC_PRIORITY_CTRL0                                                     0x18003080
#define DC2_SYS_DC_PRIORITY_CTRL0_reg_addr                                            "0xB8003080"
#define DC2_SYS_DC_PRIORITY_CTRL0_reg                                                 0xB8003080
#define set_DC2_SYS_DC_PRIORITY_CTRL0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PRIORITY_CTRL0_reg)=data)
#define get_DC2_SYS_DC_PRIORITY_CTRL0_reg   (*((volatile unsigned int*) DC2_SYS_DC_PRIORITY_CTRL0_reg))
#define DC2_SYS_DC_PRIORITY_CTRL0_inst_adr                                            "0x0020"
#define DC2_SYS_DC_PRIORITY_CTRL0_inst                                                0x0020
#define DC2_SYS_DC_PRIORITY_CTRL0_C0_LATCNT_END_shift                                 (16)
#define DC2_SYS_DC_PRIORITY_CTRL0_C0_LATCNT_END_mask                                  (0x00FF0000)
#define DC2_SYS_DC_PRIORITY_CTRL0_C0_LATCNT_END(data)                                 (0x00FF0000&((data)<<16))
#define DC2_SYS_DC_PRIORITY_CTRL0_C0_LATCNT_END_src(data)                             ((0x00FF0000&(data))>>16)
#define DC2_SYS_DC_PRIORITY_CTRL0_get_C0_LATCNT_END(data)                             ((0x00FF0000&(data))>>16)
#define DC2_SYS_DC_PRIORITY_CTRL0_C0_LATCNT_BEG_shift                                 (0)
#define DC2_SYS_DC_PRIORITY_CTRL0_C0_LATCNT_BEG_mask                                  (0x000000FF)
#define DC2_SYS_DC_PRIORITY_CTRL0_C0_LATCNT_BEG(data)                                 (0x000000FF&((data)<<0))
#define DC2_SYS_DC_PRIORITY_CTRL0_C0_LATCNT_BEG_src(data)                             ((0x000000FF&(data))>>0)
#define DC2_SYS_DC_PRIORITY_CTRL0_get_C0_LATCNT_BEG(data)                             ((0x000000FF&(data))>>0)


#define DC2_SYS_DC_PRIORITY_CTRL1                                                     0x18003084
#define DC2_SYS_DC_PRIORITY_CTRL1_reg_addr                                            "0xB8003084"
#define DC2_SYS_DC_PRIORITY_CTRL1_reg                                                 0xB8003084
#define set_DC2_SYS_DC_PRIORITY_CTRL1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PRIORITY_CTRL1_reg)=data)
#define get_DC2_SYS_DC_PRIORITY_CTRL1_reg   (*((volatile unsigned int*) DC2_SYS_DC_PRIORITY_CTRL1_reg))
#define DC2_SYS_DC_PRIORITY_CTRL1_inst_adr                                            "0x0021"
#define DC2_SYS_DC_PRIORITY_CTRL1_inst                                                0x0021
#define DC2_SYS_DC_PRIORITY_CTRL1_C1_LATCNT_END_shift                                 (16)
#define DC2_SYS_DC_PRIORITY_CTRL1_C1_LATCNT_END_mask                                  (0x00FF0000)
#define DC2_SYS_DC_PRIORITY_CTRL1_C1_LATCNT_END(data)                                 (0x00FF0000&((data)<<16))
#define DC2_SYS_DC_PRIORITY_CTRL1_C1_LATCNT_END_src(data)                             ((0x00FF0000&(data))>>16)
#define DC2_SYS_DC_PRIORITY_CTRL1_get_C1_LATCNT_END(data)                             ((0x00FF0000&(data))>>16)
#define DC2_SYS_DC_PRIORITY_CTRL1_C1_LATCNT_BEG_shift                                 (0)
#define DC2_SYS_DC_PRIORITY_CTRL1_C1_LATCNT_BEG_mask                                  (0x000000FF)
#define DC2_SYS_DC_PRIORITY_CTRL1_C1_LATCNT_BEG(data)                                 (0x000000FF&((data)<<0))
#define DC2_SYS_DC_PRIORITY_CTRL1_C1_LATCNT_BEG_src(data)                             ((0x000000FF&(data))>>0)
#define DC2_SYS_DC_PRIORITY_CTRL1_get_C1_LATCNT_BEG(data)                             ((0x000000FF&(data))>>0)


#define DC2_SYS_DC_PRIORITY_CTRL2                                                     0x18003088
#define DC2_SYS_DC_PRIORITY_CTRL2_reg_addr                                            "0xB8003088"
#define DC2_SYS_DC_PRIORITY_CTRL2_reg                                                 0xB8003088
#define set_DC2_SYS_DC_PRIORITY_CTRL2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PRIORITY_CTRL2_reg)=data)
#define get_DC2_SYS_DC_PRIORITY_CTRL2_reg   (*((volatile unsigned int*) DC2_SYS_DC_PRIORITY_CTRL2_reg))
#define DC2_SYS_DC_PRIORITY_CTRL2_inst_adr                                            "0x0022"
#define DC2_SYS_DC_PRIORITY_CTRL2_inst                                                0x0022
#define DC2_SYS_DC_PRIORITY_CTRL2_C2_LATCNT_END_shift                                 (16)
#define DC2_SYS_DC_PRIORITY_CTRL2_C2_LATCNT_END_mask                                  (0x00FF0000)
#define DC2_SYS_DC_PRIORITY_CTRL2_C2_LATCNT_END(data)                                 (0x00FF0000&((data)<<16))
#define DC2_SYS_DC_PRIORITY_CTRL2_C2_LATCNT_END_src(data)                             ((0x00FF0000&(data))>>16)
#define DC2_SYS_DC_PRIORITY_CTRL2_get_C2_LATCNT_END(data)                             ((0x00FF0000&(data))>>16)
#define DC2_SYS_DC_PRIORITY_CTRL2_C2_LATCNT_BEG_shift                                 (0)
#define DC2_SYS_DC_PRIORITY_CTRL2_C2_LATCNT_BEG_mask                                  (0x000000FF)
#define DC2_SYS_DC_PRIORITY_CTRL2_C2_LATCNT_BEG(data)                                 (0x000000FF&((data)<<0))
#define DC2_SYS_DC_PRIORITY_CTRL2_C2_LATCNT_BEG_src(data)                             ((0x000000FF&(data))>>0)
#define DC2_SYS_DC_PRIORITY_CTRL2_get_C2_LATCNT_BEG(data)                             ((0x000000FF&(data))>>0)


#define DC2_SYS_DC_PRIORITY_CTRL3                                                     0x1800308C
#define DC2_SYS_DC_PRIORITY_CTRL3_reg_addr                                            "0xB800308C"
#define DC2_SYS_DC_PRIORITY_CTRL3_reg                                                 0xB800308C
#define set_DC2_SYS_DC_PRIORITY_CTRL3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PRIORITY_CTRL3_reg)=data)
#define get_DC2_SYS_DC_PRIORITY_CTRL3_reg   (*((volatile unsigned int*) DC2_SYS_DC_PRIORITY_CTRL3_reg))
#define DC2_SYS_DC_PRIORITY_CTRL3_inst_adr                                            "0x0023"
#define DC2_SYS_DC_PRIORITY_CTRL3_inst                                                0x0023
#define DC2_SYS_DC_PRIORITY_CTRL3_C3_LATCNT_END_shift                                 (16)
#define DC2_SYS_DC_PRIORITY_CTRL3_C3_LATCNT_END_mask                                  (0x00FF0000)
#define DC2_SYS_DC_PRIORITY_CTRL3_C3_LATCNT_END(data)                                 (0x00FF0000&((data)<<16))
#define DC2_SYS_DC_PRIORITY_CTRL3_C3_LATCNT_END_src(data)                             ((0x00FF0000&(data))>>16)
#define DC2_SYS_DC_PRIORITY_CTRL3_get_C3_LATCNT_END(data)                             ((0x00FF0000&(data))>>16)
#define DC2_SYS_DC_PRIORITY_CTRL3_C3_LATCNT_BEG_shift                                 (0)
#define DC2_SYS_DC_PRIORITY_CTRL3_C3_LATCNT_BEG_mask                                  (0x000000FF)
#define DC2_SYS_DC_PRIORITY_CTRL3_C3_LATCNT_BEG(data)                                 (0x000000FF&((data)<<0))
#define DC2_SYS_DC_PRIORITY_CTRL3_C3_LATCNT_BEG_src(data)                             ((0x000000FF&(data))>>0)
#define DC2_SYS_DC_PRIORITY_CTRL3_get_C3_LATCNT_BEG(data)                             ((0x000000FF&(data))>>0)


#define DC2_SYS_DC_PRIORITY_CTRL4                                                     0x18003090
#define DC2_SYS_DC_PRIORITY_CTRL4_reg_addr                                            "0xB8003090"
#define DC2_SYS_DC_PRIORITY_CTRL4_reg                                                 0xB8003090
#define set_DC2_SYS_DC_PRIORITY_CTRL4_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PRIORITY_CTRL4_reg)=data)
#define get_DC2_SYS_DC_PRIORITY_CTRL4_reg   (*((volatile unsigned int*) DC2_SYS_DC_PRIORITY_CTRL4_reg))
#define DC2_SYS_DC_PRIORITY_CTRL4_inst_adr                                            "0x0024"
#define DC2_SYS_DC_PRIORITY_CTRL4_inst                                                0x0024
#define DC2_SYS_DC_PRIORITY_CTRL4_C4_LATCNT_END_shift                                 (16)
#define DC2_SYS_DC_PRIORITY_CTRL4_C4_LATCNT_END_mask                                  (0x00FF0000)
#define DC2_SYS_DC_PRIORITY_CTRL4_C4_LATCNT_END(data)                                 (0x00FF0000&((data)<<16))
#define DC2_SYS_DC_PRIORITY_CTRL4_C4_LATCNT_END_src(data)                             ((0x00FF0000&(data))>>16)
#define DC2_SYS_DC_PRIORITY_CTRL4_get_C4_LATCNT_END(data)                             ((0x00FF0000&(data))>>16)
#define DC2_SYS_DC_PRIORITY_CTRL4_C4_LATCNT_BEG_shift                                 (0)
#define DC2_SYS_DC_PRIORITY_CTRL4_C4_LATCNT_BEG_mask                                  (0x000000FF)
#define DC2_SYS_DC_PRIORITY_CTRL4_C4_LATCNT_BEG(data)                                 (0x000000FF&((data)<<0))
#define DC2_SYS_DC_PRIORITY_CTRL4_C4_LATCNT_BEG_src(data)                             ((0x000000FF&(data))>>0)
#define DC2_SYS_DC_PRIORITY_CTRL4_get_C4_LATCNT_BEG(data)                             ((0x000000FF&(data))>>0)


#define DC2_SYS_DC_PRIORITY_CTRL5                                                     0x18003094
#define DC2_SYS_DC_PRIORITY_CTRL5_reg_addr                                            "0xB8003094"
#define DC2_SYS_DC_PRIORITY_CTRL5_reg                                                 0xB8003094
#define set_DC2_SYS_DC_PRIORITY_CTRL5_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PRIORITY_CTRL5_reg)=data)
#define get_DC2_SYS_DC_PRIORITY_CTRL5_reg   (*((volatile unsigned int*) DC2_SYS_DC_PRIORITY_CTRL5_reg))
#define DC2_SYS_DC_PRIORITY_CTRL5_inst_adr                                            "0x0025"
#define DC2_SYS_DC_PRIORITY_CTRL5_inst                                                0x0025
#define DC2_SYS_DC_PRIORITY_CTRL5_C5_LATCNT_END_shift                                 (16)
#define DC2_SYS_DC_PRIORITY_CTRL5_C5_LATCNT_END_mask                                  (0x00FF0000)
#define DC2_SYS_DC_PRIORITY_CTRL5_C5_LATCNT_END(data)                                 (0x00FF0000&((data)<<16))
#define DC2_SYS_DC_PRIORITY_CTRL5_C5_LATCNT_END_src(data)                             ((0x00FF0000&(data))>>16)
#define DC2_SYS_DC_PRIORITY_CTRL5_get_C5_LATCNT_END(data)                             ((0x00FF0000&(data))>>16)
#define DC2_SYS_DC_PRIORITY_CTRL5_C5_LATCNT_BEG_shift                                 (0)
#define DC2_SYS_DC_PRIORITY_CTRL5_C5_LATCNT_BEG_mask                                  (0x000000FF)
#define DC2_SYS_DC_PRIORITY_CTRL5_C5_LATCNT_BEG(data)                                 (0x000000FF&((data)<<0))
#define DC2_SYS_DC_PRIORITY_CTRL5_C5_LATCNT_BEG_src(data)                             ((0x000000FF&(data))>>0)
#define DC2_SYS_DC_PRIORITY_CTRL5_get_C5_LATCNT_BEG(data)                             ((0x000000FF&(data))>>0)


#define DC2_SYS_DC_PRIORITY_CTRL6                                                     0x18003098
#define DC2_SYS_DC_PRIORITY_CTRL6_reg_addr                                            "0xB8003098"
#define DC2_SYS_DC_PRIORITY_CTRL6_reg                                                 0xB8003098
#define set_DC2_SYS_DC_PRIORITY_CTRL6_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PRIORITY_CTRL6_reg)=data)
#define get_DC2_SYS_DC_PRIORITY_CTRL6_reg   (*((volatile unsigned int*) DC2_SYS_DC_PRIORITY_CTRL6_reg))
#define DC2_SYS_DC_PRIORITY_CTRL6_inst_adr                                            "0x0026"
#define DC2_SYS_DC_PRIORITY_CTRL6_inst                                                0x0026
#define DC2_SYS_DC_PRIORITY_CTRL6_C6_LATCNT_END_shift                                 (16)
#define DC2_SYS_DC_PRIORITY_CTRL6_C6_LATCNT_END_mask                                  (0x00FF0000)
#define DC2_SYS_DC_PRIORITY_CTRL6_C6_LATCNT_END(data)                                 (0x00FF0000&((data)<<16))
#define DC2_SYS_DC_PRIORITY_CTRL6_C6_LATCNT_END_src(data)                             ((0x00FF0000&(data))>>16)
#define DC2_SYS_DC_PRIORITY_CTRL6_get_C6_LATCNT_END(data)                             ((0x00FF0000&(data))>>16)
#define DC2_SYS_DC_PRIORITY_CTRL6_C6_LATCNT_BEG_shift                                 (0)
#define DC2_SYS_DC_PRIORITY_CTRL6_C6_LATCNT_BEG_mask                                  (0x000000FF)
#define DC2_SYS_DC_PRIORITY_CTRL6_C6_LATCNT_BEG(data)                                 (0x000000FF&((data)<<0))
#define DC2_SYS_DC_PRIORITY_CTRL6_C6_LATCNT_BEG_src(data)                             ((0x000000FF&(data))>>0)
#define DC2_SYS_DC_PRIORITY_CTRL6_get_C6_LATCNT_BEG(data)                             ((0x000000FF&(data))>>0)


#define DC2_SYS_DC_PRIORITY_CTRL7                                                     0x1800309C
#define DC2_SYS_DC_PRIORITY_CTRL7_reg_addr                                            "0xB800309C"
#define DC2_SYS_DC_PRIORITY_CTRL7_reg                                                 0xB800309C
#define set_DC2_SYS_DC_PRIORITY_CTRL7_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PRIORITY_CTRL7_reg)=data)
#define get_DC2_SYS_DC_PRIORITY_CTRL7_reg   (*((volatile unsigned int*) DC2_SYS_DC_PRIORITY_CTRL7_reg))
#define DC2_SYS_DC_PRIORITY_CTRL7_inst_adr                                            "0x0027"
#define DC2_SYS_DC_PRIORITY_CTRL7_inst                                                0x0027
#define DC2_SYS_DC_PRIORITY_CTRL7_C7_LATCNT_END_shift                                 (16)
#define DC2_SYS_DC_PRIORITY_CTRL7_C7_LATCNT_END_mask                                  (0x00FF0000)
#define DC2_SYS_DC_PRIORITY_CTRL7_C7_LATCNT_END(data)                                 (0x00FF0000&((data)<<16))
#define DC2_SYS_DC_PRIORITY_CTRL7_C7_LATCNT_END_src(data)                             ((0x00FF0000&(data))>>16)
#define DC2_SYS_DC_PRIORITY_CTRL7_get_C7_LATCNT_END(data)                             ((0x00FF0000&(data))>>16)
#define DC2_SYS_DC_PRIORITY_CTRL7_C7_LATCNT_BEG_shift                                 (0)
#define DC2_SYS_DC_PRIORITY_CTRL7_C7_LATCNT_BEG_mask                                  (0x000000FF)
#define DC2_SYS_DC_PRIORITY_CTRL7_C7_LATCNT_BEG(data)                                 (0x000000FF&((data)<<0))
#define DC2_SYS_DC_PRIORITY_CTRL7_C7_LATCNT_BEG_src(data)                             ((0x000000FF&(data))>>0)
#define DC2_SYS_DC_PRIORITY_CTRL7_get_C7_LATCNT_BEG(data)                             ((0x000000FF&(data))>>0)


#define DC2_SYS_DC_PRIORITY_CTRL8                                                     0x180030A0
#define DC2_SYS_DC_PRIORITY_CTRL8_reg_addr                                            "0xB80030A0"
#define DC2_SYS_DC_PRIORITY_CTRL8_reg                                                 0xB80030A0
#define set_DC2_SYS_DC_PRIORITY_CTRL8_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PRIORITY_CTRL8_reg)=data)
#define get_DC2_SYS_DC_PRIORITY_CTRL8_reg   (*((volatile unsigned int*) DC2_SYS_DC_PRIORITY_CTRL8_reg))
#define DC2_SYS_DC_PRIORITY_CTRL8_inst_adr                                            "0x0028"
#define DC2_SYS_DC_PRIORITY_CTRL8_inst                                                0x0028
#define DC2_SYS_DC_PRIORITY_CTRL8_C8_LATCNT_END_shift                                 (16)
#define DC2_SYS_DC_PRIORITY_CTRL8_C8_LATCNT_END_mask                                  (0x00FF0000)
#define DC2_SYS_DC_PRIORITY_CTRL8_C8_LATCNT_END(data)                                 (0x00FF0000&((data)<<16))
#define DC2_SYS_DC_PRIORITY_CTRL8_C8_LATCNT_END_src(data)                             ((0x00FF0000&(data))>>16)
#define DC2_SYS_DC_PRIORITY_CTRL8_get_C8_LATCNT_END(data)                             ((0x00FF0000&(data))>>16)
#define DC2_SYS_DC_PRIORITY_CTRL8_C8_LATCNT_BEG_shift                                 (0)
#define DC2_SYS_DC_PRIORITY_CTRL8_C8_LATCNT_BEG_mask                                  (0x000000FF)
#define DC2_SYS_DC_PRIORITY_CTRL8_C8_LATCNT_BEG(data)                                 (0x000000FF&((data)<<0))
#define DC2_SYS_DC_PRIORITY_CTRL8_C8_LATCNT_BEG_src(data)                             ((0x000000FF&(data))>>0)
#define DC2_SYS_DC_PRIORITY_CTRL8_get_C8_LATCNT_BEG(data)                             ((0x000000FF&(data))>>0)


#define DC2_SYS_DC_PRIORITY_CTRL9                                                     0x180030A4
#define DC2_SYS_DC_PRIORITY_CTRL9_reg_addr                                            "0xB80030A4"
#define DC2_SYS_DC_PRIORITY_CTRL9_reg                                                 0xB80030A4
#define set_DC2_SYS_DC_PRIORITY_CTRL9_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PRIORITY_CTRL9_reg)=data)
#define get_DC2_SYS_DC_PRIORITY_CTRL9_reg   (*((volatile unsigned int*) DC2_SYS_DC_PRIORITY_CTRL9_reg))
#define DC2_SYS_DC_PRIORITY_CTRL9_inst_adr                                            "0x0029"
#define DC2_SYS_DC_PRIORITY_CTRL9_inst                                                0x0029
#define DC2_SYS_DC_PRIORITY_CTRL9_C9_LATCNT_END_shift                                 (16)
#define DC2_SYS_DC_PRIORITY_CTRL9_C9_LATCNT_END_mask                                  (0x00FF0000)
#define DC2_SYS_DC_PRIORITY_CTRL9_C9_LATCNT_END(data)                                 (0x00FF0000&((data)<<16))
#define DC2_SYS_DC_PRIORITY_CTRL9_C9_LATCNT_END_src(data)                             ((0x00FF0000&(data))>>16)
#define DC2_SYS_DC_PRIORITY_CTRL9_get_C9_LATCNT_END(data)                             ((0x00FF0000&(data))>>16)
#define DC2_SYS_DC_PRIORITY_CTRL9_C9_LATCNT_BEG_shift                                 (0)
#define DC2_SYS_DC_PRIORITY_CTRL9_C9_LATCNT_BEG_mask                                  (0x000000FF)
#define DC2_SYS_DC_PRIORITY_CTRL9_C9_LATCNT_BEG(data)                                 (0x000000FF&((data)<<0))
#define DC2_SYS_DC_PRIORITY_CTRL9_C9_LATCNT_BEG_src(data)                             ((0x000000FF&(data))>>0)
#define DC2_SYS_DC_PRIORITY_CTRL9_get_C9_LATCNT_BEG(data)                             ((0x000000FF&(data))>>0)


#define DC2_SYS_DC_PRIORITY_CTRLA                                                     0x180030A8
#define DC2_SYS_DC_PRIORITY_CTRLA_reg_addr                                            "0xB80030A8"
#define DC2_SYS_DC_PRIORITY_CTRLA_reg                                                 0xB80030A8
#define set_DC2_SYS_DC_PRIORITY_CTRLA_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PRIORITY_CTRLA_reg)=data)
#define get_DC2_SYS_DC_PRIORITY_CTRLA_reg   (*((volatile unsigned int*) DC2_SYS_DC_PRIORITY_CTRLA_reg))
#define DC2_SYS_DC_PRIORITY_CTRLA_inst_adr                                            "0x002A"
#define DC2_SYS_DC_PRIORITY_CTRLA_inst                                                0x002A
#define DC2_SYS_DC_PRIORITY_CTRLA_CA_LATCNT_END_shift                                 (16)
#define DC2_SYS_DC_PRIORITY_CTRLA_CA_LATCNT_END_mask                                  (0x00FF0000)
#define DC2_SYS_DC_PRIORITY_CTRLA_CA_LATCNT_END(data)                                 (0x00FF0000&((data)<<16))
#define DC2_SYS_DC_PRIORITY_CTRLA_CA_LATCNT_END_src(data)                             ((0x00FF0000&(data))>>16)
#define DC2_SYS_DC_PRIORITY_CTRLA_get_CA_LATCNT_END(data)                             ((0x00FF0000&(data))>>16)
#define DC2_SYS_DC_PRIORITY_CTRLA_CA_LATCNT_BEG_shift                                 (0)
#define DC2_SYS_DC_PRIORITY_CTRLA_CA_LATCNT_BEG_mask                                  (0x000000FF)
#define DC2_SYS_DC_PRIORITY_CTRLA_CA_LATCNT_BEG(data)                                 (0x000000FF&((data)<<0))
#define DC2_SYS_DC_PRIORITY_CTRLA_CA_LATCNT_BEG_src(data)                             ((0x000000FF&(data))>>0)
#define DC2_SYS_DC_PRIORITY_CTRLA_get_CA_LATCNT_BEG(data)                             ((0x000000FF&(data))>>0)


#define DC2_SYS_DC_PRIORITY_CTRLB                                                     0x180030AC
#define DC2_SYS_DC_PRIORITY_CTRLB_reg_addr                                            "0xB80030AC"
#define DC2_SYS_DC_PRIORITY_CTRLB_reg                                                 0xB80030AC
#define set_DC2_SYS_DC_PRIORITY_CTRLB_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PRIORITY_CTRLB_reg)=data)
#define get_DC2_SYS_DC_PRIORITY_CTRLB_reg   (*((volatile unsigned int*) DC2_SYS_DC_PRIORITY_CTRLB_reg))
#define DC2_SYS_DC_PRIORITY_CTRLB_inst_adr                                            "0x002B"
#define DC2_SYS_DC_PRIORITY_CTRLB_inst                                                0x002B
#define DC2_SYS_DC_PRIORITY_CTRLB_CB_LATCNT_END_shift                                 (16)
#define DC2_SYS_DC_PRIORITY_CTRLB_CB_LATCNT_END_mask                                  (0x00FF0000)
#define DC2_SYS_DC_PRIORITY_CTRLB_CB_LATCNT_END(data)                                 (0x00FF0000&((data)<<16))
#define DC2_SYS_DC_PRIORITY_CTRLB_CB_LATCNT_END_src(data)                             ((0x00FF0000&(data))>>16)
#define DC2_SYS_DC_PRIORITY_CTRLB_get_CB_LATCNT_END(data)                             ((0x00FF0000&(data))>>16)
#define DC2_SYS_DC_PRIORITY_CTRLB_CB_LATCNT_BEG_shift                                 (0)
#define DC2_SYS_DC_PRIORITY_CTRLB_CB_LATCNT_BEG_mask                                  (0x000000FF)
#define DC2_SYS_DC_PRIORITY_CTRLB_CB_LATCNT_BEG(data)                                 (0x000000FF&((data)<<0))
#define DC2_SYS_DC_PRIORITY_CTRLB_CB_LATCNT_BEG_src(data)                             ((0x000000FF&(data))>>0)
#define DC2_SYS_DC_PRIORITY_CTRLB_get_CB_LATCNT_BEG(data)                             ((0x000000FF&(data))>>0)


#define DC2_SYS_DC_PRIORITY_CTRLC                                                     0x180030B0
#define DC2_SYS_DC_PRIORITY_CTRLC_reg_addr                                            "0xB80030B0"
#define DC2_SYS_DC_PRIORITY_CTRLC_reg                                                 0xB80030B0
#define set_DC2_SYS_DC_PRIORITY_CTRLC_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PRIORITY_CTRLC_reg)=data)
#define get_DC2_SYS_DC_PRIORITY_CTRLC_reg   (*((volatile unsigned int*) DC2_SYS_DC_PRIORITY_CTRLC_reg))
#define DC2_SYS_DC_PRIORITY_CTRLC_inst_adr                                            "0x002C"
#define DC2_SYS_DC_PRIORITY_CTRLC_inst                                                0x002C
#define DC2_SYS_DC_PRIORITY_CTRLC_CC_LATCNT_END_shift                                 (16)
#define DC2_SYS_DC_PRIORITY_CTRLC_CC_LATCNT_END_mask                                  (0x00FF0000)
#define DC2_SYS_DC_PRIORITY_CTRLC_CC_LATCNT_END(data)                                 (0x00FF0000&((data)<<16))
#define DC2_SYS_DC_PRIORITY_CTRLC_CC_LATCNT_END_src(data)                             ((0x00FF0000&(data))>>16)
#define DC2_SYS_DC_PRIORITY_CTRLC_get_CC_LATCNT_END(data)                             ((0x00FF0000&(data))>>16)
#define DC2_SYS_DC_PRIORITY_CTRLC_CC_LATCNT_BEG_shift                                 (0)
#define DC2_SYS_DC_PRIORITY_CTRLC_CC_LATCNT_BEG_mask                                  (0x000000FF)
#define DC2_SYS_DC_PRIORITY_CTRLC_CC_LATCNT_BEG(data)                                 (0x000000FF&((data)<<0))
#define DC2_SYS_DC_PRIORITY_CTRLC_CC_LATCNT_BEG_src(data)                             ((0x000000FF&(data))>>0)
#define DC2_SYS_DC_PRIORITY_CTRLC_get_CC_LATCNT_BEG(data)                             ((0x000000FF&(data))>>0)


#define DC2_SYS_DC_PRIORITY_CTRL_HIE                                                  0x180030B4
#define DC2_SYS_DC_PRIORITY_CTRL_HIE_reg_addr                                         "0xB80030B4"
#define DC2_SYS_DC_PRIORITY_CTRL_HIE_reg                                              0xB80030B4
#define set_DC2_SYS_DC_PRIORITY_CTRL_HIE_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PRIORITY_CTRL_HIE_reg)=data)
#define get_DC2_SYS_DC_PRIORITY_CTRL_HIE_reg   (*((volatile unsigned int*) DC2_SYS_DC_PRIORITY_CTRL_HIE_reg))
#define DC2_SYS_DC_PRIORITY_CTRL_HIE_inst_adr                                         "0x002D"
#define DC2_SYS_DC_PRIORITY_CTRL_HIE_inst                                             0x002D
#define DC2_SYS_DC_PRIORITY_CTRL_HIE_GPU_LAT_NEW_shift                                (31)
#define DC2_SYS_DC_PRIORITY_CTRL_HIE_GPU_LAT_NEW_mask                                 (0x80000000)
#define DC2_SYS_DC_PRIORITY_CTRL_HIE_GPU_LAT_NEW(data)                                (0x80000000&((data)<<31))
#define DC2_SYS_DC_PRIORITY_CTRL_HIE_GPU_LAT_NEW_src(data)                            ((0x80000000&(data))>>31)
#define DC2_SYS_DC_PRIORITY_CTRL_HIE_get_GPU_LAT_NEW(data)                            ((0x80000000&(data))>>31)
#define DC2_SYS_DC_PRIORITY_CTRL_HIE_HIE_CMP_DIS_shift                                (16)
#define DC2_SYS_DC_PRIORITY_CTRL_HIE_HIE_CMP_DIS_mask                                 (0x1FFF0000)
#define DC2_SYS_DC_PRIORITY_CTRL_HIE_HIE_CMP_DIS(data)                                (0x1FFF0000&((data)<<16))
#define DC2_SYS_DC_PRIORITY_CTRL_HIE_HIE_CMP_DIS_src(data)                            ((0x1FFF0000&(data))>>16)
#define DC2_SYS_DC_PRIORITY_CTRL_HIE_get_HIE_CMP_DIS(data)                            ((0x1FFF0000&(data))>>16)
#define DC2_SYS_DC_PRIORITY_CTRL_HIE_LATCNT_PERIOD_shift                              (0)
#define DC2_SYS_DC_PRIORITY_CTRL_HIE_LATCNT_PERIOD_mask                               (0x000000FF)
#define DC2_SYS_DC_PRIORITY_CTRL_HIE_LATCNT_PERIOD(data)                              (0x000000FF&((data)<<0))
#define DC2_SYS_DC_PRIORITY_CTRL_HIE_LATCNT_PERIOD_src(data)                          ((0x000000FF&(data))>>0)
#define DC2_SYS_DC_PRIORITY_CTRL_HIE_get_LATCNT_PERIOD(data)                          ((0x000000FF&(data))>>0)


#define DC2_SYS_DC_PRIORITY_CTRL_SCPU                                                 0x180030C0
#define DC2_SYS_DC_PRIORITY_CTRL_SCPU_reg_addr                                        "0xB80030C0"
#define DC2_SYS_DC_PRIORITY_CTRL_SCPU_reg                                             0xB80030C0
#define set_DC2_SYS_DC_PRIORITY_CTRL_SCPU_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PRIORITY_CTRL_SCPU_reg)=data)
#define get_DC2_SYS_DC_PRIORITY_CTRL_SCPU_reg   (*((volatile unsigned int*) DC2_SYS_DC_PRIORITY_CTRL_SCPU_reg))
#define DC2_SYS_DC_PRIORITY_CTRL_SCPU_inst_adr                                        "0x0030"
#define DC2_SYS_DC_PRIORITY_CTRL_SCPU_inst                                            0x0030
#define DC2_SYS_DC_PRIORITY_CTRL_SCPU_SCPU_LATCNT_shift                               (0)
#define DC2_SYS_DC_PRIORITY_CTRL_SCPU_SCPU_LATCNT_mask                                (0x000000FF)
#define DC2_SYS_DC_PRIORITY_CTRL_SCPU_SCPU_LATCNT(data)                               (0x000000FF&((data)<<0))
#define DC2_SYS_DC_PRIORITY_CTRL_SCPU_SCPU_LATCNT_src(data)                           ((0x000000FF&(data))>>0)
#define DC2_SYS_DC_PRIORITY_CTRL_SCPU_get_SCPU_LATCNT(data)                           ((0x000000FF&(data))>>0)


#define DC2_SYS_DC_CLIENT_MASK                                                        0x180030D0
#define DC2_SYS_DC_CLIENT_MASK_reg_addr                                               "0xB80030D0"
#define DC2_SYS_DC_CLIENT_MASK_reg                                                    0xB80030D0
#define set_DC2_SYS_DC_CLIENT_MASK_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_CLIENT_MASK_reg)=data)
#define get_DC2_SYS_DC_CLIENT_MASK_reg   (*((volatile unsigned int*) DC2_SYS_DC_CLIENT_MASK_reg))
#define DC2_SYS_DC_CLIENT_MASK_inst_adr                                               "0x0034"
#define DC2_SYS_DC_CLIENT_MASK_inst                                                   0x0034
#define DC2_SYS_DC_CLIENT_MASK_req_mask_index_shift                                   (0)
#define DC2_SYS_DC_CLIENT_MASK_req_mask_index_mask                                    (0x00001FFF)
#define DC2_SYS_DC_CLIENT_MASK_req_mask_index(data)                                   (0x00001FFF&((data)<<0))
#define DC2_SYS_DC_CLIENT_MASK_req_mask_index_src(data)                               ((0x00001FFF&(data))>>0)
#define DC2_SYS_DC_CLIENT_MASK_get_req_mask_index(data)                               ((0x00001FFF&(data))>>0)


#define DC2_SYS_DC_PC_CTRL                                                            0x18003100
#define DC2_SYS_DC_PC_CTRL_reg_addr                                                   "0xB8003100"
#define DC2_SYS_DC_PC_CTRL_reg                                                        0xB8003100
#define set_DC2_SYS_DC_PC_CTRL_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PC_CTRL_reg)=data)
#define get_DC2_SYS_DC_PC_CTRL_reg   (*((volatile unsigned int*) DC2_SYS_DC_PC_CTRL_reg))
#define DC2_SYS_DC_PC_CTRL_inst_adr                                                   "0x0040"
#define DC2_SYS_DC_PC_CTRL_inst                                                       0x0040
#define DC2_SYS_DC_PC_CTRL_pc_go_shift                                                (0)
#define DC2_SYS_DC_PC_CTRL_pc_go_mask                                                 (0x00000001)
#define DC2_SYS_DC_PC_CTRL_pc_go(data)                                                (0x00000001&((data)<<0))
#define DC2_SYS_DC_PC_CTRL_pc_go_src(data)                                            ((0x00000001&(data))>>0)
#define DC2_SYS_DC_PC_CTRL_get_pc_go(data)                                            ((0x00000001&(data))>>0)


#define DC2_SYS_DC_PC_TOTA_MON_NUM                                                    0x18003104
#define DC2_SYS_DC_PC_TOTA_MON_NUM_reg_addr                                           "0xB8003104"
#define DC2_SYS_DC_PC_TOTA_MON_NUM_reg                                                0xB8003104
#define set_DC2_SYS_DC_PC_TOTA_MON_NUM_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PC_TOTA_MON_NUM_reg)=data)
#define get_DC2_SYS_DC_PC_TOTA_MON_NUM_reg   (*((volatile unsigned int*) DC2_SYS_DC_PC_TOTA_MON_NUM_reg))
#define DC2_SYS_DC_PC_TOTA_MON_NUM_inst_adr                                           "0x0041"
#define DC2_SYS_DC_PC_TOTA_MON_NUM_inst                                               0x0041
#define DC2_SYS_DC_PC_TOTA_MON_NUM_pc_tota_mon_num_shift                              (0)
#define DC2_SYS_DC_PC_TOTA_MON_NUM_pc_tota_mon_num_mask                               (0xFFFFFFFF)
#define DC2_SYS_DC_PC_TOTA_MON_NUM_pc_tota_mon_num(data)                              (0xFFFFFFFF&((data)<<0))
#define DC2_SYS_DC_PC_TOTA_MON_NUM_pc_tota_mon_num_src(data)                          ((0xFFFFFFFF&(data))>>0)
#define DC2_SYS_DC_PC_TOTA_MON_NUM_get_pc_tota_mon_num(data)                          ((0xFFFFFFFF&(data))>>0)


#define DC2_SYS_DC_PC_TOTA_ACK_NUM                                                    0x18003108
#define DC2_SYS_DC_PC_TOTA_ACK_NUM_reg_addr                                           "0xB8003108"
#define DC2_SYS_DC_PC_TOTA_ACK_NUM_reg                                                0xB8003108
#define set_DC2_SYS_DC_PC_TOTA_ACK_NUM_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PC_TOTA_ACK_NUM_reg)=data)
#define get_DC2_SYS_DC_PC_TOTA_ACK_NUM_reg   (*((volatile unsigned int*) DC2_SYS_DC_PC_TOTA_ACK_NUM_reg))
#define DC2_SYS_DC_PC_TOTA_ACK_NUM_inst_adr                                           "0x0042"
#define DC2_SYS_DC_PC_TOTA_ACK_NUM_inst                                               0x0042
#define DC2_SYS_DC_PC_TOTA_ACK_NUM_pc_tota_ack_num_shift                              (0)
#define DC2_SYS_DC_PC_TOTA_ACK_NUM_pc_tota_ack_num_mask                               (0xFFFFFFFF)
#define DC2_SYS_DC_PC_TOTA_ACK_NUM_pc_tota_ack_num(data)                              (0xFFFFFFFF&((data)<<0))
#define DC2_SYS_DC_PC_TOTA_ACK_NUM_pc_tota_ack_num_src(data)                          ((0xFFFFFFFF&(data))>>0)
#define DC2_SYS_DC_PC_TOTA_ACK_NUM_get_pc_tota_ack_num(data)                          ((0xFFFFFFFF&(data))>>0)


#define DC2_SYS_DC_PC_TOTA_IDL_NUM                                                    0x1800310C
#define DC2_SYS_DC_PC_TOTA_IDL_NUM_reg_addr                                           "0xB800310C"
#define DC2_SYS_DC_PC_TOTA_IDL_NUM_reg                                                0xB800310C
#define set_DC2_SYS_DC_PC_TOTA_IDL_NUM_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PC_TOTA_IDL_NUM_reg)=data)
#define get_DC2_SYS_DC_PC_TOTA_IDL_NUM_reg   (*((volatile unsigned int*) DC2_SYS_DC_PC_TOTA_IDL_NUM_reg))
#define DC2_SYS_DC_PC_TOTA_IDL_NUM_inst_adr                                           "0x0043"
#define DC2_SYS_DC_PC_TOTA_IDL_NUM_inst                                               0x0043
#define DC2_SYS_DC_PC_TOTA_IDL_NUM_pc_tota_idl_num_shift                              (0)
#define DC2_SYS_DC_PC_TOTA_IDL_NUM_pc_tota_idl_num_mask                               (0xFFFFFFFF)
#define DC2_SYS_DC_PC_TOTA_IDL_NUM_pc_tota_idl_num(data)                              (0xFFFFFFFF&((data)<<0))
#define DC2_SYS_DC_PC_TOTA_IDL_NUM_pc_tota_idl_num_src(data)                          ((0xFFFFFFFF&(data))>>0)
#define DC2_SYS_DC_PC_TOTA_IDL_NUM_get_pc_tota_idl_num(data)                          ((0xFFFFFFFF&(data))>>0)


#define DC2_SYS_DC_PC_SYSH_PROG_CTRL                                                  0x18003110
#define DC2_SYS_DC_PC_SYSH_PROG_CTRL_reg_addr                                         "0xB8003110"
#define DC2_SYS_DC_PC_SYSH_PROG_CTRL_reg                                              0xB8003110
#define set_DC2_SYS_DC_PC_SYSH_PROG_CTRL_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYSH_PROG_CTRL_reg)=data)
#define get_DC2_SYS_DC_PC_SYSH_PROG_CTRL_reg   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYSH_PROG_CTRL_reg))
#define DC2_SYS_DC_PC_SYSH_PROG_CTRL_inst_adr                                         "0x0044"
#define DC2_SYS_DC_PC_SYSH_PROG_CTRL_inst                                             0x0044
#define DC2_SYS_DC_PC_SYSH_PROG_CTRL_write_en_3_shift                                 (23)
#define DC2_SYS_DC_PC_SYSH_PROG_CTRL_write_en_3_mask                                  (0x00800000)
#define DC2_SYS_DC_PC_SYSH_PROG_CTRL_write_en_3(data)                                 (0x00800000&((data)<<23))
#define DC2_SYS_DC_PC_SYSH_PROG_CTRL_write_en_3_src(data)                             ((0x00800000&(data))>>23)
#define DC2_SYS_DC_PC_SYSH_PROG_CTRL_get_write_en_3(data)                             ((0x00800000&(data))>>23)
#define DC2_SYS_DC_PC_SYSH_PROG_CTRL_pc_sysh_prog2_sel_shift                          (16)
#define DC2_SYS_DC_PC_SYSH_PROG_CTRL_pc_sysh_prog2_sel_mask                           (0x007F0000)
#define DC2_SYS_DC_PC_SYSH_PROG_CTRL_pc_sysh_prog2_sel(data)                          (0x007F0000&((data)<<16))
#define DC2_SYS_DC_PC_SYSH_PROG_CTRL_pc_sysh_prog2_sel_src(data)                      ((0x007F0000&(data))>>16)
#define DC2_SYS_DC_PC_SYSH_PROG_CTRL_get_pc_sysh_prog2_sel(data)                      ((0x007F0000&(data))>>16)
#define DC2_SYS_DC_PC_SYSH_PROG_CTRL_write_en_2_shift                                 (15)
#define DC2_SYS_DC_PC_SYSH_PROG_CTRL_write_en_2_mask                                  (0x00008000)
#define DC2_SYS_DC_PC_SYSH_PROG_CTRL_write_en_2(data)                                 (0x00008000&((data)<<15))
#define DC2_SYS_DC_PC_SYSH_PROG_CTRL_write_en_2_src(data)                             ((0x00008000&(data))>>15)
#define DC2_SYS_DC_PC_SYSH_PROG_CTRL_get_write_en_2(data)                             ((0x00008000&(data))>>15)
#define DC2_SYS_DC_PC_SYSH_PROG_CTRL_pc_sysh_prog1_sel_shift                          (8)
#define DC2_SYS_DC_PC_SYSH_PROG_CTRL_pc_sysh_prog1_sel_mask                           (0x00007F00)
#define DC2_SYS_DC_PC_SYSH_PROG_CTRL_pc_sysh_prog1_sel(data)                          (0x00007F00&((data)<<8))
#define DC2_SYS_DC_PC_SYSH_PROG_CTRL_pc_sysh_prog1_sel_src(data)                      ((0x00007F00&(data))>>8)
#define DC2_SYS_DC_PC_SYSH_PROG_CTRL_get_pc_sysh_prog1_sel(data)                      ((0x00007F00&(data))>>8)
#define DC2_SYS_DC_PC_SYSH_PROG_CTRL_write_en_1_shift                                 (7)
#define DC2_SYS_DC_PC_SYSH_PROG_CTRL_write_en_1_mask                                  (0x00000080)
#define DC2_SYS_DC_PC_SYSH_PROG_CTRL_write_en_1(data)                                 (0x00000080&((data)<<7))
#define DC2_SYS_DC_PC_SYSH_PROG_CTRL_write_en_1_src(data)                             ((0x00000080&(data))>>7)
#define DC2_SYS_DC_PC_SYSH_PROG_CTRL_get_write_en_1(data)                             ((0x00000080&(data))>>7)
#define DC2_SYS_DC_PC_SYSH_PROG_CTRL_pc_sysh_prog0_sel_shift                          (0)
#define DC2_SYS_DC_PC_SYSH_PROG_CTRL_pc_sysh_prog0_sel_mask                           (0x0000007F)
#define DC2_SYS_DC_PC_SYSH_PROG_CTRL_pc_sysh_prog0_sel(data)                          (0x0000007F&((data)<<0))
#define DC2_SYS_DC_PC_SYSH_PROG_CTRL_pc_sysh_prog0_sel_src(data)                      ((0x0000007F&(data))>>0)
#define DC2_SYS_DC_PC_SYSH_PROG_CTRL_get_pc_sysh_prog0_sel(data)                      ((0x0000007F&(data))>>0)


#define DC2_SYS_DC_PC_SYS_PROG_CTRL1                                                  0x18003120
#define DC2_SYS_DC_PC_SYS_PROG_CTRL1_reg_addr                                         "0xB8003120"
#define DC2_SYS_DC_PC_SYS_PROG_CTRL1_reg                                              0xB8003120
#define set_DC2_SYS_DC_PC_SYS_PROG_CTRL1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYS_PROG_CTRL1_reg)=data)
#define get_DC2_SYS_DC_PC_SYS_PROG_CTRL1_reg   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYS_PROG_CTRL1_reg))
#define DC2_SYS_DC_PC_SYS_PROG_CTRL1_inst_adr                                         "0x0048"
#define DC2_SYS_DC_PC_SYS_PROG_CTRL1_inst                                             0x0048
#define DC2_SYS_DC_PC_SYS_PROG_CTRL1_pc_sysh_prog2_req_occur_shift                    (6)
#define DC2_SYS_DC_PC_SYS_PROG_CTRL1_pc_sysh_prog2_req_occur_mask                     (0x00000040)
#define DC2_SYS_DC_PC_SYS_PROG_CTRL1_pc_sysh_prog2_req_occur(data)                    (0x00000040&((data)<<6))
#define DC2_SYS_DC_PC_SYS_PROG_CTRL1_pc_sysh_prog2_req_occur_src(data)                ((0x00000040&(data))>>6)
#define DC2_SYS_DC_PC_SYS_PROG_CTRL1_get_pc_sysh_prog2_req_occur(data)                ((0x00000040&(data))>>6)
#define DC2_SYS_DC_PC_SYS_PROG_CTRL1_pc_sysh_prog1_req_occur_shift                    (5)
#define DC2_SYS_DC_PC_SYS_PROG_CTRL1_pc_sysh_prog1_req_occur_mask                     (0x00000020)
#define DC2_SYS_DC_PC_SYS_PROG_CTRL1_pc_sysh_prog1_req_occur(data)                    (0x00000020&((data)<<5))
#define DC2_SYS_DC_PC_SYS_PROG_CTRL1_pc_sysh_prog1_req_occur_src(data)                ((0x00000020&(data))>>5)
#define DC2_SYS_DC_PC_SYS_PROG_CTRL1_get_pc_sysh_prog1_req_occur(data)                ((0x00000020&(data))>>5)
#define DC2_SYS_DC_PC_SYS_PROG_CTRL1_pc_sysh_prog0_req_occur_shift                    (4)
#define DC2_SYS_DC_PC_SYS_PROG_CTRL1_pc_sysh_prog0_req_occur_mask                     (0x00000010)
#define DC2_SYS_DC_PC_SYS_PROG_CTRL1_pc_sysh_prog0_req_occur(data)                    (0x00000010&((data)<<4))
#define DC2_SYS_DC_PC_SYS_PROG_CTRL1_pc_sysh_prog0_req_occur_src(data)                ((0x00000010&(data))>>4)
#define DC2_SYS_DC_PC_SYS_PROG_CTRL1_get_pc_sysh_prog0_req_occur(data)                ((0x00000010&(data))>>4)


#define DC2_SYS_DC_PC_SYSH_PROG_0_ACC_LAT                                             0x18003130
#define DC2_SYS_DC_PC_SYSH_PROG_0_ACC_LAT_reg_addr                                    "0xB8003130"
#define DC2_SYS_DC_PC_SYSH_PROG_0_ACC_LAT_reg                                         0xB8003130
#define set_DC2_SYS_DC_PC_SYSH_PROG_0_ACC_LAT_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYSH_PROG_0_ACC_LAT_reg)=data)
#define get_DC2_SYS_DC_PC_SYSH_PROG_0_ACC_LAT_reg   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYSH_PROG_0_ACC_LAT_reg))
#define DC2_SYS_DC_PC_SYSH_PROG_0_ACC_LAT_inst_adr                                    "0x004C"
#define DC2_SYS_DC_PC_SYSH_PROG_0_ACC_LAT_inst                                        0x004C
#define DC2_SYS_DC_PC_SYSH_PROG_0_ACC_LAT_sysh_prog0_acc_lat_shift                    (0)
#define DC2_SYS_DC_PC_SYSH_PROG_0_ACC_LAT_sysh_prog0_acc_lat_mask                     (0xFFFFFFFF)
#define DC2_SYS_DC_PC_SYSH_PROG_0_ACC_LAT_sysh_prog0_acc_lat(data)                    (0xFFFFFFFF&((data)<<0))
#define DC2_SYS_DC_PC_SYSH_PROG_0_ACC_LAT_sysh_prog0_acc_lat_src(data)                ((0xFFFFFFFF&(data))>>0)
#define DC2_SYS_DC_PC_SYSH_PROG_0_ACC_LAT_get_sysh_prog0_acc_lat(data)                ((0xFFFFFFFF&(data))>>0)


#define DC2_SYS_DC_PC_SYSH_PROG_0_MAX_LAT                                             0x18003134
#define DC2_SYS_DC_PC_SYSH_PROG_0_MAX_LAT_reg_addr                                    "0xB8003134"
#define DC2_SYS_DC_PC_SYSH_PROG_0_MAX_LAT_reg                                         0xB8003134
#define set_DC2_SYS_DC_PC_SYSH_PROG_0_MAX_LAT_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYSH_PROG_0_MAX_LAT_reg)=data)
#define get_DC2_SYS_DC_PC_SYSH_PROG_0_MAX_LAT_reg   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYSH_PROG_0_MAX_LAT_reg))
#define DC2_SYS_DC_PC_SYSH_PROG_0_MAX_LAT_inst_adr                                    "0x004D"
#define DC2_SYS_DC_PC_SYSH_PROG_0_MAX_LAT_inst                                        0x004D
#define DC2_SYS_DC_PC_SYSH_PROG_0_MAX_LAT_sysh_prog0_max_lat_shift                    (0)
#define DC2_SYS_DC_PC_SYSH_PROG_0_MAX_LAT_sysh_prog0_max_lat_mask                     (0x0000FFFF)
#define DC2_SYS_DC_PC_SYSH_PROG_0_MAX_LAT_sysh_prog0_max_lat(data)                    (0x0000FFFF&((data)<<0))
#define DC2_SYS_DC_PC_SYSH_PROG_0_MAX_LAT_sysh_prog0_max_lat_src(data)                ((0x0000FFFF&(data))>>0)
#define DC2_SYS_DC_PC_SYSH_PROG_0_MAX_LAT_get_sysh_prog0_max_lat(data)                ((0x0000FFFF&(data))>>0)


#define DC2_SYS_DC_PC_SYSH_PROG_0_REQ_NUM                                             0x18003138
#define DC2_SYS_DC_PC_SYSH_PROG_0_REQ_NUM_reg_addr                                    "0xB8003138"
#define DC2_SYS_DC_PC_SYSH_PROG_0_REQ_NUM_reg                                         0xB8003138
#define set_DC2_SYS_DC_PC_SYSH_PROG_0_REQ_NUM_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYSH_PROG_0_REQ_NUM_reg)=data)
#define get_DC2_SYS_DC_PC_SYSH_PROG_0_REQ_NUM_reg   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYSH_PROG_0_REQ_NUM_reg))
#define DC2_SYS_DC_PC_SYSH_PROG_0_REQ_NUM_inst_adr                                    "0x004E"
#define DC2_SYS_DC_PC_SYSH_PROG_0_REQ_NUM_inst                                        0x004E
#define DC2_SYS_DC_PC_SYSH_PROG_0_REQ_NUM_sysh_prog0_req_num_shift                    (0)
#define DC2_SYS_DC_PC_SYSH_PROG_0_REQ_NUM_sysh_prog0_req_num_mask                     (0x00FFFFFF)
#define DC2_SYS_DC_PC_SYSH_PROG_0_REQ_NUM_sysh_prog0_req_num(data)                    (0x00FFFFFF&((data)<<0))
#define DC2_SYS_DC_PC_SYSH_PROG_0_REQ_NUM_sysh_prog0_req_num_src(data)                ((0x00FFFFFF&(data))>>0)
#define DC2_SYS_DC_PC_SYSH_PROG_0_REQ_NUM_get_sysh_prog0_req_num(data)                ((0x00FFFFFF&(data))>>0)


#define DC2_SYS_DC_PC_SYSH_PROG_0_ACK_NUM                                             0x1800313C
#define DC2_SYS_DC_PC_SYSH_PROG_0_ACK_NUM_reg_addr                                    "0xB800313C"
#define DC2_SYS_DC_PC_SYSH_PROG_0_ACK_NUM_reg                                         0xB800313C
#define set_DC2_SYS_DC_PC_SYSH_PROG_0_ACK_NUM_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYSH_PROG_0_ACK_NUM_reg)=data)
#define get_DC2_SYS_DC_PC_SYSH_PROG_0_ACK_NUM_reg   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYSH_PROG_0_ACK_NUM_reg))
#define DC2_SYS_DC_PC_SYSH_PROG_0_ACK_NUM_inst_adr                                    "0x004F"
#define DC2_SYS_DC_PC_SYSH_PROG_0_ACK_NUM_inst                                        0x004F
#define DC2_SYS_DC_PC_SYSH_PROG_0_ACK_NUM_sysh_prog0_ack_num_shift                    (0)
#define DC2_SYS_DC_PC_SYSH_PROG_0_ACK_NUM_sysh_prog0_ack_num_mask                     (0xFFFFFFFF)
#define DC2_SYS_DC_PC_SYSH_PROG_0_ACK_NUM_sysh_prog0_ack_num(data)                    (0xFFFFFFFF&((data)<<0))
#define DC2_SYS_DC_PC_SYSH_PROG_0_ACK_NUM_sysh_prog0_ack_num_src(data)                ((0xFFFFFFFF&(data))>>0)
#define DC2_SYS_DC_PC_SYSH_PROG_0_ACK_NUM_get_sysh_prog0_ack_num(data)                ((0xFFFFFFFF&(data))>>0)


#define DC2_SYS_DC_PC_SYSH_PROG_1_ACC_LAT                                             0x18003140
#define DC2_SYS_DC_PC_SYSH_PROG_1_ACC_LAT_reg_addr                                    "0xB8003140"
#define DC2_SYS_DC_PC_SYSH_PROG_1_ACC_LAT_reg                                         0xB8003140
#define set_DC2_SYS_DC_PC_SYSH_PROG_1_ACC_LAT_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYSH_PROG_1_ACC_LAT_reg)=data)
#define get_DC2_SYS_DC_PC_SYSH_PROG_1_ACC_LAT_reg   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYSH_PROG_1_ACC_LAT_reg))
#define DC2_SYS_DC_PC_SYSH_PROG_1_ACC_LAT_inst_adr                                    "0x0050"
#define DC2_SYS_DC_PC_SYSH_PROG_1_ACC_LAT_inst                                        0x0050
#define DC2_SYS_DC_PC_SYSH_PROG_1_ACC_LAT_sysh_prog1_acc_lat_shift                    (0)
#define DC2_SYS_DC_PC_SYSH_PROG_1_ACC_LAT_sysh_prog1_acc_lat_mask                     (0xFFFFFFFF)
#define DC2_SYS_DC_PC_SYSH_PROG_1_ACC_LAT_sysh_prog1_acc_lat(data)                    (0xFFFFFFFF&((data)<<0))
#define DC2_SYS_DC_PC_SYSH_PROG_1_ACC_LAT_sysh_prog1_acc_lat_src(data)                ((0xFFFFFFFF&(data))>>0)
#define DC2_SYS_DC_PC_SYSH_PROG_1_ACC_LAT_get_sysh_prog1_acc_lat(data)                ((0xFFFFFFFF&(data))>>0)


#define DC2_SYS_DC_PC_SYSH_PROG_1_MAX_LAT                                             0x18003144
#define DC2_SYS_DC_PC_SYSH_PROG_1_MAX_LAT_reg_addr                                    "0xB8003144"
#define DC2_SYS_DC_PC_SYSH_PROG_1_MAX_LAT_reg                                         0xB8003144
#define set_DC2_SYS_DC_PC_SYSH_PROG_1_MAX_LAT_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYSH_PROG_1_MAX_LAT_reg)=data)
#define get_DC2_SYS_DC_PC_SYSH_PROG_1_MAX_LAT_reg   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYSH_PROG_1_MAX_LAT_reg))
#define DC2_SYS_DC_PC_SYSH_PROG_1_MAX_LAT_inst_adr                                    "0x0051"
#define DC2_SYS_DC_PC_SYSH_PROG_1_MAX_LAT_inst                                        0x0051
#define DC2_SYS_DC_PC_SYSH_PROG_1_MAX_LAT_sysh_prog1_max_lat_shift                    (0)
#define DC2_SYS_DC_PC_SYSH_PROG_1_MAX_LAT_sysh_prog1_max_lat_mask                     (0x0000FFFF)
#define DC2_SYS_DC_PC_SYSH_PROG_1_MAX_LAT_sysh_prog1_max_lat(data)                    (0x0000FFFF&((data)<<0))
#define DC2_SYS_DC_PC_SYSH_PROG_1_MAX_LAT_sysh_prog1_max_lat_src(data)                ((0x0000FFFF&(data))>>0)
#define DC2_SYS_DC_PC_SYSH_PROG_1_MAX_LAT_get_sysh_prog1_max_lat(data)                ((0x0000FFFF&(data))>>0)


#define DC2_SYS_DC_PC_SYSH_PROG_1_REQ_NUM                                             0x18003148
#define DC2_SYS_DC_PC_SYSH_PROG_1_REQ_NUM_reg_addr                                    "0xB8003148"
#define DC2_SYS_DC_PC_SYSH_PROG_1_REQ_NUM_reg                                         0xB8003148
#define set_DC2_SYS_DC_PC_SYSH_PROG_1_REQ_NUM_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYSH_PROG_1_REQ_NUM_reg)=data)
#define get_DC2_SYS_DC_PC_SYSH_PROG_1_REQ_NUM_reg   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYSH_PROG_1_REQ_NUM_reg))
#define DC2_SYS_DC_PC_SYSH_PROG_1_REQ_NUM_inst_adr                                    "0x0052"
#define DC2_SYS_DC_PC_SYSH_PROG_1_REQ_NUM_inst                                        0x0052
#define DC2_SYS_DC_PC_SYSH_PROG_1_REQ_NUM_sysh_prog1_req_num_shift                    (0)
#define DC2_SYS_DC_PC_SYSH_PROG_1_REQ_NUM_sysh_prog1_req_num_mask                     (0x00FFFFFF)
#define DC2_SYS_DC_PC_SYSH_PROG_1_REQ_NUM_sysh_prog1_req_num(data)                    (0x00FFFFFF&((data)<<0))
#define DC2_SYS_DC_PC_SYSH_PROG_1_REQ_NUM_sysh_prog1_req_num_src(data)                ((0x00FFFFFF&(data))>>0)
#define DC2_SYS_DC_PC_SYSH_PROG_1_REQ_NUM_get_sysh_prog1_req_num(data)                ((0x00FFFFFF&(data))>>0)


#define DC2_SYS_DC_PC_SYSH_PROG_1_ACK_NUM                                             0x1800314C
#define DC2_SYS_DC_PC_SYSH_PROG_1_ACK_NUM_reg_addr                                    "0xB800314C"
#define DC2_SYS_DC_PC_SYSH_PROG_1_ACK_NUM_reg                                         0xB800314C
#define set_DC2_SYS_DC_PC_SYSH_PROG_1_ACK_NUM_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYSH_PROG_1_ACK_NUM_reg)=data)
#define get_DC2_SYS_DC_PC_SYSH_PROG_1_ACK_NUM_reg   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYSH_PROG_1_ACK_NUM_reg))
#define DC2_SYS_DC_PC_SYSH_PROG_1_ACK_NUM_inst_adr                                    "0x0053"
#define DC2_SYS_DC_PC_SYSH_PROG_1_ACK_NUM_inst                                        0x0053
#define DC2_SYS_DC_PC_SYSH_PROG_1_ACK_NUM_sysh_prog1_ack_num_shift                    (0)
#define DC2_SYS_DC_PC_SYSH_PROG_1_ACK_NUM_sysh_prog1_ack_num_mask                     (0xFFFFFFFF)
#define DC2_SYS_DC_PC_SYSH_PROG_1_ACK_NUM_sysh_prog1_ack_num(data)                    (0xFFFFFFFF&((data)<<0))
#define DC2_SYS_DC_PC_SYSH_PROG_1_ACK_NUM_sysh_prog1_ack_num_src(data)                ((0xFFFFFFFF&(data))>>0)
#define DC2_SYS_DC_PC_SYSH_PROG_1_ACK_NUM_get_sysh_prog1_ack_num(data)                ((0xFFFFFFFF&(data))>>0)


#define DC2_SYS_DC_PC_SYSH_PROG_2_ACC_LAT                                             0x18003150
#define DC2_SYS_DC_PC_SYSH_PROG_2_ACC_LAT_reg_addr                                    "0xB8003150"
#define DC2_SYS_DC_PC_SYSH_PROG_2_ACC_LAT_reg                                         0xB8003150
#define set_DC2_SYS_DC_PC_SYSH_PROG_2_ACC_LAT_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYSH_PROG_2_ACC_LAT_reg)=data)
#define get_DC2_SYS_DC_PC_SYSH_PROG_2_ACC_LAT_reg   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYSH_PROG_2_ACC_LAT_reg))
#define DC2_SYS_DC_PC_SYSH_PROG_2_ACC_LAT_inst_adr                                    "0x0054"
#define DC2_SYS_DC_PC_SYSH_PROG_2_ACC_LAT_inst                                        0x0054
#define DC2_SYS_DC_PC_SYSH_PROG_2_ACC_LAT_sysh_prog2_acc_lat_shift                    (0)
#define DC2_SYS_DC_PC_SYSH_PROG_2_ACC_LAT_sysh_prog2_acc_lat_mask                     (0xFFFFFFFF)
#define DC2_SYS_DC_PC_SYSH_PROG_2_ACC_LAT_sysh_prog2_acc_lat(data)                    (0xFFFFFFFF&((data)<<0))
#define DC2_SYS_DC_PC_SYSH_PROG_2_ACC_LAT_sysh_prog2_acc_lat_src(data)                ((0xFFFFFFFF&(data))>>0)
#define DC2_SYS_DC_PC_SYSH_PROG_2_ACC_LAT_get_sysh_prog2_acc_lat(data)                ((0xFFFFFFFF&(data))>>0)


#define DC2_SYS_DC_PC_SYSH_PROG_2_MAX_LAT                                             0x18003154
#define DC2_SYS_DC_PC_SYSH_PROG_2_MAX_LAT_reg_addr                                    "0xB8003154"
#define DC2_SYS_DC_PC_SYSH_PROG_2_MAX_LAT_reg                                         0xB8003154
#define set_DC2_SYS_DC_PC_SYSH_PROG_2_MAX_LAT_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYSH_PROG_2_MAX_LAT_reg)=data)
#define get_DC2_SYS_DC_PC_SYSH_PROG_2_MAX_LAT_reg   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYSH_PROG_2_MAX_LAT_reg))
#define DC2_SYS_DC_PC_SYSH_PROG_2_MAX_LAT_inst_adr                                    "0x0055"
#define DC2_SYS_DC_PC_SYSH_PROG_2_MAX_LAT_inst                                        0x0055
#define DC2_SYS_DC_PC_SYSH_PROG_2_MAX_LAT_sysh_prog2_max_lat_shift                    (0)
#define DC2_SYS_DC_PC_SYSH_PROG_2_MAX_LAT_sysh_prog2_max_lat_mask                     (0x0000FFFF)
#define DC2_SYS_DC_PC_SYSH_PROG_2_MAX_LAT_sysh_prog2_max_lat(data)                    (0x0000FFFF&((data)<<0))
#define DC2_SYS_DC_PC_SYSH_PROG_2_MAX_LAT_sysh_prog2_max_lat_src(data)                ((0x0000FFFF&(data))>>0)
#define DC2_SYS_DC_PC_SYSH_PROG_2_MAX_LAT_get_sysh_prog2_max_lat(data)                ((0x0000FFFF&(data))>>0)


#define DC2_SYS_DC_PC_SYSH_PROG_2_REQ_NUM                                             0x18003158
#define DC2_SYS_DC_PC_SYSH_PROG_2_REQ_NUM_reg_addr                                    "0xB8003158"
#define DC2_SYS_DC_PC_SYSH_PROG_2_REQ_NUM_reg                                         0xB8003158
#define set_DC2_SYS_DC_PC_SYSH_PROG_2_REQ_NUM_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYSH_PROG_2_REQ_NUM_reg)=data)
#define get_DC2_SYS_DC_PC_SYSH_PROG_2_REQ_NUM_reg   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYSH_PROG_2_REQ_NUM_reg))
#define DC2_SYS_DC_PC_SYSH_PROG_2_REQ_NUM_inst_adr                                    "0x0056"
#define DC2_SYS_DC_PC_SYSH_PROG_2_REQ_NUM_inst                                        0x0056
#define DC2_SYS_DC_PC_SYSH_PROG_2_REQ_NUM_sysh_prog2_req_num_shift                    (0)
#define DC2_SYS_DC_PC_SYSH_PROG_2_REQ_NUM_sysh_prog2_req_num_mask                     (0x00FFFFFF)
#define DC2_SYS_DC_PC_SYSH_PROG_2_REQ_NUM_sysh_prog2_req_num(data)                    (0x00FFFFFF&((data)<<0))
#define DC2_SYS_DC_PC_SYSH_PROG_2_REQ_NUM_sysh_prog2_req_num_src(data)                ((0x00FFFFFF&(data))>>0)
#define DC2_SYS_DC_PC_SYSH_PROG_2_REQ_NUM_get_sysh_prog2_req_num(data)                ((0x00FFFFFF&(data))>>0)


#define DC2_SYS_DC_PC_SYSH_PROG_2_ACK_NUM                                             0x1800315C
#define DC2_SYS_DC_PC_SYSH_PROG_2_ACK_NUM_reg_addr                                    "0xB800315C"
#define DC2_SYS_DC_PC_SYSH_PROG_2_ACK_NUM_reg                                         0xB800315C
#define set_DC2_SYS_DC_PC_SYSH_PROG_2_ACK_NUM_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYSH_PROG_2_ACK_NUM_reg)=data)
#define get_DC2_SYS_DC_PC_SYSH_PROG_2_ACK_NUM_reg   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYSH_PROG_2_ACK_NUM_reg))
#define DC2_SYS_DC_PC_SYSH_PROG_2_ACK_NUM_inst_adr                                    "0x0057"
#define DC2_SYS_DC_PC_SYSH_PROG_2_ACK_NUM_inst                                        0x0057
#define DC2_SYS_DC_PC_SYSH_PROG_2_ACK_NUM_sysh_prog2_ack_num_shift                    (0)
#define DC2_SYS_DC_PC_SYSH_PROG_2_ACK_NUM_sysh_prog2_ack_num_mask                     (0xFFFFFFFF)
#define DC2_SYS_DC_PC_SYSH_PROG_2_ACK_NUM_sysh_prog2_ack_num(data)                    (0xFFFFFFFF&((data)<<0))
#define DC2_SYS_DC_PC_SYSH_PROG_2_ACK_NUM_sysh_prog2_ack_num_src(data)                ((0xFFFFFFFF&(data))>>0)
#define DC2_SYS_DC_PC_SYSH_PROG_2_ACK_NUM_get_sysh_prog2_ack_num(data)                ((0xFFFFFFFF&(data))>>0)


#define DC2_SYS_DC_PC_SYSH_PROG_0                                                     0x18003190
#define DC2_SYS_DC_PC_SYSH_PROG_0_reg_addr                                            "0xB8003190"
#define DC2_SYS_DC_PC_SYSH_PROG_0_reg                                                 0xB8003190
#define set_DC2_SYS_DC_PC_SYSH_PROG_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYSH_PROG_0_reg)=data)
#define get_DC2_SYS_DC_PC_SYSH_PROG_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYSH_PROG_0_reg))
#define DC2_SYS_DC_PC_SYSH_PROG_0_inst_adr                                            "0x0064"
#define DC2_SYS_DC_PC_SYSH_PROG_0_inst                                                0x0064
#define DC2_SYS_DC_PC_SYSH_PROG_0_sysh0_hitend_cnt_shift                              (0)
#define DC2_SYS_DC_PC_SYSH_PROG_0_sysh0_hitend_cnt_mask                               (0x0000FFFF)
#define DC2_SYS_DC_PC_SYSH_PROG_0_sysh0_hitend_cnt(data)                              (0x0000FFFF&((data)<<0))
#define DC2_SYS_DC_PC_SYSH_PROG_0_sysh0_hitend_cnt_src(data)                          ((0x0000FFFF&(data))>>0)
#define DC2_SYS_DC_PC_SYSH_PROG_0_get_sysh0_hitend_cnt(data)                          ((0x0000FFFF&(data))>>0)


#define DC2_SYS_DC_PC_SYSH_PROG_1                                                     0x18003194
#define DC2_SYS_DC_PC_SYSH_PROG_1_reg_addr                                            "0xB8003194"
#define DC2_SYS_DC_PC_SYSH_PROG_1_reg                                                 0xB8003194
#define set_DC2_SYS_DC_PC_SYSH_PROG_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYSH_PROG_1_reg)=data)
#define get_DC2_SYS_DC_PC_SYSH_PROG_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYSH_PROG_1_reg))
#define DC2_SYS_DC_PC_SYSH_PROG_1_inst_adr                                            "0x0065"
#define DC2_SYS_DC_PC_SYSH_PROG_1_inst                                                0x0065
#define DC2_SYS_DC_PC_SYSH_PROG_1_sysh1_hitend_cnt_shift                              (0)
#define DC2_SYS_DC_PC_SYSH_PROG_1_sysh1_hitend_cnt_mask                               (0x0000FFFF)
#define DC2_SYS_DC_PC_SYSH_PROG_1_sysh1_hitend_cnt(data)                              (0x0000FFFF&((data)<<0))
#define DC2_SYS_DC_PC_SYSH_PROG_1_sysh1_hitend_cnt_src(data)                          ((0x0000FFFF&(data))>>0)
#define DC2_SYS_DC_PC_SYSH_PROG_1_get_sysh1_hitend_cnt(data)                          ((0x0000FFFF&(data))>>0)


#define DC2_SYS_DC_PC_SYSH_PROG_2                                                     0x18003198
#define DC2_SYS_DC_PC_SYSH_PROG_2_reg_addr                                            "0xB8003198"
#define DC2_SYS_DC_PC_SYSH_PROG_2_reg                                                 0xB8003198
#define set_DC2_SYS_DC_PC_SYSH_PROG_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYSH_PROG_2_reg)=data)
#define get_DC2_SYS_DC_PC_SYSH_PROG_2_reg   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYSH_PROG_2_reg))
#define DC2_SYS_DC_PC_SYSH_PROG_2_inst_adr                                            "0x0066"
#define DC2_SYS_DC_PC_SYSH_PROG_2_inst                                                0x0066
#define DC2_SYS_DC_PC_SYSH_PROG_2_sysh2_hitend_cnt_shift                              (0)
#define DC2_SYS_DC_PC_SYSH_PROG_2_sysh2_hitend_cnt_mask                               (0x0000FFFF)
#define DC2_SYS_DC_PC_SYSH_PROG_2_sysh2_hitend_cnt(data)                              (0x0000FFFF&((data)<<0))
#define DC2_SYS_DC_PC_SYSH_PROG_2_sysh2_hitend_cnt_src(data)                          ((0x0000FFFF&(data))>>0)
#define DC2_SYS_DC_PC_SYSH_PROG_2_get_sysh2_hitend_cnt(data)                          ((0x0000FFFF&(data))>>0)


#define DC2_SYS_DC_BIST_MODE                                                          0x180031C0
#define DC2_SYS_DC_BIST_MODE_reg_addr                                                 "0xB80031C0"
#define DC2_SYS_DC_BIST_MODE_reg                                                      0xB80031C0
#define set_DC2_SYS_DC_BIST_MODE_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_BIST_MODE_reg)=data)
#define get_DC2_SYS_DC_BIST_MODE_reg   (*((volatile unsigned int*) DC2_SYS_DC_BIST_MODE_reg))
#define DC2_SYS_DC_BIST_MODE_inst_adr                                                 "0x0070"
#define DC2_SYS_DC_BIST_MODE_inst                                                     0x0070
#define DC2_SYS_DC_BIST_MODE_DC_BIST_MODE_PICT0_shift                                 (1)
#define DC2_SYS_DC_BIST_MODE_DC_BIST_MODE_PICT0_mask                                  (0x00000002)
#define DC2_SYS_DC_BIST_MODE_DC_BIST_MODE_PICT0(data)                                 (0x00000002&((data)<<1))
#define DC2_SYS_DC_BIST_MODE_DC_BIST_MODE_PICT0_src(data)                             ((0x00000002&(data))>>1)
#define DC2_SYS_DC_BIST_MODE_get_DC_BIST_MODE_PICT0(data)                             ((0x00000002&(data))>>1)


#define DC2_SYS_DC_BIST_DONE                                                          0x180031C4
#define DC2_SYS_DC_BIST_DONE_reg_addr                                                 "0xB80031C4"
#define DC2_SYS_DC_BIST_DONE_reg                                                      0xB80031C4
#define set_DC2_SYS_DC_BIST_DONE_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_BIST_DONE_reg)=data)
#define get_DC2_SYS_DC_BIST_DONE_reg   (*((volatile unsigned int*) DC2_SYS_DC_BIST_DONE_reg))
#define DC2_SYS_DC_BIST_DONE_inst_adr                                                 "0x0071"
#define DC2_SYS_DC_BIST_DONE_inst                                                     0x0071
#define DC2_SYS_DC_BIST_DONE_DC_BIST_DONE_PICT0_shift                                 (1)
#define DC2_SYS_DC_BIST_DONE_DC_BIST_DONE_PICT0_mask                                  (0x00000002)
#define DC2_SYS_DC_BIST_DONE_DC_BIST_DONE_PICT0(data)                                 (0x00000002&((data)<<1))
#define DC2_SYS_DC_BIST_DONE_DC_BIST_DONE_PICT0_src(data)                             ((0x00000002&(data))>>1)
#define DC2_SYS_DC_BIST_DONE_get_DC_BIST_DONE_PICT0(data)                             ((0x00000002&(data))>>1)


#define DC2_SYS_DC_BIST_FAIL                                                          0x180031C8
#define DC2_SYS_DC_BIST_FAIL_reg_addr                                                 "0xB80031C8"
#define DC2_SYS_DC_BIST_FAIL_reg                                                      0xB80031C8
#define set_DC2_SYS_DC_BIST_FAIL_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_BIST_FAIL_reg)=data)
#define get_DC2_SYS_DC_BIST_FAIL_reg   (*((volatile unsigned int*) DC2_SYS_DC_BIST_FAIL_reg))
#define DC2_SYS_DC_BIST_FAIL_inst_adr                                                 "0x0072"
#define DC2_SYS_DC_BIST_FAIL_inst                                                     0x0072
#define DC2_SYS_DC_BIST_FAIL_DC_BIST_FAIL_GROUP_PICT0_shift                           (1)
#define DC2_SYS_DC_BIST_FAIL_DC_BIST_FAIL_GROUP_PICT0_mask                            (0x00000002)
#define DC2_SYS_DC_BIST_FAIL_DC_BIST_FAIL_GROUP_PICT0(data)                           (0x00000002&((data)<<1))
#define DC2_SYS_DC_BIST_FAIL_DC_BIST_FAIL_GROUP_PICT0_src(data)                       ((0x00000002&(data))>>1)
#define DC2_SYS_DC_BIST_FAIL_get_DC_BIST_FAIL_GROUP_PICT0(data)                       ((0x00000002&(data))>>1)


#define DC2_SYS_DC_BIST_DRF                                                           0x180031CC
#define DC2_SYS_DC_BIST_DRF_reg_addr                                                  "0xB80031CC"
#define DC2_SYS_DC_BIST_DRF_reg                                                       0xB80031CC
#define set_DC2_SYS_DC_BIST_DRF_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_BIST_DRF_reg)=data)
#define get_DC2_SYS_DC_BIST_DRF_reg   (*((volatile unsigned int*) DC2_SYS_DC_BIST_DRF_reg))
#define DC2_SYS_DC_BIST_DRF_inst_adr                                                  "0x0073"
#define DC2_SYS_DC_BIST_DRF_inst                                                      0x0073
#define DC2_SYS_DC_BIST_DRF_DC_DRF_MODE_PICT0_shift                                   (1)
#define DC2_SYS_DC_BIST_DRF_DC_DRF_MODE_PICT0_mask                                    (0x00000002)
#define DC2_SYS_DC_BIST_DRF_DC_DRF_MODE_PICT0(data)                                   (0x00000002&((data)<<1))
#define DC2_SYS_DC_BIST_DRF_DC_DRF_MODE_PICT0_src(data)                               ((0x00000002&(data))>>1)
#define DC2_SYS_DC_BIST_DRF_get_DC_DRF_MODE_PICT0(data)                               ((0x00000002&(data))>>1)


#define DC2_SYS_DC_BIST_RESUME                                                        0x180031D0
#define DC2_SYS_DC_BIST_RESUME_reg_addr                                               "0xB80031D0"
#define DC2_SYS_DC_BIST_RESUME_reg                                                    0xB80031D0
#define set_DC2_SYS_DC_BIST_RESUME_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_BIST_RESUME_reg)=data)
#define get_DC2_SYS_DC_BIST_RESUME_reg   (*((volatile unsigned int*) DC2_SYS_DC_BIST_RESUME_reg))
#define DC2_SYS_DC_BIST_RESUME_inst_adr                                               "0x0074"
#define DC2_SYS_DC_BIST_RESUME_inst                                                   0x0074
#define DC2_SYS_DC_BIST_RESUME_DC_DRF_RESUME_PICT0_shift                              (1)
#define DC2_SYS_DC_BIST_RESUME_DC_DRF_RESUME_PICT0_mask                               (0x00000002)
#define DC2_SYS_DC_BIST_RESUME_DC_DRF_RESUME_PICT0(data)                              (0x00000002&((data)<<1))
#define DC2_SYS_DC_BIST_RESUME_DC_DRF_RESUME_PICT0_src(data)                          ((0x00000002&(data))>>1)
#define DC2_SYS_DC_BIST_RESUME_get_DC_DRF_RESUME_PICT0(data)                          ((0x00000002&(data))>>1)


#define DC2_SYS_DC_BIST0_DRF_DONE                                                     0x180031D4
#define DC2_SYS_DC_BIST0_DRF_DONE_reg_addr                                            "0xB80031D4"
#define DC2_SYS_DC_BIST0_DRF_DONE_reg                                                 0xB80031D4
#define set_DC2_SYS_DC_BIST0_DRF_DONE_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_BIST0_DRF_DONE_reg)=data)
#define get_DC2_SYS_DC_BIST0_DRF_DONE_reg   (*((volatile unsigned int*) DC2_SYS_DC_BIST0_DRF_DONE_reg))
#define DC2_SYS_DC_BIST0_DRF_DONE_inst_adr                                            "0x0075"
#define DC2_SYS_DC_BIST0_DRF_DONE_inst                                                0x0075
#define DC2_SYS_DC_BIST0_DRF_DONE_DC_DRF_DONE_PICT0_shift                             (1)
#define DC2_SYS_DC_BIST0_DRF_DONE_DC_DRF_DONE_PICT0_mask                              (0x00000002)
#define DC2_SYS_DC_BIST0_DRF_DONE_DC_DRF_DONE_PICT0(data)                             (0x00000002&((data)<<1))
#define DC2_SYS_DC_BIST0_DRF_DONE_DC_DRF_DONE_PICT0_src(data)                         ((0x00000002&(data))>>1)
#define DC2_SYS_DC_BIST0_DRF_DONE_get_DC_DRF_DONE_PICT0(data)                         ((0x00000002&(data))>>1)


#define DC2_SYS_DC_BIST_DRF_PAUSE                                                     0x180031D8
#define DC2_SYS_DC_BIST_DRF_PAUSE_reg_addr                                            "0xB80031D8"
#define DC2_SYS_DC_BIST_DRF_PAUSE_reg                                                 0xB80031D8
#define set_DC2_SYS_DC_BIST_DRF_PAUSE_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_BIST_DRF_PAUSE_reg)=data)
#define get_DC2_SYS_DC_BIST_DRF_PAUSE_reg   (*((volatile unsigned int*) DC2_SYS_DC_BIST_DRF_PAUSE_reg))
#define DC2_SYS_DC_BIST_DRF_PAUSE_inst_adr                                            "0x0076"
#define DC2_SYS_DC_BIST_DRF_PAUSE_inst                                                0x0076
#define DC2_SYS_DC_BIST_DRF_PAUSE_DC_DRF_PAUSE_PICT0_shift                            (1)
#define DC2_SYS_DC_BIST_DRF_PAUSE_DC_DRF_PAUSE_PICT0_mask                             (0x00000002)
#define DC2_SYS_DC_BIST_DRF_PAUSE_DC_DRF_PAUSE_PICT0(data)                            (0x00000002&((data)<<1))
#define DC2_SYS_DC_BIST_DRF_PAUSE_DC_DRF_PAUSE_PICT0_src(data)                        ((0x00000002&(data))>>1)
#define DC2_SYS_DC_BIST_DRF_PAUSE_get_DC_DRF_PAUSE_PICT0(data)                        ((0x00000002&(data))>>1)


#define DC2_SYS_DC_BIST_DRF_FAIL                                                      0x180031DC
#define DC2_SYS_DC_BIST_DRF_FAIL_reg_addr                                             "0xB80031DC"
#define DC2_SYS_DC_BIST_DRF_FAIL_reg                                                  0xB80031DC
#define set_DC2_SYS_DC_BIST_DRF_FAIL_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_BIST_DRF_FAIL_reg)=data)
#define get_DC2_SYS_DC_BIST_DRF_FAIL_reg   (*((volatile unsigned int*) DC2_SYS_DC_BIST_DRF_FAIL_reg))
#define DC2_SYS_DC_BIST_DRF_FAIL_inst_adr                                             "0x0077"
#define DC2_SYS_DC_BIST_DRF_FAIL_inst                                                 0x0077
#define DC2_SYS_DC_BIST_DRF_FAIL_DC_DRF_FAIL_GROUP_PICT0_shift                        (1)
#define DC2_SYS_DC_BIST_DRF_FAIL_DC_DRF_FAIL_GROUP_PICT0_mask                         (0x00000002)
#define DC2_SYS_DC_BIST_DRF_FAIL_DC_DRF_FAIL_GROUP_PICT0(data)                        (0x00000002&((data)<<1))
#define DC2_SYS_DC_BIST_DRF_FAIL_DC_DRF_FAIL_GROUP_PICT0_src(data)                    ((0x00000002&(data))>>1)
#define DC2_SYS_DC_BIST_DRF_FAIL_get_DC_DRF_FAIL_GROUP_PICT0(data)                    ((0x00000002&(data))>>1)


#define DC2_SYS_DC_BIST_DETAIL                                                        0x180031E0
#define DC2_SYS_DC_BIST_DETAIL_reg_addr                                               "0xB80031E0"
#define DC2_SYS_DC_BIST_DETAIL_reg                                                    0xB80031E0
#define set_DC2_SYS_DC_BIST_DETAIL_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_BIST_DETAIL_reg)=data)
#define get_DC2_SYS_DC_BIST_DETAIL_reg   (*((volatile unsigned int*) DC2_SYS_DC_BIST_DETAIL_reg))
#define DC2_SYS_DC_BIST_DETAIL_inst_adr                                               "0x0078"
#define DC2_SYS_DC_BIST_DETAIL_inst                                                   0x0078
#define DC2_SYS_DC_BIST_DETAIL_DC_DRF_PICT_FAIL0_shift                                (5)
#define DC2_SYS_DC_BIST_DETAIL_DC_DRF_PICT_FAIL0_mask                                 (0x00000020)
#define DC2_SYS_DC_BIST_DETAIL_DC_DRF_PICT_FAIL0(data)                                (0x00000020&((data)<<5))
#define DC2_SYS_DC_BIST_DETAIL_DC_DRF_PICT_FAIL0_src(data)                            ((0x00000020&(data))>>5)
#define DC2_SYS_DC_BIST_DETAIL_get_DC_DRF_PICT_FAIL0(data)                            ((0x00000020&(data))>>5)
#define DC2_SYS_DC_BIST_DETAIL_DC_BIST_PICT_FAIL0_shift                               (4)
#define DC2_SYS_DC_BIST_DETAIL_DC_BIST_PICT_FAIL0_mask                                (0x00000010)
#define DC2_SYS_DC_BIST_DETAIL_DC_BIST_PICT_FAIL0(data)                               (0x00000010&((data)<<4))
#define DC2_SYS_DC_BIST_DETAIL_DC_BIST_PICT_FAIL0_src(data)                           ((0x00000010&(data))>>4)
#define DC2_SYS_DC_BIST_DETAIL_get_DC_BIST_PICT_FAIL0(data)                           ((0x00000010&(data))>>4)


#define DC2_SYS_DC_BIST_RM                                                            0x180031E4
#define DC2_SYS_DC_BIST_RM_reg_addr                                                   "0xB80031E4"
#define DC2_SYS_DC_BIST_RM_reg                                                        0xB80031E4
#define set_DC2_SYS_DC_BIST_RM_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_BIST_RM_reg)=data)
#define get_DC2_SYS_DC_BIST_RM_reg   (*((volatile unsigned int*) DC2_SYS_DC_BIST_RM_reg))
#define DC2_SYS_DC_BIST_RM_inst_adr                                                   "0x0079"
#define DC2_SYS_DC_BIST_RM_inst                                                       0x0079
#define DC2_SYS_DC_BIST_RM_RME_shift                                                  (4)
#define DC2_SYS_DC_BIST_RM_RME_mask                                                   (0x00000010)
#define DC2_SYS_DC_BIST_RM_RME(data)                                                  (0x00000010&((data)<<4))
#define DC2_SYS_DC_BIST_RM_RME_src(data)                                              ((0x00000010&(data))>>4)
#define DC2_SYS_DC_BIST_RM_get_RME(data)                                              ((0x00000010&(data))>>4)
#define DC2_SYS_DC_BIST_RM_RM_3_shift                                                 (3)
#define DC2_SYS_DC_BIST_RM_RM_3_mask                                                  (0x00000008)
#define DC2_SYS_DC_BIST_RM_RM_3(data)                                                 (0x00000008&((data)<<3))
#define DC2_SYS_DC_BIST_RM_RM_3_src(data)                                             ((0x00000008&(data))>>3)
#define DC2_SYS_DC_BIST_RM_get_RM_3(data)                                             ((0x00000008&(data))>>3)
#define DC2_SYS_DC_BIST_RM_RM_2_shift                                                 (2)
#define DC2_SYS_DC_BIST_RM_RM_2_mask                                                  (0x00000004)
#define DC2_SYS_DC_BIST_RM_RM_2(data)                                                 (0x00000004&((data)<<2))
#define DC2_SYS_DC_BIST_RM_RM_2_src(data)                                             ((0x00000004&(data))>>2)
#define DC2_SYS_DC_BIST_RM_get_RM_2(data)                                             ((0x00000004&(data))>>2)
#define DC2_SYS_DC_BIST_RM_RM_1_shift                                                 (1)
#define DC2_SYS_DC_BIST_RM_RM_1_mask                                                  (0x00000002)
#define DC2_SYS_DC_BIST_RM_RM_1(data)                                                 (0x00000002&((data)<<1))
#define DC2_SYS_DC_BIST_RM_RM_1_src(data)                                             ((0x00000002&(data))>>1)
#define DC2_SYS_DC_BIST_RM_get_RM_1(data)                                             ((0x00000002&(data))>>1)
#define DC2_SYS_DC_BIST_RM_RM_0_shift                                                 (0)
#define DC2_SYS_DC_BIST_RM_RM_0_mask                                                  (0x00000001)
#define DC2_SYS_DC_BIST_RM_RM_0(data)                                                 (0x00000001&((data)<<0))
#define DC2_SYS_DC_BIST_RM_RM_0_src(data)                                             ((0x00000001&(data))>>0)
#define DC2_SYS_DC_BIST_RM_get_RM_0(data)                                             ((0x00000001&(data))>>0)


#define DC2_SYS_DC_DUMMY_REG0                                                         0x180031F0
#define DC2_SYS_DC_DUMMY_REG0_reg_addr                                                "0xB80031F0"
#define DC2_SYS_DC_DUMMY_REG0_reg                                                     0xB80031F0
#define set_DC2_SYS_DC_DUMMY_REG0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_DUMMY_REG0_reg)=data)
#define get_DC2_SYS_DC_DUMMY_REG0_reg   (*((volatile unsigned int*) DC2_SYS_DC_DUMMY_REG0_reg))
#define DC2_SYS_DC_DUMMY_REG0_inst_adr                                                "0x007C"
#define DC2_SYS_DC_DUMMY_REG0_inst                                                    0x007C
#define DC2_SYS_DC_DUMMY_REG0_dummy_reg0_shift                                        (0)
#define DC2_SYS_DC_DUMMY_REG0_dummy_reg0_mask                                         (0xFFFFFFFF)
#define DC2_SYS_DC_DUMMY_REG0_dummy_reg0(data)                                        (0xFFFFFFFF&((data)<<0))
#define DC2_SYS_DC_DUMMY_REG0_dummy_reg0_src(data)                                    ((0xFFFFFFFF&(data))>>0)
#define DC2_SYS_DC_DUMMY_REG0_get_dummy_reg0(data)                                    ((0xFFFFFFFF&(data))>>0)


#define DC2_SYS_DC_DUMMY_REG1                                                         0x180031F4
#define DC2_SYS_DC_DUMMY_REG1_reg_addr                                                "0xB80031F4"
#define DC2_SYS_DC_DUMMY_REG1_reg                                                     0xB80031F4
#define set_DC2_SYS_DC_DUMMY_REG1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_DUMMY_REG1_reg)=data)
#define get_DC2_SYS_DC_DUMMY_REG1_reg   (*((volatile unsigned int*) DC2_SYS_DC_DUMMY_REG1_reg))
#define DC2_SYS_DC_DUMMY_REG1_inst_adr                                                "0x007D"
#define DC2_SYS_DC_DUMMY_REG1_inst                                                    0x007D
#define DC2_SYS_DC_DUMMY_REG1_dummy_reg1_shift                                        (0)
#define DC2_SYS_DC_DUMMY_REG1_dummy_reg1_mask                                         (0xFFFFFFFF)
#define DC2_SYS_DC_DUMMY_REG1_dummy_reg1(data)                                        (0xFFFFFFFF&((data)<<0))
#define DC2_SYS_DC_DUMMY_REG1_dummy_reg1_src(data)                                    ((0xFFFFFFFF&(data))>>0)
#define DC2_SYS_DC_DUMMY_REG1_get_dummy_reg1(data)                                    ((0xFFFFFFFF&(data))>>0)


#define DC2_SYS_DC_DUMMY_REG2                                                         0x180031F8
#define DC2_SYS_DC_DUMMY_REG2_reg_addr                                                "0xB80031F8"
#define DC2_SYS_DC_DUMMY_REG2_reg                                                     0xB80031F8
#define set_DC2_SYS_DC_DUMMY_REG2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_DUMMY_REG2_reg)=data)
#define get_DC2_SYS_DC_DUMMY_REG2_reg   (*((volatile unsigned int*) DC2_SYS_DC_DUMMY_REG2_reg))
#define DC2_SYS_DC_DUMMY_REG2_inst_adr                                                "0x007E"
#define DC2_SYS_DC_DUMMY_REG2_inst                                                    0x007E
#define DC2_SYS_DC_DUMMY_REG2_dummy_reg2_shift                                        (0)
#define DC2_SYS_DC_DUMMY_REG2_dummy_reg2_mask                                         (0xFFFFFFFF)
#define DC2_SYS_DC_DUMMY_REG2_dummy_reg2(data)                                        (0xFFFFFFFF&((data)<<0))
#define DC2_SYS_DC_DUMMY_REG2_dummy_reg2_src(data)                                    ((0xFFFFFFFF&(data))>>0)
#define DC2_SYS_DC_DUMMY_REG2_get_dummy_reg2(data)                                    ((0xFFFFFFFF&(data))>>0)


#define DC2_SYS_DC_DUMMY_REG3                                                         0x180031FC
#define DC2_SYS_DC_DUMMY_REG3_reg_addr                                                "0xB80031FC"
#define DC2_SYS_DC_DUMMY_REG3_reg                                                     0xB80031FC
#define set_DC2_SYS_DC_DUMMY_REG3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_DUMMY_REG3_reg)=data)
#define get_DC2_SYS_DC_DUMMY_REG3_reg   (*((volatile unsigned int*) DC2_SYS_DC_DUMMY_REG3_reg))
#define DC2_SYS_DC_DUMMY_REG3_inst_adr                                                "0x007F"
#define DC2_SYS_DC_DUMMY_REG3_inst                                                    0x007F
#define DC2_SYS_DC_DUMMY_REG3_dummy_reg3_shift                                        (0)
#define DC2_SYS_DC_DUMMY_REG3_dummy_reg3_mask                                         (0xFFFFFFFF)
#define DC2_SYS_DC_DUMMY_REG3_dummy_reg3(data)                                        (0xFFFFFFFF&((data)<<0))
#define DC2_SYS_DC_DUMMY_REG3_dummy_reg3_src(data)                                    ((0xFFFFFFFF&(data))>>0)
#define DC2_SYS_DC_DUMMY_REG3_get_dummy_reg3(data)                                    ((0xFFFFFFFF&(data))>>0)


#define DC2_SYS_DC_MT_TYPE_0                                                          0x18003200
#define DC2_SYS_DC_MT_TYPE_1                                                          0x18003204
#define DC2_SYS_DC_MT_TYPE_2                                                          0x18003208
#define DC2_SYS_DC_MT_TYPE_3                                                          0x1800320C
#define DC2_SYS_DC_MT_TYPE_0_reg_addr                                                 "0xB8003200"
#define DC2_SYS_DC_MT_TYPE_1_reg_addr                                                 "0xB8003204"
#define DC2_SYS_DC_MT_TYPE_2_reg_addr                                                 "0xB8003208"
#define DC2_SYS_DC_MT_TYPE_3_reg_addr                                                 "0xB800320C"
#define DC2_SYS_DC_MT_TYPE_0_reg                                                      0xB8003200
#define DC2_SYS_DC_MT_TYPE_1_reg                                                      0xB8003204
#define DC2_SYS_DC_MT_TYPE_2_reg                                                      0xB8003208
#define DC2_SYS_DC_MT_TYPE_3_reg                                                      0xB800320C
#define set_DC2_SYS_DC_MT_TYPE_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_TYPE_0_reg)=data)
#define set_DC2_SYS_DC_MT_TYPE_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_TYPE_1_reg)=data)
#define set_DC2_SYS_DC_MT_TYPE_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_TYPE_2_reg)=data)
#define set_DC2_SYS_DC_MT_TYPE_3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_TYPE_3_reg)=data)
#define get_DC2_SYS_DC_MT_TYPE_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_TYPE_0_reg))
#define get_DC2_SYS_DC_MT_TYPE_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_TYPE_1_reg))
#define get_DC2_SYS_DC_MT_TYPE_2_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_TYPE_2_reg))
#define get_DC2_SYS_DC_MT_TYPE_3_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_TYPE_3_reg))
#define DC2_SYS_DC_MT_TYPE_0_inst_adr                                                 "0x0080"
#define DC2_SYS_DC_MT_TYPE_1_inst_adr                                                 "0x0081"
#define DC2_SYS_DC_MT_TYPE_2_inst_adr                                                 "0x0082"
#define DC2_SYS_DC_MT_TYPE_3_inst_adr                                                 "0x0083"
#define DC2_SYS_DC_MT_TYPE_0_inst                                                     0x0080
#define DC2_SYS_DC_MT_TYPE_1_inst                                                     0x0081
#define DC2_SYS_DC_MT_TYPE_2_inst                                                     0x0082
#define DC2_SYS_DC_MT_TYPE_3_inst                                                     0x0083
#define DC2_SYS_DC_MT_TYPE_mem_type_shift                                             (30)
#define DC2_SYS_DC_MT_TYPE_mem_type_mask                                              (0xC0000000)
#define DC2_SYS_DC_MT_TYPE_mem_type(data)                                             (0xC0000000&((data)<<30))
#define DC2_SYS_DC_MT_TYPE_mem_type_src(data)                                         ((0xC0000000&(data))>>30)
#define DC2_SYS_DC_MT_TYPE_get_mem_type(data)                                         ((0xC0000000&(data))>>30)


#define DC2_SYS_DC_MT_SADDR_0                                                         0x18003210
#define DC2_SYS_DC_MT_SADDR_1                                                         0x18003214
#define DC2_SYS_DC_MT_SADDR_2                                                         0x18003218
#define DC2_SYS_DC_MT_SADDR_3                                                         0x1800321C
#define DC2_SYS_DC_MT_SADDR_0_reg_addr                                                "0xB8003210"
#define DC2_SYS_DC_MT_SADDR_1_reg_addr                                                "0xB8003214"
#define DC2_SYS_DC_MT_SADDR_2_reg_addr                                                "0xB8003218"
#define DC2_SYS_DC_MT_SADDR_3_reg_addr                                                "0xB800321C"
#define DC2_SYS_DC_MT_SADDR_0_reg                                                     0xB8003210
#define DC2_SYS_DC_MT_SADDR_1_reg                                                     0xB8003214
#define DC2_SYS_DC_MT_SADDR_2_reg                                                     0xB8003218
#define DC2_SYS_DC_MT_SADDR_3_reg                                                     0xB800321C
#define set_DC2_SYS_DC_MT_SADDR_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_SADDR_0_reg)=data)
#define set_DC2_SYS_DC_MT_SADDR_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_SADDR_1_reg)=data)
#define set_DC2_SYS_DC_MT_SADDR_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_SADDR_2_reg)=data)
#define set_DC2_SYS_DC_MT_SADDR_3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_SADDR_3_reg)=data)
#define get_DC2_SYS_DC_MT_SADDR_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_SADDR_0_reg))
#define get_DC2_SYS_DC_MT_SADDR_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_SADDR_1_reg))
#define get_DC2_SYS_DC_MT_SADDR_2_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_SADDR_2_reg))
#define get_DC2_SYS_DC_MT_SADDR_3_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_SADDR_3_reg))
#define DC2_SYS_DC_MT_SADDR_0_inst_adr                                                "0x0084"
#define DC2_SYS_DC_MT_SADDR_1_inst_adr                                                "0x0085"
#define DC2_SYS_DC_MT_SADDR_2_inst_adr                                                "0x0086"
#define DC2_SYS_DC_MT_SADDR_3_inst_adr                                                "0x0087"
#define DC2_SYS_DC_MT_SADDR_0_inst                                                    0x0084
#define DC2_SYS_DC_MT_SADDR_1_inst                                                    0x0085
#define DC2_SYS_DC_MT_SADDR_2_inst                                                    0x0086
#define DC2_SYS_DC_MT_SADDR_3_inst                                                    0x0087
#define DC2_SYS_DC_MT_SADDR_saddr_shift                                               (5)
#define DC2_SYS_DC_MT_SADDR_saddr_mask                                                (0x7FFFFFE0)
#define DC2_SYS_DC_MT_SADDR_saddr(data)                                               (0x7FFFFFE0&((data)<<5))
#define DC2_SYS_DC_MT_SADDR_saddr_src(data)                                           ((0x7FFFFFE0&(data))>>5)
#define DC2_SYS_DC_MT_SADDR_get_saddr(data)                                           ((0x7FFFFFE0&(data))>>5)


#define DC2_SYS_DC_MT_EADDR_0                                                         0x18003220
#define DC2_SYS_DC_MT_EADDR_1                                                         0x18003224
#define DC2_SYS_DC_MT_EADDR_2                                                         0x18003228
#define DC2_SYS_DC_MT_EADDR_3                                                         0x1800322C
#define DC2_SYS_DC_MT_EADDR_0_reg_addr                                                "0xB8003220"
#define DC2_SYS_DC_MT_EADDR_1_reg_addr                                                "0xB8003224"
#define DC2_SYS_DC_MT_EADDR_2_reg_addr                                                "0xB8003228"
#define DC2_SYS_DC_MT_EADDR_3_reg_addr                                                "0xB800322C"
#define DC2_SYS_DC_MT_EADDR_0_reg                                                     0xB8003220
#define DC2_SYS_DC_MT_EADDR_1_reg                                                     0xB8003224
#define DC2_SYS_DC_MT_EADDR_2_reg                                                     0xB8003228
#define DC2_SYS_DC_MT_EADDR_3_reg                                                     0xB800322C
#define set_DC2_SYS_DC_MT_EADDR_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_EADDR_0_reg)=data)
#define set_DC2_SYS_DC_MT_EADDR_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_EADDR_1_reg)=data)
#define set_DC2_SYS_DC_MT_EADDR_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_EADDR_2_reg)=data)
#define set_DC2_SYS_DC_MT_EADDR_3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_EADDR_3_reg)=data)
#define get_DC2_SYS_DC_MT_EADDR_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_EADDR_0_reg))
#define get_DC2_SYS_DC_MT_EADDR_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_EADDR_1_reg))
#define get_DC2_SYS_DC_MT_EADDR_2_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_EADDR_2_reg))
#define get_DC2_SYS_DC_MT_EADDR_3_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_EADDR_3_reg))
#define DC2_SYS_DC_MT_EADDR_0_inst_adr                                                "0x0088"
#define DC2_SYS_DC_MT_EADDR_1_inst_adr                                                "0x0089"
#define DC2_SYS_DC_MT_EADDR_2_inst_adr                                                "0x008A"
#define DC2_SYS_DC_MT_EADDR_3_inst_adr                                                "0x008B"
#define DC2_SYS_DC_MT_EADDR_0_inst                                                    0x0088
#define DC2_SYS_DC_MT_EADDR_1_inst                                                    0x0089
#define DC2_SYS_DC_MT_EADDR_2_inst                                                    0x008A
#define DC2_SYS_DC_MT_EADDR_3_inst                                                    0x008B
#define DC2_SYS_DC_MT_EADDR_eaddr_shift                                               (5)
#define DC2_SYS_DC_MT_EADDR_eaddr_mask                                                (0x7FFFFFE0)
#define DC2_SYS_DC_MT_EADDR_eaddr(data)                                               (0x7FFFFFE0&((data)<<5))
#define DC2_SYS_DC_MT_EADDR_eaddr_src(data)                                           ((0x7FFFFFE0&(data))>>5)
#define DC2_SYS_DC_MT_EADDR_get_eaddr(data)                                           ((0x7FFFFFE0&(data))>>5)


#define DC2_SYS_DC_MT_MODE_0                                                          0x18003240
#define DC2_SYS_DC_MT_MODE_1                                                          0x18003244
#define DC2_SYS_DC_MT_MODE_2                                                          0x18003248
#define DC2_SYS_DC_MT_MODE_3                                                          0x1800324C
#define DC2_SYS_DC_MT_MODE_0_reg_addr                                                 "0xB8003240"
#define DC2_SYS_DC_MT_MODE_1_reg_addr                                                 "0xB8003244"
#define DC2_SYS_DC_MT_MODE_2_reg_addr                                                 "0xB8003248"
#define DC2_SYS_DC_MT_MODE_3_reg_addr                                                 "0xB800324C"
#define DC2_SYS_DC_MT_MODE_0_reg                                                      0xB8003240
#define DC2_SYS_DC_MT_MODE_1_reg                                                      0xB8003244
#define DC2_SYS_DC_MT_MODE_2_reg                                                      0xB8003248
#define DC2_SYS_DC_MT_MODE_3_reg                                                      0xB800324C
#define set_DC2_SYS_DC_MT_MODE_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_MODE_0_reg)=data)
#define set_DC2_SYS_DC_MT_MODE_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_MODE_1_reg)=data)
#define set_DC2_SYS_DC_MT_MODE_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_MODE_2_reg)=data)
#define set_DC2_SYS_DC_MT_MODE_3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_MODE_3_reg)=data)
#define get_DC2_SYS_DC_MT_MODE_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_MODE_0_reg))
#define get_DC2_SYS_DC_MT_MODE_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_MODE_1_reg))
#define get_DC2_SYS_DC_MT_MODE_2_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_MODE_2_reg))
#define get_DC2_SYS_DC_MT_MODE_3_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_MODE_3_reg))
#define DC2_SYS_DC_MT_MODE_0_inst_adr                                                 "0x0090"
#define DC2_SYS_DC_MT_MODE_1_inst_adr                                                 "0x0091"
#define DC2_SYS_DC_MT_MODE_2_inst_adr                                                 "0x0092"
#define DC2_SYS_DC_MT_MODE_3_inst_adr                                                 "0x0093"
#define DC2_SYS_DC_MT_MODE_0_inst                                                     0x0090
#define DC2_SYS_DC_MT_MODE_1_inst                                                     0x0091
#define DC2_SYS_DC_MT_MODE_2_inst                                                     0x0092
#define DC2_SYS_DC_MT_MODE_3_inst                                                     0x0093
#define DC2_SYS_DC_MT_MODE_write_enable5_shift                                        (2)
#define DC2_SYS_DC_MT_MODE_write_enable5_mask                                         (0x00000004)
#define DC2_SYS_DC_MT_MODE_write_enable5(data)                                        (0x00000004&((data)<<2))
#define DC2_SYS_DC_MT_MODE_write_enable5_src(data)                                    ((0x00000004&(data))>>2)
#define DC2_SYS_DC_MT_MODE_get_write_enable5(data)                                    ((0x00000004&(data))>>2)
#define DC2_SYS_DC_MT_MODE_mode_shift                                                 (0)
#define DC2_SYS_DC_MT_MODE_mode_mask                                                  (0x00000003)
#define DC2_SYS_DC_MT_MODE_mode(data)                                                 (0x00000003&((data)<<0))
#define DC2_SYS_DC_MT_MODE_mode_src(data)                                             ((0x00000003&(data))>>0)
#define DC2_SYS_DC_MT_MODE_get_mode(data)                                             ((0x00000003&(data))>>0)


#define DC2_SYS_DC_MT_TABLE_0                                                         0x18003260
#define DC2_SYS_DC_MT_TABLE_1                                                         0x18003264
#define DC2_SYS_DC_MT_TABLE_2                                                         0x18003268
#define DC2_SYS_DC_MT_TABLE_3                                                         0x1800326C
#define DC2_SYS_DC_MT_TABLE_0_reg_addr                                                "0xB8003260"
#define DC2_SYS_DC_MT_TABLE_1_reg_addr                                                "0xB8003264"
#define DC2_SYS_DC_MT_TABLE_2_reg_addr                                                "0xB8003268"
#define DC2_SYS_DC_MT_TABLE_3_reg_addr                                                "0xB800326C"
#define DC2_SYS_DC_MT_TABLE_0_reg                                                     0xB8003260
#define DC2_SYS_DC_MT_TABLE_1_reg                                                     0xB8003264
#define DC2_SYS_DC_MT_TABLE_2_reg                                                     0xB8003268
#define DC2_SYS_DC_MT_TABLE_3_reg                                                     0xB800326C
#define set_DC2_SYS_DC_MT_TABLE_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_TABLE_0_reg)=data)
#define set_DC2_SYS_DC_MT_TABLE_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_TABLE_1_reg)=data)
#define set_DC2_SYS_DC_MT_TABLE_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_TABLE_2_reg)=data)
#define set_DC2_SYS_DC_MT_TABLE_3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_TABLE_3_reg)=data)
#define get_DC2_SYS_DC_MT_TABLE_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_TABLE_0_reg))
#define get_DC2_SYS_DC_MT_TABLE_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_TABLE_1_reg))
#define get_DC2_SYS_DC_MT_TABLE_2_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_TABLE_2_reg))
#define get_DC2_SYS_DC_MT_TABLE_3_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_TABLE_3_reg))
#define DC2_SYS_DC_MT_TABLE_0_inst_adr                                                "0x0098"
#define DC2_SYS_DC_MT_TABLE_1_inst_adr                                                "0x0099"
#define DC2_SYS_DC_MT_TABLE_2_inst_adr                                                "0x009A"
#define DC2_SYS_DC_MT_TABLE_3_inst_adr                                                "0x009B"
#define DC2_SYS_DC_MT_TABLE_0_inst                                                    0x0098
#define DC2_SYS_DC_MT_TABLE_1_inst                                                    0x0099
#define DC2_SYS_DC_MT_TABLE_2_inst                                                    0x009A
#define DC2_SYS_DC_MT_TABLE_3_inst                                                    0x009B
#define DC2_SYS_DC_MT_TABLE_module_ID_0_shift                                         (24)
#define DC2_SYS_DC_MT_TABLE_module_ID_0_mask                                          (0x7F000000)
#define DC2_SYS_DC_MT_TABLE_module_ID_0(data)                                         (0x7F000000&((data)<<24))
#define DC2_SYS_DC_MT_TABLE_module_ID_0_src(data)                                     ((0x7F000000&(data))>>24)
#define DC2_SYS_DC_MT_TABLE_get_module_ID_0(data)                                     ((0x7F000000&(data))>>24)
#define DC2_SYS_DC_MT_TABLE_module_ID_1_shift                                         (16)
#define DC2_SYS_DC_MT_TABLE_module_ID_1_mask                                          (0x007F0000)
#define DC2_SYS_DC_MT_TABLE_module_ID_1(data)                                         (0x007F0000&((data)<<16))
#define DC2_SYS_DC_MT_TABLE_module_ID_1_src(data)                                     ((0x007F0000&(data))>>16)
#define DC2_SYS_DC_MT_TABLE_get_module_ID_1(data)                                     ((0x007F0000&(data))>>16)
#define DC2_SYS_DC_MT_TABLE_module_ID_2_shift                                         (8)
#define DC2_SYS_DC_MT_TABLE_module_ID_2_mask                                          (0x00007F00)
#define DC2_SYS_DC_MT_TABLE_module_ID_2(data)                                         (0x00007F00&((data)<<8))
#define DC2_SYS_DC_MT_TABLE_module_ID_2_src(data)                                     ((0x00007F00&(data))>>8)
#define DC2_SYS_DC_MT_TABLE_get_module_ID_2(data)                                     ((0x00007F00&(data))>>8)
#define DC2_SYS_DC_MT_TABLE_module_ID_3_shift                                         (0)
#define DC2_SYS_DC_MT_TABLE_module_ID_3_mask                                          (0x0000007F)
#define DC2_SYS_DC_MT_TABLE_module_ID_3(data)                                         (0x0000007F&((data)<<0))
#define DC2_SYS_DC_MT_TABLE_module_ID_3_src(data)                                     ((0x0000007F&(data))>>0)
#define DC2_SYS_DC_MT_TABLE_get_module_ID_3(data)                                     ((0x0000007F&(data))>>0)


#define DC2_SYS_DC_MT_ADDCMD_HI_0                                                     0x18003280
#define DC2_SYS_DC_MT_ADDCMD_HI_1                                                     0x18003284
#define DC2_SYS_DC_MT_ADDCMD_HI_2                                                     0x18003288
#define DC2_SYS_DC_MT_ADDCMD_HI_3                                                     0x1800328C
#define DC2_SYS_DC_MT_ADDCMD_HI_0_reg_addr                                            "0xB8003280"
#define DC2_SYS_DC_MT_ADDCMD_HI_1_reg_addr                                            "0xB8003284"
#define DC2_SYS_DC_MT_ADDCMD_HI_2_reg_addr                                            "0xB8003288"
#define DC2_SYS_DC_MT_ADDCMD_HI_3_reg_addr                                            "0xB800328C"
#define DC2_SYS_DC_MT_ADDCMD_HI_0_reg                                                 0xB8003280
#define DC2_SYS_DC_MT_ADDCMD_HI_1_reg                                                 0xB8003284
#define DC2_SYS_DC_MT_ADDCMD_HI_2_reg                                                 0xB8003288
#define DC2_SYS_DC_MT_ADDCMD_HI_3_reg                                                 0xB800328C
#define set_DC2_SYS_DC_MT_ADDCMD_HI_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_HI_0_reg)=data)
#define set_DC2_SYS_DC_MT_ADDCMD_HI_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_HI_1_reg)=data)
#define set_DC2_SYS_DC_MT_ADDCMD_HI_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_HI_2_reg)=data)
#define set_DC2_SYS_DC_MT_ADDCMD_HI_3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_HI_3_reg)=data)
#define get_DC2_SYS_DC_MT_ADDCMD_HI_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_HI_0_reg))
#define get_DC2_SYS_DC_MT_ADDCMD_HI_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_HI_1_reg))
#define get_DC2_SYS_DC_MT_ADDCMD_HI_2_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_HI_2_reg))
#define get_DC2_SYS_DC_MT_ADDCMD_HI_3_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_HI_3_reg))
#define DC2_SYS_DC_MT_ADDCMD_HI_0_inst_adr                                            "0x00A0"
#define DC2_SYS_DC_MT_ADDCMD_HI_1_inst_adr                                            "0x00A1"
#define DC2_SYS_DC_MT_ADDCMD_HI_2_inst_adr                                            "0x00A2"
#define DC2_SYS_DC_MT_ADDCMD_HI_3_inst_adr                                            "0x00A3"
#define DC2_SYS_DC_MT_ADDCMD_HI_0_inst                                                0x00A0
#define DC2_SYS_DC_MT_ADDCMD_HI_1_inst                                                0x00A1
#define DC2_SYS_DC_MT_ADDCMD_HI_2_inst                                                0x00A2
#define DC2_SYS_DC_MT_ADDCMD_HI_3_inst                                                0x00A3
#define DC2_SYS_DC_MT_ADDCMD_HI_access_type_0_shift                                   (30)
#define DC2_SYS_DC_MT_ADDCMD_HI_access_type_0_mask                                    (0xC0000000)
#define DC2_SYS_DC_MT_ADDCMD_HI_access_type_0(data)                                   (0xC0000000&((data)<<30))
#define DC2_SYS_DC_MT_ADDCMD_HI_access_type_0_src(data)                               ((0xC0000000&(data))>>30)
#define DC2_SYS_DC_MT_ADDCMD_HI_get_access_type_0(data)                               ((0xC0000000&(data))>>30)
#define DC2_SYS_DC_MT_ADDCMD_HI_access_type_1_shift                                   (28)
#define DC2_SYS_DC_MT_ADDCMD_HI_access_type_1_mask                                    (0x30000000)
#define DC2_SYS_DC_MT_ADDCMD_HI_access_type_1(data)                                   (0x30000000&((data)<<28))
#define DC2_SYS_DC_MT_ADDCMD_HI_access_type_1_src(data)                               ((0x30000000&(data))>>28)
#define DC2_SYS_DC_MT_ADDCMD_HI_get_access_type_1(data)                               ((0x30000000&(data))>>28)
#define DC2_SYS_DC_MT_ADDCMD_HI_access_type_2_shift                                   (26)
#define DC2_SYS_DC_MT_ADDCMD_HI_access_type_2_mask                                    (0x0C000000)
#define DC2_SYS_DC_MT_ADDCMD_HI_access_type_2(data)                                   (0x0C000000&((data)<<26))
#define DC2_SYS_DC_MT_ADDCMD_HI_access_type_2_src(data)                               ((0x0C000000&(data))>>26)
#define DC2_SYS_DC_MT_ADDCMD_HI_get_access_type_2(data)                               ((0x0C000000&(data))>>26)
#define DC2_SYS_DC_MT_ADDCMD_HI_access_type_3_shift                                   (24)
#define DC2_SYS_DC_MT_ADDCMD_HI_access_type_3_mask                                    (0x03000000)
#define DC2_SYS_DC_MT_ADDCMD_HI_access_type_3(data)                                   (0x03000000&((data)<<24))
#define DC2_SYS_DC_MT_ADDCMD_HI_access_type_3_src(data)                               ((0x03000000&(data))>>24)
#define DC2_SYS_DC_MT_ADDCMD_HI_get_access_type_3(data)                               ((0x03000000&(data))>>24)
#define DC2_SYS_DC_MT_ADDCMD_HI_ever_trap_shift                                       (21)
#define DC2_SYS_DC_MT_ADDCMD_HI_ever_trap_mask                                        (0x00200000)
#define DC2_SYS_DC_MT_ADDCMD_HI_ever_trap(data)                                       (0x00200000&((data)<<21))
#define DC2_SYS_DC_MT_ADDCMD_HI_ever_trap_src(data)                                   ((0x00200000&(data))>>21)
#define DC2_SYS_DC_MT_ADDCMD_HI_get_ever_trap(data)                                   ((0x00200000&(data))>>21)
#define DC2_SYS_DC_MT_ADDCMD_HI_module_ID_shift                                       (14)
#define DC2_SYS_DC_MT_ADDCMD_HI_module_ID_mask                                        (0x001FC000)
#define DC2_SYS_DC_MT_ADDCMD_HI_module_ID(data)                                       (0x001FC000&((data)<<14))
#define DC2_SYS_DC_MT_ADDCMD_HI_module_ID_src(data)                                   ((0x001FC000&(data))>>14)
#define DC2_SYS_DC_MT_ADDCMD_HI_get_module_ID(data)                                   ((0x001FC000&(data))>>14)
#define DC2_SYS_DC_MT_ADDCMD_HI_addcmd_shift                                          (0)
#define DC2_SYS_DC_MT_ADDCMD_HI_addcmd_mask                                           (0x00003FFF)
#define DC2_SYS_DC_MT_ADDCMD_HI_addcmd(data)                                          (0x00003FFF&((data)<<0))
#define DC2_SYS_DC_MT_ADDCMD_HI_addcmd_src(data)                                      ((0x00003FFF&(data))>>0)
#define DC2_SYS_DC_MT_ADDCMD_HI_get_addcmd(data)                                      ((0x00003FFF&(data))>>0)


#define DC2_SYS_DC_MT_ADDCMD_LO_0                                                     0x180032A0
#define DC2_SYS_DC_MT_ADDCMD_LO_1                                                     0x180032A4
#define DC2_SYS_DC_MT_ADDCMD_LO_2                                                     0x180032A8
#define DC2_SYS_DC_MT_ADDCMD_LO_3                                                     0x180032AC
#define DC2_SYS_DC_MT_ADDCMD_LO_0_reg_addr                                            "0xB80032A0"
#define DC2_SYS_DC_MT_ADDCMD_LO_1_reg_addr                                            "0xB80032A4"
#define DC2_SYS_DC_MT_ADDCMD_LO_2_reg_addr                                            "0xB80032A8"
#define DC2_SYS_DC_MT_ADDCMD_LO_3_reg_addr                                            "0xB80032AC"
#define DC2_SYS_DC_MT_ADDCMD_LO_0_reg                                                 0xB80032A0
#define DC2_SYS_DC_MT_ADDCMD_LO_1_reg                                                 0xB80032A4
#define DC2_SYS_DC_MT_ADDCMD_LO_2_reg                                                 0xB80032A8
#define DC2_SYS_DC_MT_ADDCMD_LO_3_reg                                                 0xB80032AC
#define set_DC2_SYS_DC_MT_ADDCMD_LO_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_LO_0_reg)=data)
#define set_DC2_SYS_DC_MT_ADDCMD_LO_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_LO_1_reg)=data)
#define set_DC2_SYS_DC_MT_ADDCMD_LO_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_LO_2_reg)=data)
#define set_DC2_SYS_DC_MT_ADDCMD_LO_3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_LO_3_reg)=data)
#define get_DC2_SYS_DC_MT_ADDCMD_LO_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_LO_0_reg))
#define get_DC2_SYS_DC_MT_ADDCMD_LO_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_LO_1_reg))
#define get_DC2_SYS_DC_MT_ADDCMD_LO_2_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_LO_2_reg))
#define get_DC2_SYS_DC_MT_ADDCMD_LO_3_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_LO_3_reg))
#define DC2_SYS_DC_MT_ADDCMD_LO_0_inst_adr                                            "0x00A8"
#define DC2_SYS_DC_MT_ADDCMD_LO_1_inst_adr                                            "0x00A9"
#define DC2_SYS_DC_MT_ADDCMD_LO_2_inst_adr                                            "0x00AA"
#define DC2_SYS_DC_MT_ADDCMD_LO_3_inst_adr                                            "0x00AB"
#define DC2_SYS_DC_MT_ADDCMD_LO_0_inst                                                0x00A8
#define DC2_SYS_DC_MT_ADDCMD_LO_1_inst                                                0x00A9
#define DC2_SYS_DC_MT_ADDCMD_LO_2_inst                                                0x00AA
#define DC2_SYS_DC_MT_ADDCMD_LO_3_inst                                                0x00AB
#define DC2_SYS_DC_MT_ADDCMD_LO_addcmd_shift                                          (0)
#define DC2_SYS_DC_MT_ADDCMD_LO_addcmd_mask                                           (0xFFFFFFFF)
#define DC2_SYS_DC_MT_ADDCMD_LO_addcmd(data)                                          (0xFFFFFFFF&((data)<<0))
#define DC2_SYS_DC_MT_ADDCMD_LO_addcmd_src(data)                                      ((0xFFFFFFFF&(data))>>0)
#define DC2_SYS_DC_MT_ADDCMD_LO_get_addcmd(data)                                      ((0xFFFFFFFF&(data))>>0)


#define DC2_SYS_DC_MT_ADDCMD_SA_0                                                     0x180032B0
#define DC2_SYS_DC_MT_ADDCMD_SA_1                                                     0x180032B4
#define DC2_SYS_DC_MT_ADDCMD_SA_2                                                     0x180032B8
#define DC2_SYS_DC_MT_ADDCMD_SA_3                                                     0x180032BC
#define DC2_SYS_DC_MT_ADDCMD_SA_0_reg_addr                                            "0xB80032B0"
#define DC2_SYS_DC_MT_ADDCMD_SA_1_reg_addr                                            "0xB80032B4"
#define DC2_SYS_DC_MT_ADDCMD_SA_2_reg_addr                                            "0xB80032B8"
#define DC2_SYS_DC_MT_ADDCMD_SA_3_reg_addr                                            "0xB80032BC"
#define DC2_SYS_DC_MT_ADDCMD_SA_0_reg                                                 0xB80032B0
#define DC2_SYS_DC_MT_ADDCMD_SA_1_reg                                                 0xB80032B4
#define DC2_SYS_DC_MT_ADDCMD_SA_2_reg                                                 0xB80032B8
#define DC2_SYS_DC_MT_ADDCMD_SA_3_reg                                                 0xB80032BC
#define set_DC2_SYS_DC_MT_ADDCMD_SA_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_SA_0_reg)=data)
#define set_DC2_SYS_DC_MT_ADDCMD_SA_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_SA_1_reg)=data)
#define set_DC2_SYS_DC_MT_ADDCMD_SA_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_SA_2_reg)=data)
#define set_DC2_SYS_DC_MT_ADDCMD_SA_3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_SA_3_reg)=data)
#define get_DC2_SYS_DC_MT_ADDCMD_SA_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_SA_0_reg))
#define get_DC2_SYS_DC_MT_ADDCMD_SA_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_SA_1_reg))
#define get_DC2_SYS_DC_MT_ADDCMD_SA_2_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_SA_2_reg))
#define get_DC2_SYS_DC_MT_ADDCMD_SA_3_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_SA_3_reg))
#define DC2_SYS_DC_MT_ADDCMD_SA_0_inst_adr                                            "0x00AC"
#define DC2_SYS_DC_MT_ADDCMD_SA_1_inst_adr                                            "0x00AD"
#define DC2_SYS_DC_MT_ADDCMD_SA_2_inst_adr                                            "0x00AE"
#define DC2_SYS_DC_MT_ADDCMD_SA_3_inst_adr                                            "0x00AF"
#define DC2_SYS_DC_MT_ADDCMD_SA_0_inst                                                0x00AC
#define DC2_SYS_DC_MT_ADDCMD_SA_1_inst                                                0x00AD
#define DC2_SYS_DC_MT_ADDCMD_SA_2_inst                                                0x00AE
#define DC2_SYS_DC_MT_ADDCMD_SA_3_inst                                                0x00AF
#define DC2_SYS_DC_MT_ADDCMD_SA_trap_seq_sa_shift                                     (0)
#define DC2_SYS_DC_MT_ADDCMD_SA_trap_seq_sa_mask                                      (0xFFFFFFFF)
#define DC2_SYS_DC_MT_ADDCMD_SA_trap_seq_sa(data)                                     (0xFFFFFFFF&((data)<<0))
#define DC2_SYS_DC_MT_ADDCMD_SA_trap_seq_sa_src(data)                                 ((0xFFFFFFFF&(data))>>0)
#define DC2_SYS_DC_MT_ADDCMD_SA_get_trap_seq_sa(data)                                 ((0xFFFFFFFF&(data))>>0)


#define DC2_SYS_DC_MT_MISC                                                            0x180032C0
#define DC2_SYS_DC_MT_MISC_reg_addr                                                   "0xB80032C0"
#define DC2_SYS_DC_MT_MISC_reg                                                        0xB80032C0
#define set_DC2_SYS_DC_MT_MISC_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_MISC_reg)=data)
#define get_DC2_SYS_DC_MT_MISC_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_MISC_reg))
#define DC2_SYS_DC_MT_MISC_inst_adr                                                   "0x00B0"
#define DC2_SYS_DC_MT_MISC_inst                                                       0x00B0
#define DC2_SYS_DC_MT_MISC_enable_block_info_shift                                    (1)
#define DC2_SYS_DC_MT_MISC_enable_block_info_mask                                     (0x00000002)
#define DC2_SYS_DC_MT_MISC_enable_block_info(data)                                    (0x00000002&((data)<<1))
#define DC2_SYS_DC_MT_MISC_enable_block_info_src(data)                                ((0x00000002&(data))>>1)
#define DC2_SYS_DC_MT_MISC_get_enable_block_info(data)                                ((0x00000002&(data))>>1)
#define DC2_SYS_DC_MT_MISC_disable_cross_range_check_shift                            (0)
#define DC2_SYS_DC_MT_MISC_disable_cross_range_check_mask                             (0x00000001)
#define DC2_SYS_DC_MT_MISC_disable_cross_range_check(data)                            (0x00000001&((data)<<0))
#define DC2_SYS_DC_MT_MISC_disable_cross_range_check_src(data)                        ((0x00000001&(data))>>0)
#define DC2_SYS_DC_MT_MISC_get_disable_cross_range_check(data)                        ((0x00000001&(data))>>0)


#define DC2_SYS_DC_EC_CTRL                                                            0x180032D0
#define DC2_SYS_DC_EC_CTRL_reg_addr                                                   "0xB80032D0"
#define DC2_SYS_DC_EC_CTRL_reg                                                        0xB80032D0
#define set_DC2_SYS_DC_EC_CTRL_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_EC_CTRL_reg)=data)
#define get_DC2_SYS_DC_EC_CTRL_reg   (*((volatile unsigned int*) DC2_SYS_DC_EC_CTRL_reg))
#define DC2_SYS_DC_EC_CTRL_inst_adr                                                   "0x00B4"
#define DC2_SYS_DC_EC_CTRL_inst                                                       0x00B4
#define DC2_SYS_DC_EC_CTRL_write_enable3_shift                                        (31)
#define DC2_SYS_DC_EC_CTRL_write_enable3_mask                                         (0x80000000)
#define DC2_SYS_DC_EC_CTRL_write_enable3(data)                                        (0x80000000&((data)<<31))
#define DC2_SYS_DC_EC_CTRL_write_enable3_src(data)                                    ((0x80000000&(data))>>31)
#define DC2_SYS_DC_EC_CTRL_get_write_enable3(data)                                    ((0x80000000&(data))>>31)
#define DC2_SYS_DC_EC_CTRL_error_cmd_swap_addr_shift                                  (4)
#define DC2_SYS_DC_EC_CTRL_error_cmd_swap_addr_mask                                   (0x7FFFFFF0)
#define DC2_SYS_DC_EC_CTRL_error_cmd_swap_addr(data)                                  (0x7FFFFFF0&((data)<<4))
#define DC2_SYS_DC_EC_CTRL_error_cmd_swap_addr_src(data)                              ((0x7FFFFFF0&(data))>>4)
#define DC2_SYS_DC_EC_CTRL_get_error_cmd_swap_addr(data)                              ((0x7FFFFFF0&(data))>>4)
#define DC2_SYS_DC_EC_CTRL_write_enable2_shift                                        (3)
#define DC2_SYS_DC_EC_CTRL_write_enable2_mask                                         (0x00000008)
#define DC2_SYS_DC_EC_CTRL_write_enable2(data)                                        (0x00000008&((data)<<3))
#define DC2_SYS_DC_EC_CTRL_write_enable2_src(data)                                    ((0x00000008&(data))>>3)
#define DC2_SYS_DC_EC_CTRL_get_write_enable2(data)                                    ((0x00000008&(data))>>3)
#define DC2_SYS_DC_EC_CTRL_error_cmd_swap_en_shift                                    (2)
#define DC2_SYS_DC_EC_CTRL_error_cmd_swap_en_mask                                     (0x00000004)
#define DC2_SYS_DC_EC_CTRL_error_cmd_swap_en(data)                                    (0x00000004&((data)<<2))
#define DC2_SYS_DC_EC_CTRL_error_cmd_swap_en_src(data)                                ((0x00000004&(data))>>2)
#define DC2_SYS_DC_EC_CTRL_get_error_cmd_swap_en(data)                                ((0x00000004&(data))>>2)
#define DC2_SYS_DC_EC_CTRL_write_enable1_shift                                        (1)
#define DC2_SYS_DC_EC_CTRL_write_enable1_mask                                         (0x00000002)
#define DC2_SYS_DC_EC_CTRL_write_enable1(data)                                        (0x00000002&((data)<<1))
#define DC2_SYS_DC_EC_CTRL_write_enable1_src(data)                                    ((0x00000002&(data))>>1)
#define DC2_SYS_DC_EC_CTRL_get_write_enable1(data)                                    ((0x00000002&(data))>>1)
#define DC2_SYS_DC_EC_CTRL_error_cmd_detection_en_shift                               (0)
#define DC2_SYS_DC_EC_CTRL_error_cmd_detection_en_mask                                (0x00000001)
#define DC2_SYS_DC_EC_CTRL_error_cmd_detection_en(data)                               (0x00000001&((data)<<0))
#define DC2_SYS_DC_EC_CTRL_error_cmd_detection_en_src(data)                           ((0x00000001&(data))>>0)
#define DC2_SYS_DC_EC_CTRL_get_error_cmd_detection_en(data)                           ((0x00000001&(data))>>0)


#define DC2_SYS_DC_EC_ADDCMD_HI                                                       0x180032D4
#define DC2_SYS_DC_EC_ADDCMD_HI_reg_addr                                              "0xB80032D4"
#define DC2_SYS_DC_EC_ADDCMD_HI_reg                                                   0xB80032D4
#define set_DC2_SYS_DC_EC_ADDCMD_HI_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_EC_ADDCMD_HI_reg)=data)
#define get_DC2_SYS_DC_EC_ADDCMD_HI_reg   (*((volatile unsigned int*) DC2_SYS_DC_EC_ADDCMD_HI_reg))
#define DC2_SYS_DC_EC_ADDCMD_HI_inst_adr                                              "0x00B5"
#define DC2_SYS_DC_EC_ADDCMD_HI_inst                                                  0x00B5
#define DC2_SYS_DC_EC_ADDCMD_HI_error_cmd_ever_trap_shift                             (30)
#define DC2_SYS_DC_EC_ADDCMD_HI_error_cmd_ever_trap_mask                              (0x40000000)
#define DC2_SYS_DC_EC_ADDCMD_HI_error_cmd_ever_trap(data)                             (0x40000000&((data)<<30))
#define DC2_SYS_DC_EC_ADDCMD_HI_error_cmd_ever_trap_src(data)                         ((0x40000000&(data))>>30)
#define DC2_SYS_DC_EC_ADDCMD_HI_get_error_cmd_ever_trap(data)                         ((0x40000000&(data))>>30)
#define DC2_SYS_DC_EC_ADDCMD_HI_trap_case_shift                                       (22)
#define DC2_SYS_DC_EC_ADDCMD_HI_trap_case_mask                                        (0x3FC00000)
#define DC2_SYS_DC_EC_ADDCMD_HI_trap_case(data)                                       (0x3FC00000&((data)<<22))
#define DC2_SYS_DC_EC_ADDCMD_HI_trap_case_src(data)                                   ((0x3FC00000&(data))>>22)
#define DC2_SYS_DC_EC_ADDCMD_HI_get_trap_case(data)                                   ((0x3FC00000&(data))>>22)
#define DC2_SYS_DC_EC_ADDCMD_HI_Addcmd_hi_shift                                       (0)
#define DC2_SYS_DC_EC_ADDCMD_HI_Addcmd_hi_mask                                        (0x003FFFFF)
#define DC2_SYS_DC_EC_ADDCMD_HI_Addcmd_hi(data)                                       (0x003FFFFF&((data)<<0))
#define DC2_SYS_DC_EC_ADDCMD_HI_Addcmd_hi_src(data)                                   ((0x003FFFFF&(data))>>0)
#define DC2_SYS_DC_EC_ADDCMD_HI_get_Addcmd_hi(data)                                   ((0x003FFFFF&(data))>>0)


#define DC2_SYS_DC_EC_ADDCMD_LO                                                       0x180032D8
#define DC2_SYS_DC_EC_ADDCMD_LO_reg_addr                                              "0xB80032D8"
#define DC2_SYS_DC_EC_ADDCMD_LO_reg                                                   0xB80032D8
#define set_DC2_SYS_DC_EC_ADDCMD_LO_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_EC_ADDCMD_LO_reg)=data)
#define get_DC2_SYS_DC_EC_ADDCMD_LO_reg   (*((volatile unsigned int*) DC2_SYS_DC_EC_ADDCMD_LO_reg))
#define DC2_SYS_DC_EC_ADDCMD_LO_inst_adr                                              "0x00B6"
#define DC2_SYS_DC_EC_ADDCMD_LO_inst                                                  0x00B6
#define DC2_SYS_DC_EC_ADDCMD_LO_Addcmd_lo_shift                                       (0)
#define DC2_SYS_DC_EC_ADDCMD_LO_Addcmd_lo_mask                                        (0xFFFFFFFF)
#define DC2_SYS_DC_EC_ADDCMD_LO_Addcmd_lo(data)                                       (0xFFFFFFFF&((data)<<0))
#define DC2_SYS_DC_EC_ADDCMD_LO_Addcmd_lo_src(data)                                   ((0xFFFFFFFF&(data))>>0)
#define DC2_SYS_DC_EC_ADDCMD_LO_get_Addcmd_lo(data)                                   ((0xFFFFFFFF&(data))>>0)


#define DC2_SYS_DC_RD_TAG_CHECK                                                       0x180032DC
#define DC2_SYS_DC_RD_TAG_CHECK_reg_addr                                              "0xB80032DC"
#define DC2_SYS_DC_RD_TAG_CHECK_reg                                                   0xB80032DC
#define set_DC2_SYS_DC_RD_TAG_CHECK_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_RD_TAG_CHECK_reg)=data)
#define get_DC2_SYS_DC_RD_TAG_CHECK_reg   (*((volatile unsigned int*) DC2_SYS_DC_RD_TAG_CHECK_reg))
#define DC2_SYS_DC_RD_TAG_CHECK_inst_adr                                              "0x00B7"
#define DC2_SYS_DC_RD_TAG_CHECK_inst                                                  0x00B7
#define DC2_SYS_DC_RD_TAG_CHECK_write_enable1_shift                                   (1)
#define DC2_SYS_DC_RD_TAG_CHECK_write_enable1_mask                                    (0x00000002)
#define DC2_SYS_DC_RD_TAG_CHECK_write_enable1(data)                                   (0x00000002&((data)<<1))
#define DC2_SYS_DC_RD_TAG_CHECK_write_enable1_src(data)                               ((0x00000002&(data))>>1)
#define DC2_SYS_DC_RD_TAG_CHECK_get_write_enable1(data)                               ((0x00000002&(data))>>1)
#define DC2_SYS_DC_RD_TAG_CHECK_tag_check_en_shift                                    (0)
#define DC2_SYS_DC_RD_TAG_CHECK_tag_check_en_mask                                     (0x00000001)
#define DC2_SYS_DC_RD_TAG_CHECK_tag_check_en(data)                                    (0x00000001&((data)<<0))
#define DC2_SYS_DC_RD_TAG_CHECK_tag_check_en_src(data)                                ((0x00000001&(data))>>0)
#define DC2_SYS_DC_RD_TAG_CHECK_get_tag_check_en(data)                                ((0x00000001&(data))>>0)


#define DC2_SYS_DC_INT_ENABLE                                                         0x180032E8
#define DC2_SYS_DC_INT_ENABLE_reg_addr                                                "0xB80032E8"
#define DC2_SYS_DC_INT_ENABLE_reg                                                     0xB80032E8
#define set_DC2_SYS_DC_INT_ENABLE_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_INT_ENABLE_reg)=data)
#define get_DC2_SYS_DC_INT_ENABLE_reg   (*((volatile unsigned int*) DC2_SYS_DC_INT_ENABLE_reg))
#define DC2_SYS_DC_INT_ENABLE_inst_adr                                                "0x00BA"
#define DC2_SYS_DC_INT_ENABLE_inst                                                    0x00BA
#define DC2_SYS_DC_INT_ENABLE_pic_offset_x_odd_int_en_shift                           (24)
#define DC2_SYS_DC_INT_ENABLE_pic_offset_x_odd_int_en_mask                            (0x01000000)
#define DC2_SYS_DC_INT_ENABLE_pic_offset_x_odd_int_en(data)                           (0x01000000&((data)<<24))
#define DC2_SYS_DC_INT_ENABLE_pic_offset_x_odd_int_en_src(data)                       ((0x01000000&(data))>>24)
#define DC2_SYS_DC_INT_ENABLE_get_pic_offset_x_odd_int_en(data)                       ((0x01000000&(data))>>24)
#define DC2_SYS_DC_INT_ENABLE_rd_tag_mismatch_int_en_shift                            (23)
#define DC2_SYS_DC_INT_ENABLE_rd_tag_mismatch_int_en_mask                             (0x00800000)
#define DC2_SYS_DC_INT_ENABLE_rd_tag_mismatch_int_en(data)                            (0x00800000&((data)<<23))
#define DC2_SYS_DC_INT_ENABLE_rd_tag_mismatch_int_en_src(data)                        ((0x00800000&(data))>>23)
#define DC2_SYS_DC_INT_ENABLE_get_rd_tag_mismatch_int_en(data)                        ((0x00800000&(data))>>23)
#define DC2_SYS_DC_INT_ENABLE_err_seq_sa_odd_int_en_shift                             (22)
#define DC2_SYS_DC_INT_ENABLE_err_seq_sa_odd_int_en_mask                              (0x00400000)
#define DC2_SYS_DC_INT_ENABLE_err_seq_sa_odd_int_en(data)                             (0x00400000&((data)<<22))
#define DC2_SYS_DC_INT_ENABLE_err_seq_sa_odd_int_en_src(data)                         ((0x00400000&(data))>>22)
#define DC2_SYS_DC_INT_ENABLE_get_err_seq_sa_odd_int_en(data)                         ((0x00400000&(data))>>22)
#define DC2_SYS_DC_INT_ENABLE_err_seq_bl_zero_int_en_shift                            (21)
#define DC2_SYS_DC_INT_ENABLE_err_seq_bl_zero_int_en_mask                             (0x00200000)
#define DC2_SYS_DC_INT_ENABLE_err_seq_bl_zero_int_en(data)                            (0x00200000&((data)<<21))
#define DC2_SYS_DC_INT_ENABLE_err_seq_bl_zero_int_en_src(data)                        ((0x00200000&(data))>>21)
#define DC2_SYS_DC_INT_ENABLE_get_err_seq_bl_zero_int_en(data)                        ((0x00200000&(data))>>21)
#define DC2_SYS_DC_INT_ENABLE_err_seq_bl_odd_int_en_shift                             (20)
#define DC2_SYS_DC_INT_ENABLE_err_seq_bl_odd_int_en_mask                              (0x00100000)
#define DC2_SYS_DC_INT_ENABLE_err_seq_bl_odd_int_en(data)                             (0x00100000&((data)<<20))
#define DC2_SYS_DC_INT_ENABLE_err_seq_bl_odd_int_en_src(data)                         ((0x00100000&(data))>>20)
#define DC2_SYS_DC_INT_ENABLE_get_err_seq_bl_odd_int_en(data)                         ((0x00100000&(data))>>20)
#define DC2_SYS_DC_INT_ENABLE_err_blk_8x2_on_64_int_en_shift                          (19)
#define DC2_SYS_DC_INT_ENABLE_err_blk_8x2_on_64_int_en_mask                           (0x00080000)
#define DC2_SYS_DC_INT_ENABLE_err_blk_8x2_on_64_int_en(data)                          (0x00080000&((data)<<19))
#define DC2_SYS_DC_INT_ENABLE_err_blk_8x2_on_64_int_en_src(data)                      ((0x00080000&(data))>>19)
#define DC2_SYS_DC_INT_ENABLE_get_err_blk_8x2_on_64_int_en(data)                      ((0x00080000&(data))>>19)
#define DC2_SYS_DC_INT_ENABLE_err_blk_size_exceed_int_en_shift                        (18)
#define DC2_SYS_DC_INT_ENABLE_err_blk_size_exceed_int_en_mask                         (0x00040000)
#define DC2_SYS_DC_INT_ENABLE_err_blk_size_exceed_int_en(data)                        (0x00040000&((data)<<18))
#define DC2_SYS_DC_INT_ENABLE_err_blk_size_exceed_int_en_src(data)                    ((0x00040000&(data))>>18)
#define DC2_SYS_DC_INT_ENABLE_get_err_blk_size_exceed_int_en(data)                    ((0x00040000&(data))>>18)
#define DC2_SYS_DC_INT_ENABLE_err_blk_h_zero_int_en_shift                             (17)
#define DC2_SYS_DC_INT_ENABLE_err_blk_h_zero_int_en_mask                              (0x00020000)
#define DC2_SYS_DC_INT_ENABLE_err_blk_h_zero_int_en(data)                             (0x00020000&((data)<<17))
#define DC2_SYS_DC_INT_ENABLE_err_blk_h_zero_int_en_src(data)                         ((0x00020000&(data))>>17)
#define DC2_SYS_DC_INT_ENABLE_get_err_blk_h_zero_int_en(data)                         ((0x00020000&(data))>>17)
#define DC2_SYS_DC_INT_ENABLE_err_blk_w_zero_int_en_shift                             (16)
#define DC2_SYS_DC_INT_ENABLE_err_blk_w_zero_int_en_mask                              (0x00010000)
#define DC2_SYS_DC_INT_ENABLE_err_blk_w_zero_int_en(data)                             (0x00010000&((data)<<16))
#define DC2_SYS_DC_INT_ENABLE_err_blk_w_zero_int_en_src(data)                         ((0x00010000&(data))>>16)
#define DC2_SYS_DC_INT_ENABLE_get_err_blk_w_zero_int_en(data)                         ((0x00010000&(data))>>16)
#define DC2_SYS_DC_INT_ENABLE_mt_3_mod3_int_en_shift                                  (12)
#define DC2_SYS_DC_INT_ENABLE_mt_3_mod3_int_en_mask                                   (0x00001000)
#define DC2_SYS_DC_INT_ENABLE_mt_3_mod3_int_en(data)                                  (0x00001000&((data)<<12))
#define DC2_SYS_DC_INT_ENABLE_mt_3_mod3_int_en_src(data)                              ((0x00001000&(data))>>12)
#define DC2_SYS_DC_INT_ENABLE_get_mt_3_mod3_int_en(data)                              ((0x00001000&(data))>>12)
#define DC2_SYS_DC_INT_ENABLE_mt_3_mod2_int_en_shift                                  (11)
#define DC2_SYS_DC_INT_ENABLE_mt_3_mod2_int_en_mask                                   (0x00000800)
#define DC2_SYS_DC_INT_ENABLE_mt_3_mod2_int_en(data)                                  (0x00000800&((data)<<11))
#define DC2_SYS_DC_INT_ENABLE_mt_3_mod2_int_en_src(data)                              ((0x00000800&(data))>>11)
#define DC2_SYS_DC_INT_ENABLE_get_mt_3_mod2_int_en(data)                              ((0x00000800&(data))>>11)
#define DC2_SYS_DC_INT_ENABLE_mt_3_mod1_int_en_shift                                  (10)
#define DC2_SYS_DC_INT_ENABLE_mt_3_mod1_int_en_mask                                   (0x00000400)
#define DC2_SYS_DC_INT_ENABLE_mt_3_mod1_int_en(data)                                  (0x00000400&((data)<<10))
#define DC2_SYS_DC_INT_ENABLE_mt_3_mod1_int_en_src(data)                              ((0x00000400&(data))>>10)
#define DC2_SYS_DC_INT_ENABLE_get_mt_3_mod1_int_en(data)                              ((0x00000400&(data))>>10)
#define DC2_SYS_DC_INT_ENABLE_mt_2_mod3_int_en_shift                                  (9)
#define DC2_SYS_DC_INT_ENABLE_mt_2_mod3_int_en_mask                                   (0x00000200)
#define DC2_SYS_DC_INT_ENABLE_mt_2_mod3_int_en(data)                                  (0x00000200&((data)<<9))
#define DC2_SYS_DC_INT_ENABLE_mt_2_mod3_int_en_src(data)                              ((0x00000200&(data))>>9)
#define DC2_SYS_DC_INT_ENABLE_get_mt_2_mod3_int_en(data)                              ((0x00000200&(data))>>9)
#define DC2_SYS_DC_INT_ENABLE_mt_2_mod2_int_en_shift                                  (8)
#define DC2_SYS_DC_INT_ENABLE_mt_2_mod2_int_en_mask                                   (0x00000100)
#define DC2_SYS_DC_INT_ENABLE_mt_2_mod2_int_en(data)                                  (0x00000100&((data)<<8))
#define DC2_SYS_DC_INT_ENABLE_mt_2_mod2_int_en_src(data)                              ((0x00000100&(data))>>8)
#define DC2_SYS_DC_INT_ENABLE_get_mt_2_mod2_int_en(data)                              ((0x00000100&(data))>>8)
#define DC2_SYS_DC_INT_ENABLE_mt_2_mod1_int_en_shift                                  (7)
#define DC2_SYS_DC_INT_ENABLE_mt_2_mod1_int_en_mask                                   (0x00000080)
#define DC2_SYS_DC_INT_ENABLE_mt_2_mod1_int_en(data)                                  (0x00000080&((data)<<7))
#define DC2_SYS_DC_INT_ENABLE_mt_2_mod1_int_en_src(data)                              ((0x00000080&(data))>>7)
#define DC2_SYS_DC_INT_ENABLE_get_mt_2_mod1_int_en(data)                              ((0x00000080&(data))>>7)
#define DC2_SYS_DC_INT_ENABLE_mt_1_mod3_int_en_shift                                  (6)
#define DC2_SYS_DC_INT_ENABLE_mt_1_mod3_int_en_mask                                   (0x00000040)
#define DC2_SYS_DC_INT_ENABLE_mt_1_mod3_int_en(data)                                  (0x00000040&((data)<<6))
#define DC2_SYS_DC_INT_ENABLE_mt_1_mod3_int_en_src(data)                              ((0x00000040&(data))>>6)
#define DC2_SYS_DC_INT_ENABLE_get_mt_1_mod3_int_en(data)                              ((0x00000040&(data))>>6)
#define DC2_SYS_DC_INT_ENABLE_mt_1_mod2_int_en_shift                                  (5)
#define DC2_SYS_DC_INT_ENABLE_mt_1_mod2_int_en_mask                                   (0x00000020)
#define DC2_SYS_DC_INT_ENABLE_mt_1_mod2_int_en(data)                                  (0x00000020&((data)<<5))
#define DC2_SYS_DC_INT_ENABLE_mt_1_mod2_int_en_src(data)                              ((0x00000020&(data))>>5)
#define DC2_SYS_DC_INT_ENABLE_get_mt_1_mod2_int_en(data)                              ((0x00000020&(data))>>5)
#define DC2_SYS_DC_INT_ENABLE_mt_1_mod1_int_en_shift                                  (4)
#define DC2_SYS_DC_INT_ENABLE_mt_1_mod1_int_en_mask                                   (0x00000010)
#define DC2_SYS_DC_INT_ENABLE_mt_1_mod1_int_en(data)                                  (0x00000010&((data)<<4))
#define DC2_SYS_DC_INT_ENABLE_mt_1_mod1_int_en_src(data)                              ((0x00000010&(data))>>4)
#define DC2_SYS_DC_INT_ENABLE_get_mt_1_mod1_int_en(data)                              ((0x00000010&(data))>>4)
#define DC2_SYS_DC_INT_ENABLE_mt_0_mod3_int_en_shift                                  (3)
#define DC2_SYS_DC_INT_ENABLE_mt_0_mod3_int_en_mask                                   (0x00000008)
#define DC2_SYS_DC_INT_ENABLE_mt_0_mod3_int_en(data)                                  (0x00000008&((data)<<3))
#define DC2_SYS_DC_INT_ENABLE_mt_0_mod3_int_en_src(data)                              ((0x00000008&(data))>>3)
#define DC2_SYS_DC_INT_ENABLE_get_mt_0_mod3_int_en(data)                              ((0x00000008&(data))>>3)
#define DC2_SYS_DC_INT_ENABLE_mt_0_mod2_int_en_shift                                  (2)
#define DC2_SYS_DC_INT_ENABLE_mt_0_mod2_int_en_mask                                   (0x00000004)
#define DC2_SYS_DC_INT_ENABLE_mt_0_mod2_int_en(data)                                  (0x00000004&((data)<<2))
#define DC2_SYS_DC_INT_ENABLE_mt_0_mod2_int_en_src(data)                              ((0x00000004&(data))>>2)
#define DC2_SYS_DC_INT_ENABLE_get_mt_0_mod2_int_en(data)                              ((0x00000004&(data))>>2)
#define DC2_SYS_DC_INT_ENABLE_mt_0_mod1_int_en_shift                                  (1)
#define DC2_SYS_DC_INT_ENABLE_mt_0_mod1_int_en_mask                                   (0x00000002)
#define DC2_SYS_DC_INT_ENABLE_mt_0_mod1_int_en(data)                                  (0x00000002&((data)<<1))
#define DC2_SYS_DC_INT_ENABLE_mt_0_mod1_int_en_src(data)                              ((0x00000002&(data))>>1)
#define DC2_SYS_DC_INT_ENABLE_get_mt_0_mod1_int_en(data)                              ((0x00000002&(data))>>1)
#define DC2_SYS_DC_INT_ENABLE_write_data_shift                                        (0)
#define DC2_SYS_DC_INT_ENABLE_write_data_mask                                         (0x00000001)
#define DC2_SYS_DC_INT_ENABLE_write_data(data)                                        (0x00000001&((data)<<0))
#define DC2_SYS_DC_INT_ENABLE_write_data_src(data)                                    ((0x00000001&(data))>>0)
#define DC2_SYS_DC_INT_ENABLE_get_write_data(data)                                    ((0x00000001&(data))>>0)


#define DC2_SYS_DC_INT_STATUS                                                         0x180032EC
#define DC2_SYS_DC_INT_STATUS_reg_addr                                                "0xB80032EC"
#define DC2_SYS_DC_INT_STATUS_reg                                                     0xB80032EC
#define set_DC2_SYS_DC_INT_STATUS_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_INT_STATUS_reg)=data)
#define get_DC2_SYS_DC_INT_STATUS_reg   (*((volatile unsigned int*) DC2_SYS_DC_INT_STATUS_reg))
#define DC2_SYS_DC_INT_STATUS_inst_adr                                                "0x00BB"
#define DC2_SYS_DC_INT_STATUS_inst                                                    0x00BB
#define DC2_SYS_DC_INT_STATUS_pic_offset_x_odd_int_shift                              (24)
#define DC2_SYS_DC_INT_STATUS_pic_offset_x_odd_int_mask                               (0x01000000)
#define DC2_SYS_DC_INT_STATUS_pic_offset_x_odd_int(data)                              (0x01000000&((data)<<24))
#define DC2_SYS_DC_INT_STATUS_pic_offset_x_odd_int_src(data)                          ((0x01000000&(data))>>24)
#define DC2_SYS_DC_INT_STATUS_get_pic_offset_x_odd_int(data)                          ((0x01000000&(data))>>24)
#define DC2_SYS_DC_INT_STATUS_rd_tag_mismatch_int_shift                               (23)
#define DC2_SYS_DC_INT_STATUS_rd_tag_mismatch_int_mask                                (0x00800000)
#define DC2_SYS_DC_INT_STATUS_rd_tag_mismatch_int(data)                               (0x00800000&((data)<<23))
#define DC2_SYS_DC_INT_STATUS_rd_tag_mismatch_int_src(data)                           ((0x00800000&(data))>>23)
#define DC2_SYS_DC_INT_STATUS_get_rd_tag_mismatch_int(data)                           ((0x00800000&(data))>>23)
#define DC2_SYS_DC_INT_STATUS_err_seq_sa_odd_int_shift                                (22)
#define DC2_SYS_DC_INT_STATUS_err_seq_sa_odd_int_mask                                 (0x00400000)
#define DC2_SYS_DC_INT_STATUS_err_seq_sa_odd_int(data)                                (0x00400000&((data)<<22))
#define DC2_SYS_DC_INT_STATUS_err_seq_sa_odd_int_src(data)                            ((0x00400000&(data))>>22)
#define DC2_SYS_DC_INT_STATUS_get_err_seq_sa_odd_int(data)                            ((0x00400000&(data))>>22)
#define DC2_SYS_DC_INT_STATUS_err_seq_bl_zero_int_shift                               (21)
#define DC2_SYS_DC_INT_STATUS_err_seq_bl_zero_int_mask                                (0x00200000)
#define DC2_SYS_DC_INT_STATUS_err_seq_bl_zero_int(data)                               (0x00200000&((data)<<21))
#define DC2_SYS_DC_INT_STATUS_err_seq_bl_zero_int_src(data)                           ((0x00200000&(data))>>21)
#define DC2_SYS_DC_INT_STATUS_get_err_seq_bl_zero_int(data)                           ((0x00200000&(data))>>21)
#define DC2_SYS_DC_INT_STATUS_err_seq_bl_odd_int_shift                                (20)
#define DC2_SYS_DC_INT_STATUS_err_seq_bl_odd_int_mask                                 (0x00100000)
#define DC2_SYS_DC_INT_STATUS_err_seq_bl_odd_int(data)                                (0x00100000&((data)<<20))
#define DC2_SYS_DC_INT_STATUS_err_seq_bl_odd_int_src(data)                            ((0x00100000&(data))>>20)
#define DC2_SYS_DC_INT_STATUS_get_err_seq_bl_odd_int(data)                            ((0x00100000&(data))>>20)
#define DC2_SYS_DC_INT_STATUS_err_blk_8x2_on_64_int_shift                             (19)
#define DC2_SYS_DC_INT_STATUS_err_blk_8x2_on_64_int_mask                              (0x00080000)
#define DC2_SYS_DC_INT_STATUS_err_blk_8x2_on_64_int(data)                             (0x00080000&((data)<<19))
#define DC2_SYS_DC_INT_STATUS_err_blk_8x2_on_64_int_src(data)                         ((0x00080000&(data))>>19)
#define DC2_SYS_DC_INT_STATUS_get_err_blk_8x2_on_64_int(data)                         ((0x00080000&(data))>>19)
#define DC2_SYS_DC_INT_STATUS_err_blk_size_exceed_int_shift                           (18)
#define DC2_SYS_DC_INT_STATUS_err_blk_size_exceed_int_mask                            (0x00040000)
#define DC2_SYS_DC_INT_STATUS_err_blk_size_exceed_int(data)                           (0x00040000&((data)<<18))
#define DC2_SYS_DC_INT_STATUS_err_blk_size_exceed_int_src(data)                       ((0x00040000&(data))>>18)
#define DC2_SYS_DC_INT_STATUS_get_err_blk_size_exceed_int(data)                       ((0x00040000&(data))>>18)
#define DC2_SYS_DC_INT_STATUS_err_blk_h_zero_int_shift                                (17)
#define DC2_SYS_DC_INT_STATUS_err_blk_h_zero_int_mask                                 (0x00020000)
#define DC2_SYS_DC_INT_STATUS_err_blk_h_zero_int(data)                                (0x00020000&((data)<<17))
#define DC2_SYS_DC_INT_STATUS_err_blk_h_zero_int_src(data)                            ((0x00020000&(data))>>17)
#define DC2_SYS_DC_INT_STATUS_get_err_blk_h_zero_int(data)                            ((0x00020000&(data))>>17)
#define DC2_SYS_DC_INT_STATUS_err_blk_w_zero_int_shift                                (16)
#define DC2_SYS_DC_INT_STATUS_err_blk_w_zero_int_mask                                 (0x00010000)
#define DC2_SYS_DC_INT_STATUS_err_blk_w_zero_int(data)                                (0x00010000&((data)<<16))
#define DC2_SYS_DC_INT_STATUS_err_blk_w_zero_int_src(data)                            ((0x00010000&(data))>>16)
#define DC2_SYS_DC_INT_STATUS_get_err_blk_w_zero_int(data)                            ((0x00010000&(data))>>16)
#define DC2_SYS_DC_INT_STATUS_mt_3_mod3_int_shift                                     (12)
#define DC2_SYS_DC_INT_STATUS_mt_3_mod3_int_mask                                      (0x00001000)
#define DC2_SYS_DC_INT_STATUS_mt_3_mod3_int(data)                                     (0x00001000&((data)<<12))
#define DC2_SYS_DC_INT_STATUS_mt_3_mod3_int_src(data)                                 ((0x00001000&(data))>>12)
#define DC2_SYS_DC_INT_STATUS_get_mt_3_mod3_int(data)                                 ((0x00001000&(data))>>12)
#define DC2_SYS_DC_INT_STATUS_mt_3_mod2_int_shift                                     (11)
#define DC2_SYS_DC_INT_STATUS_mt_3_mod2_int_mask                                      (0x00000800)
#define DC2_SYS_DC_INT_STATUS_mt_3_mod2_int(data)                                     (0x00000800&((data)<<11))
#define DC2_SYS_DC_INT_STATUS_mt_3_mod2_int_src(data)                                 ((0x00000800&(data))>>11)
#define DC2_SYS_DC_INT_STATUS_get_mt_3_mod2_int(data)                                 ((0x00000800&(data))>>11)
#define DC2_SYS_DC_INT_STATUS_mt_3_mod1_int_shift                                     (10)
#define DC2_SYS_DC_INT_STATUS_mt_3_mod1_int_mask                                      (0x00000400)
#define DC2_SYS_DC_INT_STATUS_mt_3_mod1_int(data)                                     (0x00000400&((data)<<10))
#define DC2_SYS_DC_INT_STATUS_mt_3_mod1_int_src(data)                                 ((0x00000400&(data))>>10)
#define DC2_SYS_DC_INT_STATUS_get_mt_3_mod1_int(data)                                 ((0x00000400&(data))>>10)
#define DC2_SYS_DC_INT_STATUS_mt_2_mod3_int_shift                                     (9)
#define DC2_SYS_DC_INT_STATUS_mt_2_mod3_int_mask                                      (0x00000200)
#define DC2_SYS_DC_INT_STATUS_mt_2_mod3_int(data)                                     (0x00000200&((data)<<9))
#define DC2_SYS_DC_INT_STATUS_mt_2_mod3_int_src(data)                                 ((0x00000200&(data))>>9)
#define DC2_SYS_DC_INT_STATUS_get_mt_2_mod3_int(data)                                 ((0x00000200&(data))>>9)
#define DC2_SYS_DC_INT_STATUS_mt_2_mod2_int_shift                                     (8)
#define DC2_SYS_DC_INT_STATUS_mt_2_mod2_int_mask                                      (0x00000100)
#define DC2_SYS_DC_INT_STATUS_mt_2_mod2_int(data)                                     (0x00000100&((data)<<8))
#define DC2_SYS_DC_INT_STATUS_mt_2_mod2_int_src(data)                                 ((0x00000100&(data))>>8)
#define DC2_SYS_DC_INT_STATUS_get_mt_2_mod2_int(data)                                 ((0x00000100&(data))>>8)
#define DC2_SYS_DC_INT_STATUS_mt_2_mod1_int_shift                                     (7)
#define DC2_SYS_DC_INT_STATUS_mt_2_mod1_int_mask                                      (0x00000080)
#define DC2_SYS_DC_INT_STATUS_mt_2_mod1_int(data)                                     (0x00000080&((data)<<7))
#define DC2_SYS_DC_INT_STATUS_mt_2_mod1_int_src(data)                                 ((0x00000080&(data))>>7)
#define DC2_SYS_DC_INT_STATUS_get_mt_2_mod1_int(data)                                 ((0x00000080&(data))>>7)
#define DC2_SYS_DC_INT_STATUS_mt_1_mod3_int_shift                                     (6)
#define DC2_SYS_DC_INT_STATUS_mt_1_mod3_int_mask                                      (0x00000040)
#define DC2_SYS_DC_INT_STATUS_mt_1_mod3_int(data)                                     (0x00000040&((data)<<6))
#define DC2_SYS_DC_INT_STATUS_mt_1_mod3_int_src(data)                                 ((0x00000040&(data))>>6)
#define DC2_SYS_DC_INT_STATUS_get_mt_1_mod3_int(data)                                 ((0x00000040&(data))>>6)
#define DC2_SYS_DC_INT_STATUS_mt_1_mod2_int_shift                                     (5)
#define DC2_SYS_DC_INT_STATUS_mt_1_mod2_int_mask                                      (0x00000020)
#define DC2_SYS_DC_INT_STATUS_mt_1_mod2_int(data)                                     (0x00000020&((data)<<5))
#define DC2_SYS_DC_INT_STATUS_mt_1_mod2_int_src(data)                                 ((0x00000020&(data))>>5)
#define DC2_SYS_DC_INT_STATUS_get_mt_1_mod2_int(data)                                 ((0x00000020&(data))>>5)
#define DC2_SYS_DC_INT_STATUS_mt_1_mod1_int_shift                                     (4)
#define DC2_SYS_DC_INT_STATUS_mt_1_mod1_int_mask                                      (0x00000010)
#define DC2_SYS_DC_INT_STATUS_mt_1_mod1_int(data)                                     (0x00000010&((data)<<4))
#define DC2_SYS_DC_INT_STATUS_mt_1_mod1_int_src(data)                                 ((0x00000010&(data))>>4)
#define DC2_SYS_DC_INT_STATUS_get_mt_1_mod1_int(data)                                 ((0x00000010&(data))>>4)
#define DC2_SYS_DC_INT_STATUS_mt_0_mod3_int_shift                                     (3)
#define DC2_SYS_DC_INT_STATUS_mt_0_mod3_int_mask                                      (0x00000008)
#define DC2_SYS_DC_INT_STATUS_mt_0_mod3_int(data)                                     (0x00000008&((data)<<3))
#define DC2_SYS_DC_INT_STATUS_mt_0_mod3_int_src(data)                                 ((0x00000008&(data))>>3)
#define DC2_SYS_DC_INT_STATUS_get_mt_0_mod3_int(data)                                 ((0x00000008&(data))>>3)
#define DC2_SYS_DC_INT_STATUS_mt_0_mod2_int_shift                                     (2)
#define DC2_SYS_DC_INT_STATUS_mt_0_mod2_int_mask                                      (0x00000004)
#define DC2_SYS_DC_INT_STATUS_mt_0_mod2_int(data)                                     (0x00000004&((data)<<2))
#define DC2_SYS_DC_INT_STATUS_mt_0_mod2_int_src(data)                                 ((0x00000004&(data))>>2)
#define DC2_SYS_DC_INT_STATUS_get_mt_0_mod2_int(data)                                 ((0x00000004&(data))>>2)
#define DC2_SYS_DC_INT_STATUS_mt_0_mod1_int_shift                                     (1)
#define DC2_SYS_DC_INT_STATUS_mt_0_mod1_int_mask                                      (0x00000002)
#define DC2_SYS_DC_INT_STATUS_mt_0_mod1_int(data)                                     (0x00000002&((data)<<1))
#define DC2_SYS_DC_INT_STATUS_mt_0_mod1_int_src(data)                                 ((0x00000002&(data))>>1)
#define DC2_SYS_DC_INT_STATUS_get_mt_0_mod1_int(data)                                 ((0x00000002&(data))>>1)
#define DC2_SYS_DC_INT_STATUS_write_data_shift                                        (0)
#define DC2_SYS_DC_INT_STATUS_write_data_mask                                         (0x00000001)
#define DC2_SYS_DC_INT_STATUS_write_data(data)                                        (0x00000001&((data)<<0))
#define DC2_SYS_DC_INT_STATUS_write_data_src(data)                                    ((0x00000001&(data))>>0)
#define DC2_SYS_DC_INT_STATUS_get_write_data(data)                                    ((0x00000001&(data))>>0)


#define DC2_SYS_BW_CTRL                                                               0x18003300
#define DC2_SYS_BW_CTRL_reg_addr                                                      "0xB8003300"
#define DC2_SYS_BW_CTRL_reg                                                           0xB8003300
#define set_DC2_SYS_BW_CTRL_reg(data)   (*((volatile unsigned int*) DC2_SYS_BW_CTRL_reg)=data)
#define get_DC2_SYS_BW_CTRL_reg   (*((volatile unsigned int*) DC2_SYS_BW_CTRL_reg))
#define DC2_SYS_BW_CTRL_inst_adr                                                      "0x00C0"
#define DC2_SYS_BW_CTRL_inst                                                          0x00C0
#define DC2_SYS_BW_CTRL_bw_en_shift                                                   (0)
#define DC2_SYS_BW_CTRL_bw_en_mask                                                    (0x00001FFF)
#define DC2_SYS_BW_CTRL_bw_en(data)                                                   (0x00001FFF&((data)<<0))
#define DC2_SYS_BW_CTRL_bw_en_src(data)                                               ((0x00001FFF&(data))>>0)
#define DC2_SYS_BW_CTRL_get_bw_en(data)                                               ((0x00001FFF&(data))>>0)


#define DC2_SYS_BW_TIMER_THRESHOLD_0                                                  0x18003304
#define DC2_SYS_BW_TIMER_THRESHOLD_1                                                  0x18003308
#define DC2_SYS_BW_TIMER_THRESHOLD_2                                                  0x1800330C
#define DC2_SYS_BW_TIMER_THRESHOLD_3                                                  0x18003310
#define DC2_SYS_BW_TIMER_THRESHOLD_4                                                  0x18003314
#define DC2_SYS_BW_TIMER_THRESHOLD_5                                                  0x18003318
#define DC2_SYS_BW_TIMER_THRESHOLD_6                                                  0x1800331C
#define DC2_SYS_BW_TIMER_THRESHOLD_7                                                  0x18003320
#define DC2_SYS_BW_TIMER_THRESHOLD_8                                                  0x18003324
#define DC2_SYS_BW_TIMER_THRESHOLD_9                                                  0x18003328
#define DC2_SYS_BW_TIMER_THRESHOLD_10                                                  0x1800332C
#define DC2_SYS_BW_TIMER_THRESHOLD_11                                                  0x18003330
#define DC2_SYS_BW_TIMER_THRESHOLD_12                                                  0x18003334
#define DC2_SYS_BW_TIMER_THRESHOLD_0_reg_addr                                         "0xB8003304"
#define DC2_SYS_BW_TIMER_THRESHOLD_1_reg_addr                                         "0xB8003308"
#define DC2_SYS_BW_TIMER_THRESHOLD_2_reg_addr                                         "0xB800330C"
#define DC2_SYS_BW_TIMER_THRESHOLD_3_reg_addr                                         "0xB8003310"
#define DC2_SYS_BW_TIMER_THRESHOLD_4_reg_addr                                         "0xB8003314"
#define DC2_SYS_BW_TIMER_THRESHOLD_5_reg_addr                                         "0xB8003318"
#define DC2_SYS_BW_TIMER_THRESHOLD_6_reg_addr                                         "0xB800331C"
#define DC2_SYS_BW_TIMER_THRESHOLD_7_reg_addr                                         "0xB8003320"
#define DC2_SYS_BW_TIMER_THRESHOLD_8_reg_addr                                         "0xB8003324"
#define DC2_SYS_BW_TIMER_THRESHOLD_9_reg_addr                                         "0xB8003328"
#define DC2_SYS_BW_TIMER_THRESHOLD_10_reg_addr                                         "0xB800332C"
#define DC2_SYS_BW_TIMER_THRESHOLD_11_reg_addr                                         "0xB8003330"
#define DC2_SYS_BW_TIMER_THRESHOLD_12_reg_addr                                         "0xB8003334"
#define DC2_SYS_BW_TIMER_THRESHOLD_0_reg                                              0xB8003304
#define DC2_SYS_BW_TIMER_THRESHOLD_1_reg                                              0xB8003308
#define DC2_SYS_BW_TIMER_THRESHOLD_2_reg                                              0xB800330C
#define DC2_SYS_BW_TIMER_THRESHOLD_3_reg                                              0xB8003310
#define DC2_SYS_BW_TIMER_THRESHOLD_4_reg                                              0xB8003314
#define DC2_SYS_BW_TIMER_THRESHOLD_5_reg                                              0xB8003318
#define DC2_SYS_BW_TIMER_THRESHOLD_6_reg                                              0xB800331C
#define DC2_SYS_BW_TIMER_THRESHOLD_7_reg                                              0xB8003320
#define DC2_SYS_BW_TIMER_THRESHOLD_8_reg                                              0xB8003324
#define DC2_SYS_BW_TIMER_THRESHOLD_9_reg                                              0xB8003328
#define DC2_SYS_BW_TIMER_THRESHOLD_10_reg                                              0xB800332C
#define DC2_SYS_BW_TIMER_THRESHOLD_11_reg                                              0xB8003330
#define DC2_SYS_BW_TIMER_THRESHOLD_12_reg                                              0xB8003334
#define set_DC2_SYS_BW_TIMER_THRESHOLD_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_BW_TIMER_THRESHOLD_0_reg)=data)
#define set_DC2_SYS_BW_TIMER_THRESHOLD_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_BW_TIMER_THRESHOLD_1_reg)=data)
#define set_DC2_SYS_BW_TIMER_THRESHOLD_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_BW_TIMER_THRESHOLD_2_reg)=data)
#define set_DC2_SYS_BW_TIMER_THRESHOLD_3_reg(data)   (*((volatile unsigned int*) DC2_SYS_BW_TIMER_THRESHOLD_3_reg)=data)
#define set_DC2_SYS_BW_TIMER_THRESHOLD_4_reg(data)   (*((volatile unsigned int*) DC2_SYS_BW_TIMER_THRESHOLD_4_reg)=data)
#define set_DC2_SYS_BW_TIMER_THRESHOLD_5_reg(data)   (*((volatile unsigned int*) DC2_SYS_BW_TIMER_THRESHOLD_5_reg)=data)
#define set_DC2_SYS_BW_TIMER_THRESHOLD_6_reg(data)   (*((volatile unsigned int*) DC2_SYS_BW_TIMER_THRESHOLD_6_reg)=data)
#define set_DC2_SYS_BW_TIMER_THRESHOLD_7_reg(data)   (*((volatile unsigned int*) DC2_SYS_BW_TIMER_THRESHOLD_7_reg)=data)
#define set_DC2_SYS_BW_TIMER_THRESHOLD_8_reg(data)   (*((volatile unsigned int*) DC2_SYS_BW_TIMER_THRESHOLD_8_reg)=data)
#define set_DC2_SYS_BW_TIMER_THRESHOLD_9_reg(data)   (*((volatile unsigned int*) DC2_SYS_BW_TIMER_THRESHOLD_9_reg)=data)
#define set_DC2_SYS_BW_TIMER_THRESHOLD_10_reg(data)   (*((volatile unsigned int*) DC2_SYS_BW_TIMER_THRESHOLD_10_reg)=data)
#define set_DC2_SYS_BW_TIMER_THRESHOLD_11_reg(data)   (*((volatile unsigned int*) DC2_SYS_BW_TIMER_THRESHOLD_11_reg)=data)
#define set_DC2_SYS_BW_TIMER_THRESHOLD_12_reg(data)   (*((volatile unsigned int*) DC2_SYS_BW_TIMER_THRESHOLD_12_reg)=data)
#define get_DC2_SYS_BW_TIMER_THRESHOLD_0_reg   (*((volatile unsigned int*) DC2_SYS_BW_TIMER_THRESHOLD_0_reg))
#define get_DC2_SYS_BW_TIMER_THRESHOLD_1_reg   (*((volatile unsigned int*) DC2_SYS_BW_TIMER_THRESHOLD_1_reg))
#define get_DC2_SYS_BW_TIMER_THRESHOLD_2_reg   (*((volatile unsigned int*) DC2_SYS_BW_TIMER_THRESHOLD_2_reg))
#define get_DC2_SYS_BW_TIMER_THRESHOLD_3_reg   (*((volatile unsigned int*) DC2_SYS_BW_TIMER_THRESHOLD_3_reg))
#define get_DC2_SYS_BW_TIMER_THRESHOLD_4_reg   (*((volatile unsigned int*) DC2_SYS_BW_TIMER_THRESHOLD_4_reg))
#define get_DC2_SYS_BW_TIMER_THRESHOLD_5_reg   (*((volatile unsigned int*) DC2_SYS_BW_TIMER_THRESHOLD_5_reg))
#define get_DC2_SYS_BW_TIMER_THRESHOLD_6_reg   (*((volatile unsigned int*) DC2_SYS_BW_TIMER_THRESHOLD_6_reg))
#define get_DC2_SYS_BW_TIMER_THRESHOLD_7_reg   (*((volatile unsigned int*) DC2_SYS_BW_TIMER_THRESHOLD_7_reg))
#define get_DC2_SYS_BW_TIMER_THRESHOLD_8_reg   (*((volatile unsigned int*) DC2_SYS_BW_TIMER_THRESHOLD_8_reg))
#define get_DC2_SYS_BW_TIMER_THRESHOLD_9_reg   (*((volatile unsigned int*) DC2_SYS_BW_TIMER_THRESHOLD_9_reg))
#define get_DC2_SYS_BW_TIMER_THRESHOLD_10_reg   (*((volatile unsigned int*) DC2_SYS_BW_TIMER_THRESHOLD_10_reg))
#define get_DC2_SYS_BW_TIMER_THRESHOLD_11_reg   (*((volatile unsigned int*) DC2_SYS_BW_TIMER_THRESHOLD_11_reg))
#define get_DC2_SYS_BW_TIMER_THRESHOLD_12_reg   (*((volatile unsigned int*) DC2_SYS_BW_TIMER_THRESHOLD_12_reg))
#define DC2_SYS_BW_TIMER_THRESHOLD_0_inst_adr                                         "0x00C1"
#define DC2_SYS_BW_TIMER_THRESHOLD_1_inst_adr                                         "0x00C2"
#define DC2_SYS_BW_TIMER_THRESHOLD_2_inst_adr                                         "0x00C3"
#define DC2_SYS_BW_TIMER_THRESHOLD_3_inst_adr                                         "0x00C4"
#define DC2_SYS_BW_TIMER_THRESHOLD_4_inst_adr                                         "0x00C5"
#define DC2_SYS_BW_TIMER_THRESHOLD_5_inst_adr                                         "0x00C6"
#define DC2_SYS_BW_TIMER_THRESHOLD_6_inst_adr                                         "0x00C7"
#define DC2_SYS_BW_TIMER_THRESHOLD_7_inst_adr                                         "0x00C8"
#define DC2_SYS_BW_TIMER_THRESHOLD_8_inst_adr                                         "0x00C9"
#define DC2_SYS_BW_TIMER_THRESHOLD_9_inst_adr                                         "0x00CA"
#define DC2_SYS_BW_TIMER_THRESHOLD_10_inst_adr                                         "0x00CB"
#define DC2_SYS_BW_TIMER_THRESHOLD_11_inst_adr                                         "0x00CC"
#define DC2_SYS_BW_TIMER_THRESHOLD_12_inst_adr                                         "0x00CD"
#define DC2_SYS_BW_TIMER_THRESHOLD_0_inst                                             0x00C1
#define DC2_SYS_BW_TIMER_THRESHOLD_1_inst                                             0x00C2
#define DC2_SYS_BW_TIMER_THRESHOLD_2_inst                                             0x00C3
#define DC2_SYS_BW_TIMER_THRESHOLD_3_inst                                             0x00C4
#define DC2_SYS_BW_TIMER_THRESHOLD_4_inst                                             0x00C5
#define DC2_SYS_BW_TIMER_THRESHOLD_5_inst                                             0x00C6
#define DC2_SYS_BW_TIMER_THRESHOLD_6_inst                                             0x00C7
#define DC2_SYS_BW_TIMER_THRESHOLD_7_inst                                             0x00C8
#define DC2_SYS_BW_TIMER_THRESHOLD_8_inst                                             0x00C9
#define DC2_SYS_BW_TIMER_THRESHOLD_9_inst                                             0x00CA
#define DC2_SYS_BW_TIMER_THRESHOLD_10_inst                                             0x00CB
#define DC2_SYS_BW_TIMER_THRESHOLD_11_inst                                             0x00CC
#define DC2_SYS_BW_TIMER_THRESHOLD_12_inst                                             0x00CD
#define DC2_SYS_BW_TIMER_THRESHOLD_value_shift                                        (0)
#define DC2_SYS_BW_TIMER_THRESHOLD_value_mask                                         (0xFFFFFFFF)
#define DC2_SYS_BW_TIMER_THRESHOLD_value(data)                                        (0xFFFFFFFF&((data)<<0))
#define DC2_SYS_BW_TIMER_THRESHOLD_value_src(data)                                    ((0xFFFFFFFF&(data))>>0)
#define DC2_SYS_BW_TIMER_THRESHOLD_get_value(data)                                    ((0xFFFFFFFF&(data))>>0)


#define DC2_SYS_BW_REQUEST_THRESHOLD_0                                                0x18003338
#define DC2_SYS_BW_REQUEST_THRESHOLD_1                                                0x1800333C
#define DC2_SYS_BW_REQUEST_THRESHOLD_2                                                0x18003340
#define DC2_SYS_BW_REQUEST_THRESHOLD_3                                                0x18003344
#define DC2_SYS_BW_REQUEST_THRESHOLD_4                                                0x18003348
#define DC2_SYS_BW_REQUEST_THRESHOLD_5                                                0x1800334C
#define DC2_SYS_BW_REQUEST_THRESHOLD_6                                                0x18003350
#define DC2_SYS_BW_REQUEST_THRESHOLD_7                                                0x18003354
#define DC2_SYS_BW_REQUEST_THRESHOLD_8                                                0x18003358
#define DC2_SYS_BW_REQUEST_THRESHOLD_9                                                0x1800335C
#define DC2_SYS_BW_REQUEST_THRESHOLD_10                                                0x18003360
#define DC2_SYS_BW_REQUEST_THRESHOLD_11                                                0x18003364
#define DC2_SYS_BW_REQUEST_THRESHOLD_12                                                0x18003368
#define DC2_SYS_BW_REQUEST_THRESHOLD_0_reg_addr                                       "0xB8003338"
#define DC2_SYS_BW_REQUEST_THRESHOLD_1_reg_addr                                       "0xB800333C"
#define DC2_SYS_BW_REQUEST_THRESHOLD_2_reg_addr                                       "0xB8003340"
#define DC2_SYS_BW_REQUEST_THRESHOLD_3_reg_addr                                       "0xB8003344"
#define DC2_SYS_BW_REQUEST_THRESHOLD_4_reg_addr                                       "0xB8003348"
#define DC2_SYS_BW_REQUEST_THRESHOLD_5_reg_addr                                       "0xB800334C"
#define DC2_SYS_BW_REQUEST_THRESHOLD_6_reg_addr                                       "0xB8003350"
#define DC2_SYS_BW_REQUEST_THRESHOLD_7_reg_addr                                       "0xB8003354"
#define DC2_SYS_BW_REQUEST_THRESHOLD_8_reg_addr                                       "0xB8003358"
#define DC2_SYS_BW_REQUEST_THRESHOLD_9_reg_addr                                       "0xB800335C"
#define DC2_SYS_BW_REQUEST_THRESHOLD_10_reg_addr                                       "0xB8003360"
#define DC2_SYS_BW_REQUEST_THRESHOLD_11_reg_addr                                       "0xB8003364"
#define DC2_SYS_BW_REQUEST_THRESHOLD_12_reg_addr                                       "0xB8003368"
#define DC2_SYS_BW_REQUEST_THRESHOLD_0_reg                                            0xB8003338
#define DC2_SYS_BW_REQUEST_THRESHOLD_1_reg                                            0xB800333C
#define DC2_SYS_BW_REQUEST_THRESHOLD_2_reg                                            0xB8003340
#define DC2_SYS_BW_REQUEST_THRESHOLD_3_reg                                            0xB8003344
#define DC2_SYS_BW_REQUEST_THRESHOLD_4_reg                                            0xB8003348
#define DC2_SYS_BW_REQUEST_THRESHOLD_5_reg                                            0xB800334C
#define DC2_SYS_BW_REQUEST_THRESHOLD_6_reg                                            0xB8003350
#define DC2_SYS_BW_REQUEST_THRESHOLD_7_reg                                            0xB8003354
#define DC2_SYS_BW_REQUEST_THRESHOLD_8_reg                                            0xB8003358
#define DC2_SYS_BW_REQUEST_THRESHOLD_9_reg                                            0xB800335C
#define DC2_SYS_BW_REQUEST_THRESHOLD_10_reg                                            0xB8003360
#define DC2_SYS_BW_REQUEST_THRESHOLD_11_reg                                            0xB8003364
#define DC2_SYS_BW_REQUEST_THRESHOLD_12_reg                                            0xB8003368
#define set_DC2_SYS_BW_REQUEST_THRESHOLD_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_BW_REQUEST_THRESHOLD_0_reg)=data)
#define set_DC2_SYS_BW_REQUEST_THRESHOLD_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_BW_REQUEST_THRESHOLD_1_reg)=data)
#define set_DC2_SYS_BW_REQUEST_THRESHOLD_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_BW_REQUEST_THRESHOLD_2_reg)=data)
#define set_DC2_SYS_BW_REQUEST_THRESHOLD_3_reg(data)   (*((volatile unsigned int*) DC2_SYS_BW_REQUEST_THRESHOLD_3_reg)=data)
#define set_DC2_SYS_BW_REQUEST_THRESHOLD_4_reg(data)   (*((volatile unsigned int*) DC2_SYS_BW_REQUEST_THRESHOLD_4_reg)=data)
#define set_DC2_SYS_BW_REQUEST_THRESHOLD_5_reg(data)   (*((volatile unsigned int*) DC2_SYS_BW_REQUEST_THRESHOLD_5_reg)=data)
#define set_DC2_SYS_BW_REQUEST_THRESHOLD_6_reg(data)   (*((volatile unsigned int*) DC2_SYS_BW_REQUEST_THRESHOLD_6_reg)=data)
#define set_DC2_SYS_BW_REQUEST_THRESHOLD_7_reg(data)   (*((volatile unsigned int*) DC2_SYS_BW_REQUEST_THRESHOLD_7_reg)=data)
#define set_DC2_SYS_BW_REQUEST_THRESHOLD_8_reg(data)   (*((volatile unsigned int*) DC2_SYS_BW_REQUEST_THRESHOLD_8_reg)=data)
#define set_DC2_SYS_BW_REQUEST_THRESHOLD_9_reg(data)   (*((volatile unsigned int*) DC2_SYS_BW_REQUEST_THRESHOLD_9_reg)=data)
#define set_DC2_SYS_BW_REQUEST_THRESHOLD_10_reg(data)   (*((volatile unsigned int*) DC2_SYS_BW_REQUEST_THRESHOLD_10_reg)=data)
#define set_DC2_SYS_BW_REQUEST_THRESHOLD_11_reg(data)   (*((volatile unsigned int*) DC2_SYS_BW_REQUEST_THRESHOLD_11_reg)=data)
#define set_DC2_SYS_BW_REQUEST_THRESHOLD_12_reg(data)   (*((volatile unsigned int*) DC2_SYS_BW_REQUEST_THRESHOLD_12_reg)=data)
#define get_DC2_SYS_BW_REQUEST_THRESHOLD_0_reg   (*((volatile unsigned int*) DC2_SYS_BW_REQUEST_THRESHOLD_0_reg))
#define get_DC2_SYS_BW_REQUEST_THRESHOLD_1_reg   (*((volatile unsigned int*) DC2_SYS_BW_REQUEST_THRESHOLD_1_reg))
#define get_DC2_SYS_BW_REQUEST_THRESHOLD_2_reg   (*((volatile unsigned int*) DC2_SYS_BW_REQUEST_THRESHOLD_2_reg))
#define get_DC2_SYS_BW_REQUEST_THRESHOLD_3_reg   (*((volatile unsigned int*) DC2_SYS_BW_REQUEST_THRESHOLD_3_reg))
#define get_DC2_SYS_BW_REQUEST_THRESHOLD_4_reg   (*((volatile unsigned int*) DC2_SYS_BW_REQUEST_THRESHOLD_4_reg))
#define get_DC2_SYS_BW_REQUEST_THRESHOLD_5_reg   (*((volatile unsigned int*) DC2_SYS_BW_REQUEST_THRESHOLD_5_reg))
#define get_DC2_SYS_BW_REQUEST_THRESHOLD_6_reg   (*((volatile unsigned int*) DC2_SYS_BW_REQUEST_THRESHOLD_6_reg))
#define get_DC2_SYS_BW_REQUEST_THRESHOLD_7_reg   (*((volatile unsigned int*) DC2_SYS_BW_REQUEST_THRESHOLD_7_reg))
#define get_DC2_SYS_BW_REQUEST_THRESHOLD_8_reg   (*((volatile unsigned int*) DC2_SYS_BW_REQUEST_THRESHOLD_8_reg))
#define get_DC2_SYS_BW_REQUEST_THRESHOLD_9_reg   (*((volatile unsigned int*) DC2_SYS_BW_REQUEST_THRESHOLD_9_reg))
#define get_DC2_SYS_BW_REQUEST_THRESHOLD_10_reg   (*((volatile unsigned int*) DC2_SYS_BW_REQUEST_THRESHOLD_10_reg))
#define get_DC2_SYS_BW_REQUEST_THRESHOLD_11_reg   (*((volatile unsigned int*) DC2_SYS_BW_REQUEST_THRESHOLD_11_reg))
#define get_DC2_SYS_BW_REQUEST_THRESHOLD_12_reg   (*((volatile unsigned int*) DC2_SYS_BW_REQUEST_THRESHOLD_12_reg))
#define DC2_SYS_BW_REQUEST_THRESHOLD_0_inst_adr                                       "0x00CE"
#define DC2_SYS_BW_REQUEST_THRESHOLD_1_inst_adr                                       "0x00CF"
#define DC2_SYS_BW_REQUEST_THRESHOLD_2_inst_adr                                       "0x00D0"
#define DC2_SYS_BW_REQUEST_THRESHOLD_3_inst_adr                                       "0x00D1"
#define DC2_SYS_BW_REQUEST_THRESHOLD_4_inst_adr                                       "0x00D2"
#define DC2_SYS_BW_REQUEST_THRESHOLD_5_inst_adr                                       "0x00D3"
#define DC2_SYS_BW_REQUEST_THRESHOLD_6_inst_adr                                       "0x00D4"
#define DC2_SYS_BW_REQUEST_THRESHOLD_7_inst_adr                                       "0x00D5"
#define DC2_SYS_BW_REQUEST_THRESHOLD_8_inst_adr                                       "0x00D6"
#define DC2_SYS_BW_REQUEST_THRESHOLD_9_inst_adr                                       "0x00D7"
#define DC2_SYS_BW_REQUEST_THRESHOLD_10_inst_adr                                       "0x00D8"
#define DC2_SYS_BW_REQUEST_THRESHOLD_11_inst_adr                                       "0x00D9"
#define DC2_SYS_BW_REQUEST_THRESHOLD_12_inst_adr                                       "0x00DA"
#define DC2_SYS_BW_REQUEST_THRESHOLD_0_inst                                           0x00CE
#define DC2_SYS_BW_REQUEST_THRESHOLD_1_inst                                           0x00CF
#define DC2_SYS_BW_REQUEST_THRESHOLD_2_inst                                           0x00D0
#define DC2_SYS_BW_REQUEST_THRESHOLD_3_inst                                           0x00D1
#define DC2_SYS_BW_REQUEST_THRESHOLD_4_inst                                           0x00D2
#define DC2_SYS_BW_REQUEST_THRESHOLD_5_inst                                           0x00D3
#define DC2_SYS_BW_REQUEST_THRESHOLD_6_inst                                           0x00D4
#define DC2_SYS_BW_REQUEST_THRESHOLD_7_inst                                           0x00D5
#define DC2_SYS_BW_REQUEST_THRESHOLD_8_inst                                           0x00D6
#define DC2_SYS_BW_REQUEST_THRESHOLD_9_inst                                           0x00D7
#define DC2_SYS_BW_REQUEST_THRESHOLD_10_inst                                           0x00D8
#define DC2_SYS_BW_REQUEST_THRESHOLD_11_inst                                           0x00D9
#define DC2_SYS_BW_REQUEST_THRESHOLD_12_inst                                           0x00DA
#define DC2_SYS_BW_REQUEST_THRESHOLD_value_shift                                      (0)
#define DC2_SYS_BW_REQUEST_THRESHOLD_value_mask                                       (0x00FFFFFF)
#define DC2_SYS_BW_REQUEST_THRESHOLD_value(data)                                      (0x00FFFFFF&((data)<<0))
#define DC2_SYS_BW_REQUEST_THRESHOLD_value_src(data)                                  ((0x00FFFFFF&(data))>>0)
#define DC2_SYS_BW_REQUEST_THRESHOLD_get_value(data)                                  ((0x00FFFFFF&(data))>>0)


#define DC2_SYS_DC_SYS2_MUX                                                           0x18003400
#define DC2_SYS_DC_SYS2_MUX_reg_addr                                                  "0xB8003400"
#define DC2_SYS_DC_SYS2_MUX_reg                                                       0xB8003400
#define set_DC2_SYS_DC_SYS2_MUX_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_SYS2_MUX_reg)=data)
#define get_DC2_SYS_DC_SYS2_MUX_reg   (*((volatile unsigned int*) DC2_SYS_DC_SYS2_MUX_reg))
#define DC2_SYS_DC_SYS2_MUX_inst_adr                                                  "0x0000"
#define DC2_SYS_DC_SYS2_MUX_inst                                                      0x0000
#define DC2_SYS_DC_SYS2_MUX_pre_tra_rd_cnt_shift                                      (20)
#define DC2_SYS_DC_SYS2_MUX_pre_tra_rd_cnt_mask                                       (0x3FF00000)
#define DC2_SYS_DC_SYS2_MUX_pre_tra_rd_cnt(data)                                      (0x3FF00000&((data)<<20))
#define DC2_SYS_DC_SYS2_MUX_pre_tra_rd_cnt_src(data)                                  ((0x3FF00000&(data))>>20)
#define DC2_SYS_DC_SYS2_MUX_get_pre_tra_rd_cnt(data)                                  ((0x3FF00000&(data))>>20)
#define DC2_SYS_DC_SYS2_MUX_pre_tra_wr_cnt_shift                                      (8)
#define DC2_SYS_DC_SYS2_MUX_pre_tra_wr_cnt_mask                                       (0x0003FF00)
#define DC2_SYS_DC_SYS2_MUX_pre_tra_wr_cnt(data)                                      (0x0003FF00&((data)<<8))
#define DC2_SYS_DC_SYS2_MUX_pre_tra_wr_cnt_src(data)                                  ((0x0003FF00&(data))>>8)
#define DC2_SYS_DC_SYS2_MUX_get_pre_tra_wr_cnt(data)                                  ((0x0003FF00&(data))>>8)
#define DC2_SYS_DC_SYS2_MUX_ve2_mux_shift                                             (4)
#define DC2_SYS_DC_SYS2_MUX_ve2_mux_mask                                              (0x00000010)
#define DC2_SYS_DC_SYS2_MUX_ve2_mux(data)                                             (0x00000010&((data)<<4))
#define DC2_SYS_DC_SYS2_MUX_ve2_mux_src(data)                                         ((0x00000010&(data))>>4)
#define DC2_SYS_DC_SYS2_MUX_get_ve2_mux(data)                                         ((0x00000010&(data))>>4)
#define DC2_SYS_DC_SYS2_MUX_ve_mux_shift                                              (3)
#define DC2_SYS_DC_SYS2_MUX_ve_mux_mask                                               (0x00000008)
#define DC2_SYS_DC_SYS2_MUX_ve_mux(data)                                              (0x00000008&((data)<<3))
#define DC2_SYS_DC_SYS2_MUX_ve_mux_src(data)                                          ((0x00000008&(data))>>3)
#define DC2_SYS_DC_SYS2_MUX_get_ve_mux(data)                                          ((0x00000008&(data))>>3)
#define DC2_SYS_DC_SYS2_MUX_memc_mux_shift                                            (2)
#define DC2_SYS_DC_SYS2_MUX_memc_mux_mask                                             (0x00000004)
#define DC2_SYS_DC_SYS2_MUX_memc_mux(data)                                            (0x00000004&((data)<<2))
#define DC2_SYS_DC_SYS2_MUX_memc_mux_src(data)                                        ((0x00000004&(data))>>2)
#define DC2_SYS_DC_SYS2_MUX_get_memc_mux(data)                                        ((0x00000004&(data))>>2)
#define DC2_SYS_DC_SYS2_MUX_tv_sb4_mux_shift                                          (1)
#define DC2_SYS_DC_SYS2_MUX_tv_sb4_mux_mask                                           (0x00000002)
#define DC2_SYS_DC_SYS2_MUX_tv_sb4_mux(data)                                          (0x00000002&((data)<<1))
#define DC2_SYS_DC_SYS2_MUX_tv_sb4_mux_src(data)                                      ((0x00000002&(data))>>1)
#define DC2_SYS_DC_SYS2_MUX_get_tv_sb4_mux(data)                                      ((0x00000002&(data))>>1)
#define DC2_SYS_DC_SYS2_MUX_tv_sb2_mux_shift                                          (0)
#define DC2_SYS_DC_SYS2_MUX_tv_sb2_mux_mask                                           (0x00000001)
#define DC2_SYS_DC_SYS2_MUX_tv_sb2_mux(data)                                          (0x00000001&((data)<<0))
#define DC2_SYS_DC_SYS2_MUX_tv_sb2_mux_src(data)                                      ((0x00000001&(data))>>0)
#define DC2_SYS_DC_SYS2_MUX_get_tv_sb2_mux(data)                                      ((0x00000001&(data))>>0)


#define DC2_SYS_DC_MT_ADDCMD_HI_SYS2_0                                                0x18003410
#define DC2_SYS_DC_MT_ADDCMD_HI_SYS2_1                                                0x18003414
#define DC2_SYS_DC_MT_ADDCMD_HI_SYS2_2                                                0x18003418
#define DC2_SYS_DC_MT_ADDCMD_HI_SYS2_3                                                0x1800341C
#define DC2_SYS_DC_MT_ADDCMD_HI_SYS2_0_reg_addr                                       "0xB8003410"
#define DC2_SYS_DC_MT_ADDCMD_HI_SYS2_1_reg_addr                                       "0xB8003414"
#define DC2_SYS_DC_MT_ADDCMD_HI_SYS2_2_reg_addr                                       "0xB8003418"
#define DC2_SYS_DC_MT_ADDCMD_HI_SYS2_3_reg_addr                                       "0xB800341C"
#define DC2_SYS_DC_MT_ADDCMD_HI_SYS2_0_reg                                            0xB8003410
#define DC2_SYS_DC_MT_ADDCMD_HI_SYS2_1_reg                                            0xB8003414
#define DC2_SYS_DC_MT_ADDCMD_HI_SYS2_2_reg                                            0xB8003418
#define DC2_SYS_DC_MT_ADDCMD_HI_SYS2_3_reg                                            0xB800341C
#define set_DC2_SYS_DC_MT_ADDCMD_HI_SYS2_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_HI_SYS2_0_reg)=data)
#define set_DC2_SYS_DC_MT_ADDCMD_HI_SYS2_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_HI_SYS2_1_reg)=data)
#define set_DC2_SYS_DC_MT_ADDCMD_HI_SYS2_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_HI_SYS2_2_reg)=data)
#define set_DC2_SYS_DC_MT_ADDCMD_HI_SYS2_3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_HI_SYS2_3_reg)=data)
#define get_DC2_SYS_DC_MT_ADDCMD_HI_SYS2_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_HI_SYS2_0_reg))
#define get_DC2_SYS_DC_MT_ADDCMD_HI_SYS2_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_HI_SYS2_1_reg))
#define get_DC2_SYS_DC_MT_ADDCMD_HI_SYS2_2_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_HI_SYS2_2_reg))
#define get_DC2_SYS_DC_MT_ADDCMD_HI_SYS2_3_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_HI_SYS2_3_reg))
#define DC2_SYS_DC_MT_ADDCMD_HI_SYS2_0_inst_adr                                       "0x0004"
#define DC2_SYS_DC_MT_ADDCMD_HI_SYS2_1_inst_adr                                       "0x0005"
#define DC2_SYS_DC_MT_ADDCMD_HI_SYS2_2_inst_adr                                       "0x0006"
#define DC2_SYS_DC_MT_ADDCMD_HI_SYS2_3_inst_adr                                       "0x0007"
#define DC2_SYS_DC_MT_ADDCMD_HI_SYS2_0_inst                                           0x0004
#define DC2_SYS_DC_MT_ADDCMD_HI_SYS2_1_inst                                           0x0005
#define DC2_SYS_DC_MT_ADDCMD_HI_SYS2_2_inst                                           0x0006
#define DC2_SYS_DC_MT_ADDCMD_HI_SYS2_3_inst                                           0x0007
#define DC2_SYS_DC_MT_ADDCMD_HI_SYS2_ever_trap_shift                                  (21)
#define DC2_SYS_DC_MT_ADDCMD_HI_SYS2_ever_trap_mask                                   (0x00200000)
#define DC2_SYS_DC_MT_ADDCMD_HI_SYS2_ever_trap(data)                                  (0x00200000&((data)<<21))
#define DC2_SYS_DC_MT_ADDCMD_HI_SYS2_ever_trap_src(data)                              ((0x00200000&(data))>>21)
#define DC2_SYS_DC_MT_ADDCMD_HI_SYS2_get_ever_trap(data)                              ((0x00200000&(data))>>21)
#define DC2_SYS_DC_MT_ADDCMD_HI_SYS2_module_ID_shift                                  (14)
#define DC2_SYS_DC_MT_ADDCMD_HI_SYS2_module_ID_mask                                   (0x001FC000)
#define DC2_SYS_DC_MT_ADDCMD_HI_SYS2_module_ID(data)                                  (0x001FC000&((data)<<14))
#define DC2_SYS_DC_MT_ADDCMD_HI_SYS2_module_ID_src(data)                              ((0x001FC000&(data))>>14)
#define DC2_SYS_DC_MT_ADDCMD_HI_SYS2_get_module_ID(data)                              ((0x001FC000&(data))>>14)
#define DC2_SYS_DC_MT_ADDCMD_HI_SYS2_addcmd_shift                                     (0)
#define DC2_SYS_DC_MT_ADDCMD_HI_SYS2_addcmd_mask                                      (0x00003FFF)
#define DC2_SYS_DC_MT_ADDCMD_HI_SYS2_addcmd(data)                                     (0x00003FFF&((data)<<0))
#define DC2_SYS_DC_MT_ADDCMD_HI_SYS2_addcmd_src(data)                                 ((0x00003FFF&(data))>>0)
#define DC2_SYS_DC_MT_ADDCMD_HI_SYS2_get_addcmd(data)                                 ((0x00003FFF&(data))>>0)


#define DC2_SYS_DC_MT_ADDCMD_LO_SYS2_0                                                0x18003420
#define DC2_SYS_DC_MT_ADDCMD_LO_SYS2_1                                                0x18003424
#define DC2_SYS_DC_MT_ADDCMD_LO_SYS2_2                                                0x18003428
#define DC2_SYS_DC_MT_ADDCMD_LO_SYS2_3                                                0x1800342C
#define DC2_SYS_DC_MT_ADDCMD_LO_SYS2_0_reg_addr                                       "0xB8003420"
#define DC2_SYS_DC_MT_ADDCMD_LO_SYS2_1_reg_addr                                       "0xB8003424"
#define DC2_SYS_DC_MT_ADDCMD_LO_SYS2_2_reg_addr                                       "0xB8003428"
#define DC2_SYS_DC_MT_ADDCMD_LO_SYS2_3_reg_addr                                       "0xB800342C"
#define DC2_SYS_DC_MT_ADDCMD_LO_SYS2_0_reg                                            0xB8003420
#define DC2_SYS_DC_MT_ADDCMD_LO_SYS2_1_reg                                            0xB8003424
#define DC2_SYS_DC_MT_ADDCMD_LO_SYS2_2_reg                                            0xB8003428
#define DC2_SYS_DC_MT_ADDCMD_LO_SYS2_3_reg                                            0xB800342C
#define set_DC2_SYS_DC_MT_ADDCMD_LO_SYS2_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_LO_SYS2_0_reg)=data)
#define set_DC2_SYS_DC_MT_ADDCMD_LO_SYS2_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_LO_SYS2_1_reg)=data)
#define set_DC2_SYS_DC_MT_ADDCMD_LO_SYS2_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_LO_SYS2_2_reg)=data)
#define set_DC2_SYS_DC_MT_ADDCMD_LO_SYS2_3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_LO_SYS2_3_reg)=data)
#define get_DC2_SYS_DC_MT_ADDCMD_LO_SYS2_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_LO_SYS2_0_reg))
#define get_DC2_SYS_DC_MT_ADDCMD_LO_SYS2_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_LO_SYS2_1_reg))
#define get_DC2_SYS_DC_MT_ADDCMD_LO_SYS2_2_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_LO_SYS2_2_reg))
#define get_DC2_SYS_DC_MT_ADDCMD_LO_SYS2_3_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_LO_SYS2_3_reg))
#define DC2_SYS_DC_MT_ADDCMD_LO_SYS2_0_inst_adr                                       "0x0008"
#define DC2_SYS_DC_MT_ADDCMD_LO_SYS2_1_inst_adr                                       "0x0009"
#define DC2_SYS_DC_MT_ADDCMD_LO_SYS2_2_inst_adr                                       "0x000A"
#define DC2_SYS_DC_MT_ADDCMD_LO_SYS2_3_inst_adr                                       "0x000B"
#define DC2_SYS_DC_MT_ADDCMD_LO_SYS2_0_inst                                           0x0008
#define DC2_SYS_DC_MT_ADDCMD_LO_SYS2_1_inst                                           0x0009
#define DC2_SYS_DC_MT_ADDCMD_LO_SYS2_2_inst                                           0x000A
#define DC2_SYS_DC_MT_ADDCMD_LO_SYS2_3_inst                                           0x000B
#define DC2_SYS_DC_MT_ADDCMD_LO_SYS2_addcmd_shift                                     (0)
#define DC2_SYS_DC_MT_ADDCMD_LO_SYS2_addcmd_mask                                      (0xFFFFFFFF)
#define DC2_SYS_DC_MT_ADDCMD_LO_SYS2_addcmd(data)                                     (0xFFFFFFFF&((data)<<0))
#define DC2_SYS_DC_MT_ADDCMD_LO_SYS2_addcmd_src(data)                                 ((0xFFFFFFFF&(data))>>0)
#define DC2_SYS_DC_MT_ADDCMD_LO_SYS2_get_addcmd(data)                                 ((0xFFFFFFFF&(data))>>0)


#define DC2_SYS_DC_MT_ADDCMD_SA_SYS2_0                                                0x18003430
#define DC2_SYS_DC_MT_ADDCMD_SA_SYS2_1                                                0x18003434
#define DC2_SYS_DC_MT_ADDCMD_SA_SYS2_2                                                0x18003438
#define DC2_SYS_DC_MT_ADDCMD_SA_SYS2_3                                                0x1800343C
#define DC2_SYS_DC_MT_ADDCMD_SA_SYS2_0_reg_addr                                       "0xB8003430"
#define DC2_SYS_DC_MT_ADDCMD_SA_SYS2_1_reg_addr                                       "0xB8003434"
#define DC2_SYS_DC_MT_ADDCMD_SA_SYS2_2_reg_addr                                       "0xB8003438"
#define DC2_SYS_DC_MT_ADDCMD_SA_SYS2_3_reg_addr                                       "0xB800343C"
#define DC2_SYS_DC_MT_ADDCMD_SA_SYS2_0_reg                                            0xB8003430
#define DC2_SYS_DC_MT_ADDCMD_SA_SYS2_1_reg                                            0xB8003434
#define DC2_SYS_DC_MT_ADDCMD_SA_SYS2_2_reg                                            0xB8003438
#define DC2_SYS_DC_MT_ADDCMD_SA_SYS2_3_reg                                            0xB800343C
#define set_DC2_SYS_DC_MT_ADDCMD_SA_SYS2_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_SA_SYS2_0_reg)=data)
#define set_DC2_SYS_DC_MT_ADDCMD_SA_SYS2_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_SA_SYS2_1_reg)=data)
#define set_DC2_SYS_DC_MT_ADDCMD_SA_SYS2_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_SA_SYS2_2_reg)=data)
#define set_DC2_SYS_DC_MT_ADDCMD_SA_SYS2_3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_SA_SYS2_3_reg)=data)
#define get_DC2_SYS_DC_MT_ADDCMD_SA_SYS2_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_SA_SYS2_0_reg))
#define get_DC2_SYS_DC_MT_ADDCMD_SA_SYS2_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_SA_SYS2_1_reg))
#define get_DC2_SYS_DC_MT_ADDCMD_SA_SYS2_2_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_SA_SYS2_2_reg))
#define get_DC2_SYS_DC_MT_ADDCMD_SA_SYS2_3_reg   (*((volatile unsigned int*) DC2_SYS_DC_MT_ADDCMD_SA_SYS2_3_reg))
#define DC2_SYS_DC_MT_ADDCMD_SA_SYS2_0_inst_adr                                       "0x000C"
#define DC2_SYS_DC_MT_ADDCMD_SA_SYS2_1_inst_adr                                       "0x000D"
#define DC2_SYS_DC_MT_ADDCMD_SA_SYS2_2_inst_adr                                       "0x000E"
#define DC2_SYS_DC_MT_ADDCMD_SA_SYS2_3_inst_adr                                       "0x000F"
#define DC2_SYS_DC_MT_ADDCMD_SA_SYS2_0_inst                                           0x000C
#define DC2_SYS_DC_MT_ADDCMD_SA_SYS2_1_inst                                           0x000D
#define DC2_SYS_DC_MT_ADDCMD_SA_SYS2_2_inst                                           0x000E
#define DC2_SYS_DC_MT_ADDCMD_SA_SYS2_3_inst                                           0x000F
#define DC2_SYS_DC_MT_ADDCMD_SA_SYS2_trap_seq_sa_shift                                (0)
#define DC2_SYS_DC_MT_ADDCMD_SA_SYS2_trap_seq_sa_mask                                 (0xFFFFFFFF)
#define DC2_SYS_DC_MT_ADDCMD_SA_SYS2_trap_seq_sa(data)                                (0xFFFFFFFF&((data)<<0))
#define DC2_SYS_DC_MT_ADDCMD_SA_SYS2_trap_seq_sa_src(data)                            ((0xFFFFFFFF&(data))>>0)
#define DC2_SYS_DC_MT_ADDCMD_SA_SYS2_get_trap_seq_sa(data)                            ((0xFFFFFFFF&(data))>>0)


#define DC2_SYS_DC_EC_ADDCMD_HI_SYS2                                                  0x18003440
#define DC2_SYS_DC_EC_ADDCMD_HI_SYS2_reg_addr                                         "0xB8003440"
#define DC2_SYS_DC_EC_ADDCMD_HI_SYS2_reg                                              0xB8003440
#define set_DC2_SYS_DC_EC_ADDCMD_HI_SYS2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_EC_ADDCMD_HI_SYS2_reg)=data)
#define get_DC2_SYS_DC_EC_ADDCMD_HI_SYS2_reg   (*((volatile unsigned int*) DC2_SYS_DC_EC_ADDCMD_HI_SYS2_reg))
#define DC2_SYS_DC_EC_ADDCMD_HI_SYS2_inst_adr                                         "0x0010"
#define DC2_SYS_DC_EC_ADDCMD_HI_SYS2_inst                                             0x0010
#define DC2_SYS_DC_EC_ADDCMD_HI_SYS2_error_cmd_ever_trap_shift                        (30)
#define DC2_SYS_DC_EC_ADDCMD_HI_SYS2_error_cmd_ever_trap_mask                         (0x40000000)
#define DC2_SYS_DC_EC_ADDCMD_HI_SYS2_error_cmd_ever_trap(data)                        (0x40000000&((data)<<30))
#define DC2_SYS_DC_EC_ADDCMD_HI_SYS2_error_cmd_ever_trap_src(data)                    ((0x40000000&(data))>>30)
#define DC2_SYS_DC_EC_ADDCMD_HI_SYS2_get_error_cmd_ever_trap(data)                    ((0x40000000&(data))>>30)
#define DC2_SYS_DC_EC_ADDCMD_HI_SYS2_trap_case_shift                                  (22)
#define DC2_SYS_DC_EC_ADDCMD_HI_SYS2_trap_case_mask                                   (0x3FC00000)
#define DC2_SYS_DC_EC_ADDCMD_HI_SYS2_trap_case(data)                                  (0x3FC00000&((data)<<22))
#define DC2_SYS_DC_EC_ADDCMD_HI_SYS2_trap_case_src(data)                              ((0x3FC00000&(data))>>22)
#define DC2_SYS_DC_EC_ADDCMD_HI_SYS2_get_trap_case(data)                              ((0x3FC00000&(data))>>22)
#define DC2_SYS_DC_EC_ADDCMD_HI_SYS2_Addcmd_hi_shift                                  (0)
#define DC2_SYS_DC_EC_ADDCMD_HI_SYS2_Addcmd_hi_mask                                   (0x003FFFFF)
#define DC2_SYS_DC_EC_ADDCMD_HI_SYS2_Addcmd_hi(data)                                  (0x003FFFFF&((data)<<0))
#define DC2_SYS_DC_EC_ADDCMD_HI_SYS2_Addcmd_hi_src(data)                              ((0x003FFFFF&(data))>>0)
#define DC2_SYS_DC_EC_ADDCMD_HI_SYS2_get_Addcmd_hi(data)                              ((0x003FFFFF&(data))>>0)


#define DC2_SYS_DC_EC_ADDCMD_LO_SYS2                                                  0x18003444
#define DC2_SYS_DC_EC_ADDCMD_LO_SYS2_reg_addr                                         "0xB8003444"
#define DC2_SYS_DC_EC_ADDCMD_LO_SYS2_reg                                              0xB8003444
#define set_DC2_SYS_DC_EC_ADDCMD_LO_SYS2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_EC_ADDCMD_LO_SYS2_reg)=data)
#define get_DC2_SYS_DC_EC_ADDCMD_LO_SYS2_reg   (*((volatile unsigned int*) DC2_SYS_DC_EC_ADDCMD_LO_SYS2_reg))
#define DC2_SYS_DC_EC_ADDCMD_LO_SYS2_inst_adr                                         "0x0011"
#define DC2_SYS_DC_EC_ADDCMD_LO_SYS2_inst                                             0x0011
#define DC2_SYS_DC_EC_ADDCMD_LO_SYS2_Addcmd_lo_shift                                  (0)
#define DC2_SYS_DC_EC_ADDCMD_LO_SYS2_Addcmd_lo_mask                                   (0xFFFFFFFF)
#define DC2_SYS_DC_EC_ADDCMD_LO_SYS2_Addcmd_lo(data)                                  (0xFFFFFFFF&((data)<<0))
#define DC2_SYS_DC_EC_ADDCMD_LO_SYS2_Addcmd_lo_src(data)                              ((0xFFFFFFFF&(data))>>0)
#define DC2_SYS_DC_EC_ADDCMD_LO_SYS2_get_Addcmd_lo(data)                              ((0xFFFFFFFF&(data))>>0)


#define DC2_SYS_DC_INT_ENABLE_SYS2                                                    0x1800344C
#define DC2_SYS_DC_INT_ENABLE_SYS2_reg_addr                                           "0xB800344C"
#define DC2_SYS_DC_INT_ENABLE_SYS2_reg                                                0xB800344C
#define set_DC2_SYS_DC_INT_ENABLE_SYS2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_INT_ENABLE_SYS2_reg)=data)
#define get_DC2_SYS_DC_INT_ENABLE_SYS2_reg   (*((volatile unsigned int*) DC2_SYS_DC_INT_ENABLE_SYS2_reg))
#define DC2_SYS_DC_INT_ENABLE_SYS2_inst_adr                                           "0x0013"
#define DC2_SYS_DC_INT_ENABLE_SYS2_inst                                               0x0013
#define DC2_SYS_DC_INT_ENABLE_SYS2_rd_tag_mismatch_int_en_shift                       (23)
#define DC2_SYS_DC_INT_ENABLE_SYS2_rd_tag_mismatch_int_en_mask                        (0x00800000)
#define DC2_SYS_DC_INT_ENABLE_SYS2_rd_tag_mismatch_int_en(data)                       (0x00800000&((data)<<23))
#define DC2_SYS_DC_INT_ENABLE_SYS2_rd_tag_mismatch_int_en_src(data)                   ((0x00800000&(data))>>23)
#define DC2_SYS_DC_INT_ENABLE_SYS2_get_rd_tag_mismatch_int_en(data)                   ((0x00800000&(data))>>23)
#define DC2_SYS_DC_INT_ENABLE_SYS2_err_seq_sa_odd_int_en_shift                        (22)
#define DC2_SYS_DC_INT_ENABLE_SYS2_err_seq_sa_odd_int_en_mask                         (0x00400000)
#define DC2_SYS_DC_INT_ENABLE_SYS2_err_seq_sa_odd_int_en(data)                        (0x00400000&((data)<<22))
#define DC2_SYS_DC_INT_ENABLE_SYS2_err_seq_sa_odd_int_en_src(data)                    ((0x00400000&(data))>>22)
#define DC2_SYS_DC_INT_ENABLE_SYS2_get_err_seq_sa_odd_int_en(data)                    ((0x00400000&(data))>>22)
#define DC2_SYS_DC_INT_ENABLE_SYS2_err_seq_bl_zero_int_en_shift                       (21)
#define DC2_SYS_DC_INT_ENABLE_SYS2_err_seq_bl_zero_int_en_mask                        (0x00200000)
#define DC2_SYS_DC_INT_ENABLE_SYS2_err_seq_bl_zero_int_en(data)                       (0x00200000&((data)<<21))
#define DC2_SYS_DC_INT_ENABLE_SYS2_err_seq_bl_zero_int_en_src(data)                   ((0x00200000&(data))>>21)
#define DC2_SYS_DC_INT_ENABLE_SYS2_get_err_seq_bl_zero_int_en(data)                   ((0x00200000&(data))>>21)
#define DC2_SYS_DC_INT_ENABLE_SYS2_err_seq_bl_odd_int_en_shift                        (20)
#define DC2_SYS_DC_INT_ENABLE_SYS2_err_seq_bl_odd_int_en_mask                         (0x00100000)
#define DC2_SYS_DC_INT_ENABLE_SYS2_err_seq_bl_odd_int_en(data)                        (0x00100000&((data)<<20))
#define DC2_SYS_DC_INT_ENABLE_SYS2_err_seq_bl_odd_int_en_src(data)                    ((0x00100000&(data))>>20)
#define DC2_SYS_DC_INT_ENABLE_SYS2_get_err_seq_bl_odd_int_en(data)                    ((0x00100000&(data))>>20)
#define DC2_SYS_DC_INT_ENABLE_SYS2_err_blk_8x2_on_64_int_en_shift                     (19)
#define DC2_SYS_DC_INT_ENABLE_SYS2_err_blk_8x2_on_64_int_en_mask                      (0x00080000)
#define DC2_SYS_DC_INT_ENABLE_SYS2_err_blk_8x2_on_64_int_en(data)                     (0x00080000&((data)<<19))
#define DC2_SYS_DC_INT_ENABLE_SYS2_err_blk_8x2_on_64_int_en_src(data)                 ((0x00080000&(data))>>19)
#define DC2_SYS_DC_INT_ENABLE_SYS2_get_err_blk_8x2_on_64_int_en(data)                 ((0x00080000&(data))>>19)
#define DC2_SYS_DC_INT_ENABLE_SYS2_err_blk_size_exceed_int_en_shift                   (18)
#define DC2_SYS_DC_INT_ENABLE_SYS2_err_blk_size_exceed_int_en_mask                    (0x00040000)
#define DC2_SYS_DC_INT_ENABLE_SYS2_err_blk_size_exceed_int_en(data)                   (0x00040000&((data)<<18))
#define DC2_SYS_DC_INT_ENABLE_SYS2_err_blk_size_exceed_int_en_src(data)               ((0x00040000&(data))>>18)
#define DC2_SYS_DC_INT_ENABLE_SYS2_get_err_blk_size_exceed_int_en(data)               ((0x00040000&(data))>>18)
#define DC2_SYS_DC_INT_ENABLE_SYS2_err_blk_h_zero_int_en_shift                        (17)
#define DC2_SYS_DC_INT_ENABLE_SYS2_err_blk_h_zero_int_en_mask                         (0x00020000)
#define DC2_SYS_DC_INT_ENABLE_SYS2_err_blk_h_zero_int_en(data)                        (0x00020000&((data)<<17))
#define DC2_SYS_DC_INT_ENABLE_SYS2_err_blk_h_zero_int_en_src(data)                    ((0x00020000&(data))>>17)
#define DC2_SYS_DC_INT_ENABLE_SYS2_get_err_blk_h_zero_int_en(data)                    ((0x00020000&(data))>>17)
#define DC2_SYS_DC_INT_ENABLE_SYS2_err_blk_w_zero_int_en_shift                        (16)
#define DC2_SYS_DC_INT_ENABLE_SYS2_err_blk_w_zero_int_en_mask                         (0x00010000)
#define DC2_SYS_DC_INT_ENABLE_SYS2_err_blk_w_zero_int_en(data)                        (0x00010000&((data)<<16))
#define DC2_SYS_DC_INT_ENABLE_SYS2_err_blk_w_zero_int_en_src(data)                    ((0x00010000&(data))>>16)
#define DC2_SYS_DC_INT_ENABLE_SYS2_get_err_blk_w_zero_int_en(data)                    ((0x00010000&(data))>>16)
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_3_mod3_int_en_shift                             (12)
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_3_mod3_int_en_mask                              (0x00001000)
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_3_mod3_int_en(data)                             (0x00001000&((data)<<12))
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_3_mod3_int_en_src(data)                         ((0x00001000&(data))>>12)
#define DC2_SYS_DC_INT_ENABLE_SYS2_get_mt_3_mod3_int_en(data)                         ((0x00001000&(data))>>12)
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_3_mod2_int_en_shift                             (11)
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_3_mod2_int_en_mask                              (0x00000800)
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_3_mod2_int_en(data)                             (0x00000800&((data)<<11))
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_3_mod2_int_en_src(data)                         ((0x00000800&(data))>>11)
#define DC2_SYS_DC_INT_ENABLE_SYS2_get_mt_3_mod2_int_en(data)                         ((0x00000800&(data))>>11)
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_3_mod1_int_en_shift                             (10)
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_3_mod1_int_en_mask                              (0x00000400)
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_3_mod1_int_en(data)                             (0x00000400&((data)<<10))
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_3_mod1_int_en_src(data)                         ((0x00000400&(data))>>10)
#define DC2_SYS_DC_INT_ENABLE_SYS2_get_mt_3_mod1_int_en(data)                         ((0x00000400&(data))>>10)
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_2_mod3_int_en_shift                             (9)
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_2_mod3_int_en_mask                              (0x00000200)
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_2_mod3_int_en(data)                             (0x00000200&((data)<<9))
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_2_mod3_int_en_src(data)                         ((0x00000200&(data))>>9)
#define DC2_SYS_DC_INT_ENABLE_SYS2_get_mt_2_mod3_int_en(data)                         ((0x00000200&(data))>>9)
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_2_mod2_int_en_shift                             (8)
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_2_mod2_int_en_mask                              (0x00000100)
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_2_mod2_int_en(data)                             (0x00000100&((data)<<8))
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_2_mod2_int_en_src(data)                         ((0x00000100&(data))>>8)
#define DC2_SYS_DC_INT_ENABLE_SYS2_get_mt_2_mod2_int_en(data)                         ((0x00000100&(data))>>8)
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_2_mod1_int_en_shift                             (7)
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_2_mod1_int_en_mask                              (0x00000080)
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_2_mod1_int_en(data)                             (0x00000080&((data)<<7))
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_2_mod1_int_en_src(data)                         ((0x00000080&(data))>>7)
#define DC2_SYS_DC_INT_ENABLE_SYS2_get_mt_2_mod1_int_en(data)                         ((0x00000080&(data))>>7)
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_1_mod3_int_en_shift                             (6)
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_1_mod3_int_en_mask                              (0x00000040)
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_1_mod3_int_en(data)                             (0x00000040&((data)<<6))
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_1_mod3_int_en_src(data)                         ((0x00000040&(data))>>6)
#define DC2_SYS_DC_INT_ENABLE_SYS2_get_mt_1_mod3_int_en(data)                         ((0x00000040&(data))>>6)
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_1_mod2_int_en_shift                             (5)
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_1_mod2_int_en_mask                              (0x00000020)
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_1_mod2_int_en(data)                             (0x00000020&((data)<<5))
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_1_mod2_int_en_src(data)                         ((0x00000020&(data))>>5)
#define DC2_SYS_DC_INT_ENABLE_SYS2_get_mt_1_mod2_int_en(data)                         ((0x00000020&(data))>>5)
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_1_mod1_int_en_shift                             (4)
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_1_mod1_int_en_mask                              (0x00000010)
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_1_mod1_int_en(data)                             (0x00000010&((data)<<4))
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_1_mod1_int_en_src(data)                         ((0x00000010&(data))>>4)
#define DC2_SYS_DC_INT_ENABLE_SYS2_get_mt_1_mod1_int_en(data)                         ((0x00000010&(data))>>4)
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_0_mod3_int_en_shift                             (3)
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_0_mod3_int_en_mask                              (0x00000008)
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_0_mod3_int_en(data)                             (0x00000008&((data)<<3))
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_0_mod3_int_en_src(data)                         ((0x00000008&(data))>>3)
#define DC2_SYS_DC_INT_ENABLE_SYS2_get_mt_0_mod3_int_en(data)                         ((0x00000008&(data))>>3)
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_0_mod2_int_en_shift                             (2)
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_0_mod2_int_en_mask                              (0x00000004)
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_0_mod2_int_en(data)                             (0x00000004&((data)<<2))
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_0_mod2_int_en_src(data)                         ((0x00000004&(data))>>2)
#define DC2_SYS_DC_INT_ENABLE_SYS2_get_mt_0_mod2_int_en(data)                         ((0x00000004&(data))>>2)
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_0_mod1_int_en_shift                             (1)
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_0_mod1_int_en_mask                              (0x00000002)
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_0_mod1_int_en(data)                             (0x00000002&((data)<<1))
#define DC2_SYS_DC_INT_ENABLE_SYS2_mt_0_mod1_int_en_src(data)                         ((0x00000002&(data))>>1)
#define DC2_SYS_DC_INT_ENABLE_SYS2_get_mt_0_mod1_int_en(data)                         ((0x00000002&(data))>>1)
#define DC2_SYS_DC_INT_ENABLE_SYS2_write_data_shift                                   (0)
#define DC2_SYS_DC_INT_ENABLE_SYS2_write_data_mask                                    (0x00000001)
#define DC2_SYS_DC_INT_ENABLE_SYS2_write_data(data)                                   (0x00000001&((data)<<0))
#define DC2_SYS_DC_INT_ENABLE_SYS2_write_data_src(data)                               ((0x00000001&(data))>>0)
#define DC2_SYS_DC_INT_ENABLE_SYS2_get_write_data(data)                               ((0x00000001&(data))>>0)


#define DC2_SYS_DC_INT_STATUS_SYS2                                                    0x18003450
#define DC2_SYS_DC_INT_STATUS_SYS2_reg_addr                                           "0xB8003450"
#define DC2_SYS_DC_INT_STATUS_SYS2_reg                                                0xB8003450
#define set_DC2_SYS_DC_INT_STATUS_SYS2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_INT_STATUS_SYS2_reg)=data)
#define get_DC2_SYS_DC_INT_STATUS_SYS2_reg   (*((volatile unsigned int*) DC2_SYS_DC_INT_STATUS_SYS2_reg))
#define DC2_SYS_DC_INT_STATUS_SYS2_inst_adr                                           "0x0014"
#define DC2_SYS_DC_INT_STATUS_SYS2_inst                                               0x0014
#define DC2_SYS_DC_INT_STATUS_SYS2_rd_tag_mismatch_int_shift                          (23)
#define DC2_SYS_DC_INT_STATUS_SYS2_rd_tag_mismatch_int_mask                           (0x00800000)
#define DC2_SYS_DC_INT_STATUS_SYS2_rd_tag_mismatch_int(data)                          (0x00800000&((data)<<23))
#define DC2_SYS_DC_INT_STATUS_SYS2_rd_tag_mismatch_int_src(data)                      ((0x00800000&(data))>>23)
#define DC2_SYS_DC_INT_STATUS_SYS2_get_rd_tag_mismatch_int(data)                      ((0x00800000&(data))>>23)
#define DC2_SYS_DC_INT_STATUS_SYS2_err_seq_sa_odd_int_shift                           (22)
#define DC2_SYS_DC_INT_STATUS_SYS2_err_seq_sa_odd_int_mask                            (0x00400000)
#define DC2_SYS_DC_INT_STATUS_SYS2_err_seq_sa_odd_int(data)                           (0x00400000&((data)<<22))
#define DC2_SYS_DC_INT_STATUS_SYS2_err_seq_sa_odd_int_src(data)                       ((0x00400000&(data))>>22)
#define DC2_SYS_DC_INT_STATUS_SYS2_get_err_seq_sa_odd_int(data)                       ((0x00400000&(data))>>22)
#define DC2_SYS_DC_INT_STATUS_SYS2_err_seq_bl_zero_int_shift                          (21)
#define DC2_SYS_DC_INT_STATUS_SYS2_err_seq_bl_zero_int_mask                           (0x00200000)
#define DC2_SYS_DC_INT_STATUS_SYS2_err_seq_bl_zero_int(data)                          (0x00200000&((data)<<21))
#define DC2_SYS_DC_INT_STATUS_SYS2_err_seq_bl_zero_int_src(data)                      ((0x00200000&(data))>>21)
#define DC2_SYS_DC_INT_STATUS_SYS2_get_err_seq_bl_zero_int(data)                      ((0x00200000&(data))>>21)
#define DC2_SYS_DC_INT_STATUS_SYS2_err_seq_bl_odd_int_shift                           (20)
#define DC2_SYS_DC_INT_STATUS_SYS2_err_seq_bl_odd_int_mask                            (0x00100000)
#define DC2_SYS_DC_INT_STATUS_SYS2_err_seq_bl_odd_int(data)                           (0x00100000&((data)<<20))
#define DC2_SYS_DC_INT_STATUS_SYS2_err_seq_bl_odd_int_src(data)                       ((0x00100000&(data))>>20)
#define DC2_SYS_DC_INT_STATUS_SYS2_get_err_seq_bl_odd_int(data)                       ((0x00100000&(data))>>20)
#define DC2_SYS_DC_INT_STATUS_SYS2_err_blk_8x2_on_64_int_shift                        (19)
#define DC2_SYS_DC_INT_STATUS_SYS2_err_blk_8x2_on_64_int_mask                         (0x00080000)
#define DC2_SYS_DC_INT_STATUS_SYS2_err_blk_8x2_on_64_int(data)                        (0x00080000&((data)<<19))
#define DC2_SYS_DC_INT_STATUS_SYS2_err_blk_8x2_on_64_int_src(data)                    ((0x00080000&(data))>>19)
#define DC2_SYS_DC_INT_STATUS_SYS2_get_err_blk_8x2_on_64_int(data)                    ((0x00080000&(data))>>19)
#define DC2_SYS_DC_INT_STATUS_SYS2_err_blk_size_exceed_int_shift                      (18)
#define DC2_SYS_DC_INT_STATUS_SYS2_err_blk_size_exceed_int_mask                       (0x00040000)
#define DC2_SYS_DC_INT_STATUS_SYS2_err_blk_size_exceed_int(data)                      (0x00040000&((data)<<18))
#define DC2_SYS_DC_INT_STATUS_SYS2_err_blk_size_exceed_int_src(data)                  ((0x00040000&(data))>>18)
#define DC2_SYS_DC_INT_STATUS_SYS2_get_err_blk_size_exceed_int(data)                  ((0x00040000&(data))>>18)
#define DC2_SYS_DC_INT_STATUS_SYS2_err_blk_h_zero_int_shift                           (17)
#define DC2_SYS_DC_INT_STATUS_SYS2_err_blk_h_zero_int_mask                            (0x00020000)
#define DC2_SYS_DC_INT_STATUS_SYS2_err_blk_h_zero_int(data)                           (0x00020000&((data)<<17))
#define DC2_SYS_DC_INT_STATUS_SYS2_err_blk_h_zero_int_src(data)                       ((0x00020000&(data))>>17)
#define DC2_SYS_DC_INT_STATUS_SYS2_get_err_blk_h_zero_int(data)                       ((0x00020000&(data))>>17)
#define DC2_SYS_DC_INT_STATUS_SYS2_err_blk_w_zero_int_shift                           (16)
#define DC2_SYS_DC_INT_STATUS_SYS2_err_blk_w_zero_int_mask                            (0x00010000)
#define DC2_SYS_DC_INT_STATUS_SYS2_err_blk_w_zero_int(data)                           (0x00010000&((data)<<16))
#define DC2_SYS_DC_INT_STATUS_SYS2_err_blk_w_zero_int_src(data)                       ((0x00010000&(data))>>16)
#define DC2_SYS_DC_INT_STATUS_SYS2_get_err_blk_w_zero_int(data)                       ((0x00010000&(data))>>16)
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_3_mod3_int_shift                                (12)
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_3_mod3_int_mask                                 (0x00001000)
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_3_mod3_int(data)                                (0x00001000&((data)<<12))
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_3_mod3_int_src(data)                            ((0x00001000&(data))>>12)
#define DC2_SYS_DC_INT_STATUS_SYS2_get_mt_3_mod3_int(data)                            ((0x00001000&(data))>>12)
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_3_mod2_int_shift                                (11)
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_3_mod2_int_mask                                 (0x00000800)
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_3_mod2_int(data)                                (0x00000800&((data)<<11))
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_3_mod2_int_src(data)                            ((0x00000800&(data))>>11)
#define DC2_SYS_DC_INT_STATUS_SYS2_get_mt_3_mod2_int(data)                            ((0x00000800&(data))>>11)
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_3_mod1_int_shift                                (10)
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_3_mod1_int_mask                                 (0x00000400)
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_3_mod1_int(data)                                (0x00000400&((data)<<10))
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_3_mod1_int_src(data)                            ((0x00000400&(data))>>10)
#define DC2_SYS_DC_INT_STATUS_SYS2_get_mt_3_mod1_int(data)                            ((0x00000400&(data))>>10)
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_2_mod3_int_shift                                (9)
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_2_mod3_int_mask                                 (0x00000200)
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_2_mod3_int(data)                                (0x00000200&((data)<<9))
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_2_mod3_int_src(data)                            ((0x00000200&(data))>>9)
#define DC2_SYS_DC_INT_STATUS_SYS2_get_mt_2_mod3_int(data)                            ((0x00000200&(data))>>9)
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_2_mod2_int_shift                                (8)
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_2_mod2_int_mask                                 (0x00000100)
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_2_mod2_int(data)                                (0x00000100&((data)<<8))
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_2_mod2_int_src(data)                            ((0x00000100&(data))>>8)
#define DC2_SYS_DC_INT_STATUS_SYS2_get_mt_2_mod2_int(data)                            ((0x00000100&(data))>>8)
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_2_mod1_int_shift                                (7)
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_2_mod1_int_mask                                 (0x00000080)
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_2_mod1_int(data)                                (0x00000080&((data)<<7))
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_2_mod1_int_src(data)                            ((0x00000080&(data))>>7)
#define DC2_SYS_DC_INT_STATUS_SYS2_get_mt_2_mod1_int(data)                            ((0x00000080&(data))>>7)
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_1_mod3_int_shift                                (6)
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_1_mod3_int_mask                                 (0x00000040)
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_1_mod3_int(data)                                (0x00000040&((data)<<6))
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_1_mod3_int_src(data)                            ((0x00000040&(data))>>6)
#define DC2_SYS_DC_INT_STATUS_SYS2_get_mt_1_mod3_int(data)                            ((0x00000040&(data))>>6)
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_1_mod2_int_shift                                (5)
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_1_mod2_int_mask                                 (0x00000020)
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_1_mod2_int(data)                                (0x00000020&((data)<<5))
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_1_mod2_int_src(data)                            ((0x00000020&(data))>>5)
#define DC2_SYS_DC_INT_STATUS_SYS2_get_mt_1_mod2_int(data)                            ((0x00000020&(data))>>5)
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_1_mod1_int_shift                                (4)
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_1_mod1_int_mask                                 (0x00000010)
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_1_mod1_int(data)                                (0x00000010&((data)<<4))
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_1_mod1_int_src(data)                            ((0x00000010&(data))>>4)
#define DC2_SYS_DC_INT_STATUS_SYS2_get_mt_1_mod1_int(data)                            ((0x00000010&(data))>>4)
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_0_mod3_int_shift                                (3)
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_0_mod3_int_mask                                 (0x00000008)
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_0_mod3_int(data)                                (0x00000008&((data)<<3))
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_0_mod3_int_src(data)                            ((0x00000008&(data))>>3)
#define DC2_SYS_DC_INT_STATUS_SYS2_get_mt_0_mod3_int(data)                            ((0x00000008&(data))>>3)
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_0_mod2_int_shift                                (2)
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_0_mod2_int_mask                                 (0x00000004)
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_0_mod2_int(data)                                (0x00000004&((data)<<2))
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_0_mod2_int_src(data)                            ((0x00000004&(data))>>2)
#define DC2_SYS_DC_INT_STATUS_SYS2_get_mt_0_mod2_int(data)                            ((0x00000004&(data))>>2)
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_0_mod1_int_shift                                (1)
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_0_mod1_int_mask                                 (0x00000002)
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_0_mod1_int(data)                                (0x00000002&((data)<<1))
#define DC2_SYS_DC_INT_STATUS_SYS2_mt_0_mod1_int_src(data)                            ((0x00000002&(data))>>1)
#define DC2_SYS_DC_INT_STATUS_SYS2_get_mt_0_mod1_int(data)                            ((0x00000002&(data))>>1)
#define DC2_SYS_DC_INT_STATUS_SYS2_write_data_shift                                   (0)
#define DC2_SYS_DC_INT_STATUS_SYS2_write_data_mask                                    (0x00000001)
#define DC2_SYS_DC_INT_STATUS_SYS2_write_data(data)                                   (0x00000001&((data)<<0))
#define DC2_SYS_DC_INT_STATUS_SYS2_write_data_src(data)                               ((0x00000001&(data))>>0)
#define DC2_SYS_DC_INT_STATUS_SYS2_get_write_data(data)                               ((0x00000001&(data))>>0)


#define DC2_SYS_DC_64_CMD_CTRL                                                        0x18003008
#define DC2_SYS_DC_64_CMD_CTRL_reg_addr                                               "0xB8003008"
#define DC2_SYS_DC_64_CMD_CTRL_reg                                                    0xB8003008
#define set_DC2_SYS_DC_64_CMD_CTRL_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_64_CMD_CTRL_reg)=data)
#define get_DC2_SYS_DC_64_CMD_CTRL_reg   (*((volatile unsigned int*) DC2_SYS_DC_64_CMD_CTRL_reg))
#define DC2_SYS_DC_64_CMD_CTRL_inst_adr                                               "0x0002"
#define DC2_SYS_DC_64_CMD_CTRL_inst                                                   0x0002
#define DC2_SYS_DC_64_CMD_CTRL_cmd_inorder_shift                                      (31)
#define DC2_SYS_DC_64_CMD_CTRL_cmd_inorder_mask                                       (0x80000000)
#define DC2_SYS_DC_64_CMD_CTRL_cmd_inorder(data)                                      (0x80000000&((data)<<31))
#define DC2_SYS_DC_64_CMD_CTRL_cmd_inorder_src(data)                                  ((0x80000000&(data))>>31)
#define DC2_SYS_DC_64_CMD_CTRL_get_cmd_inorder(data)                                  ((0x80000000&(data))>>31)
#define DC2_SYS_DC_64_CMD_CTRL_cmd_zero_bl_bypass_shift                               (30)
#define DC2_SYS_DC_64_CMD_CTRL_cmd_zero_bl_bypass_mask                                (0x40000000)
#define DC2_SYS_DC_64_CMD_CTRL_cmd_zero_bl_bypass(data)                               (0x40000000&((data)<<30))
#define DC2_SYS_DC_64_CMD_CTRL_cmd_zero_bl_bypass_src(data)                           ((0x40000000&(data))>>30)
#define DC2_SYS_DC_64_CMD_CTRL_get_cmd_zero_bl_bypass(data)                           ((0x40000000&(data))>>30)
#define DC2_SYS_DC_64_CMD_CTRL_wcmd_fifo_th_shift                                     (16)
#define DC2_SYS_DC_64_CMD_CTRL_wcmd_fifo_th_mask                                      (0x00070000)
#define DC2_SYS_DC_64_CMD_CTRL_wcmd_fifo_th(data)                                     (0x00070000&((data)<<16))
#define DC2_SYS_DC_64_CMD_CTRL_wcmd_fifo_th_src(data)                                 ((0x00070000&(data))>>16)
#define DC2_SYS_DC_64_CMD_CTRL_get_wcmd_fifo_th(data)                                 ((0x00070000&(data))>>16)
#define DC2_SYS_DC_64_CMD_CTRL_rcmd_fifo_th_shift                                     (8)
#define DC2_SYS_DC_64_CMD_CTRL_rcmd_fifo_th_mask                                      (0x00000700)
#define DC2_SYS_DC_64_CMD_CTRL_rcmd_fifo_th(data)                                     (0x00000700&((data)<<8))
#define DC2_SYS_DC_64_CMD_CTRL_rcmd_fifo_th_src(data)                                 ((0x00000700&(data))>>8)
#define DC2_SYS_DC_64_CMD_CTRL_get_rcmd_fifo_th(data)                                 ((0x00000700&(data))>>8)
#define DC2_SYS_DC_64_CMD_CTRL_wait_wdone_th_shift                                    (0)
#define DC2_SYS_DC_64_CMD_CTRL_wait_wdone_th_mask                                     (0x0000001F)
#define DC2_SYS_DC_64_CMD_CTRL_wait_wdone_th(data)                                    (0x0000001F&((data)<<0))
#define DC2_SYS_DC_64_CMD_CTRL_wait_wdone_th_src(data)                                ((0x0000001F&(data))>>0)
#define DC2_SYS_DC_64_CMD_CTRL_get_wait_wdone_th(data)                                ((0x0000001F&(data))>>0)


#define DC2_SYS_DC_64_BUF_CTRL                                                        0x1800300C
#define DC2_SYS_DC_64_BUF_CTRL_reg_addr                                               "0xB800300C"
#define DC2_SYS_DC_64_BUF_CTRL_reg                                                    0xB800300C
#define set_DC2_SYS_DC_64_BUF_CTRL_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_64_BUF_CTRL_reg)=data)
#define get_DC2_SYS_DC_64_BUF_CTRL_reg   (*((volatile unsigned int*) DC2_SYS_DC_64_BUF_CTRL_reg))
#define DC2_SYS_DC_64_BUF_CTRL_inst_adr                                               "0x0003"
#define DC2_SYS_DC_64_BUF_CTRL_inst                                                   0x0003
#define DC2_SYS_DC_64_BUF_CTRL_full_transfer_shift                                    (31)
#define DC2_SYS_DC_64_BUF_CTRL_full_transfer_mask                                     (0x80000000)
#define DC2_SYS_DC_64_BUF_CTRL_full_transfer(data)                                    (0x80000000&((data)<<31))
#define DC2_SYS_DC_64_BUF_CTRL_full_transfer_src(data)                                ((0x80000000&(data))>>31)
#define DC2_SYS_DC_64_BUF_CTRL_get_full_transfer(data)                                ((0x80000000&(data))>>31)
#define DC2_SYS_DC_64_BUF_CTRL_wdata_fifo_th_shift                                    (8)
#define DC2_SYS_DC_64_BUF_CTRL_wdata_fifo_th_mask                                     (0x00003F00)
#define DC2_SYS_DC_64_BUF_CTRL_wdata_fifo_th(data)                                    (0x00003F00&((data)<<8))
#define DC2_SYS_DC_64_BUF_CTRL_wdata_fifo_th_src(data)                                ((0x00003F00&(data))>>8)
#define DC2_SYS_DC_64_BUF_CTRL_get_wdata_fifo_th(data)                                ((0x00003F00&(data))>>8)
#define DC2_SYS_DC_64_BUF_CTRL_rdata_fifo_th_shift                                    (0)
#define DC2_SYS_DC_64_BUF_CTRL_rdata_fifo_th_mask                                     (0x0000003F)
#define DC2_SYS_DC_64_BUF_CTRL_rdata_fifo_th(data)                                    (0x0000003F&((data)<<0))
#define DC2_SYS_DC_64_BUF_CTRL_rdata_fifo_th_src(data)                                ((0x0000003F&(data))>>0)
#define DC2_SYS_DC_64_BUF_CTRL_get_rdata_fifo_th(data)                                ((0x0000003F&(data))>>0)


#define DC2_SYS_DC_64_DUMMY                                                           0x18003014
#define DC2_SYS_DC_64_DUMMY_reg_addr                                                  "0xB8003014"
#define DC2_SYS_DC_64_DUMMY_reg                                                       0xB8003014
#define set_DC2_SYS_DC_64_DUMMY_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_64_DUMMY_reg)=data)
#define get_DC2_SYS_DC_64_DUMMY_reg   (*((volatile unsigned int*) DC2_SYS_DC_64_DUMMY_reg))
#define DC2_SYS_DC_64_DUMMY_inst_adr                                                  "0x0005"
#define DC2_SYS_DC_64_DUMMY_inst                                                      0x0005
#define DC2_SYS_DC_64_DUMMY_dummy_shift                                               (0)
#define DC2_SYS_DC_64_DUMMY_dummy_mask                                                (0xFFFFFFFF)
#define DC2_SYS_DC_64_DUMMY_dummy(data)                                               (0xFFFFFFFF&((data)<<0))
#define DC2_SYS_DC_64_DUMMY_dummy_src(data)                                           ((0xFFFFFFFF&(data))>>0)
#define DC2_SYS_DC_64_DUMMY_get_dummy(data)                                           ((0xFFFFFFFF&(data))>>0)



#define DC2_SYS_DC_64_ERR_STATUS_AIO                                                  0x180030C4
#define DC2_SYS_DC_64_ERR_STATUS_AIO_reg_addr                                         "0xB80030C4"
#define DC2_SYS_DC_64_ERR_STATUS_AIO_reg                                              0xB80030C4
#define set_DC2_SYS_DC_64_ERR_STATUS_AIO_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_64_ERR_STATUS_AIO_reg)=data)
#define get_DC2_SYS_DC_64_ERR_STATUS_AIO_reg   (*((volatile unsigned int*) DC2_SYS_DC_64_ERR_STATUS_AIO_reg))
#define DC2_SYS_DC_64_ERR_STATUS_AIO_inst_adr                                         "0x0031"
#define DC2_SYS_DC_64_ERR_STATUS_AIO_inst                                             0x0031
#define DC2_SYS_DC_64_ERR_STATUS_AIO_dbg_en_shift                                     (31)
#define DC2_SYS_DC_64_ERR_STATUS_AIO_dbg_en_mask                                      (0x80000000)
#define DC2_SYS_DC_64_ERR_STATUS_AIO_dbg_en(data)                                     (0x80000000&((data)<<31))
#define DC2_SYS_DC_64_ERR_STATUS_AIO_dbg_en_src(data)                                 ((0x80000000&(data))>>31)
#define DC2_SYS_DC_64_ERR_STATUS_AIO_get_dbg_en(data)                                 ((0x80000000&(data))>>31)
#define DC2_SYS_DC_64_ERR_STATUS_AIO_err_bl_zero_shift                                (30)
#define DC2_SYS_DC_64_ERR_STATUS_AIO_err_bl_zero_mask                                 (0x40000000)
#define DC2_SYS_DC_64_ERR_STATUS_AIO_err_bl_zero(data)                                (0x40000000&((data)<<30))
#define DC2_SYS_DC_64_ERR_STATUS_AIO_err_bl_zero_src(data)                            ((0x40000000&(data))>>30)
#define DC2_SYS_DC_64_ERR_STATUS_AIO_get_err_bl_zero(data)                            ((0x40000000&(data))>>30)
#define DC2_SYS_DC_64_ERR_STATUS_AIO_err_blk_wxh_odd_shift                            (29)
#define DC2_SYS_DC_64_ERR_STATUS_AIO_err_blk_wxh_odd_mask                             (0x20000000)
#define DC2_SYS_DC_64_ERR_STATUS_AIO_err_blk_wxh_odd(data)                            (0x20000000&((data)<<29))
#define DC2_SYS_DC_64_ERR_STATUS_AIO_err_blk_wxh_odd_src(data)                        ((0x20000000&(data))>>29)
#define DC2_SYS_DC_64_ERR_STATUS_AIO_get_err_blk_wxh_odd(data)                        ((0x20000000&(data))>>29)
#define DC2_SYS_DC_64_ERR_STATUS_AIO_max_wcmd_in_fifo_shift                           (24)
#define DC2_SYS_DC_64_ERR_STATUS_AIO_max_wcmd_in_fifo_mask                            (0x0F000000)
#define DC2_SYS_DC_64_ERR_STATUS_AIO_max_wcmd_in_fifo(data)                           (0x0F000000&((data)<<24))
#define DC2_SYS_DC_64_ERR_STATUS_AIO_max_wcmd_in_fifo_src(data)                       ((0x0F000000&(data))>>24)
#define DC2_SYS_DC_64_ERR_STATUS_AIO_get_max_wcmd_in_fifo(data)                       ((0x0F000000&(data))>>24)
#define DC2_SYS_DC_64_ERR_STATUS_AIO_max_rcmd_in_fifo_shift                           (20)
#define DC2_SYS_DC_64_ERR_STATUS_AIO_max_rcmd_in_fifo_mask                            (0x00F00000)
#define DC2_SYS_DC_64_ERR_STATUS_AIO_max_rcmd_in_fifo(data)                           (0x00F00000&((data)<<20))
#define DC2_SYS_DC_64_ERR_STATUS_AIO_max_rcmd_in_fifo_src(data)                       ((0x00F00000&(data))>>20)
#define DC2_SYS_DC_64_ERR_STATUS_AIO_get_max_rcmd_in_fifo(data)                       ((0x00F00000&(data))>>20)
#define DC2_SYS_DC_64_ERR_STATUS_AIO_max_wait_wdone_shift                             (14)
#define DC2_SYS_DC_64_ERR_STATUS_AIO_max_wait_wdone_mask                              (0x000FC000)
#define DC2_SYS_DC_64_ERR_STATUS_AIO_max_wait_wdone(data)                             (0x000FC000&((data)<<14))
#define DC2_SYS_DC_64_ERR_STATUS_AIO_max_wait_wdone_src(data)                         ((0x000FC000&(data))>>14)
#define DC2_SYS_DC_64_ERR_STATUS_AIO_get_max_wait_wdone(data)                         ((0x000FC000&(data))>>14)
#define DC2_SYS_DC_64_ERR_STATUS_AIO_max_wdata_in_fifo_shift                          (7)
#define DC2_SYS_DC_64_ERR_STATUS_AIO_max_wdata_in_fifo_mask                           (0x00003F80)
#define DC2_SYS_DC_64_ERR_STATUS_AIO_max_wdata_in_fifo(data)                          (0x00003F80&((data)<<7))
#define DC2_SYS_DC_64_ERR_STATUS_AIO_max_wdata_in_fifo_src(data)                      ((0x00003F80&(data))>>7)
#define DC2_SYS_DC_64_ERR_STATUS_AIO_get_max_wdata_in_fifo(data)                      ((0x00003F80&(data))>>7)
#define DC2_SYS_DC_64_ERR_STATUS_AIO_max_rdata_in_fifo_shift                          (0)
#define DC2_SYS_DC_64_ERR_STATUS_AIO_max_rdata_in_fifo_mask                           (0x0000007F)
#define DC2_SYS_DC_64_ERR_STATUS_AIO_max_rdata_in_fifo(data)                          (0x0000007F&((data)<<0))
#define DC2_SYS_DC_64_ERR_STATUS_AIO_max_rdata_in_fifo_src(data)                      ((0x0000007F&(data))>>0)
#define DC2_SYS_DC_64_ERR_STATUS_AIO_get_max_rdata_in_fifo(data)                      ((0x0000007F&(data))>>0)


#define DC2_SYS_DC_64_ERR_STATUS_SB1                                                  0x180030C8
#define DC2_SYS_DC_64_ERR_STATUS_SB1_reg_addr                                         "0xB80030C8"
#define DC2_SYS_DC_64_ERR_STATUS_SB1_reg                                              0xB80030C8
#define set_DC2_SYS_DC_64_ERR_STATUS_SB1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_64_ERR_STATUS_SB1_reg)=data)
#define get_DC2_SYS_DC_64_ERR_STATUS_SB1_reg   (*((volatile unsigned int*) DC2_SYS_DC_64_ERR_STATUS_SB1_reg))
#define DC2_SYS_DC_64_ERR_STATUS_SB1_inst_adr                                         "0x0032"
#define DC2_SYS_DC_64_ERR_STATUS_SB1_inst                                             0x0032
#define DC2_SYS_DC_64_ERR_STATUS_SB1_dbg_en_shift                                     (31)
#define DC2_SYS_DC_64_ERR_STATUS_SB1_dbg_en_mask                                      (0x80000000)
#define DC2_SYS_DC_64_ERR_STATUS_SB1_dbg_en(data)                                     (0x80000000&((data)<<31))
#define DC2_SYS_DC_64_ERR_STATUS_SB1_dbg_en_src(data)                                 ((0x80000000&(data))>>31)
#define DC2_SYS_DC_64_ERR_STATUS_SB1_get_dbg_en(data)                                 ((0x80000000&(data))>>31)
#define DC2_SYS_DC_64_ERR_STATUS_SB1_err_bl_zero_shift                                (30)
#define DC2_SYS_DC_64_ERR_STATUS_SB1_err_bl_zero_mask                                 (0x40000000)
#define DC2_SYS_DC_64_ERR_STATUS_SB1_err_bl_zero(data)                                (0x40000000&((data)<<30))
#define DC2_SYS_DC_64_ERR_STATUS_SB1_err_bl_zero_src(data)                            ((0x40000000&(data))>>30)
#define DC2_SYS_DC_64_ERR_STATUS_SB1_get_err_bl_zero(data)                            ((0x40000000&(data))>>30)
#define DC2_SYS_DC_64_ERR_STATUS_SB1_err_blk_wxh_odd_shift                            (29)
#define DC2_SYS_DC_64_ERR_STATUS_SB1_err_blk_wxh_odd_mask                             (0x20000000)
#define DC2_SYS_DC_64_ERR_STATUS_SB1_err_blk_wxh_odd(data)                            (0x20000000&((data)<<29))
#define DC2_SYS_DC_64_ERR_STATUS_SB1_err_blk_wxh_odd_src(data)                        ((0x20000000&(data))>>29)
#define DC2_SYS_DC_64_ERR_STATUS_SB1_get_err_blk_wxh_odd(data)                        ((0x20000000&(data))>>29)
#define DC2_SYS_DC_64_ERR_STATUS_SB1_max_wcmd_in_fifo_shift                           (24)
#define DC2_SYS_DC_64_ERR_STATUS_SB1_max_wcmd_in_fifo_mask                            (0x0F000000)
#define DC2_SYS_DC_64_ERR_STATUS_SB1_max_wcmd_in_fifo(data)                           (0x0F000000&((data)<<24))
#define DC2_SYS_DC_64_ERR_STATUS_SB1_max_wcmd_in_fifo_src(data)                       ((0x0F000000&(data))>>24)
#define DC2_SYS_DC_64_ERR_STATUS_SB1_get_max_wcmd_in_fifo(data)                       ((0x0F000000&(data))>>24)
#define DC2_SYS_DC_64_ERR_STATUS_SB1_max_rcmd_in_fifo_shift                           (20)
#define DC2_SYS_DC_64_ERR_STATUS_SB1_max_rcmd_in_fifo_mask                            (0x00F00000)
#define DC2_SYS_DC_64_ERR_STATUS_SB1_max_rcmd_in_fifo(data)                           (0x00F00000&((data)<<20))
#define DC2_SYS_DC_64_ERR_STATUS_SB1_max_rcmd_in_fifo_src(data)                       ((0x00F00000&(data))>>20)
#define DC2_SYS_DC_64_ERR_STATUS_SB1_get_max_rcmd_in_fifo(data)                       ((0x00F00000&(data))>>20)
#define DC2_SYS_DC_64_ERR_STATUS_SB1_max_wait_wdone_shift                             (14)
#define DC2_SYS_DC_64_ERR_STATUS_SB1_max_wait_wdone_mask                              (0x000FC000)
#define DC2_SYS_DC_64_ERR_STATUS_SB1_max_wait_wdone(data)                             (0x000FC000&((data)<<14))
#define DC2_SYS_DC_64_ERR_STATUS_SB1_max_wait_wdone_src(data)                         ((0x000FC000&(data))>>14)
#define DC2_SYS_DC_64_ERR_STATUS_SB1_get_max_wait_wdone(data)                         ((0x000FC000&(data))>>14)
#define DC2_SYS_DC_64_ERR_STATUS_SB1_max_wdata_in_fifo_shift                          (7)
#define DC2_SYS_DC_64_ERR_STATUS_SB1_max_wdata_in_fifo_mask                           (0x00003F80)
#define DC2_SYS_DC_64_ERR_STATUS_SB1_max_wdata_in_fifo(data)                          (0x00003F80&((data)<<7))
#define DC2_SYS_DC_64_ERR_STATUS_SB1_max_wdata_in_fifo_src(data)                      ((0x00003F80&(data))>>7)
#define DC2_SYS_DC_64_ERR_STATUS_SB1_get_max_wdata_in_fifo(data)                      ((0x00003F80&(data))>>7)
#define DC2_SYS_DC_64_ERR_STATUS_SB1_max_rdata_in_fifo_shift                          (0)
#define DC2_SYS_DC_64_ERR_STATUS_SB1_max_rdata_in_fifo_mask                           (0x0000007F)
#define DC2_SYS_DC_64_ERR_STATUS_SB1_max_rdata_in_fifo(data)                          (0x0000007F&((data)<<0))
#define DC2_SYS_DC_64_ERR_STATUS_SB1_max_rdata_in_fifo_src(data)                      ((0x0000007F&(data))>>0)
#define DC2_SYS_DC_64_ERR_STATUS_SB1_get_max_rdata_in_fifo(data)                      ((0x0000007F&(data))>>0)


#define DC2_SYS_DC_64_ERR_STATUS_SB3                                                  0x180030CC
#define DC2_SYS_DC_64_ERR_STATUS_SB3_reg_addr                                         "0xB80030CC"
#define DC2_SYS_DC_64_ERR_STATUS_SB3_reg                                              0xB80030CC
#define set_DC2_SYS_DC_64_ERR_STATUS_SB3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_64_ERR_STATUS_SB3_reg)=data)
#define get_DC2_SYS_DC_64_ERR_STATUS_SB3_reg   (*((volatile unsigned int*) DC2_SYS_DC_64_ERR_STATUS_SB3_reg))
#define DC2_SYS_DC_64_ERR_STATUS_SB3_inst_adr                                         "0x0033"
#define DC2_SYS_DC_64_ERR_STATUS_SB3_inst                                             0x0033
#define DC2_SYS_DC_64_ERR_STATUS_SB3_dbg_en_shift                                     (31)
#define DC2_SYS_DC_64_ERR_STATUS_SB3_dbg_en_mask                                      (0x80000000)
#define DC2_SYS_DC_64_ERR_STATUS_SB3_dbg_en(data)                                     (0x80000000&((data)<<31))
#define DC2_SYS_DC_64_ERR_STATUS_SB3_dbg_en_src(data)                                 ((0x80000000&(data))>>31)
#define DC2_SYS_DC_64_ERR_STATUS_SB3_get_dbg_en(data)                                 ((0x80000000&(data))>>31)
#define DC2_SYS_DC_64_ERR_STATUS_SB3_err_bl_zero_shift                                (30)
#define DC2_SYS_DC_64_ERR_STATUS_SB3_err_bl_zero_mask                                 (0x40000000)
#define DC2_SYS_DC_64_ERR_STATUS_SB3_err_bl_zero(data)                                (0x40000000&((data)<<30))
#define DC2_SYS_DC_64_ERR_STATUS_SB3_err_bl_zero_src(data)                            ((0x40000000&(data))>>30)
#define DC2_SYS_DC_64_ERR_STATUS_SB3_get_err_bl_zero(data)                            ((0x40000000&(data))>>30)
#define DC2_SYS_DC_64_ERR_STATUS_SB3_err_blk_wxh_odd_shift                            (29)
#define DC2_SYS_DC_64_ERR_STATUS_SB3_err_blk_wxh_odd_mask                             (0x20000000)
#define DC2_SYS_DC_64_ERR_STATUS_SB3_err_blk_wxh_odd(data)                            (0x20000000&((data)<<29))
#define DC2_SYS_DC_64_ERR_STATUS_SB3_err_blk_wxh_odd_src(data)                        ((0x20000000&(data))>>29)
#define DC2_SYS_DC_64_ERR_STATUS_SB3_get_err_blk_wxh_odd(data)                        ((0x20000000&(data))>>29)
#define DC2_SYS_DC_64_ERR_STATUS_SB3_max_wcmd_in_fifo_shift                           (24)
#define DC2_SYS_DC_64_ERR_STATUS_SB3_max_wcmd_in_fifo_mask                            (0x0F000000)
#define DC2_SYS_DC_64_ERR_STATUS_SB3_max_wcmd_in_fifo(data)                           (0x0F000000&((data)<<24))
#define DC2_SYS_DC_64_ERR_STATUS_SB3_max_wcmd_in_fifo_src(data)                       ((0x0F000000&(data))>>24)
#define DC2_SYS_DC_64_ERR_STATUS_SB3_get_max_wcmd_in_fifo(data)                       ((0x0F000000&(data))>>24)
#define DC2_SYS_DC_64_ERR_STATUS_SB3_max_rcmd_in_fifo_shift                           (20)
#define DC2_SYS_DC_64_ERR_STATUS_SB3_max_rcmd_in_fifo_mask                            (0x00F00000)
#define DC2_SYS_DC_64_ERR_STATUS_SB3_max_rcmd_in_fifo(data)                           (0x00F00000&((data)<<20))
#define DC2_SYS_DC_64_ERR_STATUS_SB3_max_rcmd_in_fifo_src(data)                       ((0x00F00000&(data))>>20)
#define DC2_SYS_DC_64_ERR_STATUS_SB3_get_max_rcmd_in_fifo(data)                       ((0x00F00000&(data))>>20)
#define DC2_SYS_DC_64_ERR_STATUS_SB3_max_wait_wdone_shift                             (14)
#define DC2_SYS_DC_64_ERR_STATUS_SB3_max_wait_wdone_mask                              (0x000FC000)
#define DC2_SYS_DC_64_ERR_STATUS_SB3_max_wait_wdone(data)                             (0x000FC000&((data)<<14))
#define DC2_SYS_DC_64_ERR_STATUS_SB3_max_wait_wdone_src(data)                         ((0x000FC000&(data))>>14)
#define DC2_SYS_DC_64_ERR_STATUS_SB3_get_max_wait_wdone(data)                         ((0x000FC000&(data))>>14)
#define DC2_SYS_DC_64_ERR_STATUS_SB3_max_wdata_in_fifo_shift                          (7)
#define DC2_SYS_DC_64_ERR_STATUS_SB3_max_wdata_in_fifo_mask                           (0x00003F80)
#define DC2_SYS_DC_64_ERR_STATUS_SB3_max_wdata_in_fifo(data)                          (0x00003F80&((data)<<7))
#define DC2_SYS_DC_64_ERR_STATUS_SB3_max_wdata_in_fifo_src(data)                      ((0x00003F80&(data))>>7)
#define DC2_SYS_DC_64_ERR_STATUS_SB3_get_max_wdata_in_fifo(data)                      ((0x00003F80&(data))>>7)
#define DC2_SYS_DC_64_ERR_STATUS_SB3_max_rdata_in_fifo_shift                          (0)
#define DC2_SYS_DC_64_ERR_STATUS_SB3_max_rdata_in_fifo_mask                           (0x0000007F)
#define DC2_SYS_DC_64_ERR_STATUS_SB3_max_rdata_in_fifo(data)                          (0x0000007F&((data)<<0))
#define DC2_SYS_DC_64_ERR_STATUS_SB3_max_rdata_in_fifo_src(data)                      ((0x0000007F&(data))>>0)
#define DC2_SYS_DC_64_ERR_STATUS_SB3_get_max_rdata_in_fifo(data)                      ((0x0000007F&(data))>>0)


#define DC2_SYS_DC_64_BIST_MODE                                                       0x18003B00
#define DC2_SYS_DC_64_BIST_MODE_reg_addr                                              "0xB8003B00"
#define DC2_SYS_DC_64_BIST_MODE_reg                                                   0xB8003B00
#define set_DC2_SYS_DC_64_BIST_MODE_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_64_BIST_MODE_reg)=data)
#define get_DC2_SYS_DC_64_BIST_MODE_reg   (*((volatile unsigned int*) DC2_SYS_DC_64_BIST_MODE_reg))
#define DC2_SYS_DC_64_BIST_MODE_inst_adr                                              "0x00C0"
#define DC2_SYS_DC_64_BIST_MODE_inst                                                  0x00C0
#define DC2_SYS_DC_64_BIST_MODE_DC_BIST_MODE_WRAP2_shift                              (2)
#define DC2_SYS_DC_64_BIST_MODE_DC_BIST_MODE_WRAP2_mask                               (0x00000004)
#define DC2_SYS_DC_64_BIST_MODE_DC_BIST_MODE_WRAP2(data)                              (0x00000004&((data)<<2))
#define DC2_SYS_DC_64_BIST_MODE_DC_BIST_MODE_WRAP2_src(data)                          ((0x00000004&(data))>>2)
#define DC2_SYS_DC_64_BIST_MODE_get_DC_BIST_MODE_WRAP2(data)                          ((0x00000004&(data))>>2)
#define DC2_SYS_DC_64_BIST_MODE_DC_BIST_MODE_WRAP1_shift                              (1)
#define DC2_SYS_DC_64_BIST_MODE_DC_BIST_MODE_WRAP1_mask                               (0x00000002)
#define DC2_SYS_DC_64_BIST_MODE_DC_BIST_MODE_WRAP1(data)                              (0x00000002&((data)<<1))
#define DC2_SYS_DC_64_BIST_MODE_DC_BIST_MODE_WRAP1_src(data)                          ((0x00000002&(data))>>1)
#define DC2_SYS_DC_64_BIST_MODE_get_DC_BIST_MODE_WRAP1(data)                          ((0x00000002&(data))>>1)
#define DC2_SYS_DC_64_BIST_MODE_DC_BIST_MODE_WRAP0_shift                              (0)
#define DC2_SYS_DC_64_BIST_MODE_DC_BIST_MODE_WRAP0_mask                               (0x00000001)
#define DC2_SYS_DC_64_BIST_MODE_DC_BIST_MODE_WRAP0(data)                              (0x00000001&((data)<<0))
#define DC2_SYS_DC_64_BIST_MODE_DC_BIST_MODE_WRAP0_src(data)                          ((0x00000001&(data))>>0)
#define DC2_SYS_DC_64_BIST_MODE_get_DC_BIST_MODE_WRAP0(data)                          ((0x00000001&(data))>>0)


#define DC2_SYS_DC_64_BIST_DONE                                                       0x18003B04
#define DC2_SYS_DC_64_BIST_DONE_reg_addr                                              "0xB8003B04"
#define DC2_SYS_DC_64_BIST_DONE_reg                                                   0xB8003B04
#define set_DC2_SYS_DC_64_BIST_DONE_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_64_BIST_DONE_reg)=data)
#define get_DC2_SYS_DC_64_BIST_DONE_reg   (*((volatile unsigned int*) DC2_SYS_DC_64_BIST_DONE_reg))
#define DC2_SYS_DC_64_BIST_DONE_inst_adr                                              "0x00C1"
#define DC2_SYS_DC_64_BIST_DONE_inst                                                  0x00C1
#define DC2_SYS_DC_64_BIST_DONE_DC_BIST_DONE_WRAP2_shift                              (2)
#define DC2_SYS_DC_64_BIST_DONE_DC_BIST_DONE_WRAP2_mask                               (0x00000004)
#define DC2_SYS_DC_64_BIST_DONE_DC_BIST_DONE_WRAP2(data)                              (0x00000004&((data)<<2))
#define DC2_SYS_DC_64_BIST_DONE_DC_BIST_DONE_WRAP2_src(data)                          ((0x00000004&(data))>>2)
#define DC2_SYS_DC_64_BIST_DONE_get_DC_BIST_DONE_WRAP2(data)                          ((0x00000004&(data))>>2)
#define DC2_SYS_DC_64_BIST_DONE_DC_BIST_DONE_WRAP1_shift                              (1)
#define DC2_SYS_DC_64_BIST_DONE_DC_BIST_DONE_WRAP1_mask                               (0x00000002)
#define DC2_SYS_DC_64_BIST_DONE_DC_BIST_DONE_WRAP1(data)                              (0x00000002&((data)<<1))
#define DC2_SYS_DC_64_BIST_DONE_DC_BIST_DONE_WRAP1_src(data)                          ((0x00000002&(data))>>1)
#define DC2_SYS_DC_64_BIST_DONE_get_DC_BIST_DONE_WRAP1(data)                          ((0x00000002&(data))>>1)
#define DC2_SYS_DC_64_BIST_DONE_DC_BIST_DONE_WRAP0_shift                              (0)
#define DC2_SYS_DC_64_BIST_DONE_DC_BIST_DONE_WRAP0_mask                               (0x00000001)
#define DC2_SYS_DC_64_BIST_DONE_DC_BIST_DONE_WRAP0(data)                              (0x00000001&((data)<<0))
#define DC2_SYS_DC_64_BIST_DONE_DC_BIST_DONE_WRAP0_src(data)                          ((0x00000001&(data))>>0)
#define DC2_SYS_DC_64_BIST_DONE_get_DC_BIST_DONE_WRAP0(data)                          ((0x00000001&(data))>>0)


#define DC2_SYS_DC_64_BIST_FAIL                                                       0x18003B08
#define DC2_SYS_DC_64_BIST_FAIL_reg_addr                                              "0xB8003B08"
#define DC2_SYS_DC_64_BIST_FAIL_reg                                                   0xB8003B08
#define set_DC2_SYS_DC_64_BIST_FAIL_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_64_BIST_FAIL_reg)=data)
#define get_DC2_SYS_DC_64_BIST_FAIL_reg   (*((volatile unsigned int*) DC2_SYS_DC_64_BIST_FAIL_reg))
#define DC2_SYS_DC_64_BIST_FAIL_inst_adr                                              "0x00C2"
#define DC2_SYS_DC_64_BIST_FAIL_inst                                                  0x00C2
#define DC2_SYS_DC_64_BIST_FAIL_DC_BIST_FAIL_GROUP_WRAP2_shift                        (2)
#define DC2_SYS_DC_64_BIST_FAIL_DC_BIST_FAIL_GROUP_WRAP2_mask                         (0x00000004)
#define DC2_SYS_DC_64_BIST_FAIL_DC_BIST_FAIL_GROUP_WRAP2(data)                        (0x00000004&((data)<<2))
#define DC2_SYS_DC_64_BIST_FAIL_DC_BIST_FAIL_GROUP_WRAP2_src(data)                    ((0x00000004&(data))>>2)
#define DC2_SYS_DC_64_BIST_FAIL_get_DC_BIST_FAIL_GROUP_WRAP2(data)                    ((0x00000004&(data))>>2)
#define DC2_SYS_DC_64_BIST_FAIL_DC_BIST_FAIL_GROUP_WRAP1_shift                        (1)
#define DC2_SYS_DC_64_BIST_FAIL_DC_BIST_FAIL_GROUP_WRAP1_mask                         (0x00000002)
#define DC2_SYS_DC_64_BIST_FAIL_DC_BIST_FAIL_GROUP_WRAP1(data)                        (0x00000002&((data)<<1))
#define DC2_SYS_DC_64_BIST_FAIL_DC_BIST_FAIL_GROUP_WRAP1_src(data)                    ((0x00000002&(data))>>1)
#define DC2_SYS_DC_64_BIST_FAIL_get_DC_BIST_FAIL_GROUP_WRAP1(data)                    ((0x00000002&(data))>>1)
#define DC2_SYS_DC_64_BIST_FAIL_DC_BIST_FAIL_GROUP_WRAP0_shift                        (0)
#define DC2_SYS_DC_64_BIST_FAIL_DC_BIST_FAIL_GROUP_WRAP0_mask                         (0x00000001)
#define DC2_SYS_DC_64_BIST_FAIL_DC_BIST_FAIL_GROUP_WRAP0(data)                        (0x00000001&((data)<<0))
#define DC2_SYS_DC_64_BIST_FAIL_DC_BIST_FAIL_GROUP_WRAP0_src(data)                    ((0x00000001&(data))>>0)
#define DC2_SYS_DC_64_BIST_FAIL_get_DC_BIST_FAIL_GROUP_WRAP0(data)                    ((0x00000001&(data))>>0)


#define DC2_SYS_DC_64_DRF                                                             0x18003B0C
#define DC2_SYS_DC_64_DRF_reg_addr                                                    "0xB8003B0C"
#define DC2_SYS_DC_64_DRF_reg                                                         0xB8003B0C
#define set_DC2_SYS_DC_64_DRF_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_64_DRF_reg)=data)
#define get_DC2_SYS_DC_64_DRF_reg   (*((volatile unsigned int*) DC2_SYS_DC_64_DRF_reg))
#define DC2_SYS_DC_64_DRF_inst_adr                                                    "0x00C3"
#define DC2_SYS_DC_64_DRF_inst                                                        0x00C3
#define DC2_SYS_DC_64_DRF_DC_DRF_MODE_WRAP2_shift                                     (2)
#define DC2_SYS_DC_64_DRF_DC_DRF_MODE_WRAP2_mask                                      (0x00000004)
#define DC2_SYS_DC_64_DRF_DC_DRF_MODE_WRAP2(data)                                     (0x00000004&((data)<<2))
#define DC2_SYS_DC_64_DRF_DC_DRF_MODE_WRAP2_src(data)                                 ((0x00000004&(data))>>2)
#define DC2_SYS_DC_64_DRF_get_DC_DRF_MODE_WRAP2(data)                                 ((0x00000004&(data))>>2)
#define DC2_SYS_DC_64_DRF_DC_DRF_MODE_WRAP1_shift                                     (1)
#define DC2_SYS_DC_64_DRF_DC_DRF_MODE_WRAP1_mask                                      (0x00000002)
#define DC2_SYS_DC_64_DRF_DC_DRF_MODE_WRAP1(data)                                     (0x00000002&((data)<<1))
#define DC2_SYS_DC_64_DRF_DC_DRF_MODE_WRAP1_src(data)                                 ((0x00000002&(data))>>1)
#define DC2_SYS_DC_64_DRF_get_DC_DRF_MODE_WRAP1(data)                                 ((0x00000002&(data))>>1)
#define DC2_SYS_DC_64_DRF_DC_DRF_MODE_WRAP0_shift                                     (0)
#define DC2_SYS_DC_64_DRF_DC_DRF_MODE_WRAP0_mask                                      (0x00000001)
#define DC2_SYS_DC_64_DRF_DC_DRF_MODE_WRAP0(data)                                     (0x00000001&((data)<<0))
#define DC2_SYS_DC_64_DRF_DC_DRF_MODE_WRAP0_src(data)                                 ((0x00000001&(data))>>0)
#define DC2_SYS_DC_64_DRF_get_DC_DRF_MODE_WRAP0(data)                                 ((0x00000001&(data))>>0)


#define DC2_SYS_DC_64_DRF_RESUME                                                      0x18003B10
#define DC2_SYS_DC_64_DRF_RESUME_reg_addr                                             "0xB8003B10"
#define DC2_SYS_DC_64_DRF_RESUME_reg                                                  0xB8003B10
#define set_DC2_SYS_DC_64_DRF_RESUME_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_64_DRF_RESUME_reg)=data)
#define get_DC2_SYS_DC_64_DRF_RESUME_reg   (*((volatile unsigned int*) DC2_SYS_DC_64_DRF_RESUME_reg))
#define DC2_SYS_DC_64_DRF_RESUME_inst_adr                                             "0x00C4"
#define DC2_SYS_DC_64_DRF_RESUME_inst                                                 0x00C4
#define DC2_SYS_DC_64_DRF_RESUME_DC_DRF_RESUME_WRAP2_shift                            (2)
#define DC2_SYS_DC_64_DRF_RESUME_DC_DRF_RESUME_WRAP2_mask                             (0x00000004)
#define DC2_SYS_DC_64_DRF_RESUME_DC_DRF_RESUME_WRAP2(data)                            (0x00000004&((data)<<2))
#define DC2_SYS_DC_64_DRF_RESUME_DC_DRF_RESUME_WRAP2_src(data)                        ((0x00000004&(data))>>2)
#define DC2_SYS_DC_64_DRF_RESUME_get_DC_DRF_RESUME_WRAP2(data)                        ((0x00000004&(data))>>2)
#define DC2_SYS_DC_64_DRF_RESUME_DC_DRF_RESUME_WRAP1_shift                            (1)
#define DC2_SYS_DC_64_DRF_RESUME_DC_DRF_RESUME_WRAP1_mask                             (0x00000002)
#define DC2_SYS_DC_64_DRF_RESUME_DC_DRF_RESUME_WRAP1(data)                            (0x00000002&((data)<<1))
#define DC2_SYS_DC_64_DRF_RESUME_DC_DRF_RESUME_WRAP1_src(data)                        ((0x00000002&(data))>>1)
#define DC2_SYS_DC_64_DRF_RESUME_get_DC_DRF_RESUME_WRAP1(data)                        ((0x00000002&(data))>>1)
#define DC2_SYS_DC_64_DRF_RESUME_DC_DRF_RESUME_WRAP0_shift                            (0)
#define DC2_SYS_DC_64_DRF_RESUME_DC_DRF_RESUME_WRAP0_mask                             (0x00000001)
#define DC2_SYS_DC_64_DRF_RESUME_DC_DRF_RESUME_WRAP0(data)                            (0x00000001&((data)<<0))
#define DC2_SYS_DC_64_DRF_RESUME_DC_DRF_RESUME_WRAP0_src(data)                        ((0x00000001&(data))>>0)
#define DC2_SYS_DC_64_DRF_RESUME_get_DC_DRF_RESUME_WRAP0(data)                        ((0x00000001&(data))>>0)


#define DC2_SYS_DC_64_DRF_DONE                                                        0x18003B14
#define DC2_SYS_DC_64_DRF_DONE_reg_addr                                               "0xB8003B14"
#define DC2_SYS_DC_64_DRF_DONE_reg                                                    0xB8003B14
#define set_DC2_SYS_DC_64_DRF_DONE_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_64_DRF_DONE_reg)=data)
#define get_DC2_SYS_DC_64_DRF_DONE_reg   (*((volatile unsigned int*) DC2_SYS_DC_64_DRF_DONE_reg))
#define DC2_SYS_DC_64_DRF_DONE_inst_adr                                               "0x00C5"
#define DC2_SYS_DC_64_DRF_DONE_inst                                                   0x00C5
#define DC2_SYS_DC_64_DRF_DONE_DC_DRF_DONE_WRAP2_shift                                (2)
#define DC2_SYS_DC_64_DRF_DONE_DC_DRF_DONE_WRAP2_mask                                 (0x00000004)
#define DC2_SYS_DC_64_DRF_DONE_DC_DRF_DONE_WRAP2(data)                                (0x00000004&((data)<<2))
#define DC2_SYS_DC_64_DRF_DONE_DC_DRF_DONE_WRAP2_src(data)                            ((0x00000004&(data))>>2)
#define DC2_SYS_DC_64_DRF_DONE_get_DC_DRF_DONE_WRAP2(data)                            ((0x00000004&(data))>>2)
#define DC2_SYS_DC_64_DRF_DONE_DC_DRF_DONE_WRAP1_shift                                (1)
#define DC2_SYS_DC_64_DRF_DONE_DC_DRF_DONE_WRAP1_mask                                 (0x00000002)
#define DC2_SYS_DC_64_DRF_DONE_DC_DRF_DONE_WRAP1(data)                                (0x00000002&((data)<<1))
#define DC2_SYS_DC_64_DRF_DONE_DC_DRF_DONE_WRAP1_src(data)                            ((0x00000002&(data))>>1)
#define DC2_SYS_DC_64_DRF_DONE_get_DC_DRF_DONE_WRAP1(data)                            ((0x00000002&(data))>>1)
#define DC2_SYS_DC_64_DRF_DONE_DC_DRF_DONE_WRAP0_shift                                (0)
#define DC2_SYS_DC_64_DRF_DONE_DC_DRF_DONE_WRAP0_mask                                 (0x00000001)
#define DC2_SYS_DC_64_DRF_DONE_DC_DRF_DONE_WRAP0(data)                                (0x00000001&((data)<<0))
#define DC2_SYS_DC_64_DRF_DONE_DC_DRF_DONE_WRAP0_src(data)                            ((0x00000001&(data))>>0)
#define DC2_SYS_DC_64_DRF_DONE_get_DC_DRF_DONE_WRAP0(data)                            ((0x00000001&(data))>>0)


#define DC2_SYS_DC_64_DRF_PAUSE                                                       0x18003B18
#define DC2_SYS_DC_64_DRF_PAUSE_reg_addr                                              "0xB8003B18"
#define DC2_SYS_DC_64_DRF_PAUSE_reg                                                   0xB8003B18
#define set_DC2_SYS_DC_64_DRF_PAUSE_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_64_DRF_PAUSE_reg)=data)
#define get_DC2_SYS_DC_64_DRF_PAUSE_reg   (*((volatile unsigned int*) DC2_SYS_DC_64_DRF_PAUSE_reg))
#define DC2_SYS_DC_64_DRF_PAUSE_inst_adr                                              "0x00C6"
#define DC2_SYS_DC_64_DRF_PAUSE_inst                                                  0x00C6
#define DC2_SYS_DC_64_DRF_PAUSE_DC_DRF_PAUSE_WRAP2_shift                              (2)
#define DC2_SYS_DC_64_DRF_PAUSE_DC_DRF_PAUSE_WRAP2_mask                               (0x00000004)
#define DC2_SYS_DC_64_DRF_PAUSE_DC_DRF_PAUSE_WRAP2(data)                              (0x00000004&((data)<<2))
#define DC2_SYS_DC_64_DRF_PAUSE_DC_DRF_PAUSE_WRAP2_src(data)                          ((0x00000004&(data))>>2)
#define DC2_SYS_DC_64_DRF_PAUSE_get_DC_DRF_PAUSE_WRAP2(data)                          ((0x00000004&(data))>>2)
#define DC2_SYS_DC_64_DRF_PAUSE_DC_DRF_PAUSE_WRAP1_shift                              (1)
#define DC2_SYS_DC_64_DRF_PAUSE_DC_DRF_PAUSE_WRAP1_mask                               (0x00000002)
#define DC2_SYS_DC_64_DRF_PAUSE_DC_DRF_PAUSE_WRAP1(data)                              (0x00000002&((data)<<1))
#define DC2_SYS_DC_64_DRF_PAUSE_DC_DRF_PAUSE_WRAP1_src(data)                          ((0x00000002&(data))>>1)
#define DC2_SYS_DC_64_DRF_PAUSE_get_DC_DRF_PAUSE_WRAP1(data)                          ((0x00000002&(data))>>1)
#define DC2_SYS_DC_64_DRF_PAUSE_DC_DRF_PAUSE_WRAP0_shift                              (0)
#define DC2_SYS_DC_64_DRF_PAUSE_DC_DRF_PAUSE_WRAP0_mask                               (0x00000001)
#define DC2_SYS_DC_64_DRF_PAUSE_DC_DRF_PAUSE_WRAP0(data)                              (0x00000001&((data)<<0))
#define DC2_SYS_DC_64_DRF_PAUSE_DC_DRF_PAUSE_WRAP0_src(data)                          ((0x00000001&(data))>>0)
#define DC2_SYS_DC_64_DRF_PAUSE_get_DC_DRF_PAUSE_WRAP0(data)                          ((0x00000001&(data))>>0)


#define DC2_SYS_DC_64_DRF_FAIL                                                        0x18003B1C
#define DC2_SYS_DC_64_DRF_FAIL_reg_addr                                               "0xB8003B1C"
#define DC2_SYS_DC_64_DRF_FAIL_reg                                                    0xB8003B1C
#define set_DC2_SYS_DC_64_DRF_FAIL_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_64_DRF_FAIL_reg)=data)
#define get_DC2_SYS_DC_64_DRF_FAIL_reg   (*((volatile unsigned int*) DC2_SYS_DC_64_DRF_FAIL_reg))
#define DC2_SYS_DC_64_DRF_FAIL_inst_adr                                               "0x00C7"
#define DC2_SYS_DC_64_DRF_FAIL_inst                                                   0x00C7
#define DC2_SYS_DC_64_DRF_FAIL_DC_DRF_FAIL_GROUP_WRAP2_shift                          (2)
#define DC2_SYS_DC_64_DRF_FAIL_DC_DRF_FAIL_GROUP_WRAP2_mask                           (0x00000004)
#define DC2_SYS_DC_64_DRF_FAIL_DC_DRF_FAIL_GROUP_WRAP2(data)                          (0x00000004&((data)<<2))
#define DC2_SYS_DC_64_DRF_FAIL_DC_DRF_FAIL_GROUP_WRAP2_src(data)                      ((0x00000004&(data))>>2)
#define DC2_SYS_DC_64_DRF_FAIL_get_DC_DRF_FAIL_GROUP_WRAP2(data)                      ((0x00000004&(data))>>2)
#define DC2_SYS_DC_64_DRF_FAIL_DC_DRF_FAIL_GROUP_WRAP1_shift                          (1)
#define DC2_SYS_DC_64_DRF_FAIL_DC_DRF_FAIL_GROUP_WRAP1_mask                           (0x00000002)
#define DC2_SYS_DC_64_DRF_FAIL_DC_DRF_FAIL_GROUP_WRAP1(data)                          (0x00000002&((data)<<1))
#define DC2_SYS_DC_64_DRF_FAIL_DC_DRF_FAIL_GROUP_WRAP1_src(data)                      ((0x00000002&(data))>>1)
#define DC2_SYS_DC_64_DRF_FAIL_get_DC_DRF_FAIL_GROUP_WRAP1(data)                      ((0x00000002&(data))>>1)
#define DC2_SYS_DC_64_DRF_FAIL_DC_DRF_FAIL_GROUP_WRAP0_shift                          (0)
#define DC2_SYS_DC_64_DRF_FAIL_DC_DRF_FAIL_GROUP_WRAP0_mask                           (0x00000001)
#define DC2_SYS_DC_64_DRF_FAIL_DC_DRF_FAIL_GROUP_WRAP0(data)                          (0x00000001&((data)<<0))
#define DC2_SYS_DC_64_DRF_FAIL_DC_DRF_FAIL_GROUP_WRAP0_src(data)                      ((0x00000001&(data))>>0)
#define DC2_SYS_DC_64_DRF_FAIL_get_DC_DRF_FAIL_GROUP_WRAP0(data)                      ((0x00000001&(data))>>0)


#define DC2_SYS_DC_64_BIST_DETAIL                                                     0x18003B20
#define DC2_SYS_DC_64_BIST_DETAIL_reg_addr                                            "0xB8003B20"
#define DC2_SYS_DC_64_BIST_DETAIL_reg                                                 0xB8003B20
#define set_DC2_SYS_DC_64_BIST_DETAIL_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_64_BIST_DETAIL_reg)=data)
#define get_DC2_SYS_DC_64_BIST_DETAIL_reg   (*((volatile unsigned int*) DC2_SYS_DC_64_BIST_DETAIL_reg))
#define DC2_SYS_DC_64_BIST_DETAIL_inst_adr                                            "0x00C8"
#define DC2_SYS_DC_64_BIST_DETAIL_inst                                                0x00C8
#define DC2_SYS_DC_64_BIST_DETAIL_DC_DRF_WRAP2_FAIL_1_shift                           (11)
#define DC2_SYS_DC_64_BIST_DETAIL_DC_DRF_WRAP2_FAIL_1_mask                            (0x00000800)
#define DC2_SYS_DC_64_BIST_DETAIL_DC_DRF_WRAP2_FAIL_1(data)                           (0x00000800&((data)<<11))
#define DC2_SYS_DC_64_BIST_DETAIL_DC_DRF_WRAP2_FAIL_1_src(data)                       ((0x00000800&(data))>>11)
#define DC2_SYS_DC_64_BIST_DETAIL_get_DC_DRF_WRAP2_FAIL_1(data)                       ((0x00000800&(data))>>11)
#define DC2_SYS_DC_64_BIST_DETAIL_DC_DRF_WRAP2_FAIL_0_shift                           (10)
#define DC2_SYS_DC_64_BIST_DETAIL_DC_DRF_WRAP2_FAIL_0_mask                            (0x00000400)
#define DC2_SYS_DC_64_BIST_DETAIL_DC_DRF_WRAP2_FAIL_0(data)                           (0x00000400&((data)<<10))
#define DC2_SYS_DC_64_BIST_DETAIL_DC_DRF_WRAP2_FAIL_0_src(data)                       ((0x00000400&(data))>>10)
#define DC2_SYS_DC_64_BIST_DETAIL_get_DC_DRF_WRAP2_FAIL_0(data)                       ((0x00000400&(data))>>10)
#define DC2_SYS_DC_64_BIST_DETAIL_DC_BIST_WRAP2_FAIL_1_shift                          (9)
#define DC2_SYS_DC_64_BIST_DETAIL_DC_BIST_WRAP2_FAIL_1_mask                           (0x00000200)
#define DC2_SYS_DC_64_BIST_DETAIL_DC_BIST_WRAP2_FAIL_1(data)                          (0x00000200&((data)<<9))
#define DC2_SYS_DC_64_BIST_DETAIL_DC_BIST_WRAP2_FAIL_1_src(data)                      ((0x00000200&(data))>>9)
#define DC2_SYS_DC_64_BIST_DETAIL_get_DC_BIST_WRAP2_FAIL_1(data)                      ((0x00000200&(data))>>9)
#define DC2_SYS_DC_64_BIST_DETAIL_DC_BIST_WRAP2_FAIL_0_shift                          (8)
#define DC2_SYS_DC_64_BIST_DETAIL_DC_BIST_WRAP2_FAIL_0_mask                           (0x00000100)
#define DC2_SYS_DC_64_BIST_DETAIL_DC_BIST_WRAP2_FAIL_0(data)                          (0x00000100&((data)<<8))
#define DC2_SYS_DC_64_BIST_DETAIL_DC_BIST_WRAP2_FAIL_0_src(data)                      ((0x00000100&(data))>>8)
#define DC2_SYS_DC_64_BIST_DETAIL_get_DC_BIST_WRAP2_FAIL_0(data)                      ((0x00000100&(data))>>8)
#define DC2_SYS_DC_64_BIST_DETAIL_DC_DRF_WRAP1_FAIL_1_shift                           (7)
#define DC2_SYS_DC_64_BIST_DETAIL_DC_DRF_WRAP1_FAIL_1_mask                            (0x00000080)
#define DC2_SYS_DC_64_BIST_DETAIL_DC_DRF_WRAP1_FAIL_1(data)                           (0x00000080&((data)<<7))
#define DC2_SYS_DC_64_BIST_DETAIL_DC_DRF_WRAP1_FAIL_1_src(data)                       ((0x00000080&(data))>>7)
#define DC2_SYS_DC_64_BIST_DETAIL_get_DC_DRF_WRAP1_FAIL_1(data)                       ((0x00000080&(data))>>7)
#define DC2_SYS_DC_64_BIST_DETAIL_DC_DRF_WRAP1_FAIL_0_shift                           (6)
#define DC2_SYS_DC_64_BIST_DETAIL_DC_DRF_WRAP1_FAIL_0_mask                            (0x00000040)
#define DC2_SYS_DC_64_BIST_DETAIL_DC_DRF_WRAP1_FAIL_0(data)                           (0x00000040&((data)<<6))
#define DC2_SYS_DC_64_BIST_DETAIL_DC_DRF_WRAP1_FAIL_0_src(data)                       ((0x00000040&(data))>>6)
#define DC2_SYS_DC_64_BIST_DETAIL_get_DC_DRF_WRAP1_FAIL_0(data)                       ((0x00000040&(data))>>6)
#define DC2_SYS_DC_64_BIST_DETAIL_DC_BIST_WRAP1_FAIL_1_shift                          (5)
#define DC2_SYS_DC_64_BIST_DETAIL_DC_BIST_WRAP1_FAIL_1_mask                           (0x00000020)
#define DC2_SYS_DC_64_BIST_DETAIL_DC_BIST_WRAP1_FAIL_1(data)                          (0x00000020&((data)<<5))
#define DC2_SYS_DC_64_BIST_DETAIL_DC_BIST_WRAP1_FAIL_1_src(data)                      ((0x00000020&(data))>>5)
#define DC2_SYS_DC_64_BIST_DETAIL_get_DC_BIST_WRAP1_FAIL_1(data)                      ((0x00000020&(data))>>5)
#define DC2_SYS_DC_64_BIST_DETAIL_DC_BIST_WRAP1_FAIL_0_shift                          (4)
#define DC2_SYS_DC_64_BIST_DETAIL_DC_BIST_WRAP1_FAIL_0_mask                           (0x00000010)
#define DC2_SYS_DC_64_BIST_DETAIL_DC_BIST_WRAP1_FAIL_0(data)                          (0x00000010&((data)<<4))
#define DC2_SYS_DC_64_BIST_DETAIL_DC_BIST_WRAP1_FAIL_0_src(data)                      ((0x00000010&(data))>>4)
#define DC2_SYS_DC_64_BIST_DETAIL_get_DC_BIST_WRAP1_FAIL_0(data)                      ((0x00000010&(data))>>4)
#define DC2_SYS_DC_64_BIST_DETAIL_DC_DRF_WRAP0_FAIL_1_shift                           (3)
#define DC2_SYS_DC_64_BIST_DETAIL_DC_DRF_WRAP0_FAIL_1_mask                            (0x00000008)
#define DC2_SYS_DC_64_BIST_DETAIL_DC_DRF_WRAP0_FAIL_1(data)                           (0x00000008&((data)<<3))
#define DC2_SYS_DC_64_BIST_DETAIL_DC_DRF_WRAP0_FAIL_1_src(data)                       ((0x00000008&(data))>>3)
#define DC2_SYS_DC_64_BIST_DETAIL_get_DC_DRF_WRAP0_FAIL_1(data)                       ((0x00000008&(data))>>3)
#define DC2_SYS_DC_64_BIST_DETAIL_DC_DRF_WRAP0_FAIL_0_shift                           (2)
#define DC2_SYS_DC_64_BIST_DETAIL_DC_DRF_WRAP0_FAIL_0_mask                            (0x00000004)
#define DC2_SYS_DC_64_BIST_DETAIL_DC_DRF_WRAP0_FAIL_0(data)                           (0x00000004&((data)<<2))
#define DC2_SYS_DC_64_BIST_DETAIL_DC_DRF_WRAP0_FAIL_0_src(data)                       ((0x00000004&(data))>>2)
#define DC2_SYS_DC_64_BIST_DETAIL_get_DC_DRF_WRAP0_FAIL_0(data)                       ((0x00000004&(data))>>2)
#define DC2_SYS_DC_64_BIST_DETAIL_DC_BIST_WRAP0_FAIL_1_shift                          (1)
#define DC2_SYS_DC_64_BIST_DETAIL_DC_BIST_WRAP0_FAIL_1_mask                           (0x00000002)
#define DC2_SYS_DC_64_BIST_DETAIL_DC_BIST_WRAP0_FAIL_1(data)                          (0x00000002&((data)<<1))
#define DC2_SYS_DC_64_BIST_DETAIL_DC_BIST_WRAP0_FAIL_1_src(data)                      ((0x00000002&(data))>>1)
#define DC2_SYS_DC_64_BIST_DETAIL_get_DC_BIST_WRAP0_FAIL_1(data)                      ((0x00000002&(data))>>1)
#define DC2_SYS_DC_64_BIST_DETAIL_DC_BIST_WRAP0_FAIL_0_shift                          (0)
#define DC2_SYS_DC_64_BIST_DETAIL_DC_BIST_WRAP0_FAIL_0_mask                           (0x00000001)
#define DC2_SYS_DC_64_BIST_DETAIL_DC_BIST_WRAP0_FAIL_0(data)                          (0x00000001&((data)<<0))
#define DC2_SYS_DC_64_BIST_DETAIL_DC_BIST_WRAP0_FAIL_0_src(data)                      ((0x00000001&(data))>>0)
#define DC2_SYS_DC_64_BIST_DETAIL_get_DC_BIST_WRAP0_FAIL_0(data)                      ((0x00000001&(data))>>0)


#define DC2_SYS_DC_64_BIST_RM                                                         0x18003B24
#define DC2_SYS_DC_64_BIST_RM_reg_addr                                                "0xB8003B24"
#define DC2_SYS_DC_64_BIST_RM_reg                                                     0xB8003B24
#define set_DC2_SYS_DC_64_BIST_RM_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_64_BIST_RM_reg)=data)
#define get_DC2_SYS_DC_64_BIST_RM_reg   (*((volatile unsigned int*) DC2_SYS_DC_64_BIST_RM_reg))
#define DC2_SYS_DC_64_BIST_RM_inst_adr                                                "0x00C9"
#define DC2_SYS_DC_64_BIST_RM_inst                                                    0x00C9
#define DC2_SYS_DC_64_BIST_RM_RMEA_shift                                              (20)
#define DC2_SYS_DC_64_BIST_RM_RMEA_mask                                               (0x00100000)
#define DC2_SYS_DC_64_BIST_RM_RMEA(data)                                              (0x00100000&((data)<<20))
#define DC2_SYS_DC_64_BIST_RM_RMEA_src(data)                                          ((0x00100000&(data))>>20)
#define DC2_SYS_DC_64_BIST_RM_get_RMEA(data)                                          ((0x00100000&(data))>>20)
#define DC2_SYS_DC_64_BIST_RM_RMA_shift                                               (16)
#define DC2_SYS_DC_64_BIST_RM_RMA_mask                                                (0x000F0000)
#define DC2_SYS_DC_64_BIST_RM_RMA(data)                                               (0x000F0000&((data)<<16))
#define DC2_SYS_DC_64_BIST_RM_RMA_src(data)                                           ((0x000F0000&(data))>>16)
#define DC2_SYS_DC_64_BIST_RM_get_RMA(data)                                           ((0x000F0000&(data))>>16)
#define DC2_SYS_DC_64_BIST_RM_RMEB_shift                                              (12)
#define DC2_SYS_DC_64_BIST_RM_RMEB_mask                                               (0x00001000)
#define DC2_SYS_DC_64_BIST_RM_RMEB(data)                                              (0x00001000&((data)<<12))
#define DC2_SYS_DC_64_BIST_RM_RMEB_src(data)                                          ((0x00001000&(data))>>12)
#define DC2_SYS_DC_64_BIST_RM_get_RMEB(data)                                          ((0x00001000&(data))>>12)
#define DC2_SYS_DC_64_BIST_RM_RMB_shift                                               (8)
#define DC2_SYS_DC_64_BIST_RM_RMB_mask                                                (0x00000F00)
#define DC2_SYS_DC_64_BIST_RM_RMB(data)                                               (0x00000F00&((data)<<8))
#define DC2_SYS_DC_64_BIST_RM_RMB_src(data)                                           ((0x00000F00&(data))>>8)
#define DC2_SYS_DC_64_BIST_RM_get_RMB(data)                                           ((0x00000F00&(data))>>8)


#define DC2_SYS_DC_64_PC_CTRL                                                         0x180031B0
#define DC2_SYS_DC_64_PC_CTRL_reg_addr                                                "0xB80031B0"
#define DC2_SYS_DC_64_PC_CTRL_reg                                                     0xB80031B0
#define set_DC2_SYS_DC_64_PC_CTRL_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_64_PC_CTRL_reg)=data)
#define get_DC2_SYS_DC_64_PC_CTRL_reg   (*((volatile unsigned int*) DC2_SYS_DC_64_PC_CTRL_reg))
#define DC2_SYS_DC_64_PC_CTRL_inst_adr                                                "0x006C"
#define DC2_SYS_DC_64_PC_CTRL_inst                                                    0x006C
#define DC2_SYS_DC_64_PC_CTRL_pc_go_shift                                             (0)
#define DC2_SYS_DC_64_PC_CTRL_pc_go_mask                                              (0x00000001)
#define DC2_SYS_DC_64_PC_CTRL_pc_go(data)                                             (0x00000001&((data)<<0))
#define DC2_SYS_DC_64_PC_CTRL_pc_go_src(data)                                         ((0x00000001&(data))>>0)
#define DC2_SYS_DC_64_PC_CTRL_get_pc_go(data)                                         ((0x00000001&(data))>>0)


#define DC2_SYS_DC_PC_SYS_PROG_CTRL                                                   0x18003114
#define DC2_SYS_DC_PC_SYS_PROG_CTRL_reg_addr                                          "0xB8003114"
#define DC2_SYS_DC_PC_SYS_PROG_CTRL_reg                                               0xB8003114
#define set_DC2_SYS_DC_PC_SYS_PROG_CTRL_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYS_PROG_CTRL_reg)=data)
#define get_DC2_SYS_DC_PC_SYS_PROG_CTRL_reg   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYS_PROG_CTRL_reg))
#define DC2_SYS_DC_PC_SYS_PROG_CTRL_inst_adr                                          "0x0045"
#define DC2_SYS_DC_PC_SYS_PROG_CTRL_inst                                              0x0045
#define DC2_SYS_DC_PC_SYS_PROG_CTRL_write_en_3_shift                                  (23)
#define DC2_SYS_DC_PC_SYS_PROG_CTRL_write_en_3_mask                                   (0x00800000)
#define DC2_SYS_DC_PC_SYS_PROG_CTRL_write_en_3(data)                                  (0x00800000&((data)<<23))
#define DC2_SYS_DC_PC_SYS_PROG_CTRL_write_en_3_src(data)                              ((0x00800000&(data))>>23)
#define DC2_SYS_DC_PC_SYS_PROG_CTRL_get_write_en_3(data)                              ((0x00800000&(data))>>23)
#define DC2_SYS_DC_PC_SYS_PROG_CTRL_pc_sys_prog2_sel_shift                            (16)
#define DC2_SYS_DC_PC_SYS_PROG_CTRL_pc_sys_prog2_sel_mask                             (0x007F0000)
#define DC2_SYS_DC_PC_SYS_PROG_CTRL_pc_sys_prog2_sel(data)                            (0x007F0000&((data)<<16))
#define DC2_SYS_DC_PC_SYS_PROG_CTRL_pc_sys_prog2_sel_src(data)                        ((0x007F0000&(data))>>16)
#define DC2_SYS_DC_PC_SYS_PROG_CTRL_get_pc_sys_prog2_sel(data)                        ((0x007F0000&(data))>>16)
#define DC2_SYS_DC_PC_SYS_PROG_CTRL_write_en_2_shift                                  (15)
#define DC2_SYS_DC_PC_SYS_PROG_CTRL_write_en_2_mask                                   (0x00008000)
#define DC2_SYS_DC_PC_SYS_PROG_CTRL_write_en_2(data)                                  (0x00008000&((data)<<15))
#define DC2_SYS_DC_PC_SYS_PROG_CTRL_write_en_2_src(data)                              ((0x00008000&(data))>>15)
#define DC2_SYS_DC_PC_SYS_PROG_CTRL_get_write_en_2(data)                              ((0x00008000&(data))>>15)
#define DC2_SYS_DC_PC_SYS_PROG_CTRL_pc_sys_prog1_sel_shift                            (8)
#define DC2_SYS_DC_PC_SYS_PROG_CTRL_pc_sys_prog1_sel_mask                             (0x00007F00)
#define DC2_SYS_DC_PC_SYS_PROG_CTRL_pc_sys_prog1_sel(data)                            (0x00007F00&((data)<<8))
#define DC2_SYS_DC_PC_SYS_PROG_CTRL_pc_sys_prog1_sel_src(data)                        ((0x00007F00&(data))>>8)
#define DC2_SYS_DC_PC_SYS_PROG_CTRL_get_pc_sys_prog1_sel(data)                        ((0x00007F00&(data))>>8)
#define DC2_SYS_DC_PC_SYS_PROG_CTRL_write_en_1_shift                                  (7)
#define DC2_SYS_DC_PC_SYS_PROG_CTRL_write_en_1_mask                                   (0x00000080)
#define DC2_SYS_DC_PC_SYS_PROG_CTRL_write_en_1(data)                                  (0x00000080&((data)<<7))
#define DC2_SYS_DC_PC_SYS_PROG_CTRL_write_en_1_src(data)                              ((0x00000080&(data))>>7)
#define DC2_SYS_DC_PC_SYS_PROG_CTRL_get_write_en_1(data)                              ((0x00000080&(data))>>7)
#define DC2_SYS_DC_PC_SYS_PROG_CTRL_pc_sys_prog0_sel_shift                            (0)
#define DC2_SYS_DC_PC_SYS_PROG_CTRL_pc_sys_prog0_sel_mask                             (0x0000007F)
#define DC2_SYS_DC_PC_SYS_PROG_CTRL_pc_sys_prog0_sel(data)                            (0x0000007F&((data)<<0))
#define DC2_SYS_DC_PC_SYS_PROG_CTRL_pc_sys_prog0_sel_src(data)                        ((0x0000007F&(data))>>0)
#define DC2_SYS_DC_PC_SYS_PROG_CTRL_get_pc_sys_prog0_sel(data)                        ((0x0000007F&(data))>>0)


#define DC2_SYS_DC_64_PC_SYS_PROG_CTRL1                                               0x180031B4
#define DC2_SYS_DC_64_PC_SYS_PROG_CTRL1_reg_addr                                      "0xB80031B4"
#define DC2_SYS_DC_64_PC_SYS_PROG_CTRL1_reg                                           0xB80031B4
#define set_DC2_SYS_DC_64_PC_SYS_PROG_CTRL1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_64_PC_SYS_PROG_CTRL1_reg)=data)
#define get_DC2_SYS_DC_64_PC_SYS_PROG_CTRL1_reg   (*((volatile unsigned int*) DC2_SYS_DC_64_PC_SYS_PROG_CTRL1_reg))
#define DC2_SYS_DC_64_PC_SYS_PROG_CTRL1_inst_adr                                      "0x006D"
#define DC2_SYS_DC_64_PC_SYS_PROG_CTRL1_inst                                          0x006D
#define DC2_SYS_DC_64_PC_SYS_PROG_CTRL1_pc_sys_prog2_req_occur_shift                  (2)
#define DC2_SYS_DC_64_PC_SYS_PROG_CTRL1_pc_sys_prog2_req_occur_mask                   (0x00000004)
#define DC2_SYS_DC_64_PC_SYS_PROG_CTRL1_pc_sys_prog2_req_occur(data)                  (0x00000004&((data)<<2))
#define DC2_SYS_DC_64_PC_SYS_PROG_CTRL1_pc_sys_prog2_req_occur_src(data)              ((0x00000004&(data))>>2)
#define DC2_SYS_DC_64_PC_SYS_PROG_CTRL1_get_pc_sys_prog2_req_occur(data)              ((0x00000004&(data))>>2)
#define DC2_SYS_DC_64_PC_SYS_PROG_CTRL1_pc_sys_prog1_req_occur_shift                  (1)
#define DC2_SYS_DC_64_PC_SYS_PROG_CTRL1_pc_sys_prog1_req_occur_mask                   (0x00000002)
#define DC2_SYS_DC_64_PC_SYS_PROG_CTRL1_pc_sys_prog1_req_occur(data)                  (0x00000002&((data)<<1))
#define DC2_SYS_DC_64_PC_SYS_PROG_CTRL1_pc_sys_prog1_req_occur_src(data)              ((0x00000002&(data))>>1)
#define DC2_SYS_DC_64_PC_SYS_PROG_CTRL1_get_pc_sys_prog1_req_occur(data)              ((0x00000002&(data))>>1)
#define DC2_SYS_DC_64_PC_SYS_PROG_CTRL1_pc_sys_prog0_req_occur_shift                  (0)
#define DC2_SYS_DC_64_PC_SYS_PROG_CTRL1_pc_sys_prog0_req_occur_mask                   (0x00000001)
#define DC2_SYS_DC_64_PC_SYS_PROG_CTRL1_pc_sys_prog0_req_occur(data)                  (0x00000001&((data)<<0))
#define DC2_SYS_DC_64_PC_SYS_PROG_CTRL1_pc_sys_prog0_req_occur_src(data)              ((0x00000001&(data))>>0)
#define DC2_SYS_DC_64_PC_SYS_PROG_CTRL1_get_pc_sys_prog0_req_occur(data)              ((0x00000001&(data))>>0)


#define DC2_SYS_DC_PC_SYS_PROG_0_ACC_LAT                                              0x18003160
#define DC2_SYS_DC_PC_SYS_PROG_0_ACC_LAT_reg_addr                                     "0xB8003160"
#define DC2_SYS_DC_PC_SYS_PROG_0_ACC_LAT_reg                                          0xB8003160
#define set_DC2_SYS_DC_PC_SYS_PROG_0_ACC_LAT_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYS_PROG_0_ACC_LAT_reg)=data)
#define get_DC2_SYS_DC_PC_SYS_PROG_0_ACC_LAT_reg   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYS_PROG_0_ACC_LAT_reg))
#define DC2_SYS_DC_PC_SYS_PROG_0_ACC_LAT_inst_adr                                     "0x0058"
#define DC2_SYS_DC_PC_SYS_PROG_0_ACC_LAT_inst                                         0x0058
#define DC2_SYS_DC_PC_SYS_PROG_0_ACC_LAT_sys_prog0_acc_lat_shift                      (0)
#define DC2_SYS_DC_PC_SYS_PROG_0_ACC_LAT_sys_prog0_acc_lat_mask                       (0xFFFFFFFF)
#define DC2_SYS_DC_PC_SYS_PROG_0_ACC_LAT_sys_prog0_acc_lat(data)                      (0xFFFFFFFF&((data)<<0))
#define DC2_SYS_DC_PC_SYS_PROG_0_ACC_LAT_sys_prog0_acc_lat_src(data)                  ((0xFFFFFFFF&(data))>>0)
#define DC2_SYS_DC_PC_SYS_PROG_0_ACC_LAT_get_sys_prog0_acc_lat(data)                  ((0xFFFFFFFF&(data))>>0)


#define DC2_SYS_DC_PC_SYS_PROG_0_MAX_LAT                                              0x18003164
#define DC2_SYS_DC_PC_SYS_PROG_0_MAX_LAT_reg_addr                                     "0xB8003164"
#define DC2_SYS_DC_PC_SYS_PROG_0_MAX_LAT_reg                                          0xB8003164
#define set_DC2_SYS_DC_PC_SYS_PROG_0_MAX_LAT_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYS_PROG_0_MAX_LAT_reg)=data)
#define get_DC2_SYS_DC_PC_SYS_PROG_0_MAX_LAT_reg   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYS_PROG_0_MAX_LAT_reg))
#define DC2_SYS_DC_PC_SYS_PROG_0_MAX_LAT_inst_adr                                     "0x0059"
#define DC2_SYS_DC_PC_SYS_PROG_0_MAX_LAT_inst                                         0x0059
#define DC2_SYS_DC_PC_SYS_PROG_0_MAX_LAT_sys_prog0_max_lat_shift                      (0)
#define DC2_SYS_DC_PC_SYS_PROG_0_MAX_LAT_sys_prog0_max_lat_mask                       (0x0000FFFF)
#define DC2_SYS_DC_PC_SYS_PROG_0_MAX_LAT_sys_prog0_max_lat(data)                      (0x0000FFFF&((data)<<0))
#define DC2_SYS_DC_PC_SYS_PROG_0_MAX_LAT_sys_prog0_max_lat_src(data)                  ((0x0000FFFF&(data))>>0)
#define DC2_SYS_DC_PC_SYS_PROG_0_MAX_LAT_get_sys_prog0_max_lat(data)                  ((0x0000FFFF&(data))>>0)


#define DC2_SYS_DC_PC_SYS_PROG_0_REQ_NUM                                              0x18003168
#define DC2_SYS_DC_PC_SYS_PROG_0_REQ_NUM_reg_addr                                     "0xB8003168"
#define DC2_SYS_DC_PC_SYS_PROG_0_REQ_NUM_reg                                          0xB8003168
#define set_DC2_SYS_DC_PC_SYS_PROG_0_REQ_NUM_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYS_PROG_0_REQ_NUM_reg)=data)
#define get_DC2_SYS_DC_PC_SYS_PROG_0_REQ_NUM_reg   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYS_PROG_0_REQ_NUM_reg))
#define DC2_SYS_DC_PC_SYS_PROG_0_REQ_NUM_inst_adr                                     "0x005A"
#define DC2_SYS_DC_PC_SYS_PROG_0_REQ_NUM_inst                                         0x005A
#define DC2_SYS_DC_PC_SYS_PROG_0_REQ_NUM_sys_prog0_req_num_shift                      (0)
#define DC2_SYS_DC_PC_SYS_PROG_0_REQ_NUM_sys_prog0_req_num_mask                       (0x00FFFFFF)
#define DC2_SYS_DC_PC_SYS_PROG_0_REQ_NUM_sys_prog0_req_num(data)                      (0x00FFFFFF&((data)<<0))
#define DC2_SYS_DC_PC_SYS_PROG_0_REQ_NUM_sys_prog0_req_num_src(data)                  ((0x00FFFFFF&(data))>>0)
#define DC2_SYS_DC_PC_SYS_PROG_0_REQ_NUM_get_sys_prog0_req_num(data)                  ((0x00FFFFFF&(data))>>0)


#define DC2_SYS_DC_PC_SYS_PROG_0_ACK_NUM                                              0x1800316C
#define DC2_SYS_DC_PC_SYS_PROG_0_ACK_NUM_reg_addr                                     "0xB800316C"
#define DC2_SYS_DC_PC_SYS_PROG_0_ACK_NUM_reg                                          0xB800316C
#define set_DC2_SYS_DC_PC_SYS_PROG_0_ACK_NUM_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYS_PROG_0_ACK_NUM_reg)=data)
#define get_DC2_SYS_DC_PC_SYS_PROG_0_ACK_NUM_reg   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYS_PROG_0_ACK_NUM_reg))
#define DC2_SYS_DC_PC_SYS_PROG_0_ACK_NUM_inst_adr                                     "0x005B"
#define DC2_SYS_DC_PC_SYS_PROG_0_ACK_NUM_inst                                         0x005B
#define DC2_SYS_DC_PC_SYS_PROG_0_ACK_NUM_sys_prog0_ack_num_shift                      (0)
#define DC2_SYS_DC_PC_SYS_PROG_0_ACK_NUM_sys_prog0_ack_num_mask                       (0xFFFFFFFF)
#define DC2_SYS_DC_PC_SYS_PROG_0_ACK_NUM_sys_prog0_ack_num(data)                      (0xFFFFFFFF&((data)<<0))
#define DC2_SYS_DC_PC_SYS_PROG_0_ACK_NUM_sys_prog0_ack_num_src(data)                  ((0xFFFFFFFF&(data))>>0)
#define DC2_SYS_DC_PC_SYS_PROG_0_ACK_NUM_get_sys_prog0_ack_num(data)                  ((0xFFFFFFFF&(data))>>0)


#define DC2_SYS_DC_PC_SYS_PROG_1_ACC_LAT                                              0x18003170
#define DC2_SYS_DC_PC_SYS_PROG_1_ACC_LAT_reg_addr                                     "0xB8003170"
#define DC2_SYS_DC_PC_SYS_PROG_1_ACC_LAT_reg                                          0xB8003170
#define set_DC2_SYS_DC_PC_SYS_PROG_1_ACC_LAT_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYS_PROG_1_ACC_LAT_reg)=data)
#define get_DC2_SYS_DC_PC_SYS_PROG_1_ACC_LAT_reg   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYS_PROG_1_ACC_LAT_reg))
#define DC2_SYS_DC_PC_SYS_PROG_1_ACC_LAT_inst_adr                                     "0x005C"
#define DC2_SYS_DC_PC_SYS_PROG_1_ACC_LAT_inst                                         0x005C
#define DC2_SYS_DC_PC_SYS_PROG_1_ACC_LAT_sys_prog1_acc_lat_shift                      (0)
#define DC2_SYS_DC_PC_SYS_PROG_1_ACC_LAT_sys_prog1_acc_lat_mask                       (0xFFFFFFFF)
#define DC2_SYS_DC_PC_SYS_PROG_1_ACC_LAT_sys_prog1_acc_lat(data)                      (0xFFFFFFFF&((data)<<0))
#define DC2_SYS_DC_PC_SYS_PROG_1_ACC_LAT_sys_prog1_acc_lat_src(data)                  ((0xFFFFFFFF&(data))>>0)
#define DC2_SYS_DC_PC_SYS_PROG_1_ACC_LAT_get_sys_prog1_acc_lat(data)                  ((0xFFFFFFFF&(data))>>0)


#define DC2_SYS_DC_PC_SYS_PROG_1_MAX_LAT                                              0x18003174
#define DC2_SYS_DC_PC_SYS_PROG_1_MAX_LAT_reg_addr                                     "0xB8003174"
#define DC2_SYS_DC_PC_SYS_PROG_1_MAX_LAT_reg                                          0xB8003174
#define set_DC2_SYS_DC_PC_SYS_PROG_1_MAX_LAT_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYS_PROG_1_MAX_LAT_reg)=data)
#define get_DC2_SYS_DC_PC_SYS_PROG_1_MAX_LAT_reg   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYS_PROG_1_MAX_LAT_reg))
#define DC2_SYS_DC_PC_SYS_PROG_1_MAX_LAT_inst_adr                                     "0x005D"
#define DC2_SYS_DC_PC_SYS_PROG_1_MAX_LAT_inst                                         0x005D
#define DC2_SYS_DC_PC_SYS_PROG_1_MAX_LAT_sys_prog1_max_lat_shift                      (0)
#define DC2_SYS_DC_PC_SYS_PROG_1_MAX_LAT_sys_prog1_max_lat_mask                       (0x0000FFFF)
#define DC2_SYS_DC_PC_SYS_PROG_1_MAX_LAT_sys_prog1_max_lat(data)                      (0x0000FFFF&((data)<<0))
#define DC2_SYS_DC_PC_SYS_PROG_1_MAX_LAT_sys_prog1_max_lat_src(data)                  ((0x0000FFFF&(data))>>0)
#define DC2_SYS_DC_PC_SYS_PROG_1_MAX_LAT_get_sys_prog1_max_lat(data)                  ((0x0000FFFF&(data))>>0)


#define DC2_SYS_DC_PC_SYS_PROG_1_REQ_NUM                                              0x18003178
#define DC2_SYS_DC_PC_SYS_PROG_1_REQ_NUM_reg_addr                                     "0xB8003178"
#define DC2_SYS_DC_PC_SYS_PROG_1_REQ_NUM_reg                                          0xB8003178
#define set_DC2_SYS_DC_PC_SYS_PROG_1_REQ_NUM_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYS_PROG_1_REQ_NUM_reg)=data)
#define get_DC2_SYS_DC_PC_SYS_PROG_1_REQ_NUM_reg   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYS_PROG_1_REQ_NUM_reg))
#define DC2_SYS_DC_PC_SYS_PROG_1_REQ_NUM_inst_adr                                     "0x005E"
#define DC2_SYS_DC_PC_SYS_PROG_1_REQ_NUM_inst                                         0x005E
#define DC2_SYS_DC_PC_SYS_PROG_1_REQ_NUM_sys_prog1_req_num_shift                      (0)
#define DC2_SYS_DC_PC_SYS_PROG_1_REQ_NUM_sys_prog1_req_num_mask                       (0x00FFFFFF)
#define DC2_SYS_DC_PC_SYS_PROG_1_REQ_NUM_sys_prog1_req_num(data)                      (0x00FFFFFF&((data)<<0))
#define DC2_SYS_DC_PC_SYS_PROG_1_REQ_NUM_sys_prog1_req_num_src(data)                  ((0x00FFFFFF&(data))>>0)
#define DC2_SYS_DC_PC_SYS_PROG_1_REQ_NUM_get_sys_prog1_req_num(data)                  ((0x00FFFFFF&(data))>>0)


#define DC2_SYS_DC_PC_SYS_PROG_1_ACK_NUM                                              0x1800317C
#define DC2_SYS_DC_PC_SYS_PROG_1_ACK_NUM_reg_addr                                     "0xB800317C"
#define DC2_SYS_DC_PC_SYS_PROG_1_ACK_NUM_reg                                          0xB800317C
#define set_DC2_SYS_DC_PC_SYS_PROG_1_ACK_NUM_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYS_PROG_1_ACK_NUM_reg)=data)
#define get_DC2_SYS_DC_PC_SYS_PROG_1_ACK_NUM_reg   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYS_PROG_1_ACK_NUM_reg))
#define DC2_SYS_DC_PC_SYS_PROG_1_ACK_NUM_inst_adr                                     "0x005F"
#define DC2_SYS_DC_PC_SYS_PROG_1_ACK_NUM_inst                                         0x005F
#define DC2_SYS_DC_PC_SYS_PROG_1_ACK_NUM_sys_prog1_ack_num_shift                      (0)
#define DC2_SYS_DC_PC_SYS_PROG_1_ACK_NUM_sys_prog1_ack_num_mask                       (0xFFFFFFFF)
#define DC2_SYS_DC_PC_SYS_PROG_1_ACK_NUM_sys_prog1_ack_num(data)                      (0xFFFFFFFF&((data)<<0))
#define DC2_SYS_DC_PC_SYS_PROG_1_ACK_NUM_sys_prog1_ack_num_src(data)                  ((0xFFFFFFFF&(data))>>0)
#define DC2_SYS_DC_PC_SYS_PROG_1_ACK_NUM_get_sys_prog1_ack_num(data)                  ((0xFFFFFFFF&(data))>>0)


#define DC2_SYS_DC_PC_SYS_PROG_2_ACC_LAT                                              0x18003180
#define DC2_SYS_DC_PC_SYS_PROG_2_ACC_LAT_reg_addr                                     "0xB8003180"
#define DC2_SYS_DC_PC_SYS_PROG_2_ACC_LAT_reg                                          0xB8003180
#define set_DC2_SYS_DC_PC_SYS_PROG_2_ACC_LAT_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYS_PROG_2_ACC_LAT_reg)=data)
#define get_DC2_SYS_DC_PC_SYS_PROG_2_ACC_LAT_reg   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYS_PROG_2_ACC_LAT_reg))
#define DC2_SYS_DC_PC_SYS_PROG_2_ACC_LAT_inst_adr                                     "0x0060"
#define DC2_SYS_DC_PC_SYS_PROG_2_ACC_LAT_inst                                         0x0060
#define DC2_SYS_DC_PC_SYS_PROG_2_ACC_LAT_sys_prog2_acc_lat_shift                      (0)
#define DC2_SYS_DC_PC_SYS_PROG_2_ACC_LAT_sys_prog2_acc_lat_mask                       (0xFFFFFFFF)
#define DC2_SYS_DC_PC_SYS_PROG_2_ACC_LAT_sys_prog2_acc_lat(data)                      (0xFFFFFFFF&((data)<<0))
#define DC2_SYS_DC_PC_SYS_PROG_2_ACC_LAT_sys_prog2_acc_lat_src(data)                  ((0xFFFFFFFF&(data))>>0)
#define DC2_SYS_DC_PC_SYS_PROG_2_ACC_LAT_get_sys_prog2_acc_lat(data)                  ((0xFFFFFFFF&(data))>>0)


#define DC2_SYS_DC_PC_SYS_PROG_2_MAX_LAT                                              0x18003184
#define DC2_SYS_DC_PC_SYS_PROG_2_MAX_LAT_reg_addr                                     "0xB8003184"
#define DC2_SYS_DC_PC_SYS_PROG_2_MAX_LAT_reg                                          0xB8003184
#define set_DC2_SYS_DC_PC_SYS_PROG_2_MAX_LAT_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYS_PROG_2_MAX_LAT_reg)=data)
#define get_DC2_SYS_DC_PC_SYS_PROG_2_MAX_LAT_reg   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYS_PROG_2_MAX_LAT_reg))
#define DC2_SYS_DC_PC_SYS_PROG_2_MAX_LAT_inst_adr                                     "0x0061"
#define DC2_SYS_DC_PC_SYS_PROG_2_MAX_LAT_inst                                         0x0061
#define DC2_SYS_DC_PC_SYS_PROG_2_MAX_LAT_sys_prog2_max_lat_shift                      (0)
#define DC2_SYS_DC_PC_SYS_PROG_2_MAX_LAT_sys_prog2_max_lat_mask                       (0x0000FFFF)
#define DC2_SYS_DC_PC_SYS_PROG_2_MAX_LAT_sys_prog2_max_lat(data)                      (0x0000FFFF&((data)<<0))
#define DC2_SYS_DC_PC_SYS_PROG_2_MAX_LAT_sys_prog2_max_lat_src(data)                  ((0x0000FFFF&(data))>>0)
#define DC2_SYS_DC_PC_SYS_PROG_2_MAX_LAT_get_sys_prog2_max_lat(data)                  ((0x0000FFFF&(data))>>0)


#define DC2_SYS_DC_PC_SYS_PROG_2_REQ_NUM                                              0x18003188
#define DC2_SYS_DC_PC_SYS_PROG_2_REQ_NUM_reg_addr                                     "0xB8003188"
#define DC2_SYS_DC_PC_SYS_PROG_2_REQ_NUM_reg                                          0xB8003188
#define set_DC2_SYS_DC_PC_SYS_PROG_2_REQ_NUM_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYS_PROG_2_REQ_NUM_reg)=data)
#define get_DC2_SYS_DC_PC_SYS_PROG_2_REQ_NUM_reg   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYS_PROG_2_REQ_NUM_reg))
#define DC2_SYS_DC_PC_SYS_PROG_2_REQ_NUM_inst_adr                                     "0x0062"
#define DC2_SYS_DC_PC_SYS_PROG_2_REQ_NUM_inst                                         0x0062
#define DC2_SYS_DC_PC_SYS_PROG_2_REQ_NUM_sys_prog2_req_num_shift                      (0)
#define DC2_SYS_DC_PC_SYS_PROG_2_REQ_NUM_sys_prog2_req_num_mask                       (0x00FFFFFF)
#define DC2_SYS_DC_PC_SYS_PROG_2_REQ_NUM_sys_prog2_req_num(data)                      (0x00FFFFFF&((data)<<0))
#define DC2_SYS_DC_PC_SYS_PROG_2_REQ_NUM_sys_prog2_req_num_src(data)                  ((0x00FFFFFF&(data))>>0)
#define DC2_SYS_DC_PC_SYS_PROG_2_REQ_NUM_get_sys_prog2_req_num(data)                  ((0x00FFFFFF&(data))>>0)


#define DC2_SYS_DC_PC_SYS_PROG_2_ACK_NUM                                              0x1800318C
#define DC2_SYS_DC_PC_SYS_PROG_2_ACK_NUM_reg_addr                                     "0xB800318C"
#define DC2_SYS_DC_PC_SYS_PROG_2_ACK_NUM_reg                                          0xB800318C
#define set_DC2_SYS_DC_PC_SYS_PROG_2_ACK_NUM_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYS_PROG_2_ACK_NUM_reg)=data)
#define get_DC2_SYS_DC_PC_SYS_PROG_2_ACK_NUM_reg   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYS_PROG_2_ACK_NUM_reg))
#define DC2_SYS_DC_PC_SYS_PROG_2_ACK_NUM_inst_adr                                     "0x0063"
#define DC2_SYS_DC_PC_SYS_PROG_2_ACK_NUM_inst                                         0x0063
#define DC2_SYS_DC_PC_SYS_PROG_2_ACK_NUM_sys_prog2_ack_num_shift                      (0)
#define DC2_SYS_DC_PC_SYS_PROG_2_ACK_NUM_sys_prog2_ack_num_mask                       (0xFFFFFFFF)
#define DC2_SYS_DC_PC_SYS_PROG_2_ACK_NUM_sys_prog2_ack_num(data)                      (0xFFFFFFFF&((data)<<0))
#define DC2_SYS_DC_PC_SYS_PROG_2_ACK_NUM_sys_prog2_ack_num_src(data)                  ((0xFFFFFFFF&(data))>>0)
#define DC2_SYS_DC_PC_SYS_PROG_2_ACK_NUM_get_sys_prog2_ack_num(data)                  ((0xFFFFFFFF&(data))>>0)


#define DC2_SYS_DC_PC_SYS_PROG_0                                                      0x180031A0
#define DC2_SYS_DC_PC_SYS_PROG_0_reg_addr                                             "0xB80031A0"
#define DC2_SYS_DC_PC_SYS_PROG_0_reg                                                  0xB80031A0
#define set_DC2_SYS_DC_PC_SYS_PROG_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYS_PROG_0_reg)=data)
#define get_DC2_SYS_DC_PC_SYS_PROG_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYS_PROG_0_reg))
#define DC2_SYS_DC_PC_SYS_PROG_0_inst_adr                                             "0x0068"
#define DC2_SYS_DC_PC_SYS_PROG_0_inst                                                 0x0068
#define DC2_SYS_DC_PC_SYS_PROG_0_sys0_hitend_cnt_shift                                (0)
#define DC2_SYS_DC_PC_SYS_PROG_0_sys0_hitend_cnt_mask                                 (0x0000FFFF)
#define DC2_SYS_DC_PC_SYS_PROG_0_sys0_hitend_cnt(data)                                (0x0000FFFF&((data)<<0))
#define DC2_SYS_DC_PC_SYS_PROG_0_sys0_hitend_cnt_src(data)                            ((0x0000FFFF&(data))>>0)
#define DC2_SYS_DC_PC_SYS_PROG_0_get_sys0_hitend_cnt(data)                            ((0x0000FFFF&(data))>>0)


#define DC2_SYS_DC_PC_SYS_PROG_1                                                      0x180031A4
#define DC2_SYS_DC_PC_SYS_PROG_1_reg_addr                                             "0xB80031A4"
#define DC2_SYS_DC_PC_SYS_PROG_1_reg                                                  0xB80031A4
#define set_DC2_SYS_DC_PC_SYS_PROG_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYS_PROG_1_reg)=data)
#define get_DC2_SYS_DC_PC_SYS_PROG_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYS_PROG_1_reg))
#define DC2_SYS_DC_PC_SYS_PROG_1_inst_adr                                             "0x0069"
#define DC2_SYS_DC_PC_SYS_PROG_1_inst                                                 0x0069
#define DC2_SYS_DC_PC_SYS_PROG_1_sys1_hitend_cnt_shift                                (0)
#define DC2_SYS_DC_PC_SYS_PROG_1_sys1_hitend_cnt_mask                                 (0x0000FFFF)
#define DC2_SYS_DC_PC_SYS_PROG_1_sys1_hitend_cnt(data)                                (0x0000FFFF&((data)<<0))
#define DC2_SYS_DC_PC_SYS_PROG_1_sys1_hitend_cnt_src(data)                            ((0x0000FFFF&(data))>>0)
#define DC2_SYS_DC_PC_SYS_PROG_1_get_sys1_hitend_cnt(data)                            ((0x0000FFFF&(data))>>0)


#define DC2_SYS_DC_PC_SYS_PROG_2                                                      0x180031A8
#define DC2_SYS_DC_PC_SYS_PROG_2_reg_addr                                             "0xB80031A8"
#define DC2_SYS_DC_PC_SYS_PROG_2_reg                                                  0xB80031A8
#define set_DC2_SYS_DC_PC_SYS_PROG_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYS_PROG_2_reg)=data)
#define get_DC2_SYS_DC_PC_SYS_PROG_2_reg   (*((volatile unsigned int*) DC2_SYS_DC_PC_SYS_PROG_2_reg))
#define DC2_SYS_DC_PC_SYS_PROG_2_inst_adr                                             "0x006A"
#define DC2_SYS_DC_PC_SYS_PROG_2_inst                                                 0x006A
#define DC2_SYS_DC_PC_SYS_PROG_2_sys2_hitend_cnt_shift                                (0)
#define DC2_SYS_DC_PC_SYS_PROG_2_sys2_hitend_cnt_mask                                 (0x0000FFFF)
#define DC2_SYS_DC_PC_SYS_PROG_2_sys2_hitend_cnt(data)                                (0x0000FFFF&((data)<<0))
#define DC2_SYS_DC_PC_SYS_PROG_2_sys2_hitend_cnt_src(data)                            ((0x0000FFFF&(data))>>0)
#define DC2_SYS_DC_PC_SYS_PROG_2_get_sys2_hitend_cnt(data)                            ((0x0000FFFF&(data))>>0)

#define DC2_SYS_EXSRAM_CTRL                                                           0x18003500
#define DC2_SYS_EXSRAM_CTRL_reg_addr                                                  "0xB8003500"
#define DC2_SYS_EXSRAM_CTRL_reg                                                       0xB8003500
#define set_DC2_SYS_EXSRAM_CTRL_reg(data)   (*((volatile unsigned int*) DC2_SYS_EXSRAM_CTRL_reg)=data)
#define get_DC2_SYS_EXSRAM_CTRL_reg   (*((volatile unsigned int*) DC2_SYS_EXSRAM_CTRL_reg))
#define DC2_SYS_EXSRAM_CTRL_inst_adr                                                  "0x0040"
#define DC2_SYS_EXSRAM_CTRL_inst                                                      0x0040
#define DC2_SYS_EXSRAM_CTRL_enable_shift                                              (0)
#define DC2_SYS_EXSRAM_CTRL_enable_mask                                               (0x00000001)
#define DC2_SYS_EXSRAM_CTRL_enable(data)                                              (0x00000001&((data)<<0))
#define DC2_SYS_EXSRAM_CTRL_enable_src(data)                                          ((0x00000001&(data))>>0)
#define DC2_SYS_EXSRAM_CTRL_get_enable(data)                                          ((0x00000001&(data))>>0)


#define DC2_SYS_DC_GLOBAL_SCRAMBLE_CTRL                                               0x18003510
#define DC2_SYS_DC_GLOBAL_SCRAMBLE_CTRL_reg_addr                                      "0xB8003510"
#define DC2_SYS_DC_GLOBAL_SCRAMBLE_CTRL_reg                                           0xB8003510
#define set_DC2_SYS_DC_GLOBAL_SCRAMBLE_CTRL_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_GLOBAL_SCRAMBLE_CTRL_reg)=data)
#define get_DC2_SYS_DC_GLOBAL_SCRAMBLE_CTRL_reg   (*((volatile unsigned int*) DC2_SYS_DC_GLOBAL_SCRAMBLE_CTRL_reg))
#define DC2_SYS_DC_GLOBAL_SCRAMBLE_CTRL_inst_adr                                      "0x0044"
#define DC2_SYS_DC_GLOBAL_SCRAMBLE_CTRL_inst                                          0x0044
#define DC2_SYS_DC_GLOBAL_SCRAMBLE_CTRL_global_scramble_en_shift                      (0)
#define DC2_SYS_DC_GLOBAL_SCRAMBLE_CTRL_global_scramble_en_mask                       (0x00000001)
#define DC2_SYS_DC_GLOBAL_SCRAMBLE_CTRL_global_scramble_en(data)                      (0x00000001&((data)<<0))
#define DC2_SYS_DC_GLOBAL_SCRAMBLE_CTRL_global_scramble_en_src(data)                  ((0x00000001&(data))>>0)
#define DC2_SYS_DC_GLOBAL_SCRAMBLE_CTRL_get_global_scramble_en(data)                  ((0x00000001&(data))>>0)


#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_0                                              0x18003514
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_0_reg_addr                                     "0xB8003514"
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_0_reg                                          0xB8003514
#define set_DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_0_reg)=data)
#define get_DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_0_reg))
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_0_inst_adr                                     "0x0045"
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_0_inst                                         0x0045
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_0_key1_shift                                   (16)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_0_key1_mask                                    (0xFFFF0000)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_0_key1(data)                                   (0xFFFF0000&((data)<<16))
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_0_key1_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_0_get_key1(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_0_key0_shift                                   (0)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_0_key0_mask                                    (0x0000FFFF)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_0_key0(data)                                   (0x0000FFFF&((data)<<0))
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_0_key0_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_0_get_key0(data)                               ((0x0000FFFF&(data))>>0)


#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_1                                              0x18003518
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_1_reg_addr                                     "0xB8003518"
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_1_reg                                          0xB8003518
#define set_DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_1_reg)=data)
#define get_DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_1_reg))
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_1_inst_adr                                     "0x0046"
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_1_inst                                         0x0046
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_1_key3_shift                                   (16)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_1_key3_mask                                    (0xFFFF0000)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_1_key3(data)                                   (0xFFFF0000&((data)<<16))
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_1_key3_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_1_get_key3(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_1_key2_shift                                   (0)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_1_key2_mask                                    (0x0000FFFF)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_1_key2(data)                                   (0x0000FFFF&((data)<<0))
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_1_key2_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_1_get_key2(data)                               ((0x0000FFFF&(data))>>0)


#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_2                                              0x1800351C
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_2_reg_addr                                     "0xB800351C"
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_2_reg                                          0xB800351C
#define set_DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_2_reg)=data)
#define get_DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_2_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_2_reg))
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_2_inst_adr                                     "0x0047"
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_2_inst                                         0x0047
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_2_key5_shift                                   (16)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_2_key5_mask                                    (0xFFFF0000)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_2_key5(data)                                   (0xFFFF0000&((data)<<16))
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_2_key5_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_2_get_key5(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_2_key4_shift                                   (0)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_2_key4_mask                                    (0x0000FFFF)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_2_key4(data)                                   (0x0000FFFF&((data)<<0))
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_2_key4_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_2_get_key4(data)                               ((0x0000FFFF&(data))>>0)


#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_3                                              0x18003520
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_3_reg_addr                                     "0xB8003520"
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_3_reg                                          0xB8003520
#define set_DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_3_reg)=data)
#define get_DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_3_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_3_reg))
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_3_inst_adr                                     "0x0048"
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_3_inst                                         0x0048
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_3_key7_shift                                   (16)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_3_key7_mask                                    (0xFFFF0000)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_3_key7(data)                                   (0xFFFF0000&((data)<<16))
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_3_key7_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_3_get_key7(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_3_key6_shift                                   (0)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_3_key6_mask                                    (0x0000FFFF)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_3_key6(data)                                   (0x0000FFFF&((data)<<0))
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_3_key6_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_3_get_key6(data)                               ((0x0000FFFF&(data))>>0)


#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_4                                              0x18003524
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_4_reg_addr                                     "0xB8003524"
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_4_reg                                          0xB8003524
#define set_DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_4_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_4_reg)=data)
#define get_DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_4_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_4_reg))
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_4_inst_adr                                     "0x0049"
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_4_inst                                         0x0049
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_4_key9_shift                                   (16)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_4_key9_mask                                    (0xFFFF0000)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_4_key9(data)                                   (0xFFFF0000&((data)<<16))
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_4_key9_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_4_get_key9(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_4_key8_shift                                   (0)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_4_key8_mask                                    (0x0000FFFF)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_4_key8(data)                                   (0x0000FFFF&((data)<<0))
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_4_key8_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_4_get_key8(data)                               ((0x0000FFFF&(data))>>0)


#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_5                                              0x18003528
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_5_reg_addr                                     "0xB8003528"
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_5_reg                                          0xB8003528
#define set_DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_5_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_5_reg)=data)
#define get_DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_5_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_5_reg))
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_5_inst_adr                                     "0x004A"
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_5_inst                                         0x004A
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_5_keyB_shift                                   (16)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_5_keyB_mask                                    (0xFFFF0000)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_5_keyB(data)                                   (0xFFFF0000&((data)<<16))
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_5_keyB_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_5_get_keyB(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_5_keyA_shift                                   (0)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_5_keyA_mask                                    (0x0000FFFF)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_5_keyA(data)                                   (0x0000FFFF&((data)<<0))
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_5_keyA_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_5_get_keyA(data)                               ((0x0000FFFF&(data))>>0)


#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_6                                              0x1800352C
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_6_reg_addr                                     "0xB800352C"
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_6_reg                                          0xB800352C
#define set_DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_6_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_6_reg)=data)
#define get_DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_6_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_6_reg))
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_6_inst_adr                                     "0x004B"
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_6_inst                                         0x004B
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_6_keyD_shift                                   (16)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_6_keyD_mask                                    (0xFFFF0000)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_6_keyD(data)                                   (0xFFFF0000&((data)<<16))
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_6_keyD_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_6_get_keyD(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_6_keyC_shift                                   (0)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_6_keyC_mask                                    (0x0000FFFF)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_6_keyC(data)                                   (0x0000FFFF&((data)<<0))
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_6_keyC_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC2_SYS_DC_MEM_SCRAMBLE_GLOBAL_6_get_keyC(data)                               ((0x0000FFFF&(data))>>0)


#define DC2_SYS_DC_MEM_PROTECT_CTRL                                                   0x18003540
#define DC2_SYS_DC_MEM_PROTECT_CTRL_reg_addr                                          "0xB8003540"
#define DC2_SYS_DC_MEM_PROTECT_CTRL_reg                                               0xB8003540
#define set_DC2_SYS_DC_MEM_PROTECT_CTRL_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_PROTECT_CTRL_reg)=data)
#define get_DC2_SYS_DC_MEM_PROTECT_CTRL_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_PROTECT_CTRL_reg))
#define DC2_SYS_DC_MEM_PROTECT_CTRL_inst_adr                                          "0x0050"
#define DC2_SYS_DC_MEM_PROTECT_CTRL_inst                                              0x0050
#define DC2_SYS_DC_MEM_PROTECT_CTRL_osd1_protect_3_en_shift                           (24)
#define DC2_SYS_DC_MEM_PROTECT_CTRL_osd1_protect_3_en_mask                            (0x01000000)
#define DC2_SYS_DC_MEM_PROTECT_CTRL_osd1_protect_3_en(data)                           (0x01000000&((data)<<24))
#define DC2_SYS_DC_MEM_PROTECT_CTRL_osd1_protect_3_en_src(data)                       ((0x01000000&(data))>>24)
#define DC2_SYS_DC_MEM_PROTECT_CTRL_get_osd1_protect_3_en(data)                       ((0x01000000&(data))>>24)
#define DC2_SYS_DC_MEM_PROTECT_CTRL_protect_3_en_shift                                (19)
#define DC2_SYS_DC_MEM_PROTECT_CTRL_protect_3_en_mask                                 (0x00080000)
#define DC2_SYS_DC_MEM_PROTECT_CTRL_protect_3_en(data)                                (0x00080000&((data)<<19))
#define DC2_SYS_DC_MEM_PROTECT_CTRL_protect_3_en_src(data)                            ((0x00080000&(data))>>19)
#define DC2_SYS_DC_MEM_PROTECT_CTRL_get_protect_3_en(data)                            ((0x00080000&(data))>>19)
#define DC2_SYS_DC_MEM_PROTECT_CTRL_protect_2_en_shift                                (18)
#define DC2_SYS_DC_MEM_PROTECT_CTRL_protect_2_en_mask                                 (0x00040000)
#define DC2_SYS_DC_MEM_PROTECT_CTRL_protect_2_en(data)                                (0x00040000&((data)<<18))
#define DC2_SYS_DC_MEM_PROTECT_CTRL_protect_2_en_src(data)                            ((0x00040000&(data))>>18)
#define DC2_SYS_DC_MEM_PROTECT_CTRL_get_protect_2_en(data)                            ((0x00040000&(data))>>18)
#define DC2_SYS_DC_MEM_PROTECT_CTRL_protect_1_en_shift                                (17)
#define DC2_SYS_DC_MEM_PROTECT_CTRL_protect_1_en_mask                                 (0x00020000)
#define DC2_SYS_DC_MEM_PROTECT_CTRL_protect_1_en(data)                                (0x00020000&((data)<<17))
#define DC2_SYS_DC_MEM_PROTECT_CTRL_protect_1_en_src(data)                            ((0x00020000&(data))>>17)
#define DC2_SYS_DC_MEM_PROTECT_CTRL_get_protect_1_en(data)                            ((0x00020000&(data))>>17)
#define DC2_SYS_DC_MEM_PROTECT_CTRL_protect_0_en_shift                                (16)
#define DC2_SYS_DC_MEM_PROTECT_CTRL_protect_0_en_mask                                 (0x00010000)
#define DC2_SYS_DC_MEM_PROTECT_CTRL_protect_0_en(data)                                (0x00010000&((data)<<16))
#define DC2_SYS_DC_MEM_PROTECT_CTRL_protect_0_en_src(data)                            ((0x00010000&(data))>>16)
#define DC2_SYS_DC_MEM_PROTECT_CTRL_get_protect_0_en(data)                            ((0x00010000&(data))>>16)
#define DC2_SYS_DC_MEM_PROTECT_CTRL_protect_3_scramble_en_shift                       (3)
#define DC2_SYS_DC_MEM_PROTECT_CTRL_protect_3_scramble_en_mask                        (0x00000008)
#define DC2_SYS_DC_MEM_PROTECT_CTRL_protect_3_scramble_en(data)                       (0x00000008&((data)<<3))
#define DC2_SYS_DC_MEM_PROTECT_CTRL_protect_3_scramble_en_src(data)                   ((0x00000008&(data))>>3)
#define DC2_SYS_DC_MEM_PROTECT_CTRL_get_protect_3_scramble_en(data)                   ((0x00000008&(data))>>3)
#define DC2_SYS_DC_MEM_PROTECT_CTRL_protect_2_scramble_en_shift                       (2)
#define DC2_SYS_DC_MEM_PROTECT_CTRL_protect_2_scramble_en_mask                        (0x00000004)
#define DC2_SYS_DC_MEM_PROTECT_CTRL_protect_2_scramble_en(data)                       (0x00000004&((data)<<2))
#define DC2_SYS_DC_MEM_PROTECT_CTRL_protect_2_scramble_en_src(data)                   ((0x00000004&(data))>>2)
#define DC2_SYS_DC_MEM_PROTECT_CTRL_get_protect_2_scramble_en(data)                   ((0x00000004&(data))>>2)
#define DC2_SYS_DC_MEM_PROTECT_CTRL_protect_1_scramble_en_shift                       (1)
#define DC2_SYS_DC_MEM_PROTECT_CTRL_protect_1_scramble_en_mask                        (0x00000002)
#define DC2_SYS_DC_MEM_PROTECT_CTRL_protect_1_scramble_en(data)                       (0x00000002&((data)<<1))
#define DC2_SYS_DC_MEM_PROTECT_CTRL_protect_1_scramble_en_src(data)                   ((0x00000002&(data))>>1)
#define DC2_SYS_DC_MEM_PROTECT_CTRL_get_protect_1_scramble_en(data)                   ((0x00000002&(data))>>1)
#define DC2_SYS_DC_MEM_PROTECT_CTRL_protect_0_scramble_en_shift                       (0)
#define DC2_SYS_DC_MEM_PROTECT_CTRL_protect_0_scramble_en_mask                        (0x00000001)
#define DC2_SYS_DC_MEM_PROTECT_CTRL_protect_0_scramble_en(data)                       (0x00000001&((data)<<0))
#define DC2_SYS_DC_MEM_PROTECT_CTRL_protect_0_scramble_en_src(data)                   ((0x00000001&(data))>>0)
#define DC2_SYS_DC_MEM_PROTECT_CTRL_get_protect_0_scramble_en(data)                   ((0x00000001&(data))>>0)


#define DC2_SYS_DC_SECURE_MAX                                                         0x18003544
#define DC2_SYS_DC_SECURE_MAX_reg_addr                                                "0xB8003544"
#define DC2_SYS_DC_SECURE_MAX_reg                                                     0xB8003544
#define set_DC2_SYS_DC_SECURE_MAX_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_SECURE_MAX_reg)=data)
#define get_DC2_SYS_DC_SECURE_MAX_reg   (*((volatile unsigned int*) DC2_SYS_DC_SECURE_MAX_reg))
#define DC2_SYS_DC_SECURE_MAX_inst_adr                                                "0x0051"
#define DC2_SYS_DC_SECURE_MAX_inst                                                    0x0051
#define DC2_SYS_DC_SECURE_MAX_addr_shift                                              (12)
#define DC2_SYS_DC_SECURE_MAX_addr_mask                                               (0xFFFFF000)
#define DC2_SYS_DC_SECURE_MAX_addr(data)                                              (0xFFFFF000&((data)<<12))
#define DC2_SYS_DC_SECURE_MAX_addr_src(data)                                          ((0xFFFFF000&(data))>>12)
#define DC2_SYS_DC_SECURE_MAX_get_addr(data)                                          ((0xFFFFF000&(data))>>12)
#define DC2_SYS_DC_SECURE_MAX_y_limit_shift                                           (1)
#define DC2_SYS_DC_SECURE_MAX_y_limit_mask                                            (0x00000002)
#define DC2_SYS_DC_SECURE_MAX_y_limit(data)                                           (0x00000002&((data)<<1))
#define DC2_SYS_DC_SECURE_MAX_y_limit_src(data)                                       ((0x00000002&(data))>>1)
#define DC2_SYS_DC_SECURE_MAX_get_y_limit(data)                                       ((0x00000002&(data))>>1)


#define DC2_SYS_DC_MEM_PROTECT_START_0                                                0x18003550
#define DC2_SYS_DC_MEM_PROTECT_START_1                                                0x18003554
#define DC2_SYS_DC_MEM_PROTECT_START_2                                                0x18003558
#define DC2_SYS_DC_MEM_PROTECT_START_3                                                0x1800355C
#define DC2_SYS_DC_MEM_PROTECT_START_0_reg_addr                                       "0xB8003550"
#define DC2_SYS_DC_MEM_PROTECT_START_1_reg_addr                                       "0xB8003554"
#define DC2_SYS_DC_MEM_PROTECT_START_2_reg_addr                                       "0xB8003558"
#define DC2_SYS_DC_MEM_PROTECT_START_3_reg_addr                                       "0xB800355C"
#define DC2_SYS_DC_MEM_PROTECT_START_0_reg                                            0xB8003550
#define DC2_SYS_DC_MEM_PROTECT_START_1_reg                                            0xB8003554
#define DC2_SYS_DC_MEM_PROTECT_START_2_reg                                            0xB8003558
#define DC2_SYS_DC_MEM_PROTECT_START_3_reg                                            0xB800355C
#define set_DC2_SYS_DC_MEM_PROTECT_START_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_PROTECT_START_0_reg)=data)
#define set_DC2_SYS_DC_MEM_PROTECT_START_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_PROTECT_START_1_reg)=data)
#define set_DC2_SYS_DC_MEM_PROTECT_START_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_PROTECT_START_2_reg)=data)
#define set_DC2_SYS_DC_MEM_PROTECT_START_3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_PROTECT_START_3_reg)=data)
#define get_DC2_SYS_DC_MEM_PROTECT_START_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_PROTECT_START_0_reg))
#define get_DC2_SYS_DC_MEM_PROTECT_START_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_PROTECT_START_1_reg))
#define get_DC2_SYS_DC_MEM_PROTECT_START_2_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_PROTECT_START_2_reg))
#define get_DC2_SYS_DC_MEM_PROTECT_START_3_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_PROTECT_START_3_reg))
#define DC2_SYS_DC_MEM_PROTECT_START_0_inst_adr                                       "0x0054"
#define DC2_SYS_DC_MEM_PROTECT_START_1_inst_adr                                       "0x0055"
#define DC2_SYS_DC_MEM_PROTECT_START_2_inst_adr                                       "0x0056"
#define DC2_SYS_DC_MEM_PROTECT_START_3_inst_adr                                       "0x0057"
#define DC2_SYS_DC_MEM_PROTECT_START_0_inst                                           0x0054
#define DC2_SYS_DC_MEM_PROTECT_START_1_inst                                           0x0055
#define DC2_SYS_DC_MEM_PROTECT_START_2_inst                                           0x0056
#define DC2_SYS_DC_MEM_PROTECT_START_3_inst                                           0x0057
#define DC2_SYS_DC_MEM_PROTECT_START_addr_shift                                       (12)
#define DC2_SYS_DC_MEM_PROTECT_START_addr_mask                                        (0xFFFFF000)
#define DC2_SYS_DC_MEM_PROTECT_START_addr(data)                                       (0xFFFFF000&((data)<<12))
#define DC2_SYS_DC_MEM_PROTECT_START_addr_src(data)                                   ((0xFFFFF000&(data))>>12)
#define DC2_SYS_DC_MEM_PROTECT_START_get_addr(data)                                   ((0xFFFFF000&(data))>>12)


#define DC2_SYS_DC_MEM_PROTECT_END_0                                                  0x18003560
#define DC2_SYS_DC_MEM_PROTECT_END_1                                                  0x18003564
#define DC2_SYS_DC_MEM_PROTECT_END_2                                                  0x18003568
#define DC2_SYS_DC_MEM_PROTECT_END_3                                                  0x1800356C
#define DC2_SYS_DC_MEM_PROTECT_END_0_reg_addr                                         "0xB8003560"
#define DC2_SYS_DC_MEM_PROTECT_END_1_reg_addr                                         "0xB8003564"
#define DC2_SYS_DC_MEM_PROTECT_END_2_reg_addr                                         "0xB8003568"
#define DC2_SYS_DC_MEM_PROTECT_END_3_reg_addr                                         "0xB800356C"
#define DC2_SYS_DC_MEM_PROTECT_END_0_reg                                              0xB8003560
#define DC2_SYS_DC_MEM_PROTECT_END_1_reg                                              0xB8003564
#define DC2_SYS_DC_MEM_PROTECT_END_2_reg                                              0xB8003568
#define DC2_SYS_DC_MEM_PROTECT_END_3_reg                                              0xB800356C
#define set_DC2_SYS_DC_MEM_PROTECT_END_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_PROTECT_END_0_reg)=data)
#define set_DC2_SYS_DC_MEM_PROTECT_END_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_PROTECT_END_1_reg)=data)
#define set_DC2_SYS_DC_MEM_PROTECT_END_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_PROTECT_END_2_reg)=data)
#define set_DC2_SYS_DC_MEM_PROTECT_END_3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_PROTECT_END_3_reg)=data)
#define get_DC2_SYS_DC_MEM_PROTECT_END_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_PROTECT_END_0_reg))
#define get_DC2_SYS_DC_MEM_PROTECT_END_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_PROTECT_END_1_reg))
#define get_DC2_SYS_DC_MEM_PROTECT_END_2_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_PROTECT_END_2_reg))
#define get_DC2_SYS_DC_MEM_PROTECT_END_3_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_PROTECT_END_3_reg))
#define DC2_SYS_DC_MEM_PROTECT_END_0_inst_adr                                         "0x0058"
#define DC2_SYS_DC_MEM_PROTECT_END_1_inst_adr                                         "0x0059"
#define DC2_SYS_DC_MEM_PROTECT_END_2_inst_adr                                         "0x005A"
#define DC2_SYS_DC_MEM_PROTECT_END_3_inst_adr                                         "0x005B"
#define DC2_SYS_DC_MEM_PROTECT_END_0_inst                                             0x0058
#define DC2_SYS_DC_MEM_PROTECT_END_1_inst                                             0x0059
#define DC2_SYS_DC_MEM_PROTECT_END_2_inst                                             0x005A
#define DC2_SYS_DC_MEM_PROTECT_END_3_inst                                             0x005B
#define DC2_SYS_DC_MEM_PROTECT_END_addr_shift                                         (12)
#define DC2_SYS_DC_MEM_PROTECT_END_addr_mask                                          (0xFFFFF000)
#define DC2_SYS_DC_MEM_PROTECT_END_addr(data)                                         (0xFFFFF000&((data)<<12))
#define DC2_SYS_DC_MEM_PROTECT_END_addr_src(data)                                     ((0xFFFFF000&(data))>>12)
#define DC2_SYS_DC_MEM_PROTECT_END_get_addr(data)                                     ((0xFFFFF000&(data))>>12)


#define DC2_SYS_DC_KCPU_REGION_0                                                      0x18003570
#define DC2_SYS_DC_KCPU_REGION_1                                                      0x18003574
#define DC2_SYS_DC_KCPU_REGION_2                                                      0x18003578
#define DC2_SYS_DC_KCPU_REGION_3                                                      0x1800357C
#define DC2_SYS_DC_KCPU_REGION_0_reg_addr                                             "0xB8003570"
#define DC2_SYS_DC_KCPU_REGION_1_reg_addr                                             "0xB8003574"
#define DC2_SYS_DC_KCPU_REGION_2_reg_addr                                             "0xB8003578"
#define DC2_SYS_DC_KCPU_REGION_3_reg_addr                                             "0xB800357C"
#define DC2_SYS_DC_KCPU_REGION_0_reg                                                  0xB8003570
#define DC2_SYS_DC_KCPU_REGION_1_reg                                                  0xB8003574
#define DC2_SYS_DC_KCPU_REGION_2_reg                                                  0xB8003578
#define DC2_SYS_DC_KCPU_REGION_3_reg                                                  0xB800357C
#define set_DC2_SYS_DC_KCPU_REGION_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_KCPU_REGION_0_reg)=data)
#define set_DC2_SYS_DC_KCPU_REGION_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_KCPU_REGION_1_reg)=data)
#define set_DC2_SYS_DC_KCPU_REGION_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_KCPU_REGION_2_reg)=data)
#define set_DC2_SYS_DC_KCPU_REGION_3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_KCPU_REGION_3_reg)=data)
#define get_DC2_SYS_DC_KCPU_REGION_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_KCPU_REGION_0_reg))
#define get_DC2_SYS_DC_KCPU_REGION_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_KCPU_REGION_1_reg))
#define get_DC2_SYS_DC_KCPU_REGION_2_reg   (*((volatile unsigned int*) DC2_SYS_DC_KCPU_REGION_2_reg))
#define get_DC2_SYS_DC_KCPU_REGION_3_reg   (*((volatile unsigned int*) DC2_SYS_DC_KCPU_REGION_3_reg))
#define DC2_SYS_DC_KCPU_REGION_0_inst_adr                                             "0x005C"
#define DC2_SYS_DC_KCPU_REGION_1_inst_adr                                             "0x005D"
#define DC2_SYS_DC_KCPU_REGION_2_inst_adr                                             "0x005E"
#define DC2_SYS_DC_KCPU_REGION_3_inst_adr                                             "0x005F"
#define DC2_SYS_DC_KCPU_REGION_0_inst                                                 0x005C
#define DC2_SYS_DC_KCPU_REGION_1_inst                                                 0x005D
#define DC2_SYS_DC_KCPU_REGION_2_inst                                                 0x005E
#define DC2_SYS_DC_KCPU_REGION_3_inst                                                 0x005F
#define DC2_SYS_DC_KCPU_REGION_tp_kc_shift                                            (4)
#define DC2_SYS_DC_KCPU_REGION_tp_kc_mask                                             (0x00000010)
#define DC2_SYS_DC_KCPU_REGION_tp_kc(data)                                            (0x00000010&((data)<<4))
#define DC2_SYS_DC_KCPU_REGION_tp_kc_src(data)                                        ((0x00000010&(data))>>4)
#define DC2_SYS_DC_KCPU_REGION_get_tp_kc(data)                                        ((0x00000010&(data))>>4)
#define DC2_SYS_DC_KCPU_REGION_emmc_kc_shift                                          (3)
#define DC2_SYS_DC_KCPU_REGION_emmc_kc_mask                                           (0x00000008)
#define DC2_SYS_DC_KCPU_REGION_emmc_kc(data)                                          (0x00000008&((data)<<3))
#define DC2_SYS_DC_KCPU_REGION_emmc_kc_src(data)                                      ((0x00000008&(data))>>3)
#define DC2_SYS_DC_KCPU_REGION_get_emmc_kc(data)                                      ((0x00000008&(data))>>3)
#define DC2_SYS_DC_KCPU_REGION_nf_kc_shift                                            (2)
#define DC2_SYS_DC_KCPU_REGION_nf_kc_mask                                             (0x00000004)
#define DC2_SYS_DC_KCPU_REGION_nf_kc(data)                                            (0x00000004&((data)<<2))
#define DC2_SYS_DC_KCPU_REGION_nf_kc_src(data)                                        ((0x00000004&(data))>>2)
#define DC2_SYS_DC_KCPU_REGION_get_nf_kc(data)                                        ((0x00000004&(data))>>2)
#define DC2_SYS_DC_KCPU_REGION_cp_kc_shift                                            (1)
#define DC2_SYS_DC_KCPU_REGION_cp_kc_mask                                             (0x00000002)
#define DC2_SYS_DC_KCPU_REGION_cp_kc(data)                                            (0x00000002&((data)<<1))
#define DC2_SYS_DC_KCPU_REGION_cp_kc_src(data)                                        ((0x00000002&(data))>>1)
#define DC2_SYS_DC_KCPU_REGION_get_cp_kc(data)                                        ((0x00000002&(data))>>1)
#define DC2_SYS_DC_KCPU_REGION_md_kc_shift                                            (0)
#define DC2_SYS_DC_KCPU_REGION_md_kc_mask                                             (0x00000001)
#define DC2_SYS_DC_KCPU_REGION_md_kc(data)                                            (0x00000001&((data)<<0))
#define DC2_SYS_DC_KCPU_REGION_md_kc_src(data)                                        ((0x00000001&(data))>>0)
#define DC2_SYS_DC_KCPU_REGION_get_md_kc(data)                                        ((0x00000001&(data))>>0)


#define DC2_SYS_DC_MEM_CONTENT_CTRL                                                   0x180035E0
#define DC2_SYS_DC_MEM_CONTENT_CTRL_reg_addr                                          "0xB80035E0"
#define DC2_SYS_DC_MEM_CONTENT_CTRL_reg                                               0xB80035E0
#define set_DC2_SYS_DC_MEM_CONTENT_CTRL_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_CONTENT_CTRL_reg)=data)
#define get_DC2_SYS_DC_MEM_CONTENT_CTRL_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_CONTENT_CTRL_reg))
#define DC2_SYS_DC_MEM_CONTENT_CTRL_inst_adr                                          "0x0078"
#define DC2_SYS_DC_MEM_CONTENT_CTRL_inst                                              0x0078
#define DC2_SYS_DC_MEM_CONTENT_CTRL_content_7_en_shift                                (23)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_content_7_en_mask                                 (0x00800000)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_content_7_en(data)                                (0x00800000&((data)<<23))
#define DC2_SYS_DC_MEM_CONTENT_CTRL_content_7_en_src(data)                            ((0x00800000&(data))>>23)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_get_content_7_en(data)                            ((0x00800000&(data))>>23)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_content_6_en_shift                                (22)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_content_6_en_mask                                 (0x00400000)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_content_6_en(data)                                (0x00400000&((data)<<22))
#define DC2_SYS_DC_MEM_CONTENT_CTRL_content_6_en_src(data)                            ((0x00400000&(data))>>22)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_get_content_6_en(data)                            ((0x00400000&(data))>>22)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_content_5_en_shift                                (21)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_content_5_en_mask                                 (0x00200000)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_content_5_en(data)                                (0x00200000&((data)<<21))
#define DC2_SYS_DC_MEM_CONTENT_CTRL_content_5_en_src(data)                            ((0x00200000&(data))>>21)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_get_content_5_en(data)                            ((0x00200000&(data))>>21)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_content_4_en_shift                                (20)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_content_4_en_mask                                 (0x00100000)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_content_4_en(data)                                (0x00100000&((data)<<20))
#define DC2_SYS_DC_MEM_CONTENT_CTRL_content_4_en_src(data)                            ((0x00100000&(data))>>20)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_get_content_4_en(data)                            ((0x00100000&(data))>>20)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_content_3_en_shift                                (19)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_content_3_en_mask                                 (0x00080000)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_content_3_en(data)                                (0x00080000&((data)<<19))
#define DC2_SYS_DC_MEM_CONTENT_CTRL_content_3_en_src(data)                            ((0x00080000&(data))>>19)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_get_content_3_en(data)                            ((0x00080000&(data))>>19)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_content_2_en_shift                                (18)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_content_2_en_mask                                 (0x00040000)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_content_2_en(data)                                (0x00040000&((data)<<18))
#define DC2_SYS_DC_MEM_CONTENT_CTRL_content_2_en_src(data)                            ((0x00040000&(data))>>18)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_get_content_2_en(data)                            ((0x00040000&(data))>>18)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_content_1_en_shift                                (17)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_content_1_en_mask                                 (0x00020000)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_content_1_en(data)                                (0x00020000&((data)<<17))
#define DC2_SYS_DC_MEM_CONTENT_CTRL_content_1_en_src(data)                            ((0x00020000&(data))>>17)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_get_content_1_en(data)                            ((0x00020000&(data))>>17)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_content_0_en_shift                                (16)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_content_0_en_mask                                 (0x00010000)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_content_0_en(data)                                (0x00010000&((data)<<16))
#define DC2_SYS_DC_MEM_CONTENT_CTRL_content_0_en_src(data)                            ((0x00010000&(data))>>16)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_get_content_0_en(data)                            ((0x00010000&(data))>>16)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_scramble_7_en_shift                               (7)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_scramble_7_en_mask                                (0x00000080)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_scramble_7_en(data)                               (0x00000080&((data)<<7))
#define DC2_SYS_DC_MEM_CONTENT_CTRL_scramble_7_en_src(data)                           ((0x00000080&(data))>>7)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_get_scramble_7_en(data)                           ((0x00000080&(data))>>7)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_scramble_6_en_shift                               (6)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_scramble_6_en_mask                                (0x00000040)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_scramble_6_en(data)                               (0x00000040&((data)<<6))
#define DC2_SYS_DC_MEM_CONTENT_CTRL_scramble_6_en_src(data)                           ((0x00000040&(data))>>6)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_get_scramble_6_en(data)                           ((0x00000040&(data))>>6)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_scramble_5_en_shift                               (5)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_scramble_5_en_mask                                (0x00000020)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_scramble_5_en(data)                               (0x00000020&((data)<<5))
#define DC2_SYS_DC_MEM_CONTENT_CTRL_scramble_5_en_src(data)                           ((0x00000020&(data))>>5)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_get_scramble_5_en(data)                           ((0x00000020&(data))>>5)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_scramble_4_en_shift                               (4)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_scramble_4_en_mask                                (0x00000010)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_scramble_4_en(data)                               (0x00000010&((data)<<4))
#define DC2_SYS_DC_MEM_CONTENT_CTRL_scramble_4_en_src(data)                           ((0x00000010&(data))>>4)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_get_scramble_4_en(data)                           ((0x00000010&(data))>>4)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_scramble_3_en_shift                               (3)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_scramble_3_en_mask                                (0x00000008)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_scramble_3_en(data)                               (0x00000008&((data)<<3))
#define DC2_SYS_DC_MEM_CONTENT_CTRL_scramble_3_en_src(data)                           ((0x00000008&(data))>>3)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_get_scramble_3_en(data)                           ((0x00000008&(data))>>3)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_scramble_2_en_shift                               (2)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_scramble_2_en_mask                                (0x00000004)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_scramble_2_en(data)                               (0x00000004&((data)<<2))
#define DC2_SYS_DC_MEM_CONTENT_CTRL_scramble_2_en_src(data)                           ((0x00000004&(data))>>2)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_get_scramble_2_en(data)                           ((0x00000004&(data))>>2)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_scramble_1_en_shift                               (1)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_scramble_1_en_mask                                (0x00000002)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_scramble_1_en(data)                               (0x00000002&((data)<<1))
#define DC2_SYS_DC_MEM_CONTENT_CTRL_scramble_1_en_src(data)                           ((0x00000002&(data))>>1)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_get_scramble_1_en(data)                           ((0x00000002&(data))>>1)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_scramble_0_en_shift                               (0)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_scramble_0_en_mask                                (0x00000001)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_scramble_0_en(data)                               (0x00000001&((data)<<0))
#define DC2_SYS_DC_MEM_CONTENT_CTRL_scramble_0_en_src(data)                           ((0x00000001&(data))>>0)
#define DC2_SYS_DC_MEM_CONTENT_CTRL_get_scramble_0_en(data)                           ((0x00000001&(data))>>0)


#define DC2_SYS_DC_SCRAMBLE_ACCESS_0                                                  0x18003600
#define DC2_SYS_DC_SCRAMBLE_ACCESS_1                                                  0x18003604
#define DC2_SYS_DC_SCRAMBLE_ACCESS_2                                                  0x18003608
#define DC2_SYS_DC_SCRAMBLE_ACCESS_3                                                  0x1800360C
#define DC2_SYS_DC_SCRAMBLE_ACCESS_4                                                  0x18003610
#define DC2_SYS_DC_SCRAMBLE_ACCESS_5                                                  0x18003614
#define DC2_SYS_DC_SCRAMBLE_ACCESS_6                                                  0x18003618
#define DC2_SYS_DC_SCRAMBLE_ACCESS_7                                                  0x1800361C
#define DC2_SYS_DC_SCRAMBLE_ACCESS_0_reg_addr                                         "0xB8003600"
#define DC2_SYS_DC_SCRAMBLE_ACCESS_1_reg_addr                                         "0xB8003604"
#define DC2_SYS_DC_SCRAMBLE_ACCESS_2_reg_addr                                         "0xB8003608"
#define DC2_SYS_DC_SCRAMBLE_ACCESS_3_reg_addr                                         "0xB800360C"
#define DC2_SYS_DC_SCRAMBLE_ACCESS_4_reg_addr                                         "0xB8003610"
#define DC2_SYS_DC_SCRAMBLE_ACCESS_5_reg_addr                                         "0xB8003614"
#define DC2_SYS_DC_SCRAMBLE_ACCESS_6_reg_addr                                         "0xB8003618"
#define DC2_SYS_DC_SCRAMBLE_ACCESS_7_reg_addr                                         "0xB800361C"
#define DC2_SYS_DC_SCRAMBLE_ACCESS_0_reg                                              0xB8003600
#define DC2_SYS_DC_SCRAMBLE_ACCESS_1_reg                                              0xB8003604
#define DC2_SYS_DC_SCRAMBLE_ACCESS_2_reg                                              0xB8003608
#define DC2_SYS_DC_SCRAMBLE_ACCESS_3_reg                                              0xB800360C
#define DC2_SYS_DC_SCRAMBLE_ACCESS_4_reg                                              0xB8003610
#define DC2_SYS_DC_SCRAMBLE_ACCESS_5_reg                                              0xB8003614
#define DC2_SYS_DC_SCRAMBLE_ACCESS_6_reg                                              0xB8003618
#define DC2_SYS_DC_SCRAMBLE_ACCESS_7_reg                                              0xB800361C
#define set_DC2_SYS_DC_SCRAMBLE_ACCESS_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_SCRAMBLE_ACCESS_0_reg)=data)
#define set_DC2_SYS_DC_SCRAMBLE_ACCESS_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_SCRAMBLE_ACCESS_1_reg)=data)
#define set_DC2_SYS_DC_SCRAMBLE_ACCESS_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_SCRAMBLE_ACCESS_2_reg)=data)
#define set_DC2_SYS_DC_SCRAMBLE_ACCESS_3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_SCRAMBLE_ACCESS_3_reg)=data)
#define set_DC2_SYS_DC_SCRAMBLE_ACCESS_4_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_SCRAMBLE_ACCESS_4_reg)=data)
#define set_DC2_SYS_DC_SCRAMBLE_ACCESS_5_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_SCRAMBLE_ACCESS_5_reg)=data)
#define set_DC2_SYS_DC_SCRAMBLE_ACCESS_6_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_SCRAMBLE_ACCESS_6_reg)=data)
#define set_DC2_SYS_DC_SCRAMBLE_ACCESS_7_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_SCRAMBLE_ACCESS_7_reg)=data)
#define get_DC2_SYS_DC_SCRAMBLE_ACCESS_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_SCRAMBLE_ACCESS_0_reg))
#define get_DC2_SYS_DC_SCRAMBLE_ACCESS_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_SCRAMBLE_ACCESS_1_reg))
#define get_DC2_SYS_DC_SCRAMBLE_ACCESS_2_reg   (*((volatile unsigned int*) DC2_SYS_DC_SCRAMBLE_ACCESS_2_reg))
#define get_DC2_SYS_DC_SCRAMBLE_ACCESS_3_reg   (*((volatile unsigned int*) DC2_SYS_DC_SCRAMBLE_ACCESS_3_reg))
#define get_DC2_SYS_DC_SCRAMBLE_ACCESS_4_reg   (*((volatile unsigned int*) DC2_SYS_DC_SCRAMBLE_ACCESS_4_reg))
#define get_DC2_SYS_DC_SCRAMBLE_ACCESS_5_reg   (*((volatile unsigned int*) DC2_SYS_DC_SCRAMBLE_ACCESS_5_reg))
#define get_DC2_SYS_DC_SCRAMBLE_ACCESS_6_reg   (*((volatile unsigned int*) DC2_SYS_DC_SCRAMBLE_ACCESS_6_reg))
#define get_DC2_SYS_DC_SCRAMBLE_ACCESS_7_reg   (*((volatile unsigned int*) DC2_SYS_DC_SCRAMBLE_ACCESS_7_reg))
#define DC2_SYS_DC_SCRAMBLE_ACCESS_0_inst_adr                                         "0x0080"
#define DC2_SYS_DC_SCRAMBLE_ACCESS_1_inst_adr                                         "0x0081"
#define DC2_SYS_DC_SCRAMBLE_ACCESS_2_inst_adr                                         "0x0082"
#define DC2_SYS_DC_SCRAMBLE_ACCESS_3_inst_adr                                         "0x0083"
#define DC2_SYS_DC_SCRAMBLE_ACCESS_4_inst_adr                                         "0x0084"
#define DC2_SYS_DC_SCRAMBLE_ACCESS_5_inst_adr                                         "0x0085"
#define DC2_SYS_DC_SCRAMBLE_ACCESS_6_inst_adr                                         "0x0086"
#define DC2_SYS_DC_SCRAMBLE_ACCESS_7_inst_adr                                         "0x0087"
#define DC2_SYS_DC_SCRAMBLE_ACCESS_0_inst                                             0x0080
#define DC2_SYS_DC_SCRAMBLE_ACCESS_1_inst                                             0x0081
#define DC2_SYS_DC_SCRAMBLE_ACCESS_2_inst                                             0x0082
#define DC2_SYS_DC_SCRAMBLE_ACCESS_3_inst                                             0x0083
#define DC2_SYS_DC_SCRAMBLE_ACCESS_4_inst                                             0x0084
#define DC2_SYS_DC_SCRAMBLE_ACCESS_5_inst                                             0x0085
#define DC2_SYS_DC_SCRAMBLE_ACCESS_6_inst                                             0x0086
#define DC2_SYS_DC_SCRAMBLE_ACCESS_7_inst                                             0x0087
#define DC2_SYS_DC_SCRAMBLE_ACCESS_tp_kc_shift                                        (13)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_tp_kc_mask                                         (0x00002000)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_tp_kc(data)                                        (0x00002000&((data)<<13))
#define DC2_SYS_DC_SCRAMBLE_ACCESS_tp_kc_src(data)                                    ((0x00002000&(data))>>13)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_get_tp_kc(data)                                    ((0x00002000&(data))>>13)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_emmc_kc_shift                                      (12)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_emmc_kc_mask                                       (0x00001000)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_emmc_kc(data)                                      (0x00001000&((data)<<12))
#define DC2_SYS_DC_SCRAMBLE_ACCESS_emmc_kc_src(data)                                  ((0x00001000&(data))>>12)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_get_emmc_kc(data)                                  ((0x00001000&(data))>>12)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_acpu_shift                                         (10)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_acpu_mask                                          (0x00000C00)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_acpu(data)                                         (0x00000C00&((data)<<10))
#define DC2_SYS_DC_SCRAMBLE_ACCESS_acpu_src(data)                                     ((0x00000C00&(data))>>10)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_get_acpu(data)                                     ((0x00000C00&(data))>>10)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_vcpu_shift                                         (8)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_vcpu_mask                                          (0x00000300)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_vcpu(data)                                         (0x00000300&((data)<<8))
#define DC2_SYS_DC_SCRAMBLE_ACCESS_vcpu_src(data)                                     ((0x00000300&(data))>>8)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_get_vcpu(data)                                     ((0x00000300&(data))>>8)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_nf_kc_shift                                        (7)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_nf_kc_mask                                         (0x00000080)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_nf_kc(data)                                        (0x00000080&((data)<<7))
#define DC2_SYS_DC_SCRAMBLE_ACCESS_nf_kc_src(data)                                    ((0x00000080&(data))>>7)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_get_nf_kc(data)                                    ((0x00000080&(data))>>7)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_ve_shift                                           (6)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_ve_mask                                            (0x00000040)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_ve(data)                                           (0x00000040&((data)<<6))
#define DC2_SYS_DC_SCRAMBLE_ACCESS_ve_src(data)                                       ((0x00000040&(data))>>6)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_get_ve(data)                                       ((0x00000040&(data))>>6)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_vde_shift                                          (5)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_vde_mask                                           (0x00000020)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_vde(data)                                          (0x00000020&((data)<<5))
#define DC2_SYS_DC_SCRAMBLE_ACCESS_vde_src(data)                                      ((0x00000020&(data))>>5)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_get_vde(data)                                      ((0x00000020&(data))>>5)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_ade_shift                                          (4)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_ade_mask                                           (0x00000010)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_ade(data)                                          (0x00000010&((data)<<4))
#define DC2_SYS_DC_SCRAMBLE_ACCESS_ade_src(data)                                      ((0x00000010&(data))>>4)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_get_ade(data)                                      ((0x00000010&(data))>>4)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_ae_shift                                           (3)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_ae_mask                                            (0x00000008)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_ae(data)                                           (0x00000008&((data)<<3))
#define DC2_SYS_DC_SCRAMBLE_ACCESS_ae_src(data)                                       ((0x00000008&(data))>>3)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_get_ae(data)                                       ((0x00000008&(data))>>3)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_md_kc_shift                                        (2)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_md_kc_mask                                         (0x00000004)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_md_kc(data)                                        (0x00000004&((data)<<2))
#define DC2_SYS_DC_SCRAMBLE_ACCESS_md_kc_src(data)                                    ((0x00000004&(data))>>2)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_get_md_kc(data)                                    ((0x00000004&(data))>>2)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_cp_kc_shift                                        (1)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_cp_kc_mask                                         (0x00000002)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_cp_kc(data)                                        (0x00000002&((data)<<1))
#define DC2_SYS_DC_SCRAMBLE_ACCESS_cp_kc_src(data)                                    ((0x00000002&(data))>>1)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_get_cp_kc(data)                                    ((0x00000002&(data))>>1)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_md_vc_shift                                        (0)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_md_vc_mask                                         (0x00000001)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_md_vc(data)                                        (0x00000001&((data)<<0))
#define DC2_SYS_DC_SCRAMBLE_ACCESS_md_vc_src(data)                                    ((0x00000001&(data))>>0)
#define DC2_SYS_DC_SCRAMBLE_ACCESS_get_md_vc(data)                                    ((0x00000001&(data))>>0)


#define DC2_SYS_DC_MEM_SCRAMBLE_START_0                                               0x18003620
#define DC2_SYS_DC_MEM_SCRAMBLE_START_1                                               0x18003624
#define DC2_SYS_DC_MEM_SCRAMBLE_START_2                                               0x18003628
#define DC2_SYS_DC_MEM_SCRAMBLE_START_3                                               0x1800362C
#define DC2_SYS_DC_MEM_SCRAMBLE_START_4                                               0x18003630
#define DC2_SYS_DC_MEM_SCRAMBLE_START_5                                               0x18003634
#define DC2_SYS_DC_MEM_SCRAMBLE_START_6                                               0x18003638
#define DC2_SYS_DC_MEM_SCRAMBLE_START_7                                               0x1800363C
#define DC2_SYS_DC_MEM_SCRAMBLE_START_0_reg_addr                                      "0xB8003620"
#define DC2_SYS_DC_MEM_SCRAMBLE_START_1_reg_addr                                      "0xB8003624"
#define DC2_SYS_DC_MEM_SCRAMBLE_START_2_reg_addr                                      "0xB8003628"
#define DC2_SYS_DC_MEM_SCRAMBLE_START_3_reg_addr                                      "0xB800362C"
#define DC2_SYS_DC_MEM_SCRAMBLE_START_4_reg_addr                                      "0xB8003630"
#define DC2_SYS_DC_MEM_SCRAMBLE_START_5_reg_addr                                      "0xB8003634"
#define DC2_SYS_DC_MEM_SCRAMBLE_START_6_reg_addr                                      "0xB8003638"
#define DC2_SYS_DC_MEM_SCRAMBLE_START_7_reg_addr                                      "0xB800363C"
#define DC2_SYS_DC_MEM_SCRAMBLE_START_0_reg                                           0xB8003620
#define DC2_SYS_DC_MEM_SCRAMBLE_START_1_reg                                           0xB8003624
#define DC2_SYS_DC_MEM_SCRAMBLE_START_2_reg                                           0xB8003628
#define DC2_SYS_DC_MEM_SCRAMBLE_START_3_reg                                           0xB800362C
#define DC2_SYS_DC_MEM_SCRAMBLE_START_4_reg                                           0xB8003630
#define DC2_SYS_DC_MEM_SCRAMBLE_START_5_reg                                           0xB8003634
#define DC2_SYS_DC_MEM_SCRAMBLE_START_6_reg                                           0xB8003638
#define DC2_SYS_DC_MEM_SCRAMBLE_START_7_reg                                           0xB800363C
#define set_DC2_SYS_DC_MEM_SCRAMBLE_START_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_START_0_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_START_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_START_1_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_START_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_START_2_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_START_3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_START_3_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_START_4_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_START_4_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_START_5_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_START_5_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_START_6_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_START_6_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_START_7_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_START_7_reg)=data)
#define get_DC2_SYS_DC_MEM_SCRAMBLE_START_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_START_0_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_START_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_START_1_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_START_2_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_START_2_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_START_3_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_START_3_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_START_4_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_START_4_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_START_5_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_START_5_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_START_6_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_START_6_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_START_7_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_START_7_reg))
#define DC2_SYS_DC_MEM_SCRAMBLE_START_0_inst_adr                                      "0x0088"
#define DC2_SYS_DC_MEM_SCRAMBLE_START_1_inst_adr                                      "0x0089"
#define DC2_SYS_DC_MEM_SCRAMBLE_START_2_inst_adr                                      "0x008A"
#define DC2_SYS_DC_MEM_SCRAMBLE_START_3_inst_adr                                      "0x008B"
#define DC2_SYS_DC_MEM_SCRAMBLE_START_4_inst_adr                                      "0x008C"
#define DC2_SYS_DC_MEM_SCRAMBLE_START_5_inst_adr                                      "0x008D"
#define DC2_SYS_DC_MEM_SCRAMBLE_START_6_inst_adr                                      "0x008E"
#define DC2_SYS_DC_MEM_SCRAMBLE_START_7_inst_adr                                      "0x008F"
#define DC2_SYS_DC_MEM_SCRAMBLE_START_0_inst                                          0x0088
#define DC2_SYS_DC_MEM_SCRAMBLE_START_1_inst                                          0x0089
#define DC2_SYS_DC_MEM_SCRAMBLE_START_2_inst                                          0x008A
#define DC2_SYS_DC_MEM_SCRAMBLE_START_3_inst                                          0x008B
#define DC2_SYS_DC_MEM_SCRAMBLE_START_4_inst                                          0x008C
#define DC2_SYS_DC_MEM_SCRAMBLE_START_5_inst                                          0x008D
#define DC2_SYS_DC_MEM_SCRAMBLE_START_6_inst                                          0x008E
#define DC2_SYS_DC_MEM_SCRAMBLE_START_7_inst                                          0x008F
#define DC2_SYS_DC_MEM_SCRAMBLE_START_addr_shift                                      (12)
#define DC2_SYS_DC_MEM_SCRAMBLE_START_addr_mask                                       (0xFFFFF000)
#define DC2_SYS_DC_MEM_SCRAMBLE_START_addr(data)                                      (0xFFFFF000&((data)<<12))
#define DC2_SYS_DC_MEM_SCRAMBLE_START_addr_src(data)                                  ((0xFFFFF000&(data))>>12)
#define DC2_SYS_DC_MEM_SCRAMBLE_START_get_addr(data)                                  ((0xFFFFF000&(data))>>12)


#define DC2_SYS_DC_MEM_SCRAMBLE_END_0                                                 0x18003640
#define DC2_SYS_DC_MEM_SCRAMBLE_END_1                                                 0x18003644
#define DC2_SYS_DC_MEM_SCRAMBLE_END_2                                                 0x18003648
#define DC2_SYS_DC_MEM_SCRAMBLE_END_3                                                 0x1800364C
#define DC2_SYS_DC_MEM_SCRAMBLE_END_4                                                 0x18003650
#define DC2_SYS_DC_MEM_SCRAMBLE_END_5                                                 0x18003654
#define DC2_SYS_DC_MEM_SCRAMBLE_END_6                                                 0x18003658
#define DC2_SYS_DC_MEM_SCRAMBLE_END_7                                                 0x1800365C
#define DC2_SYS_DC_MEM_SCRAMBLE_END_0_reg_addr                                        "0xB8003640"
#define DC2_SYS_DC_MEM_SCRAMBLE_END_1_reg_addr                                        "0xB8003644"
#define DC2_SYS_DC_MEM_SCRAMBLE_END_2_reg_addr                                        "0xB8003648"
#define DC2_SYS_DC_MEM_SCRAMBLE_END_3_reg_addr                                        "0xB800364C"
#define DC2_SYS_DC_MEM_SCRAMBLE_END_4_reg_addr                                        "0xB8003650"
#define DC2_SYS_DC_MEM_SCRAMBLE_END_5_reg_addr                                        "0xB8003654"
#define DC2_SYS_DC_MEM_SCRAMBLE_END_6_reg_addr                                        "0xB8003658"
#define DC2_SYS_DC_MEM_SCRAMBLE_END_7_reg_addr                                        "0xB800365C"
#define DC2_SYS_DC_MEM_SCRAMBLE_END_0_reg                                             0xB8003640
#define DC2_SYS_DC_MEM_SCRAMBLE_END_1_reg                                             0xB8003644
#define DC2_SYS_DC_MEM_SCRAMBLE_END_2_reg                                             0xB8003648
#define DC2_SYS_DC_MEM_SCRAMBLE_END_3_reg                                             0xB800364C
#define DC2_SYS_DC_MEM_SCRAMBLE_END_4_reg                                             0xB8003650
#define DC2_SYS_DC_MEM_SCRAMBLE_END_5_reg                                             0xB8003654
#define DC2_SYS_DC_MEM_SCRAMBLE_END_6_reg                                             0xB8003658
#define DC2_SYS_DC_MEM_SCRAMBLE_END_7_reg                                             0xB800365C
#define set_DC2_SYS_DC_MEM_SCRAMBLE_END_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_END_0_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_END_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_END_1_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_END_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_END_2_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_END_3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_END_3_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_END_4_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_END_4_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_END_5_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_END_5_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_END_6_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_END_6_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_END_7_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_END_7_reg)=data)
#define get_DC2_SYS_DC_MEM_SCRAMBLE_END_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_END_0_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_END_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_END_1_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_END_2_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_END_2_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_END_3_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_END_3_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_END_4_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_END_4_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_END_5_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_END_5_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_END_6_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_END_6_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_END_7_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_END_7_reg))
#define DC2_SYS_DC_MEM_SCRAMBLE_END_0_inst_adr                                        "0x0090"
#define DC2_SYS_DC_MEM_SCRAMBLE_END_1_inst_adr                                        "0x0091"
#define DC2_SYS_DC_MEM_SCRAMBLE_END_2_inst_adr                                        "0x0092"
#define DC2_SYS_DC_MEM_SCRAMBLE_END_3_inst_adr                                        "0x0093"
#define DC2_SYS_DC_MEM_SCRAMBLE_END_4_inst_adr                                        "0x0094"
#define DC2_SYS_DC_MEM_SCRAMBLE_END_5_inst_adr                                        "0x0095"
#define DC2_SYS_DC_MEM_SCRAMBLE_END_6_inst_adr                                        "0x0096"
#define DC2_SYS_DC_MEM_SCRAMBLE_END_7_inst_adr                                        "0x0097"
#define DC2_SYS_DC_MEM_SCRAMBLE_END_0_inst                                            0x0090
#define DC2_SYS_DC_MEM_SCRAMBLE_END_1_inst                                            0x0091
#define DC2_SYS_DC_MEM_SCRAMBLE_END_2_inst                                            0x0092
#define DC2_SYS_DC_MEM_SCRAMBLE_END_3_inst                                            0x0093
#define DC2_SYS_DC_MEM_SCRAMBLE_END_4_inst                                            0x0094
#define DC2_SYS_DC_MEM_SCRAMBLE_END_5_inst                                            0x0095
#define DC2_SYS_DC_MEM_SCRAMBLE_END_6_inst                                            0x0096
#define DC2_SYS_DC_MEM_SCRAMBLE_END_7_inst                                            0x0097
#define DC2_SYS_DC_MEM_SCRAMBLE_END_addr_shift                                        (12)
#define DC2_SYS_DC_MEM_SCRAMBLE_END_addr_mask                                         (0xFFFFF000)
#define DC2_SYS_DC_MEM_SCRAMBLE_END_addr(data)                                        (0xFFFFF000&((data)<<12))
#define DC2_SYS_DC_MEM_SCRAMBLE_END_addr_src(data)                                    ((0xFFFFF000&(data))>>12)
#define DC2_SYS_DC_MEM_SCRAMBLE_END_get_addr(data)                                    ((0xFFFFF000&(data))>>12)


#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_0                                            0x18003660
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_1                                            0x18003664
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_2                                            0x18003668
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_3                                            0x1800366C
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_4                                            0x18003670
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_5                                            0x18003674
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_6                                            0x18003678
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_7                                            0x1800367C
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_0_reg_addr                                   "0xB8003660"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_1_reg_addr                                   "0xB8003664"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_2_reg_addr                                   "0xB8003668"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_3_reg_addr                                   "0xB800366C"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_4_reg_addr                                   "0xB8003670"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_5_reg_addr                                   "0xB8003674"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_6_reg_addr                                   "0xB8003678"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_7_reg_addr                                   "0xB800367C"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_0_reg                                        0xB8003660
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_1_reg                                        0xB8003664
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_2_reg                                        0xB8003668
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_3_reg                                        0xB800366C
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_4_reg                                        0xB8003670
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_5_reg                                        0xB8003674
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_6_reg                                        0xB8003678
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_7_reg                                        0xB800367C
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_0_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_1_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_2_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_3_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_4_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_4_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_5_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_5_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_6_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_6_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_7_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_7_reg)=data)
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_0_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_1_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_2_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_2_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_3_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_3_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_4_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_4_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_5_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_5_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_6_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_6_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_7_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_7_reg))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_0_inst_adr                                   "0x0098"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_1_inst_adr                                   "0x0099"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_2_inst_adr                                   "0x009A"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_3_inst_adr                                   "0x009B"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_4_inst_adr                                   "0x009C"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_5_inst_adr                                   "0x009D"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_6_inst_adr                                   "0x009E"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_7_inst_adr                                   "0x009F"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_0_inst                                       0x0098
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_1_inst                                       0x0099
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_2_inst                                       0x009A
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_3_inst                                       0x009B
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_4_inst                                       0x009C
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_5_inst                                       0x009D
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_6_inst                                       0x009E
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_7_inst                                       0x009F
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_key1_shift                                   (16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_key1_mask                                    (0xFFFF0000)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_key1(data)                                   (0xFFFF0000&((data)<<16))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_key1_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_get_key1(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_key0_shift                                   (0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_key0_mask                                    (0x0000FFFF)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_key0(data)                                   (0x0000FFFF&((data)<<0))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_key0_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR0_get_key0(data)                               ((0x0000FFFF&(data))>>0)


#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_0                                            0x18003680
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_1                                            0x18003684
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_2                                            0x18003688
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_3                                            0x1800368C
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_4                                            0x18003690
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_5                                            0x18003694
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_6                                            0x18003698
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_7                                            0x1800369C
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_0_reg_addr                                   "0xB8003680"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_1_reg_addr                                   "0xB8003684"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_2_reg_addr                                   "0xB8003688"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_3_reg_addr                                   "0xB800368C"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_4_reg_addr                                   "0xB8003690"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_5_reg_addr                                   "0xB8003694"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_6_reg_addr                                   "0xB8003698"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_7_reg_addr                                   "0xB800369C"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_0_reg                                        0xB8003680
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_1_reg                                        0xB8003684
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_2_reg                                        0xB8003688
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_3_reg                                        0xB800368C
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_4_reg                                        0xB8003690
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_5_reg                                        0xB8003694
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_6_reg                                        0xB8003698
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_7_reg                                        0xB800369C
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_0_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_1_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_2_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_3_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_4_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_4_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_5_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_5_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_6_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_6_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_7_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_7_reg)=data)
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_0_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_1_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_2_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_2_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_3_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_3_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_4_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_4_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_5_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_5_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_6_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_6_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_7_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_7_reg))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_0_inst_adr                                   "0x00A0"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_1_inst_adr                                   "0x00A1"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_2_inst_adr                                   "0x00A2"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_3_inst_adr                                   "0x00A3"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_4_inst_adr                                   "0x00A4"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_5_inst_adr                                   "0x00A5"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_6_inst_adr                                   "0x00A6"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_7_inst_adr                                   "0x00A7"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_0_inst                                       0x00A0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_1_inst                                       0x00A1
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_2_inst                                       0x00A2
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_3_inst                                       0x00A3
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_4_inst                                       0x00A4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_5_inst                                       0x00A5
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_6_inst                                       0x00A6
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_7_inst                                       0x00A7
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_key3_shift                                   (16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_key3_mask                                    (0xFFFF0000)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_key3(data)                                   (0xFFFF0000&((data)<<16))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_key3_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_get_key3(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_key2_shift                                   (0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_key2_mask                                    (0x0000FFFF)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_key2(data)                                   (0x0000FFFF&((data)<<0))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_key2_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR1_get_key2(data)                               ((0x0000FFFF&(data))>>0)


#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_0                                            0x180036A0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_1                                            0x180036A4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_2                                            0x180036A8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_3                                            0x180036AC
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_4                                            0x180036B0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_5                                            0x180036B4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_6                                            0x180036B8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_7                                            0x180036BC
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_0_reg_addr                                   "0xB80036A0"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_1_reg_addr                                   "0xB80036A4"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_2_reg_addr                                   "0xB80036A8"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_3_reg_addr                                   "0xB80036AC"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_4_reg_addr                                   "0xB80036B0"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_5_reg_addr                                   "0xB80036B4"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_6_reg_addr                                   "0xB80036B8"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_7_reg_addr                                   "0xB80036BC"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_0_reg                                        0xB80036A0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_1_reg                                        0xB80036A4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_2_reg                                        0xB80036A8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_3_reg                                        0xB80036AC
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_4_reg                                        0xB80036B0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_5_reg                                        0xB80036B4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_6_reg                                        0xB80036B8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_7_reg                                        0xB80036BC
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_0_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_1_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_2_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_3_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_4_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_4_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_5_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_5_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_6_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_6_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_7_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_7_reg)=data)
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_0_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_1_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_2_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_2_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_3_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_3_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_4_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_4_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_5_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_5_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_6_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_6_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_7_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_7_reg))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_0_inst_adr                                   "0x00A8"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_1_inst_adr                                   "0x00A9"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_2_inst_adr                                   "0x00AA"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_3_inst_adr                                   "0x00AB"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_4_inst_adr                                   "0x00AC"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_5_inst_adr                                   "0x00AD"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_6_inst_adr                                   "0x00AE"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_7_inst_adr                                   "0x00AF"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_0_inst                                       0x00A8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_1_inst                                       0x00A9
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_2_inst                                       0x00AA
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_3_inst                                       0x00AB
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_4_inst                                       0x00AC
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_5_inst                                       0x00AD
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_6_inst                                       0x00AE
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_7_inst                                       0x00AF
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_key5_shift                                   (16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_key5_mask                                    (0xFFFF0000)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_key5(data)                                   (0xFFFF0000&((data)<<16))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_key5_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_get_key5(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_key4_shift                                   (0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_key4_mask                                    (0x0000FFFF)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_key4(data)                                   (0x0000FFFF&((data)<<0))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_key4_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR2_get_key4(data)                               ((0x0000FFFF&(data))>>0)


#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_0                                            0x180036C0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_1                                            0x180036C4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_2                                            0x180036C8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_3                                            0x180036CC
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_4                                            0x180036D0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_5                                            0x180036D4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_6                                            0x180036D8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_7                                            0x180036DC
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_0_reg_addr                                   "0xB80036C0"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_1_reg_addr                                   "0xB80036C4"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_2_reg_addr                                   "0xB80036C8"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_3_reg_addr                                   "0xB80036CC"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_4_reg_addr                                   "0xB80036D0"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_5_reg_addr                                   "0xB80036D4"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_6_reg_addr                                   "0xB80036D8"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_7_reg_addr                                   "0xB80036DC"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_0_reg                                        0xB80036C0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_1_reg                                        0xB80036C4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_2_reg                                        0xB80036C8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_3_reg                                        0xB80036CC
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_4_reg                                        0xB80036D0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_5_reg                                        0xB80036D4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_6_reg                                        0xB80036D8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_7_reg                                        0xB80036DC
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_0_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_1_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_2_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_3_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_4_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_4_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_5_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_5_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_6_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_6_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_7_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_7_reg)=data)
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_0_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_1_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_2_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_2_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_3_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_3_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_4_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_4_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_5_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_5_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_6_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_6_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_7_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_7_reg))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_0_inst_adr                                   "0x00B0"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_1_inst_adr                                   "0x00B1"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_2_inst_adr                                   "0x00B2"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_3_inst_adr                                   "0x00B3"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_4_inst_adr                                   "0x00B4"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_5_inst_adr                                   "0x00B5"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_6_inst_adr                                   "0x00B6"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_7_inst_adr                                   "0x00B7"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_0_inst                                       0x00B0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_1_inst                                       0x00B1
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_2_inst                                       0x00B2
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_3_inst                                       0x00B3
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_4_inst                                       0x00B4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_5_inst                                       0x00B5
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_6_inst                                       0x00B6
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_7_inst                                       0x00B7
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_key7_shift                                   (16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_key7_mask                                    (0xFFFF0000)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_key7(data)                                   (0xFFFF0000&((data)<<16))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_key7_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_get_key7(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_key6_shift                                   (0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_key6_mask                                    (0x0000FFFF)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_key6(data)                                   (0x0000FFFF&((data)<<0))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_key6_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR3_get_key6(data)                               ((0x0000FFFF&(data))>>0)


#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_0                                            0x180036E0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_1                                            0x180036E4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_2                                            0x180036E8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_3                                            0x180036EC
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_4                                            0x180036F0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_5                                            0x180036F4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_6                                            0x180036F8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_7                                            0x180036FC
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_0_reg_addr                                   "0xB80036E0"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_1_reg_addr                                   "0xB80036E4"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_2_reg_addr                                   "0xB80036E8"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_3_reg_addr                                   "0xB80036EC"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_4_reg_addr                                   "0xB80036F0"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_5_reg_addr                                   "0xB80036F4"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_6_reg_addr                                   "0xB80036F8"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_7_reg_addr                                   "0xB80036FC"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_0_reg                                        0xB80036E0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_1_reg                                        0xB80036E4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_2_reg                                        0xB80036E8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_3_reg                                        0xB80036EC
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_4_reg                                        0xB80036F0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_5_reg                                        0xB80036F4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_6_reg                                        0xB80036F8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_7_reg                                        0xB80036FC
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_0_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_1_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_2_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_3_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_4_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_4_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_5_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_5_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_6_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_6_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_7_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_7_reg)=data)
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_0_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_1_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_2_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_2_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_3_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_3_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_4_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_4_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_5_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_5_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_6_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_6_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_7_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_7_reg))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_0_inst_adr                                   "0x00B8"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_1_inst_adr                                   "0x00B9"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_2_inst_adr                                   "0x00BA"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_3_inst_adr                                   "0x00BB"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_4_inst_adr                                   "0x00BC"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_5_inst_adr                                   "0x00BD"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_6_inst_adr                                   "0x00BE"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_7_inst_adr                                   "0x00BF"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_0_inst                                       0x00B8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_1_inst                                       0x00B9
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_2_inst                                       0x00BA
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_3_inst                                       0x00BB
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_4_inst                                       0x00BC
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_5_inst                                       0x00BD
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_6_inst                                       0x00BE
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_7_inst                                       0x00BF
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_key9_shift                                   (16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_key9_mask                                    (0xFFFF0000)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_key9(data)                                   (0xFFFF0000&((data)<<16))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_key9_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_get_key9(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_key8_shift                                   (0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_key8_mask                                    (0x0000FFFF)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_key8(data)                                   (0x0000FFFF&((data)<<0))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_key8_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR4_get_key8(data)                               ((0x0000FFFF&(data))>>0)


#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_0                                            0x18003700
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_1                                            0x18003704
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_2                                            0x18003708
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_3                                            0x1800370C
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_4                                            0x18003710
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_5                                            0x18003714
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_6                                            0x18003718
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_7                                            0x1800371C
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_0_reg_addr                                   "0xB8003700"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_1_reg_addr                                   "0xB8003704"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_2_reg_addr                                   "0xB8003708"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_3_reg_addr                                   "0xB800370C"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_4_reg_addr                                   "0xB8003710"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_5_reg_addr                                   "0xB8003714"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_6_reg_addr                                   "0xB8003718"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_7_reg_addr                                   "0xB800371C"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_0_reg                                        0xB8003700
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_1_reg                                        0xB8003704
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_2_reg                                        0xB8003708
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_3_reg                                        0xB800370C
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_4_reg                                        0xB8003710
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_5_reg                                        0xB8003714
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_6_reg                                        0xB8003718
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_7_reg                                        0xB800371C
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_0_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_1_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_2_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_3_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_4_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_4_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_5_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_5_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_6_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_6_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_7_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_7_reg)=data)
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_0_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_1_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_2_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_2_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_3_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_3_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_4_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_4_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_5_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_5_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_6_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_6_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_7_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_7_reg))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_0_inst_adr                                   "0x00C0"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_1_inst_adr                                   "0x00C1"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_2_inst_adr                                   "0x00C2"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_3_inst_adr                                   "0x00C3"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_4_inst_adr                                   "0x00C4"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_5_inst_adr                                   "0x00C5"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_6_inst_adr                                   "0x00C6"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_7_inst_adr                                   "0x00C7"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_0_inst                                       0x00C0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_1_inst                                       0x00C1
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_2_inst                                       0x00C2
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_3_inst                                       0x00C3
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_4_inst                                       0x00C4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_5_inst                                       0x00C5
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_6_inst                                       0x00C6
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_7_inst                                       0x00C7
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_keyB_shift                                   (16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_keyB_mask                                    (0xFFFF0000)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_keyB(data)                                   (0xFFFF0000&((data)<<16))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_keyB_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_get_keyB(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_keyA_shift                                   (0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_keyA_mask                                    (0x0000FFFF)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_keyA(data)                                   (0x0000FFFF&((data)<<0))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_keyA_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR5_get_keyA(data)                               ((0x0000FFFF&(data))>>0)


#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_0                                            0x18003720
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_1                                            0x18003724
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_2                                            0x18003728
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_3                                            0x1800372C
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_4                                            0x18003730
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_5                                            0x18003734
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_6                                            0x18003738
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_7                                            0x1800373C
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_0_reg_addr                                   "0xB8003720"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_1_reg_addr                                   "0xB8003724"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_2_reg_addr                                   "0xB8003728"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_3_reg_addr                                   "0xB800372C"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_4_reg_addr                                   "0xB8003730"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_5_reg_addr                                   "0xB8003734"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_6_reg_addr                                   "0xB8003738"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_7_reg_addr                                   "0xB800373C"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_0_reg                                        0xB8003720
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_1_reg                                        0xB8003724
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_2_reg                                        0xB8003728
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_3_reg                                        0xB800372C
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_4_reg                                        0xB8003730
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_5_reg                                        0xB8003734
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_6_reg                                        0xB8003738
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_7_reg                                        0xB800373C
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_0_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_1_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_2_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_3_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_4_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_4_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_5_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_5_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_6_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_6_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_7_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_7_reg)=data)
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_0_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_1_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_2_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_2_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_3_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_3_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_4_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_4_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_5_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_5_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_6_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_6_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_7_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_7_reg))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_0_inst_adr                                   "0x00C8"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_1_inst_adr                                   "0x00C9"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_2_inst_adr                                   "0x00CA"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_3_inst_adr                                   "0x00CB"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_4_inst_adr                                   "0x00CC"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_5_inst_adr                                   "0x00CD"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_6_inst_adr                                   "0x00CE"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_7_inst_adr                                   "0x00CF"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_0_inst                                       0x00C8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_1_inst                                       0x00C9
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_2_inst                                       0x00CA
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_3_inst                                       0x00CB
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_4_inst                                       0x00CC
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_5_inst                                       0x00CD
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_6_inst                                       0x00CE
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_7_inst                                       0x00CF
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_keyD_shift                                   (16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_keyD_mask                                    (0xFFFF0000)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_keyD(data)                                   (0xFFFF0000&((data)<<16))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_keyD_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_get_keyD(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_keyC_shift                                   (0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_keyC_mask                                    (0x0000FFFF)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_keyC(data)                                   (0x0000FFFF&((data)<<0))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_keyC_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_CUR6_get_keyC(data)                               ((0x0000FFFF&(data))>>0)


#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_0                                            0x18003740
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_1                                            0x18003744
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_2                                            0x18003748
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_3                                            0x1800374C
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_4                                            0x18003750
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_5                                            0x18003754
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_6                                            0x18003758
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_7                                            0x1800375C
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_0_reg_addr                                   "0xB8003740"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_1_reg_addr                                   "0xB8003744"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_2_reg_addr                                   "0xB8003748"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_3_reg_addr                                   "0xB800374C"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_4_reg_addr                                   "0xB8003750"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_5_reg_addr                                   "0xB8003754"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_6_reg_addr                                   "0xB8003758"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_7_reg_addr                                   "0xB800375C"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_0_reg                                        0xB8003740
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_1_reg                                        0xB8003744
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_2_reg                                        0xB8003748
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_3_reg                                        0xB800374C
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_4_reg                                        0xB8003750
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_5_reg                                        0xB8003754
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_6_reg                                        0xB8003758
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_7_reg                                        0xB800375C
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_0_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_1_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_2_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_3_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_4_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_4_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_5_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_5_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_6_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_6_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_7_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_7_reg)=data)
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_0_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_1_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_2_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_2_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_3_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_3_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_4_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_4_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_5_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_5_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_6_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_6_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_7_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_7_reg))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_0_inst_adr                                   "0x00D0"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_1_inst_adr                                   "0x00D1"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_2_inst_adr                                   "0x00D2"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_3_inst_adr                                   "0x00D3"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_4_inst_adr                                   "0x00D4"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_5_inst_adr                                   "0x00D5"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_6_inst_adr                                   "0x00D6"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_7_inst_adr                                   "0x00D7"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_0_inst                                       0x00D0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_1_inst                                       0x00D1
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_2_inst                                       0x00D2
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_3_inst                                       0x00D3
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_4_inst                                       0x00D4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_5_inst                                       0x00D5
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_6_inst                                       0x00D6
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_7_inst                                       0x00D7
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_key1_shift                                   (16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_key1_mask                                    (0xFFFF0000)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_key1(data)                                   (0xFFFF0000&((data)<<16))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_key1_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_get_key1(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_key0_shift                                   (0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_key0_mask                                    (0x0000FFFF)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_key0(data)                                   (0x0000FFFF&((data)<<0))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_key0_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE0_get_key0(data)                               ((0x0000FFFF&(data))>>0)


#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_0                                            0x18003760
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_1                                            0x18003764
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_2                                            0x18003768
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_3                                            0x1800376C
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_4                                            0x18003770
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_5                                            0x18003774
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_6                                            0x18003778
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_7                                            0x1800377C
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_0_reg_addr                                   "0xB8003760"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_1_reg_addr                                   "0xB8003764"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_2_reg_addr                                   "0xB8003768"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_3_reg_addr                                   "0xB800376C"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_4_reg_addr                                   "0xB8003770"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_5_reg_addr                                   "0xB8003774"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_6_reg_addr                                   "0xB8003778"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_7_reg_addr                                   "0xB800377C"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_0_reg                                        0xB8003760
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_1_reg                                        0xB8003764
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_2_reg                                        0xB8003768
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_3_reg                                        0xB800376C
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_4_reg                                        0xB8003770
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_5_reg                                        0xB8003774
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_6_reg                                        0xB8003778
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_7_reg                                        0xB800377C
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_0_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_1_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_2_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_3_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_4_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_4_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_5_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_5_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_6_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_6_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_7_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_7_reg)=data)
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_0_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_1_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_2_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_2_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_3_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_3_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_4_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_4_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_5_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_5_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_6_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_6_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_7_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_7_reg))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_0_inst_adr                                   "0x00D8"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_1_inst_adr                                   "0x00D9"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_2_inst_adr                                   "0x00DA"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_3_inst_adr                                   "0x00DB"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_4_inst_adr                                   "0x00DC"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_5_inst_adr                                   "0x00DD"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_6_inst_adr                                   "0x00DE"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_7_inst_adr                                   "0x00DF"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_0_inst                                       0x00D8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_1_inst                                       0x00D9
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_2_inst                                       0x00DA
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_3_inst                                       0x00DB
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_4_inst                                       0x00DC
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_5_inst                                       0x00DD
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_6_inst                                       0x00DE
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_7_inst                                       0x00DF
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_key3_shift                                   (16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_key3_mask                                    (0xFFFF0000)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_key3(data)                                   (0xFFFF0000&((data)<<16))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_key3_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_get_key3(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_key2_shift                                   (0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_key2_mask                                    (0x0000FFFF)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_key2(data)                                   (0x0000FFFF&((data)<<0))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_key2_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE1_get_key2(data)                               ((0x0000FFFF&(data))>>0)


#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_0                                            0x18003780
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_1                                            0x18003784
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_2                                            0x18003788
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_3                                            0x1800378C
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_4                                            0x18003790
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_5                                            0x18003794
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_6                                            0x18003798
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_7                                            0x1800379C
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_0_reg_addr                                   "0xB8003780"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_1_reg_addr                                   "0xB8003784"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_2_reg_addr                                   "0xB8003788"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_3_reg_addr                                   "0xB800378C"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_4_reg_addr                                   "0xB8003790"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_5_reg_addr                                   "0xB8003794"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_6_reg_addr                                   "0xB8003798"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_7_reg_addr                                   "0xB800379C"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_0_reg                                        0xB8003780
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_1_reg                                        0xB8003784
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_2_reg                                        0xB8003788
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_3_reg                                        0xB800378C
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_4_reg                                        0xB8003790
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_5_reg                                        0xB8003794
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_6_reg                                        0xB8003798
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_7_reg                                        0xB800379C
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_0_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_1_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_2_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_3_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_4_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_4_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_5_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_5_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_6_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_6_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_7_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_7_reg)=data)
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_0_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_1_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_2_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_2_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_3_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_3_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_4_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_4_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_5_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_5_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_6_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_6_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_7_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_7_reg))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_0_inst_adr                                   "0x00E0"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_1_inst_adr                                   "0x00E1"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_2_inst_adr                                   "0x00E2"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_3_inst_adr                                   "0x00E3"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_4_inst_adr                                   "0x00E4"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_5_inst_adr                                   "0x00E5"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_6_inst_adr                                   "0x00E6"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_7_inst_adr                                   "0x00E7"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_0_inst                                       0x00E0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_1_inst                                       0x00E1
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_2_inst                                       0x00E2
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_3_inst                                       0x00E3
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_4_inst                                       0x00E4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_5_inst                                       0x00E5
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_6_inst                                       0x00E6
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_7_inst                                       0x00E7
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_key5_shift                                   (16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_key5_mask                                    (0xFFFF0000)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_key5(data)                                   (0xFFFF0000&((data)<<16))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_key5_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_get_key5(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_key4_shift                                   (0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_key4_mask                                    (0x0000FFFF)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_key4(data)                                   (0x0000FFFF&((data)<<0))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_key4_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE2_get_key4(data)                               ((0x0000FFFF&(data))>>0)


#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_0                                            0x180037A0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_1                                            0x180037A4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_2                                            0x180037A8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_3                                            0x180037AC
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_4                                            0x180037B0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_5                                            0x180037B4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_6                                            0x180037B8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_7                                            0x180037BC
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_0_reg_addr                                   "0xB80037A0"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_1_reg_addr                                   "0xB80037A4"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_2_reg_addr                                   "0xB80037A8"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_3_reg_addr                                   "0xB80037AC"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_4_reg_addr                                   "0xB80037B0"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_5_reg_addr                                   "0xB80037B4"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_6_reg_addr                                   "0xB80037B8"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_7_reg_addr                                   "0xB80037BC"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_0_reg                                        0xB80037A0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_1_reg                                        0xB80037A4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_2_reg                                        0xB80037A8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_3_reg                                        0xB80037AC
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_4_reg                                        0xB80037B0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_5_reg                                        0xB80037B4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_6_reg                                        0xB80037B8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_7_reg                                        0xB80037BC
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_0_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_1_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_2_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_3_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_4_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_4_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_5_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_5_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_6_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_6_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_7_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_7_reg)=data)
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_0_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_1_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_2_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_2_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_3_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_3_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_4_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_4_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_5_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_5_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_6_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_6_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_7_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_7_reg))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_0_inst_adr                                   "0x00E8"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_1_inst_adr                                   "0x00E9"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_2_inst_adr                                   "0x00EA"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_3_inst_adr                                   "0x00EB"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_4_inst_adr                                   "0x00EC"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_5_inst_adr                                   "0x00ED"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_6_inst_adr                                   "0x00EE"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_7_inst_adr                                   "0x00EF"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_0_inst                                       0x00E8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_1_inst                                       0x00E9
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_2_inst                                       0x00EA
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_3_inst                                       0x00EB
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_4_inst                                       0x00EC
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_5_inst                                       0x00ED
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_6_inst                                       0x00EE
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_7_inst                                       0x00EF
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_key7_shift                                   (16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_key7_mask                                    (0xFFFF0000)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_key7(data)                                   (0xFFFF0000&((data)<<16))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_key7_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_get_key7(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_key6_shift                                   (0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_key6_mask                                    (0x0000FFFF)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_key6(data)                                   (0x0000FFFF&((data)<<0))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_key6_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE3_get_key6(data)                               ((0x0000FFFF&(data))>>0)


#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_0                                            0x180037C0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_1                                            0x180037C4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_2                                            0x180037C8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_3                                            0x180037CC
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_4                                            0x180037D0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_5                                            0x180037D4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_6                                            0x180037D8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_7                                            0x180037DC
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_0_reg_addr                                   "0xB80037C0"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_1_reg_addr                                   "0xB80037C4"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_2_reg_addr                                   "0xB80037C8"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_3_reg_addr                                   "0xB80037CC"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_4_reg_addr                                   "0xB80037D0"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_5_reg_addr                                   "0xB80037D4"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_6_reg_addr                                   "0xB80037D8"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_7_reg_addr                                   "0xB80037DC"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_0_reg                                        0xB80037C0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_1_reg                                        0xB80037C4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_2_reg                                        0xB80037C8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_3_reg                                        0xB80037CC
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_4_reg                                        0xB80037D0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_5_reg                                        0xB80037D4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_6_reg                                        0xB80037D8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_7_reg                                        0xB80037DC
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_0_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_1_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_2_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_3_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_4_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_4_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_5_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_5_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_6_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_6_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_7_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_7_reg)=data)
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_0_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_1_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_2_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_2_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_3_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_3_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_4_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_4_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_5_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_5_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_6_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_6_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_7_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_7_reg))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_0_inst_adr                                   "0x00F0"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_1_inst_adr                                   "0x00F1"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_2_inst_adr                                   "0x00F2"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_3_inst_adr                                   "0x00F3"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_4_inst_adr                                   "0x00F4"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_5_inst_adr                                   "0x00F5"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_6_inst_adr                                   "0x00F6"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_7_inst_adr                                   "0x00F7"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_0_inst                                       0x00F0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_1_inst                                       0x00F1
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_2_inst                                       0x00F2
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_3_inst                                       0x00F3
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_4_inst                                       0x00F4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_5_inst                                       0x00F5
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_6_inst                                       0x00F6
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_7_inst                                       0x00F7
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_key9_shift                                   (16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_key9_mask                                    (0xFFFF0000)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_key9(data)                                   (0xFFFF0000&((data)<<16))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_key9_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_get_key9(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_key8_shift                                   (0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_key8_mask                                    (0x0000FFFF)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_key8(data)                                   (0x0000FFFF&((data)<<0))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_key8_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE4_get_key8(data)                               ((0x0000FFFF&(data))>>0)


#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_0                                            0x180037E0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_1                                            0x180037E4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_2                                            0x180037E8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_3                                            0x180037EC
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_4                                            0x180037F0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_5                                            0x180037F4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_6                                            0x180037F8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_7                                            0x180037FC
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_0_reg_addr                                   "0xB80037E0"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_1_reg_addr                                   "0xB80037E4"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_2_reg_addr                                   "0xB80037E8"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_3_reg_addr                                   "0xB80037EC"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_4_reg_addr                                   "0xB80037F0"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_5_reg_addr                                   "0xB80037F4"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_6_reg_addr                                   "0xB80037F8"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_7_reg_addr                                   "0xB80037FC"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_0_reg                                        0xB80037E0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_1_reg                                        0xB80037E4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_2_reg                                        0xB80037E8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_3_reg                                        0xB80037EC
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_4_reg                                        0xB80037F0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_5_reg                                        0xB80037F4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_6_reg                                        0xB80037F8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_7_reg                                        0xB80037FC
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_0_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_1_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_2_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_3_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_4_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_4_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_5_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_5_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_6_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_6_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_7_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_7_reg)=data)
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_0_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_1_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_2_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_2_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_3_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_3_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_4_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_4_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_5_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_5_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_6_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_6_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_7_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_7_reg))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_0_inst_adr                                   "0x00F8"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_1_inst_adr                                   "0x00F9"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_2_inst_adr                                   "0x00FA"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_3_inst_adr                                   "0x00FB"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_4_inst_adr                                   "0x00FC"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_5_inst_adr                                   "0x00FD"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_6_inst_adr                                   "0x00FE"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_7_inst_adr                                   "0x00FF"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_0_inst                                       0x00F8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_1_inst                                       0x00F9
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_2_inst                                       0x00FA
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_3_inst                                       0x00FB
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_4_inst                                       0x00FC
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_5_inst                                       0x00FD
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_6_inst                                       0x00FE
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_7_inst                                       0x00FF
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_keyB_shift                                   (16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_keyB_mask                                    (0xFFFF0000)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_keyB(data)                                   (0xFFFF0000&((data)<<16))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_keyB_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_get_keyB(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_keyA_shift                                   (0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_keyA_mask                                    (0x0000FFFF)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_keyA(data)                                   (0x0000FFFF&((data)<<0))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_keyA_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE5_get_keyA(data)                               ((0x0000FFFF&(data))>>0)


#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_0                                            0x18003800
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_1                                            0x18003804
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_2                                            0x18003808
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_3                                            0x1800380C
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_4                                            0x18003810
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_5                                            0x18003814
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_6                                            0x18003818
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_7                                            0x1800381C
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_0_reg_addr                                   "0xB8003800"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_1_reg_addr                                   "0xB8003804"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_2_reg_addr                                   "0xB8003808"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_3_reg_addr                                   "0xB800380C"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_4_reg_addr                                   "0xB8003810"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_5_reg_addr                                   "0xB8003814"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_6_reg_addr                                   "0xB8003818"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_7_reg_addr                                   "0xB800381C"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_0_reg                                        0xB8003800
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_1_reg                                        0xB8003804
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_2_reg                                        0xB8003808
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_3_reg                                        0xB800380C
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_4_reg                                        0xB8003810
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_5_reg                                        0xB8003814
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_6_reg                                        0xB8003818
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_7_reg                                        0xB800381C
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_0_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_1_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_2_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_3_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_4_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_4_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_5_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_5_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_6_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_6_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_7_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_7_reg)=data)
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_0_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_1_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_2_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_2_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_3_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_3_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_4_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_4_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_5_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_5_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_6_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_6_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_7_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_7_reg))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_0_inst_adr                                   "0x0000"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_1_inst_adr                                   "0x0001"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_2_inst_adr                                   "0x0002"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_3_inst_adr                                   "0x0003"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_4_inst_adr                                   "0x0004"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_5_inst_adr                                   "0x0005"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_6_inst_adr                                   "0x0006"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_7_inst_adr                                   "0x0007"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_0_inst                                       0x0000
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_1_inst                                       0x0001
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_2_inst                                       0x0002
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_3_inst                                       0x0003
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_4_inst                                       0x0004
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_5_inst                                       0x0005
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_6_inst                                       0x0006
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_7_inst                                       0x0007
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_keyD_shift                                   (16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_keyD_mask                                    (0xFFFF0000)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_keyD(data)                                   (0xFFFF0000&((data)<<16))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_keyD_src(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_get_keyD(data)                               ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_keyC_shift                                   (0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_keyC_mask                                    (0x0000FFFF)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_keyC(data)                                   (0x0000FFFF&((data)<<0))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_keyC_src(data)                               ((0x0000FFFF&(data))>>0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_PRE6_get_keyC(data)                               ((0x0000FFFF&(data))>>0)


#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_0                                             0x18003820
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_1                                             0x18003824
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_2                                             0x18003828
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_3                                             0x1800382C
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_4                                             0x18003830
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_5                                             0x18003834
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_6                                             0x18003838
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_7                                             0x1800383C
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_0_reg_addr                                    "0xB8003820"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_1_reg_addr                                    "0xB8003824"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_2_reg_addr                                    "0xB8003828"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_3_reg_addr                                    "0xB800382C"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_4_reg_addr                                    "0xB8003830"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_5_reg_addr                                    "0xB8003834"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_6_reg_addr                                    "0xB8003838"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_7_reg_addr                                    "0xB800383C"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_0_reg                                         0xB8003820
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_1_reg                                         0xB8003824
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_2_reg                                         0xB8003828
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_3_reg                                         0xB800382C
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_4_reg                                         0xB8003830
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_5_reg                                         0xB8003834
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_6_reg                                         0xB8003838
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_7_reg                                         0xB800383C
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_0_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_1_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_2_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_3_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_4_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_4_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_5_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_5_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_6_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_6_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_7_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_7_reg)=data)
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_0_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_1_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_2_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_2_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_3_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_3_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_4_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_4_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_5_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_5_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_6_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_6_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_7_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_7_reg))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_0_inst_adr                                    "0x0008"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_1_inst_adr                                    "0x0009"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_2_inst_adr                                    "0x000A"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_3_inst_adr                                    "0x000B"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_4_inst_adr                                    "0x000C"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_5_inst_adr                                    "0x000D"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_6_inst_adr                                    "0x000E"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_7_inst_adr                                    "0x000F"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_0_inst                                        0x0008
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_1_inst                                        0x0009
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_2_inst                                        0x000A
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_3_inst                                        0x000B
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_4_inst                                        0x000C
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_5_inst                                        0x000D
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_6_inst                                        0x000E
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_7_inst                                        0x000F
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_key1_shift                                    (16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_key1_mask                                     (0xFFFF0000)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_key1(data)                                    (0xFFFF0000&((data)<<16))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_key1_src(data)                                ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_get_key1(data)                                ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_key0_shift                                    (0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_key0_mask                                     (0x0000FFFF)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_key0(data)                                    (0x0000FFFF&((data)<<0))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_key0_src(data)                                ((0x0000FFFF&(data))>>0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP0_get_key0(data)                                ((0x0000FFFF&(data))>>0)


#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_0                                             0x18003840
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_1                                             0x18003844
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_2                                             0x18003848
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_3                                             0x1800384C
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_4                                             0x18003850
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_5                                             0x18003854
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_6                                             0x18003858
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_7                                             0x1800385C
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_0_reg_addr                                    "0xB8003840"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_1_reg_addr                                    "0xB8003844"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_2_reg_addr                                    "0xB8003848"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_3_reg_addr                                    "0xB800384C"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_4_reg_addr                                    "0xB8003850"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_5_reg_addr                                    "0xB8003854"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_6_reg_addr                                    "0xB8003858"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_7_reg_addr                                    "0xB800385C"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_0_reg                                         0xB8003840
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_1_reg                                         0xB8003844
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_2_reg                                         0xB8003848
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_3_reg                                         0xB800384C
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_4_reg                                         0xB8003850
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_5_reg                                         0xB8003854
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_6_reg                                         0xB8003858
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_7_reg                                         0xB800385C
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_0_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_1_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_2_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_3_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_4_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_4_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_5_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_5_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_6_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_6_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_7_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_7_reg)=data)
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_0_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_1_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_2_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_2_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_3_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_3_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_4_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_4_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_5_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_5_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_6_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_6_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_7_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_7_reg))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_0_inst_adr                                    "0x0010"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_1_inst_adr                                    "0x0011"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_2_inst_adr                                    "0x0012"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_3_inst_adr                                    "0x0013"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_4_inst_adr                                    "0x0014"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_5_inst_adr                                    "0x0015"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_6_inst_adr                                    "0x0016"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_7_inst_adr                                    "0x0017"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_0_inst                                        0x0010
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_1_inst                                        0x0011
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_2_inst                                        0x0012
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_3_inst                                        0x0013
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_4_inst                                        0x0014
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_5_inst                                        0x0015
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_6_inst                                        0x0016
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_7_inst                                        0x0017
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_key3_shift                                    (16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_key3_mask                                     (0xFFFF0000)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_key3(data)                                    (0xFFFF0000&((data)<<16))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_key3_src(data)                                ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_get_key3(data)                                ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_key2_shift                                    (0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_key2_mask                                     (0x0000FFFF)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_key2(data)                                    (0x0000FFFF&((data)<<0))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_key2_src(data)                                ((0x0000FFFF&(data))>>0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP1_get_key2(data)                                ((0x0000FFFF&(data))>>0)


#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_0                                             0x18003860
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_1                                             0x18003864
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_2                                             0x18003868
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_3                                             0x1800386C
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_4                                             0x18003870
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_5                                             0x18003874
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_6                                             0x18003878
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_7                                             0x1800387C
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_0_reg_addr                                    "0xB8003860"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_1_reg_addr                                    "0xB8003864"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_2_reg_addr                                    "0xB8003868"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_3_reg_addr                                    "0xB800386C"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_4_reg_addr                                    "0xB8003870"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_5_reg_addr                                    "0xB8003874"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_6_reg_addr                                    "0xB8003878"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_7_reg_addr                                    "0xB800387C"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_0_reg                                         0xB8003860
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_1_reg                                         0xB8003864
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_2_reg                                         0xB8003868
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_3_reg                                         0xB800386C
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_4_reg                                         0xB8003870
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_5_reg                                         0xB8003874
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_6_reg                                         0xB8003878
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_7_reg                                         0xB800387C
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_0_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_1_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_2_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_3_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_4_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_4_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_5_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_5_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_6_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_6_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_7_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_7_reg)=data)
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_0_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_1_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_2_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_2_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_3_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_3_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_4_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_4_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_5_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_5_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_6_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_6_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_7_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_7_reg))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_0_inst_adr                                    "0x0018"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_1_inst_adr                                    "0x0019"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_2_inst_adr                                    "0x001A"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_3_inst_adr                                    "0x001B"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_4_inst_adr                                    "0x001C"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_5_inst_adr                                    "0x001D"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_6_inst_adr                                    "0x001E"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_7_inst_adr                                    "0x001F"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_0_inst                                        0x0018
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_1_inst                                        0x0019
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_2_inst                                        0x001A
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_3_inst                                        0x001B
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_4_inst                                        0x001C
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_5_inst                                        0x001D
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_6_inst                                        0x001E
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_7_inst                                        0x001F
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_key5_shift                                    (16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_key5_mask                                     (0xFFFF0000)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_key5(data)                                    (0xFFFF0000&((data)<<16))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_key5_src(data)                                ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_get_key5(data)                                ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_key4_shift                                    (0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_key4_mask                                     (0x0000FFFF)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_key4(data)                                    (0x0000FFFF&((data)<<0))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_key4_src(data)                                ((0x0000FFFF&(data))>>0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP2_get_key4(data)                                ((0x0000FFFF&(data))>>0)


#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_0                                             0x18003880
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_1                                             0x18003884
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_2                                             0x18003888
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_3                                             0x1800388C
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_4                                             0x18003890
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_5                                             0x18003894
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_6                                             0x18003898
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_7                                             0x1800389C
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_0_reg_addr                                    "0xB8003880"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_1_reg_addr                                    "0xB8003884"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_2_reg_addr                                    "0xB8003888"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_3_reg_addr                                    "0xB800388C"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_4_reg_addr                                    "0xB8003890"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_5_reg_addr                                    "0xB8003894"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_6_reg_addr                                    "0xB8003898"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_7_reg_addr                                    "0xB800389C"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_0_reg                                         0xB8003880
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_1_reg                                         0xB8003884
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_2_reg                                         0xB8003888
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_3_reg                                         0xB800388C
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_4_reg                                         0xB8003890
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_5_reg                                         0xB8003894
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_6_reg                                         0xB8003898
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_7_reg                                         0xB800389C
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_0_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_1_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_2_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_3_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_4_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_4_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_5_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_5_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_6_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_6_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_7_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_7_reg)=data)
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_0_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_1_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_2_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_2_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_3_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_3_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_4_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_4_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_5_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_5_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_6_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_6_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_7_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_7_reg))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_0_inst_adr                                    "0x0020"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_1_inst_adr                                    "0x0021"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_2_inst_adr                                    "0x0022"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_3_inst_adr                                    "0x0023"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_4_inst_adr                                    "0x0024"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_5_inst_adr                                    "0x0025"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_6_inst_adr                                    "0x0026"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_7_inst_adr                                    "0x0027"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_0_inst                                        0x0020
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_1_inst                                        0x0021
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_2_inst                                        0x0022
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_3_inst                                        0x0023
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_4_inst                                        0x0024
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_5_inst                                        0x0025
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_6_inst                                        0x0026
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_7_inst                                        0x0027
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_key7_shift                                    (16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_key7_mask                                     (0xFFFF0000)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_key7(data)                                    (0xFFFF0000&((data)<<16))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_key7_src(data)                                ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_get_key7(data)                                ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_key6_shift                                    (0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_key6_mask                                     (0x0000FFFF)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_key6(data)                                    (0x0000FFFF&((data)<<0))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_key6_src(data)                                ((0x0000FFFF&(data))>>0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP3_get_key6(data)                                ((0x0000FFFF&(data))>>0)


#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_0                                             0x180038A0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_1                                             0x180038A4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_2                                             0x180038A8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_3                                             0x180038AC
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_4                                             0x180038B0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_5                                             0x180038B4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_6                                             0x180038B8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_7                                             0x180038BC
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_0_reg_addr                                    "0xB80038A0"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_1_reg_addr                                    "0xB80038A4"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_2_reg_addr                                    "0xB80038A8"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_3_reg_addr                                    "0xB80038AC"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_4_reg_addr                                    "0xB80038B0"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_5_reg_addr                                    "0xB80038B4"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_6_reg_addr                                    "0xB80038B8"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_7_reg_addr                                    "0xB80038BC"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_0_reg                                         0xB80038A0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_1_reg                                         0xB80038A4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_2_reg                                         0xB80038A8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_3_reg                                         0xB80038AC
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_4_reg                                         0xB80038B0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_5_reg                                         0xB80038B4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_6_reg                                         0xB80038B8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_7_reg                                         0xB80038BC
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_0_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_1_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_2_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_3_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_4_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_4_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_5_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_5_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_6_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_6_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_7_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_7_reg)=data)
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_0_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_1_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_2_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_2_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_3_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_3_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_4_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_4_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_5_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_5_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_6_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_6_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_7_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_7_reg))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_0_inst_adr                                    "0x0028"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_1_inst_adr                                    "0x0029"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_2_inst_adr                                    "0x002A"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_3_inst_adr                                    "0x002B"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_4_inst_adr                                    "0x002C"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_5_inst_adr                                    "0x002D"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_6_inst_adr                                    "0x002E"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_7_inst_adr                                    "0x002F"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_0_inst                                        0x0028
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_1_inst                                        0x0029
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_2_inst                                        0x002A
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_3_inst                                        0x002B
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_4_inst                                        0x002C
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_5_inst                                        0x002D
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_6_inst                                        0x002E
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_7_inst                                        0x002F
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_key9_shift                                    (16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_key9_mask                                     (0xFFFF0000)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_key9(data)                                    (0xFFFF0000&((data)<<16))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_key9_src(data)                                ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_get_key9(data)                                ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_key8_shift                                    (0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_key8_mask                                     (0x0000FFFF)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_key8(data)                                    (0x0000FFFF&((data)<<0))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_key8_src(data)                                ((0x0000FFFF&(data))>>0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP4_get_key8(data)                                ((0x0000FFFF&(data))>>0)


#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_0                                             0x180038C0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_1                                             0x180038C4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_2                                             0x180038C8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_3                                             0x180038CC
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_4                                             0x180038D0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_5                                             0x180038D4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_6                                             0x180038D8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_7                                             0x180038DC
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_0_reg_addr                                    "0xB80038C0"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_1_reg_addr                                    "0xB80038C4"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_2_reg_addr                                    "0xB80038C8"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_3_reg_addr                                    "0xB80038CC"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_4_reg_addr                                    "0xB80038D0"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_5_reg_addr                                    "0xB80038D4"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_6_reg_addr                                    "0xB80038D8"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_7_reg_addr                                    "0xB80038DC"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_0_reg                                         0xB80038C0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_1_reg                                         0xB80038C4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_2_reg                                         0xB80038C8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_3_reg                                         0xB80038CC
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_4_reg                                         0xB80038D0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_5_reg                                         0xB80038D4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_6_reg                                         0xB80038D8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_7_reg                                         0xB80038DC
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_0_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_1_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_2_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_3_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_4_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_4_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_5_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_5_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_6_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_6_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_7_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_7_reg)=data)
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_0_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_1_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_2_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_2_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_3_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_3_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_4_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_4_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_5_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_5_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_6_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_6_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_7_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_7_reg))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_0_inst_adr                                    "0x0030"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_1_inst_adr                                    "0x0031"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_2_inst_adr                                    "0x0032"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_3_inst_adr                                    "0x0033"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_4_inst_adr                                    "0x0034"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_5_inst_adr                                    "0x0035"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_6_inst_adr                                    "0x0036"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_7_inst_adr                                    "0x0037"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_0_inst                                        0x0030
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_1_inst                                        0x0031
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_2_inst                                        0x0032
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_3_inst                                        0x0033
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_4_inst                                        0x0034
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_5_inst                                        0x0035
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_6_inst                                        0x0036
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_7_inst                                        0x0037
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_keyB_shift                                    (16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_keyB_mask                                     (0xFFFF0000)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_keyB(data)                                    (0xFFFF0000&((data)<<16))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_keyB_src(data)                                ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_get_keyB(data)                                ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_keyA_shift                                    (0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_keyA_mask                                     (0x0000FFFF)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_keyA(data)                                    (0x0000FFFF&((data)<<0))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_keyA_src(data)                                ((0x0000FFFF&(data))>>0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP5_get_keyA(data)                                ((0x0000FFFF&(data))>>0)


#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_0                                             0x180038E0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_1                                             0x180038E4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_2                                             0x180038E8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_3                                             0x180038EC
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_4                                             0x180038F0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_5                                             0x180038F4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_6                                             0x180038F8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_7                                             0x180038FC
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_0_reg_addr                                    "0xB80038E0"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_1_reg_addr                                    "0xB80038E4"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_2_reg_addr                                    "0xB80038E8"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_3_reg_addr                                    "0xB80038EC"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_4_reg_addr                                    "0xB80038F0"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_5_reg_addr                                    "0xB80038F4"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_6_reg_addr                                    "0xB80038F8"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_7_reg_addr                                    "0xB80038FC"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_0_reg                                         0xB80038E0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_1_reg                                         0xB80038E4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_2_reg                                         0xB80038E8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_3_reg                                         0xB80038EC
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_4_reg                                         0xB80038F0
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_5_reg                                         0xB80038F4
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_6_reg                                         0xB80038F8
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_7_reg                                         0xB80038FC
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_0_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_1_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_2_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_3_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_3_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_4_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_4_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_5_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_5_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_6_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_6_reg)=data)
#define set_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_7_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_7_reg)=data)
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_0_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_1_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_2_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_2_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_3_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_3_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_4_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_4_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_5_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_5_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_6_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_6_reg))
#define get_DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_7_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_7_reg))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_0_inst_adr                                    "0x0038"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_1_inst_adr                                    "0x0039"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_2_inst_adr                                    "0x003A"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_3_inst_adr                                    "0x003B"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_4_inst_adr                                    "0x003C"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_5_inst_adr                                    "0x003D"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_6_inst_adr                                    "0x003E"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_7_inst_adr                                    "0x003F"
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_0_inst                                        0x0038
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_1_inst                                        0x0039
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_2_inst                                        0x003A
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_3_inst                                        0x003B
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_4_inst                                        0x003C
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_5_inst                                        0x003D
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_6_inst                                        0x003E
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_7_inst                                        0x003F
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_keyD_shift                                    (16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_keyD_mask                                     (0xFFFF0000)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_keyD(data)                                    (0xFFFF0000&((data)<<16))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_keyD_src(data)                                ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_get_keyD(data)                                ((0xFFFF0000&(data))>>16)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_keyC_shift                                    (0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_keyC_mask                                     (0x0000FFFF)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_keyC(data)                                    (0x0000FFFF&((data)<<0))
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_keyC_src(data)                                ((0x0000FFFF&(data))>>0)
#define DC2_SYS_DC_MEM_SCRAMBLE_BUF_UP6_get_keyC(data)                                ((0x0000FFFF&(data))>>0)


#define DC2_SYS_DC_MEM_DISPLAY_CTRL                                                   0x18003580
#define DC2_SYS_DC_MEM_DISPLAY_CTRL_reg_addr                                          "0xB8003580"
#define DC2_SYS_DC_MEM_DISPLAY_CTRL_reg                                               0xB8003580
#define set_DC2_SYS_DC_MEM_DISPLAY_CTRL_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_MEM_DISPLAY_CTRL_reg)=data)
#define get_DC2_SYS_DC_MEM_DISPLAY_CTRL_reg   (*((volatile unsigned int*) DC2_SYS_DC_MEM_DISPLAY_CTRL_reg))
#define DC2_SYS_DC_MEM_DISPLAY_CTRL_inst_adr                                          "0x0060"
#define DC2_SYS_DC_MEM_DISPLAY_CTRL_inst                                              0x0060
#define DC2_SYS_DC_MEM_DISPLAY_CTRL_display_1_en_shift                                (17)
#define DC2_SYS_DC_MEM_DISPLAY_CTRL_display_1_en_mask                                 (0x00020000)
#define DC2_SYS_DC_MEM_DISPLAY_CTRL_display_1_en(data)                                (0x00020000&((data)<<17))
#define DC2_SYS_DC_MEM_DISPLAY_CTRL_display_1_en_src(data)                            ((0x00020000&(data))>>17)
#define DC2_SYS_DC_MEM_DISPLAY_CTRL_get_display_1_en(data)                            ((0x00020000&(data))>>17)
#define DC2_SYS_DC_MEM_DISPLAY_CTRL_display_0_en_shift                                (16)
#define DC2_SYS_DC_MEM_DISPLAY_CTRL_display_0_en_mask                                 (0x00010000)
#define DC2_SYS_DC_MEM_DISPLAY_CTRL_display_0_en(data)                                (0x00010000&((data)<<16))
#define DC2_SYS_DC_MEM_DISPLAY_CTRL_display_0_en_src(data)                            ((0x00010000&(data))>>16)
#define DC2_SYS_DC_MEM_DISPLAY_CTRL_get_display_0_en(data)                            ((0x00010000&(data))>>16)
#define DC2_SYS_DC_MEM_DISPLAY_CTRL_display_1_scramble_en_shift                       (1)
#define DC2_SYS_DC_MEM_DISPLAY_CTRL_display_1_scramble_en_mask                        (0x00000002)
#define DC2_SYS_DC_MEM_DISPLAY_CTRL_display_1_scramble_en(data)                       (0x00000002&((data)<<1))
#define DC2_SYS_DC_MEM_DISPLAY_CTRL_display_1_scramble_en_src(data)                   ((0x00000002&(data))>>1)
#define DC2_SYS_DC_MEM_DISPLAY_CTRL_get_display_1_scramble_en(data)                   ((0x00000002&(data))>>1)
#define DC2_SYS_DC_MEM_DISPLAY_CTRL_display_0_scramble_en_shift                       (0)
#define DC2_SYS_DC_MEM_DISPLAY_CTRL_display_0_scramble_en_mask                        (0x00000001)
#define DC2_SYS_DC_MEM_DISPLAY_CTRL_display_0_scramble_en(data)                       (0x00000001&((data)<<0))
#define DC2_SYS_DC_MEM_DISPLAY_CTRL_display_0_scramble_en_src(data)                   ((0x00000001&(data))>>0)
#define DC2_SYS_DC_MEM_DISPLAY_CTRL_get_display_0_scramble_en(data)                   ((0x00000001&(data))>>0)


#define DC2_SYS_DC_DISPLAY_START_0                                                    0x18003588
#define DC2_SYS_DC_DISPLAY_START_1                                                    0x1800358C
#define DC2_SYS_DC_DISPLAY_START_0_reg_addr                                           "0xB8003588"
#define DC2_SYS_DC_DISPLAY_START_1_reg_addr                                           "0xB800358C"
#define DC2_SYS_DC_DISPLAY_START_0_reg                                                0xB8003588
#define DC2_SYS_DC_DISPLAY_START_1_reg                                                0xB800358C
#define set_DC2_SYS_DC_DISPLAY_START_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_DISPLAY_START_0_reg)=data)
#define set_DC2_SYS_DC_DISPLAY_START_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_DISPLAY_START_1_reg)=data)
#define get_DC2_SYS_DC_DISPLAY_START_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_DISPLAY_START_0_reg))
#define get_DC2_SYS_DC_DISPLAY_START_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_DISPLAY_START_1_reg))
#define DC2_SYS_DC_DISPLAY_START_0_inst_adr                                           "0x0062"
#define DC2_SYS_DC_DISPLAY_START_1_inst_adr                                           "0x0063"
#define DC2_SYS_DC_DISPLAY_START_0_inst                                               0x0062
#define DC2_SYS_DC_DISPLAY_START_1_inst                                               0x0063
#define DC2_SYS_DC_DISPLAY_START_addr_shift                                           (12)
#define DC2_SYS_DC_DISPLAY_START_addr_mask                                            (0xFFFFF000)
#define DC2_SYS_DC_DISPLAY_START_addr(data)                                           (0xFFFFF000&((data)<<12))
#define DC2_SYS_DC_DISPLAY_START_addr_src(data)                                       ((0xFFFFF000&(data))>>12)
#define DC2_SYS_DC_DISPLAY_START_get_addr(data)                                       ((0xFFFFF000&(data))>>12)


#define DC2_SYS_DC_DISPLAY_END_0                                                      0x18003590
#define DC2_SYS_DC_DISPLAY_END_1                                                      0x18003594
#define DC2_SYS_DC_DISPLAY_END_0_reg_addr                                             "0xB8003590"
#define DC2_SYS_DC_DISPLAY_END_1_reg_addr                                             "0xB8003594"
#define DC2_SYS_DC_DISPLAY_END_0_reg                                                  0xB8003590
#define DC2_SYS_DC_DISPLAY_END_1_reg                                                  0xB8003594
#define set_DC2_SYS_DC_DISPLAY_END_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_DISPLAY_END_0_reg)=data)
#define set_DC2_SYS_DC_DISPLAY_END_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_DISPLAY_END_1_reg)=data)
#define get_DC2_SYS_DC_DISPLAY_END_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_DISPLAY_END_0_reg))
#define get_DC2_SYS_DC_DISPLAY_END_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_DISPLAY_END_1_reg))
#define DC2_SYS_DC_DISPLAY_END_0_inst_adr                                             "0x0064"
#define DC2_SYS_DC_DISPLAY_END_1_inst_adr                                             "0x0065"
#define DC2_SYS_DC_DISPLAY_END_0_inst                                                 0x0064
#define DC2_SYS_DC_DISPLAY_END_1_inst                                                 0x0065
#define DC2_SYS_DC_DISPLAY_END_addr_shift                                             (12)
#define DC2_SYS_DC_DISPLAY_END_addr_mask                                              (0xFFFFF000)
#define DC2_SYS_DC_DISPLAY_END_addr(data)                                             (0xFFFFF000&((data)<<12))
#define DC2_SYS_DC_DISPLAY_END_addr_src(data)                                         ((0xFFFFF000&(data))>>12)
#define DC2_SYS_DC_DISPLAY_END_get_addr(data)                                         ((0xFFFFF000&(data))>>12)


#define DC2_SYS_DC_DISPLAY_ACCESS_0                                                   0x18003598
#define DC2_SYS_DC_DISPLAY_ACCESS_1                                                   0x1800359C
#define DC2_SYS_DC_DISPLAY_ACCESS_0_reg_addr                                          "0xB8003598"
#define DC2_SYS_DC_DISPLAY_ACCESS_1_reg_addr                                          "0xB800359C"
#define DC2_SYS_DC_DISPLAY_ACCESS_0_reg                                               0xB8003598
#define DC2_SYS_DC_DISPLAY_ACCESS_1_reg                                               0xB800359C
#define set_DC2_SYS_DC_DISPLAY_ACCESS_0_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_DISPLAY_ACCESS_0_reg)=data)
#define set_DC2_SYS_DC_DISPLAY_ACCESS_1_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_DISPLAY_ACCESS_1_reg)=data)
#define get_DC2_SYS_DC_DISPLAY_ACCESS_0_reg   (*((volatile unsigned int*) DC2_SYS_DC_DISPLAY_ACCESS_0_reg))
#define get_DC2_SYS_DC_DISPLAY_ACCESS_1_reg   (*((volatile unsigned int*) DC2_SYS_DC_DISPLAY_ACCESS_1_reg))
#define DC2_SYS_DC_DISPLAY_ACCESS_0_inst_adr                                          "0x0066"
#define DC2_SYS_DC_DISPLAY_ACCESS_1_inst_adr                                          "0x0067"
#define DC2_SYS_DC_DISPLAY_ACCESS_0_inst                                              0x0066
#define DC2_SYS_DC_DISPLAY_ACCESS_1_inst                                              0x0067
#define DC2_SYS_DC_DISPLAY_ACCESS_me_shift                                            (11)
#define DC2_SYS_DC_DISPLAY_ACCESS_me_mask                                             (0x00000800)
#define DC2_SYS_DC_DISPLAY_ACCESS_me(data)                                            (0x00000800&((data)<<11))
#define DC2_SYS_DC_DISPLAY_ACCESS_me_src(data)                                        ((0x00000800&(data))>>11)
#define DC2_SYS_DC_DISPLAY_ACCESS_get_me(data)                                        ((0x00000800&(data))>>11)
#define DC2_SYS_DC_DISPLAY_ACCESS_osd1_shift                                          (10)
#define DC2_SYS_DC_DISPLAY_ACCESS_osd1_mask                                           (0x00000400)
#define DC2_SYS_DC_DISPLAY_ACCESS_osd1(data)                                          (0x00000400&((data)<<10))
#define DC2_SYS_DC_DISPLAY_ACCESS_osd1_src(data)                                      ((0x00000400&(data))>>10)
#define DC2_SYS_DC_DISPLAY_ACCESS_get_osd1(data)                                      ((0x00000400&(data))>>10)
#define DC2_SYS_DC_DISPLAY_ACCESS_osd2_shift                                          (9)
#define DC2_SYS_DC_DISPLAY_ACCESS_osd2_mask                                           (0x00000200)
#define DC2_SYS_DC_DISPLAY_ACCESS_osd2(data)                                          (0x00000200&((data)<<9))
#define DC2_SYS_DC_DISPLAY_ACCESS_osd2_src(data)                                      ((0x00000200&(data))>>9)
#define DC2_SYS_DC_DISPLAY_ACCESS_get_osd2(data)                                      ((0x00000200&(data))>>9)
#define DC2_SYS_DC_DISPLAY_ACCESS_subtitle_shift                                      (8)
#define DC2_SYS_DC_DISPLAY_ACCESS_subtitle_mask                                       (0x00000100)
#define DC2_SYS_DC_DISPLAY_ACCESS_subtitle(data)                                      (0x00000100&((data)<<8))
#define DC2_SYS_DC_DISPLAY_ACCESS_subtitle_src(data)                                  ((0x00000100&(data))>>8)
#define DC2_SYS_DC_DISPLAY_ACCESS_get_subtitle(data)                                  ((0x00000100&(data))>>8)
#define DC2_SYS_DC_DISPLAY_ACCESS_vcpu_shift                                          (6)
#define DC2_SYS_DC_DISPLAY_ACCESS_vcpu_mask                                           (0x000000C0)
#define DC2_SYS_DC_DISPLAY_ACCESS_vcpu(data)                                          (0x000000C0&((data)<<6))
#define DC2_SYS_DC_DISPLAY_ACCESS_vcpu_src(data)                                      ((0x000000C0&(data))>>6)
#define DC2_SYS_DC_DISPLAY_ACCESS_get_vcpu(data)                                      ((0x000000C0&(data))>>6)
#define DC2_SYS_DC_DISPLAY_ACCESS_ve_shift                                            (5)
#define DC2_SYS_DC_DISPLAY_ACCESS_ve_mask                                             (0x00000020)
#define DC2_SYS_DC_DISPLAY_ACCESS_ve(data)                                            (0x00000020&((data)<<5))
#define DC2_SYS_DC_DISPLAY_ACCESS_ve_src(data)                                        ((0x00000020&(data))>>5)
#define DC2_SYS_DC_DISPLAY_ACCESS_get_ve(data)                                        ((0x00000020&(data))>>5)
#define DC2_SYS_DC_DISPLAY_ACCESS_vde_shift                                           (4)
#define DC2_SYS_DC_DISPLAY_ACCESS_vde_mask                                            (0x00000010)
#define DC2_SYS_DC_DISPLAY_ACCESS_vde(data)                                           (0x00000010&((data)<<4))
#define DC2_SYS_DC_DISPLAY_ACCESS_vde_src(data)                                       ((0x00000010&(data))>>4)
#define DC2_SYS_DC_DISPLAY_ACCESS_get_vde(data)                                       ((0x00000010&(data))>>4)
#define DC2_SYS_DC_DISPLAY_ACCESS_gpu_shift                                           (3)
#define DC2_SYS_DC_DISPLAY_ACCESS_gpu_mask                                            (0x00000008)
#define DC2_SYS_DC_DISPLAY_ACCESS_gpu(data)                                           (0x00000008&((data)<<3))
#define DC2_SYS_DC_DISPLAY_ACCESS_gpu_src(data)                                       ((0x00000008&(data))>>3)
#define DC2_SYS_DC_DISPLAY_ACCESS_get_gpu(data)                                       ((0x00000008&(data))>>3)
#define DC2_SYS_DC_DISPLAY_ACCESS_md_kc_shift                                         (2)
#define DC2_SYS_DC_DISPLAY_ACCESS_md_kc_mask                                          (0x00000004)
#define DC2_SYS_DC_DISPLAY_ACCESS_md_kc(data)                                         (0x00000004&((data)<<2))
#define DC2_SYS_DC_DISPLAY_ACCESS_md_kc_src(data)                                     ((0x00000004&(data))>>2)
#define DC2_SYS_DC_DISPLAY_ACCESS_get_md_kc(data)                                     ((0x00000004&(data))>>2)
#define DC2_SYS_DC_DISPLAY_ACCESS_cp_kc_shift                                         (1)
#define DC2_SYS_DC_DISPLAY_ACCESS_cp_kc_mask                                          (0x00000002)
#define DC2_SYS_DC_DISPLAY_ACCESS_cp_kc(data)                                         (0x00000002&((data)<<1))
#define DC2_SYS_DC_DISPLAY_ACCESS_cp_kc_src(data)                                     ((0x00000002&(data))>>1)
#define DC2_SYS_DC_DISPLAY_ACCESS_get_cp_kc(data)                                     ((0x00000002&(data))>>1)
#define DC2_SYS_DC_DISPLAY_ACCESS_md_vc_shift                                         (0)
#define DC2_SYS_DC_DISPLAY_ACCESS_md_vc_mask                                          (0x00000001)
#define DC2_SYS_DC_DISPLAY_ACCESS_md_vc(data)                                         (0x00000001&((data)<<0))
#define DC2_SYS_DC_DISPLAY_ACCESS_md_vc_src(data)                                     ((0x00000001&(data))>>0)
#define DC2_SYS_DC_DISPLAY_ACCESS_get_md_vc(data)                                     ((0x00000001&(data))>>0)


#define DC2_SYS_DC_SECURE_INT_ENABLE                                                  0x180035A0
#define DC2_SYS_DC_SECURE_INT_ENABLE_reg_addr                                         "0xB80035A0"
#define DC2_SYS_DC_SECURE_INT_ENABLE_reg                                              0xB80035A0
#define set_DC2_SYS_DC_SECURE_INT_ENABLE_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_SECURE_INT_ENABLE_reg)=data)
#define get_DC2_SYS_DC_SECURE_INT_ENABLE_reg   (*((volatile unsigned int*) DC2_SYS_DC_SECURE_INT_ENABLE_reg))
#define DC2_SYS_DC_SECURE_INT_ENABLE_inst_adr                                         "0x0068"
#define DC2_SYS_DC_SECURE_INT_ENABLE_inst                                             0x0068
#define DC2_SYS_DC_SECURE_INT_ENABLE_display_touch_other_en_shift                     (31)
#define DC2_SYS_DC_SECURE_INT_ENABLE_display_touch_other_en_mask                      (0x80000000)
#define DC2_SYS_DC_SECURE_INT_ENABLE_display_touch_other_en(data)                     (0x80000000&((data)<<31))
#define DC2_SYS_DC_SECURE_INT_ENABLE_display_touch_other_en_src(data)                 ((0x80000000&(data))>>31)
#define DC2_SYS_DC_SECURE_INT_ENABLE_get_display_touch_other_en(data)                 ((0x80000000&(data))>>31)
#define DC2_SYS_DC_SECURE_INT_ENABLE_display1_touch_en_shift                          (30)
#define DC2_SYS_DC_SECURE_INT_ENABLE_display1_touch_en_mask                           (0x40000000)
#define DC2_SYS_DC_SECURE_INT_ENABLE_display1_touch_en(data)                          (0x40000000&((data)<<30))
#define DC2_SYS_DC_SECURE_INT_ENABLE_display1_touch_en_src(data)                      ((0x40000000&(data))>>30)
#define DC2_SYS_DC_SECURE_INT_ENABLE_get_display1_touch_en(data)                      ((0x40000000&(data))>>30)
#define DC2_SYS_DC_SECURE_INT_ENABLE_display0_touch_en_shift                          (29)
#define DC2_SYS_DC_SECURE_INT_ENABLE_display0_touch_en_mask                           (0x20000000)
#define DC2_SYS_DC_SECURE_INT_ENABLE_display0_touch_en(data)                          (0x20000000&((data)<<29))
#define DC2_SYS_DC_SECURE_INT_ENABLE_display0_touch_en_src(data)                      ((0x20000000&(data))>>29)
#define DC2_SYS_DC_SECURE_INT_ENABLE_get_display0_touch_en(data)                      ((0x20000000&(data))>>29)
#define DC2_SYS_DC_SECURE_INT_ENABLE_blk_over_max_secure_addr_int_en_shift            (28)
#define DC2_SYS_DC_SECURE_INT_ENABLE_blk_over_max_secure_addr_int_en_mask             (0x10000000)
#define DC2_SYS_DC_SECURE_INT_ENABLE_blk_over_max_secure_addr_int_en(data)            (0x10000000&((data)<<28))
#define DC2_SYS_DC_SECURE_INT_ENABLE_blk_over_max_secure_addr_int_en_src(data)        ((0x10000000&(data))>>28)
#define DC2_SYS_DC_SECURE_INT_ENABLE_get_blk_over_max_secure_addr_int_en(data)        ((0x10000000&(data))>>28)
#define DC2_SYS_DC_SECURE_INT_ENABLE_seq_over_max_secure_addr_int_en_shift            (27)
#define DC2_SYS_DC_SECURE_INT_ENABLE_seq_over_max_secure_addr_int_en_mask             (0x08000000)
#define DC2_SYS_DC_SECURE_INT_ENABLE_seq_over_max_secure_addr_int_en(data)            (0x08000000&((data)<<27))
#define DC2_SYS_DC_SECURE_INT_ENABLE_seq_over_max_secure_addr_int_en_src(data)        ((0x08000000&(data))>>27)
#define DC2_SYS_DC_SECURE_INT_ENABLE_get_seq_over_max_secure_addr_int_en(data)        ((0x08000000&(data))>>27)
#define DC2_SYS_DC_SECURE_INT_ENABLE_blk_y_overflow_int_en_shift                      (26)
#define DC2_SYS_DC_SECURE_INT_ENABLE_blk_y_overflow_int_en_mask                       (0x04000000)
#define DC2_SYS_DC_SECURE_INT_ENABLE_blk_y_overflow_int_en(data)                      (0x04000000&((data)<<26))
#define DC2_SYS_DC_SECURE_INT_ENABLE_blk_y_overflow_int_en_src(data)                  ((0x04000000&(data))>>26)
#define DC2_SYS_DC_SECURE_INT_ENABLE_get_blk_y_overflow_int_en(data)                  ((0x04000000&(data))>>26)
#define DC2_SYS_DC_SECURE_INT_ENABLE_blk_x_overflow_int_en_shift                      (25)
#define DC2_SYS_DC_SECURE_INT_ENABLE_blk_x_overflow_int_en_mask                       (0x02000000)
#define DC2_SYS_DC_SECURE_INT_ENABLE_blk_x_overflow_int_en(data)                      (0x02000000&((data)<<25))
#define DC2_SYS_DC_SECURE_INT_ENABLE_blk_x_overflow_int_en_src(data)                  ((0x02000000&(data))>>25)
#define DC2_SYS_DC_SECURE_INT_ENABLE_get_blk_x_overflow_int_en(data)                  ((0x02000000&(data))>>25)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content7_blk_touch_int_en_shift                  (24)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content7_blk_touch_int_en_mask                   (0x01000000)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content7_blk_touch_int_en(data)                  (0x01000000&((data)<<24))
#define DC2_SYS_DC_SECURE_INT_ENABLE_content7_blk_touch_int_en_src(data)              ((0x01000000&(data))>>24)
#define DC2_SYS_DC_SECURE_INT_ENABLE_get_content7_blk_touch_int_en(data)              ((0x01000000&(data))>>24)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content7_seq_touch_int_en_shift                  (23)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content7_seq_touch_int_en_mask                   (0x00800000)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content7_seq_touch_int_en(data)                  (0x00800000&((data)<<23))
#define DC2_SYS_DC_SECURE_INT_ENABLE_content7_seq_touch_int_en_src(data)              ((0x00800000&(data))>>23)
#define DC2_SYS_DC_SECURE_INT_ENABLE_get_content7_seq_touch_int_en(data)              ((0x00800000&(data))>>23)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content6_blk_touch_int_en_shift                  (22)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content6_blk_touch_int_en_mask                   (0x00400000)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content6_blk_touch_int_en(data)                  (0x00400000&((data)<<22))
#define DC2_SYS_DC_SECURE_INT_ENABLE_content6_blk_touch_int_en_src(data)              ((0x00400000&(data))>>22)
#define DC2_SYS_DC_SECURE_INT_ENABLE_get_content6_blk_touch_int_en(data)              ((0x00400000&(data))>>22)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content6_seq_touch_int_en_shift                  (21)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content6_seq_touch_int_en_mask                   (0x00200000)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content6_seq_touch_int_en(data)                  (0x00200000&((data)<<21))
#define DC2_SYS_DC_SECURE_INT_ENABLE_content6_seq_touch_int_en_src(data)              ((0x00200000&(data))>>21)
#define DC2_SYS_DC_SECURE_INT_ENABLE_get_content6_seq_touch_int_en(data)              ((0x00200000&(data))>>21)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content5_blk_touch_int_en_shift                  (20)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content5_blk_touch_int_en_mask                   (0x00100000)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content5_blk_touch_int_en(data)                  (0x00100000&((data)<<20))
#define DC2_SYS_DC_SECURE_INT_ENABLE_content5_blk_touch_int_en_src(data)              ((0x00100000&(data))>>20)
#define DC2_SYS_DC_SECURE_INT_ENABLE_get_content5_blk_touch_int_en(data)              ((0x00100000&(data))>>20)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content5_seq_touch_int_en_shift                  (19)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content5_seq_touch_int_en_mask                   (0x00080000)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content5_seq_touch_int_en(data)                  (0x00080000&((data)<<19))
#define DC2_SYS_DC_SECURE_INT_ENABLE_content5_seq_touch_int_en_src(data)              ((0x00080000&(data))>>19)
#define DC2_SYS_DC_SECURE_INT_ENABLE_get_content5_seq_touch_int_en(data)              ((0x00080000&(data))>>19)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content4_blk_touch_int_en_shift                  (18)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content4_blk_touch_int_en_mask                   (0x00040000)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content4_blk_touch_int_en(data)                  (0x00040000&((data)<<18))
#define DC2_SYS_DC_SECURE_INT_ENABLE_content4_blk_touch_int_en_src(data)              ((0x00040000&(data))>>18)
#define DC2_SYS_DC_SECURE_INT_ENABLE_get_content4_blk_touch_int_en(data)              ((0x00040000&(data))>>18)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content4_seq_touch_int_en_shift                  (17)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content4_seq_touch_int_en_mask                   (0x00020000)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content4_seq_touch_int_en(data)                  (0x00020000&((data)<<17))
#define DC2_SYS_DC_SECURE_INT_ENABLE_content4_seq_touch_int_en_src(data)              ((0x00020000&(data))>>17)
#define DC2_SYS_DC_SECURE_INT_ENABLE_get_content4_seq_touch_int_en(data)              ((0x00020000&(data))>>17)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content3_blk_touch_int_en_shift                  (16)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content3_blk_touch_int_en_mask                   (0x00010000)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content3_blk_touch_int_en(data)                  (0x00010000&((data)<<16))
#define DC2_SYS_DC_SECURE_INT_ENABLE_content3_blk_touch_int_en_src(data)              ((0x00010000&(data))>>16)
#define DC2_SYS_DC_SECURE_INT_ENABLE_get_content3_blk_touch_int_en(data)              ((0x00010000&(data))>>16)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content3_seq_touch_int_en_shift                  (15)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content3_seq_touch_int_en_mask                   (0x00008000)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content3_seq_touch_int_en(data)                  (0x00008000&((data)<<15))
#define DC2_SYS_DC_SECURE_INT_ENABLE_content3_seq_touch_int_en_src(data)              ((0x00008000&(data))>>15)
#define DC2_SYS_DC_SECURE_INT_ENABLE_get_content3_seq_touch_int_en(data)              ((0x00008000&(data))>>15)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content2_blk_touch_int_en_shift                  (14)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content2_blk_touch_int_en_mask                   (0x00004000)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content2_blk_touch_int_en(data)                  (0x00004000&((data)<<14))
#define DC2_SYS_DC_SECURE_INT_ENABLE_content2_blk_touch_int_en_src(data)              ((0x00004000&(data))>>14)
#define DC2_SYS_DC_SECURE_INT_ENABLE_get_content2_blk_touch_int_en(data)              ((0x00004000&(data))>>14)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content2_seq_touch_int_en_shift                  (13)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content2_seq_touch_int_en_mask                   (0x00002000)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content2_seq_touch_int_en(data)                  (0x00002000&((data)<<13))
#define DC2_SYS_DC_SECURE_INT_ENABLE_content2_seq_touch_int_en_src(data)              ((0x00002000&(data))>>13)
#define DC2_SYS_DC_SECURE_INT_ENABLE_get_content2_seq_touch_int_en(data)              ((0x00002000&(data))>>13)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content1_blk_touch_int_en_shift                  (12)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content1_blk_touch_int_en_mask                   (0x00001000)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content1_blk_touch_int_en(data)                  (0x00001000&((data)<<12))
#define DC2_SYS_DC_SECURE_INT_ENABLE_content1_blk_touch_int_en_src(data)              ((0x00001000&(data))>>12)
#define DC2_SYS_DC_SECURE_INT_ENABLE_get_content1_blk_touch_int_en(data)              ((0x00001000&(data))>>12)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content1_seq_touch_int_en_shift                  (11)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content1_seq_touch_int_en_mask                   (0x00000800)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content1_seq_touch_int_en(data)                  (0x00000800&((data)<<11))
#define DC2_SYS_DC_SECURE_INT_ENABLE_content1_seq_touch_int_en_src(data)              ((0x00000800&(data))>>11)
#define DC2_SYS_DC_SECURE_INT_ENABLE_get_content1_seq_touch_int_en(data)              ((0x00000800&(data))>>11)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content0_blk_touch_int_en_shift                  (10)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content0_blk_touch_int_en_mask                   (0x00000400)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content0_blk_touch_int_en(data)                  (0x00000400&((data)<<10))
#define DC2_SYS_DC_SECURE_INT_ENABLE_content0_blk_touch_int_en_src(data)              ((0x00000400&(data))>>10)
#define DC2_SYS_DC_SECURE_INT_ENABLE_get_content0_blk_touch_int_en(data)              ((0x00000400&(data))>>10)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content0_seq_touch_int_en_shift                  (9)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content0_seq_touch_int_en_mask                   (0x00000200)
#define DC2_SYS_DC_SECURE_INT_ENABLE_content0_seq_touch_int_en(data)                  (0x00000200&((data)<<9))
#define DC2_SYS_DC_SECURE_INT_ENABLE_content0_seq_touch_int_en_src(data)              ((0x00000200&(data))>>9)
#define DC2_SYS_DC_SECURE_INT_ENABLE_get_content0_seq_touch_int_en(data)              ((0x00000200&(data))>>9)
#define DC2_SYS_DC_SECURE_INT_ENABLE_protect3_blk_picset_touch_int_en_shift           (8)
#define DC2_SYS_DC_SECURE_INT_ENABLE_protect3_blk_picset_touch_int_en_mask            (0x00000100)
#define DC2_SYS_DC_SECURE_INT_ENABLE_protect3_blk_picset_touch_int_en(data)           (0x00000100&((data)<<8))
#define DC2_SYS_DC_SECURE_INT_ENABLE_protect3_blk_picset_touch_int_en_src(data)       ((0x00000100&(data))>>8)
#define DC2_SYS_DC_SECURE_INT_ENABLE_get_protect3_blk_picset_touch_int_en(data)       ((0x00000100&(data))>>8)
#define DC2_SYS_DC_SECURE_INT_ENABLE_protect3_seq_touch_int_en_shift                  (7)
#define DC2_SYS_DC_SECURE_INT_ENABLE_protect3_seq_touch_int_en_mask                   (0x00000080)
#define DC2_SYS_DC_SECURE_INT_ENABLE_protect3_seq_touch_int_en(data)                  (0x00000080&((data)<<7))
#define DC2_SYS_DC_SECURE_INT_ENABLE_protect3_seq_touch_int_en_src(data)              ((0x00000080&(data))>>7)
#define DC2_SYS_DC_SECURE_INT_ENABLE_get_protect3_seq_touch_int_en(data)              ((0x00000080&(data))>>7)
#define DC2_SYS_DC_SECURE_INT_ENABLE_protect2_blk_picset_touch_int_en_shift           (6)
#define DC2_SYS_DC_SECURE_INT_ENABLE_protect2_blk_picset_touch_int_en_mask            (0x00000040)
#define DC2_SYS_DC_SECURE_INT_ENABLE_protect2_blk_picset_touch_int_en(data)           (0x00000040&((data)<<6))
#define DC2_SYS_DC_SECURE_INT_ENABLE_protect2_blk_picset_touch_int_en_src(data)       ((0x00000040&(data))>>6)
#define DC2_SYS_DC_SECURE_INT_ENABLE_get_protect2_blk_picset_touch_int_en(data)       ((0x00000040&(data))>>6)
#define DC2_SYS_DC_SECURE_INT_ENABLE_protect2_seq_touch_int_en_shift                  (5)
#define DC2_SYS_DC_SECURE_INT_ENABLE_protect2_seq_touch_int_en_mask                   (0x00000020)
#define DC2_SYS_DC_SECURE_INT_ENABLE_protect2_seq_touch_int_en(data)                  (0x00000020&((data)<<5))
#define DC2_SYS_DC_SECURE_INT_ENABLE_protect2_seq_touch_int_en_src(data)              ((0x00000020&(data))>>5)
#define DC2_SYS_DC_SECURE_INT_ENABLE_get_protect2_seq_touch_int_en(data)              ((0x00000020&(data))>>5)
#define DC2_SYS_DC_SECURE_INT_ENABLE_protect1_blk_picset_touch_int_en_shift           (4)
#define DC2_SYS_DC_SECURE_INT_ENABLE_protect1_blk_picset_touch_int_en_mask            (0x00000010)
#define DC2_SYS_DC_SECURE_INT_ENABLE_protect1_blk_picset_touch_int_en(data)           (0x00000010&((data)<<4))
#define DC2_SYS_DC_SECURE_INT_ENABLE_protect1_blk_picset_touch_int_en_src(data)       ((0x00000010&(data))>>4)
#define DC2_SYS_DC_SECURE_INT_ENABLE_get_protect1_blk_picset_touch_int_en(data)       ((0x00000010&(data))>>4)
#define DC2_SYS_DC_SECURE_INT_ENABLE_protect1_seq_touch_int_en_shift                  (3)
#define DC2_SYS_DC_SECURE_INT_ENABLE_protect1_seq_touch_int_en_mask                   (0x00000008)
#define DC2_SYS_DC_SECURE_INT_ENABLE_protect1_seq_touch_int_en(data)                  (0x00000008&((data)<<3))
#define DC2_SYS_DC_SECURE_INT_ENABLE_protect1_seq_touch_int_en_src(data)              ((0x00000008&(data))>>3)
#define DC2_SYS_DC_SECURE_INT_ENABLE_get_protect1_seq_touch_int_en(data)              ((0x00000008&(data))>>3)
#define DC2_SYS_DC_SECURE_INT_ENABLE_protect0_blk_picset_touch_int_en_shift           (2)
#define DC2_SYS_DC_SECURE_INT_ENABLE_protect0_blk_picset_touch_int_en_mask            (0x00000004)
#define DC2_SYS_DC_SECURE_INT_ENABLE_protect0_blk_picset_touch_int_en(data)           (0x00000004&((data)<<2))
#define DC2_SYS_DC_SECURE_INT_ENABLE_protect0_blk_picset_touch_int_en_src(data)       ((0x00000004&(data))>>2)
#define DC2_SYS_DC_SECURE_INT_ENABLE_get_protect0_blk_picset_touch_int_en(data)       ((0x00000004&(data))>>2)
#define DC2_SYS_DC_SECURE_INT_ENABLE_protect0_seq_touch_int_en_shift                  (1)
#define DC2_SYS_DC_SECURE_INT_ENABLE_protect0_seq_touch_int_en_mask                   (0x00000002)
#define DC2_SYS_DC_SECURE_INT_ENABLE_protect0_seq_touch_int_en(data)                  (0x00000002&((data)<<1))
#define DC2_SYS_DC_SECURE_INT_ENABLE_protect0_seq_touch_int_en_src(data)              ((0x00000002&(data))>>1)
#define DC2_SYS_DC_SECURE_INT_ENABLE_get_protect0_seq_touch_int_en(data)              ((0x00000002&(data))>>1)
#define DC2_SYS_DC_SECURE_INT_ENABLE_write_data_shift                                 (0)
#define DC2_SYS_DC_SECURE_INT_ENABLE_write_data_mask                                  (0x00000001)
#define DC2_SYS_DC_SECURE_INT_ENABLE_write_data(data)                                 (0x00000001&((data)<<0))
#define DC2_SYS_DC_SECURE_INT_ENABLE_write_data_src(data)                             ((0x00000001&(data))>>0)
#define DC2_SYS_DC_SECURE_INT_ENABLE_get_write_data(data)                             ((0x00000001&(data))>>0)


#define DC2_SYS_DC_SECURE_INT_STATUS                                                  0x180035A4
#define DC2_SYS_DC_SECURE_INT_STATUS_reg_addr                                         "0xB80035A4"
#define DC2_SYS_DC_SECURE_INT_STATUS_reg                                              0xB80035A4
#define set_DC2_SYS_DC_SECURE_INT_STATUS_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_SECURE_INT_STATUS_reg)=data)
#define get_DC2_SYS_DC_SECURE_INT_STATUS_reg   (*((volatile unsigned int*) DC2_SYS_DC_SECURE_INT_STATUS_reg))
#define DC2_SYS_DC_SECURE_INT_STATUS_inst_adr                                         "0x0069"
#define DC2_SYS_DC_SECURE_INT_STATUS_inst                                             0x0069
#define DC2_SYS_DC_SECURE_INT_STATUS_display_touch_other_int_shift                    (31)
#define DC2_SYS_DC_SECURE_INT_STATUS_display_touch_other_int_mask                     (0x80000000)
#define DC2_SYS_DC_SECURE_INT_STATUS_display_touch_other_int(data)                    (0x80000000&((data)<<31))
#define DC2_SYS_DC_SECURE_INT_STATUS_display_touch_other_int_src(data)                ((0x80000000&(data))>>31)
#define DC2_SYS_DC_SECURE_INT_STATUS_get_display_touch_other_int(data)                ((0x80000000&(data))>>31)
#define DC2_SYS_DC_SECURE_INT_STATUS_display1_touch_int_shift                         (30)
#define DC2_SYS_DC_SECURE_INT_STATUS_display1_touch_int_mask                          (0x40000000)
#define DC2_SYS_DC_SECURE_INT_STATUS_display1_touch_int(data)                         (0x40000000&((data)<<30))
#define DC2_SYS_DC_SECURE_INT_STATUS_display1_touch_int_src(data)                     ((0x40000000&(data))>>30)
#define DC2_SYS_DC_SECURE_INT_STATUS_get_display1_touch_int(data)                     ((0x40000000&(data))>>30)
#define DC2_SYS_DC_SECURE_INT_STATUS_display0_touch_int_shift                         (29)
#define DC2_SYS_DC_SECURE_INT_STATUS_display0_touch_int_mask                          (0x20000000)
#define DC2_SYS_DC_SECURE_INT_STATUS_display0_touch_int(data)                         (0x20000000&((data)<<29))
#define DC2_SYS_DC_SECURE_INT_STATUS_display0_touch_int_src(data)                     ((0x20000000&(data))>>29)
#define DC2_SYS_DC_SECURE_INT_STATUS_get_display0_touch_int(data)                     ((0x20000000&(data))>>29)
#define DC2_SYS_DC_SECURE_INT_STATUS_blk_over_max_secure_addr_int_shift               (28)
#define DC2_SYS_DC_SECURE_INT_STATUS_blk_over_max_secure_addr_int_mask                (0x10000000)
#define DC2_SYS_DC_SECURE_INT_STATUS_blk_over_max_secure_addr_int(data)               (0x10000000&((data)<<28))
#define DC2_SYS_DC_SECURE_INT_STATUS_blk_over_max_secure_addr_int_src(data)           ((0x10000000&(data))>>28)
#define DC2_SYS_DC_SECURE_INT_STATUS_get_blk_over_max_secure_addr_int(data)           ((0x10000000&(data))>>28)
#define DC2_SYS_DC_SECURE_INT_STATUS_seq_over_max_secure_addr_int_shift               (27)
#define DC2_SYS_DC_SECURE_INT_STATUS_seq_over_max_secure_addr_int_mask                (0x08000000)
#define DC2_SYS_DC_SECURE_INT_STATUS_seq_over_max_secure_addr_int(data)               (0x08000000&((data)<<27))
#define DC2_SYS_DC_SECURE_INT_STATUS_seq_over_max_secure_addr_int_src(data)           ((0x08000000&(data))>>27)
#define DC2_SYS_DC_SECURE_INT_STATUS_get_seq_over_max_secure_addr_int(data)           ((0x08000000&(data))>>27)
#define DC2_SYS_DC_SECURE_INT_STATUS_blk_y_overflow_int_shift                         (26)
#define DC2_SYS_DC_SECURE_INT_STATUS_blk_y_overflow_int_mask                          (0x04000000)
#define DC2_SYS_DC_SECURE_INT_STATUS_blk_y_overflow_int(data)                         (0x04000000&((data)<<26))
#define DC2_SYS_DC_SECURE_INT_STATUS_blk_y_overflow_int_src(data)                     ((0x04000000&(data))>>26)
#define DC2_SYS_DC_SECURE_INT_STATUS_get_blk_y_overflow_int(data)                     ((0x04000000&(data))>>26)
#define DC2_SYS_DC_SECURE_INT_STATUS_blk_x_overflow_int_shift                         (25)
#define DC2_SYS_DC_SECURE_INT_STATUS_blk_x_overflow_int_mask                          (0x02000000)
#define DC2_SYS_DC_SECURE_INT_STATUS_blk_x_overflow_int(data)                         (0x02000000&((data)<<25))
#define DC2_SYS_DC_SECURE_INT_STATUS_blk_x_overflow_int_src(data)                     ((0x02000000&(data))>>25)
#define DC2_SYS_DC_SECURE_INT_STATUS_get_blk_x_overflow_int(data)                     ((0x02000000&(data))>>25)
#define DC2_SYS_DC_SECURE_INT_STATUS_content7_blk_touch_int_shift                     (24)
#define DC2_SYS_DC_SECURE_INT_STATUS_content7_blk_touch_int_mask                      (0x01000000)
#define DC2_SYS_DC_SECURE_INT_STATUS_content7_blk_touch_int(data)                     (0x01000000&((data)<<24))
#define DC2_SYS_DC_SECURE_INT_STATUS_content7_blk_touch_int_src(data)                 ((0x01000000&(data))>>24)
#define DC2_SYS_DC_SECURE_INT_STATUS_get_content7_blk_touch_int(data)                 ((0x01000000&(data))>>24)
#define DC2_SYS_DC_SECURE_INT_STATUS_content7_seq_touch_int_shift                     (23)
#define DC2_SYS_DC_SECURE_INT_STATUS_content7_seq_touch_int_mask                      (0x00800000)
#define DC2_SYS_DC_SECURE_INT_STATUS_content7_seq_touch_int(data)                     (0x00800000&((data)<<23))
#define DC2_SYS_DC_SECURE_INT_STATUS_content7_seq_touch_int_src(data)                 ((0x00800000&(data))>>23)
#define DC2_SYS_DC_SECURE_INT_STATUS_get_content7_seq_touch_int(data)                 ((0x00800000&(data))>>23)
#define DC2_SYS_DC_SECURE_INT_STATUS_content6_blk_touch_int_shift                     (22)
#define DC2_SYS_DC_SECURE_INT_STATUS_content6_blk_touch_int_mask                      (0x00400000)
#define DC2_SYS_DC_SECURE_INT_STATUS_content6_blk_touch_int(data)                     (0x00400000&((data)<<22))
#define DC2_SYS_DC_SECURE_INT_STATUS_content6_blk_touch_int_src(data)                 ((0x00400000&(data))>>22)
#define DC2_SYS_DC_SECURE_INT_STATUS_get_content6_blk_touch_int(data)                 ((0x00400000&(data))>>22)
#define DC2_SYS_DC_SECURE_INT_STATUS_content6_seq_touch_int_shift                     (21)
#define DC2_SYS_DC_SECURE_INT_STATUS_content6_seq_touch_int_mask                      (0x00200000)
#define DC2_SYS_DC_SECURE_INT_STATUS_content6_seq_touch_int(data)                     (0x00200000&((data)<<21))
#define DC2_SYS_DC_SECURE_INT_STATUS_content6_seq_touch_int_src(data)                 ((0x00200000&(data))>>21)
#define DC2_SYS_DC_SECURE_INT_STATUS_get_content6_seq_touch_int(data)                 ((0x00200000&(data))>>21)
#define DC2_SYS_DC_SECURE_INT_STATUS_content5_blk_touch_int_shift                     (20)
#define DC2_SYS_DC_SECURE_INT_STATUS_content5_blk_touch_int_mask                      (0x00100000)
#define DC2_SYS_DC_SECURE_INT_STATUS_content5_blk_touch_int(data)                     (0x00100000&((data)<<20))
#define DC2_SYS_DC_SECURE_INT_STATUS_content5_blk_touch_int_src(data)                 ((0x00100000&(data))>>20)
#define DC2_SYS_DC_SECURE_INT_STATUS_get_content5_blk_touch_int(data)                 ((0x00100000&(data))>>20)
#define DC2_SYS_DC_SECURE_INT_STATUS_content5_seq_touch_int_shift                     (19)
#define DC2_SYS_DC_SECURE_INT_STATUS_content5_seq_touch_int_mask                      (0x00080000)
#define DC2_SYS_DC_SECURE_INT_STATUS_content5_seq_touch_int(data)                     (0x00080000&((data)<<19))
#define DC2_SYS_DC_SECURE_INT_STATUS_content5_seq_touch_int_src(data)                 ((0x00080000&(data))>>19)
#define DC2_SYS_DC_SECURE_INT_STATUS_get_content5_seq_touch_int(data)                 ((0x00080000&(data))>>19)
#define DC2_SYS_DC_SECURE_INT_STATUS_content4_blk_touch_int_shift                     (18)
#define DC2_SYS_DC_SECURE_INT_STATUS_content4_blk_touch_int_mask                      (0x00040000)
#define DC2_SYS_DC_SECURE_INT_STATUS_content4_blk_touch_int(data)                     (0x00040000&((data)<<18))
#define DC2_SYS_DC_SECURE_INT_STATUS_content4_blk_touch_int_src(data)                 ((0x00040000&(data))>>18)
#define DC2_SYS_DC_SECURE_INT_STATUS_get_content4_blk_touch_int(data)                 ((0x00040000&(data))>>18)
#define DC2_SYS_DC_SECURE_INT_STATUS_content4_seq_touch_int_shift                     (17)
#define DC2_SYS_DC_SECURE_INT_STATUS_content4_seq_touch_int_mask                      (0x00020000)
#define DC2_SYS_DC_SECURE_INT_STATUS_content4_seq_touch_int(data)                     (0x00020000&((data)<<17))
#define DC2_SYS_DC_SECURE_INT_STATUS_content4_seq_touch_int_src(data)                 ((0x00020000&(data))>>17)
#define DC2_SYS_DC_SECURE_INT_STATUS_get_content4_seq_touch_int(data)                 ((0x00020000&(data))>>17)
#define DC2_SYS_DC_SECURE_INT_STATUS_content3_blk_touch_int_shift                     (16)
#define DC2_SYS_DC_SECURE_INT_STATUS_content3_blk_touch_int_mask                      (0x00010000)
#define DC2_SYS_DC_SECURE_INT_STATUS_content3_blk_touch_int(data)                     (0x00010000&((data)<<16))
#define DC2_SYS_DC_SECURE_INT_STATUS_content3_blk_touch_int_src(data)                 ((0x00010000&(data))>>16)
#define DC2_SYS_DC_SECURE_INT_STATUS_get_content3_blk_touch_int(data)                 ((0x00010000&(data))>>16)
#define DC2_SYS_DC_SECURE_INT_STATUS_content3_seq_touch_int_shift                     (15)
#define DC2_SYS_DC_SECURE_INT_STATUS_content3_seq_touch_int_mask                      (0x00008000)
#define DC2_SYS_DC_SECURE_INT_STATUS_content3_seq_touch_int(data)                     (0x00008000&((data)<<15))
#define DC2_SYS_DC_SECURE_INT_STATUS_content3_seq_touch_int_src(data)                 ((0x00008000&(data))>>15)
#define DC2_SYS_DC_SECURE_INT_STATUS_get_content3_seq_touch_int(data)                 ((0x00008000&(data))>>15)
#define DC2_SYS_DC_SECURE_INT_STATUS_content2_blk_touch_int_shift                     (14)
#define DC2_SYS_DC_SECURE_INT_STATUS_content2_blk_touch_int_mask                      (0x00004000)
#define DC2_SYS_DC_SECURE_INT_STATUS_content2_blk_touch_int(data)                     (0x00004000&((data)<<14))
#define DC2_SYS_DC_SECURE_INT_STATUS_content2_blk_touch_int_src(data)                 ((0x00004000&(data))>>14)
#define DC2_SYS_DC_SECURE_INT_STATUS_get_content2_blk_touch_int(data)                 ((0x00004000&(data))>>14)
#define DC2_SYS_DC_SECURE_INT_STATUS_content2_seq_touch_int_shift                     (13)
#define DC2_SYS_DC_SECURE_INT_STATUS_content2_seq_touch_int_mask                      (0x00002000)
#define DC2_SYS_DC_SECURE_INT_STATUS_content2_seq_touch_int(data)                     (0x00002000&((data)<<13))
#define DC2_SYS_DC_SECURE_INT_STATUS_content2_seq_touch_int_src(data)                 ((0x00002000&(data))>>13)
#define DC2_SYS_DC_SECURE_INT_STATUS_get_content2_seq_touch_int(data)                 ((0x00002000&(data))>>13)
#define DC2_SYS_DC_SECURE_INT_STATUS_content1_blk_touch_int_shift                     (12)
#define DC2_SYS_DC_SECURE_INT_STATUS_content1_blk_touch_int_mask                      (0x00001000)
#define DC2_SYS_DC_SECURE_INT_STATUS_content1_blk_touch_int(data)                     (0x00001000&((data)<<12))
#define DC2_SYS_DC_SECURE_INT_STATUS_content1_blk_touch_int_src(data)                 ((0x00001000&(data))>>12)
#define DC2_SYS_DC_SECURE_INT_STATUS_get_content1_blk_touch_int(data)                 ((0x00001000&(data))>>12)
#define DC2_SYS_DC_SECURE_INT_STATUS_content1_seq_touch_int_shift                     (11)
#define DC2_SYS_DC_SECURE_INT_STATUS_content1_seq_touch_int_mask                      (0x00000800)
#define DC2_SYS_DC_SECURE_INT_STATUS_content1_seq_touch_int(data)                     (0x00000800&((data)<<11))
#define DC2_SYS_DC_SECURE_INT_STATUS_content1_seq_touch_int_src(data)                 ((0x00000800&(data))>>11)
#define DC2_SYS_DC_SECURE_INT_STATUS_get_content1_seq_touch_int(data)                 ((0x00000800&(data))>>11)
#define DC2_SYS_DC_SECURE_INT_STATUS_content0_blk_touch_int_shift                     (10)
#define DC2_SYS_DC_SECURE_INT_STATUS_content0_blk_touch_int_mask                      (0x00000400)
#define DC2_SYS_DC_SECURE_INT_STATUS_content0_blk_touch_int(data)                     (0x00000400&((data)<<10))
#define DC2_SYS_DC_SECURE_INT_STATUS_content0_blk_touch_int_src(data)                 ((0x00000400&(data))>>10)
#define DC2_SYS_DC_SECURE_INT_STATUS_get_content0_blk_touch_int(data)                 ((0x00000400&(data))>>10)
#define DC2_SYS_DC_SECURE_INT_STATUS_content0_seq_touch_int_shift                     (9)
#define DC2_SYS_DC_SECURE_INT_STATUS_content0_seq_touch_int_mask                      (0x00000200)
#define DC2_SYS_DC_SECURE_INT_STATUS_content0_seq_touch_int(data)                     (0x00000200&((data)<<9))
#define DC2_SYS_DC_SECURE_INT_STATUS_content0_seq_touch_int_src(data)                 ((0x00000200&(data))>>9)
#define DC2_SYS_DC_SECURE_INT_STATUS_get_content0_seq_touch_int(data)                 ((0x00000200&(data))>>9)
#define DC2_SYS_DC_SECURE_INT_STATUS_protect3_blk_picset_touch_int_shift              (8)
#define DC2_SYS_DC_SECURE_INT_STATUS_protect3_blk_picset_touch_int_mask               (0x00000100)
#define DC2_SYS_DC_SECURE_INT_STATUS_protect3_blk_picset_touch_int(data)              (0x00000100&((data)<<8))
#define DC2_SYS_DC_SECURE_INT_STATUS_protect3_blk_picset_touch_int_src(data)          ((0x00000100&(data))>>8)
#define DC2_SYS_DC_SECURE_INT_STATUS_get_protect3_blk_picset_touch_int(data)          ((0x00000100&(data))>>8)
#define DC2_SYS_DC_SECURE_INT_STATUS_protect3_seq_touch_int_shift                     (7)
#define DC2_SYS_DC_SECURE_INT_STATUS_protect3_seq_touch_int_mask                      (0x00000080)
#define DC2_SYS_DC_SECURE_INT_STATUS_protect3_seq_touch_int(data)                     (0x00000080&((data)<<7))
#define DC2_SYS_DC_SECURE_INT_STATUS_protect3_seq_touch_int_src(data)                 ((0x00000080&(data))>>7)
#define DC2_SYS_DC_SECURE_INT_STATUS_get_protect3_seq_touch_int(data)                 ((0x00000080&(data))>>7)
#define DC2_SYS_DC_SECURE_INT_STATUS_protect2_blk_picset_touch_int_shift              (6)
#define DC2_SYS_DC_SECURE_INT_STATUS_protect2_blk_picset_touch_int_mask               (0x00000040)
#define DC2_SYS_DC_SECURE_INT_STATUS_protect2_blk_picset_touch_int(data)              (0x00000040&((data)<<6))
#define DC2_SYS_DC_SECURE_INT_STATUS_protect2_blk_picset_touch_int_src(data)          ((0x00000040&(data))>>6)
#define DC2_SYS_DC_SECURE_INT_STATUS_get_protect2_blk_picset_touch_int(data)          ((0x00000040&(data))>>6)
#define DC2_SYS_DC_SECURE_INT_STATUS_protect2_seq_touch_int_shift                     (5)
#define DC2_SYS_DC_SECURE_INT_STATUS_protect2_seq_touch_int_mask                      (0x00000020)
#define DC2_SYS_DC_SECURE_INT_STATUS_protect2_seq_touch_int(data)                     (0x00000020&((data)<<5))
#define DC2_SYS_DC_SECURE_INT_STATUS_protect2_seq_touch_int_src(data)                 ((0x00000020&(data))>>5)
#define DC2_SYS_DC_SECURE_INT_STATUS_get_protect2_seq_touch_int(data)                 ((0x00000020&(data))>>5)
#define DC2_SYS_DC_SECURE_INT_STATUS_protect1_blk_picset_touch_int_shift              (4)
#define DC2_SYS_DC_SECURE_INT_STATUS_protect1_blk_picset_touch_int_mask               (0x00000010)
#define DC2_SYS_DC_SECURE_INT_STATUS_protect1_blk_picset_touch_int(data)              (0x00000010&((data)<<4))
#define DC2_SYS_DC_SECURE_INT_STATUS_protect1_blk_picset_touch_int_src(data)          ((0x00000010&(data))>>4)
#define DC2_SYS_DC_SECURE_INT_STATUS_get_protect1_blk_picset_touch_int(data)          ((0x00000010&(data))>>4)
#define DC2_SYS_DC_SECURE_INT_STATUS_protect1_seq_touch_int_shift                     (3)
#define DC2_SYS_DC_SECURE_INT_STATUS_protect1_seq_touch_int_mask                      (0x00000008)
#define DC2_SYS_DC_SECURE_INT_STATUS_protect1_seq_touch_int(data)                     (0x00000008&((data)<<3))
#define DC2_SYS_DC_SECURE_INT_STATUS_protect1_seq_touch_int_src(data)                 ((0x00000008&(data))>>3)
#define DC2_SYS_DC_SECURE_INT_STATUS_get_protect1_seq_touch_int(data)                 ((0x00000008&(data))>>3)
#define DC2_SYS_DC_SECURE_INT_STATUS_protect0_blk_picset_touch_int_shift              (2)
#define DC2_SYS_DC_SECURE_INT_STATUS_protect0_blk_picset_touch_int_mask               (0x00000004)
#define DC2_SYS_DC_SECURE_INT_STATUS_protect0_blk_picset_touch_int(data)              (0x00000004&((data)<<2))
#define DC2_SYS_DC_SECURE_INT_STATUS_protect0_blk_picset_touch_int_src(data)          ((0x00000004&(data))>>2)
#define DC2_SYS_DC_SECURE_INT_STATUS_get_protect0_blk_picset_touch_int(data)          ((0x00000004&(data))>>2)
#define DC2_SYS_DC_SECURE_INT_STATUS_protect0_seq_touch_int_shift                     (1)
#define DC2_SYS_DC_SECURE_INT_STATUS_protect0_seq_touch_int_mask                      (0x00000002)
#define DC2_SYS_DC_SECURE_INT_STATUS_protect0_seq_touch_int(data)                     (0x00000002&((data)<<1))
#define DC2_SYS_DC_SECURE_INT_STATUS_protect0_seq_touch_int_src(data)                 ((0x00000002&(data))>>1)
#define DC2_SYS_DC_SECURE_INT_STATUS_get_protect0_seq_touch_int(data)                 ((0x00000002&(data))>>1)
#define DC2_SYS_DC_SECURE_INT_STATUS_write_data_shift                                 (0)
#define DC2_SYS_DC_SECURE_INT_STATUS_write_data_mask                                  (0x00000001)
#define DC2_SYS_DC_SECURE_INT_STATUS_write_data(data)                                 (0x00000001&((data)<<0))
#define DC2_SYS_DC_SECURE_INT_STATUS_write_data_src(data)                             ((0x00000001&(data))>>0)
#define DC2_SYS_DC_SECURE_INT_STATUS_get_write_data(data)                             ((0x00000001&(data))>>0)


#define DC2_SYS_DC_SECURE_ERROR_INFO                                                  0x180035A8
#define DC2_SYS_DC_SECURE_ERROR_INFO_reg_addr                                         "0xB80035A8"
#define DC2_SYS_DC_SECURE_ERROR_INFO_reg                                              0xB80035A8
#define set_DC2_SYS_DC_SECURE_ERROR_INFO_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_SECURE_ERROR_INFO_reg)=data)
#define get_DC2_SYS_DC_SECURE_ERROR_INFO_reg   (*((volatile unsigned int*) DC2_SYS_DC_SECURE_ERROR_INFO_reg))
#define DC2_SYS_DC_SECURE_ERROR_INFO_inst_adr                                         "0x006A"
#define DC2_SYS_DC_SECURE_ERROR_INFO_inst                                             0x006A
#define DC2_SYS_DC_SECURE_ERROR_INFO_blk_error_pic_index_shift                        (16)
#define DC2_SYS_DC_SECURE_ERROR_INFO_blk_error_pic_index_mask                         (0x007F0000)
#define DC2_SYS_DC_SECURE_ERROR_INFO_blk_error_pic_index(data)                        (0x007F0000&((data)<<16))
#define DC2_SYS_DC_SECURE_ERROR_INFO_blk_error_pic_index_src(data)                    ((0x007F0000&(data))>>16)
#define DC2_SYS_DC_SECURE_ERROR_INFO_get_blk_error_pic_index(data)                    ((0x007F0000&(data))>>16)
#define DC2_SYS_DC_SECURE_ERROR_INFO_seq_read_error_id_shift                          (8)
#define DC2_SYS_DC_SECURE_ERROR_INFO_seq_read_error_id_mask                           (0x00007F00)
#define DC2_SYS_DC_SECURE_ERROR_INFO_seq_read_error_id(data)                          (0x00007F00&((data)<<8))
#define DC2_SYS_DC_SECURE_ERROR_INFO_seq_read_error_id_src(data)                      ((0x00007F00&(data))>>8)
#define DC2_SYS_DC_SECURE_ERROR_INFO_get_seq_read_error_id(data)                      ((0x00007F00&(data))>>8)
#define DC2_SYS_DC_SECURE_ERROR_INFO_seq_write_error_id_shift                         (0)
#define DC2_SYS_DC_SECURE_ERROR_INFO_seq_write_error_id_mask                          (0x0000007F)
#define DC2_SYS_DC_SECURE_ERROR_INFO_seq_write_error_id(data)                         (0x0000007F&((data)<<0))
#define DC2_SYS_DC_SECURE_ERROR_INFO_seq_write_error_id_src(data)                     ((0x0000007F&(data))>>0)
#define DC2_SYS_DC_SECURE_ERROR_INFO_get_seq_write_error_id(data)                     ((0x0000007F&(data))>>0)


#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE                                              0x180035AC
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_reg_addr                                     "0xB80035AC"
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_reg                                          0xB80035AC
#define set_DC2_SYS_DC_SECURE_KEY_INT_ENABLE_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_SECURE_KEY_INT_ENABLE_reg)=data)
#define get_DC2_SYS_DC_SECURE_KEY_INT_ENABLE_reg   (*((volatile unsigned int*) DC2_SYS_DC_SECURE_KEY_INT_ENABLE_reg))
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_inst_adr                                     "0x006B"
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_inst                                         0x006B
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_content7_key_updated_int_en_shift            (8)
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_content7_key_updated_int_en_mask             (0x00000100)
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_content7_key_updated_int_en(data)            (0x00000100&((data)<<8))
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_content7_key_updated_int_en_src(data)        ((0x00000100&(data))>>8)
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_get_content7_key_updated_int_en(data)        ((0x00000100&(data))>>8)
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_content6_key_updated_int_en_shift            (7)
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_content6_key_updated_int_en_mask             (0x00000080)
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_content6_key_updated_int_en(data)            (0x00000080&((data)<<7))
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_content6_key_updated_int_en_src(data)        ((0x00000080&(data))>>7)
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_get_content6_key_updated_int_en(data)        ((0x00000080&(data))>>7)
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_content5_key_updated_int_en_shift            (6)
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_content5_key_updated_int_en_mask             (0x00000040)
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_content5_key_updated_int_en(data)            (0x00000040&((data)<<6))
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_content5_key_updated_int_en_src(data)        ((0x00000040&(data))>>6)
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_get_content5_key_updated_int_en(data)        ((0x00000040&(data))>>6)
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_content4_key_updated_int_en_shift            (5)
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_content4_key_updated_int_en_mask             (0x00000020)
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_content4_key_updated_int_en(data)            (0x00000020&((data)<<5))
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_content4_key_updated_int_en_src(data)        ((0x00000020&(data))>>5)
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_get_content4_key_updated_int_en(data)        ((0x00000020&(data))>>5)
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_content3_key_updated_int_en_shift            (4)
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_content3_key_updated_int_en_mask             (0x00000010)
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_content3_key_updated_int_en(data)            (0x00000010&((data)<<4))
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_content3_key_updated_int_en_src(data)        ((0x00000010&(data))>>4)
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_get_content3_key_updated_int_en(data)        ((0x00000010&(data))>>4)
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_content2_key_updated_int_en_shift            (3)
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_content2_key_updated_int_en_mask             (0x00000008)
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_content2_key_updated_int_en(data)            (0x00000008&((data)<<3))
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_content2_key_updated_int_en_src(data)        ((0x00000008&(data))>>3)
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_get_content2_key_updated_int_en(data)        ((0x00000008&(data))>>3)
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_content1_key_updated_int_en_shift            (2)
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_content1_key_updated_int_en_mask             (0x00000004)
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_content1_key_updated_int_en(data)            (0x00000004&((data)<<2))
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_content1_key_updated_int_en_src(data)        ((0x00000004&(data))>>2)
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_get_content1_key_updated_int_en(data)        ((0x00000004&(data))>>2)
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_content0_key_updated_int_en_shift            (1)
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_content0_key_updated_int_en_mask             (0x00000002)
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_content0_key_updated_int_en(data)            (0x00000002&((data)<<1))
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_content0_key_updated_int_en_src(data)        ((0x00000002&(data))>>1)
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_get_content0_key_updated_int_en(data)        ((0x00000002&(data))>>1)
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_write_data_shift                             (0)
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_write_data_mask                              (0x00000001)
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_write_data(data)                             (0x00000001&((data)<<0))
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_write_data_src(data)                         ((0x00000001&(data))>>0)
#define DC2_SYS_DC_SECURE_KEY_INT_ENABLE_get_write_data(data)                         ((0x00000001&(data))>>0)


#define DC2_SYS_DC_SECURE_KEY_INT_STATUS                                              0x180035B0
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_reg_addr                                     "0xB80035B0"
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_reg                                          0xB80035B0
#define set_DC2_SYS_DC_SECURE_KEY_INT_STATUS_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_SECURE_KEY_INT_STATUS_reg)=data)
#define get_DC2_SYS_DC_SECURE_KEY_INT_STATUS_reg   (*((volatile unsigned int*) DC2_SYS_DC_SECURE_KEY_INT_STATUS_reg))
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_inst_adr                                     "0x006C"
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_inst                                         0x006C
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_content7_key_updated_int_shift               (8)
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_content7_key_updated_int_mask                (0x00000100)
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_content7_key_updated_int(data)               (0x00000100&((data)<<8))
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_content7_key_updated_int_src(data)           ((0x00000100&(data))>>8)
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_get_content7_key_updated_int(data)           ((0x00000100&(data))>>8)
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_content6_key_updated_int_shift               (7)
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_content6_key_updated_int_mask                (0x00000080)
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_content6_key_updated_int(data)               (0x00000080&((data)<<7))
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_content6_key_updated_int_src(data)           ((0x00000080&(data))>>7)
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_get_content6_key_updated_int(data)           ((0x00000080&(data))>>7)
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_content5_key_updated_int_shift               (6)
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_content5_key_updated_int_mask                (0x00000040)
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_content5_key_updated_int(data)               (0x00000040&((data)<<6))
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_content5_key_updated_int_src(data)           ((0x00000040&(data))>>6)
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_get_content5_key_updated_int(data)           ((0x00000040&(data))>>6)
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_content4_key_updated_int_shift               (5)
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_content4_key_updated_int_mask                (0x00000020)
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_content4_key_updated_int(data)               (0x00000020&((data)<<5))
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_content4_key_updated_int_src(data)           ((0x00000020&(data))>>5)
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_get_content4_key_updated_int(data)           ((0x00000020&(data))>>5)
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_content3_key_updated_int_shift               (4)
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_content3_key_updated_int_mask                (0x00000010)
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_content3_key_updated_int(data)               (0x00000010&((data)<<4))
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_content3_key_updated_int_src(data)           ((0x00000010&(data))>>4)
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_get_content3_key_updated_int(data)           ((0x00000010&(data))>>4)
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_content2_key_updated_int_shift               (3)
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_content2_key_updated_int_mask                (0x00000008)
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_content2_key_updated_int(data)               (0x00000008&((data)<<3))
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_content2_key_updated_int_src(data)           ((0x00000008&(data))>>3)
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_get_content2_key_updated_int(data)           ((0x00000008&(data))>>3)
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_content1_key_updated_int_shift               (2)
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_content1_key_updated_int_mask                (0x00000004)
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_content1_key_updated_int(data)               (0x00000004&((data)<<2))
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_content1_key_updated_int_src(data)           ((0x00000004&(data))>>2)
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_get_content1_key_updated_int(data)           ((0x00000004&(data))>>2)
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_content0_key_updated_int_shift               (1)
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_content0_key_updated_int_mask                (0x00000002)
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_content0_key_updated_int(data)               (0x00000002&((data)<<1))
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_content0_key_updated_int_src(data)           ((0x00000002&(data))>>1)
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_get_content0_key_updated_int(data)           ((0x00000002&(data))>>1)
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_write_data_shift                             (0)
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_write_data_mask                              (0x00000001)
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_write_data(data)                             (0x00000001&((data)<<0))
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_write_data_src(data)                         ((0x00000001&(data))>>0)
#define DC2_SYS_DC_SECURE_KEY_INT_STATUS_get_write_data(data)                         ((0x00000001&(data))>>0)


#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2                                             0x180035B4
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_reg_addr                                    "0xB80035B4"
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_reg                                         0xB80035B4
#define set_DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_reg)=data)
#define get_DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_reg   (*((volatile unsigned int*) DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_reg))
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_inst_adr                                    "0x006D"
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_inst                                        0x006D
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_display_touch_other_en_shift                (31)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_display_touch_other_en_mask                 (0x80000000)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_display_touch_other_en(data)                (0x80000000&((data)<<31))
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_display_touch_other_en_src(data)            ((0x80000000&(data))>>31)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_get_display_touch_other_en(data)            ((0x80000000&(data))>>31)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_display1_touch_en_shift                     (30)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_display1_touch_en_mask                      (0x40000000)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_display1_touch_en(data)                     (0x40000000&((data)<<30))
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_display1_touch_en_src(data)                 ((0x40000000&(data))>>30)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_get_display1_touch_en(data)                 ((0x40000000&(data))>>30)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_display0_touch_en_shift                     (29)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_display0_touch_en_mask                      (0x20000000)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_display0_touch_en(data)                     (0x20000000&((data)<<29))
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_display0_touch_en_src(data)                 ((0x20000000&(data))>>29)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_get_display0_touch_en(data)                 ((0x20000000&(data))>>29)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_seq_over_max_secure_addr_int_en_shift       (27)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_seq_over_max_secure_addr_int_en_mask        (0x08000000)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_seq_over_max_secure_addr_int_en(data)       (0x08000000&((data)<<27))
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_seq_over_max_secure_addr_int_en_src(data)   ((0x08000000&(data))>>27)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_get_seq_over_max_secure_addr_int_en(data)   ((0x08000000&(data))>>27)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_blk_y_overflow_int_en_shift                 (26)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_blk_y_overflow_int_en_mask                  (0x04000000)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_blk_y_overflow_int_en(data)                 (0x04000000&((data)<<26))
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_blk_y_overflow_int_en_src(data)             ((0x04000000&(data))>>26)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_get_blk_y_overflow_int_en(data)             ((0x04000000&(data))>>26)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_blk_x_overflow_int_en_shift                 (25)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_blk_x_overflow_int_en_mask                  (0x02000000)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_blk_x_overflow_int_en(data)                 (0x02000000&((data)<<25))
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_blk_x_overflow_int_en_src(data)             ((0x02000000&(data))>>25)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_get_blk_x_overflow_int_en(data)             ((0x02000000&(data))>>25)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_content7_seq_touch_int_en_shift             (23)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_content7_seq_touch_int_en_mask              (0x00800000)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_content7_seq_touch_int_en(data)             (0x00800000&((data)<<23))
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_content7_seq_touch_int_en_src(data)         ((0x00800000&(data))>>23)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_get_content7_seq_touch_int_en(data)         ((0x00800000&(data))>>23)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_content6_seq_touch_int_en_shift             (21)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_content6_seq_touch_int_en_mask              (0x00200000)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_content6_seq_touch_int_en(data)             (0x00200000&((data)<<21))
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_content6_seq_touch_int_en_src(data)         ((0x00200000&(data))>>21)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_get_content6_seq_touch_int_en(data)         ((0x00200000&(data))>>21)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_content5_seq_touch_int_en_shift             (19)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_content5_seq_touch_int_en_mask              (0x00080000)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_content5_seq_touch_int_en(data)             (0x00080000&((data)<<19))
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_content5_seq_touch_int_en_src(data)         ((0x00080000&(data))>>19)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_get_content5_seq_touch_int_en(data)         ((0x00080000&(data))>>19)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_content4_seq_touch_int_en_shift             (17)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_content4_seq_touch_int_en_mask              (0x00020000)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_content4_seq_touch_int_en(data)             (0x00020000&((data)<<17))
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_content4_seq_touch_int_en_src(data)         ((0x00020000&(data))>>17)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_get_content4_seq_touch_int_en(data)         ((0x00020000&(data))>>17)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_content3_seq_touch_int_en_shift             (15)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_content3_seq_touch_int_en_mask              (0x00008000)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_content3_seq_touch_int_en(data)             (0x00008000&((data)<<15))
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_content3_seq_touch_int_en_src(data)         ((0x00008000&(data))>>15)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_get_content3_seq_touch_int_en(data)         ((0x00008000&(data))>>15)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_content2_seq_touch_int_en_shift             (13)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_content2_seq_touch_int_en_mask              (0x00002000)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_content2_seq_touch_int_en(data)             (0x00002000&((data)<<13))
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_content2_seq_touch_int_en_src(data)         ((0x00002000&(data))>>13)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_get_content2_seq_touch_int_en(data)         ((0x00002000&(data))>>13)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_content1_seq_touch_int_en_shift             (11)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_content1_seq_touch_int_en_mask              (0x00000800)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_content1_seq_touch_int_en(data)             (0x00000800&((data)<<11))
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_content1_seq_touch_int_en_src(data)         ((0x00000800&(data))>>11)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_get_content1_seq_touch_int_en(data)         ((0x00000800&(data))>>11)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_content0_seq_touch_int_en_shift             (9)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_content0_seq_touch_int_en_mask              (0x00000200)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_content0_seq_touch_int_en(data)             (0x00000200&((data)<<9))
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_content0_seq_touch_int_en_src(data)         ((0x00000200&(data))>>9)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_get_content0_seq_touch_int_en(data)         ((0x00000200&(data))>>9)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_protect3_seq_touch_int_en_shift             (7)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_protect3_seq_touch_int_en_mask              (0x00000080)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_protect3_seq_touch_int_en(data)             (0x00000080&((data)<<7))
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_protect3_seq_touch_int_en_src(data)         ((0x00000080&(data))>>7)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_get_protect3_seq_touch_int_en(data)         ((0x00000080&(data))>>7)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_protect2_seq_touch_int_en_shift             (5)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_protect2_seq_touch_int_en_mask              (0x00000020)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_protect2_seq_touch_int_en(data)             (0x00000020&((data)<<5))
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_protect2_seq_touch_int_en_src(data)         ((0x00000020&(data))>>5)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_get_protect2_seq_touch_int_en(data)         ((0x00000020&(data))>>5)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_protect1_seq_touch_int_en_shift             (3)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_protect1_seq_touch_int_en_mask              (0x00000008)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_protect1_seq_touch_int_en(data)             (0x00000008&((data)<<3))
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_protect1_seq_touch_int_en_src(data)         ((0x00000008&(data))>>3)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_get_protect1_seq_touch_int_en(data)         ((0x00000008&(data))>>3)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_protect0_seq_touch_int_en_shift             (1)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_protect0_seq_touch_int_en_mask              (0x00000002)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_protect0_seq_touch_int_en(data)             (0x00000002&((data)<<1))
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_protect0_seq_touch_int_en_src(data)         ((0x00000002&(data))>>1)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_get_protect0_seq_touch_int_en(data)         ((0x00000002&(data))>>1)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_write_data_shift                            (0)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_write_data_mask                             (0x00000001)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_write_data(data)                            (0x00000001&((data)<<0))
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_write_data_src(data)                        ((0x00000001&(data))>>0)
#define DC2_SYS_DC_SECURE_INT_ENABLE_SYS2_get_write_data(data)                        ((0x00000001&(data))>>0)


#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2                                             0x180035B8
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_reg_addr                                    "0xB80035B8"
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_reg                                         0xB80035B8
#define set_DC2_SYS_DC_SECURE_INT_STATUS_SYS2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_SECURE_INT_STATUS_SYS2_reg)=data)
#define get_DC2_SYS_DC_SECURE_INT_STATUS_SYS2_reg   (*((volatile unsigned int*) DC2_SYS_DC_SECURE_INT_STATUS_SYS2_reg))
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_inst_adr                                    "0x006E"
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_inst                                        0x006E
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_display_touch_other_int_shift               (31)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_display_touch_other_int_mask                (0x80000000)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_display_touch_other_int(data)               (0x80000000&((data)<<31))
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_display_touch_other_int_src(data)           ((0x80000000&(data))>>31)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_get_display_touch_other_int(data)           ((0x80000000&(data))>>31)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_display1_touch_int_shift                    (30)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_display1_touch_int_mask                     (0x40000000)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_display1_touch_int(data)                    (0x40000000&((data)<<30))
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_display1_touch_int_src(data)                ((0x40000000&(data))>>30)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_get_display1_touch_int(data)                ((0x40000000&(data))>>30)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_display0_touch_int_shift                    (29)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_display0_touch_int_mask                     (0x20000000)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_display0_touch_int(data)                    (0x20000000&((data)<<29))
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_display0_touch_int_src(data)                ((0x20000000&(data))>>29)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_get_display0_touch_int(data)                ((0x20000000&(data))>>29)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_seq_over_max_secure_addr_int_shift          (27)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_seq_over_max_secure_addr_int_mask           (0x08000000)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_seq_over_max_secure_addr_int(data)          (0x08000000&((data)<<27))
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_seq_over_max_secure_addr_int_src(data)      ((0x08000000&(data))>>27)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_get_seq_over_max_secure_addr_int(data)      ((0x08000000&(data))>>27)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_blk_y_overflow_int_shift                    (26)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_blk_y_overflow_int_mask                     (0x04000000)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_blk_y_overflow_int(data)                    (0x04000000&((data)<<26))
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_blk_y_overflow_int_src(data)                ((0x04000000&(data))>>26)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_get_blk_y_overflow_int(data)                ((0x04000000&(data))>>26)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_blk_x_overflow_int_shift                    (25)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_blk_x_overflow_int_mask                     (0x02000000)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_blk_x_overflow_int(data)                    (0x02000000&((data)<<25))
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_blk_x_overflow_int_src(data)                ((0x02000000&(data))>>25)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_get_blk_x_overflow_int(data)                ((0x02000000&(data))>>25)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_content7_seq_touch_int_shift                (23)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_content7_seq_touch_int_mask                 (0x00800000)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_content7_seq_touch_int(data)                (0x00800000&((data)<<23))
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_content7_seq_touch_int_src(data)            ((0x00800000&(data))>>23)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_get_content7_seq_touch_int(data)            ((0x00800000&(data))>>23)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_content6_seq_touch_int_shift                (21)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_content6_seq_touch_int_mask                 (0x00200000)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_content6_seq_touch_int(data)                (0x00200000&((data)<<21))
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_content6_seq_touch_int_src(data)            ((0x00200000&(data))>>21)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_get_content6_seq_touch_int(data)            ((0x00200000&(data))>>21)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_content5_seq_touch_int_shift                (19)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_content5_seq_touch_int_mask                 (0x00080000)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_content5_seq_touch_int(data)                (0x00080000&((data)<<19))
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_content5_seq_touch_int_src(data)            ((0x00080000&(data))>>19)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_get_content5_seq_touch_int(data)            ((0x00080000&(data))>>19)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_content4_seq_touch_int_shift                (17)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_content4_seq_touch_int_mask                 (0x00020000)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_content4_seq_touch_int(data)                (0x00020000&((data)<<17))
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_content4_seq_touch_int_src(data)            ((0x00020000&(data))>>17)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_get_content4_seq_touch_int(data)            ((0x00020000&(data))>>17)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_content3_seq_touch_int_shift                (15)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_content3_seq_touch_int_mask                 (0x00008000)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_content3_seq_touch_int(data)                (0x00008000&((data)<<15))
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_content3_seq_touch_int_src(data)            ((0x00008000&(data))>>15)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_get_content3_seq_touch_int(data)            ((0x00008000&(data))>>15)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_content2_seq_touch_int_shift                (13)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_content2_seq_touch_int_mask                 (0x00002000)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_content2_seq_touch_int(data)                (0x00002000&((data)<<13))
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_content2_seq_touch_int_src(data)            ((0x00002000&(data))>>13)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_get_content2_seq_touch_int(data)            ((0x00002000&(data))>>13)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_content1_seq_touch_int_shift                (11)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_content1_seq_touch_int_mask                 (0x00000800)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_content1_seq_touch_int(data)                (0x00000800&((data)<<11))
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_content1_seq_touch_int_src(data)            ((0x00000800&(data))>>11)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_get_content1_seq_touch_int(data)            ((0x00000800&(data))>>11)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_content0_seq_touch_int_shift                (9)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_content0_seq_touch_int_mask                 (0x00000200)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_content0_seq_touch_int(data)                (0x00000200&((data)<<9))
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_content0_seq_touch_int_src(data)            ((0x00000200&(data))>>9)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_get_content0_seq_touch_int(data)            ((0x00000200&(data))>>9)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_protect3_seq_touch_int_shift                (7)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_protect3_seq_touch_int_mask                 (0x00000080)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_protect3_seq_touch_int(data)                (0x00000080&((data)<<7))
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_protect3_seq_touch_int_src(data)            ((0x00000080&(data))>>7)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_get_protect3_seq_touch_int(data)            ((0x00000080&(data))>>7)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_protect2_seq_touch_int_shift                (5)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_protect2_seq_touch_int_mask                 (0x00000020)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_protect2_seq_touch_int(data)                (0x00000020&((data)<<5))
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_protect2_seq_touch_int_src(data)            ((0x00000020&(data))>>5)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_get_protect2_seq_touch_int(data)            ((0x00000020&(data))>>5)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_protect1_seq_touch_int_shift                (3)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_protect1_seq_touch_int_mask                 (0x00000008)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_protect1_seq_touch_int(data)                (0x00000008&((data)<<3))
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_protect1_seq_touch_int_src(data)            ((0x00000008&(data))>>3)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_get_protect1_seq_touch_int(data)            ((0x00000008&(data))>>3)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_protect0_seq_touch_int_shift                (1)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_protect0_seq_touch_int_mask                 (0x00000002)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_protect0_seq_touch_int(data)                (0x00000002&((data)<<1))
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_protect0_seq_touch_int_src(data)            ((0x00000002&(data))>>1)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_get_protect0_seq_touch_int(data)            ((0x00000002&(data))>>1)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_write_data_shift                            (0)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_write_data_mask                             (0x00000001)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_write_data(data)                            (0x00000001&((data)<<0))
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_write_data_src(data)                        ((0x00000001&(data))>>0)
#define DC2_SYS_DC_SECURE_INT_STATUS_SYS2_get_write_data(data)                        ((0x00000001&(data))>>0)


#define DC2_SYS_DC_SECURE_ERROR_INFO_SYS2                                             0x180035BC
#define DC2_SYS_DC_SECURE_ERROR_INFO_SYS2_reg_addr                                    "0xB80035BC"
#define DC2_SYS_DC_SECURE_ERROR_INFO_SYS2_reg                                         0xB80035BC
#define set_DC2_SYS_DC_SECURE_ERROR_INFO_SYS2_reg(data)   (*((volatile unsigned int*) DC2_SYS_DC_SECURE_ERROR_INFO_SYS2_reg)=data)
#define get_DC2_SYS_DC_SECURE_ERROR_INFO_SYS2_reg   (*((volatile unsigned int*) DC2_SYS_DC_SECURE_ERROR_INFO_SYS2_reg))
#define DC2_SYS_DC_SECURE_ERROR_INFO_SYS2_inst_adr                                    "0x006F"
#define DC2_SYS_DC_SECURE_ERROR_INFO_SYS2_inst                                        0x006F
#define DC2_SYS_DC_SECURE_ERROR_INFO_SYS2_seq_read_error_id_shift                     (8)
#define DC2_SYS_DC_SECURE_ERROR_INFO_SYS2_seq_read_error_id_mask                      (0x00007F00)
#define DC2_SYS_DC_SECURE_ERROR_INFO_SYS2_seq_read_error_id(data)                     (0x00007F00&((data)<<8))
#define DC2_SYS_DC_SECURE_ERROR_INFO_SYS2_seq_read_error_id_src(data)                 ((0x00007F00&(data))>>8)
#define DC2_SYS_DC_SECURE_ERROR_INFO_SYS2_get_seq_read_error_id(data)                 ((0x00007F00&(data))>>8)
#define DC2_SYS_DC_SECURE_ERROR_INFO_SYS2_seq_write_error_id_shift                    (0)
#define DC2_SYS_DC_SECURE_ERROR_INFO_SYS2_seq_write_error_id_mask                     (0x0000007F)
#define DC2_SYS_DC_SECURE_ERROR_INFO_SYS2_seq_write_error_id(data)                    (0x0000007F&((data)<<0))
#define DC2_SYS_DC_SECURE_ERROR_INFO_SYS2_seq_write_error_id_src(data)                ((0x0000007F&(data))>>0)
#define DC2_SYS_DC_SECURE_ERROR_INFO_SYS2_get_seq_write_error_id(data)                ((0x0000007F&(data))>>0)

#endif
