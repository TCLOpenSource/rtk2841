/**************************************************************
// Spec Version                  : unknown
// Parser Version                : DVR_Parser_6.8(110516)
// CModelGen Version             : 5.0 2009.04.09
// Naming Rule                   :  Register_Name
// Naming Rule                   : Module_Register_Name_reg
// Parse Option                  : Only Parse _op1
// Parse Address Region          : All Address Region 
// Decode bit number             : 12 bits
// Firmware Header Generate Date : 2012/8/1 15:22:57
***************************************************************/


#ifndef _VE1_MBIST_REG_H_INCLUDED_
#define _VE1_MBIST_REG_H_INCLUDED_
#ifdef  _VE1_MBIST_USE_STRUCT
typedef struct 
{
unsigned int     bist_2p_clk_sel:1;
unsigned int     LS:1;
unsigned int     SYSH_RMEA:1;
unsigned int     SYSH_RMA:4;
unsigned int     SYSH_RMEB:1;
unsigned int     SYSH_RMB:4;
unsigned int     SYSH_RME:1;
unsigned int     SYSH_RM:4;
unsigned int     RMEA:1;
unsigned int     RMA:4;
unsigned int     RMEB:1;
unsigned int     RMB:4;
unsigned int     RME:1;
unsigned int     RM:4;
}VE1_BIST_RM;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     ve1_bist_mode_8:1;
unsigned int     ve1_bist_mode_7:1;
unsigned int     ve1_bist_mode_6:1;
unsigned int     ve1_bist_mode_5:1;
unsigned int     ve1_bist_mode_4:1;
unsigned int     ve1_bist_mode_3:1;
unsigned int     ve1_bist_mode_2:1;
unsigned int     ve1_bist_mode_1:1;
}VE1_BIST_MODE;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     ve1_bist_done_8:1;
unsigned int     ve1_bist_done_7:1;
unsigned int     ve1_bist_done_6:1;
unsigned int     ve1_bist_done_5:1;
unsigned int     ve1_bist_done_4:1;
unsigned int     ve1_bist_done_3:1;
unsigned int     ve1_bist_done_2:1;
unsigned int     ve1_bist_done_1:1;
}VE1_BIST_DONE;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     ve1_bist_fail_group_8:1;
unsigned int     ve1_bist_fail_group_7:1;
unsigned int     ve1_bist_fail_group_6:1;
unsigned int     ve1_bist_fail_group_5:1;
unsigned int     ve1_bist_fail_group_4:1;
unsigned int     ve1_bist_fail_group_3:1;
unsigned int     ve1_bist_fail_group_2:1;
unsigned int     ve1_bist_fail_group_1:1;
}VE1_BIST_FAIL_GROUP;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     ve1_drf_mode_8:1;
unsigned int     ve1_drf_mode_7:1;
unsigned int     ve1_drf_mode_6:1;
unsigned int     ve1_drf_mode_5:1;
unsigned int     ve1_drf_mode_4:1;
unsigned int     ve1_drf_mode_3:1;
unsigned int     ve1_drf_mode_2:1;
unsigned int     ve1_drf_mode_1:1;
}VE1_DRF_MODE;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     ve1_drf_resume_8:1;
unsigned int     ve1_drf_resume_7:1;
unsigned int     ve1_drf_resume_6:1;
unsigned int     ve1_drf_resume_5:1;
unsigned int     ve1_drf_resume_4:1;
unsigned int     ve1_drf_resume_3:1;
unsigned int     ve1_drf_resume_2:1;
unsigned int     ve1_drf_resume_1:1;
}VE1_DRF_RESUME;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     ve1_drf_pause_8:1;
unsigned int     ve1_drf_pause_7:1;
unsigned int     ve1_drf_pause_6:1;
unsigned int     ve1_drf_pause_5:1;
unsigned int     ve1_drf_pause_4:1;
unsigned int     ve1_drf_pause_3:1;
unsigned int     ve1_drf_pause_2:1;
unsigned int     ve1_drf_pause_1:1;
}VE1_DRF_PAUSE;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     ve1_drf_done_8:1;
unsigned int     ve1_drf_done_7:1;
unsigned int     ve1_drf_done_6:1;
unsigned int     ve1_drf_done_5:1;
unsigned int     ve1_drf_done_4:1;
unsigned int     ve1_drf_done_3:1;
unsigned int     ve1_drf_done_2:1;
unsigned int     ve1_drf_done_1:1;
}VE1_DRF_DONE;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     ve1_drf_fail_group_8:1;
unsigned int     ve1_drf_fail_group_7:1;
unsigned int     ve1_drf_fail_group_6:1;
unsigned int     ve1_drf_fail_group_5:1;
unsigned int     ve1_drf_fail_group_4:1;
unsigned int     ve1_drf_fail_group_3:1;
unsigned int     ve1_drf_fail_group_2:1;
unsigned int     ve1_drf_fail_group_1:1;
}VE1_DRF_FAIL_GROUP;

typedef struct 
{
unsigned int     reserved_0:26;
unsigned int     ve1_bist1_fail:6;
}VE1_BIST1_FAIL;

typedef struct 
{
unsigned int     reserved_0:26;
unsigned int     ve1_drf1_fail:6;
}VE1_DRF1_FAIL;

typedef struct 
{
unsigned int     reserved_0:22;
unsigned int     ve1_bist2_fail:10;
}VE1_BIST2_FAIL;

typedef struct 
{
unsigned int     reserved_0:22;
unsigned int     ve1_drf2_fail:10;
}VE1_DRF2_FAIL;

typedef struct 
{
unsigned int     reserved_0:25;
unsigned int     ve1_bist3_fail:7;
}VE1_BIST3_FAIL;

typedef struct 
{
unsigned int     reserved_0:25;
unsigned int     ve1_drf3_fail:7;
}VE1_DRF3_FAIL;

typedef struct 
{
unsigned int     reserved_0:27;
unsigned int     ve1_bist4_fail:5;
}VE1_BIST4_FAIL;

typedef struct 
{
unsigned int     reserved_0:27;
unsigned int     ve1_drf4_fail:5;
}VE1_DRF4_FAIL;

typedef struct 
{
unsigned int     reserved_0:26;
unsigned int     ve1_bist5_fail:6;
}VE1_BIST5_FAIL;

typedef struct 
{
unsigned int     reserved_0:26;
unsigned int     ve1_drf5_fail:6;
}VE1_DRF5_FAIL;

typedef struct 
{
unsigned int     reserved_0:27;
unsigned int     ve1_bist6_fail:5;
}VE1_BIST6_FAIL;

typedef struct 
{
unsigned int     reserved_0:27;
unsigned int     ve1_drf6_fail:5;
}VE1_DRF6_FAIL;

typedef struct 
{
unsigned int     reserved_0:23;
unsigned int     ve1_bist7_fail:9;
}VE1_BIST7_FAIL;

typedef struct 
{
unsigned int     reserved_0:23;
unsigned int     ve1_drf7_fail:9;
}VE1_DRF7_FAIL;

typedef struct 
{
unsigned int     reserved_0:22;
unsigned int     ve1_bist8_fail:10;
}VE1_BIST8_FAIL;

typedef struct 
{
unsigned int     reserved_0:22;
unsigned int     ve1_drf8_fail:10;
}VE1_DRF8_FAIL;

#endif

#define VE1_BIST_RM                                                                  0x1800EF00
#define VE1_BIST_RM_reg_addr                                                         "0xB800EF00"
#define VE1_BIST_RM_reg                                                              0xB800EF00
#define set_VE1_BIST_RM_reg(data)   (*((volatile unsigned int*) VE1_BIST_RM_reg)=data)
#define get_VE1_BIST_RM_reg   (*((volatile unsigned int*) VE1_BIST_RM_reg))
#define VE1_BIST_RM_inst_adr                                                         "0x00C0"
#define VE1_BIST_RM_inst                                                             0x00C0
#define VE1_BIST_RM_bist_2p_clk_sel_shift                                            (31)
#define VE1_BIST_RM_bist_2p_clk_sel_mask                                             (0x80000000)
#define VE1_BIST_RM_bist_2p_clk_sel(data)                                            (0x80000000&((data)<<31))
#define VE1_BIST_RM_bist_2p_clk_sel_src(data)                                        ((0x80000000&(data))>>31)
#define VE1_BIST_RM_get_bist_2p_clk_sel(data)                                        ((0x80000000&(data))>>31)
#define VE1_BIST_RM_LS_shift                                                         (30)
#define VE1_BIST_RM_LS_mask                                                          (0x40000000)
#define VE1_BIST_RM_LS(data)                                                         (0x40000000&((data)<<30))
#define VE1_BIST_RM_LS_src(data)                                                     ((0x40000000&(data))>>30)
#define VE1_BIST_RM_get_LS(data)                                                     ((0x40000000&(data))>>30)
#define VE1_BIST_RM_SYSH_RMEA_shift                                                  (29)
#define VE1_BIST_RM_SYSH_RMEA_mask                                                   (0x20000000)
#define VE1_BIST_RM_SYSH_RMEA(data)                                                  (0x20000000&((data)<<29))
#define VE1_BIST_RM_SYSH_RMEA_src(data)                                              ((0x20000000&(data))>>29)
#define VE1_BIST_RM_get_SYSH_RMEA(data)                                              ((0x20000000&(data))>>29)
#define VE1_BIST_RM_SYSH_RMA_shift                                                   (25)
#define VE1_BIST_RM_SYSH_RMA_mask                                                    (0x1E000000)
#define VE1_BIST_RM_SYSH_RMA(data)                                                   (0x1E000000&((data)<<25))
#define VE1_BIST_RM_SYSH_RMA_src(data)                                               ((0x1E000000&(data))>>25)
#define VE1_BIST_RM_get_SYSH_RMA(data)                                               ((0x1E000000&(data))>>25)
#define VE1_BIST_RM_SYSH_RMEB_shift                                                  (24)
#define VE1_BIST_RM_SYSH_RMEB_mask                                                   (0x01000000)
#define VE1_BIST_RM_SYSH_RMEB(data)                                                  (0x01000000&((data)<<24))
#define VE1_BIST_RM_SYSH_RMEB_src(data)                                              ((0x01000000&(data))>>24)
#define VE1_BIST_RM_get_SYSH_RMEB(data)                                              ((0x01000000&(data))>>24)
#define VE1_BIST_RM_SYSH_RMB_shift                                                   (20)
#define VE1_BIST_RM_SYSH_RMB_mask                                                    (0x00F00000)
#define VE1_BIST_RM_SYSH_RMB(data)                                                   (0x00F00000&((data)<<20))
#define VE1_BIST_RM_SYSH_RMB_src(data)                                               ((0x00F00000&(data))>>20)
#define VE1_BIST_RM_get_SYSH_RMB(data)                                               ((0x00F00000&(data))>>20)
#define VE1_BIST_RM_SYSH_RME_shift                                                   (19)
#define VE1_BIST_RM_SYSH_RME_mask                                                    (0x00080000)
#define VE1_BIST_RM_SYSH_RME(data)                                                   (0x00080000&((data)<<19))
#define VE1_BIST_RM_SYSH_RME_src(data)                                               ((0x00080000&(data))>>19)
#define VE1_BIST_RM_get_SYSH_RME(data)                                               ((0x00080000&(data))>>19)
#define VE1_BIST_RM_SYSH_RM_shift                                                    (15)
#define VE1_BIST_RM_SYSH_RM_mask                                                     (0x00078000)
#define VE1_BIST_RM_SYSH_RM(data)                                                    (0x00078000&((data)<<15))
#define VE1_BIST_RM_SYSH_RM_src(data)                                                ((0x00078000&(data))>>15)
#define VE1_BIST_RM_get_SYSH_RM(data)                                                ((0x00078000&(data))>>15)
#define VE1_BIST_RM_RMEA_shift                                                       (14)
#define VE1_BIST_RM_RMEA_mask                                                        (0x00004000)
#define VE1_BIST_RM_RMEA(data)                                                       (0x00004000&((data)<<14))
#define VE1_BIST_RM_RMEA_src(data)                                                   ((0x00004000&(data))>>14)
#define VE1_BIST_RM_get_RMEA(data)                                                   ((0x00004000&(data))>>14)
#define VE1_BIST_RM_RMA_shift                                                        (10)
#define VE1_BIST_RM_RMA_mask                                                         (0x00003C00)
#define VE1_BIST_RM_RMA(data)                                                        (0x00003C00&((data)<<10))
#define VE1_BIST_RM_RMA_src(data)                                                    ((0x00003C00&(data))>>10)
#define VE1_BIST_RM_get_RMA(data)                                                    ((0x00003C00&(data))>>10)
#define VE1_BIST_RM_RMEB_shift                                                       (9)
#define VE1_BIST_RM_RMEB_mask                                                        (0x00000200)
#define VE1_BIST_RM_RMEB(data)                                                       (0x00000200&((data)<<9))
#define VE1_BIST_RM_RMEB_src(data)                                                   ((0x00000200&(data))>>9)
#define VE1_BIST_RM_get_RMEB(data)                                                   ((0x00000200&(data))>>9)
#define VE1_BIST_RM_RMB_shift                                                        (5)
#define VE1_BIST_RM_RMB_mask                                                         (0x000001E0)
#define VE1_BIST_RM_RMB(data)                                                        (0x000001E0&((data)<<5))
#define VE1_BIST_RM_RMB_src(data)                                                    ((0x000001E0&(data))>>5)
#define VE1_BIST_RM_get_RMB(data)                                                    ((0x000001E0&(data))>>5)
#define VE1_BIST_RM_RME_shift                                                        (4)
#define VE1_BIST_RM_RME_mask                                                         (0x00000010)
#define VE1_BIST_RM_RME(data)                                                        (0x00000010&((data)<<4))
#define VE1_BIST_RM_RME_src(data)                                                    ((0x00000010&(data))>>4)
#define VE1_BIST_RM_get_RME(data)                                                    ((0x00000010&(data))>>4)
#define VE1_BIST_RM_RM_shift                                                         (0)
#define VE1_BIST_RM_RM_mask                                                          (0x0000000F)
#define VE1_BIST_RM_RM(data)                                                         (0x0000000F&((data)<<0))
#define VE1_BIST_RM_RM_src(data)                                                     ((0x0000000F&(data))>>0)
#define VE1_BIST_RM_get_RM(data)                                                     ((0x0000000F&(data))>>0)


#define VE1_BIST_MODE                                                                0x1800EF04
#define VE1_BIST_MODE_reg_addr                                                       "0xB800EF04"
#define VE1_BIST_MODE_reg                                                            0xB800EF04
#define set_VE1_BIST_MODE_reg(data)   (*((volatile unsigned int*) VE1_BIST_MODE_reg)=data)
#define get_VE1_BIST_MODE_reg   (*((volatile unsigned int*) VE1_BIST_MODE_reg))
#define VE1_BIST_MODE_inst_adr                                                       "0x00C1"
#define VE1_BIST_MODE_inst                                                           0x00C1
#define VE1_BIST_MODE_ve1_bist_mode_8_shift                                          (7)
#define VE1_BIST_MODE_ve1_bist_mode_8_mask                                           (0x00000080)
#define VE1_BIST_MODE_ve1_bist_mode_8(data)                                          (0x00000080&((data)<<7))
#define VE1_BIST_MODE_ve1_bist_mode_8_src(data)                                      ((0x00000080&(data))>>7)
#define VE1_BIST_MODE_get_ve1_bist_mode_8(data)                                      ((0x00000080&(data))>>7)
#define VE1_BIST_MODE_ve1_bist_mode_7_shift                                          (6)
#define VE1_BIST_MODE_ve1_bist_mode_7_mask                                           (0x00000040)
#define VE1_BIST_MODE_ve1_bist_mode_7(data)                                          (0x00000040&((data)<<6))
#define VE1_BIST_MODE_ve1_bist_mode_7_src(data)                                      ((0x00000040&(data))>>6)
#define VE1_BIST_MODE_get_ve1_bist_mode_7(data)                                      ((0x00000040&(data))>>6)
#define VE1_BIST_MODE_ve1_bist_mode_6_shift                                          (5)
#define VE1_BIST_MODE_ve1_bist_mode_6_mask                                           (0x00000020)
#define VE1_BIST_MODE_ve1_bist_mode_6(data)                                          (0x00000020&((data)<<5))
#define VE1_BIST_MODE_ve1_bist_mode_6_src(data)                                      ((0x00000020&(data))>>5)
#define VE1_BIST_MODE_get_ve1_bist_mode_6(data)                                      ((0x00000020&(data))>>5)
#define VE1_BIST_MODE_ve1_bist_mode_5_shift                                          (4)
#define VE1_BIST_MODE_ve1_bist_mode_5_mask                                           (0x00000010)
#define VE1_BIST_MODE_ve1_bist_mode_5(data)                                          (0x00000010&((data)<<4))
#define VE1_BIST_MODE_ve1_bist_mode_5_src(data)                                      ((0x00000010&(data))>>4)
#define VE1_BIST_MODE_get_ve1_bist_mode_5(data)                                      ((0x00000010&(data))>>4)
#define VE1_BIST_MODE_ve1_bist_mode_4_shift                                          (3)
#define VE1_BIST_MODE_ve1_bist_mode_4_mask                                           (0x00000008)
#define VE1_BIST_MODE_ve1_bist_mode_4(data)                                          (0x00000008&((data)<<3))
#define VE1_BIST_MODE_ve1_bist_mode_4_src(data)                                      ((0x00000008&(data))>>3)
#define VE1_BIST_MODE_get_ve1_bist_mode_4(data)                                      ((0x00000008&(data))>>3)
#define VE1_BIST_MODE_ve1_bist_mode_3_shift                                          (2)
#define VE1_BIST_MODE_ve1_bist_mode_3_mask                                           (0x00000004)
#define VE1_BIST_MODE_ve1_bist_mode_3(data)                                          (0x00000004&((data)<<2))
#define VE1_BIST_MODE_ve1_bist_mode_3_src(data)                                      ((0x00000004&(data))>>2)
#define VE1_BIST_MODE_get_ve1_bist_mode_3(data)                                      ((0x00000004&(data))>>2)
#define VE1_BIST_MODE_ve1_bist_mode_2_shift                                          (1)
#define VE1_BIST_MODE_ve1_bist_mode_2_mask                                           (0x00000002)
#define VE1_BIST_MODE_ve1_bist_mode_2(data)                                          (0x00000002&((data)<<1))
#define VE1_BIST_MODE_ve1_bist_mode_2_src(data)                                      ((0x00000002&(data))>>1)
#define VE1_BIST_MODE_get_ve1_bist_mode_2(data)                                      ((0x00000002&(data))>>1)
#define VE1_BIST_MODE_ve1_bist_mode_1_shift                                          (0)
#define VE1_BIST_MODE_ve1_bist_mode_1_mask                                           (0x00000001)
#define VE1_BIST_MODE_ve1_bist_mode_1(data)                                          (0x00000001&((data)<<0))
#define VE1_BIST_MODE_ve1_bist_mode_1_src(data)                                      ((0x00000001&(data))>>0)
#define VE1_BIST_MODE_get_ve1_bist_mode_1(data)                                      ((0x00000001&(data))>>0)


#define VE1_BIST_DONE                                                                0x1800EF08
#define VE1_BIST_DONE_reg_addr                                                       "0xB800EF08"
#define VE1_BIST_DONE_reg                                                            0xB800EF08
#define set_VE1_BIST_DONE_reg(data)   (*((volatile unsigned int*) VE1_BIST_DONE_reg)=data)
#define get_VE1_BIST_DONE_reg   (*((volatile unsigned int*) VE1_BIST_DONE_reg))
#define VE1_BIST_DONE_inst_adr                                                       "0x00C2"
#define VE1_BIST_DONE_inst                                                           0x00C2
#define VE1_BIST_DONE_ve1_bist_done_8_shift                                          (7)
#define VE1_BIST_DONE_ve1_bist_done_8_mask                                           (0x00000080)
#define VE1_BIST_DONE_ve1_bist_done_8(data)                                          (0x00000080&((data)<<7))
#define VE1_BIST_DONE_ve1_bist_done_8_src(data)                                      ((0x00000080&(data))>>7)
#define VE1_BIST_DONE_get_ve1_bist_done_8(data)                                      ((0x00000080&(data))>>7)
#define VE1_BIST_DONE_ve1_bist_done_7_shift                                          (6)
#define VE1_BIST_DONE_ve1_bist_done_7_mask                                           (0x00000040)
#define VE1_BIST_DONE_ve1_bist_done_7(data)                                          (0x00000040&((data)<<6))
#define VE1_BIST_DONE_ve1_bist_done_7_src(data)                                      ((0x00000040&(data))>>6)
#define VE1_BIST_DONE_get_ve1_bist_done_7(data)                                      ((0x00000040&(data))>>6)
#define VE1_BIST_DONE_ve1_bist_done_6_shift                                          (5)
#define VE1_BIST_DONE_ve1_bist_done_6_mask                                           (0x00000020)
#define VE1_BIST_DONE_ve1_bist_done_6(data)                                          (0x00000020&((data)<<5))
#define VE1_BIST_DONE_ve1_bist_done_6_src(data)                                      ((0x00000020&(data))>>5)
#define VE1_BIST_DONE_get_ve1_bist_done_6(data)                                      ((0x00000020&(data))>>5)
#define VE1_BIST_DONE_ve1_bist_done_5_shift                                          (4)
#define VE1_BIST_DONE_ve1_bist_done_5_mask                                           (0x00000010)
#define VE1_BIST_DONE_ve1_bist_done_5(data)                                          (0x00000010&((data)<<4))
#define VE1_BIST_DONE_ve1_bist_done_5_src(data)                                      ((0x00000010&(data))>>4)
#define VE1_BIST_DONE_get_ve1_bist_done_5(data)                                      ((0x00000010&(data))>>4)
#define VE1_BIST_DONE_ve1_bist_done_4_shift                                          (3)
#define VE1_BIST_DONE_ve1_bist_done_4_mask                                           (0x00000008)
#define VE1_BIST_DONE_ve1_bist_done_4(data)                                          (0x00000008&((data)<<3))
#define VE1_BIST_DONE_ve1_bist_done_4_src(data)                                      ((0x00000008&(data))>>3)
#define VE1_BIST_DONE_get_ve1_bist_done_4(data)                                      ((0x00000008&(data))>>3)
#define VE1_BIST_DONE_ve1_bist_done_3_shift                                          (2)
#define VE1_BIST_DONE_ve1_bist_done_3_mask                                           (0x00000004)
#define VE1_BIST_DONE_ve1_bist_done_3(data)                                          (0x00000004&((data)<<2))
#define VE1_BIST_DONE_ve1_bist_done_3_src(data)                                      ((0x00000004&(data))>>2)
#define VE1_BIST_DONE_get_ve1_bist_done_3(data)                                      ((0x00000004&(data))>>2)
#define VE1_BIST_DONE_ve1_bist_done_2_shift                                          (1)
#define VE1_BIST_DONE_ve1_bist_done_2_mask                                           (0x00000002)
#define VE1_BIST_DONE_ve1_bist_done_2(data)                                          (0x00000002&((data)<<1))
#define VE1_BIST_DONE_ve1_bist_done_2_src(data)                                      ((0x00000002&(data))>>1)
#define VE1_BIST_DONE_get_ve1_bist_done_2(data)                                      ((0x00000002&(data))>>1)
#define VE1_BIST_DONE_ve1_bist_done_1_shift                                          (0)
#define VE1_BIST_DONE_ve1_bist_done_1_mask                                           (0x00000001)
#define VE1_BIST_DONE_ve1_bist_done_1(data)                                          (0x00000001&((data)<<0))
#define VE1_BIST_DONE_ve1_bist_done_1_src(data)                                      ((0x00000001&(data))>>0)
#define VE1_BIST_DONE_get_ve1_bist_done_1(data)                                      ((0x00000001&(data))>>0)


#define VE1_BIST_FAIL_GROUP                                                          0x1800EF0C
#define VE1_BIST_FAIL_GROUP_reg_addr                                                 "0xB800EF0C"
#define VE1_BIST_FAIL_GROUP_reg                                                      0xB800EF0C
#define set_VE1_BIST_FAIL_GROUP_reg(data)   (*((volatile unsigned int*) VE1_BIST_FAIL_GROUP_reg)=data)
#define get_VE1_BIST_FAIL_GROUP_reg   (*((volatile unsigned int*) VE1_BIST_FAIL_GROUP_reg))
#define VE1_BIST_FAIL_GROUP_inst_adr                                                 "0x00C3"
#define VE1_BIST_FAIL_GROUP_inst                                                     0x00C3
#define VE1_BIST_FAIL_GROUP_ve1_bist_fail_group_8_shift                              (7)
#define VE1_BIST_FAIL_GROUP_ve1_bist_fail_group_8_mask                               (0x00000080)
#define VE1_BIST_FAIL_GROUP_ve1_bist_fail_group_8(data)                              (0x00000080&((data)<<7))
#define VE1_BIST_FAIL_GROUP_ve1_bist_fail_group_8_src(data)                          ((0x00000080&(data))>>7)
#define VE1_BIST_FAIL_GROUP_get_ve1_bist_fail_group_8(data)                          ((0x00000080&(data))>>7)
#define VE1_BIST_FAIL_GROUP_ve1_bist_fail_group_7_shift                              (6)
#define VE1_BIST_FAIL_GROUP_ve1_bist_fail_group_7_mask                               (0x00000040)
#define VE1_BIST_FAIL_GROUP_ve1_bist_fail_group_7(data)                              (0x00000040&((data)<<6))
#define VE1_BIST_FAIL_GROUP_ve1_bist_fail_group_7_src(data)                          ((0x00000040&(data))>>6)
#define VE1_BIST_FAIL_GROUP_get_ve1_bist_fail_group_7(data)                          ((0x00000040&(data))>>6)
#define VE1_BIST_FAIL_GROUP_ve1_bist_fail_group_6_shift                              (5)
#define VE1_BIST_FAIL_GROUP_ve1_bist_fail_group_6_mask                               (0x00000020)
#define VE1_BIST_FAIL_GROUP_ve1_bist_fail_group_6(data)                              (0x00000020&((data)<<5))
#define VE1_BIST_FAIL_GROUP_ve1_bist_fail_group_6_src(data)                          ((0x00000020&(data))>>5)
#define VE1_BIST_FAIL_GROUP_get_ve1_bist_fail_group_6(data)                          ((0x00000020&(data))>>5)
#define VE1_BIST_FAIL_GROUP_ve1_bist_fail_group_5_shift                              (4)
#define VE1_BIST_FAIL_GROUP_ve1_bist_fail_group_5_mask                               (0x00000010)
#define VE1_BIST_FAIL_GROUP_ve1_bist_fail_group_5(data)                              (0x00000010&((data)<<4))
#define VE1_BIST_FAIL_GROUP_ve1_bist_fail_group_5_src(data)                          ((0x00000010&(data))>>4)
#define VE1_BIST_FAIL_GROUP_get_ve1_bist_fail_group_5(data)                          ((0x00000010&(data))>>4)
#define VE1_BIST_FAIL_GROUP_ve1_bist_fail_group_4_shift                              (3)
#define VE1_BIST_FAIL_GROUP_ve1_bist_fail_group_4_mask                               (0x00000008)
#define VE1_BIST_FAIL_GROUP_ve1_bist_fail_group_4(data)                              (0x00000008&((data)<<3))
#define VE1_BIST_FAIL_GROUP_ve1_bist_fail_group_4_src(data)                          ((0x00000008&(data))>>3)
#define VE1_BIST_FAIL_GROUP_get_ve1_bist_fail_group_4(data)                          ((0x00000008&(data))>>3)
#define VE1_BIST_FAIL_GROUP_ve1_bist_fail_group_3_shift                              (2)
#define VE1_BIST_FAIL_GROUP_ve1_bist_fail_group_3_mask                               (0x00000004)
#define VE1_BIST_FAIL_GROUP_ve1_bist_fail_group_3(data)                              (0x00000004&((data)<<2))
#define VE1_BIST_FAIL_GROUP_ve1_bist_fail_group_3_src(data)                          ((0x00000004&(data))>>2)
#define VE1_BIST_FAIL_GROUP_get_ve1_bist_fail_group_3(data)                          ((0x00000004&(data))>>2)
#define VE1_BIST_FAIL_GROUP_ve1_bist_fail_group_2_shift                              (1)
#define VE1_BIST_FAIL_GROUP_ve1_bist_fail_group_2_mask                               (0x00000002)
#define VE1_BIST_FAIL_GROUP_ve1_bist_fail_group_2(data)                              (0x00000002&((data)<<1))
#define VE1_BIST_FAIL_GROUP_ve1_bist_fail_group_2_src(data)                          ((0x00000002&(data))>>1)
#define VE1_BIST_FAIL_GROUP_get_ve1_bist_fail_group_2(data)                          ((0x00000002&(data))>>1)
#define VE1_BIST_FAIL_GROUP_ve1_bist_fail_group_1_shift                              (0)
#define VE1_BIST_FAIL_GROUP_ve1_bist_fail_group_1_mask                               (0x00000001)
#define VE1_BIST_FAIL_GROUP_ve1_bist_fail_group_1(data)                              (0x00000001&((data)<<0))
#define VE1_BIST_FAIL_GROUP_ve1_bist_fail_group_1_src(data)                          ((0x00000001&(data))>>0)
#define VE1_BIST_FAIL_GROUP_get_ve1_bist_fail_group_1(data)                          ((0x00000001&(data))>>0)


#define VE1_DRF_MODE                                                                 0x1800EF10
#define VE1_DRF_MODE_reg_addr                                                        "0xB800EF10"
#define VE1_DRF_MODE_reg                                                             0xB800EF10
#define set_VE1_DRF_MODE_reg(data)   (*((volatile unsigned int*) VE1_DRF_MODE_reg)=data)
#define get_VE1_DRF_MODE_reg   (*((volatile unsigned int*) VE1_DRF_MODE_reg))
#define VE1_DRF_MODE_inst_adr                                                        "0x00C4"
#define VE1_DRF_MODE_inst                                                            0x00C4
#define VE1_DRF_MODE_ve1_drf_mode_8_shift                                            (7)
#define VE1_DRF_MODE_ve1_drf_mode_8_mask                                             (0x00000080)
#define VE1_DRF_MODE_ve1_drf_mode_8(data)                                            (0x00000080&((data)<<7))
#define VE1_DRF_MODE_ve1_drf_mode_8_src(data)                                        ((0x00000080&(data))>>7)
#define VE1_DRF_MODE_get_ve1_drf_mode_8(data)                                        ((0x00000080&(data))>>7)
#define VE1_DRF_MODE_ve1_drf_mode_7_shift                                            (6)
#define VE1_DRF_MODE_ve1_drf_mode_7_mask                                             (0x00000040)
#define VE1_DRF_MODE_ve1_drf_mode_7(data)                                            (0x00000040&((data)<<6))
#define VE1_DRF_MODE_ve1_drf_mode_7_src(data)                                        ((0x00000040&(data))>>6)
#define VE1_DRF_MODE_get_ve1_drf_mode_7(data)                                        ((0x00000040&(data))>>6)
#define VE1_DRF_MODE_ve1_drf_mode_6_shift                                            (5)
#define VE1_DRF_MODE_ve1_drf_mode_6_mask                                             (0x00000020)
#define VE1_DRF_MODE_ve1_drf_mode_6(data)                                            (0x00000020&((data)<<5))
#define VE1_DRF_MODE_ve1_drf_mode_6_src(data)                                        ((0x00000020&(data))>>5)
#define VE1_DRF_MODE_get_ve1_drf_mode_6(data)                                        ((0x00000020&(data))>>5)
#define VE1_DRF_MODE_ve1_drf_mode_5_shift                                            (4)
#define VE1_DRF_MODE_ve1_drf_mode_5_mask                                             (0x00000010)
#define VE1_DRF_MODE_ve1_drf_mode_5(data)                                            (0x00000010&((data)<<4))
#define VE1_DRF_MODE_ve1_drf_mode_5_src(data)                                        ((0x00000010&(data))>>4)
#define VE1_DRF_MODE_get_ve1_drf_mode_5(data)                                        ((0x00000010&(data))>>4)
#define VE1_DRF_MODE_ve1_drf_mode_4_shift                                            (3)
#define VE1_DRF_MODE_ve1_drf_mode_4_mask                                             (0x00000008)
#define VE1_DRF_MODE_ve1_drf_mode_4(data)                                            (0x00000008&((data)<<3))
#define VE1_DRF_MODE_ve1_drf_mode_4_src(data)                                        ((0x00000008&(data))>>3)
#define VE1_DRF_MODE_get_ve1_drf_mode_4(data)                                        ((0x00000008&(data))>>3)
#define VE1_DRF_MODE_ve1_drf_mode_3_shift                                            (2)
#define VE1_DRF_MODE_ve1_drf_mode_3_mask                                             (0x00000004)
#define VE1_DRF_MODE_ve1_drf_mode_3(data)                                            (0x00000004&((data)<<2))
#define VE1_DRF_MODE_ve1_drf_mode_3_src(data)                                        ((0x00000004&(data))>>2)
#define VE1_DRF_MODE_get_ve1_drf_mode_3(data)                                        ((0x00000004&(data))>>2)
#define VE1_DRF_MODE_ve1_drf_mode_2_shift                                            (1)
#define VE1_DRF_MODE_ve1_drf_mode_2_mask                                             (0x00000002)
#define VE1_DRF_MODE_ve1_drf_mode_2(data)                                            (0x00000002&((data)<<1))
#define VE1_DRF_MODE_ve1_drf_mode_2_src(data)                                        ((0x00000002&(data))>>1)
#define VE1_DRF_MODE_get_ve1_drf_mode_2(data)                                        ((0x00000002&(data))>>1)
#define VE1_DRF_MODE_ve1_drf_mode_1_shift                                            (0)
#define VE1_DRF_MODE_ve1_drf_mode_1_mask                                             (0x00000001)
#define VE1_DRF_MODE_ve1_drf_mode_1(data)                                            (0x00000001&((data)<<0))
#define VE1_DRF_MODE_ve1_drf_mode_1_src(data)                                        ((0x00000001&(data))>>0)
#define VE1_DRF_MODE_get_ve1_drf_mode_1(data)                                        ((0x00000001&(data))>>0)


#define VE1_DRF_RESUME                                                               0x1800EF14
#define VE1_DRF_RESUME_reg_addr                                                      "0xB800EF14"
#define VE1_DRF_RESUME_reg                                                           0xB800EF14
#define set_VE1_DRF_RESUME_reg(data)   (*((volatile unsigned int*) VE1_DRF_RESUME_reg)=data)
#define get_VE1_DRF_RESUME_reg   (*((volatile unsigned int*) VE1_DRF_RESUME_reg))
#define VE1_DRF_RESUME_inst_adr                                                      "0x00C5"
#define VE1_DRF_RESUME_inst                                                          0x00C5
#define VE1_DRF_RESUME_ve1_drf_resume_8_shift                                        (7)
#define VE1_DRF_RESUME_ve1_drf_resume_8_mask                                         (0x00000080)
#define VE1_DRF_RESUME_ve1_drf_resume_8(data)                                        (0x00000080&((data)<<7))
#define VE1_DRF_RESUME_ve1_drf_resume_8_src(data)                                    ((0x00000080&(data))>>7)
#define VE1_DRF_RESUME_get_ve1_drf_resume_8(data)                                    ((0x00000080&(data))>>7)
#define VE1_DRF_RESUME_ve1_drf_resume_7_shift                                        (6)
#define VE1_DRF_RESUME_ve1_drf_resume_7_mask                                         (0x00000040)
#define VE1_DRF_RESUME_ve1_drf_resume_7(data)                                        (0x00000040&((data)<<6))
#define VE1_DRF_RESUME_ve1_drf_resume_7_src(data)                                    ((0x00000040&(data))>>6)
#define VE1_DRF_RESUME_get_ve1_drf_resume_7(data)                                    ((0x00000040&(data))>>6)
#define VE1_DRF_RESUME_ve1_drf_resume_6_shift                                        (5)
#define VE1_DRF_RESUME_ve1_drf_resume_6_mask                                         (0x00000020)
#define VE1_DRF_RESUME_ve1_drf_resume_6(data)                                        (0x00000020&((data)<<5))
#define VE1_DRF_RESUME_ve1_drf_resume_6_src(data)                                    ((0x00000020&(data))>>5)
#define VE1_DRF_RESUME_get_ve1_drf_resume_6(data)                                    ((0x00000020&(data))>>5)
#define VE1_DRF_RESUME_ve1_drf_resume_5_shift                                        (4)
#define VE1_DRF_RESUME_ve1_drf_resume_5_mask                                         (0x00000010)
#define VE1_DRF_RESUME_ve1_drf_resume_5(data)                                        (0x00000010&((data)<<4))
#define VE1_DRF_RESUME_ve1_drf_resume_5_src(data)                                    ((0x00000010&(data))>>4)
#define VE1_DRF_RESUME_get_ve1_drf_resume_5(data)                                    ((0x00000010&(data))>>4)
#define VE1_DRF_RESUME_ve1_drf_resume_4_shift                                        (3)
#define VE1_DRF_RESUME_ve1_drf_resume_4_mask                                         (0x00000008)
#define VE1_DRF_RESUME_ve1_drf_resume_4(data)                                        (0x00000008&((data)<<3))
#define VE1_DRF_RESUME_ve1_drf_resume_4_src(data)                                    ((0x00000008&(data))>>3)
#define VE1_DRF_RESUME_get_ve1_drf_resume_4(data)                                    ((0x00000008&(data))>>3)
#define VE1_DRF_RESUME_ve1_drf_resume_3_shift                                        (2)
#define VE1_DRF_RESUME_ve1_drf_resume_3_mask                                         (0x00000004)
#define VE1_DRF_RESUME_ve1_drf_resume_3(data)                                        (0x00000004&((data)<<2))
#define VE1_DRF_RESUME_ve1_drf_resume_3_src(data)                                    ((0x00000004&(data))>>2)
#define VE1_DRF_RESUME_get_ve1_drf_resume_3(data)                                    ((0x00000004&(data))>>2)
#define VE1_DRF_RESUME_ve1_drf_resume_2_shift                                        (1)
#define VE1_DRF_RESUME_ve1_drf_resume_2_mask                                         (0x00000002)
#define VE1_DRF_RESUME_ve1_drf_resume_2(data)                                        (0x00000002&((data)<<1))
#define VE1_DRF_RESUME_ve1_drf_resume_2_src(data)                                    ((0x00000002&(data))>>1)
#define VE1_DRF_RESUME_get_ve1_drf_resume_2(data)                                    ((0x00000002&(data))>>1)
#define VE1_DRF_RESUME_ve1_drf_resume_1_shift                                        (0)
#define VE1_DRF_RESUME_ve1_drf_resume_1_mask                                         (0x00000001)
#define VE1_DRF_RESUME_ve1_drf_resume_1(data)                                        (0x00000001&((data)<<0))
#define VE1_DRF_RESUME_ve1_drf_resume_1_src(data)                                    ((0x00000001&(data))>>0)
#define VE1_DRF_RESUME_get_ve1_drf_resume_1(data)                                    ((0x00000001&(data))>>0)


#define VE1_DRF_PAUSE                                                                0x1800EF18
#define VE1_DRF_PAUSE_reg_addr                                                       "0xB800EF18"
#define VE1_DRF_PAUSE_reg                                                            0xB800EF18
#define set_VE1_DRF_PAUSE_reg(data)   (*((volatile unsigned int*) VE1_DRF_PAUSE_reg)=data)
#define get_VE1_DRF_PAUSE_reg   (*((volatile unsigned int*) VE1_DRF_PAUSE_reg))
#define VE1_DRF_PAUSE_inst_adr                                                       "0x00C6"
#define VE1_DRF_PAUSE_inst                                                           0x00C6
#define VE1_DRF_PAUSE_ve1_drf_pause_8_shift                                          (7)
#define VE1_DRF_PAUSE_ve1_drf_pause_8_mask                                           (0x00000080)
#define VE1_DRF_PAUSE_ve1_drf_pause_8(data)                                          (0x00000080&((data)<<7))
#define VE1_DRF_PAUSE_ve1_drf_pause_8_src(data)                                      ((0x00000080&(data))>>7)
#define VE1_DRF_PAUSE_get_ve1_drf_pause_8(data)                                      ((0x00000080&(data))>>7)
#define VE1_DRF_PAUSE_ve1_drf_pause_7_shift                                          (6)
#define VE1_DRF_PAUSE_ve1_drf_pause_7_mask                                           (0x00000040)
#define VE1_DRF_PAUSE_ve1_drf_pause_7(data)                                          (0x00000040&((data)<<6))
#define VE1_DRF_PAUSE_ve1_drf_pause_7_src(data)                                      ((0x00000040&(data))>>6)
#define VE1_DRF_PAUSE_get_ve1_drf_pause_7(data)                                      ((0x00000040&(data))>>6)
#define VE1_DRF_PAUSE_ve1_drf_pause_6_shift                                          (5)
#define VE1_DRF_PAUSE_ve1_drf_pause_6_mask                                           (0x00000020)
#define VE1_DRF_PAUSE_ve1_drf_pause_6(data)                                          (0x00000020&((data)<<5))
#define VE1_DRF_PAUSE_ve1_drf_pause_6_src(data)                                      ((0x00000020&(data))>>5)
#define VE1_DRF_PAUSE_get_ve1_drf_pause_6(data)                                      ((0x00000020&(data))>>5)
#define VE1_DRF_PAUSE_ve1_drf_pause_5_shift                                          (4)
#define VE1_DRF_PAUSE_ve1_drf_pause_5_mask                                           (0x00000010)
#define VE1_DRF_PAUSE_ve1_drf_pause_5(data)                                          (0x00000010&((data)<<4))
#define VE1_DRF_PAUSE_ve1_drf_pause_5_src(data)                                      ((0x00000010&(data))>>4)
#define VE1_DRF_PAUSE_get_ve1_drf_pause_5(data)                                      ((0x00000010&(data))>>4)
#define VE1_DRF_PAUSE_ve1_drf_pause_4_shift                                          (3)
#define VE1_DRF_PAUSE_ve1_drf_pause_4_mask                                           (0x00000008)
#define VE1_DRF_PAUSE_ve1_drf_pause_4(data)                                          (0x00000008&((data)<<3))
#define VE1_DRF_PAUSE_ve1_drf_pause_4_src(data)                                      ((0x00000008&(data))>>3)
#define VE1_DRF_PAUSE_get_ve1_drf_pause_4(data)                                      ((0x00000008&(data))>>3)
#define VE1_DRF_PAUSE_ve1_drf_pause_3_shift                                          (2)
#define VE1_DRF_PAUSE_ve1_drf_pause_3_mask                                           (0x00000004)
#define VE1_DRF_PAUSE_ve1_drf_pause_3(data)                                          (0x00000004&((data)<<2))
#define VE1_DRF_PAUSE_ve1_drf_pause_3_src(data)                                      ((0x00000004&(data))>>2)
#define VE1_DRF_PAUSE_get_ve1_drf_pause_3(data)                                      ((0x00000004&(data))>>2)
#define VE1_DRF_PAUSE_ve1_drf_pause_2_shift                                          (1)
#define VE1_DRF_PAUSE_ve1_drf_pause_2_mask                                           (0x00000002)
#define VE1_DRF_PAUSE_ve1_drf_pause_2(data)                                          (0x00000002&((data)<<1))
#define VE1_DRF_PAUSE_ve1_drf_pause_2_src(data)                                      ((0x00000002&(data))>>1)
#define VE1_DRF_PAUSE_get_ve1_drf_pause_2(data)                                      ((0x00000002&(data))>>1)
#define VE1_DRF_PAUSE_ve1_drf_pause_1_shift                                          (0)
#define VE1_DRF_PAUSE_ve1_drf_pause_1_mask                                           (0x00000001)
#define VE1_DRF_PAUSE_ve1_drf_pause_1(data)                                          (0x00000001&((data)<<0))
#define VE1_DRF_PAUSE_ve1_drf_pause_1_src(data)                                      ((0x00000001&(data))>>0)
#define VE1_DRF_PAUSE_get_ve1_drf_pause_1(data)                                      ((0x00000001&(data))>>0)


#define VE1_DRF_DONE                                                                 0x1800EF1C
#define VE1_DRF_DONE_reg_addr                                                        "0xB800EF1C"
#define VE1_DRF_DONE_reg                                                             0xB800EF1C
#define set_VE1_DRF_DONE_reg(data)   (*((volatile unsigned int*) VE1_DRF_DONE_reg)=data)
#define get_VE1_DRF_DONE_reg   (*((volatile unsigned int*) VE1_DRF_DONE_reg))
#define VE1_DRF_DONE_inst_adr                                                        "0x00C7"
#define VE1_DRF_DONE_inst                                                            0x00C7
#define VE1_DRF_DONE_ve1_drf_done_8_shift                                            (7)
#define VE1_DRF_DONE_ve1_drf_done_8_mask                                             (0x00000080)
#define VE1_DRF_DONE_ve1_drf_done_8(data)                                            (0x00000080&((data)<<7))
#define VE1_DRF_DONE_ve1_drf_done_8_src(data)                                        ((0x00000080&(data))>>7)
#define VE1_DRF_DONE_get_ve1_drf_done_8(data)                                        ((0x00000080&(data))>>7)
#define VE1_DRF_DONE_ve1_drf_done_7_shift                                            (6)
#define VE1_DRF_DONE_ve1_drf_done_7_mask                                             (0x00000040)
#define VE1_DRF_DONE_ve1_drf_done_7(data)                                            (0x00000040&((data)<<6))
#define VE1_DRF_DONE_ve1_drf_done_7_src(data)                                        ((0x00000040&(data))>>6)
#define VE1_DRF_DONE_get_ve1_drf_done_7(data)                                        ((0x00000040&(data))>>6)
#define VE1_DRF_DONE_ve1_drf_done_6_shift                                            (5)
#define VE1_DRF_DONE_ve1_drf_done_6_mask                                             (0x00000020)
#define VE1_DRF_DONE_ve1_drf_done_6(data)                                            (0x00000020&((data)<<5))
#define VE1_DRF_DONE_ve1_drf_done_6_src(data)                                        ((0x00000020&(data))>>5)
#define VE1_DRF_DONE_get_ve1_drf_done_6(data)                                        ((0x00000020&(data))>>5)
#define VE1_DRF_DONE_ve1_drf_done_5_shift                                            (4)
#define VE1_DRF_DONE_ve1_drf_done_5_mask                                             (0x00000010)
#define VE1_DRF_DONE_ve1_drf_done_5(data)                                            (0x00000010&((data)<<4))
#define VE1_DRF_DONE_ve1_drf_done_5_src(data)                                        ((0x00000010&(data))>>4)
#define VE1_DRF_DONE_get_ve1_drf_done_5(data)                                        ((0x00000010&(data))>>4)
#define VE1_DRF_DONE_ve1_drf_done_4_shift                                            (3)
#define VE1_DRF_DONE_ve1_drf_done_4_mask                                             (0x00000008)
#define VE1_DRF_DONE_ve1_drf_done_4(data)                                            (0x00000008&((data)<<3))
#define VE1_DRF_DONE_ve1_drf_done_4_src(data)                                        ((0x00000008&(data))>>3)
#define VE1_DRF_DONE_get_ve1_drf_done_4(data)                                        ((0x00000008&(data))>>3)
#define VE1_DRF_DONE_ve1_drf_done_3_shift                                            (2)
#define VE1_DRF_DONE_ve1_drf_done_3_mask                                             (0x00000004)
#define VE1_DRF_DONE_ve1_drf_done_3(data)                                            (0x00000004&((data)<<2))
#define VE1_DRF_DONE_ve1_drf_done_3_src(data)                                        ((0x00000004&(data))>>2)
#define VE1_DRF_DONE_get_ve1_drf_done_3(data)                                        ((0x00000004&(data))>>2)
#define VE1_DRF_DONE_ve1_drf_done_2_shift                                            (1)
#define VE1_DRF_DONE_ve1_drf_done_2_mask                                             (0x00000002)
#define VE1_DRF_DONE_ve1_drf_done_2(data)                                            (0x00000002&((data)<<1))
#define VE1_DRF_DONE_ve1_drf_done_2_src(data)                                        ((0x00000002&(data))>>1)
#define VE1_DRF_DONE_get_ve1_drf_done_2(data)                                        ((0x00000002&(data))>>1)
#define VE1_DRF_DONE_ve1_drf_done_1_shift                                            (0)
#define VE1_DRF_DONE_ve1_drf_done_1_mask                                             (0x00000001)
#define VE1_DRF_DONE_ve1_drf_done_1(data)                                            (0x00000001&((data)<<0))
#define VE1_DRF_DONE_ve1_drf_done_1_src(data)                                        ((0x00000001&(data))>>0)
#define VE1_DRF_DONE_get_ve1_drf_done_1(data)                                        ((0x00000001&(data))>>0)


#define VE1_DRF_FAIL_GROUP                                                           0x1800EF20
#define VE1_DRF_FAIL_GROUP_reg_addr                                                  "0xB800EF20"
#define VE1_DRF_FAIL_GROUP_reg                                                       0xB800EF20
#define set_VE1_DRF_FAIL_GROUP_reg(data)   (*((volatile unsigned int*) VE1_DRF_FAIL_GROUP_reg)=data)
#define get_VE1_DRF_FAIL_GROUP_reg   (*((volatile unsigned int*) VE1_DRF_FAIL_GROUP_reg))
#define VE1_DRF_FAIL_GROUP_inst_adr                                                  "0x00C8"
#define VE1_DRF_FAIL_GROUP_inst                                                      0x00C8
#define VE1_DRF_FAIL_GROUP_ve1_drf_fail_group_8_shift                                (7)
#define VE1_DRF_FAIL_GROUP_ve1_drf_fail_group_8_mask                                 (0x00000080)
#define VE1_DRF_FAIL_GROUP_ve1_drf_fail_group_8(data)                                (0x00000080&((data)<<7))
#define VE1_DRF_FAIL_GROUP_ve1_drf_fail_group_8_src(data)                            ((0x00000080&(data))>>7)
#define VE1_DRF_FAIL_GROUP_get_ve1_drf_fail_group_8(data)                            ((0x00000080&(data))>>7)
#define VE1_DRF_FAIL_GROUP_ve1_drf_fail_group_7_shift                                (6)
#define VE1_DRF_FAIL_GROUP_ve1_drf_fail_group_7_mask                                 (0x00000040)
#define VE1_DRF_FAIL_GROUP_ve1_drf_fail_group_7(data)                                (0x00000040&((data)<<6))
#define VE1_DRF_FAIL_GROUP_ve1_drf_fail_group_7_src(data)                            ((0x00000040&(data))>>6)
#define VE1_DRF_FAIL_GROUP_get_ve1_drf_fail_group_7(data)                            ((0x00000040&(data))>>6)
#define VE1_DRF_FAIL_GROUP_ve1_drf_fail_group_6_shift                                (5)
#define VE1_DRF_FAIL_GROUP_ve1_drf_fail_group_6_mask                                 (0x00000020)
#define VE1_DRF_FAIL_GROUP_ve1_drf_fail_group_6(data)                                (0x00000020&((data)<<5))
#define VE1_DRF_FAIL_GROUP_ve1_drf_fail_group_6_src(data)                            ((0x00000020&(data))>>5)
#define VE1_DRF_FAIL_GROUP_get_ve1_drf_fail_group_6(data)                            ((0x00000020&(data))>>5)
#define VE1_DRF_FAIL_GROUP_ve1_drf_fail_group_5_shift                                (4)
#define VE1_DRF_FAIL_GROUP_ve1_drf_fail_group_5_mask                                 (0x00000010)
#define VE1_DRF_FAIL_GROUP_ve1_drf_fail_group_5(data)                                (0x00000010&((data)<<4))
#define VE1_DRF_FAIL_GROUP_ve1_drf_fail_group_5_src(data)                            ((0x00000010&(data))>>4)
#define VE1_DRF_FAIL_GROUP_get_ve1_drf_fail_group_5(data)                            ((0x00000010&(data))>>4)
#define VE1_DRF_FAIL_GROUP_ve1_drf_fail_group_4_shift                                (3)
#define VE1_DRF_FAIL_GROUP_ve1_drf_fail_group_4_mask                                 (0x00000008)
#define VE1_DRF_FAIL_GROUP_ve1_drf_fail_group_4(data)                                (0x00000008&((data)<<3))
#define VE1_DRF_FAIL_GROUP_ve1_drf_fail_group_4_src(data)                            ((0x00000008&(data))>>3)
#define VE1_DRF_FAIL_GROUP_get_ve1_drf_fail_group_4(data)                            ((0x00000008&(data))>>3)
#define VE1_DRF_FAIL_GROUP_ve1_drf_fail_group_3_shift                                (2)
#define VE1_DRF_FAIL_GROUP_ve1_drf_fail_group_3_mask                                 (0x00000004)
#define VE1_DRF_FAIL_GROUP_ve1_drf_fail_group_3(data)                                (0x00000004&((data)<<2))
#define VE1_DRF_FAIL_GROUP_ve1_drf_fail_group_3_src(data)                            ((0x00000004&(data))>>2)
#define VE1_DRF_FAIL_GROUP_get_ve1_drf_fail_group_3(data)                            ((0x00000004&(data))>>2)
#define VE1_DRF_FAIL_GROUP_ve1_drf_fail_group_2_shift                                (1)
#define VE1_DRF_FAIL_GROUP_ve1_drf_fail_group_2_mask                                 (0x00000002)
#define VE1_DRF_FAIL_GROUP_ve1_drf_fail_group_2(data)                                (0x00000002&((data)<<1))
#define VE1_DRF_FAIL_GROUP_ve1_drf_fail_group_2_src(data)                            ((0x00000002&(data))>>1)
#define VE1_DRF_FAIL_GROUP_get_ve1_drf_fail_group_2(data)                            ((0x00000002&(data))>>1)
#define VE1_DRF_FAIL_GROUP_ve1_drf_fail_group_1_shift                                (0)
#define VE1_DRF_FAIL_GROUP_ve1_drf_fail_group_1_mask                                 (0x00000001)
#define VE1_DRF_FAIL_GROUP_ve1_drf_fail_group_1(data)                                (0x00000001&((data)<<0))
#define VE1_DRF_FAIL_GROUP_ve1_drf_fail_group_1_src(data)                            ((0x00000001&(data))>>0)
#define VE1_DRF_FAIL_GROUP_get_ve1_drf_fail_group_1(data)                            ((0x00000001&(data))>>0)


#define VE1_BIST1_FAIL                                                               0x1800EF30
#define VE1_BIST1_FAIL_reg_addr                                                      "0xB800EF30"
#define VE1_BIST1_FAIL_reg                                                           0xB800EF30
#define set_VE1_BIST1_FAIL_reg(data)   (*((volatile unsigned int*) VE1_BIST1_FAIL_reg)=data)
#define get_VE1_BIST1_FAIL_reg   (*((volatile unsigned int*) VE1_BIST1_FAIL_reg))
#define VE1_BIST1_FAIL_inst_adr                                                      "0x00CC"
#define VE1_BIST1_FAIL_inst                                                          0x00CC
#define VE1_BIST1_FAIL_ve1_bist1_fail_shift                                          (0)
#define VE1_BIST1_FAIL_ve1_bist1_fail_mask                                           (0x0000003F)
#define VE1_BIST1_FAIL_ve1_bist1_fail(data)                                          (0x0000003F&((data)<<0))
#define VE1_BIST1_FAIL_ve1_bist1_fail_src(data)                                      ((0x0000003F&(data))>>0)
#define VE1_BIST1_FAIL_get_ve1_bist1_fail(data)                                      ((0x0000003F&(data))>>0)


#define VE1_DRF1_FAIL                                                                0x1800EF34
#define VE1_DRF1_FAIL_reg_addr                                                       "0xB800EF34"
#define VE1_DRF1_FAIL_reg                                                            0xB800EF34
#define set_VE1_DRF1_FAIL_reg(data)   (*((volatile unsigned int*) VE1_DRF1_FAIL_reg)=data)
#define get_VE1_DRF1_FAIL_reg   (*((volatile unsigned int*) VE1_DRF1_FAIL_reg))
#define VE1_DRF1_FAIL_inst_adr                                                       "0x00CD"
#define VE1_DRF1_FAIL_inst                                                           0x00CD
#define VE1_DRF1_FAIL_ve1_drf1_fail_shift                                            (0)
#define VE1_DRF1_FAIL_ve1_drf1_fail_mask                                             (0x0000003F)
#define VE1_DRF1_FAIL_ve1_drf1_fail(data)                                            (0x0000003F&((data)<<0))
#define VE1_DRF1_FAIL_ve1_drf1_fail_src(data)                                        ((0x0000003F&(data))>>0)
#define VE1_DRF1_FAIL_get_ve1_drf1_fail(data)                                        ((0x0000003F&(data))>>0)


#define VE1_BIST2_FAIL                                                               0x1800EF38
#define VE1_BIST2_FAIL_reg_addr                                                      "0xB800EF38"
#define VE1_BIST2_FAIL_reg                                                           0xB800EF38
#define set_VE1_BIST2_FAIL_reg(data)   (*((volatile unsigned int*) VE1_BIST2_FAIL_reg)=data)
#define get_VE1_BIST2_FAIL_reg   (*((volatile unsigned int*) VE1_BIST2_FAIL_reg))
#define VE1_BIST2_FAIL_inst_adr                                                      "0x00CE"
#define VE1_BIST2_FAIL_inst                                                          0x00CE
#define VE1_BIST2_FAIL_ve1_bist2_fail_shift                                          (0)
#define VE1_BIST2_FAIL_ve1_bist2_fail_mask                                           (0x000003FF)
#define VE1_BIST2_FAIL_ve1_bist2_fail(data)                                          (0x000003FF&((data)<<0))
#define VE1_BIST2_FAIL_ve1_bist2_fail_src(data)                                      ((0x000003FF&(data))>>0)
#define VE1_BIST2_FAIL_get_ve1_bist2_fail(data)                                      ((0x000003FF&(data))>>0)


#define VE1_DRF2_FAIL                                                                0x1800EF3C
#define VE1_DRF2_FAIL_reg_addr                                                       "0xB800EF3C"
#define VE1_DRF2_FAIL_reg                                                            0xB800EF3C
#define set_VE1_DRF2_FAIL_reg(data)   (*((volatile unsigned int*) VE1_DRF2_FAIL_reg)=data)
#define get_VE1_DRF2_FAIL_reg   (*((volatile unsigned int*) VE1_DRF2_FAIL_reg))
#define VE1_DRF2_FAIL_inst_adr                                                       "0x00CF"
#define VE1_DRF2_FAIL_inst                                                           0x00CF
#define VE1_DRF2_FAIL_ve1_drf2_fail_shift                                            (0)
#define VE1_DRF2_FAIL_ve1_drf2_fail_mask                                             (0x000003FF)
#define VE1_DRF2_FAIL_ve1_drf2_fail(data)                                            (0x000003FF&((data)<<0))
#define VE1_DRF2_FAIL_ve1_drf2_fail_src(data)                                        ((0x000003FF&(data))>>0)
#define VE1_DRF2_FAIL_get_ve1_drf2_fail(data)                                        ((0x000003FF&(data))>>0)


#define VE1_BIST3_FAIL                                                               0x1800EF40
#define VE1_BIST3_FAIL_reg_addr                                                      "0xB800EF40"
#define VE1_BIST3_FAIL_reg                                                           0xB800EF40
#define set_VE1_BIST3_FAIL_reg(data)   (*((volatile unsigned int*) VE1_BIST3_FAIL_reg)=data)
#define get_VE1_BIST3_FAIL_reg   (*((volatile unsigned int*) VE1_BIST3_FAIL_reg))
#define VE1_BIST3_FAIL_inst_adr                                                      "0x00D0"
#define VE1_BIST3_FAIL_inst                                                          0x00D0
#define VE1_BIST3_FAIL_ve1_bist3_fail_shift                                          (0)
#define VE1_BIST3_FAIL_ve1_bist3_fail_mask                                           (0x0000007F)
#define VE1_BIST3_FAIL_ve1_bist3_fail(data)                                          (0x0000007F&((data)<<0))
#define VE1_BIST3_FAIL_ve1_bist3_fail_src(data)                                      ((0x0000007F&(data))>>0)
#define VE1_BIST3_FAIL_get_ve1_bist3_fail(data)                                      ((0x0000007F&(data))>>0)


#define VE1_DRF3_FAIL                                                                0x1800EF44
#define VE1_DRF3_FAIL_reg_addr                                                       "0xB800EF44"
#define VE1_DRF3_FAIL_reg                                                            0xB800EF44
#define set_VE1_DRF3_FAIL_reg(data)   (*((volatile unsigned int*) VE1_DRF3_FAIL_reg)=data)
#define get_VE1_DRF3_FAIL_reg   (*((volatile unsigned int*) VE1_DRF3_FAIL_reg))
#define VE1_DRF3_FAIL_inst_adr                                                       "0x00D1"
#define VE1_DRF3_FAIL_inst                                                           0x00D1
#define VE1_DRF3_FAIL_ve1_drf3_fail_shift                                            (0)
#define VE1_DRF3_FAIL_ve1_drf3_fail_mask                                             (0x0000007F)
#define VE1_DRF3_FAIL_ve1_drf3_fail(data)                                            (0x0000007F&((data)<<0))
#define VE1_DRF3_FAIL_ve1_drf3_fail_src(data)                                        ((0x0000007F&(data))>>0)
#define VE1_DRF3_FAIL_get_ve1_drf3_fail(data)                                        ((0x0000007F&(data))>>0)


#define VE1_BIST4_FAIL                                                               0x1800EF48
#define VE1_BIST4_FAIL_reg_addr                                                      "0xB800EF48"
#define VE1_BIST4_FAIL_reg                                                           0xB800EF48
#define set_VE1_BIST4_FAIL_reg(data)   (*((volatile unsigned int*) VE1_BIST4_FAIL_reg)=data)
#define get_VE1_BIST4_FAIL_reg   (*((volatile unsigned int*) VE1_BIST4_FAIL_reg))
#define VE1_BIST4_FAIL_inst_adr                                                      "0x00D2"
#define VE1_BIST4_FAIL_inst                                                          0x00D2
#define VE1_BIST4_FAIL_ve1_bist4_fail_shift                                          (0)
#define VE1_BIST4_FAIL_ve1_bist4_fail_mask                                           (0x0000001F)
#define VE1_BIST4_FAIL_ve1_bist4_fail(data)                                          (0x0000001F&((data)<<0))
#define VE1_BIST4_FAIL_ve1_bist4_fail_src(data)                                      ((0x0000001F&(data))>>0)
#define VE1_BIST4_FAIL_get_ve1_bist4_fail(data)                                      ((0x0000001F&(data))>>0)


#define VE1_DRF4_FAIL                                                                0x1800EF4C
#define VE1_DRF4_FAIL_reg_addr                                                       "0xB800EF4C"
#define VE1_DRF4_FAIL_reg                                                            0xB800EF4C
#define set_VE1_DRF4_FAIL_reg(data)   (*((volatile unsigned int*) VE1_DRF4_FAIL_reg)=data)
#define get_VE1_DRF4_FAIL_reg   (*((volatile unsigned int*) VE1_DRF4_FAIL_reg))
#define VE1_DRF4_FAIL_inst_adr                                                       "0x00D3"
#define VE1_DRF4_FAIL_inst                                                           0x00D3
#define VE1_DRF4_FAIL_ve1_drf4_fail_shift                                            (0)
#define VE1_DRF4_FAIL_ve1_drf4_fail_mask                                             (0x0000001F)
#define VE1_DRF4_FAIL_ve1_drf4_fail(data)                                            (0x0000001F&((data)<<0))
#define VE1_DRF4_FAIL_ve1_drf4_fail_src(data)                                        ((0x0000001F&(data))>>0)
#define VE1_DRF4_FAIL_get_ve1_drf4_fail(data)                                        ((0x0000001F&(data))>>0)


#define VE1_BIST5_FAIL                                                               0x1800EF50
#define VE1_BIST5_FAIL_reg_addr                                                      "0xB800EF50"
#define VE1_BIST5_FAIL_reg                                                           0xB800EF50
#define set_VE1_BIST5_FAIL_reg(data)   (*((volatile unsigned int*) VE1_BIST5_FAIL_reg)=data)
#define get_VE1_BIST5_FAIL_reg   (*((volatile unsigned int*) VE1_BIST5_FAIL_reg))
#define VE1_BIST5_FAIL_inst_adr                                                      "0x00D4"
#define VE1_BIST5_FAIL_inst                                                          0x00D4
#define VE1_BIST5_FAIL_ve1_bist5_fail_shift                                          (0)
#define VE1_BIST5_FAIL_ve1_bist5_fail_mask                                           (0x0000003F)
#define VE1_BIST5_FAIL_ve1_bist5_fail(data)                                          (0x0000003F&((data)<<0))
#define VE1_BIST5_FAIL_ve1_bist5_fail_src(data)                                      ((0x0000003F&(data))>>0)
#define VE1_BIST5_FAIL_get_ve1_bist5_fail(data)                                      ((0x0000003F&(data))>>0)


#define VE1_DRF5_FAIL                                                                0x1800EF54
#define VE1_DRF5_FAIL_reg_addr                                                       "0xB800EF54"
#define VE1_DRF5_FAIL_reg                                                            0xB800EF54
#define set_VE1_DRF5_FAIL_reg(data)   (*((volatile unsigned int*) VE1_DRF5_FAIL_reg)=data)
#define get_VE1_DRF5_FAIL_reg   (*((volatile unsigned int*) VE1_DRF5_FAIL_reg))
#define VE1_DRF5_FAIL_inst_adr                                                       "0x00D5"
#define VE1_DRF5_FAIL_inst                                                           0x00D5
#define VE1_DRF5_FAIL_ve1_drf5_fail_shift                                            (0)
#define VE1_DRF5_FAIL_ve1_drf5_fail_mask                                             (0x0000003F)
#define VE1_DRF5_FAIL_ve1_drf5_fail(data)                                            (0x0000003F&((data)<<0))
#define VE1_DRF5_FAIL_ve1_drf5_fail_src(data)                                        ((0x0000003F&(data))>>0)
#define VE1_DRF5_FAIL_get_ve1_drf5_fail(data)                                        ((0x0000003F&(data))>>0)


#define VE1_BIST6_FAIL                                                               0x1800EF58
#define VE1_BIST6_FAIL_reg_addr                                                      "0xB800EF58"
#define VE1_BIST6_FAIL_reg                                                           0xB800EF58
#define set_VE1_BIST6_FAIL_reg(data)   (*((volatile unsigned int*) VE1_BIST6_FAIL_reg)=data)
#define get_VE1_BIST6_FAIL_reg   (*((volatile unsigned int*) VE1_BIST6_FAIL_reg))
#define VE1_BIST6_FAIL_inst_adr                                                      "0x00D6"
#define VE1_BIST6_FAIL_inst                                                          0x00D6
#define VE1_BIST6_FAIL_ve1_bist6_fail_shift                                          (0)
#define VE1_BIST6_FAIL_ve1_bist6_fail_mask                                           (0x0000001F)
#define VE1_BIST6_FAIL_ve1_bist6_fail(data)                                          (0x0000001F&((data)<<0))
#define VE1_BIST6_FAIL_ve1_bist6_fail_src(data)                                      ((0x0000001F&(data))>>0)
#define VE1_BIST6_FAIL_get_ve1_bist6_fail(data)                                      ((0x0000001F&(data))>>0)


#define VE1_DRF6_FAIL                                                                0x1800EF5C
#define VE1_DRF6_FAIL_reg_addr                                                       "0xB800EF5C"
#define VE1_DRF6_FAIL_reg                                                            0xB800EF5C
#define set_VE1_DRF6_FAIL_reg(data)   (*((volatile unsigned int*) VE1_DRF6_FAIL_reg)=data)
#define get_VE1_DRF6_FAIL_reg   (*((volatile unsigned int*) VE1_DRF6_FAIL_reg))
#define VE1_DRF6_FAIL_inst_adr                                                       "0x00D7"
#define VE1_DRF6_FAIL_inst                                                           0x00D7
#define VE1_DRF6_FAIL_ve1_drf6_fail_shift                                            (0)
#define VE1_DRF6_FAIL_ve1_drf6_fail_mask                                             (0x0000001F)
#define VE1_DRF6_FAIL_ve1_drf6_fail(data)                                            (0x0000001F&((data)<<0))
#define VE1_DRF6_FAIL_ve1_drf6_fail_src(data)                                        ((0x0000001F&(data))>>0)
#define VE1_DRF6_FAIL_get_ve1_drf6_fail(data)                                        ((0x0000001F&(data))>>0)


#define VE1_BIST7_FAIL                                                               0x1800EF60
#define VE1_BIST7_FAIL_reg_addr                                                      "0xB800EF60"
#define VE1_BIST7_FAIL_reg                                                           0xB800EF60
#define set_VE1_BIST7_FAIL_reg(data)   (*((volatile unsigned int*) VE1_BIST7_FAIL_reg)=data)
#define get_VE1_BIST7_FAIL_reg   (*((volatile unsigned int*) VE1_BIST7_FAIL_reg))
#define VE1_BIST7_FAIL_inst_adr                                                      "0x00D8"
#define VE1_BIST7_FAIL_inst                                                          0x00D8
#define VE1_BIST7_FAIL_ve1_bist7_fail_shift                                          (0)
#define VE1_BIST7_FAIL_ve1_bist7_fail_mask                                           (0x000001FF)
#define VE1_BIST7_FAIL_ve1_bist7_fail(data)                                          (0x000001FF&((data)<<0))
#define VE1_BIST7_FAIL_ve1_bist7_fail_src(data)                                      ((0x000001FF&(data))>>0)
#define VE1_BIST7_FAIL_get_ve1_bist7_fail(data)                                      ((0x000001FF&(data))>>0)


#define VE1_DRF7_FAIL                                                                0x1800EF64
#define VE1_DRF7_FAIL_reg_addr                                                       "0xB800EF64"
#define VE1_DRF7_FAIL_reg                                                            0xB800EF64
#define set_VE1_DRF7_FAIL_reg(data)   (*((volatile unsigned int*) VE1_DRF7_FAIL_reg)=data)
#define get_VE1_DRF7_FAIL_reg   (*((volatile unsigned int*) VE1_DRF7_FAIL_reg))
#define VE1_DRF7_FAIL_inst_adr                                                       "0x00D9"
#define VE1_DRF7_FAIL_inst                                                           0x00D9
#define VE1_DRF7_FAIL_ve1_drf7_fail_shift                                            (0)
#define VE1_DRF7_FAIL_ve1_drf7_fail_mask                                             (0x000001FF)
#define VE1_DRF7_FAIL_ve1_drf7_fail(data)                                            (0x000001FF&((data)<<0))
#define VE1_DRF7_FAIL_ve1_drf7_fail_src(data)                                        ((0x000001FF&(data))>>0)
#define VE1_DRF7_FAIL_get_ve1_drf7_fail(data)                                        ((0x000001FF&(data))>>0)


#define VE1_BIST8_FAIL                                                               0x1800EF68
#define VE1_BIST8_FAIL_reg_addr                                                      "0xB800EF68"
#define VE1_BIST8_FAIL_reg                                                           0xB800EF68
#define set_VE1_BIST8_FAIL_reg(data)   (*((volatile unsigned int*) VE1_BIST8_FAIL_reg)=data)
#define get_VE1_BIST8_FAIL_reg   (*((volatile unsigned int*) VE1_BIST8_FAIL_reg))
#define VE1_BIST8_FAIL_inst_adr                                                      "0x00DA"
#define VE1_BIST8_FAIL_inst                                                          0x00DA
#define VE1_BIST8_FAIL_ve1_bist8_fail_shift                                          (0)
#define VE1_BIST8_FAIL_ve1_bist8_fail_mask                                           (0x000003FF)
#define VE1_BIST8_FAIL_ve1_bist8_fail(data)                                          (0x000003FF&((data)<<0))
#define VE1_BIST8_FAIL_ve1_bist8_fail_src(data)                                      ((0x000003FF&(data))>>0)
#define VE1_BIST8_FAIL_get_ve1_bist8_fail(data)                                      ((0x000003FF&(data))>>0)


#define VE1_DRF8_FAIL                                                                0x1800EF6C
#define VE1_DRF8_FAIL_reg_addr                                                       "0xB800EF6C"
#define VE1_DRF8_FAIL_reg                                                            0xB800EF6C
#define set_VE1_DRF8_FAIL_reg(data)   (*((volatile unsigned int*) VE1_DRF8_FAIL_reg)=data)
#define get_VE1_DRF8_FAIL_reg   (*((volatile unsigned int*) VE1_DRF8_FAIL_reg))
#define VE1_DRF8_FAIL_inst_adr                                                       "0x00DB"
#define VE1_DRF8_FAIL_inst                                                           0x00DB
#define VE1_DRF8_FAIL_ve1_drf8_fail_shift                                            (0)
#define VE1_DRF8_FAIL_ve1_drf8_fail_mask                                             (0x000003FF)
#define VE1_DRF8_FAIL_ve1_drf8_fail(data)                                            (0x000003FF&((data)<<0))
#define VE1_DRF8_FAIL_ve1_drf8_fail_src(data)                                        ((0x000003FF&(data))>>0)
#define VE1_DRF8_FAIL_get_ve1_drf8_fail(data)                                        ((0x000003FF&(data))>>0)


#endif
