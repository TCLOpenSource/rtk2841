/**************************************************************
// Spec Version                  : 3.1
// Parser Version                : DVR_Parser_6.11(120105)
// CModelGen Version             : 5.1 2012.01.05
// Naming Rule                   :  Register_Name
// Naming Rule                   : Module_Register_Name_reg
// Parse Option                  : Only Parse _op1
// Parse Address Region          : All Address Region 
// Decode bit number             : 12 bits
// Firmware Header Generate Date : 2014/1/22 16:14:29
***************************************************************/


#ifndef _AE_REG_H_INCLUDED_
#define _AE_REG_H_INCLUDED_
#ifdef  _AE_USE_STRUCT
typedef struct 
{
unsigned int     reserved_0:1;
unsigned int     src:31;
}ADSP_ADE_SRC;

typedef struct 
{
unsigned int     reserved_0:1;
unsigned int     dst:31;
}ADSP_ADE_DST;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     valid:1;
unsigned int     dir:1;
unsigned int     size:14;
}ADSP_ADE_SIZE;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     done_7:1;
unsigned int     done_6:1;
unsigned int     done_5:1;
unsigned int     done_4:1;
unsigned int     done_3:1;
unsigned int     done_2:1;
unsigned int     done_1:1;
unsigned int     done_0:1;
}ADSP_ADE_STATUS;

typedef struct 
{
unsigned int     reserved_0:14;
unsigned int     write_en1:1;
unsigned int     max_xfer:6;
unsigned int     reserved_1:5;
unsigned int     write_en3:1;
unsigned int     dmem_req_en:1;
unsigned int     write_en4:1;
unsigned int     stop:1;
unsigned int     write_en5:1;
unsigned int     go:1;
}ADSP_ADE_CNTL;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     int_done:1;
}ADSP_ADE_INT;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     int_done_en:1;
}ADSP_ADE_INT_EN;

typedef struct 
{
unsigned int     reserved_0:13;
unsigned int     max_xfer:6;
unsigned int     reserved_1:4;
unsigned int     threshold:6;
unsigned int     reserved_2:3;
}ADSP_AEE_THLD;

typedef struct 
{
unsigned int     reserved_0:18;
unsigned int     bit_cnt:14;
}ADSP_AEE_VBIT_CNT;

typedef struct 
{
unsigned int     used_cnt:32;
}ADSP_AEE_USED_CNT;

typedef struct 
{
unsigned int     reserved_0:27;
unsigned int     write_en1:1;
unsigned int     stop:1;
unsigned int     write_en2:1;
unsigned int     dir:1;
unsigned int     go:1;
}ADSP_AEE_CTRL;

typedef struct 
{
unsigned int     reserved_0:27;
unsigned int     int4:1;
unsigned int     int3:1;
unsigned int     int2:1;
unsigned int     int1:1;
unsigned int     write_data:1;
}ADSP_AEE_INT;

typedef struct 
{
unsigned int     reserved_0:27;
unsigned int     int4_en:1;
unsigned int     int3_en:1;
unsigned int     int2_en:1;
unsigned int     int1_en:1;
unsigned int     write_data:1;
}ADSP_AEE_INT_EN;

typedef struct 
{
unsigned int     reserved_0:1;
unsigned int     ring_limit:28;
unsigned int     reserved_1:3;
}ADSP_AEE_RING_LIMIT;

typedef struct 
{
unsigned int     reserved_0:1;
unsigned int     ring_base:28;
unsigned int     reserved_1:3;
}ADSP_AEE_RING_BASE;

typedef struct 
{
unsigned int     reserved_0:1;
unsigned int     ring_rp:31;
}ADSP_AEE_RING_RP;

typedef struct 
{
unsigned int     reserved_0:1;
unsigned int     ring_wp:31;
}ADSP_AEE_RING_WP;

typedef struct 
{
unsigned int     reserved_0:1;
unsigned int     ring_cp:31;
}ADSP_AEE_RING_CP;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     limit:16;
}ADSP_AEE_SEARCH_LIMIT;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     crc_init:16;
}ADSP_AEE_CRC_INIT;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     write_en4:1;
unsigned int     crc_mode:1;
unsigned int     write_en1:1;
unsigned int     crc_reset:1;
unsigned int     write_en2:1;
unsigned int     crc_cont:1;
unsigned int     write_en3:1;
unsigned int     crc_on:1;
}ADSP_AEE_CRC_CNTL;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     crc_length:16;
}ADSP_AEE_CRC_LENGTH;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     crc_result:16;
}ADSP_AEE_CRC_RESULT;

typedef struct 
{
unsigned int     crc_bit_cnt:32;
}ADSP_AEE_BIT_CNT;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     acc:16;
}ADSP_AEE_CRC_ACC;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     acc_cnt:4;
}ADSP_AEE_CRC_ACC_CNT;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     aee_audio_mode:2;
}AEE_OGG_MODE;

typedef struct 
{
unsigned int     reserved_0:19;
unsigned int     ae_dbg_en:1;
unsigned int     ae_dbg_sel1:6;
unsigned int     ae_dbg_sel0:6;
}AE_DEBUG;

typedef struct 
{
unsigned int     reserved_0:1;
unsigned int     src_src_base:28;
unsigned int     reserved_1:3;
}SRC_SRC_BASE;

typedef struct 
{
unsigned int     reserved_0:1;
unsigned int     src_src_wp:29;
unsigned int     reserved_1:2;
}SRC_SRC_WP;

typedef struct 
{
unsigned int     reserved_0:1;
unsigned int     src_src_rp:29;
unsigned int     reserved_1:2;
}SRC_SRC_RP;

typedef struct 
{
unsigned int     reserved_0:1;
unsigned int     src_dest_base:28;
unsigned int     reserved_1:3;
}SRC_DEST_BASE;

typedef struct 
{
unsigned int     reserved_0:1;
unsigned int     src_dest_wp:29;
unsigned int     reserved_1:2;
}SRC_DEST_WP;

typedef struct 
{
unsigned int     reserved_0:1;
unsigned int     src_dest_rp:29;
unsigned int     reserved_1:2;
}SRC_DEST_RP;

typedef struct 
{
unsigned int     reserved_0:1;
unsigned int     base:28;
unsigned int     reserved_1:3;
}SRC_ITR_BUF0;

typedef struct 
{
unsigned int     reserved_0:1;
unsigned int     wp:29;
unsigned int     reserved_1:2;
}SRC_ITR_BUF1;

typedef struct 
{
unsigned int     reserved_0:1;
unsigned int     rp:29;
unsigned int     reserved_1:2;
}SRC_ITR_BUF2;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     write_en3:1;
unsigned int     itr_rb_size:7;
unsigned int     reserved_1:9;
unsigned int     write_en2:1;
unsigned int     phase:1;
unsigned int     write_en1:1;
unsigned int     src_mode:4;
}SRC_CTRL0;

typedef struct 
{
unsigned int     write_en6:1;
unsigned int     src_rb_size:7;
unsigned int     write_en5:1;
unsigned int     dest_rb_size:7;
unsigned int     write_en4:1;
unsigned int     reserved_0:1;
unsigned int     write_en3:1;
unsigned int     chan_num:3;
unsigned int     write_en2:1;
unsigned int     reserved_1:3;
unsigned int     write_en:1;
unsigned int     size:5;
}SRC_CTRL1;

typedef struct 
{
unsigned int     reserved_0:2;
unsigned int     write_en7:1;
unsigned int     idx_2:8;
unsigned int     write_en6:1;
unsigned int     rom_sync_sel:1;
unsigned int     write_en5:1;
unsigned int     filter_tap:2;
unsigned int     write_en4:1;
unsigned int     idx:8;
unsigned int     write_en3:1;
unsigned int     mode:2;
unsigned int     write_en2:1;
unsigned int     stop:1;
unsigned int     write_en1:1;
unsigned int     go:1;
}SRC_CTRL2;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     chan_busy:3;
}SRC_STATUS;

typedef struct 
{
unsigned int     reserved_0:20;
unsigned int     write_en6:1;
unsigned int     stop_en:1;
unsigned int     write_en5:1;
unsigned int     time_out:1;
unsigned int     write_en4:1;
unsigned int     done:1;
unsigned int     write_en3:1;
unsigned int     error:1;
unsigned int     write_en2:1;
unsigned int     src_rb_empty:1;
unsigned int     write_en1:1;
unsigned int     dest_rb_full:1;
}SRC_RB_STATUS;

typedef struct 
{
unsigned int     reserved_0:22;
unsigned int     write_en5:1;
unsigned int     time_out:1;
unsigned int     write_en4:1;
unsigned int     done_en:1;
unsigned int     write_en3:1;
unsigned int     error_en:1;
unsigned int     write_en2:1;
unsigned int     src_rb_empty_en:1;
unsigned int     write_en1:1;
unsigned int     dest_rb_full_en:1;
}SRC_INT_EN;

typedef struct 
{
unsigned int     reserved_0:7;
unsigned int     thld:25;
}SRC_SRC_THRESHOLD;

typedef struct 
{
unsigned int     reserved_0:1;
unsigned int     adr1:29;
unsigned int     reserved_1:2;
}FILTER_COEF_0;

typedef struct 
{
unsigned int     reserved_0:1;
unsigned int     adr:29;
unsigned int     reserved_1:2;
}FILTER_COEF;

typedef struct 
{
unsigned int     reserved_0:1;
unsigned int     adr1_phase2:29;
unsigned int     reserved_1:2;
}FILTER_COEF_2;

typedef struct 
{
unsigned int     reserved_0:1;
unsigned int     adr2_phase2:29;
unsigned int     reserved_1:2;
}FILTER_COEF_3;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     load_coef:1;
}FILTER_COEF_CTRL;

typedef struct 
{
unsigned int     dummy:32;
}AE_DUMMY;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     str_state_flt:4;
unsigned int     reserved_1:4;
unsigned int     str_state_dma:4;
unsigned int     reserved_2:4;
unsigned int     dma_state:4;
unsigned int     reserved_3:4;
unsigned int     ctrl_state:4;
}AE_SRC_STATE;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     acc_sel_stg1:5;
unsigned int     reserved_1:3;
unsigned int     acc_sel_stg2:5;
unsigned int     reserved_2:6;
unsigned int     in_load_num:10;
}NEW_CTRL;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     rst:1;
}AE_SRC_RST;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     enable:1;
}SRC_FLEX_FLT_0;

typedef struct 
{
unsigned int     reserved_0:22;
unsigned int     tap1_num:10;
}SRC_FLEX_FLT_1;

typedef struct 
{
unsigned int     reserved_0:12;
unsigned int     rate_down_1:4;
unsigned int     reserved_1:1;
unsigned int     rate_down_0:7;
unsigned int     rate_up:8;
}SRC_FLEX_FLT_1;

typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     ls_acpu:1;
unsigned int     rme_acpu:1;
unsigned int     rm_dmem:4;
unsigned int     reserved_1:20;
}MBIST_ACPU;

typedef struct 
{
unsigned int     rm_dc_tag:4;
unsigned int     reserved_0:12;
unsigned int     rm_ic_tag0:4;
unsigned int     rm_ic_tag1:4;
unsigned int     reserved_1:8;
}MBIST_ACPU;

typedef struct 
{
unsigned int     rm_dc_data:4;
unsigned int     reserved_0:12;
unsigned int     rm_ic_data0:4;
unsigned int     rm_ic_data1:4;
unsigned int     reserved_1:8;
}MBISR_ACPU;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     acpu_bist_mode:1;
}MBIST_ACPU;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     acpu_bist_done:1;
}MBIST_ACPU;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     acpu_bist_fail_group:1;
}MBIST_ACPU;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     bist_fail2:1;
unsigned int     bist_fail1:1;
unsigned int     bist_fail0:1;
}MBIST_ACPU;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     drf_mode:1;
}MBIST_ACPU;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     drf_resume:1;
}MBIST_ACPU;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     drf_done:1;
}MBIST_ACPU;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     drf_pause:1;
}MBIST_ACPU;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     drf_fail_group:1;
}MBIST_ACPU;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     drf_fail2:1;
unsigned int     drf_fail1:1;
unsigned int     drf_fail0:1;
}MBIST_ACPU;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     second_run_en:1;
}MBISR_ACPU;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     fail_group:1;
}MBISR_ACPU;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     bisr_fail_3:1;
unsigned int     bisr_fail_2:1;
unsigned int     bisr_fail_1:1;
unsigned int     bisr_fail_0:1;
}MBISR_ACPU;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     drf_mode:1;
}MBISR_ACPU;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     drf_resume:1;
}MBISR_ACPU;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     drf_done:1;
}MBISR_ACPU;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     drf_fail_group:1;
}MBISR_ACPU;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     drf_pause:1;
}MBISR_ACPU;

typedef struct 
{
unsigned int     drf_repaired:1;
unsigned int     reserved_0:27;
unsigned int     drf_fail_3:1;
unsigned int     drf_fail_2:1;
unsigned int     drf_fail_1:1;
unsigned int     drf_fail_0:1;
}MBISR_ACPU;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     rmeb_aee:1;
unsigned int     rmb_aee:4;
unsigned int     reserved_1:3;
unsigned int     rmea_aee:1;
unsigned int     rma_aee:4;
unsigned int     reserved_2:3;
unsigned int     rmeb_ade:1;
unsigned int     rmb_ade:4;
unsigned int     reserved_3:3;
unsigned int     rmea_ade:1;
unsigned int     rma_ade:4;
}AE_BIST;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     rme_src_coef:1;
unsigned int     rm_src_coef:4;
unsigned int     reserved_1:3;
unsigned int     rme_src_dat:1;
unsigned int     rm_src_dat:4;
unsigned int     reserved_2:3;
unsigned int     rmeb_src_rwbuf:1;
unsigned int     rmb_src_rwbuf:4;
unsigned int     reserved_3:3;
unsigned int     rmea_src_rwbuf:1;
unsigned int     rma_src_rwbuf:4;
}AE_BIST;

typedef struct 
{
unsigned int     reserved_0:27;
unsigned int     mode_src_coef:1;
unsigned int     mode_src_dat:1;
unsigned int     mode_src_rwbuf:1;
unsigned int     mode_aee:1;
unsigned int     mode_ade:1;
}AE_BIST;

typedef struct 
{
unsigned int     reserved_0:27;
unsigned int     done_src_coef:1;
unsigned int     done_src_dat:1;
unsigned int     done_src_rwbuf:1;
unsigned int     done_aee:1;
unsigned int     done_ade:1;
}AE_BIST;

typedef struct 
{
unsigned int     reserved_0:27;
unsigned int     fail_src_coef:1;
unsigned int     fail_src_dat:1;
unsigned int     fail_src_rwbuf:1;
unsigned int     fail_aee:1;
unsigned int     fail_ade:1;
}AE_BIST;

typedef struct 
{
unsigned int     reserved_0:27;
unsigned int     mode_src_coef:1;
unsigned int     mode_src_dat:1;
unsigned int     mode_src_rwbuf:1;
unsigned int     mode_aee:1;
unsigned int     mode_ade:1;
}AE_DRF;

typedef struct 
{
unsigned int     reserved_0:27;
unsigned int     done_src_coef:1;
unsigned int     done_src_dat:1;
unsigned int     done_src_rwbuf:1;
unsigned int     done_aee:1;
unsigned int     done_ade:1;
}AE_DRF;

typedef struct 
{
unsigned int     reserved_0:27;
unsigned int     fail_src_coef:1;
unsigned int     fail_src_dat:1;
unsigned int     fail_src_rwbuf:1;
unsigned int     fail_aee:1;
unsigned int     fail_ade:1;
}AE_DRF;

typedef struct 
{
unsigned int     reserved_0:27;
unsigned int     pause_src_coef:1;
unsigned int     pause_src_dat:1;
unsigned int     pause_src_rwbuf:1;
unsigned int     pause_aee:1;
unsigned int     pause_ade:1;
}AE_DRF;

typedef struct 
{
unsigned int     reserved_0:27;
unsigned int     resume_src_coef:1;
unsigned int     resume_src_dat:1;
unsigned int     resume_src_rwbuf:1;
unsigned int     resume_aee:1;
unsigned int     resume_ade:1;
}AE_DRF;

typedef struct 
{
unsigned int     reserved_0:27;
unsigned int     ls_src_coef:1;
unsigned int     ls_src_dat:1;
unsigned int     ls_src_rwbuf:1;
unsigned int     ls_aee:1;
unsigned int     ls_ade:1;
}AE_BIST;

#endif

#define ADSP_ADE_SRC_0                                                               0x18002000
#define ADSP_ADE_SRC_1                                                               0x18002004
#define ADSP_ADE_SRC_2                                                               0x18002008
#define ADSP_ADE_SRC_3                                                               0x1800200C
#define ADSP_ADE_SRC_4                                                               0x18002010
#define ADSP_ADE_SRC_5                                                               0x18002014
#define ADSP_ADE_SRC_6                                                               0x18002018
#define ADSP_ADE_SRC_7                                                               0x1800201C
#define ADSP_ADE_SRC_0_reg_addr                                                      "0xB8002000"
#define ADSP_ADE_SRC_1_reg_addr                                                      "0xB8002004"
#define ADSP_ADE_SRC_2_reg_addr                                                      "0xB8002008"
#define ADSP_ADE_SRC_3_reg_addr                                                      "0xB800200C"
#define ADSP_ADE_SRC_4_reg_addr                                                      "0xB8002010"
#define ADSP_ADE_SRC_5_reg_addr                                                      "0xB8002014"
#define ADSP_ADE_SRC_6_reg_addr                                                      "0xB8002018"
#define ADSP_ADE_SRC_7_reg_addr                                                      "0xB800201C"
#define ADSP_ADE_SRC_0_reg                                                           0xB8002000
#define ADSP_ADE_SRC_1_reg                                                           0xB8002004
#define ADSP_ADE_SRC_2_reg                                                           0xB8002008
#define ADSP_ADE_SRC_3_reg                                                           0xB800200C
#define ADSP_ADE_SRC_4_reg                                                           0xB8002010
#define ADSP_ADE_SRC_5_reg                                                           0xB8002014
#define ADSP_ADE_SRC_6_reg                                                           0xB8002018
#define ADSP_ADE_SRC_7_reg                                                           0xB800201C
#define set_ADSP_ADE_SRC_0_reg(data)   (*((volatile unsigned int*) ADSP_ADE_SRC_0_reg)=data)
#define set_ADSP_ADE_SRC_1_reg(data)   (*((volatile unsigned int*) ADSP_ADE_SRC_1_reg)=data)
#define set_ADSP_ADE_SRC_2_reg(data)   (*((volatile unsigned int*) ADSP_ADE_SRC_2_reg)=data)
#define set_ADSP_ADE_SRC_3_reg(data)   (*((volatile unsigned int*) ADSP_ADE_SRC_3_reg)=data)
#define set_ADSP_ADE_SRC_4_reg(data)   (*((volatile unsigned int*) ADSP_ADE_SRC_4_reg)=data)
#define set_ADSP_ADE_SRC_5_reg(data)   (*((volatile unsigned int*) ADSP_ADE_SRC_5_reg)=data)
#define set_ADSP_ADE_SRC_6_reg(data)   (*((volatile unsigned int*) ADSP_ADE_SRC_6_reg)=data)
#define set_ADSP_ADE_SRC_7_reg(data)   (*((volatile unsigned int*) ADSP_ADE_SRC_7_reg)=data)
#define get_ADSP_ADE_SRC_0_reg   (*((volatile unsigned int*) ADSP_ADE_SRC_0_reg))
#define get_ADSP_ADE_SRC_1_reg   (*((volatile unsigned int*) ADSP_ADE_SRC_1_reg))
#define get_ADSP_ADE_SRC_2_reg   (*((volatile unsigned int*) ADSP_ADE_SRC_2_reg))
#define get_ADSP_ADE_SRC_3_reg   (*((volatile unsigned int*) ADSP_ADE_SRC_3_reg))
#define get_ADSP_ADE_SRC_4_reg   (*((volatile unsigned int*) ADSP_ADE_SRC_4_reg))
#define get_ADSP_ADE_SRC_5_reg   (*((volatile unsigned int*) ADSP_ADE_SRC_5_reg))
#define get_ADSP_ADE_SRC_6_reg   (*((volatile unsigned int*) ADSP_ADE_SRC_6_reg))
#define get_ADSP_ADE_SRC_7_reg   (*((volatile unsigned int*) ADSP_ADE_SRC_7_reg))
#define ADSP_ADE_SRC_0_inst_adr                                                      "0x0000"
#define ADSP_ADE_SRC_1_inst_adr                                                      "0x0001"
#define ADSP_ADE_SRC_2_inst_adr                                                      "0x0002"
#define ADSP_ADE_SRC_3_inst_adr                                                      "0x0003"
#define ADSP_ADE_SRC_4_inst_adr                                                      "0x0004"
#define ADSP_ADE_SRC_5_inst_adr                                                      "0x0005"
#define ADSP_ADE_SRC_6_inst_adr                                                      "0x0006"
#define ADSP_ADE_SRC_7_inst_adr                                                      "0x0007"
#define ADSP_ADE_SRC_0_inst                                                          0x0000
#define ADSP_ADE_SRC_1_inst                                                          0x0001
#define ADSP_ADE_SRC_2_inst                                                          0x0002
#define ADSP_ADE_SRC_3_inst                                                          0x0003
#define ADSP_ADE_SRC_4_inst                                                          0x0004
#define ADSP_ADE_SRC_5_inst                                                          0x0005
#define ADSP_ADE_SRC_6_inst                                                          0x0006
#define ADSP_ADE_SRC_7_inst                                                          0x0007
#define ADSP_ADE_SRC_src_shift                                                       (0)
#define ADSP_ADE_SRC_src_mask                                                        (0x7FFFFFFF)
#define ADSP_ADE_SRC_src(data)                                                       (0x7FFFFFFF&((data)<<0))
#define ADSP_ADE_SRC_src_src(data)                                                   ((0x7FFFFFFF&(data))>>0)
#define ADSP_ADE_SRC_get_src(data)                                                   ((0x7FFFFFFF&(data))>>0)


#define ADSP_ADE_DST_0                                                               0x18002020
#define ADSP_ADE_DST_1                                                               0x18002024
#define ADSP_ADE_DST_2                                                               0x18002028
#define ADSP_ADE_DST_3                                                               0x1800202C
#define ADSP_ADE_DST_4                                                               0x18002030
#define ADSP_ADE_DST_5                                                               0x18002034
#define ADSP_ADE_DST_6                                                               0x18002038
#define ADSP_ADE_DST_7                                                               0x1800203C
#define ADSP_ADE_DST_0_reg_addr                                                      "0xB8002020"
#define ADSP_ADE_DST_1_reg_addr                                                      "0xB8002024"
#define ADSP_ADE_DST_2_reg_addr                                                      "0xB8002028"
#define ADSP_ADE_DST_3_reg_addr                                                      "0xB800202C"
#define ADSP_ADE_DST_4_reg_addr                                                      "0xB8002030"
#define ADSP_ADE_DST_5_reg_addr                                                      "0xB8002034"
#define ADSP_ADE_DST_6_reg_addr                                                      "0xB8002038"
#define ADSP_ADE_DST_7_reg_addr                                                      "0xB800203C"
#define ADSP_ADE_DST_0_reg                                                           0xB8002020
#define ADSP_ADE_DST_1_reg                                                           0xB8002024
#define ADSP_ADE_DST_2_reg                                                           0xB8002028
#define ADSP_ADE_DST_3_reg                                                           0xB800202C
#define ADSP_ADE_DST_4_reg                                                           0xB8002030
#define ADSP_ADE_DST_5_reg                                                           0xB8002034
#define ADSP_ADE_DST_6_reg                                                           0xB8002038
#define ADSP_ADE_DST_7_reg                                                           0xB800203C
#define set_ADSP_ADE_DST_0_reg(data)   (*((volatile unsigned int*) ADSP_ADE_DST_0_reg)=data)
#define set_ADSP_ADE_DST_1_reg(data)   (*((volatile unsigned int*) ADSP_ADE_DST_1_reg)=data)
#define set_ADSP_ADE_DST_2_reg(data)   (*((volatile unsigned int*) ADSP_ADE_DST_2_reg)=data)
#define set_ADSP_ADE_DST_3_reg(data)   (*((volatile unsigned int*) ADSP_ADE_DST_3_reg)=data)
#define set_ADSP_ADE_DST_4_reg(data)   (*((volatile unsigned int*) ADSP_ADE_DST_4_reg)=data)
#define set_ADSP_ADE_DST_5_reg(data)   (*((volatile unsigned int*) ADSP_ADE_DST_5_reg)=data)
#define set_ADSP_ADE_DST_6_reg(data)   (*((volatile unsigned int*) ADSP_ADE_DST_6_reg)=data)
#define set_ADSP_ADE_DST_7_reg(data)   (*((volatile unsigned int*) ADSP_ADE_DST_7_reg)=data)
#define get_ADSP_ADE_DST_0_reg   (*((volatile unsigned int*) ADSP_ADE_DST_0_reg))
#define get_ADSP_ADE_DST_1_reg   (*((volatile unsigned int*) ADSP_ADE_DST_1_reg))
#define get_ADSP_ADE_DST_2_reg   (*((volatile unsigned int*) ADSP_ADE_DST_2_reg))
#define get_ADSP_ADE_DST_3_reg   (*((volatile unsigned int*) ADSP_ADE_DST_3_reg))
#define get_ADSP_ADE_DST_4_reg   (*((volatile unsigned int*) ADSP_ADE_DST_4_reg))
#define get_ADSP_ADE_DST_5_reg   (*((volatile unsigned int*) ADSP_ADE_DST_5_reg))
#define get_ADSP_ADE_DST_6_reg   (*((volatile unsigned int*) ADSP_ADE_DST_6_reg))
#define get_ADSP_ADE_DST_7_reg   (*((volatile unsigned int*) ADSP_ADE_DST_7_reg))
#define ADSP_ADE_DST_0_inst_adr                                                      "0x0008"
#define ADSP_ADE_DST_1_inst_adr                                                      "0x0009"
#define ADSP_ADE_DST_2_inst_adr                                                      "0x000A"
#define ADSP_ADE_DST_3_inst_adr                                                      "0x000B"
#define ADSP_ADE_DST_4_inst_adr                                                      "0x000C"
#define ADSP_ADE_DST_5_inst_adr                                                      "0x000D"
#define ADSP_ADE_DST_6_inst_adr                                                      "0x000E"
#define ADSP_ADE_DST_7_inst_adr                                                      "0x000F"
#define ADSP_ADE_DST_0_inst                                                          0x0008
#define ADSP_ADE_DST_1_inst                                                          0x0009
#define ADSP_ADE_DST_2_inst                                                          0x000A
#define ADSP_ADE_DST_3_inst                                                          0x000B
#define ADSP_ADE_DST_4_inst                                                          0x000C
#define ADSP_ADE_DST_5_inst                                                          0x000D
#define ADSP_ADE_DST_6_inst                                                          0x000E
#define ADSP_ADE_DST_7_inst                                                          0x000F
#define ADSP_ADE_DST_dst_shift                                                       (0)
#define ADSP_ADE_DST_dst_mask                                                        (0x7FFFFFFF)
#define ADSP_ADE_DST_dst(data)                                                       (0x7FFFFFFF&((data)<<0))
#define ADSP_ADE_DST_dst_src(data)                                                   ((0x7FFFFFFF&(data))>>0)
#define ADSP_ADE_DST_get_dst(data)                                                   ((0x7FFFFFFF&(data))>>0)


#define ADSP_ADE_SIZE_0                                                              0x18002040
#define ADSP_ADE_SIZE_1                                                              0x18002044
#define ADSP_ADE_SIZE_2                                                              0x18002048
#define ADSP_ADE_SIZE_3                                                              0x1800204C
#define ADSP_ADE_SIZE_4                                                              0x18002050
#define ADSP_ADE_SIZE_5                                                              0x18002054
#define ADSP_ADE_SIZE_6                                                              0x18002058
#define ADSP_ADE_SIZE_7                                                              0x1800205C
#define ADSP_ADE_SIZE_0_reg_addr                                                     "0xB8002040"
#define ADSP_ADE_SIZE_1_reg_addr                                                     "0xB8002044"
#define ADSP_ADE_SIZE_2_reg_addr                                                     "0xB8002048"
#define ADSP_ADE_SIZE_3_reg_addr                                                     "0xB800204C"
#define ADSP_ADE_SIZE_4_reg_addr                                                     "0xB8002050"
#define ADSP_ADE_SIZE_5_reg_addr                                                     "0xB8002054"
#define ADSP_ADE_SIZE_6_reg_addr                                                     "0xB8002058"
#define ADSP_ADE_SIZE_7_reg_addr                                                     "0xB800205C"
#define ADSP_ADE_SIZE_0_reg                                                          0xB8002040
#define ADSP_ADE_SIZE_1_reg                                                          0xB8002044
#define ADSP_ADE_SIZE_2_reg                                                          0xB8002048
#define ADSP_ADE_SIZE_3_reg                                                          0xB800204C
#define ADSP_ADE_SIZE_4_reg                                                          0xB8002050
#define ADSP_ADE_SIZE_5_reg                                                          0xB8002054
#define ADSP_ADE_SIZE_6_reg                                                          0xB8002058
#define ADSP_ADE_SIZE_7_reg                                                          0xB800205C
#define set_ADSP_ADE_SIZE_0_reg(data)   (*((volatile unsigned int*) ADSP_ADE_SIZE_0_reg)=data)
#define set_ADSP_ADE_SIZE_1_reg(data)   (*((volatile unsigned int*) ADSP_ADE_SIZE_1_reg)=data)
#define set_ADSP_ADE_SIZE_2_reg(data)   (*((volatile unsigned int*) ADSP_ADE_SIZE_2_reg)=data)
#define set_ADSP_ADE_SIZE_3_reg(data)   (*((volatile unsigned int*) ADSP_ADE_SIZE_3_reg)=data)
#define set_ADSP_ADE_SIZE_4_reg(data)   (*((volatile unsigned int*) ADSP_ADE_SIZE_4_reg)=data)
#define set_ADSP_ADE_SIZE_5_reg(data)   (*((volatile unsigned int*) ADSP_ADE_SIZE_5_reg)=data)
#define set_ADSP_ADE_SIZE_6_reg(data)   (*((volatile unsigned int*) ADSP_ADE_SIZE_6_reg)=data)
#define set_ADSP_ADE_SIZE_7_reg(data)   (*((volatile unsigned int*) ADSP_ADE_SIZE_7_reg)=data)
#define get_ADSP_ADE_SIZE_0_reg   (*((volatile unsigned int*) ADSP_ADE_SIZE_0_reg))
#define get_ADSP_ADE_SIZE_1_reg   (*((volatile unsigned int*) ADSP_ADE_SIZE_1_reg))
#define get_ADSP_ADE_SIZE_2_reg   (*((volatile unsigned int*) ADSP_ADE_SIZE_2_reg))
#define get_ADSP_ADE_SIZE_3_reg   (*((volatile unsigned int*) ADSP_ADE_SIZE_3_reg))
#define get_ADSP_ADE_SIZE_4_reg   (*((volatile unsigned int*) ADSP_ADE_SIZE_4_reg))
#define get_ADSP_ADE_SIZE_5_reg   (*((volatile unsigned int*) ADSP_ADE_SIZE_5_reg))
#define get_ADSP_ADE_SIZE_6_reg   (*((volatile unsigned int*) ADSP_ADE_SIZE_6_reg))
#define get_ADSP_ADE_SIZE_7_reg   (*((volatile unsigned int*) ADSP_ADE_SIZE_7_reg))
#define ADSP_ADE_SIZE_0_inst_adr                                                     "0x0010"
#define ADSP_ADE_SIZE_1_inst_adr                                                     "0x0011"
#define ADSP_ADE_SIZE_2_inst_adr                                                     "0x0012"
#define ADSP_ADE_SIZE_3_inst_adr                                                     "0x0013"
#define ADSP_ADE_SIZE_4_inst_adr                                                     "0x0014"
#define ADSP_ADE_SIZE_5_inst_adr                                                     "0x0015"
#define ADSP_ADE_SIZE_6_inst_adr                                                     "0x0016"
#define ADSP_ADE_SIZE_7_inst_adr                                                     "0x0017"
#define ADSP_ADE_SIZE_0_inst                                                         0x0010
#define ADSP_ADE_SIZE_1_inst                                                         0x0011
#define ADSP_ADE_SIZE_2_inst                                                         0x0012
#define ADSP_ADE_SIZE_3_inst                                                         0x0013
#define ADSP_ADE_SIZE_4_inst                                                         0x0014
#define ADSP_ADE_SIZE_5_inst                                                         0x0015
#define ADSP_ADE_SIZE_6_inst                                                         0x0016
#define ADSP_ADE_SIZE_7_inst                                                         0x0017
#define ADSP_ADE_SIZE_valid_shift                                                    (15)
#define ADSP_ADE_SIZE_valid_mask                                                     (0x00008000)
#define ADSP_ADE_SIZE_valid(data)                                                    (0x00008000&((data)<<15))
#define ADSP_ADE_SIZE_valid_src(data)                                                ((0x00008000&(data))>>15)
#define ADSP_ADE_SIZE_get_valid(data)                                                ((0x00008000&(data))>>15)
#define ADSP_ADE_SIZE_dir_shift                                                      (14)
#define ADSP_ADE_SIZE_dir_mask                                                       (0x00004000)
#define ADSP_ADE_SIZE_dir(data)                                                      (0x00004000&((data)<<14))
#define ADSP_ADE_SIZE_dir_src(data)                                                  ((0x00004000&(data))>>14)
#define ADSP_ADE_SIZE_get_dir(data)                                                  ((0x00004000&(data))>>14)
#define ADSP_ADE_SIZE_size_shift                                                     (0)
#define ADSP_ADE_SIZE_size_mask                                                      (0x00003FFF)
#define ADSP_ADE_SIZE_size(data)                                                     (0x00003FFF&((data)<<0))
#define ADSP_ADE_SIZE_size_src(data)                                                 ((0x00003FFF&(data))>>0)
#define ADSP_ADE_SIZE_get_size(data)                                                 ((0x00003FFF&(data))>>0)


#define ADSP_ADE_STATUS                                                              0x18002060
#define ADSP_ADE_STATUS_reg_addr                                                     "0xB8002060"
#define ADSP_ADE_STATUS_reg                                                          0xB8002060
#define set_ADSP_ADE_STATUS_reg(data)   (*((volatile unsigned int*) ADSP_ADE_STATUS_reg)=data)
#define get_ADSP_ADE_STATUS_reg   (*((volatile unsigned int*) ADSP_ADE_STATUS_reg))
#define ADSP_ADE_STATUS_inst_adr                                                     "0x0018"
#define ADSP_ADE_STATUS_inst                                                         0x0018
#define ADSP_ADE_STATUS_done_7_shift                                                 (7)
#define ADSP_ADE_STATUS_done_7_mask                                                  (0x00000080)
#define ADSP_ADE_STATUS_done_7(data)                                                 (0x00000080&((data)<<7))
#define ADSP_ADE_STATUS_done_7_src(data)                                             ((0x00000080&(data))>>7)
#define ADSP_ADE_STATUS_get_done_7(data)                                             ((0x00000080&(data))>>7)
#define ADSP_ADE_STATUS_done_6_shift                                                 (6)
#define ADSP_ADE_STATUS_done_6_mask                                                  (0x00000040)
#define ADSP_ADE_STATUS_done_6(data)                                                 (0x00000040&((data)<<6))
#define ADSP_ADE_STATUS_done_6_src(data)                                             ((0x00000040&(data))>>6)
#define ADSP_ADE_STATUS_get_done_6(data)                                             ((0x00000040&(data))>>6)
#define ADSP_ADE_STATUS_done_5_shift                                                 (5)
#define ADSP_ADE_STATUS_done_5_mask                                                  (0x00000020)
#define ADSP_ADE_STATUS_done_5(data)                                                 (0x00000020&((data)<<5))
#define ADSP_ADE_STATUS_done_5_src(data)                                             ((0x00000020&(data))>>5)
#define ADSP_ADE_STATUS_get_done_5(data)                                             ((0x00000020&(data))>>5)
#define ADSP_ADE_STATUS_done_4_shift                                                 (4)
#define ADSP_ADE_STATUS_done_4_mask                                                  (0x00000010)
#define ADSP_ADE_STATUS_done_4(data)                                                 (0x00000010&((data)<<4))
#define ADSP_ADE_STATUS_done_4_src(data)                                             ((0x00000010&(data))>>4)
#define ADSP_ADE_STATUS_get_done_4(data)                                             ((0x00000010&(data))>>4)
#define ADSP_ADE_STATUS_done_3_shift                                                 (3)
#define ADSP_ADE_STATUS_done_3_mask                                                  (0x00000008)
#define ADSP_ADE_STATUS_done_3(data)                                                 (0x00000008&((data)<<3))
#define ADSP_ADE_STATUS_done_3_src(data)                                             ((0x00000008&(data))>>3)
#define ADSP_ADE_STATUS_get_done_3(data)                                             ((0x00000008&(data))>>3)
#define ADSP_ADE_STATUS_done_2_shift                                                 (2)
#define ADSP_ADE_STATUS_done_2_mask                                                  (0x00000004)
#define ADSP_ADE_STATUS_done_2(data)                                                 (0x00000004&((data)<<2))
#define ADSP_ADE_STATUS_done_2_src(data)                                             ((0x00000004&(data))>>2)
#define ADSP_ADE_STATUS_get_done_2(data)                                             ((0x00000004&(data))>>2)
#define ADSP_ADE_STATUS_done_1_shift                                                 (1)
#define ADSP_ADE_STATUS_done_1_mask                                                  (0x00000002)
#define ADSP_ADE_STATUS_done_1(data)                                                 (0x00000002&((data)<<1))
#define ADSP_ADE_STATUS_done_1_src(data)                                             ((0x00000002&(data))>>1)
#define ADSP_ADE_STATUS_get_done_1(data)                                             ((0x00000002&(data))>>1)
#define ADSP_ADE_STATUS_done_0_shift                                                 (0)
#define ADSP_ADE_STATUS_done_0_mask                                                  (0x00000001)
#define ADSP_ADE_STATUS_done_0(data)                                                 (0x00000001&((data)<<0))
#define ADSP_ADE_STATUS_done_0_src(data)                                             ((0x00000001&(data))>>0)
#define ADSP_ADE_STATUS_get_done_0(data)                                             ((0x00000001&(data))>>0)


#define ADSP_ADE_CNTL                                                                0x18002064
#define ADSP_ADE_CNTL_reg_addr                                                       "0xB8002064"
#define ADSP_ADE_CNTL_reg                                                            0xB8002064
#define set_ADSP_ADE_CNTL_reg(data)   (*((volatile unsigned int*) ADSP_ADE_CNTL_reg)=data)
#define get_ADSP_ADE_CNTL_reg   (*((volatile unsigned int*) ADSP_ADE_CNTL_reg))
#define ADSP_ADE_CNTL_inst_adr                                                       "0x0019"
#define ADSP_ADE_CNTL_inst                                                           0x0019
#define ADSP_ADE_CNTL_write_en1_shift                                                (17)
#define ADSP_ADE_CNTL_write_en1_mask                                                 (0x00020000)
#define ADSP_ADE_CNTL_write_en1(data)                                                (0x00020000&((data)<<17))
#define ADSP_ADE_CNTL_write_en1_src(data)                                            ((0x00020000&(data))>>17)
#define ADSP_ADE_CNTL_get_write_en1(data)                                            ((0x00020000&(data))>>17)
#define ADSP_ADE_CNTL_max_xfer_shift                                                 (11)
#define ADSP_ADE_CNTL_max_xfer_mask                                                  (0x0001F800)
#define ADSP_ADE_CNTL_max_xfer(data)                                                 (0x0001F800&((data)<<11))
#define ADSP_ADE_CNTL_max_xfer_src(data)                                             ((0x0001F800&(data))>>11)
#define ADSP_ADE_CNTL_get_max_xfer(data)                                             ((0x0001F800&(data))>>11)
#define ADSP_ADE_CNTL_write_en3_shift                                                (5)
#define ADSP_ADE_CNTL_write_en3_mask                                                 (0x00000020)
#define ADSP_ADE_CNTL_write_en3(data)                                                (0x00000020&((data)<<5))
#define ADSP_ADE_CNTL_write_en3_src(data)                                            ((0x00000020&(data))>>5)
#define ADSP_ADE_CNTL_get_write_en3(data)                                            ((0x00000020&(data))>>5)
#define ADSP_ADE_CNTL_dmem_req_en_shift                                              (4)
#define ADSP_ADE_CNTL_dmem_req_en_mask                                               (0x00000010)
#define ADSP_ADE_CNTL_dmem_req_en(data)                                              (0x00000010&((data)<<4))
#define ADSP_ADE_CNTL_dmem_req_en_src(data)                                          ((0x00000010&(data))>>4)
#define ADSP_ADE_CNTL_get_dmem_req_en(data)                                          ((0x00000010&(data))>>4)
#define ADSP_ADE_CNTL_write_en4_shift                                                (3)
#define ADSP_ADE_CNTL_write_en4_mask                                                 (0x00000008)
#define ADSP_ADE_CNTL_write_en4(data)                                                (0x00000008&((data)<<3))
#define ADSP_ADE_CNTL_write_en4_src(data)                                            ((0x00000008&(data))>>3)
#define ADSP_ADE_CNTL_get_write_en4(data)                                            ((0x00000008&(data))>>3)
#define ADSP_ADE_CNTL_stop_shift                                                     (2)
#define ADSP_ADE_CNTL_stop_mask                                                      (0x00000004)
#define ADSP_ADE_CNTL_stop(data)                                                     (0x00000004&((data)<<2))
#define ADSP_ADE_CNTL_stop_src(data)                                                 ((0x00000004&(data))>>2)
#define ADSP_ADE_CNTL_get_stop(data)                                                 ((0x00000004&(data))>>2)
#define ADSP_ADE_CNTL_write_en5_shift                                                (1)
#define ADSP_ADE_CNTL_write_en5_mask                                                 (0x00000002)
#define ADSP_ADE_CNTL_write_en5(data)                                                (0x00000002&((data)<<1))
#define ADSP_ADE_CNTL_write_en5_src(data)                                            ((0x00000002&(data))>>1)
#define ADSP_ADE_CNTL_get_write_en5(data)                                            ((0x00000002&(data))>>1)
#define ADSP_ADE_CNTL_go_shift                                                       (0)
#define ADSP_ADE_CNTL_go_mask                                                        (0x00000001)
#define ADSP_ADE_CNTL_go(data)                                                       (0x00000001&((data)<<0))
#define ADSP_ADE_CNTL_go_src(data)                                                   ((0x00000001&(data))>>0)
#define ADSP_ADE_CNTL_get_go(data)                                                   ((0x00000001&(data))>>0)


#define ADSP_ADE_INT                                                                 0x18002068
#define ADSP_ADE_INT_reg_addr                                                        "0xB8002068"
#define ADSP_ADE_INT_reg                                                             0xB8002068
#define set_ADSP_ADE_INT_reg(data)   (*((volatile unsigned int*) ADSP_ADE_INT_reg)=data)
#define get_ADSP_ADE_INT_reg   (*((volatile unsigned int*) ADSP_ADE_INT_reg))
#define ADSP_ADE_INT_inst_adr                                                        "0x001A"
#define ADSP_ADE_INT_inst                                                            0x001A
#define ADSP_ADE_INT_int_done_shift                                                  (0)
#define ADSP_ADE_INT_int_done_mask                                                   (0x00000001)
#define ADSP_ADE_INT_int_done(data)                                                  (0x00000001&((data)<<0))
#define ADSP_ADE_INT_int_done_src(data)                                              ((0x00000001&(data))>>0)
#define ADSP_ADE_INT_get_int_done(data)                                              ((0x00000001&(data))>>0)


#define ADSP_ADE_INT_EN                                                              0x1800206c
#define ADSP_ADE_INT_EN_reg_addr                                                     "0xB800206C"
#define ADSP_ADE_INT_EN_reg                                                          0xB800206C
#define set_ADSP_ADE_INT_EN_reg(data)   (*((volatile unsigned int*) ADSP_ADE_INT_EN_reg)=data)
#define get_ADSP_ADE_INT_EN_reg   (*((volatile unsigned int*) ADSP_ADE_INT_EN_reg))
#define ADSP_ADE_INT_EN_inst_adr                                                     "0x001B"
#define ADSP_ADE_INT_EN_inst                                                         0x001B
#define ADSP_ADE_INT_EN_int_done_en_shift                                            (0)
#define ADSP_ADE_INT_EN_int_done_en_mask                                             (0x00000001)
#define ADSP_ADE_INT_EN_int_done_en(data)                                            (0x00000001&((data)<<0))
#define ADSP_ADE_INT_EN_int_done_en_src(data)                                        ((0x00000001&(data))>>0)
#define ADSP_ADE_INT_EN_get_int_done_en(data)                                        ((0x00000001&(data))>>0)


#define ADSP_AEE_THLD                                                                0x18002078
#define ADSP_AEE_THLD_reg_addr                                                       "0xB8002078"
#define ADSP_AEE_THLD_reg                                                            0xB8002078
#define set_ADSP_AEE_THLD_reg(data)   (*((volatile unsigned int*) ADSP_AEE_THLD_reg)=data)
#define get_ADSP_AEE_THLD_reg   (*((volatile unsigned int*) ADSP_AEE_THLD_reg))
#define ADSP_AEE_THLD_inst_adr                                                       "0x001E"
#define ADSP_AEE_THLD_inst                                                           0x001E
#define ADSP_AEE_THLD_max_xfer_shift                                                 (13)
#define ADSP_AEE_THLD_max_xfer_mask                                                  (0x0007E000)
#define ADSP_AEE_THLD_max_xfer(data)                                                 (0x0007E000&((data)<<13))
#define ADSP_AEE_THLD_max_xfer_src(data)                                             ((0x0007E000&(data))>>13)
#define ADSP_AEE_THLD_get_max_xfer(data)                                             ((0x0007E000&(data))>>13)
#define ADSP_AEE_THLD_threshold_shift                                                (3)
#define ADSP_AEE_THLD_threshold_mask                                                 (0x000001F8)
#define ADSP_AEE_THLD_threshold(data)                                                (0x000001F8&((data)<<3))
#define ADSP_AEE_THLD_threshold_src(data)                                            ((0x000001F8&(data))>>3)
#define ADSP_AEE_THLD_get_threshold(data)                                            ((0x000001F8&(data))>>3)


#define ADSP_AEE_VBIT_CNT                                                            0x1800207c
#define ADSP_AEE_VBIT_CNT_reg_addr                                                   "0xB800207C"
#define ADSP_AEE_VBIT_CNT_reg                                                        0xB800207C
#define set_ADSP_AEE_VBIT_CNT_reg(data)   (*((volatile unsigned int*) ADSP_AEE_VBIT_CNT_reg)=data)
#define get_ADSP_AEE_VBIT_CNT_reg   (*((volatile unsigned int*) ADSP_AEE_VBIT_CNT_reg))
#define ADSP_AEE_VBIT_CNT_inst_adr                                                   "0x001F"
#define ADSP_AEE_VBIT_CNT_inst                                                       0x001F
#define ADSP_AEE_VBIT_CNT_bit_cnt_shift                                              (0)
#define ADSP_AEE_VBIT_CNT_bit_cnt_mask                                               (0x00003FFF)
#define ADSP_AEE_VBIT_CNT_bit_cnt(data)                                              (0x00003FFF&((data)<<0))
#define ADSP_AEE_VBIT_CNT_bit_cnt_src(data)                                          ((0x00003FFF&(data))>>0)
#define ADSP_AEE_VBIT_CNT_get_bit_cnt(data)                                          ((0x00003FFF&(data))>>0)


#define ADSP_AEE_USED_CNT                                                            0x18002080
#define ADSP_AEE_USED_CNT_reg_addr                                                   "0xB8002080"
#define ADSP_AEE_USED_CNT_reg                                                        0xB8002080
#define set_ADSP_AEE_USED_CNT_reg(data)   (*((volatile unsigned int*) ADSP_AEE_USED_CNT_reg)=data)
#define get_ADSP_AEE_USED_CNT_reg   (*((volatile unsigned int*) ADSP_AEE_USED_CNT_reg))
#define ADSP_AEE_USED_CNT_inst_adr                                                   "0x0020"
#define ADSP_AEE_USED_CNT_inst                                                       0x0020
#define ADSP_AEE_USED_CNT_used_cnt_shift                                             (0)
#define ADSP_AEE_USED_CNT_used_cnt_mask                                              (0xFFFFFFFF)
#define ADSP_AEE_USED_CNT_used_cnt(data)                                             (0xFFFFFFFF&((data)<<0))
#define ADSP_AEE_USED_CNT_used_cnt_src(data)                                         ((0xFFFFFFFF&(data))>>0)
#define ADSP_AEE_USED_CNT_get_used_cnt(data)                                         ((0xFFFFFFFF&(data))>>0)


#define ADSP_AEE_CTRL                                                                0x18002084
#define ADSP_AEE_CTRL_reg_addr                                                       "0xB8002084"
#define ADSP_AEE_CTRL_reg                                                            0xB8002084
#define set_ADSP_AEE_CTRL_reg(data)   (*((volatile unsigned int*) ADSP_AEE_CTRL_reg)=data)
#define get_ADSP_AEE_CTRL_reg   (*((volatile unsigned int*) ADSP_AEE_CTRL_reg))
#define ADSP_AEE_CTRL_inst_adr                                                       "0x0021"
#define ADSP_AEE_CTRL_inst                                                           0x0021
#define ADSP_AEE_CTRL_write_en1_shift                                                (4)
#define ADSP_AEE_CTRL_write_en1_mask                                                 (0x00000010)
#define ADSP_AEE_CTRL_write_en1(data)                                                (0x00000010&((data)<<4))
#define ADSP_AEE_CTRL_write_en1_src(data)                                            ((0x00000010&(data))>>4)
#define ADSP_AEE_CTRL_get_write_en1(data)                                            ((0x00000010&(data))>>4)
#define ADSP_AEE_CTRL_stop_shift                                                     (3)
#define ADSP_AEE_CTRL_stop_mask                                                      (0x00000008)
#define ADSP_AEE_CTRL_stop(data)                                                     (0x00000008&((data)<<3))
#define ADSP_AEE_CTRL_stop_src(data)                                                 ((0x00000008&(data))>>3)
#define ADSP_AEE_CTRL_get_stop(data)                                                 ((0x00000008&(data))>>3)
#define ADSP_AEE_CTRL_write_en2_shift                                                (2)
#define ADSP_AEE_CTRL_write_en2_mask                                                 (0x00000004)
#define ADSP_AEE_CTRL_write_en2(data)                                                (0x00000004&((data)<<2))
#define ADSP_AEE_CTRL_write_en2_src(data)                                            ((0x00000004&(data))>>2)
#define ADSP_AEE_CTRL_get_write_en2(data)                                            ((0x00000004&(data))>>2)
#define ADSP_AEE_CTRL_dir_shift                                                      (1)
#define ADSP_AEE_CTRL_dir_mask                                                       (0x00000002)
#define ADSP_AEE_CTRL_dir(data)                                                      (0x00000002&((data)<<1))
#define ADSP_AEE_CTRL_dir_src(data)                                                  ((0x00000002&(data))>>1)
#define ADSP_AEE_CTRL_get_dir(data)                                                  ((0x00000002&(data))>>1)
#define ADSP_AEE_CTRL_go_shift                                                       (0)
#define ADSP_AEE_CTRL_go_mask                                                        (0x00000001)
#define ADSP_AEE_CTRL_go(data)                                                       (0x00000001&((data)<<0))
#define ADSP_AEE_CTRL_go_src(data)                                                   ((0x00000001&(data))>>0)
#define ADSP_AEE_CTRL_get_go(data)                                                   ((0x00000001&(data))>>0)


#define ADSP_AEE_INT                                                                 0x18002088
#define ADSP_AEE_INT_reg_addr                                                        "0xB8002088"
#define ADSP_AEE_INT_reg                                                             0xB8002088
#define set_ADSP_AEE_INT_reg(data)   (*((volatile unsigned int*) ADSP_AEE_INT_reg)=data)
#define get_ADSP_AEE_INT_reg   (*((volatile unsigned int*) ADSP_AEE_INT_reg))
#define ADSP_AEE_INT_inst_adr                                                        "0x0022"
#define ADSP_AEE_INT_inst                                                            0x0022
#define ADSP_AEE_INT_int4_shift                                                      (4)
#define ADSP_AEE_INT_int4_mask                                                       (0x00000010)
#define ADSP_AEE_INT_int4(data)                                                      (0x00000010&((data)<<4))
#define ADSP_AEE_INT_int4_src(data)                                                  ((0x00000010&(data))>>4)
#define ADSP_AEE_INT_get_int4(data)                                                  ((0x00000010&(data))>>4)
#define ADSP_AEE_INT_int3_shift                                                      (3)
#define ADSP_AEE_INT_int3_mask                                                       (0x00000008)
#define ADSP_AEE_INT_int3(data)                                                      (0x00000008&((data)<<3))
#define ADSP_AEE_INT_int3_src(data)                                                  ((0x00000008&(data))>>3)
#define ADSP_AEE_INT_get_int3(data)                                                  ((0x00000008&(data))>>3)
#define ADSP_AEE_INT_int2_shift                                                      (2)
#define ADSP_AEE_INT_int2_mask                                                       (0x00000004)
#define ADSP_AEE_INT_int2(data)                                                      (0x00000004&((data)<<2))
#define ADSP_AEE_INT_int2_src(data)                                                  ((0x00000004&(data))>>2)
#define ADSP_AEE_INT_get_int2(data)                                                  ((0x00000004&(data))>>2)
#define ADSP_AEE_INT_int1_shift                                                      (1)
#define ADSP_AEE_INT_int1_mask                                                       (0x00000002)
#define ADSP_AEE_INT_int1(data)                                                      (0x00000002&((data)<<1))
#define ADSP_AEE_INT_int1_src(data)                                                  ((0x00000002&(data))>>1)
#define ADSP_AEE_INT_get_int1(data)                                                  ((0x00000002&(data))>>1)
#define ADSP_AEE_INT_write_data_shift                                                (0)
#define ADSP_AEE_INT_write_data_mask                                                 (0x00000001)
#define ADSP_AEE_INT_write_data(data)                                                (0x00000001&((data)<<0))
#define ADSP_AEE_INT_write_data_src(data)                                            ((0x00000001&(data))>>0)
#define ADSP_AEE_INT_get_write_data(data)                                            ((0x00000001&(data))>>0)


#define ADSP_AEE_INT_EN                                                              0x1800208c
#define ADSP_AEE_INT_EN_reg_addr                                                     "0xB800208C"
#define ADSP_AEE_INT_EN_reg                                                          0xB800208C
#define set_ADSP_AEE_INT_EN_reg(data)   (*((volatile unsigned int*) ADSP_AEE_INT_EN_reg)=data)
#define get_ADSP_AEE_INT_EN_reg   (*((volatile unsigned int*) ADSP_AEE_INT_EN_reg))
#define ADSP_AEE_INT_EN_inst_adr                                                     "0x0023"
#define ADSP_AEE_INT_EN_inst                                                         0x0023
#define ADSP_AEE_INT_EN_int4_en_shift                                                (4)
#define ADSP_AEE_INT_EN_int4_en_mask                                                 (0x00000010)
#define ADSP_AEE_INT_EN_int4_en(data)                                                (0x00000010&((data)<<4))
#define ADSP_AEE_INT_EN_int4_en_src(data)                                            ((0x00000010&(data))>>4)
#define ADSP_AEE_INT_EN_get_int4_en(data)                                            ((0x00000010&(data))>>4)
#define ADSP_AEE_INT_EN_int3_en_shift                                                (3)
#define ADSP_AEE_INT_EN_int3_en_mask                                                 (0x00000008)
#define ADSP_AEE_INT_EN_int3_en(data)                                                (0x00000008&((data)<<3))
#define ADSP_AEE_INT_EN_int3_en_src(data)                                            ((0x00000008&(data))>>3)
#define ADSP_AEE_INT_EN_get_int3_en(data)                                            ((0x00000008&(data))>>3)
#define ADSP_AEE_INT_EN_int2_en_shift                                                (2)
#define ADSP_AEE_INT_EN_int2_en_mask                                                 (0x00000004)
#define ADSP_AEE_INT_EN_int2_en(data)                                                (0x00000004&((data)<<2))
#define ADSP_AEE_INT_EN_int2_en_src(data)                                            ((0x00000004&(data))>>2)
#define ADSP_AEE_INT_EN_get_int2_en(data)                                            ((0x00000004&(data))>>2)
#define ADSP_AEE_INT_EN_int1_en_shift                                                (1)
#define ADSP_AEE_INT_EN_int1_en_mask                                                 (0x00000002)
#define ADSP_AEE_INT_EN_int1_en(data)                                                (0x00000002&((data)<<1))
#define ADSP_AEE_INT_EN_int1_en_src(data)                                            ((0x00000002&(data))>>1)
#define ADSP_AEE_INT_EN_get_int1_en(data)                                            ((0x00000002&(data))>>1)
#define ADSP_AEE_INT_EN_write_data_shift                                             (0)
#define ADSP_AEE_INT_EN_write_data_mask                                              (0x00000001)
#define ADSP_AEE_INT_EN_write_data(data)                                             (0x00000001&((data)<<0))
#define ADSP_AEE_INT_EN_write_data_src(data)                                         ((0x00000001&(data))>>0)
#define ADSP_AEE_INT_EN_get_write_data(data)                                         ((0x00000001&(data))>>0)


#define ADSP_AEE_RING_LIMIT                                                          0x18002094
#define ADSP_AEE_RING_LIMIT_reg_addr                                                 "0xB8002094"
#define ADSP_AEE_RING_LIMIT_reg                                                      0xB8002094
#define set_ADSP_AEE_RING_LIMIT_reg(data)   (*((volatile unsigned int*) ADSP_AEE_RING_LIMIT_reg)=data)
#define get_ADSP_AEE_RING_LIMIT_reg   (*((volatile unsigned int*) ADSP_AEE_RING_LIMIT_reg))
#define ADSP_AEE_RING_LIMIT_inst_adr                                                 "0x0025"
#define ADSP_AEE_RING_LIMIT_inst                                                     0x0025
#define ADSP_AEE_RING_LIMIT_ring_limit_shift                                         (3)
#define ADSP_AEE_RING_LIMIT_ring_limit_mask                                          (0x7FFFFFF8)
#define ADSP_AEE_RING_LIMIT_ring_limit(data)                                         (0x7FFFFFF8&((data)<<3))
#define ADSP_AEE_RING_LIMIT_ring_limit_src(data)                                     ((0x7FFFFFF8&(data))>>3)
#define ADSP_AEE_RING_LIMIT_get_ring_limit(data)                                     ((0x7FFFFFF8&(data))>>3)


#define ADSP_AEE_RING_BASE                                                           0x18002098
#define ADSP_AEE_RING_BASE_reg_addr                                                  "0xB8002098"
#define ADSP_AEE_RING_BASE_reg                                                       0xB8002098
#define set_ADSP_AEE_RING_BASE_reg(data)   (*((volatile unsigned int*) ADSP_AEE_RING_BASE_reg)=data)
#define get_ADSP_AEE_RING_BASE_reg   (*((volatile unsigned int*) ADSP_AEE_RING_BASE_reg))
#define ADSP_AEE_RING_BASE_inst_adr                                                  "0x0026"
#define ADSP_AEE_RING_BASE_inst                                                      0x0026
#define ADSP_AEE_RING_BASE_ring_base_shift                                           (3)
#define ADSP_AEE_RING_BASE_ring_base_mask                                            (0x7FFFFFF8)
#define ADSP_AEE_RING_BASE_ring_base(data)                                           (0x7FFFFFF8&((data)<<3))
#define ADSP_AEE_RING_BASE_ring_base_src(data)                                       ((0x7FFFFFF8&(data))>>3)
#define ADSP_AEE_RING_BASE_get_ring_base(data)                                       ((0x7FFFFFF8&(data))>>3)


#define ADSP_AEE_RING_RP                                                             0x1800209c
#define ADSP_AEE_RING_RP_reg_addr                                                    "0xB800209C"
#define ADSP_AEE_RING_RP_reg                                                         0xB800209C
#define set_ADSP_AEE_RING_RP_reg(data)   (*((volatile unsigned int*) ADSP_AEE_RING_RP_reg)=data)
#define get_ADSP_AEE_RING_RP_reg   (*((volatile unsigned int*) ADSP_AEE_RING_RP_reg))
#define ADSP_AEE_RING_RP_inst_adr                                                    "0x0027"
#define ADSP_AEE_RING_RP_inst                                                        0x0027
#define ADSP_AEE_RING_RP_ring_rp_shift                                               (0)
#define ADSP_AEE_RING_RP_ring_rp_mask                                                (0x7FFFFFFF)
#define ADSP_AEE_RING_RP_ring_rp(data)                                               (0x7FFFFFFF&((data)<<0))
#define ADSP_AEE_RING_RP_ring_rp_src(data)                                           ((0x7FFFFFFF&(data))>>0)
#define ADSP_AEE_RING_RP_get_ring_rp(data)                                           ((0x7FFFFFFF&(data))>>0)


#define ADSP_AEE_RING_WP                                                             0x180020a0
#define ADSP_AEE_RING_WP_reg_addr                                                    "0xB80020A0"
#define ADSP_AEE_RING_WP_reg                                                         0xB80020A0
#define set_ADSP_AEE_RING_WP_reg(data)   (*((volatile unsigned int*) ADSP_AEE_RING_WP_reg)=data)
#define get_ADSP_AEE_RING_WP_reg   (*((volatile unsigned int*) ADSP_AEE_RING_WP_reg))
#define ADSP_AEE_RING_WP_inst_adr                                                    "0x0028"
#define ADSP_AEE_RING_WP_inst                                                        0x0028
#define ADSP_AEE_RING_WP_ring_wp_shift                                               (0)
#define ADSP_AEE_RING_WP_ring_wp_mask                                                (0x7FFFFFFF)
#define ADSP_AEE_RING_WP_ring_wp(data)                                               (0x7FFFFFFF&((data)<<0))
#define ADSP_AEE_RING_WP_ring_wp_src(data)                                           ((0x7FFFFFFF&(data))>>0)
#define ADSP_AEE_RING_WP_get_ring_wp(data)                                           ((0x7FFFFFFF&(data))>>0)


#define ADSP_AEE_RING_CP                                                             0x180020a4
#define ADSP_AEE_RING_CP_reg_addr                                                    "0xB80020A4"
#define ADSP_AEE_RING_CP_reg                                                         0xB80020A4
#define set_ADSP_AEE_RING_CP_reg(data)   (*((volatile unsigned int*) ADSP_AEE_RING_CP_reg)=data)
#define get_ADSP_AEE_RING_CP_reg   (*((volatile unsigned int*) ADSP_AEE_RING_CP_reg))
#define ADSP_AEE_RING_CP_inst_adr                                                    "0x0029"
#define ADSP_AEE_RING_CP_inst                                                        0x0029
#define ADSP_AEE_RING_CP_ring_cp_shift                                               (0)
#define ADSP_AEE_RING_CP_ring_cp_mask                                                (0x7FFFFFFF)
#define ADSP_AEE_RING_CP_ring_cp(data)                                               (0x7FFFFFFF&((data)<<0))
#define ADSP_AEE_RING_CP_ring_cp_src(data)                                           ((0x7FFFFFFF&(data))>>0)
#define ADSP_AEE_RING_CP_get_ring_cp(data)                                           ((0x7FFFFFFF&(data))>>0)


#define ADSP_AEE_SEARCH_LIMIT                                                        0x180020c8
#define ADSP_AEE_SEARCH_LIMIT_reg_addr                                               "0xB80020C8"
#define ADSP_AEE_SEARCH_LIMIT_reg                                                    0xB80020C8
#define set_ADSP_AEE_SEARCH_LIMIT_reg(data)   (*((volatile unsigned int*) ADSP_AEE_SEARCH_LIMIT_reg)=data)
#define get_ADSP_AEE_SEARCH_LIMIT_reg   (*((volatile unsigned int*) ADSP_AEE_SEARCH_LIMIT_reg))
#define ADSP_AEE_SEARCH_LIMIT_inst_adr                                               "0x0032"
#define ADSP_AEE_SEARCH_LIMIT_inst                                                   0x0032
#define ADSP_AEE_SEARCH_LIMIT_limit_shift                                            (0)
#define ADSP_AEE_SEARCH_LIMIT_limit_mask                                             (0x0000FFFF)
#define ADSP_AEE_SEARCH_LIMIT_limit(data)                                            (0x0000FFFF&((data)<<0))
#define ADSP_AEE_SEARCH_LIMIT_limit_src(data)                                        ((0x0000FFFF&(data))>>0)
#define ADSP_AEE_SEARCH_LIMIT_get_limit(data)                                        ((0x0000FFFF&(data))>>0)


#define ADSP_AEE_CRC_INIT                                                            0x180020ac
#define ADSP_AEE_CRC_INIT_reg_addr                                                   "0xB80020AC"
#define ADSP_AEE_CRC_INIT_reg                                                        0xB80020AC
#define set_ADSP_AEE_CRC_INIT_reg(data)   (*((volatile unsigned int*) ADSP_AEE_CRC_INIT_reg)=data)
#define get_ADSP_AEE_CRC_INIT_reg   (*((volatile unsigned int*) ADSP_AEE_CRC_INIT_reg))
#define ADSP_AEE_CRC_INIT_inst_adr                                                   "0x002B"
#define ADSP_AEE_CRC_INIT_inst                                                       0x002B
#define ADSP_AEE_CRC_INIT_crc_init_shift                                             (0)
#define ADSP_AEE_CRC_INIT_crc_init_mask                                              (0x0000FFFF)
#define ADSP_AEE_CRC_INIT_crc_init(data)                                             (0x0000FFFF&((data)<<0))
#define ADSP_AEE_CRC_INIT_crc_init_src(data)                                         ((0x0000FFFF&(data))>>0)
#define ADSP_AEE_CRC_INIT_get_crc_init(data)                                         ((0x0000FFFF&(data))>>0)


#define ADSP_AEE_CRC_CNTL                                                            0x180020b0
#define ADSP_AEE_CRC_CNTL_reg_addr                                                   "0xB80020B0"
#define ADSP_AEE_CRC_CNTL_reg                                                        0xB80020B0
#define set_ADSP_AEE_CRC_CNTL_reg(data)   (*((volatile unsigned int*) ADSP_AEE_CRC_CNTL_reg)=data)
#define get_ADSP_AEE_CRC_CNTL_reg   (*((volatile unsigned int*) ADSP_AEE_CRC_CNTL_reg))
#define ADSP_AEE_CRC_CNTL_inst_adr                                                   "0x002C"
#define ADSP_AEE_CRC_CNTL_inst                                                       0x002C
#define ADSP_AEE_CRC_CNTL_write_en4_shift                                            (7)
#define ADSP_AEE_CRC_CNTL_write_en4_mask                                             (0x00000080)
#define ADSP_AEE_CRC_CNTL_write_en4(data)                                            (0x00000080&((data)<<7))
#define ADSP_AEE_CRC_CNTL_write_en4_src(data)                                        ((0x00000080&(data))>>7)
#define ADSP_AEE_CRC_CNTL_get_write_en4(data)                                        ((0x00000080&(data))>>7)
#define ADSP_AEE_CRC_CNTL_crc_mode_shift                                             (6)
#define ADSP_AEE_CRC_CNTL_crc_mode_mask                                              (0x00000040)
#define ADSP_AEE_CRC_CNTL_crc_mode(data)                                             (0x00000040&((data)<<6))
#define ADSP_AEE_CRC_CNTL_crc_mode_src(data)                                         ((0x00000040&(data))>>6)
#define ADSP_AEE_CRC_CNTL_get_crc_mode(data)                                         ((0x00000040&(data))>>6)
#define ADSP_AEE_CRC_CNTL_write_en1_shift                                            (5)
#define ADSP_AEE_CRC_CNTL_write_en1_mask                                             (0x00000020)
#define ADSP_AEE_CRC_CNTL_write_en1(data)                                            (0x00000020&((data)<<5))
#define ADSP_AEE_CRC_CNTL_write_en1_src(data)                                        ((0x00000020&(data))>>5)
#define ADSP_AEE_CRC_CNTL_get_write_en1(data)                                        ((0x00000020&(data))>>5)
#define ADSP_AEE_CRC_CNTL_crc_reset_shift                                            (4)
#define ADSP_AEE_CRC_CNTL_crc_reset_mask                                             (0x00000010)
#define ADSP_AEE_CRC_CNTL_crc_reset(data)                                            (0x00000010&((data)<<4))
#define ADSP_AEE_CRC_CNTL_crc_reset_src(data)                                        ((0x00000010&(data))>>4)
#define ADSP_AEE_CRC_CNTL_get_crc_reset(data)                                        ((0x00000010&(data))>>4)
#define ADSP_AEE_CRC_CNTL_write_en2_shift                                            (3)
#define ADSP_AEE_CRC_CNTL_write_en2_mask                                             (0x00000008)
#define ADSP_AEE_CRC_CNTL_write_en2(data)                                            (0x00000008&((data)<<3))
#define ADSP_AEE_CRC_CNTL_write_en2_src(data)                                        ((0x00000008&(data))>>3)
#define ADSP_AEE_CRC_CNTL_get_write_en2(data)                                        ((0x00000008&(data))>>3)
#define ADSP_AEE_CRC_CNTL_crc_cont_shift                                             (2)
#define ADSP_AEE_CRC_CNTL_crc_cont_mask                                              (0x00000004)
#define ADSP_AEE_CRC_CNTL_crc_cont(data)                                             (0x00000004&((data)<<2))
#define ADSP_AEE_CRC_CNTL_crc_cont_src(data)                                         ((0x00000004&(data))>>2)
#define ADSP_AEE_CRC_CNTL_get_crc_cont(data)                                         ((0x00000004&(data))>>2)
#define ADSP_AEE_CRC_CNTL_write_en3_shift                                            (1)
#define ADSP_AEE_CRC_CNTL_write_en3_mask                                             (0x00000002)
#define ADSP_AEE_CRC_CNTL_write_en3(data)                                            (0x00000002&((data)<<1))
#define ADSP_AEE_CRC_CNTL_write_en3_src(data)                                        ((0x00000002&(data))>>1)
#define ADSP_AEE_CRC_CNTL_get_write_en3(data)                                        ((0x00000002&(data))>>1)
#define ADSP_AEE_CRC_CNTL_crc_on_shift                                               (0)
#define ADSP_AEE_CRC_CNTL_crc_on_mask                                                (0x00000001)
#define ADSP_AEE_CRC_CNTL_crc_on(data)                                               (0x00000001&((data)<<0))
#define ADSP_AEE_CRC_CNTL_crc_on_src(data)                                           ((0x00000001&(data))>>0)
#define ADSP_AEE_CRC_CNTL_get_crc_on(data)                                           ((0x00000001&(data))>>0)


#define ADSP_AEE_CRC_LENGTH                                                          0x180020b4
#define ADSP_AEE_CRC_LENGTH_reg_addr                                                 "0xB80020B4"
#define ADSP_AEE_CRC_LENGTH_reg                                                      0xB80020B4
#define set_ADSP_AEE_CRC_LENGTH_reg(data)   (*((volatile unsigned int*) ADSP_AEE_CRC_LENGTH_reg)=data)
#define get_ADSP_AEE_CRC_LENGTH_reg   (*((volatile unsigned int*) ADSP_AEE_CRC_LENGTH_reg))
#define ADSP_AEE_CRC_LENGTH_inst_adr                                                 "0x002D"
#define ADSP_AEE_CRC_LENGTH_inst                                                     0x002D
#define ADSP_AEE_CRC_LENGTH_crc_length_shift                                         (0)
#define ADSP_AEE_CRC_LENGTH_crc_length_mask                                          (0x0000FFFF)
#define ADSP_AEE_CRC_LENGTH_crc_length(data)                                         (0x0000FFFF&((data)<<0))
#define ADSP_AEE_CRC_LENGTH_crc_length_src(data)                                     ((0x0000FFFF&(data))>>0)
#define ADSP_AEE_CRC_LENGTH_get_crc_length(data)                                     ((0x0000FFFF&(data))>>0)


#define ADSP_AEE_CRC_RESULT                                                          0x180020b8
#define ADSP_AEE_CRC_RESULT_reg_addr                                                 "0xB80020B8"
#define ADSP_AEE_CRC_RESULT_reg                                                      0xB80020B8
#define set_ADSP_AEE_CRC_RESULT_reg(data)   (*((volatile unsigned int*) ADSP_AEE_CRC_RESULT_reg)=data)
#define get_ADSP_AEE_CRC_RESULT_reg   (*((volatile unsigned int*) ADSP_AEE_CRC_RESULT_reg))
#define ADSP_AEE_CRC_RESULT_inst_adr                                                 "0x002E"
#define ADSP_AEE_CRC_RESULT_inst                                                     0x002E
#define ADSP_AEE_CRC_RESULT_crc_result_shift                                         (0)
#define ADSP_AEE_CRC_RESULT_crc_result_mask                                          (0x0000FFFF)
#define ADSP_AEE_CRC_RESULT_crc_result(data)                                         (0x0000FFFF&((data)<<0))
#define ADSP_AEE_CRC_RESULT_crc_result_src(data)                                     ((0x0000FFFF&(data))>>0)
#define ADSP_AEE_CRC_RESULT_get_crc_result(data)                                     ((0x0000FFFF&(data))>>0)


#define ADSP_AEE_BIT_CNT                                                             0x180020bc
#define ADSP_AEE_BIT_CNT_reg_addr                                                    "0xB80020BC"
#define ADSP_AEE_BIT_CNT_reg                                                         0xB80020BC
#define set_ADSP_AEE_BIT_CNT_reg(data)   (*((volatile unsigned int*) ADSP_AEE_BIT_CNT_reg)=data)
#define get_ADSP_AEE_BIT_CNT_reg   (*((volatile unsigned int*) ADSP_AEE_BIT_CNT_reg))
#define ADSP_AEE_BIT_CNT_inst_adr                                                    "0x002F"
#define ADSP_AEE_BIT_CNT_inst                                                        0x002F
#define ADSP_AEE_BIT_CNT_crc_bit_cnt_shift                                           (0)
#define ADSP_AEE_BIT_CNT_crc_bit_cnt_mask                                            (0xFFFFFFFF)
#define ADSP_AEE_BIT_CNT_crc_bit_cnt(data)                                           (0xFFFFFFFF&((data)<<0))
#define ADSP_AEE_BIT_CNT_crc_bit_cnt_src(data)                                       ((0xFFFFFFFF&(data))>>0)
#define ADSP_AEE_BIT_CNT_get_crc_bit_cnt(data)                                       ((0xFFFFFFFF&(data))>>0)


#define ADSP_AEE_CRC_ACC                                                             0x180020c0
#define ADSP_AEE_CRC_ACC_reg_addr                                                    "0xB80020C0"
#define ADSP_AEE_CRC_ACC_reg                                                         0xB80020C0
#define set_ADSP_AEE_CRC_ACC_reg(data)   (*((volatile unsigned int*) ADSP_AEE_CRC_ACC_reg)=data)
#define get_ADSP_AEE_CRC_ACC_reg   (*((volatile unsigned int*) ADSP_AEE_CRC_ACC_reg))
#define ADSP_AEE_CRC_ACC_inst_adr                                                    "0x0030"
#define ADSP_AEE_CRC_ACC_inst                                                        0x0030
#define ADSP_AEE_CRC_ACC_acc_shift                                                   (0)
#define ADSP_AEE_CRC_ACC_acc_mask                                                    (0x0000FFFF)
#define ADSP_AEE_CRC_ACC_acc(data)                                                   (0x0000FFFF&((data)<<0))
#define ADSP_AEE_CRC_ACC_acc_src(data)                                               ((0x0000FFFF&(data))>>0)
#define ADSP_AEE_CRC_ACC_get_acc(data)                                               ((0x0000FFFF&(data))>>0)


#define ADSP_AEE_CRC_ACC_CNT                                                         0x180020c4
#define ADSP_AEE_CRC_ACC_CNT_reg_addr                                                "0xB80020C4"
#define ADSP_AEE_CRC_ACC_CNT_reg                                                     0xB80020C4
#define set_ADSP_AEE_CRC_ACC_CNT_reg(data)   (*((volatile unsigned int*) ADSP_AEE_CRC_ACC_CNT_reg)=data)
#define get_ADSP_AEE_CRC_ACC_CNT_reg   (*((volatile unsigned int*) ADSP_AEE_CRC_ACC_CNT_reg))
#define ADSP_AEE_CRC_ACC_CNT_inst_adr                                                "0x0031"
#define ADSP_AEE_CRC_ACC_CNT_inst                                                    0x0031
#define ADSP_AEE_CRC_ACC_CNT_acc_cnt_shift                                           (0)
#define ADSP_AEE_CRC_ACC_CNT_acc_cnt_mask                                            (0x0000000F)
#define ADSP_AEE_CRC_ACC_CNT_acc_cnt(data)                                           (0x0000000F&((data)<<0))
#define ADSP_AEE_CRC_ACC_CNT_acc_cnt_src(data)                                       ((0x0000000F&(data))>>0)
#define ADSP_AEE_CRC_ACC_CNT_get_acc_cnt(data)                                       ((0x0000000F&(data))>>0)


#define AEE_OGG_MODE                                                                 0x180020d0
#define AEE_OGG_MODE_reg_addr                                                        "0xB80020D0"
#define AEE_OGG_MODE_reg                                                             0xB80020D0
#define set_AEE_OGG_MODE_reg(data)   (*((volatile unsigned int*) AEE_OGG_MODE_reg)=data)
#define get_AEE_OGG_MODE_reg   (*((volatile unsigned int*) AEE_OGG_MODE_reg))
#define AEE_OGG_MODE_inst_adr                                                        "0x0034"
#define AEE_OGG_MODE_inst                                                            0x0034
#define AEE_OGG_MODE_aee_audio_mode_shift                                            (0)
#define AEE_OGG_MODE_aee_audio_mode_mask                                             (0x00000003)
#define AEE_OGG_MODE_aee_audio_mode(data)                                            (0x00000003&((data)<<0))
#define AEE_OGG_MODE_aee_audio_mode_src(data)                                        ((0x00000003&(data))>>0)
#define AEE_OGG_MODE_get_aee_audio_mode(data)                                        ((0x00000003&(data))>>0)


#define AE_DEBUG                                                                     0x180020d8
#define AE_DEBUG_reg_addr                                                            "0xB80020D8"
#define AE_DEBUG_reg                                                                 0xB80020D8
#define set_AE_DEBUG_reg(data)   (*((volatile unsigned int*) AE_DEBUG_reg)=data)
#define get_AE_DEBUG_reg   (*((volatile unsigned int*) AE_DEBUG_reg))
#define AE_DEBUG_inst_adr                                                            "0x0036"
#define AE_DEBUG_inst                                                                0x0036
#define AE_DEBUG_ae_dbg_en_shift                                                     (12)
#define AE_DEBUG_ae_dbg_en_mask                                                      (0x00001000)
#define AE_DEBUG_ae_dbg_en(data)                                                     (0x00001000&((data)<<12))
#define AE_DEBUG_ae_dbg_en_src(data)                                                 ((0x00001000&(data))>>12)
#define AE_DEBUG_get_ae_dbg_en(data)                                                 ((0x00001000&(data))>>12)
#define AE_DEBUG_ae_dbg_sel1_shift                                                   (6)
#define AE_DEBUG_ae_dbg_sel1_mask                                                    (0x00000FC0)
#define AE_DEBUG_ae_dbg_sel1(data)                                                   (0x00000FC0&((data)<<6))
#define AE_DEBUG_ae_dbg_sel1_src(data)                                               ((0x00000FC0&(data))>>6)
#define AE_DEBUG_get_ae_dbg_sel1(data)                                               ((0x00000FC0&(data))>>6)
#define AE_DEBUG_ae_dbg_sel0_shift                                                   (0)
#define AE_DEBUG_ae_dbg_sel0_mask                                                    (0x0000003F)
#define AE_DEBUG_ae_dbg_sel0(data)                                                   (0x0000003F&((data)<<0))
#define AE_DEBUG_ae_dbg_sel0_src(data)                                               ((0x0000003F&(data))>>0)
#define AE_DEBUG_get_ae_dbg_sel0(data)                                               ((0x0000003F&(data))>>0)


#define SRC_SRC_BASE                                                                 0x18002100
#define SRC_SRC_BASE_reg_addr                                                        "0xB8002100"
#define SRC_SRC_BASE_reg                                                             0xB8002100
#define set_SRC_SRC_BASE_reg(data)   (*((volatile unsigned int*) SRC_SRC_BASE_reg)=data)
#define get_SRC_SRC_BASE_reg   (*((volatile unsigned int*) SRC_SRC_BASE_reg))
#define SRC_SRC_BASE_inst_adr                                                        "0x0040"
#define SRC_SRC_BASE_inst                                                            0x0040
#define SRC_SRC_BASE_src_src_base_shift                                              (3)
#define SRC_SRC_BASE_src_src_base_mask                                               (0x7FFFFFF8)
#define SRC_SRC_BASE_src_src_base(data)                                              (0x7FFFFFF8&((data)<<3))
#define SRC_SRC_BASE_src_src_base_src(data)                                          ((0x7FFFFFF8&(data))>>3)
#define SRC_SRC_BASE_get_src_src_base(data)                                          ((0x7FFFFFF8&(data))>>3)


#define SRC_SRC_WP                                                                   0x18002104
#define SRC_SRC_WP_reg_addr                                                          "0xB8002104"
#define SRC_SRC_WP_reg                                                               0xB8002104
#define set_SRC_SRC_WP_reg(data)   (*((volatile unsigned int*) SRC_SRC_WP_reg)=data)
#define get_SRC_SRC_WP_reg   (*((volatile unsigned int*) SRC_SRC_WP_reg))
#define SRC_SRC_WP_inst_adr                                                          "0x0041"
#define SRC_SRC_WP_inst                                                              0x0041
#define SRC_SRC_WP_src_src_wp_shift                                                  (2)
#define SRC_SRC_WP_src_src_wp_mask                                                   (0x7FFFFFFC)
#define SRC_SRC_WP_src_src_wp(data)                                                  (0x7FFFFFFC&((data)<<2))
#define SRC_SRC_WP_src_src_wp_src(data)                                              ((0x7FFFFFFC&(data))>>2)
#define SRC_SRC_WP_get_src_src_wp(data)                                              ((0x7FFFFFFC&(data))>>2)


#define SRC_SRC_RP                                                                   0x18002108
#define SRC_SRC_RP_reg_addr                                                          "0xB8002108"
#define SRC_SRC_RP_reg                                                               0xB8002108
#define set_SRC_SRC_RP_reg(data)   (*((volatile unsigned int*) SRC_SRC_RP_reg)=data)
#define get_SRC_SRC_RP_reg   (*((volatile unsigned int*) SRC_SRC_RP_reg))
#define SRC_SRC_RP_inst_adr                                                          "0x0042"
#define SRC_SRC_RP_inst                                                              0x0042
#define SRC_SRC_RP_src_src_rp_shift                                                  (2)
#define SRC_SRC_RP_src_src_rp_mask                                                   (0x7FFFFFFC)
#define SRC_SRC_RP_src_src_rp(data)                                                  (0x7FFFFFFC&((data)<<2))
#define SRC_SRC_RP_src_src_rp_src(data)                                              ((0x7FFFFFFC&(data))>>2)
#define SRC_SRC_RP_get_src_src_rp(data)                                              ((0x7FFFFFFC&(data))>>2)


#define SRC_DEST_BASE                                                                0x1800210c
#define SRC_DEST_BASE_reg_addr                                                       "0xB800210C"
#define SRC_DEST_BASE_reg                                                            0xB800210C
#define set_SRC_DEST_BASE_reg(data)   (*((volatile unsigned int*) SRC_DEST_BASE_reg)=data)
#define get_SRC_DEST_BASE_reg   (*((volatile unsigned int*) SRC_DEST_BASE_reg))
#define SRC_DEST_BASE_inst_adr                                                       "0x0043"
#define SRC_DEST_BASE_inst                                                           0x0043
#define SRC_DEST_BASE_src_dest_base_shift                                            (3)
#define SRC_DEST_BASE_src_dest_base_mask                                             (0x7FFFFFF8)
#define SRC_DEST_BASE_src_dest_base(data)                                            (0x7FFFFFF8&((data)<<3))
#define SRC_DEST_BASE_src_dest_base_src(data)                                        ((0x7FFFFFF8&(data))>>3)
#define SRC_DEST_BASE_get_src_dest_base(data)                                        ((0x7FFFFFF8&(data))>>3)


#define SRC_DEST_WP                                                                  0x18002110
#define SRC_DEST_WP_reg_addr                                                         "0xB8002110"
#define SRC_DEST_WP_reg                                                              0xB8002110
#define set_SRC_DEST_WP_reg(data)   (*((volatile unsigned int*) SRC_DEST_WP_reg)=data)
#define get_SRC_DEST_WP_reg   (*((volatile unsigned int*) SRC_DEST_WP_reg))
#define SRC_DEST_WP_inst_adr                                                         "0x0044"
#define SRC_DEST_WP_inst                                                             0x0044
#define SRC_DEST_WP_src_dest_wp_shift                                                (2)
#define SRC_DEST_WP_src_dest_wp_mask                                                 (0x7FFFFFFC)
#define SRC_DEST_WP_src_dest_wp(data)                                                (0x7FFFFFFC&((data)<<2))
#define SRC_DEST_WP_src_dest_wp_src(data)                                            ((0x7FFFFFFC&(data))>>2)
#define SRC_DEST_WP_get_src_dest_wp(data)                                            ((0x7FFFFFFC&(data))>>2)


#define SRC_DEST_RP                                                                  0x18002114
#define SRC_DEST_RP_reg_addr                                                         "0xB8002114"
#define SRC_DEST_RP_reg                                                              0xB8002114
#define set_SRC_DEST_RP_reg(data)   (*((volatile unsigned int*) SRC_DEST_RP_reg)=data)
#define get_SRC_DEST_RP_reg   (*((volatile unsigned int*) SRC_DEST_RP_reg))
#define SRC_DEST_RP_inst_adr                                                         "0x0045"
#define SRC_DEST_RP_inst                                                             0x0045
#define SRC_DEST_RP_src_dest_rp_shift                                                (2)
#define SRC_DEST_RP_src_dest_rp_mask                                                 (0x7FFFFFFC)
#define SRC_DEST_RP_src_dest_rp(data)                                                (0x7FFFFFFC&((data)<<2))
#define SRC_DEST_RP_src_dest_rp_src(data)                                            ((0x7FFFFFFC&(data))>>2)
#define SRC_DEST_RP_get_src_dest_rp(data)                                            ((0x7FFFFFFC&(data))>>2)


#define SRC_ITR_BUF0                                                                 0x18002118
#define SRC_ITR_BUF0_reg_addr                                                        "0xB8002118"
#define SRC_ITR_BUF0_reg                                                             0xB8002118
#define set_SRC_ITR_BUF0_reg(data)   (*((volatile unsigned int*) SRC_ITR_BUF0_reg)=data)
#define get_SRC_ITR_BUF0_reg   (*((volatile unsigned int*) SRC_ITR_BUF0_reg))
#define SRC_ITR_BUF0_inst_adr                                                        "0x0046"
#define SRC_ITR_BUF0_inst                                                            0x0046
#define SRC_ITR_BUF0_base_shift                                                      (3)
#define SRC_ITR_BUF0_base_mask                                                       (0x7FFFFFF8)
#define SRC_ITR_BUF0_base(data)                                                      (0x7FFFFFF8&((data)<<3))
#define SRC_ITR_BUF0_base_src(data)                                                  ((0x7FFFFFF8&(data))>>3)
#define SRC_ITR_BUF0_get_base(data)                                                  ((0x7FFFFFF8&(data))>>3)


#define SRC_ITR_BUF1                                                                 0x1800211c
#define SRC_ITR_BUF1_reg_addr                                                        "0xB800211C"
#define SRC_ITR_BUF1_reg                                                             0xB800211C
#define set_SRC_ITR_BUF1_reg(data)   (*((volatile unsigned int*) SRC_ITR_BUF1_reg)=data)
#define get_SRC_ITR_BUF1_reg   (*((volatile unsigned int*) SRC_ITR_BUF1_reg))
#define SRC_ITR_BUF1_inst_adr                                                        "0x0047"
#define SRC_ITR_BUF1_inst                                                            0x0047
#define SRC_ITR_BUF1_wp_shift                                                        (2)
#define SRC_ITR_BUF1_wp_mask                                                         (0x7FFFFFFC)
#define SRC_ITR_BUF1_wp(data)                                                        (0x7FFFFFFC&((data)<<2))
#define SRC_ITR_BUF1_wp_src(data)                                                    ((0x7FFFFFFC&(data))>>2)
#define SRC_ITR_BUF1_get_wp(data)                                                    ((0x7FFFFFFC&(data))>>2)


#define SRC_ITR_BUF2                                                                 0x18002120
#define SRC_ITR_BUF2_reg_addr                                                        "0xB8002120"
#define SRC_ITR_BUF2_reg                                                             0xB8002120
#define set_SRC_ITR_BUF2_reg(data)   (*((volatile unsigned int*) SRC_ITR_BUF2_reg)=data)
#define get_SRC_ITR_BUF2_reg   (*((volatile unsigned int*) SRC_ITR_BUF2_reg))
#define SRC_ITR_BUF2_inst_adr                                                        "0x0048"
#define SRC_ITR_BUF2_inst                                                            0x0048
#define SRC_ITR_BUF2_rp_shift                                                        (2)
#define SRC_ITR_BUF2_rp_mask                                                         (0x7FFFFFFC)
#define SRC_ITR_BUF2_rp(data)                                                        (0x7FFFFFFC&((data)<<2))
#define SRC_ITR_BUF2_rp_src(data)                                                    ((0x7FFFFFFC&(data))>>2)
#define SRC_ITR_BUF2_get_rp(data)                                                    ((0x7FFFFFFC&(data))>>2)


#define SRC_CTRL0                                                                    0x18002124
#define SRC_CTRL0_reg_addr                                                           "0xB8002124"
#define SRC_CTRL0_reg                                                                0xB8002124
#define set_SRC_CTRL0_reg(data)   (*((volatile unsigned int*) SRC_CTRL0_reg)=data)
#define get_SRC_CTRL0_reg   (*((volatile unsigned int*) SRC_CTRL0_reg))
#define SRC_CTRL0_inst_adr                                                           "0x0049"
#define SRC_CTRL0_inst                                                               0x0049
#define SRC_CTRL0_write_en3_shift                                                    (23)
#define SRC_CTRL0_write_en3_mask                                                     (0x00800000)
#define SRC_CTRL0_write_en3(data)                                                    (0x00800000&((data)<<23))
#define SRC_CTRL0_write_en3_src(data)                                                ((0x00800000&(data))>>23)
#define SRC_CTRL0_get_write_en3(data)                                                ((0x00800000&(data))>>23)
#define SRC_CTRL0_itr_rb_size_shift                                                  (16)
#define SRC_CTRL0_itr_rb_size_mask                                                   (0x007F0000)
#define SRC_CTRL0_itr_rb_size(data)                                                  (0x007F0000&((data)<<16))
#define SRC_CTRL0_itr_rb_size_src(data)                                              ((0x007F0000&(data))>>16)
#define SRC_CTRL0_get_itr_rb_size(data)                                              ((0x007F0000&(data))>>16)
#define SRC_CTRL0_write_en2_shift                                                    (6)
#define SRC_CTRL0_write_en2_mask                                                     (0x00000040)
#define SRC_CTRL0_write_en2(data)                                                    (0x00000040&((data)<<6))
#define SRC_CTRL0_write_en2_src(data)                                                ((0x00000040&(data))>>6)
#define SRC_CTRL0_get_write_en2(data)                                                ((0x00000040&(data))>>6)
#define SRC_CTRL0_phase_shift                                                        (5)
#define SRC_CTRL0_phase_mask                                                         (0x00000020)
#define SRC_CTRL0_phase(data)                                                        (0x00000020&((data)<<5))
#define SRC_CTRL0_phase_src(data)                                                    ((0x00000020&(data))>>5)
#define SRC_CTRL0_get_phase(data)                                                    ((0x00000020&(data))>>5)
#define SRC_CTRL0_write_en1_shift                                                    (4)
#define SRC_CTRL0_write_en1_mask                                                     (0x00000010)
#define SRC_CTRL0_write_en1(data)                                                    (0x00000010&((data)<<4))
#define SRC_CTRL0_write_en1_src(data)                                                ((0x00000010&(data))>>4)
#define SRC_CTRL0_get_write_en1(data)                                                ((0x00000010&(data))>>4)
#define SRC_CTRL0_src_mode_shift                                                     (0)
#define SRC_CTRL0_src_mode_mask                                                      (0x0000000F)
#define SRC_CTRL0_src_mode(data)                                                     (0x0000000F&((data)<<0))
#define SRC_CTRL0_src_mode_src(data)                                                 ((0x0000000F&(data))>>0)
#define SRC_CTRL0_get_src_mode(data)                                                 ((0x0000000F&(data))>>0)


#define SRC_CTRL1                                                                    0x18002128
#define SRC_CTRL1_reg_addr                                                           "0xB8002128"
#define SRC_CTRL1_reg                                                                0xB8002128
#define set_SRC_CTRL1_reg(data)   (*((volatile unsigned int*) SRC_CTRL1_reg)=data)
#define get_SRC_CTRL1_reg   (*((volatile unsigned int*) SRC_CTRL1_reg))
#define SRC_CTRL1_inst_adr                                                           "0x004A"
#define SRC_CTRL1_inst                                                               0x004A
#define SRC_CTRL1_write_en6_shift                                                    (31)
#define SRC_CTRL1_write_en6_mask                                                     (0x80000000)
#define SRC_CTRL1_write_en6(data)                                                    (0x80000000&((data)<<31))
#define SRC_CTRL1_write_en6_src(data)                                                ((0x80000000&(data))>>31)
#define SRC_CTRL1_get_write_en6(data)                                                ((0x80000000&(data))>>31)
#define SRC_CTRL1_src_rb_size_shift                                                  (24)
#define SRC_CTRL1_src_rb_size_mask                                                   (0x7F000000)
#define SRC_CTRL1_src_rb_size(data)                                                  (0x7F000000&((data)<<24))
#define SRC_CTRL1_src_rb_size_src(data)                                              ((0x7F000000&(data))>>24)
#define SRC_CTRL1_get_src_rb_size(data)                                              ((0x7F000000&(data))>>24)
#define SRC_CTRL1_write_en5_shift                                                    (23)
#define SRC_CTRL1_write_en5_mask                                                     (0x00800000)
#define SRC_CTRL1_write_en5(data)                                                    (0x00800000&((data)<<23))
#define SRC_CTRL1_write_en5_src(data)                                                ((0x00800000&(data))>>23)
#define SRC_CTRL1_get_write_en5(data)                                                ((0x00800000&(data))>>23)
#define SRC_CTRL1_dest_rb_size_shift                                                 (16)
#define SRC_CTRL1_dest_rb_size_mask                                                  (0x007F0000)
#define SRC_CTRL1_dest_rb_size(data)                                                 (0x007F0000&((data)<<16))
#define SRC_CTRL1_dest_rb_size_src(data)                                             ((0x007F0000&(data))>>16)
#define SRC_CTRL1_get_dest_rb_size(data)                                             ((0x007F0000&(data))>>16)
#define SRC_CTRL1_write_en4_shift                                                    (15)
#define SRC_CTRL1_write_en4_mask                                                     (0x00008000)
#define SRC_CTRL1_write_en4(data)                                                    (0x00008000&((data)<<15))
#define SRC_CTRL1_write_en4_src(data)                                                ((0x00008000&(data))>>15)
#define SRC_CTRL1_get_write_en4(data)                                                ((0x00008000&(data))>>15)
#define SRC_CTRL1_write_en3_shift                                                    (13)
#define SRC_CTRL1_write_en3_mask                                                     (0x00002000)
#define SRC_CTRL1_write_en3(data)                                                    (0x00002000&((data)<<13))
#define SRC_CTRL1_write_en3_src(data)                                                ((0x00002000&(data))>>13)
#define SRC_CTRL1_get_write_en3(data)                                                ((0x00002000&(data))>>13)
#define SRC_CTRL1_chan_num_shift                                                     (10)
#define SRC_CTRL1_chan_num_mask                                                      (0x00001C00)
#define SRC_CTRL1_chan_num(data)                                                     (0x00001C00&((data)<<10))
#define SRC_CTRL1_chan_num_src(data)                                                 ((0x00001C00&(data))>>10)
#define SRC_CTRL1_get_chan_num(data)                                                 ((0x00001C00&(data))>>10)
#define SRC_CTRL1_write_en2_shift                                                    (9)
#define SRC_CTRL1_write_en2_mask                                                     (0x00000200)
#define SRC_CTRL1_write_en2(data)                                                    (0x00000200&((data)<<9))
#define SRC_CTRL1_write_en2_src(data)                                                ((0x00000200&(data))>>9)
#define SRC_CTRL1_get_write_en2(data)                                                ((0x00000200&(data))>>9)
#define SRC_CTRL1_write_en_shift                                                     (5)
#define SRC_CTRL1_write_en_mask                                                      (0x00000020)
#define SRC_CTRL1_write_en(data)                                                     (0x00000020&((data)<<5))
#define SRC_CTRL1_write_en_src(data)                                                 ((0x00000020&(data))>>5)
#define SRC_CTRL1_get_write_en(data)                                                 ((0x00000020&(data))>>5)
#define SRC_CTRL1_size_shift                                                         (0)
#define SRC_CTRL1_size_mask                                                          (0x0000001F)
#define SRC_CTRL1_size(data)                                                         (0x0000001F&((data)<<0))
#define SRC_CTRL1_size_src(data)                                                     ((0x0000001F&(data))>>0)
#define SRC_CTRL1_get_size(data)                                                     ((0x0000001F&(data))>>0)


#define SRC_CTRL2                                                                    0x1800212c
#define SRC_CTRL2_reg_addr                                                           "0xB800212C"
#define SRC_CTRL2_reg                                                                0xB800212C
#define set_SRC_CTRL2_reg(data)   (*((volatile unsigned int*) SRC_CTRL2_reg)=data)
#define get_SRC_CTRL2_reg   (*((volatile unsigned int*) SRC_CTRL2_reg))
#define SRC_CTRL2_inst_adr                                                           "0x004B"
#define SRC_CTRL2_inst                                                               0x004B
#define SRC_CTRL2_write_en7_shift                                                    (24)
#define SRC_CTRL2_write_en7_mask                                                     (0x01000000)
#define SRC_CTRL2_write_en7(data)                                                    (0x01000000&((data)<<24))
#define SRC_CTRL2_write_en7_src(data)                                                ((0x01000000&(data))>>24)
#define SRC_CTRL2_get_write_en7(data)                                                ((0x01000000&(data))>>24)
#define SRC_CTRL2_idx_2_shift                                                        (16)
#define SRC_CTRL2_idx_2_mask                                                         (0x00FF0000)
#define SRC_CTRL2_idx_2(data)                                                        (0x00FF0000&((data)<<16))
#define SRC_CTRL2_idx_2_src(data)                                                    ((0x00FF0000&(data))>>16)
#define SRC_CTRL2_get_idx_2(data)                                                    ((0x00FF0000&(data))>>16)
#define SRC_CTRL2_write_en6_shift                                                    (29)
#define SRC_CTRL2_write_en6_mask                                                     (0x20000000)
#define SRC_CTRL2_write_en6(data)                                                    (0x20000000&((data)<<29))
#define SRC_CTRL2_write_en6_src(data)                                                ((0x20000000&(data))>>29)
#define SRC_CTRL2_get_write_en6(data)                                                ((0x20000000&(data))>>29)
#define SRC_CTRL2_rom_sync_sel_shift                                                 (28)
#define SRC_CTRL2_rom_sync_sel_mask                                                  (0x10000000)
#define SRC_CTRL2_rom_sync_sel(data)                                                 (0x10000000&((data)<<28))
#define SRC_CTRL2_rom_sync_sel_src(data)                                             ((0x10000000&(data))>>28)
#define SRC_CTRL2_get_rom_sync_sel(data)                                             ((0x10000000&(data))>>28)
#define SRC_CTRL2_write_en5_shift                                                    (27)
#define SRC_CTRL2_write_en5_mask                                                     (0x08000000)
#define SRC_CTRL2_write_en5(data)                                                    (0x08000000&((data)<<27))
#define SRC_CTRL2_write_en5_src(data)                                                ((0x08000000&(data))>>27)
#define SRC_CTRL2_get_write_en5(data)                                                ((0x08000000&(data))>>27)
#define SRC_CTRL2_filter_tap_shift                                                   (25)
#define SRC_CTRL2_filter_tap_mask                                                    (0x06000000)
#define SRC_CTRL2_filter_tap(data)                                                   (0x06000000&((data)<<25))
#define SRC_CTRL2_filter_tap_src(data)                                               ((0x06000000&(data))>>25)
#define SRC_CTRL2_get_filter_tap(data)                                               ((0x06000000&(data))>>25)
#define SRC_CTRL2_write_en4_shift                                                    (15)
#define SRC_CTRL2_write_en4_mask                                                     (0x00008000)
#define SRC_CTRL2_write_en4(data)                                                    (0x00008000&((data)<<15))
#define SRC_CTRL2_write_en4_src(data)                                                ((0x00008000&(data))>>15)
#define SRC_CTRL2_get_write_en4(data)                                                ((0x00008000&(data))>>15)
#define SRC_CTRL2_idx_shift                                                          (7)
#define SRC_CTRL2_idx_mask                                                           (0x00007F80)
#define SRC_CTRL2_idx(data)                                                          (0x00007F80&((data)<<7))
#define SRC_CTRL2_idx_src(data)                                                      ((0x00007F80&(data))>>7)
#define SRC_CTRL2_get_idx(data)                                                      ((0x00007F80&(data))>>7)
#define SRC_CTRL2_write_en3_shift                                                    (6)
#define SRC_CTRL2_write_en3_mask                                                     (0x00000040)
#define SRC_CTRL2_write_en3(data)                                                    (0x00000040&((data)<<6))
#define SRC_CTRL2_write_en3_src(data)                                                ((0x00000040&(data))>>6)
#define SRC_CTRL2_get_write_en3(data)                                                ((0x00000040&(data))>>6)
#define SRC_CTRL2_mode_shift                                                         (4)
#define SRC_CTRL2_mode_mask                                                          (0x00000030)
#define SRC_CTRL2_mode(data)                                                         (0x00000030&((data)<<4))
#define SRC_CTRL2_mode_src(data)                                                     ((0x00000030&(data))>>4)
#define SRC_CTRL2_get_mode(data)                                                     ((0x00000030&(data))>>4)
#define SRC_CTRL2_write_en2_shift                                                    (3)
#define SRC_CTRL2_write_en2_mask                                                     (0x00000008)
#define SRC_CTRL2_write_en2(data)                                                    (0x00000008&((data)<<3))
#define SRC_CTRL2_write_en2_src(data)                                                ((0x00000008&(data))>>3)
#define SRC_CTRL2_get_write_en2(data)                                                ((0x00000008&(data))>>3)
#define SRC_CTRL2_stop_shift                                                         (2)
#define SRC_CTRL2_stop_mask                                                          (0x00000004)
#define SRC_CTRL2_stop(data)                                                         (0x00000004&((data)<<2))
#define SRC_CTRL2_stop_src(data)                                                     ((0x00000004&(data))>>2)
#define SRC_CTRL2_get_stop(data)                                                     ((0x00000004&(data))>>2)
#define SRC_CTRL2_write_en1_shift                                                    (1)
#define SRC_CTRL2_write_en1_mask                                                     (0x00000002)
#define SRC_CTRL2_write_en1(data)                                                    (0x00000002&((data)<<1))
#define SRC_CTRL2_write_en1_src(data)                                                ((0x00000002&(data))>>1)
#define SRC_CTRL2_get_write_en1(data)                                                ((0x00000002&(data))>>1)
#define SRC_CTRL2_go_shift                                                           (0)
#define SRC_CTRL2_go_mask                                                            (0x00000001)
#define SRC_CTRL2_go(data)                                                           (0x00000001&((data)<<0))
#define SRC_CTRL2_go_src(data)                                                       ((0x00000001&(data))>>0)
#define SRC_CTRL2_get_go(data)                                                       ((0x00000001&(data))>>0)


#define SRC_STATUS                                                                   0x18002130
#define SRC_STATUS_reg_addr                                                          "0xB8002130"
#define SRC_STATUS_reg                                                               0xB8002130
#define set_SRC_STATUS_reg(data)   (*((volatile unsigned int*) SRC_STATUS_reg)=data)
#define get_SRC_STATUS_reg   (*((volatile unsigned int*) SRC_STATUS_reg))
#define SRC_STATUS_inst_adr                                                          "0x004C"
#define SRC_STATUS_inst                                                              0x004C
#define SRC_STATUS_chan_busy_shift                                                   (0)
#define SRC_STATUS_chan_busy_mask                                                    (0x00000007)
#define SRC_STATUS_chan_busy(data)                                                   (0x00000007&((data)<<0))
#define SRC_STATUS_chan_busy_src(data)                                               ((0x00000007&(data))>>0)
#define SRC_STATUS_get_chan_busy(data)                                               ((0x00000007&(data))>>0)


#define SRC_RB_STATUS                                                                0x18002134
#define SRC_RB_STATUS_reg_addr                                                       "0xB8002134"
#define SRC_RB_STATUS_reg                                                            0xB8002134
#define set_SRC_RB_STATUS_reg(data)   (*((volatile unsigned int*) SRC_RB_STATUS_reg)=data)
#define get_SRC_RB_STATUS_reg   (*((volatile unsigned int*) SRC_RB_STATUS_reg))
#define SRC_RB_STATUS_inst_adr                                                       "0x004D"
#define SRC_RB_STATUS_inst                                                           0x004D
#define SRC_RB_STATUS_write_en6_shift                                                (11)
#define SRC_RB_STATUS_write_en6_mask                                                 (0x00000800)
#define SRC_RB_STATUS_write_en6(data)                                                (0x00000800&((data)<<11))
#define SRC_RB_STATUS_write_en6_src(data)                                            ((0x00000800&(data))>>11)
#define SRC_RB_STATUS_get_write_en6(data)                                            ((0x00000800&(data))>>11)
#define SRC_RB_STATUS_stop_en_shift                                                  (10)
#define SRC_RB_STATUS_stop_en_mask                                                   (0x00000400)
#define SRC_RB_STATUS_stop_en(data)                                                  (0x00000400&((data)<<10))
#define SRC_RB_STATUS_stop_en_src(data)                                              ((0x00000400&(data))>>10)
#define SRC_RB_STATUS_get_stop_en(data)                                              ((0x00000400&(data))>>10)
#define SRC_RB_STATUS_write_en5_shift                                                (9)
#define SRC_RB_STATUS_write_en5_mask                                                 (0x00000200)
#define SRC_RB_STATUS_write_en5(data)                                                (0x00000200&((data)<<9))
#define SRC_RB_STATUS_write_en5_src(data)                                            ((0x00000200&(data))>>9)
#define SRC_RB_STATUS_get_write_en5(data)                                            ((0x00000200&(data))>>9)
#define SRC_RB_STATUS_time_out_shift                                                 (8)
#define SRC_RB_STATUS_time_out_mask                                                  (0x00000100)
#define SRC_RB_STATUS_time_out(data)                                                 (0x00000100&((data)<<8))
#define SRC_RB_STATUS_time_out_src(data)                                             ((0x00000100&(data))>>8)
#define SRC_RB_STATUS_get_time_out(data)                                             ((0x00000100&(data))>>8)
#define SRC_RB_STATUS_write_en4_shift                                                (7)
#define SRC_RB_STATUS_write_en4_mask                                                 (0x00000080)
#define SRC_RB_STATUS_write_en4(data)                                                (0x00000080&((data)<<7))
#define SRC_RB_STATUS_write_en4_src(data)                                            ((0x00000080&(data))>>7)
#define SRC_RB_STATUS_get_write_en4(data)                                            ((0x00000080&(data))>>7)
#define SRC_RB_STATUS_done_shift                                                     (6)
#define SRC_RB_STATUS_done_mask                                                      (0x00000040)
#define SRC_RB_STATUS_done(data)                                                     (0x00000040&((data)<<6))
#define SRC_RB_STATUS_done_src(data)                                                 ((0x00000040&(data))>>6)
#define SRC_RB_STATUS_get_done(data)                                                 ((0x00000040&(data))>>6)
#define SRC_RB_STATUS_write_en3_shift                                                (5)
#define SRC_RB_STATUS_write_en3_mask                                                 (0x00000020)
#define SRC_RB_STATUS_write_en3(data)                                                (0x00000020&((data)<<5))
#define SRC_RB_STATUS_write_en3_src(data)                                            ((0x00000020&(data))>>5)
#define SRC_RB_STATUS_get_write_en3(data)                                            ((0x00000020&(data))>>5)
#define SRC_RB_STATUS_error_shift                                                    (4)
#define SRC_RB_STATUS_error_mask                                                     (0x00000010)
#define SRC_RB_STATUS_error(data)                                                    (0x00000010&((data)<<4))
#define SRC_RB_STATUS_error_src(data)                                                ((0x00000010&(data))>>4)
#define SRC_RB_STATUS_get_error(data)                                                ((0x00000010&(data))>>4)
#define SRC_RB_STATUS_write_en2_shift                                                (3)
#define SRC_RB_STATUS_write_en2_mask                                                 (0x00000008)
#define SRC_RB_STATUS_write_en2(data)                                                (0x00000008&((data)<<3))
#define SRC_RB_STATUS_write_en2_src(data)                                            ((0x00000008&(data))>>3)
#define SRC_RB_STATUS_get_write_en2(data)                                            ((0x00000008&(data))>>3)
#define SRC_RB_STATUS_src_rb_empty_shift                                             (2)
#define SRC_RB_STATUS_src_rb_empty_mask                                              (0x00000004)
#define SRC_RB_STATUS_src_rb_empty(data)                                             (0x00000004&((data)<<2))
#define SRC_RB_STATUS_src_rb_empty_src(data)                                         ((0x00000004&(data))>>2)
#define SRC_RB_STATUS_get_src_rb_empty(data)                                         ((0x00000004&(data))>>2)
#define SRC_RB_STATUS_write_en1_shift                                                (1)
#define SRC_RB_STATUS_write_en1_mask                                                 (0x00000002)
#define SRC_RB_STATUS_write_en1(data)                                                (0x00000002&((data)<<1))
#define SRC_RB_STATUS_write_en1_src(data)                                            ((0x00000002&(data))>>1)
#define SRC_RB_STATUS_get_write_en1(data)                                            ((0x00000002&(data))>>1)
#define SRC_RB_STATUS_dest_rb_full_shift                                             (0)
#define SRC_RB_STATUS_dest_rb_full_mask                                              (0x00000001)
#define SRC_RB_STATUS_dest_rb_full(data)                                             (0x00000001&((data)<<0))
#define SRC_RB_STATUS_dest_rb_full_src(data)                                         ((0x00000001&(data))>>0)
#define SRC_RB_STATUS_get_dest_rb_full(data)                                         ((0x00000001&(data))>>0)


#define SRC_INT_EN                                                                   0x18002138
#define SRC_INT_EN_reg_addr                                                          "0xB8002138"
#define SRC_INT_EN_reg                                                               0xB8002138
#define set_SRC_INT_EN_reg(data)   (*((volatile unsigned int*) SRC_INT_EN_reg)=data)
#define get_SRC_INT_EN_reg   (*((volatile unsigned int*) SRC_INT_EN_reg))
#define SRC_INT_EN_inst_adr                                                          "0x004E"
#define SRC_INT_EN_inst                                                              0x004E
#define SRC_INT_EN_write_en5_shift                                                   (9)
#define SRC_INT_EN_write_en5_mask                                                    (0x00000200)
#define SRC_INT_EN_write_en5(data)                                                   (0x00000200&((data)<<9))
#define SRC_INT_EN_write_en5_src(data)                                               ((0x00000200&(data))>>9)
#define SRC_INT_EN_get_write_en5(data)                                               ((0x00000200&(data))>>9)
#define SRC_INT_EN_time_out_shift                                                    (8)
#define SRC_INT_EN_time_out_mask                                                     (0x00000100)
#define SRC_INT_EN_time_out(data)                                                    (0x00000100&((data)<<8))
#define SRC_INT_EN_time_out_src(data)                                                ((0x00000100&(data))>>8)
#define SRC_INT_EN_get_time_out(data)                                                ((0x00000100&(data))>>8)
#define SRC_INT_EN_write_en4_shift                                                   (7)
#define SRC_INT_EN_write_en4_mask                                                    (0x00000080)
#define SRC_INT_EN_write_en4(data)                                                   (0x00000080&((data)<<7))
#define SRC_INT_EN_write_en4_src(data)                                               ((0x00000080&(data))>>7)
#define SRC_INT_EN_get_write_en4(data)                                               ((0x00000080&(data))>>7)
#define SRC_INT_EN_done_en_shift                                                     (6)
#define SRC_INT_EN_done_en_mask                                                      (0x00000040)
#define SRC_INT_EN_done_en(data)                                                     (0x00000040&((data)<<6))
#define SRC_INT_EN_done_en_src(data)                                                 ((0x00000040&(data))>>6)
#define SRC_INT_EN_get_done_en(data)                                                 ((0x00000040&(data))>>6)
#define SRC_INT_EN_write_en3_shift                                                   (5)
#define SRC_INT_EN_write_en3_mask                                                    (0x00000020)
#define SRC_INT_EN_write_en3(data)                                                   (0x00000020&((data)<<5))
#define SRC_INT_EN_write_en3_src(data)                                               ((0x00000020&(data))>>5)
#define SRC_INT_EN_get_write_en3(data)                                               ((0x00000020&(data))>>5)
#define SRC_INT_EN_error_en_shift                                                    (4)
#define SRC_INT_EN_error_en_mask                                                     (0x00000010)
#define SRC_INT_EN_error_en(data)                                                    (0x00000010&((data)<<4))
#define SRC_INT_EN_error_en_src(data)                                                ((0x00000010&(data))>>4)
#define SRC_INT_EN_get_error_en(data)                                                ((0x00000010&(data))>>4)
#define SRC_INT_EN_write_en2_shift                                                   (3)
#define SRC_INT_EN_write_en2_mask                                                    (0x00000008)
#define SRC_INT_EN_write_en2(data)                                                   (0x00000008&((data)<<3))
#define SRC_INT_EN_write_en2_src(data)                                               ((0x00000008&(data))>>3)
#define SRC_INT_EN_get_write_en2(data)                                               ((0x00000008&(data))>>3)
#define SRC_INT_EN_src_rb_empty_en_shift                                             (2)
#define SRC_INT_EN_src_rb_empty_en_mask                                              (0x00000004)
#define SRC_INT_EN_src_rb_empty_en(data)                                             (0x00000004&((data)<<2))
#define SRC_INT_EN_src_rb_empty_en_src(data)                                         ((0x00000004&(data))>>2)
#define SRC_INT_EN_get_src_rb_empty_en(data)                                         ((0x00000004&(data))>>2)
#define SRC_INT_EN_write_en1_shift                                                   (1)
#define SRC_INT_EN_write_en1_mask                                                    (0x00000002)
#define SRC_INT_EN_write_en1(data)                                                   (0x00000002&((data)<<1))
#define SRC_INT_EN_write_en1_src(data)                                               ((0x00000002&(data))>>1)
#define SRC_INT_EN_get_write_en1(data)                                               ((0x00000002&(data))>>1)
#define SRC_INT_EN_dest_rb_full_en_shift                                             (0)
#define SRC_INT_EN_dest_rb_full_en_mask                                              (0x00000001)
#define SRC_INT_EN_dest_rb_full_en(data)                                             (0x00000001&((data)<<0))
#define SRC_INT_EN_dest_rb_full_en_src(data)                                         ((0x00000001&(data))>>0)
#define SRC_INT_EN_get_dest_rb_full_en(data)                                         ((0x00000001&(data))>>0)


#define SRC_SRC_THRESHOLD                                                            0x1800213c
#define SRC_SRC_THRESHOLD_reg_addr                                                   "0xB800213C"
#define SRC_SRC_THRESHOLD_reg                                                        0xB800213C
#define set_SRC_SRC_THRESHOLD_reg(data)   (*((volatile unsigned int*) SRC_SRC_THRESHOLD_reg)=data)
#define get_SRC_SRC_THRESHOLD_reg   (*((volatile unsigned int*) SRC_SRC_THRESHOLD_reg))
#define SRC_SRC_THRESHOLD_inst_adr                                                   "0x004F"
#define SRC_SRC_THRESHOLD_inst                                                       0x004F
#define SRC_SRC_THRESHOLD_thld_shift                                                 (0)
#define SRC_SRC_THRESHOLD_thld_mask                                                  (0x01FFFFFF)
#define SRC_SRC_THRESHOLD_thld(data)                                                 (0x01FFFFFF&((data)<<0))
#define SRC_SRC_THRESHOLD_thld_src(data)                                             ((0x01FFFFFF&(data))>>0)
#define SRC_SRC_THRESHOLD_get_thld(data)                                             ((0x01FFFFFF&(data))>>0)


#define FILTER_COEF_0                                                                0x18002140
#define FILTER_COEF_0_reg_addr                                                       "0xB8002140"
#define FILTER_COEF_0_reg                                                            0xB8002140
#define set_FILTER_COEF_0_reg(data)   (*((volatile unsigned int*) FILTER_COEF_0_reg)=data)
#define get_FILTER_COEF_0_reg   (*((volatile unsigned int*) FILTER_COEF_0_reg))
#define FILTER_COEF_0_inst_adr                                                       "0x0050"
#define FILTER_COEF_0_inst                                                           0x0050
#define FILTER_COEF_0_adr1_shift                                                     (2)
#define FILTER_COEF_0_adr1_mask                                                      (0x7FFFFFFC)
#define FILTER_COEF_0_adr1(data)                                                     (0x7FFFFFFC&((data)<<2))
#define FILTER_COEF_0_adr1_src(data)                                                 ((0x7FFFFFFC&(data))>>2)
#define FILTER_COEF_0_get_adr1(data)                                                 ((0x7FFFFFFC&(data))>>2)


#define FILTER_COEF                                                                  0x18002144
#define FILTER_COEF_reg_addr                                                         "0xB8002144"
#define FILTER_COEF_reg                                                              0xB8002144
#define set_FILTER_COEF_reg(data)   (*((volatile unsigned int*) FILTER_COEF_reg)=data)
#define get_FILTER_COEF_reg   (*((volatile unsigned int*) FILTER_COEF_reg))
#define FILTER_COEF_inst_adr                                                         "0x0051"
#define FILTER_COEF_inst                                                             0x0051
#define FILTER_COEF_adr_shift                                                        (2)
#define FILTER_COEF_adr_mask                                                         (0x7FFFFFFC)
#define FILTER_COEF_adr(data)                                                        (0x7FFFFFFC&((data)<<2))
#define FILTER_COEF_adr_src(data)                                                    ((0x7FFFFFFC&(data))>>2)
#define FILTER_COEF_get_adr(data)                                                    ((0x7FFFFFFC&(data))>>2)


#define FILTER_COEF_2                                                                0x18002148
#define FILTER_COEF_2_reg_addr                                                       "0xB8002148"
#define FILTER_COEF_2_reg                                                            0xB8002148
#define set_FILTER_COEF_2_reg(data)   (*((volatile unsigned int*) FILTER_COEF_2_reg)=data)
#define get_FILTER_COEF_2_reg   (*((volatile unsigned int*) FILTER_COEF_2_reg))
#define FILTER_COEF_2_inst_adr                                                       "0x0052"
#define FILTER_COEF_2_inst                                                           0x0052
#define FILTER_COEF_2_adr1_phase2_shift                                              (2)
#define FILTER_COEF_2_adr1_phase2_mask                                               (0x7FFFFFFC)
#define FILTER_COEF_2_adr1_phase2(data)                                              (0x7FFFFFFC&((data)<<2))
#define FILTER_COEF_2_adr1_phase2_src(data)                                          ((0x7FFFFFFC&(data))>>2)
#define FILTER_COEF_2_get_adr1_phase2(data)                                          ((0x7FFFFFFC&(data))>>2)


#define FILTER_COEF_3                                                                0x1800214c
#define FILTER_COEF_3_reg_addr                                                       "0xB800214C"
#define FILTER_COEF_3_reg                                                            0xB800214C
#define set_FILTER_COEF_3_reg(data)   (*((volatile unsigned int*) FILTER_COEF_3_reg)=data)
#define get_FILTER_COEF_3_reg   (*((volatile unsigned int*) FILTER_COEF_3_reg))
#define FILTER_COEF_3_inst_adr                                                       "0x0053"
#define FILTER_COEF_3_inst                                                           0x0053
#define FILTER_COEF_3_adr2_phase2_shift                                              (2)
#define FILTER_COEF_3_adr2_phase2_mask                                               (0x7FFFFFFC)
#define FILTER_COEF_3_adr2_phase2(data)                                              (0x7FFFFFFC&((data)<<2))
#define FILTER_COEF_3_adr2_phase2_src(data)                                          ((0x7FFFFFFC&(data))>>2)
#define FILTER_COEF_3_get_adr2_phase2(data)                                          ((0x7FFFFFFC&(data))>>2)


#define FILTER_COEF_CTRL                                                             0x18002150
#define FILTER_COEF_CTRL_reg_addr                                                    "0xB8002150"
#define FILTER_COEF_CTRL_reg                                                         0xB8002150
#define set_FILTER_COEF_CTRL_reg(data)   (*((volatile unsigned int*) FILTER_COEF_CTRL_reg)=data)
#define get_FILTER_COEF_CTRL_reg   (*((volatile unsigned int*) FILTER_COEF_CTRL_reg))
#define FILTER_COEF_CTRL_inst_adr                                                    "0x0054"
#define FILTER_COEF_CTRL_inst                                                        0x0054
#define FILTER_COEF_CTRL_load_coef_shift                                             (0)
#define FILTER_COEF_CTRL_load_coef_mask                                              (0x00000001)
#define FILTER_COEF_CTRL_load_coef(data)                                             (0x00000001&((data)<<0))
#define FILTER_COEF_CTRL_load_coef_src(data)                                         ((0x00000001&(data))>>0)
#define FILTER_COEF_CTRL_get_load_coef(data)                                         ((0x00000001&(data))>>0)


#define AE_DUMMY                                                                     0x18002154
#define AE_DUMMY_reg_addr                                                            "0xB8002154"
#define AE_DUMMY_reg                                                                 0xB8002154
#define set_AE_DUMMY_reg(data)   (*((volatile unsigned int*) AE_DUMMY_reg)=data)
#define get_AE_DUMMY_reg   (*((volatile unsigned int*) AE_DUMMY_reg))
#define AE_DUMMY_inst_adr                                                            "0x0055"
#define AE_DUMMY_inst                                                                0x0055
#define AE_DUMMY_dummy_shift                                                         (0)
#define AE_DUMMY_dummy_mask                                                          (0xFFFFFFFF)
#define AE_DUMMY_dummy(data)                                                         (0xFFFFFFFF&((data)<<0))
#define AE_DUMMY_dummy_src(data)                                                     ((0xFFFFFFFF&(data))>>0)
#define AE_DUMMY_get_dummy(data)                                                     ((0xFFFFFFFF&(data))>>0)


#define AE_SRC_STATE                                                                 0x18002158
#define AE_SRC_STATE_reg_addr                                                        "0xB8002158"
#define AE_SRC_STATE_reg                                                             0xB8002158
#define set_AE_SRC_STATE_reg(data)   (*((volatile unsigned int*) AE_SRC_STATE_reg)=data)
#define get_AE_SRC_STATE_reg   (*((volatile unsigned int*) AE_SRC_STATE_reg))
#define AE_SRC_STATE_inst_adr                                                        "0x0056"
#define AE_SRC_STATE_inst                                                            0x0056
#define AE_SRC_STATE_str_state_flt_shift                                             (24)
#define AE_SRC_STATE_str_state_flt_mask                                              (0x0F000000)
#define AE_SRC_STATE_str_state_flt(data)                                             (0x0F000000&((data)<<24))
#define AE_SRC_STATE_str_state_flt_src(data)                                         ((0x0F000000&(data))>>24)
#define AE_SRC_STATE_get_str_state_flt(data)                                         ((0x0F000000&(data))>>24)
#define AE_SRC_STATE_str_state_dma_shift                                             (16)
#define AE_SRC_STATE_str_state_dma_mask                                              (0x000F0000)
#define AE_SRC_STATE_str_state_dma(data)                                             (0x000F0000&((data)<<16))
#define AE_SRC_STATE_str_state_dma_src(data)                                         ((0x000F0000&(data))>>16)
#define AE_SRC_STATE_get_str_state_dma(data)                                         ((0x000F0000&(data))>>16)
#define AE_SRC_STATE_dma_state_shift                                                 (8)
#define AE_SRC_STATE_dma_state_mask                                                  (0x00000F00)
#define AE_SRC_STATE_dma_state(data)                                                 (0x00000F00&((data)<<8))
#define AE_SRC_STATE_dma_state_src(data)                                             ((0x00000F00&(data))>>8)
#define AE_SRC_STATE_get_dma_state(data)                                             ((0x00000F00&(data))>>8)
#define AE_SRC_STATE_ctrl_state_shift                                                (0)
#define AE_SRC_STATE_ctrl_state_mask                                                 (0x0000000F)
#define AE_SRC_STATE_ctrl_state(data)                                                (0x0000000F&((data)<<0))
#define AE_SRC_STATE_ctrl_state_src(data)                                            ((0x0000000F&(data))>>0)
#define AE_SRC_STATE_get_ctrl_state(data)                                            ((0x0000000F&(data))>>0)


#define NEW_CTRL                                                                     0x18002160
#define NEW_CTRL_reg_addr                                                            "0xB8002160"
#define NEW_CTRL_reg                                                                 0xB8002160
#define set_NEW_CTRL_reg(data)   (*((volatile unsigned int*) NEW_CTRL_reg)=data)
#define get_NEW_CTRL_reg   (*((volatile unsigned int*) NEW_CTRL_reg))
#define NEW_CTRL_inst_adr                                                            "0x0058"
#define NEW_CTRL_inst                                                                0x0058
#define NEW_CTRL_acc_sel_stg1_shift                                                  (24)
#define NEW_CTRL_acc_sel_stg1_mask                                                   (0x1F000000)
#define NEW_CTRL_acc_sel_stg1(data)                                                  (0x1F000000&((data)<<24))
#define NEW_CTRL_acc_sel_stg1_src(data)                                              ((0x1F000000&(data))>>24)
#define NEW_CTRL_get_acc_sel_stg1(data)                                              ((0x1F000000&(data))>>24)
#define NEW_CTRL_acc_sel_stg2_shift                                                  (16)
#define NEW_CTRL_acc_sel_stg2_mask                                                   (0x001F0000)
#define NEW_CTRL_acc_sel_stg2(data)                                                  (0x001F0000&((data)<<16))
#define NEW_CTRL_acc_sel_stg2_src(data)                                              ((0x001F0000&(data))>>16)
#define NEW_CTRL_get_acc_sel_stg2(data)                                              ((0x001F0000&(data))>>16)
#define NEW_CTRL_in_load_num_shift                                                   (0)
#define NEW_CTRL_in_load_num_mask                                                    (0x000003FF)
#define NEW_CTRL_in_load_num(data)                                                   (0x000003FF&((data)<<0))
#define NEW_CTRL_in_load_num_src(data)                                               ((0x000003FF&(data))>>0)
#define NEW_CTRL_get_in_load_num(data)                                               ((0x000003FF&(data))>>0)


#define AE_SRC_RST                                                                   0x18002164
#define AE_SRC_RST_reg_addr                                                          "0xB8002164"
#define AE_SRC_RST_reg                                                               0xB8002164
#define set_AE_SRC_RST_reg(data)   (*((volatile unsigned int*) AE_SRC_RST_reg)=data)
#define get_AE_SRC_RST_reg   (*((volatile unsigned int*) AE_SRC_RST_reg))
#define AE_SRC_RST_inst_adr                                                          "0x0059"
#define AE_SRC_RST_inst                                                              0x0059
#define AE_SRC_RST_rst_shift                                                         (0)
#define AE_SRC_RST_rst_mask                                                          (0x00000001)
#define AE_SRC_RST_rst(data)                                                         (0x00000001&((data)<<0))
#define AE_SRC_RST_rst_src(data)                                                     ((0x00000001&(data))>>0)
#define AE_SRC_RST_get_rst(data)                                                     ((0x00000001&(data))>>0)


#define SRC_FLEX_FLT_0                                                               0x18002168
#define SRC_FLEX_FLT_0_reg_addr                                                      "0xB8002168"
#define SRC_FLEX_FLT_0_reg                                                           0xB8002168
#define set_SRC_FLEX_FLT_0_reg(data)   (*((volatile unsigned int*) SRC_FLEX_FLT_0_reg)=data)
#define get_SRC_FLEX_FLT_0_reg   (*((volatile unsigned int*) SRC_FLEX_FLT_0_reg))
#define SRC_FLEX_FLT_0_inst_adr                                                      "0x005A"
#define SRC_FLEX_FLT_0_inst                                                          0x005A
#define SRC_FLEX_FLT_0_enable_shift                                                  (0)
#define SRC_FLEX_FLT_0_enable_mask                                                   (0x00000001)
#define SRC_FLEX_FLT_0_enable(data)                                                  (0x00000001&((data)<<0))
#define SRC_FLEX_FLT_0_enable_src(data)                                              ((0x00000001&(data))>>0)
#define SRC_FLEX_FLT_0_get_enable(data)                                              ((0x00000001&(data))>>0)


#define SRC_FLEX_FLT_1                                                               0x1800216c
#define SRC_FLEX_FLT_1_reg_addr                                                      "0xB800216C"
#define SRC_FLEX_FLT_1_reg                                                           0xB800216C
#define set_SRC_FLEX_FLT_1_reg(data)   (*((volatile unsigned int*) SRC_FLEX_FLT_1_reg)=data)
#define get_SRC_FLEX_FLT_1_reg   (*((volatile unsigned int*) SRC_FLEX_FLT_1_reg))
#define SRC_FLEX_FLT_1_inst_adr                                                      "0x005B"
#define SRC_FLEX_FLT_1_inst                                                          0x005B
#define SRC_FLEX_FLT_1_tap1_num_shift                                                (0)
#define SRC_FLEX_FLT_1_tap1_num_mask                                                 (0x000003FF)
#define SRC_FLEX_FLT_1_tap1_num(data)                                                (0x000003FF&((data)<<0))
#define SRC_FLEX_FLT_1_tap1_num_src(data)                                            ((0x000003FF&(data))>>0)
#define SRC_FLEX_FLT_1_get_tap1_num(data)                                            ((0x000003FF&(data))>>0)


#define SRC_FLEX_FLT_1                                                               0x18002170
#define SRC_FLEX_FLT_1_reg_addr                                                      "0xB8002170"
#define SRC_FLEX_FLT_1_reg                                                           0xB8002170
#define set_SRC_FLEX_FLT_1_reg(data)   (*((volatile unsigned int*) SRC_FLEX_FLT_1_reg)=data)
#define get_SRC_FLEX_FLT_1_reg   (*((volatile unsigned int*) SRC_FLEX_FLT_1_reg))
#define SRC_FLEX_FLT_1_inst_adr                                                      "0x005C"
#define SRC_FLEX_FLT_1_inst                                                          0x005C
#define SRC_FLEX_FLT_1_rate_down_1_shift                                             (16)
#define SRC_FLEX_FLT_1_rate_down_1_mask                                              (0x000F0000)
#define SRC_FLEX_FLT_1_rate_down_1(data)                                             (0x000F0000&((data)<<16))
#define SRC_FLEX_FLT_1_rate_down_1_src(data)                                         ((0x000F0000&(data))>>16)
#define SRC_FLEX_FLT_1_get_rate_down_1(data)                                         ((0x000F0000&(data))>>16)
#define SRC_FLEX_FLT_1_rate_down_0_shift                                             (8)
#define SRC_FLEX_FLT_1_rate_down_0_mask                                              (0x00007F00)
#define SRC_FLEX_FLT_1_rate_down_0(data)                                             (0x00007F00&((data)<<8))
#define SRC_FLEX_FLT_1_rate_down_0_src(data)                                         ((0x00007F00&(data))>>8)
#define SRC_FLEX_FLT_1_get_rate_down_0(data)                                         ((0x00007F00&(data))>>8)
#define SRC_FLEX_FLT_1_rate_up_shift                                                 (0)
#define SRC_FLEX_FLT_1_rate_up_mask                                                  (0x000000FF)
#define SRC_FLEX_FLT_1_rate_up(data)                                                 (0x000000FF&((data)<<0))
#define SRC_FLEX_FLT_1_rate_up_src(data)                                             ((0x000000FF&(data))>>0)
#define SRC_FLEX_FLT_1_get_rate_up(data)                                             ((0x000000FF&(data))>>0)


#define MBIST_ACPU                                                                   0x18002200
#define MBIST_ACPU_reg_addr                                                          "0xB8002200"
#define MBIST_ACPU_reg                                                               0xB8002200
#define set_MBIST_ACPU_reg(data)   (*((volatile unsigned int*) MBIST_ACPU_reg)=data)
#define get_MBIST_ACPU_reg   (*((volatile unsigned int*) MBIST_ACPU_reg))
#define MBIST_ACPU_inst_adr                                                          "0x0080"
#define MBIST_ACPU_inst                                                              0x0080
#define MBIST_ACPU_ls_acpu_shift                                                     (25)
#define MBIST_ACPU_ls_acpu_mask                                                      (0x02000000)
#define MBIST_ACPU_ls_acpu(data)                                                     (0x02000000&((data)<<25))
#define MBIST_ACPU_ls_acpu_src(data)                                                 ((0x02000000&(data))>>25)
#define MBIST_ACPU_get_ls_acpu(data)                                                 ((0x02000000&(data))>>25)
#define MBIST_ACPU_rme_acpu_shift                                                    (24)
#define MBIST_ACPU_rme_acpu_mask                                                     (0x01000000)
#define MBIST_ACPU_rme_acpu(data)                                                    (0x01000000&((data)<<24))
#define MBIST_ACPU_rme_acpu_src(data)                                                ((0x01000000&(data))>>24)
#define MBIST_ACPU_get_rme_acpu(data)                                                ((0x01000000&(data))>>24)
#define MBIST_ACPU_rm_dmem_shift                                                     (20)
#define MBIST_ACPU_rm_dmem_mask                                                      (0x00F00000)
#define MBIST_ACPU_rm_dmem(data)                                                     (0x00F00000&((data)<<20))
#define MBIST_ACPU_rm_dmem_src(data)                                                 ((0x00F00000&(data))>>20)
#define MBIST_ACPU_get_rm_dmem(data)                                                 ((0x00F00000&(data))>>20)


#define MBIST_ACPU                                                                   0x18002204
#define MBIST_ACPU_reg_addr                                                          "0xB8002204"
#define MBIST_ACPU_reg                                                               0xB8002204
#define set_MBIST_ACPU_reg(data)   (*((volatile unsigned int*) MBIST_ACPU_reg)=data)
#define get_MBIST_ACPU_reg   (*((volatile unsigned int*) MBIST_ACPU_reg))
#define MBIST_ACPU_inst_adr                                                          "0x0081"
#define MBIST_ACPU_inst                                                              0x0081
#define MBIST_ACPU_rm_dc_tag_shift                                                   (28)
#define MBIST_ACPU_rm_dc_tag_mask                                                    (0xF0000000)
#define MBIST_ACPU_rm_dc_tag(data)                                                   (0xF0000000&((data)<<28))
#define MBIST_ACPU_rm_dc_tag_src(data)                                               ((0xF0000000&(data))>>28)
#define MBIST_ACPU_get_rm_dc_tag(data)                                               ((0xF0000000&(data))>>28)
#define MBIST_ACPU_rm_ic_tag0_shift                                                  (12)
#define MBIST_ACPU_rm_ic_tag0_mask                                                   (0x0000F000)
#define MBIST_ACPU_rm_ic_tag0(data)                                                  (0x0000F000&((data)<<12))
#define MBIST_ACPU_rm_ic_tag0_src(data)                                              ((0x0000F000&(data))>>12)
#define MBIST_ACPU_get_rm_ic_tag0(data)                                              ((0x0000F000&(data))>>12)
#define MBIST_ACPU_rm_ic_tag1_shift                                                  (8)
#define MBIST_ACPU_rm_ic_tag1_mask                                                   (0x00000F00)
#define MBIST_ACPU_rm_ic_tag1(data)                                                  (0x00000F00&((data)<<8))
#define MBIST_ACPU_rm_ic_tag1_src(data)                                              ((0x00000F00&(data))>>8)
#define MBIST_ACPU_get_rm_ic_tag1(data)                                              ((0x00000F00&(data))>>8)


#define MBISR_ACPU                                                                   0x18002208
#define MBISR_ACPU_reg_addr                                                          "0xB8002208"
#define MBISR_ACPU_reg                                                               0xB8002208
#define set_MBISR_ACPU_reg(data)   (*((volatile unsigned int*) MBISR_ACPU_reg)=data)
#define get_MBISR_ACPU_reg   (*((volatile unsigned int*) MBISR_ACPU_reg))
#define MBISR_ACPU_inst_adr                                                          "0x0082"
#define MBISR_ACPU_inst                                                              0x0082
#define MBISR_ACPU_rm_dc_data_shift                                                  (28)
#define MBISR_ACPU_rm_dc_data_mask                                                   (0xF0000000)
#define MBISR_ACPU_rm_dc_data(data)                                                  (0xF0000000&((data)<<28))
#define MBISR_ACPU_rm_dc_data_src(data)                                              ((0xF0000000&(data))>>28)
#define MBISR_ACPU_get_rm_dc_data(data)                                              ((0xF0000000&(data))>>28)
#define MBISR_ACPU_rm_ic_data0_shift                                                 (12)
#define MBISR_ACPU_rm_ic_data0_mask                                                  (0x0000F000)
#define MBISR_ACPU_rm_ic_data0(data)                                                 (0x0000F000&((data)<<12))
#define MBISR_ACPU_rm_ic_data0_src(data)                                             ((0x0000F000&(data))>>12)
#define MBISR_ACPU_get_rm_ic_data0(data)                                             ((0x0000F000&(data))>>12)
#define MBISR_ACPU_rm_ic_data1_shift                                                 (8)
#define MBISR_ACPU_rm_ic_data1_mask                                                  (0x00000F00)
#define MBISR_ACPU_rm_ic_data1(data)                                                 (0x00000F00&((data)<<8))
#define MBISR_ACPU_rm_ic_data1_src(data)                                             ((0x00000F00&(data))>>8)
#define MBISR_ACPU_get_rm_ic_data1(data)                                             ((0x00000F00&(data))>>8)


#define MBIST_ACPU                                                                   0x18002210
#define MBIST_ACPU_reg_addr                                                          "0xB8002210"
#define MBIST_ACPU_reg                                                               0xB8002210
#define set_MBIST_ACPU_reg(data)   (*((volatile unsigned int*) MBIST_ACPU_reg)=data)
#define get_MBIST_ACPU_reg   (*((volatile unsigned int*) MBIST_ACPU_reg))
#define MBIST_ACPU_inst_adr                                                          "0x0084"
#define MBIST_ACPU_inst                                                              0x0084
#define MBIST_ACPU_acpu_bist_mode_shift                                              (0)
#define MBIST_ACPU_acpu_bist_mode_mask                                               (0x00000001)
#define MBIST_ACPU_acpu_bist_mode(data)                                              (0x00000001&((data)<<0))
#define MBIST_ACPU_acpu_bist_mode_src(data)                                          ((0x00000001&(data))>>0)
#define MBIST_ACPU_get_acpu_bist_mode(data)                                          ((0x00000001&(data))>>0)


#define MBIST_ACPU                                                                   0x18002214
#define MBIST_ACPU_reg_addr                                                          "0xB8002214"
#define MBIST_ACPU_reg                                                               0xB8002214
#define set_MBIST_ACPU_reg(data)   (*((volatile unsigned int*) MBIST_ACPU_reg)=data)
#define get_MBIST_ACPU_reg   (*((volatile unsigned int*) MBIST_ACPU_reg))
#define MBIST_ACPU_inst_adr                                                          "0x0085"
#define MBIST_ACPU_inst                                                              0x0085
#define MBIST_ACPU_acpu_bist_done_shift                                              (0)
#define MBIST_ACPU_acpu_bist_done_mask                                               (0x00000001)
#define MBIST_ACPU_acpu_bist_done(data)                                              (0x00000001&((data)<<0))
#define MBIST_ACPU_acpu_bist_done_src(data)                                          ((0x00000001&(data))>>0)
#define MBIST_ACPU_get_acpu_bist_done(data)                                          ((0x00000001&(data))>>0)


#define MBIST_ACPU                                                                   0x18002218
#define MBIST_ACPU_reg_addr                                                          "0xB8002218"
#define MBIST_ACPU_reg                                                               0xB8002218
#define set_MBIST_ACPU_reg(data)   (*((volatile unsigned int*) MBIST_ACPU_reg)=data)
#define get_MBIST_ACPU_reg   (*((volatile unsigned int*) MBIST_ACPU_reg))
#define MBIST_ACPU_inst_adr                                                          "0x0086"
#define MBIST_ACPU_inst                                                              0x0086
#define MBIST_ACPU_acpu_bist_fail_group_shift                                        (0)
#define MBIST_ACPU_acpu_bist_fail_group_mask                                         (0x00000001)
#define MBIST_ACPU_acpu_bist_fail_group(data)                                        (0x00000001&((data)<<0))
#define MBIST_ACPU_acpu_bist_fail_group_src(data)                                    ((0x00000001&(data))>>0)
#define MBIST_ACPU_get_acpu_bist_fail_group(data)                                    ((0x00000001&(data))>>0)


#define MBIST_ACPU                                                                   0x1800221C
#define MBIST_ACPU_reg_addr                                                          "0xB800221C"
#define MBIST_ACPU_reg                                                               0xB800221C
#define set_MBIST_ACPU_reg(data)   (*((volatile unsigned int*) MBIST_ACPU_reg)=data)
#define get_MBIST_ACPU_reg   (*((volatile unsigned int*) MBIST_ACPU_reg))
#define MBIST_ACPU_inst_adr                                                          "0x0087"
#define MBIST_ACPU_inst                                                              0x0087
#define MBIST_ACPU_bist_fail2_shift                                                  (2)
#define MBIST_ACPU_bist_fail2_mask                                                   (0x00000004)
#define MBIST_ACPU_bist_fail2(data)                                                  (0x00000004&((data)<<2))
#define MBIST_ACPU_bist_fail2_src(data)                                              ((0x00000004&(data))>>2)
#define MBIST_ACPU_get_bist_fail2(data)                                              ((0x00000004&(data))>>2)
#define MBIST_ACPU_bist_fail1_shift                                                  (1)
#define MBIST_ACPU_bist_fail1_mask                                                   (0x00000002)
#define MBIST_ACPU_bist_fail1(data)                                                  (0x00000002&((data)<<1))
#define MBIST_ACPU_bist_fail1_src(data)                                              ((0x00000002&(data))>>1)
#define MBIST_ACPU_get_bist_fail1(data)                                              ((0x00000002&(data))>>1)
#define MBIST_ACPU_bist_fail0_shift                                                  (0)
#define MBIST_ACPU_bist_fail0_mask                                                   (0x00000001)
#define MBIST_ACPU_bist_fail0(data)                                                  (0x00000001&((data)<<0))
#define MBIST_ACPU_bist_fail0_src(data)                                              ((0x00000001&(data))>>0)
#define MBIST_ACPU_get_bist_fail0(data)                                              ((0x00000001&(data))>>0)


#define MBIST_ACPU                                                                   0x18002220
#define MBIST_ACPU_reg_addr                                                          "0xB8002220"
#define MBIST_ACPU_reg                                                               0xB8002220
#define set_MBIST_ACPU_reg(data)   (*((volatile unsigned int*) MBIST_ACPU_reg)=data)
#define get_MBIST_ACPU_reg   (*((volatile unsigned int*) MBIST_ACPU_reg))
#define MBIST_ACPU_inst_adr                                                          "0x0088"
#define MBIST_ACPU_inst                                                              0x0088
#define MBIST_ACPU_drf_mode_shift                                                    (0)
#define MBIST_ACPU_drf_mode_mask                                                     (0x00000001)
#define MBIST_ACPU_drf_mode(data)                                                    (0x00000001&((data)<<0))
#define MBIST_ACPU_drf_mode_src(data)                                                ((0x00000001&(data))>>0)
#define MBIST_ACPU_get_drf_mode(data)                                                ((0x00000001&(data))>>0)


#define MBIST_ACPU                                                                   0x18002224
#define MBIST_ACPU_reg_addr                                                          "0xB8002224"
#define MBIST_ACPU_reg                                                               0xB8002224
#define set_MBIST_ACPU_reg(data)   (*((volatile unsigned int*) MBIST_ACPU_reg)=data)
#define get_MBIST_ACPU_reg   (*((volatile unsigned int*) MBIST_ACPU_reg))
#define MBIST_ACPU_inst_adr                                                          "0x0089"
#define MBIST_ACPU_inst                                                              0x0089
#define MBIST_ACPU_drf_resume_shift                                                  (0)
#define MBIST_ACPU_drf_resume_mask                                                   (0x00000001)
#define MBIST_ACPU_drf_resume(data)                                                  (0x00000001&((data)<<0))
#define MBIST_ACPU_drf_resume_src(data)                                              ((0x00000001&(data))>>0)
#define MBIST_ACPU_get_drf_resume(data)                                              ((0x00000001&(data))>>0)


#define MBIST_ACPU                                                                   0x18002228
#define MBIST_ACPU_reg_addr                                                          "0xB8002228"
#define MBIST_ACPU_reg                                                               0xB8002228
#define set_MBIST_ACPU_reg(data)   (*((volatile unsigned int*) MBIST_ACPU_reg)=data)
#define get_MBIST_ACPU_reg   (*((volatile unsigned int*) MBIST_ACPU_reg))
#define MBIST_ACPU_inst_adr                                                          "0x008A"
#define MBIST_ACPU_inst                                                              0x008A
#define MBIST_ACPU_drf_done_shift                                                    (0)
#define MBIST_ACPU_drf_done_mask                                                     (0x00000001)
#define MBIST_ACPU_drf_done(data)                                                    (0x00000001&((data)<<0))
#define MBIST_ACPU_drf_done_src(data)                                                ((0x00000001&(data))>>0)
#define MBIST_ACPU_get_drf_done(data)                                                ((0x00000001&(data))>>0)


#define MBIST_ACPU                                                                   0x1800222C
#define MBIST_ACPU_reg_addr                                                          "0xB800222C"
#define MBIST_ACPU_reg                                                               0xB800222C
#define set_MBIST_ACPU_reg(data)   (*((volatile unsigned int*) MBIST_ACPU_reg)=data)
#define get_MBIST_ACPU_reg   (*((volatile unsigned int*) MBIST_ACPU_reg))
#define MBIST_ACPU_inst_adr                                                          "0x008B"
#define MBIST_ACPU_inst                                                              0x008B
#define MBIST_ACPU_drf_pause_shift                                                   (0)
#define MBIST_ACPU_drf_pause_mask                                                    (0x00000001)
#define MBIST_ACPU_drf_pause(data)                                                   (0x00000001&((data)<<0))
#define MBIST_ACPU_drf_pause_src(data)                                               ((0x00000001&(data))>>0)
#define MBIST_ACPU_get_drf_pause(data)                                               ((0x00000001&(data))>>0)


#define MBIST_ACPU                                                                   0x18002230
#define MBIST_ACPU_reg_addr                                                          "0xB8002230"
#define MBIST_ACPU_reg                                                               0xB8002230
#define set_MBIST_ACPU_reg(data)   (*((volatile unsigned int*) MBIST_ACPU_reg)=data)
#define get_MBIST_ACPU_reg   (*((volatile unsigned int*) MBIST_ACPU_reg))
#define MBIST_ACPU_inst_adr                                                          "0x008C"
#define MBIST_ACPU_inst                                                              0x008C
#define MBIST_ACPU_drf_fail_group_shift                                              (0)
#define MBIST_ACPU_drf_fail_group_mask                                               (0x00000001)
#define MBIST_ACPU_drf_fail_group(data)                                              (0x00000001&((data)<<0))
#define MBIST_ACPU_drf_fail_group_src(data)                                          ((0x00000001&(data))>>0)
#define MBIST_ACPU_get_drf_fail_group(data)                                          ((0x00000001&(data))>>0)


#define MBIST_ACPU                                                                   0x18002234
#define MBIST_ACPU_reg_addr                                                          "0xB8002234"
#define MBIST_ACPU_reg                                                               0xB8002234
#define set_MBIST_ACPU_reg(data)   (*((volatile unsigned int*) MBIST_ACPU_reg)=data)
#define get_MBIST_ACPU_reg   (*((volatile unsigned int*) MBIST_ACPU_reg))
#define MBIST_ACPU_inst_adr                                                          "0x008D"
#define MBIST_ACPU_inst                                                              0x008D
#define MBIST_ACPU_drf_fail2_shift                                                   (2)
#define MBIST_ACPU_drf_fail2_mask                                                    (0x00000004)
#define MBIST_ACPU_drf_fail2(data)                                                   (0x00000004&((data)<<2))
#define MBIST_ACPU_drf_fail2_src(data)                                               ((0x00000004&(data))>>2)
#define MBIST_ACPU_get_drf_fail2(data)                                               ((0x00000004&(data))>>2)
#define MBIST_ACPU_drf_fail1_shift                                                   (1)
#define MBIST_ACPU_drf_fail1_mask                                                    (0x00000002)
#define MBIST_ACPU_drf_fail1(data)                                                   (0x00000002&((data)<<1))
#define MBIST_ACPU_drf_fail1_src(data)                                               ((0x00000002&(data))>>1)
#define MBIST_ACPU_get_drf_fail1(data)                                               ((0x00000002&(data))>>1)
#define MBIST_ACPU_drf_fail0_shift                                                   (0)
#define MBIST_ACPU_drf_fail0_mask                                                    (0x00000001)
#define MBIST_ACPU_drf_fail0(data)                                                   (0x00000001&((data)<<0))
#define MBIST_ACPU_drf_fail0_src(data)                                               ((0x00000001&(data))>>0)
#define MBIST_ACPU_get_drf_fail0(data)                                               ((0x00000001&(data))>>0)


#define MBISR_ACPU                                                                   0x18002238
#define MBISR_ACPU_reg_addr                                                          "0xB8002238"
#define MBISR_ACPU_reg                                                               0xB8002238
#define set_MBISR_ACPU_reg(data)   (*((volatile unsigned int*) MBISR_ACPU_reg)=data)
#define get_MBISR_ACPU_reg   (*((volatile unsigned int*) MBISR_ACPU_reg))
#define MBISR_ACPU_inst_adr                                                          "0x008E"
#define MBISR_ACPU_inst                                                              0x008E
#define MBISR_ACPU_second_run_en_shift                                               (0)
#define MBISR_ACPU_second_run_en_mask                                                (0x00000001)
#define MBISR_ACPU_second_run_en(data)                                               (0x00000001&((data)<<0))
#define MBISR_ACPU_second_run_en_src(data)                                           ((0x00000001&(data))>>0)
#define MBISR_ACPU_get_second_run_en(data)                                           ((0x00000001&(data))>>0)


#define MBISR_ACPU                                                                   0x1800223C
#define MBISR_ACPU_reg_addr                                                          "0xB800223C"
#define MBISR_ACPU_reg                                                               0xB800223C
#define set_MBISR_ACPU_reg(data)   (*((volatile unsigned int*) MBISR_ACPU_reg)=data)
#define get_MBISR_ACPU_reg   (*((volatile unsigned int*) MBISR_ACPU_reg))
#define MBISR_ACPU_inst_adr                                                          "0x008F"
#define MBISR_ACPU_inst                                                              0x008F
#define MBISR_ACPU_fail_group_shift                                                  (0)
#define MBISR_ACPU_fail_group_mask                                                   (0x00000001)
#define MBISR_ACPU_fail_group(data)                                                  (0x00000001&((data)<<0))
#define MBISR_ACPU_fail_group_src(data)                                              ((0x00000001&(data))>>0)
#define MBISR_ACPU_get_fail_group(data)                                              ((0x00000001&(data))>>0)


#define MBISR_ACPU                                                                   0x18002240
#define MBISR_ACPU_reg_addr                                                          "0xB8002240"
#define MBISR_ACPU_reg                                                               0xB8002240
#define set_MBISR_ACPU_reg(data)   (*((volatile unsigned int*) MBISR_ACPU_reg)=data)
#define get_MBISR_ACPU_reg   (*((volatile unsigned int*) MBISR_ACPU_reg))
#define MBISR_ACPU_inst_adr                                                          "0x0090"
#define MBISR_ACPU_inst                                                              0x0090
#define MBISR_ACPU_bisr_fail_3_shift                                                 (3)
#define MBISR_ACPU_bisr_fail_3_mask                                                  (0x00000008)
#define MBISR_ACPU_bisr_fail_3(data)                                                 (0x00000008&((data)<<3))
#define MBISR_ACPU_bisr_fail_3_src(data)                                             ((0x00000008&(data))>>3)
#define MBISR_ACPU_get_bisr_fail_3(data)                                             ((0x00000008&(data))>>3)
#define MBISR_ACPU_bisr_fail_2_shift                                                 (2)
#define MBISR_ACPU_bisr_fail_2_mask                                                  (0x00000004)
#define MBISR_ACPU_bisr_fail_2(data)                                                 (0x00000004&((data)<<2))
#define MBISR_ACPU_bisr_fail_2_src(data)                                             ((0x00000004&(data))>>2)
#define MBISR_ACPU_get_bisr_fail_2(data)                                             ((0x00000004&(data))>>2)
#define MBISR_ACPU_bisr_fail_1_shift                                                 (1)
#define MBISR_ACPU_bisr_fail_1_mask                                                  (0x00000002)
#define MBISR_ACPU_bisr_fail_1(data)                                                 (0x00000002&((data)<<1))
#define MBISR_ACPU_bisr_fail_1_src(data)                                             ((0x00000002&(data))>>1)
#define MBISR_ACPU_get_bisr_fail_1(data)                                             ((0x00000002&(data))>>1)
#define MBISR_ACPU_bisr_fail_0_shift                                                 (0)
#define MBISR_ACPU_bisr_fail_0_mask                                                  (0x00000001)
#define MBISR_ACPU_bisr_fail_0(data)                                                 (0x00000001&((data)<<0))
#define MBISR_ACPU_bisr_fail_0_src(data)                                             ((0x00000001&(data))>>0)
#define MBISR_ACPU_get_bisr_fail_0(data)                                             ((0x00000001&(data))>>0)


#define MBISR_ACPU                                                                   0x18002244
#define MBISR_ACPU_reg_addr                                                          "0xB8002244"
#define MBISR_ACPU_reg                                                               0xB8002244
#define set_MBISR_ACPU_reg(data)   (*((volatile unsigned int*) MBISR_ACPU_reg)=data)
#define get_MBISR_ACPU_reg   (*((volatile unsigned int*) MBISR_ACPU_reg))
#define MBISR_ACPU_inst_adr                                                          "0x0091"
#define MBISR_ACPU_inst                                                              0x0091
#define MBISR_ACPU_drf_mode_shift                                                    (0)
#define MBISR_ACPU_drf_mode_mask                                                     (0x00000001)
#define MBISR_ACPU_drf_mode(data)                                                    (0x00000001&((data)<<0))
#define MBISR_ACPU_drf_mode_src(data)                                                ((0x00000001&(data))>>0)
#define MBISR_ACPU_get_drf_mode(data)                                                ((0x00000001&(data))>>0)


#define MBISR_ACPU                                                                   0x18002248
#define MBISR_ACPU_reg_addr                                                          "0xB8002248"
#define MBISR_ACPU_reg                                                               0xB8002248
#define set_MBISR_ACPU_reg(data)   (*((volatile unsigned int*) MBISR_ACPU_reg)=data)
#define get_MBISR_ACPU_reg   (*((volatile unsigned int*) MBISR_ACPU_reg))
#define MBISR_ACPU_inst_adr                                                          "0x0092"
#define MBISR_ACPU_inst                                                              0x0092
#define MBISR_ACPU_drf_resume_shift                                                  (0)
#define MBISR_ACPU_drf_resume_mask                                                   (0x00000001)
#define MBISR_ACPU_drf_resume(data)                                                  (0x00000001&((data)<<0))
#define MBISR_ACPU_drf_resume_src(data)                                              ((0x00000001&(data))>>0)
#define MBISR_ACPU_get_drf_resume(data)                                              ((0x00000001&(data))>>0)


#define MBISR_ACPU                                                                   0x1800224C
#define MBISR_ACPU_reg_addr                                                          "0xB800224C"
#define MBISR_ACPU_reg                                                               0xB800224C
#define set_MBISR_ACPU_reg(data)   (*((volatile unsigned int*) MBISR_ACPU_reg)=data)
#define get_MBISR_ACPU_reg   (*((volatile unsigned int*) MBISR_ACPU_reg))
#define MBISR_ACPU_inst_adr                                                          "0x0093"
#define MBISR_ACPU_inst                                                              0x0093
#define MBISR_ACPU_drf_done_shift                                                    (0)
#define MBISR_ACPU_drf_done_mask                                                     (0x00000001)
#define MBISR_ACPU_drf_done(data)                                                    (0x00000001&((data)<<0))
#define MBISR_ACPU_drf_done_src(data)                                                ((0x00000001&(data))>>0)
#define MBISR_ACPU_get_drf_done(data)                                                ((0x00000001&(data))>>0)


#define MBISR_ACPU                                                                   0x18002250
#define MBISR_ACPU_reg_addr                                                          "0xB8002250"
#define MBISR_ACPU_reg                                                               0xB8002250
#define set_MBISR_ACPU_reg(data)   (*((volatile unsigned int*) MBISR_ACPU_reg)=data)
#define get_MBISR_ACPU_reg   (*((volatile unsigned int*) MBISR_ACPU_reg))
#define MBISR_ACPU_inst_adr                                                          "0x0094"
#define MBISR_ACPU_inst                                                              0x0094
#define MBISR_ACPU_drf_fail_group_shift                                              (0)
#define MBISR_ACPU_drf_fail_group_mask                                               (0x00000001)
#define MBISR_ACPU_drf_fail_group(data)                                              (0x00000001&((data)<<0))
#define MBISR_ACPU_drf_fail_group_src(data)                                          ((0x00000001&(data))>>0)
#define MBISR_ACPU_get_drf_fail_group(data)                                          ((0x00000001&(data))>>0)


#define MBISR_ACPU                                                                   0x18002254
#define MBISR_ACPU_reg_addr                                                          "0xB8002254"
#define MBISR_ACPU_reg                                                               0xB8002254
#define set_MBISR_ACPU_reg(data)   (*((volatile unsigned int*) MBISR_ACPU_reg)=data)
#define get_MBISR_ACPU_reg   (*((volatile unsigned int*) MBISR_ACPU_reg))
#define MBISR_ACPU_inst_adr                                                          "0x0095"
#define MBISR_ACPU_inst                                                              0x0095
#define MBISR_ACPU_drf_pause_shift                                                   (0)
#define MBISR_ACPU_drf_pause_mask                                                    (0x00000001)
#define MBISR_ACPU_drf_pause(data)                                                   (0x00000001&((data)<<0))
#define MBISR_ACPU_drf_pause_src(data)                                               ((0x00000001&(data))>>0)
#define MBISR_ACPU_get_drf_pause(data)                                               ((0x00000001&(data))>>0)


#define MBISR_ACPU                                                                   0x18002258
#define MBISR_ACPU_reg_addr                                                          "0xB8002258"
#define MBISR_ACPU_reg                                                               0xB8002258
#define set_MBISR_ACPU_reg(data)   (*((volatile unsigned int*) MBISR_ACPU_reg)=data)
#define get_MBISR_ACPU_reg   (*((volatile unsigned int*) MBISR_ACPU_reg))
#define MBISR_ACPU_inst_adr                                                          "0x0096"
#define MBISR_ACPU_inst                                                              0x0096
#define MBISR_ACPU_drf_repaired_shift                                                (31)
#define MBISR_ACPU_drf_repaired_mask                                                 (0x80000000)
#define MBISR_ACPU_drf_repaired(data)                                                (0x80000000&((data)<<31))
#define MBISR_ACPU_drf_repaired_src(data)                                            ((0x80000000&(data))>>31)
#define MBISR_ACPU_get_drf_repaired(data)                                            ((0x80000000&(data))>>31)
#define MBISR_ACPU_drf_fail_3_shift                                                  (3)
#define MBISR_ACPU_drf_fail_3_mask                                                   (0x00000008)
#define MBISR_ACPU_drf_fail_3(data)                                                  (0x00000008&((data)<<3))
#define MBISR_ACPU_drf_fail_3_src(data)                                              ((0x00000008&(data))>>3)
#define MBISR_ACPU_get_drf_fail_3(data)                                              ((0x00000008&(data))>>3)
#define MBISR_ACPU_drf_fail_2_shift                                                  (2)
#define MBISR_ACPU_drf_fail_2_mask                                                   (0x00000004)
#define MBISR_ACPU_drf_fail_2(data)                                                  (0x00000004&((data)<<2))
#define MBISR_ACPU_drf_fail_2_src(data)                                              ((0x00000004&(data))>>2)
#define MBISR_ACPU_get_drf_fail_2(data)                                              ((0x00000004&(data))>>2)
#define MBISR_ACPU_drf_fail_1_shift                                                  (1)
#define MBISR_ACPU_drf_fail_1_mask                                                   (0x00000002)
#define MBISR_ACPU_drf_fail_1(data)                                                  (0x00000002&((data)<<1))
#define MBISR_ACPU_drf_fail_1_src(data)                                              ((0x00000002&(data))>>1)
#define MBISR_ACPU_get_drf_fail_1(data)                                              ((0x00000002&(data))>>1)
#define MBISR_ACPU_drf_fail_0_shift                                                  (0)
#define MBISR_ACPU_drf_fail_0_mask                                                   (0x00000001)
#define MBISR_ACPU_drf_fail_0(data)                                                  (0x00000001&((data)<<0))
#define MBISR_ACPU_drf_fail_0_src(data)                                              ((0x00000001&(data))>>0)
#define MBISR_ACPU_get_drf_fail_0(data)                                              ((0x00000001&(data))>>0)


#define AE_BIST                                                                      0x18002260
#define AE_BIST_reg_addr                                                             "0xB8002260"
#define AE_BIST_reg                                                                  0xB8002260
#define set_AE_BIST_reg(data)   (*((volatile unsigned int*) AE_BIST_reg)=data)
#define get_AE_BIST_reg   (*((volatile unsigned int*) AE_BIST_reg))
#define AE_BIST_inst_adr                                                             "0x0098"
#define AE_BIST_inst                                                                 0x0098
#define AE_BIST_rmeb_aee_shift                                                       (28)
#define AE_BIST_rmeb_aee_mask                                                        (0x10000000)
#define AE_BIST_rmeb_aee(data)                                                       (0x10000000&((data)<<28))
#define AE_BIST_rmeb_aee_src(data)                                                   ((0x10000000&(data))>>28)
#define AE_BIST_get_rmeb_aee(data)                                                   ((0x10000000&(data))>>28)
#define AE_BIST_rmb_aee_shift                                                        (24)
#define AE_BIST_rmb_aee_mask                                                         (0x0F000000)
#define AE_BIST_rmb_aee(data)                                                        (0x0F000000&((data)<<24))
#define AE_BIST_rmb_aee_src(data)                                                    ((0x0F000000&(data))>>24)
#define AE_BIST_get_rmb_aee(data)                                                    ((0x0F000000&(data))>>24)
#define AE_BIST_rmea_aee_shift                                                       (20)
#define AE_BIST_rmea_aee_mask                                                        (0x00100000)
#define AE_BIST_rmea_aee(data)                                                       (0x00100000&((data)<<20))
#define AE_BIST_rmea_aee_src(data)                                                   ((0x00100000&(data))>>20)
#define AE_BIST_get_rmea_aee(data)                                                   ((0x00100000&(data))>>20)
#define AE_BIST_rma_aee_shift                                                        (16)
#define AE_BIST_rma_aee_mask                                                         (0x000F0000)
#define AE_BIST_rma_aee(data)                                                        (0x000F0000&((data)<<16))
#define AE_BIST_rma_aee_src(data)                                                    ((0x000F0000&(data))>>16)
#define AE_BIST_get_rma_aee(data)                                                    ((0x000F0000&(data))>>16)
#define AE_BIST_rmeb_ade_shift                                                       (12)
#define AE_BIST_rmeb_ade_mask                                                        (0x00001000)
#define AE_BIST_rmeb_ade(data)                                                       (0x00001000&((data)<<12))
#define AE_BIST_rmeb_ade_src(data)                                                   ((0x00001000&(data))>>12)
#define AE_BIST_get_rmeb_ade(data)                                                   ((0x00001000&(data))>>12)
#define AE_BIST_rmb_ade_shift                                                        (8)
#define AE_BIST_rmb_ade_mask                                                         (0x00000F00)
#define AE_BIST_rmb_ade(data)                                                        (0x00000F00&((data)<<8))
#define AE_BIST_rmb_ade_src(data)                                                    ((0x00000F00&(data))>>8)
#define AE_BIST_get_rmb_ade(data)                                                    ((0x00000F00&(data))>>8)
#define AE_BIST_rmea_ade_shift                                                       (4)
#define AE_BIST_rmea_ade_mask                                                        (0x00000010)
#define AE_BIST_rmea_ade(data)                                                       (0x00000010&((data)<<4))
#define AE_BIST_rmea_ade_src(data)                                                   ((0x00000010&(data))>>4)
#define AE_BIST_get_rmea_ade(data)                                                   ((0x00000010&(data))>>4)
#define AE_BIST_rma_ade_shift                                                        (0)
#define AE_BIST_rma_ade_mask                                                         (0x0000000F)
#define AE_BIST_rma_ade(data)                                                        (0x0000000F&((data)<<0))
#define AE_BIST_rma_ade_src(data)                                                    ((0x0000000F&(data))>>0)
#define AE_BIST_get_rma_ade(data)                                                    ((0x0000000F&(data))>>0)


#define AE_BIST                                                                      0x18002264
#define AE_BIST_reg_addr                                                             "0xB8002264"
#define AE_BIST_reg                                                                  0xB8002264
#define set_AE_BIST_reg(data)   (*((volatile unsigned int*) AE_BIST_reg)=data)
#define get_AE_BIST_reg   (*((volatile unsigned int*) AE_BIST_reg))
#define AE_BIST_inst_adr                                                             "0x0099"
#define AE_BIST_inst                                                                 0x0099
#define AE_BIST_rme_src_coef_shift                                                   (28)
#define AE_BIST_rme_src_coef_mask                                                    (0x10000000)
#define AE_BIST_rme_src_coef(data)                                                   (0x10000000&((data)<<28))
#define AE_BIST_rme_src_coef_src(data)                                               ((0x10000000&(data))>>28)
#define AE_BIST_get_rme_src_coef(data)                                               ((0x10000000&(data))>>28)
#define AE_BIST_rm_src_coef_shift                                                    (24)
#define AE_BIST_rm_src_coef_mask                                                     (0x0F000000)
#define AE_BIST_rm_src_coef(data)                                                    (0x0F000000&((data)<<24))
#define AE_BIST_rm_src_coef_src(data)                                                ((0x0F000000&(data))>>24)
#define AE_BIST_get_rm_src_coef(data)                                                ((0x0F000000&(data))>>24)
#define AE_BIST_rme_src_dat_shift                                                    (20)
#define AE_BIST_rme_src_dat_mask                                                     (0x00100000)
#define AE_BIST_rme_src_dat(data)                                                    (0x00100000&((data)<<20))
#define AE_BIST_rme_src_dat_src(data)                                                ((0x00100000&(data))>>20)
#define AE_BIST_get_rme_src_dat(data)                                                ((0x00100000&(data))>>20)
#define AE_BIST_rm_src_dat_shift                                                     (16)
#define AE_BIST_rm_src_dat_mask                                                      (0x000F0000)
#define AE_BIST_rm_src_dat(data)                                                     (0x000F0000&((data)<<16))
#define AE_BIST_rm_src_dat_src(data)                                                 ((0x000F0000&(data))>>16)
#define AE_BIST_get_rm_src_dat(data)                                                 ((0x000F0000&(data))>>16)
#define AE_BIST_rmeb_src_rwbuf_shift                                                 (12)
#define AE_BIST_rmeb_src_rwbuf_mask                                                  (0x00001000)
#define AE_BIST_rmeb_src_rwbuf(data)                                                 (0x00001000&((data)<<12))
#define AE_BIST_rmeb_src_rwbuf_src(data)                                             ((0x00001000&(data))>>12)
#define AE_BIST_get_rmeb_src_rwbuf(data)                                             ((0x00001000&(data))>>12)
#define AE_BIST_rmb_src_rwbuf_shift                                                  (8)
#define AE_BIST_rmb_src_rwbuf_mask                                                   (0x00000F00)
#define AE_BIST_rmb_src_rwbuf(data)                                                  (0x00000F00&((data)<<8))
#define AE_BIST_rmb_src_rwbuf_src(data)                                              ((0x00000F00&(data))>>8)
#define AE_BIST_get_rmb_src_rwbuf(data)                                              ((0x00000F00&(data))>>8)
#define AE_BIST_rmea_src_rwbuf_shift                                                 (4)
#define AE_BIST_rmea_src_rwbuf_mask                                                  (0x00000010)
#define AE_BIST_rmea_src_rwbuf(data)                                                 (0x00000010&((data)<<4))
#define AE_BIST_rmea_src_rwbuf_src(data)                                             ((0x00000010&(data))>>4)
#define AE_BIST_get_rmea_src_rwbuf(data)                                             ((0x00000010&(data))>>4)
#define AE_BIST_rma_src_rwbuf_shift                                                  (0)
#define AE_BIST_rma_src_rwbuf_mask                                                   (0x0000000F)
#define AE_BIST_rma_src_rwbuf(data)                                                  (0x0000000F&((data)<<0))
#define AE_BIST_rma_src_rwbuf_src(data)                                              ((0x0000000F&(data))>>0)
#define AE_BIST_get_rma_src_rwbuf(data)                                              ((0x0000000F&(data))>>0)


#define AE_BIST                                                                      0x18002268
#define AE_BIST_reg_addr                                                             "0xB8002268"
#define AE_BIST_reg                                                                  0xB8002268
#define set_AE_BIST_reg(data)   (*((volatile unsigned int*) AE_BIST_reg)=data)
#define get_AE_BIST_reg   (*((volatile unsigned int*) AE_BIST_reg))
#define AE_BIST_inst_adr                                                             "0x009A"
#define AE_BIST_inst                                                                 0x009A
#define AE_BIST_mode_src_coef_shift                                                  (4)
#define AE_BIST_mode_src_coef_mask                                                   (0x00000010)
#define AE_BIST_mode_src_coef(data)                                                  (0x00000010&((data)<<4))
#define AE_BIST_mode_src_coef_src(data)                                              ((0x00000010&(data))>>4)
#define AE_BIST_get_mode_src_coef(data)                                              ((0x00000010&(data))>>4)
#define AE_BIST_mode_src_dat_shift                                                   (3)
#define AE_BIST_mode_src_dat_mask                                                    (0x00000008)
#define AE_BIST_mode_src_dat(data)                                                   (0x00000008&((data)<<3))
#define AE_BIST_mode_src_dat_src(data)                                               ((0x00000008&(data))>>3)
#define AE_BIST_get_mode_src_dat(data)                                               ((0x00000008&(data))>>3)
#define AE_BIST_mode_src_rwbuf_shift                                                 (2)
#define AE_BIST_mode_src_rwbuf_mask                                                  (0x00000004)
#define AE_BIST_mode_src_rwbuf(data)                                                 (0x00000004&((data)<<2))
#define AE_BIST_mode_src_rwbuf_src(data)                                             ((0x00000004&(data))>>2)
#define AE_BIST_get_mode_src_rwbuf(data)                                             ((0x00000004&(data))>>2)
#define AE_BIST_mode_aee_shift                                                       (1)
#define AE_BIST_mode_aee_mask                                                        (0x00000002)
#define AE_BIST_mode_aee(data)                                                       (0x00000002&((data)<<1))
#define AE_BIST_mode_aee_src(data)                                                   ((0x00000002&(data))>>1)
#define AE_BIST_get_mode_aee(data)                                                   ((0x00000002&(data))>>1)
#define AE_BIST_mode_ade_shift                                                       (0)
#define AE_BIST_mode_ade_mask                                                        (0x00000001)
#define AE_BIST_mode_ade(data)                                                       (0x00000001&((data)<<0))
#define AE_BIST_mode_ade_src(data)                                                   ((0x00000001&(data))>>0)
#define AE_BIST_get_mode_ade(data)                                                   ((0x00000001&(data))>>0)


#define AE_BIST                                                                      0x1800226c
#define AE_BIST_reg_addr                                                             "0xB800226C"
#define AE_BIST_reg                                                                  0xB800226C
#define set_AE_BIST_reg(data)   (*((volatile unsigned int*) AE_BIST_reg)=data)
#define get_AE_BIST_reg   (*((volatile unsigned int*) AE_BIST_reg))
#define AE_BIST_inst_adr                                                             "0x009B"
#define AE_BIST_inst                                                                 0x009B
#define AE_BIST_done_src_coef_shift                                                  (4)
#define AE_BIST_done_src_coef_mask                                                   (0x00000010)
#define AE_BIST_done_src_coef(data)                                                  (0x00000010&((data)<<4))
#define AE_BIST_done_src_coef_src(data)                                              ((0x00000010&(data))>>4)
#define AE_BIST_get_done_src_coef(data)                                              ((0x00000010&(data))>>4)
#define AE_BIST_done_src_dat_shift                                                   (3)
#define AE_BIST_done_src_dat_mask                                                    (0x00000008)
#define AE_BIST_done_src_dat(data)                                                   (0x00000008&((data)<<3))
#define AE_BIST_done_src_dat_src(data)                                               ((0x00000008&(data))>>3)
#define AE_BIST_get_done_src_dat(data)                                               ((0x00000008&(data))>>3)
#define AE_BIST_done_src_rwbuf_shift                                                 (2)
#define AE_BIST_done_src_rwbuf_mask                                                  (0x00000004)
#define AE_BIST_done_src_rwbuf(data)                                                 (0x00000004&((data)<<2))
#define AE_BIST_done_src_rwbuf_src(data)                                             ((0x00000004&(data))>>2)
#define AE_BIST_get_done_src_rwbuf(data)                                             ((0x00000004&(data))>>2)
#define AE_BIST_done_aee_shift                                                       (1)
#define AE_BIST_done_aee_mask                                                        (0x00000002)
#define AE_BIST_done_aee(data)                                                       (0x00000002&((data)<<1))
#define AE_BIST_done_aee_src(data)                                                   ((0x00000002&(data))>>1)
#define AE_BIST_get_done_aee(data)                                                   ((0x00000002&(data))>>1)
#define AE_BIST_done_ade_shift                                                       (0)
#define AE_BIST_done_ade_mask                                                        (0x00000001)
#define AE_BIST_done_ade(data)                                                       (0x00000001&((data)<<0))
#define AE_BIST_done_ade_src(data)                                                   ((0x00000001&(data))>>0)
#define AE_BIST_get_done_ade(data)                                                   ((0x00000001&(data))>>0)


#define AE_BIST                                                                      0x18002270
#define AE_BIST_reg_addr                                                             "0xB8002270"
#define AE_BIST_reg                                                                  0xB8002270
#define set_AE_BIST_reg(data)   (*((volatile unsigned int*) AE_BIST_reg)=data)
#define get_AE_BIST_reg   (*((volatile unsigned int*) AE_BIST_reg))
#define AE_BIST_inst_adr                                                             "0x009C"
#define AE_BIST_inst                                                                 0x009C
#define AE_BIST_fail_src_coef_shift                                                  (4)
#define AE_BIST_fail_src_coef_mask                                                   (0x00000010)
#define AE_BIST_fail_src_coef(data)                                                  (0x00000010&((data)<<4))
#define AE_BIST_fail_src_coef_src(data)                                              ((0x00000010&(data))>>4)
#define AE_BIST_get_fail_src_coef(data)                                              ((0x00000010&(data))>>4)
#define AE_BIST_fail_src_dat_shift                                                   (3)
#define AE_BIST_fail_src_dat_mask                                                    (0x00000008)
#define AE_BIST_fail_src_dat(data)                                                   (0x00000008&((data)<<3))
#define AE_BIST_fail_src_dat_src(data)                                               ((0x00000008&(data))>>3)
#define AE_BIST_get_fail_src_dat(data)                                               ((0x00000008&(data))>>3)
#define AE_BIST_fail_src_rwbuf_shift                                                 (2)
#define AE_BIST_fail_src_rwbuf_mask                                                  (0x00000004)
#define AE_BIST_fail_src_rwbuf(data)                                                 (0x00000004&((data)<<2))
#define AE_BIST_fail_src_rwbuf_src(data)                                             ((0x00000004&(data))>>2)
#define AE_BIST_get_fail_src_rwbuf(data)                                             ((0x00000004&(data))>>2)
#define AE_BIST_fail_aee_shift                                                       (1)
#define AE_BIST_fail_aee_mask                                                        (0x00000002)
#define AE_BIST_fail_aee(data)                                                       (0x00000002&((data)<<1))
#define AE_BIST_fail_aee_src(data)                                                   ((0x00000002&(data))>>1)
#define AE_BIST_get_fail_aee(data)                                                   ((0x00000002&(data))>>1)
#define AE_BIST_fail_ade_shift                                                       (0)
#define AE_BIST_fail_ade_mask                                                        (0x00000001)
#define AE_BIST_fail_ade(data)                                                       (0x00000001&((data)<<0))
#define AE_BIST_fail_ade_src(data)                                                   ((0x00000001&(data))>>0)
#define AE_BIST_get_fail_ade(data)                                                   ((0x00000001&(data))>>0)


#define AE_DRF                                                                       0x18002274
#define AE_DRF_reg_addr                                                              "0xB8002274"
#define AE_DRF_reg                                                                   0xB8002274
#define set_AE_DRF_reg(data)   (*((volatile unsigned int*) AE_DRF_reg)=data)
#define get_AE_DRF_reg   (*((volatile unsigned int*) AE_DRF_reg))
#define AE_DRF_inst_adr                                                              "0x009D"
#define AE_DRF_inst                                                                  0x009D
#define AE_DRF_mode_src_coef_shift                                                   (4)
#define AE_DRF_mode_src_coef_mask                                                    (0x00000010)
#define AE_DRF_mode_src_coef(data)                                                   (0x00000010&((data)<<4))
#define AE_DRF_mode_src_coef_src(data)                                               ((0x00000010&(data))>>4)
#define AE_DRF_get_mode_src_coef(data)                                               ((0x00000010&(data))>>4)
#define AE_DRF_mode_src_dat_shift                                                    (3)
#define AE_DRF_mode_src_dat_mask                                                     (0x00000008)
#define AE_DRF_mode_src_dat(data)                                                    (0x00000008&((data)<<3))
#define AE_DRF_mode_src_dat_src(data)                                                ((0x00000008&(data))>>3)
#define AE_DRF_get_mode_src_dat(data)                                                ((0x00000008&(data))>>3)
#define AE_DRF_mode_src_rwbuf_shift                                                  (2)
#define AE_DRF_mode_src_rwbuf_mask                                                   (0x00000004)
#define AE_DRF_mode_src_rwbuf(data)                                                  (0x00000004&((data)<<2))
#define AE_DRF_mode_src_rwbuf_src(data)                                              ((0x00000004&(data))>>2)
#define AE_DRF_get_mode_src_rwbuf(data)                                              ((0x00000004&(data))>>2)
#define AE_DRF_mode_aee_shift                                                        (1)
#define AE_DRF_mode_aee_mask                                                         (0x00000002)
#define AE_DRF_mode_aee(data)                                                        (0x00000002&((data)<<1))
#define AE_DRF_mode_aee_src(data)                                                    ((0x00000002&(data))>>1)
#define AE_DRF_get_mode_aee(data)                                                    ((0x00000002&(data))>>1)
#define AE_DRF_mode_ade_shift                                                        (0)
#define AE_DRF_mode_ade_mask                                                         (0x00000001)
#define AE_DRF_mode_ade(data)                                                        (0x00000001&((data)<<0))
#define AE_DRF_mode_ade_src(data)                                                    ((0x00000001&(data))>>0)
#define AE_DRF_get_mode_ade(data)                                                    ((0x00000001&(data))>>0)


#define AE_DRF                                                                       0x18002278
#define AE_DRF_reg_addr                                                              "0xB8002278"
#define AE_DRF_reg                                                                   0xB8002278
#define set_AE_DRF_reg(data)   (*((volatile unsigned int*) AE_DRF_reg)=data)
#define get_AE_DRF_reg   (*((volatile unsigned int*) AE_DRF_reg))
#define AE_DRF_inst_adr                                                              "0x009E"
#define AE_DRF_inst                                                                  0x009E
#define AE_DRF_done_src_coef_shift                                                   (4)
#define AE_DRF_done_src_coef_mask                                                    (0x00000010)
#define AE_DRF_done_src_coef(data)                                                   (0x00000010&((data)<<4))
#define AE_DRF_done_src_coef_src(data)                                               ((0x00000010&(data))>>4)
#define AE_DRF_get_done_src_coef(data)                                               ((0x00000010&(data))>>4)
#define AE_DRF_done_src_dat_shift                                                    (3)
#define AE_DRF_done_src_dat_mask                                                     (0x00000008)
#define AE_DRF_done_src_dat(data)                                                    (0x00000008&((data)<<3))
#define AE_DRF_done_src_dat_src(data)                                                ((0x00000008&(data))>>3)
#define AE_DRF_get_done_src_dat(data)                                                ((0x00000008&(data))>>3)
#define AE_DRF_done_src_rwbuf_shift                                                  (2)
#define AE_DRF_done_src_rwbuf_mask                                                   (0x00000004)
#define AE_DRF_done_src_rwbuf(data)                                                  (0x00000004&((data)<<2))
#define AE_DRF_done_src_rwbuf_src(data)                                              ((0x00000004&(data))>>2)
#define AE_DRF_get_done_src_rwbuf(data)                                              ((0x00000004&(data))>>2)
#define AE_DRF_done_aee_shift                                                        (1)
#define AE_DRF_done_aee_mask                                                         (0x00000002)
#define AE_DRF_done_aee(data)                                                        (0x00000002&((data)<<1))
#define AE_DRF_done_aee_src(data)                                                    ((0x00000002&(data))>>1)
#define AE_DRF_get_done_aee(data)                                                    ((0x00000002&(data))>>1)
#define AE_DRF_done_ade_shift                                                        (0)
#define AE_DRF_done_ade_mask                                                         (0x00000001)
#define AE_DRF_done_ade(data)                                                        (0x00000001&((data)<<0))
#define AE_DRF_done_ade_src(data)                                                    ((0x00000001&(data))>>0)
#define AE_DRF_get_done_ade(data)                                                    ((0x00000001&(data))>>0)


#define AE_DRF                                                                       0x1800227c
#define AE_DRF_reg_addr                                                              "0xB800227C"
#define AE_DRF_reg                                                                   0xB800227C
#define set_AE_DRF_reg(data)   (*((volatile unsigned int*) AE_DRF_reg)=data)
#define get_AE_DRF_reg   (*((volatile unsigned int*) AE_DRF_reg))
#define AE_DRF_inst_adr                                                              "0x009F"
#define AE_DRF_inst                                                                  0x009F
#define AE_DRF_fail_src_coef_shift                                                   (4)
#define AE_DRF_fail_src_coef_mask                                                    (0x00000010)
#define AE_DRF_fail_src_coef(data)                                                   (0x00000010&((data)<<4))
#define AE_DRF_fail_src_coef_src(data)                                               ((0x00000010&(data))>>4)
#define AE_DRF_get_fail_src_coef(data)                                               ((0x00000010&(data))>>4)
#define AE_DRF_fail_src_dat_shift                                                    (3)
#define AE_DRF_fail_src_dat_mask                                                     (0x00000008)
#define AE_DRF_fail_src_dat(data)                                                    (0x00000008&((data)<<3))
#define AE_DRF_fail_src_dat_src(data)                                                ((0x00000008&(data))>>3)
#define AE_DRF_get_fail_src_dat(data)                                                ((0x00000008&(data))>>3)
#define AE_DRF_fail_src_rwbuf_shift                                                  (2)
#define AE_DRF_fail_src_rwbuf_mask                                                   (0x00000004)
#define AE_DRF_fail_src_rwbuf(data)                                                  (0x00000004&((data)<<2))
#define AE_DRF_fail_src_rwbuf_src(data)                                              ((0x00000004&(data))>>2)
#define AE_DRF_get_fail_src_rwbuf(data)                                              ((0x00000004&(data))>>2)
#define AE_DRF_fail_aee_shift                                                        (1)
#define AE_DRF_fail_aee_mask                                                         (0x00000002)
#define AE_DRF_fail_aee(data)                                                        (0x00000002&((data)<<1))
#define AE_DRF_fail_aee_src(data)                                                    ((0x00000002&(data))>>1)
#define AE_DRF_get_fail_aee(data)                                                    ((0x00000002&(data))>>1)
#define AE_DRF_fail_ade_shift                                                        (0)
#define AE_DRF_fail_ade_mask                                                         (0x00000001)
#define AE_DRF_fail_ade(data)                                                        (0x00000001&((data)<<0))
#define AE_DRF_fail_ade_src(data)                                                    ((0x00000001&(data))>>0)
#define AE_DRF_get_fail_ade(data)                                                    ((0x00000001&(data))>>0)


#define AE_DRF                                                                       0x18002280
#define AE_DRF_reg_addr                                                              "0xB8002280"
#define AE_DRF_reg                                                                   0xB8002280
#define set_AE_DRF_reg(data)   (*((volatile unsigned int*) AE_DRF_reg)=data)
#define get_AE_DRF_reg   (*((volatile unsigned int*) AE_DRF_reg))
#define AE_DRF_inst_adr                                                              "0x00A0"
#define AE_DRF_inst                                                                  0x00A0
#define AE_DRF_pause_src_coef_shift                                                  (4)
#define AE_DRF_pause_src_coef_mask                                                   (0x00000010)
#define AE_DRF_pause_src_coef(data)                                                  (0x00000010&((data)<<4))
#define AE_DRF_pause_src_coef_src(data)                                              ((0x00000010&(data))>>4)
#define AE_DRF_get_pause_src_coef(data)                                              ((0x00000010&(data))>>4)
#define AE_DRF_pause_src_dat_shift                                                   (3)
#define AE_DRF_pause_src_dat_mask                                                    (0x00000008)
#define AE_DRF_pause_src_dat(data)                                                   (0x00000008&((data)<<3))
#define AE_DRF_pause_src_dat_src(data)                                               ((0x00000008&(data))>>3)
#define AE_DRF_get_pause_src_dat(data)                                               ((0x00000008&(data))>>3)
#define AE_DRF_pause_src_rwbuf_shift                                                 (2)
#define AE_DRF_pause_src_rwbuf_mask                                                  (0x00000004)
#define AE_DRF_pause_src_rwbuf(data)                                                 (0x00000004&((data)<<2))
#define AE_DRF_pause_src_rwbuf_src(data)                                             ((0x00000004&(data))>>2)
#define AE_DRF_get_pause_src_rwbuf(data)                                             ((0x00000004&(data))>>2)
#define AE_DRF_pause_aee_shift                                                       (1)
#define AE_DRF_pause_aee_mask                                                        (0x00000002)
#define AE_DRF_pause_aee(data)                                                       (0x00000002&((data)<<1))
#define AE_DRF_pause_aee_src(data)                                                   ((0x00000002&(data))>>1)
#define AE_DRF_get_pause_aee(data)                                                   ((0x00000002&(data))>>1)
#define AE_DRF_pause_ade_shift                                                       (0)
#define AE_DRF_pause_ade_mask                                                        (0x00000001)
#define AE_DRF_pause_ade(data)                                                       (0x00000001&((data)<<0))
#define AE_DRF_pause_ade_src(data)                                                   ((0x00000001&(data))>>0)
#define AE_DRF_get_pause_ade(data)                                                   ((0x00000001&(data))>>0)


#define AE_DRF                                                                       0x18002284
#define AE_DRF_reg_addr                                                              "0xB8002284"
#define AE_DRF_reg                                                                   0xB8002284
#define set_AE_DRF_reg(data)   (*((volatile unsigned int*) AE_DRF_reg)=data)
#define get_AE_DRF_reg   (*((volatile unsigned int*) AE_DRF_reg))
#define AE_DRF_inst_adr                                                              "0x00A1"
#define AE_DRF_inst                                                                  0x00A1
#define AE_DRF_resume_src_coef_shift                                                 (4)
#define AE_DRF_resume_src_coef_mask                                                  (0x00000010)
#define AE_DRF_resume_src_coef(data)                                                 (0x00000010&((data)<<4))
#define AE_DRF_resume_src_coef_src(data)                                             ((0x00000010&(data))>>4)
#define AE_DRF_get_resume_src_coef(data)                                             ((0x00000010&(data))>>4)
#define AE_DRF_resume_src_dat_shift                                                  (3)
#define AE_DRF_resume_src_dat_mask                                                   (0x00000008)
#define AE_DRF_resume_src_dat(data)                                                  (0x00000008&((data)<<3))
#define AE_DRF_resume_src_dat_src(data)                                              ((0x00000008&(data))>>3)
#define AE_DRF_get_resume_src_dat(data)                                              ((0x00000008&(data))>>3)
#define AE_DRF_resume_src_rwbuf_shift                                                (2)
#define AE_DRF_resume_src_rwbuf_mask                                                 (0x00000004)
#define AE_DRF_resume_src_rwbuf(data)                                                (0x00000004&((data)<<2))
#define AE_DRF_resume_src_rwbuf_src(data)                                            ((0x00000004&(data))>>2)
#define AE_DRF_get_resume_src_rwbuf(data)                                            ((0x00000004&(data))>>2)
#define AE_DRF_resume_aee_shift                                                      (1)
#define AE_DRF_resume_aee_mask                                                       (0x00000002)
#define AE_DRF_resume_aee(data)                                                      (0x00000002&((data)<<1))
#define AE_DRF_resume_aee_src(data)                                                  ((0x00000002&(data))>>1)
#define AE_DRF_get_resume_aee(data)                                                  ((0x00000002&(data))>>1)
#define AE_DRF_resume_ade_shift                                                      (0)
#define AE_DRF_resume_ade_mask                                                       (0x00000001)
#define AE_DRF_resume_ade(data)                                                      (0x00000001&((data)<<0))
#define AE_DRF_resume_ade_src(data)                                                  ((0x00000001&(data))>>0)
#define AE_DRF_get_resume_ade(data)                                                  ((0x00000001&(data))>>0)


#define AE_BIST                                                                      0x18002288
#define AE_BIST_reg_addr                                                             "0xB8002288"
#define AE_BIST_reg                                                                  0xB8002288
#define set_AE_BIST_reg(data)   (*((volatile unsigned int*) AE_BIST_reg)=data)
#define get_AE_BIST_reg   (*((volatile unsigned int*) AE_BIST_reg))
#define AE_BIST_inst_adr                                                             "0x00A2"
#define AE_BIST_inst                                                                 0x00A2
#define AE_BIST_ls_src_coef_shift                                                    (4)
#define AE_BIST_ls_src_coef_mask                                                     (0x00000010)
#define AE_BIST_ls_src_coef(data)                                                    (0x00000010&((data)<<4))
#define AE_BIST_ls_src_coef_src(data)                                                ((0x00000010&(data))>>4)
#define AE_BIST_get_ls_src_coef(data)                                                ((0x00000010&(data))>>4)
#define AE_BIST_ls_src_dat_shift                                                     (3)
#define AE_BIST_ls_src_dat_mask                                                      (0x00000008)
#define AE_BIST_ls_src_dat(data)                                                     (0x00000008&((data)<<3))
#define AE_BIST_ls_src_dat_src(data)                                                 ((0x00000008&(data))>>3)
#define AE_BIST_get_ls_src_dat(data)                                                 ((0x00000008&(data))>>3)
#define AE_BIST_ls_src_rwbuf_shift                                                   (2)
#define AE_BIST_ls_src_rwbuf_mask                                                    (0x00000004)
#define AE_BIST_ls_src_rwbuf(data)                                                   (0x00000004&((data)<<2))
#define AE_BIST_ls_src_rwbuf_src(data)                                               ((0x00000004&(data))>>2)
#define AE_BIST_get_ls_src_rwbuf(data)                                               ((0x00000004&(data))>>2)
#define AE_BIST_ls_aee_shift                                                         (1)
#define AE_BIST_ls_aee_mask                                                          (0x00000002)
#define AE_BIST_ls_aee(data)                                                         (0x00000002&((data)<<1))
#define AE_BIST_ls_aee_src(data)                                                     ((0x00000002&(data))>>1)
#define AE_BIST_get_ls_aee(data)                                                     ((0x00000002&(data))>>1)
#define AE_BIST_ls_ade_shift                                                         (0)
#define AE_BIST_ls_ade_mask                                                          (0x00000001)
#define AE_BIST_ls_ade(data)                                                         (0x00000001&((data)<<0))
#define AE_BIST_ls_ade_src(data)                                                     ((0x00000001&(data))>>0)
#define AE_BIST_get_ls_ade(data)                                                     ((0x00000001&(data))>>0)


#endif
