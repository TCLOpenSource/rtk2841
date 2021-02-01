/**************************************************************
// Spec Version                  : unknown
// Parser Version                : DVR_Parser_6.11(120105)
// CModelGen Version             : 5.1 2012.01.05
// Naming Rule                   :  Module_Register_Name
// Naming Rule                   : Module_Register_Name_reg
// Parse Option                  : Only Parse _op1
// Parse Address Region          : All Address Region 
// Decode bit number             : 12 bits
// Firmware Header Generate Date : 2015/9/23 15:3:45
***************************************************************/


#ifndef _IPMD_REG_H_INCLUDED_
#define _IPMD_REG_H_INCLUDED_
#ifdef  _IPMD_USE_STRUCT
typedef struct 
{
unsigned int     reserved_0:18;
unsigned int     write_enable7:1;
unsigned int     Off4x4:1;
unsigned int     write_enable6:1;
unsigned int     Flush_cmd_disable:1;
unsigned int     write_enable5:1;
unsigned int     Softrst_disable:1;
unsigned int     write_enable4:1;
unsigned int     Umem_bypass:1;
unsigned int     write_enable3:1;
unsigned int     SReset_busy_clr:1;
unsigned int     write_enable2:1;
unsigned int     Pwmem_override:1;
unsigned int     write_enable1:1;
unsigned int     Constr_intra_pred:1;
}IPMD_CTRL;

typedef struct 
{
unsigned int     intra_flag:32;
}IPMD_INTRA;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     Value:28;
}IPMD_INTR_THRESH;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     Reach_Thresh:1;
unsigned int     Count:28;
}IPMD_BUSY;

typedef struct 
{
unsigned int     reserved_0:2;
unsigned int     Luma_Part:2;
unsigned int     reserved_1:7;
unsigned int     Luma_Cost:21;
}IPMD_RESULT0;

typedef struct 
{
unsigned int     reserved_0:11;
unsigned int     Chroma_Cost:21;
}IPMD_RESULT1;

typedef struct 
{
unsigned int     reserved_0:25;
unsigned int     Value:7;
}IPMD_LAMBDA;

typedef struct 
{
unsigned int     reserved_0:11;
unsigned int     Value:21;
}IPMD_WEIGHT;

typedef struct 
{
unsigned int     GenPulse:1;
unsigned int     DbgCtrl:3;
unsigned int     PicCount:14;
unsigned int     MbAddrX:7;
unsigned int     MbAddrY:7;
}IPMD_DBUS1;

typedef struct 
{
unsigned int     DbgCtrl:32;
}IPMD_DBUS2;

typedef struct 
{
unsigned int     R_16x16_0:4;
unsigned int     R_16x16_1:4;
unsigned int     R_16x16_2:4;
unsigned int     R_16x16_3:4;
unsigned int     R_chroma_0:4;
unsigned int     R_chroma_1:4;
unsigned int     R_chroma_2:4;
unsigned int     R_chroma_3:4;
}IPMD_COST0;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     R_same_8x8:4;
unsigned int     R_diff_8x8:4;
unsigned int     R_same_4x4:4;
unsigned int     R_diff_4x4:4;
}IPMD_COST1;

typedef struct 
{
unsigned int     Value:32;
}IPMD_INTRAMODE;

typedef struct 
{
unsigned int     Luma:32;
}IPMD_REMMODE;

typedef struct 
{
unsigned int     reserved_0:25;
unsigned int     y:7;
}IPMD_SLICE;

typedef struct 
{
unsigned int     Write_Pulse:1;
unsigned int     Read_Pulse:1;
unsigned int     reserved_0:3;
unsigned int     Address:7;
unsigned int     reserved_1:2;
unsigned int     IntraSel:2;
unsigned int     SubPart0:4;
unsigned int     SubPart1:4;
unsigned int     SubPart2:4;
unsigned int     SubPart3:4;
}IPMD_NPM_CTRL;

typedef struct 
{
unsigned int     reserved_0:5;
unsigned int     Luma_wr:1;
unsigned int     CB_wr:1;
unsigned int     CR_wr:1;
unsigned int     Luma:8;
unsigned int     CB:8;
unsigned int     CR:8;
}IPMD_ULPRED;

typedef struct 
{
unsigned int     reserved_0:26;
unsigned int     IntraLumaStyleSel:1;
unsigned int     reserved_1:5;
}IPMD_CBPCTRL;

typedef struct 
{
unsigned int     Lookup:32;
}IPMD_SUMRUNCOST_4X4;

typedef struct 
{
unsigned int     reserved_0:18;
unsigned int     Enable:1;
unsigned int     Thresh:13;
}IPMD_MBLEVEL_DROP;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     write_enable3:1;
unsigned int     flat_qtable:1;
unsigned int     write_enable2:1;
unsigned int     qpy:6;
unsigned int     write_enable1:1;
unsigned int     qpc:6;
}IPMD_QUANTIZER;

typedef struct 
{
unsigned int     reserved_0:9;
unsigned int     PictureType:2;
unsigned int     reserved_1:21;
}IPMD_MBINFO;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     cbp_stay:4;
unsigned int     cbp_base:4;
}IPMD_CBP;

#endif

#define IPMD_CTRL                                                                    0x18036100
#define IPMD_CTRL_reg_addr                                                           "0xB8036100"
#define IPMD_CTRL_reg                                                                0xB8036100
#define set_IPMD_CTRL_reg(data)   (*((volatile unsigned int*) IPMD_CTRL_reg)=data)
#define get_IPMD_CTRL_reg   (*((volatile unsigned int*) IPMD_CTRL_reg))
#define IPMD_CTRL_inst_adr                                                           "0x0040"
#define IPMD_CTRL_inst                                                               0x0040
#define IPMD_CTRL_write_enable7_shift                                                (13)
#define IPMD_CTRL_write_enable7_mask                                                 (0x00002000)
#define IPMD_CTRL_write_enable7(data)                                                (0x00002000&((data)<<13))
#define IPMD_CTRL_write_enable7_src(data)                                            ((0x00002000&(data))>>13)
#define IPMD_CTRL_get_write_enable7(data)                                            ((0x00002000&(data))>>13)
#define IPMD_CTRL_Off4x4_shift                                                       (12)
#define IPMD_CTRL_Off4x4_mask                                                        (0x00001000)
#define IPMD_CTRL_Off4x4(data)                                                       (0x00001000&((data)<<12))
#define IPMD_CTRL_Off4x4_src(data)                                                   ((0x00001000&(data))>>12)
#define IPMD_CTRL_get_Off4x4(data)                                                   ((0x00001000&(data))>>12)
#define IPMD_CTRL_write_enable6_shift                                                (11)
#define IPMD_CTRL_write_enable6_mask                                                 (0x00000800)
#define IPMD_CTRL_write_enable6(data)                                                (0x00000800&((data)<<11))
#define IPMD_CTRL_write_enable6_src(data)                                            ((0x00000800&(data))>>11)
#define IPMD_CTRL_get_write_enable6(data)                                            ((0x00000800&(data))>>11)
#define IPMD_CTRL_Flush_cmd_disable_shift                                            (10)
#define IPMD_CTRL_Flush_cmd_disable_mask                                             (0x00000400)
#define IPMD_CTRL_Flush_cmd_disable(data)                                            (0x00000400&((data)<<10))
#define IPMD_CTRL_Flush_cmd_disable_src(data)                                        ((0x00000400&(data))>>10)
#define IPMD_CTRL_get_Flush_cmd_disable(data)                                        ((0x00000400&(data))>>10)
#define IPMD_CTRL_write_enable5_shift                                                (9)
#define IPMD_CTRL_write_enable5_mask                                                 (0x00000200)
#define IPMD_CTRL_write_enable5(data)                                                (0x00000200&((data)<<9))
#define IPMD_CTRL_write_enable5_src(data)                                            ((0x00000200&(data))>>9)
#define IPMD_CTRL_get_write_enable5(data)                                            ((0x00000200&(data))>>9)
#define IPMD_CTRL_Softrst_disable_shift                                              (8)
#define IPMD_CTRL_Softrst_disable_mask                                               (0x00000100)
#define IPMD_CTRL_Softrst_disable(data)                                              (0x00000100&((data)<<8))
#define IPMD_CTRL_Softrst_disable_src(data)                                          ((0x00000100&(data))>>8)
#define IPMD_CTRL_get_Softrst_disable(data)                                          ((0x00000100&(data))>>8)
#define IPMD_CTRL_write_enable4_shift                                                (7)
#define IPMD_CTRL_write_enable4_mask                                                 (0x00000080)
#define IPMD_CTRL_write_enable4(data)                                                (0x00000080&((data)<<7))
#define IPMD_CTRL_write_enable4_src(data)                                            ((0x00000080&(data))>>7)
#define IPMD_CTRL_get_write_enable4(data)                                            ((0x00000080&(data))>>7)
#define IPMD_CTRL_Umem_bypass_shift                                                  (6)
#define IPMD_CTRL_Umem_bypass_mask                                                   (0x00000040)
#define IPMD_CTRL_Umem_bypass(data)                                                  (0x00000040&((data)<<6))
#define IPMD_CTRL_Umem_bypass_src(data)                                              ((0x00000040&(data))>>6)
#define IPMD_CTRL_get_Umem_bypass(data)                                              ((0x00000040&(data))>>6)
#define IPMD_CTRL_write_enable3_shift                                                (5)
#define IPMD_CTRL_write_enable3_mask                                                 (0x00000020)
#define IPMD_CTRL_write_enable3(data)                                                (0x00000020&((data)<<5))
#define IPMD_CTRL_write_enable3_src(data)                                            ((0x00000020&(data))>>5)
#define IPMD_CTRL_get_write_enable3(data)                                            ((0x00000020&(data))>>5)
#define IPMD_CTRL_SReset_busy_clr_shift                                              (4)
#define IPMD_CTRL_SReset_busy_clr_mask                                               (0x00000010)
#define IPMD_CTRL_SReset_busy_clr(data)                                              (0x00000010&((data)<<4))
#define IPMD_CTRL_SReset_busy_clr_src(data)                                          ((0x00000010&(data))>>4)
#define IPMD_CTRL_get_SReset_busy_clr(data)                                          ((0x00000010&(data))>>4)
#define IPMD_CTRL_write_enable2_shift                                                (3)
#define IPMD_CTRL_write_enable2_mask                                                 (0x00000008)
#define IPMD_CTRL_write_enable2(data)                                                (0x00000008&((data)<<3))
#define IPMD_CTRL_write_enable2_src(data)                                            ((0x00000008&(data))>>3)
#define IPMD_CTRL_get_write_enable2(data)                                            ((0x00000008&(data))>>3)
#define IPMD_CTRL_Pwmem_override_shift                                               (2)
#define IPMD_CTRL_Pwmem_override_mask                                                (0x00000004)
#define IPMD_CTRL_Pwmem_override(data)                                               (0x00000004&((data)<<2))
#define IPMD_CTRL_Pwmem_override_src(data)                                           ((0x00000004&(data))>>2)
#define IPMD_CTRL_get_Pwmem_override(data)                                           ((0x00000004&(data))>>2)
#define IPMD_CTRL_write_enable1_shift                                                (1)
#define IPMD_CTRL_write_enable1_mask                                                 (0x00000002)
#define IPMD_CTRL_write_enable1(data)                                                (0x00000002&((data)<<1))
#define IPMD_CTRL_write_enable1_src(data)                                            ((0x00000002&(data))>>1)
#define IPMD_CTRL_get_write_enable1(data)                                            ((0x00000002&(data))>>1)
#define IPMD_CTRL_Constr_intra_pred_shift                                            (0)
#define IPMD_CTRL_Constr_intra_pred_mask                                             (0x00000001)
#define IPMD_CTRL_Constr_intra_pred(data)                                            (0x00000001&((data)<<0))
#define IPMD_CTRL_Constr_intra_pred_src(data)                                        ((0x00000001&(data))>>0)
#define IPMD_CTRL_get_Constr_intra_pred(data)                                        ((0x00000001&(data))>>0)


#define IPMD_INTRA_0                                                                 0x1803610C
#define IPMD_INTRA_1                                                                 0x18036110
#define IPMD_INTRA_2                                                                 0x18036114
#define IPMD_INTRA_3                                                                 0x18036118
#define IPMD_INTRA_0_reg_addr                                                        "0xB803610C"
#define IPMD_INTRA_1_reg_addr                                                        "0xB8036110"
#define IPMD_INTRA_2_reg_addr                                                        "0xB8036114"
#define IPMD_INTRA_3_reg_addr                                                        "0xB8036118"
#define IPMD_INTRA_0_reg                                                             0xB803610C
#define IPMD_INTRA_1_reg                                                             0xB8036110
#define IPMD_INTRA_2_reg                                                             0xB8036114
#define IPMD_INTRA_3_reg                                                             0xB8036118
#define set_IPMD_INTRA_0_reg(data)   (*((volatile unsigned int*) IPMD_INTRA_0_reg)=data)
#define set_IPMD_INTRA_1_reg(data)   (*((volatile unsigned int*) IPMD_INTRA_1_reg)=data)
#define set_IPMD_INTRA_2_reg(data)   (*((volatile unsigned int*) IPMD_INTRA_2_reg)=data)
#define set_IPMD_INTRA_3_reg(data)   (*((volatile unsigned int*) IPMD_INTRA_3_reg)=data)
#define get_IPMD_INTRA_0_reg   (*((volatile unsigned int*) IPMD_INTRA_0_reg))
#define get_IPMD_INTRA_1_reg   (*((volatile unsigned int*) IPMD_INTRA_1_reg))
#define get_IPMD_INTRA_2_reg   (*((volatile unsigned int*) IPMD_INTRA_2_reg))
#define get_IPMD_INTRA_3_reg   (*((volatile unsigned int*) IPMD_INTRA_3_reg))
#define IPMD_INTRA_0_inst_adr                                                        "0x0043"
#define IPMD_INTRA_1_inst_adr                                                        "0x0044"
#define IPMD_INTRA_2_inst_adr                                                        "0x0045"
#define IPMD_INTRA_3_inst_adr                                                        "0x0046"
#define IPMD_INTRA_0_inst                                                            0x0043
#define IPMD_INTRA_1_inst                                                            0x0044
#define IPMD_INTRA_2_inst                                                            0x0045
#define IPMD_INTRA_3_inst                                                            0x0046
#define IPMD_INTRA_intra_flag_shift                                                  (0)
#define IPMD_INTRA_intra_flag_mask                                                   (0xFFFFFFFF)
#define IPMD_INTRA_intra_flag(data)                                                  (0xFFFFFFFF&((data)<<0))
#define IPMD_INTRA_intra_flag_src(data)                                              ((0xFFFFFFFF&(data))>>0)
#define IPMD_INTRA_get_intra_flag(data)                                              ((0xFFFFFFFF&(data))>>0)


#define IPMD_INTR_THRESH                                                             0x18036120
#define IPMD_INTR_THRESH_reg_addr                                                    "0xB8036120"
#define IPMD_INTR_THRESH_reg                                                         0xB8036120
#define set_IPMD_INTR_THRESH_reg(data)   (*((volatile unsigned int*) IPMD_INTR_THRESH_reg)=data)
#define get_IPMD_INTR_THRESH_reg   (*((volatile unsigned int*) IPMD_INTR_THRESH_reg))
#define IPMD_INTR_THRESH_inst_adr                                                    "0x0048"
#define IPMD_INTR_THRESH_inst                                                        0x0048
#define IPMD_INTR_THRESH_Value_shift                                                 (0)
#define IPMD_INTR_THRESH_Value_mask                                                  (0x0FFFFFFF)
#define IPMD_INTR_THRESH_Value(data)                                                 (0x0FFFFFFF&((data)<<0))
#define IPMD_INTR_THRESH_Value_src(data)                                             ((0x0FFFFFFF&(data))>>0)
#define IPMD_INTR_THRESH_get_Value(data)                                             ((0x0FFFFFFF&(data))>>0)


#define IPMD_BUSY                                                                    0x18036124
#define IPMD_BUSY_reg_addr                                                           "0xB8036124"
#define IPMD_BUSY_reg                                                                0xB8036124
#define set_IPMD_BUSY_reg(data)   (*((volatile unsigned int*) IPMD_BUSY_reg)=data)
#define get_IPMD_BUSY_reg   (*((volatile unsigned int*) IPMD_BUSY_reg))
#define IPMD_BUSY_inst_adr                                                           "0x0049"
#define IPMD_BUSY_inst                                                               0x0049
#define IPMD_BUSY_Reach_Thresh_shift                                                 (28)
#define IPMD_BUSY_Reach_Thresh_mask                                                  (0x10000000)
#define IPMD_BUSY_Reach_Thresh(data)                                                 (0x10000000&((data)<<28))
#define IPMD_BUSY_Reach_Thresh_src(data)                                             ((0x10000000&(data))>>28)
#define IPMD_BUSY_get_Reach_Thresh(data)                                             ((0x10000000&(data))>>28)
#define IPMD_BUSY_Count_shift                                                        (0)
#define IPMD_BUSY_Count_mask                                                         (0x0FFFFFFF)
#define IPMD_BUSY_Count(data)                                                        (0x0FFFFFFF&((data)<<0))
#define IPMD_BUSY_Count_src(data)                                                    ((0x0FFFFFFF&(data))>>0)
#define IPMD_BUSY_get_Count(data)                                                    ((0x0FFFFFFF&(data))>>0)


#define IPMD_RESULT0                                                                 0x18036128
#define IPMD_RESULT0_reg_addr                                                        "0xB8036128"
#define IPMD_RESULT0_reg                                                             0xB8036128
#define set_IPMD_RESULT0_reg(data)   (*((volatile unsigned int*) IPMD_RESULT0_reg)=data)
#define get_IPMD_RESULT0_reg   (*((volatile unsigned int*) IPMD_RESULT0_reg))
#define IPMD_RESULT0_inst_adr                                                        "0x004A"
#define IPMD_RESULT0_inst                                                            0x004A
#define IPMD_RESULT0_Luma_Part_shift                                                 (28)
#define IPMD_RESULT0_Luma_Part_mask                                                  (0x30000000)
#define IPMD_RESULT0_Luma_Part(data)                                                 (0x30000000&((data)<<28))
#define IPMD_RESULT0_Luma_Part_src(data)                                             ((0x30000000&(data))>>28)
#define IPMD_RESULT0_get_Luma_Part(data)                                             ((0x30000000&(data))>>28)
#define IPMD_RESULT0_Luma_Cost_shift                                                 (0)
#define IPMD_RESULT0_Luma_Cost_mask                                                  (0x001FFFFF)
#define IPMD_RESULT0_Luma_Cost(data)                                                 (0x001FFFFF&((data)<<0))
#define IPMD_RESULT0_Luma_Cost_src(data)                                             ((0x001FFFFF&(data))>>0)
#define IPMD_RESULT0_get_Luma_Cost(data)                                             ((0x001FFFFF&(data))>>0)


#define IPMD_RESULT1                                                                 0x1803612C
#define IPMD_RESULT1_reg_addr                                                        "0xB803612C"
#define IPMD_RESULT1_reg                                                             0xB803612C
#define set_IPMD_RESULT1_reg(data)   (*((volatile unsigned int*) IPMD_RESULT1_reg)=data)
#define get_IPMD_RESULT1_reg   (*((volatile unsigned int*) IPMD_RESULT1_reg))
#define IPMD_RESULT1_inst_adr                                                        "0x004B"
#define IPMD_RESULT1_inst                                                            0x004B
#define IPMD_RESULT1_Chroma_Cost_shift                                               (0)
#define IPMD_RESULT1_Chroma_Cost_mask                                                (0x001FFFFF)
#define IPMD_RESULT1_Chroma_Cost(data)                                               (0x001FFFFF&((data)<<0))
#define IPMD_RESULT1_Chroma_Cost_src(data)                                           ((0x001FFFFF&(data))>>0)
#define IPMD_RESULT1_get_Chroma_Cost(data)                                           ((0x001FFFFF&(data))>>0)


#define IPMD_LAMBDA                                                                  0x18036130
#define IPMD_LAMBDA_reg_addr                                                         "0xB8036130"
#define IPMD_LAMBDA_reg                                                              0xB8036130
#define set_IPMD_LAMBDA_reg(data)   (*((volatile unsigned int*) IPMD_LAMBDA_reg)=data)
#define get_IPMD_LAMBDA_reg   (*((volatile unsigned int*) IPMD_LAMBDA_reg))
#define IPMD_LAMBDA_inst_adr                                                         "0x004C"
#define IPMD_LAMBDA_inst                                                             0x004C
#define IPMD_LAMBDA_Value_shift                                                      (0)
#define IPMD_LAMBDA_Value_mask                                                       (0x0000007F)
#define IPMD_LAMBDA_Value(data)                                                      (0x0000007F&((data)<<0))
#define IPMD_LAMBDA_Value_src(data)                                                  ((0x0000007F&(data))>>0)
#define IPMD_LAMBDA_get_Value(data)                                                  ((0x0000007F&(data))>>0)


#define IPMD_WEIGHT_0                                                                0x18036134
#define IPMD_WEIGHT_1                                                                0x18036138
#define IPMD_WEIGHT_2                                                                0x1803613C
#define IPMD_WEIGHT_0_reg_addr                                                       "0xB8036134"
#define IPMD_WEIGHT_1_reg_addr                                                       "0xB8036138"
#define IPMD_WEIGHT_2_reg_addr                                                       "0xB803613C"
#define IPMD_WEIGHT_0_reg                                                            0xB8036134
#define IPMD_WEIGHT_1_reg                                                            0xB8036138
#define IPMD_WEIGHT_2_reg                                                            0xB803613C
#define set_IPMD_WEIGHT_0_reg(data)   (*((volatile unsigned int*) IPMD_WEIGHT_0_reg)=data)
#define set_IPMD_WEIGHT_1_reg(data)   (*((volatile unsigned int*) IPMD_WEIGHT_1_reg)=data)
#define set_IPMD_WEIGHT_2_reg(data)   (*((volatile unsigned int*) IPMD_WEIGHT_2_reg)=data)
#define get_IPMD_WEIGHT_0_reg   (*((volatile unsigned int*) IPMD_WEIGHT_0_reg))
#define get_IPMD_WEIGHT_1_reg   (*((volatile unsigned int*) IPMD_WEIGHT_1_reg))
#define get_IPMD_WEIGHT_2_reg   (*((volatile unsigned int*) IPMD_WEIGHT_2_reg))
#define IPMD_WEIGHT_0_inst_adr                                                       "0x004D"
#define IPMD_WEIGHT_1_inst_adr                                                       "0x004E"
#define IPMD_WEIGHT_2_inst_adr                                                       "0x004F"
#define IPMD_WEIGHT_0_inst                                                           0x004D
#define IPMD_WEIGHT_1_inst                                                           0x004E
#define IPMD_WEIGHT_2_inst                                                           0x004F
#define IPMD_WEIGHT_Value_shift                                                      (0)
#define IPMD_WEIGHT_Value_mask                                                       (0x001FFFFF)
#define IPMD_WEIGHT_Value(data)                                                      (0x001FFFFF&((data)<<0))
#define IPMD_WEIGHT_Value_src(data)                                                  ((0x001FFFFF&(data))>>0)
#define IPMD_WEIGHT_get_Value(data)                                                  ((0x001FFFFF&(data))>>0)


#define IPMD_DBUS1                                                                   0x18036140
#define IPMD_DBUS1_reg_addr                                                          "0xB8036140"
#define IPMD_DBUS1_reg                                                               0xB8036140
#define set_IPMD_DBUS1_reg(data)   (*((volatile unsigned int*) IPMD_DBUS1_reg)=data)
#define get_IPMD_DBUS1_reg   (*((volatile unsigned int*) IPMD_DBUS1_reg))
#define IPMD_DBUS1_inst_adr                                                          "0x0050"
#define IPMD_DBUS1_inst                                                              0x0050
#define IPMD_DBUS1_GenPulse_shift                                                    (31)
#define IPMD_DBUS1_GenPulse_mask                                                     (0x80000000)
#define IPMD_DBUS1_GenPulse(data)                                                    (0x80000000&((data)<<31))
#define IPMD_DBUS1_GenPulse_src(data)                                                ((0x80000000&(data))>>31)
#define IPMD_DBUS1_get_GenPulse(data)                                                ((0x80000000&(data))>>31)
#define IPMD_DBUS1_DbgCtrl_shift                                                     (28)
#define IPMD_DBUS1_DbgCtrl_mask                                                      (0x70000000)
#define IPMD_DBUS1_DbgCtrl(data)                                                     (0x70000000&((data)<<28))
#define IPMD_DBUS1_DbgCtrl_src(data)                                                 ((0x70000000&(data))>>28)
#define IPMD_DBUS1_get_DbgCtrl(data)                                                 ((0x70000000&(data))>>28)
#define IPMD_DBUS1_PicCount_shift                                                    (14)
#define IPMD_DBUS1_PicCount_mask                                                     (0x0FFFC000)
#define IPMD_DBUS1_PicCount(data)                                                    (0x0FFFC000&((data)<<14))
#define IPMD_DBUS1_PicCount_src(data)                                                ((0x0FFFC000&(data))>>14)
#define IPMD_DBUS1_get_PicCount(data)                                                ((0x0FFFC000&(data))>>14)
#define IPMD_DBUS1_MbAddrX_shift                                                     (7)
#define IPMD_DBUS1_MbAddrX_mask                                                      (0x00003F80)
#define IPMD_DBUS1_MbAddrX(data)                                                     (0x00003F80&((data)<<7))
#define IPMD_DBUS1_MbAddrX_src(data)                                                 ((0x00003F80&(data))>>7)
#define IPMD_DBUS1_get_MbAddrX(data)                                                 ((0x00003F80&(data))>>7)
#define IPMD_DBUS1_MbAddrY_shift                                                     (0)
#define IPMD_DBUS1_MbAddrY_mask                                                      (0x0000007F)
#define IPMD_DBUS1_MbAddrY(data)                                                     (0x0000007F&((data)<<0))
#define IPMD_DBUS1_MbAddrY_src(data)                                                 ((0x0000007F&(data))>>0)
#define IPMD_DBUS1_get_MbAddrY(data)                                                 ((0x0000007F&(data))>>0)


#define IPMD_DBUS2                                                                   0x18036144
#define IPMD_DBUS2_reg_addr                                                          "0xB8036144"
#define IPMD_DBUS2_reg                                                               0xB8036144
#define set_IPMD_DBUS2_reg(data)   (*((volatile unsigned int*) IPMD_DBUS2_reg)=data)
#define get_IPMD_DBUS2_reg   (*((volatile unsigned int*) IPMD_DBUS2_reg))
#define IPMD_DBUS2_inst_adr                                                          "0x0051"
#define IPMD_DBUS2_inst                                                              0x0051
#define IPMD_DBUS2_DbgCtrl_shift                                                     (0)
#define IPMD_DBUS2_DbgCtrl_mask                                                      (0xFFFFFFFF)
#define IPMD_DBUS2_DbgCtrl(data)                                                     (0xFFFFFFFF&((data)<<0))
#define IPMD_DBUS2_DbgCtrl_src(data)                                                 ((0xFFFFFFFF&(data))>>0)
#define IPMD_DBUS2_get_DbgCtrl(data)                                                 ((0xFFFFFFFF&(data))>>0)


#define IPMD_COST0                                                                   0x18036148
#define IPMD_COST0_reg_addr                                                          "0xB8036148"
#define IPMD_COST0_reg                                                               0xB8036148
#define set_IPMD_COST0_reg(data)   (*((volatile unsigned int*) IPMD_COST0_reg)=data)
#define get_IPMD_COST0_reg   (*((volatile unsigned int*) IPMD_COST0_reg))
#define IPMD_COST0_inst_adr                                                          "0x0052"
#define IPMD_COST0_inst                                                              0x0052
#define IPMD_COST0_R_16x16_0_shift                                                   (28)
#define IPMD_COST0_R_16x16_0_mask                                                    (0xF0000000)
#define IPMD_COST0_R_16x16_0(data)                                                   (0xF0000000&((data)<<28))
#define IPMD_COST0_R_16x16_0_src(data)                                               ((0xF0000000&(data))>>28)
#define IPMD_COST0_get_R_16x16_0(data)                                               ((0xF0000000&(data))>>28)
#define IPMD_COST0_R_16x16_1_shift                                                   (24)
#define IPMD_COST0_R_16x16_1_mask                                                    (0x0F000000)
#define IPMD_COST0_R_16x16_1(data)                                                   (0x0F000000&((data)<<24))
#define IPMD_COST0_R_16x16_1_src(data)                                               ((0x0F000000&(data))>>24)
#define IPMD_COST0_get_R_16x16_1(data)                                               ((0x0F000000&(data))>>24)
#define IPMD_COST0_R_16x16_2_shift                                                   (20)
#define IPMD_COST0_R_16x16_2_mask                                                    (0x00F00000)
#define IPMD_COST0_R_16x16_2(data)                                                   (0x00F00000&((data)<<20))
#define IPMD_COST0_R_16x16_2_src(data)                                               ((0x00F00000&(data))>>20)
#define IPMD_COST0_get_R_16x16_2(data)                                               ((0x00F00000&(data))>>20)
#define IPMD_COST0_R_16x16_3_shift                                                   (16)
#define IPMD_COST0_R_16x16_3_mask                                                    (0x000F0000)
#define IPMD_COST0_R_16x16_3(data)                                                   (0x000F0000&((data)<<16))
#define IPMD_COST0_R_16x16_3_src(data)                                               ((0x000F0000&(data))>>16)
#define IPMD_COST0_get_R_16x16_3(data)                                               ((0x000F0000&(data))>>16)
#define IPMD_COST0_R_chroma_0_shift                                                  (12)
#define IPMD_COST0_R_chroma_0_mask                                                   (0x0000F000)
#define IPMD_COST0_R_chroma_0(data)                                                  (0x0000F000&((data)<<12))
#define IPMD_COST0_R_chroma_0_src(data)                                              ((0x0000F000&(data))>>12)
#define IPMD_COST0_get_R_chroma_0(data)                                              ((0x0000F000&(data))>>12)
#define IPMD_COST0_R_chroma_1_shift                                                  (8)
#define IPMD_COST0_R_chroma_1_mask                                                   (0x00000F00)
#define IPMD_COST0_R_chroma_1(data)                                                  (0x00000F00&((data)<<8))
#define IPMD_COST0_R_chroma_1_src(data)                                              ((0x00000F00&(data))>>8)
#define IPMD_COST0_get_R_chroma_1(data)                                              ((0x00000F00&(data))>>8)
#define IPMD_COST0_R_chroma_2_shift                                                  (4)
#define IPMD_COST0_R_chroma_2_mask                                                   (0x000000F0)
#define IPMD_COST0_R_chroma_2(data)                                                  (0x000000F0&((data)<<4))
#define IPMD_COST0_R_chroma_2_src(data)                                              ((0x000000F0&(data))>>4)
#define IPMD_COST0_get_R_chroma_2(data)                                              ((0x000000F0&(data))>>4)
#define IPMD_COST0_R_chroma_3_shift                                                  (0)
#define IPMD_COST0_R_chroma_3_mask                                                   (0x0000000F)
#define IPMD_COST0_R_chroma_3(data)                                                  (0x0000000F&((data)<<0))
#define IPMD_COST0_R_chroma_3_src(data)                                              ((0x0000000F&(data))>>0)
#define IPMD_COST0_get_R_chroma_3(data)                                              ((0x0000000F&(data))>>0)


#define IPMD_COST1                                                                   0x1803614C
#define IPMD_COST1_reg_addr                                                          "0xB803614C"
#define IPMD_COST1_reg                                                               0xB803614C
#define set_IPMD_COST1_reg(data)   (*((volatile unsigned int*) IPMD_COST1_reg)=data)
#define get_IPMD_COST1_reg   (*((volatile unsigned int*) IPMD_COST1_reg))
#define IPMD_COST1_inst_adr                                                          "0x0053"
#define IPMD_COST1_inst                                                              0x0053
#define IPMD_COST1_R_same_8x8_shift                                                  (12)
#define IPMD_COST1_R_same_8x8_mask                                                   (0x0000F000)
#define IPMD_COST1_R_same_8x8(data)                                                  (0x0000F000&((data)<<12))
#define IPMD_COST1_R_same_8x8_src(data)                                              ((0x0000F000&(data))>>12)
#define IPMD_COST1_get_R_same_8x8(data)                                              ((0x0000F000&(data))>>12)
#define IPMD_COST1_R_diff_8x8_shift                                                  (8)
#define IPMD_COST1_R_diff_8x8_mask                                                   (0x00000F00)
#define IPMD_COST1_R_diff_8x8(data)                                                  (0x00000F00&((data)<<8))
#define IPMD_COST1_R_diff_8x8_src(data)                                              ((0x00000F00&(data))>>8)
#define IPMD_COST1_get_R_diff_8x8(data)                                              ((0x00000F00&(data))>>8)
#define IPMD_COST1_R_same_4x4_shift                                                  (4)
#define IPMD_COST1_R_same_4x4_mask                                                   (0x000000F0)
#define IPMD_COST1_R_same_4x4(data)                                                  (0x000000F0&((data)<<4))
#define IPMD_COST1_R_same_4x4_src(data)                                              ((0x000000F0&(data))>>4)
#define IPMD_COST1_get_R_same_4x4(data)                                              ((0x000000F0&(data))>>4)
#define IPMD_COST1_R_diff_4x4_shift                                                  (0)
#define IPMD_COST1_R_diff_4x4_mask                                                   (0x0000000F)
#define IPMD_COST1_R_diff_4x4(data)                                                  (0x0000000F&((data)<<0))
#define IPMD_COST1_R_diff_4x4_src(data)                                              ((0x0000000F&(data))>>0)
#define IPMD_COST1_get_R_diff_4x4(data)                                              ((0x0000000F&(data))>>0)


#define IPMD_INTRAMODE_0                                                             0x18036150
#define IPMD_INTRAMODE_1                                                             0x18036154
#define IPMD_INTRAMODE_2                                                             0x18036158
#define IPMD_INTRAMODE_0_reg_addr                                                    "0xB8036150"
#define IPMD_INTRAMODE_1_reg_addr                                                    "0xB8036154"
#define IPMD_INTRAMODE_2_reg_addr                                                    "0xB8036158"
#define IPMD_INTRAMODE_0_reg                                                         0xB8036150
#define IPMD_INTRAMODE_1_reg                                                         0xB8036154
#define IPMD_INTRAMODE_2_reg                                                         0xB8036158
#define set_IPMD_INTRAMODE_0_reg(data)   (*((volatile unsigned int*) IPMD_INTRAMODE_0_reg)=data)
#define set_IPMD_INTRAMODE_1_reg(data)   (*((volatile unsigned int*) IPMD_INTRAMODE_1_reg)=data)
#define set_IPMD_INTRAMODE_2_reg(data)   (*((volatile unsigned int*) IPMD_INTRAMODE_2_reg)=data)
#define get_IPMD_INTRAMODE_0_reg   (*((volatile unsigned int*) IPMD_INTRAMODE_0_reg))
#define get_IPMD_INTRAMODE_1_reg   (*((volatile unsigned int*) IPMD_INTRAMODE_1_reg))
#define get_IPMD_INTRAMODE_2_reg   (*((volatile unsigned int*) IPMD_INTRAMODE_2_reg))
#define IPMD_INTRAMODE_0_inst_adr                                                    "0x0054"
#define IPMD_INTRAMODE_1_inst_adr                                                    "0x0055"
#define IPMD_INTRAMODE_2_inst_adr                                                    "0x0056"
#define IPMD_INTRAMODE_0_inst                                                        0x0054
#define IPMD_INTRAMODE_1_inst                                                        0x0055
#define IPMD_INTRAMODE_2_inst                                                        0x0056
#define IPMD_INTRAMODE_Value_shift                                                   (0)
#define IPMD_INTRAMODE_Value_mask                                                    (0xFFFFFFFF)
#define IPMD_INTRAMODE_Value(data)                                                   (0xFFFFFFFF&((data)<<0))
#define IPMD_INTRAMODE_Value_src(data)                                               ((0xFFFFFFFF&(data))>>0)
#define IPMD_INTRAMODE_get_Value(data)                                               ((0xFFFFFFFF&(data))>>0)


#define IPMD_REMMODE_0                                                               0x1803615C
#define IPMD_REMMODE_1                                                               0x18036160
#define IPMD_REMMODE_2                                                               0x18036164
#define IPMD_REMMODE_0_reg_addr                                                      "0xB803615C"
#define IPMD_REMMODE_1_reg_addr                                                      "0xB8036160"
#define IPMD_REMMODE_2_reg_addr                                                      "0xB8036164"
#define IPMD_REMMODE_0_reg                                                           0xB803615C
#define IPMD_REMMODE_1_reg                                                           0xB8036160
#define IPMD_REMMODE_2_reg                                                           0xB8036164
#define set_IPMD_REMMODE_0_reg(data)   (*((volatile unsigned int*) IPMD_REMMODE_0_reg)=data)
#define set_IPMD_REMMODE_1_reg(data)   (*((volatile unsigned int*) IPMD_REMMODE_1_reg)=data)
#define set_IPMD_REMMODE_2_reg(data)   (*((volatile unsigned int*) IPMD_REMMODE_2_reg)=data)
#define get_IPMD_REMMODE_0_reg   (*((volatile unsigned int*) IPMD_REMMODE_0_reg))
#define get_IPMD_REMMODE_1_reg   (*((volatile unsigned int*) IPMD_REMMODE_1_reg))
#define get_IPMD_REMMODE_2_reg   (*((volatile unsigned int*) IPMD_REMMODE_2_reg))
#define IPMD_REMMODE_0_inst_adr                                                      "0x0057"
#define IPMD_REMMODE_1_inst_adr                                                      "0x0058"
#define IPMD_REMMODE_2_inst_adr                                                      "0x0059"
#define IPMD_REMMODE_0_inst                                                          0x0057
#define IPMD_REMMODE_1_inst                                                          0x0058
#define IPMD_REMMODE_2_inst                                                          0x0059
#define IPMD_REMMODE_Luma_shift                                                      (0)
#define IPMD_REMMODE_Luma_mask                                                       (0xFFFFFFFF)
#define IPMD_REMMODE_Luma(data)                                                      (0xFFFFFFFF&((data)<<0))
#define IPMD_REMMODE_Luma_src(data)                                                  ((0xFFFFFFFF&(data))>>0)
#define IPMD_REMMODE_get_Luma(data)                                                  ((0xFFFFFFFF&(data))>>0)


#define IPMD_SLICE                                                                   0x18036168
#define IPMD_SLICE_reg_addr                                                          "0xB8036168"
#define IPMD_SLICE_reg                                                               0xB8036168
#define set_IPMD_SLICE_reg(data)   (*((volatile unsigned int*) IPMD_SLICE_reg)=data)
#define get_IPMD_SLICE_reg   (*((volatile unsigned int*) IPMD_SLICE_reg))
#define IPMD_SLICE_inst_adr                                                          "0x005A"
#define IPMD_SLICE_inst                                                              0x005A
#define IPMD_SLICE_y_shift                                                           (0)
#define IPMD_SLICE_y_mask                                                            (0x0000007F)
#define IPMD_SLICE_y(data)                                                           (0x0000007F&((data)<<0))
#define IPMD_SLICE_y_src(data)                                                       ((0x0000007F&(data))>>0)
#define IPMD_SLICE_get_y(data)                                                       ((0x0000007F&(data))>>0)


#define IPMD_NPM_CTRL                                                                0x1803616C
#define IPMD_NPM_CTRL_reg_addr                                                       "0xB803616C"
#define IPMD_NPM_CTRL_reg                                                            0xB803616C
#define set_IPMD_NPM_CTRL_reg(data)   (*((volatile unsigned int*) IPMD_NPM_CTRL_reg)=data)
#define get_IPMD_NPM_CTRL_reg   (*((volatile unsigned int*) IPMD_NPM_CTRL_reg))
#define IPMD_NPM_CTRL_inst_adr                                                       "0x005B"
#define IPMD_NPM_CTRL_inst                                                           0x005B
#define IPMD_NPM_CTRL_Write_Pulse_shift                                              (31)
#define IPMD_NPM_CTRL_Write_Pulse_mask                                               (0x80000000)
#define IPMD_NPM_CTRL_Write_Pulse(data)                                              (0x80000000&((data)<<31))
#define IPMD_NPM_CTRL_Write_Pulse_src(data)                                          ((0x80000000&(data))>>31)
#define IPMD_NPM_CTRL_get_Write_Pulse(data)                                          ((0x80000000&(data))>>31)
#define IPMD_NPM_CTRL_Read_Pulse_shift                                               (30)
#define IPMD_NPM_CTRL_Read_Pulse_mask                                                (0x40000000)
#define IPMD_NPM_CTRL_Read_Pulse(data)                                               (0x40000000&((data)<<30))
#define IPMD_NPM_CTRL_Read_Pulse_src(data)                                           ((0x40000000&(data))>>30)
#define IPMD_NPM_CTRL_get_Read_Pulse(data)                                           ((0x40000000&(data))>>30)
#define IPMD_NPM_CTRL_Address_shift                                                  (20)
#define IPMD_NPM_CTRL_Address_mask                                                   (0x07F00000)
#define IPMD_NPM_CTRL_Address(data)                                                  (0x07F00000&((data)<<20))
#define IPMD_NPM_CTRL_Address_src(data)                                              ((0x07F00000&(data))>>20)
#define IPMD_NPM_CTRL_get_Address(data)                                              ((0x07F00000&(data))>>20)
#define IPMD_NPM_CTRL_IntraSel_shift                                                 (16)
#define IPMD_NPM_CTRL_IntraSel_mask                                                  (0x00030000)
#define IPMD_NPM_CTRL_IntraSel(data)                                                 (0x00030000&((data)<<16))
#define IPMD_NPM_CTRL_IntraSel_src(data)                                             ((0x00030000&(data))>>16)
#define IPMD_NPM_CTRL_get_IntraSel(data)                                             ((0x00030000&(data))>>16)
#define IPMD_NPM_CTRL_SubPart0_shift                                                 (12)
#define IPMD_NPM_CTRL_SubPart0_mask                                                  (0x0000F000)
#define IPMD_NPM_CTRL_SubPart0(data)                                                 (0x0000F000&((data)<<12))
#define IPMD_NPM_CTRL_SubPart0_src(data)                                             ((0x0000F000&(data))>>12)
#define IPMD_NPM_CTRL_get_SubPart0(data)                                             ((0x0000F000&(data))>>12)
#define IPMD_NPM_CTRL_SubPart1_shift                                                 (8)
#define IPMD_NPM_CTRL_SubPart1_mask                                                  (0x00000F00)
#define IPMD_NPM_CTRL_SubPart1(data)                                                 (0x00000F00&((data)<<8))
#define IPMD_NPM_CTRL_SubPart1_src(data)                                             ((0x00000F00&(data))>>8)
#define IPMD_NPM_CTRL_get_SubPart1(data)                                             ((0x00000F00&(data))>>8)
#define IPMD_NPM_CTRL_SubPart2_shift                                                 (4)
#define IPMD_NPM_CTRL_SubPart2_mask                                                  (0x000000F0)
#define IPMD_NPM_CTRL_SubPart2(data)                                                 (0x000000F0&((data)<<4))
#define IPMD_NPM_CTRL_SubPart2_src(data)                                             ((0x000000F0&(data))>>4)
#define IPMD_NPM_CTRL_get_SubPart2(data)                                             ((0x000000F0&(data))>>4)
#define IPMD_NPM_CTRL_SubPart3_shift                                                 (0)
#define IPMD_NPM_CTRL_SubPart3_mask                                                  (0x0000000F)
#define IPMD_NPM_CTRL_SubPart3(data)                                                 (0x0000000F&((data)<<0))
#define IPMD_NPM_CTRL_SubPart3_src(data)                                             ((0x0000000F&(data))>>0)
#define IPMD_NPM_CTRL_get_SubPart3(data)                                             ((0x0000000F&(data))>>0)


#define IPMD_ULPRED                                                                  0x18036170
#define IPMD_ULPRED_reg_addr                                                         "0xB8036170"
#define IPMD_ULPRED_reg                                                              0xB8036170
#define set_IPMD_ULPRED_reg(data)   (*((volatile unsigned int*) IPMD_ULPRED_reg)=data)
#define get_IPMD_ULPRED_reg   (*((volatile unsigned int*) IPMD_ULPRED_reg))
#define IPMD_ULPRED_inst_adr                                                         "0x005C"
#define IPMD_ULPRED_inst                                                             0x005C
#define IPMD_ULPRED_Luma_wr_shift                                                    (26)
#define IPMD_ULPRED_Luma_wr_mask                                                     (0x04000000)
#define IPMD_ULPRED_Luma_wr(data)                                                    (0x04000000&((data)<<26))
#define IPMD_ULPRED_Luma_wr_src(data)                                                ((0x04000000&(data))>>26)
#define IPMD_ULPRED_get_Luma_wr(data)                                                ((0x04000000&(data))>>26)
#define IPMD_ULPRED_CB_wr_shift                                                      (25)
#define IPMD_ULPRED_CB_wr_mask                                                       (0x02000000)
#define IPMD_ULPRED_CB_wr(data)                                                      (0x02000000&((data)<<25))
#define IPMD_ULPRED_CB_wr_src(data)                                                  ((0x02000000&(data))>>25)
#define IPMD_ULPRED_get_CB_wr(data)                                                  ((0x02000000&(data))>>25)
#define IPMD_ULPRED_CR_wr_shift                                                      (24)
#define IPMD_ULPRED_CR_wr_mask                                                       (0x01000000)
#define IPMD_ULPRED_CR_wr(data)                                                      (0x01000000&((data)<<24))
#define IPMD_ULPRED_CR_wr_src(data)                                                  ((0x01000000&(data))>>24)
#define IPMD_ULPRED_get_CR_wr(data)                                                  ((0x01000000&(data))>>24)
#define IPMD_ULPRED_Luma_shift                                                       (16)
#define IPMD_ULPRED_Luma_mask                                                        (0x00FF0000)
#define IPMD_ULPRED_Luma(data)                                                       (0x00FF0000&((data)<<16))
#define IPMD_ULPRED_Luma_src(data)                                                   ((0x00FF0000&(data))>>16)
#define IPMD_ULPRED_get_Luma(data)                                                   ((0x00FF0000&(data))>>16)
#define IPMD_ULPRED_CB_shift                                                         (8)
#define IPMD_ULPRED_CB_mask                                                          (0x0000FF00)
#define IPMD_ULPRED_CB(data)                                                         (0x0000FF00&((data)<<8))
#define IPMD_ULPRED_CB_src(data)                                                     ((0x0000FF00&(data))>>8)
#define IPMD_ULPRED_get_CB(data)                                                     ((0x0000FF00&(data))>>8)
#define IPMD_ULPRED_CR_shift                                                         (0)
#define IPMD_ULPRED_CR_mask                                                          (0x000000FF)
#define IPMD_ULPRED_CR(data)                                                         (0x000000FF&((data)<<0))
#define IPMD_ULPRED_CR_src(data)                                                     ((0x000000FF&(data))>>0)
#define IPMD_ULPRED_get_CR(data)                                                     ((0x000000FF&(data))>>0)


#define IPMD_CBPCTRL                                                                 0x18036174
#define IPMD_CBPCTRL_reg_addr                                                        "0xB8036174"
#define IPMD_CBPCTRL_reg                                                             0xB8036174
#define set_IPMD_CBPCTRL_reg(data)   (*((volatile unsigned int*) IPMD_CBPCTRL_reg)=data)
#define get_IPMD_CBPCTRL_reg   (*((volatile unsigned int*) IPMD_CBPCTRL_reg))
#define IPMD_CBPCTRL_inst_adr                                                        "0x005D"
#define IPMD_CBPCTRL_inst                                                            0x005D
#define IPMD_CBPCTRL_IntraLumaStyleSel_shift                                         (5)
#define IPMD_CBPCTRL_IntraLumaStyleSel_mask                                          (0x00000020)
#define IPMD_CBPCTRL_IntraLumaStyleSel(data)                                         (0x00000020&((data)<<5))
#define IPMD_CBPCTRL_IntraLumaStyleSel_src(data)                                     ((0x00000020&(data))>>5)
#define IPMD_CBPCTRL_get_IntraLumaStyleSel(data)                                     ((0x00000020&(data))>>5)


#define IPMD_SUMRUNCOST_4X4_0                                                        0x18036198
#define IPMD_SUMRUNCOST_4X4_1                                                        0x1803619C
#define IPMD_SUMRUNCOST_4X4_0_reg_addr                                               "0xB8036198"
#define IPMD_SUMRUNCOST_4X4_1_reg_addr                                               "0xB803619C"
#define IPMD_SUMRUNCOST_4X4_0_reg                                                    0xB8036198
#define IPMD_SUMRUNCOST_4X4_1_reg                                                    0xB803619C
#define set_IPMD_SUMRUNCOST_4X4_0_reg(data)   (*((volatile unsigned int*) IPMD_SUMRUNCOST_4X4_0_reg)=data)
#define set_IPMD_SUMRUNCOST_4X4_1_reg(data)   (*((volatile unsigned int*) IPMD_SUMRUNCOST_4X4_1_reg)=data)
#define get_IPMD_SUMRUNCOST_4X4_0_reg   (*((volatile unsigned int*) IPMD_SUMRUNCOST_4X4_0_reg))
#define get_IPMD_SUMRUNCOST_4X4_1_reg   (*((volatile unsigned int*) IPMD_SUMRUNCOST_4X4_1_reg))
#define IPMD_SUMRUNCOST_4X4_0_inst_adr                                               "0x0066"
#define IPMD_SUMRUNCOST_4X4_1_inst_adr                                               "0x0067"
#define IPMD_SUMRUNCOST_4X4_0_inst                                                   0x0066
#define IPMD_SUMRUNCOST_4X4_1_inst                                                   0x0067
#define IPMD_SUMRUNCOST_4X4_Lookup_shift                                             (0)
#define IPMD_SUMRUNCOST_4X4_Lookup_mask                                              (0xFFFFFFFF)
#define IPMD_SUMRUNCOST_4X4_Lookup(data)                                             (0xFFFFFFFF&((data)<<0))
#define IPMD_SUMRUNCOST_4X4_Lookup_src(data)                                         ((0xFFFFFFFF&(data))>>0)
#define IPMD_SUMRUNCOST_4X4_get_Lookup(data)                                         ((0xFFFFFFFF&(data))>>0)


#define IPMD_MBLEVEL_DROP                                                            0x180361A0
#define IPMD_MBLEVEL_DROP_reg_addr                                                   "0xB80361A0"
#define IPMD_MBLEVEL_DROP_reg                                                        0xB80361A0
#define set_IPMD_MBLEVEL_DROP_reg(data)   (*((volatile unsigned int*) IPMD_MBLEVEL_DROP_reg)=data)
#define get_IPMD_MBLEVEL_DROP_reg   (*((volatile unsigned int*) IPMD_MBLEVEL_DROP_reg))
#define IPMD_MBLEVEL_DROP_inst_adr                                                   "0x0068"
#define IPMD_MBLEVEL_DROP_inst                                                       0x0068
#define IPMD_MBLEVEL_DROP_Enable_shift                                               (13)
#define IPMD_MBLEVEL_DROP_Enable_mask                                                (0x00002000)
#define IPMD_MBLEVEL_DROP_Enable(data)                                               (0x00002000&((data)<<13))
#define IPMD_MBLEVEL_DROP_Enable_src(data)                                           ((0x00002000&(data))>>13)
#define IPMD_MBLEVEL_DROP_get_Enable(data)                                           ((0x00002000&(data))>>13)
#define IPMD_MBLEVEL_DROP_Thresh_shift                                               (0)
#define IPMD_MBLEVEL_DROP_Thresh_mask                                                (0x00001FFF)
#define IPMD_MBLEVEL_DROP_Thresh(data)                                               (0x00001FFF&((data)<<0))
#define IPMD_MBLEVEL_DROP_Thresh_src(data)                                           ((0x00001FFF&(data))>>0)
#define IPMD_MBLEVEL_DROP_get_Thresh(data)                                           ((0x00001FFF&(data))>>0)


#define IPMD_QUANTIZER                                                               0x180361A4
#define IPMD_QUANTIZER_reg_addr                                                      "0xB80361A4"
#define IPMD_QUANTIZER_reg                                                           0xB80361A4
#define set_IPMD_QUANTIZER_reg(data)   (*((volatile unsigned int*) IPMD_QUANTIZER_reg)=data)
#define get_IPMD_QUANTIZER_reg   (*((volatile unsigned int*) IPMD_QUANTIZER_reg))
#define IPMD_QUANTIZER_inst_adr                                                      "0x0069"
#define IPMD_QUANTIZER_inst                                                          0x0069
#define IPMD_QUANTIZER_write_enable3_shift                                           (15)
#define IPMD_QUANTIZER_write_enable3_mask                                            (0x00008000)
#define IPMD_QUANTIZER_write_enable3(data)                                           (0x00008000&((data)<<15))
#define IPMD_QUANTIZER_write_enable3_src(data)                                       ((0x00008000&(data))>>15)
#define IPMD_QUANTIZER_get_write_enable3(data)                                       ((0x00008000&(data))>>15)
#define IPMD_QUANTIZER_flat_qtable_shift                                             (14)
#define IPMD_QUANTIZER_flat_qtable_mask                                              (0x00004000)
#define IPMD_QUANTIZER_flat_qtable(data)                                             (0x00004000&((data)<<14))
#define IPMD_QUANTIZER_flat_qtable_src(data)                                         ((0x00004000&(data))>>14)
#define IPMD_QUANTIZER_get_flat_qtable(data)                                         ((0x00004000&(data))>>14)
#define IPMD_QUANTIZER_write_enable2_shift                                           (13)
#define IPMD_QUANTIZER_write_enable2_mask                                            (0x00002000)
#define IPMD_QUANTIZER_write_enable2(data)                                           (0x00002000&((data)<<13))
#define IPMD_QUANTIZER_write_enable2_src(data)                                       ((0x00002000&(data))>>13)
#define IPMD_QUANTIZER_get_write_enable2(data)                                       ((0x00002000&(data))>>13)
#define IPMD_QUANTIZER_qpy_shift                                                     (7)
#define IPMD_QUANTIZER_qpy_mask                                                      (0x00001F80)
#define IPMD_QUANTIZER_qpy(data)                                                     (0x00001F80&((data)<<7))
#define IPMD_QUANTIZER_qpy_src(data)                                                 ((0x00001F80&(data))>>7)
#define IPMD_QUANTIZER_get_qpy(data)                                                 ((0x00001F80&(data))>>7)
#define IPMD_QUANTIZER_write_enable1_shift                                           (6)
#define IPMD_QUANTIZER_write_enable1_mask                                            (0x00000040)
#define IPMD_QUANTIZER_write_enable1(data)                                           (0x00000040&((data)<<6))
#define IPMD_QUANTIZER_write_enable1_src(data)                                       ((0x00000040&(data))>>6)
#define IPMD_QUANTIZER_get_write_enable1(data)                                       ((0x00000040&(data))>>6)
#define IPMD_QUANTIZER_qpc_shift                                                     (0)
#define IPMD_QUANTIZER_qpc_mask                                                      (0x0000003F)
#define IPMD_QUANTIZER_qpc(data)                                                     (0x0000003F&((data)<<0))
#define IPMD_QUANTIZER_qpc_src(data)                                                 ((0x0000003F&(data))>>0)
#define IPMD_QUANTIZER_get_qpc(data)                                                 ((0x0000003F&(data))>>0)


#define IPMD_MBINFO                                                                  0x180361A8
#define IPMD_MBINFO_reg_addr                                                         "0xB80361A8"
#define IPMD_MBINFO_reg                                                              0xB80361A8
#define set_IPMD_MBINFO_reg(data)   (*((volatile unsigned int*) IPMD_MBINFO_reg)=data)
#define get_IPMD_MBINFO_reg   (*((volatile unsigned int*) IPMD_MBINFO_reg))
#define IPMD_MBINFO_inst_adr                                                         "0x006A"
#define IPMD_MBINFO_inst                                                             0x006A
#define IPMD_MBINFO_PictureType_shift                                                (21)
#define IPMD_MBINFO_PictureType_mask                                                 (0x00600000)
#define IPMD_MBINFO_PictureType(data)                                                (0x00600000&((data)<<21))
#define IPMD_MBINFO_PictureType_src(data)                                            ((0x00600000&(data))>>21)
#define IPMD_MBINFO_get_PictureType(data)                                            ((0x00600000&(data))>>21)


#define IPMD_CBP                                                                     0x180361AC
#define IPMD_CBP_reg_addr                                                            "0xB80361AC"
#define IPMD_CBP_reg                                                                 0xB80361AC
#define set_IPMD_CBP_reg(data)   (*((volatile unsigned int*) IPMD_CBP_reg)=data)
#define get_IPMD_CBP_reg   (*((volatile unsigned int*) IPMD_CBP_reg))
#define IPMD_CBP_inst_adr                                                            "0x006B"
#define IPMD_CBP_inst                                                                0x006B
#define IPMD_CBP_cbp_stay_shift                                                      (4)
#define IPMD_CBP_cbp_stay_mask                                                       (0x000000F0)
#define IPMD_CBP_cbp_stay(data)                                                      (0x000000F0&((data)<<4))
#define IPMD_CBP_cbp_stay_src(data)                                                  ((0x000000F0&(data))>>4)
#define IPMD_CBP_get_cbp_stay(data)                                                  ((0x000000F0&(data))>>4)
#define IPMD_CBP_cbp_base_shift                                                      (0)
#define IPMD_CBP_cbp_base_mask                                                       (0x0000000F)
#define IPMD_CBP_cbp_base(data)                                                      (0x0000000F&((data)<<0))
#define IPMD_CBP_cbp_base_src(data)                                                  ((0x0000000F&(data))>>0)
#define IPMD_CBP_get_cbp_base(data)                                                  ((0x0000000F&(data))>>0)


#endif
