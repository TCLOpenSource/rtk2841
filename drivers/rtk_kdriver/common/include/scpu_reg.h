/**************************************************************
// Spec Version                  : 0
// Parser Version                : DVR_Parser_6.11(120105)
// CModelGen Version             : 5.1 2012.01.05
// Naming Rule                   :  Register_Name
// Naming Rule                   : Module_Register_Name_reg
// Parse Option                  : Only Parse _op1
// Parse Address Region          : All Address Region 
// Decode bit number             : 12 bits
// Firmware Header Generate Date : 2013/1/3 15:21:14
***************************************************************/


#ifndef _SCPU_REG_H_INCLUDED_
#define _SCPU_REG_H_INCLUDED_
#ifdef  _SCPU_USE_STRUCT
typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     protect_3_en:1;
unsigned int     protect_2_en:1;
unsigned int     protect_1_en:1;
unsigned int     protect_0_en:1;
}SCPU_MEM_PROTECT_CTRL;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     Size_limit:2;
}SCPU_MEM_SCRAMBLE_CTRL;

typedef struct 
{
unsigned int     mem_protect_saddr:20;
unsigned int     reserved_0:12;
}SCPU_MEM_PROTECT_SADDR;

typedef struct 
{
unsigned int     mem_protect_eaddr:20;
unsigned int     reserved_0:12;
}SCPU_MEM_PROTECT_EADDR;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     mem_protect_int:1;
unsigned int     mem_protect_int_en:1;
unsigned int     write_data:1;
}SCPU_MEM_PROTECT_INT;

typedef struct 
{
unsigned int     protect_hit_addr:32;
}SCPU_MEM_PROTECT_HIT_ADDR;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     protect_hit_rw:1;
}SCPU_MEM_PROTECT_HIT_RW;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     dc_protect_7_en:1;
unsigned int     dc_protect_6_en:1;
unsigned int     dc_protect_5_en:1;
unsigned int     dc_protect_4_en:1;
unsigned int     dc_protect_3_en:1;
unsigned int     dc_protect_2_en:1;
unsigned int     dc_protect_1_en:1;
unsigned int     dc_protect_0_en:1;
}DC_CONTENT_PROTECT_CTRL;

typedef struct 
{
unsigned int     dc_mem_protect_saddr:20;
unsigned int     reserved_0:12;
}DC_CONTENT_PROTECT_SADDR;

typedef struct 
{
unsigned int     dc_mem_protect_eaddr:20;
unsigned int     reserved_0:12;
}DC_CONTENT_PROTECT_EADDR;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     dc_mem_protect_int:1;
unsigned int     dc_mem_protect_int_en:1;
unsigned int     write_data:1;
}DC_CONTENT_PROTECT_INT;

typedef struct 
{
unsigned int     dc_protect_hit_addr:32;
}DC_CONTENT_PROTECT_HIT_ADDR;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     dc_protect_hit_rw:1;
}DC_CONTENT_PROTECT_HIT_RW;

typedef struct 
{
unsigned int     dbg_start_addr:32;
}DBG_START;

typedef struct 
{
unsigned int     dbg_end_addr:32;
}DBG_END;

typedef struct 
{
unsigned int     reserved_0:27;
unsigned int     write_en2:1;
unsigned int     dbg_wr_chk:2;
unsigned int     write_en1:1;
unsigned int     dbg_en:1;
}DBG_CTRL;

typedef struct 
{
unsigned int     reserved_0:27;
unsigned int     scpu_int:1;
unsigned int     scpu_int_en:1;
unsigned int     scpu_neg_int:1;
unsigned int     scpu_neg_int_en:1;
unsigned int     write_data:1;
}DBG_INT;

typedef struct 
{
unsigned int     dbg_addr:32;
}DBG_ADDR;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     scpu_dbg_write:1;
}DBG_ADDR1;

typedef struct 
{
unsigned int     RM_7:4;
unsigned int     RM_6:4;
unsigned int     RM_5:4;
unsigned int     RM_4:4;
unsigned int     RM_3:4;
unsigned int     RM_2:4;
unsigned int     RM_1:4;
unsigned int     RM_0:4;
}RM_7_0;

typedef struct 
{
unsigned int     RM_15:4;
unsigned int     RM_14:4;
unsigned int     RM_13:4;
unsigned int     RM_12:4;
unsigned int     RM_11:4;
unsigned int     RM_10:4;
unsigned int     RM_9:4;
unsigned int     RM_8:4;
}RM_15_8;

typedef struct 
{
unsigned int     RM_23:4;
unsigned int     RM_22:4;
unsigned int     RM_21:4;
unsigned int     RM_20:4;
unsigned int     RM_19:4;
unsigned int     RM_18:4;
unsigned int     RM_17:4;
unsigned int     RM_16:4;
}RM_23_16;

typedef struct 
{
unsigned int     RM_31:4;
unsigned int     RM_30:4;
unsigned int     RM_29:4;
unsigned int     RM_28:4;
unsigned int     RM_27:4;
unsigned int     RM_26:4;
unsigned int     RM_25:4;
unsigned int     RM_24:4;
}RM_31_24;

typedef struct 
{
unsigned int     reserved_0:23;
unsigned int     RME:1;
unsigned int     RM_33:4;
unsigned int     RM_32:4;
}RM_33_32;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     LS_7:1;
unsigned int     LS_6:1;
unsigned int     LS_5:1;
unsigned int     LS_4:1;
unsigned int     LS_3:1;
unsigned int     LS_2:1;
unsigned int     LS_1:1;
unsigned int     LS_0:1;
}LS_7_0;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     LS_15:1;
unsigned int     LS_14:1;
unsigned int     LS_13:1;
unsigned int     LS_12:1;
unsigned int     LS_11:1;
unsigned int     LS_10:1;
unsigned int     LS_9:1;
unsigned int     LS_8:1;
}LS_15_8;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     LS_23:1;
unsigned int     LS_22:1;
unsigned int     LS_21:1;
unsigned int     LS_20:1;
unsigned int     LS_19:1;
unsigned int     LS_18:1;
unsigned int     LS_17:1;
unsigned int     LS_16:1;
}LS_23_16;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     LS_31:1;
unsigned int     LS_30:1;
unsigned int     LS_29:1;
unsigned int     LS_28:1;
unsigned int     LS_27:1;
unsigned int     LS_26:1;
unsigned int     LS_25:1;
unsigned int     LS_24:1;
}LS_31_24;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     LS_33:1;
unsigned int     LS_32:1;
}LS_33_32;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     BIST3_MODE:1;
unsigned int     BIST2_MODE:1;
unsigned int     BIST1_MODE:1;
unsigned int     BIST0_MODE:1;
}BIST_MODE;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     DRF_BIST3_MODE:1;
unsigned int     DRF_BIST2_MODE:1;
unsigned int     DRF_BIST1_MODE:1;
unsigned int     DRF_BIST0_MODE:1;
}DRF_BIST_MODE;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     DRF_BIST3_TEST_RESUME:1;
unsigned int     DRF_BIST2_TEST_RESUME:1;
unsigned int     DRF_BIST1_TEST_RESUME:1;
unsigned int     DRF_BIST0_TEST_RESUME:1;
}DRF_BIST_TEST_RESUME;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     BIST3_DONE:1;
unsigned int     BIST2_DONE:1;
unsigned int     BIST1_DONE:1;
unsigned int     BIST0_DONE:1;
}BIST_DONE;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     DRF_BIST3_DONE:1;
unsigned int     DRF_BIST2_DONE:1;
unsigned int     DRF_BIST1_DONE:1;
unsigned int     DRF_BIST0_DONE:1;
}DRF_BIST_DONE;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     DRF_BIST3_START_PAUSE:1;
unsigned int     DRF_BIST2_START_PAUSE:1;
unsigned int     DRF_BIST1_START_PAUSE:1;
unsigned int     DRF_BIST0_START_PAUSE:1;
}DRF_BIST_START_PAUSE;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     BIST3_FAIL:1;
unsigned int     BIST2_FAIL:1;
unsigned int     BIST1_FAIL:1;
unsigned int     BIST0_FAIL:1;
}BIST_FAIL_GROUP;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     DRF_BIST3_FAIL:1;
unsigned int     DRF_BIST2_FAIL:1;
unsigned int     DRF_BIST1_FAIL:1;
unsigned int     DRF_BIST0_FAIL:1;
}DRF_BIST_FAIL_GROUP;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     BIST0_FAIL_7:1;
unsigned int     BIST0_FAIL_6:1;
unsigned int     BIST0_FAIL_5:1;
unsigned int     BIST0_FAIL_4:1;
unsigned int     BIST0_FAIL_3:1;
unsigned int     BIST0_FAIL_2:1;
unsigned int     BIST0_FAIL_1:1;
unsigned int     BIST0_FAIL_0:1;
}BIST0_FAIL;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     DRF_BIST0_FAIL_7:1;
unsigned int     DRF_BIST0_FAIL_6:1;
unsigned int     DRF_BIST0_FAIL_5:1;
unsigned int     DRF_BIST0_FAIL_4:1;
unsigned int     DRF_BIST0_FAIL_3:1;
unsigned int     DRF_BIST0_FAIL_2:1;
unsigned int     DRF_BIST0_FAIL_1:1;
unsigned int     DRF_BIST0_FAIL_0:1;
}DRF_BIST0_FAIL;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     BIST1_FAIL_7:1;
unsigned int     BIST1_FAIL_6:1;
unsigned int     BIST1_FAIL_5:1;
unsigned int     BIST1_FAIL_4:1;
unsigned int     BIST1_FAIL_3:1;
unsigned int     BIST1_FAIL_2:1;
unsigned int     BIST1_FAIL_1:1;
unsigned int     BIST1_FAIL_0:1;
}BIST1_FAIL;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     DRF_BIST1_FAIL_7:1;
unsigned int     DRF_BIST1_FAIL_6:1;
unsigned int     DRF_BIST1_FAIL_5:1;
unsigned int     DRF_BIST1_FAIL_4:1;
unsigned int     DRF_BIST1_FAIL_3:1;
unsigned int     DRF_BIST1_FAIL_2:1;
unsigned int     DRF_BIST1_FAIL_1:1;
unsigned int     DRF_BIST1_FAIL_0:1;
}DRF_BIST1_FAIL;

typedef struct 
{
unsigned int     reserved_0:20;
unsigned int     BIST2_FAIL_11:1;
unsigned int     BIST2_FAIL_10:1;
unsigned int     BIST2_FAIL_9:1;
unsigned int     BIST2_FAIL_8:1;
unsigned int     BIST2_FAIL_7:1;
unsigned int     BIST2_FAIL_6:1;
unsigned int     BIST2_FAIL_5:1;
unsigned int     BIST2_FAIL_4:1;
unsigned int     BIST2_FAIL_3:1;
unsigned int     BIST2_FAIL_2:1;
unsigned int     BIST2_FAIL_1:1;
unsigned int     BIST2_FAIL_0:1;
}BIST2_FAIL;

typedef struct 
{
unsigned int     reserved_0:20;
unsigned int     DRF_BIST2_FAIL_11:1;
unsigned int     DRF_BIST2_FAIL_10:1;
unsigned int     DRF_BIST2_FAIL_9:1;
unsigned int     DRF_BIST2_FAIL_8:1;
unsigned int     DRF_BIST2_FAIL_7:1;
unsigned int     DRF_BIST2_FAIL_6:1;
unsigned int     DRF_BIST2_FAIL_5:1;
unsigned int     DRF_BIST2_FAIL_4:1;
unsigned int     DRF_BIST2_FAIL_3:1;
unsigned int     DRF_BIST2_FAIL_2:1;
unsigned int     DRF_BIST2_FAIL_1:1;
unsigned int     DRF_BIST2_FAIL_0:1;
}DRF_BIST2_FAIL;

typedef struct 
{
unsigned int     reserved_0:26;
unsigned int     BIST3_FAIL_5:1;
unsigned int     BIST3_FAIL_4:1;
unsigned int     BIST3_FAIL_3:1;
unsigned int     BIST3_FAIL_2:1;
unsigned int     BIST3_FAIL_1:1;
unsigned int     BIST3_FAIL_0:1;
}BIST3_FAIL;

typedef struct 
{
unsigned int     reserved_0:26;
unsigned int     DRF_BIST3_FAIL_5:1;
unsigned int     DRF_BIST3_FAIL_4:1;
unsigned int     DRF_BIST3_FAIL_3:1;
unsigned int     DRF_BIST3_FAIL_2:1;
unsigned int     DRF_BIST3_FAIL_1:1;
unsigned int     DRF_BIST3_FAIL_0:1;
}DRF_BIST3_FAIL;

#endif

#define SCPU_MEM_PROTECT_CTRL                                                        0x1805D300
#define SCPU_MEM_PROTECT_CTRL_reg_addr                                               "0xB805D300"
#define SCPU_MEM_PROTECT_CTRL_reg                                                    0xB805D300
#define set_SCPU_MEM_PROTECT_CTRL_reg(data)   (*((volatile unsigned int*) SCPU_MEM_PROTECT_CTRL_reg)=data)
#define get_SCPU_MEM_PROTECT_CTRL_reg   (*((volatile unsigned int*) SCPU_MEM_PROTECT_CTRL_reg))
#define SCPU_MEM_PROTECT_CTRL_inst_adr                                               "0x00C0"
#define SCPU_MEM_PROTECT_CTRL_inst                                                   0x00C0
#define SCPU_MEM_PROTECT_CTRL_protect_3_en_shift                                     (3)
#define SCPU_MEM_PROTECT_CTRL_protect_3_en_mask                                      (0x00000008)
#define SCPU_MEM_PROTECT_CTRL_protect_3_en(data)                                     (0x00000008&((data)<<3))
#define SCPU_MEM_PROTECT_CTRL_protect_3_en_src(data)                                 ((0x00000008&(data))>>3)
#define SCPU_MEM_PROTECT_CTRL_get_protect_3_en(data)                                 ((0x00000008&(data))>>3)
#define SCPU_MEM_PROTECT_CTRL_protect_2_en_shift                                     (2)
#define SCPU_MEM_PROTECT_CTRL_protect_2_en_mask                                      (0x00000004)
#define SCPU_MEM_PROTECT_CTRL_protect_2_en(data)                                     (0x00000004&((data)<<2))
#define SCPU_MEM_PROTECT_CTRL_protect_2_en_src(data)                                 ((0x00000004&(data))>>2)
#define SCPU_MEM_PROTECT_CTRL_get_protect_2_en(data)                                 ((0x00000004&(data))>>2)
#define SCPU_MEM_PROTECT_CTRL_protect_1_en_shift                                     (1)
#define SCPU_MEM_PROTECT_CTRL_protect_1_en_mask                                      (0x00000002)
#define SCPU_MEM_PROTECT_CTRL_protect_1_en(data)                                     (0x00000002&((data)<<1))
#define SCPU_MEM_PROTECT_CTRL_protect_1_en_src(data)                                 ((0x00000002&(data))>>1)
#define SCPU_MEM_PROTECT_CTRL_get_protect_1_en(data)                                 ((0x00000002&(data))>>1)
#define SCPU_MEM_PROTECT_CTRL_protect_0_en_shift                                     (0)
#define SCPU_MEM_PROTECT_CTRL_protect_0_en_mask                                      (0x00000001)
#define SCPU_MEM_PROTECT_CTRL_protect_0_en(data)                                     (0x00000001&((data)<<0))
#define SCPU_MEM_PROTECT_CTRL_protect_0_en_src(data)                                 ((0x00000001&(data))>>0)
#define SCPU_MEM_PROTECT_CTRL_get_protect_0_en(data)                                 ((0x00000001&(data))>>0)


#define SCPU_MEM_SCRAMBLE_CTRL                                                       0x1805D304
#define SCPU_MEM_SCRAMBLE_CTRL_reg_addr                                              "0xB805D304"
#define SCPU_MEM_SCRAMBLE_CTRL_reg                                                   0xB805D304
#define set_SCPU_MEM_SCRAMBLE_CTRL_reg(data)   (*((volatile unsigned int*) SCPU_MEM_SCRAMBLE_CTRL_reg)=data)
#define get_SCPU_MEM_SCRAMBLE_CTRL_reg   (*((volatile unsigned int*) SCPU_MEM_SCRAMBLE_CTRL_reg))
#define SCPU_MEM_SCRAMBLE_CTRL_inst_adr                                              "0x00C1"
#define SCPU_MEM_SCRAMBLE_CTRL_inst                                                  0x00C1
#define SCPU_MEM_SCRAMBLE_CTRL_Size_limit_shift                                      (0)
#define SCPU_MEM_SCRAMBLE_CTRL_Size_limit_mask                                       (0x00000003)
#define SCPU_MEM_SCRAMBLE_CTRL_Size_limit(data)                                      (0x00000003&((data)<<0))
#define SCPU_MEM_SCRAMBLE_CTRL_Size_limit_src(data)                                  ((0x00000003&(data))>>0)
#define SCPU_MEM_SCRAMBLE_CTRL_get_Size_limit(data)                                  ((0x00000003&(data))>>0)


#define SCPU_MEM_PROTECT_SADDR_0                                                     0x1805D310
#define SCPU_MEM_PROTECT_SADDR_1                                                     0x1805D314
#define SCPU_MEM_PROTECT_SADDR_2                                                     0x1805D318
#define SCPU_MEM_PROTECT_SADDR_3                                                     0x1805D31C
#define SCPU_MEM_PROTECT_SADDR_0_reg_addr                                            "0xB805D310"
#define SCPU_MEM_PROTECT_SADDR_1_reg_addr                                            "0xB805D314"
#define SCPU_MEM_PROTECT_SADDR_2_reg_addr                                            "0xB805D318"
#define SCPU_MEM_PROTECT_SADDR_3_reg_addr                                            "0xB805D31C"
#define SCPU_MEM_PROTECT_SADDR_0_reg                                                 0xB805D310
#define SCPU_MEM_PROTECT_SADDR_1_reg                                                 0xB805D314
#define SCPU_MEM_PROTECT_SADDR_2_reg                                                 0xB805D318
#define SCPU_MEM_PROTECT_SADDR_3_reg                                                 0xB805D31C
#define set_SCPU_MEM_PROTECT_SADDR_0_reg(data)   (*((volatile unsigned int*) SCPU_MEM_PROTECT_SADDR_0_reg)=data)
#define set_SCPU_MEM_PROTECT_SADDR_1_reg(data)   (*((volatile unsigned int*) SCPU_MEM_PROTECT_SADDR_1_reg)=data)
#define set_SCPU_MEM_PROTECT_SADDR_2_reg(data)   (*((volatile unsigned int*) SCPU_MEM_PROTECT_SADDR_2_reg)=data)
#define set_SCPU_MEM_PROTECT_SADDR_3_reg(data)   (*((volatile unsigned int*) SCPU_MEM_PROTECT_SADDR_3_reg)=data)
#define get_SCPU_MEM_PROTECT_SADDR_0_reg   (*((volatile unsigned int*) SCPU_MEM_PROTECT_SADDR_0_reg))
#define get_SCPU_MEM_PROTECT_SADDR_1_reg   (*((volatile unsigned int*) SCPU_MEM_PROTECT_SADDR_1_reg))
#define get_SCPU_MEM_PROTECT_SADDR_2_reg   (*((volatile unsigned int*) SCPU_MEM_PROTECT_SADDR_2_reg))
#define get_SCPU_MEM_PROTECT_SADDR_3_reg   (*((volatile unsigned int*) SCPU_MEM_PROTECT_SADDR_3_reg))
#define SCPU_MEM_PROTECT_SADDR_0_inst_adr                                            "0x00C4"
#define SCPU_MEM_PROTECT_SADDR_1_inst_adr                                            "0x00C5"
#define SCPU_MEM_PROTECT_SADDR_2_inst_adr                                            "0x00C6"
#define SCPU_MEM_PROTECT_SADDR_3_inst_adr                                            "0x00C7"
#define SCPU_MEM_PROTECT_SADDR_0_inst                                                0x00C4
#define SCPU_MEM_PROTECT_SADDR_1_inst                                                0x00C5
#define SCPU_MEM_PROTECT_SADDR_2_inst                                                0x00C6
#define SCPU_MEM_PROTECT_SADDR_3_inst                                                0x00C7
#define SCPU_MEM_PROTECT_SADDR_mem_protect_saddr_shift                               (12)
#define SCPU_MEM_PROTECT_SADDR_mem_protect_saddr_mask                                (0xFFFFF000)
#define SCPU_MEM_PROTECT_SADDR_mem_protect_saddr(data)                               (0xFFFFF000&((data)<<12))
#define SCPU_MEM_PROTECT_SADDR_mem_protect_saddr_src(data)                           ((0xFFFFF000&(data))>>12)
#define SCPU_MEM_PROTECT_SADDR_get_mem_protect_saddr(data)                           ((0xFFFFF000&(data))>>12)


#define SCPU_MEM_PROTECT_EADDR_0                                                     0x1805D320
#define SCPU_MEM_PROTECT_EADDR_1                                                     0x1805D324
#define SCPU_MEM_PROTECT_EADDR_2                                                     0x1805D328
#define SCPU_MEM_PROTECT_EADDR_3                                                     0x1805D32C
#define SCPU_MEM_PROTECT_EADDR_0_reg_addr                                            "0xB805D320"
#define SCPU_MEM_PROTECT_EADDR_1_reg_addr                                            "0xB805D324"
#define SCPU_MEM_PROTECT_EADDR_2_reg_addr                                            "0xB805D328"
#define SCPU_MEM_PROTECT_EADDR_3_reg_addr                                            "0xB805D32C"
#define SCPU_MEM_PROTECT_EADDR_0_reg                                                 0xB805D320
#define SCPU_MEM_PROTECT_EADDR_1_reg                                                 0xB805D324
#define SCPU_MEM_PROTECT_EADDR_2_reg                                                 0xB805D328
#define SCPU_MEM_PROTECT_EADDR_3_reg                                                 0xB805D32C
#define set_SCPU_MEM_PROTECT_EADDR_0_reg(data)   (*((volatile unsigned int*) SCPU_MEM_PROTECT_EADDR_0_reg)=data)
#define set_SCPU_MEM_PROTECT_EADDR_1_reg(data)   (*((volatile unsigned int*) SCPU_MEM_PROTECT_EADDR_1_reg)=data)
#define set_SCPU_MEM_PROTECT_EADDR_2_reg(data)   (*((volatile unsigned int*) SCPU_MEM_PROTECT_EADDR_2_reg)=data)
#define set_SCPU_MEM_PROTECT_EADDR_3_reg(data)   (*((volatile unsigned int*) SCPU_MEM_PROTECT_EADDR_3_reg)=data)
#define get_SCPU_MEM_PROTECT_EADDR_0_reg   (*((volatile unsigned int*) SCPU_MEM_PROTECT_EADDR_0_reg))
#define get_SCPU_MEM_PROTECT_EADDR_1_reg   (*((volatile unsigned int*) SCPU_MEM_PROTECT_EADDR_1_reg))
#define get_SCPU_MEM_PROTECT_EADDR_2_reg   (*((volatile unsigned int*) SCPU_MEM_PROTECT_EADDR_2_reg))
#define get_SCPU_MEM_PROTECT_EADDR_3_reg   (*((volatile unsigned int*) SCPU_MEM_PROTECT_EADDR_3_reg))
#define SCPU_MEM_PROTECT_EADDR_0_inst_adr                                            "0x00C8"
#define SCPU_MEM_PROTECT_EADDR_1_inst_adr                                            "0x00C9"
#define SCPU_MEM_PROTECT_EADDR_2_inst_adr                                            "0x00CA"
#define SCPU_MEM_PROTECT_EADDR_3_inst_adr                                            "0x00CB"
#define SCPU_MEM_PROTECT_EADDR_0_inst                                                0x00C8
#define SCPU_MEM_PROTECT_EADDR_1_inst                                                0x00C9
#define SCPU_MEM_PROTECT_EADDR_2_inst                                                0x00CA
#define SCPU_MEM_PROTECT_EADDR_3_inst                                                0x00CB
#define SCPU_MEM_PROTECT_EADDR_mem_protect_eaddr_shift                               (12)
#define SCPU_MEM_PROTECT_EADDR_mem_protect_eaddr_mask                                (0xFFFFF000)
#define SCPU_MEM_PROTECT_EADDR_mem_protect_eaddr(data)                               (0xFFFFF000&((data)<<12))
#define SCPU_MEM_PROTECT_EADDR_mem_protect_eaddr_src(data)                           ((0xFFFFF000&(data))>>12)
#define SCPU_MEM_PROTECT_EADDR_get_mem_protect_eaddr(data)                           ((0xFFFFF000&(data))>>12)


#define SCPU_MEM_PROTECT_INT                                                         0x1805D330
#define SCPU_MEM_PROTECT_INT_reg_addr                                                "0xB805D330"
#define SCPU_MEM_PROTECT_INT_reg                                                     0xB805D330
#define set_SCPU_MEM_PROTECT_INT_reg(data)   (*((volatile unsigned int*) SCPU_MEM_PROTECT_INT_reg)=data)
#define get_SCPU_MEM_PROTECT_INT_reg   (*((volatile unsigned int*) SCPU_MEM_PROTECT_INT_reg))
#define SCPU_MEM_PROTECT_INT_inst_adr                                                "0x00CC"
#define SCPU_MEM_PROTECT_INT_inst                                                    0x00CC
#define SCPU_MEM_PROTECT_INT_mem_protect_int_shift                                   (2)
#define SCPU_MEM_PROTECT_INT_mem_protect_int_mask                                    (0x00000004)
#define SCPU_MEM_PROTECT_INT_mem_protect_int(data)                                   (0x00000004&((data)<<2))
#define SCPU_MEM_PROTECT_INT_mem_protect_int_src(data)                               ((0x00000004&(data))>>2)
#define SCPU_MEM_PROTECT_INT_get_mem_protect_int(data)                               ((0x00000004&(data))>>2)
#define SCPU_MEM_PROTECT_INT_mem_protect_int_en_shift                                (1)
#define SCPU_MEM_PROTECT_INT_mem_protect_int_en_mask                                 (0x00000002)
#define SCPU_MEM_PROTECT_INT_mem_protect_int_en(data)                                (0x00000002&((data)<<1))
#define SCPU_MEM_PROTECT_INT_mem_protect_int_en_src(data)                            ((0x00000002&(data))>>1)
#define SCPU_MEM_PROTECT_INT_get_mem_protect_int_en(data)                            ((0x00000002&(data))>>1)
#define SCPU_MEM_PROTECT_INT_write_data_shift                                        (0)
#define SCPU_MEM_PROTECT_INT_write_data_mask                                         (0x00000001)
#define SCPU_MEM_PROTECT_INT_write_data(data)                                        (0x00000001&((data)<<0))
#define SCPU_MEM_PROTECT_INT_write_data_src(data)                                    ((0x00000001&(data))>>0)
#define SCPU_MEM_PROTECT_INT_get_write_data(data)                                    ((0x00000001&(data))>>0)


#define SCPU_MEM_PROTECT_HIT_ADDR                                                    0x1805D334
#define SCPU_MEM_PROTECT_HIT_ADDR_reg_addr                                           "0xB805D334"
#define SCPU_MEM_PROTECT_HIT_ADDR_reg                                                0xB805D334
#define set_SCPU_MEM_PROTECT_HIT_ADDR_reg(data)   (*((volatile unsigned int*) SCPU_MEM_PROTECT_HIT_ADDR_reg)=data)
#define get_SCPU_MEM_PROTECT_HIT_ADDR_reg   (*((volatile unsigned int*) SCPU_MEM_PROTECT_HIT_ADDR_reg))
#define SCPU_MEM_PROTECT_HIT_ADDR_inst_adr                                           "0x00CD"
#define SCPU_MEM_PROTECT_HIT_ADDR_inst                                               0x00CD
#define SCPU_MEM_PROTECT_HIT_ADDR_protect_hit_addr_shift                             (0)
#define SCPU_MEM_PROTECT_HIT_ADDR_protect_hit_addr_mask                              (0xFFFFFFFF)
#define SCPU_MEM_PROTECT_HIT_ADDR_protect_hit_addr(data)                             (0xFFFFFFFF&((data)<<0))
#define SCPU_MEM_PROTECT_HIT_ADDR_protect_hit_addr_src(data)                         ((0xFFFFFFFF&(data))>>0)
#define SCPU_MEM_PROTECT_HIT_ADDR_get_protect_hit_addr(data)                         ((0xFFFFFFFF&(data))>>0)


#define SCPU_MEM_PROTECT_HIT_RW                                                      0x1805D338
#define SCPU_MEM_PROTECT_HIT_RW_reg_addr                                             "0xB805D338"
#define SCPU_MEM_PROTECT_HIT_RW_reg                                                  0xB805D338
#define set_SCPU_MEM_PROTECT_HIT_RW_reg(data)   (*((volatile unsigned int*) SCPU_MEM_PROTECT_HIT_RW_reg)=data)
#define get_SCPU_MEM_PROTECT_HIT_RW_reg   (*((volatile unsigned int*) SCPU_MEM_PROTECT_HIT_RW_reg))
#define SCPU_MEM_PROTECT_HIT_RW_inst_adr                                             "0x00CE"
#define SCPU_MEM_PROTECT_HIT_RW_inst                                                 0x00CE
#define SCPU_MEM_PROTECT_HIT_RW_protect_hit_rw_shift                                 (0)
#define SCPU_MEM_PROTECT_HIT_RW_protect_hit_rw_mask                                  (0x00000001)
#define SCPU_MEM_PROTECT_HIT_RW_protect_hit_rw(data)                                 (0x00000001&((data)<<0))
#define SCPU_MEM_PROTECT_HIT_RW_protect_hit_rw_src(data)                             ((0x00000001&(data))>>0)
#define SCPU_MEM_PROTECT_HIT_RW_get_protect_hit_rw(data)                             ((0x00000001&(data))>>0)


#define DC_CONTENT_PROTECT_CTRL                                                      0x1805D340
#define DC_CONTENT_PROTECT_CTRL_reg_addr                                             "0xB805D340"
#define DC_CONTENT_PROTECT_CTRL_reg                                                  0xB805D340
#define set_DC_CONTENT_PROTECT_CTRL_reg(data)   (*((volatile unsigned int*) DC_CONTENT_PROTECT_CTRL_reg)=data)
#define get_DC_CONTENT_PROTECT_CTRL_reg   (*((volatile unsigned int*) DC_CONTENT_PROTECT_CTRL_reg))
#define DC_CONTENT_PROTECT_CTRL_inst_adr                                             "0x00D0"
#define DC_CONTENT_PROTECT_CTRL_inst                                                 0x00D0
#define DC_CONTENT_PROTECT_CTRL_dc_protect_7_en_shift                                (7)
#define DC_CONTENT_PROTECT_CTRL_dc_protect_7_en_mask                                 (0x00000080)
#define DC_CONTENT_PROTECT_CTRL_dc_protect_7_en(data)                                (0x00000080&((data)<<7))
#define DC_CONTENT_PROTECT_CTRL_dc_protect_7_en_src(data)                            ((0x00000080&(data))>>7)
#define DC_CONTENT_PROTECT_CTRL_get_dc_protect_7_en(data)                            ((0x00000080&(data))>>7)
#define DC_CONTENT_PROTECT_CTRL_dc_protect_6_en_shift                                (6)
#define DC_CONTENT_PROTECT_CTRL_dc_protect_6_en_mask                                 (0x00000040)
#define DC_CONTENT_PROTECT_CTRL_dc_protect_6_en(data)                                (0x00000040&((data)<<6))
#define DC_CONTENT_PROTECT_CTRL_dc_protect_6_en_src(data)                            ((0x00000040&(data))>>6)
#define DC_CONTENT_PROTECT_CTRL_get_dc_protect_6_en(data)                            ((0x00000040&(data))>>6)
#define DC_CONTENT_PROTECT_CTRL_dc_protect_5_en_shift                                (5)
#define DC_CONTENT_PROTECT_CTRL_dc_protect_5_en_mask                                 (0x00000020)
#define DC_CONTENT_PROTECT_CTRL_dc_protect_5_en(data)                                (0x00000020&((data)<<5))
#define DC_CONTENT_PROTECT_CTRL_dc_protect_5_en_src(data)                            ((0x00000020&(data))>>5)
#define DC_CONTENT_PROTECT_CTRL_get_dc_protect_5_en(data)                            ((0x00000020&(data))>>5)
#define DC_CONTENT_PROTECT_CTRL_dc_protect_4_en_shift                                (4)
#define DC_CONTENT_PROTECT_CTRL_dc_protect_4_en_mask                                 (0x00000010)
#define DC_CONTENT_PROTECT_CTRL_dc_protect_4_en(data)                                (0x00000010&((data)<<4))
#define DC_CONTENT_PROTECT_CTRL_dc_protect_4_en_src(data)                            ((0x00000010&(data))>>4)
#define DC_CONTENT_PROTECT_CTRL_get_dc_protect_4_en(data)                            ((0x00000010&(data))>>4)
#define DC_CONTENT_PROTECT_CTRL_dc_protect_3_en_shift                                (3)
#define DC_CONTENT_PROTECT_CTRL_dc_protect_3_en_mask                                 (0x00000008)
#define DC_CONTENT_PROTECT_CTRL_dc_protect_3_en(data)                                (0x00000008&((data)<<3))
#define DC_CONTENT_PROTECT_CTRL_dc_protect_3_en_src(data)                            ((0x00000008&(data))>>3)
#define DC_CONTENT_PROTECT_CTRL_get_dc_protect_3_en(data)                            ((0x00000008&(data))>>3)
#define DC_CONTENT_PROTECT_CTRL_dc_protect_2_en_shift                                (2)
#define DC_CONTENT_PROTECT_CTRL_dc_protect_2_en_mask                                 (0x00000004)
#define DC_CONTENT_PROTECT_CTRL_dc_protect_2_en(data)                                (0x00000004&((data)<<2))
#define DC_CONTENT_PROTECT_CTRL_dc_protect_2_en_src(data)                            ((0x00000004&(data))>>2)
#define DC_CONTENT_PROTECT_CTRL_get_dc_protect_2_en(data)                            ((0x00000004&(data))>>2)
#define DC_CONTENT_PROTECT_CTRL_dc_protect_1_en_shift                                (1)
#define DC_CONTENT_PROTECT_CTRL_dc_protect_1_en_mask                                 (0x00000002)
#define DC_CONTENT_PROTECT_CTRL_dc_protect_1_en(data)                                (0x00000002&((data)<<1))
#define DC_CONTENT_PROTECT_CTRL_dc_protect_1_en_src(data)                            ((0x00000002&(data))>>1)
#define DC_CONTENT_PROTECT_CTRL_get_dc_protect_1_en(data)                            ((0x00000002&(data))>>1)
#define DC_CONTENT_PROTECT_CTRL_dc_protect_0_en_shift                                (0)
#define DC_CONTENT_PROTECT_CTRL_dc_protect_0_en_mask                                 (0x00000001)
#define DC_CONTENT_PROTECT_CTRL_dc_protect_0_en(data)                                (0x00000001&((data)<<0))
#define DC_CONTENT_PROTECT_CTRL_dc_protect_0_en_src(data)                            ((0x00000001&(data))>>0)
#define DC_CONTENT_PROTECT_CTRL_get_dc_protect_0_en(data)                            ((0x00000001&(data))>>0)


#define DC_CONTENT_PROTECT_SADDR_0                                                   0x1805D350
#define DC_CONTENT_PROTECT_SADDR_1                                                   0x1805D354
#define DC_CONTENT_PROTECT_SADDR_2                                                   0x1805D358
#define DC_CONTENT_PROTECT_SADDR_3                                                   0x1805D35C
#define DC_CONTENT_PROTECT_SADDR_4                                                   0x1805D360
#define DC_CONTENT_PROTECT_SADDR_5                                                   0x1805D364
#define DC_CONTENT_PROTECT_SADDR_6                                                   0x1805D368
#define DC_CONTENT_PROTECT_SADDR_7                                                   0x1805D36C
#define DC_CONTENT_PROTECT_SADDR_0_reg_addr                                          "0xB805D350"
#define DC_CONTENT_PROTECT_SADDR_1_reg_addr                                          "0xB805D354"
#define DC_CONTENT_PROTECT_SADDR_2_reg_addr                                          "0xB805D358"
#define DC_CONTENT_PROTECT_SADDR_3_reg_addr                                          "0xB805D35C"
#define DC_CONTENT_PROTECT_SADDR_4_reg_addr                                          "0xB805D360"
#define DC_CONTENT_PROTECT_SADDR_5_reg_addr                                          "0xB805D364"
#define DC_CONTENT_PROTECT_SADDR_6_reg_addr                                          "0xB805D368"
#define DC_CONTENT_PROTECT_SADDR_7_reg_addr                                          "0xB805D36C"
#define DC_CONTENT_PROTECT_SADDR_0_reg                                               0xB805D350
#define DC_CONTENT_PROTECT_SADDR_1_reg                                               0xB805D354
#define DC_CONTENT_PROTECT_SADDR_2_reg                                               0xB805D358
#define DC_CONTENT_PROTECT_SADDR_3_reg                                               0xB805D35C
#define DC_CONTENT_PROTECT_SADDR_4_reg                                               0xB805D360
#define DC_CONTENT_PROTECT_SADDR_5_reg                                               0xB805D364
#define DC_CONTENT_PROTECT_SADDR_6_reg                                               0xB805D368
#define DC_CONTENT_PROTECT_SADDR_7_reg                                               0xB805D36C
#define set_DC_CONTENT_PROTECT_SADDR_0_reg(data)   (*((volatile unsigned int*) DC_CONTENT_PROTECT_SADDR_0_reg)=data)
#define set_DC_CONTENT_PROTECT_SADDR_1_reg(data)   (*((volatile unsigned int*) DC_CONTENT_PROTECT_SADDR_1_reg)=data)
#define set_DC_CONTENT_PROTECT_SADDR_2_reg(data)   (*((volatile unsigned int*) DC_CONTENT_PROTECT_SADDR_2_reg)=data)
#define set_DC_CONTENT_PROTECT_SADDR_3_reg(data)   (*((volatile unsigned int*) DC_CONTENT_PROTECT_SADDR_3_reg)=data)
#define set_DC_CONTENT_PROTECT_SADDR_4_reg(data)   (*((volatile unsigned int*) DC_CONTENT_PROTECT_SADDR_4_reg)=data)
#define set_DC_CONTENT_PROTECT_SADDR_5_reg(data)   (*((volatile unsigned int*) DC_CONTENT_PROTECT_SADDR_5_reg)=data)
#define set_DC_CONTENT_PROTECT_SADDR_6_reg(data)   (*((volatile unsigned int*) DC_CONTENT_PROTECT_SADDR_6_reg)=data)
#define set_DC_CONTENT_PROTECT_SADDR_7_reg(data)   (*((volatile unsigned int*) DC_CONTENT_PROTECT_SADDR_7_reg)=data)
#define get_DC_CONTENT_PROTECT_SADDR_0_reg   (*((volatile unsigned int*) DC_CONTENT_PROTECT_SADDR_0_reg))
#define get_DC_CONTENT_PROTECT_SADDR_1_reg   (*((volatile unsigned int*) DC_CONTENT_PROTECT_SADDR_1_reg))
#define get_DC_CONTENT_PROTECT_SADDR_2_reg   (*((volatile unsigned int*) DC_CONTENT_PROTECT_SADDR_2_reg))
#define get_DC_CONTENT_PROTECT_SADDR_3_reg   (*((volatile unsigned int*) DC_CONTENT_PROTECT_SADDR_3_reg))
#define get_DC_CONTENT_PROTECT_SADDR_4_reg   (*((volatile unsigned int*) DC_CONTENT_PROTECT_SADDR_4_reg))
#define get_DC_CONTENT_PROTECT_SADDR_5_reg   (*((volatile unsigned int*) DC_CONTENT_PROTECT_SADDR_5_reg))
#define get_DC_CONTENT_PROTECT_SADDR_6_reg   (*((volatile unsigned int*) DC_CONTENT_PROTECT_SADDR_6_reg))
#define get_DC_CONTENT_PROTECT_SADDR_7_reg   (*((volatile unsigned int*) DC_CONTENT_PROTECT_SADDR_7_reg))
#define DC_CONTENT_PROTECT_SADDR_0_inst_adr                                          "0x00D4"
#define DC_CONTENT_PROTECT_SADDR_1_inst_adr                                          "0x00D5"
#define DC_CONTENT_PROTECT_SADDR_2_inst_adr                                          "0x00D6"
#define DC_CONTENT_PROTECT_SADDR_3_inst_adr                                          "0x00D7"
#define DC_CONTENT_PROTECT_SADDR_4_inst_adr                                          "0x00D8"
#define DC_CONTENT_PROTECT_SADDR_5_inst_adr                                          "0x00D9"
#define DC_CONTENT_PROTECT_SADDR_6_inst_adr                                          "0x00DA"
#define DC_CONTENT_PROTECT_SADDR_7_inst_adr                                          "0x00DB"
#define DC_CONTENT_PROTECT_SADDR_0_inst                                              0x00D4
#define DC_CONTENT_PROTECT_SADDR_1_inst                                              0x00D5
#define DC_CONTENT_PROTECT_SADDR_2_inst                                              0x00D6
#define DC_CONTENT_PROTECT_SADDR_3_inst                                              0x00D7
#define DC_CONTENT_PROTECT_SADDR_4_inst                                              0x00D8
#define DC_CONTENT_PROTECT_SADDR_5_inst                                              0x00D9
#define DC_CONTENT_PROTECT_SADDR_6_inst                                              0x00DA
#define DC_CONTENT_PROTECT_SADDR_7_inst                                              0x00DB
#define DC_CONTENT_PROTECT_SADDR_dc_mem_protect_saddr_shift                          (12)
#define DC_CONTENT_PROTECT_SADDR_dc_mem_protect_saddr_mask                           (0xFFFFF000)
#define DC_CONTENT_PROTECT_SADDR_dc_mem_protect_saddr(data)                          (0xFFFFF000&((data)<<12))
#define DC_CONTENT_PROTECT_SADDR_dc_mem_protect_saddr_src(data)                      ((0xFFFFF000&(data))>>12)
#define DC_CONTENT_PROTECT_SADDR_get_dc_mem_protect_saddr(data)                      ((0xFFFFF000&(data))>>12)


#define DC_CONTENT_PROTECT_EADDR_0                                                   0x1805D370
#define DC_CONTENT_PROTECT_EADDR_1                                                   0x1805D374
#define DC_CONTENT_PROTECT_EADDR_2                                                   0x1805D378
#define DC_CONTENT_PROTECT_EADDR_3                                                   0x1805D37C
#define DC_CONTENT_PROTECT_EADDR_4                                                   0x1805D380
#define DC_CONTENT_PROTECT_EADDR_5                                                   0x1805D384
#define DC_CONTENT_PROTECT_EADDR_6                                                   0x1805D388
#define DC_CONTENT_PROTECT_EADDR_7                                                   0x1805D38C
#define DC_CONTENT_PROTECT_EADDR_0_reg_addr                                          "0xB805D370"
#define DC_CONTENT_PROTECT_EADDR_1_reg_addr                                          "0xB805D374"
#define DC_CONTENT_PROTECT_EADDR_2_reg_addr                                          "0xB805D378"
#define DC_CONTENT_PROTECT_EADDR_3_reg_addr                                          "0xB805D37C"
#define DC_CONTENT_PROTECT_EADDR_4_reg_addr                                          "0xB805D380"
#define DC_CONTENT_PROTECT_EADDR_5_reg_addr                                          "0xB805D384"
#define DC_CONTENT_PROTECT_EADDR_6_reg_addr                                          "0xB805D388"
#define DC_CONTENT_PROTECT_EADDR_7_reg_addr                                          "0xB805D38C"
#define DC_CONTENT_PROTECT_EADDR_0_reg                                               0xB805D370
#define DC_CONTENT_PROTECT_EADDR_1_reg                                               0xB805D374
#define DC_CONTENT_PROTECT_EADDR_2_reg                                               0xB805D378
#define DC_CONTENT_PROTECT_EADDR_3_reg                                               0xB805D37C
#define DC_CONTENT_PROTECT_EADDR_4_reg                                               0xB805D380
#define DC_CONTENT_PROTECT_EADDR_5_reg                                               0xB805D384
#define DC_CONTENT_PROTECT_EADDR_6_reg                                               0xB805D388
#define DC_CONTENT_PROTECT_EADDR_7_reg                                               0xB805D38C
#define set_DC_CONTENT_PROTECT_EADDR_0_reg(data)   (*((volatile unsigned int*) DC_CONTENT_PROTECT_EADDR_0_reg)=data)
#define set_DC_CONTENT_PROTECT_EADDR_1_reg(data)   (*((volatile unsigned int*) DC_CONTENT_PROTECT_EADDR_1_reg)=data)
#define set_DC_CONTENT_PROTECT_EADDR_2_reg(data)   (*((volatile unsigned int*) DC_CONTENT_PROTECT_EADDR_2_reg)=data)
#define set_DC_CONTENT_PROTECT_EADDR_3_reg(data)   (*((volatile unsigned int*) DC_CONTENT_PROTECT_EADDR_3_reg)=data)
#define set_DC_CONTENT_PROTECT_EADDR_4_reg(data)   (*((volatile unsigned int*) DC_CONTENT_PROTECT_EADDR_4_reg)=data)
#define set_DC_CONTENT_PROTECT_EADDR_5_reg(data)   (*((volatile unsigned int*) DC_CONTENT_PROTECT_EADDR_5_reg)=data)
#define set_DC_CONTENT_PROTECT_EADDR_6_reg(data)   (*((volatile unsigned int*) DC_CONTENT_PROTECT_EADDR_6_reg)=data)
#define set_DC_CONTENT_PROTECT_EADDR_7_reg(data)   (*((volatile unsigned int*) DC_CONTENT_PROTECT_EADDR_7_reg)=data)
#define get_DC_CONTENT_PROTECT_EADDR_0_reg   (*((volatile unsigned int*) DC_CONTENT_PROTECT_EADDR_0_reg))
#define get_DC_CONTENT_PROTECT_EADDR_1_reg   (*((volatile unsigned int*) DC_CONTENT_PROTECT_EADDR_1_reg))
#define get_DC_CONTENT_PROTECT_EADDR_2_reg   (*((volatile unsigned int*) DC_CONTENT_PROTECT_EADDR_2_reg))
#define get_DC_CONTENT_PROTECT_EADDR_3_reg   (*((volatile unsigned int*) DC_CONTENT_PROTECT_EADDR_3_reg))
#define get_DC_CONTENT_PROTECT_EADDR_4_reg   (*((volatile unsigned int*) DC_CONTENT_PROTECT_EADDR_4_reg))
#define get_DC_CONTENT_PROTECT_EADDR_5_reg   (*((volatile unsigned int*) DC_CONTENT_PROTECT_EADDR_5_reg))
#define get_DC_CONTENT_PROTECT_EADDR_6_reg   (*((volatile unsigned int*) DC_CONTENT_PROTECT_EADDR_6_reg))
#define get_DC_CONTENT_PROTECT_EADDR_7_reg   (*((volatile unsigned int*) DC_CONTENT_PROTECT_EADDR_7_reg))
#define DC_CONTENT_PROTECT_EADDR_0_inst_adr                                          "0x00DC"
#define DC_CONTENT_PROTECT_EADDR_1_inst_adr                                          "0x00DD"
#define DC_CONTENT_PROTECT_EADDR_2_inst_adr                                          "0x00DE"
#define DC_CONTENT_PROTECT_EADDR_3_inst_adr                                          "0x00DF"
#define DC_CONTENT_PROTECT_EADDR_4_inst_adr                                          "0x00E0"
#define DC_CONTENT_PROTECT_EADDR_5_inst_adr                                          "0x00E1"
#define DC_CONTENT_PROTECT_EADDR_6_inst_adr                                          "0x00E2"
#define DC_CONTENT_PROTECT_EADDR_7_inst_adr                                          "0x00E3"
#define DC_CONTENT_PROTECT_EADDR_0_inst                                              0x00DC
#define DC_CONTENT_PROTECT_EADDR_1_inst                                              0x00DD
#define DC_CONTENT_PROTECT_EADDR_2_inst                                              0x00DE
#define DC_CONTENT_PROTECT_EADDR_3_inst                                              0x00DF
#define DC_CONTENT_PROTECT_EADDR_4_inst                                              0x00E0
#define DC_CONTENT_PROTECT_EADDR_5_inst                                              0x00E1
#define DC_CONTENT_PROTECT_EADDR_6_inst                                              0x00E2
#define DC_CONTENT_PROTECT_EADDR_7_inst                                              0x00E3
#define DC_CONTENT_PROTECT_EADDR_dc_mem_protect_eaddr_shift                          (12)
#define DC_CONTENT_PROTECT_EADDR_dc_mem_protect_eaddr_mask                           (0xFFFFF000)
#define DC_CONTENT_PROTECT_EADDR_dc_mem_protect_eaddr(data)                          (0xFFFFF000&((data)<<12))
#define DC_CONTENT_PROTECT_EADDR_dc_mem_protect_eaddr_src(data)                      ((0xFFFFF000&(data))>>12)
#define DC_CONTENT_PROTECT_EADDR_get_dc_mem_protect_eaddr(data)                      ((0xFFFFF000&(data))>>12)


#define DC_CONTENT_PROTECT_INT                                                       0x1805D390
#define DC_CONTENT_PROTECT_INT_reg_addr                                              "0xB805D390"
#define DC_CONTENT_PROTECT_INT_reg                                                   0xB805D390
#define set_DC_CONTENT_PROTECT_INT_reg(data)   (*((volatile unsigned int*) DC_CONTENT_PROTECT_INT_reg)=data)
#define get_DC_CONTENT_PROTECT_INT_reg   (*((volatile unsigned int*) DC_CONTENT_PROTECT_INT_reg))
#define DC_CONTENT_PROTECT_INT_inst_adr                                              "0x00E4"
#define DC_CONTENT_PROTECT_INT_inst                                                  0x00E4
#define DC_CONTENT_PROTECT_INT_dc_mem_protect_int_shift                              (2)
#define DC_CONTENT_PROTECT_INT_dc_mem_protect_int_mask                               (0x00000004)
#define DC_CONTENT_PROTECT_INT_dc_mem_protect_int(data)                              (0x00000004&((data)<<2))
#define DC_CONTENT_PROTECT_INT_dc_mem_protect_int_src(data)                          ((0x00000004&(data))>>2)
#define DC_CONTENT_PROTECT_INT_get_dc_mem_protect_int(data)                          ((0x00000004&(data))>>2)
#define DC_CONTENT_PROTECT_INT_dc_mem_protect_int_en_shift                           (1)
#define DC_CONTENT_PROTECT_INT_dc_mem_protect_int_en_mask                            (0x00000002)
#define DC_CONTENT_PROTECT_INT_dc_mem_protect_int_en(data)                           (0x00000002&((data)<<1))
#define DC_CONTENT_PROTECT_INT_dc_mem_protect_int_en_src(data)                       ((0x00000002&(data))>>1)
#define DC_CONTENT_PROTECT_INT_get_dc_mem_protect_int_en(data)                       ((0x00000002&(data))>>1)
#define DC_CONTENT_PROTECT_INT_write_data_shift                                      (0)
#define DC_CONTENT_PROTECT_INT_write_data_mask                                       (0x00000001)
#define DC_CONTENT_PROTECT_INT_write_data(data)                                      (0x00000001&((data)<<0))
#define DC_CONTENT_PROTECT_INT_write_data_src(data)                                  ((0x00000001&(data))>>0)
#define DC_CONTENT_PROTECT_INT_get_write_data(data)                                  ((0x00000001&(data))>>0)


#define DC_CONTENT_PROTECT_HIT_ADDR                                                  0x1805D394
#define DC_CONTENT_PROTECT_HIT_ADDR_reg_addr                                         "0xB805D394"
#define DC_CONTENT_PROTECT_HIT_ADDR_reg                                              0xB805D394
#define set_DC_CONTENT_PROTECT_HIT_ADDR_reg(data)   (*((volatile unsigned int*) DC_CONTENT_PROTECT_HIT_ADDR_reg)=data)
#define get_DC_CONTENT_PROTECT_HIT_ADDR_reg   (*((volatile unsigned int*) DC_CONTENT_PROTECT_HIT_ADDR_reg))
#define DC_CONTENT_PROTECT_HIT_ADDR_inst_adr                                         "0x00E5"
#define DC_CONTENT_PROTECT_HIT_ADDR_inst                                             0x00E5
#define DC_CONTENT_PROTECT_HIT_ADDR_dc_protect_hit_addr_shift                        (0)
#define DC_CONTENT_PROTECT_HIT_ADDR_dc_protect_hit_addr_mask                         (0xFFFFFFFF)
#define DC_CONTENT_PROTECT_HIT_ADDR_dc_protect_hit_addr(data)                        (0xFFFFFFFF&((data)<<0))
#define DC_CONTENT_PROTECT_HIT_ADDR_dc_protect_hit_addr_src(data)                    ((0xFFFFFFFF&(data))>>0)
#define DC_CONTENT_PROTECT_HIT_ADDR_get_dc_protect_hit_addr(data)                    ((0xFFFFFFFF&(data))>>0)


#define DC_CONTENT_PROTECT_HIT_RW                                                    0x1805D398
#define DC_CONTENT_PROTECT_HIT_RW_reg_addr                                           "0xB805D398"
#define DC_CONTENT_PROTECT_HIT_RW_reg                                                0xB805D398
#define set_DC_CONTENT_PROTECT_HIT_RW_reg(data)   (*((volatile unsigned int*) DC_CONTENT_PROTECT_HIT_RW_reg)=data)
#define get_DC_CONTENT_PROTECT_HIT_RW_reg   (*((volatile unsigned int*) DC_CONTENT_PROTECT_HIT_RW_reg))
#define DC_CONTENT_PROTECT_HIT_RW_inst_adr                                           "0x00E6"
#define DC_CONTENT_PROTECT_HIT_RW_inst                                               0x00E6
#define DC_CONTENT_PROTECT_HIT_RW_dc_protect_hit_rw_shift                            (0)
#define DC_CONTENT_PROTECT_HIT_RW_dc_protect_hit_rw_mask                             (0x00000001)
#define DC_CONTENT_PROTECT_HIT_RW_dc_protect_hit_rw(data)                            (0x00000001&((data)<<0))
#define DC_CONTENT_PROTECT_HIT_RW_dc_protect_hit_rw_src(data)                        ((0x00000001&(data))>>0)
#define DC_CONTENT_PROTECT_HIT_RW_get_dc_protect_hit_rw(data)                        ((0x00000001&(data))>>0)


#define DBG_START_0                                                                  0x1805D400
#define DBG_START_1                                                                  0x1805D404
#define DBG_START_2                                                                  0x1805D408
#define DBG_START_3                                                                  0x1805D40C
#define DBG_START_0_reg_addr                                                         "0xB805D400"
#define DBG_START_1_reg_addr                                                         "0xB805D404"
#define DBG_START_2_reg_addr                                                         "0xB805D408"
#define DBG_START_3_reg_addr                                                         "0xB805D40C"
#define DBG_START_0_reg                                                              0xB805D400
#define DBG_START_1_reg                                                              0xB805D404
#define DBG_START_2_reg                                                              0xB805D408
#define DBG_START_3_reg                                                              0xB805D40C
#define set_DBG_START_0_reg(data)   (*((volatile unsigned int*) DBG_START_0_reg)=data)
#define set_DBG_START_1_reg(data)   (*((volatile unsigned int*) DBG_START_1_reg)=data)
#define set_DBG_START_2_reg(data)   (*((volatile unsigned int*) DBG_START_2_reg)=data)
#define set_DBG_START_3_reg(data)   (*((volatile unsigned int*) DBG_START_3_reg)=data)
#define get_DBG_START_0_reg   (*((volatile unsigned int*) DBG_START_0_reg))
#define get_DBG_START_1_reg   (*((volatile unsigned int*) DBG_START_1_reg))
#define get_DBG_START_2_reg   (*((volatile unsigned int*) DBG_START_2_reg))
#define get_DBG_START_3_reg   (*((volatile unsigned int*) DBG_START_3_reg))
#define DBG_START_0_inst_adr                                                         "0x0000"
#define DBG_START_1_inst_adr                                                         "0x0001"
#define DBG_START_2_inst_adr                                                         "0x0002"
#define DBG_START_3_inst_adr                                                         "0x0003"
#define DBG_START_0_inst                                                             0x0000
#define DBG_START_1_inst                                                             0x0001
#define DBG_START_2_inst                                                             0x0002
#define DBG_START_3_inst                                                             0x0003
#define DBG_START_dbg_start_addr_shift                                               (0)
#define DBG_START_dbg_start_addr_mask                                                (0xFFFFFFFF)
#define DBG_START_dbg_start_addr(data)                                               (0xFFFFFFFF&((data)<<0))
#define DBG_START_dbg_start_addr_src(data)                                           ((0xFFFFFFFF&(data))>>0)
#define DBG_START_get_dbg_start_addr(data)                                           ((0xFFFFFFFF&(data))>>0)


#define DBG_END_0                                                                    0x1805D410
#define DBG_END_1                                                                    0x1805D414
#define DBG_END_2                                                                    0x1805D418
#define DBG_END_3                                                                    0x1805D41C
#define DBG_END_0_reg_addr                                                           "0xB805D410"
#define DBG_END_1_reg_addr                                                           "0xB805D414"
#define DBG_END_2_reg_addr                                                           "0xB805D418"
#define DBG_END_3_reg_addr                                                           "0xB805D41C"
#define DBG_END_0_reg                                                                0xB805D410
#define DBG_END_1_reg                                                                0xB805D414
#define DBG_END_2_reg                                                                0xB805D418
#define DBG_END_3_reg                                                                0xB805D41C
#define set_DBG_END_0_reg(data)   (*((volatile unsigned int*) DBG_END_0_reg)=data)
#define set_DBG_END_1_reg(data)   (*((volatile unsigned int*) DBG_END_1_reg)=data)
#define set_DBG_END_2_reg(data)   (*((volatile unsigned int*) DBG_END_2_reg)=data)
#define set_DBG_END_3_reg(data)   (*((volatile unsigned int*) DBG_END_3_reg)=data)
#define get_DBG_END_0_reg   (*((volatile unsigned int*) DBG_END_0_reg))
#define get_DBG_END_1_reg   (*((volatile unsigned int*) DBG_END_1_reg))
#define get_DBG_END_2_reg   (*((volatile unsigned int*) DBG_END_2_reg))
#define get_DBG_END_3_reg   (*((volatile unsigned int*) DBG_END_3_reg))
#define DBG_END_0_inst_adr                                                           "0x0004"
#define DBG_END_1_inst_adr                                                           "0x0005"
#define DBG_END_2_inst_adr                                                           "0x0006"
#define DBG_END_3_inst_adr                                                           "0x0007"
#define DBG_END_0_inst                                                               0x0004
#define DBG_END_1_inst                                                               0x0005
#define DBG_END_2_inst                                                               0x0006
#define DBG_END_3_inst                                                               0x0007
#define DBG_END_dbg_end_addr_shift                                                   (0)
#define DBG_END_dbg_end_addr_mask                                                    (0xFFFFFFFF)
#define DBG_END_dbg_end_addr(data)                                                   (0xFFFFFFFF&((data)<<0))
#define DBG_END_dbg_end_addr_src(data)                                               ((0xFFFFFFFF&(data))>>0)
#define DBG_END_get_dbg_end_addr(data)                                               ((0xFFFFFFFF&(data))>>0)


#define DBG_CTRL_0                                                                   0x1805D420
#define DBG_CTRL_1                                                                   0x1805D424
#define DBG_CTRL_2                                                                   0x1805D428
#define DBG_CTRL_3                                                                   0x1805D42C
#define DBG_CTRL_0_reg_addr                                                          "0xB805D420"
#define DBG_CTRL_1_reg_addr                                                          "0xB805D424"
#define DBG_CTRL_2_reg_addr                                                          "0xB805D428"
#define DBG_CTRL_3_reg_addr                                                          "0xB805D42C"
#define DBG_CTRL_0_reg                                                               0xB805D420
#define DBG_CTRL_1_reg                                                               0xB805D424
#define DBG_CTRL_2_reg                                                               0xB805D428
#define DBG_CTRL_3_reg                                                               0xB805D42C
#define set_DBG_CTRL_0_reg(data)   (*((volatile unsigned int*) DBG_CTRL_0_reg)=data)
#define set_DBG_CTRL_1_reg(data)   (*((volatile unsigned int*) DBG_CTRL_1_reg)=data)
#define set_DBG_CTRL_2_reg(data)   (*((volatile unsigned int*) DBG_CTRL_2_reg)=data)
#define set_DBG_CTRL_3_reg(data)   (*((volatile unsigned int*) DBG_CTRL_3_reg)=data)
#define get_DBG_CTRL_0_reg   (*((volatile unsigned int*) DBG_CTRL_0_reg))
#define get_DBG_CTRL_1_reg   (*((volatile unsigned int*) DBG_CTRL_1_reg))
#define get_DBG_CTRL_2_reg   (*((volatile unsigned int*) DBG_CTRL_2_reg))
#define get_DBG_CTRL_3_reg   (*((volatile unsigned int*) DBG_CTRL_3_reg))
#define DBG_CTRL_0_inst_adr                                                          "0x0008"
#define DBG_CTRL_1_inst_adr                                                          "0x0009"
#define DBG_CTRL_2_inst_adr                                                          "0x000A"
#define DBG_CTRL_3_inst_adr                                                          "0x000B"
#define DBG_CTRL_0_inst                                                              0x0008
#define DBG_CTRL_1_inst                                                              0x0009
#define DBG_CTRL_2_inst                                                              0x000A
#define DBG_CTRL_3_inst                                                              0x000B
#define DBG_CTRL_write_en2_shift                                                     (4)
#define DBG_CTRL_write_en2_mask                                                      (0x00000010)
#define DBG_CTRL_write_en2(data)                                                     (0x00000010&((data)<<4))
#define DBG_CTRL_write_en2_src(data)                                                 ((0x00000010&(data))>>4)
#define DBG_CTRL_get_write_en2(data)                                                 ((0x00000010&(data))>>4)
#define DBG_CTRL_dbg_wr_chk_shift                                                    (2)
#define DBG_CTRL_dbg_wr_chk_mask                                                     (0x0000000C)
#define DBG_CTRL_dbg_wr_chk(data)                                                    (0x0000000C&((data)<<2))
#define DBG_CTRL_dbg_wr_chk_src(data)                                                ((0x0000000C&(data))>>2)
#define DBG_CTRL_get_dbg_wr_chk(data)                                                ((0x0000000C&(data))>>2)
#define DBG_CTRL_write_en1_shift                                                     (1)
#define DBG_CTRL_write_en1_mask                                                      (0x00000002)
#define DBG_CTRL_write_en1(data)                                                     (0x00000002&((data)<<1))
#define DBG_CTRL_write_en1_src(data)                                                 ((0x00000002&(data))>>1)
#define DBG_CTRL_get_write_en1(data)                                                 ((0x00000002&(data))>>1)
#define DBG_CTRL_dbg_en_shift                                                        (0)
#define DBG_CTRL_dbg_en_mask                                                         (0x00000001)
#define DBG_CTRL_dbg_en(data)                                                        (0x00000001&((data)<<0))
#define DBG_CTRL_dbg_en_src(data)                                                    ((0x00000001&(data))>>0)
#define DBG_CTRL_get_dbg_en(data)                                                    ((0x00000001&(data))>>0)


#define DBG_INT                                                                      0x1805D430
#define DBG_INT_reg_addr                                                             "0xB805D430"
#define DBG_INT_reg                                                                  0xB805D430
#define set_DBG_INT_reg(data)   (*((volatile unsigned int*) DBG_INT_reg)=data)
#define get_DBG_INT_reg   (*((volatile unsigned int*) DBG_INT_reg))
#define DBG_INT_inst_adr                                                             "0x000C"
#define DBG_INT_inst                                                                 0x000C
#define DBG_INT_scpu_int_shift                                                       (4)
#define DBG_INT_scpu_int_mask                                                        (0x00000010)
#define DBG_INT_scpu_int(data)                                                       (0x00000010&((data)<<4))
#define DBG_INT_scpu_int_src(data)                                                   ((0x00000010&(data))>>4)
#define DBG_INT_get_scpu_int(data)                                                   ((0x00000010&(data))>>4)
#define DBG_INT_scpu_int_en_shift                                                    (3)
#define DBG_INT_scpu_int_en_mask                                                     (0x00000008)
#define DBG_INT_scpu_int_en(data)                                                    (0x00000008&((data)<<3))
#define DBG_INT_scpu_int_en_src(data)                                                ((0x00000008&(data))>>3)
#define DBG_INT_get_scpu_int_en(data)                                                ((0x00000008&(data))>>3)
#define DBG_INT_scpu_neg_int_shift                                                   (2)
#define DBG_INT_scpu_neg_int_mask                                                    (0x00000004)
#define DBG_INT_scpu_neg_int(data)                                                   (0x00000004&((data)<<2))
#define DBG_INT_scpu_neg_int_src(data)                                               ((0x00000004&(data))>>2)
#define DBG_INT_get_scpu_neg_int(data)                                               ((0x00000004&(data))>>2)
#define DBG_INT_scpu_neg_int_en_shift                                                (1)
#define DBG_INT_scpu_neg_int_en_mask                                                 (0x00000002)
#define DBG_INT_scpu_neg_int_en(data)                                                (0x00000002&((data)<<1))
#define DBG_INT_scpu_neg_int_en_src(data)                                            ((0x00000002&(data))>>1)
#define DBG_INT_get_scpu_neg_int_en(data)                                            ((0x00000002&(data))>>1)
#define DBG_INT_write_data_shift                                                     (0)
#define DBG_INT_write_data_mask                                                      (0x00000001)
#define DBG_INT_write_data(data)                                                     (0x00000001&((data)<<0))
#define DBG_INT_write_data_src(data)                                                 ((0x00000001&(data))>>0)
#define DBG_INT_get_write_data(data)                                                 ((0x00000001&(data))>>0)


#define DBG_ADDR                                                                     0x1805D434
#define DBG_ADDR_reg_addr                                                            "0xB805D434"
#define DBG_ADDR_reg                                                                 0xB805D434
#define set_DBG_ADDR_reg(data)   (*((volatile unsigned int*) DBG_ADDR_reg)=data)
#define get_DBG_ADDR_reg   (*((volatile unsigned int*) DBG_ADDR_reg))
#define DBG_ADDR_inst_adr                                                            "0x000D"
#define DBG_ADDR_inst                                                                0x000D
#define DBG_ADDR_dbg_addr_shift                                                      (0)
#define DBG_ADDR_dbg_addr_mask                                                       (0xFFFFFFFF)
#define DBG_ADDR_dbg_addr(data)                                                      (0xFFFFFFFF&((data)<<0))
#define DBG_ADDR_dbg_addr_src(data)                                                  ((0xFFFFFFFF&(data))>>0)
#define DBG_ADDR_get_dbg_addr(data)                                                  ((0xFFFFFFFF&(data))>>0)


#define DBG_ADDR1                                                                    0x1805D438
#define DBG_ADDR1_reg_addr                                                           "0xB805D438"
#define DBG_ADDR1_reg                                                                0xB805D438
#define set_DBG_ADDR1_reg(data)   (*((volatile unsigned int*) DBG_ADDR1_reg)=data)
#define get_DBG_ADDR1_reg   (*((volatile unsigned int*) DBG_ADDR1_reg))
#define DBG_ADDR1_inst_adr                                                           "0x000E"
#define DBG_ADDR1_inst                                                               0x000E
#define DBG_ADDR1_scpu_dbg_write_shift                                               (0)
#define DBG_ADDR1_scpu_dbg_write_mask                                                (0x00000001)
#define DBG_ADDR1_scpu_dbg_write(data)                                               (0x00000001&((data)<<0))
#define DBG_ADDR1_scpu_dbg_write_src(data)                                           ((0x00000001&(data))>>0)
#define DBG_ADDR1_get_scpu_dbg_write(data)                                           ((0x00000001&(data))>>0)


#define RM_7_0                                                                       0x1805D600
#define RM_7_0_reg_addr                                                              "0xB805D600"
#define RM_7_0_reg                                                                   0xB805D600
#define set_RM_7_0_reg(data)   (*((volatile unsigned int*) RM_7_0_reg)=data)
#define get_RM_7_0_reg   (*((volatile unsigned int*) RM_7_0_reg))
#define RM_7_0_inst_adr                                                              "0x0080"
#define RM_7_0_inst                                                                  0x0080
#define RM_7_0_RM_7_shift                                                            (28)
#define RM_7_0_RM_7_mask                                                             (0xF0000000)
#define RM_7_0_RM_7(data)                                                            (0xF0000000&((data)<<28))
#define RM_7_0_RM_7_src(data)                                                        ((0xF0000000&(data))>>28)
#define RM_7_0_get_RM_7(data)                                                        ((0xF0000000&(data))>>28)
#define RM_7_0_RM_6_shift                                                            (24)
#define RM_7_0_RM_6_mask                                                             (0x0F000000)
#define RM_7_0_RM_6(data)                                                            (0x0F000000&((data)<<24))
#define RM_7_0_RM_6_src(data)                                                        ((0x0F000000&(data))>>24)
#define RM_7_0_get_RM_6(data)                                                        ((0x0F000000&(data))>>24)
#define RM_7_0_RM_5_shift                                                            (20)
#define RM_7_0_RM_5_mask                                                             (0x00F00000)
#define RM_7_0_RM_5(data)                                                            (0x00F00000&((data)<<20))
#define RM_7_0_RM_5_src(data)                                                        ((0x00F00000&(data))>>20)
#define RM_7_0_get_RM_5(data)                                                        ((0x00F00000&(data))>>20)
#define RM_7_0_RM_4_shift                                                            (16)
#define RM_7_0_RM_4_mask                                                             (0x000F0000)
#define RM_7_0_RM_4(data)                                                            (0x000F0000&((data)<<16))
#define RM_7_0_RM_4_src(data)                                                        ((0x000F0000&(data))>>16)
#define RM_7_0_get_RM_4(data)                                                        ((0x000F0000&(data))>>16)
#define RM_7_0_RM_3_shift                                                            (12)
#define RM_7_0_RM_3_mask                                                             (0x0000F000)
#define RM_7_0_RM_3(data)                                                            (0x0000F000&((data)<<12))
#define RM_7_0_RM_3_src(data)                                                        ((0x0000F000&(data))>>12)
#define RM_7_0_get_RM_3(data)                                                        ((0x0000F000&(data))>>12)
#define RM_7_0_RM_2_shift                                                            (8)
#define RM_7_0_RM_2_mask                                                             (0x00000F00)
#define RM_7_0_RM_2(data)                                                            (0x00000F00&((data)<<8))
#define RM_7_0_RM_2_src(data)                                                        ((0x00000F00&(data))>>8)
#define RM_7_0_get_RM_2(data)                                                        ((0x00000F00&(data))>>8)
#define RM_7_0_RM_1_shift                                                            (4)
#define RM_7_0_RM_1_mask                                                             (0x000000F0)
#define RM_7_0_RM_1(data)                                                            (0x000000F0&((data)<<4))
#define RM_7_0_RM_1_src(data)                                                        ((0x000000F0&(data))>>4)
#define RM_7_0_get_RM_1(data)                                                        ((0x000000F0&(data))>>4)
#define RM_7_0_RM_0_shift                                                            (0)
#define RM_7_0_RM_0_mask                                                             (0x0000000F)
#define RM_7_0_RM_0(data)                                                            (0x0000000F&((data)<<0))
#define RM_7_0_RM_0_src(data)                                                        ((0x0000000F&(data))>>0)
#define RM_7_0_get_RM_0(data)                                                        ((0x0000000F&(data))>>0)


#define RM_15_8                                                                      0x1805D604
#define RM_15_8_reg_addr                                                             "0xB805D604"
#define RM_15_8_reg                                                                  0xB805D604
#define set_RM_15_8_reg(data)   (*((volatile unsigned int*) RM_15_8_reg)=data)
#define get_RM_15_8_reg   (*((volatile unsigned int*) RM_15_8_reg))
#define RM_15_8_inst_adr                                                             "0x0081"
#define RM_15_8_inst                                                                 0x0081
#define RM_15_8_RM_15_shift                                                          (28)
#define RM_15_8_RM_15_mask                                                           (0xF0000000)
#define RM_15_8_RM_15(data)                                                          (0xF0000000&((data)<<28))
#define RM_15_8_RM_15_src(data)                                                      ((0xF0000000&(data))>>28)
#define RM_15_8_get_RM_15(data)                                                      ((0xF0000000&(data))>>28)
#define RM_15_8_RM_14_shift                                                          (24)
#define RM_15_8_RM_14_mask                                                           (0x0F000000)
#define RM_15_8_RM_14(data)                                                          (0x0F000000&((data)<<24))
#define RM_15_8_RM_14_src(data)                                                      ((0x0F000000&(data))>>24)
#define RM_15_8_get_RM_14(data)                                                      ((0x0F000000&(data))>>24)
#define RM_15_8_RM_13_shift                                                          (20)
#define RM_15_8_RM_13_mask                                                           (0x00F00000)
#define RM_15_8_RM_13(data)                                                          (0x00F00000&((data)<<20))
#define RM_15_8_RM_13_src(data)                                                      ((0x00F00000&(data))>>20)
#define RM_15_8_get_RM_13(data)                                                      ((0x00F00000&(data))>>20)
#define RM_15_8_RM_12_shift                                                          (16)
#define RM_15_8_RM_12_mask                                                           (0x000F0000)
#define RM_15_8_RM_12(data)                                                          (0x000F0000&((data)<<16))
#define RM_15_8_RM_12_src(data)                                                      ((0x000F0000&(data))>>16)
#define RM_15_8_get_RM_12(data)                                                      ((0x000F0000&(data))>>16)
#define RM_15_8_RM_11_shift                                                          (12)
#define RM_15_8_RM_11_mask                                                           (0x0000F000)
#define RM_15_8_RM_11(data)                                                          (0x0000F000&((data)<<12))
#define RM_15_8_RM_11_src(data)                                                      ((0x0000F000&(data))>>12)
#define RM_15_8_get_RM_11(data)                                                      ((0x0000F000&(data))>>12)
#define RM_15_8_RM_10_shift                                                          (8)
#define RM_15_8_RM_10_mask                                                           (0x00000F00)
#define RM_15_8_RM_10(data)                                                          (0x00000F00&((data)<<8))
#define RM_15_8_RM_10_src(data)                                                      ((0x00000F00&(data))>>8)
#define RM_15_8_get_RM_10(data)                                                      ((0x00000F00&(data))>>8)
#define RM_15_8_RM_9_shift                                                           (4)
#define RM_15_8_RM_9_mask                                                            (0x000000F0)
#define RM_15_8_RM_9(data)                                                           (0x000000F0&((data)<<4))
#define RM_15_8_RM_9_src(data)                                                       ((0x000000F0&(data))>>4)
#define RM_15_8_get_RM_9(data)                                                       ((0x000000F0&(data))>>4)
#define RM_15_8_RM_8_shift                                                           (0)
#define RM_15_8_RM_8_mask                                                            (0x0000000F)
#define RM_15_8_RM_8(data)                                                           (0x0000000F&((data)<<0))
#define RM_15_8_RM_8_src(data)                                                       ((0x0000000F&(data))>>0)
#define RM_15_8_get_RM_8(data)                                                       ((0x0000000F&(data))>>0)


#define RM_23_16                                                                     0x1805D608
#define RM_23_16_reg_addr                                                            "0xB805D608"
#define RM_23_16_reg                                                                 0xB805D608
#define set_RM_23_16_reg(data)   (*((volatile unsigned int*) RM_23_16_reg)=data)
#define get_RM_23_16_reg   (*((volatile unsigned int*) RM_23_16_reg))
#define RM_23_16_inst_adr                                                            "0x0082"
#define RM_23_16_inst                                                                0x0082
#define RM_23_16_RM_23_shift                                                         (28)
#define RM_23_16_RM_23_mask                                                          (0xF0000000)
#define RM_23_16_RM_23(data)                                                         (0xF0000000&((data)<<28))
#define RM_23_16_RM_23_src(data)                                                     ((0xF0000000&(data))>>28)
#define RM_23_16_get_RM_23(data)                                                     ((0xF0000000&(data))>>28)
#define RM_23_16_RM_22_shift                                                         (24)
#define RM_23_16_RM_22_mask                                                          (0x0F000000)
#define RM_23_16_RM_22(data)                                                         (0x0F000000&((data)<<24))
#define RM_23_16_RM_22_src(data)                                                     ((0x0F000000&(data))>>24)
#define RM_23_16_get_RM_22(data)                                                     ((0x0F000000&(data))>>24)
#define RM_23_16_RM_21_shift                                                         (20)
#define RM_23_16_RM_21_mask                                                          (0x00F00000)
#define RM_23_16_RM_21(data)                                                         (0x00F00000&((data)<<20))
#define RM_23_16_RM_21_src(data)                                                     ((0x00F00000&(data))>>20)
#define RM_23_16_get_RM_21(data)                                                     ((0x00F00000&(data))>>20)
#define RM_23_16_RM_20_shift                                                         (16)
#define RM_23_16_RM_20_mask                                                          (0x000F0000)
#define RM_23_16_RM_20(data)                                                         (0x000F0000&((data)<<16))
#define RM_23_16_RM_20_src(data)                                                     ((0x000F0000&(data))>>16)
#define RM_23_16_get_RM_20(data)                                                     ((0x000F0000&(data))>>16)
#define RM_23_16_RM_19_shift                                                         (12)
#define RM_23_16_RM_19_mask                                                          (0x0000F000)
#define RM_23_16_RM_19(data)                                                         (0x0000F000&((data)<<12))
#define RM_23_16_RM_19_src(data)                                                     ((0x0000F000&(data))>>12)
#define RM_23_16_get_RM_19(data)                                                     ((0x0000F000&(data))>>12)
#define RM_23_16_RM_18_shift                                                         (8)
#define RM_23_16_RM_18_mask                                                          (0x00000F00)
#define RM_23_16_RM_18(data)                                                         (0x00000F00&((data)<<8))
#define RM_23_16_RM_18_src(data)                                                     ((0x00000F00&(data))>>8)
#define RM_23_16_get_RM_18(data)                                                     ((0x00000F00&(data))>>8)
#define RM_23_16_RM_17_shift                                                         (4)
#define RM_23_16_RM_17_mask                                                          (0x000000F0)
#define RM_23_16_RM_17(data)                                                         (0x000000F0&((data)<<4))
#define RM_23_16_RM_17_src(data)                                                     ((0x000000F0&(data))>>4)
#define RM_23_16_get_RM_17(data)                                                     ((0x000000F0&(data))>>4)
#define RM_23_16_RM_16_shift                                                         (0)
#define RM_23_16_RM_16_mask                                                          (0x0000000F)
#define RM_23_16_RM_16(data)                                                         (0x0000000F&((data)<<0))
#define RM_23_16_RM_16_src(data)                                                     ((0x0000000F&(data))>>0)
#define RM_23_16_get_RM_16(data)                                                     ((0x0000000F&(data))>>0)


#define RM_31_24                                                                     0x1805D60c
#define RM_31_24_reg_addr                                                            "0xB805D60C"
#define RM_31_24_reg                                                                 0xB805D60C
#define set_RM_31_24_reg(data)   (*((volatile unsigned int*) RM_31_24_reg)=data)
#define get_RM_31_24_reg   (*((volatile unsigned int*) RM_31_24_reg))
#define RM_31_24_inst_adr                                                            "0x0083"
#define RM_31_24_inst                                                                0x0083
#define RM_31_24_RM_31_shift                                                         (28)
#define RM_31_24_RM_31_mask                                                          (0xF0000000)
#define RM_31_24_RM_31(data)                                                         (0xF0000000&((data)<<28))
#define RM_31_24_RM_31_src(data)                                                     ((0xF0000000&(data))>>28)
#define RM_31_24_get_RM_31(data)                                                     ((0xF0000000&(data))>>28)
#define RM_31_24_RM_30_shift                                                         (24)
#define RM_31_24_RM_30_mask                                                          (0x0F000000)
#define RM_31_24_RM_30(data)                                                         (0x0F000000&((data)<<24))
#define RM_31_24_RM_30_src(data)                                                     ((0x0F000000&(data))>>24)
#define RM_31_24_get_RM_30(data)                                                     ((0x0F000000&(data))>>24)
#define RM_31_24_RM_29_shift                                                         (20)
#define RM_31_24_RM_29_mask                                                          (0x00F00000)
#define RM_31_24_RM_29(data)                                                         (0x00F00000&((data)<<20))
#define RM_31_24_RM_29_src(data)                                                     ((0x00F00000&(data))>>20)
#define RM_31_24_get_RM_29(data)                                                     ((0x00F00000&(data))>>20)
#define RM_31_24_RM_28_shift                                                         (16)
#define RM_31_24_RM_28_mask                                                          (0x000F0000)
#define RM_31_24_RM_28(data)                                                         (0x000F0000&((data)<<16))
#define RM_31_24_RM_28_src(data)                                                     ((0x000F0000&(data))>>16)
#define RM_31_24_get_RM_28(data)                                                     ((0x000F0000&(data))>>16)
#define RM_31_24_RM_27_shift                                                         (12)
#define RM_31_24_RM_27_mask                                                          (0x0000F000)
#define RM_31_24_RM_27(data)                                                         (0x0000F000&((data)<<12))
#define RM_31_24_RM_27_src(data)                                                     ((0x0000F000&(data))>>12)
#define RM_31_24_get_RM_27(data)                                                     ((0x0000F000&(data))>>12)
#define RM_31_24_RM_26_shift                                                         (8)
#define RM_31_24_RM_26_mask                                                          (0x00000F00)
#define RM_31_24_RM_26(data)                                                         (0x00000F00&((data)<<8))
#define RM_31_24_RM_26_src(data)                                                     ((0x00000F00&(data))>>8)
#define RM_31_24_get_RM_26(data)                                                     ((0x00000F00&(data))>>8)
#define RM_31_24_RM_25_shift                                                         (4)
#define RM_31_24_RM_25_mask                                                          (0x000000F0)
#define RM_31_24_RM_25(data)                                                         (0x000000F0&((data)<<4))
#define RM_31_24_RM_25_src(data)                                                     ((0x000000F0&(data))>>4)
#define RM_31_24_get_RM_25(data)                                                     ((0x000000F0&(data))>>4)
#define RM_31_24_RM_24_shift                                                         (0)
#define RM_31_24_RM_24_mask                                                          (0x0000000F)
#define RM_31_24_RM_24(data)                                                         (0x0000000F&((data)<<0))
#define RM_31_24_RM_24_src(data)                                                     ((0x0000000F&(data))>>0)
#define RM_31_24_get_RM_24(data)                                                     ((0x0000000F&(data))>>0)


#define RM_33_32                                                                     0x1805D610
#define RM_33_32_reg_addr                                                            "0xB805D610"
#define RM_33_32_reg                                                                 0xB805D610
#define set_RM_33_32_reg(data)   (*((volatile unsigned int*) RM_33_32_reg)=data)
#define get_RM_33_32_reg   (*((volatile unsigned int*) RM_33_32_reg))
#define RM_33_32_inst_adr                                                            "0x0084"
#define RM_33_32_inst                                                                0x0084
#define RM_33_32_RME_shift                                                           (8)
#define RM_33_32_RME_mask                                                            (0x00000100)
#define RM_33_32_RME(data)                                                           (0x00000100&((data)<<8))
#define RM_33_32_RME_src(data)                                                       ((0x00000100&(data))>>8)
#define RM_33_32_get_RME(data)                                                       ((0x00000100&(data))>>8)
#define RM_33_32_RM_33_shift                                                         (4)
#define RM_33_32_RM_33_mask                                                          (0x000000F0)
#define RM_33_32_RM_33(data)                                                         (0x000000F0&((data)<<4))
#define RM_33_32_RM_33_src(data)                                                     ((0x000000F0&(data))>>4)
#define RM_33_32_get_RM_33(data)                                                     ((0x000000F0&(data))>>4)
#define RM_33_32_RM_32_shift                                                         (0)
#define RM_33_32_RM_32_mask                                                          (0x0000000F)
#define RM_33_32_RM_32(data)                                                         (0x0000000F&((data)<<0))
#define RM_33_32_RM_32_src(data)                                                     ((0x0000000F&(data))>>0)
#define RM_33_32_get_RM_32(data)                                                     ((0x0000000F&(data))>>0)


#define LS_7_0                                                                       0x1805D614
#define LS_7_0_reg_addr                                                              "0xB805D614"
#define LS_7_0_reg                                                                   0xB805D614
#define set_LS_7_0_reg(data)   (*((volatile unsigned int*) LS_7_0_reg)=data)
#define get_LS_7_0_reg   (*((volatile unsigned int*) LS_7_0_reg))
#define LS_7_0_inst_adr                                                              "0x0085"
#define LS_7_0_inst                                                                  0x0085
#define LS_7_0_LS_7_shift                                                            (7)
#define LS_7_0_LS_7_mask                                                             (0x00000080)
#define LS_7_0_LS_7(data)                                                            (0x00000080&((data)<<7))
#define LS_7_0_LS_7_src(data)                                                        ((0x00000080&(data))>>7)
#define LS_7_0_get_LS_7(data)                                                        ((0x00000080&(data))>>7)
#define LS_7_0_LS_6_shift                                                            (6)
#define LS_7_0_LS_6_mask                                                             (0x00000040)
#define LS_7_0_LS_6(data)                                                            (0x00000040&((data)<<6))
#define LS_7_0_LS_6_src(data)                                                        ((0x00000040&(data))>>6)
#define LS_7_0_get_LS_6(data)                                                        ((0x00000040&(data))>>6)
#define LS_7_0_LS_5_shift                                                            (5)
#define LS_7_0_LS_5_mask                                                             (0x00000020)
#define LS_7_0_LS_5(data)                                                            (0x00000020&((data)<<5))
#define LS_7_0_LS_5_src(data)                                                        ((0x00000020&(data))>>5)
#define LS_7_0_get_LS_5(data)                                                        ((0x00000020&(data))>>5)
#define LS_7_0_LS_4_shift                                                            (4)
#define LS_7_0_LS_4_mask                                                             (0x00000010)
#define LS_7_0_LS_4(data)                                                            (0x00000010&((data)<<4))
#define LS_7_0_LS_4_src(data)                                                        ((0x00000010&(data))>>4)
#define LS_7_0_get_LS_4(data)                                                        ((0x00000010&(data))>>4)
#define LS_7_0_LS_3_shift                                                            (3)
#define LS_7_0_LS_3_mask                                                             (0x00000008)
#define LS_7_0_LS_3(data)                                                            (0x00000008&((data)<<3))
#define LS_7_0_LS_3_src(data)                                                        ((0x00000008&(data))>>3)
#define LS_7_0_get_LS_3(data)                                                        ((0x00000008&(data))>>3)
#define LS_7_0_LS_2_shift                                                            (2)
#define LS_7_0_LS_2_mask                                                             (0x00000004)
#define LS_7_0_LS_2(data)                                                            (0x00000004&((data)<<2))
#define LS_7_0_LS_2_src(data)                                                        ((0x00000004&(data))>>2)
#define LS_7_0_get_LS_2(data)                                                        ((0x00000004&(data))>>2)
#define LS_7_0_LS_1_shift                                                            (1)
#define LS_7_0_LS_1_mask                                                             (0x00000002)
#define LS_7_0_LS_1(data)                                                            (0x00000002&((data)<<1))
#define LS_7_0_LS_1_src(data)                                                        ((0x00000002&(data))>>1)
#define LS_7_0_get_LS_1(data)                                                        ((0x00000002&(data))>>1)
#define LS_7_0_LS_0_shift                                                            (0)
#define LS_7_0_LS_0_mask                                                             (0x00000001)
#define LS_7_0_LS_0(data)                                                            (0x00000001&((data)<<0))
#define LS_7_0_LS_0_src(data)                                                        ((0x00000001&(data))>>0)
#define LS_7_0_get_LS_0(data)                                                        ((0x00000001&(data))>>0)


#define LS_15_8                                                                      0x1805D618
#define LS_15_8_reg_addr                                                             "0xB805D618"
#define LS_15_8_reg                                                                  0xB805D618
#define set_LS_15_8_reg(data)   (*((volatile unsigned int*) LS_15_8_reg)=data)
#define get_LS_15_8_reg   (*((volatile unsigned int*) LS_15_8_reg))
#define LS_15_8_inst_adr                                                             "0x0086"
#define LS_15_8_inst                                                                 0x0086
#define LS_15_8_LS_15_shift                                                          (7)
#define LS_15_8_LS_15_mask                                                           (0x00000080)
#define LS_15_8_LS_15(data)                                                          (0x00000080&((data)<<7))
#define LS_15_8_LS_15_src(data)                                                      ((0x00000080&(data))>>7)
#define LS_15_8_get_LS_15(data)                                                      ((0x00000080&(data))>>7)
#define LS_15_8_LS_14_shift                                                          (6)
#define LS_15_8_LS_14_mask                                                           (0x00000040)
#define LS_15_8_LS_14(data)                                                          (0x00000040&((data)<<6))
#define LS_15_8_LS_14_src(data)                                                      ((0x00000040&(data))>>6)
#define LS_15_8_get_LS_14(data)                                                      ((0x00000040&(data))>>6)
#define LS_15_8_LS_13_shift                                                          (5)
#define LS_15_8_LS_13_mask                                                           (0x00000020)
#define LS_15_8_LS_13(data)                                                          (0x00000020&((data)<<5))
#define LS_15_8_LS_13_src(data)                                                      ((0x00000020&(data))>>5)
#define LS_15_8_get_LS_13(data)                                                      ((0x00000020&(data))>>5)
#define LS_15_8_LS_12_shift                                                          (4)
#define LS_15_8_LS_12_mask                                                           (0x00000010)
#define LS_15_8_LS_12(data)                                                          (0x00000010&((data)<<4))
#define LS_15_8_LS_12_src(data)                                                      ((0x00000010&(data))>>4)
#define LS_15_8_get_LS_12(data)                                                      ((0x00000010&(data))>>4)
#define LS_15_8_LS_11_shift                                                          (3)
#define LS_15_8_LS_11_mask                                                           (0x00000008)
#define LS_15_8_LS_11(data)                                                          (0x00000008&((data)<<3))
#define LS_15_8_LS_11_src(data)                                                      ((0x00000008&(data))>>3)
#define LS_15_8_get_LS_11(data)                                                      ((0x00000008&(data))>>3)
#define LS_15_8_LS_10_shift                                                          (2)
#define LS_15_8_LS_10_mask                                                           (0x00000004)
#define LS_15_8_LS_10(data)                                                          (0x00000004&((data)<<2))
#define LS_15_8_LS_10_src(data)                                                      ((0x00000004&(data))>>2)
#define LS_15_8_get_LS_10(data)                                                      ((0x00000004&(data))>>2)
#define LS_15_8_LS_9_shift                                                           (1)
#define LS_15_8_LS_9_mask                                                            (0x00000002)
#define LS_15_8_LS_9(data)                                                           (0x00000002&((data)<<1))
#define LS_15_8_LS_9_src(data)                                                       ((0x00000002&(data))>>1)
#define LS_15_8_get_LS_9(data)                                                       ((0x00000002&(data))>>1)
#define LS_15_8_LS_8_shift                                                           (0)
#define LS_15_8_LS_8_mask                                                            (0x00000001)
#define LS_15_8_LS_8(data)                                                           (0x00000001&((data)<<0))
#define LS_15_8_LS_8_src(data)                                                       ((0x00000001&(data))>>0)
#define LS_15_8_get_LS_8(data)                                                       ((0x00000001&(data))>>0)


#define LS_23_16                                                                     0x1805D61c
#define LS_23_16_reg_addr                                                            "0xB805D61C"
#define LS_23_16_reg                                                                 0xB805D61C
#define set_LS_23_16_reg(data)   (*((volatile unsigned int*) LS_23_16_reg)=data)
#define get_LS_23_16_reg   (*((volatile unsigned int*) LS_23_16_reg))
#define LS_23_16_inst_adr                                                            "0x0087"
#define LS_23_16_inst                                                                0x0087
#define LS_23_16_LS_23_shift                                                         (7)
#define LS_23_16_LS_23_mask                                                          (0x00000080)
#define LS_23_16_LS_23(data)                                                         (0x00000080&((data)<<7))
#define LS_23_16_LS_23_src(data)                                                     ((0x00000080&(data))>>7)
#define LS_23_16_get_LS_23(data)                                                     ((0x00000080&(data))>>7)
#define LS_23_16_LS_22_shift                                                         (6)
#define LS_23_16_LS_22_mask                                                          (0x00000040)
#define LS_23_16_LS_22(data)                                                         (0x00000040&((data)<<6))
#define LS_23_16_LS_22_src(data)                                                     ((0x00000040&(data))>>6)
#define LS_23_16_get_LS_22(data)                                                     ((0x00000040&(data))>>6)
#define LS_23_16_LS_21_shift                                                         (5)
#define LS_23_16_LS_21_mask                                                          (0x00000020)
#define LS_23_16_LS_21(data)                                                         (0x00000020&((data)<<5))
#define LS_23_16_LS_21_src(data)                                                     ((0x00000020&(data))>>5)
#define LS_23_16_get_LS_21(data)                                                     ((0x00000020&(data))>>5)
#define LS_23_16_LS_20_shift                                                         (4)
#define LS_23_16_LS_20_mask                                                          (0x00000010)
#define LS_23_16_LS_20(data)                                                         (0x00000010&((data)<<4))
#define LS_23_16_LS_20_src(data)                                                     ((0x00000010&(data))>>4)
#define LS_23_16_get_LS_20(data)                                                     ((0x00000010&(data))>>4)
#define LS_23_16_LS_19_shift                                                         (3)
#define LS_23_16_LS_19_mask                                                          (0x00000008)
#define LS_23_16_LS_19(data)                                                         (0x00000008&((data)<<3))
#define LS_23_16_LS_19_src(data)                                                     ((0x00000008&(data))>>3)
#define LS_23_16_get_LS_19(data)                                                     ((0x00000008&(data))>>3)
#define LS_23_16_LS_18_shift                                                         (2)
#define LS_23_16_LS_18_mask                                                          (0x00000004)
#define LS_23_16_LS_18(data)                                                         (0x00000004&((data)<<2))
#define LS_23_16_LS_18_src(data)                                                     ((0x00000004&(data))>>2)
#define LS_23_16_get_LS_18(data)                                                     ((0x00000004&(data))>>2)
#define LS_23_16_LS_17_shift                                                         (1)
#define LS_23_16_LS_17_mask                                                          (0x00000002)
#define LS_23_16_LS_17(data)                                                         (0x00000002&((data)<<1))
#define LS_23_16_LS_17_src(data)                                                     ((0x00000002&(data))>>1)
#define LS_23_16_get_LS_17(data)                                                     ((0x00000002&(data))>>1)
#define LS_23_16_LS_16_shift                                                         (0)
#define LS_23_16_LS_16_mask                                                          (0x00000001)
#define LS_23_16_LS_16(data)                                                         (0x00000001&((data)<<0))
#define LS_23_16_LS_16_src(data)                                                     ((0x00000001&(data))>>0)
#define LS_23_16_get_LS_16(data)                                                     ((0x00000001&(data))>>0)


#define LS_31_24                                                                     0x1805D620
#define LS_31_24_reg_addr                                                            "0xB805D620"
#define LS_31_24_reg                                                                 0xB805D620
#define set_LS_31_24_reg(data)   (*((volatile unsigned int*) LS_31_24_reg)=data)
#define get_LS_31_24_reg   (*((volatile unsigned int*) LS_31_24_reg))
#define LS_31_24_inst_adr                                                            "0x0088"
#define LS_31_24_inst                                                                0x0088
#define LS_31_24_LS_31_shift                                                         (7)
#define LS_31_24_LS_31_mask                                                          (0x00000080)
#define LS_31_24_LS_31(data)                                                         (0x00000080&((data)<<7))
#define LS_31_24_LS_31_src(data)                                                     ((0x00000080&(data))>>7)
#define LS_31_24_get_LS_31(data)                                                     ((0x00000080&(data))>>7)
#define LS_31_24_LS_30_shift                                                         (6)
#define LS_31_24_LS_30_mask                                                          (0x00000040)
#define LS_31_24_LS_30(data)                                                         (0x00000040&((data)<<6))
#define LS_31_24_LS_30_src(data)                                                     ((0x00000040&(data))>>6)
#define LS_31_24_get_LS_30(data)                                                     ((0x00000040&(data))>>6)
#define LS_31_24_LS_29_shift                                                         (5)
#define LS_31_24_LS_29_mask                                                          (0x00000020)
#define LS_31_24_LS_29(data)                                                         (0x00000020&((data)<<5))
#define LS_31_24_LS_29_src(data)                                                     ((0x00000020&(data))>>5)
#define LS_31_24_get_LS_29(data)                                                     ((0x00000020&(data))>>5)
#define LS_31_24_LS_28_shift                                                         (4)
#define LS_31_24_LS_28_mask                                                          (0x00000010)
#define LS_31_24_LS_28(data)                                                         (0x00000010&((data)<<4))
#define LS_31_24_LS_28_src(data)                                                     ((0x00000010&(data))>>4)
#define LS_31_24_get_LS_28(data)                                                     ((0x00000010&(data))>>4)
#define LS_31_24_LS_27_shift                                                         (3)
#define LS_31_24_LS_27_mask                                                          (0x00000008)
#define LS_31_24_LS_27(data)                                                         (0x00000008&((data)<<3))
#define LS_31_24_LS_27_src(data)                                                     ((0x00000008&(data))>>3)
#define LS_31_24_get_LS_27(data)                                                     ((0x00000008&(data))>>3)
#define LS_31_24_LS_26_shift                                                         (2)
#define LS_31_24_LS_26_mask                                                          (0x00000004)
#define LS_31_24_LS_26(data)                                                         (0x00000004&((data)<<2))
#define LS_31_24_LS_26_src(data)                                                     ((0x00000004&(data))>>2)
#define LS_31_24_get_LS_26(data)                                                     ((0x00000004&(data))>>2)
#define LS_31_24_LS_25_shift                                                         (1)
#define LS_31_24_LS_25_mask                                                          (0x00000002)
#define LS_31_24_LS_25(data)                                                         (0x00000002&((data)<<1))
#define LS_31_24_LS_25_src(data)                                                     ((0x00000002&(data))>>1)
#define LS_31_24_get_LS_25(data)                                                     ((0x00000002&(data))>>1)
#define LS_31_24_LS_24_shift                                                         (0)
#define LS_31_24_LS_24_mask                                                          (0x00000001)
#define LS_31_24_LS_24(data)                                                         (0x00000001&((data)<<0))
#define LS_31_24_LS_24_src(data)                                                     ((0x00000001&(data))>>0)
#define LS_31_24_get_LS_24(data)                                                     ((0x00000001&(data))>>0)


#define LS_33_32                                                                     0x1805D624
#define LS_33_32_reg_addr                                                            "0xB805D624"
#define LS_33_32_reg                                                                 0xB805D624
#define set_LS_33_32_reg(data)   (*((volatile unsigned int*) LS_33_32_reg)=data)
#define get_LS_33_32_reg   (*((volatile unsigned int*) LS_33_32_reg))
#define LS_33_32_inst_adr                                                            "0x0089"
#define LS_33_32_inst                                                                0x0089
#define LS_33_32_LS_33_shift                                                         (1)
#define LS_33_32_LS_33_mask                                                          (0x00000002)
#define LS_33_32_LS_33(data)                                                         (0x00000002&((data)<<1))
#define LS_33_32_LS_33_src(data)                                                     ((0x00000002&(data))>>1)
#define LS_33_32_get_LS_33(data)                                                     ((0x00000002&(data))>>1)
#define LS_33_32_LS_32_shift                                                         (0)
#define LS_33_32_LS_32_mask                                                          (0x00000001)
#define LS_33_32_LS_32(data)                                                         (0x00000001&((data)<<0))
#define LS_33_32_LS_32_src(data)                                                     ((0x00000001&(data))>>0)
#define LS_33_32_get_LS_32(data)                                                     ((0x00000001&(data))>>0)


#define BIST_MODE                                                                    0x1805D630
#define BIST_MODE_reg_addr                                                           "0xB805D630"
#define BIST_MODE_reg                                                                0xB805D630
#define set_BIST_MODE_reg(data)   (*((volatile unsigned int*) BIST_MODE_reg)=data)
#define get_BIST_MODE_reg   (*((volatile unsigned int*) BIST_MODE_reg))
#define BIST_MODE_inst_adr                                                           "0x008C"
#define BIST_MODE_inst                                                               0x008C
#define BIST_MODE_BIST3_MODE_shift                                                   (3)
#define BIST_MODE_BIST3_MODE_mask                                                    (0x00000008)
#define BIST_MODE_BIST3_MODE(data)                                                   (0x00000008&((data)<<3))
#define BIST_MODE_BIST3_MODE_src(data)                                               ((0x00000008&(data))>>3)
#define BIST_MODE_get_BIST3_MODE(data)                                               ((0x00000008&(data))>>3)
#define BIST_MODE_BIST2_MODE_shift                                                   (2)
#define BIST_MODE_BIST2_MODE_mask                                                    (0x00000004)
#define BIST_MODE_BIST2_MODE(data)                                                   (0x00000004&((data)<<2))
#define BIST_MODE_BIST2_MODE_src(data)                                               ((0x00000004&(data))>>2)
#define BIST_MODE_get_BIST2_MODE(data)                                               ((0x00000004&(data))>>2)
#define BIST_MODE_BIST1_MODE_shift                                                   (1)
#define BIST_MODE_BIST1_MODE_mask                                                    (0x00000002)
#define BIST_MODE_BIST1_MODE(data)                                                   (0x00000002&((data)<<1))
#define BIST_MODE_BIST1_MODE_src(data)                                               ((0x00000002&(data))>>1)
#define BIST_MODE_get_BIST1_MODE(data)                                               ((0x00000002&(data))>>1)
#define BIST_MODE_BIST0_MODE_shift                                                   (0)
#define BIST_MODE_BIST0_MODE_mask                                                    (0x00000001)
#define BIST_MODE_BIST0_MODE(data)                                                   (0x00000001&((data)<<0))
#define BIST_MODE_BIST0_MODE_src(data)                                               ((0x00000001&(data))>>0)
#define BIST_MODE_get_BIST0_MODE(data)                                               ((0x00000001&(data))>>0)


#define DRF_BIST_MODE                                                                0x1805D634
#define DRF_BIST_MODE_reg_addr                                                       "0xB805D634"
#define DRF_BIST_MODE_reg                                                            0xB805D634
#define set_DRF_BIST_MODE_reg(data)   (*((volatile unsigned int*) DRF_BIST_MODE_reg)=data)
#define get_DRF_BIST_MODE_reg   (*((volatile unsigned int*) DRF_BIST_MODE_reg))
#define DRF_BIST_MODE_inst_adr                                                       "0x008D"
#define DRF_BIST_MODE_inst                                                           0x008D
#define DRF_BIST_MODE_DRF_BIST3_MODE_shift                                           (3)
#define DRF_BIST_MODE_DRF_BIST3_MODE_mask                                            (0x00000008)
#define DRF_BIST_MODE_DRF_BIST3_MODE(data)                                           (0x00000008&((data)<<3))
#define DRF_BIST_MODE_DRF_BIST3_MODE_src(data)                                       ((0x00000008&(data))>>3)
#define DRF_BIST_MODE_get_DRF_BIST3_MODE(data)                                       ((0x00000008&(data))>>3)
#define DRF_BIST_MODE_DRF_BIST2_MODE_shift                                           (2)
#define DRF_BIST_MODE_DRF_BIST2_MODE_mask                                            (0x00000004)
#define DRF_BIST_MODE_DRF_BIST2_MODE(data)                                           (0x00000004&((data)<<2))
#define DRF_BIST_MODE_DRF_BIST2_MODE_src(data)                                       ((0x00000004&(data))>>2)
#define DRF_BIST_MODE_get_DRF_BIST2_MODE(data)                                       ((0x00000004&(data))>>2)
#define DRF_BIST_MODE_DRF_BIST1_MODE_shift                                           (1)
#define DRF_BIST_MODE_DRF_BIST1_MODE_mask                                            (0x00000002)
#define DRF_BIST_MODE_DRF_BIST1_MODE(data)                                           (0x00000002&((data)<<1))
#define DRF_BIST_MODE_DRF_BIST1_MODE_src(data)                                       ((0x00000002&(data))>>1)
#define DRF_BIST_MODE_get_DRF_BIST1_MODE(data)                                       ((0x00000002&(data))>>1)
#define DRF_BIST_MODE_DRF_BIST0_MODE_shift                                           (0)
#define DRF_BIST_MODE_DRF_BIST0_MODE_mask                                            (0x00000001)
#define DRF_BIST_MODE_DRF_BIST0_MODE(data)                                           (0x00000001&((data)<<0))
#define DRF_BIST_MODE_DRF_BIST0_MODE_src(data)                                       ((0x00000001&(data))>>0)
#define DRF_BIST_MODE_get_DRF_BIST0_MODE(data)                                       ((0x00000001&(data))>>0)


#define DRF_BIST_TEST_RESUME                                                         0x1805D638
#define DRF_BIST_TEST_RESUME_reg_addr                                                "0xB805D638"
#define DRF_BIST_TEST_RESUME_reg                                                     0xB805D638
#define set_DRF_BIST_TEST_RESUME_reg(data)   (*((volatile unsigned int*) DRF_BIST_TEST_RESUME_reg)=data)
#define get_DRF_BIST_TEST_RESUME_reg   (*((volatile unsigned int*) DRF_BIST_TEST_RESUME_reg))
#define DRF_BIST_TEST_RESUME_inst_adr                                                "0x008E"
#define DRF_BIST_TEST_RESUME_inst                                                    0x008E
#define DRF_BIST_TEST_RESUME_DRF_BIST3_TEST_RESUME_shift                             (3)
#define DRF_BIST_TEST_RESUME_DRF_BIST3_TEST_RESUME_mask                              (0x00000008)
#define DRF_BIST_TEST_RESUME_DRF_BIST3_TEST_RESUME(data)                             (0x00000008&((data)<<3))
#define DRF_BIST_TEST_RESUME_DRF_BIST3_TEST_RESUME_src(data)                         ((0x00000008&(data))>>3)
#define DRF_BIST_TEST_RESUME_get_DRF_BIST3_TEST_RESUME(data)                         ((0x00000008&(data))>>3)
#define DRF_BIST_TEST_RESUME_DRF_BIST2_TEST_RESUME_shift                             (2)
#define DRF_BIST_TEST_RESUME_DRF_BIST2_TEST_RESUME_mask                              (0x00000004)
#define DRF_BIST_TEST_RESUME_DRF_BIST2_TEST_RESUME(data)                             (0x00000004&((data)<<2))
#define DRF_BIST_TEST_RESUME_DRF_BIST2_TEST_RESUME_src(data)                         ((0x00000004&(data))>>2)
#define DRF_BIST_TEST_RESUME_get_DRF_BIST2_TEST_RESUME(data)                         ((0x00000004&(data))>>2)
#define DRF_BIST_TEST_RESUME_DRF_BIST1_TEST_RESUME_shift                             (1)
#define DRF_BIST_TEST_RESUME_DRF_BIST1_TEST_RESUME_mask                              (0x00000002)
#define DRF_BIST_TEST_RESUME_DRF_BIST1_TEST_RESUME(data)                             (0x00000002&((data)<<1))
#define DRF_BIST_TEST_RESUME_DRF_BIST1_TEST_RESUME_src(data)                         ((0x00000002&(data))>>1)
#define DRF_BIST_TEST_RESUME_get_DRF_BIST1_TEST_RESUME(data)                         ((0x00000002&(data))>>1)
#define DRF_BIST_TEST_RESUME_DRF_BIST0_TEST_RESUME_shift                             (0)
#define DRF_BIST_TEST_RESUME_DRF_BIST0_TEST_RESUME_mask                              (0x00000001)
#define DRF_BIST_TEST_RESUME_DRF_BIST0_TEST_RESUME(data)                             (0x00000001&((data)<<0))
#define DRF_BIST_TEST_RESUME_DRF_BIST0_TEST_RESUME_src(data)                         ((0x00000001&(data))>>0)
#define DRF_BIST_TEST_RESUME_get_DRF_BIST0_TEST_RESUME(data)                         ((0x00000001&(data))>>0)


#define BIST_DONE                                                                    0x1805D63C
#define BIST_DONE_reg_addr                                                           "0xB805D63C"
#define BIST_DONE_reg                                                                0xB805D63C
#define set_BIST_DONE_reg(data)   (*((volatile unsigned int*) BIST_DONE_reg)=data)
#define get_BIST_DONE_reg   (*((volatile unsigned int*) BIST_DONE_reg))
#define BIST_DONE_inst_adr                                                           "0x008F"
#define BIST_DONE_inst                                                               0x008F
#define BIST_DONE_BIST3_DONE_shift                                                   (3)
#define BIST_DONE_BIST3_DONE_mask                                                    (0x00000008)
#define BIST_DONE_BIST3_DONE(data)                                                   (0x00000008&((data)<<3))
#define BIST_DONE_BIST3_DONE_src(data)                                               ((0x00000008&(data))>>3)
#define BIST_DONE_get_BIST3_DONE(data)                                               ((0x00000008&(data))>>3)
#define BIST_DONE_BIST2_DONE_shift                                                   (2)
#define BIST_DONE_BIST2_DONE_mask                                                    (0x00000004)
#define BIST_DONE_BIST2_DONE(data)                                                   (0x00000004&((data)<<2))
#define BIST_DONE_BIST2_DONE_src(data)                                               ((0x00000004&(data))>>2)
#define BIST_DONE_get_BIST2_DONE(data)                                               ((0x00000004&(data))>>2)
#define BIST_DONE_BIST1_DONE_shift                                                   (1)
#define BIST_DONE_BIST1_DONE_mask                                                    (0x00000002)
#define BIST_DONE_BIST1_DONE(data)                                                   (0x00000002&((data)<<1))
#define BIST_DONE_BIST1_DONE_src(data)                                               ((0x00000002&(data))>>1)
#define BIST_DONE_get_BIST1_DONE(data)                                               ((0x00000002&(data))>>1)
#define BIST_DONE_BIST0_DONE_shift                                                   (0)
#define BIST_DONE_BIST0_DONE_mask                                                    (0x00000001)
#define BIST_DONE_BIST0_DONE(data)                                                   (0x00000001&((data)<<0))
#define BIST_DONE_BIST0_DONE_src(data)                                               ((0x00000001&(data))>>0)
#define BIST_DONE_get_BIST0_DONE(data)                                               ((0x00000001&(data))>>0)


#define DRF_BIST_DONE                                                                0x1805D640
#define DRF_BIST_DONE_reg_addr                                                       "0xB805D640"
#define DRF_BIST_DONE_reg                                                            0xB805D640
#define set_DRF_BIST_DONE_reg(data)   (*((volatile unsigned int*) DRF_BIST_DONE_reg)=data)
#define get_DRF_BIST_DONE_reg   (*((volatile unsigned int*) DRF_BIST_DONE_reg))
#define DRF_BIST_DONE_inst_adr                                                       "0x0090"
#define DRF_BIST_DONE_inst                                                           0x0090
#define DRF_BIST_DONE_DRF_BIST3_DONE_shift                                           (3)
#define DRF_BIST_DONE_DRF_BIST3_DONE_mask                                            (0x00000008)
#define DRF_BIST_DONE_DRF_BIST3_DONE(data)                                           (0x00000008&((data)<<3))
#define DRF_BIST_DONE_DRF_BIST3_DONE_src(data)                                       ((0x00000008&(data))>>3)
#define DRF_BIST_DONE_get_DRF_BIST3_DONE(data)                                       ((0x00000008&(data))>>3)
#define DRF_BIST_DONE_DRF_BIST2_DONE_shift                                           (2)
#define DRF_BIST_DONE_DRF_BIST2_DONE_mask                                            (0x00000004)
#define DRF_BIST_DONE_DRF_BIST2_DONE(data)                                           (0x00000004&((data)<<2))
#define DRF_BIST_DONE_DRF_BIST2_DONE_src(data)                                       ((0x00000004&(data))>>2)
#define DRF_BIST_DONE_get_DRF_BIST2_DONE(data)                                       ((0x00000004&(data))>>2)
#define DRF_BIST_DONE_DRF_BIST1_DONE_shift                                           (1)
#define DRF_BIST_DONE_DRF_BIST1_DONE_mask                                            (0x00000002)
#define DRF_BIST_DONE_DRF_BIST1_DONE(data)                                           (0x00000002&((data)<<1))
#define DRF_BIST_DONE_DRF_BIST1_DONE_src(data)                                       ((0x00000002&(data))>>1)
#define DRF_BIST_DONE_get_DRF_BIST1_DONE(data)                                       ((0x00000002&(data))>>1)
#define DRF_BIST_DONE_DRF_BIST0_DONE_shift                                           (0)
#define DRF_BIST_DONE_DRF_BIST0_DONE_mask                                            (0x00000001)
#define DRF_BIST_DONE_DRF_BIST0_DONE(data)                                           (0x00000001&((data)<<0))
#define DRF_BIST_DONE_DRF_BIST0_DONE_src(data)                                       ((0x00000001&(data))>>0)
#define DRF_BIST_DONE_get_DRF_BIST0_DONE(data)                                       ((0x00000001&(data))>>0)


#define DRF_BIST_START_PAUSE                                                         0x1805D644
#define DRF_BIST_START_PAUSE_reg_addr                                                "0xB805D644"
#define DRF_BIST_START_PAUSE_reg                                                     0xB805D644
#define set_DRF_BIST_START_PAUSE_reg(data)   (*((volatile unsigned int*) DRF_BIST_START_PAUSE_reg)=data)
#define get_DRF_BIST_START_PAUSE_reg   (*((volatile unsigned int*) DRF_BIST_START_PAUSE_reg))
#define DRF_BIST_START_PAUSE_inst_adr                                                "0x0091"
#define DRF_BIST_START_PAUSE_inst                                                    0x0091
#define DRF_BIST_START_PAUSE_DRF_BIST3_START_PAUSE_shift                             (3)
#define DRF_BIST_START_PAUSE_DRF_BIST3_START_PAUSE_mask                              (0x00000008)
#define DRF_BIST_START_PAUSE_DRF_BIST3_START_PAUSE(data)                             (0x00000008&((data)<<3))
#define DRF_BIST_START_PAUSE_DRF_BIST3_START_PAUSE_src(data)                         ((0x00000008&(data))>>3)
#define DRF_BIST_START_PAUSE_get_DRF_BIST3_START_PAUSE(data)                         ((0x00000008&(data))>>3)
#define DRF_BIST_START_PAUSE_DRF_BIST2_START_PAUSE_shift                             (2)
#define DRF_BIST_START_PAUSE_DRF_BIST2_START_PAUSE_mask                              (0x00000004)
#define DRF_BIST_START_PAUSE_DRF_BIST2_START_PAUSE(data)                             (0x00000004&((data)<<2))
#define DRF_BIST_START_PAUSE_DRF_BIST2_START_PAUSE_src(data)                         ((0x00000004&(data))>>2)
#define DRF_BIST_START_PAUSE_get_DRF_BIST2_START_PAUSE(data)                         ((0x00000004&(data))>>2)
#define DRF_BIST_START_PAUSE_DRF_BIST1_START_PAUSE_shift                             (1)
#define DRF_BIST_START_PAUSE_DRF_BIST1_START_PAUSE_mask                              (0x00000002)
#define DRF_BIST_START_PAUSE_DRF_BIST1_START_PAUSE(data)                             (0x00000002&((data)<<1))
#define DRF_BIST_START_PAUSE_DRF_BIST1_START_PAUSE_src(data)                         ((0x00000002&(data))>>1)
#define DRF_BIST_START_PAUSE_get_DRF_BIST1_START_PAUSE(data)                         ((0x00000002&(data))>>1)
#define DRF_BIST_START_PAUSE_DRF_BIST0_START_PAUSE_shift                             (0)
#define DRF_BIST_START_PAUSE_DRF_BIST0_START_PAUSE_mask                              (0x00000001)
#define DRF_BIST_START_PAUSE_DRF_BIST0_START_PAUSE(data)                             (0x00000001&((data)<<0))
#define DRF_BIST_START_PAUSE_DRF_BIST0_START_PAUSE_src(data)                         ((0x00000001&(data))>>0)
#define DRF_BIST_START_PAUSE_get_DRF_BIST0_START_PAUSE(data)                         ((0x00000001&(data))>>0)


#define BIST_FAIL_GROUP                                                              0x1805D648
#define BIST_FAIL_GROUP_reg_addr                                                     "0xB805D648"
#define BIST_FAIL_GROUP_reg                                                          0xB805D648
#define set_BIST_FAIL_GROUP_reg(data)   (*((volatile unsigned int*) BIST_FAIL_GROUP_reg)=data)
#define get_BIST_FAIL_GROUP_reg   (*((volatile unsigned int*) BIST_FAIL_GROUP_reg))
#define BIST_FAIL_GROUP_inst_adr                                                     "0x0092"
#define BIST_FAIL_GROUP_inst                                                         0x0092
#define BIST_FAIL_GROUP_BIST3_FAIL_shift                                             (3)
#define BIST_FAIL_GROUP_BIST3_FAIL_mask                                              (0x00000008)
#define BIST_FAIL_GROUP_BIST3_FAIL(data)                                             (0x00000008&((data)<<3))
#define BIST_FAIL_GROUP_BIST3_FAIL_src(data)                                         ((0x00000008&(data))>>3)
#define BIST_FAIL_GROUP_get_BIST3_FAIL(data)                                         ((0x00000008&(data))>>3)
#define BIST_FAIL_GROUP_BIST2_FAIL_shift                                             (2)
#define BIST_FAIL_GROUP_BIST2_FAIL_mask                                              (0x00000004)
#define BIST_FAIL_GROUP_BIST2_FAIL(data)                                             (0x00000004&((data)<<2))
#define BIST_FAIL_GROUP_BIST2_FAIL_src(data)                                         ((0x00000004&(data))>>2)
#define BIST_FAIL_GROUP_get_BIST2_FAIL(data)                                         ((0x00000004&(data))>>2)
#define BIST_FAIL_GROUP_BIST1_FAIL_shift                                             (1)
#define BIST_FAIL_GROUP_BIST1_FAIL_mask                                              (0x00000002)
#define BIST_FAIL_GROUP_BIST1_FAIL(data)                                             (0x00000002&((data)<<1))
#define BIST_FAIL_GROUP_BIST1_FAIL_src(data)                                         ((0x00000002&(data))>>1)
#define BIST_FAIL_GROUP_get_BIST1_FAIL(data)                                         ((0x00000002&(data))>>1)
#define BIST_FAIL_GROUP_BIST0_FAIL_shift                                             (0)
#define BIST_FAIL_GROUP_BIST0_FAIL_mask                                              (0x00000001)
#define BIST_FAIL_GROUP_BIST0_FAIL(data)                                             (0x00000001&((data)<<0))
#define BIST_FAIL_GROUP_BIST0_FAIL_src(data)                                         ((0x00000001&(data))>>0)
#define BIST_FAIL_GROUP_get_BIST0_FAIL(data)                                         ((0x00000001&(data))>>0)


#define DRF_BIST_FAIL_GROUP                                                          0x1805D64C
#define DRF_BIST_FAIL_GROUP_reg_addr                                                 "0xB805D64C"
#define DRF_BIST_FAIL_GROUP_reg                                                      0xB805D64C
#define set_DRF_BIST_FAIL_GROUP_reg(data)   (*((volatile unsigned int*) DRF_BIST_FAIL_GROUP_reg)=data)
#define get_DRF_BIST_FAIL_GROUP_reg   (*((volatile unsigned int*) DRF_BIST_FAIL_GROUP_reg))
#define DRF_BIST_FAIL_GROUP_inst_adr                                                 "0x0093"
#define DRF_BIST_FAIL_GROUP_inst                                                     0x0093
#define DRF_BIST_FAIL_GROUP_DRF_BIST3_FAIL_shift                                     (3)
#define DRF_BIST_FAIL_GROUP_DRF_BIST3_FAIL_mask                                      (0x00000008)
#define DRF_BIST_FAIL_GROUP_DRF_BIST3_FAIL(data)                                     (0x00000008&((data)<<3))
#define DRF_BIST_FAIL_GROUP_DRF_BIST3_FAIL_src(data)                                 ((0x00000008&(data))>>3)
#define DRF_BIST_FAIL_GROUP_get_DRF_BIST3_FAIL(data)                                 ((0x00000008&(data))>>3)
#define DRF_BIST_FAIL_GROUP_DRF_BIST2_FAIL_shift                                     (2)
#define DRF_BIST_FAIL_GROUP_DRF_BIST2_FAIL_mask                                      (0x00000004)
#define DRF_BIST_FAIL_GROUP_DRF_BIST2_FAIL(data)                                     (0x00000004&((data)<<2))
#define DRF_BIST_FAIL_GROUP_DRF_BIST2_FAIL_src(data)                                 ((0x00000004&(data))>>2)
#define DRF_BIST_FAIL_GROUP_get_DRF_BIST2_FAIL(data)                                 ((0x00000004&(data))>>2)
#define DRF_BIST_FAIL_GROUP_DRF_BIST1_FAIL_shift                                     (1)
#define DRF_BIST_FAIL_GROUP_DRF_BIST1_FAIL_mask                                      (0x00000002)
#define DRF_BIST_FAIL_GROUP_DRF_BIST1_FAIL(data)                                     (0x00000002&((data)<<1))
#define DRF_BIST_FAIL_GROUP_DRF_BIST1_FAIL_src(data)                                 ((0x00000002&(data))>>1)
#define DRF_BIST_FAIL_GROUP_get_DRF_BIST1_FAIL(data)                                 ((0x00000002&(data))>>1)
#define DRF_BIST_FAIL_GROUP_DRF_BIST0_FAIL_shift                                     (0)
#define DRF_BIST_FAIL_GROUP_DRF_BIST0_FAIL_mask                                      (0x00000001)
#define DRF_BIST_FAIL_GROUP_DRF_BIST0_FAIL(data)                                     (0x00000001&((data)<<0))
#define DRF_BIST_FAIL_GROUP_DRF_BIST0_FAIL_src(data)                                 ((0x00000001&(data))>>0)
#define DRF_BIST_FAIL_GROUP_get_DRF_BIST0_FAIL(data)                                 ((0x00000001&(data))>>0)


#define BIST0_FAIL                                                                   0x1805D650
#define BIST0_FAIL_reg_addr                                                          "0xB805D650"
#define BIST0_FAIL_reg                                                               0xB805D650
#define set_BIST0_FAIL_reg(data)   (*((volatile unsigned int*) BIST0_FAIL_reg)=data)
#define get_BIST0_FAIL_reg   (*((volatile unsigned int*) BIST0_FAIL_reg))
#define BIST0_FAIL_inst_adr                                                          "0x0094"
#define BIST0_FAIL_inst                                                              0x0094
#define BIST0_FAIL_BIST0_FAIL_7_shift                                                (7)
#define BIST0_FAIL_BIST0_FAIL_7_mask                                                 (0x00000080)
#define BIST0_FAIL_BIST0_FAIL_7(data)                                                (0x00000080&((data)<<7))
#define BIST0_FAIL_BIST0_FAIL_7_src(data)                                            ((0x00000080&(data))>>7)
#define BIST0_FAIL_get_BIST0_FAIL_7(data)                                            ((0x00000080&(data))>>7)
#define BIST0_FAIL_BIST0_FAIL_6_shift                                                (6)
#define BIST0_FAIL_BIST0_FAIL_6_mask                                                 (0x00000040)
#define BIST0_FAIL_BIST0_FAIL_6(data)                                                (0x00000040&((data)<<6))
#define BIST0_FAIL_BIST0_FAIL_6_src(data)                                            ((0x00000040&(data))>>6)
#define BIST0_FAIL_get_BIST0_FAIL_6(data)                                            ((0x00000040&(data))>>6)
#define BIST0_FAIL_BIST0_FAIL_5_shift                                                (5)
#define BIST0_FAIL_BIST0_FAIL_5_mask                                                 (0x00000020)
#define BIST0_FAIL_BIST0_FAIL_5(data)                                                (0x00000020&((data)<<5))
#define BIST0_FAIL_BIST0_FAIL_5_src(data)                                            ((0x00000020&(data))>>5)
#define BIST0_FAIL_get_BIST0_FAIL_5(data)                                            ((0x00000020&(data))>>5)
#define BIST0_FAIL_BIST0_FAIL_4_shift                                                (4)
#define BIST0_FAIL_BIST0_FAIL_4_mask                                                 (0x00000010)
#define BIST0_FAIL_BIST0_FAIL_4(data)                                                (0x00000010&((data)<<4))
#define BIST0_FAIL_BIST0_FAIL_4_src(data)                                            ((0x00000010&(data))>>4)
#define BIST0_FAIL_get_BIST0_FAIL_4(data)                                            ((0x00000010&(data))>>4)
#define BIST0_FAIL_BIST0_FAIL_3_shift                                                (3)
#define BIST0_FAIL_BIST0_FAIL_3_mask                                                 (0x00000008)
#define BIST0_FAIL_BIST0_FAIL_3(data)                                                (0x00000008&((data)<<3))
#define BIST0_FAIL_BIST0_FAIL_3_src(data)                                            ((0x00000008&(data))>>3)
#define BIST0_FAIL_get_BIST0_FAIL_3(data)                                            ((0x00000008&(data))>>3)
#define BIST0_FAIL_BIST0_FAIL_2_shift                                                (2)
#define BIST0_FAIL_BIST0_FAIL_2_mask                                                 (0x00000004)
#define BIST0_FAIL_BIST0_FAIL_2(data)                                                (0x00000004&((data)<<2))
#define BIST0_FAIL_BIST0_FAIL_2_src(data)                                            ((0x00000004&(data))>>2)
#define BIST0_FAIL_get_BIST0_FAIL_2(data)                                            ((0x00000004&(data))>>2)
#define BIST0_FAIL_BIST0_FAIL_1_shift                                                (1)
#define BIST0_FAIL_BIST0_FAIL_1_mask                                                 (0x00000002)
#define BIST0_FAIL_BIST0_FAIL_1(data)                                                (0x00000002&((data)<<1))
#define BIST0_FAIL_BIST0_FAIL_1_src(data)                                            ((0x00000002&(data))>>1)
#define BIST0_FAIL_get_BIST0_FAIL_1(data)                                            ((0x00000002&(data))>>1)
#define BIST0_FAIL_BIST0_FAIL_0_shift                                                (0)
#define BIST0_FAIL_BIST0_FAIL_0_mask                                                 (0x00000001)
#define BIST0_FAIL_BIST0_FAIL_0(data)                                                (0x00000001&((data)<<0))
#define BIST0_FAIL_BIST0_FAIL_0_src(data)                                            ((0x00000001&(data))>>0)
#define BIST0_FAIL_get_BIST0_FAIL_0(data)                                            ((0x00000001&(data))>>0)


#define DRF_BIST0_FAIL                                                               0x1805D654
#define DRF_BIST0_FAIL_reg_addr                                                      "0xB805D654"
#define DRF_BIST0_FAIL_reg                                                           0xB805D654
#define set_DRF_BIST0_FAIL_reg(data)   (*((volatile unsigned int*) DRF_BIST0_FAIL_reg)=data)
#define get_DRF_BIST0_FAIL_reg   (*((volatile unsigned int*) DRF_BIST0_FAIL_reg))
#define DRF_BIST0_FAIL_inst_adr                                                      "0x0095"
#define DRF_BIST0_FAIL_inst                                                          0x0095
#define DRF_BIST0_FAIL_DRF_BIST0_FAIL_7_shift                                        (7)
#define DRF_BIST0_FAIL_DRF_BIST0_FAIL_7_mask                                         (0x00000080)
#define DRF_BIST0_FAIL_DRF_BIST0_FAIL_7(data)                                        (0x00000080&((data)<<7))
#define DRF_BIST0_FAIL_DRF_BIST0_FAIL_7_src(data)                                    ((0x00000080&(data))>>7)
#define DRF_BIST0_FAIL_get_DRF_BIST0_FAIL_7(data)                                    ((0x00000080&(data))>>7)
#define DRF_BIST0_FAIL_DRF_BIST0_FAIL_6_shift                                        (6)
#define DRF_BIST0_FAIL_DRF_BIST0_FAIL_6_mask                                         (0x00000040)
#define DRF_BIST0_FAIL_DRF_BIST0_FAIL_6(data)                                        (0x00000040&((data)<<6))
#define DRF_BIST0_FAIL_DRF_BIST0_FAIL_6_src(data)                                    ((0x00000040&(data))>>6)
#define DRF_BIST0_FAIL_get_DRF_BIST0_FAIL_6(data)                                    ((0x00000040&(data))>>6)
#define DRF_BIST0_FAIL_DRF_BIST0_FAIL_5_shift                                        (5)
#define DRF_BIST0_FAIL_DRF_BIST0_FAIL_5_mask                                         (0x00000020)
#define DRF_BIST0_FAIL_DRF_BIST0_FAIL_5(data)                                        (0x00000020&((data)<<5))
#define DRF_BIST0_FAIL_DRF_BIST0_FAIL_5_src(data)                                    ((0x00000020&(data))>>5)
#define DRF_BIST0_FAIL_get_DRF_BIST0_FAIL_5(data)                                    ((0x00000020&(data))>>5)
#define DRF_BIST0_FAIL_DRF_BIST0_FAIL_4_shift                                        (4)
#define DRF_BIST0_FAIL_DRF_BIST0_FAIL_4_mask                                         (0x00000010)
#define DRF_BIST0_FAIL_DRF_BIST0_FAIL_4(data)                                        (0x00000010&((data)<<4))
#define DRF_BIST0_FAIL_DRF_BIST0_FAIL_4_src(data)                                    ((0x00000010&(data))>>4)
#define DRF_BIST0_FAIL_get_DRF_BIST0_FAIL_4(data)                                    ((0x00000010&(data))>>4)
#define DRF_BIST0_FAIL_DRF_BIST0_FAIL_3_shift                                        (3)
#define DRF_BIST0_FAIL_DRF_BIST0_FAIL_3_mask                                         (0x00000008)
#define DRF_BIST0_FAIL_DRF_BIST0_FAIL_3(data)                                        (0x00000008&((data)<<3))
#define DRF_BIST0_FAIL_DRF_BIST0_FAIL_3_src(data)                                    ((0x00000008&(data))>>3)
#define DRF_BIST0_FAIL_get_DRF_BIST0_FAIL_3(data)                                    ((0x00000008&(data))>>3)
#define DRF_BIST0_FAIL_DRF_BIST0_FAIL_2_shift                                        (2)
#define DRF_BIST0_FAIL_DRF_BIST0_FAIL_2_mask                                         (0x00000004)
#define DRF_BIST0_FAIL_DRF_BIST0_FAIL_2(data)                                        (0x00000004&((data)<<2))
#define DRF_BIST0_FAIL_DRF_BIST0_FAIL_2_src(data)                                    ((0x00000004&(data))>>2)
#define DRF_BIST0_FAIL_get_DRF_BIST0_FAIL_2(data)                                    ((0x00000004&(data))>>2)
#define DRF_BIST0_FAIL_DRF_BIST0_FAIL_1_shift                                        (1)
#define DRF_BIST0_FAIL_DRF_BIST0_FAIL_1_mask                                         (0x00000002)
#define DRF_BIST0_FAIL_DRF_BIST0_FAIL_1(data)                                        (0x00000002&((data)<<1))
#define DRF_BIST0_FAIL_DRF_BIST0_FAIL_1_src(data)                                    ((0x00000002&(data))>>1)
#define DRF_BIST0_FAIL_get_DRF_BIST0_FAIL_1(data)                                    ((0x00000002&(data))>>1)
#define DRF_BIST0_FAIL_DRF_BIST0_FAIL_0_shift                                        (0)
#define DRF_BIST0_FAIL_DRF_BIST0_FAIL_0_mask                                         (0x00000001)
#define DRF_BIST0_FAIL_DRF_BIST0_FAIL_0(data)                                        (0x00000001&((data)<<0))
#define DRF_BIST0_FAIL_DRF_BIST0_FAIL_0_src(data)                                    ((0x00000001&(data))>>0)
#define DRF_BIST0_FAIL_get_DRF_BIST0_FAIL_0(data)                                    ((0x00000001&(data))>>0)


#define BIST1_FAIL                                                                   0x1805D658
#define BIST1_FAIL_reg_addr                                                          "0xB805D658"
#define BIST1_FAIL_reg                                                               0xB805D658
#define set_BIST1_FAIL_reg(data)   (*((volatile unsigned int*) BIST1_FAIL_reg)=data)
#define get_BIST1_FAIL_reg   (*((volatile unsigned int*) BIST1_FAIL_reg))
#define BIST1_FAIL_inst_adr                                                          "0x0096"
#define BIST1_FAIL_inst                                                              0x0096
#define BIST1_FAIL_BIST1_FAIL_7_shift                                                (7)
#define BIST1_FAIL_BIST1_FAIL_7_mask                                                 (0x00000080)
#define BIST1_FAIL_BIST1_FAIL_7(data)                                                (0x00000080&((data)<<7))
#define BIST1_FAIL_BIST1_FAIL_7_src(data)                                            ((0x00000080&(data))>>7)
#define BIST1_FAIL_get_BIST1_FAIL_7(data)                                            ((0x00000080&(data))>>7)
#define BIST1_FAIL_BIST1_FAIL_6_shift                                                (6)
#define BIST1_FAIL_BIST1_FAIL_6_mask                                                 (0x00000040)
#define BIST1_FAIL_BIST1_FAIL_6(data)                                                (0x00000040&((data)<<6))
#define BIST1_FAIL_BIST1_FAIL_6_src(data)                                            ((0x00000040&(data))>>6)
#define BIST1_FAIL_get_BIST1_FAIL_6(data)                                            ((0x00000040&(data))>>6)
#define BIST1_FAIL_BIST1_FAIL_5_shift                                                (5)
#define BIST1_FAIL_BIST1_FAIL_5_mask                                                 (0x00000020)
#define BIST1_FAIL_BIST1_FAIL_5(data)                                                (0x00000020&((data)<<5))
#define BIST1_FAIL_BIST1_FAIL_5_src(data)                                            ((0x00000020&(data))>>5)
#define BIST1_FAIL_get_BIST1_FAIL_5(data)                                            ((0x00000020&(data))>>5)
#define BIST1_FAIL_BIST1_FAIL_4_shift                                                (4)
#define BIST1_FAIL_BIST1_FAIL_4_mask                                                 (0x00000010)
#define BIST1_FAIL_BIST1_FAIL_4(data)                                                (0x00000010&((data)<<4))
#define BIST1_FAIL_BIST1_FAIL_4_src(data)                                            ((0x00000010&(data))>>4)
#define BIST1_FAIL_get_BIST1_FAIL_4(data)                                            ((0x00000010&(data))>>4)
#define BIST1_FAIL_BIST1_FAIL_3_shift                                                (3)
#define BIST1_FAIL_BIST1_FAIL_3_mask                                                 (0x00000008)
#define BIST1_FAIL_BIST1_FAIL_3(data)                                                (0x00000008&((data)<<3))
#define BIST1_FAIL_BIST1_FAIL_3_src(data)                                            ((0x00000008&(data))>>3)
#define BIST1_FAIL_get_BIST1_FAIL_3(data)                                            ((0x00000008&(data))>>3)
#define BIST1_FAIL_BIST1_FAIL_2_shift                                                (2)
#define BIST1_FAIL_BIST1_FAIL_2_mask                                                 (0x00000004)
#define BIST1_FAIL_BIST1_FAIL_2(data)                                                (0x00000004&((data)<<2))
#define BIST1_FAIL_BIST1_FAIL_2_src(data)                                            ((0x00000004&(data))>>2)
#define BIST1_FAIL_get_BIST1_FAIL_2(data)                                            ((0x00000004&(data))>>2)
#define BIST1_FAIL_BIST1_FAIL_1_shift                                                (1)
#define BIST1_FAIL_BIST1_FAIL_1_mask                                                 (0x00000002)
#define BIST1_FAIL_BIST1_FAIL_1(data)                                                (0x00000002&((data)<<1))
#define BIST1_FAIL_BIST1_FAIL_1_src(data)                                            ((0x00000002&(data))>>1)
#define BIST1_FAIL_get_BIST1_FAIL_1(data)                                            ((0x00000002&(data))>>1)
#define BIST1_FAIL_BIST1_FAIL_0_shift                                                (0)
#define BIST1_FAIL_BIST1_FAIL_0_mask                                                 (0x00000001)
#define BIST1_FAIL_BIST1_FAIL_0(data)                                                (0x00000001&((data)<<0))
#define BIST1_FAIL_BIST1_FAIL_0_src(data)                                            ((0x00000001&(data))>>0)
#define BIST1_FAIL_get_BIST1_FAIL_0(data)                                            ((0x00000001&(data))>>0)


#define DRF_BIST1_FAIL                                                               0x1805D65C
#define DRF_BIST1_FAIL_reg_addr                                                      "0xB805D65C"
#define DRF_BIST1_FAIL_reg                                                           0xB805D65C
#define set_DRF_BIST1_FAIL_reg(data)   (*((volatile unsigned int*) DRF_BIST1_FAIL_reg)=data)
#define get_DRF_BIST1_FAIL_reg   (*((volatile unsigned int*) DRF_BIST1_FAIL_reg))
#define DRF_BIST1_FAIL_inst_adr                                                      "0x0097"
#define DRF_BIST1_FAIL_inst                                                          0x0097
#define DRF_BIST1_FAIL_DRF_BIST1_FAIL_7_shift                                        (7)
#define DRF_BIST1_FAIL_DRF_BIST1_FAIL_7_mask                                         (0x00000080)
#define DRF_BIST1_FAIL_DRF_BIST1_FAIL_7(data)                                        (0x00000080&((data)<<7))
#define DRF_BIST1_FAIL_DRF_BIST1_FAIL_7_src(data)                                    ((0x00000080&(data))>>7)
#define DRF_BIST1_FAIL_get_DRF_BIST1_FAIL_7(data)                                    ((0x00000080&(data))>>7)
#define DRF_BIST1_FAIL_DRF_BIST1_FAIL_6_shift                                        (6)
#define DRF_BIST1_FAIL_DRF_BIST1_FAIL_6_mask                                         (0x00000040)
#define DRF_BIST1_FAIL_DRF_BIST1_FAIL_6(data)                                        (0x00000040&((data)<<6))
#define DRF_BIST1_FAIL_DRF_BIST1_FAIL_6_src(data)                                    ((0x00000040&(data))>>6)
#define DRF_BIST1_FAIL_get_DRF_BIST1_FAIL_6(data)                                    ((0x00000040&(data))>>6)
#define DRF_BIST1_FAIL_DRF_BIST1_FAIL_5_shift                                        (5)
#define DRF_BIST1_FAIL_DRF_BIST1_FAIL_5_mask                                         (0x00000020)
#define DRF_BIST1_FAIL_DRF_BIST1_FAIL_5(data)                                        (0x00000020&((data)<<5))
#define DRF_BIST1_FAIL_DRF_BIST1_FAIL_5_src(data)                                    ((0x00000020&(data))>>5)
#define DRF_BIST1_FAIL_get_DRF_BIST1_FAIL_5(data)                                    ((0x00000020&(data))>>5)
#define DRF_BIST1_FAIL_DRF_BIST1_FAIL_4_shift                                        (4)
#define DRF_BIST1_FAIL_DRF_BIST1_FAIL_4_mask                                         (0x00000010)
#define DRF_BIST1_FAIL_DRF_BIST1_FAIL_4(data)                                        (0x00000010&((data)<<4))
#define DRF_BIST1_FAIL_DRF_BIST1_FAIL_4_src(data)                                    ((0x00000010&(data))>>4)
#define DRF_BIST1_FAIL_get_DRF_BIST1_FAIL_4(data)                                    ((0x00000010&(data))>>4)
#define DRF_BIST1_FAIL_DRF_BIST1_FAIL_3_shift                                        (3)
#define DRF_BIST1_FAIL_DRF_BIST1_FAIL_3_mask                                         (0x00000008)
#define DRF_BIST1_FAIL_DRF_BIST1_FAIL_3(data)                                        (0x00000008&((data)<<3))
#define DRF_BIST1_FAIL_DRF_BIST1_FAIL_3_src(data)                                    ((0x00000008&(data))>>3)
#define DRF_BIST1_FAIL_get_DRF_BIST1_FAIL_3(data)                                    ((0x00000008&(data))>>3)
#define DRF_BIST1_FAIL_DRF_BIST1_FAIL_2_shift                                        (2)
#define DRF_BIST1_FAIL_DRF_BIST1_FAIL_2_mask                                         (0x00000004)
#define DRF_BIST1_FAIL_DRF_BIST1_FAIL_2(data)                                        (0x00000004&((data)<<2))
#define DRF_BIST1_FAIL_DRF_BIST1_FAIL_2_src(data)                                    ((0x00000004&(data))>>2)
#define DRF_BIST1_FAIL_get_DRF_BIST1_FAIL_2(data)                                    ((0x00000004&(data))>>2)
#define DRF_BIST1_FAIL_DRF_BIST1_FAIL_1_shift                                        (1)
#define DRF_BIST1_FAIL_DRF_BIST1_FAIL_1_mask                                         (0x00000002)
#define DRF_BIST1_FAIL_DRF_BIST1_FAIL_1(data)                                        (0x00000002&((data)<<1))
#define DRF_BIST1_FAIL_DRF_BIST1_FAIL_1_src(data)                                    ((0x00000002&(data))>>1)
#define DRF_BIST1_FAIL_get_DRF_BIST1_FAIL_1(data)                                    ((0x00000002&(data))>>1)
#define DRF_BIST1_FAIL_DRF_BIST1_FAIL_0_shift                                        (0)
#define DRF_BIST1_FAIL_DRF_BIST1_FAIL_0_mask                                         (0x00000001)
#define DRF_BIST1_FAIL_DRF_BIST1_FAIL_0(data)                                        (0x00000001&((data)<<0))
#define DRF_BIST1_FAIL_DRF_BIST1_FAIL_0_src(data)                                    ((0x00000001&(data))>>0)
#define DRF_BIST1_FAIL_get_DRF_BIST1_FAIL_0(data)                                    ((0x00000001&(data))>>0)


#define BIST2_FAIL                                                                   0x1805D660
#define BIST2_FAIL_reg_addr                                                          "0xB805D660"
#define BIST2_FAIL_reg                                                               0xB805D660
#define set_BIST2_FAIL_reg(data)   (*((volatile unsigned int*) BIST2_FAIL_reg)=data)
#define get_BIST2_FAIL_reg   (*((volatile unsigned int*) BIST2_FAIL_reg))
#define BIST2_FAIL_inst_adr                                                          "0x0098"
#define BIST2_FAIL_inst                                                              0x0098
#define BIST2_FAIL_BIST2_FAIL_11_shift                                               (11)
#define BIST2_FAIL_BIST2_FAIL_11_mask                                                (0x00000800)
#define BIST2_FAIL_BIST2_FAIL_11(data)                                               (0x00000800&((data)<<11))
#define BIST2_FAIL_BIST2_FAIL_11_src(data)                                           ((0x00000800&(data))>>11)
#define BIST2_FAIL_get_BIST2_FAIL_11(data)                                           ((0x00000800&(data))>>11)
#define BIST2_FAIL_BIST2_FAIL_10_shift                                               (10)
#define BIST2_FAIL_BIST2_FAIL_10_mask                                                (0x00000400)
#define BIST2_FAIL_BIST2_FAIL_10(data)                                               (0x00000400&((data)<<10))
#define BIST2_FAIL_BIST2_FAIL_10_src(data)                                           ((0x00000400&(data))>>10)
#define BIST2_FAIL_get_BIST2_FAIL_10(data)                                           ((0x00000400&(data))>>10)
#define BIST2_FAIL_BIST2_FAIL_9_shift                                                (9)
#define BIST2_FAIL_BIST2_FAIL_9_mask                                                 (0x00000200)
#define BIST2_FAIL_BIST2_FAIL_9(data)                                                (0x00000200&((data)<<9))
#define BIST2_FAIL_BIST2_FAIL_9_src(data)                                            ((0x00000200&(data))>>9)
#define BIST2_FAIL_get_BIST2_FAIL_9(data)                                            ((0x00000200&(data))>>9)
#define BIST2_FAIL_BIST2_FAIL_8_shift                                                (8)
#define BIST2_FAIL_BIST2_FAIL_8_mask                                                 (0x00000100)
#define BIST2_FAIL_BIST2_FAIL_8(data)                                                (0x00000100&((data)<<8))
#define BIST2_FAIL_BIST2_FAIL_8_src(data)                                            ((0x00000100&(data))>>8)
#define BIST2_FAIL_get_BIST2_FAIL_8(data)                                            ((0x00000100&(data))>>8)
#define BIST2_FAIL_BIST2_FAIL_7_shift                                                (7)
#define BIST2_FAIL_BIST2_FAIL_7_mask                                                 (0x00000080)
#define BIST2_FAIL_BIST2_FAIL_7(data)                                                (0x00000080&((data)<<7))
#define BIST2_FAIL_BIST2_FAIL_7_src(data)                                            ((0x00000080&(data))>>7)
#define BIST2_FAIL_get_BIST2_FAIL_7(data)                                            ((0x00000080&(data))>>7)
#define BIST2_FAIL_BIST2_FAIL_6_shift                                                (6)
#define BIST2_FAIL_BIST2_FAIL_6_mask                                                 (0x00000040)
#define BIST2_FAIL_BIST2_FAIL_6(data)                                                (0x00000040&((data)<<6))
#define BIST2_FAIL_BIST2_FAIL_6_src(data)                                            ((0x00000040&(data))>>6)
#define BIST2_FAIL_get_BIST2_FAIL_6(data)                                            ((0x00000040&(data))>>6)
#define BIST2_FAIL_BIST2_FAIL_5_shift                                                (5)
#define BIST2_FAIL_BIST2_FAIL_5_mask                                                 (0x00000020)
#define BIST2_FAIL_BIST2_FAIL_5(data)                                                (0x00000020&((data)<<5))
#define BIST2_FAIL_BIST2_FAIL_5_src(data)                                            ((0x00000020&(data))>>5)
#define BIST2_FAIL_get_BIST2_FAIL_5(data)                                            ((0x00000020&(data))>>5)
#define BIST2_FAIL_BIST2_FAIL_4_shift                                                (4)
#define BIST2_FAIL_BIST2_FAIL_4_mask                                                 (0x00000010)
#define BIST2_FAIL_BIST2_FAIL_4(data)                                                (0x00000010&((data)<<4))
#define BIST2_FAIL_BIST2_FAIL_4_src(data)                                            ((0x00000010&(data))>>4)
#define BIST2_FAIL_get_BIST2_FAIL_4(data)                                            ((0x00000010&(data))>>4)
#define BIST2_FAIL_BIST2_FAIL_3_shift                                                (3)
#define BIST2_FAIL_BIST2_FAIL_3_mask                                                 (0x00000008)
#define BIST2_FAIL_BIST2_FAIL_3(data)                                                (0x00000008&((data)<<3))
#define BIST2_FAIL_BIST2_FAIL_3_src(data)                                            ((0x00000008&(data))>>3)
#define BIST2_FAIL_get_BIST2_FAIL_3(data)                                            ((0x00000008&(data))>>3)
#define BIST2_FAIL_BIST2_FAIL_2_shift                                                (2)
#define BIST2_FAIL_BIST2_FAIL_2_mask                                                 (0x00000004)
#define BIST2_FAIL_BIST2_FAIL_2(data)                                                (0x00000004&((data)<<2))
#define BIST2_FAIL_BIST2_FAIL_2_src(data)                                            ((0x00000004&(data))>>2)
#define BIST2_FAIL_get_BIST2_FAIL_2(data)                                            ((0x00000004&(data))>>2)
#define BIST2_FAIL_BIST2_FAIL_1_shift                                                (1)
#define BIST2_FAIL_BIST2_FAIL_1_mask                                                 (0x00000002)
#define BIST2_FAIL_BIST2_FAIL_1(data)                                                (0x00000002&((data)<<1))
#define BIST2_FAIL_BIST2_FAIL_1_src(data)                                            ((0x00000002&(data))>>1)
#define BIST2_FAIL_get_BIST2_FAIL_1(data)                                            ((0x00000002&(data))>>1)
#define BIST2_FAIL_BIST2_FAIL_0_shift                                                (0)
#define BIST2_FAIL_BIST2_FAIL_0_mask                                                 (0x00000001)
#define BIST2_FAIL_BIST2_FAIL_0(data)                                                (0x00000001&((data)<<0))
#define BIST2_FAIL_BIST2_FAIL_0_src(data)                                            ((0x00000001&(data))>>0)
#define BIST2_FAIL_get_BIST2_FAIL_0(data)                                            ((0x00000001&(data))>>0)


#define DRF_BIST2_FAIL                                                               0x1805D664
#define DRF_BIST2_FAIL_reg_addr                                                      "0xB805D664"
#define DRF_BIST2_FAIL_reg                                                           0xB805D664
#define set_DRF_BIST2_FAIL_reg(data)   (*((volatile unsigned int*) DRF_BIST2_FAIL_reg)=data)
#define get_DRF_BIST2_FAIL_reg   (*((volatile unsigned int*) DRF_BIST2_FAIL_reg))
#define DRF_BIST2_FAIL_inst_adr                                                      "0x0099"
#define DRF_BIST2_FAIL_inst                                                          0x0099
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_11_shift                                       (11)
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_11_mask                                        (0x00000800)
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_11(data)                                       (0x00000800&((data)<<11))
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_11_src(data)                                   ((0x00000800&(data))>>11)
#define DRF_BIST2_FAIL_get_DRF_BIST2_FAIL_11(data)                                   ((0x00000800&(data))>>11)
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_10_shift                                       (10)
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_10_mask                                        (0x00000400)
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_10(data)                                       (0x00000400&((data)<<10))
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_10_src(data)                                   ((0x00000400&(data))>>10)
#define DRF_BIST2_FAIL_get_DRF_BIST2_FAIL_10(data)                                   ((0x00000400&(data))>>10)
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_9_shift                                        (9)
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_9_mask                                         (0x00000200)
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_9(data)                                        (0x00000200&((data)<<9))
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_9_src(data)                                    ((0x00000200&(data))>>9)
#define DRF_BIST2_FAIL_get_DRF_BIST2_FAIL_9(data)                                    ((0x00000200&(data))>>9)
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_8_shift                                        (8)
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_8_mask                                         (0x00000100)
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_8(data)                                        (0x00000100&((data)<<8))
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_8_src(data)                                    ((0x00000100&(data))>>8)
#define DRF_BIST2_FAIL_get_DRF_BIST2_FAIL_8(data)                                    ((0x00000100&(data))>>8)
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_7_shift                                        (7)
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_7_mask                                         (0x00000080)
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_7(data)                                        (0x00000080&((data)<<7))
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_7_src(data)                                    ((0x00000080&(data))>>7)
#define DRF_BIST2_FAIL_get_DRF_BIST2_FAIL_7(data)                                    ((0x00000080&(data))>>7)
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_6_shift                                        (6)
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_6_mask                                         (0x00000040)
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_6(data)                                        (0x00000040&((data)<<6))
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_6_src(data)                                    ((0x00000040&(data))>>6)
#define DRF_BIST2_FAIL_get_DRF_BIST2_FAIL_6(data)                                    ((0x00000040&(data))>>6)
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_5_shift                                        (5)
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_5_mask                                         (0x00000020)
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_5(data)                                        (0x00000020&((data)<<5))
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_5_src(data)                                    ((0x00000020&(data))>>5)
#define DRF_BIST2_FAIL_get_DRF_BIST2_FAIL_5(data)                                    ((0x00000020&(data))>>5)
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_4_shift                                        (4)
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_4_mask                                         (0x00000010)
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_4(data)                                        (0x00000010&((data)<<4))
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_4_src(data)                                    ((0x00000010&(data))>>4)
#define DRF_BIST2_FAIL_get_DRF_BIST2_FAIL_4(data)                                    ((0x00000010&(data))>>4)
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_3_shift                                        (3)
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_3_mask                                         (0x00000008)
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_3(data)                                        (0x00000008&((data)<<3))
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_3_src(data)                                    ((0x00000008&(data))>>3)
#define DRF_BIST2_FAIL_get_DRF_BIST2_FAIL_3(data)                                    ((0x00000008&(data))>>3)
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_2_shift                                        (2)
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_2_mask                                         (0x00000004)
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_2(data)                                        (0x00000004&((data)<<2))
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_2_src(data)                                    ((0x00000004&(data))>>2)
#define DRF_BIST2_FAIL_get_DRF_BIST2_FAIL_2(data)                                    ((0x00000004&(data))>>2)
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_1_shift                                        (1)
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_1_mask                                         (0x00000002)
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_1(data)                                        (0x00000002&((data)<<1))
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_1_src(data)                                    ((0x00000002&(data))>>1)
#define DRF_BIST2_FAIL_get_DRF_BIST2_FAIL_1(data)                                    ((0x00000002&(data))>>1)
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_0_shift                                        (0)
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_0_mask                                         (0x00000001)
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_0(data)                                        (0x00000001&((data)<<0))
#define DRF_BIST2_FAIL_DRF_BIST2_FAIL_0_src(data)                                    ((0x00000001&(data))>>0)
#define DRF_BIST2_FAIL_get_DRF_BIST2_FAIL_0(data)                                    ((0x00000001&(data))>>0)


#define BIST3_FAIL                                                                   0x1805D668
#define BIST3_FAIL_reg_addr                                                          "0xB805D668"
#define BIST3_FAIL_reg                                                               0xB805D668
#define set_BIST3_FAIL_reg(data)   (*((volatile unsigned int*) BIST3_FAIL_reg)=data)
#define get_BIST3_FAIL_reg   (*((volatile unsigned int*) BIST3_FAIL_reg))
#define BIST3_FAIL_inst_adr                                                          "0x009A"
#define BIST3_FAIL_inst                                                              0x009A
#define BIST3_FAIL_BIST3_FAIL_5_shift                                                (5)
#define BIST3_FAIL_BIST3_FAIL_5_mask                                                 (0x00000020)
#define BIST3_FAIL_BIST3_FAIL_5(data)                                                (0x00000020&((data)<<5))
#define BIST3_FAIL_BIST3_FAIL_5_src(data)                                            ((0x00000020&(data))>>5)
#define BIST3_FAIL_get_BIST3_FAIL_5(data)                                            ((0x00000020&(data))>>5)
#define BIST3_FAIL_BIST3_FAIL_4_shift                                                (4)
#define BIST3_FAIL_BIST3_FAIL_4_mask                                                 (0x00000010)
#define BIST3_FAIL_BIST3_FAIL_4(data)                                                (0x00000010&((data)<<4))
#define BIST3_FAIL_BIST3_FAIL_4_src(data)                                            ((0x00000010&(data))>>4)
#define BIST3_FAIL_get_BIST3_FAIL_4(data)                                            ((0x00000010&(data))>>4)
#define BIST3_FAIL_BIST3_FAIL_3_shift                                                (3)
#define BIST3_FAIL_BIST3_FAIL_3_mask                                                 (0x00000008)
#define BIST3_FAIL_BIST3_FAIL_3(data)                                                (0x00000008&((data)<<3))
#define BIST3_FAIL_BIST3_FAIL_3_src(data)                                            ((0x00000008&(data))>>3)
#define BIST3_FAIL_get_BIST3_FAIL_3(data)                                            ((0x00000008&(data))>>3)
#define BIST3_FAIL_BIST3_FAIL_2_shift                                                (2)
#define BIST3_FAIL_BIST3_FAIL_2_mask                                                 (0x00000004)
#define BIST3_FAIL_BIST3_FAIL_2(data)                                                (0x00000004&((data)<<2))
#define BIST3_FAIL_BIST3_FAIL_2_src(data)                                            ((0x00000004&(data))>>2)
#define BIST3_FAIL_get_BIST3_FAIL_2(data)                                            ((0x00000004&(data))>>2)
#define BIST3_FAIL_BIST3_FAIL_1_shift                                                (1)
#define BIST3_FAIL_BIST3_FAIL_1_mask                                                 (0x00000002)
#define BIST3_FAIL_BIST3_FAIL_1(data)                                                (0x00000002&((data)<<1))
#define BIST3_FAIL_BIST3_FAIL_1_src(data)                                            ((0x00000002&(data))>>1)
#define BIST3_FAIL_get_BIST3_FAIL_1(data)                                            ((0x00000002&(data))>>1)
#define BIST3_FAIL_BIST3_FAIL_0_shift                                                (0)
#define BIST3_FAIL_BIST3_FAIL_0_mask                                                 (0x00000001)
#define BIST3_FAIL_BIST3_FAIL_0(data)                                                (0x00000001&((data)<<0))
#define BIST3_FAIL_BIST3_FAIL_0_src(data)                                            ((0x00000001&(data))>>0)
#define BIST3_FAIL_get_BIST3_FAIL_0(data)                                            ((0x00000001&(data))>>0)


#define DRF_BIST3_FAIL                                                               0x1805D66C
#define DRF_BIST3_FAIL_reg_addr                                                      "0xB805D66C"
#define DRF_BIST3_FAIL_reg                                                           0xB805D66C
#define set_DRF_BIST3_FAIL_reg(data)   (*((volatile unsigned int*) DRF_BIST3_FAIL_reg)=data)
#define get_DRF_BIST3_FAIL_reg   (*((volatile unsigned int*) DRF_BIST3_FAIL_reg))
#define DRF_BIST3_FAIL_inst_adr                                                      "0x009B"
#define DRF_BIST3_FAIL_inst                                                          0x009B
#define DRF_BIST3_FAIL_DRF_BIST3_FAIL_5_shift                                        (5)
#define DRF_BIST3_FAIL_DRF_BIST3_FAIL_5_mask                                         (0x00000020)
#define DRF_BIST3_FAIL_DRF_BIST3_FAIL_5(data)                                        (0x00000020&((data)<<5))
#define DRF_BIST3_FAIL_DRF_BIST3_FAIL_5_src(data)                                    ((0x00000020&(data))>>5)
#define DRF_BIST3_FAIL_get_DRF_BIST3_FAIL_5(data)                                    ((0x00000020&(data))>>5)
#define DRF_BIST3_FAIL_DRF_BIST3_FAIL_4_shift                                        (4)
#define DRF_BIST3_FAIL_DRF_BIST3_FAIL_4_mask                                         (0x00000010)
#define DRF_BIST3_FAIL_DRF_BIST3_FAIL_4(data)                                        (0x00000010&((data)<<4))
#define DRF_BIST3_FAIL_DRF_BIST3_FAIL_4_src(data)                                    ((0x00000010&(data))>>4)
#define DRF_BIST3_FAIL_get_DRF_BIST3_FAIL_4(data)                                    ((0x00000010&(data))>>4)
#define DRF_BIST3_FAIL_DRF_BIST3_FAIL_3_shift                                        (3)
#define DRF_BIST3_FAIL_DRF_BIST3_FAIL_3_mask                                         (0x00000008)
#define DRF_BIST3_FAIL_DRF_BIST3_FAIL_3(data)                                        (0x00000008&((data)<<3))
#define DRF_BIST3_FAIL_DRF_BIST3_FAIL_3_src(data)                                    ((0x00000008&(data))>>3)
#define DRF_BIST3_FAIL_get_DRF_BIST3_FAIL_3(data)                                    ((0x00000008&(data))>>3)
#define DRF_BIST3_FAIL_DRF_BIST3_FAIL_2_shift                                        (2)
#define DRF_BIST3_FAIL_DRF_BIST3_FAIL_2_mask                                         (0x00000004)
#define DRF_BIST3_FAIL_DRF_BIST3_FAIL_2(data)                                        (0x00000004&((data)<<2))
#define DRF_BIST3_FAIL_DRF_BIST3_FAIL_2_src(data)                                    ((0x00000004&(data))>>2)
#define DRF_BIST3_FAIL_get_DRF_BIST3_FAIL_2(data)                                    ((0x00000004&(data))>>2)
#define DRF_BIST3_FAIL_DRF_BIST3_FAIL_1_shift                                        (1)
#define DRF_BIST3_FAIL_DRF_BIST3_FAIL_1_mask                                         (0x00000002)
#define DRF_BIST3_FAIL_DRF_BIST3_FAIL_1(data)                                        (0x00000002&((data)<<1))
#define DRF_BIST3_FAIL_DRF_BIST3_FAIL_1_src(data)                                    ((0x00000002&(data))>>1)
#define DRF_BIST3_FAIL_get_DRF_BIST3_FAIL_1(data)                                    ((0x00000002&(data))>>1)
#define DRF_BIST3_FAIL_DRF_BIST3_FAIL_0_shift                                        (0)
#define DRF_BIST3_FAIL_DRF_BIST3_FAIL_0_mask                                         (0x00000001)
#define DRF_BIST3_FAIL_DRF_BIST3_FAIL_0(data)                                        (0x00000001&((data)<<0))
#define DRF_BIST3_FAIL_DRF_BIST3_FAIL_0_src(data)                                    ((0x00000001&(data))>>0)
#define DRF_BIST3_FAIL_get_DRF_BIST3_FAIL_0(data)                                    ((0x00000001&(data))>>0)


#endif
