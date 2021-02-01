// This file is generated using the spec version 1.39, firmware template version 1.39and SRIF Parser                                                                                source code SVN rev:750                    Version flow no.:1.0.208
#ifndef _OSDCSR_REG_H_INCLUDED_
#define _OSDCSR_REG_H_INCLUDED_

//#define  _OSDCSR_USE_STRUCT
#ifdef _OSDCSR_USE_STRUCT

typedef struct
{
    unsigned int    reserved_0:6;
    unsigned int    curdou:1;
    unsigned int    cpe:1;
    unsigned int    asf:6;
    unsigned int    auto_sm:2;
    unsigned int    clkr:1;
    unsigned int    fh:1;
    unsigned int    fv:1;
    unsigned int    rfe:1;
    unsigned int    aci:2;
    unsigned int    cm:2;
    unsigned int    psi:2;
    unsigned int    reserved_1:4;
    unsigned int    ls:1;
    unsigned int    ce:1;
}OSD_curcfg;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    lt:3;
    unsigned int    reserved_1:1;
    unsigned int    ba:25;
    unsigned int    zero:2;
}OSD_curlar;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    xpos:11;
    unsigned int    reserved_1:5;
    unsigned int    ypos:11;
}OSD_curpos;

typedef struct
{
    unsigned int    y:8;
    unsigned int    cr:8;
    unsigned int    cb:8;
    unsigned int    reserved_0:6;
    unsigned int    al:2;
}OSD_curpal00;

typedef struct
{
    unsigned int    y:8;
    unsigned int    cr:8;
    unsigned int    cb:8;
    unsigned int    reserved_0:6;
    unsigned int    al:2;
}OSD_curpal01;

typedef struct
{
    unsigned int    y:8;
    unsigned int    cr:8;
    unsigned int    cb:8;
    unsigned int    reserved_0:6;
    unsigned int    al:2;
}OSD_curpal02;

typedef struct
{
    unsigned int    y:8;
    unsigned int    cr:8;
    unsigned int    cb:8;
    unsigned int    reserved_0:6;
    unsigned int    al:2;
}OSD_curpal03;

typedef struct
{
    unsigned int    y:8;
    unsigned int    cr:8;
    unsigned int    cb:8;
    unsigned int    reserved_0:6;
    unsigned int    al:2;
}OSD_curpal10;

typedef struct
{
    unsigned int    y:8;
    unsigned int    cr:8;
    unsigned int    cb:8;
    unsigned int    reserved_0:6;
    unsigned int    al:2;
}OSD_curpal11;

typedef struct
{
    unsigned int    y:8;
    unsigned int    cr:8;
    unsigned int    cb:8;
    unsigned int    reserved_0:6;
    unsigned int    al:2;
}OSD_curpal12;

typedef struct
{
    unsigned int    y:8;
    unsigned int    cr:8;
    unsigned int    cb:8;
    unsigned int    reserved_0:6;
    unsigned int    al:2;
}OSD_curpal13;

typedef struct
{
    unsigned int    y:8;
    unsigned int    cr:8;
    unsigned int    cb:8;
    unsigned int    reserved_0:6;
    unsigned int    al:2;
}OSD_curpal20;

typedef struct
{
    unsigned int    y:8;
    unsigned int    cr:8;
    unsigned int    cb:8;
    unsigned int    reserved_0:6;
    unsigned int    al:2;
}OSD_curpal21;

typedef struct
{
    unsigned int    y:8;
    unsigned int    cr:8;
    unsigned int    cb:8;
    unsigned int    reserved_0:6;
    unsigned int    al:2;
}OSD_curpal22;

typedef struct
{
    unsigned int    y:8;
    unsigned int    cr:8;
    unsigned int    cb:8;
    unsigned int    reserved_0:6;
    unsigned int    al:2;
}OSD_curpal23;

typedef struct
{
    unsigned int    y:8;
    unsigned int    cr:8;
    unsigned int    cb:8;
    unsigned int    reserved_0:6;
    unsigned int    al:2;
}OSD_curpal30;

typedef struct
{
    unsigned int    y:8;
    unsigned int    cr:8;
    unsigned int    cb:8;
    unsigned int    reserved_0:6;
    unsigned int    al:2;
}OSD_curpal31;

typedef struct
{
    unsigned int    y:8;
    unsigned int    cr:8;
    unsigned int    cb:8;
    unsigned int    reserved_0:6;
    unsigned int    al:2;
}OSD_curpal32;

typedef struct
{
    unsigned int    y:8;
    unsigned int    cr:8;
    unsigned int    cb:8;
    unsigned int    reserved_0:6;
    unsigned int    al:2;
}OSD_curpal33;

typedef struct
{
    unsigned int    rst:1;
    unsigned int    en:1;
    unsigned int    reserved_0:30;
}OSD_curbistcr;

typedef struct
{
    unsigned int    done:1;
    unsigned int    reserved_0:29;
    unsigned int    mbf1:1;
    unsigned int    mbf0:1;
}OSD_curbistsr;
#endif


#define OSD_CURCFG                                                    0x18048480
#define OSD_CURCFG_reg_addr                                           "0xB8048480"
#define OSD_CURCFG_reg                                                0xB8048480
#define OSD_CURCFG_inst_addr                                          "0x0120"
#define OSD_CURCFG_inst                                               0x0120
#define OSD_CURCFG_curdou_shift                                       (25)
#define OSD_CURCFG_cpe_shift                                          (24)
#define OSD_CURCFG_asf_shift                                          (18)
#define OSD_CURCFG_auto_sm_shift                                      (16)
#define OSD_CURCFG_clkr_shift                                         (15)
#define OSD_CURCFG_fh_shift                                           (14)
#define OSD_CURCFG_fv_shift                                           (13)
#define OSD_CURCFG_rfe_shift                                          (12)
#define OSD_CURCFG_aci_shift                                          (10)
#define OSD_CURCFG_cm_shift                                           (8)
#define OSD_CURCFG_psi_shift                                          (6)
#define OSD_CURCFG_ls_shift                                           (1)
#define OSD_CURCFG_ce_shift                                           (0)
#define OSD_CURCFG_curdou_mask                                        (0x02000000)
#define OSD_CURCFG_cpe_mask                                           (0x01000000)
#define OSD_CURCFG_asf_mask                                           (0x00FC0000)
#define OSD_CURCFG_auto_sm_mask                                       (0x00030000)
#define OSD_CURCFG_clkr_mask                                          (0x00008000)
#define OSD_CURCFG_fh_mask                                            (0x00004000)
#define OSD_CURCFG_fv_mask                                            (0x00002000)
#define OSD_CURCFG_rfe_mask                                           (0x00001000)
#define OSD_CURCFG_aci_mask                                           (0x00000C00)
#define OSD_CURCFG_cm_mask                                            (0x00000300)
#define OSD_CURCFG_psi_mask                                           (0x000000C0)
#define OSD_CURCFG_ls_mask                                            (0x00000002)
#define OSD_CURCFG_ce_mask                                            (0x00000001)
#define OSD_CURCFG_curdou(data)                                       (0x02000000&((data)<<25))
#define OSD_CURCFG_cpe(data)                                          (0x01000000&((data)<<24))
#define OSD_CURCFG_asf(data)                                          (0x00FC0000&((data)<<18))
#define OSD_CURCFG_auto_sm(data)                                      (0x00030000&((data)<<16))
#define OSD_CURCFG_clkr(data)                                         (0x00008000&((data)<<15))
#define OSD_CURCFG_fh(data)                                           (0x00004000&((data)<<14))
#define OSD_CURCFG_fv(data)                                           (0x00002000&((data)<<13))
#define OSD_CURCFG_rfe(data)                                          (0x00001000&((data)<<12))
#define OSD_CURCFG_aci(data)                                          (0x00000C00&((data)<<10))
#define OSD_CURCFG_cm(data)                                           (0x00000300&((data)<<8))
#define OSD_CURCFG_psi(data)                                          (0x000000C0&((data)<<6))
#define OSD_CURCFG_ls(data)                                           (0x00000002&((data)<<1))
#define OSD_CURCFG_ce(data)                                           (0x00000001&(data))
#define OSD_CURCFG_get_curdou(data)                                   ((0x02000000&(data))>>25)
#define OSD_CURCFG_get_cpe(data)                                      ((0x01000000&(data))>>24)
#define OSD_CURCFG_get_asf(data)                                      ((0x00FC0000&(data))>>18)
#define OSD_CURCFG_get_auto_sm(data)                                  ((0x00030000&(data))>>16)
#define OSD_CURCFG_get_clkr(data)                                     ((0x00008000&(data))>>15)
#define OSD_CURCFG_get_fh(data)                                       ((0x00004000&(data))>>14)
#define OSD_CURCFG_get_fv(data)                                       ((0x00002000&(data))>>13)
#define OSD_CURCFG_get_rfe(data)                                      ((0x00001000&(data))>>12)
#define OSD_CURCFG_get_aci(data)                                      ((0x00000C00&(data))>>10)
#define OSD_CURCFG_get_cm(data)                                       ((0x00000300&(data))>>8)
#define OSD_CURCFG_get_psi(data)                                      ((0x000000C0&(data))>>6)
#define OSD_CURCFG_get_ls(data)                                       ((0x00000002&(data))>>1)
#define OSD_CURCFG_get_ce(data)                                       (0x00000001&(data))


#define OSD_CURLAR                                                    0x18048484
#define OSD_CURLAR_reg_addr                                           "0xB8048484"
#define OSD_CURLAR_reg                                                0xB8048484
#define OSD_CURLAR_inst_addr                                          "0x0121"
#define OSD_CURLAR_inst                                               0x0121
#define OSD_CURLAR_lt_shift                                           (28)
#define OSD_CURLAR_ba_shift                                           (2)
#define OSD_CURLAR_zero_shift                                         (0)
#define OSD_CURLAR_lt_mask                                            (0x70000000)
#define OSD_CURLAR_ba_mask                                            (0x07FFFFFC)
#define OSD_CURLAR_zero_mask                                          (0x00000003)
#define OSD_CURLAR_lt(data)                                           (0x70000000&((data)<<28))
#define OSD_CURLAR_ba(data)                                           (0x07FFFFFC&((data)<<2))
#define OSD_CURLAR_zero(data)                                         (0x00000003&(data))
#define OSD_CURLAR_get_lt(data)                                       ((0x70000000&(data))>>28)
#define OSD_CURLAR_get_ba(data)                                       ((0x07FFFFFC&(data))>>2)
#define OSD_CURLAR_get_zero(data)                                     (0x00000003&(data))


#define OSD_CURPOS                                                    0x18048488
#define OSD_CURPOS_reg_addr                                           "0xB8048488"
#define OSD_CURPOS_reg                                                0xB8048488
#define OSD_CURPOS_inst_addr                                          "0x0122"
#define OSD_CURPOS_inst                                               0x0122
#define OSD_CURPOS_xpos_shift                                         (16)
#define OSD_CURPOS_ypos_shift                                         (0)
#define OSD_CURPOS_xpos_mask                                          (0x07FF0000)
#define OSD_CURPOS_ypos_mask                                          (0x000007FF)
#define OSD_CURPOS_xpos(data)                                         (0x07FF0000&((data)<<16))
#define OSD_CURPOS_ypos(data)                                         (0x000007FF&(data))
#define OSD_CURPOS_get_xpos(data)                                     ((0x07FF0000&(data))>>16)
#define OSD_CURPOS_get_ypos(data)                                     (0x000007FF&(data))


#define OSD_CURPAL00                                                  0x18048490
#define OSD_CURPAL00_reg_addr                                         "0xB8048490"
#define OSD_CURPAL00_reg                                              0xB8048490
#define OSD_CURPAL00_inst_addr                                        "0x0124"
#define OSD_CURPAL00_inst                                             0x0124
#define OSD_CURPAL00_y_shift                                          (24)
#define OSD_CURPAL00_cr_shift                                         (16)
#define OSD_CURPAL00_cb_shift                                         (8)
#define OSD_CURPAL00_al_shift                                         (0)
#define OSD_CURPAL00_y_mask                                           (0xFF000000)
#define OSD_CURPAL00_cr_mask                                          (0x00FF0000)
#define OSD_CURPAL00_cb_mask                                          (0x0000FF00)
#define OSD_CURPAL00_al_mask                                          (0x00000003)
#define OSD_CURPAL00_y(data)                                          (0xFF000000&((data)<<24))
#define OSD_CURPAL00_cr(data)                                         (0x00FF0000&((data)<<16))
#define OSD_CURPAL00_cb(data)                                         (0x0000FF00&((data)<<8))
#define OSD_CURPAL00_al(data)                                         (0x00000003&(data))
#define OSD_CURPAL00_get_y(data)                                      ((0xFF000000&(data))>>24)
#define OSD_CURPAL00_get_cr(data)                                     ((0x00FF0000&(data))>>16)
#define OSD_CURPAL00_get_cb(data)                                     ((0x0000FF00&(data))>>8)
#define OSD_CURPAL00_get_al(data)                                     (0x00000003&(data))


#define OSD_CURPAL01                                                  0x18048494
#define OSD_CURPAL01_reg_addr                                         "0xB8048494"
#define OSD_CURPAL01_reg                                              0xB8048494
#define OSD_CURPAL01_inst_addr                                        "0x0125"
#define OSD_CURPAL01_inst                                             0x0125
#define OSD_CURPAL01_y_shift                                          (24)
#define OSD_CURPAL01_cr_shift                                         (16)
#define OSD_CURPAL01_cb_shift                                         (8)
#define OSD_CURPAL01_al_shift                                         (0)
#define OSD_CURPAL01_y_mask                                           (0xFF000000)
#define OSD_CURPAL01_cr_mask                                          (0x00FF0000)
#define OSD_CURPAL01_cb_mask                                          (0x0000FF00)
#define OSD_CURPAL01_al_mask                                          (0x00000003)
#define OSD_CURPAL01_y(data)                                          (0xFF000000&((data)<<24))
#define OSD_CURPAL01_cr(data)                                         (0x00FF0000&((data)<<16))
#define OSD_CURPAL01_cb(data)                                         (0x0000FF00&((data)<<8))
#define OSD_CURPAL01_al(data)                                         (0x00000003&(data))
#define OSD_CURPAL01_get_y(data)                                      ((0xFF000000&(data))>>24)
#define OSD_CURPAL01_get_cr(data)                                     ((0x00FF0000&(data))>>16)
#define OSD_CURPAL01_get_cb(data)                                     ((0x0000FF00&(data))>>8)
#define OSD_CURPAL01_get_al(data)                                     (0x00000003&(data))


#define OSD_CURPAL02                                                  0x18048498
#define OSD_CURPAL02_reg_addr                                         "0xB8048498"
#define OSD_CURPAL02_reg                                              0xB8048498
#define OSD_CURPAL02_inst_addr                                        "0x0126"
#define OSD_CURPAL02_inst                                             0x0126
#define OSD_CURPAL02_y_shift                                          (24)
#define OSD_CURPAL02_cr_shift                                         (16)
#define OSD_CURPAL02_cb_shift                                         (8)
#define OSD_CURPAL02_al_shift                                         (0)
#define OSD_CURPAL02_y_mask                                           (0xFF000000)
#define OSD_CURPAL02_cr_mask                                          (0x00FF0000)
#define OSD_CURPAL02_cb_mask                                          (0x0000FF00)
#define OSD_CURPAL02_al_mask                                          (0x00000003)
#define OSD_CURPAL02_y(data)                                          (0xFF000000&((data)<<24))
#define OSD_CURPAL02_cr(data)                                         (0x00FF0000&((data)<<16))
#define OSD_CURPAL02_cb(data)                                         (0x0000FF00&((data)<<8))
#define OSD_CURPAL02_al(data)                                         (0x00000003&(data))
#define OSD_CURPAL02_get_y(data)                                      ((0xFF000000&(data))>>24)
#define OSD_CURPAL02_get_cr(data)                                     ((0x00FF0000&(data))>>16)
#define OSD_CURPAL02_get_cb(data)                                     ((0x0000FF00&(data))>>8)
#define OSD_CURPAL02_get_al(data)                                     (0x00000003&(data))


#define OSD_CURPAL03                                                  0x1804849c
#define OSD_CURPAL03_reg_addr                                         "0xB804849C"
#define OSD_CURPAL03_reg                                              0xB804849C
#define OSD_CURPAL03_inst_addr                                        "0x0127"
#define OSD_CURPAL03_inst                                             0x0127
#define OSD_CURPAL03_y_shift                                          (24)
#define OSD_CURPAL03_cr_shift                                         (16)
#define OSD_CURPAL03_cb_shift                                         (8)
#define OSD_CURPAL03_al_shift                                         (0)
#define OSD_CURPAL03_y_mask                                           (0xFF000000)
#define OSD_CURPAL03_cr_mask                                          (0x00FF0000)
#define OSD_CURPAL03_cb_mask                                          (0x0000FF00)
#define OSD_CURPAL03_al_mask                                          (0x00000003)
#define OSD_CURPAL03_y(data)                                          (0xFF000000&((data)<<24))
#define OSD_CURPAL03_cr(data)                                         (0x00FF0000&((data)<<16))
#define OSD_CURPAL03_cb(data)                                         (0x0000FF00&((data)<<8))
#define OSD_CURPAL03_al(data)                                         (0x00000003&(data))
#define OSD_CURPAL03_get_y(data)                                      ((0xFF000000&(data))>>24)
#define OSD_CURPAL03_get_cr(data)                                     ((0x00FF0000&(data))>>16)
#define OSD_CURPAL03_get_cb(data)                                     ((0x0000FF00&(data))>>8)
#define OSD_CURPAL03_get_al(data)                                     (0x00000003&(data))


#define OSD_CURPAL10                                                  0x180484a0
#define OSD_CURPAL10_reg_addr                                         "0xB80484A0"
#define OSD_CURPAL10_reg                                              0xB80484A0
#define OSD_CURPAL10_inst_addr                                        "0x0128"
#define OSD_CURPAL10_inst                                             0x0128
#define OSD_CURPAL10_y_shift                                          (24)
#define OSD_CURPAL10_cr_shift                                         (16)
#define OSD_CURPAL10_cb_shift                                         (8)
#define OSD_CURPAL10_al_shift                                         (0)
#define OSD_CURPAL10_y_mask                                           (0xFF000000)
#define OSD_CURPAL10_cr_mask                                          (0x00FF0000)
#define OSD_CURPAL10_cb_mask                                          (0x0000FF00)
#define OSD_CURPAL10_al_mask                                          (0x00000003)
#define OSD_CURPAL10_y(data)                                          (0xFF000000&((data)<<24))
#define OSD_CURPAL10_cr(data)                                         (0x00FF0000&((data)<<16))
#define OSD_CURPAL10_cb(data)                                         (0x0000FF00&((data)<<8))
#define OSD_CURPAL10_al(data)                                         (0x00000003&(data))
#define OSD_CURPAL10_get_y(data)                                      ((0xFF000000&(data))>>24)
#define OSD_CURPAL10_get_cr(data)                                     ((0x00FF0000&(data))>>16)
#define OSD_CURPAL10_get_cb(data)                                     ((0x0000FF00&(data))>>8)
#define OSD_CURPAL10_get_al(data)                                     (0x00000003&(data))


#define OSD_CURPAL11                                                  0x180484a4
#define OSD_CURPAL11_reg_addr                                         "0xB80484A4"
#define OSD_CURPAL11_reg                                              0xB80484A4
#define OSD_CURPAL11_inst_addr                                        "0x0129"
#define OSD_CURPAL11_inst                                             0x0129
#define OSD_CURPAL11_y_shift                                          (24)
#define OSD_CURPAL11_cr_shift                                         (16)
#define OSD_CURPAL11_cb_shift                                         (8)
#define OSD_CURPAL11_al_shift                                         (0)
#define OSD_CURPAL11_y_mask                                           (0xFF000000)
#define OSD_CURPAL11_cr_mask                                          (0x00FF0000)
#define OSD_CURPAL11_cb_mask                                          (0x0000FF00)
#define OSD_CURPAL11_al_mask                                          (0x00000003)
#define OSD_CURPAL11_y(data)                                          (0xFF000000&((data)<<24))
#define OSD_CURPAL11_cr(data)                                         (0x00FF0000&((data)<<16))
#define OSD_CURPAL11_cb(data)                                         (0x0000FF00&((data)<<8))
#define OSD_CURPAL11_al(data)                                         (0x00000003&(data))
#define OSD_CURPAL11_get_y(data)                                      ((0xFF000000&(data))>>24)
#define OSD_CURPAL11_get_cr(data)                                     ((0x00FF0000&(data))>>16)
#define OSD_CURPAL11_get_cb(data)                                     ((0x0000FF00&(data))>>8)
#define OSD_CURPAL11_get_al(data)                                     (0x00000003&(data))


#define OSD_CURPAL12                                                  0x180484a8
#define OSD_CURPAL12_reg_addr                                         "0xB80484A8"
#define OSD_CURPAL12_reg                                              0xB80484A8
#define OSD_CURPAL12_inst_addr                                        "0x012A"
#define OSD_CURPAL12_inst                                             0x012A
#define OSD_CURPAL12_y_shift                                          (24)
#define OSD_CURPAL12_cr_shift                                         (16)
#define OSD_CURPAL12_cb_shift                                         (8)
#define OSD_CURPAL12_al_shift                                         (0)
#define OSD_CURPAL12_y_mask                                           (0xFF000000)
#define OSD_CURPAL12_cr_mask                                          (0x00FF0000)
#define OSD_CURPAL12_cb_mask                                          (0x0000FF00)
#define OSD_CURPAL12_al_mask                                          (0x00000003)
#define OSD_CURPAL12_y(data)                                          (0xFF000000&((data)<<24))
#define OSD_CURPAL12_cr(data)                                         (0x00FF0000&((data)<<16))
#define OSD_CURPAL12_cb(data)                                         (0x0000FF00&((data)<<8))
#define OSD_CURPAL12_al(data)                                         (0x00000003&(data))
#define OSD_CURPAL12_get_y(data)                                      ((0xFF000000&(data))>>24)
#define OSD_CURPAL12_get_cr(data)                                     ((0x00FF0000&(data))>>16)
#define OSD_CURPAL12_get_cb(data)                                     ((0x0000FF00&(data))>>8)
#define OSD_CURPAL12_get_al(data)                                     (0x00000003&(data))


#define OSD_CURPAL13                                                  0x180484ac
#define OSD_CURPAL13_reg_addr                                         "0xB80484AC"
#define OSD_CURPAL13_reg                                              0xB80484AC
#define OSD_CURPAL13_inst_addr                                        "0x012B"
#define OSD_CURPAL13_inst                                             0x012B
#define OSD_CURPAL13_y_shift                                          (24)
#define OSD_CURPAL13_cr_shift                                         (16)
#define OSD_CURPAL13_cb_shift                                         (8)
#define OSD_CURPAL13_al_shift                                         (0)
#define OSD_CURPAL13_y_mask                                           (0xFF000000)
#define OSD_CURPAL13_cr_mask                                          (0x00FF0000)
#define OSD_CURPAL13_cb_mask                                          (0x0000FF00)
#define OSD_CURPAL13_al_mask                                          (0x00000003)
#define OSD_CURPAL13_y(data)                                          (0xFF000000&((data)<<24))
#define OSD_CURPAL13_cr(data)                                         (0x00FF0000&((data)<<16))
#define OSD_CURPAL13_cb(data)                                         (0x0000FF00&((data)<<8))
#define OSD_CURPAL13_al(data)                                         (0x00000003&(data))
#define OSD_CURPAL13_get_y(data)                                      ((0xFF000000&(data))>>24)
#define OSD_CURPAL13_get_cr(data)                                     ((0x00FF0000&(data))>>16)
#define OSD_CURPAL13_get_cb(data)                                     ((0x0000FF00&(data))>>8)
#define OSD_CURPAL13_get_al(data)                                     (0x00000003&(data))


#define OSD_CURPAL20                                                  0x180484b0
#define OSD_CURPAL20_reg_addr                                         "0xB80484B0"
#define OSD_CURPAL20_reg                                              0xB80484B0
#define OSD_CURPAL20_inst_addr                                        "0x012C"
#define OSD_CURPAL20_inst                                             0x012C
#define OSD_CURPAL20_y_shift                                          (24)
#define OSD_CURPAL20_cr_shift                                         (16)
#define OSD_CURPAL20_cb_shift                                         (8)
#define OSD_CURPAL20_al_shift                                         (0)
#define OSD_CURPAL20_y_mask                                           (0xFF000000)
#define OSD_CURPAL20_cr_mask                                          (0x00FF0000)
#define OSD_CURPAL20_cb_mask                                          (0x0000FF00)
#define OSD_CURPAL20_al_mask                                          (0x00000003)
#define OSD_CURPAL20_y(data)                                          (0xFF000000&((data)<<24))
#define OSD_CURPAL20_cr(data)                                         (0x00FF0000&((data)<<16))
#define OSD_CURPAL20_cb(data)                                         (0x0000FF00&((data)<<8))
#define OSD_CURPAL20_al(data)                                         (0x00000003&(data))
#define OSD_CURPAL20_get_y(data)                                      ((0xFF000000&(data))>>24)
#define OSD_CURPAL20_get_cr(data)                                     ((0x00FF0000&(data))>>16)
#define OSD_CURPAL20_get_cb(data)                                     ((0x0000FF00&(data))>>8)
#define OSD_CURPAL20_get_al(data)                                     (0x00000003&(data))


#define OSD_CURPAL21                                                  0x180484b4
#define OSD_CURPAL21_reg_addr                                         "0xB80484B4"
#define OSD_CURPAL21_reg                                              0xB80484B4
#define OSD_CURPAL21_inst_addr                                        "0x012D"
#define OSD_CURPAL21_inst                                             0x012D
#define OSD_CURPAL21_y_shift                                          (24)
#define OSD_CURPAL21_cr_shift                                         (16)
#define OSD_CURPAL21_cb_shift                                         (8)
#define OSD_CURPAL21_al_shift                                         (0)
#define OSD_CURPAL21_y_mask                                           (0xFF000000)
#define OSD_CURPAL21_cr_mask                                          (0x00FF0000)
#define OSD_CURPAL21_cb_mask                                          (0x0000FF00)
#define OSD_CURPAL21_al_mask                                          (0x00000003)
#define OSD_CURPAL21_y(data)                                          (0xFF000000&((data)<<24))
#define OSD_CURPAL21_cr(data)                                         (0x00FF0000&((data)<<16))
#define OSD_CURPAL21_cb(data)                                         (0x0000FF00&((data)<<8))
#define OSD_CURPAL21_al(data)                                         (0x00000003&(data))
#define OSD_CURPAL21_get_y(data)                                      ((0xFF000000&(data))>>24)
#define OSD_CURPAL21_get_cr(data)                                     ((0x00FF0000&(data))>>16)
#define OSD_CURPAL21_get_cb(data)                                     ((0x0000FF00&(data))>>8)
#define OSD_CURPAL21_get_al(data)                                     (0x00000003&(data))


#define OSD_CURPAL22                                                  0x180484b8
#define OSD_CURPAL22_reg_addr                                         "0xB80484B8"
#define OSD_CURPAL22_reg                                              0xB80484B8
#define OSD_CURPAL22_inst_addr                                        "0x012E"
#define OSD_CURPAL22_inst                                             0x012E
#define OSD_CURPAL22_y_shift                                          (24)
#define OSD_CURPAL22_cr_shift                                         (16)
#define OSD_CURPAL22_cb_shift                                         (8)
#define OSD_CURPAL22_al_shift                                         (0)
#define OSD_CURPAL22_y_mask                                           (0xFF000000)
#define OSD_CURPAL22_cr_mask                                          (0x00FF0000)
#define OSD_CURPAL22_cb_mask                                          (0x0000FF00)
#define OSD_CURPAL22_al_mask                                          (0x00000003)
#define OSD_CURPAL22_y(data)                                          (0xFF000000&((data)<<24))
#define OSD_CURPAL22_cr(data)                                         (0x00FF0000&((data)<<16))
#define OSD_CURPAL22_cb(data)                                         (0x0000FF00&((data)<<8))
#define OSD_CURPAL22_al(data)                                         (0x00000003&(data))
#define OSD_CURPAL22_get_y(data)                                      ((0xFF000000&(data))>>24)
#define OSD_CURPAL22_get_cr(data)                                     ((0x00FF0000&(data))>>16)
#define OSD_CURPAL22_get_cb(data)                                     ((0x0000FF00&(data))>>8)
#define OSD_CURPAL22_get_al(data)                                     (0x00000003&(data))


#define OSD_CURPAL23                                                  0x180484bc
#define OSD_CURPAL23_reg_addr                                         "0xB80484BC"
#define OSD_CURPAL23_reg                                              0xB80484BC
#define OSD_CURPAL23_inst_addr                                        "0x012F"
#define OSD_CURPAL23_inst                                             0x012F
#define OSD_CURPAL23_y_shift                                          (24)
#define OSD_CURPAL23_cr_shift                                         (16)
#define OSD_CURPAL23_cb_shift                                         (8)
#define OSD_CURPAL23_al_shift                                         (0)
#define OSD_CURPAL23_y_mask                                           (0xFF000000)
#define OSD_CURPAL23_cr_mask                                          (0x00FF0000)
#define OSD_CURPAL23_cb_mask                                          (0x0000FF00)
#define OSD_CURPAL23_al_mask                                          (0x00000003)
#define OSD_CURPAL23_y(data)                                          (0xFF000000&((data)<<24))
#define OSD_CURPAL23_cr(data)                                         (0x00FF0000&((data)<<16))
#define OSD_CURPAL23_cb(data)                                         (0x0000FF00&((data)<<8))
#define OSD_CURPAL23_al(data)                                         (0x00000003&(data))
#define OSD_CURPAL23_get_y(data)                                      ((0xFF000000&(data))>>24)
#define OSD_CURPAL23_get_cr(data)                                     ((0x00FF0000&(data))>>16)
#define OSD_CURPAL23_get_cb(data)                                     ((0x0000FF00&(data))>>8)
#define OSD_CURPAL23_get_al(data)                                     (0x00000003&(data))


#define OSD_CURPAL30                                                  0x180484c0
#define OSD_CURPAL30_reg_addr                                         "0xB80484C0"
#define OSD_CURPAL30_reg                                              0xB80484C0
#define OSD_CURPAL30_inst_addr                                        "0x0130"
#define OSD_CURPAL30_inst                                             0x0130
#define OSD_CURPAL30_y_shift                                          (24)
#define OSD_CURPAL30_cr_shift                                         (16)
#define OSD_CURPAL30_cb_shift                                         (8)
#define OSD_CURPAL30_al_shift                                         (0)
#define OSD_CURPAL30_y_mask                                           (0xFF000000)
#define OSD_CURPAL30_cr_mask                                          (0x00FF0000)
#define OSD_CURPAL30_cb_mask                                          (0x0000FF00)
#define OSD_CURPAL30_al_mask                                          (0x00000003)
#define OSD_CURPAL30_y(data)                                          (0xFF000000&((data)<<24))
#define OSD_CURPAL30_cr(data)                                         (0x00FF0000&((data)<<16))
#define OSD_CURPAL30_cb(data)                                         (0x0000FF00&((data)<<8))
#define OSD_CURPAL30_al(data)                                         (0x00000003&(data))
#define OSD_CURPAL30_get_y(data)                                      ((0xFF000000&(data))>>24)
#define OSD_CURPAL30_get_cr(data)                                     ((0x00FF0000&(data))>>16)
#define OSD_CURPAL30_get_cb(data)                                     ((0x0000FF00&(data))>>8)
#define OSD_CURPAL30_get_al(data)                                     (0x00000003&(data))


#define OSD_CURPAL31                                                  0x180484c4
#define OSD_CURPAL31_reg_addr                                         "0xB80484C4"
#define OSD_CURPAL31_reg                                              0xB80484C4
#define OSD_CURPAL31_inst_addr                                        "0x0131"
#define OSD_CURPAL31_inst                                             0x0131
#define OSD_CURPAL31_y_shift                                          (24)
#define OSD_CURPAL31_cr_shift                                         (16)
#define OSD_CURPAL31_cb_shift                                         (8)
#define OSD_CURPAL31_al_shift                                         (0)
#define OSD_CURPAL31_y_mask                                           (0xFF000000)
#define OSD_CURPAL31_cr_mask                                          (0x00FF0000)
#define OSD_CURPAL31_cb_mask                                          (0x0000FF00)
#define OSD_CURPAL31_al_mask                                          (0x00000003)
#define OSD_CURPAL31_y(data)                                          (0xFF000000&((data)<<24))
#define OSD_CURPAL31_cr(data)                                         (0x00FF0000&((data)<<16))
#define OSD_CURPAL31_cb(data)                                         (0x0000FF00&((data)<<8))
#define OSD_CURPAL31_al(data)                                         (0x00000003&(data))
#define OSD_CURPAL31_get_y(data)                                      ((0xFF000000&(data))>>24)
#define OSD_CURPAL31_get_cr(data)                                     ((0x00FF0000&(data))>>16)
#define OSD_CURPAL31_get_cb(data)                                     ((0x0000FF00&(data))>>8)
#define OSD_CURPAL31_get_al(data)                                     (0x00000003&(data))


#define OSD_CURPAL32                                                  0x180484c8
#define OSD_CURPAL32_reg_addr                                         "0xB80484C8"
#define OSD_CURPAL32_reg                                              0xB80484C8
#define OSD_CURPAL32_inst_addr                                        "0x0132"
#define OSD_CURPAL32_inst                                             0x0132
#define OSD_CURPAL32_y_shift                                          (24)
#define OSD_CURPAL32_cr_shift                                         (16)
#define OSD_CURPAL32_cb_shift                                         (8)
#define OSD_CURPAL32_al_shift                                         (0)
#define OSD_CURPAL32_y_mask                                           (0xFF000000)
#define OSD_CURPAL32_cr_mask                                          (0x00FF0000)
#define OSD_CURPAL32_cb_mask                                          (0x0000FF00)
#define OSD_CURPAL32_al_mask                                          (0x00000003)
#define OSD_CURPAL32_y(data)                                          (0xFF000000&((data)<<24))
#define OSD_CURPAL32_cr(data)                                         (0x00FF0000&((data)<<16))
#define OSD_CURPAL32_cb(data)                                         (0x0000FF00&((data)<<8))
#define OSD_CURPAL32_al(data)                                         (0x00000003&(data))
#define OSD_CURPAL32_get_y(data)                                      ((0xFF000000&(data))>>24)
#define OSD_CURPAL32_get_cr(data)                                     ((0x00FF0000&(data))>>16)
#define OSD_CURPAL32_get_cb(data)                                     ((0x0000FF00&(data))>>8)
#define OSD_CURPAL32_get_al(data)                                     (0x00000003&(data))


#define OSD_CURPAL33                                                  0x180484cc
#define OSD_CURPAL33_reg_addr                                         "0xB80484CC"
#define OSD_CURPAL33_reg                                              0xB80484CC
#define OSD_CURPAL33_inst_addr                                        "0x0133"
#define OSD_CURPAL33_inst                                             0x0133
#define OSD_CURPAL33_y_shift                                          (24)
#define OSD_CURPAL33_cr_shift                                         (16)
#define OSD_CURPAL33_cb_shift                                         (8)
#define OSD_CURPAL33_al_shift                                         (0)
#define OSD_CURPAL33_y_mask                                           (0xFF000000)
#define OSD_CURPAL33_cr_mask                                          (0x00FF0000)
#define OSD_CURPAL33_cb_mask                                          (0x0000FF00)
#define OSD_CURPAL33_al_mask                                          (0x00000003)
#define OSD_CURPAL33_y(data)                                          (0xFF000000&((data)<<24))
#define OSD_CURPAL33_cr(data)                                         (0x00FF0000&((data)<<16))
#define OSD_CURPAL33_cb(data)                                         (0x0000FF00&((data)<<8))
#define OSD_CURPAL33_al(data)                                         (0x00000003&(data))
#define OSD_CURPAL33_get_y(data)                                      ((0xFF000000&(data))>>24)
#define OSD_CURPAL33_get_cr(data)                                     ((0x00FF0000&(data))>>16)
#define OSD_CURPAL33_get_cb(data)                                     ((0x0000FF00&(data))>>8)
#define OSD_CURPAL33_get_al(data)                                     (0x00000003&(data))


#define OSD_CURBISTCR                                                 0x180484d0
#define OSD_CURBISTCR_reg_addr                                        "0xB80484D0"
#define OSD_CURBISTCR_reg                                             0xB80484D0
#define OSD_CURBISTCR_inst_addr                                       "0x0134"
#define OSD_CURBISTCR_inst                                            0x0134
#define OSD_CURBISTCR_rst_shift                                       (31)
#define OSD_CURBISTCR_en_shift                                        (30)
#define OSD_CURBISTCR_rst_mask                                        (0x80000000)
#define OSD_CURBISTCR_en_mask                                         (0x40000000)
#define OSD_CURBISTCR_rst(data)                                       (0x80000000&((data)<<31))
#define OSD_CURBISTCR_en(data)                                        (0x40000000&((data)<<30))
#define OSD_CURBISTCR_get_rst(data)                                   ((0x80000000&(data))>>31)
#define OSD_CURBISTCR_get_en(data)                                    ((0x40000000&(data))>>30)


#define OSD_CURBISTSR                                                 0x180484d4
#define OSD_CURBISTSR_reg_addr                                        "0xB80484D4"
#define OSD_CURBISTSR_reg                                             0xB80484D4
#define OSD_CURBISTSR_inst_addr                                       "0x0135"
#define OSD_CURBISTSR_inst                                            0x0135
#define OSD_CURBISTSR_done_shift                                      (31)
#define OSD_CURBISTSR_mbf1_shift                                      (1)
#define OSD_CURBISTSR_mbf0_shift                                      (0)
#define OSD_CURBISTSR_done_mask                                       (0x80000000)
#define OSD_CURBISTSR_mbf1_mask                                       (0x00000002)
#define OSD_CURBISTSR_mbf0_mask                                       (0x00000001)
#define OSD_CURBISTSR_done(data)                                      (0x80000000&((data)<<31))
#define OSD_CURBISTSR_mbf1(data)                                      (0x00000002&((data)<<1))
#define OSD_CURBISTSR_mbf0(data)                                      (0x00000001&(data))
#define OSD_CURBISTSR_get_done(data)                                  ((0x80000000&(data))>>31)
#define OSD_CURBISTSR_get_mbf1(data)                                  ((0x00000002&(data))>>1)
#define OSD_CURBISTSR_get_mbf0(data)                                  (0x00000001&(data))
#endif
