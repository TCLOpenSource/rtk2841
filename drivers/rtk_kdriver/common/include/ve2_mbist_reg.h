/**************************************************************
// Spec Version                  : unknown
// Parser Version                : DVR_Parser_6.8(110516)
// CModelGen Version             : 5.0 2009.04.09
// Naming Rule                   :  Register_Name
// Naming Rule                   : Module_Register_Name_reg
// Parse Option                  : Only Parse _op1
// Parse Address Region          : All Address Region 
// Decode bit number             : 12 bits
// Firmware Header Generate Date : 2012/8/1 15:23:47
***************************************************************/


#ifndef _VE2_MBIST_REG_H_INCLUDED_
#define _VE2_MBIST_REG_H_INCLUDED_
#ifdef  _VE2_MBIST_USE_STRUCT
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
}VE2_BIST_RM;

typedef struct 
{
unsigned int     reserved_0:19;
unsigned int     ve2_bist_mode_13:1;
unsigned int     ve2_bist_mode_12:1;
unsigned int     ve2_bist_mode_11:1;
unsigned int     ve2_bist_mode_10:1;
unsigned int     ve2_bist_mode_9:1;
unsigned int     ve2_bist_mode_8:1;
unsigned int     ve2_bist_mode_7:1;
unsigned int     ve2_bist_mode_6:1;
unsigned int     ve2_bist_mode_5:1;
unsigned int     ve2_bist_mode_4:1;
unsigned int     ve2_bist_mode_3:1;
unsigned int     ve2_bist_mode_2:1;
unsigned int     ve2_bist_mode_1:1;
}VE2_BIST_MODE;

typedef struct 
{
unsigned int     reserved_0:19;
unsigned int     ve2_bist_done_13:1;
unsigned int     ve2_bist_done_12:1;
unsigned int     ve2_bist_done_11:1;
unsigned int     ve2_bist_done_10:1;
unsigned int     ve2_bist_done_9:1;
unsigned int     ve2_bist_done_8:1;
unsigned int     ve2_bist_done_7:1;
unsigned int     ve2_bist_done_6:1;
unsigned int     ve2_bist_done_5:1;
unsigned int     ve2_bist_done_4:1;
unsigned int     ve2_bist_done_3:1;
unsigned int     ve2_bist_done_2:1;
unsigned int     ve2_bist_done_1:1;
}VE2_BIST_DONE;

typedef struct 
{
unsigned int     reserved_0:19;
unsigned int     ve2_bist_fail_group_13:1;
unsigned int     ve2_bist_fail_group_12:1;
unsigned int     ve2_bist_fail_group_11:1;
unsigned int     ve2_bist_fail_group_10:1;
unsigned int     ve2_bist_fail_group_9:1;
unsigned int     ve2_bist_fail_group_8:1;
unsigned int     ve2_bist_fail_group_7:1;
unsigned int     ve2_bist_fail_group_6:1;
unsigned int     ve2_bist_fail_group_5:1;
unsigned int     ve2_bist_fail_group_4:1;
unsigned int     ve2_bist_fail_group_3:1;
unsigned int     ve2_bist_fail_group_2:1;
unsigned int     ve2_bist_fail_group_1:1;
}VE2_BIST_FAIL_GROUP;

typedef struct 
{
unsigned int     reserved_0:19;
unsigned int     ve2_drf_mode_13:1;
unsigned int     ve2_drf_mode_12:1;
unsigned int     ve2_drf_mode_11:1;
unsigned int     ve2_drf_mode_10:1;
unsigned int     ve2_drf_mode_9:1;
unsigned int     ve2_drf_mode_8:1;
unsigned int     ve2_drf_mode_7:1;
unsigned int     ve2_drf_mode_6:1;
unsigned int     ve2_drf_mode_5:1;
unsigned int     ve2_drf_mode_4:1;
unsigned int     ve2_drf_mode_3:1;
unsigned int     ve2_drf_mode_2:1;
unsigned int     ve2_drf_mode_1:1;
}VE2_DRF_MODE;

typedef struct 
{
unsigned int     reserved_0:19;
unsigned int     ve2_drf_resume_13:1;
unsigned int     ve2_drf_resume_12:1;
unsigned int     ve2_drf_resume_11:1;
unsigned int     ve2_drf_resume_10:1;
unsigned int     ve2_drf_resume_9:1;
unsigned int     ve2_drf_resume_8:1;
unsigned int     ve2_drf_resume_7:1;
unsigned int     ve2_drf_resume_6:1;
unsigned int     ve2_drf_resume_5:1;
unsigned int     ve2_drf_resume_4:1;
unsigned int     ve2_drf_resume_3:1;
unsigned int     ve2_drf_resume_2:1;
unsigned int     ve2_drf_resume_1:1;
}VE2_DRF_RESUME;

typedef struct 
{
unsigned int     reserved_0:19;
unsigned int     ve2_drf_pause_13:1;
unsigned int     ve2_drf_pause_12:1;
unsigned int     ve2_drf_pause_11:1;
unsigned int     ve2_drf_pause_10:1;
unsigned int     ve2_drf_pause_9:1;
unsigned int     ve2_drf_pause_8:1;
unsigned int     ve2_drf_pause_7:1;
unsigned int     ve2_drf_pause_6:1;
unsigned int     ve2_drf_pause_5:1;
unsigned int     ve2_drf_pause_4:1;
unsigned int     ve2_drf_pause_3:1;
unsigned int     ve2_drf_pause_2:1;
unsigned int     ve2_drf_pause_1:1;
}VE2_DRF_PAUSE;

typedef struct 
{
unsigned int     reserved_0:19;
unsigned int     ve2_drf_done_13:1;
unsigned int     ve2_drf_done_12:1;
unsigned int     ve2_drf_done_11:1;
unsigned int     ve2_drf_done_10:1;
unsigned int     ve2_drf_done_9:1;
unsigned int     ve2_drf_done_8:1;
unsigned int     ve2_drf_done_7:1;
unsigned int     ve2_drf_done_6:1;
unsigned int     ve2_drf_done_5:1;
unsigned int     ve2_drf_done_4:1;
unsigned int     ve2_drf_done_3:1;
unsigned int     ve2_drf_done_2:1;
unsigned int     ve2_drf_done_1:1;
}VE2_DRF_DONE;

typedef struct 
{
unsigned int     reserved_0:19;
unsigned int     ve2_drf_fail_group_13:1;
unsigned int     ve2_drf_fail_group_12:1;
unsigned int     ve2_drf_fail_group_11:1;
unsigned int     ve2_drf_fail_group_10:1;
unsigned int     ve2_drf_fail_group_9:1;
unsigned int     ve2_drf_fail_group_8:1;
unsigned int     ve2_drf_fail_group_7:1;
unsigned int     ve2_drf_fail_group_6:1;
unsigned int     ve2_drf_fail_group_5:1;
unsigned int     ve2_drf_fail_group_4:1;
unsigned int     ve2_drf_fail_group_3:1;
unsigned int     ve2_drf_fail_group_2:1;
unsigned int     ve2_drf_fail_group_1:1;
}VE2_DRF_FAIL_GROUP;

typedef struct 
{
unsigned int     reserved_0:22;
unsigned int     ve2_bist1_fail:10;
}VE2_BIST1_FAIL;

typedef struct 
{
unsigned int     reserved_0:22;
unsigned int     ve2_drf1_fail:10;
}VE2_DRF1_FAIL;

typedef struct 
{
unsigned int     reserved_0:26;
unsigned int     ve2_bist2_fail:6;
}VE2_BIST2_FAIL;

typedef struct 
{
unsigned int     reserved_0:26;
unsigned int     ve2_drf2_fail:6;
}VE2_DRF2_FAIL;

typedef struct 
{
unsigned int     reserved_0:25;
unsigned int     ve2_bist3_fail:7;
}VE2_BIST3_FAIL;

typedef struct 
{
unsigned int     reserved_0:25;
unsigned int     ve2_drf3_fail:7;
}VE2_DRF3_FAIL;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     ve2_bist4_fail:8;
}VE2_BIST4_FAIL;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     ve2_drf4_fail:8;
}VE2_DRF4_FAIL;

typedef struct 
{
unsigned int     reserved_0:26;
unsigned int     ve2_bist5_fail:6;
}VE2_BIST5_FAIL;

typedef struct 
{
unsigned int     reserved_0:26;
unsigned int     ve2_drf5_fail:6;
}VE2_DRF5_FAIL;

typedef struct 
{
unsigned int     reserved_0:26;
unsigned int     ve2_bist6_fail:6;
}VE2_BIST6_FAIL;

typedef struct 
{
unsigned int     reserved_0:26;
unsigned int     ve2_drf6_fail:6;
}VE2_DRF6_FAIL;

typedef struct 
{
unsigned int     reserved_0:22;
unsigned int     ve2_bist7_fail:10;
}VE2_BIST7_FAIL;

typedef struct 
{
unsigned int     reserved_0:22;
unsigned int     ve2_drf7_fail:10;
}VE2_DRF7_FAIL;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     ve2_bist8_fail:8;
}VE2_BIST8_FAIL;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     ve2_drf8_fail:8;
}VE2_DRF8_FAIL;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     ve2_bist9_fail:8;
}VE2_BIST9_FAIL;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     ve2_drf9_fail:8;
}VE2_DRF9_FAIL;

typedef struct 
{
unsigned int     reserved_0:27;
unsigned int     ve2_bist10_fail:5;
}VE2_BIST10_FAIL;

typedef struct 
{
unsigned int     reserved_0:27;
unsigned int     ve2_drf10_fail:5;
}VE2_DRF10_FAIL;

typedef struct 
{
unsigned int     reserved_0:25;
unsigned int     ve2_bist11_fail:7;
}VE2_BIST11_FAIL;

typedef struct 
{
unsigned int     reserved_0:25;
unsigned int     ve2_drf11_fail:7;
}VE2_DRF11_FAIL;

typedef struct 
{
unsigned int     reserved_0:23;
unsigned int     ve2_bist12_fail:9;
}VE2_BIST12_FAIL;

typedef struct 
{
unsigned int     reserved_0:23;
unsigned int     ve2_drf12_fail:9;
}VE2_DRF12_FAIL;

typedef struct 
{
unsigned int     reserved_0:27;
unsigned int     ve2_bist13_fail:5;
}VE2_BIST12_FAIL;

typedef struct 
{
unsigned int     reserved_0:27;
unsigned int     ve2_drf13_fail:5;
}VE2_DRF12_FAIL;

#endif

#define VE2_BIST_RM                                                                  0x18036F00
#define VE2_BIST_RM_reg_addr                                                         "0xB8036F00"
#define VE2_BIST_RM_reg                                                              0xB8036F00
#define set_VE2_BIST_RM_reg(data)   (*((volatile unsigned int*) VE2_BIST_RM_reg)=data)
#define get_VE2_BIST_RM_reg   (*((volatile unsigned int*) VE2_BIST_RM_reg))
#define VE2_BIST_RM_inst_adr                                                         "0x00C0"
#define VE2_BIST_RM_inst                                                             0x00C0
#define VE2_BIST_RM_bist_2p_clk_sel_shift                                            (31)
#define VE2_BIST_RM_bist_2p_clk_sel_mask                                             (0x80000000)
#define VE2_BIST_RM_bist_2p_clk_sel(data)                                            (0x80000000&((data)<<31))
#define VE2_BIST_RM_bist_2p_clk_sel_src(data)                                        ((0x80000000&(data))>>31)
#define VE2_BIST_RM_get_bist_2p_clk_sel(data)                                        ((0x80000000&(data))>>31)
#define VE2_BIST_RM_LS_shift                                                         (30)
#define VE2_BIST_RM_LS_mask                                                          (0x40000000)
#define VE2_BIST_RM_LS(data)                                                         (0x40000000&((data)<<30))
#define VE2_BIST_RM_LS_src(data)                                                     ((0x40000000&(data))>>30)
#define VE2_BIST_RM_get_LS(data)                                                     ((0x40000000&(data))>>30)
#define VE2_BIST_RM_SYSH_RMEA_shift                                                  (29)
#define VE2_BIST_RM_SYSH_RMEA_mask                                                   (0x20000000)
#define VE2_BIST_RM_SYSH_RMEA(data)                                                  (0x20000000&((data)<<29))
#define VE2_BIST_RM_SYSH_RMEA_src(data)                                              ((0x20000000&(data))>>29)
#define VE2_BIST_RM_get_SYSH_RMEA(data)                                              ((0x20000000&(data))>>29)
#define VE2_BIST_RM_SYSH_RMA_shift                                                   (25)
#define VE2_BIST_RM_SYSH_RMA_mask                                                    (0x1E000000)
#define VE2_BIST_RM_SYSH_RMA(data)                                                   (0x1E000000&((data)<<25))
#define VE2_BIST_RM_SYSH_RMA_src(data)                                               ((0x1E000000&(data))>>25)
#define VE2_BIST_RM_get_SYSH_RMA(data)                                               ((0x1E000000&(data))>>25)
#define VE2_BIST_RM_SYSH_RMEB_shift                                                  (24)
#define VE2_BIST_RM_SYSH_RMEB_mask                                                   (0x01000000)
#define VE2_BIST_RM_SYSH_RMEB(data)                                                  (0x01000000&((data)<<24))
#define VE2_BIST_RM_SYSH_RMEB_src(data)                                              ((0x01000000&(data))>>24)
#define VE2_BIST_RM_get_SYSH_RMEB(data)                                              ((0x01000000&(data))>>24)
#define VE2_BIST_RM_SYSH_RMB_shift                                                   (20)
#define VE2_BIST_RM_SYSH_RMB_mask                                                    (0x00F00000)
#define VE2_BIST_RM_SYSH_RMB(data)                                                   (0x00F00000&((data)<<20))
#define VE2_BIST_RM_SYSH_RMB_src(data)                                               ((0x00F00000&(data))>>20)
#define VE2_BIST_RM_get_SYSH_RMB(data)                                               ((0x00F00000&(data))>>20)
#define VE2_BIST_RM_SYSH_RME_shift                                                   (19)
#define VE2_BIST_RM_SYSH_RME_mask                                                    (0x00080000)
#define VE2_BIST_RM_SYSH_RME(data)                                                   (0x00080000&((data)<<19))
#define VE2_BIST_RM_SYSH_RME_src(data)                                               ((0x00080000&(data))>>19)
#define VE2_BIST_RM_get_SYSH_RME(data)                                               ((0x00080000&(data))>>19)
#define VE2_BIST_RM_SYSH_RM_shift                                                    (15)
#define VE2_BIST_RM_SYSH_RM_mask                                                     (0x00078000)
#define VE2_BIST_RM_SYSH_RM(data)                                                    (0x00078000&((data)<<15))
#define VE2_BIST_RM_SYSH_RM_src(data)                                                ((0x00078000&(data))>>15)
#define VE2_BIST_RM_get_SYSH_RM(data)                                                ((0x00078000&(data))>>15)
#define VE2_BIST_RM_RMEA_shift                                                       (14)
#define VE2_BIST_RM_RMEA_mask                                                        (0x00004000)
#define VE2_BIST_RM_RMEA(data)                                                       (0x00004000&((data)<<14))
#define VE2_BIST_RM_RMEA_src(data)                                                   ((0x00004000&(data))>>14)
#define VE2_BIST_RM_get_RMEA(data)                                                   ((0x00004000&(data))>>14)
#define VE2_BIST_RM_RMA_shift                                                        (10)
#define VE2_BIST_RM_RMA_mask                                                         (0x00003C00)
#define VE2_BIST_RM_RMA(data)                                                        (0x00003C00&((data)<<10))
#define VE2_BIST_RM_RMA_src(data)                                                    ((0x00003C00&(data))>>10)
#define VE2_BIST_RM_get_RMA(data)                                                    ((0x00003C00&(data))>>10)
#define VE2_BIST_RM_RMEB_shift                                                       (9)
#define VE2_BIST_RM_RMEB_mask                                                        (0x00000200)
#define VE2_BIST_RM_RMEB(data)                                                       (0x00000200&((data)<<9))
#define VE2_BIST_RM_RMEB_src(data)                                                   ((0x00000200&(data))>>9)
#define VE2_BIST_RM_get_RMEB(data)                                                   ((0x00000200&(data))>>9)
#define VE2_BIST_RM_RMB_shift                                                        (5)
#define VE2_BIST_RM_RMB_mask                                                         (0x000001E0)
#define VE2_BIST_RM_RMB(data)                                                        (0x000001E0&((data)<<5))
#define VE2_BIST_RM_RMB_src(data)                                                    ((0x000001E0&(data))>>5)
#define VE2_BIST_RM_get_RMB(data)                                                    ((0x000001E0&(data))>>5)
#define VE2_BIST_RM_RME_shift                                                        (4)
#define VE2_BIST_RM_RME_mask                                                         (0x00000010)
#define VE2_BIST_RM_RME(data)                                                        (0x00000010&((data)<<4))
#define VE2_BIST_RM_RME_src(data)                                                    ((0x00000010&(data))>>4)
#define VE2_BIST_RM_get_RME(data)                                                    ((0x00000010&(data))>>4)
#define VE2_BIST_RM_RM_shift                                                         (0)
#define VE2_BIST_RM_RM_mask                                                          (0x0000000F)
#define VE2_BIST_RM_RM(data)                                                         (0x0000000F&((data)<<0))
#define VE2_BIST_RM_RM_src(data)                                                     ((0x0000000F&(data))>>0)
#define VE2_BIST_RM_get_RM(data)                                                     ((0x0000000F&(data))>>0)


#define VE2_BIST_MODE                                                                0x18036F04
#define VE2_BIST_MODE_reg_addr                                                       "0xB8036F04"
#define VE2_BIST_MODE_reg                                                            0xB8036F04
#define set_VE2_BIST_MODE_reg(data)   (*((volatile unsigned int*) VE2_BIST_MODE_reg)=data)
#define get_VE2_BIST_MODE_reg   (*((volatile unsigned int*) VE2_BIST_MODE_reg))
#define VE2_BIST_MODE_inst_adr                                                       "0x00C1"
#define VE2_BIST_MODE_inst                                                           0x00C1
#define VE2_BIST_MODE_ve2_bist_mode_13_shift                                         (12)
#define VE2_BIST_MODE_ve2_bist_mode_13_mask                                          (0x00001000)
#define VE2_BIST_MODE_ve2_bist_mode_13(data)                                         (0x00001000&((data)<<12))
#define VE2_BIST_MODE_ve2_bist_mode_13_src(data)                                     ((0x00001000&(data))>>12)
#define VE2_BIST_MODE_get_ve2_bist_mode_13(data)                                     ((0x00001000&(data))>>12)
#define VE2_BIST_MODE_ve2_bist_mode_12_shift                                         (11)
#define VE2_BIST_MODE_ve2_bist_mode_12_mask                                          (0x00000800)
#define VE2_BIST_MODE_ve2_bist_mode_12(data)                                         (0x00000800&((data)<<11))
#define VE2_BIST_MODE_ve2_bist_mode_12_src(data)                                     ((0x00000800&(data))>>11)
#define VE2_BIST_MODE_get_ve2_bist_mode_12(data)                                     ((0x00000800&(data))>>11)
#define VE2_BIST_MODE_ve2_bist_mode_11_shift                                         (10)
#define VE2_BIST_MODE_ve2_bist_mode_11_mask                                          (0x00000400)
#define VE2_BIST_MODE_ve2_bist_mode_11(data)                                         (0x00000400&((data)<<10))
#define VE2_BIST_MODE_ve2_bist_mode_11_src(data)                                     ((0x00000400&(data))>>10)
#define VE2_BIST_MODE_get_ve2_bist_mode_11(data)                                     ((0x00000400&(data))>>10)
#define VE2_BIST_MODE_ve2_bist_mode_10_shift                                         (9)
#define VE2_BIST_MODE_ve2_bist_mode_10_mask                                          (0x00000200)
#define VE2_BIST_MODE_ve2_bist_mode_10(data)                                         (0x00000200&((data)<<9))
#define VE2_BIST_MODE_ve2_bist_mode_10_src(data)                                     ((0x00000200&(data))>>9)
#define VE2_BIST_MODE_get_ve2_bist_mode_10(data)                                     ((0x00000200&(data))>>9)
#define VE2_BIST_MODE_ve2_bist_mode_9_shift                                          (8)
#define VE2_BIST_MODE_ve2_bist_mode_9_mask                                           (0x00000100)
#define VE2_BIST_MODE_ve2_bist_mode_9(data)                                          (0x00000100&((data)<<8))
#define VE2_BIST_MODE_ve2_bist_mode_9_src(data)                                      ((0x00000100&(data))>>8)
#define VE2_BIST_MODE_get_ve2_bist_mode_9(data)                                      ((0x00000100&(data))>>8)
#define VE2_BIST_MODE_ve2_bist_mode_8_shift                                          (7)
#define VE2_BIST_MODE_ve2_bist_mode_8_mask                                           (0x00000080)
#define VE2_BIST_MODE_ve2_bist_mode_8(data)                                          (0x00000080&((data)<<7))
#define VE2_BIST_MODE_ve2_bist_mode_8_src(data)                                      ((0x00000080&(data))>>7)
#define VE2_BIST_MODE_get_ve2_bist_mode_8(data)                                      ((0x00000080&(data))>>7)
#define VE2_BIST_MODE_ve2_bist_mode_7_shift                                          (6)
#define VE2_BIST_MODE_ve2_bist_mode_7_mask                                           (0x00000040)
#define VE2_BIST_MODE_ve2_bist_mode_7(data)                                          (0x00000040&((data)<<6))
#define VE2_BIST_MODE_ve2_bist_mode_7_src(data)                                      ((0x00000040&(data))>>6)
#define VE2_BIST_MODE_get_ve2_bist_mode_7(data)                                      ((0x00000040&(data))>>6)
#define VE2_BIST_MODE_ve2_bist_mode_6_shift                                          (5)
#define VE2_BIST_MODE_ve2_bist_mode_6_mask                                           (0x00000020)
#define VE2_BIST_MODE_ve2_bist_mode_6(data)                                          (0x00000020&((data)<<5))
#define VE2_BIST_MODE_ve2_bist_mode_6_src(data)                                      ((0x00000020&(data))>>5)
#define VE2_BIST_MODE_get_ve2_bist_mode_6(data)                                      ((0x00000020&(data))>>5)
#define VE2_BIST_MODE_ve2_bist_mode_5_shift                                          (4)
#define VE2_BIST_MODE_ve2_bist_mode_5_mask                                           (0x00000010)
#define VE2_BIST_MODE_ve2_bist_mode_5(data)                                          (0x00000010&((data)<<4))
#define VE2_BIST_MODE_ve2_bist_mode_5_src(data)                                      ((0x00000010&(data))>>4)
#define VE2_BIST_MODE_get_ve2_bist_mode_5(data)                                      ((0x00000010&(data))>>4)
#define VE2_BIST_MODE_ve2_bist_mode_4_shift                                          (3)
#define VE2_BIST_MODE_ve2_bist_mode_4_mask                                           (0x00000008)
#define VE2_BIST_MODE_ve2_bist_mode_4(data)                                          (0x00000008&((data)<<3))
#define VE2_BIST_MODE_ve2_bist_mode_4_src(data)                                      ((0x00000008&(data))>>3)
#define VE2_BIST_MODE_get_ve2_bist_mode_4(data)                                      ((0x00000008&(data))>>3)
#define VE2_BIST_MODE_ve2_bist_mode_3_shift                                          (2)
#define VE2_BIST_MODE_ve2_bist_mode_3_mask                                           (0x00000004)
#define VE2_BIST_MODE_ve2_bist_mode_3(data)                                          (0x00000004&((data)<<2))
#define VE2_BIST_MODE_ve2_bist_mode_3_src(data)                                      ((0x00000004&(data))>>2)
#define VE2_BIST_MODE_get_ve2_bist_mode_3(data)                                      ((0x00000004&(data))>>2)
#define VE2_BIST_MODE_ve2_bist_mode_2_shift                                          (1)
#define VE2_BIST_MODE_ve2_bist_mode_2_mask                                           (0x00000002)
#define VE2_BIST_MODE_ve2_bist_mode_2(data)                                          (0x00000002&((data)<<1))
#define VE2_BIST_MODE_ve2_bist_mode_2_src(data)                                      ((0x00000002&(data))>>1)
#define VE2_BIST_MODE_get_ve2_bist_mode_2(data)                                      ((0x00000002&(data))>>1)
#define VE2_BIST_MODE_ve2_bist_mode_1_shift                                          (0)
#define VE2_BIST_MODE_ve2_bist_mode_1_mask                                           (0x00000001)
#define VE2_BIST_MODE_ve2_bist_mode_1(data)                                          (0x00000001&((data)<<0))
#define VE2_BIST_MODE_ve2_bist_mode_1_src(data)                                      ((0x00000001&(data))>>0)
#define VE2_BIST_MODE_get_ve2_bist_mode_1(data)                                      ((0x00000001&(data))>>0)


#define VE2_BIST_DONE                                                                0x18036F08
#define VE2_BIST_DONE_reg_addr                                                       "0xB8036F08"
#define VE2_BIST_DONE_reg                                                            0xB8036F08
#define set_VE2_BIST_DONE_reg(data)   (*((volatile unsigned int*) VE2_BIST_DONE_reg)=data)
#define get_VE2_BIST_DONE_reg   (*((volatile unsigned int*) VE2_BIST_DONE_reg))
#define VE2_BIST_DONE_inst_adr                                                       "0x00C2"
#define VE2_BIST_DONE_inst                                                           0x00C2
#define VE2_BIST_DONE_ve2_bist_done_13_shift                                         (12)
#define VE2_BIST_DONE_ve2_bist_done_13_mask                                          (0x00001000)
#define VE2_BIST_DONE_ve2_bist_done_13(data)                                         (0x00001000&((data)<<12))
#define VE2_BIST_DONE_ve2_bist_done_13_src(data)                                     ((0x00001000&(data))>>12)
#define VE2_BIST_DONE_get_ve2_bist_done_13(data)                                     ((0x00001000&(data))>>12)
#define VE2_BIST_DONE_ve2_bist_done_12_shift                                         (11)
#define VE2_BIST_DONE_ve2_bist_done_12_mask                                          (0x00000800)
#define VE2_BIST_DONE_ve2_bist_done_12(data)                                         (0x00000800&((data)<<11))
#define VE2_BIST_DONE_ve2_bist_done_12_src(data)                                     ((0x00000800&(data))>>11)
#define VE2_BIST_DONE_get_ve2_bist_done_12(data)                                     ((0x00000800&(data))>>11)
#define VE2_BIST_DONE_ve2_bist_done_11_shift                                         (10)
#define VE2_BIST_DONE_ve2_bist_done_11_mask                                          (0x00000400)
#define VE2_BIST_DONE_ve2_bist_done_11(data)                                         (0x00000400&((data)<<10))
#define VE2_BIST_DONE_ve2_bist_done_11_src(data)                                     ((0x00000400&(data))>>10)
#define VE2_BIST_DONE_get_ve2_bist_done_11(data)                                     ((0x00000400&(data))>>10)
#define VE2_BIST_DONE_ve2_bist_done_10_shift                                         (9)
#define VE2_BIST_DONE_ve2_bist_done_10_mask                                          (0x00000200)
#define VE2_BIST_DONE_ve2_bist_done_10(data)                                         (0x00000200&((data)<<9))
#define VE2_BIST_DONE_ve2_bist_done_10_src(data)                                     ((0x00000200&(data))>>9)
#define VE2_BIST_DONE_get_ve2_bist_done_10(data)                                     ((0x00000200&(data))>>9)
#define VE2_BIST_DONE_ve2_bist_done_9_shift                                          (8)
#define VE2_BIST_DONE_ve2_bist_done_9_mask                                           (0x00000100)
#define VE2_BIST_DONE_ve2_bist_done_9(data)                                          (0x00000100&((data)<<8))
#define VE2_BIST_DONE_ve2_bist_done_9_src(data)                                      ((0x00000100&(data))>>8)
#define VE2_BIST_DONE_get_ve2_bist_done_9(data)                                      ((0x00000100&(data))>>8)
#define VE2_BIST_DONE_ve2_bist_done_8_shift                                          (7)
#define VE2_BIST_DONE_ve2_bist_done_8_mask                                           (0x00000080)
#define VE2_BIST_DONE_ve2_bist_done_8(data)                                          (0x00000080&((data)<<7))
#define VE2_BIST_DONE_ve2_bist_done_8_src(data)                                      ((0x00000080&(data))>>7)
#define VE2_BIST_DONE_get_ve2_bist_done_8(data)                                      ((0x00000080&(data))>>7)
#define VE2_BIST_DONE_ve2_bist_done_7_shift                                          (6)
#define VE2_BIST_DONE_ve2_bist_done_7_mask                                           (0x00000040)
#define VE2_BIST_DONE_ve2_bist_done_7(data)                                          (0x00000040&((data)<<6))
#define VE2_BIST_DONE_ve2_bist_done_7_src(data)                                      ((0x00000040&(data))>>6)
#define VE2_BIST_DONE_get_ve2_bist_done_7(data)                                      ((0x00000040&(data))>>6)
#define VE2_BIST_DONE_ve2_bist_done_6_shift                                          (5)
#define VE2_BIST_DONE_ve2_bist_done_6_mask                                           (0x00000020)
#define VE2_BIST_DONE_ve2_bist_done_6(data)                                          (0x00000020&((data)<<5))
#define VE2_BIST_DONE_ve2_bist_done_6_src(data)                                      ((0x00000020&(data))>>5)
#define VE2_BIST_DONE_get_ve2_bist_done_6(data)                                      ((0x00000020&(data))>>5)
#define VE2_BIST_DONE_ve2_bist_done_5_shift                                          (4)
#define VE2_BIST_DONE_ve2_bist_done_5_mask                                           (0x00000010)
#define VE2_BIST_DONE_ve2_bist_done_5(data)                                          (0x00000010&((data)<<4))
#define VE2_BIST_DONE_ve2_bist_done_5_src(data)                                      ((0x00000010&(data))>>4)
#define VE2_BIST_DONE_get_ve2_bist_done_5(data)                                      ((0x00000010&(data))>>4)
#define VE2_BIST_DONE_ve2_bist_done_4_shift                                          (3)
#define VE2_BIST_DONE_ve2_bist_done_4_mask                                           (0x00000008)
#define VE2_BIST_DONE_ve2_bist_done_4(data)                                          (0x00000008&((data)<<3))
#define VE2_BIST_DONE_ve2_bist_done_4_src(data)                                      ((0x00000008&(data))>>3)
#define VE2_BIST_DONE_get_ve2_bist_done_4(data)                                      ((0x00000008&(data))>>3)
#define VE2_BIST_DONE_ve2_bist_done_3_shift                                          (2)
#define VE2_BIST_DONE_ve2_bist_done_3_mask                                           (0x00000004)
#define VE2_BIST_DONE_ve2_bist_done_3(data)                                          (0x00000004&((data)<<2))
#define VE2_BIST_DONE_ve2_bist_done_3_src(data)                                      ((0x00000004&(data))>>2)
#define VE2_BIST_DONE_get_ve2_bist_done_3(data)                                      ((0x00000004&(data))>>2)
#define VE2_BIST_DONE_ve2_bist_done_2_shift                                          (1)
#define VE2_BIST_DONE_ve2_bist_done_2_mask                                           (0x00000002)
#define VE2_BIST_DONE_ve2_bist_done_2(data)                                          (0x00000002&((data)<<1))
#define VE2_BIST_DONE_ve2_bist_done_2_src(data)                                      ((0x00000002&(data))>>1)
#define VE2_BIST_DONE_get_ve2_bist_done_2(data)                                      ((0x00000002&(data))>>1)
#define VE2_BIST_DONE_ve2_bist_done_1_shift                                          (0)
#define VE2_BIST_DONE_ve2_bist_done_1_mask                                           (0x00000001)
#define VE2_BIST_DONE_ve2_bist_done_1(data)                                          (0x00000001&((data)<<0))
#define VE2_BIST_DONE_ve2_bist_done_1_src(data)                                      ((0x00000001&(data))>>0)
#define VE2_BIST_DONE_get_ve2_bist_done_1(data)                                      ((0x00000001&(data))>>0)


#define VE2_BIST_FAIL_GROUP                                                          0x18036F0C
#define VE2_BIST_FAIL_GROUP_reg_addr                                                 "0xB8036F0C"
#define VE2_BIST_FAIL_GROUP_reg                                                      0xB8036F0C
#define set_VE2_BIST_FAIL_GROUP_reg(data)   (*((volatile unsigned int*) VE2_BIST_FAIL_GROUP_reg)=data)
#define get_VE2_BIST_FAIL_GROUP_reg   (*((volatile unsigned int*) VE2_BIST_FAIL_GROUP_reg))
#define VE2_BIST_FAIL_GROUP_inst_adr                                                 "0x00C3"
#define VE2_BIST_FAIL_GROUP_inst                                                     0x00C3
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_13_shift                             (12)
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_13_mask                              (0x00001000)
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_13(data)                             (0x00001000&((data)<<12))
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_13_src(data)                         ((0x00001000&(data))>>12)
#define VE2_BIST_FAIL_GROUP_get_ve2_bist_fail_group_13(data)                         ((0x00001000&(data))>>12)
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_12_shift                             (11)
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_12_mask                              (0x00000800)
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_12(data)                             (0x00000800&((data)<<11))
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_12_src(data)                         ((0x00000800&(data))>>11)
#define VE2_BIST_FAIL_GROUP_get_ve2_bist_fail_group_12(data)                         ((0x00000800&(data))>>11)
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_11_shift                             (10)
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_11_mask                              (0x00000400)
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_11(data)                             (0x00000400&((data)<<10))
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_11_src(data)                         ((0x00000400&(data))>>10)
#define VE2_BIST_FAIL_GROUP_get_ve2_bist_fail_group_11(data)                         ((0x00000400&(data))>>10)
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_10_shift                             (9)
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_10_mask                              (0x00000200)
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_10(data)                             (0x00000200&((data)<<9))
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_10_src(data)                         ((0x00000200&(data))>>9)
#define VE2_BIST_FAIL_GROUP_get_ve2_bist_fail_group_10(data)                         ((0x00000200&(data))>>9)
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_9_shift                              (8)
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_9_mask                               (0x00000100)
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_9(data)                              (0x00000100&((data)<<8))
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_9_src(data)                          ((0x00000100&(data))>>8)
#define VE2_BIST_FAIL_GROUP_get_ve2_bist_fail_group_9(data)                          ((0x00000100&(data))>>8)
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_8_shift                              (7)
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_8_mask                               (0x00000080)
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_8(data)                              (0x00000080&((data)<<7))
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_8_src(data)                          ((0x00000080&(data))>>7)
#define VE2_BIST_FAIL_GROUP_get_ve2_bist_fail_group_8(data)                          ((0x00000080&(data))>>7)
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_7_shift                              (6)
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_7_mask                               (0x00000040)
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_7(data)                              (0x00000040&((data)<<6))
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_7_src(data)                          ((0x00000040&(data))>>6)
#define VE2_BIST_FAIL_GROUP_get_ve2_bist_fail_group_7(data)                          ((0x00000040&(data))>>6)
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_6_shift                              (5)
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_6_mask                               (0x00000020)
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_6(data)                              (0x00000020&((data)<<5))
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_6_src(data)                          ((0x00000020&(data))>>5)
#define VE2_BIST_FAIL_GROUP_get_ve2_bist_fail_group_6(data)                          ((0x00000020&(data))>>5)
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_5_shift                              (4)
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_5_mask                               (0x00000010)
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_5(data)                              (0x00000010&((data)<<4))
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_5_src(data)                          ((0x00000010&(data))>>4)
#define VE2_BIST_FAIL_GROUP_get_ve2_bist_fail_group_5(data)                          ((0x00000010&(data))>>4)
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_4_shift                              (3)
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_4_mask                               (0x00000008)
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_4(data)                              (0x00000008&((data)<<3))
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_4_src(data)                          ((0x00000008&(data))>>3)
#define VE2_BIST_FAIL_GROUP_get_ve2_bist_fail_group_4(data)                          ((0x00000008&(data))>>3)
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_3_shift                              (2)
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_3_mask                               (0x00000004)
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_3(data)                              (0x00000004&((data)<<2))
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_3_src(data)                          ((0x00000004&(data))>>2)
#define VE2_BIST_FAIL_GROUP_get_ve2_bist_fail_group_3(data)                          ((0x00000004&(data))>>2)
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_2_shift                              (1)
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_2_mask                               (0x00000002)
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_2(data)                              (0x00000002&((data)<<1))
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_2_src(data)                          ((0x00000002&(data))>>1)
#define VE2_BIST_FAIL_GROUP_get_ve2_bist_fail_group_2(data)                          ((0x00000002&(data))>>1)
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_1_shift                              (0)
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_1_mask                               (0x00000001)
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_1(data)                              (0x00000001&((data)<<0))
#define VE2_BIST_FAIL_GROUP_ve2_bist_fail_group_1_src(data)                          ((0x00000001&(data))>>0)
#define VE2_BIST_FAIL_GROUP_get_ve2_bist_fail_group_1(data)                          ((0x00000001&(data))>>0)


#define VE2_DRF_MODE                                                                 0x18036F10
#define VE2_DRF_MODE_reg_addr                                                        "0xB8036F10"
#define VE2_DRF_MODE_reg                                                             0xB8036F10
#define set_VE2_DRF_MODE_reg(data)   (*((volatile unsigned int*) VE2_DRF_MODE_reg)=data)
#define get_VE2_DRF_MODE_reg   (*((volatile unsigned int*) VE2_DRF_MODE_reg))
#define VE2_DRF_MODE_inst_adr                                                        "0x00C4"
#define VE2_DRF_MODE_inst                                                            0x00C4
#define VE2_DRF_MODE_ve2_drf_mode_13_shift                                           (12)
#define VE2_DRF_MODE_ve2_drf_mode_13_mask                                            (0x00001000)
#define VE2_DRF_MODE_ve2_drf_mode_13(data)                                           (0x00001000&((data)<<12))
#define VE2_DRF_MODE_ve2_drf_mode_13_src(data)                                       ((0x00001000&(data))>>12)
#define VE2_DRF_MODE_get_ve2_drf_mode_13(data)                                       ((0x00001000&(data))>>12)
#define VE2_DRF_MODE_ve2_drf_mode_12_shift                                           (11)
#define VE2_DRF_MODE_ve2_drf_mode_12_mask                                            (0x00000800)
#define VE2_DRF_MODE_ve2_drf_mode_12(data)                                           (0x00000800&((data)<<11))
#define VE2_DRF_MODE_ve2_drf_mode_12_src(data)                                       ((0x00000800&(data))>>11)
#define VE2_DRF_MODE_get_ve2_drf_mode_12(data)                                       ((0x00000800&(data))>>11)
#define VE2_DRF_MODE_ve2_drf_mode_11_shift                                           (10)
#define VE2_DRF_MODE_ve2_drf_mode_11_mask                                            (0x00000400)
#define VE2_DRF_MODE_ve2_drf_mode_11(data)                                           (0x00000400&((data)<<10))
#define VE2_DRF_MODE_ve2_drf_mode_11_src(data)                                       ((0x00000400&(data))>>10)
#define VE2_DRF_MODE_get_ve2_drf_mode_11(data)                                       ((0x00000400&(data))>>10)
#define VE2_DRF_MODE_ve2_drf_mode_10_shift                                           (9)
#define VE2_DRF_MODE_ve2_drf_mode_10_mask                                            (0x00000200)
#define VE2_DRF_MODE_ve2_drf_mode_10(data)                                           (0x00000200&((data)<<9))
#define VE2_DRF_MODE_ve2_drf_mode_10_src(data)                                       ((0x00000200&(data))>>9)
#define VE2_DRF_MODE_get_ve2_drf_mode_10(data)                                       ((0x00000200&(data))>>9)
#define VE2_DRF_MODE_ve2_drf_mode_9_shift                                            (8)
#define VE2_DRF_MODE_ve2_drf_mode_9_mask                                             (0x00000100)
#define VE2_DRF_MODE_ve2_drf_mode_9(data)                                            (0x00000100&((data)<<8))
#define VE2_DRF_MODE_ve2_drf_mode_9_src(data)                                        ((0x00000100&(data))>>8)
#define VE2_DRF_MODE_get_ve2_drf_mode_9(data)                                        ((0x00000100&(data))>>8)
#define VE2_DRF_MODE_ve2_drf_mode_8_shift                                            (7)
#define VE2_DRF_MODE_ve2_drf_mode_8_mask                                             (0x00000080)
#define VE2_DRF_MODE_ve2_drf_mode_8(data)                                            (0x00000080&((data)<<7))
#define VE2_DRF_MODE_ve2_drf_mode_8_src(data)                                        ((0x00000080&(data))>>7)
#define VE2_DRF_MODE_get_ve2_drf_mode_8(data)                                        ((0x00000080&(data))>>7)
#define VE2_DRF_MODE_ve2_drf_mode_7_shift                                            (6)
#define VE2_DRF_MODE_ve2_drf_mode_7_mask                                             (0x00000040)
#define VE2_DRF_MODE_ve2_drf_mode_7(data)                                            (0x00000040&((data)<<6))
#define VE2_DRF_MODE_ve2_drf_mode_7_src(data)                                        ((0x00000040&(data))>>6)
#define VE2_DRF_MODE_get_ve2_drf_mode_7(data)                                        ((0x00000040&(data))>>6)
#define VE2_DRF_MODE_ve2_drf_mode_6_shift                                            (5)
#define VE2_DRF_MODE_ve2_drf_mode_6_mask                                             (0x00000020)
#define VE2_DRF_MODE_ve2_drf_mode_6(data)                                            (0x00000020&((data)<<5))
#define VE2_DRF_MODE_ve2_drf_mode_6_src(data)                                        ((0x00000020&(data))>>5)
#define VE2_DRF_MODE_get_ve2_drf_mode_6(data)                                        ((0x00000020&(data))>>5)
#define VE2_DRF_MODE_ve2_drf_mode_5_shift                                            (4)
#define VE2_DRF_MODE_ve2_drf_mode_5_mask                                             (0x00000010)
#define VE2_DRF_MODE_ve2_drf_mode_5(data)                                            (0x00000010&((data)<<4))
#define VE2_DRF_MODE_ve2_drf_mode_5_src(data)                                        ((0x00000010&(data))>>4)
#define VE2_DRF_MODE_get_ve2_drf_mode_5(data)                                        ((0x00000010&(data))>>4)
#define VE2_DRF_MODE_ve2_drf_mode_4_shift                                            (3)
#define VE2_DRF_MODE_ve2_drf_mode_4_mask                                             (0x00000008)
#define VE2_DRF_MODE_ve2_drf_mode_4(data)                                            (0x00000008&((data)<<3))
#define VE2_DRF_MODE_ve2_drf_mode_4_src(data)                                        ((0x00000008&(data))>>3)
#define VE2_DRF_MODE_get_ve2_drf_mode_4(data)                                        ((0x00000008&(data))>>3)
#define VE2_DRF_MODE_ve2_drf_mode_3_shift                                            (2)
#define VE2_DRF_MODE_ve2_drf_mode_3_mask                                             (0x00000004)
#define VE2_DRF_MODE_ve2_drf_mode_3(data)                                            (0x00000004&((data)<<2))
#define VE2_DRF_MODE_ve2_drf_mode_3_src(data)                                        ((0x00000004&(data))>>2)
#define VE2_DRF_MODE_get_ve2_drf_mode_3(data)                                        ((0x00000004&(data))>>2)
#define VE2_DRF_MODE_ve2_drf_mode_2_shift                                            (1)
#define VE2_DRF_MODE_ve2_drf_mode_2_mask                                             (0x00000002)
#define VE2_DRF_MODE_ve2_drf_mode_2(data)                                            (0x00000002&((data)<<1))
#define VE2_DRF_MODE_ve2_drf_mode_2_src(data)                                        ((0x00000002&(data))>>1)
#define VE2_DRF_MODE_get_ve2_drf_mode_2(data)                                        ((0x00000002&(data))>>1)
#define VE2_DRF_MODE_ve2_drf_mode_1_shift                                            (0)
#define VE2_DRF_MODE_ve2_drf_mode_1_mask                                             (0x00000001)
#define VE2_DRF_MODE_ve2_drf_mode_1(data)                                            (0x00000001&((data)<<0))
#define VE2_DRF_MODE_ve2_drf_mode_1_src(data)                                        ((0x00000001&(data))>>0)
#define VE2_DRF_MODE_get_ve2_drf_mode_1(data)                                        ((0x00000001&(data))>>0)


#define VE2_DRF_RESUME                                                               0x18036F14
#define VE2_DRF_RESUME_reg_addr                                                      "0xB8036F14"
#define VE2_DRF_RESUME_reg                                                           0xB8036F14
#define set_VE2_DRF_RESUME_reg(data)   (*((volatile unsigned int*) VE2_DRF_RESUME_reg)=data)
#define get_VE2_DRF_RESUME_reg   (*((volatile unsigned int*) VE2_DRF_RESUME_reg))
#define VE2_DRF_RESUME_inst_adr                                                      "0x00C5"
#define VE2_DRF_RESUME_inst                                                          0x00C5
#define VE2_DRF_RESUME_ve2_drf_resume_13_shift                                       (12)
#define VE2_DRF_RESUME_ve2_drf_resume_13_mask                                        (0x00001000)
#define VE2_DRF_RESUME_ve2_drf_resume_13(data)                                       (0x00001000&((data)<<12))
#define VE2_DRF_RESUME_ve2_drf_resume_13_src(data)                                   ((0x00001000&(data))>>12)
#define VE2_DRF_RESUME_get_ve2_drf_resume_13(data)                                   ((0x00001000&(data))>>12)
#define VE2_DRF_RESUME_ve2_drf_resume_12_shift                                       (11)
#define VE2_DRF_RESUME_ve2_drf_resume_12_mask                                        (0x00000800)
#define VE2_DRF_RESUME_ve2_drf_resume_12(data)                                       (0x00000800&((data)<<11))
#define VE2_DRF_RESUME_ve2_drf_resume_12_src(data)                                   ((0x00000800&(data))>>11)
#define VE2_DRF_RESUME_get_ve2_drf_resume_12(data)                                   ((0x00000800&(data))>>11)
#define VE2_DRF_RESUME_ve2_drf_resume_11_shift                                       (10)
#define VE2_DRF_RESUME_ve2_drf_resume_11_mask                                        (0x00000400)
#define VE2_DRF_RESUME_ve2_drf_resume_11(data)                                       (0x00000400&((data)<<10))
#define VE2_DRF_RESUME_ve2_drf_resume_11_src(data)                                   ((0x00000400&(data))>>10)
#define VE2_DRF_RESUME_get_ve2_drf_resume_11(data)                                   ((0x00000400&(data))>>10)
#define VE2_DRF_RESUME_ve2_drf_resume_10_shift                                       (9)
#define VE2_DRF_RESUME_ve2_drf_resume_10_mask                                        (0x00000200)
#define VE2_DRF_RESUME_ve2_drf_resume_10(data)                                       (0x00000200&((data)<<9))
#define VE2_DRF_RESUME_ve2_drf_resume_10_src(data)                                   ((0x00000200&(data))>>9)
#define VE2_DRF_RESUME_get_ve2_drf_resume_10(data)                                   ((0x00000200&(data))>>9)
#define VE2_DRF_RESUME_ve2_drf_resume_9_shift                                        (8)
#define VE2_DRF_RESUME_ve2_drf_resume_9_mask                                         (0x00000100)
#define VE2_DRF_RESUME_ve2_drf_resume_9(data)                                        (0x00000100&((data)<<8))
#define VE2_DRF_RESUME_ve2_drf_resume_9_src(data)                                    ((0x00000100&(data))>>8)
#define VE2_DRF_RESUME_get_ve2_drf_resume_9(data)                                    ((0x00000100&(data))>>8)
#define VE2_DRF_RESUME_ve2_drf_resume_8_shift                                        (7)
#define VE2_DRF_RESUME_ve2_drf_resume_8_mask                                         (0x00000080)
#define VE2_DRF_RESUME_ve2_drf_resume_8(data)                                        (0x00000080&((data)<<7))
#define VE2_DRF_RESUME_ve2_drf_resume_8_src(data)                                    ((0x00000080&(data))>>7)
#define VE2_DRF_RESUME_get_ve2_drf_resume_8(data)                                    ((0x00000080&(data))>>7)
#define VE2_DRF_RESUME_ve2_drf_resume_7_shift                                        (6)
#define VE2_DRF_RESUME_ve2_drf_resume_7_mask                                         (0x00000040)
#define VE2_DRF_RESUME_ve2_drf_resume_7(data)                                        (0x00000040&((data)<<6))
#define VE2_DRF_RESUME_ve2_drf_resume_7_src(data)                                    ((0x00000040&(data))>>6)
#define VE2_DRF_RESUME_get_ve2_drf_resume_7(data)                                    ((0x00000040&(data))>>6)
#define VE2_DRF_RESUME_ve2_drf_resume_6_shift                                        (5)
#define VE2_DRF_RESUME_ve2_drf_resume_6_mask                                         (0x00000020)
#define VE2_DRF_RESUME_ve2_drf_resume_6(data)                                        (0x00000020&((data)<<5))
#define VE2_DRF_RESUME_ve2_drf_resume_6_src(data)                                    ((0x00000020&(data))>>5)
#define VE2_DRF_RESUME_get_ve2_drf_resume_6(data)                                    ((0x00000020&(data))>>5)
#define VE2_DRF_RESUME_ve2_drf_resume_5_shift                                        (4)
#define VE2_DRF_RESUME_ve2_drf_resume_5_mask                                         (0x00000010)
#define VE2_DRF_RESUME_ve2_drf_resume_5(data)                                        (0x00000010&((data)<<4))
#define VE2_DRF_RESUME_ve2_drf_resume_5_src(data)                                    ((0x00000010&(data))>>4)
#define VE2_DRF_RESUME_get_ve2_drf_resume_5(data)                                    ((0x00000010&(data))>>4)
#define VE2_DRF_RESUME_ve2_drf_resume_4_shift                                        (3)
#define VE2_DRF_RESUME_ve2_drf_resume_4_mask                                         (0x00000008)
#define VE2_DRF_RESUME_ve2_drf_resume_4(data)                                        (0x00000008&((data)<<3))
#define VE2_DRF_RESUME_ve2_drf_resume_4_src(data)                                    ((0x00000008&(data))>>3)
#define VE2_DRF_RESUME_get_ve2_drf_resume_4(data)                                    ((0x00000008&(data))>>3)
#define VE2_DRF_RESUME_ve2_drf_resume_3_shift                                        (2)
#define VE2_DRF_RESUME_ve2_drf_resume_3_mask                                         (0x00000004)
#define VE2_DRF_RESUME_ve2_drf_resume_3(data)                                        (0x00000004&((data)<<2))
#define VE2_DRF_RESUME_ve2_drf_resume_3_src(data)                                    ((0x00000004&(data))>>2)
#define VE2_DRF_RESUME_get_ve2_drf_resume_3(data)                                    ((0x00000004&(data))>>2)
#define VE2_DRF_RESUME_ve2_drf_resume_2_shift                                        (1)
#define VE2_DRF_RESUME_ve2_drf_resume_2_mask                                         (0x00000002)
#define VE2_DRF_RESUME_ve2_drf_resume_2(data)                                        (0x00000002&((data)<<1))
#define VE2_DRF_RESUME_ve2_drf_resume_2_src(data)                                    ((0x00000002&(data))>>1)
#define VE2_DRF_RESUME_get_ve2_drf_resume_2(data)                                    ((0x00000002&(data))>>1)
#define VE2_DRF_RESUME_ve2_drf_resume_1_shift                                        (0)
#define VE2_DRF_RESUME_ve2_drf_resume_1_mask                                         (0x00000001)
#define VE2_DRF_RESUME_ve2_drf_resume_1(data)                                        (0x00000001&((data)<<0))
#define VE2_DRF_RESUME_ve2_drf_resume_1_src(data)                                    ((0x00000001&(data))>>0)
#define VE2_DRF_RESUME_get_ve2_drf_resume_1(data)                                    ((0x00000001&(data))>>0)


#define VE2_DRF_PAUSE                                                                0x18036F18
#define VE2_DRF_PAUSE_reg_addr                                                       "0xB8036F18"
#define VE2_DRF_PAUSE_reg                                                            0xB8036F18
#define set_VE2_DRF_PAUSE_reg(data)   (*((volatile unsigned int*) VE2_DRF_PAUSE_reg)=data)
#define get_VE2_DRF_PAUSE_reg   (*((volatile unsigned int*) VE2_DRF_PAUSE_reg))
#define VE2_DRF_PAUSE_inst_adr                                                       "0x00C6"
#define VE2_DRF_PAUSE_inst                                                           0x00C6
#define VE2_DRF_PAUSE_ve2_drf_pause_13_shift                                         (12)
#define VE2_DRF_PAUSE_ve2_drf_pause_13_mask                                          (0x00001000)
#define VE2_DRF_PAUSE_ve2_drf_pause_13(data)                                         (0x00001000&((data)<<12))
#define VE2_DRF_PAUSE_ve2_drf_pause_13_src(data)                                     ((0x00001000&(data))>>12)
#define VE2_DRF_PAUSE_get_ve2_drf_pause_13(data)                                     ((0x00001000&(data))>>12)
#define VE2_DRF_PAUSE_ve2_drf_pause_12_shift                                         (11)
#define VE2_DRF_PAUSE_ve2_drf_pause_12_mask                                          (0x00000800)
#define VE2_DRF_PAUSE_ve2_drf_pause_12(data)                                         (0x00000800&((data)<<11))
#define VE2_DRF_PAUSE_ve2_drf_pause_12_src(data)                                     ((0x00000800&(data))>>11)
#define VE2_DRF_PAUSE_get_ve2_drf_pause_12(data)                                     ((0x00000800&(data))>>11)
#define VE2_DRF_PAUSE_ve2_drf_pause_11_shift                                         (10)
#define VE2_DRF_PAUSE_ve2_drf_pause_11_mask                                          (0x00000400)
#define VE2_DRF_PAUSE_ve2_drf_pause_11(data)                                         (0x00000400&((data)<<10))
#define VE2_DRF_PAUSE_ve2_drf_pause_11_src(data)                                     ((0x00000400&(data))>>10)
#define VE2_DRF_PAUSE_get_ve2_drf_pause_11(data)                                     ((0x00000400&(data))>>10)
#define VE2_DRF_PAUSE_ve2_drf_pause_10_shift                                         (9)
#define VE2_DRF_PAUSE_ve2_drf_pause_10_mask                                          (0x00000200)
#define VE2_DRF_PAUSE_ve2_drf_pause_10(data)                                         (0x00000200&((data)<<9))
#define VE2_DRF_PAUSE_ve2_drf_pause_10_src(data)                                     ((0x00000200&(data))>>9)
#define VE2_DRF_PAUSE_get_ve2_drf_pause_10(data)                                     ((0x00000200&(data))>>9)
#define VE2_DRF_PAUSE_ve2_drf_pause_9_shift                                          (8)
#define VE2_DRF_PAUSE_ve2_drf_pause_9_mask                                           (0x00000100)
#define VE2_DRF_PAUSE_ve2_drf_pause_9(data)                                          (0x00000100&((data)<<8))
#define VE2_DRF_PAUSE_ve2_drf_pause_9_src(data)                                      ((0x00000100&(data))>>8)
#define VE2_DRF_PAUSE_get_ve2_drf_pause_9(data)                                      ((0x00000100&(data))>>8)
#define VE2_DRF_PAUSE_ve2_drf_pause_8_shift                                          (7)
#define VE2_DRF_PAUSE_ve2_drf_pause_8_mask                                           (0x00000080)
#define VE2_DRF_PAUSE_ve2_drf_pause_8(data)                                          (0x00000080&((data)<<7))
#define VE2_DRF_PAUSE_ve2_drf_pause_8_src(data)                                      ((0x00000080&(data))>>7)
#define VE2_DRF_PAUSE_get_ve2_drf_pause_8(data)                                      ((0x00000080&(data))>>7)
#define VE2_DRF_PAUSE_ve2_drf_pause_7_shift                                          (6)
#define VE2_DRF_PAUSE_ve2_drf_pause_7_mask                                           (0x00000040)
#define VE2_DRF_PAUSE_ve2_drf_pause_7(data)                                          (0x00000040&((data)<<6))
#define VE2_DRF_PAUSE_ve2_drf_pause_7_src(data)                                      ((0x00000040&(data))>>6)
#define VE2_DRF_PAUSE_get_ve2_drf_pause_7(data)                                      ((0x00000040&(data))>>6)
#define VE2_DRF_PAUSE_ve2_drf_pause_6_shift                                          (5)
#define VE2_DRF_PAUSE_ve2_drf_pause_6_mask                                           (0x00000020)
#define VE2_DRF_PAUSE_ve2_drf_pause_6(data)                                          (0x00000020&((data)<<5))
#define VE2_DRF_PAUSE_ve2_drf_pause_6_src(data)                                      ((0x00000020&(data))>>5)
#define VE2_DRF_PAUSE_get_ve2_drf_pause_6(data)                                      ((0x00000020&(data))>>5)
#define VE2_DRF_PAUSE_ve2_drf_pause_5_shift                                          (4)
#define VE2_DRF_PAUSE_ve2_drf_pause_5_mask                                           (0x00000010)
#define VE2_DRF_PAUSE_ve2_drf_pause_5(data)                                          (0x00000010&((data)<<4))
#define VE2_DRF_PAUSE_ve2_drf_pause_5_src(data)                                      ((0x00000010&(data))>>4)
#define VE2_DRF_PAUSE_get_ve2_drf_pause_5(data)                                      ((0x00000010&(data))>>4)
#define VE2_DRF_PAUSE_ve2_drf_pause_4_shift                                          (3)
#define VE2_DRF_PAUSE_ve2_drf_pause_4_mask                                           (0x00000008)
#define VE2_DRF_PAUSE_ve2_drf_pause_4(data)                                          (0x00000008&((data)<<3))
#define VE2_DRF_PAUSE_ve2_drf_pause_4_src(data)                                      ((0x00000008&(data))>>3)
#define VE2_DRF_PAUSE_get_ve2_drf_pause_4(data)                                      ((0x00000008&(data))>>3)
#define VE2_DRF_PAUSE_ve2_drf_pause_3_shift                                          (2)
#define VE2_DRF_PAUSE_ve2_drf_pause_3_mask                                           (0x00000004)
#define VE2_DRF_PAUSE_ve2_drf_pause_3(data)                                          (0x00000004&((data)<<2))
#define VE2_DRF_PAUSE_ve2_drf_pause_3_src(data)                                      ((0x00000004&(data))>>2)
#define VE2_DRF_PAUSE_get_ve2_drf_pause_3(data)                                      ((0x00000004&(data))>>2)
#define VE2_DRF_PAUSE_ve2_drf_pause_2_shift                                          (1)
#define VE2_DRF_PAUSE_ve2_drf_pause_2_mask                                           (0x00000002)
#define VE2_DRF_PAUSE_ve2_drf_pause_2(data)                                          (0x00000002&((data)<<1))
#define VE2_DRF_PAUSE_ve2_drf_pause_2_src(data)                                      ((0x00000002&(data))>>1)
#define VE2_DRF_PAUSE_get_ve2_drf_pause_2(data)                                      ((0x00000002&(data))>>1)
#define VE2_DRF_PAUSE_ve2_drf_pause_1_shift                                          (0)
#define VE2_DRF_PAUSE_ve2_drf_pause_1_mask                                           (0x00000001)
#define VE2_DRF_PAUSE_ve2_drf_pause_1(data)                                          (0x00000001&((data)<<0))
#define VE2_DRF_PAUSE_ve2_drf_pause_1_src(data)                                      ((0x00000001&(data))>>0)
#define VE2_DRF_PAUSE_get_ve2_drf_pause_1(data)                                      ((0x00000001&(data))>>0)


#define VE2_DRF_DONE                                                                 0x18036F1C
#define VE2_DRF_DONE_reg_addr                                                        "0xB8036F1C"
#define VE2_DRF_DONE_reg                                                             0xB8036F1C
#define set_VE2_DRF_DONE_reg(data)   (*((volatile unsigned int*) VE2_DRF_DONE_reg)=data)
#define get_VE2_DRF_DONE_reg   (*((volatile unsigned int*) VE2_DRF_DONE_reg))
#define VE2_DRF_DONE_inst_adr                                                        "0x00C7"
#define VE2_DRF_DONE_inst                                                            0x00C7
#define VE2_DRF_DONE_ve2_drf_done_13_shift                                           (12)
#define VE2_DRF_DONE_ve2_drf_done_13_mask                                            (0x00001000)
#define VE2_DRF_DONE_ve2_drf_done_13(data)                                           (0x00001000&((data)<<12))
#define VE2_DRF_DONE_ve2_drf_done_13_src(data)                                       ((0x00001000&(data))>>12)
#define VE2_DRF_DONE_get_ve2_drf_done_13(data)                                       ((0x00001000&(data))>>12)
#define VE2_DRF_DONE_ve2_drf_done_12_shift                                           (11)
#define VE2_DRF_DONE_ve2_drf_done_12_mask                                            (0x00000800)
#define VE2_DRF_DONE_ve2_drf_done_12(data)                                           (0x00000800&((data)<<11))
#define VE2_DRF_DONE_ve2_drf_done_12_src(data)                                       ((0x00000800&(data))>>11)
#define VE2_DRF_DONE_get_ve2_drf_done_12(data)                                       ((0x00000800&(data))>>11)
#define VE2_DRF_DONE_ve2_drf_done_11_shift                                           (10)
#define VE2_DRF_DONE_ve2_drf_done_11_mask                                            (0x00000400)
#define VE2_DRF_DONE_ve2_drf_done_11(data)                                           (0x00000400&((data)<<10))
#define VE2_DRF_DONE_ve2_drf_done_11_src(data)                                       ((0x00000400&(data))>>10)
#define VE2_DRF_DONE_get_ve2_drf_done_11(data)                                       ((0x00000400&(data))>>10)
#define VE2_DRF_DONE_ve2_drf_done_10_shift                                           (9)
#define VE2_DRF_DONE_ve2_drf_done_10_mask                                            (0x00000200)
#define VE2_DRF_DONE_ve2_drf_done_10(data)                                           (0x00000200&((data)<<9))
#define VE2_DRF_DONE_ve2_drf_done_10_src(data)                                       ((0x00000200&(data))>>9)
#define VE2_DRF_DONE_get_ve2_drf_done_10(data)                                       ((0x00000200&(data))>>9)
#define VE2_DRF_DONE_ve2_drf_done_9_shift                                            (8)
#define VE2_DRF_DONE_ve2_drf_done_9_mask                                             (0x00000100)
#define VE2_DRF_DONE_ve2_drf_done_9(data)                                            (0x00000100&((data)<<8))
#define VE2_DRF_DONE_ve2_drf_done_9_src(data)                                        ((0x00000100&(data))>>8)
#define VE2_DRF_DONE_get_ve2_drf_done_9(data)                                        ((0x00000100&(data))>>8)
#define VE2_DRF_DONE_ve2_drf_done_8_shift                                            (7)
#define VE2_DRF_DONE_ve2_drf_done_8_mask                                             (0x00000080)
#define VE2_DRF_DONE_ve2_drf_done_8(data)                                            (0x00000080&((data)<<7))
#define VE2_DRF_DONE_ve2_drf_done_8_src(data)                                        ((0x00000080&(data))>>7)
#define VE2_DRF_DONE_get_ve2_drf_done_8(data)                                        ((0x00000080&(data))>>7)
#define VE2_DRF_DONE_ve2_drf_done_7_shift                                            (6)
#define VE2_DRF_DONE_ve2_drf_done_7_mask                                             (0x00000040)
#define VE2_DRF_DONE_ve2_drf_done_7(data)                                            (0x00000040&((data)<<6))
#define VE2_DRF_DONE_ve2_drf_done_7_src(data)                                        ((0x00000040&(data))>>6)
#define VE2_DRF_DONE_get_ve2_drf_done_7(data)                                        ((0x00000040&(data))>>6)
#define VE2_DRF_DONE_ve2_drf_done_6_shift                                            (5)
#define VE2_DRF_DONE_ve2_drf_done_6_mask                                             (0x00000020)
#define VE2_DRF_DONE_ve2_drf_done_6(data)                                            (0x00000020&((data)<<5))
#define VE2_DRF_DONE_ve2_drf_done_6_src(data)                                        ((0x00000020&(data))>>5)
#define VE2_DRF_DONE_get_ve2_drf_done_6(data)                                        ((0x00000020&(data))>>5)
#define VE2_DRF_DONE_ve2_drf_done_5_shift                                            (4)
#define VE2_DRF_DONE_ve2_drf_done_5_mask                                             (0x00000010)
#define VE2_DRF_DONE_ve2_drf_done_5(data)                                            (0x00000010&((data)<<4))
#define VE2_DRF_DONE_ve2_drf_done_5_src(data)                                        ((0x00000010&(data))>>4)
#define VE2_DRF_DONE_get_ve2_drf_done_5(data)                                        ((0x00000010&(data))>>4)
#define VE2_DRF_DONE_ve2_drf_done_4_shift                                            (3)
#define VE2_DRF_DONE_ve2_drf_done_4_mask                                             (0x00000008)
#define VE2_DRF_DONE_ve2_drf_done_4(data)                                            (0x00000008&((data)<<3))
#define VE2_DRF_DONE_ve2_drf_done_4_src(data)                                        ((0x00000008&(data))>>3)
#define VE2_DRF_DONE_get_ve2_drf_done_4(data)                                        ((0x00000008&(data))>>3)
#define VE2_DRF_DONE_ve2_drf_done_3_shift                                            (2)
#define VE2_DRF_DONE_ve2_drf_done_3_mask                                             (0x00000004)
#define VE2_DRF_DONE_ve2_drf_done_3(data)                                            (0x00000004&((data)<<2))
#define VE2_DRF_DONE_ve2_drf_done_3_src(data)                                        ((0x00000004&(data))>>2)
#define VE2_DRF_DONE_get_ve2_drf_done_3(data)                                        ((0x00000004&(data))>>2)
#define VE2_DRF_DONE_ve2_drf_done_2_shift                                            (1)
#define VE2_DRF_DONE_ve2_drf_done_2_mask                                             (0x00000002)
#define VE2_DRF_DONE_ve2_drf_done_2(data)                                            (0x00000002&((data)<<1))
#define VE2_DRF_DONE_ve2_drf_done_2_src(data)                                        ((0x00000002&(data))>>1)
#define VE2_DRF_DONE_get_ve2_drf_done_2(data)                                        ((0x00000002&(data))>>1)
#define VE2_DRF_DONE_ve2_drf_done_1_shift                                            (0)
#define VE2_DRF_DONE_ve2_drf_done_1_mask                                             (0x00000001)
#define VE2_DRF_DONE_ve2_drf_done_1(data)                                            (0x00000001&((data)<<0))
#define VE2_DRF_DONE_ve2_drf_done_1_src(data)                                        ((0x00000001&(data))>>0)
#define VE2_DRF_DONE_get_ve2_drf_done_1(data)                                        ((0x00000001&(data))>>0)


#define VE2_DRF_FAIL_GROUP                                                           0x18036F20
#define VE2_DRF_FAIL_GROUP_reg_addr                                                  "0xB8036F20"
#define VE2_DRF_FAIL_GROUP_reg                                                       0xB8036F20
#define set_VE2_DRF_FAIL_GROUP_reg(data)   (*((volatile unsigned int*) VE2_DRF_FAIL_GROUP_reg)=data)
#define get_VE2_DRF_FAIL_GROUP_reg   (*((volatile unsigned int*) VE2_DRF_FAIL_GROUP_reg))
#define VE2_DRF_FAIL_GROUP_inst_adr                                                  "0x00C8"
#define VE2_DRF_FAIL_GROUP_inst                                                      0x00C8
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_13_shift                               (12)
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_13_mask                                (0x00001000)
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_13(data)                               (0x00001000&((data)<<12))
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_13_src(data)                           ((0x00001000&(data))>>12)
#define VE2_DRF_FAIL_GROUP_get_ve2_drf_fail_group_13(data)                           ((0x00001000&(data))>>12)
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_12_shift                               (11)
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_12_mask                                (0x00000800)
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_12(data)                               (0x00000800&((data)<<11))
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_12_src(data)                           ((0x00000800&(data))>>11)
#define VE2_DRF_FAIL_GROUP_get_ve2_drf_fail_group_12(data)                           ((0x00000800&(data))>>11)
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_11_shift                               (10)
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_11_mask                                (0x00000400)
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_11(data)                               (0x00000400&((data)<<10))
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_11_src(data)                           ((0x00000400&(data))>>10)
#define VE2_DRF_FAIL_GROUP_get_ve2_drf_fail_group_11(data)                           ((0x00000400&(data))>>10)
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_10_shift                               (9)
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_10_mask                                (0x00000200)
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_10(data)                               (0x00000200&((data)<<9))
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_10_src(data)                           ((0x00000200&(data))>>9)
#define VE2_DRF_FAIL_GROUP_get_ve2_drf_fail_group_10(data)                           ((0x00000200&(data))>>9)
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_9_shift                                (8)
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_9_mask                                 (0x00000100)
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_9(data)                                (0x00000100&((data)<<8))
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_9_src(data)                            ((0x00000100&(data))>>8)
#define VE2_DRF_FAIL_GROUP_get_ve2_drf_fail_group_9(data)                            ((0x00000100&(data))>>8)
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_8_shift                                (7)
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_8_mask                                 (0x00000080)
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_8(data)                                (0x00000080&((data)<<7))
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_8_src(data)                            ((0x00000080&(data))>>7)
#define VE2_DRF_FAIL_GROUP_get_ve2_drf_fail_group_8(data)                            ((0x00000080&(data))>>7)
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_7_shift                                (6)
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_7_mask                                 (0x00000040)
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_7(data)                                (0x00000040&((data)<<6))
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_7_src(data)                            ((0x00000040&(data))>>6)
#define VE2_DRF_FAIL_GROUP_get_ve2_drf_fail_group_7(data)                            ((0x00000040&(data))>>6)
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_6_shift                                (5)
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_6_mask                                 (0x00000020)
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_6(data)                                (0x00000020&((data)<<5))
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_6_src(data)                            ((0x00000020&(data))>>5)
#define VE2_DRF_FAIL_GROUP_get_ve2_drf_fail_group_6(data)                            ((0x00000020&(data))>>5)
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_5_shift                                (4)
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_5_mask                                 (0x00000010)
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_5(data)                                (0x00000010&((data)<<4))
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_5_src(data)                            ((0x00000010&(data))>>4)
#define VE2_DRF_FAIL_GROUP_get_ve2_drf_fail_group_5(data)                            ((0x00000010&(data))>>4)
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_4_shift                                (3)
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_4_mask                                 (0x00000008)
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_4(data)                                (0x00000008&((data)<<3))
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_4_src(data)                            ((0x00000008&(data))>>3)
#define VE2_DRF_FAIL_GROUP_get_ve2_drf_fail_group_4(data)                            ((0x00000008&(data))>>3)
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_3_shift                                (2)
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_3_mask                                 (0x00000004)
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_3(data)                                (0x00000004&((data)<<2))
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_3_src(data)                            ((0x00000004&(data))>>2)
#define VE2_DRF_FAIL_GROUP_get_ve2_drf_fail_group_3(data)                            ((0x00000004&(data))>>2)
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_2_shift                                (1)
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_2_mask                                 (0x00000002)
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_2(data)                                (0x00000002&((data)<<1))
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_2_src(data)                            ((0x00000002&(data))>>1)
#define VE2_DRF_FAIL_GROUP_get_ve2_drf_fail_group_2(data)                            ((0x00000002&(data))>>1)
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_1_shift                                (0)
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_1_mask                                 (0x00000001)
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_1(data)                                (0x00000001&((data)<<0))
#define VE2_DRF_FAIL_GROUP_ve2_drf_fail_group_1_src(data)                            ((0x00000001&(data))>>0)
#define VE2_DRF_FAIL_GROUP_get_ve2_drf_fail_group_1(data)                            ((0x00000001&(data))>>0)


#define VE2_BIST1_FAIL                                                               0x18036F30
#define VE2_BIST1_FAIL_reg_addr                                                      "0xB8036F30"
#define VE2_BIST1_FAIL_reg                                                           0xB8036F30
#define set_VE2_BIST1_FAIL_reg(data)   (*((volatile unsigned int*) VE2_BIST1_FAIL_reg)=data)
#define get_VE2_BIST1_FAIL_reg   (*((volatile unsigned int*) VE2_BIST1_FAIL_reg))
#define VE2_BIST1_FAIL_inst_adr                                                      "0x00CC"
#define VE2_BIST1_FAIL_inst                                                          0x00CC
#define VE2_BIST1_FAIL_ve2_bist1_fail_shift                                          (0)
#define VE2_BIST1_FAIL_ve2_bist1_fail_mask                                           (0x000003FF)
#define VE2_BIST1_FAIL_ve2_bist1_fail(data)                                          (0x000003FF&((data)<<0))
#define VE2_BIST1_FAIL_ve2_bist1_fail_src(data)                                      ((0x000003FF&(data))>>0)
#define VE2_BIST1_FAIL_get_ve2_bist1_fail(data)                                      ((0x000003FF&(data))>>0)


#define VE2_DRF1_FAIL                                                                0x18036F34
#define VE2_DRF1_FAIL_reg_addr                                                       "0xB8036F34"
#define VE2_DRF1_FAIL_reg                                                            0xB8036F34
#define set_VE2_DRF1_FAIL_reg(data)   (*((volatile unsigned int*) VE2_DRF1_FAIL_reg)=data)
#define get_VE2_DRF1_FAIL_reg   (*((volatile unsigned int*) VE2_DRF1_FAIL_reg))
#define VE2_DRF1_FAIL_inst_adr                                                       "0x00CD"
#define VE2_DRF1_FAIL_inst                                                           0x00CD
#define VE2_DRF1_FAIL_ve2_drf1_fail_shift                                            (0)
#define VE2_DRF1_FAIL_ve2_drf1_fail_mask                                             (0x000003FF)
#define VE2_DRF1_FAIL_ve2_drf1_fail(data)                                            (0x000003FF&((data)<<0))
#define VE2_DRF1_FAIL_ve2_drf1_fail_src(data)                                        ((0x000003FF&(data))>>0)
#define VE2_DRF1_FAIL_get_ve2_drf1_fail(data)                                        ((0x000003FF&(data))>>0)


#define VE2_BIST2_FAIL                                                               0x18036F38
#define VE2_BIST2_FAIL_reg_addr                                                      "0xB8036F38"
#define VE2_BIST2_FAIL_reg                                                           0xB8036F38
#define set_VE2_BIST2_FAIL_reg(data)   (*((volatile unsigned int*) VE2_BIST2_FAIL_reg)=data)
#define get_VE2_BIST2_FAIL_reg   (*((volatile unsigned int*) VE2_BIST2_FAIL_reg))
#define VE2_BIST2_FAIL_inst_adr                                                      "0x00CE"
#define VE2_BIST2_FAIL_inst                                                          0x00CE
#define VE2_BIST2_FAIL_ve2_bist2_fail_shift                                          (0)
#define VE2_BIST2_FAIL_ve2_bist2_fail_mask                                           (0x0000003F)
#define VE2_BIST2_FAIL_ve2_bist2_fail(data)                                          (0x0000003F&((data)<<0))
#define VE2_BIST2_FAIL_ve2_bist2_fail_src(data)                                      ((0x0000003F&(data))>>0)
#define VE2_BIST2_FAIL_get_ve2_bist2_fail(data)                                      ((0x0000003F&(data))>>0)


#define VE2_DRF2_FAIL                                                                0x18036F3C
#define VE2_DRF2_FAIL_reg_addr                                                       "0xB8036F3C"
#define VE2_DRF2_FAIL_reg                                                            0xB8036F3C
#define set_VE2_DRF2_FAIL_reg(data)   (*((volatile unsigned int*) VE2_DRF2_FAIL_reg)=data)
#define get_VE2_DRF2_FAIL_reg   (*((volatile unsigned int*) VE2_DRF2_FAIL_reg))
#define VE2_DRF2_FAIL_inst_adr                                                       "0x00CF"
#define VE2_DRF2_FAIL_inst                                                           0x00CF
#define VE2_DRF2_FAIL_ve2_drf2_fail_shift                                            (0)
#define VE2_DRF2_FAIL_ve2_drf2_fail_mask                                             (0x0000003F)
#define VE2_DRF2_FAIL_ve2_drf2_fail(data)                                            (0x0000003F&((data)<<0))
#define VE2_DRF2_FAIL_ve2_drf2_fail_src(data)                                        ((0x0000003F&(data))>>0)
#define VE2_DRF2_FAIL_get_ve2_drf2_fail(data)                                        ((0x0000003F&(data))>>0)


#define VE2_BIST3_FAIL                                                               0x18036F40
#define VE2_BIST3_FAIL_reg_addr                                                      "0xB8036F40"
#define VE2_BIST3_FAIL_reg                                                           0xB8036F40
#define set_VE2_BIST3_FAIL_reg(data)   (*((volatile unsigned int*) VE2_BIST3_FAIL_reg)=data)
#define get_VE2_BIST3_FAIL_reg   (*((volatile unsigned int*) VE2_BIST3_FAIL_reg))
#define VE2_BIST3_FAIL_inst_adr                                                      "0x00D0"
#define VE2_BIST3_FAIL_inst                                                          0x00D0
#define VE2_BIST3_FAIL_ve2_bist3_fail_shift                                          (0)
#define VE2_BIST3_FAIL_ve2_bist3_fail_mask                                           (0x0000007F)
#define VE2_BIST3_FAIL_ve2_bist3_fail(data)                                          (0x0000007F&((data)<<0))
#define VE2_BIST3_FAIL_ve2_bist3_fail_src(data)                                      ((0x0000007F&(data))>>0)
#define VE2_BIST3_FAIL_get_ve2_bist3_fail(data)                                      ((0x0000007F&(data))>>0)


#define VE2_DRF3_FAIL                                                                0x18036F44
#define VE2_DRF3_FAIL_reg_addr                                                       "0xB8036F44"
#define VE2_DRF3_FAIL_reg                                                            0xB8036F44
#define set_VE2_DRF3_FAIL_reg(data)   (*((volatile unsigned int*) VE2_DRF3_FAIL_reg)=data)
#define get_VE2_DRF3_FAIL_reg   (*((volatile unsigned int*) VE2_DRF3_FAIL_reg))
#define VE2_DRF3_FAIL_inst_adr                                                       "0x00D1"
#define VE2_DRF3_FAIL_inst                                                           0x00D1
#define VE2_DRF3_FAIL_ve2_drf3_fail_shift                                            (0)
#define VE2_DRF3_FAIL_ve2_drf3_fail_mask                                             (0x0000007F)
#define VE2_DRF3_FAIL_ve2_drf3_fail(data)                                            (0x0000007F&((data)<<0))
#define VE2_DRF3_FAIL_ve2_drf3_fail_src(data)                                        ((0x0000007F&(data))>>0)
#define VE2_DRF3_FAIL_get_ve2_drf3_fail(data)                                        ((0x0000007F&(data))>>0)


#define VE2_BIST4_FAIL                                                               0x18036F48
#define VE2_BIST4_FAIL_reg_addr                                                      "0xB8036F48"
#define VE2_BIST4_FAIL_reg                                                           0xB8036F48
#define set_VE2_BIST4_FAIL_reg(data)   (*((volatile unsigned int*) VE2_BIST4_FAIL_reg)=data)
#define get_VE2_BIST4_FAIL_reg   (*((volatile unsigned int*) VE2_BIST4_FAIL_reg))
#define VE2_BIST4_FAIL_inst_adr                                                      "0x00D2"
#define VE2_BIST4_FAIL_inst                                                          0x00D2
#define VE2_BIST4_FAIL_ve2_bist4_fail_shift                                          (0)
#define VE2_BIST4_FAIL_ve2_bist4_fail_mask                                           (0x000000FF)
#define VE2_BIST4_FAIL_ve2_bist4_fail(data)                                          (0x000000FF&((data)<<0))
#define VE2_BIST4_FAIL_ve2_bist4_fail_src(data)                                      ((0x000000FF&(data))>>0)
#define VE2_BIST4_FAIL_get_ve2_bist4_fail(data)                                      ((0x000000FF&(data))>>0)


#define VE2_DRF4_FAIL                                                                0x18036F4C
#define VE2_DRF4_FAIL_reg_addr                                                       "0xB8036F4C"
#define VE2_DRF4_FAIL_reg                                                            0xB8036F4C
#define set_VE2_DRF4_FAIL_reg(data)   (*((volatile unsigned int*) VE2_DRF4_FAIL_reg)=data)
#define get_VE2_DRF4_FAIL_reg   (*((volatile unsigned int*) VE2_DRF4_FAIL_reg))
#define VE2_DRF4_FAIL_inst_adr                                                       "0x00D3"
#define VE2_DRF4_FAIL_inst                                                           0x00D3
#define VE2_DRF4_FAIL_ve2_drf4_fail_shift                                            (0)
#define VE2_DRF4_FAIL_ve2_drf4_fail_mask                                             (0x000000FF)
#define VE2_DRF4_FAIL_ve2_drf4_fail(data)                                            (0x000000FF&((data)<<0))
#define VE2_DRF4_FAIL_ve2_drf4_fail_src(data)                                        ((0x000000FF&(data))>>0)
#define VE2_DRF4_FAIL_get_ve2_drf4_fail(data)                                        ((0x000000FF&(data))>>0)


#define VE2_BIST5_FAIL                                                               0x18036F50
#define VE2_BIST5_FAIL_reg_addr                                                      "0xB8036F50"
#define VE2_BIST5_FAIL_reg                                                           0xB8036F50
#define set_VE2_BIST5_FAIL_reg(data)   (*((volatile unsigned int*) VE2_BIST5_FAIL_reg)=data)
#define get_VE2_BIST5_FAIL_reg   (*((volatile unsigned int*) VE2_BIST5_FAIL_reg))
#define VE2_BIST5_FAIL_inst_adr                                                      "0x00D4"
#define VE2_BIST5_FAIL_inst                                                          0x00D4
#define VE2_BIST5_FAIL_ve2_bist5_fail_shift                                          (0)
#define VE2_BIST5_FAIL_ve2_bist5_fail_mask                                           (0x0000003F)
#define VE2_BIST5_FAIL_ve2_bist5_fail(data)                                          (0x0000003F&((data)<<0))
#define VE2_BIST5_FAIL_ve2_bist5_fail_src(data)                                      ((0x0000003F&(data))>>0)
#define VE2_BIST5_FAIL_get_ve2_bist5_fail(data)                                      ((0x0000003F&(data))>>0)


#define VE2_DRF5_FAIL                                                                0x18036F54
#define VE2_DRF5_FAIL_reg_addr                                                       "0xB8036F54"
#define VE2_DRF5_FAIL_reg                                                            0xB8036F54
#define set_VE2_DRF5_FAIL_reg(data)   (*((volatile unsigned int*) VE2_DRF5_FAIL_reg)=data)
#define get_VE2_DRF5_FAIL_reg   (*((volatile unsigned int*) VE2_DRF5_FAIL_reg))
#define VE2_DRF5_FAIL_inst_adr                                                       "0x00D5"
#define VE2_DRF5_FAIL_inst                                                           0x00D5
#define VE2_DRF5_FAIL_ve2_drf5_fail_shift                                            (0)
#define VE2_DRF5_FAIL_ve2_drf5_fail_mask                                             (0x0000003F)
#define VE2_DRF5_FAIL_ve2_drf5_fail(data)                                            (0x0000003F&((data)<<0))
#define VE2_DRF5_FAIL_ve2_drf5_fail_src(data)                                        ((0x0000003F&(data))>>0)
#define VE2_DRF5_FAIL_get_ve2_drf5_fail(data)                                        ((0x0000003F&(data))>>0)


#define VE2_BIST6_FAIL                                                               0x18036F58
#define VE2_BIST6_FAIL_reg_addr                                                      "0xB8036F58"
#define VE2_BIST6_FAIL_reg                                                           0xB8036F58
#define set_VE2_BIST6_FAIL_reg(data)   (*((volatile unsigned int*) VE2_BIST6_FAIL_reg)=data)
#define get_VE2_BIST6_FAIL_reg   (*((volatile unsigned int*) VE2_BIST6_FAIL_reg))
#define VE2_BIST6_FAIL_inst_adr                                                      "0x00D6"
#define VE2_BIST6_FAIL_inst                                                          0x00D6
#define VE2_BIST6_FAIL_ve2_bist6_fail_shift                                          (0)
#define VE2_BIST6_FAIL_ve2_bist6_fail_mask                                           (0x0000003F)
#define VE2_BIST6_FAIL_ve2_bist6_fail(data)                                          (0x0000003F&((data)<<0))
#define VE2_BIST6_FAIL_ve2_bist6_fail_src(data)                                      ((0x0000003F&(data))>>0)
#define VE2_BIST6_FAIL_get_ve2_bist6_fail(data)                                      ((0x0000003F&(data))>>0)


#define VE2_DRF6_FAIL                                                                0x18036F5C
#define VE2_DRF6_FAIL_reg_addr                                                       "0xB8036F5C"
#define VE2_DRF6_FAIL_reg                                                            0xB8036F5C
#define set_VE2_DRF6_FAIL_reg(data)   (*((volatile unsigned int*) VE2_DRF6_FAIL_reg)=data)
#define get_VE2_DRF6_FAIL_reg   (*((volatile unsigned int*) VE2_DRF6_FAIL_reg))
#define VE2_DRF6_FAIL_inst_adr                                                       "0x00D7"
#define VE2_DRF6_FAIL_inst                                                           0x00D7
#define VE2_DRF6_FAIL_ve2_drf6_fail_shift                                            (0)
#define VE2_DRF6_FAIL_ve2_drf6_fail_mask                                             (0x0000003F)
#define VE2_DRF6_FAIL_ve2_drf6_fail(data)                                            (0x0000003F&((data)<<0))
#define VE2_DRF6_FAIL_ve2_drf6_fail_src(data)                                        ((0x0000003F&(data))>>0)
#define VE2_DRF6_FAIL_get_ve2_drf6_fail(data)                                        ((0x0000003F&(data))>>0)


#define VE2_BIST7_FAIL                                                               0x18036F60
#define VE2_BIST7_FAIL_reg_addr                                                      "0xB8036F60"
#define VE2_BIST7_FAIL_reg                                                           0xB8036F60
#define set_VE2_BIST7_FAIL_reg(data)   (*((volatile unsigned int*) VE2_BIST7_FAIL_reg)=data)
#define get_VE2_BIST7_FAIL_reg   (*((volatile unsigned int*) VE2_BIST7_FAIL_reg))
#define VE2_BIST7_FAIL_inst_adr                                                      "0x00D8"
#define VE2_BIST7_FAIL_inst                                                          0x00D8
#define VE2_BIST7_FAIL_ve2_bist7_fail_shift                                          (0)
#define VE2_BIST7_FAIL_ve2_bist7_fail_mask                                           (0x000003FF)
#define VE2_BIST7_FAIL_ve2_bist7_fail(data)                                          (0x000003FF&((data)<<0))
#define VE2_BIST7_FAIL_ve2_bist7_fail_src(data)                                      ((0x000003FF&(data))>>0)
#define VE2_BIST7_FAIL_get_ve2_bist7_fail(data)                                      ((0x000003FF&(data))>>0)


#define VE2_DRF7_FAIL                                                                0x18036F64
#define VE2_DRF7_FAIL_reg_addr                                                       "0xB8036F64"
#define VE2_DRF7_FAIL_reg                                                            0xB8036F64
#define set_VE2_DRF7_FAIL_reg(data)   (*((volatile unsigned int*) VE2_DRF7_FAIL_reg)=data)
#define get_VE2_DRF7_FAIL_reg   (*((volatile unsigned int*) VE2_DRF7_FAIL_reg))
#define VE2_DRF7_FAIL_inst_adr                                                       "0x00D9"
#define VE2_DRF7_FAIL_inst                                                           0x00D9
#define VE2_DRF7_FAIL_ve2_drf7_fail_shift                                            (0)
#define VE2_DRF7_FAIL_ve2_drf7_fail_mask                                             (0x000003FF)
#define VE2_DRF7_FAIL_ve2_drf7_fail(data)                                            (0x000003FF&((data)<<0))
#define VE2_DRF7_FAIL_ve2_drf7_fail_src(data)                                        ((0x000003FF&(data))>>0)
#define VE2_DRF7_FAIL_get_ve2_drf7_fail(data)                                        ((0x000003FF&(data))>>0)


#define VE2_BIST8_FAIL                                                               0x18036F68
#define VE2_BIST8_FAIL_reg_addr                                                      "0xB8036F68"
#define VE2_BIST8_FAIL_reg                                                           0xB8036F68
#define set_VE2_BIST8_FAIL_reg(data)   (*((volatile unsigned int*) VE2_BIST8_FAIL_reg)=data)
#define get_VE2_BIST8_FAIL_reg   (*((volatile unsigned int*) VE2_BIST8_FAIL_reg))
#define VE2_BIST8_FAIL_inst_adr                                                      "0x00DA"
#define VE2_BIST8_FAIL_inst                                                          0x00DA
#define VE2_BIST8_FAIL_ve2_bist8_fail_shift                                          (0)
#define VE2_BIST8_FAIL_ve2_bist8_fail_mask                                           (0x000000FF)
#define VE2_BIST8_FAIL_ve2_bist8_fail(data)                                          (0x000000FF&((data)<<0))
#define VE2_BIST8_FAIL_ve2_bist8_fail_src(data)                                      ((0x000000FF&(data))>>0)
#define VE2_BIST8_FAIL_get_ve2_bist8_fail(data)                                      ((0x000000FF&(data))>>0)


#define VE2_DRF8_FAIL                                                                0x18036F6C
#define VE2_DRF8_FAIL_reg_addr                                                       "0xB8036F6C"
#define VE2_DRF8_FAIL_reg                                                            0xB8036F6C
#define set_VE2_DRF8_FAIL_reg(data)   (*((volatile unsigned int*) VE2_DRF8_FAIL_reg)=data)
#define get_VE2_DRF8_FAIL_reg   (*((volatile unsigned int*) VE2_DRF8_FAIL_reg))
#define VE2_DRF8_FAIL_inst_adr                                                       "0x00DB"
#define VE2_DRF8_FAIL_inst                                                           0x00DB
#define VE2_DRF8_FAIL_ve2_drf8_fail_shift                                            (0)
#define VE2_DRF8_FAIL_ve2_drf8_fail_mask                                             (0x000000FF)
#define VE2_DRF8_FAIL_ve2_drf8_fail(data)                                            (0x000000FF&((data)<<0))
#define VE2_DRF8_FAIL_ve2_drf8_fail_src(data)                                        ((0x000000FF&(data))>>0)
#define VE2_DRF8_FAIL_get_ve2_drf8_fail(data)                                        ((0x000000FF&(data))>>0)


#define VE2_BIST9_FAIL                                                               0x18036F70
#define VE2_BIST9_FAIL_reg_addr                                                      "0xB8036F70"
#define VE2_BIST9_FAIL_reg                                                           0xB8036F70
#define set_VE2_BIST9_FAIL_reg(data)   (*((volatile unsigned int*) VE2_BIST9_FAIL_reg)=data)
#define get_VE2_BIST9_FAIL_reg   (*((volatile unsigned int*) VE2_BIST9_FAIL_reg))
#define VE2_BIST9_FAIL_inst_adr                                                      "0x00DC"
#define VE2_BIST9_FAIL_inst                                                          0x00DC
#define VE2_BIST9_FAIL_ve2_bist9_fail_shift                                          (0)
#define VE2_BIST9_FAIL_ve2_bist9_fail_mask                                           (0x000000FF)
#define VE2_BIST9_FAIL_ve2_bist9_fail(data)                                          (0x000000FF&((data)<<0))
#define VE2_BIST9_FAIL_ve2_bist9_fail_src(data)                                      ((0x000000FF&(data))>>0)
#define VE2_BIST9_FAIL_get_ve2_bist9_fail(data)                                      ((0x000000FF&(data))>>0)


#define VE2_DRF9_FAIL                                                                0x18036F74
#define VE2_DRF9_FAIL_reg_addr                                                       "0xB8036F74"
#define VE2_DRF9_FAIL_reg                                                            0xB8036F74
#define set_VE2_DRF9_FAIL_reg(data)   (*((volatile unsigned int*) VE2_DRF9_FAIL_reg)=data)
#define get_VE2_DRF9_FAIL_reg   (*((volatile unsigned int*) VE2_DRF9_FAIL_reg))
#define VE2_DRF9_FAIL_inst_adr                                                       "0x00DD"
#define VE2_DRF9_FAIL_inst                                                           0x00DD
#define VE2_DRF9_FAIL_ve2_drf9_fail_shift                                            (0)
#define VE2_DRF9_FAIL_ve2_drf9_fail_mask                                             (0x000000FF)
#define VE2_DRF9_FAIL_ve2_drf9_fail(data)                                            (0x000000FF&((data)<<0))
#define VE2_DRF9_FAIL_ve2_drf9_fail_src(data)                                        ((0x000000FF&(data))>>0)
#define VE2_DRF9_FAIL_get_ve2_drf9_fail(data)                                        ((0x000000FF&(data))>>0)


#define VE2_BIST10_FAIL                                                              0x18036F78
#define VE2_BIST10_FAIL_reg_addr                                                     "0xB8036F78"
#define VE2_BIST10_FAIL_reg                                                          0xB8036F78
#define set_VE2_BIST10_FAIL_reg(data)   (*((volatile unsigned int*) VE2_BIST10_FAIL_reg)=data)
#define get_VE2_BIST10_FAIL_reg   (*((volatile unsigned int*) VE2_BIST10_FAIL_reg))
#define VE2_BIST10_FAIL_inst_adr                                                     "0x00DE"
#define VE2_BIST10_FAIL_inst                                                         0x00DE
#define VE2_BIST10_FAIL_ve2_bist10_fail_shift                                        (0)
#define VE2_BIST10_FAIL_ve2_bist10_fail_mask                                         (0x0000001F)
#define VE2_BIST10_FAIL_ve2_bist10_fail(data)                                        (0x0000001F&((data)<<0))
#define VE2_BIST10_FAIL_ve2_bist10_fail_src(data)                                    ((0x0000001F&(data))>>0)
#define VE2_BIST10_FAIL_get_ve2_bist10_fail(data)                                    ((0x0000001F&(data))>>0)


#define VE2_DRF10_FAIL                                                               0x18036F7C
#define VE2_DRF10_FAIL_reg_addr                                                      "0xB8036F7C"
#define VE2_DRF10_FAIL_reg                                                           0xB8036F7C
#define set_VE2_DRF10_FAIL_reg(data)   (*((volatile unsigned int*) VE2_DRF10_FAIL_reg)=data)
#define get_VE2_DRF10_FAIL_reg   (*((volatile unsigned int*) VE2_DRF10_FAIL_reg))
#define VE2_DRF10_FAIL_inst_adr                                                      "0x00DF"
#define VE2_DRF10_FAIL_inst                                                          0x00DF
#define VE2_DRF10_FAIL_ve2_drf10_fail_shift                                          (0)
#define VE2_DRF10_FAIL_ve2_drf10_fail_mask                                           (0x0000001F)
#define VE2_DRF10_FAIL_ve2_drf10_fail(data)                                          (0x0000001F&((data)<<0))
#define VE2_DRF10_FAIL_ve2_drf10_fail_src(data)                                      ((0x0000001F&(data))>>0)
#define VE2_DRF10_FAIL_get_ve2_drf10_fail(data)                                      ((0x0000001F&(data))>>0)


#define VE2_BIST11_FAIL                                                              0x18036F80
#define VE2_BIST11_FAIL_reg_addr                                                     "0xB8036F80"
#define VE2_BIST11_FAIL_reg                                                          0xB8036F80
#define set_VE2_BIST11_FAIL_reg(data)   (*((volatile unsigned int*) VE2_BIST11_FAIL_reg)=data)
#define get_VE2_BIST11_FAIL_reg   (*((volatile unsigned int*) VE2_BIST11_FAIL_reg))
#define VE2_BIST11_FAIL_inst_adr                                                     "0x00E0"
#define VE2_BIST11_FAIL_inst                                                         0x00E0
#define VE2_BIST11_FAIL_ve2_bist11_fail_shift                                        (0)
#define VE2_BIST11_FAIL_ve2_bist11_fail_mask                                         (0x0000007F)
#define VE2_BIST11_FAIL_ve2_bist11_fail(data)                                        (0x0000007F&((data)<<0))
#define VE2_BIST11_FAIL_ve2_bist11_fail_src(data)                                    ((0x0000007F&(data))>>0)
#define VE2_BIST11_FAIL_get_ve2_bist11_fail(data)                                    ((0x0000007F&(data))>>0)


#define VE2_DRF11_FAIL                                                               0x18036F84
#define VE2_DRF11_FAIL_reg_addr                                                      "0xB8036F84"
#define VE2_DRF11_FAIL_reg                                                           0xB8036F84
#define set_VE2_DRF11_FAIL_reg(data)   (*((volatile unsigned int*) VE2_DRF11_FAIL_reg)=data)
#define get_VE2_DRF11_FAIL_reg   (*((volatile unsigned int*) VE2_DRF11_FAIL_reg))
#define VE2_DRF11_FAIL_inst_adr                                                      "0x00E1"
#define VE2_DRF11_FAIL_inst                                                          0x00E1
#define VE2_DRF11_FAIL_ve2_drf11_fail_shift                                          (0)
#define VE2_DRF11_FAIL_ve2_drf11_fail_mask                                           (0x0000007F)
#define VE2_DRF11_FAIL_ve2_drf11_fail(data)                                          (0x0000007F&((data)<<0))
#define VE2_DRF11_FAIL_ve2_drf11_fail_src(data)                                      ((0x0000007F&(data))>>0)
#define VE2_DRF11_FAIL_get_ve2_drf11_fail(data)                                      ((0x0000007F&(data))>>0)


#define VE2_BIST12_FAIL                                                              0x18036F88
#define VE2_BIST12_FAIL_reg_addr                                                     "0xB8036F88"
#define VE2_BIST12_FAIL_reg                                                          0xB8036F88
#define set_VE2_BIST12_FAIL_reg(data)   (*((volatile unsigned int*) VE2_BIST12_FAIL_reg)=data)
#define get_VE2_BIST12_FAIL_reg   (*((volatile unsigned int*) VE2_BIST12_FAIL_reg))
#define VE2_BIST12_FAIL_inst_adr                                                     "0x00E2"
#define VE2_BIST12_FAIL_inst                                                         0x00E2
#define VE2_BIST12_FAIL_ve2_bist12_fail_shift                                        (0)
#define VE2_BIST12_FAIL_ve2_bist12_fail_mask                                         (0x000001FF)
#define VE2_BIST12_FAIL_ve2_bist12_fail(data)                                        (0x000001FF&((data)<<0))
#define VE2_BIST12_FAIL_ve2_bist12_fail_src(data)                                    ((0x000001FF&(data))>>0)
#define VE2_BIST12_FAIL_get_ve2_bist12_fail(data)                                    ((0x000001FF&(data))>>0)


#define VE2_DRF12_FAIL                                                               0x18036F8C
#define VE2_DRF12_FAIL_reg_addr                                                      "0xB8036F8C"
#define VE2_DRF12_FAIL_reg                                                           0xB8036F8C
#define set_VE2_DRF12_FAIL_reg(data)   (*((volatile unsigned int*) VE2_DRF12_FAIL_reg)=data)
#define get_VE2_DRF12_FAIL_reg   (*((volatile unsigned int*) VE2_DRF12_FAIL_reg))
#define VE2_DRF12_FAIL_inst_adr                                                      "0x00E3"
#define VE2_DRF12_FAIL_inst                                                          0x00E3
#define VE2_DRF12_FAIL_ve2_drf12_fail_shift                                          (0)
#define VE2_DRF12_FAIL_ve2_drf12_fail_mask                                           (0x000001FF)
#define VE2_DRF12_FAIL_ve2_drf12_fail(data)                                          (0x000001FF&((data)<<0))
#define VE2_DRF12_FAIL_ve2_drf12_fail_src(data)                                      ((0x000001FF&(data))>>0)
#define VE2_DRF12_FAIL_get_ve2_drf12_fail(data)                                      ((0x000001FF&(data))>>0)


#define VE2_BIST12_FAIL                                                              0x18036F90
#define VE2_BIST12_FAIL_reg_addr                                                     "0xB8036F90"
#define VE2_BIST12_FAIL_reg                                                          0xB8036F90
#define set_VE2_BIST12_FAIL_reg(data)   (*((volatile unsigned int*) VE2_BIST12_FAIL_reg)=data)
#define get_VE2_BIST12_FAIL_reg   (*((volatile unsigned int*) VE2_BIST12_FAIL_reg))
#define VE2_BIST12_FAIL_inst_adr                                                     "0x00E4"
#define VE2_BIST12_FAIL_inst                                                         0x00E4
#define VE2_BIST12_FAIL_ve2_bist13_fail_shift                                        (0)
#define VE2_BIST12_FAIL_ve2_bist13_fail_mask                                         (0x0000001F)
#define VE2_BIST12_FAIL_ve2_bist13_fail(data)                                        (0x0000001F&((data)<<0))
#define VE2_BIST12_FAIL_ve2_bist13_fail_src(data)                                    ((0x0000001F&(data))>>0)
#define VE2_BIST12_FAIL_get_ve2_bist13_fail(data)                                    ((0x0000001F&(data))>>0)


#define VE2_DRF12_FAIL                                                               0x18036F94
#define VE2_DRF12_FAIL_reg_addr                                                      "0xB8036F94"
#define VE2_DRF12_FAIL_reg                                                           0xB8036F94
#define set_VE2_DRF12_FAIL_reg(data)   (*((volatile unsigned int*) VE2_DRF12_FAIL_reg)=data)
#define get_VE2_DRF12_FAIL_reg   (*((volatile unsigned int*) VE2_DRF12_FAIL_reg))
#define VE2_DRF12_FAIL_inst_adr                                                      "0x00E5"
#define VE2_DRF12_FAIL_inst                                                          0x00E5
#define VE2_DRF12_FAIL_ve2_drf13_fail_shift                                          (0)
#define VE2_DRF12_FAIL_ve2_drf13_fail_mask                                           (0x0000001F)
#define VE2_DRF12_FAIL_ve2_drf13_fail(data)                                          (0x0000001F&((data)<<0))
#define VE2_DRF12_FAIL_ve2_drf13_fail_src(data)                                      ((0x0000001F&(data))>>0)
#define VE2_DRF12_FAIL_get_ve2_drf13_fail(data)                                      ((0x0000001F&(data))>>0)


#endif
