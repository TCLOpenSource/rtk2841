/**************************************************************
// Spec Version                  : 0.1.0
// Parser Version                : DVR_Parser_6.8(110516)
// CModelGen Version             : 5.0 2009.04.09
// Naming Rule                   :  Register_Name
// Naming Rule                   : Module_Register_Name_reg
// Parse Option                  : Only Parse _op1
// Parse Address Region          : 0X1801C000  ~  0X1801C100
// Decode bit number             : 12 bits
// Firmware Header Generate Date : 2012/8/9 21:16:6
***************************************************************/


#ifndef _SB1_REG_H_INCLUDED_
#define _SB1_REG_H_INCLUDED_
#ifdef  _SB1_USE_STRUCT
typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     sb1_c0_latcnt_end:12;
unsigned int     reserved_1:4;
unsigned int     sb1_c0_latcnt_beg:12;
}SB1_PRI0;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     sb1_c1_latcnt_end:12;
unsigned int     reserved_1:4;
unsigned int     sb1_c1_latcnt_beg:12;
}SB1_PRI1;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     sb1_c2_latcnt_end:12;
unsigned int     reserved_1:4;
unsigned int     sb1_c2_latcnt_beg:12;
}SB1_PRI2;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     sb1_c3_latcnt_end:12;
unsigned int     reserved_1:4;
unsigned int     sb1_c3_latcnt_beg:12;
}SB1_PRI3;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     sb1_c4_latcnt_end:12;
unsigned int     reserved_1:4;
unsigned int     sb1_c4_latcnt_beg:12;
}SB1_PRI4;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     sb1_c5_latcnt_end:12;
unsigned int     reserved_1:4;
unsigned int     sb1_c5_latcnt_beg:12;
}SB1_PRI5;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     sb1_c6_latcnt_end:12;
unsigned int     reserved_1:4;
unsigned int     sb1_c6_latcnt_beg:12;
}SB1_PRI6;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     sb1_c7_latcnt_end:12;
unsigned int     reserved_1:4;
unsigned int     sb1_c7_latcnt_beg:12;
}SB1_PRI7;

typedef struct 
{
unsigned int     reserved_0:20;
unsigned int     sb1_pri_cnt_period:12;
}SB1_PRI8;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     sb1_req_mask_index:8;
}SB1_CHANNEL0;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     sb1_req_busy_index:8;
}SB1_CHANNEL1;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     sb1_allow_cmd_cnt:3;
}SB1_MISC_CTRL;

#endif

#define SB1_PRI0                                                                      0x1801C000
#define SB1_PRI0_reg_addr                                                             "0xB801C000"
#define SB1_PRI0_reg                                                                  0xB801C000
#define set_SB1_PRI0_reg(data)   (*((volatile unsigned int*) SB1_PRI0_reg)=data)
#define get_SB1_PRI0_reg   (*((volatile unsigned int*) SB1_PRI0_reg))
#define SB1_PRI0_inst_adr                                                             "0x0000"
#define SB1_PRI0_inst                                                                 0x0000
#define SB1_PRI0_sb1_c0_latcnt_end_shift                                              (16)
#define SB1_PRI0_sb1_c0_latcnt_end_mask                                               (0x0FFF0000)
#define SB1_PRI0_sb1_c0_latcnt_end(data)                                              (0x0FFF0000&((data)<<16))
#define SB1_PRI0_sb1_c0_latcnt_end_src(data)                                          ((0x0FFF0000&(data))>>16)
#define SB1_PRI0_get_sb1_c0_latcnt_end(data)                                          ((0x0FFF0000&(data))>>16)
#define SB1_PRI0_sb1_c0_latcnt_beg_shift                                              (0)
#define SB1_PRI0_sb1_c0_latcnt_beg_mask                                               (0x00000FFF)
#define SB1_PRI0_sb1_c0_latcnt_beg(data)                                              (0x00000FFF&((data)<<0))
#define SB1_PRI0_sb1_c0_latcnt_beg_src(data)                                          ((0x00000FFF&(data))>>0)
#define SB1_PRI0_get_sb1_c0_latcnt_beg(data)                                          ((0x00000FFF&(data))>>0)


#define SB1_PRI1                                                                      0x1801C004
#define SB1_PRI1_reg_addr                                                             "0xB801C004"
#define SB1_PRI1_reg                                                                  0xB801C004
#define set_SB1_PRI1_reg(data)   (*((volatile unsigned int*) SB1_PRI1_reg)=data)
#define get_SB1_PRI1_reg   (*((volatile unsigned int*) SB1_PRI1_reg))
#define SB1_PRI1_inst_adr                                                             "0x0001"
#define SB1_PRI1_inst                                                                 0x0001
#define SB1_PRI1_sb1_c1_latcnt_end_shift                                              (16)
#define SB1_PRI1_sb1_c1_latcnt_end_mask                                               (0x0FFF0000)
#define SB1_PRI1_sb1_c1_latcnt_end(data)                                              (0x0FFF0000&((data)<<16))
#define SB1_PRI1_sb1_c1_latcnt_end_src(data)                                          ((0x0FFF0000&(data))>>16)
#define SB1_PRI1_get_sb1_c1_latcnt_end(data)                                          ((0x0FFF0000&(data))>>16)
#define SB1_PRI1_sb1_c1_latcnt_beg_shift                                              (0)
#define SB1_PRI1_sb1_c1_latcnt_beg_mask                                               (0x00000FFF)
#define SB1_PRI1_sb1_c1_latcnt_beg(data)                                              (0x00000FFF&((data)<<0))
#define SB1_PRI1_sb1_c1_latcnt_beg_src(data)                                          ((0x00000FFF&(data))>>0)
#define SB1_PRI1_get_sb1_c1_latcnt_beg(data)                                          ((0x00000FFF&(data))>>0)


#define SB1_PRI2                                                                      0x1801C008
#define SB1_PRI2_reg_addr                                                             "0xB801C008"
#define SB1_PRI2_reg                                                                  0xB801C008
#define set_SB1_PRI2_reg(data)   (*((volatile unsigned int*) SB1_PRI2_reg)=data)
#define get_SB1_PRI2_reg   (*((volatile unsigned int*) SB1_PRI2_reg))
#define SB1_PRI2_inst_adr                                                             "0x0002"
#define SB1_PRI2_inst                                                                 0x0002
#define SB1_PRI2_sb1_c2_latcnt_end_shift                                              (16)
#define SB1_PRI2_sb1_c2_latcnt_end_mask                                               (0x0FFF0000)
#define SB1_PRI2_sb1_c2_latcnt_end(data)                                              (0x0FFF0000&((data)<<16))
#define SB1_PRI2_sb1_c2_latcnt_end_src(data)                                          ((0x0FFF0000&(data))>>16)
#define SB1_PRI2_get_sb1_c2_latcnt_end(data)                                          ((0x0FFF0000&(data))>>16)
#define SB1_PRI2_sb1_c2_latcnt_beg_shift                                              (0)
#define SB1_PRI2_sb1_c2_latcnt_beg_mask                                               (0x00000FFF)
#define SB1_PRI2_sb1_c2_latcnt_beg(data)                                              (0x00000FFF&((data)<<0))
#define SB1_PRI2_sb1_c2_latcnt_beg_src(data)                                          ((0x00000FFF&(data))>>0)
#define SB1_PRI2_get_sb1_c2_latcnt_beg(data)                                          ((0x00000FFF&(data))>>0)


#define SB1_PRI3                                                                      0x1801C00C
#define SB1_PRI3_reg_addr                                                             "0xB801C00C"
#define SB1_PRI3_reg                                                                  0xB801C00C
#define set_SB1_PRI3_reg(data)   (*((volatile unsigned int*) SB1_PRI3_reg)=data)
#define get_SB1_PRI3_reg   (*((volatile unsigned int*) SB1_PRI3_reg))
#define SB1_PRI3_inst_adr                                                             "0x0003"
#define SB1_PRI3_inst                                                                 0x0003
#define SB1_PRI3_sb1_c3_latcnt_end_shift                                              (16)
#define SB1_PRI3_sb1_c3_latcnt_end_mask                                               (0x0FFF0000)
#define SB1_PRI3_sb1_c3_latcnt_end(data)                                              (0x0FFF0000&((data)<<16))
#define SB1_PRI3_sb1_c3_latcnt_end_src(data)                                          ((0x0FFF0000&(data))>>16)
#define SB1_PRI3_get_sb1_c3_latcnt_end(data)                                          ((0x0FFF0000&(data))>>16)
#define SB1_PRI3_sb1_c3_latcnt_beg_shift                                              (0)
#define SB1_PRI3_sb1_c3_latcnt_beg_mask                                               (0x00000FFF)
#define SB1_PRI3_sb1_c3_latcnt_beg(data)                                              (0x00000FFF&((data)<<0))
#define SB1_PRI3_sb1_c3_latcnt_beg_src(data)                                          ((0x00000FFF&(data))>>0)
#define SB1_PRI3_get_sb1_c3_latcnt_beg(data)                                          ((0x00000FFF&(data))>>0)


#define SB1_PRI4                                                                      0x1801C010
#define SB1_PRI4_reg_addr                                                             "0xB801C010"
#define SB1_PRI4_reg                                                                  0xB801C010
#define set_SB1_PRI4_reg(data)   (*((volatile unsigned int*) SB1_PRI4_reg)=data)
#define get_SB1_PRI4_reg   (*((volatile unsigned int*) SB1_PRI4_reg))
#define SB1_PRI4_inst_adr                                                             "0x0004"
#define SB1_PRI4_inst                                                                 0x0004
#define SB1_PRI4_sb1_c4_latcnt_end_shift                                              (16)
#define SB1_PRI4_sb1_c4_latcnt_end_mask                                               (0x0FFF0000)
#define SB1_PRI4_sb1_c4_latcnt_end(data)                                              (0x0FFF0000&((data)<<16))
#define SB1_PRI4_sb1_c4_latcnt_end_src(data)                                          ((0x0FFF0000&(data))>>16)
#define SB1_PRI4_get_sb1_c4_latcnt_end(data)                                          ((0x0FFF0000&(data))>>16)
#define SB1_PRI4_sb1_c4_latcnt_beg_shift                                              (0)
#define SB1_PRI4_sb1_c4_latcnt_beg_mask                                               (0x00000FFF)
#define SB1_PRI4_sb1_c4_latcnt_beg(data)                                              (0x00000FFF&((data)<<0))
#define SB1_PRI4_sb1_c4_latcnt_beg_src(data)                                          ((0x00000FFF&(data))>>0)
#define SB1_PRI4_get_sb1_c4_latcnt_beg(data)                                          ((0x00000FFF&(data))>>0)


#define SB1_PRI5                                                                      0x1801C014
#define SB1_PRI5_reg_addr                                                             "0xB801C014"
#define SB1_PRI5_reg                                                                  0xB801C014
#define set_SB1_PRI5_reg(data)   (*((volatile unsigned int*) SB1_PRI5_reg)=data)
#define get_SB1_PRI5_reg   (*((volatile unsigned int*) SB1_PRI5_reg))
#define SB1_PRI5_inst_adr                                                             "0x0005"
#define SB1_PRI5_inst                                                                 0x0005
#define SB1_PRI5_sb1_c5_latcnt_end_shift                                              (16)
#define SB1_PRI5_sb1_c5_latcnt_end_mask                                               (0x0FFF0000)
#define SB1_PRI5_sb1_c5_latcnt_end(data)                                              (0x0FFF0000&((data)<<16))
#define SB1_PRI5_sb1_c5_latcnt_end_src(data)                                          ((0x0FFF0000&(data))>>16)
#define SB1_PRI5_get_sb1_c5_latcnt_end(data)                                          ((0x0FFF0000&(data))>>16)
#define SB1_PRI5_sb1_c5_latcnt_beg_shift                                              (0)
#define SB1_PRI5_sb1_c5_latcnt_beg_mask                                               (0x00000FFF)
#define SB1_PRI5_sb1_c5_latcnt_beg(data)                                              (0x00000FFF&((data)<<0))
#define SB1_PRI5_sb1_c5_latcnt_beg_src(data)                                          ((0x00000FFF&(data))>>0)
#define SB1_PRI5_get_sb1_c5_latcnt_beg(data)                                          ((0x00000FFF&(data))>>0)


#define SB1_PRI6                                                                      0x1801C018
#define SB1_PRI6_reg_addr                                                             "0xB801C018"
#define SB1_PRI6_reg                                                                  0xB801C018
#define set_SB1_PRI6_reg(data)   (*((volatile unsigned int*) SB1_PRI6_reg)=data)
#define get_SB1_PRI6_reg   (*((volatile unsigned int*) SB1_PRI6_reg))
#define SB1_PRI6_inst_adr                                                             "0x0006"
#define SB1_PRI6_inst                                                                 0x0006
#define SB1_PRI6_sb1_c6_latcnt_end_shift                                              (16)
#define SB1_PRI6_sb1_c6_latcnt_end_mask                                               (0x0FFF0000)
#define SB1_PRI6_sb1_c6_latcnt_end(data)                                              (0x0FFF0000&((data)<<16))
#define SB1_PRI6_sb1_c6_latcnt_end_src(data)                                          ((0x0FFF0000&(data))>>16)
#define SB1_PRI6_get_sb1_c6_latcnt_end(data)                                          ((0x0FFF0000&(data))>>16)
#define SB1_PRI6_sb1_c6_latcnt_beg_shift                                              (0)
#define SB1_PRI6_sb1_c6_latcnt_beg_mask                                               (0x00000FFF)
#define SB1_PRI6_sb1_c6_latcnt_beg(data)                                              (0x00000FFF&((data)<<0))
#define SB1_PRI6_sb1_c6_latcnt_beg_src(data)                                          ((0x00000FFF&(data))>>0)
#define SB1_PRI6_get_sb1_c6_latcnt_beg(data)                                          ((0x00000FFF&(data))>>0)


#define SB1_PRI7                                                                      0x1801C01C
#define SB1_PRI7_reg_addr                                                             "0xB801C01C"
#define SB1_PRI7_reg                                                                  0xB801C01C
#define set_SB1_PRI7_reg(data)   (*((volatile unsigned int*) SB1_PRI7_reg)=data)
#define get_SB1_PRI7_reg   (*((volatile unsigned int*) SB1_PRI7_reg))
#define SB1_PRI7_inst_adr                                                             "0x0007"
#define SB1_PRI7_inst                                                                 0x0007
#define SB1_PRI7_sb1_c7_latcnt_end_shift                                              (16)
#define SB1_PRI7_sb1_c7_latcnt_end_mask                                               (0x0FFF0000)
#define SB1_PRI7_sb1_c7_latcnt_end(data)                                              (0x0FFF0000&((data)<<16))
#define SB1_PRI7_sb1_c7_latcnt_end_src(data)                                          ((0x0FFF0000&(data))>>16)
#define SB1_PRI7_get_sb1_c7_latcnt_end(data)                                          ((0x0FFF0000&(data))>>16)
#define SB1_PRI7_sb1_c7_latcnt_beg_shift                                              (0)
#define SB1_PRI7_sb1_c7_latcnt_beg_mask                                               (0x00000FFF)
#define SB1_PRI7_sb1_c7_latcnt_beg(data)                                              (0x00000FFF&((data)<<0))
#define SB1_PRI7_sb1_c7_latcnt_beg_src(data)                                          ((0x00000FFF&(data))>>0)
#define SB1_PRI7_get_sb1_c7_latcnt_beg(data)                                          ((0x00000FFF&(data))>>0)


#define SB1_PRI8                                                                      0x1801C020
#define SB1_PRI8_reg_addr                                                             "0xB801C020"
#define SB1_PRI8_reg                                                                  0xB801C020
#define set_SB1_PRI8_reg(data)   (*((volatile unsigned int*) SB1_PRI8_reg)=data)
#define get_SB1_PRI8_reg   (*((volatile unsigned int*) SB1_PRI8_reg))
#define SB1_PRI8_inst_adr                                                             "0x0008"
#define SB1_PRI8_inst                                                                 0x0008
#define SB1_PRI8_sb1_pri_cnt_period_shift                                             (0)
#define SB1_PRI8_sb1_pri_cnt_period_mask                                              (0x00000FFF)
#define SB1_PRI8_sb1_pri_cnt_period(data)                                             (0x00000FFF&((data)<<0))
#define SB1_PRI8_sb1_pri_cnt_period_src(data)                                         ((0x00000FFF&(data))>>0)
#define SB1_PRI8_get_sb1_pri_cnt_period(data)                                         ((0x00000FFF&(data))>>0)


#define SB1_CHANNEL0                                                                  0x1801C024
#define SB1_CHANNEL0_reg_addr                                                         "0xB801C024"
#define SB1_CHANNEL0_reg                                                              0xB801C024
#define set_SB1_CHANNEL0_reg(data)   (*((volatile unsigned int*) SB1_CHANNEL0_reg)=data)
#define get_SB1_CHANNEL0_reg   (*((volatile unsigned int*) SB1_CHANNEL0_reg))
#define SB1_CHANNEL0_inst_adr                                                         "0x0009"
#define SB1_CHANNEL0_inst                                                             0x0009
#define SB1_CHANNEL0_sb1_req_mask_index_shift                                         (0)
#define SB1_CHANNEL0_sb1_req_mask_index_mask                                          (0x000000FF)
#define SB1_CHANNEL0_sb1_req_mask_index(data)                                         (0x000000FF&((data)<<0))
#define SB1_CHANNEL0_sb1_req_mask_index_src(data)                                     ((0x000000FF&(data))>>0)
#define SB1_CHANNEL0_get_sb1_req_mask_index(data)                                     ((0x000000FF&(data))>>0)


#define SB1_CHANNEL1                                                                  0x1801C028
#define SB1_CHANNEL1_reg_addr                                                         "0xB801C028"
#define SB1_CHANNEL1_reg                                                              0xB801C028
#define set_SB1_CHANNEL1_reg(data)   (*((volatile unsigned int*) SB1_CHANNEL1_reg)=data)
#define get_SB1_CHANNEL1_reg   (*((volatile unsigned int*) SB1_CHANNEL1_reg))
#define SB1_CHANNEL1_inst_adr                                                         "0x000A"
#define SB1_CHANNEL1_inst                                                             0x000A
#define SB1_CHANNEL1_sb1_req_busy_index_shift                                         (0)
#define SB1_CHANNEL1_sb1_req_busy_index_mask                                          (0x000000FF)
#define SB1_CHANNEL1_sb1_req_busy_index(data)                                         (0x000000FF&((data)<<0))
#define SB1_CHANNEL1_sb1_req_busy_index_src(data)                                     ((0x000000FF&(data))>>0)
#define SB1_CHANNEL1_get_sb1_req_busy_index(data)                                     ((0x000000FF&(data))>>0)


#define SB1_MISC_CTRL                                                                0x1801C02C
#define SB1_MISC_CTRL_reg_addr                                                       "0xB801C02C"
#define SB1_MISC_CTRL_reg                                                            0xB801C02C
#define set_SB1_MISC_CTRL_reg(data)   (*((volatile unsigned int*) SB1_MISC_CTRL_reg)=data)
#define get_SB1_MISC_CTRL_reg   (*((volatile unsigned int*) SB1_MISC_CTRL_reg))
#define SB1_MISC_CTRL_inst_adr                                                       "0x000B"
#define SB1_MISC_CTRL_inst                                                           0x000B
#define SB1_MISC_CTRL_sb1_allow_cmd_cnt_shift                                        (0)
#define SB1_MISC_CTRL_sb1_allow_cmd_cnt_mask                                         (0x00000007)
#define SB1_MISC_CTRL_sb1_allow_cmd_cnt(data)                                        (0x00000007&((data)<<0))
#define SB1_MISC_CTRL_sb1_allow_cmd_cnt_src(data)                                    ((0x00000007&(data))>>0)
#define SB1_MISC_CTRL_get_sb1_allow_cmd_cnt(data)                                    ((0x00000007&(data))>>0)


#endif
