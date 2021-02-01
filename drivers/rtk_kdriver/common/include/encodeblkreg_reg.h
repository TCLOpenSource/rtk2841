/**************************************************************
// Spec Version                  : unknown
// Parser Version                : DVR_Parser_6.11(120105)
// CModelGen Version             : 5.1 2012.01.05
// Naming Rule                   :  Module_Register_Name
// Naming Rule                   : Module_Register_Name_reg
// Parse Option                  : Only Parse _op1
// Parse Address Region          : All Address Region 
// Decode bit number             : 12 bits
// Firmware Header Generate Date : 2015/7/16 8:13:40
***************************************************************/


#ifndef _ENCODEBLKREG_REG_H_INCLUDED_
#define _ENCODEBLKREG_REG_H_INCLUDED_
#ifdef  _ENCODEBLKREG_USE_STRUCT
typedef struct 
{
unsigned int     reserved_0:25;
unsigned int     write_enable3:1;
unsigned int     vlc_bank:1;
unsigned int     write_enable2:1;
unsigned int     tq_bank:1;
unsigned int     write_enable1:1;
unsigned int     cm_mstr:2;
}ENCODEBLKREG_CM_CTRL;

typedef struct 
{
unsigned int     reserved_0:14;
unsigned int     write_enable2:1;
unsigned int     vlc_pred_counter:8;
unsigned int     write_enable1:1;
unsigned int     vlc_curmb_addr:8;
}ENCODEBLKREG_CURADR;

typedef struct 
{
unsigned int     reserved_0:13;
unsigned int     entropy_coding_mode:1;
unsigned int     pic_init_qp:6;
unsigned int     direct_8x8_inferflg:1;
unsigned int     transform_8x8_mode_flg:1;
unsigned int     num_ref_idx_l0_active_minus1:5;
unsigned int     num_ref_idx_l1_active_minus1:5;
}ENCODEBLKREG_H264_CNTL;

typedef struct 
{
unsigned int     reserved_0:17;
unsigned int     write_enable3:1;
unsigned int     pic_type:3;
unsigned int     write_enable2:1;
unsigned int     slice_qp_delta:7;
unsigned int     write_enable1:1;
unsigned int     cabac_init_idc:2;
}ENCODEBLKREG_H264_CNTL2;

typedef struct 
{
unsigned int     enc_bitcnt:32;
}ENCODEBLKREG_VLC_BITCNT;

typedef struct 
{
unsigned int     reserved_0:11;
unsigned int     write_enable4:1;
unsigned int     qp_delta:6;
unsigned int     write_enable3:1;
unsigned int     qpy:6;
unsigned int     write_enable2:1;
unsigned int     mbtype:4;
unsigned int     write_enable1:1;
unsigned int     transform_size_8x8:1;
}ENCODEBLKREG_VLC_MBTYPE;

typedef struct 
{
unsigned int     write_enable2:1;
unsigned int     cbp6bits:6;
unsigned int     write_enable1:1;
unsigned int     subblkpat:24;
}ENCODEBLKREG_VLC_CBP;

typedef struct 
{
unsigned int     reserved_0:23;
unsigned int     mbpartition:9;
}ENCODEBLKREG_MB_PARTITION;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     mb_pred_mode:8;
}ENCODEBLKREG_MB_PREDMODE;

typedef struct 
{
unsigned int     rem_mode:32;
}ENCODEBLKREG_INTRA_PRED;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     ref_idx_l0:2;
unsigned int     mvd_l0_y:10;
unsigned int     mvd_l0_x:12;
}ENCODEBLKREG_REF_L0;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     ref_idx_l1:2;
unsigned int     mvd_l1_y:10;
unsigned int     mvd_l1_x:12;
}ENCODEBLKREG_REF_L1;

typedef struct 
{
unsigned int     reserved_0:12;
unsigned int     left_luma_d:5;
unsigned int     left_luma_c:5;
unsigned int     left_luma_b:5;
unsigned int     left_luma_a:5;
}ENCODEBLKREG_TOTAL_COEF1;

typedef struct 
{
unsigned int     reserved_0:12;
unsigned int     left_cb_a:5;
unsigned int     left_cb_b:5;
unsigned int     left_cr_a:5;
unsigned int     left_cr_b:5;
}ENCODEBLKREG_TOTAL_COEF2;

typedef struct 
{
unsigned int     left_nb:32;
}ENCODEBLKREG_CABAC_LEFT;

#endif

#define ENCODEBLKREG_CM_CTRL                                                         0x18036400
#define ENCODEBLKREG_CM_CTRL_reg_addr                                                "0xB8036400"
#define ENCODEBLKREG_CM_CTRL_reg                                                     0xB8036400
#define set_ENCODEBLKREG_CM_CTRL_reg(data)   (*((volatile unsigned int*) ENCODEBLKREG_CM_CTRL_reg)=data)
#define get_ENCODEBLKREG_CM_CTRL_reg   (*((volatile unsigned int*) ENCODEBLKREG_CM_CTRL_reg))
#define ENCODEBLKREG_CM_CTRL_inst_adr                                                "0x0000"
#define ENCODEBLKREG_CM_CTRL_inst                                                    0x0000
#define ENCODEBLKREG_CM_CTRL_write_enable3_shift                                     (6)
#define ENCODEBLKREG_CM_CTRL_write_enable3_mask                                      (0x00000040)
#define ENCODEBLKREG_CM_CTRL_write_enable3(data)                                     (0x00000040&((data)<<6))
#define ENCODEBLKREG_CM_CTRL_write_enable3_src(data)                                 ((0x00000040&(data))>>6)
#define ENCODEBLKREG_CM_CTRL_get_write_enable3(data)                                 ((0x00000040&(data))>>6)
#define ENCODEBLKREG_CM_CTRL_vlc_bank_shift                                          (5)
#define ENCODEBLKREG_CM_CTRL_vlc_bank_mask                                           (0x00000020)
#define ENCODEBLKREG_CM_CTRL_vlc_bank(data)                                          (0x00000020&((data)<<5))
#define ENCODEBLKREG_CM_CTRL_vlc_bank_src(data)                                      ((0x00000020&(data))>>5)
#define ENCODEBLKREG_CM_CTRL_get_vlc_bank(data)                                      ((0x00000020&(data))>>5)
#define ENCODEBLKREG_CM_CTRL_write_enable2_shift                                     (4)
#define ENCODEBLKREG_CM_CTRL_write_enable2_mask                                      (0x00000010)
#define ENCODEBLKREG_CM_CTRL_write_enable2(data)                                     (0x00000010&((data)<<4))
#define ENCODEBLKREG_CM_CTRL_write_enable2_src(data)                                 ((0x00000010&(data))>>4)
#define ENCODEBLKREG_CM_CTRL_get_write_enable2(data)                                 ((0x00000010&(data))>>4)
#define ENCODEBLKREG_CM_CTRL_tq_bank_shift                                           (3)
#define ENCODEBLKREG_CM_CTRL_tq_bank_mask                                            (0x00000008)
#define ENCODEBLKREG_CM_CTRL_tq_bank(data)                                           (0x00000008&((data)<<3))
#define ENCODEBLKREG_CM_CTRL_tq_bank_src(data)                                       ((0x00000008&(data))>>3)
#define ENCODEBLKREG_CM_CTRL_get_tq_bank(data)                                       ((0x00000008&(data))>>3)
#define ENCODEBLKREG_CM_CTRL_write_enable1_shift                                     (2)
#define ENCODEBLKREG_CM_CTRL_write_enable1_mask                                      (0x00000004)
#define ENCODEBLKREG_CM_CTRL_write_enable1(data)                                     (0x00000004&((data)<<2))
#define ENCODEBLKREG_CM_CTRL_write_enable1_src(data)                                 ((0x00000004&(data))>>2)
#define ENCODEBLKREG_CM_CTRL_get_write_enable1(data)                                 ((0x00000004&(data))>>2)
#define ENCODEBLKREG_CM_CTRL_cm_mstr_shift                                           (0)
#define ENCODEBLKREG_CM_CTRL_cm_mstr_mask                                            (0x00000003)
#define ENCODEBLKREG_CM_CTRL_cm_mstr(data)                                           (0x00000003&((data)<<0))
#define ENCODEBLKREG_CM_CTRL_cm_mstr_src(data)                                       ((0x00000003&(data))>>0)
#define ENCODEBLKREG_CM_CTRL_get_cm_mstr(data)                                       ((0x00000003&(data))>>0)


#define ENCODEBLKREG_CURADR                                                          0x18036404
#define ENCODEBLKREG_CURADR_reg_addr                                                 "0xB8036404"
#define ENCODEBLKREG_CURADR_reg                                                      0xB8036404
#define set_ENCODEBLKREG_CURADR_reg(data)   (*((volatile unsigned int*) ENCODEBLKREG_CURADR_reg)=data)
#define get_ENCODEBLKREG_CURADR_reg   (*((volatile unsigned int*) ENCODEBLKREG_CURADR_reg))
#define ENCODEBLKREG_CURADR_inst_adr                                                 "0x0001"
#define ENCODEBLKREG_CURADR_inst                                                     0x0001
#define ENCODEBLKREG_CURADR_write_enable2_shift                                      (17)
#define ENCODEBLKREG_CURADR_write_enable2_mask                                       (0x00020000)
#define ENCODEBLKREG_CURADR_write_enable2(data)                                      (0x00020000&((data)<<17))
#define ENCODEBLKREG_CURADR_write_enable2_src(data)                                  ((0x00020000&(data))>>17)
#define ENCODEBLKREG_CURADR_get_write_enable2(data)                                  ((0x00020000&(data))>>17)
#define ENCODEBLKREG_CURADR_vlc_pred_counter_shift                                   (9)
#define ENCODEBLKREG_CURADR_vlc_pred_counter_mask                                    (0x0001FE00)
#define ENCODEBLKREG_CURADR_vlc_pred_counter(data)                                   (0x0001FE00&((data)<<9))
#define ENCODEBLKREG_CURADR_vlc_pred_counter_src(data)                               ((0x0001FE00&(data))>>9)
#define ENCODEBLKREG_CURADR_get_vlc_pred_counter(data)                               ((0x0001FE00&(data))>>9)
#define ENCODEBLKREG_CURADR_write_enable1_shift                                      (8)
#define ENCODEBLKREG_CURADR_write_enable1_mask                                       (0x00000100)
#define ENCODEBLKREG_CURADR_write_enable1(data)                                      (0x00000100&((data)<<8))
#define ENCODEBLKREG_CURADR_write_enable1_src(data)                                  ((0x00000100&(data))>>8)
#define ENCODEBLKREG_CURADR_get_write_enable1(data)                                  ((0x00000100&(data))>>8)
#define ENCODEBLKREG_CURADR_vlc_curmb_addr_shift                                     (0)
#define ENCODEBLKREG_CURADR_vlc_curmb_addr_mask                                      (0x000000FF)
#define ENCODEBLKREG_CURADR_vlc_curmb_addr(data)                                     (0x000000FF&((data)<<0))
#define ENCODEBLKREG_CURADR_vlc_curmb_addr_src(data)                                 ((0x000000FF&(data))>>0)
#define ENCODEBLKREG_CURADR_get_vlc_curmb_addr(data)                                 ((0x000000FF&(data))>>0)


#define ENCODEBLKREG_H264_CNTL                                                       0x18036408
#define ENCODEBLKREG_H264_CNTL_reg_addr                                              "0xB8036408"
#define ENCODEBLKREG_H264_CNTL_reg                                                   0xB8036408
#define set_ENCODEBLKREG_H264_CNTL_reg(data)   (*((volatile unsigned int*) ENCODEBLKREG_H264_CNTL_reg)=data)
#define get_ENCODEBLKREG_H264_CNTL_reg   (*((volatile unsigned int*) ENCODEBLKREG_H264_CNTL_reg))
#define ENCODEBLKREG_H264_CNTL_inst_adr                                              "0x0002"
#define ENCODEBLKREG_H264_CNTL_inst                                                  0x0002
#define ENCODEBLKREG_H264_CNTL_entropy_coding_mode_shift                             (18)
#define ENCODEBLKREG_H264_CNTL_entropy_coding_mode_mask                              (0x00040000)
#define ENCODEBLKREG_H264_CNTL_entropy_coding_mode(data)                             (0x00040000&((data)<<18))
#define ENCODEBLKREG_H264_CNTL_entropy_coding_mode_src(data)                         ((0x00040000&(data))>>18)
#define ENCODEBLKREG_H264_CNTL_get_entropy_coding_mode(data)                         ((0x00040000&(data))>>18)
#define ENCODEBLKREG_H264_CNTL_pic_init_qp_shift                                     (12)
#define ENCODEBLKREG_H264_CNTL_pic_init_qp_mask                                      (0x0003F000)
#define ENCODEBLKREG_H264_CNTL_pic_init_qp(data)                                     (0x0003F000&((data)<<12))
#define ENCODEBLKREG_H264_CNTL_pic_init_qp_src(data)                                 ((0x0003F000&(data))>>12)
#define ENCODEBLKREG_H264_CNTL_get_pic_init_qp(data)                                 ((0x0003F000&(data))>>12)
#define ENCODEBLKREG_H264_CNTL_direct_8x8_inferflg_shift                             (11)
#define ENCODEBLKREG_H264_CNTL_direct_8x8_inferflg_mask                              (0x00000800)
#define ENCODEBLKREG_H264_CNTL_direct_8x8_inferflg(data)                             (0x00000800&((data)<<11))
#define ENCODEBLKREG_H264_CNTL_direct_8x8_inferflg_src(data)                         ((0x00000800&(data))>>11)
#define ENCODEBLKREG_H264_CNTL_get_direct_8x8_inferflg(data)                         ((0x00000800&(data))>>11)
#define ENCODEBLKREG_H264_CNTL_transform_8x8_mode_flg_shift                          (10)
#define ENCODEBLKREG_H264_CNTL_transform_8x8_mode_flg_mask                           (0x00000400)
#define ENCODEBLKREG_H264_CNTL_transform_8x8_mode_flg(data)                          (0x00000400&((data)<<10))
#define ENCODEBLKREG_H264_CNTL_transform_8x8_mode_flg_src(data)                      ((0x00000400&(data))>>10)
#define ENCODEBLKREG_H264_CNTL_get_transform_8x8_mode_flg(data)                      ((0x00000400&(data))>>10)
#define ENCODEBLKREG_H264_CNTL_num_ref_idx_l0_active_minus1_shift                    (5)
#define ENCODEBLKREG_H264_CNTL_num_ref_idx_l0_active_minus1_mask                     (0x000003E0)
#define ENCODEBLKREG_H264_CNTL_num_ref_idx_l0_active_minus1(data)                    (0x000003E0&((data)<<5))
#define ENCODEBLKREG_H264_CNTL_num_ref_idx_l0_active_minus1_src(data)                ((0x000003E0&(data))>>5)
#define ENCODEBLKREG_H264_CNTL_get_num_ref_idx_l0_active_minus1(data)                ((0x000003E0&(data))>>5)
#define ENCODEBLKREG_H264_CNTL_num_ref_idx_l1_active_minus1_shift                    (0)
#define ENCODEBLKREG_H264_CNTL_num_ref_idx_l1_active_minus1_mask                     (0x0000001F)
#define ENCODEBLKREG_H264_CNTL_num_ref_idx_l1_active_minus1(data)                    (0x0000001F&((data)<<0))
#define ENCODEBLKREG_H264_CNTL_num_ref_idx_l1_active_minus1_src(data)                ((0x0000001F&(data))>>0)
#define ENCODEBLKREG_H264_CNTL_get_num_ref_idx_l1_active_minus1(data)                ((0x0000001F&(data))>>0)


#define ENCODEBLKREG_H264_CNTL2                                                      0x1803640C
#define ENCODEBLKREG_H264_CNTL2_reg_addr                                             "0xB803640C"
#define ENCODEBLKREG_H264_CNTL2_reg                                                  0xB803640C
#define set_ENCODEBLKREG_H264_CNTL2_reg(data)   (*((volatile unsigned int*) ENCODEBLKREG_H264_CNTL2_reg)=data)
#define get_ENCODEBLKREG_H264_CNTL2_reg   (*((volatile unsigned int*) ENCODEBLKREG_H264_CNTL2_reg))
#define ENCODEBLKREG_H264_CNTL2_inst_adr                                             "0x0003"
#define ENCODEBLKREG_H264_CNTL2_inst                                                 0x0003
#define ENCODEBLKREG_H264_CNTL2_write_enable3_shift                                  (14)
#define ENCODEBLKREG_H264_CNTL2_write_enable3_mask                                   (0x00004000)
#define ENCODEBLKREG_H264_CNTL2_write_enable3(data)                                  (0x00004000&((data)<<14))
#define ENCODEBLKREG_H264_CNTL2_write_enable3_src(data)                              ((0x00004000&(data))>>14)
#define ENCODEBLKREG_H264_CNTL2_get_write_enable3(data)                              ((0x00004000&(data))>>14)
#define ENCODEBLKREG_H264_CNTL2_pic_type_shift                                       (11)
#define ENCODEBLKREG_H264_CNTL2_pic_type_mask                                        (0x00003800)
#define ENCODEBLKREG_H264_CNTL2_pic_type(data)                                       (0x00003800&((data)<<11))
#define ENCODEBLKREG_H264_CNTL2_pic_type_src(data)                                   ((0x00003800&(data))>>11)
#define ENCODEBLKREG_H264_CNTL2_get_pic_type(data)                                   ((0x00003800&(data))>>11)
#define ENCODEBLKREG_H264_CNTL2_write_enable2_shift                                  (10)
#define ENCODEBLKREG_H264_CNTL2_write_enable2_mask                                   (0x00000400)
#define ENCODEBLKREG_H264_CNTL2_write_enable2(data)                                  (0x00000400&((data)<<10))
#define ENCODEBLKREG_H264_CNTL2_write_enable2_src(data)                              ((0x00000400&(data))>>10)
#define ENCODEBLKREG_H264_CNTL2_get_write_enable2(data)                              ((0x00000400&(data))>>10)
#define ENCODEBLKREG_H264_CNTL2_slice_qp_delta_shift                                 (3)
#define ENCODEBLKREG_H264_CNTL2_slice_qp_delta_mask                                  (0x000003F8)
#define ENCODEBLKREG_H264_CNTL2_slice_qp_delta(data)                                 (0x000003F8&((data)<<3))
#define ENCODEBLKREG_H264_CNTL2_slice_qp_delta_src(data)                             ((0x000003F8&(data))>>3)
#define ENCODEBLKREG_H264_CNTL2_get_slice_qp_delta(data)                             ((0x000003F8&(data))>>3)
#define ENCODEBLKREG_H264_CNTL2_write_enable1_shift                                  (2)
#define ENCODEBLKREG_H264_CNTL2_write_enable1_mask                                   (0x00000004)
#define ENCODEBLKREG_H264_CNTL2_write_enable1(data)                                  (0x00000004&((data)<<2))
#define ENCODEBLKREG_H264_CNTL2_write_enable1_src(data)                              ((0x00000004&(data))>>2)
#define ENCODEBLKREG_H264_CNTL2_get_write_enable1(data)                              ((0x00000004&(data))>>2)
#define ENCODEBLKREG_H264_CNTL2_cabac_init_idc_shift                                 (0)
#define ENCODEBLKREG_H264_CNTL2_cabac_init_idc_mask                                  (0x00000003)
#define ENCODEBLKREG_H264_CNTL2_cabac_init_idc(data)                                 (0x00000003&((data)<<0))
#define ENCODEBLKREG_H264_CNTL2_cabac_init_idc_src(data)                             ((0x00000003&(data))>>0)
#define ENCODEBLKREG_H264_CNTL2_get_cabac_init_idc(data)                             ((0x00000003&(data))>>0)


#define ENCODEBLKREG_VLC_BITCNT                                                      0x18036414
#define ENCODEBLKREG_VLC_BITCNT_reg_addr                                             "0xB8036414"
#define ENCODEBLKREG_VLC_BITCNT_reg                                                  0xB8036414
#define set_ENCODEBLKREG_VLC_BITCNT_reg(data)   (*((volatile unsigned int*) ENCODEBLKREG_VLC_BITCNT_reg)=data)
#define get_ENCODEBLKREG_VLC_BITCNT_reg   (*((volatile unsigned int*) ENCODEBLKREG_VLC_BITCNT_reg))
#define ENCODEBLKREG_VLC_BITCNT_inst_adr                                             "0x0005"
#define ENCODEBLKREG_VLC_BITCNT_inst                                                 0x0005
#define ENCODEBLKREG_VLC_BITCNT_enc_bitcnt_shift                                     (0)
#define ENCODEBLKREG_VLC_BITCNT_enc_bitcnt_mask                                      (0xFFFFFFFF)
#define ENCODEBLKREG_VLC_BITCNT_enc_bitcnt(data)                                     (0xFFFFFFFF&((data)<<0))
#define ENCODEBLKREG_VLC_BITCNT_enc_bitcnt_src(data)                                 ((0xFFFFFFFF&(data))>>0)
#define ENCODEBLKREG_VLC_BITCNT_get_enc_bitcnt(data)                                 ((0xFFFFFFFF&(data))>>0)


#define ENCODEBLKREG_VLC_MBTYPE                                                      0x18036430
#define ENCODEBLKREG_VLC_MBTYPE_reg_addr                                             "0xB8036430"
#define ENCODEBLKREG_VLC_MBTYPE_reg                                                  0xB8036430
#define set_ENCODEBLKREG_VLC_MBTYPE_reg(data)   (*((volatile unsigned int*) ENCODEBLKREG_VLC_MBTYPE_reg)=data)
#define get_ENCODEBLKREG_VLC_MBTYPE_reg   (*((volatile unsigned int*) ENCODEBLKREG_VLC_MBTYPE_reg))
#define ENCODEBLKREG_VLC_MBTYPE_inst_adr                                             "0x000C"
#define ENCODEBLKREG_VLC_MBTYPE_inst                                                 0x000C
#define ENCODEBLKREG_VLC_MBTYPE_write_enable4_shift                                  (20)
#define ENCODEBLKREG_VLC_MBTYPE_write_enable4_mask                                   (0x00100000)
#define ENCODEBLKREG_VLC_MBTYPE_write_enable4(data)                                  (0x00100000&((data)<<20))
#define ENCODEBLKREG_VLC_MBTYPE_write_enable4_src(data)                              ((0x00100000&(data))>>20)
#define ENCODEBLKREG_VLC_MBTYPE_get_write_enable4(data)                              ((0x00100000&(data))>>20)
#define ENCODEBLKREG_VLC_MBTYPE_qp_delta_shift                                       (14)
#define ENCODEBLKREG_VLC_MBTYPE_qp_delta_mask                                        (0x000FC000)
#define ENCODEBLKREG_VLC_MBTYPE_qp_delta(data)                                       (0x000FC000&((data)<<14))
#define ENCODEBLKREG_VLC_MBTYPE_qp_delta_src(data)                                   ((0x000FC000&(data))>>14)
#define ENCODEBLKREG_VLC_MBTYPE_get_qp_delta(data)                                   ((0x000FC000&(data))>>14)
#define ENCODEBLKREG_VLC_MBTYPE_write_enable3_shift                                  (13)
#define ENCODEBLKREG_VLC_MBTYPE_write_enable3_mask                                   (0x00002000)
#define ENCODEBLKREG_VLC_MBTYPE_write_enable3(data)                                  (0x00002000&((data)<<13))
#define ENCODEBLKREG_VLC_MBTYPE_write_enable3_src(data)                              ((0x00002000&(data))>>13)
#define ENCODEBLKREG_VLC_MBTYPE_get_write_enable3(data)                              ((0x00002000&(data))>>13)
#define ENCODEBLKREG_VLC_MBTYPE_qpy_shift                                            (7)
#define ENCODEBLKREG_VLC_MBTYPE_qpy_mask                                             (0x00001F80)
#define ENCODEBLKREG_VLC_MBTYPE_qpy(data)                                            (0x00001F80&((data)<<7))
#define ENCODEBLKREG_VLC_MBTYPE_qpy_src(data)                                        ((0x00001F80&(data))>>7)
#define ENCODEBLKREG_VLC_MBTYPE_get_qpy(data)                                        ((0x00001F80&(data))>>7)
#define ENCODEBLKREG_VLC_MBTYPE_write_enable2_shift                                  (6)
#define ENCODEBLKREG_VLC_MBTYPE_write_enable2_mask                                   (0x00000040)
#define ENCODEBLKREG_VLC_MBTYPE_write_enable2(data)                                  (0x00000040&((data)<<6))
#define ENCODEBLKREG_VLC_MBTYPE_write_enable2_src(data)                              ((0x00000040&(data))>>6)
#define ENCODEBLKREG_VLC_MBTYPE_get_write_enable2(data)                              ((0x00000040&(data))>>6)
#define ENCODEBLKREG_VLC_MBTYPE_mbtype_shift                                         (2)
#define ENCODEBLKREG_VLC_MBTYPE_mbtype_mask                                          (0x0000003C)
#define ENCODEBLKREG_VLC_MBTYPE_mbtype(data)                                         (0x0000003C&((data)<<2))
#define ENCODEBLKREG_VLC_MBTYPE_mbtype_src(data)                                     ((0x0000003C&(data))>>2)
#define ENCODEBLKREG_VLC_MBTYPE_get_mbtype(data)                                     ((0x0000003C&(data))>>2)
#define ENCODEBLKREG_VLC_MBTYPE_write_enable1_shift                                  (1)
#define ENCODEBLKREG_VLC_MBTYPE_write_enable1_mask                                   (0x00000002)
#define ENCODEBLKREG_VLC_MBTYPE_write_enable1(data)                                  (0x00000002&((data)<<1))
#define ENCODEBLKREG_VLC_MBTYPE_write_enable1_src(data)                              ((0x00000002&(data))>>1)
#define ENCODEBLKREG_VLC_MBTYPE_get_write_enable1(data)                              ((0x00000002&(data))>>1)
#define ENCODEBLKREG_VLC_MBTYPE_transform_size_8x8_shift                             (0)
#define ENCODEBLKREG_VLC_MBTYPE_transform_size_8x8_mask                              (0x00000001)
#define ENCODEBLKREG_VLC_MBTYPE_transform_size_8x8(data)                             (0x00000001&((data)<<0))
#define ENCODEBLKREG_VLC_MBTYPE_transform_size_8x8_src(data)                         ((0x00000001&(data))>>0)
#define ENCODEBLKREG_VLC_MBTYPE_get_transform_size_8x8(data)                         ((0x00000001&(data))>>0)


#define ENCODEBLKREG_VLC_CBP                                                         0x18036434
#define ENCODEBLKREG_VLC_CBP_reg_addr                                                "0xB8036434"
#define ENCODEBLKREG_VLC_CBP_reg                                                     0xB8036434
#define set_ENCODEBLKREG_VLC_CBP_reg(data)   (*((volatile unsigned int*) ENCODEBLKREG_VLC_CBP_reg)=data)
#define get_ENCODEBLKREG_VLC_CBP_reg   (*((volatile unsigned int*) ENCODEBLKREG_VLC_CBP_reg))
#define ENCODEBLKREG_VLC_CBP_inst_adr                                                "0x000D"
#define ENCODEBLKREG_VLC_CBP_inst                                                    0x000D
#define ENCODEBLKREG_VLC_CBP_write_enable2_shift                                     (31)
#define ENCODEBLKREG_VLC_CBP_write_enable2_mask                                      (0x80000000)
#define ENCODEBLKREG_VLC_CBP_write_enable2(data)                                     (0x80000000&((data)<<31))
#define ENCODEBLKREG_VLC_CBP_write_enable2_src(data)                                 ((0x80000000&(data))>>31)
#define ENCODEBLKREG_VLC_CBP_get_write_enable2(data)                                 ((0x80000000&(data))>>31)
#define ENCODEBLKREG_VLC_CBP_cbp6bits_shift                                          (25)
#define ENCODEBLKREG_VLC_CBP_cbp6bits_mask                                           (0x7E000000)
#define ENCODEBLKREG_VLC_CBP_cbp6bits(data)                                          (0x7E000000&((data)<<25))
#define ENCODEBLKREG_VLC_CBP_cbp6bits_src(data)                                      ((0x7E000000&(data))>>25)
#define ENCODEBLKREG_VLC_CBP_get_cbp6bits(data)                                      ((0x7E000000&(data))>>25)
#define ENCODEBLKREG_VLC_CBP_write_enable1_shift                                     (24)
#define ENCODEBLKREG_VLC_CBP_write_enable1_mask                                      (0x01000000)
#define ENCODEBLKREG_VLC_CBP_write_enable1(data)                                     (0x01000000&((data)<<24))
#define ENCODEBLKREG_VLC_CBP_write_enable1_src(data)                                 ((0x01000000&(data))>>24)
#define ENCODEBLKREG_VLC_CBP_get_write_enable1(data)                                 ((0x01000000&(data))>>24)
#define ENCODEBLKREG_VLC_CBP_subblkpat_shift                                         (0)
#define ENCODEBLKREG_VLC_CBP_subblkpat_mask                                          (0x00FFFFFF)
#define ENCODEBLKREG_VLC_CBP_subblkpat(data)                                         (0x00FFFFFF&((data)<<0))
#define ENCODEBLKREG_VLC_CBP_subblkpat_src(data)                                     ((0x00FFFFFF&(data))>>0)
#define ENCODEBLKREG_VLC_CBP_get_subblkpat(data)                                     ((0x00FFFFFF&(data))>>0)


#define ENCODEBLKREG_MB_PARTITION                                                    0x18036438
#define ENCODEBLKREG_MB_PARTITION_reg_addr                                           "0xB8036438"
#define ENCODEBLKREG_MB_PARTITION_reg                                                0xB8036438
#define set_ENCODEBLKREG_MB_PARTITION_reg(data)   (*((volatile unsigned int*) ENCODEBLKREG_MB_PARTITION_reg)=data)
#define get_ENCODEBLKREG_MB_PARTITION_reg   (*((volatile unsigned int*) ENCODEBLKREG_MB_PARTITION_reg))
#define ENCODEBLKREG_MB_PARTITION_inst_adr                                           "0x000E"
#define ENCODEBLKREG_MB_PARTITION_inst                                               0x000E
#define ENCODEBLKREG_MB_PARTITION_mbpartition_shift                                  (0)
#define ENCODEBLKREG_MB_PARTITION_mbpartition_mask                                   (0x000001FF)
#define ENCODEBLKREG_MB_PARTITION_mbpartition(data)                                  (0x000001FF&((data)<<0))
#define ENCODEBLKREG_MB_PARTITION_mbpartition_src(data)                              ((0x000001FF&(data))>>0)
#define ENCODEBLKREG_MB_PARTITION_get_mbpartition(data)                              ((0x000001FF&(data))>>0)


#define ENCODEBLKREG_MB_PREDMODE                                                     0x1803643C
#define ENCODEBLKREG_MB_PREDMODE_reg_addr                                            "0xB803643C"
#define ENCODEBLKREG_MB_PREDMODE_reg                                                 0xB803643C
#define set_ENCODEBLKREG_MB_PREDMODE_reg(data)   (*((volatile unsigned int*) ENCODEBLKREG_MB_PREDMODE_reg)=data)
#define get_ENCODEBLKREG_MB_PREDMODE_reg   (*((volatile unsigned int*) ENCODEBLKREG_MB_PREDMODE_reg))
#define ENCODEBLKREG_MB_PREDMODE_inst_adr                                            "0x000F"
#define ENCODEBLKREG_MB_PREDMODE_inst                                                0x000F
#define ENCODEBLKREG_MB_PREDMODE_mb_pred_mode_shift                                  (0)
#define ENCODEBLKREG_MB_PREDMODE_mb_pred_mode_mask                                   (0x000000FF)
#define ENCODEBLKREG_MB_PREDMODE_mb_pred_mode(data)                                  (0x000000FF&((data)<<0))
#define ENCODEBLKREG_MB_PREDMODE_mb_pred_mode_src(data)                              ((0x000000FF&(data))>>0)
#define ENCODEBLKREG_MB_PREDMODE_get_mb_pred_mode(data)                              ((0x000000FF&(data))>>0)


#define ENCODEBLKREG_INTRA_PRED_0                                                    0x18036440
#define ENCODEBLKREG_INTRA_PRED_1                                                    0x18036444
#define ENCODEBLKREG_INTRA_PRED_2                                                    0x18036448
#define ENCODEBLKREG_INTRA_PRED_0_reg_addr                                           "0xB8036440"
#define ENCODEBLKREG_INTRA_PRED_1_reg_addr                                           "0xB8036444"
#define ENCODEBLKREG_INTRA_PRED_2_reg_addr                                           "0xB8036448"
#define ENCODEBLKREG_INTRA_PRED_0_reg                                                0xB8036440
#define ENCODEBLKREG_INTRA_PRED_1_reg                                                0xB8036444
#define ENCODEBLKREG_INTRA_PRED_2_reg                                                0xB8036448
#define set_ENCODEBLKREG_INTRA_PRED_0_reg(data)   (*((volatile unsigned int*) ENCODEBLKREG_INTRA_PRED_0_reg)=data)
#define set_ENCODEBLKREG_INTRA_PRED_1_reg(data)   (*((volatile unsigned int*) ENCODEBLKREG_INTRA_PRED_1_reg)=data)
#define set_ENCODEBLKREG_INTRA_PRED_2_reg(data)   (*((volatile unsigned int*) ENCODEBLKREG_INTRA_PRED_2_reg)=data)
#define get_ENCODEBLKREG_INTRA_PRED_0_reg   (*((volatile unsigned int*) ENCODEBLKREG_INTRA_PRED_0_reg))
#define get_ENCODEBLKREG_INTRA_PRED_1_reg   (*((volatile unsigned int*) ENCODEBLKREG_INTRA_PRED_1_reg))
#define get_ENCODEBLKREG_INTRA_PRED_2_reg   (*((volatile unsigned int*) ENCODEBLKREG_INTRA_PRED_2_reg))
#define ENCODEBLKREG_INTRA_PRED_0_inst_adr                                           "0x0010"
#define ENCODEBLKREG_INTRA_PRED_1_inst_adr                                           "0x0011"
#define ENCODEBLKREG_INTRA_PRED_2_inst_adr                                           "0x0012"
#define ENCODEBLKREG_INTRA_PRED_0_inst                                               0x0010
#define ENCODEBLKREG_INTRA_PRED_1_inst                                               0x0011
#define ENCODEBLKREG_INTRA_PRED_2_inst                                               0x0012
#define ENCODEBLKREG_INTRA_PRED_rem_mode_shift                                       (0)
#define ENCODEBLKREG_INTRA_PRED_rem_mode_mask                                        (0xFFFFFFFF)
#define ENCODEBLKREG_INTRA_PRED_rem_mode(data)                                       (0xFFFFFFFF&((data)<<0))
#define ENCODEBLKREG_INTRA_PRED_rem_mode_src(data)                                   ((0xFFFFFFFF&(data))>>0)
#define ENCODEBLKREG_INTRA_PRED_get_rem_mode(data)                                   ((0xFFFFFFFF&(data))>>0)


#define ENCODEBLKREG_REF_L0_0                                                        0x18036450
#define ENCODEBLKREG_REF_L0_1                                                        0x18036454
#define ENCODEBLKREG_REF_L0_2                                                        0x18036458
#define ENCODEBLKREG_REF_L0_3                                                        0x1803645C
#define ENCODEBLKREG_REF_L0_0_reg_addr                                               "0xB8036450"
#define ENCODEBLKREG_REF_L0_1_reg_addr                                               "0xB8036454"
#define ENCODEBLKREG_REF_L0_2_reg_addr                                               "0xB8036458"
#define ENCODEBLKREG_REF_L0_3_reg_addr                                               "0xB803645C"
#define ENCODEBLKREG_REF_L0_0_reg                                                    0xB8036450
#define ENCODEBLKREG_REF_L0_1_reg                                                    0xB8036454
#define ENCODEBLKREG_REF_L0_2_reg                                                    0xB8036458
#define ENCODEBLKREG_REF_L0_3_reg                                                    0xB803645C
#define set_ENCODEBLKREG_REF_L0_0_reg(data)   (*((volatile unsigned int*) ENCODEBLKREG_REF_L0_0_reg)=data)
#define set_ENCODEBLKREG_REF_L0_1_reg(data)   (*((volatile unsigned int*) ENCODEBLKREG_REF_L0_1_reg)=data)
#define set_ENCODEBLKREG_REF_L0_2_reg(data)   (*((volatile unsigned int*) ENCODEBLKREG_REF_L0_2_reg)=data)
#define set_ENCODEBLKREG_REF_L0_3_reg(data)   (*((volatile unsigned int*) ENCODEBLKREG_REF_L0_3_reg)=data)
#define get_ENCODEBLKREG_REF_L0_0_reg   (*((volatile unsigned int*) ENCODEBLKREG_REF_L0_0_reg))
#define get_ENCODEBLKREG_REF_L0_1_reg   (*((volatile unsigned int*) ENCODEBLKREG_REF_L0_1_reg))
#define get_ENCODEBLKREG_REF_L0_2_reg   (*((volatile unsigned int*) ENCODEBLKREG_REF_L0_2_reg))
#define get_ENCODEBLKREG_REF_L0_3_reg   (*((volatile unsigned int*) ENCODEBLKREG_REF_L0_3_reg))
#define ENCODEBLKREG_REF_L0_0_inst_adr                                               "0x0014"
#define ENCODEBLKREG_REF_L0_1_inst_adr                                               "0x0015"
#define ENCODEBLKREG_REF_L0_2_inst_adr                                               "0x0016"
#define ENCODEBLKREG_REF_L0_3_inst_adr                                               "0x0017"
#define ENCODEBLKREG_REF_L0_0_inst                                                   0x0014
#define ENCODEBLKREG_REF_L0_1_inst                                                   0x0015
#define ENCODEBLKREG_REF_L0_2_inst                                                   0x0016
#define ENCODEBLKREG_REF_L0_3_inst                                                   0x0017
#define ENCODEBLKREG_REF_L0_ref_idx_l0_shift                                         (22)
#define ENCODEBLKREG_REF_L0_ref_idx_l0_mask                                          (0x00C00000)
#define ENCODEBLKREG_REF_L0_ref_idx_l0(data)                                         (0x00C00000&((data)<<22))
#define ENCODEBLKREG_REF_L0_ref_idx_l0_src(data)                                     ((0x00C00000&(data))>>22)
#define ENCODEBLKREG_REF_L0_get_ref_idx_l0(data)                                     ((0x00C00000&(data))>>22)
#define ENCODEBLKREG_REF_L0_mvd_l0_y_shift                                           (12)
#define ENCODEBLKREG_REF_L0_mvd_l0_y_mask                                            (0x003FF000)
#define ENCODEBLKREG_REF_L0_mvd_l0_y(data)                                           (0x003FF000&((data)<<12))
#define ENCODEBLKREG_REF_L0_mvd_l0_y_src(data)                                       ((0x003FF000&(data))>>12)
#define ENCODEBLKREG_REF_L0_get_mvd_l0_y(data)                                       ((0x003FF000&(data))>>12)
#define ENCODEBLKREG_REF_L0_mvd_l0_x_shift                                           (0)
#define ENCODEBLKREG_REF_L0_mvd_l0_x_mask                                            (0x00000FFF)
#define ENCODEBLKREG_REF_L0_mvd_l0_x(data)                                           (0x00000FFF&((data)<<0))
#define ENCODEBLKREG_REF_L0_mvd_l0_x_src(data)                                       ((0x00000FFF&(data))>>0)
#define ENCODEBLKREG_REF_L0_get_mvd_l0_x(data)                                       ((0x00000FFF&(data))>>0)


#define ENCODEBLKREG_REF_L1_0                                                        0x18036460
#define ENCODEBLKREG_REF_L1_1                                                        0x18036464
#define ENCODEBLKREG_REF_L1_2                                                        0x18036468
#define ENCODEBLKREG_REF_L1_3                                                        0x1803646C
#define ENCODEBLKREG_REF_L1_0_reg_addr                                               "0xB8036460"
#define ENCODEBLKREG_REF_L1_1_reg_addr                                               "0xB8036464"
#define ENCODEBLKREG_REF_L1_2_reg_addr                                               "0xB8036468"
#define ENCODEBLKREG_REF_L1_3_reg_addr                                               "0xB803646C"
#define ENCODEBLKREG_REF_L1_0_reg                                                    0xB8036460
#define ENCODEBLKREG_REF_L1_1_reg                                                    0xB8036464
#define ENCODEBLKREG_REF_L1_2_reg                                                    0xB8036468
#define ENCODEBLKREG_REF_L1_3_reg                                                    0xB803646C
#define set_ENCODEBLKREG_REF_L1_0_reg(data)   (*((volatile unsigned int*) ENCODEBLKREG_REF_L1_0_reg)=data)
#define set_ENCODEBLKREG_REF_L1_1_reg(data)   (*((volatile unsigned int*) ENCODEBLKREG_REF_L1_1_reg)=data)
#define set_ENCODEBLKREG_REF_L1_2_reg(data)   (*((volatile unsigned int*) ENCODEBLKREG_REF_L1_2_reg)=data)
#define set_ENCODEBLKREG_REF_L1_3_reg(data)   (*((volatile unsigned int*) ENCODEBLKREG_REF_L1_3_reg)=data)
#define get_ENCODEBLKREG_REF_L1_0_reg   (*((volatile unsigned int*) ENCODEBLKREG_REF_L1_0_reg))
#define get_ENCODEBLKREG_REF_L1_1_reg   (*((volatile unsigned int*) ENCODEBLKREG_REF_L1_1_reg))
#define get_ENCODEBLKREG_REF_L1_2_reg   (*((volatile unsigned int*) ENCODEBLKREG_REF_L1_2_reg))
#define get_ENCODEBLKREG_REF_L1_3_reg   (*((volatile unsigned int*) ENCODEBLKREG_REF_L1_3_reg))
#define ENCODEBLKREG_REF_L1_0_inst_adr                                               "0x0018"
#define ENCODEBLKREG_REF_L1_1_inst_adr                                               "0x0019"
#define ENCODEBLKREG_REF_L1_2_inst_adr                                               "0x001A"
#define ENCODEBLKREG_REF_L1_3_inst_adr                                               "0x001B"
#define ENCODEBLKREG_REF_L1_0_inst                                                   0x0018
#define ENCODEBLKREG_REF_L1_1_inst                                                   0x0019
#define ENCODEBLKREG_REF_L1_2_inst                                                   0x001A
#define ENCODEBLKREG_REF_L1_3_inst                                                   0x001B
#define ENCODEBLKREG_REF_L1_ref_idx_l1_shift                                         (22)
#define ENCODEBLKREG_REF_L1_ref_idx_l1_mask                                          (0x00C00000)
#define ENCODEBLKREG_REF_L1_ref_idx_l1(data)                                         (0x00C00000&((data)<<22))
#define ENCODEBLKREG_REF_L1_ref_idx_l1_src(data)                                     ((0x00C00000&(data))>>22)
#define ENCODEBLKREG_REF_L1_get_ref_idx_l1(data)                                     ((0x00C00000&(data))>>22)
#define ENCODEBLKREG_REF_L1_mvd_l1_y_shift                                           (12)
#define ENCODEBLKREG_REF_L1_mvd_l1_y_mask                                            (0x003FF000)
#define ENCODEBLKREG_REF_L1_mvd_l1_y(data)                                           (0x003FF000&((data)<<12))
#define ENCODEBLKREG_REF_L1_mvd_l1_y_src(data)                                       ((0x003FF000&(data))>>12)
#define ENCODEBLKREG_REF_L1_get_mvd_l1_y(data)                                       ((0x003FF000&(data))>>12)
#define ENCODEBLKREG_REF_L1_mvd_l1_x_shift                                           (0)
#define ENCODEBLKREG_REF_L1_mvd_l1_x_mask                                            (0x00000FFF)
#define ENCODEBLKREG_REF_L1_mvd_l1_x(data)                                           (0x00000FFF&((data)<<0))
#define ENCODEBLKREG_REF_L1_mvd_l1_x_src(data)                                       ((0x00000FFF&(data))>>0)
#define ENCODEBLKREG_REF_L1_get_mvd_l1_x(data)                                       ((0x00000FFF&(data))>>0)


#define ENCODEBLKREG_TOTAL_COEF1                                                     0x18036470
#define ENCODEBLKREG_TOTAL_COEF1_reg_addr                                            "0xB8036470"
#define ENCODEBLKREG_TOTAL_COEF1_reg                                                 0xB8036470
#define set_ENCODEBLKREG_TOTAL_COEF1_reg(data)   (*((volatile unsigned int*) ENCODEBLKREG_TOTAL_COEF1_reg)=data)
#define get_ENCODEBLKREG_TOTAL_COEF1_reg   (*((volatile unsigned int*) ENCODEBLKREG_TOTAL_COEF1_reg))
#define ENCODEBLKREG_TOTAL_COEF1_inst_adr                                            "0x001C"
#define ENCODEBLKREG_TOTAL_COEF1_inst                                                0x001C
#define ENCODEBLKREG_TOTAL_COEF1_left_luma_d_shift                                   (15)
#define ENCODEBLKREG_TOTAL_COEF1_left_luma_d_mask                                    (0x000F8000)
#define ENCODEBLKREG_TOTAL_COEF1_left_luma_d(data)                                   (0x000F8000&((data)<<15))
#define ENCODEBLKREG_TOTAL_COEF1_left_luma_d_src(data)                               ((0x000F8000&(data))>>15)
#define ENCODEBLKREG_TOTAL_COEF1_get_left_luma_d(data)                               ((0x000F8000&(data))>>15)
#define ENCODEBLKREG_TOTAL_COEF1_left_luma_c_shift                                   (10)
#define ENCODEBLKREG_TOTAL_COEF1_left_luma_c_mask                                    (0x00007C00)
#define ENCODEBLKREG_TOTAL_COEF1_left_luma_c(data)                                   (0x00007C00&((data)<<10))
#define ENCODEBLKREG_TOTAL_COEF1_left_luma_c_src(data)                               ((0x00007C00&(data))>>10)
#define ENCODEBLKREG_TOTAL_COEF1_get_left_luma_c(data)                               ((0x00007C00&(data))>>10)
#define ENCODEBLKREG_TOTAL_COEF1_left_luma_b_shift                                   (5)
#define ENCODEBLKREG_TOTAL_COEF1_left_luma_b_mask                                    (0x000003E0)
#define ENCODEBLKREG_TOTAL_COEF1_left_luma_b(data)                                   (0x000003E0&((data)<<5))
#define ENCODEBLKREG_TOTAL_COEF1_left_luma_b_src(data)                               ((0x000003E0&(data))>>5)
#define ENCODEBLKREG_TOTAL_COEF1_get_left_luma_b(data)                               ((0x000003E0&(data))>>5)
#define ENCODEBLKREG_TOTAL_COEF1_left_luma_a_shift                                   (0)
#define ENCODEBLKREG_TOTAL_COEF1_left_luma_a_mask                                    (0x0000001F)
#define ENCODEBLKREG_TOTAL_COEF1_left_luma_a(data)                                   (0x0000001F&((data)<<0))
#define ENCODEBLKREG_TOTAL_COEF1_left_luma_a_src(data)                               ((0x0000001F&(data))>>0)
#define ENCODEBLKREG_TOTAL_COEF1_get_left_luma_a(data)                               ((0x0000001F&(data))>>0)


#define ENCODEBLKREG_TOTAL_COEF2                                                     0x18036474
#define ENCODEBLKREG_TOTAL_COEF2_reg_addr                                            "0xB8036474"
#define ENCODEBLKREG_TOTAL_COEF2_reg                                                 0xB8036474
#define set_ENCODEBLKREG_TOTAL_COEF2_reg(data)   (*((volatile unsigned int*) ENCODEBLKREG_TOTAL_COEF2_reg)=data)
#define get_ENCODEBLKREG_TOTAL_COEF2_reg   (*((volatile unsigned int*) ENCODEBLKREG_TOTAL_COEF2_reg))
#define ENCODEBLKREG_TOTAL_COEF2_inst_adr                                            "0x001D"
#define ENCODEBLKREG_TOTAL_COEF2_inst                                                0x001D
#define ENCODEBLKREG_TOTAL_COEF2_left_cb_a_shift                                     (15)
#define ENCODEBLKREG_TOTAL_COEF2_left_cb_a_mask                                      (0x000F8000)
#define ENCODEBLKREG_TOTAL_COEF2_left_cb_a(data)                                     (0x000F8000&((data)<<15))
#define ENCODEBLKREG_TOTAL_COEF2_left_cb_a_src(data)                                 ((0x000F8000&(data))>>15)
#define ENCODEBLKREG_TOTAL_COEF2_get_left_cb_a(data)                                 ((0x000F8000&(data))>>15)
#define ENCODEBLKREG_TOTAL_COEF2_left_cb_b_shift                                     (10)
#define ENCODEBLKREG_TOTAL_COEF2_left_cb_b_mask                                      (0x00007C00)
#define ENCODEBLKREG_TOTAL_COEF2_left_cb_b(data)                                     (0x00007C00&((data)<<10))
#define ENCODEBLKREG_TOTAL_COEF2_left_cb_b_src(data)                                 ((0x00007C00&(data))>>10)
#define ENCODEBLKREG_TOTAL_COEF2_get_left_cb_b(data)                                 ((0x00007C00&(data))>>10)
#define ENCODEBLKREG_TOTAL_COEF2_left_cr_a_shift                                     (5)
#define ENCODEBLKREG_TOTAL_COEF2_left_cr_a_mask                                      (0x000003E0)
#define ENCODEBLKREG_TOTAL_COEF2_left_cr_a(data)                                     (0x000003E0&((data)<<5))
#define ENCODEBLKREG_TOTAL_COEF2_left_cr_a_src(data)                                 ((0x000003E0&(data))>>5)
#define ENCODEBLKREG_TOTAL_COEF2_get_left_cr_a(data)                                 ((0x000003E0&(data))>>5)
#define ENCODEBLKREG_TOTAL_COEF2_left_cr_b_shift                                     (0)
#define ENCODEBLKREG_TOTAL_COEF2_left_cr_b_mask                                      (0x0000001F)
#define ENCODEBLKREG_TOTAL_COEF2_left_cr_b(data)                                     (0x0000001F&((data)<<0))
#define ENCODEBLKREG_TOTAL_COEF2_left_cr_b_src(data)                                 ((0x0000001F&(data))>>0)
#define ENCODEBLKREG_TOTAL_COEF2_get_left_cr_b(data)                                 ((0x0000001F&(data))>>0)


#define ENCODEBLKREG_CABAC_LEFT_0                                                    0x18036478
#define ENCODEBLKREG_CABAC_LEFT_1                                                    0x1803647C
#define ENCODEBLKREG_CABAC_LEFT_2                                                    0x18036480
#define ENCODEBLKREG_CABAC_LEFT_3                                                    0x18036484
#define ENCODEBLKREG_CABAC_LEFT_4                                                    0x18036488
#define ENCODEBLKREG_CABAC_LEFT_5                                                    0x1803648C
#define ENCODEBLKREG_CABAC_LEFT_0_reg_addr                                           "0xB8036478"
#define ENCODEBLKREG_CABAC_LEFT_1_reg_addr                                           "0xB803647C"
#define ENCODEBLKREG_CABAC_LEFT_2_reg_addr                                           "0xB8036480"
#define ENCODEBLKREG_CABAC_LEFT_3_reg_addr                                           "0xB8036484"
#define ENCODEBLKREG_CABAC_LEFT_4_reg_addr                                           "0xB8036488"
#define ENCODEBLKREG_CABAC_LEFT_5_reg_addr                                           "0xB803648C"
#define ENCODEBLKREG_CABAC_LEFT_0_reg                                                0xB8036478
#define ENCODEBLKREG_CABAC_LEFT_1_reg                                                0xB803647C
#define ENCODEBLKREG_CABAC_LEFT_2_reg                                                0xB8036480
#define ENCODEBLKREG_CABAC_LEFT_3_reg                                                0xB8036484
#define ENCODEBLKREG_CABAC_LEFT_4_reg                                                0xB8036488
#define ENCODEBLKREG_CABAC_LEFT_5_reg                                                0xB803648C
#define set_ENCODEBLKREG_CABAC_LEFT_0_reg(data)   (*((volatile unsigned int*) ENCODEBLKREG_CABAC_LEFT_0_reg)=data)
#define set_ENCODEBLKREG_CABAC_LEFT_1_reg(data)   (*((volatile unsigned int*) ENCODEBLKREG_CABAC_LEFT_1_reg)=data)
#define set_ENCODEBLKREG_CABAC_LEFT_2_reg(data)   (*((volatile unsigned int*) ENCODEBLKREG_CABAC_LEFT_2_reg)=data)
#define set_ENCODEBLKREG_CABAC_LEFT_3_reg(data)   (*((volatile unsigned int*) ENCODEBLKREG_CABAC_LEFT_3_reg)=data)
#define set_ENCODEBLKREG_CABAC_LEFT_4_reg(data)   (*((volatile unsigned int*) ENCODEBLKREG_CABAC_LEFT_4_reg)=data)
#define set_ENCODEBLKREG_CABAC_LEFT_5_reg(data)   (*((volatile unsigned int*) ENCODEBLKREG_CABAC_LEFT_5_reg)=data)
#define get_ENCODEBLKREG_CABAC_LEFT_0_reg   (*((volatile unsigned int*) ENCODEBLKREG_CABAC_LEFT_0_reg))
#define get_ENCODEBLKREG_CABAC_LEFT_1_reg   (*((volatile unsigned int*) ENCODEBLKREG_CABAC_LEFT_1_reg))
#define get_ENCODEBLKREG_CABAC_LEFT_2_reg   (*((volatile unsigned int*) ENCODEBLKREG_CABAC_LEFT_2_reg))
#define get_ENCODEBLKREG_CABAC_LEFT_3_reg   (*((volatile unsigned int*) ENCODEBLKREG_CABAC_LEFT_3_reg))
#define get_ENCODEBLKREG_CABAC_LEFT_4_reg   (*((volatile unsigned int*) ENCODEBLKREG_CABAC_LEFT_4_reg))
#define get_ENCODEBLKREG_CABAC_LEFT_5_reg   (*((volatile unsigned int*) ENCODEBLKREG_CABAC_LEFT_5_reg))
#define ENCODEBLKREG_CABAC_LEFT_0_inst_adr                                           "0x001E"
#define ENCODEBLKREG_CABAC_LEFT_1_inst_adr                                           "0x001F"
#define ENCODEBLKREG_CABAC_LEFT_2_inst_adr                                           "0x0020"
#define ENCODEBLKREG_CABAC_LEFT_3_inst_adr                                           "0x0021"
#define ENCODEBLKREG_CABAC_LEFT_4_inst_adr                                           "0x0022"
#define ENCODEBLKREG_CABAC_LEFT_5_inst_adr                                           "0x0023"
#define ENCODEBLKREG_CABAC_LEFT_0_inst                                               0x001E
#define ENCODEBLKREG_CABAC_LEFT_1_inst                                               0x001F
#define ENCODEBLKREG_CABAC_LEFT_2_inst                                               0x0020
#define ENCODEBLKREG_CABAC_LEFT_3_inst                                               0x0021
#define ENCODEBLKREG_CABAC_LEFT_4_inst                                               0x0022
#define ENCODEBLKREG_CABAC_LEFT_5_inst                                               0x0023
#define ENCODEBLKREG_CABAC_LEFT_left_nb_shift                                        (0)
#define ENCODEBLKREG_CABAC_LEFT_left_nb_mask                                         (0xFFFFFFFF)
#define ENCODEBLKREG_CABAC_LEFT_left_nb(data)                                        (0xFFFFFFFF&((data)<<0))
#define ENCODEBLKREG_CABAC_LEFT_left_nb_src(data)                                    ((0xFFFFFFFF&(data))>>0)
#define ENCODEBLKREG_CABAC_LEFT_get_left_nb(data)                                    ((0xFFFFFFFF&(data))>>0)


#endif
