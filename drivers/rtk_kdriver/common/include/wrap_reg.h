/**************************************************************
// Spec Version                  : 0.3
// Parser Version                : DVR_Parser_6.11(120105)
// CModelGen Version             : 5.1 2012.01.05
// Naming Rule                   :  Module_Register_Name
// Naming Rule                   : Module_Register_Name_reg
// Parse Option                  : Only Parse _op1
// Parse Address Region          : All Address Region 
// Decode bit number             : 12 bits
// Firmware Header Generate Date : 2014/1/28 15:28:41
***************************************************************/


#ifndef _WRAP_REG_H_INCLUDED_
#define _WRAP_REG_H_INCLUDED_
#ifdef  _WRAP_USE_STRUCT
typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     protect_3_en:1;
unsigned int     protect_2_en:1;
unsigned int     protect_1_en:1;
unsigned int     protect_0_en:1;
}WRAP_MEM_PROTECT_CTRL;

typedef struct 
{
unsigned int     protect_saddr0:20;
unsigned int     reserved_0:12;
}WRAP_MEM_PROTECT_SADDR0;

typedef struct 
{
unsigned int     protect_eaddr0:20;
unsigned int     reserved_0:12;
}WRAP_MEM_PROTECT_EADDR0;

typedef struct 
{
unsigned int     protect_saddr1:20;
unsigned int     reserved_0:12;
}WRAP_MEM_PROTECT_SADDR1;

typedef struct 
{
unsigned int     protect_eaddr1:20;
unsigned int     reserved_0:12;
}WRAP_MEM_PROTECT_EADDR1;

typedef struct 
{
unsigned int     protect_saddr2:20;
unsigned int     reserved_0:12;
}WRAP_MEM_PROTECT_SADDR2;

typedef struct 
{
unsigned int     protect_eaddr2:20;
unsigned int     reserved_0:12;
}WRAP_MEM_PROTECT_EADDR2;

typedef struct 
{
unsigned int     protect_saddr3:20;
unsigned int     reserved_0:12;
}WRAP_MEM_PROTECT_SADDR3;

typedef struct 
{
unsigned int     protect_eaddr3:20;
unsigned int     reserved_0:12;
}WRAP_MEM_PROTECT_EADDR3;

typedef struct 
{
unsigned int     key1:16;
unsigned int     key0:16;
}WRAP_MEM_SCRAMBLE_TOTAL_0;

typedef struct 
{
unsigned int     key3:16;
unsigned int     key2:16;
}WRAP_MEM_SCRAMBLE_TOTAL_1;

typedef struct 
{
unsigned int     key5:16;
unsigned int     key4:16;
}WRAP_MEM_SCRAMBLE_TOTAL_2;

typedef struct 
{
unsigned int     key7:16;
unsigned int     key6:16;
}WRAP_MEM_SCRAMBLE_TOTAL_3;

typedef struct 
{
unsigned int     key9:16;
unsigned int     key8:16;
}WRAP_MEM_SCRAMBLE_TOTAL_4;

typedef struct 
{
unsigned int     keyB:16;
unsigned int     keyA:16;
}WRAP_MEM_SCRAMBLE_TOTAL_5;

typedef struct 
{
unsigned int     keyD:16;
unsigned int     keyC:16;
}WRAP_MEM_SCRAMBLE_TOTAL_6;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     scpu_scramble_en:1;
}WRAP_MEM_SCRAMBLE_EN;

typedef struct 
{
unsigned int     reserved_0:18;
unsigned int     scpu_dbg_mode_sel:2;
unsigned int     scpu_dbg_sel_dc:4;
unsigned int     scpu_dbg_sel_fr:4;
unsigned int     scpu_dbg_sel_dis:4;
}WRAP_DBG_SEL_CTRL;

typedef struct 
{
unsigned int     reserved_0:23;
unsigned int     cp15sdisable:4;
unsigned int     cfgsdisable:1;
unsigned int     dbgen_source_sel:1;
unsigned int     spiden_source_sel:1;
unsigned int     niden_source_sel:1;
unsigned int     spniden_source_sel:1;
}WRAP_CORE_INPUT_CTRL0;

typedef struct 
{
unsigned int     reserved_0:1;
unsigned int     cfgaddrfilterens:1;
unsigned int     reserved_1:2;
unsigned int     cfgaddrfilterstarts:12;
unsigned int     reserved_2:4;
unsigned int     cfgaddrfilterends:12;
}WRAP_CORE_INPUT_CTRL1;

typedef struct 
{
unsigned int     reserved_0:1;
unsigned int     cfgaddrfilterenns:1;
unsigned int     reserved_1:2;
unsigned int     cfgaddrfilterstartns:12;
unsigned int     reserved_2:4;
unsigned int     cfgaddrfilterendns:12;
}WRAP_CORE_INPUT_CTRL2;

typedef struct 
{
unsigned int     apb_tsgen_a:32;
}WRAP_TSGEN_INPUT_CTRL0;

typedef struct 
{
unsigned int     apb_tsgen_d:32;
}WRAP_TSGEN_INPUT_CTRL1;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     apb_tsgen_slverr:1;
}WRAP_TSGEN_INPUT_CTRL2;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     ns_scpu_acc_prot_int:1;
unsigned int     ns_scpu_acc_prot_int_en:1;
}WRAP_NS_SCPU_ACC_PROT_INT;

typedef struct 
{
unsigned int     ns_scpu_acc_prot_addr:32;
}WRAP_NS_SCPU_ACC_PROT_ADDR;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     ns_scpu_acc_prot_rw:1;
}WRAP_NS_SCPU_ACC_PROT_RW;

typedef struct 
{
unsigned int     reserved_0:7;
unsigned int     ns_scpu_acc_cont_wr_en:1;
unsigned int     reserved_1:7;
unsigned int     ns_scpu_acc_cont_rd_en:1;
unsigned int     reserved_2:8;
unsigned int     content_prot_en7:1;
unsigned int     content_prot_en6:1;
unsigned int     content_prot_en5:1;
unsigned int     content_prot_en4:1;
unsigned int     content_prot_en3:1;
unsigned int     content_prot_en2:1;
unsigned int     content_prot_en1:1;
unsigned int     content_prot_en0:1;
}WRAP_CONTENT_PROT_EN;

typedef struct 
{
unsigned int     content_prot_saddr0:20;
unsigned int     reserved_0:12;
}WRAP_CONTENT_PROTECT_SADDR0;

typedef struct 
{
unsigned int     content_prot_eaddr0:20;
unsigned int     reserved_0:12;
}WRAP_CONTENT_PROTECT_EADDR0;

typedef struct 
{
unsigned int     content_prot_saddr1:20;
unsigned int     reserved_0:12;
}WRAP_CONTENT_PROTECT_SADDR1;

typedef struct 
{
unsigned int     content_prot_eaddr1:20;
unsigned int     reserved_0:12;
}WRAP_CONTENT_PROTECT_EADDR1;

typedef struct 
{
unsigned int     content_prot_saddr2:20;
unsigned int     reserved_0:12;
}WRAP_CONTENT_PROTECT_SADDR2;

typedef struct 
{
unsigned int     content_prot_eaddr2:20;
unsigned int     reserved_0:12;
}WRAP_CONTENT_PROTECT_EADDR2;

typedef struct 
{
unsigned int     content_prot_saddr3:20;
unsigned int     reserved_0:12;
}WRAP_CONTENT_PROTECT_SADDR3;

typedef struct 
{
unsigned int     content_prot_eaddr3:20;
unsigned int     reserved_0:12;
}WRAP_CONTENT_PROTECT_EADDR3;

typedef struct 
{
unsigned int     content_prot_saddr4:20;
unsigned int     reserved_0:12;
}WRAP_CONTENT_PROTECT_SADDR4;

typedef struct 
{
unsigned int     content_prot_eaddr4:20;
unsigned int     reserved_0:12;
}WRAP_CONTENT_PROTECT_EADDR4;

typedef struct 
{
unsigned int     content_prot_saddr5:20;
unsigned int     reserved_0:12;
}WRAP_CONTENT_PROTECT_SADDR5;

typedef struct 
{
unsigned int     content_prot_eaddr5:20;
unsigned int     reserved_0:12;
}WRAP_CONTENT_PROTECT_EADDR5;

typedef struct 
{
unsigned int     content_prot_saddr6:20;
unsigned int     reserved_0:12;
}WRAP_CONTENT_PROTECT_SADDR6;

typedef struct 
{
unsigned int     content_prot_eaddr6:20;
unsigned int     reserved_0:12;
}WRAP_CONTENT_PROTECT_EADDR6;

typedef struct 
{
unsigned int     content_prot_saddr7:20;
unsigned int     reserved_0:12;
}WRAP_CONTENT_PROTECT_SADDR7;

typedef struct 
{
unsigned int     content_prot_eaddr7:20;
unsigned int     reserved_0:12;
}WRAP_CONTENT_PROTECT_EADDR7;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     ns_scpu_acc_cont_prot_int:1;
unsigned int     ns_scpu_acc_cont_prot_int_en:1;
}WRAP_NS_SCPU_ACC_CONT_PROT_INT;

typedef struct 
{
unsigned int     ns_scpu_acc_cont_prot_addr:32;
}WRAP_NS_SCPU_ACC_CONT_PROT_ADDR;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     ns_scpu_acc_cont_prot_rw:1;
}WRAP_NS_SCPU_ACC_CONT_PROT_RW;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     display_prot_en1:1;
unsigned int     display_prot_en0:1;
}WRAP_DISPLAY_PROT_EN;

typedef struct 
{
unsigned int     display_prot_saddr0:20;
unsigned int     reserved_0:12;
}WRAP_DISPLAY_PROTECT_SADDR0;

typedef struct 
{
unsigned int     display_prot_eaddr0:20;
unsigned int     reserved_0:12;
}WRAP_DISPLAY_PROTECT_EADDR0;

typedef struct 
{
unsigned int     display_prot_saddr1:20;
unsigned int     reserved_0:12;
}WRAP_DISPLAY_PROTECT_SADDR1;

typedef struct 
{
unsigned int     display_prot_eaddr1:20;
unsigned int     reserved_0:12;
}WRAP_DISPLAY_PROTECT_EADDR1;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     ns_scpu_acc_disp_prot_int:1;
unsigned int     ns_scpu_acc_disp_prot_int_en:1;
}WRAP_NS_SCPU_ACC_DISP_PROT_INT;

typedef struct 
{
unsigned int     ns_scpu_acc_disp_prot_addr:32;
}WRAP_NS_SCPU_ACC_DISP_PROT_ADDR;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     ns_scpu_acc_disp_prot_rw:1;
}WRAP_NS_SCPU_ACC_DISP_PROT_RW;

#endif

#define WRAP_MEM_PROTECT_CTRL                                                        0x1805C800
#define WRAP_MEM_PROTECT_CTRL_reg_addr                                               "0xB805C800"
#define WRAP_MEM_PROTECT_CTRL_reg                                                    0xB805C800
#define set_WRAP_MEM_PROTECT_CTRL_reg(data)   (*((volatile unsigned int*) WRAP_MEM_PROTECT_CTRL_reg)=data)
#define get_WRAP_MEM_PROTECT_CTRL_reg   (*((volatile unsigned int*) WRAP_MEM_PROTECT_CTRL_reg))
#define WRAP_MEM_PROTECT_CTRL_inst_adr                                               "0x0000"
#define WRAP_MEM_PROTECT_CTRL_inst                                                   0x0000
#define WRAP_MEM_PROTECT_CTRL_protect_3_en_shift                                     (3)
#define WRAP_MEM_PROTECT_CTRL_protect_3_en_mask                                      (0x00000008)
#define WRAP_MEM_PROTECT_CTRL_protect_3_en(data)                                     (0x00000008&((data)<<3))
#define WRAP_MEM_PROTECT_CTRL_protect_3_en_src(data)                                 ((0x00000008&(data))>>3)
#define WRAP_MEM_PROTECT_CTRL_get_protect_3_en(data)                                 ((0x00000008&(data))>>3)
#define WRAP_MEM_PROTECT_CTRL_protect_2_en_shift                                     (2)
#define WRAP_MEM_PROTECT_CTRL_protect_2_en_mask                                      (0x00000004)
#define WRAP_MEM_PROTECT_CTRL_protect_2_en(data)                                     (0x00000004&((data)<<2))
#define WRAP_MEM_PROTECT_CTRL_protect_2_en_src(data)                                 ((0x00000004&(data))>>2)
#define WRAP_MEM_PROTECT_CTRL_get_protect_2_en(data)                                 ((0x00000004&(data))>>2)
#define WRAP_MEM_PROTECT_CTRL_protect_1_en_shift                                     (1)
#define WRAP_MEM_PROTECT_CTRL_protect_1_en_mask                                      (0x00000002)
#define WRAP_MEM_PROTECT_CTRL_protect_1_en(data)                                     (0x00000002&((data)<<1))
#define WRAP_MEM_PROTECT_CTRL_protect_1_en_src(data)                                 ((0x00000002&(data))>>1)
#define WRAP_MEM_PROTECT_CTRL_get_protect_1_en(data)                                 ((0x00000002&(data))>>1)
#define WRAP_MEM_PROTECT_CTRL_protect_0_en_shift                                     (0)
#define WRAP_MEM_PROTECT_CTRL_protect_0_en_mask                                      (0x00000001)
#define WRAP_MEM_PROTECT_CTRL_protect_0_en(data)                                     (0x00000001&((data)<<0))
#define WRAP_MEM_PROTECT_CTRL_protect_0_en_src(data)                                 ((0x00000001&(data))>>0)
#define WRAP_MEM_PROTECT_CTRL_get_protect_0_en(data)                                 ((0x00000001&(data))>>0)


#define WRAP_MEM_PROTECT_SADDR0                                                      0x1805C804
#define WRAP_MEM_PROTECT_SADDR0_reg_addr                                             "0xB805C804"
#define WRAP_MEM_PROTECT_SADDR0_reg                                                  0xB805C804
#define set_WRAP_MEM_PROTECT_SADDR0_reg(data)   (*((volatile unsigned int*) WRAP_MEM_PROTECT_SADDR0_reg)=data)
#define get_WRAP_MEM_PROTECT_SADDR0_reg   (*((volatile unsigned int*) WRAP_MEM_PROTECT_SADDR0_reg))
#define WRAP_MEM_PROTECT_SADDR0_inst_adr                                             "0x0001"
#define WRAP_MEM_PROTECT_SADDR0_inst                                                 0x0001
#define WRAP_MEM_PROTECT_SADDR0_protect_saddr0_shift                                 (12)
#define WRAP_MEM_PROTECT_SADDR0_protect_saddr0_mask                                  (0xFFFFF000)
#define WRAP_MEM_PROTECT_SADDR0_protect_saddr0(data)                                 (0xFFFFF000&((data)<<12))
#define WRAP_MEM_PROTECT_SADDR0_protect_saddr0_src(data)                             ((0xFFFFF000&(data))>>12)
#define WRAP_MEM_PROTECT_SADDR0_get_protect_saddr0(data)                             ((0xFFFFF000&(data))>>12)


#define WRAP_MEM_PROTECT_EADDR0                                                      0x1805C808
#define WRAP_MEM_PROTECT_EADDR0_reg_addr                                             "0xB805C808"
#define WRAP_MEM_PROTECT_EADDR0_reg                                                  0xB805C808
#define set_WRAP_MEM_PROTECT_EADDR0_reg(data)   (*((volatile unsigned int*) WRAP_MEM_PROTECT_EADDR0_reg)=data)
#define get_WRAP_MEM_PROTECT_EADDR0_reg   (*((volatile unsigned int*) WRAP_MEM_PROTECT_EADDR0_reg))
#define WRAP_MEM_PROTECT_EADDR0_inst_adr                                             "0x0002"
#define WRAP_MEM_PROTECT_EADDR0_inst                                                 0x0002
#define WRAP_MEM_PROTECT_EADDR0_protect_eaddr0_shift                                 (12)
#define WRAP_MEM_PROTECT_EADDR0_protect_eaddr0_mask                                  (0xFFFFF000)
#define WRAP_MEM_PROTECT_EADDR0_protect_eaddr0(data)                                 (0xFFFFF000&((data)<<12))
#define WRAP_MEM_PROTECT_EADDR0_protect_eaddr0_src(data)                             ((0xFFFFF000&(data))>>12)
#define WRAP_MEM_PROTECT_EADDR0_get_protect_eaddr0(data)                             ((0xFFFFF000&(data))>>12)


#define WRAP_MEM_PROTECT_SADDR1                                                      0x1805C80C
#define WRAP_MEM_PROTECT_SADDR1_reg_addr                                             "0xB805C80C"
#define WRAP_MEM_PROTECT_SADDR1_reg                                                  0xB805C80C
#define set_WRAP_MEM_PROTECT_SADDR1_reg(data)   (*((volatile unsigned int*) WRAP_MEM_PROTECT_SADDR1_reg)=data)
#define get_WRAP_MEM_PROTECT_SADDR1_reg   (*((volatile unsigned int*) WRAP_MEM_PROTECT_SADDR1_reg))
#define WRAP_MEM_PROTECT_SADDR1_inst_adr                                             "0x0003"
#define WRAP_MEM_PROTECT_SADDR1_inst                                                 0x0003
#define WRAP_MEM_PROTECT_SADDR1_protect_saddr1_shift                                 (12)
#define WRAP_MEM_PROTECT_SADDR1_protect_saddr1_mask                                  (0xFFFFF000)
#define WRAP_MEM_PROTECT_SADDR1_protect_saddr1(data)                                 (0xFFFFF000&((data)<<12))
#define WRAP_MEM_PROTECT_SADDR1_protect_saddr1_src(data)                             ((0xFFFFF000&(data))>>12)
#define WRAP_MEM_PROTECT_SADDR1_get_protect_saddr1(data)                             ((0xFFFFF000&(data))>>12)


#define WRAP_MEM_PROTECT_EADDR1                                                      0x1805C810
#define WRAP_MEM_PROTECT_EADDR1_reg_addr                                             "0xB805C810"
#define WRAP_MEM_PROTECT_EADDR1_reg                                                  0xB805C810
#define set_WRAP_MEM_PROTECT_EADDR1_reg(data)   (*((volatile unsigned int*) WRAP_MEM_PROTECT_EADDR1_reg)=data)
#define get_WRAP_MEM_PROTECT_EADDR1_reg   (*((volatile unsigned int*) WRAP_MEM_PROTECT_EADDR1_reg))
#define WRAP_MEM_PROTECT_EADDR1_inst_adr                                             "0x0004"
#define WRAP_MEM_PROTECT_EADDR1_inst                                                 0x0004
#define WRAP_MEM_PROTECT_EADDR1_protect_eaddr1_shift                                 (12)
#define WRAP_MEM_PROTECT_EADDR1_protect_eaddr1_mask                                  (0xFFFFF000)
#define WRAP_MEM_PROTECT_EADDR1_protect_eaddr1(data)                                 (0xFFFFF000&((data)<<12))
#define WRAP_MEM_PROTECT_EADDR1_protect_eaddr1_src(data)                             ((0xFFFFF000&(data))>>12)
#define WRAP_MEM_PROTECT_EADDR1_get_protect_eaddr1(data)                             ((0xFFFFF000&(data))>>12)


#define WRAP_MEM_PROTECT_SADDR2                                                      0x1805C814
#define WRAP_MEM_PROTECT_SADDR2_reg_addr                                             "0xB805C814"
#define WRAP_MEM_PROTECT_SADDR2_reg                                                  0xB805C814
#define set_WRAP_MEM_PROTECT_SADDR2_reg(data)   (*((volatile unsigned int*) WRAP_MEM_PROTECT_SADDR2_reg)=data)
#define get_WRAP_MEM_PROTECT_SADDR2_reg   (*((volatile unsigned int*) WRAP_MEM_PROTECT_SADDR2_reg))
#define WRAP_MEM_PROTECT_SADDR2_inst_adr                                             "0x0005"
#define WRAP_MEM_PROTECT_SADDR2_inst                                                 0x0005
#define WRAP_MEM_PROTECT_SADDR2_protect_saddr2_shift                                 (12)
#define WRAP_MEM_PROTECT_SADDR2_protect_saddr2_mask                                  (0xFFFFF000)
#define WRAP_MEM_PROTECT_SADDR2_protect_saddr2(data)                                 (0xFFFFF000&((data)<<12))
#define WRAP_MEM_PROTECT_SADDR2_protect_saddr2_src(data)                             ((0xFFFFF000&(data))>>12)
#define WRAP_MEM_PROTECT_SADDR2_get_protect_saddr2(data)                             ((0xFFFFF000&(data))>>12)


#define WRAP_MEM_PROTECT_EADDR2                                                      0x1805C818
#define WRAP_MEM_PROTECT_EADDR2_reg_addr                                             "0xB805C818"
#define WRAP_MEM_PROTECT_EADDR2_reg                                                  0xB805C818
#define set_WRAP_MEM_PROTECT_EADDR2_reg(data)   (*((volatile unsigned int*) WRAP_MEM_PROTECT_EADDR2_reg)=data)
#define get_WRAP_MEM_PROTECT_EADDR2_reg   (*((volatile unsigned int*) WRAP_MEM_PROTECT_EADDR2_reg))
#define WRAP_MEM_PROTECT_EADDR2_inst_adr                                             "0x0006"
#define WRAP_MEM_PROTECT_EADDR2_inst                                                 0x0006
#define WRAP_MEM_PROTECT_EADDR2_protect_eaddr2_shift                                 (12)
#define WRAP_MEM_PROTECT_EADDR2_protect_eaddr2_mask                                  (0xFFFFF000)
#define WRAP_MEM_PROTECT_EADDR2_protect_eaddr2(data)                                 (0xFFFFF000&((data)<<12))
#define WRAP_MEM_PROTECT_EADDR2_protect_eaddr2_src(data)                             ((0xFFFFF000&(data))>>12)
#define WRAP_MEM_PROTECT_EADDR2_get_protect_eaddr2(data)                             ((0xFFFFF000&(data))>>12)


#define WRAP_MEM_PROTECT_SADDR3                                                      0x1805C81C
#define WRAP_MEM_PROTECT_SADDR3_reg_addr                                             "0xB805C81C"
#define WRAP_MEM_PROTECT_SADDR3_reg                                                  0xB805C81C
#define set_WRAP_MEM_PROTECT_SADDR3_reg(data)   (*((volatile unsigned int*) WRAP_MEM_PROTECT_SADDR3_reg)=data)
#define get_WRAP_MEM_PROTECT_SADDR3_reg   (*((volatile unsigned int*) WRAP_MEM_PROTECT_SADDR3_reg))
#define WRAP_MEM_PROTECT_SADDR3_inst_adr                                             "0x0007"
#define WRAP_MEM_PROTECT_SADDR3_inst                                                 0x0007
#define WRAP_MEM_PROTECT_SADDR3_protect_saddr3_shift                                 (12)
#define WRAP_MEM_PROTECT_SADDR3_protect_saddr3_mask                                  (0xFFFFF000)
#define WRAP_MEM_PROTECT_SADDR3_protect_saddr3(data)                                 (0xFFFFF000&((data)<<12))
#define WRAP_MEM_PROTECT_SADDR3_protect_saddr3_src(data)                             ((0xFFFFF000&(data))>>12)
#define WRAP_MEM_PROTECT_SADDR3_get_protect_saddr3(data)                             ((0xFFFFF000&(data))>>12)


#define WRAP_MEM_PROTECT_EADDR3                                                      0x1805C820
#define WRAP_MEM_PROTECT_EADDR3_reg_addr                                             "0xB805C820"
#define WRAP_MEM_PROTECT_EADDR3_reg                                                  0xB805C820
#define set_WRAP_MEM_PROTECT_EADDR3_reg(data)   (*((volatile unsigned int*) WRAP_MEM_PROTECT_EADDR3_reg)=data)
#define get_WRAP_MEM_PROTECT_EADDR3_reg   (*((volatile unsigned int*) WRAP_MEM_PROTECT_EADDR3_reg))
#define WRAP_MEM_PROTECT_EADDR3_inst_adr                                             "0x0008"
#define WRAP_MEM_PROTECT_EADDR3_inst                                                 0x0008
#define WRAP_MEM_PROTECT_EADDR3_protect_eaddr3_shift                                 (12)
#define WRAP_MEM_PROTECT_EADDR3_protect_eaddr3_mask                                  (0xFFFFF000)
#define WRAP_MEM_PROTECT_EADDR3_protect_eaddr3(data)                                 (0xFFFFF000&((data)<<12))
#define WRAP_MEM_PROTECT_EADDR3_protect_eaddr3_src(data)                             ((0xFFFFF000&(data))>>12)
#define WRAP_MEM_PROTECT_EADDR3_get_protect_eaddr3(data)                             ((0xFFFFF000&(data))>>12)


#define WRAP_MEM_SCRAMBLE_TOTAL_0                                                    0x1805C824
#define WRAP_MEM_SCRAMBLE_TOTAL_0_reg_addr                                           "0xB805C824"
#define WRAP_MEM_SCRAMBLE_TOTAL_0_reg                                                0xB805C824
#define set_WRAP_MEM_SCRAMBLE_TOTAL_0_reg(data)   (*((volatile unsigned int*) WRAP_MEM_SCRAMBLE_TOTAL_0_reg)=data)
#define get_WRAP_MEM_SCRAMBLE_TOTAL_0_reg   (*((volatile unsigned int*) WRAP_MEM_SCRAMBLE_TOTAL_0_reg))
#define WRAP_MEM_SCRAMBLE_TOTAL_0_inst_adr                                           "0x0009"
#define WRAP_MEM_SCRAMBLE_TOTAL_0_inst                                               0x0009
#define WRAP_MEM_SCRAMBLE_TOTAL_0_key1_shift                                         (16)
#define WRAP_MEM_SCRAMBLE_TOTAL_0_key1_mask                                          (0xFFFF0000)
#define WRAP_MEM_SCRAMBLE_TOTAL_0_key1(data)                                         (0xFFFF0000&((data)<<16))
#define WRAP_MEM_SCRAMBLE_TOTAL_0_key1_src(data)                                     ((0xFFFF0000&(data))>>16)
#define WRAP_MEM_SCRAMBLE_TOTAL_0_get_key1(data)                                     ((0xFFFF0000&(data))>>16)
#define WRAP_MEM_SCRAMBLE_TOTAL_0_key0_shift                                         (0)
#define WRAP_MEM_SCRAMBLE_TOTAL_0_key0_mask                                          (0x0000FFFF)
#define WRAP_MEM_SCRAMBLE_TOTAL_0_key0(data)                                         (0x0000FFFF&((data)<<0))
#define WRAP_MEM_SCRAMBLE_TOTAL_0_key0_src(data)                                     ((0x0000FFFF&(data))>>0)
#define WRAP_MEM_SCRAMBLE_TOTAL_0_get_key0(data)                                     ((0x0000FFFF&(data))>>0)


#define WRAP_MEM_SCRAMBLE_TOTAL_1                                                    0x1805C828
#define WRAP_MEM_SCRAMBLE_TOTAL_1_reg_addr                                           "0xB805C828"
#define WRAP_MEM_SCRAMBLE_TOTAL_1_reg                                                0xB805C828
#define set_WRAP_MEM_SCRAMBLE_TOTAL_1_reg(data)   (*((volatile unsigned int*) WRAP_MEM_SCRAMBLE_TOTAL_1_reg)=data)
#define get_WRAP_MEM_SCRAMBLE_TOTAL_1_reg   (*((volatile unsigned int*) WRAP_MEM_SCRAMBLE_TOTAL_1_reg))
#define WRAP_MEM_SCRAMBLE_TOTAL_1_inst_adr                                           "0x000A"
#define WRAP_MEM_SCRAMBLE_TOTAL_1_inst                                               0x000A
#define WRAP_MEM_SCRAMBLE_TOTAL_1_key3_shift                                         (16)
#define WRAP_MEM_SCRAMBLE_TOTAL_1_key3_mask                                          (0xFFFF0000)
#define WRAP_MEM_SCRAMBLE_TOTAL_1_key3(data)                                         (0xFFFF0000&((data)<<16))
#define WRAP_MEM_SCRAMBLE_TOTAL_1_key3_src(data)                                     ((0xFFFF0000&(data))>>16)
#define WRAP_MEM_SCRAMBLE_TOTAL_1_get_key3(data)                                     ((0xFFFF0000&(data))>>16)
#define WRAP_MEM_SCRAMBLE_TOTAL_1_key2_shift                                         (0)
#define WRAP_MEM_SCRAMBLE_TOTAL_1_key2_mask                                          (0x0000FFFF)
#define WRAP_MEM_SCRAMBLE_TOTAL_1_key2(data)                                         (0x0000FFFF&((data)<<0))
#define WRAP_MEM_SCRAMBLE_TOTAL_1_key2_src(data)                                     ((0x0000FFFF&(data))>>0)
#define WRAP_MEM_SCRAMBLE_TOTAL_1_get_key2(data)                                     ((0x0000FFFF&(data))>>0)


#define WRAP_MEM_SCRAMBLE_TOTAL_2                                                    0x1805C82C
#define WRAP_MEM_SCRAMBLE_TOTAL_2_reg_addr                                           "0xB805C82C"
#define WRAP_MEM_SCRAMBLE_TOTAL_2_reg                                                0xB805C82C
#define set_WRAP_MEM_SCRAMBLE_TOTAL_2_reg(data)   (*((volatile unsigned int*) WRAP_MEM_SCRAMBLE_TOTAL_2_reg)=data)
#define get_WRAP_MEM_SCRAMBLE_TOTAL_2_reg   (*((volatile unsigned int*) WRAP_MEM_SCRAMBLE_TOTAL_2_reg))
#define WRAP_MEM_SCRAMBLE_TOTAL_2_inst_adr                                           "0x000B"
#define WRAP_MEM_SCRAMBLE_TOTAL_2_inst                                               0x000B
#define WRAP_MEM_SCRAMBLE_TOTAL_2_key5_shift                                         (16)
#define WRAP_MEM_SCRAMBLE_TOTAL_2_key5_mask                                          (0xFFFF0000)
#define WRAP_MEM_SCRAMBLE_TOTAL_2_key5(data)                                         (0xFFFF0000&((data)<<16))
#define WRAP_MEM_SCRAMBLE_TOTAL_2_key5_src(data)                                     ((0xFFFF0000&(data))>>16)
#define WRAP_MEM_SCRAMBLE_TOTAL_2_get_key5(data)                                     ((0xFFFF0000&(data))>>16)
#define WRAP_MEM_SCRAMBLE_TOTAL_2_key4_shift                                         (0)
#define WRAP_MEM_SCRAMBLE_TOTAL_2_key4_mask                                          (0x0000FFFF)
#define WRAP_MEM_SCRAMBLE_TOTAL_2_key4(data)                                         (0x0000FFFF&((data)<<0))
#define WRAP_MEM_SCRAMBLE_TOTAL_2_key4_src(data)                                     ((0x0000FFFF&(data))>>0)
#define WRAP_MEM_SCRAMBLE_TOTAL_2_get_key4(data)                                     ((0x0000FFFF&(data))>>0)


#define WRAP_MEM_SCRAMBLE_TOTAL_3                                                    0x1805C830
#define WRAP_MEM_SCRAMBLE_TOTAL_3_reg_addr                                           "0xB805C830"
#define WRAP_MEM_SCRAMBLE_TOTAL_3_reg                                                0xB805C830
#define set_WRAP_MEM_SCRAMBLE_TOTAL_3_reg(data)   (*((volatile unsigned int*) WRAP_MEM_SCRAMBLE_TOTAL_3_reg)=data)
#define get_WRAP_MEM_SCRAMBLE_TOTAL_3_reg   (*((volatile unsigned int*) WRAP_MEM_SCRAMBLE_TOTAL_3_reg))
#define WRAP_MEM_SCRAMBLE_TOTAL_3_inst_adr                                           "0x000C"
#define WRAP_MEM_SCRAMBLE_TOTAL_3_inst                                               0x000C
#define WRAP_MEM_SCRAMBLE_TOTAL_3_key7_shift                                         (16)
#define WRAP_MEM_SCRAMBLE_TOTAL_3_key7_mask                                          (0xFFFF0000)
#define WRAP_MEM_SCRAMBLE_TOTAL_3_key7(data)                                         (0xFFFF0000&((data)<<16))
#define WRAP_MEM_SCRAMBLE_TOTAL_3_key7_src(data)                                     ((0xFFFF0000&(data))>>16)
#define WRAP_MEM_SCRAMBLE_TOTAL_3_get_key7(data)                                     ((0xFFFF0000&(data))>>16)
#define WRAP_MEM_SCRAMBLE_TOTAL_3_key6_shift                                         (0)
#define WRAP_MEM_SCRAMBLE_TOTAL_3_key6_mask                                          (0x0000FFFF)
#define WRAP_MEM_SCRAMBLE_TOTAL_3_key6(data)                                         (0x0000FFFF&((data)<<0))
#define WRAP_MEM_SCRAMBLE_TOTAL_3_key6_src(data)                                     ((0x0000FFFF&(data))>>0)
#define WRAP_MEM_SCRAMBLE_TOTAL_3_get_key6(data)                                     ((0x0000FFFF&(data))>>0)


#define WRAP_MEM_SCRAMBLE_TOTAL_4                                                    0x1805C834
#define WRAP_MEM_SCRAMBLE_TOTAL_4_reg_addr                                           "0xB805C834"
#define WRAP_MEM_SCRAMBLE_TOTAL_4_reg                                                0xB805C834
#define set_WRAP_MEM_SCRAMBLE_TOTAL_4_reg(data)   (*((volatile unsigned int*) WRAP_MEM_SCRAMBLE_TOTAL_4_reg)=data)
#define get_WRAP_MEM_SCRAMBLE_TOTAL_4_reg   (*((volatile unsigned int*) WRAP_MEM_SCRAMBLE_TOTAL_4_reg))
#define WRAP_MEM_SCRAMBLE_TOTAL_4_inst_adr                                           "0x000D"
#define WRAP_MEM_SCRAMBLE_TOTAL_4_inst                                               0x000D
#define WRAP_MEM_SCRAMBLE_TOTAL_4_key9_shift                                         (16)
#define WRAP_MEM_SCRAMBLE_TOTAL_4_key9_mask                                          (0xFFFF0000)
#define WRAP_MEM_SCRAMBLE_TOTAL_4_key9(data)                                         (0xFFFF0000&((data)<<16))
#define WRAP_MEM_SCRAMBLE_TOTAL_4_key9_src(data)                                     ((0xFFFF0000&(data))>>16)
#define WRAP_MEM_SCRAMBLE_TOTAL_4_get_key9(data)                                     ((0xFFFF0000&(data))>>16)
#define WRAP_MEM_SCRAMBLE_TOTAL_4_key8_shift                                         (0)
#define WRAP_MEM_SCRAMBLE_TOTAL_4_key8_mask                                          (0x0000FFFF)
#define WRAP_MEM_SCRAMBLE_TOTAL_4_key8(data)                                         (0x0000FFFF&((data)<<0))
#define WRAP_MEM_SCRAMBLE_TOTAL_4_key8_src(data)                                     ((0x0000FFFF&(data))>>0)
#define WRAP_MEM_SCRAMBLE_TOTAL_4_get_key8(data)                                     ((0x0000FFFF&(data))>>0)


#define WRAP_MEM_SCRAMBLE_TOTAL_5                                                    0x1805C838
#define WRAP_MEM_SCRAMBLE_TOTAL_5_reg_addr                                           "0xB805C838"
#define WRAP_MEM_SCRAMBLE_TOTAL_5_reg                                                0xB805C838
#define set_WRAP_MEM_SCRAMBLE_TOTAL_5_reg(data)   (*((volatile unsigned int*) WRAP_MEM_SCRAMBLE_TOTAL_5_reg)=data)
#define get_WRAP_MEM_SCRAMBLE_TOTAL_5_reg   (*((volatile unsigned int*) WRAP_MEM_SCRAMBLE_TOTAL_5_reg))
#define WRAP_MEM_SCRAMBLE_TOTAL_5_inst_adr                                           "0x000E"
#define WRAP_MEM_SCRAMBLE_TOTAL_5_inst                                               0x000E
#define WRAP_MEM_SCRAMBLE_TOTAL_5_keyB_shift                                         (16)
#define WRAP_MEM_SCRAMBLE_TOTAL_5_keyB_mask                                          (0xFFFF0000)
#define WRAP_MEM_SCRAMBLE_TOTAL_5_keyB(data)                                         (0xFFFF0000&((data)<<16))
#define WRAP_MEM_SCRAMBLE_TOTAL_5_keyB_src(data)                                     ((0xFFFF0000&(data))>>16)
#define WRAP_MEM_SCRAMBLE_TOTAL_5_get_keyB(data)                                     ((0xFFFF0000&(data))>>16)
#define WRAP_MEM_SCRAMBLE_TOTAL_5_keyA_shift                                         (0)
#define WRAP_MEM_SCRAMBLE_TOTAL_5_keyA_mask                                          (0x0000FFFF)
#define WRAP_MEM_SCRAMBLE_TOTAL_5_keyA(data)                                         (0x0000FFFF&((data)<<0))
#define WRAP_MEM_SCRAMBLE_TOTAL_5_keyA_src(data)                                     ((0x0000FFFF&(data))>>0)
#define WRAP_MEM_SCRAMBLE_TOTAL_5_get_keyA(data)                                     ((0x0000FFFF&(data))>>0)


#define WRAP_MEM_SCRAMBLE_TOTAL_6                                                    0x1805C83C
#define WRAP_MEM_SCRAMBLE_TOTAL_6_reg_addr                                           "0xB805C83C"
#define WRAP_MEM_SCRAMBLE_TOTAL_6_reg                                                0xB805C83C
#define set_WRAP_MEM_SCRAMBLE_TOTAL_6_reg(data)   (*((volatile unsigned int*) WRAP_MEM_SCRAMBLE_TOTAL_6_reg)=data)
#define get_WRAP_MEM_SCRAMBLE_TOTAL_6_reg   (*((volatile unsigned int*) WRAP_MEM_SCRAMBLE_TOTAL_6_reg))
#define WRAP_MEM_SCRAMBLE_TOTAL_6_inst_adr                                           "0x000F"
#define WRAP_MEM_SCRAMBLE_TOTAL_6_inst                                               0x000F
#define WRAP_MEM_SCRAMBLE_TOTAL_6_keyD_shift                                         (16)
#define WRAP_MEM_SCRAMBLE_TOTAL_6_keyD_mask                                          (0xFFFF0000)
#define WRAP_MEM_SCRAMBLE_TOTAL_6_keyD(data)                                         (0xFFFF0000&((data)<<16))
#define WRAP_MEM_SCRAMBLE_TOTAL_6_keyD_src(data)                                     ((0xFFFF0000&(data))>>16)
#define WRAP_MEM_SCRAMBLE_TOTAL_6_get_keyD(data)                                     ((0xFFFF0000&(data))>>16)
#define WRAP_MEM_SCRAMBLE_TOTAL_6_keyC_shift                                         (0)
#define WRAP_MEM_SCRAMBLE_TOTAL_6_keyC_mask                                          (0x0000FFFF)
#define WRAP_MEM_SCRAMBLE_TOTAL_6_keyC(data)                                         (0x0000FFFF&((data)<<0))
#define WRAP_MEM_SCRAMBLE_TOTAL_6_keyC_src(data)                                     ((0x0000FFFF&(data))>>0)
#define WRAP_MEM_SCRAMBLE_TOTAL_6_get_keyC(data)                                     ((0x0000FFFF&(data))>>0)


#define WRAP_MEM_SCRAMBLE_EN                                                         0x1805C840
#define WRAP_MEM_SCRAMBLE_EN_reg_addr                                                "0xB805C840"
#define WRAP_MEM_SCRAMBLE_EN_reg                                                     0xB805C840
#define set_WRAP_MEM_SCRAMBLE_EN_reg(data)   (*((volatile unsigned int*) WRAP_MEM_SCRAMBLE_EN_reg)=data)
#define get_WRAP_MEM_SCRAMBLE_EN_reg   (*((volatile unsigned int*) WRAP_MEM_SCRAMBLE_EN_reg))
#define WRAP_MEM_SCRAMBLE_EN_inst_adr                                                "0x0010"
#define WRAP_MEM_SCRAMBLE_EN_inst                                                    0x0010
#define WRAP_MEM_SCRAMBLE_EN_scpu_scramble_en_shift                                  (0)
#define WRAP_MEM_SCRAMBLE_EN_scpu_scramble_en_mask                                   (0x00000001)
#define WRAP_MEM_SCRAMBLE_EN_scpu_scramble_en(data)                                  (0x00000001&((data)<<0))
#define WRAP_MEM_SCRAMBLE_EN_scpu_scramble_en_src(data)                              ((0x00000001&(data))>>0)
#define WRAP_MEM_SCRAMBLE_EN_get_scpu_scramble_en(data)                              ((0x00000001&(data))>>0)


#define WRAP_DBG_SEL_CTRL                                                            0x1805C844
#define WRAP_DBG_SEL_CTRL_reg_addr                                                   "0xB805C844"
#define WRAP_DBG_SEL_CTRL_reg                                                        0xB805C844
#define set_WRAP_DBG_SEL_CTRL_reg(data)   (*((volatile unsigned int*) WRAP_DBG_SEL_CTRL_reg)=data)
#define get_WRAP_DBG_SEL_CTRL_reg   (*((volatile unsigned int*) WRAP_DBG_SEL_CTRL_reg))
#define WRAP_DBG_SEL_CTRL_inst_adr                                                   "0x0011"
#define WRAP_DBG_SEL_CTRL_inst                                                       0x0011
#define WRAP_DBG_SEL_CTRL_scpu_dbg_mode_sel_shift                                    (12)
#define WRAP_DBG_SEL_CTRL_scpu_dbg_mode_sel_mask                                     (0x00003000)
#define WRAP_DBG_SEL_CTRL_scpu_dbg_mode_sel(data)                                    (0x00003000&((data)<<12))
#define WRAP_DBG_SEL_CTRL_scpu_dbg_mode_sel_src(data)                                ((0x00003000&(data))>>12)
#define WRAP_DBG_SEL_CTRL_get_scpu_dbg_mode_sel(data)                                ((0x00003000&(data))>>12)
#define WRAP_DBG_SEL_CTRL_scpu_dbg_sel_dc_shift                                      (8)
#define WRAP_DBG_SEL_CTRL_scpu_dbg_sel_dc_mask                                       (0x00000F00)
#define WRAP_DBG_SEL_CTRL_scpu_dbg_sel_dc(data)                                      (0x00000F00&((data)<<8))
#define WRAP_DBG_SEL_CTRL_scpu_dbg_sel_dc_src(data)                                  ((0x00000F00&(data))>>8)
#define WRAP_DBG_SEL_CTRL_get_scpu_dbg_sel_dc(data)                                  ((0x00000F00&(data))>>8)
#define WRAP_DBG_SEL_CTRL_scpu_dbg_sel_fr_shift                                      (4)
#define WRAP_DBG_SEL_CTRL_scpu_dbg_sel_fr_mask                                       (0x000000F0)
#define WRAP_DBG_SEL_CTRL_scpu_dbg_sel_fr(data)                                      (0x000000F0&((data)<<4))
#define WRAP_DBG_SEL_CTRL_scpu_dbg_sel_fr_src(data)                                  ((0x000000F0&(data))>>4)
#define WRAP_DBG_SEL_CTRL_get_scpu_dbg_sel_fr(data)                                  ((0x000000F0&(data))>>4)
#define WRAP_DBG_SEL_CTRL_scpu_dbg_sel_dis_shift                                     (0)
#define WRAP_DBG_SEL_CTRL_scpu_dbg_sel_dis_mask                                      (0x0000000F)
#define WRAP_DBG_SEL_CTRL_scpu_dbg_sel_dis(data)                                     (0x0000000F&((data)<<0))
#define WRAP_DBG_SEL_CTRL_scpu_dbg_sel_dis_src(data)                                 ((0x0000000F&(data))>>0)
#define WRAP_DBG_SEL_CTRL_get_scpu_dbg_sel_dis(data)                                 ((0x0000000F&(data))>>0)


#define WRAP_CORE_INPUT_CTRL0                                                        0x1805C848
#define WRAP_CORE_INPUT_CTRL0_reg_addr                                               "0xB805C848"
#define WRAP_CORE_INPUT_CTRL0_reg                                                    0xB805C848
#define set_WRAP_CORE_INPUT_CTRL0_reg(data)   (*((volatile unsigned int*) WRAP_CORE_INPUT_CTRL0_reg)=data)
#define get_WRAP_CORE_INPUT_CTRL0_reg   (*((volatile unsigned int*) WRAP_CORE_INPUT_CTRL0_reg))
#define WRAP_CORE_INPUT_CTRL0_inst_adr                                               "0x0012"
#define WRAP_CORE_INPUT_CTRL0_inst                                                   0x0012
#define WRAP_CORE_INPUT_CTRL0_cp15sdisable_shift                                     (5)
#define WRAP_CORE_INPUT_CTRL0_cp15sdisable_mask                                      (0x000001E0)
#define WRAP_CORE_INPUT_CTRL0_cp15sdisable(data)                                     (0x000001E0&((data)<<5))
#define WRAP_CORE_INPUT_CTRL0_cp15sdisable_src(data)                                 ((0x000001E0&(data))>>5)
#define WRAP_CORE_INPUT_CTRL0_get_cp15sdisable(data)                                 ((0x000001E0&(data))>>5)
#define WRAP_CORE_INPUT_CTRL0_cfgsdisable_shift                                      (4)
#define WRAP_CORE_INPUT_CTRL0_cfgsdisable_mask                                       (0x00000010)
#define WRAP_CORE_INPUT_CTRL0_cfgsdisable(data)                                      (0x00000010&((data)<<4))
#define WRAP_CORE_INPUT_CTRL0_cfgsdisable_src(data)                                  ((0x00000010&(data))>>4)
#define WRAP_CORE_INPUT_CTRL0_get_cfgsdisable(data)                                  ((0x00000010&(data))>>4)
#define WRAP_CORE_INPUT_CTRL0_dbgen_source_sel_shift                                 (3)
#define WRAP_CORE_INPUT_CTRL0_dbgen_source_sel_mask                                  (0x00000008)
#define WRAP_CORE_INPUT_CTRL0_dbgen_source_sel(data)                                 (0x00000008&((data)<<3))
#define WRAP_CORE_INPUT_CTRL0_dbgen_source_sel_src(data)                             ((0x00000008&(data))>>3)
#define WRAP_CORE_INPUT_CTRL0_get_dbgen_source_sel(data)                             ((0x00000008&(data))>>3)
#define WRAP_CORE_INPUT_CTRL0_spiden_source_sel_shift                                (2)
#define WRAP_CORE_INPUT_CTRL0_spiden_source_sel_mask                                 (0x00000004)
#define WRAP_CORE_INPUT_CTRL0_spiden_source_sel(data)                                (0x00000004&((data)<<2))
#define WRAP_CORE_INPUT_CTRL0_spiden_source_sel_src(data)                            ((0x00000004&(data))>>2)
#define WRAP_CORE_INPUT_CTRL0_get_spiden_source_sel(data)                            ((0x00000004&(data))>>2)
#define WRAP_CORE_INPUT_CTRL0_niden_source_sel_shift                                 (1)
#define WRAP_CORE_INPUT_CTRL0_niden_source_sel_mask                                  (0x00000002)
#define WRAP_CORE_INPUT_CTRL0_niden_source_sel(data)                                 (0x00000002&((data)<<1))
#define WRAP_CORE_INPUT_CTRL0_niden_source_sel_src(data)                             ((0x00000002&(data))>>1)
#define WRAP_CORE_INPUT_CTRL0_get_niden_source_sel(data)                             ((0x00000002&(data))>>1)
#define WRAP_CORE_INPUT_CTRL0_spniden_source_sel_shift                               (0)
#define WRAP_CORE_INPUT_CTRL0_spniden_source_sel_mask                                (0x00000001)
#define WRAP_CORE_INPUT_CTRL0_spniden_source_sel(data)                               (0x00000001&((data)<<0))
#define WRAP_CORE_INPUT_CTRL0_spniden_source_sel_src(data)                           ((0x00000001&(data))>>0)
#define WRAP_CORE_INPUT_CTRL0_get_spniden_source_sel(data)                           ((0x00000001&(data))>>0)


#define WRAP_CORE_INPUT_CTRL1                                                        0x1805C84C
#define WRAP_CORE_INPUT_CTRL1_reg_addr                                               "0xB805C84C"
#define WRAP_CORE_INPUT_CTRL1_reg                                                    0xB805C84C
#define set_WRAP_CORE_INPUT_CTRL1_reg(data)   (*((volatile unsigned int*) WRAP_CORE_INPUT_CTRL1_reg)=data)
#define get_WRAP_CORE_INPUT_CTRL1_reg   (*((volatile unsigned int*) WRAP_CORE_INPUT_CTRL1_reg))
#define WRAP_CORE_INPUT_CTRL1_inst_adr                                               "0x0013"
#define WRAP_CORE_INPUT_CTRL1_inst                                                   0x0013
#define WRAP_CORE_INPUT_CTRL1_cfgaddrfilterens_shift                                 (30)
#define WRAP_CORE_INPUT_CTRL1_cfgaddrfilterens_mask                                  (0x40000000)
#define WRAP_CORE_INPUT_CTRL1_cfgaddrfilterens(data)                                 (0x40000000&((data)<<30))
#define WRAP_CORE_INPUT_CTRL1_cfgaddrfilterens_src(data)                             ((0x40000000&(data))>>30)
#define WRAP_CORE_INPUT_CTRL1_get_cfgaddrfilterens(data)                             ((0x40000000&(data))>>30)
#define WRAP_CORE_INPUT_CTRL1_cfgaddrfilterstarts_shift                              (16)
#define WRAP_CORE_INPUT_CTRL1_cfgaddrfilterstarts_mask                               (0x0FFF0000)
#define WRAP_CORE_INPUT_CTRL1_cfgaddrfilterstarts(data)                              (0x0FFF0000&((data)<<16))
#define WRAP_CORE_INPUT_CTRL1_cfgaddrfilterstarts_src(data)                          ((0x0FFF0000&(data))>>16)
#define WRAP_CORE_INPUT_CTRL1_get_cfgaddrfilterstarts(data)                          ((0x0FFF0000&(data))>>16)
#define WRAP_CORE_INPUT_CTRL1_cfgaddrfilterends_shift                                (0)
#define WRAP_CORE_INPUT_CTRL1_cfgaddrfilterends_mask                                 (0x00000FFF)
#define WRAP_CORE_INPUT_CTRL1_cfgaddrfilterends(data)                                (0x00000FFF&((data)<<0))
#define WRAP_CORE_INPUT_CTRL1_cfgaddrfilterends_src(data)                            ((0x00000FFF&(data))>>0)
#define WRAP_CORE_INPUT_CTRL1_get_cfgaddrfilterends(data)                            ((0x00000FFF&(data))>>0)


#define WRAP_CORE_INPUT_CTRL2                                                        0x1805C850
#define WRAP_CORE_INPUT_CTRL2_reg_addr                                               "0xB805C850"
#define WRAP_CORE_INPUT_CTRL2_reg                                                    0xB805C850
#define set_WRAP_CORE_INPUT_CTRL2_reg(data)   (*((volatile unsigned int*) WRAP_CORE_INPUT_CTRL2_reg)=data)
#define get_WRAP_CORE_INPUT_CTRL2_reg   (*((volatile unsigned int*) WRAP_CORE_INPUT_CTRL2_reg))
#define WRAP_CORE_INPUT_CTRL2_inst_adr                                               "0x0014"
#define WRAP_CORE_INPUT_CTRL2_inst                                                   0x0014
#define WRAP_CORE_INPUT_CTRL2_cfgaddrfilterenns_shift                                (30)
#define WRAP_CORE_INPUT_CTRL2_cfgaddrfilterenns_mask                                 (0x40000000)
#define WRAP_CORE_INPUT_CTRL2_cfgaddrfilterenns(data)                                (0x40000000&((data)<<30))
#define WRAP_CORE_INPUT_CTRL2_cfgaddrfilterenns_src(data)                            ((0x40000000&(data))>>30)
#define WRAP_CORE_INPUT_CTRL2_get_cfgaddrfilterenns(data)                            ((0x40000000&(data))>>30)
#define WRAP_CORE_INPUT_CTRL2_cfgaddrfilterstartns_shift                             (16)
#define WRAP_CORE_INPUT_CTRL2_cfgaddrfilterstartns_mask                              (0x0FFF0000)
#define WRAP_CORE_INPUT_CTRL2_cfgaddrfilterstartns(data)                             (0x0FFF0000&((data)<<16))
#define WRAP_CORE_INPUT_CTRL2_cfgaddrfilterstartns_src(data)                         ((0x0FFF0000&(data))>>16)
#define WRAP_CORE_INPUT_CTRL2_get_cfgaddrfilterstartns(data)                         ((0x0FFF0000&(data))>>16)
#define WRAP_CORE_INPUT_CTRL2_cfgaddrfilterendns_shift                               (0)
#define WRAP_CORE_INPUT_CTRL2_cfgaddrfilterendns_mask                                (0x00000FFF)
#define WRAP_CORE_INPUT_CTRL2_cfgaddrfilterendns(data)                               (0x00000FFF&((data)<<0))
#define WRAP_CORE_INPUT_CTRL2_cfgaddrfilterendns_src(data)                           ((0x00000FFF&(data))>>0)
#define WRAP_CORE_INPUT_CTRL2_get_cfgaddrfilterendns(data)                           ((0x00000FFF&(data))>>0)


#define WRAP_TSGEN_INPUT_CTRL0                                                       0x1805C854
#define WRAP_TSGEN_INPUT_CTRL0_reg_addr                                              "0xB805C854"
#define WRAP_TSGEN_INPUT_CTRL0_reg                                                   0xB805C854
#define set_WRAP_TSGEN_INPUT_CTRL0_reg(data)   (*((volatile unsigned int*) WRAP_TSGEN_INPUT_CTRL0_reg)=data)
#define get_WRAP_TSGEN_INPUT_CTRL0_reg   (*((volatile unsigned int*) WRAP_TSGEN_INPUT_CTRL0_reg))
#define WRAP_TSGEN_INPUT_CTRL0_inst_adr                                              "0x0015"
#define WRAP_TSGEN_INPUT_CTRL0_inst                                                  0x0015
#define WRAP_TSGEN_INPUT_CTRL0_apb_tsgen_a_shift                                     (0)
#define WRAP_TSGEN_INPUT_CTRL0_apb_tsgen_a_mask                                      (0xFFFFFFFF)
#define WRAP_TSGEN_INPUT_CTRL0_apb_tsgen_a(data)                                     (0xFFFFFFFF&((data)<<0))
#define WRAP_TSGEN_INPUT_CTRL0_apb_tsgen_a_src(data)                                 ((0xFFFFFFFF&(data))>>0)
#define WRAP_TSGEN_INPUT_CTRL0_get_apb_tsgen_a(data)                                 ((0xFFFFFFFF&(data))>>0)


#define WRAP_TSGEN_INPUT_CTRL1                                                       0x1805C858
#define WRAP_TSGEN_INPUT_CTRL1_reg_addr                                              "0xB805C858"
#define WRAP_TSGEN_INPUT_CTRL1_reg                                                   0xB805C858
#define set_WRAP_TSGEN_INPUT_CTRL1_reg(data)   (*((volatile unsigned int*) WRAP_TSGEN_INPUT_CTRL1_reg)=data)
#define get_WRAP_TSGEN_INPUT_CTRL1_reg   (*((volatile unsigned int*) WRAP_TSGEN_INPUT_CTRL1_reg))
#define WRAP_TSGEN_INPUT_CTRL1_inst_adr                                              "0x0016"
#define WRAP_TSGEN_INPUT_CTRL1_inst                                                  0x0016
#define WRAP_TSGEN_INPUT_CTRL1_apb_tsgen_d_shift                                     (0)
#define WRAP_TSGEN_INPUT_CTRL1_apb_tsgen_d_mask                                      (0xFFFFFFFF)
#define WRAP_TSGEN_INPUT_CTRL1_apb_tsgen_d(data)                                     (0xFFFFFFFF&((data)<<0))
#define WRAP_TSGEN_INPUT_CTRL1_apb_tsgen_d_src(data)                                 ((0xFFFFFFFF&(data))>>0)
#define WRAP_TSGEN_INPUT_CTRL1_get_apb_tsgen_d(data)                                 ((0xFFFFFFFF&(data))>>0)


#define WRAP_TSGEN_INPUT_CTRL2                                                       0x1805C85C
#define WRAP_TSGEN_INPUT_CTRL2_reg_addr                                              "0xB805C85C"
#define WRAP_TSGEN_INPUT_CTRL2_reg                                                   0xB805C85C
#define set_WRAP_TSGEN_INPUT_CTRL2_reg(data)   (*((volatile unsigned int*) WRAP_TSGEN_INPUT_CTRL2_reg)=data)
#define get_WRAP_TSGEN_INPUT_CTRL2_reg   (*((volatile unsigned int*) WRAP_TSGEN_INPUT_CTRL2_reg))
#define WRAP_TSGEN_INPUT_CTRL2_inst_adr                                              "0x0017"
#define WRAP_TSGEN_INPUT_CTRL2_inst                                                  0x0017
#define WRAP_TSGEN_INPUT_CTRL2_apb_tsgen_slverr_shift                                (0)
#define WRAP_TSGEN_INPUT_CTRL2_apb_tsgen_slverr_mask                                 (0x00000001)
#define WRAP_TSGEN_INPUT_CTRL2_apb_tsgen_slverr(data)                                (0x00000001&((data)<<0))
#define WRAP_TSGEN_INPUT_CTRL2_apb_tsgen_slverr_src(data)                            ((0x00000001&(data))>>0)
#define WRAP_TSGEN_INPUT_CTRL2_get_apb_tsgen_slverr(data)                            ((0x00000001&(data))>>0)


#define WRAP_NS_SCPU_ACC_PROT_INT                                                    0x1805C860
#define WRAP_NS_SCPU_ACC_PROT_INT_reg_addr                                           "0xB805C860"
#define WRAP_NS_SCPU_ACC_PROT_INT_reg                                                0xB805C860
#define set_WRAP_NS_SCPU_ACC_PROT_INT_reg(data)   (*((volatile unsigned int*) WRAP_NS_SCPU_ACC_PROT_INT_reg)=data)
#define get_WRAP_NS_SCPU_ACC_PROT_INT_reg   (*((volatile unsigned int*) WRAP_NS_SCPU_ACC_PROT_INT_reg))
#define WRAP_NS_SCPU_ACC_PROT_INT_inst_adr                                           "0x0018"
#define WRAP_NS_SCPU_ACC_PROT_INT_inst                                               0x0018
#define WRAP_NS_SCPU_ACC_PROT_INT_ns_scpu_acc_prot_int_shift                         (1)
#define WRAP_NS_SCPU_ACC_PROT_INT_ns_scpu_acc_prot_int_mask                          (0x00000002)
#define WRAP_NS_SCPU_ACC_PROT_INT_ns_scpu_acc_prot_int(data)                         (0x00000002&((data)<<1))
#define WRAP_NS_SCPU_ACC_PROT_INT_ns_scpu_acc_prot_int_src(data)                     ((0x00000002&(data))>>1)
#define WRAP_NS_SCPU_ACC_PROT_INT_get_ns_scpu_acc_prot_int(data)                     ((0x00000002&(data))>>1)
#define WRAP_NS_SCPU_ACC_PROT_INT_ns_scpu_acc_prot_int_en_shift                      (0)
#define WRAP_NS_SCPU_ACC_PROT_INT_ns_scpu_acc_prot_int_en_mask                       (0x00000001)
#define WRAP_NS_SCPU_ACC_PROT_INT_ns_scpu_acc_prot_int_en(data)                      (0x00000001&((data)<<0))
#define WRAP_NS_SCPU_ACC_PROT_INT_ns_scpu_acc_prot_int_en_src(data)                  ((0x00000001&(data))>>0)
#define WRAP_NS_SCPU_ACC_PROT_INT_get_ns_scpu_acc_prot_int_en(data)                  ((0x00000001&(data))>>0)


#define WRAP_NS_SCPU_ACC_PROT_ADDR                                                   0x1805C864
#define WRAP_NS_SCPU_ACC_PROT_ADDR_reg_addr                                          "0xB805C864"
#define WRAP_NS_SCPU_ACC_PROT_ADDR_reg                                               0xB805C864
#define set_WRAP_NS_SCPU_ACC_PROT_ADDR_reg(data)   (*((volatile unsigned int*) WRAP_NS_SCPU_ACC_PROT_ADDR_reg)=data)
#define get_WRAP_NS_SCPU_ACC_PROT_ADDR_reg   (*((volatile unsigned int*) WRAP_NS_SCPU_ACC_PROT_ADDR_reg))
#define WRAP_NS_SCPU_ACC_PROT_ADDR_inst_adr                                          "0x0019"
#define WRAP_NS_SCPU_ACC_PROT_ADDR_inst                                              0x0019
#define WRAP_NS_SCPU_ACC_PROT_ADDR_ns_scpu_acc_prot_addr_shift                       (0)
#define WRAP_NS_SCPU_ACC_PROT_ADDR_ns_scpu_acc_prot_addr_mask                        (0xFFFFFFFF)
#define WRAP_NS_SCPU_ACC_PROT_ADDR_ns_scpu_acc_prot_addr(data)                       (0xFFFFFFFF&((data)<<0))
#define WRAP_NS_SCPU_ACC_PROT_ADDR_ns_scpu_acc_prot_addr_src(data)                   ((0xFFFFFFFF&(data))>>0)
#define WRAP_NS_SCPU_ACC_PROT_ADDR_get_ns_scpu_acc_prot_addr(data)                   ((0xFFFFFFFF&(data))>>0)


#define WRAP_NS_SCPU_ACC_PROT_RW                                                     0x1805C868
#define WRAP_NS_SCPU_ACC_PROT_RW_reg_addr                                            "0xB805C868"
#define WRAP_NS_SCPU_ACC_PROT_RW_reg                                                 0xB805C868
#define set_WRAP_NS_SCPU_ACC_PROT_RW_reg(data)   (*((volatile unsigned int*) WRAP_NS_SCPU_ACC_PROT_RW_reg)=data)
#define get_WRAP_NS_SCPU_ACC_PROT_RW_reg   (*((volatile unsigned int*) WRAP_NS_SCPU_ACC_PROT_RW_reg))
#define WRAP_NS_SCPU_ACC_PROT_RW_inst_adr                                            "0x001A"
#define WRAP_NS_SCPU_ACC_PROT_RW_inst                                                0x001A
#define WRAP_NS_SCPU_ACC_PROT_RW_ns_scpu_acc_prot_rw_shift                           (0)
#define WRAP_NS_SCPU_ACC_PROT_RW_ns_scpu_acc_prot_rw_mask                            (0x00000001)
#define WRAP_NS_SCPU_ACC_PROT_RW_ns_scpu_acc_prot_rw(data)                           (0x00000001&((data)<<0))
#define WRAP_NS_SCPU_ACC_PROT_RW_ns_scpu_acc_prot_rw_src(data)                       ((0x00000001&(data))>>0)
#define WRAP_NS_SCPU_ACC_PROT_RW_get_ns_scpu_acc_prot_rw(data)                       ((0x00000001&(data))>>0)


#define WRAP_CONTENT_PROT_EN                                                         0x1805C86C
#define WRAP_CONTENT_PROT_EN_reg_addr                                                "0xB805C86C"
#define WRAP_CONTENT_PROT_EN_reg                                                     0xB805C86C
#define set_WRAP_CONTENT_PROT_EN_reg(data)   (*((volatile unsigned int*) WRAP_CONTENT_PROT_EN_reg)=data)
#define get_WRAP_CONTENT_PROT_EN_reg   (*((volatile unsigned int*) WRAP_CONTENT_PROT_EN_reg))
#define WRAP_CONTENT_PROT_EN_inst_adr                                                "0x001B"
#define WRAP_CONTENT_PROT_EN_inst                                                    0x001B
#define WRAP_CONTENT_PROT_EN_ns_scpu_acc_cont_wr_en_shift                            (24)
#define WRAP_CONTENT_PROT_EN_ns_scpu_acc_cont_wr_en_mask                             (0x01000000)
#define WRAP_CONTENT_PROT_EN_ns_scpu_acc_cont_wr_en(data)                            (0x01000000&((data)<<24))
#define WRAP_CONTENT_PROT_EN_ns_scpu_acc_cont_wr_en_src(data)                        ((0x01000000&(data))>>24)
#define WRAP_CONTENT_PROT_EN_get_ns_scpu_acc_cont_wr_en(data)                        ((0x01000000&(data))>>24)
#define WRAP_CONTENT_PROT_EN_ns_scpu_acc_cont_rd_en_shift                            (16)
#define WRAP_CONTENT_PROT_EN_ns_scpu_acc_cont_rd_en_mask                             (0x00010000)
#define WRAP_CONTENT_PROT_EN_ns_scpu_acc_cont_rd_en(data)                            (0x00010000&((data)<<16))
#define WRAP_CONTENT_PROT_EN_ns_scpu_acc_cont_rd_en_src(data)                        ((0x00010000&(data))>>16)
#define WRAP_CONTENT_PROT_EN_get_ns_scpu_acc_cont_rd_en(data)                        ((0x00010000&(data))>>16)
#define WRAP_CONTENT_PROT_EN_content_prot_en7_shift                                  (7)
#define WRAP_CONTENT_PROT_EN_content_prot_en7_mask                                   (0x00000080)
#define WRAP_CONTENT_PROT_EN_content_prot_en7(data)                                  (0x00000080&((data)<<7))
#define WRAP_CONTENT_PROT_EN_content_prot_en7_src(data)                              ((0x00000080&(data))>>7)
#define WRAP_CONTENT_PROT_EN_get_content_prot_en7(data)                              ((0x00000080&(data))>>7)
#define WRAP_CONTENT_PROT_EN_content_prot_en6_shift                                  (6)
#define WRAP_CONTENT_PROT_EN_content_prot_en6_mask                                   (0x00000040)
#define WRAP_CONTENT_PROT_EN_content_prot_en6(data)                                  (0x00000040&((data)<<6))
#define WRAP_CONTENT_PROT_EN_content_prot_en6_src(data)                              ((0x00000040&(data))>>6)
#define WRAP_CONTENT_PROT_EN_get_content_prot_en6(data)                              ((0x00000040&(data))>>6)
#define WRAP_CONTENT_PROT_EN_content_prot_en5_shift                                  (5)
#define WRAP_CONTENT_PROT_EN_content_prot_en5_mask                                   (0x00000020)
#define WRAP_CONTENT_PROT_EN_content_prot_en5(data)                                  (0x00000020&((data)<<5))
#define WRAP_CONTENT_PROT_EN_content_prot_en5_src(data)                              ((0x00000020&(data))>>5)
#define WRAP_CONTENT_PROT_EN_get_content_prot_en5(data)                              ((0x00000020&(data))>>5)
#define WRAP_CONTENT_PROT_EN_content_prot_en4_shift                                  (4)
#define WRAP_CONTENT_PROT_EN_content_prot_en4_mask                                   (0x00000010)
#define WRAP_CONTENT_PROT_EN_content_prot_en4(data)                                  (0x00000010&((data)<<4))
#define WRAP_CONTENT_PROT_EN_content_prot_en4_src(data)                              ((0x00000010&(data))>>4)
#define WRAP_CONTENT_PROT_EN_get_content_prot_en4(data)                              ((0x00000010&(data))>>4)
#define WRAP_CONTENT_PROT_EN_content_prot_en3_shift                                  (3)
#define WRAP_CONTENT_PROT_EN_content_prot_en3_mask                                   (0x00000008)
#define WRAP_CONTENT_PROT_EN_content_prot_en3(data)                                  (0x00000008&((data)<<3))
#define WRAP_CONTENT_PROT_EN_content_prot_en3_src(data)                              ((0x00000008&(data))>>3)
#define WRAP_CONTENT_PROT_EN_get_content_prot_en3(data)                              ((0x00000008&(data))>>3)
#define WRAP_CONTENT_PROT_EN_content_prot_en2_shift                                  (2)
#define WRAP_CONTENT_PROT_EN_content_prot_en2_mask                                   (0x00000004)
#define WRAP_CONTENT_PROT_EN_content_prot_en2(data)                                  (0x00000004&((data)<<2))
#define WRAP_CONTENT_PROT_EN_content_prot_en2_src(data)                              ((0x00000004&(data))>>2)
#define WRAP_CONTENT_PROT_EN_get_content_prot_en2(data)                              ((0x00000004&(data))>>2)
#define WRAP_CONTENT_PROT_EN_content_prot_en1_shift                                  (1)
#define WRAP_CONTENT_PROT_EN_content_prot_en1_mask                                   (0x00000002)
#define WRAP_CONTENT_PROT_EN_content_prot_en1(data)                                  (0x00000002&((data)<<1))
#define WRAP_CONTENT_PROT_EN_content_prot_en1_src(data)                              ((0x00000002&(data))>>1)
#define WRAP_CONTENT_PROT_EN_get_content_prot_en1(data)                              ((0x00000002&(data))>>1)
#define WRAP_CONTENT_PROT_EN_content_prot_en0_shift                                  (0)
#define WRAP_CONTENT_PROT_EN_content_prot_en0_mask                                   (0x00000001)
#define WRAP_CONTENT_PROT_EN_content_prot_en0(data)                                  (0x00000001&((data)<<0))
#define WRAP_CONTENT_PROT_EN_content_prot_en0_src(data)                              ((0x00000001&(data))>>0)
#define WRAP_CONTENT_PROT_EN_get_content_prot_en0(data)                              ((0x00000001&(data))>>0)


#define WRAP_CONTENT_PROTECT_SADDR0                                                  0x1805C870
#define WRAP_CONTENT_PROTECT_SADDR0_reg_addr                                         "0xB805C870"
#define WRAP_CONTENT_PROTECT_SADDR0_reg                                              0xB805C870
#define set_WRAP_CONTENT_PROTECT_SADDR0_reg(data)   (*((volatile unsigned int*) WRAP_CONTENT_PROTECT_SADDR0_reg)=data)
#define get_WRAP_CONTENT_PROTECT_SADDR0_reg   (*((volatile unsigned int*) WRAP_CONTENT_PROTECT_SADDR0_reg))
#define WRAP_CONTENT_PROTECT_SADDR0_inst_adr                                         "0x001C"
#define WRAP_CONTENT_PROTECT_SADDR0_inst                                             0x001C
#define WRAP_CONTENT_PROTECT_SADDR0_content_prot_saddr0_shift                        (12)
#define WRAP_CONTENT_PROTECT_SADDR0_content_prot_saddr0_mask                         (0xFFFFF000)
#define WRAP_CONTENT_PROTECT_SADDR0_content_prot_saddr0(data)                        (0xFFFFF000&((data)<<12))
#define WRAP_CONTENT_PROTECT_SADDR0_content_prot_saddr0_src(data)                    ((0xFFFFF000&(data))>>12)
#define WRAP_CONTENT_PROTECT_SADDR0_get_content_prot_saddr0(data)                    ((0xFFFFF000&(data))>>12)


#define WRAP_CONTENT_PROTECT_EADDR0                                                  0x1805C874
#define WRAP_CONTENT_PROTECT_EADDR0_reg_addr                                         "0xB805C874"
#define WRAP_CONTENT_PROTECT_EADDR0_reg                                              0xB805C874
#define set_WRAP_CONTENT_PROTECT_EADDR0_reg(data)   (*((volatile unsigned int*) WRAP_CONTENT_PROTECT_EADDR0_reg)=data)
#define get_WRAP_CONTENT_PROTECT_EADDR0_reg   (*((volatile unsigned int*) WRAP_CONTENT_PROTECT_EADDR0_reg))
#define WRAP_CONTENT_PROTECT_EADDR0_inst_adr                                         "0x001D"
#define WRAP_CONTENT_PROTECT_EADDR0_inst                                             0x001D
#define WRAP_CONTENT_PROTECT_EADDR0_content_prot_eaddr0_shift                        (12)
#define WRAP_CONTENT_PROTECT_EADDR0_content_prot_eaddr0_mask                         (0xFFFFF000)
#define WRAP_CONTENT_PROTECT_EADDR0_content_prot_eaddr0(data)                        (0xFFFFF000&((data)<<12))
#define WRAP_CONTENT_PROTECT_EADDR0_content_prot_eaddr0_src(data)                    ((0xFFFFF000&(data))>>12)
#define WRAP_CONTENT_PROTECT_EADDR0_get_content_prot_eaddr0(data)                    ((0xFFFFF000&(data))>>12)


#define WRAP_CONTENT_PROTECT_SADDR1                                                  0x1805C878
#define WRAP_CONTENT_PROTECT_SADDR1_reg_addr                                         "0xB805C878"
#define WRAP_CONTENT_PROTECT_SADDR1_reg                                              0xB805C878
#define set_WRAP_CONTENT_PROTECT_SADDR1_reg(data)   (*((volatile unsigned int*) WRAP_CONTENT_PROTECT_SADDR1_reg)=data)
#define get_WRAP_CONTENT_PROTECT_SADDR1_reg   (*((volatile unsigned int*) WRAP_CONTENT_PROTECT_SADDR1_reg))
#define WRAP_CONTENT_PROTECT_SADDR1_inst_adr                                         "0x001E"
#define WRAP_CONTENT_PROTECT_SADDR1_inst                                             0x001E
#define WRAP_CONTENT_PROTECT_SADDR1_content_prot_saddr1_shift                        (12)
#define WRAP_CONTENT_PROTECT_SADDR1_content_prot_saddr1_mask                         (0xFFFFF000)
#define WRAP_CONTENT_PROTECT_SADDR1_content_prot_saddr1(data)                        (0xFFFFF000&((data)<<12))
#define WRAP_CONTENT_PROTECT_SADDR1_content_prot_saddr1_src(data)                    ((0xFFFFF000&(data))>>12)
#define WRAP_CONTENT_PROTECT_SADDR1_get_content_prot_saddr1(data)                    ((0xFFFFF000&(data))>>12)


#define WRAP_CONTENT_PROTECT_EADDR1                                                  0x1805C87C
#define WRAP_CONTENT_PROTECT_EADDR1_reg_addr                                         "0xB805C87C"
#define WRAP_CONTENT_PROTECT_EADDR1_reg                                              0xB805C87C
#define set_WRAP_CONTENT_PROTECT_EADDR1_reg(data)   (*((volatile unsigned int*) WRAP_CONTENT_PROTECT_EADDR1_reg)=data)
#define get_WRAP_CONTENT_PROTECT_EADDR1_reg   (*((volatile unsigned int*) WRAP_CONTENT_PROTECT_EADDR1_reg))
#define WRAP_CONTENT_PROTECT_EADDR1_inst_adr                                         "0x001F"
#define WRAP_CONTENT_PROTECT_EADDR1_inst                                             0x001F
#define WRAP_CONTENT_PROTECT_EADDR1_content_prot_eaddr1_shift                        (12)
#define WRAP_CONTENT_PROTECT_EADDR1_content_prot_eaddr1_mask                         (0xFFFFF000)
#define WRAP_CONTENT_PROTECT_EADDR1_content_prot_eaddr1(data)                        (0xFFFFF000&((data)<<12))
#define WRAP_CONTENT_PROTECT_EADDR1_content_prot_eaddr1_src(data)                    ((0xFFFFF000&(data))>>12)
#define WRAP_CONTENT_PROTECT_EADDR1_get_content_prot_eaddr1(data)                    ((0xFFFFF000&(data))>>12)


#define WRAP_CONTENT_PROTECT_SADDR2                                                  0x1805C880
#define WRAP_CONTENT_PROTECT_SADDR2_reg_addr                                         "0xB805C880"
#define WRAP_CONTENT_PROTECT_SADDR2_reg                                              0xB805C880
#define set_WRAP_CONTENT_PROTECT_SADDR2_reg(data)   (*((volatile unsigned int*) WRAP_CONTENT_PROTECT_SADDR2_reg)=data)
#define get_WRAP_CONTENT_PROTECT_SADDR2_reg   (*((volatile unsigned int*) WRAP_CONTENT_PROTECT_SADDR2_reg))
#define WRAP_CONTENT_PROTECT_SADDR2_inst_adr                                         "0x0020"
#define WRAP_CONTENT_PROTECT_SADDR2_inst                                             0x0020
#define WRAP_CONTENT_PROTECT_SADDR2_content_prot_saddr2_shift                        (12)
#define WRAP_CONTENT_PROTECT_SADDR2_content_prot_saddr2_mask                         (0xFFFFF000)
#define WRAP_CONTENT_PROTECT_SADDR2_content_prot_saddr2(data)                        (0xFFFFF000&((data)<<12))
#define WRAP_CONTENT_PROTECT_SADDR2_content_prot_saddr2_src(data)                    ((0xFFFFF000&(data))>>12)
#define WRAP_CONTENT_PROTECT_SADDR2_get_content_prot_saddr2(data)                    ((0xFFFFF000&(data))>>12)


#define WRAP_CONTENT_PROTECT_EADDR2                                                  0x1805C884
#define WRAP_CONTENT_PROTECT_EADDR2_reg_addr                                         "0xB805C884"
#define WRAP_CONTENT_PROTECT_EADDR2_reg                                              0xB805C884
#define set_WRAP_CONTENT_PROTECT_EADDR2_reg(data)   (*((volatile unsigned int*) WRAP_CONTENT_PROTECT_EADDR2_reg)=data)
#define get_WRAP_CONTENT_PROTECT_EADDR2_reg   (*((volatile unsigned int*) WRAP_CONTENT_PROTECT_EADDR2_reg))
#define WRAP_CONTENT_PROTECT_EADDR2_inst_adr                                         "0x0021"
#define WRAP_CONTENT_PROTECT_EADDR2_inst                                             0x0021
#define WRAP_CONTENT_PROTECT_EADDR2_content_prot_eaddr2_shift                        (12)
#define WRAP_CONTENT_PROTECT_EADDR2_content_prot_eaddr2_mask                         (0xFFFFF000)
#define WRAP_CONTENT_PROTECT_EADDR2_content_prot_eaddr2(data)                        (0xFFFFF000&((data)<<12))
#define WRAP_CONTENT_PROTECT_EADDR2_content_prot_eaddr2_src(data)                    ((0xFFFFF000&(data))>>12)
#define WRAP_CONTENT_PROTECT_EADDR2_get_content_prot_eaddr2(data)                    ((0xFFFFF000&(data))>>12)


#define WRAP_CONTENT_PROTECT_SADDR3                                                  0x1805C888
#define WRAP_CONTENT_PROTECT_SADDR3_reg_addr                                         "0xB805C888"
#define WRAP_CONTENT_PROTECT_SADDR3_reg                                              0xB805C888
#define set_WRAP_CONTENT_PROTECT_SADDR3_reg(data)   (*((volatile unsigned int*) WRAP_CONTENT_PROTECT_SADDR3_reg)=data)
#define get_WRAP_CONTENT_PROTECT_SADDR3_reg   (*((volatile unsigned int*) WRAP_CONTENT_PROTECT_SADDR3_reg))
#define WRAP_CONTENT_PROTECT_SADDR3_inst_adr                                         "0x0022"
#define WRAP_CONTENT_PROTECT_SADDR3_inst                                             0x0022
#define WRAP_CONTENT_PROTECT_SADDR3_content_prot_saddr3_shift                        (12)
#define WRAP_CONTENT_PROTECT_SADDR3_content_prot_saddr3_mask                         (0xFFFFF000)
#define WRAP_CONTENT_PROTECT_SADDR3_content_prot_saddr3(data)                        (0xFFFFF000&((data)<<12))
#define WRAP_CONTENT_PROTECT_SADDR3_content_prot_saddr3_src(data)                    ((0xFFFFF000&(data))>>12)
#define WRAP_CONTENT_PROTECT_SADDR3_get_content_prot_saddr3(data)                    ((0xFFFFF000&(data))>>12)


#define WRAP_CONTENT_PROTECT_EADDR3                                                  0x1805C88C
#define WRAP_CONTENT_PROTECT_EADDR3_reg_addr                                         "0xB805C88C"
#define WRAP_CONTENT_PROTECT_EADDR3_reg                                              0xB805C88C
#define set_WRAP_CONTENT_PROTECT_EADDR3_reg(data)   (*((volatile unsigned int*) WRAP_CONTENT_PROTECT_EADDR3_reg)=data)
#define get_WRAP_CONTENT_PROTECT_EADDR3_reg   (*((volatile unsigned int*) WRAP_CONTENT_PROTECT_EADDR3_reg))
#define WRAP_CONTENT_PROTECT_EADDR3_inst_adr                                         "0x0023"
#define WRAP_CONTENT_PROTECT_EADDR3_inst                                             0x0023
#define WRAP_CONTENT_PROTECT_EADDR3_content_prot_eaddr3_shift                        (12)
#define WRAP_CONTENT_PROTECT_EADDR3_content_prot_eaddr3_mask                         (0xFFFFF000)
#define WRAP_CONTENT_PROTECT_EADDR3_content_prot_eaddr3(data)                        (0xFFFFF000&((data)<<12))
#define WRAP_CONTENT_PROTECT_EADDR3_content_prot_eaddr3_src(data)                    ((0xFFFFF000&(data))>>12)
#define WRAP_CONTENT_PROTECT_EADDR3_get_content_prot_eaddr3(data)                    ((0xFFFFF000&(data))>>12)


#define WRAP_CONTENT_PROTECT_SADDR4                                                  0x1805C890
#define WRAP_CONTENT_PROTECT_SADDR4_reg_addr                                         "0xB805C890"
#define WRAP_CONTENT_PROTECT_SADDR4_reg                                              0xB805C890
#define set_WRAP_CONTENT_PROTECT_SADDR4_reg(data)   (*((volatile unsigned int*) WRAP_CONTENT_PROTECT_SADDR4_reg)=data)
#define get_WRAP_CONTENT_PROTECT_SADDR4_reg   (*((volatile unsigned int*) WRAP_CONTENT_PROTECT_SADDR4_reg))
#define WRAP_CONTENT_PROTECT_SADDR4_inst_adr                                         "0x0024"
#define WRAP_CONTENT_PROTECT_SADDR4_inst                                             0x0024
#define WRAP_CONTENT_PROTECT_SADDR4_content_prot_saddr4_shift                        (12)
#define WRAP_CONTENT_PROTECT_SADDR4_content_prot_saddr4_mask                         (0xFFFFF000)
#define WRAP_CONTENT_PROTECT_SADDR4_content_prot_saddr4(data)                        (0xFFFFF000&((data)<<12))
#define WRAP_CONTENT_PROTECT_SADDR4_content_prot_saddr4_src(data)                    ((0xFFFFF000&(data))>>12)
#define WRAP_CONTENT_PROTECT_SADDR4_get_content_prot_saddr4(data)                    ((0xFFFFF000&(data))>>12)


#define WRAP_CONTENT_PROTECT_EADDR4                                                  0x1805C894
#define WRAP_CONTENT_PROTECT_EADDR4_reg_addr                                         "0xB805C894"
#define WRAP_CONTENT_PROTECT_EADDR4_reg                                              0xB805C894
#define set_WRAP_CONTENT_PROTECT_EADDR4_reg(data)   (*((volatile unsigned int*) WRAP_CONTENT_PROTECT_EADDR4_reg)=data)
#define get_WRAP_CONTENT_PROTECT_EADDR4_reg   (*((volatile unsigned int*) WRAP_CONTENT_PROTECT_EADDR4_reg))
#define WRAP_CONTENT_PROTECT_EADDR4_inst_adr                                         "0x0025"
#define WRAP_CONTENT_PROTECT_EADDR4_inst                                             0x0025
#define WRAP_CONTENT_PROTECT_EADDR4_content_prot_eaddr4_shift                        (12)
#define WRAP_CONTENT_PROTECT_EADDR4_content_prot_eaddr4_mask                         (0xFFFFF000)
#define WRAP_CONTENT_PROTECT_EADDR4_content_prot_eaddr4(data)                        (0xFFFFF000&((data)<<12))
#define WRAP_CONTENT_PROTECT_EADDR4_content_prot_eaddr4_src(data)                    ((0xFFFFF000&(data))>>12)
#define WRAP_CONTENT_PROTECT_EADDR4_get_content_prot_eaddr4(data)                    ((0xFFFFF000&(data))>>12)


#define WRAP_CONTENT_PROTECT_SADDR5                                                  0x1805C898
#define WRAP_CONTENT_PROTECT_SADDR5_reg_addr                                         "0xB805C898"
#define WRAP_CONTENT_PROTECT_SADDR5_reg                                              0xB805C898
#define set_WRAP_CONTENT_PROTECT_SADDR5_reg(data)   (*((volatile unsigned int*) WRAP_CONTENT_PROTECT_SADDR5_reg)=data)
#define get_WRAP_CONTENT_PROTECT_SADDR5_reg   (*((volatile unsigned int*) WRAP_CONTENT_PROTECT_SADDR5_reg))
#define WRAP_CONTENT_PROTECT_SADDR5_inst_adr                                         "0x0026"
#define WRAP_CONTENT_PROTECT_SADDR5_inst                                             0x0026
#define WRAP_CONTENT_PROTECT_SADDR5_content_prot_saddr5_shift                        (12)
#define WRAP_CONTENT_PROTECT_SADDR5_content_prot_saddr5_mask                         (0xFFFFF000)
#define WRAP_CONTENT_PROTECT_SADDR5_content_prot_saddr5(data)                        (0xFFFFF000&((data)<<12))
#define WRAP_CONTENT_PROTECT_SADDR5_content_prot_saddr5_src(data)                    ((0xFFFFF000&(data))>>12)
#define WRAP_CONTENT_PROTECT_SADDR5_get_content_prot_saddr5(data)                    ((0xFFFFF000&(data))>>12)


#define WRAP_CONTENT_PROTECT_EADDR5                                                  0x1805C89C
#define WRAP_CONTENT_PROTECT_EADDR5_reg_addr                                         "0xB805C89C"
#define WRAP_CONTENT_PROTECT_EADDR5_reg                                              0xB805C89C
#define set_WRAP_CONTENT_PROTECT_EADDR5_reg(data)   (*((volatile unsigned int*) WRAP_CONTENT_PROTECT_EADDR5_reg)=data)
#define get_WRAP_CONTENT_PROTECT_EADDR5_reg   (*((volatile unsigned int*) WRAP_CONTENT_PROTECT_EADDR5_reg))
#define WRAP_CONTENT_PROTECT_EADDR5_inst_adr                                         "0x0027"
#define WRAP_CONTENT_PROTECT_EADDR5_inst                                             0x0027
#define WRAP_CONTENT_PROTECT_EADDR5_content_prot_eaddr5_shift                        (12)
#define WRAP_CONTENT_PROTECT_EADDR5_content_prot_eaddr5_mask                         (0xFFFFF000)
#define WRAP_CONTENT_PROTECT_EADDR5_content_prot_eaddr5(data)                        (0xFFFFF000&((data)<<12))
#define WRAP_CONTENT_PROTECT_EADDR5_content_prot_eaddr5_src(data)                    ((0xFFFFF000&(data))>>12)
#define WRAP_CONTENT_PROTECT_EADDR5_get_content_prot_eaddr5(data)                    ((0xFFFFF000&(data))>>12)


#define WRAP_CONTENT_PROTECT_SADDR6                                                  0x1805C8A0
#define WRAP_CONTENT_PROTECT_SADDR6_reg_addr                                         "0xB805C8A0"
#define WRAP_CONTENT_PROTECT_SADDR6_reg                                              0xB805C8A0
#define set_WRAP_CONTENT_PROTECT_SADDR6_reg(data)   (*((volatile unsigned int*) WRAP_CONTENT_PROTECT_SADDR6_reg)=data)
#define get_WRAP_CONTENT_PROTECT_SADDR6_reg   (*((volatile unsigned int*) WRAP_CONTENT_PROTECT_SADDR6_reg))
#define WRAP_CONTENT_PROTECT_SADDR6_inst_adr                                         "0x0028"
#define WRAP_CONTENT_PROTECT_SADDR6_inst                                             0x0028
#define WRAP_CONTENT_PROTECT_SADDR6_content_prot_saddr6_shift                        (12)
#define WRAP_CONTENT_PROTECT_SADDR6_content_prot_saddr6_mask                         (0xFFFFF000)
#define WRAP_CONTENT_PROTECT_SADDR6_content_prot_saddr6(data)                        (0xFFFFF000&((data)<<12))
#define WRAP_CONTENT_PROTECT_SADDR6_content_prot_saddr6_src(data)                    ((0xFFFFF000&(data))>>12)
#define WRAP_CONTENT_PROTECT_SADDR6_get_content_prot_saddr6(data)                    ((0xFFFFF000&(data))>>12)


#define WRAP_CONTENT_PROTECT_EADDR6                                                  0x1805C8A4
#define WRAP_CONTENT_PROTECT_EADDR6_reg_addr                                         "0xB805C8A4"
#define WRAP_CONTENT_PROTECT_EADDR6_reg                                              0xB805C8A4
#define set_WRAP_CONTENT_PROTECT_EADDR6_reg(data)   (*((volatile unsigned int*) WRAP_CONTENT_PROTECT_EADDR6_reg)=data)
#define get_WRAP_CONTENT_PROTECT_EADDR6_reg   (*((volatile unsigned int*) WRAP_CONTENT_PROTECT_EADDR6_reg))
#define WRAP_CONTENT_PROTECT_EADDR6_inst_adr                                         "0x0029"
#define WRAP_CONTENT_PROTECT_EADDR6_inst                                             0x0029
#define WRAP_CONTENT_PROTECT_EADDR6_content_prot_eaddr6_shift                        (12)
#define WRAP_CONTENT_PROTECT_EADDR6_content_prot_eaddr6_mask                         (0xFFFFF000)
#define WRAP_CONTENT_PROTECT_EADDR6_content_prot_eaddr6(data)                        (0xFFFFF000&((data)<<12))
#define WRAP_CONTENT_PROTECT_EADDR6_content_prot_eaddr6_src(data)                    ((0xFFFFF000&(data))>>12)
#define WRAP_CONTENT_PROTECT_EADDR6_get_content_prot_eaddr6(data)                    ((0xFFFFF000&(data))>>12)


#define WRAP_CONTENT_PROTECT_SADDR7                                                  0x1805C8A8
#define WRAP_CONTENT_PROTECT_SADDR7_reg_addr                                         "0xB805C8A8"
#define WRAP_CONTENT_PROTECT_SADDR7_reg                                              0xB805C8A8
#define set_WRAP_CONTENT_PROTECT_SADDR7_reg(data)   (*((volatile unsigned int*) WRAP_CONTENT_PROTECT_SADDR7_reg)=data)
#define get_WRAP_CONTENT_PROTECT_SADDR7_reg   (*((volatile unsigned int*) WRAP_CONTENT_PROTECT_SADDR7_reg))
#define WRAP_CONTENT_PROTECT_SADDR7_inst_adr                                         "0x002A"
#define WRAP_CONTENT_PROTECT_SADDR7_inst                                             0x002A
#define WRAP_CONTENT_PROTECT_SADDR7_content_prot_saddr7_shift                        (12)
#define WRAP_CONTENT_PROTECT_SADDR7_content_prot_saddr7_mask                         (0xFFFFF000)
#define WRAP_CONTENT_PROTECT_SADDR7_content_prot_saddr7(data)                        (0xFFFFF000&((data)<<12))
#define WRAP_CONTENT_PROTECT_SADDR7_content_prot_saddr7_src(data)                    ((0xFFFFF000&(data))>>12)
#define WRAP_CONTENT_PROTECT_SADDR7_get_content_prot_saddr7(data)                    ((0xFFFFF000&(data))>>12)


#define WRAP_CONTENT_PROTECT_EADDR7                                                  0x1805C8AC
#define WRAP_CONTENT_PROTECT_EADDR7_reg_addr                                         "0xB805C8AC"
#define WRAP_CONTENT_PROTECT_EADDR7_reg                                              0xB805C8AC
#define set_WRAP_CONTENT_PROTECT_EADDR7_reg(data)   (*((volatile unsigned int*) WRAP_CONTENT_PROTECT_EADDR7_reg)=data)
#define get_WRAP_CONTENT_PROTECT_EADDR7_reg   (*((volatile unsigned int*) WRAP_CONTENT_PROTECT_EADDR7_reg))
#define WRAP_CONTENT_PROTECT_EADDR7_inst_adr                                         "0x002B"
#define WRAP_CONTENT_PROTECT_EADDR7_inst                                             0x002B
#define WRAP_CONTENT_PROTECT_EADDR7_content_prot_eaddr7_shift                        (12)
#define WRAP_CONTENT_PROTECT_EADDR7_content_prot_eaddr7_mask                         (0xFFFFF000)
#define WRAP_CONTENT_PROTECT_EADDR7_content_prot_eaddr7(data)                        (0xFFFFF000&((data)<<12))
#define WRAP_CONTENT_PROTECT_EADDR7_content_prot_eaddr7_src(data)                    ((0xFFFFF000&(data))>>12)
#define WRAP_CONTENT_PROTECT_EADDR7_get_content_prot_eaddr7(data)                    ((0xFFFFF000&(data))>>12)


#define WRAP_NS_SCPU_ACC_CONT_PROT_INT                                               0x1805C8B0
#define WRAP_NS_SCPU_ACC_CONT_PROT_INT_reg_addr                                      "0xB805C8B0"
#define WRAP_NS_SCPU_ACC_CONT_PROT_INT_reg                                           0xB805C8B0
#define set_WRAP_NS_SCPU_ACC_CONT_PROT_INT_reg(data)   (*((volatile unsigned int*) WRAP_NS_SCPU_ACC_CONT_PROT_INT_reg)=data)
#define get_WRAP_NS_SCPU_ACC_CONT_PROT_INT_reg   (*((volatile unsigned int*) WRAP_NS_SCPU_ACC_CONT_PROT_INT_reg))
#define WRAP_NS_SCPU_ACC_CONT_PROT_INT_inst_adr                                      "0x002C"
#define WRAP_NS_SCPU_ACC_CONT_PROT_INT_inst                                          0x002C
#define WRAP_NS_SCPU_ACC_CONT_PROT_INT_ns_scpu_acc_cont_prot_int_shift               (1)
#define WRAP_NS_SCPU_ACC_CONT_PROT_INT_ns_scpu_acc_cont_prot_int_mask                (0x00000002)
#define WRAP_NS_SCPU_ACC_CONT_PROT_INT_ns_scpu_acc_cont_prot_int(data)               (0x00000002&((data)<<1))
#define WRAP_NS_SCPU_ACC_CONT_PROT_INT_ns_scpu_acc_cont_prot_int_src(data)           ((0x00000002&(data))>>1)
#define WRAP_NS_SCPU_ACC_CONT_PROT_INT_get_ns_scpu_acc_cont_prot_int(data)           ((0x00000002&(data))>>1)
#define WRAP_NS_SCPU_ACC_CONT_PROT_INT_ns_scpu_acc_cont_prot_int_en_shift            (0)
#define WRAP_NS_SCPU_ACC_CONT_PROT_INT_ns_scpu_acc_cont_prot_int_en_mask             (0x00000001)
#define WRAP_NS_SCPU_ACC_CONT_PROT_INT_ns_scpu_acc_cont_prot_int_en(data)            (0x00000001&((data)<<0))
#define WRAP_NS_SCPU_ACC_CONT_PROT_INT_ns_scpu_acc_cont_prot_int_en_src(data)        ((0x00000001&(data))>>0)
#define WRAP_NS_SCPU_ACC_CONT_PROT_INT_get_ns_scpu_acc_cont_prot_int_en(data)        ((0x00000001&(data))>>0)


#define WRAP_NS_SCPU_ACC_CONT_PROT_ADDR                                              0x1805C8B4
#define WRAP_NS_SCPU_ACC_CONT_PROT_ADDR_reg_addr                                     "0xB805C8B4"
#define WRAP_NS_SCPU_ACC_CONT_PROT_ADDR_reg                                          0xB805C8B4
#define set_WRAP_NS_SCPU_ACC_CONT_PROT_ADDR_reg(data)   (*((volatile unsigned int*) WRAP_NS_SCPU_ACC_CONT_PROT_ADDR_reg)=data)
#define get_WRAP_NS_SCPU_ACC_CONT_PROT_ADDR_reg   (*((volatile unsigned int*) WRAP_NS_SCPU_ACC_CONT_PROT_ADDR_reg))
#define WRAP_NS_SCPU_ACC_CONT_PROT_ADDR_inst_adr                                     "0x002D"
#define WRAP_NS_SCPU_ACC_CONT_PROT_ADDR_inst                                         0x002D
#define WRAP_NS_SCPU_ACC_CONT_PROT_ADDR_ns_scpu_acc_cont_prot_addr_shift             (0)
#define WRAP_NS_SCPU_ACC_CONT_PROT_ADDR_ns_scpu_acc_cont_prot_addr_mask              (0xFFFFFFFF)
#define WRAP_NS_SCPU_ACC_CONT_PROT_ADDR_ns_scpu_acc_cont_prot_addr(data)             (0xFFFFFFFF&((data)<<0))
#define WRAP_NS_SCPU_ACC_CONT_PROT_ADDR_ns_scpu_acc_cont_prot_addr_src(data)         ((0xFFFFFFFF&(data))>>0)
#define WRAP_NS_SCPU_ACC_CONT_PROT_ADDR_get_ns_scpu_acc_cont_prot_addr(data)         ((0xFFFFFFFF&(data))>>0)


#define WRAP_NS_SCPU_ACC_CONT_PROT_RW                                                0x1805C8B8
#define WRAP_NS_SCPU_ACC_CONT_PROT_RW_reg_addr                                       "0xB805C8B8"
#define WRAP_NS_SCPU_ACC_CONT_PROT_RW_reg                                            0xB805C8B8
#define set_WRAP_NS_SCPU_ACC_CONT_PROT_RW_reg(data)   (*((volatile unsigned int*) WRAP_NS_SCPU_ACC_CONT_PROT_RW_reg)=data)
#define get_WRAP_NS_SCPU_ACC_CONT_PROT_RW_reg   (*((volatile unsigned int*) WRAP_NS_SCPU_ACC_CONT_PROT_RW_reg))
#define WRAP_NS_SCPU_ACC_CONT_PROT_RW_inst_adr                                       "0x002E"
#define WRAP_NS_SCPU_ACC_CONT_PROT_RW_inst                                           0x002E
#define WRAP_NS_SCPU_ACC_CONT_PROT_RW_ns_scpu_acc_cont_prot_rw_shift                 (0)
#define WRAP_NS_SCPU_ACC_CONT_PROT_RW_ns_scpu_acc_cont_prot_rw_mask                  (0x00000001)
#define WRAP_NS_SCPU_ACC_CONT_PROT_RW_ns_scpu_acc_cont_prot_rw(data)                 (0x00000001&((data)<<0))
#define WRAP_NS_SCPU_ACC_CONT_PROT_RW_ns_scpu_acc_cont_prot_rw_src(data)             ((0x00000001&(data))>>0)
#define WRAP_NS_SCPU_ACC_CONT_PROT_RW_get_ns_scpu_acc_cont_prot_rw(data)             ((0x00000001&(data))>>0)


#define WRAP_DISPLAY_PROT_EN                                                         0x1805C8BC
#define WRAP_DISPLAY_PROT_EN_reg_addr                                                "0xB805C8BC"
#define WRAP_DISPLAY_PROT_EN_reg                                                     0xB805C8BC
#define set_WRAP_DISPLAY_PROT_EN_reg(data)   (*((volatile unsigned int*) WRAP_DISPLAY_PROT_EN_reg)=data)
#define get_WRAP_DISPLAY_PROT_EN_reg   (*((volatile unsigned int*) WRAP_DISPLAY_PROT_EN_reg))
#define WRAP_DISPLAY_PROT_EN_inst_adr                                                "0x002F"
#define WRAP_DISPLAY_PROT_EN_inst                                                    0x002F
#define WRAP_DISPLAY_PROT_EN_display_prot_en1_shift                                  (1)
#define WRAP_DISPLAY_PROT_EN_display_prot_en1_mask                                   (0x00000002)
#define WRAP_DISPLAY_PROT_EN_display_prot_en1(data)                                  (0x00000002&((data)<<1))
#define WRAP_DISPLAY_PROT_EN_display_prot_en1_src(data)                              ((0x00000002&(data))>>1)
#define WRAP_DISPLAY_PROT_EN_get_display_prot_en1(data)                              ((0x00000002&(data))>>1)
#define WRAP_DISPLAY_PROT_EN_display_prot_en0_shift                                  (0)
#define WRAP_DISPLAY_PROT_EN_display_prot_en0_mask                                   (0x00000001)
#define WRAP_DISPLAY_PROT_EN_display_prot_en0(data)                                  (0x00000001&((data)<<0))
#define WRAP_DISPLAY_PROT_EN_display_prot_en0_src(data)                              ((0x00000001&(data))>>0)
#define WRAP_DISPLAY_PROT_EN_get_display_prot_en0(data)                              ((0x00000001&(data))>>0)


#define WRAP_DISPLAY_PROTECT_SADDR0                                                  0x1805C8C0
#define WRAP_DISPLAY_PROTECT_SADDR0_reg_addr                                         "0xB805C8C0"
#define WRAP_DISPLAY_PROTECT_SADDR0_reg                                              0xB805C8C0
#define set_WRAP_DISPLAY_PROTECT_SADDR0_reg(data)   (*((volatile unsigned int*) WRAP_DISPLAY_PROTECT_SADDR0_reg)=data)
#define get_WRAP_DISPLAY_PROTECT_SADDR0_reg   (*((volatile unsigned int*) WRAP_DISPLAY_PROTECT_SADDR0_reg))
#define WRAP_DISPLAY_PROTECT_SADDR0_inst_adr                                         "0x0030"
#define WRAP_DISPLAY_PROTECT_SADDR0_inst                                             0x0030
#define WRAP_DISPLAY_PROTECT_SADDR0_display_prot_saddr0_shift                        (12)
#define WRAP_DISPLAY_PROTECT_SADDR0_display_prot_saddr0_mask                         (0xFFFFF000)
#define WRAP_DISPLAY_PROTECT_SADDR0_display_prot_saddr0(data)                        (0xFFFFF000&((data)<<12))
#define WRAP_DISPLAY_PROTECT_SADDR0_display_prot_saddr0_src(data)                    ((0xFFFFF000&(data))>>12)
#define WRAP_DISPLAY_PROTECT_SADDR0_get_display_prot_saddr0(data)                    ((0xFFFFF000&(data))>>12)


#define WRAP_DISPLAY_PROTECT_EADDR0                                                  0x1805C8C4
#define WRAP_DISPLAY_PROTECT_EADDR0_reg_addr                                         "0xB805C8C4"
#define WRAP_DISPLAY_PROTECT_EADDR0_reg                                              0xB805C8C4
#define set_WRAP_DISPLAY_PROTECT_EADDR0_reg(data)   (*((volatile unsigned int*) WRAP_DISPLAY_PROTECT_EADDR0_reg)=data)
#define get_WRAP_DISPLAY_PROTECT_EADDR0_reg   (*((volatile unsigned int*) WRAP_DISPLAY_PROTECT_EADDR0_reg))
#define WRAP_DISPLAY_PROTECT_EADDR0_inst_adr                                         "0x0031"
#define WRAP_DISPLAY_PROTECT_EADDR0_inst                                             0x0031
#define WRAP_DISPLAY_PROTECT_EADDR0_display_prot_eaddr0_shift                        (12)
#define WRAP_DISPLAY_PROTECT_EADDR0_display_prot_eaddr0_mask                         (0xFFFFF000)
#define WRAP_DISPLAY_PROTECT_EADDR0_display_prot_eaddr0(data)                        (0xFFFFF000&((data)<<12))
#define WRAP_DISPLAY_PROTECT_EADDR0_display_prot_eaddr0_src(data)                    ((0xFFFFF000&(data))>>12)
#define WRAP_DISPLAY_PROTECT_EADDR0_get_display_prot_eaddr0(data)                    ((0xFFFFF000&(data))>>12)


#define WRAP_DISPLAY_PROTECT_SADDR1                                                  0x1805C8C8
#define WRAP_DISPLAY_PROTECT_SADDR1_reg_addr                                         "0xB805C8C8"
#define WRAP_DISPLAY_PROTECT_SADDR1_reg                                              0xB805C8C8
#define set_WRAP_DISPLAY_PROTECT_SADDR1_reg(data)   (*((volatile unsigned int*) WRAP_DISPLAY_PROTECT_SADDR1_reg)=data)
#define get_WRAP_DISPLAY_PROTECT_SADDR1_reg   (*((volatile unsigned int*) WRAP_DISPLAY_PROTECT_SADDR1_reg))
#define WRAP_DISPLAY_PROTECT_SADDR1_inst_adr                                         "0x0032"
#define WRAP_DISPLAY_PROTECT_SADDR1_inst                                             0x0032
#define WRAP_DISPLAY_PROTECT_SADDR1_display_prot_saddr1_shift                        (12)
#define WRAP_DISPLAY_PROTECT_SADDR1_display_prot_saddr1_mask                         (0xFFFFF000)
#define WRAP_DISPLAY_PROTECT_SADDR1_display_prot_saddr1(data)                        (0xFFFFF000&((data)<<12))
#define WRAP_DISPLAY_PROTECT_SADDR1_display_prot_saddr1_src(data)                    ((0xFFFFF000&(data))>>12)
#define WRAP_DISPLAY_PROTECT_SADDR1_get_display_prot_saddr1(data)                    ((0xFFFFF000&(data))>>12)


#define WRAP_DISPLAY_PROTECT_EADDR1                                                  0x1805C8CC
#define WRAP_DISPLAY_PROTECT_EADDR1_reg_addr                                         "0xB805C8CC"
#define WRAP_DISPLAY_PROTECT_EADDR1_reg                                              0xB805C8CC
#define set_WRAP_DISPLAY_PROTECT_EADDR1_reg(data)   (*((volatile unsigned int*) WRAP_DISPLAY_PROTECT_EADDR1_reg)=data)
#define get_WRAP_DISPLAY_PROTECT_EADDR1_reg   (*((volatile unsigned int*) WRAP_DISPLAY_PROTECT_EADDR1_reg))
#define WRAP_DISPLAY_PROTECT_EADDR1_inst_adr                                         "0x0033"
#define WRAP_DISPLAY_PROTECT_EADDR1_inst                                             0x0033
#define WRAP_DISPLAY_PROTECT_EADDR1_display_prot_eaddr1_shift                        (12)
#define WRAP_DISPLAY_PROTECT_EADDR1_display_prot_eaddr1_mask                         (0xFFFFF000)
#define WRAP_DISPLAY_PROTECT_EADDR1_display_prot_eaddr1(data)                        (0xFFFFF000&((data)<<12))
#define WRAP_DISPLAY_PROTECT_EADDR1_display_prot_eaddr1_src(data)                    ((0xFFFFF000&(data))>>12)
#define WRAP_DISPLAY_PROTECT_EADDR1_get_display_prot_eaddr1(data)                    ((0xFFFFF000&(data))>>12)


#define WRAP_NS_SCPU_ACC_DISP_PROT_INT                                               0x1805C8D0
#define WRAP_NS_SCPU_ACC_DISP_PROT_INT_reg_addr                                      "0xB805C8D0"
#define WRAP_NS_SCPU_ACC_DISP_PROT_INT_reg                                           0xB805C8D0
#define set_WRAP_NS_SCPU_ACC_DISP_PROT_INT_reg(data)   (*((volatile unsigned int*) WRAP_NS_SCPU_ACC_DISP_PROT_INT_reg)=data)
#define get_WRAP_NS_SCPU_ACC_DISP_PROT_INT_reg   (*((volatile unsigned int*) WRAP_NS_SCPU_ACC_DISP_PROT_INT_reg))
#define WRAP_NS_SCPU_ACC_DISP_PROT_INT_inst_adr                                      "0x0034"
#define WRAP_NS_SCPU_ACC_DISP_PROT_INT_inst                                          0x0034
#define WRAP_NS_SCPU_ACC_DISP_PROT_INT_ns_scpu_acc_disp_prot_int_shift               (1)
#define WRAP_NS_SCPU_ACC_DISP_PROT_INT_ns_scpu_acc_disp_prot_int_mask                (0x00000002)
#define WRAP_NS_SCPU_ACC_DISP_PROT_INT_ns_scpu_acc_disp_prot_int(data)               (0x00000002&((data)<<1))
#define WRAP_NS_SCPU_ACC_DISP_PROT_INT_ns_scpu_acc_disp_prot_int_src(data)           ((0x00000002&(data))>>1)
#define WRAP_NS_SCPU_ACC_DISP_PROT_INT_get_ns_scpu_acc_disp_prot_int(data)           ((0x00000002&(data))>>1)
#define WRAP_NS_SCPU_ACC_DISP_PROT_INT_ns_scpu_acc_disp_prot_int_en_shift            (0)
#define WRAP_NS_SCPU_ACC_DISP_PROT_INT_ns_scpu_acc_disp_prot_int_en_mask             (0x00000001)
#define WRAP_NS_SCPU_ACC_DISP_PROT_INT_ns_scpu_acc_disp_prot_int_en(data)            (0x00000001&((data)<<0))
#define WRAP_NS_SCPU_ACC_DISP_PROT_INT_ns_scpu_acc_disp_prot_int_en_src(data)        ((0x00000001&(data))>>0)
#define WRAP_NS_SCPU_ACC_DISP_PROT_INT_get_ns_scpu_acc_disp_prot_int_en(data)        ((0x00000001&(data))>>0)


#define WRAP_NS_SCPU_ACC_DISP_PROT_ADDR                                              0x1805C8D4
#define WRAP_NS_SCPU_ACC_DISP_PROT_ADDR_reg_addr                                     "0xB805C8D4"
#define WRAP_NS_SCPU_ACC_DISP_PROT_ADDR_reg                                          0xB805C8D4
#define set_WRAP_NS_SCPU_ACC_DISP_PROT_ADDR_reg(data)   (*((volatile unsigned int*) WRAP_NS_SCPU_ACC_DISP_PROT_ADDR_reg)=data)
#define get_WRAP_NS_SCPU_ACC_DISP_PROT_ADDR_reg   (*((volatile unsigned int*) WRAP_NS_SCPU_ACC_DISP_PROT_ADDR_reg))
#define WRAP_NS_SCPU_ACC_DISP_PROT_ADDR_inst_adr                                     "0x0035"
#define WRAP_NS_SCPU_ACC_DISP_PROT_ADDR_inst                                         0x0035
#define WRAP_NS_SCPU_ACC_DISP_PROT_ADDR_ns_scpu_acc_disp_prot_addr_shift             (0)
#define WRAP_NS_SCPU_ACC_DISP_PROT_ADDR_ns_scpu_acc_disp_prot_addr_mask              (0xFFFFFFFF)
#define WRAP_NS_SCPU_ACC_DISP_PROT_ADDR_ns_scpu_acc_disp_prot_addr(data)             (0xFFFFFFFF&((data)<<0))
#define WRAP_NS_SCPU_ACC_DISP_PROT_ADDR_ns_scpu_acc_disp_prot_addr_src(data)         ((0xFFFFFFFF&(data))>>0)
#define WRAP_NS_SCPU_ACC_DISP_PROT_ADDR_get_ns_scpu_acc_disp_prot_addr(data)         ((0xFFFFFFFF&(data))>>0)


#define WRAP_NS_SCPU_ACC_DISP_PROT_RW                                                0x1805C8D8
#define WRAP_NS_SCPU_ACC_DISP_PROT_RW_reg_addr                                       "0xB805C8D8"
#define WRAP_NS_SCPU_ACC_DISP_PROT_RW_reg                                            0xB805C8D8
#define set_WRAP_NS_SCPU_ACC_DISP_PROT_RW_reg(data)   (*((volatile unsigned int*) WRAP_NS_SCPU_ACC_DISP_PROT_RW_reg)=data)
#define get_WRAP_NS_SCPU_ACC_DISP_PROT_RW_reg   (*((volatile unsigned int*) WRAP_NS_SCPU_ACC_DISP_PROT_RW_reg))
#define WRAP_NS_SCPU_ACC_DISP_PROT_RW_inst_adr                                       "0x0036"
#define WRAP_NS_SCPU_ACC_DISP_PROT_RW_inst                                           0x0036
#define WRAP_NS_SCPU_ACC_DISP_PROT_RW_ns_scpu_acc_disp_prot_rw_shift                 (0)
#define WRAP_NS_SCPU_ACC_DISP_PROT_RW_ns_scpu_acc_disp_prot_rw_mask                  (0x00000001)
#define WRAP_NS_SCPU_ACC_DISP_PROT_RW_ns_scpu_acc_disp_prot_rw(data)                 (0x00000001&((data)<<0))
#define WRAP_NS_SCPU_ACC_DISP_PROT_RW_ns_scpu_acc_disp_prot_rw_src(data)             ((0x00000001&(data))>>0)
#define WRAP_NS_SCPU_ACC_DISP_PROT_RW_get_ns_scpu_acc_disp_prot_rw(data)             ((0x00000001&(data))>>0)


#endif
