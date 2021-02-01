// This file is generated using the spec version 1.39, firmware template version 1.39and SRIF Parser                                                                                source code SVN rev:780                    Version flow no.:1.1.20
#ifndef _PERI_REG_H_INCLUDED_
#define _PERI_REG_H_INCLUDED_

//#define  _PERI_USE_STRUCT
#ifdef _PERI_USE_STRUCT

typedef struct
{
    unsigned int    pdcf:8;
    unsigned int    reserved_0:8;
    unsigned int    pfip:8;
    unsigned int    pfdbe:8;
}GPIO_fcr;

typedef struct
{
    unsigned int    pdf_in:8;
    unsigned int    pdf_out:8;
    unsigned int    reserved_0:8;
    unsigned int    pfbm:8;
}GPIO_fdata;

typedef struct
{
    unsigned int    pdcg:8;
    unsigned int    reserved_0:8;
    unsigned int    pgip:8;
    unsigned int    pgdbe:8;
}GPIO_gcr;

typedef struct
{
    unsigned int    pdg_in:8;
    unsigned int    pdg_out:8;
    unsigned int    reserved_0:8;
    unsigned int    pgbm:8;
}GPIO_gdata;

typedef struct
{
    unsigned int    pdch:8;
    unsigned int    reserved_0:8;
    unsigned int    phip:8;
    unsigned int    phdbe:8;
}GPIO_hcr;

typedef struct
{
    unsigned int    pdh_in:8;
    unsigned int    pdh_out:8;
    unsigned int    reserved_0:8;
    unsigned int    phbm:8;
}GPIO_hdata;

typedef struct
{
    unsigned int    pdck:8;
    unsigned int    reserved_0:8;
    unsigned int    pkip:8;
    unsigned int    pkdbe:8;
}GPIO_kcr;

typedef struct
{
    unsigned int    pdk_in:8;
    unsigned int    pdk_out:8;
    unsigned int    reserved_0:8;
    unsigned int    pkbm:8;
}GPIO_kdata;

typedef struct
{
    unsigned int    pdcm:8;
    unsigned int    reserved_0:8;
    unsigned int    pmip:8;
    unsigned int    pmdbe:8;
}GPIO_mcr;

typedef struct
{
    unsigned int    pdm_in:8;
    unsigned int    pdm_out:8;
    unsigned int    reserved_0:8;
    unsigned int    pmbm:8;
}GPIO_mdata;

typedef struct
{
    unsigned int    pdcn:8;
    unsigned int    reserved_0:8;
    unsigned int    pnip:8;
    unsigned int    pndbe:8;
}GPIO_ncr;

typedef struct
{
    unsigned int    pdn_in:8;
    unsigned int    pdn_out:8;
    unsigned int    reserved_0:8;
    unsigned int    pnbm:8;
}GPIO_ndata;

typedef struct
{
    unsigned int    pdcp:8;
    unsigned int    reserved_0:8;
    unsigned int    ppip:8;
    unsigned int    ppdbe:8;
}GPIO_pcr;

typedef struct
{
    unsigned int    pdp_in:8;
    unsigned int    pdp_out:8;
    unsigned int    reserved_0:8;
    unsigned int    ppbm:8;
}GPIO_pdata;

typedef struct
{
    unsigned int    pdcq:8;
    unsigned int    reserved_0:8;
    unsigned int    pqip:8;
    unsigned int    pqdbe:8;
}GPIO_qcr;

typedef struct
{
    unsigned int    pdq_in:8;
    unsigned int    pdq_out:8;
    unsigned int    reserved_0:8;
    unsigned int    pqbm:8;
}GPIO_qdata;

typedef struct
{
    unsigned int    pdcr:8;
    unsigned int    reserved_0:8;
    unsigned int    prip:8;
    unsigned int    prdbe:8;
}GPIO_rcr;

typedef struct
{
    unsigned int    pdr_in:8;
    unsigned int    pdr_out:8;
    unsigned int    reserved_0:8;
    unsigned int    prbm:8;
}GPIO_rdata;

typedef struct
{
    unsigned int    pdcs:8;
    unsigned int    reserved_0:8;
    unsigned int    psip:8;
    unsigned int    psdbe:8;
}GPIO_scr;

typedef struct
{
    unsigned int    pds_in:8;
    unsigned int    pds_out:8;
    unsigned int    reserved_0:8;
    unsigned int    psbm:8;
}GPIO_sdata;

typedef struct
{
    unsigned int    pdct:8;
    unsigned int    reserved_0:8;
    unsigned int    ptip:8;
    unsigned int    ptdbe:8;
}GPIO_tcr;

typedef struct
{
    unsigned int    pdt_in:8;
    unsigned int    pdt_out:8;
    unsigned int    reserved_0:8;
    unsigned int    ptbm:8;
}GPIO_tdata;

typedef struct
{
    unsigned int    pdcu:8;
    unsigned int    reserved_0:8;
    unsigned int    puip:8;
    unsigned int    pudbe:8;
}GPIO_ucr;

typedef struct
{
    unsigned int    pdu_in:8;
    unsigned int    pdu_out:8;
    unsigned int    reserved_0:8;
    unsigned int    pubm:8;
}GPIO_udata;

typedef struct
{
    unsigned int    pdcv:8;
    unsigned int    reserved_0:8;
    unsigned int    pvip:8;
    unsigned int    pvdbe:8;
}GPIO_vcr;

typedef struct
{
    unsigned int    pdv_in:8;
    unsigned int    pdv_out:8;
    unsigned int    reserved_0:8;
    unsigned int    pvbm:8;
}GPIO_vdata;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    pf7ie:2;
    unsigned int    pf6ie:2;
    unsigned int    pf5ie:2;
    unsigned int    pf4ie:2;
    unsigned int    pf3ie:2;
    unsigned int    pf2ie:2;
    unsigned int    pf1ie:2;
    unsigned int    pf0ie:2;
}GPIO_fimr;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    pg7ie:2;
    unsigned int    pg6ie:2;
    unsigned int    pg5ie:2;
    unsigned int    pg4ie:2;
    unsigned int    pg3ie:2;
    unsigned int    pg2ie:2;
    unsigned int    pg1ie:2;
    unsigned int    pg0ie:2;
}GPIO_gimr;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    ph7ie:2;
    unsigned int    ph6ie:2;
    unsigned int    ph5ie:2;
    unsigned int    ph4ie:2;
    unsigned int    ph3ie:2;
    unsigned int    ph2ie:2;
    unsigned int    ph1ie:2;
    unsigned int    ph0ie:2;
}GPIO_himr;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    pk7ie:2;
    unsigned int    pk6ie:2;
    unsigned int    pk5ie:2;
    unsigned int    pk4ie:2;
    unsigned int    pk3ie:2;
    unsigned int    pk2ie:2;
    unsigned int    pk1ie:2;
    unsigned int    pk0ie:2;
}GPIO_kimr;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    pm7ie:2;
    unsigned int    pm6ie:2;
    unsigned int    pm5ie:2;
    unsigned int    pm4ie:2;
    unsigned int    pm3ie:2;
    unsigned int    pm2ie:2;
    unsigned int    pm1ie:2;
    unsigned int    pm0ie:2;
}GPIO_mimr;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    pn7ie:2;
    unsigned int    pn6ie:2;
    unsigned int    pn5ie:2;
    unsigned int    pn4ie:2;
    unsigned int    pn3ie:2;
    unsigned int    pn2ie:2;
    unsigned int    pn1ie:2;
    unsigned int    pn0ie:2;
}GPIO_nimr;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    pp7ie:2;
    unsigned int    pp6ie:2;
    unsigned int    pp5ie:2;
    unsigned int    pp4ie:2;
    unsigned int    pp3ie:2;
    unsigned int    pp2ie:2;
    unsigned int    pp1ie:2;
    unsigned int    pp0ie:2;
}GPIO_pimr;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    pq7ie:2;
    unsigned int    pq6ie:2;
    unsigned int    pq5ie:2;
    unsigned int    pq4ie:2;
    unsigned int    pq3ie:2;
    unsigned int    pq2ie:2;
    unsigned int    pq1ie:2;
    unsigned int    pq0ie:2;
}GPIO_qimr;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    pr7ie:2;
    unsigned int    pr6ie:2;
    unsigned int    pr5ie:2;
    unsigned int    pr4ie:2;
    unsigned int    pr3ie:2;
    unsigned int    pr2ie:2;
    unsigned int    pr1ie:2;
    unsigned int    pr0ie:2;
}GPIO_rimr;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    ps7ie:2;
    unsigned int    ps6ie:2;
    unsigned int    ps5ie:2;
    unsigned int    ps4ie:2;
    unsigned int    ps3ie:2;
    unsigned int    ps2ie:2;
    unsigned int    ps1ie:2;
    unsigned int    ps0ie:2;
}GPIO_simr;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    pt7ie:2;
    unsigned int    pt6ie:2;
    unsigned int    pt5ie:2;
    unsigned int    pt4ie:2;
    unsigned int    pt3ie:2;
    unsigned int    pt2ie:2;
    unsigned int    pt1ie:2;
    unsigned int    pt0ie:2;
}GPIO_timr;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    pu7ie:2;
    unsigned int    pu6ie:2;
    unsigned int    pu5ie:2;
    unsigned int    pu4ie:2;
    unsigned int    pu3ie:2;
    unsigned int    pu2ie:2;
    unsigned int    pu1ie:2;
    unsigned int    pu0ie:2;
}GPIO_uimr;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    pv7ie:2;
    unsigned int    pv6ie:2;
    unsigned int    pv5ie:2;
    unsigned int    pv4ie:2;
    unsigned int    pv3ie:2;
    unsigned int    pv2ie:2;
    unsigned int    pv1ie:2;
    unsigned int    pv0ie:2;
}GPIO_vimr;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    gpidcb:4;
}GPIO_er;

typedef struct
{
    unsigned int    gpiof7_sel:4;
    unsigned int    gpiof6_sel:4;
    unsigned int    gpiof5_sel:4;
    unsigned int    gpiof4_sel:4;
    unsigned int    gpiof3_sel:4;
    unsigned int    gpiof2_sel:4;
    unsigned int    gpiof1_sel:4;
    unsigned int    gpiof0_sel:4;
}PFS;

typedef struct
{
    unsigned int    gpiog7_sel:4;
    unsigned int    gpiog6_sel:4;
    unsigned int    gpiog5_sel:4;
    unsigned int    gpiog4_sel:4;
    unsigned int    gpiog3_sel:4;
    unsigned int    gpiog2_sel:4;
    unsigned int    gpiog1_sel:4;
    unsigned int    gpiog0_sel:4;
}PGS;

typedef struct
{
    unsigned int    gpioh7_sel:4;
    unsigned int    gpioh6_sel:4;
    unsigned int    gpioh5_sel:4;
    unsigned int    gpioh4_sel:4;
    unsigned int    gpioh3_sel:4;
    unsigned int    gpioh2_sel:4;
    unsigned int    gpioh1_sel:4;
    unsigned int    gpioh0_sel:4;
}PHS;

typedef struct
{
    unsigned int    gpiok7_sel:4;
    unsigned int    gpiok6_sel:4;
    unsigned int    gpiok5_sel:4;
    unsigned int    gpiok4_sel:4;
    unsigned int    gpiok3_sel:4;
    unsigned int    gpiok2_sel:4;
    unsigned int    gpiok1_sel:4;
    unsigned int    gpiok0_sel:4;
}PKS;

typedef struct
{
    unsigned int    gpiom7_sel:4;
    unsigned int    gpiom6_sel:4;
    unsigned int    gpiom5_sel:4;
    unsigned int    gpiom4_sel:4;
    unsigned int    gpiom3_sel:4;
    unsigned int    gpiom2_sel:4;
    unsigned int    gpiom1_sel:4;
    unsigned int    gpiom0_sel:4;
}PMS;

typedef struct
{
    unsigned int    gpion7_sel:4;
    unsigned int    gpion6_sel:4;
    unsigned int    gpion5_sel:4;
    unsigned int    gpion4_sel:4;
    unsigned int    gpion3_sel:4;
    unsigned int    gpion2_sel:4;
    unsigned int    gpion1_sel:4;
    unsigned int    gpion0_sel:4;
}PNS;

typedef struct
{
    unsigned int    gpiop7_sel:4;
    unsigned int    gpiop6_sel:4;
    unsigned int    gpiop5_sel:4;
    unsigned int    gpiop4_sel:4;
    unsigned int    gpiop3_sel:4;
    unsigned int    gpiop2_sel:4;
    unsigned int    gpiop1_sel:4;
    unsigned int    gpiop0_sel:4;
}PPS;

typedef struct
{
    unsigned int    gpioq7_sel:4;
    unsigned int    gpioq6_sel:4;
    unsigned int    gpioq5_sel:4;
    unsigned int    gpioq4_sel:4;
    unsigned int    gpioq3_sel:4;
    unsigned int    gpioq2_sel:4;
    unsigned int    gpioq1_sel:4;
    unsigned int    gpioq0_sel:4;
}PQS;

typedef struct
{
    unsigned int    gpior7_sel:4;
    unsigned int    gpior6_sel:4;
    unsigned int    gpior5_sel:4;
    unsigned int    gpior4_sel:4;
    unsigned int    gpior3_sel:4;
    unsigned int    gpior2_sel:4;
    unsigned int    gpior1_sel:4;
    unsigned int    gpior0_sel:4;
}PRS;

typedef struct
{
    unsigned int    gpios7_sel:4;
    unsigned int    gpios6_sel:4;
    unsigned int    gpios5_sel:4;
    unsigned int    gpios4_sel:4;
    unsigned int    gpios3_sel:4;
    unsigned int    gpios2_sel:4;
    unsigned int    gpios1_sel:4;
    unsigned int    gpios0_sel:4;
}PSS;

typedef struct
{
    unsigned int    gpiot7_sel:4;
    unsigned int    gpiot6_sel:4;
    unsigned int    gpiot5_sel:4;
    unsigned int    gpiot4_sel:4;
    unsigned int    gpiot3_sel:4;
    unsigned int    gpiot2_sel:4;
    unsigned int    gpiot1_sel:4;
    unsigned int    gpiot0_sel:4;
}PTS;

typedef struct
{
    unsigned int    gpiou7_sel:4;
    unsigned int    gpiou6_sel:4;
    unsigned int    gpiou5_sel:4;
    unsigned int    gpiou4_sel:4;
    unsigned int    gpiou3_sel:4;
    unsigned int    gpiou2_sel:4;
    unsigned int    gpiou1_sel:4;
    unsigned int    gpiou0_sel:4;
}PUS;

typedef struct
{
    unsigned int    gpiov7_sel:4;
    unsigned int    gpiov6_sel:4;
    unsigned int    gpiov5_sel:4;
    unsigned int    gpiov4_sel:4;
    unsigned int    gpiov3_sel:4;
    unsigned int    gpiov2_sel:4;
    unsigned int    gpiov1_sel:4;
    unsigned int    gpiov0_sel:4;
}PVS;

typedef struct
{
    unsigned int    pwm_w_db_en:1;
    unsigned int    pwm_db_rsel:1;
    unsigned int    pwm_w_db_wr:1;
    unsigned int    pwm_w_db_mode:1;
    unsigned int    reserved_0:28;
}PWM_db_ctrl;

typedef struct
{
    unsigned int    pwm0l:1;
    unsigned int    pwm0_ck:1;
    unsigned int    pwm0_en:1;
    unsigned int    pwm0_vs_rst_en:1;
    unsigned int    pwm0_dut_8b:1;
    unsigned int    reserved_0:22;
    unsigned int    open_drain_mod_sel:1;
    unsigned int    reserved_1:3;
    unsigned int    pwm_width_sel:1;
}PWM0_ctrl;

typedef struct
{
    unsigned int    pwm0_cnt_mode:1;
    unsigned int    pwm0_ck_sel_hs:1;
    unsigned int    pwm0_ck_sel:1;
    unsigned int    reserved_0:1;
    unsigned int    pwm0_cycle_max:4;
    unsigned int    reserved_1:10;
    unsigned int    pwm0_m:2;
    unsigned int    pwm0_n:12;
}PWM0_timing_ctrl;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    pwm0_dut:12;
    unsigned int    reserved_1:4;
    unsigned int    pwm0_totalcnt:12;
}PWM0_duty_set;

typedef struct
{
    unsigned int    pwm1l:1;
    unsigned int    pwm1_ck:1;
    unsigned int    pwm1_en:1;
    unsigned int    pwm1_vs_rst_en:1;
    unsigned int    pwm1_dut_8b:1;
    unsigned int    reserved_0:22;
    unsigned int    open_drain_mod_sel:1;
    unsigned int    reserved_1:4;
}PWM1_ctrl;

typedef struct
{
    unsigned int    pwm1_cnt_mode:1;
    unsigned int    pwm1_ck_sel_hs:1;
    unsigned int    pwm1_ck_sel:1;
    unsigned int    reserved_0:1;
    unsigned int    pwm1_cycle_max:4;
    unsigned int    reserved_1:10;
    unsigned int    pwm1_m:2;
    unsigned int    pwm1_n:12;
}PWM1_timing_ctrl;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    pwm1_dut:12;
    unsigned int    reserved_1:4;
    unsigned int    pwm1_totalcnt:12;
}PWM1_duty_set;

typedef struct
{
    unsigned int    pwm2l:1;
    unsigned int    pwm2_ck:1;
    unsigned int    pwm2_en:1;
    unsigned int    pwm2_vs_rst_en:1;
    unsigned int    pwm2_dut_8b:1;
    unsigned int    reserved_0:22;
    unsigned int    open_drain_mod_sel:1;
    unsigned int    reserved_1:4;
}PWM2_ctrl;

typedef struct
{
    unsigned int    pwm2_cnt_mode:1;
    unsigned int    pwm2_ck_sel_hs:1;
    unsigned int    pwm2_ck_sel:1;
    unsigned int    reserved_0:1;
    unsigned int    pwm2_cycle_max:4;
    unsigned int    reserved_1:10;
    unsigned int    pwm2_m:2;
    unsigned int    pwm2_n:12;
}PWM2_timing_ctrl;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    pwm2_dut:12;
    unsigned int    reserved_1:4;
    unsigned int    pwm2_totalcnt:12;
}PWM2_duty_set;

typedef struct
{
    unsigned int    pwm3l:1;
    unsigned int    pwm3_ck:1;
    unsigned int    pwm3_en:1;
    unsigned int    pwm3_vs_rst_en:1;
    unsigned int    pwm3_dut_8b:1;
    unsigned int    reserved_0:22;
    unsigned int    open_drain_mod_sel:1;
    unsigned int    reserved_1:4;
}PWM3_ctrl;

typedef struct
{
    unsigned int    pwm3_cnt_mode:1;
    unsigned int    pwm3_ck_sel_hs:1;
    unsigned int    pwm3_ck_sel:1;
    unsigned int    reserved_0:1;
    unsigned int    pwm3_cycle_max:4;
    unsigned int    reserved_1:10;
    unsigned int    pwm3_m:2;
    unsigned int    pwm3_n:12;
}PWM3_timing_ctrl;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    pwm3_dut:12;
    unsigned int    reserved_1:4;
    unsigned int    pwm3_totalcnt:12;
}PWM3_duty_set;

typedef struct
{
    unsigned int    pwm4l:1;
    unsigned int    pwm4_ck:1;
    unsigned int    pwm4_en:1;
    unsigned int    pwm4_vs_rst_en:1;
    unsigned int    pwm4_dut_8b:1;
    unsigned int    reserved_0:22;
    unsigned int    open_drain_mod_sel:1;
    unsigned int    reserved_1:4;
}PWM4_ctrl;

typedef struct
{
    unsigned int    pwm4_cnt_mode:1;
    unsigned int    pwm4_ck_sel_hs:1;
    unsigned int    pwm4_ck_sel:1;
    unsigned int    reserved_0:1;
    unsigned int    pwm4_cycle_max:4;
    unsigned int    reserved_1:10;
    unsigned int    pwm4_m:2;
    unsigned int    pwm4_n:12;
}PWM4_timing_ctrl;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    pwm4_dut:12;
    unsigned int    reserved_1:4;
    unsigned int    pwm4_totalcnt:12;
}PWM4_duty_set;

typedef struct
{
    unsigned int    pwm5l:1;
    unsigned int    pwm5_ck:1;
    unsigned int    pwm5_en:1;
    unsigned int    pwm5_vs_rst_en:1;
    unsigned int    pwm5_dut_8b:1;
    unsigned int    reserved_0:22;
    unsigned int    open_drain_mod_sel:1;
    unsigned int    reserved_1:4;
}PWM5_ctrl;

typedef struct
{
    unsigned int    pwm5_cnt_mode:1;
    unsigned int    pwm5_ck_sel_hs:1;
    unsigned int    pwm5_ck_sel:1;
    unsigned int    reserved_0:1;
    unsigned int    pwm5_cycle_max:4;
    unsigned int    reserved_1:10;
    unsigned int    pwm5_m:2;
    unsigned int    pwm5_n:12;
}PWM5_timing_ctrl;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    pwm5_dut:12;
    unsigned int    reserved_1:4;
    unsigned int    pwm5_totalcnt:12;
}PWM5_duty_set;

typedef struct
{
    unsigned int    pwm6l:1;
    unsigned int    pwm6_ck:1;
    unsigned int    pwm6_en:1;
    unsigned int    pwm6_vs_rst_en:1;
    unsigned int    pwm6_dut_8b:1;
    unsigned int    reserved_0:22;
    unsigned int    open_drain_mod_sel:1;
    unsigned int    reserved_1:4;
}PWM6_ctrl;

typedef struct
{
    unsigned int    pwm6_cnt_mode:1;
    unsigned int    pwm6_ck_sel_hs:1;
    unsigned int    pwm6_ck_sel:1;
    unsigned int    reserved_0:1;
    unsigned int    pwm6_cycle_max:4;
    unsigned int    reserved_1:10;
    unsigned int    pwm6_m:2;
    unsigned int    pwm6_n:12;
}PWM6_timing_ctrl;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    pwm6_dut:12;
    unsigned int    reserved_1:4;
    unsigned int    pwm6_totalcnt:12;
}PWM6_duty_set;

typedef struct
{
    unsigned int    pwm7l:1;
    unsigned int    pwm7_ck:1;
    unsigned int    pwm7_en:1;
    unsigned int    pwm7_vs_rst_en:1;
    unsigned int    pwm7_dut_8b:1;
    unsigned int    reserved_0:22;
    unsigned int    open_drain_mod_sel:1;
    unsigned int    reserved_1:4;
}PWM7_ctrl;

typedef struct
{
    unsigned int    pwm7_cnt_mode:1;
    unsigned int    pwm7_ck_sel_hs:1;
    unsigned int    pwm7_ck_sel:1;
    unsigned int    reserved_0:1;
    unsigned int    pwm7_cycle_max:4;
    unsigned int    reserved_1:10;
    unsigned int    pwm7_m:2;
    unsigned int    pwm7_n:12;
}PWM7_timing_ctrl;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    pwm7_dut:12;
    unsigned int    reserved_1:4;
    unsigned int    pwm7_totalcnt:12;
}PWM7_duty_set;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    rvd_a:3;
    unsigned int    auto_read:1;
    unsigned int    reserved_1:1;
    unsigned int    selvpp:3;
    unsigned int    reserved_2:1;
    unsigned int    op:3;
    unsigned int    key_protect_bit:1;
    unsigned int    reserved_3:1;
    unsigned int    read:1;
    unsigned int    enb:1;
    unsigned int    reserved_4:1;
    unsigned int    b:3;
    unsigned int    reserved_5:3;
    unsigned int    a:5;
}EF_ctrl0;

typedef struct
{
    unsigned int    reserved_0:30;
    unsigned int    mode:1;
    unsigned int    program:1;
}EF_ctrl1;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    auto_read_done:1;
}EF_ctrl_st;

typedef struct
{
    unsigned int    dout:32;
}EF0;

typedef struct
{
    unsigned int    dout:32;
}EF1;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    crc_en:1;
}EF_ctrl_st;

typedef struct
{
    unsigned int    crc_ini:16;
    unsigned int    crc_out:16;
}EF_crc;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    ic_slave_disable:1;
    unsigned int    ic_restart_en:1;
    unsigned int    ic_10bitaddr_master:1;
    unsigned int    ic_10bitaddr_slave:1;
    unsigned int    speed:2;
    unsigned int    master_mode:1;
}IC_con;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    special:1;
    unsigned int    gc_or_start:1;
    unsigned int    ic_tar:10;
}IC_tar;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    ic_sar:10;
}IC_sar;

typedef struct
{
    unsigned int    reserved_0:29;
    unsigned int    ic_hs_mar:3;
}IC_hs_maddr;

typedef struct
{
    unsigned int    reserved_0:23;
    unsigned int    cmd:1;
    unsigned int    dat:8;
}IC_data_cmd;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    ic_ss_scl_hcnt:16;
}IC_ss_scl_hcnt;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    ic_ss_scl_lcnt:16;
}IS_ss_scl_lcnt;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    ic_fs_scl_hcnt:16;
}IC_fs_scl_hcnt;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    ic_fs_scl_lcnt:16;
}IC_fs_scl_lcnt;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    gen_call:1;
    unsigned int    start_det:1;
    unsigned int    stop_det:1;
    unsigned int    activity:1;
    unsigned int    rx_done:1;
    unsigned int    tx_abrt:1;
    unsigned int    rd_req:1;
    unsigned int    tx_empty:1;
    unsigned int    tx_over:1;
    unsigned int    rx_full:1;
    unsigned int    rx_over:1;
    unsigned int    rx_under:1;
}IC_intr_stat;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    m_gen_call:1;
    unsigned int    m_start_det:1;
    unsigned int    m_stop_det:1;
    unsigned int    m_activity:1;
    unsigned int    m_rx_done:1;
    unsigned int    m_tx_abrt:1;
    unsigned int    m_rd_req:1;
    unsigned int    m_tx_empty:1;
    unsigned int    m_tx_over:1;
    unsigned int    m_rx_full:1;
    unsigned int    m_rx_over:1;
    unsigned int    m_rx_under:1;
}IC_intr_mask;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    r_gen_call:1;
    unsigned int    r_start_det:1;
    unsigned int    r_stop_det:1;
    unsigned int    r_activity:1;
    unsigned int    r_rx_done:1;
    unsigned int    r_tx_abrt:1;
    unsigned int    r_rd_req:1;
    unsigned int    r_tx_empty:1;
    unsigned int    r_tx_over:1;
    unsigned int    r_rx_full:1;
    unsigned int    r_rx_over:1;
    unsigned int    r_rx_under:1;
}IC_raw_intr_stat;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    rx_tl:8;
}IC_rx_tl;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    tx_tl:8;
}IC_tx_tl;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    clr_intr:1;
}IC_clr_intr;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    clr_rx_under:1;
}IC_clr_rx_under;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    clr_rx_over:1;
}IC_clr_rx_over;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    clr_tx_over:1;
}IC_clr_tx_over;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    clr_rd_req:1;
}IC_clr_rd_req;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    clr_tx_abrt:1;
}IC_clr_tx_abrt;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    clr_rx_done:1;
}IC_clr_rx_done;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    clr_activity:1;
}IC_clr_activity;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    clr_stop_det:1;
}IC_clr_stop_det;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    clr_start_det:1;
}IC_clr_start_det;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    clr_gen_call:1;
}IC_clr_gen_call;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    enable:1;
}IC_enable;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    rff:1;
    unsigned int    rfne:1;
    unsigned int    tfe:1;
    unsigned int    tfnf:1;
    unsigned int    activity:1;
}IC_status;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    txflr:4;
}IC_txflr;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    rxflr:4;
}IC_rxflr;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    abrt_slvrd_intx:1;
    unsigned int    abrt_slv_arblost:1;
    unsigned int    abrt_slvflush_txfifo:1;
    unsigned int    arb_lost:1;
    unsigned int    arb_master_dis:1;
    unsigned int    abrt_10b_rd_norstrt:1;
    unsigned int    abrt_sbyte_norstrt:1;
    unsigned int    abrt_hs_norstrt:1;
    unsigned int    abrt_sbyte_ackdet:1;
    unsigned int    abrt_hs_ackdet:1;
    unsigned int    abrt_gcall_read:1;
    unsigned int    abrt_gcall_noack:1;
    unsigned int    abrt_txdata_noack:1;
    unsigned int    abrt_10addr2_noack:1;
    unsigned int    abrt_10addr1_noack:1;
    unsigned int    abrt_7b_addr_noack:1;
}IC_tx_abrt_source;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    enable:1;
    unsigned int    start:1;
    unsigned int    done_ie:1;
    unsigned int    done:1;
    unsigned int    valid_len:4;
    unsigned int    reserved_1:3;
    unsigned int    pre_cmd:1;
    unsigned int    pre_data:8;
}IC_pre_data_cmd;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    tx_buffer_depth:8;
    unsigned int    rx_buffer_depth:8;
    unsigned int    add_encoded_params:1;
    unsigned int    has_dma:1;
    unsigned int    intr_io:1;
    unsigned int    hc_count_values:1;
    unsigned int    max_speed_mode:2;
    unsigned int    apb_data_width:2;
}IC_comp_param;

typedef struct
{
    unsigned int    ic_comp_version:32;
}IC_comp_version;

typedef struct
{
    unsigned int    ic_comp_type:32;
}IC_comp_type;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    ic_slave_disable:1;
    unsigned int    ic_restart_en:1;
    unsigned int    ic_10bitaddr_master:1;
    unsigned int    ic_10bitaddr_slave:1;
    unsigned int    speed:2;
    unsigned int    master_mode:1;
}IC_con_1;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    special:1;
    unsigned int    gc_or_start:1;
    unsigned int    ic_tar:10;
}IC_tar_1;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    ic_sar:10;
}IC_sar_1;

typedef struct
{
    unsigned int    reserved_0:29;
    unsigned int    ic_hs_mar:3;
}IC_hs_maddr_1;

typedef struct
{
    unsigned int    reserved_0:23;
    unsigned int    cmd:1;
    unsigned int    dat:8;
}IC_data_cmd_1;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    ic_ss_scl_hcnt:16;
}IC_ss_scl_hcnt_1;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    ic_ss_scl_lcnt:16;
}IC_ss_scl_lcnt_1;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    ic_fs_scl_hcnt:16;
}IC_fs_scl_hcnt_1;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    ic_fs_scl_lcnt:16;
}IC_fs_scl_lcnt_1;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    gen_call:1;
    unsigned int    start_det:1;
    unsigned int    stop_det:1;
    unsigned int    activity:1;
    unsigned int    rx_done:1;
    unsigned int    tx_abrt:1;
    unsigned int    rd_req:1;
    unsigned int    tx_empty:1;
    unsigned int    tx_over:1;
    unsigned int    rx_full:1;
    unsigned int    rx_over:1;
    unsigned int    rx_under:1;
}IC_intr_stat_1;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    m_gen_call:1;
    unsigned int    m_start_det:1;
    unsigned int    m_stop_det:1;
    unsigned int    m_activity:1;
    unsigned int    m_rx_done:1;
    unsigned int    m_tx_abrt:1;
    unsigned int    m_rd_req:1;
    unsigned int    m_tx_empty:1;
    unsigned int    m_tx_over:1;
    unsigned int    m_rx_full:1;
    unsigned int    m_rx_over:1;
    unsigned int    m_rx_under:1;
}IC_intr_mask_1;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    r_gen_call:1;
    unsigned int    r_start_det:1;
    unsigned int    r_stop_det:1;
    unsigned int    r_activity:1;
    unsigned int    r_rx_done:1;
    unsigned int    r_tx_abrt:1;
    unsigned int    r_rd_req:1;
    unsigned int    r_tx_empty:1;
    unsigned int    r_tx_over:1;
    unsigned int    r_rx_full:1;
    unsigned int    r_rx_over:1;
    unsigned int    r_rx_under:1;
}IC_raw_intr_stat_1;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    rx_tl:8;
}IC_rx_tl_1;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    tx_tl:8;
}IC_tx_tl_1;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    clr_intr:1;
}IC_clr_intr_1;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    clr_rx_under:1;
}IC_clr_rx_under_1;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    clr_rx_over:1;
}IC_clr_rx_over_1;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    clr_tx_over:1;
}IC_clr_tx_over_1;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    clr_rd_req:1;
}IC_clr_rd_req_1;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    clr_tx_abrt:1;
}IC_clr_tx_abrt_1;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    clr_rx_done:1;
}IC_clr_rx_done_1;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    clr_activity:1;
}IC_clr_activity_1;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    clr_stop_det:1;
}IC_clr_stop_det_1;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    clr_start_det:1;
}IC_clr_start_det_1;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    clr_gen_call:1;
}IC_clr_gen_call_1;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    enable:1;
}IC_enable_1;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    rff:1;
    unsigned int    rfne:1;
    unsigned int    tfe:1;
    unsigned int    tfnf:1;
    unsigned int    activity:1;
}IC_status_1;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    txflr:4;
}IC_txflr_1;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    rxflr:4;
}IC_rxflr_1;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    abrt_slvrd_intx:1;
    unsigned int    abrt_slv_arblost:1;
    unsigned int    abrt_slvflush_txfifo:1;
    unsigned int    arb_lost:1;
    unsigned int    arb_master_dis:1;
    unsigned int    abrt_10b_rd_norstrt:1;
    unsigned int    abrt_sbyte_norstrt:1;
    unsigned int    abrt_hs_norstrt:1;
    unsigned int    abrt_sbyte_ackdet:1;
    unsigned int    abrt_hs_ackdet:1;
    unsigned int    abrt_gcall_read:1;
    unsigned int    abrt_gcall_noack:1;
    unsigned int    abrt_txdata_noack:1;
    unsigned int    abrt_10addr2_noack:1;
    unsigned int    abrt_10addr1_noack:1;
    unsigned int    abrt_7b_addr_noack:1;
}IC_tx_abrt_source_1;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    enable:1;
    unsigned int    start:1;
    unsigned int    done_ie:1;
    unsigned int    done:1;
    unsigned int    valid_len:4;
    unsigned int    reserved_1:3;
    unsigned int    pre_cmd:1;
    unsigned int    pre_data:8;
}IC_pre_data_cmd_1;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    tx_buffer_depth:8;
    unsigned int    rx_buffer_depth:8;
    unsigned int    add_encoded_params:1;
    unsigned int    has_dma:1;
    unsigned int    intr_io:1;
    unsigned int    hc_count_values:1;
    unsigned int    max_speed_mode:2;
    unsigned int    apb_data_width:2;
}IC_comp_param_1;

typedef struct
{
    unsigned int    ic_comp_version:32;
}IC_comp_version_1;

typedef struct
{
    unsigned int    ic_comp_type:32;
}IC_comp_type_1;

typedef struct
{
    unsigned int    pdca:8;
    unsigned int    reserved_0:8;
    unsigned int    paip:8;
    unsigned int    padbe:8;
}GPIO_acr;

typedef struct
{
    unsigned int    pda_in:8;
    unsigned int    pda_out:8;
    unsigned int    reserved_0:8;
    unsigned int    pabm:8;
}GPIO_adata;

typedef struct
{
    unsigned int    pdcb:8;
    unsigned int    reserved_0:8;
    unsigned int    pbip:8;
    unsigned int    pbdbe:8;
}GPIO_bcr;

typedef struct
{
    unsigned int    pdb_in:8;
    unsigned int    pdb_out:8;
    unsigned int    reserved_0:8;
    unsigned int    pbbm:8;
}GPIO_bdata;

typedef struct
{
    unsigned int    pdcc:8;
    unsigned int    reserved_0:8;
    unsigned int    pcip:8;
    unsigned int    pcdbe:8;
}GPIO_ccr;

typedef struct
{
    unsigned int    pdc_in:8;
    unsigned int    pdc_out:8;
    unsigned int    reserved_0:8;
    unsigned int    pcbm:8;
}GPIO_cdata;

typedef struct
{
    unsigned int    pdcd:8;
    unsigned int    reserved_0:8;
    unsigned int    pdip:8;
    unsigned int    pddbe:8;
}GPIO_dcr;

typedef struct
{
    unsigned int    pdd_in:8;
    unsigned int    pdd_out:8;
    unsigned int    reserved_0:8;
    unsigned int    pdbm:8;
}GPIO_ddata;

typedef struct
{
    unsigned int    pdce:8;
    unsigned int    reserved_0:8;
    unsigned int    peip:8;
    unsigned int    pedbe:8;
}GPIO_ecr;

typedef struct
{
    unsigned int    pde_in:8;
    unsigned int    pde_out:8;
    unsigned int    reserved_0:8;
    unsigned int    pebm:8;
}GPIO_edata;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    gpidcb:4;
}GPIO_er;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    pa7ie:2;
    unsigned int    pa6ie:2;
    unsigned int    pa5ie:2;
    unsigned int    pa4ie:2;
    unsigned int    pa3ie:2;
    unsigned int    pa2ie:2;
    unsigned int    pa1ie:2;
    unsigned int    pa0ie:2;
}GPIO_aimr;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    pb7ie:2;
    unsigned int    pb6ie:2;
    unsigned int    pb5ie:2;
    unsigned int    pb4ie:2;
    unsigned int    pb3ie:2;
    unsigned int    pb2ie:2;
    unsigned int    pb1ie:2;
    unsigned int    pb0ie:2;
}GPIO_bimr;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    pc7ie:2;
    unsigned int    pc6ie:2;
    unsigned int    pc5ie:2;
    unsigned int    pc4ie:2;
    unsigned int    pc3ie:2;
    unsigned int    pc2ie:2;
    unsigned int    pc1ie:2;
    unsigned int    pc0ie:2;
}GPIO_cimr;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    pd7ie:2;
    unsigned int    pd6ie:2;
    unsigned int    pd5ie:2;
    unsigned int    pd4ie:2;
    unsigned int    pd3ie:2;
    unsigned int    pd2ie:2;
    unsigned int    pd1ie:2;
    unsigned int    pd0ie:2;
}GPIO_dimr;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    pe7ie:2;
    unsigned int    pe6ie:2;
    unsigned int    pe5ie:2;
    unsigned int    pe4ie:2;
    unsigned int    pe3ie:2;
    unsigned int    pe2ie:2;
    unsigned int    pe1ie:2;
    unsigned int    pe0ie:2;
}GPIO_eimr;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    gpioa7_sel:2;
    unsigned int    gpioa6_sel:2;
    unsigned int    gpioa5_sel:2;
    unsigned int    gpioa4_sel:2;
    unsigned int    gpioa3_sel:2;
    unsigned int    gpioa2_sel:2;
    unsigned int    gpioa1_sel:2;
    unsigned int    gpioa0_sel:2;
}PAS;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    gpiob7_sel:2;
    unsigned int    gpiob6_sel:2;
    unsigned int    gpiob5_sel:2;
    unsigned int    gpiob4_sel:2;
    unsigned int    gpiob3_sel:2;
    unsigned int    gpiob2_sel:2;
    unsigned int    gpiob1_sel:2;
    unsigned int    gpiob0_sel:2;
}PBS;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    gpioc7_sel:2;
    unsigned int    gpioc6_sel:2;
    unsigned int    gpioc5_sel:2;
    unsigned int    gpioc4_sel:2;
    unsigned int    gpioc3_sel:2;
    unsigned int    gpioc2_sel:2;
    unsigned int    gpioc1_sel:2;
    unsigned int    gpioc0_sel:2;
}PCS;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    gpiod7_sel:2;
    unsigned int    gpiod6_sel:2;
    unsigned int    gpiod5_sel:2;
    unsigned int    gpiod4_sel:2;
    unsigned int    gpiod3_sel:2;
    unsigned int    gpiod2_sel:2;
    unsigned int    gpiod1_sel:2;
    unsigned int    gpiod0_sel:2;
}PDS;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    gpioe7_sel:2;
    unsigned int    gpioe6_sel:2;
    unsigned int    gpioe5_sel:2;
    unsigned int    gpioe4_sel:2;
    unsigned int    gpioe3_sel:2;
    unsigned int    gpioe2_sel:2;
    unsigned int    gpioe1_sel:2;
    unsigned int    gpioe0_sel:2;
}PES;

typedef struct
{
    unsigned int    st_pw0cd0_mask:8;
    unsigned int    st_pw0ocd0_mask:8;
    unsigned int    st_pw0cd0:8;
    unsigned int    st_pw0ocd0:8;
}ST_pwm0_b0;

typedef struct
{
    unsigned int    st_pwm_enable0:1;
    unsigned int    reserved_0:10;
    unsigned int    pwm0csd_mask:5;
    unsigned int    reserved_1:11;
    unsigned int    pwm0csd:5;
}ST_pwm0_ad0;

typedef struct
{
    unsigned int    st_pw1cd1_mask:8;
    unsigned int    st_pw1ocd1_mask:8;
    unsigned int    st_pw1cd1:8;
    unsigned int    st_pw1ocd1:8;
}ST_pwm0_b1;

typedef struct
{
    unsigned int    st_pwm_enable1:1;
    unsigned int    reserved_0:10;
    unsigned int    pwm1csd_mask:5;
    unsigned int    reserved_1:11;
    unsigned int    pwm1csd:5;
}ST_pwm0_ad1;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    rbd:8;
}ST_uart1_rbr;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    thd:8;
}ST_uart1_thr;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    dll:8;
}ST_uart1_dll;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    dlm:8;
}ST_uart1_dlm;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    edssi:1;
    unsigned int    elsi:1;
    unsigned int    etbei:1;
    unsigned int    erbi:1;
}ST_uart1_ier;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    fifo16:2;
    unsigned int    reserved_1:2;
    unsigned int    iid:3;
    unsigned int    ipnd:1;
}ST_uart1_iir;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    rtrg:2;
    unsigned int    reserved_1:2;
    unsigned int    dmam:1;
    unsigned int    tfrst:1;
    unsigned int    rfrst:1;
    unsigned int    efifo:1;
}ST_uart1_fcr;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    dlab:1;
    unsigned int    brk:1;
    unsigned int    eps:2;
    unsigned int    pen:1;
    unsigned int    stp:1;
    unsigned int    wls:2;
}ST_uart1_lcr;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    loop:1;
    unsigned int    reserved_1:2;
    unsigned int    rts:1;
    unsigned int    dtr:1;
}ST_uart1_mcr;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    rfe:1;
    unsigned int    temt:1;
    unsigned int    thre:1;
    unsigned int    bi:1;
    unsigned int    fe:1;
    unsigned int    pe:1;
    unsigned int    oe:1;
    unsigned int    dr:1;
}ST_uart1_lsr;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    dcd:1;
    unsigned int    ri:1;
    unsigned int    dsr:1;
    unsigned int    cts:1;
    unsigned int    reserved_1:3;
    unsigned int    dcts:1;
}UART1_msr;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    scr:8;
}ST_uart1_scr;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    rbd:8;
}ST_uart2_rbr;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    thd:8;
}ST_uart2_thr;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    dll:8;
}ST_uart2_dll;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    dlm:8;
}ST_uart2_dlm;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    edssi:1;
    unsigned int    elsi:1;
    unsigned int    etbei:1;
    unsigned int    erbi:1;
}ST_uart2_ier;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    fifo16:2;
    unsigned int    reserved_1:2;
    unsigned int    iid:3;
    unsigned int    ipnd:1;
}ST_uart2_iir;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    rtrg:2;
    unsigned int    reserved_1:2;
    unsigned int    dmam:1;
    unsigned int    tfrst:1;
    unsigned int    rfrst:1;
    unsigned int    efifo:1;
}ST_uart2_fcr;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    dlab:1;
    unsigned int    brk:1;
    unsigned int    eps:2;
    unsigned int    pen:1;
    unsigned int    stp:1;
    unsigned int    wls:2;
}ST_uart2_lcr;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    loop:1;
    unsigned int    reserved_1:2;
    unsigned int    rts:1;
    unsigned int    dtr:1;
}ST_uart2_mcr;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    rfe:1;
    unsigned int    temt:1;
    unsigned int    thre:1;
    unsigned int    bi:1;
    unsigned int    fe:1;
    unsigned int    pe:1;
    unsigned int    oe:1;
    unsigned int    dr:1;
}ST_uart2_lsr;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    dcd:1;
    unsigned int    ri:1;
    unsigned int    dsr:1;
    unsigned int    cts:1;
    unsigned int    reserved_1:3;
    unsigned int    dcts:1;
}ST_uart2_msr;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    scr:8;
}ST_uart2_scr;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    rbd:8;
}ST_uart3_rbr;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    thd:8;
}ST_uart3_thr;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    dll:8;
}ST_uart3_dll;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    dlm:8;
}ST_uart3_dlm;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    edssi:1;
    unsigned int    elsi:1;
    unsigned int    etbei:1;
    unsigned int    erbi:1;
}ST_uart3_ier;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    fifo16:2;
    unsigned int    reserved_1:2;
    unsigned int    iid:3;
    unsigned int    ipnd:1;
}ST_uart3_iir;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    rtrg:2;
    unsigned int    reserved_1:2;
    unsigned int    dmam:1;
    unsigned int    tfrst:1;
    unsigned int    rfrst:1;
    unsigned int    efifo:1;
}ST_uart3_fcr;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    dlab:1;
    unsigned int    brk:1;
    unsigned int    eps:2;
    unsigned int    pen:1;
    unsigned int    stp:1;
    unsigned int    wls:2;
}ST_uart3_lcr;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    loop:1;
    unsigned int    reserved_1:2;
    unsigned int    rts:1;
    unsigned int    dtr:1;
}ST_uart3_mcr;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    rfe:1;
    unsigned int    temt:1;
    unsigned int    thre:1;
    unsigned int    bi:1;
    unsigned int    fe:1;
    unsigned int    pe:1;
    unsigned int    oe:1;
    unsigned int    dr:1;
}ST_uart3_lsr;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    dcd:1;
    unsigned int    ri:1;
    unsigned int    dsr:1;
    unsigned int    cts:1;
    unsigned int    reserved_1:3;
    unsigned int    dcts:1;
}ST_uart3_msr;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    scr:8;
}ST_uart3_scr;

typedef struct
{
    unsigned int    irrbl:8;
    unsigned int    irrml:8;
    unsigned int    irrdzl:8;
    unsigned int    irrdol:8;
}ST_ir_psr;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    irrdl:6;
    unsigned int    irrrl:8;
    unsigned int    irrsl:8;
}ST_ir_per;

typedef struct
{
    unsigned int    irit:8;
    unsigned int    iroct:8;
    unsigned int    irfd:16;
}ST_ir_sf;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    iriotcdp:16;
}ST_ir_dpir;

typedef struct
{
    unsigned int    irsr:1;
    unsigned int    reserved_0:7;
    unsigned int    irednm:1;
    unsigned int    reserved_1:1;
    unsigned int    iredn:6;
    unsigned int    reserved_2:1;
    unsigned int    raw_fifo_ov:1;
    unsigned int    raw_fifo_val:1;
    unsigned int    raw_en:1;
    unsigned int    mlae:1;
    unsigned int    irie:1;
    unsigned int    irres:1;
    unsigned int    irue:1;
    unsigned int    ircm:1;
    unsigned int    irbme:1;
    unsigned int    irdpm:1;
    unsigned int    irdn:5;
}ST_ir_cr;

typedef struct
{
    unsigned int    irrp:32;
}ST_ir_rp;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    rmt_big:1;
    unsigned int    raw_fifo_ov:1;
    unsigned int    raw_fifo_val:1;
    unsigned int    irrf:1;
    unsigned int    irdvf:1;
}ST_ir_sr;

typedef struct
{
    unsigned int    reserved_0:6;
    unsigned int    write_enable2:1;
    unsigned int    stop_sample:1;
    unsigned int    stop_time:16;
    unsigned int    reserved_1:1;
    unsigned int    write_enable1:1;
    unsigned int    fifo_thr:6;
}ST_ir_raw_ctrl;

typedef struct
{
    unsigned int    dat:32;
}ST_ir_raw_ff;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    cnt:16;
}ST_ir_raw_sample_time;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    val:6;
}ST_ir_raw_wl;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    len:8;
    unsigned int    clk:16;
}ST_ir_raw_deb;

typedef struct
{
    unsigned int    irrbl:8;
    unsigned int    irrml:8;
    unsigned int    irrdzl:8;
    unsigned int    irrdol:8;
}ST_ir_psr_up;

typedef struct
{
    unsigned int    reserved_0:7;
    unsigned int    rc6_in:1;
    unsigned int    irtr:8;
    unsigned int    irrrl:8;
    unsigned int    irrsl:8;
}ST_ir_per_up;

typedef struct
{
    unsigned int    irrp:32;
}ST_ir_rp2;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    rp_num:4;
    unsigned int    reserved_1:3;
    unsigned int    ext_rp_en:1;
}ST_ir_ext_rp_cf;

typedef struct
{
    unsigned int    rp_burst:8;
    unsigned int    rp_silence:8;
    unsigned int    rp_tail_burst:8;
    unsigned int    rp_tail_silence:8;
}ST_ir_ext_rp_timg;

typedef struct
{
    unsigned int    rp_burst:8;
    unsigned int    rp_silence:8;
    unsigned int    rp_tail_burst:8;
    unsigned int    rp_tail_silence:8;
}ST_ir_ext_rp_timg_up;

typedef struct
{
    unsigned int    hw_decode_data0l:32;
}HW_decode_data0_l;

typedef struct
{
    unsigned int    hw_decode_data0h:32;
}HW_decode_data0_h;

typedef struct
{
    unsigned int    decode_mask_data0l:32;
}DECODE_mask_data0_l;

typedef struct
{
    unsigned int    decode_mask_data0h:32;
}DECODE_mask_data0_h;

typedef struct
{
    unsigned int    hw_decode_data1l:32;
}HW_decode_data1_l;

typedef struct
{
    unsigned int    hw_decode_data1h:32;
}HW_decode_data1_h;

typedef struct
{
    unsigned int    decode_mask_data1l:32;
}DECODE_mask_data1_l;

typedef struct
{
    unsigned int    decode_mask_data1h:32;
}DECODE_mask_data1_h;

typedef struct
{
    unsigned int    hw_decode_data2l:32;
}HW_decode_data2_l;

typedef struct
{
    unsigned int    hw_decode_data2h:32;
}HW_decode_data2_h;

typedef struct
{
    unsigned int    decode_mask_data2l:32;
}DECODE_mask_data2_l;

typedef struct
{
    unsigned int    decode_mask_data2h:32;
}DECODE_mask_data2_h;

typedef struct
{
    unsigned int    hw_decode_data3l:32;
}HW_decode_data3_l;

typedef struct
{
    unsigned int    hw_decode_data3h:32;
}HW_decode_data3_h;

typedef struct
{
    unsigned int    decode_mask_data3l:32;
}DECODE_mask_data3_l;

typedef struct
{
    unsigned int    decode_mask_data3h:32;
}DECODE_mask_data3_h;

typedef struct
{
    unsigned int    hw_decode_data4l:32;
}HW_decode_data4_l;

typedef struct
{
    unsigned int    hw_decode_data4h:32;
}HW_decode_data4_h;

typedef struct
{
    unsigned int    decode_mask_data4l:32;
}DECODE_mask_data4_l;

typedef struct
{
    unsigned int    decode_mask_data4h:32;
}DECODE_mask_data4_h;

typedef struct
{
    unsigned int    hw_decode_data5l:32;
}HW_decode_data5_l;

typedef struct
{
    unsigned int    hw_decode_data5h:32;
}HW_decode_data5_h;

typedef struct
{
    unsigned int    decode_mask_data5l:32;
}DECODE_mask_data5_l;

typedef struct
{
    unsigned int    decode_mask_data5h:32;
}DECODE_mask_data5_h;

typedef struct
{
    unsigned int    hw_decode_data6l:32;
}HW_decode_data6_l;

typedef struct
{
    unsigned int    hw_decode_data6h:32;
}HW_decode_data6_h;

typedef struct
{
    unsigned int    decode_mask_data6l:32;
}DECODE_mask_data6_l;

typedef struct
{
    unsigned int    decode_mask_data6h:32;
}DECODE_mask_data6_h;

typedef struct
{
    unsigned int    hw_decode_data7l:32;
}HW_decode_data7_l;

typedef struct
{
    unsigned int    hw_decode_data7h:32;
}HW_decode_data7_h;

typedef struct
{
    unsigned int    decode_mask_data7l:32;
}DECODE_mask_data7_l;

typedef struct
{
    unsigned int    decode_mask_data7h:32;
}DECODE_mask_data7_h;

typedef struct
{
    unsigned int    compare7_enable:1;
    unsigned int    compare6_enable:1;
    unsigned int    compare5_enable:1;
    unsigned int    compare4_enable:1;
    unsigned int    compare3_enable:1;
    unsigned int    compare2_enable:1;
    unsigned int    compare1_enable:1;
    unsigned int    compare0_enable:1;
    unsigned int    int_latchdata:8;
    unsigned int    compare7_int_en:1;
    unsigned int    compare6_int_en:1;
    unsigned int    compare5_int_en:1;
    unsigned int    compare4_int_en:1;
    unsigned int    compare3_int_en:1;
    unsigned int    compare2_int_en:1;
    unsigned int    compare1_int_en:1;
    unsigned int    compare0_int_en:1;
    unsigned int    compare7_int_status:1;
    unsigned int    compare6_int_status:1;
    unsigned int    compare5_int_status:1;
    unsigned int    compare4_int_status:1;
    unsigned int    compare3_int_status:1;
    unsigned int    compare2_int_status:1;
    unsigned int    compare1_int_status:1;
    unsigned int    compare0_int_status:1;
}INT_ctrl;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    test_mode_en:1;
}TEST_mode_ctrl;

typedef struct
{
    unsigned int    test_mode_datal:32;
}TEST_mode_data0;

typedef struct
{
    unsigned int    test_mode_datah:32;
}TEST_mode_data1;

typedef struct
{
    unsigned int    pad0_active:1;
    unsigned int    reserved_0:7;
    unsigned int    pad0_thred:8;
    unsigned int    pad0_sw:4;
    unsigned int    reserved_1:3;
    unsigned int    pad0_ctrl:1;
    unsigned int    adc_val0:8;
}ST_pad0;

typedef struct
{
    unsigned int    pad1_active:1;
    unsigned int    reserved_0:7;
    unsigned int    pad1_thred:8;
    unsigned int    pad1_sw:4;
    unsigned int    reserved_1:3;
    unsigned int    pad1_ctrl:1;
    unsigned int    adc_val1:8;
}ST_pad1;

typedef struct
{
    unsigned int    pad2_active:1;
    unsigned int    reserved_0:7;
    unsigned int    pad2_thred:8;
    unsigned int    pad2_sw:4;
    unsigned int    reserved_1:3;
    unsigned int    pad2_ctrl:1;
    unsigned int    adc_val2:8;
}ST_pad2;

typedef struct
{
    unsigned int    pad3_active:1;
    unsigned int    reserved_0:7;
    unsigned int    pad3_thred:8;
    unsigned int    pad3_sw:4;
    unsigned int    reserved_1:3;
    unsigned int    pad3_ctrl:1;
    unsigned int    adc_val3:8;
}ST_pad3;

typedef struct
{
    unsigned int    pad4_active:1;
    unsigned int    reserved_0:7;
    unsigned int    pad4_thred:8;
    unsigned int    pad4_sw:4;
    unsigned int    reserved_1:3;
    unsigned int    pad4_ctrl:1;
    unsigned int    adc_val4:8;
}ST_pad4;

typedef struct
{
    unsigned int    pad5_active:1;
    unsigned int    reserved_0:7;
    unsigned int    pad5_thred:8;
    unsigned int    pad5_sw:4;
    unsigned int    reserved_1:3;
    unsigned int    pad5_ctrl:1;
    unsigned int    adc_val5:8;
}ST_pad5;

typedef struct
{
    unsigned int    pad6_active:1;
    unsigned int    reserved_0:7;
    unsigned int    pad6_thred:8;
    unsigned int    pad6_sw:4;
    unsigned int    reserved_1:3;
    unsigned int    pad6_ctrl:1;
    unsigned int    adc_val6:8;
}ST_pad6;

typedef struct
{
    unsigned int    pad7_active:1;
    unsigned int    reserved_0:7;
    unsigned int    pad7_thred:8;
    unsigned int    pad7_sw:4;
    unsigned int    reserved_1:3;
    unsigned int    pad7_ctrl:1;
    unsigned int    adc_val7:8;
}ST_pad7;

typedef struct
{
    unsigned int    sel_wait:4;
    unsigned int    sel_adc_ck:4;
    unsigned int    debounce_cnt:4;
    unsigned int    reserved_0:4;
    unsigned int    dout_test_in:8;
    unsigned int    reserved_1:6;
    unsigned int    test_en:1;
    unsigned int    enable:1;
}ST_lsadc_ctrl;

typedef struct
{
    unsigned int    irq_en:8;
    unsigned int    pad_cnt:4;
    unsigned int    adc_busy:1;
    unsigned int    reserved_0:2;
    unsigned int    pad_ctrl:5;
    unsigned int    reserved_1:4;
    unsigned int    pad7_status:1;
    unsigned int    pad6_status:1;
    unsigned int    pad5_status:1;
    unsigned int    pad4_status:1;
    unsigned int    pad3_status:1;
    unsigned int    pad2_status:1;
    unsigned int    pad1_status:1;
    unsigned int    pad0_status:1;
}ST_lsadc_status;

typedef struct
{
    unsigned int    reserved_0:14;
    unsigned int    jd_sbias:2;
    unsigned int    reserved_1:2;
    unsigned int    jd_adsbias:2;
    unsigned int    reserved_2:3;
    unsigned int    jd_svr:1;
    unsigned int    reserved_3:3;
    unsigned int    jd_adcksel:1;
    unsigned int    reserved_4:3;
    unsigned int    jd_power:1;
}ST_lsadc_analog_ctrl;

typedef struct
{
    unsigned int    level_0_start_val:8;
    unsigned int    level_0_end_val:8;
    unsigned int    block0en:1;
    unsigned int    reserved_0:13;
    unsigned int    int_en0:1;
    unsigned int    int_pending_bit0:1;
}LSADC_pad5_level_set0;

typedef struct
{
    unsigned int    level_1_start_val:8;
    unsigned int    level_1_end_val:8;
    unsigned int    block1en:1;
    unsigned int    reserved_0:13;
    unsigned int    int_en1:1;
    unsigned int    int_pending_bit1:1;
}LSADC_pad5_level_set1;

typedef struct
{
    unsigned int    level_2_start_val:8;
    unsigned int    level_2_end_val:8;
    unsigned int    block2en:1;
    unsigned int    reserved_0:13;
    unsigned int    int_en2:1;
    unsigned int    int_pending_bit2:1;
}LSADC_pad5_level_set2;

typedef struct
{
    unsigned int    level_3_start_val:8;
    unsigned int    level_3_end_val:8;
    unsigned int    block3en:1;
    unsigned int    reserved_0:13;
    unsigned int    int_en3:1;
    unsigned int    int_pending_bit3:1;
}LSADC_pad5_level_set3;

typedef struct
{
    unsigned int    level_4_start_val:8;
    unsigned int    level_4_end_val:8;
    unsigned int    block4en:1;
    unsigned int    reserved_0:13;
    unsigned int    int_en4:1;
    unsigned int    int_pending_bit4:1;
}LSADC_pad5_level_set4;

typedef struct
{
    unsigned int    level_5_start_val:8;
    unsigned int    level_5_end_val:8;
    unsigned int    block5en:1;
    unsigned int    reserved_0:13;
    unsigned int    int_en5:1;
    unsigned int    int_pending_bit5:1;
}LSADC_pad5_level_set5;

typedef struct
{
    unsigned int    level_6_start_val:8;
    unsigned int    level_6_end_val:8;
    unsigned int    block6en:1;
    unsigned int    reserved_0:13;
    unsigned int    int_en6:1;
    unsigned int    int_pending_bit6:1;
}LSADC_pad5_level_set6;

typedef struct
{
    unsigned int    level_7_start_val:8;
    unsigned int    level_7_end_val:8;
    unsigned int    block7en:1;
    unsigned int    reserved_0:13;
    unsigned int    int_en7:1;
    unsigned int    int_pending_bit7:1;
}LSADC_pad5_level_set7;

typedef struct
{
    unsigned int    level_0_start_val:8;
    unsigned int    level_0_end_val:8;
    unsigned int    block0en:1;
    unsigned int    reserved_0:13;
    unsigned int    int_en0:1;
    unsigned int    int_pending_bit0:1;
}LSADC_pad6_level_set0;

typedef struct
{
    unsigned int    level_1_start_val:8;
    unsigned int    level_1_end_val:8;
    unsigned int    block1en:1;
    unsigned int    reserved_0:13;
    unsigned int    int_en1:1;
    unsigned int    int_pending_bit1:1;
}LSADC_pad6_level_set1;

typedef struct
{
    unsigned int    level_2_start_val:8;
    unsigned int    level_2_end_val:8;
    unsigned int    block2en:1;
    unsigned int    reserved_0:13;
    unsigned int    int_en2:1;
    unsigned int    int_pending_bit2:1;
}LSADC_pad6_level_set2;

typedef struct
{
    unsigned int    level_3_start_val:8;
    unsigned int    level_3_end_val:8;
    unsigned int    block3en:1;
    unsigned int    reserved_0:13;
    unsigned int    int_en3:1;
    unsigned int    int_pending_bit3:1;
}LSADC_pad6_level_set3;

typedef struct
{
    unsigned int    level_4_start_val:8;
    unsigned int    level_4_end_val:8;
    unsigned int    block4en:1;
    unsigned int    reserved_0:13;
    unsigned int    int_en4:1;
    unsigned int    int_pending_bit4:1;
}LSADC_pad6_level_set4;

typedef struct
{
    unsigned int    level_5_start_val:8;
    unsigned int    level_5_end_val:8;
    unsigned int    block5en:1;
    unsigned int    reserved_0:13;
    unsigned int    int_en5:1;
    unsigned int    int_pending_bit5:1;
}LSADC_pad6_level_set5;

typedef struct
{
    unsigned int    level_6_start_val:8;
    unsigned int    level_6_end_val:8;
    unsigned int    block6en:1;
    unsigned int    reserved_0:13;
    unsigned int    int_en6:1;
    unsigned int    int_pending_bit6:1;
}LSADC_pad6_level_set6;

typedef struct
{
    unsigned int    level_7_start_val:8;
    unsigned int    level_7_end_val:8;
    unsigned int    block7en:1;
    unsigned int    reserved_0:13;
    unsigned int    int_en7:1;
    unsigned int    int_pending_bit7:1;
}LSADC_pad6_level_set7;

typedef struct
{
    unsigned int    level_0_start_val:8;
    unsigned int    level_0_end_val:8;
    unsigned int    block0en:1;
    unsigned int    reserved_0:13;
    unsigned int    int_en0:1;
    unsigned int    int_pending_bit0:1;
}LSADC_pad7_level_set0;

typedef struct
{
    unsigned int    level_1_start_val:8;
    unsigned int    level_1_end_val:8;
    unsigned int    block1en:1;
    unsigned int    reserved_0:13;
    unsigned int    int_en1:1;
    unsigned int    int_pending_bit1:1;
}LSADC_pad7_level_set1;

typedef struct
{
    unsigned int    level_2_start_val:8;
    unsigned int    level_2_end_val:8;
    unsigned int    block2en:1;
    unsigned int    reserved_0:13;
    unsigned int    int_en2:1;
    unsigned int    int_pending_bit2:1;
}LSADC_pad7_level_set2;

typedef struct
{
    unsigned int    level_3_start_val:8;
    unsigned int    level_3_end_val:8;
    unsigned int    block3en:1;
    unsigned int    reserved_0:13;
    unsigned int    int_en3:1;
    unsigned int    int_pending_bit3:1;
}LSADC_pad7_level_set3;

typedef struct
{
    unsigned int    level_4_start_val:8;
    unsigned int    level_4_end_val:8;
    unsigned int    block4en:1;
    unsigned int    reserved_0:13;
    unsigned int    int_en4:1;
    unsigned int    int_pending_bit4:1;
}LSADC_pad7_level_set4;

typedef struct
{
    unsigned int    level_5_start_val:8;
    unsigned int    level_5_end_val:8;
    unsigned int    block5en:1;
    unsigned int    reserved_0:13;
    unsigned int    int_en5:1;
    unsigned int    int_pending_bit5:1;
}LSADC_pad7_level_set5;

typedef struct
{
    unsigned int    level_6_start_val:8;
    unsigned int    level_6_end_val:8;
    unsigned int    block6en:1;
    unsigned int    reserved_0:13;
    unsigned int    int_en6:1;
    unsigned int    int_pending_bit6:1;
}LSADC_pad7_level_set6;

typedef struct
{
    unsigned int    level_7_start_val:8;
    unsigned int    level_7_end_val:8;
    unsigned int    block7en:1;
    unsigned int    reserved_0:13;
    unsigned int    int_en7:1;
    unsigned int    int_pending_bit7:1;
}LSADC_pad7_level_set7;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    adc_value5latch:8;
    unsigned int    int_latchstatus:8;
}LSADC_int_pad5;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    adc_value6latch:8;
    unsigned int    int_latchstatus:8;
}LSADC_int_pad6;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    adc_value7latch:8;
    unsigned int    int_latchstatus:8;
}LSADC_int_pad7;

typedef struct
{
    unsigned int    range_23_0:24;
    unsigned int    reserved_0:8;
}ST_tmr0_dr;

typedef struct
{
    unsigned int    value_23_0:24;
    unsigned int    reserved_0:7;
    unsigned int    tcip:1;
}ST_tmr0_vr;

typedef struct
{
    unsigned int    en:1;
    unsigned int    mode:1;
    unsigned int    tc0ie:1;
    unsigned int    reserved_0:29;
}ST_tmr0_cr;

typedef struct
{
    unsigned int    df0_15_0:16;
    unsigned int    reserved_0:16;
}ST_tmr0_dbr;

typedef struct
{
    unsigned int    range_23_0:24;
    unsigned int    reserved_0:8;
}ST_tmr1_dr;

typedef struct
{
    unsigned int    value_23_0:24;
    unsigned int    reserved_0:7;
    unsigned int    tcip:1;
}ST_tmr1_vr;

typedef struct
{
    unsigned int    en:1;
    unsigned int    mode:1;
    unsigned int    tc1ie:1;
    unsigned int    reserved_0:29;
}ST_tmr1_cr;

typedef struct
{
    unsigned int    df1_15_0:16;
    unsigned int    reserved_0:16;
}ST_tmr1_dbr;

typedef struct
{
    unsigned int    range_23_0:24;
    unsigned int    reserved_0:8;
}ST_tmr2_dr;

typedef struct
{
    unsigned int    value_23_0:24;
    unsigned int    reserved_0:7;
    unsigned int    tcip:1;
}ST_tmr2_vr;

typedef struct
{
    unsigned int    en:1;
    unsigned int    mode:1;
    unsigned int    tc2ie:1;
    unsigned int    reserved_0:29;
}ST_tmr2_cr;

typedef struct
{
    unsigned int    df2_15_0:16;
    unsigned int    reserved_0:16;
}ST_tmr2_dbr;

typedef struct
{
    unsigned int    range_23_0:24;
    unsigned int    reserved_0:8;
}ST_tmr3_dr;

typedef struct
{
    unsigned int    value_23_0:24;
    unsigned int    reserved_0:7;
    unsigned int    tcip:1;
}ST_tmr3_vr;

typedef struct
{
    unsigned int    en:1;
    unsigned int    mode:1;
    unsigned int    tc3ie:1;
    unsigned int    reserved_0:29;
}ST_tmr3_cr;

typedef struct
{
    unsigned int    df3_15_0:16;
    unsigned int    reserved_0:16;
}ST_tmr3_dbr;

typedef struct
{
    unsigned int    range_23_0:24;
    unsigned int    reserved_0:8;
}ST_tmr4_dr;

typedef struct
{
    unsigned int    value_23_0:24;
    unsigned int    reserved_0:7;
    unsigned int    tcip:1;
}ST_tmr4_vr;

typedef struct
{
    unsigned int    en:1;
    unsigned int    mode:1;
    unsigned int    tc4ie:1;
    unsigned int    reserved_0:29;
}ST_tmr4_cr;

typedef struct
{
    unsigned int    df4_15_0:16;
    unsigned int    reserved_0:16;
}ST_tmr4_dbr;

typedef struct
{
    unsigned int    range_23_0:24;
    unsigned int    reserved_0:8;
}ST_tmr5_dr;

typedef struct
{
    unsigned int    value_23_0:24;
    unsigned int    reserved_0:7;
    unsigned int    tcip:1;
}ST_tmr5_vr;

typedef struct
{
    unsigned int    en:1;
    unsigned int    mode:1;
    unsigned int    tc5ie:1;
    unsigned int    reserved_0:29;
}ST_tmr5_cr;

typedef struct
{
    unsigned int    df5_15_0:16;
    unsigned int    reserved_0:16;
}ST_tmr5_dbr;

typedef struct
{
    unsigned int    range_23_0:24;
    unsigned int    reserved_0:8;
}ST_tmr6_dr;

typedef struct
{
    unsigned int    value_23_0:24;
    unsigned int    reserved_0:7;
    unsigned int    tcip:1;
}ST_tmr6_vr;

typedef struct
{
    unsigned int    en:1;
    unsigned int    mode:1;
    unsigned int    tc6ie:1;
    unsigned int    reserved_0:29;
}ST_tmr6_cr;

typedef struct
{
    unsigned int    df6_15_0:16;
    unsigned int    reserved_0:16;
}ST_tmr6_dbr;

typedef struct
{
    unsigned int    range_23_0:24;
    unsigned int    reserved_0:8;
}ST_tmr7_dr;

typedef struct
{
    unsigned int    value_23_0:24;
    unsigned int    reserved_0:7;
    unsigned int    tcip:1;
}ST_tmr7_vr;

typedef struct
{
    unsigned int    en:1;
    unsigned int    mode:1;
    unsigned int    tc0ie:1;
    unsigned int    reserved_0:29;
}ST_tmr7_cr;

typedef struct
{
    unsigned int    df0_15_0:16;
    unsigned int    reserved_0:16;
}ST_tmr7_dbr;

typedef struct
{
    unsigned int    ovsel:4;
    unsigned int    reserved_0:9;
    unsigned int    dummy18011700_18_12:7;
    unsigned int    reserved_1:3;
    unsigned int    test_en:1;
    unsigned int    reserved_2:4;
    unsigned int    dummy18011700_3:1;
    unsigned int    pwr_sel:1;
    unsigned int    trig_reset:1;
    unsigned int    enable:1;
}ST_wr_cr;

typedef struct
{
    unsigned int    wdt:16;
    unsigned int    reserved_0:14;
    unsigned int    pause:1;
    unsigned int    wdt_clear:1;
}ST_wr_tr;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    wdc_3_0:4;
    unsigned int    wds:16;
}ST_wr_mr;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    cpu_ack:1;
    unsigned int    int_ack:1;
    unsigned int    wdog_cnt_ovs:1;
    unsigned int    reserved_1:4;
}ST_rec_ic_st_cf;

typedef struct
{
    unsigned int    data:32;
}ST_rec_data0;

typedef struct
{
    unsigned int    data:32;
}ST_rec_data1;

typedef struct
{
    unsigned int    data:32;
}ST_rec_data2;

typedef struct
{
    unsigned int    data:32;
}ST_rec_data3;

typedef struct
{
    unsigned int    data:32;
}ST_rec_data4;

typedef struct
{
    unsigned int    data:32;
}ST_rec_data5;

typedef struct
{
    unsigned int    data:32;
}ST_rec_data6;

typedef struct
{
    unsigned int    data:32;
}ST_rec_data7;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    cmderr_ie:1;
    unsigned int    timeout_en:1;
    unsigned int    debounce_mode:2;
    unsigned int    timeout_ie:1;
    unsigned int    retime_m:3;
}ST_i2c_cr;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    cmderr:1;
    unsigned int    reserved_1:2;
    unsigned int    finish:1;
    unsigned int    timeout:1;
    unsigned int    reserved_2:3;
}ST_i2c_sr;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    timeout_val:8;
}ST_i2c_tr;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    edid_address:3;
    unsigned int    finish_int_en:1;
    unsigned int    ddc1_force:1;
    unsigned int    ddc2b_force:1;
    unsigned int    edid_srwen:1;
    unsigned int    edid_en:1;
}ST_edid_cr;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    ddc1_vcount:8;
}ST_ddc_vcr;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    edid_sadr:8;
}ST_edid_imswsar;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    edid_eadr:8;
}ST_edid_imswear;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    edidmode:1;
    unsigned int    edidsubaddress:1;
    unsigned int    edidstop:1;
    unsigned int    reserved_1:2;
    unsigned int    edidsubaddress_ie:1;
    unsigned int    edidstop_ie:1;
}ST_edid_ir;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    edidap:8;
}ST_ddc_sir;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    ediddp:8;
}ST_ddc_sap;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    bist_fail:1;
    unsigned int    bist_done:1;
    unsigned int    reserved_1:2;
    unsigned int    bist_rstn:1;
    unsigned int    bist_mode:1;
}ST_ddc_bistcr;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    segpt_latie:1;
    unsigned int    reserved_1:6;
    unsigned int    sgid_en:1;
}ST_ddc_scr;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    sgid_address:7;
    unsigned int    sgid_dtrden:1;
}ST_ddc_ssar;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    segpt_latched:1;
    unsigned int    seg_pt:7;
}ST_ddc_spr;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    special_mode:1;
    unsigned int    doffpt_reset:1;
    unsigned int    diffpt_reset:1;
    unsigned int    ciid_en:1;
}ST_ddc_sfcr;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    ciid_address:7;
    unsigned int    cirws_current:1;
}ST_ddc_sfsar;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    ciiddp:8;
}ST_ddc_sfdr;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    cirws_2nd:1;
    unsigned int    cirws_1st:1;
    unsigned int    cippt_2nd:1;
    unsigned int    cispt_2nd:1;
    unsigned int    cippt_1st:1;
    unsigned int    cispt_1st:1;
}ST_ddc_sfbsr;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    ffdi_dlen:5;
}ST_ddc_sfiblr;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    diff_wpt:4;
    unsigned int    diff_rpt:4;
}ST_ddc_sfibrwpr;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    diffstop_pt:4;
}ST_ddc_sfibswpr;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    ffdo_dlen:5;
}ST_ddc_sfobsr;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    doff_wpt:4;
    unsigned int    doff_rpt:4;
}ST_ddc_sfobrwpr;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    ffdouf_st:1;
    unsigned int    ffdiof_st:1;
    unsigned int    ffdonf_st:1;
    unsigned int    ffdoet_st:1;
    unsigned int    ffdifu_st:1;
    unsigned int    ffdine_st:1;
    unsigned int    reserved_1:2;
}ST_ddc_sfsr;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    ffdouf_ie:1;
    unsigned int    ffdiof_ie:1;
    unsigned int    ffdonf_ie:1;
    unsigned int    ffdoet_ie:1;
    unsigned int    ffdifu_ie:1;
    unsigned int    ffdine_ie:1;
    unsigned int    cippt_ie:1;
    unsigned int    cispt_ie:1;
}ST_ddc_sfir;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    cmdfsm_st:8;
}ST_ddc_fsms;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    cmderr_ie:1;
    unsigned int    timeout_en:1;
    unsigned int    debounce_mode:2;
    unsigned int    timeout_ie:1;
    unsigned int    retime_m:3;
}ST_i2c_cr_2;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    cmderr:1;
    unsigned int    reserved_1:2;
    unsigned int    finish:1;
    unsigned int    timeout:1;
    unsigned int    reserved_2:3;
}ST_i2c_sr_2;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    timeout_val:8;
}ST_i2c_tr_2;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    edid_address:3;
    unsigned int    finish_int_en:1;
    unsigned int    ddc1_force:1;
    unsigned int    ddc2b_force:1;
    unsigned int    edid_srwen:1;
    unsigned int    edid_en:1;
}ST_edid_cr_2;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    ddc1_vcount:8;
}ST_ddc_vcr_2;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    edid_sadr:8;
}ST_edid_imswsar_2;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    edid_eadr:8;
}ST_edid_imswear_2;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    edidmode:1;
    unsigned int    edidsubaddress:1;
    unsigned int    edidstop:1;
    unsigned int    reserved_1:2;
    unsigned int    edidsubaddress_ie:1;
    unsigned int    edidstop_ie:1;
}ST_edid_ir_2;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    edidap:8;
}ST_ddc_sir_2;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    ediddp:8;
}ST_ddc_sap_2;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    bist_fail:1;
    unsigned int    bist_done:1;
    unsigned int    reserved_1:2;
    unsigned int    bist_rstn:1;
    unsigned int    bist_mode:1;
}ST_ddc_bistcr_2;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    segpt_latie:1;
    unsigned int    reserved_1:6;
    unsigned int    sgid_en:1;
}ST_ddc_scr_2;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    sgid_address:7;
    unsigned int    sgid_dtrden:1;
}ST_ddc_ssar_2;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    segpt_latched:1;
    unsigned int    seg_pt:7;
}ST_ddc_spr_2;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    special_mode:1;
    unsigned int    doffpt_reset:1;
    unsigned int    diffpt_reset:1;
    unsigned int    ciid_en:1;
}ST_ddc_sfcr_2;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    ciid_address:7;
    unsigned int    cirws_current:1;
}ST_ddc_sfsar_2;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    ciiddp:8;
}ST_ddc_sfdr_2;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    cirws_2nd:1;
    unsigned int    cirws_1st:1;
    unsigned int    cippt_2nd:1;
    unsigned int    cispt_2nd:1;
    unsigned int    cippt_1st:1;
    unsigned int    cispt_1st:1;
}ST_ddc_sfbsr_2;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    ffdi_dlen:5;
}ST_ddc_sfiblr_2;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    diff_wpt:4;
    unsigned int    diff_rpt:4;
}ST_ddc_sfibrwpr_2;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    diffstop_pt:4;
}ST_ddc_sfibswpr_2;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    ffdo_dlen:5;
}ST_ddc_sfobsr_2;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    doff_wpt:4;
    unsigned int    doff_rpt:4;
}ST_ddc_sfobrwpr_2;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    ffdouf_st:1;
    unsigned int    ffdiof_st:1;
    unsigned int    ffdonf_st:1;
    unsigned int    ffdoet_st:1;
    unsigned int    ffdifu_st:1;
    unsigned int    ffdine_st:1;
    unsigned int    reserved_1:2;
}ST_ddc_sfsr_2;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    ffdouf_ie:1;
    unsigned int    ffdiof_ie:1;
    unsigned int    ffdonf_ie:1;
    unsigned int    ffdoet_ie:1;
    unsigned int    ffdifu_ie:1;
    unsigned int    ffdine_ie:1;
    unsigned int    cippt_ie:1;
    unsigned int    cispt_ie:1;
}ST_ddc_sfir_2;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    cmdfsm_st:8;
}ST_ddc_fsms_2;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    cmderr_ie:1;
    unsigned int    timeout_en:1;
    unsigned int    debounce_mode:2;
    unsigned int    timeout_ie:1;
    unsigned int    retime_m:3;
}ST_i2c_cr_3;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    cmderr:1;
    unsigned int    reserved_1:2;
    unsigned int    finish:1;
    unsigned int    timeout:1;
    unsigned int    reserved_2:3;
}ST_i2c_sr_3;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    timeout_val:8;
}ST_i2c_tr_3;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    edid_address:3;
    unsigned int    finish_int_en:1;
    unsigned int    ddc1_force:1;
    unsigned int    ddc2b_force:1;
    unsigned int    edid_srwen:1;
    unsigned int    edid_en:1;
}ST_edid_cr_3;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    ddc1_vcount:8;
}ST_ddc_vcr_3;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    edid_sadr:8;
}ST_edid_imswsar_3;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    edid_eadr:8;
}ST_edid_imswear_3;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    edidmode:1;
    unsigned int    edidsubaddress:1;
    unsigned int    edidstop:1;
    unsigned int    reserved_1:2;
    unsigned int    edidsubaddress_ie:1;
    unsigned int    edidstop_ie:1;
}ST_edid_ir_3;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    edidap:8;
}ST_ddc_sir_3;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    ediddp:8;
}ST_ddc_sap_3;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    bist_fail:1;
    unsigned int    bist_done:1;
    unsigned int    reserved_1:2;
    unsigned int    bist_rstn:1;
    unsigned int    bist_mode:1;
}ST_ddc_bistcr_3;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    segpt_latie:1;
    unsigned int    reserved_1:6;
    unsigned int    sgid_en:1;
}ST_ddc_scr_3;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    sgid_address:7;
    unsigned int    sgid_dtrden:1;
}ST_ddc_ssar_3;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    segpt_latched:1;
    unsigned int    seg_pt:7;
}ST_ddc_spr_3;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    special_mode:1;
    unsigned int    doffpt_reset:1;
    unsigned int    diffpt_reset:1;
    unsigned int    ciid_en:1;
}ST_ddc_sfcr_3;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    ciid_address:7;
    unsigned int    cirws_current:1;
}ST_ddc_sfsar_3;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    ciiddp:8;
}ST_ddc_sfdr_3;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    cirws_2nd:1;
    unsigned int    cirws_1st:1;
    unsigned int    cippt_2nd:1;
    unsigned int    cispt_2nd:1;
    unsigned int    cippt_1st:1;
    unsigned int    cispt_1st:1;
}ST_ddc_sfbsr_3;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    ffdi_dlen:5;
}ST_ddc_sfiblr_3;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    diff_wpt:4;
    unsigned int    diff_rpt:4;
}ST_ddc_sfibrwpr_3;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    diffstop_pt:4;
}ST_ddc_sfibswpr_3;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    ffdo_dlen:5;
}ST_ddc_sfobsr_3;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    doff_wpt:4;
    unsigned int    doff_rpt:4;
}ST_ddc_sfobrwpr_3;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    ffdouf_st:1;
    unsigned int    ffdiof_st:1;
    unsigned int    ffdonf_st:1;
    unsigned int    ffdoet_st:1;
    unsigned int    ffdifu_st:1;
    unsigned int    ffdine_st:1;
    unsigned int    reserved_1:2;
}ST_ddc_sfsr_3;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    ffdouf_ie:1;
    unsigned int    ffdiof_ie:1;
    unsigned int    ffdonf_ie:1;
    unsigned int    ffdoet_ie:1;
    unsigned int    ffdifu_ie:1;
    unsigned int    ffdine_ie:1;
    unsigned int    cippt_ie:1;
    unsigned int    cispt_ie:1;
}ST_ddc_sfir_3;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    cmdfsm_st:8;
}ST_ddc_fsms_3;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    cmderr_ie:1;
    unsigned int    timeout_en:1;
    unsigned int    debounce_mode:2;
    unsigned int    timeout_ie:1;
    unsigned int    retime_m:3;
}ST_i2c_cr_4;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    cmderr:1;
    unsigned int    reserved_1:2;
    unsigned int    finish:1;
    unsigned int    timeout:1;
    unsigned int    reserved_2:3;
}ST_i2c_sr_4;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    timeout_val:8;
}ST_i2c_tr_4;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    edid_address:3;
    unsigned int    finish_int_en:1;
    unsigned int    ddc1_force:1;
    unsigned int    ddc2b_force:1;
    unsigned int    edid_srwen:1;
    unsigned int    edid_en:1;
}ST_edid_cr_4;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    ddc1_vcount:8;
}ST_ddc_vcr_4;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    edid_sadr:8;
}ST_edid_imswsar_4;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    edid_eadr:8;
}ST_edid_imswear_4;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    edidmode:1;
    unsigned int    edidsubaddress:1;
    unsigned int    edidstop:1;
    unsigned int    reserved_1:2;
    unsigned int    edidsubaddress_ie:1;
    unsigned int    edidstop_ie:1;
}ST_edid_ir_4;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    edidap:8;
}ST_ddc_sir_4;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    ediddp:8;
}ST_ddc_sap_4;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    bist_fail:1;
    unsigned int    bist_done:1;
    unsigned int    reserved_1:2;
    unsigned int    bist_rstn:1;
    unsigned int    bist_mode:1;
}ST_ddc_bistcr_4;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    segpt_latie:1;
    unsigned int    reserved_1:6;
    unsigned int    sgid_en:1;
}ST_ddc_scr_4;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    sgid_address:7;
    unsigned int    sgid_dtrden:1;
}ST_ddc_ssar_4;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    segpt_latched:1;
    unsigned int    seg_pt:7;
}ST_ddc_spr_4;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    special_mode:1;
    unsigned int    doffpt_reset:1;
    unsigned int    diffpt_reset:1;
    unsigned int    ciid_en:1;
}ST_ddc_sfcr_4;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    ciid_address:7;
    unsigned int    cirws_current:1;
}ST_ddc_sfsar_4;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    ciiddp:8;
}ST_ddc_sfdr_4;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    cirws_2nd:1;
    unsigned int    cirws_1st:1;
    unsigned int    cippt_2nd:1;
    unsigned int    cispt_2nd:1;
    unsigned int    cippt_1st:1;
    unsigned int    cispt_1st:1;
}ST_ddc_sfbsr_4;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    ffdi_dlen:5;
}ST_ddc_sfiblr_4;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    diff_wpt:4;
    unsigned int    diff_rpt:4;
}ST_ddc_sfibrwpr_4;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    diffstop_pt:4;
}ST_ddc_sfibswpr_4;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    ffdo_dlen:5;
}ST_ddc_sfobsr_4;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    doff_wpt:4;
    unsigned int    doff_rpt:4;
}ST_ddc_sfobrwpr_4;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    ffdouf_st:1;
    unsigned int    ffdiof_st:1;
    unsigned int    ffdonf_st:1;
    unsigned int    ffdoet_st:1;
    unsigned int    ffdifu_st:1;
    unsigned int    ffdine_st:1;
    unsigned int    reserved_1:2;
}ST_ddc_sfsr_4;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    ffdouf_ie:1;
    unsigned int    ffdiof_ie:1;
    unsigned int    ffdonf_ie:1;
    unsigned int    ffdoet_ie:1;
    unsigned int    ffdifu_ie:1;
    unsigned int    ffdine_ie:1;
    unsigned int    cippt_ie:1;
    unsigned int    cispt_ie:1;
}ST_ddc_sfir_4;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    cmdfsm_st:8;
}ST_ddc_fsms_4;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    rtcsec:7;
}MIS_rtcsec;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    rtcmin:6;
}MIS_rtcmin;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    rtchr:5;
}MIS_rtchr;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    rtcdate1:8;
}MIS_rtcdate1;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    rtcdate2:6;
}MIS_rtcdate2;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    almmin:6;
}MIS_almmin;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    almhr:5;
}MIS_almhr;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    almdate1:8;
}MIS_almdate1;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    almdate2:6;
}MIS_almdate2;

typedef struct
{
    unsigned int    reserved_0:29;
    unsigned int    vref:2;
    unsigned int    rtcstop:1;
}MIS_rtcstop;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    rtcpwr:1;
    unsigned int    co:2;
    unsigned int    ct:2;
    unsigned int    clksel:1;
    unsigned int    bc:2;
}MIS_rtcacr;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    rtcen:8;
}MIS_rtcen;

typedef struct
{
    unsigned int    rtc_alarm_int:1;
    unsigned int    rtc_date_int:1;
    unsigned int    rtc_hour_int:1;
    unsigned int    rtc_min_int:1;
    unsigned int    rtc_hsec_int:1;
    unsigned int    reserved_0:20;
    unsigned int    rtcrst:1;
    unsigned int    reserved_1:1;
    unsigned int    almen:1;
    unsigned int    dainte:1;
    unsigned int    huinte:1;
    unsigned int    muinte:1;
    unsigned int    hsuinte:1;
}MIS_rtccr;
#endif


#define GPIO_FCR                                                      0x18012000
#define GPIO_FCR_reg_addr                                             "0xb8012000"
#define GPIO_FCR_reg                                                  0xb8012000
#define GPIO_FCR_inst_addr                                            "0x0000"
#define GPIO_FCR_inst                                                 0x0000
#define GPIO_FCR_pdcf_shift                                           (24)
#define GPIO_FCR_pfip_shift                                           (8)
#define GPIO_FCR_pfdbe_shift                                          (0)
#define GPIO_FCR_pdcf_mask                                            (0xFF000000)
#define GPIO_FCR_pfip_mask                                            (0x0000FF00)
#define GPIO_FCR_pfdbe_mask                                           (0x000000FF)
#define GPIO_FCR_pdcf(data)                                           (0xFF000000&((data)<<24))
#define GPIO_FCR_pfip(data)                                           (0x0000FF00&((data)<<8))
#define GPIO_FCR_pfdbe(data)                                          (0x000000FF&(data))
#define GPIO_FCR_get_pdcf(data)                                       ((0xFF000000&(data))>>24)
#define GPIO_FCR_get_pfip(data)                                       ((0x0000FF00&(data))>>8)
#define GPIO_FCR_get_pfdbe(data)                                      (0x000000FF&(data))


#define GPIO_FDATA                                                    0x18012004
#define GPIO_FDATA_reg_addr                                           "0xb8012004"
#define GPIO_FDATA_reg                                                0xb8012004
#define GPIO_FDATA_inst_addr                                          "0x0001"
#define GPIO_FDATA_inst                                               0x0001
#define GPIO_FDATA_pdf_in_shift                                       (24)
#define GPIO_FDATA_pdf_out_shift                                      (16)
#define GPIO_FDATA_pfbm_shift                                         (0)
#define GPIO_FDATA_pdf_in_mask                                        (0xFF000000)
#define GPIO_FDATA_pdf_out_mask                                       (0x00FF0000)
#define GPIO_FDATA_pfbm_mask                                          (0x000000FF)
#define GPIO_FDATA_pdf_in(data)                                       (0xFF000000&((data)<<24))
#define GPIO_FDATA_pdf_out(data)                                      (0x00FF0000&((data)<<16))
#define GPIO_FDATA_pfbm(data)                                         (0x000000FF&(data))
#define GPIO_FDATA_get_pdf_in(data)                                   ((0xFF000000&(data))>>24)
#define GPIO_FDATA_get_pdf_out(data)                                  ((0x00FF0000&(data))>>16)
#define GPIO_FDATA_get_pfbm(data)                                     (0x000000FF&(data))


#define GPIO_GCR                                                      0x18012008
#define GPIO_GCR_reg_addr                                             "0xb8012008"
#define GPIO_GCR_reg                                                  0xb8012008
#define GPIO_GCR_inst_addr                                            "0x0002"
#define GPIO_GCR_inst                                                 0x0002
#define GPIO_GCR_pdcg_shift                                           (24)
#define GPIO_GCR_pgip_shift                                           (8)
#define GPIO_GCR_pgdbe_shift                                          (0)
#define GPIO_GCR_pdcg_mask                                            (0xFF000000)
#define GPIO_GCR_pgip_mask                                            (0x0000FF00)
#define GPIO_GCR_pgdbe_mask                                           (0x000000FF)
#define GPIO_GCR_pdcg(data)                                           (0xFF000000&((data)<<24))
#define GPIO_GCR_pgip(data)                                           (0x0000FF00&((data)<<8))
#define GPIO_GCR_pgdbe(data)                                          (0x000000FF&(data))
#define GPIO_GCR_get_pdcg(data)                                       ((0xFF000000&(data))>>24)
#define GPIO_GCR_get_pgip(data)                                       ((0x0000FF00&(data))>>8)
#define GPIO_GCR_get_pgdbe(data)                                      (0x000000FF&(data))


#define GPIO_GDATA                                                    0x1801200c
#define GPIO_GDATA_reg_addr                                           "0xb801200c"
#define GPIO_GDATA_reg                                                0xb801200c
#define GPIO_GDATA_inst_addr                                          "0x0003"
#define GPIO_GDATA_inst                                               0x0003
#define GPIO_GDATA_pdg_in_shift                                       (24)
#define GPIO_GDATA_pdg_out_shift                                      (16)
#define GPIO_GDATA_pgbm_shift                                         (0)
#define GPIO_GDATA_pdg_in_mask                                        (0xFF000000)
#define GPIO_GDATA_pdg_out_mask                                       (0x00FF0000)
#define GPIO_GDATA_pgbm_mask                                          (0x000000FF)
#define GPIO_GDATA_pdg_in(data)                                       (0xFF000000&((data)<<24))
#define GPIO_GDATA_pdg_out(data)                                      (0x00FF0000&((data)<<16))
#define GPIO_GDATA_pgbm(data)                                         (0x000000FF&(data))
#define GPIO_GDATA_get_pdg_in(data)                                   ((0xFF000000&(data))>>24)
#define GPIO_GDATA_get_pdg_out(data)                                  ((0x00FF0000&(data))>>16)
#define GPIO_GDATA_get_pgbm(data)                                     (0x000000FF&(data))


#define GPIO_HCR                                                      0x18012010
#define GPIO_HCR_reg_addr                                             "0xb8012010"
#define GPIO_HCR_reg                                                  0xb8012010
#define GPIO_HCR_inst_addr                                            "0x0004"
#define GPIO_HCR_inst                                                 0x0004
#define GPIO_HCR_pdch_shift                                           (24)
#define GPIO_HCR_phip_shift                                           (8)
#define GPIO_HCR_phdbe_shift                                          (0)
#define GPIO_HCR_pdch_mask                                            (0xFF000000)
#define GPIO_HCR_phip_mask                                            (0x0000FF00)
#define GPIO_HCR_phdbe_mask                                           (0x000000FF)
#define GPIO_HCR_pdch(data)                                           (0xFF000000&((data)<<24))
#define GPIO_HCR_phip(data)                                           (0x0000FF00&((data)<<8))
#define GPIO_HCR_phdbe(data)                                          (0x000000FF&(data))
#define GPIO_HCR_get_pdch(data)                                       ((0xFF000000&(data))>>24)
#define GPIO_HCR_get_phip(data)                                       ((0x0000FF00&(data))>>8)
#define GPIO_HCR_get_phdbe(data)                                      (0x000000FF&(data))


#define GPIO_HDATA                                                    0x18012014
#define GPIO_HDATA_reg_addr                                           "0xb8012014"
#define GPIO_HDATA_reg                                                0xb8012014
#define GPIO_HDATA_inst_addr                                          "0x0005"
#define GPIO_HDATA_inst                                               0x0005
#define GPIO_HDATA_pdh_in_shift                                       (24)
#define GPIO_HDATA_pdh_out_shift                                      (16)
#define GPIO_HDATA_phbm_shift                                         (0)
#define GPIO_HDATA_pdh_in_mask                                        (0xFF000000)
#define GPIO_HDATA_pdh_out_mask                                       (0x00FF0000)
#define GPIO_HDATA_phbm_mask                                          (0x000000FF)
#define GPIO_HDATA_pdh_in(data)                                       (0xFF000000&((data)<<24))
#define GPIO_HDATA_pdh_out(data)                                      (0x00FF0000&((data)<<16))
#define GPIO_HDATA_phbm(data)                                         (0x000000FF&(data))
#define GPIO_HDATA_get_pdh_in(data)                                   ((0xFF000000&(data))>>24)
#define GPIO_HDATA_get_pdh_out(data)                                  ((0x00FF0000&(data))>>16)
#define GPIO_HDATA_get_phbm(data)                                     (0x000000FF&(data))


#define GPIO_KCR                                                      0x18012018
#define GPIO_KCR_reg_addr                                             "0xb8012018"
#define GPIO_KCR_reg                                                  0xb8012018
#define GPIO_KCR_inst_addr                                            "0x0006"
#define GPIO_KCR_inst                                                 0x0006
#define GPIO_KCR_pdck_shift                                           (24)
#define GPIO_KCR_pkip_shift                                           (8)
#define GPIO_KCR_pkdbe_shift                                          (0)
#define GPIO_KCR_pdck_mask                                            (0xFF000000)
#define GPIO_KCR_pkip_mask                                            (0x0000FF00)
#define GPIO_KCR_pkdbe_mask                                           (0x000000FF)
#define GPIO_KCR_pdck(data)                                           (0xFF000000&((data)<<24))
#define GPIO_KCR_pkip(data)                                           (0x0000FF00&((data)<<8))
#define GPIO_KCR_pkdbe(data)                                          (0x000000FF&(data))
#define GPIO_KCR_get_pdck(data)                                       ((0xFF000000&(data))>>24)
#define GPIO_KCR_get_pkip(data)                                       ((0x0000FF00&(data))>>8)
#define GPIO_KCR_get_pkdbe(data)                                      (0x000000FF&(data))


#define GPIO_KDATA                                                    0x1801201c
#define GPIO_KDATA_reg_addr                                           "0xb801201c"
#define GPIO_KDATA_reg                                                0xb801201c
#define GPIO_KDATA_inst_addr                                          "0x0007"
#define GPIO_KDATA_inst                                               0x0007
#define GPIO_KDATA_pdk_in_shift                                       (24)
#define GPIO_KDATA_pdk_out_shift                                      (16)
#define GPIO_KDATA_pkbm_shift                                         (0)
#define GPIO_KDATA_pdk_in_mask                                        (0xFF000000)
#define GPIO_KDATA_pdk_out_mask                                       (0x00FF0000)
#define GPIO_KDATA_pkbm_mask                                          (0x000000FF)
#define GPIO_KDATA_pdk_in(data)                                       (0xFF000000&((data)<<24))
#define GPIO_KDATA_pdk_out(data)                                      (0x00FF0000&((data)<<16))
#define GPIO_KDATA_pkbm(data)                                         (0x000000FF&(data))
#define GPIO_KDATA_get_pdk_in(data)                                   ((0xFF000000&(data))>>24)
#define GPIO_KDATA_get_pdk_out(data)                                  ((0x00FF0000&(data))>>16)
#define GPIO_KDATA_get_pkbm(data)                                     (0x000000FF&(data))


#define GPIO_MCR                                                      0x18012020
#define GPIO_MCR_reg_addr                                             "0xb8012020"
#define GPIO_MCR_reg                                                  0xb8012020
#define GPIO_MCR_inst_addr                                            "0x0008"
#define GPIO_MCR_inst                                                 0x0008
#define GPIO_MCR_pdcm_shift                                           (24)
#define GPIO_MCR_pmip_shift                                           (8)
#define GPIO_MCR_pmdbe_shift                                          (0)
#define GPIO_MCR_pdcm_mask                                            (0xFF000000)
#define GPIO_MCR_pmip_mask                                            (0x0000FF00)
#define GPIO_MCR_pmdbe_mask                                           (0x000000FF)
#define GPIO_MCR_pdcm(data)                                           (0xFF000000&((data)<<24))
#define GPIO_MCR_pmip(data)                                           (0x0000FF00&((data)<<8))
#define GPIO_MCR_pmdbe(data)                                          (0x000000FF&(data))
#define GPIO_MCR_get_pdcm(data)                                       ((0xFF000000&(data))>>24)
#define GPIO_MCR_get_pmip(data)                                       ((0x0000FF00&(data))>>8)
#define GPIO_MCR_get_pmdbe(data)                                      (0x000000FF&(data))


#define GPIO_MDATA                                                    0x18012024
#define GPIO_MDATA_reg_addr                                           "0xb8012024"
#define GPIO_MDATA_reg                                                0xb8012024
#define GPIO_MDATA_inst_addr                                          "0x0009"
#define GPIO_MDATA_inst                                               0x0009
#define GPIO_MDATA_pdm_in_shift                                       (24)
#define GPIO_MDATA_pdm_out_shift                                      (16)
#define GPIO_MDATA_pmbm_shift                                         (0)
#define GPIO_MDATA_pdm_in_mask                                        (0xFF000000)
#define GPIO_MDATA_pdm_out_mask                                       (0x00FF0000)
#define GPIO_MDATA_pmbm_mask                                          (0x000000FF)
#define GPIO_MDATA_pdm_in(data)                                       (0xFF000000&((data)<<24))
#define GPIO_MDATA_pdm_out(data)                                      (0x00FF0000&((data)<<16))
#define GPIO_MDATA_pmbm(data)                                         (0x000000FF&(data))
#define GPIO_MDATA_get_pdm_in(data)                                   ((0xFF000000&(data))>>24)
#define GPIO_MDATA_get_pdm_out(data)                                  ((0x00FF0000&(data))>>16)
#define GPIO_MDATA_get_pmbm(data)                                     (0x000000FF&(data))


#define GPIO_NCR                                                      0x18012028
#define GPIO_NCR_reg_addr                                             "0xb8012028"
#define GPIO_NCR_reg                                                  0xb8012028
#define GPIO_NCR_inst_addr                                            "0x000A"
#define GPIO_NCR_inst                                                 0x000A
#define GPIO_NCR_pdcn_shift                                           (24)
#define GPIO_NCR_pnip_shift                                           (8)
#define GPIO_NCR_pndbe_shift                                          (0)
#define GPIO_NCR_pdcn_mask                                            (0xFF000000)
#define GPIO_NCR_pnip_mask                                            (0x0000FF00)
#define GPIO_NCR_pndbe_mask                                           (0x000000FF)
#define GPIO_NCR_pdcn(data)                                           (0xFF000000&((data)<<24))
#define GPIO_NCR_pnip(data)                                           (0x0000FF00&((data)<<8))
#define GPIO_NCR_pndbe(data)                                          (0x000000FF&(data))
#define GPIO_NCR_get_pdcn(data)                                       ((0xFF000000&(data))>>24)
#define GPIO_NCR_get_pnip(data)                                       ((0x0000FF00&(data))>>8)
#define GPIO_NCR_get_pndbe(data)                                      (0x000000FF&(data))


#define GPIO_NDATA                                                    0x1801202c
#define GPIO_NDATA_reg_addr                                           "0xb801202c"
#define GPIO_NDATA_reg                                                0xb801202c
#define GPIO_NDATA_inst_addr                                          "0x000B"
#define GPIO_NDATA_inst                                               0x000B
#define GPIO_NDATA_pdn_in_shift                                       (24)
#define GPIO_NDATA_pdn_out_shift                                      (16)
#define GPIO_NDATA_pnbm_shift                                         (0)
#define GPIO_NDATA_pdn_in_mask                                        (0xFF000000)
#define GPIO_NDATA_pdn_out_mask                                       (0x00FF0000)
#define GPIO_NDATA_pnbm_mask                                          (0x000000FF)
#define GPIO_NDATA_pdn_in(data)                                       (0xFF000000&((data)<<24))
#define GPIO_NDATA_pdn_out(data)                                      (0x00FF0000&((data)<<16))
#define GPIO_NDATA_pnbm(data)                                         (0x000000FF&(data))
#define GPIO_NDATA_get_pdn_in(data)                                   ((0xFF000000&(data))>>24)
#define GPIO_NDATA_get_pdn_out(data)                                  ((0x00FF0000&(data))>>16)
#define GPIO_NDATA_get_pnbm(data)                                     (0x000000FF&(data))


#define GPIO_PCR                                                      0x18012030
#define GPIO_PCR_reg_addr                                             "0xb8012030"
#define GPIO_PCR_reg                                                  0xb8012030
#define GPIO_PCR_inst_addr                                            "0x000C"
#define GPIO_PCR_inst                                                 0x000C
#define GPIO_PCR_pdcp_shift                                           (24)
#define GPIO_PCR_ppip_shift                                           (8)
#define GPIO_PCR_ppdbe_shift                                          (0)
#define GPIO_PCR_pdcp_mask                                            (0xFF000000)
#define GPIO_PCR_ppip_mask                                            (0x0000FF00)
#define GPIO_PCR_ppdbe_mask                                           (0x000000FF)
#define GPIO_PCR_pdcp(data)                                           (0xFF000000&((data)<<24))
#define GPIO_PCR_ppip(data)                                           (0x0000FF00&((data)<<8))
#define GPIO_PCR_ppdbe(data)                                          (0x000000FF&(data))
#define GPIO_PCR_get_pdcp(data)                                       ((0xFF000000&(data))>>24)
#define GPIO_PCR_get_ppip(data)                                       ((0x0000FF00&(data))>>8)
#define GPIO_PCR_get_ppdbe(data)                                      (0x000000FF&(data))


#define GPIO_PDATA                                                    0x18012034
#define GPIO_PDATA_reg_addr                                           "0xb8012034"
#define GPIO_PDATA_reg                                                0xb8012034
#define GPIO_PDATA_inst_addr                                          "0x000D"
#define GPIO_PDATA_inst                                               0x000D
#define GPIO_PDATA_pdp_in_shift                                       (24)
#define GPIO_PDATA_pdp_out_shift                                      (16)
#define GPIO_PDATA_ppbm_shift                                         (0)
#define GPIO_PDATA_pdp_in_mask                                        (0xFF000000)
#define GPIO_PDATA_pdp_out_mask                                       (0x00FF0000)
#define GPIO_PDATA_ppbm_mask                                          (0x000000FF)
#define GPIO_PDATA_pdp_in(data)                                       (0xFF000000&((data)<<24))
#define GPIO_PDATA_pdp_out(data)                                      (0x00FF0000&((data)<<16))
#define GPIO_PDATA_ppbm(data)                                         (0x000000FF&(data))
#define GPIO_PDATA_get_pdp_in(data)                                   ((0xFF000000&(data))>>24)
#define GPIO_PDATA_get_pdp_out(data)                                  ((0x00FF0000&(data))>>16)
#define GPIO_PDATA_get_ppbm(data)                                     (0x000000FF&(data))


#define GPIO_QCR                                                      0x18012038
#define GPIO_QCR_reg_addr                                             "0xb8012038"
#define GPIO_QCR_reg                                                  0xb8012038
#define GPIO_QCR_inst_addr                                            "0x000E"
#define GPIO_QCR_inst                                                 0x000E
#define GPIO_QCR_pdcq_shift                                           (24)
#define GPIO_QCR_pqip_shift                                           (8)
#define GPIO_QCR_pqdbe_shift                                          (0)
#define GPIO_QCR_pdcq_mask                                            (0xFF000000)
#define GPIO_QCR_pqip_mask                                            (0x0000FF00)
#define GPIO_QCR_pqdbe_mask                                           (0x000000FF)
#define GPIO_QCR_pdcq(data)                                           (0xFF000000&((data)<<24))
#define GPIO_QCR_pqip(data)                                           (0x0000FF00&((data)<<8))
#define GPIO_QCR_pqdbe(data)                                          (0x000000FF&(data))
#define GPIO_QCR_get_pdcq(data)                                       ((0xFF000000&(data))>>24)
#define GPIO_QCR_get_pqip(data)                                       ((0x0000FF00&(data))>>8)
#define GPIO_QCR_get_pqdbe(data)                                      (0x000000FF&(data))


#define GPIO_QDATA                                                    0x1801203c
#define GPIO_QDATA_reg_addr                                           "0xb801203c"
#define GPIO_QDATA_reg                                                0xb801203c
#define GPIO_QDATA_inst_addr                                          "0x000F"
#define GPIO_QDATA_inst                                               0x000F
#define GPIO_QDATA_pdq_in_shift                                       (24)
#define GPIO_QDATA_pdq_out_shift                                      (16)
#define GPIO_QDATA_pqbm_shift                                         (0)
#define GPIO_QDATA_pdq_in_mask                                        (0xFF000000)
#define GPIO_QDATA_pdq_out_mask                                       (0x00FF0000)
#define GPIO_QDATA_pqbm_mask                                          (0x000000FF)
#define GPIO_QDATA_pdq_in(data)                                       (0xFF000000&((data)<<24))
#define GPIO_QDATA_pdq_out(data)                                      (0x00FF0000&((data)<<16))
#define GPIO_QDATA_pqbm(data)                                         (0x000000FF&(data))
#define GPIO_QDATA_get_pdq_in(data)                                   ((0xFF000000&(data))>>24)
#define GPIO_QDATA_get_pdq_out(data)                                  ((0x00FF0000&(data))>>16)
#define GPIO_QDATA_get_pqbm(data)                                     (0x000000FF&(data))


#define GPIO_RCR                                                      0x18012040
#define GPIO_RCR_reg_addr                                             "0xb8012040"
#define GPIO_RCR_reg                                                  0xb8012040
#define GPIO_RCR_inst_addr                                            "0x0010"
#define GPIO_RCR_inst                                                 0x0010
#define GPIO_RCR_pdcr_shift                                           (24)
#define GPIO_RCR_prip_shift                                           (8)
#define GPIO_RCR_prdbe_shift                                          (0)
#define GPIO_RCR_pdcr_mask                                            (0xFF000000)
#define GPIO_RCR_prip_mask                                            (0x0000FF00)
#define GPIO_RCR_prdbe_mask                                           (0x000000FF)
#define GPIO_RCR_pdcr(data)                                           (0xFF000000&((data)<<24))
#define GPIO_RCR_prip(data)                                           (0x0000FF00&((data)<<8))
#define GPIO_RCR_prdbe(data)                                          (0x000000FF&(data))
#define GPIO_RCR_get_pdcr(data)                                       ((0xFF000000&(data))>>24)
#define GPIO_RCR_get_prip(data)                                       ((0x0000FF00&(data))>>8)
#define GPIO_RCR_get_prdbe(data)                                      (0x000000FF&(data))


#define GPIO_RDATA                                                    0x18012044
#define GPIO_RDATA_reg_addr                                           "0xb8012044"
#define GPIO_RDATA_reg                                                0xb8012044
#define GPIO_RDATA_inst_addr                                          "0x0011"
#define GPIO_RDATA_inst                                               0x0011
#define GPIO_RDATA_pdr_in_shift                                       (24)
#define GPIO_RDATA_pdr_out_shift                                      (16)
#define GPIO_RDATA_prbm_shift                                         (0)
#define GPIO_RDATA_pdr_in_mask                                        (0xFF000000)
#define GPIO_RDATA_pdr_out_mask                                       (0x00FF0000)
#define GPIO_RDATA_prbm_mask                                          (0x000000FF)
#define GPIO_RDATA_pdr_in(data)                                       (0xFF000000&((data)<<24))
#define GPIO_RDATA_pdr_out(data)                                      (0x00FF0000&((data)<<16))
#define GPIO_RDATA_prbm(data)                                         (0x000000FF&(data))
#define GPIO_RDATA_get_pdr_in(data)                                   ((0xFF000000&(data))>>24)
#define GPIO_RDATA_get_pdr_out(data)                                  ((0x00FF0000&(data))>>16)
#define GPIO_RDATA_get_prbm(data)                                     (0x000000FF&(data))


#define GPIO_SCR                                                      0x18012048
#define GPIO_SCR_reg_addr                                             "0xb8012048"
#define GPIO_SCR_reg                                                  0xb8012048
#define GPIO_SCR_inst_addr                                            "0x0012"
#define GPIO_SCR_inst                                                 0x0012
#define GPIO_SCR_pdcs_shift                                           (24)
#define GPIO_SCR_psip_shift                                           (8)
#define GPIO_SCR_psdbe_shift                                          (0)
#define GPIO_SCR_pdcs_mask                                            (0xFF000000)
#define GPIO_SCR_psip_mask                                            (0x0000FF00)
#define GPIO_SCR_psdbe_mask                                           (0x000000FF)
#define GPIO_SCR_pdcs(data)                                           (0xFF000000&((data)<<24))
#define GPIO_SCR_psip(data)                                           (0x0000FF00&((data)<<8))
#define GPIO_SCR_psdbe(data)                                          (0x000000FF&(data))
#define GPIO_SCR_get_pdcs(data)                                       ((0xFF000000&(data))>>24)
#define GPIO_SCR_get_psip(data)                                       ((0x0000FF00&(data))>>8)
#define GPIO_SCR_get_psdbe(data)                                      (0x000000FF&(data))


#define GPIO_SDATA                                                    0x1801204c
#define GPIO_SDATA_reg_addr                                           "0xb801204c"
#define GPIO_SDATA_reg                                                0xb801204c
#define GPIO_SDATA_inst_addr                                          "0x0013"
#define GPIO_SDATA_inst                                               0x0013
#define GPIO_SDATA_pds_in_shift                                       (24)
#define GPIO_SDATA_pds_out_shift                                      (16)
#define GPIO_SDATA_psbm_shift                                         (0)
#define GPIO_SDATA_pds_in_mask                                        (0xFF000000)
#define GPIO_SDATA_pds_out_mask                                       (0x00FF0000)
#define GPIO_SDATA_psbm_mask                                          (0x000000FF)
#define GPIO_SDATA_pds_in(data)                                       (0xFF000000&((data)<<24))
#define GPIO_SDATA_pds_out(data)                                      (0x00FF0000&((data)<<16))
#define GPIO_SDATA_psbm(data)                                         (0x000000FF&(data))
#define GPIO_SDATA_get_pds_in(data)                                   ((0xFF000000&(data))>>24)
#define GPIO_SDATA_get_pds_out(data)                                  ((0x00FF0000&(data))>>16)
#define GPIO_SDATA_get_psbm(data)                                     (0x000000FF&(data))


#define GPIO_TCR                                                      0x18012050
#define GPIO_TCR_reg_addr                                             "0xb8012050"
#define GPIO_TCR_reg                                                  0xb8012050
#define GPIO_TCR_inst_addr                                            "0x0014"
#define GPIO_TCR_inst                                                 0x0014
#define GPIO_TCR_pdct_shift                                           (24)
#define GPIO_TCR_ptip_shift                                           (8)
#define GPIO_TCR_ptdbe_shift                                          (0)
#define GPIO_TCR_pdct_mask                                            (0xFF000000)
#define GPIO_TCR_ptip_mask                                            (0x0000FF00)
#define GPIO_TCR_ptdbe_mask                                           (0x000000FF)
#define GPIO_TCR_pdct(data)                                           (0xFF000000&((data)<<24))
#define GPIO_TCR_ptip(data)                                           (0x0000FF00&((data)<<8))
#define GPIO_TCR_ptdbe(data)                                          (0x000000FF&(data))
#define GPIO_TCR_get_pdct(data)                                       ((0xFF000000&(data))>>24)
#define GPIO_TCR_get_ptip(data)                                       ((0x0000FF00&(data))>>8)
#define GPIO_TCR_get_ptdbe(data)                                      (0x000000FF&(data))


#define GPIO_TDATA                                                    0x18012054
#define GPIO_TDATA_reg_addr                                           "0xb8012054"
#define GPIO_TDATA_reg                                                0xb8012054
#define GPIO_TDATA_inst_addr                                          "0x0015"
#define GPIO_TDATA_inst                                               0x0015
#define GPIO_TDATA_pdt_in_shift                                       (24)
#define GPIO_TDATA_pdt_out_shift                                      (16)
#define GPIO_TDATA_ptbm_shift                                         (0)
#define GPIO_TDATA_pdt_in_mask                                        (0xFF000000)
#define GPIO_TDATA_pdt_out_mask                                       (0x00FF0000)
#define GPIO_TDATA_ptbm_mask                                          (0x000000FF)
#define GPIO_TDATA_pdt_in(data)                                       (0xFF000000&((data)<<24))
#define GPIO_TDATA_pdt_out(data)                                      (0x00FF0000&((data)<<16))
#define GPIO_TDATA_ptbm(data)                                         (0x000000FF&(data))
#define GPIO_TDATA_get_pdt_in(data)                                   ((0xFF000000&(data))>>24)
#define GPIO_TDATA_get_pdt_out(data)                                  ((0x00FF0000&(data))>>16)
#define GPIO_TDATA_get_ptbm(data)                                     (0x000000FF&(data))


#define GPIO_UCR                                                      0x18012058
#define GPIO_UCR_reg_addr                                             "0xb8012058"
#define GPIO_UCR_reg                                                  0xb8012058
#define GPIO_UCR_inst_addr                                            "0x0016"
#define GPIO_UCR_inst                                                 0x0016
#define GPIO_UCR_pdcu_shift                                           (24)
#define GPIO_UCR_puip_shift                                           (8)
#define GPIO_UCR_pudbe_shift                                          (0)
#define GPIO_UCR_pdcu_mask                                            (0xFF000000)
#define GPIO_UCR_puip_mask                                            (0x0000FF00)
#define GPIO_UCR_pudbe_mask                                           (0x000000FF)
#define GPIO_UCR_pdcu(data)                                           (0xFF000000&((data)<<24))
#define GPIO_UCR_puip(data)                                           (0x0000FF00&((data)<<8))
#define GPIO_UCR_pudbe(data)                                          (0x000000FF&(data))
#define GPIO_UCR_get_pdcu(data)                                       ((0xFF000000&(data))>>24)
#define GPIO_UCR_get_puip(data)                                       ((0x0000FF00&(data))>>8)
#define GPIO_UCR_get_pudbe(data)                                      (0x000000FF&(data))


#define GPIO_UDATA                                                    0x1801205c
#define GPIO_UDATA_reg_addr                                           "0xb801205c"
#define GPIO_UDATA_reg                                                0xb801205c
#define GPIO_UDATA_inst_addr                                          "0x0017"
#define GPIO_UDATA_inst                                               0x0017
#define GPIO_UDATA_pdu_in_shift                                       (24)
#define GPIO_UDATA_pdu_out_shift                                      (16)
#define GPIO_UDATA_pubm_shift                                         (0)
#define GPIO_UDATA_pdu_in_mask                                        (0xFF000000)
#define GPIO_UDATA_pdu_out_mask                                       (0x00FF0000)
#define GPIO_UDATA_pubm_mask                                          (0x000000FF)
#define GPIO_UDATA_pdu_in(data)                                       (0xFF000000&((data)<<24))
#define GPIO_UDATA_pdu_out(data)                                      (0x00FF0000&((data)<<16))
#define GPIO_UDATA_pubm(data)                                         (0x000000FF&(data))
#define GPIO_UDATA_get_pdu_in(data)                                   ((0xFF000000&(data))>>24)
#define GPIO_UDATA_get_pdu_out(data)                                  ((0x00FF0000&(data))>>16)
#define GPIO_UDATA_get_pubm(data)                                     (0x000000FF&(data))


#define GPIO_VCR                                                      0x18012060
#define GPIO_VCR_reg_addr                                             "0xb8012060"
#define GPIO_VCR_reg                                                  0xb8012060
#define GPIO_VCR_inst_addr                                            "0x0018"
#define GPIO_VCR_inst                                                 0x0018
#define GPIO_VCR_pdcv_shift                                           (24)
#define GPIO_VCR_pvip_shift                                           (8)
#define GPIO_VCR_pvdbe_shift                                          (0)
#define GPIO_VCR_pdcv_mask                                            (0xFF000000)
#define GPIO_VCR_pvip_mask                                            (0x0000FF00)
#define GPIO_VCR_pvdbe_mask                                           (0x000000FF)
#define GPIO_VCR_pdcv(data)                                           (0xFF000000&((data)<<24))
#define GPIO_VCR_pvip(data)                                           (0x0000FF00&((data)<<8))
#define GPIO_VCR_pvdbe(data)                                          (0x000000FF&(data))
#define GPIO_VCR_get_pdcv(data)                                       ((0xFF000000&(data))>>24)
#define GPIO_VCR_get_pvip(data)                                       ((0x0000FF00&(data))>>8)
#define GPIO_VCR_get_pvdbe(data)                                      (0x000000FF&(data))


#define GPIO_VDATA                                                    0x18012064
#define GPIO_VDATA_reg_addr                                           "0xb8012064"
#define GPIO_VDATA_reg                                                0xb8012064
#define GPIO_VDATA_inst_addr                                          "0x0019"
#define GPIO_VDATA_inst                                               0x0019
#define GPIO_VDATA_pdv_in_shift                                       (24)
#define GPIO_VDATA_pdv_out_shift                                      (16)
#define GPIO_VDATA_pvbm_shift                                         (0)
#define GPIO_VDATA_pdv_in_mask                                        (0xFF000000)
#define GPIO_VDATA_pdv_out_mask                                       (0x00FF0000)
#define GPIO_VDATA_pvbm_mask                                          (0x000000FF)
#define GPIO_VDATA_pdv_in(data)                                       (0xFF000000&((data)<<24))
#define GPIO_VDATA_pdv_out(data)                                      (0x00FF0000&((data)<<16))
#define GPIO_VDATA_pvbm(data)                                         (0x000000FF&(data))
#define GPIO_VDATA_get_pdv_in(data)                                   ((0xFF000000&(data))>>24)
#define GPIO_VDATA_get_pdv_out(data)                                  ((0x00FF0000&(data))>>16)
#define GPIO_VDATA_get_pvbm(data)                                     (0x000000FF&(data))


#define GPIO_FIMR                                                     0x18012068
#define GPIO_FIMR_reg_addr                                            "0xb8012068"
#define GPIO_FIMR_reg                                                 0xb8012068
#define GPIO_FIMR_inst_addr                                           "0x001A"
#define GPIO_FIMR_inst                                                0x001A
#define GPIO_FIMR_pf7ie_shift                                         (14)
#define GPIO_FIMR_pf6ie_shift                                         (12)
#define GPIO_FIMR_pf5ie_shift                                         (10)
#define GPIO_FIMR_pf4ie_shift                                         (8)
#define GPIO_FIMR_pf3ie_shift                                         (6)
#define GPIO_FIMR_pf2ie_shift                                         (4)
#define GPIO_FIMR_pf1ie_shift                                         (2)
#define GPIO_FIMR_pf0ie_shift                                         (0)
#define GPIO_FIMR_pf7ie_mask                                          (0x0000C000)
#define GPIO_FIMR_pf6ie_mask                                          (0x00003000)
#define GPIO_FIMR_pf5ie_mask                                          (0x00000C00)
#define GPIO_FIMR_pf4ie_mask                                          (0x00000300)
#define GPIO_FIMR_pf3ie_mask                                          (0x000000C0)
#define GPIO_FIMR_pf2ie_mask                                          (0x00000030)
#define GPIO_FIMR_pf1ie_mask                                          (0x0000000C)
#define GPIO_FIMR_pf0ie_mask                                          (0x00000003)
#define GPIO_FIMR_pf7ie(data)                                         (0x0000C000&((data)<<14))
#define GPIO_FIMR_pf6ie(data)                                         (0x00003000&((data)<<12))
#define GPIO_FIMR_pf5ie(data)                                         (0x00000C00&((data)<<10))
#define GPIO_FIMR_pf4ie(data)                                         (0x00000300&((data)<<8))
#define GPIO_FIMR_pf3ie(data)                                         (0x000000C0&((data)<<6))
#define GPIO_FIMR_pf2ie(data)                                         (0x00000030&((data)<<4))
#define GPIO_FIMR_pf1ie(data)                                         (0x0000000C&((data)<<2))
#define GPIO_FIMR_pf0ie(data)                                         (0x00000003&(data))
#define GPIO_FIMR_get_pf7ie(data)                                     ((0x0000C000&(data))>>14)
#define GPIO_FIMR_get_pf6ie(data)                                     ((0x00003000&(data))>>12)
#define GPIO_FIMR_get_pf5ie(data)                                     ((0x00000C00&(data))>>10)
#define GPIO_FIMR_get_pf4ie(data)                                     ((0x00000300&(data))>>8)
#define GPIO_FIMR_get_pf3ie(data)                                     ((0x000000C0&(data))>>6)
#define GPIO_FIMR_get_pf2ie(data)                                     ((0x00000030&(data))>>4)
#define GPIO_FIMR_get_pf1ie(data)                                     ((0x0000000C&(data))>>2)
#define GPIO_FIMR_get_pf0ie(data)                                     (0x00000003&(data))


#define GPIO_GIMR                                                     0x1801206c
#define GPIO_GIMR_reg_addr                                            "0xb801206c"
#define GPIO_GIMR_reg                                                 0xb801206c
#define GPIO_GIMR_inst_addr                                           "0x001B"
#define GPIO_GIMR_inst                                                0x001B
#define GPIO_GIMR_pg7ie_shift                                         (14)
#define GPIO_GIMR_pg6ie_shift                                         (12)
#define GPIO_GIMR_pg5ie_shift                                         (10)
#define GPIO_GIMR_pg4ie_shift                                         (8)
#define GPIO_GIMR_pg3ie_shift                                         (6)
#define GPIO_GIMR_pg2ie_shift                                         (4)
#define GPIO_GIMR_pg1ie_shift                                         (2)
#define GPIO_GIMR_pg0ie_shift                                         (0)
#define GPIO_GIMR_pg7ie_mask                                          (0x0000C000)
#define GPIO_GIMR_pg6ie_mask                                          (0x00003000)
#define GPIO_GIMR_pg5ie_mask                                          (0x00000C00)
#define GPIO_GIMR_pg4ie_mask                                          (0x00000300)
#define GPIO_GIMR_pg3ie_mask                                          (0x000000C0)
#define GPIO_GIMR_pg2ie_mask                                          (0x00000030)
#define GPIO_GIMR_pg1ie_mask                                          (0x0000000C)
#define GPIO_GIMR_pg0ie_mask                                          (0x00000003)
#define GPIO_GIMR_pg7ie(data)                                         (0x0000C000&((data)<<14))
#define GPIO_GIMR_pg6ie(data)                                         (0x00003000&((data)<<12))
#define GPIO_GIMR_pg5ie(data)                                         (0x00000C00&((data)<<10))
#define GPIO_GIMR_pg4ie(data)                                         (0x00000300&((data)<<8))
#define GPIO_GIMR_pg3ie(data)                                         (0x000000C0&((data)<<6))
#define GPIO_GIMR_pg2ie(data)                                         (0x00000030&((data)<<4))
#define GPIO_GIMR_pg1ie(data)                                         (0x0000000C&((data)<<2))
#define GPIO_GIMR_pg0ie(data)                                         (0x00000003&(data))
#define GPIO_GIMR_get_pg7ie(data)                                     ((0x0000C000&(data))>>14)
#define GPIO_GIMR_get_pg6ie(data)                                     ((0x00003000&(data))>>12)
#define GPIO_GIMR_get_pg5ie(data)                                     ((0x00000C00&(data))>>10)
#define GPIO_GIMR_get_pg4ie(data)                                     ((0x00000300&(data))>>8)
#define GPIO_GIMR_get_pg3ie(data)                                     ((0x000000C0&(data))>>6)
#define GPIO_GIMR_get_pg2ie(data)                                     ((0x00000030&(data))>>4)
#define GPIO_GIMR_get_pg1ie(data)                                     ((0x0000000C&(data))>>2)
#define GPIO_GIMR_get_pg0ie(data)                                     (0x00000003&(data))


#define GPIO_HIMR                                                     0x18012070
#define GPIO_HIMR_reg_addr                                            "0xb8012070"
#define GPIO_HIMR_reg                                                 0xb8012070
#define GPIO_HIMR_inst_addr                                           "0x001C"
#define GPIO_HIMR_inst                                                0x001C
#define GPIO_HIMR_ph7ie_shift                                         (14)
#define GPIO_HIMR_ph6ie_shift                                         (12)
#define GPIO_HIMR_ph5ie_shift                                         (10)
#define GPIO_HIMR_ph4ie_shift                                         (8)
#define GPIO_HIMR_ph3ie_shift                                         (6)
#define GPIO_HIMR_ph2ie_shift                                         (4)
#define GPIO_HIMR_ph1ie_shift                                         (2)
#define GPIO_HIMR_ph0ie_shift                                         (0)
#define GPIO_HIMR_ph7ie_mask                                          (0x0000C000)
#define GPIO_HIMR_ph6ie_mask                                          (0x00003000)
#define GPIO_HIMR_ph5ie_mask                                          (0x00000C00)
#define GPIO_HIMR_ph4ie_mask                                          (0x00000300)
#define GPIO_HIMR_ph3ie_mask                                          (0x000000C0)
#define GPIO_HIMR_ph2ie_mask                                          (0x00000030)
#define GPIO_HIMR_ph1ie_mask                                          (0x0000000C)
#define GPIO_HIMR_ph0ie_mask                                          (0x00000003)
#define GPIO_HIMR_ph7ie(data)                                         (0x0000C000&((data)<<14))
#define GPIO_HIMR_ph6ie(data)                                         (0x00003000&((data)<<12))
#define GPIO_HIMR_ph5ie(data)                                         (0x00000C00&((data)<<10))
#define GPIO_HIMR_ph4ie(data)                                         (0x00000300&((data)<<8))
#define GPIO_HIMR_ph3ie(data)                                         (0x000000C0&((data)<<6))
#define GPIO_HIMR_ph2ie(data)                                         (0x00000030&((data)<<4))
#define GPIO_HIMR_ph1ie(data)                                         (0x0000000C&((data)<<2))
#define GPIO_HIMR_ph0ie(data)                                         (0x00000003&(data))
#define GPIO_HIMR_get_ph7ie(data)                                     ((0x0000C000&(data))>>14)
#define GPIO_HIMR_get_ph6ie(data)                                     ((0x00003000&(data))>>12)
#define GPIO_HIMR_get_ph5ie(data)                                     ((0x00000C00&(data))>>10)
#define GPIO_HIMR_get_ph4ie(data)                                     ((0x00000300&(data))>>8)
#define GPIO_HIMR_get_ph3ie(data)                                     ((0x000000C0&(data))>>6)
#define GPIO_HIMR_get_ph2ie(data)                                     ((0x00000030&(data))>>4)
#define GPIO_HIMR_get_ph1ie(data)                                     ((0x0000000C&(data))>>2)
#define GPIO_HIMR_get_ph0ie(data)                                     (0x00000003&(data))


#define GPIO_KIMR                                                     0x18012074
#define GPIO_KIMR_reg_addr                                            "0xb8012074"
#define GPIO_KIMR_reg                                                 0xb8012074
#define GPIO_KIMR_inst_addr                                           "0x001D"
#define GPIO_KIMR_inst                                                0x001D
#define GPIO_KIMR_pk7ie_shift                                         (14)
#define GPIO_KIMR_pk6ie_shift                                         (12)
#define GPIO_KIMR_pk5ie_shift                                         (10)
#define GPIO_KIMR_pk4ie_shift                                         (8)
#define GPIO_KIMR_pk3ie_shift                                         (6)
#define GPIO_KIMR_pk2ie_shift                                         (4)
#define GPIO_KIMR_pk1ie_shift                                         (2)
#define GPIO_KIMR_pk0ie_shift                                         (0)
#define GPIO_KIMR_pk7ie_mask                                          (0x0000C000)
#define GPIO_KIMR_pk6ie_mask                                          (0x00003000)
#define GPIO_KIMR_pk5ie_mask                                          (0x00000C00)
#define GPIO_KIMR_pk4ie_mask                                          (0x00000300)
#define GPIO_KIMR_pk3ie_mask                                          (0x000000C0)
#define GPIO_KIMR_pk2ie_mask                                          (0x00000030)
#define GPIO_KIMR_pk1ie_mask                                          (0x0000000C)
#define GPIO_KIMR_pk0ie_mask                                          (0x00000003)
#define GPIO_KIMR_pk7ie(data)                                         (0x0000C000&((data)<<14))
#define GPIO_KIMR_pk6ie(data)                                         (0x00003000&((data)<<12))
#define GPIO_KIMR_pk5ie(data)                                         (0x00000C00&((data)<<10))
#define GPIO_KIMR_pk4ie(data)                                         (0x00000300&((data)<<8))
#define GPIO_KIMR_pk3ie(data)                                         (0x000000C0&((data)<<6))
#define GPIO_KIMR_pk2ie(data)                                         (0x00000030&((data)<<4))
#define GPIO_KIMR_pk1ie(data)                                         (0x0000000C&((data)<<2))
#define GPIO_KIMR_pk0ie(data)                                         (0x00000003&(data))
#define GPIO_KIMR_get_pk7ie(data)                                     ((0x0000C000&(data))>>14)
#define GPIO_KIMR_get_pk6ie(data)                                     ((0x00003000&(data))>>12)
#define GPIO_KIMR_get_pk5ie(data)                                     ((0x00000C00&(data))>>10)
#define GPIO_KIMR_get_pk4ie(data)                                     ((0x00000300&(data))>>8)
#define GPIO_KIMR_get_pk3ie(data)                                     ((0x000000C0&(data))>>6)
#define GPIO_KIMR_get_pk2ie(data)                                     ((0x00000030&(data))>>4)
#define GPIO_KIMR_get_pk1ie(data)                                     ((0x0000000C&(data))>>2)
#define GPIO_KIMR_get_pk0ie(data)                                     (0x00000003&(data))


#define GPIO_MIMR                                                     0x18012078
#define GPIO_MIMR_reg_addr                                            "0xb8012078"
#define GPIO_MIMR_reg                                                 0xb8012078
#define GPIO_MIMR_inst_addr                                           "0x001E"
#define GPIO_MIMR_inst                                                0x001E
#define GPIO_MIMR_pm7ie_shift                                         (14)
#define GPIO_MIMR_pm6ie_shift                                         (12)
#define GPIO_MIMR_pm5ie_shift                                         (10)
#define GPIO_MIMR_pm4ie_shift                                         (8)
#define GPIO_MIMR_pm3ie_shift                                         (6)
#define GPIO_MIMR_pm2ie_shift                                         (4)
#define GPIO_MIMR_pm1ie_shift                                         (2)
#define GPIO_MIMR_pm0ie_shift                                         (0)
#define GPIO_MIMR_pm7ie_mask                                          (0x0000C000)
#define GPIO_MIMR_pm6ie_mask                                          (0x00003000)
#define GPIO_MIMR_pm5ie_mask                                          (0x00000C00)
#define GPIO_MIMR_pm4ie_mask                                          (0x00000300)
#define GPIO_MIMR_pm3ie_mask                                          (0x000000C0)
#define GPIO_MIMR_pm2ie_mask                                          (0x00000030)
#define GPIO_MIMR_pm1ie_mask                                          (0x0000000C)
#define GPIO_MIMR_pm0ie_mask                                          (0x00000003)
#define GPIO_MIMR_pm7ie(data)                                         (0x0000C000&((data)<<14))
#define GPIO_MIMR_pm6ie(data)                                         (0x00003000&((data)<<12))
#define GPIO_MIMR_pm5ie(data)                                         (0x00000C00&((data)<<10))
#define GPIO_MIMR_pm4ie(data)                                         (0x00000300&((data)<<8))
#define GPIO_MIMR_pm3ie(data)                                         (0x000000C0&((data)<<6))
#define GPIO_MIMR_pm2ie(data)                                         (0x00000030&((data)<<4))
#define GPIO_MIMR_pm1ie(data)                                         (0x0000000C&((data)<<2))
#define GPIO_MIMR_pm0ie(data)                                         (0x00000003&(data))
#define GPIO_MIMR_get_pm7ie(data)                                     ((0x0000C000&(data))>>14)
#define GPIO_MIMR_get_pm6ie(data)                                     ((0x00003000&(data))>>12)
#define GPIO_MIMR_get_pm5ie(data)                                     ((0x00000C00&(data))>>10)
#define GPIO_MIMR_get_pm4ie(data)                                     ((0x00000300&(data))>>8)
#define GPIO_MIMR_get_pm3ie(data)                                     ((0x000000C0&(data))>>6)
#define GPIO_MIMR_get_pm2ie(data)                                     ((0x00000030&(data))>>4)
#define GPIO_MIMR_get_pm1ie(data)                                     ((0x0000000C&(data))>>2)
#define GPIO_MIMR_get_pm0ie(data)                                     (0x00000003&(data))


#define GPIO_NIMR                                                     0x1801207c
#define GPIO_NIMR_reg_addr                                            "0xb801207c"
#define GPIO_NIMR_reg                                                 0xb801207c
#define GPIO_NIMR_inst_addr                                           "0x001F"
#define GPIO_NIMR_inst                                                0x001F
#define GPIO_NIMR_pn7ie_shift                                         (14)
#define GPIO_NIMR_pn6ie_shift                                         (12)
#define GPIO_NIMR_pn5ie_shift                                         (10)
#define GPIO_NIMR_pn4ie_shift                                         (8)
#define GPIO_NIMR_pn3ie_shift                                         (6)
#define GPIO_NIMR_pn2ie_shift                                         (4)
#define GPIO_NIMR_pn1ie_shift                                         (2)
#define GPIO_NIMR_pn0ie_shift                                         (0)
#define GPIO_NIMR_pn7ie_mask                                          (0x0000C000)
#define GPIO_NIMR_pn6ie_mask                                          (0x00003000)
#define GPIO_NIMR_pn5ie_mask                                          (0x00000C00)
#define GPIO_NIMR_pn4ie_mask                                          (0x00000300)
#define GPIO_NIMR_pn3ie_mask                                          (0x000000C0)
#define GPIO_NIMR_pn2ie_mask                                          (0x00000030)
#define GPIO_NIMR_pn1ie_mask                                          (0x0000000C)
#define GPIO_NIMR_pn0ie_mask                                          (0x00000003)
#define GPIO_NIMR_pn7ie(data)                                         (0x0000C000&((data)<<14))
#define GPIO_NIMR_pn6ie(data)                                         (0x00003000&((data)<<12))
#define GPIO_NIMR_pn5ie(data)                                         (0x00000C00&((data)<<10))
#define GPIO_NIMR_pn4ie(data)                                         (0x00000300&((data)<<8))
#define GPIO_NIMR_pn3ie(data)                                         (0x000000C0&((data)<<6))
#define GPIO_NIMR_pn2ie(data)                                         (0x00000030&((data)<<4))
#define GPIO_NIMR_pn1ie(data)                                         (0x0000000C&((data)<<2))
#define GPIO_NIMR_pn0ie(data)                                         (0x00000003&(data))
#define GPIO_NIMR_get_pn7ie(data)                                     ((0x0000C000&(data))>>14)
#define GPIO_NIMR_get_pn6ie(data)                                     ((0x00003000&(data))>>12)
#define GPIO_NIMR_get_pn5ie(data)                                     ((0x00000C00&(data))>>10)
#define GPIO_NIMR_get_pn4ie(data)                                     ((0x00000300&(data))>>8)
#define GPIO_NIMR_get_pn3ie(data)                                     ((0x000000C0&(data))>>6)
#define GPIO_NIMR_get_pn2ie(data)                                     ((0x00000030&(data))>>4)
#define GPIO_NIMR_get_pn1ie(data)                                     ((0x0000000C&(data))>>2)
#define GPIO_NIMR_get_pn0ie(data)                                     (0x00000003&(data))


#define GPIO_PIMR                                                     0x18012080
#define GPIO_PIMR_reg_addr                                            "0xb8012080"
#define GPIO_PIMR_reg                                                 0xb8012080
#define GPIO_PIMR_inst_addr                                           "0x0020"
#define GPIO_PIMR_inst                                                0x0020
#define GPIO_PIMR_pp7ie_shift                                         (14)
#define GPIO_PIMR_pp6ie_shift                                         (12)
#define GPIO_PIMR_pp5ie_shift                                         (10)
#define GPIO_PIMR_pp4ie_shift                                         (8)
#define GPIO_PIMR_pp3ie_shift                                         (6)
#define GPIO_PIMR_pp2ie_shift                                         (4)
#define GPIO_PIMR_pp1ie_shift                                         (2)
#define GPIO_PIMR_pp0ie_shift                                         (0)
#define GPIO_PIMR_pp7ie_mask                                          (0x0000C000)
#define GPIO_PIMR_pp6ie_mask                                          (0x00003000)
#define GPIO_PIMR_pp5ie_mask                                          (0x00000C00)
#define GPIO_PIMR_pp4ie_mask                                          (0x00000300)
#define GPIO_PIMR_pp3ie_mask                                          (0x000000C0)
#define GPIO_PIMR_pp2ie_mask                                          (0x00000030)
#define GPIO_PIMR_pp1ie_mask                                          (0x0000000C)
#define GPIO_PIMR_pp0ie_mask                                          (0x00000003)
#define GPIO_PIMR_pp7ie(data)                                         (0x0000C000&((data)<<14))
#define GPIO_PIMR_pp6ie(data)                                         (0x00003000&((data)<<12))
#define GPIO_PIMR_pp5ie(data)                                         (0x00000C00&((data)<<10))
#define GPIO_PIMR_pp4ie(data)                                         (0x00000300&((data)<<8))
#define GPIO_PIMR_pp3ie(data)                                         (0x000000C0&((data)<<6))
#define GPIO_PIMR_pp2ie(data)                                         (0x00000030&((data)<<4))
#define GPIO_PIMR_pp1ie(data)                                         (0x0000000C&((data)<<2))
#define GPIO_PIMR_pp0ie(data)                                         (0x00000003&(data))
#define GPIO_PIMR_get_pp7ie(data)                                     ((0x0000C000&(data))>>14)
#define GPIO_PIMR_get_pp6ie(data)                                     ((0x00003000&(data))>>12)
#define GPIO_PIMR_get_pp5ie(data)                                     ((0x00000C00&(data))>>10)
#define GPIO_PIMR_get_pp4ie(data)                                     ((0x00000300&(data))>>8)
#define GPIO_PIMR_get_pp3ie(data)                                     ((0x000000C0&(data))>>6)
#define GPIO_PIMR_get_pp2ie(data)                                     ((0x00000030&(data))>>4)
#define GPIO_PIMR_get_pp1ie(data)                                     ((0x0000000C&(data))>>2)
#define GPIO_PIMR_get_pp0ie(data)                                     (0x00000003&(data))


#define GPIO_QIMR                                                     0x18012084
#define GPIO_QIMR_reg_addr                                            "0xb8012084"
#define GPIO_QIMR_reg                                                 0xb8012084
#define GPIO_QIMR_inst_addr                                           "0x0021"
#define GPIO_QIMR_inst                                                0x0021
#define GPIO_QIMR_pq7ie_shift                                         (14)
#define GPIO_QIMR_pq6ie_shift                                         (12)
#define GPIO_QIMR_pq5ie_shift                                         (10)
#define GPIO_QIMR_pq4ie_shift                                         (8)
#define GPIO_QIMR_pq3ie_shift                                         (6)
#define GPIO_QIMR_pq2ie_shift                                         (4)
#define GPIO_QIMR_pq1ie_shift                                         (2)
#define GPIO_QIMR_pq0ie_shift                                         (0)
#define GPIO_QIMR_pq7ie_mask                                          (0x0000C000)
#define GPIO_QIMR_pq6ie_mask                                          (0x00003000)
#define GPIO_QIMR_pq5ie_mask                                          (0x00000C00)
#define GPIO_QIMR_pq4ie_mask                                          (0x00000300)
#define GPIO_QIMR_pq3ie_mask                                          (0x000000C0)
#define GPIO_QIMR_pq2ie_mask                                          (0x00000030)
#define GPIO_QIMR_pq1ie_mask                                          (0x0000000C)
#define GPIO_QIMR_pq0ie_mask                                          (0x00000003)
#define GPIO_QIMR_pq7ie(data)                                         (0x0000C000&((data)<<14))
#define GPIO_QIMR_pq6ie(data)                                         (0x00003000&((data)<<12))
#define GPIO_QIMR_pq5ie(data)                                         (0x00000C00&((data)<<10))
#define GPIO_QIMR_pq4ie(data)                                         (0x00000300&((data)<<8))
#define GPIO_QIMR_pq3ie(data)                                         (0x000000C0&((data)<<6))
#define GPIO_QIMR_pq2ie(data)                                         (0x00000030&((data)<<4))
#define GPIO_QIMR_pq1ie(data)                                         (0x0000000C&((data)<<2))
#define GPIO_QIMR_pq0ie(data)                                         (0x00000003&(data))
#define GPIO_QIMR_get_pq7ie(data)                                     ((0x0000C000&(data))>>14)
#define GPIO_QIMR_get_pq6ie(data)                                     ((0x00003000&(data))>>12)
#define GPIO_QIMR_get_pq5ie(data)                                     ((0x00000C00&(data))>>10)
#define GPIO_QIMR_get_pq4ie(data)                                     ((0x00000300&(data))>>8)
#define GPIO_QIMR_get_pq3ie(data)                                     ((0x000000C0&(data))>>6)
#define GPIO_QIMR_get_pq2ie(data)                                     ((0x00000030&(data))>>4)
#define GPIO_QIMR_get_pq1ie(data)                                     ((0x0000000C&(data))>>2)
#define GPIO_QIMR_get_pq0ie(data)                                     (0x00000003&(data))


#define GPIO_RIMR                                                     0x18012088
#define GPIO_RIMR_reg_addr                                            "0xb8012088"
#define GPIO_RIMR_reg                                                 0xb8012088
#define GPIO_RIMR_inst_addr                                           "0x0022"
#define GPIO_RIMR_inst                                                0x0022
#define GPIO_RIMR_pr7ie_shift                                         (14)
#define GPIO_RIMR_pr6ie_shift                                         (12)
#define GPIO_RIMR_pr5ie_shift                                         (10)
#define GPIO_RIMR_pr4ie_shift                                         (8)
#define GPIO_RIMR_pr3ie_shift                                         (6)
#define GPIO_RIMR_pr2ie_shift                                         (4)
#define GPIO_RIMR_pr1ie_shift                                         (2)
#define GPIO_RIMR_pr0ie_shift                                         (0)
#define GPIO_RIMR_pr7ie_mask                                          (0x0000C000)
#define GPIO_RIMR_pr6ie_mask                                          (0x00003000)
#define GPIO_RIMR_pr5ie_mask                                          (0x00000C00)
#define GPIO_RIMR_pr4ie_mask                                          (0x00000300)
#define GPIO_RIMR_pr3ie_mask                                          (0x000000C0)
#define GPIO_RIMR_pr2ie_mask                                          (0x00000030)
#define GPIO_RIMR_pr1ie_mask                                          (0x0000000C)
#define GPIO_RIMR_pr0ie_mask                                          (0x00000003)
#define GPIO_RIMR_pr7ie(data)                                         (0x0000C000&((data)<<14))
#define GPIO_RIMR_pr6ie(data)                                         (0x00003000&((data)<<12))
#define GPIO_RIMR_pr5ie(data)                                         (0x00000C00&((data)<<10))
#define GPIO_RIMR_pr4ie(data)                                         (0x00000300&((data)<<8))
#define GPIO_RIMR_pr3ie(data)                                         (0x000000C0&((data)<<6))
#define GPIO_RIMR_pr2ie(data)                                         (0x00000030&((data)<<4))
#define GPIO_RIMR_pr1ie(data)                                         (0x0000000C&((data)<<2))
#define GPIO_RIMR_pr0ie(data)                                         (0x00000003&(data))
#define GPIO_RIMR_get_pr7ie(data)                                     ((0x0000C000&(data))>>14)
#define GPIO_RIMR_get_pr6ie(data)                                     ((0x00003000&(data))>>12)
#define GPIO_RIMR_get_pr5ie(data)                                     ((0x00000C00&(data))>>10)
#define GPIO_RIMR_get_pr4ie(data)                                     ((0x00000300&(data))>>8)
#define GPIO_RIMR_get_pr3ie(data)                                     ((0x000000C0&(data))>>6)
#define GPIO_RIMR_get_pr2ie(data)                                     ((0x00000030&(data))>>4)
#define GPIO_RIMR_get_pr1ie(data)                                     ((0x0000000C&(data))>>2)
#define GPIO_RIMR_get_pr0ie(data)                                     (0x00000003&(data))


#define GPIO_SIMR                                                     0x1801208c
#define GPIO_SIMR_reg_addr                                            "0xb801208c"
#define GPIO_SIMR_reg                                                 0xb801208c
#define GPIO_SIMR_inst_addr                                           "0x0023"
#define GPIO_SIMR_inst                                                0x0023
#define GPIO_SIMR_ps7ie_shift                                         (14)
#define GPIO_SIMR_ps6ie_shift                                         (12)
#define GPIO_SIMR_ps5ie_shift                                         (10)
#define GPIO_SIMR_ps4ie_shift                                         (8)
#define GPIO_SIMR_ps3ie_shift                                         (6)
#define GPIO_SIMR_ps2ie_shift                                         (4)
#define GPIO_SIMR_ps1ie_shift                                         (2)
#define GPIO_SIMR_ps0ie_shift                                         (0)
#define GPIO_SIMR_ps7ie_mask                                          (0x0000C000)
#define GPIO_SIMR_ps6ie_mask                                          (0x00003000)
#define GPIO_SIMR_ps5ie_mask                                          (0x00000C00)
#define GPIO_SIMR_ps4ie_mask                                          (0x00000300)
#define GPIO_SIMR_ps3ie_mask                                          (0x000000C0)
#define GPIO_SIMR_ps2ie_mask                                          (0x00000030)
#define GPIO_SIMR_ps1ie_mask                                          (0x0000000C)
#define GPIO_SIMR_ps0ie_mask                                          (0x00000003)
#define GPIO_SIMR_ps7ie(data)                                         (0x0000C000&((data)<<14))
#define GPIO_SIMR_ps6ie(data)                                         (0x00003000&((data)<<12))
#define GPIO_SIMR_ps5ie(data)                                         (0x00000C00&((data)<<10))
#define GPIO_SIMR_ps4ie(data)                                         (0x00000300&((data)<<8))
#define GPIO_SIMR_ps3ie(data)                                         (0x000000C0&((data)<<6))
#define GPIO_SIMR_ps2ie(data)                                         (0x00000030&((data)<<4))
#define GPIO_SIMR_ps1ie(data)                                         (0x0000000C&((data)<<2))
#define GPIO_SIMR_ps0ie(data)                                         (0x00000003&(data))
#define GPIO_SIMR_get_ps7ie(data)                                     ((0x0000C000&(data))>>14)
#define GPIO_SIMR_get_ps6ie(data)                                     ((0x00003000&(data))>>12)
#define GPIO_SIMR_get_ps5ie(data)                                     ((0x00000C00&(data))>>10)
#define GPIO_SIMR_get_ps4ie(data)                                     ((0x00000300&(data))>>8)
#define GPIO_SIMR_get_ps3ie(data)                                     ((0x000000C0&(data))>>6)
#define GPIO_SIMR_get_ps2ie(data)                                     ((0x00000030&(data))>>4)
#define GPIO_SIMR_get_ps1ie(data)                                     ((0x0000000C&(data))>>2)
#define GPIO_SIMR_get_ps0ie(data)                                     (0x00000003&(data))


#define GPIO_TIMR                                                     0x18012090
#define GPIO_TIMR_reg_addr                                            "0xb8012090"
#define GPIO_TIMR_reg                                                 0xb8012090
#define GPIO_TIMR_inst_addr                                           "0x0024"
#define GPIO_TIMR_inst                                                0x0024
#define GPIO_TIMR_pt7ie_shift                                         (14)
#define GPIO_TIMR_pt6ie_shift                                         (12)
#define GPIO_TIMR_pt5ie_shift                                         (10)
#define GPIO_TIMR_pt4ie_shift                                         (8)
#define GPIO_TIMR_pt3ie_shift                                         (6)
#define GPIO_TIMR_pt2ie_shift                                         (4)
#define GPIO_TIMR_pt1ie_shift                                         (2)
#define GPIO_TIMR_pt0ie_shift                                         (0)
#define GPIO_TIMR_pt7ie_mask                                          (0x0000C000)
#define GPIO_TIMR_pt6ie_mask                                          (0x00003000)
#define GPIO_TIMR_pt5ie_mask                                          (0x00000C00)
#define GPIO_TIMR_pt4ie_mask                                          (0x00000300)
#define GPIO_TIMR_pt3ie_mask                                          (0x000000C0)
#define GPIO_TIMR_pt2ie_mask                                          (0x00000030)
#define GPIO_TIMR_pt1ie_mask                                          (0x0000000C)
#define GPIO_TIMR_pt0ie_mask                                          (0x00000003)
#define GPIO_TIMR_pt7ie(data)                                         (0x0000C000&((data)<<14))
#define GPIO_TIMR_pt6ie(data)                                         (0x00003000&((data)<<12))
#define GPIO_TIMR_pt5ie(data)                                         (0x00000C00&((data)<<10))
#define GPIO_TIMR_pt4ie(data)                                         (0x00000300&((data)<<8))
#define GPIO_TIMR_pt3ie(data)                                         (0x000000C0&((data)<<6))
#define GPIO_TIMR_pt2ie(data)                                         (0x00000030&((data)<<4))
#define GPIO_TIMR_pt1ie(data)                                         (0x0000000C&((data)<<2))
#define GPIO_TIMR_pt0ie(data)                                         (0x00000003&(data))
#define GPIO_TIMR_get_pt7ie(data)                                     ((0x0000C000&(data))>>14)
#define GPIO_TIMR_get_pt6ie(data)                                     ((0x00003000&(data))>>12)
#define GPIO_TIMR_get_pt5ie(data)                                     ((0x00000C00&(data))>>10)
#define GPIO_TIMR_get_pt4ie(data)                                     ((0x00000300&(data))>>8)
#define GPIO_TIMR_get_pt3ie(data)                                     ((0x000000C0&(data))>>6)
#define GPIO_TIMR_get_pt2ie(data)                                     ((0x00000030&(data))>>4)
#define GPIO_TIMR_get_pt1ie(data)                                     ((0x0000000C&(data))>>2)
#define GPIO_TIMR_get_pt0ie(data)                                     (0x00000003&(data))


#define GPIO_UIMR                                                     0x18012094
#define GPIO_UIMR_reg_addr                                            "0xb8012094"
#define GPIO_UIMR_reg                                                 0xb8012094
#define GPIO_UIMR_inst_addr                                           "0x0025"
#define GPIO_UIMR_inst                                                0x0025
#define GPIO_UIMR_pu7ie_shift                                         (14)
#define GPIO_UIMR_pu6ie_shift                                         (12)
#define GPIO_UIMR_pu5ie_shift                                         (10)
#define GPIO_UIMR_pu4ie_shift                                         (8)
#define GPIO_UIMR_pu3ie_shift                                         (6)
#define GPIO_UIMR_pu2ie_shift                                         (4)
#define GPIO_UIMR_pu1ie_shift                                         (2)
#define GPIO_UIMR_pu0ie_shift                                         (0)
#define GPIO_UIMR_pu7ie_mask                                          (0x0000C000)
#define GPIO_UIMR_pu6ie_mask                                          (0x00003000)
#define GPIO_UIMR_pu5ie_mask                                          (0x00000C00)
#define GPIO_UIMR_pu4ie_mask                                          (0x00000300)
#define GPIO_UIMR_pu3ie_mask                                          (0x000000C0)
#define GPIO_UIMR_pu2ie_mask                                          (0x00000030)
#define GPIO_UIMR_pu1ie_mask                                          (0x0000000C)
#define GPIO_UIMR_pu0ie_mask                                          (0x00000003)
#define GPIO_UIMR_pu7ie(data)                                         (0x0000C000&((data)<<14))
#define GPIO_UIMR_pu6ie(data)                                         (0x00003000&((data)<<12))
#define GPIO_UIMR_pu5ie(data)                                         (0x00000C00&((data)<<10))
#define GPIO_UIMR_pu4ie(data)                                         (0x00000300&((data)<<8))
#define GPIO_UIMR_pu3ie(data)                                         (0x000000C0&((data)<<6))
#define GPIO_UIMR_pu2ie(data)                                         (0x00000030&((data)<<4))
#define GPIO_UIMR_pu1ie(data)                                         (0x0000000C&((data)<<2))
#define GPIO_UIMR_pu0ie(data)                                         (0x00000003&(data))
#define GPIO_UIMR_get_pu7ie(data)                                     ((0x0000C000&(data))>>14)
#define GPIO_UIMR_get_pu6ie(data)                                     ((0x00003000&(data))>>12)
#define GPIO_UIMR_get_pu5ie(data)                                     ((0x00000C00&(data))>>10)
#define GPIO_UIMR_get_pu4ie(data)                                     ((0x00000300&(data))>>8)
#define GPIO_UIMR_get_pu3ie(data)                                     ((0x000000C0&(data))>>6)
#define GPIO_UIMR_get_pu2ie(data)                                     ((0x00000030&(data))>>4)
#define GPIO_UIMR_get_pu1ie(data)                                     ((0x0000000C&(data))>>2)
#define GPIO_UIMR_get_pu0ie(data)                                     (0x00000003&(data))


#define GPIO_VIMR                                                     0x18012098
#define GPIO_VIMR_reg_addr                                            "0xb8012098"
#define GPIO_VIMR_reg                                                 0xb8012098
#define GPIO_VIMR_inst_addr                                           "0x0026"
#define GPIO_VIMR_inst                                                0x0026
#define GPIO_VIMR_pv7ie_shift                                         (14)
#define GPIO_VIMR_pv6ie_shift                                         (12)
#define GPIO_VIMR_pv5ie_shift                                         (10)
#define GPIO_VIMR_pv4ie_shift                                         (8)
#define GPIO_VIMR_pv3ie_shift                                         (6)
#define GPIO_VIMR_pv2ie_shift                                         (4)
#define GPIO_VIMR_pv1ie_shift                                         (2)
#define GPIO_VIMR_pv0ie_shift                                         (0)
#define GPIO_VIMR_pv7ie_mask                                          (0x0000C000)
#define GPIO_VIMR_pv6ie_mask                                          (0x00003000)
#define GPIO_VIMR_pv5ie_mask                                          (0x00000C00)
#define GPIO_VIMR_pv4ie_mask                                          (0x00000300)
#define GPIO_VIMR_pv3ie_mask                                          (0x000000C0)
#define GPIO_VIMR_pv2ie_mask                                          (0x00000030)
#define GPIO_VIMR_pv1ie_mask                                          (0x0000000C)
#define GPIO_VIMR_pv0ie_mask                                          (0x00000003)
#define GPIO_VIMR_pv7ie(data)                                         (0x0000C000&((data)<<14))
#define GPIO_VIMR_pv6ie(data)                                         (0x00003000&((data)<<12))
#define GPIO_VIMR_pv5ie(data)                                         (0x00000C00&((data)<<10))
#define GPIO_VIMR_pv4ie(data)                                         (0x00000300&((data)<<8))
#define GPIO_VIMR_pv3ie(data)                                         (0x000000C0&((data)<<6))
#define GPIO_VIMR_pv2ie(data)                                         (0x00000030&((data)<<4))
#define GPIO_VIMR_pv1ie(data)                                         (0x0000000C&((data)<<2))
#define GPIO_VIMR_pv0ie(data)                                         (0x00000003&(data))
#define GPIO_VIMR_get_pv7ie(data)                                     ((0x0000C000&(data))>>14)
#define GPIO_VIMR_get_pv6ie(data)                                     ((0x00003000&(data))>>12)
#define GPIO_VIMR_get_pv5ie(data)                                     ((0x00000C00&(data))>>10)
#define GPIO_VIMR_get_pv4ie(data)                                     ((0x00000300&(data))>>8)
#define GPIO_VIMR_get_pv3ie(data)                                     ((0x000000C0&(data))>>6)
#define GPIO_VIMR_get_pv2ie(data)                                     ((0x00000030&(data))>>4)
#define GPIO_VIMR_get_pv1ie(data)                                     ((0x0000000C&(data))>>2)
#define GPIO_VIMR_get_pv0ie(data)                                     (0x00000003&(data))


#define GPIO_ER                                                       0x1801209c
#define GPIO_ER_reg_addr                                              "0xb801209c"
#define GPIO_ER_reg                                                   0xb801209c
#define GPIO_ER_inst_addr                                             "0x0027"
#define GPIO_ER_inst                                                  0x0027
#define GPIO_ER_gpidcb_shift                                          (0)
#define GPIO_ER_gpidcb_mask                                           (0x0000000F)
#define GPIO_ER_gpidcb(data)                                          (0x0000000F&(data))
#define GPIO_ER_get_gpidcb(data)                                      (0x0000000F&(data))


#define PFS                                                           0x180120a0
#define PFS_reg_addr                                                  "0xb80120a0"
#define PFS_reg                                                       0xb80120a0
#define PFS_inst_addr                                                 "0x0028"
#define PFS_inst                                                      0x0028
#define PFS_gpiof7_sel_shift                                          (28)
#define PFS_gpiof6_sel_shift                                          (24)
#define PFS_gpiof5_sel_shift                                          (20)
#define PFS_gpiof4_sel_shift                                          (16)
#define PFS_gpiof3_sel_shift                                          (12)
#define PFS_gpiof2_sel_shift                                          (8)
#define PFS_gpiof1_sel_shift                                          (4)
#define PFS_gpiof0_sel_shift                                          (0)
#define PFS_gpiof7_sel_mask                                           (0xF0000000)
#define PFS_gpiof6_sel_mask                                           (0x0F000000)
#define PFS_gpiof5_sel_mask                                           (0x00F00000)
#define PFS_gpiof4_sel_mask                                           (0x000F0000)
#define PFS_gpiof3_sel_mask                                           (0x0000F000)
#define PFS_gpiof2_sel_mask                                           (0x00000F00)
#define PFS_gpiof1_sel_mask                                           (0x000000F0)
#define PFS_gpiof0_sel_mask                                           (0x0000000F)
#define PFS_gpiof7_sel(data)                                          (0xF0000000&((data)<<28))
#define PFS_gpiof6_sel(data)                                          (0x0F000000&((data)<<24))
#define PFS_gpiof5_sel(data)                                          (0x00F00000&((data)<<20))
#define PFS_gpiof4_sel(data)                                          (0x000F0000&((data)<<16))
#define PFS_gpiof3_sel(data)                                          (0x0000F000&((data)<<12))
#define PFS_gpiof2_sel(data)                                          (0x00000F00&((data)<<8))
#define PFS_gpiof1_sel(data)                                          (0x000000F0&((data)<<4))
#define PFS_gpiof0_sel(data)                                          (0x0000000F&(data))
#define PFS_get_gpiof7_sel(data)                                      ((0xF0000000&(data))>>28)
#define PFS_get_gpiof6_sel(data)                                      ((0x0F000000&(data))>>24)
#define PFS_get_gpiof5_sel(data)                                      ((0x00F00000&(data))>>20)
#define PFS_get_gpiof4_sel(data)                                      ((0x000F0000&(data))>>16)
#define PFS_get_gpiof3_sel(data)                                      ((0x0000F000&(data))>>12)
#define PFS_get_gpiof2_sel(data)                                      ((0x00000F00&(data))>>8)
#define PFS_get_gpiof1_sel(data)                                      ((0x000000F0&(data))>>4)
#define PFS_get_gpiof0_sel(data)                                      (0x0000000F&(data))


#define PGS                                                           0x180120a4
#define PGS_reg_addr                                                  "0xb80120a4"
#define PGS_reg                                                       0xb80120a4
#define PGS_inst_addr                                                 "0x0029"
#define PGS_inst                                                      0x0029
#define PGS_gpiog7_sel_shift                                          (28)
#define PGS_gpiog6_sel_shift                                          (24)
#define PGS_gpiog5_sel_shift                                          (20)
#define PGS_gpiog4_sel_shift                                          (16)
#define PGS_gpiog3_sel_shift                                          (12)
#define PGS_gpiog2_sel_shift                                          (8)
#define PGS_gpiog1_sel_shift                                          (4)
#define PGS_gpiog0_sel_shift                                          (0)
#define PGS_gpiog7_sel_mask                                           (0xF0000000)
#define PGS_gpiog6_sel_mask                                           (0x0F000000)
#define PGS_gpiog5_sel_mask                                           (0x00F00000)
#define PGS_gpiog4_sel_mask                                           (0x000F0000)
#define PGS_gpiog3_sel_mask                                           (0x0000F000)
#define PGS_gpiog2_sel_mask                                           (0x00000F00)
#define PGS_gpiog1_sel_mask                                           (0x000000F0)
#define PGS_gpiog0_sel_mask                                           (0x0000000F)
#define PGS_gpiog7_sel(data)                                          (0xF0000000&((data)<<28))
#define PGS_gpiog6_sel(data)                                          (0x0F000000&((data)<<24))
#define PGS_gpiog5_sel(data)                                          (0x00F00000&((data)<<20))
#define PGS_gpiog4_sel(data)                                          (0x000F0000&((data)<<16))
#define PGS_gpiog3_sel(data)                                          (0x0000F000&((data)<<12))
#define PGS_gpiog2_sel(data)                                          (0x00000F00&((data)<<8))
#define PGS_gpiog1_sel(data)                                          (0x000000F0&((data)<<4))
#define PGS_gpiog0_sel(data)                                          (0x0000000F&(data))
#define PGS_get_gpiog7_sel(data)                                      ((0xF0000000&(data))>>28)
#define PGS_get_gpiog6_sel(data)                                      ((0x0F000000&(data))>>24)
#define PGS_get_gpiog5_sel(data)                                      ((0x00F00000&(data))>>20)
#define PGS_get_gpiog4_sel(data)                                      ((0x000F0000&(data))>>16)
#define PGS_get_gpiog3_sel(data)                                      ((0x0000F000&(data))>>12)
#define PGS_get_gpiog2_sel(data)                                      ((0x00000F00&(data))>>8)
#define PGS_get_gpiog1_sel(data)                                      ((0x000000F0&(data))>>4)
#define PGS_get_gpiog0_sel(data)                                      (0x0000000F&(data))


#define PHS                                                           0x180120a8
#define PHS_reg_addr                                                  "0xb80120a8"
#define PHS_reg                                                       0xb80120a8
#define PHS_inst_addr                                                 "0x002A"
#define PHS_inst                                                      0x002A
#define PHS_gpioh7_sel_shift                                          (28)
#define PHS_gpioh6_sel_shift                                          (24)
#define PHS_gpioh5_sel_shift                                          (20)
#define PHS_gpioh4_sel_shift                                          (16)
#define PHS_gpioh3_sel_shift                                          (12)
#define PHS_gpioh2_sel_shift                                          (8)
#define PHS_gpioh1_sel_shift                                          (4)
#define PHS_gpioh0_sel_shift                                          (0)
#define PHS_gpioh7_sel_mask                                           (0xF0000000)
#define PHS_gpioh6_sel_mask                                           (0x0F000000)
#define PHS_gpioh5_sel_mask                                           (0x00F00000)
#define PHS_gpioh4_sel_mask                                           (0x000F0000)
#define PHS_gpioh3_sel_mask                                           (0x0000F000)
#define PHS_gpioh2_sel_mask                                           (0x00000F00)
#define PHS_gpioh1_sel_mask                                           (0x000000F0)
#define PHS_gpioh0_sel_mask                                           (0x0000000F)
#define PHS_gpioh7_sel(data)                                          (0xF0000000&((data)<<28))
#define PHS_gpioh6_sel(data)                                          (0x0F000000&((data)<<24))
#define PHS_gpioh5_sel(data)                                          (0x00F00000&((data)<<20))
#define PHS_gpioh4_sel(data)                                          (0x000F0000&((data)<<16))
#define PHS_gpioh3_sel(data)                                          (0x0000F000&((data)<<12))
#define PHS_gpioh2_sel(data)                                          (0x00000F00&((data)<<8))
#define PHS_gpioh1_sel(data)                                          (0x000000F0&((data)<<4))
#define PHS_gpioh0_sel(data)                                          (0x0000000F&(data))
#define PHS_get_gpioh7_sel(data)                                      ((0xF0000000&(data))>>28)
#define PHS_get_gpioh6_sel(data)                                      ((0x0F000000&(data))>>24)
#define PHS_get_gpioh5_sel(data)                                      ((0x00F00000&(data))>>20)
#define PHS_get_gpioh4_sel(data)                                      ((0x000F0000&(data))>>16)
#define PHS_get_gpioh3_sel(data)                                      ((0x0000F000&(data))>>12)
#define PHS_get_gpioh2_sel(data)                                      ((0x00000F00&(data))>>8)
#define PHS_get_gpioh1_sel(data)                                      ((0x000000F0&(data))>>4)
#define PHS_get_gpioh0_sel(data)                                      (0x0000000F&(data))


#define PKS                                                           0x180120ac
#define PKS_reg_addr                                                  "0xb80120ac"
#define PKS_reg                                                       0xb80120ac
#define PKS_inst_addr                                                 "0x002B"
#define PKS_inst                                                      0x002B
#define PKS_gpiok7_sel_shift                                          (28)
#define PKS_gpiok6_sel_shift                                          (24)
#define PKS_gpiok5_sel_shift                                          (20)
#define PKS_gpiok4_sel_shift                                          (16)
#define PKS_gpiok3_sel_shift                                          (12)
#define PKS_gpiok2_sel_shift                                          (8)
#define PKS_gpiok1_sel_shift                                          (4)
#define PKS_gpiok0_sel_shift                                          (0)
#define PKS_gpiok7_sel_mask                                           (0xF0000000)
#define PKS_gpiok6_sel_mask                                           (0x0F000000)
#define PKS_gpiok5_sel_mask                                           (0x00F00000)
#define PKS_gpiok4_sel_mask                                           (0x000F0000)
#define PKS_gpiok3_sel_mask                                           (0x0000F000)
#define PKS_gpiok2_sel_mask                                           (0x00000F00)
#define PKS_gpiok1_sel_mask                                           (0x000000F0)
#define PKS_gpiok0_sel_mask                                           (0x0000000F)
#define PKS_gpiok7_sel(data)                                          (0xF0000000&((data)<<28))
#define PKS_gpiok6_sel(data)                                          (0x0F000000&((data)<<24))
#define PKS_gpiok5_sel(data)                                          (0x00F00000&((data)<<20))
#define PKS_gpiok4_sel(data)                                          (0x000F0000&((data)<<16))
#define PKS_gpiok3_sel(data)                                          (0x0000F000&((data)<<12))
#define PKS_gpiok2_sel(data)                                          (0x00000F00&((data)<<8))
#define PKS_gpiok1_sel(data)                                          (0x000000F0&((data)<<4))
#define PKS_gpiok0_sel(data)                                          (0x0000000F&(data))
#define PKS_get_gpiok7_sel(data)                                      ((0xF0000000&(data))>>28)
#define PKS_get_gpiok6_sel(data)                                      ((0x0F000000&(data))>>24)
#define PKS_get_gpiok5_sel(data)                                      ((0x00F00000&(data))>>20)
#define PKS_get_gpiok4_sel(data)                                      ((0x000F0000&(data))>>16)
#define PKS_get_gpiok3_sel(data)                                      ((0x0000F000&(data))>>12)
#define PKS_get_gpiok2_sel(data)                                      ((0x00000F00&(data))>>8)
#define PKS_get_gpiok1_sel(data)                                      ((0x000000F0&(data))>>4)
#define PKS_get_gpiok0_sel(data)                                      (0x0000000F&(data))


#define PMS                                                           0x180120b0
#define PMS_reg_addr                                                  "0xb80120b0"
#define PMS_reg                                                       0xb80120b0
#define PMS_inst_addr                                                 "0x002C"
#define PMS_inst                                                      0x002C
#define PMS_gpiom7_sel_shift                                          (28)
#define PMS_gpiom6_sel_shift                                          (24)
#define PMS_gpiom5_sel_shift                                          (20)
#define PMS_gpiom4_sel_shift                                          (16)
#define PMS_gpiom3_sel_shift                                          (12)
#define PMS_gpiom2_sel_shift                                          (8)
#define PMS_gpiom1_sel_shift                                          (4)
#define PMS_gpiom0_sel_shift                                          (0)
#define PMS_gpiom7_sel_mask                                           (0xF0000000)
#define PMS_gpiom6_sel_mask                                           (0x0F000000)
#define PMS_gpiom5_sel_mask                                           (0x00F00000)
#define PMS_gpiom4_sel_mask                                           (0x000F0000)
#define PMS_gpiom3_sel_mask                                           (0x0000F000)
#define PMS_gpiom2_sel_mask                                           (0x00000F00)
#define PMS_gpiom1_sel_mask                                           (0x000000F0)
#define PMS_gpiom0_sel_mask                                           (0x0000000F)
#define PMS_gpiom7_sel(data)                                          (0xF0000000&((data)<<28))
#define PMS_gpiom6_sel(data)                                          (0x0F000000&((data)<<24))
#define PMS_gpiom5_sel(data)                                          (0x00F00000&((data)<<20))
#define PMS_gpiom4_sel(data)                                          (0x000F0000&((data)<<16))
#define PMS_gpiom3_sel(data)                                          (0x0000F000&((data)<<12))
#define PMS_gpiom2_sel(data)                                          (0x00000F00&((data)<<8))
#define PMS_gpiom1_sel(data)                                          (0x000000F0&((data)<<4))
#define PMS_gpiom0_sel(data)                                          (0x0000000F&(data))
#define PMS_get_gpiom7_sel(data)                                      ((0xF0000000&(data))>>28)
#define PMS_get_gpiom6_sel(data)                                      ((0x0F000000&(data))>>24)
#define PMS_get_gpiom5_sel(data)                                      ((0x00F00000&(data))>>20)
#define PMS_get_gpiom4_sel(data)                                      ((0x000F0000&(data))>>16)
#define PMS_get_gpiom3_sel(data)                                      ((0x0000F000&(data))>>12)
#define PMS_get_gpiom2_sel(data)                                      ((0x00000F00&(data))>>8)
#define PMS_get_gpiom1_sel(data)                                      ((0x000000F0&(data))>>4)
#define PMS_get_gpiom0_sel(data)                                      (0x0000000F&(data))


#define PNS                                                           0x180120b4
#define PNS_reg_addr                                                  "0xb80120b4"
#define PNS_reg                                                       0xb80120b4
#define PNS_inst_addr                                                 "0x002D"
#define PNS_inst                                                      0x002D
#define PNS_gpion7_sel_shift                                          (28)
#define PNS_gpion6_sel_shift                                          (24)
#define PNS_gpion5_sel_shift                                          (20)
#define PNS_gpion4_sel_shift                                          (16)
#define PNS_gpion3_sel_shift                                          (12)
#define PNS_gpion2_sel_shift                                          (8)
#define PNS_gpion1_sel_shift                                          (4)
#define PNS_gpion0_sel_shift                                          (0)
#define PNS_gpion7_sel_mask                                           (0xF0000000)
#define PNS_gpion6_sel_mask                                           (0x0F000000)
#define PNS_gpion5_sel_mask                                           (0x00F00000)
#define PNS_gpion4_sel_mask                                           (0x000F0000)
#define PNS_gpion3_sel_mask                                           (0x0000F000)
#define PNS_gpion2_sel_mask                                           (0x00000F00)
#define PNS_gpion1_sel_mask                                           (0x000000F0)
#define PNS_gpion0_sel_mask                                           (0x0000000F)
#define PNS_gpion7_sel(data)                                          (0xF0000000&((data)<<28))
#define PNS_gpion6_sel(data)                                          (0x0F000000&((data)<<24))
#define PNS_gpion5_sel(data)                                          (0x00F00000&((data)<<20))
#define PNS_gpion4_sel(data)                                          (0x000F0000&((data)<<16))
#define PNS_gpion3_sel(data)                                          (0x0000F000&((data)<<12))
#define PNS_gpion2_sel(data)                                          (0x00000F00&((data)<<8))
#define PNS_gpion1_sel(data)                                          (0x000000F0&((data)<<4))
#define PNS_gpion0_sel(data)                                          (0x0000000F&(data))
#define PNS_get_gpion7_sel(data)                                      ((0xF0000000&(data))>>28)
#define PNS_get_gpion6_sel(data)                                      ((0x0F000000&(data))>>24)
#define PNS_get_gpion5_sel(data)                                      ((0x00F00000&(data))>>20)
#define PNS_get_gpion4_sel(data)                                      ((0x000F0000&(data))>>16)
#define PNS_get_gpion3_sel(data)                                      ((0x0000F000&(data))>>12)
#define PNS_get_gpion2_sel(data)                                      ((0x00000F00&(data))>>8)
#define PNS_get_gpion1_sel(data)                                      ((0x000000F0&(data))>>4)
#define PNS_get_gpion0_sel(data)                                      (0x0000000F&(data))


#define PPS                                                           0x180120b8
#define PPS_reg_addr                                                  "0xb80120b8"
#define PPS_reg                                                       0xb80120b8
#define PPS_inst_addr                                                 "0x002E"
#define PPS_inst                                                      0x002E
#define PPS_gpiop7_sel_shift                                          (28)
#define PPS_gpiop6_sel_shift                                          (24)
#define PPS_gpiop5_sel_shift                                          (20)
#define PPS_gpiop4_sel_shift                                          (16)
#define PPS_gpiop3_sel_shift                                          (12)
#define PPS_gpiop2_sel_shift                                          (8)
#define PPS_gpiop1_sel_shift                                          (4)
#define PPS_gpiop0_sel_shift                                          (0)
#define PPS_gpiop7_sel_mask                                           (0xF0000000)
#define PPS_gpiop6_sel_mask                                           (0x0F000000)
#define PPS_gpiop5_sel_mask                                           (0x00F00000)
#define PPS_gpiop4_sel_mask                                           (0x000F0000)
#define PPS_gpiop3_sel_mask                                           (0x0000F000)
#define PPS_gpiop2_sel_mask                                           (0x00000F00)
#define PPS_gpiop1_sel_mask                                           (0x000000F0)
#define PPS_gpiop0_sel_mask                                           (0x0000000F)
#define PPS_gpiop7_sel(data)                                          (0xF0000000&((data)<<28))
#define PPS_gpiop6_sel(data)                                          (0x0F000000&((data)<<24))
#define PPS_gpiop5_sel(data)                                          (0x00F00000&((data)<<20))
#define PPS_gpiop4_sel(data)                                          (0x000F0000&((data)<<16))
#define PPS_gpiop3_sel(data)                                          (0x0000F000&((data)<<12))
#define PPS_gpiop2_sel(data)                                          (0x00000F00&((data)<<8))
#define PPS_gpiop1_sel(data)                                          (0x000000F0&((data)<<4))
#define PPS_gpiop0_sel(data)                                          (0x0000000F&(data))
#define PPS_get_gpiop7_sel(data)                                      ((0xF0000000&(data))>>28)
#define PPS_get_gpiop6_sel(data)                                      ((0x0F000000&(data))>>24)
#define PPS_get_gpiop5_sel(data)                                      ((0x00F00000&(data))>>20)
#define PPS_get_gpiop4_sel(data)                                      ((0x000F0000&(data))>>16)
#define PPS_get_gpiop3_sel(data)                                      ((0x0000F000&(data))>>12)
#define PPS_get_gpiop2_sel(data)                                      ((0x00000F00&(data))>>8)
#define PPS_get_gpiop1_sel(data)                                      ((0x000000F0&(data))>>4)
#define PPS_get_gpiop0_sel(data)                                      (0x0000000F&(data))


#define PQS                                                           0x180120bc
#define PQS_reg_addr                                                  "0xb80120bc"
#define PQS_reg                                                       0xb80120bc
#define PQS_inst_addr                                                 "0x002F"
#define PQS_inst                                                      0x002F
#define PQS_gpioq7_sel_shift                                          (28)
#define PQS_gpioq6_sel_shift                                          (24)
#define PQS_gpioq5_sel_shift                                          (20)
#define PQS_gpioq4_sel_shift                                          (16)
#define PQS_gpioq3_sel_shift                                          (12)
#define PQS_gpioq2_sel_shift                                          (8)
#define PQS_gpioq1_sel_shift                                          (4)
#define PQS_gpioq0_sel_shift                                          (0)
#define PQS_gpioq7_sel_mask                                           (0xF0000000)
#define PQS_gpioq6_sel_mask                                           (0x0F000000)
#define PQS_gpioq5_sel_mask                                           (0x00F00000)
#define PQS_gpioq4_sel_mask                                           (0x000F0000)
#define PQS_gpioq3_sel_mask                                           (0x0000F000)
#define PQS_gpioq2_sel_mask                                           (0x00000F00)
#define PQS_gpioq1_sel_mask                                           (0x000000F0)
#define PQS_gpioq0_sel_mask                                           (0x0000000F)
#define PQS_gpioq7_sel(data)                                          (0xF0000000&((data)<<28))
#define PQS_gpioq6_sel(data)                                          (0x0F000000&((data)<<24))
#define PQS_gpioq5_sel(data)                                          (0x00F00000&((data)<<20))
#define PQS_gpioq4_sel(data)                                          (0x000F0000&((data)<<16))
#define PQS_gpioq3_sel(data)                                          (0x0000F000&((data)<<12))
#define PQS_gpioq2_sel(data)                                          (0x00000F00&((data)<<8))
#define PQS_gpioq1_sel(data)                                          (0x000000F0&((data)<<4))
#define PQS_gpioq0_sel(data)                                          (0x0000000F&(data))
#define PQS_get_gpioq7_sel(data)                                      ((0xF0000000&(data))>>28)
#define PQS_get_gpioq6_sel(data)                                      ((0x0F000000&(data))>>24)
#define PQS_get_gpioq5_sel(data)                                      ((0x00F00000&(data))>>20)
#define PQS_get_gpioq4_sel(data)                                      ((0x000F0000&(data))>>16)
#define PQS_get_gpioq3_sel(data)                                      ((0x0000F000&(data))>>12)
#define PQS_get_gpioq2_sel(data)                                      ((0x00000F00&(data))>>8)
#define PQS_get_gpioq1_sel(data)                                      ((0x000000F0&(data))>>4)
#define PQS_get_gpioq0_sel(data)                                      (0x0000000F&(data))


#define PRS                                                           0x180120c0
#define PRS_reg_addr                                                  "0xb80120c0"
#define PRS_reg                                                       0xb80120c0
#define PRS_inst_addr                                                 "0x0030"
#define PRS_inst                                                      0x0030
#define PRS_gpior7_sel_shift                                          (28)
#define PRS_gpior6_sel_shift                                          (24)
#define PRS_gpior5_sel_shift                                          (20)
#define PRS_gpior4_sel_shift                                          (16)
#define PRS_gpior3_sel_shift                                          (12)
#define PRS_gpior2_sel_shift                                          (8)
#define PRS_gpior1_sel_shift                                          (4)
#define PRS_gpior0_sel_shift                                          (0)
#define PRS_gpior7_sel_mask                                           (0xF0000000)
#define PRS_gpior6_sel_mask                                           (0x0F000000)
#define PRS_gpior5_sel_mask                                           (0x00F00000)
#define PRS_gpior4_sel_mask                                           (0x000F0000)
#define PRS_gpior3_sel_mask                                           (0x0000F000)
#define PRS_gpior2_sel_mask                                           (0x00000F00)
#define PRS_gpior1_sel_mask                                           (0x000000F0)
#define PRS_gpior0_sel_mask                                           (0x0000000F)
#define PRS_gpior7_sel(data)                                          (0xF0000000&((data)<<28))
#define PRS_gpior6_sel(data)                                          (0x0F000000&((data)<<24))
#define PRS_gpior5_sel(data)                                          (0x00F00000&((data)<<20))
#define PRS_gpior4_sel(data)                                          (0x000F0000&((data)<<16))
#define PRS_gpior3_sel(data)                                          (0x0000F000&((data)<<12))
#define PRS_gpior2_sel(data)                                          (0x00000F00&((data)<<8))
#define PRS_gpior1_sel(data)                                          (0x000000F0&((data)<<4))
#define PRS_gpior0_sel(data)                                          (0x0000000F&(data))
#define PRS_get_gpior7_sel(data)                                      ((0xF0000000&(data))>>28)
#define PRS_get_gpior6_sel(data)                                      ((0x0F000000&(data))>>24)
#define PRS_get_gpior5_sel(data)                                      ((0x00F00000&(data))>>20)
#define PRS_get_gpior4_sel(data)                                      ((0x000F0000&(data))>>16)
#define PRS_get_gpior3_sel(data)                                      ((0x0000F000&(data))>>12)
#define PRS_get_gpior2_sel(data)                                      ((0x00000F00&(data))>>8)
#define PRS_get_gpior1_sel(data)                                      ((0x000000F0&(data))>>4)
#define PRS_get_gpior0_sel(data)                                      (0x0000000F&(data))


#define PSS                                                           0x180120c4
#define PSS_reg_addr                                                  "0xb80120c4"
#define PSS_reg                                                       0xb80120c4
#define PSS_inst_addr                                                 "0x0031"
#define PSS_inst                                                      0x0031
#define PSS_gpios7_sel_shift                                          (28)
#define PSS_gpios6_sel_shift                                          (24)
#define PSS_gpios5_sel_shift                                          (20)
#define PSS_gpios4_sel_shift                                          (16)
#define PSS_gpios3_sel_shift                                          (12)
#define PSS_gpios2_sel_shift                                          (8)
#define PSS_gpios1_sel_shift                                          (4)
#define PSS_gpios0_sel_shift                                          (0)
#define PSS_gpios7_sel_mask                                           (0xF0000000)
#define PSS_gpios6_sel_mask                                           (0x0F000000)
#define PSS_gpios5_sel_mask                                           (0x00F00000)
#define PSS_gpios4_sel_mask                                           (0x000F0000)
#define PSS_gpios3_sel_mask                                           (0x0000F000)
#define PSS_gpios2_sel_mask                                           (0x00000F00)
#define PSS_gpios1_sel_mask                                           (0x000000F0)
#define PSS_gpios0_sel_mask                                           (0x0000000F)
#define PSS_gpios7_sel(data)                                          (0xF0000000&((data)<<28))
#define PSS_gpios6_sel(data)                                          (0x0F000000&((data)<<24))
#define PSS_gpios5_sel(data)                                          (0x00F00000&((data)<<20))
#define PSS_gpios4_sel(data)                                          (0x000F0000&((data)<<16))
#define PSS_gpios3_sel(data)                                          (0x0000F000&((data)<<12))
#define PSS_gpios2_sel(data)                                          (0x00000F00&((data)<<8))
#define PSS_gpios1_sel(data)                                          (0x000000F0&((data)<<4))
#define PSS_gpios0_sel(data)                                          (0x0000000F&(data))
#define PSS_get_gpios7_sel(data)                                      ((0xF0000000&(data))>>28)
#define PSS_get_gpios6_sel(data)                                      ((0x0F000000&(data))>>24)
#define PSS_get_gpios5_sel(data)                                      ((0x00F00000&(data))>>20)
#define PSS_get_gpios4_sel(data)                                      ((0x000F0000&(data))>>16)
#define PSS_get_gpios3_sel(data)                                      ((0x0000F000&(data))>>12)
#define PSS_get_gpios2_sel(data)                                      ((0x00000F00&(data))>>8)
#define PSS_get_gpios1_sel(data)                                      ((0x000000F0&(data))>>4)
#define PSS_get_gpios0_sel(data)                                      (0x0000000F&(data))


#define PTS                                                           0x180120c8
#define PTS_reg_addr                                                  "0xb80120c8"
#define PTS_reg                                                       0xb80120c8
#define PTS_inst_addr                                                 "0x0032"
#define PTS_inst                                                      0x0032
#define PTS_gpiot7_sel_shift                                          (28)
#define PTS_gpiot6_sel_shift                                          (24)
#define PTS_gpiot5_sel_shift                                          (20)
#define PTS_gpiot4_sel_shift                                          (16)
#define PTS_gpiot3_sel_shift                                          (12)
#define PTS_gpiot2_sel_shift                                          (8)
#define PTS_gpiot1_sel_shift                                          (4)
#define PTS_gpiot0_sel_shift                                          (0)
#define PTS_gpiot7_sel_mask                                           (0xF0000000)
#define PTS_gpiot6_sel_mask                                           (0x0F000000)
#define PTS_gpiot5_sel_mask                                           (0x00F00000)
#define PTS_gpiot4_sel_mask                                           (0x000F0000)
#define PTS_gpiot3_sel_mask                                           (0x0000F000)
#define PTS_gpiot2_sel_mask                                           (0x00000F00)
#define PTS_gpiot1_sel_mask                                           (0x000000F0)
#define PTS_gpiot0_sel_mask                                           (0x0000000F)
#define PTS_gpiot7_sel(data)                                          (0xF0000000&((data)<<28))
#define PTS_gpiot6_sel(data)                                          (0x0F000000&((data)<<24))
#define PTS_gpiot5_sel(data)                                          (0x00F00000&((data)<<20))
#define PTS_gpiot4_sel(data)                                          (0x000F0000&((data)<<16))
#define PTS_gpiot3_sel(data)                                          (0x0000F000&((data)<<12))
#define PTS_gpiot2_sel(data)                                          (0x00000F00&((data)<<8))
#define PTS_gpiot1_sel(data)                                          (0x000000F0&((data)<<4))
#define PTS_gpiot0_sel(data)                                          (0x0000000F&(data))
#define PTS_get_gpiot7_sel(data)                                      ((0xF0000000&(data))>>28)
#define PTS_get_gpiot6_sel(data)                                      ((0x0F000000&(data))>>24)
#define PTS_get_gpiot5_sel(data)                                      ((0x00F00000&(data))>>20)
#define PTS_get_gpiot4_sel(data)                                      ((0x000F0000&(data))>>16)
#define PTS_get_gpiot3_sel(data)                                      ((0x0000F000&(data))>>12)
#define PTS_get_gpiot2_sel(data)                                      ((0x00000F00&(data))>>8)
#define PTS_get_gpiot1_sel(data)                                      ((0x000000F0&(data))>>4)
#define PTS_get_gpiot0_sel(data)                                      (0x0000000F&(data))


#define PUS                                                           0x180120cc
#define PUS_reg_addr                                                  "0xb80120cc"
#define PUS_reg                                                       0xb80120cc
#define PUS_inst_addr                                                 "0x0033"
#define PUS_inst                                                      0x0033
#define PUS_gpiou7_sel_shift                                          (28)
#define PUS_gpiou6_sel_shift                                          (24)
#define PUS_gpiou5_sel_shift                                          (20)
#define PUS_gpiou4_sel_shift                                          (16)
#define PUS_gpiou3_sel_shift                                          (12)
#define PUS_gpiou2_sel_shift                                          (8)
#define PUS_gpiou1_sel_shift                                          (4)
#define PUS_gpiou0_sel_shift                                          (0)
#define PUS_gpiou7_sel_mask                                           (0xF0000000)
#define PUS_gpiou6_sel_mask                                           (0x0F000000)
#define PUS_gpiou5_sel_mask                                           (0x00F00000)
#define PUS_gpiou4_sel_mask                                           (0x000F0000)
#define PUS_gpiou3_sel_mask                                           (0x0000F000)
#define PUS_gpiou2_sel_mask                                           (0x00000F00)
#define PUS_gpiou1_sel_mask                                           (0x000000F0)
#define PUS_gpiou0_sel_mask                                           (0x0000000F)
#define PUS_gpiou7_sel(data)                                          (0xF0000000&((data)<<28))
#define PUS_gpiou6_sel(data)                                          (0x0F000000&((data)<<24))
#define PUS_gpiou5_sel(data)                                          (0x00F00000&((data)<<20))
#define PUS_gpiou4_sel(data)                                          (0x000F0000&((data)<<16))
#define PUS_gpiou3_sel(data)                                          (0x0000F000&((data)<<12))
#define PUS_gpiou2_sel(data)                                          (0x00000F00&((data)<<8))
#define PUS_gpiou1_sel(data)                                          (0x000000F0&((data)<<4))
#define PUS_gpiou0_sel(data)                                          (0x0000000F&(data))
#define PUS_get_gpiou7_sel(data)                                      ((0xF0000000&(data))>>28)
#define PUS_get_gpiou6_sel(data)                                      ((0x0F000000&(data))>>24)
#define PUS_get_gpiou5_sel(data)                                      ((0x00F00000&(data))>>20)
#define PUS_get_gpiou4_sel(data)                                      ((0x000F0000&(data))>>16)
#define PUS_get_gpiou3_sel(data)                                      ((0x0000F000&(data))>>12)
#define PUS_get_gpiou2_sel(data)                                      ((0x00000F00&(data))>>8)
#define PUS_get_gpiou1_sel(data)                                      ((0x000000F0&(data))>>4)
#define PUS_get_gpiou0_sel(data)                                      (0x0000000F&(data))


#define PVS                                                           0x180120d0
#define PVS_reg_addr                                                  "0xb80120d0"
#define PVS_reg                                                       0xb80120d0
#define PVS_inst_addr                                                 "0x0034"
#define PVS_inst                                                      0x0034
#define PVS_gpiov7_sel_shift                                          (28)
#define PVS_gpiov6_sel_shift                                          (24)
#define PVS_gpiov5_sel_shift                                          (20)
#define PVS_gpiov4_sel_shift                                          (16)
#define PVS_gpiov3_sel_shift                                          (12)
#define PVS_gpiov2_sel_shift                                          (8)
#define PVS_gpiov1_sel_shift                                          (4)
#define PVS_gpiov0_sel_shift                                          (0)
#define PVS_gpiov7_sel_mask                                           (0xF0000000)
#define PVS_gpiov6_sel_mask                                           (0x0F000000)
#define PVS_gpiov5_sel_mask                                           (0x00F00000)
#define PVS_gpiov4_sel_mask                                           (0x000F0000)
#define PVS_gpiov3_sel_mask                                           (0x0000F000)
#define PVS_gpiov2_sel_mask                                           (0x00000F00)
#define PVS_gpiov1_sel_mask                                           (0x000000F0)
#define PVS_gpiov0_sel_mask                                           (0x0000000F)
#define PVS_gpiov7_sel(data)                                          (0xF0000000&((data)<<28))
#define PVS_gpiov6_sel(data)                                          (0x0F000000&((data)<<24))
#define PVS_gpiov5_sel(data)                                          (0x00F00000&((data)<<20))
#define PVS_gpiov4_sel(data)                                          (0x000F0000&((data)<<16))
#define PVS_gpiov3_sel(data)                                          (0x0000F000&((data)<<12))
#define PVS_gpiov2_sel(data)                                          (0x00000F00&((data)<<8))
#define PVS_gpiov1_sel(data)                                          (0x000000F0&((data)<<4))
#define PVS_gpiov0_sel(data)                                          (0x0000000F&(data))
#define PVS_get_gpiov7_sel(data)                                      ((0xF0000000&(data))>>28)
#define PVS_get_gpiov6_sel(data)                                      ((0x0F000000&(data))>>24)
#define PVS_get_gpiov5_sel(data)                                      ((0x00F00000&(data))>>20)
#define PVS_get_gpiov4_sel(data)                                      ((0x000F0000&(data))>>16)
#define PVS_get_gpiov3_sel(data)                                      ((0x0000F000&(data))>>12)
#define PVS_get_gpiov2_sel(data)                                      ((0x00000F00&(data))>>8)
#define PVS_get_gpiov1_sel(data)                                      ((0x000000F0&(data))>>4)
#define PVS_get_gpiov0_sel(data)                                      (0x0000000F&(data))


#define PWM_DB_CTRL                                                   0x18012100
#define PWM_DB_CTRL_reg_addr                                          "0xb8012100"
#define PWM_DB_CTRL_reg                                               0xb8012100
#define PWM_DB_CTRL_inst_addr                                         "0x0040"
#define PWM_DB_CTRL_inst                                              0x0040
#define PWM_DB_CTRL_pwm_w_db_en_shift                                 (31)
#define PWM_DB_CTRL_pwm_db_rsel_shift                                 (30)
#define PWM_DB_CTRL_pwm_w_db_wr_shift                                 (29)
#define PWM_DB_CTRL_pwm_w_db_mode_shift                               (28)
#define PWM_DB_CTRL_pwm_w_db_en_mask                                  (0x80000000)
#define PWM_DB_CTRL_pwm_db_rsel_mask                                  (0x40000000)
#define PWM_DB_CTRL_pwm_w_db_wr_mask                                  (0x20000000)
#define PWM_DB_CTRL_pwm_w_db_mode_mask                                (0x10000000)
#define PWM_DB_CTRL_pwm_w_db_en(data)                                 (0x80000000&((data)<<31))
#define PWM_DB_CTRL_pwm_db_rsel(data)                                 (0x40000000&((data)<<30))
#define PWM_DB_CTRL_pwm_w_db_wr(data)                                 (0x20000000&((data)<<29))
#define PWM_DB_CTRL_pwm_w_db_mode(data)                               (0x10000000&((data)<<28))
#define PWM_DB_CTRL_get_pwm_w_db_en(data)                             ((0x80000000&(data))>>31)
#define PWM_DB_CTRL_get_pwm_db_rsel(data)                             ((0x40000000&(data))>>30)
#define PWM_DB_CTRL_get_pwm_w_db_wr(data)                             ((0x20000000&(data))>>29)
#define PWM_DB_CTRL_get_pwm_w_db_mode(data)                           ((0x10000000&(data))>>28)


#define PWM0_CTRL                                                     0x18012104
#define PWM0_CTRL_reg_addr                                            "0xb8012104"
#define PWM0_CTRL_reg                                                 0xb8012104
#define PWM0_CTRL_inst_addr                                           "0x0041"
#define PWM0_CTRL_inst                                                0x0041
#define PWM0_CTRL_pwm0l_shift                                         (31)
#define PWM0_CTRL_pwm0_ck_shift                                       (30)
#define PWM0_CTRL_pwm0_en_shift                                       (29)
#define PWM0_CTRL_pwm0_vs_rst_en_shift                                (28)
#define PWM0_CTRL_pwm0_dut_8b_shift                                   (27)
#define PWM0_CTRL_open_drain_mod_sel_shift                            (4)
#define PWM0_CTRL_pwm_width_sel_shift                                 (0)
#define PWM0_CTRL_pwm0l_mask                                          (0x80000000)
#define PWM0_CTRL_pwm0_ck_mask                                        (0x40000000)
#define PWM0_CTRL_pwm0_en_mask                                        (0x20000000)
#define PWM0_CTRL_pwm0_vs_rst_en_mask                                 (0x10000000)
#define PWM0_CTRL_pwm0_dut_8b_mask                                    (0x08000000)
#define PWM0_CTRL_open_drain_mod_sel_mask                             (0x00000010)
#define PWM0_CTRL_pwm_width_sel_mask                                  (0x00000001)
#define PWM0_CTRL_pwm0l(data)                                         (0x80000000&((data)<<31))
#define PWM0_CTRL_pwm0_ck(data)                                       (0x40000000&((data)<<30))
#define PWM0_CTRL_pwm0_en(data)                                       (0x20000000&((data)<<29))
#define PWM0_CTRL_pwm0_vs_rst_en(data)                                (0x10000000&((data)<<28))
#define PWM0_CTRL_pwm0_dut_8b(data)                                   (0x08000000&((data)<<27))
#define PWM0_CTRL_open_drain_mod_sel(data)                            (0x00000010&((data)<<4))
#define PWM0_CTRL_pwm_width_sel(data)                                 (0x00000001&(data))
#define PWM0_CTRL_get_pwm0l(data)                                     ((0x80000000&(data))>>31)
#define PWM0_CTRL_get_pwm0_ck(data)                                   ((0x40000000&(data))>>30)
#define PWM0_CTRL_get_pwm0_en(data)                                   ((0x20000000&(data))>>29)
#define PWM0_CTRL_get_pwm0_vs_rst_en(data)                            ((0x10000000&(data))>>28)
#define PWM0_CTRL_get_pwm0_dut_8b(data)                               ((0x08000000&(data))>>27)
#define PWM0_CTRL_get_open_drain_mod_sel(data)                        ((0x00000010&(data))>>4)
#define PWM0_CTRL_get_pwm_width_sel(data)                             (0x00000001&(data))


#define PWM0_TIMING_CTRL                                              0x18012108
#define PWM0_TIMING_CTRL_reg_addr                                     "0xb8012108"
#define PWM0_TIMING_CTRL_reg                                          0xb8012108
#define PWM0_TIMING_CTRL_inst_addr                                    "0x0042"
#define PWM0_TIMING_CTRL_inst                                         0x0042
#define PWM0_TIMING_CTRL_pwm0_cnt_mode_shift                          (31)
#define PWM0_TIMING_CTRL_pwm0_ck_sel_hs_shift                         (30)
#define PWM0_TIMING_CTRL_pwm0_ck_sel_shift                            (29)
#define PWM0_TIMING_CTRL_pwm0_cycle_max_shift                         (24)
#define PWM0_TIMING_CTRL_pwm0_m_shift                                 (12)
#define PWM0_TIMING_CTRL_pwm0_n_shift                                 (0)
#define PWM0_TIMING_CTRL_pwm0_cnt_mode_mask                           (0x80000000)
#define PWM0_TIMING_CTRL_pwm0_ck_sel_hs_mask                          (0x40000000)
#define PWM0_TIMING_CTRL_pwm0_ck_sel_mask                             (0x20000000)
#define PWM0_TIMING_CTRL_pwm0_cycle_max_mask                          (0x0F000000)
#define PWM0_TIMING_CTRL_pwm0_m_mask                                  (0x00003000)
#define PWM0_TIMING_CTRL_pwm0_n_mask                                  (0x00000FFF)
#define PWM0_TIMING_CTRL_pwm0_cnt_mode(data)                          (0x80000000&((data)<<31))
#define PWM0_TIMING_CTRL_pwm0_ck_sel_hs(data)                         (0x40000000&((data)<<30))
#define PWM0_TIMING_CTRL_pwm0_ck_sel(data)                            (0x20000000&((data)<<29))
#define PWM0_TIMING_CTRL_pwm0_cycle_max(data)                         (0x0F000000&((data)<<24))
#define PWM0_TIMING_CTRL_pwm0_m(data)                                 (0x00003000&((data)<<12))
#define PWM0_TIMING_CTRL_pwm0_n(data)                                 (0x00000FFF&(data))
#define PWM0_TIMING_CTRL_get_pwm0_cnt_mode(data)                      ((0x80000000&(data))>>31)
#define PWM0_TIMING_CTRL_get_pwm0_ck_sel_hs(data)                     ((0x40000000&(data))>>30)
#define PWM0_TIMING_CTRL_get_pwm0_ck_sel(data)                        ((0x20000000&(data))>>29)
#define PWM0_TIMING_CTRL_get_pwm0_cycle_max(data)                     ((0x0F000000&(data))>>24)
#define PWM0_TIMING_CTRL_get_pwm0_m(data)                             ((0x00003000&(data))>>12)
#define PWM0_TIMING_CTRL_get_pwm0_n(data)                             (0x00000FFF&(data))


#define PWM0_DUTY_SET                                                 0x1801210c
#define PWM0_DUTY_SET_reg_addr                                        "0xb801210c"
#define PWM0_DUTY_SET_reg                                             0xb801210c
#define PWM0_DUTY_SET_inst_addr                                       "0x0043"
#define PWM0_DUTY_SET_inst                                            0x0043
#define PWM0_DUTY_SET_pwm0_dut_shift                                  (16)
#define PWM0_DUTY_SET_pwm0_totalcnt_shift                             (0)
#define PWM0_DUTY_SET_pwm0_dut_mask                                   (0x0FFF0000)
#define PWM0_DUTY_SET_pwm0_totalcnt_mask                              (0x00000FFF)
#define PWM0_DUTY_SET_pwm0_dut(data)                                  (0x0FFF0000&((data)<<16))
#define PWM0_DUTY_SET_pwm0_totalcnt(data)                             (0x00000FFF&(data))
#define PWM0_DUTY_SET_get_pwm0_dut(data)                              ((0x0FFF0000&(data))>>16)
#define PWM0_DUTY_SET_get_pwm0_totalcnt(data)                         (0x00000FFF&(data))


#define PWM1_CTRL                                                     0x18012110
#define PWM1_CTRL_reg_addr                                            "0xb8012110"
#define PWM1_CTRL_reg                                                 0xb8012110
#define PWM1_CTRL_inst_addr                                           "0x0044"
#define PWM1_CTRL_inst                                                0x0044
#define PWM1_CTRL_pwm1l_shift                                         (31)
#define PWM1_CTRL_pwm1_ck_shift                                       (30)
#define PWM1_CTRL_pwm1_en_shift                                       (29)
#define PWM1_CTRL_pwm1_vs_rst_en_shift                                (28)
#define PWM1_CTRL_pwm1_dut_8b_shift                                   (27)
#define PWM1_CTRL_open_drain_mod_sel_shift                            (4)
#define PWM1_CTRL_pwm1l_mask                                          (0x80000000)
#define PWM1_CTRL_pwm1_ck_mask                                        (0x40000000)
#define PWM1_CTRL_pwm1_en_mask                                        (0x20000000)
#define PWM1_CTRL_pwm1_vs_rst_en_mask                                 (0x10000000)
#define PWM1_CTRL_pwm1_dut_8b_mask                                    (0x08000000)
#define PWM1_CTRL_open_drain_mod_sel_mask                             (0x00000010)
#define PWM1_CTRL_pwm1l(data)                                         (0x80000000&((data)<<31))
#define PWM1_CTRL_pwm1_ck(data)                                       (0x40000000&((data)<<30))
#define PWM1_CTRL_pwm1_en(data)                                       (0x20000000&((data)<<29))
#define PWM1_CTRL_pwm1_vs_rst_en(data)                                (0x10000000&((data)<<28))
#define PWM1_CTRL_pwm1_dut_8b(data)                                   (0x08000000&((data)<<27))
#define PWM1_CTRL_open_drain_mod_sel(data)                            (0x00000010&((data)<<4))
#define PWM1_CTRL_get_pwm1l(data)                                     ((0x80000000&(data))>>31)
#define PWM1_CTRL_get_pwm1_ck(data)                                   ((0x40000000&(data))>>30)
#define PWM1_CTRL_get_pwm1_en(data)                                   ((0x20000000&(data))>>29)
#define PWM1_CTRL_get_pwm1_vs_rst_en(data)                            ((0x10000000&(data))>>28)
#define PWM1_CTRL_get_pwm1_dut_8b(data)                               ((0x08000000&(data))>>27)
#define PWM1_CTRL_get_open_drain_mod_sel(data)                        ((0x00000010&(data))>>4)


#define PWM1_TIMING_CTRL                                              0x18012114
#define PWM1_TIMING_CTRL_reg_addr                                     "0xb8012114"
#define PWM1_TIMING_CTRL_reg                                          0xb8012114
#define PWM1_TIMING_CTRL_inst_addr                                    "0x0045"
#define PWM1_TIMING_CTRL_inst                                         0x0045
#define PWM1_TIMING_CTRL_pwm1_cnt_mode_shift                          (31)
#define PWM1_TIMING_CTRL_pwm1_ck_sel_hs_shift                         (30)
#define PWM1_TIMING_CTRL_pwm1_ck_sel_shift                            (29)
#define PWM1_TIMING_CTRL_pwm1_cycle_max_shift                         (24)
#define PWM1_TIMING_CTRL_pwm1_m_shift                                 (12)
#define PWM1_TIMING_CTRL_pwm1_n_shift                                 (0)
#define PWM1_TIMING_CTRL_pwm1_cnt_mode_mask                           (0x80000000)
#define PWM1_TIMING_CTRL_pwm1_ck_sel_hs_mask                          (0x40000000)
#define PWM1_TIMING_CTRL_pwm1_ck_sel_mask                             (0x20000000)
#define PWM1_TIMING_CTRL_pwm1_cycle_max_mask                          (0x0F000000)
#define PWM1_TIMING_CTRL_pwm1_m_mask                                  (0x00003000)
#define PWM1_TIMING_CTRL_pwm1_n_mask                                  (0x00000FFF)
#define PWM1_TIMING_CTRL_pwm1_cnt_mode(data)                          (0x80000000&((data)<<31))
#define PWM1_TIMING_CTRL_pwm1_ck_sel_hs(data)                         (0x40000000&((data)<<30))
#define PWM1_TIMING_CTRL_pwm1_ck_sel(data)                            (0x20000000&((data)<<29))
#define PWM1_TIMING_CTRL_pwm1_cycle_max(data)                         (0x0F000000&((data)<<24))
#define PWM1_TIMING_CTRL_pwm1_m(data)                                 (0x00003000&((data)<<12))
#define PWM1_TIMING_CTRL_pwm1_n(data)                                 (0x00000FFF&(data))
#define PWM1_TIMING_CTRL_get_pwm1_cnt_mode(data)                      ((0x80000000&(data))>>31)
#define PWM1_TIMING_CTRL_get_pwm1_ck_sel_hs(data)                     ((0x40000000&(data))>>30)
#define PWM1_TIMING_CTRL_get_pwm1_ck_sel(data)                        ((0x20000000&(data))>>29)
#define PWM1_TIMING_CTRL_get_pwm1_cycle_max(data)                     ((0x0F000000&(data))>>24)
#define PWM1_TIMING_CTRL_get_pwm1_m(data)                             ((0x00003000&(data))>>12)
#define PWM1_TIMING_CTRL_get_pwm1_n(data)                             (0x00000FFF&(data))


#define PWM1_DUTY_SET                                                 0x18012118
#define PWM1_DUTY_SET_reg_addr                                        "0xb8012118"
#define PWM1_DUTY_SET_reg                                             0xb8012118
#define PWM1_DUTY_SET_inst_addr                                       "0x0046"
#define PWM1_DUTY_SET_inst                                            0x0046
#define PWM1_DUTY_SET_pwm1_dut_shift                                  (16)
#define PWM1_DUTY_SET_pwm1_totalcnt_shift                             (0)
#define PWM1_DUTY_SET_pwm1_dut_mask                                   (0x0FFF0000)
#define PWM1_DUTY_SET_pwm1_totalcnt_mask                              (0x00000FFF)
#define PWM1_DUTY_SET_pwm1_dut(data)                                  (0x0FFF0000&((data)<<16))
#define PWM1_DUTY_SET_pwm1_totalcnt(data)                             (0x00000FFF&(data))
#define PWM1_DUTY_SET_get_pwm1_dut(data)                              ((0x0FFF0000&(data))>>16)
#define PWM1_DUTY_SET_get_pwm1_totalcnt(data)                         (0x00000FFF&(data))


#define PWM2_CTRL                                                     0x1801211c
#define PWM2_CTRL_reg_addr                                            "0xb801211c"
#define PWM2_CTRL_reg                                                 0xb801211c
#define PWM2_CTRL_inst_addr                                           "0x0047"
#define PWM2_CTRL_inst                                                0x0047
#define PWM2_CTRL_pwm2l_shift                                         (31)
#define PWM2_CTRL_pwm2_ck_shift                                       (30)
#define PWM2_CTRL_pwm2_en_shift                                       (29)
#define PWM2_CTRL_pwm2_vs_rst_en_shift                                (28)
#define PWM2_CTRL_pwm2_dut_8b_shift                                   (27)
#define PWM2_CTRL_open_drain_mod_sel_shift                            (4)
#define PWM2_CTRL_pwm2l_mask                                          (0x80000000)
#define PWM2_CTRL_pwm2_ck_mask                                        (0x40000000)
#define PWM2_CTRL_pwm2_en_mask                                        (0x20000000)
#define PWM2_CTRL_pwm2_vs_rst_en_mask                                 (0x10000000)
#define PWM2_CTRL_pwm2_dut_8b_mask                                    (0x08000000)
#define PWM2_CTRL_open_drain_mod_sel_mask                             (0x00000010)
#define PWM2_CTRL_pwm2l(data)                                         (0x80000000&((data)<<31))
#define PWM2_CTRL_pwm2_ck(data)                                       (0x40000000&((data)<<30))
#define PWM2_CTRL_pwm2_en(data)                                       (0x20000000&((data)<<29))
#define PWM2_CTRL_pwm2_vs_rst_en(data)                                (0x10000000&((data)<<28))
#define PWM2_CTRL_pwm2_dut_8b(data)                                   (0x08000000&((data)<<27))
#define PWM2_CTRL_open_drain_mod_sel(data)                            (0x00000010&((data)<<4))
#define PWM2_CTRL_get_pwm2l(data)                                     ((0x80000000&(data))>>31)
#define PWM2_CTRL_get_pwm2_ck(data)                                   ((0x40000000&(data))>>30)
#define PWM2_CTRL_get_pwm2_en(data)                                   ((0x20000000&(data))>>29)
#define PWM2_CTRL_get_pwm2_vs_rst_en(data)                            ((0x10000000&(data))>>28)
#define PWM2_CTRL_get_pwm2_dut_8b(data)                               ((0x08000000&(data))>>27)
#define PWM2_CTRL_get_open_drain_mod_sel(data)                        ((0x00000010&(data))>>4)


#define PWM2_TIMING_CTRL                                              0x18012120
#define PWM2_TIMING_CTRL_reg_addr                                     "0xb8012120"
#define PWM2_TIMING_CTRL_reg                                          0xb8012120
#define PWM2_TIMING_CTRL_inst_addr                                    "0x0048"
#define PWM2_TIMING_CTRL_inst                                         0x0048
#define PWM2_TIMING_CTRL_pwm2_cnt_mode_shift                          (31)
#define PWM2_TIMING_CTRL_pwm2_ck_sel_hs_shift                         (30)
#define PWM2_TIMING_CTRL_pwm2_ck_sel_shift                            (29)
#define PWM2_TIMING_CTRL_pwm2_cycle_max_shift                         (24)
#define PWM2_TIMING_CTRL_pwm2_m_shift                                 (12)
#define PWM2_TIMING_CTRL_pwm2_n_shift                                 (0)
#define PWM2_TIMING_CTRL_pwm2_cnt_mode_mask                           (0x80000000)
#define PWM2_TIMING_CTRL_pwm2_ck_sel_hs_mask                          (0x40000000)
#define PWM2_TIMING_CTRL_pwm2_ck_sel_mask                             (0x20000000)
#define PWM2_TIMING_CTRL_pwm2_cycle_max_mask                          (0x0F000000)
#define PWM2_TIMING_CTRL_pwm2_m_mask                                  (0x00003000)
#define PWM2_TIMING_CTRL_pwm2_n_mask                                  (0x00000FFF)
#define PWM2_TIMING_CTRL_pwm2_cnt_mode(data)                          (0x80000000&((data)<<31))
#define PWM2_TIMING_CTRL_pwm2_ck_sel_hs(data)                         (0x40000000&((data)<<30))
#define PWM2_TIMING_CTRL_pwm2_ck_sel(data)                            (0x20000000&((data)<<29))
#define PWM2_TIMING_CTRL_pwm2_cycle_max(data)                         (0x0F000000&((data)<<24))
#define PWM2_TIMING_CTRL_pwm2_m(data)                                 (0x00003000&((data)<<12))
#define PWM2_TIMING_CTRL_pwm2_n(data)                                 (0x00000FFF&(data))
#define PWM2_TIMING_CTRL_get_pwm2_cnt_mode(data)                      ((0x80000000&(data))>>31)
#define PWM2_TIMING_CTRL_get_pwm2_ck_sel_hs(data)                     ((0x40000000&(data))>>30)
#define PWM2_TIMING_CTRL_get_pwm2_ck_sel(data)                        ((0x20000000&(data))>>29)
#define PWM2_TIMING_CTRL_get_pwm2_cycle_max(data)                     ((0x0F000000&(data))>>24)
#define PWM2_TIMING_CTRL_get_pwm2_m(data)                             ((0x00003000&(data))>>12)
#define PWM2_TIMING_CTRL_get_pwm2_n(data)                             (0x00000FFF&(data))


#define PWM2_DUTY_SET                                                 0x18012124
#define PWM2_DUTY_SET_reg_addr                                        "0xb8012124"
#define PWM2_DUTY_SET_reg                                             0xb8012124
#define PWM2_DUTY_SET_inst_addr                                       "0x0049"
#define PWM2_DUTY_SET_inst                                            0x0049
#define PWM2_DUTY_SET_pwm2_dut_shift                                  (16)
#define PWM2_DUTY_SET_pwm2_totalcnt_shift                             (0)
#define PWM2_DUTY_SET_pwm2_dut_mask                                   (0x0FFF0000)
#define PWM2_DUTY_SET_pwm2_totalcnt_mask                              (0x00000FFF)
#define PWM2_DUTY_SET_pwm2_dut(data)                                  (0x0FFF0000&((data)<<16))
#define PWM2_DUTY_SET_pwm2_totalcnt(data)                             (0x00000FFF&(data))
#define PWM2_DUTY_SET_get_pwm2_dut(data)                              ((0x0FFF0000&(data))>>16)
#define PWM2_DUTY_SET_get_pwm2_totalcnt(data)                         (0x00000FFF&(data))


#define PWM3_CTRL                                                     0x18012128
#define PWM3_CTRL_reg_addr                                            "0xb8012128"
#define PWM3_CTRL_reg                                                 0xb8012128
#define PWM3_CTRL_inst_addr                                           "0x004A"
#define PWM3_CTRL_inst                                                0x004A
#define PWM3_CTRL_pwm3l_shift                                         (31)
#define PWM3_CTRL_pwm3_ck_shift                                       (30)
#define PWM3_CTRL_pwm3_en_shift                                       (29)
#define PWM3_CTRL_pwm3_vs_rst_en_shift                                (28)
#define PWM3_CTRL_pwm3_dut_8b_shift                                   (27)
#define PWM3_CTRL_open_drain_mod_sel_shift                            (4)
#define PWM3_CTRL_pwm3l_mask                                          (0x80000000)
#define PWM3_CTRL_pwm3_ck_mask                                        (0x40000000)
#define PWM3_CTRL_pwm3_en_mask                                        (0x20000000)
#define PWM3_CTRL_pwm3_vs_rst_en_mask                                 (0x10000000)
#define PWM3_CTRL_pwm3_dut_8b_mask                                    (0x08000000)
#define PWM3_CTRL_open_drain_mod_sel_mask                             (0x00000010)
#define PWM3_CTRL_pwm3l(data)                                         (0x80000000&((data)<<31))
#define PWM3_CTRL_pwm3_ck(data)                                       (0x40000000&((data)<<30))
#define PWM3_CTRL_pwm3_en(data)                                       (0x20000000&((data)<<29))
#define PWM3_CTRL_pwm3_vs_rst_en(data)                                (0x10000000&((data)<<28))
#define PWM3_CTRL_pwm3_dut_8b(data)                                   (0x08000000&((data)<<27))
#define PWM3_CTRL_open_drain_mod_sel(data)                            (0x00000010&((data)<<4))
#define PWM3_CTRL_get_pwm3l(data)                                     ((0x80000000&(data))>>31)
#define PWM3_CTRL_get_pwm3_ck(data)                                   ((0x40000000&(data))>>30)
#define PWM3_CTRL_get_pwm3_en(data)                                   ((0x20000000&(data))>>29)
#define PWM3_CTRL_get_pwm3_vs_rst_en(data)                            ((0x10000000&(data))>>28)
#define PWM3_CTRL_get_pwm3_dut_8b(data)                               ((0x08000000&(data))>>27)
#define PWM3_CTRL_get_open_drain_mod_sel(data)                        ((0x00000010&(data))>>4)


#define PWM3_TIMING_CTRL                                              0x1801212c
#define PWM3_TIMING_CTRL_reg_addr                                     "0xb801212c"
#define PWM3_TIMING_CTRL_reg                                          0xb801212c
#define PWM3_TIMING_CTRL_inst_addr                                    "0x004B"
#define PWM3_TIMING_CTRL_inst                                         0x004B
#define PWM3_TIMING_CTRL_pwm3_cnt_mode_shift                          (31)
#define PWM3_TIMING_CTRL_pwm3_ck_sel_hs_shift                         (30)
#define PWM3_TIMING_CTRL_pwm3_ck_sel_shift                            (29)
#define PWM3_TIMING_CTRL_pwm3_cycle_max_shift                         (24)
#define PWM3_TIMING_CTRL_pwm3_m_shift                                 (12)
#define PWM3_TIMING_CTRL_pwm3_n_shift                                 (0)
#define PWM3_TIMING_CTRL_pwm3_cnt_mode_mask                           (0x80000000)
#define PWM3_TIMING_CTRL_pwm3_ck_sel_hs_mask                          (0x40000000)
#define PWM3_TIMING_CTRL_pwm3_ck_sel_mask                             (0x20000000)
#define PWM3_TIMING_CTRL_pwm3_cycle_max_mask                          (0x0F000000)
#define PWM3_TIMING_CTRL_pwm3_m_mask                                  (0x00003000)
#define PWM3_TIMING_CTRL_pwm3_n_mask                                  (0x00000FFF)
#define PWM3_TIMING_CTRL_pwm3_cnt_mode(data)                          (0x80000000&((data)<<31))
#define PWM3_TIMING_CTRL_pwm3_ck_sel_hs(data)                         (0x40000000&((data)<<30))
#define PWM3_TIMING_CTRL_pwm3_ck_sel(data)                            (0x20000000&((data)<<29))
#define PWM3_TIMING_CTRL_pwm3_cycle_max(data)                         (0x0F000000&((data)<<24))
#define PWM3_TIMING_CTRL_pwm3_m(data)                                 (0x00003000&((data)<<12))
#define PWM3_TIMING_CTRL_pwm3_n(data)                                 (0x00000FFF&(data))
#define PWM3_TIMING_CTRL_get_pwm3_cnt_mode(data)                      ((0x80000000&(data))>>31)
#define PWM3_TIMING_CTRL_get_pwm3_ck_sel_hs(data)                     ((0x40000000&(data))>>30)
#define PWM3_TIMING_CTRL_get_pwm3_ck_sel(data)                        ((0x20000000&(data))>>29)
#define PWM3_TIMING_CTRL_get_pwm3_cycle_max(data)                     ((0x0F000000&(data))>>24)
#define PWM3_TIMING_CTRL_get_pwm3_m(data)                             ((0x00003000&(data))>>12)
#define PWM3_TIMING_CTRL_get_pwm3_n(data)                             (0x00000FFF&(data))


#define PWM3_DUTY_SET                                                 0x18012130
#define PWM3_DUTY_SET_reg_addr                                        "0xb8012130"
#define PWM3_DUTY_SET_reg                                             0xb8012130
#define PWM3_DUTY_SET_inst_addr                                       "0x004C"
#define PWM3_DUTY_SET_inst                                            0x004C
#define PWM3_DUTY_SET_pwm3_dut_shift                                  (16)
#define PWM3_DUTY_SET_pwm3_totalcnt_shift                             (0)
#define PWM3_DUTY_SET_pwm3_dut_mask                                   (0x0FFF0000)
#define PWM3_DUTY_SET_pwm3_totalcnt_mask                              (0x00000FFF)
#define PWM3_DUTY_SET_pwm3_dut(data)                                  (0x0FFF0000&((data)<<16))
#define PWM3_DUTY_SET_pwm3_totalcnt(data)                             (0x00000FFF&(data))
#define PWM3_DUTY_SET_get_pwm3_dut(data)                              ((0x0FFF0000&(data))>>16)
#define PWM3_DUTY_SET_get_pwm3_totalcnt(data)                         (0x00000FFF&(data))


#define PWM4_CTRL                                                     0x18012134
#define PWM4_CTRL_reg_addr                                            "0xb8012134"
#define PWM4_CTRL_reg                                                 0xb8012134
#define PWM4_CTRL_inst_addr                                           "0x004D"
#define PWM4_CTRL_inst                                                0x004D
#define PWM4_CTRL_pwm4l_shift                                         (31)
#define PWM4_CTRL_pwm4_ck_shift                                       (30)
#define PWM4_CTRL_pwm4_en_shift                                       (29)
#define PWM4_CTRL_pwm4_vs_rst_en_shift                                (28)
#define PWM4_CTRL_pwm4_dut_8b_shift                                   (27)
#define PWM4_CTRL_open_drain_mod_sel_shift                            (4)
#define PWM4_CTRL_pwm4l_mask                                          (0x80000000)
#define PWM4_CTRL_pwm4_ck_mask                                        (0x40000000)
#define PWM4_CTRL_pwm4_en_mask                                        (0x20000000)
#define PWM4_CTRL_pwm4_vs_rst_en_mask                                 (0x10000000)
#define PWM4_CTRL_pwm4_dut_8b_mask                                    (0x08000000)
#define PWM4_CTRL_open_drain_mod_sel_mask                             (0x00000010)
#define PWM4_CTRL_pwm4l(data)                                         (0x80000000&((data)<<31))
#define PWM4_CTRL_pwm4_ck(data)                                       (0x40000000&((data)<<30))
#define PWM4_CTRL_pwm4_en(data)                                       (0x20000000&((data)<<29))
#define PWM4_CTRL_pwm4_vs_rst_en(data)                                (0x10000000&((data)<<28))
#define PWM4_CTRL_pwm4_dut_8b(data)                                   (0x08000000&((data)<<27))
#define PWM4_CTRL_open_drain_mod_sel(data)                            (0x00000010&((data)<<4))
#define PWM4_CTRL_get_pwm4l(data)                                     ((0x80000000&(data))>>31)
#define PWM4_CTRL_get_pwm4_ck(data)                                   ((0x40000000&(data))>>30)
#define PWM4_CTRL_get_pwm4_en(data)                                   ((0x20000000&(data))>>29)
#define PWM4_CTRL_get_pwm4_vs_rst_en(data)                            ((0x10000000&(data))>>28)
#define PWM4_CTRL_get_pwm4_dut_8b(data)                               ((0x08000000&(data))>>27)
#define PWM4_CTRL_get_open_drain_mod_sel(data)                        ((0x00000010&(data))>>4)


#define PWM4_TIMING_CTRL                                              0x18012138
#define PWM4_TIMING_CTRL_reg_addr                                     "0xb8012138"
#define PWM4_TIMING_CTRL_reg                                          0xb8012138
#define PWM4_TIMING_CTRL_inst_addr                                    "0x004E"
#define PWM4_TIMING_CTRL_inst                                         0x004E
#define PWM4_TIMING_CTRL_pwm4_cnt_mode_shift                          (31)
#define PWM4_TIMING_CTRL_pwm4_ck_sel_hs_shift                         (30)
#define PWM4_TIMING_CTRL_pwm4_ck_sel_shift                            (29)
#define PWM4_TIMING_CTRL_pwm4_cycle_max_shift                         (24)
#define PWM4_TIMING_CTRL_pwm4_m_shift                                 (12)
#define PWM4_TIMING_CTRL_pwm4_n_shift                                 (0)
#define PWM4_TIMING_CTRL_pwm4_cnt_mode_mask                           (0x80000000)
#define PWM4_TIMING_CTRL_pwm4_ck_sel_hs_mask                          (0x40000000)
#define PWM4_TIMING_CTRL_pwm4_ck_sel_mask                             (0x20000000)
#define PWM4_TIMING_CTRL_pwm4_cycle_max_mask                          (0x0F000000)
#define PWM4_TIMING_CTRL_pwm4_m_mask                                  (0x00003000)
#define PWM4_TIMING_CTRL_pwm4_n_mask                                  (0x00000FFF)
#define PWM4_TIMING_CTRL_pwm4_cnt_mode(data)                          (0x80000000&((data)<<31))
#define PWM4_TIMING_CTRL_pwm4_ck_sel_hs(data)                         (0x40000000&((data)<<30))
#define PWM4_TIMING_CTRL_pwm4_ck_sel(data)                            (0x20000000&((data)<<29))
#define PWM4_TIMING_CTRL_pwm4_cycle_max(data)                         (0x0F000000&((data)<<24))
#define PWM4_TIMING_CTRL_pwm4_m(data)                                 (0x00003000&((data)<<12))
#define PWM4_TIMING_CTRL_pwm4_n(data)                                 (0x00000FFF&(data))
#define PWM4_TIMING_CTRL_get_pwm4_cnt_mode(data)                      ((0x80000000&(data))>>31)
#define PWM4_TIMING_CTRL_get_pwm4_ck_sel_hs(data)                     ((0x40000000&(data))>>30)
#define PWM4_TIMING_CTRL_get_pwm4_ck_sel(data)                        ((0x20000000&(data))>>29)
#define PWM4_TIMING_CTRL_get_pwm4_cycle_max(data)                     ((0x0F000000&(data))>>24)
#define PWM4_TIMING_CTRL_get_pwm4_m(data)                             ((0x00003000&(data))>>12)
#define PWM4_TIMING_CTRL_get_pwm4_n(data)                             (0x00000FFF&(data))


#define PWM4_DUTY_SET                                                 0x1801213c
#define PWM4_DUTY_SET_reg_addr                                        "0xb801213c"
#define PWM4_DUTY_SET_reg                                             0xb801213c
#define PWM4_DUTY_SET_inst_addr                                       "0x004F"
#define PWM4_DUTY_SET_inst                                            0x004F
#define PWM4_DUTY_SET_pwm4_dut_shift                                  (16)
#define PWM4_DUTY_SET_pwm4_totalcnt_shift                             (0)
#define PWM4_DUTY_SET_pwm4_dut_mask                                   (0x0FFF0000)
#define PWM4_DUTY_SET_pwm4_totalcnt_mask                              (0x00000FFF)
#define PWM4_DUTY_SET_pwm4_dut(data)                                  (0x0FFF0000&((data)<<16))
#define PWM4_DUTY_SET_pwm4_totalcnt(data)                             (0x00000FFF&(data))
#define PWM4_DUTY_SET_get_pwm4_dut(data)                              ((0x0FFF0000&(data))>>16)
#define PWM4_DUTY_SET_get_pwm4_totalcnt(data)                         (0x00000FFF&(data))


#define PWM5_CTRL                                                     0x18012140
#define PWM5_CTRL_reg_addr                                            "0xb8012140"
#define PWM5_CTRL_reg                                                 0xb8012140
#define PWM5_CTRL_inst_addr                                           "0x0050"
#define PWM5_CTRL_inst                                                0x0050
#define PWM5_CTRL_pwm5l_shift                                         (31)
#define PWM5_CTRL_pwm5_ck_shift                                       (30)
#define PWM5_CTRL_pwm5_en_shift                                       (29)
#define PWM5_CTRL_pwm5_vs_rst_en_shift                                (28)
#define PWM5_CTRL_pwm5_dut_8b_shift                                   (27)
#define PWM5_CTRL_open_drain_mod_sel_shift                            (4)
#define PWM5_CTRL_pwm5l_mask                                          (0x80000000)
#define PWM5_CTRL_pwm5_ck_mask                                        (0x40000000)
#define PWM5_CTRL_pwm5_en_mask                                        (0x20000000)
#define PWM5_CTRL_pwm5_vs_rst_en_mask                                 (0x10000000)
#define PWM5_CTRL_pwm5_dut_8b_mask                                    (0x08000000)
#define PWM5_CTRL_open_drain_mod_sel_mask                             (0x00000010)
#define PWM5_CTRL_pwm5l(data)                                         (0x80000000&((data)<<31))
#define PWM5_CTRL_pwm5_ck(data)                                       (0x40000000&((data)<<30))
#define PWM5_CTRL_pwm5_en(data)                                       (0x20000000&((data)<<29))
#define PWM5_CTRL_pwm5_vs_rst_en(data)                                (0x10000000&((data)<<28))
#define PWM5_CTRL_pwm5_dut_8b(data)                                   (0x08000000&((data)<<27))
#define PWM5_CTRL_open_drain_mod_sel(data)                            (0x00000010&((data)<<4))
#define PWM5_CTRL_get_pwm5l(data)                                     ((0x80000000&(data))>>31)
#define PWM5_CTRL_get_pwm5_ck(data)                                   ((0x40000000&(data))>>30)
#define PWM5_CTRL_get_pwm5_en(data)                                   ((0x20000000&(data))>>29)
#define PWM5_CTRL_get_pwm5_vs_rst_en(data)                            ((0x10000000&(data))>>28)
#define PWM5_CTRL_get_pwm5_dut_8b(data)                               ((0x08000000&(data))>>27)
#define PWM5_CTRL_get_open_drain_mod_sel(data)                        ((0x00000010&(data))>>4)


#define PWM5_TIMING_CTRL                                              0x18012144
#define PWM5_TIMING_CTRL_reg_addr                                     "0xb8012144"
#define PWM5_TIMING_CTRL_reg                                          0xb8012144
#define PWM5_TIMING_CTRL_inst_addr                                    "0x0051"
#define PWM5_TIMING_CTRL_inst                                         0x0051
#define PWM5_TIMING_CTRL_pwm5_cnt_mode_shift                          (31)
#define PWM5_TIMING_CTRL_pwm5_ck_sel_hs_shift                         (30)
#define PWM5_TIMING_CTRL_pwm5_ck_sel_shift                            (29)
#define PWM5_TIMING_CTRL_pwm5_cycle_max_shift                         (24)
#define PWM5_TIMING_CTRL_pwm5_m_shift                                 (12)
#define PWM5_TIMING_CTRL_pwm5_n_shift                                 (0)
#define PWM5_TIMING_CTRL_pwm5_cnt_mode_mask                           (0x80000000)
#define PWM5_TIMING_CTRL_pwm5_ck_sel_hs_mask                          (0x40000000)
#define PWM5_TIMING_CTRL_pwm5_ck_sel_mask                             (0x20000000)
#define PWM5_TIMING_CTRL_pwm5_cycle_max_mask                          (0x0F000000)
#define PWM5_TIMING_CTRL_pwm5_m_mask                                  (0x00003000)
#define PWM5_TIMING_CTRL_pwm5_n_mask                                  (0x00000FFF)
#define PWM5_TIMING_CTRL_pwm5_cnt_mode(data)                          (0x80000000&((data)<<31))
#define PWM5_TIMING_CTRL_pwm5_ck_sel_hs(data)                         (0x40000000&((data)<<30))
#define PWM5_TIMING_CTRL_pwm5_ck_sel(data)                            (0x20000000&((data)<<29))
#define PWM5_TIMING_CTRL_pwm5_cycle_max(data)                         (0x0F000000&((data)<<24))
#define PWM5_TIMING_CTRL_pwm5_m(data)                                 (0x00003000&((data)<<12))
#define PWM5_TIMING_CTRL_pwm5_n(data)                                 (0x00000FFF&(data))
#define PWM5_TIMING_CTRL_get_pwm5_cnt_mode(data)                      ((0x80000000&(data))>>31)
#define PWM5_TIMING_CTRL_get_pwm5_ck_sel_hs(data)                     ((0x40000000&(data))>>30)
#define PWM5_TIMING_CTRL_get_pwm5_ck_sel(data)                        ((0x20000000&(data))>>29)
#define PWM5_TIMING_CTRL_get_pwm5_cycle_max(data)                     ((0x0F000000&(data))>>24)
#define PWM5_TIMING_CTRL_get_pwm5_m(data)                             ((0x00003000&(data))>>12)
#define PWM5_TIMING_CTRL_get_pwm5_n(data)                             (0x00000FFF&(data))


#define PWM5_DUTY_SET                                                 0x18012148
#define PWM5_DUTY_SET_reg_addr                                        "0xb8012148"
#define PWM5_DUTY_SET_reg                                             0xb8012148
#define PWM5_DUTY_SET_inst_addr                                       "0x0052"
#define PWM5_DUTY_SET_inst                                            0x0052
#define PWM5_DUTY_SET_pwm5_dut_shift                                  (16)
#define PWM5_DUTY_SET_pwm5_totalcnt_shift                             (0)
#define PWM5_DUTY_SET_pwm5_dut_mask                                   (0x0FFF0000)
#define PWM5_DUTY_SET_pwm5_totalcnt_mask                              (0x00000FFF)
#define PWM5_DUTY_SET_pwm5_dut(data)                                  (0x0FFF0000&((data)<<16))
#define PWM5_DUTY_SET_pwm5_totalcnt(data)                             (0x00000FFF&(data))
#define PWM5_DUTY_SET_get_pwm5_dut(data)                              ((0x0FFF0000&(data))>>16)
#define PWM5_DUTY_SET_get_pwm5_totalcnt(data)                         (0x00000FFF&(data))


#define PWM6_CTRL                                                     0x1801214c
#define PWM6_CTRL_reg_addr                                            "0xb801214c"
#define PWM6_CTRL_reg                                                 0xb801214c
#define PWM6_CTRL_inst_addr                                           "0x0053"
#define PWM6_CTRL_inst                                                0x0053
#define PWM6_CTRL_pwm6l_shift                                         (31)
#define PWM6_CTRL_pwm6_ck_shift                                       (30)
#define PWM6_CTRL_pwm6_en_shift                                       (29)
#define PWM6_CTRL_pwm6_vs_rst_en_shift                                (28)
#define PWM6_CTRL_pwm6_dut_8b_shift                                   (27)
#define PWM6_CTRL_open_drain_mod_sel_shift                            (4)
#define PWM6_CTRL_pwm6l_mask                                          (0x80000000)
#define PWM6_CTRL_pwm6_ck_mask                                        (0x40000000)
#define PWM6_CTRL_pwm6_en_mask                                        (0x20000000)
#define PWM6_CTRL_pwm6_vs_rst_en_mask                                 (0x10000000)
#define PWM6_CTRL_pwm6_dut_8b_mask                                    (0x08000000)
#define PWM6_CTRL_open_drain_mod_sel_mask                             (0x00000010)
#define PWM6_CTRL_pwm6l(data)                                         (0x80000000&((data)<<31))
#define PWM6_CTRL_pwm6_ck(data)                                       (0x40000000&((data)<<30))
#define PWM6_CTRL_pwm6_en(data)                                       (0x20000000&((data)<<29))
#define PWM6_CTRL_pwm6_vs_rst_en(data)                                (0x10000000&((data)<<28))
#define PWM6_CTRL_pwm6_dut_8b(data)                                   (0x08000000&((data)<<27))
#define PWM6_CTRL_open_drain_mod_sel(data)                            (0x00000010&((data)<<4))
#define PWM6_CTRL_get_pwm6l(data)                                     ((0x80000000&(data))>>31)
#define PWM6_CTRL_get_pwm6_ck(data)                                   ((0x40000000&(data))>>30)
#define PWM6_CTRL_get_pwm6_en(data)                                   ((0x20000000&(data))>>29)
#define PWM6_CTRL_get_pwm6_vs_rst_en(data)                            ((0x10000000&(data))>>28)
#define PWM6_CTRL_get_pwm6_dut_8b(data)                               ((0x08000000&(data))>>27)
#define PWM6_CTRL_get_open_drain_mod_sel(data)                        ((0x00000010&(data))>>4)


#define PWM6_TIMING_CTRL                                              0x18012150
#define PWM6_TIMING_CTRL_reg_addr                                     "0xb8012150"
#define PWM6_TIMING_CTRL_reg                                          0xb8012150
#define PWM6_TIMING_CTRL_inst_addr                                    "0x0054"
#define PWM6_TIMING_CTRL_inst                                         0x0054
#define PWM6_TIMING_CTRL_pwm6_cnt_mode_shift                          (31)
#define PWM6_TIMING_CTRL_pwm6_ck_sel_hs_shift                         (30)
#define PWM6_TIMING_CTRL_pwm6_ck_sel_shift                            (29)
#define PWM6_TIMING_CTRL_pwm6_cycle_max_shift                         (24)
#define PWM6_TIMING_CTRL_pwm6_m_shift                                 (12)
#define PWM6_TIMING_CTRL_pwm6_n_shift                                 (0)
#define PWM6_TIMING_CTRL_pwm6_cnt_mode_mask                           (0x80000000)
#define PWM6_TIMING_CTRL_pwm6_ck_sel_hs_mask                          (0x40000000)
#define PWM6_TIMING_CTRL_pwm6_ck_sel_mask                             (0x20000000)
#define PWM6_TIMING_CTRL_pwm6_cycle_max_mask                          (0x0F000000)
#define PWM6_TIMING_CTRL_pwm6_m_mask                                  (0x00003000)
#define PWM6_TIMING_CTRL_pwm6_n_mask                                  (0x00000FFF)
#define PWM6_TIMING_CTRL_pwm6_cnt_mode(data)                          (0x80000000&((data)<<31))
#define PWM6_TIMING_CTRL_pwm6_ck_sel_hs(data)                         (0x40000000&((data)<<30))
#define PWM6_TIMING_CTRL_pwm6_ck_sel(data)                            (0x20000000&((data)<<29))
#define PWM6_TIMING_CTRL_pwm6_cycle_max(data)                         (0x0F000000&((data)<<24))
#define PWM6_TIMING_CTRL_pwm6_m(data)                                 (0x00003000&((data)<<12))
#define PWM6_TIMING_CTRL_pwm6_n(data)                                 (0x00000FFF&(data))
#define PWM6_TIMING_CTRL_get_pwm6_cnt_mode(data)                      ((0x80000000&(data))>>31)
#define PWM6_TIMING_CTRL_get_pwm6_ck_sel_hs(data)                     ((0x40000000&(data))>>30)
#define PWM6_TIMING_CTRL_get_pwm6_ck_sel(data)                        ((0x20000000&(data))>>29)
#define PWM6_TIMING_CTRL_get_pwm6_cycle_max(data)                     ((0x0F000000&(data))>>24)
#define PWM6_TIMING_CTRL_get_pwm6_m(data)                             ((0x00003000&(data))>>12)
#define PWM6_TIMING_CTRL_get_pwm6_n(data)                             (0x00000FFF&(data))


#define PWM6_DUTY_SET                                                 0x18012154
#define PWM6_DUTY_SET_reg_addr                                        "0xb8012154"
#define PWM6_DUTY_SET_reg                                             0xb8012154
#define PWM6_DUTY_SET_inst_addr                                       "0x0055"
#define PWM6_DUTY_SET_inst                                            0x0055
#define PWM6_DUTY_SET_pwm6_dut_shift                                  (16)
#define PWM6_DUTY_SET_pwm6_totalcnt_shift                             (0)
#define PWM6_DUTY_SET_pwm6_dut_mask                                   (0x0FFF0000)
#define PWM6_DUTY_SET_pwm6_totalcnt_mask                              (0x00000FFF)
#define PWM6_DUTY_SET_pwm6_dut(data)                                  (0x0FFF0000&((data)<<16))
#define PWM6_DUTY_SET_pwm6_totalcnt(data)                             (0x00000FFF&(data))
#define PWM6_DUTY_SET_get_pwm6_dut(data)                              ((0x0FFF0000&(data))>>16)
#define PWM6_DUTY_SET_get_pwm6_totalcnt(data)                         (0x00000FFF&(data))


#define PWM7_CTRL                                                     0x18012158
#define PWM7_CTRL_reg_addr                                            "0xb8012158"
#define PWM7_CTRL_reg                                                 0xb8012158
#define PWM7_CTRL_inst_addr                                           "0x0056"
#define PWM7_CTRL_inst                                                0x0056
#define PWM7_CTRL_pwm7l_shift                                         (31)
#define PWM7_CTRL_pwm7_ck_shift                                       (30)
#define PWM7_CTRL_pwm7_en_shift                                       (29)
#define PWM7_CTRL_pwm7_vs_rst_en_shift                                (28)
#define PWM7_CTRL_pwm7_dut_8b_shift                                   (27)
#define PWM7_CTRL_open_drain_mod_sel_shift                            (4)
#define PWM7_CTRL_pwm7l_mask                                          (0x80000000)
#define PWM7_CTRL_pwm7_ck_mask                                        (0x40000000)
#define PWM7_CTRL_pwm7_en_mask                                        (0x20000000)
#define PWM7_CTRL_pwm7_vs_rst_en_mask                                 (0x10000000)
#define PWM7_CTRL_pwm7_dut_8b_mask                                    (0x08000000)
#define PWM7_CTRL_open_drain_mod_sel_mask                             (0x00000010)
#define PWM7_CTRL_pwm7l(data)                                         (0x80000000&((data)<<31))
#define PWM7_CTRL_pwm7_ck(data)                                       (0x40000000&((data)<<30))
#define PWM7_CTRL_pwm7_en(data)                                       (0x20000000&((data)<<29))
#define PWM7_CTRL_pwm7_vs_rst_en(data)                                (0x10000000&((data)<<28))
#define PWM7_CTRL_pwm7_dut_8b(data)                                   (0x08000000&((data)<<27))
#define PWM7_CTRL_open_drain_mod_sel(data)                            (0x00000010&((data)<<4))
#define PWM7_CTRL_get_pwm7l(data)                                     ((0x80000000&(data))>>31)
#define PWM7_CTRL_get_pwm7_ck(data)                                   ((0x40000000&(data))>>30)
#define PWM7_CTRL_get_pwm7_en(data)                                   ((0x20000000&(data))>>29)
#define PWM7_CTRL_get_pwm7_vs_rst_en(data)                            ((0x10000000&(data))>>28)
#define PWM7_CTRL_get_pwm7_dut_8b(data)                               ((0x08000000&(data))>>27)
#define PWM7_CTRL_get_open_drain_mod_sel(data)                        ((0x00000010&(data))>>4)


#define PWM7_TIMING_CTRL                                              0x1801215c
#define PWM7_TIMING_CTRL_reg_addr                                     "0xb801215c"
#define PWM7_TIMING_CTRL_reg                                          0xb801215c
#define PWM7_TIMING_CTRL_inst_addr                                    "0x0057"
#define PWM7_TIMING_CTRL_inst                                         0x0057
#define PWM7_TIMING_CTRL_pwm7_cnt_mode_shift                          (31)
#define PWM7_TIMING_CTRL_pwm7_ck_sel_hs_shift                         (30)
#define PWM7_TIMING_CTRL_pwm7_ck_sel_shift                            (29)
#define PWM7_TIMING_CTRL_pwm7_cycle_max_shift                         (24)
#define PWM7_TIMING_CTRL_pwm7_m_shift                                 (12)
#define PWM7_TIMING_CTRL_pwm7_n_shift                                 (0)
#define PWM7_TIMING_CTRL_pwm7_cnt_mode_mask                           (0x80000000)
#define PWM7_TIMING_CTRL_pwm7_ck_sel_hs_mask                          (0x40000000)
#define PWM7_TIMING_CTRL_pwm7_ck_sel_mask                             (0x20000000)
#define PWM7_TIMING_CTRL_pwm7_cycle_max_mask                          (0x0F000000)
#define PWM7_TIMING_CTRL_pwm7_m_mask                                  (0x00003000)
#define PWM7_TIMING_CTRL_pwm7_n_mask                                  (0x00000FFF)
#define PWM7_TIMING_CTRL_pwm7_cnt_mode(data)                          (0x80000000&((data)<<31))
#define PWM7_TIMING_CTRL_pwm7_ck_sel_hs(data)                         (0x40000000&((data)<<30))
#define PWM7_TIMING_CTRL_pwm7_ck_sel(data)                            (0x20000000&((data)<<29))
#define PWM7_TIMING_CTRL_pwm7_cycle_max(data)                         (0x0F000000&((data)<<24))
#define PWM7_TIMING_CTRL_pwm7_m(data)                                 (0x00003000&((data)<<12))
#define PWM7_TIMING_CTRL_pwm7_n(data)                                 (0x00000FFF&(data))
#define PWM7_TIMING_CTRL_get_pwm7_cnt_mode(data)                      ((0x80000000&(data))>>31)
#define PWM7_TIMING_CTRL_get_pwm7_ck_sel_hs(data)                     ((0x40000000&(data))>>30)
#define PWM7_TIMING_CTRL_get_pwm7_ck_sel(data)                        ((0x20000000&(data))>>29)
#define PWM7_TIMING_CTRL_get_pwm7_cycle_max(data)                     ((0x0F000000&(data))>>24)
#define PWM7_TIMING_CTRL_get_pwm7_m(data)                             ((0x00003000&(data))>>12)
#define PWM7_TIMING_CTRL_get_pwm7_n(data)                             (0x00000FFF&(data))


#define PWM7_DUTY_SET                                                 0x18012160
#define PWM7_DUTY_SET_reg_addr                                        "0xb8012160"
#define PWM7_DUTY_SET_reg                                             0xb8012160
#define PWM7_DUTY_SET_inst_addr                                       "0x0058"
#define PWM7_DUTY_SET_inst                                            0x0058
#define PWM7_DUTY_SET_pwm7_dut_shift                                  (16)
#define PWM7_DUTY_SET_pwm7_totalcnt_shift                             (0)
#define PWM7_DUTY_SET_pwm7_dut_mask                                   (0x0FFF0000)
#define PWM7_DUTY_SET_pwm7_totalcnt_mask                              (0x00000FFF)
#define PWM7_DUTY_SET_pwm7_dut(data)                                  (0x0FFF0000&((data)<<16))
#define PWM7_DUTY_SET_pwm7_totalcnt(data)                             (0x00000FFF&(data))
#define PWM7_DUTY_SET_get_pwm7_dut(data)                              ((0x0FFF0000&(data))>>16)
#define PWM7_DUTY_SET_get_pwm7_totalcnt(data)                         (0x00000FFF&(data))


#define EF_CTRL0                                                      0x18012200
#define EF_CTRL0_reg_addr                                             "0xb8012200"
#define EF_CTRL0_reg                                                  0xb8012200
#define EF_CTRL0_inst_addr                                            "0x0080"
#define EF_CTRL0_inst                                                 0x0080
#define EF_CTRL0_rvd_a_shift                                          (25)
#define EF_CTRL0_auto_read_shift                                      (24)
#define EF_CTRL0_selvpp_shift                                         (20)
#define EF_CTRL0_op_shift                                             (16)
#define EF_CTRL0_key_protect_bit_shift                                (15)
#define EF_CTRL0_read_shift                                           (13)
#define EF_CTRL0_enb_shift                                            (12)
#define EF_CTRL0_b_shift                                              (8)
#define EF_CTRL0_a_shift                                              (0)
#define EF_CTRL0_rvd_a_mask                                           (0x0E000000)
#define EF_CTRL0_auto_read_mask                                       (0x01000000)
#define EF_CTRL0_selvpp_mask                                          (0x00700000)
#define EF_CTRL0_op_mask                                              (0x00070000)
#define EF_CTRL0_key_protect_bit_mask                                 (0x00008000)
#define EF_CTRL0_read_mask                                            (0x00002000)
#define EF_CTRL0_enb_mask                                             (0x00001000)
#define EF_CTRL0_b_mask                                               (0x00000700)
#define EF_CTRL0_a_mask                                               (0x0000001F)
#define EF_CTRL0_rvd_a(data)                                          (0x0E000000&((data)<<25))
#define EF_CTRL0_auto_read(data)                                      (0x01000000&((data)<<24))
#define EF_CTRL0_selvpp(data)                                         (0x00700000&((data)<<20))
#define EF_CTRL0_op(data)                                             (0x00070000&((data)<<16))
#define EF_CTRL0_key_protect_bit(data)                                (0x00008000&((data)<<15))
#define EF_CTRL0_read(data)                                           (0x00002000&((data)<<13))
#define EF_CTRL0_enb(data)                                            (0x00001000&((data)<<12))
#define EF_CTRL0_b(data)                                              (0x00000700&((data)<<8))
#define EF_CTRL0_a(data)                                              (0x0000001F&(data))
#define EF_CTRL0_get_rvd_a(data)                                      ((0x0E000000&(data))>>25)
#define EF_CTRL0_get_auto_read(data)                                  ((0x01000000&(data))>>24)
#define EF_CTRL0_get_selvpp(data)                                     ((0x00700000&(data))>>20)
#define EF_CTRL0_get_op(data)                                         ((0x00070000&(data))>>16)
#define EF_CTRL0_get_key_protect_bit(data)                            ((0x00008000&(data))>>15)
#define EF_CTRL0_get_read(data)                                       ((0x00002000&(data))>>13)
#define EF_CTRL0_get_enb(data)                                        ((0x00001000&(data))>>12)
#define EF_CTRL0_get_b(data)                                          ((0x00000700&(data))>>8)
#define EF_CTRL0_get_a(data)                                          (0x0000001F&(data))


#define EF_CTRL1                                                      0x18012204
#define EF_CTRL1_reg_addr                                             "0xb8012204"
#define EF_CTRL1_reg                                                  0xb8012204
#define EF_CTRL1_inst_addr                                            "0x0081"
#define EF_CTRL1_inst                                                 0x0081
#define EF_CTRL1_mode_shift                                           (1)
#define EF_CTRL1_program_shift                                        (0)
#define EF_CTRL1_mode_mask                                            (0x00000002)
#define EF_CTRL1_program_mask                                         (0x00000001)
#define EF_CTRL1_mode(data)                                           (0x00000002&((data)<<1))
#define EF_CTRL1_program(data)                                        (0x00000001&(data))
#define EF_CTRL1_get_mode(data)                                       ((0x00000002&(data))>>1)
#define EF_CTRL1_get_program(data)                                    (0x00000001&(data))


#define EF_CTRL_ST                                                    0x18012208
#define EF_CTRL_ST_reg_addr                                           "0xb8012208"
#define EF_CTRL_ST_reg                                                0xb8012208
#define EF_CTRL_ST_inst_addr                                          "0x0082"
#define EF_CTRL_ST_inst                                               0x0082
#define EF_CTRL_ST_auto_read_done_shift                               (0)
#define EF_CTRL_ST_auto_read_done_mask                                (0x00000001)
#define EF_CTRL_ST_auto_read_done(data)                               (0x00000001&(data))
#define EF_CTRL_ST_get_auto_read_done(data)                           (0x00000001&(data))


#define EF0                                                           0x1801220c
#define EF0_reg_addr                                                  "0xb801220c"
#define EF0_reg                                                       0xb801220c
#define EF0_inst_addr                                                 "0x0083"
#define EF0_inst                                                      0x0083
#define EF0_dout_shift                                                (0)
#define EF0_dout_mask                                                 (0xFFFFFFFF)
#define EF0_dout(data)                                                (0xFFFFFFFF&(data))
#define EF0_get_dout(data)                                            (0xFFFFFFFF&(data))


#define EF1                                                           0x18012210
#define EF1_reg_addr                                                  "0xb8012210"
#define EF1_reg                                                       0xb8012210
#define EF1_inst_addr                                                 "0x0084"
#define EF1_inst                                                      0x0084
#define EF1_dout_shift                                                (0)
#define EF1_dout_mask                                                 (0xFFFFFFFF)
#define EF1_dout(data)                                                (0xFFFFFFFF&(data))
#define EF1_get_dout(data)                                            (0xFFFFFFFF&(data))


#define EF_CTRL_ST                                                    0x18012214
#define EF_CTRL_ST_reg_addr                                           "0xb8012214"
#define EF_CTRL_ST_reg                                                0xb8012214
#define EF_CTRL_ST_inst_addr                                          "0x0085"
#define EF_CTRL_ST_inst                                               0x0085
#define EF_CTRL_ST_crc_en_shift                                       (0)
#define EF_CTRL_ST_crc_en_mask                                        (0x00000001)
#define EF_CTRL_ST_crc_en(data)                                       (0x00000001&(data))
#define EF_CTRL_ST_get_crc_en(data)                                   (0x00000001&(data))


#define EF_CRC                                                        0x18012218
#define EF_CRC_reg_addr                                               "0xb8012218"
#define EF_CRC_reg                                                    0xb8012218
#define EF_CRC_inst_addr                                              "0x0086"
#define EF_CRC_inst                                                   0x0086
#define EF_CRC_crc_ini_shift                                          (16)
#define EF_CRC_crc_out_shift                                          (0)
#define EF_CRC_crc_ini_mask                                           (0xFFFF0000)
#define EF_CRC_crc_out_mask                                           (0x0000FFFF)
#define EF_CRC_crc_ini(data)                                          (0xFFFF0000&((data)<<16))
#define EF_CRC_crc_out(data)                                          (0x0000FFFF&(data))
#define EF_CRC_get_crc_ini(data)                                      ((0xFFFF0000&(data))>>16)
#define EF_CRC_get_crc_out(data)                                      (0x0000FFFF&(data))


#define IC_CON                                                        0x18012300
#define IC_CON_reg_addr                                               "0xb8012300"
#define IC_CON_reg                                                    0xb8012300
#define IC_CON_inst_addr                                              "0x00C0"
#define IC_CON_inst                                                   0x00C0
#define IC_CON_ic_slave_disable_shift                                 (6)
#define IC_CON_ic_restart_en_shift                                    (5)
#define IC_CON_ic_10bitaddr_master_shift                              (4)
#define IC_CON_ic_10bitaddr_slave_shift                               (3)
#define IC_CON_speed_shift                                            (1)
#define IC_CON_master_mode_shift                                      (0)
#define IC_CON_ic_slave_disable_mask                                  (0x00000040)
#define IC_CON_ic_restart_en_mask                                     (0x00000020)
#define IC_CON_ic_10bitaddr_master_mask                               (0x00000010)
#define IC_CON_ic_10bitaddr_slave_mask                                (0x00000008)
#define IC_CON_speed_mask                                             (0x00000006)
#define IC_CON_master_mode_mask                                       (0x00000001)
#define IC_CON_ic_slave_disable(data)                                 (0x00000040&((data)<<6))
#define IC_CON_ic_restart_en(data)                                    (0x00000020&((data)<<5))
#define IC_CON_ic_10bitaddr_master(data)                              (0x00000010&((data)<<4))
#define IC_CON_ic_10bitaddr_slave(data)                               (0x00000008&((data)<<3))
#define IC_CON_speed(data)                                            (0x00000006&((data)<<1))
#define IC_CON_master_mode(data)                                      (0x00000001&(data))
#define IC_CON_get_ic_slave_disable(data)                             ((0x00000040&(data))>>6)
#define IC_CON_get_ic_restart_en(data)                                ((0x00000020&(data))>>5)
#define IC_CON_get_ic_10bitaddr_master(data)                          ((0x00000010&(data))>>4)
#define IC_CON_get_ic_10bitaddr_slave(data)                           ((0x00000008&(data))>>3)
#define IC_CON_get_speed(data)                                        ((0x00000006&(data))>>1)
#define IC_CON_get_master_mode(data)                                  (0x00000001&(data))


#define IC_TAR                                                        0x18012304
#define IC_TAR_reg_addr                                               "0xb8012304"
#define IC_TAR_reg                                                    0xb8012304
#define IC_TAR_inst_addr                                              "0x00C1"
#define IC_TAR_inst                                                   0x00C1
#define IC_TAR_special_shift                                          (11)
#define IC_TAR_gc_or_start_shift                                      (10)
#define IC_TAR_ic_tar_shift                                           (0)
#define IC_TAR_special_mask                                           (0x00000800)
#define IC_TAR_gc_or_start_mask                                       (0x00000400)
#define IC_TAR_ic_tar_mask                                            (0x000003FF)
#define IC_TAR_special(data)                                          (0x00000800&((data)<<11))
#define IC_TAR_gc_or_start(data)                                      (0x00000400&((data)<<10))
#define IC_TAR_ic_tar(data)                                           (0x000003FF&(data))
#define IC_TAR_get_special(data)                                      ((0x00000800&(data))>>11)
#define IC_TAR_get_gc_or_start(data)                                  ((0x00000400&(data))>>10)
#define IC_TAR_get_ic_tar(data)                                       (0x000003FF&(data))


#define IC_SAR                                                        0x18012308
#define IC_SAR_reg_addr                                               "0xb8012308"
#define IC_SAR_reg                                                    0xb8012308
#define IC_SAR_inst_addr                                              "0x00C2"
#define IC_SAR_inst                                                   0x00C2
#define IC_SAR_ic_sar_shift                                           (0)
#define IC_SAR_ic_sar_mask                                            (0x000003FF)
#define IC_SAR_ic_sar(data)                                           (0x000003FF&(data))
#define IC_SAR_get_ic_sar(data)                                       (0x000003FF&(data))


#define IC_HS_MADDR                                                   0x1801230c
#define IC_HS_MADDR_reg_addr                                          "0xb801230c"
#define IC_HS_MADDR_reg                                               0xb801230c
#define IC_HS_MADDR_inst_addr                                         "0x00C3"
#define IC_HS_MADDR_inst                                              0x00C3
#define IC_HS_MADDR_ic_hs_mar_shift                                   (0)
#define IC_HS_MADDR_ic_hs_mar_mask                                    (0x00000007)
#define IC_HS_MADDR_ic_hs_mar(data)                                   (0x00000007&(data))
#define IC_HS_MADDR_get_ic_hs_mar(data)                               (0x00000007&(data))


#define IC_DATA_CMD                                                   0x18012310
#define IC_DATA_CMD_reg_addr                                          "0xb8012310"
#define IC_DATA_CMD_reg                                               0xb8012310
#define IC_DATA_CMD_inst_addr                                         "0x00C4"
#define IC_DATA_CMD_inst                                              0x00C4
#define IC_DATA_CMD_cmd_shift                                         (8)
#define IC_DATA_CMD_dat_shift                                         (0)
#define IC_DATA_CMD_cmd_mask                                          (0x00000100)
#define IC_DATA_CMD_dat_mask                                          (0x000000FF)
#define IC_DATA_CMD_cmd(data)                                         (0x00000100&((data)<<8))
#define IC_DATA_CMD_dat(data)                                         (0x000000FF&(data))
#define IC_DATA_CMD_get_cmd(data)                                     ((0x00000100&(data))>>8)
#define IC_DATA_CMD_get_dat(data)                                     (0x000000FF&(data))


#define IC_SS_SCL_HCNT                                                0x18012314
#define IC_SS_SCL_HCNT_reg_addr                                       "0xb8012314"
#define IC_SS_SCL_HCNT_reg                                            0xb8012314
#define IC_SS_SCL_HCNT_inst_addr                                      "0x00C5"
#define IC_SS_SCL_HCNT_inst                                           0x00C5
#define IC_SS_SCL_HCNT_ic_ss_scl_hcnt_shift                           (0)
#define IC_SS_SCL_HCNT_ic_ss_scl_hcnt_mask                            (0x0000FFFF)
#define IC_SS_SCL_HCNT_ic_ss_scl_hcnt(data)                           (0x0000FFFF&(data))
#define IC_SS_SCL_HCNT_get_ic_ss_scl_hcnt(data)                       (0x0000FFFF&(data))


#define IS_SS_SCL_LCNT                                                0x18012318
#define IS_SS_SCL_LCNT_reg_addr                                       "0xb8012318"
#define IS_SS_SCL_LCNT_reg                                            0xb8012318
#define IS_SS_SCL_LCNT_inst_addr                                      "0x00C6"
#define IS_SS_SCL_LCNT_inst                                           0x00C6
#define IS_SS_SCL_LCNT_ic_ss_scl_lcnt_shift                           (0)
#define IS_SS_SCL_LCNT_ic_ss_scl_lcnt_mask                            (0x0000FFFF)
#define IS_SS_SCL_LCNT_ic_ss_scl_lcnt(data)                           (0x0000FFFF&(data))
#define IS_SS_SCL_LCNT_get_ic_ss_scl_lcnt(data)                       (0x0000FFFF&(data))


#define IC_FS_SCL_HCNT                                                0x1801231c
#define IC_FS_SCL_HCNT_reg_addr                                       "0xb801231c"
#define IC_FS_SCL_HCNT_reg                                            0xb801231c
#define IC_FS_SCL_HCNT_inst_addr                                      "0x00C7"
#define IC_FS_SCL_HCNT_inst                                           0x00C7
#define IC_FS_SCL_HCNT_ic_fs_scl_hcnt_shift                           (0)
#define IC_FS_SCL_HCNT_ic_fs_scl_hcnt_mask                            (0x0000FFFF)
#define IC_FS_SCL_HCNT_ic_fs_scl_hcnt(data)                           (0x0000FFFF&(data))
#define IC_FS_SCL_HCNT_get_ic_fs_scl_hcnt(data)                       (0x0000FFFF&(data))


#define IC_FS_SCL_LCNT                                                0x18012320
#define IC_FS_SCL_LCNT_reg_addr                                       "0xb8012320"
#define IC_FS_SCL_LCNT_reg                                            0xb8012320
#define IC_FS_SCL_LCNT_inst_addr                                      "0x00C8"
#define IC_FS_SCL_LCNT_inst                                           0x00C8
#define IC_FS_SCL_LCNT_ic_fs_scl_lcnt_shift                           (0)
#define IC_FS_SCL_LCNT_ic_fs_scl_lcnt_mask                            (0x0000FFFF)
#define IC_FS_SCL_LCNT_ic_fs_scl_lcnt(data)                           (0x0000FFFF&(data))
#define IC_FS_SCL_LCNT_get_ic_fs_scl_lcnt(data)                       (0x0000FFFF&(data))


#define IC_INTR_STAT                                                  0x1801232c
#define IC_INTR_STAT_reg_addr                                         "0xb801232c"
#define IC_INTR_STAT_reg                                              0xb801232c
#define IC_INTR_STAT_inst_addr                                        "0x00CB"
#define IC_INTR_STAT_inst                                             0x00CB
#define IC_INTR_STAT_gen_call_shift                                   (11)
#define IC_INTR_STAT_start_det_shift                                  (10)
#define IC_INTR_STAT_stop_det_shift                                   (9)
#define IC_INTR_STAT_activity_shift                                   (8)
#define IC_INTR_STAT_rx_done_shift                                    (7)
#define IC_INTR_STAT_tx_abrt_shift                                    (6)
#define IC_INTR_STAT_rd_req_shift                                     (5)
#define IC_INTR_STAT_tx_empty_shift                                   (4)
#define IC_INTR_STAT_tx_over_shift                                    (3)
#define IC_INTR_STAT_rx_full_shift                                    (2)
#define IC_INTR_STAT_rx_over_shift                                    (1)
#define IC_INTR_STAT_rx_under_shift                                   (0)
#define IC_INTR_STAT_gen_call_mask                                    (0x00000800)
#define IC_INTR_STAT_start_det_mask                                   (0x00000400)
#define IC_INTR_STAT_stop_det_mask                                    (0x00000200)
#define IC_INTR_STAT_activity_mask                                    (0x00000100)
#define IC_INTR_STAT_rx_done_mask                                     (0x00000080)
#define IC_INTR_STAT_tx_abrt_mask                                     (0x00000040)
#define IC_INTR_STAT_rd_req_mask                                      (0x00000020)
#define IC_INTR_STAT_tx_empty_mask                                    (0x00000010)
#define IC_INTR_STAT_tx_over_mask                                     (0x00000008)
#define IC_INTR_STAT_rx_full_mask                                     (0x00000004)
#define IC_INTR_STAT_rx_over_mask                                     (0x00000002)
#define IC_INTR_STAT_rx_under_mask                                    (0x00000001)
#define IC_INTR_STAT_gen_call(data)                                   (0x00000800&((data)<<11))
#define IC_INTR_STAT_start_det(data)                                  (0x00000400&((data)<<10))
#define IC_INTR_STAT_stop_det(data)                                   (0x00000200&((data)<<9))
#define IC_INTR_STAT_activity(data)                                   (0x00000100&((data)<<8))
#define IC_INTR_STAT_rx_done(data)                                    (0x00000080&((data)<<7))
#define IC_INTR_STAT_tx_abrt(data)                                    (0x00000040&((data)<<6))
#define IC_INTR_STAT_rd_req(data)                                     (0x00000020&((data)<<5))
#define IC_INTR_STAT_tx_empty(data)                                   (0x00000010&((data)<<4))
#define IC_INTR_STAT_tx_over(data)                                    (0x00000008&((data)<<3))
#define IC_INTR_STAT_rx_full(data)                                    (0x00000004&((data)<<2))
#define IC_INTR_STAT_rx_over(data)                                    (0x00000002&((data)<<1))
#define IC_INTR_STAT_rx_under(data)                                   (0x00000001&(data))
#define IC_INTR_STAT_get_gen_call(data)                               ((0x00000800&(data))>>11)
#define IC_INTR_STAT_get_start_det(data)                              ((0x00000400&(data))>>10)
#define IC_INTR_STAT_get_stop_det(data)                               ((0x00000200&(data))>>9)
#define IC_INTR_STAT_get_activity(data)                               ((0x00000100&(data))>>8)
#define IC_INTR_STAT_get_rx_done(data)                                ((0x00000080&(data))>>7)
#define IC_INTR_STAT_get_tx_abrt(data)                                ((0x00000040&(data))>>6)
#define IC_INTR_STAT_get_rd_req(data)                                 ((0x00000020&(data))>>5)
#define IC_INTR_STAT_get_tx_empty(data)                               ((0x00000010&(data))>>4)
#define IC_INTR_STAT_get_tx_over(data)                                ((0x00000008&(data))>>3)
#define IC_INTR_STAT_get_rx_full(data)                                ((0x00000004&(data))>>2)
#define IC_INTR_STAT_get_rx_over(data)                                ((0x00000002&(data))>>1)
#define IC_INTR_STAT_get_rx_under(data)                               (0x00000001&(data))


#define IC_INTR_MASK                                                  0x18012330
#define IC_INTR_MASK_reg_addr                                         "0xb8012330"
#define IC_INTR_MASK_reg                                              0xb8012330
#define IC_INTR_MASK_inst_addr                                        "0x00CC"
#define IC_INTR_MASK_inst                                             0x00CC
#define IC_INTR_MASK_m_gen_call_shift                                 (11)
#define IC_INTR_MASK_m_start_det_shift                                (10)
#define IC_INTR_MASK_m_stop_det_shift                                 (9)
#define IC_INTR_MASK_m_activity_shift                                 (8)
#define IC_INTR_MASK_m_rx_done_shift                                  (7)
#define IC_INTR_MASK_m_tx_abrt_shift                                  (6)
#define IC_INTR_MASK_m_rd_req_shift                                   (5)
#define IC_INTR_MASK_m_tx_empty_shift                                 (4)
#define IC_INTR_MASK_m_tx_over_shift                                  (3)
#define IC_INTR_MASK_m_rx_full_shift                                  (2)
#define IC_INTR_MASK_m_rx_over_shift                                  (1)
#define IC_INTR_MASK_m_rx_under_shift                                 (0)
#define IC_INTR_MASK_m_gen_call_mask                                  (0x00000800)
#define IC_INTR_MASK_m_start_det_mask                                 (0x00000400)
#define IC_INTR_MASK_m_stop_det_mask                                  (0x00000200)
#define IC_INTR_MASK_m_activity_mask                                  (0x00000100)
#define IC_INTR_MASK_m_rx_done_mask                                   (0x00000080)
#define IC_INTR_MASK_m_tx_abrt_mask                                   (0x00000040)
#define IC_INTR_MASK_m_rd_req_mask                                    (0x00000020)
#define IC_INTR_MASK_m_tx_empty_mask                                  (0x00000010)
#define IC_INTR_MASK_m_tx_over_mask                                   (0x00000008)
#define IC_INTR_MASK_m_rx_full_mask                                   (0x00000004)
#define IC_INTR_MASK_m_rx_over_mask                                   (0x00000002)
#define IC_INTR_MASK_m_rx_under_mask                                  (0x00000001)
#define IC_INTR_MASK_m_gen_call(data)                                 (0x00000800&((data)<<11))
#define IC_INTR_MASK_m_start_det(data)                                (0x00000400&((data)<<10))
#define IC_INTR_MASK_m_stop_det(data)                                 (0x00000200&((data)<<9))
#define IC_INTR_MASK_m_activity(data)                                 (0x00000100&((data)<<8))
#define IC_INTR_MASK_m_rx_done(data)                                  (0x00000080&((data)<<7))
#define IC_INTR_MASK_m_tx_abrt(data)                                  (0x00000040&((data)<<6))
#define IC_INTR_MASK_m_rd_req(data)                                   (0x00000020&((data)<<5))
#define IC_INTR_MASK_m_tx_empty(data)                                 (0x00000010&((data)<<4))
#define IC_INTR_MASK_m_tx_over(data)                                  (0x00000008&((data)<<3))
#define IC_INTR_MASK_m_rx_full(data)                                  (0x00000004&((data)<<2))
#define IC_INTR_MASK_m_rx_over(data)                                  (0x00000002&((data)<<1))
#define IC_INTR_MASK_m_rx_under(data)                                 (0x00000001&(data))
#define IC_INTR_MASK_get_m_gen_call(data)                             ((0x00000800&(data))>>11)
#define IC_INTR_MASK_get_m_start_det(data)                            ((0x00000400&(data))>>10)
#define IC_INTR_MASK_get_m_stop_det(data)                             ((0x00000200&(data))>>9)
#define IC_INTR_MASK_get_m_activity(data)                             ((0x00000100&(data))>>8)
#define IC_INTR_MASK_get_m_rx_done(data)                              ((0x00000080&(data))>>7)
#define IC_INTR_MASK_get_m_tx_abrt(data)                              ((0x00000040&(data))>>6)
#define IC_INTR_MASK_get_m_rd_req(data)                               ((0x00000020&(data))>>5)
#define IC_INTR_MASK_get_m_tx_empty(data)                             ((0x00000010&(data))>>4)
#define IC_INTR_MASK_get_m_tx_over(data)                              ((0x00000008&(data))>>3)
#define IC_INTR_MASK_get_m_rx_full(data)                              ((0x00000004&(data))>>2)
#define IC_INTR_MASK_get_m_rx_over(data)                              ((0x00000002&(data))>>1)
#define IC_INTR_MASK_get_m_rx_under(data)                             (0x00000001&(data))


#define IC_RAW_INTR_STAT                                              0x18012334
#define IC_RAW_INTR_STAT_reg_addr                                     "0xb8012334"
#define IC_RAW_INTR_STAT_reg                                          0xb8012334
#define IC_RAW_INTR_STAT_inst_addr                                    "0x00CD"
#define IC_RAW_INTR_STAT_inst                                         0x00CD
#define IC_RAW_INTR_STAT_r_gen_call_shift                             (11)
#define IC_RAW_INTR_STAT_r_start_det_shift                            (10)
#define IC_RAW_INTR_STAT_r_stop_det_shift                             (9)
#define IC_RAW_INTR_STAT_r_activity_shift                             (8)
#define IC_RAW_INTR_STAT_r_rx_done_shift                              (7)
#define IC_RAW_INTR_STAT_r_tx_abrt_shift                              (6)
#define IC_RAW_INTR_STAT_r_rd_req_shift                               (5)
#define IC_RAW_INTR_STAT_r_tx_empty_shift                             (4)
#define IC_RAW_INTR_STAT_r_tx_over_shift                              (3)
#define IC_RAW_INTR_STAT_r_rx_full_shift                              (2)
#define IC_RAW_INTR_STAT_r_rx_over_shift                              (1)
#define IC_RAW_INTR_STAT_r_rx_under_shift                             (0)
#define IC_RAW_INTR_STAT_r_gen_call_mask                              (0x00000800)
#define IC_RAW_INTR_STAT_r_start_det_mask                             (0x00000400)
#define IC_RAW_INTR_STAT_r_stop_det_mask                              (0x00000200)
#define IC_RAW_INTR_STAT_r_activity_mask                              (0x00000100)
#define IC_RAW_INTR_STAT_r_rx_done_mask                               (0x00000080)
#define IC_RAW_INTR_STAT_r_tx_abrt_mask                               (0x00000040)
#define IC_RAW_INTR_STAT_r_rd_req_mask                                (0x00000020)
#define IC_RAW_INTR_STAT_r_tx_empty_mask                              (0x00000010)
#define IC_RAW_INTR_STAT_r_tx_over_mask                               (0x00000008)
#define IC_RAW_INTR_STAT_r_rx_full_mask                               (0x00000004)
#define IC_RAW_INTR_STAT_r_rx_over_mask                               (0x00000002)
#define IC_RAW_INTR_STAT_r_rx_under_mask                              (0x00000001)
#define IC_RAW_INTR_STAT_r_gen_call(data)                             (0x00000800&((data)<<11))
#define IC_RAW_INTR_STAT_r_start_det(data)                            (0x00000400&((data)<<10))
#define IC_RAW_INTR_STAT_r_stop_det(data)                             (0x00000200&((data)<<9))
#define IC_RAW_INTR_STAT_r_activity(data)                             (0x00000100&((data)<<8))
#define IC_RAW_INTR_STAT_r_rx_done(data)                              (0x00000080&((data)<<7))
#define IC_RAW_INTR_STAT_r_tx_abrt(data)                              (0x00000040&((data)<<6))
#define IC_RAW_INTR_STAT_r_rd_req(data)                               (0x00000020&((data)<<5))
#define IC_RAW_INTR_STAT_r_tx_empty(data)                             (0x00000010&((data)<<4))
#define IC_RAW_INTR_STAT_r_tx_over(data)                              (0x00000008&((data)<<3))
#define IC_RAW_INTR_STAT_r_rx_full(data)                              (0x00000004&((data)<<2))
#define IC_RAW_INTR_STAT_r_rx_over(data)                              (0x00000002&((data)<<1))
#define IC_RAW_INTR_STAT_r_rx_under(data)                             (0x00000001&(data))
#define IC_RAW_INTR_STAT_get_r_gen_call(data)                         ((0x00000800&(data))>>11)
#define IC_RAW_INTR_STAT_get_r_start_det(data)                        ((0x00000400&(data))>>10)
#define IC_RAW_INTR_STAT_get_r_stop_det(data)                         ((0x00000200&(data))>>9)
#define IC_RAW_INTR_STAT_get_r_activity(data)                         ((0x00000100&(data))>>8)
#define IC_RAW_INTR_STAT_get_r_rx_done(data)                          ((0x00000080&(data))>>7)
#define IC_RAW_INTR_STAT_get_r_tx_abrt(data)                          ((0x00000040&(data))>>6)
#define IC_RAW_INTR_STAT_get_r_rd_req(data)                           ((0x00000020&(data))>>5)
#define IC_RAW_INTR_STAT_get_r_tx_empty(data)                         ((0x00000010&(data))>>4)
#define IC_RAW_INTR_STAT_get_r_tx_over(data)                          ((0x00000008&(data))>>3)
#define IC_RAW_INTR_STAT_get_r_rx_full(data)                          ((0x00000004&(data))>>2)
#define IC_RAW_INTR_STAT_get_r_rx_over(data)                          ((0x00000002&(data))>>1)
#define IC_RAW_INTR_STAT_get_r_rx_under(data)                         (0x00000001&(data))


#define IC_RX_TL                                                      0x18012338
#define IC_RX_TL_reg_addr                                             "0xb8012338"
#define IC_RX_TL_reg                                                  0xb8012338
#define IC_RX_TL_inst_addr                                            "0x00CE"
#define IC_RX_TL_inst                                                 0x00CE
#define IC_RX_TL_rx_tl_shift                                          (0)
#define IC_RX_TL_rx_tl_mask                                           (0x000000FF)
#define IC_RX_TL_rx_tl(data)                                          (0x000000FF&(data))
#define IC_RX_TL_get_rx_tl(data)                                      (0x000000FF&(data))


#define IC_TX_TL                                                      0x1801233c
#define IC_TX_TL_reg_addr                                             "0xb801233c"
#define IC_TX_TL_reg                                                  0xb801233c
#define IC_TX_TL_inst_addr                                            "0x00CF"
#define IC_TX_TL_inst                                                 0x00CF
#define IC_TX_TL_tx_tl_shift                                          (0)
#define IC_TX_TL_tx_tl_mask                                           (0x000000FF)
#define IC_TX_TL_tx_tl(data)                                          (0x000000FF&(data))
#define IC_TX_TL_get_tx_tl(data)                                      (0x000000FF&(data))


#define IC_CLR_INTR                                                   0x18012340
#define IC_CLR_INTR_reg_addr                                          "0xb8012340"
#define IC_CLR_INTR_reg                                               0xb8012340
#define IC_CLR_INTR_inst_addr                                         "0x00D0"
#define IC_CLR_INTR_inst                                              0x00D0
#define IC_CLR_INTR_clr_intr_shift                                    (0)
#define IC_CLR_INTR_clr_intr_mask                                     (0x00000001)
#define IC_CLR_INTR_clr_intr(data)                                    (0x00000001&(data))
#define IC_CLR_INTR_get_clr_intr(data)                                (0x00000001&(data))


#define IC_CLR_RX_UNDER                                               0x18012344
#define IC_CLR_RX_UNDER_reg_addr                                      "0xb8012344"
#define IC_CLR_RX_UNDER_reg                                           0xb8012344
#define IC_CLR_RX_UNDER_inst_addr                                     "0x00D1"
#define IC_CLR_RX_UNDER_inst                                          0x00D1
#define IC_CLR_RX_UNDER_clr_rx_under_shift                            (0)
#define IC_CLR_RX_UNDER_clr_rx_under_mask                             (0x00000001)
#define IC_CLR_RX_UNDER_clr_rx_under(data)                            (0x00000001&(data))
#define IC_CLR_RX_UNDER_get_clr_rx_under(data)                        (0x00000001&(data))


#define IC_CLR_RX_OVER                                                0x18012348
#define IC_CLR_RX_OVER_reg_addr                                       "0xb8012348"
#define IC_CLR_RX_OVER_reg                                            0xb8012348
#define IC_CLR_RX_OVER_inst_addr                                      "0x00D2"
#define IC_CLR_RX_OVER_inst                                           0x00D2
#define IC_CLR_RX_OVER_clr_rx_over_shift                              (0)
#define IC_CLR_RX_OVER_clr_rx_over_mask                               (0x00000001)
#define IC_CLR_RX_OVER_clr_rx_over(data)                              (0x00000001&(data))
#define IC_CLR_RX_OVER_get_clr_rx_over(data)                          (0x00000001&(data))


#define IC_CLR_TX_OVER                                                0x1801234c
#define IC_CLR_TX_OVER_reg_addr                                       "0xb801234c"
#define IC_CLR_TX_OVER_reg                                            0xb801234c
#define IC_CLR_TX_OVER_inst_addr                                      "0x00D3"
#define IC_CLR_TX_OVER_inst                                           0x00D3
#define IC_CLR_TX_OVER_clr_tx_over_shift                              (0)
#define IC_CLR_TX_OVER_clr_tx_over_mask                               (0x00000001)
#define IC_CLR_TX_OVER_clr_tx_over(data)                              (0x00000001&(data))
#define IC_CLR_TX_OVER_get_clr_tx_over(data)                          (0x00000001&(data))


#define IC_CLR_RD_REQ                                                 0x18012350
#define IC_CLR_RD_REQ_reg_addr                                        "0xb8012350"
#define IC_CLR_RD_REQ_reg                                             0xb8012350
#define IC_CLR_RD_REQ_inst_addr                                       "0x00D4"
#define IC_CLR_RD_REQ_inst                                            0x00D4
#define IC_CLR_RD_REQ_clr_rd_req_shift                                (0)
#define IC_CLR_RD_REQ_clr_rd_req_mask                                 (0x00000001)
#define IC_CLR_RD_REQ_clr_rd_req(data)                                (0x00000001&(data))
#define IC_CLR_RD_REQ_get_clr_rd_req(data)                            (0x00000001&(data))


#define IC_CLR_TX_ABRT                                                0x18012354
#define IC_CLR_TX_ABRT_reg_addr                                       "0xb8012354"
#define IC_CLR_TX_ABRT_reg                                            0xb8012354
#define IC_CLR_TX_ABRT_inst_addr                                      "0x00D5"
#define IC_CLR_TX_ABRT_inst                                           0x00D5
#define IC_CLR_TX_ABRT_clr_tx_abrt_shift                              (0)
#define IC_CLR_TX_ABRT_clr_tx_abrt_mask                               (0x00000001)
#define IC_CLR_TX_ABRT_clr_tx_abrt(data)                              (0x00000001&(data))
#define IC_CLR_TX_ABRT_get_clr_tx_abrt(data)                          (0x00000001&(data))


#define IC_CLR_RX_DONE                                                0x18012358
#define IC_CLR_RX_DONE_reg_addr                                       "0xb8012358"
#define IC_CLR_RX_DONE_reg                                            0xb8012358
#define IC_CLR_RX_DONE_inst_addr                                      "0x00D6"
#define IC_CLR_RX_DONE_inst                                           0x00D6
#define IC_CLR_RX_DONE_clr_rx_done_shift                              (0)
#define IC_CLR_RX_DONE_clr_rx_done_mask                               (0x00000001)
#define IC_CLR_RX_DONE_clr_rx_done(data)                              (0x00000001&(data))
#define IC_CLR_RX_DONE_get_clr_rx_done(data)                          (0x00000001&(data))


#define IC_CLR_ACTIVITY                                               0x1801235c
#define IC_CLR_ACTIVITY_reg_addr                                      "0xb801235c"
#define IC_CLR_ACTIVITY_reg                                           0xb801235c
#define IC_CLR_ACTIVITY_inst_addr                                     "0x00D7"
#define IC_CLR_ACTIVITY_inst                                          0x00D7
#define IC_CLR_ACTIVITY_clr_activity_shift                            (0)
#define IC_CLR_ACTIVITY_clr_activity_mask                             (0x00000001)
#define IC_CLR_ACTIVITY_clr_activity(data)                            (0x00000001&(data))
#define IC_CLR_ACTIVITY_get_clr_activity(data)                        (0x00000001&(data))


#define IC_CLR_STOP_DET                                               0x18012360
#define IC_CLR_STOP_DET_reg_addr                                      "0xb8012360"
#define IC_CLR_STOP_DET_reg                                           0xb8012360
#define IC_CLR_STOP_DET_inst_addr                                     "0x00D8"
#define IC_CLR_STOP_DET_inst                                          0x00D8
#define IC_CLR_STOP_DET_clr_stop_det_shift                            (0)
#define IC_CLR_STOP_DET_clr_stop_det_mask                             (0x00000001)
#define IC_CLR_STOP_DET_clr_stop_det(data)                            (0x00000001&(data))
#define IC_CLR_STOP_DET_get_clr_stop_det(data)                        (0x00000001&(data))


#define IC_CLR_START_DET                                              0x18012364
#define IC_CLR_START_DET_reg_addr                                     "0xb8012364"
#define IC_CLR_START_DET_reg                                          0xb8012364
#define IC_CLR_START_DET_inst_addr                                    "0x00D9"
#define IC_CLR_START_DET_inst                                         0x00D9
#define IC_CLR_START_DET_clr_start_det_shift                          (0)
#define IC_CLR_START_DET_clr_start_det_mask                           (0x00000001)
#define IC_CLR_START_DET_clr_start_det(data)                          (0x00000001&(data))
#define IC_CLR_START_DET_get_clr_start_det(data)                      (0x00000001&(data))


#define IC_CLR_GEN_CALL                                               0x18012368
#define IC_CLR_GEN_CALL_reg_addr                                      "0xb8012368"
#define IC_CLR_GEN_CALL_reg                                           0xb8012368
#define IC_CLR_GEN_CALL_inst_addr                                     "0x00DA"
#define IC_CLR_GEN_CALL_inst                                          0x00DA
#define IC_CLR_GEN_CALL_clr_gen_call_shift                            (0)
#define IC_CLR_GEN_CALL_clr_gen_call_mask                             (0x00000001)
#define IC_CLR_GEN_CALL_clr_gen_call(data)                            (0x00000001&(data))
#define IC_CLR_GEN_CALL_get_clr_gen_call(data)                        (0x00000001&(data))


#define IC_ENABLE                                                     0x1801236c
#define IC_ENABLE_reg_addr                                            "0xb801236c"
#define IC_ENABLE_reg                                                 0xb801236c
#define IC_ENABLE_inst_addr                                           "0x00DB"
#define IC_ENABLE_inst                                                0x00DB
#define IC_ENABLE_enable_shift                                        (0)
#define IC_ENABLE_enable_mask                                         (0x00000001)
#define IC_ENABLE_enable(data)                                        (0x00000001&(data))
#define IC_ENABLE_get_enable(data)                                    (0x00000001&(data))


#define IC_STATUS                                                     0x18012370
#define IC_STATUS_reg_addr                                            "0xb8012370"
#define IC_STATUS_reg                                                 0xb8012370
#define IC_STATUS_inst_addr                                           "0x00DC"
#define IC_STATUS_inst                                                0x00DC
#define IC_STATUS_rff_shift                                           (4)
#define IC_STATUS_rfne_shift                                          (3)
#define IC_STATUS_tfe_shift                                           (2)
#define IC_STATUS_tfnf_shift                                          (1)
#define IC_STATUS_activity_shift                                      (0)
#define IC_STATUS_rff_mask                                            (0x00000010)
#define IC_STATUS_rfne_mask                                           (0x00000008)
#define IC_STATUS_tfe_mask                                            (0x00000004)
#define IC_STATUS_tfnf_mask                                           (0x00000002)
#define IC_STATUS_activity_mask                                       (0x00000001)
#define IC_STATUS_rff(data)                                           (0x00000010&((data)<<4))
#define IC_STATUS_rfne(data)                                          (0x00000008&((data)<<3))
#define IC_STATUS_tfe(data)                                           (0x00000004&((data)<<2))
#define IC_STATUS_tfnf(data)                                          (0x00000002&((data)<<1))
#define IC_STATUS_activity(data)                                      (0x00000001&(data))
#define IC_STATUS_get_rff(data)                                       ((0x00000010&(data))>>4)
#define IC_STATUS_get_rfne(data)                                      ((0x00000008&(data))>>3)
#define IC_STATUS_get_tfe(data)                                       ((0x00000004&(data))>>2)
#define IC_STATUS_get_tfnf(data)                                      ((0x00000002&(data))>>1)
#define IC_STATUS_get_activity(data)                                  (0x00000001&(data))


#define IC_TXFLR                                                      0x18012374
#define IC_TXFLR_reg_addr                                             "0xb8012374"
#define IC_TXFLR_reg                                                  0xb8012374
#define IC_TXFLR_inst_addr                                            "0x00DD"
#define IC_TXFLR_inst                                                 0x00DD
#define IC_TXFLR_txflr_shift                                          (0)
#define IC_TXFLR_txflr_mask                                           (0x0000000F)
#define IC_TXFLR_txflr(data)                                          (0x0000000F&(data))
#define IC_TXFLR_get_txflr(data)                                      (0x0000000F&(data))


#define IC_RXFLR                                                      0x18012378
#define IC_RXFLR_reg_addr                                             "0xb8012378"
#define IC_RXFLR_reg                                                  0xb8012378
#define IC_RXFLR_inst_addr                                            "0x00DE"
#define IC_RXFLR_inst                                                 0x00DE
#define IC_RXFLR_rxflr_shift                                          (0)
#define IC_RXFLR_rxflr_mask                                           (0x0000000F)
#define IC_RXFLR_rxflr(data)                                          (0x0000000F&(data))
#define IC_RXFLR_get_rxflr(data)                                      (0x0000000F&(data))


#define IC_TX_ABRT_SOURCE                                             0x18012380
#define IC_TX_ABRT_SOURCE_reg_addr                                    "0xb8012380"
#define IC_TX_ABRT_SOURCE_reg                                         0xb8012380
#define IC_TX_ABRT_SOURCE_inst_addr                                   "0x00E0"
#define IC_TX_ABRT_SOURCE_inst                                        0x00E0
#define IC_TX_ABRT_SOURCE_abrt_slvrd_intx_shift                       (15)
#define IC_TX_ABRT_SOURCE_abrt_slv_arblost_shift                      (14)
#define IC_TX_ABRT_SOURCE_abrt_slvflush_txfifo_shift                  (13)
#define IC_TX_ABRT_SOURCE_arb_lost_shift                              (12)
#define IC_TX_ABRT_SOURCE_arb_master_dis_shift                        (11)
#define IC_TX_ABRT_SOURCE_abrt_10b_rd_norstrt_shift                   (10)
#define IC_TX_ABRT_SOURCE_abrt_sbyte_norstrt_shift                    (9)
#define IC_TX_ABRT_SOURCE_abrt_hs_norstrt_shift                       (8)
#define IC_TX_ABRT_SOURCE_abrt_sbyte_ackdet_shift                     (7)
#define IC_TX_ABRT_SOURCE_abrt_hs_ackdet_shift                        (6)
#define IC_TX_ABRT_SOURCE_abrt_gcall_read_shift                       (5)
#define IC_TX_ABRT_SOURCE_abrt_gcall_noack_shift                      (4)
#define IC_TX_ABRT_SOURCE_abrt_txdata_noack_shift                     (3)
#define IC_TX_ABRT_SOURCE_abrt_10addr2_noack_shift                    (2)
#define IC_TX_ABRT_SOURCE_abrt_10addr1_noack_shift                    (1)
#define IC_TX_ABRT_SOURCE_abrt_7b_addr_noack_shift                    (0)
#define IC_TX_ABRT_SOURCE_abrt_slvrd_intx_mask                        (0x00008000)
#define IC_TX_ABRT_SOURCE_abrt_slv_arblost_mask                       (0x00004000)
#define IC_TX_ABRT_SOURCE_abrt_slvflush_txfifo_mask                   (0x00002000)
#define IC_TX_ABRT_SOURCE_arb_lost_mask                               (0x00001000)
#define IC_TX_ABRT_SOURCE_arb_master_dis_mask                         (0x00000800)
#define IC_TX_ABRT_SOURCE_abrt_10b_rd_norstrt_mask                    (0x00000400)
#define IC_TX_ABRT_SOURCE_abrt_sbyte_norstrt_mask                     (0x00000200)
#define IC_TX_ABRT_SOURCE_abrt_hs_norstrt_mask                        (0x00000100)
#define IC_TX_ABRT_SOURCE_abrt_sbyte_ackdet_mask                      (0x00000080)
#define IC_TX_ABRT_SOURCE_abrt_hs_ackdet_mask                         (0x00000040)
#define IC_TX_ABRT_SOURCE_abrt_gcall_read_mask                        (0x00000020)
#define IC_TX_ABRT_SOURCE_abrt_gcall_noack_mask                       (0x00000010)
#define IC_TX_ABRT_SOURCE_abrt_txdata_noack_mask                      (0x00000008)
#define IC_TX_ABRT_SOURCE_abrt_10addr2_noack_mask                     (0x00000004)
#define IC_TX_ABRT_SOURCE_abrt_10addr1_noack_mask                     (0x00000002)
#define IC_TX_ABRT_SOURCE_abrt_7b_addr_noack_mask                     (0x00000001)
#define IC_TX_ABRT_SOURCE_abrt_slvrd_intx(data)                       (0x00008000&((data)<<15))
#define IC_TX_ABRT_SOURCE_abrt_slv_arblost(data)                      (0x00004000&((data)<<14))
#define IC_TX_ABRT_SOURCE_abrt_slvflush_txfifo(data)                  (0x00002000&((data)<<13))
#define IC_TX_ABRT_SOURCE_arb_lost(data)                              (0x00001000&((data)<<12))
#define IC_TX_ABRT_SOURCE_arb_master_dis(data)                        (0x00000800&((data)<<11))
#define IC_TX_ABRT_SOURCE_abrt_10b_rd_norstrt(data)                   (0x00000400&((data)<<10))
#define IC_TX_ABRT_SOURCE_abrt_sbyte_norstrt(data)                    (0x00000200&((data)<<9))
#define IC_TX_ABRT_SOURCE_abrt_hs_norstrt(data)                       (0x00000100&((data)<<8))
#define IC_TX_ABRT_SOURCE_abrt_sbyte_ackdet(data)                     (0x00000080&((data)<<7))
#define IC_TX_ABRT_SOURCE_abrt_hs_ackdet(data)                        (0x00000040&((data)<<6))
#define IC_TX_ABRT_SOURCE_abrt_gcall_read(data)                       (0x00000020&((data)<<5))
#define IC_TX_ABRT_SOURCE_abrt_gcall_noack(data)                      (0x00000010&((data)<<4))
#define IC_TX_ABRT_SOURCE_abrt_txdata_noack(data)                     (0x00000008&((data)<<3))
#define IC_TX_ABRT_SOURCE_abrt_10addr2_noack(data)                    (0x00000004&((data)<<2))
#define IC_TX_ABRT_SOURCE_abrt_10addr1_noack(data)                    (0x00000002&((data)<<1))
#define IC_TX_ABRT_SOURCE_abrt_7b_addr_noack(data)                    (0x00000001&(data))
#define IC_TX_ABRT_SOURCE_get_abrt_slvrd_intx(data)                   ((0x00008000&(data))>>15)
#define IC_TX_ABRT_SOURCE_get_abrt_slv_arblost(data)                  ((0x00004000&(data))>>14)
#define IC_TX_ABRT_SOURCE_get_abrt_slvflush_txfifo(data)              ((0x00002000&(data))>>13)
#define IC_TX_ABRT_SOURCE_get_arb_lost(data)                          ((0x00001000&(data))>>12)
#define IC_TX_ABRT_SOURCE_get_arb_master_dis(data)                    ((0x00000800&(data))>>11)
#define IC_TX_ABRT_SOURCE_get_abrt_10b_rd_norstrt(data)               ((0x00000400&(data))>>10)
#define IC_TX_ABRT_SOURCE_get_abrt_sbyte_norstrt(data)                ((0x00000200&(data))>>9)
#define IC_TX_ABRT_SOURCE_get_abrt_hs_norstrt(data)                   ((0x00000100&(data))>>8)
#define IC_TX_ABRT_SOURCE_get_abrt_sbyte_ackdet(data)                 ((0x00000080&(data))>>7)
#define IC_TX_ABRT_SOURCE_get_abrt_hs_ackdet(data)                    ((0x00000040&(data))>>6)
#define IC_TX_ABRT_SOURCE_get_abrt_gcall_read(data)                   ((0x00000020&(data))>>5)
#define IC_TX_ABRT_SOURCE_get_abrt_gcall_noack(data)                  ((0x00000010&(data))>>4)
#define IC_TX_ABRT_SOURCE_get_abrt_txdata_noack(data)                 ((0x00000008&(data))>>3)
#define IC_TX_ABRT_SOURCE_get_abrt_10addr2_noack(data)                ((0x00000004&(data))>>2)
#define IC_TX_ABRT_SOURCE_get_abrt_10addr1_noack(data)                ((0x00000002&(data))>>1)
#define IC_TX_ABRT_SOURCE_get_abrt_7b_addr_noack(data)                (0x00000001&(data))


#define IC_PRE_DATA_CMD                                               0x180123a0
#define IC_PRE_DATA_CMD_reg_addr                                      "0xb80123a0"
#define IC_PRE_DATA_CMD_reg                                           0xb80123a0
#define IC_PRE_DATA_CMD_inst_addr                                     "0x00E8"
#define IC_PRE_DATA_CMD_inst                                          0x00E8
#define IC_PRE_DATA_CMD_enable_shift                                  (19)
#define IC_PRE_DATA_CMD_start_shift                                   (18)
#define IC_PRE_DATA_CMD_done_ie_shift                                 (17)
#define IC_PRE_DATA_CMD_done_shift                                    (16)
#define IC_PRE_DATA_CMD_valid_len_shift                               (12)
#define IC_PRE_DATA_CMD_pre_cmd_shift                                 (8)
#define IC_PRE_DATA_CMD_pre_data_shift                                (0)
#define IC_PRE_DATA_CMD_enable_mask                                   (0x00080000)
#define IC_PRE_DATA_CMD_start_mask                                    (0x00040000)
#define IC_PRE_DATA_CMD_done_ie_mask                                  (0x00020000)
#define IC_PRE_DATA_CMD_done_mask                                     (0x00010000)
#define IC_PRE_DATA_CMD_valid_len_mask                                (0x0000F000)
#define IC_PRE_DATA_CMD_pre_cmd_mask                                  (0x00000100)
#define IC_PRE_DATA_CMD_pre_data_mask                                 (0x000000FF)
#define IC_PRE_DATA_CMD_enable(data)                                  (0x00080000&((data)<<19))
#define IC_PRE_DATA_CMD_start(data)                                   (0x00040000&((data)<<18))
#define IC_PRE_DATA_CMD_done_ie(data)                                 (0x00020000&((data)<<17))
#define IC_PRE_DATA_CMD_done(data)                                    (0x00010000&((data)<<16))
#define IC_PRE_DATA_CMD_valid_len(data)                               (0x0000F000&((data)<<12))
#define IC_PRE_DATA_CMD_pre_cmd(data)                                 (0x00000100&((data)<<8))
#define IC_PRE_DATA_CMD_pre_data(data)                                (0x000000FF&(data))
#define IC_PRE_DATA_CMD_get_enable(data)                              ((0x00080000&(data))>>19)
#define IC_PRE_DATA_CMD_get_start(data)                               ((0x00040000&(data))>>18)
#define IC_PRE_DATA_CMD_get_done_ie(data)                             ((0x00020000&(data))>>17)
#define IC_PRE_DATA_CMD_get_done(data)                                ((0x00010000&(data))>>16)
#define IC_PRE_DATA_CMD_get_valid_len(data)                           ((0x0000F000&(data))>>12)
#define IC_PRE_DATA_CMD_get_pre_cmd(data)                             ((0x00000100&(data))>>8)
#define IC_PRE_DATA_CMD_get_pre_data(data)                            (0x000000FF&(data))


#define IC_COMP_PARAM                                                 0x180123f4
#define IC_COMP_PARAM_reg_addr                                        "0xb80123f4"
#define IC_COMP_PARAM_reg                                             0xb80123f4
#define IC_COMP_PARAM_inst_addr                                       "0x00FD"
#define IC_COMP_PARAM_inst                                            0x00FD
#define IC_COMP_PARAM_tx_buffer_depth_shift                           (16)
#define IC_COMP_PARAM_rx_buffer_depth_shift                           (8)
#define IC_COMP_PARAM_add_encoded_params_shift                        (7)
#define IC_COMP_PARAM_has_dma_shift                                   (6)
#define IC_COMP_PARAM_intr_io_shift                                   (5)
#define IC_COMP_PARAM_hc_count_values_shift                           (4)
#define IC_COMP_PARAM_max_speed_mode_shift                            (2)
#define IC_COMP_PARAM_apb_data_width_shift                            (0)
#define IC_COMP_PARAM_tx_buffer_depth_mask                            (0x00FF0000)
#define IC_COMP_PARAM_rx_buffer_depth_mask                            (0x0000FF00)
#define IC_COMP_PARAM_add_encoded_params_mask                         (0x00000080)
#define IC_COMP_PARAM_has_dma_mask                                    (0x00000040)
#define IC_COMP_PARAM_intr_io_mask                                    (0x00000020)
#define IC_COMP_PARAM_hc_count_values_mask                            (0x00000010)
#define IC_COMP_PARAM_max_speed_mode_mask                             (0x0000000C)
#define IC_COMP_PARAM_apb_data_width_mask                             (0x00000003)
#define IC_COMP_PARAM_tx_buffer_depth(data)                           (0x00FF0000&((data)<<16))
#define IC_COMP_PARAM_rx_buffer_depth(data)                           (0x0000FF00&((data)<<8))
#define IC_COMP_PARAM_add_encoded_params(data)                        (0x00000080&((data)<<7))
#define IC_COMP_PARAM_has_dma(data)                                   (0x00000040&((data)<<6))
#define IC_COMP_PARAM_intr_io(data)                                   (0x00000020&((data)<<5))
#define IC_COMP_PARAM_hc_count_values(data)                           (0x00000010&((data)<<4))
#define IC_COMP_PARAM_max_speed_mode(data)                            (0x0000000C&((data)<<2))
#define IC_COMP_PARAM_apb_data_width(data)                            (0x00000003&(data))
#define IC_COMP_PARAM_get_tx_buffer_depth(data)                       ((0x00FF0000&(data))>>16)
#define IC_COMP_PARAM_get_rx_buffer_depth(data)                       ((0x0000FF00&(data))>>8)
#define IC_COMP_PARAM_get_add_encoded_params(data)                    ((0x00000080&(data))>>7)
#define IC_COMP_PARAM_get_has_dma(data)                               ((0x00000040&(data))>>6)
#define IC_COMP_PARAM_get_intr_io(data)                               ((0x00000020&(data))>>5)
#define IC_COMP_PARAM_get_hc_count_values(data)                       ((0x00000010&(data))>>4)
#define IC_COMP_PARAM_get_max_speed_mode(data)                        ((0x0000000C&(data))>>2)
#define IC_COMP_PARAM_get_apb_data_width(data)                        (0x00000003&(data))


#define IC_COMP_VERSION                                               0x180123f8
#define IC_COMP_VERSION_reg_addr                                      "0xb80123f8"
#define IC_COMP_VERSION_reg                                           0xb80123f8
#define IC_COMP_VERSION_inst_addr                                     "0x00FE"
#define IC_COMP_VERSION_inst                                          0x00FE
#define IC_COMP_VERSION_ic_comp_version_shift                         (0)
#define IC_COMP_VERSION_ic_comp_version_mask                          (0xFFFFFFFF)
#define IC_COMP_VERSION_ic_comp_version(data)                         (0xFFFFFFFF&(data))
#define IC_COMP_VERSION_get_ic_comp_version(data)                     (0xFFFFFFFF&(data))


#define IC_COMP_TYPE                                                  0x180123fc
#define IC_COMP_TYPE_reg_addr                                         "0xb80123fc"
#define IC_COMP_TYPE_reg                                              0xb80123fc
#define IC_COMP_TYPE_inst_addr                                        "0x00FF"
#define IC_COMP_TYPE_inst                                             0x00FF
#define IC_COMP_TYPE_ic_comp_type_shift                               (0)
#define IC_COMP_TYPE_ic_comp_type_mask                                (0xFFFFFFFF)
#define IC_COMP_TYPE_ic_comp_type(data)                               (0xFFFFFFFF&(data))
#define IC_COMP_TYPE_get_ic_comp_type(data)                           (0xFFFFFFFF&(data))


#define IC_CON_1                                                      0x18012a00
#define IC_CON_1_reg_addr                                             "0xb8012a00"
#define IC_CON_1_reg                                                  0xb8012a00
#define IC_CON_1_inst_addr                                            "0x0280"
#define IC_CON_1_inst                                                 0x0280
#define IC_CON_1_ic_slave_disable_shift                               (6)
#define IC_CON_1_ic_restart_en_shift                                  (5)
#define IC_CON_1_ic_10bitaddr_master_shift                            (4)
#define IC_CON_1_ic_10bitaddr_slave_shift                             (3)
#define IC_CON_1_speed_shift                                          (1)
#define IC_CON_1_master_mode_shift                                    (0)
#define IC_CON_1_ic_slave_disable_mask                                (0x00000040)
#define IC_CON_1_ic_restart_en_mask                                   (0x00000020)
#define IC_CON_1_ic_10bitaddr_master_mask                             (0x00000010)
#define IC_CON_1_ic_10bitaddr_slave_mask                              (0x00000008)
#define IC_CON_1_speed_mask                                           (0x00000006)
#define IC_CON_1_master_mode_mask                                     (0x00000001)
#define IC_CON_1_ic_slave_disable(data)                               (0x00000040&((data)<<6))
#define IC_CON_1_ic_restart_en(data)                                  (0x00000020&((data)<<5))
#define IC_CON_1_ic_10bitaddr_master(data)                            (0x00000010&((data)<<4))
#define IC_CON_1_ic_10bitaddr_slave(data)                             (0x00000008&((data)<<3))
#define IC_CON_1_speed(data)                                          (0x00000006&((data)<<1))
#define IC_CON_1_master_mode(data)                                    (0x00000001&(data))
#define IC_CON_1_get_ic_slave_disable(data)                           ((0x00000040&(data))>>6)
#define IC_CON_1_get_ic_restart_en(data)                              ((0x00000020&(data))>>5)
#define IC_CON_1_get_ic_10bitaddr_master(data)                        ((0x00000010&(data))>>4)
#define IC_CON_1_get_ic_10bitaddr_slave(data)                         ((0x00000008&(data))>>3)
#define IC_CON_1_get_speed(data)                                      ((0x00000006&(data))>>1)
#define IC_CON_1_get_master_mode(data)                                (0x00000001&(data))


#define IC_TAR_1                                                      0x18012a04
#define IC_TAR_1_reg_addr                                             "0xb8012a04"
#define IC_TAR_1_reg                                                  0xb8012a04
#define IC_TAR_1_inst_addr                                            "0x0281"
#define IC_TAR_1_inst                                                 0x0281
#define IC_TAR_1_special_shift                                        (11)
#define IC_TAR_1_gc_or_start_shift                                    (10)
#define IC_TAR_1_ic_tar_shift                                         (0)
#define IC_TAR_1_special_mask                                         (0x00000800)
#define IC_TAR_1_gc_or_start_mask                                     (0x00000400)
#define IC_TAR_1_ic_tar_mask                                          (0x000003FF)
#define IC_TAR_1_special(data)                                        (0x00000800&((data)<<11))
#define IC_TAR_1_gc_or_start(data)                                    (0x00000400&((data)<<10))
#define IC_TAR_1_ic_tar(data)                                         (0x000003FF&(data))
#define IC_TAR_1_get_special(data)                                    ((0x00000800&(data))>>11)
#define IC_TAR_1_get_gc_or_start(data)                                ((0x00000400&(data))>>10)
#define IC_TAR_1_get_ic_tar(data)                                     (0x000003FF&(data))


#define IC_SAR_1                                                      0x18012a08
#define IC_SAR_1_reg_addr                                             "0xb8012a08"
#define IC_SAR_1_reg                                                  0xb8012a08
#define IC_SAR_1_inst_addr                                            "0x0282"
#define IC_SAR_1_inst                                                 0x0282
#define IC_SAR_1_ic_sar_shift                                         (0)
#define IC_SAR_1_ic_sar_mask                                          (0x000003FF)
#define IC_SAR_1_ic_sar(data)                                         (0x000003FF&(data))
#define IC_SAR_1_get_ic_sar(data)                                     (0x000003FF&(data))


#define IC_HS_MADDR_1                                                 0x18012a0c
#define IC_HS_MADDR_1_reg_addr                                        "0xb8012a0c"
#define IC_HS_MADDR_1_reg                                             0xb8012a0c
#define IC_HS_MADDR_1_inst_addr                                       "0x0283"
#define IC_HS_MADDR_1_inst                                            0x0283
#define IC_HS_MADDR_1_ic_hs_mar_shift                                 (0)
#define IC_HS_MADDR_1_ic_hs_mar_mask                                  (0x00000007)
#define IC_HS_MADDR_1_ic_hs_mar(data)                                 (0x00000007&(data))
#define IC_HS_MADDR_1_get_ic_hs_mar(data)                             (0x00000007&(data))


#define IC_DATA_CMD_1                                                 0x18012a10
#define IC_DATA_CMD_1_reg_addr                                        "0xb8012a10"
#define IC_DATA_CMD_1_reg                                             0xb8012a10
#define IC_DATA_CMD_1_inst_addr                                       "0x0284"
#define IC_DATA_CMD_1_inst                                            0x0284
#define IC_DATA_CMD_1_cmd_shift                                       (8)
#define IC_DATA_CMD_1_dat_shift                                       (0)
#define IC_DATA_CMD_1_cmd_mask                                        (0x00000100)
#define IC_DATA_CMD_1_dat_mask                                        (0x000000FF)
#define IC_DATA_CMD_1_cmd(data)                                       (0x00000100&((data)<<8))
#define IC_DATA_CMD_1_dat(data)                                       (0x000000FF&(data))
#define IC_DATA_CMD_1_get_cmd(data)                                   ((0x00000100&(data))>>8)
#define IC_DATA_CMD_1_get_dat(data)                                   (0x000000FF&(data))


#define IC_SS_SCL_HCNT_1                                              0x18012a14
#define IC_SS_SCL_HCNT_1_reg_addr                                     "0xb8012a14"
#define IC_SS_SCL_HCNT_1_reg                                          0xb8012a14
#define IC_SS_SCL_HCNT_1_inst_addr                                    "0x0285"
#define IC_SS_SCL_HCNT_1_inst                                         0x0285
#define IC_SS_SCL_HCNT_1_ic_ss_scl_hcnt_shift                         (0)
#define IC_SS_SCL_HCNT_1_ic_ss_scl_hcnt_mask                          (0x0000FFFF)
#define IC_SS_SCL_HCNT_1_ic_ss_scl_hcnt(data)                         (0x0000FFFF&(data))
#define IC_SS_SCL_HCNT_1_get_ic_ss_scl_hcnt(data)                     (0x0000FFFF&(data))


#define IC_SS_SCL_LCNT_1                                              0x18012a18
#define IC_SS_SCL_LCNT_1_reg_addr                                     "0xb8012a18"
#define IC_SS_SCL_LCNT_1_reg                                          0xb8012a18
#define IC_SS_SCL_LCNT_1_inst_addr                                    "0x0286"
#define IC_SS_SCL_LCNT_1_inst                                         0x0286
#define IC_SS_SCL_LCNT_1_ic_ss_scl_lcnt_shift                         (0)
#define IC_SS_SCL_LCNT_1_ic_ss_scl_lcnt_mask                          (0x0000FFFF)
#define IC_SS_SCL_LCNT_1_ic_ss_scl_lcnt(data)                         (0x0000FFFF&(data))
#define IC_SS_SCL_LCNT_1_get_ic_ss_scl_lcnt(data)                     (0x0000FFFF&(data))


#define IC_FS_SCL_HCNT_1                                              0x18012a1c
#define IC_FS_SCL_HCNT_1_reg_addr                                     "0xb8012a1c"
#define IC_FS_SCL_HCNT_1_reg                                          0xb8012a1c
#define IC_FS_SCL_HCNT_1_inst_addr                                    "0x0287"
#define IC_FS_SCL_HCNT_1_inst                                         0x0287
#define IC_FS_SCL_HCNT_1_ic_fs_scl_hcnt_shift                         (0)
#define IC_FS_SCL_HCNT_1_ic_fs_scl_hcnt_mask                          (0x0000FFFF)
#define IC_FS_SCL_HCNT_1_ic_fs_scl_hcnt(data)                         (0x0000FFFF&(data))
#define IC_FS_SCL_HCNT_1_get_ic_fs_scl_hcnt(data)                     (0x0000FFFF&(data))


#define IC_FS_SCL_LCNT_1                                              0x18012a20
#define IC_FS_SCL_LCNT_1_reg_addr                                     "0xb8012a20"
#define IC_FS_SCL_LCNT_1_reg                                          0xb8012a20
#define IC_FS_SCL_LCNT_1_inst_addr                                    "0x0288"
#define IC_FS_SCL_LCNT_1_inst                                         0x0288
#define IC_FS_SCL_LCNT_1_ic_fs_scl_lcnt_shift                         (0)
#define IC_FS_SCL_LCNT_1_ic_fs_scl_lcnt_mask                          (0x0000FFFF)
#define IC_FS_SCL_LCNT_1_ic_fs_scl_lcnt(data)                         (0x0000FFFF&(data))
#define IC_FS_SCL_LCNT_1_get_ic_fs_scl_lcnt(data)                     (0x0000FFFF&(data))


#define IC_INTR_STAT_1                                                0x18012a2c
#define IC_INTR_STAT_1_reg_addr                                       "0xb8012a2c"
#define IC_INTR_STAT_1_reg                                            0xb8012a2c
#define IC_INTR_STAT_1_inst_addr                                      "0x028B"
#define IC_INTR_STAT_1_inst                                           0x028B
#define IC_INTR_STAT_1_gen_call_shift                                 (11)
#define IC_INTR_STAT_1_start_det_shift                                (10)
#define IC_INTR_STAT_1_stop_det_shift                                 (9)
#define IC_INTR_STAT_1_activity_shift                                 (8)
#define IC_INTR_STAT_1_rx_done_shift                                  (7)
#define IC_INTR_STAT_1_tx_abrt_shift                                  (6)
#define IC_INTR_STAT_1_rd_req_shift                                   (5)
#define IC_INTR_STAT_1_tx_empty_shift                                 (4)
#define IC_INTR_STAT_1_tx_over_shift                                  (3)
#define IC_INTR_STAT_1_rx_full_shift                                  (2)
#define IC_INTR_STAT_1_rx_over_shift                                  (1)
#define IC_INTR_STAT_1_rx_under_shift                                 (0)
#define IC_INTR_STAT_1_gen_call_mask                                  (0x00000800)
#define IC_INTR_STAT_1_start_det_mask                                 (0x00000400)
#define IC_INTR_STAT_1_stop_det_mask                                  (0x00000200)
#define IC_INTR_STAT_1_activity_mask                                  (0x00000100)
#define IC_INTR_STAT_1_rx_done_mask                                   (0x00000080)
#define IC_INTR_STAT_1_tx_abrt_mask                                   (0x00000040)
#define IC_INTR_STAT_1_rd_req_mask                                    (0x00000020)
#define IC_INTR_STAT_1_tx_empty_mask                                  (0x00000010)
#define IC_INTR_STAT_1_tx_over_mask                                   (0x00000008)
#define IC_INTR_STAT_1_rx_full_mask                                   (0x00000004)
#define IC_INTR_STAT_1_rx_over_mask                                   (0x00000002)
#define IC_INTR_STAT_1_rx_under_mask                                  (0x00000001)
#define IC_INTR_STAT_1_gen_call(data)                                 (0x00000800&((data)<<11))
#define IC_INTR_STAT_1_start_det(data)                                (0x00000400&((data)<<10))
#define IC_INTR_STAT_1_stop_det(data)                                 (0x00000200&((data)<<9))
#define IC_INTR_STAT_1_activity(data)                                 (0x00000100&((data)<<8))
#define IC_INTR_STAT_1_rx_done(data)                                  (0x00000080&((data)<<7))
#define IC_INTR_STAT_1_tx_abrt(data)                                  (0x00000040&((data)<<6))
#define IC_INTR_STAT_1_rd_req(data)                                   (0x00000020&((data)<<5))
#define IC_INTR_STAT_1_tx_empty(data)                                 (0x00000010&((data)<<4))
#define IC_INTR_STAT_1_tx_over(data)                                  (0x00000008&((data)<<3))
#define IC_INTR_STAT_1_rx_full(data)                                  (0x00000004&((data)<<2))
#define IC_INTR_STAT_1_rx_over(data)                                  (0x00000002&((data)<<1))
#define IC_INTR_STAT_1_rx_under(data)                                 (0x00000001&(data))
#define IC_INTR_STAT_1_get_gen_call(data)                             ((0x00000800&(data))>>11)
#define IC_INTR_STAT_1_get_start_det(data)                            ((0x00000400&(data))>>10)
#define IC_INTR_STAT_1_get_stop_det(data)                             ((0x00000200&(data))>>9)
#define IC_INTR_STAT_1_get_activity(data)                             ((0x00000100&(data))>>8)
#define IC_INTR_STAT_1_get_rx_done(data)                              ((0x00000080&(data))>>7)
#define IC_INTR_STAT_1_get_tx_abrt(data)                              ((0x00000040&(data))>>6)
#define IC_INTR_STAT_1_get_rd_req(data)                               ((0x00000020&(data))>>5)
#define IC_INTR_STAT_1_get_tx_empty(data)                             ((0x00000010&(data))>>4)
#define IC_INTR_STAT_1_get_tx_over(data)                              ((0x00000008&(data))>>3)
#define IC_INTR_STAT_1_get_rx_full(data)                              ((0x00000004&(data))>>2)
#define IC_INTR_STAT_1_get_rx_over(data)                              ((0x00000002&(data))>>1)
#define IC_INTR_STAT_1_get_rx_under(data)                             (0x00000001&(data))


#define IC_INTR_MASK_1                                                0x18012a30
#define IC_INTR_MASK_1_reg_addr                                       "0xb8012a30"
#define IC_INTR_MASK_1_reg                                            0xb8012a30
#define IC_INTR_MASK_1_inst_addr                                      "0x028C"
#define IC_INTR_MASK_1_inst                                           0x028C
#define IC_INTR_MASK_1_m_gen_call_shift                               (11)
#define IC_INTR_MASK_1_m_start_det_shift                              (10)
#define IC_INTR_MASK_1_m_stop_det_shift                               (9)
#define IC_INTR_MASK_1_m_activity_shift                               (8)
#define IC_INTR_MASK_1_m_rx_done_shift                                (7)
#define IC_INTR_MASK_1_m_tx_abrt_shift                                (6)
#define IC_INTR_MASK_1_m_rd_req_shift                                 (5)
#define IC_INTR_MASK_1_m_tx_empty_shift                               (4)
#define IC_INTR_MASK_1_m_tx_over_shift                                (3)
#define IC_INTR_MASK_1_m_rx_full_shift                                (2)
#define IC_INTR_MASK_1_m_rx_over_shift                                (1)
#define IC_INTR_MASK_1_m_rx_under_shift                               (0)
#define IC_INTR_MASK_1_m_gen_call_mask                                (0x00000800)
#define IC_INTR_MASK_1_m_start_det_mask                               (0x00000400)
#define IC_INTR_MASK_1_m_stop_det_mask                                (0x00000200)
#define IC_INTR_MASK_1_m_activity_mask                                (0x00000100)
#define IC_INTR_MASK_1_m_rx_done_mask                                 (0x00000080)
#define IC_INTR_MASK_1_m_tx_abrt_mask                                 (0x00000040)
#define IC_INTR_MASK_1_m_rd_req_mask                                  (0x00000020)
#define IC_INTR_MASK_1_m_tx_empty_mask                                (0x00000010)
#define IC_INTR_MASK_1_m_tx_over_mask                                 (0x00000008)
#define IC_INTR_MASK_1_m_rx_full_mask                                 (0x00000004)
#define IC_INTR_MASK_1_m_rx_over_mask                                 (0x00000002)
#define IC_INTR_MASK_1_m_rx_under_mask                                (0x00000001)
#define IC_INTR_MASK_1_m_gen_call(data)                               (0x00000800&((data)<<11))
#define IC_INTR_MASK_1_m_start_det(data)                              (0x00000400&((data)<<10))
#define IC_INTR_MASK_1_m_stop_det(data)                               (0x00000200&((data)<<9))
#define IC_INTR_MASK_1_m_activity(data)                               (0x00000100&((data)<<8))
#define IC_INTR_MASK_1_m_rx_done(data)                                (0x00000080&((data)<<7))
#define IC_INTR_MASK_1_m_tx_abrt(data)                                (0x00000040&((data)<<6))
#define IC_INTR_MASK_1_m_rd_req(data)                                 (0x00000020&((data)<<5))
#define IC_INTR_MASK_1_m_tx_empty(data)                               (0x00000010&((data)<<4))
#define IC_INTR_MASK_1_m_tx_over(data)                                (0x00000008&((data)<<3))
#define IC_INTR_MASK_1_m_rx_full(data)                                (0x00000004&((data)<<2))
#define IC_INTR_MASK_1_m_rx_over(data)                                (0x00000002&((data)<<1))
#define IC_INTR_MASK_1_m_rx_under(data)                               (0x00000001&(data))
#define IC_INTR_MASK_1_get_m_gen_call(data)                           ((0x00000800&(data))>>11)
#define IC_INTR_MASK_1_get_m_start_det(data)                          ((0x00000400&(data))>>10)
#define IC_INTR_MASK_1_get_m_stop_det(data)                           ((0x00000200&(data))>>9)
#define IC_INTR_MASK_1_get_m_activity(data)                           ((0x00000100&(data))>>8)
#define IC_INTR_MASK_1_get_m_rx_done(data)                            ((0x00000080&(data))>>7)
#define IC_INTR_MASK_1_get_m_tx_abrt(data)                            ((0x00000040&(data))>>6)
#define IC_INTR_MASK_1_get_m_rd_req(data)                             ((0x00000020&(data))>>5)
#define IC_INTR_MASK_1_get_m_tx_empty(data)                           ((0x00000010&(data))>>4)
#define IC_INTR_MASK_1_get_m_tx_over(data)                            ((0x00000008&(data))>>3)
#define IC_INTR_MASK_1_get_m_rx_full(data)                            ((0x00000004&(data))>>2)
#define IC_INTR_MASK_1_get_m_rx_over(data)                            ((0x00000002&(data))>>1)
#define IC_INTR_MASK_1_get_m_rx_under(data)                           (0x00000001&(data))


#define IC_RAW_INTR_STAT_1                                            0x18012a34
#define IC_RAW_INTR_STAT_1_reg_addr                                   "0xb8012a34"
#define IC_RAW_INTR_STAT_1_reg                                        0xb8012a34
#define IC_RAW_INTR_STAT_1_inst_addr                                  "0x028D"
#define IC_RAW_INTR_STAT_1_inst                                       0x028D
#define IC_RAW_INTR_STAT_1_r_gen_call_shift                           (11)
#define IC_RAW_INTR_STAT_1_r_start_det_shift                          (10)
#define IC_RAW_INTR_STAT_1_r_stop_det_shift                           (9)
#define IC_RAW_INTR_STAT_1_r_activity_shift                           (8)
#define IC_RAW_INTR_STAT_1_r_rx_done_shift                            (7)
#define IC_RAW_INTR_STAT_1_r_tx_abrt_shift                            (6)
#define IC_RAW_INTR_STAT_1_r_rd_req_shift                             (5)
#define IC_RAW_INTR_STAT_1_r_tx_empty_shift                           (4)
#define IC_RAW_INTR_STAT_1_r_tx_over_shift                            (3)
#define IC_RAW_INTR_STAT_1_r_rx_full_shift                            (2)
#define IC_RAW_INTR_STAT_1_r_rx_over_shift                            (1)
#define IC_RAW_INTR_STAT_1_r_rx_under_shift                           (0)
#define IC_RAW_INTR_STAT_1_r_gen_call_mask                            (0x00000800)
#define IC_RAW_INTR_STAT_1_r_start_det_mask                           (0x00000400)
#define IC_RAW_INTR_STAT_1_r_stop_det_mask                            (0x00000200)
#define IC_RAW_INTR_STAT_1_r_activity_mask                            (0x00000100)
#define IC_RAW_INTR_STAT_1_r_rx_done_mask                             (0x00000080)
#define IC_RAW_INTR_STAT_1_r_tx_abrt_mask                             (0x00000040)
#define IC_RAW_INTR_STAT_1_r_rd_req_mask                              (0x00000020)
#define IC_RAW_INTR_STAT_1_r_tx_empty_mask                            (0x00000010)
#define IC_RAW_INTR_STAT_1_r_tx_over_mask                             (0x00000008)
#define IC_RAW_INTR_STAT_1_r_rx_full_mask                             (0x00000004)
#define IC_RAW_INTR_STAT_1_r_rx_over_mask                             (0x00000002)
#define IC_RAW_INTR_STAT_1_r_rx_under_mask                            (0x00000001)
#define IC_RAW_INTR_STAT_1_r_gen_call(data)                           (0x00000800&((data)<<11))
#define IC_RAW_INTR_STAT_1_r_start_det(data)                          (0x00000400&((data)<<10))
#define IC_RAW_INTR_STAT_1_r_stop_det(data)                           (0x00000200&((data)<<9))
#define IC_RAW_INTR_STAT_1_r_activity(data)                           (0x00000100&((data)<<8))
#define IC_RAW_INTR_STAT_1_r_rx_done(data)                            (0x00000080&((data)<<7))
#define IC_RAW_INTR_STAT_1_r_tx_abrt(data)                            (0x00000040&((data)<<6))
#define IC_RAW_INTR_STAT_1_r_rd_req(data)                             (0x00000020&((data)<<5))
#define IC_RAW_INTR_STAT_1_r_tx_empty(data)                           (0x00000010&((data)<<4))
#define IC_RAW_INTR_STAT_1_r_tx_over(data)                            (0x00000008&((data)<<3))
#define IC_RAW_INTR_STAT_1_r_rx_full(data)                            (0x00000004&((data)<<2))
#define IC_RAW_INTR_STAT_1_r_rx_over(data)                            (0x00000002&((data)<<1))
#define IC_RAW_INTR_STAT_1_r_rx_under(data)                           (0x00000001&(data))
#define IC_RAW_INTR_STAT_1_get_r_gen_call(data)                       ((0x00000800&(data))>>11)
#define IC_RAW_INTR_STAT_1_get_r_start_det(data)                      ((0x00000400&(data))>>10)
#define IC_RAW_INTR_STAT_1_get_r_stop_det(data)                       ((0x00000200&(data))>>9)
#define IC_RAW_INTR_STAT_1_get_r_activity(data)                       ((0x00000100&(data))>>8)
#define IC_RAW_INTR_STAT_1_get_r_rx_done(data)                        ((0x00000080&(data))>>7)
#define IC_RAW_INTR_STAT_1_get_r_tx_abrt(data)                        ((0x00000040&(data))>>6)
#define IC_RAW_INTR_STAT_1_get_r_rd_req(data)                         ((0x00000020&(data))>>5)
#define IC_RAW_INTR_STAT_1_get_r_tx_empty(data)                       ((0x00000010&(data))>>4)
#define IC_RAW_INTR_STAT_1_get_r_tx_over(data)                        ((0x00000008&(data))>>3)
#define IC_RAW_INTR_STAT_1_get_r_rx_full(data)                        ((0x00000004&(data))>>2)
#define IC_RAW_INTR_STAT_1_get_r_rx_over(data)                        ((0x00000002&(data))>>1)
#define IC_RAW_INTR_STAT_1_get_r_rx_under(data)                       (0x00000001&(data))


#define IC_RX_TL_1                                                    0x18012a38
#define IC_RX_TL_1_reg_addr                                           "0xb8012a38"
#define IC_RX_TL_1_reg                                                0xb8012a38
#define IC_RX_TL_1_inst_addr                                          "0x028E"
#define IC_RX_TL_1_inst                                               0x028E
#define IC_RX_TL_1_rx_tl_shift                                        (0)
#define IC_RX_TL_1_rx_tl_mask                                         (0x000000FF)
#define IC_RX_TL_1_rx_tl(data)                                        (0x000000FF&(data))
#define IC_RX_TL_1_get_rx_tl(data)                                    (0x000000FF&(data))


#define IC_TX_TL_1                                                    0x18012a3c
#define IC_TX_TL_1_reg_addr                                           "0xb8012a3c"
#define IC_TX_TL_1_reg                                                0xb8012a3c
#define IC_TX_TL_1_inst_addr                                          "0x028F"
#define IC_TX_TL_1_inst                                               0x028F
#define IC_TX_TL_1_tx_tl_shift                                        (0)
#define IC_TX_TL_1_tx_tl_mask                                         (0x000000FF)
#define IC_TX_TL_1_tx_tl(data)                                        (0x000000FF&(data))
#define IC_TX_TL_1_get_tx_tl(data)                                    (0x000000FF&(data))


#define IC_CLR_INTR_1                                                 0x18012a40
#define IC_CLR_INTR_1_reg_addr                                        "0xb8012a40"
#define IC_CLR_INTR_1_reg                                             0xb8012a40
#define IC_CLR_INTR_1_inst_addr                                       "0x0290"
#define IC_CLR_INTR_1_inst                                            0x0290
#define IC_CLR_INTR_1_clr_intr_shift                                  (0)
#define IC_CLR_INTR_1_clr_intr_mask                                   (0x00000001)
#define IC_CLR_INTR_1_clr_intr(data)                                  (0x00000001&(data))
#define IC_CLR_INTR_1_get_clr_intr(data)                              (0x00000001&(data))


#define IC_CLR_RX_UNDER_1                                             0x18012a44
#define IC_CLR_RX_UNDER_1_reg_addr                                    "0xb8012a44"
#define IC_CLR_RX_UNDER_1_reg                                         0xb8012a44
#define IC_CLR_RX_UNDER_1_inst_addr                                   "0x0291"
#define IC_CLR_RX_UNDER_1_inst                                        0x0291
#define IC_CLR_RX_UNDER_1_clr_rx_under_shift                          (0)
#define IC_CLR_RX_UNDER_1_clr_rx_under_mask                           (0x00000001)
#define IC_CLR_RX_UNDER_1_clr_rx_under(data)                          (0x00000001&(data))
#define IC_CLR_RX_UNDER_1_get_clr_rx_under(data)                      (0x00000001&(data))


#define IC_CLR_RX_OVER_1                                              0x18012a48
#define IC_CLR_RX_OVER_1_reg_addr                                     "0xb8012a48"
#define IC_CLR_RX_OVER_1_reg                                          0xb8012a48
#define IC_CLR_RX_OVER_1_inst_addr                                    "0x0292"
#define IC_CLR_RX_OVER_1_inst                                         0x0292
#define IC_CLR_RX_OVER_1_clr_rx_over_shift                            (0)
#define IC_CLR_RX_OVER_1_clr_rx_over_mask                             (0x00000001)
#define IC_CLR_RX_OVER_1_clr_rx_over(data)                            (0x00000001&(data))
#define IC_CLR_RX_OVER_1_get_clr_rx_over(data)                        (0x00000001&(data))


#define IC_CLR_TX_OVER_1                                              0x18012a4c
#define IC_CLR_TX_OVER_1_reg_addr                                     "0xb8012a4c"
#define IC_CLR_TX_OVER_1_reg                                          0xb8012a4c
#define IC_CLR_TX_OVER_1_inst_addr                                    "0x0293"
#define IC_CLR_TX_OVER_1_inst                                         0x0293
#define IC_CLR_TX_OVER_1_clr_tx_over_shift                            (0)
#define IC_CLR_TX_OVER_1_clr_tx_over_mask                             (0x00000001)
#define IC_CLR_TX_OVER_1_clr_tx_over(data)                            (0x00000001&(data))
#define IC_CLR_TX_OVER_1_get_clr_tx_over(data)                        (0x00000001&(data))


#define IC_CLR_RD_REQ_1                                               0x18012a50
#define IC_CLR_RD_REQ_1_reg_addr                                      "0xb8012a50"
#define IC_CLR_RD_REQ_1_reg                                           0xb8012a50
#define IC_CLR_RD_REQ_1_inst_addr                                     "0x0294"
#define IC_CLR_RD_REQ_1_inst                                          0x0294
#define IC_CLR_RD_REQ_1_clr_rd_req_shift                              (0)
#define IC_CLR_RD_REQ_1_clr_rd_req_mask                               (0x00000001)
#define IC_CLR_RD_REQ_1_clr_rd_req(data)                              (0x00000001&(data))
#define IC_CLR_RD_REQ_1_get_clr_rd_req(data)                          (0x00000001&(data))


#define IC_CLR_TX_ABRT_1                                              0x18012a54
#define IC_CLR_TX_ABRT_1_reg_addr                                     "0xb8012a54"
#define IC_CLR_TX_ABRT_1_reg                                          0xb8012a54
#define IC_CLR_TX_ABRT_1_inst_addr                                    "0x0295"
#define IC_CLR_TX_ABRT_1_inst                                         0x0295
#define IC_CLR_TX_ABRT_1_clr_tx_abrt_shift                            (0)
#define IC_CLR_TX_ABRT_1_clr_tx_abrt_mask                             (0x00000001)
#define IC_CLR_TX_ABRT_1_clr_tx_abrt(data)                            (0x00000001&(data))
#define IC_CLR_TX_ABRT_1_get_clr_tx_abrt(data)                        (0x00000001&(data))


#define IC_CLR_RX_DONE_1                                              0x18012a58
#define IC_CLR_RX_DONE_1_reg_addr                                     "0xb8012a58"
#define IC_CLR_RX_DONE_1_reg                                          0xb8012a58
#define IC_CLR_RX_DONE_1_inst_addr                                    "0x0296"
#define IC_CLR_RX_DONE_1_inst                                         0x0296
#define IC_CLR_RX_DONE_1_clr_rx_done_shift                            (0)
#define IC_CLR_RX_DONE_1_clr_rx_done_mask                             (0x00000001)
#define IC_CLR_RX_DONE_1_clr_rx_done(data)                            (0x00000001&(data))
#define IC_CLR_RX_DONE_1_get_clr_rx_done(data)                        (0x00000001&(data))


#define IC_CLR_ACTIVITY_1                                             0x18012a5c
#define IC_CLR_ACTIVITY_1_reg_addr                                    "0xb8012a5c"
#define IC_CLR_ACTIVITY_1_reg                                         0xb8012a5c
#define IC_CLR_ACTIVITY_1_inst_addr                                   "0x0297"
#define IC_CLR_ACTIVITY_1_inst                                        0x0297
#define IC_CLR_ACTIVITY_1_clr_activity_shift                          (0)
#define IC_CLR_ACTIVITY_1_clr_activity_mask                           (0x00000001)
#define IC_CLR_ACTIVITY_1_clr_activity(data)                          (0x00000001&(data))
#define IC_CLR_ACTIVITY_1_get_clr_activity(data)                      (0x00000001&(data))


#define IC_CLR_STOP_DET_1                                             0x18012a60
#define IC_CLR_STOP_DET_1_reg_addr                                    "0xb8012a60"
#define IC_CLR_STOP_DET_1_reg                                         0xb8012a60
#define IC_CLR_STOP_DET_1_inst_addr                                   "0x0298"
#define IC_CLR_STOP_DET_1_inst                                        0x0298
#define IC_CLR_STOP_DET_1_clr_stop_det_shift                          (0)
#define IC_CLR_STOP_DET_1_clr_stop_det_mask                           (0x00000001)
#define IC_CLR_STOP_DET_1_clr_stop_det(data)                          (0x00000001&(data))
#define IC_CLR_STOP_DET_1_get_clr_stop_det(data)                      (0x00000001&(data))


#define IC_CLR_START_DET_1                                            0x18012a64
#define IC_CLR_START_DET_1_reg_addr                                   "0xb8012a64"
#define IC_CLR_START_DET_1_reg                                        0xb8012a64
#define IC_CLR_START_DET_1_inst_addr                                  "0x0299"
#define IC_CLR_START_DET_1_inst                                       0x0299
#define IC_CLR_START_DET_1_clr_start_det_shift                        (0)
#define IC_CLR_START_DET_1_clr_start_det_mask                         (0x00000001)
#define IC_CLR_START_DET_1_clr_start_det(data)                        (0x00000001&(data))
#define IC_CLR_START_DET_1_get_clr_start_det(data)                    (0x00000001&(data))


#define IC_CLR_GEN_CALL_1                                             0x18012a68
#define IC_CLR_GEN_CALL_1_reg_addr                                    "0xb8012a68"
#define IC_CLR_GEN_CALL_1_reg                                         0xb8012a68
#define IC_CLR_GEN_CALL_1_inst_addr                                   "0x029A"
#define IC_CLR_GEN_CALL_1_inst                                        0x029A
#define IC_CLR_GEN_CALL_1_clr_gen_call_shift                          (0)
#define IC_CLR_GEN_CALL_1_clr_gen_call_mask                           (0x00000001)
#define IC_CLR_GEN_CALL_1_clr_gen_call(data)                          (0x00000001&(data))
#define IC_CLR_GEN_CALL_1_get_clr_gen_call(data)                      (0x00000001&(data))


#define IC_ENABLE_1                                                   0x18012a6c
#define IC_ENABLE_1_reg_addr                                          "0xb8012a6c"
#define IC_ENABLE_1_reg                                               0xb8012a6c
#define IC_ENABLE_1_inst_addr                                         "0x029B"
#define IC_ENABLE_1_inst                                              0x029B
#define IC_ENABLE_1_enable_shift                                      (0)
#define IC_ENABLE_1_enable_mask                                       (0x00000001)
#define IC_ENABLE_1_enable(data)                                      (0x00000001&(data))
#define IC_ENABLE_1_get_enable(data)                                  (0x00000001&(data))


#define IC_STATUS_1                                                   0x18012a70
#define IC_STATUS_1_reg_addr                                          "0xb8012a70"
#define IC_STATUS_1_reg                                               0xb8012a70
#define IC_STATUS_1_inst_addr                                         "0x029C"
#define IC_STATUS_1_inst                                              0x029C
#define IC_STATUS_1_rff_shift                                         (4)
#define IC_STATUS_1_rfne_shift                                        (3)
#define IC_STATUS_1_tfe_shift                                         (2)
#define IC_STATUS_1_tfnf_shift                                        (1)
#define IC_STATUS_1_activity_shift                                    (0)
#define IC_STATUS_1_rff_mask                                          (0x00000010)
#define IC_STATUS_1_rfne_mask                                         (0x00000008)
#define IC_STATUS_1_tfe_mask                                          (0x00000004)
#define IC_STATUS_1_tfnf_mask                                         (0x00000002)
#define IC_STATUS_1_activity_mask                                     (0x00000001)
#define IC_STATUS_1_rff(data)                                         (0x00000010&((data)<<4))
#define IC_STATUS_1_rfne(data)                                        (0x00000008&((data)<<3))
#define IC_STATUS_1_tfe(data)                                         (0x00000004&((data)<<2))
#define IC_STATUS_1_tfnf(data)                                        (0x00000002&((data)<<1))
#define IC_STATUS_1_activity(data)                                    (0x00000001&(data))
#define IC_STATUS_1_get_rff(data)                                     ((0x00000010&(data))>>4)
#define IC_STATUS_1_get_rfne(data)                                    ((0x00000008&(data))>>3)
#define IC_STATUS_1_get_tfe(data)                                     ((0x00000004&(data))>>2)
#define IC_STATUS_1_get_tfnf(data)                                    ((0x00000002&(data))>>1)
#define IC_STATUS_1_get_activity(data)                                (0x00000001&(data))


#define IC_TXFLR_1                                                    0x18012a74
#define IC_TXFLR_1_reg_addr                                           "0xb8012a74"
#define IC_TXFLR_1_reg                                                0xb8012a74
#define IC_TXFLR_1_inst_addr                                          "0x029D"
#define IC_TXFLR_1_inst                                               0x029D
#define IC_TXFLR_1_txflr_shift                                        (0)
#define IC_TXFLR_1_txflr_mask                                         (0x0000000F)
#define IC_TXFLR_1_txflr(data)                                        (0x0000000F&(data))
#define IC_TXFLR_1_get_txflr(data)                                    (0x0000000F&(data))


#define IC_RXFLR_1                                                    0x18012a78
#define IC_RXFLR_1_reg_addr                                           "0xb8012a78"
#define IC_RXFLR_1_reg                                                0xb8012a78
#define IC_RXFLR_1_inst_addr                                          "0x029E"
#define IC_RXFLR_1_inst                                               0x029E
#define IC_RXFLR_1_rxflr_shift                                        (0)
#define IC_RXFLR_1_rxflr_mask                                         (0x0000000F)
#define IC_RXFLR_1_rxflr(data)                                        (0x0000000F&(data))
#define IC_RXFLR_1_get_rxflr(data)                                    (0x0000000F&(data))


#define IC_TX_ABRT_SOURCE_1                                           0x18012a80
#define IC_TX_ABRT_SOURCE_1_reg_addr                                  "0xb8012a80"
#define IC_TX_ABRT_SOURCE_1_reg                                       0xb8012a80
#define IC_TX_ABRT_SOURCE_1_inst_addr                                 "0x02A0"
#define IC_TX_ABRT_SOURCE_1_inst                                      0x02A0
#define IC_TX_ABRT_SOURCE_1_abrt_slvrd_intx_shift                     (15)
#define IC_TX_ABRT_SOURCE_1_abrt_slv_arblost_shift                    (14)
#define IC_TX_ABRT_SOURCE_1_abrt_slvflush_txfifo_shift                (13)
#define IC_TX_ABRT_SOURCE_1_arb_lost_shift                            (12)
#define IC_TX_ABRT_SOURCE_1_arb_master_dis_shift                      (11)
#define IC_TX_ABRT_SOURCE_1_abrt_10b_rd_norstrt_shift                 (10)
#define IC_TX_ABRT_SOURCE_1_abrt_sbyte_norstrt_shift                  (9)
#define IC_TX_ABRT_SOURCE_1_abrt_hs_norstrt_shift                     (8)
#define IC_TX_ABRT_SOURCE_1_abrt_sbyte_ackdet_shift                   (7)
#define IC_TX_ABRT_SOURCE_1_abrt_hs_ackdet_shift                      (6)
#define IC_TX_ABRT_SOURCE_1_abrt_gcall_read_shift                     (5)
#define IC_TX_ABRT_SOURCE_1_abrt_gcall_noack_shift                    (4)
#define IC_TX_ABRT_SOURCE_1_abrt_txdata_noack_shift                   (3)
#define IC_TX_ABRT_SOURCE_1_abrt_10addr2_noack_shift                  (2)
#define IC_TX_ABRT_SOURCE_1_abrt_10addr1_noack_shift                  (1)
#define IC_TX_ABRT_SOURCE_1_abrt_7b_addr_noack_shift                  (0)
#define IC_TX_ABRT_SOURCE_1_abrt_slvrd_intx_mask                      (0x00008000)
#define IC_TX_ABRT_SOURCE_1_abrt_slv_arblost_mask                     (0x00004000)
#define IC_TX_ABRT_SOURCE_1_abrt_slvflush_txfifo_mask                 (0x00002000)
#define IC_TX_ABRT_SOURCE_1_arb_lost_mask                             (0x00001000)
#define IC_TX_ABRT_SOURCE_1_arb_master_dis_mask                       (0x00000800)
#define IC_TX_ABRT_SOURCE_1_abrt_10b_rd_norstrt_mask                  (0x00000400)
#define IC_TX_ABRT_SOURCE_1_abrt_sbyte_norstrt_mask                   (0x00000200)
#define IC_TX_ABRT_SOURCE_1_abrt_hs_norstrt_mask                      (0x00000100)
#define IC_TX_ABRT_SOURCE_1_abrt_sbyte_ackdet_mask                    (0x00000080)
#define IC_TX_ABRT_SOURCE_1_abrt_hs_ackdet_mask                       (0x00000040)
#define IC_TX_ABRT_SOURCE_1_abrt_gcall_read_mask                      (0x00000020)
#define IC_TX_ABRT_SOURCE_1_abrt_gcall_noack_mask                     (0x00000010)
#define IC_TX_ABRT_SOURCE_1_abrt_txdata_noack_mask                    (0x00000008)
#define IC_TX_ABRT_SOURCE_1_abrt_10addr2_noack_mask                   (0x00000004)
#define IC_TX_ABRT_SOURCE_1_abrt_10addr1_noack_mask                   (0x00000002)
#define IC_TX_ABRT_SOURCE_1_abrt_7b_addr_noack_mask                   (0x00000001)
#define IC_TX_ABRT_SOURCE_1_abrt_slvrd_intx(data)                     (0x00008000&((data)<<15))
#define IC_TX_ABRT_SOURCE_1_abrt_slv_arblost(data)                    (0x00004000&((data)<<14))
#define IC_TX_ABRT_SOURCE_1_abrt_slvflush_txfifo(data)                (0x00002000&((data)<<13))
#define IC_TX_ABRT_SOURCE_1_arb_lost(data)                            (0x00001000&((data)<<12))
#define IC_TX_ABRT_SOURCE_1_arb_master_dis(data)                      (0x00000800&((data)<<11))
#define IC_TX_ABRT_SOURCE_1_abrt_10b_rd_norstrt(data)                 (0x00000400&((data)<<10))
#define IC_TX_ABRT_SOURCE_1_abrt_sbyte_norstrt(data)                  (0x00000200&((data)<<9))
#define IC_TX_ABRT_SOURCE_1_abrt_hs_norstrt(data)                     (0x00000100&((data)<<8))
#define IC_TX_ABRT_SOURCE_1_abrt_sbyte_ackdet(data)                   (0x00000080&((data)<<7))
#define IC_TX_ABRT_SOURCE_1_abrt_hs_ackdet(data)                      (0x00000040&((data)<<6))
#define IC_TX_ABRT_SOURCE_1_abrt_gcall_read(data)                     (0x00000020&((data)<<5))
#define IC_TX_ABRT_SOURCE_1_abrt_gcall_noack(data)                    (0x00000010&((data)<<4))
#define IC_TX_ABRT_SOURCE_1_abrt_txdata_noack(data)                   (0x00000008&((data)<<3))
#define IC_TX_ABRT_SOURCE_1_abrt_10addr2_noack(data)                  (0x00000004&((data)<<2))
#define IC_TX_ABRT_SOURCE_1_abrt_10addr1_noack(data)                  (0x00000002&((data)<<1))
#define IC_TX_ABRT_SOURCE_1_abrt_7b_addr_noack(data)                  (0x00000001&(data))
#define IC_TX_ABRT_SOURCE_1_get_abrt_slvrd_intx(data)                 ((0x00008000&(data))>>15)
#define IC_TX_ABRT_SOURCE_1_get_abrt_slv_arblost(data)                ((0x00004000&(data))>>14)
#define IC_TX_ABRT_SOURCE_1_get_abrt_slvflush_txfifo(data)            ((0x00002000&(data))>>13)
#define IC_TX_ABRT_SOURCE_1_get_arb_lost(data)                        ((0x00001000&(data))>>12)
#define IC_TX_ABRT_SOURCE_1_get_arb_master_dis(data)                  ((0x00000800&(data))>>11)
#define IC_TX_ABRT_SOURCE_1_get_abrt_10b_rd_norstrt(data)             ((0x00000400&(data))>>10)
#define IC_TX_ABRT_SOURCE_1_get_abrt_sbyte_norstrt(data)              ((0x00000200&(data))>>9)
#define IC_TX_ABRT_SOURCE_1_get_abrt_hs_norstrt(data)                 ((0x00000100&(data))>>8)
#define IC_TX_ABRT_SOURCE_1_get_abrt_sbyte_ackdet(data)               ((0x00000080&(data))>>7)
#define IC_TX_ABRT_SOURCE_1_get_abrt_hs_ackdet(data)                  ((0x00000040&(data))>>6)
#define IC_TX_ABRT_SOURCE_1_get_abrt_gcall_read(data)                 ((0x00000020&(data))>>5)
#define IC_TX_ABRT_SOURCE_1_get_abrt_gcall_noack(data)                ((0x00000010&(data))>>4)
#define IC_TX_ABRT_SOURCE_1_get_abrt_txdata_noack(data)               ((0x00000008&(data))>>3)
#define IC_TX_ABRT_SOURCE_1_get_abrt_10addr2_noack(data)              ((0x00000004&(data))>>2)
#define IC_TX_ABRT_SOURCE_1_get_abrt_10addr1_noack(data)              ((0x00000002&(data))>>1)
#define IC_TX_ABRT_SOURCE_1_get_abrt_7b_addr_noack(data)              (0x00000001&(data))


#define IC_PRE_DATA_CMD_1                                             0x18012aa0
#define IC_PRE_DATA_CMD_1_reg_addr                                    "0xb8012aa0"
#define IC_PRE_DATA_CMD_1_reg                                         0xb8012aa0
#define IC_PRE_DATA_CMD_1_inst_addr                                   "0x02A8"
#define IC_PRE_DATA_CMD_1_inst                                        0x02A8
#define IC_PRE_DATA_CMD_1_enable_shift                                (19)
#define IC_PRE_DATA_CMD_1_start_shift                                 (18)
#define IC_PRE_DATA_CMD_1_done_ie_shift                               (17)
#define IC_PRE_DATA_CMD_1_done_shift                                  (16)
#define IC_PRE_DATA_CMD_1_valid_len_shift                             (12)
#define IC_PRE_DATA_CMD_1_pre_cmd_shift                               (8)
#define IC_PRE_DATA_CMD_1_pre_data_shift                              (0)
#define IC_PRE_DATA_CMD_1_enable_mask                                 (0x00080000)
#define IC_PRE_DATA_CMD_1_start_mask                                  (0x00040000)
#define IC_PRE_DATA_CMD_1_done_ie_mask                                (0x00020000)
#define IC_PRE_DATA_CMD_1_done_mask                                   (0x00010000)
#define IC_PRE_DATA_CMD_1_valid_len_mask                              (0x0000F000)
#define IC_PRE_DATA_CMD_1_pre_cmd_mask                                (0x00000100)
#define IC_PRE_DATA_CMD_1_pre_data_mask                               (0x000000FF)
#define IC_PRE_DATA_CMD_1_enable(data)                                (0x00080000&((data)<<19))
#define IC_PRE_DATA_CMD_1_start(data)                                 (0x00040000&((data)<<18))
#define IC_PRE_DATA_CMD_1_done_ie(data)                               (0x00020000&((data)<<17))
#define IC_PRE_DATA_CMD_1_done(data)                                  (0x00010000&((data)<<16))
#define IC_PRE_DATA_CMD_1_valid_len(data)                             (0x0000F000&((data)<<12))
#define IC_PRE_DATA_CMD_1_pre_cmd(data)                               (0x00000100&((data)<<8))
#define IC_PRE_DATA_CMD_1_pre_data(data)                              (0x000000FF&(data))
#define IC_PRE_DATA_CMD_1_get_enable(data)                            ((0x00080000&(data))>>19)
#define IC_PRE_DATA_CMD_1_get_start(data)                             ((0x00040000&(data))>>18)
#define IC_PRE_DATA_CMD_1_get_done_ie(data)                           ((0x00020000&(data))>>17)
#define IC_PRE_DATA_CMD_1_get_done(data)                              ((0x00010000&(data))>>16)
#define IC_PRE_DATA_CMD_1_get_valid_len(data)                         ((0x0000F000&(data))>>12)
#define IC_PRE_DATA_CMD_1_get_pre_cmd(data)                           ((0x00000100&(data))>>8)
#define IC_PRE_DATA_CMD_1_get_pre_data(data)                          (0x000000FF&(data))


#define IC_COMP_PARAM_1                                               0x18012af4
#define IC_COMP_PARAM_1_reg_addr                                      "0xb8012af4"
#define IC_COMP_PARAM_1_reg                                           0xb8012af4
#define IC_COMP_PARAM_1_inst_addr                                     "0x02BD"
#define IC_COMP_PARAM_1_inst                                          0x02BD
#define IC_COMP_PARAM_1_tx_buffer_depth_shift                         (16)
#define IC_COMP_PARAM_1_rx_buffer_depth_shift                         (8)
#define IC_COMP_PARAM_1_add_encoded_params_shift                      (7)
#define IC_COMP_PARAM_1_has_dma_shift                                 (6)
#define IC_COMP_PARAM_1_intr_io_shift                                 (5)
#define IC_COMP_PARAM_1_hc_count_values_shift                         (4)
#define IC_COMP_PARAM_1_max_speed_mode_shift                          (2)
#define IC_COMP_PARAM_1_apb_data_width_shift                          (0)
#define IC_COMP_PARAM_1_tx_buffer_depth_mask                          (0x00FF0000)
#define IC_COMP_PARAM_1_rx_buffer_depth_mask                          (0x0000FF00)
#define IC_COMP_PARAM_1_add_encoded_params_mask                       (0x00000080)
#define IC_COMP_PARAM_1_has_dma_mask                                  (0x00000040)
#define IC_COMP_PARAM_1_intr_io_mask                                  (0x00000020)
#define IC_COMP_PARAM_1_hc_count_values_mask                          (0x00000010)
#define IC_COMP_PARAM_1_max_speed_mode_mask                           (0x0000000C)
#define IC_COMP_PARAM_1_apb_data_width_mask                           (0x00000003)
#define IC_COMP_PARAM_1_tx_buffer_depth(data)                         (0x00FF0000&((data)<<16))
#define IC_COMP_PARAM_1_rx_buffer_depth(data)                         (0x0000FF00&((data)<<8))
#define IC_COMP_PARAM_1_add_encoded_params(data)                      (0x00000080&((data)<<7))
#define IC_COMP_PARAM_1_has_dma(data)                                 (0x00000040&((data)<<6))
#define IC_COMP_PARAM_1_intr_io(data)                                 (0x00000020&((data)<<5))
#define IC_COMP_PARAM_1_hc_count_values(data)                         (0x00000010&((data)<<4))
#define IC_COMP_PARAM_1_max_speed_mode(data)                          (0x0000000C&((data)<<2))
#define IC_COMP_PARAM_1_apb_data_width(data)                          (0x00000003&(data))
#define IC_COMP_PARAM_1_get_tx_buffer_depth(data)                     ((0x00FF0000&(data))>>16)
#define IC_COMP_PARAM_1_get_rx_buffer_depth(data)                     ((0x0000FF00&(data))>>8)
#define IC_COMP_PARAM_1_get_add_encoded_params(data)                  ((0x00000080&(data))>>7)
#define IC_COMP_PARAM_1_get_has_dma(data)                             ((0x00000040&(data))>>6)
#define IC_COMP_PARAM_1_get_intr_io(data)                             ((0x00000020&(data))>>5)
#define IC_COMP_PARAM_1_get_hc_count_values(data)                     ((0x00000010&(data))>>4)
#define IC_COMP_PARAM_1_get_max_speed_mode(data)                      ((0x0000000C&(data))>>2)
#define IC_COMP_PARAM_1_get_apb_data_width(data)                      (0x00000003&(data))


#define IC_COMP_VERSION_1                                             0x18012af8
#define IC_COMP_VERSION_1_reg_addr                                    "0xb8012af8"
#define IC_COMP_VERSION_1_reg                                         0xb8012af8
#define IC_COMP_VERSION_1_inst_addr                                   "0x02BE"
#define IC_COMP_VERSION_1_inst                                        0x02BE
#define IC_COMP_VERSION_1_ic_comp_version_shift                       (0)
#define IC_COMP_VERSION_1_ic_comp_version_mask                        (0xFFFFFFFF)
#define IC_COMP_VERSION_1_ic_comp_version(data)                       (0xFFFFFFFF&(data))
#define IC_COMP_VERSION_1_get_ic_comp_version(data)                   (0xFFFFFFFF&(data))


#define IC_COMP_TYPE_1                                                0x18012afc
#define IC_COMP_TYPE_1_reg_addr                                       "0xb8012afc"
#define IC_COMP_TYPE_1_reg                                            0xb8012afc
#define IC_COMP_TYPE_1_inst_addr                                      "0x02BF"
#define IC_COMP_TYPE_1_inst                                           0x02BF
#define IC_COMP_TYPE_1_ic_comp_type_shift                             (0)
#define IC_COMP_TYPE_1_ic_comp_type_mask                              (0xFFFFFFFF)
#define IC_COMP_TYPE_1_ic_comp_type(data)                             (0xFFFFFFFF&(data))
#define IC_COMP_TYPE_1_get_ic_comp_type(data)                         (0xFFFFFFFF&(data))


#define GPIO_ACR                                                      0x18011200
#define GPIO_ACR_reg_addr                                             "0xb8011200"
#define GPIO_ACR_reg                                                  0xb8011200
#define GPIO_ACR_inst_addr                                            "0x0080"
#define GPIO_ACR_inst                                                 0x0080
#define GPIO_ACR_pdca_shift                                           (24)
#define GPIO_ACR_paip_shift                                           (8)
#define GPIO_ACR_padbe_shift                                          (0)
#define GPIO_ACR_pdca_mask                                            (0xFF000000)
#define GPIO_ACR_paip_mask                                            (0x0000FF00)
#define GPIO_ACR_padbe_mask                                           (0x000000FF)
#define GPIO_ACR_pdca(data)                                           (0xFF000000&((data)<<24))
#define GPIO_ACR_paip(data)                                           (0x0000FF00&((data)<<8))
#define GPIO_ACR_padbe(data)                                          (0x000000FF&(data))
#define GPIO_ACR_get_pdca(data)                                       ((0xFF000000&(data))>>24)
#define GPIO_ACR_get_paip(data)                                       ((0x0000FF00&(data))>>8)
#define GPIO_ACR_get_padbe(data)                                      (0x000000FF&(data))


#define GPIO_ADATA                                                    0x18011204
#define GPIO_ADATA_reg_addr                                           "0xb8011204"
#define GPIO_ADATA_reg                                                0xb8011204
#define GPIO_ADATA_inst_addr                                          "0x0081"
#define GPIO_ADATA_inst                                               0x0081
#define GPIO_ADATA_pda_in_shift                                       (24)
#define GPIO_ADATA_pda_out_shift                                      (16)
#define GPIO_ADATA_pabm_shift                                         (0)
#define GPIO_ADATA_pda_in_mask                                        (0xFF000000)
#define GPIO_ADATA_pda_out_mask                                       (0x00FF0000)
#define GPIO_ADATA_pabm_mask                                          (0x000000FF)
#define GPIO_ADATA_pda_in(data)                                       (0xFF000000&((data)<<24))
#define GPIO_ADATA_pda_out(data)                                      (0x00FF0000&((data)<<16))
#define GPIO_ADATA_pabm(data)                                         (0x000000FF&(data))
#define GPIO_ADATA_get_pda_in(data)                                   ((0xFF000000&(data))>>24)
#define GPIO_ADATA_get_pda_out(data)                                  ((0x00FF0000&(data))>>16)
#define GPIO_ADATA_get_pabm(data)                                     (0x000000FF&(data))


#define GPIO_BCR                                                      0x18011208
#define GPIO_BCR_reg_addr                                             "0xb8011208"
#define GPIO_BCR_reg                                                  0xb8011208
#define GPIO_BCR_inst_addr                                            "0x0082"
#define GPIO_BCR_inst                                                 0x0082
#define GPIO_BCR_pdcb_shift                                           (24)
#define GPIO_BCR_pbip_shift                                           (8)
#define GPIO_BCR_pbdbe_shift                                          (0)
#define GPIO_BCR_pdcb_mask                                            (0xFF000000)
#define GPIO_BCR_pbip_mask                                            (0x0000FF00)
#define GPIO_BCR_pbdbe_mask                                           (0x000000FF)
#define GPIO_BCR_pdcb(data)                                           (0xFF000000&((data)<<24))
#define GPIO_BCR_pbip(data)                                           (0x0000FF00&((data)<<8))
#define GPIO_BCR_pbdbe(data)                                          (0x000000FF&(data))
#define GPIO_BCR_get_pdcb(data)                                       ((0xFF000000&(data))>>24)
#define GPIO_BCR_get_pbip(data)                                       ((0x0000FF00&(data))>>8)
#define GPIO_BCR_get_pbdbe(data)                                      (0x000000FF&(data))


#define GPIO_BDATA                                                    0x1801120c
#define GPIO_BDATA_reg_addr                                           "0xb801120c"
#define GPIO_BDATA_reg                                                0xb801120c
#define GPIO_BDATA_inst_addr                                          "0x0083"
#define GPIO_BDATA_inst                                               0x0083
#define GPIO_BDATA_pdb_in_shift                                       (24)
#define GPIO_BDATA_pdb_out_shift                                      (16)
#define GPIO_BDATA_pbbm_shift                                         (0)
#define GPIO_BDATA_pdb_in_mask                                        (0xFF000000)
#define GPIO_BDATA_pdb_out_mask                                       (0x00FF0000)
#define GPIO_BDATA_pbbm_mask                                          (0x000000FF)
#define GPIO_BDATA_pdb_in(data)                                       (0xFF000000&((data)<<24))
#define GPIO_BDATA_pdb_out(data)                                      (0x00FF0000&((data)<<16))
#define GPIO_BDATA_pbbm(data)                                         (0x000000FF&(data))
#define GPIO_BDATA_get_pdb_in(data)                                   ((0xFF000000&(data))>>24)
#define GPIO_BDATA_get_pdb_out(data)                                  ((0x00FF0000&(data))>>16)
#define GPIO_BDATA_get_pbbm(data)                                     (0x000000FF&(data))


#define GPIO_CCR                                                      0x18011210
#define GPIO_CCR_reg_addr                                             "0xb8011210"
#define GPIO_CCR_reg                                                  0xb8011210
#define GPIO_CCR_inst_addr                                            "0x0084"
#define GPIO_CCR_inst                                                 0x0084
#define GPIO_CCR_pdcc_shift                                           (24)
#define GPIO_CCR_pcip_shift                                           (8)
#define GPIO_CCR_pcdbe_shift                                          (0)
#define GPIO_CCR_pdcc_mask                                            (0xFF000000)
#define GPIO_CCR_pcip_mask                                            (0x0000FF00)
#define GPIO_CCR_pcdbe_mask                                           (0x000000FF)
#define GPIO_CCR_pdcc(data)                                           (0xFF000000&((data)<<24))
#define GPIO_CCR_pcip(data)                                           (0x0000FF00&((data)<<8))
#define GPIO_CCR_pcdbe(data)                                          (0x000000FF&(data))
#define GPIO_CCR_get_pdcc(data)                                       ((0xFF000000&(data))>>24)
#define GPIO_CCR_get_pcip(data)                                       ((0x0000FF00&(data))>>8)
#define GPIO_CCR_get_pcdbe(data)                                      (0x000000FF&(data))


#define GPIO_CDATA                                                    0x18011214
#define GPIO_CDATA_reg_addr                                           "0xb8011214"
#define GPIO_CDATA_reg                                                0xb8011214
#define GPIO_CDATA_inst_addr                                          "0x0085"
#define GPIO_CDATA_inst                                               0x0085
#define GPIO_CDATA_pdc_in_shift                                       (24)
#define GPIO_CDATA_pdc_out_shift                                      (16)
#define GPIO_CDATA_pcbm_shift                                         (0)
#define GPIO_CDATA_pdc_in_mask                                        (0xFF000000)
#define GPIO_CDATA_pdc_out_mask                                       (0x00FF0000)
#define GPIO_CDATA_pcbm_mask                                          (0x000000FF)
#define GPIO_CDATA_pdc_in(data)                                       (0xFF000000&((data)<<24))
#define GPIO_CDATA_pdc_out(data)                                      (0x00FF0000&((data)<<16))
#define GPIO_CDATA_pcbm(data)                                         (0x000000FF&(data))
#define GPIO_CDATA_get_pdc_in(data)                                   ((0xFF000000&(data))>>24)
#define GPIO_CDATA_get_pdc_out(data)                                  ((0x00FF0000&(data))>>16)
#define GPIO_CDATA_get_pcbm(data)                                     (0x000000FF&(data))


#define GPIO_DCR                                                      0x18011218
#define GPIO_DCR_reg_addr                                             "0xb8011218"
#define GPIO_DCR_reg                                                  0xb8011218
#define GPIO_DCR_inst_addr                                            "0x0086"
#define GPIO_DCR_inst                                                 0x0086
#define GPIO_DCR_pdcd_shift                                           (24)
#define GPIO_DCR_pdip_shift                                           (8)
#define GPIO_DCR_pddbe_shift                                          (0)
#define GPIO_DCR_pdcd_mask                                            (0xFF000000)
#define GPIO_DCR_pdip_mask                                            (0x0000FF00)
#define GPIO_DCR_pddbe_mask                                           (0x000000FF)
#define GPIO_DCR_pdcd(data)                                           (0xFF000000&((data)<<24))
#define GPIO_DCR_pdip(data)                                           (0x0000FF00&((data)<<8))
#define GPIO_DCR_pddbe(data)                                          (0x000000FF&(data))
#define GPIO_DCR_get_pdcd(data)                                       ((0xFF000000&(data))>>24)
#define GPIO_DCR_get_pdip(data)                                       ((0x0000FF00&(data))>>8)
#define GPIO_DCR_get_pddbe(data)                                      (0x000000FF&(data))


#define GPIO_DDATA                                                    0x1801121c
#define GPIO_DDATA_reg_addr                                           "0xb801121c"
#define GPIO_DDATA_reg                                                0xb801121c
#define GPIO_DDATA_inst_addr                                          "0x0087"
#define GPIO_DDATA_inst                                               0x0087
#define GPIO_DDATA_pdd_in_shift                                       (24)
#define GPIO_DDATA_pdd_out_shift                                      (16)
#define GPIO_DDATA_pdbm_shift                                         (0)
#define GPIO_DDATA_pdd_in_mask                                        (0xFF000000)
#define GPIO_DDATA_pdd_out_mask                                       (0x00FF0000)
#define GPIO_DDATA_pdbm_mask                                          (0x000000FF)
#define GPIO_DDATA_pdd_in(data)                                       (0xFF000000&((data)<<24))
#define GPIO_DDATA_pdd_out(data)                                      (0x00FF0000&((data)<<16))
#define GPIO_DDATA_pdbm(data)                                         (0x000000FF&(data))
#define GPIO_DDATA_get_pdd_in(data)                                   ((0xFF000000&(data))>>24)
#define GPIO_DDATA_get_pdd_out(data)                                  ((0x00FF0000&(data))>>16)
#define GPIO_DDATA_get_pdbm(data)                                     (0x000000FF&(data))


#define GPIO_ECR                                                      0x18011220
#define GPIO_ECR_reg_addr                                             "0xb8011220"
#define GPIO_ECR_reg                                                  0xb8011220
#define GPIO_ECR_inst_addr                                            "0x0088"
#define GPIO_ECR_inst                                                 0x0088
#define GPIO_ECR_pdce_shift                                           (24)
#define GPIO_ECR_peip_shift                                           (8)
#define GPIO_ECR_pedbe_shift                                          (0)
#define GPIO_ECR_pdce_mask                                            (0xFF000000)
#define GPIO_ECR_peip_mask                                            (0x0000FF00)
#define GPIO_ECR_pedbe_mask                                           (0x000000FF)
#define GPIO_ECR_pdce(data)                                           (0xFF000000&((data)<<24))
#define GPIO_ECR_peip(data)                                           (0x0000FF00&((data)<<8))
#define GPIO_ECR_pedbe(data)                                          (0x000000FF&(data))
#define GPIO_ECR_get_pdce(data)                                       ((0xFF000000&(data))>>24)
#define GPIO_ECR_get_peip(data)                                       ((0x0000FF00&(data))>>8)
#define GPIO_ECR_get_pedbe(data)                                      (0x000000FF&(data))


#define GPIO_EDATA                                                    0x18011224
#define GPIO_EDATA_reg_addr                                           "0xb8011224"
#define GPIO_EDATA_reg                                                0xb8011224
#define GPIO_EDATA_inst_addr                                          "0x0089"
#define GPIO_EDATA_inst                                               0x0089
#define GPIO_EDATA_pde_in_shift                                       (24)
#define GPIO_EDATA_pde_out_shift                                      (16)
#define GPIO_EDATA_pebm_shift                                         (0)
#define GPIO_EDATA_pde_in_mask                                        (0xFF000000)
#define GPIO_EDATA_pde_out_mask                                       (0x00FF0000)
#define GPIO_EDATA_pebm_mask                                          (0x000000FF)
#define GPIO_EDATA_pde_in(data)                                       (0xFF000000&((data)<<24))
#define GPIO_EDATA_pde_out(data)                                      (0x00FF0000&((data)<<16))
#define GPIO_EDATA_pebm(data)                                         (0x000000FF&(data))
#define GPIO_EDATA_get_pde_in(data)                                   ((0xFF000000&(data))>>24)
#define GPIO_EDATA_get_pde_out(data)                                  ((0x00FF0000&(data))>>16)
#define GPIO_EDATA_get_pebm(data)                                     (0x000000FF&(data))


#define GPIO_ER                                                       0x18011228
#define GPIO_ER_reg_addr                                              "0xb8011228"
#define GPIO_ER_reg                                                   0xb8011228
#define GPIO_ER_inst_addr                                             "0x008A"
#define GPIO_ER_inst                                                  0x008A
#define GPIO_ER_gpidcb_shift                                          (0)
#define GPIO_ER_gpidcb_mask                                           (0x0000000F)
#define GPIO_ER_gpidcb(data)                                          (0x0000000F&(data))
#define GPIO_ER_get_gpidcb(data)                                      (0x0000000F&(data))


#define GPIO_AIMR                                                     0x1801122c
#define GPIO_AIMR_reg_addr                                            "0xb801122c"
#define GPIO_AIMR_reg                                                 0xb801122c
#define GPIO_AIMR_inst_addr                                           "0x008B"
#define GPIO_AIMR_inst                                                0x008B
#define GPIO_AIMR_pa7ie_shift                                         (14)
#define GPIO_AIMR_pa6ie_shift                                         (12)
#define GPIO_AIMR_pa5ie_shift                                         (10)
#define GPIO_AIMR_pa4ie_shift                                         (8)
#define GPIO_AIMR_pa3ie_shift                                         (6)
#define GPIO_AIMR_pa2ie_shift                                         (4)
#define GPIO_AIMR_pa1ie_shift                                         (2)
#define GPIO_AIMR_pa0ie_shift                                         (0)
#define GPIO_AIMR_pa7ie_mask                                          (0x0000C000)
#define GPIO_AIMR_pa6ie_mask                                          (0x00003000)
#define GPIO_AIMR_pa5ie_mask                                          (0x00000C00)
#define GPIO_AIMR_pa4ie_mask                                          (0x00000300)
#define GPIO_AIMR_pa3ie_mask                                          (0x000000C0)
#define GPIO_AIMR_pa2ie_mask                                          (0x00000030)
#define GPIO_AIMR_pa1ie_mask                                          (0x0000000C)
#define GPIO_AIMR_pa0ie_mask                                          (0x00000003)
#define GPIO_AIMR_pa7ie(data)                                         (0x0000C000&((data)<<14))
#define GPIO_AIMR_pa6ie(data)                                         (0x00003000&((data)<<12))
#define GPIO_AIMR_pa5ie(data)                                         (0x00000C00&((data)<<10))
#define GPIO_AIMR_pa4ie(data)                                         (0x00000300&((data)<<8))
#define GPIO_AIMR_pa3ie(data)                                         (0x000000C0&((data)<<6))
#define GPIO_AIMR_pa2ie(data)                                         (0x00000030&((data)<<4))
#define GPIO_AIMR_pa1ie(data)                                         (0x0000000C&((data)<<2))
#define GPIO_AIMR_pa0ie(data)                                         (0x00000003&(data))
#define GPIO_AIMR_get_pa7ie(data)                                     ((0x0000C000&(data))>>14)
#define GPIO_AIMR_get_pa6ie(data)                                     ((0x00003000&(data))>>12)
#define GPIO_AIMR_get_pa5ie(data)                                     ((0x00000C00&(data))>>10)
#define GPIO_AIMR_get_pa4ie(data)                                     ((0x00000300&(data))>>8)
#define GPIO_AIMR_get_pa3ie(data)                                     ((0x000000C0&(data))>>6)
#define GPIO_AIMR_get_pa2ie(data)                                     ((0x00000030&(data))>>4)
#define GPIO_AIMR_get_pa1ie(data)                                     ((0x0000000C&(data))>>2)
#define GPIO_AIMR_get_pa0ie(data)                                     (0x00000003&(data))


#define GPIO_BIMR                                                     0x18011230
#define GPIO_BIMR_reg_addr                                            "0xb8011230"
#define GPIO_BIMR_reg                                                 0xb8011230
#define GPIO_BIMR_inst_addr                                           "0x008C"
#define GPIO_BIMR_inst                                                0x008C
#define GPIO_BIMR_pb7ie_shift                                         (14)
#define GPIO_BIMR_pb6ie_shift                                         (12)
#define GPIO_BIMR_pb5ie_shift                                         (10)
#define GPIO_BIMR_pb4ie_shift                                         (8)
#define GPIO_BIMR_pb3ie_shift                                         (6)
#define GPIO_BIMR_pb2ie_shift                                         (4)
#define GPIO_BIMR_pb1ie_shift                                         (2)
#define GPIO_BIMR_pb0ie_shift                                         (0)
#define GPIO_BIMR_pb7ie_mask                                          (0x0000C000)
#define GPIO_BIMR_pb6ie_mask                                          (0x00003000)
#define GPIO_BIMR_pb5ie_mask                                          (0x00000C00)
#define GPIO_BIMR_pb4ie_mask                                          (0x00000300)
#define GPIO_BIMR_pb3ie_mask                                          (0x000000C0)
#define GPIO_BIMR_pb2ie_mask                                          (0x00000030)
#define GPIO_BIMR_pb1ie_mask                                          (0x0000000C)
#define GPIO_BIMR_pb0ie_mask                                          (0x00000003)
#define GPIO_BIMR_pb7ie(data)                                         (0x0000C000&((data)<<14))
#define GPIO_BIMR_pb6ie(data)                                         (0x00003000&((data)<<12))
#define GPIO_BIMR_pb5ie(data)                                         (0x00000C00&((data)<<10))
#define GPIO_BIMR_pb4ie(data)                                         (0x00000300&((data)<<8))
#define GPIO_BIMR_pb3ie(data)                                         (0x000000C0&((data)<<6))
#define GPIO_BIMR_pb2ie(data)                                         (0x00000030&((data)<<4))
#define GPIO_BIMR_pb1ie(data)                                         (0x0000000C&((data)<<2))
#define GPIO_BIMR_pb0ie(data)                                         (0x00000003&(data))
#define GPIO_BIMR_get_pb7ie(data)                                     ((0x0000C000&(data))>>14)
#define GPIO_BIMR_get_pb6ie(data)                                     ((0x00003000&(data))>>12)
#define GPIO_BIMR_get_pb5ie(data)                                     ((0x00000C00&(data))>>10)
#define GPIO_BIMR_get_pb4ie(data)                                     ((0x00000300&(data))>>8)
#define GPIO_BIMR_get_pb3ie(data)                                     ((0x000000C0&(data))>>6)
#define GPIO_BIMR_get_pb2ie(data)                                     ((0x00000030&(data))>>4)
#define GPIO_BIMR_get_pb1ie(data)                                     ((0x0000000C&(data))>>2)
#define GPIO_BIMR_get_pb0ie(data)                                     (0x00000003&(data))


#define GPIO_CIMR                                                     0x18011234
#define GPIO_CIMR_reg_addr                                            "0xb8011234"
#define GPIO_CIMR_reg                                                 0xb8011234
#define GPIO_CIMR_inst_addr                                           "0x008D"
#define GPIO_CIMR_inst                                                0x008D
#define GPIO_CIMR_pc7ie_shift                                         (14)
#define GPIO_CIMR_pc6ie_shift                                         (12)
#define GPIO_CIMR_pc5ie_shift                                         (10)
#define GPIO_CIMR_pc4ie_shift                                         (8)
#define GPIO_CIMR_pc3ie_shift                                         (6)
#define GPIO_CIMR_pc2ie_shift                                         (4)
#define GPIO_CIMR_pc1ie_shift                                         (2)
#define GPIO_CIMR_pc0ie_shift                                         (0)
#define GPIO_CIMR_pc7ie_mask                                          (0x0000C000)
#define GPIO_CIMR_pc6ie_mask                                          (0x00003000)
#define GPIO_CIMR_pc5ie_mask                                          (0x00000C00)
#define GPIO_CIMR_pc4ie_mask                                          (0x00000300)
#define GPIO_CIMR_pc3ie_mask                                          (0x000000C0)
#define GPIO_CIMR_pc2ie_mask                                          (0x00000030)
#define GPIO_CIMR_pc1ie_mask                                          (0x0000000C)
#define GPIO_CIMR_pc0ie_mask                                          (0x00000003)
#define GPIO_CIMR_pc7ie(data)                                         (0x0000C000&((data)<<14))
#define GPIO_CIMR_pc6ie(data)                                         (0x00003000&((data)<<12))
#define GPIO_CIMR_pc5ie(data)                                         (0x00000C00&((data)<<10))
#define GPIO_CIMR_pc4ie(data)                                         (0x00000300&((data)<<8))
#define GPIO_CIMR_pc3ie(data)                                         (0x000000C0&((data)<<6))
#define GPIO_CIMR_pc2ie(data)                                         (0x00000030&((data)<<4))
#define GPIO_CIMR_pc1ie(data)                                         (0x0000000C&((data)<<2))
#define GPIO_CIMR_pc0ie(data)                                         (0x00000003&(data))
#define GPIO_CIMR_get_pc7ie(data)                                     ((0x0000C000&(data))>>14)
#define GPIO_CIMR_get_pc6ie(data)                                     ((0x00003000&(data))>>12)
#define GPIO_CIMR_get_pc5ie(data)                                     ((0x00000C00&(data))>>10)
#define GPIO_CIMR_get_pc4ie(data)                                     ((0x00000300&(data))>>8)
#define GPIO_CIMR_get_pc3ie(data)                                     ((0x000000C0&(data))>>6)
#define GPIO_CIMR_get_pc2ie(data)                                     ((0x00000030&(data))>>4)
#define GPIO_CIMR_get_pc1ie(data)                                     ((0x0000000C&(data))>>2)
#define GPIO_CIMR_get_pc0ie(data)                                     (0x00000003&(data))


#define GPIO_DIMR                                                     0x18011238
#define GPIO_DIMR_reg_addr                                            "0xb8011238"
#define GPIO_DIMR_reg                                                 0xb8011238
#define GPIO_DIMR_inst_addr                                           "0x008E"
#define GPIO_DIMR_inst                                                0x008E
#define GPIO_DIMR_pd7ie_shift                                         (14)
#define GPIO_DIMR_pd6ie_shift                                         (12)
#define GPIO_DIMR_pd5ie_shift                                         (10)
#define GPIO_DIMR_pd4ie_shift                                         (8)
#define GPIO_DIMR_pd3ie_shift                                         (6)
#define GPIO_DIMR_pd2ie_shift                                         (4)
#define GPIO_DIMR_pd1ie_shift                                         (2)
#define GPIO_DIMR_pd0ie_shift                                         (0)
#define GPIO_DIMR_pd7ie_mask                                          (0x0000C000)
#define GPIO_DIMR_pd6ie_mask                                          (0x00003000)
#define GPIO_DIMR_pd5ie_mask                                          (0x00000C00)
#define GPIO_DIMR_pd4ie_mask                                          (0x00000300)
#define GPIO_DIMR_pd3ie_mask                                          (0x000000C0)
#define GPIO_DIMR_pd2ie_mask                                          (0x00000030)
#define GPIO_DIMR_pd1ie_mask                                          (0x0000000C)
#define GPIO_DIMR_pd0ie_mask                                          (0x00000003)
#define GPIO_DIMR_pd7ie(data)                                         (0x0000C000&((data)<<14))
#define GPIO_DIMR_pd6ie(data)                                         (0x00003000&((data)<<12))
#define GPIO_DIMR_pd5ie(data)                                         (0x00000C00&((data)<<10))
#define GPIO_DIMR_pd4ie(data)                                         (0x00000300&((data)<<8))
#define GPIO_DIMR_pd3ie(data)                                         (0x000000C0&((data)<<6))
#define GPIO_DIMR_pd2ie(data)                                         (0x00000030&((data)<<4))
#define GPIO_DIMR_pd1ie(data)                                         (0x0000000C&((data)<<2))
#define GPIO_DIMR_pd0ie(data)                                         (0x00000003&(data))
#define GPIO_DIMR_get_pd7ie(data)                                     ((0x0000C000&(data))>>14)
#define GPIO_DIMR_get_pd6ie(data)                                     ((0x00003000&(data))>>12)
#define GPIO_DIMR_get_pd5ie(data)                                     ((0x00000C00&(data))>>10)
#define GPIO_DIMR_get_pd4ie(data)                                     ((0x00000300&(data))>>8)
#define GPIO_DIMR_get_pd3ie(data)                                     ((0x000000C0&(data))>>6)
#define GPIO_DIMR_get_pd2ie(data)                                     ((0x00000030&(data))>>4)
#define GPIO_DIMR_get_pd1ie(data)                                     ((0x0000000C&(data))>>2)
#define GPIO_DIMR_get_pd0ie(data)                                     (0x00000003&(data))


#define GPIO_EIMR                                                     0x1801123c
#define GPIO_EIMR_reg_addr                                            "0xb801123c"
#define GPIO_EIMR_reg                                                 0xb801123c
#define GPIO_EIMR_inst_addr                                           "0x008F"
#define GPIO_EIMR_inst                                                0x008F
#define GPIO_EIMR_pe7ie_shift                                         (14)
#define GPIO_EIMR_pe6ie_shift                                         (12)
#define GPIO_EIMR_pe5ie_shift                                         (10)
#define GPIO_EIMR_pe4ie_shift                                         (8)
#define GPIO_EIMR_pe3ie_shift                                         (6)
#define GPIO_EIMR_pe2ie_shift                                         (4)
#define GPIO_EIMR_pe1ie_shift                                         (2)
#define GPIO_EIMR_pe0ie_shift                                         (0)
#define GPIO_EIMR_pe7ie_mask                                          (0x0000C000)
#define GPIO_EIMR_pe6ie_mask                                          (0x00003000)
#define GPIO_EIMR_pe5ie_mask                                          (0x00000C00)
#define GPIO_EIMR_pe4ie_mask                                          (0x00000300)
#define GPIO_EIMR_pe3ie_mask                                          (0x000000C0)
#define GPIO_EIMR_pe2ie_mask                                          (0x00000030)
#define GPIO_EIMR_pe1ie_mask                                          (0x0000000C)
#define GPIO_EIMR_pe0ie_mask                                          (0x00000003)
#define GPIO_EIMR_pe7ie(data)                                         (0x0000C000&((data)<<14))
#define GPIO_EIMR_pe6ie(data)                                         (0x00003000&((data)<<12))
#define GPIO_EIMR_pe5ie(data)                                         (0x00000C00&((data)<<10))
#define GPIO_EIMR_pe4ie(data)                                         (0x00000300&((data)<<8))
#define GPIO_EIMR_pe3ie(data)                                         (0x000000C0&((data)<<6))
#define GPIO_EIMR_pe2ie(data)                                         (0x00000030&((data)<<4))
#define GPIO_EIMR_pe1ie(data)                                         (0x0000000C&((data)<<2))
#define GPIO_EIMR_pe0ie(data)                                         (0x00000003&(data))
#define GPIO_EIMR_get_pe7ie(data)                                     ((0x0000C000&(data))>>14)
#define GPIO_EIMR_get_pe6ie(data)                                     ((0x00003000&(data))>>12)
#define GPIO_EIMR_get_pe5ie(data)                                     ((0x00000C00&(data))>>10)
#define GPIO_EIMR_get_pe4ie(data)                                     ((0x00000300&(data))>>8)
#define GPIO_EIMR_get_pe3ie(data)                                     ((0x000000C0&(data))>>6)
#define GPIO_EIMR_get_pe2ie(data)                                     ((0x00000030&(data))>>4)
#define GPIO_EIMR_get_pe1ie(data)                                     ((0x0000000C&(data))>>2)
#define GPIO_EIMR_get_pe0ie(data)                                     (0x00000003&(data))


#define PAS                                                           0x18011240
#define PAS_reg_addr                                                  "0xb8011240"
#define PAS_reg                                                       0xb8011240
#define PAS_inst_addr                                                 "0x0090"
#define PAS_inst                                                      0x0090
#define PAS_gpioa7_sel_shift                                          (14)
#define PAS_gpioa6_sel_shift                                          (12)
#define PAS_gpioa5_sel_shift                                          (10)
#define PAS_gpioa4_sel_shift                                          (8)
#define PAS_gpioa3_sel_shift                                          (6)
#define PAS_gpioa2_sel_shift                                          (4)
#define PAS_gpioa1_sel_shift                                          (2)
#define PAS_gpioa0_sel_shift                                          (0)
#define PAS_gpioa7_sel_mask                                           (0x0000C000)
#define PAS_gpioa6_sel_mask                                           (0x00003000)
#define PAS_gpioa5_sel_mask                                           (0x00000C00)
#define PAS_gpioa4_sel_mask                                           (0x00000300)
#define PAS_gpioa3_sel_mask                                           (0x000000C0)
#define PAS_gpioa2_sel_mask                                           (0x00000030)
#define PAS_gpioa1_sel_mask                                           (0x0000000C)
#define PAS_gpioa0_sel_mask                                           (0x00000003)
#define PAS_gpioa7_sel(data)                                          (0x0000C000&((data)<<14))
#define PAS_gpioa6_sel(data)                                          (0x00003000&((data)<<12))
#define PAS_gpioa5_sel(data)                                          (0x00000C00&((data)<<10))
#define PAS_gpioa4_sel(data)                                          (0x00000300&((data)<<8))
#define PAS_gpioa3_sel(data)                                          (0x000000C0&((data)<<6))
#define PAS_gpioa2_sel(data)                                          (0x00000030&((data)<<4))
#define PAS_gpioa1_sel(data)                                          (0x0000000C&((data)<<2))
#define PAS_gpioa0_sel(data)                                          (0x00000003&(data))
#define PAS_get_gpioa7_sel(data)                                      ((0x0000C000&(data))>>14)
#define PAS_get_gpioa6_sel(data)                                      ((0x00003000&(data))>>12)
#define PAS_get_gpioa5_sel(data)                                      ((0x00000C00&(data))>>10)
#define PAS_get_gpioa4_sel(data)                                      ((0x00000300&(data))>>8)
#define PAS_get_gpioa3_sel(data)                                      ((0x000000C0&(data))>>6)
#define PAS_get_gpioa2_sel(data)                                      ((0x00000030&(data))>>4)
#define PAS_get_gpioa1_sel(data)                                      ((0x0000000C&(data))>>2)
#define PAS_get_gpioa0_sel(data)                                      (0x00000003&(data))


#define PBS                                                           0x18011244
#define PBS_reg_addr                                                  "0xb8011244"
#define PBS_reg                                                       0xb8011244
#define PBS_inst_addr                                                 "0x0091"
#define PBS_inst                                                      0x0091
#define PBS_gpiob7_sel_shift                                          (14)
#define PBS_gpiob6_sel_shift                                          (12)
#define PBS_gpiob5_sel_shift                                          (10)
#define PBS_gpiob4_sel_shift                                          (8)
#define PBS_gpiob3_sel_shift                                          (6)
#define PBS_gpiob2_sel_shift                                          (4)
#define PBS_gpiob1_sel_shift                                          (2)
#define PBS_gpiob0_sel_shift                                          (0)
#define PBS_gpiob7_sel_mask                                           (0x0000C000)
#define PBS_gpiob6_sel_mask                                           (0x00003000)
#define PBS_gpiob5_sel_mask                                           (0x00000C00)
#define PBS_gpiob4_sel_mask                                           (0x00000300)
#define PBS_gpiob3_sel_mask                                           (0x000000C0)
#define PBS_gpiob2_sel_mask                                           (0x00000030)
#define PBS_gpiob1_sel_mask                                           (0x0000000C)
#define PBS_gpiob0_sel_mask                                           (0x00000003)
#define PBS_gpiob7_sel(data)                                          (0x0000C000&((data)<<14))
#define PBS_gpiob6_sel(data)                                          (0x00003000&((data)<<12))
#define PBS_gpiob5_sel(data)                                          (0x00000C00&((data)<<10))
#define PBS_gpiob4_sel(data)                                          (0x00000300&((data)<<8))
#define PBS_gpiob3_sel(data)                                          (0x000000C0&((data)<<6))
#define PBS_gpiob2_sel(data)                                          (0x00000030&((data)<<4))
#define PBS_gpiob1_sel(data)                                          (0x0000000C&((data)<<2))
#define PBS_gpiob0_sel(data)                                          (0x00000003&(data))
#define PBS_get_gpiob7_sel(data)                                      ((0x0000C000&(data))>>14)
#define PBS_get_gpiob6_sel(data)                                      ((0x00003000&(data))>>12)
#define PBS_get_gpiob5_sel(data)                                      ((0x00000C00&(data))>>10)
#define PBS_get_gpiob4_sel(data)                                      ((0x00000300&(data))>>8)
#define PBS_get_gpiob3_sel(data)                                      ((0x000000C0&(data))>>6)
#define PBS_get_gpiob2_sel(data)                                      ((0x00000030&(data))>>4)
#define PBS_get_gpiob1_sel(data)                                      ((0x0000000C&(data))>>2)
#define PBS_get_gpiob0_sel(data)                                      (0x00000003&(data))


#define PCS                                                           0x18011248
#define PCS_reg_addr                                                  "0xb8011248"
#define PCS_reg                                                       0xb8011248
#define PCS_inst_addr                                                 "0x0092"
#define PCS_inst                                                      0x0092
#define PCS_gpioc7_sel_shift                                          (14)
#define PCS_gpioc6_sel_shift                                          (12)
#define PCS_gpioc5_sel_shift                                          (10)
#define PCS_gpioc4_sel_shift                                          (8)
#define PCS_gpioc3_sel_shift                                          (6)
#define PCS_gpioc2_sel_shift                                          (4)
#define PCS_gpioc1_sel_shift                                          (2)
#define PCS_gpioc0_sel_shift                                          (0)
#define PCS_gpioc7_sel_mask                                           (0x0000C000)
#define PCS_gpioc6_sel_mask                                           (0x00003000)
#define PCS_gpioc5_sel_mask                                           (0x00000C00)
#define PCS_gpioc4_sel_mask                                           (0x00000300)
#define PCS_gpioc3_sel_mask                                           (0x000000C0)
#define PCS_gpioc2_sel_mask                                           (0x00000030)
#define PCS_gpioc1_sel_mask                                           (0x0000000C)
#define PCS_gpioc0_sel_mask                                           (0x00000003)
#define PCS_gpioc7_sel(data)                                          (0x0000C000&((data)<<14))
#define PCS_gpioc6_sel(data)                                          (0x00003000&((data)<<12))
#define PCS_gpioc5_sel(data)                                          (0x00000C00&((data)<<10))
#define PCS_gpioc4_sel(data)                                          (0x00000300&((data)<<8))
#define PCS_gpioc3_sel(data)                                          (0x000000C0&((data)<<6))
#define PCS_gpioc2_sel(data)                                          (0x00000030&((data)<<4))
#define PCS_gpioc1_sel(data)                                          (0x0000000C&((data)<<2))
#define PCS_gpioc0_sel(data)                                          (0x00000003&(data))
#define PCS_get_gpioc7_sel(data)                                      ((0x0000C000&(data))>>14)
#define PCS_get_gpioc6_sel(data)                                      ((0x00003000&(data))>>12)
#define PCS_get_gpioc5_sel(data)                                      ((0x00000C00&(data))>>10)
#define PCS_get_gpioc4_sel(data)                                      ((0x00000300&(data))>>8)
#define PCS_get_gpioc3_sel(data)                                      ((0x000000C0&(data))>>6)
#define PCS_get_gpioc2_sel(data)                                      ((0x00000030&(data))>>4)
#define PCS_get_gpioc1_sel(data)                                      ((0x0000000C&(data))>>2)
#define PCS_get_gpioc0_sel(data)                                      (0x00000003&(data))


#define PDS                                                           0x1801124c
#define PDS_reg_addr                                                  "0xb801124c"
#define PDS_reg                                                       0xb801124c
#define PDS_inst_addr                                                 "0x0093"
#define PDS_inst                                                      0x0093
#define PDS_gpiod7_sel_shift                                          (14)
#define PDS_gpiod6_sel_shift                                          (12)
#define PDS_gpiod5_sel_shift                                          (10)
#define PDS_gpiod4_sel_shift                                          (8)
#define PDS_gpiod3_sel_shift                                          (6)
#define PDS_gpiod2_sel_shift                                          (4)
#define PDS_gpiod1_sel_shift                                          (2)
#define PDS_gpiod0_sel_shift                                          (0)
#define PDS_gpiod7_sel_mask                                           (0x0000C000)
#define PDS_gpiod6_sel_mask                                           (0x00003000)
#define PDS_gpiod5_sel_mask                                           (0x00000C00)
#define PDS_gpiod4_sel_mask                                           (0x00000300)
#define PDS_gpiod3_sel_mask                                           (0x000000C0)
#define PDS_gpiod2_sel_mask                                           (0x00000030)
#define PDS_gpiod1_sel_mask                                           (0x0000000C)
#define PDS_gpiod0_sel_mask                                           (0x00000003)
#define PDS_gpiod7_sel(data)                                          (0x0000C000&((data)<<14))
#define PDS_gpiod6_sel(data)                                          (0x00003000&((data)<<12))
#define PDS_gpiod5_sel(data)                                          (0x00000C00&((data)<<10))
#define PDS_gpiod4_sel(data)                                          (0x00000300&((data)<<8))
#define PDS_gpiod3_sel(data)                                          (0x000000C0&((data)<<6))
#define PDS_gpiod2_sel(data)                                          (0x00000030&((data)<<4))
#define PDS_gpiod1_sel(data)                                          (0x0000000C&((data)<<2))
#define PDS_gpiod0_sel(data)                                          (0x00000003&(data))
#define PDS_get_gpiod7_sel(data)                                      ((0x0000C000&(data))>>14)
#define PDS_get_gpiod6_sel(data)                                      ((0x00003000&(data))>>12)
#define PDS_get_gpiod5_sel(data)                                      ((0x00000C00&(data))>>10)
#define PDS_get_gpiod4_sel(data)                                      ((0x00000300&(data))>>8)
#define PDS_get_gpiod3_sel(data)                                      ((0x000000C0&(data))>>6)
#define PDS_get_gpiod2_sel(data)                                      ((0x00000030&(data))>>4)
#define PDS_get_gpiod1_sel(data)                                      ((0x0000000C&(data))>>2)
#define PDS_get_gpiod0_sel(data)                                      (0x00000003&(data))


#define PES                                                           0x18011250
#define PES_reg_addr                                                  "0xb8011250"
#define PES_reg                                                       0xb8011250
#define PES_inst_addr                                                 "0x0094"
#define PES_inst                                                      0x0094
#define PES_gpioe7_sel_shift                                          (14)
#define PES_gpioe6_sel_shift                                          (12)
#define PES_gpioe5_sel_shift                                          (10)
#define PES_gpioe4_sel_shift                                          (8)
#define PES_gpioe3_sel_shift                                          (6)
#define PES_gpioe2_sel_shift                                          (4)
#define PES_gpioe1_sel_shift                                          (2)
#define PES_gpioe0_sel_shift                                          (0)
#define PES_gpioe7_sel_mask                                           (0x0000C000)
#define PES_gpioe6_sel_mask                                           (0x00003000)
#define PES_gpioe5_sel_mask                                           (0x00000C00)
#define PES_gpioe4_sel_mask                                           (0x00000300)
#define PES_gpioe3_sel_mask                                           (0x000000C0)
#define PES_gpioe2_sel_mask                                           (0x00000030)
#define PES_gpioe1_sel_mask                                           (0x0000000C)
#define PES_gpioe0_sel_mask                                           (0x00000003)
#define PES_gpioe7_sel(data)                                          (0x0000C000&((data)<<14))
#define PES_gpioe6_sel(data)                                          (0x00003000&((data)<<12))
#define PES_gpioe5_sel(data)                                          (0x00000C00&((data)<<10))
#define PES_gpioe4_sel(data)                                          (0x00000300&((data)<<8))
#define PES_gpioe3_sel(data)                                          (0x000000C0&((data)<<6))
#define PES_gpioe2_sel(data)                                          (0x00000030&((data)<<4))
#define PES_gpioe1_sel(data)                                          (0x0000000C&((data)<<2))
#define PES_gpioe0_sel(data)                                          (0x00000003&(data))
#define PES_get_gpioe7_sel(data)                                      ((0x0000C000&(data))>>14)
#define PES_get_gpioe6_sel(data)                                      ((0x00003000&(data))>>12)
#define PES_get_gpioe5_sel(data)                                      ((0x00000C00&(data))>>10)
#define PES_get_gpioe4_sel(data)                                      ((0x00000300&(data))>>8)
#define PES_get_gpioe3_sel(data)                                      ((0x000000C0&(data))>>6)
#define PES_get_gpioe2_sel(data)                                      ((0x00000030&(data))>>4)
#define PES_get_gpioe1_sel(data)                                      ((0x0000000C&(data))>>2)
#define PES_get_gpioe0_sel(data)                                      (0x00000003&(data))


#define ST_PWM0_B0                                                    0x18011254
#define ST_PWM0_B0_reg_addr                                           "0xb8011254"
#define ST_PWM0_B0_reg                                                0xb8011254
#define ST_PWM0_B0_inst_addr                                          "0x0095"
#define ST_PWM0_B0_inst                                               0x0095
#define ST_PWM0_B0_st_pw0cd0_mask_shift                               (24)
#define ST_PWM0_B0_st_pw0ocd0_mask_shift                              (16)
#define ST_PWM0_B0_st_pw0cd0_shift                                    (8)
#define ST_PWM0_B0_st_pw0ocd0_shift                                   (0)
#define ST_PWM0_B0_st_pw0cd0_mask_mask                                (0xFF000000)
#define ST_PWM0_B0_st_pw0ocd0_mask_mask                               (0x00FF0000)
#define ST_PWM0_B0_st_pw0cd0_mask                                     (0x0000FF00)
#define ST_PWM0_B0_st_pw0ocd0_mask                                    (0x000000FF)
#define ST_PWM0_B0_st_pw0cd0_mask(data)                               (0xFF000000&((data)<<24))
#define ST_PWM0_B0_st_pw0ocd0_mask(data)                              (0x00FF0000&((data)<<16))
#define ST_PWM0_B0_st_pw0cd0(data)                                    (0x0000FF00&((data)<<8))
#define ST_PWM0_B0_st_pw0ocd0(data)                                   (0x000000FF&(data))
#define ST_PWM0_B0_get_st_pw0cd0_mask(data)                           ((0xFF000000&(data))>>24)
#define ST_PWM0_B0_get_st_pw0ocd0_mask(data)                          ((0x00FF0000&(data))>>16)
#define ST_PWM0_B0_get_st_pw0cd0(data)                                ((0x0000FF00&(data))>>8)
#define ST_PWM0_B0_get_st_pw0ocd0(data)                               (0x000000FF&(data))


#define ST_PWM0_AD0                                                   0x18011258
#define ST_PWM0_AD0_reg_addr                                          "0xb8011258"
#define ST_PWM0_AD0_reg                                               0xb8011258
#define ST_PWM0_AD0_inst_addr                                         "0x0096"
#define ST_PWM0_AD0_inst                                              0x0096
#define ST_PWM0_AD0_st_pwm_enable0_shift                              (31)
#define ST_PWM0_AD0_pwm0csd_mask_shift                                (16)
#define ST_PWM0_AD0_pwm0csd_shift                                     (0)
#define ST_PWM0_AD0_st_pwm_enable0_mask                               (0x80000000)
#define ST_PWM0_AD0_pwm0csd_mask_mask                                 (0x001F0000)
#define ST_PWM0_AD0_pwm0csd_mask                                      (0x0000001F)
#define ST_PWM0_AD0_st_pwm_enable0(data)                              (0x80000000&((data)<<31))
#define ST_PWM0_AD0_pwm0csd_mask(data)                                (0x001F0000&((data)<<16))
#define ST_PWM0_AD0_pwm0csd(data)                                     (0x0000001F&(data))
#define ST_PWM0_AD0_get_st_pwm_enable0(data)                          ((0x80000000&(data))>>31)
#define ST_PWM0_AD0_get_pwm0csd_mask(data)                            ((0x001F0000&(data))>>16)
#define ST_PWM0_AD0_get_pwm0csd(data)                                 (0x0000001F&(data))


#define ST_PWM0_B1                                                    0x1801125c
#define ST_PWM0_B1_reg_addr                                           "0xb801125c"
#define ST_PWM0_B1_reg                                                0xb801125c
#define ST_PWM0_B1_inst_addr                                          "0x0097"
#define ST_PWM0_B1_inst                                               0x0097
#define ST_PWM0_B1_st_pw1cd1_mask_shift                               (24)
#define ST_PWM0_B1_st_pw1ocd1_mask_shift                              (16)
#define ST_PWM0_B1_st_pw1cd1_shift                                    (8)
#define ST_PWM0_B1_st_pw1ocd1_shift                                   (0)
#define ST_PWM0_B1_st_pw1cd1_mask_mask                                (0xFF000000)
#define ST_PWM0_B1_st_pw1ocd1_mask_mask                               (0x00FF0000)
#define ST_PWM0_B1_st_pw1cd1_mask                                     (0x0000FF00)
#define ST_PWM0_B1_st_pw1ocd1_mask                                    (0x000000FF)
#define ST_PWM0_B1_st_pw1cd1_mask(data)                               (0xFF000000&((data)<<24))
#define ST_PWM0_B1_st_pw1ocd1_mask(data)                              (0x00FF0000&((data)<<16))
#define ST_PWM0_B1_st_pw1cd1(data)                                    (0x0000FF00&((data)<<8))
#define ST_PWM0_B1_st_pw1ocd1(data)                                   (0x000000FF&(data))
#define ST_PWM0_B1_get_st_pw1cd1_mask(data)                           ((0xFF000000&(data))>>24)
#define ST_PWM0_B1_get_st_pw1ocd1_mask(data)                          ((0x00FF0000&(data))>>16)
#define ST_PWM0_B1_get_st_pw1cd1(data)                                ((0x0000FF00&(data))>>8)
#define ST_PWM0_B1_get_st_pw1ocd1(data)                               (0x000000FF&(data))


#define ST_PWM0_AD1                                                   0x18011260
#define ST_PWM0_AD1_reg_addr                                          "0xb8011260"
#define ST_PWM0_AD1_reg                                               0xb8011260
#define ST_PWM0_AD1_inst_addr                                         "0x0098"
#define ST_PWM0_AD1_inst                                              0x0098
#define ST_PWM0_AD1_st_pwm_enable1_shift                              (31)
#define ST_PWM0_AD1_pwm1csd_mask_shift                                (16)
#define ST_PWM0_AD1_pwm1csd_shift                                     (0)
#define ST_PWM0_AD1_st_pwm_enable1_mask                               (0x80000000)
#define ST_PWM0_AD1_pwm1csd_mask_mask                                 (0x001F0000)
#define ST_PWM0_AD1_pwm1csd_mask                                      (0x0000001F)
#define ST_PWM0_AD1_st_pwm_enable1(data)                              (0x80000000&((data)<<31))
#define ST_PWM0_AD1_pwm1csd_mask(data)                                (0x001F0000&((data)<<16))
#define ST_PWM0_AD1_pwm1csd(data)                                     (0x0000001F&(data))
#define ST_PWM0_AD1_get_st_pwm_enable1(data)                          ((0x80000000&(data))>>31)
#define ST_PWM0_AD1_get_pwm1csd_mask(data)                            ((0x001F0000&(data))>>16)
#define ST_PWM0_AD1_get_pwm1csd(data)                                 (0x0000001F&(data))


#define ST_UART1_RBR                                                  0x18011300
#define ST_UART1_RBR_reg_addr                                         "0xb8011300"
#define ST_UART1_RBR_reg                                              0xb8011300
#define ST_UART1_RBR_inst_addr                                        "0x00C0"
#define ST_UART1_RBR_inst                                             0x00C0
#define ST_UART1_RBR_rbd_shift                                        (0)
#define ST_UART1_RBR_rbd_mask                                         (0x000000FF)
#define ST_UART1_RBR_rbd(data)                                        (0x000000FF&(data))
#define ST_UART1_RBR_get_rbd(data)                                    (0x000000FF&(data))


#define ST_UART1_THR                                                  0x18011300
#define ST_UART1_THR_reg_addr                                         "0xb8011300"
#define ST_UART1_THR_reg                                              0xb8011300
#define ST_UART1_THR_inst_addr                                        "0x00C0"
#define ST_UART1_THR_inst                                             0x00C0
#define ST_UART1_THR_thd_shift                                        (0)
#define ST_UART1_THR_thd_mask                                         (0x000000FF)
#define ST_UART1_THR_thd(data)                                        (0x000000FF&(data))
#define ST_UART1_THR_get_thd(data)                                    (0x000000FF&(data))


#define ST_UART1_DLL                                                  0x18011300
#define ST_UART1_DLL_reg_addr                                         "0xb8011300"
#define ST_UART1_DLL_reg                                              0xb8011300
#define ST_UART1_DLL_inst_addr                                        "0x00C0"
#define ST_UART1_DLL_inst                                             0x00C0
#define ST_UART1_DLL_dll_shift                                        (0)
#define ST_UART1_DLL_dll_mask                                         (0x000000FF)
#define ST_UART1_DLL_dll(data)                                        (0x000000FF&(data))
#define ST_UART1_DLL_get_dll(data)                                    (0x000000FF&(data))


#define ST_UART1_DLM                                                  0x18011304
#define ST_UART1_DLM_reg_addr                                         "0xb8011304"
#define ST_UART1_DLM_reg                                              0xb8011304
#define ST_UART1_DLM_inst_addr                                        "0x00C1"
#define ST_UART1_DLM_inst                                             0x00C1
#define ST_UART1_DLM_dlm_shift                                        (0)
#define ST_UART1_DLM_dlm_mask                                         (0x000000FF)
#define ST_UART1_DLM_dlm(data)                                        (0x000000FF&(data))
#define ST_UART1_DLM_get_dlm(data)                                    (0x000000FF&(data))


#define ST_UART1_IER                                                  0x18011304
#define ST_UART1_IER_reg_addr                                         "0xb8011304"
#define ST_UART1_IER_reg                                              0xb8011304
#define ST_UART1_IER_inst_addr                                        "0x00C1"
#define ST_UART1_IER_inst                                             0x00C1
#define ST_UART1_IER_edssi_shift                                      (3)
#define ST_UART1_IER_elsi_shift                                       (2)
#define ST_UART1_IER_etbei_shift                                      (1)
#define ST_UART1_IER_erbi_shift                                       (0)
#define ST_UART1_IER_edssi_mask                                       (0x00000008)
#define ST_UART1_IER_elsi_mask                                        (0x00000004)
#define ST_UART1_IER_etbei_mask                                       (0x00000002)
#define ST_UART1_IER_erbi_mask                                        (0x00000001)
#define ST_UART1_IER_edssi(data)                                      (0x00000008&((data)<<3))
#define ST_UART1_IER_elsi(data)                                       (0x00000004&((data)<<2))
#define ST_UART1_IER_etbei(data)                                      (0x00000002&((data)<<1))
#define ST_UART1_IER_erbi(data)                                       (0x00000001&(data))
#define ST_UART1_IER_get_edssi(data)                                  ((0x00000008&(data))>>3)
#define ST_UART1_IER_get_elsi(data)                                   ((0x00000004&(data))>>2)
#define ST_UART1_IER_get_etbei(data)                                  ((0x00000002&(data))>>1)
#define ST_UART1_IER_get_erbi(data)                                   (0x00000001&(data))


#define ST_UART1_IIR                                                  0x18011308
#define ST_UART1_IIR_reg_addr                                         "0xb8011308"
#define ST_UART1_IIR_reg                                              0xb8011308
#define ST_UART1_IIR_inst_addr                                        "0x00C2"
#define ST_UART1_IIR_inst                                             0x00C2
#define ST_UART1_IIR_fifo16_shift                                     (6)
#define ST_UART1_IIR_iid_shift                                        (1)
#define ST_UART1_IIR_ipnd_shift                                       (0)
#define ST_UART1_IIR_fifo16_mask                                      (0x000000C0)
#define ST_UART1_IIR_iid_mask                                         (0x0000000E)
#define ST_UART1_IIR_ipnd_mask                                        (0x00000001)
#define ST_UART1_IIR_fifo16(data)                                     (0x000000C0&((data)<<6))
#define ST_UART1_IIR_iid(data)                                        (0x0000000E&((data)<<1))
#define ST_UART1_IIR_ipnd(data)                                       (0x00000001&(data))
#define ST_UART1_IIR_get_fifo16(data)                                 ((0x000000C0&(data))>>6)
#define ST_UART1_IIR_get_iid(data)                                    ((0x0000000E&(data))>>1)
#define ST_UART1_IIR_get_ipnd(data)                                   (0x00000001&(data))


#define ST_UART1_FCR                                                  0x18011308
#define ST_UART1_FCR_reg_addr                                         "0xb8011308"
#define ST_UART1_FCR_reg                                              0xb8011308
#define ST_UART1_FCR_inst_addr                                        "0x00C2"
#define ST_UART1_FCR_inst                                             0x00C2
#define ST_UART1_FCR_rtrg_shift                                       (6)
#define ST_UART1_FCR_dmam_shift                                       (3)
#define ST_UART1_FCR_tfrst_shift                                      (2)
#define ST_UART1_FCR_rfrst_shift                                      (1)
#define ST_UART1_FCR_efifo_shift                                      (0)
#define ST_UART1_FCR_rtrg_mask                                        (0x000000C0)
#define ST_UART1_FCR_dmam_mask                                        (0x00000008)
#define ST_UART1_FCR_tfrst_mask                                       (0x00000004)
#define ST_UART1_FCR_rfrst_mask                                       (0x00000002)
#define ST_UART1_FCR_efifo_mask                                       (0x00000001)
#define ST_UART1_FCR_rtrg(data)                                       (0x000000C0&((data)<<6))
#define ST_UART1_FCR_dmam(data)                                       (0x00000008&((data)<<3))
#define ST_UART1_FCR_tfrst(data)                                      (0x00000004&((data)<<2))
#define ST_UART1_FCR_rfrst(data)                                      (0x00000002&((data)<<1))
#define ST_UART1_FCR_efifo(data)                                      (0x00000001&(data))
#define ST_UART1_FCR_get_rtrg(data)                                   ((0x000000C0&(data))>>6)
#define ST_UART1_FCR_get_dmam(data)                                   ((0x00000008&(data))>>3)
#define ST_UART1_FCR_get_tfrst(data)                                  ((0x00000004&(data))>>2)
#define ST_UART1_FCR_get_rfrst(data)                                  ((0x00000002&(data))>>1)
#define ST_UART1_FCR_get_efifo(data)                                  (0x00000001&(data))


#define ST_UART1_LCR                                                  0x1801130c
#define ST_UART1_LCR_reg_addr                                         "0xb801130c"
#define ST_UART1_LCR_reg                                              0xb801130c
#define ST_UART1_LCR_inst_addr                                        "0x00C3"
#define ST_UART1_LCR_inst                                             0x00C3
#define ST_UART1_LCR_dlab_shift                                       (7)
#define ST_UART1_LCR_brk_shift                                        (6)
#define ST_UART1_LCR_eps_shift                                        (4)
#define ST_UART1_LCR_pen_shift                                        (3)
#define ST_UART1_LCR_stp_shift                                        (2)
#define ST_UART1_LCR_wls_shift                                        (0)
#define ST_UART1_LCR_dlab_mask                                        (0x00000080)
#define ST_UART1_LCR_brk_mask                                         (0x00000040)
#define ST_UART1_LCR_eps_mask                                         (0x00000030)
#define ST_UART1_LCR_pen_mask                                         (0x00000008)
#define ST_UART1_LCR_stp_mask                                         (0x00000004)
#define ST_UART1_LCR_wls_mask                                         (0x00000003)
#define ST_UART1_LCR_dlab(data)                                       (0x00000080&((data)<<7))
#define ST_UART1_LCR_brk(data)                                        (0x00000040&((data)<<6))
#define ST_UART1_LCR_eps(data)                                        (0x00000030&((data)<<4))
#define ST_UART1_LCR_pen(data)                                        (0x00000008&((data)<<3))
#define ST_UART1_LCR_stp(data)                                        (0x00000004&((data)<<2))
#define ST_UART1_LCR_wls(data)                                        (0x00000003&(data))
#define ST_UART1_LCR_get_dlab(data)                                   ((0x00000080&(data))>>7)
#define ST_UART1_LCR_get_brk(data)                                    ((0x00000040&(data))>>6)
#define ST_UART1_LCR_get_eps(data)                                    ((0x00000030&(data))>>4)
#define ST_UART1_LCR_get_pen(data)                                    ((0x00000008&(data))>>3)
#define ST_UART1_LCR_get_stp(data)                                    ((0x00000004&(data))>>2)
#define ST_UART1_LCR_get_wls(data)                                    (0x00000003&(data))


#define ST_UART1_MCR                                                  0x18011310
#define ST_UART1_MCR_reg_addr                                         "0xb8011310"
#define ST_UART1_MCR_reg                                              0xb8011310
#define ST_UART1_MCR_inst_addr                                        "0x00C4"
#define ST_UART1_MCR_inst                                             0x00C4
#define ST_UART1_MCR_loop_shift                                       (4)
#define ST_UART1_MCR_rts_shift                                        (1)
#define ST_UART1_MCR_dtr_shift                                        (0)
#define ST_UART1_MCR_loop_mask                                        (0x00000010)
#define ST_UART1_MCR_rts_mask                                         (0x00000002)
#define ST_UART1_MCR_dtr_mask                                         (0x00000001)
#define ST_UART1_MCR_loop(data)                                       (0x00000010&((data)<<4))
#define ST_UART1_MCR_rts(data)                                        (0x00000002&((data)<<1))
#define ST_UART1_MCR_dtr(data)                                        (0x00000001&(data))
#define ST_UART1_MCR_get_loop(data)                                   ((0x00000010&(data))>>4)
#define ST_UART1_MCR_get_rts(data)                                    ((0x00000002&(data))>>1)
#define ST_UART1_MCR_get_dtr(data)                                    (0x00000001&(data))


#define ST_UART1_LSR                                                  0x18011314
#define ST_UART1_LSR_reg_addr                                         "0xb8011314"
#define ST_UART1_LSR_reg                                              0xb8011314
#define ST_UART1_LSR_inst_addr                                        "0x00C5"
#define ST_UART1_LSR_inst                                             0x00C5
#define ST_UART1_LSR_rfe_shift                                        (7)
#define ST_UART1_LSR_temt_shift                                       (6)
#define ST_UART1_LSR_thre_shift                                       (5)
#define ST_UART1_LSR_bi_shift                                         (4)
#define ST_UART1_LSR_fe_shift                                         (3)
#define ST_UART1_LSR_pe_shift                                         (2)
#define ST_UART1_LSR_oe_shift                                         (1)
#define ST_UART1_LSR_dr_shift                                         (0)
#define ST_UART1_LSR_rfe_mask                                         (0x00000080)
#define ST_UART1_LSR_temt_mask                                        (0x00000040)
#define ST_UART1_LSR_thre_mask                                        (0x00000020)
#define ST_UART1_LSR_bi_mask                                          (0x00000010)
#define ST_UART1_LSR_fe_mask                                          (0x00000008)
#define ST_UART1_LSR_pe_mask                                          (0x00000004)
#define ST_UART1_LSR_oe_mask                                          (0x00000002)
#define ST_UART1_LSR_dr_mask                                          (0x00000001)
#define ST_UART1_LSR_rfe(data)                                        (0x00000080&((data)<<7))
#define ST_UART1_LSR_temt(data)                                       (0x00000040&((data)<<6))
#define ST_UART1_LSR_thre(data)                                       (0x00000020&((data)<<5))
#define ST_UART1_LSR_bi(data)                                         (0x00000010&((data)<<4))
#define ST_UART1_LSR_fe(data)                                         (0x00000008&((data)<<3))
#define ST_UART1_LSR_pe(data)                                         (0x00000004&((data)<<2))
#define ST_UART1_LSR_oe(data)                                         (0x00000002&((data)<<1))
#define ST_UART1_LSR_dr(data)                                         (0x00000001&(data))
#define ST_UART1_LSR_get_rfe(data)                                    ((0x00000080&(data))>>7)
#define ST_UART1_LSR_get_temt(data)                                   ((0x00000040&(data))>>6)
#define ST_UART1_LSR_get_thre(data)                                   ((0x00000020&(data))>>5)
#define ST_UART1_LSR_get_bi(data)                                     ((0x00000010&(data))>>4)
#define ST_UART1_LSR_get_fe(data)                                     ((0x00000008&(data))>>3)
#define ST_UART1_LSR_get_pe(data)                                     ((0x00000004&(data))>>2)
#define ST_UART1_LSR_get_oe(data)                                     ((0x00000002&(data))>>1)
#define ST_UART1_LSR_get_dr(data)                                     (0x00000001&(data))


#define UART1_MSR                                                     0x18011318
#define UART1_MSR_reg_addr                                            "0xb8011318"
#define UART1_MSR_reg                                                 0xb8011318
#define UART1_MSR_inst_addr                                           "0x00C6"
#define UART1_MSR_inst                                                0x00C6
#define UART1_MSR_dcd_shift                                           (7)
#define UART1_MSR_ri_shift                                            (6)
#define UART1_MSR_dsr_shift                                           (5)
#define UART1_MSR_cts_shift                                           (4)
#define UART1_MSR_dcts_shift                                          (0)
#define UART1_MSR_dcd_mask                                            (0x00000080)
#define UART1_MSR_ri_mask                                             (0x00000040)
#define UART1_MSR_dsr_mask                                            (0x00000020)
#define UART1_MSR_cts_mask                                            (0x00000010)
#define UART1_MSR_dcts_mask                                           (0x00000001)
#define UART1_MSR_dcd(data)                                           (0x00000080&((data)<<7))
#define UART1_MSR_ri(data)                                            (0x00000040&((data)<<6))
#define UART1_MSR_dsr(data)                                           (0x00000020&((data)<<5))
#define UART1_MSR_cts(data)                                           (0x00000010&((data)<<4))
#define UART1_MSR_dcts(data)                                          (0x00000001&(data))
#define UART1_MSR_get_dcd(data)                                       ((0x00000080&(data))>>7)
#define UART1_MSR_get_ri(data)                                        ((0x00000040&(data))>>6)
#define UART1_MSR_get_dsr(data)                                       ((0x00000020&(data))>>5)
#define UART1_MSR_get_cts(data)                                       ((0x00000010&(data))>>4)
#define UART1_MSR_get_dcts(data)                                      (0x00000001&(data))


#define ST_UART1_SCR                                                  0x1801131c
#define ST_UART1_SCR_reg_addr                                         "0xb801131c"
#define ST_UART1_SCR_reg                                              0xb801131c
#define ST_UART1_SCR_inst_addr                                        "0x00C7"
#define ST_UART1_SCR_inst                                             0x00C7
#define ST_UART1_SCR_scr_shift                                        (0)
#define ST_UART1_SCR_scr_mask                                         (0x000000FF)
#define ST_UART1_SCR_scr(data)                                        (0x000000FF&(data))
#define ST_UART1_SCR_get_scr(data)                                    (0x000000FF&(data))


#define ST_UART2_RBR                                                  0x18011320
#define ST_UART2_RBR_reg_addr                                         "0xb8011320"
#define ST_UART2_RBR_reg                                              0xb8011320
#define ST_UART2_RBR_inst_addr                                        "0x00C8"
#define ST_UART2_RBR_inst                                             0x00C8
#define ST_UART2_RBR_rbd_shift                                        (0)
#define ST_UART2_RBR_rbd_mask                                         (0x000000FF)
#define ST_UART2_RBR_rbd(data)                                        (0x000000FF&(data))
#define ST_UART2_RBR_get_rbd(data)                                    (0x000000FF&(data))


#define ST_UART2_THR                                                  0x18011320
#define ST_UART2_THR_reg_addr                                         "0xb8011320"
#define ST_UART2_THR_reg                                              0xb8011320
#define ST_UART2_THR_inst_addr                                        "0x00C8"
#define ST_UART2_THR_inst                                             0x00C8
#define ST_UART2_THR_thd_shift                                        (0)
#define ST_UART2_THR_thd_mask                                         (0x000000FF)
#define ST_UART2_THR_thd(data)                                        (0x000000FF&(data))
#define ST_UART2_THR_get_thd(data)                                    (0x000000FF&(data))


#define ST_UART2_DLL                                                  0x18011320
#define ST_UART2_DLL_reg_addr                                         "0xb8011320"
#define ST_UART2_DLL_reg                                              0xb8011320
#define ST_UART2_DLL_inst_addr                                        "0x00C8"
#define ST_UART2_DLL_inst                                             0x00C8
#define ST_UART2_DLL_dll_shift                                        (0)
#define ST_UART2_DLL_dll_mask                                         (0x000000FF)
#define ST_UART2_DLL_dll(data)                                        (0x000000FF&(data))
#define ST_UART2_DLL_get_dll(data)                                    (0x000000FF&(data))


#define ST_UART2_DLM                                                  0x18011324
#define ST_UART2_DLM_reg_addr                                         "0xb8011324"
#define ST_UART2_DLM_reg                                              0xb8011324
#define ST_UART2_DLM_inst_addr                                        "0x00C9"
#define ST_UART2_DLM_inst                                             0x00C9
#define ST_UART2_DLM_dlm_shift                                        (0)
#define ST_UART2_DLM_dlm_mask                                         (0x000000FF)
#define ST_UART2_DLM_dlm(data)                                        (0x000000FF&(data))
#define ST_UART2_DLM_get_dlm(data)                                    (0x000000FF&(data))


#define ST_UART2_IER                                                  0x18011324
#define ST_UART2_IER_reg_addr                                         "0xb8011324"
#define ST_UART2_IER_reg                                              0xb8011324
#define ST_UART2_IER_inst_addr                                        "0x00C9"
#define ST_UART2_IER_inst                                             0x00C9
#define ST_UART2_IER_edssi_shift                                      (3)
#define ST_UART2_IER_elsi_shift                                       (2)
#define ST_UART2_IER_etbei_shift                                      (1)
#define ST_UART2_IER_erbi_shift                                       (0)
#define ST_UART2_IER_edssi_mask                                       (0x00000008)
#define ST_UART2_IER_elsi_mask                                        (0x00000004)
#define ST_UART2_IER_etbei_mask                                       (0x00000002)
#define ST_UART2_IER_erbi_mask                                        (0x00000001)
#define ST_UART2_IER_edssi(data)                                      (0x00000008&((data)<<3))
#define ST_UART2_IER_elsi(data)                                       (0x00000004&((data)<<2))
#define ST_UART2_IER_etbei(data)                                      (0x00000002&((data)<<1))
#define ST_UART2_IER_erbi(data)                                       (0x00000001&(data))
#define ST_UART2_IER_get_edssi(data)                                  ((0x00000008&(data))>>3)
#define ST_UART2_IER_get_elsi(data)                                   ((0x00000004&(data))>>2)
#define ST_UART2_IER_get_etbei(data)                                  ((0x00000002&(data))>>1)
#define ST_UART2_IER_get_erbi(data)                                   (0x00000001&(data))


#define ST_UART2_IIR                                                  0x18011328
#define ST_UART2_IIR_reg_addr                                         "0xb8011328"
#define ST_UART2_IIR_reg                                              0xb8011328
#define ST_UART2_IIR_inst_addr                                        "0x00CA"
#define ST_UART2_IIR_inst                                             0x00CA
#define ST_UART2_IIR_fifo16_shift                                     (6)
#define ST_UART2_IIR_iid_shift                                        (1)
#define ST_UART2_IIR_ipnd_shift                                       (0)
#define ST_UART2_IIR_fifo16_mask                                      (0x000000C0)
#define ST_UART2_IIR_iid_mask                                         (0x0000000E)
#define ST_UART2_IIR_ipnd_mask                                        (0x00000001)
#define ST_UART2_IIR_fifo16(data)                                     (0x000000C0&((data)<<6))
#define ST_UART2_IIR_iid(data)                                        (0x0000000E&((data)<<1))
#define ST_UART2_IIR_ipnd(data)                                       (0x00000001&(data))
#define ST_UART2_IIR_get_fifo16(data)                                 ((0x000000C0&(data))>>6)
#define ST_UART2_IIR_get_iid(data)                                    ((0x0000000E&(data))>>1)
#define ST_UART2_IIR_get_ipnd(data)                                   (0x00000001&(data))


#define ST_UART2_FCR                                                  0x18011328
#define ST_UART2_FCR_reg_addr                                         "0xb8011328"
#define ST_UART2_FCR_reg                                              0xb8011328
#define ST_UART2_FCR_inst_addr                                        "0x00CA"
#define ST_UART2_FCR_inst                                             0x00CA
#define ST_UART2_FCR_rtrg_shift                                       (6)
#define ST_UART2_FCR_dmam_shift                                       (3)
#define ST_UART2_FCR_tfrst_shift                                      (2)
#define ST_UART2_FCR_rfrst_shift                                      (1)
#define ST_UART2_FCR_efifo_shift                                      (0)
#define ST_UART2_FCR_rtrg_mask                                        (0x000000C0)
#define ST_UART2_FCR_dmam_mask                                        (0x00000008)
#define ST_UART2_FCR_tfrst_mask                                       (0x00000004)
#define ST_UART2_FCR_rfrst_mask                                       (0x00000002)
#define ST_UART2_FCR_efifo_mask                                       (0x00000001)
#define ST_UART2_FCR_rtrg(data)                                       (0x000000C0&((data)<<6))
#define ST_UART2_FCR_dmam(data)                                       (0x00000008&((data)<<3))
#define ST_UART2_FCR_tfrst(data)                                      (0x00000004&((data)<<2))
#define ST_UART2_FCR_rfrst(data)                                      (0x00000002&((data)<<1))
#define ST_UART2_FCR_efifo(data)                                      (0x00000001&(data))
#define ST_UART2_FCR_get_rtrg(data)                                   ((0x000000C0&(data))>>6)
#define ST_UART2_FCR_get_dmam(data)                                   ((0x00000008&(data))>>3)
#define ST_UART2_FCR_get_tfrst(data)                                  ((0x00000004&(data))>>2)
#define ST_UART2_FCR_get_rfrst(data)                                  ((0x00000002&(data))>>1)
#define ST_UART2_FCR_get_efifo(data)                                  (0x00000001&(data))


#define ST_UART2_LCR                                                  0x1801132c
#define ST_UART2_LCR_reg_addr                                         "0xb801132c"
#define ST_UART2_LCR_reg                                              0xb801132c
#define ST_UART2_LCR_inst_addr                                        "0x00CB"
#define ST_UART2_LCR_inst                                             0x00CB
#define ST_UART2_LCR_dlab_shift                                       (7)
#define ST_UART2_LCR_brk_shift                                        (6)
#define ST_UART2_LCR_eps_shift                                        (4)
#define ST_UART2_LCR_pen_shift                                        (3)
#define ST_UART2_LCR_stp_shift                                        (2)
#define ST_UART2_LCR_wls_shift                                        (0)
#define ST_UART2_LCR_dlab_mask                                        (0x00000080)
#define ST_UART2_LCR_brk_mask                                         (0x00000040)
#define ST_UART2_LCR_eps_mask                                         (0x00000030)
#define ST_UART2_LCR_pen_mask                                         (0x00000008)
#define ST_UART2_LCR_stp_mask                                         (0x00000004)
#define ST_UART2_LCR_wls_mask                                         (0x00000003)
#define ST_UART2_LCR_dlab(data)                                       (0x00000080&((data)<<7))
#define ST_UART2_LCR_brk(data)                                        (0x00000040&((data)<<6))
#define ST_UART2_LCR_eps(data)                                        (0x00000030&((data)<<4))
#define ST_UART2_LCR_pen(data)                                        (0x00000008&((data)<<3))
#define ST_UART2_LCR_stp(data)                                        (0x00000004&((data)<<2))
#define ST_UART2_LCR_wls(data)                                        (0x00000003&(data))
#define ST_UART2_LCR_get_dlab(data)                                   ((0x00000080&(data))>>7)
#define ST_UART2_LCR_get_brk(data)                                    ((0x00000040&(data))>>6)
#define ST_UART2_LCR_get_eps(data)                                    ((0x00000030&(data))>>4)
#define ST_UART2_LCR_get_pen(data)                                    ((0x00000008&(data))>>3)
#define ST_UART2_LCR_get_stp(data)                                    ((0x00000004&(data))>>2)
#define ST_UART2_LCR_get_wls(data)                                    (0x00000003&(data))


#define ST_UART2_MCR                                                  0x18011330
#define ST_UART2_MCR_reg_addr                                         "0xb8011330"
#define ST_UART2_MCR_reg                                              0xb8011330
#define ST_UART2_MCR_inst_addr                                        "0x00CC"
#define ST_UART2_MCR_inst                                             0x00CC
#define ST_UART2_MCR_loop_shift                                       (4)
#define ST_UART2_MCR_rts_shift                                        (1)
#define ST_UART2_MCR_dtr_shift                                        (0)
#define ST_UART2_MCR_loop_mask                                        (0x00000010)
#define ST_UART2_MCR_rts_mask                                         (0x00000002)
#define ST_UART2_MCR_dtr_mask                                         (0x00000001)
#define ST_UART2_MCR_loop(data)                                       (0x00000010&((data)<<4))
#define ST_UART2_MCR_rts(data)                                        (0x00000002&((data)<<1))
#define ST_UART2_MCR_dtr(data)                                        (0x00000001&(data))
#define ST_UART2_MCR_get_loop(data)                                   ((0x00000010&(data))>>4)
#define ST_UART2_MCR_get_rts(data)                                    ((0x00000002&(data))>>1)
#define ST_UART2_MCR_get_dtr(data)                                    (0x00000001&(data))


#define ST_UART2_LSR                                                  0x18011334
#define ST_UART2_LSR_reg_addr                                         "0xb8011334"
#define ST_UART2_LSR_reg                                              0xb8011334
#define ST_UART2_LSR_inst_addr                                        "0x00CD"
#define ST_UART2_LSR_inst                                             0x00CD
#define ST_UART2_LSR_rfe_shift                                        (7)
#define ST_UART2_LSR_temt_shift                                       (6)
#define ST_UART2_LSR_thre_shift                                       (5)
#define ST_UART2_LSR_bi_shift                                         (4)
#define ST_UART2_LSR_fe_shift                                         (3)
#define ST_UART2_LSR_pe_shift                                         (2)
#define ST_UART2_LSR_oe_shift                                         (1)
#define ST_UART2_LSR_dr_shift                                         (0)
#define ST_UART2_LSR_rfe_mask                                         (0x00000080)
#define ST_UART2_LSR_temt_mask                                        (0x00000040)
#define ST_UART2_LSR_thre_mask                                        (0x00000020)
#define ST_UART2_LSR_bi_mask                                          (0x00000010)
#define ST_UART2_LSR_fe_mask                                          (0x00000008)
#define ST_UART2_LSR_pe_mask                                          (0x00000004)
#define ST_UART2_LSR_oe_mask                                          (0x00000002)
#define ST_UART2_LSR_dr_mask                                          (0x00000001)
#define ST_UART2_LSR_rfe(data)                                        (0x00000080&((data)<<7))
#define ST_UART2_LSR_temt(data)                                       (0x00000040&((data)<<6))
#define ST_UART2_LSR_thre(data)                                       (0x00000020&((data)<<5))
#define ST_UART2_LSR_bi(data)                                         (0x00000010&((data)<<4))
#define ST_UART2_LSR_fe(data)                                         (0x00000008&((data)<<3))
#define ST_UART2_LSR_pe(data)                                         (0x00000004&((data)<<2))
#define ST_UART2_LSR_oe(data)                                         (0x00000002&((data)<<1))
#define ST_UART2_LSR_dr(data)                                         (0x00000001&(data))
#define ST_UART2_LSR_get_rfe(data)                                    ((0x00000080&(data))>>7)
#define ST_UART2_LSR_get_temt(data)                                   ((0x00000040&(data))>>6)
#define ST_UART2_LSR_get_thre(data)                                   ((0x00000020&(data))>>5)
#define ST_UART2_LSR_get_bi(data)                                     ((0x00000010&(data))>>4)
#define ST_UART2_LSR_get_fe(data)                                     ((0x00000008&(data))>>3)
#define ST_UART2_LSR_get_pe(data)                                     ((0x00000004&(data))>>2)
#define ST_UART2_LSR_get_oe(data)                                     ((0x00000002&(data))>>1)
#define ST_UART2_LSR_get_dr(data)                                     (0x00000001&(data))


#define ST_UART2_MSR                                                  0x18011338
#define ST_UART2_MSR_reg_addr                                         "0xb8011338"
#define ST_UART2_MSR_reg                                              0xb8011338
#define ST_UART2_MSR_inst_addr                                        "0x00CE"
#define ST_UART2_MSR_inst                                             0x00CE
#define ST_UART2_MSR_dcd_shift                                        (7)
#define ST_UART2_MSR_ri_shift                                         (6)
#define ST_UART2_MSR_dsr_shift                                        (5)
#define ST_UART2_MSR_cts_shift                                        (4)
#define ST_UART2_MSR_dcts_shift                                       (0)
#define ST_UART2_MSR_dcd_mask                                         (0x00000080)
#define ST_UART2_MSR_ri_mask                                          (0x00000040)
#define ST_UART2_MSR_dsr_mask                                         (0x00000020)
#define ST_UART2_MSR_cts_mask                                         (0x00000010)
#define ST_UART2_MSR_dcts_mask                                        (0x00000001)
#define ST_UART2_MSR_dcd(data)                                        (0x00000080&((data)<<7))
#define ST_UART2_MSR_ri(data)                                         (0x00000040&((data)<<6))
#define ST_UART2_MSR_dsr(data)                                        (0x00000020&((data)<<5))
#define ST_UART2_MSR_cts(data)                                        (0x00000010&((data)<<4))
#define ST_UART2_MSR_dcts(data)                                       (0x00000001&(data))
#define ST_UART2_MSR_get_dcd(data)                                    ((0x00000080&(data))>>7)
#define ST_UART2_MSR_get_ri(data)                                     ((0x00000040&(data))>>6)
#define ST_UART2_MSR_get_dsr(data)                                    ((0x00000020&(data))>>5)
#define ST_UART2_MSR_get_cts(data)                                    ((0x00000010&(data))>>4)
#define ST_UART2_MSR_get_dcts(data)                                   (0x00000001&(data))


#define ST_UART2_SCR                                                  0x1801133c
#define ST_UART2_SCR_reg_addr                                         "0xb801133c"
#define ST_UART2_SCR_reg                                              0xb801133c
#define ST_UART2_SCR_inst_addr                                        "0x00CF"
#define ST_UART2_SCR_inst                                             0x00CF
#define ST_UART2_SCR_scr_shift                                        (0)
#define ST_UART2_SCR_scr_mask                                         (0x000000FF)
#define ST_UART2_SCR_scr(data)                                        (0x000000FF&(data))
#define ST_UART2_SCR_get_scr(data)                                    (0x000000FF&(data))


#define ST_UART3_RBR                                                  0x18011340
#define ST_UART3_RBR_reg_addr                                         "0xb8011340"
#define ST_UART3_RBR_reg                                              0xb8011340
#define ST_UART3_RBR_inst_addr                                        "0x00D0"
#define ST_UART3_RBR_inst                                             0x00D0
#define ST_UART3_RBR_rbd_shift                                        (0)
#define ST_UART3_RBR_rbd_mask                                         (0x000000FF)
#define ST_UART3_RBR_rbd(data)                                        (0x000000FF&(data))
#define ST_UART3_RBR_get_rbd(data)                                    (0x000000FF&(data))


#define ST_UART3_THR                                                  0x18011340
#define ST_UART3_THR_reg_addr                                         "0xb8011340"
#define ST_UART3_THR_reg                                              0xb8011340
#define ST_UART3_THR_inst_addr                                        "0x00D0"
#define ST_UART3_THR_inst                                             0x00D0
#define ST_UART3_THR_thd_shift                                        (0)
#define ST_UART3_THR_thd_mask                                         (0x000000FF)
#define ST_UART3_THR_thd(data)                                        (0x000000FF&(data))
#define ST_UART3_THR_get_thd(data)                                    (0x000000FF&(data))


#define ST_UART3_DLL                                                  0x18011340
#define ST_UART3_DLL_reg_addr                                         "0xb8011340"
#define ST_UART3_DLL_reg                                              0xb8011340
#define ST_UART3_DLL_inst_addr                                        "0x00D0"
#define ST_UART3_DLL_inst                                             0x00D0
#define ST_UART3_DLL_dll_shift                                        (0)
#define ST_UART3_DLL_dll_mask                                         (0x000000FF)
#define ST_UART3_DLL_dll(data)                                        (0x000000FF&(data))
#define ST_UART3_DLL_get_dll(data)                                    (0x000000FF&(data))


#define ST_UART3_DLM                                                  0x18011344
#define ST_UART3_DLM_reg_addr                                         "0xb8011344"
#define ST_UART3_DLM_reg                                              0xb8011344
#define ST_UART3_DLM_inst_addr                                        "0x00D1"
#define ST_UART3_DLM_inst                                             0x00D1
#define ST_UART3_DLM_dlm_shift                                        (0)
#define ST_UART3_DLM_dlm_mask                                         (0x000000FF)
#define ST_UART3_DLM_dlm(data)                                        (0x000000FF&(data))
#define ST_UART3_DLM_get_dlm(data)                                    (0x000000FF&(data))


#define ST_UART3_IER                                                  0x18011344
#define ST_UART3_IER_reg_addr                                         "0xb8011344"
#define ST_UART3_IER_reg                                              0xb8011344
#define ST_UART3_IER_inst_addr                                        "0x00D1"
#define ST_UART3_IER_inst                                             0x00D1
#define ST_UART3_IER_edssi_shift                                      (3)
#define ST_UART3_IER_elsi_shift                                       (2)
#define ST_UART3_IER_etbei_shift                                      (1)
#define ST_UART3_IER_erbi_shift                                       (0)
#define ST_UART3_IER_edssi_mask                                       (0x00000008)
#define ST_UART3_IER_elsi_mask                                        (0x00000004)
#define ST_UART3_IER_etbei_mask                                       (0x00000002)
#define ST_UART3_IER_erbi_mask                                        (0x00000001)
#define ST_UART3_IER_edssi(data)                                      (0x00000008&((data)<<3))
#define ST_UART3_IER_elsi(data)                                       (0x00000004&((data)<<2))
#define ST_UART3_IER_etbei(data)                                      (0x00000002&((data)<<1))
#define ST_UART3_IER_erbi(data)                                       (0x00000001&(data))
#define ST_UART3_IER_get_edssi(data)                                  ((0x00000008&(data))>>3)
#define ST_UART3_IER_get_elsi(data)                                   ((0x00000004&(data))>>2)
#define ST_UART3_IER_get_etbei(data)                                  ((0x00000002&(data))>>1)
#define ST_UART3_IER_get_erbi(data)                                   (0x00000001&(data))


#define ST_UART3_IIR                                                  0x18011348
#define ST_UART3_IIR_reg_addr                                         "0xb8011348"
#define ST_UART3_IIR_reg                                              0xb8011348
#define ST_UART3_IIR_inst_addr                                        "0x00D2"
#define ST_UART3_IIR_inst                                             0x00D2
#define ST_UART3_IIR_fifo16_shift                                     (6)
#define ST_UART3_IIR_iid_shift                                        (1)
#define ST_UART3_IIR_ipnd_shift                                       (0)
#define ST_UART3_IIR_fifo16_mask                                      (0x000000C0)
#define ST_UART3_IIR_iid_mask                                         (0x0000000E)
#define ST_UART3_IIR_ipnd_mask                                        (0x00000001)
#define ST_UART3_IIR_fifo16(data)                                     (0x000000C0&((data)<<6))
#define ST_UART3_IIR_iid(data)                                        (0x0000000E&((data)<<1))
#define ST_UART3_IIR_ipnd(data)                                       (0x00000001&(data))
#define ST_UART3_IIR_get_fifo16(data)                                 ((0x000000C0&(data))>>6)
#define ST_UART3_IIR_get_iid(data)                                    ((0x0000000E&(data))>>1)
#define ST_UART3_IIR_get_ipnd(data)                                   (0x00000001&(data))


#define ST_UART3_FCR                                                  0x18011348
#define ST_UART3_FCR_reg_addr                                         "0xb8011348"
#define ST_UART3_FCR_reg                                              0xb8011348
#define ST_UART3_FCR_inst_addr                                        "0x00D2"
#define ST_UART3_FCR_inst                                             0x00D2
#define ST_UART3_FCR_rtrg_shift                                       (6)
#define ST_UART3_FCR_dmam_shift                                       (3)
#define ST_UART3_FCR_tfrst_shift                                      (2)
#define ST_UART3_FCR_rfrst_shift                                      (1)
#define ST_UART3_FCR_efifo_shift                                      (0)
#define ST_UART3_FCR_rtrg_mask                                        (0x000000C0)
#define ST_UART3_FCR_dmam_mask                                        (0x00000008)
#define ST_UART3_FCR_tfrst_mask                                       (0x00000004)
#define ST_UART3_FCR_rfrst_mask                                       (0x00000002)
#define ST_UART3_FCR_efifo_mask                                       (0x00000001)
#define ST_UART3_FCR_rtrg(data)                                       (0x000000C0&((data)<<6))
#define ST_UART3_FCR_dmam(data)                                       (0x00000008&((data)<<3))
#define ST_UART3_FCR_tfrst(data)                                      (0x00000004&((data)<<2))
#define ST_UART3_FCR_rfrst(data)                                      (0x00000002&((data)<<1))
#define ST_UART3_FCR_efifo(data)                                      (0x00000001&(data))
#define ST_UART3_FCR_get_rtrg(data)                                   ((0x000000C0&(data))>>6)
#define ST_UART3_FCR_get_dmam(data)                                   ((0x00000008&(data))>>3)
#define ST_UART3_FCR_get_tfrst(data)                                  ((0x00000004&(data))>>2)
#define ST_UART3_FCR_get_rfrst(data)                                  ((0x00000002&(data))>>1)
#define ST_UART3_FCR_get_efifo(data)                                  (0x00000001&(data))


#define ST_UART3_LCR                                                  0x1801134c
#define ST_UART3_LCR_reg_addr                                         "0xb801134c"
#define ST_UART3_LCR_reg                                              0xb801134c
#define ST_UART3_LCR_inst_addr                                        "0x00D3"
#define ST_UART3_LCR_inst                                             0x00D3
#define ST_UART3_LCR_dlab_shift                                       (7)
#define ST_UART3_LCR_brk_shift                                        (6)
#define ST_UART3_LCR_eps_shift                                        (4)
#define ST_UART3_LCR_pen_shift                                        (3)
#define ST_UART3_LCR_stp_shift                                        (2)
#define ST_UART3_LCR_wls_shift                                        (0)
#define ST_UART3_LCR_dlab_mask                                        (0x00000080)
#define ST_UART3_LCR_brk_mask                                         (0x00000040)
#define ST_UART3_LCR_eps_mask                                         (0x00000030)
#define ST_UART3_LCR_pen_mask                                         (0x00000008)
#define ST_UART3_LCR_stp_mask                                         (0x00000004)
#define ST_UART3_LCR_wls_mask                                         (0x00000003)
#define ST_UART3_LCR_dlab(data)                                       (0x00000080&((data)<<7))
#define ST_UART3_LCR_brk(data)                                        (0x00000040&((data)<<6))
#define ST_UART3_LCR_eps(data)                                        (0x00000030&((data)<<4))
#define ST_UART3_LCR_pen(data)                                        (0x00000008&((data)<<3))
#define ST_UART3_LCR_stp(data)                                        (0x00000004&((data)<<2))
#define ST_UART3_LCR_wls(data)                                        (0x00000003&(data))
#define ST_UART3_LCR_get_dlab(data)                                   ((0x00000080&(data))>>7)
#define ST_UART3_LCR_get_brk(data)                                    ((0x00000040&(data))>>6)
#define ST_UART3_LCR_get_eps(data)                                    ((0x00000030&(data))>>4)
#define ST_UART3_LCR_get_pen(data)                                    ((0x00000008&(data))>>3)
#define ST_UART3_LCR_get_stp(data)                                    ((0x00000004&(data))>>2)
#define ST_UART3_LCR_get_wls(data)                                    (0x00000003&(data))


#define ST_UART3_MCR                                                  0x18011350
#define ST_UART3_MCR_reg_addr                                         "0xb8011350"
#define ST_UART3_MCR_reg                                              0xb8011350
#define ST_UART3_MCR_inst_addr                                        "0x00D4"
#define ST_UART3_MCR_inst                                             0x00D4
#define ST_UART3_MCR_loop_shift                                       (4)
#define ST_UART3_MCR_rts_shift                                        (1)
#define ST_UART3_MCR_dtr_shift                                        (0)
#define ST_UART3_MCR_loop_mask                                        (0x00000010)
#define ST_UART3_MCR_rts_mask                                         (0x00000002)
#define ST_UART3_MCR_dtr_mask                                         (0x00000001)
#define ST_UART3_MCR_loop(data)                                       (0x00000010&((data)<<4))
#define ST_UART3_MCR_rts(data)                                        (0x00000002&((data)<<1))
#define ST_UART3_MCR_dtr(data)                                        (0x00000001&(data))
#define ST_UART3_MCR_get_loop(data)                                   ((0x00000010&(data))>>4)
#define ST_UART3_MCR_get_rts(data)                                    ((0x00000002&(data))>>1)
#define ST_UART3_MCR_get_dtr(data)                                    (0x00000001&(data))


#define ST_UART3_LSR                                                  0x18011354
#define ST_UART3_LSR_reg_addr                                         "0xb8011354"
#define ST_UART3_LSR_reg                                              0xb8011354
#define ST_UART3_LSR_inst_addr                                        "0x00D5"
#define ST_UART3_LSR_inst                                             0x00D5
#define ST_UART3_LSR_rfe_shift                                        (7)
#define ST_UART3_LSR_temt_shift                                       (6)
#define ST_UART3_LSR_thre_shift                                       (5)
#define ST_UART3_LSR_bi_shift                                         (4)
#define ST_UART3_LSR_fe_shift                                         (3)
#define ST_UART3_LSR_pe_shift                                         (2)
#define ST_UART3_LSR_oe_shift                                         (1)
#define ST_UART3_LSR_dr_shift                                         (0)
#define ST_UART3_LSR_rfe_mask                                         (0x00000080)
#define ST_UART3_LSR_temt_mask                                        (0x00000040)
#define ST_UART3_LSR_thre_mask                                        (0x00000020)
#define ST_UART3_LSR_bi_mask                                          (0x00000010)
#define ST_UART3_LSR_fe_mask                                          (0x00000008)
#define ST_UART3_LSR_pe_mask                                          (0x00000004)
#define ST_UART3_LSR_oe_mask                                          (0x00000002)
#define ST_UART3_LSR_dr_mask                                          (0x00000001)
#define ST_UART3_LSR_rfe(data)                                        (0x00000080&((data)<<7))
#define ST_UART3_LSR_temt(data)                                       (0x00000040&((data)<<6))
#define ST_UART3_LSR_thre(data)                                       (0x00000020&((data)<<5))
#define ST_UART3_LSR_bi(data)                                         (0x00000010&((data)<<4))
#define ST_UART3_LSR_fe(data)                                         (0x00000008&((data)<<3))
#define ST_UART3_LSR_pe(data)                                         (0x00000004&((data)<<2))
#define ST_UART3_LSR_oe(data)                                         (0x00000002&((data)<<1))
#define ST_UART3_LSR_dr(data)                                         (0x00000001&(data))
#define ST_UART3_LSR_get_rfe(data)                                    ((0x00000080&(data))>>7)
#define ST_UART3_LSR_get_temt(data)                                   ((0x00000040&(data))>>6)
#define ST_UART3_LSR_get_thre(data)                                   ((0x00000020&(data))>>5)
#define ST_UART3_LSR_get_bi(data)                                     ((0x00000010&(data))>>4)
#define ST_UART3_LSR_get_fe(data)                                     ((0x00000008&(data))>>3)
#define ST_UART3_LSR_get_pe(data)                                     ((0x00000004&(data))>>2)
#define ST_UART3_LSR_get_oe(data)                                     ((0x00000002&(data))>>1)
#define ST_UART3_LSR_get_dr(data)                                     (0x00000001&(data))


#define ST_UART3_MSR                                                  0x18011358
#define ST_UART3_MSR_reg_addr                                         "0xb8011358"
#define ST_UART3_MSR_reg                                              0xb8011358
#define ST_UART3_MSR_inst_addr                                        "0x00D6"
#define ST_UART3_MSR_inst                                             0x00D6
#define ST_UART3_MSR_dcd_shift                                        (7)
#define ST_UART3_MSR_ri_shift                                         (6)
#define ST_UART3_MSR_dsr_shift                                        (5)
#define ST_UART3_MSR_cts_shift                                        (4)
#define ST_UART3_MSR_dcts_shift                                       (0)
#define ST_UART3_MSR_dcd_mask                                         (0x00000080)
#define ST_UART3_MSR_ri_mask                                          (0x00000040)
#define ST_UART3_MSR_dsr_mask                                         (0x00000020)
#define ST_UART3_MSR_cts_mask                                         (0x00000010)
#define ST_UART3_MSR_dcts_mask                                        (0x00000001)
#define ST_UART3_MSR_dcd(data)                                        (0x00000080&((data)<<7))
#define ST_UART3_MSR_ri(data)                                         (0x00000040&((data)<<6))
#define ST_UART3_MSR_dsr(data)                                        (0x00000020&((data)<<5))
#define ST_UART3_MSR_cts(data)                                        (0x00000010&((data)<<4))
#define ST_UART3_MSR_dcts(data)                                       (0x00000001&(data))
#define ST_UART3_MSR_get_dcd(data)                                    ((0x00000080&(data))>>7)
#define ST_UART3_MSR_get_ri(data)                                     ((0x00000040&(data))>>6)
#define ST_UART3_MSR_get_dsr(data)                                    ((0x00000020&(data))>>5)
#define ST_UART3_MSR_get_cts(data)                                    ((0x00000010&(data))>>4)
#define ST_UART3_MSR_get_dcts(data)                                   (0x00000001&(data))


#define ST_UART3_SCR                                                  0x1801135c
#define ST_UART3_SCR_reg_addr                                         "0xb801135c"
#define ST_UART3_SCR_reg                                              0xb801135c
#define ST_UART3_SCR_inst_addr                                        "0x00D7"
#define ST_UART3_SCR_inst                                             0x00D7
#define ST_UART3_SCR_scr_shift                                        (0)
#define ST_UART3_SCR_scr_mask                                         (0x000000FF)
#define ST_UART3_SCR_scr(data)                                        (0x000000FF&(data))
#define ST_UART3_SCR_get_scr(data)                                    (0x000000FF&(data))


#define ST_IR_PSR                                                     0x18011400
#define ST_IR_PSR_reg_addr                                            "0xb8011400"
#define ST_IR_PSR_reg                                                 0xb8011400
#define ST_IR_PSR_inst_addr                                           "0x0100"
#define ST_IR_PSR_inst                                                0x0100
#define ST_IR_PSR_irrbl_shift                                         (24)
#define ST_IR_PSR_irrml_shift                                         (16)
#define ST_IR_PSR_irrdzl_shift                                        (8)
#define ST_IR_PSR_irrdol_shift                                        (0)
#define ST_IR_PSR_irrbl_mask                                          (0xFF000000)
#define ST_IR_PSR_irrml_mask                                          (0x00FF0000)
#define ST_IR_PSR_irrdzl_mask                                         (0x0000FF00)
#define ST_IR_PSR_irrdol_mask                                         (0x000000FF)
#define ST_IR_PSR_irrbl(data)                                         (0xFF000000&((data)<<24))
#define ST_IR_PSR_irrml(data)                                         (0x00FF0000&((data)<<16))
#define ST_IR_PSR_irrdzl(data)                                        (0x0000FF00&((data)<<8))
#define ST_IR_PSR_irrdol(data)                                        (0x000000FF&(data))
#define ST_IR_PSR_get_irrbl(data)                                     ((0xFF000000&(data))>>24)
#define ST_IR_PSR_get_irrml(data)                                     ((0x00FF0000&(data))>>16)
#define ST_IR_PSR_get_irrdzl(data)                                    ((0x0000FF00&(data))>>8)
#define ST_IR_PSR_get_irrdol(data)                                    (0x000000FF&(data))


#define ST_IR_PER                                                     0x18011404
#define ST_IR_PER_reg_addr                                            "0xb8011404"
#define ST_IR_PER_reg                                                 0xb8011404
#define ST_IR_PER_inst_addr                                           "0x0101"
#define ST_IR_PER_inst                                                0x0101
#define ST_IR_PER_irrdl_shift                                         (16)
#define ST_IR_PER_irrrl_shift                                         (8)
#define ST_IR_PER_irrsl_shift                                         (0)
#define ST_IR_PER_irrdl_mask                                          (0x003F0000)
#define ST_IR_PER_irrrl_mask                                          (0x0000FF00)
#define ST_IR_PER_irrsl_mask                                          (0x000000FF)
#define ST_IR_PER_irrdl(data)                                         (0x003F0000&((data)<<16))
#define ST_IR_PER_irrrl(data)                                         (0x0000FF00&((data)<<8))
#define ST_IR_PER_irrsl(data)                                         (0x000000FF&(data))
#define ST_IR_PER_get_irrdl(data)                                     ((0x003F0000&(data))>>16)
#define ST_IR_PER_get_irrrl(data)                                     ((0x0000FF00&(data))>>8)
#define ST_IR_PER_get_irrsl(data)                                     (0x000000FF&(data))


#define ST_IR_SF                                                      0x18011408
#define ST_IR_SF_reg_addr                                             "0xb8011408"
#define ST_IR_SF_reg                                                  0xb8011408
#define ST_IR_SF_inst_addr                                            "0x0102"
#define ST_IR_SF_inst                                                 0x0102
#define ST_IR_SF_irit_shift                                           (24)
#define ST_IR_SF_iroct_shift                                          (16)
#define ST_IR_SF_irfd_shift                                           (0)
#define ST_IR_SF_irit_mask                                            (0xFF000000)
#define ST_IR_SF_iroct_mask                                           (0x00FF0000)
#define ST_IR_SF_irfd_mask                                            (0x0000FFFF)
#define ST_IR_SF_irit(data)                                           (0xFF000000&((data)<<24))
#define ST_IR_SF_iroct(data)                                          (0x00FF0000&((data)<<16))
#define ST_IR_SF_irfd(data)                                           (0x0000FFFF&(data))
#define ST_IR_SF_get_irit(data)                                       ((0xFF000000&(data))>>24)
#define ST_IR_SF_get_iroct(data)                                      ((0x00FF0000&(data))>>16)
#define ST_IR_SF_get_irfd(data)                                       (0x0000FFFF&(data))


#define ST_IR_DPIR                                                    0x1801140c
#define ST_IR_DPIR_reg_addr                                           "0xb801140c"
#define ST_IR_DPIR_reg                                                0xb801140c
#define ST_IR_DPIR_inst_addr                                          "0x0103"
#define ST_IR_DPIR_inst                                               0x0103
#define ST_IR_DPIR_iriotcdp_shift                                     (0)
#define ST_IR_DPIR_iriotcdp_mask                                      (0x0000FFFF)
#define ST_IR_DPIR_iriotcdp(data)                                     (0x0000FFFF&(data))
#define ST_IR_DPIR_get_iriotcdp(data)                                 (0x0000FFFF&(data))


#define ST_IR_CR                                                      0x18011410
#define ST_IR_CR_reg_addr                                             "0xb8011410"
#define ST_IR_CR_reg                                                  0xb8011410
#define ST_IR_CR_inst_addr                                            "0x0104"
#define ST_IR_CR_inst                                                 0x0104
#define ST_IR_CR_irsr_shift                                           (31)
#define ST_IR_CR_irednm_shift                                         (23)
#define ST_IR_CR_iredn_shift                                          (16)
#define ST_IR_CR_raw_fifo_ov_shift                                    (14)
#define ST_IR_CR_raw_fifo_val_shift                                   (13)
#define ST_IR_CR_raw_en_shift                                         (12)
#define ST_IR_CR_mlae_shift                                           (11)
#define ST_IR_CR_irie_shift                                           (10)
#define ST_IR_CR_irres_shift                                          (9)
#define ST_IR_CR_irue_shift                                           (8)
#define ST_IR_CR_ircm_shift                                           (7)
#define ST_IR_CR_irbme_shift                                          (6)
#define ST_IR_CR_irdpm_shift                                          (5)
#define ST_IR_CR_irdn_shift                                           (0)
#define ST_IR_CR_irsr_mask                                            (0x80000000)
#define ST_IR_CR_irednm_mask                                          (0x00800000)
#define ST_IR_CR_iredn_mask                                           (0x003F0000)
#define ST_IR_CR_raw_fifo_ov_mask                                     (0x00004000)
#define ST_IR_CR_raw_fifo_val_mask                                    (0x00002000)
#define ST_IR_CR_raw_en_mask                                          (0x00001000)
#define ST_IR_CR_mlae_mask                                            (0x00000800)
#define ST_IR_CR_irie_mask                                            (0x00000400)
#define ST_IR_CR_irres_mask                                           (0x00000200)
#define ST_IR_CR_irue_mask                                            (0x00000100)
#define ST_IR_CR_ircm_mask                                            (0x00000080)
#define ST_IR_CR_irbme_mask                                           (0x00000040)
#define ST_IR_CR_irdpm_mask                                           (0x00000020)
#define ST_IR_CR_irdn_mask                                            (0x0000001F)
#define ST_IR_CR_irsr(data)                                           (0x80000000&((data)<<31))
#define ST_IR_CR_irednm(data)                                         (0x00800000&((data)<<23))
#define ST_IR_CR_iredn(data)                                          (0x003F0000&((data)<<16))
#define ST_IR_CR_raw_fifo_ov(data)                                    (0x00004000&((data)<<14))
#define ST_IR_CR_raw_fifo_val(data)                                   (0x00002000&((data)<<13))
#define ST_IR_CR_raw_en(data)                                         (0x00001000&((data)<<12))
#define ST_IR_CR_mlae(data)                                           (0x00000800&((data)<<11))
#define ST_IR_CR_irie(data)                                           (0x00000400&((data)<<10))
#define ST_IR_CR_irres(data)                                          (0x00000200&((data)<<9))
#define ST_IR_CR_irue(data)                                           (0x00000100&((data)<<8))
#define ST_IR_CR_ircm(data)                                           (0x00000080&((data)<<7))
#define ST_IR_CR_irbme(data)                                          (0x00000040&((data)<<6))
#define ST_IR_CR_irdpm(data)                                          (0x00000020&((data)<<5))
#define ST_IR_CR_irdn(data)                                           (0x0000001F&(data))
#define ST_IR_CR_get_irsr(data)                                       ((0x80000000&(data))>>31)
#define ST_IR_CR_get_irednm(data)                                     ((0x00800000&(data))>>23)
#define ST_IR_CR_get_iredn(data)                                      ((0x003F0000&(data))>>16)
#define ST_IR_CR_get_raw_fifo_ov(data)                                ((0x00004000&(data))>>14)
#define ST_IR_CR_get_raw_fifo_val(data)                               ((0x00002000&(data))>>13)
#define ST_IR_CR_get_raw_en(data)                                     ((0x00001000&(data))>>12)
#define ST_IR_CR_get_mlae(data)                                       ((0x00000800&(data))>>11)
#define ST_IR_CR_get_irie(data)                                       ((0x00000400&(data))>>10)
#define ST_IR_CR_get_irres(data)                                      ((0x00000200&(data))>>9)
#define ST_IR_CR_get_irue(data)                                       ((0x00000100&(data))>>8)
#define ST_IR_CR_get_ircm(data)                                       ((0x00000080&(data))>>7)
#define ST_IR_CR_get_irbme(data)                                      ((0x00000040&(data))>>6)
#define ST_IR_CR_get_irdpm(data)                                      ((0x00000020&(data))>>5)
#define ST_IR_CR_get_irdn(data)                                       (0x0000001F&(data))


#define ST_IR_RP                                                      0x18011414
#define ST_IR_RP_reg_addr                                             "0xb8011414"
#define ST_IR_RP_reg                                                  0xb8011414
#define ST_IR_RP_inst_addr                                            "0x0105"
#define ST_IR_RP_inst                                                 0x0105
#define ST_IR_RP_irrp_shift                                           (0)
#define ST_IR_RP_irrp_mask                                            (0xFFFFFFFF)
#define ST_IR_RP_irrp(data)                                           (0xFFFFFFFF&(data))
#define ST_IR_RP_get_irrp(data)                                       (0xFFFFFFFF&(data))


#define ST_IR_SR                                                      0x18011418
#define ST_IR_SR_reg_addr                                             "0xb8011418"
#define ST_IR_SR_reg                                                  0xb8011418
#define ST_IR_SR_inst_addr                                            "0x0106"
#define ST_IR_SR_inst                                                 0x0106
#define ST_IR_SR_rmt_big_shift                                        (4)
#define ST_IR_SR_raw_fifo_ov_shift                                    (3)
#define ST_IR_SR_raw_fifo_val_shift                                   (2)
#define ST_IR_SR_irrf_shift                                           (1)
#define ST_IR_SR_irdvf_shift                                          (0)
#define ST_IR_SR_rmt_big_mask                                         (0x00000010)
#define ST_IR_SR_raw_fifo_ov_mask                                     (0x00000008)
#define ST_IR_SR_raw_fifo_val_mask                                    (0x00000004)
#define ST_IR_SR_irrf_mask                                            (0x00000002)
#define ST_IR_SR_irdvf_mask                                           (0x00000001)
#define ST_IR_SR_rmt_big(data)                                        (0x00000010&((data)<<4))
#define ST_IR_SR_raw_fifo_ov(data)                                    (0x00000008&((data)<<3))
#define ST_IR_SR_raw_fifo_val(data)                                   (0x00000004&((data)<<2))
#define ST_IR_SR_irrf(data)                                           (0x00000002&((data)<<1))
#define ST_IR_SR_irdvf(data)                                          (0x00000001&(data))
#define ST_IR_SR_get_rmt_big(data)                                    ((0x00000010&(data))>>4)
#define ST_IR_SR_get_raw_fifo_ov(data)                                ((0x00000008&(data))>>3)
#define ST_IR_SR_get_raw_fifo_val(data)                               ((0x00000004&(data))>>2)
#define ST_IR_SR_get_irrf(data)                                       ((0x00000002&(data))>>1)
#define ST_IR_SR_get_irdvf(data)                                      (0x00000001&(data))


#define ST_IR_RAW_CTRL                                                0x1801141c
#define ST_IR_RAW_CTRL_reg_addr                                       "0xb801141c"
#define ST_IR_RAW_CTRL_reg                                            0xb801141c
#define ST_IR_RAW_CTRL_inst_addr                                      "0x0107"
#define ST_IR_RAW_CTRL_inst                                           0x0107
#define ST_IR_RAW_CTRL_write_enable2_shift                            (25)
#define ST_IR_RAW_CTRL_stop_sample_shift                              (24)
#define ST_IR_RAW_CTRL_stop_time_shift                                (8)
#define ST_IR_RAW_CTRL_write_enable1_shift                            (6)
#define ST_IR_RAW_CTRL_fifo_thr_shift                                 (0)
#define ST_IR_RAW_CTRL_write_enable2_mask                             (0x02000000)
#define ST_IR_RAW_CTRL_stop_sample_mask                               (0x01000000)
#define ST_IR_RAW_CTRL_stop_time_mask                                 (0x00FFFF00)
#define ST_IR_RAW_CTRL_write_enable1_mask                             (0x00000040)
#define ST_IR_RAW_CTRL_fifo_thr_mask                                  (0x0000003F)
#define ST_IR_RAW_CTRL_write_enable2(data)                            (0x02000000&((data)<<25))
#define ST_IR_RAW_CTRL_stop_sample(data)                              (0x01000000&((data)<<24))
#define ST_IR_RAW_CTRL_stop_time(data)                                (0x00FFFF00&((data)<<8))
#define ST_IR_RAW_CTRL_write_enable1(data)                            (0x00000040&((data)<<6))
#define ST_IR_RAW_CTRL_fifo_thr(data)                                 (0x0000003F&(data))
#define ST_IR_RAW_CTRL_get_write_enable2(data)                        ((0x02000000&(data))>>25)
#define ST_IR_RAW_CTRL_get_stop_sample(data)                          ((0x01000000&(data))>>24)
#define ST_IR_RAW_CTRL_get_stop_time(data)                            ((0x00FFFF00&(data))>>8)
#define ST_IR_RAW_CTRL_get_write_enable1(data)                        ((0x00000040&(data))>>6)
#define ST_IR_RAW_CTRL_get_fifo_thr(data)                             (0x0000003F&(data))


#define ST_IR_RAW_FF                                                  0x18011420
#define ST_IR_RAW_FF_reg_addr                                         "0xb8011420"
#define ST_IR_RAW_FF_reg                                              0xb8011420
#define ST_IR_RAW_FF_inst_addr                                        "0x0108"
#define ST_IR_RAW_FF_inst                                             0x0108
#define ST_IR_RAW_FF_dat_shift                                        (0)
#define ST_IR_RAW_FF_dat_mask                                         (0xFFFFFFFF)
#define ST_IR_RAW_FF_dat(data)                                        (0xFFFFFFFF&(data))
#define ST_IR_RAW_FF_get_dat(data)                                    (0xFFFFFFFF&(data))


#define ST_IR_RAW_SAMPLE_TIME                                         0x18011424
#define ST_IR_RAW_SAMPLE_TIME_reg_addr                                "0xb8011424"
#define ST_IR_RAW_SAMPLE_TIME_reg                                     0xb8011424
#define ST_IR_RAW_SAMPLE_TIME_inst_addr                               "0x0109"
#define ST_IR_RAW_SAMPLE_TIME_inst                                    0x0109
#define ST_IR_RAW_SAMPLE_TIME_cnt_shift                               (0)
#define ST_IR_RAW_SAMPLE_TIME_cnt_mask                                (0x0000FFFF)
#define ST_IR_RAW_SAMPLE_TIME_cnt(data)                               (0x0000FFFF&(data))
#define ST_IR_RAW_SAMPLE_TIME_get_cnt(data)                           (0x0000FFFF&(data))


#define ST_IR_RAW_WL                                                  0x18011428
#define ST_IR_RAW_WL_reg_addr                                         "0xb8011428"
#define ST_IR_RAW_WL_reg                                              0xb8011428
#define ST_IR_RAW_WL_inst_addr                                        "0x010A"
#define ST_IR_RAW_WL_inst                                             0x010A
#define ST_IR_RAW_WL_val_shift                                        (0)
#define ST_IR_RAW_WL_val_mask                                         (0x0000003F)
#define ST_IR_RAW_WL_val(data)                                        (0x0000003F&(data))
#define ST_IR_RAW_WL_get_val(data)                                    (0x0000003F&(data))


#define ST_IR_RAW_DEB                                                 0x1801142c
#define ST_IR_RAW_DEB_reg_addr                                        "0xb801142c"
#define ST_IR_RAW_DEB_reg                                             0xb801142c
#define ST_IR_RAW_DEB_inst_addr                                       "0x010B"
#define ST_IR_RAW_DEB_inst                                            0x010B
#define ST_IR_RAW_DEB_len_shift                                       (16)
#define ST_IR_RAW_DEB_clk_shift                                       (0)
#define ST_IR_RAW_DEB_len_mask                                        (0x00FF0000)
#define ST_IR_RAW_DEB_clk_mask                                        (0x0000FFFF)
#define ST_IR_RAW_DEB_len(data)                                       (0x00FF0000&((data)<<16))
#define ST_IR_RAW_DEB_clk(data)                                       (0x0000FFFF&(data))
#define ST_IR_RAW_DEB_get_len(data)                                   ((0x00FF0000&(data))>>16)
#define ST_IR_RAW_DEB_get_clk(data)                                   (0x0000FFFF&(data))


#define ST_IR_PSR_UP                                                  0x18011430
#define ST_IR_PSR_UP_reg_addr                                         "0xb8011430"
#define ST_IR_PSR_UP_reg                                              0xb8011430
#define ST_IR_PSR_UP_inst_addr                                        "0x010C"
#define ST_IR_PSR_UP_inst                                             0x010C
#define ST_IR_PSR_UP_irrbl_shift                                      (24)
#define ST_IR_PSR_UP_irrml_shift                                      (16)
#define ST_IR_PSR_UP_irrdzl_shift                                     (8)
#define ST_IR_PSR_UP_irrdol_shift                                     (0)
#define ST_IR_PSR_UP_irrbl_mask                                       (0xFF000000)
#define ST_IR_PSR_UP_irrml_mask                                       (0x00FF0000)
#define ST_IR_PSR_UP_irrdzl_mask                                      (0x0000FF00)
#define ST_IR_PSR_UP_irrdol_mask                                      (0x000000FF)
#define ST_IR_PSR_UP_irrbl(data)                                      (0xFF000000&((data)<<24))
#define ST_IR_PSR_UP_irrml(data)                                      (0x00FF0000&((data)<<16))
#define ST_IR_PSR_UP_irrdzl(data)                                     (0x0000FF00&((data)<<8))
#define ST_IR_PSR_UP_irrdol(data)                                     (0x000000FF&(data))
#define ST_IR_PSR_UP_get_irrbl(data)                                  ((0xFF000000&(data))>>24)
#define ST_IR_PSR_UP_get_irrml(data)                                  ((0x00FF0000&(data))>>16)
#define ST_IR_PSR_UP_get_irrdzl(data)                                 ((0x0000FF00&(data))>>8)
#define ST_IR_PSR_UP_get_irrdol(data)                                 (0x000000FF&(data))


#define ST_IR_PER_UP                                                  0x18011434
#define ST_IR_PER_UP_reg_addr                                         "0xb8011434"
#define ST_IR_PER_UP_reg                                              0xb8011434
#define ST_IR_PER_UP_inst_addr                                        "0x010D"
#define ST_IR_PER_UP_inst                                             0x010D
#define ST_IR_PER_UP_rc6_in_shift                                     (24)
#define ST_IR_PER_UP_irtr_shift                                       (16)
#define ST_IR_PER_UP_irrrl_shift                                      (8)
#define ST_IR_PER_UP_irrsl_shift                                      (0)
#define ST_IR_PER_UP_rc6_in_mask                                      (0x01000000)
#define ST_IR_PER_UP_irtr_mask                                        (0x00FF0000)
#define ST_IR_PER_UP_irrrl_mask                                       (0x0000FF00)
#define ST_IR_PER_UP_irrsl_mask                                       (0x000000FF)
#define ST_IR_PER_UP_rc6_in(data)                                     (0x01000000&((data)<<24))
#define ST_IR_PER_UP_irtr(data)                                       (0x00FF0000&((data)<<16))
#define ST_IR_PER_UP_irrrl(data)                                      (0x0000FF00&((data)<<8))
#define ST_IR_PER_UP_irrsl(data)                                      (0x000000FF&(data))
#define ST_IR_PER_UP_get_rc6_in(data)                                 ((0x01000000&(data))>>24)
#define ST_IR_PER_UP_get_irtr(data)                                   ((0x00FF0000&(data))>>16)
#define ST_IR_PER_UP_get_irrrl(data)                                  ((0x0000FF00&(data))>>8)
#define ST_IR_PER_UP_get_irrsl(data)                                  (0x000000FF&(data))


#define ST_IR_RP2                                                     0x18011438
#define ST_IR_RP2_reg_addr                                            "0xb8011438"
#define ST_IR_RP2_reg                                                 0xb8011438
#define ST_IR_RP2_inst_addr                                           "0x010E"
#define ST_IR_RP2_inst                                                0x010E
#define ST_IR_RP2_irrp_shift                                          (0)
#define ST_IR_RP2_irrp_mask                                           (0xFFFFFFFF)
#define ST_IR_RP2_irrp(data)                                          (0xFFFFFFFF&(data))
#define ST_IR_RP2_get_irrp(data)                                      (0xFFFFFFFF&(data))


#define ST_IR_EXT_RP_CF                                               0x1801143c
#define ST_IR_EXT_RP_CF_reg_addr                                      "0xb801143c"
#define ST_IR_EXT_RP_CF_reg                                           0xb801143c
#define ST_IR_EXT_RP_CF_inst_addr                                     "0x010F"
#define ST_IR_EXT_RP_CF_inst                                          0x010F
#define ST_IR_EXT_RP_CF_rp_num_shift                                  (4)
#define ST_IR_EXT_RP_CF_ext_rp_en_shift                               (0)
#define ST_IR_EXT_RP_CF_rp_num_mask                                   (0x000000F0)
#define ST_IR_EXT_RP_CF_ext_rp_en_mask                                (0x00000001)
#define ST_IR_EXT_RP_CF_rp_num(data)                                  (0x000000F0&((data)<<4))
#define ST_IR_EXT_RP_CF_ext_rp_en(data)                               (0x00000001&(data))
#define ST_IR_EXT_RP_CF_get_rp_num(data)                              ((0x000000F0&(data))>>4)
#define ST_IR_EXT_RP_CF_get_ext_rp_en(data)                           (0x00000001&(data))


#define ST_IR_EXT_RP_TIMG                                             0x18011440
#define ST_IR_EXT_RP_TIMG_reg_addr                                    "0xb8011440"
#define ST_IR_EXT_RP_TIMG_reg                                         0xb8011440
#define ST_IR_EXT_RP_TIMG_inst_addr                                   "0x0110"
#define ST_IR_EXT_RP_TIMG_inst                                        0x0110
#define ST_IR_EXT_RP_TIMG_rp_burst_shift                              (24)
#define ST_IR_EXT_RP_TIMG_rp_silence_shift                            (16)
#define ST_IR_EXT_RP_TIMG_rp_tail_burst_shift                         (8)
#define ST_IR_EXT_RP_TIMG_rp_tail_silence_shift                       (0)
#define ST_IR_EXT_RP_TIMG_rp_burst_mask                               (0xFF000000)
#define ST_IR_EXT_RP_TIMG_rp_silence_mask                             (0x00FF0000)
#define ST_IR_EXT_RP_TIMG_rp_tail_burst_mask                          (0x0000FF00)
#define ST_IR_EXT_RP_TIMG_rp_tail_silence_mask                        (0x000000FF)
#define ST_IR_EXT_RP_TIMG_rp_burst(data)                              (0xFF000000&((data)<<24))
#define ST_IR_EXT_RP_TIMG_rp_silence(data)                            (0x00FF0000&((data)<<16))
#define ST_IR_EXT_RP_TIMG_rp_tail_burst(data)                         (0x0000FF00&((data)<<8))
#define ST_IR_EXT_RP_TIMG_rp_tail_silence(data)                       (0x000000FF&(data))
#define ST_IR_EXT_RP_TIMG_get_rp_burst(data)                          ((0xFF000000&(data))>>24)
#define ST_IR_EXT_RP_TIMG_get_rp_silence(data)                        ((0x00FF0000&(data))>>16)
#define ST_IR_EXT_RP_TIMG_get_rp_tail_burst(data)                     ((0x0000FF00&(data))>>8)
#define ST_IR_EXT_RP_TIMG_get_rp_tail_silence(data)                   (0x000000FF&(data))


#define ST_IR_EXT_RP_TIMG_UP                                          0x18011444
#define ST_IR_EXT_RP_TIMG_UP_reg_addr                                 "0xb8011444"
#define ST_IR_EXT_RP_TIMG_UP_reg                                      0xb8011444
#define ST_IR_EXT_RP_TIMG_UP_inst_addr                                "0x0111"
#define ST_IR_EXT_RP_TIMG_UP_inst                                     0x0111
#define ST_IR_EXT_RP_TIMG_UP_rp_burst_shift                           (24)
#define ST_IR_EXT_RP_TIMG_UP_rp_silence_shift                         (16)
#define ST_IR_EXT_RP_TIMG_UP_rp_tail_burst_shift                      (8)
#define ST_IR_EXT_RP_TIMG_UP_rp_tail_silence_shift                    (0)
#define ST_IR_EXT_RP_TIMG_UP_rp_burst_mask                            (0xFF000000)
#define ST_IR_EXT_RP_TIMG_UP_rp_silence_mask                          (0x00FF0000)
#define ST_IR_EXT_RP_TIMG_UP_rp_tail_burst_mask                       (0x0000FF00)
#define ST_IR_EXT_RP_TIMG_UP_rp_tail_silence_mask                     (0x000000FF)
#define ST_IR_EXT_RP_TIMG_UP_rp_burst(data)                           (0xFF000000&((data)<<24))
#define ST_IR_EXT_RP_TIMG_UP_rp_silence(data)                         (0x00FF0000&((data)<<16))
#define ST_IR_EXT_RP_TIMG_UP_rp_tail_burst(data)                      (0x0000FF00&((data)<<8))
#define ST_IR_EXT_RP_TIMG_UP_rp_tail_silence(data)                    (0x000000FF&(data))
#define ST_IR_EXT_RP_TIMG_UP_get_rp_burst(data)                       ((0xFF000000&(data))>>24)
#define ST_IR_EXT_RP_TIMG_UP_get_rp_silence(data)                     ((0x00FF0000&(data))>>16)
#define ST_IR_EXT_RP_TIMG_UP_get_rp_tail_burst(data)                  ((0x0000FF00&(data))>>8)
#define ST_IR_EXT_RP_TIMG_UP_get_rp_tail_silence(data)                (0x000000FF&(data))


#define HW_DECODE_DATA0_L                                             0x18011450
#define HW_DECODE_DATA0_L_reg_addr                                    "0xb8011450"
#define HW_DECODE_DATA0_L_reg                                         0xb8011450
#define HW_DECODE_DATA0_L_inst_addr                                   "0x0114"
#define HW_DECODE_DATA0_L_inst                                        0x0114
#define HW_DECODE_DATA0_L_hw_decode_data0l_shift                      (0)
#define HW_DECODE_DATA0_L_hw_decode_data0l_mask                       (0xFFFFFFFF)
#define HW_DECODE_DATA0_L_hw_decode_data0l(data)                      (0xFFFFFFFF&(data))
#define HW_DECODE_DATA0_L_get_hw_decode_data0l(data)                  (0xFFFFFFFF&(data))


#define HW_DECODE_DATA0_H                                             0x18011454
#define HW_DECODE_DATA0_H_reg_addr                                    "0xb8011454"
#define HW_DECODE_DATA0_H_reg                                         0xb8011454
#define HW_DECODE_DATA0_H_inst_addr                                   "0x0115"
#define HW_DECODE_DATA0_H_inst                                        0x0115
#define HW_DECODE_DATA0_H_hw_decode_data0h_shift                      (0)
#define HW_DECODE_DATA0_H_hw_decode_data0h_mask                       (0xFFFFFFFF)
#define HW_DECODE_DATA0_H_hw_decode_data0h(data)                      (0xFFFFFFFF&(data))
#define HW_DECODE_DATA0_H_get_hw_decode_data0h(data)                  (0xFFFFFFFF&(data))


#define DECODE_MASK_DATA0_L                                           0x18011458
#define DECODE_MASK_DATA0_L_reg_addr                                  "0xb8011458"
#define DECODE_MASK_DATA0_L_reg                                       0xb8011458
#define DECODE_MASK_DATA0_L_inst_addr                                 "0x0116"
#define DECODE_MASK_DATA0_L_inst                                      0x0116
#define DECODE_MASK_DATA0_L_decode_mask_data0l_shift                  (0)
#define DECODE_MASK_DATA0_L_decode_mask_data0l_mask                   (0xFFFFFFFF)
#define DECODE_MASK_DATA0_L_decode_mask_data0l(data)                  (0xFFFFFFFF&(data))
#define DECODE_MASK_DATA0_L_get_decode_mask_data0l(data)              (0xFFFFFFFF&(data))


#define DECODE_MASK_DATA0_H                                           0x1801145c
#define DECODE_MASK_DATA0_H_reg_addr                                  "0xb801145c"
#define DECODE_MASK_DATA0_H_reg                                       0xb801145c
#define DECODE_MASK_DATA0_H_inst_addr                                 "0x0117"
#define DECODE_MASK_DATA0_H_inst                                      0x0117
#define DECODE_MASK_DATA0_H_decode_mask_data0h_shift                  (0)
#define DECODE_MASK_DATA0_H_decode_mask_data0h_mask                   (0xFFFFFFFF)
#define DECODE_MASK_DATA0_H_decode_mask_data0h(data)                  (0xFFFFFFFF&(data))
#define DECODE_MASK_DATA0_H_get_decode_mask_data0h(data)              (0xFFFFFFFF&(data))


#define HW_DECODE_DATA1_L                                             0x18011460
#define HW_DECODE_DATA1_L_reg_addr                                    "0xb8011460"
#define HW_DECODE_DATA1_L_reg                                         0xb8011460
#define HW_DECODE_DATA1_L_inst_addr                                   "0x0118"
#define HW_DECODE_DATA1_L_inst                                        0x0118
#define HW_DECODE_DATA1_L_hw_decode_data1l_shift                      (0)
#define HW_DECODE_DATA1_L_hw_decode_data1l_mask                       (0xFFFFFFFF)
#define HW_DECODE_DATA1_L_hw_decode_data1l(data)                      (0xFFFFFFFF&(data))
#define HW_DECODE_DATA1_L_get_hw_decode_data1l(data)                  (0xFFFFFFFF&(data))


#define HW_DECODE_DATA1_H                                             0x18011464
#define HW_DECODE_DATA1_H_reg_addr                                    "0xb8011464"
#define HW_DECODE_DATA1_H_reg                                         0xb8011464
#define HW_DECODE_DATA1_H_inst_addr                                   "0x0119"
#define HW_DECODE_DATA1_H_inst                                        0x0119
#define HW_DECODE_DATA1_H_hw_decode_data1h_shift                      (0)
#define HW_DECODE_DATA1_H_hw_decode_data1h_mask                       (0xFFFFFFFF)
#define HW_DECODE_DATA1_H_hw_decode_data1h(data)                      (0xFFFFFFFF&(data))
#define HW_DECODE_DATA1_H_get_hw_decode_data1h(data)                  (0xFFFFFFFF&(data))


#define DECODE_MASK_DATA1_L                                           0x18011468
#define DECODE_MASK_DATA1_L_reg_addr                                  "0xb8011468"
#define DECODE_MASK_DATA1_L_reg                                       0xb8011468
#define DECODE_MASK_DATA1_L_inst_addr                                 "0x011A"
#define DECODE_MASK_DATA1_L_inst                                      0x011A
#define DECODE_MASK_DATA1_L_decode_mask_data1l_shift                  (0)
#define DECODE_MASK_DATA1_L_decode_mask_data1l_mask                   (0xFFFFFFFF)
#define DECODE_MASK_DATA1_L_decode_mask_data1l(data)                  (0xFFFFFFFF&(data))
#define DECODE_MASK_DATA1_L_get_decode_mask_data1l(data)              (0xFFFFFFFF&(data))


#define DECODE_MASK_DATA1_H                                           0x1801146c
#define DECODE_MASK_DATA1_H_reg_addr                                  "0xb801146c"
#define DECODE_MASK_DATA1_H_reg                                       0xb801146c
#define DECODE_MASK_DATA1_H_inst_addr                                 "0x011B"
#define DECODE_MASK_DATA1_H_inst                                      0x011B
#define DECODE_MASK_DATA1_H_decode_mask_data1h_shift                  (0)
#define DECODE_MASK_DATA1_H_decode_mask_data1h_mask                   (0xFFFFFFFF)
#define DECODE_MASK_DATA1_H_decode_mask_data1h(data)                  (0xFFFFFFFF&(data))
#define DECODE_MASK_DATA1_H_get_decode_mask_data1h(data)              (0xFFFFFFFF&(data))


#define HW_DECODE_DATA2_L                                             0x18011470
#define HW_DECODE_DATA2_L_reg_addr                                    "0xb8011470"
#define HW_DECODE_DATA2_L_reg                                         0xb8011470
#define HW_DECODE_DATA2_L_inst_addr                                   "0x011C"
#define HW_DECODE_DATA2_L_inst                                        0x011C
#define HW_DECODE_DATA2_L_hw_decode_data2l_shift                      (0)
#define HW_DECODE_DATA2_L_hw_decode_data2l_mask                       (0xFFFFFFFF)
#define HW_DECODE_DATA2_L_hw_decode_data2l(data)                      (0xFFFFFFFF&(data))
#define HW_DECODE_DATA2_L_get_hw_decode_data2l(data)                  (0xFFFFFFFF&(data))


#define HW_DECODE_DATA2_H                                             0x18011474
#define HW_DECODE_DATA2_H_reg_addr                                    "0xb8011474"
#define HW_DECODE_DATA2_H_reg                                         0xb8011474
#define HW_DECODE_DATA2_H_inst_addr                                   "0x011D"
#define HW_DECODE_DATA2_H_inst                                        0x011D
#define HW_DECODE_DATA2_H_hw_decode_data2h_shift                      (0)
#define HW_DECODE_DATA2_H_hw_decode_data2h_mask                       (0xFFFFFFFF)
#define HW_DECODE_DATA2_H_hw_decode_data2h(data)                      (0xFFFFFFFF&(data))
#define HW_DECODE_DATA2_H_get_hw_decode_data2h(data)                  (0xFFFFFFFF&(data))


#define DECODE_MASK_DATA2_L                                           0x18011478
#define DECODE_MASK_DATA2_L_reg_addr                                  "0xb8011478"
#define DECODE_MASK_DATA2_L_reg                                       0xb8011478
#define DECODE_MASK_DATA2_L_inst_addr                                 "0x011E"
#define DECODE_MASK_DATA2_L_inst                                      0x011E
#define DECODE_MASK_DATA2_L_decode_mask_data2l_shift                  (0)
#define DECODE_MASK_DATA2_L_decode_mask_data2l_mask                   (0xFFFFFFFF)
#define DECODE_MASK_DATA2_L_decode_mask_data2l(data)                  (0xFFFFFFFF&(data))
#define DECODE_MASK_DATA2_L_get_decode_mask_data2l(data)              (0xFFFFFFFF&(data))


#define DECODE_MASK_DATA2_H                                           0x1801147c
#define DECODE_MASK_DATA2_H_reg_addr                                  "0xb801147c"
#define DECODE_MASK_DATA2_H_reg                                       0xb801147c
#define DECODE_MASK_DATA2_H_inst_addr                                 "0x011F"
#define DECODE_MASK_DATA2_H_inst                                      0x011F
#define DECODE_MASK_DATA2_H_decode_mask_data2h_shift                  (0)
#define DECODE_MASK_DATA2_H_decode_mask_data2h_mask                   (0xFFFFFFFF)
#define DECODE_MASK_DATA2_H_decode_mask_data2h(data)                  (0xFFFFFFFF&(data))
#define DECODE_MASK_DATA2_H_get_decode_mask_data2h(data)              (0xFFFFFFFF&(data))


#define HW_DECODE_DATA3_L                                             0x18011480
#define HW_DECODE_DATA3_L_reg_addr                                    "0xb8011480"
#define HW_DECODE_DATA3_L_reg                                         0xb8011480
#define HW_DECODE_DATA3_L_inst_addr                                   "0x0120"
#define HW_DECODE_DATA3_L_inst                                        0x0120
#define HW_DECODE_DATA3_L_hw_decode_data3l_shift                      (0)
#define HW_DECODE_DATA3_L_hw_decode_data3l_mask                       (0xFFFFFFFF)
#define HW_DECODE_DATA3_L_hw_decode_data3l(data)                      (0xFFFFFFFF&(data))
#define HW_DECODE_DATA3_L_get_hw_decode_data3l(data)                  (0xFFFFFFFF&(data))


#define HW_DECODE_DATA3_H                                             0x18011484
#define HW_DECODE_DATA3_H_reg_addr                                    "0xb8011484"
#define HW_DECODE_DATA3_H_reg                                         0xb8011484
#define HW_DECODE_DATA3_H_inst_addr                                   "0x0121"
#define HW_DECODE_DATA3_H_inst                                        0x0121
#define HW_DECODE_DATA3_H_hw_decode_data3h_shift                      (0)
#define HW_DECODE_DATA3_H_hw_decode_data3h_mask                       (0xFFFFFFFF)
#define HW_DECODE_DATA3_H_hw_decode_data3h(data)                      (0xFFFFFFFF&(data))
#define HW_DECODE_DATA3_H_get_hw_decode_data3h(data)                  (0xFFFFFFFF&(data))


#define DECODE_MASK_DATA3_L                                           0x18011488
#define DECODE_MASK_DATA3_L_reg_addr                                  "0xb8011488"
#define DECODE_MASK_DATA3_L_reg                                       0xb8011488
#define DECODE_MASK_DATA3_L_inst_addr                                 "0x0122"
#define DECODE_MASK_DATA3_L_inst                                      0x0122
#define DECODE_MASK_DATA3_L_decode_mask_data3l_shift                  (0)
#define DECODE_MASK_DATA3_L_decode_mask_data3l_mask                   (0xFFFFFFFF)
#define DECODE_MASK_DATA3_L_decode_mask_data3l(data)                  (0xFFFFFFFF&(data))
#define DECODE_MASK_DATA3_L_get_decode_mask_data3l(data)              (0xFFFFFFFF&(data))


#define DECODE_MASK_DATA3_H                                           0x1801148c
#define DECODE_MASK_DATA3_H_reg_addr                                  "0xb801148c"
#define DECODE_MASK_DATA3_H_reg                                       0xb801148c
#define DECODE_MASK_DATA3_H_inst_addr                                 "0x0123"
#define DECODE_MASK_DATA3_H_inst                                      0x0123
#define DECODE_MASK_DATA3_H_decode_mask_data3h_shift                  (0)
#define DECODE_MASK_DATA3_H_decode_mask_data3h_mask                   (0xFFFFFFFF)
#define DECODE_MASK_DATA3_H_decode_mask_data3h(data)                  (0xFFFFFFFF&(data))
#define DECODE_MASK_DATA3_H_get_decode_mask_data3h(data)              (0xFFFFFFFF&(data))


#define HW_DECODE_DATA4_L                                             0x18011490
#define HW_DECODE_DATA4_L_reg_addr                                    "0xb8011490"
#define HW_DECODE_DATA4_L_reg                                         0xb8011490
#define HW_DECODE_DATA4_L_inst_addr                                   "0x0124"
#define HW_DECODE_DATA4_L_inst                                        0x0124
#define HW_DECODE_DATA4_L_hw_decode_data4l_shift                      (0)
#define HW_DECODE_DATA4_L_hw_decode_data4l_mask                       (0xFFFFFFFF)
#define HW_DECODE_DATA4_L_hw_decode_data4l(data)                      (0xFFFFFFFF&(data))
#define HW_DECODE_DATA4_L_get_hw_decode_data4l(data)                  (0xFFFFFFFF&(data))


#define HW_DECODE_DATA4_H                                             0x18011494
#define HW_DECODE_DATA4_H_reg_addr                                    "0xb8011494"
#define HW_DECODE_DATA4_H_reg                                         0xb8011494
#define HW_DECODE_DATA4_H_inst_addr                                   "0x0125"
#define HW_DECODE_DATA4_H_inst                                        0x0125
#define HW_DECODE_DATA4_H_hw_decode_data4h_shift                      (0)
#define HW_DECODE_DATA4_H_hw_decode_data4h_mask                       (0xFFFFFFFF)
#define HW_DECODE_DATA4_H_hw_decode_data4h(data)                      (0xFFFFFFFF&(data))
#define HW_DECODE_DATA4_H_get_hw_decode_data4h(data)                  (0xFFFFFFFF&(data))


#define DECODE_MASK_DATA4_L                                           0x18011498
#define DECODE_MASK_DATA4_L_reg_addr                                  "0xb8011498"
#define DECODE_MASK_DATA4_L_reg                                       0xb8011498
#define DECODE_MASK_DATA4_L_inst_addr                                 "0x0126"
#define DECODE_MASK_DATA4_L_inst                                      0x0126
#define DECODE_MASK_DATA4_L_decode_mask_data4l_shift                  (0)
#define DECODE_MASK_DATA4_L_decode_mask_data4l_mask                   (0xFFFFFFFF)
#define DECODE_MASK_DATA4_L_decode_mask_data4l(data)                  (0xFFFFFFFF&(data))
#define DECODE_MASK_DATA4_L_get_decode_mask_data4l(data)              (0xFFFFFFFF&(data))


#define DECODE_MASK_DATA4_H                                           0x1801149c
#define DECODE_MASK_DATA4_H_reg_addr                                  "0xb801149c"
#define DECODE_MASK_DATA4_H_reg                                       0xb801149c
#define DECODE_MASK_DATA4_H_inst_addr                                 "0x0127"
#define DECODE_MASK_DATA4_H_inst                                      0x0127
#define DECODE_MASK_DATA4_H_decode_mask_data4h_shift                  (0)
#define DECODE_MASK_DATA4_H_decode_mask_data4h_mask                   (0xFFFFFFFF)
#define DECODE_MASK_DATA4_H_decode_mask_data4h(data)                  (0xFFFFFFFF&(data))
#define DECODE_MASK_DATA4_H_get_decode_mask_data4h(data)              (0xFFFFFFFF&(data))


#define HW_DECODE_DATA5_L                                             0x180114a0
#define HW_DECODE_DATA5_L_reg_addr                                    "0xb80114a0"
#define HW_DECODE_DATA5_L_reg                                         0xb80114a0
#define HW_DECODE_DATA5_L_inst_addr                                   "0x0128"
#define HW_DECODE_DATA5_L_inst                                        0x0128
#define HW_DECODE_DATA5_L_hw_decode_data5l_shift                      (0)
#define HW_DECODE_DATA5_L_hw_decode_data5l_mask                       (0xFFFFFFFF)
#define HW_DECODE_DATA5_L_hw_decode_data5l(data)                      (0xFFFFFFFF&(data))
#define HW_DECODE_DATA5_L_get_hw_decode_data5l(data)                  (0xFFFFFFFF&(data))


#define HW_DECODE_DATA5_H                                             0x180114a4
#define HW_DECODE_DATA5_H_reg_addr                                    "0xb80114a4"
#define HW_DECODE_DATA5_H_reg                                         0xb80114a4
#define HW_DECODE_DATA5_H_inst_addr                                   "0x0129"
#define HW_DECODE_DATA5_H_inst                                        0x0129
#define HW_DECODE_DATA5_H_hw_decode_data5h_shift                      (0)
#define HW_DECODE_DATA5_H_hw_decode_data5h_mask                       (0xFFFFFFFF)
#define HW_DECODE_DATA5_H_hw_decode_data5h(data)                      (0xFFFFFFFF&(data))
#define HW_DECODE_DATA5_H_get_hw_decode_data5h(data)                  (0xFFFFFFFF&(data))


#define DECODE_MASK_DATA5_L                                           0x180114a8
#define DECODE_MASK_DATA5_L_reg_addr                                  "0xb80114a8"
#define DECODE_MASK_DATA5_L_reg                                       0xb80114a8
#define DECODE_MASK_DATA5_L_inst_addr                                 "0x012A"
#define DECODE_MASK_DATA5_L_inst                                      0x012A
#define DECODE_MASK_DATA5_L_decode_mask_data5l_shift                  (0)
#define DECODE_MASK_DATA5_L_decode_mask_data5l_mask                   (0xFFFFFFFF)
#define DECODE_MASK_DATA5_L_decode_mask_data5l(data)                  (0xFFFFFFFF&(data))
#define DECODE_MASK_DATA5_L_get_decode_mask_data5l(data)              (0xFFFFFFFF&(data))


#define DECODE_MASK_DATA5_H                                           0x180114ac
#define DECODE_MASK_DATA5_H_reg_addr                                  "0xb80114ac"
#define DECODE_MASK_DATA5_H_reg                                       0xb80114ac
#define DECODE_MASK_DATA5_H_inst_addr                                 "0x012B"
#define DECODE_MASK_DATA5_H_inst                                      0x012B
#define DECODE_MASK_DATA5_H_decode_mask_data5h_shift                  (0)
#define DECODE_MASK_DATA5_H_decode_mask_data5h_mask                   (0xFFFFFFFF)
#define DECODE_MASK_DATA5_H_decode_mask_data5h(data)                  (0xFFFFFFFF&(data))
#define DECODE_MASK_DATA5_H_get_decode_mask_data5h(data)              (0xFFFFFFFF&(data))


#define HW_DECODE_DATA6_L                                             0x180114b0
#define HW_DECODE_DATA6_L_reg_addr                                    "0xb80114b0"
#define HW_DECODE_DATA6_L_reg                                         0xb80114b0
#define HW_DECODE_DATA6_L_inst_addr                                   "0x012C"
#define HW_DECODE_DATA6_L_inst                                        0x012C
#define HW_DECODE_DATA6_L_hw_decode_data6l_shift                      (0)
#define HW_DECODE_DATA6_L_hw_decode_data6l_mask                       (0xFFFFFFFF)
#define HW_DECODE_DATA6_L_hw_decode_data6l(data)                      (0xFFFFFFFF&(data))
#define HW_DECODE_DATA6_L_get_hw_decode_data6l(data)                  (0xFFFFFFFF&(data))


#define HW_DECODE_DATA6_H                                             0x180114b4
#define HW_DECODE_DATA6_H_reg_addr                                    "0xb80114b4"
#define HW_DECODE_DATA6_H_reg                                         0xb80114b4
#define HW_DECODE_DATA6_H_inst_addr                                   "0x012D"
#define HW_DECODE_DATA6_H_inst                                        0x012D
#define HW_DECODE_DATA6_H_hw_decode_data6h_shift                      (0)
#define HW_DECODE_DATA6_H_hw_decode_data6h_mask                       (0xFFFFFFFF)
#define HW_DECODE_DATA6_H_hw_decode_data6h(data)                      (0xFFFFFFFF&(data))
#define HW_DECODE_DATA6_H_get_hw_decode_data6h(data)                  (0xFFFFFFFF&(data))


#define DECODE_MASK_DATA6_L                                           0x180114b8
#define DECODE_MASK_DATA6_L_reg_addr                                  "0xb80114b8"
#define DECODE_MASK_DATA6_L_reg                                       0xb80114b8
#define DECODE_MASK_DATA6_L_inst_addr                                 "0x012E"
#define DECODE_MASK_DATA6_L_inst                                      0x012E
#define DECODE_MASK_DATA6_L_decode_mask_data6l_shift                  (0)
#define DECODE_MASK_DATA6_L_decode_mask_data6l_mask                   (0xFFFFFFFF)
#define DECODE_MASK_DATA6_L_decode_mask_data6l(data)                  (0xFFFFFFFF&(data))
#define DECODE_MASK_DATA6_L_get_decode_mask_data6l(data)              (0xFFFFFFFF&(data))


#define DECODE_MASK_DATA6_H                                           0x180114bc
#define DECODE_MASK_DATA6_H_reg_addr                                  "0xb80114bc"
#define DECODE_MASK_DATA6_H_reg                                       0xb80114bc
#define DECODE_MASK_DATA6_H_inst_addr                                 "0x012F"
#define DECODE_MASK_DATA6_H_inst                                      0x012F
#define DECODE_MASK_DATA6_H_decode_mask_data6h_shift                  (0)
#define DECODE_MASK_DATA6_H_decode_mask_data6h_mask                   (0xFFFFFFFF)
#define DECODE_MASK_DATA6_H_decode_mask_data6h(data)                  (0xFFFFFFFF&(data))
#define DECODE_MASK_DATA6_H_get_decode_mask_data6h(data)              (0xFFFFFFFF&(data))


#define HW_DECODE_DATA7_L                                             0x180114c0
#define HW_DECODE_DATA7_L_reg_addr                                    "0xb80114c0"
#define HW_DECODE_DATA7_L_reg                                         0xb80114c0
#define HW_DECODE_DATA7_L_inst_addr                                   "0x0130"
#define HW_DECODE_DATA7_L_inst                                        0x0130
#define HW_DECODE_DATA7_L_hw_decode_data7l_shift                      (0)
#define HW_DECODE_DATA7_L_hw_decode_data7l_mask                       (0xFFFFFFFF)
#define HW_DECODE_DATA7_L_hw_decode_data7l(data)                      (0xFFFFFFFF&(data))
#define HW_DECODE_DATA7_L_get_hw_decode_data7l(data)                  (0xFFFFFFFF&(data))


#define HW_DECODE_DATA7_H                                             0x180114c4
#define HW_DECODE_DATA7_H_reg_addr                                    "0xb80114c4"
#define HW_DECODE_DATA7_H_reg                                         0xb80114c4
#define HW_DECODE_DATA7_H_inst_addr                                   "0x0131"
#define HW_DECODE_DATA7_H_inst                                        0x0131
#define HW_DECODE_DATA7_H_hw_decode_data7h_shift                      (0)
#define HW_DECODE_DATA7_H_hw_decode_data7h_mask                       (0xFFFFFFFF)
#define HW_DECODE_DATA7_H_hw_decode_data7h(data)                      (0xFFFFFFFF&(data))
#define HW_DECODE_DATA7_H_get_hw_decode_data7h(data)                  (0xFFFFFFFF&(data))


#define DECODE_MASK_DATA7_L                                           0x180114c8
#define DECODE_MASK_DATA7_L_reg_addr                                  "0xb80114c8"
#define DECODE_MASK_DATA7_L_reg                                       0xb80114c8
#define DECODE_MASK_DATA7_L_inst_addr                                 "0x0132"
#define DECODE_MASK_DATA7_L_inst                                      0x0132
#define DECODE_MASK_DATA7_L_decode_mask_data7l_shift                  (0)
#define DECODE_MASK_DATA7_L_decode_mask_data7l_mask                   (0xFFFFFFFF)
#define DECODE_MASK_DATA7_L_decode_mask_data7l(data)                  (0xFFFFFFFF&(data))
#define DECODE_MASK_DATA7_L_get_decode_mask_data7l(data)              (0xFFFFFFFF&(data))


#define DECODE_MASK_DATA7_H                                           0x180114cc
#define DECODE_MASK_DATA7_H_reg_addr                                  "0xb80114cc"
#define DECODE_MASK_DATA7_H_reg                                       0xb80114cc
#define DECODE_MASK_DATA7_H_inst_addr                                 "0x0133"
#define DECODE_MASK_DATA7_H_inst                                      0x0133
#define DECODE_MASK_DATA7_H_decode_mask_data7h_shift                  (0)
#define DECODE_MASK_DATA7_H_decode_mask_data7h_mask                   (0xFFFFFFFF)
#define DECODE_MASK_DATA7_H_decode_mask_data7h(data)                  (0xFFFFFFFF&(data))
#define DECODE_MASK_DATA7_H_get_decode_mask_data7h(data)              (0xFFFFFFFF&(data))


#define INT_CTRL                                                      0x180114d0
#define INT_CTRL_reg_addr                                             "0xb80114d0"
#define INT_CTRL_reg                                                  0xb80114d0
#define INT_CTRL_inst_addr                                            "0x0134"
#define INT_CTRL_inst                                                 0x0134
#define INT_CTRL_compare7_enable_shift                                (31)
#define INT_CTRL_compare6_enable_shift                                (30)
#define INT_CTRL_compare5_enable_shift                                (29)
#define INT_CTRL_compare4_enable_shift                                (28)
#define INT_CTRL_compare3_enable_shift                                (27)
#define INT_CTRL_compare2_enable_shift                                (26)
#define INT_CTRL_compare1_enable_shift                                (25)
#define INT_CTRL_compare0_enable_shift                                (24)
#define INT_CTRL_int_latchdata_shift                                  (16)
#define INT_CTRL_compare7_int_en_shift                                (15)
#define INT_CTRL_compare6_int_en_shift                                (14)
#define INT_CTRL_compare5_int_en_shift                                (13)
#define INT_CTRL_compare4_int_en_shift                                (12)
#define INT_CTRL_compare3_int_en_shift                                (11)
#define INT_CTRL_compare2_int_en_shift                                (10)
#define INT_CTRL_compare1_int_en_shift                                (9)
#define INT_CTRL_compare0_int_en_shift                                (8)
#define INT_CTRL_compare7_int_status_shift                            (7)
#define INT_CTRL_compare6_int_status_shift                            (6)
#define INT_CTRL_compare5_int_status_shift                            (5)
#define INT_CTRL_compare4_int_status_shift                            (4)
#define INT_CTRL_compare3_int_status_shift                            (3)
#define INT_CTRL_compare2_int_status_shift                            (2)
#define INT_CTRL_compare1_int_status_shift                            (1)
#define INT_CTRL_compare0_int_status_shift                            (0)
#define INT_CTRL_compare7_enable_mask                                 (0x80000000)
#define INT_CTRL_compare6_enable_mask                                 (0x40000000)
#define INT_CTRL_compare5_enable_mask                                 (0x20000000)
#define INT_CTRL_compare4_enable_mask                                 (0x10000000)
#define INT_CTRL_compare3_enable_mask                                 (0x08000000)
#define INT_CTRL_compare2_enable_mask                                 (0x04000000)
#define INT_CTRL_compare1_enable_mask                                 (0x02000000)
#define INT_CTRL_compare0_enable_mask                                 (0x01000000)
#define INT_CTRL_int_latchdata_mask                                   (0x00FF0000)
#define INT_CTRL_compare7_int_en_mask                                 (0x00008000)
#define INT_CTRL_compare6_int_en_mask                                 (0x00004000)
#define INT_CTRL_compare5_int_en_mask                                 (0x00002000)
#define INT_CTRL_compare4_int_en_mask                                 (0x00001000)
#define INT_CTRL_compare3_int_en_mask                                 (0x00000800)
#define INT_CTRL_compare2_int_en_mask                                 (0x00000400)
#define INT_CTRL_compare1_int_en_mask                                 (0x00000200)
#define INT_CTRL_compare0_int_en_mask                                 (0x00000100)
#define INT_CTRL_compare7_int_status_mask                             (0x00000080)
#define INT_CTRL_compare6_int_status_mask                             (0x00000040)
#define INT_CTRL_compare5_int_status_mask                             (0x00000020)
#define INT_CTRL_compare4_int_status_mask                             (0x00000010)
#define INT_CTRL_compare3_int_status_mask                             (0x00000008)
#define INT_CTRL_compare2_int_status_mask                             (0x00000004)
#define INT_CTRL_compare1_int_status_mask                             (0x00000002)
#define INT_CTRL_compare0_int_status_mask                             (0x00000001)
#define INT_CTRL_compare7_enable(data)                                (0x80000000&((data)<<31))
#define INT_CTRL_compare6_enable(data)                                (0x40000000&((data)<<30))
#define INT_CTRL_compare5_enable(data)                                (0x20000000&((data)<<29))
#define INT_CTRL_compare4_enable(data)                                (0x10000000&((data)<<28))
#define INT_CTRL_compare3_enable(data)                                (0x08000000&((data)<<27))
#define INT_CTRL_compare2_enable(data)                                (0x04000000&((data)<<26))
#define INT_CTRL_compare1_enable(data)                                (0x02000000&((data)<<25))
#define INT_CTRL_compare0_enable(data)                                (0x01000000&((data)<<24))
#define INT_CTRL_int_latchdata(data)                                  (0x00FF0000&((data)<<16))
#define INT_CTRL_compare7_int_en(data)                                (0x00008000&((data)<<15))
#define INT_CTRL_compare6_int_en(data)                                (0x00004000&((data)<<14))
#define INT_CTRL_compare5_int_en(data)                                (0x00002000&((data)<<13))
#define INT_CTRL_compare4_int_en(data)                                (0x00001000&((data)<<12))
#define INT_CTRL_compare3_int_en(data)                                (0x00000800&((data)<<11))
#define INT_CTRL_compare2_int_en(data)                                (0x00000400&((data)<<10))
#define INT_CTRL_compare1_int_en(data)                                (0x00000200&((data)<<9))
#define INT_CTRL_compare0_int_en(data)                                (0x00000100&((data)<<8))
#define INT_CTRL_compare7_int_status(data)                            (0x00000080&((data)<<7))
#define INT_CTRL_compare6_int_status(data)                            (0x00000040&((data)<<6))
#define INT_CTRL_compare5_int_status(data)                            (0x00000020&((data)<<5))
#define INT_CTRL_compare4_int_status(data)                            (0x00000010&((data)<<4))
#define INT_CTRL_compare3_int_status(data)                            (0x00000008&((data)<<3))
#define INT_CTRL_compare2_int_status(data)                            (0x00000004&((data)<<2))
#define INT_CTRL_compare1_int_status(data)                            (0x00000002&((data)<<1))
#define INT_CTRL_compare0_int_status(data)                            (0x00000001&(data))
#define INT_CTRL_get_compare7_enable(data)                            ((0x80000000&(data))>>31)
#define INT_CTRL_get_compare6_enable(data)                            ((0x40000000&(data))>>30)
#define INT_CTRL_get_compare5_enable(data)                            ((0x20000000&(data))>>29)
#define INT_CTRL_get_compare4_enable(data)                            ((0x10000000&(data))>>28)
#define INT_CTRL_get_compare3_enable(data)                            ((0x08000000&(data))>>27)
#define INT_CTRL_get_compare2_enable(data)                            ((0x04000000&(data))>>26)
#define INT_CTRL_get_compare1_enable(data)                            ((0x02000000&(data))>>25)
#define INT_CTRL_get_compare0_enable(data)                            ((0x01000000&(data))>>24)
#define INT_CTRL_get_int_latchdata(data)                              ((0x00FF0000&(data))>>16)
#define INT_CTRL_get_compare7_int_en(data)                            ((0x00008000&(data))>>15)
#define INT_CTRL_get_compare6_int_en(data)                            ((0x00004000&(data))>>14)
#define INT_CTRL_get_compare5_int_en(data)                            ((0x00002000&(data))>>13)
#define INT_CTRL_get_compare4_int_en(data)                            ((0x00001000&(data))>>12)
#define INT_CTRL_get_compare3_int_en(data)                            ((0x00000800&(data))>>11)
#define INT_CTRL_get_compare2_int_en(data)                            ((0x00000400&(data))>>10)
#define INT_CTRL_get_compare1_int_en(data)                            ((0x00000200&(data))>>9)
#define INT_CTRL_get_compare0_int_en(data)                            ((0x00000100&(data))>>8)
#define INT_CTRL_get_compare7_int_status(data)                        ((0x00000080&(data))>>7)
#define INT_CTRL_get_compare6_int_status(data)                        ((0x00000040&(data))>>6)
#define INT_CTRL_get_compare5_int_status(data)                        ((0x00000020&(data))>>5)
#define INT_CTRL_get_compare4_int_status(data)                        ((0x00000010&(data))>>4)
#define INT_CTRL_get_compare3_int_status(data)                        ((0x00000008&(data))>>3)
#define INT_CTRL_get_compare2_int_status(data)                        ((0x00000004&(data))>>2)
#define INT_CTRL_get_compare1_int_status(data)                        ((0x00000002&(data))>>1)
#define INT_CTRL_get_compare0_int_status(data)                        (0x00000001&(data))


#define TEST_MODE_CTRL                                                0x180114d4
#define TEST_MODE_CTRL_reg_addr                                       "0xb80114d4"
#define TEST_MODE_CTRL_reg                                            0xb80114d4
#define TEST_MODE_CTRL_inst_addr                                      "0x0135"
#define TEST_MODE_CTRL_inst                                           0x0135
#define TEST_MODE_CTRL_test_mode_en_shift                             (0)
#define TEST_MODE_CTRL_test_mode_en_mask                              (0x00000001)
#define TEST_MODE_CTRL_test_mode_en(data)                             (0x00000001&(data))
#define TEST_MODE_CTRL_get_test_mode_en(data)                         (0x00000001&(data))


#define TEST_MODE_DATA0                                               0x180114d8
#define TEST_MODE_DATA0_reg_addr                                      "0xb80114d8"
#define TEST_MODE_DATA0_reg                                           0xb80114d8
#define TEST_MODE_DATA0_inst_addr                                     "0x0136"
#define TEST_MODE_DATA0_inst                                          0x0136
#define TEST_MODE_DATA0_test_mode_datal_shift                         (0)
#define TEST_MODE_DATA0_test_mode_datal_mask                          (0xFFFFFFFF)
#define TEST_MODE_DATA0_test_mode_datal(data)                         (0xFFFFFFFF&(data))
#define TEST_MODE_DATA0_get_test_mode_datal(data)                     (0xFFFFFFFF&(data))


#define TEST_MODE_DATA1                                               0x180114dc
#define TEST_MODE_DATA1_reg_addr                                      "0xb80114dc"
#define TEST_MODE_DATA1_reg                                           0xb80114dc
#define TEST_MODE_DATA1_inst_addr                                     "0x0137"
#define TEST_MODE_DATA1_inst                                          0x0137
#define TEST_MODE_DATA1_test_mode_datah_shift                         (0)
#define TEST_MODE_DATA1_test_mode_datah_mask                          (0xFFFFFFFF)
#define TEST_MODE_DATA1_test_mode_datah(data)                         (0xFFFFFFFF&(data))
#define TEST_MODE_DATA1_get_test_mode_datah(data)                     (0xFFFFFFFF&(data))


#define ST_PAD0                                                       0x18011500
#define ST_PAD0_reg_addr                                              "0xb8011500"
#define ST_PAD0_reg                                                   0xb8011500
#define ST_PAD0_inst_addr                                             "0x0140"
#define ST_PAD0_inst                                                  0x0140
#define ST_PAD0_pad0_active_shift                                     (31)
#define ST_PAD0_pad0_thred_shift                                      (16)
#define ST_PAD0_pad0_sw_shift                                         (12)
#define ST_PAD0_pad0_ctrl_shift                                       (8)
#define ST_PAD0_adc_val0_shift                                        (0)
#define ST_PAD0_pad0_active_mask                                      (0x80000000)
#define ST_PAD0_pad0_thred_mask                                       (0x00FF0000)
#define ST_PAD0_pad0_sw_mask                                          (0x0000F000)
#define ST_PAD0_pad0_ctrl_mask                                        (0x00000100)
#define ST_PAD0_adc_val0_mask                                         (0x000000FF)
#define ST_PAD0_pad0_active(data)                                     (0x80000000&((data)<<31))
#define ST_PAD0_pad0_thred(data)                                      (0x00FF0000&((data)<<16))
#define ST_PAD0_pad0_sw(data)                                         (0x0000F000&((data)<<12))
#define ST_PAD0_pad0_ctrl(data)                                       (0x00000100&((data)<<8))
#define ST_PAD0_adc_val0(data)                                        (0x000000FF&(data))
#define ST_PAD0_get_pad0_active(data)                                 ((0x80000000&(data))>>31)
#define ST_PAD0_get_pad0_thred(data)                                  ((0x00FF0000&(data))>>16)
#define ST_PAD0_get_pad0_sw(data)                                     ((0x0000F000&(data))>>12)
#define ST_PAD0_get_pad0_ctrl(data)                                   ((0x00000100&(data))>>8)
#define ST_PAD0_get_adc_val0(data)                                    (0x000000FF&(data))


#define ST_PAD1                                                       0x18011504
#define ST_PAD1_reg_addr                                              "0xb8011504"
#define ST_PAD1_reg                                                   0xb8011504
#define ST_PAD1_inst_addr                                             "0x0141"
#define ST_PAD1_inst                                                  0x0141
#define ST_PAD1_pad1_active_shift                                     (31)
#define ST_PAD1_pad1_thred_shift                                      (16)
#define ST_PAD1_pad1_sw_shift                                         (12)
#define ST_PAD1_pad1_ctrl_shift                                       (8)
#define ST_PAD1_adc_val1_shift                                        (0)
#define ST_PAD1_pad1_active_mask                                      (0x80000000)
#define ST_PAD1_pad1_thred_mask                                       (0x00FF0000)
#define ST_PAD1_pad1_sw_mask                                          (0x0000F000)
#define ST_PAD1_pad1_ctrl_mask                                        (0x00000100)
#define ST_PAD1_adc_val1_mask                                         (0x000000FF)
#define ST_PAD1_pad1_active(data)                                     (0x80000000&((data)<<31))
#define ST_PAD1_pad1_thred(data)                                      (0x00FF0000&((data)<<16))
#define ST_PAD1_pad1_sw(data)                                         (0x0000F000&((data)<<12))
#define ST_PAD1_pad1_ctrl(data)                                       (0x00000100&((data)<<8))
#define ST_PAD1_adc_val1(data)                                        (0x000000FF&(data))
#define ST_PAD1_get_pad1_active(data)                                 ((0x80000000&(data))>>31)
#define ST_PAD1_get_pad1_thred(data)                                  ((0x00FF0000&(data))>>16)
#define ST_PAD1_get_pad1_sw(data)                                     ((0x0000F000&(data))>>12)
#define ST_PAD1_get_pad1_ctrl(data)                                   ((0x00000100&(data))>>8)
#define ST_PAD1_get_adc_val1(data)                                    (0x000000FF&(data))


#define ST_PAD2                                                       0x18011508
#define ST_PAD2_reg_addr                                              "0xb8011508"
#define ST_PAD2_reg                                                   0xb8011508
#define ST_PAD2_inst_addr                                             "0x0142"
#define ST_PAD2_inst                                                  0x0142
#define ST_PAD2_pad2_active_shift                                     (31)
#define ST_PAD2_pad2_thred_shift                                      (16)
#define ST_PAD2_pad2_sw_shift                                         (12)
#define ST_PAD2_pad2_ctrl_shift                                       (8)
#define ST_PAD2_adc_val2_shift                                        (0)
#define ST_PAD2_pad2_active_mask                                      (0x80000000)
#define ST_PAD2_pad2_thred_mask                                       (0x00FF0000)
#define ST_PAD2_pad2_sw_mask                                          (0x0000F000)
#define ST_PAD2_pad2_ctrl_mask                                        (0x00000100)
#define ST_PAD2_adc_val2_mask                                         (0x000000FF)
#define ST_PAD2_pad2_active(data)                                     (0x80000000&((data)<<31))
#define ST_PAD2_pad2_thred(data)                                      (0x00FF0000&((data)<<16))
#define ST_PAD2_pad2_sw(data)                                         (0x0000F000&((data)<<12))
#define ST_PAD2_pad2_ctrl(data)                                       (0x00000100&((data)<<8))
#define ST_PAD2_adc_val2(data)                                        (0x000000FF&(data))
#define ST_PAD2_get_pad2_active(data)                                 ((0x80000000&(data))>>31)
#define ST_PAD2_get_pad2_thred(data)                                  ((0x00FF0000&(data))>>16)
#define ST_PAD2_get_pad2_sw(data)                                     ((0x0000F000&(data))>>12)
#define ST_PAD2_get_pad2_ctrl(data)                                   ((0x00000100&(data))>>8)
#define ST_PAD2_get_adc_val2(data)                                    (0x000000FF&(data))


#define ST_PAD3                                                       0x1801150c
#define ST_PAD3_reg_addr                                              "0xb801150c"
#define ST_PAD3_reg                                                   0xb801150c
#define ST_PAD3_inst_addr                                             "0x0143"
#define ST_PAD3_inst                                                  0x0143
#define ST_PAD3_pad3_active_shift                                     (31)
#define ST_PAD3_pad3_thred_shift                                      (16)
#define ST_PAD3_pad3_sw_shift                                         (12)
#define ST_PAD3_pad3_ctrl_shift                                       (8)
#define ST_PAD3_adc_val3_shift                                        (0)
#define ST_PAD3_pad3_active_mask                                      (0x80000000)
#define ST_PAD3_pad3_thred_mask                                       (0x00FF0000)
#define ST_PAD3_pad3_sw_mask                                          (0x0000F000)
#define ST_PAD3_pad3_ctrl_mask                                        (0x00000100)
#define ST_PAD3_adc_val3_mask                                         (0x000000FF)
#define ST_PAD3_pad3_active(data)                                     (0x80000000&((data)<<31))
#define ST_PAD3_pad3_thred(data)                                      (0x00FF0000&((data)<<16))
#define ST_PAD3_pad3_sw(data)                                         (0x0000F000&((data)<<12))
#define ST_PAD3_pad3_ctrl(data)                                       (0x00000100&((data)<<8))
#define ST_PAD3_adc_val3(data)                                        (0x000000FF&(data))
#define ST_PAD3_get_pad3_active(data)                                 ((0x80000000&(data))>>31)
#define ST_PAD3_get_pad3_thred(data)                                  ((0x00FF0000&(data))>>16)
#define ST_PAD3_get_pad3_sw(data)                                     ((0x0000F000&(data))>>12)
#define ST_PAD3_get_pad3_ctrl(data)                                   ((0x00000100&(data))>>8)
#define ST_PAD3_get_adc_val3(data)                                    (0x000000FF&(data))


#define ST_PAD4                                                       0x18011510
#define ST_PAD4_reg_addr                                              "0xb8011510"
#define ST_PAD4_reg                                                   0xb8011510
#define ST_PAD4_inst_addr                                             "0x0144"
#define ST_PAD4_inst                                                  0x0144
#define ST_PAD4_pad4_active_shift                                     (31)
#define ST_PAD4_pad4_thred_shift                                      (16)
#define ST_PAD4_pad4_sw_shift                                         (12)
#define ST_PAD4_pad4_ctrl_shift                                       (8)
#define ST_PAD4_adc_val4_shift                                        (0)
#define ST_PAD4_pad4_active_mask                                      (0x80000000)
#define ST_PAD4_pad4_thred_mask                                       (0x00FF0000)
#define ST_PAD4_pad4_sw_mask                                          (0x0000F000)
#define ST_PAD4_pad4_ctrl_mask                                        (0x00000100)
#define ST_PAD4_adc_val4_mask                                         (0x000000FF)
#define ST_PAD4_pad4_active(data)                                     (0x80000000&((data)<<31))
#define ST_PAD4_pad4_thred(data)                                      (0x00FF0000&((data)<<16))
#define ST_PAD4_pad4_sw(data)                                         (0x0000F000&((data)<<12))
#define ST_PAD4_pad4_ctrl(data)                                       (0x00000100&((data)<<8))
#define ST_PAD4_adc_val4(data)                                        (0x000000FF&(data))
#define ST_PAD4_get_pad4_active(data)                                 ((0x80000000&(data))>>31)
#define ST_PAD4_get_pad4_thred(data)                                  ((0x00FF0000&(data))>>16)
#define ST_PAD4_get_pad4_sw(data)                                     ((0x0000F000&(data))>>12)
#define ST_PAD4_get_pad4_ctrl(data)                                   ((0x00000100&(data))>>8)
#define ST_PAD4_get_adc_val4(data)                                    (0x000000FF&(data))


#define ST_PAD5                                                       0x18011514
#define ST_PAD5_reg_addr                                              "0xb8011514"
#define ST_PAD5_reg                                                   0xb8011514
#define ST_PAD5_inst_addr                                             "0x0145"
#define ST_PAD5_inst                                                  0x0145
#define ST_PAD5_pad5_active_shift                                     (31)
#define ST_PAD5_pad5_thred_shift                                      (16)
#define ST_PAD5_pad5_sw_shift                                         (12)
#define ST_PAD5_pad5_ctrl_shift                                       (8)
#define ST_PAD5_adc_val5_shift                                        (0)
#define ST_PAD5_pad5_active_mask                                      (0x80000000)
#define ST_PAD5_pad5_thred_mask                                       (0x00FF0000)
#define ST_PAD5_pad5_sw_mask                                          (0x0000F000)
#define ST_PAD5_pad5_ctrl_mask                                        (0x00000100)
#define ST_PAD5_adc_val5_mask                                         (0x000000FF)
#define ST_PAD5_pad5_active(data)                                     (0x80000000&((data)<<31))
#define ST_PAD5_pad5_thred(data)                                      (0x00FF0000&((data)<<16))
#define ST_PAD5_pad5_sw(data)                                         (0x0000F000&((data)<<12))
#define ST_PAD5_pad5_ctrl(data)                                       (0x00000100&((data)<<8))
#define ST_PAD5_adc_val5(data)                                        (0x000000FF&(data))
#define ST_PAD5_get_pad5_active(data)                                 ((0x80000000&(data))>>31)
#define ST_PAD5_get_pad5_thred(data)                                  ((0x00FF0000&(data))>>16)
#define ST_PAD5_get_pad5_sw(data)                                     ((0x0000F000&(data))>>12)
#define ST_PAD5_get_pad5_ctrl(data)                                   ((0x00000100&(data))>>8)
#define ST_PAD5_get_adc_val5(data)                                    (0x000000FF&(data))


#define ST_PAD6                                                       0x18011518
#define ST_PAD6_reg_addr                                              "0xb8011518"
#define ST_PAD6_reg                                                   0xb8011518
#define ST_PAD6_inst_addr                                             "0x0146"
#define ST_PAD6_inst                                                  0x0146
#define ST_PAD6_pad6_active_shift                                     (31)
#define ST_PAD6_pad6_thred_shift                                      (16)
#define ST_PAD6_pad6_sw_shift                                         (12)
#define ST_PAD6_pad6_ctrl_shift                                       (8)
#define ST_PAD6_adc_val6_shift                                        (0)
#define ST_PAD6_pad6_active_mask                                      (0x80000000)
#define ST_PAD6_pad6_thred_mask                                       (0x00FF0000)
#define ST_PAD6_pad6_sw_mask                                          (0x0000F000)
#define ST_PAD6_pad6_ctrl_mask                                        (0x00000100)
#define ST_PAD6_adc_val6_mask                                         (0x000000FF)
#define ST_PAD6_pad6_active(data)                                     (0x80000000&((data)<<31))
#define ST_PAD6_pad6_thred(data)                                      (0x00FF0000&((data)<<16))
#define ST_PAD6_pad6_sw(data)                                         (0x0000F000&((data)<<12))
#define ST_PAD6_pad6_ctrl(data)                                       (0x00000100&((data)<<8))
#define ST_PAD6_adc_val6(data)                                        (0x000000FF&(data))
#define ST_PAD6_get_pad6_active(data)                                 ((0x80000000&(data))>>31)
#define ST_PAD6_get_pad6_thred(data)                                  ((0x00FF0000&(data))>>16)
#define ST_PAD6_get_pad6_sw(data)                                     ((0x0000F000&(data))>>12)
#define ST_PAD6_get_pad6_ctrl(data)                                   ((0x00000100&(data))>>8)
#define ST_PAD6_get_adc_val6(data)                                    (0x000000FF&(data))


#define ST_PAD7                                                       0x1801151c
#define ST_PAD7_reg_addr                                              "0xb801151c"
#define ST_PAD7_reg                                                   0xb801151c
#define ST_PAD7_inst_addr                                             "0x0147"
#define ST_PAD7_inst                                                  0x0147
#define ST_PAD7_pad7_active_shift                                     (31)
#define ST_PAD7_pad7_thred_shift                                      (16)
#define ST_PAD7_pad7_sw_shift                                         (12)
#define ST_PAD7_pad7_ctrl_shift                                       (8)
#define ST_PAD7_adc_val7_shift                                        (0)
#define ST_PAD7_pad7_active_mask                                      (0x80000000)
#define ST_PAD7_pad7_thred_mask                                       (0x00FF0000)
#define ST_PAD7_pad7_sw_mask                                          (0x0000F000)
#define ST_PAD7_pad7_ctrl_mask                                        (0x00000100)
#define ST_PAD7_adc_val7_mask                                         (0x000000FF)
#define ST_PAD7_pad7_active(data)                                     (0x80000000&((data)<<31))
#define ST_PAD7_pad7_thred(data)                                      (0x00FF0000&((data)<<16))
#define ST_PAD7_pad7_sw(data)                                         (0x0000F000&((data)<<12))
#define ST_PAD7_pad7_ctrl(data)                                       (0x00000100&((data)<<8))
#define ST_PAD7_adc_val7(data)                                        (0x000000FF&(data))
#define ST_PAD7_get_pad7_active(data)                                 ((0x80000000&(data))>>31)
#define ST_PAD7_get_pad7_thred(data)                                  ((0x00FF0000&(data))>>16)
#define ST_PAD7_get_pad7_sw(data)                                     ((0x0000F000&(data))>>12)
#define ST_PAD7_get_pad7_ctrl(data)                                   ((0x00000100&(data))>>8)
#define ST_PAD7_get_adc_val7(data)                                    (0x000000FF&(data))


#define ST_LSADC_CTRL                                                 0x18011520
#define ST_LSADC_CTRL_reg_addr                                        "0xb8011520"
#define ST_LSADC_CTRL_reg                                             0xb8011520
#define ST_LSADC_CTRL_inst_addr                                       "0x0148"
#define ST_LSADC_CTRL_inst                                            0x0148
#define ST_LSADC_CTRL_sel_wait_shift                                  (28)
#define ST_LSADC_CTRL_sel_adc_ck_shift                                (24)
#define ST_LSADC_CTRL_debounce_cnt_shift                              (20)
#define ST_LSADC_CTRL_dout_test_in_shift                              (8)
#define ST_LSADC_CTRL_test_en_shift                                   (1)
#define ST_LSADC_CTRL_enable_shift                                    (0)
#define ST_LSADC_CTRL_sel_wait_mask                                   (0xF0000000)
#define ST_LSADC_CTRL_sel_adc_ck_mask                                 (0x0F000000)
#define ST_LSADC_CTRL_debounce_cnt_mask                               (0x00F00000)
#define ST_LSADC_CTRL_dout_test_in_mask                               (0x0000FF00)
#define ST_LSADC_CTRL_test_en_mask                                    (0x00000002)
#define ST_LSADC_CTRL_enable_mask                                     (0x00000001)
#define ST_LSADC_CTRL_sel_wait(data)                                  (0xF0000000&((data)<<28))
#define ST_LSADC_CTRL_sel_adc_ck(data)                                (0x0F000000&((data)<<24))
#define ST_LSADC_CTRL_debounce_cnt(data)                              (0x00F00000&((data)<<20))
#define ST_LSADC_CTRL_dout_test_in(data)                              (0x0000FF00&((data)<<8))
#define ST_LSADC_CTRL_test_en(data)                                   (0x00000002&((data)<<1))
#define ST_LSADC_CTRL_enable(data)                                    (0x00000001&(data))
#define ST_LSADC_CTRL_get_sel_wait(data)                              ((0xF0000000&(data))>>28)
#define ST_LSADC_CTRL_get_sel_adc_ck(data)                            ((0x0F000000&(data))>>24)
#define ST_LSADC_CTRL_get_debounce_cnt(data)                          ((0x00F00000&(data))>>20)
#define ST_LSADC_CTRL_get_dout_test_in(data)                          ((0x0000FF00&(data))>>8)
#define ST_LSADC_CTRL_get_test_en(data)                               ((0x00000002&(data))>>1)
#define ST_LSADC_CTRL_get_enable(data)                                (0x00000001&(data))


#define ST_LSADC_STATUS                                               0x18011524
#define ST_LSADC_STATUS_reg_addr                                      "0xb8011524"
#define ST_LSADC_STATUS_reg                                           0xb8011524
#define ST_LSADC_STATUS_inst_addr                                     "0x0149"
#define ST_LSADC_STATUS_inst                                          0x0149
#define ST_LSADC_STATUS_irq_en_shift                                  (24)
#define ST_LSADC_STATUS_pad_cnt_shift                                 (20)
#define ST_LSADC_STATUS_adc_busy_shift                                (19)
#define ST_LSADC_STATUS_pad_ctrl_shift                                (12)
#define ST_LSADC_STATUS_pad7_status_shift                             (7)
#define ST_LSADC_STATUS_pad6_status_shift                             (6)
#define ST_LSADC_STATUS_pad5_status_shift                             (5)
#define ST_LSADC_STATUS_pad4_status_shift                             (4)
#define ST_LSADC_STATUS_pad3_status_shift                             (3)
#define ST_LSADC_STATUS_pad2_status_shift                             (2)
#define ST_LSADC_STATUS_pad1_status_shift                             (1)
#define ST_LSADC_STATUS_pad0_status_shift                             (0)
#define ST_LSADC_STATUS_irq_en_mask                                   (0xFF000000)
#define ST_LSADC_STATUS_pad_cnt_mask                                  (0x00F00000)
#define ST_LSADC_STATUS_adc_busy_mask                                 (0x00080000)
#define ST_LSADC_STATUS_pad_ctrl_mask                                 (0x0001F000)
#define ST_LSADC_STATUS_pad7_status_mask                              (0x00000080)
#define ST_LSADC_STATUS_pad6_status_mask                              (0x00000040)
#define ST_LSADC_STATUS_pad5_status_mask                              (0x00000020)
#define ST_LSADC_STATUS_pad4_status_mask                              (0x00000010)
#define ST_LSADC_STATUS_pad3_status_mask                              (0x00000008)
#define ST_LSADC_STATUS_pad2_status_mask                              (0x00000004)
#define ST_LSADC_STATUS_pad1_status_mask                              (0x00000002)
#define ST_LSADC_STATUS_pad0_status_mask                              (0x00000001)
#define ST_LSADC_STATUS_irq_en(data)                                  (0xFF000000&((data)<<24))
#define ST_LSADC_STATUS_pad_cnt(data)                                 (0x00F00000&((data)<<20))
#define ST_LSADC_STATUS_adc_busy(data)                                (0x00080000&((data)<<19))
#define ST_LSADC_STATUS_pad_ctrl(data)                                (0x0001F000&((data)<<12))
#define ST_LSADC_STATUS_pad7_status(data)                             (0x00000080&((data)<<7))
#define ST_LSADC_STATUS_pad6_status(data)                             (0x00000040&((data)<<6))
#define ST_LSADC_STATUS_pad5_status(data)                             (0x00000020&((data)<<5))
#define ST_LSADC_STATUS_pad4_status(data)                             (0x00000010&((data)<<4))
#define ST_LSADC_STATUS_pad3_status(data)                             (0x00000008&((data)<<3))
#define ST_LSADC_STATUS_pad2_status(data)                             (0x00000004&((data)<<2))
#define ST_LSADC_STATUS_pad1_status(data)                             (0x00000002&((data)<<1))
#define ST_LSADC_STATUS_pad0_status(data)                             (0x00000001&(data))
#define ST_LSADC_STATUS_get_irq_en(data)                              ((0xFF000000&(data))>>24)
#define ST_LSADC_STATUS_get_pad_cnt(data)                             ((0x00F00000&(data))>>20)
#define ST_LSADC_STATUS_get_adc_busy(data)                            ((0x00080000&(data))>>19)
#define ST_LSADC_STATUS_get_pad_ctrl(data)                            ((0x0001F000&(data))>>12)
#define ST_LSADC_STATUS_get_pad7_status(data)                         ((0x00000080&(data))>>7)
#define ST_LSADC_STATUS_get_pad6_status(data)                         ((0x00000040&(data))>>6)
#define ST_LSADC_STATUS_get_pad5_status(data)                         ((0x00000020&(data))>>5)
#define ST_LSADC_STATUS_get_pad4_status(data)                         ((0x00000010&(data))>>4)
#define ST_LSADC_STATUS_get_pad3_status(data)                         ((0x00000008&(data))>>3)
#define ST_LSADC_STATUS_get_pad2_status(data)                         ((0x00000004&(data))>>2)
#define ST_LSADC_STATUS_get_pad1_status(data)                         ((0x00000002&(data))>>1)
#define ST_LSADC_STATUS_get_pad0_status(data)                         (0x00000001&(data))


#define ST_LSADC_ANALOG_CTRL                                          0x18011528
#define ST_LSADC_ANALOG_CTRL_reg_addr                                 "0xb8011528"
#define ST_LSADC_ANALOG_CTRL_reg                                      0xb8011528
#define ST_LSADC_ANALOG_CTRL_inst_addr                                "0x014A"
#define ST_LSADC_ANALOG_CTRL_inst                                     0x014A
#define ST_LSADC_ANALOG_CTRL_jd_sbias_shift                           (16)
#define ST_LSADC_ANALOG_CTRL_jd_adsbias_shift                         (12)
#define ST_LSADC_ANALOG_CTRL_jd_svr_shift                             (8)
#define ST_LSADC_ANALOG_CTRL_jd_adcksel_shift                         (4)
#define ST_LSADC_ANALOG_CTRL_jd_power_shift                           (0)
#define ST_LSADC_ANALOG_CTRL_jd_sbias_mask                            (0x00030000)
#define ST_LSADC_ANALOG_CTRL_jd_adsbias_mask                          (0x00003000)
#define ST_LSADC_ANALOG_CTRL_jd_svr_mask                              (0x00000100)
#define ST_LSADC_ANALOG_CTRL_jd_adcksel_mask                          (0x00000010)
#define ST_LSADC_ANALOG_CTRL_jd_power_mask                            (0x00000001)
#define ST_LSADC_ANALOG_CTRL_jd_sbias(data)                           (0x00030000&((data)<<16))
#define ST_LSADC_ANALOG_CTRL_jd_adsbias(data)                         (0x00003000&((data)<<12))
#define ST_LSADC_ANALOG_CTRL_jd_svr(data)                             (0x00000100&((data)<<8))
#define ST_LSADC_ANALOG_CTRL_jd_adcksel(data)                         (0x00000010&((data)<<4))
#define ST_LSADC_ANALOG_CTRL_jd_power(data)                           (0x00000001&(data))
#define ST_LSADC_ANALOG_CTRL_get_jd_sbias(data)                       ((0x00030000&(data))>>16)
#define ST_LSADC_ANALOG_CTRL_get_jd_adsbias(data)                     ((0x00003000&(data))>>12)
#define ST_LSADC_ANALOG_CTRL_get_jd_svr(data)                         ((0x00000100&(data))>>8)
#define ST_LSADC_ANALOG_CTRL_get_jd_adcksel(data)                     ((0x00000010&(data))>>4)
#define ST_LSADC_ANALOG_CTRL_get_jd_power(data)                       (0x00000001&(data))


#define LSADC_PAD5_LEVEL_SET0                                         0x18011530
#define LSADC_PAD5_LEVEL_SET0_reg_addr                                "0xb8011530"
#define LSADC_PAD5_LEVEL_SET0_reg                                     0xb8011530
#define LSADC_PAD5_LEVEL_SET0_inst_addr                               "0x014C"
#define LSADC_PAD5_LEVEL_SET0_inst                                    0x014C
#define LSADC_PAD5_LEVEL_SET0_level_0_start_val_shift                 (24)
#define LSADC_PAD5_LEVEL_SET0_level_0_end_val_shift                   (16)
#define LSADC_PAD5_LEVEL_SET0_block0en_shift                          (15)
#define LSADC_PAD5_LEVEL_SET0_int_en0_shift                           (1)
#define LSADC_PAD5_LEVEL_SET0_int_pending_bit0_shift                  (0)
#define LSADC_PAD5_LEVEL_SET0_level_0_start_val_mask                  (0xFF000000)
#define LSADC_PAD5_LEVEL_SET0_level_0_end_val_mask                    (0x00FF0000)
#define LSADC_PAD5_LEVEL_SET0_block0en_mask                           (0x00008000)
#define LSADC_PAD5_LEVEL_SET0_int_en0_mask                            (0x00000002)
#define LSADC_PAD5_LEVEL_SET0_int_pending_bit0_mask                   (0x00000001)
#define LSADC_PAD5_LEVEL_SET0_level_0_start_val(data)                 (0xFF000000&((data)<<24))
#define LSADC_PAD5_LEVEL_SET0_level_0_end_val(data)                   (0x00FF0000&((data)<<16))
#define LSADC_PAD5_LEVEL_SET0_block0en(data)                          (0x00008000&((data)<<15))
#define LSADC_PAD5_LEVEL_SET0_int_en0(data)                           (0x00000002&((data)<<1))
#define LSADC_PAD5_LEVEL_SET0_int_pending_bit0(data)                  (0x00000001&(data))
#define LSADC_PAD5_LEVEL_SET0_get_level_0_start_val(data)             ((0xFF000000&(data))>>24)
#define LSADC_PAD5_LEVEL_SET0_get_level_0_end_val(data)               ((0x00FF0000&(data))>>16)
#define LSADC_PAD5_LEVEL_SET0_get_block0en(data)                      ((0x00008000&(data))>>15)
#define LSADC_PAD5_LEVEL_SET0_get_int_en0(data)                       ((0x00000002&(data))>>1)
#define LSADC_PAD5_LEVEL_SET0_get_int_pending_bit0(data)              (0x00000001&(data))


#define LSADC_PAD5_LEVEL_SET1                                         0x18011534
#define LSADC_PAD5_LEVEL_SET1_reg_addr                                "0xb8011534"
#define LSADC_PAD5_LEVEL_SET1_reg                                     0xb8011534
#define LSADC_PAD5_LEVEL_SET1_inst_addr                               "0x014D"
#define LSADC_PAD5_LEVEL_SET1_inst                                    0x014D
#define LSADC_PAD5_LEVEL_SET1_level_1_start_val_shift                 (24)
#define LSADC_PAD5_LEVEL_SET1_level_1_end_val_shift                   (16)
#define LSADC_PAD5_LEVEL_SET1_block1en_shift                          (15)
#define LSADC_PAD5_LEVEL_SET1_int_en1_shift                           (1)
#define LSADC_PAD5_LEVEL_SET1_int_pending_bit1_shift                  (0)
#define LSADC_PAD5_LEVEL_SET1_level_1_start_val_mask                  (0xFF000000)
#define LSADC_PAD5_LEVEL_SET1_level_1_end_val_mask                    (0x00FF0000)
#define LSADC_PAD5_LEVEL_SET1_block1en_mask                           (0x00008000)
#define LSADC_PAD5_LEVEL_SET1_int_en1_mask                            (0x00000002)
#define LSADC_PAD5_LEVEL_SET1_int_pending_bit1_mask                   (0x00000001)
#define LSADC_PAD5_LEVEL_SET1_level_1_start_val(data)                 (0xFF000000&((data)<<24))
#define LSADC_PAD5_LEVEL_SET1_level_1_end_val(data)                   (0x00FF0000&((data)<<16))
#define LSADC_PAD5_LEVEL_SET1_block1en(data)                          (0x00008000&((data)<<15))
#define LSADC_PAD5_LEVEL_SET1_int_en1(data)                           (0x00000002&((data)<<1))
#define LSADC_PAD5_LEVEL_SET1_int_pending_bit1(data)                  (0x00000001&(data))
#define LSADC_PAD5_LEVEL_SET1_get_level_1_start_val(data)             ((0xFF000000&(data))>>24)
#define LSADC_PAD5_LEVEL_SET1_get_level_1_end_val(data)               ((0x00FF0000&(data))>>16)
#define LSADC_PAD5_LEVEL_SET1_get_block1en(data)                      ((0x00008000&(data))>>15)
#define LSADC_PAD5_LEVEL_SET1_get_int_en1(data)                       ((0x00000002&(data))>>1)
#define LSADC_PAD5_LEVEL_SET1_get_int_pending_bit1(data)              (0x00000001&(data))


#define LSADC_PAD5_LEVEL_SET2                                         0x18011538
#define LSADC_PAD5_LEVEL_SET2_reg_addr                                "0xb8011538"
#define LSADC_PAD5_LEVEL_SET2_reg                                     0xb8011538
#define LSADC_PAD5_LEVEL_SET2_inst_addr                               "0x014E"
#define LSADC_PAD5_LEVEL_SET2_inst                                    0x014E
#define LSADC_PAD5_LEVEL_SET2_level_2_start_val_shift                 (24)
#define LSADC_PAD5_LEVEL_SET2_level_2_end_val_shift                   (16)
#define LSADC_PAD5_LEVEL_SET2_block2en_shift                          (15)
#define LSADC_PAD5_LEVEL_SET2_int_en2_shift                           (1)
#define LSADC_PAD5_LEVEL_SET2_int_pending_bit2_shift                  (0)
#define LSADC_PAD5_LEVEL_SET2_level_2_start_val_mask                  (0xFF000000)
#define LSADC_PAD5_LEVEL_SET2_level_2_end_val_mask                    (0x00FF0000)
#define LSADC_PAD5_LEVEL_SET2_block2en_mask                           (0x00008000)
#define LSADC_PAD5_LEVEL_SET2_int_en2_mask                            (0x00000002)
#define LSADC_PAD5_LEVEL_SET2_int_pending_bit2_mask                   (0x00000001)
#define LSADC_PAD5_LEVEL_SET2_level_2_start_val(data)                 (0xFF000000&((data)<<24))
#define LSADC_PAD5_LEVEL_SET2_level_2_end_val(data)                   (0x00FF0000&((data)<<16))
#define LSADC_PAD5_LEVEL_SET2_block2en(data)                          (0x00008000&((data)<<15))
#define LSADC_PAD5_LEVEL_SET2_int_en2(data)                           (0x00000002&((data)<<1))
#define LSADC_PAD5_LEVEL_SET2_int_pending_bit2(data)                  (0x00000001&(data))
#define LSADC_PAD5_LEVEL_SET2_get_level_2_start_val(data)             ((0xFF000000&(data))>>24)
#define LSADC_PAD5_LEVEL_SET2_get_level_2_end_val(data)               ((0x00FF0000&(data))>>16)
#define LSADC_PAD5_LEVEL_SET2_get_block2en(data)                      ((0x00008000&(data))>>15)
#define LSADC_PAD5_LEVEL_SET2_get_int_en2(data)                       ((0x00000002&(data))>>1)
#define LSADC_PAD5_LEVEL_SET2_get_int_pending_bit2(data)              (0x00000001&(data))


#define LSADC_PAD5_LEVEL_SET3                                         0x1801153c
#define LSADC_PAD5_LEVEL_SET3_reg_addr                                "0xb801153c"
#define LSADC_PAD5_LEVEL_SET3_reg                                     0xb801153c
#define LSADC_PAD5_LEVEL_SET3_inst_addr                               "0x014F"
#define LSADC_PAD5_LEVEL_SET3_inst                                    0x014F
#define LSADC_PAD5_LEVEL_SET3_level_3_start_val_shift                 (24)
#define LSADC_PAD5_LEVEL_SET3_level_3_end_val_shift                   (16)
#define LSADC_PAD5_LEVEL_SET3_block3en_shift                          (15)
#define LSADC_PAD5_LEVEL_SET3_int_en3_shift                           (1)
#define LSADC_PAD5_LEVEL_SET3_int_pending_bit3_shift                  (0)
#define LSADC_PAD5_LEVEL_SET3_level_3_start_val_mask                  (0xFF000000)
#define LSADC_PAD5_LEVEL_SET3_level_3_end_val_mask                    (0x00FF0000)
#define LSADC_PAD5_LEVEL_SET3_block3en_mask                           (0x00008000)
#define LSADC_PAD5_LEVEL_SET3_int_en3_mask                            (0x00000002)
#define LSADC_PAD5_LEVEL_SET3_int_pending_bit3_mask                   (0x00000001)
#define LSADC_PAD5_LEVEL_SET3_level_3_start_val(data)                 (0xFF000000&((data)<<24))
#define LSADC_PAD5_LEVEL_SET3_level_3_end_val(data)                   (0x00FF0000&((data)<<16))
#define LSADC_PAD5_LEVEL_SET3_block3en(data)                          (0x00008000&((data)<<15))
#define LSADC_PAD5_LEVEL_SET3_int_en3(data)                           (0x00000002&((data)<<1))
#define LSADC_PAD5_LEVEL_SET3_int_pending_bit3(data)                  (0x00000001&(data))
#define LSADC_PAD5_LEVEL_SET3_get_level_3_start_val(data)             ((0xFF000000&(data))>>24)
#define LSADC_PAD5_LEVEL_SET3_get_level_3_end_val(data)               ((0x00FF0000&(data))>>16)
#define LSADC_PAD5_LEVEL_SET3_get_block3en(data)                      ((0x00008000&(data))>>15)
#define LSADC_PAD5_LEVEL_SET3_get_int_en3(data)                       ((0x00000002&(data))>>1)
#define LSADC_PAD5_LEVEL_SET3_get_int_pending_bit3(data)              (0x00000001&(data))


#define LSADC_PAD5_LEVEL_SET4                                         0x18011540
#define LSADC_PAD5_LEVEL_SET4_reg_addr                                "0xb8011540"
#define LSADC_PAD5_LEVEL_SET4_reg                                     0xb8011540
#define LSADC_PAD5_LEVEL_SET4_inst_addr                               "0x0150"
#define LSADC_PAD5_LEVEL_SET4_inst                                    0x0150
#define LSADC_PAD5_LEVEL_SET4_level_4_start_val_shift                 (24)
#define LSADC_PAD5_LEVEL_SET4_level_4_end_val_shift                   (16)
#define LSADC_PAD5_LEVEL_SET4_block4en_shift                          (15)
#define LSADC_PAD5_LEVEL_SET4_int_en4_shift                           (1)
#define LSADC_PAD5_LEVEL_SET4_int_pending_bit4_shift                  (0)
#define LSADC_PAD5_LEVEL_SET4_level_4_start_val_mask                  (0xFF000000)
#define LSADC_PAD5_LEVEL_SET4_level_4_end_val_mask                    (0x00FF0000)
#define LSADC_PAD5_LEVEL_SET4_block4en_mask                           (0x00008000)
#define LSADC_PAD5_LEVEL_SET4_int_en4_mask                            (0x00000002)
#define LSADC_PAD5_LEVEL_SET4_int_pending_bit4_mask                   (0x00000001)
#define LSADC_PAD5_LEVEL_SET4_level_4_start_val(data)                 (0xFF000000&((data)<<24))
#define LSADC_PAD5_LEVEL_SET4_level_4_end_val(data)                   (0x00FF0000&((data)<<16))
#define LSADC_PAD5_LEVEL_SET4_block4en(data)                          (0x00008000&((data)<<15))
#define LSADC_PAD5_LEVEL_SET4_int_en4(data)                           (0x00000002&((data)<<1))
#define LSADC_PAD5_LEVEL_SET4_int_pending_bit4(data)                  (0x00000001&(data))
#define LSADC_PAD5_LEVEL_SET4_get_level_4_start_val(data)             ((0xFF000000&(data))>>24)
#define LSADC_PAD5_LEVEL_SET4_get_level_4_end_val(data)               ((0x00FF0000&(data))>>16)
#define LSADC_PAD5_LEVEL_SET4_get_block4en(data)                      ((0x00008000&(data))>>15)
#define LSADC_PAD5_LEVEL_SET4_get_int_en4(data)                       ((0x00000002&(data))>>1)
#define LSADC_PAD5_LEVEL_SET4_get_int_pending_bit4(data)              (0x00000001&(data))


#define LSADC_PAD5_LEVEL_SET5                                         0x18011544
#define LSADC_PAD5_LEVEL_SET5_reg_addr                                "0xb8011544"
#define LSADC_PAD5_LEVEL_SET5_reg                                     0xb8011544
#define LSADC_PAD5_LEVEL_SET5_inst_addr                               "0x0151"
#define LSADC_PAD5_LEVEL_SET5_inst                                    0x0151
#define LSADC_PAD5_LEVEL_SET5_level_5_start_val_shift                 (24)
#define LSADC_PAD5_LEVEL_SET5_level_5_end_val_shift                   (16)
#define LSADC_PAD5_LEVEL_SET5_block5en_shift                          (15)
#define LSADC_PAD5_LEVEL_SET5_int_en5_shift                           (1)
#define LSADC_PAD5_LEVEL_SET5_int_pending_bit5_shift                  (0)
#define LSADC_PAD5_LEVEL_SET5_level_5_start_val_mask                  (0xFF000000)
#define LSADC_PAD5_LEVEL_SET5_level_5_end_val_mask                    (0x00FF0000)
#define LSADC_PAD5_LEVEL_SET5_block5en_mask                           (0x00008000)
#define LSADC_PAD5_LEVEL_SET5_int_en5_mask                            (0x00000002)
#define LSADC_PAD5_LEVEL_SET5_int_pending_bit5_mask                   (0x00000001)
#define LSADC_PAD5_LEVEL_SET5_level_5_start_val(data)                 (0xFF000000&((data)<<24))
#define LSADC_PAD5_LEVEL_SET5_level_5_end_val(data)                   (0x00FF0000&((data)<<16))
#define LSADC_PAD5_LEVEL_SET5_block5en(data)                          (0x00008000&((data)<<15))
#define LSADC_PAD5_LEVEL_SET5_int_en5(data)                           (0x00000002&((data)<<1))
#define LSADC_PAD5_LEVEL_SET5_int_pending_bit5(data)                  (0x00000001&(data))
#define LSADC_PAD5_LEVEL_SET5_get_level_5_start_val(data)             ((0xFF000000&(data))>>24)
#define LSADC_PAD5_LEVEL_SET5_get_level_5_end_val(data)               ((0x00FF0000&(data))>>16)
#define LSADC_PAD5_LEVEL_SET5_get_block5en(data)                      ((0x00008000&(data))>>15)
#define LSADC_PAD5_LEVEL_SET5_get_int_en5(data)                       ((0x00000002&(data))>>1)
#define LSADC_PAD5_LEVEL_SET5_get_int_pending_bit5(data)              (0x00000001&(data))


#define LSADC_PAD5_LEVEL_SET6                                         0x18011548
#define LSADC_PAD5_LEVEL_SET6_reg_addr                                "0xb8011548"
#define LSADC_PAD5_LEVEL_SET6_reg                                     0xb8011548
#define LSADC_PAD5_LEVEL_SET6_inst_addr                               "0x0152"
#define LSADC_PAD5_LEVEL_SET6_inst                                    0x0152
#define LSADC_PAD5_LEVEL_SET6_level_6_start_val_shift                 (24)
#define LSADC_PAD5_LEVEL_SET6_level_6_end_val_shift                   (16)
#define LSADC_PAD5_LEVEL_SET6_block6en_shift                          (15)
#define LSADC_PAD5_LEVEL_SET6_int_en6_shift                           (1)
#define LSADC_PAD5_LEVEL_SET6_int_pending_bit6_shift                  (0)
#define LSADC_PAD5_LEVEL_SET6_level_6_start_val_mask                  (0xFF000000)
#define LSADC_PAD5_LEVEL_SET6_level_6_end_val_mask                    (0x00FF0000)
#define LSADC_PAD5_LEVEL_SET6_block6en_mask                           (0x00008000)
#define LSADC_PAD5_LEVEL_SET6_int_en6_mask                            (0x00000002)
#define LSADC_PAD5_LEVEL_SET6_int_pending_bit6_mask                   (0x00000001)
#define LSADC_PAD5_LEVEL_SET6_level_6_start_val(data)                 (0xFF000000&((data)<<24))
#define LSADC_PAD5_LEVEL_SET6_level_6_end_val(data)                   (0x00FF0000&((data)<<16))
#define LSADC_PAD5_LEVEL_SET6_block6en(data)                          (0x00008000&((data)<<15))
#define LSADC_PAD5_LEVEL_SET6_int_en6(data)                           (0x00000002&((data)<<1))
#define LSADC_PAD5_LEVEL_SET6_int_pending_bit6(data)                  (0x00000001&(data))
#define LSADC_PAD5_LEVEL_SET6_get_level_6_start_val(data)             ((0xFF000000&(data))>>24)
#define LSADC_PAD5_LEVEL_SET6_get_level_6_end_val(data)               ((0x00FF0000&(data))>>16)
#define LSADC_PAD5_LEVEL_SET6_get_block6en(data)                      ((0x00008000&(data))>>15)
#define LSADC_PAD5_LEVEL_SET6_get_int_en6(data)                       ((0x00000002&(data))>>1)
#define LSADC_PAD5_LEVEL_SET6_get_int_pending_bit6(data)              (0x00000001&(data))


#define LSADC_PAD5_LEVEL_SET7                                         0x1801154c
#define LSADC_PAD5_LEVEL_SET7_reg_addr                                "0xb801154c"
#define LSADC_PAD5_LEVEL_SET7_reg                                     0xb801154c
#define LSADC_PAD5_LEVEL_SET7_inst_addr                               "0x0153"
#define LSADC_PAD5_LEVEL_SET7_inst                                    0x0153
#define LSADC_PAD5_LEVEL_SET7_level_7_start_val_shift                 (24)
#define LSADC_PAD5_LEVEL_SET7_level_7_end_val_shift                   (16)
#define LSADC_PAD5_LEVEL_SET7_block7en_shift                          (15)
#define LSADC_PAD5_LEVEL_SET7_int_en7_shift                           (1)
#define LSADC_PAD5_LEVEL_SET7_int_pending_bit7_shift                  (0)
#define LSADC_PAD5_LEVEL_SET7_level_7_start_val_mask                  (0xFF000000)
#define LSADC_PAD5_LEVEL_SET7_level_7_end_val_mask                    (0x00FF0000)
#define LSADC_PAD5_LEVEL_SET7_block7en_mask                           (0x00008000)
#define LSADC_PAD5_LEVEL_SET7_int_en7_mask                            (0x00000002)
#define LSADC_PAD5_LEVEL_SET7_int_pending_bit7_mask                   (0x00000001)
#define LSADC_PAD5_LEVEL_SET7_level_7_start_val(data)                 (0xFF000000&((data)<<24))
#define LSADC_PAD5_LEVEL_SET7_level_7_end_val(data)                   (0x00FF0000&((data)<<16))
#define LSADC_PAD5_LEVEL_SET7_block7en(data)                          (0x00008000&((data)<<15))
#define LSADC_PAD5_LEVEL_SET7_int_en7(data)                           (0x00000002&((data)<<1))
#define LSADC_PAD5_LEVEL_SET7_int_pending_bit7(data)                  (0x00000001&(data))
#define LSADC_PAD5_LEVEL_SET7_get_level_7_start_val(data)             ((0xFF000000&(data))>>24)
#define LSADC_PAD5_LEVEL_SET7_get_level_7_end_val(data)               ((0x00FF0000&(data))>>16)
#define LSADC_PAD5_LEVEL_SET7_get_block7en(data)                      ((0x00008000&(data))>>15)
#define LSADC_PAD5_LEVEL_SET7_get_int_en7(data)                       ((0x00000002&(data))>>1)
#define LSADC_PAD5_LEVEL_SET7_get_int_pending_bit7(data)              (0x00000001&(data))


#define LSADC_PAD6_LEVEL_SET0                                         0x18011550
#define LSADC_PAD6_LEVEL_SET0_reg_addr                                "0xb8011550"
#define LSADC_PAD6_LEVEL_SET0_reg                                     0xb8011550
#define LSADC_PAD6_LEVEL_SET0_inst_addr                               "0x0154"
#define LSADC_PAD6_LEVEL_SET0_inst                                    0x0154
#define LSADC_PAD6_LEVEL_SET0_level_0_start_val_shift                 (24)
#define LSADC_PAD6_LEVEL_SET0_level_0_end_val_shift                   (16)
#define LSADC_PAD6_LEVEL_SET0_block0en_shift                          (15)
#define LSADC_PAD6_LEVEL_SET0_int_en0_shift                           (1)
#define LSADC_PAD6_LEVEL_SET0_int_pending_bit0_shift                  (0)
#define LSADC_PAD6_LEVEL_SET0_level_0_start_val_mask                  (0xFF000000)
#define LSADC_PAD6_LEVEL_SET0_level_0_end_val_mask                    (0x00FF0000)
#define LSADC_PAD6_LEVEL_SET0_block0en_mask                           (0x00008000)
#define LSADC_PAD6_LEVEL_SET0_int_en0_mask                            (0x00000002)
#define LSADC_PAD6_LEVEL_SET0_int_pending_bit0_mask                   (0x00000001)
#define LSADC_PAD6_LEVEL_SET0_level_0_start_val(data)                 (0xFF000000&((data)<<24))
#define LSADC_PAD6_LEVEL_SET0_level_0_end_val(data)                   (0x00FF0000&((data)<<16))
#define LSADC_PAD6_LEVEL_SET0_block0en(data)                          (0x00008000&((data)<<15))
#define LSADC_PAD6_LEVEL_SET0_int_en0(data)                           (0x00000002&((data)<<1))
#define LSADC_PAD6_LEVEL_SET0_int_pending_bit0(data)                  (0x00000001&(data))
#define LSADC_PAD6_LEVEL_SET0_get_level_0_start_val(data)             ((0xFF000000&(data))>>24)
#define LSADC_PAD6_LEVEL_SET0_get_level_0_end_val(data)               ((0x00FF0000&(data))>>16)
#define LSADC_PAD6_LEVEL_SET0_get_block0en(data)                      ((0x00008000&(data))>>15)
#define LSADC_PAD6_LEVEL_SET0_get_int_en0(data)                       ((0x00000002&(data))>>1)
#define LSADC_PAD6_LEVEL_SET0_get_int_pending_bit0(data)              (0x00000001&(data))


#define LSADC_PAD6_LEVEL_SET1                                         0x18011554
#define LSADC_PAD6_LEVEL_SET1_reg_addr                                "0xb8011554"
#define LSADC_PAD6_LEVEL_SET1_reg                                     0xb8011554
#define LSADC_PAD6_LEVEL_SET1_inst_addr                               "0x0155"
#define LSADC_PAD6_LEVEL_SET1_inst                                    0x0155
#define LSADC_PAD6_LEVEL_SET1_level_1_start_val_shift                 (24)
#define LSADC_PAD6_LEVEL_SET1_level_1_end_val_shift                   (16)
#define LSADC_PAD6_LEVEL_SET1_block1en_shift                          (15)
#define LSADC_PAD6_LEVEL_SET1_int_en1_shift                           (1)
#define LSADC_PAD6_LEVEL_SET1_int_pending_bit1_shift                  (0)
#define LSADC_PAD6_LEVEL_SET1_level_1_start_val_mask                  (0xFF000000)
#define LSADC_PAD6_LEVEL_SET1_level_1_end_val_mask                    (0x00FF0000)
#define LSADC_PAD6_LEVEL_SET1_block1en_mask                           (0x00008000)
#define LSADC_PAD6_LEVEL_SET1_int_en1_mask                            (0x00000002)
#define LSADC_PAD6_LEVEL_SET1_int_pending_bit1_mask                   (0x00000001)
#define LSADC_PAD6_LEVEL_SET1_level_1_start_val(data)                 (0xFF000000&((data)<<24))
#define LSADC_PAD6_LEVEL_SET1_level_1_end_val(data)                   (0x00FF0000&((data)<<16))
#define LSADC_PAD6_LEVEL_SET1_block1en(data)                          (0x00008000&((data)<<15))
#define LSADC_PAD6_LEVEL_SET1_int_en1(data)                           (0x00000002&((data)<<1))
#define LSADC_PAD6_LEVEL_SET1_int_pending_bit1(data)                  (0x00000001&(data))
#define LSADC_PAD6_LEVEL_SET1_get_level_1_start_val(data)             ((0xFF000000&(data))>>24)
#define LSADC_PAD6_LEVEL_SET1_get_level_1_end_val(data)               ((0x00FF0000&(data))>>16)
#define LSADC_PAD6_LEVEL_SET1_get_block1en(data)                      ((0x00008000&(data))>>15)
#define LSADC_PAD6_LEVEL_SET1_get_int_en1(data)                       ((0x00000002&(data))>>1)
#define LSADC_PAD6_LEVEL_SET1_get_int_pending_bit1(data)              (0x00000001&(data))


#define LSADC_PAD6_LEVEL_SET2                                         0x18011558
#define LSADC_PAD6_LEVEL_SET2_reg_addr                                "0xb8011558"
#define LSADC_PAD6_LEVEL_SET2_reg                                     0xb8011558
#define LSADC_PAD6_LEVEL_SET2_inst_addr                               "0x0156"
#define LSADC_PAD6_LEVEL_SET2_inst                                    0x0156
#define LSADC_PAD6_LEVEL_SET2_level_2_start_val_shift                 (24)
#define LSADC_PAD6_LEVEL_SET2_level_2_end_val_shift                   (16)
#define LSADC_PAD6_LEVEL_SET2_block2en_shift                          (15)
#define LSADC_PAD6_LEVEL_SET2_int_en2_shift                           (1)
#define LSADC_PAD6_LEVEL_SET2_int_pending_bit2_shift                  (0)
#define LSADC_PAD6_LEVEL_SET2_level_2_start_val_mask                  (0xFF000000)
#define LSADC_PAD6_LEVEL_SET2_level_2_end_val_mask                    (0x00FF0000)
#define LSADC_PAD6_LEVEL_SET2_block2en_mask                           (0x00008000)
#define LSADC_PAD6_LEVEL_SET2_int_en2_mask                            (0x00000002)
#define LSADC_PAD6_LEVEL_SET2_int_pending_bit2_mask                   (0x00000001)
#define LSADC_PAD6_LEVEL_SET2_level_2_start_val(data)                 (0xFF000000&((data)<<24))
#define LSADC_PAD6_LEVEL_SET2_level_2_end_val(data)                   (0x00FF0000&((data)<<16))
#define LSADC_PAD6_LEVEL_SET2_block2en(data)                          (0x00008000&((data)<<15))
#define LSADC_PAD6_LEVEL_SET2_int_en2(data)                           (0x00000002&((data)<<1))
#define LSADC_PAD6_LEVEL_SET2_int_pending_bit2(data)                  (0x00000001&(data))
#define LSADC_PAD6_LEVEL_SET2_get_level_2_start_val(data)             ((0xFF000000&(data))>>24)
#define LSADC_PAD6_LEVEL_SET2_get_level_2_end_val(data)               ((0x00FF0000&(data))>>16)
#define LSADC_PAD6_LEVEL_SET2_get_block2en(data)                      ((0x00008000&(data))>>15)
#define LSADC_PAD6_LEVEL_SET2_get_int_en2(data)                       ((0x00000002&(data))>>1)
#define LSADC_PAD6_LEVEL_SET2_get_int_pending_bit2(data)              (0x00000001&(data))


#define LSADC_PAD6_LEVEL_SET3                                         0x1801155c
#define LSADC_PAD6_LEVEL_SET3_reg_addr                                "0xb801155c"
#define LSADC_PAD6_LEVEL_SET3_reg                                     0xb801155c
#define LSADC_PAD6_LEVEL_SET3_inst_addr                               "0x0157"
#define LSADC_PAD6_LEVEL_SET3_inst                                    0x0157
#define LSADC_PAD6_LEVEL_SET3_level_3_start_val_shift                 (24)
#define LSADC_PAD6_LEVEL_SET3_level_3_end_val_shift                   (16)
#define LSADC_PAD6_LEVEL_SET3_block3en_shift                          (15)
#define LSADC_PAD6_LEVEL_SET3_int_en3_shift                           (1)
#define LSADC_PAD6_LEVEL_SET3_int_pending_bit3_shift                  (0)
#define LSADC_PAD6_LEVEL_SET3_level_3_start_val_mask                  (0xFF000000)
#define LSADC_PAD6_LEVEL_SET3_level_3_end_val_mask                    (0x00FF0000)
#define LSADC_PAD6_LEVEL_SET3_block3en_mask                           (0x00008000)
#define LSADC_PAD6_LEVEL_SET3_int_en3_mask                            (0x00000002)
#define LSADC_PAD6_LEVEL_SET3_int_pending_bit3_mask                   (0x00000001)
#define LSADC_PAD6_LEVEL_SET3_level_3_start_val(data)                 (0xFF000000&((data)<<24))
#define LSADC_PAD6_LEVEL_SET3_level_3_end_val(data)                   (0x00FF0000&((data)<<16))
#define LSADC_PAD6_LEVEL_SET3_block3en(data)                          (0x00008000&((data)<<15))
#define LSADC_PAD6_LEVEL_SET3_int_en3(data)                           (0x00000002&((data)<<1))
#define LSADC_PAD6_LEVEL_SET3_int_pending_bit3(data)                  (0x00000001&(data))
#define LSADC_PAD6_LEVEL_SET3_get_level_3_start_val(data)             ((0xFF000000&(data))>>24)
#define LSADC_PAD6_LEVEL_SET3_get_level_3_end_val(data)               ((0x00FF0000&(data))>>16)
#define LSADC_PAD6_LEVEL_SET3_get_block3en(data)                      ((0x00008000&(data))>>15)
#define LSADC_PAD6_LEVEL_SET3_get_int_en3(data)                       ((0x00000002&(data))>>1)
#define LSADC_PAD6_LEVEL_SET3_get_int_pending_bit3(data)              (0x00000001&(data))


#define LSADC_PAD6_LEVEL_SET4                                         0x18011560
#define LSADC_PAD6_LEVEL_SET4_reg_addr                                "0xb8011560"
#define LSADC_PAD6_LEVEL_SET4_reg                                     0xb8011560
#define LSADC_PAD6_LEVEL_SET4_inst_addr                               "0x0158"
#define LSADC_PAD6_LEVEL_SET4_inst                                    0x0158
#define LSADC_PAD6_LEVEL_SET4_level_4_start_val_shift                 (24)
#define LSADC_PAD6_LEVEL_SET4_level_4_end_val_shift                   (16)
#define LSADC_PAD6_LEVEL_SET4_block4en_shift                          (15)
#define LSADC_PAD6_LEVEL_SET4_int_en4_shift                           (1)
#define LSADC_PAD6_LEVEL_SET4_int_pending_bit4_shift                  (0)
#define LSADC_PAD6_LEVEL_SET4_level_4_start_val_mask                  (0xFF000000)
#define LSADC_PAD6_LEVEL_SET4_level_4_end_val_mask                    (0x00FF0000)
#define LSADC_PAD6_LEVEL_SET4_block4en_mask                           (0x00008000)
#define LSADC_PAD6_LEVEL_SET4_int_en4_mask                            (0x00000002)
#define LSADC_PAD6_LEVEL_SET4_int_pending_bit4_mask                   (0x00000001)
#define LSADC_PAD6_LEVEL_SET4_level_4_start_val(data)                 (0xFF000000&((data)<<24))
#define LSADC_PAD6_LEVEL_SET4_level_4_end_val(data)                   (0x00FF0000&((data)<<16))
#define LSADC_PAD6_LEVEL_SET4_block4en(data)                          (0x00008000&((data)<<15))
#define LSADC_PAD6_LEVEL_SET4_int_en4(data)                           (0x00000002&((data)<<1))
#define LSADC_PAD6_LEVEL_SET4_int_pending_bit4(data)                  (0x00000001&(data))
#define LSADC_PAD6_LEVEL_SET4_get_level_4_start_val(data)             ((0xFF000000&(data))>>24)
#define LSADC_PAD6_LEVEL_SET4_get_level_4_end_val(data)               ((0x00FF0000&(data))>>16)
#define LSADC_PAD6_LEVEL_SET4_get_block4en(data)                      ((0x00008000&(data))>>15)
#define LSADC_PAD6_LEVEL_SET4_get_int_en4(data)                       ((0x00000002&(data))>>1)
#define LSADC_PAD6_LEVEL_SET4_get_int_pending_bit4(data)              (0x00000001&(data))


#define LSADC_PAD6_LEVEL_SET5                                         0x18011564
#define LSADC_PAD6_LEVEL_SET5_reg_addr                                "0xb8011564"
#define LSADC_PAD6_LEVEL_SET5_reg                                     0xb8011564
#define LSADC_PAD6_LEVEL_SET5_inst_addr                               "0x0159"
#define LSADC_PAD6_LEVEL_SET5_inst                                    0x0159
#define LSADC_PAD6_LEVEL_SET5_level_5_start_val_shift                 (24)
#define LSADC_PAD6_LEVEL_SET5_level_5_end_val_shift                   (16)
#define LSADC_PAD6_LEVEL_SET5_block5en_shift                          (15)
#define LSADC_PAD6_LEVEL_SET5_int_en5_shift                           (1)
#define LSADC_PAD6_LEVEL_SET5_int_pending_bit5_shift                  (0)
#define LSADC_PAD6_LEVEL_SET5_level_5_start_val_mask                  (0xFF000000)
#define LSADC_PAD6_LEVEL_SET5_level_5_end_val_mask                    (0x00FF0000)
#define LSADC_PAD6_LEVEL_SET5_block5en_mask                           (0x00008000)
#define LSADC_PAD6_LEVEL_SET5_int_en5_mask                            (0x00000002)
#define LSADC_PAD6_LEVEL_SET5_int_pending_bit5_mask                   (0x00000001)
#define LSADC_PAD6_LEVEL_SET5_level_5_start_val(data)                 (0xFF000000&((data)<<24))
#define LSADC_PAD6_LEVEL_SET5_level_5_end_val(data)                   (0x00FF0000&((data)<<16))
#define LSADC_PAD6_LEVEL_SET5_block5en(data)                          (0x00008000&((data)<<15))
#define LSADC_PAD6_LEVEL_SET5_int_en5(data)                           (0x00000002&((data)<<1))
#define LSADC_PAD6_LEVEL_SET5_int_pending_bit5(data)                  (0x00000001&(data))
#define LSADC_PAD6_LEVEL_SET5_get_level_5_start_val(data)             ((0xFF000000&(data))>>24)
#define LSADC_PAD6_LEVEL_SET5_get_level_5_end_val(data)               ((0x00FF0000&(data))>>16)
#define LSADC_PAD6_LEVEL_SET5_get_block5en(data)                      ((0x00008000&(data))>>15)
#define LSADC_PAD6_LEVEL_SET5_get_int_en5(data)                       ((0x00000002&(data))>>1)
#define LSADC_PAD6_LEVEL_SET5_get_int_pending_bit5(data)              (0x00000001&(data))


#define LSADC_PAD6_LEVEL_SET6                                         0x18011568
#define LSADC_PAD6_LEVEL_SET6_reg_addr                                "0xb8011568"
#define LSADC_PAD6_LEVEL_SET6_reg                                     0xb8011568
#define LSADC_PAD6_LEVEL_SET6_inst_addr                               "0x015A"
#define LSADC_PAD6_LEVEL_SET6_inst                                    0x015A
#define LSADC_PAD6_LEVEL_SET6_level_6_start_val_shift                 (24)
#define LSADC_PAD6_LEVEL_SET6_level_6_end_val_shift                   (16)
#define LSADC_PAD6_LEVEL_SET6_block6en_shift                          (15)
#define LSADC_PAD6_LEVEL_SET6_int_en6_shift                           (1)
#define LSADC_PAD6_LEVEL_SET6_int_pending_bit6_shift                  (0)
#define LSADC_PAD6_LEVEL_SET6_level_6_start_val_mask                  (0xFF000000)
#define LSADC_PAD6_LEVEL_SET6_level_6_end_val_mask                    (0x00FF0000)
#define LSADC_PAD6_LEVEL_SET6_block6en_mask                           (0x00008000)
#define LSADC_PAD6_LEVEL_SET6_int_en6_mask                            (0x00000002)
#define LSADC_PAD6_LEVEL_SET6_int_pending_bit6_mask                   (0x00000001)
#define LSADC_PAD6_LEVEL_SET6_level_6_start_val(data)                 (0xFF000000&((data)<<24))
#define LSADC_PAD6_LEVEL_SET6_level_6_end_val(data)                   (0x00FF0000&((data)<<16))
#define LSADC_PAD6_LEVEL_SET6_block6en(data)                          (0x00008000&((data)<<15))
#define LSADC_PAD6_LEVEL_SET6_int_en6(data)                           (0x00000002&((data)<<1))
#define LSADC_PAD6_LEVEL_SET6_int_pending_bit6(data)                  (0x00000001&(data))
#define LSADC_PAD6_LEVEL_SET6_get_level_6_start_val(data)             ((0xFF000000&(data))>>24)
#define LSADC_PAD6_LEVEL_SET6_get_level_6_end_val(data)               ((0x00FF0000&(data))>>16)
#define LSADC_PAD6_LEVEL_SET6_get_block6en(data)                      ((0x00008000&(data))>>15)
#define LSADC_PAD6_LEVEL_SET6_get_int_en6(data)                       ((0x00000002&(data))>>1)
#define LSADC_PAD6_LEVEL_SET6_get_int_pending_bit6(data)              (0x00000001&(data))


#define LSADC_PAD6_LEVEL_SET7                                         0x1801156c
#define LSADC_PAD6_LEVEL_SET7_reg_addr                                "0xb801156c"
#define LSADC_PAD6_LEVEL_SET7_reg                                     0xb801156c
#define LSADC_PAD6_LEVEL_SET7_inst_addr                               "0x015B"
#define LSADC_PAD6_LEVEL_SET7_inst                                    0x015B
#define LSADC_PAD6_LEVEL_SET7_level_7_start_val_shift                 (24)
#define LSADC_PAD6_LEVEL_SET7_level_7_end_val_shift                   (16)
#define LSADC_PAD6_LEVEL_SET7_block7en_shift                          (15)
#define LSADC_PAD6_LEVEL_SET7_int_en7_shift                           (1)
#define LSADC_PAD6_LEVEL_SET7_int_pending_bit7_shift                  (0)
#define LSADC_PAD6_LEVEL_SET7_level_7_start_val_mask                  (0xFF000000)
#define LSADC_PAD6_LEVEL_SET7_level_7_end_val_mask                    (0x00FF0000)
#define LSADC_PAD6_LEVEL_SET7_block7en_mask                           (0x00008000)
#define LSADC_PAD6_LEVEL_SET7_int_en7_mask                            (0x00000002)
#define LSADC_PAD6_LEVEL_SET7_int_pending_bit7_mask                   (0x00000001)
#define LSADC_PAD6_LEVEL_SET7_level_7_start_val(data)                 (0xFF000000&((data)<<24))
#define LSADC_PAD6_LEVEL_SET7_level_7_end_val(data)                   (0x00FF0000&((data)<<16))
#define LSADC_PAD6_LEVEL_SET7_block7en(data)                          (0x00008000&((data)<<15))
#define LSADC_PAD6_LEVEL_SET7_int_en7(data)                           (0x00000002&((data)<<1))
#define LSADC_PAD6_LEVEL_SET7_int_pending_bit7(data)                  (0x00000001&(data))
#define LSADC_PAD6_LEVEL_SET7_get_level_7_start_val(data)             ((0xFF000000&(data))>>24)
#define LSADC_PAD6_LEVEL_SET7_get_level_7_end_val(data)               ((0x00FF0000&(data))>>16)
#define LSADC_PAD6_LEVEL_SET7_get_block7en(data)                      ((0x00008000&(data))>>15)
#define LSADC_PAD6_LEVEL_SET7_get_int_en7(data)                       ((0x00000002&(data))>>1)
#define LSADC_PAD6_LEVEL_SET7_get_int_pending_bit7(data)              (0x00000001&(data))


#define LSADC_PAD7_LEVEL_SET0                                         0x18011570
#define LSADC_PAD7_LEVEL_SET0_reg_addr                                "0xb8011570"
#define LSADC_PAD7_LEVEL_SET0_reg                                     0xb8011570
#define LSADC_PAD7_LEVEL_SET0_inst_addr                               "0x015C"
#define LSADC_PAD7_LEVEL_SET0_inst                                    0x015C
#define LSADC_PAD7_LEVEL_SET0_level_0_start_val_shift                 (24)
#define LSADC_PAD7_LEVEL_SET0_level_0_end_val_shift                   (16)
#define LSADC_PAD7_LEVEL_SET0_block0en_shift                          (15)
#define LSADC_PAD7_LEVEL_SET0_int_en0_shift                           (1)
#define LSADC_PAD7_LEVEL_SET0_int_pending_bit0_shift                  (0)
#define LSADC_PAD7_LEVEL_SET0_level_0_start_val_mask                  (0xFF000000)
#define LSADC_PAD7_LEVEL_SET0_level_0_end_val_mask                    (0x00FF0000)
#define LSADC_PAD7_LEVEL_SET0_block0en_mask                           (0x00008000)
#define LSADC_PAD7_LEVEL_SET0_int_en0_mask                            (0x00000002)
#define LSADC_PAD7_LEVEL_SET0_int_pending_bit0_mask                   (0x00000001)
#define LSADC_PAD7_LEVEL_SET0_level_0_start_val(data)                 (0xFF000000&((data)<<24))
#define LSADC_PAD7_LEVEL_SET0_level_0_end_val(data)                   (0x00FF0000&((data)<<16))
#define LSADC_PAD7_LEVEL_SET0_block0en(data)                          (0x00008000&((data)<<15))
#define LSADC_PAD7_LEVEL_SET0_int_en0(data)                           (0x00000002&((data)<<1))
#define LSADC_PAD7_LEVEL_SET0_int_pending_bit0(data)                  (0x00000001&(data))
#define LSADC_PAD7_LEVEL_SET0_get_level_0_start_val(data)             ((0xFF000000&(data))>>24)
#define LSADC_PAD7_LEVEL_SET0_get_level_0_end_val(data)               ((0x00FF0000&(data))>>16)
#define LSADC_PAD7_LEVEL_SET0_get_block0en(data)                      ((0x00008000&(data))>>15)
#define LSADC_PAD7_LEVEL_SET0_get_int_en0(data)                       ((0x00000002&(data))>>1)
#define LSADC_PAD7_LEVEL_SET0_get_int_pending_bit0(data)              (0x00000001&(data))


#define LSADC_PAD7_LEVEL_SET1                                         0x18011574
#define LSADC_PAD7_LEVEL_SET1_reg_addr                                "0xb8011574"
#define LSADC_PAD7_LEVEL_SET1_reg                                     0xb8011574
#define LSADC_PAD7_LEVEL_SET1_inst_addr                               "0x015D"
#define LSADC_PAD7_LEVEL_SET1_inst                                    0x015D
#define LSADC_PAD7_LEVEL_SET1_level_1_start_val_shift                 (24)
#define LSADC_PAD7_LEVEL_SET1_level_1_end_val_shift                   (16)
#define LSADC_PAD7_LEVEL_SET1_block1en_shift                          (15)
#define LSADC_PAD7_LEVEL_SET1_int_en1_shift                           (1)
#define LSADC_PAD7_LEVEL_SET1_int_pending_bit1_shift                  (0)
#define LSADC_PAD7_LEVEL_SET1_level_1_start_val_mask                  (0xFF000000)
#define LSADC_PAD7_LEVEL_SET1_level_1_end_val_mask                    (0x00FF0000)
#define LSADC_PAD7_LEVEL_SET1_block1en_mask                           (0x00008000)
#define LSADC_PAD7_LEVEL_SET1_int_en1_mask                            (0x00000002)
#define LSADC_PAD7_LEVEL_SET1_int_pending_bit1_mask                   (0x00000001)
#define LSADC_PAD7_LEVEL_SET1_level_1_start_val(data)                 (0xFF000000&((data)<<24))
#define LSADC_PAD7_LEVEL_SET1_level_1_end_val(data)                   (0x00FF0000&((data)<<16))
#define LSADC_PAD7_LEVEL_SET1_block1en(data)                          (0x00008000&((data)<<15))
#define LSADC_PAD7_LEVEL_SET1_int_en1(data)                           (0x00000002&((data)<<1))
#define LSADC_PAD7_LEVEL_SET1_int_pending_bit1(data)                  (0x00000001&(data))
#define LSADC_PAD7_LEVEL_SET1_get_level_1_start_val(data)             ((0xFF000000&(data))>>24)
#define LSADC_PAD7_LEVEL_SET1_get_level_1_end_val(data)               ((0x00FF0000&(data))>>16)
#define LSADC_PAD7_LEVEL_SET1_get_block1en(data)                      ((0x00008000&(data))>>15)
#define LSADC_PAD7_LEVEL_SET1_get_int_en1(data)                       ((0x00000002&(data))>>1)
#define LSADC_PAD7_LEVEL_SET1_get_int_pending_bit1(data)              (0x00000001&(data))


#define LSADC_PAD7_LEVEL_SET2                                         0x18011578
#define LSADC_PAD7_LEVEL_SET2_reg_addr                                "0xb8011578"
#define LSADC_PAD7_LEVEL_SET2_reg                                     0xb8011578
#define LSADC_PAD7_LEVEL_SET2_inst_addr                               "0x015E"
#define LSADC_PAD7_LEVEL_SET2_inst                                    0x015E
#define LSADC_PAD7_LEVEL_SET2_level_2_start_val_shift                 (24)
#define LSADC_PAD7_LEVEL_SET2_level_2_end_val_shift                   (16)
#define LSADC_PAD7_LEVEL_SET2_block2en_shift                          (15)
#define LSADC_PAD7_LEVEL_SET2_int_en2_shift                           (1)
#define LSADC_PAD7_LEVEL_SET2_int_pending_bit2_shift                  (0)
#define LSADC_PAD7_LEVEL_SET2_level_2_start_val_mask                  (0xFF000000)
#define LSADC_PAD7_LEVEL_SET2_level_2_end_val_mask                    (0x00FF0000)
#define LSADC_PAD7_LEVEL_SET2_block2en_mask                           (0x00008000)
#define LSADC_PAD7_LEVEL_SET2_int_en2_mask                            (0x00000002)
#define LSADC_PAD7_LEVEL_SET2_int_pending_bit2_mask                   (0x00000001)
#define LSADC_PAD7_LEVEL_SET2_level_2_start_val(data)                 (0xFF000000&((data)<<24))
#define LSADC_PAD7_LEVEL_SET2_level_2_end_val(data)                   (0x00FF0000&((data)<<16))
#define LSADC_PAD7_LEVEL_SET2_block2en(data)                          (0x00008000&((data)<<15))
#define LSADC_PAD7_LEVEL_SET2_int_en2(data)                           (0x00000002&((data)<<1))
#define LSADC_PAD7_LEVEL_SET2_int_pending_bit2(data)                  (0x00000001&(data))
#define LSADC_PAD7_LEVEL_SET2_get_level_2_start_val(data)             ((0xFF000000&(data))>>24)
#define LSADC_PAD7_LEVEL_SET2_get_level_2_end_val(data)               ((0x00FF0000&(data))>>16)
#define LSADC_PAD7_LEVEL_SET2_get_block2en(data)                      ((0x00008000&(data))>>15)
#define LSADC_PAD7_LEVEL_SET2_get_int_en2(data)                       ((0x00000002&(data))>>1)
#define LSADC_PAD7_LEVEL_SET2_get_int_pending_bit2(data)              (0x00000001&(data))


#define LSADC_PAD7_LEVEL_SET3                                         0x1801157c
#define LSADC_PAD7_LEVEL_SET3_reg_addr                                "0xb801157c"
#define LSADC_PAD7_LEVEL_SET3_reg                                     0xb801157c
#define LSADC_PAD7_LEVEL_SET3_inst_addr                               "0x015F"
#define LSADC_PAD7_LEVEL_SET3_inst                                    0x015F
#define LSADC_PAD7_LEVEL_SET3_level_3_start_val_shift                 (24)
#define LSADC_PAD7_LEVEL_SET3_level_3_end_val_shift                   (16)
#define LSADC_PAD7_LEVEL_SET3_block3en_shift                          (15)
#define LSADC_PAD7_LEVEL_SET3_int_en3_shift                           (1)
#define LSADC_PAD7_LEVEL_SET3_int_pending_bit3_shift                  (0)
#define LSADC_PAD7_LEVEL_SET3_level_3_start_val_mask                  (0xFF000000)
#define LSADC_PAD7_LEVEL_SET3_level_3_end_val_mask                    (0x00FF0000)
#define LSADC_PAD7_LEVEL_SET3_block3en_mask                           (0x00008000)
#define LSADC_PAD7_LEVEL_SET3_int_en3_mask                            (0x00000002)
#define LSADC_PAD7_LEVEL_SET3_int_pending_bit3_mask                   (0x00000001)
#define LSADC_PAD7_LEVEL_SET3_level_3_start_val(data)                 (0xFF000000&((data)<<24))
#define LSADC_PAD7_LEVEL_SET3_level_3_end_val(data)                   (0x00FF0000&((data)<<16))
#define LSADC_PAD7_LEVEL_SET3_block3en(data)                          (0x00008000&((data)<<15))
#define LSADC_PAD7_LEVEL_SET3_int_en3(data)                           (0x00000002&((data)<<1))
#define LSADC_PAD7_LEVEL_SET3_int_pending_bit3(data)                  (0x00000001&(data))
#define LSADC_PAD7_LEVEL_SET3_get_level_3_start_val(data)             ((0xFF000000&(data))>>24)
#define LSADC_PAD7_LEVEL_SET3_get_level_3_end_val(data)               ((0x00FF0000&(data))>>16)
#define LSADC_PAD7_LEVEL_SET3_get_block3en(data)                      ((0x00008000&(data))>>15)
#define LSADC_PAD7_LEVEL_SET3_get_int_en3(data)                       ((0x00000002&(data))>>1)
#define LSADC_PAD7_LEVEL_SET3_get_int_pending_bit3(data)              (0x00000001&(data))


#define LSADC_PAD7_LEVEL_SET4                                         0x18011580
#define LSADC_PAD7_LEVEL_SET4_reg_addr                                "0xb8011580"
#define LSADC_PAD7_LEVEL_SET4_reg                                     0xb8011580
#define LSADC_PAD7_LEVEL_SET4_inst_addr                               "0x0160"
#define LSADC_PAD7_LEVEL_SET4_inst                                    0x0160
#define LSADC_PAD7_LEVEL_SET4_level_4_start_val_shift                 (24)
#define LSADC_PAD7_LEVEL_SET4_level_4_end_val_shift                   (16)
#define LSADC_PAD7_LEVEL_SET4_block4en_shift                          (15)
#define LSADC_PAD7_LEVEL_SET4_int_en4_shift                           (1)
#define LSADC_PAD7_LEVEL_SET4_int_pending_bit4_shift                  (0)
#define LSADC_PAD7_LEVEL_SET4_level_4_start_val_mask                  (0xFF000000)
#define LSADC_PAD7_LEVEL_SET4_level_4_end_val_mask                    (0x00FF0000)
#define LSADC_PAD7_LEVEL_SET4_block4en_mask                           (0x00008000)
#define LSADC_PAD7_LEVEL_SET4_int_en4_mask                            (0x00000002)
#define LSADC_PAD7_LEVEL_SET4_int_pending_bit4_mask                   (0x00000001)
#define LSADC_PAD7_LEVEL_SET4_level_4_start_val(data)                 (0xFF000000&((data)<<24))
#define LSADC_PAD7_LEVEL_SET4_level_4_end_val(data)                   (0x00FF0000&((data)<<16))
#define LSADC_PAD7_LEVEL_SET4_block4en(data)                          (0x00008000&((data)<<15))
#define LSADC_PAD7_LEVEL_SET4_int_en4(data)                           (0x00000002&((data)<<1))
#define LSADC_PAD7_LEVEL_SET4_int_pending_bit4(data)                  (0x00000001&(data))
#define LSADC_PAD7_LEVEL_SET4_get_level_4_start_val(data)             ((0xFF000000&(data))>>24)
#define LSADC_PAD7_LEVEL_SET4_get_level_4_end_val(data)               ((0x00FF0000&(data))>>16)
#define LSADC_PAD7_LEVEL_SET4_get_block4en(data)                      ((0x00008000&(data))>>15)
#define LSADC_PAD7_LEVEL_SET4_get_int_en4(data)                       ((0x00000002&(data))>>1)
#define LSADC_PAD7_LEVEL_SET4_get_int_pending_bit4(data)              (0x00000001&(data))


#define LSADC_PAD7_LEVEL_SET5                                         0x18011584
#define LSADC_PAD7_LEVEL_SET5_reg_addr                                "0xb8011584"
#define LSADC_PAD7_LEVEL_SET5_reg                                     0xb8011584
#define LSADC_PAD7_LEVEL_SET5_inst_addr                               "0x0161"
#define LSADC_PAD7_LEVEL_SET5_inst                                    0x0161
#define LSADC_PAD7_LEVEL_SET5_level_5_start_val_shift                 (24)
#define LSADC_PAD7_LEVEL_SET5_level_5_end_val_shift                   (16)
#define LSADC_PAD7_LEVEL_SET5_block5en_shift                          (15)
#define LSADC_PAD7_LEVEL_SET5_int_en5_shift                           (1)
#define LSADC_PAD7_LEVEL_SET5_int_pending_bit5_shift                  (0)
#define LSADC_PAD7_LEVEL_SET5_level_5_start_val_mask                  (0xFF000000)
#define LSADC_PAD7_LEVEL_SET5_level_5_end_val_mask                    (0x00FF0000)
#define LSADC_PAD7_LEVEL_SET5_block5en_mask                           (0x00008000)
#define LSADC_PAD7_LEVEL_SET5_int_en5_mask                            (0x00000002)
#define LSADC_PAD7_LEVEL_SET5_int_pending_bit5_mask                   (0x00000001)
#define LSADC_PAD7_LEVEL_SET5_level_5_start_val(data)                 (0xFF000000&((data)<<24))
#define LSADC_PAD7_LEVEL_SET5_level_5_end_val(data)                   (0x00FF0000&((data)<<16))
#define LSADC_PAD7_LEVEL_SET5_block5en(data)                          (0x00008000&((data)<<15))
#define LSADC_PAD7_LEVEL_SET5_int_en5(data)                           (0x00000002&((data)<<1))
#define LSADC_PAD7_LEVEL_SET5_int_pending_bit5(data)                  (0x00000001&(data))
#define LSADC_PAD7_LEVEL_SET5_get_level_5_start_val(data)             ((0xFF000000&(data))>>24)
#define LSADC_PAD7_LEVEL_SET5_get_level_5_end_val(data)               ((0x00FF0000&(data))>>16)
#define LSADC_PAD7_LEVEL_SET5_get_block5en(data)                      ((0x00008000&(data))>>15)
#define LSADC_PAD7_LEVEL_SET5_get_int_en5(data)                       ((0x00000002&(data))>>1)
#define LSADC_PAD7_LEVEL_SET5_get_int_pending_bit5(data)              (0x00000001&(data))


#define LSADC_PAD7_LEVEL_SET6                                         0x18011588
#define LSADC_PAD7_LEVEL_SET6_reg_addr                                "0xb8011588"
#define LSADC_PAD7_LEVEL_SET6_reg                                     0xb8011588
#define LSADC_PAD7_LEVEL_SET6_inst_addr                               "0x0162"
#define LSADC_PAD7_LEVEL_SET6_inst                                    0x0162
#define LSADC_PAD7_LEVEL_SET6_level_6_start_val_shift                 (24)
#define LSADC_PAD7_LEVEL_SET6_level_6_end_val_shift                   (16)
#define LSADC_PAD7_LEVEL_SET6_block6en_shift                          (15)
#define LSADC_PAD7_LEVEL_SET6_int_en6_shift                           (1)
#define LSADC_PAD7_LEVEL_SET6_int_pending_bit6_shift                  (0)
#define LSADC_PAD7_LEVEL_SET6_level_6_start_val_mask                  (0xFF000000)
#define LSADC_PAD7_LEVEL_SET6_level_6_end_val_mask                    (0x00FF0000)
#define LSADC_PAD7_LEVEL_SET6_block6en_mask                           (0x00008000)
#define LSADC_PAD7_LEVEL_SET6_int_en6_mask                            (0x00000002)
#define LSADC_PAD7_LEVEL_SET6_int_pending_bit6_mask                   (0x00000001)
#define LSADC_PAD7_LEVEL_SET6_level_6_start_val(data)                 (0xFF000000&((data)<<24))
#define LSADC_PAD7_LEVEL_SET6_level_6_end_val(data)                   (0x00FF0000&((data)<<16))
#define LSADC_PAD7_LEVEL_SET6_block6en(data)                          (0x00008000&((data)<<15))
#define LSADC_PAD7_LEVEL_SET6_int_en6(data)                           (0x00000002&((data)<<1))
#define LSADC_PAD7_LEVEL_SET6_int_pending_bit6(data)                  (0x00000001&(data))
#define LSADC_PAD7_LEVEL_SET6_get_level_6_start_val(data)             ((0xFF000000&(data))>>24)
#define LSADC_PAD7_LEVEL_SET6_get_level_6_end_val(data)               ((0x00FF0000&(data))>>16)
#define LSADC_PAD7_LEVEL_SET6_get_block6en(data)                      ((0x00008000&(data))>>15)
#define LSADC_PAD7_LEVEL_SET6_get_int_en6(data)                       ((0x00000002&(data))>>1)
#define LSADC_PAD7_LEVEL_SET6_get_int_pending_bit6(data)              (0x00000001&(data))


#define LSADC_PAD7_LEVEL_SET7                                         0x1801158c
#define LSADC_PAD7_LEVEL_SET7_reg_addr                                "0xb801158c"
#define LSADC_PAD7_LEVEL_SET7_reg                                     0xb801158c
#define LSADC_PAD7_LEVEL_SET7_inst_addr                               "0x0163"
#define LSADC_PAD7_LEVEL_SET7_inst                                    0x0163
#define LSADC_PAD7_LEVEL_SET7_level_7_start_val_shift                 (24)
#define LSADC_PAD7_LEVEL_SET7_level_7_end_val_shift                   (16)
#define LSADC_PAD7_LEVEL_SET7_block7en_shift                          (15)
#define LSADC_PAD7_LEVEL_SET7_int_en7_shift                           (1)
#define LSADC_PAD7_LEVEL_SET7_int_pending_bit7_shift                  (0)
#define LSADC_PAD7_LEVEL_SET7_level_7_start_val_mask                  (0xFF000000)
#define LSADC_PAD7_LEVEL_SET7_level_7_end_val_mask                    (0x00FF0000)
#define LSADC_PAD7_LEVEL_SET7_block7en_mask                           (0x00008000)
#define LSADC_PAD7_LEVEL_SET7_int_en7_mask                            (0x00000002)
#define LSADC_PAD7_LEVEL_SET7_int_pending_bit7_mask                   (0x00000001)
#define LSADC_PAD7_LEVEL_SET7_level_7_start_val(data)                 (0xFF000000&((data)<<24))
#define LSADC_PAD7_LEVEL_SET7_level_7_end_val(data)                   (0x00FF0000&((data)<<16))
#define LSADC_PAD7_LEVEL_SET7_block7en(data)                          (0x00008000&((data)<<15))
#define LSADC_PAD7_LEVEL_SET7_int_en7(data)                           (0x00000002&((data)<<1))
#define LSADC_PAD7_LEVEL_SET7_int_pending_bit7(data)                  (0x00000001&(data))
#define LSADC_PAD7_LEVEL_SET7_get_level_7_start_val(data)             ((0xFF000000&(data))>>24)
#define LSADC_PAD7_LEVEL_SET7_get_level_7_end_val(data)               ((0x00FF0000&(data))>>16)
#define LSADC_PAD7_LEVEL_SET7_get_block7en(data)                      ((0x00008000&(data))>>15)
#define LSADC_PAD7_LEVEL_SET7_get_int_en7(data)                       ((0x00000002&(data))>>1)
#define LSADC_PAD7_LEVEL_SET7_get_int_pending_bit7(data)              (0x00000001&(data))


#define LSADC_INT_PAD5                                                0x18011590
#define LSADC_INT_PAD5_reg_addr                                       "0xb8011590"
#define LSADC_INT_PAD5_reg                                            0xb8011590
#define LSADC_INT_PAD5_inst_addr                                      "0x0164"
#define LSADC_INT_PAD5_inst                                           0x0164
#define LSADC_INT_PAD5_adc_value5latch_shift                          (8)
#define LSADC_INT_PAD5_int_latchstatus_shift                          (0)
#define LSADC_INT_PAD5_adc_value5latch_mask                           (0x0000FF00)
#define LSADC_INT_PAD5_int_latchstatus_mask                           (0x000000FF)
#define LSADC_INT_PAD5_adc_value5latch(data)                          (0x0000FF00&((data)<<8))
#define LSADC_INT_PAD5_int_latchstatus(data)                          (0x000000FF&(data))
#define LSADC_INT_PAD5_get_adc_value5latch(data)                      ((0x0000FF00&(data))>>8)
#define LSADC_INT_PAD5_get_int_latchstatus(data)                      (0x000000FF&(data))


#define LSADC_INT_PAD6                                                0x18011594
#define LSADC_INT_PAD6_reg_addr                                       "0xb8011594"
#define LSADC_INT_PAD6_reg                                            0xb8011594
#define LSADC_INT_PAD6_inst_addr                                      "0x0165"
#define LSADC_INT_PAD6_inst                                           0x0165
#define LSADC_INT_PAD6_adc_value6latch_shift                          (8)
#define LSADC_INT_PAD6_int_latchstatus_shift                          (0)
#define LSADC_INT_PAD6_adc_value6latch_mask                           (0x0000FF00)
#define LSADC_INT_PAD6_int_latchstatus_mask                           (0x000000FF)
#define LSADC_INT_PAD6_adc_value6latch(data)                          (0x0000FF00&((data)<<8))
#define LSADC_INT_PAD6_int_latchstatus(data)                          (0x000000FF&(data))
#define LSADC_INT_PAD6_get_adc_value6latch(data)                      ((0x0000FF00&(data))>>8)
#define LSADC_INT_PAD6_get_int_latchstatus(data)                      (0x000000FF&(data))


#define LSADC_INT_PAD7                                                0x18011598
#define LSADC_INT_PAD7_reg_addr                                       "0xb8011598"
#define LSADC_INT_PAD7_reg                                            0xb8011598
#define LSADC_INT_PAD7_inst_addr                                      "0x0166"
#define LSADC_INT_PAD7_inst                                           0x0166
#define LSADC_INT_PAD7_adc_value7latch_shift                          (8)
#define LSADC_INT_PAD7_int_latchstatus_shift                          (0)
#define LSADC_INT_PAD7_adc_value7latch_mask                           (0x0000FF00)
#define LSADC_INT_PAD7_int_latchstatus_mask                           (0x000000FF)
#define LSADC_INT_PAD7_adc_value7latch(data)                          (0x0000FF00&((data)<<8))
#define LSADC_INT_PAD7_int_latchstatus(data)                          (0x000000FF&(data))
#define LSADC_INT_PAD7_get_adc_value7latch(data)                      ((0x0000FF00&(data))>>8)
#define LSADC_INT_PAD7_get_int_latchstatus(data)                      (0x000000FF&(data))


#define ST_TMR0_DR                                                    0x18011600
#define ST_TMR0_DR_reg_addr                                           "0xb8011600"
#define ST_TMR0_DR_reg                                                0xb8011600
#define ST_TMR0_DR_inst_addr                                          "0x0180"
#define ST_TMR0_DR_inst                                               0x0180
#define ST_TMR0_DR_range_23_0_shift                                   (8)
#define ST_TMR0_DR_range_23_0_mask                                    (0xFFFFFF00)
#define ST_TMR0_DR_range_23_0(data)                                   (0xFFFFFF00&((data)<<8))
#define ST_TMR0_DR_get_range_23_0(data)                               ((0xFFFFFF00&(data))>>8)


#define ST_TMR0_VR                                                    0x18011604
#define ST_TMR0_VR_reg_addr                                           "0xb8011604"
#define ST_TMR0_VR_reg                                                0xb8011604
#define ST_TMR0_VR_inst_addr                                          "0x0181"
#define ST_TMR0_VR_inst                                               0x0181
#define ST_TMR0_VR_value_23_0_shift                                   (8)
#define ST_TMR0_VR_tcip_shift                                         (0)
#define ST_TMR0_VR_value_23_0_mask                                    (0xFFFFFF00)
#define ST_TMR0_VR_tcip_mask                                          (0x00000001)
#define ST_TMR0_VR_value_23_0(data)                                   (0xFFFFFF00&((data)<<8))
#define ST_TMR0_VR_tcip(data)                                         (0x00000001&(data))
#define ST_TMR0_VR_get_value_23_0(data)                               ((0xFFFFFF00&(data))>>8)
#define ST_TMR0_VR_get_tcip(data)                                     (0x00000001&(data))


#define ST_TMR0_CR                                                    0x18011608
#define ST_TMR0_CR_reg_addr                                           "0xb8011608"
#define ST_TMR0_CR_reg                                                0xb8011608
#define ST_TMR0_CR_inst_addr                                          "0x0182"
#define ST_TMR0_CR_inst                                               0x0182
#define ST_TMR0_CR_en_shift                                           (31)
#define ST_TMR0_CR_mode_shift                                         (30)
#define ST_TMR0_CR_tc0ie_shift                                        (29)
#define ST_TMR0_CR_en_mask                                            (0x80000000)
#define ST_TMR0_CR_mode_mask                                          (0x40000000)
#define ST_TMR0_CR_tc0ie_mask                                         (0x20000000)
#define ST_TMR0_CR_en(data)                                           (0x80000000&((data)<<31))
#define ST_TMR0_CR_mode(data)                                         (0x40000000&((data)<<30))
#define ST_TMR0_CR_tc0ie(data)                                        (0x20000000&((data)<<29))
#define ST_TMR0_CR_get_en(data)                                       ((0x80000000&(data))>>31)
#define ST_TMR0_CR_get_mode(data)                                     ((0x40000000&(data))>>30)
#define ST_TMR0_CR_get_tc0ie(data)                                    ((0x20000000&(data))>>29)


#define ST_TMR0_DBR                                                   0x1801160c
#define ST_TMR0_DBR_reg_addr                                          "0xb801160c"
#define ST_TMR0_DBR_reg                                               0xb801160c
#define ST_TMR0_DBR_inst_addr                                         "0x0183"
#define ST_TMR0_DBR_inst                                              0x0183
#define ST_TMR0_DBR_df0_15_0_shift                                    (16)
#define ST_TMR0_DBR_df0_15_0_mask                                     (0xFFFF0000)
#define ST_TMR0_DBR_df0_15_0(data)                                    (0xFFFF0000&((data)<<16))
#define ST_TMR0_DBR_get_df0_15_0(data)                                ((0xFFFF0000&(data))>>16)


#define ST_TMR1_DR                                                    0x18011610
#define ST_TMR1_DR_reg_addr                                           "0xb8011610"
#define ST_TMR1_DR_reg                                                0xb8011610
#define ST_TMR1_DR_inst_addr                                          "0x0184"
#define ST_TMR1_DR_inst                                               0x0184
#define ST_TMR1_DR_range_23_0_shift                                   (8)
#define ST_TMR1_DR_range_23_0_mask                                    (0xFFFFFF00)
#define ST_TMR1_DR_range_23_0(data)                                   (0xFFFFFF00&((data)<<8))
#define ST_TMR1_DR_get_range_23_0(data)                               ((0xFFFFFF00&(data))>>8)


#define ST_TMR1_VR                                                    0x18011614
#define ST_TMR1_VR_reg_addr                                           "0xb8011614"
#define ST_TMR1_VR_reg                                                0xb8011614
#define ST_TMR1_VR_inst_addr                                          "0x0185"
#define ST_TMR1_VR_inst                                               0x0185
#define ST_TMR1_VR_value_23_0_shift                                   (8)
#define ST_TMR1_VR_tcip_shift                                         (0)
#define ST_TMR1_VR_value_23_0_mask                                    (0xFFFFFF00)
#define ST_TMR1_VR_tcip_mask                                          (0x00000001)
#define ST_TMR1_VR_value_23_0(data)                                   (0xFFFFFF00&((data)<<8))
#define ST_TMR1_VR_tcip(data)                                         (0x00000001&(data))
#define ST_TMR1_VR_get_value_23_0(data)                               ((0xFFFFFF00&(data))>>8)
#define ST_TMR1_VR_get_tcip(data)                                     (0x00000001&(data))


#define ST_TMR1_CR                                                    0x18011618
#define ST_TMR1_CR_reg_addr                                           "0xb8011618"
#define ST_TMR1_CR_reg                                                0xb8011618
#define ST_TMR1_CR_inst_addr                                          "0x0186"
#define ST_TMR1_CR_inst                                               0x0186
#define ST_TMR1_CR_en_shift                                           (31)
#define ST_TMR1_CR_mode_shift                                         (30)
#define ST_TMR1_CR_tc1ie_shift                                        (29)
#define ST_TMR1_CR_en_mask                                            (0x80000000)
#define ST_TMR1_CR_mode_mask                                          (0x40000000)
#define ST_TMR1_CR_tc1ie_mask                                         (0x20000000)
#define ST_TMR1_CR_en(data)                                           (0x80000000&((data)<<31))
#define ST_TMR1_CR_mode(data)                                         (0x40000000&((data)<<30))
#define ST_TMR1_CR_tc1ie(data)                                        (0x20000000&((data)<<29))
#define ST_TMR1_CR_get_en(data)                                       ((0x80000000&(data))>>31)
#define ST_TMR1_CR_get_mode(data)                                     ((0x40000000&(data))>>30)
#define ST_TMR1_CR_get_tc1ie(data)                                    ((0x20000000&(data))>>29)


#define ST_TMR1_DBR                                                   0x1801161c
#define ST_TMR1_DBR_reg_addr                                          "0xb801161c"
#define ST_TMR1_DBR_reg                                               0xb801161c
#define ST_TMR1_DBR_inst_addr                                         "0x0187"
#define ST_TMR1_DBR_inst                                              0x0187
#define ST_TMR1_DBR_df1_15_0_shift                                    (16)
#define ST_TMR1_DBR_df1_15_0_mask                                     (0xFFFF0000)
#define ST_TMR1_DBR_df1_15_0(data)                                    (0xFFFF0000&((data)<<16))
#define ST_TMR1_DBR_get_df1_15_0(data)                                ((0xFFFF0000&(data))>>16)


#define ST_TMR2_DR                                                    0x18011620
#define ST_TMR2_DR_reg_addr                                           "0xb8011620"
#define ST_TMR2_DR_reg                                                0xb8011620
#define ST_TMR2_DR_inst_addr                                          "0x0188"
#define ST_TMR2_DR_inst                                               0x0188
#define ST_TMR2_DR_range_23_0_shift                                   (8)
#define ST_TMR2_DR_range_23_0_mask                                    (0xFFFFFF00)
#define ST_TMR2_DR_range_23_0(data)                                   (0xFFFFFF00&((data)<<8))
#define ST_TMR2_DR_get_range_23_0(data)                               ((0xFFFFFF00&(data))>>8)


#define ST_TMR2_VR                                                    0x18011624
#define ST_TMR2_VR_reg_addr                                           "0xb8011624"
#define ST_TMR2_VR_reg                                                0xb8011624
#define ST_TMR2_VR_inst_addr                                          "0x0189"
#define ST_TMR2_VR_inst                                               0x0189
#define ST_TMR2_VR_value_23_0_shift                                   (8)
#define ST_TMR2_VR_tcip_shift                                         (0)
#define ST_TMR2_VR_value_23_0_mask                                    (0xFFFFFF00)
#define ST_TMR2_VR_tcip_mask                                          (0x00000001)
#define ST_TMR2_VR_value_23_0(data)                                   (0xFFFFFF00&((data)<<8))
#define ST_TMR2_VR_tcip(data)                                         (0x00000001&(data))
#define ST_TMR2_VR_get_value_23_0(data)                               ((0xFFFFFF00&(data))>>8)
#define ST_TMR2_VR_get_tcip(data)                                     (0x00000001&(data))


#define ST_TMR2_CR                                                    0x18011628
#define ST_TMR2_CR_reg_addr                                           "0xb8011628"
#define ST_TMR2_CR_reg                                                0xb8011628
#define ST_TMR2_CR_inst_addr                                          "0x018A"
#define ST_TMR2_CR_inst                                               0x018A
#define ST_TMR2_CR_en_shift                                           (31)
#define ST_TMR2_CR_mode_shift                                         (30)
#define ST_TMR2_CR_tc2ie_shift                                        (29)
#define ST_TMR2_CR_en_mask                                            (0x80000000)
#define ST_TMR2_CR_mode_mask                                          (0x40000000)
#define ST_TMR2_CR_tc2ie_mask                                         (0x20000000)
#define ST_TMR2_CR_en(data)                                           (0x80000000&((data)<<31))
#define ST_TMR2_CR_mode(data)                                         (0x40000000&((data)<<30))
#define ST_TMR2_CR_tc2ie(data)                                        (0x20000000&((data)<<29))
#define ST_TMR2_CR_get_en(data)                                       ((0x80000000&(data))>>31)
#define ST_TMR2_CR_get_mode(data)                                     ((0x40000000&(data))>>30)
#define ST_TMR2_CR_get_tc2ie(data)                                    ((0x20000000&(data))>>29)


#define ST_TMR2_DBR                                                   0x1801162c
#define ST_TMR2_DBR_reg_addr                                          "0xb801162c"
#define ST_TMR2_DBR_reg                                               0xb801162c
#define ST_TMR2_DBR_inst_addr                                         "0x018B"
#define ST_TMR2_DBR_inst                                              0x018B
#define ST_TMR2_DBR_df2_15_0_shift                                    (16)
#define ST_TMR2_DBR_df2_15_0_mask                                     (0xFFFF0000)
#define ST_TMR2_DBR_df2_15_0(data)                                    (0xFFFF0000&((data)<<16))
#define ST_TMR2_DBR_get_df2_15_0(data)                                ((0xFFFF0000&(data))>>16)


#define ST_TMR3_DR                                                    0x18011630
#define ST_TMR3_DR_reg_addr                                           "0xb8011630"
#define ST_TMR3_DR_reg                                                0xb8011630
#define ST_TMR3_DR_inst_addr                                          "0x018C"
#define ST_TMR3_DR_inst                                               0x018C
#define ST_TMR3_DR_range_23_0_shift                                   (8)
#define ST_TMR3_DR_range_23_0_mask                                    (0xFFFFFF00)
#define ST_TMR3_DR_range_23_0(data)                                   (0xFFFFFF00&((data)<<8))
#define ST_TMR3_DR_get_range_23_0(data)                               ((0xFFFFFF00&(data))>>8)


#define ST_TMR3_VR                                                    0x18011634
#define ST_TMR3_VR_reg_addr                                           "0xb8011634"
#define ST_TMR3_VR_reg                                                0xb8011634
#define ST_TMR3_VR_inst_addr                                          "0x018D"
#define ST_TMR3_VR_inst                                               0x018D
#define ST_TMR3_VR_value_23_0_shift                                   (8)
#define ST_TMR3_VR_tcip_shift                                         (0)
#define ST_TMR3_VR_value_23_0_mask                                    (0xFFFFFF00)
#define ST_TMR3_VR_tcip_mask                                          (0x00000001)
#define ST_TMR3_VR_value_23_0(data)                                   (0xFFFFFF00&((data)<<8))
#define ST_TMR3_VR_tcip(data)                                         (0x00000001&(data))
#define ST_TMR3_VR_get_value_23_0(data)                               ((0xFFFFFF00&(data))>>8)
#define ST_TMR3_VR_get_tcip(data)                                     (0x00000001&(data))


#define ST_TMR3_CR                                                    0x18011638
#define ST_TMR3_CR_reg_addr                                           "0xb8011638"
#define ST_TMR3_CR_reg                                                0xb8011638
#define ST_TMR3_CR_inst_addr                                          "0x018E"
#define ST_TMR3_CR_inst                                               0x018E
#define ST_TMR3_CR_en_shift                                           (31)
#define ST_TMR3_CR_mode_shift                                         (30)
#define ST_TMR3_CR_tc3ie_shift                                        (29)
#define ST_TMR3_CR_en_mask                                            (0x80000000)
#define ST_TMR3_CR_mode_mask                                          (0x40000000)
#define ST_TMR3_CR_tc3ie_mask                                         (0x20000000)
#define ST_TMR3_CR_en(data)                                           (0x80000000&((data)<<31))
#define ST_TMR3_CR_mode(data)                                         (0x40000000&((data)<<30))
#define ST_TMR3_CR_tc3ie(data)                                        (0x20000000&((data)<<29))
#define ST_TMR3_CR_get_en(data)                                       ((0x80000000&(data))>>31)
#define ST_TMR3_CR_get_mode(data)                                     ((0x40000000&(data))>>30)
#define ST_TMR3_CR_get_tc3ie(data)                                    ((0x20000000&(data))>>29)


#define ST_TMR3_DBR                                                   0x1801163c
#define ST_TMR3_DBR_reg_addr                                          "0xb801163c"
#define ST_TMR3_DBR_reg                                               0xb801163c
#define ST_TMR3_DBR_inst_addr                                         "0x018F"
#define ST_TMR3_DBR_inst                                              0x018F
#define ST_TMR3_DBR_df3_15_0_shift                                    (16)
#define ST_TMR3_DBR_df3_15_0_mask                                     (0xFFFF0000)
#define ST_TMR3_DBR_df3_15_0(data)                                    (0xFFFF0000&((data)<<16))
#define ST_TMR3_DBR_get_df3_15_0(data)                                ((0xFFFF0000&(data))>>16)


#define ST_TMR4_DR                                                    0x18011640
#define ST_TMR4_DR_reg_addr                                           "0xb8011640"
#define ST_TMR4_DR_reg                                                0xb8011640
#define ST_TMR4_DR_inst_addr                                          "0x0190"
#define ST_TMR4_DR_inst                                               0x0190
#define ST_TMR4_DR_range_23_0_shift                                   (8)
#define ST_TMR4_DR_range_23_0_mask                                    (0xFFFFFF00)
#define ST_TMR4_DR_range_23_0(data)                                   (0xFFFFFF00&((data)<<8))
#define ST_TMR4_DR_get_range_23_0(data)                               ((0xFFFFFF00&(data))>>8)


#define ST_TMR4_VR                                                    0x18011644
#define ST_TMR4_VR_reg_addr                                           "0xb8011644"
#define ST_TMR4_VR_reg                                                0xb8011644
#define ST_TMR4_VR_inst_addr                                          "0x0191"
#define ST_TMR4_VR_inst                                               0x0191
#define ST_TMR4_VR_value_23_0_shift                                   (8)
#define ST_TMR4_VR_tcip_shift                                         (0)
#define ST_TMR4_VR_value_23_0_mask                                    (0xFFFFFF00)
#define ST_TMR4_VR_tcip_mask                                          (0x00000001)
#define ST_TMR4_VR_value_23_0(data)                                   (0xFFFFFF00&((data)<<8))
#define ST_TMR4_VR_tcip(data)                                         (0x00000001&(data))
#define ST_TMR4_VR_get_value_23_0(data)                               ((0xFFFFFF00&(data))>>8)
#define ST_TMR4_VR_get_tcip(data)                                     (0x00000001&(data))


#define ST_TMR4_CR                                                    0x18011648
#define ST_TMR4_CR_reg_addr                                           "0xb8011648"
#define ST_TMR4_CR_reg                                                0xb8011648
#define ST_TMR4_CR_inst_addr                                          "0x0192"
#define ST_TMR4_CR_inst                                               0x0192
#define ST_TMR4_CR_en_shift                                           (31)
#define ST_TMR4_CR_mode_shift                                         (30)
#define ST_TMR4_CR_tc4ie_shift                                        (29)
#define ST_TMR4_CR_en_mask                                            (0x80000000)
#define ST_TMR4_CR_mode_mask                                          (0x40000000)
#define ST_TMR4_CR_tc4ie_mask                                         (0x20000000)
#define ST_TMR4_CR_en(data)                                           (0x80000000&((data)<<31))
#define ST_TMR4_CR_mode(data)                                         (0x40000000&((data)<<30))
#define ST_TMR4_CR_tc4ie(data)                                        (0x20000000&((data)<<29))
#define ST_TMR4_CR_get_en(data)                                       ((0x80000000&(data))>>31)
#define ST_TMR4_CR_get_mode(data)                                     ((0x40000000&(data))>>30)
#define ST_TMR4_CR_get_tc4ie(data)                                    ((0x20000000&(data))>>29)


#define ST_TMR4_DBR                                                   0x1801164c
#define ST_TMR4_DBR_reg_addr                                          "0xb801164c"
#define ST_TMR4_DBR_reg                                               0xb801164c
#define ST_TMR4_DBR_inst_addr                                         "0x0193"
#define ST_TMR4_DBR_inst                                              0x0193
#define ST_TMR4_DBR_df4_15_0_shift                                    (16)
#define ST_TMR4_DBR_df4_15_0_mask                                     (0xFFFF0000)
#define ST_TMR4_DBR_df4_15_0(data)                                    (0xFFFF0000&((data)<<16))
#define ST_TMR4_DBR_get_df4_15_0(data)                                ((0xFFFF0000&(data))>>16)


#define ST_TMR5_DR                                                    0x18011650
#define ST_TMR5_DR_reg_addr                                           "0xb8011650"
#define ST_TMR5_DR_reg                                                0xb8011650
#define ST_TMR5_DR_inst_addr                                          "0x0194"
#define ST_TMR5_DR_inst                                               0x0194
#define ST_TMR5_DR_range_23_0_shift                                   (8)
#define ST_TMR5_DR_range_23_0_mask                                    (0xFFFFFF00)
#define ST_TMR5_DR_range_23_0(data)                                   (0xFFFFFF00&((data)<<8))
#define ST_TMR5_DR_get_range_23_0(data)                               ((0xFFFFFF00&(data))>>8)


#define ST_TMR5_VR                                                    0x18011654
#define ST_TMR5_VR_reg_addr                                           "0xb8011654"
#define ST_TMR5_VR_reg                                                0xb8011654
#define ST_TMR5_VR_inst_addr                                          "0x0195"
#define ST_TMR5_VR_inst                                               0x0195
#define ST_TMR5_VR_value_23_0_shift                                   (8)
#define ST_TMR5_VR_tcip_shift                                         (0)
#define ST_TMR5_VR_value_23_0_mask                                    (0xFFFFFF00)
#define ST_TMR5_VR_tcip_mask                                          (0x00000001)
#define ST_TMR5_VR_value_23_0(data)                                   (0xFFFFFF00&((data)<<8))
#define ST_TMR5_VR_tcip(data)                                         (0x00000001&(data))
#define ST_TMR5_VR_get_value_23_0(data)                               ((0xFFFFFF00&(data))>>8)
#define ST_TMR5_VR_get_tcip(data)                                     (0x00000001&(data))


#define ST_TMR5_CR                                                    0x18011658
#define ST_TMR5_CR_reg_addr                                           "0xb8011658"
#define ST_TMR5_CR_reg                                                0xb8011658
#define ST_TMR5_CR_inst_addr                                          "0x0196"
#define ST_TMR5_CR_inst                                               0x0196
#define ST_TMR5_CR_en_shift                                           (31)
#define ST_TMR5_CR_mode_shift                                         (30)
#define ST_TMR5_CR_tc5ie_shift                                        (29)
#define ST_TMR5_CR_en_mask                                            (0x80000000)
#define ST_TMR5_CR_mode_mask                                          (0x40000000)
#define ST_TMR5_CR_tc5ie_mask                                         (0x20000000)
#define ST_TMR5_CR_en(data)                                           (0x80000000&((data)<<31))
#define ST_TMR5_CR_mode(data)                                         (0x40000000&((data)<<30))
#define ST_TMR5_CR_tc5ie(data)                                        (0x20000000&((data)<<29))
#define ST_TMR5_CR_get_en(data)                                       ((0x80000000&(data))>>31)
#define ST_TMR5_CR_get_mode(data)                                     ((0x40000000&(data))>>30)
#define ST_TMR5_CR_get_tc5ie(data)                                    ((0x20000000&(data))>>29)


#define ST_TMR5_DBR                                                   0x1801165c
#define ST_TMR5_DBR_reg_addr                                          "0xb801165c"
#define ST_TMR5_DBR_reg                                               0xb801165c
#define ST_TMR5_DBR_inst_addr                                         "0x0197"
#define ST_TMR5_DBR_inst                                              0x0197
#define ST_TMR5_DBR_df5_15_0_shift                                    (16)
#define ST_TMR5_DBR_df5_15_0_mask                                     (0xFFFF0000)
#define ST_TMR5_DBR_df5_15_0(data)                                    (0xFFFF0000&((data)<<16))
#define ST_TMR5_DBR_get_df5_15_0(data)                                ((0xFFFF0000&(data))>>16)


#define ST_TMR6_DR                                                    0x18011660
#define ST_TMR6_DR_reg_addr                                           "0xb8011660"
#define ST_TMR6_DR_reg                                                0xb8011660
#define ST_TMR6_DR_inst_addr                                          "0x0198"
#define ST_TMR6_DR_inst                                               0x0198
#define ST_TMR6_DR_range_23_0_shift                                   (8)
#define ST_TMR6_DR_range_23_0_mask                                    (0xFFFFFF00)
#define ST_TMR6_DR_range_23_0(data)                                   (0xFFFFFF00&((data)<<8))
#define ST_TMR6_DR_get_range_23_0(data)                               ((0xFFFFFF00&(data))>>8)


#define ST_TMR6_VR                                                    0x18011664
#define ST_TMR6_VR_reg_addr                                           "0xb8011664"
#define ST_TMR6_VR_reg                                                0xb8011664
#define ST_TMR6_VR_inst_addr                                          "0x0199"
#define ST_TMR6_VR_inst                                               0x0199
#define ST_TMR6_VR_value_23_0_shift                                   (8)
#define ST_TMR6_VR_tcip_shift                                         (0)
#define ST_TMR6_VR_value_23_0_mask                                    (0xFFFFFF00)
#define ST_TMR6_VR_tcip_mask                                          (0x00000001)
#define ST_TMR6_VR_value_23_0(data)                                   (0xFFFFFF00&((data)<<8))
#define ST_TMR6_VR_tcip(data)                                         (0x00000001&(data))
#define ST_TMR6_VR_get_value_23_0(data)                               ((0xFFFFFF00&(data))>>8)
#define ST_TMR6_VR_get_tcip(data)                                     (0x00000001&(data))


#define ST_TMR6_CR                                                    0x18011668
#define ST_TMR6_CR_reg_addr                                           "0xb8011668"
#define ST_TMR6_CR_reg                                                0xb8011668
#define ST_TMR6_CR_inst_addr                                          "0x019A"
#define ST_TMR6_CR_inst                                               0x019A
#define ST_TMR6_CR_en_shift                                           (31)
#define ST_TMR6_CR_mode_shift                                         (30)
#define ST_TMR6_CR_tc6ie_shift                                        (29)
#define ST_TMR6_CR_en_mask                                            (0x80000000)
#define ST_TMR6_CR_mode_mask                                          (0x40000000)
#define ST_TMR6_CR_tc6ie_mask                                         (0x20000000)
#define ST_TMR6_CR_en(data)                                           (0x80000000&((data)<<31))
#define ST_TMR6_CR_mode(data)                                         (0x40000000&((data)<<30))
#define ST_TMR6_CR_tc6ie(data)                                        (0x20000000&((data)<<29))
#define ST_TMR6_CR_get_en(data)                                       ((0x80000000&(data))>>31)
#define ST_TMR6_CR_get_mode(data)                                     ((0x40000000&(data))>>30)
#define ST_TMR6_CR_get_tc6ie(data)                                    ((0x20000000&(data))>>29)


#define ST_TMR6_DBR                                                   0x1801166c
#define ST_TMR6_DBR_reg_addr                                          "0xb801166c"
#define ST_TMR6_DBR_reg                                               0xb801166c
#define ST_TMR6_DBR_inst_addr                                         "0x019B"
#define ST_TMR6_DBR_inst                                              0x019B
#define ST_TMR6_DBR_df6_15_0_shift                                    (16)
#define ST_TMR6_DBR_df6_15_0_mask                                     (0xFFFF0000)
#define ST_TMR6_DBR_df6_15_0(data)                                    (0xFFFF0000&((data)<<16))
#define ST_TMR6_DBR_get_df6_15_0(data)                                ((0xFFFF0000&(data))>>16)


#define ST_TMR7_DR                                                    0x18011670
#define ST_TMR7_DR_reg_addr                                           "0xb8011670"
#define ST_TMR7_DR_reg                                                0xb8011670
#define ST_TMR7_DR_inst_addr                                          "0x019C"
#define ST_TMR7_DR_inst                                               0x019C
#define ST_TMR7_DR_range_23_0_shift                                   (8)
#define ST_TMR7_DR_range_23_0_mask                                    (0xFFFFFF00)
#define ST_TMR7_DR_range_23_0(data)                                   (0xFFFFFF00&((data)<<8))
#define ST_TMR7_DR_get_range_23_0(data)                               ((0xFFFFFF00&(data))>>8)


#define ST_TMR7_VR                                                    0x18011674
#define ST_TMR7_VR_reg_addr                                           "0xb8011674"
#define ST_TMR7_VR_reg                                                0xb8011674
#define ST_TMR7_VR_inst_addr                                          "0x019D"
#define ST_TMR7_VR_inst                                               0x019D
#define ST_TMR7_VR_value_23_0_shift                                   (8)
#define ST_TMR7_VR_tcip_shift                                         (0)
#define ST_TMR7_VR_value_23_0_mask                                    (0xFFFFFF00)
#define ST_TMR7_VR_tcip_mask                                          (0x00000001)
#define ST_TMR7_VR_value_23_0(data)                                   (0xFFFFFF00&((data)<<8))
#define ST_TMR7_VR_tcip(data)                                         (0x00000001&(data))
#define ST_TMR7_VR_get_value_23_0(data)                               ((0xFFFFFF00&(data))>>8)
#define ST_TMR7_VR_get_tcip(data)                                     (0x00000001&(data))


#define ST_TMR7_CR                                                    0x18011678
#define ST_TMR7_CR_reg_addr                                           "0xb8011678"
#define ST_TMR7_CR_reg                                                0xb8011678
#define ST_TMR7_CR_inst_addr                                          "0x019E"
#define ST_TMR7_CR_inst                                               0x019E
#define ST_TMR7_CR_en_shift                                           (31)
#define ST_TMR7_CR_mode_shift                                         (30)
#define ST_TMR7_CR_tc0ie_shift                                        (29)
#define ST_TMR7_CR_en_mask                                            (0x80000000)
#define ST_TMR7_CR_mode_mask                                          (0x40000000)
#define ST_TMR7_CR_tc0ie_mask                                         (0x20000000)
#define ST_TMR7_CR_en(data)                                           (0x80000000&((data)<<31))
#define ST_TMR7_CR_mode(data)                                         (0x40000000&((data)<<30))
#define ST_TMR7_CR_tc0ie(data)                                        (0x20000000&((data)<<29))
#define ST_TMR7_CR_get_en(data)                                       ((0x80000000&(data))>>31)
#define ST_TMR7_CR_get_mode(data)                                     ((0x40000000&(data))>>30)
#define ST_TMR7_CR_get_tc0ie(data)                                    ((0x20000000&(data))>>29)


#define ST_TMR7_DBR                                                   0x1801167c
#define ST_TMR7_DBR_reg_addr                                          "0xb801167c"
#define ST_TMR7_DBR_reg                                               0xb801167c
#define ST_TMR7_DBR_inst_addr                                         "0x019F"
#define ST_TMR7_DBR_inst                                              0x019F
#define ST_TMR7_DBR_df0_15_0_shift                                    (16)
#define ST_TMR7_DBR_df0_15_0_mask                                     (0xFFFF0000)
#define ST_TMR7_DBR_df0_15_0(data)                                    (0xFFFF0000&((data)<<16))
#define ST_TMR7_DBR_get_df0_15_0(data)                                ((0xFFFF0000&(data))>>16)


#define ST_WR_CR                                                      0x18011700
#define ST_WR_CR_reg_addr                                             "0xb8011700"
#define ST_WR_CR_reg                                                  0xb8011700
#define ST_WR_CR_inst_addr                                            "0x01C0"
#define ST_WR_CR_inst                                                 0x01C0
#define ST_WR_CR_ovsel_shift                                          (28)
#define ST_WR_CR_dummy18011700_18_12_shift                            (12)
#define ST_WR_CR_test_en_shift                                        (8)
#define ST_WR_CR_dummy18011700_3_shift                                (3)
#define ST_WR_CR_pwr_sel_shift                                        (2)
#define ST_WR_CR_trig_reset_shift                                     (1)
#define ST_WR_CR_enable_shift                                         (0)
#define ST_WR_CR_ovsel_mask                                           (0xF0000000)
#define ST_WR_CR_dummy18011700_18_12_mask                             (0x0007F000)
#define ST_WR_CR_test_en_mask                                         (0x00000100)
#define ST_WR_CR_dummy18011700_3_mask                                 (0x00000008)
#define ST_WR_CR_pwr_sel_mask                                         (0x00000004)
#define ST_WR_CR_trig_reset_mask                                      (0x00000002)
#define ST_WR_CR_enable_mask                                          (0x00000001)
#define ST_WR_CR_ovsel(data)                                          (0xF0000000&((data)<<28))
#define ST_WR_CR_dummy18011700_18_12(data)                            (0x0007F000&((data)<<12))
#define ST_WR_CR_test_en(data)                                        (0x00000100&((data)<<8))
#define ST_WR_CR_dummy18011700_3(data)                                (0x00000008&((data)<<3))
#define ST_WR_CR_pwr_sel(data)                                        (0x00000004&((data)<<2))
#define ST_WR_CR_trig_reset(data)                                     (0x00000002&((data)<<1))
#define ST_WR_CR_enable(data)                                         (0x00000001&(data))
#define ST_WR_CR_get_ovsel(data)                                      ((0xF0000000&(data))>>28)
#define ST_WR_CR_get_dummy18011700_18_12(data)                        ((0x0007F000&(data))>>12)
#define ST_WR_CR_get_test_en(data)                                    ((0x00000100&(data))>>8)
#define ST_WR_CR_get_dummy18011700_3(data)                            ((0x00000008&(data))>>3)
#define ST_WR_CR_get_pwr_sel(data)                                    ((0x00000004&(data))>>2)
#define ST_WR_CR_get_trig_reset(data)                                 ((0x00000002&(data))>>1)
#define ST_WR_CR_get_enable(data)                                     (0x00000001&(data))


#define ST_WR_TR                                                      0x18011704
#define ST_WR_TR_reg_addr                                             "0xb8011704"
#define ST_WR_TR_reg                                                  0xb8011704
#define ST_WR_TR_inst_addr                                            "0x01C1"
#define ST_WR_TR_inst                                                 0x01C1
#define ST_WR_TR_wdt_shift                                            (16)
#define ST_WR_TR_pause_shift                                          (1)
#define ST_WR_TR_wdt_clear_shift                                      (0)
#define ST_WR_TR_wdt_mask                                             (0xFFFF0000)
#define ST_WR_TR_pause_mask                                           (0x00000002)
#define ST_WR_TR_wdt_clear_mask                                       (0x00000001)
#define ST_WR_TR_wdt(data)                                            (0xFFFF0000&((data)<<16))
#define ST_WR_TR_pause(data)                                          (0x00000002&((data)<<1))
#define ST_WR_TR_wdt_clear(data)                                      (0x00000001&(data))
#define ST_WR_TR_get_wdt(data)                                        ((0xFFFF0000&(data))>>16)
#define ST_WR_TR_get_pause(data)                                      ((0x00000002&(data))>>1)
#define ST_WR_TR_get_wdt_clear(data)                                  (0x00000001&(data))


#define ST_WR_MR                                                      0x18011708
#define ST_WR_MR_reg_addr                                             "0xb8011708"
#define ST_WR_MR_reg                                                  0xb8011708
#define ST_WR_MR_inst_addr                                            "0x01C2"
#define ST_WR_MR_inst                                                 0x01C2
#define ST_WR_MR_wdc_3_0_shift                                        (16)
#define ST_WR_MR_wds_shift                                            (0)
#define ST_WR_MR_wdc_3_0_mask                                         (0x000F0000)
#define ST_WR_MR_wds_mask                                             (0x0000FFFF)
#define ST_WR_MR_wdc_3_0(data)                                        (0x000F0000&((data)<<16))
#define ST_WR_MR_wds(data)                                            (0x0000FFFF&(data))
#define ST_WR_MR_get_wdc_3_0(data)                                    ((0x000F0000&(data))>>16)
#define ST_WR_MR_get_wds(data)                                        (0x0000FFFF&(data))


#define ST_REC_IC_ST_CF                                               0x1801170c
#define ST_REC_IC_ST_CF_reg_addr                                      "0xb801170c"
#define ST_REC_IC_ST_CF_reg                                           0xb801170c
#define ST_REC_IC_ST_CF_inst_addr                                     "0x01C3"
#define ST_REC_IC_ST_CF_inst                                          0x01C3
#define ST_REC_IC_ST_CF_cpu_ack_shift                                 (6)
#define ST_REC_IC_ST_CF_int_ack_shift                                 (5)
#define ST_REC_IC_ST_CF_wdog_cnt_ovs_shift                            (4)
#define ST_REC_IC_ST_CF_cpu_ack_mask                                  (0x00000040)
#define ST_REC_IC_ST_CF_int_ack_mask                                  (0x00000020)
#define ST_REC_IC_ST_CF_wdog_cnt_ovs_mask                             (0x00000010)
#define ST_REC_IC_ST_CF_cpu_ack(data)                                 (0x00000040&((data)<<6))
#define ST_REC_IC_ST_CF_int_ack(data)                                 (0x00000020&((data)<<5))
#define ST_REC_IC_ST_CF_wdog_cnt_ovs(data)                            (0x00000010&((data)<<4))
#define ST_REC_IC_ST_CF_get_cpu_ack(data)                             ((0x00000040&(data))>>6)
#define ST_REC_IC_ST_CF_get_int_ack(data)                             ((0x00000020&(data))>>5)
#define ST_REC_IC_ST_CF_get_wdog_cnt_ovs(data)                        ((0x00000010&(data))>>4)


#define ST_REC_DATA0                                                  0x18011740
#define ST_REC_DATA0_reg_addr                                         "0xb8011740"
#define ST_REC_DATA0_reg                                              0xb8011740
#define ST_REC_DATA0_inst_addr                                        "0x01D0"
#define ST_REC_DATA0_inst                                             0x01D0
#define ST_REC_DATA0_data_shift                                       (0)
#define ST_REC_DATA0_data_mask                                        (0xFFFFFFFF)
#define ST_REC_DATA0_data(data)                                       (0xFFFFFFFF&(data))
#define ST_REC_DATA0_get_data(data)                                   (0xFFFFFFFF&(data))


#define ST_REC_DATA1                                                  0x18011744
#define ST_REC_DATA1_reg_addr                                         "0xb8011744"
#define ST_REC_DATA1_reg                                              0xb8011744
#define ST_REC_DATA1_inst_addr                                        "0x01D1"
#define ST_REC_DATA1_inst                                             0x01D1
#define ST_REC_DATA1_data_shift                                       (0)
#define ST_REC_DATA1_data_mask                                        (0xFFFFFFFF)
#define ST_REC_DATA1_data(data)                                       (0xFFFFFFFF&(data))
#define ST_REC_DATA1_get_data(data)                                   (0xFFFFFFFF&(data))


#define ST_REC_DATA2                                                  0x18011748
#define ST_REC_DATA2_reg_addr                                         "0xb8011748"
#define ST_REC_DATA2_reg                                              0xb8011748
#define ST_REC_DATA2_inst_addr                                        "0x01D2"
#define ST_REC_DATA2_inst                                             0x01D2
#define ST_REC_DATA2_data_shift                                       (0)
#define ST_REC_DATA2_data_mask                                        (0xFFFFFFFF)
#define ST_REC_DATA2_data(data)                                       (0xFFFFFFFF&(data))
#define ST_REC_DATA2_get_data(data)                                   (0xFFFFFFFF&(data))


#define ST_REC_DATA3                                                  0x1801174c
#define ST_REC_DATA3_reg_addr                                         "0xb801174c"
#define ST_REC_DATA3_reg                                              0xb801174c
#define ST_REC_DATA3_inst_addr                                        "0x01D3"
#define ST_REC_DATA3_inst                                             0x01D3
#define ST_REC_DATA3_data_shift                                       (0)
#define ST_REC_DATA3_data_mask                                        (0xFFFFFFFF)
#define ST_REC_DATA3_data(data)                                       (0xFFFFFFFF&(data))
#define ST_REC_DATA3_get_data(data)                                   (0xFFFFFFFF&(data))


#define ST_REC_DATA4                                                  0x18011750
#define ST_REC_DATA4_reg_addr                                         "0xb8011750"
#define ST_REC_DATA4_reg                                              0xb8011750
#define ST_REC_DATA4_inst_addr                                        "0x01D4"
#define ST_REC_DATA4_inst                                             0x01D4
#define ST_REC_DATA4_data_shift                                       (0)
#define ST_REC_DATA4_data_mask                                        (0xFFFFFFFF)
#define ST_REC_DATA4_data(data)                                       (0xFFFFFFFF&(data))
#define ST_REC_DATA4_get_data(data)                                   (0xFFFFFFFF&(data))


#define ST_REC_DATA5                                                  0x18011754
#define ST_REC_DATA5_reg_addr                                         "0xb8011754"
#define ST_REC_DATA5_reg                                              0xb8011754
#define ST_REC_DATA5_inst_addr                                        "0x01D5"
#define ST_REC_DATA5_inst                                             0x01D5
#define ST_REC_DATA5_data_shift                                       (0)
#define ST_REC_DATA5_data_mask                                        (0xFFFFFFFF)
#define ST_REC_DATA5_data(data)                                       (0xFFFFFFFF&(data))
#define ST_REC_DATA5_get_data(data)                                   (0xFFFFFFFF&(data))


#define ST_REC_DATA6                                                  0x18011758
#define ST_REC_DATA6_reg_addr                                         "0xb8011758"
#define ST_REC_DATA6_reg                                              0xb8011758
#define ST_REC_DATA6_inst_addr                                        "0x01D6"
#define ST_REC_DATA6_inst                                             0x01D6
#define ST_REC_DATA6_data_shift                                       (0)
#define ST_REC_DATA6_data_mask                                        (0xFFFFFFFF)
#define ST_REC_DATA6_data(data)                                       (0xFFFFFFFF&(data))
#define ST_REC_DATA6_get_data(data)                                   (0xFFFFFFFF&(data))


#define ST_REC_DATA7                                                  0x1801175c
#define ST_REC_DATA7_reg_addr                                         "0xb801175c"
#define ST_REC_DATA7_reg                                              0xb801175c
#define ST_REC_DATA7_inst_addr                                        "0x01D7"
#define ST_REC_DATA7_inst                                             0x01D7
#define ST_REC_DATA7_data_shift                                       (0)
#define ST_REC_DATA7_data_mask                                        (0xFFFFFFFF)
#define ST_REC_DATA7_data(data)                                       (0xFFFFFFFF&(data))
#define ST_REC_DATA7_get_data(data)                                   (0xFFFFFFFF&(data))


#define ST_I2C_CR                                                     0x18011b00
#define ST_I2C_CR_reg_addr                                            "0xb8011b00"
#define ST_I2C_CR_reg                                                 0xb8011b00
#define ST_I2C_CR_inst_addr                                           "0x02C0"
#define ST_I2C_CR_inst                                                0x02C0
#define ST_I2C_CR_cmderr_ie_shift                                     (7)
#define ST_I2C_CR_timeout_en_shift                                    (6)
#define ST_I2C_CR_debounce_mode_shift                                 (4)
#define ST_I2C_CR_timeout_ie_shift                                    (3)
#define ST_I2C_CR_retime_m_shift                                      (0)
#define ST_I2C_CR_cmderr_ie_mask                                      (0x00000080)
#define ST_I2C_CR_timeout_en_mask                                     (0x00000040)
#define ST_I2C_CR_debounce_mode_mask                                  (0x00000030)
#define ST_I2C_CR_timeout_ie_mask                                     (0x00000008)
#define ST_I2C_CR_retime_m_mask                                       (0x00000007)
#define ST_I2C_CR_cmderr_ie(data)                                     (0x00000080&((data)<<7))
#define ST_I2C_CR_timeout_en(data)                                    (0x00000040&((data)<<6))
#define ST_I2C_CR_debounce_mode(data)                                 (0x00000030&((data)<<4))
#define ST_I2C_CR_timeout_ie(data)                                    (0x00000008&((data)<<3))
#define ST_I2C_CR_retime_m(data)                                      (0x00000007&(data))
#define ST_I2C_CR_get_cmderr_ie(data)                                 ((0x00000080&(data))>>7)
#define ST_I2C_CR_get_timeout_en(data)                                ((0x00000040&(data))>>6)
#define ST_I2C_CR_get_debounce_mode(data)                             ((0x00000030&(data))>>4)
#define ST_I2C_CR_get_timeout_ie(data)                                ((0x00000008&(data))>>3)
#define ST_I2C_CR_get_retime_m(data)                                  (0x00000007&(data))


#define ST_I2C_SR                                                     0x18011b04
#define ST_I2C_SR_reg_addr                                            "0xb8011b04"
#define ST_I2C_SR_reg                                                 0xb8011b04
#define ST_I2C_SR_inst_addr                                           "0x02C1"
#define ST_I2C_SR_inst                                                0x02C1
#define ST_I2C_SR_cmderr_shift                                        (7)
#define ST_I2C_SR_finish_shift                                        (4)
#define ST_I2C_SR_timeout_shift                                       (3)
#define ST_I2C_SR_cmderr_mask                                         (0x00000080)
#define ST_I2C_SR_finish_mask                                         (0x00000010)
#define ST_I2C_SR_timeout_mask                                        (0x00000008)
#define ST_I2C_SR_cmderr(data)                                        (0x00000080&((data)<<7))
#define ST_I2C_SR_finish(data)                                        (0x00000010&((data)<<4))
#define ST_I2C_SR_timeout(data)                                       (0x00000008&((data)<<3))
#define ST_I2C_SR_get_cmderr(data)                                    ((0x00000080&(data))>>7)
#define ST_I2C_SR_get_finish(data)                                    ((0x00000010&(data))>>4)
#define ST_I2C_SR_get_timeout(data)                                   ((0x00000008&(data))>>3)


#define ST_I2C_TR                                                     0x18011b08
#define ST_I2C_TR_reg_addr                                            "0xb8011b08"
#define ST_I2C_TR_reg                                                 0xb8011b08
#define ST_I2C_TR_inst_addr                                           "0x02C2"
#define ST_I2C_TR_inst                                                0x02C2
#define ST_I2C_TR_timeout_val_shift                                   (0)
#define ST_I2C_TR_timeout_val_mask                                    (0x000000FF)
#define ST_I2C_TR_timeout_val(data)                                   (0x000000FF&(data))
#define ST_I2C_TR_get_timeout_val(data)                               (0x000000FF&(data))


#define ST_EDID_CR                                                    0x18011b0c
#define ST_EDID_CR_reg_addr                                           "0xb8011b0c"
#define ST_EDID_CR_reg                                                0xb8011b0c
#define ST_EDID_CR_inst_addr                                          "0x02C3"
#define ST_EDID_CR_inst                                               0x02C3
#define ST_EDID_CR_edid_address_shift                                 (5)
#define ST_EDID_CR_finish_int_en_shift                                (4)
#define ST_EDID_CR_ddc1_force_shift                                   (3)
#define ST_EDID_CR_ddc2b_force_shift                                  (2)
#define ST_EDID_CR_edid_srwen_shift                                   (1)
#define ST_EDID_CR_edid_en_shift                                      (0)
#define ST_EDID_CR_edid_address_mask                                  (0x000000E0)
#define ST_EDID_CR_finish_int_en_mask                                 (0x00000010)
#define ST_EDID_CR_ddc1_force_mask                                    (0x00000008)
#define ST_EDID_CR_ddc2b_force_mask                                   (0x00000004)
#define ST_EDID_CR_edid_srwen_mask                                    (0x00000002)
#define ST_EDID_CR_edid_en_mask                                       (0x00000001)
#define ST_EDID_CR_edid_address(data)                                 (0x000000E0&((data)<<5))
#define ST_EDID_CR_finish_int_en(data)                                (0x00000010&((data)<<4))
#define ST_EDID_CR_ddc1_force(data)                                   (0x00000008&((data)<<3))
#define ST_EDID_CR_ddc2b_force(data)                                  (0x00000004&((data)<<2))
#define ST_EDID_CR_edid_srwen(data)                                   (0x00000002&((data)<<1))
#define ST_EDID_CR_edid_en(data)                                      (0x00000001&(data))
#define ST_EDID_CR_get_edid_address(data)                             ((0x000000E0&(data))>>5)
#define ST_EDID_CR_get_finish_int_en(data)                            ((0x00000010&(data))>>4)
#define ST_EDID_CR_get_ddc1_force(data)                               ((0x00000008&(data))>>3)
#define ST_EDID_CR_get_ddc2b_force(data)                              ((0x00000004&(data))>>2)
#define ST_EDID_CR_get_edid_srwen(data)                               ((0x00000002&(data))>>1)
#define ST_EDID_CR_get_edid_en(data)                                  (0x00000001&(data))


#define ST_DDC_VCR                                                    0x18011b10
#define ST_DDC_VCR_reg_addr                                           "0xb8011b10"
#define ST_DDC_VCR_reg                                                0xb8011b10
#define ST_DDC_VCR_inst_addr                                          "0x02C4"
#define ST_DDC_VCR_inst                                               0x02C4
#define ST_DDC_VCR_ddc1_vcount_shift                                  (0)
#define ST_DDC_VCR_ddc1_vcount_mask                                   (0x000000FF)
#define ST_DDC_VCR_ddc1_vcount(data)                                  (0x000000FF&(data))
#define ST_DDC_VCR_get_ddc1_vcount(data)                              (0x000000FF&(data))


#define ST_EDID_IMSWSAR                                               0x18011b14
#define ST_EDID_IMSWSAR_reg_addr                                      "0xb8011b14"
#define ST_EDID_IMSWSAR_reg                                           0xb8011b14
#define ST_EDID_IMSWSAR_inst_addr                                     "0x02C5"
#define ST_EDID_IMSWSAR_inst                                          0x02C5
#define ST_EDID_IMSWSAR_edid_sadr_shift                               (0)
#define ST_EDID_IMSWSAR_edid_sadr_mask                                (0x000000FF)
#define ST_EDID_IMSWSAR_edid_sadr(data)                               (0x000000FF&(data))
#define ST_EDID_IMSWSAR_get_edid_sadr(data)                           (0x000000FF&(data))


#define ST_EDID_IMSWEAR                                               0x18011b18
#define ST_EDID_IMSWEAR_reg_addr                                      "0xb8011b18"
#define ST_EDID_IMSWEAR_reg                                           0xb8011b18
#define ST_EDID_IMSWEAR_inst_addr                                     "0x02C6"
#define ST_EDID_IMSWEAR_inst                                          0x02C6
#define ST_EDID_IMSWEAR_edid_eadr_shift                               (0)
#define ST_EDID_IMSWEAR_edid_eadr_mask                                (0x000000FF)
#define ST_EDID_IMSWEAR_edid_eadr(data)                               (0x000000FF&(data))
#define ST_EDID_IMSWEAR_get_edid_eadr(data)                           (0x000000FF&(data))


#define ST_EDID_IR                                                    0x18011b1c
#define ST_EDID_IR_reg_addr                                           "0xb8011b1c"
#define ST_EDID_IR_reg                                                0xb8011b1c
#define ST_EDID_IR_inst_addr                                          "0x02C7"
#define ST_EDID_IR_inst                                               0x02C7
#define ST_EDID_IR_edidmode_shift                                     (6)
#define ST_EDID_IR_edidsubaddress_shift                               (5)
#define ST_EDID_IR_edidstop_shift                                     (4)
#define ST_EDID_IR_edidsubaddress_ie_shift                            (1)
#define ST_EDID_IR_edidstop_ie_shift                                  (0)
#define ST_EDID_IR_edidmode_mask                                      (0x00000040)
#define ST_EDID_IR_edidsubaddress_mask                                (0x00000020)
#define ST_EDID_IR_edidstop_mask                                      (0x00000010)
#define ST_EDID_IR_edidsubaddress_ie_mask                             (0x00000002)
#define ST_EDID_IR_edidstop_ie_mask                                   (0x00000001)
#define ST_EDID_IR_edidmode(data)                                     (0x00000040&((data)<<6))
#define ST_EDID_IR_edidsubaddress(data)                               (0x00000020&((data)<<5))
#define ST_EDID_IR_edidstop(data)                                     (0x00000010&((data)<<4))
#define ST_EDID_IR_edidsubaddress_ie(data)                            (0x00000002&((data)<<1))
#define ST_EDID_IR_edidstop_ie(data)                                  (0x00000001&(data))
#define ST_EDID_IR_get_edidmode(data)                                 ((0x00000040&(data))>>6)
#define ST_EDID_IR_get_edidsubaddress(data)                           ((0x00000020&(data))>>5)
#define ST_EDID_IR_get_edidstop(data)                                 ((0x00000010&(data))>>4)
#define ST_EDID_IR_get_edidsubaddress_ie(data)                        ((0x00000002&(data))>>1)
#define ST_EDID_IR_get_edidstop_ie(data)                              (0x00000001&(data))


#define ST_DDC_SIR                                                    0x18011b20
#define ST_DDC_SIR_reg_addr                                           "0xb8011b20"
#define ST_DDC_SIR_reg                                                0xb8011b20
#define ST_DDC_SIR_inst_addr                                          "0x02C8"
#define ST_DDC_SIR_inst                                               0x02C8
#define ST_DDC_SIR_edidap_shift                                       (0)
#define ST_DDC_SIR_edidap_mask                                        (0x000000FF)
#define ST_DDC_SIR_edidap(data)                                       (0x000000FF&(data))
#define ST_DDC_SIR_get_edidap(data)                                   (0x000000FF&(data))


#define ST_DDC_SAP                                                    0x18011b24
#define ST_DDC_SAP_reg_addr                                           "0xb8011b24"
#define ST_DDC_SAP_reg                                                0xb8011b24
#define ST_DDC_SAP_inst_addr                                          "0x02C9"
#define ST_DDC_SAP_inst                                               0x02C9
#define ST_DDC_SAP_ediddp_shift                                       (0)
#define ST_DDC_SAP_ediddp_mask                                        (0x000000FF)
#define ST_DDC_SAP_ediddp(data)                                       (0x000000FF&(data))
#define ST_DDC_SAP_get_ediddp(data)                                   (0x000000FF&(data))


#define ST_DDC_BISTCR                                                 0x18011b28
#define ST_DDC_BISTCR_reg_addr                                        "0xb8011b28"
#define ST_DDC_BISTCR_reg                                             0xb8011b28
#define ST_DDC_BISTCR_inst_addr                                       "0x02CA"
#define ST_DDC_BISTCR_inst                                            0x02CA
#define ST_DDC_BISTCR_bist_fail_shift                                 (5)
#define ST_DDC_BISTCR_bist_done_shift                                 (4)
#define ST_DDC_BISTCR_bist_rstn_shift                                 (1)
#define ST_DDC_BISTCR_bist_mode_shift                                 (0)
#define ST_DDC_BISTCR_bist_fail_mask                                  (0x00000020)
#define ST_DDC_BISTCR_bist_done_mask                                  (0x00000010)
#define ST_DDC_BISTCR_bist_rstn_mask                                  (0x00000002)
#define ST_DDC_BISTCR_bist_mode_mask                                  (0x00000001)
#define ST_DDC_BISTCR_bist_fail(data)                                 (0x00000020&((data)<<5))
#define ST_DDC_BISTCR_bist_done(data)                                 (0x00000010&((data)<<4))
#define ST_DDC_BISTCR_bist_rstn(data)                                 (0x00000002&((data)<<1))
#define ST_DDC_BISTCR_bist_mode(data)                                 (0x00000001&(data))
#define ST_DDC_BISTCR_get_bist_fail(data)                             ((0x00000020&(data))>>5)
#define ST_DDC_BISTCR_get_bist_done(data)                             ((0x00000010&(data))>>4)
#define ST_DDC_BISTCR_get_bist_rstn(data)                             ((0x00000002&(data))>>1)
#define ST_DDC_BISTCR_get_bist_mode(data)                             (0x00000001&(data))


#define ST_DDC_SCR                                                    0x18011b2c
#define ST_DDC_SCR_reg_addr                                           "0xb8011b2c"
#define ST_DDC_SCR_reg                                                0xb8011b2c
#define ST_DDC_SCR_inst_addr                                          "0x02CB"
#define ST_DDC_SCR_inst                                               0x02CB
#define ST_DDC_SCR_segpt_latie_shift                                  (7)
#define ST_DDC_SCR_sgid_en_shift                                      (0)
#define ST_DDC_SCR_segpt_latie_mask                                   (0x00000080)
#define ST_DDC_SCR_sgid_en_mask                                       (0x00000001)
#define ST_DDC_SCR_segpt_latie(data)                                  (0x00000080&((data)<<7))
#define ST_DDC_SCR_sgid_en(data)                                      (0x00000001&(data))
#define ST_DDC_SCR_get_segpt_latie(data)                              ((0x00000080&(data))>>7)
#define ST_DDC_SCR_get_sgid_en(data)                                  (0x00000001&(data))


#define ST_DDC_SSAR                                                   0x18011b30
#define ST_DDC_SSAR_reg_addr                                          "0xb8011b30"
#define ST_DDC_SSAR_reg                                               0xb8011b30
#define ST_DDC_SSAR_inst_addr                                         "0x02CC"
#define ST_DDC_SSAR_inst                                              0x02CC
#define ST_DDC_SSAR_sgid_address_shift                                (1)
#define ST_DDC_SSAR_sgid_dtrden_shift                                 (0)
#define ST_DDC_SSAR_sgid_address_mask                                 (0x000000FE)
#define ST_DDC_SSAR_sgid_dtrden_mask                                  (0x00000001)
#define ST_DDC_SSAR_sgid_address(data)                                (0x000000FE&((data)<<1))
#define ST_DDC_SSAR_sgid_dtrden(data)                                 (0x00000001&(data))
#define ST_DDC_SSAR_get_sgid_address(data)                            ((0x000000FE&(data))>>1)
#define ST_DDC_SSAR_get_sgid_dtrden(data)                             (0x00000001&(data))


#define ST_DDC_SPR                                                    0x18011b34
#define ST_DDC_SPR_reg_addr                                           "0xb8011b34"
#define ST_DDC_SPR_reg                                                0xb8011b34
#define ST_DDC_SPR_inst_addr                                          "0x02CD"
#define ST_DDC_SPR_inst                                               0x02CD
#define ST_DDC_SPR_segpt_latched_shift                                (7)
#define ST_DDC_SPR_seg_pt_shift                                       (0)
#define ST_DDC_SPR_segpt_latched_mask                                 (0x00000080)
#define ST_DDC_SPR_seg_pt_mask                                        (0x0000007F)
#define ST_DDC_SPR_segpt_latched(data)                                (0x00000080&((data)<<7))
#define ST_DDC_SPR_seg_pt(data)                                       (0x0000007F&(data))
#define ST_DDC_SPR_get_segpt_latched(data)                            ((0x00000080&(data))>>7)
#define ST_DDC_SPR_get_seg_pt(data)                                   (0x0000007F&(data))


#define ST_DDC_SFCR                                                   0x18011b38
#define ST_DDC_SFCR_reg_addr                                          "0xb8011b38"
#define ST_DDC_SFCR_reg                                               0xb8011b38
#define ST_DDC_SFCR_inst_addr                                         "0x02CE"
#define ST_DDC_SFCR_inst                                              0x02CE
#define ST_DDC_SFCR_special_mode_shift                                (3)
#define ST_DDC_SFCR_doffpt_reset_shift                                (2)
#define ST_DDC_SFCR_diffpt_reset_shift                                (1)
#define ST_DDC_SFCR_ciid_en_shift                                     (0)
#define ST_DDC_SFCR_special_mode_mask                                 (0x00000008)
#define ST_DDC_SFCR_doffpt_reset_mask                                 (0x00000004)
#define ST_DDC_SFCR_diffpt_reset_mask                                 (0x00000002)
#define ST_DDC_SFCR_ciid_en_mask                                      (0x00000001)
#define ST_DDC_SFCR_special_mode(data)                                (0x00000008&((data)<<3))
#define ST_DDC_SFCR_doffpt_reset(data)                                (0x00000004&((data)<<2))
#define ST_DDC_SFCR_diffpt_reset(data)                                (0x00000002&((data)<<1))
#define ST_DDC_SFCR_ciid_en(data)                                     (0x00000001&(data))
#define ST_DDC_SFCR_get_special_mode(data)                            ((0x00000008&(data))>>3)
#define ST_DDC_SFCR_get_doffpt_reset(data)                            ((0x00000004&(data))>>2)
#define ST_DDC_SFCR_get_diffpt_reset(data)                            ((0x00000002&(data))>>1)
#define ST_DDC_SFCR_get_ciid_en(data)                                 (0x00000001&(data))


#define ST_DDC_SFSAR                                                  0x18011b3c
#define ST_DDC_SFSAR_reg_addr                                         "0xb8011b3c"
#define ST_DDC_SFSAR_reg                                              0xb8011b3c
#define ST_DDC_SFSAR_inst_addr                                        "0x02CF"
#define ST_DDC_SFSAR_inst                                             0x02CF
#define ST_DDC_SFSAR_ciid_address_shift                               (1)
#define ST_DDC_SFSAR_cirws_current_shift                              (0)
#define ST_DDC_SFSAR_ciid_address_mask                                (0x000000FE)
#define ST_DDC_SFSAR_cirws_current_mask                               (0x00000001)
#define ST_DDC_SFSAR_ciid_address(data)                               (0x000000FE&((data)<<1))
#define ST_DDC_SFSAR_cirws_current(data)                              (0x00000001&(data))
#define ST_DDC_SFSAR_get_ciid_address(data)                           ((0x000000FE&(data))>>1)
#define ST_DDC_SFSAR_get_cirws_current(data)                          (0x00000001&(data))


#define ST_DDC_SFDR                                                   0x18011b40
#define ST_DDC_SFDR_reg_addr                                          "0xb8011b40"
#define ST_DDC_SFDR_reg                                               0xb8011b40
#define ST_DDC_SFDR_inst_addr                                         "0x02D0"
#define ST_DDC_SFDR_inst                                              0x02D0
#define ST_DDC_SFDR_ciiddp_shift                                      (0)
#define ST_DDC_SFDR_ciiddp_mask                                       (0x000000FF)
#define ST_DDC_SFDR_ciiddp(data)                                      (0x000000FF&(data))
#define ST_DDC_SFDR_get_ciiddp(data)                                  (0x000000FF&(data))


#define ST_DDC_SFBSR                                                  0x18011b44
#define ST_DDC_SFBSR_reg_addr                                         "0xb8011b44"
#define ST_DDC_SFBSR_reg                                              0xb8011b44
#define ST_DDC_SFBSR_inst_addr                                        "0x02D1"
#define ST_DDC_SFBSR_inst                                             0x02D1
#define ST_DDC_SFBSR_cirws_2nd_shift                                  (5)
#define ST_DDC_SFBSR_cirws_1st_shift                                  (4)
#define ST_DDC_SFBSR_cippt_2nd_shift                                  (3)
#define ST_DDC_SFBSR_cispt_2nd_shift                                  (2)
#define ST_DDC_SFBSR_cippt_1st_shift                                  (1)
#define ST_DDC_SFBSR_cispt_1st_shift                                  (0)
#define ST_DDC_SFBSR_cirws_2nd_mask                                   (0x00000020)
#define ST_DDC_SFBSR_cirws_1st_mask                                   (0x00000010)
#define ST_DDC_SFBSR_cippt_2nd_mask                                   (0x00000008)
#define ST_DDC_SFBSR_cispt_2nd_mask                                   (0x00000004)
#define ST_DDC_SFBSR_cippt_1st_mask                                   (0x00000002)
#define ST_DDC_SFBSR_cispt_1st_mask                                   (0x00000001)
#define ST_DDC_SFBSR_cirws_2nd(data)                                  (0x00000020&((data)<<5))
#define ST_DDC_SFBSR_cirws_1st(data)                                  (0x00000010&((data)<<4))
#define ST_DDC_SFBSR_cippt_2nd(data)                                  (0x00000008&((data)<<3))
#define ST_DDC_SFBSR_cispt_2nd(data)                                  (0x00000004&((data)<<2))
#define ST_DDC_SFBSR_cippt_1st(data)                                  (0x00000002&((data)<<1))
#define ST_DDC_SFBSR_cispt_1st(data)                                  (0x00000001&(data))
#define ST_DDC_SFBSR_get_cirws_2nd(data)                              ((0x00000020&(data))>>5)
#define ST_DDC_SFBSR_get_cirws_1st(data)                              ((0x00000010&(data))>>4)
#define ST_DDC_SFBSR_get_cippt_2nd(data)                              ((0x00000008&(data))>>3)
#define ST_DDC_SFBSR_get_cispt_2nd(data)                              ((0x00000004&(data))>>2)
#define ST_DDC_SFBSR_get_cippt_1st(data)                              ((0x00000002&(data))>>1)
#define ST_DDC_SFBSR_get_cispt_1st(data)                              (0x00000001&(data))


#define ST_DDC_SFIBLR                                                 0x18011b48
#define ST_DDC_SFIBLR_reg_addr                                        "0xb8011b48"
#define ST_DDC_SFIBLR_reg                                             0xb8011b48
#define ST_DDC_SFIBLR_inst_addr                                       "0x02D2"
#define ST_DDC_SFIBLR_inst                                            0x02D2
#define ST_DDC_SFIBLR_ffdi_dlen_shift                                 (0)
#define ST_DDC_SFIBLR_ffdi_dlen_mask                                  (0x0000001F)
#define ST_DDC_SFIBLR_ffdi_dlen(data)                                 (0x0000001F&(data))
#define ST_DDC_SFIBLR_get_ffdi_dlen(data)                             (0x0000001F&(data))


#define ST_DDC_SFIBRWPR                                               0x18011b4c
#define ST_DDC_SFIBRWPR_reg_addr                                      "0xb8011b4c"
#define ST_DDC_SFIBRWPR_reg                                           0xb8011b4c
#define ST_DDC_SFIBRWPR_inst_addr                                     "0x02D3"
#define ST_DDC_SFIBRWPR_inst                                          0x02D3
#define ST_DDC_SFIBRWPR_diff_wpt_shift                                (4)
#define ST_DDC_SFIBRWPR_diff_rpt_shift                                (0)
#define ST_DDC_SFIBRWPR_diff_wpt_mask                                 (0x000000F0)
#define ST_DDC_SFIBRWPR_diff_rpt_mask                                 (0x0000000F)
#define ST_DDC_SFIBRWPR_diff_wpt(data)                                (0x000000F0&((data)<<4))
#define ST_DDC_SFIBRWPR_diff_rpt(data)                                (0x0000000F&(data))
#define ST_DDC_SFIBRWPR_get_diff_wpt(data)                            ((0x000000F0&(data))>>4)
#define ST_DDC_SFIBRWPR_get_diff_rpt(data)                            (0x0000000F&(data))


#define ST_DDC_SFIBSWPR                                               0x18011b50
#define ST_DDC_SFIBSWPR_reg_addr                                      "0xb8011b50"
#define ST_DDC_SFIBSWPR_reg                                           0xb8011b50
#define ST_DDC_SFIBSWPR_inst_addr                                     "0x02D4"
#define ST_DDC_SFIBSWPR_inst                                          0x02D4
#define ST_DDC_SFIBSWPR_diffstop_pt_shift                             (0)
#define ST_DDC_SFIBSWPR_diffstop_pt_mask                              (0x0000000F)
#define ST_DDC_SFIBSWPR_diffstop_pt(data)                             (0x0000000F&(data))
#define ST_DDC_SFIBSWPR_get_diffstop_pt(data)                         (0x0000000F&(data))


#define ST_DDC_SFOBSR                                                 0x18011b54
#define ST_DDC_SFOBSR_reg_addr                                        "0xb8011b54"
#define ST_DDC_SFOBSR_reg                                             0xb8011b54
#define ST_DDC_SFOBSR_inst_addr                                       "0x02D5"
#define ST_DDC_SFOBSR_inst                                            0x02D5
#define ST_DDC_SFOBSR_ffdo_dlen_shift                                 (0)
#define ST_DDC_SFOBSR_ffdo_dlen_mask                                  (0x0000001F)
#define ST_DDC_SFOBSR_ffdo_dlen(data)                                 (0x0000001F&(data))
#define ST_DDC_SFOBSR_get_ffdo_dlen(data)                             (0x0000001F&(data))


#define ST_DDC_SFOBRWPR                                               0x18011b58
#define ST_DDC_SFOBRWPR_reg_addr                                      "0xb8011b58"
#define ST_DDC_SFOBRWPR_reg                                           0xb8011b58
#define ST_DDC_SFOBRWPR_inst_addr                                     "0x02D6"
#define ST_DDC_SFOBRWPR_inst                                          0x02D6
#define ST_DDC_SFOBRWPR_doff_wpt_shift                                (4)
#define ST_DDC_SFOBRWPR_doff_rpt_shift                                (0)
#define ST_DDC_SFOBRWPR_doff_wpt_mask                                 (0x000000F0)
#define ST_DDC_SFOBRWPR_doff_rpt_mask                                 (0x0000000F)
#define ST_DDC_SFOBRWPR_doff_wpt(data)                                (0x000000F0&((data)<<4))
#define ST_DDC_SFOBRWPR_doff_rpt(data)                                (0x0000000F&(data))
#define ST_DDC_SFOBRWPR_get_doff_wpt(data)                            ((0x000000F0&(data))>>4)
#define ST_DDC_SFOBRWPR_get_doff_rpt(data)                            (0x0000000F&(data))


#define ST_DDC_SFSR                                                   0x18011b5c
#define ST_DDC_SFSR_reg_addr                                          "0xb8011b5c"
#define ST_DDC_SFSR_reg                                               0xb8011b5c
#define ST_DDC_SFSR_inst_addr                                         "0x02D7"
#define ST_DDC_SFSR_inst                                              0x02D7
#define ST_DDC_SFSR_ffdouf_st_shift                                   (7)
#define ST_DDC_SFSR_ffdiof_st_shift                                   (6)
#define ST_DDC_SFSR_ffdonf_st_shift                                   (5)
#define ST_DDC_SFSR_ffdoet_st_shift                                   (4)
#define ST_DDC_SFSR_ffdifu_st_shift                                   (3)
#define ST_DDC_SFSR_ffdine_st_shift                                   (2)
#define ST_DDC_SFSR_ffdouf_st_mask                                    (0x00000080)
#define ST_DDC_SFSR_ffdiof_st_mask                                    (0x00000040)
#define ST_DDC_SFSR_ffdonf_st_mask                                    (0x00000020)
#define ST_DDC_SFSR_ffdoet_st_mask                                    (0x00000010)
#define ST_DDC_SFSR_ffdifu_st_mask                                    (0x00000008)
#define ST_DDC_SFSR_ffdine_st_mask                                    (0x00000004)
#define ST_DDC_SFSR_ffdouf_st(data)                                   (0x00000080&((data)<<7))
#define ST_DDC_SFSR_ffdiof_st(data)                                   (0x00000040&((data)<<6))
#define ST_DDC_SFSR_ffdonf_st(data)                                   (0x00000020&((data)<<5))
#define ST_DDC_SFSR_ffdoet_st(data)                                   (0x00000010&((data)<<4))
#define ST_DDC_SFSR_ffdifu_st(data)                                   (0x00000008&((data)<<3))
#define ST_DDC_SFSR_ffdine_st(data)                                   (0x00000004&((data)<<2))
#define ST_DDC_SFSR_get_ffdouf_st(data)                               ((0x00000080&(data))>>7)
#define ST_DDC_SFSR_get_ffdiof_st(data)                               ((0x00000040&(data))>>6)
#define ST_DDC_SFSR_get_ffdonf_st(data)                               ((0x00000020&(data))>>5)
#define ST_DDC_SFSR_get_ffdoet_st(data)                               ((0x00000010&(data))>>4)
#define ST_DDC_SFSR_get_ffdifu_st(data)                               ((0x00000008&(data))>>3)
#define ST_DDC_SFSR_get_ffdine_st(data)                               ((0x00000004&(data))>>2)


#define ST_DDC_SFIR                                                   0x18011b60
#define ST_DDC_SFIR_reg_addr                                          "0xb8011b60"
#define ST_DDC_SFIR_reg                                               0xb8011b60
#define ST_DDC_SFIR_inst_addr                                         "0x02D8"
#define ST_DDC_SFIR_inst                                              0x02D8
#define ST_DDC_SFIR_ffdouf_ie_shift                                   (7)
#define ST_DDC_SFIR_ffdiof_ie_shift                                   (6)
#define ST_DDC_SFIR_ffdonf_ie_shift                                   (5)
#define ST_DDC_SFIR_ffdoet_ie_shift                                   (4)
#define ST_DDC_SFIR_ffdifu_ie_shift                                   (3)
#define ST_DDC_SFIR_ffdine_ie_shift                                   (2)
#define ST_DDC_SFIR_cippt_ie_shift                                    (1)
#define ST_DDC_SFIR_cispt_ie_shift                                    (0)
#define ST_DDC_SFIR_ffdouf_ie_mask                                    (0x00000080)
#define ST_DDC_SFIR_ffdiof_ie_mask                                    (0x00000040)
#define ST_DDC_SFIR_ffdonf_ie_mask                                    (0x00000020)
#define ST_DDC_SFIR_ffdoet_ie_mask                                    (0x00000010)
#define ST_DDC_SFIR_ffdifu_ie_mask                                    (0x00000008)
#define ST_DDC_SFIR_ffdine_ie_mask                                    (0x00000004)
#define ST_DDC_SFIR_cippt_ie_mask                                     (0x00000002)
#define ST_DDC_SFIR_cispt_ie_mask                                     (0x00000001)
#define ST_DDC_SFIR_ffdouf_ie(data)                                   (0x00000080&((data)<<7))
#define ST_DDC_SFIR_ffdiof_ie(data)                                   (0x00000040&((data)<<6))
#define ST_DDC_SFIR_ffdonf_ie(data)                                   (0x00000020&((data)<<5))
#define ST_DDC_SFIR_ffdoet_ie(data)                                   (0x00000010&((data)<<4))
#define ST_DDC_SFIR_ffdifu_ie(data)                                   (0x00000008&((data)<<3))
#define ST_DDC_SFIR_ffdine_ie(data)                                   (0x00000004&((data)<<2))
#define ST_DDC_SFIR_cippt_ie(data)                                    (0x00000002&((data)<<1))
#define ST_DDC_SFIR_cispt_ie(data)                                    (0x00000001&(data))
#define ST_DDC_SFIR_get_ffdouf_ie(data)                               ((0x00000080&(data))>>7)
#define ST_DDC_SFIR_get_ffdiof_ie(data)                               ((0x00000040&(data))>>6)
#define ST_DDC_SFIR_get_ffdonf_ie(data)                               ((0x00000020&(data))>>5)
#define ST_DDC_SFIR_get_ffdoet_ie(data)                               ((0x00000010&(data))>>4)
#define ST_DDC_SFIR_get_ffdifu_ie(data)                               ((0x00000008&(data))>>3)
#define ST_DDC_SFIR_get_ffdine_ie(data)                               ((0x00000004&(data))>>2)
#define ST_DDC_SFIR_get_cippt_ie(data)                                ((0x00000002&(data))>>1)
#define ST_DDC_SFIR_get_cispt_ie(data)                                (0x00000001&(data))


#define ST_DDC_FSMS                                                   0x18011b64
#define ST_DDC_FSMS_reg_addr                                          "0xb8011b64"
#define ST_DDC_FSMS_reg                                               0xb8011b64
#define ST_DDC_FSMS_inst_addr                                         "0x02D9"
#define ST_DDC_FSMS_inst                                              0x02D9
#define ST_DDC_FSMS_cmdfsm_st_shift                                   (0)
#define ST_DDC_FSMS_cmdfsm_st_mask                                    (0x000000FF)
#define ST_DDC_FSMS_cmdfsm_st(data)                                   (0x000000FF&(data))
#define ST_DDC_FSMS_get_cmdfsm_st(data)                               (0x000000FF&(data))


#define ST_I2C_CR_2                                                   0x18011c00
#define ST_I2C_CR_2_reg_addr                                          "0xb8011c00"
#define ST_I2C_CR_2_reg                                               0xb8011c00
#define ST_I2C_CR_2_inst_addr                                         "0x0300"
#define ST_I2C_CR_2_inst                                              0x0300
#define ST_I2C_CR_2_cmderr_ie_shift                                   (7)
#define ST_I2C_CR_2_timeout_en_shift                                  (6)
#define ST_I2C_CR_2_debounce_mode_shift                               (4)
#define ST_I2C_CR_2_timeout_ie_shift                                  (3)
#define ST_I2C_CR_2_retime_m_shift                                    (0)
#define ST_I2C_CR_2_cmderr_ie_mask                                    (0x00000080)
#define ST_I2C_CR_2_timeout_en_mask                                   (0x00000040)
#define ST_I2C_CR_2_debounce_mode_mask                                (0x00000030)
#define ST_I2C_CR_2_timeout_ie_mask                                   (0x00000008)
#define ST_I2C_CR_2_retime_m_mask                                     (0x00000007)
#define ST_I2C_CR_2_cmderr_ie(data)                                   (0x00000080&((data)<<7))
#define ST_I2C_CR_2_timeout_en(data)                                  (0x00000040&((data)<<6))
#define ST_I2C_CR_2_debounce_mode(data)                               (0x00000030&((data)<<4))
#define ST_I2C_CR_2_timeout_ie(data)                                  (0x00000008&((data)<<3))
#define ST_I2C_CR_2_retime_m(data)                                    (0x00000007&(data))
#define ST_I2C_CR_2_get_cmderr_ie(data)                               ((0x00000080&(data))>>7)
#define ST_I2C_CR_2_get_timeout_en(data)                              ((0x00000040&(data))>>6)
#define ST_I2C_CR_2_get_debounce_mode(data)                           ((0x00000030&(data))>>4)
#define ST_I2C_CR_2_get_timeout_ie(data)                              ((0x00000008&(data))>>3)
#define ST_I2C_CR_2_get_retime_m(data)                                (0x00000007&(data))


#define ST_I2C_SR_2                                                   0x18011c04
#define ST_I2C_SR_2_reg_addr                                          "0xb8011c04"
#define ST_I2C_SR_2_reg                                               0xb8011c04
#define ST_I2C_SR_2_inst_addr                                         "0x0301"
#define ST_I2C_SR_2_inst                                              0x0301
#define ST_I2C_SR_2_cmderr_shift                                      (7)
#define ST_I2C_SR_2_finish_shift                                      (4)
#define ST_I2C_SR_2_timeout_shift                                     (3)
#define ST_I2C_SR_2_cmderr_mask                                       (0x00000080)
#define ST_I2C_SR_2_finish_mask                                       (0x00000010)
#define ST_I2C_SR_2_timeout_mask                                      (0x00000008)
#define ST_I2C_SR_2_cmderr(data)                                      (0x00000080&((data)<<7))
#define ST_I2C_SR_2_finish(data)                                      (0x00000010&((data)<<4))
#define ST_I2C_SR_2_timeout(data)                                     (0x00000008&((data)<<3))
#define ST_I2C_SR_2_get_cmderr(data)                                  ((0x00000080&(data))>>7)
#define ST_I2C_SR_2_get_finish(data)                                  ((0x00000010&(data))>>4)
#define ST_I2C_SR_2_get_timeout(data)                                 ((0x00000008&(data))>>3)


#define ST_I2C_TR_2                                                   0x18011c08
#define ST_I2C_TR_2_reg_addr                                          "0xb8011c08"
#define ST_I2C_TR_2_reg                                               0xb8011c08
#define ST_I2C_TR_2_inst_addr                                         "0x0302"
#define ST_I2C_TR_2_inst                                              0x0302
#define ST_I2C_TR_2_timeout_val_shift                                 (0)
#define ST_I2C_TR_2_timeout_val_mask                                  (0x000000FF)
#define ST_I2C_TR_2_timeout_val(data)                                 (0x000000FF&(data))
#define ST_I2C_TR_2_get_timeout_val(data)                             (0x000000FF&(data))


#define ST_EDID_CR_2                                                  0x18011c0c
#define ST_EDID_CR_2_reg_addr                                         "0xb8011c0c"
#define ST_EDID_CR_2_reg                                              0xb8011c0c
#define ST_EDID_CR_2_inst_addr                                        "0x0303"
#define ST_EDID_CR_2_inst                                             0x0303
#define ST_EDID_CR_2_edid_address_shift                               (5)
#define ST_EDID_CR_2_finish_int_en_shift                              (4)
#define ST_EDID_CR_2_ddc1_force_shift                                 (3)
#define ST_EDID_CR_2_ddc2b_force_shift                                (2)
#define ST_EDID_CR_2_edid_srwen_shift                                 (1)
#define ST_EDID_CR_2_edid_en_shift                                    (0)
#define ST_EDID_CR_2_edid_address_mask                                (0x000000E0)
#define ST_EDID_CR_2_finish_int_en_mask                               (0x00000010)
#define ST_EDID_CR_2_ddc1_force_mask                                  (0x00000008)
#define ST_EDID_CR_2_ddc2b_force_mask                                 (0x00000004)
#define ST_EDID_CR_2_edid_srwen_mask                                  (0x00000002)
#define ST_EDID_CR_2_edid_en_mask                                     (0x00000001)
#define ST_EDID_CR_2_edid_address(data)                               (0x000000E0&((data)<<5))
#define ST_EDID_CR_2_finish_int_en(data)                              (0x00000010&((data)<<4))
#define ST_EDID_CR_2_ddc1_force(data)                                 (0x00000008&((data)<<3))
#define ST_EDID_CR_2_ddc2b_force(data)                                (0x00000004&((data)<<2))
#define ST_EDID_CR_2_edid_srwen(data)                                 (0x00000002&((data)<<1))
#define ST_EDID_CR_2_edid_en(data)                                    (0x00000001&(data))
#define ST_EDID_CR_2_get_edid_address(data)                           ((0x000000E0&(data))>>5)
#define ST_EDID_CR_2_get_finish_int_en(data)                          ((0x00000010&(data))>>4)
#define ST_EDID_CR_2_get_ddc1_force(data)                             ((0x00000008&(data))>>3)
#define ST_EDID_CR_2_get_ddc2b_force(data)                            ((0x00000004&(data))>>2)
#define ST_EDID_CR_2_get_edid_srwen(data)                             ((0x00000002&(data))>>1)
#define ST_EDID_CR_2_get_edid_en(data)                                (0x00000001&(data))


#define ST_DDC_VCR_2                                                  0x18011c10
#define ST_DDC_VCR_2_reg_addr                                         "0xb8011c10"
#define ST_DDC_VCR_2_reg                                              0xb8011c10
#define ST_DDC_VCR_2_inst_addr                                        "0x0304"
#define ST_DDC_VCR_2_inst                                             0x0304
#define ST_DDC_VCR_2_ddc1_vcount_shift                                (0)
#define ST_DDC_VCR_2_ddc1_vcount_mask                                 (0x000000FF)
#define ST_DDC_VCR_2_ddc1_vcount(data)                                (0x000000FF&(data))
#define ST_DDC_VCR_2_get_ddc1_vcount(data)                            (0x000000FF&(data))


#define ST_EDID_IMSWSAR_2                                             0x18011c14
#define ST_EDID_IMSWSAR_2_reg_addr                                    "0xb8011c14"
#define ST_EDID_IMSWSAR_2_reg                                         0xb8011c14
#define ST_EDID_IMSWSAR_2_inst_addr                                   "0x0305"
#define ST_EDID_IMSWSAR_2_inst                                        0x0305
#define ST_EDID_IMSWSAR_2_edid_sadr_shift                             (0)
#define ST_EDID_IMSWSAR_2_edid_sadr_mask                              (0x000000FF)
#define ST_EDID_IMSWSAR_2_edid_sadr(data)                             (0x000000FF&(data))
#define ST_EDID_IMSWSAR_2_get_edid_sadr(data)                         (0x000000FF&(data))


#define ST_EDID_IMSWEAR_2                                             0x18011c18
#define ST_EDID_IMSWEAR_2_reg_addr                                    "0xb8011c18"
#define ST_EDID_IMSWEAR_2_reg                                         0xb8011c18
#define ST_EDID_IMSWEAR_2_inst_addr                                   "0x0306"
#define ST_EDID_IMSWEAR_2_inst                                        0x0306
#define ST_EDID_IMSWEAR_2_edid_eadr_shift                             (0)
#define ST_EDID_IMSWEAR_2_edid_eadr_mask                              (0x000000FF)
#define ST_EDID_IMSWEAR_2_edid_eadr(data)                             (0x000000FF&(data))
#define ST_EDID_IMSWEAR_2_get_edid_eadr(data)                         (0x000000FF&(data))


#define ST_EDID_IR_2                                                  0x18011c1c
#define ST_EDID_IR_2_reg_addr                                         "0xb8011c1c"
#define ST_EDID_IR_2_reg                                              0xb8011c1c
#define ST_EDID_IR_2_inst_addr                                        "0x0307"
#define ST_EDID_IR_2_inst                                             0x0307
#define ST_EDID_IR_2_edidmode_shift                                   (6)
#define ST_EDID_IR_2_edidsubaddress_shift                             (5)
#define ST_EDID_IR_2_edidstop_shift                                   (4)
#define ST_EDID_IR_2_edidsubaddress_ie_shift                          (1)
#define ST_EDID_IR_2_edidstop_ie_shift                                (0)
#define ST_EDID_IR_2_edidmode_mask                                    (0x00000040)
#define ST_EDID_IR_2_edidsubaddress_mask                              (0x00000020)
#define ST_EDID_IR_2_edidstop_mask                                    (0x00000010)
#define ST_EDID_IR_2_edidsubaddress_ie_mask                           (0x00000002)
#define ST_EDID_IR_2_edidstop_ie_mask                                 (0x00000001)
#define ST_EDID_IR_2_edidmode(data)                                   (0x00000040&((data)<<6))
#define ST_EDID_IR_2_edidsubaddress(data)                             (0x00000020&((data)<<5))
#define ST_EDID_IR_2_edidstop(data)                                   (0x00000010&((data)<<4))
#define ST_EDID_IR_2_edidsubaddress_ie(data)                          (0x00000002&((data)<<1))
#define ST_EDID_IR_2_edidstop_ie(data)                                (0x00000001&(data))
#define ST_EDID_IR_2_get_edidmode(data)                               ((0x00000040&(data))>>6)
#define ST_EDID_IR_2_get_edidsubaddress(data)                         ((0x00000020&(data))>>5)
#define ST_EDID_IR_2_get_edidstop(data)                               ((0x00000010&(data))>>4)
#define ST_EDID_IR_2_get_edidsubaddress_ie(data)                      ((0x00000002&(data))>>1)
#define ST_EDID_IR_2_get_edidstop_ie(data)                            (0x00000001&(data))


#define ST_DDC_SIR_2                                                  0x18011c20
#define ST_DDC_SIR_2_reg_addr                                         "0xb8011c20"
#define ST_DDC_SIR_2_reg                                              0xb8011c20
#define ST_DDC_SIR_2_inst_addr                                        "0x0308"
#define ST_DDC_SIR_2_inst                                             0x0308
#define ST_DDC_SIR_2_edidap_shift                                     (0)
#define ST_DDC_SIR_2_edidap_mask                                      (0x000000FF)
#define ST_DDC_SIR_2_edidap(data)                                     (0x000000FF&(data))
#define ST_DDC_SIR_2_get_edidap(data)                                 (0x000000FF&(data))


#define ST_DDC_SAP_2                                                  0x18011c24
#define ST_DDC_SAP_2_reg_addr                                         "0xb8011c24"
#define ST_DDC_SAP_2_reg                                              0xb8011c24
#define ST_DDC_SAP_2_inst_addr                                        "0x0309"
#define ST_DDC_SAP_2_inst                                             0x0309
#define ST_DDC_SAP_2_ediddp_shift                                     (0)
#define ST_DDC_SAP_2_ediddp_mask                                      (0x000000FF)
#define ST_DDC_SAP_2_ediddp(data)                                     (0x000000FF&(data))
#define ST_DDC_SAP_2_get_ediddp(data)                                 (0x000000FF&(data))


#define ST_DDC_BISTCR_2                                               0x18011c28
#define ST_DDC_BISTCR_2_reg_addr                                      "0xb8011c28"
#define ST_DDC_BISTCR_2_reg                                           0xb8011c28
#define ST_DDC_BISTCR_2_inst_addr                                     "0x030A"
#define ST_DDC_BISTCR_2_inst                                          0x030A
#define ST_DDC_BISTCR_2_bist_fail_shift                               (5)
#define ST_DDC_BISTCR_2_bist_done_shift                               (4)
#define ST_DDC_BISTCR_2_bist_rstn_shift                               (1)
#define ST_DDC_BISTCR_2_bist_mode_shift                               (0)
#define ST_DDC_BISTCR_2_bist_fail_mask                                (0x00000020)
#define ST_DDC_BISTCR_2_bist_done_mask                                (0x00000010)
#define ST_DDC_BISTCR_2_bist_rstn_mask                                (0x00000002)
#define ST_DDC_BISTCR_2_bist_mode_mask                                (0x00000001)
#define ST_DDC_BISTCR_2_bist_fail(data)                               (0x00000020&((data)<<5))
#define ST_DDC_BISTCR_2_bist_done(data)                               (0x00000010&((data)<<4))
#define ST_DDC_BISTCR_2_bist_rstn(data)                               (0x00000002&((data)<<1))
#define ST_DDC_BISTCR_2_bist_mode(data)                               (0x00000001&(data))
#define ST_DDC_BISTCR_2_get_bist_fail(data)                           ((0x00000020&(data))>>5)
#define ST_DDC_BISTCR_2_get_bist_done(data)                           ((0x00000010&(data))>>4)
#define ST_DDC_BISTCR_2_get_bist_rstn(data)                           ((0x00000002&(data))>>1)
#define ST_DDC_BISTCR_2_get_bist_mode(data)                           (0x00000001&(data))


#define ST_DDC_SCR_2                                                  0x18011c2c
#define ST_DDC_SCR_2_reg_addr                                         "0xb8011c2c"
#define ST_DDC_SCR_2_reg                                              0xb8011c2c
#define ST_DDC_SCR_2_inst_addr                                        "0x030B"
#define ST_DDC_SCR_2_inst                                             0x030B
#define ST_DDC_SCR_2_segpt_latie_shift                                (7)
#define ST_DDC_SCR_2_sgid_en_shift                                    (0)
#define ST_DDC_SCR_2_segpt_latie_mask                                 (0x00000080)
#define ST_DDC_SCR_2_sgid_en_mask                                     (0x00000001)
#define ST_DDC_SCR_2_segpt_latie(data)                                (0x00000080&((data)<<7))
#define ST_DDC_SCR_2_sgid_en(data)                                    (0x00000001&(data))
#define ST_DDC_SCR_2_get_segpt_latie(data)                            ((0x00000080&(data))>>7)
#define ST_DDC_SCR_2_get_sgid_en(data)                                (0x00000001&(data))


#define ST_DDC_SSAR_2                                                 0x18011c30
#define ST_DDC_SSAR_2_reg_addr                                        "0xb8011c30"
#define ST_DDC_SSAR_2_reg                                             0xb8011c30
#define ST_DDC_SSAR_2_inst_addr                                       "0x030C"
#define ST_DDC_SSAR_2_inst                                            0x030C
#define ST_DDC_SSAR_2_sgid_address_shift                              (1)
#define ST_DDC_SSAR_2_sgid_dtrden_shift                               (0)
#define ST_DDC_SSAR_2_sgid_address_mask                               (0x000000FE)
#define ST_DDC_SSAR_2_sgid_dtrden_mask                                (0x00000001)
#define ST_DDC_SSAR_2_sgid_address(data)                              (0x000000FE&((data)<<1))
#define ST_DDC_SSAR_2_sgid_dtrden(data)                               (0x00000001&(data))
#define ST_DDC_SSAR_2_get_sgid_address(data)                          ((0x000000FE&(data))>>1)
#define ST_DDC_SSAR_2_get_sgid_dtrden(data)                           (0x00000001&(data))


#define ST_DDC_SPR_2                                                  0x18011c34
#define ST_DDC_SPR_2_reg_addr                                         "0xb8011c34"
#define ST_DDC_SPR_2_reg                                              0xb8011c34
#define ST_DDC_SPR_2_inst_addr                                        "0x030D"
#define ST_DDC_SPR_2_inst                                             0x030D
#define ST_DDC_SPR_2_segpt_latched_shift                              (7)
#define ST_DDC_SPR_2_seg_pt_shift                                     (0)
#define ST_DDC_SPR_2_segpt_latched_mask                               (0x00000080)
#define ST_DDC_SPR_2_seg_pt_mask                                      (0x0000007F)
#define ST_DDC_SPR_2_segpt_latched(data)                              (0x00000080&((data)<<7))
#define ST_DDC_SPR_2_seg_pt(data)                                     (0x0000007F&(data))
#define ST_DDC_SPR_2_get_segpt_latched(data)                          ((0x00000080&(data))>>7)
#define ST_DDC_SPR_2_get_seg_pt(data)                                 (0x0000007F&(data))


#define ST_DDC_SFCR_2                                                 0x18011c38
#define ST_DDC_SFCR_2_reg_addr                                        "0xb8011c38"
#define ST_DDC_SFCR_2_reg                                             0xb8011c38
#define ST_DDC_SFCR_2_inst_addr                                       "0x030E"
#define ST_DDC_SFCR_2_inst                                            0x030E
#define ST_DDC_SFCR_2_special_mode_shift                              (3)
#define ST_DDC_SFCR_2_doffpt_reset_shift                              (2)
#define ST_DDC_SFCR_2_diffpt_reset_shift                              (1)
#define ST_DDC_SFCR_2_ciid_en_shift                                   (0)
#define ST_DDC_SFCR_2_special_mode_mask                               (0x00000008)
#define ST_DDC_SFCR_2_doffpt_reset_mask                               (0x00000004)
#define ST_DDC_SFCR_2_diffpt_reset_mask                               (0x00000002)
#define ST_DDC_SFCR_2_ciid_en_mask                                    (0x00000001)
#define ST_DDC_SFCR_2_special_mode(data)                              (0x00000008&((data)<<3))
#define ST_DDC_SFCR_2_doffpt_reset(data)                              (0x00000004&((data)<<2))
#define ST_DDC_SFCR_2_diffpt_reset(data)                              (0x00000002&((data)<<1))
#define ST_DDC_SFCR_2_ciid_en(data)                                   (0x00000001&(data))
#define ST_DDC_SFCR_2_get_special_mode(data)                          ((0x00000008&(data))>>3)
#define ST_DDC_SFCR_2_get_doffpt_reset(data)                          ((0x00000004&(data))>>2)
#define ST_DDC_SFCR_2_get_diffpt_reset(data)                          ((0x00000002&(data))>>1)
#define ST_DDC_SFCR_2_get_ciid_en(data)                               (0x00000001&(data))


#define ST_DDC_SFSAR_2                                                0x18011c3c
#define ST_DDC_SFSAR_2_reg_addr                                       "0xb8011c3c"
#define ST_DDC_SFSAR_2_reg                                            0xb8011c3c
#define ST_DDC_SFSAR_2_inst_addr                                      "0x030F"
#define ST_DDC_SFSAR_2_inst                                           0x030F
#define ST_DDC_SFSAR_2_ciid_address_shift                             (1)
#define ST_DDC_SFSAR_2_cirws_current_shift                            (0)
#define ST_DDC_SFSAR_2_ciid_address_mask                              (0x000000FE)
#define ST_DDC_SFSAR_2_cirws_current_mask                             (0x00000001)
#define ST_DDC_SFSAR_2_ciid_address(data)                             (0x000000FE&((data)<<1))
#define ST_DDC_SFSAR_2_cirws_current(data)                            (0x00000001&(data))
#define ST_DDC_SFSAR_2_get_ciid_address(data)                         ((0x000000FE&(data))>>1)
#define ST_DDC_SFSAR_2_get_cirws_current(data)                        (0x00000001&(data))


#define ST_DDC_SFDR_2                                                 0x18011c40
#define ST_DDC_SFDR_2_reg_addr                                        "0xb8011c40"
#define ST_DDC_SFDR_2_reg                                             0xb8011c40
#define ST_DDC_SFDR_2_inst_addr                                       "0x0310"
#define ST_DDC_SFDR_2_inst                                            0x0310
#define ST_DDC_SFDR_2_ciiddp_shift                                    (0)
#define ST_DDC_SFDR_2_ciiddp_mask                                     (0x000000FF)
#define ST_DDC_SFDR_2_ciiddp(data)                                    (0x000000FF&(data))
#define ST_DDC_SFDR_2_get_ciiddp(data)                                (0x000000FF&(data))


#define ST_DDC_SFBSR_2                                                0x18011c44
#define ST_DDC_SFBSR_2_reg_addr                                       "0xb8011c44"
#define ST_DDC_SFBSR_2_reg                                            0xb8011c44
#define ST_DDC_SFBSR_2_inst_addr                                      "0x0311"
#define ST_DDC_SFBSR_2_inst                                           0x0311
#define ST_DDC_SFBSR_2_cirws_2nd_shift                                (5)
#define ST_DDC_SFBSR_2_cirws_1st_shift                                (4)
#define ST_DDC_SFBSR_2_cippt_2nd_shift                                (3)
#define ST_DDC_SFBSR_2_cispt_2nd_shift                                (2)
#define ST_DDC_SFBSR_2_cippt_1st_shift                                (1)
#define ST_DDC_SFBSR_2_cispt_1st_shift                                (0)
#define ST_DDC_SFBSR_2_cirws_2nd_mask                                 (0x00000020)
#define ST_DDC_SFBSR_2_cirws_1st_mask                                 (0x00000010)
#define ST_DDC_SFBSR_2_cippt_2nd_mask                                 (0x00000008)
#define ST_DDC_SFBSR_2_cispt_2nd_mask                                 (0x00000004)
#define ST_DDC_SFBSR_2_cippt_1st_mask                                 (0x00000002)
#define ST_DDC_SFBSR_2_cispt_1st_mask                                 (0x00000001)
#define ST_DDC_SFBSR_2_cirws_2nd(data)                                (0x00000020&((data)<<5))
#define ST_DDC_SFBSR_2_cirws_1st(data)                                (0x00000010&((data)<<4))
#define ST_DDC_SFBSR_2_cippt_2nd(data)                                (0x00000008&((data)<<3))
#define ST_DDC_SFBSR_2_cispt_2nd(data)                                (0x00000004&((data)<<2))
#define ST_DDC_SFBSR_2_cippt_1st(data)                                (0x00000002&((data)<<1))
#define ST_DDC_SFBSR_2_cispt_1st(data)                                (0x00000001&(data))
#define ST_DDC_SFBSR_2_get_cirws_2nd(data)                            ((0x00000020&(data))>>5)
#define ST_DDC_SFBSR_2_get_cirws_1st(data)                            ((0x00000010&(data))>>4)
#define ST_DDC_SFBSR_2_get_cippt_2nd(data)                            ((0x00000008&(data))>>3)
#define ST_DDC_SFBSR_2_get_cispt_2nd(data)                            ((0x00000004&(data))>>2)
#define ST_DDC_SFBSR_2_get_cippt_1st(data)                            ((0x00000002&(data))>>1)
#define ST_DDC_SFBSR_2_get_cispt_1st(data)                            (0x00000001&(data))


#define ST_DDC_SFIBLR_2                                               0x18011c48
#define ST_DDC_SFIBLR_2_reg_addr                                      "0xb8011c48"
#define ST_DDC_SFIBLR_2_reg                                           0xb8011c48
#define ST_DDC_SFIBLR_2_inst_addr                                     "0x0312"
#define ST_DDC_SFIBLR_2_inst                                          0x0312
#define ST_DDC_SFIBLR_2_ffdi_dlen_shift                               (0)
#define ST_DDC_SFIBLR_2_ffdi_dlen_mask                                (0x0000001F)
#define ST_DDC_SFIBLR_2_ffdi_dlen(data)                               (0x0000001F&(data))
#define ST_DDC_SFIBLR_2_get_ffdi_dlen(data)                           (0x0000001F&(data))


#define ST_DDC_SFIBRWPR_2                                             0x18011c4c
#define ST_DDC_SFIBRWPR_2_reg_addr                                    "0xb8011c4c"
#define ST_DDC_SFIBRWPR_2_reg                                         0xb8011c4c
#define ST_DDC_SFIBRWPR_2_inst_addr                                   "0x0313"
#define ST_DDC_SFIBRWPR_2_inst                                        0x0313
#define ST_DDC_SFIBRWPR_2_diff_wpt_shift                              (4)
#define ST_DDC_SFIBRWPR_2_diff_rpt_shift                              (0)
#define ST_DDC_SFIBRWPR_2_diff_wpt_mask                               (0x000000F0)
#define ST_DDC_SFIBRWPR_2_diff_rpt_mask                               (0x0000000F)
#define ST_DDC_SFIBRWPR_2_diff_wpt(data)                              (0x000000F0&((data)<<4))
#define ST_DDC_SFIBRWPR_2_diff_rpt(data)                              (0x0000000F&(data))
#define ST_DDC_SFIBRWPR_2_get_diff_wpt(data)                          ((0x000000F0&(data))>>4)
#define ST_DDC_SFIBRWPR_2_get_diff_rpt(data)                          (0x0000000F&(data))


#define ST_DDC_SFIBSWPR_2                                             0x18011c50
#define ST_DDC_SFIBSWPR_2_reg_addr                                    "0xb8011c50"
#define ST_DDC_SFIBSWPR_2_reg                                         0xb8011c50
#define ST_DDC_SFIBSWPR_2_inst_addr                                   "0x0314"
#define ST_DDC_SFIBSWPR_2_inst                                        0x0314
#define ST_DDC_SFIBSWPR_2_diffstop_pt_shift                           (0)
#define ST_DDC_SFIBSWPR_2_diffstop_pt_mask                            (0x0000000F)
#define ST_DDC_SFIBSWPR_2_diffstop_pt(data)                           (0x0000000F&(data))
#define ST_DDC_SFIBSWPR_2_get_diffstop_pt(data)                       (0x0000000F&(data))


#define ST_DDC_SFOBSR_2                                               0x18011c54
#define ST_DDC_SFOBSR_2_reg_addr                                      "0xb8011c54"
#define ST_DDC_SFOBSR_2_reg                                           0xb8011c54
#define ST_DDC_SFOBSR_2_inst_addr                                     "0x0315"
#define ST_DDC_SFOBSR_2_inst                                          0x0315
#define ST_DDC_SFOBSR_2_ffdo_dlen_shift                               (0)
#define ST_DDC_SFOBSR_2_ffdo_dlen_mask                                (0x0000001F)
#define ST_DDC_SFOBSR_2_ffdo_dlen(data)                               (0x0000001F&(data))
#define ST_DDC_SFOBSR_2_get_ffdo_dlen(data)                           (0x0000001F&(data))


#define ST_DDC_SFOBRWPR_2                                             0x18011c58
#define ST_DDC_SFOBRWPR_2_reg_addr                                    "0xb8011c58"
#define ST_DDC_SFOBRWPR_2_reg                                         0xb8011c58
#define ST_DDC_SFOBRWPR_2_inst_addr                                   "0x0316"
#define ST_DDC_SFOBRWPR_2_inst                                        0x0316
#define ST_DDC_SFOBRWPR_2_doff_wpt_shift                              (4)
#define ST_DDC_SFOBRWPR_2_doff_rpt_shift                              (0)
#define ST_DDC_SFOBRWPR_2_doff_wpt_mask                               (0x000000F0)
#define ST_DDC_SFOBRWPR_2_doff_rpt_mask                               (0x0000000F)
#define ST_DDC_SFOBRWPR_2_doff_wpt(data)                              (0x000000F0&((data)<<4))
#define ST_DDC_SFOBRWPR_2_doff_rpt(data)                              (0x0000000F&(data))
#define ST_DDC_SFOBRWPR_2_get_doff_wpt(data)                          ((0x000000F0&(data))>>4)
#define ST_DDC_SFOBRWPR_2_get_doff_rpt(data)                          (0x0000000F&(data))


#define ST_DDC_SFSR_2                                                 0x18011c5c
#define ST_DDC_SFSR_2_reg_addr                                        "0xb8011c5c"
#define ST_DDC_SFSR_2_reg                                             0xb8011c5c
#define ST_DDC_SFSR_2_inst_addr                                       "0x0317"
#define ST_DDC_SFSR_2_inst                                            0x0317
#define ST_DDC_SFSR_2_ffdouf_st_shift                                 (7)
#define ST_DDC_SFSR_2_ffdiof_st_shift                                 (6)
#define ST_DDC_SFSR_2_ffdonf_st_shift                                 (5)
#define ST_DDC_SFSR_2_ffdoet_st_shift                                 (4)
#define ST_DDC_SFSR_2_ffdifu_st_shift                                 (3)
#define ST_DDC_SFSR_2_ffdine_st_shift                                 (2)
#define ST_DDC_SFSR_2_ffdouf_st_mask                                  (0x00000080)
#define ST_DDC_SFSR_2_ffdiof_st_mask                                  (0x00000040)
#define ST_DDC_SFSR_2_ffdonf_st_mask                                  (0x00000020)
#define ST_DDC_SFSR_2_ffdoet_st_mask                                  (0x00000010)
#define ST_DDC_SFSR_2_ffdifu_st_mask                                  (0x00000008)
#define ST_DDC_SFSR_2_ffdine_st_mask                                  (0x00000004)
#define ST_DDC_SFSR_2_ffdouf_st(data)                                 (0x00000080&((data)<<7))
#define ST_DDC_SFSR_2_ffdiof_st(data)                                 (0x00000040&((data)<<6))
#define ST_DDC_SFSR_2_ffdonf_st(data)                                 (0x00000020&((data)<<5))
#define ST_DDC_SFSR_2_ffdoet_st(data)                                 (0x00000010&((data)<<4))
#define ST_DDC_SFSR_2_ffdifu_st(data)                                 (0x00000008&((data)<<3))
#define ST_DDC_SFSR_2_ffdine_st(data)                                 (0x00000004&((data)<<2))
#define ST_DDC_SFSR_2_get_ffdouf_st(data)                             ((0x00000080&(data))>>7)
#define ST_DDC_SFSR_2_get_ffdiof_st(data)                             ((0x00000040&(data))>>6)
#define ST_DDC_SFSR_2_get_ffdonf_st(data)                             ((0x00000020&(data))>>5)
#define ST_DDC_SFSR_2_get_ffdoet_st(data)                             ((0x00000010&(data))>>4)
#define ST_DDC_SFSR_2_get_ffdifu_st(data)                             ((0x00000008&(data))>>3)
#define ST_DDC_SFSR_2_get_ffdine_st(data)                             ((0x00000004&(data))>>2)


#define ST_DDC_SFIR_2                                                 0x18011c60
#define ST_DDC_SFIR_2_reg_addr                                        "0xb8011c60"
#define ST_DDC_SFIR_2_reg                                             0xb8011c60
#define ST_DDC_SFIR_2_inst_addr                                       "0x0318"
#define ST_DDC_SFIR_2_inst                                            0x0318
#define ST_DDC_SFIR_2_ffdouf_ie_shift                                 (7)
#define ST_DDC_SFIR_2_ffdiof_ie_shift                                 (6)
#define ST_DDC_SFIR_2_ffdonf_ie_shift                                 (5)
#define ST_DDC_SFIR_2_ffdoet_ie_shift                                 (4)
#define ST_DDC_SFIR_2_ffdifu_ie_shift                                 (3)
#define ST_DDC_SFIR_2_ffdine_ie_shift                                 (2)
#define ST_DDC_SFIR_2_cippt_ie_shift                                  (1)
#define ST_DDC_SFIR_2_cispt_ie_shift                                  (0)
#define ST_DDC_SFIR_2_ffdouf_ie_mask                                  (0x00000080)
#define ST_DDC_SFIR_2_ffdiof_ie_mask                                  (0x00000040)
#define ST_DDC_SFIR_2_ffdonf_ie_mask                                  (0x00000020)
#define ST_DDC_SFIR_2_ffdoet_ie_mask                                  (0x00000010)
#define ST_DDC_SFIR_2_ffdifu_ie_mask                                  (0x00000008)
#define ST_DDC_SFIR_2_ffdine_ie_mask                                  (0x00000004)
#define ST_DDC_SFIR_2_cippt_ie_mask                                   (0x00000002)
#define ST_DDC_SFIR_2_cispt_ie_mask                                   (0x00000001)
#define ST_DDC_SFIR_2_ffdouf_ie(data)                                 (0x00000080&((data)<<7))
#define ST_DDC_SFIR_2_ffdiof_ie(data)                                 (0x00000040&((data)<<6))
#define ST_DDC_SFIR_2_ffdonf_ie(data)                                 (0x00000020&((data)<<5))
#define ST_DDC_SFIR_2_ffdoet_ie(data)                                 (0x00000010&((data)<<4))
#define ST_DDC_SFIR_2_ffdifu_ie(data)                                 (0x00000008&((data)<<3))
#define ST_DDC_SFIR_2_ffdine_ie(data)                                 (0x00000004&((data)<<2))
#define ST_DDC_SFIR_2_cippt_ie(data)                                  (0x00000002&((data)<<1))
#define ST_DDC_SFIR_2_cispt_ie(data)                                  (0x00000001&(data))
#define ST_DDC_SFIR_2_get_ffdouf_ie(data)                             ((0x00000080&(data))>>7)
#define ST_DDC_SFIR_2_get_ffdiof_ie(data)                             ((0x00000040&(data))>>6)
#define ST_DDC_SFIR_2_get_ffdonf_ie(data)                             ((0x00000020&(data))>>5)
#define ST_DDC_SFIR_2_get_ffdoet_ie(data)                             ((0x00000010&(data))>>4)
#define ST_DDC_SFIR_2_get_ffdifu_ie(data)                             ((0x00000008&(data))>>3)
#define ST_DDC_SFIR_2_get_ffdine_ie(data)                             ((0x00000004&(data))>>2)
#define ST_DDC_SFIR_2_get_cippt_ie(data)                              ((0x00000002&(data))>>1)
#define ST_DDC_SFIR_2_get_cispt_ie(data)                              (0x00000001&(data))


#define ST_DDC_FSMS_2                                                 0x18011c64
#define ST_DDC_FSMS_2_reg_addr                                        "0xb8011c64"
#define ST_DDC_FSMS_2_reg                                             0xb8011c64
#define ST_DDC_FSMS_2_inst_addr                                       "0x0319"
#define ST_DDC_FSMS_2_inst                                            0x0319
#define ST_DDC_FSMS_2_cmdfsm_st_shift                                 (0)
#define ST_DDC_FSMS_2_cmdfsm_st_mask                                  (0x000000FF)
#define ST_DDC_FSMS_2_cmdfsm_st(data)                                 (0x000000FF&(data))
#define ST_DDC_FSMS_2_get_cmdfsm_st(data)                             (0x000000FF&(data))


#define ST_I2C_CR_3                                                   0x18011d00
#define ST_I2C_CR_3_reg_addr                                          "0xb8011d00"
#define ST_I2C_CR_3_reg                                               0xb8011d00
#define ST_I2C_CR_3_inst_addr                                         "0x0340"
#define ST_I2C_CR_3_inst                                              0x0340
#define ST_I2C_CR_3_cmderr_ie_shift                                   (7)
#define ST_I2C_CR_3_timeout_en_shift                                  (6)
#define ST_I2C_CR_3_debounce_mode_shift                               (4)
#define ST_I2C_CR_3_timeout_ie_shift                                  (3)
#define ST_I2C_CR_3_retime_m_shift                                    (0)
#define ST_I2C_CR_3_cmderr_ie_mask                                    (0x00000080)
#define ST_I2C_CR_3_timeout_en_mask                                   (0x00000040)
#define ST_I2C_CR_3_debounce_mode_mask                                (0x00000030)
#define ST_I2C_CR_3_timeout_ie_mask                                   (0x00000008)
#define ST_I2C_CR_3_retime_m_mask                                     (0x00000007)
#define ST_I2C_CR_3_cmderr_ie(data)                                   (0x00000080&((data)<<7))
#define ST_I2C_CR_3_timeout_en(data)                                  (0x00000040&((data)<<6))
#define ST_I2C_CR_3_debounce_mode(data)                               (0x00000030&((data)<<4))
#define ST_I2C_CR_3_timeout_ie(data)                                  (0x00000008&((data)<<3))
#define ST_I2C_CR_3_retime_m(data)                                    (0x00000007&(data))
#define ST_I2C_CR_3_get_cmderr_ie(data)                               ((0x00000080&(data))>>7)
#define ST_I2C_CR_3_get_timeout_en(data)                              ((0x00000040&(data))>>6)
#define ST_I2C_CR_3_get_debounce_mode(data)                           ((0x00000030&(data))>>4)
#define ST_I2C_CR_3_get_timeout_ie(data)                              ((0x00000008&(data))>>3)
#define ST_I2C_CR_3_get_retime_m(data)                                (0x00000007&(data))


#define ST_I2C_SR_3                                                   0x18011d04
#define ST_I2C_SR_3_reg_addr                                          "0xb8011d04"
#define ST_I2C_SR_3_reg                                               0xb8011d04
#define ST_I2C_SR_3_inst_addr                                         "0x0341"
#define ST_I2C_SR_3_inst                                              0x0341
#define ST_I2C_SR_3_cmderr_shift                                      (7)
#define ST_I2C_SR_3_finish_shift                                      (4)
#define ST_I2C_SR_3_timeout_shift                                     (3)
#define ST_I2C_SR_3_cmderr_mask                                       (0x00000080)
#define ST_I2C_SR_3_finish_mask                                       (0x00000010)
#define ST_I2C_SR_3_timeout_mask                                      (0x00000008)
#define ST_I2C_SR_3_cmderr(data)                                      (0x00000080&((data)<<7))
#define ST_I2C_SR_3_finish(data)                                      (0x00000010&((data)<<4))
#define ST_I2C_SR_3_timeout(data)                                     (0x00000008&((data)<<3))
#define ST_I2C_SR_3_get_cmderr(data)                                  ((0x00000080&(data))>>7)
#define ST_I2C_SR_3_get_finish(data)                                  ((0x00000010&(data))>>4)
#define ST_I2C_SR_3_get_timeout(data)                                 ((0x00000008&(data))>>3)


#define ST_I2C_TR_3                                                   0x18011d08
#define ST_I2C_TR_3_reg_addr                                          "0xb8011d08"
#define ST_I2C_TR_3_reg                                               0xb8011d08
#define ST_I2C_TR_3_inst_addr                                         "0x0342"
#define ST_I2C_TR_3_inst                                              0x0342
#define ST_I2C_TR_3_timeout_val_shift                                 (0)
#define ST_I2C_TR_3_timeout_val_mask                                  (0x000000FF)
#define ST_I2C_TR_3_timeout_val(data)                                 (0x000000FF&(data))
#define ST_I2C_TR_3_get_timeout_val(data)                             (0x000000FF&(data))


#define ST_EDID_CR_3                                                  0x18011d0c
#define ST_EDID_CR_3_reg_addr                                         "0xb8011d0c"
#define ST_EDID_CR_3_reg                                              0xb8011d0c
#define ST_EDID_CR_3_inst_addr                                        "0x0343"
#define ST_EDID_CR_3_inst                                             0x0343
#define ST_EDID_CR_3_edid_address_shift                               (5)
#define ST_EDID_CR_3_finish_int_en_shift                              (4)
#define ST_EDID_CR_3_ddc1_force_shift                                 (3)
#define ST_EDID_CR_3_ddc2b_force_shift                                (2)
#define ST_EDID_CR_3_edid_srwen_shift                                 (1)
#define ST_EDID_CR_3_edid_en_shift                                    (0)
#define ST_EDID_CR_3_edid_address_mask                                (0x000000E0)
#define ST_EDID_CR_3_finish_int_en_mask                               (0x00000010)
#define ST_EDID_CR_3_ddc1_force_mask                                  (0x00000008)
#define ST_EDID_CR_3_ddc2b_force_mask                                 (0x00000004)
#define ST_EDID_CR_3_edid_srwen_mask                                  (0x00000002)
#define ST_EDID_CR_3_edid_en_mask                                     (0x00000001)
#define ST_EDID_CR_3_edid_address(data)                               (0x000000E0&((data)<<5))
#define ST_EDID_CR_3_finish_int_en(data)                              (0x00000010&((data)<<4))
#define ST_EDID_CR_3_ddc1_force(data)                                 (0x00000008&((data)<<3))
#define ST_EDID_CR_3_ddc2b_force(data)                                (0x00000004&((data)<<2))
#define ST_EDID_CR_3_edid_srwen(data)                                 (0x00000002&((data)<<1))
#define ST_EDID_CR_3_edid_en(data)                                    (0x00000001&(data))
#define ST_EDID_CR_3_get_edid_address(data)                           ((0x000000E0&(data))>>5)
#define ST_EDID_CR_3_get_finish_int_en(data)                          ((0x00000010&(data))>>4)
#define ST_EDID_CR_3_get_ddc1_force(data)                             ((0x00000008&(data))>>3)
#define ST_EDID_CR_3_get_ddc2b_force(data)                            ((0x00000004&(data))>>2)
#define ST_EDID_CR_3_get_edid_srwen(data)                             ((0x00000002&(data))>>1)
#define ST_EDID_CR_3_get_edid_en(data)                                (0x00000001&(data))


#define ST_DDC_VCR_3                                                  0x18011d10
#define ST_DDC_VCR_3_reg_addr                                         "0xb8011d10"
#define ST_DDC_VCR_3_reg                                              0xb8011d10
#define ST_DDC_VCR_3_inst_addr                                        "0x0344"
#define ST_DDC_VCR_3_inst                                             0x0344
#define ST_DDC_VCR_3_ddc1_vcount_shift                                (0)
#define ST_DDC_VCR_3_ddc1_vcount_mask                                 (0x000000FF)
#define ST_DDC_VCR_3_ddc1_vcount(data)                                (0x000000FF&(data))
#define ST_DDC_VCR_3_get_ddc1_vcount(data)                            (0x000000FF&(data))


#define ST_EDID_IMSWSAR_3                                             0x18011d14
#define ST_EDID_IMSWSAR_3_reg_addr                                    "0xb8011d14"
#define ST_EDID_IMSWSAR_3_reg                                         0xb8011d14
#define ST_EDID_IMSWSAR_3_inst_addr                                   "0x0345"
#define ST_EDID_IMSWSAR_3_inst                                        0x0345
#define ST_EDID_IMSWSAR_3_edid_sadr_shift                             (0)
#define ST_EDID_IMSWSAR_3_edid_sadr_mask                              (0x000000FF)
#define ST_EDID_IMSWSAR_3_edid_sadr(data)                             (0x000000FF&(data))
#define ST_EDID_IMSWSAR_3_get_edid_sadr(data)                         (0x000000FF&(data))


#define ST_EDID_IMSWEAR_3                                             0x18011d18
#define ST_EDID_IMSWEAR_3_reg_addr                                    "0xb8011d18"
#define ST_EDID_IMSWEAR_3_reg                                         0xb8011d18
#define ST_EDID_IMSWEAR_3_inst_addr                                   "0x0346"
#define ST_EDID_IMSWEAR_3_inst                                        0x0346
#define ST_EDID_IMSWEAR_3_edid_eadr_shift                             (0)
#define ST_EDID_IMSWEAR_3_edid_eadr_mask                              (0x000000FF)
#define ST_EDID_IMSWEAR_3_edid_eadr(data)                             (0x000000FF&(data))
#define ST_EDID_IMSWEAR_3_get_edid_eadr(data)                         (0x000000FF&(data))


#define ST_EDID_IR_3                                                  0x18011d1c
#define ST_EDID_IR_3_reg_addr                                         "0xb8011d1c"
#define ST_EDID_IR_3_reg                                              0xb8011d1c
#define ST_EDID_IR_3_inst_addr                                        "0x0347"
#define ST_EDID_IR_3_inst                                             0x0347
#define ST_EDID_IR_3_edidmode_shift                                   (6)
#define ST_EDID_IR_3_edidsubaddress_shift                             (5)
#define ST_EDID_IR_3_edidstop_shift                                   (4)
#define ST_EDID_IR_3_edidsubaddress_ie_shift                          (1)
#define ST_EDID_IR_3_edidstop_ie_shift                                (0)
#define ST_EDID_IR_3_edidmode_mask                                    (0x00000040)
#define ST_EDID_IR_3_edidsubaddress_mask                              (0x00000020)
#define ST_EDID_IR_3_edidstop_mask                                    (0x00000010)
#define ST_EDID_IR_3_edidsubaddress_ie_mask                           (0x00000002)
#define ST_EDID_IR_3_edidstop_ie_mask                                 (0x00000001)
#define ST_EDID_IR_3_edidmode(data)                                   (0x00000040&((data)<<6))
#define ST_EDID_IR_3_edidsubaddress(data)                             (0x00000020&((data)<<5))
#define ST_EDID_IR_3_edidstop(data)                                   (0x00000010&((data)<<4))
#define ST_EDID_IR_3_edidsubaddress_ie(data)                          (0x00000002&((data)<<1))
#define ST_EDID_IR_3_edidstop_ie(data)                                (0x00000001&(data))
#define ST_EDID_IR_3_get_edidmode(data)                               ((0x00000040&(data))>>6)
#define ST_EDID_IR_3_get_edidsubaddress(data)                         ((0x00000020&(data))>>5)
#define ST_EDID_IR_3_get_edidstop(data)                               ((0x00000010&(data))>>4)
#define ST_EDID_IR_3_get_edidsubaddress_ie(data)                      ((0x00000002&(data))>>1)
#define ST_EDID_IR_3_get_edidstop_ie(data)                            (0x00000001&(data))


#define ST_DDC_SIR_3                                                  0x18011d20
#define ST_DDC_SIR_3_reg_addr                                         "0xb8011d20"
#define ST_DDC_SIR_3_reg                                              0xb8011d20
#define ST_DDC_SIR_3_inst_addr                                        "0x0348"
#define ST_DDC_SIR_3_inst                                             0x0348
#define ST_DDC_SIR_3_edidap_shift                                     (0)
#define ST_DDC_SIR_3_edidap_mask                                      (0x000000FF)
#define ST_DDC_SIR_3_edidap(data)                                     (0x000000FF&(data))
#define ST_DDC_SIR_3_get_edidap(data)                                 (0x000000FF&(data))


#define ST_DDC_SAP_3                                                  0x18011d24
#define ST_DDC_SAP_3_reg_addr                                         "0xb8011d24"
#define ST_DDC_SAP_3_reg                                              0xb8011d24
#define ST_DDC_SAP_3_inst_addr                                        "0x0349"
#define ST_DDC_SAP_3_inst                                             0x0349
#define ST_DDC_SAP_3_ediddp_shift                                     (0)
#define ST_DDC_SAP_3_ediddp_mask                                      (0x000000FF)
#define ST_DDC_SAP_3_ediddp(data)                                     (0x000000FF&(data))
#define ST_DDC_SAP_3_get_ediddp(data)                                 (0x000000FF&(data))


#define ST_DDC_BISTCR_3                                               0x18011d28
#define ST_DDC_BISTCR_3_reg_addr                                      "0xb8011d28"
#define ST_DDC_BISTCR_3_reg                                           0xb8011d28
#define ST_DDC_BISTCR_3_inst_addr                                     "0x034A"
#define ST_DDC_BISTCR_3_inst                                          0x034A
#define ST_DDC_BISTCR_3_bist_fail_shift                               (5)
#define ST_DDC_BISTCR_3_bist_done_shift                               (4)
#define ST_DDC_BISTCR_3_bist_rstn_shift                               (1)
#define ST_DDC_BISTCR_3_bist_mode_shift                               (0)
#define ST_DDC_BISTCR_3_bist_fail_mask                                (0x00000020)
#define ST_DDC_BISTCR_3_bist_done_mask                                (0x00000010)
#define ST_DDC_BISTCR_3_bist_rstn_mask                                (0x00000002)
#define ST_DDC_BISTCR_3_bist_mode_mask                                (0x00000001)
#define ST_DDC_BISTCR_3_bist_fail(data)                               (0x00000020&((data)<<5))
#define ST_DDC_BISTCR_3_bist_done(data)                               (0x00000010&((data)<<4))
#define ST_DDC_BISTCR_3_bist_rstn(data)                               (0x00000002&((data)<<1))
#define ST_DDC_BISTCR_3_bist_mode(data)                               (0x00000001&(data))
#define ST_DDC_BISTCR_3_get_bist_fail(data)                           ((0x00000020&(data))>>5)
#define ST_DDC_BISTCR_3_get_bist_done(data)                           ((0x00000010&(data))>>4)
#define ST_DDC_BISTCR_3_get_bist_rstn(data)                           ((0x00000002&(data))>>1)
#define ST_DDC_BISTCR_3_get_bist_mode(data)                           (0x00000001&(data))


#define ST_DDC_SCR_3                                                  0x18011d2c
#define ST_DDC_SCR_3_reg_addr                                         "0xb8011d2c"
#define ST_DDC_SCR_3_reg                                              0xb8011d2c
#define ST_DDC_SCR_3_inst_addr                                        "0x034B"
#define ST_DDC_SCR_3_inst                                             0x034B
#define ST_DDC_SCR_3_segpt_latie_shift                                (7)
#define ST_DDC_SCR_3_sgid_en_shift                                    (0)
#define ST_DDC_SCR_3_segpt_latie_mask                                 (0x00000080)
#define ST_DDC_SCR_3_sgid_en_mask                                     (0x00000001)
#define ST_DDC_SCR_3_segpt_latie(data)                                (0x00000080&((data)<<7))
#define ST_DDC_SCR_3_sgid_en(data)                                    (0x00000001&(data))
#define ST_DDC_SCR_3_get_segpt_latie(data)                            ((0x00000080&(data))>>7)
#define ST_DDC_SCR_3_get_sgid_en(data)                                (0x00000001&(data))


#define ST_DDC_SSAR_3                                                 0x18011d30
#define ST_DDC_SSAR_3_reg_addr                                        "0xb8011d30"
#define ST_DDC_SSAR_3_reg                                             0xb8011d30
#define ST_DDC_SSAR_3_inst_addr                                       "0x034C"
#define ST_DDC_SSAR_3_inst                                            0x034C
#define ST_DDC_SSAR_3_sgid_address_shift                              (1)
#define ST_DDC_SSAR_3_sgid_dtrden_shift                               (0)
#define ST_DDC_SSAR_3_sgid_address_mask                               (0x000000FE)
#define ST_DDC_SSAR_3_sgid_dtrden_mask                                (0x00000001)
#define ST_DDC_SSAR_3_sgid_address(data)                              (0x000000FE&((data)<<1))
#define ST_DDC_SSAR_3_sgid_dtrden(data)                               (0x00000001&(data))
#define ST_DDC_SSAR_3_get_sgid_address(data)                          ((0x000000FE&(data))>>1)
#define ST_DDC_SSAR_3_get_sgid_dtrden(data)                           (0x00000001&(data))


#define ST_DDC_SPR_3                                                  0x18011d34
#define ST_DDC_SPR_3_reg_addr                                         "0xb8011d34"
#define ST_DDC_SPR_3_reg                                              0xb8011d34
#define ST_DDC_SPR_3_inst_addr                                        "0x034D"
#define ST_DDC_SPR_3_inst                                             0x034D
#define ST_DDC_SPR_3_segpt_latched_shift                              (7)
#define ST_DDC_SPR_3_seg_pt_shift                                     (0)
#define ST_DDC_SPR_3_segpt_latched_mask                               (0x00000080)
#define ST_DDC_SPR_3_seg_pt_mask                                      (0x0000007F)
#define ST_DDC_SPR_3_segpt_latched(data)                              (0x00000080&((data)<<7))
#define ST_DDC_SPR_3_seg_pt(data)                                     (0x0000007F&(data))
#define ST_DDC_SPR_3_get_segpt_latched(data)                          ((0x00000080&(data))>>7)
#define ST_DDC_SPR_3_get_seg_pt(data)                                 (0x0000007F&(data))


#define ST_DDC_SFCR_3                                                 0x18011d38
#define ST_DDC_SFCR_3_reg_addr                                        "0xb8011d38"
#define ST_DDC_SFCR_3_reg                                             0xb8011d38
#define ST_DDC_SFCR_3_inst_addr                                       "0x034E"
#define ST_DDC_SFCR_3_inst                                            0x034E
#define ST_DDC_SFCR_3_special_mode_shift                              (3)
#define ST_DDC_SFCR_3_doffpt_reset_shift                              (2)
#define ST_DDC_SFCR_3_diffpt_reset_shift                              (1)
#define ST_DDC_SFCR_3_ciid_en_shift                                   (0)
#define ST_DDC_SFCR_3_special_mode_mask                               (0x00000008)
#define ST_DDC_SFCR_3_doffpt_reset_mask                               (0x00000004)
#define ST_DDC_SFCR_3_diffpt_reset_mask                               (0x00000002)
#define ST_DDC_SFCR_3_ciid_en_mask                                    (0x00000001)
#define ST_DDC_SFCR_3_special_mode(data)                              (0x00000008&((data)<<3))
#define ST_DDC_SFCR_3_doffpt_reset(data)                              (0x00000004&((data)<<2))
#define ST_DDC_SFCR_3_diffpt_reset(data)                              (0x00000002&((data)<<1))
#define ST_DDC_SFCR_3_ciid_en(data)                                   (0x00000001&(data))
#define ST_DDC_SFCR_3_get_special_mode(data)                          ((0x00000008&(data))>>3)
#define ST_DDC_SFCR_3_get_doffpt_reset(data)                          ((0x00000004&(data))>>2)
#define ST_DDC_SFCR_3_get_diffpt_reset(data)                          ((0x00000002&(data))>>1)
#define ST_DDC_SFCR_3_get_ciid_en(data)                               (0x00000001&(data))


#define ST_DDC_SFSAR_3                                                0x18011d3c
#define ST_DDC_SFSAR_3_reg_addr                                       "0xb8011d3c"
#define ST_DDC_SFSAR_3_reg                                            0xb8011d3c
#define ST_DDC_SFSAR_3_inst_addr                                      "0x034F"
#define ST_DDC_SFSAR_3_inst                                           0x034F
#define ST_DDC_SFSAR_3_ciid_address_shift                             (1)
#define ST_DDC_SFSAR_3_cirws_current_shift                            (0)
#define ST_DDC_SFSAR_3_ciid_address_mask                              (0x000000FE)
#define ST_DDC_SFSAR_3_cirws_current_mask                             (0x00000001)
#define ST_DDC_SFSAR_3_ciid_address(data)                             (0x000000FE&((data)<<1))
#define ST_DDC_SFSAR_3_cirws_current(data)                            (0x00000001&(data))
#define ST_DDC_SFSAR_3_get_ciid_address(data)                         ((0x000000FE&(data))>>1)
#define ST_DDC_SFSAR_3_get_cirws_current(data)                        (0x00000001&(data))


#define ST_DDC_SFDR_3                                                 0x18011d40
#define ST_DDC_SFDR_3_reg_addr                                        "0xb8011d40"
#define ST_DDC_SFDR_3_reg                                             0xb8011d40
#define ST_DDC_SFDR_3_inst_addr                                       "0x0350"
#define ST_DDC_SFDR_3_inst                                            0x0350
#define ST_DDC_SFDR_3_ciiddp_shift                                    (0)
#define ST_DDC_SFDR_3_ciiddp_mask                                     (0x000000FF)
#define ST_DDC_SFDR_3_ciiddp(data)                                    (0x000000FF&(data))
#define ST_DDC_SFDR_3_get_ciiddp(data)                                (0x000000FF&(data))


#define ST_DDC_SFBSR_3                                                0x18011d44
#define ST_DDC_SFBSR_3_reg_addr                                       "0xb8011d44"
#define ST_DDC_SFBSR_3_reg                                            0xb8011d44
#define ST_DDC_SFBSR_3_inst_addr                                      "0x0351"
#define ST_DDC_SFBSR_3_inst                                           0x0351
#define ST_DDC_SFBSR_3_cirws_2nd_shift                                (5)
#define ST_DDC_SFBSR_3_cirws_1st_shift                                (4)
#define ST_DDC_SFBSR_3_cippt_2nd_shift                                (3)
#define ST_DDC_SFBSR_3_cispt_2nd_shift                                (2)
#define ST_DDC_SFBSR_3_cippt_1st_shift                                (1)
#define ST_DDC_SFBSR_3_cispt_1st_shift                                (0)
#define ST_DDC_SFBSR_3_cirws_2nd_mask                                 (0x00000020)
#define ST_DDC_SFBSR_3_cirws_1st_mask                                 (0x00000010)
#define ST_DDC_SFBSR_3_cippt_2nd_mask                                 (0x00000008)
#define ST_DDC_SFBSR_3_cispt_2nd_mask                                 (0x00000004)
#define ST_DDC_SFBSR_3_cippt_1st_mask                                 (0x00000002)
#define ST_DDC_SFBSR_3_cispt_1st_mask                                 (0x00000001)
#define ST_DDC_SFBSR_3_cirws_2nd(data)                                (0x00000020&((data)<<5))
#define ST_DDC_SFBSR_3_cirws_1st(data)                                (0x00000010&((data)<<4))
#define ST_DDC_SFBSR_3_cippt_2nd(data)                                (0x00000008&((data)<<3))
#define ST_DDC_SFBSR_3_cispt_2nd(data)                                (0x00000004&((data)<<2))
#define ST_DDC_SFBSR_3_cippt_1st(data)                                (0x00000002&((data)<<1))
#define ST_DDC_SFBSR_3_cispt_1st(data)                                (0x00000001&(data))
#define ST_DDC_SFBSR_3_get_cirws_2nd(data)                            ((0x00000020&(data))>>5)
#define ST_DDC_SFBSR_3_get_cirws_1st(data)                            ((0x00000010&(data))>>4)
#define ST_DDC_SFBSR_3_get_cippt_2nd(data)                            ((0x00000008&(data))>>3)
#define ST_DDC_SFBSR_3_get_cispt_2nd(data)                            ((0x00000004&(data))>>2)
#define ST_DDC_SFBSR_3_get_cippt_1st(data)                            ((0x00000002&(data))>>1)
#define ST_DDC_SFBSR_3_get_cispt_1st(data)                            (0x00000001&(data))


#define ST_DDC_SFIBLR_3                                               0x18011d48
#define ST_DDC_SFIBLR_3_reg_addr                                      "0xb8011d48"
#define ST_DDC_SFIBLR_3_reg                                           0xb8011d48
#define ST_DDC_SFIBLR_3_inst_addr                                     "0x0352"
#define ST_DDC_SFIBLR_3_inst                                          0x0352
#define ST_DDC_SFIBLR_3_ffdi_dlen_shift                               (0)
#define ST_DDC_SFIBLR_3_ffdi_dlen_mask                                (0x0000001F)
#define ST_DDC_SFIBLR_3_ffdi_dlen(data)                               (0x0000001F&(data))
#define ST_DDC_SFIBLR_3_get_ffdi_dlen(data)                           (0x0000001F&(data))


#define ST_DDC_SFIBRWPR_3                                             0x18011d4c
#define ST_DDC_SFIBRWPR_3_reg_addr                                    "0xb8011d4c"
#define ST_DDC_SFIBRWPR_3_reg                                         0xb8011d4c
#define ST_DDC_SFIBRWPR_3_inst_addr                                   "0x0353"
#define ST_DDC_SFIBRWPR_3_inst                                        0x0353
#define ST_DDC_SFIBRWPR_3_diff_wpt_shift                              (4)
#define ST_DDC_SFIBRWPR_3_diff_rpt_shift                              (0)
#define ST_DDC_SFIBRWPR_3_diff_wpt_mask                               (0x000000F0)
#define ST_DDC_SFIBRWPR_3_diff_rpt_mask                               (0x0000000F)
#define ST_DDC_SFIBRWPR_3_diff_wpt(data)                              (0x000000F0&((data)<<4))
#define ST_DDC_SFIBRWPR_3_diff_rpt(data)                              (0x0000000F&(data))
#define ST_DDC_SFIBRWPR_3_get_diff_wpt(data)                          ((0x000000F0&(data))>>4)
#define ST_DDC_SFIBRWPR_3_get_diff_rpt(data)                          (0x0000000F&(data))


#define ST_DDC_SFIBSWPR_3                                             0x18011d50
#define ST_DDC_SFIBSWPR_3_reg_addr                                    "0xb8011d50"
#define ST_DDC_SFIBSWPR_3_reg                                         0xb8011d50
#define ST_DDC_SFIBSWPR_3_inst_addr                                   "0x0354"
#define ST_DDC_SFIBSWPR_3_inst                                        0x0354
#define ST_DDC_SFIBSWPR_3_diffstop_pt_shift                           (0)
#define ST_DDC_SFIBSWPR_3_diffstop_pt_mask                            (0x0000000F)
#define ST_DDC_SFIBSWPR_3_diffstop_pt(data)                           (0x0000000F&(data))
#define ST_DDC_SFIBSWPR_3_get_diffstop_pt(data)                       (0x0000000F&(data))


#define ST_DDC_SFOBSR_3                                               0x18011d54
#define ST_DDC_SFOBSR_3_reg_addr                                      "0xb8011d54"
#define ST_DDC_SFOBSR_3_reg                                           0xb8011d54
#define ST_DDC_SFOBSR_3_inst_addr                                     "0x0355"
#define ST_DDC_SFOBSR_3_inst                                          0x0355
#define ST_DDC_SFOBSR_3_ffdo_dlen_shift                               (0)
#define ST_DDC_SFOBSR_3_ffdo_dlen_mask                                (0x0000001F)
#define ST_DDC_SFOBSR_3_ffdo_dlen(data)                               (0x0000001F&(data))
#define ST_DDC_SFOBSR_3_get_ffdo_dlen(data)                           (0x0000001F&(data))


#define ST_DDC_SFOBRWPR_3                                             0x18011d58
#define ST_DDC_SFOBRWPR_3_reg_addr                                    "0xb8011d58"
#define ST_DDC_SFOBRWPR_3_reg                                         0xb8011d58
#define ST_DDC_SFOBRWPR_3_inst_addr                                   "0x0356"
#define ST_DDC_SFOBRWPR_3_inst                                        0x0356
#define ST_DDC_SFOBRWPR_3_doff_wpt_shift                              (4)
#define ST_DDC_SFOBRWPR_3_doff_rpt_shift                              (0)
#define ST_DDC_SFOBRWPR_3_doff_wpt_mask                               (0x000000F0)
#define ST_DDC_SFOBRWPR_3_doff_rpt_mask                               (0x0000000F)
#define ST_DDC_SFOBRWPR_3_doff_wpt(data)                              (0x000000F0&((data)<<4))
#define ST_DDC_SFOBRWPR_3_doff_rpt(data)                              (0x0000000F&(data))
#define ST_DDC_SFOBRWPR_3_get_doff_wpt(data)                          ((0x000000F0&(data))>>4)
#define ST_DDC_SFOBRWPR_3_get_doff_rpt(data)                          (0x0000000F&(data))


#define ST_DDC_SFSR_3                                                 0x18011d5c
#define ST_DDC_SFSR_3_reg_addr                                        "0xb8011d5c"
#define ST_DDC_SFSR_3_reg                                             0xb8011d5c
#define ST_DDC_SFSR_3_inst_addr                                       "0x0357"
#define ST_DDC_SFSR_3_inst                                            0x0357
#define ST_DDC_SFSR_3_ffdouf_st_shift                                 (7)
#define ST_DDC_SFSR_3_ffdiof_st_shift                                 (6)
#define ST_DDC_SFSR_3_ffdonf_st_shift                                 (5)
#define ST_DDC_SFSR_3_ffdoet_st_shift                                 (4)
#define ST_DDC_SFSR_3_ffdifu_st_shift                                 (3)
#define ST_DDC_SFSR_3_ffdine_st_shift                                 (2)
#define ST_DDC_SFSR_3_ffdouf_st_mask                                  (0x00000080)
#define ST_DDC_SFSR_3_ffdiof_st_mask                                  (0x00000040)
#define ST_DDC_SFSR_3_ffdonf_st_mask                                  (0x00000020)
#define ST_DDC_SFSR_3_ffdoet_st_mask                                  (0x00000010)
#define ST_DDC_SFSR_3_ffdifu_st_mask                                  (0x00000008)
#define ST_DDC_SFSR_3_ffdine_st_mask                                  (0x00000004)
#define ST_DDC_SFSR_3_ffdouf_st(data)                                 (0x00000080&((data)<<7))
#define ST_DDC_SFSR_3_ffdiof_st(data)                                 (0x00000040&((data)<<6))
#define ST_DDC_SFSR_3_ffdonf_st(data)                                 (0x00000020&((data)<<5))
#define ST_DDC_SFSR_3_ffdoet_st(data)                                 (0x00000010&((data)<<4))
#define ST_DDC_SFSR_3_ffdifu_st(data)                                 (0x00000008&((data)<<3))
#define ST_DDC_SFSR_3_ffdine_st(data)                                 (0x00000004&((data)<<2))
#define ST_DDC_SFSR_3_get_ffdouf_st(data)                             ((0x00000080&(data))>>7)
#define ST_DDC_SFSR_3_get_ffdiof_st(data)                             ((0x00000040&(data))>>6)
#define ST_DDC_SFSR_3_get_ffdonf_st(data)                             ((0x00000020&(data))>>5)
#define ST_DDC_SFSR_3_get_ffdoet_st(data)                             ((0x00000010&(data))>>4)
#define ST_DDC_SFSR_3_get_ffdifu_st(data)                             ((0x00000008&(data))>>3)
#define ST_DDC_SFSR_3_get_ffdine_st(data)                             ((0x00000004&(data))>>2)


#define ST_DDC_SFIR_3                                                 0x18011d60
#define ST_DDC_SFIR_3_reg_addr                                        "0xb8011d60"
#define ST_DDC_SFIR_3_reg                                             0xb8011d60
#define ST_DDC_SFIR_3_inst_addr                                       "0x0358"
#define ST_DDC_SFIR_3_inst                                            0x0358
#define ST_DDC_SFIR_3_ffdouf_ie_shift                                 (7)
#define ST_DDC_SFIR_3_ffdiof_ie_shift                                 (6)
#define ST_DDC_SFIR_3_ffdonf_ie_shift                                 (5)
#define ST_DDC_SFIR_3_ffdoet_ie_shift                                 (4)
#define ST_DDC_SFIR_3_ffdifu_ie_shift                                 (3)
#define ST_DDC_SFIR_3_ffdine_ie_shift                                 (2)
#define ST_DDC_SFIR_3_cippt_ie_shift                                  (1)
#define ST_DDC_SFIR_3_cispt_ie_shift                                  (0)
#define ST_DDC_SFIR_3_ffdouf_ie_mask                                  (0x00000080)
#define ST_DDC_SFIR_3_ffdiof_ie_mask                                  (0x00000040)
#define ST_DDC_SFIR_3_ffdonf_ie_mask                                  (0x00000020)
#define ST_DDC_SFIR_3_ffdoet_ie_mask                                  (0x00000010)
#define ST_DDC_SFIR_3_ffdifu_ie_mask                                  (0x00000008)
#define ST_DDC_SFIR_3_ffdine_ie_mask                                  (0x00000004)
#define ST_DDC_SFIR_3_cippt_ie_mask                                   (0x00000002)
#define ST_DDC_SFIR_3_cispt_ie_mask                                   (0x00000001)
#define ST_DDC_SFIR_3_ffdouf_ie(data)                                 (0x00000080&((data)<<7))
#define ST_DDC_SFIR_3_ffdiof_ie(data)                                 (0x00000040&((data)<<6))
#define ST_DDC_SFIR_3_ffdonf_ie(data)                                 (0x00000020&((data)<<5))
#define ST_DDC_SFIR_3_ffdoet_ie(data)                                 (0x00000010&((data)<<4))
#define ST_DDC_SFIR_3_ffdifu_ie(data)                                 (0x00000008&((data)<<3))
#define ST_DDC_SFIR_3_ffdine_ie(data)                                 (0x00000004&((data)<<2))
#define ST_DDC_SFIR_3_cippt_ie(data)                                  (0x00000002&((data)<<1))
#define ST_DDC_SFIR_3_cispt_ie(data)                                  (0x00000001&(data))
#define ST_DDC_SFIR_3_get_ffdouf_ie(data)                             ((0x00000080&(data))>>7)
#define ST_DDC_SFIR_3_get_ffdiof_ie(data)                             ((0x00000040&(data))>>6)
#define ST_DDC_SFIR_3_get_ffdonf_ie(data)                             ((0x00000020&(data))>>5)
#define ST_DDC_SFIR_3_get_ffdoet_ie(data)                             ((0x00000010&(data))>>4)
#define ST_DDC_SFIR_3_get_ffdifu_ie(data)                             ((0x00000008&(data))>>3)
#define ST_DDC_SFIR_3_get_ffdine_ie(data)                             ((0x00000004&(data))>>2)
#define ST_DDC_SFIR_3_get_cippt_ie(data)                              ((0x00000002&(data))>>1)
#define ST_DDC_SFIR_3_get_cispt_ie(data)                              (0x00000001&(data))


#define ST_DDC_FSMS_3                                                 0x18011d64
#define ST_DDC_FSMS_3_reg_addr                                        "0xb8011d64"
#define ST_DDC_FSMS_3_reg                                             0xb8011d64
#define ST_DDC_FSMS_3_inst_addr                                       "0x0359"
#define ST_DDC_FSMS_3_inst                                            0x0359
#define ST_DDC_FSMS_3_cmdfsm_st_shift                                 (0)
#define ST_DDC_FSMS_3_cmdfsm_st_mask                                  (0x000000FF)
#define ST_DDC_FSMS_3_cmdfsm_st(data)                                 (0x000000FF&(data))
#define ST_DDC_FSMS_3_get_cmdfsm_st(data)                             (0x000000FF&(data))


#define ST_I2C_CR_4                                                   0x18011e00
#define ST_I2C_CR_4_reg_addr                                          "0xb8011e00"
#define ST_I2C_CR_4_reg                                               0xb8011e00
#define ST_I2C_CR_4_inst_addr                                         "0x0380"
#define ST_I2C_CR_4_inst                                              0x0380
#define ST_I2C_CR_4_cmderr_ie_shift                                   (7)
#define ST_I2C_CR_4_timeout_en_shift                                  (6)
#define ST_I2C_CR_4_debounce_mode_shift                               (4)
#define ST_I2C_CR_4_timeout_ie_shift                                  (3)
#define ST_I2C_CR_4_retime_m_shift                                    (0)
#define ST_I2C_CR_4_cmderr_ie_mask                                    (0x00000080)
#define ST_I2C_CR_4_timeout_en_mask                                   (0x00000040)
#define ST_I2C_CR_4_debounce_mode_mask                                (0x00000030)
#define ST_I2C_CR_4_timeout_ie_mask                                   (0x00000008)
#define ST_I2C_CR_4_retime_m_mask                                     (0x00000007)
#define ST_I2C_CR_4_cmderr_ie(data)                                   (0x00000080&((data)<<7))
#define ST_I2C_CR_4_timeout_en(data)                                  (0x00000040&((data)<<6))
#define ST_I2C_CR_4_debounce_mode(data)                               (0x00000030&((data)<<4))
#define ST_I2C_CR_4_timeout_ie(data)                                  (0x00000008&((data)<<3))
#define ST_I2C_CR_4_retime_m(data)                                    (0x00000007&(data))
#define ST_I2C_CR_4_get_cmderr_ie(data)                               ((0x00000080&(data))>>7)
#define ST_I2C_CR_4_get_timeout_en(data)                              ((0x00000040&(data))>>6)
#define ST_I2C_CR_4_get_debounce_mode(data)                           ((0x00000030&(data))>>4)
#define ST_I2C_CR_4_get_timeout_ie(data)                              ((0x00000008&(data))>>3)
#define ST_I2C_CR_4_get_retime_m(data)                                (0x00000007&(data))


#define ST_I2C_SR_4                                                   0x18011e04
#define ST_I2C_SR_4_reg_addr                                          "0xb8011e04"
#define ST_I2C_SR_4_reg                                               0xb8011e04
#define ST_I2C_SR_4_inst_addr                                         "0x0381"
#define ST_I2C_SR_4_inst                                              0x0381
#define ST_I2C_SR_4_cmderr_shift                                      (7)
#define ST_I2C_SR_4_finish_shift                                      (4)
#define ST_I2C_SR_4_timeout_shift                                     (3)
#define ST_I2C_SR_4_cmderr_mask                                       (0x00000080)
#define ST_I2C_SR_4_finish_mask                                       (0x00000010)
#define ST_I2C_SR_4_timeout_mask                                      (0x00000008)
#define ST_I2C_SR_4_cmderr(data)                                      (0x00000080&((data)<<7))
#define ST_I2C_SR_4_finish(data)                                      (0x00000010&((data)<<4))
#define ST_I2C_SR_4_timeout(data)                                     (0x00000008&((data)<<3))
#define ST_I2C_SR_4_get_cmderr(data)                                  ((0x00000080&(data))>>7)
#define ST_I2C_SR_4_get_finish(data)                                  ((0x00000010&(data))>>4)
#define ST_I2C_SR_4_get_timeout(data)                                 ((0x00000008&(data))>>3)


#define ST_I2C_TR_4                                                   0x18011e08
#define ST_I2C_TR_4_reg_addr                                          "0xb8011e08"
#define ST_I2C_TR_4_reg                                               0xb8011e08
#define ST_I2C_TR_4_inst_addr                                         "0x0382"
#define ST_I2C_TR_4_inst                                              0x0382
#define ST_I2C_TR_4_timeout_val_shift                                 (0)
#define ST_I2C_TR_4_timeout_val_mask                                  (0x000000FF)
#define ST_I2C_TR_4_timeout_val(data)                                 (0x000000FF&(data))
#define ST_I2C_TR_4_get_timeout_val(data)                             (0x000000FF&(data))


#define ST_EDID_CR_4                                                  0x18011e0c
#define ST_EDID_CR_4_reg_addr                                         "0xb8011e0c"
#define ST_EDID_CR_4_reg                                              0xb8011e0c
#define ST_EDID_CR_4_inst_addr                                        "0x0383"
#define ST_EDID_CR_4_inst                                             0x0383
#define ST_EDID_CR_4_edid_address_shift                               (5)
#define ST_EDID_CR_4_finish_int_en_shift                              (4)
#define ST_EDID_CR_4_ddc1_force_shift                                 (3)
#define ST_EDID_CR_4_ddc2b_force_shift                                (2)
#define ST_EDID_CR_4_edid_srwen_shift                                 (1)
#define ST_EDID_CR_4_edid_en_shift                                    (0)
#define ST_EDID_CR_4_edid_address_mask                                (0x000000E0)
#define ST_EDID_CR_4_finish_int_en_mask                               (0x00000010)
#define ST_EDID_CR_4_ddc1_force_mask                                  (0x00000008)
#define ST_EDID_CR_4_ddc2b_force_mask                                 (0x00000004)
#define ST_EDID_CR_4_edid_srwen_mask                                  (0x00000002)
#define ST_EDID_CR_4_edid_en_mask                                     (0x00000001)
#define ST_EDID_CR_4_edid_address(data)                               (0x000000E0&((data)<<5))
#define ST_EDID_CR_4_finish_int_en(data)                              (0x00000010&((data)<<4))
#define ST_EDID_CR_4_ddc1_force(data)                                 (0x00000008&((data)<<3))
#define ST_EDID_CR_4_ddc2b_force(data)                                (0x00000004&((data)<<2))
#define ST_EDID_CR_4_edid_srwen(data)                                 (0x00000002&((data)<<1))
#define ST_EDID_CR_4_edid_en(data)                                    (0x00000001&(data))
#define ST_EDID_CR_4_get_edid_address(data)                           ((0x000000E0&(data))>>5)
#define ST_EDID_CR_4_get_finish_int_en(data)                          ((0x00000010&(data))>>4)
#define ST_EDID_CR_4_get_ddc1_force(data)                             ((0x00000008&(data))>>3)
#define ST_EDID_CR_4_get_ddc2b_force(data)                            ((0x00000004&(data))>>2)
#define ST_EDID_CR_4_get_edid_srwen(data)                             ((0x00000002&(data))>>1)
#define ST_EDID_CR_4_get_edid_en(data)                                (0x00000001&(data))


#define ST_DDC_VCR_4                                                  0x18011e10
#define ST_DDC_VCR_4_reg_addr                                         "0xb8011e10"
#define ST_DDC_VCR_4_reg                                              0xb8011e10
#define ST_DDC_VCR_4_inst_addr                                        "0x0384"
#define ST_DDC_VCR_4_inst                                             0x0384
#define ST_DDC_VCR_4_ddc1_vcount_shift                                (0)
#define ST_DDC_VCR_4_ddc1_vcount_mask                                 (0x000000FF)
#define ST_DDC_VCR_4_ddc1_vcount(data)                                (0x000000FF&(data))
#define ST_DDC_VCR_4_get_ddc1_vcount(data)                            (0x000000FF&(data))


#define ST_EDID_IMSWSAR_4                                             0x18011e14
#define ST_EDID_IMSWSAR_4_reg_addr                                    "0xb8011e14"
#define ST_EDID_IMSWSAR_4_reg                                         0xb8011e14
#define ST_EDID_IMSWSAR_4_inst_addr                                   "0x0385"
#define ST_EDID_IMSWSAR_4_inst                                        0x0385
#define ST_EDID_IMSWSAR_4_edid_sadr_shift                             (0)
#define ST_EDID_IMSWSAR_4_edid_sadr_mask                              (0x000000FF)
#define ST_EDID_IMSWSAR_4_edid_sadr(data)                             (0x000000FF&(data))
#define ST_EDID_IMSWSAR_4_get_edid_sadr(data)                         (0x000000FF&(data))


#define ST_EDID_IMSWEAR_4                                             0x18011e18
#define ST_EDID_IMSWEAR_4_reg_addr                                    "0xb8011e18"
#define ST_EDID_IMSWEAR_4_reg                                         0xb8011e18
#define ST_EDID_IMSWEAR_4_inst_addr                                   "0x0386"
#define ST_EDID_IMSWEAR_4_inst                                        0x0386
#define ST_EDID_IMSWEAR_4_edid_eadr_shift                             (0)
#define ST_EDID_IMSWEAR_4_edid_eadr_mask                              (0x000000FF)
#define ST_EDID_IMSWEAR_4_edid_eadr(data)                             (0x000000FF&(data))
#define ST_EDID_IMSWEAR_4_get_edid_eadr(data)                         (0x000000FF&(data))


#define ST_EDID_IR_4                                                  0x18011e1c
#define ST_EDID_IR_4_reg_addr                                         "0xb8011e1c"
#define ST_EDID_IR_4_reg                                              0xb8011e1c
#define ST_EDID_IR_4_inst_addr                                        "0x0387"
#define ST_EDID_IR_4_inst                                             0x0387
#define ST_EDID_IR_4_edidmode_shift                                   (6)
#define ST_EDID_IR_4_edidsubaddress_shift                             (5)
#define ST_EDID_IR_4_edidstop_shift                                   (4)
#define ST_EDID_IR_4_edidsubaddress_ie_shift                          (1)
#define ST_EDID_IR_4_edidstop_ie_shift                                (0)
#define ST_EDID_IR_4_edidmode_mask                                    (0x00000040)
#define ST_EDID_IR_4_edidsubaddress_mask                              (0x00000020)
#define ST_EDID_IR_4_edidstop_mask                                    (0x00000010)
#define ST_EDID_IR_4_edidsubaddress_ie_mask                           (0x00000002)
#define ST_EDID_IR_4_edidstop_ie_mask                                 (0x00000001)
#define ST_EDID_IR_4_edidmode(data)                                   (0x00000040&((data)<<6))
#define ST_EDID_IR_4_edidsubaddress(data)                             (0x00000020&((data)<<5))
#define ST_EDID_IR_4_edidstop(data)                                   (0x00000010&((data)<<4))
#define ST_EDID_IR_4_edidsubaddress_ie(data)                          (0x00000002&((data)<<1))
#define ST_EDID_IR_4_edidstop_ie(data)                                (0x00000001&(data))
#define ST_EDID_IR_4_get_edidmode(data)                               ((0x00000040&(data))>>6)
#define ST_EDID_IR_4_get_edidsubaddress(data)                         ((0x00000020&(data))>>5)
#define ST_EDID_IR_4_get_edidstop(data)                               ((0x00000010&(data))>>4)
#define ST_EDID_IR_4_get_edidsubaddress_ie(data)                      ((0x00000002&(data))>>1)
#define ST_EDID_IR_4_get_edidstop_ie(data)                            (0x00000001&(data))


#define ST_DDC_SIR_4                                                  0x18011e20
#define ST_DDC_SIR_4_reg_addr                                         "0xb8011e20"
#define ST_DDC_SIR_4_reg                                              0xb8011e20
#define ST_DDC_SIR_4_inst_addr                                        "0x0388"
#define ST_DDC_SIR_4_inst                                             0x0388
#define ST_DDC_SIR_4_edidap_shift                                     (0)
#define ST_DDC_SIR_4_edidap_mask                                      (0x000000FF)
#define ST_DDC_SIR_4_edidap(data)                                     (0x000000FF&(data))
#define ST_DDC_SIR_4_get_edidap(data)                                 (0x000000FF&(data))


#define ST_DDC_SAP_4                                                  0x18011e24
#define ST_DDC_SAP_4_reg_addr                                         "0xb8011e24"
#define ST_DDC_SAP_4_reg                                              0xb8011e24
#define ST_DDC_SAP_4_inst_addr                                        "0x0389"
#define ST_DDC_SAP_4_inst                                             0x0389
#define ST_DDC_SAP_4_ediddp_shift                                     (0)
#define ST_DDC_SAP_4_ediddp_mask                                      (0x000000FF)
#define ST_DDC_SAP_4_ediddp(data)                                     (0x000000FF&(data))
#define ST_DDC_SAP_4_get_ediddp(data)                                 (0x000000FF&(data))


#define ST_DDC_BISTCR_4                                               0x18011e28
#define ST_DDC_BISTCR_4_reg_addr                                      "0xb8011e28"
#define ST_DDC_BISTCR_4_reg                                           0xb8011e28
#define ST_DDC_BISTCR_4_inst_addr                                     "0x038A"
#define ST_DDC_BISTCR_4_inst                                          0x038A
#define ST_DDC_BISTCR_4_bist_fail_shift                               (5)
#define ST_DDC_BISTCR_4_bist_done_shift                               (4)
#define ST_DDC_BISTCR_4_bist_rstn_shift                               (1)
#define ST_DDC_BISTCR_4_bist_mode_shift                               (0)
#define ST_DDC_BISTCR_4_bist_fail_mask                                (0x00000020)
#define ST_DDC_BISTCR_4_bist_done_mask                                (0x00000010)
#define ST_DDC_BISTCR_4_bist_rstn_mask                                (0x00000002)
#define ST_DDC_BISTCR_4_bist_mode_mask                                (0x00000001)
#define ST_DDC_BISTCR_4_bist_fail(data)                               (0x00000020&((data)<<5))
#define ST_DDC_BISTCR_4_bist_done(data)                               (0x00000010&((data)<<4))
#define ST_DDC_BISTCR_4_bist_rstn(data)                               (0x00000002&((data)<<1))
#define ST_DDC_BISTCR_4_bist_mode(data)                               (0x00000001&(data))
#define ST_DDC_BISTCR_4_get_bist_fail(data)                           ((0x00000020&(data))>>5)
#define ST_DDC_BISTCR_4_get_bist_done(data)                           ((0x00000010&(data))>>4)
#define ST_DDC_BISTCR_4_get_bist_rstn(data)                           ((0x00000002&(data))>>1)
#define ST_DDC_BISTCR_4_get_bist_mode(data)                           (0x00000001&(data))


#define ST_DDC_SCR_4                                                  0x18011e2c
#define ST_DDC_SCR_4_reg_addr                                         "0xb8011e2c"
#define ST_DDC_SCR_4_reg                                              0xb8011e2c
#define ST_DDC_SCR_4_inst_addr                                        "0x038B"
#define ST_DDC_SCR_4_inst                                             0x038B
#define ST_DDC_SCR_4_segpt_latie_shift                                (7)
#define ST_DDC_SCR_4_sgid_en_shift                                    (0)
#define ST_DDC_SCR_4_segpt_latie_mask                                 (0x00000080)
#define ST_DDC_SCR_4_sgid_en_mask                                     (0x00000001)
#define ST_DDC_SCR_4_segpt_latie(data)                                (0x00000080&((data)<<7))
#define ST_DDC_SCR_4_sgid_en(data)                                    (0x00000001&(data))
#define ST_DDC_SCR_4_get_segpt_latie(data)                            ((0x00000080&(data))>>7)
#define ST_DDC_SCR_4_get_sgid_en(data)                                (0x00000001&(data))


#define ST_DDC_SSAR_4                                                 0x18011e30
#define ST_DDC_SSAR_4_reg_addr                                        "0xb8011e30"
#define ST_DDC_SSAR_4_reg                                             0xb8011e30
#define ST_DDC_SSAR_4_inst_addr                                       "0x038C"
#define ST_DDC_SSAR_4_inst                                            0x038C
#define ST_DDC_SSAR_4_sgid_address_shift                              (1)
#define ST_DDC_SSAR_4_sgid_dtrden_shift                               (0)
#define ST_DDC_SSAR_4_sgid_address_mask                               (0x000000FE)
#define ST_DDC_SSAR_4_sgid_dtrden_mask                                (0x00000001)
#define ST_DDC_SSAR_4_sgid_address(data)                              (0x000000FE&((data)<<1))
#define ST_DDC_SSAR_4_sgid_dtrden(data)                               (0x00000001&(data))
#define ST_DDC_SSAR_4_get_sgid_address(data)                          ((0x000000FE&(data))>>1)
#define ST_DDC_SSAR_4_get_sgid_dtrden(data)                           (0x00000001&(data))


#define ST_DDC_SPR_4                                                  0x18011e34
#define ST_DDC_SPR_4_reg_addr                                         "0xb8011e34"
#define ST_DDC_SPR_4_reg                                              0xb8011e34
#define ST_DDC_SPR_4_inst_addr                                        "0x038D"
#define ST_DDC_SPR_4_inst                                             0x038D
#define ST_DDC_SPR_4_segpt_latched_shift                              (7)
#define ST_DDC_SPR_4_seg_pt_shift                                     (0)
#define ST_DDC_SPR_4_segpt_latched_mask                               (0x00000080)
#define ST_DDC_SPR_4_seg_pt_mask                                      (0x0000007F)
#define ST_DDC_SPR_4_segpt_latched(data)                              (0x00000080&((data)<<7))
#define ST_DDC_SPR_4_seg_pt(data)                                     (0x0000007F&(data))
#define ST_DDC_SPR_4_get_segpt_latched(data)                          ((0x00000080&(data))>>7)
#define ST_DDC_SPR_4_get_seg_pt(data)                                 (0x0000007F&(data))


#define ST_DDC_SFCR_4                                                 0x18011e38
#define ST_DDC_SFCR_4_reg_addr                                        "0xb8011e38"
#define ST_DDC_SFCR_4_reg                                             0xb8011e38
#define ST_DDC_SFCR_4_inst_addr                                       "0x038E"
#define ST_DDC_SFCR_4_inst                                            0x038E
#define ST_DDC_SFCR_4_special_mode_shift                              (3)
#define ST_DDC_SFCR_4_doffpt_reset_shift                              (2)
#define ST_DDC_SFCR_4_diffpt_reset_shift                              (1)
#define ST_DDC_SFCR_4_ciid_en_shift                                   (0)
#define ST_DDC_SFCR_4_special_mode_mask                               (0x00000008)
#define ST_DDC_SFCR_4_doffpt_reset_mask                               (0x00000004)
#define ST_DDC_SFCR_4_diffpt_reset_mask                               (0x00000002)
#define ST_DDC_SFCR_4_ciid_en_mask                                    (0x00000001)
#define ST_DDC_SFCR_4_special_mode(data)                              (0x00000008&((data)<<3))
#define ST_DDC_SFCR_4_doffpt_reset(data)                              (0x00000004&((data)<<2))
#define ST_DDC_SFCR_4_diffpt_reset(data)                              (0x00000002&((data)<<1))
#define ST_DDC_SFCR_4_ciid_en(data)                                   (0x00000001&(data))
#define ST_DDC_SFCR_4_get_special_mode(data)                          ((0x00000008&(data))>>3)
#define ST_DDC_SFCR_4_get_doffpt_reset(data)                          ((0x00000004&(data))>>2)
#define ST_DDC_SFCR_4_get_diffpt_reset(data)                          ((0x00000002&(data))>>1)
#define ST_DDC_SFCR_4_get_ciid_en(data)                               (0x00000001&(data))


#define ST_DDC_SFSAR_4                                                0x18011e3c
#define ST_DDC_SFSAR_4_reg_addr                                       "0xb8011e3c"
#define ST_DDC_SFSAR_4_reg                                            0xb8011e3c
#define ST_DDC_SFSAR_4_inst_addr                                      "0x038F"
#define ST_DDC_SFSAR_4_inst                                           0x038F
#define ST_DDC_SFSAR_4_ciid_address_shift                             (1)
#define ST_DDC_SFSAR_4_cirws_current_shift                            (0)
#define ST_DDC_SFSAR_4_ciid_address_mask                              (0x000000FE)
#define ST_DDC_SFSAR_4_cirws_current_mask                             (0x00000001)
#define ST_DDC_SFSAR_4_ciid_address(data)                             (0x000000FE&((data)<<1))
#define ST_DDC_SFSAR_4_cirws_current(data)                            (0x00000001&(data))
#define ST_DDC_SFSAR_4_get_ciid_address(data)                         ((0x000000FE&(data))>>1)
#define ST_DDC_SFSAR_4_get_cirws_current(data)                        (0x00000001&(data))


#define ST_DDC_SFDR_4                                                 0x18011e40
#define ST_DDC_SFDR_4_reg_addr                                        "0xb8011e40"
#define ST_DDC_SFDR_4_reg                                             0xb8011e40
#define ST_DDC_SFDR_4_inst_addr                                       "0x0390"
#define ST_DDC_SFDR_4_inst                                            0x0390
#define ST_DDC_SFDR_4_ciiddp_shift                                    (0)
#define ST_DDC_SFDR_4_ciiddp_mask                                     (0x000000FF)
#define ST_DDC_SFDR_4_ciiddp(data)                                    (0x000000FF&(data))
#define ST_DDC_SFDR_4_get_ciiddp(data)                                (0x000000FF&(data))


#define ST_DDC_SFBSR_4                                                0x18011e44
#define ST_DDC_SFBSR_4_reg_addr                                       "0xb8011e44"
#define ST_DDC_SFBSR_4_reg                                            0xb8011e44
#define ST_DDC_SFBSR_4_inst_addr                                      "0x0391"
#define ST_DDC_SFBSR_4_inst                                           0x0391
#define ST_DDC_SFBSR_4_cirws_2nd_shift                                (5)
#define ST_DDC_SFBSR_4_cirws_1st_shift                                (4)
#define ST_DDC_SFBSR_4_cippt_2nd_shift                                (3)
#define ST_DDC_SFBSR_4_cispt_2nd_shift                                (2)
#define ST_DDC_SFBSR_4_cippt_1st_shift                                (1)
#define ST_DDC_SFBSR_4_cispt_1st_shift                                (0)
#define ST_DDC_SFBSR_4_cirws_2nd_mask                                 (0x00000020)
#define ST_DDC_SFBSR_4_cirws_1st_mask                                 (0x00000010)
#define ST_DDC_SFBSR_4_cippt_2nd_mask                                 (0x00000008)
#define ST_DDC_SFBSR_4_cispt_2nd_mask                                 (0x00000004)
#define ST_DDC_SFBSR_4_cippt_1st_mask                                 (0x00000002)
#define ST_DDC_SFBSR_4_cispt_1st_mask                                 (0x00000001)
#define ST_DDC_SFBSR_4_cirws_2nd(data)                                (0x00000020&((data)<<5))
#define ST_DDC_SFBSR_4_cirws_1st(data)                                (0x00000010&((data)<<4))
#define ST_DDC_SFBSR_4_cippt_2nd(data)                                (0x00000008&((data)<<3))
#define ST_DDC_SFBSR_4_cispt_2nd(data)                                (0x00000004&((data)<<2))
#define ST_DDC_SFBSR_4_cippt_1st(data)                                (0x00000002&((data)<<1))
#define ST_DDC_SFBSR_4_cispt_1st(data)                                (0x00000001&(data))
#define ST_DDC_SFBSR_4_get_cirws_2nd(data)                            ((0x00000020&(data))>>5)
#define ST_DDC_SFBSR_4_get_cirws_1st(data)                            ((0x00000010&(data))>>4)
#define ST_DDC_SFBSR_4_get_cippt_2nd(data)                            ((0x00000008&(data))>>3)
#define ST_DDC_SFBSR_4_get_cispt_2nd(data)                            ((0x00000004&(data))>>2)
#define ST_DDC_SFBSR_4_get_cippt_1st(data)                            ((0x00000002&(data))>>1)
#define ST_DDC_SFBSR_4_get_cispt_1st(data)                            (0x00000001&(data))


#define ST_DDC_SFIBLR_4                                               0x18011e48
#define ST_DDC_SFIBLR_4_reg_addr                                      "0xb8011e48"
#define ST_DDC_SFIBLR_4_reg                                           0xb8011e48
#define ST_DDC_SFIBLR_4_inst_addr                                     "0x0392"
#define ST_DDC_SFIBLR_4_inst                                          0x0392
#define ST_DDC_SFIBLR_4_ffdi_dlen_shift                               (0)
#define ST_DDC_SFIBLR_4_ffdi_dlen_mask                                (0x0000001F)
#define ST_DDC_SFIBLR_4_ffdi_dlen(data)                               (0x0000001F&(data))
#define ST_DDC_SFIBLR_4_get_ffdi_dlen(data)                           (0x0000001F&(data))


#define ST_DDC_SFIBRWPR_4                                             0x18011e4c
#define ST_DDC_SFIBRWPR_4_reg_addr                                    "0xb8011e4c"
#define ST_DDC_SFIBRWPR_4_reg                                         0xb8011e4c
#define ST_DDC_SFIBRWPR_4_inst_addr                                   "0x0393"
#define ST_DDC_SFIBRWPR_4_inst                                        0x0393
#define ST_DDC_SFIBRWPR_4_diff_wpt_shift                              (4)
#define ST_DDC_SFIBRWPR_4_diff_rpt_shift                              (0)
#define ST_DDC_SFIBRWPR_4_diff_wpt_mask                               (0x000000F0)
#define ST_DDC_SFIBRWPR_4_diff_rpt_mask                               (0x0000000F)
#define ST_DDC_SFIBRWPR_4_diff_wpt(data)                              (0x000000F0&((data)<<4))
#define ST_DDC_SFIBRWPR_4_diff_rpt(data)                              (0x0000000F&(data))
#define ST_DDC_SFIBRWPR_4_get_diff_wpt(data)                          ((0x000000F0&(data))>>4)
#define ST_DDC_SFIBRWPR_4_get_diff_rpt(data)                          (0x0000000F&(data))


#define ST_DDC_SFIBSWPR_4                                             0x18011e50
#define ST_DDC_SFIBSWPR_4_reg_addr                                    "0xb8011e50"
#define ST_DDC_SFIBSWPR_4_reg                                         0xb8011e50
#define ST_DDC_SFIBSWPR_4_inst_addr                                   "0x0394"
#define ST_DDC_SFIBSWPR_4_inst                                        0x0394
#define ST_DDC_SFIBSWPR_4_diffstop_pt_shift                           (0)
#define ST_DDC_SFIBSWPR_4_diffstop_pt_mask                            (0x0000000F)
#define ST_DDC_SFIBSWPR_4_diffstop_pt(data)                           (0x0000000F&(data))
#define ST_DDC_SFIBSWPR_4_get_diffstop_pt(data)                       (0x0000000F&(data))


#define ST_DDC_SFOBSR_4                                               0x18011e54
#define ST_DDC_SFOBSR_4_reg_addr                                      "0xb8011e54"
#define ST_DDC_SFOBSR_4_reg                                           0xb8011e54
#define ST_DDC_SFOBSR_4_inst_addr                                     "0x0395"
#define ST_DDC_SFOBSR_4_inst                                          0x0395
#define ST_DDC_SFOBSR_4_ffdo_dlen_shift                               (0)
#define ST_DDC_SFOBSR_4_ffdo_dlen_mask                                (0x0000001F)
#define ST_DDC_SFOBSR_4_ffdo_dlen(data)                               (0x0000001F&(data))
#define ST_DDC_SFOBSR_4_get_ffdo_dlen(data)                           (0x0000001F&(data))


#define ST_DDC_SFOBRWPR_4                                             0x18011e58
#define ST_DDC_SFOBRWPR_4_reg_addr                                    "0xb8011e58"
#define ST_DDC_SFOBRWPR_4_reg                                         0xb8011e58
#define ST_DDC_SFOBRWPR_4_inst_addr                                   "0x0396"
#define ST_DDC_SFOBRWPR_4_inst                                        0x0396
#define ST_DDC_SFOBRWPR_4_doff_wpt_shift                              (4)
#define ST_DDC_SFOBRWPR_4_doff_rpt_shift                              (0)
#define ST_DDC_SFOBRWPR_4_doff_wpt_mask                               (0x000000F0)
#define ST_DDC_SFOBRWPR_4_doff_rpt_mask                               (0x0000000F)
#define ST_DDC_SFOBRWPR_4_doff_wpt(data)                              (0x000000F0&((data)<<4))
#define ST_DDC_SFOBRWPR_4_doff_rpt(data)                              (0x0000000F&(data))
#define ST_DDC_SFOBRWPR_4_get_doff_wpt(data)                          ((0x000000F0&(data))>>4)
#define ST_DDC_SFOBRWPR_4_get_doff_rpt(data)                          (0x0000000F&(data))


#define ST_DDC_SFSR_4                                                 0x18011e5c
#define ST_DDC_SFSR_4_reg_addr                                        "0xb8011e5c"
#define ST_DDC_SFSR_4_reg                                             0xb8011e5c
#define ST_DDC_SFSR_4_inst_addr                                       "0x0397"
#define ST_DDC_SFSR_4_inst                                            0x0397
#define ST_DDC_SFSR_4_ffdouf_st_shift                                 (7)
#define ST_DDC_SFSR_4_ffdiof_st_shift                                 (6)
#define ST_DDC_SFSR_4_ffdonf_st_shift                                 (5)
#define ST_DDC_SFSR_4_ffdoet_st_shift                                 (4)
#define ST_DDC_SFSR_4_ffdifu_st_shift                                 (3)
#define ST_DDC_SFSR_4_ffdine_st_shift                                 (2)
#define ST_DDC_SFSR_4_ffdouf_st_mask                                  (0x00000080)
#define ST_DDC_SFSR_4_ffdiof_st_mask                                  (0x00000040)
#define ST_DDC_SFSR_4_ffdonf_st_mask                                  (0x00000020)
#define ST_DDC_SFSR_4_ffdoet_st_mask                                  (0x00000010)
#define ST_DDC_SFSR_4_ffdifu_st_mask                                  (0x00000008)
#define ST_DDC_SFSR_4_ffdine_st_mask                                  (0x00000004)
#define ST_DDC_SFSR_4_ffdouf_st(data)                                 (0x00000080&((data)<<7))
#define ST_DDC_SFSR_4_ffdiof_st(data)                                 (0x00000040&((data)<<6))
#define ST_DDC_SFSR_4_ffdonf_st(data)                                 (0x00000020&((data)<<5))
#define ST_DDC_SFSR_4_ffdoet_st(data)                                 (0x00000010&((data)<<4))
#define ST_DDC_SFSR_4_ffdifu_st(data)                                 (0x00000008&((data)<<3))
#define ST_DDC_SFSR_4_ffdine_st(data)                                 (0x00000004&((data)<<2))
#define ST_DDC_SFSR_4_get_ffdouf_st(data)                             ((0x00000080&(data))>>7)
#define ST_DDC_SFSR_4_get_ffdiof_st(data)                             ((0x00000040&(data))>>6)
#define ST_DDC_SFSR_4_get_ffdonf_st(data)                             ((0x00000020&(data))>>5)
#define ST_DDC_SFSR_4_get_ffdoet_st(data)                             ((0x00000010&(data))>>4)
#define ST_DDC_SFSR_4_get_ffdifu_st(data)                             ((0x00000008&(data))>>3)
#define ST_DDC_SFSR_4_get_ffdine_st(data)                             ((0x00000004&(data))>>2)


#define ST_DDC_SFIR_4                                                 0x18011e60
#define ST_DDC_SFIR_4_reg_addr                                        "0xb8011e60"
#define ST_DDC_SFIR_4_reg                                             0xb8011e60
#define ST_DDC_SFIR_4_inst_addr                                       "0x0398"
#define ST_DDC_SFIR_4_inst                                            0x0398
#define ST_DDC_SFIR_4_ffdouf_ie_shift                                 (7)
#define ST_DDC_SFIR_4_ffdiof_ie_shift                                 (6)
#define ST_DDC_SFIR_4_ffdonf_ie_shift                                 (5)
#define ST_DDC_SFIR_4_ffdoet_ie_shift                                 (4)
#define ST_DDC_SFIR_4_ffdifu_ie_shift                                 (3)
#define ST_DDC_SFIR_4_ffdine_ie_shift                                 (2)
#define ST_DDC_SFIR_4_cippt_ie_shift                                  (1)
#define ST_DDC_SFIR_4_cispt_ie_shift                                  (0)
#define ST_DDC_SFIR_4_ffdouf_ie_mask                                  (0x00000080)
#define ST_DDC_SFIR_4_ffdiof_ie_mask                                  (0x00000040)
#define ST_DDC_SFIR_4_ffdonf_ie_mask                                  (0x00000020)
#define ST_DDC_SFIR_4_ffdoet_ie_mask                                  (0x00000010)
#define ST_DDC_SFIR_4_ffdifu_ie_mask                                  (0x00000008)
#define ST_DDC_SFIR_4_ffdine_ie_mask                                  (0x00000004)
#define ST_DDC_SFIR_4_cippt_ie_mask                                   (0x00000002)
#define ST_DDC_SFIR_4_cispt_ie_mask                                   (0x00000001)
#define ST_DDC_SFIR_4_ffdouf_ie(data)                                 (0x00000080&((data)<<7))
#define ST_DDC_SFIR_4_ffdiof_ie(data)                                 (0x00000040&((data)<<6))
#define ST_DDC_SFIR_4_ffdonf_ie(data)                                 (0x00000020&((data)<<5))
#define ST_DDC_SFIR_4_ffdoet_ie(data)                                 (0x00000010&((data)<<4))
#define ST_DDC_SFIR_4_ffdifu_ie(data)                                 (0x00000008&((data)<<3))
#define ST_DDC_SFIR_4_ffdine_ie(data)                                 (0x00000004&((data)<<2))
#define ST_DDC_SFIR_4_cippt_ie(data)                                  (0x00000002&((data)<<1))
#define ST_DDC_SFIR_4_cispt_ie(data)                                  (0x00000001&(data))
#define ST_DDC_SFIR_4_get_ffdouf_ie(data)                             ((0x00000080&(data))>>7)
#define ST_DDC_SFIR_4_get_ffdiof_ie(data)                             ((0x00000040&(data))>>6)
#define ST_DDC_SFIR_4_get_ffdonf_ie(data)                             ((0x00000020&(data))>>5)
#define ST_DDC_SFIR_4_get_ffdoet_ie(data)                             ((0x00000010&(data))>>4)
#define ST_DDC_SFIR_4_get_ffdifu_ie(data)                             ((0x00000008&(data))>>3)
#define ST_DDC_SFIR_4_get_ffdine_ie(data)                             ((0x00000004&(data))>>2)
#define ST_DDC_SFIR_4_get_cippt_ie(data)                              ((0x00000002&(data))>>1)
#define ST_DDC_SFIR_4_get_cispt_ie(data)                              (0x00000001&(data))


#define ST_DDC_FSMS_4                                                 0x18011e64
#define ST_DDC_FSMS_4_reg_addr                                        "0xb8011e64"
#define ST_DDC_FSMS_4_reg                                             0xb8011e64
#define ST_DDC_FSMS_4_inst_addr                                       "0x0399"
#define ST_DDC_FSMS_4_inst                                            0x0399
#define ST_DDC_FSMS_4_cmdfsm_st_shift                                 (0)
#define ST_DDC_FSMS_4_cmdfsm_st_mask                                  (0x000000FF)
#define ST_DDC_FSMS_4_cmdfsm_st(data)                                 (0x000000FF&(data))
#define ST_DDC_FSMS_4_get_cmdfsm_st(data)                             (0x000000FF&(data))


#define MIS_RTCSEC                                                    0x18011f00
#define MIS_RTCSEC_reg_addr                                           "0xb8011f00"
#define MIS_RTCSEC_reg                                                0xb8011f00
#define MIS_RTCSEC_inst_addr                                          "0x03C0"
#define MIS_RTCSEC_inst                                               0x03C0
#define MIS_RTCSEC_rtcsec_shift                                       (0)
#define MIS_RTCSEC_rtcsec_mask                                        (0x0000007F)
#define MIS_RTCSEC_rtcsec(data)                                       (0x0000007F&(data))
#define MIS_RTCSEC_get_rtcsec(data)                                   (0x0000007F&(data))


#define MIS_RTCMIN                                                    0x18011f04
#define MIS_RTCMIN_reg_addr                                           "0xb8011f04"
#define MIS_RTCMIN_reg                                                0xb8011f04
#define MIS_RTCMIN_inst_addr                                          "0x03C1"
#define MIS_RTCMIN_inst                                               0x03C1
#define MIS_RTCMIN_rtcmin_shift                                       (0)
#define MIS_RTCMIN_rtcmin_mask                                        (0x0000003F)
#define MIS_RTCMIN_rtcmin(data)                                       (0x0000003F&(data))
#define MIS_RTCMIN_get_rtcmin(data)                                   (0x0000003F&(data))


#define MIS_RTCHR                                                     0x18011f08
#define MIS_RTCHR_reg_addr                                            "0xb8011f08"
#define MIS_RTCHR_reg                                                 0xb8011f08
#define MIS_RTCHR_inst_addr                                           "0x03C2"
#define MIS_RTCHR_inst                                                0x03C2
#define MIS_RTCHR_rtchr_shift                                         (0)
#define MIS_RTCHR_rtchr_mask                                          (0x0000001F)
#define MIS_RTCHR_rtchr(data)                                         (0x0000001F&(data))
#define MIS_RTCHR_get_rtchr(data)                                     (0x0000001F&(data))


#define MIS_RTCDATE1                                                  0x18011f0c
#define MIS_RTCDATE1_reg_addr                                         "0xb8011f0c"
#define MIS_RTCDATE1_reg                                              0xb8011f0c
#define MIS_RTCDATE1_inst_addr                                        "0x03C3"
#define MIS_RTCDATE1_inst                                             0x03C3
#define MIS_RTCDATE1_rtcdate1_shift                                   (0)
#define MIS_RTCDATE1_rtcdate1_mask                                    (0x000000FF)
#define MIS_RTCDATE1_rtcdate1(data)                                   (0x000000FF&(data))
#define MIS_RTCDATE1_get_rtcdate1(data)                               (0x000000FF&(data))


#define MIS_RTCDATE2                                                  0x18011f10
#define MIS_RTCDATE2_reg_addr                                         "0xb8011f10"
#define MIS_RTCDATE2_reg                                              0xb8011f10
#define MIS_RTCDATE2_inst_addr                                        "0x03C4"
#define MIS_RTCDATE2_inst                                             0x03C4
#define MIS_RTCDATE2_rtcdate2_shift                                   (0)
#define MIS_RTCDATE2_rtcdate2_mask                                    (0x0000003F)
#define MIS_RTCDATE2_rtcdate2(data)                                   (0x0000003F&(data))
#define MIS_RTCDATE2_get_rtcdate2(data)                               (0x0000003F&(data))


#define MIS_ALMMIN                                                    0x18011f14
#define MIS_ALMMIN_reg_addr                                           "0xb8011f14"
#define MIS_ALMMIN_reg                                                0xb8011f14
#define MIS_ALMMIN_inst_addr                                          "0x03C5"
#define MIS_ALMMIN_inst                                               0x03C5
#define MIS_ALMMIN_almmin_shift                                       (0)
#define MIS_ALMMIN_almmin_mask                                        (0x0000003F)
#define MIS_ALMMIN_almmin(data)                                       (0x0000003F&(data))
#define MIS_ALMMIN_get_almmin(data)                                   (0x0000003F&(data))


#define MIS_ALMHR                                                     0x18011f18
#define MIS_ALMHR_reg_addr                                            "0xb8011f18"
#define MIS_ALMHR_reg                                                 0xb8011f18
#define MIS_ALMHR_inst_addr                                           "0x03C6"
#define MIS_ALMHR_inst                                                0x03C6
#define MIS_ALMHR_almhr_shift                                         (0)
#define MIS_ALMHR_almhr_mask                                          (0x0000001F)
#define MIS_ALMHR_almhr(data)                                         (0x0000001F&(data))
#define MIS_ALMHR_get_almhr(data)                                     (0x0000001F&(data))


#define MIS_ALMDATE1                                                  0x18011f1c
#define MIS_ALMDATE1_reg_addr                                         "0xb8011f1c"
#define MIS_ALMDATE1_reg                                              0xb8011f1c
#define MIS_ALMDATE1_inst_addr                                        "0x03C7"
#define MIS_ALMDATE1_inst                                             0x03C7
#define MIS_ALMDATE1_almdate1_shift                                   (0)
#define MIS_ALMDATE1_almdate1_mask                                    (0x000000FF)
#define MIS_ALMDATE1_almdate1(data)                                   (0x000000FF&(data))
#define MIS_ALMDATE1_get_almdate1(data)                               (0x000000FF&(data))


#define MIS_ALMDATE2                                                  0x18011f20
#define MIS_ALMDATE2_reg_addr                                         "0xb8011f20"
#define MIS_ALMDATE2_reg                                              0xb8011f20
#define MIS_ALMDATE2_inst_addr                                        "0x03C8"
#define MIS_ALMDATE2_inst                                             0x03C8
#define MIS_ALMDATE2_almdate2_shift                                   (0)
#define MIS_ALMDATE2_almdate2_mask                                    (0x0000003F)
#define MIS_ALMDATE2_almdate2(data)                                   (0x0000003F&(data))
#define MIS_ALMDATE2_get_almdate2(data)                               (0x0000003F&(data))


#define MIS_RTCSTOP                                                   0x18011f24
#define MIS_RTCSTOP_reg_addr                                          "0xb8011f24"
#define MIS_RTCSTOP_reg                                               0xb8011f24
#define MIS_RTCSTOP_inst_addr                                         "0x03C9"
#define MIS_RTCSTOP_inst                                              0x03C9
#define MIS_RTCSTOP_vref_shift                                        (1)
#define MIS_RTCSTOP_rtcstop_shift                                     (0)
#define MIS_RTCSTOP_vref_mask                                         (0x00000006)
#define MIS_RTCSTOP_rtcstop_mask                                      (0x00000001)
#define MIS_RTCSTOP_vref(data)                                        (0x00000006&((data)<<1))
#define MIS_RTCSTOP_rtcstop(data)                                     (0x00000001&(data))
#define MIS_RTCSTOP_get_vref(data)                                    ((0x00000006&(data))>>1)
#define MIS_RTCSTOP_get_rtcstop(data)                                 (0x00000001&(data))


#define MIS_RTCACR                                                    0x18011f28
#define MIS_RTCACR_reg_addr                                           "0xb8011f28"
#define MIS_RTCACR_reg                                                0xb8011f28
#define MIS_RTCACR_inst_addr                                          "0x03CA"
#define MIS_RTCACR_inst                                               0x03CA
#define MIS_RTCACR_rtcpwr_shift                                       (7)
#define MIS_RTCACR_co_shift                                           (5)
#define MIS_RTCACR_ct_shift                                           (3)
#define MIS_RTCACR_clksel_shift                                       (2)
#define MIS_RTCACR_bc_shift                                           (0)
#define MIS_RTCACR_rtcpwr_mask                                        (0x00000080)
#define MIS_RTCACR_co_mask                                            (0x00000060)
#define MIS_RTCACR_ct_mask                                            (0x00000018)
#define MIS_RTCACR_clksel_mask                                        (0x00000004)
#define MIS_RTCACR_bc_mask                                            (0x00000003)
#define MIS_RTCACR_rtcpwr(data)                                       (0x00000080&((data)<<7))
#define MIS_RTCACR_co(data)                                           (0x00000060&((data)<<5))
#define MIS_RTCACR_ct(data)                                           (0x00000018&((data)<<3))
#define MIS_RTCACR_clksel(data)                                       (0x00000004&((data)<<2))
#define MIS_RTCACR_bc(data)                                           (0x00000003&(data))
#define MIS_RTCACR_get_rtcpwr(data)                                   ((0x00000080&(data))>>7)
#define MIS_RTCACR_get_co(data)                                       ((0x00000060&(data))>>5)
#define MIS_RTCACR_get_ct(data)                                       ((0x00000018&(data))>>3)
#define MIS_RTCACR_get_clksel(data)                                   ((0x00000004&(data))>>2)
#define MIS_RTCACR_get_bc(data)                                       (0x00000003&(data))


#define MIS_RTCEN                                                     0x18011f2c
#define MIS_RTCEN_reg_addr                                            "0xb8011f2c"
#define MIS_RTCEN_reg                                                 0xb8011f2c
#define MIS_RTCEN_inst_addr                                           "0x03CB"
#define MIS_RTCEN_inst                                                0x03CB
#define MIS_RTCEN_rtcen_shift                                         (0)
#define MIS_RTCEN_rtcen_mask                                          (0x000000FF)
#define MIS_RTCEN_rtcen(data)                                         (0x000000FF&(data))
#define MIS_RTCEN_get_rtcen(data)                                     (0x000000FF&(data))


#define MIS_RTCCR                                                     0x18011f30
#define MIS_RTCCR_reg_addr                                            "0xb8011f30"
#define MIS_RTCCR_reg                                                 0xb8011f30
#define MIS_RTCCR_inst_addr                                           "0x03CC"
#define MIS_RTCCR_inst                                                0x03CC
#define MIS_RTCCR_rtc_alarm_int_shift                                 (31)
#define MIS_RTCCR_rtc_date_int_shift                                  (30)
#define MIS_RTCCR_rtc_hour_int_shift                                  (29)
#define MIS_RTCCR_rtc_min_int_shift                                   (28)
#define MIS_RTCCR_rtc_hsec_int_shift                                  (27)
#define MIS_RTCCR_rtcrst_shift                                        (6)
#define MIS_RTCCR_almen_shift                                         (4)
#define MIS_RTCCR_dainte_shift                                        (3)
#define MIS_RTCCR_huinte_shift                                        (2)
#define MIS_RTCCR_muinte_shift                                        (1)
#define MIS_RTCCR_hsuinte_shift                                       (0)
#define MIS_RTCCR_rtc_alarm_int_mask                                  (0x80000000)
#define MIS_RTCCR_rtc_date_int_mask                                   (0x40000000)
#define MIS_RTCCR_rtc_hour_int_mask                                   (0x20000000)
#define MIS_RTCCR_rtc_min_int_mask                                    (0x10000000)
#define MIS_RTCCR_rtc_hsec_int_mask                                   (0x08000000)
#define MIS_RTCCR_rtcrst_mask                                         (0x00000040)
#define MIS_RTCCR_almen_mask                                          (0x00000010)
#define MIS_RTCCR_dainte_mask                                         (0x00000008)
#define MIS_RTCCR_huinte_mask                                         (0x00000004)
#define MIS_RTCCR_muinte_mask                                         (0x00000002)
#define MIS_RTCCR_hsuinte_mask                                        (0x00000001)
#define MIS_RTCCR_rtc_alarm_int(data)                                 (0x80000000&((data)<<31))
#define MIS_RTCCR_rtc_date_int(data)                                  (0x40000000&((data)<<30))
#define MIS_RTCCR_rtc_hour_int(data)                                  (0x20000000&((data)<<29))
#define MIS_RTCCR_rtc_min_int(data)                                   (0x10000000&((data)<<28))
#define MIS_RTCCR_rtc_hsec_int(data)                                  (0x08000000&((data)<<27))
#define MIS_RTCCR_rtcrst(data)                                        (0x00000040&((data)<<6))
#define MIS_RTCCR_almen(data)                                         (0x00000010&((data)<<4))
#define MIS_RTCCR_dainte(data)                                        (0x00000008&((data)<<3))
#define MIS_RTCCR_huinte(data)                                        (0x00000004&((data)<<2))
#define MIS_RTCCR_muinte(data)                                        (0x00000002&((data)<<1))
#define MIS_RTCCR_hsuinte(data)                                       (0x00000001&(data))
#define MIS_RTCCR_get_rtc_alarm_int(data)                             ((0x80000000&(data))>>31)
#define MIS_RTCCR_get_rtc_date_int(data)                              ((0x40000000&(data))>>30)
#define MIS_RTCCR_get_rtc_hour_int(data)                              ((0x20000000&(data))>>29)
#define MIS_RTCCR_get_rtc_min_int(data)                               ((0x10000000&(data))>>28)
#define MIS_RTCCR_get_rtc_hsec_int(data)                              ((0x08000000&(data))>>27)
#define MIS_RTCCR_get_rtcrst(data)                                    ((0x00000040&(data))>>6)
#define MIS_RTCCR_get_almen(data)                                     ((0x00000010&(data))>>4)
#define MIS_RTCCR_get_dainte(data)                                    ((0x00000008&(data))>>3)
#define MIS_RTCCR_get_huinte(data)                                    ((0x00000004&(data))>>2)
#define MIS_RTCCR_get_muinte(data)                                    ((0x00000002&(data))>>1)
#define MIS_RTCCR_get_hsuinte(data)                                   (0x00000001&(data))
#endif
