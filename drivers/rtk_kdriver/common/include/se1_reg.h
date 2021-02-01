/**************************************************************
// Spec Version                  : 1.7
// Parser Version                : DVR_Parser_6.8(110516)
// CModelGen Version             : 5.0 2009.04.09
// Naming Rule                   :  Module_Register_Name
// Naming Rule                   : Module_Register_Name_reg
// Parse Option                  : Only Parse _op1
// Parse Address Region          : All Address Region 
// Decode bit number             : 12 bits
// Firmware Header Generate Date : 2014-6-20 21:47:16
***************************************************************/


#ifndef _SE1_REG_H_INCLUDED_
#define _SE1_REG_H_INCLUDED_
#ifdef  _SE1_USE_STRUCT
typedef struct 
{
unsigned int     base:28;
unsigned int     reserved_0:4;
}SE1_CMDBASE;

typedef struct 
{
unsigned int     limit:28;
unsigned int     reserved_0:4;
}SE1_CMDLMT;

typedef struct 
{
unsigned int     rptr:28;
unsigned int     reserved_0:4;
}SE1_CMDRPTR;

typedef struct 
{
unsigned int     wptr:28;
unsigned int     reserved_0:4;
}SE1_CMDWPTR;

typedef struct 
{
unsigned int     reserved_0:25;
unsigned int     srwordcnt:7;
}SE1_SRWORDCNT;

typedef struct 
{
unsigned int     reserved_0:20;
unsigned int     disable:4;
unsigned int     reserved_1:4;
unsigned int     Pri2:2;
unsigned int     Pri1:2;
}SE1_Q_PRIORITY;

typedef struct 
{
unsigned int     reserved_0:9;
unsigned int     write_enable10:1;
unsigned int     rounding_en:1;
unsigned int     write_enable8:1;
unsigned int     big_endian_o:1;
unsigned int     write_enable7:1;
unsigned int     big_endian_i2:1;
unsigned int     write_enable6:1;
unsigned int     big_endian_i1:1;
unsigned int     write_enable5:1;
unsigned int     alpha_loc2:1;
unsigned int     reserved_1:6;
unsigned int     write_enable2:1;
unsigned int     alpha_loc:1;
unsigned int     write_enable1:1;
unsigned int     Format:4;
}SE1_CLR_FMT;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     color_key:24;
}SE1_COLOR_KEY;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     dst_color_key:24;
}SE1_DST_COLOR_KEY;

typedef struct 
{
unsigned int     src_color:32;
}SE1_SRC_COLOR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     src_alpha:8;
}SE1_SRC_ALPHA;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     dest_alpha:8;
}SE1_DEST_ALPHA;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     rslt_alpha:8;
}SE1_RSLT_ALPHA;

typedef struct 
{
unsigned int     baddr:32;
}SE1_BADDR1;

typedef struct 
{
unsigned int     reserved_0:15;
unsigned int     interleave:1;
unsigned int     pitch:16;
}SE1_PITCH1;

typedef struct 
{
unsigned int     baddr:32;
}SE1_BADDR2;

typedef struct 
{
unsigned int     reserved_0:15;
unsigned int     interleave:1;
unsigned int     pitch:16;
}SE1_PITCH2;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     clut_lock_st:3;
}SE1_CLUT_LOCK_ST;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     hdown:1;
unsigned int     vdown:1;
unsigned int     hup:1;
unsigned int     vup:1;
}SE1_CONVSCALING;

typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     m01:13;
unsigned int     m00:13;
}SE1_CONVCOEF1;

typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     m10:13;
unsigned int     m02:13;
}SE1_CONVCOEF2;

typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     m12:13;
unsigned int     m11:13;
}SE1_CONVCOEF3;

typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     m21:13;
unsigned int     m20:13;
}SE1_CONVCOEF4;

typedef struct 
{
unsigned int     reserved_0:19;
unsigned int     m22:13;
}SE1_CONVCOEF5;

typedef struct 
{
unsigned int     reserved_0:2;
unsigned int     a2:10;
unsigned int     a1:10;
unsigned int     a0:10;
}SE1_CONVCOEF6;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     color_key:24;
}SE1_FCV_BITBLIT_COLOR_KEY;

typedef struct 
{
unsigned int     reserved_0:7;
unsigned int     src_clr_add_red:9;
unsigned int     reserved_1:7;
unsigned int     src_clr_mul_red:9;
}SE1_SRC_CLR_RED;

typedef struct 
{
unsigned int     reserved_0:7;
unsigned int     src_clr_add_green:9;
unsigned int     reserved_1:7;
unsigned int     src_clr_mul_green:9;
}SE1_SRC_CLR_GREEN;

typedef struct 
{
unsigned int     reserved_0:7;
unsigned int     src_clr_add_blue:9;
unsigned int     reserved_1:7;
unsigned int     src_clr_mul_blue:9;
}SE1_SRC_CLR_BLUE;

typedef struct 
{
unsigned int     reserved_0:7;
unsigned int     src_clr_add_alpha:9;
unsigned int     reserved_1:7;
unsigned int     src_clr_mul_alpha:9;
}SE1_SRC_CLR_ALPHA;

typedef struct 
{
unsigned int     auto_dir_en:1;
unsigned int     vo_plane:1;
unsigned int     before_vo_cur:1;
unsigned int     after_vo_cur:1;
unsigned int     vbi:1;
unsigned int     reserved_0:15;
unsigned int     margin_VOtoSE:12;
}SE1_SYNC_VO_MARGIN;

typedef struct 
{
unsigned int     reserved_0:18;
unsigned int     VO_current_y:14;
}SE1_SYNC_VO_LOCATION;

typedef struct 
{
unsigned int     reserved_0:15;
unsigned int     gdma_direction:1;
unsigned int     reserved_1:3;
unsigned int     total_y:13;
}SE1_SYNC_VO_TOTAL_Y;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     color_alpha:8;
}SE1_FB_COLORALPHA;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     repl_alpha:1;
unsigned int     repl_color:1;
unsigned int     ref_alpha:1;
unsigned int     htype:2;
unsigned int     vtype:1;
unsigned int     hodd:1;
unsigned int     vodd:1;
}SE1_STRETCH;

typedef struct 
{
unsigned int     reserved_0:10;
unsigned int     H_scaling_iniph:4;
unsigned int     H_scaling_dph_msb:4;
unsigned int     H_scaling_dph_lsb:14;
}SE1_HDHS;

typedef struct 
{
unsigned int     reserved_0:10;
unsigned int     V_scaling_iniph:4;
unsigned int     V_scaling_dph_msb:4;
unsigned int     V_scaling_dph_lsb:14;
}SE1_VDHS;

typedef struct 
{
unsigned int     reserved_0:18;
unsigned int     hcoef:14;
}SE1_HCOEF1;

typedef struct 
{
unsigned int     reserved_0:18;
unsigned int     hcoef:14;
}SE1_HCOEF1_32;

typedef struct 
{
unsigned int     reserved_0:18;
unsigned int     vcoef:14;
}SE1_VCOEF1;

typedef struct 
{
unsigned int     reserved_0:18;
unsigned int     vcoef:14;
}SE1_VCOEF1_16;

typedef struct 
{
unsigned int     reserved_0:18;
unsigned int     hcoef:14;
}SE1_HCOEF2;

typedef struct 
{
unsigned int     reserved_0:18;
unsigned int     hcoef:14;
}SE1_HCOEF2_32;

typedef struct 
{
unsigned int     reserved_0:18;
unsigned int     vcoef:14;
}SE1_VCOEF2;

typedef struct 
{
unsigned int     reserved_0:18;
unsigned int     vcoef:14;
}SE1_VCOEF2_16;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     color_key:24;
}SE1_SC_BITBLIT_COLOR_KEY;

typedef struct 
{
unsigned int     m22:16;
unsigned int     m11:16;
}SE1_QT_INV_MATRIX_SCALING;

typedef struct 
{
unsigned int     m21:16;
unsigned int     m12:16;
}SE1_QT_INV_MATRIX_SHEARING;

typedef struct 
{
unsigned int     m32:16;
unsigned int     m31:16;
}SE1_QT_INV_MATRIX_MOVING;

typedef struct 
{
unsigned int     m23:16;
unsigned int     m13:16;
}SE1_QT_INV_MATRIX_PROJECTION_0;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     m33:16;
}SE1_QT_INV_MATRIX_PROJECTION_1;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     src_x_color_g_step:13;
unsigned int     reserved_1:3;
unsigned int     src_x_color_r_step:13;
}SE1_SRC_LG_2;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     src_x_color_b_step:13;
unsigned int     reserved_1:3;
unsigned int     src_x_alpha_step:13;
}SE1_SRC_LG_3;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     src_y_color_g_step:13;
unsigned int     reserved_1:3;
unsigned int     src_y_color_r_step:13;
}SE1_SRC_LG_4;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     src_y_color_b_step:13;
unsigned int     reserved_1:3;
unsigned int     src_y_alpha_step:13;
}SE1_SRC_LG_5;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     src_color_direction:2;
}SE1_SRC_LG_6;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     dst_dfb_alp_ctrl:1;
unsigned int     src_dfb_alp_ctrl:1;
}SE1_DFB_CTRL;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     endiswap:1;
unsigned int     go:1;
unsigned int     write_data:1;
}SE1_CTRL;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     idle:1;
}SE1_IDLE;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     sel2:2;
unsigned int     sel1:2;
}SE1_INTSEL;

typedef struct 
{
unsigned int     reserved_0:14;
unsigned int     vo_sync_err:1;
unsigned int     fmt_err:1;
unsigned int     reserved_1:12;
unsigned int     com_empty:1;
unsigned int     com_err:1;
unsigned int     sync:1;
unsigned int     write_data:1;
}SE1_INTS;

typedef struct 
{
unsigned int     reserved_0:14;
unsigned int     vo_sync_err:1;
unsigned int     fmt_err:1;
unsigned int     reserved_1:12;
unsigned int     com_empty:1;
unsigned int     com_err:1;
unsigned int     sync:1;
unsigned int     write_data:1;
}SE1_INTE;

typedef struct 
{
unsigned int     instcnt_l:32;
}SE1_INSTCNT_L;

typedef struct 
{
unsigned int     instcnt_h:32;
}SE1_INSTCNT_H;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     radr:8;
}SE1_CLUT_RADR;

typedef struct 
{
unsigned int     value:32;
}SE1_CLUT_VALUE;

typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     dbg_change:1;
unsigned int     dbg_en:1;
unsigned int     dbg_module_sel1:4;
unsigned int     dbg_module_sel0:4;
unsigned int     reserved_1:3;
unsigned int     dbg_sel1:5;
unsigned int     reserved_2:3;
unsigned int     dbg_sel0:5;
}SE1_DBG;

typedef struct 
{
unsigned int     Reg1:16;
unsigned int     Reg0:16;
}SE1_SCTCH;

typedef struct 
{
unsigned int     reserved_0:26;
unsigned int     ls:1;
unsigned int     rm:4;
unsigned int     rme:1;
}SE1_READ_MARGIN;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     se1_bist_mode_1:1;
unsigned int     se1_bist_mode_0:1;
}SE1_SE1_BIST_MODE;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     se1_bist_done_1:1;
unsigned int     se1_bist_done_0:1;
}SE1_SE1_BIST_DONE;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     se1_bist_fail_group_1:1;
unsigned int     se1_bist_fail_group_0:1;
}SE1_SE1_BIST_FAIL_GROUP;

typedef struct 
{
unsigned int     reserved_0:23;
unsigned int     se1_bist_0_fail_8:1;
unsigned int     se1_bist_0_fail_7:1;
unsigned int     se1_bist_0_fail_6:1;
unsigned int     se1_bist_0_fail_5:1;
unsigned int     se1_bist_0_fail_4:1;
unsigned int     se1_bist_0_fail_3:1;
unsigned int     se1_bist_0_fail_2:1;
unsigned int     se1_bist_0_fail_1:1;
unsigned int     se1_bist_0_fail_0:1;
}SE1_SE1_BIST_0_FAIL;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     se1_bist_1_fail_1:1;
unsigned int     se1_bist_1_fail_0:1;
}SE1_SE1_BIST_1_FAIL;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     se1_drf_mode_1:1;
unsigned int     se1_drf_mode_0:1;
}SE1_SE1_DRF_MODE;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     se1_drf_resume_1:1;
unsigned int     se1_drf_resume_0:1;
}SE1_SE1_DRF_RESUME;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     se1_drf_done_1:1;
unsigned int     se1_drf_done_0:1;
}SE1_SE1_DRF_DONE;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     se1_drf_pause1_1:1;
unsigned int     se1_drf_pause1_0:1;
}SE1_SE1_DRF_PAUSE;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     se1_drf_fail_group_1:1;
unsigned int     se1_drf_fail_group_0:1;
}SE1_SE1_DRF_FAIL_GROUP;

typedef struct 
{
unsigned int     reserved_0:23;
unsigned int     se1_drf_0_fail_8:1;
unsigned int     se1_drf_0_fail_7:1;
unsigned int     se1_drf_0_fail_6:1;
unsigned int     se1_drf_0_fail_5:1;
unsigned int     se1_drf_0_fail_4:1;
unsigned int     se1_drf_0_fail_3:1;
unsigned int     se1_drf_0_fail_2:1;
unsigned int     se1_drf_0_fail_1:1;
unsigned int     se1_drf_0_fail_0:1;
}SE1_SE1_DRF_0_FAIL;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     se1_drf_1_fail_1:1;
unsigned int     se1_drf_1_fail_0:1;
}SE1_SE1_DRF_1_FAIL;

#endif

#define SE1_CMDBASE_0                                                                 0x1803E000
#define SE1_CMDBASE_1                                                                 0x1803E004
#define SE1_CMDBASE_0_reg_addr                                                        "0xB803E000"
#define SE1_CMDBASE_1_reg_addr                                                        "0xB803E004"
#define SE1_CMDBASE_0_reg                                                             0xB803E000
#define SE1_CMDBASE_1_reg                                                             0xB803E004
#define set_SE1_CMDBASE_0_reg(data)   (*((volatile unsigned int*) SE1_CMDBASE_0_reg)=data)
#define set_SE1_CMDBASE_1_reg(data)   (*((volatile unsigned int*) SE1_CMDBASE_1_reg)=data)
#define get_SE1_CMDBASE_0_reg   (*((volatile unsigned int*) SE1_CMDBASE_0_reg))
#define get_SE1_CMDBASE_1_reg   (*((volatile unsigned int*) SE1_CMDBASE_1_reg))
#define SE1_CMDBASE_0_inst_adr                                                        "0x0000"
#define SE1_CMDBASE_1_inst_adr                                                        "0x0001"
#define SE1_CMDBASE_0_inst                                                            0x0000
#define SE1_CMDBASE_1_inst                                                            0x0001
#define SE1_CMDBASE_base_shift                                                        (4)
#define SE1_CMDBASE_base_mask                                                         (0xFFFFFFF0)
#define SE1_CMDBASE_base(data)                                                        (0xFFFFFFF0&((data)<<4))
#define SE1_CMDBASE_base_src(data)                                                    ((0xFFFFFFF0&(data))>>4)
#define SE1_CMDBASE_get_base(data)                                                    ((0xFFFFFFF0&(data))>>4)


#define SE1_CMDLMT_0                                                                  0x1803E010
#define SE1_CMDLMT_1                                                                  0x1803E014
#define SE1_CMDLMT_0_reg_addr                                                         "0xB803E010"
#define SE1_CMDLMT_1_reg_addr                                                         "0xB803E014"
#define SE1_CMDLMT_0_reg                                                              0xB803E010
#define SE1_CMDLMT_1_reg                                                              0xB803E014
#define set_SE1_CMDLMT_0_reg(data)   (*((volatile unsigned int*) SE1_CMDLMT_0_reg)=data)
#define set_SE1_CMDLMT_1_reg(data)   (*((volatile unsigned int*) SE1_CMDLMT_1_reg)=data)
#define get_SE1_CMDLMT_0_reg   (*((volatile unsigned int*) SE1_CMDLMT_0_reg))
#define get_SE1_CMDLMT_1_reg   (*((volatile unsigned int*) SE1_CMDLMT_1_reg))
#define SE1_CMDLMT_0_inst_adr                                                         "0x0004"
#define SE1_CMDLMT_1_inst_adr                                                         "0x0005"
#define SE1_CMDLMT_0_inst                                                             0x0004
#define SE1_CMDLMT_1_inst                                                             0x0005
#define SE1_CMDLMT_limit_shift                                                        (4)
#define SE1_CMDLMT_limit_mask                                                         (0xFFFFFFF0)
#define SE1_CMDLMT_limit(data)                                                        (0xFFFFFFF0&((data)<<4))
#define SE1_CMDLMT_limit_src(data)                                                    ((0xFFFFFFF0&(data))>>4)
#define SE1_CMDLMT_get_limit(data)                                                    ((0xFFFFFFF0&(data))>>4)


#define SE1_CMDRPTR_0                                                                 0x1803E020
#define SE1_CMDRPTR_1                                                                 0x1803E024
#define SE1_CMDRPTR_0_reg_addr                                                        "0xB803E020"
#define SE1_CMDRPTR_1_reg_addr                                                        "0xB803E024"
#define SE1_CMDRPTR_0_reg                                                             0xB803E020
#define SE1_CMDRPTR_1_reg                                                             0xB803E024
#define set_SE1_CMDRPTR_0_reg(data)   (*((volatile unsigned int*) SE1_CMDRPTR_0_reg)=data)
#define set_SE1_CMDRPTR_1_reg(data)   (*((volatile unsigned int*) SE1_CMDRPTR_1_reg)=data)
#define get_SE1_CMDRPTR_0_reg   (*((volatile unsigned int*) SE1_CMDRPTR_0_reg))
#define get_SE1_CMDRPTR_1_reg   (*((volatile unsigned int*) SE1_CMDRPTR_1_reg))
#define SE1_CMDRPTR_0_inst_adr                                                        "0x0008"
#define SE1_CMDRPTR_1_inst_adr                                                        "0x0009"
#define SE1_CMDRPTR_0_inst                                                            0x0008
#define SE1_CMDRPTR_1_inst                                                            0x0009
#define SE1_CMDRPTR_rptr_shift                                                        (4)
#define SE1_CMDRPTR_rptr_mask                                                         (0xFFFFFFF0)
#define SE1_CMDRPTR_rptr(data)                                                        (0xFFFFFFF0&((data)<<4))
#define SE1_CMDRPTR_rptr_src(data)                                                    ((0xFFFFFFF0&(data))>>4)
#define SE1_CMDRPTR_get_rptr(data)                                                    ((0xFFFFFFF0&(data))>>4)


#define SE1_CMDWPTR_0                                                                 0x1803E030
#define SE1_CMDWPTR_1                                                                 0x1803E034
#define SE1_CMDWPTR_0_reg_addr                                                        "0xB803E030"
#define SE1_CMDWPTR_1_reg_addr                                                        "0xB803E034"
#define SE1_CMDWPTR_0_reg                                                             0xB803E030
#define SE1_CMDWPTR_1_reg                                                             0xB803E034
#define set_SE1_CMDWPTR_0_reg(data)   (*((volatile unsigned int*) SE1_CMDWPTR_0_reg)=data)
#define set_SE1_CMDWPTR_1_reg(data)   (*((volatile unsigned int*) SE1_CMDWPTR_1_reg)=data)
#define get_SE1_CMDWPTR_0_reg   (*((volatile unsigned int*) SE1_CMDWPTR_0_reg))
#define get_SE1_CMDWPTR_1_reg   (*((volatile unsigned int*) SE1_CMDWPTR_1_reg))
#define SE1_CMDWPTR_0_inst_adr                                                        "0x000C"
#define SE1_CMDWPTR_1_inst_adr                                                        "0x000D"
#define SE1_CMDWPTR_0_inst                                                            0x000C
#define SE1_CMDWPTR_1_inst                                                            0x000D
#define SE1_CMDWPTR_wptr_shift                                                        (4)
#define SE1_CMDWPTR_wptr_mask                                                         (0xFFFFFFF0)
#define SE1_CMDWPTR_wptr(data)                                                        (0xFFFFFFF0&((data)<<4))
#define SE1_CMDWPTR_wptr_src(data)                                                    ((0xFFFFFFF0&(data))>>4)
#define SE1_CMDWPTR_get_wptr(data)                                                    ((0xFFFFFFF0&(data))>>4)


#define SE1_SRWORDCNT_0                                                               0x1803E040
#define SE1_SRWORDCNT_1                                                               0x1803E044
#define SE1_SRWORDCNT_0_reg_addr                                                      "0xB803E040"
#define SE1_SRWORDCNT_1_reg_addr                                                      "0xB803E044"
#define SE1_SRWORDCNT_0_reg                                                           0xB803E040
#define SE1_SRWORDCNT_1_reg                                                           0xB803E044
#define set_SE1_SRWORDCNT_0_reg(data)   (*((volatile unsigned int*) SE1_SRWORDCNT_0_reg)=data)
#define set_SE1_SRWORDCNT_1_reg(data)   (*((volatile unsigned int*) SE1_SRWORDCNT_1_reg)=data)
#define get_SE1_SRWORDCNT_0_reg   (*((volatile unsigned int*) SE1_SRWORDCNT_0_reg))
#define get_SE1_SRWORDCNT_1_reg   (*((volatile unsigned int*) SE1_SRWORDCNT_1_reg))
#define SE1_SRWORDCNT_0_inst_adr                                                      "0x0010"
#define SE1_SRWORDCNT_1_inst_adr                                                      "0x0011"
#define SE1_SRWORDCNT_0_inst                                                          0x0010
#define SE1_SRWORDCNT_1_inst                                                          0x0011
#define SE1_SRWORDCNT_srwordcnt_shift                                                 (0)
#define SE1_SRWORDCNT_srwordcnt_mask                                                  (0x0000007F)
#define SE1_SRWORDCNT_srwordcnt(data)                                                 (0x0000007F&((data)<<0))
#define SE1_SRWORDCNT_srwordcnt_src(data)                                             ((0x0000007F&(data))>>0)
#define SE1_SRWORDCNT_get_srwordcnt(data)                                             ((0x0000007F&(data))>>0)


#define SE1_Q_PRIORITY                                                                0x1803E050
#define SE1_Q_PRIORITY_reg_addr                                                       "0xB803E050"
#define SE1_Q_PRIORITY_reg                                                            0xB803E050
#define set_SE1_Q_PRIORITY_reg(data)   (*((volatile unsigned int*) SE1_Q_PRIORITY_reg)=data)
#define get_SE1_Q_PRIORITY_reg   (*((volatile unsigned int*) SE1_Q_PRIORITY_reg))
#define SE1_Q_PRIORITY_inst_adr                                                       "0x0014"
#define SE1_Q_PRIORITY_inst                                                           0x0014
#define SE1_Q_PRIORITY_disable_shift                                                  (8)
#define SE1_Q_PRIORITY_disable_mask                                                   (0x00000F00)
#define SE1_Q_PRIORITY_disable(data)                                                  (0x00000F00&((data)<<8))
#define SE1_Q_PRIORITY_disable_src(data)                                              ((0x00000F00&(data))>>8)
#define SE1_Q_PRIORITY_get_disable(data)                                              ((0x00000F00&(data))>>8)
#define SE1_Q_PRIORITY_Pri2_shift                                                     (2)
#define SE1_Q_PRIORITY_Pri2_mask                                                      (0x0000000C)
#define SE1_Q_PRIORITY_Pri2(data)                                                     (0x0000000C&((data)<<2))
#define SE1_Q_PRIORITY_Pri2_src(data)                                                 ((0x0000000C&(data))>>2)
#define SE1_Q_PRIORITY_get_Pri2(data)                                                 ((0x0000000C&(data))>>2)
#define SE1_Q_PRIORITY_Pri1_shift                                                     (0)
#define SE1_Q_PRIORITY_Pri1_mask                                                      (0x00000003)
#define SE1_Q_PRIORITY_Pri1(data)                                                     (0x00000003&((data)<<0))
#define SE1_Q_PRIORITY_Pri1_src(data)                                                 ((0x00000003&(data))>>0)
#define SE1_Q_PRIORITY_get_Pri1(data)                                                 ((0x00000003&(data))>>0)


#define SE1_CLR_FMT_0                                                                 0x1803E060
#define SE1_CLR_FMT_1                                                                 0x1803E064
#define SE1_CLR_FMT_0_reg_addr                                                        "0xB803E060"
#define SE1_CLR_FMT_1_reg_addr                                                        "0xB803E064"
#define SE1_CLR_FMT_0_reg                                                             0xB803E060
#define SE1_CLR_FMT_1_reg                                                             0xB803E064
#define set_SE1_CLR_FMT_0_reg(data)   (*((volatile unsigned int*) SE1_CLR_FMT_0_reg)=data)
#define set_SE1_CLR_FMT_1_reg(data)   (*((volatile unsigned int*) SE1_CLR_FMT_1_reg)=data)
#define get_SE1_CLR_FMT_0_reg   (*((volatile unsigned int*) SE1_CLR_FMT_0_reg))
#define get_SE1_CLR_FMT_1_reg   (*((volatile unsigned int*) SE1_CLR_FMT_1_reg))
#define SE1_CLR_FMT_0_inst_adr                                                        "0x0018"
#define SE1_CLR_FMT_1_inst_adr                                                        "0x0019"
#define SE1_CLR_FMT_0_inst                                                            0x0018
#define SE1_CLR_FMT_1_inst                                                            0x0019
#define SE1_CLR_FMT_write_enable10_shift                                              (22)
#define SE1_CLR_FMT_write_enable10_mask                                               (0x00400000)
#define SE1_CLR_FMT_write_enable10(data)                                              (0x00400000&((data)<<22))
#define SE1_CLR_FMT_write_enable10_src(data)                                          ((0x00400000&(data))>>22)
#define SE1_CLR_FMT_get_write_enable10(data)                                          ((0x00400000&(data))>>22)
#define SE1_CLR_FMT_rounding_en_shift                                                 (21)
#define SE1_CLR_FMT_rounding_en_mask                                                  (0x00200000)
#define SE1_CLR_FMT_rounding_en(data)                                                 (0x00200000&((data)<<21))
#define SE1_CLR_FMT_rounding_en_src(data)                                             ((0x00200000&(data))>>21)
#define SE1_CLR_FMT_get_rounding_en(data)                                             ((0x00200000&(data))>>21)
#define SE1_CLR_FMT_write_enable8_shift                                               (20)
#define SE1_CLR_FMT_write_enable8_mask                                                (0x00100000)
#define SE1_CLR_FMT_write_enable8(data)                                               (0x00100000&((data)<<20))
#define SE1_CLR_FMT_write_enable8_src(data)                                           ((0x00100000&(data))>>20)
#define SE1_CLR_FMT_get_write_enable8(data)                                           ((0x00100000&(data))>>20)
#define SE1_CLR_FMT_big_endian_o_shift                                                (19)
#define SE1_CLR_FMT_big_endian_o_mask                                                 (0x00080000)
#define SE1_CLR_FMT_big_endian_o(data)                                                (0x00080000&((data)<<19))
#define SE1_CLR_FMT_big_endian_o_src(data)                                            ((0x00080000&(data))>>19)
#define SE1_CLR_FMT_get_big_endian_o(data)                                            ((0x00080000&(data))>>19)
#define SE1_CLR_FMT_write_enable7_shift                                               (18)
#define SE1_CLR_FMT_write_enable7_mask                                                (0x00040000)
#define SE1_CLR_FMT_write_enable7(data)                                               (0x00040000&((data)<<18))
#define SE1_CLR_FMT_write_enable7_src(data)                                           ((0x00040000&(data))>>18)
#define SE1_CLR_FMT_get_write_enable7(data)                                           ((0x00040000&(data))>>18)
#define SE1_CLR_FMT_big_endian_i2_shift                                               (17)
#define SE1_CLR_FMT_big_endian_i2_mask                                                (0x00020000)
#define SE1_CLR_FMT_big_endian_i2(data)                                               (0x00020000&((data)<<17))
#define SE1_CLR_FMT_big_endian_i2_src(data)                                           ((0x00020000&(data))>>17)
#define SE1_CLR_FMT_get_big_endian_i2(data)                                           ((0x00020000&(data))>>17)
#define SE1_CLR_FMT_write_enable6_shift                                               (16)
#define SE1_CLR_FMT_write_enable6_mask                                                (0x00010000)
#define SE1_CLR_FMT_write_enable6(data)                                               (0x00010000&((data)<<16))
#define SE1_CLR_FMT_write_enable6_src(data)                                           ((0x00010000&(data))>>16)
#define SE1_CLR_FMT_get_write_enable6(data)                                           ((0x00010000&(data))>>16)
#define SE1_CLR_FMT_big_endian_i1_shift                                               (15)
#define SE1_CLR_FMT_big_endian_i1_mask                                                (0x00008000)
#define SE1_CLR_FMT_big_endian_i1(data)                                               (0x00008000&((data)<<15))
#define SE1_CLR_FMT_big_endian_i1_src(data)                                           ((0x00008000&(data))>>15)
#define SE1_CLR_FMT_get_big_endian_i1(data)                                           ((0x00008000&(data))>>15)
#define SE1_CLR_FMT_write_enable5_shift                                               (14)
#define SE1_CLR_FMT_write_enable5_mask                                                (0x00004000)
#define SE1_CLR_FMT_write_enable5(data)                                               (0x00004000&((data)<<14))
#define SE1_CLR_FMT_write_enable5_src(data)                                           ((0x00004000&(data))>>14)
#define SE1_CLR_FMT_get_write_enable5(data)                                           ((0x00004000&(data))>>14)
#define SE1_CLR_FMT_alpha_loc2_shift                                                  (13)
#define SE1_CLR_FMT_alpha_loc2_mask                                                   (0x00002000)
#define SE1_CLR_FMT_alpha_loc2(data)                                                  (0x00002000&((data)<<13))
#define SE1_CLR_FMT_alpha_loc2_src(data)                                              ((0x00002000&(data))>>13)
#define SE1_CLR_FMT_get_alpha_loc2(data)                                              ((0x00002000&(data))>>13)
#define SE1_CLR_FMT_write_enable2_shift                                               (6)
#define SE1_CLR_FMT_write_enable2_mask                                                (0x00000040)
#define SE1_CLR_FMT_write_enable2(data)                                               (0x00000040&((data)<<6))
#define SE1_CLR_FMT_write_enable2_src(data)                                           ((0x00000040&(data))>>6)
#define SE1_CLR_FMT_get_write_enable2(data)                                           ((0x00000040&(data))>>6)
#define SE1_CLR_FMT_alpha_loc_shift                                                   (5)
#define SE1_CLR_FMT_alpha_loc_mask                                                    (0x00000020)
#define SE1_CLR_FMT_alpha_loc(data)                                                   (0x00000020&((data)<<5))
#define SE1_CLR_FMT_alpha_loc_src(data)                                               ((0x00000020&(data))>>5)
#define SE1_CLR_FMT_get_alpha_loc(data)                                               ((0x00000020&(data))>>5)
#define SE1_CLR_FMT_write_enable1_shift                                               (4)
#define SE1_CLR_FMT_write_enable1_mask                                                (0x00000010)
#define SE1_CLR_FMT_write_enable1(data)                                               (0x00000010&((data)<<4))
#define SE1_CLR_FMT_write_enable1_src(data)                                           ((0x00000010&(data))>>4)
#define SE1_CLR_FMT_get_write_enable1(data)                                           ((0x00000010&(data))>>4)
#define SE1_CLR_FMT_Format_shift                                                      (0)
#define SE1_CLR_FMT_Format_mask                                                       (0x0000000F)
#define SE1_CLR_FMT_Format(data)                                                      (0x0000000F&((data)<<0))
#define SE1_CLR_FMT_Format_src(data)                                                  ((0x0000000F&(data))>>0)
#define SE1_CLR_FMT_get_Format(data)                                                  ((0x0000000F&(data))>>0)


#define SE1_COLOR_KEY_0                                                               0x1803E070
#define SE1_COLOR_KEY_1                                                               0x1803E074
#define SE1_COLOR_KEY_0_reg_addr                                                      "0xB803E070"
#define SE1_COLOR_KEY_1_reg_addr                                                      "0xB803E074"
#define SE1_COLOR_KEY_0_reg                                                           0xB803E070
#define SE1_COLOR_KEY_1_reg                                                           0xB803E074
#define set_SE1_COLOR_KEY_0_reg(data)   (*((volatile unsigned int*) SE1_COLOR_KEY_0_reg)=data)
#define set_SE1_COLOR_KEY_1_reg(data)   (*((volatile unsigned int*) SE1_COLOR_KEY_1_reg)=data)
#define get_SE1_COLOR_KEY_0_reg   (*((volatile unsigned int*) SE1_COLOR_KEY_0_reg))
#define get_SE1_COLOR_KEY_1_reg   (*((volatile unsigned int*) SE1_COLOR_KEY_1_reg))
#define SE1_COLOR_KEY_0_inst_adr                                                      "0x001C"
#define SE1_COLOR_KEY_1_inst_adr                                                      "0x001D"
#define SE1_COLOR_KEY_0_inst                                                          0x001C
#define SE1_COLOR_KEY_1_inst                                                          0x001D
#define SE1_COLOR_KEY_color_key_shift                                                 (0)
#define SE1_COLOR_KEY_color_key_mask                                                  (0x00FFFFFF)
#define SE1_COLOR_KEY_color_key(data)                                                 (0x00FFFFFF&((data)<<0))
#define SE1_COLOR_KEY_color_key_src(data)                                             ((0x00FFFFFF&(data))>>0)
#define SE1_COLOR_KEY_get_color_key(data)                                             ((0x00FFFFFF&(data))>>0)


#define SE1_DST_COLOR_KEY_0                                                           0x1803E080
#define SE1_DST_COLOR_KEY_1                                                           0x1803E084
#define SE1_DST_COLOR_KEY_0_reg_addr                                                  "0xB803E080"
#define SE1_DST_COLOR_KEY_1_reg_addr                                                  "0xB803E084"
#define SE1_DST_COLOR_KEY_0_reg                                                       0xB803E080
#define SE1_DST_COLOR_KEY_1_reg                                                       0xB803E084
#define set_SE1_DST_COLOR_KEY_0_reg(data)   (*((volatile unsigned int*) SE1_DST_COLOR_KEY_0_reg)=data)
#define set_SE1_DST_COLOR_KEY_1_reg(data)   (*((volatile unsigned int*) SE1_DST_COLOR_KEY_1_reg)=data)
#define get_SE1_DST_COLOR_KEY_0_reg   (*((volatile unsigned int*) SE1_DST_COLOR_KEY_0_reg))
#define get_SE1_DST_COLOR_KEY_1_reg   (*((volatile unsigned int*) SE1_DST_COLOR_KEY_1_reg))
#define SE1_DST_COLOR_KEY_0_inst_adr                                                  "0x0020"
#define SE1_DST_COLOR_KEY_1_inst_adr                                                  "0x0021"
#define SE1_DST_COLOR_KEY_0_inst                                                      0x0020
#define SE1_DST_COLOR_KEY_1_inst                                                      0x0021
#define SE1_DST_COLOR_KEY_dst_color_key_shift                                         (0)
#define SE1_DST_COLOR_KEY_dst_color_key_mask                                          (0x00FFFFFF)
#define SE1_DST_COLOR_KEY_dst_color_key(data)                                         (0x00FFFFFF&((data)<<0))
#define SE1_DST_COLOR_KEY_dst_color_key_src(data)                                     ((0x00FFFFFF&(data))>>0)
#define SE1_DST_COLOR_KEY_get_dst_color_key(data)                                     ((0x00FFFFFF&(data))>>0)


#define SE1_SRC_COLOR_0                                                               0x1803E090
#define SE1_SRC_COLOR_1                                                               0x1803E094
#define SE1_SRC_COLOR_0_reg_addr                                                      "0xB803E090"
#define SE1_SRC_COLOR_1_reg_addr                                                      "0xB803E094"
#define SE1_SRC_COLOR_0_reg                                                           0xB803E090
#define SE1_SRC_COLOR_1_reg                                                           0xB803E094
#define set_SE1_SRC_COLOR_0_reg(data)   (*((volatile unsigned int*) SE1_SRC_COLOR_0_reg)=data)
#define set_SE1_SRC_COLOR_1_reg(data)   (*((volatile unsigned int*) SE1_SRC_COLOR_1_reg)=data)
#define get_SE1_SRC_COLOR_0_reg   (*((volatile unsigned int*) SE1_SRC_COLOR_0_reg))
#define get_SE1_SRC_COLOR_1_reg   (*((volatile unsigned int*) SE1_SRC_COLOR_1_reg))
#define SE1_SRC_COLOR_0_inst_adr                                                      "0x0024"
#define SE1_SRC_COLOR_1_inst_adr                                                      "0x0025"
#define SE1_SRC_COLOR_0_inst                                                          0x0024
#define SE1_SRC_COLOR_1_inst                                                          0x0025
#define SE1_SRC_COLOR_src_color_shift                                                 (0)
#define SE1_SRC_COLOR_src_color_mask                                                  (0xFFFFFFFF)
#define SE1_SRC_COLOR_src_color(data)                                                 (0xFFFFFFFF&((data)<<0))
#define SE1_SRC_COLOR_src_color_src(data)                                             ((0xFFFFFFFF&(data))>>0)
#define SE1_SRC_COLOR_get_src_color(data)                                             ((0xFFFFFFFF&(data))>>0)


#define SE1_SRC_ALPHA_0                                                               0x1803E0A0
#define SE1_SRC_ALPHA_1                                                               0x1803E0A4
#define SE1_SRC_ALPHA_0_reg_addr                                                      "0xB803E0A0"
#define SE1_SRC_ALPHA_1_reg_addr                                                      "0xB803E0A4"
#define SE1_SRC_ALPHA_0_reg                                                           0xB803E0A0
#define SE1_SRC_ALPHA_1_reg                                                           0xB803E0A4
#define set_SE1_SRC_ALPHA_0_reg(data)   (*((volatile unsigned int*) SE1_SRC_ALPHA_0_reg)=data)
#define set_SE1_SRC_ALPHA_1_reg(data)   (*((volatile unsigned int*) SE1_SRC_ALPHA_1_reg)=data)
#define get_SE1_SRC_ALPHA_0_reg   (*((volatile unsigned int*) SE1_SRC_ALPHA_0_reg))
#define get_SE1_SRC_ALPHA_1_reg   (*((volatile unsigned int*) SE1_SRC_ALPHA_1_reg))
#define SE1_SRC_ALPHA_0_inst_adr                                                      "0x0028"
#define SE1_SRC_ALPHA_1_inst_adr                                                      "0x0029"
#define SE1_SRC_ALPHA_0_inst                                                          0x0028
#define SE1_SRC_ALPHA_1_inst                                                          0x0029
#define SE1_SRC_ALPHA_src_alpha_shift                                                 (0)
#define SE1_SRC_ALPHA_src_alpha_mask                                                  (0x000000FF)
#define SE1_SRC_ALPHA_src_alpha(data)                                                 (0x000000FF&((data)<<0))
#define SE1_SRC_ALPHA_src_alpha_src(data)                                             ((0x000000FF&(data))>>0)
#define SE1_SRC_ALPHA_get_src_alpha(data)                                             ((0x000000FF&(data))>>0)


#define SE1_DEST_ALPHA_0                                                              0x1803E0B0
#define SE1_DEST_ALPHA_1                                                              0x1803E0B4
#define SE1_DEST_ALPHA_0_reg_addr                                                     "0xB803E0B0"
#define SE1_DEST_ALPHA_1_reg_addr                                                     "0xB803E0B4"
#define SE1_DEST_ALPHA_0_reg                                                          0xB803E0B0
#define SE1_DEST_ALPHA_1_reg                                                          0xB803E0B4
#define set_SE1_DEST_ALPHA_0_reg(data)   (*((volatile unsigned int*) SE1_DEST_ALPHA_0_reg)=data)
#define set_SE1_DEST_ALPHA_1_reg(data)   (*((volatile unsigned int*) SE1_DEST_ALPHA_1_reg)=data)
#define get_SE1_DEST_ALPHA_0_reg   (*((volatile unsigned int*) SE1_DEST_ALPHA_0_reg))
#define get_SE1_DEST_ALPHA_1_reg   (*((volatile unsigned int*) SE1_DEST_ALPHA_1_reg))
#define SE1_DEST_ALPHA_0_inst_adr                                                     "0x002C"
#define SE1_DEST_ALPHA_1_inst_adr                                                     "0x002D"
#define SE1_DEST_ALPHA_0_inst                                                         0x002C
#define SE1_DEST_ALPHA_1_inst                                                         0x002D
#define SE1_DEST_ALPHA_dest_alpha_shift                                               (0)
#define SE1_DEST_ALPHA_dest_alpha_mask                                                (0x000000FF)
#define SE1_DEST_ALPHA_dest_alpha(data)                                               (0x000000FF&((data)<<0))
#define SE1_DEST_ALPHA_dest_alpha_src(data)                                           ((0x000000FF&(data))>>0)
#define SE1_DEST_ALPHA_get_dest_alpha(data)                                           ((0x000000FF&(data))>>0)


#define SE1_RSLT_ALPHA_0                                                              0x1803E0C0
#define SE1_RSLT_ALPHA_1                                                              0x1803E0C4
#define SE1_RSLT_ALPHA_0_reg_addr                                                     "0xB803E0C0"
#define SE1_RSLT_ALPHA_1_reg_addr                                                     "0xB803E0C4"
#define SE1_RSLT_ALPHA_0_reg                                                          0xB803E0C0
#define SE1_RSLT_ALPHA_1_reg                                                          0xB803E0C4
#define set_SE1_RSLT_ALPHA_0_reg(data)   (*((volatile unsigned int*) SE1_RSLT_ALPHA_0_reg)=data)
#define set_SE1_RSLT_ALPHA_1_reg(data)   (*((volatile unsigned int*) SE1_RSLT_ALPHA_1_reg)=data)
#define get_SE1_RSLT_ALPHA_0_reg   (*((volatile unsigned int*) SE1_RSLT_ALPHA_0_reg))
#define get_SE1_RSLT_ALPHA_1_reg   (*((volatile unsigned int*) SE1_RSLT_ALPHA_1_reg))
#define SE1_RSLT_ALPHA_0_inst_adr                                                     "0x0030"
#define SE1_RSLT_ALPHA_1_inst_adr                                                     "0x0031"
#define SE1_RSLT_ALPHA_0_inst                                                         0x0030
#define SE1_RSLT_ALPHA_1_inst                                                         0x0031
#define SE1_RSLT_ALPHA_rslt_alpha_shift                                               (0)
#define SE1_RSLT_ALPHA_rslt_alpha_mask                                                (0x000000FF)
#define SE1_RSLT_ALPHA_rslt_alpha(data)                                               (0x000000FF&((data)<<0))
#define SE1_RSLT_ALPHA_rslt_alpha_src(data)                                           ((0x000000FF&(data))>>0)
#define SE1_RSLT_ALPHA_get_rslt_alpha(data)                                           ((0x000000FF&(data))>>0)


#define SE1_BADDR1_0                                                                  0x1803E0D0
#define SE1_BADDR1_1                                                                  0x1803E0D4
#define SE1_BADDR1_2                                                                  0x1803E0D8
#define SE1_BADDR1_3                                                                  0x1803E0DC
#define SE1_BADDR1_0_reg_addr                                                         "0xB803E0D0"
#define SE1_BADDR1_1_reg_addr                                                         "0xB803E0D4"
#define SE1_BADDR1_2_reg_addr                                                         "0xB803E0D8"
#define SE1_BADDR1_3_reg_addr                                                         "0xB803E0DC"
#define SE1_BADDR1_0_reg                                                              0xB803E0D0
#define SE1_BADDR1_1_reg                                                              0xB803E0D4
#define SE1_BADDR1_2_reg                                                              0xB803E0D8
#define SE1_BADDR1_3_reg                                                              0xB803E0DC
#define set_SE1_BADDR1_0_reg(data)   (*((volatile unsigned int*) SE1_BADDR1_0_reg)=data)
#define set_SE1_BADDR1_1_reg(data)   (*((volatile unsigned int*) SE1_BADDR1_1_reg)=data)
#define set_SE1_BADDR1_2_reg(data)   (*((volatile unsigned int*) SE1_BADDR1_2_reg)=data)
#define set_SE1_BADDR1_3_reg(data)   (*((volatile unsigned int*) SE1_BADDR1_3_reg)=data)
#define get_SE1_BADDR1_0_reg   (*((volatile unsigned int*) SE1_BADDR1_0_reg))
#define get_SE1_BADDR1_1_reg   (*((volatile unsigned int*) SE1_BADDR1_1_reg))
#define get_SE1_BADDR1_2_reg   (*((volatile unsigned int*) SE1_BADDR1_2_reg))
#define get_SE1_BADDR1_3_reg   (*((volatile unsigned int*) SE1_BADDR1_3_reg))
#define SE1_BADDR1_0_inst_adr                                                         "0x0034"
#define SE1_BADDR1_1_inst_adr                                                         "0x0035"
#define SE1_BADDR1_2_inst_adr                                                         "0x0036"
#define SE1_BADDR1_3_inst_adr                                                         "0x0037"
#define SE1_BADDR1_0_inst                                                             0x0034
#define SE1_BADDR1_1_inst                                                             0x0035
#define SE1_BADDR1_2_inst                                                             0x0036
#define SE1_BADDR1_3_inst                                                             0x0037
#define SE1_BADDR1_baddr_shift                                                        (0)
#define SE1_BADDR1_baddr_mask                                                         (0xFFFFFFFF)
#define SE1_BADDR1_baddr(data)                                                        (0xFFFFFFFF&((data)<<0))
#define SE1_BADDR1_baddr_src(data)                                                    ((0xFFFFFFFF&(data))>>0)
#define SE1_BADDR1_get_baddr(data)                                                    ((0xFFFFFFFF&(data))>>0)


#define SE1_PITCH1_0                                                                  0x1803E0E0
#define SE1_PITCH1_1                                                                  0x1803E0E4
#define SE1_PITCH1_2                                                                  0x1803E0E8
#define SE1_PITCH1_3                                                                  0x1803E0EC
#define SE1_PITCH1_0_reg_addr                                                         "0xB803E0E0"
#define SE1_PITCH1_1_reg_addr                                                         "0xB803E0E4"
#define SE1_PITCH1_2_reg_addr                                                         "0xB803E0E8"
#define SE1_PITCH1_3_reg_addr                                                         "0xB803E0EC"
#define SE1_PITCH1_0_reg                                                              0xB803E0E0
#define SE1_PITCH1_1_reg                                                              0xB803E0E4
#define SE1_PITCH1_2_reg                                                              0xB803E0E8
#define SE1_PITCH1_3_reg                                                              0xB803E0EC
#define set_SE1_PITCH1_0_reg(data)   (*((volatile unsigned int*) SE1_PITCH1_0_reg)=data)
#define set_SE1_PITCH1_1_reg(data)   (*((volatile unsigned int*) SE1_PITCH1_1_reg)=data)
#define set_SE1_PITCH1_2_reg(data)   (*((volatile unsigned int*) SE1_PITCH1_2_reg)=data)
#define set_SE1_PITCH1_3_reg(data)   (*((volatile unsigned int*) SE1_PITCH1_3_reg)=data)
#define get_SE1_PITCH1_0_reg   (*((volatile unsigned int*) SE1_PITCH1_0_reg))
#define get_SE1_PITCH1_1_reg   (*((volatile unsigned int*) SE1_PITCH1_1_reg))
#define get_SE1_PITCH1_2_reg   (*((volatile unsigned int*) SE1_PITCH1_2_reg))
#define get_SE1_PITCH1_3_reg   (*((volatile unsigned int*) SE1_PITCH1_3_reg))
#define SE1_PITCH1_0_inst_adr                                                         "0x0038"
#define SE1_PITCH1_1_inst_adr                                                         "0x0039"
#define SE1_PITCH1_2_inst_adr                                                         "0x003A"
#define SE1_PITCH1_3_inst_adr                                                         "0x003B"
#define SE1_PITCH1_0_inst                                                             0x0038
#define SE1_PITCH1_1_inst                                                             0x0039
#define SE1_PITCH1_2_inst                                                             0x003A
#define SE1_PITCH1_3_inst                                                             0x003B
#define SE1_PITCH1_interleave_shift                                                   (16)
#define SE1_PITCH1_interleave_mask                                                    (0x00010000)
#define SE1_PITCH1_interleave(data)                                                   (0x00010000&((data)<<16))
#define SE1_PITCH1_interleave_src(data)                                               ((0x00010000&(data))>>16)
#define SE1_PITCH1_get_interleave(data)                                               ((0x00010000&(data))>>16)
#define SE1_PITCH1_pitch_shift                                                        (0)
#define SE1_PITCH1_pitch_mask                                                         (0x0000FFFF)
#define SE1_PITCH1_pitch(data)                                                        (0x0000FFFF&((data)<<0))
#define SE1_PITCH1_pitch_src(data)                                                    ((0x0000FFFF&(data))>>0)
#define SE1_PITCH1_get_pitch(data)                                                    ((0x0000FFFF&(data))>>0)


#define SE1_BADDR2_0                                                                  0x1803E0F0
#define SE1_BADDR2_1                                                                  0x1803E0F4
#define SE1_BADDR2_2                                                                  0x1803E0F8
#define SE1_BADDR2_3                                                                  0x1803E0FC
#define SE1_BADDR2_0_reg_addr                                                         "0xB803E0F0"
#define SE1_BADDR2_1_reg_addr                                                         "0xB803E0F4"
#define SE1_BADDR2_2_reg_addr                                                         "0xB803E0F8"
#define SE1_BADDR2_3_reg_addr                                                         "0xB803E0FC"
#define SE1_BADDR2_0_reg                                                              0xB803E0F0
#define SE1_BADDR2_1_reg                                                              0xB803E0F4
#define SE1_BADDR2_2_reg                                                              0xB803E0F8
#define SE1_BADDR2_3_reg                                                              0xB803E0FC
#define set_SE1_BADDR2_0_reg(data)   (*((volatile unsigned int*) SE1_BADDR2_0_reg)=data)
#define set_SE1_BADDR2_1_reg(data)   (*((volatile unsigned int*) SE1_BADDR2_1_reg)=data)
#define set_SE1_BADDR2_2_reg(data)   (*((volatile unsigned int*) SE1_BADDR2_2_reg)=data)
#define set_SE1_BADDR2_3_reg(data)   (*((volatile unsigned int*) SE1_BADDR2_3_reg)=data)
#define get_SE1_BADDR2_0_reg   (*((volatile unsigned int*) SE1_BADDR2_0_reg))
#define get_SE1_BADDR2_1_reg   (*((volatile unsigned int*) SE1_BADDR2_1_reg))
#define get_SE1_BADDR2_2_reg   (*((volatile unsigned int*) SE1_BADDR2_2_reg))
#define get_SE1_BADDR2_3_reg   (*((volatile unsigned int*) SE1_BADDR2_3_reg))
#define SE1_BADDR2_0_inst_adr                                                         "0x003C"
#define SE1_BADDR2_1_inst_adr                                                         "0x003D"
#define SE1_BADDR2_2_inst_adr                                                         "0x003E"
#define SE1_BADDR2_3_inst_adr                                                         "0x003F"
#define SE1_BADDR2_0_inst                                                             0x003C
#define SE1_BADDR2_1_inst                                                             0x003D
#define SE1_BADDR2_2_inst                                                             0x003E
#define SE1_BADDR2_3_inst                                                             0x003F
#define SE1_BADDR2_baddr_shift                                                        (0)
#define SE1_BADDR2_baddr_mask                                                         (0xFFFFFFFF)
#define SE1_BADDR2_baddr(data)                                                        (0xFFFFFFFF&((data)<<0))
#define SE1_BADDR2_baddr_src(data)                                                    ((0xFFFFFFFF&(data))>>0)
#define SE1_BADDR2_get_baddr(data)                                                    ((0xFFFFFFFF&(data))>>0)


#define SE1_PITCH2_0                                                                  0x1803E100
#define SE1_PITCH2_1                                                                  0x1803E104
#define SE1_PITCH2_2                                                                  0x1803E108
#define SE1_PITCH2_3                                                                  0x1803E10C
#define SE1_PITCH2_0_reg_addr                                                         "0xB803E100"
#define SE1_PITCH2_1_reg_addr                                                         "0xB803E104"
#define SE1_PITCH2_2_reg_addr                                                         "0xB803E108"
#define SE1_PITCH2_3_reg_addr                                                         "0xB803E10C"
#define SE1_PITCH2_0_reg                                                              0xB803E100
#define SE1_PITCH2_1_reg                                                              0xB803E104
#define SE1_PITCH2_2_reg                                                              0xB803E108
#define SE1_PITCH2_3_reg                                                              0xB803E10C
#define set_SE1_PITCH2_0_reg(data)   (*((volatile unsigned int*) SE1_PITCH2_0_reg)=data)
#define set_SE1_PITCH2_1_reg(data)   (*((volatile unsigned int*) SE1_PITCH2_1_reg)=data)
#define set_SE1_PITCH2_2_reg(data)   (*((volatile unsigned int*) SE1_PITCH2_2_reg)=data)
#define set_SE1_PITCH2_3_reg(data)   (*((volatile unsigned int*) SE1_PITCH2_3_reg)=data)
#define get_SE1_PITCH2_0_reg   (*((volatile unsigned int*) SE1_PITCH2_0_reg))
#define get_SE1_PITCH2_1_reg   (*((volatile unsigned int*) SE1_PITCH2_1_reg))
#define get_SE1_PITCH2_2_reg   (*((volatile unsigned int*) SE1_PITCH2_2_reg))
#define get_SE1_PITCH2_3_reg   (*((volatile unsigned int*) SE1_PITCH2_3_reg))
#define SE1_PITCH2_0_inst_adr                                                         "0x0040"
#define SE1_PITCH2_1_inst_adr                                                         "0x0041"
#define SE1_PITCH2_2_inst_adr                                                         "0x0042"
#define SE1_PITCH2_3_inst_adr                                                         "0x0043"
#define SE1_PITCH2_0_inst                                                             0x0040
#define SE1_PITCH2_1_inst                                                             0x0041
#define SE1_PITCH2_2_inst                                                             0x0042
#define SE1_PITCH2_3_inst                                                             0x0043
#define SE1_PITCH2_interleave_shift                                                   (16)
#define SE1_PITCH2_interleave_mask                                                    (0x00010000)
#define SE1_PITCH2_interleave(data)                                                   (0x00010000&((data)<<16))
#define SE1_PITCH2_interleave_src(data)                                               ((0x00010000&(data))>>16)
#define SE1_PITCH2_get_interleave(data)                                               ((0x00010000&(data))>>16)
#define SE1_PITCH2_pitch_shift                                                        (0)
#define SE1_PITCH2_pitch_mask                                                         (0x0000FFFF)
#define SE1_PITCH2_pitch(data)                                                        (0x0000FFFF&((data)<<0))
#define SE1_PITCH2_pitch_src(data)                                                    ((0x0000FFFF&(data))>>0)
#define SE1_PITCH2_get_pitch(data)                                                    ((0x0000FFFF&(data))>>0)


#define SE1_CLUT_LOCK_ST                                                              0x1803E1D0
#define SE1_CLUT_LOCK_ST_reg_addr                                                     "0xB803E1D0"
#define SE1_CLUT_LOCK_ST_reg                                                          0xB803E1D0
#define set_SE1_CLUT_LOCK_ST_reg(data)   (*((volatile unsigned int*) SE1_CLUT_LOCK_ST_reg)=data)
#define get_SE1_CLUT_LOCK_ST_reg   (*((volatile unsigned int*) SE1_CLUT_LOCK_ST_reg))
#define SE1_CLUT_LOCK_ST_inst_adr                                                     "0x0074"
#define SE1_CLUT_LOCK_ST_inst                                                         0x0074
#define SE1_CLUT_LOCK_ST_clut_lock_st_shift                                           (0)
#define SE1_CLUT_LOCK_ST_clut_lock_st_mask                                            (0x00000007)
#define SE1_CLUT_LOCK_ST_clut_lock_st(data)                                           (0x00000007&((data)<<0))
#define SE1_CLUT_LOCK_ST_clut_lock_st_src(data)                                       ((0x00000007&(data))>>0)
#define SE1_CLUT_LOCK_ST_get_clut_lock_st(data)                                       ((0x00000007&(data))>>0)


#define SE1_CONVSCALING_0                                                             0x1803E1E0
#define SE1_CONVSCALING_1                                                             0x1803E1E4
#define SE1_CONVSCALING_0_reg_addr                                                    "0xB803E1E0"
#define SE1_CONVSCALING_1_reg_addr                                                    "0xB803E1E4"
#define SE1_CONVSCALING_0_reg                                                         0xB803E1E0
#define SE1_CONVSCALING_1_reg                                                         0xB803E1E4
#define set_SE1_CONVSCALING_0_reg(data)   (*((volatile unsigned int*) SE1_CONVSCALING_0_reg)=data)
#define set_SE1_CONVSCALING_1_reg(data)   (*((volatile unsigned int*) SE1_CONVSCALING_1_reg)=data)
#define get_SE1_CONVSCALING_0_reg   (*((volatile unsigned int*) SE1_CONVSCALING_0_reg))
#define get_SE1_CONVSCALING_1_reg   (*((volatile unsigned int*) SE1_CONVSCALING_1_reg))
#define SE1_CONVSCALING_0_inst_adr                                                    "0x0078"
#define SE1_CONVSCALING_1_inst_adr                                                    "0x0079"
#define SE1_CONVSCALING_0_inst                                                        0x0078
#define SE1_CONVSCALING_1_inst                                                        0x0079
#define SE1_CONVSCALING_hdown_shift                                                   (3)
#define SE1_CONVSCALING_hdown_mask                                                    (0x00000008)
#define SE1_CONVSCALING_hdown(data)                                                   (0x00000008&((data)<<3))
#define SE1_CONVSCALING_hdown_src(data)                                               ((0x00000008&(data))>>3)
#define SE1_CONVSCALING_get_hdown(data)                                               ((0x00000008&(data))>>3)
#define SE1_CONVSCALING_vdown_shift                                                   (2)
#define SE1_CONVSCALING_vdown_mask                                                    (0x00000004)
#define SE1_CONVSCALING_vdown(data)                                                   (0x00000004&((data)<<2))
#define SE1_CONVSCALING_vdown_src(data)                                               ((0x00000004&(data))>>2)
#define SE1_CONVSCALING_get_vdown(data)                                               ((0x00000004&(data))>>2)
#define SE1_CONVSCALING_hup_shift                                                     (1)
#define SE1_CONVSCALING_hup_mask                                                      (0x00000002)
#define SE1_CONVSCALING_hup(data)                                                     (0x00000002&((data)<<1))
#define SE1_CONVSCALING_hup_src(data)                                                 ((0x00000002&(data))>>1)
#define SE1_CONVSCALING_get_hup(data)                                                 ((0x00000002&(data))>>1)
#define SE1_CONVSCALING_vup_shift                                                     (0)
#define SE1_CONVSCALING_vup_mask                                                      (0x00000001)
#define SE1_CONVSCALING_vup(data)                                                     (0x00000001&((data)<<0))
#define SE1_CONVSCALING_vup_src(data)                                                 ((0x00000001&(data))>>0)
#define SE1_CONVSCALING_get_vup(data)                                                 ((0x00000001&(data))>>0)


#define SE1_CONVCOEF1_0                                                               0x1803E1F0
#define SE1_CONVCOEF1_1                                                               0x1803E1F4
#define SE1_CONVCOEF1_0_reg_addr                                                      "0xB803E1F0"
#define SE1_CONVCOEF1_1_reg_addr                                                      "0xB803E1F4"
#define SE1_CONVCOEF1_0_reg                                                           0xB803E1F0
#define SE1_CONVCOEF1_1_reg                                                           0xB803E1F4
#define set_SE1_CONVCOEF1_0_reg(data)   (*((volatile unsigned int*) SE1_CONVCOEF1_0_reg)=data)
#define set_SE1_CONVCOEF1_1_reg(data)   (*((volatile unsigned int*) SE1_CONVCOEF1_1_reg)=data)
#define get_SE1_CONVCOEF1_0_reg   (*((volatile unsigned int*) SE1_CONVCOEF1_0_reg))
#define get_SE1_CONVCOEF1_1_reg   (*((volatile unsigned int*) SE1_CONVCOEF1_1_reg))
#define SE1_CONVCOEF1_0_inst_adr                                                      "0x007C"
#define SE1_CONVCOEF1_1_inst_adr                                                      "0x007D"
#define SE1_CONVCOEF1_0_inst                                                          0x007C
#define SE1_CONVCOEF1_1_inst                                                          0x007D
#define SE1_CONVCOEF1_m01_shift                                                       (13)
#define SE1_CONVCOEF1_m01_mask                                                        (0x03FFE000)
#define SE1_CONVCOEF1_m01(data)                                                       (0x03FFE000&((data)<<13))
#define SE1_CONVCOEF1_m01_src(data)                                                   ((0x03FFE000&(data))>>13)
#define SE1_CONVCOEF1_get_m01(data)                                                   ((0x03FFE000&(data))>>13)
#define SE1_CONVCOEF1_m00_shift                                                       (0)
#define SE1_CONVCOEF1_m00_mask                                                        (0x00001FFF)
#define SE1_CONVCOEF1_m00(data)                                                       (0x00001FFF&((data)<<0))
#define SE1_CONVCOEF1_m00_src(data)                                                   ((0x00001FFF&(data))>>0)
#define SE1_CONVCOEF1_get_m00(data)                                                   ((0x00001FFF&(data))>>0)


#define SE1_CONVCOEF2_0                                                               0x1803E200
#define SE1_CONVCOEF2_1                                                               0x1803E204
#define SE1_CONVCOEF2_0_reg_addr                                                      "0xB803E200"
#define SE1_CONVCOEF2_1_reg_addr                                                      "0xB803E204"
#define SE1_CONVCOEF2_0_reg                                                           0xB803E200
#define SE1_CONVCOEF2_1_reg                                                           0xB803E204
#define set_SE1_CONVCOEF2_0_reg(data)   (*((volatile unsigned int*) SE1_CONVCOEF2_0_reg)=data)
#define set_SE1_CONVCOEF2_1_reg(data)   (*((volatile unsigned int*) SE1_CONVCOEF2_1_reg)=data)
#define get_SE1_CONVCOEF2_0_reg   (*((volatile unsigned int*) SE1_CONVCOEF2_0_reg))
#define get_SE1_CONVCOEF2_1_reg   (*((volatile unsigned int*) SE1_CONVCOEF2_1_reg))
#define SE1_CONVCOEF2_0_inst_adr                                                      "0x0080"
#define SE1_CONVCOEF2_1_inst_adr                                                      "0x0081"
#define SE1_CONVCOEF2_0_inst                                                          0x0080
#define SE1_CONVCOEF2_1_inst                                                          0x0081
#define SE1_CONVCOEF2_m10_shift                                                       (13)
#define SE1_CONVCOEF2_m10_mask                                                        (0x03FFE000)
#define SE1_CONVCOEF2_m10(data)                                                       (0x03FFE000&((data)<<13))
#define SE1_CONVCOEF2_m10_src(data)                                                   ((0x03FFE000&(data))>>13)
#define SE1_CONVCOEF2_get_m10(data)                                                   ((0x03FFE000&(data))>>13)
#define SE1_CONVCOEF2_m02_shift                                                       (0)
#define SE1_CONVCOEF2_m02_mask                                                        (0x00001FFF)
#define SE1_CONVCOEF2_m02(data)                                                       (0x00001FFF&((data)<<0))
#define SE1_CONVCOEF2_m02_src(data)                                                   ((0x00001FFF&(data))>>0)
#define SE1_CONVCOEF2_get_m02(data)                                                   ((0x00001FFF&(data))>>0)


#define SE1_CONVCOEF3_0                                                               0x1803E210
#define SE1_CONVCOEF3_1                                                               0x1803E214
#define SE1_CONVCOEF3_0_reg_addr                                                      "0xB803E210"
#define SE1_CONVCOEF3_1_reg_addr                                                      "0xB803E214"
#define SE1_CONVCOEF3_0_reg                                                           0xB803E210
#define SE1_CONVCOEF3_1_reg                                                           0xB803E214
#define set_SE1_CONVCOEF3_0_reg(data)   (*((volatile unsigned int*) SE1_CONVCOEF3_0_reg)=data)
#define set_SE1_CONVCOEF3_1_reg(data)   (*((volatile unsigned int*) SE1_CONVCOEF3_1_reg)=data)
#define get_SE1_CONVCOEF3_0_reg   (*((volatile unsigned int*) SE1_CONVCOEF3_0_reg))
#define get_SE1_CONVCOEF3_1_reg   (*((volatile unsigned int*) SE1_CONVCOEF3_1_reg))
#define SE1_CONVCOEF3_0_inst_adr                                                      "0x0084"
#define SE1_CONVCOEF3_1_inst_adr                                                      "0x0085"
#define SE1_CONVCOEF3_0_inst                                                          0x0084
#define SE1_CONVCOEF3_1_inst                                                          0x0085
#define SE1_CONVCOEF3_m12_shift                                                       (13)
#define SE1_CONVCOEF3_m12_mask                                                        (0x03FFE000)
#define SE1_CONVCOEF3_m12(data)                                                       (0x03FFE000&((data)<<13))
#define SE1_CONVCOEF3_m12_src(data)                                                   ((0x03FFE000&(data))>>13)
#define SE1_CONVCOEF3_get_m12(data)                                                   ((0x03FFE000&(data))>>13)
#define SE1_CONVCOEF3_m11_shift                                                       (0)
#define SE1_CONVCOEF3_m11_mask                                                        (0x00001FFF)
#define SE1_CONVCOEF3_m11(data)                                                       (0x00001FFF&((data)<<0))
#define SE1_CONVCOEF3_m11_src(data)                                                   ((0x00001FFF&(data))>>0)
#define SE1_CONVCOEF3_get_m11(data)                                                   ((0x00001FFF&(data))>>0)


#define SE1_CONVCOEF4_0                                                               0x1803E220
#define SE1_CONVCOEF4_1                                                               0x1803E224
#define SE1_CONVCOEF4_0_reg_addr                                                      "0xB803E220"
#define SE1_CONVCOEF4_1_reg_addr                                                      "0xB803E224"
#define SE1_CONVCOEF4_0_reg                                                           0xB803E220
#define SE1_CONVCOEF4_1_reg                                                           0xB803E224
#define set_SE1_CONVCOEF4_0_reg(data)   (*((volatile unsigned int*) SE1_CONVCOEF4_0_reg)=data)
#define set_SE1_CONVCOEF4_1_reg(data)   (*((volatile unsigned int*) SE1_CONVCOEF4_1_reg)=data)
#define get_SE1_CONVCOEF4_0_reg   (*((volatile unsigned int*) SE1_CONVCOEF4_0_reg))
#define get_SE1_CONVCOEF4_1_reg   (*((volatile unsigned int*) SE1_CONVCOEF4_1_reg))
#define SE1_CONVCOEF4_0_inst_adr                                                      "0x0088"
#define SE1_CONVCOEF4_1_inst_adr                                                      "0x0089"
#define SE1_CONVCOEF4_0_inst                                                          0x0088
#define SE1_CONVCOEF4_1_inst                                                          0x0089
#define SE1_CONVCOEF4_m21_shift                                                       (13)
#define SE1_CONVCOEF4_m21_mask                                                        (0x03FFE000)
#define SE1_CONVCOEF4_m21(data)                                                       (0x03FFE000&((data)<<13))
#define SE1_CONVCOEF4_m21_src(data)                                                   ((0x03FFE000&(data))>>13)
#define SE1_CONVCOEF4_get_m21(data)                                                   ((0x03FFE000&(data))>>13)
#define SE1_CONVCOEF4_m20_shift                                                       (0)
#define SE1_CONVCOEF4_m20_mask                                                        (0x00001FFF)
#define SE1_CONVCOEF4_m20(data)                                                       (0x00001FFF&((data)<<0))
#define SE1_CONVCOEF4_m20_src(data)                                                   ((0x00001FFF&(data))>>0)
#define SE1_CONVCOEF4_get_m20(data)                                                   ((0x00001FFF&(data))>>0)


#define SE1_CONVCOEF5_0                                                               0x1803E230
#define SE1_CONVCOEF5_1                                                               0x1803E234
#define SE1_CONVCOEF5_0_reg_addr                                                      "0xB803E230"
#define SE1_CONVCOEF5_1_reg_addr                                                      "0xB803E234"
#define SE1_CONVCOEF5_0_reg                                                           0xB803E230
#define SE1_CONVCOEF5_1_reg                                                           0xB803E234
#define set_SE1_CONVCOEF5_0_reg(data)   (*((volatile unsigned int*) SE1_CONVCOEF5_0_reg)=data)
#define set_SE1_CONVCOEF5_1_reg(data)   (*((volatile unsigned int*) SE1_CONVCOEF5_1_reg)=data)
#define get_SE1_CONVCOEF5_0_reg   (*((volatile unsigned int*) SE1_CONVCOEF5_0_reg))
#define get_SE1_CONVCOEF5_1_reg   (*((volatile unsigned int*) SE1_CONVCOEF5_1_reg))
#define SE1_CONVCOEF5_0_inst_adr                                                      "0x008C"
#define SE1_CONVCOEF5_1_inst_adr                                                      "0x008D"
#define SE1_CONVCOEF5_0_inst                                                          0x008C
#define SE1_CONVCOEF5_1_inst                                                          0x008D
#define SE1_CONVCOEF5_m22_shift                                                       (0)
#define SE1_CONVCOEF5_m22_mask                                                        (0x00001FFF)
#define SE1_CONVCOEF5_m22(data)                                                       (0x00001FFF&((data)<<0))
#define SE1_CONVCOEF5_m22_src(data)                                                   ((0x00001FFF&(data))>>0)
#define SE1_CONVCOEF5_get_m22(data)                                                   ((0x00001FFF&(data))>>0)


#define SE1_CONVCOEF6_0                                                               0x1803E240
#define SE1_CONVCOEF6_1                                                               0x1803E244
#define SE1_CONVCOEF6_0_reg_addr                                                      "0xB803E240"
#define SE1_CONVCOEF6_1_reg_addr                                                      "0xB803E244"
#define SE1_CONVCOEF6_0_reg                                                           0xB803E240
#define SE1_CONVCOEF6_1_reg                                                           0xB803E244
#define set_SE1_CONVCOEF6_0_reg(data)   (*((volatile unsigned int*) SE1_CONVCOEF6_0_reg)=data)
#define set_SE1_CONVCOEF6_1_reg(data)   (*((volatile unsigned int*) SE1_CONVCOEF6_1_reg)=data)
#define get_SE1_CONVCOEF6_0_reg   (*((volatile unsigned int*) SE1_CONVCOEF6_0_reg))
#define get_SE1_CONVCOEF6_1_reg   (*((volatile unsigned int*) SE1_CONVCOEF6_1_reg))
#define SE1_CONVCOEF6_0_inst_adr                                                      "0x0090"
#define SE1_CONVCOEF6_1_inst_adr                                                      "0x0091"
#define SE1_CONVCOEF6_0_inst                                                          0x0090
#define SE1_CONVCOEF6_1_inst                                                          0x0091
#define SE1_CONVCOEF6_a2_shift                                                        (20)
#define SE1_CONVCOEF6_a2_mask                                                         (0x3FF00000)
#define SE1_CONVCOEF6_a2(data)                                                        (0x3FF00000&((data)<<20))
#define SE1_CONVCOEF6_a2_src(data)                                                    ((0x3FF00000&(data))>>20)
#define SE1_CONVCOEF6_get_a2(data)                                                    ((0x3FF00000&(data))>>20)
#define SE1_CONVCOEF6_a1_shift                                                        (10)
#define SE1_CONVCOEF6_a1_mask                                                         (0x000FFC00)
#define SE1_CONVCOEF6_a1(data)                                                        (0x000FFC00&((data)<<10))
#define SE1_CONVCOEF6_a1_src(data)                                                    ((0x000FFC00&(data))>>10)
#define SE1_CONVCOEF6_get_a1(data)                                                    ((0x000FFC00&(data))>>10)
#define SE1_CONVCOEF6_a0_shift                                                        (0)
#define SE1_CONVCOEF6_a0_mask                                                         (0x000003FF)
#define SE1_CONVCOEF6_a0(data)                                                        (0x000003FF&((data)<<0))
#define SE1_CONVCOEF6_a0_src(data)                                                    ((0x000003FF&(data))>>0)
#define SE1_CONVCOEF6_get_a0(data)                                                    ((0x000003FF&(data))>>0)


#define SE1_FCV_BITBLIT_COLOR_KEY_0                                                   0x1803E250
#define SE1_FCV_BITBLIT_COLOR_KEY_1                                                   0x1803E254
#define SE1_FCV_BITBLIT_COLOR_KEY_0_reg_addr                                          "0xB803E250"
#define SE1_FCV_BITBLIT_COLOR_KEY_1_reg_addr                                          "0xB803E254"
#define SE1_FCV_BITBLIT_COLOR_KEY_0_reg                                               0xB803E250
#define SE1_FCV_BITBLIT_COLOR_KEY_1_reg                                               0xB803E254
#define set_SE1_FCV_BITBLIT_COLOR_KEY_0_reg(data)   (*((volatile unsigned int*) SE1_FCV_BITBLIT_COLOR_KEY_0_reg)=data)
#define set_SE1_FCV_BITBLIT_COLOR_KEY_1_reg(data)   (*((volatile unsigned int*) SE1_FCV_BITBLIT_COLOR_KEY_1_reg)=data)
#define get_SE1_FCV_BITBLIT_COLOR_KEY_0_reg   (*((volatile unsigned int*) SE1_FCV_BITBLIT_COLOR_KEY_0_reg))
#define get_SE1_FCV_BITBLIT_COLOR_KEY_1_reg   (*((volatile unsigned int*) SE1_FCV_BITBLIT_COLOR_KEY_1_reg))
#define SE1_FCV_BITBLIT_COLOR_KEY_0_inst_adr                                          "0x0094"
#define SE1_FCV_BITBLIT_COLOR_KEY_1_inst_adr                                          "0x0095"
#define SE1_FCV_BITBLIT_COLOR_KEY_0_inst                                              0x0094
#define SE1_FCV_BITBLIT_COLOR_KEY_1_inst                                              0x0095
#define SE1_FCV_BITBLIT_COLOR_KEY_color_key_shift                                     (0)
#define SE1_FCV_BITBLIT_COLOR_KEY_color_key_mask                                      (0x00FFFFFF)
#define SE1_FCV_BITBLIT_COLOR_KEY_color_key(data)                                     (0x00FFFFFF&((data)<<0))
#define SE1_FCV_BITBLIT_COLOR_KEY_color_key_src(data)                                 ((0x00FFFFFF&(data))>>0)
#define SE1_FCV_BITBLIT_COLOR_KEY_get_color_key(data)                                 ((0x00FFFFFF&(data))>>0)


#define SE1_SRC_CLR_RED_0                                                             0x1803E260
#define SE1_SRC_CLR_RED_1                                                             0x1803E264
#define SE1_SRC_CLR_RED_0_reg_addr                                                    "0xB803E260"
#define SE1_SRC_CLR_RED_1_reg_addr                                                    "0xB803E264"
#define SE1_SRC_CLR_RED_0_reg                                                         0xB803E260
#define SE1_SRC_CLR_RED_1_reg                                                         0xB803E264
#define set_SE1_SRC_CLR_RED_0_reg(data)   (*((volatile unsigned int*) SE1_SRC_CLR_RED_0_reg)=data)
#define set_SE1_SRC_CLR_RED_1_reg(data)   (*((volatile unsigned int*) SE1_SRC_CLR_RED_1_reg)=data)
#define get_SE1_SRC_CLR_RED_0_reg   (*((volatile unsigned int*) SE1_SRC_CLR_RED_0_reg))
#define get_SE1_SRC_CLR_RED_1_reg   (*((volatile unsigned int*) SE1_SRC_CLR_RED_1_reg))
#define SE1_SRC_CLR_RED_0_inst_adr                                                    "0x0098"
#define SE1_SRC_CLR_RED_1_inst_adr                                                    "0x0099"
#define SE1_SRC_CLR_RED_0_inst                                                        0x0098
#define SE1_SRC_CLR_RED_1_inst                                                        0x0099
#define SE1_SRC_CLR_RED_src_clr_add_red_shift                                         (16)
#define SE1_SRC_CLR_RED_src_clr_add_red_mask                                          (0x01FF0000)
#define SE1_SRC_CLR_RED_src_clr_add_red(data)                                         (0x01FF0000&((data)<<16))
#define SE1_SRC_CLR_RED_src_clr_add_red_src(data)                                     ((0x01FF0000&(data))>>16)
#define SE1_SRC_CLR_RED_get_src_clr_add_red(data)                                     ((0x01FF0000&(data))>>16)
#define SE1_SRC_CLR_RED_src_clr_mul_red_shift                                         (0)
#define SE1_SRC_CLR_RED_src_clr_mul_red_mask                                          (0x000001FF)
#define SE1_SRC_CLR_RED_src_clr_mul_red(data)                                         (0x000001FF&((data)<<0))
#define SE1_SRC_CLR_RED_src_clr_mul_red_src(data)                                     ((0x000001FF&(data))>>0)
#define SE1_SRC_CLR_RED_get_src_clr_mul_red(data)                                     ((0x000001FF&(data))>>0)


#define SE1_SRC_CLR_GREEN_0                                                           0x1803E270
#define SE1_SRC_CLR_GREEN_1                                                           0x1803E274
#define SE1_SRC_CLR_GREEN_0_reg_addr                                                  "0xB803E270"
#define SE1_SRC_CLR_GREEN_1_reg_addr                                                  "0xB803E274"
#define SE1_SRC_CLR_GREEN_0_reg                                                       0xB803E270
#define SE1_SRC_CLR_GREEN_1_reg                                                       0xB803E274
#define set_SE1_SRC_CLR_GREEN_0_reg(data)   (*((volatile unsigned int*) SE1_SRC_CLR_GREEN_0_reg)=data)
#define set_SE1_SRC_CLR_GREEN_1_reg(data)   (*((volatile unsigned int*) SE1_SRC_CLR_GREEN_1_reg)=data)
#define get_SE1_SRC_CLR_GREEN_0_reg   (*((volatile unsigned int*) SE1_SRC_CLR_GREEN_0_reg))
#define get_SE1_SRC_CLR_GREEN_1_reg   (*((volatile unsigned int*) SE1_SRC_CLR_GREEN_1_reg))
#define SE1_SRC_CLR_GREEN_0_inst_adr                                                  "0x009C"
#define SE1_SRC_CLR_GREEN_1_inst_adr                                                  "0x009D"
#define SE1_SRC_CLR_GREEN_0_inst                                                      0x009C
#define SE1_SRC_CLR_GREEN_1_inst                                                      0x009D
#define SE1_SRC_CLR_GREEN_src_clr_add_green_shift                                     (16)
#define SE1_SRC_CLR_GREEN_src_clr_add_green_mask                                      (0x01FF0000)
#define SE1_SRC_CLR_GREEN_src_clr_add_green(data)                                     (0x01FF0000&((data)<<16))
#define SE1_SRC_CLR_GREEN_src_clr_add_green_src(data)                                 ((0x01FF0000&(data))>>16)
#define SE1_SRC_CLR_GREEN_get_src_clr_add_green(data)                                 ((0x01FF0000&(data))>>16)
#define SE1_SRC_CLR_GREEN_src_clr_mul_green_shift                                     (0)
#define SE1_SRC_CLR_GREEN_src_clr_mul_green_mask                                      (0x000001FF)
#define SE1_SRC_CLR_GREEN_src_clr_mul_green(data)                                     (0x000001FF&((data)<<0))
#define SE1_SRC_CLR_GREEN_src_clr_mul_green_src(data)                                 ((0x000001FF&(data))>>0)
#define SE1_SRC_CLR_GREEN_get_src_clr_mul_green(data)                                 ((0x000001FF&(data))>>0)


#define SE1_SRC_CLR_BLUE_0                                                            0x1803E280
#define SE1_SRC_CLR_BLUE_1                                                            0x1803E284
#define SE1_SRC_CLR_BLUE_0_reg_addr                                                   "0xB803E280"
#define SE1_SRC_CLR_BLUE_1_reg_addr                                                   "0xB803E284"
#define SE1_SRC_CLR_BLUE_0_reg                                                        0xB803E280
#define SE1_SRC_CLR_BLUE_1_reg                                                        0xB803E284
#define set_SE1_SRC_CLR_BLUE_0_reg(data)   (*((volatile unsigned int*) SE1_SRC_CLR_BLUE_0_reg)=data)
#define set_SE1_SRC_CLR_BLUE_1_reg(data)   (*((volatile unsigned int*) SE1_SRC_CLR_BLUE_1_reg)=data)
#define get_SE1_SRC_CLR_BLUE_0_reg   (*((volatile unsigned int*) SE1_SRC_CLR_BLUE_0_reg))
#define get_SE1_SRC_CLR_BLUE_1_reg   (*((volatile unsigned int*) SE1_SRC_CLR_BLUE_1_reg))
#define SE1_SRC_CLR_BLUE_0_inst_adr                                                   "0x00A0"
#define SE1_SRC_CLR_BLUE_1_inst_adr                                                   "0x00A1"
#define SE1_SRC_CLR_BLUE_0_inst                                                       0x00A0
#define SE1_SRC_CLR_BLUE_1_inst                                                       0x00A1
#define SE1_SRC_CLR_BLUE_src_clr_add_blue_shift                                       (16)
#define SE1_SRC_CLR_BLUE_src_clr_add_blue_mask                                        (0x01FF0000)
#define SE1_SRC_CLR_BLUE_src_clr_add_blue(data)                                       (0x01FF0000&((data)<<16))
#define SE1_SRC_CLR_BLUE_src_clr_add_blue_src(data)                                   ((0x01FF0000&(data))>>16)
#define SE1_SRC_CLR_BLUE_get_src_clr_add_blue(data)                                   ((0x01FF0000&(data))>>16)
#define SE1_SRC_CLR_BLUE_src_clr_mul_blue_shift                                       (0)
#define SE1_SRC_CLR_BLUE_src_clr_mul_blue_mask                                        (0x000001FF)
#define SE1_SRC_CLR_BLUE_src_clr_mul_blue(data)                                       (0x000001FF&((data)<<0))
#define SE1_SRC_CLR_BLUE_src_clr_mul_blue_src(data)                                   ((0x000001FF&(data))>>0)
#define SE1_SRC_CLR_BLUE_get_src_clr_mul_blue(data)                                   ((0x000001FF&(data))>>0)


#define SE1_SRC_CLR_ALPHA_0                                                           0x1803E290
#define SE1_SRC_CLR_ALPHA_1                                                           0x1803E294
#define SE1_SRC_CLR_ALPHA_0_reg_addr                                                  "0xB803E290"
#define SE1_SRC_CLR_ALPHA_1_reg_addr                                                  "0xB803E294"
#define SE1_SRC_CLR_ALPHA_0_reg                                                       0xB803E290
#define SE1_SRC_CLR_ALPHA_1_reg                                                       0xB803E294
#define set_SE1_SRC_CLR_ALPHA_0_reg(data)   (*((volatile unsigned int*) SE1_SRC_CLR_ALPHA_0_reg)=data)
#define set_SE1_SRC_CLR_ALPHA_1_reg(data)   (*((volatile unsigned int*) SE1_SRC_CLR_ALPHA_1_reg)=data)
#define get_SE1_SRC_CLR_ALPHA_0_reg   (*((volatile unsigned int*) SE1_SRC_CLR_ALPHA_0_reg))
#define get_SE1_SRC_CLR_ALPHA_1_reg   (*((volatile unsigned int*) SE1_SRC_CLR_ALPHA_1_reg))
#define SE1_SRC_CLR_ALPHA_0_inst_adr                                                  "0x00A4"
#define SE1_SRC_CLR_ALPHA_1_inst_adr                                                  "0x00A5"
#define SE1_SRC_CLR_ALPHA_0_inst                                                      0x00A4
#define SE1_SRC_CLR_ALPHA_1_inst                                                      0x00A5
#define SE1_SRC_CLR_ALPHA_src_clr_add_alpha_shift                                     (16)
#define SE1_SRC_CLR_ALPHA_src_clr_add_alpha_mask                                      (0x01FF0000)
#define SE1_SRC_CLR_ALPHA_src_clr_add_alpha(data)                                     (0x01FF0000&((data)<<16))
#define SE1_SRC_CLR_ALPHA_src_clr_add_alpha_src(data)                                 ((0x01FF0000&(data))>>16)
#define SE1_SRC_CLR_ALPHA_get_src_clr_add_alpha(data)                                 ((0x01FF0000&(data))>>16)
#define SE1_SRC_CLR_ALPHA_src_clr_mul_alpha_shift                                     (0)
#define SE1_SRC_CLR_ALPHA_src_clr_mul_alpha_mask                                      (0x000001FF)
#define SE1_SRC_CLR_ALPHA_src_clr_mul_alpha(data)                                     (0x000001FF&((data)<<0))
#define SE1_SRC_CLR_ALPHA_src_clr_mul_alpha_src(data)                                 ((0x000001FF&(data))>>0)
#define SE1_SRC_CLR_ALPHA_get_src_clr_mul_alpha(data)                                 ((0x000001FF&(data))>>0)


#define SE1_SYNC_VO_MARGIN_0                                                          0x1803E2A0
#define SE1_SYNC_VO_MARGIN_1                                                          0x1803E2A4
#define SE1_SYNC_VO_MARGIN_0_reg_addr                                                 "0xB803E2A0"
#define SE1_SYNC_VO_MARGIN_1_reg_addr                                                 "0xB803E2A4"
#define SE1_SYNC_VO_MARGIN_0_reg                                                      0xB803E2A0
#define SE1_SYNC_VO_MARGIN_1_reg                                                      0xB803E2A4
#define set_SE1_SYNC_VO_MARGIN_0_reg(data)   (*((volatile unsigned int*) SE1_SYNC_VO_MARGIN_0_reg)=data)
#define set_SE1_SYNC_VO_MARGIN_1_reg(data)   (*((volatile unsigned int*) SE1_SYNC_VO_MARGIN_1_reg)=data)
#define get_SE1_SYNC_VO_MARGIN_0_reg   (*((volatile unsigned int*) SE1_SYNC_VO_MARGIN_0_reg))
#define get_SE1_SYNC_VO_MARGIN_1_reg   (*((volatile unsigned int*) SE1_SYNC_VO_MARGIN_1_reg))
#define SE1_SYNC_VO_MARGIN_0_inst_adr                                                 "0x00A8"
#define SE1_SYNC_VO_MARGIN_1_inst_adr                                                 "0x00A9"
#define SE1_SYNC_VO_MARGIN_0_inst                                                     0x00A8
#define SE1_SYNC_VO_MARGIN_1_inst                                                     0x00A9
#define SE1_SYNC_VO_MARGIN_auto_dir_en_shift                                          (31)
#define SE1_SYNC_VO_MARGIN_auto_dir_en_mask                                           (0x80000000)
#define SE1_SYNC_VO_MARGIN_auto_dir_en(data)                                          (0x80000000&((data)<<31))
#define SE1_SYNC_VO_MARGIN_auto_dir_en_src(data)                                      ((0x80000000&(data))>>31)
#define SE1_SYNC_VO_MARGIN_get_auto_dir_en(data)                                      ((0x80000000&(data))>>31)
#define SE1_SYNC_VO_MARGIN_vo_plane_shift                                             (30)
#define SE1_SYNC_VO_MARGIN_vo_plane_mask                                              (0x40000000)
#define SE1_SYNC_VO_MARGIN_vo_plane(data)                                             (0x40000000&((data)<<30))
#define SE1_SYNC_VO_MARGIN_vo_plane_src(data)                                         ((0x40000000&(data))>>30)
#define SE1_SYNC_VO_MARGIN_get_vo_plane(data)                                         ((0x40000000&(data))>>30)
#define SE1_SYNC_VO_MARGIN_before_vo_cur_shift                                        (29)
#define SE1_SYNC_VO_MARGIN_before_vo_cur_mask                                         (0x20000000)
#define SE1_SYNC_VO_MARGIN_before_vo_cur(data)                                        (0x20000000&((data)<<29))
#define SE1_SYNC_VO_MARGIN_before_vo_cur_src(data)                                    ((0x20000000&(data))>>29)
#define SE1_SYNC_VO_MARGIN_get_before_vo_cur(data)                                    ((0x20000000&(data))>>29)
#define SE1_SYNC_VO_MARGIN_after_vo_cur_shift                                         (28)
#define SE1_SYNC_VO_MARGIN_after_vo_cur_mask                                          (0x10000000)
#define SE1_SYNC_VO_MARGIN_after_vo_cur(data)                                         (0x10000000&((data)<<28))
#define SE1_SYNC_VO_MARGIN_after_vo_cur_src(data)                                     ((0x10000000&(data))>>28)
#define SE1_SYNC_VO_MARGIN_get_after_vo_cur(data)                                     ((0x10000000&(data))>>28)
#define SE1_SYNC_VO_MARGIN_vbi_shift                                                  (27)
#define SE1_SYNC_VO_MARGIN_vbi_mask                                                   (0x08000000)
#define SE1_SYNC_VO_MARGIN_vbi(data)                                                  (0x08000000&((data)<<27))
#define SE1_SYNC_VO_MARGIN_vbi_src(data)                                              ((0x08000000&(data))>>27)
#define SE1_SYNC_VO_MARGIN_get_vbi(data)                                              ((0x08000000&(data))>>27)
#define SE1_SYNC_VO_MARGIN_margin_VOtoSE1_shift                                        (0)
#define SE1_SYNC_VO_MARGIN_margin_VOtoSE1_mask                                         (0x00000FFF)
#define SE1_SYNC_VO_MARGIN_margin_VOtoSE(data)                                        (0x00000FFF&((data)<<0))
#define SE1_SYNC_VO_MARGIN_margin_VOtoSE1_src(data)                                    ((0x00000FFF&(data))>>0)
#define SE1_SYNC_VO_MARGIN_get_margin_VOtoSE(data)                                    ((0x00000FFF&(data))>>0)


#define SE1_SYNC_VO_LOCATION_0                                                        0x1803E2B0
#define SE1_SYNC_VO_LOCATION_1                                                        0x1803E2B4
#define SE1_SYNC_VO_LOCATION_0_reg_addr                                               "0xB803E2B0"
#define SE1_SYNC_VO_LOCATION_1_reg_addr                                               "0xB803E2B4"
#define SE1_SYNC_VO_LOCATION_0_reg                                                    0xB803E2B0
#define SE1_SYNC_VO_LOCATION_1_reg                                                    0xB803E2B4
#define set_SE1_SYNC_VO_LOCATION_0_reg(data)   (*((volatile unsigned int*) SE1_SYNC_VO_LOCATION_0_reg)=data)
#define set_SE1_SYNC_VO_LOCATION_1_reg(data)   (*((volatile unsigned int*) SE1_SYNC_VO_LOCATION_1_reg)=data)
#define get_SE1_SYNC_VO_LOCATION_0_reg   (*((volatile unsigned int*) SE1_SYNC_VO_LOCATION_0_reg))
#define get_SE1_SYNC_VO_LOCATION_1_reg   (*((volatile unsigned int*) SE1_SYNC_VO_LOCATION_1_reg))
#define SE1_SYNC_VO_LOCATION_0_inst_adr                                               "0x00AC"
#define SE1_SYNC_VO_LOCATION_1_inst_adr                                               "0x00AD"
#define SE1_SYNC_VO_LOCATION_0_inst                                                   0x00AC
#define SE1_SYNC_VO_LOCATION_1_inst                                                   0x00AD
#define SE1_SYNC_VO_LOCATION_VO_current_y_shift                                       (0)
#define SE1_SYNC_VO_LOCATION_VO_current_y_mask                                        (0x00003FFF)
#define SE1_SYNC_VO_LOCATION_VO_current_y(data)                                       (0x00003FFF&((data)<<0))
#define SE1_SYNC_VO_LOCATION_VO_current_y_src(data)                                   ((0x00003FFF&(data))>>0)
#define SE1_SYNC_VO_LOCATION_get_VO_current_y(data)                                   ((0x00003FFF&(data))>>0)


#define SE1_SYNC_VO_TOTAL_Y_0                                                         0x1800EB60
#define SE1_SYNC_VO_TOTAL_Y_1                                                         0x1800EB64
#define SE1_SYNC_VO_TOTAL_Y_0_reg_addr                                                "0xB800EB60"
#define SE1_SYNC_VO_TOTAL_Y_1_reg_addr                                                "0xB800EB64"
#define SE1_SYNC_VO_TOTAL_Y_0_reg                                                     0xB800EB60
#define SE1_SYNC_VO_TOTAL_Y_1_reg                                                     0xB800EB64
#define set_SE1_SYNC_VO_TOTAL_Y_0_reg(data)   (*((volatile unsigned int*) SE1_SYNC_VO_TOTAL_Y_0_reg)=data)
#define set_SE1_SYNC_VO_TOTAL_Y_1_reg(data)   (*((volatile unsigned int*) SE1_SYNC_VO_TOTAL_Y_1_reg)=data)
#define get_SE1_SYNC_VO_TOTAL_Y_0_reg   (*((volatile unsigned int*) SE1_SYNC_VO_TOTAL_Y_0_reg))
#define get_SE1_SYNC_VO_TOTAL_Y_1_reg   (*((volatile unsigned int*) SE1_SYNC_VO_TOTAL_Y_1_reg))
#define SE1_SYNC_VO_TOTAL_Y_0_inst_adr                                                "0x00D8"
#define SE1_SYNC_VO_TOTAL_Y_1_inst_adr                                                "0x00D9"
#define SE1_SYNC_VO_TOTAL_Y_0_inst                                                    0x00D8
#define SE1_SYNC_VO_TOTAL_Y_1_inst                                                    0x00D9
#define SE1_SYNC_VO_TOTAL_Y_gdma_direction_shift                                      (16)
#define SE1_SYNC_VO_TOTAL_Y_gdma_direction_mask                                       (0x00010000)
#define SE1_SYNC_VO_TOTAL_Y_gdma_direction(data)                                      (0x00010000&((data)<<16))
#define SE1_SYNC_VO_TOTAL_Y_gdma_direction_src(data)                                  ((0x00010000&(data))>>16)
#define SE1_SYNC_VO_TOTAL_Y_get_gdma_direction(data)                                  ((0x00010000&(data))>>16)
#define SE1_SYNC_VO_TOTAL_Y_total_y_shift                                             (0)
#define SE1_SYNC_VO_TOTAL_Y_total_y_mask                                              (0x00001FFF)
#define SE1_SYNC_VO_TOTAL_Y_total_y(data)                                             (0x00001FFF&((data)<<0))
#define SE1_SYNC_VO_TOTAL_Y_total_y_src(data)                                         ((0x00001FFF&(data))>>0)
#define SE1_SYNC_VO_TOTAL_Y_get_total_y(data)                                         ((0x00001FFF&(data))>>0)


#define SE1_FB_COLORALPHA_0                                                           0x1803EB50
#define SE1_FB_COLORALPHA_1                                                           0x1803EB54
#define SE1_FB_COLORALPHA_0_reg_addr                                                  "0xB803EB50"
#define SE1_FB_COLORALPHA_1_reg_addr                                                  "0xB803EB54"
#define SE1_FB_COLORALPHA_0_reg                                                       0xB803EB50
#define SE1_FB_COLORALPHA_1_reg                                                       0xB803EB54
#define set_SE1_FB_COLORALPHA_0_reg(data)   (*((volatile unsigned int*) SE1_FB_COLORALPHA_0_reg)=data)
#define set_SE1_FB_COLORALPHA_1_reg(data)   (*((volatile unsigned int*) SE1_FB_COLORALPHA_1_reg)=data)
#define get_SE1_FB_COLORALPHA_0_reg   (*((volatile unsigned int*) SE1_FB_COLORALPHA_0_reg))
#define get_SE1_FB_COLORALPHA_1_reg   (*((volatile unsigned int*) SE1_FB_COLORALPHA_1_reg))
#define SE1_FB_COLORALPHA_0_inst_adr                                                  "0x00D4"
#define SE1_FB_COLORALPHA_1_inst_adr                                                  "0x00D5"
#define SE1_FB_COLORALPHA_0_inst                                                      0x00D4
#define SE1_FB_COLORALPHA_1_inst                                                      0x00D5
#define SE1_FB_COLORALPHA_color_alpha_shift                                           (0)
#define SE1_FB_COLORALPHA_color_alpha_mask                                            (0x000000FF)
#define SE1_FB_COLORALPHA_color_alpha(data)                                           (0x000000FF&((data)<<0))
#define SE1_FB_COLORALPHA_color_alpha_src(data)                                       ((0x000000FF&(data))>>0)
#define SE1_FB_COLORALPHA_get_color_alpha(data)                                       ((0x000000FF&(data))>>0)


#define SE1_STRETCH_0                                                                 0x1803E2C0
#define SE1_STRETCH_1                                                                 0x1803E2C4
#define SE1_STRETCH_0_reg_addr                                                        "0xB803E2C0"
#define SE1_STRETCH_1_reg_addr                                                        "0xB803E2C4"
#define SE1_STRETCH_0_reg                                                             0xB803E2C0
#define SE1_STRETCH_1_reg                                                             0xB803E2C4
#define set_SE1_STRETCH_0_reg(data)   (*((volatile unsigned int*) SE1_STRETCH_0_reg)=data)
#define set_SE1_STRETCH_1_reg(data)   (*((volatile unsigned int*) SE1_STRETCH_1_reg)=data)
#define get_SE1_STRETCH_0_reg   (*((volatile unsigned int*) SE1_STRETCH_0_reg))
#define get_SE1_STRETCH_1_reg   (*((volatile unsigned int*) SE1_STRETCH_1_reg))
#define SE1_STRETCH_0_inst_adr                                                        "0x00B0"
#define SE1_STRETCH_1_inst_adr                                                        "0x00B1"
#define SE1_STRETCH_0_inst                                                            0x00B0
#define SE1_STRETCH_1_inst                                                            0x00B1
#define SE1_STRETCH_repl_alpha_shift                                                  (7)
#define SE1_STRETCH_repl_alpha_mask                                                   (0x00000080)
#define SE1_STRETCH_repl_alpha(data)                                                  (0x00000080&((data)<<7))
#define SE1_STRETCH_repl_alpha_src(data)                                              ((0x00000080&(data))>>7)
#define SE1_STRETCH_get_repl_alpha(data)                                              ((0x00000080&(data))>>7)
#define SE1_STRETCH_repl_color_shift                                                  (6)
#define SE1_STRETCH_repl_color_mask                                                   (0x00000040)
#define SE1_STRETCH_repl_color(data)                                                  (0x00000040&((data)<<6))
#define SE1_STRETCH_repl_color_src(data)                                              ((0x00000040&(data))>>6)
#define SE1_STRETCH_get_repl_color(data)                                              ((0x00000040&(data))>>6)
#define SE1_STRETCH_ref_alpha_shift                                                   (5)
#define SE1_STRETCH_ref_alpha_mask                                                    (0x00000020)
#define SE1_STRETCH_ref_alpha(data)                                                   (0x00000020&((data)<<5))
#define SE1_STRETCH_ref_alpha_src(data)                                               ((0x00000020&(data))>>5)
#define SE1_STRETCH_get_ref_alpha(data)                                               ((0x00000020&(data))>>5)
#define SE1_STRETCH_htype_shift                                                       (3)
#define SE1_STRETCH_htype_mask                                                        (0x00000018)
#define SE1_STRETCH_htype(data)                                                       (0x00000018&((data)<<3))
#define SE1_STRETCH_htype_src(data)                                                   ((0x00000018&(data))>>3)
#define SE1_STRETCH_get_htype(data)                                                   ((0x00000018&(data))>>3)
#define SE1_STRETCH_vtype_shift                                                       (2)
#define SE1_STRETCH_vtype_mask                                                        (0x00000004)
#define SE1_STRETCH_vtype(data)                                                       (0x00000004&((data)<<2))
#define SE1_STRETCH_vtype_src(data)                                                   ((0x00000004&(data))>>2)
#define SE1_STRETCH_get_vtype(data)                                                   ((0x00000004&(data))>>2)
#define SE1_STRETCH_hodd_shift                                                        (1)
#define SE1_STRETCH_hodd_mask                                                         (0x00000002)
#define SE1_STRETCH_hodd(data)                                                        (0x00000002&((data)<<1))
#define SE1_STRETCH_hodd_src(data)                                                    ((0x00000002&(data))>>1)
#define SE1_STRETCH_get_hodd(data)                                                    ((0x00000002&(data))>>1)
#define SE1_STRETCH_vodd_shift                                                        (0)
#define SE1_STRETCH_vodd_mask                                                         (0x00000001)
#define SE1_STRETCH_vodd(data)                                                        (0x00000001&((data)<<0))
#define SE1_STRETCH_vodd_src(data)                                                    ((0x00000001&(data))>>0)
#define SE1_STRETCH_get_vodd(data)                                                    ((0x00000001&(data))>>0)


#define SE1_HDHS_0                                                                    0x1803E2D0
#define SE1_HDHS_1                                                                    0x1803E2D4
#define SE1_HDHS_0_reg_addr                                                           "0xB803E2D0"
#define SE1_HDHS_1_reg_addr                                                           "0xB803E2D4"
#define SE1_HDHS_0_reg                                                                0xB803E2D0
#define SE1_HDHS_1_reg                                                                0xB803E2D4
#define set_SE1_HDHS_0_reg(data)   (*((volatile unsigned int*) SE1_HDHS_0_reg)=data)
#define set_SE1_HDHS_1_reg(data)   (*((volatile unsigned int*) SE1_HDHS_1_reg)=data)
#define get_SE1_HDHS_0_reg   (*((volatile unsigned int*) SE1_HDHS_0_reg))
#define get_SE1_HDHS_1_reg   (*((volatile unsigned int*) SE1_HDHS_1_reg))
#define SE1_HDHS_0_inst_adr                                                           "0x00B4"
#define SE1_HDHS_1_inst_adr                                                           "0x00B5"
#define SE1_HDHS_0_inst                                                               0x00B4
#define SE1_HDHS_1_inst                                                               0x00B5
#define SE1_HDHS_H_scaling_iniph_shift                                                (18)
#define SE1_HDHS_H_scaling_iniph_mask                                                 (0x003C0000)
#define SE1_HDHS_H_scaling_iniph(data)                                                (0x003C0000&((data)<<18))
#define SE1_HDHS_H_scaling_iniph_src(data)                                            ((0x003C0000&(data))>>18)
#define SE1_HDHS_get_H_scaling_iniph(data)                                            ((0x003C0000&(data))>>18)
#define SE1_HDHS_H_scaling_dph_msb_shift                                              (14)
#define SE1_HDHS_H_scaling_dph_msb_mask                                               (0x0003C000)
#define SE1_HDHS_H_scaling_dph_msb(data)                                              (0x0003C000&((data)<<14))
#define SE1_HDHS_H_scaling_dph_msb_src(data)                                          ((0x0003C000&(data))>>14)
#define SE1_HDHS_get_H_scaling_dph_msb(data)                                          ((0x0003C000&(data))>>14)
#define SE1_HDHS_H_scaling_dph_lsb_shift                                              (0)
#define SE1_HDHS_H_scaling_dph_lsb_mask                                               (0x00003FFF)
#define SE1_HDHS_H_scaling_dph_lsb(data)                                              (0x00003FFF&((data)<<0))
#define SE1_HDHS_H_scaling_dph_lsb_src(data)                                          ((0x00003FFF&(data))>>0)
#define SE1_HDHS_get_H_scaling_dph_lsb(data)                                          ((0x00003FFF&(data))>>0)


#define SE1_VDHS_0                                                                    0x1803E2E0
#define SE1_VDHS_1                                                                    0x1803E2E4
#define SE1_VDHS_0_reg_addr                                                           "0xB803E2E0"
#define SE1_VDHS_1_reg_addr                                                           "0xB803E2E4"
#define SE1_VDHS_0_reg                                                                0xB803E2E0
#define SE1_VDHS_1_reg                                                                0xB803E2E4
#define set_SE1_VDHS_0_reg(data)   (*((volatile unsigned int*) SE1_VDHS_0_reg)=data)
#define set_SE1_VDHS_1_reg(data)   (*((volatile unsigned int*) SE1_VDHS_1_reg)=data)
#define get_SE1_VDHS_0_reg   (*((volatile unsigned int*) SE1_VDHS_0_reg))
#define get_SE1_VDHS_1_reg   (*((volatile unsigned int*) SE1_VDHS_1_reg))
#define SE1_VDHS_0_inst_adr                                                           "0x00B8"
#define SE1_VDHS_1_inst_adr                                                           "0x00B9"
#define SE1_VDHS_0_inst                                                               0x00B8
#define SE1_VDHS_1_inst                                                               0x00B9
#define SE1_VDHS_V_scaling_iniph_shift                                                (18)
#define SE1_VDHS_V_scaling_iniph_mask                                                 (0x003C0000)
#define SE1_VDHS_V_scaling_iniph(data)                                                (0x003C0000&((data)<<18))
#define SE1_VDHS_V_scaling_iniph_src(data)                                            ((0x003C0000&(data))>>18)
#define SE1_VDHS_get_V_scaling_iniph(data)                                            ((0x003C0000&(data))>>18)
#define SE1_VDHS_V_scaling_dph_msb_shift                                              (14)
#define SE1_VDHS_V_scaling_dph_msb_mask                                               (0x0003C000)
#define SE1_VDHS_V_scaling_dph_msb(data)                                              (0x0003C000&((data)<<14))
#define SE1_VDHS_V_scaling_dph_msb_src(data)                                          ((0x0003C000&(data))>>14)
#define SE1_VDHS_get_V_scaling_dph_msb(data)                                          ((0x0003C000&(data))>>14)
#define SE1_VDHS_V_scaling_dph_lsb_shift                                              (0)
#define SE1_VDHS_V_scaling_dph_lsb_mask                                               (0x00003FFF)
#define SE1_VDHS_V_scaling_dph_lsb(data)                                              (0x00003FFF&((data)<<0))
#define SE1_VDHS_V_scaling_dph_lsb_src(data)                                          ((0x00003FFF&(data))>>0)
#define SE1_VDHS_get_V_scaling_dph_lsb(data)                                          ((0x00003FFF&(data))>>0)


#define SE1_HCOEF1_0                                                                  0x1803E300
#define SE1_HCOEF1_1                                                                  0x1803E304
#define SE1_HCOEF1_2                                                                  0x1803E308
#define SE1_HCOEF1_3                                                                  0x1803E30C
#define SE1_HCOEF1_4                                                                  0x1803E310
#define SE1_HCOEF1_5                                                                  0x1803E314
#define SE1_HCOEF1_6                                                                  0x1803E318
#define SE1_HCOEF1_7                                                                  0x1803E31C
#define SE1_HCOEF1_8                                                                  0x1803E320
#define SE1_HCOEF1_9                                                                  0x1803E324
#define SE1_HCOEF1_10                                                                  0x1803E328
#define SE1_HCOEF1_11                                                                  0x1803E32C
#define SE1_HCOEF1_12                                                                  0x1803E330
#define SE1_HCOEF1_13                                                                  0x1803E334
#define SE1_HCOEF1_14                                                                  0x1803E338
#define SE1_HCOEF1_15                                                                  0x1803E33C
#define SE1_HCOEF1_16                                                                  0x1803E340
#define SE1_HCOEF1_17                                                                  0x1803E344
#define SE1_HCOEF1_18                                                                  0x1803E348
#define SE1_HCOEF1_19                                                                  0x1803E34C
#define SE1_HCOEF1_20                                                                  0x1803E350
#define SE1_HCOEF1_21                                                                  0x1803E354
#define SE1_HCOEF1_22                                                                  0x1803E358
#define SE1_HCOEF1_23                                                                  0x1803E35C
#define SE1_HCOEF1_24                                                                  0x1803E360
#define SE1_HCOEF1_25                                                                  0x1803E364
#define SE1_HCOEF1_26                                                                  0x1803E368
#define SE1_HCOEF1_27                                                                  0x1803E36C
#define SE1_HCOEF1_28                                                                  0x1803E370
#define SE1_HCOEF1_29                                                                  0x1803E374
#define SE1_HCOEF1_30                                                                  0x1803E378
#define SE1_HCOEF1_31                                                                  0x1803E37C
#define SE1_HCOEF1_0_reg_addr                                                         "0xB803E300"
#define SE1_HCOEF1_1_reg_addr                                                         "0xB803E304"
#define SE1_HCOEF1_2_reg_addr                                                         "0xB803E308"
#define SE1_HCOEF1_3_reg_addr                                                         "0xB803E30C"
#define SE1_HCOEF1_4_reg_addr                                                         "0xB803E310"
#define SE1_HCOEF1_5_reg_addr                                                         "0xB803E314"
#define SE1_HCOEF1_6_reg_addr                                                         "0xB803E318"
#define SE1_HCOEF1_7_reg_addr                                                         "0xB803E31C"
#define SE1_HCOEF1_8_reg_addr                                                         "0xB803E320"
#define SE1_HCOEF1_9_reg_addr                                                         "0xB803E324"
#define SE1_HCOEF1_10_reg_addr                                                         "0xB803E328"
#define SE1_HCOEF1_11_reg_addr                                                         "0xB803E32C"
#define SE1_HCOEF1_12_reg_addr                                                         "0xB803E330"
#define SE1_HCOEF1_13_reg_addr                                                         "0xB803E334"
#define SE1_HCOEF1_14_reg_addr                                                         "0xB803E338"
#define SE1_HCOEF1_15_reg_addr                                                         "0xB803E33C"
#define SE1_HCOEF1_16_reg_addr                                                         "0xB803E340"
#define SE1_HCOEF1_17_reg_addr                                                         "0xB803E344"
#define SE1_HCOEF1_18_reg_addr                                                         "0xB803E348"
#define SE1_HCOEF1_19_reg_addr                                                         "0xB803E34C"
#define SE1_HCOEF1_20_reg_addr                                                         "0xB803E350"
#define SE1_HCOEF1_21_reg_addr                                                         "0xB803E354"
#define SE1_HCOEF1_22_reg_addr                                                         "0xB803E358"
#define SE1_HCOEF1_23_reg_addr                                                         "0xB803E35C"
#define SE1_HCOEF1_24_reg_addr                                                         "0xB803E360"
#define SE1_HCOEF1_25_reg_addr                                                         "0xB803E364"
#define SE1_HCOEF1_26_reg_addr                                                         "0xB803E368"
#define SE1_HCOEF1_27_reg_addr                                                         "0xB803E36C"
#define SE1_HCOEF1_28_reg_addr                                                         "0xB803E370"
#define SE1_HCOEF1_29_reg_addr                                                         "0xB803E374"
#define SE1_HCOEF1_30_reg_addr                                                         "0xB803E378"
#define SE1_HCOEF1_31_reg_addr                                                         "0xB803E37C"
#define SE1_HCOEF1_0_reg                                                              0xB803E300
#define SE1_HCOEF1_1_reg                                                              0xB803E304
#define SE1_HCOEF1_2_reg                                                              0xB803E308
#define SE1_HCOEF1_3_reg                                                              0xB803E30C
#define SE1_HCOEF1_4_reg                                                              0xB803E310
#define SE1_HCOEF1_5_reg                                                              0xB803E314
#define SE1_HCOEF1_6_reg                                                              0xB803E318
#define SE1_HCOEF1_7_reg                                                              0xB803E31C
#define SE1_HCOEF1_8_reg                                                              0xB803E320
#define SE1_HCOEF1_9_reg                                                              0xB803E324
#define SE1_HCOEF1_10_reg                                                              0xB803E328
#define SE1_HCOEF1_11_reg                                                              0xB803E32C
#define SE1_HCOEF1_12_reg                                                              0xB803E330
#define SE1_HCOEF1_13_reg                                                              0xB803E334
#define SE1_HCOEF1_14_reg                                                              0xB803E338
#define SE1_HCOEF1_15_reg                                                              0xB803E33C
#define SE1_HCOEF1_16_reg                                                              0xB803E340
#define SE1_HCOEF1_17_reg                                                              0xB803E344
#define SE1_HCOEF1_18_reg                                                              0xB803E348
#define SE1_HCOEF1_19_reg                                                              0xB803E34C
#define SE1_HCOEF1_20_reg                                                              0xB803E350
#define SE1_HCOEF1_21_reg                                                              0xB803E354
#define SE1_HCOEF1_22_reg                                                              0xB803E358
#define SE1_HCOEF1_23_reg                                                              0xB803E35C
#define SE1_HCOEF1_24_reg                                                              0xB803E360
#define SE1_HCOEF1_25_reg                                                              0xB803E364
#define SE1_HCOEF1_26_reg                                                              0xB803E368
#define SE1_HCOEF1_27_reg                                                              0xB803E36C
#define SE1_HCOEF1_28_reg                                                              0xB803E370
#define SE1_HCOEF1_29_reg                                                              0xB803E374
#define SE1_HCOEF1_30_reg                                                              0xB803E378
#define SE1_HCOEF1_31_reg                                                              0xB803E37C
#define set_SE1_HCOEF1_0_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_0_reg)=data)
#define set_SE1_HCOEF1_1_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_1_reg)=data)
#define set_SE1_HCOEF1_2_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_2_reg)=data)
#define set_SE1_HCOEF1_3_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_3_reg)=data)
#define set_SE1_HCOEF1_4_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_4_reg)=data)
#define set_SE1_HCOEF1_5_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_5_reg)=data)
#define set_SE1_HCOEF1_6_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_6_reg)=data)
#define set_SE1_HCOEF1_7_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_7_reg)=data)
#define set_SE1_HCOEF1_8_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_8_reg)=data)
#define set_SE1_HCOEF1_9_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_9_reg)=data)
#define set_SE1_HCOEF1_10_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_10_reg)=data)
#define set_SE1_HCOEF1_11_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_11_reg)=data)
#define set_SE1_HCOEF1_12_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_12_reg)=data)
#define set_SE1_HCOEF1_13_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_13_reg)=data)
#define set_SE1_HCOEF1_14_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_14_reg)=data)
#define set_SE1_HCOEF1_15_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_15_reg)=data)
#define set_SE1_HCOEF1_16_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_16_reg)=data)
#define set_SE1_HCOEF1_17_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_17_reg)=data)
#define set_SE1_HCOEF1_18_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_18_reg)=data)
#define set_SE1_HCOEF1_19_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_19_reg)=data)
#define set_SE1_HCOEF1_20_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_20_reg)=data)
#define set_SE1_HCOEF1_21_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_21_reg)=data)
#define set_SE1_HCOEF1_22_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_22_reg)=data)
#define set_SE1_HCOEF1_23_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_23_reg)=data)
#define set_SE1_HCOEF1_24_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_24_reg)=data)
#define set_SE1_HCOEF1_25_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_25_reg)=data)
#define set_SE1_HCOEF1_26_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_26_reg)=data)
#define set_SE1_HCOEF1_27_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_27_reg)=data)
#define set_SE1_HCOEF1_28_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_28_reg)=data)
#define set_SE1_HCOEF1_29_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_29_reg)=data)
#define set_SE1_HCOEF1_30_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_30_reg)=data)
#define set_SE1_HCOEF1_31_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_31_reg)=data)
#define get_SE1_HCOEF1_0_reg   (*((volatile unsigned int*) SE1_HCOEF1_0_reg))
#define get_SE1_HCOEF1_1_reg   (*((volatile unsigned int*) SE1_HCOEF1_1_reg))
#define get_SE1_HCOEF1_2_reg   (*((volatile unsigned int*) SE1_HCOEF1_2_reg))
#define get_SE1_HCOEF1_3_reg   (*((volatile unsigned int*) SE1_HCOEF1_3_reg))
#define get_SE1_HCOEF1_4_reg   (*((volatile unsigned int*) SE1_HCOEF1_4_reg))
#define get_SE1_HCOEF1_5_reg   (*((volatile unsigned int*) SE1_HCOEF1_5_reg))
#define get_SE1_HCOEF1_6_reg   (*((volatile unsigned int*) SE1_HCOEF1_6_reg))
#define get_SE1_HCOEF1_7_reg   (*((volatile unsigned int*) SE1_HCOEF1_7_reg))
#define get_SE1_HCOEF1_8_reg   (*((volatile unsigned int*) SE1_HCOEF1_8_reg))
#define get_SE1_HCOEF1_9_reg   (*((volatile unsigned int*) SE1_HCOEF1_9_reg))
#define get_SE1_HCOEF1_10_reg   (*((volatile unsigned int*) SE1_HCOEF1_10_reg))
#define get_SE1_HCOEF1_11_reg   (*((volatile unsigned int*) SE1_HCOEF1_11_reg))
#define get_SE1_HCOEF1_12_reg   (*((volatile unsigned int*) SE1_HCOEF1_12_reg))
#define get_SE1_HCOEF1_13_reg   (*((volatile unsigned int*) SE1_HCOEF1_13_reg))
#define get_SE1_HCOEF1_14_reg   (*((volatile unsigned int*) SE1_HCOEF1_14_reg))
#define get_SE1_HCOEF1_15_reg   (*((volatile unsigned int*) SE1_HCOEF1_15_reg))
#define get_SE1_HCOEF1_16_reg   (*((volatile unsigned int*) SE1_HCOEF1_16_reg))
#define get_SE1_HCOEF1_17_reg   (*((volatile unsigned int*) SE1_HCOEF1_17_reg))
#define get_SE1_HCOEF1_18_reg   (*((volatile unsigned int*) SE1_HCOEF1_18_reg))
#define get_SE1_HCOEF1_19_reg   (*((volatile unsigned int*) SE1_HCOEF1_19_reg))
#define get_SE1_HCOEF1_20_reg   (*((volatile unsigned int*) SE1_HCOEF1_20_reg))
#define get_SE1_HCOEF1_21_reg   (*((volatile unsigned int*) SE1_HCOEF1_21_reg))
#define get_SE1_HCOEF1_22_reg   (*((volatile unsigned int*) SE1_HCOEF1_22_reg))
#define get_SE1_HCOEF1_23_reg   (*((volatile unsigned int*) SE1_HCOEF1_23_reg))
#define get_SE1_HCOEF1_24_reg   (*((volatile unsigned int*) SE1_HCOEF1_24_reg))
#define get_SE1_HCOEF1_25_reg   (*((volatile unsigned int*) SE1_HCOEF1_25_reg))
#define get_SE1_HCOEF1_26_reg   (*((volatile unsigned int*) SE1_HCOEF1_26_reg))
#define get_SE1_HCOEF1_27_reg   (*((volatile unsigned int*) SE1_HCOEF1_27_reg))
#define get_SE1_HCOEF1_28_reg   (*((volatile unsigned int*) SE1_HCOEF1_28_reg))
#define get_SE1_HCOEF1_29_reg   (*((volatile unsigned int*) SE1_HCOEF1_29_reg))
#define get_SE1_HCOEF1_30_reg   (*((volatile unsigned int*) SE1_HCOEF1_30_reg))
#define get_SE1_HCOEF1_31_reg   (*((volatile unsigned int*) SE1_HCOEF1_31_reg))
#define SE1_HCOEF1_0_inst_adr                                                         "0x00C0"
#define SE1_HCOEF1_1_inst_adr                                                         "0x00C1"
#define SE1_HCOEF1_2_inst_adr                                                         "0x00C2"
#define SE1_HCOEF1_3_inst_adr                                                         "0x00C3"
#define SE1_HCOEF1_4_inst_adr                                                         "0x00C4"
#define SE1_HCOEF1_5_inst_adr                                                         "0x00C5"
#define SE1_HCOEF1_6_inst_adr                                                         "0x00C6"
#define SE1_HCOEF1_7_inst_adr                                                         "0x00C7"
#define SE1_HCOEF1_8_inst_adr                                                         "0x00C8"
#define SE1_HCOEF1_9_inst_adr                                                         "0x00C9"
#define SE1_HCOEF1_10_inst_adr                                                         "0x00CA"
#define SE1_HCOEF1_11_inst_adr                                                         "0x00CB"
#define SE1_HCOEF1_12_inst_adr                                                         "0x00CC"
#define SE1_HCOEF1_13_inst_adr                                                         "0x00CD"
#define SE1_HCOEF1_14_inst_adr                                                         "0x00CE"
#define SE1_HCOEF1_15_inst_adr                                                         "0x00CF"
#define SE1_HCOEF1_16_inst_adr                                                         "0x00D0"
#define SE1_HCOEF1_17_inst_adr                                                         "0x00D1"
#define SE1_HCOEF1_18_inst_adr                                                         "0x00D2"
#define SE1_HCOEF1_19_inst_adr                                                         "0x00D3"
#define SE1_HCOEF1_20_inst_adr                                                         "0x00D4"
#define SE1_HCOEF1_21_inst_adr                                                         "0x00D5"
#define SE1_HCOEF1_22_inst_adr                                                         "0x00D6"
#define SE1_HCOEF1_23_inst_adr                                                         "0x00D7"
#define SE1_HCOEF1_24_inst_adr                                                         "0x00D8"
#define SE1_HCOEF1_25_inst_adr                                                         "0x00D9"
#define SE1_HCOEF1_26_inst_adr                                                         "0x00DA"
#define SE1_HCOEF1_27_inst_adr                                                         "0x00DB"
#define SE1_HCOEF1_28_inst_adr                                                         "0x00DC"
#define SE1_HCOEF1_29_inst_adr                                                         "0x00DD"
#define SE1_HCOEF1_30_inst_adr                                                         "0x00DE"
#define SE1_HCOEF1_31_inst_adr                                                         "0x00DF"
#define SE1_HCOEF1_0_inst                                                             0x00C0
#define SE1_HCOEF1_1_inst                                                             0x00C1
#define SE1_HCOEF1_2_inst                                                             0x00C2
#define SE1_HCOEF1_3_inst                                                             0x00C3
#define SE1_HCOEF1_4_inst                                                             0x00C4
#define SE1_HCOEF1_5_inst                                                             0x00C5
#define SE1_HCOEF1_6_inst                                                             0x00C6
#define SE1_HCOEF1_7_inst                                                             0x00C7
#define SE1_HCOEF1_8_inst                                                             0x00C8
#define SE1_HCOEF1_9_inst                                                             0x00C9
#define SE1_HCOEF1_10_inst                                                             0x00CA
#define SE1_HCOEF1_11_inst                                                             0x00CB
#define SE1_HCOEF1_12_inst                                                             0x00CC
#define SE1_HCOEF1_13_inst                                                             0x00CD
#define SE1_HCOEF1_14_inst                                                             0x00CE
#define SE1_HCOEF1_15_inst                                                             0x00CF
#define SE1_HCOEF1_16_inst                                                             0x00D0
#define SE1_HCOEF1_17_inst                                                             0x00D1
#define SE1_HCOEF1_18_inst                                                             0x00D2
#define SE1_HCOEF1_19_inst                                                             0x00D3
#define SE1_HCOEF1_20_inst                                                             0x00D4
#define SE1_HCOEF1_21_inst                                                             0x00D5
#define SE1_HCOEF1_22_inst                                                             0x00D6
#define SE1_HCOEF1_23_inst                                                             0x00D7
#define SE1_HCOEF1_24_inst                                                             0x00D8
#define SE1_HCOEF1_25_inst                                                             0x00D9
#define SE1_HCOEF1_26_inst                                                             0x00DA
#define SE1_HCOEF1_27_inst                                                             0x00DB
#define SE1_HCOEF1_28_inst                                                             0x00DC
#define SE1_HCOEF1_29_inst                                                             0x00DD
#define SE1_HCOEF1_30_inst                                                             0x00DE
#define SE1_HCOEF1_31_inst                                                             0x00DF
#define SE1_HCOEF1_hcoef_shift                                                        (0)
#define SE1_HCOEF1_hcoef_mask                                                         (0x00003FFF)
#define SE1_HCOEF1_hcoef(data)                                                        (0x00003FFF&((data)<<0))
#define SE1_HCOEF1_hcoef_src(data)                                                    ((0x00003FFF&(data))>>0)
#define SE1_HCOEF1_get_hcoef(data)                                                    ((0x00003FFF&(data))>>0)


#define SE1_HCOEF1_32_0                                                               0x1803E380
#define SE1_HCOEF1_32_1                                                               0x1803E384
#define SE1_HCOEF1_32_2                                                               0x1803E388
#define SE1_HCOEF1_32_3                                                               0x1803E38C
#define SE1_HCOEF1_32_4                                                               0x1803E390
#define SE1_HCOEF1_32_5                                                               0x1803E394
#define SE1_HCOEF1_32_6                                                               0x1803E398
#define SE1_HCOEF1_32_7                                                               0x1803E39C
#define SE1_HCOEF1_32_8                                                               0x1803E3A0
#define SE1_HCOEF1_32_9                                                               0x1803E3A4
#define SE1_HCOEF1_32_10                                                               0x1803E3A8
#define SE1_HCOEF1_32_11                                                               0x1803E3AC
#define SE1_HCOEF1_32_12                                                               0x1803E3B0
#define SE1_HCOEF1_32_13                                                               0x1803E3B4
#define SE1_HCOEF1_32_14                                                               0x1803E3B8
#define SE1_HCOEF1_32_15                                                               0x1803E3BC
#define SE1_HCOEF1_32_16                                                               0x1803E3C0
#define SE1_HCOEF1_32_17                                                               0x1803E3C4
#define SE1_HCOEF1_32_18                                                               0x1803E3C8
#define SE1_HCOEF1_32_19                                                               0x1803E3CC
#define SE1_HCOEF1_32_20                                                               0x1803E3D0
#define SE1_HCOEF1_32_21                                                               0x1803E3D4
#define SE1_HCOEF1_32_22                                                               0x1803E3D8
#define SE1_HCOEF1_32_23                                                               0x1803E3DC
#define SE1_HCOEF1_32_24                                                               0x1803E3E0
#define SE1_HCOEF1_32_25                                                               0x1803E3E4
#define SE1_HCOEF1_32_26                                                               0x1803E3E8
#define SE1_HCOEF1_32_27                                                               0x1803E3EC
#define SE1_HCOEF1_32_28                                                               0x1803E3F0
#define SE1_HCOEF1_32_29                                                               0x1803E3F4
#define SE1_HCOEF1_32_30                                                               0x1803E3F8
#define SE1_HCOEF1_32_31                                                               0x1803E3FC
#define SE1_HCOEF1_32_0_reg_addr                                                      "0xB803E380"
#define SE1_HCOEF1_32_1_reg_addr                                                      "0xB803E384"
#define SE1_HCOEF1_32_2_reg_addr                                                      "0xB803E388"
#define SE1_HCOEF1_32_3_reg_addr                                                      "0xB803E38C"
#define SE1_HCOEF1_32_4_reg_addr                                                      "0xB803E390"
#define SE1_HCOEF1_32_5_reg_addr                                                      "0xB803E394"
#define SE1_HCOEF1_32_6_reg_addr                                                      "0xB803E398"
#define SE1_HCOEF1_32_7_reg_addr                                                      "0xB803E39C"
#define SE1_HCOEF1_32_8_reg_addr                                                      "0xB803E3A0"
#define SE1_HCOEF1_32_9_reg_addr                                                      "0xB803E3A4"
#define SE1_HCOEF1_32_10_reg_addr                                                      "0xB803E3A8"
#define SE1_HCOEF1_32_11_reg_addr                                                      "0xB803E3AC"
#define SE1_HCOEF1_32_12_reg_addr                                                      "0xB803E3B0"
#define SE1_HCOEF1_32_13_reg_addr                                                      "0xB803E3B4"
#define SE1_HCOEF1_32_14_reg_addr                                                      "0xB803E3B8"
#define SE1_HCOEF1_32_15_reg_addr                                                      "0xB803E3BC"
#define SE1_HCOEF1_32_16_reg_addr                                                      "0xB803E3C0"
#define SE1_HCOEF1_32_17_reg_addr                                                      "0xB803E3C4"
#define SE1_HCOEF1_32_18_reg_addr                                                      "0xB803E3C8"
#define SE1_HCOEF1_32_19_reg_addr                                                      "0xB803E3CC"
#define SE1_HCOEF1_32_20_reg_addr                                                      "0xB803E3D0"
#define SE1_HCOEF1_32_21_reg_addr                                                      "0xB803E3D4"
#define SE1_HCOEF1_32_22_reg_addr                                                      "0xB803E3D8"
#define SE1_HCOEF1_32_23_reg_addr                                                      "0xB803E3DC"
#define SE1_HCOEF1_32_24_reg_addr                                                      "0xB803E3E0"
#define SE1_HCOEF1_32_25_reg_addr                                                      "0xB803E3E4"
#define SE1_HCOEF1_32_26_reg_addr                                                      "0xB803E3E8"
#define SE1_HCOEF1_32_27_reg_addr                                                      "0xB803E3EC"
#define SE1_HCOEF1_32_28_reg_addr                                                      "0xB803E3F0"
#define SE1_HCOEF1_32_29_reg_addr                                                      "0xB803E3F4"
#define SE1_HCOEF1_32_30_reg_addr                                                      "0xB803E3F8"
#define SE1_HCOEF1_32_31_reg_addr                                                      "0xB803E3FC"
#define SE1_HCOEF1_32_0_reg                                                           0xB803E380
#define SE1_HCOEF1_32_1_reg                                                           0xB803E384
#define SE1_HCOEF1_32_2_reg                                                           0xB803E388
#define SE1_HCOEF1_32_3_reg                                                           0xB803E38C
#define SE1_HCOEF1_32_4_reg                                                           0xB803E390
#define SE1_HCOEF1_32_5_reg                                                           0xB803E394
#define SE1_HCOEF1_32_6_reg                                                           0xB803E398
#define SE1_HCOEF1_32_7_reg                                                           0xB803E39C
#define SE1_HCOEF1_32_8_reg                                                           0xB803E3A0
#define SE1_HCOEF1_32_9_reg                                                           0xB803E3A4
#define SE1_HCOEF1_32_10_reg                                                           0xB803E3A8
#define SE1_HCOEF1_32_11_reg                                                           0xB803E3AC
#define SE1_HCOEF1_32_12_reg                                                           0xB803E3B0
#define SE1_HCOEF1_32_13_reg                                                           0xB803E3B4
#define SE1_HCOEF1_32_14_reg                                                           0xB803E3B8
#define SE1_HCOEF1_32_15_reg                                                           0xB803E3BC
#define SE1_HCOEF1_32_16_reg                                                           0xB803E3C0
#define SE1_HCOEF1_32_17_reg                                                           0xB803E3C4
#define SE1_HCOEF1_32_18_reg                                                           0xB803E3C8
#define SE1_HCOEF1_32_19_reg                                                           0xB803E3CC
#define SE1_HCOEF1_32_20_reg                                                           0xB803E3D0
#define SE1_HCOEF1_32_21_reg                                                           0xB803E3D4
#define SE1_HCOEF1_32_22_reg                                                           0xB803E3D8
#define SE1_HCOEF1_32_23_reg                                                           0xB803E3DC
#define SE1_HCOEF1_32_24_reg                                                           0xB803E3E0
#define SE1_HCOEF1_32_25_reg                                                           0xB803E3E4
#define SE1_HCOEF1_32_26_reg                                                           0xB803E3E8
#define SE1_HCOEF1_32_27_reg                                                           0xB803E3EC
#define SE1_HCOEF1_32_28_reg                                                           0xB803E3F0
#define SE1_HCOEF1_32_29_reg                                                           0xB803E3F4
#define SE1_HCOEF1_32_30_reg                                                           0xB803E3F8
#define SE1_HCOEF1_32_31_reg                                                           0xB803E3FC
#define set_SE1_HCOEF1_32_0_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_32_0_reg)=data)
#define set_SE1_HCOEF1_32_1_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_32_1_reg)=data)
#define set_SE1_HCOEF1_32_2_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_32_2_reg)=data)
#define set_SE1_HCOEF1_32_3_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_32_3_reg)=data)
#define set_SE1_HCOEF1_32_4_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_32_4_reg)=data)
#define set_SE1_HCOEF1_32_5_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_32_5_reg)=data)
#define set_SE1_HCOEF1_32_6_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_32_6_reg)=data)
#define set_SE1_HCOEF1_32_7_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_32_7_reg)=data)
#define set_SE1_HCOEF1_32_8_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_32_8_reg)=data)
#define set_SE1_HCOEF1_32_9_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_32_9_reg)=data)
#define set_SE1_HCOEF1_32_10_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_32_10_reg)=data)
#define set_SE1_HCOEF1_32_11_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_32_11_reg)=data)
#define set_SE1_HCOEF1_32_12_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_32_12_reg)=data)
#define set_SE1_HCOEF1_32_13_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_32_13_reg)=data)
#define set_SE1_HCOEF1_32_14_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_32_14_reg)=data)
#define set_SE1_HCOEF1_32_15_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_32_15_reg)=data)
#define set_SE1_HCOEF1_32_16_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_32_16_reg)=data)
#define set_SE1_HCOEF1_32_17_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_32_17_reg)=data)
#define set_SE1_HCOEF1_32_18_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_32_18_reg)=data)
#define set_SE1_HCOEF1_32_19_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_32_19_reg)=data)
#define set_SE1_HCOEF1_32_20_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_32_20_reg)=data)
#define set_SE1_HCOEF1_32_21_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_32_21_reg)=data)
#define set_SE1_HCOEF1_32_22_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_32_22_reg)=data)
#define set_SE1_HCOEF1_32_23_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_32_23_reg)=data)
#define set_SE1_HCOEF1_32_24_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_32_24_reg)=data)
#define set_SE1_HCOEF1_32_25_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_32_25_reg)=data)
#define set_SE1_HCOEF1_32_26_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_32_26_reg)=data)
#define set_SE1_HCOEF1_32_27_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_32_27_reg)=data)
#define set_SE1_HCOEF1_32_28_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_32_28_reg)=data)
#define set_SE1_HCOEF1_32_29_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_32_29_reg)=data)
#define set_SE1_HCOEF1_32_30_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_32_30_reg)=data)
#define set_SE1_HCOEF1_32_31_reg(data)   (*((volatile unsigned int*) SE1_HCOEF1_32_31_reg)=data)
#define get_SE1_HCOEF1_32_0_reg   (*((volatile unsigned int*) SE1_HCOEF1_32_0_reg))
#define get_SE1_HCOEF1_32_1_reg   (*((volatile unsigned int*) SE1_HCOEF1_32_1_reg))
#define get_SE1_HCOEF1_32_2_reg   (*((volatile unsigned int*) SE1_HCOEF1_32_2_reg))
#define get_SE1_HCOEF1_32_3_reg   (*((volatile unsigned int*) SE1_HCOEF1_32_3_reg))
#define get_SE1_HCOEF1_32_4_reg   (*((volatile unsigned int*) SE1_HCOEF1_32_4_reg))
#define get_SE1_HCOEF1_32_5_reg   (*((volatile unsigned int*) SE1_HCOEF1_32_5_reg))
#define get_SE1_HCOEF1_32_6_reg   (*((volatile unsigned int*) SE1_HCOEF1_32_6_reg))
#define get_SE1_HCOEF1_32_7_reg   (*((volatile unsigned int*) SE1_HCOEF1_32_7_reg))
#define get_SE1_HCOEF1_32_8_reg   (*((volatile unsigned int*) SE1_HCOEF1_32_8_reg))
#define get_SE1_HCOEF1_32_9_reg   (*((volatile unsigned int*) SE1_HCOEF1_32_9_reg))
#define get_SE1_HCOEF1_32_10_reg   (*((volatile unsigned int*) SE1_HCOEF1_32_10_reg))
#define get_SE1_HCOEF1_32_11_reg   (*((volatile unsigned int*) SE1_HCOEF1_32_11_reg))
#define get_SE1_HCOEF1_32_12_reg   (*((volatile unsigned int*) SE1_HCOEF1_32_12_reg))
#define get_SE1_HCOEF1_32_13_reg   (*((volatile unsigned int*) SE1_HCOEF1_32_13_reg))
#define get_SE1_HCOEF1_32_14_reg   (*((volatile unsigned int*) SE1_HCOEF1_32_14_reg))
#define get_SE1_HCOEF1_32_15_reg   (*((volatile unsigned int*) SE1_HCOEF1_32_15_reg))
#define get_SE1_HCOEF1_32_16_reg   (*((volatile unsigned int*) SE1_HCOEF1_32_16_reg))
#define get_SE1_HCOEF1_32_17_reg   (*((volatile unsigned int*) SE1_HCOEF1_32_17_reg))
#define get_SE1_HCOEF1_32_18_reg   (*((volatile unsigned int*) SE1_HCOEF1_32_18_reg))
#define get_SE1_HCOEF1_32_19_reg   (*((volatile unsigned int*) SE1_HCOEF1_32_19_reg))
#define get_SE1_HCOEF1_32_20_reg   (*((volatile unsigned int*) SE1_HCOEF1_32_20_reg))
#define get_SE1_HCOEF1_32_21_reg   (*((volatile unsigned int*) SE1_HCOEF1_32_21_reg))
#define get_SE1_HCOEF1_32_22_reg   (*((volatile unsigned int*) SE1_HCOEF1_32_22_reg))
#define get_SE1_HCOEF1_32_23_reg   (*((volatile unsigned int*) SE1_HCOEF1_32_23_reg))
#define get_SE1_HCOEF1_32_24_reg   (*((volatile unsigned int*) SE1_HCOEF1_32_24_reg))
#define get_SE1_HCOEF1_32_25_reg   (*((volatile unsigned int*) SE1_HCOEF1_32_25_reg))
#define get_SE1_HCOEF1_32_26_reg   (*((volatile unsigned int*) SE1_HCOEF1_32_26_reg))
#define get_SE1_HCOEF1_32_27_reg   (*((volatile unsigned int*) SE1_HCOEF1_32_27_reg))
#define get_SE1_HCOEF1_32_28_reg   (*((volatile unsigned int*) SE1_HCOEF1_32_28_reg))
#define get_SE1_HCOEF1_32_29_reg   (*((volatile unsigned int*) SE1_HCOEF1_32_29_reg))
#define get_SE1_HCOEF1_32_30_reg   (*((volatile unsigned int*) SE1_HCOEF1_32_30_reg))
#define get_SE1_HCOEF1_32_31_reg   (*((volatile unsigned int*) SE1_HCOEF1_32_31_reg))
#define SE1_HCOEF1_32_0_inst_adr                                                      "0x00E0"
#define SE1_HCOEF1_32_1_inst_adr                                                      "0x00E1"
#define SE1_HCOEF1_32_2_inst_adr                                                      "0x00E2"
#define SE1_HCOEF1_32_3_inst_adr                                                      "0x00E3"
#define SE1_HCOEF1_32_4_inst_adr                                                      "0x00E4"
#define SE1_HCOEF1_32_5_inst_adr                                                      "0x00E5"
#define SE1_HCOEF1_32_6_inst_adr                                                      "0x00E6"
#define SE1_HCOEF1_32_7_inst_adr                                                      "0x00E7"
#define SE1_HCOEF1_32_8_inst_adr                                                      "0x00E8"
#define SE1_HCOEF1_32_9_inst_adr                                                      "0x00E9"
#define SE1_HCOEF1_32_10_inst_adr                                                      "0x00EA"
#define SE1_HCOEF1_32_11_inst_adr                                                      "0x00EB"
#define SE1_HCOEF1_32_12_inst_adr                                                      "0x00EC"
#define SE1_HCOEF1_32_13_inst_adr                                                      "0x00ED"
#define SE1_HCOEF1_32_14_inst_adr                                                      "0x00EE"
#define SE1_HCOEF1_32_15_inst_adr                                                      "0x00EF"
#define SE1_HCOEF1_32_16_inst_adr                                                      "0x00F0"
#define SE1_HCOEF1_32_17_inst_adr                                                      "0x00F1"
#define SE1_HCOEF1_32_18_inst_adr                                                      "0x00F2"
#define SE1_HCOEF1_32_19_inst_adr                                                      "0x00F3"
#define SE1_HCOEF1_32_20_inst_adr                                                      "0x00F4"
#define SE1_HCOEF1_32_21_inst_adr                                                      "0x00F5"
#define SE1_HCOEF1_32_22_inst_adr                                                      "0x00F6"
#define SE1_HCOEF1_32_23_inst_adr                                                      "0x00F7"
#define SE1_HCOEF1_32_24_inst_adr                                                      "0x00F8"
#define SE1_HCOEF1_32_25_inst_adr                                                      "0x00F9"
#define SE1_HCOEF1_32_26_inst_adr                                                      "0x00FA"
#define SE1_HCOEF1_32_27_inst_adr                                                      "0x00FB"
#define SE1_HCOEF1_32_28_inst_adr                                                      "0x00FC"
#define SE1_HCOEF1_32_29_inst_adr                                                      "0x00FD"
#define SE1_HCOEF1_32_30_inst_adr                                                      "0x00FE"
#define SE1_HCOEF1_32_31_inst_adr                                                      "0x00FF"
#define SE1_HCOEF1_32_0_inst                                                          0x00E0
#define SE1_HCOEF1_32_1_inst                                                          0x00E1
#define SE1_HCOEF1_32_2_inst                                                          0x00E2
#define SE1_HCOEF1_32_3_inst                                                          0x00E3
#define SE1_HCOEF1_32_4_inst                                                          0x00E4
#define SE1_HCOEF1_32_5_inst                                                          0x00E5
#define SE1_HCOEF1_32_6_inst                                                          0x00E6
#define SE1_HCOEF1_32_7_inst                                                          0x00E7
#define SE1_HCOEF1_32_8_inst                                                          0x00E8
#define SE1_HCOEF1_32_9_inst                                                          0x00E9
#define SE1_HCOEF1_32_10_inst                                                          0x00EA
#define SE1_HCOEF1_32_11_inst                                                          0x00EB
#define SE1_HCOEF1_32_12_inst                                                          0x00EC
#define SE1_HCOEF1_32_13_inst                                                          0x00ED
#define SE1_HCOEF1_32_14_inst                                                          0x00EE
#define SE1_HCOEF1_32_15_inst                                                          0x00EF
#define SE1_HCOEF1_32_16_inst                                                          0x00F0
#define SE1_HCOEF1_32_17_inst                                                          0x00F1
#define SE1_HCOEF1_32_18_inst                                                          0x00F2
#define SE1_HCOEF1_32_19_inst                                                          0x00F3
#define SE1_HCOEF1_32_20_inst                                                          0x00F4
#define SE1_HCOEF1_32_21_inst                                                          0x00F5
#define SE1_HCOEF1_32_22_inst                                                          0x00F6
#define SE1_HCOEF1_32_23_inst                                                          0x00F7
#define SE1_HCOEF1_32_24_inst                                                          0x00F8
#define SE1_HCOEF1_32_25_inst                                                          0x00F9
#define SE1_HCOEF1_32_26_inst                                                          0x00FA
#define SE1_HCOEF1_32_27_inst                                                          0x00FB
#define SE1_HCOEF1_32_28_inst                                                          0x00FC
#define SE1_HCOEF1_32_29_inst                                                          0x00FD
#define SE1_HCOEF1_32_30_inst                                                          0x00FE
#define SE1_HCOEF1_32_31_inst                                                          0x00FF
#define SE1_HCOEF1_32_hcoef_shift                                                     (0)
#define SE1_HCOEF1_32_hcoef_mask                                                      (0x00003FFF)
#define SE1_HCOEF1_32_hcoef(data)                                                     (0x00003FFF&((data)<<0))
#define SE1_HCOEF1_32_hcoef_src(data)                                                 ((0x00003FFF&(data))>>0)
#define SE1_HCOEF1_32_get_hcoef(data)                                                 ((0x00003FFF&(data))>>0)


#define SE1_VCOEF1_0                                                                  0x1803E400
#define SE1_VCOEF1_1                                                                  0x1803E404
#define SE1_VCOEF1_2                                                                  0x1803E408
#define SE1_VCOEF1_3                                                                  0x1803E40C
#define SE1_VCOEF1_4                                                                  0x1803E410
#define SE1_VCOEF1_5                                                                  0x1803E414
#define SE1_VCOEF1_6                                                                  0x1803E418
#define SE1_VCOEF1_7                                                                  0x1803E41C
#define SE1_VCOEF1_8                                                                  0x1803E420
#define SE1_VCOEF1_9                                                                  0x1803E424
#define SE1_VCOEF1_10                                                                  0x1803E428
#define SE1_VCOEF1_11                                                                  0x1803E42C
#define SE1_VCOEF1_12                                                                  0x1803E430
#define SE1_VCOEF1_13                                                                  0x1803E434
#define SE1_VCOEF1_14                                                                  0x1803E438
#define SE1_VCOEF1_15                                                                  0x1803E43C
#define SE1_VCOEF1_0_reg_addr                                                         "0xB803E400"
#define SE1_VCOEF1_1_reg_addr                                                         "0xB803E404"
#define SE1_VCOEF1_2_reg_addr                                                         "0xB803E408"
#define SE1_VCOEF1_3_reg_addr                                                         "0xB803E40C"
#define SE1_VCOEF1_4_reg_addr                                                         "0xB803E410"
#define SE1_VCOEF1_5_reg_addr                                                         "0xB803E414"
#define SE1_VCOEF1_6_reg_addr                                                         "0xB803E418"
#define SE1_VCOEF1_7_reg_addr                                                         "0xB803E41C"
#define SE1_VCOEF1_8_reg_addr                                                         "0xB803E420"
#define SE1_VCOEF1_9_reg_addr                                                         "0xB803E424"
#define SE1_VCOEF1_10_reg_addr                                                         "0xB803E428"
#define SE1_VCOEF1_11_reg_addr                                                         "0xB803E42C"
#define SE1_VCOEF1_12_reg_addr                                                         "0xB803E430"
#define SE1_VCOEF1_13_reg_addr                                                         "0xB803E434"
#define SE1_VCOEF1_14_reg_addr                                                         "0xB803E438"
#define SE1_VCOEF1_15_reg_addr                                                         "0xB803E43C"
#define SE1_VCOEF1_0_reg                                                              0xB803E400
#define SE1_VCOEF1_1_reg                                                              0xB803E404
#define SE1_VCOEF1_2_reg                                                              0xB803E408
#define SE1_VCOEF1_3_reg                                                              0xB803E40C
#define SE1_VCOEF1_4_reg                                                              0xB803E410
#define SE1_VCOEF1_5_reg                                                              0xB803E414
#define SE1_VCOEF1_6_reg                                                              0xB803E418
#define SE1_VCOEF1_7_reg                                                              0xB803E41C
#define SE1_VCOEF1_8_reg                                                              0xB803E420
#define SE1_VCOEF1_9_reg                                                              0xB803E424
#define SE1_VCOEF1_10_reg                                                              0xB803E428
#define SE1_VCOEF1_11_reg                                                              0xB803E42C
#define SE1_VCOEF1_12_reg                                                              0xB803E430
#define SE1_VCOEF1_13_reg                                                              0xB803E434
#define SE1_VCOEF1_14_reg                                                              0xB803E438
#define SE1_VCOEF1_15_reg                                                              0xB803E43C
#define set_SE1_VCOEF1_0_reg(data)   (*((volatile unsigned int*) SE1_VCOEF1_0_reg)=data)
#define set_SE1_VCOEF1_1_reg(data)   (*((volatile unsigned int*) SE1_VCOEF1_1_reg)=data)
#define set_SE1_VCOEF1_2_reg(data)   (*((volatile unsigned int*) SE1_VCOEF1_2_reg)=data)
#define set_SE1_VCOEF1_3_reg(data)   (*((volatile unsigned int*) SE1_VCOEF1_3_reg)=data)
#define set_SE1_VCOEF1_4_reg(data)   (*((volatile unsigned int*) SE1_VCOEF1_4_reg)=data)
#define set_SE1_VCOEF1_5_reg(data)   (*((volatile unsigned int*) SE1_VCOEF1_5_reg)=data)
#define set_SE1_VCOEF1_6_reg(data)   (*((volatile unsigned int*) SE1_VCOEF1_6_reg)=data)
#define set_SE1_VCOEF1_7_reg(data)   (*((volatile unsigned int*) SE1_VCOEF1_7_reg)=data)
#define set_SE1_VCOEF1_8_reg(data)   (*((volatile unsigned int*) SE1_VCOEF1_8_reg)=data)
#define set_SE1_VCOEF1_9_reg(data)   (*((volatile unsigned int*) SE1_VCOEF1_9_reg)=data)
#define set_SE1_VCOEF1_10_reg(data)   (*((volatile unsigned int*) SE1_VCOEF1_10_reg)=data)
#define set_SE1_VCOEF1_11_reg(data)   (*((volatile unsigned int*) SE1_VCOEF1_11_reg)=data)
#define set_SE1_VCOEF1_12_reg(data)   (*((volatile unsigned int*) SE1_VCOEF1_12_reg)=data)
#define set_SE1_VCOEF1_13_reg(data)   (*((volatile unsigned int*) SE1_VCOEF1_13_reg)=data)
#define set_SE1_VCOEF1_14_reg(data)   (*((volatile unsigned int*) SE1_VCOEF1_14_reg)=data)
#define set_SE1_VCOEF1_15_reg(data)   (*((volatile unsigned int*) SE1_VCOEF1_15_reg)=data)
#define get_SE1_VCOEF1_0_reg   (*((volatile unsigned int*) SE1_VCOEF1_0_reg))
#define get_SE1_VCOEF1_1_reg   (*((volatile unsigned int*) SE1_VCOEF1_1_reg))
#define get_SE1_VCOEF1_2_reg   (*((volatile unsigned int*) SE1_VCOEF1_2_reg))
#define get_SE1_VCOEF1_3_reg   (*((volatile unsigned int*) SE1_VCOEF1_3_reg))
#define get_SE1_VCOEF1_4_reg   (*((volatile unsigned int*) SE1_VCOEF1_4_reg))
#define get_SE1_VCOEF1_5_reg   (*((volatile unsigned int*) SE1_VCOEF1_5_reg))
#define get_SE1_VCOEF1_6_reg   (*((volatile unsigned int*) SE1_VCOEF1_6_reg))
#define get_SE1_VCOEF1_7_reg   (*((volatile unsigned int*) SE1_VCOEF1_7_reg))
#define get_SE1_VCOEF1_8_reg   (*((volatile unsigned int*) SE1_VCOEF1_8_reg))
#define get_SE1_VCOEF1_9_reg   (*((volatile unsigned int*) SE1_VCOEF1_9_reg))
#define get_SE1_VCOEF1_10_reg   (*((volatile unsigned int*) SE1_VCOEF1_10_reg))
#define get_SE1_VCOEF1_11_reg   (*((volatile unsigned int*) SE1_VCOEF1_11_reg))
#define get_SE1_VCOEF1_12_reg   (*((volatile unsigned int*) SE1_VCOEF1_12_reg))
#define get_SE1_VCOEF1_13_reg   (*((volatile unsigned int*) SE1_VCOEF1_13_reg))
#define get_SE1_VCOEF1_14_reg   (*((volatile unsigned int*) SE1_VCOEF1_14_reg))
#define get_SE1_VCOEF1_15_reg   (*((volatile unsigned int*) SE1_VCOEF1_15_reg))
#define SE1_VCOEF1_0_inst_adr                                                         "0x0000"
#define SE1_VCOEF1_1_inst_adr                                                         "0x0001"
#define SE1_VCOEF1_2_inst_adr                                                         "0x0002"
#define SE1_VCOEF1_3_inst_adr                                                         "0x0003"
#define SE1_VCOEF1_4_inst_adr                                                         "0x0004"
#define SE1_VCOEF1_5_inst_adr                                                         "0x0005"
#define SE1_VCOEF1_6_inst_adr                                                         "0x0006"
#define SE1_VCOEF1_7_inst_adr                                                         "0x0007"
#define SE1_VCOEF1_8_inst_adr                                                         "0x0008"
#define SE1_VCOEF1_9_inst_adr                                                         "0x0009"
#define SE1_VCOEF1_10_inst_adr                                                         "0x000A"
#define SE1_VCOEF1_11_inst_adr                                                         "0x000B"
#define SE1_VCOEF1_12_inst_adr                                                         "0x000C"
#define SE1_VCOEF1_13_inst_adr                                                         "0x000D"
#define SE1_VCOEF1_14_inst_adr                                                         "0x000E"
#define SE1_VCOEF1_15_inst_adr                                                         "0x000F"
#define SE1_VCOEF1_0_inst                                                             0x0000
#define SE1_VCOEF1_1_inst                                                             0x0001
#define SE1_VCOEF1_2_inst                                                             0x0002
#define SE1_VCOEF1_3_inst                                                             0x0003
#define SE1_VCOEF1_4_inst                                                             0x0004
#define SE1_VCOEF1_5_inst                                                             0x0005
#define SE1_VCOEF1_6_inst                                                             0x0006
#define SE1_VCOEF1_7_inst                                                             0x0007
#define SE1_VCOEF1_8_inst                                                             0x0008
#define SE1_VCOEF1_9_inst                                                             0x0009
#define SE1_VCOEF1_10_inst                                                             0x000A
#define SE1_VCOEF1_11_inst                                                             0x000B
#define SE1_VCOEF1_12_inst                                                             0x000C
#define SE1_VCOEF1_13_inst                                                             0x000D
#define SE1_VCOEF1_14_inst                                                             0x000E
#define SE1_VCOEF1_15_inst                                                             0x000F
#define SE1_VCOEF1_vcoef_shift                                                        (0)
#define SE1_VCOEF1_vcoef_mask                                                         (0x00003FFF)
#define SE1_VCOEF1_vcoef(data)                                                        (0x00003FFF&((data)<<0))
#define SE1_VCOEF1_vcoef_src(data)                                                    ((0x00003FFF&(data))>>0)
#define SE1_VCOEF1_get_vcoef(data)                                                    ((0x00003FFF&(data))>>0)


#define SE1_VCOEF1_16_0                                                               0x1803E440
#define SE1_VCOEF1_16_1                                                               0x1803E444
#define SE1_VCOEF1_16_2                                                               0x1803E448
#define SE1_VCOEF1_16_3                                                               0x1803E44C
#define SE1_VCOEF1_16_4                                                               0x1803E450
#define SE1_VCOEF1_16_5                                                               0x1803E454
#define SE1_VCOEF1_16_6                                                               0x1803E458
#define SE1_VCOEF1_16_7                                                               0x1803E45C
#define SE1_VCOEF1_16_8                                                               0x1803E460
#define SE1_VCOEF1_16_9                                                               0x1803E464
#define SE1_VCOEF1_16_10                                                               0x1803E468
#define SE1_VCOEF1_16_11                                                               0x1803E46C
#define SE1_VCOEF1_16_12                                                               0x1803E470
#define SE1_VCOEF1_16_13                                                               0x1803E474
#define SE1_VCOEF1_16_14                                                               0x1803E478
#define SE1_VCOEF1_16_15                                                               0x1803E47C
#define SE1_VCOEF1_16_0_reg_addr                                                      "0xB803E440"
#define SE1_VCOEF1_16_1_reg_addr                                                      "0xB803E444"
#define SE1_VCOEF1_16_2_reg_addr                                                      "0xB803E448"
#define SE1_VCOEF1_16_3_reg_addr                                                      "0xB803E44C"
#define SE1_VCOEF1_16_4_reg_addr                                                      "0xB803E450"
#define SE1_VCOEF1_16_5_reg_addr                                                      "0xB803E454"
#define SE1_VCOEF1_16_6_reg_addr                                                      "0xB803E458"
#define SE1_VCOEF1_16_7_reg_addr                                                      "0xB803E45C"
#define SE1_VCOEF1_16_8_reg_addr                                                      "0xB803E460"
#define SE1_VCOEF1_16_9_reg_addr                                                      "0xB803E464"
#define SE1_VCOEF1_16_10_reg_addr                                                      "0xB803E468"
#define SE1_VCOEF1_16_11_reg_addr                                                      "0xB803E46C"
#define SE1_VCOEF1_16_12_reg_addr                                                      "0xB803E470"
#define SE1_VCOEF1_16_13_reg_addr                                                      "0xB803E474"
#define SE1_VCOEF1_16_14_reg_addr                                                      "0xB803E478"
#define SE1_VCOEF1_16_15_reg_addr                                                      "0xB803E47C"
#define SE1_VCOEF1_16_0_reg                                                           0xB803E440
#define SE1_VCOEF1_16_1_reg                                                           0xB803E444
#define SE1_VCOEF1_16_2_reg                                                           0xB803E448
#define SE1_VCOEF1_16_3_reg                                                           0xB803E44C
#define SE1_VCOEF1_16_4_reg                                                           0xB803E450
#define SE1_VCOEF1_16_5_reg                                                           0xB803E454
#define SE1_VCOEF1_16_6_reg                                                           0xB803E458
#define SE1_VCOEF1_16_7_reg                                                           0xB803E45C
#define SE1_VCOEF1_16_8_reg                                                           0xB803E460
#define SE1_VCOEF1_16_9_reg                                                           0xB803E464
#define SE1_VCOEF1_16_10_reg                                                           0xB803E468
#define SE1_VCOEF1_16_11_reg                                                           0xB803E46C
#define SE1_VCOEF1_16_12_reg                                                           0xB803E470
#define SE1_VCOEF1_16_13_reg                                                           0xB803E474
#define SE1_VCOEF1_16_14_reg                                                           0xB803E478
#define SE1_VCOEF1_16_15_reg                                                           0xB803E47C
#define set_SE1_VCOEF1_16_0_reg(data)   (*((volatile unsigned int*) SE1_VCOEF1_16_0_reg)=data)
#define set_SE1_VCOEF1_16_1_reg(data)   (*((volatile unsigned int*) SE1_VCOEF1_16_1_reg)=data)
#define set_SE1_VCOEF1_16_2_reg(data)   (*((volatile unsigned int*) SE1_VCOEF1_16_2_reg)=data)
#define set_SE1_VCOEF1_16_3_reg(data)   (*((volatile unsigned int*) SE1_VCOEF1_16_3_reg)=data)
#define set_SE1_VCOEF1_16_4_reg(data)   (*((volatile unsigned int*) SE1_VCOEF1_16_4_reg)=data)
#define set_SE1_VCOEF1_16_5_reg(data)   (*((volatile unsigned int*) SE1_VCOEF1_16_5_reg)=data)
#define set_SE1_VCOEF1_16_6_reg(data)   (*((volatile unsigned int*) SE1_VCOEF1_16_6_reg)=data)
#define set_SE1_VCOEF1_16_7_reg(data)   (*((volatile unsigned int*) SE1_VCOEF1_16_7_reg)=data)
#define set_SE1_VCOEF1_16_8_reg(data)   (*((volatile unsigned int*) SE1_VCOEF1_16_8_reg)=data)
#define set_SE1_VCOEF1_16_9_reg(data)   (*((volatile unsigned int*) SE1_VCOEF1_16_9_reg)=data)
#define set_SE1_VCOEF1_16_10_reg(data)   (*((volatile unsigned int*) SE1_VCOEF1_16_10_reg)=data)
#define set_SE1_VCOEF1_16_11_reg(data)   (*((volatile unsigned int*) SE1_VCOEF1_16_11_reg)=data)
#define set_SE1_VCOEF1_16_12_reg(data)   (*((volatile unsigned int*) SE1_VCOEF1_16_12_reg)=data)
#define set_SE1_VCOEF1_16_13_reg(data)   (*((volatile unsigned int*) SE1_VCOEF1_16_13_reg)=data)
#define set_SE1_VCOEF1_16_14_reg(data)   (*((volatile unsigned int*) SE1_VCOEF1_16_14_reg)=data)
#define set_SE1_VCOEF1_16_15_reg(data)   (*((volatile unsigned int*) SE1_VCOEF1_16_15_reg)=data)
#define get_SE1_VCOEF1_16_0_reg   (*((volatile unsigned int*) SE1_VCOEF1_16_0_reg))
#define get_SE1_VCOEF1_16_1_reg   (*((volatile unsigned int*) SE1_VCOEF1_16_1_reg))
#define get_SE1_VCOEF1_16_2_reg   (*((volatile unsigned int*) SE1_VCOEF1_16_2_reg))
#define get_SE1_VCOEF1_16_3_reg   (*((volatile unsigned int*) SE1_VCOEF1_16_3_reg))
#define get_SE1_VCOEF1_16_4_reg   (*((volatile unsigned int*) SE1_VCOEF1_16_4_reg))
#define get_SE1_VCOEF1_16_5_reg   (*((volatile unsigned int*) SE1_VCOEF1_16_5_reg))
#define get_SE1_VCOEF1_16_6_reg   (*((volatile unsigned int*) SE1_VCOEF1_16_6_reg))
#define get_SE1_VCOEF1_16_7_reg   (*((volatile unsigned int*) SE1_VCOEF1_16_7_reg))
#define get_SE1_VCOEF1_16_8_reg   (*((volatile unsigned int*) SE1_VCOEF1_16_8_reg))
#define get_SE1_VCOEF1_16_9_reg   (*((volatile unsigned int*) SE1_VCOEF1_16_9_reg))
#define get_SE1_VCOEF1_16_10_reg   (*((volatile unsigned int*) SE1_VCOEF1_16_10_reg))
#define get_SE1_VCOEF1_16_11_reg   (*((volatile unsigned int*) SE1_VCOEF1_16_11_reg))
#define get_SE1_VCOEF1_16_12_reg   (*((volatile unsigned int*) SE1_VCOEF1_16_12_reg))
#define get_SE1_VCOEF1_16_13_reg   (*((volatile unsigned int*) SE1_VCOEF1_16_13_reg))
#define get_SE1_VCOEF1_16_14_reg   (*((volatile unsigned int*) SE1_VCOEF1_16_14_reg))
#define get_SE1_VCOEF1_16_15_reg   (*((volatile unsigned int*) SE1_VCOEF1_16_15_reg))
#define SE1_VCOEF1_16_0_inst_adr                                                      "0x0010"
#define SE1_VCOEF1_16_1_inst_adr                                                      "0x0011"
#define SE1_VCOEF1_16_2_inst_adr                                                      "0x0012"
#define SE1_VCOEF1_16_3_inst_adr                                                      "0x0013"
#define SE1_VCOEF1_16_4_inst_adr                                                      "0x0014"
#define SE1_VCOEF1_16_5_inst_adr                                                      "0x0015"
#define SE1_VCOEF1_16_6_inst_adr                                                      "0x0016"
#define SE1_VCOEF1_16_7_inst_adr                                                      "0x0017"
#define SE1_VCOEF1_16_8_inst_adr                                                      "0x0018"
#define SE1_VCOEF1_16_9_inst_adr                                                      "0x0019"
#define SE1_VCOEF1_16_10_inst_adr                                                      "0x001A"
#define SE1_VCOEF1_16_11_inst_adr                                                      "0x001B"
#define SE1_VCOEF1_16_12_inst_adr                                                      "0x001C"
#define SE1_VCOEF1_16_13_inst_adr                                                      "0x001D"
#define SE1_VCOEF1_16_14_inst_adr                                                      "0x001E"
#define SE1_VCOEF1_16_15_inst_adr                                                      "0x001F"
#define SE1_VCOEF1_16_0_inst                                                          0x0010
#define SE1_VCOEF1_16_1_inst                                                          0x0011
#define SE1_VCOEF1_16_2_inst                                                          0x0012
#define SE1_VCOEF1_16_3_inst                                                          0x0013
#define SE1_VCOEF1_16_4_inst                                                          0x0014
#define SE1_VCOEF1_16_5_inst                                                          0x0015
#define SE1_VCOEF1_16_6_inst                                                          0x0016
#define SE1_VCOEF1_16_7_inst                                                          0x0017
#define SE1_VCOEF1_16_8_inst                                                          0x0018
#define SE1_VCOEF1_16_9_inst                                                          0x0019
#define SE1_VCOEF1_16_10_inst                                                          0x001A
#define SE1_VCOEF1_16_11_inst                                                          0x001B
#define SE1_VCOEF1_16_12_inst                                                          0x001C
#define SE1_VCOEF1_16_13_inst                                                          0x001D
#define SE1_VCOEF1_16_14_inst                                                          0x001E
#define SE1_VCOEF1_16_15_inst                                                          0x001F
#define SE1_VCOEF1_16_vcoef_shift                                                     (0)
#define SE1_VCOEF1_16_vcoef_mask                                                      (0x00003FFF)
#define SE1_VCOEF1_16_vcoef(data)                                                     (0x00003FFF&((data)<<0))
#define SE1_VCOEF1_16_vcoef_src(data)                                                 ((0x00003FFF&(data))>>0)
#define SE1_VCOEF1_16_get_vcoef(data)                                                 ((0x00003FFF&(data))>>0)


#define SE1_HCOEF2_0                                                                  0x1803E480
#define SE1_HCOEF2_1                                                                  0x1803E484
#define SE1_HCOEF2_2                                                                  0x1803E488
#define SE1_HCOEF2_3                                                                  0x1803E48C
#define SE1_HCOEF2_4                                                                  0x1803E490
#define SE1_HCOEF2_5                                                                  0x1803E494
#define SE1_HCOEF2_6                                                                  0x1803E498
#define SE1_HCOEF2_7                                                                  0x1803E49C
#define SE1_HCOEF2_8                                                                  0x1803E4A0
#define SE1_HCOEF2_9                                                                  0x1803E4A4
#define SE1_HCOEF2_10                                                                  0x1803E4A8
#define SE1_HCOEF2_11                                                                  0x1803E4AC
#define SE1_HCOEF2_12                                                                  0x1803E4B0
#define SE1_HCOEF2_13                                                                  0x1803E4B4
#define SE1_HCOEF2_14                                                                  0x1803E4B8
#define SE1_HCOEF2_15                                                                  0x1803E4BC
#define SE1_HCOEF2_16                                                                  0x1803E4C0
#define SE1_HCOEF2_17                                                                  0x1803E4C4
#define SE1_HCOEF2_18                                                                  0x1803E4C8
#define SE1_HCOEF2_19                                                                  0x1803E4CC
#define SE1_HCOEF2_20                                                                  0x1803E4D0
#define SE1_HCOEF2_21                                                                  0x1803E4D4
#define SE1_HCOEF2_22                                                                  0x1803E4D8
#define SE1_HCOEF2_23                                                                  0x1803E4DC
#define SE1_HCOEF2_24                                                                  0x1803E4E0
#define SE1_HCOEF2_25                                                                  0x1803E4E4
#define SE1_HCOEF2_26                                                                  0x1803E4E8
#define SE1_HCOEF2_27                                                                  0x1803E4EC
#define SE1_HCOEF2_28                                                                  0x1803E4F0
#define SE1_HCOEF2_29                                                                  0x1803E4F4
#define SE1_HCOEF2_30                                                                  0x1803E4F8
#define SE1_HCOEF2_31                                                                  0x1803E4FC
#define SE1_HCOEF2_0_reg_addr                                                         "0xB803E480"
#define SE1_HCOEF2_1_reg_addr                                                         "0xB803E484"
#define SE1_HCOEF2_2_reg_addr                                                         "0xB803E488"
#define SE1_HCOEF2_3_reg_addr                                                         "0xB803E48C"
#define SE1_HCOEF2_4_reg_addr                                                         "0xB803E490"
#define SE1_HCOEF2_5_reg_addr                                                         "0xB803E494"
#define SE1_HCOEF2_6_reg_addr                                                         "0xB803E498"
#define SE1_HCOEF2_7_reg_addr                                                         "0xB803E49C"
#define SE1_HCOEF2_8_reg_addr                                                         "0xB803E4A0"
#define SE1_HCOEF2_9_reg_addr                                                         "0xB803E4A4"
#define SE1_HCOEF2_10_reg_addr                                                         "0xB803E4A8"
#define SE1_HCOEF2_11_reg_addr                                                         "0xB803E4AC"
#define SE1_HCOEF2_12_reg_addr                                                         "0xB803E4B0"
#define SE1_HCOEF2_13_reg_addr                                                         "0xB803E4B4"
#define SE1_HCOEF2_14_reg_addr                                                         "0xB803E4B8"
#define SE1_HCOEF2_15_reg_addr                                                         "0xB803E4BC"
#define SE1_HCOEF2_16_reg_addr                                                         "0xB803E4C0"
#define SE1_HCOEF2_17_reg_addr                                                         "0xB803E4C4"
#define SE1_HCOEF2_18_reg_addr                                                         "0xB803E4C8"
#define SE1_HCOEF2_19_reg_addr                                                         "0xB803E4CC"
#define SE1_HCOEF2_20_reg_addr                                                         "0xB803E4D0"
#define SE1_HCOEF2_21_reg_addr                                                         "0xB803E4D4"
#define SE1_HCOEF2_22_reg_addr                                                         "0xB803E4D8"
#define SE1_HCOEF2_23_reg_addr                                                         "0xB803E4DC"
#define SE1_HCOEF2_24_reg_addr                                                         "0xB803E4E0"
#define SE1_HCOEF2_25_reg_addr                                                         "0xB803E4E4"
#define SE1_HCOEF2_26_reg_addr                                                         "0xB803E4E8"
#define SE1_HCOEF2_27_reg_addr                                                         "0xB803E4EC"
#define SE1_HCOEF2_28_reg_addr                                                         "0xB803E4F0"
#define SE1_HCOEF2_29_reg_addr                                                         "0xB803E4F4"
#define SE1_HCOEF2_30_reg_addr                                                         "0xB803E4F8"
#define SE1_HCOEF2_31_reg_addr                                                         "0xB803E4FC"
#define SE1_HCOEF2_0_reg                                                              0xB803E480
#define SE1_HCOEF2_1_reg                                                              0xB803E484
#define SE1_HCOEF2_2_reg                                                              0xB803E488
#define SE1_HCOEF2_3_reg                                                              0xB803E48C
#define SE1_HCOEF2_4_reg                                                              0xB803E490
#define SE1_HCOEF2_5_reg                                                              0xB803E494
#define SE1_HCOEF2_6_reg                                                              0xB803E498
#define SE1_HCOEF2_7_reg                                                              0xB803E49C
#define SE1_HCOEF2_8_reg                                                              0xB803E4A0
#define SE1_HCOEF2_9_reg                                                              0xB803E4A4
#define SE1_HCOEF2_10_reg                                                              0xB803E4A8
#define SE1_HCOEF2_11_reg                                                              0xB803E4AC
#define SE1_HCOEF2_12_reg                                                              0xB803E4B0
#define SE1_HCOEF2_13_reg                                                              0xB803E4B4
#define SE1_HCOEF2_14_reg                                                              0xB803E4B8
#define SE1_HCOEF2_15_reg                                                              0xB803E4BC
#define SE1_HCOEF2_16_reg                                                              0xB803E4C0
#define SE1_HCOEF2_17_reg                                                              0xB803E4C4
#define SE1_HCOEF2_18_reg                                                              0xB803E4C8
#define SE1_HCOEF2_19_reg                                                              0xB803E4CC
#define SE1_HCOEF2_20_reg                                                              0xB803E4D0
#define SE1_HCOEF2_21_reg                                                              0xB803E4D4
#define SE1_HCOEF2_22_reg                                                              0xB803E4D8
#define SE1_HCOEF2_23_reg                                                              0xB803E4DC
#define SE1_HCOEF2_24_reg                                                              0xB803E4E0
#define SE1_HCOEF2_25_reg                                                              0xB803E4E4
#define SE1_HCOEF2_26_reg                                                              0xB803E4E8
#define SE1_HCOEF2_27_reg                                                              0xB803E4EC
#define SE1_HCOEF2_28_reg                                                              0xB803E4F0
#define SE1_HCOEF2_29_reg                                                              0xB803E4F4
#define SE1_HCOEF2_30_reg                                                              0xB803E4F8
#define SE1_HCOEF2_31_reg                                                              0xB803E4FC
#define set_SE1_HCOEF2_0_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_0_reg)=data)
#define set_SE1_HCOEF2_1_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_1_reg)=data)
#define set_SE1_HCOEF2_2_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_2_reg)=data)
#define set_SE1_HCOEF2_3_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_3_reg)=data)
#define set_SE1_HCOEF2_4_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_4_reg)=data)
#define set_SE1_HCOEF2_5_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_5_reg)=data)
#define set_SE1_HCOEF2_6_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_6_reg)=data)
#define set_SE1_HCOEF2_7_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_7_reg)=data)
#define set_SE1_HCOEF2_8_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_8_reg)=data)
#define set_SE1_HCOEF2_9_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_9_reg)=data)
#define set_SE1_HCOEF2_10_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_10_reg)=data)
#define set_SE1_HCOEF2_11_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_11_reg)=data)
#define set_SE1_HCOEF2_12_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_12_reg)=data)
#define set_SE1_HCOEF2_13_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_13_reg)=data)
#define set_SE1_HCOEF2_14_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_14_reg)=data)
#define set_SE1_HCOEF2_15_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_15_reg)=data)
#define set_SE1_HCOEF2_16_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_16_reg)=data)
#define set_SE1_HCOEF2_17_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_17_reg)=data)
#define set_SE1_HCOEF2_18_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_18_reg)=data)
#define set_SE1_HCOEF2_19_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_19_reg)=data)
#define set_SE1_HCOEF2_20_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_20_reg)=data)
#define set_SE1_HCOEF2_21_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_21_reg)=data)
#define set_SE1_HCOEF2_22_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_22_reg)=data)
#define set_SE1_HCOEF2_23_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_23_reg)=data)
#define set_SE1_HCOEF2_24_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_24_reg)=data)
#define set_SE1_HCOEF2_25_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_25_reg)=data)
#define set_SE1_HCOEF2_26_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_26_reg)=data)
#define set_SE1_HCOEF2_27_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_27_reg)=data)
#define set_SE1_HCOEF2_28_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_28_reg)=data)
#define set_SE1_HCOEF2_29_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_29_reg)=data)
#define set_SE1_HCOEF2_30_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_30_reg)=data)
#define set_SE1_HCOEF2_31_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_31_reg)=data)
#define get_SE1_HCOEF2_0_reg   (*((volatile unsigned int*) SE1_HCOEF2_0_reg))
#define get_SE1_HCOEF2_1_reg   (*((volatile unsigned int*) SE1_HCOEF2_1_reg))
#define get_SE1_HCOEF2_2_reg   (*((volatile unsigned int*) SE1_HCOEF2_2_reg))
#define get_SE1_HCOEF2_3_reg   (*((volatile unsigned int*) SE1_HCOEF2_3_reg))
#define get_SE1_HCOEF2_4_reg   (*((volatile unsigned int*) SE1_HCOEF2_4_reg))
#define get_SE1_HCOEF2_5_reg   (*((volatile unsigned int*) SE1_HCOEF2_5_reg))
#define get_SE1_HCOEF2_6_reg   (*((volatile unsigned int*) SE1_HCOEF2_6_reg))
#define get_SE1_HCOEF2_7_reg   (*((volatile unsigned int*) SE1_HCOEF2_7_reg))
#define get_SE1_HCOEF2_8_reg   (*((volatile unsigned int*) SE1_HCOEF2_8_reg))
#define get_SE1_HCOEF2_9_reg   (*((volatile unsigned int*) SE1_HCOEF2_9_reg))
#define get_SE1_HCOEF2_10_reg   (*((volatile unsigned int*) SE1_HCOEF2_10_reg))
#define get_SE1_HCOEF2_11_reg   (*((volatile unsigned int*) SE1_HCOEF2_11_reg))
#define get_SE1_HCOEF2_12_reg   (*((volatile unsigned int*) SE1_HCOEF2_12_reg))
#define get_SE1_HCOEF2_13_reg   (*((volatile unsigned int*) SE1_HCOEF2_13_reg))
#define get_SE1_HCOEF2_14_reg   (*((volatile unsigned int*) SE1_HCOEF2_14_reg))
#define get_SE1_HCOEF2_15_reg   (*((volatile unsigned int*) SE1_HCOEF2_15_reg))
#define get_SE1_HCOEF2_16_reg   (*((volatile unsigned int*) SE1_HCOEF2_16_reg))
#define get_SE1_HCOEF2_17_reg   (*((volatile unsigned int*) SE1_HCOEF2_17_reg))
#define get_SE1_HCOEF2_18_reg   (*((volatile unsigned int*) SE1_HCOEF2_18_reg))
#define get_SE1_HCOEF2_19_reg   (*((volatile unsigned int*) SE1_HCOEF2_19_reg))
#define get_SE1_HCOEF2_20_reg   (*((volatile unsigned int*) SE1_HCOEF2_20_reg))
#define get_SE1_HCOEF2_21_reg   (*((volatile unsigned int*) SE1_HCOEF2_21_reg))
#define get_SE1_HCOEF2_22_reg   (*((volatile unsigned int*) SE1_HCOEF2_22_reg))
#define get_SE1_HCOEF2_23_reg   (*((volatile unsigned int*) SE1_HCOEF2_23_reg))
#define get_SE1_HCOEF2_24_reg   (*((volatile unsigned int*) SE1_HCOEF2_24_reg))
#define get_SE1_HCOEF2_25_reg   (*((volatile unsigned int*) SE1_HCOEF2_25_reg))
#define get_SE1_HCOEF2_26_reg   (*((volatile unsigned int*) SE1_HCOEF2_26_reg))
#define get_SE1_HCOEF2_27_reg   (*((volatile unsigned int*) SE1_HCOEF2_27_reg))
#define get_SE1_HCOEF2_28_reg   (*((volatile unsigned int*) SE1_HCOEF2_28_reg))
#define get_SE1_HCOEF2_29_reg   (*((volatile unsigned int*) SE1_HCOEF2_29_reg))
#define get_SE1_HCOEF2_30_reg   (*((volatile unsigned int*) SE1_HCOEF2_30_reg))
#define get_SE1_HCOEF2_31_reg   (*((volatile unsigned int*) SE1_HCOEF2_31_reg))
#define SE1_HCOEF2_0_inst_adr                                                         "0x0020"
#define SE1_HCOEF2_1_inst_adr                                                         "0x0021"
#define SE1_HCOEF2_2_inst_adr                                                         "0x0022"
#define SE1_HCOEF2_3_inst_adr                                                         "0x0023"
#define SE1_HCOEF2_4_inst_adr                                                         "0x0024"
#define SE1_HCOEF2_5_inst_adr                                                         "0x0025"
#define SE1_HCOEF2_6_inst_adr                                                         "0x0026"
#define SE1_HCOEF2_7_inst_adr                                                         "0x0027"
#define SE1_HCOEF2_8_inst_adr                                                         "0x0028"
#define SE1_HCOEF2_9_inst_adr                                                         "0x0029"
#define SE1_HCOEF2_10_inst_adr                                                         "0x002A"
#define SE1_HCOEF2_11_inst_adr                                                         "0x002B"
#define SE1_HCOEF2_12_inst_adr                                                         "0x002C"
#define SE1_HCOEF2_13_inst_adr                                                         "0x002D"
#define SE1_HCOEF2_14_inst_adr                                                         "0x002E"
#define SE1_HCOEF2_15_inst_adr                                                         "0x002F"
#define SE1_HCOEF2_16_inst_adr                                                         "0x0030"
#define SE1_HCOEF2_17_inst_adr                                                         "0x0031"
#define SE1_HCOEF2_18_inst_adr                                                         "0x0032"
#define SE1_HCOEF2_19_inst_adr                                                         "0x0033"
#define SE1_HCOEF2_20_inst_adr                                                         "0x0034"
#define SE1_HCOEF2_21_inst_adr                                                         "0x0035"
#define SE1_HCOEF2_22_inst_adr                                                         "0x0036"
#define SE1_HCOEF2_23_inst_adr                                                         "0x0037"
#define SE1_HCOEF2_24_inst_adr                                                         "0x0038"
#define SE1_HCOEF2_25_inst_adr                                                         "0x0039"
#define SE1_HCOEF2_26_inst_adr                                                         "0x003A"
#define SE1_HCOEF2_27_inst_adr                                                         "0x003B"
#define SE1_HCOEF2_28_inst_adr                                                         "0x003C"
#define SE1_HCOEF2_29_inst_adr                                                         "0x003D"
#define SE1_HCOEF2_30_inst_adr                                                         "0x003E"
#define SE1_HCOEF2_31_inst_adr                                                         "0x003F"
#define SE1_HCOEF2_0_inst                                                             0x0020
#define SE1_HCOEF2_1_inst                                                             0x0021
#define SE1_HCOEF2_2_inst                                                             0x0022
#define SE1_HCOEF2_3_inst                                                             0x0023
#define SE1_HCOEF2_4_inst                                                             0x0024
#define SE1_HCOEF2_5_inst                                                             0x0025
#define SE1_HCOEF2_6_inst                                                             0x0026
#define SE1_HCOEF2_7_inst                                                             0x0027
#define SE1_HCOEF2_8_inst                                                             0x0028
#define SE1_HCOEF2_9_inst                                                             0x0029
#define SE1_HCOEF2_10_inst                                                             0x002A
#define SE1_HCOEF2_11_inst                                                             0x002B
#define SE1_HCOEF2_12_inst                                                             0x002C
#define SE1_HCOEF2_13_inst                                                             0x002D
#define SE1_HCOEF2_14_inst                                                             0x002E
#define SE1_HCOEF2_15_inst                                                             0x002F
#define SE1_HCOEF2_16_inst                                                             0x0030
#define SE1_HCOEF2_17_inst                                                             0x0031
#define SE1_HCOEF2_18_inst                                                             0x0032
#define SE1_HCOEF2_19_inst                                                             0x0033
#define SE1_HCOEF2_20_inst                                                             0x0034
#define SE1_HCOEF2_21_inst                                                             0x0035
#define SE1_HCOEF2_22_inst                                                             0x0036
#define SE1_HCOEF2_23_inst                                                             0x0037
#define SE1_HCOEF2_24_inst                                                             0x0038
#define SE1_HCOEF2_25_inst                                                             0x0039
#define SE1_HCOEF2_26_inst                                                             0x003A
#define SE1_HCOEF2_27_inst                                                             0x003B
#define SE1_HCOEF2_28_inst                                                             0x003C
#define SE1_HCOEF2_29_inst                                                             0x003D
#define SE1_HCOEF2_30_inst                                                             0x003E
#define SE1_HCOEF2_31_inst                                                             0x003F
#define SE1_HCOEF2_hcoef_shift                                                        (0)
#define SE1_HCOEF2_hcoef_mask                                                         (0x00003FFF)
#define SE1_HCOEF2_hcoef(data)                                                        (0x00003FFF&((data)<<0))
#define SE1_HCOEF2_hcoef_src(data)                                                    ((0x00003FFF&(data))>>0)
#define SE1_HCOEF2_get_hcoef(data)                                                    ((0x00003FFF&(data))>>0)


#define SE1_HCOEF2_32_0                                                               0x1803E500
#define SE1_HCOEF2_32_1                                                               0x1803E504
#define SE1_HCOEF2_32_2                                                               0x1803E508
#define SE1_HCOEF2_32_3                                                               0x1803E50C
#define SE1_HCOEF2_32_4                                                               0x1803E510
#define SE1_HCOEF2_32_5                                                               0x1803E514
#define SE1_HCOEF2_32_6                                                               0x1803E518
#define SE1_HCOEF2_32_7                                                               0x1803E51C
#define SE1_HCOEF2_32_8                                                               0x1803E520
#define SE1_HCOEF2_32_9                                                               0x1803E524
#define SE1_HCOEF2_32_10                                                               0x1803E528
#define SE1_HCOEF2_32_11                                                               0x1803E52C
#define SE1_HCOEF2_32_12                                                               0x1803E530
#define SE1_HCOEF2_32_13                                                               0x1803E534
#define SE1_HCOEF2_32_14                                                               0x1803E538
#define SE1_HCOEF2_32_15                                                               0x1803E53C
#define SE1_HCOEF2_32_16                                                               0x1803E540
#define SE1_HCOEF2_32_17                                                               0x1803E544
#define SE1_HCOEF2_32_18                                                               0x1803E548
#define SE1_HCOEF2_32_19                                                               0x1803E54C
#define SE1_HCOEF2_32_20                                                               0x1803E550
#define SE1_HCOEF2_32_21                                                               0x1803E554
#define SE1_HCOEF2_32_22                                                               0x1803E558
#define SE1_HCOEF2_32_23                                                               0x1803E55C
#define SE1_HCOEF2_32_24                                                               0x1803E560
#define SE1_HCOEF2_32_25                                                               0x1803E564
#define SE1_HCOEF2_32_26                                                               0x1803E568
#define SE1_HCOEF2_32_27                                                               0x1803E56C
#define SE1_HCOEF2_32_28                                                               0x1803E570
#define SE1_HCOEF2_32_29                                                               0x1803E574
#define SE1_HCOEF2_32_30                                                               0x1803E578
#define SE1_HCOEF2_32_31                                                               0x1803E57C
#define SE1_HCOEF2_32_0_reg_addr                                                      "0xB803E500"
#define SE1_HCOEF2_32_1_reg_addr                                                      "0xB803E504"
#define SE1_HCOEF2_32_2_reg_addr                                                      "0xB803E508"
#define SE1_HCOEF2_32_3_reg_addr                                                      "0xB803E50C"
#define SE1_HCOEF2_32_4_reg_addr                                                      "0xB803E510"
#define SE1_HCOEF2_32_5_reg_addr                                                      "0xB803E514"
#define SE1_HCOEF2_32_6_reg_addr                                                      "0xB803E518"
#define SE1_HCOEF2_32_7_reg_addr                                                      "0xB803E51C"
#define SE1_HCOEF2_32_8_reg_addr                                                      "0xB803E520"
#define SE1_HCOEF2_32_9_reg_addr                                                      "0xB803E524"
#define SE1_HCOEF2_32_10_reg_addr                                                      "0xB803E528"
#define SE1_HCOEF2_32_11_reg_addr                                                      "0xB803E52C"
#define SE1_HCOEF2_32_12_reg_addr                                                      "0xB803E530"
#define SE1_HCOEF2_32_13_reg_addr                                                      "0xB803E534"
#define SE1_HCOEF2_32_14_reg_addr                                                      "0xB803E538"
#define SE1_HCOEF2_32_15_reg_addr                                                      "0xB803E53C"
#define SE1_HCOEF2_32_16_reg_addr                                                      "0xB803E540"
#define SE1_HCOEF2_32_17_reg_addr                                                      "0xB803E544"
#define SE1_HCOEF2_32_18_reg_addr                                                      "0xB803E548"
#define SE1_HCOEF2_32_19_reg_addr                                                      "0xB803E54C"
#define SE1_HCOEF2_32_20_reg_addr                                                      "0xB803E550"
#define SE1_HCOEF2_32_21_reg_addr                                                      "0xB803E554"
#define SE1_HCOEF2_32_22_reg_addr                                                      "0xB803E558"
#define SE1_HCOEF2_32_23_reg_addr                                                      "0xB803E55C"
#define SE1_HCOEF2_32_24_reg_addr                                                      "0xB803E560"
#define SE1_HCOEF2_32_25_reg_addr                                                      "0xB803E564"
#define SE1_HCOEF2_32_26_reg_addr                                                      "0xB803E568"
#define SE1_HCOEF2_32_27_reg_addr                                                      "0xB803E56C"
#define SE1_HCOEF2_32_28_reg_addr                                                      "0xB803E570"
#define SE1_HCOEF2_32_29_reg_addr                                                      "0xB803E574"
#define SE1_HCOEF2_32_30_reg_addr                                                      "0xB803E578"
#define SE1_HCOEF2_32_31_reg_addr                                                      "0xB803E57C"
#define SE1_HCOEF2_32_0_reg                                                           0xB803E500
#define SE1_HCOEF2_32_1_reg                                                           0xB803E504
#define SE1_HCOEF2_32_2_reg                                                           0xB803E508
#define SE1_HCOEF2_32_3_reg                                                           0xB803E50C
#define SE1_HCOEF2_32_4_reg                                                           0xB803E510
#define SE1_HCOEF2_32_5_reg                                                           0xB803E514
#define SE1_HCOEF2_32_6_reg                                                           0xB803E518
#define SE1_HCOEF2_32_7_reg                                                           0xB803E51C
#define SE1_HCOEF2_32_8_reg                                                           0xB803E520
#define SE1_HCOEF2_32_9_reg                                                           0xB803E524
#define SE1_HCOEF2_32_10_reg                                                           0xB803E528
#define SE1_HCOEF2_32_11_reg                                                           0xB803E52C
#define SE1_HCOEF2_32_12_reg                                                           0xB803E530
#define SE1_HCOEF2_32_13_reg                                                           0xB803E534
#define SE1_HCOEF2_32_14_reg                                                           0xB803E538
#define SE1_HCOEF2_32_15_reg                                                           0xB803E53C
#define SE1_HCOEF2_32_16_reg                                                           0xB803E540
#define SE1_HCOEF2_32_17_reg                                                           0xB803E544
#define SE1_HCOEF2_32_18_reg                                                           0xB803E548
#define SE1_HCOEF2_32_19_reg                                                           0xB803E54C
#define SE1_HCOEF2_32_20_reg                                                           0xB803E550
#define SE1_HCOEF2_32_21_reg                                                           0xB803E554
#define SE1_HCOEF2_32_22_reg                                                           0xB803E558
#define SE1_HCOEF2_32_23_reg                                                           0xB803E55C
#define SE1_HCOEF2_32_24_reg                                                           0xB803E560
#define SE1_HCOEF2_32_25_reg                                                           0xB803E564
#define SE1_HCOEF2_32_26_reg                                                           0xB803E568
#define SE1_HCOEF2_32_27_reg                                                           0xB803E56C
#define SE1_HCOEF2_32_28_reg                                                           0xB803E570
#define SE1_HCOEF2_32_29_reg                                                           0xB803E574
#define SE1_HCOEF2_32_30_reg                                                           0xB803E578
#define SE1_HCOEF2_32_31_reg                                                           0xB803E57C
#define set_SE1_HCOEF2_32_0_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_32_0_reg)=data)
#define set_SE1_HCOEF2_32_1_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_32_1_reg)=data)
#define set_SE1_HCOEF2_32_2_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_32_2_reg)=data)
#define set_SE1_HCOEF2_32_3_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_32_3_reg)=data)
#define set_SE1_HCOEF2_32_4_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_32_4_reg)=data)
#define set_SE1_HCOEF2_32_5_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_32_5_reg)=data)
#define set_SE1_HCOEF2_32_6_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_32_6_reg)=data)
#define set_SE1_HCOEF2_32_7_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_32_7_reg)=data)
#define set_SE1_HCOEF2_32_8_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_32_8_reg)=data)
#define set_SE1_HCOEF2_32_9_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_32_9_reg)=data)
#define set_SE1_HCOEF2_32_10_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_32_10_reg)=data)
#define set_SE1_HCOEF2_32_11_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_32_11_reg)=data)
#define set_SE1_HCOEF2_32_12_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_32_12_reg)=data)
#define set_SE1_HCOEF2_32_13_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_32_13_reg)=data)
#define set_SE1_HCOEF2_32_14_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_32_14_reg)=data)
#define set_SE1_HCOEF2_32_15_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_32_15_reg)=data)
#define set_SE1_HCOEF2_32_16_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_32_16_reg)=data)
#define set_SE1_HCOEF2_32_17_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_32_17_reg)=data)
#define set_SE1_HCOEF2_32_18_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_32_18_reg)=data)
#define set_SE1_HCOEF2_32_19_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_32_19_reg)=data)
#define set_SE1_HCOEF2_32_20_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_32_20_reg)=data)
#define set_SE1_HCOEF2_32_21_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_32_21_reg)=data)
#define set_SE1_HCOEF2_32_22_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_32_22_reg)=data)
#define set_SE1_HCOEF2_32_23_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_32_23_reg)=data)
#define set_SE1_HCOEF2_32_24_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_32_24_reg)=data)
#define set_SE1_HCOEF2_32_25_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_32_25_reg)=data)
#define set_SE1_HCOEF2_32_26_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_32_26_reg)=data)
#define set_SE1_HCOEF2_32_27_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_32_27_reg)=data)
#define set_SE1_HCOEF2_32_28_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_32_28_reg)=data)
#define set_SE1_HCOEF2_32_29_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_32_29_reg)=data)
#define set_SE1_HCOEF2_32_30_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_32_30_reg)=data)
#define set_SE1_HCOEF2_32_31_reg(data)   (*((volatile unsigned int*) SE1_HCOEF2_32_31_reg)=data)
#define get_SE1_HCOEF2_32_0_reg   (*((volatile unsigned int*) SE1_HCOEF2_32_0_reg))
#define get_SE1_HCOEF2_32_1_reg   (*((volatile unsigned int*) SE1_HCOEF2_32_1_reg))
#define get_SE1_HCOEF2_32_2_reg   (*((volatile unsigned int*) SE1_HCOEF2_32_2_reg))
#define get_SE1_HCOEF2_32_3_reg   (*((volatile unsigned int*) SE1_HCOEF2_32_3_reg))
#define get_SE1_HCOEF2_32_4_reg   (*((volatile unsigned int*) SE1_HCOEF2_32_4_reg))
#define get_SE1_HCOEF2_32_5_reg   (*((volatile unsigned int*) SE1_HCOEF2_32_5_reg))
#define get_SE1_HCOEF2_32_6_reg   (*((volatile unsigned int*) SE1_HCOEF2_32_6_reg))
#define get_SE1_HCOEF2_32_7_reg   (*((volatile unsigned int*) SE1_HCOEF2_32_7_reg))
#define get_SE1_HCOEF2_32_8_reg   (*((volatile unsigned int*) SE1_HCOEF2_32_8_reg))
#define get_SE1_HCOEF2_32_9_reg   (*((volatile unsigned int*) SE1_HCOEF2_32_9_reg))
#define get_SE1_HCOEF2_32_10_reg   (*((volatile unsigned int*) SE1_HCOEF2_32_10_reg))
#define get_SE1_HCOEF2_32_11_reg   (*((volatile unsigned int*) SE1_HCOEF2_32_11_reg))
#define get_SE1_HCOEF2_32_12_reg   (*((volatile unsigned int*) SE1_HCOEF2_32_12_reg))
#define get_SE1_HCOEF2_32_13_reg   (*((volatile unsigned int*) SE1_HCOEF2_32_13_reg))
#define get_SE1_HCOEF2_32_14_reg   (*((volatile unsigned int*) SE1_HCOEF2_32_14_reg))
#define get_SE1_HCOEF2_32_15_reg   (*((volatile unsigned int*) SE1_HCOEF2_32_15_reg))
#define get_SE1_HCOEF2_32_16_reg   (*((volatile unsigned int*) SE1_HCOEF2_32_16_reg))
#define get_SE1_HCOEF2_32_17_reg   (*((volatile unsigned int*) SE1_HCOEF2_32_17_reg))
#define get_SE1_HCOEF2_32_18_reg   (*((volatile unsigned int*) SE1_HCOEF2_32_18_reg))
#define get_SE1_HCOEF2_32_19_reg   (*((volatile unsigned int*) SE1_HCOEF2_32_19_reg))
#define get_SE1_HCOEF2_32_20_reg   (*((volatile unsigned int*) SE1_HCOEF2_32_20_reg))
#define get_SE1_HCOEF2_32_21_reg   (*((volatile unsigned int*) SE1_HCOEF2_32_21_reg))
#define get_SE1_HCOEF2_32_22_reg   (*((volatile unsigned int*) SE1_HCOEF2_32_22_reg))
#define get_SE1_HCOEF2_32_23_reg   (*((volatile unsigned int*) SE1_HCOEF2_32_23_reg))
#define get_SE1_HCOEF2_32_24_reg   (*((volatile unsigned int*) SE1_HCOEF2_32_24_reg))
#define get_SE1_HCOEF2_32_25_reg   (*((volatile unsigned int*) SE1_HCOEF2_32_25_reg))
#define get_SE1_HCOEF2_32_26_reg   (*((volatile unsigned int*) SE1_HCOEF2_32_26_reg))
#define get_SE1_HCOEF2_32_27_reg   (*((volatile unsigned int*) SE1_HCOEF2_32_27_reg))
#define get_SE1_HCOEF2_32_28_reg   (*((volatile unsigned int*) SE1_HCOEF2_32_28_reg))
#define get_SE1_HCOEF2_32_29_reg   (*((volatile unsigned int*) SE1_HCOEF2_32_29_reg))
#define get_SE1_HCOEF2_32_30_reg   (*((volatile unsigned int*) SE1_HCOEF2_32_30_reg))
#define get_SE1_HCOEF2_32_31_reg   (*((volatile unsigned int*) SE1_HCOEF2_32_31_reg))
#define SE1_HCOEF2_32_0_inst_adr                                                      "0x0040"
#define SE1_HCOEF2_32_1_inst_adr                                                      "0x0041"
#define SE1_HCOEF2_32_2_inst_adr                                                      "0x0042"
#define SE1_HCOEF2_32_3_inst_adr                                                      "0x0043"
#define SE1_HCOEF2_32_4_inst_adr                                                      "0x0044"
#define SE1_HCOEF2_32_5_inst_adr                                                      "0x0045"
#define SE1_HCOEF2_32_6_inst_adr                                                      "0x0046"
#define SE1_HCOEF2_32_7_inst_adr                                                      "0x0047"
#define SE1_HCOEF2_32_8_inst_adr                                                      "0x0048"
#define SE1_HCOEF2_32_9_inst_adr                                                      "0x0049"
#define SE1_HCOEF2_32_10_inst_adr                                                      "0x004A"
#define SE1_HCOEF2_32_11_inst_adr                                                      "0x004B"
#define SE1_HCOEF2_32_12_inst_adr                                                      "0x004C"
#define SE1_HCOEF2_32_13_inst_adr                                                      "0x004D"
#define SE1_HCOEF2_32_14_inst_adr                                                      "0x004E"
#define SE1_HCOEF2_32_15_inst_adr                                                      "0x004F"
#define SE1_HCOEF2_32_16_inst_adr                                                      "0x0050"
#define SE1_HCOEF2_32_17_inst_adr                                                      "0x0051"
#define SE1_HCOEF2_32_18_inst_adr                                                      "0x0052"
#define SE1_HCOEF2_32_19_inst_adr                                                      "0x0053"
#define SE1_HCOEF2_32_20_inst_adr                                                      "0x0054"
#define SE1_HCOEF2_32_21_inst_adr                                                      "0x0055"
#define SE1_HCOEF2_32_22_inst_adr                                                      "0x0056"
#define SE1_HCOEF2_32_23_inst_adr                                                      "0x0057"
#define SE1_HCOEF2_32_24_inst_adr                                                      "0x0058"
#define SE1_HCOEF2_32_25_inst_adr                                                      "0x0059"
#define SE1_HCOEF2_32_26_inst_adr                                                      "0x005A"
#define SE1_HCOEF2_32_27_inst_adr                                                      "0x005B"
#define SE1_HCOEF2_32_28_inst_adr                                                      "0x005C"
#define SE1_HCOEF2_32_29_inst_adr                                                      "0x005D"
#define SE1_HCOEF2_32_30_inst_adr                                                      "0x005E"
#define SE1_HCOEF2_32_31_inst_adr                                                      "0x005F"
#define SE1_HCOEF2_32_0_inst                                                          0x0040
#define SE1_HCOEF2_32_1_inst                                                          0x0041
#define SE1_HCOEF2_32_2_inst                                                          0x0042
#define SE1_HCOEF2_32_3_inst                                                          0x0043
#define SE1_HCOEF2_32_4_inst                                                          0x0044
#define SE1_HCOEF2_32_5_inst                                                          0x0045
#define SE1_HCOEF2_32_6_inst                                                          0x0046
#define SE1_HCOEF2_32_7_inst                                                          0x0047
#define SE1_HCOEF2_32_8_inst                                                          0x0048
#define SE1_HCOEF2_32_9_inst                                                          0x0049
#define SE1_HCOEF2_32_10_inst                                                          0x004A
#define SE1_HCOEF2_32_11_inst                                                          0x004B
#define SE1_HCOEF2_32_12_inst                                                          0x004C
#define SE1_HCOEF2_32_13_inst                                                          0x004D
#define SE1_HCOEF2_32_14_inst                                                          0x004E
#define SE1_HCOEF2_32_15_inst                                                          0x004F
#define SE1_HCOEF2_32_16_inst                                                          0x0050
#define SE1_HCOEF2_32_17_inst                                                          0x0051
#define SE1_HCOEF2_32_18_inst                                                          0x0052
#define SE1_HCOEF2_32_19_inst                                                          0x0053
#define SE1_HCOEF2_32_20_inst                                                          0x0054
#define SE1_HCOEF2_32_21_inst                                                          0x0055
#define SE1_HCOEF2_32_22_inst                                                          0x0056
#define SE1_HCOEF2_32_23_inst                                                          0x0057
#define SE1_HCOEF2_32_24_inst                                                          0x0058
#define SE1_HCOEF2_32_25_inst                                                          0x0059
#define SE1_HCOEF2_32_26_inst                                                          0x005A
#define SE1_HCOEF2_32_27_inst                                                          0x005B
#define SE1_HCOEF2_32_28_inst                                                          0x005C
#define SE1_HCOEF2_32_29_inst                                                          0x005D
#define SE1_HCOEF2_32_30_inst                                                          0x005E
#define SE1_HCOEF2_32_31_inst                                                          0x005F
#define SE1_HCOEF2_32_hcoef_shift                                                     (0)
#define SE1_HCOEF2_32_hcoef_mask                                                      (0x00003FFF)
#define SE1_HCOEF2_32_hcoef(data)                                                     (0x00003FFF&((data)<<0))
#define SE1_HCOEF2_32_hcoef_src(data)                                                 ((0x00003FFF&(data))>>0)
#define SE1_HCOEF2_32_get_hcoef(data)                                                 ((0x00003FFF&(data))>>0)


#define SE1_VCOEF2_0                                                                  0x1803E580
#define SE1_VCOEF2_1                                                                  0x1803E584
#define SE1_VCOEF2_2                                                                  0x1803E588
#define SE1_VCOEF2_3                                                                  0x1803E58C
#define SE1_VCOEF2_4                                                                  0x1803E590
#define SE1_VCOEF2_5                                                                  0x1803E594
#define SE1_VCOEF2_6                                                                  0x1803E598
#define SE1_VCOEF2_7                                                                  0x1803E59C
#define SE1_VCOEF2_8                                                                  0x1803E5A0
#define SE1_VCOEF2_9                                                                  0x1803E5A4
#define SE1_VCOEF2_10                                                                  0x1803E5A8
#define SE1_VCOEF2_11                                                                  0x1803E5AC
#define SE1_VCOEF2_12                                                                  0x1803E5B0
#define SE1_VCOEF2_13                                                                  0x1803E5B4
#define SE1_VCOEF2_14                                                                  0x1803E5B8
#define SE1_VCOEF2_15                                                                  0x1803E5BC
#define SE1_VCOEF2_0_reg_addr                                                         "0xB803E580"
#define SE1_VCOEF2_1_reg_addr                                                         "0xB803E584"
#define SE1_VCOEF2_2_reg_addr                                                         "0xB803E588"
#define SE1_VCOEF2_3_reg_addr                                                         "0xB803E58C"
#define SE1_VCOEF2_4_reg_addr                                                         "0xB803E590"
#define SE1_VCOEF2_5_reg_addr                                                         "0xB803E594"
#define SE1_VCOEF2_6_reg_addr                                                         "0xB803E598"
#define SE1_VCOEF2_7_reg_addr                                                         "0xB803E59C"
#define SE1_VCOEF2_8_reg_addr                                                         "0xB803E5A0"
#define SE1_VCOEF2_9_reg_addr                                                         "0xB803E5A4"
#define SE1_VCOEF2_10_reg_addr                                                         "0xB803E5A8"
#define SE1_VCOEF2_11_reg_addr                                                         "0xB803E5AC"
#define SE1_VCOEF2_12_reg_addr                                                         "0xB803E5B0"
#define SE1_VCOEF2_13_reg_addr                                                         "0xB803E5B4"
#define SE1_VCOEF2_14_reg_addr                                                         "0xB803E5B8"
#define SE1_VCOEF2_15_reg_addr                                                         "0xB803E5BC"
#define SE1_VCOEF2_0_reg                                                              0xB803E580
#define SE1_VCOEF2_1_reg                                                              0xB803E584
#define SE1_VCOEF2_2_reg                                                              0xB803E588
#define SE1_VCOEF2_3_reg                                                              0xB803E58C
#define SE1_VCOEF2_4_reg                                                              0xB803E590
#define SE1_VCOEF2_5_reg                                                              0xB803E594
#define SE1_VCOEF2_6_reg                                                              0xB803E598
#define SE1_VCOEF2_7_reg                                                              0xB803E59C
#define SE1_VCOEF2_8_reg                                                              0xB803E5A0
#define SE1_VCOEF2_9_reg                                                              0xB803E5A4
#define SE1_VCOEF2_10_reg                                                              0xB803E5A8
#define SE1_VCOEF2_11_reg                                                              0xB803E5AC
#define SE1_VCOEF2_12_reg                                                              0xB803E5B0
#define SE1_VCOEF2_13_reg                                                              0xB803E5B4
#define SE1_VCOEF2_14_reg                                                              0xB803E5B8
#define SE1_VCOEF2_15_reg                                                              0xB803E5BC
#define set_SE1_VCOEF2_0_reg(data)   (*((volatile unsigned int*) SE1_VCOEF2_0_reg)=data)
#define set_SE1_VCOEF2_1_reg(data)   (*((volatile unsigned int*) SE1_VCOEF2_1_reg)=data)
#define set_SE1_VCOEF2_2_reg(data)   (*((volatile unsigned int*) SE1_VCOEF2_2_reg)=data)
#define set_SE1_VCOEF2_3_reg(data)   (*((volatile unsigned int*) SE1_VCOEF2_3_reg)=data)
#define set_SE1_VCOEF2_4_reg(data)   (*((volatile unsigned int*) SE1_VCOEF2_4_reg)=data)
#define set_SE1_VCOEF2_5_reg(data)   (*((volatile unsigned int*) SE1_VCOEF2_5_reg)=data)
#define set_SE1_VCOEF2_6_reg(data)   (*((volatile unsigned int*) SE1_VCOEF2_6_reg)=data)
#define set_SE1_VCOEF2_7_reg(data)   (*((volatile unsigned int*) SE1_VCOEF2_7_reg)=data)
#define set_SE1_VCOEF2_8_reg(data)   (*((volatile unsigned int*) SE1_VCOEF2_8_reg)=data)
#define set_SE1_VCOEF2_9_reg(data)   (*((volatile unsigned int*) SE1_VCOEF2_9_reg)=data)
#define set_SE1_VCOEF2_10_reg(data)   (*((volatile unsigned int*) SE1_VCOEF2_10_reg)=data)
#define set_SE1_VCOEF2_11_reg(data)   (*((volatile unsigned int*) SE1_VCOEF2_11_reg)=data)
#define set_SE1_VCOEF2_12_reg(data)   (*((volatile unsigned int*) SE1_VCOEF2_12_reg)=data)
#define set_SE1_VCOEF2_13_reg(data)   (*((volatile unsigned int*) SE1_VCOEF2_13_reg)=data)
#define set_SE1_VCOEF2_14_reg(data)   (*((volatile unsigned int*) SE1_VCOEF2_14_reg)=data)
#define set_SE1_VCOEF2_15_reg(data)   (*((volatile unsigned int*) SE1_VCOEF2_15_reg)=data)
#define get_SE1_VCOEF2_0_reg   (*((volatile unsigned int*) SE1_VCOEF2_0_reg))
#define get_SE1_VCOEF2_1_reg   (*((volatile unsigned int*) SE1_VCOEF2_1_reg))
#define get_SE1_VCOEF2_2_reg   (*((volatile unsigned int*) SE1_VCOEF2_2_reg))
#define get_SE1_VCOEF2_3_reg   (*((volatile unsigned int*) SE1_VCOEF2_3_reg))
#define get_SE1_VCOEF2_4_reg   (*((volatile unsigned int*) SE1_VCOEF2_4_reg))
#define get_SE1_VCOEF2_5_reg   (*((volatile unsigned int*) SE1_VCOEF2_5_reg))
#define get_SE1_VCOEF2_6_reg   (*((volatile unsigned int*) SE1_VCOEF2_6_reg))
#define get_SE1_VCOEF2_7_reg   (*((volatile unsigned int*) SE1_VCOEF2_7_reg))
#define get_SE1_VCOEF2_8_reg   (*((volatile unsigned int*) SE1_VCOEF2_8_reg))
#define get_SE1_VCOEF2_9_reg   (*((volatile unsigned int*) SE1_VCOEF2_9_reg))
#define get_SE1_VCOEF2_10_reg   (*((volatile unsigned int*) SE1_VCOEF2_10_reg))
#define get_SE1_VCOEF2_11_reg   (*((volatile unsigned int*) SE1_VCOEF2_11_reg))
#define get_SE1_VCOEF2_12_reg   (*((volatile unsigned int*) SE1_VCOEF2_12_reg))
#define get_SE1_VCOEF2_13_reg   (*((volatile unsigned int*) SE1_VCOEF2_13_reg))
#define get_SE1_VCOEF2_14_reg   (*((volatile unsigned int*) SE1_VCOEF2_14_reg))
#define get_SE1_VCOEF2_15_reg   (*((volatile unsigned int*) SE1_VCOEF2_15_reg))
#define SE1_VCOEF2_0_inst_adr                                                         "0x0060"
#define SE1_VCOEF2_1_inst_adr                                                         "0x0061"
#define SE1_VCOEF2_2_inst_adr                                                         "0x0062"
#define SE1_VCOEF2_3_inst_adr                                                         "0x0063"
#define SE1_VCOEF2_4_inst_adr                                                         "0x0064"
#define SE1_VCOEF2_5_inst_adr                                                         "0x0065"
#define SE1_VCOEF2_6_inst_adr                                                         "0x0066"
#define SE1_VCOEF2_7_inst_adr                                                         "0x0067"
#define SE1_VCOEF2_8_inst_adr                                                         "0x0068"
#define SE1_VCOEF2_9_inst_adr                                                         "0x0069"
#define SE1_VCOEF2_10_inst_adr                                                         "0x006A"
#define SE1_VCOEF2_11_inst_adr                                                         "0x006B"
#define SE1_VCOEF2_12_inst_adr                                                         "0x006C"
#define SE1_VCOEF2_13_inst_adr                                                         "0x006D"
#define SE1_VCOEF2_14_inst_adr                                                         "0x006E"
#define SE1_VCOEF2_15_inst_adr                                                         "0x006F"
#define SE1_VCOEF2_0_inst                                                             0x0060
#define SE1_VCOEF2_1_inst                                                             0x0061
#define SE1_VCOEF2_2_inst                                                             0x0062
#define SE1_VCOEF2_3_inst                                                             0x0063
#define SE1_VCOEF2_4_inst                                                             0x0064
#define SE1_VCOEF2_5_inst                                                             0x0065
#define SE1_VCOEF2_6_inst                                                             0x0066
#define SE1_VCOEF2_7_inst                                                             0x0067
#define SE1_VCOEF2_8_inst                                                             0x0068
#define SE1_VCOEF2_9_inst                                                             0x0069
#define SE1_VCOEF2_10_inst                                                             0x006A
#define SE1_VCOEF2_11_inst                                                             0x006B
#define SE1_VCOEF2_12_inst                                                             0x006C
#define SE1_VCOEF2_13_inst                                                             0x006D
#define SE1_VCOEF2_14_inst                                                             0x006E
#define SE1_VCOEF2_15_inst                                                             0x006F
#define SE1_VCOEF2_vcoef_shift                                                        (0)
#define SE1_VCOEF2_vcoef_mask                                                         (0x00003FFF)
#define SE1_VCOEF2_vcoef(data)                                                        (0x00003FFF&((data)<<0))
#define SE1_VCOEF2_vcoef_src(data)                                                    ((0x00003FFF&(data))>>0)
#define SE1_VCOEF2_get_vcoef(data)                                                    ((0x00003FFF&(data))>>0)


#define SE1_VCOEF2_16_0                                                               0x1803E5C0
#define SE1_VCOEF2_16_1                                                               0x1803E5C4
#define SE1_VCOEF2_16_2                                                               0x1803E5C8
#define SE1_VCOEF2_16_3                                                               0x1803E5CC
#define SE1_VCOEF2_16_4                                                               0x1803E5D0
#define SE1_VCOEF2_16_5                                                               0x1803E5D4
#define SE1_VCOEF2_16_6                                                               0x1803E5D8
#define SE1_VCOEF2_16_7                                                               0x1803E5DC
#define SE1_VCOEF2_16_8                                                               0x1803E5E0
#define SE1_VCOEF2_16_9                                                               0x1803E5E4
#define SE1_VCOEF2_16_10                                                               0x1803E5E8
#define SE1_VCOEF2_16_11                                                               0x1803E5EC
#define SE1_VCOEF2_16_12                                                               0x1803E5F0
#define SE1_VCOEF2_16_13                                                               0x1803E5F4
#define SE1_VCOEF2_16_14                                                               0x1803E5F8
#define SE1_VCOEF2_16_15                                                               0x1803E5FC
#define SE1_VCOEF2_16_0_reg_addr                                                      "0xB803E5C0"
#define SE1_VCOEF2_16_1_reg_addr                                                      "0xB803E5C4"
#define SE1_VCOEF2_16_2_reg_addr                                                      "0xB803E5C8"
#define SE1_VCOEF2_16_3_reg_addr                                                      "0xB803E5CC"
#define SE1_VCOEF2_16_4_reg_addr                                                      "0xB803E5D0"
#define SE1_VCOEF2_16_5_reg_addr                                                      "0xB803E5D4"
#define SE1_VCOEF2_16_6_reg_addr                                                      "0xB803E5D8"
#define SE1_VCOEF2_16_7_reg_addr                                                      "0xB803E5DC"
#define SE1_VCOEF2_16_8_reg_addr                                                      "0xB803E5E0"
#define SE1_VCOEF2_16_9_reg_addr                                                      "0xB803E5E4"
#define SE1_VCOEF2_16_10_reg_addr                                                      "0xB803E5E8"
#define SE1_VCOEF2_16_11_reg_addr                                                      "0xB803E5EC"
#define SE1_VCOEF2_16_12_reg_addr                                                      "0xB803E5F0"
#define SE1_VCOEF2_16_13_reg_addr                                                      "0xB803E5F4"
#define SE1_VCOEF2_16_14_reg_addr                                                      "0xB803E5F8"
#define SE1_VCOEF2_16_15_reg_addr                                                      "0xB803E5FC"
#define SE1_VCOEF2_16_0_reg                                                           0xB803E5C0
#define SE1_VCOEF2_16_1_reg                                                           0xB803E5C4
#define SE1_VCOEF2_16_2_reg                                                           0xB803E5C8
#define SE1_VCOEF2_16_3_reg                                                           0xB803E5CC
#define SE1_VCOEF2_16_4_reg                                                           0xB803E5D0
#define SE1_VCOEF2_16_5_reg                                                           0xB803E5D4
#define SE1_VCOEF2_16_6_reg                                                           0xB803E5D8
#define SE1_VCOEF2_16_7_reg                                                           0xB803E5DC
#define SE1_VCOEF2_16_8_reg                                                           0xB803E5E0
#define SE1_VCOEF2_16_9_reg                                                           0xB803E5E4
#define SE1_VCOEF2_16_10_reg                                                           0xB803E5E8
#define SE1_VCOEF2_16_11_reg                                                           0xB803E5EC
#define SE1_VCOEF2_16_12_reg                                                           0xB803E5F0
#define SE1_VCOEF2_16_13_reg                                                           0xB803E5F4
#define SE1_VCOEF2_16_14_reg                                                           0xB803E5F8
#define SE1_VCOEF2_16_15_reg                                                           0xB803E5FC
#define set_SE1_VCOEF2_16_0_reg(data)   (*((volatile unsigned int*) SE1_VCOEF2_16_0_reg)=data)
#define set_SE1_VCOEF2_16_1_reg(data)   (*((volatile unsigned int*) SE1_VCOEF2_16_1_reg)=data)
#define set_SE1_VCOEF2_16_2_reg(data)   (*((volatile unsigned int*) SE1_VCOEF2_16_2_reg)=data)
#define set_SE1_VCOEF2_16_3_reg(data)   (*((volatile unsigned int*) SE1_VCOEF2_16_3_reg)=data)
#define set_SE1_VCOEF2_16_4_reg(data)   (*((volatile unsigned int*) SE1_VCOEF2_16_4_reg)=data)
#define set_SE1_VCOEF2_16_5_reg(data)   (*((volatile unsigned int*) SE1_VCOEF2_16_5_reg)=data)
#define set_SE1_VCOEF2_16_6_reg(data)   (*((volatile unsigned int*) SE1_VCOEF2_16_6_reg)=data)
#define set_SE1_VCOEF2_16_7_reg(data)   (*((volatile unsigned int*) SE1_VCOEF2_16_7_reg)=data)
#define set_SE1_VCOEF2_16_8_reg(data)   (*((volatile unsigned int*) SE1_VCOEF2_16_8_reg)=data)
#define set_SE1_VCOEF2_16_9_reg(data)   (*((volatile unsigned int*) SE1_VCOEF2_16_9_reg)=data)
#define set_SE1_VCOEF2_16_10_reg(data)   (*((volatile unsigned int*) SE1_VCOEF2_16_10_reg)=data)
#define set_SE1_VCOEF2_16_11_reg(data)   (*((volatile unsigned int*) SE1_VCOEF2_16_11_reg)=data)
#define set_SE1_VCOEF2_16_12_reg(data)   (*((volatile unsigned int*) SE1_VCOEF2_16_12_reg)=data)
#define set_SE1_VCOEF2_16_13_reg(data)   (*((volatile unsigned int*) SE1_VCOEF2_16_13_reg)=data)
#define set_SE1_VCOEF2_16_14_reg(data)   (*((volatile unsigned int*) SE1_VCOEF2_16_14_reg)=data)
#define set_SE1_VCOEF2_16_15_reg(data)   (*((volatile unsigned int*) SE1_VCOEF2_16_15_reg)=data)
#define get_SE1_VCOEF2_16_0_reg   (*((volatile unsigned int*) SE1_VCOEF2_16_0_reg))
#define get_SE1_VCOEF2_16_1_reg   (*((volatile unsigned int*) SE1_VCOEF2_16_1_reg))
#define get_SE1_VCOEF2_16_2_reg   (*((volatile unsigned int*) SE1_VCOEF2_16_2_reg))
#define get_SE1_VCOEF2_16_3_reg   (*((volatile unsigned int*) SE1_VCOEF2_16_3_reg))
#define get_SE1_VCOEF2_16_4_reg   (*((volatile unsigned int*) SE1_VCOEF2_16_4_reg))
#define get_SE1_VCOEF2_16_5_reg   (*((volatile unsigned int*) SE1_VCOEF2_16_5_reg))
#define get_SE1_VCOEF2_16_6_reg   (*((volatile unsigned int*) SE1_VCOEF2_16_6_reg))
#define get_SE1_VCOEF2_16_7_reg   (*((volatile unsigned int*) SE1_VCOEF2_16_7_reg))
#define get_SE1_VCOEF2_16_8_reg   (*((volatile unsigned int*) SE1_VCOEF2_16_8_reg))
#define get_SE1_VCOEF2_16_9_reg   (*((volatile unsigned int*) SE1_VCOEF2_16_9_reg))
#define get_SE1_VCOEF2_16_10_reg   (*((volatile unsigned int*) SE1_VCOEF2_16_10_reg))
#define get_SE1_VCOEF2_16_11_reg   (*((volatile unsigned int*) SE1_VCOEF2_16_11_reg))
#define get_SE1_VCOEF2_16_12_reg   (*((volatile unsigned int*) SE1_VCOEF2_16_12_reg))
#define get_SE1_VCOEF2_16_13_reg   (*((volatile unsigned int*) SE1_VCOEF2_16_13_reg))
#define get_SE1_VCOEF2_16_14_reg   (*((volatile unsigned int*) SE1_VCOEF2_16_14_reg))
#define get_SE1_VCOEF2_16_15_reg   (*((volatile unsigned int*) SE1_VCOEF2_16_15_reg))
#define SE1_VCOEF2_16_0_inst_adr                                                      "0x0070"
#define SE1_VCOEF2_16_1_inst_adr                                                      "0x0071"
#define SE1_VCOEF2_16_2_inst_adr                                                      "0x0072"
#define SE1_VCOEF2_16_3_inst_adr                                                      "0x0073"
#define SE1_VCOEF2_16_4_inst_adr                                                      "0x0074"
#define SE1_VCOEF2_16_5_inst_adr                                                      "0x0075"
#define SE1_VCOEF2_16_6_inst_adr                                                      "0x0076"
#define SE1_VCOEF2_16_7_inst_adr                                                      "0x0077"
#define SE1_VCOEF2_16_8_inst_adr                                                      "0x0078"
#define SE1_VCOEF2_16_9_inst_adr                                                      "0x0079"
#define SE1_VCOEF2_16_10_inst_adr                                                      "0x007A"
#define SE1_VCOEF2_16_11_inst_adr                                                      "0x007B"
#define SE1_VCOEF2_16_12_inst_adr                                                      "0x007C"
#define SE1_VCOEF2_16_13_inst_adr                                                      "0x007D"
#define SE1_VCOEF2_16_14_inst_adr                                                      "0x007E"
#define SE1_VCOEF2_16_15_inst_adr                                                      "0x007F"
#define SE1_VCOEF2_16_0_inst                                                          0x0070
#define SE1_VCOEF2_16_1_inst                                                          0x0071
#define SE1_VCOEF2_16_2_inst                                                          0x0072
#define SE1_VCOEF2_16_3_inst                                                          0x0073
#define SE1_VCOEF2_16_4_inst                                                          0x0074
#define SE1_VCOEF2_16_5_inst                                                          0x0075
#define SE1_VCOEF2_16_6_inst                                                          0x0076
#define SE1_VCOEF2_16_7_inst                                                          0x0077
#define SE1_VCOEF2_16_8_inst                                                          0x0078
#define SE1_VCOEF2_16_9_inst                                                          0x0079
#define SE1_VCOEF2_16_10_inst                                                          0x007A
#define SE1_VCOEF2_16_11_inst                                                          0x007B
#define SE1_VCOEF2_16_12_inst                                                          0x007C
#define SE1_VCOEF2_16_13_inst                                                          0x007D
#define SE1_VCOEF2_16_14_inst                                                          0x007E
#define SE1_VCOEF2_16_15_inst                                                          0x007F
#define SE1_VCOEF2_16_vcoef_shift                                                     (0)
#define SE1_VCOEF2_16_vcoef_mask                                                      (0x00003FFF)
#define SE1_VCOEF2_16_vcoef(data)                                                     (0x00003FFF&((data)<<0))
#define SE1_VCOEF2_16_vcoef_src(data)                                                 ((0x00003FFF&(data))>>0)
#define SE1_VCOEF2_16_get_vcoef(data)                                                 ((0x00003FFF&(data))>>0)


#define SE1_SC_BITBLIT_COLOR_KEY_0                                                    0x1803E900
#define SE1_SC_BITBLIT_COLOR_KEY_1                                                    0x1803E904
#define SE1_SC_BITBLIT_COLOR_KEY_0_reg_addr                                           "0xB803E900"
#define SE1_SC_BITBLIT_COLOR_KEY_1_reg_addr                                           "0xB803E904"
#define SE1_SC_BITBLIT_COLOR_KEY_0_reg                                                0xB803E900
#define SE1_SC_BITBLIT_COLOR_KEY_1_reg                                                0xB803E904
#define set_SE1_SC_BITBLIT_COLOR_KEY_0_reg(data)   (*((volatile unsigned int*) SE1_SC_BITBLIT_COLOR_KEY_0_reg)=data)
#define set_SE1_SC_BITBLIT_COLOR_KEY_1_reg(data)   (*((volatile unsigned int*) SE1_SC_BITBLIT_COLOR_KEY_1_reg)=data)
#define get_SE1_SC_BITBLIT_COLOR_KEY_0_reg   (*((volatile unsigned int*) SE1_SC_BITBLIT_COLOR_KEY_0_reg))
#define get_SE1_SC_BITBLIT_COLOR_KEY_1_reg   (*((volatile unsigned int*) SE1_SC_BITBLIT_COLOR_KEY_1_reg))
#define SE1_SC_BITBLIT_COLOR_KEY_0_inst_adr                                           "0x0040"
#define SE1_SC_BITBLIT_COLOR_KEY_1_inst_adr                                           "0x0041"
#define SE1_SC_BITBLIT_COLOR_KEY_0_inst                                               0x0040
#define SE1_SC_BITBLIT_COLOR_KEY_1_inst                                               0x0041
#define SE1_SC_BITBLIT_COLOR_KEY_color_key_shift                                      (0)
#define SE1_SC_BITBLIT_COLOR_KEY_color_key_mask                                       (0x00FFFFFF)
#define SE1_SC_BITBLIT_COLOR_KEY_color_key(data)                                      (0x00FFFFFF&((data)<<0))
#define SE1_SC_BITBLIT_COLOR_KEY_color_key_src(data)                                  ((0x00FFFFFF&(data))>>0)
#define SE1_SC_BITBLIT_COLOR_KEY_get_color_key(data)                                  ((0x00FFFFFF&(data))>>0)


#define SE1_QT_INV_MATRIX_SCALING_0                                                   0x1803EB00
#define SE1_QT_INV_MATRIX_SCALING_1                                                   0x1803EB04
#define SE1_QT_INV_MATRIX_SCALING_0_reg_addr                                          "0xB803EB00"
#define SE1_QT_INV_MATRIX_SCALING_1_reg_addr                                          "0xB803EB04"
#define SE1_QT_INV_MATRIX_SCALING_0_reg                                               0xB803EB00
#define SE1_QT_INV_MATRIX_SCALING_1_reg                                               0xB803EB04
#define set_SE1_QT_INV_MATRIX_SCALING_0_reg(data)   (*((volatile unsigned int*) SE1_QT_INV_MATRIX_SCALING_0_reg)=data)
#define set_SE1_QT_INV_MATRIX_SCALING_1_reg(data)   (*((volatile unsigned int*) SE1_QT_INV_MATRIX_SCALING_1_reg)=data)
#define get_SE1_QT_INV_MATRIX_SCALING_0_reg   (*((volatile unsigned int*) SE1_QT_INV_MATRIX_SCALING_0_reg))
#define get_SE1_QT_INV_MATRIX_SCALING_1_reg   (*((volatile unsigned int*) SE1_QT_INV_MATRIX_SCALING_1_reg))
#define SE1_QT_INV_MATRIX_SCALING_0_inst_adr                                          "0x00C0"
#define SE1_QT_INV_MATRIX_SCALING_1_inst_adr                                          "0x00C1"
#define SE1_QT_INV_MATRIX_SCALING_0_inst                                              0x00C0
#define SE1_QT_INV_MATRIX_SCALING_1_inst                                              0x00C1
#define SE1_QT_INV_MATRIX_SCALING_m22_shift                                           (16)
#define SE1_QT_INV_MATRIX_SCALING_m22_mask                                            (0xFFFF0000)
#define SE1_QT_INV_MATRIX_SCALING_m22(data)                                           (0xFFFF0000&((data)<<16))
#define SE1_QT_INV_MATRIX_SCALING_m22_src(data)                                       ((0xFFFF0000&(data))>>16)
#define SE1_QT_INV_MATRIX_SCALING_get_m22(data)                                       ((0xFFFF0000&(data))>>16)
#define SE1_QT_INV_MATRIX_SCALING_m11_shift                                           (0)
#define SE1_QT_INV_MATRIX_SCALING_m11_mask                                            (0x0000FFFF)
#define SE1_QT_INV_MATRIX_SCALING_m11(data)                                           (0x0000FFFF&((data)<<0))
#define SE1_QT_INV_MATRIX_SCALING_m11_src(data)                                       ((0x0000FFFF&(data))>>0)
#define SE1_QT_INV_MATRIX_SCALING_get_m11(data)                                       ((0x0000FFFF&(data))>>0)


#define SE1_QT_INV_MATRIX_SHEARING_0                                                  0x1803EB10
#define SE1_QT_INV_MATRIX_SHEARING_1                                                  0x1803EB14
#define SE1_QT_INV_MATRIX_SHEARING_0_reg_addr                                         "0xB803EB10"
#define SE1_QT_INV_MATRIX_SHEARING_1_reg_addr                                         "0xB803EB14"
#define SE1_QT_INV_MATRIX_SHEARING_0_reg                                              0xB803EB10
#define SE1_QT_INV_MATRIX_SHEARING_1_reg                                              0xB803EB14
#define set_SE1_QT_INV_MATRIX_SHEARING_0_reg(data)   (*((volatile unsigned int*) SE1_QT_INV_MATRIX_SHEARING_0_reg)=data)
#define set_SE1_QT_INV_MATRIX_SHEARING_1_reg(data)   (*((volatile unsigned int*) SE1_QT_INV_MATRIX_SHEARING_1_reg)=data)
#define get_SE1_QT_INV_MATRIX_SHEARING_0_reg   (*((volatile unsigned int*) SE1_QT_INV_MATRIX_SHEARING_0_reg))
#define get_SE1_QT_INV_MATRIX_SHEARING_1_reg   (*((volatile unsigned int*) SE1_QT_INV_MATRIX_SHEARING_1_reg))
#define SE1_QT_INV_MATRIX_SHEARING_0_inst_adr                                         "0x00C4"
#define SE1_QT_INV_MATRIX_SHEARING_1_inst_adr                                         "0x00C5"
#define SE1_QT_INV_MATRIX_SHEARING_0_inst                                             0x00C4
#define SE1_QT_INV_MATRIX_SHEARING_1_inst                                             0x00C5
#define SE1_QT_INV_MATRIX_SHEARING_m21_shift                                          (16)
#define SE1_QT_INV_MATRIX_SHEARING_m21_mask                                           (0xFFFF0000)
#define SE1_QT_INV_MATRIX_SHEARING_m21(data)                                          (0xFFFF0000&((data)<<16))
#define SE1_QT_INV_MATRIX_SHEARING_m21_src(data)                                      ((0xFFFF0000&(data))>>16)
#define SE1_QT_INV_MATRIX_SHEARING_get_m21(data)                                      ((0xFFFF0000&(data))>>16)
#define SE1_QT_INV_MATRIX_SHEARING_m12_shift                                          (0)
#define SE1_QT_INV_MATRIX_SHEARING_m12_mask                                           (0x0000FFFF)
#define SE1_QT_INV_MATRIX_SHEARING_m12(data)                                          (0x0000FFFF&((data)<<0))
#define SE1_QT_INV_MATRIX_SHEARING_m12_src(data)                                      ((0x0000FFFF&(data))>>0)
#define SE1_QT_INV_MATRIX_SHEARING_get_m12(data)                                      ((0x0000FFFF&(data))>>0)


#define SE1_QT_INV_MATRIX_MOVING_0                                                    0x1803EB20
#define SE1_QT_INV_MATRIX_MOVING_1                                                    0x1803EB24
#define SE1_QT_INV_MATRIX_MOVING_0_reg_addr                                           "0xB803EB20"
#define SE1_QT_INV_MATRIX_MOVING_1_reg_addr                                           "0xB803EB24"
#define SE1_QT_INV_MATRIX_MOVING_0_reg                                                0xB803EB20
#define SE1_QT_INV_MATRIX_MOVING_1_reg                                                0xB803EB24
#define set_SE1_QT_INV_MATRIX_MOVING_0_reg(data)   (*((volatile unsigned int*) SE1_QT_INV_MATRIX_MOVING_0_reg)=data)
#define set_SE1_QT_INV_MATRIX_MOVING_1_reg(data)   (*((volatile unsigned int*) SE1_QT_INV_MATRIX_MOVING_1_reg)=data)
#define get_SE1_QT_INV_MATRIX_MOVING_0_reg   (*((volatile unsigned int*) SE1_QT_INV_MATRIX_MOVING_0_reg))
#define get_SE1_QT_INV_MATRIX_MOVING_1_reg   (*((volatile unsigned int*) SE1_QT_INV_MATRIX_MOVING_1_reg))
#define SE1_QT_INV_MATRIX_MOVING_0_inst_adr                                           "0x00C8"
#define SE1_QT_INV_MATRIX_MOVING_1_inst_adr                                           "0x00C9"
#define SE1_QT_INV_MATRIX_MOVING_0_inst                                               0x00C8
#define SE1_QT_INV_MATRIX_MOVING_1_inst                                               0x00C9
#define SE1_QT_INV_MATRIX_MOVING_m32_shift                                            (16)
#define SE1_QT_INV_MATRIX_MOVING_m32_mask                                             (0xFFFF0000)
#define SE1_QT_INV_MATRIX_MOVING_m32(data)                                            (0xFFFF0000&((data)<<16))
#define SE1_QT_INV_MATRIX_MOVING_m32_src(data)                                        ((0xFFFF0000&(data))>>16)
#define SE1_QT_INV_MATRIX_MOVING_get_m32(data)                                        ((0xFFFF0000&(data))>>16)
#define SE1_QT_INV_MATRIX_MOVING_m31_shift                                            (0)
#define SE1_QT_INV_MATRIX_MOVING_m31_mask                                             (0x0000FFFF)
#define SE1_QT_INV_MATRIX_MOVING_m31(data)                                            (0x0000FFFF&((data)<<0))
#define SE1_QT_INV_MATRIX_MOVING_m31_src(data)                                        ((0x0000FFFF&(data))>>0)
#define SE1_QT_INV_MATRIX_MOVING_get_m31(data)                                        ((0x0000FFFF&(data))>>0)


#define SE1_QT_INV_MATRIX_PROJECTION_0_0                                              0x1803EB30
#define SE1_QT_INV_MATRIX_PROJECTION_0_1                                              0x1803EB34
#define SE1_QT_INV_MATRIX_PROJECTION_0_0_reg_addr                                     "0xB803EB30"
#define SE1_QT_INV_MATRIX_PROJECTION_0_1_reg_addr                                     "0xB803EB34"
#define SE1_QT_INV_MATRIX_PROJECTION_0_0_reg                                          0xB803EB30
#define SE1_QT_INV_MATRIX_PROJECTION_0_1_reg                                          0xB803EB34
#define set_SE1_QT_INV_MATRIX_PROJECTION_0_0_reg(data)   (*((volatile unsigned int*) SE1_QT_INV_MATRIX_PROJECTION_0_0_reg)=data)
#define set_SE1_QT_INV_MATRIX_PROJECTION_0_1_reg(data)   (*((volatile unsigned int*) SE1_QT_INV_MATRIX_PROJECTION_0_1_reg)=data)
#define get_SE1_QT_INV_MATRIX_PROJECTION_0_0_reg   (*((volatile unsigned int*) SE1_QT_INV_MATRIX_PROJECTION_0_0_reg))
#define get_SE1_QT_INV_MATRIX_PROJECTION_0_1_reg   (*((volatile unsigned int*) SE1_QT_INV_MATRIX_PROJECTION_0_1_reg))
#define SE1_QT_INV_MATRIX_PROJECTION_0_0_inst_adr                                     "0x00CC"
#define SE1_QT_INV_MATRIX_PROJECTION_0_1_inst_adr                                     "0x00CD"
#define SE1_QT_INV_MATRIX_PROJECTION_0_0_inst                                         0x00CC
#define SE1_QT_INV_MATRIX_PROJECTION_0_1_inst                                         0x00CD
#define SE1_QT_INV_MATRIX_PROJECTION_0_m23_shift                                      (16)
#define SE1_QT_INV_MATRIX_PROJECTION_0_m23_mask                                       (0xFFFF0000)
#define SE1_QT_INV_MATRIX_PROJECTION_0_m23(data)                                      (0xFFFF0000&((data)<<16))
#define SE1_QT_INV_MATRIX_PROJECTION_0_m23_src(data)                                  ((0xFFFF0000&(data))>>16)
#define SE1_QT_INV_MATRIX_PROJECTION_0_get_m23(data)                                  ((0xFFFF0000&(data))>>16)
#define SE1_QT_INV_MATRIX_PROJECTION_0_m13_shift                                      (0)
#define SE1_QT_INV_MATRIX_PROJECTION_0_m13_mask                                       (0x0000FFFF)
#define SE1_QT_INV_MATRIX_PROJECTION_0_m13(data)                                      (0x0000FFFF&((data)<<0))
#define SE1_QT_INV_MATRIX_PROJECTION_0_m13_src(data)                                  ((0x0000FFFF&(data))>>0)
#define SE1_QT_INV_MATRIX_PROJECTION_0_get_m13(data)                                  ((0x0000FFFF&(data))>>0)


#define SE1_QT_INV_MATRIX_PROJECTION_1_0                                              0x1803EB40
#define SE1_QT_INV_MATRIX_PROJECTION_1_1                                              0x1803EB44
#define SE1_QT_INV_MATRIX_PROJECTION_1_0_reg_addr                                     "0xB803EB40"
#define SE1_QT_INV_MATRIX_PROJECTION_1_1_reg_addr                                     "0xB803EB44"
#define SE1_QT_INV_MATRIX_PROJECTION_1_0_reg                                          0xB803EB40
#define SE1_QT_INV_MATRIX_PROJECTION_1_1_reg                                          0xB803EB44
#define set_SE1_QT_INV_MATRIX_PROJECTION_1_0_reg(data)   (*((volatile unsigned int*) SE1_QT_INV_MATRIX_PROJECTION_1_0_reg)=data)
#define set_SE1_QT_INV_MATRIX_PROJECTION_1_1_reg(data)   (*((volatile unsigned int*) SE1_QT_INV_MATRIX_PROJECTION_1_1_reg)=data)
#define get_SE1_QT_INV_MATRIX_PROJECTION_1_0_reg   (*((volatile unsigned int*) SE1_QT_INV_MATRIX_PROJECTION_1_0_reg))
#define get_SE1_QT_INV_MATRIX_PROJECTION_1_1_reg   (*((volatile unsigned int*) SE1_QT_INV_MATRIX_PROJECTION_1_1_reg))
#define SE1_QT_INV_MATRIX_PROJECTION_1_0_inst_adr                                     "0x00D0"
#define SE1_QT_INV_MATRIX_PROJECTION_1_1_inst_adr                                     "0x00D1"
#define SE1_QT_INV_MATRIX_PROJECTION_1_0_inst                                         0x00D0
#define SE1_QT_INV_MATRIX_PROJECTION_1_1_inst                                         0x00D1
#define SE1_QT_INV_MATRIX_PROJECTION_1_m33_shift                                      (0)
#define SE1_QT_INV_MATRIX_PROJECTION_1_m33_mask                                       (0x0000FFFF)
#define SE1_QT_INV_MATRIX_PROJECTION_1_m33(data)                                      (0x0000FFFF&((data)<<0))
#define SE1_QT_INV_MATRIX_PROJECTION_1_m33_src(data)                                  ((0x0000FFFF&(data))>>0)
#define SE1_QT_INV_MATRIX_PROJECTION_1_get_m33(data)                                  ((0x0000FFFF&(data))>>0)


#define SE1_SRC_LG_2_0                                                                0x1803EC20
#define SE1_SRC_LG_2_1                                                                0x1803EC24
#define SE1_SRC_LG_2_0_reg_addr                                                       "0xB803EC20"
#define SE1_SRC_LG_2_1_reg_addr                                                       "0xB803EC24"
#define SE1_SRC_LG_2_0_reg                                                            0xB803EC20
#define SE1_SRC_LG_2_1_reg                                                            0xB803EC24
#define set_SE1_SRC_LG_2_0_reg(data)   (*((volatile unsigned int*) SE1_SRC_LG_2_0_reg)=data)
#define set_SE1_SRC_LG_2_1_reg(data)   (*((volatile unsigned int*) SE1_SRC_LG_2_1_reg)=data)
#define get_SE1_SRC_LG_2_0_reg   (*((volatile unsigned int*) SE1_SRC_LG_2_0_reg))
#define get_SE1_SRC_LG_2_1_reg   (*((volatile unsigned int*) SE1_SRC_LG_2_1_reg))
#define SE1_SRC_LG_2_0_inst_adr                                                       "0x0008"
#define SE1_SRC_LG_2_1_inst_adr                                                       "0x0009"
#define SE1_SRC_LG_2_0_inst                                                           0x0008
#define SE1_SRC_LG_2_1_inst                                                           0x0009
#define SE1_SRC_LG_2_src_x_color_g_step_shift                                         (16)
#define SE1_SRC_LG_2_src_x_color_g_step_mask                                          (0x1FFF0000)
#define SE1_SRC_LG_2_src_x_color_g_step(data)                                         (0x1FFF0000&((data)<<16))
#define SE1_SRC_LG_2_src_x_color_g_step_src(data)                                     ((0x1FFF0000&(data))>>16)
#define SE1_SRC_LG_2_get_src_x_color_g_step(data)                                     ((0x1FFF0000&(data))>>16)
#define SE1_SRC_LG_2_src_x_color_r_step_shift                                         (0)
#define SE1_SRC_LG_2_src_x_color_r_step_mask                                          (0x00001FFF)
#define SE1_SRC_LG_2_src_x_color_r_step(data)                                         (0x00001FFF&((data)<<0))
#define SE1_SRC_LG_2_src_x_color_r_step_src(data)                                     ((0x00001FFF&(data))>>0)
#define SE1_SRC_LG_2_get_src_x_color_r_step(data)                                     ((0x00001FFF&(data))>>0)


#define SE1_SRC_LG_3_0                                                                0x1803EC30
#define SE1_SRC_LG_3_1                                                                0x1803EC34
#define SE1_SRC_LG_3_0_reg_addr                                                       "0xB803EC30"
#define SE1_SRC_LG_3_1_reg_addr                                                       "0xB803EC34"
#define SE1_SRC_LG_3_0_reg                                                            0xB803EC30
#define SE1_SRC_LG_3_1_reg                                                            0xB803EC34
#define set_SE1_SRC_LG_3_0_reg(data)   (*((volatile unsigned int*) SE1_SRC_LG_3_0_reg)=data)
#define set_SE1_SRC_LG_3_1_reg(data)   (*((volatile unsigned int*) SE1_SRC_LG_3_1_reg)=data)
#define get_SE1_SRC_LG_3_0_reg   (*((volatile unsigned int*) SE1_SRC_LG_3_0_reg))
#define get_SE1_SRC_LG_3_1_reg   (*((volatile unsigned int*) SE1_SRC_LG_3_1_reg))
#define SE1_SRC_LG_3_0_inst_adr                                                       "0x000C"
#define SE1_SRC_LG_3_1_inst_adr                                                       "0x000D"
#define SE1_SRC_LG_3_0_inst                                                           0x000C
#define SE1_SRC_LG_3_1_inst                                                           0x000D
#define SE1_SRC_LG_3_src_x_color_b_step_shift                                         (16)
#define SE1_SRC_LG_3_src_x_color_b_step_mask                                          (0x1FFF0000)
#define SE1_SRC_LG_3_src_x_color_b_step(data)                                         (0x1FFF0000&((data)<<16))
#define SE1_SRC_LG_3_src_x_color_b_step_src(data)                                     ((0x1FFF0000&(data))>>16)
#define SE1_SRC_LG_3_get_src_x_color_b_step(data)                                     ((0x1FFF0000&(data))>>16)
#define SE1_SRC_LG_3_src_x_alpha_step_shift                                           (0)
#define SE1_SRC_LG_3_src_x_alpha_step_mask                                            (0x00001FFF)
#define SE1_SRC_LG_3_src_x_alpha_step(data)                                           (0x00001FFF&((data)<<0))
#define SE1_SRC_LG_3_src_x_alpha_step_src(data)                                       ((0x00001FFF&(data))>>0)
#define SE1_SRC_LG_3_get_src_x_alpha_step(data)                                       ((0x00001FFF&(data))>>0)


#define SE1_SRC_LG_4_0                                                                0x1803EC40
#define SE1_SRC_LG_4_1                                                                0x1803EC44
#define SE1_SRC_LG_4_0_reg_addr                                                       "0xB803EC40"
#define SE1_SRC_LG_4_1_reg_addr                                                       "0xB803EC44"
#define SE1_SRC_LG_4_0_reg                                                            0xB803EC40
#define SE1_SRC_LG_4_1_reg                                                            0xB803EC44
#define set_SE1_SRC_LG_4_0_reg(data)   (*((volatile unsigned int*) SE1_SRC_LG_4_0_reg)=data)
#define set_SE1_SRC_LG_4_1_reg(data)   (*((volatile unsigned int*) SE1_SRC_LG_4_1_reg)=data)
#define get_SE1_SRC_LG_4_0_reg   (*((volatile unsigned int*) SE1_SRC_LG_4_0_reg))
#define get_SE1_SRC_LG_4_1_reg   (*((volatile unsigned int*) SE1_SRC_LG_4_1_reg))
#define SE1_SRC_LG_4_0_inst_adr                                                       "0x0010"
#define SE1_SRC_LG_4_1_inst_adr                                                       "0x0011"
#define SE1_SRC_LG_4_0_inst                                                           0x0010
#define SE1_SRC_LG_4_1_inst                                                           0x0011
#define SE1_SRC_LG_4_src_y_color_g_step_shift                                         (16)
#define SE1_SRC_LG_4_src_y_color_g_step_mask                                          (0x1FFF0000)
#define SE1_SRC_LG_4_src_y_color_g_step(data)                                         (0x1FFF0000&((data)<<16))
#define SE1_SRC_LG_4_src_y_color_g_step_src(data)                                     ((0x1FFF0000&(data))>>16)
#define SE1_SRC_LG_4_get_src_y_color_g_step(data)                                     ((0x1FFF0000&(data))>>16)
#define SE1_SRC_LG_4_src_y_color_r_step_shift                                         (0)
#define SE1_SRC_LG_4_src_y_color_r_step_mask                                          (0x00001FFF)
#define SE1_SRC_LG_4_src_y_color_r_step(data)                                         (0x00001FFF&((data)<<0))
#define SE1_SRC_LG_4_src_y_color_r_step_src(data)                                     ((0x00001FFF&(data))>>0)
#define SE1_SRC_LG_4_get_src_y_color_r_step(data)                                     ((0x00001FFF&(data))>>0)


#define SE1_SRC_LG_5_0                                                                0x1803EC50
#define SE1_SRC_LG_5_1                                                                0x1803EC54
#define SE1_SRC_LG_5_0_reg_addr                                                       "0xB803EC50"
#define SE1_SRC_LG_5_1_reg_addr                                                       "0xB803EC54"
#define SE1_SRC_LG_5_0_reg                                                            0xB803EC50
#define SE1_SRC_LG_5_1_reg                                                            0xB803EC54
#define set_SE1_SRC_LG_5_0_reg(data)   (*((volatile unsigned int*) SE1_SRC_LG_5_0_reg)=data)
#define set_SE1_SRC_LG_5_1_reg(data)   (*((volatile unsigned int*) SE1_SRC_LG_5_1_reg)=data)
#define get_SE1_SRC_LG_5_0_reg   (*((volatile unsigned int*) SE1_SRC_LG_5_0_reg))
#define get_SE1_SRC_LG_5_1_reg   (*((volatile unsigned int*) SE1_SRC_LG_5_1_reg))
#define SE1_SRC_LG_5_0_inst_adr                                                       "0x0014"
#define SE1_SRC_LG_5_1_inst_adr                                                       "0x0015"
#define SE1_SRC_LG_5_0_inst                                                           0x0014
#define SE1_SRC_LG_5_1_inst                                                           0x0015
#define SE1_SRC_LG_5_src_y_color_b_step_shift                                         (16)
#define SE1_SRC_LG_5_src_y_color_b_step_mask                                          (0x1FFF0000)
#define SE1_SRC_LG_5_src_y_color_b_step(data)                                         (0x1FFF0000&((data)<<16))
#define SE1_SRC_LG_5_src_y_color_b_step_src(data)                                     ((0x1FFF0000&(data))>>16)
#define SE1_SRC_LG_5_get_src_y_color_b_step(data)                                     ((0x1FFF0000&(data))>>16)
#define SE1_SRC_LG_5_src_y_alpha_step_shift                                           (0)
#define SE1_SRC_LG_5_src_y_alpha_step_mask                                            (0x00001FFF)
#define SE1_SRC_LG_5_src_y_alpha_step(data)                                           (0x00001FFF&((data)<<0))
#define SE1_SRC_LG_5_src_y_alpha_step_src(data)                                       ((0x00001FFF&(data))>>0)
#define SE1_SRC_LG_5_get_src_y_alpha_step(data)                                       ((0x00001FFF&(data))>>0)


#define SE1_SRC_LG_6_0                                                                0x1803EC60
#define SE1_SRC_LG_6_1                                                                0x1803EC64
#define SE1_SRC_LG_6_0_reg_addr                                                       "0xB803EC60"
#define SE1_SRC_LG_6_1_reg_addr                                                       "0xB803EC64"
#define SE1_SRC_LG_6_0_reg                                                            0xB803EC60
#define SE1_SRC_LG_6_1_reg                                                            0xB803EC64
#define set_SE1_SRC_LG_6_0_reg(data)   (*((volatile unsigned int*) SE1_SRC_LG_6_0_reg)=data)
#define set_SE1_SRC_LG_6_1_reg(data)   (*((volatile unsigned int*) SE1_SRC_LG_6_1_reg)=data)
#define get_SE1_SRC_LG_6_0_reg   (*((volatile unsigned int*) SE1_SRC_LG_6_0_reg))
#define get_SE1_SRC_LG_6_1_reg   (*((volatile unsigned int*) SE1_SRC_LG_6_1_reg))
#define SE1_SRC_LG_6_0_inst_adr                                                       "0x0018"
#define SE1_SRC_LG_6_1_inst_adr                                                       "0x0019"
#define SE1_SRC_LG_6_0_inst                                                           0x0018
#define SE1_SRC_LG_6_1_inst                                                           0x0019
#define SE1_SRC_LG_6_src_color_direction_shift                                        (0)
#define SE1_SRC_LG_6_src_color_direction_mask                                         (0x00000003)
#define SE1_SRC_LG_6_src_color_direction(data)                                        (0x00000003&((data)<<0))
#define SE1_SRC_LG_6_src_color_direction_src(data)                                    ((0x00000003&(data))>>0)
#define SE1_SRC_LG_6_get_src_color_direction(data)                                    ((0x00000003&(data))>>0)


#define SE1_DFB_CTRL_0                                                                0x1800ED80
#define SE1_DFB_CTRL_1                                                                0x1800ED84
#define SE1_DFB_CTRL_0_reg_addr                                                       "0xB800ED80"
#define SE1_DFB_CTRL_1_reg_addr                                                       "0xB800ED84"
#define SE1_DFB_CTRL_0_reg                                                            0xB800ED80
#define SE1_DFB_CTRL_1_reg                                                            0xB800ED84
#define set_SE1_DFB_CTRL_0_reg(data)   (*((volatile unsigned int*) SE1_DFB_CTRL_0_reg)=data)
#define set_SE1_DFB_CTRL_1_reg(data)   (*((volatile unsigned int*) SE1_DFB_CTRL_1_reg)=data)
#define get_SE1_DFB_CTRL_0_reg   (*((volatile unsigned int*) SE1_DFB_CTRL_0_reg))
#define get_SE1_DFB_CTRL_1_reg   (*((volatile unsigned int*) SE1_DFB_CTRL_1_reg))
#define SE1_DFB_CTRL_0_inst_adr                                                       "0x0060"
#define SE1_DFB_CTRL_1_inst_adr                                                       "0x0061"
#define SE1_DFB_CTRL_0_inst                                                           0x0060
#define SE1_DFB_CTRL_1_inst                                                           0x0061
#define SE1_DFB_CTRL_dst_dfb_alp_ctrl_shift                                           (1)
#define SE1_DFB_CTRL_dst_dfb_alp_ctrl_mask                                            (0x00000002)
#define SE1_DFB_CTRL_dst_dfb_alp_ctrl(data)                                           (0x00000002&((data)<<1))
#define SE1_DFB_CTRL_dst_dfb_alp_ctrl_src(data)                                       ((0x00000002&(data))>>1)
#define SE1_DFB_CTRL_get_dst_dfb_alp_ctrl(data)                                       ((0x00000002&(data))>>1)
#define SE1_DFB_CTRL_src_dfb_alp_ctrl_shift                                           (0)
#define SE1_DFB_CTRL_src_dfb_alp_ctrl_mask                                            (0x00000001)
#define SE1_DFB_CTRL_src_dfb_alp_ctrl(data)                                           (0x00000001&((data)<<0))
#define SE1_DFB_CTRL_src_dfb_alp_ctrl_src(data)                                       ((0x00000001&(data))>>0)
#define SE1_DFB_CTRL_get_src_dfb_alp_ctrl(data)                                       ((0x00000001&(data))>>0)


#define SE1_CTRL_0                                                                    0x1803E960
#define SE1_CTRL_1                                                                    0x1803E964
#define SE1_CTRL_0_reg_addr                                                           "0xB803E960"
#define SE1_CTRL_1_reg_addr                                                           "0xB803E964"
#define SE1_CTRL_0_reg                                                                0xB803E960
#define SE1_CTRL_1_reg                                                                0xB803E964
#define set_SE1_CTRL_0_reg(data)   (*((volatile unsigned int*) SE1_CTRL_0_reg)=data)
#define set_SE1_CTRL_1_reg(data)   (*((volatile unsigned int*) SE1_CTRL_1_reg)=data)
#define get_SE1_CTRL_0_reg   (*((volatile unsigned int*) SE1_CTRL_0_reg))
#define get_SE1_CTRL_1_reg   (*((volatile unsigned int*) SE1_CTRL_1_reg))
#define SE1_CTRL_0_inst_adr                                                           "0x0058"
#define SE1_CTRL_1_inst_adr                                                           "0x0059"
#define SE1_CTRL_0_inst                                                               0x0058
#define SE1_CTRL_1_inst                                                               0x0059
#define SE1_CTRL_endiswap_shift                                                       (2)
#define SE1_CTRL_endiswap_mask                                                        (0x00000004)
#define SE1_CTRL_endiswap(data)                                                       (0x00000004&((data)<<2))
#define SE1_CTRL_endiswap_src(data)                                                   ((0x00000004&(data))>>2)
#define SE1_CTRL_get_endiswap(data)                                                   ((0x00000004&(data))>>2)
#define SE1_CTRL_go_shift                                                             (1)
#define SE1_CTRL_go_mask                                                              (0x00000002)
#define SE1_CTRL_go(data)                                                             (0x00000002&((data)<<1))
#define SE1_CTRL_go_src(data)                                                         ((0x00000002&(data))>>1)
#define SE1_CTRL_get_go(data)                                                         ((0x00000002&(data))>>1)
#define SE1_CTRL_write_data_shift                                                     (0)
#define SE1_CTRL_write_data_mask                                                      (0x00000001)
#define SE1_CTRL_write_data(data)                                                     (0x00000001&((data)<<0))
#define SE1_CTRL_write_data_src(data)                                                 ((0x00000001&(data))>>0)
#define SE1_CTRL_get_write_data(data)                                                 ((0x00000001&(data))>>0)


#define SE1_IDLE_0                                                                    0x1803E970
#define SE1_IDLE_1                                                                    0x1803E974
#define SE1_IDLE_0_reg_addr                                                           "0xB803E970"
#define SE1_IDLE_1_reg_addr                                                           "0xB803E974"
#define SE1_IDLE_0_reg                                                                0xB803E970
#define SE1_IDLE_1_reg                                                                0xB803E974
#define set_SE1_IDLE_0_reg(data)   (*((volatile unsigned int*) SE1_IDLE_0_reg)=data)
#define set_SE1_IDLE_1_reg(data)   (*((volatile unsigned int*) SE1_IDLE_1_reg)=data)
#define get_SE1_IDLE_0_reg   (*((volatile unsigned int*) SE1_IDLE_0_reg))
#define get_SE1_IDLE_1_reg   (*((volatile unsigned int*) SE1_IDLE_1_reg))
#define SE1_IDLE_0_inst_adr                                                           "0x005C"
#define SE1_IDLE_1_inst_adr                                                           "0x005D"
#define SE1_IDLE_0_inst                                                               0x005C
#define SE1_IDLE_1_inst                                                               0x005D
#define SE1_IDLE_idle_shift                                                           (0)
#define SE1_IDLE_idle_mask                                                            (0x00000001)
#define SE1_IDLE_idle(data)                                                           (0x00000001&((data)<<0))
#define SE1_IDLE_idle_src(data)                                                       ((0x00000001&(data))>>0)
#define SE1_IDLE_get_idle(data)                                                       ((0x00000001&(data))>>0)


#define SE1_INTSEL                                                                    0x1803E980
#define SE1_INTSEL_reg_addr                                                           "0xB803E980"
#define SE1_INTSEL_reg                                                                0xB803E980
#define set_SE1_INTSEL_reg(data)   (*((volatile unsigned int*) SE1_INTSEL_reg)=data)
#define get_SE1_INTSEL_reg   (*((volatile unsigned int*) SE1_INTSEL_reg))
#define SE1_INTSEL_inst_adr                                                           "0x0060"
#define SE1_INTSEL_inst                                                               0x0060
#define SE1_INTSEL_sel2_shift                                                         (2)
#define SE1_INTSEL_sel2_mask                                                          (0x0000000C)
#define SE1_INTSEL_sel2(data)                                                         (0x0000000C&((data)<<2))
#define SE1_INTSEL_sel2_src(data)                                                     ((0x0000000C&(data))>>2)
#define SE1_INTSEL_get_sel2(data)                                                     ((0x0000000C&(data))>>2)
#define SE1_INTSEL_sel1_shift                                                         (0)
#define SE1_INTSEL_sel1_mask                                                          (0x00000003)
#define SE1_INTSEL_sel1(data)                                                         (0x00000003&((data)<<0))
#define SE1_INTSEL_sel1_src(data)                                                     ((0x00000003&(data))>>0)
#define SE1_INTSEL_get_sel1(data)                                                     ((0x00000003&(data))>>0)


#define SE1_INTS_0                                                                    0x1803E990
#define SE1_INTS_1                                                                    0x1803E994
#define SE1_INTS_0_reg_addr                                                           "0xB803E990"
#define SE1_INTS_1_reg_addr                                                           "0xB803E994"
#define SE1_INTS_0_reg                                                                0xB803E990
#define SE1_INTS_1_reg                                                                0xB803E994
#define set_SE1_INTS_0_reg(data)   (*((volatile unsigned int*) SE1_INTS_0_reg)=data)
#define set_SE1_INTS_1_reg(data)   (*((volatile unsigned int*) SE1_INTS_1_reg)=data)
#define get_SE1_INTS_0_reg   (*((volatile unsigned int*) SE1_INTS_0_reg))
#define get_SE1_INTS_1_reg   (*((volatile unsigned int*) SE1_INTS_1_reg))
#define SE1_INTS_0_inst_adr                                                           "0x0064"
#define SE1_INTS_1_inst_adr                                                           "0x0065"
#define SE1_INTS_0_inst                                                               0x0064
#define SE1_INTS_1_inst                                                               0x0065
#define SE1_INTS_vo_sync_err_shift                                                    (17)
#define SE1_INTS_vo_sync_err_mask                                                     (0x00020000)
#define SE1_INTS_vo_sync_err(data)                                                    (0x00020000&((data)<<17))
#define SE1_INTS_vo_sync_err_src(data)                                                ((0x00020000&(data))>>17)
#define SE1_INTS_get_vo_sync_err(data)                                                ((0x00020000&(data))>>17)
#define SE1_INTS_fmt_err_shift                                                        (16)
#define SE1_INTS_fmt_err_mask                                                         (0x00010000)
#define SE1_INTS_fmt_err(data)                                                        (0x00010000&((data)<<16))
#define SE1_INTS_fmt_err_src(data)                                                    ((0x00010000&(data))>>16)
#define SE1_INTS_get_fmt_err(data)                                                    ((0x00010000&(data))>>16)
#define SE1_INTS_com_empty_shift                                                      (3)
#define SE1_INTS_com_empty_mask                                                       (0x00000008)
#define SE1_INTS_com_empty(data)                                                      (0x00000008&((data)<<3))
#define SE1_INTS_com_empty_src(data)                                                  ((0x00000008&(data))>>3)
#define SE1_INTS_get_com_empty(data)                                                  ((0x00000008&(data))>>3)
#define SE1_INTS_com_err_shift                                                        (2)
#define SE1_INTS_com_err_mask                                                         (0x00000004)
#define SE1_INTS_com_err(data)                                                        (0x00000004&((data)<<2))
#define SE1_INTS_com_err_src(data)                                                    ((0x00000004&(data))>>2)
#define SE1_INTS_get_com_err(data)                                                    ((0x00000004&(data))>>2)
#define SE1_INTS_sync_shift                                                           (1)
#define SE1_INTS_sync_mask                                                            (0x00000002)
#define SE1_INTS_sync(data)                                                           (0x00000002&((data)<<1))
#define SE1_INTS_sync_src(data)                                                       ((0x00000002&(data))>>1)
#define SE1_INTS_get_sync(data)                                                       ((0x00000002&(data))>>1)
#define SE1_INTS_write_data_shift                                                     (0)
#define SE1_INTS_write_data_mask                                                      (0x00000001)
#define SE1_INTS_write_data(data)                                                     (0x00000001&((data)<<0))
#define SE1_INTS_write_data_src(data)                                                 ((0x00000001&(data))>>0)
#define SE1_INTS_get_write_data(data)                                                 ((0x00000001&(data))>>0)


#define SE1_INTE_0                                                                    0x1803E9A0
#define SE1_INTE_1                                                                    0x1803E9A4
#define SE1_INTE_0_reg_addr                                                           "0xB803E9A0"
#define SE1_INTE_1_reg_addr                                                           "0xB803E9A4"
#define SE1_INTE_0_reg                                                                0xB803E9A0
#define SE1_INTE_1_reg                                                                0xB803E9A4
#define set_SE1_INTE_0_reg(data)   (*((volatile unsigned int*) SE1_INTE_0_reg)=data)
#define set_SE1_INTE_1_reg(data)   (*((volatile unsigned int*) SE1_INTE_1_reg)=data)
#define get_SE1_INTE_0_reg   (*((volatile unsigned int*) SE1_INTE_0_reg))
#define get_SE1_INTE_1_reg   (*((volatile unsigned int*) SE1_INTE_1_reg))
#define SE1_INTE_0_inst_adr                                                           "0x0068"
#define SE1_INTE_1_inst_adr                                                           "0x0069"
#define SE1_INTE_0_inst                                                               0x0068
#define SE1_INTE_1_inst                                                               0x0069
#define SE1_INTE_vo_sync_err_shift                                                    (17)
#define SE1_INTE_vo_sync_err_mask                                                     (0x00020000)
#define SE1_INTE_vo_sync_err(data)                                                    (0x00020000&((data)<<17))
#define SE1_INTE_vo_sync_err_src(data)                                                ((0x00020000&(data))>>17)
#define SE1_INTE_get_vo_sync_err(data)                                                ((0x00020000&(data))>>17)
#define SE1_INTE_fmt_err_shift                                                        (16)
#define SE1_INTE_fmt_err_mask                                                         (0x00010000)
#define SE1_INTE_fmt_err(data)                                                        (0x00010000&((data)<<16))
#define SE1_INTE_fmt_err_src(data)                                                    ((0x00010000&(data))>>16)
#define SE1_INTE_get_fmt_err(data)                                                    ((0x00010000&(data))>>16)
#define SE1_INTE_com_empty_shift                                                      (3)
#define SE1_INTE_com_empty_mask                                                       (0x00000008)
#define SE1_INTE_com_empty(data)                                                      (0x00000008&((data)<<3))
#define SE1_INTE_com_empty_src(data)                                                  ((0x00000008&(data))>>3)
#define SE1_INTE_get_com_empty(data)                                                  ((0x00000008&(data))>>3)
#define SE1_INTE_com_err_shift                                                        (2)
#define SE1_INTE_com_err_mask                                                         (0x00000004)
#define SE1_INTE_com_err(data)                                                        (0x00000004&((data)<<2))
#define SE1_INTE_com_err_src(data)                                                    ((0x00000004&(data))>>2)
#define SE1_INTE_get_com_err(data)                                                    ((0x00000004&(data))>>2)
#define SE1_INTE_sync_shift                                                           (1)
#define SE1_INTE_sync_mask                                                            (0x00000002)
#define SE1_INTE_sync(data)                                                           (0x00000002&((data)<<1))
#define SE1_INTE_sync_src(data)                                                       ((0x00000002&(data))>>1)
#define SE1_INTE_get_sync(data)                                                       ((0x00000002&(data))>>1)
#define SE1_INTE_write_data_shift                                                     (0)
#define SE1_INTE_write_data_mask                                                      (0x00000001)
#define SE1_INTE_write_data(data)                                                     (0x00000001&((data)<<0))
#define SE1_INTE_write_data_src(data)                                                 ((0x00000001&(data))>>0)
#define SE1_INTE_get_write_data(data)                                                 ((0x00000001&(data))>>0)


#define SE1_INSTCNT_L_0                                                               0x1803E9B0
#define SE1_INSTCNT_L_1                                                               0x1803E9B4
#define SE1_INSTCNT_L_0_reg_addr                                                      "0xB803E9B0"
#define SE1_INSTCNT_L_1_reg_addr                                                      "0xB803E9B4"
#define SE1_INSTCNT_L_0_reg                                                           0xB803E9B0
#define SE1_INSTCNT_L_1_reg                                                           0xB803E9B4
#define set_SE1_INSTCNT_L_0_reg(data)   (*((volatile unsigned int*) SE1_INSTCNT_L_0_reg)=data)
#define set_SE1_INSTCNT_L_1_reg(data)   (*((volatile unsigned int*) SE1_INSTCNT_L_1_reg)=data)
#define get_SE1_INSTCNT_L_0_reg   (*((volatile unsigned int*) SE1_INSTCNT_L_0_reg))
#define get_SE1_INSTCNT_L_1_reg   (*((volatile unsigned int*) SE1_INSTCNT_L_1_reg))
#define SE1_INSTCNT_L_0_inst_adr                                                      "0x006C"
#define SE1_INSTCNT_L_1_inst_adr                                                      "0x006D"
#define SE1_INSTCNT_L_0_inst                                                          0x006C
#define SE1_INSTCNT_L_1_inst                                                          0x006D
#define SE1_INSTCNT_L_instcnt_l_shift                                                 (0)
#define SE1_INSTCNT_L_instcnt_l_mask                                                  (0xFFFFFFFF)
#define SE1_INSTCNT_L_instcnt_l(data)                                                 (0xFFFFFFFF&((data)<<0))
#define SE1_INSTCNT_L_instcnt_l_src(data)                                             ((0xFFFFFFFF&(data))>>0)
#define SE1_INSTCNT_L_get_instcnt_l(data)                                             ((0xFFFFFFFF&(data))>>0)


#define SE1_INSTCNT_H_0                                                               0x1803E9C0
#define SE1_INSTCNT_H_1                                                               0x1803E9C4
#define SE1_INSTCNT_H_0_reg_addr                                                      "0xB803E9C0"
#define SE1_INSTCNT_H_1_reg_addr                                                      "0xB803E9C4"
#define SE1_INSTCNT_H_0_reg                                                           0xB803E9C0
#define SE1_INSTCNT_H_1_reg                                                           0xB803E9C4
#define set_SE1_INSTCNT_H_0_reg(data)   (*((volatile unsigned int*) SE1_INSTCNT_H_0_reg)=data)
#define set_SE1_INSTCNT_H_1_reg(data)   (*((volatile unsigned int*) SE1_INSTCNT_H_1_reg)=data)
#define get_SE1_INSTCNT_H_0_reg   (*((volatile unsigned int*) SE1_INSTCNT_H_0_reg))
#define get_SE1_INSTCNT_H_1_reg   (*((volatile unsigned int*) SE1_INSTCNT_H_1_reg))
#define SE1_INSTCNT_H_0_inst_adr                                                      "0x0070"
#define SE1_INSTCNT_H_1_inst_adr                                                      "0x0071"
#define SE1_INSTCNT_H_0_inst                                                          0x0070
#define SE1_INSTCNT_H_1_inst                                                          0x0071
#define SE1_INSTCNT_H_instcnt_h_shift                                                 (0)
#define SE1_INSTCNT_H_instcnt_h_mask                                                  (0xFFFFFFFF)
#define SE1_INSTCNT_H_instcnt_h(data)                                                 (0xFFFFFFFF&((data)<<0))
#define SE1_INSTCNT_H_instcnt_h_src(data)                                             ((0xFFFFFFFF&(data))>>0)
#define SE1_INSTCNT_H_get_instcnt_h(data)                                             ((0xFFFFFFFF&(data))>>0)


#define SE1_CLUT_RADR                                                                 0x1803E9D0
#define SE1_CLUT_RADR_reg_addr                                                        "0xB803E9D0"
#define SE1_CLUT_RADR_reg                                                             0xB803E9D0
#define set_SE1_CLUT_RADR_reg(data)   (*((volatile unsigned int*) SE1_CLUT_RADR_reg)=data)
#define get_SE1_CLUT_RADR_reg   (*((volatile unsigned int*) SE1_CLUT_RADR_reg))
#define SE1_CLUT_RADR_inst_adr                                                        "0x0074"
#define SE1_CLUT_RADR_inst                                                            0x0074
#define SE1_CLUT_RADR_radr_shift                                                      (0)
#define SE1_CLUT_RADR_radr_mask                                                       (0x000000FF)
#define SE1_CLUT_RADR_radr(data)                                                      (0x000000FF&((data)<<0))
#define SE1_CLUT_RADR_radr_src(data)                                                  ((0x000000FF&(data))>>0)
#define SE1_CLUT_RADR_get_radr(data)                                                  ((0x000000FF&(data))>>0)


#define SE1_CLUT_VALUE                                                                0x1803E9D4
#define SE1_CLUT_VALUE_reg_addr                                                       "0xB803E9D4"
#define SE1_CLUT_VALUE_reg                                                            0xB803E9D4
#define set_SE1_CLUT_VALUE_reg(data)   (*((volatile unsigned int*) SE1_CLUT_VALUE_reg)=data)
#define get_SE1_CLUT_VALUE_reg   (*((volatile unsigned int*) SE1_CLUT_VALUE_reg))
#define SE1_CLUT_VALUE_inst_adr                                                       "0x0075"
#define SE1_CLUT_VALUE_inst                                                           0x0075
#define SE1_CLUT_VALUE_value_shift                                                    (0)
#define SE1_CLUT_VALUE_value_mask                                                     (0xFFFFFFFF)
#define SE1_CLUT_VALUE_value(data)                                                    (0xFFFFFFFF&((data)<<0))
#define SE1_CLUT_VALUE_value_src(data)                                                ((0xFFFFFFFF&(data))>>0)
#define SE1_CLUT_VALUE_get_value(data)                                                ((0xFFFFFFFF&(data))>>0)


#define SE1_DBG                                                                       0x1803E9D8
#define SE1_DBG_reg_addr                                                              "0xB803E9D8"
#define SE1_DBG_reg                                                                   0xB803E9D8
#define set_SE1_DBG_reg(data)   (*((volatile unsigned int*) SE1_DBG_reg)=data)
#define get_SE1_DBG_reg   (*((volatile unsigned int*) SE1_DBG_reg))
#define SE1_DBG_inst_adr                                                              "0x0076"
#define SE1_DBG_inst                                                                  0x0076
#define SE1_DBG_dbg_change_shift                                                      (25)
#define SE1_DBG_dbg_change_mask                                                       (0x02000000)
#define SE1_DBG_dbg_change(data)                                                      (0x02000000&((data)<<25))
#define SE1_DBG_dbg_change_src(data)                                                  ((0x02000000&(data))>>25)
#define SE1_DBG_get_dbg_change(data)                                                  ((0x02000000&(data))>>25)
#define SE1_DBG_dbg_en_shift                                                          (24)
#define SE1_DBG_dbg_en_mask                                                           (0x01000000)
#define SE1_DBG_dbg_en(data)                                                          (0x01000000&((data)<<24))
#define SE1_DBG_dbg_en_src(data)                                                      ((0x01000000&(data))>>24)
#define SE1_DBG_get_dbg_en(data)                                                      ((0x01000000&(data))>>24)
#define SE1_DBG_dbg_module_sel1_shift                                                 (20)
#define SE1_DBG_dbg_module_sel1_mask                                                  (0x00F00000)
#define SE1_DBG_dbg_module_sel1(data)                                                 (0x00F00000&((data)<<20))
#define SE1_DBG_dbg_module_sel1_src(data)                                             ((0x00F00000&(data))>>20)
#define SE1_DBG_get_dbg_module_sel1(data)                                             ((0x00F00000&(data))>>20)
#define SE1_DBG_dbg_module_sel0_shift                                                 (16)
#define SE1_DBG_dbg_module_sel0_mask                                                  (0x000F0000)
#define SE1_DBG_dbg_module_sel0(data)                                                 (0x000F0000&((data)<<16))
#define SE1_DBG_dbg_module_sel0_src(data)                                             ((0x000F0000&(data))>>16)
#define SE1_DBG_get_dbg_module_sel0(data)                                             ((0x000F0000&(data))>>16)
#define SE1_DBG_dbg_sel1_shift                                                        (8)
#define SE1_DBG_dbg_sel1_mask                                                         (0x00001F00)
#define SE1_DBG_dbg_sel1(data)                                                        (0x00001F00&((data)<<8))
#define SE1_DBG_dbg_sel1_src(data)                                                    ((0x00001F00&(data))>>8)
#define SE1_DBG_get_dbg_sel1(data)                                                    ((0x00001F00&(data))>>8)
#define SE1_DBG_dbg_sel0_shift                                                        (0)
#define SE1_DBG_dbg_sel0_mask                                                         (0x0000001F)
#define SE1_DBG_dbg_sel0(data)                                                        (0x0000001F&((data)<<0))
#define SE1_DBG_dbg_sel0_src(data)                                                    ((0x0000001F&(data))>>0)
#define SE1_DBG_get_dbg_sel0(data)                                                    ((0x0000001F&(data))>>0)


#define SE1_SCTCH                                                                     0x1803E9DC
#define SE1_SCTCH_reg_addr                                                            "0xB803E9DC"
#define SE1_SCTCH_reg                                                                 0xB803E9DC
#define set_SE1_SCTCH_reg(data)   (*((volatile unsigned int*) SE1_SCTCH_reg)=data)
#define get_SE1_SCTCH_reg   (*((volatile unsigned int*) SE1_SCTCH_reg))
#define SE1_SCTCH_inst_adr                                                            "0x0077"
#define SE1_SCTCH_inst                                                                0x0077
#define SE1_SCTCH_Reg1_shift                                                          (16)
#define SE1_SCTCH_Reg1_mask                                                           (0xFFFF0000)
#define SE1_SCTCH_Reg1(data)                                                          (0xFFFF0000&((data)<<16))
#define SE1_SCTCH_Reg1_src(data)                                                      ((0xFFFF0000&(data))>>16)
#define SE1_SCTCH_get_Reg1(data)                                                      ((0xFFFF0000&(data))>>16)
#define SE1_SCTCH_Reg0_shift                                                          (0)
#define SE1_SCTCH_Reg0_mask                                                           (0x0000FFFF)
#define SE1_SCTCH_Reg0(data)                                                          (0x0000FFFF&((data)<<0))
#define SE1_SCTCH_Reg0_src(data)                                                      ((0x0000FFFF&(data))>>0)
#define SE1_SCTCH_get_Reg0(data)                                                      ((0x0000FFFF&(data))>>0)


#define SE1_READ_MARGIN                                                               0x1803EA00
#define SE1_READ_MARGIN_reg_addr                                                      "0xB803EA00"
#define SE1_READ_MARGIN_reg                                                           0xB803EA00
#define set_SE1_READ_MARGIN_reg(data)   (*((volatile unsigned int*) SE1_READ_MARGIN_reg)=data)
#define get_SE1_READ_MARGIN_reg   (*((volatile unsigned int*) SE1_READ_MARGIN_reg))
#define SE1_READ_MARGIN_inst_adr                                                      "0x0080"
#define SE1_READ_MARGIN_inst                                                          0x0080
#define SE1_READ_MARGIN_ls_shift                                                      (5)
#define SE1_READ_MARGIN_ls_mask                                                       (0x00000020)
#define SE1_READ_MARGIN_ls(data)                                                      (0x00000020&((data)<<5))
#define SE1_READ_MARGIN_ls_src(data)                                                  ((0x00000020&(data))>>5)
#define SE1_READ_MARGIN_get_ls(data)                                                  ((0x00000020&(data))>>5)
#define SE1_READ_MARGIN_rm_shift                                                      (1)
#define SE1_READ_MARGIN_rm_mask                                                       (0x0000001E)
#define SE1_READ_MARGIN_rm(data)                                                      (0x0000001E&((data)<<1))
#define SE1_READ_MARGIN_rm_src(data)                                                  ((0x0000001E&(data))>>1)
#define SE1_READ_MARGIN_get_rm(data)                                                  ((0x0000001E&(data))>>1)
#define SE1_READ_MARGIN_rme_shift                                                     (0)
#define SE1_READ_MARGIN_rme_mask                                                      (0x00000001)
#define SE1_READ_MARGIN_rme(data)                                                     (0x00000001&((data)<<0))
#define SE1_READ_MARGIN_rme_src(data)                                                 ((0x00000001&(data))>>0)
#define SE1_READ_MARGIN_get_rme(data)                                                 ((0x00000001&(data))>>0)


#define SE1_SE1_BIST_MODE                                                              0x1803EA04
#define SE1_SE1_BIST_MODE_reg_addr                                                     "0xB803EA04"
#define SE1_SE1_BIST_MODE_reg                                                          0xB803EA04
#define set_SE1_SE1_BIST_MODE_reg(data)   (*((volatile unsigned int*) SE1_SE1_BIST_MODE_reg)=data)
#define get_SE1_SE1_BIST_MODE_reg   (*((volatile unsigned int*) SE1_SE1_BIST_MODE_reg))
#define SE1_SE1_BIST_MODE_inst_adr                                                     "0x0081"
#define SE1_SE1_BIST_MODE_inst                                                         0x0081
#define SE1_SE1_BIST_MODE_se1_bist_mode_1_shift                                         (1)
#define SE1_SE1_BIST_MODE_se1_bist_mode_1_mask                                          (0x00000002)
#define SE1_SE1_BIST_MODE_se1_bist_mode_1(data)                                         (0x00000002&((data)<<1))
#define SE1_SE1_BIST_MODE_se1_bist_mode_1_src(data)                                     ((0x00000002&(data))>>1)
#define SE1_SE1_BIST_MODE_get_se1_bist_mode_1(data)                                     ((0x00000002&(data))>>1)
#define SE1_SE1_BIST_MODE_se1_bist_mode_0_shift                                         (0)
#define SE1_SE1_BIST_MODE_se1_bist_mode_0_mask                                          (0x00000001)
#define SE1_SE1_BIST_MODE_se1_bist_mode_0(data)                                         (0x00000001&((data)<<0))
#define SE1_SE1_BIST_MODE_se1_bist_mode_0_src(data)                                     ((0x00000001&(data))>>0)
#define SE1_SE1_BIST_MODE_get_se1_bist_mode_0(data)                                     ((0x00000001&(data))>>0)


#define SE1_SE1_BIST_DONE                                                              0x1803EA08
#define SE1_SE1_BIST_DONE_reg_addr                                                     "0xB803EA08"
#define SE1_SE1_BIST_DONE_reg                                                          0xB803EA08
#define set_SE1_SE1_BIST_DONE_reg(data)   (*((volatile unsigned int*) SE1_SE1_BIST_DONE_reg)=data)
#define get_SE1_SE1_BIST_DONE_reg   (*((volatile unsigned int*) SE1_SE1_BIST_DONE_reg))
#define SE1_SE1_BIST_DONE_inst_adr                                                     "0x0082"
#define SE1_SE1_BIST_DONE_inst                                                         0x0082
#define SE1_SE1_BIST_DONE_se1_bist_done_1_shift                                         (1)
#define SE1_SE1_BIST_DONE_se1_bist_done_1_mask                                          (0x00000002)
#define SE1_SE1_BIST_DONE_se1_bist_done_1(data)                                         (0x00000002&((data)<<1))
#define SE1_SE1_BIST_DONE_se1_bist_done_1_src(data)                                     ((0x00000002&(data))>>1)
#define SE1_SE1_BIST_DONE_get_se1_bist_done_1(data)                                     ((0x00000002&(data))>>1)
#define SE1_SE1_BIST_DONE_se1_bist_done_0_shift                                         (0)
#define SE1_SE1_BIST_DONE_se1_bist_done_0_mask                                          (0x00000001)
#define SE1_SE1_BIST_DONE_se1_bist_done_0(data)                                         (0x00000001&((data)<<0))
#define SE1_SE1_BIST_DONE_se1_bist_done_0_src(data)                                     ((0x00000001&(data))>>0)
#define SE1_SE1_BIST_DONE_get_se1_bist_done_0(data)                                     ((0x00000001&(data))>>0)


#define SE1_SE1_BIST_FAIL_GROUP                                                        0x1803EA0C
#define SE1_SE1_BIST_FAIL_GROUP_reg_addr                                               "0xB803EA0C"
#define SE1_SE1_BIST_FAIL_GROUP_reg                                                    0xB803EA0C
#define set_SE1_SE1_BIST_FAIL_GROUP_reg(data)   (*((volatile unsigned int*) SE1_SE1_BIST_FAIL_GROUP_reg)=data)
#define get_SE1_SE1_BIST_FAIL_GROUP_reg   (*((volatile unsigned int*) SE1_SE1_BIST_FAIL_GROUP_reg))
#define SE1_SE1_BIST_FAIL_GROUP_inst_adr                                               "0x0083"
#define SE1_SE1_BIST_FAIL_GROUP_inst                                                   0x0083
#define SE1_SE1_BIST_FAIL_GROUP_se1_bist_fail_group_1_shift                             (1)
#define SE1_SE1_BIST_FAIL_GROUP_se1_bist_fail_group_1_mask                              (0x00000002)
#define SE1_SE1_BIST_FAIL_GROUP_se1_bist_fail_group_1(data)                             (0x00000002&((data)<<1))
#define SE1_SE1_BIST_FAIL_GROUP_se1_bist_fail_group_1_src(data)                         ((0x00000002&(data))>>1)
#define SE1_SE1_BIST_FAIL_GROUP_get_se1_bist_fail_group_1(data)                         ((0x00000002&(data))>>1)
#define SE1_SE1_BIST_FAIL_GROUP_se1_bist_fail_group_0_shift                             (0)
#define SE1_SE1_BIST_FAIL_GROUP_se1_bist_fail_group_0_mask                              (0x00000001)
#define SE1_SE1_BIST_FAIL_GROUP_se1_bist_fail_group_0(data)                             (0x00000001&((data)<<0))
#define SE1_SE1_BIST_FAIL_GROUP_se1_bist_fail_group_0_src(data)                         ((0x00000001&(data))>>0)
#define SE1_SE1_BIST_FAIL_GROUP_get_se1_bist_fail_group_0(data)                         ((0x00000001&(data))>>0)


#define SE1_SE1_BIST_0_FAIL                                                            0x1803EA10
#define SE1_SE1_BIST_0_FAIL_reg_addr                                                   "0xB803EA10"
#define SE1_SE1_BIST_0_FAIL_reg                                                        0xB803EA10
#define set_SE1_SE1_BIST_0_FAIL_reg(data)   (*((volatile unsigned int*) SE1_SE1_BIST_0_FAIL_reg)=data)
#define get_SE1_SE1_BIST_0_FAIL_reg   (*((volatile unsigned int*) SE1_SE1_BIST_0_FAIL_reg))
#define SE1_SE1_BIST_0_FAIL_inst_adr                                                   "0x0084"
#define SE1_SE1_BIST_0_FAIL_inst                                                       0x0084
#define SE1_SE1_BIST_0_FAIL_se1_bist_0_fail_8_shift                                     (8)
#define SE1_SE1_BIST_0_FAIL_se1_bist_0_fail_8_mask                                      (0x00000100)
#define SE1_SE1_BIST_0_FAIL_se1_bist_0_fail_8(data)                                     (0x00000100&((data)<<8))
#define SE1_SE1_BIST_0_FAIL_se1_bist_0_fail_8_src(data)                                 ((0x00000100&(data))>>8)
#define SE1_SE1_BIST_0_FAIL_get_se1_bist_0_fail_8(data)                                 ((0x00000100&(data))>>8)
#define SE1_SE1_BIST_0_FAIL_se1_bist_0_fail_7_shift                                     (7)
#define SE1_SE1_BIST_0_FAIL_se1_bist_0_fail_7_mask                                      (0x00000080)
#define SE1_SE1_BIST_0_FAIL_se1_bist_0_fail_7(data)                                     (0x00000080&((data)<<7))
#define SE1_SE1_BIST_0_FAIL_se1_bist_0_fail_7_src(data)                                 ((0x00000080&(data))>>7)
#define SE1_SE1_BIST_0_FAIL_get_se1_bist_0_fail_7(data)                                 ((0x00000080&(data))>>7)
#define SE1_SE1_BIST_0_FAIL_se1_bist_0_fail_6_shift                                     (6)
#define SE1_SE1_BIST_0_FAIL_se1_bist_0_fail_6_mask                                      (0x00000040)
#define SE1_SE1_BIST_0_FAIL_se1_bist_0_fail_6(data)                                     (0x00000040&((data)<<6))
#define SE1_SE1_BIST_0_FAIL_se1_bist_0_fail_6_src(data)                                 ((0x00000040&(data))>>6)
#define SE1_SE1_BIST_0_FAIL_get_se1_bist_0_fail_6(data)                                 ((0x00000040&(data))>>6)
#define SE1_SE1_BIST_0_FAIL_se1_bist_0_fail_5_shift                                     (5)
#define SE1_SE1_BIST_0_FAIL_se1_bist_0_fail_5_mask                                      (0x00000020)
#define SE1_SE1_BIST_0_FAIL_se1_bist_0_fail_5(data)                                     (0x00000020&((data)<<5))
#define SE1_SE1_BIST_0_FAIL_se1_bist_0_fail_5_src(data)                                 ((0x00000020&(data))>>5)
#define SE1_SE1_BIST_0_FAIL_get_se1_bist_0_fail_5(data)                                 ((0x00000020&(data))>>5)
#define SE1_SE1_BIST_0_FAIL_se1_bist_0_fail_4_shift                                     (4)
#define SE1_SE1_BIST_0_FAIL_se1_bist_0_fail_4_mask                                      (0x00000010)
#define SE1_SE1_BIST_0_FAIL_se1_bist_0_fail_4(data)                                     (0x00000010&((data)<<4))
#define SE1_SE1_BIST_0_FAIL_se1_bist_0_fail_4_src(data)                                 ((0x00000010&(data))>>4)
#define SE1_SE1_BIST_0_FAIL_get_se1_bist_0_fail_4(data)                                 ((0x00000010&(data))>>4)
#define SE1_SE1_BIST_0_FAIL_se1_bist_0_fail_3_shift                                     (3)
#define SE1_SE1_BIST_0_FAIL_se1_bist_0_fail_3_mask                                      (0x00000008)
#define SE1_SE1_BIST_0_FAIL_se1_bist_0_fail_3(data)                                     (0x00000008&((data)<<3))
#define SE1_SE1_BIST_0_FAIL_se1_bist_0_fail_3_src(data)                                 ((0x00000008&(data))>>3)
#define SE1_SE1_BIST_0_FAIL_get_se1_bist_0_fail_3(data)                                 ((0x00000008&(data))>>3)
#define SE1_SE1_BIST_0_FAIL_se1_bist_0_fail_2_shift                                     (2)
#define SE1_SE1_BIST_0_FAIL_se1_bist_0_fail_2_mask                                      (0x00000004)
#define SE1_SE1_BIST_0_FAIL_se1_bist_0_fail_2(data)                                     (0x00000004&((data)<<2))
#define SE1_SE1_BIST_0_FAIL_se1_bist_0_fail_2_src(data)                                 ((0x00000004&(data))>>2)
#define SE1_SE1_BIST_0_FAIL_get_se1_bist_0_fail_2(data)                                 ((0x00000004&(data))>>2)
#define SE1_SE1_BIST_0_FAIL_se1_bist_0_fail_1_shift                                     (1)
#define SE1_SE1_BIST_0_FAIL_se1_bist_0_fail_1_mask                                      (0x00000002)
#define SE1_SE1_BIST_0_FAIL_se1_bist_0_fail_1(data)                                     (0x00000002&((data)<<1))
#define SE1_SE1_BIST_0_FAIL_se1_bist_0_fail_1_src(data)                                 ((0x00000002&(data))>>1)
#define SE1_SE1_BIST_0_FAIL_get_se1_bist_0_fail_1(data)                                 ((0x00000002&(data))>>1)
#define SE1_SE1_BIST_0_FAIL_se1_bist_0_fail_0_shift                                     (0)
#define SE1_SE1_BIST_0_FAIL_se1_bist_0_fail_0_mask                                      (0x00000001)
#define SE1_SE1_BIST_0_FAIL_se1_bist_0_fail_0(data)                                     (0x00000001&((data)<<0))
#define SE1_SE1_BIST_0_FAIL_se1_bist_0_fail_0_src(data)                                 ((0x00000001&(data))>>0)
#define SE1_SE1_BIST_0_FAIL_get_se1_bist_0_fail_0(data)                                 ((0x00000001&(data))>>0)


#define SE1_SE1_BIST_1_FAIL                                                            0x1803EA14
#define SE1_SE1_BIST_1_FAIL_reg_addr                                                   "0xB803EA14"
#define SE1_SE1_BIST_1_FAIL_reg                                                        0xB803EA14
#define set_SE1_SE1_BIST_1_FAIL_reg(data)   (*((volatile unsigned int*) SE1_SE1_BIST_1_FAIL_reg)=data)
#define get_SE1_SE1_BIST_1_FAIL_reg   (*((volatile unsigned int*) SE1_SE1_BIST_1_FAIL_reg))
#define SE1_SE1_BIST_1_FAIL_inst_adr                                                   "0x0085"
#define SE1_SE1_BIST_1_FAIL_inst                                                       0x0085
#define SE1_SE1_BIST_1_FAIL_se1_bist_1_fail_1_shift                                     (1)
#define SE1_SE1_BIST_1_FAIL_se1_bist_1_fail_1_mask                                      (0x00000002)
#define SE1_SE1_BIST_1_FAIL_se1_bist_1_fail_1(data)                                     (0x00000002&((data)<<1))
#define SE1_SE1_BIST_1_FAIL_se1_bist_1_fail_1_src(data)                                 ((0x00000002&(data))>>1)
#define SE1_SE1_BIST_1_FAIL_get_se1_bist_1_fail_1(data)                                 ((0x00000002&(data))>>1)
#define SE1_SE1_BIST_1_FAIL_se1_bist_1_fail_0_shift                                     (0)
#define SE1_SE1_BIST_1_FAIL_se1_bist_1_fail_0_mask                                      (0x00000001)
#define SE1_SE1_BIST_1_FAIL_se1_bist_1_fail_0(data)                                     (0x00000001&((data)<<0))
#define SE1_SE1_BIST_1_FAIL_se1_bist_1_fail_0_src(data)                                 ((0x00000001&(data))>>0)
#define SE1_SE1_BIST_1_FAIL_get_se1_bist_1_fail_0(data)                                 ((0x00000001&(data))>>0)


#define SE1_SE1_DRF_MODE                                                               0x1803EA18
#define SE1_SE1_DRF_MODE_reg_addr                                                      "0xB803EA18"
#define SE1_SE1_DRF_MODE_reg                                                           0xB803EA18
#define set_SE1_SE1_DRF_MODE_reg(data)   (*((volatile unsigned int*) SE1_SE1_DRF_MODE_reg)=data)
#define get_SE1_SE1_DRF_MODE_reg   (*((volatile unsigned int*) SE1_SE1_DRF_MODE_reg))
#define SE1_SE1_DRF_MODE_inst_adr                                                      "0x0086"
#define SE1_SE1_DRF_MODE_inst                                                          0x0086
#define SE1_SE1_DRF_MODE_se1_drf_mode_1_shift                                           (1)
#define SE1_SE1_DRF_MODE_se1_drf_mode_1_mask                                            (0x00000002)
#define SE1_SE1_DRF_MODE_se1_drf_mode_1(data)                                           (0x00000002&((data)<<1))
#define SE1_SE1_DRF_MODE_se1_drf_mode_1_src(data)                                       ((0x00000002&(data))>>1)
#define SE1_SE1_DRF_MODE_get_se1_drf_mode_1(data)                                       ((0x00000002&(data))>>1)
#define SE1_SE1_DRF_MODE_se1_drf_mode_0_shift                                           (0)
#define SE1_SE1_DRF_MODE_se1_drf_mode_0_mask                                            (0x00000001)
#define SE1_SE1_DRF_MODE_se1_drf_mode_0(data)                                           (0x00000001&((data)<<0))
#define SE1_SE1_DRF_MODE_se1_drf_mode_0_src(data)                                       ((0x00000001&(data))>>0)
#define SE1_SE1_DRF_MODE_get_se1_drf_mode_0(data)                                       ((0x00000001&(data))>>0)


#define SE1_SE1_DRF_RESUME                                                             0x1803EA1C
#define SE1_SE1_DRF_RESUME_reg_addr                                                    "0xB803EA1C"
#define SE1_SE1_DRF_RESUME_reg                                                         0xB803EA1C
#define set_SE1_SE1_DRF_RESUME_reg(data)   (*((volatile unsigned int*) SE1_SE1_DRF_RESUME_reg)=data)
#define get_SE1_SE1_DRF_RESUME_reg   (*((volatile unsigned int*) SE1_SE1_DRF_RESUME_reg))
#define SE1_SE1_DRF_RESUME_inst_adr                                                    "0x0087"
#define SE1_SE1_DRF_RESUME_inst                                                        0x0087
#define SE1_SE1_DRF_RESUME_se1_drf_resume_1_shift                                       (1)
#define SE1_SE1_DRF_RESUME_se1_drf_resume_1_mask                                        (0x00000002)
#define SE1_SE1_DRF_RESUME_se1_drf_resume_1(data)                                       (0x00000002&((data)<<1))
#define SE1_SE1_DRF_RESUME_se1_drf_resume_1_src(data)                                   ((0x00000002&(data))>>1)
#define SE1_SE1_DRF_RESUME_get_se1_drf_resume_1(data)                                   ((0x00000002&(data))>>1)
#define SE1_SE1_DRF_RESUME_se1_drf_resume_0_shift                                       (0)
#define SE1_SE1_DRF_RESUME_se1_drf_resume_0_mask                                        (0x00000001)
#define SE1_SE1_DRF_RESUME_se1_drf_resume_0(data)                                       (0x00000001&((data)<<0))
#define SE1_SE1_DRF_RESUME_se1_drf_resume_0_src(data)                                   ((0x00000001&(data))>>0)
#define SE1_SE1_DRF_RESUME_get_se1_drf_resume_0(data)                                   ((0x00000001&(data))>>0)


#define SE1_SE1_DRF_DONE                                                               0x1803EA20
#define SE1_SE1_DRF_DONE_reg_addr                                                      "0xB803EA20"
#define SE1_SE1_DRF_DONE_reg                                                           0xB803EA20
#define set_SE1_SE1_DRF_DONE_reg(data)   (*((volatile unsigned int*) SE1_SE1_DRF_DONE_reg)=data)
#define get_SE1_SE1_DRF_DONE_reg   (*((volatile unsigned int*) SE1_SE1_DRF_DONE_reg))
#define SE1_SE1_DRF_DONE_inst_adr                                                      "0x0088"
#define SE1_SE1_DRF_DONE_inst                                                          0x0088
#define SE1_SE1_DRF_DONE_se1_drf_done_1_shift                                           (1)
#define SE1_SE1_DRF_DONE_se1_drf_done_1_mask                                            (0x00000002)
#define SE1_SE1_DRF_DONE_se1_drf_done_1(data)                                           (0x00000002&((data)<<1))
#define SE1_SE1_DRF_DONE_se1_drf_done_1_src(data)                                       ((0x00000002&(data))>>1)
#define SE1_SE1_DRF_DONE_get_se1_drf_done_1(data)                                       ((0x00000002&(data))>>1)
#define SE1_SE1_DRF_DONE_se1_drf_done_0_shift                                           (0)
#define SE1_SE1_DRF_DONE_se1_drf_done_0_mask                                            (0x00000001)
#define SE1_SE1_DRF_DONE_se1_drf_done_0(data)                                           (0x00000001&((data)<<0))
#define SE1_SE1_DRF_DONE_se1_drf_done_0_src(data)                                       ((0x00000001&(data))>>0)
#define SE1_SE1_DRF_DONE_get_se1_drf_done_0(data)                                       ((0x00000001&(data))>>0)


#define SE1_SE1_DRF_PAUSE                                                              0x1803EA24
#define SE1_SE1_DRF_PAUSE_reg_addr                                                     "0xB803EA24"
#define SE1_SE1_DRF_PAUSE_reg                                                          0xB803EA24
#define set_SE1_SE1_DRF_PAUSE_reg(data)   (*((volatile unsigned int*) SE1_SE1_DRF_PAUSE_reg)=data)
#define get_SE1_SE1_DRF_PAUSE_reg   (*((volatile unsigned int*) SE1_SE1_DRF_PAUSE_reg))
#define SE1_SE1_DRF_PAUSE_inst_adr                                                     "0x0089"
#define SE1_SE1_DRF_PAUSE_inst                                                         0x0089
#define SE1_SE1_DRF_PAUSE_se1_drf_pause1_1_shift                                         (1)
#define SE1_SE1_DRF_PAUSE_se1_drf_pause1_1_mask                                          (0x00000002)
#define SE1_SE1_DRF_PAUSE_se1_drf_pause1_1(data)                                         (0x00000002&((data)<<1))
#define SE1_SE1_DRF_PAUSE_se1_drf_pause1_1_src(data)                                     ((0x00000002&(data))>>1)
#define SE1_SE1_DRF_PAUSE_get_se1_drf_pause1_1(data)                                     ((0x00000002&(data))>>1)
#define SE1_SE1_DRF_PAUSE_se1_drf_pause1_0_shift                                         (0)
#define SE1_SE1_DRF_PAUSE_se1_drf_pause1_0_mask                                          (0x00000001)
#define SE1_SE1_DRF_PAUSE_se1_drf_pause1_0(data)                                         (0x00000001&((data)<<0))
#define SE1_SE1_DRF_PAUSE_se1_drf_pause1_0_src(data)                                     ((0x00000001&(data))>>0)
#define SE1_SE1_DRF_PAUSE_get_se1_drf_pause1_0(data)                                     ((0x00000001&(data))>>0)


#define SE1_SE1_DRF_FAIL_GROUP                                                         0x1803EA28
#define SE1_SE1_DRF_FAIL_GROUP_reg_addr                                                "0xB803EA28"
#define SE1_SE1_DRF_FAIL_GROUP_reg                                                     0xB803EA28
#define set_SE1_SE1_DRF_FAIL_GROUP_reg(data)   (*((volatile unsigned int*) SE1_SE1_DRF_FAIL_GROUP_reg)=data)
#define get_SE1_SE1_DRF_FAIL_GROUP_reg   (*((volatile unsigned int*) SE1_SE1_DRF_FAIL_GROUP_reg))
#define SE1_SE1_DRF_FAIL_GROUP_inst_adr                                                "0x008A"
#define SE1_SE1_DRF_FAIL_GROUP_inst                                                    0x008A
#define SE1_SE1_DRF_FAIL_GROUP_se1_drf_fail_group_1_shift                               (1)
#define SE1_SE1_DRF_FAIL_GROUP_se1_drf_fail_group_1_mask                                (0x00000002)
#define SE1_SE1_DRF_FAIL_GROUP_se1_drf_fail_group_1(data)                               (0x00000002&((data)<<1))
#define SE1_SE1_DRF_FAIL_GROUP_se1_drf_fail_group_1_src(data)                           ((0x00000002&(data))>>1)
#define SE1_SE1_DRF_FAIL_GROUP_get_se1_drf_fail_group_1(data)                           ((0x00000002&(data))>>1)
#define SE1_SE1_DRF_FAIL_GROUP_se1_drf_fail_group_0_shift                               (0)
#define SE1_SE1_DRF_FAIL_GROUP_se1_drf_fail_group_0_mask                                (0x00000001)
#define SE1_SE1_DRF_FAIL_GROUP_se1_drf_fail_group_0(data)                               (0x00000001&((data)<<0))
#define SE1_SE1_DRF_FAIL_GROUP_se1_drf_fail_group_0_src(data)                           ((0x00000001&(data))>>0)
#define SE1_SE1_DRF_FAIL_GROUP_get_se1_drf_fail_group_0(data)                           ((0x00000001&(data))>>0)


#define SE1_SE1_DRF_0_FAIL                                                             0x1803EA2C
#define SE1_SE1_DRF_0_FAIL_reg_addr                                                    "0xB803EA2C"
#define SE1_SE1_DRF_0_FAIL_reg                                                         0xB803EA2C
#define set_SE1_SE1_DRF_0_FAIL_reg(data)   (*((volatile unsigned int*) SE1_SE1_DRF_0_FAIL_reg)=data)
#define get_SE1_SE1_DRF_0_FAIL_reg   (*((volatile unsigned int*) SE1_SE1_DRF_0_FAIL_reg))
#define SE1_SE1_DRF_0_FAIL_inst_adr                                                    "0x008B"
#define SE1_SE1_DRF_0_FAIL_inst                                                        0x008B
#define SE1_SE1_DRF_0_FAIL_se1_drf_0_fail_8_shift                                       (8)
#define SE1_SE1_DRF_0_FAIL_se1_drf_0_fail_8_mask                                        (0x00000100)
#define SE1_SE1_DRF_0_FAIL_se1_drf_0_fail_8(data)                                       (0x00000100&((data)<<8))
#define SE1_SE1_DRF_0_FAIL_se1_drf_0_fail_8_src(data)                                   ((0x00000100&(data))>>8)
#define SE1_SE1_DRF_0_FAIL_get_se1_drf_0_fail_8(data)                                   ((0x00000100&(data))>>8)
#define SE1_SE1_DRF_0_FAIL_se1_drf_0_fail_7_shift                                       (7)
#define SE1_SE1_DRF_0_FAIL_se1_drf_0_fail_7_mask                                        (0x00000080)
#define SE1_SE1_DRF_0_FAIL_se1_drf_0_fail_7(data)                                       (0x00000080&((data)<<7))
#define SE1_SE1_DRF_0_FAIL_se1_drf_0_fail_7_src(data)                                   ((0x00000080&(data))>>7)
#define SE1_SE1_DRF_0_FAIL_get_se1_drf_0_fail_7(data)                                   ((0x00000080&(data))>>7)
#define SE1_SE1_DRF_0_FAIL_se1_drf_0_fail_6_shift                                       (6)
#define SE1_SE1_DRF_0_FAIL_se1_drf_0_fail_6_mask                                        (0x00000040)
#define SE1_SE1_DRF_0_FAIL_se1_drf_0_fail_6(data)                                       (0x00000040&((data)<<6))
#define SE1_SE1_DRF_0_FAIL_se1_drf_0_fail_6_src(data)                                   ((0x00000040&(data))>>6)
#define SE1_SE1_DRF_0_FAIL_get_se1_drf_0_fail_6(data)                                   ((0x00000040&(data))>>6)
#define SE1_SE1_DRF_0_FAIL_se1_drf_0_fail_5_shift                                       (5)
#define SE1_SE1_DRF_0_FAIL_se1_drf_0_fail_5_mask                                        (0x00000020)
#define SE1_SE1_DRF_0_FAIL_se1_drf_0_fail_5(data)                                       (0x00000020&((data)<<5))
#define SE1_SE1_DRF_0_FAIL_se1_drf_0_fail_5_src(data)                                   ((0x00000020&(data))>>5)
#define SE1_SE1_DRF_0_FAIL_get_se1_drf_0_fail_5(data)                                   ((0x00000020&(data))>>5)
#define SE1_SE1_DRF_0_FAIL_se1_drf_0_fail_4_shift                                       (4)
#define SE1_SE1_DRF_0_FAIL_se1_drf_0_fail_4_mask                                        (0x00000010)
#define SE1_SE1_DRF_0_FAIL_se1_drf_0_fail_4(data)                                       (0x00000010&((data)<<4))
#define SE1_SE1_DRF_0_FAIL_se1_drf_0_fail_4_src(data)                                   ((0x00000010&(data))>>4)
#define SE1_SE1_DRF_0_FAIL_get_se1_drf_0_fail_4(data)                                   ((0x00000010&(data))>>4)
#define SE1_SE1_DRF_0_FAIL_se1_drf_0_fail_3_shift                                       (3)
#define SE1_SE1_DRF_0_FAIL_se1_drf_0_fail_3_mask                                        (0x00000008)
#define SE1_SE1_DRF_0_FAIL_se1_drf_0_fail_3(data)                                       (0x00000008&((data)<<3))
#define SE1_SE1_DRF_0_FAIL_se1_drf_0_fail_3_src(data)                                   ((0x00000008&(data))>>3)
#define SE1_SE1_DRF_0_FAIL_get_se1_drf_0_fail_3(data)                                   ((0x00000008&(data))>>3)
#define SE1_SE1_DRF_0_FAIL_se1_drf_0_fail_2_shift                                       (2)
#define SE1_SE1_DRF_0_FAIL_se1_drf_0_fail_2_mask                                        (0x00000004)
#define SE1_SE1_DRF_0_FAIL_se1_drf_0_fail_2(data)                                       (0x00000004&((data)<<2))
#define SE1_SE1_DRF_0_FAIL_se1_drf_0_fail_2_src(data)                                   ((0x00000004&(data))>>2)
#define SE1_SE1_DRF_0_FAIL_get_se1_drf_0_fail_2(data)                                   ((0x00000004&(data))>>2)
#define SE1_SE1_DRF_0_FAIL_se1_drf_0_fail_1_shift                                       (1)
#define SE1_SE1_DRF_0_FAIL_se1_drf_0_fail_1_mask                                        (0x00000002)
#define SE1_SE1_DRF_0_FAIL_se1_drf_0_fail_1(data)                                       (0x00000002&((data)<<1))
#define SE1_SE1_DRF_0_FAIL_se1_drf_0_fail_1_src(data)                                   ((0x00000002&(data))>>1)
#define SE1_SE1_DRF_0_FAIL_get_se1_drf_0_fail_1(data)                                   ((0x00000002&(data))>>1)
#define SE1_SE1_DRF_0_FAIL_se1_drf_0_fail_0_shift                                       (0)
#define SE1_SE1_DRF_0_FAIL_se1_drf_0_fail_0_mask                                        (0x00000001)
#define SE1_SE1_DRF_0_FAIL_se1_drf_0_fail_0(data)                                       (0x00000001&((data)<<0))
#define SE1_SE1_DRF_0_FAIL_se1_drf_0_fail_0_src(data)                                   ((0x00000001&(data))>>0)
#define SE1_SE1_DRF_0_FAIL_get_se1_drf_0_fail_0(data)                                   ((0x00000001&(data))>>0)


#define SE1_SE1_DRF_1_FAIL                                                             0x1803EA30
#define SE1_SE1_DRF_1_FAIL_reg_addr                                                    "0xB803EA30"
#define SE1_SE1_DRF_1_FAIL_reg                                                         0xB803EA30
#define set_SE1_SE1_DRF_1_FAIL_reg(data)   (*((volatile unsigned int*) SE1_SE1_DRF_1_FAIL_reg)=data)
#define get_SE1_SE1_DRF_1_FAIL_reg   (*((volatile unsigned int*) SE1_SE1_DRF_1_FAIL_reg))
#define SE1_SE1_DRF_1_FAIL_inst_adr                                                    "0x008C"
#define SE1_SE1_DRF_1_FAIL_inst                                                        0x008C
#define SE1_SE1_DRF_1_FAIL_se1_drf_1_fail_1_shift                                       (1)
#define SE1_SE1_DRF_1_FAIL_se1_drf_1_fail_1_mask                                        (0x00000002)
#define SE1_SE1_DRF_1_FAIL_se1_drf_1_fail_1(data)                                       (0x00000002&((data)<<1))
#define SE1_SE1_DRF_1_FAIL_se1_drf_1_fail_1_src(data)                                   ((0x00000002&(data))>>1)
#define SE1_SE1_DRF_1_FAIL_get_se1_drf_1_fail_1(data)                                   ((0x00000002&(data))>>1)
#define SE1_SE1_DRF_1_FAIL_se1_drf_1_fail_0_shift                                       (0)
#define SE1_SE1_DRF_1_FAIL_se1_drf_1_fail_0_mask                                        (0x00000001)
#define SE1_SE1_DRF_1_FAIL_se1_drf_1_fail_0(data)                                       (0x00000001&((data)<<0))
#define SE1_SE1_DRF_1_FAIL_se1_drf_1_fail_0_src(data)                                   ((0x00000001&(data))>>0)
#define SE1_SE1_DRF_1_FAIL_get_se1_drf_1_fail_0(data)                                   ((0x00000001&(data))>>0)


#endif
