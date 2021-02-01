// This file is generated using the spec version 1.39, firmware template version 1.39and SRIF Parser                                                                                source code SVN rev:798                    Version flow no.:1.1.55
#ifndef _HDMI_REG_H_INCLUDED_
#define _HDMI_REG_H_INCLUDED_

//#define  _HDMI_USE_STRUCT
#ifdef _HDMI_USE_STRUCT

typedef struct
{
    unsigned int    reg_ck_4:8;
    unsigned int    reg_ck_3:8;
    unsigned int    reg_ck_2:8;
    unsigned int    reg_ck_1:8;
}REG_ck_1_4;

typedef struct
{
    unsigned int    reg_ck_8:8;
    unsigned int    reg_ck_7:8;
    unsigned int    reg_ck_6:8;
    unsigned int    reg_ck_5:8;
}REG_ck_5_8;

typedef struct
{
    unsigned int    reg_ck_12:8;
    unsigned int    reg_ck_11:8;
    unsigned int    reg_ck_10:8;
    unsigned int    reg_ck_9:8;
}REG_ck_9_12;

typedef struct
{
    unsigned int    ck_md_count:12;
    unsigned int    reserved_0:3;
    unsigned int    ck_koffok:1;
    unsigned int    ck_koff_bound:1;
    unsigned int    ck_koff_sel:4;
    unsigned int    ck_rate:4;
    unsigned int    ck_slicon:5;
    unsigned int    ck_wdo:1;
    unsigned int    ck_md_ok:1;
}REG_ck_result;

typedef struct
{
    unsigned int    reg_r_4:8;
    unsigned int    reg_r_3:8;
    unsigned int    reg_r_2:8;
    unsigned int    reg_r_1:8;
}REG_r_1_4;

typedef struct
{
    unsigned int    reg_r_8:8;
    unsigned int    reg_r_7:8;
    unsigned int    reg_r_6:8;
    unsigned int    reg_r_5:8;
}REG_r_5_8;

typedef struct
{
    unsigned int    reg_r_12:8;
    unsigned int    reg_r_11:8;
    unsigned int    reg_r_9:8;
    unsigned int    reg_r_10:8;
}REG_r_9_12;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    r_koffok:1;
    unsigned int    r_koff_bound:1;
    unsigned int    r_pr_msb:8;
    unsigned int    r_pr_lsb:8;
    unsigned int    r_filter_out_eq:7;
    unsigned int    r_eqcon:4;
}REG_r_result;

typedef struct
{
    unsigned int    reg_g_4:8;
    unsigned int    reg_g_3:8;
    unsigned int    reg_g_2:8;
    unsigned int    reg_g_1:8;
}REG_g_1_4;

typedef struct
{
    unsigned int    reg_g_8:8;
    unsigned int    reg_g_7:8;
    unsigned int    reg_g_6:8;
    unsigned int    reg_g_5:8;
}REG_g_5_8;

typedef struct
{
    unsigned int    reg_g_12:8;
    unsigned int    reg_g_11:8;
    unsigned int    reg_g_9:8;
    unsigned int    reg_g_10:8;
}REG_g_9_12;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    g_koffok:1;
    unsigned int    g_koff_bound:1;
    unsigned int    g_pr_msb:8;
    unsigned int    g_pr_lsb:8;
    unsigned int    g_filter_out_eq:7;
    unsigned int    g_eqcon:4;
}REG_g_result;

typedef struct
{
    unsigned int    reg_b_4:8;
    unsigned int    reg_b_3:8;
    unsigned int    reg_b_2:8;
    unsigned int    reg_b_1:8;
}REG_b_1_4;

typedef struct
{
    unsigned int    reg_b_8:8;
    unsigned int    reg_b_7:8;
    unsigned int    reg_b_6:8;
    unsigned int    reg_b_5:8;
}REG_b_5_8;

typedef struct
{
    unsigned int    reg_b_12:8;
    unsigned int    reg_b_11:8;
    unsigned int    reg_b_9:8;
    unsigned int    reg_b_10:8;
}REG_b_9_12;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    b_koffok:1;
    unsigned int    b_koff_bound:1;
    unsigned int    b_pr_msb:8;
    unsigned int    b_pr_lsb:8;
    unsigned int    b_filter_out_eq:7;
    unsigned int    b_eqcon:4;
}REG_b_result;

typedef struct
{
    unsigned int    reserved_0:6;
    unsigned int    bgpow:1;
    unsigned int    sbg:2;
    unsigned int    z0pow:1;
    unsigned int    adjr:4;
    unsigned int    entst_z0:1;
    unsigned int    z0tune:1;
    unsigned int    spad:1;
    unsigned int    stst:4;
    unsigned int    hspow:1;
    unsigned int    z0_res:4;
    unsigned int    z0tst:4;
    unsigned int    z0_ok:1;
    unsigned int    z0_bound:1;
}REG_bandgap_z0;

typedef struct
{
    unsigned int    dummy1800da44_31_21:11;
    unsigned int    phy_g_rst_n:1;
    unsigned int    phy_r_rst_n:1;
    unsigned int    phy_b_rst_n:1;
    unsigned int    phy_ck_pll_rst_n:1;
    unsigned int    phy_ck_rst_n:1;
    unsigned int    reg_top:8;
    unsigned int    dummy1800da44_7_6:2;
    unsigned int    reg_ckcmp:1;
    unsigned int    reg_ckdet:3;
    unsigned int    reg_cklatch:1;
    unsigned int    debug_select:1;
}REG_phy_ctl;
#endif


#define REG_CK_1_4                                                    0x1800da00
#define REG_CK_1_4_reg_addr                                           "0xb800da00"
#define REG_CK_1_4_reg                                                0xb800da00
#define REG_CK_1_4_inst_addr                                          "0x0280"
#define REG_CK_1_4_inst                                               0x0280
#define REG_CK_1_4_reg_ck_4_shift                                     (24)
#define REG_CK_1_4_reg_ck_3_shift                                     (16)
#define REG_CK_1_4_reg_ck_2_shift                                     (8)
#define REG_CK_1_4_reg_ck_1_shift                                     (0)
#define REG_CK_1_4_reg_ck_4_mask                                      (0xFF000000)
#define REG_CK_1_4_reg_ck_3_mask                                      (0x00FF0000)
#define REG_CK_1_4_reg_ck_2_mask                                      (0x0000FF00)
#define REG_CK_1_4_reg_ck_1_mask                                      (0x000000FF)
#define REG_CK_1_4_reg_ck_4(data)                                     (0xFF000000&((data)<<24))
#define REG_CK_1_4_reg_ck_3(data)                                     (0x00FF0000&((data)<<16))
#define REG_CK_1_4_reg_ck_2(data)                                     (0x0000FF00&((data)<<8))
#define REG_CK_1_4_reg_ck_1(data)                                     (0x000000FF&(data))
#define REG_CK_1_4_get_reg_ck_4(data)                                 ((0xFF000000&(data))>>24)
#define REG_CK_1_4_get_reg_ck_3(data)                                 ((0x00FF0000&(data))>>16)
#define REG_CK_1_4_get_reg_ck_2(data)                                 ((0x0000FF00&(data))>>8)
#define REG_CK_1_4_get_reg_ck_1(data)                                 (0x000000FF&(data))


#define REG_CK_5_8                                                    0x1800da04
#define REG_CK_5_8_reg_addr                                           "0xb800da04"
#define REG_CK_5_8_reg                                                0xb800da04
#define REG_CK_5_8_inst_addr                                          "0x0281"
#define REG_CK_5_8_inst                                               0x0281
#define REG_CK_5_8_reg_ck_8_shift                                     (24)
#define REG_CK_5_8_reg_ck_7_shift                                     (16)
#define REG_CK_5_8_reg_ck_6_shift                                     (8)
#define REG_CK_5_8_reg_ck_5_shift                                     (0)
#define REG_CK_5_8_reg_ck_8_mask                                      (0xFF000000)
#define REG_CK_5_8_reg_ck_7_mask                                      (0x00FF0000)
#define REG_CK_5_8_reg_ck_6_mask                                      (0x0000FF00)
#define REG_CK_5_8_reg_ck_5_mask                                      (0x000000FF)
#define REG_CK_5_8_reg_ck_8(data)                                     (0xFF000000&((data)<<24))
#define REG_CK_5_8_reg_ck_7(data)                                     (0x00FF0000&((data)<<16))
#define REG_CK_5_8_reg_ck_6(data)                                     (0x0000FF00&((data)<<8))
#define REG_CK_5_8_reg_ck_5(data)                                     (0x000000FF&(data))
#define REG_CK_5_8_get_reg_ck_8(data)                                 ((0xFF000000&(data))>>24)
#define REG_CK_5_8_get_reg_ck_7(data)                                 ((0x00FF0000&(data))>>16)
#define REG_CK_5_8_get_reg_ck_6(data)                                 ((0x0000FF00&(data))>>8)
#define REG_CK_5_8_get_reg_ck_5(data)                                 (0x000000FF&(data))


#define REG_CK_9_12                                                   0x1800da08
#define REG_CK_9_12_reg_addr                                          "0xb800da08"
#define REG_CK_9_12_reg                                               0xb800da08
#define REG_CK_9_12_inst_addr                                         "0x0282"
#define REG_CK_9_12_inst                                              0x0282
#define REG_CK_9_12_reg_ck_12_shift                                   (24)
#define REG_CK_9_12_reg_ck_11_shift                                   (16)
#define REG_CK_9_12_reg_ck_10_shift                                   (8)
#define REG_CK_9_12_reg_ck_9_shift                                    (0)
#define REG_CK_9_12_reg_ck_12_mask                                    (0xFF000000)
#define REG_CK_9_12_reg_ck_11_mask                                    (0x00FF0000)
#define REG_CK_9_12_reg_ck_10_mask                                    (0x0000FF00)
#define REG_CK_9_12_reg_ck_9_mask                                     (0x000000FF)
#define REG_CK_9_12_reg_ck_12(data)                                   (0xFF000000&((data)<<24))
#define REG_CK_9_12_reg_ck_11(data)                                   (0x00FF0000&((data)<<16))
#define REG_CK_9_12_reg_ck_10(data)                                   (0x0000FF00&((data)<<8))
#define REG_CK_9_12_reg_ck_9(data)                                    (0x000000FF&(data))
#define REG_CK_9_12_get_reg_ck_12(data)                               ((0xFF000000&(data))>>24)
#define REG_CK_9_12_get_reg_ck_11(data)                               ((0x00FF0000&(data))>>16)
#define REG_CK_9_12_get_reg_ck_10(data)                               ((0x0000FF00&(data))>>8)
#define REG_CK_9_12_get_reg_ck_9(data)                                (0x000000FF&(data))


#define REG_CK_RESULT                                                 0x1800da0c
#define REG_CK_RESULT_reg_addr                                        "0xb800da0c"
#define REG_CK_RESULT_reg                                             0xb800da0c
#define REG_CK_RESULT_inst_addr                                       "0x0283"
#define REG_CK_RESULT_inst                                            0x0283
#define REG_CK_RESULT_ck_md_count_shift                               (20)
#define REG_CK_RESULT_ck_koffok_shift                                 (16)
#define REG_CK_RESULT_ck_koff_bound_shift                             (15)
#define REG_CK_RESULT_ck_koff_sel_shift                               (11)
#define REG_CK_RESULT_ck_rate_shift                                   (7)
#define REG_CK_RESULT_ck_slicon_shift                                 (2)
#define REG_CK_RESULT_ck_wdo_shift                                    (1)
#define REG_CK_RESULT_ck_md_ok_shift                                  (0)
#define REG_CK_RESULT_ck_md_count_mask                                (0xFFF00000)
#define REG_CK_RESULT_ck_koffok_mask                                  (0x00010000)
#define REG_CK_RESULT_ck_koff_bound_mask                              (0x00008000)
#define REG_CK_RESULT_ck_koff_sel_mask                                (0x00007800)
#define REG_CK_RESULT_ck_rate_mask                                    (0x00000780)
#define REG_CK_RESULT_ck_slicon_mask                                  (0x0000007C)
#define REG_CK_RESULT_ck_wdo_mask                                     (0x00000002)
#define REG_CK_RESULT_ck_md_ok_mask                                   (0x00000001)
#define REG_CK_RESULT_ck_md_count(data)                               (0xFFF00000&((data)<<20))
#define REG_CK_RESULT_ck_koffok(data)                                 (0x00010000&((data)<<16))
#define REG_CK_RESULT_ck_koff_bound(data)                             (0x00008000&((data)<<15))
#define REG_CK_RESULT_ck_koff_sel(data)                               (0x00007800&((data)<<11))
#define REG_CK_RESULT_ck_rate(data)                                   (0x00000780&((data)<<7))
#define REG_CK_RESULT_ck_slicon(data)                                 (0x0000007C&((data)<<2))
#define REG_CK_RESULT_ck_wdo(data)                                    (0x00000002&((data)<<1))
#define REG_CK_RESULT_ck_md_ok(data)                                  (0x00000001&(data))
#define REG_CK_RESULT_get_ck_md_count(data)                           ((0xFFF00000&(data))>>20)
#define REG_CK_RESULT_get_ck_koffok(data)                             ((0x00010000&(data))>>16)
#define REG_CK_RESULT_get_ck_koff_bound(data)                         ((0x00008000&(data))>>15)
#define REG_CK_RESULT_get_ck_koff_sel(data)                           ((0x00007800&(data))>>11)
#define REG_CK_RESULT_get_ck_rate(data)                               ((0x00000780&(data))>>7)
#define REG_CK_RESULT_get_ck_slicon(data)                             ((0x0000007C&(data))>>2)
#define REG_CK_RESULT_get_ck_wdo(data)                                ((0x00000002&(data))>>1)
#define REG_CK_RESULT_get_ck_md_ok(data)                              (0x00000001&(data))


#define REG_R_1_4                                                     0x1800da10
#define REG_R_1_4_reg_addr                                            "0xb800da10"
#define REG_R_1_4_reg                                                 0xb800da10
#define REG_R_1_4_inst_addr                                           "0x0284"
#define REG_R_1_4_inst                                                0x0284
#define REG_R_1_4_reg_r_4_shift                                       (24)
#define REG_R_1_4_reg_r_3_shift                                       (16)
#define REG_R_1_4_reg_r_2_shift                                       (8)
#define REG_R_1_4_reg_r_1_shift                                       (0)
#define REG_R_1_4_reg_r_4_mask                                        (0xFF000000)
#define REG_R_1_4_reg_r_3_mask                                        (0x00FF0000)
#define REG_R_1_4_reg_r_2_mask                                        (0x0000FF00)
#define REG_R_1_4_reg_r_1_mask                                        (0x000000FF)
#define REG_R_1_4_reg_r_4(data)                                       (0xFF000000&((data)<<24))
#define REG_R_1_4_reg_r_3(data)                                       (0x00FF0000&((data)<<16))
#define REG_R_1_4_reg_r_2(data)                                       (0x0000FF00&((data)<<8))
#define REG_R_1_4_reg_r_1(data)                                       (0x000000FF&(data))
#define REG_R_1_4_get_reg_r_4(data)                                   ((0xFF000000&(data))>>24)
#define REG_R_1_4_get_reg_r_3(data)                                   ((0x00FF0000&(data))>>16)
#define REG_R_1_4_get_reg_r_2(data)                                   ((0x0000FF00&(data))>>8)
#define REG_R_1_4_get_reg_r_1(data)                                   (0x000000FF&(data))


#define REG_R_5_8                                                     0x1800da14
#define REG_R_5_8_reg_addr                                            "0xb800da14"
#define REG_R_5_8_reg                                                 0xb800da14
#define REG_R_5_8_inst_addr                                           "0x0285"
#define REG_R_5_8_inst                                                0x0285
#define REG_R_5_8_reg_r_8_shift                                       (24)
#define REG_R_5_8_reg_r_7_shift                                       (16)
#define REG_R_5_8_reg_r_6_shift                                       (8)
#define REG_R_5_8_reg_r_5_shift                                       (0)
#define REG_R_5_8_reg_r_8_mask                                        (0xFF000000)
#define REG_R_5_8_reg_r_7_mask                                        (0x00FF0000)
#define REG_R_5_8_reg_r_6_mask                                        (0x0000FF00)
#define REG_R_5_8_reg_r_5_mask                                        (0x000000FF)
#define REG_R_5_8_reg_r_8(data)                                       (0xFF000000&((data)<<24))
#define REG_R_5_8_reg_r_7(data)                                       (0x00FF0000&((data)<<16))
#define REG_R_5_8_reg_r_6(data)                                       (0x0000FF00&((data)<<8))
#define REG_R_5_8_reg_r_5(data)                                       (0x000000FF&(data))
#define REG_R_5_8_get_reg_r_8(data)                                   ((0xFF000000&(data))>>24)
#define REG_R_5_8_get_reg_r_7(data)                                   ((0x00FF0000&(data))>>16)
#define REG_R_5_8_get_reg_r_6(data)                                   ((0x0000FF00&(data))>>8)
#define REG_R_5_8_get_reg_r_5(data)                                   (0x000000FF&(data))


#define REG_R_9_12                                                    0x1800da18
#define REG_R_9_12_reg_addr                                           "0xb800da18"
#define REG_R_9_12_reg                                                0xb800da18
#define REG_R_9_12_inst_addr                                          "0x0286"
#define REG_R_9_12_inst                                               0x0286
#define REG_R_9_12_reg_r_12_shift                                     (24)
#define REG_R_9_12_reg_r_11_shift                                     (16)
#define REG_R_9_12_reg_r_9_shift                                      (8)
#define REG_R_9_12_reg_r_10_shift                                     (0)
#define REG_R_9_12_reg_r_12_mask                                      (0xFF000000)
#define REG_R_9_12_reg_r_11_mask                                      (0x00FF0000)
#define REG_R_9_12_reg_r_9_mask                                       (0x0000FF00)
#define REG_R_9_12_reg_r_10_mask                                      (0x000000FF)
#define REG_R_9_12_reg_r_12(data)                                     (0xFF000000&((data)<<24))
#define REG_R_9_12_reg_r_11(data)                                     (0x00FF0000&((data)<<16))
#define REG_R_9_12_reg_r_9(data)                                      (0x0000FF00&((data)<<8))
#define REG_R_9_12_reg_r_10(data)                                     (0x000000FF&(data))
#define REG_R_9_12_get_reg_r_12(data)                                 ((0xFF000000&(data))>>24)
#define REG_R_9_12_get_reg_r_11(data)                                 ((0x00FF0000&(data))>>16)
#define REG_R_9_12_get_reg_r_9(data)                                  ((0x0000FF00&(data))>>8)
#define REG_R_9_12_get_reg_r_10(data)                                 (0x000000FF&(data))


#define REG_R_RESULT                                                  0x1800da1c
#define REG_R_RESULT_reg_addr                                         "0xb800da1c"
#define REG_R_RESULT_reg                                              0xb800da1c
#define REG_R_RESULT_inst_addr                                        "0x0287"
#define REG_R_RESULT_inst                                             0x0287
#define REG_R_RESULT_r_koffok_shift                                   (28)
#define REG_R_RESULT_r_koff_bound_shift                               (27)
#define REG_R_RESULT_r_pr_msb_shift                                   (19)
#define REG_R_RESULT_r_pr_lsb_shift                                   (11)
#define REG_R_RESULT_r_filter_out_eq_shift                            (4)
#define REG_R_RESULT_r_eqcon_shift                                    (0)
#define REG_R_RESULT_r_koffok_mask                                    (0x10000000)
#define REG_R_RESULT_r_koff_bound_mask                                (0x08000000)
#define REG_R_RESULT_r_pr_msb_mask                                    (0x07F80000)
#define REG_R_RESULT_r_pr_lsb_mask                                    (0x0007F800)
#define REG_R_RESULT_r_filter_out_eq_mask                             (0x000007F0)
#define REG_R_RESULT_r_eqcon_mask                                     (0x0000000F)
#define REG_R_RESULT_r_koffok(data)                                   (0x10000000&((data)<<28))
#define REG_R_RESULT_r_koff_bound(data)                               (0x08000000&((data)<<27))
#define REG_R_RESULT_r_pr_msb(data)                                   (0x07F80000&((data)<<19))
#define REG_R_RESULT_r_pr_lsb(data)                                   (0x0007F800&((data)<<11))
#define REG_R_RESULT_r_filter_out_eq(data)                            (0x000007F0&((data)<<4))
#define REG_R_RESULT_r_eqcon(data)                                    (0x0000000F&(data))
#define REG_R_RESULT_get_r_koffok(data)                               ((0x10000000&(data))>>28)
#define REG_R_RESULT_get_r_koff_bound(data)                           ((0x08000000&(data))>>27)
#define REG_R_RESULT_get_r_pr_msb(data)                               ((0x07F80000&(data))>>19)
#define REG_R_RESULT_get_r_pr_lsb(data)                               ((0x0007F800&(data))>>11)
#define REG_R_RESULT_get_r_filter_out_eq(data)                        ((0x000007F0&(data))>>4)
#define REG_R_RESULT_get_r_eqcon(data)                                (0x0000000F&(data))


#define REG_G_1_4                                                     0x1800da20
#define REG_G_1_4_reg_addr                                            "0xb800da20"
#define REG_G_1_4_reg                                                 0xb800da20
#define REG_G_1_4_inst_addr                                           "0x0288"
#define REG_G_1_4_inst                                                0x0288
#define REG_G_1_4_reg_g_4_shift                                       (24)
#define REG_G_1_4_reg_g_3_shift                                       (16)
#define REG_G_1_4_reg_g_2_shift                                       (8)
#define REG_G_1_4_reg_g_1_shift                                       (0)
#define REG_G_1_4_reg_g_4_mask                                        (0xFF000000)
#define REG_G_1_4_reg_g_3_mask                                        (0x00FF0000)
#define REG_G_1_4_reg_g_2_mask                                        (0x0000FF00)
#define REG_G_1_4_reg_g_1_mask                                        (0x000000FF)
#define REG_G_1_4_reg_g_4(data)                                       (0xFF000000&((data)<<24))
#define REG_G_1_4_reg_g_3(data)                                       (0x00FF0000&((data)<<16))
#define REG_G_1_4_reg_g_2(data)                                       (0x0000FF00&((data)<<8))
#define REG_G_1_4_reg_g_1(data)                                       (0x000000FF&(data))
#define REG_G_1_4_get_reg_g_4(data)                                   ((0xFF000000&(data))>>24)
#define REG_G_1_4_get_reg_g_3(data)                                   ((0x00FF0000&(data))>>16)
#define REG_G_1_4_get_reg_g_2(data)                                   ((0x0000FF00&(data))>>8)
#define REG_G_1_4_get_reg_g_1(data)                                   (0x000000FF&(data))


#define REG_G_5_8                                                     0x1800da24
#define REG_G_5_8_reg_addr                                            "0xb800da24"
#define REG_G_5_8_reg                                                 0xb800da24
#define REG_G_5_8_inst_addr                                           "0x0289"
#define REG_G_5_8_inst                                                0x0289
#define REG_G_5_8_reg_g_8_shift                                       (24)
#define REG_G_5_8_reg_g_7_shift                                       (16)
#define REG_G_5_8_reg_g_6_shift                                       (8)
#define REG_G_5_8_reg_g_5_shift                                       (0)
#define REG_G_5_8_reg_g_8_mask                                        (0xFF000000)
#define REG_G_5_8_reg_g_7_mask                                        (0x00FF0000)
#define REG_G_5_8_reg_g_6_mask                                        (0x0000FF00)
#define REG_G_5_8_reg_g_5_mask                                        (0x000000FF)
#define REG_G_5_8_reg_g_8(data)                                       (0xFF000000&((data)<<24))
#define REG_G_5_8_reg_g_7(data)                                       (0x00FF0000&((data)<<16))
#define REG_G_5_8_reg_g_6(data)                                       (0x0000FF00&((data)<<8))
#define REG_G_5_8_reg_g_5(data)                                       (0x000000FF&(data))
#define REG_G_5_8_get_reg_g_8(data)                                   ((0xFF000000&(data))>>24)
#define REG_G_5_8_get_reg_g_7(data)                                   ((0x00FF0000&(data))>>16)
#define REG_G_5_8_get_reg_g_6(data)                                   ((0x0000FF00&(data))>>8)
#define REG_G_5_8_get_reg_g_5(data)                                   (0x000000FF&(data))


#define REG_G_9_12                                                    0x1800da28
#define REG_G_9_12_reg_addr                                           "0xb800da28"
#define REG_G_9_12_reg                                                0xb800da28
#define REG_G_9_12_inst_addr                                          "0x028A"
#define REG_G_9_12_inst                                               0x028A
#define REG_G_9_12_reg_g_12_shift                                     (24)
#define REG_G_9_12_reg_g_11_shift                                     (16)
#define REG_G_9_12_reg_g_9_shift                                      (8)
#define REG_G_9_12_reg_g_10_shift                                     (0)
#define REG_G_9_12_reg_g_12_mask                                      (0xFF000000)
#define REG_G_9_12_reg_g_11_mask                                      (0x00FF0000)
#define REG_G_9_12_reg_g_9_mask                                       (0x0000FF00)
#define REG_G_9_12_reg_g_10_mask                                      (0x000000FF)
#define REG_G_9_12_reg_g_12(data)                                     (0xFF000000&((data)<<24))
#define REG_G_9_12_reg_g_11(data)                                     (0x00FF0000&((data)<<16))
#define REG_G_9_12_reg_g_9(data)                                      (0x0000FF00&((data)<<8))
#define REG_G_9_12_reg_g_10(data)                                     (0x000000FF&(data))
#define REG_G_9_12_get_reg_g_12(data)                                 ((0xFF000000&(data))>>24)
#define REG_G_9_12_get_reg_g_11(data)                                 ((0x00FF0000&(data))>>16)
#define REG_G_9_12_get_reg_g_9(data)                                  ((0x0000FF00&(data))>>8)
#define REG_G_9_12_get_reg_g_10(data)                                 (0x000000FF&(data))


#define REG_G_RESULT                                                  0x1800da2c
#define REG_G_RESULT_reg_addr                                         "0xb800da2c"
#define REG_G_RESULT_reg                                              0xb800da2c
#define REG_G_RESULT_inst_addr                                        "0x028B"
#define REG_G_RESULT_inst                                             0x028B
#define REG_G_RESULT_g_koffok_shift                                   (28)
#define REG_G_RESULT_g_koff_bound_shift                               (27)
#define REG_G_RESULT_g_pr_msb_shift                                   (19)
#define REG_G_RESULT_g_pr_lsb_shift                                   (11)
#define REG_G_RESULT_g_filter_out_eq_shift                            (4)
#define REG_G_RESULT_g_eqcon_shift                                    (0)
#define REG_G_RESULT_g_koffok_mask                                    (0x10000000)
#define REG_G_RESULT_g_koff_bound_mask                                (0x08000000)
#define REG_G_RESULT_g_pr_msb_mask                                    (0x07F80000)
#define REG_G_RESULT_g_pr_lsb_mask                                    (0x0007F800)
#define REG_G_RESULT_g_filter_out_eq_mask                             (0x000007F0)
#define REG_G_RESULT_g_eqcon_mask                                     (0x0000000F)
#define REG_G_RESULT_g_koffok(data)                                   (0x10000000&((data)<<28))
#define REG_G_RESULT_g_koff_bound(data)                               (0x08000000&((data)<<27))
#define REG_G_RESULT_g_pr_msb(data)                                   (0x07F80000&((data)<<19))
#define REG_G_RESULT_g_pr_lsb(data)                                   (0x0007F800&((data)<<11))
#define REG_G_RESULT_g_filter_out_eq(data)                            (0x000007F0&((data)<<4))
#define REG_G_RESULT_g_eqcon(data)                                    (0x0000000F&(data))
#define REG_G_RESULT_get_g_koffok(data)                               ((0x10000000&(data))>>28)
#define REG_G_RESULT_get_g_koff_bound(data)                           ((0x08000000&(data))>>27)
#define REG_G_RESULT_get_g_pr_msb(data)                               ((0x07F80000&(data))>>19)
#define REG_G_RESULT_get_g_pr_lsb(data)                               ((0x0007F800&(data))>>11)
#define REG_G_RESULT_get_g_filter_out_eq(data)                        ((0x000007F0&(data))>>4)
#define REG_G_RESULT_get_g_eqcon(data)                                (0x0000000F&(data))


#define REG_B_1_4                                                     0x1800da30
#define REG_B_1_4_reg_addr                                            "0xb800da30"
#define REG_B_1_4_reg                                                 0xb800da30
#define REG_B_1_4_inst_addr                                           "0x028C"
#define REG_B_1_4_inst                                                0x028C
#define REG_B_1_4_reg_b_4_shift                                       (24)
#define REG_B_1_4_reg_b_3_shift                                       (16)
#define REG_B_1_4_reg_b_2_shift                                       (8)
#define REG_B_1_4_reg_b_1_shift                                       (0)
#define REG_B_1_4_reg_b_4_mask                                        (0xFF000000)
#define REG_B_1_4_reg_b_3_mask                                        (0x00FF0000)
#define REG_B_1_4_reg_b_2_mask                                        (0x0000FF00)
#define REG_B_1_4_reg_b_1_mask                                        (0x000000FF)
#define REG_B_1_4_reg_b_4(data)                                       (0xFF000000&((data)<<24))
#define REG_B_1_4_reg_b_3(data)                                       (0x00FF0000&((data)<<16))
#define REG_B_1_4_reg_b_2(data)                                       (0x0000FF00&((data)<<8))
#define REG_B_1_4_reg_b_1(data)                                       (0x000000FF&(data))
#define REG_B_1_4_get_reg_b_4(data)                                   ((0xFF000000&(data))>>24)
#define REG_B_1_4_get_reg_b_3(data)                                   ((0x00FF0000&(data))>>16)
#define REG_B_1_4_get_reg_b_2(data)                                   ((0x0000FF00&(data))>>8)
#define REG_B_1_4_get_reg_b_1(data)                                   (0x000000FF&(data))


#define REG_B_5_8                                                     0x1800da34
#define REG_B_5_8_reg_addr                                            "0xb800da34"
#define REG_B_5_8_reg                                                 0xb800da34
#define REG_B_5_8_inst_addr                                           "0x028D"
#define REG_B_5_8_inst                                                0x028D
#define REG_B_5_8_reg_b_8_shift                                       (24)
#define REG_B_5_8_reg_b_7_shift                                       (16)
#define REG_B_5_8_reg_b_6_shift                                       (8)
#define REG_B_5_8_reg_b_5_shift                                       (0)
#define REG_B_5_8_reg_b_8_mask                                        (0xFF000000)
#define REG_B_5_8_reg_b_7_mask                                        (0x00FF0000)
#define REG_B_5_8_reg_b_6_mask                                        (0x0000FF00)
#define REG_B_5_8_reg_b_5_mask                                        (0x000000FF)
#define REG_B_5_8_reg_b_8(data)                                       (0xFF000000&((data)<<24))
#define REG_B_5_8_reg_b_7(data)                                       (0x00FF0000&((data)<<16))
#define REG_B_5_8_reg_b_6(data)                                       (0x0000FF00&((data)<<8))
#define REG_B_5_8_reg_b_5(data)                                       (0x000000FF&(data))
#define REG_B_5_8_get_reg_b_8(data)                                   ((0xFF000000&(data))>>24)
#define REG_B_5_8_get_reg_b_7(data)                                   ((0x00FF0000&(data))>>16)
#define REG_B_5_8_get_reg_b_6(data)                                   ((0x0000FF00&(data))>>8)
#define REG_B_5_8_get_reg_b_5(data)                                   (0x000000FF&(data))


#define REG_B_9_12                                                    0x1800da38
#define REG_B_9_12_reg_addr                                           "0xb800da38"
#define REG_B_9_12_reg                                                0xb800da38
#define REG_B_9_12_inst_addr                                          "0x028E"
#define REG_B_9_12_inst                                               0x028E
#define REG_B_9_12_reg_b_12_shift                                     (24)
#define REG_B_9_12_reg_b_11_shift                                     (16)
#define REG_B_9_12_reg_b_9_shift                                      (8)
#define REG_B_9_12_reg_b_10_shift                                     (0)
#define REG_B_9_12_reg_b_12_mask                                      (0xFF000000)
#define REG_B_9_12_reg_b_11_mask                                      (0x00FF0000)
#define REG_B_9_12_reg_b_9_mask                                       (0x0000FF00)
#define REG_B_9_12_reg_b_10_mask                                      (0x000000FF)
#define REG_B_9_12_reg_b_12(data)                                     (0xFF000000&((data)<<24))
#define REG_B_9_12_reg_b_11(data)                                     (0x00FF0000&((data)<<16))
#define REG_B_9_12_reg_b_9(data)                                      (0x0000FF00&((data)<<8))
#define REG_B_9_12_reg_b_10(data)                                     (0x000000FF&(data))
#define REG_B_9_12_get_reg_b_12(data)                                 ((0xFF000000&(data))>>24)
#define REG_B_9_12_get_reg_b_11(data)                                 ((0x00FF0000&(data))>>16)
#define REG_B_9_12_get_reg_b_9(data)                                  ((0x0000FF00&(data))>>8)
#define REG_B_9_12_get_reg_b_10(data)                                 (0x000000FF&(data))


#define REG_B_RESULT                                                  0x1800da3c
#define REG_B_RESULT_reg_addr                                         "0xb800da3c"
#define REG_B_RESULT_reg                                              0xb800da3c
#define REG_B_RESULT_inst_addr                                        "0x028F"
#define REG_B_RESULT_inst                                             0x028F
#define REG_B_RESULT_b_koffok_shift                                   (28)
#define REG_B_RESULT_b_koff_bound_shift                               (27)
#define REG_B_RESULT_b_pr_msb_shift                                   (19)
#define REG_B_RESULT_b_pr_lsb_shift                                   (11)
#define REG_B_RESULT_b_filter_out_eq_shift                            (4)
#define REG_B_RESULT_b_eqcon_shift                                    (0)
#define REG_B_RESULT_b_koffok_mask                                    (0x10000000)
#define REG_B_RESULT_b_koff_bound_mask                                (0x08000000)
#define REG_B_RESULT_b_pr_msb_mask                                    (0x07F80000)
#define REG_B_RESULT_b_pr_lsb_mask                                    (0x0007F800)
#define REG_B_RESULT_b_filter_out_eq_mask                             (0x000007F0)
#define REG_B_RESULT_b_eqcon_mask                                     (0x0000000F)
#define REG_B_RESULT_b_koffok(data)                                   (0x10000000&((data)<<28))
#define REG_B_RESULT_b_koff_bound(data)                               (0x08000000&((data)<<27))
#define REG_B_RESULT_b_pr_msb(data)                                   (0x07F80000&((data)<<19))
#define REG_B_RESULT_b_pr_lsb(data)                                   (0x0007F800&((data)<<11))
#define REG_B_RESULT_b_filter_out_eq(data)                            (0x000007F0&((data)<<4))
#define REG_B_RESULT_b_eqcon(data)                                    (0x0000000F&(data))
#define REG_B_RESULT_get_b_koffok(data)                               ((0x10000000&(data))>>28)
#define REG_B_RESULT_get_b_koff_bound(data)                           ((0x08000000&(data))>>27)
#define REG_B_RESULT_get_b_pr_msb(data)                               ((0x07F80000&(data))>>19)
#define REG_B_RESULT_get_b_pr_lsb(data)                               ((0x0007F800&(data))>>11)
#define REG_B_RESULT_get_b_filter_out_eq(data)                        ((0x000007F0&(data))>>4)
#define REG_B_RESULT_get_b_eqcon(data)                                (0x0000000F&(data))


#define REG_BANDGAP_Z0                                                0x1800da40
#define REG_BANDGAP_Z0_reg_addr                                       "0xb800da40"
#define REG_BANDGAP_Z0_reg                                            0xb800da40
#define REG_BANDGAP_Z0_inst_addr                                      "0x0290"
#define REG_BANDGAP_Z0_inst                                           0x0290
#define REG_BANDGAP_Z0_bgpow_shift                                    (25)
#define REG_BANDGAP_Z0_sbg_shift                                      (23)
#define REG_BANDGAP_Z0_z0pow_shift                                    (22)
#define REG_BANDGAP_Z0_adjr_shift                                     (18)
#define REG_BANDGAP_Z0_entst_z0_shift                                 (17)
#define REG_BANDGAP_Z0_z0tune_shift                                   (16)
#define REG_BANDGAP_Z0_spad_shift                                     (15)
#define REG_BANDGAP_Z0_stst_shift                                     (11)
#define REG_BANDGAP_Z0_hspow_shift                                    (10)
#define REG_BANDGAP_Z0_z0_res_shift                                   (6)
#define REG_BANDGAP_Z0_z0tst_shift                                    (2)
#define REG_BANDGAP_Z0_z0_ok_shift                                    (1)
#define REG_BANDGAP_Z0_z0_bound_shift                                 (0)
#define REG_BANDGAP_Z0_bgpow_mask                                     (0x02000000)
#define REG_BANDGAP_Z0_sbg_mask                                       (0x01800000)
#define REG_BANDGAP_Z0_z0pow_mask                                     (0x00400000)
#define REG_BANDGAP_Z0_adjr_mask                                      (0x003C0000)
#define REG_BANDGAP_Z0_entst_z0_mask                                  (0x00020000)
#define REG_BANDGAP_Z0_z0tune_mask                                    (0x00010000)
#define REG_BANDGAP_Z0_spad_mask                                      (0x00008000)
#define REG_BANDGAP_Z0_stst_mask                                      (0x00007800)
#define REG_BANDGAP_Z0_hspow_mask                                     (0x00000400)
#define REG_BANDGAP_Z0_z0_res_mask                                    (0x000003C0)
#define REG_BANDGAP_Z0_z0tst_mask                                     (0x0000003C)
#define REG_BANDGAP_Z0_z0_ok_mask                                     (0x00000002)
#define REG_BANDGAP_Z0_z0_bound_mask                                  (0x00000001)
#define REG_BANDGAP_Z0_bgpow(data)                                    (0x02000000&((data)<<25))
#define REG_BANDGAP_Z0_sbg(data)                                      (0x01800000&((data)<<23))
#define REG_BANDGAP_Z0_z0pow(data)                                    (0x00400000&((data)<<22))
#define REG_BANDGAP_Z0_adjr(data)                                     (0x003C0000&((data)<<18))
#define REG_BANDGAP_Z0_entst_z0(data)                                 (0x00020000&((data)<<17))
#define REG_BANDGAP_Z0_z0tune(data)                                   (0x00010000&((data)<<16))
#define REG_BANDGAP_Z0_spad(data)                                     (0x00008000&((data)<<15))
#define REG_BANDGAP_Z0_stst(data)                                     (0x00007800&((data)<<11))
#define REG_BANDGAP_Z0_hspow(data)                                    (0x00000400&((data)<<10))
#define REG_BANDGAP_Z0_z0_res(data)                                   (0x000003C0&((data)<<6))
#define REG_BANDGAP_Z0_z0tst(data)                                    (0x0000003C&((data)<<2))
#define REG_BANDGAP_Z0_z0_ok(data)                                    (0x00000002&((data)<<1))
#define REG_BANDGAP_Z0_z0_bound(data)                                 (0x00000001&(data))
#define REG_BANDGAP_Z0_get_bgpow(data)                                ((0x02000000&(data))>>25)
#define REG_BANDGAP_Z0_get_sbg(data)                                  ((0x01800000&(data))>>23)
#define REG_BANDGAP_Z0_get_z0pow(data)                                ((0x00400000&(data))>>22)
#define REG_BANDGAP_Z0_get_adjr(data)                                 ((0x003C0000&(data))>>18)
#define REG_BANDGAP_Z0_get_entst_z0(data)                             ((0x00020000&(data))>>17)
#define REG_BANDGAP_Z0_get_z0tune(data)                               ((0x00010000&(data))>>16)
#define REG_BANDGAP_Z0_get_spad(data)                                 ((0x00008000&(data))>>15)
#define REG_BANDGAP_Z0_get_stst(data)                                 ((0x00007800&(data))>>11)
#define REG_BANDGAP_Z0_get_hspow(data)                                ((0x00000400&(data))>>10)
#define REG_BANDGAP_Z0_get_z0_res(data)                               ((0x000003C0&(data))>>6)
#define REG_BANDGAP_Z0_get_z0tst(data)                                ((0x0000003C&(data))>>2)
#define REG_BANDGAP_Z0_get_z0_ok(data)                                ((0x00000002&(data))>>1)
#define REG_BANDGAP_Z0_get_z0_bound(data)                             (0x00000001&(data))


#define REG_PHY_CTL                                                   0x1800da44
#define REG_PHY_CTL_reg_addr                                          "0xb800da44"
#define REG_PHY_CTL_reg                                               0xb800da44
#define REG_PHY_CTL_inst_addr                                         "0x0291"
#define REG_PHY_CTL_inst                                              0x0291
#define REG_PHY_CTL_dummy1800da44_31_21_shift                         (21)
#define REG_PHY_CTL_phy_g_rst_n_shift                                 (20)
#define REG_PHY_CTL_phy_r_rst_n_shift                                 (19)
#define REG_PHY_CTL_phy_b_rst_n_shift                                 (18)
#define REG_PHY_CTL_phy_ck_pll_rst_n_shift                            (17)
#define REG_PHY_CTL_phy_ck_rst_n_shift                                (16)
#define REG_PHY_CTL_reg_top_shift                                     (8)
#define REG_PHY_CTL_dummy1800da44_7_6_shift                           (6)
#define REG_PHY_CTL_reg_ckcmp_shift                                   (5)
#define REG_PHY_CTL_reg_ckdet_shift                                   (2)
#define REG_PHY_CTL_reg_cklatch_shift                                 (1)
#define REG_PHY_CTL_debug_select_shift                                (0)
#define REG_PHY_CTL_dummy1800da44_31_21_mask                          (0xFFE00000)
#define REG_PHY_CTL_phy_g_rst_n_mask                                  (0x00100000)
#define REG_PHY_CTL_phy_r_rst_n_mask                                  (0x00080000)
#define REG_PHY_CTL_phy_b_rst_n_mask                                  (0x00040000)
#define REG_PHY_CTL_phy_ck_pll_rst_n_mask                             (0x00020000)
#define REG_PHY_CTL_phy_ck_rst_n_mask                                 (0x00010000)
#define REG_PHY_CTL_reg_top_mask                                      (0x0000FF00)
#define REG_PHY_CTL_dummy1800da44_7_6_mask                            (0x000000C0)
#define REG_PHY_CTL_reg_ckcmp_mask                                    (0x00000020)
#define REG_PHY_CTL_reg_ckdet_mask                                    (0x0000001C)
#define REG_PHY_CTL_reg_cklatch_mask                                  (0x00000002)
#define REG_PHY_CTL_debug_select_mask                                 (0x00000001)
#define REG_PHY_CTL_dummy1800da44_31_21(data)                         (0xFFE00000&((data)<<21))
#define REG_PHY_CTL_phy_g_rst_n(data)                                 (0x00100000&((data)<<20))
#define REG_PHY_CTL_phy_r_rst_n(data)                                 (0x00080000&((data)<<19))
#define REG_PHY_CTL_phy_b_rst_n(data)                                 (0x00040000&((data)<<18))
#define REG_PHY_CTL_phy_ck_pll_rst_n(data)                            (0x00020000&((data)<<17))
#define REG_PHY_CTL_phy_ck_rst_n(data)                                (0x00010000&((data)<<16))
#define REG_PHY_CTL_reg_top(data)                                     (0x0000FF00&((data)<<8))
#define REG_PHY_CTL_dummy1800da44_7_6(data)                           (0x000000C0&((data)<<6))
#define REG_PHY_CTL_reg_ckcmp(data)                                   (0x00000020&((data)<<5))
#define REG_PHY_CTL_reg_ckdet(data)                                   (0x0000001C&((data)<<2))
#define REG_PHY_CTL_reg_cklatch(data)                                 (0x00000002&((data)<<1))
#define REG_PHY_CTL_debug_select(data)                                (0x00000001&(data))
#define REG_PHY_CTL_get_dummy1800da44_31_21(data)                     ((0xFFE00000&(data))>>21)
#define REG_PHY_CTL_get_phy_g_rst_n(data)                             ((0x00100000&(data))>>20)
#define REG_PHY_CTL_get_phy_r_rst_n(data)                             ((0x00080000&(data))>>19)
#define REG_PHY_CTL_get_phy_b_rst_n(data)                             ((0x00040000&(data))>>18)
#define REG_PHY_CTL_get_phy_ck_pll_rst_n(data)                        ((0x00020000&(data))>>17)
#define REG_PHY_CTL_get_phy_ck_rst_n(data)                            ((0x00010000&(data))>>16)
#define REG_PHY_CTL_get_reg_top(data)                                 ((0x0000FF00&(data))>>8)
#define REG_PHY_CTL_get_dummy1800da44_7_6(data)                       ((0x000000C0&(data))>>6)
#define REG_PHY_CTL_get_reg_ckcmp(data)                               ((0x00000020&(data))>>5)
#define REG_PHY_CTL_get_reg_ckdet(data)                               ((0x0000001C&(data))>>2)
#define REG_PHY_CTL_get_reg_cklatch(data)                             ((0x00000002&(data))>>1)
#define REG_PHY_CTL_get_debug_select(data)                            (0x00000001&(data))
#endif

