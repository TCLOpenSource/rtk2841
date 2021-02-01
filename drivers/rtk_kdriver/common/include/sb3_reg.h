/**************************************************************
// Spec Version                  : 0.1.0
// Parser Version                : DVR_Parser_6.8(110516)
// CModelGen Version             : 5.0 2009.04.09
// Naming Rule                   :  Register_Name
// Naming Rule                   : Module_Register_Name_reg
// Parse Option                  : Only Parse _op1
// Parse Address Region          : 0X1801C200  ~  0X1801C300
// Decode bit number             : 12 bits
// Firmware Header Generate Date : 2012/8/9 21:17:40
***************************************************************/


#ifndef _SB3_REG_H_INCLUDED_
#define _SB3_REG_H_INCLUDED_
#ifdef  _SB3_USE_STRUCT
typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     sb3_c0_latcnt_end:12;
unsigned int     reserved_1:4;
unsigned int     sb3_c0_latcnt_beg:12;
}SB3_PRI0;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     sb3_c1_latcnt_end:12;
unsigned int     reserved_1:4;
unsigned int     sb3_c1_latcnt_beg:12;
}SB3_PRI1;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     sb3_c2_latcnt_end:12;
unsigned int     reserved_1:4;
unsigned int     sb3_c2_latcnt_beg:12;
}SB3_PRI2;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     sb3_c3_latcnt_end:12;
unsigned int     reserved_1:4;
unsigned int     sb3_c3_latcnt_beg:12;
}SB3_PRI3;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     sb3_c4_latcnt_end:12;
unsigned int     reserved_1:4;
unsigned int     sb3_c4_latcnt_beg:12;
}SB3_PRI4;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     sb3_c5_latcnt_end:12;
unsigned int     reserved_1:4;
unsigned int     sb3_c5_latcnt_beg:12;
}SB3_PRI5;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     sb3_c6_latcnt_end:12;
unsigned int     reserved_1:4;
unsigned int     sb3_c6_latcnt_beg:12;
}SB3_PRI6;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     sb3_c7_latcnt_end:12;
unsigned int     reserved_1:4;
unsigned int     sb3_c7_latcnt_beg:12;
}SB3_PRI7;

typedef struct 
{
unsigned int     reserved_0:20;
unsigned int     sb3_pri_cnt_period:12;
}SB3_PRI8;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     sb3_req_mask_index:8;
}SB3_CHANNEL0;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     sb3_req_busy_index:8;
}SB3_CHANNEL1;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     sb3_allow_cmd_cnt:3;
}SB3_MISC_CTRL;

#endif

#define SB3_PRI0                                                                      0x1801C200
#define SB3_PRI0_reg_addr                                                             "0xB801C200"
#define SB3_PRI0_reg                                                                  0xB801C200
#define set_SB3_PRI0_reg(data)   (*((volatile unsigned int*) SB3_PRI0_reg)=data)
#define get_SB3_PRI0_reg   (*((volatile unsigned int*) SB3_PRI0_reg))
#define SB3_PRI0_inst_adr                                                             "0x0080"
#define SB3_PRI0_inst                                                                 0x0080
#define SB3_PRI0_sb3_c0_latcnt_end_shift                                              (16)
#define SB3_PRI0_sb3_c0_latcnt_end_mask                                               (0x0FFF0000)
#define SB3_PRI0_sb3_c0_latcnt_end(data)                                              (0x0FFF0000&((data)<<16))
#define SB3_PRI0_sb3_c0_latcnt_end_src(data)                                          ((0x0FFF0000&(data))>>16)
#define SB3_PRI0_get_sb3_c0_latcnt_end(data)                                          ((0x0FFF0000&(data))>>16)
#define SB3_PRI0_sb3_c0_latcnt_beg_shift                                              (0)
#define SB3_PRI0_sb3_c0_latcnt_beg_mask                                               (0x00000FFF)
#define SB3_PRI0_sb3_c0_latcnt_beg(data)                                              (0x00000FFF&((data)<<0))
#define SB3_PRI0_sb3_c0_latcnt_beg_src(data)                                          ((0x00000FFF&(data))>>0)
#define SB3_PRI0_get_sb3_c0_latcnt_beg(data)                                          ((0x00000FFF&(data))>>0)


#define SB3_PRI1                                                                      0x1801C204
#define SB3_PRI1_reg_addr                                                             "0xB801C204"
#define SB3_PRI1_reg                                                                  0xB801C204
#define set_SB3_PRI1_reg(data)   (*((volatile unsigned int*) SB3_PRI1_reg)=data)
#define get_SB3_PRI1_reg   (*((volatile unsigned int*) SB3_PRI1_reg))
#define SB3_PRI1_inst_adr                                                             "0x0081"
#define SB3_PRI1_inst                                                                 0x0081
#define SB3_PRI1_sb3_c1_latcnt_end_shift                                              (16)
#define SB3_PRI1_sb3_c1_latcnt_end_mask                                               (0x0FFF0000)
#define SB3_PRI1_sb3_c1_latcnt_end(data)                                              (0x0FFF0000&((data)<<16))
#define SB3_PRI1_sb3_c1_latcnt_end_src(data)                                          ((0x0FFF0000&(data))>>16)
#define SB3_PRI1_get_sb3_c1_latcnt_end(data)                                          ((0x0FFF0000&(data))>>16)
#define SB3_PRI1_sb3_c1_latcnt_beg_shift                                              (0)
#define SB3_PRI1_sb3_c1_latcnt_beg_mask                                               (0x00000FFF)
#define SB3_PRI1_sb3_c1_latcnt_beg(data)                                              (0x00000FFF&((data)<<0))
#define SB3_PRI1_sb3_c1_latcnt_beg_src(data)                                          ((0x00000FFF&(data))>>0)
#define SB3_PRI1_get_sb3_c1_latcnt_beg(data)                                          ((0x00000FFF&(data))>>0)


#define SB3_PRI2                                                                      0x1801C208
#define SB3_PRI2_reg_addr                                                             "0xB801C208"
#define SB3_PRI2_reg                                                                  0xB801C208
#define set_SB3_PRI2_reg(data)   (*((volatile unsigned int*) SB3_PRI2_reg)=data)
#define get_SB3_PRI2_reg   (*((volatile unsigned int*) SB3_PRI2_reg))
#define SB3_PRI2_inst_adr                                                             "0x0082"
#define SB3_PRI2_inst                                                                 0x0082
#define SB3_PRI2_sb3_c2_latcnt_end_shift                                              (16)
#define SB3_PRI2_sb3_c2_latcnt_end_mask                                               (0x0FFF0000)
#define SB3_PRI2_sb3_c2_latcnt_end(data)                                              (0x0FFF0000&((data)<<16))
#define SB3_PRI2_sb3_c2_latcnt_end_src(data)                                          ((0x0FFF0000&(data))>>16)
#define SB3_PRI2_get_sb3_c2_latcnt_end(data)                                          ((0x0FFF0000&(data))>>16)
#define SB3_PRI2_sb3_c2_latcnt_beg_shift                                              (0)
#define SB3_PRI2_sb3_c2_latcnt_beg_mask                                               (0x00000FFF)
#define SB3_PRI2_sb3_c2_latcnt_beg(data)                                              (0x00000FFF&((data)<<0))
#define SB3_PRI2_sb3_c2_latcnt_beg_src(data)                                          ((0x00000FFF&(data))>>0)
#define SB3_PRI2_get_sb3_c2_latcnt_beg(data)                                          ((0x00000FFF&(data))>>0)


#define SB3_PRI3                                                                      0x1801C20C
#define SB3_PRI3_reg_addr                                                             "0xB801C20C"
#define SB3_PRI3_reg                                                                  0xB801C20C
#define set_SB3_PRI3_reg(data)   (*((volatile unsigned int*) SB3_PRI3_reg)=data)
#define get_SB3_PRI3_reg   (*((volatile unsigned int*) SB3_PRI3_reg))
#define SB3_PRI3_inst_adr                                                             "0x0083"
#define SB3_PRI3_inst                                                                 0x0083
#define SB3_PRI3_sb3_c3_latcnt_end_shift                                              (16)
#define SB3_PRI3_sb3_c3_latcnt_end_mask                                               (0x0FFF0000)
#define SB3_PRI3_sb3_c3_latcnt_end(data)                                              (0x0FFF0000&((data)<<16))
#define SB3_PRI3_sb3_c3_latcnt_end_src(data)                                          ((0x0FFF0000&(data))>>16)
#define SB3_PRI3_get_sb3_c3_latcnt_end(data)                                          ((0x0FFF0000&(data))>>16)
#define SB3_PRI3_sb3_c3_latcnt_beg_shift                                              (0)
#define SB3_PRI3_sb3_c3_latcnt_beg_mask                                               (0x00000FFF)
#define SB3_PRI3_sb3_c3_latcnt_beg(data)                                              (0x00000FFF&((data)<<0))
#define SB3_PRI3_sb3_c3_latcnt_beg_src(data)                                          ((0x00000FFF&(data))>>0)
#define SB3_PRI3_get_sb3_c3_latcnt_beg(data)                                          ((0x00000FFF&(data))>>0)


#define SB3_PRI4                                                                      0x1801C210
#define SB3_PRI4_reg_addr                                                             "0xB801C210"
#define SB3_PRI4_reg                                                                  0xB801C210
#define set_SB3_PRI4_reg(data)   (*((volatile unsigned int*) SB3_PRI4_reg)=data)
#define get_SB3_PRI4_reg   (*((volatile unsigned int*) SB3_PRI4_reg))
#define SB3_PRI4_inst_adr                                                             "0x0084"
#define SB3_PRI4_inst                                                                 0x0084
#define SB3_PRI4_sb3_c4_latcnt_end_shift                                              (16)
#define SB3_PRI4_sb3_c4_latcnt_end_mask                                               (0x0FFF0000)
#define SB3_PRI4_sb3_c4_latcnt_end(data)                                              (0x0FFF0000&((data)<<16))
#define SB3_PRI4_sb3_c4_latcnt_end_src(data)                                          ((0x0FFF0000&(data))>>16)
#define SB3_PRI4_get_sb3_c4_latcnt_end(data)                                          ((0x0FFF0000&(data))>>16)
#define SB3_PRI4_sb3_c4_latcnt_beg_shift                                              (0)
#define SB3_PRI4_sb3_c4_latcnt_beg_mask                                               (0x00000FFF)
#define SB3_PRI4_sb3_c4_latcnt_beg(data)                                              (0x00000FFF&((data)<<0))
#define SB3_PRI4_sb3_c4_latcnt_beg_src(data)                                          ((0x00000FFF&(data))>>0)
#define SB3_PRI4_get_sb3_c4_latcnt_beg(data)                                          ((0x00000FFF&(data))>>0)


#define SB3_PRI5                                                                      0x1801C214
#define SB3_PRI5_reg_addr                                                             "0xB801C214"
#define SB3_PRI5_reg                                                                  0xB801C214
#define set_SB3_PRI5_reg(data)   (*((volatile unsigned int*) SB3_PRI5_reg)=data)
#define get_SB3_PRI5_reg   (*((volatile unsigned int*) SB3_PRI5_reg))
#define SB3_PRI5_inst_adr                                                             "0x0085"
#define SB3_PRI5_inst                                                                 0x0085
#define SB3_PRI5_sb3_c5_latcnt_end_shift                                              (16)
#define SB3_PRI5_sb3_c5_latcnt_end_mask                                               (0x0FFF0000)
#define SB3_PRI5_sb3_c5_latcnt_end(data)                                              (0x0FFF0000&((data)<<16))
#define SB3_PRI5_sb3_c5_latcnt_end_src(data)                                          ((0x0FFF0000&(data))>>16)
#define SB3_PRI5_get_sb3_c5_latcnt_end(data)                                          ((0x0FFF0000&(data))>>16)
#define SB3_PRI5_sb3_c5_latcnt_beg_shift                                              (0)
#define SB3_PRI5_sb3_c5_latcnt_beg_mask                                               (0x00000FFF)
#define SB3_PRI5_sb3_c5_latcnt_beg(data)                                              (0x00000FFF&((data)<<0))
#define SB3_PRI5_sb3_c5_latcnt_beg_src(data)                                          ((0x00000FFF&(data))>>0)
#define SB3_PRI5_get_sb3_c5_latcnt_beg(data)                                          ((0x00000FFF&(data))>>0)


#define SB3_PRI6                                                                      0x1801C218
#define SB3_PRI6_reg_addr                                                             "0xB801C218"
#define SB3_PRI6_reg                                                                  0xB801C218
#define set_SB3_PRI6_reg(data)   (*((volatile unsigned int*) SB3_PRI6_reg)=data)
#define get_SB3_PRI6_reg   (*((volatile unsigned int*) SB3_PRI6_reg))
#define SB3_PRI6_inst_adr                                                             "0x0086"
#define SB3_PRI6_inst                                                                 0x0086
#define SB3_PRI6_sb3_c6_latcnt_end_shift                                              (16)
#define SB3_PRI6_sb3_c6_latcnt_end_mask                                               (0x0FFF0000)
#define SB3_PRI6_sb3_c6_latcnt_end(data)                                              (0x0FFF0000&((data)<<16))
#define SB3_PRI6_sb3_c6_latcnt_end_src(data)                                          ((0x0FFF0000&(data))>>16)
#define SB3_PRI6_get_sb3_c6_latcnt_end(data)                                          ((0x0FFF0000&(data))>>16)
#define SB3_PRI6_sb3_c6_latcnt_beg_shift                                              (0)
#define SB3_PRI6_sb3_c6_latcnt_beg_mask                                               (0x00000FFF)
#define SB3_PRI6_sb3_c6_latcnt_beg(data)                                              (0x00000FFF&((data)<<0))
#define SB3_PRI6_sb3_c6_latcnt_beg_src(data)                                          ((0x00000FFF&(data))>>0)
#define SB3_PRI6_get_sb3_c6_latcnt_beg(data)                                          ((0x00000FFF&(data))>>0)


#define SB3_PRI7                                                                      0x1801C21C
#define SB3_PRI7_reg_addr                                                             "0xB801C21C"
#define SB3_PRI7_reg                                                                  0xB801C21C
#define set_SB3_PRI7_reg(data)   (*((volatile unsigned int*) SB3_PRI7_reg)=data)
#define get_SB3_PRI7_reg   (*((volatile unsigned int*) SB3_PRI7_reg))
#define SB3_PRI7_inst_adr                                                             "0x0087"
#define SB3_PRI7_inst                                                                 0x0087
#define SB3_PRI7_sb3_c7_latcnt_end_shift                                              (16)
#define SB3_PRI7_sb3_c7_latcnt_end_mask                                               (0x0FFF0000)
#define SB3_PRI7_sb3_c7_latcnt_end(data)                                              (0x0FFF0000&((data)<<16))
#define SB3_PRI7_sb3_c7_latcnt_end_src(data)                                          ((0x0FFF0000&(data))>>16)
#define SB3_PRI7_get_sb3_c7_latcnt_end(data)                                          ((0x0FFF0000&(data))>>16)
#define SB3_PRI7_sb3_c7_latcnt_beg_shift                                              (0)
#define SB3_PRI7_sb3_c7_latcnt_beg_mask                                               (0x00000FFF)
#define SB3_PRI7_sb3_c7_latcnt_beg(data)                                              (0x00000FFF&((data)<<0))
#define SB3_PRI7_sb3_c7_latcnt_beg_src(data)                                          ((0x00000FFF&(data))>>0)
#define SB3_PRI7_get_sb3_c7_latcnt_beg(data)                                          ((0x00000FFF&(data))>>0)


#define SB3_PRI8                                                                      0x1801C220
#define SB3_PRI8_reg_addr                                                             "0xB801C220"
#define SB3_PRI8_reg                                                                  0xB801C220
#define set_SB3_PRI8_reg(data)   (*((volatile unsigned int*) SB3_PRI8_reg)=data)
#define get_SB3_PRI8_reg   (*((volatile unsigned int*) SB3_PRI8_reg))
#define SB3_PRI8_inst_adr                                                             "0x0088"
#define SB3_PRI8_inst                                                                 0x0088
#define SB3_PRI8_sb3_pri_cnt_period_shift                                             (0)
#define SB3_PRI8_sb3_pri_cnt_period_mask                                              (0x00000FFF)
#define SB3_PRI8_sb3_pri_cnt_period(data)                                             (0x00000FFF&((data)<<0))
#define SB3_PRI8_sb3_pri_cnt_period_src(data)                                         ((0x00000FFF&(data))>>0)
#define SB3_PRI8_get_sb3_pri_cnt_period(data)                                         ((0x00000FFF&(data))>>0)


#define SB3_CHANNEL0                                                                  0x1801C224
#define SB3_CHANNEL0_reg_addr                                                         "0xB801C224"
#define SB3_CHANNEL0_reg                                                              0xB801C224
#define set_SB3_CHANNEL0_reg(data)   (*((volatile unsigned int*) SB3_CHANNEL0_reg)=data)
#define get_SB3_CHANNEL0_reg   (*((volatile unsigned int*) SB3_CHANNEL0_reg))
#define SB3_CHANNEL0_inst_adr                                                         "0x0089"
#define SB3_CHANNEL0_inst                                                             0x0089
#define SB3_CHANNEL0_sb3_req_mask_index_shift                                         (0)
#define SB3_CHANNEL0_sb3_req_mask_index_mask                                          (0x000000FF)
#define SB3_CHANNEL0_sb3_req_mask_index(data)                                         (0x000000FF&((data)<<0))
#define SB3_CHANNEL0_sb3_req_mask_index_src(data)                                     ((0x000000FF&(data))>>0)
#define SB3_CHANNEL0_get_sb3_req_mask_index(data)                                     ((0x000000FF&(data))>>0)


#define SB3_CHANNEL1                                                                  0x1801C228
#define SB3_CHANNEL1_reg_addr                                                         "0xB801C228"
#define SB3_CHANNEL1_reg                                                              0xB801C228
#define set_SB3_CHANNEL1_reg(data)   (*((volatile unsigned int*) SB3_CHANNEL1_reg)=data)
#define get_SB3_CHANNEL1_reg   (*((volatile unsigned int*) SB3_CHANNEL1_reg))
#define SB3_CHANNEL1_inst_adr                                                         "0x008A"
#define SB3_CHANNEL1_inst                                                             0x008A
#define SB3_CHANNEL1_sb3_req_busy_index_shift                                         (0)
#define SB3_CHANNEL1_sb3_req_busy_index_mask                                          (0x000000FF)
#define SB3_CHANNEL1_sb3_req_busy_index(data)                                         (0x000000FF&((data)<<0))
#define SB3_CHANNEL1_sb3_req_busy_index_src(data)                                     ((0x000000FF&(data))>>0)
#define SB3_CHANNEL1_get_sb3_req_busy_index(data)                                     ((0x000000FF&(data))>>0)


#define SB3_MISC_CTRL                                                                0x1801C22C
#define SB3_MISC_CTRL_reg_addr                                                       "0xB801C22C"
#define SB3_MISC_CTRL_reg                                                            0xB801C22C
#define set_SB3_MISC_CTRL_reg(data)   (*((volatile unsigned int*) SB3_MISC_CTRL_reg)=data)
#define get_SB3_MISC_CTRL_reg   (*((volatile unsigned int*) SB3_MISC_CTRL_reg))
#define SB3_MISC_CTRL_inst_adr                                                       "0x008B"
#define SB3_MISC_CTRL_inst                                                           0x008B
#define SB3_MISC_CTRL_sb3_allow_cmd_cnt_shift                                        (0)
#define SB3_MISC_CTRL_sb3_allow_cmd_cnt_mask                                         (0x00000007)
#define SB3_MISC_CTRL_sb3_allow_cmd_cnt(data)                                        (0x00000007&((data)<<0))
#define SB3_MISC_CTRL_sb3_allow_cmd_cnt_src(data)                                    ((0x00000007&(data))>>0)
#define SB3_MISC_CTRL_get_sb3_allow_cmd_cnt(data)                                    ((0x00000007&(data))>>0)


#endif
