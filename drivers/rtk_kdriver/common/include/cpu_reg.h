/**************************************************************
// Spec Version                  : 0.13
// Parser Version                : MAR_Parser_1.0
// CModelGen Version             : 4.1 2009.03.10
// Naming Rule                   : Module_Register_Name_reg
// Firmware Header Generate Date : 2009/9/18
***************************************************************/


#ifndef _CPU_REG_H_INCLUDED_
#define _CPU_REG_H_INCLUDED_
#ifdef  _CPU_USE_STRUCT
typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     src:28;
}CPU_MCPU_DDMA_SRC;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     dst:28;
}CPU_MCPU_DDMA_DST;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     valid:1;
unsigned int     dir:1;
unsigned int     size:14;
}CPU_MCPU_DDMA_SIZE;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     done_3:1;
unsigned int     done_2:1;
unsigned int     done_1:1;
unsigned int     done_0:1;
}CPU_MCPU_DDMA_STATUS;

typedef struct 
{
unsigned int     reserved_0:23;
unsigned int     write_en2:1;
unsigned int     swap:1;
unsigned int     write_en1:1;
unsigned int     max_xfer:6;
}CPU_MCPU_DDMA_CNTL;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     mde_bist_mode:1;
unsigned int     mde_bist_rstn:1;
unsigned int     mde_bist_done:1;
unsigned int     mde_bist_fail:1;
}CPU_MCPU_DDMA_BIST;

#endif

#define CPU_MCPU_DDMA_SRC_0                                                          0x18003000
#define CPU_MCPU_DDMA_SRC_1                                                          0x18003004
#define CPU_MCPU_DDMA_SRC_2                                                          0x18003008
#define CPU_MCPU_DDMA_SRC_3                                                          0x1800300C
#define CPU_MCPU_DDMA_SRC_0_reg_addr                                                 "0xB8003000"
#define CPU_MCPU_DDMA_SRC_1_reg_addr                                                 "0xB8003004"
#define CPU_MCPU_DDMA_SRC_2_reg_addr                                                 "0xB8003008"
#define CPU_MCPU_DDMA_SRC_3_reg_addr                                                 "0xB800300C"
#define CPU_MCPU_DDMA_SRC_0_reg                                                      0xB8003000
#define CPU_MCPU_DDMA_SRC_1_reg                                                      0xB8003004
#define CPU_MCPU_DDMA_SRC_2_reg                                                      0xB8003008
#define CPU_MCPU_DDMA_SRC_3_reg                                                      0xB800300C
#define set_CPU_MCPU_DDMA_SRC_0_reg(data)   (*((volatile unsigned int*) CPU_MCPU_DDMA_SRC_0_reg)=data)
#define set_CPU_MCPU_DDMA_SRC_1_reg(data)   (*((volatile unsigned int*) CPU_MCPU_DDMA_SRC_1_reg)=data)
#define set_CPU_MCPU_DDMA_SRC_2_reg(data)   (*((volatile unsigned int*) CPU_MCPU_DDMA_SRC_2_reg)=data)
#define set_CPU_MCPU_DDMA_SRC_3_reg(data)   (*((volatile unsigned int*) CPU_MCPU_DDMA_SRC_3_reg)=data)
#define get_CPU_MCPU_DDMA_SRC_0_reg   (*((volatile unsigned int*) CPU_MCPU_DDMA_SRC_0_reg))
#define get_CPU_MCPU_DDMA_SRC_1_reg   (*((volatile unsigned int*) CPU_MCPU_DDMA_SRC_1_reg))
#define get_CPU_MCPU_DDMA_SRC_2_reg   (*((volatile unsigned int*) CPU_MCPU_DDMA_SRC_2_reg))
#define get_CPU_MCPU_DDMA_SRC_3_reg   (*((volatile unsigned int*) CPU_MCPU_DDMA_SRC_3_reg))
#define CPU_MCPU_DDMA_SRC_0_inst_adr                                                 "0x0000"
#define CPU_MCPU_DDMA_SRC_1_inst_adr                                                 "0x0001"
#define CPU_MCPU_DDMA_SRC_2_inst_adr                                                 "0x0002"
#define CPU_MCPU_DDMA_SRC_3_inst_adr                                                 "0x0003"
#define CPU_MCPU_DDMA_SRC_0_inst                                                     0x0000
#define CPU_MCPU_DDMA_SRC_1_inst                                                     0x0001
#define CPU_MCPU_DDMA_SRC_2_inst                                                     0x0002
#define CPU_MCPU_DDMA_SRC_3_inst                                                     0x0003
#define CPU_MCPU_DDMA_SRC_src_shift                                                  (0)
#define CPU_MCPU_DDMA_SRC_src_mask                                                   (0x0FFFFFFF)
#define CPU_MCPU_DDMA_SRC_src(data)                                                  (0x0FFFFFFF&((data)<<0))
#define CPU_MCPU_DDMA_SRC_src_src(data)                                              ((0x0FFFFFFF&(data))>>0)
#define CPU_MCPU_DDMA_SRC_get_src(data)                                              ((0x0FFFFFFF&(data))>>0)


#define CPU_MCPU_DDMA_DST_0                                                          0x18003010
#define CPU_MCPU_DDMA_DST_1                                                          0x18003014
#define CPU_MCPU_DDMA_DST_2                                                          0x18003018
#define CPU_MCPU_DDMA_DST_3                                                          0x1800301C
#define CPU_MCPU_DDMA_DST_0_reg_addr                                                 "0xB8003010"
#define CPU_MCPU_DDMA_DST_1_reg_addr                                                 "0xB8003014"
#define CPU_MCPU_DDMA_DST_2_reg_addr                                                 "0xB8003018"
#define CPU_MCPU_DDMA_DST_3_reg_addr                                                 "0xB800301C"
#define CPU_MCPU_DDMA_DST_0_reg                                                      0xB8003010
#define CPU_MCPU_DDMA_DST_1_reg                                                      0xB8003014
#define CPU_MCPU_DDMA_DST_2_reg                                                      0xB8003018
#define CPU_MCPU_DDMA_DST_3_reg                                                      0xB800301C
#define set_CPU_MCPU_DDMA_DST_0_reg(data)   (*((volatile unsigned int*) CPU_MCPU_DDMA_DST_0_reg)=data)
#define set_CPU_MCPU_DDMA_DST_1_reg(data)   (*((volatile unsigned int*) CPU_MCPU_DDMA_DST_1_reg)=data)
#define set_CPU_MCPU_DDMA_DST_2_reg(data)   (*((volatile unsigned int*) CPU_MCPU_DDMA_DST_2_reg)=data)
#define set_CPU_MCPU_DDMA_DST_3_reg(data)   (*((volatile unsigned int*) CPU_MCPU_DDMA_DST_3_reg)=data)
#define get_CPU_MCPU_DDMA_DST_0_reg   (*((volatile unsigned int*) CPU_MCPU_DDMA_DST_0_reg))
#define get_CPU_MCPU_DDMA_DST_1_reg   (*((volatile unsigned int*) CPU_MCPU_DDMA_DST_1_reg))
#define get_CPU_MCPU_DDMA_DST_2_reg   (*((volatile unsigned int*) CPU_MCPU_DDMA_DST_2_reg))
#define get_CPU_MCPU_DDMA_DST_3_reg   (*((volatile unsigned int*) CPU_MCPU_DDMA_DST_3_reg))
#define CPU_MCPU_DDMA_DST_0_inst_adr                                                 "0x0004"
#define CPU_MCPU_DDMA_DST_1_inst_adr                                                 "0x0005"
#define CPU_MCPU_DDMA_DST_2_inst_adr                                                 "0x0006"
#define CPU_MCPU_DDMA_DST_3_inst_adr                                                 "0x0007"
#define CPU_MCPU_DDMA_DST_0_inst                                                     0x0004
#define CPU_MCPU_DDMA_DST_1_inst                                                     0x0005
#define CPU_MCPU_DDMA_DST_2_inst                                                     0x0006
#define CPU_MCPU_DDMA_DST_3_inst                                                     0x0007
#define CPU_MCPU_DDMA_DST_dst_shift                                                  (0)
#define CPU_MCPU_DDMA_DST_dst_mask                                                   (0x0FFFFFFF)
#define CPU_MCPU_DDMA_DST_dst(data)                                                  (0x0FFFFFFF&((data)<<0))
#define CPU_MCPU_DDMA_DST_dst_src(data)                                              ((0x0FFFFFFF&(data))>>0)
#define CPU_MCPU_DDMA_DST_get_dst(data)                                              ((0x0FFFFFFF&(data))>>0)


#define CPU_MCPU_DDMA_SIZE_0                                                         0x18003020
#define CPU_MCPU_DDMA_SIZE_1                                                         0x18003024
#define CPU_MCPU_DDMA_SIZE_2                                                         0x18003028
#define CPU_MCPU_DDMA_SIZE_3                                                         0x1800302C
#define CPU_MCPU_DDMA_SIZE_0_reg_addr                                                "0xB8003020"
#define CPU_MCPU_DDMA_SIZE_1_reg_addr                                                "0xB8003024"
#define CPU_MCPU_DDMA_SIZE_2_reg_addr                                                "0xB8003028"
#define CPU_MCPU_DDMA_SIZE_3_reg_addr                                                "0xB800302C"
#define CPU_MCPU_DDMA_SIZE_0_reg                                                     0xB8003020
#define CPU_MCPU_DDMA_SIZE_1_reg                                                     0xB8003024
#define CPU_MCPU_DDMA_SIZE_2_reg                                                     0xB8003028
#define CPU_MCPU_DDMA_SIZE_3_reg                                                     0xB800302C
#define set_CPU_MCPU_DDMA_SIZE_0_reg(data)   (*((volatile unsigned int*) CPU_MCPU_DDMA_SIZE_0_reg)=data)
#define set_CPU_MCPU_DDMA_SIZE_1_reg(data)   (*((volatile unsigned int*) CPU_MCPU_DDMA_SIZE_1_reg)=data)
#define set_CPU_MCPU_DDMA_SIZE_2_reg(data)   (*((volatile unsigned int*) CPU_MCPU_DDMA_SIZE_2_reg)=data)
#define set_CPU_MCPU_DDMA_SIZE_3_reg(data)   (*((volatile unsigned int*) CPU_MCPU_DDMA_SIZE_3_reg)=data)
#define get_CPU_MCPU_DDMA_SIZE_0_reg   (*((volatile unsigned int*) CPU_MCPU_DDMA_SIZE_0_reg))
#define get_CPU_MCPU_DDMA_SIZE_1_reg   (*((volatile unsigned int*) CPU_MCPU_DDMA_SIZE_1_reg))
#define get_CPU_MCPU_DDMA_SIZE_2_reg   (*((volatile unsigned int*) CPU_MCPU_DDMA_SIZE_2_reg))
#define get_CPU_MCPU_DDMA_SIZE_3_reg   (*((volatile unsigned int*) CPU_MCPU_DDMA_SIZE_3_reg))
#define CPU_MCPU_DDMA_SIZE_0_inst_adr                                                "0x0008"
#define CPU_MCPU_DDMA_SIZE_1_inst_adr                                                "0x0009"
#define CPU_MCPU_DDMA_SIZE_2_inst_adr                                                "0x000A"
#define CPU_MCPU_DDMA_SIZE_3_inst_adr                                                "0x000B"
#define CPU_MCPU_DDMA_SIZE_0_inst                                                    0x0008
#define CPU_MCPU_DDMA_SIZE_1_inst                                                    0x0009
#define CPU_MCPU_DDMA_SIZE_2_inst                                                    0x000A
#define CPU_MCPU_DDMA_SIZE_3_inst                                                    0x000B
#define CPU_MCPU_DDMA_SIZE_valid_shift                                               (15)
#define CPU_MCPU_DDMA_SIZE_valid_mask                                                (0x00008000)
#define CPU_MCPU_DDMA_SIZE_valid(data)                                               (0x00008000&((data)<<15))
#define CPU_MCPU_DDMA_SIZE_valid_src(data)                                           ((0x00008000&(data))>>15)
#define CPU_MCPU_DDMA_SIZE_get_valid(data)                                           ((0x00008000&(data))>>15)
#define CPU_MCPU_DDMA_SIZE_dir_shift                                                 (14)
#define CPU_MCPU_DDMA_SIZE_dir_mask                                                  (0x00004000)
#define CPU_MCPU_DDMA_SIZE_dir(data)                                                 (0x00004000&((data)<<14))
#define CPU_MCPU_DDMA_SIZE_dir_src(data)                                             ((0x00004000&(data))>>14)
#define CPU_MCPU_DDMA_SIZE_get_dir(data)                                             ((0x00004000&(data))>>14)
#define CPU_MCPU_DDMA_SIZE_size_shift                                                (0)
#define CPU_MCPU_DDMA_SIZE_size_mask                                                 (0x00003FFF)
#define CPU_MCPU_DDMA_SIZE_size(data)                                                (0x00003FFF&((data)<<0))
#define CPU_MCPU_DDMA_SIZE_size_src(data)                                            ((0x00003FFF&(data))>>0)
#define CPU_MCPU_DDMA_SIZE_get_size(data)                                            ((0x00003FFF&(data))>>0)


#define CPU_MCPU_DDMA_STATUS                                                         0x18003030
#define CPU_MCPU_DDMA_STATUS_reg_addr                                                "0xB8003030"
#define CPU_MCPU_DDMA_STATUS_reg                                                     0xB8003030
#define set_CPU_MCPU_DDMA_STATUS_reg(data)   (*((volatile unsigned int*) CPU_MCPU_DDMA_STATUS_reg)=data)
#define get_CPU_MCPU_DDMA_STATUS_reg   (*((volatile unsigned int*) CPU_MCPU_DDMA_STATUS_reg))
#define CPU_MCPU_DDMA_STATUS_inst_adr                                                "0x000C"
#define CPU_MCPU_DDMA_STATUS_inst                                                    0x000C
#define CPU_MCPU_DDMA_STATUS_done_3_shift                                            (3)
#define CPU_MCPU_DDMA_STATUS_done_3_mask                                             (0x00000008)
#define CPU_MCPU_DDMA_STATUS_done_3(data)                                            (0x00000008&((data)<<3))
#define CPU_MCPU_DDMA_STATUS_done_3_src(data)                                        ((0x00000008&(data))>>3)
#define CPU_MCPU_DDMA_STATUS_get_done_3(data)                                        ((0x00000008&(data))>>3)
#define CPU_MCPU_DDMA_STATUS_done_2_shift                                            (2)
#define CPU_MCPU_DDMA_STATUS_done_2_mask                                             (0x00000004)
#define CPU_MCPU_DDMA_STATUS_done_2(data)                                            (0x00000004&((data)<<2))
#define CPU_MCPU_DDMA_STATUS_done_2_src(data)                                        ((0x00000004&(data))>>2)
#define CPU_MCPU_DDMA_STATUS_get_done_2(data)                                        ((0x00000004&(data))>>2)
#define CPU_MCPU_DDMA_STATUS_done_1_shift                                            (1)
#define CPU_MCPU_DDMA_STATUS_done_1_mask                                             (0x00000002)
#define CPU_MCPU_DDMA_STATUS_done_1(data)                                            (0x00000002&((data)<<1))
#define CPU_MCPU_DDMA_STATUS_done_1_src(data)                                        ((0x00000002&(data))>>1)
#define CPU_MCPU_DDMA_STATUS_get_done_1(data)                                        ((0x00000002&(data))>>1)
#define CPU_MCPU_DDMA_STATUS_done_0_shift                                            (0)
#define CPU_MCPU_DDMA_STATUS_done_0_mask                                             (0x00000001)
#define CPU_MCPU_DDMA_STATUS_done_0(data)                                            (0x00000001&((data)<<0))
#define CPU_MCPU_DDMA_STATUS_done_0_src(data)                                        ((0x00000001&(data))>>0)
#define CPU_MCPU_DDMA_STATUS_get_done_0(data)                                        ((0x00000001&(data))>>0)


#define CPU_MCPU_DDMA_CNTL                                                           0x18003034
#define CPU_MCPU_DDMA_CNTL_reg_addr                                                  "0xB8003034"
#define CPU_MCPU_DDMA_CNTL_reg                                                       0xB8003034
#define set_CPU_MCPU_DDMA_CNTL_reg(data)   (*((volatile unsigned int*) CPU_MCPU_DDMA_CNTL_reg)=data)
#define get_CPU_MCPU_DDMA_CNTL_reg   (*((volatile unsigned int*) CPU_MCPU_DDMA_CNTL_reg))
#define CPU_MCPU_DDMA_CNTL_inst_adr                                                  "0x000D"
#define CPU_MCPU_DDMA_CNTL_inst                                                      0x000D
#define CPU_MCPU_DDMA_CNTL_write_en2_shift                                           (8)
#define CPU_MCPU_DDMA_CNTL_write_en2_mask                                            (0x00000100)
#define CPU_MCPU_DDMA_CNTL_write_en2(data)                                           (0x00000100&((data)<<8))
#define CPU_MCPU_DDMA_CNTL_write_en2_src(data)                                       ((0x00000100&(data))>>8)
#define CPU_MCPU_DDMA_CNTL_get_write_en2(data)                                       ((0x00000100&(data))>>8)
#define CPU_MCPU_DDMA_CNTL_swap_shift                                                (7)
#define CPU_MCPU_DDMA_CNTL_swap_mask                                                 (0x00000080)
#define CPU_MCPU_DDMA_CNTL_swap(data)                                                (0x00000080&((data)<<7))
#define CPU_MCPU_DDMA_CNTL_swap_src(data)                                            ((0x00000080&(data))>>7)
#define CPU_MCPU_DDMA_CNTL_get_swap(data)                                            ((0x00000080&(data))>>7)
#define CPU_MCPU_DDMA_CNTL_write_en1_shift                                           (6)
#define CPU_MCPU_DDMA_CNTL_write_en1_mask                                            (0x00000040)
#define CPU_MCPU_DDMA_CNTL_write_en1(data)                                           (0x00000040&((data)<<6))
#define CPU_MCPU_DDMA_CNTL_write_en1_src(data)                                       ((0x00000040&(data))>>6)
#define CPU_MCPU_DDMA_CNTL_get_write_en1(data)                                       ((0x00000040&(data))>>6)
#define CPU_MCPU_DDMA_CNTL_max_xfer_shift                                            (0)
#define CPU_MCPU_DDMA_CNTL_max_xfer_mask                                             (0x0000003F)
#define CPU_MCPU_DDMA_CNTL_max_xfer(data)                                            (0x0000003F&((data)<<0))
#define CPU_MCPU_DDMA_CNTL_max_xfer_src(data)                                        ((0x0000003F&(data))>>0)
#define CPU_MCPU_DDMA_CNTL_get_max_xfer(data)                                        ((0x0000003F&(data))>>0)


#define CPU_MCPU_DDMA_BIST                                                           0x18003040
#define CPU_MCPU_DDMA_BIST_reg_addr                                                  "0xB8003040"
#define CPU_MCPU_DDMA_BIST_reg                                                       0xB8003040
#define set_CPU_MCPU_DDMA_BIST_reg(data)   (*((volatile unsigned int*) CPU_MCPU_DDMA_BIST_reg)=data)
#define get_CPU_MCPU_DDMA_BIST_reg   (*((volatile unsigned int*) CPU_MCPU_DDMA_BIST_reg))
#define CPU_MCPU_DDMA_BIST_inst_adr                                                  "0x0010"
#define CPU_MCPU_DDMA_BIST_inst                                                      0x0010
#define CPU_MCPU_DDMA_BIST_mde_bist_mode_shift                                       (3)
#define CPU_MCPU_DDMA_BIST_mde_bist_mode_mask                                        (0x00000008)
#define CPU_MCPU_DDMA_BIST_mde_bist_mode(data)                                       (0x00000008&((data)<<3))
#define CPU_MCPU_DDMA_BIST_mde_bist_mode_src(data)                                   ((0x00000008&(data))>>3)
#define CPU_MCPU_DDMA_BIST_get_mde_bist_mode(data)                                   ((0x00000008&(data))>>3)
#define CPU_MCPU_DDMA_BIST_mde_bist_rstn_shift                                       (2)
#define CPU_MCPU_DDMA_BIST_mde_bist_rstn_mask                                        (0x00000004)
#define CPU_MCPU_DDMA_BIST_mde_bist_rstn(data)                                       (0x00000004&((data)<<2))
#define CPU_MCPU_DDMA_BIST_mde_bist_rstn_src(data)                                   ((0x00000004&(data))>>2)
#define CPU_MCPU_DDMA_BIST_get_mde_bist_rstn(data)                                   ((0x00000004&(data))>>2)
#define CPU_MCPU_DDMA_BIST_mde_bist_done_shift                                       (1)
#define CPU_MCPU_DDMA_BIST_mde_bist_done_mask                                        (0x00000002)
#define CPU_MCPU_DDMA_BIST_mde_bist_done(data)                                       (0x00000002&((data)<<1))
#define CPU_MCPU_DDMA_BIST_mde_bist_done_src(data)                                   ((0x00000002&(data))>>1)
#define CPU_MCPU_DDMA_BIST_get_mde_bist_done(data)                                   ((0x00000002&(data))>>1)
#define CPU_MCPU_DDMA_BIST_mde_bist_fail_shift                                       (0)
#define CPU_MCPU_DDMA_BIST_mde_bist_fail_mask                                        (0x00000001)
#define CPU_MCPU_DDMA_BIST_mde_bist_fail(data)                                       (0x00000001&((data)<<0))
#define CPU_MCPU_DDMA_BIST_mde_bist_fail_src(data)                                   ((0x00000001&(data))>>0)
#define CPU_MCPU_DDMA_BIST_get_mde_bist_fail(data)                                   ((0x00000001&(data))>>0)


#endif
