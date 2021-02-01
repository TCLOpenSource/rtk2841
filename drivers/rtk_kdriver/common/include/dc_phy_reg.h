/**************************************************************
// Spec Version                  : 0.68
// Parser Version                : DVR_Parser_6.11(120105)
// CModelGen Version             : 5.1 2012.01.05
// Naming Rule                   :  Module_Register_Name
// Naming Rule                   : Module_Register_Name_reg
// Parse Option                  : Only Parse _op1
// Parse Address Region          : All Address Region 
// Decode bit number             : 12 bits
// Firmware Header Generate Date : 2014/2/10 11:24:31
***************************************************************/


#ifndef _DC_PHY_REG_H_INCLUDED_
#define _DC_PHY_REG_H_INCLUDED_
#ifdef  _DC_PHY_USE_STRUCT
typedef struct 
{
unsigned int     reserved_0:7;
unsigned int     tmras:9;
unsigned int     tmrcl:4;
unsigned int     tmcl:4;
unsigned int     reserved_1:1;
unsigned int     reserved_2:7;
}DC_PHY_TMCTRL0;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     tmrrd:5;
unsigned int     reserved_1:2;
unsigned int     tmrp:6;
unsigned int     reserved_2:2;
unsigned int     tmrcd:6;
unsigned int     tmrc:8;
}DC_PHY_TMCTRL1;

typedef struct 
{
unsigned int     tmccd_r2r:4;
unsigned int     tmccd:4;
unsigned int     reserved_0:1;
unsigned int     trtp:7;
unsigned int     reserved_1:3;
unsigned int     tmwtr:5;
unsigned int     reserved_2:2;
unsigned int     tmwr:6;
}DC_PHY_TMCTRL2;

typedef struct 
{
unsigned int     tmFAW:8;
unsigned int     refcycle:12;
unsigned int     reserved_0:1;
unsigned int     tmrfc:11;
}DC_PHY_TMCTRL3;

typedef struct 
{
unsigned int     reserved_0:2;
unsigned int     tAOND:6;
unsigned int     reserved_1:2;
unsigned int     tAOFD:6;
unsigned int     tmmod:8;
unsigned int     reserved_2:3;
unsigned int     tmmrd:5;
}DC_PHY_TMCTRL4;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     tmrtw:4;
unsigned int     tzqoper:12;
unsigned int     tzqinit:12;
}DC_PHY_TMCTRL5;

typedef struct 
{
unsigned int     dqs_lat_sel:1;
unsigned int     dqs_lat:7;
unsigned int     tdllk:12;
unsigned int     tzqcs:12;
}DC_PHY_TMCTRL6;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     ddr3_odt_dly_1T:1;
unsigned int     ddr3_odt_ext_1T:1;
unsigned int     reserved_1:1;
unsigned int     reserved_2:1;
unsigned int     reserved_3:1;
unsigned int     odt_force_sel:1;
unsigned int     odt_force_sig:1;
unsigned int     odt_en:1;
unsigned int     odt_dis:1;
unsigned int     reserved_4:5;
unsigned int     reserved_5:15;
}DC_PHY_ODT_CTRL;

typedef struct 
{
unsigned int     reserved_0:18;
unsigned int     reserved_1:6;
unsigned int     reserved_2:8;
}DC_PHY_CAL_CTRL2;

typedef struct 
{
unsigned int     reserved_0:26;
unsigned int     reserved_1:1;
unsigned int     init:1;
unsigned int     sren:1;
unsigned int     srex:1;
unsigned int     exe_emr:1;
unsigned int     exe_mr:1;
}DC_PHY_DC_MIS2;

typedef struct 
{
unsigned int     reserved_0:7;
unsigned int     rcd_not_eq:1;
unsigned int     reserved_1:2;
unsigned int     tmrcdwr:6;
unsigned int     tmrp_all_add:2;
unsigned int     reserved_2:1;
unsigned int     reserved_3:1;
unsigned int     reserved_4:12;
}DC_PHY_DC_MIS;

typedef struct 
{
unsigned int     reserved_0:18;
unsigned int     ref_after_last_cmd:1;
unsigned int     pre_dis:1;
unsigned int     reserved_1:9;
unsigned int     lbk_en:1;
unsigned int     reserved_2:2;
}DC_PHY_DC_MISA;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     tmrc_sel:1;
unsigned int     reserved_1:28;
}DC_PHY_DC_MISB;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     reserved_1:1;
unsigned int     reserved_2:1;
unsigned int     reserved_3:1;
unsigned int     reserved_4:1;
unsigned int     reserved_5:24;
}DC_PHY_DC_MISC;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     reserved_1:1;
unsigned int     reserved_2:1;
unsigned int     reserved_3:1;
}DC_PHY_DC_TEST_MODE_SEL;

typedef struct 
{
unsigned int     write_en_15:1;
unsigned int     dis_ap:1;
unsigned int     write_en_14:1;
unsigned int     ddr3_swap:1;
unsigned int     write_en_13:1;
unsigned int     end_500us:1;
unsigned int     write_en_12:1;
unsigned int     end_200us:1;
unsigned int     write_en_11:1;
unsigned int     fast_prechg:1;
unsigned int     write_en_10:1;
unsigned int     dis_cti:1;
unsigned int     write_en_9:1;
unsigned int     dis_8bank:1;
unsigned int     write_en_8:1;
unsigned int     use_tmmrd:1;
unsigned int     write_en_7:1;
unsigned int     dis_pre_all:1;
unsigned int     write_en_6:1;
unsigned int     ddr3_zqcl_short:1;
unsigned int     write_en_5:1;
unsigned int     ddr3_exe_zqcl:1;
unsigned int     write_en_4:1;
unsigned int     ddr3_exe_mr3:1;
unsigned int     write_en_3:1;
unsigned int     ddr3_exe_mr2:1;
unsigned int     write_en_2:1;
unsigned int     ddr3_exe_mr1:1;
unsigned int     write_en_1:1;
unsigned int     ddr3_exe_mr0:1;
unsigned int     write_en_0:1;
unsigned int     ddr3_init:1;
}DC_PHY_DC_DDR3_CTL;

typedef struct 
{
unsigned int     exmod_reg:16;
unsigned int     mod_reg:16;
}DC_PHY_MOD_REG;

typedef struct 
{
unsigned int     mod3_reg:16;
unsigned int     mod2_reg:16;
}DC_PHY_MOD23_REG;

typedef struct 
{
unsigned int     reserved_0:19;
unsigned int     wfifo_rdy_gated:1;
unsigned int     reserved_1:3;
unsigned int     rdwr_use_full:1;
unsigned int     full_gated:1;
unsigned int     rfifo_thred:7;
}DC_PHY_RFIFO_CTL;

typedef struct 
{
unsigned int     reserved_0:22;
unsigned int     sys2_wfifo_underflow:1;
unsigned int     sys2_wfifo_overflow:1;
unsigned int     sys1_wfifo_underflow:1;
unsigned int     sys1_wfifo_overflow:1;
unsigned int     sys2_qfifo_underflow:1;
unsigned int     sys2_qfifo_overflow:1;
unsigned int     sys1_qfifo_underflow:1;
unsigned int     sys1_qfifo_overflow:1;
unsigned int     err_cti_cmd:1;
unsigned int     err_active:1;
}DC_PHY_ERR_STATUS;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     exe_prea:1;
unsigned int     dis_refresh:1;
unsigned int     reserved_1:1;
unsigned int     reserved_2:1;
}DC_PHY_DC_WRITE_LEVEL;

typedef struct 
{
unsigned int     reserved_0:18;
unsigned int     int_sys2_wfifo_underflow_en:1;
unsigned int     int_sys2_wfifo_overflow_en:1;
unsigned int     int_sys1_wfifo_underflow_en:1;
unsigned int     int_sys1_wfifo_overflow_en:1;
unsigned int     int_sys2_qfifo_underflow_en:1;
unsigned int     int_sys2_qfifo_overflow_en:1;
unsigned int     int_sys1_qfifo_underflow_en:1;
unsigned int     int_sys1_qfifo_overflow_en:1;
unsigned int     reserved_1:1;
unsigned int     int_err_cticmd_en:1;
unsigned int     int_err_active_en:1;
unsigned int     reserved_2:1;
unsigned int     reserved_3:1;
unsigned int     int_en:1;
}DC_PHY_INT_ENABLE;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     reserved_1:1;
unsigned int     reserved_2:7;
}DC_PHY_RFIFO_MAXCNT;

typedef struct 
{
unsigned int     bank_act:8;
unsigned int     reserved_0:1;
unsigned int     cmd_cnt:3;
unsigned int     reserved_1:1;
unsigned int     par_st:19;
}DC_PHY_SM_STATUS;

typedef struct 
{
unsigned int     reserved_0:1;
unsigned int     wfifo_ddr_req_statistic_en:1;
unsigned int     clear_wfifo_record:1;
unsigned int     reserved_1:5;
unsigned int     wfifo_rd_cnt_et:8;
unsigned int     wfifo_rd_cnt_rl:8;
unsigned int     wfifo_wr_cnt_rl:8;
}DC_PHY_WFIFO_CNT;

typedef struct 
{
unsigned int     reserved_0:5;
unsigned int     reserved_1:3;
unsigned int     reserved_2:1;
unsigned int     reserved_3:3;
unsigned int     reserved_4:4;
unsigned int     reserved_5:7;
unsigned int     reserved_6:3;
unsigned int     dbg_mod:6;
}DC_PHY_DC_DEBUG;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     reserved_1:16;
}DC_PHY_PRE_CNT;

typedef struct 
{
unsigned int     reserved_0:32;
}DC_PHY_WFIFO_SYS_REQ_WAIT;

typedef struct 
{
unsigned int     wfifo_ddr_req_wait_total:32;
}DC_PHY_WFIFO_DDR_REQ_WAIT;

typedef struct 
{
unsigned int     wfifo_ddr_req_wait_max:16;
unsigned int     reserved_0:16;
}DC_PHY_WFIFO_MAX_REQ_WAIT;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     short_zqcl_per_sel:3;
unsigned int     auto_short_zqcl_en:1;
}DC_PHY_AUTO_SHORT_ZQ_CAL;

typedef struct 
{
unsigned int     reserved_0:1;
unsigned int     wfifo_ddr_req_statistic_en:1;
unsigned int     clear_wfifo_record:1;
unsigned int     reserved_1:5;
unsigned int     wfifo_rd_cnt_et:8;
unsigned int     wfifo_rd_cnt_rl:8;
unsigned int     wfifo_wr_cnt_rl:8;
}DC_PHY_WFIFO2_CNT;

typedef struct 
{
unsigned int     wfifo_ddr_req_wait_total:32;
}DC_PHY_WFIFO2_DDR_REQ_WAIT;

typedef struct 
{
unsigned int     wfifo_ddr_req_wait_max:16;
unsigned int     reserved_0:16;
}DC_PHY_WFIFO2_MAX_REQ_WAIT;

typedef struct 
{
unsigned int     dummy_reg:32;
}DC_PHY_DUMMY_REG;

typedef struct 
{
unsigned int     reserved_0:18;
unsigned int     reserved_1:1;
unsigned int     reserved_2:1;
unsigned int     reserved_3:1;
unsigned int     reserved_4:1;
unsigned int     reserved_5:1;
unsigned int     reserved_6:1;
unsigned int     reserved_7:1;
unsigned int     reserved_8:1;
unsigned int     reserved_9:1;
unsigned int     reserved_10:1;
unsigned int     reserved_11:3;
unsigned int     dq_sel:1;
}DC_PHY_CAL_MODE;

typedef struct 
{
unsigned int     ana_dly_sel:1;
unsigned int     reserved_0:3;
unsigned int     dll_en_test:1;
unsigned int     reserved_1:2;
unsigned int     reserved_2:1;
unsigned int     reserved_3:1;
unsigned int     reserved_4:3;
unsigned int     reserved_5:4;
unsigned int     reserved_6:2;
unsigned int     reserved_7:6;
unsigned int     reserved_8:1;
unsigned int     reserved_9:2;
unsigned int     reserved_10:5;
}DC_PHY_ANA_DLL;

typedef struct 
{
unsigned int     reserved_0:26;
unsigned int     write_en_2:1;
unsigned int     lpddr_ck_en:1;
unsigned int     write_en_1:1;
unsigned int     mod_reg_read:1;
unsigned int     write_en_0:1;
unsigned int     mod_reg_write:1;
}DC_PHY_LPDDR_CTRL;

typedef struct 
{
unsigned int     mode_reg_rdata:8;
unsigned int     reserved_0:24;
}DC_PHY_LPDDR_RDAT;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     mode_reg_wdata:8;
unsigned int     mode_reg_addr:8;
unsigned int     reserved_1:1;
unsigned int     lpddr:1;
unsigned int     reserved_2:6;
}DC_PHY_LPDDR_MODE;

typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     mem_num_sel:1;
unsigned int     fifo_arb_sel:1;
unsigned int     reserved_1:1;
unsigned int     cmdq_ch_fifo_cnt:3;
unsigned int     reserved_2:2;
unsigned int     cmdq_ch_fifo_rd_ptr:2;
unsigned int     reserved_3:2;
unsigned int     cmdq_ch_fifo_wr_ptr:2;
unsigned int     cmdq_ch_fifo_overflow:1;
unsigned int     cmdq_ch_fifo_underflow:1;
unsigned int     cmdq_ch_fifo_full:1;
unsigned int     cmdq_ch_fifo_empty:1;
unsigned int     cmdq_ch_fifo_thr:4;
unsigned int     cmdq_ch_fifo_overflow_clr:1;
unsigned int     cmdq_ch_fifo_underflow_clr:1;
unsigned int     cmdq_ch_clk_gated_en:1;
unsigned int     fifo_arb_dis:1;
}DC_PHY_FIFO_ARB_0;

typedef struct 
{
unsigned int     reserved_0:26;
unsigned int     cmdq_ch_gnt_mst1_cmd_dis:1;
unsigned int     cmdq_ch_gnt_mst1_cti_dis:1;
unsigned int     reserved_1:2;
unsigned int     cmdq_ch_gnt_mst0_cmd_dis:1;
unsigned int     cmdq_ch_gnt_mst0_cti_dis:1;
}DC_PHY_FIFO_ARB_1;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     cmdq_ch_dbg_mod:8;
}DC_PHY_FIFO_ARB_2;

typedef struct 
{
unsigned int     cmdq_ch_dummy_0:32;
}DC_PHY_FIFO_ARB_3;

typedef struct 
{
unsigned int     cmdq_ch_gnt_st0:32;
}DC_PHY_FIFO_ARB_4;

typedef struct 
{
unsigned int     cmdq_ch_gnt_st1:32;
}DC_PHY_FIFO_ARB_5;

typedef struct 
{
unsigned int     cmdq_ch_gnt_st2:32;
}DC_PHY_FIFO_ARB_6;

typedef struct 
{
unsigned int     cmdq_ch_gnt_st3:32;
}DC_PHY_FIFO_ARB_7;

typedef struct 
{
unsigned int     cmdq_ch_gnt_st4:32;
}DC_PHY_FIFO_ARB_8;

typedef struct 
{
unsigned int     cmdq_ch_gnt_st5:32;
}DC_PHY_FIFO_ARB_9;

typedef struct 
{
unsigned int     cmdq_ch_gnt_st6:32;
}DC_PHY_FIFO_ARB_10;

typedef struct 
{
unsigned int     cmdq_ch_gnt_st7:32;
}DC_PHY_FIFO_ARB_11;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     wq_ch_dbg_mod:8;
unsigned int     reserved_1:2;
unsigned int     reserved_2:6;
}DC_PHY_FIFO_ARB_13;

typedef struct 
{
unsigned int     wq_ch_dummy_0:32;
}DC_PHY_FIFO_ARB_16;

typedef struct 
{
unsigned int     wq_ch_st0:32;
}DC_PHY_FIFO_ARB_17;

typedef struct 
{
unsigned int     wq_ch_st1:32;
}DC_PHY_FIFO_ARB_18;

typedef struct 
{
unsigned int     wq_ch_st2:32;
}DC_PHY_FIFO_ARB_19;

typedef struct 
{
unsigned int     wq_ch_st3:32;
}DC_PHY_FIFO_ARB_20;

typedef struct 
{
unsigned int     reserved_0:1;
unsigned int     rq_ch_fifo_rd_ptr:7;
unsigned int     reserved_1:1;
unsigned int     rq_ch_fifo_wr_ptr:7;
unsigned int     rq_ch_fifo_overflow:1;
unsigned int     rq_ch_fifo_underflow:1;
unsigned int     rq_ch_fifo_full:1;
unsigned int     rq_ch_fifo_empty:1;
unsigned int     rq_ch_fifo_thr:8;
unsigned int     rq_ch_fifo_overflow_clr:1;
unsigned int     rq_ch_fifo_underflow_clr:1;
unsigned int     rq_ch_clk_gated_en:1;
unsigned int     reserved_2:1;
}DC_PHY_FIFO_ARB_21;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     rq_ch_fifo_cnt:8;
}DC_PHY_FIFO_ARB_22;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     rq_ch_dbg_mod:8;
}DC_PHY_FIFO_ARB_23;

typedef struct 
{
unsigned int     rq_ch_dummy_0:32;
}DC_PHY_FIFO_ARB_24;

typedef struct 
{
unsigned int     rq_ch_st0:32;
}DC_PHY_FIFO_ARB_25;

typedef struct 
{
unsigned int     rq_ch_st1:32;
}DC_PHY_FIFO_ARB_26;

typedef struct 
{
unsigned int     rq_ch_st2:32;
}DC_PHY_FIFO_ARB_27;

typedef struct 
{
unsigned int     rq_ch_st3:32;
}DC_PHY_FIFO_ARB_28;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     seq_mode_sc_sel:1;
unsigned int     scramble_en:1;
}DC_PHY_SCRAMBLE_CTRL;

typedef struct 
{
unsigned int     sc_key_1:16;
unsigned int     sc_key_0:16;
}DC_PHY_SCRAMBLE_KEY_01;

typedef struct 
{
unsigned int     sc_key_3:16;
unsigned int     sc_key_2:16;
}DC_PHY_SCRAMBLE_KEY_23;

typedef struct 
{
unsigned int     sc_key_5:16;
unsigned int     sc_key_4:16;
}DC_PHY_SCRAMBLE_KEY_45;

typedef struct 
{
unsigned int     sc_key_7:16;
unsigned int     sc_key_6:16;
}DC_PHY_SCRAMBLE_KEY_67;

typedef struct 
{
unsigned int     sc_key_9:16;
unsigned int     sc_key_8:16;
}DC_PHY_SCRAMBLE_KEY_89;

typedef struct 
{
unsigned int     sc_key_11:16;
unsigned int     sc_key_10:16;
}DC_PHY_SCRAMBLE_KEY_1011;

typedef struct 
{
unsigned int     sc_key_13:16;
unsigned int     sc_key_12:16;
}DC_PHY_SCRAMBLE_KEY_1213;

typedef struct 
{
unsigned int     sc_key_15:16;
unsigned int     sc_key_14:16;
}DC_PHY_SCRAMBLE_KEY_1415;

typedef struct 
{
unsigned int     sc_key_17:16;
unsigned int     sc_key_16:16;
}DC_PHY_SCRAMBLE_KEY_1617;

typedef struct 
{
unsigned int     sc_key_19:16;
unsigned int     sc_key_18:16;
}DC_PHY_SCRAMBLE_KEY_1819;

typedef struct 
{
unsigned int     sc_key_21:16;
unsigned int     sc_key_20:16;
}DC_PHY_SCRAMBLE_KEY_2021;

typedef struct 
{
unsigned int     sc_key_23:16;
unsigned int     sc_key_22:16;
}DC_PHY_SCRAMBLE_KEY_2223;

typedef struct 
{
unsigned int     sc_key_25:16;
unsigned int     sc_key_24:16;
}DC_PHY_SCRAMBLE_KEY_2425;

typedef struct 
{
unsigned int     sc_key_27:16;
unsigned int     sc_key_26:16;
}DC_PHY_SCRAMBLE_KEY_2627;

typedef struct 
{
unsigned int     sc_key_29:16;
unsigned int     sc_key_28:16;
}DC_PHY_SCRAMBLE_KEY_2829;

typedef struct 
{
unsigned int     sc_key_31:16;
unsigned int     sc_key_30:16;
}DC_PHY_SCRAMBLE_KEY_3031;

typedef struct 
{
unsigned int     dummy_0:32;
}DC_PHY_DUMMY_0;

typedef struct 
{
unsigned int     dummy_1:32;
}DC_PHY_DUMMY_1;

typedef struct 
{
unsigned int     dummy_2:32;
}DC_PHY_DUMMY_2;

typedef struct 
{
unsigned int     dummy_3:32;
}DC_PHY_DUMMY_3;

typedef struct 
{
unsigned int     dummy_4:32;
}DC_PHY_DUMMY_4;

typedef struct 
{
unsigned int     dummy_5:32;
}DC_PHY_DUMMY_5;

typedef struct 
{
unsigned int     dummy_6:28;
unsigned int     cs_mask:1;
unsigned int     cs1_mask:1;
unsigned int     cs_swap:1;
unsigned int     cmd_mux_sel_bga:1;
}DC_PHY_DUMMY_6;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     cmd_mux_sel:1;
unsigned int     cmd_addr_2t_en:1;
unsigned int     issue_cmd_dly_1T:1;
}DC_PHY_CMD_DLY_1T;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     write_merge_en:1;
unsigned int     read_bypass_en:1;
}DC_PHY_EXP_LANE_CTRL;

typedef struct 
{
unsigned int     tota_mon_num:32;
}DC_PHY_SCPU_PC_TOTA_MON_NUM;

typedef struct 
{
unsigned int     tota_ack_num:32;
}DC_PHY_SCPU_PC_TOTA_ACK_NUM;

typedef struct 
{
unsigned int     tota_idl_num:32;
}DC_PHY_SCPU_PC_TOTA_IDL_NUM;

typedef struct 
{
unsigned int     acc_lat:32;
}DC_PHY_SCPU_PC_ACC_LAT;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     max_lat:16;
}DC_PHY_SCPU_PC_MAX_LAT;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     req_num:24;
}DC_PHY_SCPU_PC_REQ_NUM;

typedef struct 
{
unsigned int     ack_num:32;
}DC_PHY_SCPU_PC_ACK_NUM;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     pc_go:1;
}DC_PHY_SCPU_PC_CTRL;

typedef struct 
{
unsigned int     reserved_0:18;
unsigned int     gck_ext_cyc:6;
unsigned int     reserved_1:5;
unsigned int     par_gck_en:1;
unsigned int     fsm_gck_en:1;
unsigned int     ioblk_gck_en:1;
}DC_PHY_GCK_CTRL;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     enable:1;
}DC_PHY_SCPU_LEAKY_BUCKET_CTRL_0;

typedef struct 
{
unsigned int     timer_threshold:32;
}DC_PHY_SCPU_LEAKY_BUCKET_CTRL_1;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     count_threshold:24;
}DC_PHY_SCPU_LEAKY_BUCKET_CTRL_2;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     merge_num:24;
}DC_PHY_SCPU_PC_MERGE_NUM;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     wr_req_num:24;
}DC_PHY_SCPU_PC_WR_REQ_NUM;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     data_in:20;
unsigned int     reserved_1:1;
unsigned int     speed_en:1;
unsigned int     data_in_ready:1;
unsigned int     wire_sel:1;
unsigned int     ro_sel:3;
unsigned int     dss_rst_n:1;
}DC_PHY_SPEED_SENSOR_CTRL;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     count_out:20;
unsigned int     reserved_1:2;
unsigned int     wsort_go:1;
unsigned int     ready:1;
}DC_PHY_SPEED_SENSOR_STATUS;

typedef struct 
{
unsigned int     ctrl_misc:32;
}DC_PHY_EXPRESS_LANE_CTRL_MISC;

typedef struct 
{
unsigned int     dc_dbg_out1:16;
unsigned int     dc_dbg_out0:16;
}DC_PHY_DEBUG01;

typedef struct 
{
unsigned int     dc_dbg_out3:16;
unsigned int     dc_dbg_out2:16;
}DC_PHY_DEBUG23;

typedef struct 
{
unsigned int     reserved_0:23;
unsigned int     DC_PHY_BIST_CLKSEL:1;
unsigned int     DC_PHY_BIST_MODE_3:1;
unsigned int     DC_PHY_BIST_MODE_2:1;
unsigned int     DC_PHY_PTG_BIST_MODE_3:1;
unsigned int     DC_PHY_PTG_BIST_MODE_2:1;
unsigned int     DC_PHY_PTG_BIST_MODE_1:1;
unsigned int     DC_PHY_PTG_BIST_MODE_0:1;
unsigned int     DC_PHY_BIST_MODE_0:1;
unsigned int     DC_PHY_BIST_MODE_1:1;
}DC_PHY_DC_PHY_BIST_MODE;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     DC_PHY_BIST_DONE_3:1;
unsigned int     DC_PHY_BIST_DONE_2:1;
unsigned int     DC_PHY_PTG_BIST_DONE_3:1;
unsigned int     DC_PHY_PTG_BIST_DONE_2:1;
unsigned int     DC_PHY_PTG_BIST_DONE_1:1;
unsigned int     DC_PHY_PTG_BIST_DONE_0:1;
unsigned int     DC_PHY_BIST_DONE_0:1;
unsigned int     DC_PHY_BIST_DONE_1:1;
}DC_PHY_DC_PHY_BIST_DONE;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     DC_PHY_BIST_FAIL_GROUP_3:1;
unsigned int     DC_PHY_BIST_FAIL_GROUP_2:1;
unsigned int     DC_PHY_PTG_BIST_FAIL_GROUP_3:1;
unsigned int     DC_PHY_PTG_BIST_FAIL_GROUP_2:1;
unsigned int     DC_PHY_PTG_BIST_FAIL_GROUP_1:1;
unsigned int     DC_PHY_PTG_BIST_FAIL_GROUP_0:1;
unsigned int     DC_PHY_BIST_FAIL_GROUP_0:1;
unsigned int     DC_PHY_BIST_FAIL_GROUP_1:1;
}DC_PHY_DC_PHY_BIST_FAIL;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     DC_PHY_DRF_MODE_3:1;
unsigned int     DC_PHY_DRF_MODE_2:1;
unsigned int     DC_PHY_PTG_DRF_MODE_3:1;
unsigned int     DC_PHY_PTG_DRF_MODE_2:1;
unsigned int     DC_PHY_PTG_DRF_MODE_1:1;
unsigned int     DC_PHY_PTG_DRF_MODE_0:1;
unsigned int     DC_PHY_DRF_MODE_0:1;
unsigned int     DC_PHY_DRF_MODE_1:1;
}DC_PHY_DC_PHY_BIST_DRF;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     DC_PHY_DRF_RESUME_3:1;
unsigned int     DC_PHY_DRF_RESUME_2:1;
unsigned int     DC_PHY_PTG_DRF_RESUME_3:1;
unsigned int     DC_PHY_PTG_DRF_RESUME_2:1;
unsigned int     DC_PHY_PTG_DRF_RESUME_1:1;
unsigned int     DC_PHY_PTG_DRF_RESUME_0:1;
unsigned int     DC_PHY_DRF_RESUME_0:1;
unsigned int     DC_PHY_DRF_RESUME_1:1;
}DC_PHY_DC_PHY_BIST_RESUME;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     DC_PHY_DRF_DONE_3:1;
unsigned int     DC_PHY_DRF_DONE_2:1;
unsigned int     DC_PHY_PTG_DRF_DONE_3:1;
unsigned int     DC_PHY_PTG_DRF_DONE_2:1;
unsigned int     DC_PHY_PTG_DRF_DONE_1:1;
unsigned int     DC_PHY_PTG_DRF_DONE_0:1;
unsigned int     DC_PHY_DRF_DONE_0:1;
unsigned int     DC_PHY_DRF_DONE_1:1;
}DC_PHY_DC_PHY_BIST0_DRF_DONE;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     DC_PHY_DRF_PAUSE_3:1;
unsigned int     DC_PHY_DRF_PAUSE_2:1;
unsigned int     DC_PHY_PTG_DRF_PAUSE_3:1;
unsigned int     DC_PHY_PTG_DRF_PAUSE_2:1;
unsigned int     DC_PHY_PTG_DRF_PAUSE_1:1;
unsigned int     DC_PHY_PTG_DRF_PAUSE_0:1;
unsigned int     DC_PHY_DRF_PAUSE_0:1;
unsigned int     DC_PHY_DRF_PAUSE_1:1;
}DC_PHY_DC_PHY_BIST_DRF_PAUSE;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     DC_PHY_DRF_FAIL_GROUP_3:1;
unsigned int     DC_PHY_DRF_FAIL_GROUP_2:1;
unsigned int     DC_PHY_PTG_DRF_FAIL_GROUP_3:1;
unsigned int     DC_PHY_PTG_DRF_FAIL_GROUP_2:1;
unsigned int     DC_PHY_PTG_DRF_FAIL_GROUP_1:1;
unsigned int     DC_PHY_PTG_DRF_FAIL_GROUP_0:1;
unsigned int     DC_PHY_DRF_FAIL_GROUP_0:1;
unsigned int     DC_PHY_DRF_FAIL_GROUP_1:1;
}DC_PHY_DC_PHY_BIST_DRF_FAIL;

typedef struct 
{
unsigned int     dummy:32;
}DC_PHY_DC_PHY_BIST_DETAIL;

typedef struct 
{
unsigned int     reserved_0:22;
unsigned int     dc_phy_ls:1;
unsigned int     dc_phy_ptg_ls:1;
unsigned int     reserved_1:3;
unsigned int     RME:1;
unsigned int     RM_3:1;
unsigned int     RM_2:1;
unsigned int     RM_1:1;
unsigned int     RM_0:1;
}DC_PHY_DC_PHY_BIST_RM;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     dc_phy_ptg_ready:1;
}DC_PHY_PTG_READY;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     dc_phy_ptg_rst_n:1;
unsigned int     dc_phy_ptg_clk_en:1;
unsigned int     dc_phy_ptg_sel:1;
}DC_PHY_PTG_SELECT;

typedef struct 
{
unsigned int     reserved_0:26;
unsigned int     dc_sys2_rd_block_en:1;
unsigned int     dc_sys2_wr_block_en:1;
unsigned int     dc_sys1_rd_block_en:1;
unsigned int     dc_sys1_wr_block_en:1;
unsigned int     exp_rd_block_en:1;
unsigned int     exp_wr_block_en:1;
}DC_PHY_BLOCK_REQ;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     dc_sys1_read_bypass_rw_separate_en:1;
unsigned int     dc_sys1_read_bypass_en:1;
unsigned int     dc_sys1_path_sel:1;
}DC_PHY_DC_SYS1_CTRL;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     dc_sys2_wr_qfifo_en:1;
unsigned int     dc_sys2_client_sep_enable:1;
unsigned int     dc_sys2_rw_sep_en:1;
}DC_PHY_DC_SYS2_CTRL;

typedef struct 
{
unsigned int     occ_status_clear:1;
unsigned int     reserved_0:11;
unsigned int     ki_neg:4;
unsigned int     reserved_1:4;
unsigned int     ki_pos:4;
unsigned int     reserved_2:3;
unsigned int     ot_en:1;
unsigned int     reserved_3:1;
unsigned int     stp_ref_cal_en:1;
unsigned int     reserved_4:1;
unsigned int     bw_en:1;
}DC_PHY_QOS_CTRL;

typedef struct 
{
unsigned int     reserved_0:20;
unsigned int     max_oti:4;
unsigned int     max_otf:8;
}DC_PHY_QOS_OT;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     idle_period:16;
unsigned int     add_data:8;
}DC_PHY_QOS_BW0;

typedef struct 
{
unsigned int     max_data:16;
unsigned int     min_data:16;
}DC_PHY_QOS_BW1;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     max_pri:8;
unsigned int     def_pri:8;
unsigned int     min_pri:8;
}DC_PHY_QOS_BW2;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     cur_data_max_occ:1;
unsigned int     cur_data_min_occ:1;
unsigned int     pri_max_occ:1;
unsigned int     pri_min_occ:1;
unsigned int     cur_pri:8;
unsigned int     cur_data:16;
}DC_PHY_QOS_BW3;

typedef struct 
{
unsigned int     reserved_0:20;
unsigned int     c3_wr_block_occ:1;
unsigned int     c2_wr_block_occ:1;
unsigned int     c1_wr_block_occ:1;
unsigned int     c0_wr_block_occ:1;
unsigned int     c7_rd_block_occ:1;
unsigned int     c6_rd_block_occ:1;
unsigned int     c5_rd_block_occ:1;
unsigned int     c4_rd_block_occ:1;
unsigned int     c3_rd_block_occ:1;
unsigned int     c2_rd_block_occ:1;
unsigned int     c1_rd_block_occ:1;
unsigned int     c0_rd_block_occ:1;
}DC_PHY_DC_SYS2_OT_BLOCK;

typedef struct 
{
unsigned int     reserved_0:10;
unsigned int     meas_period:14;
unsigned int     reserved_1:7;
unsigned int     eff_meas_en:1;
}DC_PHY_EFF_MEAS_CTRL;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     rd_cnt:29;
}DC_PHY_READ_CMD;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     wr_cnt:29;
}DC_PHY_WRITE_CMD;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     rd_chop_cnt:29;
}DC_PHY_READ_CHOP_CMD;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     wr_chop_cnt:29;
}DC_PHY_WRITE_CHOP_CMD;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     active_cnt_bank0:29;
}DC_PHY_ACT_BANK_0;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     precharge_cnt_bank0:29;
}DC_PHY_PRECHG_BANK_0;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     active_cnt_bank1:29;
}DC_PHY_ACT_BANK_1;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     precharge_cnt_bank1:29;
}DC_PHY_PRECHG_BANK_1;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     active_cnt_bank2:29;
}DC_PHY_ACT_BANK_2;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     precharge_cnt_bank2:29;
}DC_PHY_PRECHG_BANK_2;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     active_cnt_bank3:29;
}DC_PHY_ACT_BANK_3;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     precharge_cnt_bank3:29;
}DC_PHY_PRECHG_BANK_3;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     active_cnt_bank4:29;
}DC_PHY_ACT_BANK_4;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     precharge_cnt_bank4:29;
}DC_PHY_PRECHG_BANK_4;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     active_cnt_bank5:29;
}DC_PHY_ACT_BANK_5;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     precharge_cnt_bank5:29;
}DC_PHY_PRECHG_BANK_5;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     active_cnt_bank6:29;
}DC_PHY_ACT_BANK_6;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     precharge_cnt_bank6:29;
}DC_PHY_PRECHG_BANK_6;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     active_cnt_bank7:29;
}DC_PHY_ACT_BANK_7;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     precharge_cnt_bank7:29;
}DC_PHY_PRECHG_BANK_7;

typedef struct 
{
unsigned int     reserved_0:5;
unsigned int     w2r_cnt:27;
}DC_PHY_WRITE_TO_READ;

typedef struct 
{
unsigned int     reserved_0:5;
unsigned int     r2w_cnt:27;
}DC_PHY_READ_TO_WRITE;

typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     req_to_cmd_w:26;
}DC_PHY_WRITE_CMD_LATENCY;

typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     req_to_cmd_r:26;
}DC_PHY_READ_CMD_LATENCY;

typedef struct 
{
unsigned int     reserved_0:12;
unsigned int     bank_conflict_cnt:20;
}DC_PHY_BANK_CONFLICT;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     wr_merge_cnt_exp:28;
}DC_PHY_WRITE_MERGE;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     rd_bypass_cnt_exp:28;
}DC_PHY_READ_BYPASS;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     rd_bypass_cnt_dc_sys1:28;
}DC_PHY_DC_SYS1_READ_BYPASS;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     rd_ap_cnt:29;
}DC_PHY_READ_CMD_AP;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     wr_ap_cnt:29;
}DC_PHY_WRITE_CMD_AP;

typedef struct 
{
unsigned int     reserved_0:27;
unsigned int     outstand_reorder_en:1;
unsigned int     priority_weight_en:1;
unsigned int     direction_weight_en:1;
unsigned int     length_weight_en:1;
unsigned int     Bank_weight_en:1;
}DC_PHY_WEIGHT_ENABLE;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     pw_multiplier:3;
}DC_PHY_WEIGHT_PRIORITY;

typedef struct 
{
unsigned int     reserved_0:12;
unsigned int     dw_init_dynamic_en:1;
unsigned int     dw_init_r:8;
unsigned int     dw_init_w:8;
unsigned int     dw_multiplier:3;
}DC_PHY_WEIGHT_DIERECTION;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     lw_long_burst_prior:1;
unsigned int     lw_multiplier:3;
}DC_PHY_WEIGHT_LENGTH;

typedef struct 
{
unsigned int     reserved_0:9;
unsigned int     bw_pend_cycle:7;
unsigned int     bw_pend_en:1;
unsigned int     bw_trc:7;
unsigned int     bw_trp:5;
unsigned int     bw_multiplier:3;
}DC_PHY_WEIGHT_BANK;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     dc_sys2_group_en:1;
unsigned int     dc_sys1_group_en:1;
unsigned int     express_lane_group_en:1;
unsigned int     express_lane_wr_separate_en:1;
}DC_PHY_MULTI_CLIENT;

#endif

#define DC_PHY_TMCTRL0                                                               0x18008800
#define DC_PHY_TMCTRL0_reg_addr                                                      "0xB8008800"
#define DC_PHY_TMCTRL0_reg                                                           0xB8008800
#define set_DC_PHY_TMCTRL0_reg(data)   (*((volatile unsigned int*) DC_PHY_TMCTRL0_reg)=data)
#define get_DC_PHY_TMCTRL0_reg   (*((volatile unsigned int*) DC_PHY_TMCTRL0_reg))
#define DC_PHY_TMCTRL0_inst_adr                                                      "0x0000"
#define DC_PHY_TMCTRL0_inst                                                          0x0000
#define DC_PHY_TMCTRL0_tmras_shift                                                   (16)
#define DC_PHY_TMCTRL0_tmras_mask                                                    (0x01FF0000)
#define DC_PHY_TMCTRL0_tmras(data)                                                   (0x01FF0000&((data)<<16))
#define DC_PHY_TMCTRL0_tmras_src(data)                                               ((0x01FF0000&(data))>>16)
#define DC_PHY_TMCTRL0_get_tmras(data)                                               ((0x01FF0000&(data))>>16)
#define DC_PHY_TMCTRL0_tmrcl_shift                                                   (12)
#define DC_PHY_TMCTRL0_tmrcl_mask                                                    (0x0000F000)
#define DC_PHY_TMCTRL0_tmrcl(data)                                                   (0x0000F000&((data)<<12))
#define DC_PHY_TMCTRL0_tmrcl_src(data)                                               ((0x0000F000&(data))>>12)
#define DC_PHY_TMCTRL0_get_tmrcl(data)                                               ((0x0000F000&(data))>>12)
#define DC_PHY_TMCTRL0_tmcl_shift                                                    (8)
#define DC_PHY_TMCTRL0_tmcl_mask                                                     (0x00000F00)
#define DC_PHY_TMCTRL0_tmcl(data)                                                    (0x00000F00&((data)<<8))
#define DC_PHY_TMCTRL0_tmcl_src(data)                                                ((0x00000F00&(data))>>8)
#define DC_PHY_TMCTRL0_get_tmcl(data)                                                ((0x00000F00&(data))>>8)


#define DC_PHY_TMCTRL1                                                               0x18008804
#define DC_PHY_TMCTRL1_reg_addr                                                      "0xB8008804"
#define DC_PHY_TMCTRL1_reg                                                           0xB8008804
#define set_DC_PHY_TMCTRL1_reg(data)   (*((volatile unsigned int*) DC_PHY_TMCTRL1_reg)=data)
#define get_DC_PHY_TMCTRL1_reg   (*((volatile unsigned int*) DC_PHY_TMCTRL1_reg))
#define DC_PHY_TMCTRL1_inst_adr                                                      "0x0001"
#define DC_PHY_TMCTRL1_inst                                                          0x0001
#define DC_PHY_TMCTRL1_tmrrd_shift                                                   (24)
#define DC_PHY_TMCTRL1_tmrrd_mask                                                    (0x1F000000)
#define DC_PHY_TMCTRL1_tmrrd(data)                                                   (0x1F000000&((data)<<24))
#define DC_PHY_TMCTRL1_tmrrd_src(data)                                               ((0x1F000000&(data))>>24)
#define DC_PHY_TMCTRL1_get_tmrrd(data)                                               ((0x1F000000&(data))>>24)
#define DC_PHY_TMCTRL1_tmrp_shift                                                    (16)
#define DC_PHY_TMCTRL1_tmrp_mask                                                     (0x003F0000)
#define DC_PHY_TMCTRL1_tmrp(data)                                                    (0x003F0000&((data)<<16))
#define DC_PHY_TMCTRL1_tmrp_src(data)                                                ((0x003F0000&(data))>>16)
#define DC_PHY_TMCTRL1_get_tmrp(data)                                                ((0x003F0000&(data))>>16)
#define DC_PHY_TMCTRL1_tmrcd_shift                                                   (8)
#define DC_PHY_TMCTRL1_tmrcd_mask                                                    (0x00003F00)
#define DC_PHY_TMCTRL1_tmrcd(data)                                                   (0x00003F00&((data)<<8))
#define DC_PHY_TMCTRL1_tmrcd_src(data)                                               ((0x00003F00&(data))>>8)
#define DC_PHY_TMCTRL1_get_tmrcd(data)                                               ((0x00003F00&(data))>>8)
#define DC_PHY_TMCTRL1_tmrc_shift                                                    (0)
#define DC_PHY_TMCTRL1_tmrc_mask                                                     (0x000000FF)
#define DC_PHY_TMCTRL1_tmrc(data)                                                    (0x000000FF&((data)<<0))
#define DC_PHY_TMCTRL1_tmrc_src(data)                                                ((0x000000FF&(data))>>0)
#define DC_PHY_TMCTRL1_get_tmrc(data)                                                ((0x000000FF&(data))>>0)


#define DC_PHY_TMCTRL2                                                               0x18008808
#define DC_PHY_TMCTRL2_reg_addr                                                      "0xB8008808"
#define DC_PHY_TMCTRL2_reg                                                           0xB8008808
#define set_DC_PHY_TMCTRL2_reg(data)   (*((volatile unsigned int*) DC_PHY_TMCTRL2_reg)=data)
#define get_DC_PHY_TMCTRL2_reg   (*((volatile unsigned int*) DC_PHY_TMCTRL2_reg))
#define DC_PHY_TMCTRL2_inst_adr                                                      "0x0002"
#define DC_PHY_TMCTRL2_inst                                                          0x0002
#define DC_PHY_TMCTRL2_tmccd_r2r_shift                                               (28)
#define DC_PHY_TMCTRL2_tmccd_r2r_mask                                                (0xF0000000)
#define DC_PHY_TMCTRL2_tmccd_r2r(data)                                               (0xF0000000&((data)<<28))
#define DC_PHY_TMCTRL2_tmccd_r2r_src(data)                                           ((0xF0000000&(data))>>28)
#define DC_PHY_TMCTRL2_get_tmccd_r2r(data)                                           ((0xF0000000&(data))>>28)
#define DC_PHY_TMCTRL2_tmccd_shift                                                   (24)
#define DC_PHY_TMCTRL2_tmccd_mask                                                    (0x0F000000)
#define DC_PHY_TMCTRL2_tmccd(data)                                                   (0x0F000000&((data)<<24))
#define DC_PHY_TMCTRL2_tmccd_src(data)                                               ((0x0F000000&(data))>>24)
#define DC_PHY_TMCTRL2_get_tmccd(data)                                               ((0x0F000000&(data))>>24)
#define DC_PHY_TMCTRL2_trtp_shift                                                    (16)
#define DC_PHY_TMCTRL2_trtp_mask                                                     (0x007F0000)
#define DC_PHY_TMCTRL2_trtp(data)                                                    (0x007F0000&((data)<<16))
#define DC_PHY_TMCTRL2_trtp_src(data)                                                ((0x007F0000&(data))>>16)
#define DC_PHY_TMCTRL2_get_trtp(data)                                                ((0x007F0000&(data))>>16)
#define DC_PHY_TMCTRL2_tmwtr_shift                                                   (8)
#define DC_PHY_TMCTRL2_tmwtr_mask                                                    (0x00001F00)
#define DC_PHY_TMCTRL2_tmwtr(data)                                                   (0x00001F00&((data)<<8))
#define DC_PHY_TMCTRL2_tmwtr_src(data)                                               ((0x00001F00&(data))>>8)
#define DC_PHY_TMCTRL2_get_tmwtr(data)                                               ((0x00001F00&(data))>>8)
#define DC_PHY_TMCTRL2_tmwr_shift                                                    (0)
#define DC_PHY_TMCTRL2_tmwr_mask                                                     (0x0000003F)
#define DC_PHY_TMCTRL2_tmwr(data)                                                    (0x0000003F&((data)<<0))
#define DC_PHY_TMCTRL2_tmwr_src(data)                                                ((0x0000003F&(data))>>0)
#define DC_PHY_TMCTRL2_get_tmwr(data)                                                ((0x0000003F&(data))>>0)


#define DC_PHY_TMCTRL3                                                               0x1800880c
#define DC_PHY_TMCTRL3_reg_addr                                                      "0xB800880C"
#define DC_PHY_TMCTRL3_reg                                                           0xB800880C
#define set_DC_PHY_TMCTRL3_reg(data)   (*((volatile unsigned int*) DC_PHY_TMCTRL3_reg)=data)
#define get_DC_PHY_TMCTRL3_reg   (*((volatile unsigned int*) DC_PHY_TMCTRL3_reg))
#define DC_PHY_TMCTRL3_inst_adr                                                      "0x0003"
#define DC_PHY_TMCTRL3_inst                                                          0x0003
#define DC_PHY_TMCTRL3_tmFAW_shift                                                   (24)
#define DC_PHY_TMCTRL3_tmFAW_mask                                                    (0xFF000000)
#define DC_PHY_TMCTRL3_tmFAW(data)                                                   (0xFF000000&((data)<<24))
#define DC_PHY_TMCTRL3_tmFAW_src(data)                                               ((0xFF000000&(data))>>24)
#define DC_PHY_TMCTRL3_get_tmFAW(data)                                               ((0xFF000000&(data))>>24)
#define DC_PHY_TMCTRL3_refcycle_shift                                                (12)
#define DC_PHY_TMCTRL3_refcycle_mask                                                 (0x00FFF000)
#define DC_PHY_TMCTRL3_refcycle(data)                                                (0x00FFF000&((data)<<12))
#define DC_PHY_TMCTRL3_refcycle_src(data)                                            ((0x00FFF000&(data))>>12)
#define DC_PHY_TMCTRL3_get_refcycle(data)                                            ((0x00FFF000&(data))>>12)
#define DC_PHY_TMCTRL3_tmrfc_shift                                                   (0)
#define DC_PHY_TMCTRL3_tmrfc_mask                                                    (0x000007FF)
#define DC_PHY_TMCTRL3_tmrfc(data)                                                   (0x000007FF&((data)<<0))
#define DC_PHY_TMCTRL3_tmrfc_src(data)                                               ((0x000007FF&(data))>>0)
#define DC_PHY_TMCTRL3_get_tmrfc(data)                                               ((0x000007FF&(data))>>0)


#define DC_PHY_TMCTRL4                                                               0x18008810
#define DC_PHY_TMCTRL4_reg_addr                                                      "0xB8008810"
#define DC_PHY_TMCTRL4_reg                                                           0xB8008810
#define set_DC_PHY_TMCTRL4_reg(data)   (*((volatile unsigned int*) DC_PHY_TMCTRL4_reg)=data)
#define get_DC_PHY_TMCTRL4_reg   (*((volatile unsigned int*) DC_PHY_TMCTRL4_reg))
#define DC_PHY_TMCTRL4_inst_adr                                                      "0x0004"
#define DC_PHY_TMCTRL4_inst                                                          0x0004
#define DC_PHY_TMCTRL4_tAOND_shift                                                   (24)
#define DC_PHY_TMCTRL4_tAOND_mask                                                    (0x3F000000)
#define DC_PHY_TMCTRL4_tAOND(data)                                                   (0x3F000000&((data)<<24))
#define DC_PHY_TMCTRL4_tAOND_src(data)                                               ((0x3F000000&(data))>>24)
#define DC_PHY_TMCTRL4_get_tAOND(data)                                               ((0x3F000000&(data))>>24)
#define DC_PHY_TMCTRL4_tAOFD_shift                                                   (16)
#define DC_PHY_TMCTRL4_tAOFD_mask                                                    (0x003F0000)
#define DC_PHY_TMCTRL4_tAOFD(data)                                                   (0x003F0000&((data)<<16))
#define DC_PHY_TMCTRL4_tAOFD_src(data)                                               ((0x003F0000&(data))>>16)
#define DC_PHY_TMCTRL4_get_tAOFD(data)                                               ((0x003F0000&(data))>>16)
#define DC_PHY_TMCTRL4_tmmod_shift                                                   (8)
#define DC_PHY_TMCTRL4_tmmod_mask                                                    (0x0000FF00)
#define DC_PHY_TMCTRL4_tmmod(data)                                                   (0x0000FF00&((data)<<8))
#define DC_PHY_TMCTRL4_tmmod_src(data)                                               ((0x0000FF00&(data))>>8)
#define DC_PHY_TMCTRL4_get_tmmod(data)                                               ((0x0000FF00&(data))>>8)
#define DC_PHY_TMCTRL4_tmmrd_shift                                                   (0)
#define DC_PHY_TMCTRL4_tmmrd_mask                                                    (0x0000001F)
#define DC_PHY_TMCTRL4_tmmrd(data)                                                   (0x0000001F&((data)<<0))
#define DC_PHY_TMCTRL4_tmmrd_src(data)                                               ((0x0000001F&(data))>>0)
#define DC_PHY_TMCTRL4_get_tmmrd(data)                                               ((0x0000001F&(data))>>0)


#define DC_PHY_TMCTRL5                                                               0x18008814
#define DC_PHY_TMCTRL5_reg_addr                                                      "0xB8008814"
#define DC_PHY_TMCTRL5_reg                                                           0xB8008814
#define set_DC_PHY_TMCTRL5_reg(data)   (*((volatile unsigned int*) DC_PHY_TMCTRL5_reg)=data)
#define get_DC_PHY_TMCTRL5_reg   (*((volatile unsigned int*) DC_PHY_TMCTRL5_reg))
#define DC_PHY_TMCTRL5_inst_adr                                                      "0x0005"
#define DC_PHY_TMCTRL5_inst                                                          0x0005
#define DC_PHY_TMCTRL5_tmrtw_shift                                                   (24)
#define DC_PHY_TMCTRL5_tmrtw_mask                                                    (0x0F000000)
#define DC_PHY_TMCTRL5_tmrtw(data)                                                   (0x0F000000&((data)<<24))
#define DC_PHY_TMCTRL5_tmrtw_src(data)                                               ((0x0F000000&(data))>>24)
#define DC_PHY_TMCTRL5_get_tmrtw(data)                                               ((0x0F000000&(data))>>24)
#define DC_PHY_TMCTRL5_tzqoper_shift                                                 (12)
#define DC_PHY_TMCTRL5_tzqoper_mask                                                  (0x00FFF000)
#define DC_PHY_TMCTRL5_tzqoper(data)                                                 (0x00FFF000&((data)<<12))
#define DC_PHY_TMCTRL5_tzqoper_src(data)                                             ((0x00FFF000&(data))>>12)
#define DC_PHY_TMCTRL5_get_tzqoper(data)                                             ((0x00FFF000&(data))>>12)
#define DC_PHY_TMCTRL5_tzqinit_shift                                                 (0)
#define DC_PHY_TMCTRL5_tzqinit_mask                                                  (0x00000FFF)
#define DC_PHY_TMCTRL5_tzqinit(data)                                                 (0x00000FFF&((data)<<0))
#define DC_PHY_TMCTRL5_tzqinit_src(data)                                             ((0x00000FFF&(data))>>0)
#define DC_PHY_TMCTRL5_get_tzqinit(data)                                             ((0x00000FFF&(data))>>0)


#define DC_PHY_TMCTRL6                                                               0x18008818
#define DC_PHY_TMCTRL6_reg_addr                                                      "0xB8008818"
#define DC_PHY_TMCTRL6_reg                                                           0xB8008818
#define set_DC_PHY_TMCTRL6_reg(data)   (*((volatile unsigned int*) DC_PHY_TMCTRL6_reg)=data)
#define get_DC_PHY_TMCTRL6_reg   (*((volatile unsigned int*) DC_PHY_TMCTRL6_reg))
#define DC_PHY_TMCTRL6_inst_adr                                                      "0x0006"
#define DC_PHY_TMCTRL6_inst                                                          0x0006
#define DC_PHY_TMCTRL6_dqs_lat_sel_shift                                             (31)
#define DC_PHY_TMCTRL6_dqs_lat_sel_mask                                              (0x80000000)
#define DC_PHY_TMCTRL6_dqs_lat_sel(data)                                             (0x80000000&((data)<<31))
#define DC_PHY_TMCTRL6_dqs_lat_sel_src(data)                                         ((0x80000000&(data))>>31)
#define DC_PHY_TMCTRL6_get_dqs_lat_sel(data)                                         ((0x80000000&(data))>>31)
#define DC_PHY_TMCTRL6_dqs_lat_shift                                                 (24)
#define DC_PHY_TMCTRL6_dqs_lat_mask                                                  (0x7F000000)
#define DC_PHY_TMCTRL6_dqs_lat(data)                                                 (0x7F000000&((data)<<24))
#define DC_PHY_TMCTRL6_dqs_lat_src(data)                                             ((0x7F000000&(data))>>24)
#define DC_PHY_TMCTRL6_get_dqs_lat(data)                                             ((0x7F000000&(data))>>24)
#define DC_PHY_TMCTRL6_tdllk_shift                                                   (12)
#define DC_PHY_TMCTRL6_tdllk_mask                                                    (0x00FFF000)
#define DC_PHY_TMCTRL6_tdllk(data)                                                   (0x00FFF000&((data)<<12))
#define DC_PHY_TMCTRL6_tdllk_src(data)                                               ((0x00FFF000&(data))>>12)
#define DC_PHY_TMCTRL6_get_tdllk(data)                                               ((0x00FFF000&(data))>>12)
#define DC_PHY_TMCTRL6_tzqcs_shift                                                   (0)
#define DC_PHY_TMCTRL6_tzqcs_mask                                                    (0x00000FFF)
#define DC_PHY_TMCTRL6_tzqcs(data)                                                   (0x00000FFF&((data)<<0))
#define DC_PHY_TMCTRL6_tzqcs_src(data)                                               ((0x00000FFF&(data))>>0)
#define DC_PHY_TMCTRL6_get_tzqcs(data)                                               ((0x00000FFF&(data))>>0)


#define DC_PHY_ODT_CTRL                                                              0x18008820
#define DC_PHY_ODT_CTRL_reg_addr                                                     "0xB8008820"
#define DC_PHY_ODT_CTRL_reg                                                          0xB8008820
#define set_DC_PHY_ODT_CTRL_reg(data)   (*((volatile unsigned int*) DC_PHY_ODT_CTRL_reg)=data)
#define get_DC_PHY_ODT_CTRL_reg   (*((volatile unsigned int*) DC_PHY_ODT_CTRL_reg))
#define DC_PHY_ODT_CTRL_inst_adr                                                     "0x0008"
#define DC_PHY_ODT_CTRL_inst                                                         0x0008
#define DC_PHY_ODT_CTRL_ddr3_odt_dly_1T_shift                                        (28)
#define DC_PHY_ODT_CTRL_ddr3_odt_dly_1T_mask                                         (0x10000000)
#define DC_PHY_ODT_CTRL_ddr3_odt_dly_1T(data)                                        (0x10000000&((data)<<28))
#define DC_PHY_ODT_CTRL_ddr3_odt_dly_1T_src(data)                                    ((0x10000000&(data))>>28)
#define DC_PHY_ODT_CTRL_get_ddr3_odt_dly_1T(data)                                    ((0x10000000&(data))>>28)
#define DC_PHY_ODT_CTRL_ddr3_odt_ext_1T_shift                                        (27)
#define DC_PHY_ODT_CTRL_ddr3_odt_ext_1T_mask                                         (0x08000000)
#define DC_PHY_ODT_CTRL_ddr3_odt_ext_1T(data)                                        (0x08000000&((data)<<27))
#define DC_PHY_ODT_CTRL_ddr3_odt_ext_1T_src(data)                                    ((0x08000000&(data))>>27)
#define DC_PHY_ODT_CTRL_get_ddr3_odt_ext_1T(data)                                    ((0x08000000&(data))>>27)
#define DC_PHY_ODT_CTRL_odt_force_sel_shift                                          (23)
#define DC_PHY_ODT_CTRL_odt_force_sel_mask                                           (0x00800000)
#define DC_PHY_ODT_CTRL_odt_force_sel(data)                                          (0x00800000&((data)<<23))
#define DC_PHY_ODT_CTRL_odt_force_sel_src(data)                                      ((0x00800000&(data))>>23)
#define DC_PHY_ODT_CTRL_get_odt_force_sel(data)                                      ((0x00800000&(data))>>23)
#define DC_PHY_ODT_CTRL_odt_force_sig_shift                                          (22)
#define DC_PHY_ODT_CTRL_odt_force_sig_mask                                           (0x00400000)
#define DC_PHY_ODT_CTRL_odt_force_sig(data)                                          (0x00400000&((data)<<22))
#define DC_PHY_ODT_CTRL_odt_force_sig_src(data)                                      ((0x00400000&(data))>>22)
#define DC_PHY_ODT_CTRL_get_odt_force_sig(data)                                      ((0x00400000&(data))>>22)
#define DC_PHY_ODT_CTRL_odt_en_shift                                                 (21)
#define DC_PHY_ODT_CTRL_odt_en_mask                                                  (0x00200000)
#define DC_PHY_ODT_CTRL_odt_en(data)                                                 (0x00200000&((data)<<21))
#define DC_PHY_ODT_CTRL_odt_en_src(data)                                             ((0x00200000&(data))>>21)
#define DC_PHY_ODT_CTRL_get_odt_en(data)                                             ((0x00200000&(data))>>21)
#define DC_PHY_ODT_CTRL_odt_dis_shift                                                (20)
#define DC_PHY_ODT_CTRL_odt_dis_mask                                                 (0x00100000)
#define DC_PHY_ODT_CTRL_odt_dis(data)                                                (0x00100000&((data)<<20))
#define DC_PHY_ODT_CTRL_odt_dis_src(data)                                            ((0x00100000&(data))>>20)
#define DC_PHY_ODT_CTRL_get_odt_dis(data)                                            ((0x00100000&(data))>>20)


#define DC_PHY_CAL_CTRL2                                                             0x18008824
#define DC_PHY_CAL_CTRL2_reg_addr                                                    "0xB8008824"
#define DC_PHY_CAL_CTRL2_reg                                                         0xB8008824
#define set_DC_PHY_CAL_CTRL2_reg(data)   (*((volatile unsigned int*) DC_PHY_CAL_CTRL2_reg)=data)
#define get_DC_PHY_CAL_CTRL2_reg   (*((volatile unsigned int*) DC_PHY_CAL_CTRL2_reg))
#define DC_PHY_CAL_CTRL2_inst_adr                                                    "0x0009"
#define DC_PHY_CAL_CTRL2_inst                                                        0x0009


#define DC_PHY_DC_MIS2                                                               0x18008828
#define DC_PHY_DC_MIS2_reg_addr                                                      "0xB8008828"
#define DC_PHY_DC_MIS2_reg                                                           0xB8008828
#define set_DC_PHY_DC_MIS2_reg(data)   (*((volatile unsigned int*) DC_PHY_DC_MIS2_reg)=data)
#define get_DC_PHY_DC_MIS2_reg   (*((volatile unsigned int*) DC_PHY_DC_MIS2_reg))
#define DC_PHY_DC_MIS2_inst_adr                                                      "0x000A"
#define DC_PHY_DC_MIS2_inst                                                          0x000A
#define DC_PHY_DC_MIS2_init_shift                                                    (4)
#define DC_PHY_DC_MIS2_init_mask                                                     (0x00000010)
#define DC_PHY_DC_MIS2_init(data)                                                    (0x00000010&((data)<<4))
#define DC_PHY_DC_MIS2_init_src(data)                                                ((0x00000010&(data))>>4)
#define DC_PHY_DC_MIS2_get_init(data)                                                ((0x00000010&(data))>>4)
#define DC_PHY_DC_MIS2_sren_shift                                                    (3)
#define DC_PHY_DC_MIS2_sren_mask                                                     (0x00000008)
#define DC_PHY_DC_MIS2_sren(data)                                                    (0x00000008&((data)<<3))
#define DC_PHY_DC_MIS2_sren_src(data)                                                ((0x00000008&(data))>>3)
#define DC_PHY_DC_MIS2_get_sren(data)                                                ((0x00000008&(data))>>3)
#define DC_PHY_DC_MIS2_srex_shift                                                    (2)
#define DC_PHY_DC_MIS2_srex_mask                                                     (0x00000004)
#define DC_PHY_DC_MIS2_srex(data)                                                    (0x00000004&((data)<<2))
#define DC_PHY_DC_MIS2_srex_src(data)                                                ((0x00000004&(data))>>2)
#define DC_PHY_DC_MIS2_get_srex(data)                                                ((0x00000004&(data))>>2)
#define DC_PHY_DC_MIS2_exe_emr_shift                                                 (1)
#define DC_PHY_DC_MIS2_exe_emr_mask                                                  (0x00000002)
#define DC_PHY_DC_MIS2_exe_emr(data)                                                 (0x00000002&((data)<<1))
#define DC_PHY_DC_MIS2_exe_emr_src(data)                                             ((0x00000002&(data))>>1)
#define DC_PHY_DC_MIS2_get_exe_emr(data)                                             ((0x00000002&(data))>>1)
#define DC_PHY_DC_MIS2_exe_mr_shift                                                  (0)
#define DC_PHY_DC_MIS2_exe_mr_mask                                                   (0x00000001)
#define DC_PHY_DC_MIS2_exe_mr(data)                                                  (0x00000001&((data)<<0))
#define DC_PHY_DC_MIS2_exe_mr_src(data)                                              ((0x00000001&(data))>>0)
#define DC_PHY_DC_MIS2_get_exe_mr(data)                                              ((0x00000001&(data))>>0)


#define DC_PHY_DC_MIS                                                                0x1800882c
#define DC_PHY_DC_MIS_reg_addr                                                       "0xB800882C"
#define DC_PHY_DC_MIS_reg                                                            0xB800882C
#define set_DC_PHY_DC_MIS_reg(data)   (*((volatile unsigned int*) DC_PHY_DC_MIS_reg)=data)
#define get_DC_PHY_DC_MIS_reg   (*((volatile unsigned int*) DC_PHY_DC_MIS_reg))
#define DC_PHY_DC_MIS_inst_adr                                                       "0x000B"
#define DC_PHY_DC_MIS_inst                                                           0x000B
#define DC_PHY_DC_MIS_rcd_not_eq_shift                                               (24)
#define DC_PHY_DC_MIS_rcd_not_eq_mask                                                (0x01000000)
#define DC_PHY_DC_MIS_rcd_not_eq(data)                                               (0x01000000&((data)<<24))
#define DC_PHY_DC_MIS_rcd_not_eq_src(data)                                           ((0x01000000&(data))>>24)
#define DC_PHY_DC_MIS_get_rcd_not_eq(data)                                           ((0x01000000&(data))>>24)
#define DC_PHY_DC_MIS_tmrcdwr_shift                                                  (16)
#define DC_PHY_DC_MIS_tmrcdwr_mask                                                   (0x003F0000)
#define DC_PHY_DC_MIS_tmrcdwr(data)                                                  (0x003F0000&((data)<<16))
#define DC_PHY_DC_MIS_tmrcdwr_src(data)                                              ((0x003F0000&(data))>>16)
#define DC_PHY_DC_MIS_get_tmrcdwr(data)                                              ((0x003F0000&(data))>>16)
#define DC_PHY_DC_MIS_tmrp_all_add_shift                                             (14)
#define DC_PHY_DC_MIS_tmrp_all_add_mask                                              (0x0000C000)
#define DC_PHY_DC_MIS_tmrp_all_add(data)                                             (0x0000C000&((data)<<14))
#define DC_PHY_DC_MIS_tmrp_all_add_src(data)                                         ((0x0000C000&(data))>>14)
#define DC_PHY_DC_MIS_get_tmrp_all_add(data)                                         ((0x0000C000&(data))>>14)


#define DC_PHY_DC_MISA                                                               0x18008830
#define DC_PHY_DC_MISA_reg_addr                                                      "0xB8008830"
#define DC_PHY_DC_MISA_reg                                                           0xB8008830
#define set_DC_PHY_DC_MISA_reg(data)   (*((volatile unsigned int*) DC_PHY_DC_MISA_reg)=data)
#define get_DC_PHY_DC_MISA_reg   (*((volatile unsigned int*) DC_PHY_DC_MISA_reg))
#define DC_PHY_DC_MISA_inst_adr                                                      "0x000C"
#define DC_PHY_DC_MISA_inst                                                          0x000C
#define DC_PHY_DC_MISA_ref_after_last_cmd_shift                                      (13)
#define DC_PHY_DC_MISA_ref_after_last_cmd_mask                                       (0x00002000)
#define DC_PHY_DC_MISA_ref_after_last_cmd(data)                                      (0x00002000&((data)<<13))
#define DC_PHY_DC_MISA_ref_after_last_cmd_src(data)                                  ((0x00002000&(data))>>13)
#define DC_PHY_DC_MISA_get_ref_after_last_cmd(data)                                  ((0x00002000&(data))>>13)
#define DC_PHY_DC_MISA_pre_dis_shift                                                 (12)
#define DC_PHY_DC_MISA_pre_dis_mask                                                  (0x00001000)
#define DC_PHY_DC_MISA_pre_dis(data)                                                 (0x00001000&((data)<<12))
#define DC_PHY_DC_MISA_pre_dis_src(data)                                             ((0x00001000&(data))>>12)
#define DC_PHY_DC_MISA_get_pre_dis(data)                                             ((0x00001000&(data))>>12)
#define DC_PHY_DC_MISA_lbk_en_shift                                                  (2)
#define DC_PHY_DC_MISA_lbk_en_mask                                                   (0x00000004)
#define DC_PHY_DC_MISA_lbk_en(data)                                                  (0x00000004&((data)<<2))
#define DC_PHY_DC_MISA_lbk_en_src(data)                                              ((0x00000004&(data))>>2)
#define DC_PHY_DC_MISA_get_lbk_en(data)                                              ((0x00000004&(data))>>2)


#define DC_PHY_DC_MISB                                                               0x18008834
#define DC_PHY_DC_MISB_reg_addr                                                      "0xB8008834"
#define DC_PHY_DC_MISB_reg                                                           0xB8008834
#define set_DC_PHY_DC_MISB_reg(data)   (*((volatile unsigned int*) DC_PHY_DC_MISB_reg)=data)
#define get_DC_PHY_DC_MISB_reg   (*((volatile unsigned int*) DC_PHY_DC_MISB_reg))
#define DC_PHY_DC_MISB_inst_adr                                                      "0x000D"
#define DC_PHY_DC_MISB_inst                                                          0x000D
#define DC_PHY_DC_MISB_tmrc_sel_shift                                                (28)
#define DC_PHY_DC_MISB_tmrc_sel_mask                                                 (0x10000000)
#define DC_PHY_DC_MISB_tmrc_sel(data)                                                (0x10000000&((data)<<28))
#define DC_PHY_DC_MISB_tmrc_sel_src(data)                                            ((0x10000000&(data))>>28)
#define DC_PHY_DC_MISB_get_tmrc_sel(data)                                            ((0x10000000&(data))>>28)


#define DC_PHY_DC_MISC                                                               0x18008838
#define DC_PHY_DC_MISC_reg_addr                                                      "0xB8008838"
#define DC_PHY_DC_MISC_reg                                                           0xB8008838
#define set_DC_PHY_DC_MISC_reg(data)   (*((volatile unsigned int*) DC_PHY_DC_MISC_reg)=data)
#define get_DC_PHY_DC_MISC_reg   (*((volatile unsigned int*) DC_PHY_DC_MISC_reg))
#define DC_PHY_DC_MISC_inst_adr                                                      "0x000E"
#define DC_PHY_DC_MISC_inst                                                          0x000E


#define DC_PHY_DC_TEST_MODE_SEL                                                      0x1800883c
#define DC_PHY_DC_TEST_MODE_SEL_reg_addr                                             "0xB800883C"
#define DC_PHY_DC_TEST_MODE_SEL_reg                                                  0xB800883C
#define set_DC_PHY_DC_TEST_MODE_SEL_reg(data)   (*((volatile unsigned int*) DC_PHY_DC_TEST_MODE_SEL_reg)=data)
#define get_DC_PHY_DC_TEST_MODE_SEL_reg   (*((volatile unsigned int*) DC_PHY_DC_TEST_MODE_SEL_reg))
#define DC_PHY_DC_TEST_MODE_SEL_inst_adr                                             "0x000F"
#define DC_PHY_DC_TEST_MODE_SEL_inst                                                 0x000F


#define DC_PHY_DC_DDR3_CTL                                                           0x18008840
#define DC_PHY_DC_DDR3_CTL_reg_addr                                                  "0xB8008840"
#define DC_PHY_DC_DDR3_CTL_reg                                                       0xB8008840
#define set_DC_PHY_DC_DDR3_CTL_reg(data)   (*((volatile unsigned int*) DC_PHY_DC_DDR3_CTL_reg)=data)
#define get_DC_PHY_DC_DDR3_CTL_reg   (*((volatile unsigned int*) DC_PHY_DC_DDR3_CTL_reg))
#define DC_PHY_DC_DDR3_CTL_inst_adr                                                  "0x0010"
#define DC_PHY_DC_DDR3_CTL_inst                                                      0x0010
#define DC_PHY_DC_DDR3_CTL_write_en_15_shift                                         (31)
#define DC_PHY_DC_DDR3_CTL_write_en_15_mask                                          (0x80000000)
#define DC_PHY_DC_DDR3_CTL_write_en_15(data)                                         (0x80000000&((data)<<31))
#define DC_PHY_DC_DDR3_CTL_write_en_15_src(data)                                     ((0x80000000&(data))>>31)
#define DC_PHY_DC_DDR3_CTL_get_write_en_15(data)                                     ((0x80000000&(data))>>31)
#define DC_PHY_DC_DDR3_CTL_dis_ap_shift                                              (30)
#define DC_PHY_DC_DDR3_CTL_dis_ap_mask                                               (0x40000000)
#define DC_PHY_DC_DDR3_CTL_dis_ap(data)                                              (0x40000000&((data)<<30))
#define DC_PHY_DC_DDR3_CTL_dis_ap_src(data)                                          ((0x40000000&(data))>>30)
#define DC_PHY_DC_DDR3_CTL_get_dis_ap(data)                                          ((0x40000000&(data))>>30)
#define DC_PHY_DC_DDR3_CTL_write_en_14_shift                                         (29)
#define DC_PHY_DC_DDR3_CTL_write_en_14_mask                                          (0x20000000)
#define DC_PHY_DC_DDR3_CTL_write_en_14(data)                                         (0x20000000&((data)<<29))
#define DC_PHY_DC_DDR3_CTL_write_en_14_src(data)                                     ((0x20000000&(data))>>29)
#define DC_PHY_DC_DDR3_CTL_get_write_en_14(data)                                     ((0x20000000&(data))>>29)
#define DC_PHY_DC_DDR3_CTL_ddr3_swap_shift                                           (28)
#define DC_PHY_DC_DDR3_CTL_ddr3_swap_mask                                            (0x10000000)
#define DC_PHY_DC_DDR3_CTL_ddr3_swap(data)                                           (0x10000000&((data)<<28))
#define DC_PHY_DC_DDR3_CTL_ddr3_swap_src(data)                                       ((0x10000000&(data))>>28)
#define DC_PHY_DC_DDR3_CTL_get_ddr3_swap(data)                                       ((0x10000000&(data))>>28)
#define DC_PHY_DC_DDR3_CTL_write_en_13_shift                                         (27)
#define DC_PHY_DC_DDR3_CTL_write_en_13_mask                                          (0x08000000)
#define DC_PHY_DC_DDR3_CTL_write_en_13(data)                                         (0x08000000&((data)<<27))
#define DC_PHY_DC_DDR3_CTL_write_en_13_src(data)                                     ((0x08000000&(data))>>27)
#define DC_PHY_DC_DDR3_CTL_get_write_en_13(data)                                     ((0x08000000&(data))>>27)
#define DC_PHY_DC_DDR3_CTL_end_500us_shift                                           (26)
#define DC_PHY_DC_DDR3_CTL_end_500us_mask                                            (0x04000000)
#define DC_PHY_DC_DDR3_CTL_end_500us(data)                                           (0x04000000&((data)<<26))
#define DC_PHY_DC_DDR3_CTL_end_500us_src(data)                                       ((0x04000000&(data))>>26)
#define DC_PHY_DC_DDR3_CTL_get_end_500us(data)                                       ((0x04000000&(data))>>26)
#define DC_PHY_DC_DDR3_CTL_write_en_12_shift                                         (25)
#define DC_PHY_DC_DDR3_CTL_write_en_12_mask                                          (0x02000000)
#define DC_PHY_DC_DDR3_CTL_write_en_12(data)                                         (0x02000000&((data)<<25))
#define DC_PHY_DC_DDR3_CTL_write_en_12_src(data)                                     ((0x02000000&(data))>>25)
#define DC_PHY_DC_DDR3_CTL_get_write_en_12(data)                                     ((0x02000000&(data))>>25)
#define DC_PHY_DC_DDR3_CTL_end_200us_shift                                           (24)
#define DC_PHY_DC_DDR3_CTL_end_200us_mask                                            (0x01000000)
#define DC_PHY_DC_DDR3_CTL_end_200us(data)                                           (0x01000000&((data)<<24))
#define DC_PHY_DC_DDR3_CTL_end_200us_src(data)                                       ((0x01000000&(data))>>24)
#define DC_PHY_DC_DDR3_CTL_get_end_200us(data)                                       ((0x01000000&(data))>>24)
#define DC_PHY_DC_DDR3_CTL_write_en_11_shift                                         (23)
#define DC_PHY_DC_DDR3_CTL_write_en_11_mask                                          (0x00800000)
#define DC_PHY_DC_DDR3_CTL_write_en_11(data)                                         (0x00800000&((data)<<23))
#define DC_PHY_DC_DDR3_CTL_write_en_11_src(data)                                     ((0x00800000&(data))>>23)
#define DC_PHY_DC_DDR3_CTL_get_write_en_11(data)                                     ((0x00800000&(data))>>23)
#define DC_PHY_DC_DDR3_CTL_fast_prechg_shift                                         (22)
#define DC_PHY_DC_DDR3_CTL_fast_prechg_mask                                          (0x00400000)
#define DC_PHY_DC_DDR3_CTL_fast_prechg(data)                                         (0x00400000&((data)<<22))
#define DC_PHY_DC_DDR3_CTL_fast_prechg_src(data)                                     ((0x00400000&(data))>>22)
#define DC_PHY_DC_DDR3_CTL_get_fast_prechg(data)                                     ((0x00400000&(data))>>22)
#define DC_PHY_DC_DDR3_CTL_write_en_10_shift                                         (21)
#define DC_PHY_DC_DDR3_CTL_write_en_10_mask                                          (0x00200000)
#define DC_PHY_DC_DDR3_CTL_write_en_10(data)                                         (0x00200000&((data)<<21))
#define DC_PHY_DC_DDR3_CTL_write_en_10_src(data)                                     ((0x00200000&(data))>>21)
#define DC_PHY_DC_DDR3_CTL_get_write_en_10(data)                                     ((0x00200000&(data))>>21)
#define DC_PHY_DC_DDR3_CTL_dis_cti_shift                                             (20)
#define DC_PHY_DC_DDR3_CTL_dis_cti_mask                                              (0x00100000)
#define DC_PHY_DC_DDR3_CTL_dis_cti(data)                                             (0x00100000&((data)<<20))
#define DC_PHY_DC_DDR3_CTL_dis_cti_src(data)                                         ((0x00100000&(data))>>20)
#define DC_PHY_DC_DDR3_CTL_get_dis_cti(data)                                         ((0x00100000&(data))>>20)
#define DC_PHY_DC_DDR3_CTL_write_en_9_shift                                          (19)
#define DC_PHY_DC_DDR3_CTL_write_en_9_mask                                           (0x00080000)
#define DC_PHY_DC_DDR3_CTL_write_en_9(data)                                          (0x00080000&((data)<<19))
#define DC_PHY_DC_DDR3_CTL_write_en_9_src(data)                                      ((0x00080000&(data))>>19)
#define DC_PHY_DC_DDR3_CTL_get_write_en_9(data)                                      ((0x00080000&(data))>>19)
#define DC_PHY_DC_DDR3_CTL_dis_8bank_shift                                           (18)
#define DC_PHY_DC_DDR3_CTL_dis_8bank_mask                                            (0x00040000)
#define DC_PHY_DC_DDR3_CTL_dis_8bank(data)                                           (0x00040000&((data)<<18))
#define DC_PHY_DC_DDR3_CTL_dis_8bank_src(data)                                       ((0x00040000&(data))>>18)
#define DC_PHY_DC_DDR3_CTL_get_dis_8bank(data)                                       ((0x00040000&(data))>>18)
#define DC_PHY_DC_DDR3_CTL_write_en_8_shift                                          (17)
#define DC_PHY_DC_DDR3_CTL_write_en_8_mask                                           (0x00020000)
#define DC_PHY_DC_DDR3_CTL_write_en_8(data)                                          (0x00020000&((data)<<17))
#define DC_PHY_DC_DDR3_CTL_write_en_8_src(data)                                      ((0x00020000&(data))>>17)
#define DC_PHY_DC_DDR3_CTL_get_write_en_8(data)                                      ((0x00020000&(data))>>17)
#define DC_PHY_DC_DDR3_CTL_use_tmmrd_shift                                           (16)
#define DC_PHY_DC_DDR3_CTL_use_tmmrd_mask                                            (0x00010000)
#define DC_PHY_DC_DDR3_CTL_use_tmmrd(data)                                           (0x00010000&((data)<<16))
#define DC_PHY_DC_DDR3_CTL_use_tmmrd_src(data)                                       ((0x00010000&(data))>>16)
#define DC_PHY_DC_DDR3_CTL_get_use_tmmrd(data)                                       ((0x00010000&(data))>>16)
#define DC_PHY_DC_DDR3_CTL_write_en_7_shift                                          (15)
#define DC_PHY_DC_DDR3_CTL_write_en_7_mask                                           (0x00008000)
#define DC_PHY_DC_DDR3_CTL_write_en_7(data)                                          (0x00008000&((data)<<15))
#define DC_PHY_DC_DDR3_CTL_write_en_7_src(data)                                      ((0x00008000&(data))>>15)
#define DC_PHY_DC_DDR3_CTL_get_write_en_7(data)                                      ((0x00008000&(data))>>15)
#define DC_PHY_DC_DDR3_CTL_dis_pre_all_shift                                         (14)
#define DC_PHY_DC_DDR3_CTL_dis_pre_all_mask                                          (0x00004000)
#define DC_PHY_DC_DDR3_CTL_dis_pre_all(data)                                         (0x00004000&((data)<<14))
#define DC_PHY_DC_DDR3_CTL_dis_pre_all_src(data)                                     ((0x00004000&(data))>>14)
#define DC_PHY_DC_DDR3_CTL_get_dis_pre_all(data)                                     ((0x00004000&(data))>>14)
#define DC_PHY_DC_DDR3_CTL_write_en_6_shift                                          (13)
#define DC_PHY_DC_DDR3_CTL_write_en_6_mask                                           (0x00002000)
#define DC_PHY_DC_DDR3_CTL_write_en_6(data)                                          (0x00002000&((data)<<13))
#define DC_PHY_DC_DDR3_CTL_write_en_6_src(data)                                      ((0x00002000&(data))>>13)
#define DC_PHY_DC_DDR3_CTL_get_write_en_6(data)                                      ((0x00002000&(data))>>13)
#define DC_PHY_DC_DDR3_CTL_ddr3_zqcl_short_shift                                     (12)
#define DC_PHY_DC_DDR3_CTL_ddr3_zqcl_short_mask                                      (0x00001000)
#define DC_PHY_DC_DDR3_CTL_ddr3_zqcl_short(data)                                     (0x00001000&((data)<<12))
#define DC_PHY_DC_DDR3_CTL_ddr3_zqcl_short_src(data)                                 ((0x00001000&(data))>>12)
#define DC_PHY_DC_DDR3_CTL_get_ddr3_zqcl_short(data)                                 ((0x00001000&(data))>>12)
#define DC_PHY_DC_DDR3_CTL_write_en_5_shift                                          (11)
#define DC_PHY_DC_DDR3_CTL_write_en_5_mask                                           (0x00000800)
#define DC_PHY_DC_DDR3_CTL_write_en_5(data)                                          (0x00000800&((data)<<11))
#define DC_PHY_DC_DDR3_CTL_write_en_5_src(data)                                      ((0x00000800&(data))>>11)
#define DC_PHY_DC_DDR3_CTL_get_write_en_5(data)                                      ((0x00000800&(data))>>11)
#define DC_PHY_DC_DDR3_CTL_ddr3_exe_zqcl_shift                                       (10)
#define DC_PHY_DC_DDR3_CTL_ddr3_exe_zqcl_mask                                        (0x00000400)
#define DC_PHY_DC_DDR3_CTL_ddr3_exe_zqcl(data)                                       (0x00000400&((data)<<10))
#define DC_PHY_DC_DDR3_CTL_ddr3_exe_zqcl_src(data)                                   ((0x00000400&(data))>>10)
#define DC_PHY_DC_DDR3_CTL_get_ddr3_exe_zqcl(data)                                   ((0x00000400&(data))>>10)
#define DC_PHY_DC_DDR3_CTL_write_en_4_shift                                          (9)
#define DC_PHY_DC_DDR3_CTL_write_en_4_mask                                           (0x00000200)
#define DC_PHY_DC_DDR3_CTL_write_en_4(data)                                          (0x00000200&((data)<<9))
#define DC_PHY_DC_DDR3_CTL_write_en_4_src(data)                                      ((0x00000200&(data))>>9)
#define DC_PHY_DC_DDR3_CTL_get_write_en_4(data)                                      ((0x00000200&(data))>>9)
#define DC_PHY_DC_DDR3_CTL_ddr3_exe_mr3_shift                                        (8)
#define DC_PHY_DC_DDR3_CTL_ddr3_exe_mr3_mask                                         (0x00000100)
#define DC_PHY_DC_DDR3_CTL_ddr3_exe_mr3(data)                                        (0x00000100&((data)<<8))
#define DC_PHY_DC_DDR3_CTL_ddr3_exe_mr3_src(data)                                    ((0x00000100&(data))>>8)
#define DC_PHY_DC_DDR3_CTL_get_ddr3_exe_mr3(data)                                    ((0x00000100&(data))>>8)
#define DC_PHY_DC_DDR3_CTL_write_en_3_shift                                          (7)
#define DC_PHY_DC_DDR3_CTL_write_en_3_mask                                           (0x00000080)
#define DC_PHY_DC_DDR3_CTL_write_en_3(data)                                          (0x00000080&((data)<<7))
#define DC_PHY_DC_DDR3_CTL_write_en_3_src(data)                                      ((0x00000080&(data))>>7)
#define DC_PHY_DC_DDR3_CTL_get_write_en_3(data)                                      ((0x00000080&(data))>>7)
#define DC_PHY_DC_DDR3_CTL_ddr3_exe_mr2_shift                                        (6)
#define DC_PHY_DC_DDR3_CTL_ddr3_exe_mr2_mask                                         (0x00000040)
#define DC_PHY_DC_DDR3_CTL_ddr3_exe_mr2(data)                                        (0x00000040&((data)<<6))
#define DC_PHY_DC_DDR3_CTL_ddr3_exe_mr2_src(data)                                    ((0x00000040&(data))>>6)
#define DC_PHY_DC_DDR3_CTL_get_ddr3_exe_mr2(data)                                    ((0x00000040&(data))>>6)
#define DC_PHY_DC_DDR3_CTL_write_en_2_shift                                          (5)
#define DC_PHY_DC_DDR3_CTL_write_en_2_mask                                           (0x00000020)
#define DC_PHY_DC_DDR3_CTL_write_en_2(data)                                          (0x00000020&((data)<<5))
#define DC_PHY_DC_DDR3_CTL_write_en_2_src(data)                                      ((0x00000020&(data))>>5)
#define DC_PHY_DC_DDR3_CTL_get_write_en_2(data)                                      ((0x00000020&(data))>>5)
#define DC_PHY_DC_DDR3_CTL_ddr3_exe_mr1_shift                                        (4)
#define DC_PHY_DC_DDR3_CTL_ddr3_exe_mr1_mask                                         (0x00000010)
#define DC_PHY_DC_DDR3_CTL_ddr3_exe_mr1(data)                                        (0x00000010&((data)<<4))
#define DC_PHY_DC_DDR3_CTL_ddr3_exe_mr1_src(data)                                    ((0x00000010&(data))>>4)
#define DC_PHY_DC_DDR3_CTL_get_ddr3_exe_mr1(data)                                    ((0x00000010&(data))>>4)
#define DC_PHY_DC_DDR3_CTL_write_en_1_shift                                          (3)
#define DC_PHY_DC_DDR3_CTL_write_en_1_mask                                           (0x00000008)
#define DC_PHY_DC_DDR3_CTL_write_en_1(data)                                          (0x00000008&((data)<<3))
#define DC_PHY_DC_DDR3_CTL_write_en_1_src(data)                                      ((0x00000008&(data))>>3)
#define DC_PHY_DC_DDR3_CTL_get_write_en_1(data)                                      ((0x00000008&(data))>>3)
#define DC_PHY_DC_DDR3_CTL_ddr3_exe_mr0_shift                                        (2)
#define DC_PHY_DC_DDR3_CTL_ddr3_exe_mr0_mask                                         (0x00000004)
#define DC_PHY_DC_DDR3_CTL_ddr3_exe_mr0(data)                                        (0x00000004&((data)<<2))
#define DC_PHY_DC_DDR3_CTL_ddr3_exe_mr0_src(data)                                    ((0x00000004&(data))>>2)
#define DC_PHY_DC_DDR3_CTL_get_ddr3_exe_mr0(data)                                    ((0x00000004&(data))>>2)
#define DC_PHY_DC_DDR3_CTL_write_en_0_shift                                          (1)
#define DC_PHY_DC_DDR3_CTL_write_en_0_mask                                           (0x00000002)
#define DC_PHY_DC_DDR3_CTL_write_en_0(data)                                          (0x00000002&((data)<<1))
#define DC_PHY_DC_DDR3_CTL_write_en_0_src(data)                                      ((0x00000002&(data))>>1)
#define DC_PHY_DC_DDR3_CTL_get_write_en_0(data)                                      ((0x00000002&(data))>>1)
#define DC_PHY_DC_DDR3_CTL_ddr3_init_shift                                           (0)
#define DC_PHY_DC_DDR3_CTL_ddr3_init_mask                                            (0x00000001)
#define DC_PHY_DC_DDR3_CTL_ddr3_init(data)                                           (0x00000001&((data)<<0))
#define DC_PHY_DC_DDR3_CTL_ddr3_init_src(data)                                       ((0x00000001&(data))>>0)
#define DC_PHY_DC_DDR3_CTL_get_ddr3_init(data)                                       ((0x00000001&(data))>>0)


#define DC_PHY_MOD_REG                                                               0x18008844
#define DC_PHY_MOD_REG_reg_addr                                                      "0xB8008844"
#define DC_PHY_MOD_REG_reg                                                           0xB8008844
#define set_DC_PHY_MOD_REG_reg(data)   (*((volatile unsigned int*) DC_PHY_MOD_REG_reg)=data)
#define get_DC_PHY_MOD_REG_reg   (*((volatile unsigned int*) DC_PHY_MOD_REG_reg))
#define DC_PHY_MOD_REG_inst_adr                                                      "0x0011"
#define DC_PHY_MOD_REG_inst                                                          0x0011
#define DC_PHY_MOD_REG_exmod_reg_shift                                               (16)
#define DC_PHY_MOD_REG_exmod_reg_mask                                                (0xFFFF0000)
#define DC_PHY_MOD_REG_exmod_reg(data)                                               (0xFFFF0000&((data)<<16))
#define DC_PHY_MOD_REG_exmod_reg_src(data)                                           ((0xFFFF0000&(data))>>16)
#define DC_PHY_MOD_REG_get_exmod_reg(data)                                           ((0xFFFF0000&(data))>>16)
#define DC_PHY_MOD_REG_mod_reg_shift                                                 (0)
#define DC_PHY_MOD_REG_mod_reg_mask                                                  (0x0000FFFF)
#define DC_PHY_MOD_REG_mod_reg(data)                                                 (0x0000FFFF&((data)<<0))
#define DC_PHY_MOD_REG_mod_reg_src(data)                                             ((0x0000FFFF&(data))>>0)
#define DC_PHY_MOD_REG_get_mod_reg(data)                                             ((0x0000FFFF&(data))>>0)


#define DC_PHY_MOD23_REG                                                             0x18008848
#define DC_PHY_MOD23_REG_reg_addr                                                    "0xB8008848"
#define DC_PHY_MOD23_REG_reg                                                         0xB8008848
#define set_DC_PHY_MOD23_REG_reg(data)   (*((volatile unsigned int*) DC_PHY_MOD23_REG_reg)=data)
#define get_DC_PHY_MOD23_REG_reg   (*((volatile unsigned int*) DC_PHY_MOD23_REG_reg))
#define DC_PHY_MOD23_REG_inst_adr                                                    "0x0012"
#define DC_PHY_MOD23_REG_inst                                                        0x0012
#define DC_PHY_MOD23_REG_mod3_reg_shift                                              (16)
#define DC_PHY_MOD23_REG_mod3_reg_mask                                               (0xFFFF0000)
#define DC_PHY_MOD23_REG_mod3_reg(data)                                              (0xFFFF0000&((data)<<16))
#define DC_PHY_MOD23_REG_mod3_reg_src(data)                                          ((0xFFFF0000&(data))>>16)
#define DC_PHY_MOD23_REG_get_mod3_reg(data)                                          ((0xFFFF0000&(data))>>16)
#define DC_PHY_MOD23_REG_mod2_reg_shift                                              (0)
#define DC_PHY_MOD23_REG_mod2_reg_mask                                               (0x0000FFFF)
#define DC_PHY_MOD23_REG_mod2_reg(data)                                              (0x0000FFFF&((data)<<0))
#define DC_PHY_MOD23_REG_mod2_reg_src(data)                                          ((0x0000FFFF&(data))>>0)
#define DC_PHY_MOD23_REG_get_mod2_reg(data)                                          ((0x0000FFFF&(data))>>0)


#define DC_PHY_RFIFO_CTL                                                             0x1800884c
#define DC_PHY_RFIFO_CTL_reg_addr                                                    "0xB800884C"
#define DC_PHY_RFIFO_CTL_reg                                                         0xB800884C
#define set_DC_PHY_RFIFO_CTL_reg(data)   (*((volatile unsigned int*) DC_PHY_RFIFO_CTL_reg)=data)
#define get_DC_PHY_RFIFO_CTL_reg   (*((volatile unsigned int*) DC_PHY_RFIFO_CTL_reg))
#define DC_PHY_RFIFO_CTL_inst_adr                                                    "0x0013"
#define DC_PHY_RFIFO_CTL_inst                                                        0x0013
#define DC_PHY_RFIFO_CTL_wfifo_rdy_gated_shift                                       (12)
#define DC_PHY_RFIFO_CTL_wfifo_rdy_gated_mask                                        (0x00001000)
#define DC_PHY_RFIFO_CTL_wfifo_rdy_gated(data)                                       (0x00001000&((data)<<12))
#define DC_PHY_RFIFO_CTL_wfifo_rdy_gated_src(data)                                   ((0x00001000&(data))>>12)
#define DC_PHY_RFIFO_CTL_get_wfifo_rdy_gated(data)                                   ((0x00001000&(data))>>12)
#define DC_PHY_RFIFO_CTL_rdwr_use_full_shift                                         (8)
#define DC_PHY_RFIFO_CTL_rdwr_use_full_mask                                          (0x00000100)
#define DC_PHY_RFIFO_CTL_rdwr_use_full(data)                                         (0x00000100&((data)<<8))
#define DC_PHY_RFIFO_CTL_rdwr_use_full_src(data)                                     ((0x00000100&(data))>>8)
#define DC_PHY_RFIFO_CTL_get_rdwr_use_full(data)                                     ((0x00000100&(data))>>8)
#define DC_PHY_RFIFO_CTL_full_gated_shift                                            (7)
#define DC_PHY_RFIFO_CTL_full_gated_mask                                             (0x00000080)
#define DC_PHY_RFIFO_CTL_full_gated(data)                                            (0x00000080&((data)<<7))
#define DC_PHY_RFIFO_CTL_full_gated_src(data)                                        ((0x00000080&(data))>>7)
#define DC_PHY_RFIFO_CTL_get_full_gated(data)                                        ((0x00000080&(data))>>7)
#define DC_PHY_RFIFO_CTL_rfifo_thred_shift                                           (0)
#define DC_PHY_RFIFO_CTL_rfifo_thred_mask                                            (0x0000007F)
#define DC_PHY_RFIFO_CTL_rfifo_thred(data)                                           (0x0000007F&((data)<<0))
#define DC_PHY_RFIFO_CTL_rfifo_thred_src(data)                                       ((0x0000007F&(data))>>0)
#define DC_PHY_RFIFO_CTL_get_rfifo_thred(data)                                       ((0x0000007F&(data))>>0)


#define DC_PHY_ERR_STATUS                                                            0x18008850
#define DC_PHY_ERR_STATUS_reg_addr                                                   "0xB8008850"
#define DC_PHY_ERR_STATUS_reg                                                        0xB8008850
#define set_DC_PHY_ERR_STATUS_reg(data)   (*((volatile unsigned int*) DC_PHY_ERR_STATUS_reg)=data)
#define get_DC_PHY_ERR_STATUS_reg   (*((volatile unsigned int*) DC_PHY_ERR_STATUS_reg))
#define DC_PHY_ERR_STATUS_inst_adr                                                   "0x0014"
#define DC_PHY_ERR_STATUS_inst                                                       0x0014
#define DC_PHY_ERR_STATUS_sys2_wfifo_underflow_shift                                 (9)
#define DC_PHY_ERR_STATUS_sys2_wfifo_underflow_mask                                  (0x00000200)
#define DC_PHY_ERR_STATUS_sys2_wfifo_underflow(data)                                 (0x00000200&((data)<<9))
#define DC_PHY_ERR_STATUS_sys2_wfifo_underflow_src(data)                             ((0x00000200&(data))>>9)
#define DC_PHY_ERR_STATUS_get_sys2_wfifo_underflow(data)                             ((0x00000200&(data))>>9)
#define DC_PHY_ERR_STATUS_sys2_wfifo_overflow_shift                                  (8)
#define DC_PHY_ERR_STATUS_sys2_wfifo_overflow_mask                                   (0x00000100)
#define DC_PHY_ERR_STATUS_sys2_wfifo_overflow(data)                                  (0x00000100&((data)<<8))
#define DC_PHY_ERR_STATUS_sys2_wfifo_overflow_src(data)                              ((0x00000100&(data))>>8)
#define DC_PHY_ERR_STATUS_get_sys2_wfifo_overflow(data)                              ((0x00000100&(data))>>8)
#define DC_PHY_ERR_STATUS_sys1_wfifo_underflow_shift                                 (7)
#define DC_PHY_ERR_STATUS_sys1_wfifo_underflow_mask                                  (0x00000080)
#define DC_PHY_ERR_STATUS_sys1_wfifo_underflow(data)                                 (0x00000080&((data)<<7))
#define DC_PHY_ERR_STATUS_sys1_wfifo_underflow_src(data)                             ((0x00000080&(data))>>7)
#define DC_PHY_ERR_STATUS_get_sys1_wfifo_underflow(data)                             ((0x00000080&(data))>>7)
#define DC_PHY_ERR_STATUS_sys1_wfifo_overflow_shift                                  (6)
#define DC_PHY_ERR_STATUS_sys1_wfifo_overflow_mask                                   (0x00000040)
#define DC_PHY_ERR_STATUS_sys1_wfifo_overflow(data)                                  (0x00000040&((data)<<6))
#define DC_PHY_ERR_STATUS_sys1_wfifo_overflow_src(data)                              ((0x00000040&(data))>>6)
#define DC_PHY_ERR_STATUS_get_sys1_wfifo_overflow(data)                              ((0x00000040&(data))>>6)
#define DC_PHY_ERR_STATUS_sys2_qfifo_underflow_shift                                 (5)
#define DC_PHY_ERR_STATUS_sys2_qfifo_underflow_mask                                  (0x00000020)
#define DC_PHY_ERR_STATUS_sys2_qfifo_underflow(data)                                 (0x00000020&((data)<<5))
#define DC_PHY_ERR_STATUS_sys2_qfifo_underflow_src(data)                             ((0x00000020&(data))>>5)
#define DC_PHY_ERR_STATUS_get_sys2_qfifo_underflow(data)                             ((0x00000020&(data))>>5)
#define DC_PHY_ERR_STATUS_sys2_qfifo_overflow_shift                                  (4)
#define DC_PHY_ERR_STATUS_sys2_qfifo_overflow_mask                                   (0x00000010)
#define DC_PHY_ERR_STATUS_sys2_qfifo_overflow(data)                                  (0x00000010&((data)<<4))
#define DC_PHY_ERR_STATUS_sys2_qfifo_overflow_src(data)                              ((0x00000010&(data))>>4)
#define DC_PHY_ERR_STATUS_get_sys2_qfifo_overflow(data)                              ((0x00000010&(data))>>4)
#define DC_PHY_ERR_STATUS_sys1_qfifo_underflow_shift                                 (3)
#define DC_PHY_ERR_STATUS_sys1_qfifo_underflow_mask                                  (0x00000008)
#define DC_PHY_ERR_STATUS_sys1_qfifo_underflow(data)                                 (0x00000008&((data)<<3))
#define DC_PHY_ERR_STATUS_sys1_qfifo_underflow_src(data)                             ((0x00000008&(data))>>3)
#define DC_PHY_ERR_STATUS_get_sys1_qfifo_underflow(data)                             ((0x00000008&(data))>>3)
#define DC_PHY_ERR_STATUS_sys1_qfifo_overflow_shift                                  (2)
#define DC_PHY_ERR_STATUS_sys1_qfifo_overflow_mask                                   (0x00000004)
#define DC_PHY_ERR_STATUS_sys1_qfifo_overflow(data)                                  (0x00000004&((data)<<2))
#define DC_PHY_ERR_STATUS_sys1_qfifo_overflow_src(data)                              ((0x00000004&(data))>>2)
#define DC_PHY_ERR_STATUS_get_sys1_qfifo_overflow(data)                              ((0x00000004&(data))>>2)
#define DC_PHY_ERR_STATUS_err_cti_cmd_shift                                          (1)
#define DC_PHY_ERR_STATUS_err_cti_cmd_mask                                           (0x00000002)
#define DC_PHY_ERR_STATUS_err_cti_cmd(data)                                          (0x00000002&((data)<<1))
#define DC_PHY_ERR_STATUS_err_cti_cmd_src(data)                                      ((0x00000002&(data))>>1)
#define DC_PHY_ERR_STATUS_get_err_cti_cmd(data)                                      ((0x00000002&(data))>>1)
#define DC_PHY_ERR_STATUS_err_active_shift                                           (0)
#define DC_PHY_ERR_STATUS_err_active_mask                                            (0x00000001)
#define DC_PHY_ERR_STATUS_err_active(data)                                           (0x00000001&((data)<<0))
#define DC_PHY_ERR_STATUS_err_active_src(data)                                       ((0x00000001&(data))>>0)
#define DC_PHY_ERR_STATUS_get_err_active(data)                                       ((0x00000001&(data))>>0)


#define DC_PHY_DC_WRITE_LEVEL                                                        0x18008854
#define DC_PHY_DC_WRITE_LEVEL_reg_addr                                               "0xB8008854"
#define DC_PHY_DC_WRITE_LEVEL_reg                                                    0xB8008854
#define set_DC_PHY_DC_WRITE_LEVEL_reg(data)   (*((volatile unsigned int*) DC_PHY_DC_WRITE_LEVEL_reg)=data)
#define get_DC_PHY_DC_WRITE_LEVEL_reg   (*((volatile unsigned int*) DC_PHY_DC_WRITE_LEVEL_reg))
#define DC_PHY_DC_WRITE_LEVEL_inst_adr                                               "0x0015"
#define DC_PHY_DC_WRITE_LEVEL_inst                                                   0x0015
#define DC_PHY_DC_WRITE_LEVEL_exe_prea_shift                                         (3)
#define DC_PHY_DC_WRITE_LEVEL_exe_prea_mask                                          (0x00000008)
#define DC_PHY_DC_WRITE_LEVEL_exe_prea(data)                                         (0x00000008&((data)<<3))
#define DC_PHY_DC_WRITE_LEVEL_exe_prea_src(data)                                     ((0x00000008&(data))>>3)
#define DC_PHY_DC_WRITE_LEVEL_get_exe_prea(data)                                     ((0x00000008&(data))>>3)
#define DC_PHY_DC_WRITE_LEVEL_dis_refresh_shift                                      (2)
#define DC_PHY_DC_WRITE_LEVEL_dis_refresh_mask                                       (0x00000004)
#define DC_PHY_DC_WRITE_LEVEL_dis_refresh(data)                                      (0x00000004&((data)<<2))
#define DC_PHY_DC_WRITE_LEVEL_dis_refresh_src(data)                                  ((0x00000004&(data))>>2)
#define DC_PHY_DC_WRITE_LEVEL_get_dis_refresh(data)                                  ((0x00000004&(data))>>2)


#define DC_PHY_INT_ENABLE                                                            0x18008858
#define DC_PHY_INT_ENABLE_reg_addr                                                   "0xB8008858"
#define DC_PHY_INT_ENABLE_reg                                                        0xB8008858
#define set_DC_PHY_INT_ENABLE_reg(data)   (*((volatile unsigned int*) DC_PHY_INT_ENABLE_reg)=data)
#define get_DC_PHY_INT_ENABLE_reg   (*((volatile unsigned int*) DC_PHY_INT_ENABLE_reg))
#define DC_PHY_INT_ENABLE_inst_adr                                                   "0x0016"
#define DC_PHY_INT_ENABLE_inst                                                       0x0016
#define DC_PHY_INT_ENABLE_int_sys2_wfifo_underflow_en_shift                          (13)
#define DC_PHY_INT_ENABLE_int_sys2_wfifo_underflow_en_mask                           (0x00002000)
#define DC_PHY_INT_ENABLE_int_sys2_wfifo_underflow_en(data)                          (0x00002000&((data)<<13))
#define DC_PHY_INT_ENABLE_int_sys2_wfifo_underflow_en_src(data)                      ((0x00002000&(data))>>13)
#define DC_PHY_INT_ENABLE_get_int_sys2_wfifo_underflow_en(data)                      ((0x00002000&(data))>>13)
#define DC_PHY_INT_ENABLE_int_sys2_wfifo_overflow_en_shift                           (12)
#define DC_PHY_INT_ENABLE_int_sys2_wfifo_overflow_en_mask                            (0x00001000)
#define DC_PHY_INT_ENABLE_int_sys2_wfifo_overflow_en(data)                           (0x00001000&((data)<<12))
#define DC_PHY_INT_ENABLE_int_sys2_wfifo_overflow_en_src(data)                       ((0x00001000&(data))>>12)
#define DC_PHY_INT_ENABLE_get_int_sys2_wfifo_overflow_en(data)                       ((0x00001000&(data))>>12)
#define DC_PHY_INT_ENABLE_int_sys1_wfifo_underflow_en_shift                          (11)
#define DC_PHY_INT_ENABLE_int_sys1_wfifo_underflow_en_mask                           (0x00000800)
#define DC_PHY_INT_ENABLE_int_sys1_wfifo_underflow_en(data)                          (0x00000800&((data)<<11))
#define DC_PHY_INT_ENABLE_int_sys1_wfifo_underflow_en_src(data)                      ((0x00000800&(data))>>11)
#define DC_PHY_INT_ENABLE_get_int_sys1_wfifo_underflow_en(data)                      ((0x00000800&(data))>>11)
#define DC_PHY_INT_ENABLE_int_sys1_wfifo_overflow_en_shift                           (10)
#define DC_PHY_INT_ENABLE_int_sys1_wfifo_overflow_en_mask                            (0x00000400)
#define DC_PHY_INT_ENABLE_int_sys1_wfifo_overflow_en(data)                           (0x00000400&((data)<<10))
#define DC_PHY_INT_ENABLE_int_sys1_wfifo_overflow_en_src(data)                       ((0x00000400&(data))>>10)
#define DC_PHY_INT_ENABLE_get_int_sys1_wfifo_overflow_en(data)                       ((0x00000400&(data))>>10)
#define DC_PHY_INT_ENABLE_int_sys2_qfifo_underflow_en_shift                          (9)
#define DC_PHY_INT_ENABLE_int_sys2_qfifo_underflow_en_mask                           (0x00000200)
#define DC_PHY_INT_ENABLE_int_sys2_qfifo_underflow_en(data)                          (0x00000200&((data)<<9))
#define DC_PHY_INT_ENABLE_int_sys2_qfifo_underflow_en_src(data)                      ((0x00000200&(data))>>9)
#define DC_PHY_INT_ENABLE_get_int_sys2_qfifo_underflow_en(data)                      ((0x00000200&(data))>>9)
#define DC_PHY_INT_ENABLE_int_sys2_qfifo_overflow_en_shift                           (8)
#define DC_PHY_INT_ENABLE_int_sys2_qfifo_overflow_en_mask                            (0x00000100)
#define DC_PHY_INT_ENABLE_int_sys2_qfifo_overflow_en(data)                           (0x00000100&((data)<<8))
#define DC_PHY_INT_ENABLE_int_sys2_qfifo_overflow_en_src(data)                       ((0x00000100&(data))>>8)
#define DC_PHY_INT_ENABLE_get_int_sys2_qfifo_overflow_en(data)                       ((0x00000100&(data))>>8)
#define DC_PHY_INT_ENABLE_int_sys1_qfifo_underflow_en_shift                          (7)
#define DC_PHY_INT_ENABLE_int_sys1_qfifo_underflow_en_mask                           (0x00000080)
#define DC_PHY_INT_ENABLE_int_sys1_qfifo_underflow_en(data)                          (0x00000080&((data)<<7))
#define DC_PHY_INT_ENABLE_int_sys1_qfifo_underflow_en_src(data)                      ((0x00000080&(data))>>7)
#define DC_PHY_INT_ENABLE_get_int_sys1_qfifo_underflow_en(data)                      ((0x00000080&(data))>>7)
#define DC_PHY_INT_ENABLE_int_sys1_qfifo_overflow_en_shift                           (6)
#define DC_PHY_INT_ENABLE_int_sys1_qfifo_overflow_en_mask                            (0x00000040)
#define DC_PHY_INT_ENABLE_int_sys1_qfifo_overflow_en(data)                           (0x00000040&((data)<<6))
#define DC_PHY_INT_ENABLE_int_sys1_qfifo_overflow_en_src(data)                       ((0x00000040&(data))>>6)
#define DC_PHY_INT_ENABLE_get_int_sys1_qfifo_overflow_en(data)                       ((0x00000040&(data))>>6)
#define DC_PHY_INT_ENABLE_int_err_cticmd_en_shift                                    (4)
#define DC_PHY_INT_ENABLE_int_err_cticmd_en_mask                                     (0x00000010)
#define DC_PHY_INT_ENABLE_int_err_cticmd_en(data)                                    (0x00000010&((data)<<4))
#define DC_PHY_INT_ENABLE_int_err_cticmd_en_src(data)                                ((0x00000010&(data))>>4)
#define DC_PHY_INT_ENABLE_get_int_err_cticmd_en(data)                                ((0x00000010&(data))>>4)
#define DC_PHY_INT_ENABLE_int_err_active_en_shift                                    (3)
#define DC_PHY_INT_ENABLE_int_err_active_en_mask                                     (0x00000008)
#define DC_PHY_INT_ENABLE_int_err_active_en(data)                                    (0x00000008&((data)<<3))
#define DC_PHY_INT_ENABLE_int_err_active_en_src(data)                                ((0x00000008&(data))>>3)
#define DC_PHY_INT_ENABLE_get_int_err_active_en(data)                                ((0x00000008&(data))>>3)
#define DC_PHY_INT_ENABLE_int_en_shift                                               (0)
#define DC_PHY_INT_ENABLE_int_en_mask                                                (0x00000001)
#define DC_PHY_INT_ENABLE_int_en(data)                                               (0x00000001&((data)<<0))
#define DC_PHY_INT_ENABLE_int_en_src(data)                                           ((0x00000001&(data))>>0)
#define DC_PHY_INT_ENABLE_get_int_en(data)                                           ((0x00000001&(data))>>0)


#define DC_PHY_RFIFO_MAXCNT                                                          0x1800885c
#define DC_PHY_RFIFO_MAXCNT_reg_addr                                                 "0xB800885C"
#define DC_PHY_RFIFO_MAXCNT_reg                                                      0xB800885C
#define set_DC_PHY_RFIFO_MAXCNT_reg(data)   (*((volatile unsigned int*) DC_PHY_RFIFO_MAXCNT_reg)=data)
#define get_DC_PHY_RFIFO_MAXCNT_reg   (*((volatile unsigned int*) DC_PHY_RFIFO_MAXCNT_reg))
#define DC_PHY_RFIFO_MAXCNT_inst_adr                                                 "0x0017"
#define DC_PHY_RFIFO_MAXCNT_inst                                                     0x0017


#define DC_PHY_SM_STATUS                                                             0x18008860
#define DC_PHY_SM_STATUS_reg_addr                                                    "0xB8008860"
#define DC_PHY_SM_STATUS_reg                                                         0xB8008860
#define set_DC_PHY_SM_STATUS_reg(data)   (*((volatile unsigned int*) DC_PHY_SM_STATUS_reg)=data)
#define get_DC_PHY_SM_STATUS_reg   (*((volatile unsigned int*) DC_PHY_SM_STATUS_reg))
#define DC_PHY_SM_STATUS_inst_adr                                                    "0x0018"
#define DC_PHY_SM_STATUS_inst                                                        0x0018
#define DC_PHY_SM_STATUS_bank_act_shift                                              (24)
#define DC_PHY_SM_STATUS_bank_act_mask                                               (0xFF000000)
#define DC_PHY_SM_STATUS_bank_act(data)                                              (0xFF000000&((data)<<24))
#define DC_PHY_SM_STATUS_bank_act_src(data)                                          ((0xFF000000&(data))>>24)
#define DC_PHY_SM_STATUS_get_bank_act(data)                                          ((0xFF000000&(data))>>24)
#define DC_PHY_SM_STATUS_cmd_cnt_shift                                               (20)
#define DC_PHY_SM_STATUS_cmd_cnt_mask                                                (0x00700000)
#define DC_PHY_SM_STATUS_cmd_cnt(data)                                               (0x00700000&((data)<<20))
#define DC_PHY_SM_STATUS_cmd_cnt_src(data)                                           ((0x00700000&(data))>>20)
#define DC_PHY_SM_STATUS_get_cmd_cnt(data)                                           ((0x00700000&(data))>>20)
#define DC_PHY_SM_STATUS_par_st_shift                                                (0)
#define DC_PHY_SM_STATUS_par_st_mask                                                 (0x0007FFFF)
#define DC_PHY_SM_STATUS_par_st(data)                                                (0x0007FFFF&((data)<<0))
#define DC_PHY_SM_STATUS_par_st_src(data)                                            ((0x0007FFFF&(data))>>0)
#define DC_PHY_SM_STATUS_get_par_st(data)                                            ((0x0007FFFF&(data))>>0)


#define DC_PHY_WFIFO_CNT                                                             0x18008864
#define DC_PHY_WFIFO_CNT_reg_addr                                                    "0xB8008864"
#define DC_PHY_WFIFO_CNT_reg                                                         0xB8008864
#define set_DC_PHY_WFIFO_CNT_reg(data)   (*((volatile unsigned int*) DC_PHY_WFIFO_CNT_reg)=data)
#define get_DC_PHY_WFIFO_CNT_reg   (*((volatile unsigned int*) DC_PHY_WFIFO_CNT_reg))
#define DC_PHY_WFIFO_CNT_inst_adr                                                    "0x0019"
#define DC_PHY_WFIFO_CNT_inst                                                        0x0019
#define DC_PHY_WFIFO_CNT_wfifo_ddr_req_statistic_en_shift                            (30)
#define DC_PHY_WFIFO_CNT_wfifo_ddr_req_statistic_en_mask                             (0x40000000)
#define DC_PHY_WFIFO_CNT_wfifo_ddr_req_statistic_en(data)                            (0x40000000&((data)<<30))
#define DC_PHY_WFIFO_CNT_wfifo_ddr_req_statistic_en_src(data)                        ((0x40000000&(data))>>30)
#define DC_PHY_WFIFO_CNT_get_wfifo_ddr_req_statistic_en(data)                        ((0x40000000&(data))>>30)
#define DC_PHY_WFIFO_CNT_clear_wfifo_record_shift                                    (29)
#define DC_PHY_WFIFO_CNT_clear_wfifo_record_mask                                     (0x20000000)
#define DC_PHY_WFIFO_CNT_clear_wfifo_record(data)                                    (0x20000000&((data)<<29))
#define DC_PHY_WFIFO_CNT_clear_wfifo_record_src(data)                                ((0x20000000&(data))>>29)
#define DC_PHY_WFIFO_CNT_get_clear_wfifo_record(data)                                ((0x20000000&(data))>>29)
#define DC_PHY_WFIFO_CNT_wfifo_rd_cnt_et_shift                                       (16)
#define DC_PHY_WFIFO_CNT_wfifo_rd_cnt_et_mask                                        (0x00FF0000)
#define DC_PHY_WFIFO_CNT_wfifo_rd_cnt_et(data)                                       (0x00FF0000&((data)<<16))
#define DC_PHY_WFIFO_CNT_wfifo_rd_cnt_et_src(data)                                   ((0x00FF0000&(data))>>16)
#define DC_PHY_WFIFO_CNT_get_wfifo_rd_cnt_et(data)                                   ((0x00FF0000&(data))>>16)
#define DC_PHY_WFIFO_CNT_wfifo_rd_cnt_rl_shift                                       (8)
#define DC_PHY_WFIFO_CNT_wfifo_rd_cnt_rl_mask                                        (0x0000FF00)
#define DC_PHY_WFIFO_CNT_wfifo_rd_cnt_rl(data)                                       (0x0000FF00&((data)<<8))
#define DC_PHY_WFIFO_CNT_wfifo_rd_cnt_rl_src(data)                                   ((0x0000FF00&(data))>>8)
#define DC_PHY_WFIFO_CNT_get_wfifo_rd_cnt_rl(data)                                   ((0x0000FF00&(data))>>8)
#define DC_PHY_WFIFO_CNT_wfifo_wr_cnt_rl_shift                                       (0)
#define DC_PHY_WFIFO_CNT_wfifo_wr_cnt_rl_mask                                        (0x000000FF)
#define DC_PHY_WFIFO_CNT_wfifo_wr_cnt_rl(data)                                       (0x000000FF&((data)<<0))
#define DC_PHY_WFIFO_CNT_wfifo_wr_cnt_rl_src(data)                                   ((0x000000FF&(data))>>0)
#define DC_PHY_WFIFO_CNT_get_wfifo_wr_cnt_rl(data)                                   ((0x000000FF&(data))>>0)


#define DC_PHY_DC_DEBUG                                                              0x18008868
#define DC_PHY_DC_DEBUG_reg_addr                                                     "0xB8008868"
#define DC_PHY_DC_DEBUG_reg                                                          0xB8008868
#define set_DC_PHY_DC_DEBUG_reg(data)   (*((volatile unsigned int*) DC_PHY_DC_DEBUG_reg)=data)
#define get_DC_PHY_DC_DEBUG_reg   (*((volatile unsigned int*) DC_PHY_DC_DEBUG_reg))
#define DC_PHY_DC_DEBUG_inst_adr                                                     "0x001A"
#define DC_PHY_DC_DEBUG_inst                                                         0x001A
#define DC_PHY_DC_DEBUG_dbg_mod_shift                                                (0)
#define DC_PHY_DC_DEBUG_dbg_mod_mask                                                 (0x0000003F)
#define DC_PHY_DC_DEBUG_dbg_mod(data)                                                (0x0000003F&((data)<<0))
#define DC_PHY_DC_DEBUG_dbg_mod_src(data)                                            ((0x0000003F&(data))>>0)
#define DC_PHY_DC_DEBUG_get_dbg_mod(data)                                            ((0x0000003F&(data))>>0)


#define DC_PHY_PRE_CNT                                                               0x1800886C
#define DC_PHY_PRE_CNT_reg_addr                                                      "0xB800886C"
#define DC_PHY_PRE_CNT_reg                                                           0xB800886C
#define set_DC_PHY_PRE_CNT_reg(data)   (*((volatile unsigned int*) DC_PHY_PRE_CNT_reg)=data)
#define get_DC_PHY_PRE_CNT_reg   (*((volatile unsigned int*) DC_PHY_PRE_CNT_reg))
#define DC_PHY_PRE_CNT_inst_adr                                                      "0x001B"
#define DC_PHY_PRE_CNT_inst                                                          0x001B


#define DC_PHY_WFIFO_SYS_REQ_WAIT                                                    0x18008870
#define DC_PHY_WFIFO_SYS_REQ_WAIT_reg_addr                                           "0xB8008870"
#define DC_PHY_WFIFO_SYS_REQ_WAIT_reg                                                0xB8008870
#define set_DC_PHY_WFIFO_SYS_REQ_WAIT_reg(data)   (*((volatile unsigned int*) DC_PHY_WFIFO_SYS_REQ_WAIT_reg)=data)
#define get_DC_PHY_WFIFO_SYS_REQ_WAIT_reg   (*((volatile unsigned int*) DC_PHY_WFIFO_SYS_REQ_WAIT_reg))
#define DC_PHY_WFIFO_SYS_REQ_WAIT_inst_adr                                           "0x001C"
#define DC_PHY_WFIFO_SYS_REQ_WAIT_inst                                               0x001C


#define DC_PHY_WFIFO_DDR_REQ_WAIT                                                    0x18008874
#define DC_PHY_WFIFO_DDR_REQ_WAIT_reg_addr                                           "0xB8008874"
#define DC_PHY_WFIFO_DDR_REQ_WAIT_reg                                                0xB8008874
#define set_DC_PHY_WFIFO_DDR_REQ_WAIT_reg(data)   (*((volatile unsigned int*) DC_PHY_WFIFO_DDR_REQ_WAIT_reg)=data)
#define get_DC_PHY_WFIFO_DDR_REQ_WAIT_reg   (*((volatile unsigned int*) DC_PHY_WFIFO_DDR_REQ_WAIT_reg))
#define DC_PHY_WFIFO_DDR_REQ_WAIT_inst_adr                                           "0x001D"
#define DC_PHY_WFIFO_DDR_REQ_WAIT_inst                                               0x001D
#define DC_PHY_WFIFO_DDR_REQ_WAIT_wfifo_ddr_req_wait_total_shift                     (0)
#define DC_PHY_WFIFO_DDR_REQ_WAIT_wfifo_ddr_req_wait_total_mask                      (0xFFFFFFFF)
#define DC_PHY_WFIFO_DDR_REQ_WAIT_wfifo_ddr_req_wait_total(data)                     (0xFFFFFFFF&((data)<<0))
#define DC_PHY_WFIFO_DDR_REQ_WAIT_wfifo_ddr_req_wait_total_src(data)                 ((0xFFFFFFFF&(data))>>0)
#define DC_PHY_WFIFO_DDR_REQ_WAIT_get_wfifo_ddr_req_wait_total(data)                 ((0xFFFFFFFF&(data))>>0)


#define DC_PHY_WFIFO_MAX_REQ_WAIT                                                    0x18008878
#define DC_PHY_WFIFO_MAX_REQ_WAIT_reg_addr                                           "0xB8008878"
#define DC_PHY_WFIFO_MAX_REQ_WAIT_reg                                                0xB8008878
#define set_DC_PHY_WFIFO_MAX_REQ_WAIT_reg(data)   (*((volatile unsigned int*) DC_PHY_WFIFO_MAX_REQ_WAIT_reg)=data)
#define get_DC_PHY_WFIFO_MAX_REQ_WAIT_reg   (*((volatile unsigned int*) DC_PHY_WFIFO_MAX_REQ_WAIT_reg))
#define DC_PHY_WFIFO_MAX_REQ_WAIT_inst_adr                                           "0x001E"
#define DC_PHY_WFIFO_MAX_REQ_WAIT_inst                                               0x001E
#define DC_PHY_WFIFO_MAX_REQ_WAIT_wfifo_ddr_req_wait_max_shift                       (16)
#define DC_PHY_WFIFO_MAX_REQ_WAIT_wfifo_ddr_req_wait_max_mask                        (0xFFFF0000)
#define DC_PHY_WFIFO_MAX_REQ_WAIT_wfifo_ddr_req_wait_max(data)                       (0xFFFF0000&((data)<<16))
#define DC_PHY_WFIFO_MAX_REQ_WAIT_wfifo_ddr_req_wait_max_src(data)                   ((0xFFFF0000&(data))>>16)
#define DC_PHY_WFIFO_MAX_REQ_WAIT_get_wfifo_ddr_req_wait_max(data)                   ((0xFFFF0000&(data))>>16)


#define DC_PHY_AUTO_SHORT_ZQ_CAL                                                     0x1800887C
#define DC_PHY_AUTO_SHORT_ZQ_CAL_reg_addr                                            "0xB800887C"
#define DC_PHY_AUTO_SHORT_ZQ_CAL_reg                                                 0xB800887C
#define set_DC_PHY_AUTO_SHORT_ZQ_CAL_reg(data)   (*((volatile unsigned int*) DC_PHY_AUTO_SHORT_ZQ_CAL_reg)=data)
#define get_DC_PHY_AUTO_SHORT_ZQ_CAL_reg   (*((volatile unsigned int*) DC_PHY_AUTO_SHORT_ZQ_CAL_reg))
#define DC_PHY_AUTO_SHORT_ZQ_CAL_inst_adr                                            "0x001F"
#define DC_PHY_AUTO_SHORT_ZQ_CAL_inst                                                0x001F
#define DC_PHY_AUTO_SHORT_ZQ_CAL_short_zqcl_per_sel_shift                            (1)
#define DC_PHY_AUTO_SHORT_ZQ_CAL_short_zqcl_per_sel_mask                             (0x0000000E)
#define DC_PHY_AUTO_SHORT_ZQ_CAL_short_zqcl_per_sel(data)                            (0x0000000E&((data)<<1))
#define DC_PHY_AUTO_SHORT_ZQ_CAL_short_zqcl_per_sel_src(data)                        ((0x0000000E&(data))>>1)
#define DC_PHY_AUTO_SHORT_ZQ_CAL_get_short_zqcl_per_sel(data)                        ((0x0000000E&(data))>>1)
#define DC_PHY_AUTO_SHORT_ZQ_CAL_auto_short_zqcl_en_shift                            (0)
#define DC_PHY_AUTO_SHORT_ZQ_CAL_auto_short_zqcl_en_mask                             (0x00000001)
#define DC_PHY_AUTO_SHORT_ZQ_CAL_auto_short_zqcl_en(data)                            (0x00000001&((data)<<0))
#define DC_PHY_AUTO_SHORT_ZQ_CAL_auto_short_zqcl_en_src(data)                        ((0x00000001&(data))>>0)
#define DC_PHY_AUTO_SHORT_ZQ_CAL_get_auto_short_zqcl_en(data)                        ((0x00000001&(data))>>0)


#define DC_PHY_WFIFO2_CNT                                                            0x18008880
#define DC_PHY_WFIFO2_CNT_reg_addr                                                   "0xB8008880"
#define DC_PHY_WFIFO2_CNT_reg                                                        0xB8008880
#define set_DC_PHY_WFIFO2_CNT_reg(data)   (*((volatile unsigned int*) DC_PHY_WFIFO2_CNT_reg)=data)
#define get_DC_PHY_WFIFO2_CNT_reg   (*((volatile unsigned int*) DC_PHY_WFIFO2_CNT_reg))
#define DC_PHY_WFIFO2_CNT_inst_adr                                                   "0x0020"
#define DC_PHY_WFIFO2_CNT_inst                                                       0x0020
#define DC_PHY_WFIFO2_CNT_wfifo_ddr_req_statistic_en_shift                           (30)
#define DC_PHY_WFIFO2_CNT_wfifo_ddr_req_statistic_en_mask                            (0x40000000)
#define DC_PHY_WFIFO2_CNT_wfifo_ddr_req_statistic_en(data)                           (0x40000000&((data)<<30))
#define DC_PHY_WFIFO2_CNT_wfifo_ddr_req_statistic_en_src(data)                       ((0x40000000&(data))>>30)
#define DC_PHY_WFIFO2_CNT_get_wfifo_ddr_req_statistic_en(data)                       ((0x40000000&(data))>>30)
#define DC_PHY_WFIFO2_CNT_clear_wfifo_record_shift                                   (29)
#define DC_PHY_WFIFO2_CNT_clear_wfifo_record_mask                                    (0x20000000)
#define DC_PHY_WFIFO2_CNT_clear_wfifo_record(data)                                   (0x20000000&((data)<<29))
#define DC_PHY_WFIFO2_CNT_clear_wfifo_record_src(data)                               ((0x20000000&(data))>>29)
#define DC_PHY_WFIFO2_CNT_get_clear_wfifo_record(data)                               ((0x20000000&(data))>>29)
#define DC_PHY_WFIFO2_CNT_wfifo_rd_cnt_et_shift                                      (16)
#define DC_PHY_WFIFO2_CNT_wfifo_rd_cnt_et_mask                                       (0x00FF0000)
#define DC_PHY_WFIFO2_CNT_wfifo_rd_cnt_et(data)                                      (0x00FF0000&((data)<<16))
#define DC_PHY_WFIFO2_CNT_wfifo_rd_cnt_et_src(data)                                  ((0x00FF0000&(data))>>16)
#define DC_PHY_WFIFO2_CNT_get_wfifo_rd_cnt_et(data)                                  ((0x00FF0000&(data))>>16)
#define DC_PHY_WFIFO2_CNT_wfifo_rd_cnt_rl_shift                                      (8)
#define DC_PHY_WFIFO2_CNT_wfifo_rd_cnt_rl_mask                                       (0x0000FF00)
#define DC_PHY_WFIFO2_CNT_wfifo_rd_cnt_rl(data)                                      (0x0000FF00&((data)<<8))
#define DC_PHY_WFIFO2_CNT_wfifo_rd_cnt_rl_src(data)                                  ((0x0000FF00&(data))>>8)
#define DC_PHY_WFIFO2_CNT_get_wfifo_rd_cnt_rl(data)                                  ((0x0000FF00&(data))>>8)
#define DC_PHY_WFIFO2_CNT_wfifo_wr_cnt_rl_shift                                      (0)
#define DC_PHY_WFIFO2_CNT_wfifo_wr_cnt_rl_mask                                       (0x000000FF)
#define DC_PHY_WFIFO2_CNT_wfifo_wr_cnt_rl(data)                                      (0x000000FF&((data)<<0))
#define DC_PHY_WFIFO2_CNT_wfifo_wr_cnt_rl_src(data)                                  ((0x000000FF&(data))>>0)
#define DC_PHY_WFIFO2_CNT_get_wfifo_wr_cnt_rl(data)                                  ((0x000000FF&(data))>>0)


#define DC_PHY_WFIFO2_DDR_REQ_WAIT                                                   0x18008884
#define DC_PHY_WFIFO2_DDR_REQ_WAIT_reg_addr                                          "0xB8008884"
#define DC_PHY_WFIFO2_DDR_REQ_WAIT_reg                                               0xB8008884
#define set_DC_PHY_WFIFO2_DDR_REQ_WAIT_reg(data)   (*((volatile unsigned int*) DC_PHY_WFIFO2_DDR_REQ_WAIT_reg)=data)
#define get_DC_PHY_WFIFO2_DDR_REQ_WAIT_reg   (*((volatile unsigned int*) DC_PHY_WFIFO2_DDR_REQ_WAIT_reg))
#define DC_PHY_WFIFO2_DDR_REQ_WAIT_inst_adr                                          "0x0021"
#define DC_PHY_WFIFO2_DDR_REQ_WAIT_inst                                              0x0021
#define DC_PHY_WFIFO2_DDR_REQ_WAIT_wfifo_ddr_req_wait_total_shift                    (0)
#define DC_PHY_WFIFO2_DDR_REQ_WAIT_wfifo_ddr_req_wait_total_mask                     (0xFFFFFFFF)
#define DC_PHY_WFIFO2_DDR_REQ_WAIT_wfifo_ddr_req_wait_total(data)                    (0xFFFFFFFF&((data)<<0))
#define DC_PHY_WFIFO2_DDR_REQ_WAIT_wfifo_ddr_req_wait_total_src(data)                ((0xFFFFFFFF&(data))>>0)
#define DC_PHY_WFIFO2_DDR_REQ_WAIT_get_wfifo_ddr_req_wait_total(data)                ((0xFFFFFFFF&(data))>>0)


#define DC_PHY_WFIFO2_MAX_REQ_WAIT                                                   0x18008888
#define DC_PHY_WFIFO2_MAX_REQ_WAIT_reg_addr                                          "0xB8008888"
#define DC_PHY_WFIFO2_MAX_REQ_WAIT_reg                                               0xB8008888
#define set_DC_PHY_WFIFO2_MAX_REQ_WAIT_reg(data)   (*((volatile unsigned int*) DC_PHY_WFIFO2_MAX_REQ_WAIT_reg)=data)
#define get_DC_PHY_WFIFO2_MAX_REQ_WAIT_reg   (*((volatile unsigned int*) DC_PHY_WFIFO2_MAX_REQ_WAIT_reg))
#define DC_PHY_WFIFO2_MAX_REQ_WAIT_inst_adr                                          "0x0022"
#define DC_PHY_WFIFO2_MAX_REQ_WAIT_inst                                              0x0022
#define DC_PHY_WFIFO2_MAX_REQ_WAIT_wfifo_ddr_req_wait_max_shift                      (16)
#define DC_PHY_WFIFO2_MAX_REQ_WAIT_wfifo_ddr_req_wait_max_mask                       (0xFFFF0000)
#define DC_PHY_WFIFO2_MAX_REQ_WAIT_wfifo_ddr_req_wait_max(data)                      (0xFFFF0000&((data)<<16))
#define DC_PHY_WFIFO2_MAX_REQ_WAIT_wfifo_ddr_req_wait_max_src(data)                  ((0xFFFF0000&(data))>>16)
#define DC_PHY_WFIFO2_MAX_REQ_WAIT_get_wfifo_ddr_req_wait_max(data)                  ((0xFFFF0000&(data))>>16)


#define DC_PHY_DUMMY_REG                                                             0x18008940
#define DC_PHY_DUMMY_REG_reg_addr                                                    "0xB8008940"
#define DC_PHY_DUMMY_REG_reg                                                         0xB8008940
#define set_DC_PHY_DUMMY_REG_reg(data)   (*((volatile unsigned int*) DC_PHY_DUMMY_REG_reg)=data)
#define get_DC_PHY_DUMMY_REG_reg   (*((volatile unsigned int*) DC_PHY_DUMMY_REG_reg))
#define DC_PHY_DUMMY_REG_inst_adr                                                    "0x0050"
#define DC_PHY_DUMMY_REG_inst                                                        0x0050
#define DC_PHY_DUMMY_REG_dummy_reg_shift                                             (0)
#define DC_PHY_DUMMY_REG_dummy_reg_mask                                              (0xFFFFFFFF)
#define DC_PHY_DUMMY_REG_dummy_reg(data)                                             (0xFFFFFFFF&((data)<<0))
#define DC_PHY_DUMMY_REG_dummy_reg_src(data)                                         ((0xFFFFFFFF&(data))>>0)
#define DC_PHY_DUMMY_REG_get_dummy_reg(data)                                         ((0xFFFFFFFF&(data))>>0)


#define DC_PHY_CAL_MODE                                                              0x18008954
#define DC_PHY_CAL_MODE_reg_addr                                                     "0xB8008954"
#define DC_PHY_CAL_MODE_reg                                                          0xB8008954
#define set_DC_PHY_CAL_MODE_reg(data)   (*((volatile unsigned int*) DC_PHY_CAL_MODE_reg)=data)
#define get_DC_PHY_CAL_MODE_reg   (*((volatile unsigned int*) DC_PHY_CAL_MODE_reg))
#define DC_PHY_CAL_MODE_inst_adr                                                     "0x0055"
#define DC_PHY_CAL_MODE_inst                                                         0x0055
#define DC_PHY_CAL_MODE_dq_sel_shift                                                 (0)
#define DC_PHY_CAL_MODE_dq_sel_mask                                                  (0x00000001)
#define DC_PHY_CAL_MODE_dq_sel(data)                                                 (0x00000001&((data)<<0))
#define DC_PHY_CAL_MODE_dq_sel_src(data)                                             ((0x00000001&(data))>>0)
#define DC_PHY_CAL_MODE_get_dq_sel(data)                                             ((0x00000001&(data))>>0)


#define DC_PHY_ANA_DLL                                                               0x18008b20
#define DC_PHY_ANA_DLL_reg_addr                                                      "0xB8008B20"
#define DC_PHY_ANA_DLL_reg                                                           0xB8008B20
#define set_DC_PHY_ANA_DLL_reg(data)   (*((volatile unsigned int*) DC_PHY_ANA_DLL_reg)=data)
#define get_DC_PHY_ANA_DLL_reg   (*((volatile unsigned int*) DC_PHY_ANA_DLL_reg))
#define DC_PHY_ANA_DLL_inst_adr                                                      "0x00C8"
#define DC_PHY_ANA_DLL_inst                                                          0x00C8
#define DC_PHY_ANA_DLL_ana_dly_sel_shift                                             (31)
#define DC_PHY_ANA_DLL_ana_dly_sel_mask                                              (0x80000000)
#define DC_PHY_ANA_DLL_ana_dly_sel(data)                                             (0x80000000&((data)<<31))
#define DC_PHY_ANA_DLL_ana_dly_sel_src(data)                                         ((0x80000000&(data))>>31)
#define DC_PHY_ANA_DLL_get_ana_dly_sel(data)                                         ((0x80000000&(data))>>31)
#define DC_PHY_ANA_DLL_dll_en_test_shift                                             (27)
#define DC_PHY_ANA_DLL_dll_en_test_mask                                              (0x08000000)
#define DC_PHY_ANA_DLL_dll_en_test(data)                                             (0x08000000&((data)<<27))
#define DC_PHY_ANA_DLL_dll_en_test_src(data)                                         ((0x08000000&(data))>>27)
#define DC_PHY_ANA_DLL_get_dll_en_test(data)                                         ((0x08000000&(data))>>27)


#define DC_PHY_LPDDR_CTRL                                                            0x18008b24
#define DC_PHY_LPDDR_CTRL_reg_addr                                                   "0xB8008B24"
#define DC_PHY_LPDDR_CTRL_reg                                                        0xB8008B24
#define set_DC_PHY_LPDDR_CTRL_reg(data)   (*((volatile unsigned int*) DC_PHY_LPDDR_CTRL_reg)=data)
#define get_DC_PHY_LPDDR_CTRL_reg   (*((volatile unsigned int*) DC_PHY_LPDDR_CTRL_reg))
#define DC_PHY_LPDDR_CTRL_inst_adr                                                   "0x00C9"
#define DC_PHY_LPDDR_CTRL_inst                                                       0x00C9
#define DC_PHY_LPDDR_CTRL_write_en_2_shift                                           (5)
#define DC_PHY_LPDDR_CTRL_write_en_2_mask                                            (0x00000020)
#define DC_PHY_LPDDR_CTRL_write_en_2(data)                                           (0x00000020&((data)<<5))
#define DC_PHY_LPDDR_CTRL_write_en_2_src(data)                                       ((0x00000020&(data))>>5)
#define DC_PHY_LPDDR_CTRL_get_write_en_2(data)                                       ((0x00000020&(data))>>5)
#define DC_PHY_LPDDR_CTRL_lpddr_ck_en_shift                                          (4)
#define DC_PHY_LPDDR_CTRL_lpddr_ck_en_mask                                           (0x00000010)
#define DC_PHY_LPDDR_CTRL_lpddr_ck_en(data)                                          (0x00000010&((data)<<4))
#define DC_PHY_LPDDR_CTRL_lpddr_ck_en_src(data)                                      ((0x00000010&(data))>>4)
#define DC_PHY_LPDDR_CTRL_get_lpddr_ck_en(data)                                      ((0x00000010&(data))>>4)
#define DC_PHY_LPDDR_CTRL_write_en_1_shift                                           (3)
#define DC_PHY_LPDDR_CTRL_write_en_1_mask                                            (0x00000008)
#define DC_PHY_LPDDR_CTRL_write_en_1(data)                                           (0x00000008&((data)<<3))
#define DC_PHY_LPDDR_CTRL_write_en_1_src(data)                                       ((0x00000008&(data))>>3)
#define DC_PHY_LPDDR_CTRL_get_write_en_1(data)                                       ((0x00000008&(data))>>3)
#define DC_PHY_LPDDR_CTRL_mod_reg_read_shift                                         (2)
#define DC_PHY_LPDDR_CTRL_mod_reg_read_mask                                          (0x00000004)
#define DC_PHY_LPDDR_CTRL_mod_reg_read(data)                                         (0x00000004&((data)<<2))
#define DC_PHY_LPDDR_CTRL_mod_reg_read_src(data)                                     ((0x00000004&(data))>>2)
#define DC_PHY_LPDDR_CTRL_get_mod_reg_read(data)                                     ((0x00000004&(data))>>2)
#define DC_PHY_LPDDR_CTRL_write_en_0_shift                                           (1)
#define DC_PHY_LPDDR_CTRL_write_en_0_mask                                            (0x00000002)
#define DC_PHY_LPDDR_CTRL_write_en_0(data)                                           (0x00000002&((data)<<1))
#define DC_PHY_LPDDR_CTRL_write_en_0_src(data)                                       ((0x00000002&(data))>>1)
#define DC_PHY_LPDDR_CTRL_get_write_en_0(data)                                       ((0x00000002&(data))>>1)
#define DC_PHY_LPDDR_CTRL_mod_reg_write_shift                                        (0)
#define DC_PHY_LPDDR_CTRL_mod_reg_write_mask                                         (0x00000001)
#define DC_PHY_LPDDR_CTRL_mod_reg_write(data)                                        (0x00000001&((data)<<0))
#define DC_PHY_LPDDR_CTRL_mod_reg_write_src(data)                                    ((0x00000001&(data))>>0)
#define DC_PHY_LPDDR_CTRL_get_mod_reg_write(data)                                    ((0x00000001&(data))>>0)


#define DC_PHY_LPDDR_RDAT                                                            0x18008b28
#define DC_PHY_LPDDR_RDAT_reg_addr                                                   "0xB8008B28"
#define DC_PHY_LPDDR_RDAT_reg                                                        0xB8008B28
#define set_DC_PHY_LPDDR_RDAT_reg(data)   (*((volatile unsigned int*) DC_PHY_LPDDR_RDAT_reg)=data)
#define get_DC_PHY_LPDDR_RDAT_reg   (*((volatile unsigned int*) DC_PHY_LPDDR_RDAT_reg))
#define DC_PHY_LPDDR_RDAT_inst_adr                                                   "0x00CA"
#define DC_PHY_LPDDR_RDAT_inst                                                       0x00CA
#define DC_PHY_LPDDR_RDAT_mode_reg_rdata_shift                                       (24)
#define DC_PHY_LPDDR_RDAT_mode_reg_rdata_mask                                        (0xFF000000)
#define DC_PHY_LPDDR_RDAT_mode_reg_rdata(data)                                       (0xFF000000&((data)<<24))
#define DC_PHY_LPDDR_RDAT_mode_reg_rdata_src(data)                                   ((0xFF000000&(data))>>24)
#define DC_PHY_LPDDR_RDAT_get_mode_reg_rdata(data)                                   ((0xFF000000&(data))>>24)


#define DC_PHY_LPDDR_MODE                                                            0x18008b2c
#define DC_PHY_LPDDR_MODE_reg_addr                                                   "0xB8008B2C"
#define DC_PHY_LPDDR_MODE_reg                                                        0xB8008B2C
#define set_DC_PHY_LPDDR_MODE_reg(data)   (*((volatile unsigned int*) DC_PHY_LPDDR_MODE_reg)=data)
#define get_DC_PHY_LPDDR_MODE_reg   (*((volatile unsigned int*) DC_PHY_LPDDR_MODE_reg))
#define DC_PHY_LPDDR_MODE_inst_adr                                                   "0x00CB"
#define DC_PHY_LPDDR_MODE_inst                                                       0x00CB
#define DC_PHY_LPDDR_MODE_mode_reg_wdata_shift                                       (16)
#define DC_PHY_LPDDR_MODE_mode_reg_wdata_mask                                        (0x00FF0000)
#define DC_PHY_LPDDR_MODE_mode_reg_wdata(data)                                       (0x00FF0000&((data)<<16))
#define DC_PHY_LPDDR_MODE_mode_reg_wdata_src(data)                                   ((0x00FF0000&(data))>>16)
#define DC_PHY_LPDDR_MODE_get_mode_reg_wdata(data)                                   ((0x00FF0000&(data))>>16)
#define DC_PHY_LPDDR_MODE_mode_reg_addr_shift                                        (8)
#define DC_PHY_LPDDR_MODE_mode_reg_addr_mask                                         (0x0000FF00)
#define DC_PHY_LPDDR_MODE_mode_reg_addr(data)                                        (0x0000FF00&((data)<<8))
#define DC_PHY_LPDDR_MODE_mode_reg_addr_src(data)                                    ((0x0000FF00&(data))>>8)
#define DC_PHY_LPDDR_MODE_get_mode_reg_addr(data)                                    ((0x0000FF00&(data))>>8)
#define DC_PHY_LPDDR_MODE_lpddr_shift                                                (6)
#define DC_PHY_LPDDR_MODE_lpddr_mask                                                 (0x00000040)
#define DC_PHY_LPDDR_MODE_lpddr(data)                                                (0x00000040&((data)<<6))
#define DC_PHY_LPDDR_MODE_lpddr_src(data)                                            ((0x00000040&(data))>>6)
#define DC_PHY_LPDDR_MODE_get_lpddr(data)                                            ((0x00000040&(data))>>6)


#define DC_PHY_FIFO_ARB_0                                                            0x18008e00
#define DC_PHY_FIFO_ARB_0_reg_addr                                                   "0xB8008E00"
#define DC_PHY_FIFO_ARB_0_reg                                                        0xB8008E00
#define set_DC_PHY_FIFO_ARB_0_reg(data)   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_0_reg)=data)
#define get_DC_PHY_FIFO_ARB_0_reg   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_0_reg))
#define DC_PHY_FIFO_ARB_0_inst_adr                                                   "0x0080"
#define DC_PHY_FIFO_ARB_0_inst                                                       0x0080
#define DC_PHY_FIFO_ARB_0_mem_num_sel_shift                                          (25)
#define DC_PHY_FIFO_ARB_0_mem_num_sel_mask                                           (0x02000000)
#define DC_PHY_FIFO_ARB_0_mem_num_sel(data)                                          (0x02000000&((data)<<25))
#define DC_PHY_FIFO_ARB_0_mem_num_sel_src(data)                                      ((0x02000000&(data))>>25)
#define DC_PHY_FIFO_ARB_0_get_mem_num_sel(data)                                      ((0x02000000&(data))>>25)
#define DC_PHY_FIFO_ARB_0_fifo_arb_sel_shift                                         (24)
#define DC_PHY_FIFO_ARB_0_fifo_arb_sel_mask                                          (0x01000000)
#define DC_PHY_FIFO_ARB_0_fifo_arb_sel(data)                                         (0x01000000&((data)<<24))
#define DC_PHY_FIFO_ARB_0_fifo_arb_sel_src(data)                                     ((0x01000000&(data))>>24)
#define DC_PHY_FIFO_ARB_0_get_fifo_arb_sel(data)                                     ((0x01000000&(data))>>24)
#define DC_PHY_FIFO_ARB_0_cmdq_ch_fifo_cnt_shift                                     (20)
#define DC_PHY_FIFO_ARB_0_cmdq_ch_fifo_cnt_mask                                      (0x00700000)
#define DC_PHY_FIFO_ARB_0_cmdq_ch_fifo_cnt(data)                                     (0x00700000&((data)<<20))
#define DC_PHY_FIFO_ARB_0_cmdq_ch_fifo_cnt_src(data)                                 ((0x00700000&(data))>>20)
#define DC_PHY_FIFO_ARB_0_get_cmdq_ch_fifo_cnt(data)                                 ((0x00700000&(data))>>20)
#define DC_PHY_FIFO_ARB_0_cmdq_ch_fifo_rd_ptr_shift                                  (16)
#define DC_PHY_FIFO_ARB_0_cmdq_ch_fifo_rd_ptr_mask                                   (0x00030000)
#define DC_PHY_FIFO_ARB_0_cmdq_ch_fifo_rd_ptr(data)                                  (0x00030000&((data)<<16))
#define DC_PHY_FIFO_ARB_0_cmdq_ch_fifo_rd_ptr_src(data)                              ((0x00030000&(data))>>16)
#define DC_PHY_FIFO_ARB_0_get_cmdq_ch_fifo_rd_ptr(data)                              ((0x00030000&(data))>>16)
#define DC_PHY_FIFO_ARB_0_cmdq_ch_fifo_wr_ptr_shift                                  (12)
#define DC_PHY_FIFO_ARB_0_cmdq_ch_fifo_wr_ptr_mask                                   (0x00003000)
#define DC_PHY_FIFO_ARB_0_cmdq_ch_fifo_wr_ptr(data)                                  (0x00003000&((data)<<12))
#define DC_PHY_FIFO_ARB_0_cmdq_ch_fifo_wr_ptr_src(data)                              ((0x00003000&(data))>>12)
#define DC_PHY_FIFO_ARB_0_get_cmdq_ch_fifo_wr_ptr(data)                              ((0x00003000&(data))>>12)
#define DC_PHY_FIFO_ARB_0_cmdq_ch_fifo_overflow_shift                                (11)
#define DC_PHY_FIFO_ARB_0_cmdq_ch_fifo_overflow_mask                                 (0x00000800)
#define DC_PHY_FIFO_ARB_0_cmdq_ch_fifo_overflow(data)                                (0x00000800&((data)<<11))
#define DC_PHY_FIFO_ARB_0_cmdq_ch_fifo_overflow_src(data)                            ((0x00000800&(data))>>11)
#define DC_PHY_FIFO_ARB_0_get_cmdq_ch_fifo_overflow(data)                            ((0x00000800&(data))>>11)
#define DC_PHY_FIFO_ARB_0_cmdq_ch_fifo_underflow_shift                               (10)
#define DC_PHY_FIFO_ARB_0_cmdq_ch_fifo_underflow_mask                                (0x00000400)
#define DC_PHY_FIFO_ARB_0_cmdq_ch_fifo_underflow(data)                               (0x00000400&((data)<<10))
#define DC_PHY_FIFO_ARB_0_cmdq_ch_fifo_underflow_src(data)                           ((0x00000400&(data))>>10)
#define DC_PHY_FIFO_ARB_0_get_cmdq_ch_fifo_underflow(data)                           ((0x00000400&(data))>>10)
#define DC_PHY_FIFO_ARB_0_cmdq_ch_fifo_full_shift                                    (9)
#define DC_PHY_FIFO_ARB_0_cmdq_ch_fifo_full_mask                                     (0x00000200)
#define DC_PHY_FIFO_ARB_0_cmdq_ch_fifo_full(data)                                    (0x00000200&((data)<<9))
#define DC_PHY_FIFO_ARB_0_cmdq_ch_fifo_full_src(data)                                ((0x00000200&(data))>>9)
#define DC_PHY_FIFO_ARB_0_get_cmdq_ch_fifo_full(data)                                ((0x00000200&(data))>>9)
#define DC_PHY_FIFO_ARB_0_cmdq_ch_fifo_empty_shift                                   (8)
#define DC_PHY_FIFO_ARB_0_cmdq_ch_fifo_empty_mask                                    (0x00000100)
#define DC_PHY_FIFO_ARB_0_cmdq_ch_fifo_empty(data)                                   (0x00000100&((data)<<8))
#define DC_PHY_FIFO_ARB_0_cmdq_ch_fifo_empty_src(data)                               ((0x00000100&(data))>>8)
#define DC_PHY_FIFO_ARB_0_get_cmdq_ch_fifo_empty(data)                               ((0x00000100&(data))>>8)
#define DC_PHY_FIFO_ARB_0_cmdq_ch_fifo_thr_shift                                     (4)
#define DC_PHY_FIFO_ARB_0_cmdq_ch_fifo_thr_mask                                      (0x000000F0)
#define DC_PHY_FIFO_ARB_0_cmdq_ch_fifo_thr(data)                                     (0x000000F0&((data)<<4))
#define DC_PHY_FIFO_ARB_0_cmdq_ch_fifo_thr_src(data)                                 ((0x000000F0&(data))>>4)
#define DC_PHY_FIFO_ARB_0_get_cmdq_ch_fifo_thr(data)                                 ((0x000000F0&(data))>>4)
#define DC_PHY_FIFO_ARB_0_cmdq_ch_fifo_overflow_clr_shift                            (3)
#define DC_PHY_FIFO_ARB_0_cmdq_ch_fifo_overflow_clr_mask                             (0x00000008)
#define DC_PHY_FIFO_ARB_0_cmdq_ch_fifo_overflow_clr(data)                            (0x00000008&((data)<<3))
#define DC_PHY_FIFO_ARB_0_cmdq_ch_fifo_overflow_clr_src(data)                        ((0x00000008&(data))>>3)
#define DC_PHY_FIFO_ARB_0_get_cmdq_ch_fifo_overflow_clr(data)                        ((0x00000008&(data))>>3)
#define DC_PHY_FIFO_ARB_0_cmdq_ch_fifo_underflow_clr_shift                           (2)
#define DC_PHY_FIFO_ARB_0_cmdq_ch_fifo_underflow_clr_mask                            (0x00000004)
#define DC_PHY_FIFO_ARB_0_cmdq_ch_fifo_underflow_clr(data)                           (0x00000004&((data)<<2))
#define DC_PHY_FIFO_ARB_0_cmdq_ch_fifo_underflow_clr_src(data)                       ((0x00000004&(data))>>2)
#define DC_PHY_FIFO_ARB_0_get_cmdq_ch_fifo_underflow_clr(data)                       ((0x00000004&(data))>>2)
#define DC_PHY_FIFO_ARB_0_cmdq_ch_clk_gated_en_shift                                 (1)
#define DC_PHY_FIFO_ARB_0_cmdq_ch_clk_gated_en_mask                                  (0x00000002)
#define DC_PHY_FIFO_ARB_0_cmdq_ch_clk_gated_en(data)                                 (0x00000002&((data)<<1))
#define DC_PHY_FIFO_ARB_0_cmdq_ch_clk_gated_en_src(data)                             ((0x00000002&(data))>>1)
#define DC_PHY_FIFO_ARB_0_get_cmdq_ch_clk_gated_en(data)                             ((0x00000002&(data))>>1)
#define DC_PHY_FIFO_ARB_0_fifo_arb_dis_shift                                         (0)
#define DC_PHY_FIFO_ARB_0_fifo_arb_dis_mask                                          (0x00000001)
#define DC_PHY_FIFO_ARB_0_fifo_arb_dis(data)                                         (0x00000001&((data)<<0))
#define DC_PHY_FIFO_ARB_0_fifo_arb_dis_src(data)                                     ((0x00000001&(data))>>0)
#define DC_PHY_FIFO_ARB_0_get_fifo_arb_dis(data)                                     ((0x00000001&(data))>>0)


#define DC_PHY_FIFO_ARB_1                                                            0x18008e04
#define DC_PHY_FIFO_ARB_1_reg_addr                                                   "0xB8008E04"
#define DC_PHY_FIFO_ARB_1_reg                                                        0xB8008E04
#define set_DC_PHY_FIFO_ARB_1_reg(data)   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_1_reg)=data)
#define get_DC_PHY_FIFO_ARB_1_reg   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_1_reg))
#define DC_PHY_FIFO_ARB_1_inst_adr                                                   "0x0081"
#define DC_PHY_FIFO_ARB_1_inst                                                       0x0081
#define DC_PHY_FIFO_ARB_1_cmdq_ch_gnt_mst1_cmd_dis_shift                             (5)
#define DC_PHY_FIFO_ARB_1_cmdq_ch_gnt_mst1_cmd_dis_mask                              (0x00000020)
#define DC_PHY_FIFO_ARB_1_cmdq_ch_gnt_mst1_cmd_dis(data)                             (0x00000020&((data)<<5))
#define DC_PHY_FIFO_ARB_1_cmdq_ch_gnt_mst1_cmd_dis_src(data)                         ((0x00000020&(data))>>5)
#define DC_PHY_FIFO_ARB_1_get_cmdq_ch_gnt_mst1_cmd_dis(data)                         ((0x00000020&(data))>>5)
#define DC_PHY_FIFO_ARB_1_cmdq_ch_gnt_mst1_cti_dis_shift                             (4)
#define DC_PHY_FIFO_ARB_1_cmdq_ch_gnt_mst1_cti_dis_mask                              (0x00000010)
#define DC_PHY_FIFO_ARB_1_cmdq_ch_gnt_mst1_cti_dis(data)                             (0x00000010&((data)<<4))
#define DC_PHY_FIFO_ARB_1_cmdq_ch_gnt_mst1_cti_dis_src(data)                         ((0x00000010&(data))>>4)
#define DC_PHY_FIFO_ARB_1_get_cmdq_ch_gnt_mst1_cti_dis(data)                         ((0x00000010&(data))>>4)
#define DC_PHY_FIFO_ARB_1_cmdq_ch_gnt_mst0_cmd_dis_shift                             (1)
#define DC_PHY_FIFO_ARB_1_cmdq_ch_gnt_mst0_cmd_dis_mask                              (0x00000002)
#define DC_PHY_FIFO_ARB_1_cmdq_ch_gnt_mst0_cmd_dis(data)                             (0x00000002&((data)<<1))
#define DC_PHY_FIFO_ARB_1_cmdq_ch_gnt_mst0_cmd_dis_src(data)                         ((0x00000002&(data))>>1)
#define DC_PHY_FIFO_ARB_1_get_cmdq_ch_gnt_mst0_cmd_dis(data)                         ((0x00000002&(data))>>1)
#define DC_PHY_FIFO_ARB_1_cmdq_ch_gnt_mst0_cti_dis_shift                             (0)
#define DC_PHY_FIFO_ARB_1_cmdq_ch_gnt_mst0_cti_dis_mask                              (0x00000001)
#define DC_PHY_FIFO_ARB_1_cmdq_ch_gnt_mst0_cti_dis(data)                             (0x00000001&((data)<<0))
#define DC_PHY_FIFO_ARB_1_cmdq_ch_gnt_mst0_cti_dis_src(data)                         ((0x00000001&(data))>>0)
#define DC_PHY_FIFO_ARB_1_get_cmdq_ch_gnt_mst0_cti_dis(data)                         ((0x00000001&(data))>>0)


#define DC_PHY_FIFO_ARB_2                                                            0x18008e08
#define DC_PHY_FIFO_ARB_2_reg_addr                                                   "0xB8008E08"
#define DC_PHY_FIFO_ARB_2_reg                                                        0xB8008E08
#define set_DC_PHY_FIFO_ARB_2_reg(data)   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_2_reg)=data)
#define get_DC_PHY_FIFO_ARB_2_reg   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_2_reg))
#define DC_PHY_FIFO_ARB_2_inst_adr                                                   "0x0082"
#define DC_PHY_FIFO_ARB_2_inst                                                       0x0082
#define DC_PHY_FIFO_ARB_2_cmdq_ch_dbg_mod_shift                                      (0)
#define DC_PHY_FIFO_ARB_2_cmdq_ch_dbg_mod_mask                                       (0x000000FF)
#define DC_PHY_FIFO_ARB_2_cmdq_ch_dbg_mod(data)                                      (0x000000FF&((data)<<0))
#define DC_PHY_FIFO_ARB_2_cmdq_ch_dbg_mod_src(data)                                  ((0x000000FF&(data))>>0)
#define DC_PHY_FIFO_ARB_2_get_cmdq_ch_dbg_mod(data)                                  ((0x000000FF&(data))>>0)


#define DC_PHY_FIFO_ARB_3                                                            0x18008e0c
#define DC_PHY_FIFO_ARB_3_reg_addr                                                   "0xB8008E0C"
#define DC_PHY_FIFO_ARB_3_reg                                                        0xB8008E0C
#define set_DC_PHY_FIFO_ARB_3_reg(data)   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_3_reg)=data)
#define get_DC_PHY_FIFO_ARB_3_reg   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_3_reg))
#define DC_PHY_FIFO_ARB_3_inst_adr                                                   "0x0083"
#define DC_PHY_FIFO_ARB_3_inst                                                       0x0083
#define DC_PHY_FIFO_ARB_3_cmdq_ch_dummy_0_shift                                      (0)
#define DC_PHY_FIFO_ARB_3_cmdq_ch_dummy_0_mask                                       (0xFFFFFFFF)
#define DC_PHY_FIFO_ARB_3_cmdq_ch_dummy_0(data)                                      (0xFFFFFFFF&((data)<<0))
#define DC_PHY_FIFO_ARB_3_cmdq_ch_dummy_0_src(data)                                  ((0xFFFFFFFF&(data))>>0)
#define DC_PHY_FIFO_ARB_3_get_cmdq_ch_dummy_0(data)                                  ((0xFFFFFFFF&(data))>>0)


#define DC_PHY_FIFO_ARB_4                                                            0x18008e10
#define DC_PHY_FIFO_ARB_4_reg_addr                                                   "0xB8008E10"
#define DC_PHY_FIFO_ARB_4_reg                                                        0xB8008E10
#define set_DC_PHY_FIFO_ARB_4_reg(data)   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_4_reg)=data)
#define get_DC_PHY_FIFO_ARB_4_reg   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_4_reg))
#define DC_PHY_FIFO_ARB_4_inst_adr                                                   "0x0084"
#define DC_PHY_FIFO_ARB_4_inst                                                       0x0084
#define DC_PHY_FIFO_ARB_4_cmdq_ch_gnt_st0_shift                                      (0)
#define DC_PHY_FIFO_ARB_4_cmdq_ch_gnt_st0_mask                                       (0xFFFFFFFF)
#define DC_PHY_FIFO_ARB_4_cmdq_ch_gnt_st0(data)                                      (0xFFFFFFFF&((data)<<0))
#define DC_PHY_FIFO_ARB_4_cmdq_ch_gnt_st0_src(data)                                  ((0xFFFFFFFF&(data))>>0)
#define DC_PHY_FIFO_ARB_4_get_cmdq_ch_gnt_st0(data)                                  ((0xFFFFFFFF&(data))>>0)


#define DC_PHY_FIFO_ARB_5                                                            0x18008e14
#define DC_PHY_FIFO_ARB_5_reg_addr                                                   "0xB8008E14"
#define DC_PHY_FIFO_ARB_5_reg                                                        0xB8008E14
#define set_DC_PHY_FIFO_ARB_5_reg(data)   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_5_reg)=data)
#define get_DC_PHY_FIFO_ARB_5_reg   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_5_reg))
#define DC_PHY_FIFO_ARB_5_inst_adr                                                   "0x0085"
#define DC_PHY_FIFO_ARB_5_inst                                                       0x0085
#define DC_PHY_FIFO_ARB_5_cmdq_ch_gnt_st1_shift                                      (0)
#define DC_PHY_FIFO_ARB_5_cmdq_ch_gnt_st1_mask                                       (0xFFFFFFFF)
#define DC_PHY_FIFO_ARB_5_cmdq_ch_gnt_st1(data)                                      (0xFFFFFFFF&((data)<<0))
#define DC_PHY_FIFO_ARB_5_cmdq_ch_gnt_st1_src(data)                                  ((0xFFFFFFFF&(data))>>0)
#define DC_PHY_FIFO_ARB_5_get_cmdq_ch_gnt_st1(data)                                  ((0xFFFFFFFF&(data))>>0)


#define DC_PHY_FIFO_ARB_6                                                            0x18008e18
#define DC_PHY_FIFO_ARB_6_reg_addr                                                   "0xB8008E18"
#define DC_PHY_FIFO_ARB_6_reg                                                        0xB8008E18
#define set_DC_PHY_FIFO_ARB_6_reg(data)   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_6_reg)=data)
#define get_DC_PHY_FIFO_ARB_6_reg   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_6_reg))
#define DC_PHY_FIFO_ARB_6_inst_adr                                                   "0x0086"
#define DC_PHY_FIFO_ARB_6_inst                                                       0x0086
#define DC_PHY_FIFO_ARB_6_cmdq_ch_gnt_st2_shift                                      (0)
#define DC_PHY_FIFO_ARB_6_cmdq_ch_gnt_st2_mask                                       (0xFFFFFFFF)
#define DC_PHY_FIFO_ARB_6_cmdq_ch_gnt_st2(data)                                      (0xFFFFFFFF&((data)<<0))
#define DC_PHY_FIFO_ARB_6_cmdq_ch_gnt_st2_src(data)                                  ((0xFFFFFFFF&(data))>>0)
#define DC_PHY_FIFO_ARB_6_get_cmdq_ch_gnt_st2(data)                                  ((0xFFFFFFFF&(data))>>0)


#define DC_PHY_FIFO_ARB_7                                                            0x18008e1c
#define DC_PHY_FIFO_ARB_7_reg_addr                                                   "0xB8008E1C"
#define DC_PHY_FIFO_ARB_7_reg                                                        0xB8008E1C
#define set_DC_PHY_FIFO_ARB_7_reg(data)   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_7_reg)=data)
#define get_DC_PHY_FIFO_ARB_7_reg   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_7_reg))
#define DC_PHY_FIFO_ARB_7_inst_adr                                                   "0x0087"
#define DC_PHY_FIFO_ARB_7_inst                                                       0x0087
#define DC_PHY_FIFO_ARB_7_cmdq_ch_gnt_st3_shift                                      (0)
#define DC_PHY_FIFO_ARB_7_cmdq_ch_gnt_st3_mask                                       (0xFFFFFFFF)
#define DC_PHY_FIFO_ARB_7_cmdq_ch_gnt_st3(data)                                      (0xFFFFFFFF&((data)<<0))
#define DC_PHY_FIFO_ARB_7_cmdq_ch_gnt_st3_src(data)                                  ((0xFFFFFFFF&(data))>>0)
#define DC_PHY_FIFO_ARB_7_get_cmdq_ch_gnt_st3(data)                                  ((0xFFFFFFFF&(data))>>0)


#define DC_PHY_FIFO_ARB_8                                                            0x18008e20
#define DC_PHY_FIFO_ARB_8_reg_addr                                                   "0xB8008E20"
#define DC_PHY_FIFO_ARB_8_reg                                                        0xB8008E20
#define set_DC_PHY_FIFO_ARB_8_reg(data)   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_8_reg)=data)
#define get_DC_PHY_FIFO_ARB_8_reg   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_8_reg))
#define DC_PHY_FIFO_ARB_8_inst_adr                                                   "0x0088"
#define DC_PHY_FIFO_ARB_8_inst                                                       0x0088
#define DC_PHY_FIFO_ARB_8_cmdq_ch_gnt_st4_shift                                      (0)
#define DC_PHY_FIFO_ARB_8_cmdq_ch_gnt_st4_mask                                       (0xFFFFFFFF)
#define DC_PHY_FIFO_ARB_8_cmdq_ch_gnt_st4(data)                                      (0xFFFFFFFF&((data)<<0))
#define DC_PHY_FIFO_ARB_8_cmdq_ch_gnt_st4_src(data)                                  ((0xFFFFFFFF&(data))>>0)
#define DC_PHY_FIFO_ARB_8_get_cmdq_ch_gnt_st4(data)                                  ((0xFFFFFFFF&(data))>>0)


#define DC_PHY_FIFO_ARB_9                                                            0x18008e24
#define DC_PHY_FIFO_ARB_9_reg_addr                                                   "0xB8008E24"
#define DC_PHY_FIFO_ARB_9_reg                                                        0xB8008E24
#define set_DC_PHY_FIFO_ARB_9_reg(data)   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_9_reg)=data)
#define get_DC_PHY_FIFO_ARB_9_reg   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_9_reg))
#define DC_PHY_FIFO_ARB_9_inst_adr                                                   "0x0089"
#define DC_PHY_FIFO_ARB_9_inst                                                       0x0089
#define DC_PHY_FIFO_ARB_9_cmdq_ch_gnt_st5_shift                                      (0)
#define DC_PHY_FIFO_ARB_9_cmdq_ch_gnt_st5_mask                                       (0xFFFFFFFF)
#define DC_PHY_FIFO_ARB_9_cmdq_ch_gnt_st5(data)                                      (0xFFFFFFFF&((data)<<0))
#define DC_PHY_FIFO_ARB_9_cmdq_ch_gnt_st5_src(data)                                  ((0xFFFFFFFF&(data))>>0)
#define DC_PHY_FIFO_ARB_9_get_cmdq_ch_gnt_st5(data)                                  ((0xFFFFFFFF&(data))>>0)


#define DC_PHY_FIFO_ARB_10                                                           0x18008e28
#define DC_PHY_FIFO_ARB_10_reg_addr                                                  "0xB8008E28"
#define DC_PHY_FIFO_ARB_10_reg                                                       0xB8008E28
#define set_DC_PHY_FIFO_ARB_10_reg(data)   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_10_reg)=data)
#define get_DC_PHY_FIFO_ARB_10_reg   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_10_reg))
#define DC_PHY_FIFO_ARB_10_inst_adr                                                  "0x008A"
#define DC_PHY_FIFO_ARB_10_inst                                                      0x008A
#define DC_PHY_FIFO_ARB_10_cmdq_ch_gnt_st6_shift                                     (0)
#define DC_PHY_FIFO_ARB_10_cmdq_ch_gnt_st6_mask                                      (0xFFFFFFFF)
#define DC_PHY_FIFO_ARB_10_cmdq_ch_gnt_st6(data)                                     (0xFFFFFFFF&((data)<<0))
#define DC_PHY_FIFO_ARB_10_cmdq_ch_gnt_st6_src(data)                                 ((0xFFFFFFFF&(data))>>0)
#define DC_PHY_FIFO_ARB_10_get_cmdq_ch_gnt_st6(data)                                 ((0xFFFFFFFF&(data))>>0)


#define DC_PHY_FIFO_ARB_11                                                           0x18008e2c
#define DC_PHY_FIFO_ARB_11_reg_addr                                                  "0xB8008E2C"
#define DC_PHY_FIFO_ARB_11_reg                                                       0xB8008E2C
#define set_DC_PHY_FIFO_ARB_11_reg(data)   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_11_reg)=data)
#define get_DC_PHY_FIFO_ARB_11_reg   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_11_reg))
#define DC_PHY_FIFO_ARB_11_inst_adr                                                  "0x008B"
#define DC_PHY_FIFO_ARB_11_inst                                                      0x008B
#define DC_PHY_FIFO_ARB_11_cmdq_ch_gnt_st7_shift                                     (0)
#define DC_PHY_FIFO_ARB_11_cmdq_ch_gnt_st7_mask                                      (0xFFFFFFFF)
#define DC_PHY_FIFO_ARB_11_cmdq_ch_gnt_st7(data)                                     (0xFFFFFFFF&((data)<<0))
#define DC_PHY_FIFO_ARB_11_cmdq_ch_gnt_st7_src(data)                                 ((0xFFFFFFFF&(data))>>0)
#define DC_PHY_FIFO_ARB_11_get_cmdq_ch_gnt_st7(data)                                 ((0xFFFFFFFF&(data))>>0)


#define DC_PHY_FIFO_ARB_13                                                           0x18008e34
#define DC_PHY_FIFO_ARB_13_reg_addr                                                  "0xB8008E34"
#define DC_PHY_FIFO_ARB_13_reg                                                       0xB8008E34
#define set_DC_PHY_FIFO_ARB_13_reg(data)   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_13_reg)=data)
#define get_DC_PHY_FIFO_ARB_13_reg   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_13_reg))
#define DC_PHY_FIFO_ARB_13_inst_adr                                                  "0x008D"
#define DC_PHY_FIFO_ARB_13_inst                                                      0x008D
#define DC_PHY_FIFO_ARB_13_wq_ch_dbg_mod_shift                                       (8)
#define DC_PHY_FIFO_ARB_13_wq_ch_dbg_mod_mask                                        (0x0000FF00)
#define DC_PHY_FIFO_ARB_13_wq_ch_dbg_mod(data)                                       (0x0000FF00&((data)<<8))
#define DC_PHY_FIFO_ARB_13_wq_ch_dbg_mod_src(data)                                   ((0x0000FF00&(data))>>8)
#define DC_PHY_FIFO_ARB_13_get_wq_ch_dbg_mod(data)                                   ((0x0000FF00&(data))>>8)


#define DC_PHY_FIFO_ARB_16                                                           0x18008e40
#define DC_PHY_FIFO_ARB_16_reg_addr                                                  "0xB8008E40"
#define DC_PHY_FIFO_ARB_16_reg                                                       0xB8008E40
#define set_DC_PHY_FIFO_ARB_16_reg(data)   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_16_reg)=data)
#define get_DC_PHY_FIFO_ARB_16_reg   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_16_reg))
#define DC_PHY_FIFO_ARB_16_inst_adr                                                  "0x0090"
#define DC_PHY_FIFO_ARB_16_inst                                                      0x0090
#define DC_PHY_FIFO_ARB_16_wq_ch_dummy_0_shift                                       (0)
#define DC_PHY_FIFO_ARB_16_wq_ch_dummy_0_mask                                        (0xFFFFFFFF)
#define DC_PHY_FIFO_ARB_16_wq_ch_dummy_0(data)                                       (0xFFFFFFFF&((data)<<0))
#define DC_PHY_FIFO_ARB_16_wq_ch_dummy_0_src(data)                                   ((0xFFFFFFFF&(data))>>0)
#define DC_PHY_FIFO_ARB_16_get_wq_ch_dummy_0(data)                                   ((0xFFFFFFFF&(data))>>0)


#define DC_PHY_FIFO_ARB_17                                                           0x18008e44
#define DC_PHY_FIFO_ARB_17_reg_addr                                                  "0xB8008E44"
#define DC_PHY_FIFO_ARB_17_reg                                                       0xB8008E44
#define set_DC_PHY_FIFO_ARB_17_reg(data)   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_17_reg)=data)
#define get_DC_PHY_FIFO_ARB_17_reg   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_17_reg))
#define DC_PHY_FIFO_ARB_17_inst_adr                                                  "0x0091"
#define DC_PHY_FIFO_ARB_17_inst                                                      0x0091
#define DC_PHY_FIFO_ARB_17_wq_ch_st0_shift                                           (0)
#define DC_PHY_FIFO_ARB_17_wq_ch_st0_mask                                            (0xFFFFFFFF)
#define DC_PHY_FIFO_ARB_17_wq_ch_st0(data)                                           (0xFFFFFFFF&((data)<<0))
#define DC_PHY_FIFO_ARB_17_wq_ch_st0_src(data)                                       ((0xFFFFFFFF&(data))>>0)
#define DC_PHY_FIFO_ARB_17_get_wq_ch_st0(data)                                       ((0xFFFFFFFF&(data))>>0)


#define DC_PHY_FIFO_ARB_18                                                           0x18008e48
#define DC_PHY_FIFO_ARB_18_reg_addr                                                  "0xB8008E48"
#define DC_PHY_FIFO_ARB_18_reg                                                       0xB8008E48
#define set_DC_PHY_FIFO_ARB_18_reg(data)   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_18_reg)=data)
#define get_DC_PHY_FIFO_ARB_18_reg   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_18_reg))
#define DC_PHY_FIFO_ARB_18_inst_adr                                                  "0x0092"
#define DC_PHY_FIFO_ARB_18_inst                                                      0x0092
#define DC_PHY_FIFO_ARB_18_wq_ch_st1_shift                                           (0)
#define DC_PHY_FIFO_ARB_18_wq_ch_st1_mask                                            (0xFFFFFFFF)
#define DC_PHY_FIFO_ARB_18_wq_ch_st1(data)                                           (0xFFFFFFFF&((data)<<0))
#define DC_PHY_FIFO_ARB_18_wq_ch_st1_src(data)                                       ((0xFFFFFFFF&(data))>>0)
#define DC_PHY_FIFO_ARB_18_get_wq_ch_st1(data)                                       ((0xFFFFFFFF&(data))>>0)


#define DC_PHY_FIFO_ARB_19                                                           0x18008e4c
#define DC_PHY_FIFO_ARB_19_reg_addr                                                  "0xB8008E4C"
#define DC_PHY_FIFO_ARB_19_reg                                                       0xB8008E4C
#define set_DC_PHY_FIFO_ARB_19_reg(data)   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_19_reg)=data)
#define get_DC_PHY_FIFO_ARB_19_reg   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_19_reg))
#define DC_PHY_FIFO_ARB_19_inst_adr                                                  "0x0093"
#define DC_PHY_FIFO_ARB_19_inst                                                      0x0093
#define DC_PHY_FIFO_ARB_19_wq_ch_st2_shift                                           (0)
#define DC_PHY_FIFO_ARB_19_wq_ch_st2_mask                                            (0xFFFFFFFF)
#define DC_PHY_FIFO_ARB_19_wq_ch_st2(data)                                           (0xFFFFFFFF&((data)<<0))
#define DC_PHY_FIFO_ARB_19_wq_ch_st2_src(data)                                       ((0xFFFFFFFF&(data))>>0)
#define DC_PHY_FIFO_ARB_19_get_wq_ch_st2(data)                                       ((0xFFFFFFFF&(data))>>0)


#define DC_PHY_FIFO_ARB_20                                                           0x18008e50
#define DC_PHY_FIFO_ARB_20_reg_addr                                                  "0xB8008E50"
#define DC_PHY_FIFO_ARB_20_reg                                                       0xB8008E50
#define set_DC_PHY_FIFO_ARB_20_reg(data)   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_20_reg)=data)
#define get_DC_PHY_FIFO_ARB_20_reg   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_20_reg))
#define DC_PHY_FIFO_ARB_20_inst_adr                                                  "0x0094"
#define DC_PHY_FIFO_ARB_20_inst                                                      0x0094
#define DC_PHY_FIFO_ARB_20_wq_ch_st3_shift                                           (0)
#define DC_PHY_FIFO_ARB_20_wq_ch_st3_mask                                            (0xFFFFFFFF)
#define DC_PHY_FIFO_ARB_20_wq_ch_st3(data)                                           (0xFFFFFFFF&((data)<<0))
#define DC_PHY_FIFO_ARB_20_wq_ch_st3_src(data)                                       ((0xFFFFFFFF&(data))>>0)
#define DC_PHY_FIFO_ARB_20_get_wq_ch_st3(data)                                       ((0xFFFFFFFF&(data))>>0)


#define DC_PHY_FIFO_ARB_21                                                           0x18008e54
#define DC_PHY_FIFO_ARB_21_reg_addr                                                  "0xB8008E54"
#define DC_PHY_FIFO_ARB_21_reg                                                       0xB8008E54
#define set_DC_PHY_FIFO_ARB_21_reg(data)   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_21_reg)=data)
#define get_DC_PHY_FIFO_ARB_21_reg   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_21_reg))
#define DC_PHY_FIFO_ARB_21_inst_adr                                                  "0x0095"
#define DC_PHY_FIFO_ARB_21_inst                                                      0x0095
#define DC_PHY_FIFO_ARB_21_rq_ch_fifo_rd_ptr_shift                                   (24)
#define DC_PHY_FIFO_ARB_21_rq_ch_fifo_rd_ptr_mask                                    (0x7F000000)
#define DC_PHY_FIFO_ARB_21_rq_ch_fifo_rd_ptr(data)                                   (0x7F000000&((data)<<24))
#define DC_PHY_FIFO_ARB_21_rq_ch_fifo_rd_ptr_src(data)                               ((0x7F000000&(data))>>24)
#define DC_PHY_FIFO_ARB_21_get_rq_ch_fifo_rd_ptr(data)                               ((0x7F000000&(data))>>24)
#define DC_PHY_FIFO_ARB_21_rq_ch_fifo_wr_ptr_shift                                   (16)
#define DC_PHY_FIFO_ARB_21_rq_ch_fifo_wr_ptr_mask                                    (0x007F0000)
#define DC_PHY_FIFO_ARB_21_rq_ch_fifo_wr_ptr(data)                                   (0x007F0000&((data)<<16))
#define DC_PHY_FIFO_ARB_21_rq_ch_fifo_wr_ptr_src(data)                               ((0x007F0000&(data))>>16)
#define DC_PHY_FIFO_ARB_21_get_rq_ch_fifo_wr_ptr(data)                               ((0x007F0000&(data))>>16)
#define DC_PHY_FIFO_ARB_21_rq_ch_fifo_overflow_shift                                 (15)
#define DC_PHY_FIFO_ARB_21_rq_ch_fifo_overflow_mask                                  (0x00008000)
#define DC_PHY_FIFO_ARB_21_rq_ch_fifo_overflow(data)                                 (0x00008000&((data)<<15))
#define DC_PHY_FIFO_ARB_21_rq_ch_fifo_overflow_src(data)                             ((0x00008000&(data))>>15)
#define DC_PHY_FIFO_ARB_21_get_rq_ch_fifo_overflow(data)                             ((0x00008000&(data))>>15)
#define DC_PHY_FIFO_ARB_21_rq_ch_fifo_underflow_shift                                (14)
#define DC_PHY_FIFO_ARB_21_rq_ch_fifo_underflow_mask                                 (0x00004000)
#define DC_PHY_FIFO_ARB_21_rq_ch_fifo_underflow(data)                                (0x00004000&((data)<<14))
#define DC_PHY_FIFO_ARB_21_rq_ch_fifo_underflow_src(data)                            ((0x00004000&(data))>>14)
#define DC_PHY_FIFO_ARB_21_get_rq_ch_fifo_underflow(data)                            ((0x00004000&(data))>>14)
#define DC_PHY_FIFO_ARB_21_rq_ch_fifo_full_shift                                     (13)
#define DC_PHY_FIFO_ARB_21_rq_ch_fifo_full_mask                                      (0x00002000)
#define DC_PHY_FIFO_ARB_21_rq_ch_fifo_full(data)                                     (0x00002000&((data)<<13))
#define DC_PHY_FIFO_ARB_21_rq_ch_fifo_full_src(data)                                 ((0x00002000&(data))>>13)
#define DC_PHY_FIFO_ARB_21_get_rq_ch_fifo_full(data)                                 ((0x00002000&(data))>>13)
#define DC_PHY_FIFO_ARB_21_rq_ch_fifo_empty_shift                                    (12)
#define DC_PHY_FIFO_ARB_21_rq_ch_fifo_empty_mask                                     (0x00001000)
#define DC_PHY_FIFO_ARB_21_rq_ch_fifo_empty(data)                                    (0x00001000&((data)<<12))
#define DC_PHY_FIFO_ARB_21_rq_ch_fifo_empty_src(data)                                ((0x00001000&(data))>>12)
#define DC_PHY_FIFO_ARB_21_get_rq_ch_fifo_empty(data)                                ((0x00001000&(data))>>12)
#define DC_PHY_FIFO_ARB_21_rq_ch_fifo_thr_shift                                      (4)
#define DC_PHY_FIFO_ARB_21_rq_ch_fifo_thr_mask                                       (0x00000FF0)
#define DC_PHY_FIFO_ARB_21_rq_ch_fifo_thr(data)                                      (0x00000FF0&((data)<<4))
#define DC_PHY_FIFO_ARB_21_rq_ch_fifo_thr_src(data)                                  ((0x00000FF0&(data))>>4)
#define DC_PHY_FIFO_ARB_21_get_rq_ch_fifo_thr(data)                                  ((0x00000FF0&(data))>>4)
#define DC_PHY_FIFO_ARB_21_rq_ch_fifo_overflow_clr_shift                             (3)
#define DC_PHY_FIFO_ARB_21_rq_ch_fifo_overflow_clr_mask                              (0x00000008)
#define DC_PHY_FIFO_ARB_21_rq_ch_fifo_overflow_clr(data)                             (0x00000008&((data)<<3))
#define DC_PHY_FIFO_ARB_21_rq_ch_fifo_overflow_clr_src(data)                         ((0x00000008&(data))>>3)
#define DC_PHY_FIFO_ARB_21_get_rq_ch_fifo_overflow_clr(data)                         ((0x00000008&(data))>>3)
#define DC_PHY_FIFO_ARB_21_rq_ch_fifo_underflow_clr_shift                            (2)
#define DC_PHY_FIFO_ARB_21_rq_ch_fifo_underflow_clr_mask                             (0x00000004)
#define DC_PHY_FIFO_ARB_21_rq_ch_fifo_underflow_clr(data)                            (0x00000004&((data)<<2))
#define DC_PHY_FIFO_ARB_21_rq_ch_fifo_underflow_clr_src(data)                        ((0x00000004&(data))>>2)
#define DC_PHY_FIFO_ARB_21_get_rq_ch_fifo_underflow_clr(data)                        ((0x00000004&(data))>>2)
#define DC_PHY_FIFO_ARB_21_rq_ch_clk_gated_en_shift                                  (1)
#define DC_PHY_FIFO_ARB_21_rq_ch_clk_gated_en_mask                                   (0x00000002)
#define DC_PHY_FIFO_ARB_21_rq_ch_clk_gated_en(data)                                  (0x00000002&((data)<<1))
#define DC_PHY_FIFO_ARB_21_rq_ch_clk_gated_en_src(data)                              ((0x00000002&(data))>>1)
#define DC_PHY_FIFO_ARB_21_get_rq_ch_clk_gated_en(data)                              ((0x00000002&(data))>>1)


#define DC_PHY_FIFO_ARB_22                                                           0x18008e58
#define DC_PHY_FIFO_ARB_22_reg_addr                                                  "0xB8008E58"
#define DC_PHY_FIFO_ARB_22_reg                                                       0xB8008E58
#define set_DC_PHY_FIFO_ARB_22_reg(data)   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_22_reg)=data)
#define get_DC_PHY_FIFO_ARB_22_reg   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_22_reg))
#define DC_PHY_FIFO_ARB_22_inst_adr                                                  "0x0096"
#define DC_PHY_FIFO_ARB_22_inst                                                      0x0096
#define DC_PHY_FIFO_ARB_22_rq_ch_fifo_cnt_shift                                      (0)
#define DC_PHY_FIFO_ARB_22_rq_ch_fifo_cnt_mask                                       (0x000000FF)
#define DC_PHY_FIFO_ARB_22_rq_ch_fifo_cnt(data)                                      (0x000000FF&((data)<<0))
#define DC_PHY_FIFO_ARB_22_rq_ch_fifo_cnt_src(data)                                  ((0x000000FF&(data))>>0)
#define DC_PHY_FIFO_ARB_22_get_rq_ch_fifo_cnt(data)                                  ((0x000000FF&(data))>>0)


#define DC_PHY_FIFO_ARB_23                                                           0x18008e5c
#define DC_PHY_FIFO_ARB_23_reg_addr                                                  "0xB8008E5C"
#define DC_PHY_FIFO_ARB_23_reg                                                       0xB8008E5C
#define set_DC_PHY_FIFO_ARB_23_reg(data)   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_23_reg)=data)
#define get_DC_PHY_FIFO_ARB_23_reg   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_23_reg))
#define DC_PHY_FIFO_ARB_23_inst_adr                                                  "0x0097"
#define DC_PHY_FIFO_ARB_23_inst                                                      0x0097
#define DC_PHY_FIFO_ARB_23_rq_ch_dbg_mod_shift                                       (0)
#define DC_PHY_FIFO_ARB_23_rq_ch_dbg_mod_mask                                        (0x000000FF)
#define DC_PHY_FIFO_ARB_23_rq_ch_dbg_mod(data)                                       (0x000000FF&((data)<<0))
#define DC_PHY_FIFO_ARB_23_rq_ch_dbg_mod_src(data)                                   ((0x000000FF&(data))>>0)
#define DC_PHY_FIFO_ARB_23_get_rq_ch_dbg_mod(data)                                   ((0x000000FF&(data))>>0)


#define DC_PHY_FIFO_ARB_24                                                           0x18008e60
#define DC_PHY_FIFO_ARB_24_reg_addr                                                  "0xB8008E60"
#define DC_PHY_FIFO_ARB_24_reg                                                       0xB8008E60
#define set_DC_PHY_FIFO_ARB_24_reg(data)   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_24_reg)=data)
#define get_DC_PHY_FIFO_ARB_24_reg   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_24_reg))
#define DC_PHY_FIFO_ARB_24_inst_adr                                                  "0x0098"
#define DC_PHY_FIFO_ARB_24_inst                                                      0x0098
#define DC_PHY_FIFO_ARB_24_rq_ch_dummy_0_shift                                       (0)
#define DC_PHY_FIFO_ARB_24_rq_ch_dummy_0_mask                                        (0xFFFFFFFF)
#define DC_PHY_FIFO_ARB_24_rq_ch_dummy_0(data)                                       (0xFFFFFFFF&((data)<<0))
#define DC_PHY_FIFO_ARB_24_rq_ch_dummy_0_src(data)                                   ((0xFFFFFFFF&(data))>>0)
#define DC_PHY_FIFO_ARB_24_get_rq_ch_dummy_0(data)                                   ((0xFFFFFFFF&(data))>>0)


#define DC_PHY_FIFO_ARB_25                                                           0x18008e64
#define DC_PHY_FIFO_ARB_25_reg_addr                                                  "0xB8008E64"
#define DC_PHY_FIFO_ARB_25_reg                                                       0xB8008E64
#define set_DC_PHY_FIFO_ARB_25_reg(data)   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_25_reg)=data)
#define get_DC_PHY_FIFO_ARB_25_reg   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_25_reg))
#define DC_PHY_FIFO_ARB_25_inst_adr                                                  "0x0099"
#define DC_PHY_FIFO_ARB_25_inst                                                      0x0099
#define DC_PHY_FIFO_ARB_25_rq_ch_st0_shift                                           (0)
#define DC_PHY_FIFO_ARB_25_rq_ch_st0_mask                                            (0xFFFFFFFF)
#define DC_PHY_FIFO_ARB_25_rq_ch_st0(data)                                           (0xFFFFFFFF&((data)<<0))
#define DC_PHY_FIFO_ARB_25_rq_ch_st0_src(data)                                       ((0xFFFFFFFF&(data))>>0)
#define DC_PHY_FIFO_ARB_25_get_rq_ch_st0(data)                                       ((0xFFFFFFFF&(data))>>0)


#define DC_PHY_FIFO_ARB_26                                                           0x18008e68
#define DC_PHY_FIFO_ARB_26_reg_addr                                                  "0xB8008E68"
#define DC_PHY_FIFO_ARB_26_reg                                                       0xB8008E68
#define set_DC_PHY_FIFO_ARB_26_reg(data)   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_26_reg)=data)
#define get_DC_PHY_FIFO_ARB_26_reg   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_26_reg))
#define DC_PHY_FIFO_ARB_26_inst_adr                                                  "0x009A"
#define DC_PHY_FIFO_ARB_26_inst                                                      0x009A
#define DC_PHY_FIFO_ARB_26_rq_ch_st1_shift                                           (0)
#define DC_PHY_FIFO_ARB_26_rq_ch_st1_mask                                            (0xFFFFFFFF)
#define DC_PHY_FIFO_ARB_26_rq_ch_st1(data)                                           (0xFFFFFFFF&((data)<<0))
#define DC_PHY_FIFO_ARB_26_rq_ch_st1_src(data)                                       ((0xFFFFFFFF&(data))>>0)
#define DC_PHY_FIFO_ARB_26_get_rq_ch_st1(data)                                       ((0xFFFFFFFF&(data))>>0)


#define DC_PHY_FIFO_ARB_27                                                           0x18008e6c
#define DC_PHY_FIFO_ARB_27_reg_addr                                                  "0xB8008E6C"
#define DC_PHY_FIFO_ARB_27_reg                                                       0xB8008E6C
#define set_DC_PHY_FIFO_ARB_27_reg(data)   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_27_reg)=data)
#define get_DC_PHY_FIFO_ARB_27_reg   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_27_reg))
#define DC_PHY_FIFO_ARB_27_inst_adr                                                  "0x009B"
#define DC_PHY_FIFO_ARB_27_inst                                                      0x009B
#define DC_PHY_FIFO_ARB_27_rq_ch_st2_shift                                           (0)
#define DC_PHY_FIFO_ARB_27_rq_ch_st2_mask                                            (0xFFFFFFFF)
#define DC_PHY_FIFO_ARB_27_rq_ch_st2(data)                                           (0xFFFFFFFF&((data)<<0))
#define DC_PHY_FIFO_ARB_27_rq_ch_st2_src(data)                                       ((0xFFFFFFFF&(data))>>0)
#define DC_PHY_FIFO_ARB_27_get_rq_ch_st2(data)                                       ((0xFFFFFFFF&(data))>>0)


#define DC_PHY_FIFO_ARB_28                                                           0x18008e70
#define DC_PHY_FIFO_ARB_28_reg_addr                                                  "0xB8008E70"
#define DC_PHY_FIFO_ARB_28_reg                                                       0xB8008E70
#define set_DC_PHY_FIFO_ARB_28_reg(data)   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_28_reg)=data)
#define get_DC_PHY_FIFO_ARB_28_reg   (*((volatile unsigned int*) DC_PHY_FIFO_ARB_28_reg))
#define DC_PHY_FIFO_ARB_28_inst_adr                                                  "0x009C"
#define DC_PHY_FIFO_ARB_28_inst                                                      0x009C
#define DC_PHY_FIFO_ARB_28_rq_ch_st3_shift                                           (0)
#define DC_PHY_FIFO_ARB_28_rq_ch_st3_mask                                            (0xFFFFFFFF)
#define DC_PHY_FIFO_ARB_28_rq_ch_st3(data)                                           (0xFFFFFFFF&((data)<<0))
#define DC_PHY_FIFO_ARB_28_rq_ch_st3_src(data)                                       ((0xFFFFFFFF&(data))>>0)
#define DC_PHY_FIFO_ARB_28_get_rq_ch_st3(data)                                       ((0xFFFFFFFF&(data))>>0)


#define DC_PHY_SCRAMBLE_CTRL                                                         0x18008e74
#define DC_PHY_SCRAMBLE_CTRL_reg_addr                                                "0xB8008E74"
#define DC_PHY_SCRAMBLE_CTRL_reg                                                     0xB8008E74
#define set_DC_PHY_SCRAMBLE_CTRL_reg(data)   (*((volatile unsigned int*) DC_PHY_SCRAMBLE_CTRL_reg)=data)
#define get_DC_PHY_SCRAMBLE_CTRL_reg   (*((volatile unsigned int*) DC_PHY_SCRAMBLE_CTRL_reg))
#define DC_PHY_SCRAMBLE_CTRL_inst_adr                                                "0x009D"
#define DC_PHY_SCRAMBLE_CTRL_inst                                                    0x009D
#define DC_PHY_SCRAMBLE_CTRL_seq_mode_sc_sel_shift                                   (1)
#define DC_PHY_SCRAMBLE_CTRL_seq_mode_sc_sel_mask                                    (0x00000002)
#define DC_PHY_SCRAMBLE_CTRL_seq_mode_sc_sel(data)                                   (0x00000002&((data)<<1))
#define DC_PHY_SCRAMBLE_CTRL_seq_mode_sc_sel_src(data)                               ((0x00000002&(data))>>1)
#define DC_PHY_SCRAMBLE_CTRL_get_seq_mode_sc_sel(data)                               ((0x00000002&(data))>>1)
#define DC_PHY_SCRAMBLE_CTRL_scramble_en_shift                                       (0)
#define DC_PHY_SCRAMBLE_CTRL_scramble_en_mask                                        (0x00000001)
#define DC_PHY_SCRAMBLE_CTRL_scramble_en(data)                                       (0x00000001&((data)<<0))
#define DC_PHY_SCRAMBLE_CTRL_scramble_en_src(data)                                   ((0x00000001&(data))>>0)
#define DC_PHY_SCRAMBLE_CTRL_get_scramble_en(data)                                   ((0x00000001&(data))>>0)


#define DC_PHY_SCRAMBLE_KEY_01                                                       0x18008e78
#define DC_PHY_SCRAMBLE_KEY_01_reg_addr                                              "0xB8008E78"
#define DC_PHY_SCRAMBLE_KEY_01_reg                                                   0xB8008E78
#define set_DC_PHY_SCRAMBLE_KEY_01_reg(data)   (*((volatile unsigned int*) DC_PHY_SCRAMBLE_KEY_01_reg)=data)
#define get_DC_PHY_SCRAMBLE_KEY_01_reg   (*((volatile unsigned int*) DC_PHY_SCRAMBLE_KEY_01_reg))
#define DC_PHY_SCRAMBLE_KEY_01_inst_adr                                              "0x009E"
#define DC_PHY_SCRAMBLE_KEY_01_inst                                                  0x009E
#define DC_PHY_SCRAMBLE_KEY_01_sc_key_1_shift                                        (16)
#define DC_PHY_SCRAMBLE_KEY_01_sc_key_1_mask                                         (0xFFFF0000)
#define DC_PHY_SCRAMBLE_KEY_01_sc_key_1(data)                                        (0xFFFF0000&((data)<<16))
#define DC_PHY_SCRAMBLE_KEY_01_sc_key_1_src(data)                                    ((0xFFFF0000&(data))>>16)
#define DC_PHY_SCRAMBLE_KEY_01_get_sc_key_1(data)                                    ((0xFFFF0000&(data))>>16)
#define DC_PHY_SCRAMBLE_KEY_01_sc_key_0_shift                                        (0)
#define DC_PHY_SCRAMBLE_KEY_01_sc_key_0_mask                                         (0x0000FFFF)
#define DC_PHY_SCRAMBLE_KEY_01_sc_key_0(data)                                        (0x0000FFFF&((data)<<0))
#define DC_PHY_SCRAMBLE_KEY_01_sc_key_0_src(data)                                    ((0x0000FFFF&(data))>>0)
#define DC_PHY_SCRAMBLE_KEY_01_get_sc_key_0(data)                                    ((0x0000FFFF&(data))>>0)


#define DC_PHY_SCRAMBLE_KEY_23                                                       0x18008e7c
#define DC_PHY_SCRAMBLE_KEY_23_reg_addr                                              "0xB8008E7C"
#define DC_PHY_SCRAMBLE_KEY_23_reg                                                   0xB8008E7C
#define set_DC_PHY_SCRAMBLE_KEY_23_reg(data)   (*((volatile unsigned int*) DC_PHY_SCRAMBLE_KEY_23_reg)=data)
#define get_DC_PHY_SCRAMBLE_KEY_23_reg   (*((volatile unsigned int*) DC_PHY_SCRAMBLE_KEY_23_reg))
#define DC_PHY_SCRAMBLE_KEY_23_inst_adr                                              "0x009F"
#define DC_PHY_SCRAMBLE_KEY_23_inst                                                  0x009F
#define DC_PHY_SCRAMBLE_KEY_23_sc_key_3_shift                                        (16)
#define DC_PHY_SCRAMBLE_KEY_23_sc_key_3_mask                                         (0xFFFF0000)
#define DC_PHY_SCRAMBLE_KEY_23_sc_key_3(data)                                        (0xFFFF0000&((data)<<16))
#define DC_PHY_SCRAMBLE_KEY_23_sc_key_3_src(data)                                    ((0xFFFF0000&(data))>>16)
#define DC_PHY_SCRAMBLE_KEY_23_get_sc_key_3(data)                                    ((0xFFFF0000&(data))>>16)
#define DC_PHY_SCRAMBLE_KEY_23_sc_key_2_shift                                        (0)
#define DC_PHY_SCRAMBLE_KEY_23_sc_key_2_mask                                         (0x0000FFFF)
#define DC_PHY_SCRAMBLE_KEY_23_sc_key_2(data)                                        (0x0000FFFF&((data)<<0))
#define DC_PHY_SCRAMBLE_KEY_23_sc_key_2_src(data)                                    ((0x0000FFFF&(data))>>0)
#define DC_PHY_SCRAMBLE_KEY_23_get_sc_key_2(data)                                    ((0x0000FFFF&(data))>>0)


#define DC_PHY_SCRAMBLE_KEY_45                                                       0x18008e80
#define DC_PHY_SCRAMBLE_KEY_45_reg_addr                                              "0xB8008E80"
#define DC_PHY_SCRAMBLE_KEY_45_reg                                                   0xB8008E80
#define set_DC_PHY_SCRAMBLE_KEY_45_reg(data)   (*((volatile unsigned int*) DC_PHY_SCRAMBLE_KEY_45_reg)=data)
#define get_DC_PHY_SCRAMBLE_KEY_45_reg   (*((volatile unsigned int*) DC_PHY_SCRAMBLE_KEY_45_reg))
#define DC_PHY_SCRAMBLE_KEY_45_inst_adr                                              "0x00A0"
#define DC_PHY_SCRAMBLE_KEY_45_inst                                                  0x00A0
#define DC_PHY_SCRAMBLE_KEY_45_sc_key_5_shift                                        (16)
#define DC_PHY_SCRAMBLE_KEY_45_sc_key_5_mask                                         (0xFFFF0000)
#define DC_PHY_SCRAMBLE_KEY_45_sc_key_5(data)                                        (0xFFFF0000&((data)<<16))
#define DC_PHY_SCRAMBLE_KEY_45_sc_key_5_src(data)                                    ((0xFFFF0000&(data))>>16)
#define DC_PHY_SCRAMBLE_KEY_45_get_sc_key_5(data)                                    ((0xFFFF0000&(data))>>16)
#define DC_PHY_SCRAMBLE_KEY_45_sc_key_4_shift                                        (0)
#define DC_PHY_SCRAMBLE_KEY_45_sc_key_4_mask                                         (0x0000FFFF)
#define DC_PHY_SCRAMBLE_KEY_45_sc_key_4(data)                                        (0x0000FFFF&((data)<<0))
#define DC_PHY_SCRAMBLE_KEY_45_sc_key_4_src(data)                                    ((0x0000FFFF&(data))>>0)
#define DC_PHY_SCRAMBLE_KEY_45_get_sc_key_4(data)                                    ((0x0000FFFF&(data))>>0)


#define DC_PHY_SCRAMBLE_KEY_67                                                       0x18008e84
#define DC_PHY_SCRAMBLE_KEY_67_reg_addr                                              "0xB8008E84"
#define DC_PHY_SCRAMBLE_KEY_67_reg                                                   0xB8008E84
#define set_DC_PHY_SCRAMBLE_KEY_67_reg(data)   (*((volatile unsigned int*) DC_PHY_SCRAMBLE_KEY_67_reg)=data)
#define get_DC_PHY_SCRAMBLE_KEY_67_reg   (*((volatile unsigned int*) DC_PHY_SCRAMBLE_KEY_67_reg))
#define DC_PHY_SCRAMBLE_KEY_67_inst_adr                                              "0x00A1"
#define DC_PHY_SCRAMBLE_KEY_67_inst                                                  0x00A1
#define DC_PHY_SCRAMBLE_KEY_67_sc_key_7_shift                                        (16)
#define DC_PHY_SCRAMBLE_KEY_67_sc_key_7_mask                                         (0xFFFF0000)
#define DC_PHY_SCRAMBLE_KEY_67_sc_key_7(data)                                        (0xFFFF0000&((data)<<16))
#define DC_PHY_SCRAMBLE_KEY_67_sc_key_7_src(data)                                    ((0xFFFF0000&(data))>>16)
#define DC_PHY_SCRAMBLE_KEY_67_get_sc_key_7(data)                                    ((0xFFFF0000&(data))>>16)
#define DC_PHY_SCRAMBLE_KEY_67_sc_key_6_shift                                        (0)
#define DC_PHY_SCRAMBLE_KEY_67_sc_key_6_mask                                         (0x0000FFFF)
#define DC_PHY_SCRAMBLE_KEY_67_sc_key_6(data)                                        (0x0000FFFF&((data)<<0))
#define DC_PHY_SCRAMBLE_KEY_67_sc_key_6_src(data)                                    ((0x0000FFFF&(data))>>0)
#define DC_PHY_SCRAMBLE_KEY_67_get_sc_key_6(data)                                    ((0x0000FFFF&(data))>>0)


#define DC_PHY_SCRAMBLE_KEY_89                                                       0x18008e88
#define DC_PHY_SCRAMBLE_KEY_89_reg_addr                                              "0xB8008E88"
#define DC_PHY_SCRAMBLE_KEY_89_reg                                                   0xB8008E88
#define set_DC_PHY_SCRAMBLE_KEY_89_reg(data)   (*((volatile unsigned int*) DC_PHY_SCRAMBLE_KEY_89_reg)=data)
#define get_DC_PHY_SCRAMBLE_KEY_89_reg   (*((volatile unsigned int*) DC_PHY_SCRAMBLE_KEY_89_reg))
#define DC_PHY_SCRAMBLE_KEY_89_inst_adr                                              "0x00A2"
#define DC_PHY_SCRAMBLE_KEY_89_inst                                                  0x00A2
#define DC_PHY_SCRAMBLE_KEY_89_sc_key_9_shift                                        (16)
#define DC_PHY_SCRAMBLE_KEY_89_sc_key_9_mask                                         (0xFFFF0000)
#define DC_PHY_SCRAMBLE_KEY_89_sc_key_9(data)                                        (0xFFFF0000&((data)<<16))
#define DC_PHY_SCRAMBLE_KEY_89_sc_key_9_src(data)                                    ((0xFFFF0000&(data))>>16)
#define DC_PHY_SCRAMBLE_KEY_89_get_sc_key_9(data)                                    ((0xFFFF0000&(data))>>16)
#define DC_PHY_SCRAMBLE_KEY_89_sc_key_8_shift                                        (0)
#define DC_PHY_SCRAMBLE_KEY_89_sc_key_8_mask                                         (0x0000FFFF)
#define DC_PHY_SCRAMBLE_KEY_89_sc_key_8(data)                                        (0x0000FFFF&((data)<<0))
#define DC_PHY_SCRAMBLE_KEY_89_sc_key_8_src(data)                                    ((0x0000FFFF&(data))>>0)
#define DC_PHY_SCRAMBLE_KEY_89_get_sc_key_8(data)                                    ((0x0000FFFF&(data))>>0)


#define DC_PHY_SCRAMBLE_KEY_1011                                                     0x18008e8c
#define DC_PHY_SCRAMBLE_KEY_1011_reg_addr                                            "0xB8008E8C"
#define DC_PHY_SCRAMBLE_KEY_1011_reg                                                 0xB8008E8C
#define set_DC_PHY_SCRAMBLE_KEY_1011_reg(data)   (*((volatile unsigned int*) DC_PHY_SCRAMBLE_KEY_1011_reg)=data)
#define get_DC_PHY_SCRAMBLE_KEY_1011_reg   (*((volatile unsigned int*) DC_PHY_SCRAMBLE_KEY_1011_reg))
#define DC_PHY_SCRAMBLE_KEY_1011_inst_adr                                            "0x00A3"
#define DC_PHY_SCRAMBLE_KEY_1011_inst                                                0x00A3
#define DC_PHY_SCRAMBLE_KEY_1011_sc_key_11_shift                                     (16)
#define DC_PHY_SCRAMBLE_KEY_1011_sc_key_11_mask                                      (0xFFFF0000)
#define DC_PHY_SCRAMBLE_KEY_1011_sc_key_11(data)                                     (0xFFFF0000&((data)<<16))
#define DC_PHY_SCRAMBLE_KEY_1011_sc_key_11_src(data)                                 ((0xFFFF0000&(data))>>16)
#define DC_PHY_SCRAMBLE_KEY_1011_get_sc_key_11(data)                                 ((0xFFFF0000&(data))>>16)
#define DC_PHY_SCRAMBLE_KEY_1011_sc_key_10_shift                                     (0)
#define DC_PHY_SCRAMBLE_KEY_1011_sc_key_10_mask                                      (0x0000FFFF)
#define DC_PHY_SCRAMBLE_KEY_1011_sc_key_10(data)                                     (0x0000FFFF&((data)<<0))
#define DC_PHY_SCRAMBLE_KEY_1011_sc_key_10_src(data)                                 ((0x0000FFFF&(data))>>0)
#define DC_PHY_SCRAMBLE_KEY_1011_get_sc_key_10(data)                                 ((0x0000FFFF&(data))>>0)


#define DC_PHY_SCRAMBLE_KEY_1213                                                     0x18008e90
#define DC_PHY_SCRAMBLE_KEY_1213_reg_addr                                            "0xB8008E90"
#define DC_PHY_SCRAMBLE_KEY_1213_reg                                                 0xB8008E90
#define set_DC_PHY_SCRAMBLE_KEY_1213_reg(data)   (*((volatile unsigned int*) DC_PHY_SCRAMBLE_KEY_1213_reg)=data)
#define get_DC_PHY_SCRAMBLE_KEY_1213_reg   (*((volatile unsigned int*) DC_PHY_SCRAMBLE_KEY_1213_reg))
#define DC_PHY_SCRAMBLE_KEY_1213_inst_adr                                            "0x00A4"
#define DC_PHY_SCRAMBLE_KEY_1213_inst                                                0x00A4
#define DC_PHY_SCRAMBLE_KEY_1213_sc_key_13_shift                                     (16)
#define DC_PHY_SCRAMBLE_KEY_1213_sc_key_13_mask                                      (0xFFFF0000)
#define DC_PHY_SCRAMBLE_KEY_1213_sc_key_13(data)                                     (0xFFFF0000&((data)<<16))
#define DC_PHY_SCRAMBLE_KEY_1213_sc_key_13_src(data)                                 ((0xFFFF0000&(data))>>16)
#define DC_PHY_SCRAMBLE_KEY_1213_get_sc_key_13(data)                                 ((0xFFFF0000&(data))>>16)
#define DC_PHY_SCRAMBLE_KEY_1213_sc_key_12_shift                                     (0)
#define DC_PHY_SCRAMBLE_KEY_1213_sc_key_12_mask                                      (0x0000FFFF)
#define DC_PHY_SCRAMBLE_KEY_1213_sc_key_12(data)                                     (0x0000FFFF&((data)<<0))
#define DC_PHY_SCRAMBLE_KEY_1213_sc_key_12_src(data)                                 ((0x0000FFFF&(data))>>0)
#define DC_PHY_SCRAMBLE_KEY_1213_get_sc_key_12(data)                                 ((0x0000FFFF&(data))>>0)


#define DC_PHY_SCRAMBLE_KEY_1415                                                     0x18008e94
#define DC_PHY_SCRAMBLE_KEY_1415_reg_addr                                            "0xB8008E94"
#define DC_PHY_SCRAMBLE_KEY_1415_reg                                                 0xB8008E94
#define set_DC_PHY_SCRAMBLE_KEY_1415_reg(data)   (*((volatile unsigned int*) DC_PHY_SCRAMBLE_KEY_1415_reg)=data)
#define get_DC_PHY_SCRAMBLE_KEY_1415_reg   (*((volatile unsigned int*) DC_PHY_SCRAMBLE_KEY_1415_reg))
#define DC_PHY_SCRAMBLE_KEY_1415_inst_adr                                            "0x00A5"
#define DC_PHY_SCRAMBLE_KEY_1415_inst                                                0x00A5
#define DC_PHY_SCRAMBLE_KEY_1415_sc_key_15_shift                                     (16)
#define DC_PHY_SCRAMBLE_KEY_1415_sc_key_15_mask                                      (0xFFFF0000)
#define DC_PHY_SCRAMBLE_KEY_1415_sc_key_15(data)                                     (0xFFFF0000&((data)<<16))
#define DC_PHY_SCRAMBLE_KEY_1415_sc_key_15_src(data)                                 ((0xFFFF0000&(data))>>16)
#define DC_PHY_SCRAMBLE_KEY_1415_get_sc_key_15(data)                                 ((0xFFFF0000&(data))>>16)
#define DC_PHY_SCRAMBLE_KEY_1415_sc_key_14_shift                                     (0)
#define DC_PHY_SCRAMBLE_KEY_1415_sc_key_14_mask                                      (0x0000FFFF)
#define DC_PHY_SCRAMBLE_KEY_1415_sc_key_14(data)                                     (0x0000FFFF&((data)<<0))
#define DC_PHY_SCRAMBLE_KEY_1415_sc_key_14_src(data)                                 ((0x0000FFFF&(data))>>0)
#define DC_PHY_SCRAMBLE_KEY_1415_get_sc_key_14(data)                                 ((0x0000FFFF&(data))>>0)


#define DC_PHY_SCRAMBLE_KEY_1617                                                     0x18008e98
#define DC_PHY_SCRAMBLE_KEY_1617_reg_addr                                            "0xB8008E98"
#define DC_PHY_SCRAMBLE_KEY_1617_reg                                                 0xB8008E98
#define set_DC_PHY_SCRAMBLE_KEY_1617_reg(data)   (*((volatile unsigned int*) DC_PHY_SCRAMBLE_KEY_1617_reg)=data)
#define get_DC_PHY_SCRAMBLE_KEY_1617_reg   (*((volatile unsigned int*) DC_PHY_SCRAMBLE_KEY_1617_reg))
#define DC_PHY_SCRAMBLE_KEY_1617_inst_adr                                            "0x00A6"
#define DC_PHY_SCRAMBLE_KEY_1617_inst                                                0x00A6
#define DC_PHY_SCRAMBLE_KEY_1617_sc_key_17_shift                                     (16)
#define DC_PHY_SCRAMBLE_KEY_1617_sc_key_17_mask                                      (0xFFFF0000)
#define DC_PHY_SCRAMBLE_KEY_1617_sc_key_17(data)                                     (0xFFFF0000&((data)<<16))
#define DC_PHY_SCRAMBLE_KEY_1617_sc_key_17_src(data)                                 ((0xFFFF0000&(data))>>16)
#define DC_PHY_SCRAMBLE_KEY_1617_get_sc_key_17(data)                                 ((0xFFFF0000&(data))>>16)
#define DC_PHY_SCRAMBLE_KEY_1617_sc_key_16_shift                                     (0)
#define DC_PHY_SCRAMBLE_KEY_1617_sc_key_16_mask                                      (0x0000FFFF)
#define DC_PHY_SCRAMBLE_KEY_1617_sc_key_16(data)                                     (0x0000FFFF&((data)<<0))
#define DC_PHY_SCRAMBLE_KEY_1617_sc_key_16_src(data)                                 ((0x0000FFFF&(data))>>0)
#define DC_PHY_SCRAMBLE_KEY_1617_get_sc_key_16(data)                                 ((0x0000FFFF&(data))>>0)


#define DC_PHY_SCRAMBLE_KEY_1819                                                     0x18008e9c
#define DC_PHY_SCRAMBLE_KEY_1819_reg_addr                                            "0xB8008E9C"
#define DC_PHY_SCRAMBLE_KEY_1819_reg                                                 0xB8008E9C
#define set_DC_PHY_SCRAMBLE_KEY_1819_reg(data)   (*((volatile unsigned int*) DC_PHY_SCRAMBLE_KEY_1819_reg)=data)
#define get_DC_PHY_SCRAMBLE_KEY_1819_reg   (*((volatile unsigned int*) DC_PHY_SCRAMBLE_KEY_1819_reg))
#define DC_PHY_SCRAMBLE_KEY_1819_inst_adr                                            "0x00A7"
#define DC_PHY_SCRAMBLE_KEY_1819_inst                                                0x00A7
#define DC_PHY_SCRAMBLE_KEY_1819_sc_key_19_shift                                     (16)
#define DC_PHY_SCRAMBLE_KEY_1819_sc_key_19_mask                                      (0xFFFF0000)
#define DC_PHY_SCRAMBLE_KEY_1819_sc_key_19(data)                                     (0xFFFF0000&((data)<<16))
#define DC_PHY_SCRAMBLE_KEY_1819_sc_key_19_src(data)                                 ((0xFFFF0000&(data))>>16)
#define DC_PHY_SCRAMBLE_KEY_1819_get_sc_key_19(data)                                 ((0xFFFF0000&(data))>>16)
#define DC_PHY_SCRAMBLE_KEY_1819_sc_key_18_shift                                     (0)
#define DC_PHY_SCRAMBLE_KEY_1819_sc_key_18_mask                                      (0x0000FFFF)
#define DC_PHY_SCRAMBLE_KEY_1819_sc_key_18(data)                                     (0x0000FFFF&((data)<<0))
#define DC_PHY_SCRAMBLE_KEY_1819_sc_key_18_src(data)                                 ((0x0000FFFF&(data))>>0)
#define DC_PHY_SCRAMBLE_KEY_1819_get_sc_key_18(data)                                 ((0x0000FFFF&(data))>>0)


#define DC_PHY_SCRAMBLE_KEY_2021                                                     0x18008ea0
#define DC_PHY_SCRAMBLE_KEY_2021_reg_addr                                            "0xB8008EA0"
#define DC_PHY_SCRAMBLE_KEY_2021_reg                                                 0xB8008EA0
#define set_DC_PHY_SCRAMBLE_KEY_2021_reg(data)   (*((volatile unsigned int*) DC_PHY_SCRAMBLE_KEY_2021_reg)=data)
#define get_DC_PHY_SCRAMBLE_KEY_2021_reg   (*((volatile unsigned int*) DC_PHY_SCRAMBLE_KEY_2021_reg))
#define DC_PHY_SCRAMBLE_KEY_2021_inst_adr                                            "0x00A8"
#define DC_PHY_SCRAMBLE_KEY_2021_inst                                                0x00A8
#define DC_PHY_SCRAMBLE_KEY_2021_sc_key_21_shift                                     (16)
#define DC_PHY_SCRAMBLE_KEY_2021_sc_key_21_mask                                      (0xFFFF0000)
#define DC_PHY_SCRAMBLE_KEY_2021_sc_key_21(data)                                     (0xFFFF0000&((data)<<16))
#define DC_PHY_SCRAMBLE_KEY_2021_sc_key_21_src(data)                                 ((0xFFFF0000&(data))>>16)
#define DC_PHY_SCRAMBLE_KEY_2021_get_sc_key_21(data)                                 ((0xFFFF0000&(data))>>16)
#define DC_PHY_SCRAMBLE_KEY_2021_sc_key_20_shift                                     (0)
#define DC_PHY_SCRAMBLE_KEY_2021_sc_key_20_mask                                      (0x0000FFFF)
#define DC_PHY_SCRAMBLE_KEY_2021_sc_key_20(data)                                     (0x0000FFFF&((data)<<0))
#define DC_PHY_SCRAMBLE_KEY_2021_sc_key_20_src(data)                                 ((0x0000FFFF&(data))>>0)
#define DC_PHY_SCRAMBLE_KEY_2021_get_sc_key_20(data)                                 ((0x0000FFFF&(data))>>0)


#define DC_PHY_SCRAMBLE_KEY_2223                                                     0x18008ea4
#define DC_PHY_SCRAMBLE_KEY_2223_reg_addr                                            "0xB8008EA4"
#define DC_PHY_SCRAMBLE_KEY_2223_reg                                                 0xB8008EA4
#define set_DC_PHY_SCRAMBLE_KEY_2223_reg(data)   (*((volatile unsigned int*) DC_PHY_SCRAMBLE_KEY_2223_reg)=data)
#define get_DC_PHY_SCRAMBLE_KEY_2223_reg   (*((volatile unsigned int*) DC_PHY_SCRAMBLE_KEY_2223_reg))
#define DC_PHY_SCRAMBLE_KEY_2223_inst_adr                                            "0x00A9"
#define DC_PHY_SCRAMBLE_KEY_2223_inst                                                0x00A9
#define DC_PHY_SCRAMBLE_KEY_2223_sc_key_23_shift                                     (16)
#define DC_PHY_SCRAMBLE_KEY_2223_sc_key_23_mask                                      (0xFFFF0000)
#define DC_PHY_SCRAMBLE_KEY_2223_sc_key_23(data)                                     (0xFFFF0000&((data)<<16))
#define DC_PHY_SCRAMBLE_KEY_2223_sc_key_23_src(data)                                 ((0xFFFF0000&(data))>>16)
#define DC_PHY_SCRAMBLE_KEY_2223_get_sc_key_23(data)                                 ((0xFFFF0000&(data))>>16)
#define DC_PHY_SCRAMBLE_KEY_2223_sc_key_22_shift                                     (0)
#define DC_PHY_SCRAMBLE_KEY_2223_sc_key_22_mask                                      (0x0000FFFF)
#define DC_PHY_SCRAMBLE_KEY_2223_sc_key_22(data)                                     (0x0000FFFF&((data)<<0))
#define DC_PHY_SCRAMBLE_KEY_2223_sc_key_22_src(data)                                 ((0x0000FFFF&(data))>>0)
#define DC_PHY_SCRAMBLE_KEY_2223_get_sc_key_22(data)                                 ((0x0000FFFF&(data))>>0)


#define DC_PHY_SCRAMBLE_KEY_2425                                                     0x18008ea8
#define DC_PHY_SCRAMBLE_KEY_2425_reg_addr                                            "0xB8008EA8"
#define DC_PHY_SCRAMBLE_KEY_2425_reg                                                 0xB8008EA8
#define set_DC_PHY_SCRAMBLE_KEY_2425_reg(data)   (*((volatile unsigned int*) DC_PHY_SCRAMBLE_KEY_2425_reg)=data)
#define get_DC_PHY_SCRAMBLE_KEY_2425_reg   (*((volatile unsigned int*) DC_PHY_SCRAMBLE_KEY_2425_reg))
#define DC_PHY_SCRAMBLE_KEY_2425_inst_adr                                            "0x00AA"
#define DC_PHY_SCRAMBLE_KEY_2425_inst                                                0x00AA
#define DC_PHY_SCRAMBLE_KEY_2425_sc_key_25_shift                                     (16)
#define DC_PHY_SCRAMBLE_KEY_2425_sc_key_25_mask                                      (0xFFFF0000)
#define DC_PHY_SCRAMBLE_KEY_2425_sc_key_25(data)                                     (0xFFFF0000&((data)<<16))
#define DC_PHY_SCRAMBLE_KEY_2425_sc_key_25_src(data)                                 ((0xFFFF0000&(data))>>16)
#define DC_PHY_SCRAMBLE_KEY_2425_get_sc_key_25(data)                                 ((0xFFFF0000&(data))>>16)
#define DC_PHY_SCRAMBLE_KEY_2425_sc_key_24_shift                                     (0)
#define DC_PHY_SCRAMBLE_KEY_2425_sc_key_24_mask                                      (0x0000FFFF)
#define DC_PHY_SCRAMBLE_KEY_2425_sc_key_24(data)                                     (0x0000FFFF&((data)<<0))
#define DC_PHY_SCRAMBLE_KEY_2425_sc_key_24_src(data)                                 ((0x0000FFFF&(data))>>0)
#define DC_PHY_SCRAMBLE_KEY_2425_get_sc_key_24(data)                                 ((0x0000FFFF&(data))>>0)


#define DC_PHY_SCRAMBLE_KEY_2627                                                     0x18008eac
#define DC_PHY_SCRAMBLE_KEY_2627_reg_addr                                            "0xB8008EAC"
#define DC_PHY_SCRAMBLE_KEY_2627_reg                                                 0xB8008EAC
#define set_DC_PHY_SCRAMBLE_KEY_2627_reg(data)   (*((volatile unsigned int*) DC_PHY_SCRAMBLE_KEY_2627_reg)=data)
#define get_DC_PHY_SCRAMBLE_KEY_2627_reg   (*((volatile unsigned int*) DC_PHY_SCRAMBLE_KEY_2627_reg))
#define DC_PHY_SCRAMBLE_KEY_2627_inst_adr                                            "0x00AB"
#define DC_PHY_SCRAMBLE_KEY_2627_inst                                                0x00AB
#define DC_PHY_SCRAMBLE_KEY_2627_sc_key_27_shift                                     (16)
#define DC_PHY_SCRAMBLE_KEY_2627_sc_key_27_mask                                      (0xFFFF0000)
#define DC_PHY_SCRAMBLE_KEY_2627_sc_key_27(data)                                     (0xFFFF0000&((data)<<16))
#define DC_PHY_SCRAMBLE_KEY_2627_sc_key_27_src(data)                                 ((0xFFFF0000&(data))>>16)
#define DC_PHY_SCRAMBLE_KEY_2627_get_sc_key_27(data)                                 ((0xFFFF0000&(data))>>16)
#define DC_PHY_SCRAMBLE_KEY_2627_sc_key_26_shift                                     (0)
#define DC_PHY_SCRAMBLE_KEY_2627_sc_key_26_mask                                      (0x0000FFFF)
#define DC_PHY_SCRAMBLE_KEY_2627_sc_key_26(data)                                     (0x0000FFFF&((data)<<0))
#define DC_PHY_SCRAMBLE_KEY_2627_sc_key_26_src(data)                                 ((0x0000FFFF&(data))>>0)
#define DC_PHY_SCRAMBLE_KEY_2627_get_sc_key_26(data)                                 ((0x0000FFFF&(data))>>0)


#define DC_PHY_SCRAMBLE_KEY_2829                                                     0x18008eb0
#define DC_PHY_SCRAMBLE_KEY_2829_reg_addr                                            "0xB8008EB0"
#define DC_PHY_SCRAMBLE_KEY_2829_reg                                                 0xB8008EB0
#define set_DC_PHY_SCRAMBLE_KEY_2829_reg(data)   (*((volatile unsigned int*) DC_PHY_SCRAMBLE_KEY_2829_reg)=data)
#define get_DC_PHY_SCRAMBLE_KEY_2829_reg   (*((volatile unsigned int*) DC_PHY_SCRAMBLE_KEY_2829_reg))
#define DC_PHY_SCRAMBLE_KEY_2829_inst_adr                                            "0x00AC"
#define DC_PHY_SCRAMBLE_KEY_2829_inst                                                0x00AC
#define DC_PHY_SCRAMBLE_KEY_2829_sc_key_29_shift                                     (16)
#define DC_PHY_SCRAMBLE_KEY_2829_sc_key_29_mask                                      (0xFFFF0000)
#define DC_PHY_SCRAMBLE_KEY_2829_sc_key_29(data)                                     (0xFFFF0000&((data)<<16))
#define DC_PHY_SCRAMBLE_KEY_2829_sc_key_29_src(data)                                 ((0xFFFF0000&(data))>>16)
#define DC_PHY_SCRAMBLE_KEY_2829_get_sc_key_29(data)                                 ((0xFFFF0000&(data))>>16)
#define DC_PHY_SCRAMBLE_KEY_2829_sc_key_28_shift                                     (0)
#define DC_PHY_SCRAMBLE_KEY_2829_sc_key_28_mask                                      (0x0000FFFF)
#define DC_PHY_SCRAMBLE_KEY_2829_sc_key_28(data)                                     (0x0000FFFF&((data)<<0))
#define DC_PHY_SCRAMBLE_KEY_2829_sc_key_28_src(data)                                 ((0x0000FFFF&(data))>>0)
#define DC_PHY_SCRAMBLE_KEY_2829_get_sc_key_28(data)                                 ((0x0000FFFF&(data))>>0)


#define DC_PHY_SCRAMBLE_KEY_3031                                                     0x18008eb4
#define DC_PHY_SCRAMBLE_KEY_3031_reg_addr                                            "0xB8008EB4"
#define DC_PHY_SCRAMBLE_KEY_3031_reg                                                 0xB8008EB4
#define set_DC_PHY_SCRAMBLE_KEY_3031_reg(data)   (*((volatile unsigned int*) DC_PHY_SCRAMBLE_KEY_3031_reg)=data)
#define get_DC_PHY_SCRAMBLE_KEY_3031_reg   (*((volatile unsigned int*) DC_PHY_SCRAMBLE_KEY_3031_reg))
#define DC_PHY_SCRAMBLE_KEY_3031_inst_adr                                            "0x00AD"
#define DC_PHY_SCRAMBLE_KEY_3031_inst                                                0x00AD
#define DC_PHY_SCRAMBLE_KEY_3031_sc_key_31_shift                                     (16)
#define DC_PHY_SCRAMBLE_KEY_3031_sc_key_31_mask                                      (0xFFFF0000)
#define DC_PHY_SCRAMBLE_KEY_3031_sc_key_31(data)                                     (0xFFFF0000&((data)<<16))
#define DC_PHY_SCRAMBLE_KEY_3031_sc_key_31_src(data)                                 ((0xFFFF0000&(data))>>16)
#define DC_PHY_SCRAMBLE_KEY_3031_get_sc_key_31(data)                                 ((0xFFFF0000&(data))>>16)
#define DC_PHY_SCRAMBLE_KEY_3031_sc_key_30_shift                                     (0)
#define DC_PHY_SCRAMBLE_KEY_3031_sc_key_30_mask                                      (0x0000FFFF)
#define DC_PHY_SCRAMBLE_KEY_3031_sc_key_30(data)                                     (0x0000FFFF&((data)<<0))
#define DC_PHY_SCRAMBLE_KEY_3031_sc_key_30_src(data)                                 ((0x0000FFFF&(data))>>0)
#define DC_PHY_SCRAMBLE_KEY_3031_get_sc_key_30(data)                                 ((0x0000FFFF&(data))>>0)


#define DC_PHY_DUMMY_0                                                               0x18008ee0
#define DC_PHY_DUMMY_0_reg_addr                                                      "0xB8008EE0"
#define DC_PHY_DUMMY_0_reg                                                           0xB8008EE0
#define set_DC_PHY_DUMMY_0_reg(data)   (*((volatile unsigned int*) DC_PHY_DUMMY_0_reg)=data)
#define get_DC_PHY_DUMMY_0_reg   (*((volatile unsigned int*) DC_PHY_DUMMY_0_reg))
#define DC_PHY_DUMMY_0_inst_adr                                                      "0x00B8"
#define DC_PHY_DUMMY_0_inst                                                          0x00B8
#define DC_PHY_DUMMY_0_dummy_0_shift                                                 (0)
#define DC_PHY_DUMMY_0_dummy_0_mask                                                  (0xFFFFFFFF)
#define DC_PHY_DUMMY_0_dummy_0(data)                                                 (0xFFFFFFFF&((data)<<0))
#define DC_PHY_DUMMY_0_dummy_0_src(data)                                             ((0xFFFFFFFF&(data))>>0)
#define DC_PHY_DUMMY_0_get_dummy_0(data)                                             ((0xFFFFFFFF&(data))>>0)


#define DC_PHY_DUMMY_1                                                               0x18008ee4
#define DC_PHY_DUMMY_1_reg_addr                                                      "0xB8008EE4"
#define DC_PHY_DUMMY_1_reg                                                           0xB8008EE4
#define set_DC_PHY_DUMMY_1_reg(data)   (*((volatile unsigned int*) DC_PHY_DUMMY_1_reg)=data)
#define get_DC_PHY_DUMMY_1_reg   (*((volatile unsigned int*) DC_PHY_DUMMY_1_reg))
#define DC_PHY_DUMMY_1_inst_adr                                                      "0x00B9"
#define DC_PHY_DUMMY_1_inst                                                          0x00B9
#define DC_PHY_DUMMY_1_dummy_1_shift                                                 (0)
#define DC_PHY_DUMMY_1_dummy_1_mask                                                  (0xFFFFFFFF)
#define DC_PHY_DUMMY_1_dummy_1(data)                                                 (0xFFFFFFFF&((data)<<0))
#define DC_PHY_DUMMY_1_dummy_1_src(data)                                             ((0xFFFFFFFF&(data))>>0)
#define DC_PHY_DUMMY_1_get_dummy_1(data)                                             ((0xFFFFFFFF&(data))>>0)


#define DC_PHY_DUMMY_2                                                               0x18008ee8
#define DC_PHY_DUMMY_2_reg_addr                                                      "0xB8008EE8"
#define DC_PHY_DUMMY_2_reg                                                           0xB8008EE8
#define set_DC_PHY_DUMMY_2_reg(data)   (*((volatile unsigned int*) DC_PHY_DUMMY_2_reg)=data)
#define get_DC_PHY_DUMMY_2_reg   (*((volatile unsigned int*) DC_PHY_DUMMY_2_reg))
#define DC_PHY_DUMMY_2_inst_adr                                                      "0x00BA"
#define DC_PHY_DUMMY_2_inst                                                          0x00BA
#define DC_PHY_DUMMY_2_dummy_2_shift                                                 (0)
#define DC_PHY_DUMMY_2_dummy_2_mask                                                  (0xFFFFFFFF)
#define DC_PHY_DUMMY_2_dummy_2(data)                                                 (0xFFFFFFFF&((data)<<0))
#define DC_PHY_DUMMY_2_dummy_2_src(data)                                             ((0xFFFFFFFF&(data))>>0)
#define DC_PHY_DUMMY_2_get_dummy_2(data)                                             ((0xFFFFFFFF&(data))>>0)


#define DC_PHY_DUMMY_3                                                               0x18008eec
#define DC_PHY_DUMMY_3_reg_addr                                                      "0xB8008EEC"
#define DC_PHY_DUMMY_3_reg                                                           0xB8008EEC
#define set_DC_PHY_DUMMY_3_reg(data)   (*((volatile unsigned int*) DC_PHY_DUMMY_3_reg)=data)
#define get_DC_PHY_DUMMY_3_reg   (*((volatile unsigned int*) DC_PHY_DUMMY_3_reg))
#define DC_PHY_DUMMY_3_inst_adr                                                      "0x00BB"
#define DC_PHY_DUMMY_3_inst                                                          0x00BB
#define DC_PHY_DUMMY_3_dummy_3_shift                                                 (0)
#define DC_PHY_DUMMY_3_dummy_3_mask                                                  (0xFFFFFFFF)
#define DC_PHY_DUMMY_3_dummy_3(data)                                                 (0xFFFFFFFF&((data)<<0))
#define DC_PHY_DUMMY_3_dummy_3_src(data)                                             ((0xFFFFFFFF&(data))>>0)
#define DC_PHY_DUMMY_3_get_dummy_3(data)                                             ((0xFFFFFFFF&(data))>>0)


#define DC_PHY_DUMMY_4                                                               0x18008ef0
#define DC_PHY_DUMMY_4_reg_addr                                                      "0xB8008EF0"
#define DC_PHY_DUMMY_4_reg                                                           0xB8008EF0
#define set_DC_PHY_DUMMY_4_reg(data)   (*((volatile unsigned int*) DC_PHY_DUMMY_4_reg)=data)
#define get_DC_PHY_DUMMY_4_reg   (*((volatile unsigned int*) DC_PHY_DUMMY_4_reg))
#define DC_PHY_DUMMY_4_inst_adr                                                      "0x00BC"
#define DC_PHY_DUMMY_4_inst                                                          0x00BC
#define DC_PHY_DUMMY_4_dummy_4_shift                                                 (0)
#define DC_PHY_DUMMY_4_dummy_4_mask                                                  (0xFFFFFFFF)
#define DC_PHY_DUMMY_4_dummy_4(data)                                                 (0xFFFFFFFF&((data)<<0))
#define DC_PHY_DUMMY_4_dummy_4_src(data)                                             ((0xFFFFFFFF&(data))>>0)
#define DC_PHY_DUMMY_4_get_dummy_4(data)                                             ((0xFFFFFFFF&(data))>>0)


#define DC_PHY_DUMMY_5                                                               0x18008ef4
#define DC_PHY_DUMMY_5_reg_addr                                                      "0xB8008EF4"
#define DC_PHY_DUMMY_5_reg                                                           0xB8008EF4
#define set_DC_PHY_DUMMY_5_reg(data)   (*((volatile unsigned int*) DC_PHY_DUMMY_5_reg)=data)
#define get_DC_PHY_DUMMY_5_reg   (*((volatile unsigned int*) DC_PHY_DUMMY_5_reg))
#define DC_PHY_DUMMY_5_inst_adr                                                      "0x00BD"
#define DC_PHY_DUMMY_5_inst                                                          0x00BD
#define DC_PHY_DUMMY_5_dummy_5_shift                                                 (0)
#define DC_PHY_DUMMY_5_dummy_5_mask                                                  (0xFFFFFFFF)
#define DC_PHY_DUMMY_5_dummy_5(data)                                                 (0xFFFFFFFF&((data)<<0))
#define DC_PHY_DUMMY_5_dummy_5_src(data)                                             ((0xFFFFFFFF&(data))>>0)
#define DC_PHY_DUMMY_5_get_dummy_5(data)                                             ((0xFFFFFFFF&(data))>>0)


#define DC_PHY_DUMMY_6                                                               0x18008ef8
#define DC_PHY_DUMMY_6_reg_addr                                                      "0xB8008EF8"
#define DC_PHY_DUMMY_6_reg                                                           0xB8008EF8
#define set_DC_PHY_DUMMY_6_reg(data)   (*((volatile unsigned int*) DC_PHY_DUMMY_6_reg)=data)
#define get_DC_PHY_DUMMY_6_reg   (*((volatile unsigned int*) DC_PHY_DUMMY_6_reg))
#define DC_PHY_DUMMY_6_inst_adr                                                      "0x00BE"
#define DC_PHY_DUMMY_6_inst                                                          0x00BE
#define DC_PHY_DUMMY_6_dummy_6_shift                                                 (4)
#define DC_PHY_DUMMY_6_dummy_6_mask                                                  (0xFFFFFFF0)
#define DC_PHY_DUMMY_6_dummy_6(data)                                                 (0xFFFFFFF0&((data)<<4))
#define DC_PHY_DUMMY_6_dummy_6_src(data)                                             ((0xFFFFFFF0&(data))>>4)
#define DC_PHY_DUMMY_6_get_dummy_6(data)                                             ((0xFFFFFFF0&(data))>>4)
#define DC_PHY_DUMMY_6_cs_mask_shift                                                 (3)
#define DC_PHY_DUMMY_6_cs_mask_mask                                                  (0x00000008)
#define DC_PHY_DUMMY_6_cs_mask(data)                                                 (0x00000008&((data)<<3))
#define DC_PHY_DUMMY_6_cs_mask_src(data)                                             ((0x00000008&(data))>>3)
#define DC_PHY_DUMMY_6_get_cs_mask(data)                                             ((0x00000008&(data))>>3)
#define DC_PHY_DUMMY_6_cs1_mask_shift                                                (2)
#define DC_PHY_DUMMY_6_cs1_mask_mask                                                 (0x00000004)
#define DC_PHY_DUMMY_6_cs1_mask(data)                                                (0x00000004&((data)<<2))
#define DC_PHY_DUMMY_6_cs1_mask_src(data)                                            ((0x00000004&(data))>>2)
#define DC_PHY_DUMMY_6_get_cs1_mask(data)                                            ((0x00000004&(data))>>2)
#define DC_PHY_DUMMY_6_cs_swap_shift                                                 (1)
#define DC_PHY_DUMMY_6_cs_swap_mask                                                  (0x00000002)
#define DC_PHY_DUMMY_6_cs_swap(data)                                                 (0x00000002&((data)<<1))
#define DC_PHY_DUMMY_6_cs_swap_src(data)                                             ((0x00000002&(data))>>1)
#define DC_PHY_DUMMY_6_get_cs_swap(data)                                             ((0x00000002&(data))>>1)
#define DC_PHY_DUMMY_6_cmd_mux_sel_bga_shift                                         (0)
#define DC_PHY_DUMMY_6_cmd_mux_sel_bga_mask                                          (0x00000001)
#define DC_PHY_DUMMY_6_cmd_mux_sel_bga(data)                                         (0x00000001&((data)<<0))
#define DC_PHY_DUMMY_6_cmd_mux_sel_bga_src(data)                                     ((0x00000001&(data))>>0)
#define DC_PHY_DUMMY_6_get_cmd_mux_sel_bga(data)                                     ((0x00000001&(data))>>0)


#define DC_PHY_CMD_DLY_1T                                                            0x18008f00
#define DC_PHY_CMD_DLY_1T_reg_addr                                                   "0xB8008F00"
#define DC_PHY_CMD_DLY_1T_reg                                                        0xB8008F00
#define set_DC_PHY_CMD_DLY_1T_reg(data)   (*((volatile unsigned int*) DC_PHY_CMD_DLY_1T_reg)=data)
#define get_DC_PHY_CMD_DLY_1T_reg   (*((volatile unsigned int*) DC_PHY_CMD_DLY_1T_reg))
#define DC_PHY_CMD_DLY_1T_inst_adr                                                   "0x00C0"
#define DC_PHY_CMD_DLY_1T_inst                                                       0x00C0
#define DC_PHY_CMD_DLY_1T_cmd_mux_sel_shift                                          (2)
#define DC_PHY_CMD_DLY_1T_cmd_mux_sel_mask                                           (0x00000004)
#define DC_PHY_CMD_DLY_1T_cmd_mux_sel(data)                                          (0x00000004&((data)<<2))
#define DC_PHY_CMD_DLY_1T_cmd_mux_sel_src(data)                                      ((0x00000004&(data))>>2)
#define DC_PHY_CMD_DLY_1T_get_cmd_mux_sel(data)                                      ((0x00000004&(data))>>2)
#define DC_PHY_CMD_DLY_1T_cmd_addr_2t_en_shift                                       (1)
#define DC_PHY_CMD_DLY_1T_cmd_addr_2t_en_mask                                        (0x00000002)
#define DC_PHY_CMD_DLY_1T_cmd_addr_2t_en(data)                                       (0x00000002&((data)<<1))
#define DC_PHY_CMD_DLY_1T_cmd_addr_2t_en_src(data)                                   ((0x00000002&(data))>>1)
#define DC_PHY_CMD_DLY_1T_get_cmd_addr_2t_en(data)                                   ((0x00000002&(data))>>1)
#define DC_PHY_CMD_DLY_1T_issue_cmd_dly_1T_shift                                     (0)
#define DC_PHY_CMD_DLY_1T_issue_cmd_dly_1T_mask                                      (0x00000001)
#define DC_PHY_CMD_DLY_1T_issue_cmd_dly_1T(data)                                     (0x00000001&((data)<<0))
#define DC_PHY_CMD_DLY_1T_issue_cmd_dly_1T_src(data)                                 ((0x00000001&(data))>>0)
#define DC_PHY_CMD_DLY_1T_get_issue_cmd_dly_1T(data)                                 ((0x00000001&(data))>>0)


#define DC_PHY_EXP_LANE_CTRL                                                         0x18008f04
#define DC_PHY_EXP_LANE_CTRL_reg_addr                                                "0xB8008F04"
#define DC_PHY_EXP_LANE_CTRL_reg                                                     0xB8008F04
#define set_DC_PHY_EXP_LANE_CTRL_reg(data)   (*((volatile unsigned int*) DC_PHY_EXP_LANE_CTRL_reg)=data)
#define get_DC_PHY_EXP_LANE_CTRL_reg   (*((volatile unsigned int*) DC_PHY_EXP_LANE_CTRL_reg))
#define DC_PHY_EXP_LANE_CTRL_inst_adr                                                "0x00C1"
#define DC_PHY_EXP_LANE_CTRL_inst                                                    0x00C1
#define DC_PHY_EXP_LANE_CTRL_write_merge_en_shift                                    (1)
#define DC_PHY_EXP_LANE_CTRL_write_merge_en_mask                                     (0x00000002)
#define DC_PHY_EXP_LANE_CTRL_write_merge_en(data)                                    (0x00000002&((data)<<1))
#define DC_PHY_EXP_LANE_CTRL_write_merge_en_src(data)                                ((0x00000002&(data))>>1)
#define DC_PHY_EXP_LANE_CTRL_get_write_merge_en(data)                                ((0x00000002&(data))>>1)
#define DC_PHY_EXP_LANE_CTRL_read_bypass_en_shift                                    (0)
#define DC_PHY_EXP_LANE_CTRL_read_bypass_en_mask                                     (0x00000001)
#define DC_PHY_EXP_LANE_CTRL_read_bypass_en(data)                                    (0x00000001&((data)<<0))
#define DC_PHY_EXP_LANE_CTRL_read_bypass_en_src(data)                                ((0x00000001&(data))>>0)
#define DC_PHY_EXP_LANE_CTRL_get_read_bypass_en(data)                                ((0x00000001&(data))>>0)


#define DC_PHY_SCPU_PC_TOTA_MON_NUM                                                  0x18008f18
#define DC_PHY_SCPU_PC_TOTA_MON_NUM_reg_addr                                         "0xB8008F18"
#define DC_PHY_SCPU_PC_TOTA_MON_NUM_reg                                              0xB8008F18
#define set_DC_PHY_SCPU_PC_TOTA_MON_NUM_reg(data)   (*((volatile unsigned int*) DC_PHY_SCPU_PC_TOTA_MON_NUM_reg)=data)
#define get_DC_PHY_SCPU_PC_TOTA_MON_NUM_reg   (*((volatile unsigned int*) DC_PHY_SCPU_PC_TOTA_MON_NUM_reg))
#define DC_PHY_SCPU_PC_TOTA_MON_NUM_inst_adr                                         "0x00C6"
#define DC_PHY_SCPU_PC_TOTA_MON_NUM_inst                                             0x00C6
#define DC_PHY_SCPU_PC_TOTA_MON_NUM_tota_mon_num_shift                               (0)
#define DC_PHY_SCPU_PC_TOTA_MON_NUM_tota_mon_num_mask                                (0xFFFFFFFF)
#define DC_PHY_SCPU_PC_TOTA_MON_NUM_tota_mon_num(data)                               (0xFFFFFFFF&((data)<<0))
#define DC_PHY_SCPU_PC_TOTA_MON_NUM_tota_mon_num_src(data)                           ((0xFFFFFFFF&(data))>>0)
#define DC_PHY_SCPU_PC_TOTA_MON_NUM_get_tota_mon_num(data)                           ((0xFFFFFFFF&(data))>>0)


#define DC_PHY_SCPU_PC_TOTA_ACK_NUM                                                  0x18008f1c
#define DC_PHY_SCPU_PC_TOTA_ACK_NUM_reg_addr                                         "0xB8008F1C"
#define DC_PHY_SCPU_PC_TOTA_ACK_NUM_reg                                              0xB8008F1C
#define set_DC_PHY_SCPU_PC_TOTA_ACK_NUM_reg(data)   (*((volatile unsigned int*) DC_PHY_SCPU_PC_TOTA_ACK_NUM_reg)=data)
#define get_DC_PHY_SCPU_PC_TOTA_ACK_NUM_reg   (*((volatile unsigned int*) DC_PHY_SCPU_PC_TOTA_ACK_NUM_reg))
#define DC_PHY_SCPU_PC_TOTA_ACK_NUM_inst_adr                                         "0x00C7"
#define DC_PHY_SCPU_PC_TOTA_ACK_NUM_inst                                             0x00C7
#define DC_PHY_SCPU_PC_TOTA_ACK_NUM_tota_ack_num_shift                               (0)
#define DC_PHY_SCPU_PC_TOTA_ACK_NUM_tota_ack_num_mask                                (0xFFFFFFFF)
#define DC_PHY_SCPU_PC_TOTA_ACK_NUM_tota_ack_num(data)                               (0xFFFFFFFF&((data)<<0))
#define DC_PHY_SCPU_PC_TOTA_ACK_NUM_tota_ack_num_src(data)                           ((0xFFFFFFFF&(data))>>0)
#define DC_PHY_SCPU_PC_TOTA_ACK_NUM_get_tota_ack_num(data)                           ((0xFFFFFFFF&(data))>>0)


#define DC_PHY_SCPU_PC_TOTA_IDL_NUM                                                  0x18008f20
#define DC_PHY_SCPU_PC_TOTA_IDL_NUM_reg_addr                                         "0xB8008F20"
#define DC_PHY_SCPU_PC_TOTA_IDL_NUM_reg                                              0xB8008F20
#define set_DC_PHY_SCPU_PC_TOTA_IDL_NUM_reg(data)   (*((volatile unsigned int*) DC_PHY_SCPU_PC_TOTA_IDL_NUM_reg)=data)
#define get_DC_PHY_SCPU_PC_TOTA_IDL_NUM_reg   (*((volatile unsigned int*) DC_PHY_SCPU_PC_TOTA_IDL_NUM_reg))
#define DC_PHY_SCPU_PC_TOTA_IDL_NUM_inst_adr                                         "0x00C8"
#define DC_PHY_SCPU_PC_TOTA_IDL_NUM_inst                                             0x00C8
#define DC_PHY_SCPU_PC_TOTA_IDL_NUM_tota_idl_num_shift                               (0)
#define DC_PHY_SCPU_PC_TOTA_IDL_NUM_tota_idl_num_mask                                (0xFFFFFFFF)
#define DC_PHY_SCPU_PC_TOTA_IDL_NUM_tota_idl_num(data)                               (0xFFFFFFFF&((data)<<0))
#define DC_PHY_SCPU_PC_TOTA_IDL_NUM_tota_idl_num_src(data)                           ((0xFFFFFFFF&(data))>>0)
#define DC_PHY_SCPU_PC_TOTA_IDL_NUM_get_tota_idl_num(data)                           ((0xFFFFFFFF&(data))>>0)


#define DC_PHY_SCPU_PC_ACC_LAT                                                       0x18008f24
#define DC_PHY_SCPU_PC_ACC_LAT_reg_addr                                              "0xB8008F24"
#define DC_PHY_SCPU_PC_ACC_LAT_reg                                                   0xB8008F24
#define set_DC_PHY_SCPU_PC_ACC_LAT_reg(data)   (*((volatile unsigned int*) DC_PHY_SCPU_PC_ACC_LAT_reg)=data)
#define get_DC_PHY_SCPU_PC_ACC_LAT_reg   (*((volatile unsigned int*) DC_PHY_SCPU_PC_ACC_LAT_reg))
#define DC_PHY_SCPU_PC_ACC_LAT_inst_adr                                              "0x00C9"
#define DC_PHY_SCPU_PC_ACC_LAT_inst                                                  0x00C9
#define DC_PHY_SCPU_PC_ACC_LAT_acc_lat_shift                                         (0)
#define DC_PHY_SCPU_PC_ACC_LAT_acc_lat_mask                                          (0xFFFFFFFF)
#define DC_PHY_SCPU_PC_ACC_LAT_acc_lat(data)                                         (0xFFFFFFFF&((data)<<0))
#define DC_PHY_SCPU_PC_ACC_LAT_acc_lat_src(data)                                     ((0xFFFFFFFF&(data))>>0)
#define DC_PHY_SCPU_PC_ACC_LAT_get_acc_lat(data)                                     ((0xFFFFFFFF&(data))>>0)


#define DC_PHY_SCPU_PC_MAX_LAT                                                       0x18008f28
#define DC_PHY_SCPU_PC_MAX_LAT_reg_addr                                              "0xB8008F28"
#define DC_PHY_SCPU_PC_MAX_LAT_reg                                                   0xB8008F28
#define set_DC_PHY_SCPU_PC_MAX_LAT_reg(data)   (*((volatile unsigned int*) DC_PHY_SCPU_PC_MAX_LAT_reg)=data)
#define get_DC_PHY_SCPU_PC_MAX_LAT_reg   (*((volatile unsigned int*) DC_PHY_SCPU_PC_MAX_LAT_reg))
#define DC_PHY_SCPU_PC_MAX_LAT_inst_adr                                              "0x00CA"
#define DC_PHY_SCPU_PC_MAX_LAT_inst                                                  0x00CA
#define DC_PHY_SCPU_PC_MAX_LAT_max_lat_shift                                         (0)
#define DC_PHY_SCPU_PC_MAX_LAT_max_lat_mask                                          (0x0000FFFF)
#define DC_PHY_SCPU_PC_MAX_LAT_max_lat(data)                                         (0x0000FFFF&((data)<<0))
#define DC_PHY_SCPU_PC_MAX_LAT_max_lat_src(data)                                     ((0x0000FFFF&(data))>>0)
#define DC_PHY_SCPU_PC_MAX_LAT_get_max_lat(data)                                     ((0x0000FFFF&(data))>>0)


#define DC_PHY_SCPU_PC_REQ_NUM                                                       0x18008f2c
#define DC_PHY_SCPU_PC_REQ_NUM_reg_addr                                              "0xB8008F2C"
#define DC_PHY_SCPU_PC_REQ_NUM_reg                                                   0xB8008F2C
#define set_DC_PHY_SCPU_PC_REQ_NUM_reg(data)   (*((volatile unsigned int*) DC_PHY_SCPU_PC_REQ_NUM_reg)=data)
#define get_DC_PHY_SCPU_PC_REQ_NUM_reg   (*((volatile unsigned int*) DC_PHY_SCPU_PC_REQ_NUM_reg))
#define DC_PHY_SCPU_PC_REQ_NUM_inst_adr                                              "0x00CB"
#define DC_PHY_SCPU_PC_REQ_NUM_inst                                                  0x00CB
#define DC_PHY_SCPU_PC_REQ_NUM_req_num_shift                                         (0)
#define DC_PHY_SCPU_PC_REQ_NUM_req_num_mask                                          (0x00FFFFFF)
#define DC_PHY_SCPU_PC_REQ_NUM_req_num(data)                                         (0x00FFFFFF&((data)<<0))
#define DC_PHY_SCPU_PC_REQ_NUM_req_num_src(data)                                     ((0x00FFFFFF&(data))>>0)
#define DC_PHY_SCPU_PC_REQ_NUM_get_req_num(data)                                     ((0x00FFFFFF&(data))>>0)


#define DC_PHY_SCPU_PC_ACK_NUM                                                       0x18008f30
#define DC_PHY_SCPU_PC_ACK_NUM_reg_addr                                              "0xB8008F30"
#define DC_PHY_SCPU_PC_ACK_NUM_reg                                                   0xB8008F30
#define set_DC_PHY_SCPU_PC_ACK_NUM_reg(data)   (*((volatile unsigned int*) DC_PHY_SCPU_PC_ACK_NUM_reg)=data)
#define get_DC_PHY_SCPU_PC_ACK_NUM_reg   (*((volatile unsigned int*) DC_PHY_SCPU_PC_ACK_NUM_reg))
#define DC_PHY_SCPU_PC_ACK_NUM_inst_adr                                              "0x00CC"
#define DC_PHY_SCPU_PC_ACK_NUM_inst                                                  0x00CC
#define DC_PHY_SCPU_PC_ACK_NUM_ack_num_shift                                         (0)
#define DC_PHY_SCPU_PC_ACK_NUM_ack_num_mask                                          (0xFFFFFFFF)
#define DC_PHY_SCPU_PC_ACK_NUM_ack_num(data)                                         (0xFFFFFFFF&((data)<<0))
#define DC_PHY_SCPU_PC_ACK_NUM_ack_num_src(data)                                     ((0xFFFFFFFF&(data))>>0)
#define DC_PHY_SCPU_PC_ACK_NUM_get_ack_num(data)                                     ((0xFFFFFFFF&(data))>>0)


#define DC_PHY_SCPU_PC_CTRL                                                          0x18008f34
#define DC_PHY_SCPU_PC_CTRL_reg_addr                                                 "0xB8008F34"
#define DC_PHY_SCPU_PC_CTRL_reg                                                      0xB8008F34
#define set_DC_PHY_SCPU_PC_CTRL_reg(data)   (*((volatile unsigned int*) DC_PHY_SCPU_PC_CTRL_reg)=data)
#define get_DC_PHY_SCPU_PC_CTRL_reg   (*((volatile unsigned int*) DC_PHY_SCPU_PC_CTRL_reg))
#define DC_PHY_SCPU_PC_CTRL_inst_adr                                                 "0x00CD"
#define DC_PHY_SCPU_PC_CTRL_inst                                                     0x00CD
#define DC_PHY_SCPU_PC_CTRL_pc_go_shift                                              (0)
#define DC_PHY_SCPU_PC_CTRL_pc_go_mask                                               (0x00000001)
#define DC_PHY_SCPU_PC_CTRL_pc_go(data)                                              (0x00000001&((data)<<0))
#define DC_PHY_SCPU_PC_CTRL_pc_go_src(data)                                          ((0x00000001&(data))>>0)
#define DC_PHY_SCPU_PC_CTRL_get_pc_go(data)                                          ((0x00000001&(data))>>0)


#define DC_PHY_GCK_CTRL                                                              0x18008f38
#define DC_PHY_GCK_CTRL_reg_addr                                                     "0xB8008F38"
#define DC_PHY_GCK_CTRL_reg                                                          0xB8008F38
#define set_DC_PHY_GCK_CTRL_reg(data)   (*((volatile unsigned int*) DC_PHY_GCK_CTRL_reg)=data)
#define get_DC_PHY_GCK_CTRL_reg   (*((volatile unsigned int*) DC_PHY_GCK_CTRL_reg))
#define DC_PHY_GCK_CTRL_inst_adr                                                     "0x00CE"
#define DC_PHY_GCK_CTRL_inst                                                         0x00CE
#define DC_PHY_GCK_CTRL_gck_ext_cyc_shift                                            (8)
#define DC_PHY_GCK_CTRL_gck_ext_cyc_mask                                             (0x00003F00)
#define DC_PHY_GCK_CTRL_gck_ext_cyc(data)                                            (0x00003F00&((data)<<8))
#define DC_PHY_GCK_CTRL_gck_ext_cyc_src(data)                                        ((0x00003F00&(data))>>8)
#define DC_PHY_GCK_CTRL_get_gck_ext_cyc(data)                                        ((0x00003F00&(data))>>8)
#define DC_PHY_GCK_CTRL_par_gck_en_shift                                             (2)
#define DC_PHY_GCK_CTRL_par_gck_en_mask                                              (0x00000004)
#define DC_PHY_GCK_CTRL_par_gck_en(data)                                             (0x00000004&((data)<<2))
#define DC_PHY_GCK_CTRL_par_gck_en_src(data)                                         ((0x00000004&(data))>>2)
#define DC_PHY_GCK_CTRL_get_par_gck_en(data)                                         ((0x00000004&(data))>>2)
#define DC_PHY_GCK_CTRL_fsm_gck_en_shift                                             (1)
#define DC_PHY_GCK_CTRL_fsm_gck_en_mask                                              (0x00000002)
#define DC_PHY_GCK_CTRL_fsm_gck_en(data)                                             (0x00000002&((data)<<1))
#define DC_PHY_GCK_CTRL_fsm_gck_en_src(data)                                         ((0x00000002&(data))>>1)
#define DC_PHY_GCK_CTRL_get_fsm_gck_en(data)                                         ((0x00000002&(data))>>1)
#define DC_PHY_GCK_CTRL_ioblk_gck_en_shift                                           (0)
#define DC_PHY_GCK_CTRL_ioblk_gck_en_mask                                            (0x00000001)
#define DC_PHY_GCK_CTRL_ioblk_gck_en(data)                                           (0x00000001&((data)<<0))
#define DC_PHY_GCK_CTRL_ioblk_gck_en_src(data)                                       ((0x00000001&(data))>>0)
#define DC_PHY_GCK_CTRL_get_ioblk_gck_en(data)                                       ((0x00000001&(data))>>0)


#define DC_PHY_SCPU_LEAKY_BUCKET_CTRL_0                                              0x18008f3c
#define DC_PHY_SCPU_LEAKY_BUCKET_CTRL_0_reg_addr                                     "0xB8008F3C"
#define DC_PHY_SCPU_LEAKY_BUCKET_CTRL_0_reg                                          0xB8008F3C
#define set_DC_PHY_SCPU_LEAKY_BUCKET_CTRL_0_reg(data)   (*((volatile unsigned int*) DC_PHY_SCPU_LEAKY_BUCKET_CTRL_0_reg)=data)
#define get_DC_PHY_SCPU_LEAKY_BUCKET_CTRL_0_reg   (*((volatile unsigned int*) DC_PHY_SCPU_LEAKY_BUCKET_CTRL_0_reg))
#define DC_PHY_SCPU_LEAKY_BUCKET_CTRL_0_inst_adr                                     "0x00CF"
#define DC_PHY_SCPU_LEAKY_BUCKET_CTRL_0_inst                                         0x00CF
#define DC_PHY_SCPU_LEAKY_BUCKET_CTRL_0_enable_shift                                 (0)
#define DC_PHY_SCPU_LEAKY_BUCKET_CTRL_0_enable_mask                                  (0x00000001)
#define DC_PHY_SCPU_LEAKY_BUCKET_CTRL_0_enable(data)                                 (0x00000001&((data)<<0))
#define DC_PHY_SCPU_LEAKY_BUCKET_CTRL_0_enable_src(data)                             ((0x00000001&(data))>>0)
#define DC_PHY_SCPU_LEAKY_BUCKET_CTRL_0_get_enable(data)                             ((0x00000001&(data))>>0)


#define DC_PHY_SCPU_LEAKY_BUCKET_CTRL_1                                              0x18008f40
#define DC_PHY_SCPU_LEAKY_BUCKET_CTRL_1_reg_addr                                     "0xB8008F40"
#define DC_PHY_SCPU_LEAKY_BUCKET_CTRL_1_reg                                          0xB8008F40
#define set_DC_PHY_SCPU_LEAKY_BUCKET_CTRL_1_reg(data)   (*((volatile unsigned int*) DC_PHY_SCPU_LEAKY_BUCKET_CTRL_1_reg)=data)
#define get_DC_PHY_SCPU_LEAKY_BUCKET_CTRL_1_reg   (*((volatile unsigned int*) DC_PHY_SCPU_LEAKY_BUCKET_CTRL_1_reg))
#define DC_PHY_SCPU_LEAKY_BUCKET_CTRL_1_inst_adr                                     "0x00D0"
#define DC_PHY_SCPU_LEAKY_BUCKET_CTRL_1_inst                                         0x00D0
#define DC_PHY_SCPU_LEAKY_BUCKET_CTRL_1_timer_threshold_shift                        (0)
#define DC_PHY_SCPU_LEAKY_BUCKET_CTRL_1_timer_threshold_mask                         (0xFFFFFFFF)
#define DC_PHY_SCPU_LEAKY_BUCKET_CTRL_1_timer_threshold(data)                        (0xFFFFFFFF&((data)<<0))
#define DC_PHY_SCPU_LEAKY_BUCKET_CTRL_1_timer_threshold_src(data)                    ((0xFFFFFFFF&(data))>>0)
#define DC_PHY_SCPU_LEAKY_BUCKET_CTRL_1_get_timer_threshold(data)                    ((0xFFFFFFFF&(data))>>0)


#define DC_PHY_SCPU_LEAKY_BUCKET_CTRL_2                                              0x18008f44
#define DC_PHY_SCPU_LEAKY_BUCKET_CTRL_2_reg_addr                                     "0xB8008F44"
#define DC_PHY_SCPU_LEAKY_BUCKET_CTRL_2_reg                                          0xB8008F44
#define set_DC_PHY_SCPU_LEAKY_BUCKET_CTRL_2_reg(data)   (*((volatile unsigned int*) DC_PHY_SCPU_LEAKY_BUCKET_CTRL_2_reg)=data)
#define get_DC_PHY_SCPU_LEAKY_BUCKET_CTRL_2_reg   (*((volatile unsigned int*) DC_PHY_SCPU_LEAKY_BUCKET_CTRL_2_reg))
#define DC_PHY_SCPU_LEAKY_BUCKET_CTRL_2_inst_adr                                     "0x00D1"
#define DC_PHY_SCPU_LEAKY_BUCKET_CTRL_2_inst                                         0x00D1
#define DC_PHY_SCPU_LEAKY_BUCKET_CTRL_2_count_threshold_shift                        (0)
#define DC_PHY_SCPU_LEAKY_BUCKET_CTRL_2_count_threshold_mask                         (0x00FFFFFF)
#define DC_PHY_SCPU_LEAKY_BUCKET_CTRL_2_count_threshold(data)                        (0x00FFFFFF&((data)<<0))
#define DC_PHY_SCPU_LEAKY_BUCKET_CTRL_2_count_threshold_src(data)                    ((0x00FFFFFF&(data))>>0)
#define DC_PHY_SCPU_LEAKY_BUCKET_CTRL_2_get_count_threshold(data)                    ((0x00FFFFFF&(data))>>0)


#define DC_PHY_SCPU_PC_MERGE_NUM                                                     0x18008f48
#define DC_PHY_SCPU_PC_MERGE_NUM_reg_addr                                            "0xB8008F48"
#define DC_PHY_SCPU_PC_MERGE_NUM_reg                                                 0xB8008F48
#define set_DC_PHY_SCPU_PC_MERGE_NUM_reg(data)   (*((volatile unsigned int*) DC_PHY_SCPU_PC_MERGE_NUM_reg)=data)
#define get_DC_PHY_SCPU_PC_MERGE_NUM_reg   (*((volatile unsigned int*) DC_PHY_SCPU_PC_MERGE_NUM_reg))
#define DC_PHY_SCPU_PC_MERGE_NUM_inst_adr                                            "0x00D2"
#define DC_PHY_SCPU_PC_MERGE_NUM_inst                                                0x00D2
#define DC_PHY_SCPU_PC_MERGE_NUM_merge_num_shift                                     (0)
#define DC_PHY_SCPU_PC_MERGE_NUM_merge_num_mask                                      (0x00FFFFFF)
#define DC_PHY_SCPU_PC_MERGE_NUM_merge_num(data)                                     (0x00FFFFFF&((data)<<0))
#define DC_PHY_SCPU_PC_MERGE_NUM_merge_num_src(data)                                 ((0x00FFFFFF&(data))>>0)
#define DC_PHY_SCPU_PC_MERGE_NUM_get_merge_num(data)                                 ((0x00FFFFFF&(data))>>0)


#define DC_PHY_SCPU_PC_WR_REQ_NUM                                                    0x18008f4c
#define DC_PHY_SCPU_PC_WR_REQ_NUM_reg_addr                                           "0xB8008F4C"
#define DC_PHY_SCPU_PC_WR_REQ_NUM_reg                                                0xB8008F4C
#define set_DC_PHY_SCPU_PC_WR_REQ_NUM_reg(data)   (*((volatile unsigned int*) DC_PHY_SCPU_PC_WR_REQ_NUM_reg)=data)
#define get_DC_PHY_SCPU_PC_WR_REQ_NUM_reg   (*((volatile unsigned int*) DC_PHY_SCPU_PC_WR_REQ_NUM_reg))
#define DC_PHY_SCPU_PC_WR_REQ_NUM_inst_adr                                           "0x00D3"
#define DC_PHY_SCPU_PC_WR_REQ_NUM_inst                                               0x00D3
#define DC_PHY_SCPU_PC_WR_REQ_NUM_wr_req_num_shift                                   (0)
#define DC_PHY_SCPU_PC_WR_REQ_NUM_wr_req_num_mask                                    (0x00FFFFFF)
#define DC_PHY_SCPU_PC_WR_REQ_NUM_wr_req_num(data)                                   (0x00FFFFFF&((data)<<0))
#define DC_PHY_SCPU_PC_WR_REQ_NUM_wr_req_num_src(data)                               ((0x00FFFFFF&(data))>>0)
#define DC_PHY_SCPU_PC_WR_REQ_NUM_get_wr_req_num(data)                               ((0x00FFFFFF&(data))>>0)


#define DC_PHY_SPEED_SENSOR_CTRL                                                     0x18008f50
#define DC_PHY_SPEED_SENSOR_CTRL_reg_addr                                            "0xB8008F50"
#define DC_PHY_SPEED_SENSOR_CTRL_reg                                                 0xB8008F50
#define set_DC_PHY_SPEED_SENSOR_CTRL_reg(data)   (*((volatile unsigned int*) DC_PHY_SPEED_SENSOR_CTRL_reg)=data)
#define get_DC_PHY_SPEED_SENSOR_CTRL_reg   (*((volatile unsigned int*) DC_PHY_SPEED_SENSOR_CTRL_reg))
#define DC_PHY_SPEED_SENSOR_CTRL_inst_adr                                            "0x00D4"
#define DC_PHY_SPEED_SENSOR_CTRL_inst                                                0x00D4
#define DC_PHY_SPEED_SENSOR_CTRL_data_in_shift                                       (8)
#define DC_PHY_SPEED_SENSOR_CTRL_data_in_mask                                        (0x0FFFFF00)
#define DC_PHY_SPEED_SENSOR_CTRL_data_in(data)                                       (0x0FFFFF00&((data)<<8))
#define DC_PHY_SPEED_SENSOR_CTRL_data_in_src(data)                                   ((0x0FFFFF00&(data))>>8)
#define DC_PHY_SPEED_SENSOR_CTRL_get_data_in(data)                                   ((0x0FFFFF00&(data))>>8)
#define DC_PHY_SPEED_SENSOR_CTRL_speed_en_shift                                      (6)
#define DC_PHY_SPEED_SENSOR_CTRL_speed_en_mask                                       (0x00000040)
#define DC_PHY_SPEED_SENSOR_CTRL_speed_en(data)                                      (0x00000040&((data)<<6))
#define DC_PHY_SPEED_SENSOR_CTRL_speed_en_src(data)                                  ((0x00000040&(data))>>6)
#define DC_PHY_SPEED_SENSOR_CTRL_get_speed_en(data)                                  ((0x00000040&(data))>>6)
#define DC_PHY_SPEED_SENSOR_CTRL_data_in_ready_shift                                 (5)
#define DC_PHY_SPEED_SENSOR_CTRL_data_in_ready_mask                                  (0x00000020)
#define DC_PHY_SPEED_SENSOR_CTRL_data_in_ready(data)                                 (0x00000020&((data)<<5))
#define DC_PHY_SPEED_SENSOR_CTRL_data_in_ready_src(data)                             ((0x00000020&(data))>>5)
#define DC_PHY_SPEED_SENSOR_CTRL_get_data_in_ready(data)                             ((0x00000020&(data))>>5)
#define DC_PHY_SPEED_SENSOR_CTRL_wire_sel_shift                                      (4)
#define DC_PHY_SPEED_SENSOR_CTRL_wire_sel_mask                                       (0x00000010)
#define DC_PHY_SPEED_SENSOR_CTRL_wire_sel(data)                                      (0x00000010&((data)<<4))
#define DC_PHY_SPEED_SENSOR_CTRL_wire_sel_src(data)                                  ((0x00000010&(data))>>4)
#define DC_PHY_SPEED_SENSOR_CTRL_get_wire_sel(data)                                  ((0x00000010&(data))>>4)
#define DC_PHY_SPEED_SENSOR_CTRL_ro_sel_shift                                        (1)
#define DC_PHY_SPEED_SENSOR_CTRL_ro_sel_mask                                         (0x0000000E)
#define DC_PHY_SPEED_SENSOR_CTRL_ro_sel(data)                                        (0x0000000E&((data)<<1))
#define DC_PHY_SPEED_SENSOR_CTRL_ro_sel_src(data)                                    ((0x0000000E&(data))>>1)
#define DC_PHY_SPEED_SENSOR_CTRL_get_ro_sel(data)                                    ((0x0000000E&(data))>>1)
#define DC_PHY_SPEED_SENSOR_CTRL_dss_rst_n_shift                                     (0)
#define DC_PHY_SPEED_SENSOR_CTRL_dss_rst_n_mask                                      (0x00000001)
#define DC_PHY_SPEED_SENSOR_CTRL_dss_rst_n(data)                                     (0x00000001&((data)<<0))
#define DC_PHY_SPEED_SENSOR_CTRL_dss_rst_n_src(data)                                 ((0x00000001&(data))>>0)
#define DC_PHY_SPEED_SENSOR_CTRL_get_dss_rst_n(data)                                 ((0x00000001&(data))>>0)


#define DC_PHY_SPEED_SENSOR_STATUS                                                   0x18008f54
#define DC_PHY_SPEED_SENSOR_STATUS_reg_addr                                          "0xB8008F54"
#define DC_PHY_SPEED_SENSOR_STATUS_reg                                               0xB8008F54
#define set_DC_PHY_SPEED_SENSOR_STATUS_reg(data)   (*((volatile unsigned int*) DC_PHY_SPEED_SENSOR_STATUS_reg)=data)
#define get_DC_PHY_SPEED_SENSOR_STATUS_reg   (*((volatile unsigned int*) DC_PHY_SPEED_SENSOR_STATUS_reg))
#define DC_PHY_SPEED_SENSOR_STATUS_inst_adr                                          "0x00D5"
#define DC_PHY_SPEED_SENSOR_STATUS_inst                                              0x00D5
#define DC_PHY_SPEED_SENSOR_STATUS_count_out_shift                                   (4)
#define DC_PHY_SPEED_SENSOR_STATUS_count_out_mask                                    (0x00FFFFF0)
#define DC_PHY_SPEED_SENSOR_STATUS_count_out(data)                                   (0x00FFFFF0&((data)<<4))
#define DC_PHY_SPEED_SENSOR_STATUS_count_out_src(data)                               ((0x00FFFFF0&(data))>>4)
#define DC_PHY_SPEED_SENSOR_STATUS_get_count_out(data)                               ((0x00FFFFF0&(data))>>4)
#define DC_PHY_SPEED_SENSOR_STATUS_wsort_go_shift                                    (1)
#define DC_PHY_SPEED_SENSOR_STATUS_wsort_go_mask                                     (0x00000002)
#define DC_PHY_SPEED_SENSOR_STATUS_wsort_go(data)                                    (0x00000002&((data)<<1))
#define DC_PHY_SPEED_SENSOR_STATUS_wsort_go_src(data)                                ((0x00000002&(data))>>1)
#define DC_PHY_SPEED_SENSOR_STATUS_get_wsort_go(data)                                ((0x00000002&(data))>>1)
#define DC_PHY_SPEED_SENSOR_STATUS_ready_shift                                       (0)
#define DC_PHY_SPEED_SENSOR_STATUS_ready_mask                                        (0x00000001)
#define DC_PHY_SPEED_SENSOR_STATUS_ready(data)                                       (0x00000001&((data)<<0))
#define DC_PHY_SPEED_SENSOR_STATUS_ready_src(data)                                   ((0x00000001&(data))>>0)
#define DC_PHY_SPEED_SENSOR_STATUS_get_ready(data)                                   ((0x00000001&(data))>>0)


#define DC_PHY_EXPRESS_LANE_CTRL_MISC                                                0x18008f58
#define DC_PHY_EXPRESS_LANE_CTRL_MISC_reg_addr                                       "0xB8008F58"
#define DC_PHY_EXPRESS_LANE_CTRL_MISC_reg                                            0xB8008F58
#define set_DC_PHY_EXPRESS_LANE_CTRL_MISC_reg(data)   (*((volatile unsigned int*) DC_PHY_EXPRESS_LANE_CTRL_MISC_reg)=data)
#define get_DC_PHY_EXPRESS_LANE_CTRL_MISC_reg   (*((volatile unsigned int*) DC_PHY_EXPRESS_LANE_CTRL_MISC_reg))
#define DC_PHY_EXPRESS_LANE_CTRL_MISC_inst_adr                                       "0x00D6"
#define DC_PHY_EXPRESS_LANE_CTRL_MISC_inst                                           0x00D6
#define DC_PHY_EXPRESS_LANE_CTRL_MISC_ctrl_misc_shift                                (0)
#define DC_PHY_EXPRESS_LANE_CTRL_MISC_ctrl_misc_mask                                 (0xFFFFFFFF)
#define DC_PHY_EXPRESS_LANE_CTRL_MISC_ctrl_misc(data)                                (0xFFFFFFFF&((data)<<0))
#define DC_PHY_EXPRESS_LANE_CTRL_MISC_ctrl_misc_src(data)                            ((0xFFFFFFFF&(data))>>0)
#define DC_PHY_EXPRESS_LANE_CTRL_MISC_get_ctrl_misc(data)                            ((0xFFFFFFFF&(data))>>0)


#define DC_PHY_DEBUG01                                                               0x18008F64
#define DC_PHY_DEBUG01_reg_addr                                                      "0xB8008F64"
#define DC_PHY_DEBUG01_reg                                                           0xB8008F64
#define set_DC_PHY_DEBUG01_reg(data)   (*((volatile unsigned int*) DC_PHY_DEBUG01_reg)=data)
#define get_DC_PHY_DEBUG01_reg   (*((volatile unsigned int*) DC_PHY_DEBUG01_reg))
#define DC_PHY_DEBUG01_inst_adr                                                      "0x00D9"
#define DC_PHY_DEBUG01_inst                                                          0x00D9
#define DC_PHY_DEBUG01_dc_dbg_out1_shift                                             (16)
#define DC_PHY_DEBUG01_dc_dbg_out1_mask                                              (0xFFFF0000)
#define DC_PHY_DEBUG01_dc_dbg_out1(data)                                             (0xFFFF0000&((data)<<16))
#define DC_PHY_DEBUG01_dc_dbg_out1_src(data)                                         ((0xFFFF0000&(data))>>16)
#define DC_PHY_DEBUG01_get_dc_dbg_out1(data)                                         ((0xFFFF0000&(data))>>16)
#define DC_PHY_DEBUG01_dc_dbg_out0_shift                                             (0)
#define DC_PHY_DEBUG01_dc_dbg_out0_mask                                              (0x0000FFFF)
#define DC_PHY_DEBUG01_dc_dbg_out0(data)                                             (0x0000FFFF&((data)<<0))
#define DC_PHY_DEBUG01_dc_dbg_out0_src(data)                                         ((0x0000FFFF&(data))>>0)
#define DC_PHY_DEBUG01_get_dc_dbg_out0(data)                                         ((0x0000FFFF&(data))>>0)


#define DC_PHY_DEBUG23                                                               0x18008F68
#define DC_PHY_DEBUG23_reg_addr                                                      "0xB8008F68"
#define DC_PHY_DEBUG23_reg                                                           0xB8008F68
#define set_DC_PHY_DEBUG23_reg(data)   (*((volatile unsigned int*) DC_PHY_DEBUG23_reg)=data)
#define get_DC_PHY_DEBUG23_reg   (*((volatile unsigned int*) DC_PHY_DEBUG23_reg))
#define DC_PHY_DEBUG23_inst_adr                                                      "0x00DA"
#define DC_PHY_DEBUG23_inst                                                          0x00DA
#define DC_PHY_DEBUG23_dc_dbg_out3_shift                                             (16)
#define DC_PHY_DEBUG23_dc_dbg_out3_mask                                              (0xFFFF0000)
#define DC_PHY_DEBUG23_dc_dbg_out3(data)                                             (0xFFFF0000&((data)<<16))
#define DC_PHY_DEBUG23_dc_dbg_out3_src(data)                                         ((0xFFFF0000&(data))>>16)
#define DC_PHY_DEBUG23_get_dc_dbg_out3(data)                                         ((0xFFFF0000&(data))>>16)
#define DC_PHY_DEBUG23_dc_dbg_out2_shift                                             (0)
#define DC_PHY_DEBUG23_dc_dbg_out2_mask                                              (0x0000FFFF)
#define DC_PHY_DEBUG23_dc_dbg_out2(data)                                             (0x0000FFFF&((data)<<0))
#define DC_PHY_DEBUG23_dc_dbg_out2_src(data)                                         ((0x0000FFFF&(data))>>0)
#define DC_PHY_DEBUG23_get_dc_dbg_out2(data)                                         ((0x0000FFFF&(data))>>0)


#define DC_PHY_DC_PHY_BIST_MODE                                                      0x18008FC0
#define DC_PHY_DC_PHY_BIST_MODE_reg_addr                                             "0xB8008FC0"
#define DC_PHY_DC_PHY_BIST_MODE_reg                                                  0xB8008FC0
#define set_DC_PHY_DC_PHY_BIST_MODE_reg(data)   (*((volatile unsigned int*) DC_PHY_DC_PHY_BIST_MODE_reg)=data)
#define get_DC_PHY_DC_PHY_BIST_MODE_reg   (*((volatile unsigned int*) DC_PHY_DC_PHY_BIST_MODE_reg))
#define DC_PHY_DC_PHY_BIST_MODE_inst_adr                                             "0x00F0"
#define DC_PHY_DC_PHY_BIST_MODE_inst                                                 0x00F0
#define DC_PHY_DC_PHY_BIST_MODE_DC_PHY_BIST_CLKSEL_shift                             (8)
#define DC_PHY_DC_PHY_BIST_MODE_DC_PHY_BIST_CLKSEL_mask                              (0x00000100)
#define DC_PHY_DC_PHY_BIST_MODE_DC_PHY_BIST_CLKSEL(data)                             (0x00000100&((data)<<8))
#define DC_PHY_DC_PHY_BIST_MODE_DC_PHY_BIST_CLKSEL_src(data)                         ((0x00000100&(data))>>8)
#define DC_PHY_DC_PHY_BIST_MODE_get_DC_PHY_BIST_CLKSEL(data)                         ((0x00000100&(data))>>8)
#define DC_PHY_DC_PHY_BIST_MODE_DC_PHY_BIST_MODE_3_shift                             (7)
#define DC_PHY_DC_PHY_BIST_MODE_DC_PHY_BIST_MODE_3_mask                              (0x00000080)
#define DC_PHY_DC_PHY_BIST_MODE_DC_PHY_BIST_MODE_3(data)                             (0x00000080&((data)<<7))
#define DC_PHY_DC_PHY_BIST_MODE_DC_PHY_BIST_MODE_3_src(data)                         ((0x00000080&(data))>>7)
#define DC_PHY_DC_PHY_BIST_MODE_get_DC_PHY_BIST_MODE_3(data)                         ((0x00000080&(data))>>7)
#define DC_PHY_DC_PHY_BIST_MODE_DC_PHY_BIST_MODE_2_shift                             (6)
#define DC_PHY_DC_PHY_BIST_MODE_DC_PHY_BIST_MODE_2_mask                              (0x00000040)
#define DC_PHY_DC_PHY_BIST_MODE_DC_PHY_BIST_MODE_2(data)                             (0x00000040&((data)<<6))
#define DC_PHY_DC_PHY_BIST_MODE_DC_PHY_BIST_MODE_2_src(data)                         ((0x00000040&(data))>>6)
#define DC_PHY_DC_PHY_BIST_MODE_get_DC_PHY_BIST_MODE_2(data)                         ((0x00000040&(data))>>6)
#define DC_PHY_DC_PHY_BIST_MODE_DC_PHY_PTG_BIST_MODE_3_shift                         (5)
#define DC_PHY_DC_PHY_BIST_MODE_DC_PHY_PTG_BIST_MODE_3_mask                          (0x00000020)
#define DC_PHY_DC_PHY_BIST_MODE_DC_PHY_PTG_BIST_MODE_3(data)                         (0x00000020&((data)<<5))
#define DC_PHY_DC_PHY_BIST_MODE_DC_PHY_PTG_BIST_MODE_3_src(data)                     ((0x00000020&(data))>>5)
#define DC_PHY_DC_PHY_BIST_MODE_get_DC_PHY_PTG_BIST_MODE_3(data)                     ((0x00000020&(data))>>5)
#define DC_PHY_DC_PHY_BIST_MODE_DC_PHY_PTG_BIST_MODE_2_shift                         (4)
#define DC_PHY_DC_PHY_BIST_MODE_DC_PHY_PTG_BIST_MODE_2_mask                          (0x00000010)
#define DC_PHY_DC_PHY_BIST_MODE_DC_PHY_PTG_BIST_MODE_2(data)                         (0x00000010&((data)<<4))
#define DC_PHY_DC_PHY_BIST_MODE_DC_PHY_PTG_BIST_MODE_2_src(data)                     ((0x00000010&(data))>>4)
#define DC_PHY_DC_PHY_BIST_MODE_get_DC_PHY_PTG_BIST_MODE_2(data)                     ((0x00000010&(data))>>4)
#define DC_PHY_DC_PHY_BIST_MODE_DC_PHY_PTG_BIST_MODE_1_shift                         (3)
#define DC_PHY_DC_PHY_BIST_MODE_DC_PHY_PTG_BIST_MODE_1_mask                          (0x00000008)
#define DC_PHY_DC_PHY_BIST_MODE_DC_PHY_PTG_BIST_MODE_1(data)                         (0x00000008&((data)<<3))
#define DC_PHY_DC_PHY_BIST_MODE_DC_PHY_PTG_BIST_MODE_1_src(data)                     ((0x00000008&(data))>>3)
#define DC_PHY_DC_PHY_BIST_MODE_get_DC_PHY_PTG_BIST_MODE_1(data)                     ((0x00000008&(data))>>3)
#define DC_PHY_DC_PHY_BIST_MODE_DC_PHY_PTG_BIST_MODE_0_shift                         (2)
#define DC_PHY_DC_PHY_BIST_MODE_DC_PHY_PTG_BIST_MODE_0_mask                          (0x00000004)
#define DC_PHY_DC_PHY_BIST_MODE_DC_PHY_PTG_BIST_MODE_0(data)                         (0x00000004&((data)<<2))
#define DC_PHY_DC_PHY_BIST_MODE_DC_PHY_PTG_BIST_MODE_0_src(data)                     ((0x00000004&(data))>>2)
#define DC_PHY_DC_PHY_BIST_MODE_get_DC_PHY_PTG_BIST_MODE_0(data)                     ((0x00000004&(data))>>2)
#define DC_PHY_DC_PHY_BIST_MODE_DC_PHY_BIST_MODE_0_shift                             (1)
#define DC_PHY_DC_PHY_BIST_MODE_DC_PHY_BIST_MODE_0_mask                              (0x00000002)
#define DC_PHY_DC_PHY_BIST_MODE_DC_PHY_BIST_MODE_0(data)                             (0x00000002&((data)<<1))
#define DC_PHY_DC_PHY_BIST_MODE_DC_PHY_BIST_MODE_0_src(data)                         ((0x00000002&(data))>>1)
#define DC_PHY_DC_PHY_BIST_MODE_get_DC_PHY_BIST_MODE_0(data)                         ((0x00000002&(data))>>1)
#define DC_PHY_DC_PHY_BIST_MODE_DC_PHY_BIST_MODE_1_shift                             (0)
#define DC_PHY_DC_PHY_BIST_MODE_DC_PHY_BIST_MODE_1_mask                              (0x00000001)
#define DC_PHY_DC_PHY_BIST_MODE_DC_PHY_BIST_MODE_1(data)                             (0x00000001&((data)<<0))
#define DC_PHY_DC_PHY_BIST_MODE_DC_PHY_BIST_MODE_1_src(data)                         ((0x00000001&(data))>>0)
#define DC_PHY_DC_PHY_BIST_MODE_get_DC_PHY_BIST_MODE_1(data)                         ((0x00000001&(data))>>0)


#define DC_PHY_DC_PHY_BIST_DONE                                                      0x18008FC4
#define DC_PHY_DC_PHY_BIST_DONE_reg_addr                                             "0xB8008FC4"
#define DC_PHY_DC_PHY_BIST_DONE_reg                                                  0xB8008FC4
#define set_DC_PHY_DC_PHY_BIST_DONE_reg(data)   (*((volatile unsigned int*) DC_PHY_DC_PHY_BIST_DONE_reg)=data)
#define get_DC_PHY_DC_PHY_BIST_DONE_reg   (*((volatile unsigned int*) DC_PHY_DC_PHY_BIST_DONE_reg))
#define DC_PHY_DC_PHY_BIST_DONE_inst_adr                                             "0x00F1"
#define DC_PHY_DC_PHY_BIST_DONE_inst                                                 0x00F1
#define DC_PHY_DC_PHY_BIST_DONE_DC_PHY_BIST_DONE_3_shift                             (7)
#define DC_PHY_DC_PHY_BIST_DONE_DC_PHY_BIST_DONE_3_mask                              (0x00000080)
#define DC_PHY_DC_PHY_BIST_DONE_DC_PHY_BIST_DONE_3(data)                             (0x00000080&((data)<<7))
#define DC_PHY_DC_PHY_BIST_DONE_DC_PHY_BIST_DONE_3_src(data)                         ((0x00000080&(data))>>7)
#define DC_PHY_DC_PHY_BIST_DONE_get_DC_PHY_BIST_DONE_3(data)                         ((0x00000080&(data))>>7)
#define DC_PHY_DC_PHY_BIST_DONE_DC_PHY_BIST_DONE_2_shift                             (6)
#define DC_PHY_DC_PHY_BIST_DONE_DC_PHY_BIST_DONE_2_mask                              (0x00000040)
#define DC_PHY_DC_PHY_BIST_DONE_DC_PHY_BIST_DONE_2(data)                             (0x00000040&((data)<<6))
#define DC_PHY_DC_PHY_BIST_DONE_DC_PHY_BIST_DONE_2_src(data)                         ((0x00000040&(data))>>6)
#define DC_PHY_DC_PHY_BIST_DONE_get_DC_PHY_BIST_DONE_2(data)                         ((0x00000040&(data))>>6)
#define DC_PHY_DC_PHY_BIST_DONE_DC_PHY_PTG_BIST_DONE_3_shift                         (5)
#define DC_PHY_DC_PHY_BIST_DONE_DC_PHY_PTG_BIST_DONE_3_mask                          (0x00000020)
#define DC_PHY_DC_PHY_BIST_DONE_DC_PHY_PTG_BIST_DONE_3(data)                         (0x00000020&((data)<<5))
#define DC_PHY_DC_PHY_BIST_DONE_DC_PHY_PTG_BIST_DONE_3_src(data)                     ((0x00000020&(data))>>5)
#define DC_PHY_DC_PHY_BIST_DONE_get_DC_PHY_PTG_BIST_DONE_3(data)                     ((0x00000020&(data))>>5)
#define DC_PHY_DC_PHY_BIST_DONE_DC_PHY_PTG_BIST_DONE_2_shift                         (4)
#define DC_PHY_DC_PHY_BIST_DONE_DC_PHY_PTG_BIST_DONE_2_mask                          (0x00000010)
#define DC_PHY_DC_PHY_BIST_DONE_DC_PHY_PTG_BIST_DONE_2(data)                         (0x00000010&((data)<<4))
#define DC_PHY_DC_PHY_BIST_DONE_DC_PHY_PTG_BIST_DONE_2_src(data)                     ((0x00000010&(data))>>4)
#define DC_PHY_DC_PHY_BIST_DONE_get_DC_PHY_PTG_BIST_DONE_2(data)                     ((0x00000010&(data))>>4)
#define DC_PHY_DC_PHY_BIST_DONE_DC_PHY_PTG_BIST_DONE_1_shift                         (3)
#define DC_PHY_DC_PHY_BIST_DONE_DC_PHY_PTG_BIST_DONE_1_mask                          (0x00000008)
#define DC_PHY_DC_PHY_BIST_DONE_DC_PHY_PTG_BIST_DONE_1(data)                         (0x00000008&((data)<<3))
#define DC_PHY_DC_PHY_BIST_DONE_DC_PHY_PTG_BIST_DONE_1_src(data)                     ((0x00000008&(data))>>3)
#define DC_PHY_DC_PHY_BIST_DONE_get_DC_PHY_PTG_BIST_DONE_1(data)                     ((0x00000008&(data))>>3)
#define DC_PHY_DC_PHY_BIST_DONE_DC_PHY_PTG_BIST_DONE_0_shift                         (2)
#define DC_PHY_DC_PHY_BIST_DONE_DC_PHY_PTG_BIST_DONE_0_mask                          (0x00000004)
#define DC_PHY_DC_PHY_BIST_DONE_DC_PHY_PTG_BIST_DONE_0(data)                         (0x00000004&((data)<<2))
#define DC_PHY_DC_PHY_BIST_DONE_DC_PHY_PTG_BIST_DONE_0_src(data)                     ((0x00000004&(data))>>2)
#define DC_PHY_DC_PHY_BIST_DONE_get_DC_PHY_PTG_BIST_DONE_0(data)                     ((0x00000004&(data))>>2)
#define DC_PHY_DC_PHY_BIST_DONE_DC_PHY_BIST_DONE_0_shift                             (1)
#define DC_PHY_DC_PHY_BIST_DONE_DC_PHY_BIST_DONE_0_mask                              (0x00000002)
#define DC_PHY_DC_PHY_BIST_DONE_DC_PHY_BIST_DONE_0(data)                             (0x00000002&((data)<<1))
#define DC_PHY_DC_PHY_BIST_DONE_DC_PHY_BIST_DONE_0_src(data)                         ((0x00000002&(data))>>1)
#define DC_PHY_DC_PHY_BIST_DONE_get_DC_PHY_BIST_DONE_0(data)                         ((0x00000002&(data))>>1)
#define DC_PHY_DC_PHY_BIST_DONE_DC_PHY_BIST_DONE_1_shift                             (0)
#define DC_PHY_DC_PHY_BIST_DONE_DC_PHY_BIST_DONE_1_mask                              (0x00000001)
#define DC_PHY_DC_PHY_BIST_DONE_DC_PHY_BIST_DONE_1(data)                             (0x00000001&((data)<<0))
#define DC_PHY_DC_PHY_BIST_DONE_DC_PHY_BIST_DONE_1_src(data)                         ((0x00000001&(data))>>0)
#define DC_PHY_DC_PHY_BIST_DONE_get_DC_PHY_BIST_DONE_1(data)                         ((0x00000001&(data))>>0)


#define DC_PHY_DC_PHY_BIST_FAIL                                                      0x18008FC8
#define DC_PHY_DC_PHY_BIST_FAIL_reg_addr                                             "0xB8008FC8"
#define DC_PHY_DC_PHY_BIST_FAIL_reg                                                  0xB8008FC8
#define set_DC_PHY_DC_PHY_BIST_FAIL_reg(data)   (*((volatile unsigned int*) DC_PHY_DC_PHY_BIST_FAIL_reg)=data)
#define get_DC_PHY_DC_PHY_BIST_FAIL_reg   (*((volatile unsigned int*) DC_PHY_DC_PHY_BIST_FAIL_reg))
#define DC_PHY_DC_PHY_BIST_FAIL_inst_adr                                             "0x00F2"
#define DC_PHY_DC_PHY_BIST_FAIL_inst                                                 0x00F2
#define DC_PHY_DC_PHY_BIST_FAIL_DC_PHY_BIST_FAIL_GROUP_3_shift                       (7)
#define DC_PHY_DC_PHY_BIST_FAIL_DC_PHY_BIST_FAIL_GROUP_3_mask                        (0x00000080)
#define DC_PHY_DC_PHY_BIST_FAIL_DC_PHY_BIST_FAIL_GROUP_3(data)                       (0x00000080&((data)<<7))
#define DC_PHY_DC_PHY_BIST_FAIL_DC_PHY_BIST_FAIL_GROUP_3_src(data)                   ((0x00000080&(data))>>7)
#define DC_PHY_DC_PHY_BIST_FAIL_get_DC_PHY_BIST_FAIL_GROUP_3(data)                   ((0x00000080&(data))>>7)
#define DC_PHY_DC_PHY_BIST_FAIL_DC_PHY_BIST_FAIL_GROUP_2_shift                       (6)
#define DC_PHY_DC_PHY_BIST_FAIL_DC_PHY_BIST_FAIL_GROUP_2_mask                        (0x00000040)
#define DC_PHY_DC_PHY_BIST_FAIL_DC_PHY_BIST_FAIL_GROUP_2(data)                       (0x00000040&((data)<<6))
#define DC_PHY_DC_PHY_BIST_FAIL_DC_PHY_BIST_FAIL_GROUP_2_src(data)                   ((0x00000040&(data))>>6)
#define DC_PHY_DC_PHY_BIST_FAIL_get_DC_PHY_BIST_FAIL_GROUP_2(data)                   ((0x00000040&(data))>>6)
#define DC_PHY_DC_PHY_BIST_FAIL_DC_PHY_PTG_BIST_FAIL_GROUP_3_shift                   (5)
#define DC_PHY_DC_PHY_BIST_FAIL_DC_PHY_PTG_BIST_FAIL_GROUP_3_mask                    (0x00000020)
#define DC_PHY_DC_PHY_BIST_FAIL_DC_PHY_PTG_BIST_FAIL_GROUP_3(data)                   (0x00000020&((data)<<5))
#define DC_PHY_DC_PHY_BIST_FAIL_DC_PHY_PTG_BIST_FAIL_GROUP_3_src(data)               ((0x00000020&(data))>>5)
#define DC_PHY_DC_PHY_BIST_FAIL_get_DC_PHY_PTG_BIST_FAIL_GROUP_3(data)               ((0x00000020&(data))>>5)
#define DC_PHY_DC_PHY_BIST_FAIL_DC_PHY_PTG_BIST_FAIL_GROUP_2_shift                   (4)
#define DC_PHY_DC_PHY_BIST_FAIL_DC_PHY_PTG_BIST_FAIL_GROUP_2_mask                    (0x00000010)
#define DC_PHY_DC_PHY_BIST_FAIL_DC_PHY_PTG_BIST_FAIL_GROUP_2(data)                   (0x00000010&((data)<<4))
#define DC_PHY_DC_PHY_BIST_FAIL_DC_PHY_PTG_BIST_FAIL_GROUP_2_src(data)               ((0x00000010&(data))>>4)
#define DC_PHY_DC_PHY_BIST_FAIL_get_DC_PHY_PTG_BIST_FAIL_GROUP_2(data)               ((0x00000010&(data))>>4)
#define DC_PHY_DC_PHY_BIST_FAIL_DC_PHY_PTG_BIST_FAIL_GROUP_1_shift                   (3)
#define DC_PHY_DC_PHY_BIST_FAIL_DC_PHY_PTG_BIST_FAIL_GROUP_1_mask                    (0x00000008)
#define DC_PHY_DC_PHY_BIST_FAIL_DC_PHY_PTG_BIST_FAIL_GROUP_1(data)                   (0x00000008&((data)<<3))
#define DC_PHY_DC_PHY_BIST_FAIL_DC_PHY_PTG_BIST_FAIL_GROUP_1_src(data)               ((0x00000008&(data))>>3)
#define DC_PHY_DC_PHY_BIST_FAIL_get_DC_PHY_PTG_BIST_FAIL_GROUP_1(data)               ((0x00000008&(data))>>3)
#define DC_PHY_DC_PHY_BIST_FAIL_DC_PHY_PTG_BIST_FAIL_GROUP_0_shift                   (2)
#define DC_PHY_DC_PHY_BIST_FAIL_DC_PHY_PTG_BIST_FAIL_GROUP_0_mask                    (0x00000004)
#define DC_PHY_DC_PHY_BIST_FAIL_DC_PHY_PTG_BIST_FAIL_GROUP_0(data)                   (0x00000004&((data)<<2))
#define DC_PHY_DC_PHY_BIST_FAIL_DC_PHY_PTG_BIST_FAIL_GROUP_0_src(data)               ((0x00000004&(data))>>2)
#define DC_PHY_DC_PHY_BIST_FAIL_get_DC_PHY_PTG_BIST_FAIL_GROUP_0(data)               ((0x00000004&(data))>>2)
#define DC_PHY_DC_PHY_BIST_FAIL_DC_PHY_BIST_FAIL_GROUP_0_shift                       (1)
#define DC_PHY_DC_PHY_BIST_FAIL_DC_PHY_BIST_FAIL_GROUP_0_mask                        (0x00000002)
#define DC_PHY_DC_PHY_BIST_FAIL_DC_PHY_BIST_FAIL_GROUP_0(data)                       (0x00000002&((data)<<1))
#define DC_PHY_DC_PHY_BIST_FAIL_DC_PHY_BIST_FAIL_GROUP_0_src(data)                   ((0x00000002&(data))>>1)
#define DC_PHY_DC_PHY_BIST_FAIL_get_DC_PHY_BIST_FAIL_GROUP_0(data)                   ((0x00000002&(data))>>1)
#define DC_PHY_DC_PHY_BIST_FAIL_DC_PHY_BIST_FAIL_GROUP_1_shift                       (0)
#define DC_PHY_DC_PHY_BIST_FAIL_DC_PHY_BIST_FAIL_GROUP_1_mask                        (0x00000001)
#define DC_PHY_DC_PHY_BIST_FAIL_DC_PHY_BIST_FAIL_GROUP_1(data)                       (0x00000001&((data)<<0))
#define DC_PHY_DC_PHY_BIST_FAIL_DC_PHY_BIST_FAIL_GROUP_1_src(data)                   ((0x00000001&(data))>>0)
#define DC_PHY_DC_PHY_BIST_FAIL_get_DC_PHY_BIST_FAIL_GROUP_1(data)                   ((0x00000001&(data))>>0)


#define DC_PHY_DC_PHY_BIST_DRF                                                       0x18008FCC
#define DC_PHY_DC_PHY_BIST_DRF_reg_addr                                              "0xB8008FCC"
#define DC_PHY_DC_PHY_BIST_DRF_reg                                                   0xB8008FCC
#define set_DC_PHY_DC_PHY_BIST_DRF_reg(data)   (*((volatile unsigned int*) DC_PHY_DC_PHY_BIST_DRF_reg)=data)
#define get_DC_PHY_DC_PHY_BIST_DRF_reg   (*((volatile unsigned int*) DC_PHY_DC_PHY_BIST_DRF_reg))
#define DC_PHY_DC_PHY_BIST_DRF_inst_adr                                              "0x00F3"
#define DC_PHY_DC_PHY_BIST_DRF_inst                                                  0x00F3
#define DC_PHY_DC_PHY_BIST_DRF_DC_PHY_DRF_MODE_3_shift                               (7)
#define DC_PHY_DC_PHY_BIST_DRF_DC_PHY_DRF_MODE_3_mask                                (0x00000080)
#define DC_PHY_DC_PHY_BIST_DRF_DC_PHY_DRF_MODE_3(data)                               (0x00000080&((data)<<7))
#define DC_PHY_DC_PHY_BIST_DRF_DC_PHY_DRF_MODE_3_src(data)                           ((0x00000080&(data))>>7)
#define DC_PHY_DC_PHY_BIST_DRF_get_DC_PHY_DRF_MODE_3(data)                           ((0x00000080&(data))>>7)
#define DC_PHY_DC_PHY_BIST_DRF_DC_PHY_DRF_MODE_2_shift                               (6)
#define DC_PHY_DC_PHY_BIST_DRF_DC_PHY_DRF_MODE_2_mask                                (0x00000040)
#define DC_PHY_DC_PHY_BIST_DRF_DC_PHY_DRF_MODE_2(data)                               (0x00000040&((data)<<6))
#define DC_PHY_DC_PHY_BIST_DRF_DC_PHY_DRF_MODE_2_src(data)                           ((0x00000040&(data))>>6)
#define DC_PHY_DC_PHY_BIST_DRF_get_DC_PHY_DRF_MODE_2(data)                           ((0x00000040&(data))>>6)
#define DC_PHY_DC_PHY_BIST_DRF_DC_PHY_PTG_DRF_MODE_3_shift                           (5)
#define DC_PHY_DC_PHY_BIST_DRF_DC_PHY_PTG_DRF_MODE_3_mask                            (0x00000020)
#define DC_PHY_DC_PHY_BIST_DRF_DC_PHY_PTG_DRF_MODE_3(data)                           (0x00000020&((data)<<5))
#define DC_PHY_DC_PHY_BIST_DRF_DC_PHY_PTG_DRF_MODE_3_src(data)                       ((0x00000020&(data))>>5)
#define DC_PHY_DC_PHY_BIST_DRF_get_DC_PHY_PTG_DRF_MODE_3(data)                       ((0x00000020&(data))>>5)
#define DC_PHY_DC_PHY_BIST_DRF_DC_PHY_PTG_DRF_MODE_2_shift                           (4)
#define DC_PHY_DC_PHY_BIST_DRF_DC_PHY_PTG_DRF_MODE_2_mask                            (0x00000010)
#define DC_PHY_DC_PHY_BIST_DRF_DC_PHY_PTG_DRF_MODE_2(data)                           (0x00000010&((data)<<4))
#define DC_PHY_DC_PHY_BIST_DRF_DC_PHY_PTG_DRF_MODE_2_src(data)                       ((0x00000010&(data))>>4)
#define DC_PHY_DC_PHY_BIST_DRF_get_DC_PHY_PTG_DRF_MODE_2(data)                       ((0x00000010&(data))>>4)
#define DC_PHY_DC_PHY_BIST_DRF_DC_PHY_PTG_DRF_MODE_1_shift                           (3)
#define DC_PHY_DC_PHY_BIST_DRF_DC_PHY_PTG_DRF_MODE_1_mask                            (0x00000008)
#define DC_PHY_DC_PHY_BIST_DRF_DC_PHY_PTG_DRF_MODE_1(data)                           (0x00000008&((data)<<3))
#define DC_PHY_DC_PHY_BIST_DRF_DC_PHY_PTG_DRF_MODE_1_src(data)                       ((0x00000008&(data))>>3)
#define DC_PHY_DC_PHY_BIST_DRF_get_DC_PHY_PTG_DRF_MODE_1(data)                       ((0x00000008&(data))>>3)
#define DC_PHY_DC_PHY_BIST_DRF_DC_PHY_PTG_DRF_MODE_0_shift                           (2)
#define DC_PHY_DC_PHY_BIST_DRF_DC_PHY_PTG_DRF_MODE_0_mask                            (0x00000004)
#define DC_PHY_DC_PHY_BIST_DRF_DC_PHY_PTG_DRF_MODE_0(data)                           (0x00000004&((data)<<2))
#define DC_PHY_DC_PHY_BIST_DRF_DC_PHY_PTG_DRF_MODE_0_src(data)                       ((0x00000004&(data))>>2)
#define DC_PHY_DC_PHY_BIST_DRF_get_DC_PHY_PTG_DRF_MODE_0(data)                       ((0x00000004&(data))>>2)
#define DC_PHY_DC_PHY_BIST_DRF_DC_PHY_DRF_MODE_0_shift                               (1)
#define DC_PHY_DC_PHY_BIST_DRF_DC_PHY_DRF_MODE_0_mask                                (0x00000002)
#define DC_PHY_DC_PHY_BIST_DRF_DC_PHY_DRF_MODE_0(data)                               (0x00000002&((data)<<1))
#define DC_PHY_DC_PHY_BIST_DRF_DC_PHY_DRF_MODE_0_src(data)                           ((0x00000002&(data))>>1)
#define DC_PHY_DC_PHY_BIST_DRF_get_DC_PHY_DRF_MODE_0(data)                           ((0x00000002&(data))>>1)
#define DC_PHY_DC_PHY_BIST_DRF_DC_PHY_DRF_MODE_1_shift                               (0)
#define DC_PHY_DC_PHY_BIST_DRF_DC_PHY_DRF_MODE_1_mask                                (0x00000001)
#define DC_PHY_DC_PHY_BIST_DRF_DC_PHY_DRF_MODE_1(data)                               (0x00000001&((data)<<0))
#define DC_PHY_DC_PHY_BIST_DRF_DC_PHY_DRF_MODE_1_src(data)                           ((0x00000001&(data))>>0)
#define DC_PHY_DC_PHY_BIST_DRF_get_DC_PHY_DRF_MODE_1(data)                           ((0x00000001&(data))>>0)


#define DC_PHY_DC_PHY_BIST_RESUME                                                    0x18008FD0
#define DC_PHY_DC_PHY_BIST_RESUME_reg_addr                                           "0xB8008FD0"
#define DC_PHY_DC_PHY_BIST_RESUME_reg                                                0xB8008FD0
#define set_DC_PHY_DC_PHY_BIST_RESUME_reg(data)   (*((volatile unsigned int*) DC_PHY_DC_PHY_BIST_RESUME_reg)=data)
#define get_DC_PHY_DC_PHY_BIST_RESUME_reg   (*((volatile unsigned int*) DC_PHY_DC_PHY_BIST_RESUME_reg))
#define DC_PHY_DC_PHY_BIST_RESUME_inst_adr                                           "0x00F4"
#define DC_PHY_DC_PHY_BIST_RESUME_inst                                               0x00F4
#define DC_PHY_DC_PHY_BIST_RESUME_DC_PHY_DRF_RESUME_3_shift                          (7)
#define DC_PHY_DC_PHY_BIST_RESUME_DC_PHY_DRF_RESUME_3_mask                           (0x00000080)
#define DC_PHY_DC_PHY_BIST_RESUME_DC_PHY_DRF_RESUME_3(data)                          (0x00000080&((data)<<7))
#define DC_PHY_DC_PHY_BIST_RESUME_DC_PHY_DRF_RESUME_3_src(data)                      ((0x00000080&(data))>>7)
#define DC_PHY_DC_PHY_BIST_RESUME_get_DC_PHY_DRF_RESUME_3(data)                      ((0x00000080&(data))>>7)
#define DC_PHY_DC_PHY_BIST_RESUME_DC_PHY_DRF_RESUME_2_shift                          (6)
#define DC_PHY_DC_PHY_BIST_RESUME_DC_PHY_DRF_RESUME_2_mask                           (0x00000040)
#define DC_PHY_DC_PHY_BIST_RESUME_DC_PHY_DRF_RESUME_2(data)                          (0x00000040&((data)<<6))
#define DC_PHY_DC_PHY_BIST_RESUME_DC_PHY_DRF_RESUME_2_src(data)                      ((0x00000040&(data))>>6)
#define DC_PHY_DC_PHY_BIST_RESUME_get_DC_PHY_DRF_RESUME_2(data)                      ((0x00000040&(data))>>6)
#define DC_PHY_DC_PHY_BIST_RESUME_DC_PHY_PTG_DRF_RESUME_3_shift                      (5)
#define DC_PHY_DC_PHY_BIST_RESUME_DC_PHY_PTG_DRF_RESUME_3_mask                       (0x00000020)
#define DC_PHY_DC_PHY_BIST_RESUME_DC_PHY_PTG_DRF_RESUME_3(data)                      (0x00000020&((data)<<5))
#define DC_PHY_DC_PHY_BIST_RESUME_DC_PHY_PTG_DRF_RESUME_3_src(data)                  ((0x00000020&(data))>>5)
#define DC_PHY_DC_PHY_BIST_RESUME_get_DC_PHY_PTG_DRF_RESUME_3(data)                  ((0x00000020&(data))>>5)
#define DC_PHY_DC_PHY_BIST_RESUME_DC_PHY_PTG_DRF_RESUME_2_shift                      (4)
#define DC_PHY_DC_PHY_BIST_RESUME_DC_PHY_PTG_DRF_RESUME_2_mask                       (0x00000010)
#define DC_PHY_DC_PHY_BIST_RESUME_DC_PHY_PTG_DRF_RESUME_2(data)                      (0x00000010&((data)<<4))
#define DC_PHY_DC_PHY_BIST_RESUME_DC_PHY_PTG_DRF_RESUME_2_src(data)                  ((0x00000010&(data))>>4)
#define DC_PHY_DC_PHY_BIST_RESUME_get_DC_PHY_PTG_DRF_RESUME_2(data)                  ((0x00000010&(data))>>4)
#define DC_PHY_DC_PHY_BIST_RESUME_DC_PHY_PTG_DRF_RESUME_1_shift                      (3)
#define DC_PHY_DC_PHY_BIST_RESUME_DC_PHY_PTG_DRF_RESUME_1_mask                       (0x00000008)
#define DC_PHY_DC_PHY_BIST_RESUME_DC_PHY_PTG_DRF_RESUME_1(data)                      (0x00000008&((data)<<3))
#define DC_PHY_DC_PHY_BIST_RESUME_DC_PHY_PTG_DRF_RESUME_1_src(data)                  ((0x00000008&(data))>>3)
#define DC_PHY_DC_PHY_BIST_RESUME_get_DC_PHY_PTG_DRF_RESUME_1(data)                  ((0x00000008&(data))>>3)
#define DC_PHY_DC_PHY_BIST_RESUME_DC_PHY_PTG_DRF_RESUME_0_shift                      (2)
#define DC_PHY_DC_PHY_BIST_RESUME_DC_PHY_PTG_DRF_RESUME_0_mask                       (0x00000004)
#define DC_PHY_DC_PHY_BIST_RESUME_DC_PHY_PTG_DRF_RESUME_0(data)                      (0x00000004&((data)<<2))
#define DC_PHY_DC_PHY_BIST_RESUME_DC_PHY_PTG_DRF_RESUME_0_src(data)                  ((0x00000004&(data))>>2)
#define DC_PHY_DC_PHY_BIST_RESUME_get_DC_PHY_PTG_DRF_RESUME_0(data)                  ((0x00000004&(data))>>2)
#define DC_PHY_DC_PHY_BIST_RESUME_DC_PHY_DRF_RESUME_0_shift                          (1)
#define DC_PHY_DC_PHY_BIST_RESUME_DC_PHY_DRF_RESUME_0_mask                           (0x00000002)
#define DC_PHY_DC_PHY_BIST_RESUME_DC_PHY_DRF_RESUME_0(data)                          (0x00000002&((data)<<1))
#define DC_PHY_DC_PHY_BIST_RESUME_DC_PHY_DRF_RESUME_0_src(data)                      ((0x00000002&(data))>>1)
#define DC_PHY_DC_PHY_BIST_RESUME_get_DC_PHY_DRF_RESUME_0(data)                      ((0x00000002&(data))>>1)
#define DC_PHY_DC_PHY_BIST_RESUME_DC_PHY_DRF_RESUME_1_shift                          (0)
#define DC_PHY_DC_PHY_BIST_RESUME_DC_PHY_DRF_RESUME_1_mask                           (0x00000001)
#define DC_PHY_DC_PHY_BIST_RESUME_DC_PHY_DRF_RESUME_1(data)                          (0x00000001&((data)<<0))
#define DC_PHY_DC_PHY_BIST_RESUME_DC_PHY_DRF_RESUME_1_src(data)                      ((0x00000001&(data))>>0)
#define DC_PHY_DC_PHY_BIST_RESUME_get_DC_PHY_DRF_RESUME_1(data)                      ((0x00000001&(data))>>0)


#define DC_PHY_DC_PHY_BIST0_DRF_DONE                                                 0x18008FD4
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_reg_addr                                        "0xB8008FD4"
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_reg                                             0xB8008FD4
#define set_DC_PHY_DC_PHY_BIST0_DRF_DONE_reg(data)   (*((volatile unsigned int*) DC_PHY_DC_PHY_BIST0_DRF_DONE_reg)=data)
#define get_DC_PHY_DC_PHY_BIST0_DRF_DONE_reg   (*((volatile unsigned int*) DC_PHY_DC_PHY_BIST0_DRF_DONE_reg))
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_inst_adr                                        "0x00F5"
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_inst                                            0x00F5
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_DC_PHY_DRF_DONE_3_shift                         (7)
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_DC_PHY_DRF_DONE_3_mask                          (0x00000080)
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_DC_PHY_DRF_DONE_3(data)                         (0x00000080&((data)<<7))
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_DC_PHY_DRF_DONE_3_src(data)                     ((0x00000080&(data))>>7)
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_get_DC_PHY_DRF_DONE_3(data)                     ((0x00000080&(data))>>7)
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_DC_PHY_DRF_DONE_2_shift                         (6)
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_DC_PHY_DRF_DONE_2_mask                          (0x00000040)
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_DC_PHY_DRF_DONE_2(data)                         (0x00000040&((data)<<6))
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_DC_PHY_DRF_DONE_2_src(data)                     ((0x00000040&(data))>>6)
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_get_DC_PHY_DRF_DONE_2(data)                     ((0x00000040&(data))>>6)
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_DC_PHY_PTG_DRF_DONE_3_shift                     (5)
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_DC_PHY_PTG_DRF_DONE_3_mask                      (0x00000020)
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_DC_PHY_PTG_DRF_DONE_3(data)                     (0x00000020&((data)<<5))
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_DC_PHY_PTG_DRF_DONE_3_src(data)                 ((0x00000020&(data))>>5)
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_get_DC_PHY_PTG_DRF_DONE_3(data)                 ((0x00000020&(data))>>5)
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_DC_PHY_PTG_DRF_DONE_2_shift                     (4)
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_DC_PHY_PTG_DRF_DONE_2_mask                      (0x00000010)
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_DC_PHY_PTG_DRF_DONE_2(data)                     (0x00000010&((data)<<4))
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_DC_PHY_PTG_DRF_DONE_2_src(data)                 ((0x00000010&(data))>>4)
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_get_DC_PHY_PTG_DRF_DONE_2(data)                 ((0x00000010&(data))>>4)
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_DC_PHY_PTG_DRF_DONE_1_shift                     (3)
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_DC_PHY_PTG_DRF_DONE_1_mask                      (0x00000008)
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_DC_PHY_PTG_DRF_DONE_1(data)                     (0x00000008&((data)<<3))
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_DC_PHY_PTG_DRF_DONE_1_src(data)                 ((0x00000008&(data))>>3)
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_get_DC_PHY_PTG_DRF_DONE_1(data)                 ((0x00000008&(data))>>3)
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_DC_PHY_PTG_DRF_DONE_0_shift                     (2)
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_DC_PHY_PTG_DRF_DONE_0_mask                      (0x00000004)
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_DC_PHY_PTG_DRF_DONE_0(data)                     (0x00000004&((data)<<2))
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_DC_PHY_PTG_DRF_DONE_0_src(data)                 ((0x00000004&(data))>>2)
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_get_DC_PHY_PTG_DRF_DONE_0(data)                 ((0x00000004&(data))>>2)
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_DC_PHY_DRF_DONE_0_shift                         (1)
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_DC_PHY_DRF_DONE_0_mask                          (0x00000002)
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_DC_PHY_DRF_DONE_0(data)                         (0x00000002&((data)<<1))
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_DC_PHY_DRF_DONE_0_src(data)                     ((0x00000002&(data))>>1)
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_get_DC_PHY_DRF_DONE_0(data)                     ((0x00000002&(data))>>1)
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_DC_PHY_DRF_DONE_1_shift                         (0)
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_DC_PHY_DRF_DONE_1_mask                          (0x00000001)
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_DC_PHY_DRF_DONE_1(data)                         (0x00000001&((data)<<0))
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_DC_PHY_DRF_DONE_1_src(data)                     ((0x00000001&(data))>>0)
#define DC_PHY_DC_PHY_BIST0_DRF_DONE_get_DC_PHY_DRF_DONE_1(data)                     ((0x00000001&(data))>>0)


#define DC_PHY_DC_PHY_BIST_DRF_PAUSE                                                 0x18008FD8
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_reg_addr                                        "0xB8008FD8"
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_reg                                             0xB8008FD8
#define set_DC_PHY_DC_PHY_BIST_DRF_PAUSE_reg(data)   (*((volatile unsigned int*) DC_PHY_DC_PHY_BIST_DRF_PAUSE_reg)=data)
#define get_DC_PHY_DC_PHY_BIST_DRF_PAUSE_reg   (*((volatile unsigned int*) DC_PHY_DC_PHY_BIST_DRF_PAUSE_reg))
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_inst_adr                                        "0x00F6"
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_inst                                            0x00F6
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_DC_PHY_DRF_PAUSE_3_shift                        (7)
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_DC_PHY_DRF_PAUSE_3_mask                         (0x00000080)
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_DC_PHY_DRF_PAUSE_3(data)                        (0x00000080&((data)<<7))
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_DC_PHY_DRF_PAUSE_3_src(data)                    ((0x00000080&(data))>>7)
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_get_DC_PHY_DRF_PAUSE_3(data)                    ((0x00000080&(data))>>7)
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_DC_PHY_DRF_PAUSE_2_shift                        (6)
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_DC_PHY_DRF_PAUSE_2_mask                         (0x00000040)
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_DC_PHY_DRF_PAUSE_2(data)                        (0x00000040&((data)<<6))
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_DC_PHY_DRF_PAUSE_2_src(data)                    ((0x00000040&(data))>>6)
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_get_DC_PHY_DRF_PAUSE_2(data)                    ((0x00000040&(data))>>6)
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_DC_PHY_PTG_DRF_PAUSE_3_shift                    (5)
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_DC_PHY_PTG_DRF_PAUSE_3_mask                     (0x00000020)
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_DC_PHY_PTG_DRF_PAUSE_3(data)                    (0x00000020&((data)<<5))
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_DC_PHY_PTG_DRF_PAUSE_3_src(data)                ((0x00000020&(data))>>5)
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_get_DC_PHY_PTG_DRF_PAUSE_3(data)                ((0x00000020&(data))>>5)
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_DC_PHY_PTG_DRF_PAUSE_2_shift                    (4)
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_DC_PHY_PTG_DRF_PAUSE_2_mask                     (0x00000010)
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_DC_PHY_PTG_DRF_PAUSE_2(data)                    (0x00000010&((data)<<4))
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_DC_PHY_PTG_DRF_PAUSE_2_src(data)                ((0x00000010&(data))>>4)
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_get_DC_PHY_PTG_DRF_PAUSE_2(data)                ((0x00000010&(data))>>4)
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_DC_PHY_PTG_DRF_PAUSE_1_shift                    (3)
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_DC_PHY_PTG_DRF_PAUSE_1_mask                     (0x00000008)
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_DC_PHY_PTG_DRF_PAUSE_1(data)                    (0x00000008&((data)<<3))
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_DC_PHY_PTG_DRF_PAUSE_1_src(data)                ((0x00000008&(data))>>3)
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_get_DC_PHY_PTG_DRF_PAUSE_1(data)                ((0x00000008&(data))>>3)
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_DC_PHY_PTG_DRF_PAUSE_0_shift                    (2)
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_DC_PHY_PTG_DRF_PAUSE_0_mask                     (0x00000004)
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_DC_PHY_PTG_DRF_PAUSE_0(data)                    (0x00000004&((data)<<2))
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_DC_PHY_PTG_DRF_PAUSE_0_src(data)                ((0x00000004&(data))>>2)
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_get_DC_PHY_PTG_DRF_PAUSE_0(data)                ((0x00000004&(data))>>2)
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_DC_PHY_DRF_PAUSE_0_shift                        (1)
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_DC_PHY_DRF_PAUSE_0_mask                         (0x00000002)
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_DC_PHY_DRF_PAUSE_0(data)                        (0x00000002&((data)<<1))
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_DC_PHY_DRF_PAUSE_0_src(data)                    ((0x00000002&(data))>>1)
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_get_DC_PHY_DRF_PAUSE_0(data)                    ((0x00000002&(data))>>1)
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_DC_PHY_DRF_PAUSE_1_shift                        (0)
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_DC_PHY_DRF_PAUSE_1_mask                         (0x00000001)
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_DC_PHY_DRF_PAUSE_1(data)                        (0x00000001&((data)<<0))
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_DC_PHY_DRF_PAUSE_1_src(data)                    ((0x00000001&(data))>>0)
#define DC_PHY_DC_PHY_BIST_DRF_PAUSE_get_DC_PHY_DRF_PAUSE_1(data)                    ((0x00000001&(data))>>0)


#define DC_PHY_DC_PHY_BIST_DRF_FAIL                                                  0x18008FDC
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_reg_addr                                         "0xB8008FDC"
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_reg                                              0xB8008FDC
#define set_DC_PHY_DC_PHY_BIST_DRF_FAIL_reg(data)   (*((volatile unsigned int*) DC_PHY_DC_PHY_BIST_DRF_FAIL_reg)=data)
#define get_DC_PHY_DC_PHY_BIST_DRF_FAIL_reg   (*((volatile unsigned int*) DC_PHY_DC_PHY_BIST_DRF_FAIL_reg))
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_inst_adr                                         "0x00F7"
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_inst                                             0x00F7
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_DC_PHY_DRF_FAIL_GROUP_3_shift                    (7)
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_DC_PHY_DRF_FAIL_GROUP_3_mask                     (0x00000080)
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_DC_PHY_DRF_FAIL_GROUP_3(data)                    (0x00000080&((data)<<7))
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_DC_PHY_DRF_FAIL_GROUP_3_src(data)                ((0x00000080&(data))>>7)
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_get_DC_PHY_DRF_FAIL_GROUP_3(data)                ((0x00000080&(data))>>7)
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_DC_PHY_DRF_FAIL_GROUP_2_shift                    (6)
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_DC_PHY_DRF_FAIL_GROUP_2_mask                     (0x00000040)
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_DC_PHY_DRF_FAIL_GROUP_2(data)                    (0x00000040&((data)<<6))
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_DC_PHY_DRF_FAIL_GROUP_2_src(data)                ((0x00000040&(data))>>6)
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_get_DC_PHY_DRF_FAIL_GROUP_2(data)                ((0x00000040&(data))>>6)
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_DC_PHY_PTG_DRF_FAIL_GROUP_3_shift                (5)
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_DC_PHY_PTG_DRF_FAIL_GROUP_3_mask                 (0x00000020)
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_DC_PHY_PTG_DRF_FAIL_GROUP_3(data)                (0x00000020&((data)<<5))
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_DC_PHY_PTG_DRF_FAIL_GROUP_3_src(data)            ((0x00000020&(data))>>5)
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_get_DC_PHY_PTG_DRF_FAIL_GROUP_3(data)            ((0x00000020&(data))>>5)
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_DC_PHY_PTG_DRF_FAIL_GROUP_2_shift                (4)
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_DC_PHY_PTG_DRF_FAIL_GROUP_2_mask                 (0x00000010)
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_DC_PHY_PTG_DRF_FAIL_GROUP_2(data)                (0x00000010&((data)<<4))
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_DC_PHY_PTG_DRF_FAIL_GROUP_2_src(data)            ((0x00000010&(data))>>4)
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_get_DC_PHY_PTG_DRF_FAIL_GROUP_2(data)            ((0x00000010&(data))>>4)
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_DC_PHY_PTG_DRF_FAIL_GROUP_1_shift                (3)
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_DC_PHY_PTG_DRF_FAIL_GROUP_1_mask                 (0x00000008)
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_DC_PHY_PTG_DRF_FAIL_GROUP_1(data)                (0x00000008&((data)<<3))
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_DC_PHY_PTG_DRF_FAIL_GROUP_1_src(data)            ((0x00000008&(data))>>3)
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_get_DC_PHY_PTG_DRF_FAIL_GROUP_1(data)            ((0x00000008&(data))>>3)
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_DC_PHY_PTG_DRF_FAIL_GROUP_0_shift                (2)
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_DC_PHY_PTG_DRF_FAIL_GROUP_0_mask                 (0x00000004)
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_DC_PHY_PTG_DRF_FAIL_GROUP_0(data)                (0x00000004&((data)<<2))
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_DC_PHY_PTG_DRF_FAIL_GROUP_0_src(data)            ((0x00000004&(data))>>2)
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_get_DC_PHY_PTG_DRF_FAIL_GROUP_0(data)            ((0x00000004&(data))>>2)
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_DC_PHY_DRF_FAIL_GROUP_0_shift                    (1)
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_DC_PHY_DRF_FAIL_GROUP_0_mask                     (0x00000002)
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_DC_PHY_DRF_FAIL_GROUP_0(data)                    (0x00000002&((data)<<1))
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_DC_PHY_DRF_FAIL_GROUP_0_src(data)                ((0x00000002&(data))>>1)
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_get_DC_PHY_DRF_FAIL_GROUP_0(data)                ((0x00000002&(data))>>1)
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_DC_PHY_DRF_FAIL_GROUP_1_shift                    (0)
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_DC_PHY_DRF_FAIL_GROUP_1_mask                     (0x00000001)
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_DC_PHY_DRF_FAIL_GROUP_1(data)                    (0x00000001&((data)<<0))
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_DC_PHY_DRF_FAIL_GROUP_1_src(data)                ((0x00000001&(data))>>0)
#define DC_PHY_DC_PHY_BIST_DRF_FAIL_get_DC_PHY_DRF_FAIL_GROUP_1(data)                ((0x00000001&(data))>>0)


#define DC_PHY_DC_PHY_BIST_DETAIL                                                    0x18008FE0
#define DC_PHY_DC_PHY_BIST_DETAIL_reg_addr                                           "0xB8008FE0"
#define DC_PHY_DC_PHY_BIST_DETAIL_reg                                                0xB8008FE0
#define set_DC_PHY_DC_PHY_BIST_DETAIL_reg(data)   (*((volatile unsigned int*) DC_PHY_DC_PHY_BIST_DETAIL_reg)=data)
#define get_DC_PHY_DC_PHY_BIST_DETAIL_reg   (*((volatile unsigned int*) DC_PHY_DC_PHY_BIST_DETAIL_reg))
#define DC_PHY_DC_PHY_BIST_DETAIL_inst_adr                                           "0x00F8"
#define DC_PHY_DC_PHY_BIST_DETAIL_inst                                               0x00F8
#define DC_PHY_DC_PHY_BIST_DETAIL_dummy_shift                                        (0)
#define DC_PHY_DC_PHY_BIST_DETAIL_dummy_mask                                         (0xFFFFFFFF)
#define DC_PHY_DC_PHY_BIST_DETAIL_dummy(data)                                        (0xFFFFFFFF&((data)<<0))
#define DC_PHY_DC_PHY_BIST_DETAIL_dummy_src(data)                                    ((0xFFFFFFFF&(data))>>0)
#define DC_PHY_DC_PHY_BIST_DETAIL_get_dummy(data)                                    ((0xFFFFFFFF&(data))>>0)


#define DC_PHY_DC_PHY_BIST_RM                                                        0x18008FE4
#define DC_PHY_DC_PHY_BIST_RM_reg_addr                                               "0xB8008FE4"
#define DC_PHY_DC_PHY_BIST_RM_reg                                                    0xB8008FE4
#define set_DC_PHY_DC_PHY_BIST_RM_reg(data)   (*((volatile unsigned int*) DC_PHY_DC_PHY_BIST_RM_reg)=data)
#define get_DC_PHY_DC_PHY_BIST_RM_reg   (*((volatile unsigned int*) DC_PHY_DC_PHY_BIST_RM_reg))
#define DC_PHY_DC_PHY_BIST_RM_inst_adr                                               "0x00F9"
#define DC_PHY_DC_PHY_BIST_RM_inst                                                   0x00F9
#define DC_PHY_DC_PHY_BIST_RM_dc_phy_ls_shift                                        (9)
#define DC_PHY_DC_PHY_BIST_RM_dc_phy_ls_mask                                         (0x00000200)
#define DC_PHY_DC_PHY_BIST_RM_dc_phy_ls(data)                                        (0x00000200&((data)<<9))
#define DC_PHY_DC_PHY_BIST_RM_dc_phy_ls_src(data)                                    ((0x00000200&(data))>>9)
#define DC_PHY_DC_PHY_BIST_RM_get_dc_phy_ls(data)                                    ((0x00000200&(data))>>9)
#define DC_PHY_DC_PHY_BIST_RM_dc_phy_ptg_ls_shift                                    (8)
#define DC_PHY_DC_PHY_BIST_RM_dc_phy_ptg_ls_mask                                     (0x00000100)
#define DC_PHY_DC_PHY_BIST_RM_dc_phy_ptg_ls(data)                                    (0x00000100&((data)<<8))
#define DC_PHY_DC_PHY_BIST_RM_dc_phy_ptg_ls_src(data)                                ((0x00000100&(data))>>8)
#define DC_PHY_DC_PHY_BIST_RM_get_dc_phy_ptg_ls(data)                                ((0x00000100&(data))>>8)
#define DC_PHY_DC_PHY_BIST_RM_RME_shift                                              (4)
#define DC_PHY_DC_PHY_BIST_RM_RME_mask                                               (0x00000010)
#define DC_PHY_DC_PHY_BIST_RM_RME(data)                                              (0x00000010&((data)<<4))
#define DC_PHY_DC_PHY_BIST_RM_RME_src(data)                                          ((0x00000010&(data))>>4)
#define DC_PHY_DC_PHY_BIST_RM_get_RME(data)                                          ((0x00000010&(data))>>4)
#define DC_PHY_DC_PHY_BIST_RM_RM_3_shift                                             (3)
#define DC_PHY_DC_PHY_BIST_RM_RM_3_mask                                              (0x00000008)
#define DC_PHY_DC_PHY_BIST_RM_RM_3(data)                                             (0x00000008&((data)<<3))
#define DC_PHY_DC_PHY_BIST_RM_RM_3_src(data)                                         ((0x00000008&(data))>>3)
#define DC_PHY_DC_PHY_BIST_RM_get_RM_3(data)                                         ((0x00000008&(data))>>3)
#define DC_PHY_DC_PHY_BIST_RM_RM_2_shift                                             (2)
#define DC_PHY_DC_PHY_BIST_RM_RM_2_mask                                              (0x00000004)
#define DC_PHY_DC_PHY_BIST_RM_RM_2(data)                                             (0x00000004&((data)<<2))
#define DC_PHY_DC_PHY_BIST_RM_RM_2_src(data)                                         ((0x00000004&(data))>>2)
#define DC_PHY_DC_PHY_BIST_RM_get_RM_2(data)                                         ((0x00000004&(data))>>2)
#define DC_PHY_DC_PHY_BIST_RM_RM_1_shift                                             (1)
#define DC_PHY_DC_PHY_BIST_RM_RM_1_mask                                              (0x00000002)
#define DC_PHY_DC_PHY_BIST_RM_RM_1(data)                                             (0x00000002&((data)<<1))
#define DC_PHY_DC_PHY_BIST_RM_RM_1_src(data)                                         ((0x00000002&(data))>>1)
#define DC_PHY_DC_PHY_BIST_RM_get_RM_1(data)                                         ((0x00000002&(data))>>1)
#define DC_PHY_DC_PHY_BIST_RM_RM_0_shift                                             (0)
#define DC_PHY_DC_PHY_BIST_RM_RM_0_mask                                              (0x00000001)
#define DC_PHY_DC_PHY_BIST_RM_RM_0(data)                                             (0x00000001&((data)<<0))
#define DC_PHY_DC_PHY_BIST_RM_RM_0_src(data)                                         ((0x00000001&(data))>>0)
#define DC_PHY_DC_PHY_BIST_RM_get_RM_0(data)                                         ((0x00000001&(data))>>0)


#define DC_PHY_PTG_READY                                                             0x18008FF8
#define DC_PHY_PTG_READY_reg_addr                                                    "0xB8008FF8"
#define DC_PHY_PTG_READY_reg                                                         0xB8008FF8
#define set_DC_PHY_PTG_READY_reg(data)   (*((volatile unsigned int*) DC_PHY_PTG_READY_reg)=data)
#define get_DC_PHY_PTG_READY_reg   (*((volatile unsigned int*) DC_PHY_PTG_READY_reg))
#define DC_PHY_PTG_READY_inst_adr                                                    "0x00FE"
#define DC_PHY_PTG_READY_inst                                                        0x00FE
#define DC_PHY_PTG_READY_dc_phy_ptg_ready_shift                                      (0)
#define DC_PHY_PTG_READY_dc_phy_ptg_ready_mask                                       (0x00000001)
#define DC_PHY_PTG_READY_dc_phy_ptg_ready(data)                                      (0x00000001&((data)<<0))
#define DC_PHY_PTG_READY_dc_phy_ptg_ready_src(data)                                  ((0x00000001&(data))>>0)
#define DC_PHY_PTG_READY_get_dc_phy_ptg_ready(data)                                  ((0x00000001&(data))>>0)


#define DC_PHY_PTG_SELECT                                                            0x18008FFC
#define DC_PHY_PTG_SELECT_reg_addr                                                   "0xB8008FFC"
#define DC_PHY_PTG_SELECT_reg                                                        0xB8008FFC
#define set_DC_PHY_PTG_SELECT_reg(data)   (*((volatile unsigned int*) DC_PHY_PTG_SELECT_reg)=data)
#define get_DC_PHY_PTG_SELECT_reg   (*((volatile unsigned int*) DC_PHY_PTG_SELECT_reg))
#define DC_PHY_PTG_SELECT_inst_adr                                                   "0x00FF"
#define DC_PHY_PTG_SELECT_inst                                                       0x00FF
#define DC_PHY_PTG_SELECT_dc_phy_ptg_rst_n_shift                                     (2)
#define DC_PHY_PTG_SELECT_dc_phy_ptg_rst_n_mask                                      (0x00000004)
#define DC_PHY_PTG_SELECT_dc_phy_ptg_rst_n(data)                                     (0x00000004&((data)<<2))
#define DC_PHY_PTG_SELECT_dc_phy_ptg_rst_n_src(data)                                 ((0x00000004&(data))>>2)
#define DC_PHY_PTG_SELECT_get_dc_phy_ptg_rst_n(data)                                 ((0x00000004&(data))>>2)
#define DC_PHY_PTG_SELECT_dc_phy_ptg_clk_en_shift                                    (1)
#define DC_PHY_PTG_SELECT_dc_phy_ptg_clk_en_mask                                     (0x00000002)
#define DC_PHY_PTG_SELECT_dc_phy_ptg_clk_en(data)                                    (0x00000002&((data)<<1))
#define DC_PHY_PTG_SELECT_dc_phy_ptg_clk_en_src(data)                                ((0x00000002&(data))>>1)
#define DC_PHY_PTG_SELECT_get_dc_phy_ptg_clk_en(data)                                ((0x00000002&(data))>>1)
#define DC_PHY_PTG_SELECT_dc_phy_ptg_sel_shift                                       (0)
#define DC_PHY_PTG_SELECT_dc_phy_ptg_sel_mask                                        (0x00000001)
#define DC_PHY_PTG_SELECT_dc_phy_ptg_sel(data)                                       (0x00000001&((data)<<0))
#define DC_PHY_PTG_SELECT_dc_phy_ptg_sel_src(data)                                   ((0x00000001&(data))>>0)
#define DC_PHY_PTG_SELECT_get_dc_phy_ptg_sel(data)                                   ((0x00000001&(data))>>0)


#define DC_PHY_BLOCK_REQ                                                             0x18008C00
#define DC_PHY_BLOCK_REQ_reg_addr                                                    "0xB8008C00"
#define DC_PHY_BLOCK_REQ_reg                                                         0xB8008C00
#define set_DC_PHY_BLOCK_REQ_reg(data)   (*((volatile unsigned int*) DC_PHY_BLOCK_REQ_reg)=data)
#define get_DC_PHY_BLOCK_REQ_reg   (*((volatile unsigned int*) DC_PHY_BLOCK_REQ_reg))
#define DC_PHY_BLOCK_REQ_inst_adr                                                    "0x0000"
#define DC_PHY_BLOCK_REQ_inst                                                        0x0000
#define DC_PHY_BLOCK_REQ_dc_sys2_rd_block_en_shift                                   (5)
#define DC_PHY_BLOCK_REQ_dc_sys2_rd_block_en_mask                                    (0x00000020)
#define DC_PHY_BLOCK_REQ_dc_sys2_rd_block_en(data)                                   (0x00000020&((data)<<5))
#define DC_PHY_BLOCK_REQ_dc_sys2_rd_block_en_src(data)                               ((0x00000020&(data))>>5)
#define DC_PHY_BLOCK_REQ_get_dc_sys2_rd_block_en(data)                               ((0x00000020&(data))>>5)
#define DC_PHY_BLOCK_REQ_dc_sys2_wr_block_en_shift                                   (4)
#define DC_PHY_BLOCK_REQ_dc_sys2_wr_block_en_mask                                    (0x00000010)
#define DC_PHY_BLOCK_REQ_dc_sys2_wr_block_en(data)                                   (0x00000010&((data)<<4))
#define DC_PHY_BLOCK_REQ_dc_sys2_wr_block_en_src(data)                               ((0x00000010&(data))>>4)
#define DC_PHY_BLOCK_REQ_get_dc_sys2_wr_block_en(data)                               ((0x00000010&(data))>>4)
#define DC_PHY_BLOCK_REQ_dc_sys1_rd_block_en_shift                                   (3)
#define DC_PHY_BLOCK_REQ_dc_sys1_rd_block_en_mask                                    (0x00000008)
#define DC_PHY_BLOCK_REQ_dc_sys1_rd_block_en(data)                                   (0x00000008&((data)<<3))
#define DC_PHY_BLOCK_REQ_dc_sys1_rd_block_en_src(data)                               ((0x00000008&(data))>>3)
#define DC_PHY_BLOCK_REQ_get_dc_sys1_rd_block_en(data)                               ((0x00000008&(data))>>3)
#define DC_PHY_BLOCK_REQ_dc_sys1_wr_block_en_shift                                   (2)
#define DC_PHY_BLOCK_REQ_dc_sys1_wr_block_en_mask                                    (0x00000004)
#define DC_PHY_BLOCK_REQ_dc_sys1_wr_block_en(data)                                   (0x00000004&((data)<<2))
#define DC_PHY_BLOCK_REQ_dc_sys1_wr_block_en_src(data)                               ((0x00000004&(data))>>2)
#define DC_PHY_BLOCK_REQ_get_dc_sys1_wr_block_en(data)                               ((0x00000004&(data))>>2)
#define DC_PHY_BLOCK_REQ_exp_rd_block_en_shift                                       (1)
#define DC_PHY_BLOCK_REQ_exp_rd_block_en_mask                                        (0x00000002)
#define DC_PHY_BLOCK_REQ_exp_rd_block_en(data)                                       (0x00000002&((data)<<1))
#define DC_PHY_BLOCK_REQ_exp_rd_block_en_src(data)                                   ((0x00000002&(data))>>1)
#define DC_PHY_BLOCK_REQ_get_exp_rd_block_en(data)                                   ((0x00000002&(data))>>1)
#define DC_PHY_BLOCK_REQ_exp_wr_block_en_shift                                       (0)
#define DC_PHY_BLOCK_REQ_exp_wr_block_en_mask                                        (0x00000001)
#define DC_PHY_BLOCK_REQ_exp_wr_block_en(data)                                       (0x00000001&((data)<<0))
#define DC_PHY_BLOCK_REQ_exp_wr_block_en_src(data)                                   ((0x00000001&(data))>>0)
#define DC_PHY_BLOCK_REQ_get_exp_wr_block_en(data)                                   ((0x00000001&(data))>>0)


#define DC_PHY_DC_SYS1_CTRL                                                          0x18008C04
#define DC_PHY_DC_SYS1_CTRL_reg_addr                                                 "0xB8008C04"
#define DC_PHY_DC_SYS1_CTRL_reg                                                      0xB8008C04
#define set_DC_PHY_DC_SYS1_CTRL_reg(data)   (*((volatile unsigned int*) DC_PHY_DC_SYS1_CTRL_reg)=data)
#define get_DC_PHY_DC_SYS1_CTRL_reg   (*((volatile unsigned int*) DC_PHY_DC_SYS1_CTRL_reg))
#define DC_PHY_DC_SYS1_CTRL_inst_adr                                                 "0x0001"
#define DC_PHY_DC_SYS1_CTRL_inst                                                     0x0001
#define DC_PHY_DC_SYS1_CTRL_dc_sys1_read_bypass_rw_separate_en_shift                 (2)
#define DC_PHY_DC_SYS1_CTRL_dc_sys1_read_bypass_rw_separate_en_mask                  (0x00000004)
#define DC_PHY_DC_SYS1_CTRL_dc_sys1_read_bypass_rw_separate_en(data)                 (0x00000004&((data)<<2))
#define DC_PHY_DC_SYS1_CTRL_dc_sys1_read_bypass_rw_separate_en_src(data)             ((0x00000004&(data))>>2)
#define DC_PHY_DC_SYS1_CTRL_get_dc_sys1_read_bypass_rw_separate_en(data)             ((0x00000004&(data))>>2)
#define DC_PHY_DC_SYS1_CTRL_dc_sys1_read_bypass_en_shift                             (1)
#define DC_PHY_DC_SYS1_CTRL_dc_sys1_read_bypass_en_mask                              (0x00000002)
#define DC_PHY_DC_SYS1_CTRL_dc_sys1_read_bypass_en(data)                             (0x00000002&((data)<<1))
#define DC_PHY_DC_SYS1_CTRL_dc_sys1_read_bypass_en_src(data)                         ((0x00000002&(data))>>1)
#define DC_PHY_DC_SYS1_CTRL_get_dc_sys1_read_bypass_en(data)                         ((0x00000002&(data))>>1)
#define DC_PHY_DC_SYS1_CTRL_dc_sys1_path_sel_shift                                   (0)
#define DC_PHY_DC_SYS1_CTRL_dc_sys1_path_sel_mask                                    (0x00000001)
#define DC_PHY_DC_SYS1_CTRL_dc_sys1_path_sel(data)                                   (0x00000001&((data)<<0))
#define DC_PHY_DC_SYS1_CTRL_dc_sys1_path_sel_src(data)                               ((0x00000001&(data))>>0)
#define DC_PHY_DC_SYS1_CTRL_get_dc_sys1_path_sel(data)                               ((0x00000001&(data))>>0)


#define DC_PHY_DC_SYS2_CTRL                                                          0x18008C08
#define DC_PHY_DC_SYS2_CTRL_reg_addr                                                 "0xB8008C08"
#define DC_PHY_DC_SYS2_CTRL_reg                                                      0xB8008C08
#define set_DC_PHY_DC_SYS2_CTRL_reg(data)   (*((volatile unsigned int*) DC_PHY_DC_SYS2_CTRL_reg)=data)
#define get_DC_PHY_DC_SYS2_CTRL_reg   (*((volatile unsigned int*) DC_PHY_DC_SYS2_CTRL_reg))
#define DC_PHY_DC_SYS2_CTRL_inst_adr                                                 "0x0002"
#define DC_PHY_DC_SYS2_CTRL_inst                                                     0x0002
#define DC_PHY_DC_SYS2_CTRL_dc_sys2_wr_qfifo_en_shift                                (2)
#define DC_PHY_DC_SYS2_CTRL_dc_sys2_wr_qfifo_en_mask                                 (0x00000004)
#define DC_PHY_DC_SYS2_CTRL_dc_sys2_wr_qfifo_en(data)                                (0x00000004&((data)<<2))
#define DC_PHY_DC_SYS2_CTRL_dc_sys2_wr_qfifo_en_src(data)                            ((0x00000004&(data))>>2)
#define DC_PHY_DC_SYS2_CTRL_get_dc_sys2_wr_qfifo_en(data)                            ((0x00000004&(data))>>2)
#define DC_PHY_DC_SYS2_CTRL_dc_sys2_client_sep_enable_shift                          (1)
#define DC_PHY_DC_SYS2_CTRL_dc_sys2_client_sep_enable_mask                           (0x00000002)
#define DC_PHY_DC_SYS2_CTRL_dc_sys2_client_sep_enable(data)                          (0x00000002&((data)<<1))
#define DC_PHY_DC_SYS2_CTRL_dc_sys2_client_sep_enable_src(data)                      ((0x00000002&(data))>>1)
#define DC_PHY_DC_SYS2_CTRL_get_dc_sys2_client_sep_enable(data)                      ((0x00000002&(data))>>1)
#define DC_PHY_DC_SYS2_CTRL_dc_sys2_rw_sep_en_shift                                  (0)
#define DC_PHY_DC_SYS2_CTRL_dc_sys2_rw_sep_en_mask                                   (0x00000001)
#define DC_PHY_DC_SYS2_CTRL_dc_sys2_rw_sep_en(data)                                  (0x00000001&((data)<<0))
#define DC_PHY_DC_SYS2_CTRL_dc_sys2_rw_sep_en_src(data)                              ((0x00000001&(data))>>0)
#define DC_PHY_DC_SYS2_CTRL_get_dc_sys2_rw_sep_en(data)                              ((0x00000001&(data))>>0)


#define DC_PHY_QOS_CTRL_0                                                            0x18008C10
#define DC_PHY_QOS_CTRL_1                                                            0x18008C14
#define DC_PHY_QOS_CTRL_2                                                            0x18008C18
#define DC_PHY_QOS_CTRL_3                                                            0x18008C1C
#define DC_PHY_QOS_CTRL_4                                                            0x18008C20
#define DC_PHY_QOS_CTRL_5                                                            0x18008C24
#define DC_PHY_QOS_CTRL_6                                                            0x18008C28
#define DC_PHY_QOS_CTRL_7                                                            0x18008C2C
#define DC_PHY_QOS_CTRL_8                                                            0x18008C30
#define DC_PHY_QOS_CTRL_9                                                            0x18008C34
#define DC_PHY_QOS_CTRL_10                                                            0x18008C38
#define DC_PHY_QOS_CTRL_11                                                            0x18008C3C
#define DC_PHY_QOS_CTRL_12                                                            0x18008C40
#define DC_PHY_QOS_CTRL_13                                                            0x18008C44
#define DC_PHY_QOS_CTRL_14                                                            0x18008C48
#define DC_PHY_QOS_CTRL_15                                                            0x18008C4C
#define DC_PHY_QOS_CTRL_0_reg_addr                                                   "0xB8008C10"
#define DC_PHY_QOS_CTRL_1_reg_addr                                                   "0xB8008C14"
#define DC_PHY_QOS_CTRL_2_reg_addr                                                   "0xB8008C18"
#define DC_PHY_QOS_CTRL_3_reg_addr                                                   "0xB8008C1C"
#define DC_PHY_QOS_CTRL_4_reg_addr                                                   "0xB8008C20"
#define DC_PHY_QOS_CTRL_5_reg_addr                                                   "0xB8008C24"
#define DC_PHY_QOS_CTRL_6_reg_addr                                                   "0xB8008C28"
#define DC_PHY_QOS_CTRL_7_reg_addr                                                   "0xB8008C2C"
#define DC_PHY_QOS_CTRL_8_reg_addr                                                   "0xB8008C30"
#define DC_PHY_QOS_CTRL_9_reg_addr                                                   "0xB8008C34"
#define DC_PHY_QOS_CTRL_10_reg_addr                                                   "0xB8008C38"
#define DC_PHY_QOS_CTRL_11_reg_addr                                                   "0xB8008C3C"
#define DC_PHY_QOS_CTRL_12_reg_addr                                                   "0xB8008C40"
#define DC_PHY_QOS_CTRL_13_reg_addr                                                   "0xB8008C44"
#define DC_PHY_QOS_CTRL_14_reg_addr                                                   "0xB8008C48"
#define DC_PHY_QOS_CTRL_15_reg_addr                                                   "0xB8008C4C"
#define DC_PHY_QOS_CTRL_0_reg                                                        0xB8008C10
#define DC_PHY_QOS_CTRL_1_reg                                                        0xB8008C14
#define DC_PHY_QOS_CTRL_2_reg                                                        0xB8008C18
#define DC_PHY_QOS_CTRL_3_reg                                                        0xB8008C1C
#define DC_PHY_QOS_CTRL_4_reg                                                        0xB8008C20
#define DC_PHY_QOS_CTRL_5_reg                                                        0xB8008C24
#define DC_PHY_QOS_CTRL_6_reg                                                        0xB8008C28
#define DC_PHY_QOS_CTRL_7_reg                                                        0xB8008C2C
#define DC_PHY_QOS_CTRL_8_reg                                                        0xB8008C30
#define DC_PHY_QOS_CTRL_9_reg                                                        0xB8008C34
#define DC_PHY_QOS_CTRL_10_reg                                                        0xB8008C38
#define DC_PHY_QOS_CTRL_11_reg                                                        0xB8008C3C
#define DC_PHY_QOS_CTRL_12_reg                                                        0xB8008C40
#define DC_PHY_QOS_CTRL_13_reg                                                        0xB8008C44
#define DC_PHY_QOS_CTRL_14_reg                                                        0xB8008C48
#define DC_PHY_QOS_CTRL_15_reg                                                        0xB8008C4C
#define set_DC_PHY_QOS_CTRL_0_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_CTRL_0_reg)=data)
#define set_DC_PHY_QOS_CTRL_1_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_CTRL_1_reg)=data)
#define set_DC_PHY_QOS_CTRL_2_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_CTRL_2_reg)=data)
#define set_DC_PHY_QOS_CTRL_3_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_CTRL_3_reg)=data)
#define set_DC_PHY_QOS_CTRL_4_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_CTRL_4_reg)=data)
#define set_DC_PHY_QOS_CTRL_5_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_CTRL_5_reg)=data)
#define set_DC_PHY_QOS_CTRL_6_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_CTRL_6_reg)=data)
#define set_DC_PHY_QOS_CTRL_7_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_CTRL_7_reg)=data)
#define set_DC_PHY_QOS_CTRL_8_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_CTRL_8_reg)=data)
#define set_DC_PHY_QOS_CTRL_9_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_CTRL_9_reg)=data)
#define set_DC_PHY_QOS_CTRL_10_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_CTRL_10_reg)=data)
#define set_DC_PHY_QOS_CTRL_11_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_CTRL_11_reg)=data)
#define set_DC_PHY_QOS_CTRL_12_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_CTRL_12_reg)=data)
#define set_DC_PHY_QOS_CTRL_13_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_CTRL_13_reg)=data)
#define set_DC_PHY_QOS_CTRL_14_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_CTRL_14_reg)=data)
#define set_DC_PHY_QOS_CTRL_15_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_CTRL_15_reg)=data)
#define get_DC_PHY_QOS_CTRL_0_reg   (*((volatile unsigned int*) DC_PHY_QOS_CTRL_0_reg))
#define get_DC_PHY_QOS_CTRL_1_reg   (*((volatile unsigned int*) DC_PHY_QOS_CTRL_1_reg))
#define get_DC_PHY_QOS_CTRL_2_reg   (*((volatile unsigned int*) DC_PHY_QOS_CTRL_2_reg))
#define get_DC_PHY_QOS_CTRL_3_reg   (*((volatile unsigned int*) DC_PHY_QOS_CTRL_3_reg))
#define get_DC_PHY_QOS_CTRL_4_reg   (*((volatile unsigned int*) DC_PHY_QOS_CTRL_4_reg))
#define get_DC_PHY_QOS_CTRL_5_reg   (*((volatile unsigned int*) DC_PHY_QOS_CTRL_5_reg))
#define get_DC_PHY_QOS_CTRL_6_reg   (*((volatile unsigned int*) DC_PHY_QOS_CTRL_6_reg))
#define get_DC_PHY_QOS_CTRL_7_reg   (*((volatile unsigned int*) DC_PHY_QOS_CTRL_7_reg))
#define get_DC_PHY_QOS_CTRL_8_reg   (*((volatile unsigned int*) DC_PHY_QOS_CTRL_8_reg))
#define get_DC_PHY_QOS_CTRL_9_reg   (*((volatile unsigned int*) DC_PHY_QOS_CTRL_9_reg))
#define get_DC_PHY_QOS_CTRL_10_reg   (*((volatile unsigned int*) DC_PHY_QOS_CTRL_10_reg))
#define get_DC_PHY_QOS_CTRL_11_reg   (*((volatile unsigned int*) DC_PHY_QOS_CTRL_11_reg))
#define get_DC_PHY_QOS_CTRL_12_reg   (*((volatile unsigned int*) DC_PHY_QOS_CTRL_12_reg))
#define get_DC_PHY_QOS_CTRL_13_reg   (*((volatile unsigned int*) DC_PHY_QOS_CTRL_13_reg))
#define get_DC_PHY_QOS_CTRL_14_reg   (*((volatile unsigned int*) DC_PHY_QOS_CTRL_14_reg))
#define get_DC_PHY_QOS_CTRL_15_reg   (*((volatile unsigned int*) DC_PHY_QOS_CTRL_15_reg))
#define DC_PHY_QOS_CTRL_0_inst_adr                                                   "0x0004"
#define DC_PHY_QOS_CTRL_1_inst_adr                                                   "0x0005"
#define DC_PHY_QOS_CTRL_2_inst_adr                                                   "0x0006"
#define DC_PHY_QOS_CTRL_3_inst_adr                                                   "0x0007"
#define DC_PHY_QOS_CTRL_4_inst_adr                                                   "0x0008"
#define DC_PHY_QOS_CTRL_5_inst_adr                                                   "0x0009"
#define DC_PHY_QOS_CTRL_6_inst_adr                                                   "0x000A"
#define DC_PHY_QOS_CTRL_7_inst_adr                                                   "0x000B"
#define DC_PHY_QOS_CTRL_8_inst_adr                                                   "0x000C"
#define DC_PHY_QOS_CTRL_9_inst_adr                                                   "0x000D"
#define DC_PHY_QOS_CTRL_10_inst_adr                                                   "0x000E"
#define DC_PHY_QOS_CTRL_11_inst_adr                                                   "0x000F"
#define DC_PHY_QOS_CTRL_12_inst_adr                                                   "0x0010"
#define DC_PHY_QOS_CTRL_13_inst_adr                                                   "0x0011"
#define DC_PHY_QOS_CTRL_14_inst_adr                                                   "0x0012"
#define DC_PHY_QOS_CTRL_15_inst_adr                                                   "0x0013"
#define DC_PHY_QOS_CTRL_0_inst                                                       0x0004
#define DC_PHY_QOS_CTRL_1_inst                                                       0x0005
#define DC_PHY_QOS_CTRL_2_inst                                                       0x0006
#define DC_PHY_QOS_CTRL_3_inst                                                       0x0007
#define DC_PHY_QOS_CTRL_4_inst                                                       0x0008
#define DC_PHY_QOS_CTRL_5_inst                                                       0x0009
#define DC_PHY_QOS_CTRL_6_inst                                                       0x000A
#define DC_PHY_QOS_CTRL_7_inst                                                       0x000B
#define DC_PHY_QOS_CTRL_8_inst                                                       0x000C
#define DC_PHY_QOS_CTRL_9_inst                                                       0x000D
#define DC_PHY_QOS_CTRL_10_inst                                                       0x000E
#define DC_PHY_QOS_CTRL_11_inst                                                       0x000F
#define DC_PHY_QOS_CTRL_12_inst                                                       0x0010
#define DC_PHY_QOS_CTRL_13_inst                                                       0x0011
#define DC_PHY_QOS_CTRL_14_inst                                                       0x0012
#define DC_PHY_QOS_CTRL_15_inst                                                       0x0013
#define DC_PHY_QOS_CTRL_occ_status_clear_shift                                       (31)
#define DC_PHY_QOS_CTRL_occ_status_clear_mask                                        (0x80000000)
#define DC_PHY_QOS_CTRL_occ_status_clear(data)                                       (0x80000000&((data)<<31))
#define DC_PHY_QOS_CTRL_occ_status_clear_src(data)                                   ((0x80000000&(data))>>31)
#define DC_PHY_QOS_CTRL_get_occ_status_clear(data)                                   ((0x80000000&(data))>>31)
#define DC_PHY_QOS_CTRL_ki_neg_shift                                                 (16)
#define DC_PHY_QOS_CTRL_ki_neg_mask                                                  (0x000F0000)
#define DC_PHY_QOS_CTRL_ki_neg(data)                                                 (0x000F0000&((data)<<16))
#define DC_PHY_QOS_CTRL_ki_neg_src(data)                                             ((0x000F0000&(data))>>16)
#define DC_PHY_QOS_CTRL_get_ki_neg(data)                                             ((0x000F0000&(data))>>16)
#define DC_PHY_QOS_CTRL_ki_pos_shift                                                 (8)
#define DC_PHY_QOS_CTRL_ki_pos_mask                                                  (0x00000F00)
#define DC_PHY_QOS_CTRL_ki_pos(data)                                                 (0x00000F00&((data)<<8))
#define DC_PHY_QOS_CTRL_ki_pos_src(data)                                             ((0x00000F00&(data))>>8)
#define DC_PHY_QOS_CTRL_get_ki_pos(data)                                             ((0x00000F00&(data))>>8)
#define DC_PHY_QOS_CTRL_ot_en_shift                                                  (4)
#define DC_PHY_QOS_CTRL_ot_en_mask                                                   (0x00000010)
#define DC_PHY_QOS_CTRL_ot_en(data)                                                  (0x00000010&((data)<<4))
#define DC_PHY_QOS_CTRL_ot_en_src(data)                                              ((0x00000010&(data))>>4)
#define DC_PHY_QOS_CTRL_get_ot_en(data)                                              ((0x00000010&(data))>>4)
#define DC_PHY_QOS_CTRL_stp_ref_cal_en_shift                                         (2)
#define DC_PHY_QOS_CTRL_stp_ref_cal_en_mask                                          (0x00000004)
#define DC_PHY_QOS_CTRL_stp_ref_cal_en(data)                                         (0x00000004&((data)<<2))
#define DC_PHY_QOS_CTRL_stp_ref_cal_en_src(data)                                     ((0x00000004&(data))>>2)
#define DC_PHY_QOS_CTRL_get_stp_ref_cal_en(data)                                     ((0x00000004&(data))>>2)
#define DC_PHY_QOS_CTRL_bw_en_shift                                                  (0)
#define DC_PHY_QOS_CTRL_bw_en_mask                                                   (0x00000001)
#define DC_PHY_QOS_CTRL_bw_en(data)                                                  (0x00000001&((data)<<0))
#define DC_PHY_QOS_CTRL_bw_en_src(data)                                              ((0x00000001&(data))>>0)
#define DC_PHY_QOS_CTRL_get_bw_en(data)                                              ((0x00000001&(data))>>0)


#define DC_PHY_QOS_OT_0                                                              0x18008C50
#define DC_PHY_QOS_OT_1                                                              0x18008C54
#define DC_PHY_QOS_OT_2                                                              0x18008C58
#define DC_PHY_QOS_OT_3                                                              0x18008C5C
#define DC_PHY_QOS_OT_4                                                              0x18008C60
#define DC_PHY_QOS_OT_5                                                              0x18008C64
#define DC_PHY_QOS_OT_6                                                              0x18008C68
#define DC_PHY_QOS_OT_7                                                              0x18008C6C
#define DC_PHY_QOS_OT_8                                                              0x18008C70
#define DC_PHY_QOS_OT_9                                                              0x18008C74
#define DC_PHY_QOS_OT_10                                                              0x18008C78
#define DC_PHY_QOS_OT_11                                                              0x18008C7C
#define DC_PHY_QOS_OT_12                                                              0x18008C80
#define DC_PHY_QOS_OT_13                                                              0x18008C84
#define DC_PHY_QOS_OT_14                                                              0x18008C88
#define DC_PHY_QOS_OT_15                                                              0x18008C8C
#define DC_PHY_QOS_OT_0_reg_addr                                                     "0xB8008C50"
#define DC_PHY_QOS_OT_1_reg_addr                                                     "0xB8008C54"
#define DC_PHY_QOS_OT_2_reg_addr                                                     "0xB8008C58"
#define DC_PHY_QOS_OT_3_reg_addr                                                     "0xB8008C5C"
#define DC_PHY_QOS_OT_4_reg_addr                                                     "0xB8008C60"
#define DC_PHY_QOS_OT_5_reg_addr                                                     "0xB8008C64"
#define DC_PHY_QOS_OT_6_reg_addr                                                     "0xB8008C68"
#define DC_PHY_QOS_OT_7_reg_addr                                                     "0xB8008C6C"
#define DC_PHY_QOS_OT_8_reg_addr                                                     "0xB8008C70"
#define DC_PHY_QOS_OT_9_reg_addr                                                     "0xB8008C74"
#define DC_PHY_QOS_OT_10_reg_addr                                                     "0xB8008C78"
#define DC_PHY_QOS_OT_11_reg_addr                                                     "0xB8008C7C"
#define DC_PHY_QOS_OT_12_reg_addr                                                     "0xB8008C80"
#define DC_PHY_QOS_OT_13_reg_addr                                                     "0xB8008C84"
#define DC_PHY_QOS_OT_14_reg_addr                                                     "0xB8008C88"
#define DC_PHY_QOS_OT_15_reg_addr                                                     "0xB8008C8C"
#define DC_PHY_QOS_OT_0_reg                                                          0xB8008C50
#define DC_PHY_QOS_OT_1_reg                                                          0xB8008C54
#define DC_PHY_QOS_OT_2_reg                                                          0xB8008C58
#define DC_PHY_QOS_OT_3_reg                                                          0xB8008C5C
#define DC_PHY_QOS_OT_4_reg                                                          0xB8008C60
#define DC_PHY_QOS_OT_5_reg                                                          0xB8008C64
#define DC_PHY_QOS_OT_6_reg                                                          0xB8008C68
#define DC_PHY_QOS_OT_7_reg                                                          0xB8008C6C
#define DC_PHY_QOS_OT_8_reg                                                          0xB8008C70
#define DC_PHY_QOS_OT_9_reg                                                          0xB8008C74
#define DC_PHY_QOS_OT_10_reg                                                          0xB8008C78
#define DC_PHY_QOS_OT_11_reg                                                          0xB8008C7C
#define DC_PHY_QOS_OT_12_reg                                                          0xB8008C80
#define DC_PHY_QOS_OT_13_reg                                                          0xB8008C84
#define DC_PHY_QOS_OT_14_reg                                                          0xB8008C88
#define DC_PHY_QOS_OT_15_reg                                                          0xB8008C8C
#define set_DC_PHY_QOS_OT_0_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_OT_0_reg)=data)
#define set_DC_PHY_QOS_OT_1_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_OT_1_reg)=data)
#define set_DC_PHY_QOS_OT_2_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_OT_2_reg)=data)
#define set_DC_PHY_QOS_OT_3_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_OT_3_reg)=data)
#define set_DC_PHY_QOS_OT_4_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_OT_4_reg)=data)
#define set_DC_PHY_QOS_OT_5_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_OT_5_reg)=data)
#define set_DC_PHY_QOS_OT_6_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_OT_6_reg)=data)
#define set_DC_PHY_QOS_OT_7_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_OT_7_reg)=data)
#define set_DC_PHY_QOS_OT_8_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_OT_8_reg)=data)
#define set_DC_PHY_QOS_OT_9_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_OT_9_reg)=data)
#define set_DC_PHY_QOS_OT_10_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_OT_10_reg)=data)
#define set_DC_PHY_QOS_OT_11_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_OT_11_reg)=data)
#define set_DC_PHY_QOS_OT_12_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_OT_12_reg)=data)
#define set_DC_PHY_QOS_OT_13_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_OT_13_reg)=data)
#define set_DC_PHY_QOS_OT_14_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_OT_14_reg)=data)
#define set_DC_PHY_QOS_OT_15_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_OT_15_reg)=data)
#define get_DC_PHY_QOS_OT_0_reg   (*((volatile unsigned int*) DC_PHY_QOS_OT_0_reg))
#define get_DC_PHY_QOS_OT_1_reg   (*((volatile unsigned int*) DC_PHY_QOS_OT_1_reg))
#define get_DC_PHY_QOS_OT_2_reg   (*((volatile unsigned int*) DC_PHY_QOS_OT_2_reg))
#define get_DC_PHY_QOS_OT_3_reg   (*((volatile unsigned int*) DC_PHY_QOS_OT_3_reg))
#define get_DC_PHY_QOS_OT_4_reg   (*((volatile unsigned int*) DC_PHY_QOS_OT_4_reg))
#define get_DC_PHY_QOS_OT_5_reg   (*((volatile unsigned int*) DC_PHY_QOS_OT_5_reg))
#define get_DC_PHY_QOS_OT_6_reg   (*((volatile unsigned int*) DC_PHY_QOS_OT_6_reg))
#define get_DC_PHY_QOS_OT_7_reg   (*((volatile unsigned int*) DC_PHY_QOS_OT_7_reg))
#define get_DC_PHY_QOS_OT_8_reg   (*((volatile unsigned int*) DC_PHY_QOS_OT_8_reg))
#define get_DC_PHY_QOS_OT_9_reg   (*((volatile unsigned int*) DC_PHY_QOS_OT_9_reg))
#define get_DC_PHY_QOS_OT_10_reg   (*((volatile unsigned int*) DC_PHY_QOS_OT_10_reg))
#define get_DC_PHY_QOS_OT_11_reg   (*((volatile unsigned int*) DC_PHY_QOS_OT_11_reg))
#define get_DC_PHY_QOS_OT_12_reg   (*((volatile unsigned int*) DC_PHY_QOS_OT_12_reg))
#define get_DC_PHY_QOS_OT_13_reg   (*((volatile unsigned int*) DC_PHY_QOS_OT_13_reg))
#define get_DC_PHY_QOS_OT_14_reg   (*((volatile unsigned int*) DC_PHY_QOS_OT_14_reg))
#define get_DC_PHY_QOS_OT_15_reg   (*((volatile unsigned int*) DC_PHY_QOS_OT_15_reg))
#define DC_PHY_QOS_OT_0_inst_adr                                                     "0x0014"
#define DC_PHY_QOS_OT_1_inst_adr                                                     "0x0015"
#define DC_PHY_QOS_OT_2_inst_adr                                                     "0x0016"
#define DC_PHY_QOS_OT_3_inst_adr                                                     "0x0017"
#define DC_PHY_QOS_OT_4_inst_adr                                                     "0x0018"
#define DC_PHY_QOS_OT_5_inst_adr                                                     "0x0019"
#define DC_PHY_QOS_OT_6_inst_adr                                                     "0x001A"
#define DC_PHY_QOS_OT_7_inst_adr                                                     "0x001B"
#define DC_PHY_QOS_OT_8_inst_adr                                                     "0x001C"
#define DC_PHY_QOS_OT_9_inst_adr                                                     "0x001D"
#define DC_PHY_QOS_OT_10_inst_adr                                                     "0x001E"
#define DC_PHY_QOS_OT_11_inst_adr                                                     "0x001F"
#define DC_PHY_QOS_OT_12_inst_adr                                                     "0x0020"
#define DC_PHY_QOS_OT_13_inst_adr                                                     "0x0021"
#define DC_PHY_QOS_OT_14_inst_adr                                                     "0x0022"
#define DC_PHY_QOS_OT_15_inst_adr                                                     "0x0023"
#define DC_PHY_QOS_OT_0_inst                                                         0x0014
#define DC_PHY_QOS_OT_1_inst                                                         0x0015
#define DC_PHY_QOS_OT_2_inst                                                         0x0016
#define DC_PHY_QOS_OT_3_inst                                                         0x0017
#define DC_PHY_QOS_OT_4_inst                                                         0x0018
#define DC_PHY_QOS_OT_5_inst                                                         0x0019
#define DC_PHY_QOS_OT_6_inst                                                         0x001A
#define DC_PHY_QOS_OT_7_inst                                                         0x001B
#define DC_PHY_QOS_OT_8_inst                                                         0x001C
#define DC_PHY_QOS_OT_9_inst                                                         0x001D
#define DC_PHY_QOS_OT_10_inst                                                         0x001E
#define DC_PHY_QOS_OT_11_inst                                                         0x001F
#define DC_PHY_QOS_OT_12_inst                                                         0x0020
#define DC_PHY_QOS_OT_13_inst                                                         0x0021
#define DC_PHY_QOS_OT_14_inst                                                         0x0022
#define DC_PHY_QOS_OT_15_inst                                                         0x0023
#define DC_PHY_QOS_OT_max_oti_shift                                                  (8)
#define DC_PHY_QOS_OT_max_oti_mask                                                   (0x00000F00)
#define DC_PHY_QOS_OT_max_oti(data)                                                  (0x00000F00&((data)<<8))
#define DC_PHY_QOS_OT_max_oti_src(data)                                              ((0x00000F00&(data))>>8)
#define DC_PHY_QOS_OT_get_max_oti(data)                                              ((0x00000F00&(data))>>8)
#define DC_PHY_QOS_OT_max_otf_shift                                                  (0)
#define DC_PHY_QOS_OT_max_otf_mask                                                   (0x000000FF)
#define DC_PHY_QOS_OT_max_otf(data)                                                  (0x000000FF&((data)<<0))
#define DC_PHY_QOS_OT_max_otf_src(data)                                              ((0x000000FF&(data))>>0)
#define DC_PHY_QOS_OT_get_max_otf(data)                                              ((0x000000FF&(data))>>0)


#define DC_PHY_QOS_BW0_0                                                             0x18008C90
#define DC_PHY_QOS_BW0_1                                                             0x18008C94
#define DC_PHY_QOS_BW0_2                                                             0x18008C98
#define DC_PHY_QOS_BW0_3                                                             0x18008C9C
#define DC_PHY_QOS_BW0_4                                                             0x18008CA0
#define DC_PHY_QOS_BW0_5                                                             0x18008CA4
#define DC_PHY_QOS_BW0_6                                                             0x18008CA8
#define DC_PHY_QOS_BW0_7                                                             0x18008CAC
#define DC_PHY_QOS_BW0_8                                                             0x18008CB0
#define DC_PHY_QOS_BW0_9                                                             0x18008CB4
#define DC_PHY_QOS_BW0_10                                                             0x18008CB8
#define DC_PHY_QOS_BW0_11                                                             0x18008CBC
#define DC_PHY_QOS_BW0_12                                                             0x18008CC0
#define DC_PHY_QOS_BW0_13                                                             0x18008CC4
#define DC_PHY_QOS_BW0_14                                                             0x18008CC8
#define DC_PHY_QOS_BW0_15                                                             0x18008CCC
#define DC_PHY_QOS_BW0_0_reg_addr                                                    "0xB8008C90"
#define DC_PHY_QOS_BW0_1_reg_addr                                                    "0xB8008C94"
#define DC_PHY_QOS_BW0_2_reg_addr                                                    "0xB8008C98"
#define DC_PHY_QOS_BW0_3_reg_addr                                                    "0xB8008C9C"
#define DC_PHY_QOS_BW0_4_reg_addr                                                    "0xB8008CA0"
#define DC_PHY_QOS_BW0_5_reg_addr                                                    "0xB8008CA4"
#define DC_PHY_QOS_BW0_6_reg_addr                                                    "0xB8008CA8"
#define DC_PHY_QOS_BW0_7_reg_addr                                                    "0xB8008CAC"
#define DC_PHY_QOS_BW0_8_reg_addr                                                    "0xB8008CB0"
#define DC_PHY_QOS_BW0_9_reg_addr                                                    "0xB8008CB4"
#define DC_PHY_QOS_BW0_10_reg_addr                                                    "0xB8008CB8"
#define DC_PHY_QOS_BW0_11_reg_addr                                                    "0xB8008CBC"
#define DC_PHY_QOS_BW0_12_reg_addr                                                    "0xB8008CC0"
#define DC_PHY_QOS_BW0_13_reg_addr                                                    "0xB8008CC4"
#define DC_PHY_QOS_BW0_14_reg_addr                                                    "0xB8008CC8"
#define DC_PHY_QOS_BW0_15_reg_addr                                                    "0xB8008CCC"
#define DC_PHY_QOS_BW0_0_reg                                                         0xB8008C90
#define DC_PHY_QOS_BW0_1_reg                                                         0xB8008C94
#define DC_PHY_QOS_BW0_2_reg                                                         0xB8008C98
#define DC_PHY_QOS_BW0_3_reg                                                         0xB8008C9C
#define DC_PHY_QOS_BW0_4_reg                                                         0xB8008CA0
#define DC_PHY_QOS_BW0_5_reg                                                         0xB8008CA4
#define DC_PHY_QOS_BW0_6_reg                                                         0xB8008CA8
#define DC_PHY_QOS_BW0_7_reg                                                         0xB8008CAC
#define DC_PHY_QOS_BW0_8_reg                                                         0xB8008CB0
#define DC_PHY_QOS_BW0_9_reg                                                         0xB8008CB4
#define DC_PHY_QOS_BW0_10_reg                                                         0xB8008CB8
#define DC_PHY_QOS_BW0_11_reg                                                         0xB8008CBC
#define DC_PHY_QOS_BW0_12_reg                                                         0xB8008CC0
#define DC_PHY_QOS_BW0_13_reg                                                         0xB8008CC4
#define DC_PHY_QOS_BW0_14_reg                                                         0xB8008CC8
#define DC_PHY_QOS_BW0_15_reg                                                         0xB8008CCC
#define set_DC_PHY_QOS_BW0_0_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW0_0_reg)=data)
#define set_DC_PHY_QOS_BW0_1_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW0_1_reg)=data)
#define set_DC_PHY_QOS_BW0_2_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW0_2_reg)=data)
#define set_DC_PHY_QOS_BW0_3_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW0_3_reg)=data)
#define set_DC_PHY_QOS_BW0_4_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW0_4_reg)=data)
#define set_DC_PHY_QOS_BW0_5_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW0_5_reg)=data)
#define set_DC_PHY_QOS_BW0_6_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW0_6_reg)=data)
#define set_DC_PHY_QOS_BW0_7_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW0_7_reg)=data)
#define set_DC_PHY_QOS_BW0_8_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW0_8_reg)=data)
#define set_DC_PHY_QOS_BW0_9_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW0_9_reg)=data)
#define set_DC_PHY_QOS_BW0_10_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW0_10_reg)=data)
#define set_DC_PHY_QOS_BW0_11_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW0_11_reg)=data)
#define set_DC_PHY_QOS_BW0_12_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW0_12_reg)=data)
#define set_DC_PHY_QOS_BW0_13_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW0_13_reg)=data)
#define set_DC_PHY_QOS_BW0_14_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW0_14_reg)=data)
#define set_DC_PHY_QOS_BW0_15_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW0_15_reg)=data)
#define get_DC_PHY_QOS_BW0_0_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW0_0_reg))
#define get_DC_PHY_QOS_BW0_1_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW0_1_reg))
#define get_DC_PHY_QOS_BW0_2_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW0_2_reg))
#define get_DC_PHY_QOS_BW0_3_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW0_3_reg))
#define get_DC_PHY_QOS_BW0_4_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW0_4_reg))
#define get_DC_PHY_QOS_BW0_5_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW0_5_reg))
#define get_DC_PHY_QOS_BW0_6_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW0_6_reg))
#define get_DC_PHY_QOS_BW0_7_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW0_7_reg))
#define get_DC_PHY_QOS_BW0_8_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW0_8_reg))
#define get_DC_PHY_QOS_BW0_9_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW0_9_reg))
#define get_DC_PHY_QOS_BW0_10_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW0_10_reg))
#define get_DC_PHY_QOS_BW0_11_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW0_11_reg))
#define get_DC_PHY_QOS_BW0_12_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW0_12_reg))
#define get_DC_PHY_QOS_BW0_13_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW0_13_reg))
#define get_DC_PHY_QOS_BW0_14_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW0_14_reg))
#define get_DC_PHY_QOS_BW0_15_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW0_15_reg))
#define DC_PHY_QOS_BW0_0_inst_adr                                                    "0x0024"
#define DC_PHY_QOS_BW0_1_inst_adr                                                    "0x0025"
#define DC_PHY_QOS_BW0_2_inst_adr                                                    "0x0026"
#define DC_PHY_QOS_BW0_3_inst_adr                                                    "0x0027"
#define DC_PHY_QOS_BW0_4_inst_adr                                                    "0x0028"
#define DC_PHY_QOS_BW0_5_inst_adr                                                    "0x0029"
#define DC_PHY_QOS_BW0_6_inst_adr                                                    "0x002A"
#define DC_PHY_QOS_BW0_7_inst_adr                                                    "0x002B"
#define DC_PHY_QOS_BW0_8_inst_adr                                                    "0x002C"
#define DC_PHY_QOS_BW0_9_inst_adr                                                    "0x002D"
#define DC_PHY_QOS_BW0_10_inst_adr                                                    "0x002E"
#define DC_PHY_QOS_BW0_11_inst_adr                                                    "0x002F"
#define DC_PHY_QOS_BW0_12_inst_adr                                                    "0x0030"
#define DC_PHY_QOS_BW0_13_inst_adr                                                    "0x0031"
#define DC_PHY_QOS_BW0_14_inst_adr                                                    "0x0032"
#define DC_PHY_QOS_BW0_15_inst_adr                                                    "0x0033"
#define DC_PHY_QOS_BW0_0_inst                                                        0x0024
#define DC_PHY_QOS_BW0_1_inst                                                        0x0025
#define DC_PHY_QOS_BW0_2_inst                                                        0x0026
#define DC_PHY_QOS_BW0_3_inst                                                        0x0027
#define DC_PHY_QOS_BW0_4_inst                                                        0x0028
#define DC_PHY_QOS_BW0_5_inst                                                        0x0029
#define DC_PHY_QOS_BW0_6_inst                                                        0x002A
#define DC_PHY_QOS_BW0_7_inst                                                        0x002B
#define DC_PHY_QOS_BW0_8_inst                                                        0x002C
#define DC_PHY_QOS_BW0_9_inst                                                        0x002D
#define DC_PHY_QOS_BW0_10_inst                                                        0x002E
#define DC_PHY_QOS_BW0_11_inst                                                        0x002F
#define DC_PHY_QOS_BW0_12_inst                                                        0x0030
#define DC_PHY_QOS_BW0_13_inst                                                        0x0031
#define DC_PHY_QOS_BW0_14_inst                                                        0x0032
#define DC_PHY_QOS_BW0_15_inst                                                        0x0033
#define DC_PHY_QOS_BW0_idle_period_shift                                             (8)
#define DC_PHY_QOS_BW0_idle_period_mask                                              (0x00FFFF00)
#define DC_PHY_QOS_BW0_idle_period(data)                                             (0x00FFFF00&((data)<<8))
#define DC_PHY_QOS_BW0_idle_period_src(data)                                         ((0x00FFFF00&(data))>>8)
#define DC_PHY_QOS_BW0_get_idle_period(data)                                         ((0x00FFFF00&(data))>>8)
#define DC_PHY_QOS_BW0_add_data_shift                                                (0)
#define DC_PHY_QOS_BW0_add_data_mask                                                 (0x000000FF)
#define DC_PHY_QOS_BW0_add_data(data)                                                (0x000000FF&((data)<<0))
#define DC_PHY_QOS_BW0_add_data_src(data)                                            ((0x000000FF&(data))>>0)
#define DC_PHY_QOS_BW0_get_add_data(data)                                            ((0x000000FF&(data))>>0)


#define DC_PHY_QOS_BW1_0                                                             0x18008CD0
#define DC_PHY_QOS_BW1_1                                                             0x18008CD4
#define DC_PHY_QOS_BW1_2                                                             0x18008CD8
#define DC_PHY_QOS_BW1_3                                                             0x18008CDC
#define DC_PHY_QOS_BW1_4                                                             0x18008CE0
#define DC_PHY_QOS_BW1_5                                                             0x18008CE4
#define DC_PHY_QOS_BW1_6                                                             0x18008CE8
#define DC_PHY_QOS_BW1_7                                                             0x18008CEC
#define DC_PHY_QOS_BW1_8                                                             0x18008CF0
#define DC_PHY_QOS_BW1_9                                                             0x18008CF4
#define DC_PHY_QOS_BW1_10                                                             0x18008CF8
#define DC_PHY_QOS_BW1_11                                                             0x18008CFC
#define DC_PHY_QOS_BW1_12                                                             0x18008D00
#define DC_PHY_QOS_BW1_13                                                             0x18008D04
#define DC_PHY_QOS_BW1_14                                                             0x18008D08
#define DC_PHY_QOS_BW1_15                                                             0x18008D0C
#define DC_PHY_QOS_BW1_0_reg_addr                                                    "0xB8008CD0"
#define DC_PHY_QOS_BW1_1_reg_addr                                                    "0xB8008CD4"
#define DC_PHY_QOS_BW1_2_reg_addr                                                    "0xB8008CD8"
#define DC_PHY_QOS_BW1_3_reg_addr                                                    "0xB8008CDC"
#define DC_PHY_QOS_BW1_4_reg_addr                                                    "0xB8008CE0"
#define DC_PHY_QOS_BW1_5_reg_addr                                                    "0xB8008CE4"
#define DC_PHY_QOS_BW1_6_reg_addr                                                    "0xB8008CE8"
#define DC_PHY_QOS_BW1_7_reg_addr                                                    "0xB8008CEC"
#define DC_PHY_QOS_BW1_8_reg_addr                                                    "0xB8008CF0"
#define DC_PHY_QOS_BW1_9_reg_addr                                                    "0xB8008CF4"
#define DC_PHY_QOS_BW1_10_reg_addr                                                    "0xB8008CF8"
#define DC_PHY_QOS_BW1_11_reg_addr                                                    "0xB8008CFC"
#define DC_PHY_QOS_BW1_12_reg_addr                                                    "0xB8008D00"
#define DC_PHY_QOS_BW1_13_reg_addr                                                    "0xB8008D04"
#define DC_PHY_QOS_BW1_14_reg_addr                                                    "0xB8008D08"
#define DC_PHY_QOS_BW1_15_reg_addr                                                    "0xB8008D0C"
#define DC_PHY_QOS_BW1_0_reg                                                         0xB8008CD0
#define DC_PHY_QOS_BW1_1_reg                                                         0xB8008CD4
#define DC_PHY_QOS_BW1_2_reg                                                         0xB8008CD8
#define DC_PHY_QOS_BW1_3_reg                                                         0xB8008CDC
#define DC_PHY_QOS_BW1_4_reg                                                         0xB8008CE0
#define DC_PHY_QOS_BW1_5_reg                                                         0xB8008CE4
#define DC_PHY_QOS_BW1_6_reg                                                         0xB8008CE8
#define DC_PHY_QOS_BW1_7_reg                                                         0xB8008CEC
#define DC_PHY_QOS_BW1_8_reg                                                         0xB8008CF0
#define DC_PHY_QOS_BW1_9_reg                                                         0xB8008CF4
#define DC_PHY_QOS_BW1_10_reg                                                         0xB8008CF8
#define DC_PHY_QOS_BW1_11_reg                                                         0xB8008CFC
#define DC_PHY_QOS_BW1_12_reg                                                         0xB8008D00
#define DC_PHY_QOS_BW1_13_reg                                                         0xB8008D04
#define DC_PHY_QOS_BW1_14_reg                                                         0xB8008D08
#define DC_PHY_QOS_BW1_15_reg                                                         0xB8008D0C
#define set_DC_PHY_QOS_BW1_0_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW1_0_reg)=data)
#define set_DC_PHY_QOS_BW1_1_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW1_1_reg)=data)
#define set_DC_PHY_QOS_BW1_2_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW1_2_reg)=data)
#define set_DC_PHY_QOS_BW1_3_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW1_3_reg)=data)
#define set_DC_PHY_QOS_BW1_4_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW1_4_reg)=data)
#define set_DC_PHY_QOS_BW1_5_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW1_5_reg)=data)
#define set_DC_PHY_QOS_BW1_6_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW1_6_reg)=data)
#define set_DC_PHY_QOS_BW1_7_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW1_7_reg)=data)
#define set_DC_PHY_QOS_BW1_8_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW1_8_reg)=data)
#define set_DC_PHY_QOS_BW1_9_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW1_9_reg)=data)
#define set_DC_PHY_QOS_BW1_10_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW1_10_reg)=data)
#define set_DC_PHY_QOS_BW1_11_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW1_11_reg)=data)
#define set_DC_PHY_QOS_BW1_12_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW1_12_reg)=data)
#define set_DC_PHY_QOS_BW1_13_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW1_13_reg)=data)
#define set_DC_PHY_QOS_BW1_14_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW1_14_reg)=data)
#define set_DC_PHY_QOS_BW1_15_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW1_15_reg)=data)
#define get_DC_PHY_QOS_BW1_0_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW1_0_reg))
#define get_DC_PHY_QOS_BW1_1_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW1_1_reg))
#define get_DC_PHY_QOS_BW1_2_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW1_2_reg))
#define get_DC_PHY_QOS_BW1_3_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW1_3_reg))
#define get_DC_PHY_QOS_BW1_4_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW1_4_reg))
#define get_DC_PHY_QOS_BW1_5_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW1_5_reg))
#define get_DC_PHY_QOS_BW1_6_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW1_6_reg))
#define get_DC_PHY_QOS_BW1_7_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW1_7_reg))
#define get_DC_PHY_QOS_BW1_8_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW1_8_reg))
#define get_DC_PHY_QOS_BW1_9_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW1_9_reg))
#define get_DC_PHY_QOS_BW1_10_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW1_10_reg))
#define get_DC_PHY_QOS_BW1_11_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW1_11_reg))
#define get_DC_PHY_QOS_BW1_12_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW1_12_reg))
#define get_DC_PHY_QOS_BW1_13_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW1_13_reg))
#define get_DC_PHY_QOS_BW1_14_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW1_14_reg))
#define get_DC_PHY_QOS_BW1_15_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW1_15_reg))
#define DC_PHY_QOS_BW1_0_inst_adr                                                    "0x0034"
#define DC_PHY_QOS_BW1_1_inst_adr                                                    "0x0035"
#define DC_PHY_QOS_BW1_2_inst_adr                                                    "0x0036"
#define DC_PHY_QOS_BW1_3_inst_adr                                                    "0x0037"
#define DC_PHY_QOS_BW1_4_inst_adr                                                    "0x0038"
#define DC_PHY_QOS_BW1_5_inst_adr                                                    "0x0039"
#define DC_PHY_QOS_BW1_6_inst_adr                                                    "0x003A"
#define DC_PHY_QOS_BW1_7_inst_adr                                                    "0x003B"
#define DC_PHY_QOS_BW1_8_inst_adr                                                    "0x003C"
#define DC_PHY_QOS_BW1_9_inst_adr                                                    "0x003D"
#define DC_PHY_QOS_BW1_10_inst_adr                                                    "0x003E"
#define DC_PHY_QOS_BW1_11_inst_adr                                                    "0x003F"
#define DC_PHY_QOS_BW1_12_inst_adr                                                    "0x0040"
#define DC_PHY_QOS_BW1_13_inst_adr                                                    "0x0041"
#define DC_PHY_QOS_BW1_14_inst_adr                                                    "0x0042"
#define DC_PHY_QOS_BW1_15_inst_adr                                                    "0x0043"
#define DC_PHY_QOS_BW1_0_inst                                                        0x0034
#define DC_PHY_QOS_BW1_1_inst                                                        0x0035
#define DC_PHY_QOS_BW1_2_inst                                                        0x0036
#define DC_PHY_QOS_BW1_3_inst                                                        0x0037
#define DC_PHY_QOS_BW1_4_inst                                                        0x0038
#define DC_PHY_QOS_BW1_5_inst                                                        0x0039
#define DC_PHY_QOS_BW1_6_inst                                                        0x003A
#define DC_PHY_QOS_BW1_7_inst                                                        0x003B
#define DC_PHY_QOS_BW1_8_inst                                                        0x003C
#define DC_PHY_QOS_BW1_9_inst                                                        0x003D
#define DC_PHY_QOS_BW1_10_inst                                                        0x003E
#define DC_PHY_QOS_BW1_11_inst                                                        0x003F
#define DC_PHY_QOS_BW1_12_inst                                                        0x0040
#define DC_PHY_QOS_BW1_13_inst                                                        0x0041
#define DC_PHY_QOS_BW1_14_inst                                                        0x0042
#define DC_PHY_QOS_BW1_15_inst                                                        0x0043
#define DC_PHY_QOS_BW1_max_data_shift                                                (16)
#define DC_PHY_QOS_BW1_max_data_mask                                                 (0xFFFF0000)
#define DC_PHY_QOS_BW1_max_data(data)                                                (0xFFFF0000&((data)<<16))
#define DC_PHY_QOS_BW1_max_data_src(data)                                            ((0xFFFF0000&(data))>>16)
#define DC_PHY_QOS_BW1_get_max_data(data)                                            ((0xFFFF0000&(data))>>16)
#define DC_PHY_QOS_BW1_min_data_shift                                                (0)
#define DC_PHY_QOS_BW1_min_data_mask                                                 (0x0000FFFF)
#define DC_PHY_QOS_BW1_min_data(data)                                                (0x0000FFFF&((data)<<0))
#define DC_PHY_QOS_BW1_min_data_src(data)                                            ((0x0000FFFF&(data))>>0)
#define DC_PHY_QOS_BW1_get_min_data(data)                                            ((0x0000FFFF&(data))>>0)


#define DC_PHY_QOS_BW2_0                                                             0x18008D10
#define DC_PHY_QOS_BW2_1                                                             0x18008D14
#define DC_PHY_QOS_BW2_2                                                             0x18008D18
#define DC_PHY_QOS_BW2_3                                                             0x18008D1C
#define DC_PHY_QOS_BW2_4                                                             0x18008D20
#define DC_PHY_QOS_BW2_5                                                             0x18008D24
#define DC_PHY_QOS_BW2_6                                                             0x18008D28
#define DC_PHY_QOS_BW2_7                                                             0x18008D2C
#define DC_PHY_QOS_BW2_8                                                             0x18008D30
#define DC_PHY_QOS_BW2_9                                                             0x18008D34
#define DC_PHY_QOS_BW2_10                                                             0x18008D38
#define DC_PHY_QOS_BW2_11                                                             0x18008D3C
#define DC_PHY_QOS_BW2_12                                                             0x18008D40
#define DC_PHY_QOS_BW2_13                                                             0x18008D44
#define DC_PHY_QOS_BW2_14                                                             0x18008D48
#define DC_PHY_QOS_BW2_15                                                             0x18008D4C
#define DC_PHY_QOS_BW2_0_reg_addr                                                    "0xB8008D10"
#define DC_PHY_QOS_BW2_1_reg_addr                                                    "0xB8008D14"
#define DC_PHY_QOS_BW2_2_reg_addr                                                    "0xB8008D18"
#define DC_PHY_QOS_BW2_3_reg_addr                                                    "0xB8008D1C"
#define DC_PHY_QOS_BW2_4_reg_addr                                                    "0xB8008D20"
#define DC_PHY_QOS_BW2_5_reg_addr                                                    "0xB8008D24"
#define DC_PHY_QOS_BW2_6_reg_addr                                                    "0xB8008D28"
#define DC_PHY_QOS_BW2_7_reg_addr                                                    "0xB8008D2C"
#define DC_PHY_QOS_BW2_8_reg_addr                                                    "0xB8008D30"
#define DC_PHY_QOS_BW2_9_reg_addr                                                    "0xB8008D34"
#define DC_PHY_QOS_BW2_10_reg_addr                                                    "0xB8008D38"
#define DC_PHY_QOS_BW2_11_reg_addr                                                    "0xB8008D3C"
#define DC_PHY_QOS_BW2_12_reg_addr                                                    "0xB8008D40"
#define DC_PHY_QOS_BW2_13_reg_addr                                                    "0xB8008D44"
#define DC_PHY_QOS_BW2_14_reg_addr                                                    "0xB8008D48"
#define DC_PHY_QOS_BW2_15_reg_addr                                                    "0xB8008D4C"
#define DC_PHY_QOS_BW2_0_reg                                                         0xB8008D10
#define DC_PHY_QOS_BW2_1_reg                                                         0xB8008D14
#define DC_PHY_QOS_BW2_2_reg                                                         0xB8008D18
#define DC_PHY_QOS_BW2_3_reg                                                         0xB8008D1C
#define DC_PHY_QOS_BW2_4_reg                                                         0xB8008D20
#define DC_PHY_QOS_BW2_5_reg                                                         0xB8008D24
#define DC_PHY_QOS_BW2_6_reg                                                         0xB8008D28
#define DC_PHY_QOS_BW2_7_reg                                                         0xB8008D2C
#define DC_PHY_QOS_BW2_8_reg                                                         0xB8008D30
#define DC_PHY_QOS_BW2_9_reg                                                         0xB8008D34
#define DC_PHY_QOS_BW2_10_reg                                                         0xB8008D38
#define DC_PHY_QOS_BW2_11_reg                                                         0xB8008D3C
#define DC_PHY_QOS_BW2_12_reg                                                         0xB8008D40
#define DC_PHY_QOS_BW2_13_reg                                                         0xB8008D44
#define DC_PHY_QOS_BW2_14_reg                                                         0xB8008D48
#define DC_PHY_QOS_BW2_15_reg                                                         0xB8008D4C
#define set_DC_PHY_QOS_BW2_0_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW2_0_reg)=data)
#define set_DC_PHY_QOS_BW2_1_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW2_1_reg)=data)
#define set_DC_PHY_QOS_BW2_2_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW2_2_reg)=data)
#define set_DC_PHY_QOS_BW2_3_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW2_3_reg)=data)
#define set_DC_PHY_QOS_BW2_4_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW2_4_reg)=data)
#define set_DC_PHY_QOS_BW2_5_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW2_5_reg)=data)
#define set_DC_PHY_QOS_BW2_6_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW2_6_reg)=data)
#define set_DC_PHY_QOS_BW2_7_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW2_7_reg)=data)
#define set_DC_PHY_QOS_BW2_8_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW2_8_reg)=data)
#define set_DC_PHY_QOS_BW2_9_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW2_9_reg)=data)
#define set_DC_PHY_QOS_BW2_10_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW2_10_reg)=data)
#define set_DC_PHY_QOS_BW2_11_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW2_11_reg)=data)
#define set_DC_PHY_QOS_BW2_12_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW2_12_reg)=data)
#define set_DC_PHY_QOS_BW2_13_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW2_13_reg)=data)
#define set_DC_PHY_QOS_BW2_14_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW2_14_reg)=data)
#define set_DC_PHY_QOS_BW2_15_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW2_15_reg)=data)
#define get_DC_PHY_QOS_BW2_0_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW2_0_reg))
#define get_DC_PHY_QOS_BW2_1_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW2_1_reg))
#define get_DC_PHY_QOS_BW2_2_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW2_2_reg))
#define get_DC_PHY_QOS_BW2_3_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW2_3_reg))
#define get_DC_PHY_QOS_BW2_4_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW2_4_reg))
#define get_DC_PHY_QOS_BW2_5_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW2_5_reg))
#define get_DC_PHY_QOS_BW2_6_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW2_6_reg))
#define get_DC_PHY_QOS_BW2_7_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW2_7_reg))
#define get_DC_PHY_QOS_BW2_8_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW2_8_reg))
#define get_DC_PHY_QOS_BW2_9_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW2_9_reg))
#define get_DC_PHY_QOS_BW2_10_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW2_10_reg))
#define get_DC_PHY_QOS_BW2_11_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW2_11_reg))
#define get_DC_PHY_QOS_BW2_12_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW2_12_reg))
#define get_DC_PHY_QOS_BW2_13_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW2_13_reg))
#define get_DC_PHY_QOS_BW2_14_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW2_14_reg))
#define get_DC_PHY_QOS_BW2_15_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW2_15_reg))
#define DC_PHY_QOS_BW2_0_inst_adr                                                    "0x0044"
#define DC_PHY_QOS_BW2_1_inst_adr                                                    "0x0045"
#define DC_PHY_QOS_BW2_2_inst_adr                                                    "0x0046"
#define DC_PHY_QOS_BW2_3_inst_adr                                                    "0x0047"
#define DC_PHY_QOS_BW2_4_inst_adr                                                    "0x0048"
#define DC_PHY_QOS_BW2_5_inst_adr                                                    "0x0049"
#define DC_PHY_QOS_BW2_6_inst_adr                                                    "0x004A"
#define DC_PHY_QOS_BW2_7_inst_adr                                                    "0x004B"
#define DC_PHY_QOS_BW2_8_inst_adr                                                    "0x004C"
#define DC_PHY_QOS_BW2_9_inst_adr                                                    "0x004D"
#define DC_PHY_QOS_BW2_10_inst_adr                                                    "0x004E"
#define DC_PHY_QOS_BW2_11_inst_adr                                                    "0x004F"
#define DC_PHY_QOS_BW2_12_inst_adr                                                    "0x0050"
#define DC_PHY_QOS_BW2_13_inst_adr                                                    "0x0051"
#define DC_PHY_QOS_BW2_14_inst_adr                                                    "0x0052"
#define DC_PHY_QOS_BW2_15_inst_adr                                                    "0x0053"
#define DC_PHY_QOS_BW2_0_inst                                                        0x0044
#define DC_PHY_QOS_BW2_1_inst                                                        0x0045
#define DC_PHY_QOS_BW2_2_inst                                                        0x0046
#define DC_PHY_QOS_BW2_3_inst                                                        0x0047
#define DC_PHY_QOS_BW2_4_inst                                                        0x0048
#define DC_PHY_QOS_BW2_5_inst                                                        0x0049
#define DC_PHY_QOS_BW2_6_inst                                                        0x004A
#define DC_PHY_QOS_BW2_7_inst                                                        0x004B
#define DC_PHY_QOS_BW2_8_inst                                                        0x004C
#define DC_PHY_QOS_BW2_9_inst                                                        0x004D
#define DC_PHY_QOS_BW2_10_inst                                                        0x004E
#define DC_PHY_QOS_BW2_11_inst                                                        0x004F
#define DC_PHY_QOS_BW2_12_inst                                                        0x0050
#define DC_PHY_QOS_BW2_13_inst                                                        0x0051
#define DC_PHY_QOS_BW2_14_inst                                                        0x0052
#define DC_PHY_QOS_BW2_15_inst                                                        0x0053
#define DC_PHY_QOS_BW2_max_pri_shift                                                 (16)
#define DC_PHY_QOS_BW2_max_pri_mask                                                  (0x00FF0000)
#define DC_PHY_QOS_BW2_max_pri(data)                                                 (0x00FF0000&((data)<<16))
#define DC_PHY_QOS_BW2_max_pri_src(data)                                             ((0x00FF0000&(data))>>16)
#define DC_PHY_QOS_BW2_get_max_pri(data)                                             ((0x00FF0000&(data))>>16)
#define DC_PHY_QOS_BW2_def_pri_shift                                                 (8)
#define DC_PHY_QOS_BW2_def_pri_mask                                                  (0x0000FF00)
#define DC_PHY_QOS_BW2_def_pri(data)                                                 (0x0000FF00&((data)<<8))
#define DC_PHY_QOS_BW2_def_pri_src(data)                                             ((0x0000FF00&(data))>>8)
#define DC_PHY_QOS_BW2_get_def_pri(data)                                             ((0x0000FF00&(data))>>8)
#define DC_PHY_QOS_BW2_min_pri_shift                                                 (0)
#define DC_PHY_QOS_BW2_min_pri_mask                                                  (0x000000FF)
#define DC_PHY_QOS_BW2_min_pri(data)                                                 (0x000000FF&((data)<<0))
#define DC_PHY_QOS_BW2_min_pri_src(data)                                             ((0x000000FF&(data))>>0)
#define DC_PHY_QOS_BW2_get_min_pri(data)                                             ((0x000000FF&(data))>>0)


#define DC_PHY_QOS_BW3_0                                                             0x18008F70
#define DC_PHY_QOS_BW3_1                                                             0x18008F74
#define DC_PHY_QOS_BW3_2                                                             0x18008F78
#define DC_PHY_QOS_BW3_3                                                             0x18008F7C
#define DC_PHY_QOS_BW3_4                                                             0x18008F80
#define DC_PHY_QOS_BW3_5                                                             0x18008F84
#define DC_PHY_QOS_BW3_6                                                             0x18008F88
#define DC_PHY_QOS_BW3_7                                                             0x18008F8C
#define DC_PHY_QOS_BW3_8                                                             0x18008F90
#define DC_PHY_QOS_BW3_9                                                             0x18008F94
#define DC_PHY_QOS_BW3_10                                                             0x18008F98
#define DC_PHY_QOS_BW3_11                                                             0x18008F9C
#define DC_PHY_QOS_BW3_12                                                             0x18008FA0
#define DC_PHY_QOS_BW3_13                                                             0x18008FA4
#define DC_PHY_QOS_BW3_14                                                             0x18008FA8
#define DC_PHY_QOS_BW3_15                                                             0x18008FAC
#define DC_PHY_QOS_BW3_0_reg_addr                                                    "0xB8008F70"
#define DC_PHY_QOS_BW3_1_reg_addr                                                    "0xB8008F74"
#define DC_PHY_QOS_BW3_2_reg_addr                                                    "0xB8008F78"
#define DC_PHY_QOS_BW3_3_reg_addr                                                    "0xB8008F7C"
#define DC_PHY_QOS_BW3_4_reg_addr                                                    "0xB8008F80"
#define DC_PHY_QOS_BW3_5_reg_addr                                                    "0xB8008F84"
#define DC_PHY_QOS_BW3_6_reg_addr                                                    "0xB8008F88"
#define DC_PHY_QOS_BW3_7_reg_addr                                                    "0xB8008F8C"
#define DC_PHY_QOS_BW3_8_reg_addr                                                    "0xB8008F90"
#define DC_PHY_QOS_BW3_9_reg_addr                                                    "0xB8008F94"
#define DC_PHY_QOS_BW3_10_reg_addr                                                    "0xB8008F98"
#define DC_PHY_QOS_BW3_11_reg_addr                                                    "0xB8008F9C"
#define DC_PHY_QOS_BW3_12_reg_addr                                                    "0xB8008FA0"
#define DC_PHY_QOS_BW3_13_reg_addr                                                    "0xB8008FA4"
#define DC_PHY_QOS_BW3_14_reg_addr                                                    "0xB8008FA8"
#define DC_PHY_QOS_BW3_15_reg_addr                                                    "0xB8008FAC"
#define DC_PHY_QOS_BW3_0_reg                                                         0xB8008F70
#define DC_PHY_QOS_BW3_1_reg                                                         0xB8008F74
#define DC_PHY_QOS_BW3_2_reg                                                         0xB8008F78
#define DC_PHY_QOS_BW3_3_reg                                                         0xB8008F7C
#define DC_PHY_QOS_BW3_4_reg                                                         0xB8008F80
#define DC_PHY_QOS_BW3_5_reg                                                         0xB8008F84
#define DC_PHY_QOS_BW3_6_reg                                                         0xB8008F88
#define DC_PHY_QOS_BW3_7_reg                                                         0xB8008F8C
#define DC_PHY_QOS_BW3_8_reg                                                         0xB8008F90
#define DC_PHY_QOS_BW3_9_reg                                                         0xB8008F94
#define DC_PHY_QOS_BW3_10_reg                                                         0xB8008F98
#define DC_PHY_QOS_BW3_11_reg                                                         0xB8008F9C
#define DC_PHY_QOS_BW3_12_reg                                                         0xB8008FA0
#define DC_PHY_QOS_BW3_13_reg                                                         0xB8008FA4
#define DC_PHY_QOS_BW3_14_reg                                                         0xB8008FA8
#define DC_PHY_QOS_BW3_15_reg                                                         0xB8008FAC
#define set_DC_PHY_QOS_BW3_0_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW3_0_reg)=data)
#define set_DC_PHY_QOS_BW3_1_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW3_1_reg)=data)
#define set_DC_PHY_QOS_BW3_2_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW3_2_reg)=data)
#define set_DC_PHY_QOS_BW3_3_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW3_3_reg)=data)
#define set_DC_PHY_QOS_BW3_4_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW3_4_reg)=data)
#define set_DC_PHY_QOS_BW3_5_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW3_5_reg)=data)
#define set_DC_PHY_QOS_BW3_6_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW3_6_reg)=data)
#define set_DC_PHY_QOS_BW3_7_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW3_7_reg)=data)
#define set_DC_PHY_QOS_BW3_8_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW3_8_reg)=data)
#define set_DC_PHY_QOS_BW3_9_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW3_9_reg)=data)
#define set_DC_PHY_QOS_BW3_10_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW3_10_reg)=data)
#define set_DC_PHY_QOS_BW3_11_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW3_11_reg)=data)
#define set_DC_PHY_QOS_BW3_12_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW3_12_reg)=data)
#define set_DC_PHY_QOS_BW3_13_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW3_13_reg)=data)
#define set_DC_PHY_QOS_BW3_14_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW3_14_reg)=data)
#define set_DC_PHY_QOS_BW3_15_reg(data)   (*((volatile unsigned int*) DC_PHY_QOS_BW3_15_reg)=data)
#define get_DC_PHY_QOS_BW3_0_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW3_0_reg))
#define get_DC_PHY_QOS_BW3_1_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW3_1_reg))
#define get_DC_PHY_QOS_BW3_2_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW3_2_reg))
#define get_DC_PHY_QOS_BW3_3_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW3_3_reg))
#define get_DC_PHY_QOS_BW3_4_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW3_4_reg))
#define get_DC_PHY_QOS_BW3_5_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW3_5_reg))
#define get_DC_PHY_QOS_BW3_6_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW3_6_reg))
#define get_DC_PHY_QOS_BW3_7_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW3_7_reg))
#define get_DC_PHY_QOS_BW3_8_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW3_8_reg))
#define get_DC_PHY_QOS_BW3_9_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW3_9_reg))
#define get_DC_PHY_QOS_BW3_10_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW3_10_reg))
#define get_DC_PHY_QOS_BW3_11_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW3_11_reg))
#define get_DC_PHY_QOS_BW3_12_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW3_12_reg))
#define get_DC_PHY_QOS_BW3_13_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW3_13_reg))
#define get_DC_PHY_QOS_BW3_14_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW3_14_reg))
#define get_DC_PHY_QOS_BW3_15_reg   (*((volatile unsigned int*) DC_PHY_QOS_BW3_15_reg))
#define DC_PHY_QOS_BW3_0_inst_adr                                                    "0x00DC"
#define DC_PHY_QOS_BW3_1_inst_adr                                                    "0x00DD"
#define DC_PHY_QOS_BW3_2_inst_adr                                                    "0x00DE"
#define DC_PHY_QOS_BW3_3_inst_adr                                                    "0x00DF"
#define DC_PHY_QOS_BW3_4_inst_adr                                                    "0x00E0"
#define DC_PHY_QOS_BW3_5_inst_adr                                                    "0x00E1"
#define DC_PHY_QOS_BW3_6_inst_adr                                                    "0x00E2"
#define DC_PHY_QOS_BW3_7_inst_adr                                                    "0x00E3"
#define DC_PHY_QOS_BW3_8_inst_adr                                                    "0x00E4"
#define DC_PHY_QOS_BW3_9_inst_adr                                                    "0x00E5"
#define DC_PHY_QOS_BW3_10_inst_adr                                                    "0x00E6"
#define DC_PHY_QOS_BW3_11_inst_adr                                                    "0x00E7"
#define DC_PHY_QOS_BW3_12_inst_adr                                                    "0x00E8"
#define DC_PHY_QOS_BW3_13_inst_adr                                                    "0x00E9"
#define DC_PHY_QOS_BW3_14_inst_adr                                                    "0x00EA"
#define DC_PHY_QOS_BW3_15_inst_adr                                                    "0x00EB"
#define DC_PHY_QOS_BW3_0_inst                                                        0x00DC
#define DC_PHY_QOS_BW3_1_inst                                                        0x00DD
#define DC_PHY_QOS_BW3_2_inst                                                        0x00DE
#define DC_PHY_QOS_BW3_3_inst                                                        0x00DF
#define DC_PHY_QOS_BW3_4_inst                                                        0x00E0
#define DC_PHY_QOS_BW3_5_inst                                                        0x00E1
#define DC_PHY_QOS_BW3_6_inst                                                        0x00E2
#define DC_PHY_QOS_BW3_7_inst                                                        0x00E3
#define DC_PHY_QOS_BW3_8_inst                                                        0x00E4
#define DC_PHY_QOS_BW3_9_inst                                                        0x00E5
#define DC_PHY_QOS_BW3_10_inst                                                        0x00E6
#define DC_PHY_QOS_BW3_11_inst                                                        0x00E7
#define DC_PHY_QOS_BW3_12_inst                                                        0x00E8
#define DC_PHY_QOS_BW3_13_inst                                                        0x00E9
#define DC_PHY_QOS_BW3_14_inst                                                        0x00EA
#define DC_PHY_QOS_BW3_15_inst                                                        0x00EB
#define DC_PHY_QOS_BW3_cur_data_max_occ_shift                                        (27)
#define DC_PHY_QOS_BW3_cur_data_max_occ_mask                                         (0x08000000)
#define DC_PHY_QOS_BW3_cur_data_max_occ(data)                                        (0x08000000&((data)<<27))
#define DC_PHY_QOS_BW3_cur_data_max_occ_src(data)                                    ((0x08000000&(data))>>27)
#define DC_PHY_QOS_BW3_get_cur_data_max_occ(data)                                    ((0x08000000&(data))>>27)
#define DC_PHY_QOS_BW3_cur_data_min_occ_shift                                        (26)
#define DC_PHY_QOS_BW3_cur_data_min_occ_mask                                         (0x04000000)
#define DC_PHY_QOS_BW3_cur_data_min_occ(data)                                        (0x04000000&((data)<<26))
#define DC_PHY_QOS_BW3_cur_data_min_occ_src(data)                                    ((0x04000000&(data))>>26)
#define DC_PHY_QOS_BW3_get_cur_data_min_occ(data)                                    ((0x04000000&(data))>>26)
#define DC_PHY_QOS_BW3_pri_max_occ_shift                                             (25)
#define DC_PHY_QOS_BW3_pri_max_occ_mask                                              (0x02000000)
#define DC_PHY_QOS_BW3_pri_max_occ(data)                                             (0x02000000&((data)<<25))
#define DC_PHY_QOS_BW3_pri_max_occ_src(data)                                         ((0x02000000&(data))>>25)
#define DC_PHY_QOS_BW3_get_pri_max_occ(data)                                         ((0x02000000&(data))>>25)
#define DC_PHY_QOS_BW3_pri_min_occ_shift                                             (24)
#define DC_PHY_QOS_BW3_pri_min_occ_mask                                              (0x01000000)
#define DC_PHY_QOS_BW3_pri_min_occ(data)                                             (0x01000000&((data)<<24))
#define DC_PHY_QOS_BW3_pri_min_occ_src(data)                                         ((0x01000000&(data))>>24)
#define DC_PHY_QOS_BW3_get_pri_min_occ(data)                                         ((0x01000000&(data))>>24)
#define DC_PHY_QOS_BW3_cur_pri_shift                                                 (16)
#define DC_PHY_QOS_BW3_cur_pri_mask                                                  (0x00FF0000)
#define DC_PHY_QOS_BW3_cur_pri(data)                                                 (0x00FF0000&((data)<<16))
#define DC_PHY_QOS_BW3_cur_pri_src(data)                                             ((0x00FF0000&(data))>>16)
#define DC_PHY_QOS_BW3_get_cur_pri(data)                                             ((0x00FF0000&(data))>>16)
#define DC_PHY_QOS_BW3_cur_data_shift                                                (0)
#define DC_PHY_QOS_BW3_cur_data_mask                                                 (0x0000FFFF)
#define DC_PHY_QOS_BW3_cur_data(data)                                                (0x0000FFFF&((data)<<0))
#define DC_PHY_QOS_BW3_cur_data_src(data)                                            ((0x0000FFFF&(data))>>0)
#define DC_PHY_QOS_BW3_get_cur_data(data)                                            ((0x0000FFFF&(data))>>0)


#define DC_PHY_DC_SYS2_OT_BLOCK                                                      0x18008FB0
#define DC_PHY_DC_SYS2_OT_BLOCK_reg_addr                                             "0xB8008FB0"
#define DC_PHY_DC_SYS2_OT_BLOCK_reg                                                  0xB8008FB0
#define set_DC_PHY_DC_SYS2_OT_BLOCK_reg(data)   (*((volatile unsigned int*) DC_PHY_DC_SYS2_OT_BLOCK_reg)=data)
#define get_DC_PHY_DC_SYS2_OT_BLOCK_reg   (*((volatile unsigned int*) DC_PHY_DC_SYS2_OT_BLOCK_reg))
#define DC_PHY_DC_SYS2_OT_BLOCK_inst_adr                                             "0x00EC"
#define DC_PHY_DC_SYS2_OT_BLOCK_inst                                                 0x00EC
#define DC_PHY_DC_SYS2_OT_BLOCK_c3_wr_block_occ_shift                                (11)
#define DC_PHY_DC_SYS2_OT_BLOCK_c3_wr_block_occ_mask                                 (0x00000800)
#define DC_PHY_DC_SYS2_OT_BLOCK_c3_wr_block_occ(data)                                (0x00000800&((data)<<11))
#define DC_PHY_DC_SYS2_OT_BLOCK_c3_wr_block_occ_src(data)                            ((0x00000800&(data))>>11)
#define DC_PHY_DC_SYS2_OT_BLOCK_get_c3_wr_block_occ(data)                            ((0x00000800&(data))>>11)
#define DC_PHY_DC_SYS2_OT_BLOCK_c2_wr_block_occ_shift                                (10)
#define DC_PHY_DC_SYS2_OT_BLOCK_c2_wr_block_occ_mask                                 (0x00000400)
#define DC_PHY_DC_SYS2_OT_BLOCK_c2_wr_block_occ(data)                                (0x00000400&((data)<<10))
#define DC_PHY_DC_SYS2_OT_BLOCK_c2_wr_block_occ_src(data)                            ((0x00000400&(data))>>10)
#define DC_PHY_DC_SYS2_OT_BLOCK_get_c2_wr_block_occ(data)                            ((0x00000400&(data))>>10)
#define DC_PHY_DC_SYS2_OT_BLOCK_c1_wr_block_occ_shift                                (9)
#define DC_PHY_DC_SYS2_OT_BLOCK_c1_wr_block_occ_mask                                 (0x00000200)
#define DC_PHY_DC_SYS2_OT_BLOCK_c1_wr_block_occ(data)                                (0x00000200&((data)<<9))
#define DC_PHY_DC_SYS2_OT_BLOCK_c1_wr_block_occ_src(data)                            ((0x00000200&(data))>>9)
#define DC_PHY_DC_SYS2_OT_BLOCK_get_c1_wr_block_occ(data)                            ((0x00000200&(data))>>9)
#define DC_PHY_DC_SYS2_OT_BLOCK_c0_wr_block_occ_shift                                (8)
#define DC_PHY_DC_SYS2_OT_BLOCK_c0_wr_block_occ_mask                                 (0x00000100)
#define DC_PHY_DC_SYS2_OT_BLOCK_c0_wr_block_occ(data)                                (0x00000100&((data)<<8))
#define DC_PHY_DC_SYS2_OT_BLOCK_c0_wr_block_occ_src(data)                            ((0x00000100&(data))>>8)
#define DC_PHY_DC_SYS2_OT_BLOCK_get_c0_wr_block_occ(data)                            ((0x00000100&(data))>>8)
#define DC_PHY_DC_SYS2_OT_BLOCK_c7_rd_block_occ_shift                                (7)
#define DC_PHY_DC_SYS2_OT_BLOCK_c7_rd_block_occ_mask                                 (0x00000080)
#define DC_PHY_DC_SYS2_OT_BLOCK_c7_rd_block_occ(data)                                (0x00000080&((data)<<7))
#define DC_PHY_DC_SYS2_OT_BLOCK_c7_rd_block_occ_src(data)                            ((0x00000080&(data))>>7)
#define DC_PHY_DC_SYS2_OT_BLOCK_get_c7_rd_block_occ(data)                            ((0x00000080&(data))>>7)
#define DC_PHY_DC_SYS2_OT_BLOCK_c6_rd_block_occ_shift                                (6)
#define DC_PHY_DC_SYS2_OT_BLOCK_c6_rd_block_occ_mask                                 (0x00000040)
#define DC_PHY_DC_SYS2_OT_BLOCK_c6_rd_block_occ(data)                                (0x00000040&((data)<<6))
#define DC_PHY_DC_SYS2_OT_BLOCK_c6_rd_block_occ_src(data)                            ((0x00000040&(data))>>6)
#define DC_PHY_DC_SYS2_OT_BLOCK_get_c6_rd_block_occ(data)                            ((0x00000040&(data))>>6)
#define DC_PHY_DC_SYS2_OT_BLOCK_c5_rd_block_occ_shift                                (5)
#define DC_PHY_DC_SYS2_OT_BLOCK_c5_rd_block_occ_mask                                 (0x00000020)
#define DC_PHY_DC_SYS2_OT_BLOCK_c5_rd_block_occ(data)                                (0x00000020&((data)<<5))
#define DC_PHY_DC_SYS2_OT_BLOCK_c5_rd_block_occ_src(data)                            ((0x00000020&(data))>>5)
#define DC_PHY_DC_SYS2_OT_BLOCK_get_c5_rd_block_occ(data)                            ((0x00000020&(data))>>5)
#define DC_PHY_DC_SYS2_OT_BLOCK_c4_rd_block_occ_shift                                (4)
#define DC_PHY_DC_SYS2_OT_BLOCK_c4_rd_block_occ_mask                                 (0x00000010)
#define DC_PHY_DC_SYS2_OT_BLOCK_c4_rd_block_occ(data)                                (0x00000010&((data)<<4))
#define DC_PHY_DC_SYS2_OT_BLOCK_c4_rd_block_occ_src(data)                            ((0x00000010&(data))>>4)
#define DC_PHY_DC_SYS2_OT_BLOCK_get_c4_rd_block_occ(data)                            ((0x00000010&(data))>>4)
#define DC_PHY_DC_SYS2_OT_BLOCK_c3_rd_block_occ_shift                                (3)
#define DC_PHY_DC_SYS2_OT_BLOCK_c3_rd_block_occ_mask                                 (0x00000008)
#define DC_PHY_DC_SYS2_OT_BLOCK_c3_rd_block_occ(data)                                (0x00000008&((data)<<3))
#define DC_PHY_DC_SYS2_OT_BLOCK_c3_rd_block_occ_src(data)                            ((0x00000008&(data))>>3)
#define DC_PHY_DC_SYS2_OT_BLOCK_get_c3_rd_block_occ(data)                            ((0x00000008&(data))>>3)
#define DC_PHY_DC_SYS2_OT_BLOCK_c2_rd_block_occ_shift                                (2)
#define DC_PHY_DC_SYS2_OT_BLOCK_c2_rd_block_occ_mask                                 (0x00000004)
#define DC_PHY_DC_SYS2_OT_BLOCK_c2_rd_block_occ(data)                                (0x00000004&((data)<<2))
#define DC_PHY_DC_SYS2_OT_BLOCK_c2_rd_block_occ_src(data)                            ((0x00000004&(data))>>2)
#define DC_PHY_DC_SYS2_OT_BLOCK_get_c2_rd_block_occ(data)                            ((0x00000004&(data))>>2)
#define DC_PHY_DC_SYS2_OT_BLOCK_c1_rd_block_occ_shift                                (1)
#define DC_PHY_DC_SYS2_OT_BLOCK_c1_rd_block_occ_mask                                 (0x00000002)
#define DC_PHY_DC_SYS2_OT_BLOCK_c1_rd_block_occ(data)                                (0x00000002&((data)<<1))
#define DC_PHY_DC_SYS2_OT_BLOCK_c1_rd_block_occ_src(data)                            ((0x00000002&(data))>>1)
#define DC_PHY_DC_SYS2_OT_BLOCK_get_c1_rd_block_occ(data)                            ((0x00000002&(data))>>1)
#define DC_PHY_DC_SYS2_OT_BLOCK_c0_rd_block_occ_shift                                (0)
#define DC_PHY_DC_SYS2_OT_BLOCK_c0_rd_block_occ_mask                                 (0x00000001)
#define DC_PHY_DC_SYS2_OT_BLOCK_c0_rd_block_occ(data)                                (0x00000001&((data)<<0))
#define DC_PHY_DC_SYS2_OT_BLOCK_c0_rd_block_occ_src(data)                            ((0x00000001&(data))>>0)
#define DC_PHY_DC_SYS2_OT_BLOCK_get_c0_rd_block_occ(data)                            ((0x00000001&(data))>>0)


#define DC_PHY_EFF_MEAS_CTRL                                                         0x18008D80
#define DC_PHY_EFF_MEAS_CTRL_reg_addr                                                "0xB8008D80"
#define DC_PHY_EFF_MEAS_CTRL_reg                                                     0xB8008D80
#define set_DC_PHY_EFF_MEAS_CTRL_reg(data)   (*((volatile unsigned int*) DC_PHY_EFF_MEAS_CTRL_reg)=data)
#define get_DC_PHY_EFF_MEAS_CTRL_reg   (*((volatile unsigned int*) DC_PHY_EFF_MEAS_CTRL_reg))
#define DC_PHY_EFF_MEAS_CTRL_inst_adr                                                "0x0060"
#define DC_PHY_EFF_MEAS_CTRL_inst                                                    0x0060
#define DC_PHY_EFF_MEAS_CTRL_meas_period_shift                                       (8)
#define DC_PHY_EFF_MEAS_CTRL_meas_period_mask                                        (0x003FFF00)
#define DC_PHY_EFF_MEAS_CTRL_meas_period(data)                                       (0x003FFF00&((data)<<8))
#define DC_PHY_EFF_MEAS_CTRL_meas_period_src(data)                                   ((0x003FFF00&(data))>>8)
#define DC_PHY_EFF_MEAS_CTRL_get_meas_period(data)                                   ((0x003FFF00&(data))>>8)
#define DC_PHY_EFF_MEAS_CTRL_eff_meas_en_shift                                       (0)
#define DC_PHY_EFF_MEAS_CTRL_eff_meas_en_mask                                        (0x00000001)
#define DC_PHY_EFF_MEAS_CTRL_eff_meas_en(data)                                       (0x00000001&((data)<<0))
#define DC_PHY_EFF_MEAS_CTRL_eff_meas_en_src(data)                                   ((0x00000001&(data))>>0)
#define DC_PHY_EFF_MEAS_CTRL_get_eff_meas_en(data)                                   ((0x00000001&(data))>>0)


#define DC_PHY_READ_CMD                                                              0x18008D84
#define DC_PHY_READ_CMD_reg_addr                                                     "0xB8008D84"
#define DC_PHY_READ_CMD_reg                                                          0xB8008D84
#define set_DC_PHY_READ_CMD_reg(data)   (*((volatile unsigned int*) DC_PHY_READ_CMD_reg)=data)
#define get_DC_PHY_READ_CMD_reg   (*((volatile unsigned int*) DC_PHY_READ_CMD_reg))
#define DC_PHY_READ_CMD_inst_adr                                                     "0x0061"
#define DC_PHY_READ_CMD_inst                                                         0x0061
#define DC_PHY_READ_CMD_rd_cnt_shift                                                 (0)
#define DC_PHY_READ_CMD_rd_cnt_mask                                                  (0x1FFFFFFF)
#define DC_PHY_READ_CMD_rd_cnt(data)                                                 (0x1FFFFFFF&((data)<<0))
#define DC_PHY_READ_CMD_rd_cnt_src(data)                                             ((0x1FFFFFFF&(data))>>0)
#define DC_PHY_READ_CMD_get_rd_cnt(data)                                             ((0x1FFFFFFF&(data))>>0)


#define DC_PHY_WRITE_CMD                                                             0x18008D88
#define DC_PHY_WRITE_CMD_reg_addr                                                    "0xB8008D88"
#define DC_PHY_WRITE_CMD_reg                                                         0xB8008D88
#define set_DC_PHY_WRITE_CMD_reg(data)   (*((volatile unsigned int*) DC_PHY_WRITE_CMD_reg)=data)
#define get_DC_PHY_WRITE_CMD_reg   (*((volatile unsigned int*) DC_PHY_WRITE_CMD_reg))
#define DC_PHY_WRITE_CMD_inst_adr                                                    "0x0062"
#define DC_PHY_WRITE_CMD_inst                                                        0x0062
#define DC_PHY_WRITE_CMD_wr_cnt_shift                                                (0)
#define DC_PHY_WRITE_CMD_wr_cnt_mask                                                 (0x1FFFFFFF)
#define DC_PHY_WRITE_CMD_wr_cnt(data)                                                (0x1FFFFFFF&((data)<<0))
#define DC_PHY_WRITE_CMD_wr_cnt_src(data)                                            ((0x1FFFFFFF&(data))>>0)
#define DC_PHY_WRITE_CMD_get_wr_cnt(data)                                            ((0x1FFFFFFF&(data))>>0)


#define DC_PHY_READ_CHOP_CMD                                                         0x18008D8C
#define DC_PHY_READ_CHOP_CMD_reg_addr                                                "0xB8008D8C"
#define DC_PHY_READ_CHOP_CMD_reg                                                     0xB8008D8C
#define set_DC_PHY_READ_CHOP_CMD_reg(data)   (*((volatile unsigned int*) DC_PHY_READ_CHOP_CMD_reg)=data)
#define get_DC_PHY_READ_CHOP_CMD_reg   (*((volatile unsigned int*) DC_PHY_READ_CHOP_CMD_reg))
#define DC_PHY_READ_CHOP_CMD_inst_adr                                                "0x0063"
#define DC_PHY_READ_CHOP_CMD_inst                                                    0x0063
#define DC_PHY_READ_CHOP_CMD_rd_chop_cnt_shift                                       (0)
#define DC_PHY_READ_CHOP_CMD_rd_chop_cnt_mask                                        (0x1FFFFFFF)
#define DC_PHY_READ_CHOP_CMD_rd_chop_cnt(data)                                       (0x1FFFFFFF&((data)<<0))
#define DC_PHY_READ_CHOP_CMD_rd_chop_cnt_src(data)                                   ((0x1FFFFFFF&(data))>>0)
#define DC_PHY_READ_CHOP_CMD_get_rd_chop_cnt(data)                                   ((0x1FFFFFFF&(data))>>0)


#define DC_PHY_WRITE_CHOP_CMD                                                        0x18008D90
#define DC_PHY_WRITE_CHOP_CMD_reg_addr                                               "0xB8008D90"
#define DC_PHY_WRITE_CHOP_CMD_reg                                                    0xB8008D90
#define set_DC_PHY_WRITE_CHOP_CMD_reg(data)   (*((volatile unsigned int*) DC_PHY_WRITE_CHOP_CMD_reg)=data)
#define get_DC_PHY_WRITE_CHOP_CMD_reg   (*((volatile unsigned int*) DC_PHY_WRITE_CHOP_CMD_reg))
#define DC_PHY_WRITE_CHOP_CMD_inst_adr                                               "0x0064"
#define DC_PHY_WRITE_CHOP_CMD_inst                                                   0x0064
#define DC_PHY_WRITE_CHOP_CMD_wr_chop_cnt_shift                                      (0)
#define DC_PHY_WRITE_CHOP_CMD_wr_chop_cnt_mask                                       (0x1FFFFFFF)
#define DC_PHY_WRITE_CHOP_CMD_wr_chop_cnt(data)                                      (0x1FFFFFFF&((data)<<0))
#define DC_PHY_WRITE_CHOP_CMD_wr_chop_cnt_src(data)                                  ((0x1FFFFFFF&(data))>>0)
#define DC_PHY_WRITE_CHOP_CMD_get_wr_chop_cnt(data)                                  ((0x1FFFFFFF&(data))>>0)


#define DC_PHY_ACT_BANK_0                                                            0x18008D94
#define DC_PHY_ACT_BANK_0_reg_addr                                                   "0xB8008D94"
#define DC_PHY_ACT_BANK_0_reg                                                        0xB8008D94
#define set_DC_PHY_ACT_BANK_0_reg(data)   (*((volatile unsigned int*) DC_PHY_ACT_BANK_0_reg)=data)
#define get_DC_PHY_ACT_BANK_0_reg   (*((volatile unsigned int*) DC_PHY_ACT_BANK_0_reg))
#define DC_PHY_ACT_BANK_0_inst_adr                                                   "0x0065"
#define DC_PHY_ACT_BANK_0_inst                                                       0x0065
#define DC_PHY_ACT_BANK_0_active_cnt_bank0_shift                                     (0)
#define DC_PHY_ACT_BANK_0_active_cnt_bank0_mask                                      (0x1FFFFFFF)
#define DC_PHY_ACT_BANK_0_active_cnt_bank0(data)                                     (0x1FFFFFFF&((data)<<0))
#define DC_PHY_ACT_BANK_0_active_cnt_bank0_src(data)                                 ((0x1FFFFFFF&(data))>>0)
#define DC_PHY_ACT_BANK_0_get_active_cnt_bank0(data)                                 ((0x1FFFFFFF&(data))>>0)


#define DC_PHY_PRECHG_BANK_0                                                         0x18008D98
#define DC_PHY_PRECHG_BANK_0_reg_addr                                                "0xB8008D98"
#define DC_PHY_PRECHG_BANK_0_reg                                                     0xB8008D98
#define set_DC_PHY_PRECHG_BANK_0_reg(data)   (*((volatile unsigned int*) DC_PHY_PRECHG_BANK_0_reg)=data)
#define get_DC_PHY_PRECHG_BANK_0_reg   (*((volatile unsigned int*) DC_PHY_PRECHG_BANK_0_reg))
#define DC_PHY_PRECHG_BANK_0_inst_adr                                                "0x0066"
#define DC_PHY_PRECHG_BANK_0_inst                                                    0x0066
#define DC_PHY_PRECHG_BANK_0_precharge_cnt_bank0_shift                               (0)
#define DC_PHY_PRECHG_BANK_0_precharge_cnt_bank0_mask                                (0x1FFFFFFF)
#define DC_PHY_PRECHG_BANK_0_precharge_cnt_bank0(data)                               (0x1FFFFFFF&((data)<<0))
#define DC_PHY_PRECHG_BANK_0_precharge_cnt_bank0_src(data)                           ((0x1FFFFFFF&(data))>>0)
#define DC_PHY_PRECHG_BANK_0_get_precharge_cnt_bank0(data)                           ((0x1FFFFFFF&(data))>>0)


#define DC_PHY_ACT_BANK_1                                                            0x18008D9C
#define DC_PHY_ACT_BANK_1_reg_addr                                                   "0xB8008D9C"
#define DC_PHY_ACT_BANK_1_reg                                                        0xB8008D9C
#define set_DC_PHY_ACT_BANK_1_reg(data)   (*((volatile unsigned int*) DC_PHY_ACT_BANK_1_reg)=data)
#define get_DC_PHY_ACT_BANK_1_reg   (*((volatile unsigned int*) DC_PHY_ACT_BANK_1_reg))
#define DC_PHY_ACT_BANK_1_inst_adr                                                   "0x0067"
#define DC_PHY_ACT_BANK_1_inst                                                       0x0067
#define DC_PHY_ACT_BANK_1_active_cnt_bank1_shift                                     (0)
#define DC_PHY_ACT_BANK_1_active_cnt_bank1_mask                                      (0x1FFFFFFF)
#define DC_PHY_ACT_BANK_1_active_cnt_bank1(data)                                     (0x1FFFFFFF&((data)<<0))
#define DC_PHY_ACT_BANK_1_active_cnt_bank1_src(data)                                 ((0x1FFFFFFF&(data))>>0)
#define DC_PHY_ACT_BANK_1_get_active_cnt_bank1(data)                                 ((0x1FFFFFFF&(data))>>0)


#define DC_PHY_PRECHG_BANK_1                                                         0x18008DA0
#define DC_PHY_PRECHG_BANK_1_reg_addr                                                "0xB8008DA0"
#define DC_PHY_PRECHG_BANK_1_reg                                                     0xB8008DA0
#define set_DC_PHY_PRECHG_BANK_1_reg(data)   (*((volatile unsigned int*) DC_PHY_PRECHG_BANK_1_reg)=data)
#define get_DC_PHY_PRECHG_BANK_1_reg   (*((volatile unsigned int*) DC_PHY_PRECHG_BANK_1_reg))
#define DC_PHY_PRECHG_BANK_1_inst_adr                                                "0x0068"
#define DC_PHY_PRECHG_BANK_1_inst                                                    0x0068
#define DC_PHY_PRECHG_BANK_1_precharge_cnt_bank1_shift                               (0)
#define DC_PHY_PRECHG_BANK_1_precharge_cnt_bank1_mask                                (0x1FFFFFFF)
#define DC_PHY_PRECHG_BANK_1_precharge_cnt_bank1(data)                               (0x1FFFFFFF&((data)<<0))
#define DC_PHY_PRECHG_BANK_1_precharge_cnt_bank1_src(data)                           ((0x1FFFFFFF&(data))>>0)
#define DC_PHY_PRECHG_BANK_1_get_precharge_cnt_bank1(data)                           ((0x1FFFFFFF&(data))>>0)


#define DC_PHY_ACT_BANK_2                                                            0x18008DA4
#define DC_PHY_ACT_BANK_2_reg_addr                                                   "0xB8008DA4"
#define DC_PHY_ACT_BANK_2_reg                                                        0xB8008DA4
#define set_DC_PHY_ACT_BANK_2_reg(data)   (*((volatile unsigned int*) DC_PHY_ACT_BANK_2_reg)=data)
#define get_DC_PHY_ACT_BANK_2_reg   (*((volatile unsigned int*) DC_PHY_ACT_BANK_2_reg))
#define DC_PHY_ACT_BANK_2_inst_adr                                                   "0x0069"
#define DC_PHY_ACT_BANK_2_inst                                                       0x0069
#define DC_PHY_ACT_BANK_2_active_cnt_bank2_shift                                     (0)
#define DC_PHY_ACT_BANK_2_active_cnt_bank2_mask                                      (0x1FFFFFFF)
#define DC_PHY_ACT_BANK_2_active_cnt_bank2(data)                                     (0x1FFFFFFF&((data)<<0))
#define DC_PHY_ACT_BANK_2_active_cnt_bank2_src(data)                                 ((0x1FFFFFFF&(data))>>0)
#define DC_PHY_ACT_BANK_2_get_active_cnt_bank2(data)                                 ((0x1FFFFFFF&(data))>>0)


#define DC_PHY_PRECHG_BANK_2                                                         0x18008DA8
#define DC_PHY_PRECHG_BANK_2_reg_addr                                                "0xB8008DA8"
#define DC_PHY_PRECHG_BANK_2_reg                                                     0xB8008DA8
#define set_DC_PHY_PRECHG_BANK_2_reg(data)   (*((volatile unsigned int*) DC_PHY_PRECHG_BANK_2_reg)=data)
#define get_DC_PHY_PRECHG_BANK_2_reg   (*((volatile unsigned int*) DC_PHY_PRECHG_BANK_2_reg))
#define DC_PHY_PRECHG_BANK_2_inst_adr                                                "0x006A"
#define DC_PHY_PRECHG_BANK_2_inst                                                    0x006A
#define DC_PHY_PRECHG_BANK_2_precharge_cnt_bank2_shift                               (0)
#define DC_PHY_PRECHG_BANK_2_precharge_cnt_bank2_mask                                (0x1FFFFFFF)
#define DC_PHY_PRECHG_BANK_2_precharge_cnt_bank2(data)                               (0x1FFFFFFF&((data)<<0))
#define DC_PHY_PRECHG_BANK_2_precharge_cnt_bank2_src(data)                           ((0x1FFFFFFF&(data))>>0)
#define DC_PHY_PRECHG_BANK_2_get_precharge_cnt_bank2(data)                           ((0x1FFFFFFF&(data))>>0)


#define DC_PHY_ACT_BANK_3                                                            0x18008DAC
#define DC_PHY_ACT_BANK_3_reg_addr                                                   "0xB8008DAC"
#define DC_PHY_ACT_BANK_3_reg                                                        0xB8008DAC
#define set_DC_PHY_ACT_BANK_3_reg(data)   (*((volatile unsigned int*) DC_PHY_ACT_BANK_3_reg)=data)
#define get_DC_PHY_ACT_BANK_3_reg   (*((volatile unsigned int*) DC_PHY_ACT_BANK_3_reg))
#define DC_PHY_ACT_BANK_3_inst_adr                                                   "0x006B"
#define DC_PHY_ACT_BANK_3_inst                                                       0x006B
#define DC_PHY_ACT_BANK_3_active_cnt_bank3_shift                                     (0)
#define DC_PHY_ACT_BANK_3_active_cnt_bank3_mask                                      (0x1FFFFFFF)
#define DC_PHY_ACT_BANK_3_active_cnt_bank3(data)                                     (0x1FFFFFFF&((data)<<0))
#define DC_PHY_ACT_BANK_3_active_cnt_bank3_src(data)                                 ((0x1FFFFFFF&(data))>>0)
#define DC_PHY_ACT_BANK_3_get_active_cnt_bank3(data)                                 ((0x1FFFFFFF&(data))>>0)


#define DC_PHY_PRECHG_BANK_3                                                         0x18008DB0
#define DC_PHY_PRECHG_BANK_3_reg_addr                                                "0xB8008DB0"
#define DC_PHY_PRECHG_BANK_3_reg                                                     0xB8008DB0
#define set_DC_PHY_PRECHG_BANK_3_reg(data)   (*((volatile unsigned int*) DC_PHY_PRECHG_BANK_3_reg)=data)
#define get_DC_PHY_PRECHG_BANK_3_reg   (*((volatile unsigned int*) DC_PHY_PRECHG_BANK_3_reg))
#define DC_PHY_PRECHG_BANK_3_inst_adr                                                "0x006C"
#define DC_PHY_PRECHG_BANK_3_inst                                                    0x006C
#define DC_PHY_PRECHG_BANK_3_precharge_cnt_bank3_shift                               (0)
#define DC_PHY_PRECHG_BANK_3_precharge_cnt_bank3_mask                                (0x1FFFFFFF)
#define DC_PHY_PRECHG_BANK_3_precharge_cnt_bank3(data)                               (0x1FFFFFFF&((data)<<0))
#define DC_PHY_PRECHG_BANK_3_precharge_cnt_bank3_src(data)                           ((0x1FFFFFFF&(data))>>0)
#define DC_PHY_PRECHG_BANK_3_get_precharge_cnt_bank3(data)                           ((0x1FFFFFFF&(data))>>0)


#define DC_PHY_ACT_BANK_4                                                            0x18008DB4
#define DC_PHY_ACT_BANK_4_reg_addr                                                   "0xB8008DB4"
#define DC_PHY_ACT_BANK_4_reg                                                        0xB8008DB4
#define set_DC_PHY_ACT_BANK_4_reg(data)   (*((volatile unsigned int*) DC_PHY_ACT_BANK_4_reg)=data)
#define get_DC_PHY_ACT_BANK_4_reg   (*((volatile unsigned int*) DC_PHY_ACT_BANK_4_reg))
#define DC_PHY_ACT_BANK_4_inst_adr                                                   "0x006D"
#define DC_PHY_ACT_BANK_4_inst                                                       0x006D
#define DC_PHY_ACT_BANK_4_active_cnt_bank4_shift                                     (0)
#define DC_PHY_ACT_BANK_4_active_cnt_bank4_mask                                      (0x1FFFFFFF)
#define DC_PHY_ACT_BANK_4_active_cnt_bank4(data)                                     (0x1FFFFFFF&((data)<<0))
#define DC_PHY_ACT_BANK_4_active_cnt_bank4_src(data)                                 ((0x1FFFFFFF&(data))>>0)
#define DC_PHY_ACT_BANK_4_get_active_cnt_bank4(data)                                 ((0x1FFFFFFF&(data))>>0)


#define DC_PHY_PRECHG_BANK_4                                                         0x18008DB8
#define DC_PHY_PRECHG_BANK_4_reg_addr                                                "0xB8008DB8"
#define DC_PHY_PRECHG_BANK_4_reg                                                     0xB8008DB8
#define set_DC_PHY_PRECHG_BANK_4_reg(data)   (*((volatile unsigned int*) DC_PHY_PRECHG_BANK_4_reg)=data)
#define get_DC_PHY_PRECHG_BANK_4_reg   (*((volatile unsigned int*) DC_PHY_PRECHG_BANK_4_reg))
#define DC_PHY_PRECHG_BANK_4_inst_adr                                                "0x006E"
#define DC_PHY_PRECHG_BANK_4_inst                                                    0x006E
#define DC_PHY_PRECHG_BANK_4_precharge_cnt_bank4_shift                               (0)
#define DC_PHY_PRECHG_BANK_4_precharge_cnt_bank4_mask                                (0x1FFFFFFF)
#define DC_PHY_PRECHG_BANK_4_precharge_cnt_bank4(data)                               (0x1FFFFFFF&((data)<<0))
#define DC_PHY_PRECHG_BANK_4_precharge_cnt_bank4_src(data)                           ((0x1FFFFFFF&(data))>>0)
#define DC_PHY_PRECHG_BANK_4_get_precharge_cnt_bank4(data)                           ((0x1FFFFFFF&(data))>>0)


#define DC_PHY_ACT_BANK_5                                                            0x18008DBC
#define DC_PHY_ACT_BANK_5_reg_addr                                                   "0xB8008DBC"
#define DC_PHY_ACT_BANK_5_reg                                                        0xB8008DBC
#define set_DC_PHY_ACT_BANK_5_reg(data)   (*((volatile unsigned int*) DC_PHY_ACT_BANK_5_reg)=data)
#define get_DC_PHY_ACT_BANK_5_reg   (*((volatile unsigned int*) DC_PHY_ACT_BANK_5_reg))
#define DC_PHY_ACT_BANK_5_inst_adr                                                   "0x006F"
#define DC_PHY_ACT_BANK_5_inst                                                       0x006F
#define DC_PHY_ACT_BANK_5_active_cnt_bank5_shift                                     (0)
#define DC_PHY_ACT_BANK_5_active_cnt_bank5_mask                                      (0x1FFFFFFF)
#define DC_PHY_ACT_BANK_5_active_cnt_bank5(data)                                     (0x1FFFFFFF&((data)<<0))
#define DC_PHY_ACT_BANK_5_active_cnt_bank5_src(data)                                 ((0x1FFFFFFF&(data))>>0)
#define DC_PHY_ACT_BANK_5_get_active_cnt_bank5(data)                                 ((0x1FFFFFFF&(data))>>0)


#define DC_PHY_PRECHG_BANK_5                                                         0x18008DC0
#define DC_PHY_PRECHG_BANK_5_reg_addr                                                "0xB8008DC0"
#define DC_PHY_PRECHG_BANK_5_reg                                                     0xB8008DC0
#define set_DC_PHY_PRECHG_BANK_5_reg(data)   (*((volatile unsigned int*) DC_PHY_PRECHG_BANK_5_reg)=data)
#define get_DC_PHY_PRECHG_BANK_5_reg   (*((volatile unsigned int*) DC_PHY_PRECHG_BANK_5_reg))
#define DC_PHY_PRECHG_BANK_5_inst_adr                                                "0x0070"
#define DC_PHY_PRECHG_BANK_5_inst                                                    0x0070
#define DC_PHY_PRECHG_BANK_5_precharge_cnt_bank5_shift                               (0)
#define DC_PHY_PRECHG_BANK_5_precharge_cnt_bank5_mask                                (0x1FFFFFFF)
#define DC_PHY_PRECHG_BANK_5_precharge_cnt_bank5(data)                               (0x1FFFFFFF&((data)<<0))
#define DC_PHY_PRECHG_BANK_5_precharge_cnt_bank5_src(data)                           ((0x1FFFFFFF&(data))>>0)
#define DC_PHY_PRECHG_BANK_5_get_precharge_cnt_bank5(data)                           ((0x1FFFFFFF&(data))>>0)


#define DC_PHY_ACT_BANK_6                                                            0x18008DC4
#define DC_PHY_ACT_BANK_6_reg_addr                                                   "0xB8008DC4"
#define DC_PHY_ACT_BANK_6_reg                                                        0xB8008DC4
#define set_DC_PHY_ACT_BANK_6_reg(data)   (*((volatile unsigned int*) DC_PHY_ACT_BANK_6_reg)=data)
#define get_DC_PHY_ACT_BANK_6_reg   (*((volatile unsigned int*) DC_PHY_ACT_BANK_6_reg))
#define DC_PHY_ACT_BANK_6_inst_adr                                                   "0x0071"
#define DC_PHY_ACT_BANK_6_inst                                                       0x0071
#define DC_PHY_ACT_BANK_6_active_cnt_bank6_shift                                     (0)
#define DC_PHY_ACT_BANK_6_active_cnt_bank6_mask                                      (0x1FFFFFFF)
#define DC_PHY_ACT_BANK_6_active_cnt_bank6(data)                                     (0x1FFFFFFF&((data)<<0))
#define DC_PHY_ACT_BANK_6_active_cnt_bank6_src(data)                                 ((0x1FFFFFFF&(data))>>0)
#define DC_PHY_ACT_BANK_6_get_active_cnt_bank6(data)                                 ((0x1FFFFFFF&(data))>>0)


#define DC_PHY_PRECHG_BANK_6                                                         0x18008DC8
#define DC_PHY_PRECHG_BANK_6_reg_addr                                                "0xB8008DC8"
#define DC_PHY_PRECHG_BANK_6_reg                                                     0xB8008DC8
#define set_DC_PHY_PRECHG_BANK_6_reg(data)   (*((volatile unsigned int*) DC_PHY_PRECHG_BANK_6_reg)=data)
#define get_DC_PHY_PRECHG_BANK_6_reg   (*((volatile unsigned int*) DC_PHY_PRECHG_BANK_6_reg))
#define DC_PHY_PRECHG_BANK_6_inst_adr                                                "0x0072"
#define DC_PHY_PRECHG_BANK_6_inst                                                    0x0072
#define DC_PHY_PRECHG_BANK_6_precharge_cnt_bank6_shift                               (0)
#define DC_PHY_PRECHG_BANK_6_precharge_cnt_bank6_mask                                (0x1FFFFFFF)
#define DC_PHY_PRECHG_BANK_6_precharge_cnt_bank6(data)                               (0x1FFFFFFF&((data)<<0))
#define DC_PHY_PRECHG_BANK_6_precharge_cnt_bank6_src(data)                           ((0x1FFFFFFF&(data))>>0)
#define DC_PHY_PRECHG_BANK_6_get_precharge_cnt_bank6(data)                           ((0x1FFFFFFF&(data))>>0)


#define DC_PHY_ACT_BANK_7                                                            0x18008DCC
#define DC_PHY_ACT_BANK_7_reg_addr                                                   "0xB8008DCC"
#define DC_PHY_ACT_BANK_7_reg                                                        0xB8008DCC
#define set_DC_PHY_ACT_BANK_7_reg(data)   (*((volatile unsigned int*) DC_PHY_ACT_BANK_7_reg)=data)
#define get_DC_PHY_ACT_BANK_7_reg   (*((volatile unsigned int*) DC_PHY_ACT_BANK_7_reg))
#define DC_PHY_ACT_BANK_7_inst_adr                                                   "0x0073"
#define DC_PHY_ACT_BANK_7_inst                                                       0x0073
#define DC_PHY_ACT_BANK_7_active_cnt_bank7_shift                                     (0)
#define DC_PHY_ACT_BANK_7_active_cnt_bank7_mask                                      (0x1FFFFFFF)
#define DC_PHY_ACT_BANK_7_active_cnt_bank7(data)                                     (0x1FFFFFFF&((data)<<0))
#define DC_PHY_ACT_BANK_7_active_cnt_bank7_src(data)                                 ((0x1FFFFFFF&(data))>>0)
#define DC_PHY_ACT_BANK_7_get_active_cnt_bank7(data)                                 ((0x1FFFFFFF&(data))>>0)


#define DC_PHY_PRECHG_BANK_7                                                         0x18008DD0
#define DC_PHY_PRECHG_BANK_7_reg_addr                                                "0xB8008DD0"
#define DC_PHY_PRECHG_BANK_7_reg                                                     0xB8008DD0
#define set_DC_PHY_PRECHG_BANK_7_reg(data)   (*((volatile unsigned int*) DC_PHY_PRECHG_BANK_7_reg)=data)
#define get_DC_PHY_PRECHG_BANK_7_reg   (*((volatile unsigned int*) DC_PHY_PRECHG_BANK_7_reg))
#define DC_PHY_PRECHG_BANK_7_inst_adr                                                "0x0074"
#define DC_PHY_PRECHG_BANK_7_inst                                                    0x0074
#define DC_PHY_PRECHG_BANK_7_precharge_cnt_bank7_shift                               (0)
#define DC_PHY_PRECHG_BANK_7_precharge_cnt_bank7_mask                                (0x1FFFFFFF)
#define DC_PHY_PRECHG_BANK_7_precharge_cnt_bank7(data)                               (0x1FFFFFFF&((data)<<0))
#define DC_PHY_PRECHG_BANK_7_precharge_cnt_bank7_src(data)                           ((0x1FFFFFFF&(data))>>0)
#define DC_PHY_PRECHG_BANK_7_get_precharge_cnt_bank7(data)                           ((0x1FFFFFFF&(data))>>0)


#define DC_PHY_WRITE_TO_READ                                                         0x18008DD4
#define DC_PHY_WRITE_TO_READ_reg_addr                                                "0xB8008DD4"
#define DC_PHY_WRITE_TO_READ_reg                                                     0xB8008DD4
#define set_DC_PHY_WRITE_TO_READ_reg(data)   (*((volatile unsigned int*) DC_PHY_WRITE_TO_READ_reg)=data)
#define get_DC_PHY_WRITE_TO_READ_reg   (*((volatile unsigned int*) DC_PHY_WRITE_TO_READ_reg))
#define DC_PHY_WRITE_TO_READ_inst_adr                                                "0x0075"
#define DC_PHY_WRITE_TO_READ_inst                                                    0x0075
#define DC_PHY_WRITE_TO_READ_w2r_cnt_shift                                           (0)
#define DC_PHY_WRITE_TO_READ_w2r_cnt_mask                                            (0x07FFFFFF)
#define DC_PHY_WRITE_TO_READ_w2r_cnt(data)                                           (0x07FFFFFF&((data)<<0))
#define DC_PHY_WRITE_TO_READ_w2r_cnt_src(data)                                       ((0x07FFFFFF&(data))>>0)
#define DC_PHY_WRITE_TO_READ_get_w2r_cnt(data)                                       ((0x07FFFFFF&(data))>>0)


#define DC_PHY_READ_TO_WRITE                                                         0x18008DD8
#define DC_PHY_READ_TO_WRITE_reg_addr                                                "0xB8008DD8"
#define DC_PHY_READ_TO_WRITE_reg                                                     0xB8008DD8
#define set_DC_PHY_READ_TO_WRITE_reg(data)   (*((volatile unsigned int*) DC_PHY_READ_TO_WRITE_reg)=data)
#define get_DC_PHY_READ_TO_WRITE_reg   (*((volatile unsigned int*) DC_PHY_READ_TO_WRITE_reg))
#define DC_PHY_READ_TO_WRITE_inst_adr                                                "0x0076"
#define DC_PHY_READ_TO_WRITE_inst                                                    0x0076
#define DC_PHY_READ_TO_WRITE_r2w_cnt_shift                                           (0)
#define DC_PHY_READ_TO_WRITE_r2w_cnt_mask                                            (0x07FFFFFF)
#define DC_PHY_READ_TO_WRITE_r2w_cnt(data)                                           (0x07FFFFFF&((data)<<0))
#define DC_PHY_READ_TO_WRITE_r2w_cnt_src(data)                                       ((0x07FFFFFF&(data))>>0)
#define DC_PHY_READ_TO_WRITE_get_r2w_cnt(data)                                       ((0x07FFFFFF&(data))>>0)


#define DC_PHY_WRITE_CMD_LATENCY                                                     0x18008DDC
#define DC_PHY_WRITE_CMD_LATENCY_reg_addr                                            "0xB8008DDC"
#define DC_PHY_WRITE_CMD_LATENCY_reg                                                 0xB8008DDC
#define set_DC_PHY_WRITE_CMD_LATENCY_reg(data)   (*((volatile unsigned int*) DC_PHY_WRITE_CMD_LATENCY_reg)=data)
#define get_DC_PHY_WRITE_CMD_LATENCY_reg   (*((volatile unsigned int*) DC_PHY_WRITE_CMD_LATENCY_reg))
#define DC_PHY_WRITE_CMD_LATENCY_inst_adr                                            "0x0077"
#define DC_PHY_WRITE_CMD_LATENCY_inst                                                0x0077
#define DC_PHY_WRITE_CMD_LATENCY_req_to_cmd_w_shift                                  (0)
#define DC_PHY_WRITE_CMD_LATENCY_req_to_cmd_w_mask                                   (0x03FFFFFF)
#define DC_PHY_WRITE_CMD_LATENCY_req_to_cmd_w(data)                                  (0x03FFFFFF&((data)<<0))
#define DC_PHY_WRITE_CMD_LATENCY_req_to_cmd_w_src(data)                              ((0x03FFFFFF&(data))>>0)
#define DC_PHY_WRITE_CMD_LATENCY_get_req_to_cmd_w(data)                              ((0x03FFFFFF&(data))>>0)


#define DC_PHY_READ_CMD_LATENCY                                                      0x18008DE0
#define DC_PHY_READ_CMD_LATENCY_reg_addr                                             "0xB8008DE0"
#define DC_PHY_READ_CMD_LATENCY_reg                                                  0xB8008DE0
#define set_DC_PHY_READ_CMD_LATENCY_reg(data)   (*((volatile unsigned int*) DC_PHY_READ_CMD_LATENCY_reg)=data)
#define get_DC_PHY_READ_CMD_LATENCY_reg   (*((volatile unsigned int*) DC_PHY_READ_CMD_LATENCY_reg))
#define DC_PHY_READ_CMD_LATENCY_inst_adr                                             "0x0078"
#define DC_PHY_READ_CMD_LATENCY_inst                                                 0x0078
#define DC_PHY_READ_CMD_LATENCY_req_to_cmd_r_shift                                   (0)
#define DC_PHY_READ_CMD_LATENCY_req_to_cmd_r_mask                                    (0x03FFFFFF)
#define DC_PHY_READ_CMD_LATENCY_req_to_cmd_r(data)                                   (0x03FFFFFF&((data)<<0))
#define DC_PHY_READ_CMD_LATENCY_req_to_cmd_r_src(data)                               ((0x03FFFFFF&(data))>>0)
#define DC_PHY_READ_CMD_LATENCY_get_req_to_cmd_r(data)                               ((0x03FFFFFF&(data))>>0)


#define DC_PHY_BANK_CONFLICT                                                         0x18008DE4
#define DC_PHY_BANK_CONFLICT_reg_addr                                                "0xB8008DE4"
#define DC_PHY_BANK_CONFLICT_reg                                                     0xB8008DE4
#define set_DC_PHY_BANK_CONFLICT_reg(data)   (*((volatile unsigned int*) DC_PHY_BANK_CONFLICT_reg)=data)
#define get_DC_PHY_BANK_CONFLICT_reg   (*((volatile unsigned int*) DC_PHY_BANK_CONFLICT_reg))
#define DC_PHY_BANK_CONFLICT_inst_adr                                                "0x0079"
#define DC_PHY_BANK_CONFLICT_inst                                                    0x0079
#define DC_PHY_BANK_CONFLICT_bank_conflict_cnt_shift                                 (0)
#define DC_PHY_BANK_CONFLICT_bank_conflict_cnt_mask                                  (0x000FFFFF)
#define DC_PHY_BANK_CONFLICT_bank_conflict_cnt(data)                                 (0x000FFFFF&((data)<<0))
#define DC_PHY_BANK_CONFLICT_bank_conflict_cnt_src(data)                             ((0x000FFFFF&(data))>>0)
#define DC_PHY_BANK_CONFLICT_get_bank_conflict_cnt(data)                             ((0x000FFFFF&(data))>>0)


#define DC_PHY_WRITE_MERGE                                                           0x18008DE8
#define DC_PHY_WRITE_MERGE_reg_addr                                                  "0xB8008DE8"
#define DC_PHY_WRITE_MERGE_reg                                                       0xB8008DE8
#define set_DC_PHY_WRITE_MERGE_reg(data)   (*((volatile unsigned int*) DC_PHY_WRITE_MERGE_reg)=data)
#define get_DC_PHY_WRITE_MERGE_reg   (*((volatile unsigned int*) DC_PHY_WRITE_MERGE_reg))
#define DC_PHY_WRITE_MERGE_inst_adr                                                  "0x007A"
#define DC_PHY_WRITE_MERGE_inst                                                      0x007A
#define DC_PHY_WRITE_MERGE_wr_merge_cnt_exp_shift                                    (0)
#define DC_PHY_WRITE_MERGE_wr_merge_cnt_exp_mask                                     (0x0FFFFFFF)
#define DC_PHY_WRITE_MERGE_wr_merge_cnt_exp(data)                                    (0x0FFFFFFF&((data)<<0))
#define DC_PHY_WRITE_MERGE_wr_merge_cnt_exp_src(data)                                ((0x0FFFFFFF&(data))>>0)
#define DC_PHY_WRITE_MERGE_get_wr_merge_cnt_exp(data)                                ((0x0FFFFFFF&(data))>>0)


#define DC_PHY_READ_BYPASS                                                           0x18008DEC
#define DC_PHY_READ_BYPASS_reg_addr                                                  "0xB8008DEC"
#define DC_PHY_READ_BYPASS_reg                                                       0xB8008DEC
#define set_DC_PHY_READ_BYPASS_reg(data)   (*((volatile unsigned int*) DC_PHY_READ_BYPASS_reg)=data)
#define get_DC_PHY_READ_BYPASS_reg   (*((volatile unsigned int*) DC_PHY_READ_BYPASS_reg))
#define DC_PHY_READ_BYPASS_inst_adr                                                  "0x007B"
#define DC_PHY_READ_BYPASS_inst                                                      0x007B
#define DC_PHY_READ_BYPASS_rd_bypass_cnt_exp_shift                                   (0)
#define DC_PHY_READ_BYPASS_rd_bypass_cnt_exp_mask                                    (0x0FFFFFFF)
#define DC_PHY_READ_BYPASS_rd_bypass_cnt_exp(data)                                   (0x0FFFFFFF&((data)<<0))
#define DC_PHY_READ_BYPASS_rd_bypass_cnt_exp_src(data)                               ((0x0FFFFFFF&(data))>>0)
#define DC_PHY_READ_BYPASS_get_rd_bypass_cnt_exp(data)                               ((0x0FFFFFFF&(data))>>0)


#define DC_PHY_DC_SYS1_READ_BYPASS                                                   0x18008DF0
#define DC_PHY_DC_SYS1_READ_BYPASS_reg_addr                                          "0xB8008DF0"
#define DC_PHY_DC_SYS1_READ_BYPASS_reg                                               0xB8008DF0
#define set_DC_PHY_DC_SYS1_READ_BYPASS_reg(data)   (*((volatile unsigned int*) DC_PHY_DC_SYS1_READ_BYPASS_reg)=data)
#define get_DC_PHY_DC_SYS1_READ_BYPASS_reg   (*((volatile unsigned int*) DC_PHY_DC_SYS1_READ_BYPASS_reg))
#define DC_PHY_DC_SYS1_READ_BYPASS_inst_adr                                          "0x007C"
#define DC_PHY_DC_SYS1_READ_BYPASS_inst                                              0x007C
#define DC_PHY_DC_SYS1_READ_BYPASS_rd_bypass_cnt_dc_sys1_shift                       (0)
#define DC_PHY_DC_SYS1_READ_BYPASS_rd_bypass_cnt_dc_sys1_mask                        (0x0FFFFFFF)
#define DC_PHY_DC_SYS1_READ_BYPASS_rd_bypass_cnt_dc_sys1(data)                       (0x0FFFFFFF&((data)<<0))
#define DC_PHY_DC_SYS1_READ_BYPASS_rd_bypass_cnt_dc_sys1_src(data)                   ((0x0FFFFFFF&(data))>>0)
#define DC_PHY_DC_SYS1_READ_BYPASS_get_rd_bypass_cnt_dc_sys1(data)                   ((0x0FFFFFFF&(data))>>0)


#define DC_PHY_READ_CMD_AP                                                           0x18008DF4
#define DC_PHY_READ_CMD_AP_reg_addr                                                  "0xB8008DF4"
#define DC_PHY_READ_CMD_AP_reg                                                       0xB8008DF4
#define set_DC_PHY_READ_CMD_AP_reg(data)   (*((volatile unsigned int*) DC_PHY_READ_CMD_AP_reg)=data)
#define get_DC_PHY_READ_CMD_AP_reg   (*((volatile unsigned int*) DC_PHY_READ_CMD_AP_reg))
#define DC_PHY_READ_CMD_AP_inst_adr                                                  "0x007D"
#define DC_PHY_READ_CMD_AP_inst                                                      0x007D
#define DC_PHY_READ_CMD_AP_rd_ap_cnt_shift                                           (0)
#define DC_PHY_READ_CMD_AP_rd_ap_cnt_mask                                            (0x1FFFFFFF)
#define DC_PHY_READ_CMD_AP_rd_ap_cnt(data)                                           (0x1FFFFFFF&((data)<<0))
#define DC_PHY_READ_CMD_AP_rd_ap_cnt_src(data)                                       ((0x1FFFFFFF&(data))>>0)
#define DC_PHY_READ_CMD_AP_get_rd_ap_cnt(data)                                       ((0x1FFFFFFF&(data))>>0)


#define DC_PHY_WRITE_CMD_AP                                                          0x18008DF8
#define DC_PHY_WRITE_CMD_AP_reg_addr                                                 "0xB8008DF8"
#define DC_PHY_WRITE_CMD_AP_reg                                                      0xB8008DF8
#define set_DC_PHY_WRITE_CMD_AP_reg(data)   (*((volatile unsigned int*) DC_PHY_WRITE_CMD_AP_reg)=data)
#define get_DC_PHY_WRITE_CMD_AP_reg   (*((volatile unsigned int*) DC_PHY_WRITE_CMD_AP_reg))
#define DC_PHY_WRITE_CMD_AP_inst_adr                                                 "0x007E"
#define DC_PHY_WRITE_CMD_AP_inst                                                     0x007E
#define DC_PHY_WRITE_CMD_AP_wr_ap_cnt_shift                                          (0)
#define DC_PHY_WRITE_CMD_AP_wr_ap_cnt_mask                                           (0x1FFFFFFF)
#define DC_PHY_WRITE_CMD_AP_wr_ap_cnt(data)                                          (0x1FFFFFFF&((data)<<0))
#define DC_PHY_WRITE_CMD_AP_wr_ap_cnt_src(data)                                      ((0x1FFFFFFF&(data))>>0)
#define DC_PHY_WRITE_CMD_AP_get_wr_ap_cnt(data)                                      ((0x1FFFFFFF&(data))>>0)


#define DC_PHY_WEIGHT_ENABLE                                                         0x18008B80
#define DC_PHY_WEIGHT_ENABLE_reg_addr                                                "0xB8008B80"
#define DC_PHY_WEIGHT_ENABLE_reg                                                     0xB8008B80
#define set_DC_PHY_WEIGHT_ENABLE_reg(data)   (*((volatile unsigned int*) DC_PHY_WEIGHT_ENABLE_reg)=data)
#define get_DC_PHY_WEIGHT_ENABLE_reg   (*((volatile unsigned int*) DC_PHY_WEIGHT_ENABLE_reg))
#define DC_PHY_WEIGHT_ENABLE_inst_adr                                                "0x00E0"
#define DC_PHY_WEIGHT_ENABLE_inst                                                    0x00E0
#define DC_PHY_WEIGHT_ENABLE_outstand_reorder_en_shift                               (4)
#define DC_PHY_WEIGHT_ENABLE_outstand_reorder_en_mask                                (0x00000010)
#define DC_PHY_WEIGHT_ENABLE_outstand_reorder_en(data)                               (0x00000010&((data)<<4))
#define DC_PHY_WEIGHT_ENABLE_outstand_reorder_en_src(data)                           ((0x00000010&(data))>>4)
#define DC_PHY_WEIGHT_ENABLE_get_outstand_reorder_en(data)                           ((0x00000010&(data))>>4)
#define DC_PHY_WEIGHT_ENABLE_priority_weight_en_shift                                (3)
#define DC_PHY_WEIGHT_ENABLE_priority_weight_en_mask                                 (0x00000008)
#define DC_PHY_WEIGHT_ENABLE_priority_weight_en(data)                                (0x00000008&((data)<<3))
#define DC_PHY_WEIGHT_ENABLE_priority_weight_en_src(data)                            ((0x00000008&(data))>>3)
#define DC_PHY_WEIGHT_ENABLE_get_priority_weight_en(data)                            ((0x00000008&(data))>>3)
#define DC_PHY_WEIGHT_ENABLE_direction_weight_en_shift                               (2)
#define DC_PHY_WEIGHT_ENABLE_direction_weight_en_mask                                (0x00000004)
#define DC_PHY_WEIGHT_ENABLE_direction_weight_en(data)                               (0x00000004&((data)<<2))
#define DC_PHY_WEIGHT_ENABLE_direction_weight_en_src(data)                           ((0x00000004&(data))>>2)
#define DC_PHY_WEIGHT_ENABLE_get_direction_weight_en(data)                           ((0x00000004&(data))>>2)
#define DC_PHY_WEIGHT_ENABLE_length_weight_en_shift                                  (1)
#define DC_PHY_WEIGHT_ENABLE_length_weight_en_mask                                   (0x00000002)
#define DC_PHY_WEIGHT_ENABLE_length_weight_en(data)                                  (0x00000002&((data)<<1))
#define DC_PHY_WEIGHT_ENABLE_length_weight_en_src(data)                              ((0x00000002&(data))>>1)
#define DC_PHY_WEIGHT_ENABLE_get_length_weight_en(data)                              ((0x00000002&(data))>>1)
#define DC_PHY_WEIGHT_ENABLE_Bank_weight_en_shift                                    (0)
#define DC_PHY_WEIGHT_ENABLE_Bank_weight_en_mask                                     (0x00000001)
#define DC_PHY_WEIGHT_ENABLE_Bank_weight_en(data)                                    (0x00000001&((data)<<0))
#define DC_PHY_WEIGHT_ENABLE_Bank_weight_en_src(data)                                ((0x00000001&(data))>>0)
#define DC_PHY_WEIGHT_ENABLE_get_Bank_weight_en(data)                                ((0x00000001&(data))>>0)


#define DC_PHY_WEIGHT_PRIORITY                                                       0x18008B84
#define DC_PHY_WEIGHT_PRIORITY_reg_addr                                              "0xB8008B84"
#define DC_PHY_WEIGHT_PRIORITY_reg                                                   0xB8008B84
#define set_DC_PHY_WEIGHT_PRIORITY_reg(data)   (*((volatile unsigned int*) DC_PHY_WEIGHT_PRIORITY_reg)=data)
#define get_DC_PHY_WEIGHT_PRIORITY_reg   (*((volatile unsigned int*) DC_PHY_WEIGHT_PRIORITY_reg))
#define DC_PHY_WEIGHT_PRIORITY_inst_adr                                              "0x00E1"
#define DC_PHY_WEIGHT_PRIORITY_inst                                                  0x00E1
#define DC_PHY_WEIGHT_PRIORITY_pw_multiplier_shift                                   (0)
#define DC_PHY_WEIGHT_PRIORITY_pw_multiplier_mask                                    (0x00000007)
#define DC_PHY_WEIGHT_PRIORITY_pw_multiplier(data)                                   (0x00000007&((data)<<0))
#define DC_PHY_WEIGHT_PRIORITY_pw_multiplier_src(data)                               ((0x00000007&(data))>>0)
#define DC_PHY_WEIGHT_PRIORITY_get_pw_multiplier(data)                               ((0x00000007&(data))>>0)


#define DC_PHY_WEIGHT_DIERECTION                                                     0x18008B88
#define DC_PHY_WEIGHT_DIERECTION_reg_addr                                            "0xB8008B88"
#define DC_PHY_WEIGHT_DIERECTION_reg                                                 0xB8008B88
#define set_DC_PHY_WEIGHT_DIERECTION_reg(data)   (*((volatile unsigned int*) DC_PHY_WEIGHT_DIERECTION_reg)=data)
#define get_DC_PHY_WEIGHT_DIERECTION_reg   (*((volatile unsigned int*) DC_PHY_WEIGHT_DIERECTION_reg))
#define DC_PHY_WEIGHT_DIERECTION_inst_adr                                            "0x00E2"
#define DC_PHY_WEIGHT_DIERECTION_inst                                                0x00E2
#define DC_PHY_WEIGHT_DIERECTION_dw_init_dynamic_en_shift                            (19)
#define DC_PHY_WEIGHT_DIERECTION_dw_init_dynamic_en_mask                             (0x00080000)
#define DC_PHY_WEIGHT_DIERECTION_dw_init_dynamic_en(data)                            (0x00080000&((data)<<19))
#define DC_PHY_WEIGHT_DIERECTION_dw_init_dynamic_en_src(data)                        ((0x00080000&(data))>>19)
#define DC_PHY_WEIGHT_DIERECTION_get_dw_init_dynamic_en(data)                        ((0x00080000&(data))>>19)
#define DC_PHY_WEIGHT_DIERECTION_dw_init_r_shift                                     (11)
#define DC_PHY_WEIGHT_DIERECTION_dw_init_r_mask                                      (0x0007F800)
#define DC_PHY_WEIGHT_DIERECTION_dw_init_r(data)                                     (0x0007F800&((data)<<11))
#define DC_PHY_WEIGHT_DIERECTION_dw_init_r_src(data)                                 ((0x0007F800&(data))>>11)
#define DC_PHY_WEIGHT_DIERECTION_get_dw_init_r(data)                                 ((0x0007F800&(data))>>11)
#define DC_PHY_WEIGHT_DIERECTION_dw_init_w_shift                                     (3)
#define DC_PHY_WEIGHT_DIERECTION_dw_init_w_mask                                      (0x000007F8)
#define DC_PHY_WEIGHT_DIERECTION_dw_init_w(data)                                     (0x000007F8&((data)<<3))
#define DC_PHY_WEIGHT_DIERECTION_dw_init_w_src(data)                                 ((0x000007F8&(data))>>3)
#define DC_PHY_WEIGHT_DIERECTION_get_dw_init_w(data)                                 ((0x000007F8&(data))>>3)
#define DC_PHY_WEIGHT_DIERECTION_dw_multiplier_shift                                 (0)
#define DC_PHY_WEIGHT_DIERECTION_dw_multiplier_mask                                  (0x00000007)
#define DC_PHY_WEIGHT_DIERECTION_dw_multiplier(data)                                 (0x00000007&((data)<<0))
#define DC_PHY_WEIGHT_DIERECTION_dw_multiplier_src(data)                             ((0x00000007&(data))>>0)
#define DC_PHY_WEIGHT_DIERECTION_get_dw_multiplier(data)                             ((0x00000007&(data))>>0)


#define DC_PHY_WEIGHT_LENGTH                                                         0x18008B8C
#define DC_PHY_WEIGHT_LENGTH_reg_addr                                                "0xB8008B8C"
#define DC_PHY_WEIGHT_LENGTH_reg                                                     0xB8008B8C
#define set_DC_PHY_WEIGHT_LENGTH_reg(data)   (*((volatile unsigned int*) DC_PHY_WEIGHT_LENGTH_reg)=data)
#define get_DC_PHY_WEIGHT_LENGTH_reg   (*((volatile unsigned int*) DC_PHY_WEIGHT_LENGTH_reg))
#define DC_PHY_WEIGHT_LENGTH_inst_adr                                                "0x00E3"
#define DC_PHY_WEIGHT_LENGTH_inst                                                    0x00E3
#define DC_PHY_WEIGHT_LENGTH_lw_long_burst_prior_shift                               (3)
#define DC_PHY_WEIGHT_LENGTH_lw_long_burst_prior_mask                                (0x00000008)
#define DC_PHY_WEIGHT_LENGTH_lw_long_burst_prior(data)                               (0x00000008&((data)<<3))
#define DC_PHY_WEIGHT_LENGTH_lw_long_burst_prior_src(data)                           ((0x00000008&(data))>>3)
#define DC_PHY_WEIGHT_LENGTH_get_lw_long_burst_prior(data)                           ((0x00000008&(data))>>3)
#define DC_PHY_WEIGHT_LENGTH_lw_multiplier_shift                                     (0)
#define DC_PHY_WEIGHT_LENGTH_lw_multiplier_mask                                      (0x00000007)
#define DC_PHY_WEIGHT_LENGTH_lw_multiplier(data)                                     (0x00000007&((data)<<0))
#define DC_PHY_WEIGHT_LENGTH_lw_multiplier_src(data)                                 ((0x00000007&(data))>>0)
#define DC_PHY_WEIGHT_LENGTH_get_lw_multiplier(data)                                 ((0x00000007&(data))>>0)


#define DC_PHY_WEIGHT_BANK                                                           0x18008B90
#define DC_PHY_WEIGHT_BANK_reg_addr                                                  "0xB8008B90"
#define DC_PHY_WEIGHT_BANK_reg                                                       0xB8008B90
#define set_DC_PHY_WEIGHT_BANK_reg(data)   (*((volatile unsigned int*) DC_PHY_WEIGHT_BANK_reg)=data)
#define get_DC_PHY_WEIGHT_BANK_reg   (*((volatile unsigned int*) DC_PHY_WEIGHT_BANK_reg))
#define DC_PHY_WEIGHT_BANK_inst_adr                                                  "0x00E4"
#define DC_PHY_WEIGHT_BANK_inst                                                      0x00E4
#define DC_PHY_WEIGHT_BANK_bw_pend_cycle_shift                                       (16)
#define DC_PHY_WEIGHT_BANK_bw_pend_cycle_mask                                        (0x007F0000)
#define DC_PHY_WEIGHT_BANK_bw_pend_cycle(data)                                       (0x007F0000&((data)<<16))
#define DC_PHY_WEIGHT_BANK_bw_pend_cycle_src(data)                                   ((0x007F0000&(data))>>16)
#define DC_PHY_WEIGHT_BANK_get_bw_pend_cycle(data)                                   ((0x007F0000&(data))>>16)
#define DC_PHY_WEIGHT_BANK_bw_pend_en_shift                                          (15)
#define DC_PHY_WEIGHT_BANK_bw_pend_en_mask                                           (0x00008000)
#define DC_PHY_WEIGHT_BANK_bw_pend_en(data)                                          (0x00008000&((data)<<15))
#define DC_PHY_WEIGHT_BANK_bw_pend_en_src(data)                                      ((0x00008000&(data))>>15)
#define DC_PHY_WEIGHT_BANK_get_bw_pend_en(data)                                      ((0x00008000&(data))>>15)
#define DC_PHY_WEIGHT_BANK_bw_trc_shift                                              (8)
#define DC_PHY_WEIGHT_BANK_bw_trc_mask                                               (0x00007F00)
#define DC_PHY_WEIGHT_BANK_bw_trc(data)                                              (0x00007F00&((data)<<8))
#define DC_PHY_WEIGHT_BANK_bw_trc_src(data)                                          ((0x00007F00&(data))>>8)
#define DC_PHY_WEIGHT_BANK_get_bw_trc(data)                                          ((0x00007F00&(data))>>8)
#define DC_PHY_WEIGHT_BANK_bw_trp_shift                                              (3)
#define DC_PHY_WEIGHT_BANK_bw_trp_mask                                               (0x000000F8)
#define DC_PHY_WEIGHT_BANK_bw_trp(data)                                              (0x000000F8&((data)<<3))
#define DC_PHY_WEIGHT_BANK_bw_trp_src(data)                                          ((0x000000F8&(data))>>3)
#define DC_PHY_WEIGHT_BANK_get_bw_trp(data)                                          ((0x000000F8&(data))>>3)
#define DC_PHY_WEIGHT_BANK_bw_multiplier_shift                                       (0)
#define DC_PHY_WEIGHT_BANK_bw_multiplier_mask                                        (0x00000007)
#define DC_PHY_WEIGHT_BANK_bw_multiplier(data)                                       (0x00000007&((data)<<0))
#define DC_PHY_WEIGHT_BANK_bw_multiplier_src(data)                                   ((0x00000007&(data))>>0)
#define DC_PHY_WEIGHT_BANK_get_bw_multiplier(data)                                   ((0x00000007&(data))>>0)


#define DC_PHY_MULTI_CLIENT                                                          0x18008Bf0
#define DC_PHY_MULTI_CLIENT_reg_addr                                                 "0xB8008BF0"
#define DC_PHY_MULTI_CLIENT_reg                                                      0xB8008BF0
#define set_DC_PHY_MULTI_CLIENT_reg(data)   (*((volatile unsigned int*) DC_PHY_MULTI_CLIENT_reg)=data)
#define get_DC_PHY_MULTI_CLIENT_reg   (*((volatile unsigned int*) DC_PHY_MULTI_CLIENT_reg))
#define DC_PHY_MULTI_CLIENT_inst_adr                                                 "0x00FC"
#define DC_PHY_MULTI_CLIENT_inst                                                     0x00FC
#define DC_PHY_MULTI_CLIENT_dc_sys2_group_en_shift                                   (3)
#define DC_PHY_MULTI_CLIENT_dc_sys2_group_en_mask                                    (0x00000008)
#define DC_PHY_MULTI_CLIENT_dc_sys2_group_en(data)                                   (0x00000008&((data)<<3))
#define DC_PHY_MULTI_CLIENT_dc_sys2_group_en_src(data)                               ((0x00000008&(data))>>3)
#define DC_PHY_MULTI_CLIENT_get_dc_sys2_group_en(data)                               ((0x00000008&(data))>>3)
#define DC_PHY_MULTI_CLIENT_dc_sys1_group_en_shift                                   (2)
#define DC_PHY_MULTI_CLIENT_dc_sys1_group_en_mask                                    (0x00000004)
#define DC_PHY_MULTI_CLIENT_dc_sys1_group_en(data)                                   (0x00000004&((data)<<2))
#define DC_PHY_MULTI_CLIENT_dc_sys1_group_en_src(data)                               ((0x00000004&(data))>>2)
#define DC_PHY_MULTI_CLIENT_get_dc_sys1_group_en(data)                               ((0x00000004&(data))>>2)
#define DC_PHY_MULTI_CLIENT_express_lane_group_en_shift                              (1)
#define DC_PHY_MULTI_CLIENT_express_lane_group_en_mask                               (0x00000002)
#define DC_PHY_MULTI_CLIENT_express_lane_group_en(data)                              (0x00000002&((data)<<1))
#define DC_PHY_MULTI_CLIENT_express_lane_group_en_src(data)                          ((0x00000002&(data))>>1)
#define DC_PHY_MULTI_CLIENT_get_express_lane_group_en(data)                          ((0x00000002&(data))>>1)
#define DC_PHY_MULTI_CLIENT_express_lane_wr_separate_en_shift                        (0)
#define DC_PHY_MULTI_CLIENT_express_lane_wr_separate_en_mask                         (0x00000001)
#define DC_PHY_MULTI_CLIENT_express_lane_wr_separate_en(data)                        (0x00000001&((data)<<0))
#define DC_PHY_MULTI_CLIENT_express_lane_wr_separate_en_src(data)                    ((0x00000001&(data))>>0)
#define DC_PHY_MULTI_CLIENT_get_express_lane_wr_separate_en(data)                    ((0x00000001&(data))>>0)


#endif

