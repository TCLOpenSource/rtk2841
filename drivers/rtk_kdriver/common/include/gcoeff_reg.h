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


#ifndef _GCOEFF_REG_H_INCLUDED_
#define _GCOEFF_REG_H_INCLUDED_
#ifdef  _GCOEFF_USE_STRUCT
typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     write_enable14:1;
unsigned int     Ipmdoff:1;
unsigned int     write_enable13:1;
unsigned int     Sideband_enable:1;
unsigned int     write_enable12:1;
unsigned int     Luma16x8_xform_sel:1;
unsigned int     write_enable11:1;
unsigned int     Luma8x16_xform_sel:1;
unsigned int     write_enable10:1;
unsigned int     Flush_cmd_disable:1;
unsigned int     write_enable9:1;
unsigned int     Softrst_disable:1;
unsigned int     write_enable7:1;
unsigned int     Trmem_dv_load:1;
unsigned int     write_enable6:1;
unsigned int     Umem_bypass:1;
unsigned int     write_enable5:1;
unsigned int     Luma16x16_xform_sel:1;
unsigned int     write_enable4:1;
unsigned int     Luma8x8_xform_sel:1;
unsigned int     write_enable3:1;
unsigned int     Constr_intra_pred:1;
unsigned int     write_enable2:1;
unsigned int     Wdone_enable:1;
unsigned int     write_enable1:1;
unsigned int     SReset_busy_clr:1;
}GCOEFF_CTRL;

typedef struct 
{
unsigned int     intra_flag:32;
}GCOEFF_INTRA;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     fmvx:12;
unsigned int     reserved_1:6;
unsigned int     fmvy:10;
}GCOEFF_CHMV;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     fmvx:12;
unsigned int     reserved_1:6;
unsigned int     fmvy:10;
}GCOEFF_CHBMV;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     fmvx:12;
unsigned int     reserved_1:6;
unsigned int     fmvy:10;
}GCOEFF_CHMVD;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     fmvx:12;
unsigned int     reserved_1:6;
unsigned int     fmvy:10;
}GCOEFF_CHBMVD;

typedef struct 
{
unsigned int     seq_line_addr:32;
}GCOEFF_SDMAADR;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     Value:28;
}GCOEFF_INTR_THRESH;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     Reach_Thresh:1;
unsigned int     Count:28;
}GCOEFF_BUSY;

typedef struct 
{
unsigned int     GenPulse:1;
unsigned int     DbgCtrl:3;
unsigned int     PicCount:14;
unsigned int     MbAddrX:7;
unsigned int     MbAddrY:7;
}GCOEFF_DBUS1;

typedef struct 
{
unsigned int     DbgCtrl:32;
}GCOEFF_DBUS2;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     Vmadr_en:1;
unsigned int     BaseA0:7;
unsigned int     reserved_1:16;
}GCOEFF_BASEA;

typedef struct 
{
unsigned int     reserved_0:22;
unsigned int     OffsetA:7;
unsigned int     reserved_1:3;
}GCOEFF_OFFSETA;

typedef struct 
{
unsigned int     reserved_0:25;
unsigned int     StartA:7;
}GCOEFF_DEBPAR;

typedef struct 
{
unsigned int     reserved_0:26;
unsigned int     IntraLumaStyleSel:1;
unsigned int     XVID_combine_style:2;
unsigned int     Style_Sel:3;
}GCOEFF_CBPCTRL;

typedef struct 
{
unsigned int     Lookup:32;
}GCOEFF_SUMRUNCOST_8X8;

typedef struct 
{
unsigned int     Lookup:32;
}GCOEFF_SUMRUNCOST_4X4;

typedef struct 
{
unsigned int     reserved_0:5;
unsigned int     T4x4:11;
unsigned int     reserved_1:5;
unsigned int     T8x8:11;
}GCOEFF_SUMRUNCOST_THR;

typedef struct 
{
unsigned int     reserved_0:11;
unsigned int     T4x4:5;
unsigned int     reserved_1:9;
unsigned int     T8x8:7;
}GCOEFF_FIRSTCFF;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     T4x4:8;
unsigned int     T8x8:8;
}GCOEFF_SUMCFF;

typedef struct 
{
unsigned int     reserved_0:11;
unsigned int     List1Idx0:7;
unsigned int     List0Idx1:7;
unsigned int     List0Idx0:7;
}GCOEFF_CHROMA_LD;

typedef struct 
{
unsigned int     Value:32;
}GCOEFF_INTRAMODE;

typedef struct 
{
unsigned int     reserved_0:25;
unsigned int     y:7;
}GCOEFF_SLICE;

typedef struct 
{
unsigned int     reserved_0:18;
unsigned int     Enable:1;
unsigned int     Thresh:13;
}GCOEFF_MBLEVEL_DROP;

typedef struct 
{
unsigned int     reserved_0:5;
unsigned int     T4x4:11;
unsigned int     reserved_1:16;
}GCOEFF_SUMRUNCOST_THR_CHR;

typedef struct 
{
unsigned int     reserved_0:11;
unsigned int     T4x4:5;
unsigned int     reserved_1:16;
}GCOEFF_FIRSTCFF_CHR;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     T4x4:8;
unsigned int     reserved_1:8;
}GCOEFF_SUMCFF_CHR;

typedef struct 
{
unsigned int     reserved_0:5;
unsigned int     Luma_wr:1;
unsigned int     CB_wr:1;
unsigned int     CR_wr:1;
unsigned int     Luma:8;
unsigned int     CB:8;
unsigned int     CR:8;
}GCOEFF_ULPRED;

typedef struct 
{
unsigned int     reserved_0:7;
unsigned int     Soft_rst:1;
unsigned int     Init_en:1;
unsigned int     Rng_Size:7;
unsigned int     Rdptr:8;
unsigned int     Wrptr:8;
}GCOEFF_PMEMCTL_DBG;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     write_enable3:1;
unsigned int     flat_qtable:1;
unsigned int     write_enable2:1;
unsigned int     qpy:6;
unsigned int     write_enable1:1;
unsigned int     qpc:6;
}GCOEFF_QUANTIZER;

typedef struct 
{
unsigned int     Mem_eng_busy:1;
unsigned int     reserved_0:31;
}GCOEFF_MESTATUS;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     Inter_pred_mode:8;
unsigned int     List0RefIdx0:2;
unsigned int     List0RefIdx1:2;
unsigned int     List0RefIdx2:2;
unsigned int     List0RefIdx3:2;
unsigned int     List1RefIdx0:2;
unsigned int     List1RefIdx1:2;
unsigned int     List1RefIdx2:2;
unsigned int     List1RefIdx3:2;
}GCOEFF_LISTREF;

typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     SliceStart:1;
unsigned int     CodingType:2;
unsigned int     PictureType:2;
unsigned int     MBType:2;
unsigned int     MBpartition:3;
unsigned int     CurMBY:8;
unsigned int     CurMBX:8;
}GCOEFF_MBINFO;

typedef struct 
{
unsigned int     Value:32;
}GCOEFF_REMMODE;

typedef struct 
{
unsigned int     Value:32;
}GCOEFF_BITSTR;

typedef struct 
{
unsigned int     reserved_0:26;
unsigned int     Mb_mode:3;
unsigned int     Eob_total:1;
unsigned int     Transform_size_8x8_flag:1;
unsigned int     Mb_field_decoding_flag:1;
}GCOEFF_DEBINFO;

typedef struct 
{
unsigned int     reserved_0:21;
unsigned int     write_enable4:1;
unsigned int     DV_enable:1;
unsigned int     write_enable3:1;
unsigned int     Size:2;
unsigned int     write_enable2:1;
unsigned int     Rdptr:2;
unsigned int     write_enable1:1;
unsigned int     Wrptr:2;
}GCOEFF_SBCTRL;

#endif

#define GCOEFF_CTRL                                                                  0x18036800
#define GCOEFF_CTRL_reg_addr                                                         "0xB8036800"
#define GCOEFF_CTRL_reg                                                              0xB8036800
#define set_GCOEFF_CTRL_reg(data)   (*((volatile unsigned int*) GCOEFF_CTRL_reg)=data)
#define get_GCOEFF_CTRL_reg   (*((volatile unsigned int*) GCOEFF_CTRL_reg))
#define GCOEFF_CTRL_inst_adr                                                         "0x0000"
#define GCOEFF_CTRL_inst                                                             0x0000
#define GCOEFF_CTRL_write_enable14_shift                                             (25)
#define GCOEFF_CTRL_write_enable14_mask                                              (0x02000000)
#define GCOEFF_CTRL_write_enable14(data)                                             (0x02000000&((data)<<25))
#define GCOEFF_CTRL_write_enable14_src(data)                                         ((0x02000000&(data))>>25)
#define GCOEFF_CTRL_get_write_enable14(data)                                         ((0x02000000&(data))>>25)
#define GCOEFF_CTRL_Ipmdoff_shift                                                    (24)
#define GCOEFF_CTRL_Ipmdoff_mask                                                     (0x01000000)
#define GCOEFF_CTRL_Ipmdoff(data)                                                    (0x01000000&((data)<<24))
#define GCOEFF_CTRL_Ipmdoff_src(data)                                                ((0x01000000&(data))>>24)
#define GCOEFF_CTRL_get_Ipmdoff(data)                                                ((0x01000000&(data))>>24)
#define GCOEFF_CTRL_write_enable13_shift                                             (23)
#define GCOEFF_CTRL_write_enable13_mask                                              (0x00800000)
#define GCOEFF_CTRL_write_enable13(data)                                             (0x00800000&((data)<<23))
#define GCOEFF_CTRL_write_enable13_src(data)                                         ((0x00800000&(data))>>23)
#define GCOEFF_CTRL_get_write_enable13(data)                                         ((0x00800000&(data))>>23)
#define GCOEFF_CTRL_Sideband_enable_shift                                            (22)
#define GCOEFF_CTRL_Sideband_enable_mask                                             (0x00400000)
#define GCOEFF_CTRL_Sideband_enable(data)                                            (0x00400000&((data)<<22))
#define GCOEFF_CTRL_Sideband_enable_src(data)                                        ((0x00400000&(data))>>22)
#define GCOEFF_CTRL_get_Sideband_enable(data)                                        ((0x00400000&(data))>>22)
#define GCOEFF_CTRL_write_enable12_shift                                             (21)
#define GCOEFF_CTRL_write_enable12_mask                                              (0x00200000)
#define GCOEFF_CTRL_write_enable12(data)                                             (0x00200000&((data)<<21))
#define GCOEFF_CTRL_write_enable12_src(data)                                         ((0x00200000&(data))>>21)
#define GCOEFF_CTRL_get_write_enable12(data)                                         ((0x00200000&(data))>>21)
#define GCOEFF_CTRL_Luma16x8_xform_sel_shift                                         (20)
#define GCOEFF_CTRL_Luma16x8_xform_sel_mask                                          (0x00100000)
#define GCOEFF_CTRL_Luma16x8_xform_sel(data)                                         (0x00100000&((data)<<20))
#define GCOEFF_CTRL_Luma16x8_xform_sel_src(data)                                     ((0x00100000&(data))>>20)
#define GCOEFF_CTRL_get_Luma16x8_xform_sel(data)                                     ((0x00100000&(data))>>20)
#define GCOEFF_CTRL_write_enable11_shift                                             (19)
#define GCOEFF_CTRL_write_enable11_mask                                              (0x00080000)
#define GCOEFF_CTRL_write_enable11(data)                                             (0x00080000&((data)<<19))
#define GCOEFF_CTRL_write_enable11_src(data)                                         ((0x00080000&(data))>>19)
#define GCOEFF_CTRL_get_write_enable11(data)                                         ((0x00080000&(data))>>19)
#define GCOEFF_CTRL_Luma8x16_xform_sel_shift                                         (18)
#define GCOEFF_CTRL_Luma8x16_xform_sel_mask                                          (0x00040000)
#define GCOEFF_CTRL_Luma8x16_xform_sel(data)                                         (0x00040000&((data)<<18))
#define GCOEFF_CTRL_Luma8x16_xform_sel_src(data)                                     ((0x00040000&(data))>>18)
#define GCOEFF_CTRL_get_Luma8x16_xform_sel(data)                                     ((0x00040000&(data))>>18)
#define GCOEFF_CTRL_write_enable10_shift                                             (17)
#define GCOEFF_CTRL_write_enable10_mask                                              (0x00020000)
#define GCOEFF_CTRL_write_enable10(data)                                             (0x00020000&((data)<<17))
#define GCOEFF_CTRL_write_enable10_src(data)                                         ((0x00020000&(data))>>17)
#define GCOEFF_CTRL_get_write_enable10(data)                                         ((0x00020000&(data))>>17)
#define GCOEFF_CTRL_Flush_cmd_disable_shift                                          (16)
#define GCOEFF_CTRL_Flush_cmd_disable_mask                                           (0x00010000)
#define GCOEFF_CTRL_Flush_cmd_disable(data)                                          (0x00010000&((data)<<16))
#define GCOEFF_CTRL_Flush_cmd_disable_src(data)                                      ((0x00010000&(data))>>16)
#define GCOEFF_CTRL_get_Flush_cmd_disable(data)                                      ((0x00010000&(data))>>16)
#define GCOEFF_CTRL_write_enable9_shift                                              (15)
#define GCOEFF_CTRL_write_enable9_mask                                               (0x00008000)
#define GCOEFF_CTRL_write_enable9(data)                                              (0x00008000&((data)<<15))
#define GCOEFF_CTRL_write_enable9_src(data)                                          ((0x00008000&(data))>>15)
#define GCOEFF_CTRL_get_write_enable9(data)                                          ((0x00008000&(data))>>15)
#define GCOEFF_CTRL_Softrst_disable_shift                                            (14)
#define GCOEFF_CTRL_Softrst_disable_mask                                             (0x00004000)
#define GCOEFF_CTRL_Softrst_disable(data)                                            (0x00004000&((data)<<14))
#define GCOEFF_CTRL_Softrst_disable_src(data)                                        ((0x00004000&(data))>>14)
#define GCOEFF_CTRL_get_Softrst_disable(data)                                        ((0x00004000&(data))>>14)
#define GCOEFF_CTRL_write_enable7_shift                                              (13)
#define GCOEFF_CTRL_write_enable7_mask                                               (0x00002000)
#define GCOEFF_CTRL_write_enable7(data)                                              (0x00002000&((data)<<13))
#define GCOEFF_CTRL_write_enable7_src(data)                                          ((0x00002000&(data))>>13)
#define GCOEFF_CTRL_get_write_enable7(data)                                          ((0x00002000&(data))>>13)
#define GCOEFF_CTRL_Trmem_dv_load_shift                                              (12)
#define GCOEFF_CTRL_Trmem_dv_load_mask                                               (0x00001000)
#define GCOEFF_CTRL_Trmem_dv_load(data)                                              (0x00001000&((data)<<12))
#define GCOEFF_CTRL_Trmem_dv_load_src(data)                                          ((0x00001000&(data))>>12)
#define GCOEFF_CTRL_get_Trmem_dv_load(data)                                          ((0x00001000&(data))>>12)
#define GCOEFF_CTRL_write_enable6_shift                                              (11)
#define GCOEFF_CTRL_write_enable6_mask                                               (0x00000800)
#define GCOEFF_CTRL_write_enable6(data)                                              (0x00000800&((data)<<11))
#define GCOEFF_CTRL_write_enable6_src(data)                                          ((0x00000800&(data))>>11)
#define GCOEFF_CTRL_get_write_enable6(data)                                          ((0x00000800&(data))>>11)
#define GCOEFF_CTRL_Umem_bypass_shift                                                (10)
#define GCOEFF_CTRL_Umem_bypass_mask                                                 (0x00000400)
#define GCOEFF_CTRL_Umem_bypass(data)                                                (0x00000400&((data)<<10))
#define GCOEFF_CTRL_Umem_bypass_src(data)                                            ((0x00000400&(data))>>10)
#define GCOEFF_CTRL_get_Umem_bypass(data)                                            ((0x00000400&(data))>>10)
#define GCOEFF_CTRL_write_enable5_shift                                              (9)
#define GCOEFF_CTRL_write_enable5_mask                                               (0x00000200)
#define GCOEFF_CTRL_write_enable5(data)                                              (0x00000200&((data)<<9))
#define GCOEFF_CTRL_write_enable5_src(data)                                          ((0x00000200&(data))>>9)
#define GCOEFF_CTRL_get_write_enable5(data)                                          ((0x00000200&(data))>>9)
#define GCOEFF_CTRL_Luma16x16_xform_sel_shift                                        (8)
#define GCOEFF_CTRL_Luma16x16_xform_sel_mask                                         (0x00000100)
#define GCOEFF_CTRL_Luma16x16_xform_sel(data)                                        (0x00000100&((data)<<8))
#define GCOEFF_CTRL_Luma16x16_xform_sel_src(data)                                    ((0x00000100&(data))>>8)
#define GCOEFF_CTRL_get_Luma16x16_xform_sel(data)                                    ((0x00000100&(data))>>8)
#define GCOEFF_CTRL_write_enable4_shift                                              (7)
#define GCOEFF_CTRL_write_enable4_mask                                               (0x00000080)
#define GCOEFF_CTRL_write_enable4(data)                                              (0x00000080&((data)<<7))
#define GCOEFF_CTRL_write_enable4_src(data)                                          ((0x00000080&(data))>>7)
#define GCOEFF_CTRL_get_write_enable4(data)                                          ((0x00000080&(data))>>7)
#define GCOEFF_CTRL_Luma8x8_xform_sel_shift                                          (6)
#define GCOEFF_CTRL_Luma8x8_xform_sel_mask                                           (0x00000040)
#define GCOEFF_CTRL_Luma8x8_xform_sel(data)                                          (0x00000040&((data)<<6))
#define GCOEFF_CTRL_Luma8x8_xform_sel_src(data)                                      ((0x00000040&(data))>>6)
#define GCOEFF_CTRL_get_Luma8x8_xform_sel(data)                                      ((0x00000040&(data))>>6)
#define GCOEFF_CTRL_write_enable3_shift                                              (5)
#define GCOEFF_CTRL_write_enable3_mask                                               (0x00000020)
#define GCOEFF_CTRL_write_enable3(data)                                              (0x00000020&((data)<<5))
#define GCOEFF_CTRL_write_enable3_src(data)                                          ((0x00000020&(data))>>5)
#define GCOEFF_CTRL_get_write_enable3(data)                                          ((0x00000020&(data))>>5)
#define GCOEFF_CTRL_Constr_intra_pred_shift                                          (4)
#define GCOEFF_CTRL_Constr_intra_pred_mask                                           (0x00000010)
#define GCOEFF_CTRL_Constr_intra_pred(data)                                          (0x00000010&((data)<<4))
#define GCOEFF_CTRL_Constr_intra_pred_src(data)                                      ((0x00000010&(data))>>4)
#define GCOEFF_CTRL_get_Constr_intra_pred(data)                                      ((0x00000010&(data))>>4)
#define GCOEFF_CTRL_write_enable2_shift                                              (3)
#define GCOEFF_CTRL_write_enable2_mask                                               (0x00000008)
#define GCOEFF_CTRL_write_enable2(data)                                              (0x00000008&((data)<<3))
#define GCOEFF_CTRL_write_enable2_src(data)                                          ((0x00000008&(data))>>3)
#define GCOEFF_CTRL_get_write_enable2(data)                                          ((0x00000008&(data))>>3)
#define GCOEFF_CTRL_Wdone_enable_shift                                               (2)
#define GCOEFF_CTRL_Wdone_enable_mask                                                (0x00000004)
#define GCOEFF_CTRL_Wdone_enable(data)                                               (0x00000004&((data)<<2))
#define GCOEFF_CTRL_Wdone_enable_src(data)                                           ((0x00000004&(data))>>2)
#define GCOEFF_CTRL_get_Wdone_enable(data)                                           ((0x00000004&(data))>>2)
#define GCOEFF_CTRL_write_enable1_shift                                              (1)
#define GCOEFF_CTRL_write_enable1_mask                                               (0x00000002)
#define GCOEFF_CTRL_write_enable1(data)                                              (0x00000002&((data)<<1))
#define GCOEFF_CTRL_write_enable1_src(data)                                          ((0x00000002&(data))>>1)
#define GCOEFF_CTRL_get_write_enable1(data)                                          ((0x00000002&(data))>>1)
#define GCOEFF_CTRL_SReset_busy_clr_shift                                            (0)
#define GCOEFF_CTRL_SReset_busy_clr_mask                                             (0x00000001)
#define GCOEFF_CTRL_SReset_busy_clr(data)                                            (0x00000001&((data)<<0))
#define GCOEFF_CTRL_SReset_busy_clr_src(data)                                        ((0x00000001&(data))>>0)
#define GCOEFF_CTRL_get_SReset_busy_clr(data)                                        ((0x00000001&(data))>>0)


#define GCOEFF_INTRA_0                                                               0x18036804
#define GCOEFF_INTRA_1                                                               0x18036808
#define GCOEFF_INTRA_2                                                               0x1803680C
#define GCOEFF_INTRA_3                                                               0x18036810
#define GCOEFF_INTRA_0_reg_addr                                                      "0xB8036804"
#define GCOEFF_INTRA_1_reg_addr                                                      "0xB8036808"
#define GCOEFF_INTRA_2_reg_addr                                                      "0xB803680C"
#define GCOEFF_INTRA_3_reg_addr                                                      "0xB8036810"
#define GCOEFF_INTRA_0_reg                                                           0xB8036804
#define GCOEFF_INTRA_1_reg                                                           0xB8036808
#define GCOEFF_INTRA_2_reg                                                           0xB803680C
#define GCOEFF_INTRA_3_reg                                                           0xB8036810
#define set_GCOEFF_INTRA_0_reg(data)   (*((volatile unsigned int*) GCOEFF_INTRA_0_reg)=data)
#define set_GCOEFF_INTRA_1_reg(data)   (*((volatile unsigned int*) GCOEFF_INTRA_1_reg)=data)
#define set_GCOEFF_INTRA_2_reg(data)   (*((volatile unsigned int*) GCOEFF_INTRA_2_reg)=data)
#define set_GCOEFF_INTRA_3_reg(data)   (*((volatile unsigned int*) GCOEFF_INTRA_3_reg)=data)
#define get_GCOEFF_INTRA_0_reg   (*((volatile unsigned int*) GCOEFF_INTRA_0_reg))
#define get_GCOEFF_INTRA_1_reg   (*((volatile unsigned int*) GCOEFF_INTRA_1_reg))
#define get_GCOEFF_INTRA_2_reg   (*((volatile unsigned int*) GCOEFF_INTRA_2_reg))
#define get_GCOEFF_INTRA_3_reg   (*((volatile unsigned int*) GCOEFF_INTRA_3_reg))
#define GCOEFF_INTRA_0_inst_adr                                                      "0x0001"
#define GCOEFF_INTRA_1_inst_adr                                                      "0x0002"
#define GCOEFF_INTRA_2_inst_adr                                                      "0x0003"
#define GCOEFF_INTRA_3_inst_adr                                                      "0x0004"
#define GCOEFF_INTRA_0_inst                                                          0x0001
#define GCOEFF_INTRA_1_inst                                                          0x0002
#define GCOEFF_INTRA_2_inst                                                          0x0003
#define GCOEFF_INTRA_3_inst                                                          0x0004
#define GCOEFF_INTRA_intra_flag_shift                                                (0)
#define GCOEFF_INTRA_intra_flag_mask                                                 (0xFFFFFFFF)
#define GCOEFF_INTRA_intra_flag(data)                                                (0xFFFFFFFF&((data)<<0))
#define GCOEFF_INTRA_intra_flag_src(data)                                            ((0xFFFFFFFF&(data))>>0)
#define GCOEFF_INTRA_get_intra_flag(data)                                            ((0xFFFFFFFF&(data))>>0)


#define GCOEFF_CHMV_0                                                                0x18036814
#define GCOEFF_CHMV_1                                                                0x18036818
#define GCOEFF_CHMV_2                                                                0x1803681C
#define GCOEFF_CHMV_3                                                                0x18036820
#define GCOEFF_CHMV_0_reg_addr                                                       "0xB8036814"
#define GCOEFF_CHMV_1_reg_addr                                                       "0xB8036818"
#define GCOEFF_CHMV_2_reg_addr                                                       "0xB803681C"
#define GCOEFF_CHMV_3_reg_addr                                                       "0xB8036820"
#define GCOEFF_CHMV_0_reg                                                            0xB8036814
#define GCOEFF_CHMV_1_reg                                                            0xB8036818
#define GCOEFF_CHMV_2_reg                                                            0xB803681C
#define GCOEFF_CHMV_3_reg                                                            0xB8036820
#define set_GCOEFF_CHMV_0_reg(data)   (*((volatile unsigned int*) GCOEFF_CHMV_0_reg)=data)
#define set_GCOEFF_CHMV_1_reg(data)   (*((volatile unsigned int*) GCOEFF_CHMV_1_reg)=data)
#define set_GCOEFF_CHMV_2_reg(data)   (*((volatile unsigned int*) GCOEFF_CHMV_2_reg)=data)
#define set_GCOEFF_CHMV_3_reg(data)   (*((volatile unsigned int*) GCOEFF_CHMV_3_reg)=data)
#define get_GCOEFF_CHMV_0_reg   (*((volatile unsigned int*) GCOEFF_CHMV_0_reg))
#define get_GCOEFF_CHMV_1_reg   (*((volatile unsigned int*) GCOEFF_CHMV_1_reg))
#define get_GCOEFF_CHMV_2_reg   (*((volatile unsigned int*) GCOEFF_CHMV_2_reg))
#define get_GCOEFF_CHMV_3_reg   (*((volatile unsigned int*) GCOEFF_CHMV_3_reg))
#define GCOEFF_CHMV_0_inst_adr                                                       "0x0005"
#define GCOEFF_CHMV_1_inst_adr                                                       "0x0006"
#define GCOEFF_CHMV_2_inst_adr                                                       "0x0007"
#define GCOEFF_CHMV_3_inst_adr                                                       "0x0008"
#define GCOEFF_CHMV_0_inst                                                           0x0005
#define GCOEFF_CHMV_1_inst                                                           0x0006
#define GCOEFF_CHMV_2_inst                                                           0x0007
#define GCOEFF_CHMV_3_inst                                                           0x0008
#define GCOEFF_CHMV_fmvx_shift                                                       (16)
#define GCOEFF_CHMV_fmvx_mask                                                        (0x0FFF0000)
#define GCOEFF_CHMV_fmvx(data)                                                       (0x0FFF0000&((data)<<16))
#define GCOEFF_CHMV_fmvx_src(data)                                                   ((0x0FFF0000&(data))>>16)
#define GCOEFF_CHMV_get_fmvx(data)                                                   ((0x0FFF0000&(data))>>16)
#define GCOEFF_CHMV_fmvy_shift                                                       (0)
#define GCOEFF_CHMV_fmvy_mask                                                        (0x000003FF)
#define GCOEFF_CHMV_fmvy(data)                                                       (0x000003FF&((data)<<0))
#define GCOEFF_CHMV_fmvy_src(data)                                                   ((0x000003FF&(data))>>0)
#define GCOEFF_CHMV_get_fmvy(data)                                                   ((0x000003FF&(data))>>0)


#define GCOEFF_CHBMV_0                                                               0x18036824
#define GCOEFF_CHBMV_1                                                               0x18036828
#define GCOEFF_CHBMV_2                                                               0x1803682C
#define GCOEFF_CHBMV_3                                                               0x18036830
#define GCOEFF_CHBMV_0_reg_addr                                                      "0xB8036824"
#define GCOEFF_CHBMV_1_reg_addr                                                      "0xB8036828"
#define GCOEFF_CHBMV_2_reg_addr                                                      "0xB803682C"
#define GCOEFF_CHBMV_3_reg_addr                                                      "0xB8036830"
#define GCOEFF_CHBMV_0_reg                                                           0xB8036824
#define GCOEFF_CHBMV_1_reg                                                           0xB8036828
#define GCOEFF_CHBMV_2_reg                                                           0xB803682C
#define GCOEFF_CHBMV_3_reg                                                           0xB8036830
#define set_GCOEFF_CHBMV_0_reg(data)   (*((volatile unsigned int*) GCOEFF_CHBMV_0_reg)=data)
#define set_GCOEFF_CHBMV_1_reg(data)   (*((volatile unsigned int*) GCOEFF_CHBMV_1_reg)=data)
#define set_GCOEFF_CHBMV_2_reg(data)   (*((volatile unsigned int*) GCOEFF_CHBMV_2_reg)=data)
#define set_GCOEFF_CHBMV_3_reg(data)   (*((volatile unsigned int*) GCOEFF_CHBMV_3_reg)=data)
#define get_GCOEFF_CHBMV_0_reg   (*((volatile unsigned int*) GCOEFF_CHBMV_0_reg))
#define get_GCOEFF_CHBMV_1_reg   (*((volatile unsigned int*) GCOEFF_CHBMV_1_reg))
#define get_GCOEFF_CHBMV_2_reg   (*((volatile unsigned int*) GCOEFF_CHBMV_2_reg))
#define get_GCOEFF_CHBMV_3_reg   (*((volatile unsigned int*) GCOEFF_CHBMV_3_reg))
#define GCOEFF_CHBMV_0_inst_adr                                                      "0x0009"
#define GCOEFF_CHBMV_1_inst_adr                                                      "0x000A"
#define GCOEFF_CHBMV_2_inst_adr                                                      "0x000B"
#define GCOEFF_CHBMV_3_inst_adr                                                      "0x000C"
#define GCOEFF_CHBMV_0_inst                                                          0x0009
#define GCOEFF_CHBMV_1_inst                                                          0x000A
#define GCOEFF_CHBMV_2_inst                                                          0x000B
#define GCOEFF_CHBMV_3_inst                                                          0x000C
#define GCOEFF_CHBMV_fmvx_shift                                                      (16)
#define GCOEFF_CHBMV_fmvx_mask                                                       (0x0FFF0000)
#define GCOEFF_CHBMV_fmvx(data)                                                      (0x0FFF0000&((data)<<16))
#define GCOEFF_CHBMV_fmvx_src(data)                                                  ((0x0FFF0000&(data))>>16)
#define GCOEFF_CHBMV_get_fmvx(data)                                                  ((0x0FFF0000&(data))>>16)
#define GCOEFF_CHBMV_fmvy_shift                                                      (0)
#define GCOEFF_CHBMV_fmvy_mask                                                       (0x000003FF)
#define GCOEFF_CHBMV_fmvy(data)                                                      (0x000003FF&((data)<<0))
#define GCOEFF_CHBMV_fmvy_src(data)                                                  ((0x000003FF&(data))>>0)
#define GCOEFF_CHBMV_get_fmvy(data)                                                  ((0x000003FF&(data))>>0)


#define GCOEFF_CHMVD_0                                                               0x18036904
#define GCOEFF_CHMVD_1                                                               0x18036908
#define GCOEFF_CHMVD_2                                                               0x1803690C
#define GCOEFF_CHMVD_3                                                               0x18036910
#define GCOEFF_CHMVD_0_reg_addr                                                      "0xB8036904"
#define GCOEFF_CHMVD_1_reg_addr                                                      "0xB8036908"
#define GCOEFF_CHMVD_2_reg_addr                                                      "0xB803690C"
#define GCOEFF_CHMVD_3_reg_addr                                                      "0xB8036910"
#define GCOEFF_CHMVD_0_reg                                                           0xB8036904
#define GCOEFF_CHMVD_1_reg                                                           0xB8036908
#define GCOEFF_CHMVD_2_reg                                                           0xB803690C
#define GCOEFF_CHMVD_3_reg                                                           0xB8036910
#define set_GCOEFF_CHMVD_0_reg(data)   (*((volatile unsigned int*) GCOEFF_CHMVD_0_reg)=data)
#define set_GCOEFF_CHMVD_1_reg(data)   (*((volatile unsigned int*) GCOEFF_CHMVD_1_reg)=data)
#define set_GCOEFF_CHMVD_2_reg(data)   (*((volatile unsigned int*) GCOEFF_CHMVD_2_reg)=data)
#define set_GCOEFF_CHMVD_3_reg(data)   (*((volatile unsigned int*) GCOEFF_CHMVD_3_reg)=data)
#define get_GCOEFF_CHMVD_0_reg   (*((volatile unsigned int*) GCOEFF_CHMVD_0_reg))
#define get_GCOEFF_CHMVD_1_reg   (*((volatile unsigned int*) GCOEFF_CHMVD_1_reg))
#define get_GCOEFF_CHMVD_2_reg   (*((volatile unsigned int*) GCOEFF_CHMVD_2_reg))
#define get_GCOEFF_CHMVD_3_reg   (*((volatile unsigned int*) GCOEFF_CHMVD_3_reg))
#define GCOEFF_CHMVD_0_inst_adr                                                      "0x0041"
#define GCOEFF_CHMVD_1_inst_adr                                                      "0x0042"
#define GCOEFF_CHMVD_2_inst_adr                                                      "0x0043"
#define GCOEFF_CHMVD_3_inst_adr                                                      "0x0044"
#define GCOEFF_CHMVD_0_inst                                                          0x0041
#define GCOEFF_CHMVD_1_inst                                                          0x0042
#define GCOEFF_CHMVD_2_inst                                                          0x0043
#define GCOEFF_CHMVD_3_inst                                                          0x0044
#define GCOEFF_CHMVD_fmvx_shift                                                      (16)
#define GCOEFF_CHMVD_fmvx_mask                                                       (0x0FFF0000)
#define GCOEFF_CHMVD_fmvx(data)                                                      (0x0FFF0000&((data)<<16))
#define GCOEFF_CHMVD_fmvx_src(data)                                                  ((0x0FFF0000&(data))>>16)
#define GCOEFF_CHMVD_get_fmvx(data)                                                  ((0x0FFF0000&(data))>>16)
#define GCOEFF_CHMVD_fmvy_shift                                                      (0)
#define GCOEFF_CHMVD_fmvy_mask                                                       (0x000003FF)
#define GCOEFF_CHMVD_fmvy(data)                                                      (0x000003FF&((data)<<0))
#define GCOEFF_CHMVD_fmvy_src(data)                                                  ((0x000003FF&(data))>>0)
#define GCOEFF_CHMVD_get_fmvy(data)                                                  ((0x000003FF&(data))>>0)


#define GCOEFF_CHBMVD_0                                                              0x18036914
#define GCOEFF_CHBMVD_1                                                              0x18036918
#define GCOEFF_CHBMVD_2                                                              0x1803691C
#define GCOEFF_CHBMVD_3                                                              0x18036920
#define GCOEFF_CHBMVD_0_reg_addr                                                     "0xB8036914"
#define GCOEFF_CHBMVD_1_reg_addr                                                     "0xB8036918"
#define GCOEFF_CHBMVD_2_reg_addr                                                     "0xB803691C"
#define GCOEFF_CHBMVD_3_reg_addr                                                     "0xB8036920"
#define GCOEFF_CHBMVD_0_reg                                                          0xB8036914
#define GCOEFF_CHBMVD_1_reg                                                          0xB8036918
#define GCOEFF_CHBMVD_2_reg                                                          0xB803691C
#define GCOEFF_CHBMVD_3_reg                                                          0xB8036920
#define set_GCOEFF_CHBMVD_0_reg(data)   (*((volatile unsigned int*) GCOEFF_CHBMVD_0_reg)=data)
#define set_GCOEFF_CHBMVD_1_reg(data)   (*((volatile unsigned int*) GCOEFF_CHBMVD_1_reg)=data)
#define set_GCOEFF_CHBMVD_2_reg(data)   (*((volatile unsigned int*) GCOEFF_CHBMVD_2_reg)=data)
#define set_GCOEFF_CHBMVD_3_reg(data)   (*((volatile unsigned int*) GCOEFF_CHBMVD_3_reg)=data)
#define get_GCOEFF_CHBMVD_0_reg   (*((volatile unsigned int*) GCOEFF_CHBMVD_0_reg))
#define get_GCOEFF_CHBMVD_1_reg   (*((volatile unsigned int*) GCOEFF_CHBMVD_1_reg))
#define get_GCOEFF_CHBMVD_2_reg   (*((volatile unsigned int*) GCOEFF_CHBMVD_2_reg))
#define get_GCOEFF_CHBMVD_3_reg   (*((volatile unsigned int*) GCOEFF_CHBMVD_3_reg))
#define GCOEFF_CHBMVD_0_inst_adr                                                     "0x0045"
#define GCOEFF_CHBMVD_1_inst_adr                                                     "0x0046"
#define GCOEFF_CHBMVD_2_inst_adr                                                     "0x0047"
#define GCOEFF_CHBMVD_3_inst_adr                                                     "0x0048"
#define GCOEFF_CHBMVD_0_inst                                                         0x0045
#define GCOEFF_CHBMVD_1_inst                                                         0x0046
#define GCOEFF_CHBMVD_2_inst                                                         0x0047
#define GCOEFF_CHBMVD_3_inst                                                         0x0048
#define GCOEFF_CHBMVD_fmvx_shift                                                     (16)
#define GCOEFF_CHBMVD_fmvx_mask                                                      (0x0FFF0000)
#define GCOEFF_CHBMVD_fmvx(data)                                                     (0x0FFF0000&((data)<<16))
#define GCOEFF_CHBMVD_fmvx_src(data)                                                 ((0x0FFF0000&(data))>>16)
#define GCOEFF_CHBMVD_get_fmvx(data)                                                 ((0x0FFF0000&(data))>>16)
#define GCOEFF_CHBMVD_fmvy_shift                                                     (0)
#define GCOEFF_CHBMVD_fmvy_mask                                                      (0x000003FF)
#define GCOEFF_CHBMVD_fmvy(data)                                                     (0x000003FF&((data)<<0))
#define GCOEFF_CHBMVD_fmvy_src(data)                                                 ((0x000003FF&(data))>>0)
#define GCOEFF_CHBMVD_get_fmvy(data)                                                 ((0x000003FF&(data))>>0)


#define GCOEFF_SDMAADR                                                               0x18036834
#define GCOEFF_SDMAADR_reg_addr                                                      "0xB8036834"
#define GCOEFF_SDMAADR_reg                                                           0xB8036834
#define set_GCOEFF_SDMAADR_reg(data)   (*((volatile unsigned int*) GCOEFF_SDMAADR_reg)=data)
#define get_GCOEFF_SDMAADR_reg   (*((volatile unsigned int*) GCOEFF_SDMAADR_reg))
#define GCOEFF_SDMAADR_inst_adr                                                      "0x000D"
#define GCOEFF_SDMAADR_inst                                                          0x000D
#define GCOEFF_SDMAADR_seq_line_addr_shift                                           (0)
#define GCOEFF_SDMAADR_seq_line_addr_mask                                            (0xFFFFFFFF)
#define GCOEFF_SDMAADR_seq_line_addr(data)                                           (0xFFFFFFFF&((data)<<0))
#define GCOEFF_SDMAADR_seq_line_addr_src(data)                                       ((0xFFFFFFFF&(data))>>0)
#define GCOEFF_SDMAADR_get_seq_line_addr(data)                                       ((0xFFFFFFFF&(data))>>0)


#define GCOEFF_INTR_THRESH                                                           0x18036838
#define GCOEFF_INTR_THRESH_reg_addr                                                  "0xB8036838"
#define GCOEFF_INTR_THRESH_reg                                                       0xB8036838
#define set_GCOEFF_INTR_THRESH_reg(data)   (*((volatile unsigned int*) GCOEFF_INTR_THRESH_reg)=data)
#define get_GCOEFF_INTR_THRESH_reg   (*((volatile unsigned int*) GCOEFF_INTR_THRESH_reg))
#define GCOEFF_INTR_THRESH_inst_adr                                                  "0x000E"
#define GCOEFF_INTR_THRESH_inst                                                      0x000E
#define GCOEFF_INTR_THRESH_Value_shift                                               (0)
#define GCOEFF_INTR_THRESH_Value_mask                                                (0x0FFFFFFF)
#define GCOEFF_INTR_THRESH_Value(data)                                               (0x0FFFFFFF&((data)<<0))
#define GCOEFF_INTR_THRESH_Value_src(data)                                           ((0x0FFFFFFF&(data))>>0)
#define GCOEFF_INTR_THRESH_get_Value(data)                                           ((0x0FFFFFFF&(data))>>0)


#define GCOEFF_BUSY                                                                  0x1803683C
#define GCOEFF_BUSY_reg_addr                                                         "0xB803683C"
#define GCOEFF_BUSY_reg                                                              0xB803683C
#define set_GCOEFF_BUSY_reg(data)   (*((volatile unsigned int*) GCOEFF_BUSY_reg)=data)
#define get_GCOEFF_BUSY_reg   (*((volatile unsigned int*) GCOEFF_BUSY_reg))
#define GCOEFF_BUSY_inst_adr                                                         "0x000F"
#define GCOEFF_BUSY_inst                                                             0x000F
#define GCOEFF_BUSY_Reach_Thresh_shift                                               (28)
#define GCOEFF_BUSY_Reach_Thresh_mask                                                (0x10000000)
#define GCOEFF_BUSY_Reach_Thresh(data)                                               (0x10000000&((data)<<28))
#define GCOEFF_BUSY_Reach_Thresh_src(data)                                           ((0x10000000&(data))>>28)
#define GCOEFF_BUSY_get_Reach_Thresh(data)                                           ((0x10000000&(data))>>28)
#define GCOEFF_BUSY_Count_shift                                                      (0)
#define GCOEFF_BUSY_Count_mask                                                       (0x0FFFFFFF)
#define GCOEFF_BUSY_Count(data)                                                      (0x0FFFFFFF&((data)<<0))
#define GCOEFF_BUSY_Count_src(data)                                                  ((0x0FFFFFFF&(data))>>0)
#define GCOEFF_BUSY_get_Count(data)                                                  ((0x0FFFFFFF&(data))>>0)


#define GCOEFF_DBUS1                                                                 0x18036840
#define GCOEFF_DBUS1_reg_addr                                                        "0xB8036840"
#define GCOEFF_DBUS1_reg                                                             0xB8036840
#define set_GCOEFF_DBUS1_reg(data)   (*((volatile unsigned int*) GCOEFF_DBUS1_reg)=data)
#define get_GCOEFF_DBUS1_reg   (*((volatile unsigned int*) GCOEFF_DBUS1_reg))
#define GCOEFF_DBUS1_inst_adr                                                        "0x0010"
#define GCOEFF_DBUS1_inst                                                            0x0010
#define GCOEFF_DBUS1_GenPulse_shift                                                  (31)
#define GCOEFF_DBUS1_GenPulse_mask                                                   (0x80000000)
#define GCOEFF_DBUS1_GenPulse(data)                                                  (0x80000000&((data)<<31))
#define GCOEFF_DBUS1_GenPulse_src(data)                                              ((0x80000000&(data))>>31)
#define GCOEFF_DBUS1_get_GenPulse(data)                                              ((0x80000000&(data))>>31)
#define GCOEFF_DBUS1_DbgCtrl_shift                                                   (28)
#define GCOEFF_DBUS1_DbgCtrl_mask                                                    (0x70000000)
#define GCOEFF_DBUS1_DbgCtrl(data)                                                   (0x70000000&((data)<<28))
#define GCOEFF_DBUS1_DbgCtrl_src(data)                                               ((0x70000000&(data))>>28)
#define GCOEFF_DBUS1_get_DbgCtrl(data)                                               ((0x70000000&(data))>>28)
#define GCOEFF_DBUS1_PicCount_shift                                                  (14)
#define GCOEFF_DBUS1_PicCount_mask                                                   (0x0FFFC000)
#define GCOEFF_DBUS1_PicCount(data)                                                  (0x0FFFC000&((data)<<14))
#define GCOEFF_DBUS1_PicCount_src(data)                                              ((0x0FFFC000&(data))>>14)
#define GCOEFF_DBUS1_get_PicCount(data)                                              ((0x0FFFC000&(data))>>14)
#define GCOEFF_DBUS1_MbAddrX_shift                                                   (7)
#define GCOEFF_DBUS1_MbAddrX_mask                                                    (0x00003F80)
#define GCOEFF_DBUS1_MbAddrX(data)                                                   (0x00003F80&((data)<<7))
#define GCOEFF_DBUS1_MbAddrX_src(data)                                               ((0x00003F80&(data))>>7)
#define GCOEFF_DBUS1_get_MbAddrX(data)                                               ((0x00003F80&(data))>>7)
#define GCOEFF_DBUS1_MbAddrY_shift                                                   (0)
#define GCOEFF_DBUS1_MbAddrY_mask                                                    (0x0000007F)
#define GCOEFF_DBUS1_MbAddrY(data)                                                   (0x0000007F&((data)<<0))
#define GCOEFF_DBUS1_MbAddrY_src(data)                                               ((0x0000007F&(data))>>0)
#define GCOEFF_DBUS1_get_MbAddrY(data)                                               ((0x0000007F&(data))>>0)


#define GCOEFF_DBUS2                                                                 0x18036844
#define GCOEFF_DBUS2_reg_addr                                                        "0xB8036844"
#define GCOEFF_DBUS2_reg                                                             0xB8036844
#define set_GCOEFF_DBUS2_reg(data)   (*((volatile unsigned int*) GCOEFF_DBUS2_reg)=data)
#define get_GCOEFF_DBUS2_reg   (*((volatile unsigned int*) GCOEFF_DBUS2_reg))
#define GCOEFF_DBUS2_inst_adr                                                        "0x0011"
#define GCOEFF_DBUS2_inst                                                            0x0011
#define GCOEFF_DBUS2_DbgCtrl_shift                                                   (0)
#define GCOEFF_DBUS2_DbgCtrl_mask                                                    (0xFFFFFFFF)
#define GCOEFF_DBUS2_DbgCtrl(data)                                                   (0xFFFFFFFF&((data)<<0))
#define GCOEFF_DBUS2_DbgCtrl_src(data)                                               ((0xFFFFFFFF&(data))>>0)
#define GCOEFF_DBUS2_get_DbgCtrl(data)                                               ((0xFFFFFFFF&(data))>>0)


#define GCOEFF_BASEA                                                                 0x18036848
#define GCOEFF_BASEA_reg_addr                                                        "0xB8036848"
#define GCOEFF_BASEA_reg                                                             0xB8036848
#define set_GCOEFF_BASEA_reg(data)   (*((volatile unsigned int*) GCOEFF_BASEA_reg)=data)
#define get_GCOEFF_BASEA_reg   (*((volatile unsigned int*) GCOEFF_BASEA_reg))
#define GCOEFF_BASEA_inst_adr                                                        "0x0012"
#define GCOEFF_BASEA_inst                                                            0x0012
#define GCOEFF_BASEA_Vmadr_en_shift                                                  (23)
#define GCOEFF_BASEA_Vmadr_en_mask                                                   (0x00800000)
#define GCOEFF_BASEA_Vmadr_en(data)                                                  (0x00800000&((data)<<23))
#define GCOEFF_BASEA_Vmadr_en_src(data)                                              ((0x00800000&(data))>>23)
#define GCOEFF_BASEA_get_Vmadr_en(data)                                              ((0x00800000&(data))>>23)
#define GCOEFF_BASEA_BaseA0_shift                                                    (16)
#define GCOEFF_BASEA_BaseA0_mask                                                     (0x007F0000)
#define GCOEFF_BASEA_BaseA0(data)                                                    (0x007F0000&((data)<<16))
#define GCOEFF_BASEA_BaseA0_src(data)                                                ((0x007F0000&(data))>>16)
#define GCOEFF_BASEA_get_BaseA0(data)                                                ((0x007F0000&(data))>>16)


#define GCOEFF_OFFSETA_0                                                             0x1803684C
#define GCOEFF_OFFSETA_1                                                             0x18036850
#define GCOEFF_OFFSETA_0_reg_addr                                                    "0xB803684C"
#define GCOEFF_OFFSETA_1_reg_addr                                                    "0xB8036850"
#define GCOEFF_OFFSETA_0_reg                                                         0xB803684C
#define GCOEFF_OFFSETA_1_reg                                                         0xB8036850
#define set_GCOEFF_OFFSETA_0_reg(data)   (*((volatile unsigned int*) GCOEFF_OFFSETA_0_reg)=data)
#define set_GCOEFF_OFFSETA_1_reg(data)   (*((volatile unsigned int*) GCOEFF_OFFSETA_1_reg)=data)
#define get_GCOEFF_OFFSETA_0_reg   (*((volatile unsigned int*) GCOEFF_OFFSETA_0_reg))
#define get_GCOEFF_OFFSETA_1_reg   (*((volatile unsigned int*) GCOEFF_OFFSETA_1_reg))
#define GCOEFF_OFFSETA_0_inst_adr                                                    "0x0013"
#define GCOEFF_OFFSETA_1_inst_adr                                                    "0x0014"
#define GCOEFF_OFFSETA_0_inst                                                        0x0013
#define GCOEFF_OFFSETA_1_inst                                                        0x0014
#define GCOEFF_OFFSETA_OffsetA_shift                                                 (3)
#define GCOEFF_OFFSETA_OffsetA_mask                                                  (0x000003F8)
#define GCOEFF_OFFSETA_OffsetA(data)                                                 (0x000003F8&((data)<<3))
#define GCOEFF_OFFSETA_OffsetA_src(data)                                             ((0x000003F8&(data))>>3)
#define GCOEFF_OFFSETA_get_OffsetA(data)                                             ((0x000003F8&(data))>>3)


#define GCOEFF_DEBPAR                                                                0x18036924
#define GCOEFF_DEBPAR_reg_addr                                                       "0xB8036924"
#define GCOEFF_DEBPAR_reg                                                            0xB8036924
#define set_GCOEFF_DEBPAR_reg(data)   (*((volatile unsigned int*) GCOEFF_DEBPAR_reg)=data)
#define get_GCOEFF_DEBPAR_reg   (*((volatile unsigned int*) GCOEFF_DEBPAR_reg))
#define GCOEFF_DEBPAR_inst_adr                                                       "0x0049"
#define GCOEFF_DEBPAR_inst                                                           0x0049
#define GCOEFF_DEBPAR_StartA_shift                                                   (0)
#define GCOEFF_DEBPAR_StartA_mask                                                    (0x0000007F)
#define GCOEFF_DEBPAR_StartA(data)                                                   (0x0000007F&((data)<<0))
#define GCOEFF_DEBPAR_StartA_src(data)                                               ((0x0000007F&(data))>>0)
#define GCOEFF_DEBPAR_get_StartA(data)                                               ((0x0000007F&(data))>>0)


#define GCOEFF_CBPCTRL                                                               0x18036854
#define GCOEFF_CBPCTRL_reg_addr                                                      "0xB8036854"
#define GCOEFF_CBPCTRL_reg                                                           0xB8036854
#define set_GCOEFF_CBPCTRL_reg(data)   (*((volatile unsigned int*) GCOEFF_CBPCTRL_reg)=data)
#define get_GCOEFF_CBPCTRL_reg   (*((volatile unsigned int*) GCOEFF_CBPCTRL_reg))
#define GCOEFF_CBPCTRL_inst_adr                                                      "0x0015"
#define GCOEFF_CBPCTRL_inst                                                          0x0015
#define GCOEFF_CBPCTRL_IntraLumaStyleSel_shift                                       (5)
#define GCOEFF_CBPCTRL_IntraLumaStyleSel_mask                                        (0x00000020)
#define GCOEFF_CBPCTRL_IntraLumaStyleSel(data)                                       (0x00000020&((data)<<5))
#define GCOEFF_CBPCTRL_IntraLumaStyleSel_src(data)                                   ((0x00000020&(data))>>5)
#define GCOEFF_CBPCTRL_get_IntraLumaStyleSel(data)                                   ((0x00000020&(data))>>5)
#define GCOEFF_CBPCTRL_XVID_combine_style_shift                                      (3)
#define GCOEFF_CBPCTRL_XVID_combine_style_mask                                       (0x00000018)
#define GCOEFF_CBPCTRL_XVID_combine_style(data)                                      (0x00000018&((data)<<3))
#define GCOEFF_CBPCTRL_XVID_combine_style_src(data)                                  ((0x00000018&(data))>>3)
#define GCOEFF_CBPCTRL_get_XVID_combine_style(data)                                  ((0x00000018&(data))>>3)
#define GCOEFF_CBPCTRL_Style_Sel_shift                                               (0)
#define GCOEFF_CBPCTRL_Style_Sel_mask                                                (0x00000007)
#define GCOEFF_CBPCTRL_Style_Sel(data)                                               (0x00000007&((data)<<0))
#define GCOEFF_CBPCTRL_Style_Sel_src(data)                                           ((0x00000007&(data))>>0)
#define GCOEFF_CBPCTRL_get_Style_Sel(data)                                           ((0x00000007&(data))>>0)


#define GCOEFF_SUMRUNCOST_8X8_0                                                      0x18036858
#define GCOEFF_SUMRUNCOST_8X8_1                                                      0x1803685C
#define GCOEFF_SUMRUNCOST_8X8_2                                                      0x18036860
#define GCOEFF_SUMRUNCOST_8X8_3                                                      0x18036864
#define GCOEFF_SUMRUNCOST_8X8_4                                                      0x18036868
#define GCOEFF_SUMRUNCOST_8X8_5                                                      0x1803686C
#define GCOEFF_SUMRUNCOST_8X8_6                                                      0x18036870
#define GCOEFF_SUMRUNCOST_8X8_7                                                      0x18036874
#define GCOEFF_SUMRUNCOST_8X8_0_reg_addr                                             "0xB8036858"
#define GCOEFF_SUMRUNCOST_8X8_1_reg_addr                                             "0xB803685C"
#define GCOEFF_SUMRUNCOST_8X8_2_reg_addr                                             "0xB8036860"
#define GCOEFF_SUMRUNCOST_8X8_3_reg_addr                                             "0xB8036864"
#define GCOEFF_SUMRUNCOST_8X8_4_reg_addr                                             "0xB8036868"
#define GCOEFF_SUMRUNCOST_8X8_5_reg_addr                                             "0xB803686C"
#define GCOEFF_SUMRUNCOST_8X8_6_reg_addr                                             "0xB8036870"
#define GCOEFF_SUMRUNCOST_8X8_7_reg_addr                                             "0xB8036874"
#define GCOEFF_SUMRUNCOST_8X8_0_reg                                                  0xB8036858
#define GCOEFF_SUMRUNCOST_8X8_1_reg                                                  0xB803685C
#define GCOEFF_SUMRUNCOST_8X8_2_reg                                                  0xB8036860
#define GCOEFF_SUMRUNCOST_8X8_3_reg                                                  0xB8036864
#define GCOEFF_SUMRUNCOST_8X8_4_reg                                                  0xB8036868
#define GCOEFF_SUMRUNCOST_8X8_5_reg                                                  0xB803686C
#define GCOEFF_SUMRUNCOST_8X8_6_reg                                                  0xB8036870
#define GCOEFF_SUMRUNCOST_8X8_7_reg                                                  0xB8036874
#define set_GCOEFF_SUMRUNCOST_8X8_0_reg(data)   (*((volatile unsigned int*) GCOEFF_SUMRUNCOST_8X8_0_reg)=data)
#define set_GCOEFF_SUMRUNCOST_8X8_1_reg(data)   (*((volatile unsigned int*) GCOEFF_SUMRUNCOST_8X8_1_reg)=data)
#define set_GCOEFF_SUMRUNCOST_8X8_2_reg(data)   (*((volatile unsigned int*) GCOEFF_SUMRUNCOST_8X8_2_reg)=data)
#define set_GCOEFF_SUMRUNCOST_8X8_3_reg(data)   (*((volatile unsigned int*) GCOEFF_SUMRUNCOST_8X8_3_reg)=data)
#define set_GCOEFF_SUMRUNCOST_8X8_4_reg(data)   (*((volatile unsigned int*) GCOEFF_SUMRUNCOST_8X8_4_reg)=data)
#define set_GCOEFF_SUMRUNCOST_8X8_5_reg(data)   (*((volatile unsigned int*) GCOEFF_SUMRUNCOST_8X8_5_reg)=data)
#define set_GCOEFF_SUMRUNCOST_8X8_6_reg(data)   (*((volatile unsigned int*) GCOEFF_SUMRUNCOST_8X8_6_reg)=data)
#define set_GCOEFF_SUMRUNCOST_8X8_7_reg(data)   (*((volatile unsigned int*) GCOEFF_SUMRUNCOST_8X8_7_reg)=data)
#define get_GCOEFF_SUMRUNCOST_8X8_0_reg   (*((volatile unsigned int*) GCOEFF_SUMRUNCOST_8X8_0_reg))
#define get_GCOEFF_SUMRUNCOST_8X8_1_reg   (*((volatile unsigned int*) GCOEFF_SUMRUNCOST_8X8_1_reg))
#define get_GCOEFF_SUMRUNCOST_8X8_2_reg   (*((volatile unsigned int*) GCOEFF_SUMRUNCOST_8X8_2_reg))
#define get_GCOEFF_SUMRUNCOST_8X8_3_reg   (*((volatile unsigned int*) GCOEFF_SUMRUNCOST_8X8_3_reg))
#define get_GCOEFF_SUMRUNCOST_8X8_4_reg   (*((volatile unsigned int*) GCOEFF_SUMRUNCOST_8X8_4_reg))
#define get_GCOEFF_SUMRUNCOST_8X8_5_reg   (*((volatile unsigned int*) GCOEFF_SUMRUNCOST_8X8_5_reg))
#define get_GCOEFF_SUMRUNCOST_8X8_6_reg   (*((volatile unsigned int*) GCOEFF_SUMRUNCOST_8X8_6_reg))
#define get_GCOEFF_SUMRUNCOST_8X8_7_reg   (*((volatile unsigned int*) GCOEFF_SUMRUNCOST_8X8_7_reg))
#define GCOEFF_SUMRUNCOST_8X8_0_inst_adr                                             "0x0016"
#define GCOEFF_SUMRUNCOST_8X8_1_inst_adr                                             "0x0017"
#define GCOEFF_SUMRUNCOST_8X8_2_inst_adr                                             "0x0018"
#define GCOEFF_SUMRUNCOST_8X8_3_inst_adr                                             "0x0019"
#define GCOEFF_SUMRUNCOST_8X8_4_inst_adr                                             "0x001A"
#define GCOEFF_SUMRUNCOST_8X8_5_inst_adr                                             "0x001B"
#define GCOEFF_SUMRUNCOST_8X8_6_inst_adr                                             "0x001C"
#define GCOEFF_SUMRUNCOST_8X8_7_inst_adr                                             "0x001D"
#define GCOEFF_SUMRUNCOST_8X8_0_inst                                                 0x0016
#define GCOEFF_SUMRUNCOST_8X8_1_inst                                                 0x0017
#define GCOEFF_SUMRUNCOST_8X8_2_inst                                                 0x0018
#define GCOEFF_SUMRUNCOST_8X8_3_inst                                                 0x0019
#define GCOEFF_SUMRUNCOST_8X8_4_inst                                                 0x001A
#define GCOEFF_SUMRUNCOST_8X8_5_inst                                                 0x001B
#define GCOEFF_SUMRUNCOST_8X8_6_inst                                                 0x001C
#define GCOEFF_SUMRUNCOST_8X8_7_inst                                                 0x001D
#define GCOEFF_SUMRUNCOST_8X8_Lookup_shift                                           (0)
#define GCOEFF_SUMRUNCOST_8X8_Lookup_mask                                            (0xFFFFFFFF)
#define GCOEFF_SUMRUNCOST_8X8_Lookup(data)                                           (0xFFFFFFFF&((data)<<0))
#define GCOEFF_SUMRUNCOST_8X8_Lookup_src(data)                                       ((0xFFFFFFFF&(data))>>0)
#define GCOEFF_SUMRUNCOST_8X8_get_Lookup(data)                                       ((0xFFFFFFFF&(data))>>0)


#define GCOEFF_SUMRUNCOST_4X4_0                                                      0x18036878
#define GCOEFF_SUMRUNCOST_4X4_1                                                      0x1803687C
#define GCOEFF_SUMRUNCOST_4X4_0_reg_addr                                             "0xB8036878"
#define GCOEFF_SUMRUNCOST_4X4_1_reg_addr                                             "0xB803687C"
#define GCOEFF_SUMRUNCOST_4X4_0_reg                                                  0xB8036878
#define GCOEFF_SUMRUNCOST_4X4_1_reg                                                  0xB803687C
#define set_GCOEFF_SUMRUNCOST_4X4_0_reg(data)   (*((volatile unsigned int*) GCOEFF_SUMRUNCOST_4X4_0_reg)=data)
#define set_GCOEFF_SUMRUNCOST_4X4_1_reg(data)   (*((volatile unsigned int*) GCOEFF_SUMRUNCOST_4X4_1_reg)=data)
#define get_GCOEFF_SUMRUNCOST_4X4_0_reg   (*((volatile unsigned int*) GCOEFF_SUMRUNCOST_4X4_0_reg))
#define get_GCOEFF_SUMRUNCOST_4X4_1_reg   (*((volatile unsigned int*) GCOEFF_SUMRUNCOST_4X4_1_reg))
#define GCOEFF_SUMRUNCOST_4X4_0_inst_adr                                             "0x001E"
#define GCOEFF_SUMRUNCOST_4X4_1_inst_adr                                             "0x001F"
#define GCOEFF_SUMRUNCOST_4X4_0_inst                                                 0x001E
#define GCOEFF_SUMRUNCOST_4X4_1_inst                                                 0x001F
#define GCOEFF_SUMRUNCOST_4X4_Lookup_shift                                           (0)
#define GCOEFF_SUMRUNCOST_4X4_Lookup_mask                                            (0xFFFFFFFF)
#define GCOEFF_SUMRUNCOST_4X4_Lookup(data)                                           (0xFFFFFFFF&((data)<<0))
#define GCOEFF_SUMRUNCOST_4X4_Lookup_src(data)                                       ((0xFFFFFFFF&(data))>>0)
#define GCOEFF_SUMRUNCOST_4X4_get_Lookup(data)                                       ((0xFFFFFFFF&(data))>>0)


#define GCOEFF_SUMRUNCOST_THR                                                        0x18036880
#define GCOEFF_SUMRUNCOST_THR_reg_addr                                               "0xB8036880"
#define GCOEFF_SUMRUNCOST_THR_reg                                                    0xB8036880
#define set_GCOEFF_SUMRUNCOST_THR_reg(data)   (*((volatile unsigned int*) GCOEFF_SUMRUNCOST_THR_reg)=data)
#define get_GCOEFF_SUMRUNCOST_THR_reg   (*((volatile unsigned int*) GCOEFF_SUMRUNCOST_THR_reg))
#define GCOEFF_SUMRUNCOST_THR_inst_adr                                               "0x0020"
#define GCOEFF_SUMRUNCOST_THR_inst                                                   0x0020
#define GCOEFF_SUMRUNCOST_THR_T4x4_shift                                             (16)
#define GCOEFF_SUMRUNCOST_THR_T4x4_mask                                              (0x07FF0000)
#define GCOEFF_SUMRUNCOST_THR_T4x4(data)                                             (0x07FF0000&((data)<<16))
#define GCOEFF_SUMRUNCOST_THR_T4x4_src(data)                                         ((0x07FF0000&(data))>>16)
#define GCOEFF_SUMRUNCOST_THR_get_T4x4(data)                                         ((0x07FF0000&(data))>>16)
#define GCOEFF_SUMRUNCOST_THR_T8x8_shift                                             (0)
#define GCOEFF_SUMRUNCOST_THR_T8x8_mask                                              (0x000007FF)
#define GCOEFF_SUMRUNCOST_THR_T8x8(data)                                             (0x000007FF&((data)<<0))
#define GCOEFF_SUMRUNCOST_THR_T8x8_src(data)                                         ((0x000007FF&(data))>>0)
#define GCOEFF_SUMRUNCOST_THR_get_T8x8(data)                                         ((0x000007FF&(data))>>0)


#define GCOEFF_FIRSTCFF                                                              0x18036884
#define GCOEFF_FIRSTCFF_reg_addr                                                     "0xB8036884"
#define GCOEFF_FIRSTCFF_reg                                                          0xB8036884
#define set_GCOEFF_FIRSTCFF_reg(data)   (*((volatile unsigned int*) GCOEFF_FIRSTCFF_reg)=data)
#define get_GCOEFF_FIRSTCFF_reg   (*((volatile unsigned int*) GCOEFF_FIRSTCFF_reg))
#define GCOEFF_FIRSTCFF_inst_adr                                                     "0x0021"
#define GCOEFF_FIRSTCFF_inst                                                         0x0021
#define GCOEFF_FIRSTCFF_T4x4_shift                                                   (16)
#define GCOEFF_FIRSTCFF_T4x4_mask                                                    (0x001F0000)
#define GCOEFF_FIRSTCFF_T4x4(data)                                                   (0x001F0000&((data)<<16))
#define GCOEFF_FIRSTCFF_T4x4_src(data)                                               ((0x001F0000&(data))>>16)
#define GCOEFF_FIRSTCFF_get_T4x4(data)                                               ((0x001F0000&(data))>>16)
#define GCOEFF_FIRSTCFF_T8x8_shift                                                   (0)
#define GCOEFF_FIRSTCFF_T8x8_mask                                                    (0x0000007F)
#define GCOEFF_FIRSTCFF_T8x8(data)                                                   (0x0000007F&((data)<<0))
#define GCOEFF_FIRSTCFF_T8x8_src(data)                                               ((0x0000007F&(data))>>0)
#define GCOEFF_FIRSTCFF_get_T8x8(data)                                               ((0x0000007F&(data))>>0)


#define GCOEFF_SUMCFF                                                                0x18036888
#define GCOEFF_SUMCFF_reg_addr                                                       "0xB8036888"
#define GCOEFF_SUMCFF_reg                                                            0xB8036888
#define set_GCOEFF_SUMCFF_reg(data)   (*((volatile unsigned int*) GCOEFF_SUMCFF_reg)=data)
#define get_GCOEFF_SUMCFF_reg   (*((volatile unsigned int*) GCOEFF_SUMCFF_reg))
#define GCOEFF_SUMCFF_inst_adr                                                       "0x0022"
#define GCOEFF_SUMCFF_inst                                                           0x0022
#define GCOEFF_SUMCFF_T4x4_shift                                                     (8)
#define GCOEFF_SUMCFF_T4x4_mask                                                      (0x0000FF00)
#define GCOEFF_SUMCFF_T4x4(data)                                                     (0x0000FF00&((data)<<8))
#define GCOEFF_SUMCFF_T4x4_src(data)                                                 ((0x0000FF00&(data))>>8)
#define GCOEFF_SUMCFF_get_T4x4(data)                                                 ((0x0000FF00&(data))>>8)
#define GCOEFF_SUMCFF_T8x8_shift                                                     (0)
#define GCOEFF_SUMCFF_T8x8_mask                                                      (0x000000FF)
#define GCOEFF_SUMCFF_T8x8(data)                                                     (0x000000FF&((data)<<0))
#define GCOEFF_SUMCFF_T8x8_src(data)                                                 ((0x000000FF&(data))>>0)
#define GCOEFF_SUMCFF_get_T8x8(data)                                                 ((0x000000FF&(data))>>0)


#define GCOEFF_CHROMA_LD                                                             0x1803688C
#define GCOEFF_CHROMA_LD_reg_addr                                                    "0xB803688C"
#define GCOEFF_CHROMA_LD_reg                                                         0xB803688C
#define set_GCOEFF_CHROMA_LD_reg(data)   (*((volatile unsigned int*) GCOEFF_CHROMA_LD_reg)=data)
#define get_GCOEFF_CHROMA_LD_reg   (*((volatile unsigned int*) GCOEFF_CHROMA_LD_reg))
#define GCOEFF_CHROMA_LD_inst_adr                                                    "0x0023"
#define GCOEFF_CHROMA_LD_inst                                                        0x0023
#define GCOEFF_CHROMA_LD_List1Idx0_shift                                             (14)
#define GCOEFF_CHROMA_LD_List1Idx0_mask                                              (0x001FC000)
#define GCOEFF_CHROMA_LD_List1Idx0(data)                                             (0x001FC000&((data)<<14))
#define GCOEFF_CHROMA_LD_List1Idx0_src(data)                                         ((0x001FC000&(data))>>14)
#define GCOEFF_CHROMA_LD_get_List1Idx0(data)                                         ((0x001FC000&(data))>>14)
#define GCOEFF_CHROMA_LD_List0Idx1_shift                                             (7)
#define GCOEFF_CHROMA_LD_List0Idx1_mask                                              (0x00003F80)
#define GCOEFF_CHROMA_LD_List0Idx1(data)                                             (0x00003F80&((data)<<7))
#define GCOEFF_CHROMA_LD_List0Idx1_src(data)                                         ((0x00003F80&(data))>>7)
#define GCOEFF_CHROMA_LD_get_List0Idx1(data)                                         ((0x00003F80&(data))>>7)
#define GCOEFF_CHROMA_LD_List0Idx0_shift                                             (0)
#define GCOEFF_CHROMA_LD_List0Idx0_mask                                              (0x0000007F)
#define GCOEFF_CHROMA_LD_List0Idx0(data)                                             (0x0000007F&((data)<<0))
#define GCOEFF_CHROMA_LD_List0Idx0_src(data)                                         ((0x0000007F&(data))>>0)
#define GCOEFF_CHROMA_LD_get_List0Idx0(data)                                         ((0x0000007F&(data))>>0)


#define GCOEFF_INTRAMODE_0                                                           0x18036890
#define GCOEFF_INTRAMODE_1                                                           0x18036894
#define GCOEFF_INTRAMODE_2                                                           0x18036898
#define GCOEFF_INTRAMODE_0_reg_addr                                                  "0xB8036890"
#define GCOEFF_INTRAMODE_1_reg_addr                                                  "0xB8036894"
#define GCOEFF_INTRAMODE_2_reg_addr                                                  "0xB8036898"
#define GCOEFF_INTRAMODE_0_reg                                                       0xB8036890
#define GCOEFF_INTRAMODE_1_reg                                                       0xB8036894
#define GCOEFF_INTRAMODE_2_reg                                                       0xB8036898
#define set_GCOEFF_INTRAMODE_0_reg(data)   (*((volatile unsigned int*) GCOEFF_INTRAMODE_0_reg)=data)
#define set_GCOEFF_INTRAMODE_1_reg(data)   (*((volatile unsigned int*) GCOEFF_INTRAMODE_1_reg)=data)
#define set_GCOEFF_INTRAMODE_2_reg(data)   (*((volatile unsigned int*) GCOEFF_INTRAMODE_2_reg)=data)
#define get_GCOEFF_INTRAMODE_0_reg   (*((volatile unsigned int*) GCOEFF_INTRAMODE_0_reg))
#define get_GCOEFF_INTRAMODE_1_reg   (*((volatile unsigned int*) GCOEFF_INTRAMODE_1_reg))
#define get_GCOEFF_INTRAMODE_2_reg   (*((volatile unsigned int*) GCOEFF_INTRAMODE_2_reg))
#define GCOEFF_INTRAMODE_0_inst_adr                                                  "0x0024"
#define GCOEFF_INTRAMODE_1_inst_adr                                                  "0x0025"
#define GCOEFF_INTRAMODE_2_inst_adr                                                  "0x0026"
#define GCOEFF_INTRAMODE_0_inst                                                      0x0024
#define GCOEFF_INTRAMODE_1_inst                                                      0x0025
#define GCOEFF_INTRAMODE_2_inst                                                      0x0026
#define GCOEFF_INTRAMODE_Value_shift                                                 (0)
#define GCOEFF_INTRAMODE_Value_mask                                                  (0xFFFFFFFF)
#define GCOEFF_INTRAMODE_Value(data)                                                 (0xFFFFFFFF&((data)<<0))
#define GCOEFF_INTRAMODE_Value_src(data)                                             ((0xFFFFFFFF&(data))>>0)
#define GCOEFF_INTRAMODE_get_Value(data)                                             ((0xFFFFFFFF&(data))>>0)


#define GCOEFF_SLICE                                                                 0x1803689C
#define GCOEFF_SLICE_reg_addr                                                        "0xB803689C"
#define GCOEFF_SLICE_reg                                                             0xB803689C
#define set_GCOEFF_SLICE_reg(data)   (*((volatile unsigned int*) GCOEFF_SLICE_reg)=data)
#define get_GCOEFF_SLICE_reg   (*((volatile unsigned int*) GCOEFF_SLICE_reg))
#define GCOEFF_SLICE_inst_adr                                                        "0x0027"
#define GCOEFF_SLICE_inst                                                            0x0027
#define GCOEFF_SLICE_y_shift                                                         (0)
#define GCOEFF_SLICE_y_mask                                                          (0x0000007F)
#define GCOEFF_SLICE_y(data)                                                         (0x0000007F&((data)<<0))
#define GCOEFF_SLICE_y_src(data)                                                     ((0x0000007F&(data))>>0)
#define GCOEFF_SLICE_get_y(data)                                                     ((0x0000007F&(data))>>0)


#define GCOEFF_MBLEVEL_DROP                                                          0x180368A0
#define GCOEFF_MBLEVEL_DROP_reg_addr                                                 "0xB80368A0"
#define GCOEFF_MBLEVEL_DROP_reg                                                      0xB80368A0
#define set_GCOEFF_MBLEVEL_DROP_reg(data)   (*((volatile unsigned int*) GCOEFF_MBLEVEL_DROP_reg)=data)
#define get_GCOEFF_MBLEVEL_DROP_reg   (*((volatile unsigned int*) GCOEFF_MBLEVEL_DROP_reg))
#define GCOEFF_MBLEVEL_DROP_inst_adr                                                 "0x0028"
#define GCOEFF_MBLEVEL_DROP_inst                                                     0x0028
#define GCOEFF_MBLEVEL_DROP_Enable_shift                                             (13)
#define GCOEFF_MBLEVEL_DROP_Enable_mask                                              (0x00002000)
#define GCOEFF_MBLEVEL_DROP_Enable(data)                                             (0x00002000&((data)<<13))
#define GCOEFF_MBLEVEL_DROP_Enable_src(data)                                         ((0x00002000&(data))>>13)
#define GCOEFF_MBLEVEL_DROP_get_Enable(data)                                         ((0x00002000&(data))>>13)
#define GCOEFF_MBLEVEL_DROP_Thresh_shift                                             (0)
#define GCOEFF_MBLEVEL_DROP_Thresh_mask                                              (0x00001FFF)
#define GCOEFF_MBLEVEL_DROP_Thresh(data)                                             (0x00001FFF&((data)<<0))
#define GCOEFF_MBLEVEL_DROP_Thresh_src(data)                                         ((0x00001FFF&(data))>>0)
#define GCOEFF_MBLEVEL_DROP_get_Thresh(data)                                         ((0x00001FFF&(data))>>0)


#define GCOEFF_SUMRUNCOST_THR_CHR                                                    0x180368A4
#define GCOEFF_SUMRUNCOST_THR_CHR_reg_addr                                           "0xB80368A4"
#define GCOEFF_SUMRUNCOST_THR_CHR_reg                                                0xB80368A4
#define set_GCOEFF_SUMRUNCOST_THR_CHR_reg(data)   (*((volatile unsigned int*) GCOEFF_SUMRUNCOST_THR_CHR_reg)=data)
#define get_GCOEFF_SUMRUNCOST_THR_CHR_reg   (*((volatile unsigned int*) GCOEFF_SUMRUNCOST_THR_CHR_reg))
#define GCOEFF_SUMRUNCOST_THR_CHR_inst_adr                                           "0x0029"
#define GCOEFF_SUMRUNCOST_THR_CHR_inst                                               0x0029
#define GCOEFF_SUMRUNCOST_THR_CHR_T4x4_shift                                         (16)
#define GCOEFF_SUMRUNCOST_THR_CHR_T4x4_mask                                          (0x07FF0000)
#define GCOEFF_SUMRUNCOST_THR_CHR_T4x4(data)                                         (0x07FF0000&((data)<<16))
#define GCOEFF_SUMRUNCOST_THR_CHR_T4x4_src(data)                                     ((0x07FF0000&(data))>>16)
#define GCOEFF_SUMRUNCOST_THR_CHR_get_T4x4(data)                                     ((0x07FF0000&(data))>>16)


#define GCOEFF_FIRSTCFF_CHR                                                          0x180368A8
#define GCOEFF_FIRSTCFF_CHR_reg_addr                                                 "0xB80368A8"
#define GCOEFF_FIRSTCFF_CHR_reg                                                      0xB80368A8
#define set_GCOEFF_FIRSTCFF_CHR_reg(data)   (*((volatile unsigned int*) GCOEFF_FIRSTCFF_CHR_reg)=data)
#define get_GCOEFF_FIRSTCFF_CHR_reg   (*((volatile unsigned int*) GCOEFF_FIRSTCFF_CHR_reg))
#define GCOEFF_FIRSTCFF_CHR_inst_adr                                                 "0x002A"
#define GCOEFF_FIRSTCFF_CHR_inst                                                     0x002A
#define GCOEFF_FIRSTCFF_CHR_T4x4_shift                                               (16)
#define GCOEFF_FIRSTCFF_CHR_T4x4_mask                                                (0x001F0000)
#define GCOEFF_FIRSTCFF_CHR_T4x4(data)                                               (0x001F0000&((data)<<16))
#define GCOEFF_FIRSTCFF_CHR_T4x4_src(data)                                           ((0x001F0000&(data))>>16)
#define GCOEFF_FIRSTCFF_CHR_get_T4x4(data)                                           ((0x001F0000&(data))>>16)


#define GCOEFF_SUMCFF_CHR                                                            0x180368AC
#define GCOEFF_SUMCFF_CHR_reg_addr                                                   "0xB80368AC"
#define GCOEFF_SUMCFF_CHR_reg                                                        0xB80368AC
#define set_GCOEFF_SUMCFF_CHR_reg(data)   (*((volatile unsigned int*) GCOEFF_SUMCFF_CHR_reg)=data)
#define get_GCOEFF_SUMCFF_CHR_reg   (*((volatile unsigned int*) GCOEFF_SUMCFF_CHR_reg))
#define GCOEFF_SUMCFF_CHR_inst_adr                                                   "0x002B"
#define GCOEFF_SUMCFF_CHR_inst                                                       0x002B
#define GCOEFF_SUMCFF_CHR_T4x4_shift                                                 (8)
#define GCOEFF_SUMCFF_CHR_T4x4_mask                                                  (0x0000FF00)
#define GCOEFF_SUMCFF_CHR_T4x4(data)                                                 (0x0000FF00&((data)<<8))
#define GCOEFF_SUMCFF_CHR_T4x4_src(data)                                             ((0x0000FF00&(data))>>8)
#define GCOEFF_SUMCFF_CHR_get_T4x4(data)                                             ((0x0000FF00&(data))>>8)


#define GCOEFF_ULPRED                                                                0x180368B0
#define GCOEFF_ULPRED_reg_addr                                                       "0xB80368B0"
#define GCOEFF_ULPRED_reg                                                            0xB80368B0
#define set_GCOEFF_ULPRED_reg(data)   (*((volatile unsigned int*) GCOEFF_ULPRED_reg)=data)
#define get_GCOEFF_ULPRED_reg   (*((volatile unsigned int*) GCOEFF_ULPRED_reg))
#define GCOEFF_ULPRED_inst_adr                                                       "0x002C"
#define GCOEFF_ULPRED_inst                                                           0x002C
#define GCOEFF_ULPRED_Luma_wr_shift                                                  (26)
#define GCOEFF_ULPRED_Luma_wr_mask                                                   (0x04000000)
#define GCOEFF_ULPRED_Luma_wr(data)                                                  (0x04000000&((data)<<26))
#define GCOEFF_ULPRED_Luma_wr_src(data)                                              ((0x04000000&(data))>>26)
#define GCOEFF_ULPRED_get_Luma_wr(data)                                              ((0x04000000&(data))>>26)
#define GCOEFF_ULPRED_CB_wr_shift                                                    (25)
#define GCOEFF_ULPRED_CB_wr_mask                                                     (0x02000000)
#define GCOEFF_ULPRED_CB_wr(data)                                                    (0x02000000&((data)<<25))
#define GCOEFF_ULPRED_CB_wr_src(data)                                                ((0x02000000&(data))>>25)
#define GCOEFF_ULPRED_get_CB_wr(data)                                                ((0x02000000&(data))>>25)
#define GCOEFF_ULPRED_CR_wr_shift                                                    (24)
#define GCOEFF_ULPRED_CR_wr_mask                                                     (0x01000000)
#define GCOEFF_ULPRED_CR_wr(data)                                                    (0x01000000&((data)<<24))
#define GCOEFF_ULPRED_CR_wr_src(data)                                                ((0x01000000&(data))>>24)
#define GCOEFF_ULPRED_get_CR_wr(data)                                                ((0x01000000&(data))>>24)
#define GCOEFF_ULPRED_Luma_shift                                                     (16)
#define GCOEFF_ULPRED_Luma_mask                                                      (0x00FF0000)
#define GCOEFF_ULPRED_Luma(data)                                                     (0x00FF0000&((data)<<16))
#define GCOEFF_ULPRED_Luma_src(data)                                                 ((0x00FF0000&(data))>>16)
#define GCOEFF_ULPRED_get_Luma(data)                                                 ((0x00FF0000&(data))>>16)
#define GCOEFF_ULPRED_CB_shift                                                       (8)
#define GCOEFF_ULPRED_CB_mask                                                        (0x0000FF00)
#define GCOEFF_ULPRED_CB(data)                                                       (0x0000FF00&((data)<<8))
#define GCOEFF_ULPRED_CB_src(data)                                                   ((0x0000FF00&(data))>>8)
#define GCOEFF_ULPRED_get_CB(data)                                                   ((0x0000FF00&(data))>>8)
#define GCOEFF_ULPRED_CR_shift                                                       (0)
#define GCOEFF_ULPRED_CR_mask                                                        (0x000000FF)
#define GCOEFF_ULPRED_CR(data)                                                       (0x000000FF&((data)<<0))
#define GCOEFF_ULPRED_CR_src(data)                                                   ((0x000000FF&(data))>>0)
#define GCOEFF_ULPRED_get_CR(data)                                                   ((0x000000FF&(data))>>0)


#define GCOEFF_PMEMCTL_DBG                                                           0x180368B4
#define GCOEFF_PMEMCTL_DBG_reg_addr                                                  "0xB80368B4"
#define GCOEFF_PMEMCTL_DBG_reg                                                       0xB80368B4
#define set_GCOEFF_PMEMCTL_DBG_reg(data)   (*((volatile unsigned int*) GCOEFF_PMEMCTL_DBG_reg)=data)
#define get_GCOEFF_PMEMCTL_DBG_reg   (*((volatile unsigned int*) GCOEFF_PMEMCTL_DBG_reg))
#define GCOEFF_PMEMCTL_DBG_inst_adr                                                  "0x002D"
#define GCOEFF_PMEMCTL_DBG_inst                                                      0x002D
#define GCOEFF_PMEMCTL_DBG_Soft_rst_shift                                            (24)
#define GCOEFF_PMEMCTL_DBG_Soft_rst_mask                                             (0x01000000)
#define GCOEFF_PMEMCTL_DBG_Soft_rst(data)                                            (0x01000000&((data)<<24))
#define GCOEFF_PMEMCTL_DBG_Soft_rst_src(data)                                        ((0x01000000&(data))>>24)
#define GCOEFF_PMEMCTL_DBG_get_Soft_rst(data)                                        ((0x01000000&(data))>>24)
#define GCOEFF_PMEMCTL_DBG_Init_en_shift                                             (23)
#define GCOEFF_PMEMCTL_DBG_Init_en_mask                                              (0x00800000)
#define GCOEFF_PMEMCTL_DBG_Init_en(data)                                             (0x00800000&((data)<<23))
#define GCOEFF_PMEMCTL_DBG_Init_en_src(data)                                         ((0x00800000&(data))>>23)
#define GCOEFF_PMEMCTL_DBG_get_Init_en(data)                                         ((0x00800000&(data))>>23)
#define GCOEFF_PMEMCTL_DBG_Rng_Size_shift                                            (16)
#define GCOEFF_PMEMCTL_DBG_Rng_Size_mask                                             (0x007F0000)
#define GCOEFF_PMEMCTL_DBG_Rng_Size(data)                                            (0x007F0000&((data)<<16))
#define GCOEFF_PMEMCTL_DBG_Rng_Size_src(data)                                        ((0x007F0000&(data))>>16)
#define GCOEFF_PMEMCTL_DBG_get_Rng_Size(data)                                        ((0x007F0000&(data))>>16)
#define GCOEFF_PMEMCTL_DBG_Rdptr_shift                                               (8)
#define GCOEFF_PMEMCTL_DBG_Rdptr_mask                                                (0x0000FF00)
#define GCOEFF_PMEMCTL_DBG_Rdptr(data)                                               (0x0000FF00&((data)<<8))
#define GCOEFF_PMEMCTL_DBG_Rdptr_src(data)                                           ((0x0000FF00&(data))>>8)
#define GCOEFF_PMEMCTL_DBG_get_Rdptr(data)                                           ((0x0000FF00&(data))>>8)
#define GCOEFF_PMEMCTL_DBG_Wrptr_shift                                               (0)
#define GCOEFF_PMEMCTL_DBG_Wrptr_mask                                                (0x000000FF)
#define GCOEFF_PMEMCTL_DBG_Wrptr(data)                                               (0x000000FF&((data)<<0))
#define GCOEFF_PMEMCTL_DBG_Wrptr_src(data)                                           ((0x000000FF&(data))>>0)
#define GCOEFF_PMEMCTL_DBG_get_Wrptr(data)                                           ((0x000000FF&(data))>>0)


#define GCOEFF_QUANTIZER                                                             0x180368B8
#define GCOEFF_QUANTIZER_reg_addr                                                    "0xB80368B8"
#define GCOEFF_QUANTIZER_reg                                                         0xB80368B8
#define set_GCOEFF_QUANTIZER_reg(data)   (*((volatile unsigned int*) GCOEFF_QUANTIZER_reg)=data)
#define get_GCOEFF_QUANTIZER_reg   (*((volatile unsigned int*) GCOEFF_QUANTIZER_reg))
#define GCOEFF_QUANTIZER_inst_adr                                                    "0x002E"
#define GCOEFF_QUANTIZER_inst                                                        0x002E
#define GCOEFF_QUANTIZER_write_enable3_shift                                         (15)
#define GCOEFF_QUANTIZER_write_enable3_mask                                          (0x00008000)
#define GCOEFF_QUANTIZER_write_enable3(data)                                         (0x00008000&((data)<<15))
#define GCOEFF_QUANTIZER_write_enable3_src(data)                                     ((0x00008000&(data))>>15)
#define GCOEFF_QUANTIZER_get_write_enable3(data)                                     ((0x00008000&(data))>>15)
#define GCOEFF_QUANTIZER_flat_qtable_shift                                           (14)
#define GCOEFF_QUANTIZER_flat_qtable_mask                                            (0x00004000)
#define GCOEFF_QUANTIZER_flat_qtable(data)                                           (0x00004000&((data)<<14))
#define GCOEFF_QUANTIZER_flat_qtable_src(data)                                       ((0x00004000&(data))>>14)
#define GCOEFF_QUANTIZER_get_flat_qtable(data)                                       ((0x00004000&(data))>>14)
#define GCOEFF_QUANTIZER_write_enable2_shift                                         (13)
#define GCOEFF_QUANTIZER_write_enable2_mask                                          (0x00002000)
#define GCOEFF_QUANTIZER_write_enable2(data)                                         (0x00002000&((data)<<13))
#define GCOEFF_QUANTIZER_write_enable2_src(data)                                     ((0x00002000&(data))>>13)
#define GCOEFF_QUANTIZER_get_write_enable2(data)                                     ((0x00002000&(data))>>13)
#define GCOEFF_QUANTIZER_qpy_shift                                                   (7)
#define GCOEFF_QUANTIZER_qpy_mask                                                    (0x00001F80)
#define GCOEFF_QUANTIZER_qpy(data)                                                   (0x00001F80&((data)<<7))
#define GCOEFF_QUANTIZER_qpy_src(data)                                               ((0x00001F80&(data))>>7)
#define GCOEFF_QUANTIZER_get_qpy(data)                                               ((0x00001F80&(data))>>7)
#define GCOEFF_QUANTIZER_write_enable1_shift                                         (6)
#define GCOEFF_QUANTIZER_write_enable1_mask                                          (0x00000040)
#define GCOEFF_QUANTIZER_write_enable1(data)                                         (0x00000040&((data)<<6))
#define GCOEFF_QUANTIZER_write_enable1_src(data)                                     ((0x00000040&(data))>>6)
#define GCOEFF_QUANTIZER_get_write_enable1(data)                                     ((0x00000040&(data))>>6)
#define GCOEFF_QUANTIZER_qpc_shift                                                   (0)
#define GCOEFF_QUANTIZER_qpc_mask                                                    (0x0000003F)
#define GCOEFF_QUANTIZER_qpc(data)                                                   (0x0000003F&((data)<<0))
#define GCOEFF_QUANTIZER_qpc_src(data)                                               ((0x0000003F&(data))>>0)
#define GCOEFF_QUANTIZER_get_qpc(data)                                               ((0x0000003F&(data))>>0)


#define GCOEFF_MESTATUS                                                              0x180368BC
#define GCOEFF_MESTATUS_reg_addr                                                     "0xB80368BC"
#define GCOEFF_MESTATUS_reg                                                          0xB80368BC
#define set_GCOEFF_MESTATUS_reg(data)   (*((volatile unsigned int*) GCOEFF_MESTATUS_reg)=data)
#define get_GCOEFF_MESTATUS_reg   (*((volatile unsigned int*) GCOEFF_MESTATUS_reg))
#define GCOEFF_MESTATUS_inst_adr                                                     "0x002F"
#define GCOEFF_MESTATUS_inst                                                         0x002F
#define GCOEFF_MESTATUS_Mem_eng_busy_shift                                           (31)
#define GCOEFF_MESTATUS_Mem_eng_busy_mask                                            (0x80000000)
#define GCOEFF_MESTATUS_Mem_eng_busy(data)                                           (0x80000000&((data)<<31))
#define GCOEFF_MESTATUS_Mem_eng_busy_src(data)                                       ((0x80000000&(data))>>31)
#define GCOEFF_MESTATUS_get_Mem_eng_busy(data)                                       ((0x80000000&(data))>>31)


#define GCOEFF_LISTREF                                                               0x180368C0
#define GCOEFF_LISTREF_reg_addr                                                      "0xB80368C0"
#define GCOEFF_LISTREF_reg                                                           0xB80368C0
#define set_GCOEFF_LISTREF_reg(data)   (*((volatile unsigned int*) GCOEFF_LISTREF_reg)=data)
#define get_GCOEFF_LISTREF_reg   (*((volatile unsigned int*) GCOEFF_LISTREF_reg))
#define GCOEFF_LISTREF_inst_adr                                                      "0x0030"
#define GCOEFF_LISTREF_inst                                                          0x0030
#define GCOEFF_LISTREF_Inter_pred_mode_shift                                         (16)
#define GCOEFF_LISTREF_Inter_pred_mode_mask                                          (0x00FF0000)
#define GCOEFF_LISTREF_Inter_pred_mode(data)                                         (0x00FF0000&((data)<<16))
#define GCOEFF_LISTREF_Inter_pred_mode_src(data)                                     ((0x00FF0000&(data))>>16)
#define GCOEFF_LISTREF_get_Inter_pred_mode(data)                                     ((0x00FF0000&(data))>>16)
#define GCOEFF_LISTREF_List0RefIdx0_shift                                            (14)
#define GCOEFF_LISTREF_List0RefIdx0_mask                                             (0x0000C000)
#define GCOEFF_LISTREF_List0RefIdx0(data)                                            (0x0000C000&((data)<<14))
#define GCOEFF_LISTREF_List0RefIdx0_src(data)                                        ((0x0000C000&(data))>>14)
#define GCOEFF_LISTREF_get_List0RefIdx0(data)                                        ((0x0000C000&(data))>>14)
#define GCOEFF_LISTREF_List0RefIdx1_shift                                            (12)
#define GCOEFF_LISTREF_List0RefIdx1_mask                                             (0x00003000)
#define GCOEFF_LISTREF_List0RefIdx1(data)                                            (0x00003000&((data)<<12))
#define GCOEFF_LISTREF_List0RefIdx1_src(data)                                        ((0x00003000&(data))>>12)
#define GCOEFF_LISTREF_get_List0RefIdx1(data)                                        ((0x00003000&(data))>>12)
#define GCOEFF_LISTREF_List0RefIdx2_shift                                            (10)
#define GCOEFF_LISTREF_List0RefIdx2_mask                                             (0x00000C00)
#define GCOEFF_LISTREF_List0RefIdx2(data)                                            (0x00000C00&((data)<<10))
#define GCOEFF_LISTREF_List0RefIdx2_src(data)                                        ((0x00000C00&(data))>>10)
#define GCOEFF_LISTREF_get_List0RefIdx2(data)                                        ((0x00000C00&(data))>>10)
#define GCOEFF_LISTREF_List0RefIdx3_shift                                            (8)
#define GCOEFF_LISTREF_List0RefIdx3_mask                                             (0x00000300)
#define GCOEFF_LISTREF_List0RefIdx3(data)                                            (0x00000300&((data)<<8))
#define GCOEFF_LISTREF_List0RefIdx3_src(data)                                        ((0x00000300&(data))>>8)
#define GCOEFF_LISTREF_get_List0RefIdx3(data)                                        ((0x00000300&(data))>>8)
#define GCOEFF_LISTREF_List1RefIdx0_shift                                            (6)
#define GCOEFF_LISTREF_List1RefIdx0_mask                                             (0x000000C0)
#define GCOEFF_LISTREF_List1RefIdx0(data)                                            (0x000000C0&((data)<<6))
#define GCOEFF_LISTREF_List1RefIdx0_src(data)                                        ((0x000000C0&(data))>>6)
#define GCOEFF_LISTREF_get_List1RefIdx0(data)                                        ((0x000000C0&(data))>>6)
#define GCOEFF_LISTREF_List1RefIdx1_shift                                            (4)
#define GCOEFF_LISTREF_List1RefIdx1_mask                                             (0x00000030)
#define GCOEFF_LISTREF_List1RefIdx1(data)                                            (0x00000030&((data)<<4))
#define GCOEFF_LISTREF_List1RefIdx1_src(data)                                        ((0x00000030&(data))>>4)
#define GCOEFF_LISTREF_get_List1RefIdx1(data)                                        ((0x00000030&(data))>>4)
#define GCOEFF_LISTREF_List1RefIdx2_shift                                            (2)
#define GCOEFF_LISTREF_List1RefIdx2_mask                                             (0x0000000C)
#define GCOEFF_LISTREF_List1RefIdx2(data)                                            (0x0000000C&((data)<<2))
#define GCOEFF_LISTREF_List1RefIdx2_src(data)                                        ((0x0000000C&(data))>>2)
#define GCOEFF_LISTREF_get_List1RefIdx2(data)                                        ((0x0000000C&(data))>>2)
#define GCOEFF_LISTREF_List1RefIdx3_shift                                            (0)
#define GCOEFF_LISTREF_List1RefIdx3_mask                                             (0x00000003)
#define GCOEFF_LISTREF_List1RefIdx3(data)                                            (0x00000003&((data)<<0))
#define GCOEFF_LISTREF_List1RefIdx3_src(data)                                        ((0x00000003&(data))>>0)
#define GCOEFF_LISTREF_get_List1RefIdx3(data)                                        ((0x00000003&(data))>>0)


#define GCOEFF_MBINFO                                                                0x180368C4
#define GCOEFF_MBINFO_reg_addr                                                       "0xB80368C4"
#define GCOEFF_MBINFO_reg                                                            0xB80368C4
#define set_GCOEFF_MBINFO_reg(data)   (*((volatile unsigned int*) GCOEFF_MBINFO_reg)=data)
#define get_GCOEFF_MBINFO_reg   (*((volatile unsigned int*) GCOEFF_MBINFO_reg))
#define GCOEFF_MBINFO_inst_adr                                                       "0x0031"
#define GCOEFF_MBINFO_inst                                                           0x0031
#define GCOEFF_MBINFO_SliceStart_shift                                               (25)
#define GCOEFF_MBINFO_SliceStart_mask                                                (0x02000000)
#define GCOEFF_MBINFO_SliceStart(data)                                               (0x02000000&((data)<<25))
#define GCOEFF_MBINFO_SliceStart_src(data)                                           ((0x02000000&(data))>>25)
#define GCOEFF_MBINFO_get_SliceStart(data)                                           ((0x02000000&(data))>>25)
#define GCOEFF_MBINFO_CodingType_shift                                               (23)
#define GCOEFF_MBINFO_CodingType_mask                                                (0x01800000)
#define GCOEFF_MBINFO_CodingType(data)                                               (0x01800000&((data)<<23))
#define GCOEFF_MBINFO_CodingType_src(data)                                           ((0x01800000&(data))>>23)
#define GCOEFF_MBINFO_get_CodingType(data)                                           ((0x01800000&(data))>>23)
#define GCOEFF_MBINFO_PictureType_shift                                              (21)
#define GCOEFF_MBINFO_PictureType_mask                                               (0x00600000)
#define GCOEFF_MBINFO_PictureType(data)                                              (0x00600000&((data)<<21))
#define GCOEFF_MBINFO_PictureType_src(data)                                          ((0x00600000&(data))>>21)
#define GCOEFF_MBINFO_get_PictureType(data)                                          ((0x00600000&(data))>>21)
#define GCOEFF_MBINFO_MBType_shift                                                   (19)
#define GCOEFF_MBINFO_MBType_mask                                                    (0x00180000)
#define GCOEFF_MBINFO_MBType(data)                                                   (0x00180000&((data)<<19))
#define GCOEFF_MBINFO_MBType_src(data)                                               ((0x00180000&(data))>>19)
#define GCOEFF_MBINFO_get_MBType(data)                                               ((0x00180000&(data))>>19)
#define GCOEFF_MBINFO_MBpartition_shift                                              (16)
#define GCOEFF_MBINFO_MBpartition_mask                                               (0x00070000)
#define GCOEFF_MBINFO_MBpartition(data)                                              (0x00070000&((data)<<16))
#define GCOEFF_MBINFO_MBpartition_src(data)                                          ((0x00070000&(data))>>16)
#define GCOEFF_MBINFO_get_MBpartition(data)                                          ((0x00070000&(data))>>16)
#define GCOEFF_MBINFO_CurMBY_shift                                                   (8)
#define GCOEFF_MBINFO_CurMBY_mask                                                    (0x0000FF00)
#define GCOEFF_MBINFO_CurMBY(data)                                                   (0x0000FF00&((data)<<8))
#define GCOEFF_MBINFO_CurMBY_src(data)                                               ((0x0000FF00&(data))>>8)
#define GCOEFF_MBINFO_get_CurMBY(data)                                               ((0x0000FF00&(data))>>8)
#define GCOEFF_MBINFO_CurMBX_shift                                                   (0)
#define GCOEFF_MBINFO_CurMBX_mask                                                    (0x000000FF)
#define GCOEFF_MBINFO_CurMBX(data)                                                   (0x000000FF&((data)<<0))
#define GCOEFF_MBINFO_CurMBX_src(data)                                               ((0x000000FF&(data))>>0)
#define GCOEFF_MBINFO_get_CurMBX(data)                                               ((0x000000FF&(data))>>0)


#define GCOEFF_REMMODE_0                                                             0x180368C8
#define GCOEFF_REMMODE_1                                                             0x180368CC
#define GCOEFF_REMMODE_2                                                             0x180368D0
#define GCOEFF_REMMODE_0_reg_addr                                                    "0xB80368C8"
#define GCOEFF_REMMODE_1_reg_addr                                                    "0xB80368CC"
#define GCOEFF_REMMODE_2_reg_addr                                                    "0xB80368D0"
#define GCOEFF_REMMODE_0_reg                                                         0xB80368C8
#define GCOEFF_REMMODE_1_reg                                                         0xB80368CC
#define GCOEFF_REMMODE_2_reg                                                         0xB80368D0
#define set_GCOEFF_REMMODE_0_reg(data)   (*((volatile unsigned int*) GCOEFF_REMMODE_0_reg)=data)
#define set_GCOEFF_REMMODE_1_reg(data)   (*((volatile unsigned int*) GCOEFF_REMMODE_1_reg)=data)
#define set_GCOEFF_REMMODE_2_reg(data)   (*((volatile unsigned int*) GCOEFF_REMMODE_2_reg)=data)
#define get_GCOEFF_REMMODE_0_reg   (*((volatile unsigned int*) GCOEFF_REMMODE_0_reg))
#define get_GCOEFF_REMMODE_1_reg   (*((volatile unsigned int*) GCOEFF_REMMODE_1_reg))
#define get_GCOEFF_REMMODE_2_reg   (*((volatile unsigned int*) GCOEFF_REMMODE_2_reg))
#define GCOEFF_REMMODE_0_inst_adr                                                    "0x0032"
#define GCOEFF_REMMODE_1_inst_adr                                                    "0x0033"
#define GCOEFF_REMMODE_2_inst_adr                                                    "0x0034"
#define GCOEFF_REMMODE_0_inst                                                        0x0032
#define GCOEFF_REMMODE_1_inst                                                        0x0033
#define GCOEFF_REMMODE_2_inst                                                        0x0034
#define GCOEFF_REMMODE_Value_shift                                                   (0)
#define GCOEFF_REMMODE_Value_mask                                                    (0xFFFFFFFF)
#define GCOEFF_REMMODE_Value(data)                                                   (0xFFFFFFFF&((data)<<0))
#define GCOEFF_REMMODE_Value_src(data)                                               ((0xFFFFFFFF&(data))>>0)
#define GCOEFF_REMMODE_get_Value(data)                                               ((0xFFFFFFFF&(data))>>0)


#define GCOEFF_BITSTR_0                                                              0x180368D4
#define GCOEFF_BITSTR_1                                                              0x180368D8
#define GCOEFF_BITSTR_0_reg_addr                                                     "0xB80368D4"
#define GCOEFF_BITSTR_1_reg_addr                                                     "0xB80368D8"
#define GCOEFF_BITSTR_0_reg                                                          0xB80368D4
#define GCOEFF_BITSTR_1_reg                                                          0xB80368D8
#define set_GCOEFF_BITSTR_0_reg(data)   (*((volatile unsigned int*) GCOEFF_BITSTR_0_reg)=data)
#define set_GCOEFF_BITSTR_1_reg(data)   (*((volatile unsigned int*) GCOEFF_BITSTR_1_reg)=data)
#define get_GCOEFF_BITSTR_0_reg   (*((volatile unsigned int*) GCOEFF_BITSTR_0_reg))
#define get_GCOEFF_BITSTR_1_reg   (*((volatile unsigned int*) GCOEFF_BITSTR_1_reg))
#define GCOEFF_BITSTR_0_inst_adr                                                     "0x0035"
#define GCOEFF_BITSTR_1_inst_adr                                                     "0x0036"
#define GCOEFF_BITSTR_0_inst                                                         0x0035
#define GCOEFF_BITSTR_1_inst                                                         0x0036
#define GCOEFF_BITSTR_Value_shift                                                    (0)
#define GCOEFF_BITSTR_Value_mask                                                     (0xFFFFFFFF)
#define GCOEFF_BITSTR_Value(data)                                                    (0xFFFFFFFF&((data)<<0))
#define GCOEFF_BITSTR_Value_src(data)                                                ((0xFFFFFFFF&(data))>>0)
#define GCOEFF_BITSTR_get_Value(data)                                                ((0xFFFFFFFF&(data))>>0)


#define GCOEFF_DEBINFO                                                               0x180368DC
#define GCOEFF_DEBINFO_reg_addr                                                      "0xB80368DC"
#define GCOEFF_DEBINFO_reg                                                           0xB80368DC
#define set_GCOEFF_DEBINFO_reg(data)   (*((volatile unsigned int*) GCOEFF_DEBINFO_reg)=data)
#define get_GCOEFF_DEBINFO_reg   (*((volatile unsigned int*) GCOEFF_DEBINFO_reg))
#define GCOEFF_DEBINFO_inst_adr                                                      "0x0037"
#define GCOEFF_DEBINFO_inst                                                          0x0037
#define GCOEFF_DEBINFO_Mb_mode_shift                                                 (3)
#define GCOEFF_DEBINFO_Mb_mode_mask                                                  (0x00000038)
#define GCOEFF_DEBINFO_Mb_mode(data)                                                 (0x00000038&((data)<<3))
#define GCOEFF_DEBINFO_Mb_mode_src(data)                                             ((0x00000038&(data))>>3)
#define GCOEFF_DEBINFO_get_Mb_mode(data)                                             ((0x00000038&(data))>>3)
#define GCOEFF_DEBINFO_Eob_total_shift                                               (2)
#define GCOEFF_DEBINFO_Eob_total_mask                                                (0x00000004)
#define GCOEFF_DEBINFO_Eob_total(data)                                               (0x00000004&((data)<<2))
#define GCOEFF_DEBINFO_Eob_total_src(data)                                           ((0x00000004&(data))>>2)
#define GCOEFF_DEBINFO_get_Eob_total(data)                                           ((0x00000004&(data))>>2)
#define GCOEFF_DEBINFO_Transform_size_8x8_flag_shift                                 (1)
#define GCOEFF_DEBINFO_Transform_size_8x8_flag_mask                                  (0x00000002)
#define GCOEFF_DEBINFO_Transform_size_8x8_flag(data)                                 (0x00000002&((data)<<1))
#define GCOEFF_DEBINFO_Transform_size_8x8_flag_src(data)                             ((0x00000002&(data))>>1)
#define GCOEFF_DEBINFO_get_Transform_size_8x8_flag(data)                             ((0x00000002&(data))>>1)
#define GCOEFF_DEBINFO_Mb_field_decoding_flag_shift                                  (0)
#define GCOEFF_DEBINFO_Mb_field_decoding_flag_mask                                   (0x00000001)
#define GCOEFF_DEBINFO_Mb_field_decoding_flag(data)                                  (0x00000001&((data)<<0))
#define GCOEFF_DEBINFO_Mb_field_decoding_flag_src(data)                              ((0x00000001&(data))>>0)
#define GCOEFF_DEBINFO_get_Mb_field_decoding_flag(data)                              ((0x00000001&(data))>>0)


#define GCOEFF_SBCTRL                                                                0x18036900
#define GCOEFF_SBCTRL_reg_addr                                                       "0xB8036900"
#define GCOEFF_SBCTRL_reg                                                            0xB8036900
#define set_GCOEFF_SBCTRL_reg(data)   (*((volatile unsigned int*) GCOEFF_SBCTRL_reg)=data)
#define get_GCOEFF_SBCTRL_reg   (*((volatile unsigned int*) GCOEFF_SBCTRL_reg))
#define GCOEFF_SBCTRL_inst_adr                                                       "0x0040"
#define GCOEFF_SBCTRL_inst                                                           0x0040
#define GCOEFF_SBCTRL_write_enable4_shift                                            (10)
#define GCOEFF_SBCTRL_write_enable4_mask                                             (0x00000400)
#define GCOEFF_SBCTRL_write_enable4(data)                                            (0x00000400&((data)<<10))
#define GCOEFF_SBCTRL_write_enable4_src(data)                                        ((0x00000400&(data))>>10)
#define GCOEFF_SBCTRL_get_write_enable4(data)                                        ((0x00000400&(data))>>10)
#define GCOEFF_SBCTRL_DV_enable_shift                                                (9)
#define GCOEFF_SBCTRL_DV_enable_mask                                                 (0x00000200)
#define GCOEFF_SBCTRL_DV_enable(data)                                                (0x00000200&((data)<<9))
#define GCOEFF_SBCTRL_DV_enable_src(data)                                            ((0x00000200&(data))>>9)
#define GCOEFF_SBCTRL_get_DV_enable(data)                                            ((0x00000200&(data))>>9)
#define GCOEFF_SBCTRL_write_enable3_shift                                            (8)
#define GCOEFF_SBCTRL_write_enable3_mask                                             (0x00000100)
#define GCOEFF_SBCTRL_write_enable3(data)                                            (0x00000100&((data)<<8))
#define GCOEFF_SBCTRL_write_enable3_src(data)                                        ((0x00000100&(data))>>8)
#define GCOEFF_SBCTRL_get_write_enable3(data)                                        ((0x00000100&(data))>>8)
#define GCOEFF_SBCTRL_Size_shift                                                     (6)
#define GCOEFF_SBCTRL_Size_mask                                                      (0x000000C0)
#define GCOEFF_SBCTRL_Size(data)                                                     (0x000000C0&((data)<<6))
#define GCOEFF_SBCTRL_Size_src(data)                                                 ((0x000000C0&(data))>>6)
#define GCOEFF_SBCTRL_get_Size(data)                                                 ((0x000000C0&(data))>>6)
#define GCOEFF_SBCTRL_write_enable2_shift                                            (5)
#define GCOEFF_SBCTRL_write_enable2_mask                                             (0x00000020)
#define GCOEFF_SBCTRL_write_enable2(data)                                            (0x00000020&((data)<<5))
#define GCOEFF_SBCTRL_write_enable2_src(data)                                        ((0x00000020&(data))>>5)
#define GCOEFF_SBCTRL_get_write_enable2(data)                                        ((0x00000020&(data))>>5)
#define GCOEFF_SBCTRL_Rdptr_shift                                                    (3)
#define GCOEFF_SBCTRL_Rdptr_mask                                                     (0x00000018)
#define GCOEFF_SBCTRL_Rdptr(data)                                                    (0x00000018&((data)<<3))
#define GCOEFF_SBCTRL_Rdptr_src(data)                                                ((0x00000018&(data))>>3)
#define GCOEFF_SBCTRL_get_Rdptr(data)                                                ((0x00000018&(data))>>3)
#define GCOEFF_SBCTRL_write_enable1_shift                                            (2)
#define GCOEFF_SBCTRL_write_enable1_mask                                             (0x00000004)
#define GCOEFF_SBCTRL_write_enable1(data)                                            (0x00000004&((data)<<2))
#define GCOEFF_SBCTRL_write_enable1_src(data)                                        ((0x00000004&(data))>>2)
#define GCOEFF_SBCTRL_get_write_enable1(data)                                        ((0x00000004&(data))>>2)
#define GCOEFF_SBCTRL_Wrptr_shift                                                    (0)
#define GCOEFF_SBCTRL_Wrptr_mask                                                     (0x00000003)
#define GCOEFF_SBCTRL_Wrptr(data)                                                    (0x00000003&((data)<<0))
#define GCOEFF_SBCTRL_Wrptr_src(data)                                                ((0x00000003&(data))>>0)
#define GCOEFF_SBCTRL_get_Wrptr(data)                                                ((0x00000003&(data))>>0)


#endif
