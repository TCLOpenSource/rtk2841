// This file is generated using the spec version 1.39, firmware template version 1.39and SRIF Parser                                                                                source code SVN rev:730                    Version flow no.:1.0.180
#ifndef _BRIDGE_REG_H_INCLUDED_
#define _BRIDGE_REG_H_INCLUDED_

//#define  _BRIDGE_USE_STRUCT
#ifdef _BRIDGE_USE_STRUCT

typedef struct
{
    unsigned int    dec_mode:1;
    unsigned int    reserved_0:12;
    unsigned int    cnt_src_sel:3;
    unsigned int    time_step:4;
    unsigned int    reserved_1:9;
    unsigned int    arb_en:3;
}SB0_arb_cr;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    vdec_latcnt_end:12;
    unsigned int    reserved_1:4;
    unsigned int    vdec_latcnt_beg:12;
}SB0_latcnt_cr1;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    vbi_latcnt_end:12;
    unsigned int    reserved_1:4;
    unsigned int    vbi_latcnt_beg:12;
}SB0_latcnt_cr2;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    vi_latcnt_end:12;
    unsigned int    reserved_1:4;
    unsigned int    vi_latcnt_beg:12;
}SB0_latcnt_cr3;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    vdec_credit_val:12;
    unsigned int    vdec_deficit_val:8;
    unsigned int    vdec_elapse_val:8;
}SB0_wdrr_cr1;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    vbi_credit_val:12;
    unsigned int    vbi_deficit_val:8;
    unsigned int    vbi_elapse_val:8;
}SB0_wdrr_cr2;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    vi_credit_val:12;
    unsigned int    vi_deficit_val:8;
    unsigned int    vi_elapse_val:8;
}SB0_wdrr_cr3;

typedef struct
{
    unsigned int    vdec_cntr_val_set:1;
    unsigned int    reserved_0:3;
    unsigned int    vdec_cntr_val:12;
    unsigned int    reserved_1:4;
    unsigned int    vdec_low_lvl_val:12;
}SB0_arb_cntr_set1;

typedef struct
{
    unsigned int    vbi_cntr_val_set:1;
    unsigned int    reserved_0:3;
    unsigned int    vbi_cntr_val:12;
    unsigned int    reserved_1:4;
    unsigned int    vbi_low_lvl_val:12;
}SB0_arb_cntr_set2;

typedef struct
{
    unsigned int    vi_cntr_val_set:1;
    unsigned int    reserved_0:3;
    unsigned int    vi_cntr_val:12;
    unsigned int    reserved_1:4;
    unsigned int    vi_low_lvl_val:12;
}SB0_arb_cntr_set3;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    max_count:4;
    unsigned int    reserved_1:8;
    unsigned int    off_time:8;
}SB0_req_cr;

typedef struct
{
    unsigned int    reserved_0:13;
    unsigned int    sb_gnt:3;
    unsigned int    reserved_1:4;
    unsigned int    win_latcnt:12;
}SB0_arb_sr1;

typedef struct
{
    unsigned int    reserved_0:13;
    unsigned int    low_lvl_ie:3;
    unsigned int    reserved_1:13;
    unsigned int    low_lvl_ip:3;
}SB0_arb_sr2;

typedef struct
{
    unsigned int    dec_mode:1;
    unsigned int    reserved_0:6;
    unsigned int    cnt_src_sel:9;
    unsigned int    time_step:4;
    unsigned int    reserved_1:2;
    unsigned int    arb_en:10;
}SB3_arb_cr;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    xcdim_latcnt_end:12;
    unsigned int    reserved_1:4;
    unsigned int    xcdim_latcnt_beg:12;
}SB3_latcnt_cr1;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    gdmaosd_latcnt_end:12;
    unsigned int    reserved_1:4;
    unsigned int    gdmaosd_latcnt_beg:12;
}SB3_latcnt_cr2;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    disdisps_latcnt_end:12;
    unsigned int    reserved_1:4;
    unsigned int    disdisps_latcnt_beg:12;
}SB3_latcnt_cr3;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    discaps_latcnt_end:12;
    unsigned int    reserved_1:4;
    unsigned int    discaps_latcnt_beg:12;
}SB3_latcnt_cr4;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    vo_latcnt_end:12;
    unsigned int    reserved_1:4;
    unsigned int    vo_latcnt_beg:12;
}SB3_latcnt_cr5;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    gdmasub1_latcnt_end:12;
    unsigned int    reserved_1:4;
    unsigned int    gdmasub1_latcnt_beg:12;
}SB3_latcnt_cr6;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    gibi_latcnt_end:12;
    unsigned int    reserved_1:4;
    unsigned int    gibi_latcnt_beg:12;
}SB3_latcnt_cr7;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    memc_latcnt_end:12;
    unsigned int    reserved_1:4;
    unsigned int    memc_latcnt_beg:12;
}SB3_latcnt_cr8;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    gdmasub2_latcnt_end:12;
    unsigned int    reserved_1:4;
    unsigned int    gdmasub2_latcnt_beg:12;
}SB3_latcnt_cr9;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    xcdim_credit_val:12;
    unsigned int    xcdim_deficit_val:8;
    unsigned int    xcdim_elapse_val:8;
}SB3_wdrr_cr1;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    gdmaosd_credit_val:12;
    unsigned int    gdmaosd_deficit_val:8;
    unsigned int    gdmaosd_elapse_val:8;
}SB3_wdrr_cr2;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    disdisps_credit_val:12;
    unsigned int    disdisps_deficit_val:8;
    unsigned int    disdisps_elapse_val:8;
}SB3_wdrr_cr3;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    discaps_credit_val:12;
    unsigned int    discaps_deficit_val:8;
    unsigned int    discaps_elapse_val:8;
}SB3_wdrr_cr4;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    vo_credit_val:12;
    unsigned int    vo_deficit_val:8;
    unsigned int    vo_elapse_val:8;
}SB3_wdrr_cr5;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    gdmasub1_credit_val:12;
    unsigned int    gdmasub1_deficit_val:8;
    unsigned int    gdmasub1_elapse_val:8;
}SB3_wdrr_cr6;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    gibi_credit_val:12;
    unsigned int    gibi_deficit_val:8;
    unsigned int    gibi_elapse_val:8;
}SB3_wdrr_cr7;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    memc_credit_val:12;
    unsigned int    memc_deficit_val:8;
    unsigned int    memc_elapse_val:8;
}SB3_wdrr_cr8;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    gdmasub2_credit_val:12;
    unsigned int    gdmasub2_deficit_val:8;
    unsigned int    gdmasub2_elapse_val:8;
}SB3_wdrr_cr9;

typedef struct
{
    unsigned int    xcdim_cntr_val_set:1;
    unsigned int    reserved_0:3;
    unsigned int    xcdim_cntr_val:12;
    unsigned int    reserved_1:4;
    unsigned int    xcdim_low_lvl_val:12;
}SB3_arb_cntr_set1;

typedef struct
{
    unsigned int    gdmaosd_cntr_val_set:1;
    unsigned int    reserved_0:3;
    unsigned int    gdmaosd_cntr_val:12;
    unsigned int    reserved_1:4;
    unsigned int    gdmaosd_low_lvl_val:12;
}SB3_arb_cntr_set2;

typedef struct
{
    unsigned int    disdisps_cntr_val_set:1;
    unsigned int    reserved_0:3;
    unsigned int    disdisps_cntr_val:12;
    unsigned int    reserved_1:4;
    unsigned int    disdisps_low_lvl_val:12;
}SB3_arb_cntr_set3;

typedef struct
{
    unsigned int    discaps_cntr_val_set:1;
    unsigned int    reserved_0:3;
    unsigned int    discaps_cntr_val:12;
    unsigned int    reserved_1:4;
    unsigned int    discaps_low_lvl_val:12;
}SB3_arb_cntr_set4;

typedef struct
{
    unsigned int    vo_cntr_val_set:1;
    unsigned int    reserved_0:3;
    unsigned int    vo_cntr_val:12;
    unsigned int    reserved_1:4;
    unsigned int    vo_low_lvl_val:12;
}SB3_arb_cntr_set5;

typedef struct
{
    unsigned int    gdmasub1_cntr_val_set:1;
    unsigned int    reserved_0:3;
    unsigned int    gdmasub1_cntr_val:12;
    unsigned int    reserved_1:4;
    unsigned int    gdmasub1_low_lvl_val:12;
}SB3_arb_cntr_set6;

typedef struct
{
    unsigned int    gibi_cntr_val_set:1;
    unsigned int    reserved_0:3;
    unsigned int    gibi_cntr_val:12;
    unsigned int    reserved_1:4;
    unsigned int    gibi_low_lvl_val:12;
}SB3_arb_cntr_set7;

typedef struct
{
    unsigned int    memc_cntr_val_set:1;
    unsigned int    reserved_0:3;
    unsigned int    memc_cntr_val:12;
    unsigned int    reserved_1:4;
    unsigned int    memc_low_lvl_val:12;
}SB3_arb_cntr_set8;

typedef struct
{
    unsigned int    gdmasub2_cntr_val_set:1;
    unsigned int    reserved_0:3;
    unsigned int    gdmasub2_cntr_val:12;
    unsigned int    reserved_1:4;
    unsigned int    gdmasub2_low_lvl_val:12;
}SB3_arb_cntr_set9;

typedef struct
{
    unsigned int    reserved_0:29;
    unsigned int    cursor_pricnt:3;
}SB3_arb_cntr_set10;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    max_count:4;
    unsigned int    reserved_1:8;
    unsigned int    off_time:8;
}SB3_req_cr;

typedef struct
{
    unsigned int    reserved_0:6;
    unsigned int    sb_gnt:10;
    unsigned int    reserved_1:4;
    unsigned int    win_latcnt:12;
}SB3_arb_sr1;

typedef struct
{
    unsigned int    reserved_0:7;
    unsigned int    low_lvl_ie:9;
    unsigned int    reserved_1:7;
    unsigned int    low_lvl_ip:9;
}SB3_arb_sr2;
#endif

#define SB0_ARB_CR                                                    0x1801c000
#define SB0_ARB_CR_reg_addr                                           "0xB801C000"
#define SB0_ARB_CR_reg                                                0xB801C000
#define SB0_ARB_CR_inst_addr                                          "0x0000"
#define SB0_ARB_CR_inst                                               0x0000
#define SB0_ARB_CR_dec_mode_shift                                     (31)
#define SB0_ARB_CR_cnt_src_sel_shift                                  (16)
#define SB0_ARB_CR_time_step_shift                                    (12)
#define SB0_ARB_CR_arb_en_shift                                       (0)
#define SB0_ARB_CR_dec_mode_mask                                      (0x80000000)
#define SB0_ARB_CR_cnt_src_sel_mask                                   (0x00070000)
#define SB0_ARB_CR_time_step_mask                                     (0x0000F000)
#define SB0_ARB_CR_arb_en_mask                                        (0x00000007)
#define SB0_ARB_CR_dec_mode(data)                                     (0x80000000&((data)<<31))
#define SB0_ARB_CR_cnt_src_sel(data)                                  (0x00070000&((data)<<16))
#define SB0_ARB_CR_time_step(data)                                    (0x0000F000&((data)<<12))
#define SB0_ARB_CR_arb_en(data)                                       (0x00000007&(data))
#define SB0_ARB_CR_get_dec_mode(data)                                 ((0x80000000&(data))>>31)
#define SB0_ARB_CR_get_cnt_src_sel(data)                              ((0x00070000&(data))>>16)
#define SB0_ARB_CR_get_time_step(data)                                ((0x0000F000&(data))>>12)
#define SB0_ARB_CR_get_arb_en(data)                                   (0x00000007&(data))

#define SB0_LATCNT_CR1                                                0x1801c010
#define SB0_LATCNT_CR1_reg_addr                                       "0xB801C010"
#define SB0_LATCNT_CR1_reg                                            0xB801C010
#define SB0_LATCNT_CR1_inst_addr                                      "0x0004"
#define SB0_LATCNT_CR1_inst                                           0x0004
#define SB0_LATCNT_CR1_vdec_latcnt_end_shift                          (16)
#define SB0_LATCNT_CR1_vdec_latcnt_beg_shift                          (0)
#define SB0_LATCNT_CR1_vdec_latcnt_end_mask                           (0x0FFF0000)
#define SB0_LATCNT_CR1_vdec_latcnt_beg_mask                           (0x00000FFF)
#define SB0_LATCNT_CR1_vdec_latcnt_end(data)                          (0x0FFF0000&((data)<<16))
#define SB0_LATCNT_CR1_vdec_latcnt_beg(data)                          (0x00000FFF&(data))
#define SB0_LATCNT_CR1_get_vdec_latcnt_end(data)                      ((0x0FFF0000&(data))>>16)
#define SB0_LATCNT_CR1_get_vdec_latcnt_beg(data)                      (0x00000FFF&(data))

#define SB0_LATCNT_CR2                                                0x1801c014
#define SB0_LATCNT_CR2_reg_addr                                       "0xB801C014"
#define SB0_LATCNT_CR2_reg                                            0xB801C014
#define SB0_LATCNT_CR2_inst_addr                                      "0x0005"
#define SB0_LATCNT_CR2_inst                                           0x0005
#define SB0_LATCNT_CR2_vbi_latcnt_end_shift                           (16)
#define SB0_LATCNT_CR2_vbi_latcnt_beg_shift                           (0)
#define SB0_LATCNT_CR2_vbi_latcnt_end_mask                            (0x0FFF0000)
#define SB0_LATCNT_CR2_vbi_latcnt_beg_mask                            (0x00000FFF)
#define SB0_LATCNT_CR2_vbi_latcnt_end(data)                           (0x0FFF0000&((data)<<16))
#define SB0_LATCNT_CR2_vbi_latcnt_beg(data)                           (0x00000FFF&(data))
#define SB0_LATCNT_CR2_get_vbi_latcnt_end(data)                       ((0x0FFF0000&(data))>>16)
#define SB0_LATCNT_CR2_get_vbi_latcnt_beg(data)                       (0x00000FFF&(data))

#define SB0_LATCNT_CR3                                                0x1801c018
#define SB0_LATCNT_CR3_reg_addr                                       "0xB801C018"
#define SB0_LATCNT_CR3_reg                                            0xB801C018
#define SB0_LATCNT_CR3_inst_addr                                      "0x0006"
#define SB0_LATCNT_CR3_inst                                           0x0006
#define SB0_LATCNT_CR3_vi_latcnt_end_shift                            (16)
#define SB0_LATCNT_CR3_vi_latcnt_beg_shift                            (0)
#define SB0_LATCNT_CR3_vi_latcnt_end_mask                             (0x0FFF0000)
#define SB0_LATCNT_CR3_vi_latcnt_beg_mask                             (0x00000FFF)
#define SB0_LATCNT_CR3_vi_latcnt_end(data)                            (0x0FFF0000&((data)<<16))
#define SB0_LATCNT_CR3_vi_latcnt_beg(data)                            (0x00000FFF&(data))
#define SB0_LATCNT_CR3_get_vi_latcnt_end(data)                        ((0x0FFF0000&(data))>>16)
#define SB0_LATCNT_CR3_get_vi_latcnt_beg(data)                        (0x00000FFF&(data))

#define SB0_WDRR_CR1                                                  0x1801c01c
#define SB0_WDRR_CR1_reg_addr                                         "0xB801C01C"
#define SB0_WDRR_CR1_reg                                              0xB801C01C
#define SB0_WDRR_CR1_inst_addr                                        "0x0007"
#define SB0_WDRR_CR1_inst                                             0x0007
#define SB0_WDRR_CR1_vdec_credit_val_shift                            (16)
#define SB0_WDRR_CR1_vdec_deficit_val_shift                           (8)
#define SB0_WDRR_CR1_vdec_elapse_val_shift                            (0)
#define SB0_WDRR_CR1_vdec_credit_val_mask                             (0x0FFF0000)
#define SB0_WDRR_CR1_vdec_deficit_val_mask                            (0x0000FF00)
#define SB0_WDRR_CR1_vdec_elapse_val_mask                             (0x000000FF)
#define SB0_WDRR_CR1_vdec_credit_val(data)                            (0x0FFF0000&((data)<<16))
#define SB0_WDRR_CR1_vdec_deficit_val(data)                           (0x0000FF00&((data)<<8))
#define SB0_WDRR_CR1_vdec_elapse_val(data)                            (0x000000FF&(data))
#define SB0_WDRR_CR1_get_vdec_credit_val(data)                        ((0x0FFF0000&(data))>>16)
#define SB0_WDRR_CR1_get_vdec_deficit_val(data)                       ((0x0000FF00&(data))>>8)
#define SB0_WDRR_CR1_get_vdec_elapse_val(data)                        (0x000000FF&(data))

#define SB0_WDRR_CR2                                                  0x1801c020
#define SB0_WDRR_CR2_reg_addr                                         "0xB801C020"
#define SB0_WDRR_CR2_reg                                              0xB801C020
#define SB0_WDRR_CR2_inst_addr                                        "0x0008"
#define SB0_WDRR_CR2_inst                                             0x0008
#define SB0_WDRR_CR2_vbi_credit_val_shift                             (16)
#define SB0_WDRR_CR2_vbi_deficit_val_shift                            (8)
#define SB0_WDRR_CR2_vbi_elapse_val_shift                             (0)
#define SB0_WDRR_CR2_vbi_credit_val_mask                              (0x0FFF0000)
#define SB0_WDRR_CR2_vbi_deficit_val_mask                             (0x0000FF00)
#define SB0_WDRR_CR2_vbi_elapse_val_mask                              (0x000000FF)
#define SB0_WDRR_CR2_vbi_credit_val(data)                             (0x0FFF0000&((data)<<16))
#define SB0_WDRR_CR2_vbi_deficit_val(data)                            (0x0000FF00&((data)<<8))
#define SB0_WDRR_CR2_vbi_elapse_val(data)                             (0x000000FF&(data))
#define SB0_WDRR_CR2_get_vbi_credit_val(data)                         ((0x0FFF0000&(data))>>16)
#define SB0_WDRR_CR2_get_vbi_deficit_val(data)                        ((0x0000FF00&(data))>>8)
#define SB0_WDRR_CR2_get_vbi_elapse_val(data)                         (0x000000FF&(data))

#define SB0_WDRR_CR3                                                  0x1801c024
#define SB0_WDRR_CR3_reg_addr                                         "0xB801C024"
#define SB0_WDRR_CR3_reg                                              0xB801C024
#define SB0_WDRR_CR3_inst_addr                                        "0x0009"
#define SB0_WDRR_CR3_inst                                             0x0009
#define SB0_WDRR_CR3_vi_credit_val_shift                              (16)
#define SB0_WDRR_CR3_vi_deficit_val_shift                             (8)
#define SB0_WDRR_CR3_vi_elapse_val_shift                              (0)
#define SB0_WDRR_CR3_vi_credit_val_mask                               (0x0FFF0000)
#define SB0_WDRR_CR3_vi_deficit_val_mask                              (0x0000FF00)
#define SB0_WDRR_CR3_vi_elapse_val_mask                               (0x000000FF)
#define SB0_WDRR_CR3_vi_credit_val(data)                              (0x0FFF0000&((data)<<16))
#define SB0_WDRR_CR3_vi_deficit_val(data)                             (0x0000FF00&((data)<<8))
#define SB0_WDRR_CR3_vi_elapse_val(data)                              (0x000000FF&(data))
#define SB0_WDRR_CR3_get_vi_credit_val(data)                          ((0x0FFF0000&(data))>>16)
#define SB0_WDRR_CR3_get_vi_deficit_val(data)                         ((0x0000FF00&(data))>>8)
#define SB0_WDRR_CR3_get_vi_elapse_val(data)                          (0x000000FF&(data))

#define SB0_ARB_CNTR_SET1                                             0x1801c028
#define SB0_ARB_CNTR_SET1_reg_addr                                    "0xB801C028"
#define SB0_ARB_CNTR_SET1_reg                                         0xB801C028
#define SB0_ARB_CNTR_SET1_inst_addr                                   "0x000A"
#define SB0_ARB_CNTR_SET1_inst                                        0x000A
#define SB0_ARB_CNTR_SET1_vdec_cntr_val_set_shift                     (31)
#define SB0_ARB_CNTR_SET1_vdec_cntr_val_shift                         (16)
#define SB0_ARB_CNTR_SET1_vdec_low_lvl_val_shift                      (0)
#define SB0_ARB_CNTR_SET1_vdec_cntr_val_set_mask                      (0x80000000)
#define SB0_ARB_CNTR_SET1_vdec_cntr_val_mask                          (0x0FFF0000)
#define SB0_ARB_CNTR_SET1_vdec_low_lvl_val_mask                       (0x00000FFF)
#define SB0_ARB_CNTR_SET1_vdec_cntr_val_set(data)                     (0x80000000&((data)<<31))
#define SB0_ARB_CNTR_SET1_vdec_cntr_val(data)                         (0x0FFF0000&((data)<<16))
#define SB0_ARB_CNTR_SET1_vdec_low_lvl_val(data)                      (0x00000FFF&(data))
#define SB0_ARB_CNTR_SET1_get_vdec_cntr_val_set(data)                 ((0x80000000&(data))>>31)
#define SB0_ARB_CNTR_SET1_get_vdec_cntr_val(data)                     ((0x0FFF0000&(data))>>16)
#define SB0_ARB_CNTR_SET1_get_vdec_low_lvl_val(data)                  (0x00000FFF&(data))

#define SB0_ARB_CNTR_SET2                                             0x1801c02c
#define SB0_ARB_CNTR_SET2_reg_addr                                    "0xB801C02C"
#define SB0_ARB_CNTR_SET2_reg                                         0xB801C02C
#define SB0_ARB_CNTR_SET2_inst_addr                                   "0x000B"
#define SB0_ARB_CNTR_SET2_inst                                        0x000B
#define SB0_ARB_CNTR_SET2_vbi_cntr_val_set_shift                      (31)
#define SB0_ARB_CNTR_SET2_vbi_cntr_val_shift                          (16)
#define SB0_ARB_CNTR_SET2_vbi_low_lvl_val_shift                       (0)
#define SB0_ARB_CNTR_SET2_vbi_cntr_val_set_mask                       (0x80000000)
#define SB0_ARB_CNTR_SET2_vbi_cntr_val_mask                           (0x0FFF0000)
#define SB0_ARB_CNTR_SET2_vbi_low_lvl_val_mask                        (0x00000FFF)
#define SB0_ARB_CNTR_SET2_vbi_cntr_val_set(data)                      (0x80000000&((data)<<31))
#define SB0_ARB_CNTR_SET2_vbi_cntr_val(data)                          (0x0FFF0000&((data)<<16))
#define SB0_ARB_CNTR_SET2_vbi_low_lvl_val(data)                       (0x00000FFF&(data))
#define SB0_ARB_CNTR_SET2_get_vbi_cntr_val_set(data)                  ((0x80000000&(data))>>31)
#define SB0_ARB_CNTR_SET2_get_vbi_cntr_val(data)                      ((0x0FFF0000&(data))>>16)
#define SB0_ARB_CNTR_SET2_get_vbi_low_lvl_val(data)                   (0x00000FFF&(data))

#define SB0_ARB_CNTR_SET3                                             0x1801c030
#define SB0_ARB_CNTR_SET3_reg_addr                                    "0xB801C030"
#define SB0_ARB_CNTR_SET3_reg                                         0xB801C030
#define SB0_ARB_CNTR_SET3_inst_addr                                   "0x000C"
#define SB0_ARB_CNTR_SET3_inst                                        0x000C
#define SB0_ARB_CNTR_SET3_vi_cntr_val_set_shift                       (31)
#define SB0_ARB_CNTR_SET3_vi_cntr_val_shift                           (16)
#define SB0_ARB_CNTR_SET3_vi_low_lvl_val_shift                        (0)
#define SB0_ARB_CNTR_SET3_vi_cntr_val_set_mask                        (0x80000000)
#define SB0_ARB_CNTR_SET3_vi_cntr_val_mask                            (0x0FFF0000)
#define SB0_ARB_CNTR_SET3_vi_low_lvl_val_mask                         (0x00000FFF)
#define SB0_ARB_CNTR_SET3_vi_cntr_val_set(data)                       (0x80000000&((data)<<31))
#define SB0_ARB_CNTR_SET3_vi_cntr_val(data)                           (0x0FFF0000&((data)<<16))
#define SB0_ARB_CNTR_SET3_vi_low_lvl_val(data)                        (0x00000FFF&(data))
#define SB0_ARB_CNTR_SET3_get_vi_cntr_val_set(data)                   ((0x80000000&(data))>>31)
#define SB0_ARB_CNTR_SET3_get_vi_cntr_val(data)                       ((0x0FFF0000&(data))>>16)
#define SB0_ARB_CNTR_SET3_get_vi_low_lvl_val(data)                    (0x00000FFF&(data))

#define SB0_REQ_CR                                                    0x1801c040
#define SB0_REQ_CR_reg_addr                                           "0xB801C040"
#define SB0_REQ_CR_reg                                                0xB801C040
#define SB0_REQ_CR_inst_addr                                          "0x0010"
#define SB0_REQ_CR_inst                                               0x0010
#define SB0_REQ_CR_max_count_shift                                    (16)
#define SB0_REQ_CR_off_time_shift                                     (0)
#define SB0_REQ_CR_max_count_mask                                     (0x000F0000)
#define SB0_REQ_CR_off_time_mask                                      (0x000000FF)
#define SB0_REQ_CR_max_count(data)                                    (0x000F0000&((data)<<16))
#define SB0_REQ_CR_off_time(data)                                     (0x000000FF&(data))
#define SB0_REQ_CR_get_max_count(data)                                ((0x000F0000&(data))>>16)
#define SB0_REQ_CR_get_off_time(data)                                 (0x000000FF&(data))

#define SB0_ARB_SR1                                                   0x1801c050
#define SB0_ARB_SR1_reg_addr                                          "0xB801C050"
#define SB0_ARB_SR1_reg                                               0xB801C050
#define SB0_ARB_SR1_inst_addr                                         "0x0014"
#define SB0_ARB_SR1_inst                                              0x0014
#define SB0_ARB_SR1_sb_gnt_shift                                      (16)
#define SB0_ARB_SR1_win_latcnt_shift                                  (0)
#define SB0_ARB_SR1_sb_gnt_mask                                       (0x00070000)
#define SB0_ARB_SR1_win_latcnt_mask                                   (0x00000FFF)
#define SB0_ARB_SR1_sb_gnt(data)                                      (0x00070000&((data)<<16))
#define SB0_ARB_SR1_win_latcnt(data)                                  (0x00000FFF&(data))
#define SB0_ARB_SR1_get_sb_gnt(data)                                  ((0x00070000&(data))>>16)
#define SB0_ARB_SR1_get_win_latcnt(data)                              (0x00000FFF&(data))

#define SB0_ARB_SR2                                                   0x1801c054
#define SB0_ARB_SR2_reg_addr                                          "0xB801C054"
#define SB0_ARB_SR2_reg                                               0xB801C054
#define SB0_ARB_SR2_inst_addr                                         "0x0015"
#define SB0_ARB_SR2_inst                                              0x0015
#define SB0_ARB_SR2_low_lvl_ie_shift                                  (16)
#define SB0_ARB_SR2_low_lvl_ip_shift                                  (0)
#define SB0_ARB_SR2_low_lvl_ie_mask                                   (0x00070000)
#define SB0_ARB_SR2_low_lvl_ip_mask                                   (0x00000007)
#define SB0_ARB_SR2_low_lvl_ie(data)                                  (0x00070000&((data)<<16))
#define SB0_ARB_SR2_low_lvl_ip(data)                                  (0x00000007&(data))
#define SB0_ARB_SR2_get_low_lvl_ie(data)                              ((0x00070000&(data))>>16)
#define SB0_ARB_SR2_get_low_lvl_ip(data)                              (0x00000007&(data))

#define SB3_ARB_CR                                                    0x1801c100
#define SB3_ARB_CR_reg_addr                                           "0xB801C100"
#define SB3_ARB_CR_reg                                                0xB801C100
#define SB3_ARB_CR_inst_addr                                          "0x0040"
#define SB3_ARB_CR_inst                                               0x0040
#define SB3_ARB_CR_dec_mode_shift                                     (31)
#define SB3_ARB_CR_cnt_src_sel_shift                                  (16)
#define SB3_ARB_CR_time_step_shift                                    (12)
#define SB3_ARB_CR_arb_en_shift                                       (0)
#define SB3_ARB_CR_dec_mode_mask                                      (0x80000000)
#define SB3_ARB_CR_cnt_src_sel_mask                                   (0x01FF0000)
#define SB3_ARB_CR_time_step_mask                                     (0x0000F000)
#define SB3_ARB_CR_arb_en_mask                                        (0x000003FF)
#define SB3_ARB_CR_dec_mode(data)                                     (0x80000000&((data)<<31))
#define SB3_ARB_CR_cnt_src_sel(data)                                  (0x01FF0000&((data)<<16))
#define SB3_ARB_CR_time_step(data)                                    (0x0000F000&((data)<<12))
#define SB3_ARB_CR_arb_en(data)                                       (0x000003FF&(data))
#define SB3_ARB_CR_get_dec_mode(data)                                 ((0x80000000&(data))>>31)
#define SB3_ARB_CR_get_cnt_src_sel(data)                              ((0x01FF0000&(data))>>16)
#define SB3_ARB_CR_get_time_step(data)                                ((0x0000F000&(data))>>12)
#define SB3_ARB_CR_get_arb_en(data)                                   (0x000003FF&(data))

#define SB3_LATCNT_CR1                                                0x1801c110
#define SB3_LATCNT_CR1_reg_addr                                       "0xB801C110"
#define SB3_LATCNT_CR1_reg                                            0xB801C110
#define SB3_LATCNT_CR1_inst_addr                                      "0x0044"
#define SB3_LATCNT_CR1_inst                                           0x0044
#define SB3_LATCNT_CR1_xcdim_latcnt_end_shift                         (16)
#define SB3_LATCNT_CR1_xcdim_latcnt_beg_shift                         (0)
#define SB3_LATCNT_CR1_xcdim_latcnt_end_mask                          (0x0FFF0000)
#define SB3_LATCNT_CR1_xcdim_latcnt_beg_mask                          (0x00000FFF)
#define SB3_LATCNT_CR1_xcdim_latcnt_end(data)                         (0x0FFF0000&((data)<<16))
#define SB3_LATCNT_CR1_xcdim_latcnt_beg(data)                         (0x00000FFF&(data))
#define SB3_LATCNT_CR1_get_xcdim_latcnt_end(data)                     ((0x0FFF0000&(data))>>16)
#define SB3_LATCNT_CR1_get_xcdim_latcnt_beg(data)                     (0x00000FFF&(data))

#define SB3_LATCNT_CR2                                                0x1801c114
#define SB3_LATCNT_CR2_reg_addr                                       "0xB801C114"
#define SB3_LATCNT_CR2_reg                                            0xB801C114
#define SB3_LATCNT_CR2_inst_addr                                      "0x0045"
#define SB3_LATCNT_CR2_inst                                           0x0045
#define SB3_LATCNT_CR2_gdmaosd_latcnt_end_shift                       (16)
#define SB3_LATCNT_CR2_gdmaosd_latcnt_beg_shift                       (0)
#define SB3_LATCNT_CR2_gdmaosd_latcnt_end_mask                        (0x0FFF0000)
#define SB3_LATCNT_CR2_gdmaosd_latcnt_beg_mask                        (0x00000FFF)
#define SB3_LATCNT_CR2_gdmaosd_latcnt_end(data)                       (0x0FFF0000&((data)<<16))
#define SB3_LATCNT_CR2_gdmaosd_latcnt_beg(data)                       (0x00000FFF&(data))
#define SB3_LATCNT_CR2_get_gdmaosd_latcnt_end(data)                   ((0x0FFF0000&(data))>>16)
#define SB3_LATCNT_CR2_get_gdmaosd_latcnt_beg(data)                   (0x00000FFF&(data))

#define SB3_LATCNT_CR3                                                0x1801c118
#define SB3_LATCNT_CR3_reg_addr                                       "0xB801C118"
#define SB3_LATCNT_CR3_reg                                            0xB801C118
#define SB3_LATCNT_CR3_inst_addr                                      "0x0046"
#define SB3_LATCNT_CR3_inst                                           0x0046
#define SB3_LATCNT_CR3_disdisps_latcnt_end_shift                      (16)
#define SB3_LATCNT_CR3_disdisps_latcnt_beg_shift                      (0)
#define SB3_LATCNT_CR3_disdisps_latcnt_end_mask                       (0x0FFF0000)
#define SB3_LATCNT_CR3_disdisps_latcnt_beg_mask                       (0x00000FFF)
#define SB3_LATCNT_CR3_disdisps_latcnt_end(data)                      (0x0FFF0000&((data)<<16))
#define SB3_LATCNT_CR3_disdisps_latcnt_beg(data)                      (0x00000FFF&(data))
#define SB3_LATCNT_CR3_get_disdisps_latcnt_end(data)                  ((0x0FFF0000&(data))>>16)
#define SB3_LATCNT_CR3_get_disdisps_latcnt_beg(data)                  (0x00000FFF&(data))

#define SB3_LATCNT_CR4                                                0x1801c11c
#define SB3_LATCNT_CR4_reg_addr                                       "0xB801C11C"
#define SB3_LATCNT_CR4_reg                                            0xB801C11C
#define SB3_LATCNT_CR4_inst_addr                                      "0x0047"
#define SB3_LATCNT_CR4_inst                                           0x0047
#define SB3_LATCNT_CR4_discaps_latcnt_end_shift                       (16)
#define SB3_LATCNT_CR4_discaps_latcnt_beg_shift                       (0)
#define SB3_LATCNT_CR4_discaps_latcnt_end_mask                        (0x0FFF0000)
#define SB3_LATCNT_CR4_discaps_latcnt_beg_mask                        (0x00000FFF)
#define SB3_LATCNT_CR4_discaps_latcnt_end(data)                       (0x0FFF0000&((data)<<16))
#define SB3_LATCNT_CR4_discaps_latcnt_beg(data)                       (0x00000FFF&(data))
#define SB3_LATCNT_CR4_get_discaps_latcnt_end(data)                   ((0x0FFF0000&(data))>>16)
#define SB3_LATCNT_CR4_get_discaps_latcnt_beg(data)                   (0x00000FFF&(data))

#define SB3_LATCNT_CR5                                                0x1801c120
#define SB3_LATCNT_CR5_reg_addr                                       "0xB801C120"
#define SB3_LATCNT_CR5_reg                                            0xB801C120
#define SB3_LATCNT_CR5_inst_addr                                      "0x0048"
#define SB3_LATCNT_CR5_inst                                           0x0048
#define SB3_LATCNT_CR5_vo_latcnt_end_shift                            (16)
#define SB3_LATCNT_CR5_vo_latcnt_beg_shift                            (0)
#define SB3_LATCNT_CR5_vo_latcnt_end_mask                             (0x0FFF0000)
#define SB3_LATCNT_CR5_vo_latcnt_beg_mask                             (0x00000FFF)
#define SB3_LATCNT_CR5_vo_latcnt_end(data)                            (0x0FFF0000&((data)<<16))
#define SB3_LATCNT_CR5_vo_latcnt_beg(data)                            (0x00000FFF&(data))
#define SB3_LATCNT_CR5_get_vo_latcnt_end(data)                        ((0x0FFF0000&(data))>>16)
#define SB3_LATCNT_CR5_get_vo_latcnt_beg(data)                        (0x00000FFF&(data))

#define SB3_LATCNT_CR6                                                0x1801c124
#define SB3_LATCNT_CR6_reg_addr                                       "0xB801C124"
#define SB3_LATCNT_CR6_reg                                            0xB801C124
#define SB3_LATCNT_CR6_inst_addr                                      "0x0049"
#define SB3_LATCNT_CR6_inst                                           0x0049
#define SB3_LATCNT_CR6_gdmasub1_latcnt_end_shift                      (16)
#define SB3_LATCNT_CR6_gdmasub1_latcnt_beg_shift                      (0)
#define SB3_LATCNT_CR6_gdmasub1_latcnt_end_mask                       (0x0FFF0000)
#define SB3_LATCNT_CR6_gdmasub1_latcnt_beg_mask                       (0x00000FFF)
#define SB3_LATCNT_CR6_gdmasub1_latcnt_end(data)                      (0x0FFF0000&((data)<<16))
#define SB3_LATCNT_CR6_gdmasub1_latcnt_beg(data)                      (0x00000FFF&(data))
#define SB3_LATCNT_CR6_get_gdmasub1_latcnt_end(data)                  ((0x0FFF0000&(data))>>16)
#define SB3_LATCNT_CR6_get_gdmasub1_latcnt_beg(data)                  (0x00000FFF&(data))

#define SB3_LATCNT_CR7                                                0x1801c128
#define SB3_LATCNT_CR7_reg_addr                                       "0xB801C128"
#define SB3_LATCNT_CR7_reg                                            0xB801C128
#define SB3_LATCNT_CR7_inst_addr                                      "0x004A"
#define SB3_LATCNT_CR7_inst                                           0x004A
#define SB3_LATCNT_CR7_gibi_latcnt_end_shift                          (16)
#define SB3_LATCNT_CR7_gibi_latcnt_beg_shift                          (0)
#define SB3_LATCNT_CR7_gibi_latcnt_end_mask                           (0x0FFF0000)
#define SB3_LATCNT_CR7_gibi_latcnt_beg_mask                           (0x00000FFF)
#define SB3_LATCNT_CR7_gibi_latcnt_end(data)                          (0x0FFF0000&((data)<<16))
#define SB3_LATCNT_CR7_gibi_latcnt_beg(data)                          (0x00000FFF&(data))
#define SB3_LATCNT_CR7_get_gibi_latcnt_end(data)                      ((0x0FFF0000&(data))>>16)
#define SB3_LATCNT_CR7_get_gibi_latcnt_beg(data)                      (0x00000FFF&(data))

#define SB3_LATCNT_CR8                                                0x1801c12c
#define SB3_LATCNT_CR8_reg_addr                                       "0xB801C12C"
#define SB3_LATCNT_CR8_reg                                            0xB801C12C
#define SB3_LATCNT_CR8_inst_addr                                      "0x004B"
#define SB3_LATCNT_CR8_inst                                           0x004B
#define SB3_LATCNT_CR8_memc_latcnt_end_shift                          (16)
#define SB3_LATCNT_CR8_memc_latcnt_beg_shift                          (0)
#define SB3_LATCNT_CR8_memc_latcnt_end_mask                           (0x0FFF0000)
#define SB3_LATCNT_CR8_memc_latcnt_beg_mask                           (0x00000FFF)
#define SB3_LATCNT_CR8_memc_latcnt_end(data)                          (0x0FFF0000&((data)<<16))
#define SB3_LATCNT_CR8_memc_latcnt_beg(data)                          (0x00000FFF&(data))
#define SB3_LATCNT_CR8_get_memc_latcnt_end(data)                      ((0x0FFF0000&(data))>>16)
#define SB3_LATCNT_CR8_get_memc_latcnt_beg(data)                      (0x00000FFF&(data))

#define SB3_LATCNT_CR9                                                0x1801c130
#define SB3_LATCNT_CR9_reg_addr                                       "0xB801C130"
#define SB3_LATCNT_CR9_reg                                            0xB801C130
#define SB3_LATCNT_CR9_inst_addr                                      "0x004C"
#define SB3_LATCNT_CR9_inst                                           0x004C
#define SB3_LATCNT_CR9_gdmasub2_latcnt_end_shift                      (16)
#define SB3_LATCNT_CR9_gdmasub2_latcnt_beg_shift                      (0)
#define SB3_LATCNT_CR9_gdmasub2_latcnt_end_mask                       (0x0FFF0000)
#define SB3_LATCNT_CR9_gdmasub2_latcnt_beg_mask                       (0x00000FFF)
#define SB3_LATCNT_CR9_gdmasub2_latcnt_end(data)                      (0x0FFF0000&((data)<<16))
#define SB3_LATCNT_CR9_gdmasub2_latcnt_beg(data)                      (0x00000FFF&(data))
#define SB3_LATCNT_CR9_get_gdmasub2_latcnt_end(data)                  ((0x0FFF0000&(data))>>16)
#define SB3_LATCNT_CR9_get_gdmasub2_latcnt_beg(data)                  (0x00000FFF&(data))

#define SB3_WDRR_CR1                                                  0x1801c140
#define SB3_WDRR_CR1_reg_addr                                         "0xB801C140"
#define SB3_WDRR_CR1_reg                                              0xB801C140
#define SB3_WDRR_CR1_inst_addr                                        "0x0050"
#define SB3_WDRR_CR1_inst                                             0x0050
#define SB3_WDRR_CR1_xcdim_credit_val_shift                           (16)
#define SB3_WDRR_CR1_xcdim_deficit_val_shift                          (8)
#define SB3_WDRR_CR1_xcdim_elapse_val_shift                           (0)
#define SB3_WDRR_CR1_xcdim_credit_val_mask                            (0x0FFF0000)
#define SB3_WDRR_CR1_xcdim_deficit_val_mask                           (0x0000FF00)
#define SB3_WDRR_CR1_xcdim_elapse_val_mask                            (0x000000FF)
#define SB3_WDRR_CR1_xcdim_credit_val(data)                           (0x0FFF0000&((data)<<16))
#define SB3_WDRR_CR1_xcdim_deficit_val(data)                          (0x0000FF00&((data)<<8))
#define SB3_WDRR_CR1_xcdim_elapse_val(data)                           (0x000000FF&(data))
#define SB3_WDRR_CR1_get_xcdim_credit_val(data)                       ((0x0FFF0000&(data))>>16)
#define SB3_WDRR_CR1_get_xcdim_deficit_val(data)                      ((0x0000FF00&(data))>>8)
#define SB3_WDRR_CR1_get_xcdim_elapse_val(data)                       (0x000000FF&(data))

#define SB3_WDRR_CR2                                                  0x1801c144
#define SB3_WDRR_CR2_reg_addr                                         "0xB801C144"
#define SB3_WDRR_CR2_reg                                              0xB801C144
#define SB3_WDRR_CR2_inst_addr                                        "0x0051"
#define SB3_WDRR_CR2_inst                                             0x0051
#define SB3_WDRR_CR2_gdmaosd_credit_val_shift                         (16)
#define SB3_WDRR_CR2_gdmaosd_deficit_val_shift                        (8)
#define SB3_WDRR_CR2_gdmaosd_elapse_val_shift                         (0)
#define SB3_WDRR_CR2_gdmaosd_credit_val_mask                          (0x0FFF0000)
#define SB3_WDRR_CR2_gdmaosd_deficit_val_mask                         (0x0000FF00)
#define SB3_WDRR_CR2_gdmaosd_elapse_val_mask                          (0x000000FF)
#define SB3_WDRR_CR2_gdmaosd_credit_val(data)                         (0x0FFF0000&((data)<<16))
#define SB3_WDRR_CR2_gdmaosd_deficit_val(data)                        (0x0000FF00&((data)<<8))
#define SB3_WDRR_CR2_gdmaosd_elapse_val(data)                         (0x000000FF&(data))
#define SB3_WDRR_CR2_get_gdmaosd_credit_val(data)                     ((0x0FFF0000&(data))>>16)
#define SB3_WDRR_CR2_get_gdmaosd_deficit_val(data)                    ((0x0000FF00&(data))>>8)
#define SB3_WDRR_CR2_get_gdmaosd_elapse_val(data)                     (0x000000FF&(data))

#define SB3_WDRR_CR3                                                  0x1801c148
#define SB3_WDRR_CR3_reg_addr                                         "0xB801C148"
#define SB3_WDRR_CR3_reg                                              0xB801C148
#define SB3_WDRR_CR3_inst_addr                                        "0x0052"
#define SB3_WDRR_CR3_inst                                             0x0052
#define SB3_WDRR_CR3_disdisps_credit_val_shift                        (16)
#define SB3_WDRR_CR3_disdisps_deficit_val_shift                       (8)
#define SB3_WDRR_CR3_disdisps_elapse_val_shift                        (0)
#define SB3_WDRR_CR3_disdisps_credit_val_mask                         (0x0FFF0000)
#define SB3_WDRR_CR3_disdisps_deficit_val_mask                        (0x0000FF00)
#define SB3_WDRR_CR3_disdisps_elapse_val_mask                         (0x000000FF)
#define SB3_WDRR_CR3_disdisps_credit_val(data)                        (0x0FFF0000&((data)<<16))
#define SB3_WDRR_CR3_disdisps_deficit_val(data)                       (0x0000FF00&((data)<<8))
#define SB3_WDRR_CR3_disdisps_elapse_val(data)                        (0x000000FF&(data))
#define SB3_WDRR_CR3_get_disdisps_credit_val(data)                    ((0x0FFF0000&(data))>>16)
#define SB3_WDRR_CR3_get_disdisps_deficit_val(data)                   ((0x0000FF00&(data))>>8)
#define SB3_WDRR_CR3_get_disdisps_elapse_val(data)                    (0x000000FF&(data))

#define SB3_WDRR_CR4                                                  0x1801c14c
#define SB3_WDRR_CR4_reg_addr                                         "0xB801C14C"
#define SB3_WDRR_CR4_reg                                              0xB801C14C
#define SB3_WDRR_CR4_inst_addr                                        "0x0053"
#define SB3_WDRR_CR4_inst                                             0x0053
#define SB3_WDRR_CR4_discaps_credit_val_shift                         (16)
#define SB3_WDRR_CR4_discaps_deficit_val_shift                        (8)
#define SB3_WDRR_CR4_discaps_elapse_val_shift                         (0)
#define SB3_WDRR_CR4_discaps_credit_val_mask                          (0x0FFF0000)
#define SB3_WDRR_CR4_discaps_deficit_val_mask                         (0x0000FF00)
#define SB3_WDRR_CR4_discaps_elapse_val_mask                          (0x000000FF)
#define SB3_WDRR_CR4_discaps_credit_val(data)                         (0x0FFF0000&((data)<<16))
#define SB3_WDRR_CR4_discaps_deficit_val(data)                        (0x0000FF00&((data)<<8))
#define SB3_WDRR_CR4_discaps_elapse_val(data)                         (0x000000FF&(data))
#define SB3_WDRR_CR4_get_discaps_credit_val(data)                     ((0x0FFF0000&(data))>>16)
#define SB3_WDRR_CR4_get_discaps_deficit_val(data)                    ((0x0000FF00&(data))>>8)
#define SB3_WDRR_CR4_get_discaps_elapse_val(data)                     (0x000000FF&(data))

#define SB3_WDRR_CR5                                                  0x1801c150
#define SB3_WDRR_CR5_reg_addr                                         "0xB801C150"
#define SB3_WDRR_CR5_reg                                              0xB801C150
#define SB3_WDRR_CR5_inst_addr                                        "0x0054"
#define SB3_WDRR_CR5_inst                                             0x0054
#define SB3_WDRR_CR5_vo_credit_val_shift                              (16)
#define SB3_WDRR_CR5_vo_deficit_val_shift                             (8)
#define SB3_WDRR_CR5_vo_elapse_val_shift                              (0)
#define SB3_WDRR_CR5_vo_credit_val_mask                               (0x0FFF0000)
#define SB3_WDRR_CR5_vo_deficit_val_mask                              (0x0000FF00)
#define SB3_WDRR_CR5_vo_elapse_val_mask                               (0x000000FF)
#define SB3_WDRR_CR5_vo_credit_val(data)                              (0x0FFF0000&((data)<<16))
#define SB3_WDRR_CR5_vo_deficit_val(data)                             (0x0000FF00&((data)<<8))
#define SB3_WDRR_CR5_vo_elapse_val(data)                              (0x000000FF&(data))
#define SB3_WDRR_CR5_get_vo_credit_val(data)                          ((0x0FFF0000&(data))>>16)
#define SB3_WDRR_CR5_get_vo_deficit_val(data)                         ((0x0000FF00&(data))>>8)
#define SB3_WDRR_CR5_get_vo_elapse_val(data)                          (0x000000FF&(data))

#define SB3_WDRR_CR6                                                  0x1801c154
#define SB3_WDRR_CR6_reg_addr                                         "0xB801C154"
#define SB3_WDRR_CR6_reg                                              0xB801C154
#define SB3_WDRR_CR6_inst_addr                                        "0x0055"
#define SB3_WDRR_CR6_inst                                             0x0055
#define SB3_WDRR_CR6_gdmasub1_credit_val_shift                        (16)
#define SB3_WDRR_CR6_gdmasub1_deficit_val_shift                       (8)
#define SB3_WDRR_CR6_gdmasub1_elapse_val_shift                        (0)
#define SB3_WDRR_CR6_gdmasub1_credit_val_mask                         (0x0FFF0000)
#define SB3_WDRR_CR6_gdmasub1_deficit_val_mask                        (0x0000FF00)
#define SB3_WDRR_CR6_gdmasub1_elapse_val_mask                         (0x000000FF)
#define SB3_WDRR_CR6_gdmasub1_credit_val(data)                        (0x0FFF0000&((data)<<16))
#define SB3_WDRR_CR6_gdmasub1_deficit_val(data)                       (0x0000FF00&((data)<<8))
#define SB3_WDRR_CR6_gdmasub1_elapse_val(data)                        (0x000000FF&(data))
#define SB3_WDRR_CR6_get_gdmasub1_credit_val(data)                    ((0x0FFF0000&(data))>>16)
#define SB3_WDRR_CR6_get_gdmasub1_deficit_val(data)                   ((0x0000FF00&(data))>>8)
#define SB3_WDRR_CR6_get_gdmasub1_elapse_val(data)                    (0x000000FF&(data))

#define SB3_WDRR_CR7                                                  0x1801c158
#define SB3_WDRR_CR7_reg_addr                                         "0xB801C158"
#define SB3_WDRR_CR7_reg                                              0xB801C158
#define SB3_WDRR_CR7_inst_addr                                        "0x0056"
#define SB3_WDRR_CR7_inst                                             0x0056
#define SB3_WDRR_CR7_gibi_credit_val_shift                            (16)
#define SB3_WDRR_CR7_gibi_deficit_val_shift                           (8)
#define SB3_WDRR_CR7_gibi_elapse_val_shift                            (0)
#define SB3_WDRR_CR7_gibi_credit_val_mask                             (0x0FFF0000)
#define SB3_WDRR_CR7_gibi_deficit_val_mask                            (0x0000FF00)
#define SB3_WDRR_CR7_gibi_elapse_val_mask                             (0x000000FF)
#define SB3_WDRR_CR7_gibi_credit_val(data)                            (0x0FFF0000&((data)<<16))
#define SB3_WDRR_CR7_gibi_deficit_val(data)                           (0x0000FF00&((data)<<8))
#define SB3_WDRR_CR7_gibi_elapse_val(data)                            (0x000000FF&(data))
#define SB3_WDRR_CR7_get_gibi_credit_val(data)                        ((0x0FFF0000&(data))>>16)
#define SB3_WDRR_CR7_get_gibi_deficit_val(data)                       ((0x0000FF00&(data))>>8)
#define SB3_WDRR_CR7_get_gibi_elapse_val(data)                        (0x000000FF&(data))

#define SB3_WDRR_CR8                                                  0x1801c15c
#define SB3_WDRR_CR8_reg_addr                                         "0xB801C15C"
#define SB3_WDRR_CR8_reg                                              0xB801C15C
#define SB3_WDRR_CR8_inst_addr                                        "0x0057"
#define SB3_WDRR_CR8_inst                                             0x0057
#define SB3_WDRR_CR8_memc_credit_val_shift                            (16)
#define SB3_WDRR_CR8_memc_deficit_val_shift                           (8)
#define SB3_WDRR_CR8_memc_elapse_val_shift                            (0)
#define SB3_WDRR_CR8_memc_credit_val_mask                             (0x0FFF0000)
#define SB3_WDRR_CR8_memc_deficit_val_mask                            (0x0000FF00)
#define SB3_WDRR_CR8_memc_elapse_val_mask                             (0x000000FF)
#define SB3_WDRR_CR8_memc_credit_val(data)                            (0x0FFF0000&((data)<<16))
#define SB3_WDRR_CR8_memc_deficit_val(data)                           (0x0000FF00&((data)<<8))
#define SB3_WDRR_CR8_memc_elapse_val(data)                            (0x000000FF&(data))
#define SB3_WDRR_CR8_get_memc_credit_val(data)                        ((0x0FFF0000&(data))>>16)
#define SB3_WDRR_CR8_get_memc_deficit_val(data)                       ((0x0000FF00&(data))>>8)
#define SB3_WDRR_CR8_get_memc_elapse_val(data)                        (0x000000FF&(data))

#define SB3_WDRR_CR9                                                  0x1801c160
#define SB3_WDRR_CR9_reg_addr                                         "0xB801C160"
#define SB3_WDRR_CR9_reg                                              0xB801C160
#define SB3_WDRR_CR9_inst_addr                                        "0x0058"
#define SB3_WDRR_CR9_inst                                             0x0058
#define SB3_WDRR_CR9_gdmasub2_credit_val_shift                        (16)
#define SB3_WDRR_CR9_gdmasub2_deficit_val_shift                       (8)
#define SB3_WDRR_CR9_gdmasub2_elapse_val_shift                        (0)
#define SB3_WDRR_CR9_gdmasub2_credit_val_mask                         (0x0FFF0000)
#define SB3_WDRR_CR9_gdmasub2_deficit_val_mask                        (0x0000FF00)
#define SB3_WDRR_CR9_gdmasub2_elapse_val_mask                         (0x000000FF)
#define SB3_WDRR_CR9_gdmasub2_credit_val(data)                        (0x0FFF0000&((data)<<16))
#define SB3_WDRR_CR9_gdmasub2_deficit_val(data)                       (0x0000FF00&((data)<<8))
#define SB3_WDRR_CR9_gdmasub2_elapse_val(data)                        (0x000000FF&(data))
#define SB3_WDRR_CR9_get_gdmasub2_credit_val(data)                    ((0x0FFF0000&(data))>>16)
#define SB3_WDRR_CR9_get_gdmasub2_deficit_val(data)                   ((0x0000FF00&(data))>>8)
#define SB3_WDRR_CR9_get_gdmasub2_elapse_val(data)                    (0x000000FF&(data))

#define SB3_ARB_CNTR_SET1                                             0x1801c170
#define SB3_ARB_CNTR_SET1_reg_addr                                    "0xB801C170"
#define SB3_ARB_CNTR_SET1_reg                                         0xB801C170
#define SB3_ARB_CNTR_SET1_inst_addr                                   "0x005C"
#define SB3_ARB_CNTR_SET1_inst                                        0x005C
#define SB3_ARB_CNTR_SET1_xcdim_cntr_val_set_shift                    (31)
#define SB3_ARB_CNTR_SET1_xcdim_cntr_val_shift                        (16)
#define SB3_ARB_CNTR_SET1_xcdim_low_lvl_val_shift                     (0)
#define SB3_ARB_CNTR_SET1_xcdim_cntr_val_set_mask                     (0x80000000)
#define SB3_ARB_CNTR_SET1_xcdim_cntr_val_mask                         (0x0FFF0000)
#define SB3_ARB_CNTR_SET1_xcdim_low_lvl_val_mask                      (0x00000FFF)
#define SB3_ARB_CNTR_SET1_xcdim_cntr_val_set(data)                    (0x80000000&((data)<<31))
#define SB3_ARB_CNTR_SET1_xcdim_cntr_val(data)                        (0x0FFF0000&((data)<<16))
#define SB3_ARB_CNTR_SET1_xcdim_low_lvl_val(data)                     (0x00000FFF&(data))
#define SB3_ARB_CNTR_SET1_get_xcdim_cntr_val_set(data)                ((0x80000000&(data))>>31)
#define SB3_ARB_CNTR_SET1_get_xcdim_cntr_val(data)                    ((0x0FFF0000&(data))>>16)
#define SB3_ARB_CNTR_SET1_get_xcdim_low_lvl_val(data)                 (0x00000FFF&(data))

#define SB3_ARB_CNTR_SET2                                             0x1801c174
#define SB3_ARB_CNTR_SET2_reg_addr                                    "0xB801C174"
#define SB3_ARB_CNTR_SET2_reg                                         0xB801C174
#define SB3_ARB_CNTR_SET2_inst_addr                                   "0x005D"
#define SB3_ARB_CNTR_SET2_inst                                        0x005D
#define SB3_ARB_CNTR_SET2_gdmaosd_cntr_val_set_shift                  (31)
#define SB3_ARB_CNTR_SET2_gdmaosd_cntr_val_shift                      (16)
#define SB3_ARB_CNTR_SET2_gdmaosd_low_lvl_val_shift                   (0)
#define SB3_ARB_CNTR_SET2_gdmaosd_cntr_val_set_mask                   (0x80000000)
#define SB3_ARB_CNTR_SET2_gdmaosd_cntr_val_mask                       (0x0FFF0000)
#define SB3_ARB_CNTR_SET2_gdmaosd_low_lvl_val_mask                    (0x00000FFF)
#define SB3_ARB_CNTR_SET2_gdmaosd_cntr_val_set(data)                  (0x80000000&((data)<<31))
#define SB3_ARB_CNTR_SET2_gdmaosd_cntr_val(data)                      (0x0FFF0000&((data)<<16))
#define SB3_ARB_CNTR_SET2_gdmaosd_low_lvl_val(data)                   (0x00000FFF&(data))
#define SB3_ARB_CNTR_SET2_get_gdmaosd_cntr_val_set(data)              ((0x80000000&(data))>>31)
#define SB3_ARB_CNTR_SET2_get_gdmaosd_cntr_val(data)                  ((0x0FFF0000&(data))>>16)
#define SB3_ARB_CNTR_SET2_get_gdmaosd_low_lvl_val(data)               (0x00000FFF&(data))

#define SB3_ARB_CNTR_SET3                                             0x1801c178
#define SB3_ARB_CNTR_SET3_reg_addr                                    "0xB801C178"
#define SB3_ARB_CNTR_SET3_reg                                         0xB801C178
#define SB3_ARB_CNTR_SET3_inst_addr                                   "0x005E"
#define SB3_ARB_CNTR_SET3_inst                                        0x005E
#define SB3_ARB_CNTR_SET3_disdisps_cntr_val_set_shift                 (31)
#define SB3_ARB_CNTR_SET3_disdisps_cntr_val_shift                     (16)
#define SB3_ARB_CNTR_SET3_disdisps_low_lvl_val_shift                  (0)
#define SB3_ARB_CNTR_SET3_disdisps_cntr_val_set_mask                  (0x80000000)
#define SB3_ARB_CNTR_SET3_disdisps_cntr_val_mask                      (0x0FFF0000)
#define SB3_ARB_CNTR_SET3_disdisps_low_lvl_val_mask                   (0x00000FFF)
#define SB3_ARB_CNTR_SET3_disdisps_cntr_val_set(data)                 (0x80000000&((data)<<31))
#define SB3_ARB_CNTR_SET3_disdisps_cntr_val(data)                     (0x0FFF0000&((data)<<16))
#define SB3_ARB_CNTR_SET3_disdisps_low_lvl_val(data)                  (0x00000FFF&(data))
#define SB3_ARB_CNTR_SET3_get_disdisps_cntr_val_set(data)             ((0x80000000&(data))>>31)
#define SB3_ARB_CNTR_SET3_get_disdisps_cntr_val(data)                 ((0x0FFF0000&(data))>>16)
#define SB3_ARB_CNTR_SET3_get_disdisps_low_lvl_val(data)              (0x00000FFF&(data))

#define SB3_ARB_CNTR_SET4                                             0x1801c17c
#define SB3_ARB_CNTR_SET4_reg_addr                                    "0xB801C17C"
#define SB3_ARB_CNTR_SET4_reg                                         0xB801C17C
#define SB3_ARB_CNTR_SET4_inst_addr                                   "0x005F"
#define SB3_ARB_CNTR_SET4_inst                                        0x005F
#define SB3_ARB_CNTR_SET4_discaps_cntr_val_set_shift                  (31)
#define SB3_ARB_CNTR_SET4_discaps_cntr_val_shift                      (16)
#define SB3_ARB_CNTR_SET4_discaps_low_lvl_val_shift                   (0)
#define SB3_ARB_CNTR_SET4_discaps_cntr_val_set_mask                   (0x80000000)
#define SB3_ARB_CNTR_SET4_discaps_cntr_val_mask                       (0x0FFF0000)
#define SB3_ARB_CNTR_SET4_discaps_low_lvl_val_mask                    (0x00000FFF)
#define SB3_ARB_CNTR_SET4_discaps_cntr_val_set(data)                  (0x80000000&((data)<<31))
#define SB3_ARB_CNTR_SET4_discaps_cntr_val(data)                      (0x0FFF0000&((data)<<16))
#define SB3_ARB_CNTR_SET4_discaps_low_lvl_val(data)                   (0x00000FFF&(data))
#define SB3_ARB_CNTR_SET4_get_discaps_cntr_val_set(data)              ((0x80000000&(data))>>31)
#define SB3_ARB_CNTR_SET4_get_discaps_cntr_val(data)                  ((0x0FFF0000&(data))>>16)
#define SB3_ARB_CNTR_SET4_get_discaps_low_lvl_val(data)               (0x00000FFF&(data))

#define SB3_ARB_CNTR_SET5                                             0x1801c180
#define SB3_ARB_CNTR_SET5_reg_addr                                    "0xB801C180"
#define SB3_ARB_CNTR_SET5_reg                                         0xB801C180
#define SB3_ARB_CNTR_SET5_inst_addr                                   "0x0060"
#define SB3_ARB_CNTR_SET5_inst                                        0x0060
#define SB3_ARB_CNTR_SET5_vo_cntr_val_set_shift                       (31)
#define SB3_ARB_CNTR_SET5_vo_cntr_val_shift                           (16)
#define SB3_ARB_CNTR_SET5_vo_low_lvl_val_shift                        (0)
#define SB3_ARB_CNTR_SET5_vo_cntr_val_set_mask                        (0x80000000)
#define SB3_ARB_CNTR_SET5_vo_cntr_val_mask                            (0x0FFF0000)
#define SB3_ARB_CNTR_SET5_vo_low_lvl_val_mask                         (0x00000FFF)
#define SB3_ARB_CNTR_SET5_vo_cntr_val_set(data)                       (0x80000000&((data)<<31))
#define SB3_ARB_CNTR_SET5_vo_cntr_val(data)                           (0x0FFF0000&((data)<<16))
#define SB3_ARB_CNTR_SET5_vo_low_lvl_val(data)                        (0x00000FFF&(data))
#define SB3_ARB_CNTR_SET5_get_vo_cntr_val_set(data)                   ((0x80000000&(data))>>31)
#define SB3_ARB_CNTR_SET5_get_vo_cntr_val(data)                       ((0x0FFF0000&(data))>>16)
#define SB3_ARB_CNTR_SET5_get_vo_low_lvl_val(data)                    (0x00000FFF&(data))

#define SB3_ARB_CNTR_SET6                                             0x1801c184
#define SB3_ARB_CNTR_SET6_reg_addr                                    "0xB801C184"
#define SB3_ARB_CNTR_SET6_reg                                         0xB801C184
#define SB3_ARB_CNTR_SET6_inst_addr                                   "0x0061"
#define SB3_ARB_CNTR_SET6_inst                                        0x0061
#define SB3_ARB_CNTR_SET6_gdmasub1_cntr_val_set_shift                 (31)
#define SB3_ARB_CNTR_SET6_gdmasub1_cntr_val_shift                     (16)
#define SB3_ARB_CNTR_SET6_gdmasub1_low_lvl_val_shift                  (0)
#define SB3_ARB_CNTR_SET6_gdmasub1_cntr_val_set_mask                  (0x80000000)
#define SB3_ARB_CNTR_SET6_gdmasub1_cntr_val_mask                      (0x0FFF0000)
#define SB3_ARB_CNTR_SET6_gdmasub1_low_lvl_val_mask                   (0x00000FFF)
#define SB3_ARB_CNTR_SET6_gdmasub1_cntr_val_set(data)                 (0x80000000&((data)<<31))
#define SB3_ARB_CNTR_SET6_gdmasub1_cntr_val(data)                     (0x0FFF0000&((data)<<16))
#define SB3_ARB_CNTR_SET6_gdmasub1_low_lvl_val(data)                  (0x00000FFF&(data))
#define SB3_ARB_CNTR_SET6_get_gdmasub1_cntr_val_set(data)             ((0x80000000&(data))>>31)
#define SB3_ARB_CNTR_SET6_get_gdmasub1_cntr_val(data)                 ((0x0FFF0000&(data))>>16)
#define SB3_ARB_CNTR_SET6_get_gdmasub1_low_lvl_val(data)              (0x00000FFF&(data))

#define SB3_ARB_CNTR_SET7                                             0x1801c188
#define SB3_ARB_CNTR_SET7_reg_addr                                    "0xB801C188"
#define SB3_ARB_CNTR_SET7_reg                                         0xB801C188
#define SB3_ARB_CNTR_SET7_inst_addr                                   "0x0062"
#define SB3_ARB_CNTR_SET7_inst                                        0x0062
#define SB3_ARB_CNTR_SET7_gibi_cntr_val_set_shift                     (31)
#define SB3_ARB_CNTR_SET7_gibi_cntr_val_shift                         (16)
#define SB3_ARB_CNTR_SET7_gibi_low_lvl_val_shift                      (0)
#define SB3_ARB_CNTR_SET7_gibi_cntr_val_set_mask                      (0x80000000)
#define SB3_ARB_CNTR_SET7_gibi_cntr_val_mask                          (0x0FFF0000)
#define SB3_ARB_CNTR_SET7_gibi_low_lvl_val_mask                       (0x00000FFF)
#define SB3_ARB_CNTR_SET7_gibi_cntr_val_set(data)                     (0x80000000&((data)<<31))
#define SB3_ARB_CNTR_SET7_gibi_cntr_val(data)                         (0x0FFF0000&((data)<<16))
#define SB3_ARB_CNTR_SET7_gibi_low_lvl_val(data)                      (0x00000FFF&(data))
#define SB3_ARB_CNTR_SET7_get_gibi_cntr_val_set(data)                 ((0x80000000&(data))>>31)
#define SB3_ARB_CNTR_SET7_get_gibi_cntr_val(data)                     ((0x0FFF0000&(data))>>16)
#define SB3_ARB_CNTR_SET7_get_gibi_low_lvl_val(data)                  (0x00000FFF&(data))

#define SB3_ARB_CNTR_SET8                                             0x1801c18c
#define SB3_ARB_CNTR_SET8_reg_addr                                    "0xB801C18C"
#define SB3_ARB_CNTR_SET8_reg                                         0xB801C18C
#define SB3_ARB_CNTR_SET8_inst_addr                                   "0x0063"
#define SB3_ARB_CNTR_SET8_inst                                        0x0063
#define SB3_ARB_CNTR_SET8_memc_cntr_val_set_shift                     (31)
#define SB3_ARB_CNTR_SET8_memc_cntr_val_shift                         (16)
#define SB3_ARB_CNTR_SET8_memc_low_lvl_val_shift                      (0)
#define SB3_ARB_CNTR_SET8_memc_cntr_val_set_mask                      (0x80000000)
#define SB3_ARB_CNTR_SET8_memc_cntr_val_mask                          (0x0FFF0000)
#define SB3_ARB_CNTR_SET8_memc_low_lvl_val_mask                       (0x00000FFF)
#define SB3_ARB_CNTR_SET8_memc_cntr_val_set(data)                     (0x80000000&((data)<<31))
#define SB3_ARB_CNTR_SET8_memc_cntr_val(data)                         (0x0FFF0000&((data)<<16))
#define SB3_ARB_CNTR_SET8_memc_low_lvl_val(data)                      (0x00000FFF&(data))
#define SB3_ARB_CNTR_SET8_get_memc_cntr_val_set(data)                 ((0x80000000&(data))>>31)
#define SB3_ARB_CNTR_SET8_get_memc_cntr_val(data)                     ((0x0FFF0000&(data))>>16)
#define SB3_ARB_CNTR_SET8_get_memc_low_lvl_val(data)                  (0x00000FFF&(data))

#define SB3_ARB_CNTR_SET9                                             0x1801c190
#define SB3_ARB_CNTR_SET9_reg_addr                                    "0xB801C190"
#define SB3_ARB_CNTR_SET9_reg                                         0xB801C190
#define SB3_ARB_CNTR_SET9_inst_addr                                   "0x0064"
#define SB3_ARB_CNTR_SET9_inst                                        0x0064
#define SB3_ARB_CNTR_SET9_gdmasub2_cntr_val_set_shift                 (31)
#define SB3_ARB_CNTR_SET9_gdmasub2_cntr_val_shift                     (16)
#define SB3_ARB_CNTR_SET9_gdmasub2_low_lvl_val_shift                  (0)
#define SB3_ARB_CNTR_SET9_gdmasub2_cntr_val_set_mask                  (0x80000000)
#define SB3_ARB_CNTR_SET9_gdmasub2_cntr_val_mask                      (0x0FFF0000)
#define SB3_ARB_CNTR_SET9_gdmasub2_low_lvl_val_mask                   (0x00000FFF)
#define SB3_ARB_CNTR_SET9_gdmasub2_cntr_val_set(data)                 (0x80000000&((data)<<31))
#define SB3_ARB_CNTR_SET9_gdmasub2_cntr_val(data)                     (0x0FFF0000&((data)<<16))
#define SB3_ARB_CNTR_SET9_gdmasub2_low_lvl_val(data)                  (0x00000FFF&(data))
#define SB3_ARB_CNTR_SET9_get_gdmasub2_cntr_val_set(data)             ((0x80000000&(data))>>31)
#define SB3_ARB_CNTR_SET9_get_gdmasub2_cntr_val(data)                 ((0x0FFF0000&(data))>>16)
#define SB3_ARB_CNTR_SET9_get_gdmasub2_low_lvl_val(data)              (0x00000FFF&(data))

#define SB3_ARB_CNTR_SET10                                            0x1801c194
#define SB3_ARB_CNTR_SET10_reg_addr                                   "0xB801C194"
#define SB3_ARB_CNTR_SET10_reg                                        0xB801C194
#define SB3_ARB_CNTR_SET10_inst_addr                                  "0x0065"
#define SB3_ARB_CNTR_SET10_inst                                       0x0065
#define SB3_ARB_CNTR_SET10_cursor_pricnt_shift                        (0)
#define SB3_ARB_CNTR_SET10_cursor_pricnt_mask                         (0x00000007)
#define SB3_ARB_CNTR_SET10_cursor_pricnt(data)                        (0x00000007&(data))
#define SB3_ARB_CNTR_SET10_get_cursor_pricnt(data)                    (0x00000007&(data))

#define SB3_REQ_CR                                                    0x1801c1a0
#define SB3_REQ_CR_reg_addr                                           "0xB801C1A0"
#define SB3_REQ_CR_reg                                                0xB801C1A0
#define SB3_REQ_CR_inst_addr                                          "0x0068"
#define SB3_REQ_CR_inst                                               0x0068
#define SB3_REQ_CR_max_count_shift                                    (16)
#define SB3_REQ_CR_off_time_shift                                     (0)
#define SB3_REQ_CR_max_count_mask                                     (0x000F0000)
#define SB3_REQ_CR_off_time_mask                                      (0x000000FF)
#define SB3_REQ_CR_max_count(data)                                    (0x000F0000&((data)<<16))
#define SB3_REQ_CR_off_time(data)                                     (0x000000FF&(data))
#define SB3_REQ_CR_get_max_count(data)                                ((0x000F0000&(data))>>16)
#define SB3_REQ_CR_get_off_time(data)                                 (0x000000FF&(data))

#define SB3_ARB_SR1                                                   0x1801c1b0
#define SB3_ARB_SR1_reg_addr                                          "0xB801C1B0"
#define SB3_ARB_SR1_reg                                               0xB801C1B0
#define SB3_ARB_SR1_inst_addr                                         "0x006C"
#define SB3_ARB_SR1_inst                                              0x006C
#define SB3_ARB_SR1_sb_gnt_shift                                      (16)
#define SB3_ARB_SR1_win_latcnt_shift                                  (0)
#define SB3_ARB_SR1_sb_gnt_mask                                       (0x03FF0000)
#define SB3_ARB_SR1_win_latcnt_mask                                   (0x00000FFF)
#define SB3_ARB_SR1_sb_gnt(data)                                      (0x03FF0000&((data)<<16))
#define SB3_ARB_SR1_win_latcnt(data)                                  (0x00000FFF&(data))
#define SB3_ARB_SR1_get_sb_gnt(data)                                  ((0x03FF0000&(data))>>16)
#define SB3_ARB_SR1_get_win_latcnt(data)                              (0x00000FFF&(data))

#define SB3_ARB_SR2                                                   0x1801c1b4
#define SB3_ARB_SR2_reg_addr                                          "0xB801C1B4"
#define SB3_ARB_SR2_reg                                               0xB801C1B4
#define SB3_ARB_SR2_inst_addr                                         "0x006D"
#define SB3_ARB_SR2_inst                                              0x006D
#define SB3_ARB_SR2_low_lvl_ie_shift                                  (16)
#define SB3_ARB_SR2_low_lvl_ip_shift                                  (0)
#define SB3_ARB_SR2_low_lvl_ie_mask                                   (0x01FF0000)
#define SB3_ARB_SR2_low_lvl_ip_mask                                   (0x000001FF)
#define SB3_ARB_SR2_low_lvl_ie(data)                                  (0x01FF0000&((data)<<16))
#define SB3_ARB_SR2_low_lvl_ip(data)                                  (0x000001FF&(data))
#define SB3_ARB_SR2_get_low_lvl_ie(data)                              ((0x01FF0000&(data))>>16)
#define SB3_ARB_SR2_get_low_lvl_ip(data)                              (0x000001FF&(data))
#endif
