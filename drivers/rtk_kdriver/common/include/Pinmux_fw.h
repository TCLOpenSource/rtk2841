// This file is generated using the spec version 1.39, firmware template version 1.39and SRIF Parser                                                                                source code SVN rev:734                    Version flow no.:1.0.185
#ifndef _PINMUX_REG_H_INCLUDED_
#define _PINMUX_REG_H_INCLUDED_

//#define  _PINMUX_USE_STRUCT
#ifdef _PINMUX_USE_STRUCT

typedef struct
{
    unsigned int    pa7_ps:4;
    unsigned int    reserved_0:4;
    unsigned int    pa6_ps:4;
    unsigned int    reserved_1:4;
    unsigned int    pa5_ps:4;
    unsigned int    reserved_2:4;
    unsigned int    pa4_ps:4;
    unsigned int    reserved_3:4;
}PA_cfg0;

typedef struct
{
    unsigned int    pa3_ps:4;
    unsigned int    reserved_0:4;
    unsigned int    pa2_ps:4;
    unsigned int    reserved_1:4;
    unsigned int    pa1_ps:4;
    unsigned int    reserved_2:4;
    unsigned int    pa0_ps:4;
    unsigned int    reserved_3:4;
}PA_cfg1;

typedef struct
{
    unsigned int    pb7_ps:4;
    unsigned int    reserved_0:4;
    unsigned int    pb6_ps:4;
    unsigned int    reserved_1:4;
    unsigned int    pb5_ps:4;
    unsigned int    reserved_2:4;
    unsigned int    pb4_ps:4;
    unsigned int    reserved_3:4;
}PB_cfg0;

typedef struct
{
    unsigned int    pb3_ps:4;
    unsigned int    reserved_0:4;
    unsigned int    pb2_ps:4;
    unsigned int    reserved_1:4;
    unsigned int    pb1_ps:4;
    unsigned int    reserved_2:4;
    unsigned int    pb0_ps:4;
    unsigned int    reserved_3:4;
}PB_cfg1;

typedef struct
{
    unsigned int    pc7_ps:4;
    unsigned int    reserved_0:4;
    unsigned int    pc6_ps:4;
    unsigned int    reserved_1:4;
    unsigned int    pc5_ps:4;
    unsigned int    reserved_2:4;
    unsigned int    pc4_ps:4;
    unsigned int    reserved_3:4;
}PC_cfg0;

typedef struct
{
    unsigned int    pc3_ps:4;
    unsigned int    reserved_0:4;
    unsigned int    pc2_ps:4;
    unsigned int    reserved_1:4;
    unsigned int    pc1_ps:4;
    unsigned int    reserved_2:4;
    unsigned int    pc0_ps:4;
    unsigned int    reserved_3:4;
}PC_cfg1;

typedef struct
{
    unsigned int    pd7_ps:4;
    unsigned int    reserved_0:4;
    unsigned int    pd6_ps:4;
    unsigned int    reserved_1:4;
    unsigned int    pd5_ps:4;
    unsigned int    reserved_2:4;
    unsigned int    pd4_ps:4;
    unsigned int    reserved_3:4;
}PD_cfg0;

typedef struct
{
    unsigned int    pd3_ps:4;
    unsigned int    pd3_pd:1;
    unsigned int    pd3_pu:1;
    unsigned int    pd3_sr:1;
    unsigned int    pd3_ds:1;
    unsigned int    pd2_ps:4;
    unsigned int    pd2_pd:1;
    unsigned int    pd2_pu:1;
    unsigned int    pd2_sr:1;
    unsigned int    pd2_ds:1;
    unsigned int    pd1_ps:4;
    unsigned int    pd1_pd:1;
    unsigned int    pd1_pu:1;
    unsigned int    pd1_sr:1;
    unsigned int    pd1_ds:1;
    unsigned int    pd0_ps:4;
    unsigned int    pd0_pd:1;
    unsigned int    pd0_pu:1;
    unsigned int    pd0_sr:1;
    unsigned int    pd0_ds:1;
}PD_cfg1;

typedef struct
{
    unsigned int    pe7_ps:4;
    unsigned int    reserved_0:4;
    unsigned int    pe6_ps:4;
    unsigned int    reserved_1:4;
    unsigned int    pe5_ps:4;
    unsigned int    reserved_2:4;
    unsigned int    pe4_ps:4;
    unsigned int    reserved_3:4;
}PE_cfg0;

typedef struct
{
    unsigned int    pe3_ps:4;
    unsigned int    reserved_0:4;
    unsigned int    pe2_ps:4;
    unsigned int    pe2_pd:1;
    unsigned int    pe2_pu:1;
    unsigned int    pe2_sr:1;
    unsigned int    pe2_ds:1;
    unsigned int    pe1_ps:4;
    unsigned int    pe1_pd:1;
    unsigned int    pe1_pu:1;
    unsigned int    pe1_sr:1;
    unsigned int    pe1_ds:1;
    unsigned int    pe0_ps:4;
    unsigned int    pe0_pd:1;
    unsigned int    pe0_pu:1;
    unsigned int    pe0_sr:1;
    unsigned int    pe0_ds:1;
}PE_cfg1;

typedef struct
{
    unsigned int    pf7_ps:4;
    unsigned int    reserved_0:4;
    unsigned int    pf6_ps:4;
    unsigned int    reserved_1:4;
    unsigned int    pf5_ps:4;
    unsigned int    reserved_2:4;
    unsigned int    pf4_ps:4;
    unsigned int    reserved_3:4;
}PF_cfg0;

typedef struct
{
    unsigned int    pf3_ps:4;
    unsigned int    reserved_0:4;
    unsigned int    pf2_ps:4;
    unsigned int    reserved_1:4;
    unsigned int    pf1_ps:4;
    unsigned int    reserved_2:12;
}PF_cfg1;

typedef struct
{
    unsigned int    pg7_ps:4;
    unsigned int    pg7_pd:1;
    unsigned int    pg7_pu:1;
    unsigned int    pg7_sr:1;
    unsigned int    pg7_ds:1;
    unsigned int    pg6_ps:4;
    unsigned int    pg6_pd:1;
    unsigned int    pg6_pu:1;
    unsigned int    pg6_sr:1;
    unsigned int    pg6_ds:1;
    unsigned int    pg5_ps:4;
    unsigned int    pg5_pd:1;
    unsigned int    pg5_pu:1;
    unsigned int    pg5_sr:1;
    unsigned int    pg5_ds:1;
    unsigned int    pg4_ps:4;
    unsigned int    pg4_pd:1;
    unsigned int    pg4_pu:1;
    unsigned int    pg4_sr:1;
    unsigned int    pg4_ds:1;
}PG_cfg0;

typedef struct
{
    unsigned int    pg3_ps:4;
    unsigned int    pg3_pd:1;
    unsigned int    pg3_pu:1;
    unsigned int    pg3_sr:1;
    unsigned int    pg3_ds:1;
    unsigned int    pg2_ps:4;
    unsigned int    pg2_pd:1;
    unsigned int    pg2_pu:1;
    unsigned int    pg2_sr:1;
    unsigned int    pg2_ds:1;
    unsigned int    pg1_ps:4;
    unsigned int    pg1_pd:1;
    unsigned int    pg1_pu:1;
    unsigned int    pg1_sr:1;
    unsigned int    pg1_ds:1;
    unsigned int    pg0_ps:4;
    unsigned int    pg0_pd:1;
    unsigned int    pg0_pu:1;
    unsigned int    pg0_sr:1;
    unsigned int    pg0_ds:1;
}PG_cfg1;

typedef struct
{
    unsigned int    ph7_ps:4;
    unsigned int    ph7_pd:1;
    unsigned int    ph7_pu:1;
    unsigned int    ph7_sr:1;
    unsigned int    ph7_ds:1;
    unsigned int    ph6_ps:4;
    unsigned int    ph6_pd:1;
    unsigned int    ph6_pu:1;
    unsigned int    ph6_sr:1;
    unsigned int    ph6_ds:1;
    unsigned int    ph5_ps:4;
    unsigned int    ph5_pd:1;
    unsigned int    ph5_pu:1;
    unsigned int    ph5_sr:1;
    unsigned int    ph5_ds:1;
    unsigned int    ph4_ps:4;
    unsigned int    ph4_pd:1;
    unsigned int    ph4_pu:1;
    unsigned int    ph4_sr:1;
    unsigned int    ph4_ds:1;
}PH_cfg0;

typedef struct
{
    unsigned int    ph3_ps:4;
    unsigned int    ph3_pd:1;
    unsigned int    ph3_pu:1;
    unsigned int    ph3_sr:1;
    unsigned int    ph3_ds:1;
    unsigned int    ph2_ps:4;
    unsigned int    ph2_pd:1;
    unsigned int    ph2_pu:1;
    unsigned int    ph2_sr:1;
    unsigned int    ph2_ds:1;
    unsigned int    ph1_ps:4;
    unsigned int    ph1_pd:1;
    unsigned int    ph1_pu:1;
    unsigned int    ph1_sr:1;
    unsigned int    ph1_ds:1;
    unsigned int    ph0_ps:4;
    unsigned int    ph0_pd:1;
    unsigned int    ph0_pu:1;
    unsigned int    ph0_sr:1;
    unsigned int    ph0_ds:1;
}PH_cfg1;

typedef struct
{
    unsigned int    pi7_ps:4;
    unsigned int    pi7_pd:1;
    unsigned int    pi7_pu:1;
    unsigned int    pi7_sr:1;
    unsigned int    pi7_ds:1;
    unsigned int    pi6_ps:4;
    unsigned int    pi6_pd:1;
    unsigned int    pi6_pu:1;
    unsigned int    pi6_sr:1;
    unsigned int    pi6_ds:1;
    unsigned int    pi5_ps:4;
    unsigned int    pi5_pd:1;
    unsigned int    pi5_pu:1;
    unsigned int    pi5_sr:1;
    unsigned int    pi5_ds:1;
    unsigned int    pi4_ps:4;
    unsigned int    pi4_pd:1;
    unsigned int    pi4_pu:1;
    unsigned int    pi4_sr:1;
    unsigned int    pi4_ds:1;
}PI_cfg0;

typedef struct
{
    unsigned int    pi3_ps:4;
    unsigned int    pi3_pd:1;
    unsigned int    pi3_pu:1;
    unsigned int    pi3_sr:1;
    unsigned int    pi3_ds:1;
    unsigned int    pi2_ps:4;
    unsigned int    pi2_pd:1;
    unsigned int    pi2_pu:1;
    unsigned int    pi2_sr:1;
    unsigned int    pi2_ds:1;
    unsigned int    pi1_ps:4;
    unsigned int    pi1_pd:1;
    unsigned int    pi1_pu:1;
    unsigned int    pi1_sr:1;
    unsigned int    pi1_ds:1;
    unsigned int    pi0_ps_dummy:8;
}PI_cfg1;

typedef struct
{
    unsigned int    pj7_ps:4;
    unsigned int    pj7_pd:1;
    unsigned int    pj7_pu:1;
    unsigned int    pj7_sr:1;
    unsigned int    pj7_ds:1;
    unsigned int    pj6_ps:4;
    unsigned int    pj6_pd:1;
    unsigned int    pj6_pu:1;
    unsigned int    pj6_sr:1;
    unsigned int    pj6_ds:1;
    unsigned int    pj5_ps:4;
    unsigned int    pj5_pd:1;
    unsigned int    pj5_pu:1;
    unsigned int    pj5_sr:1;
    unsigned int    pj5_ds:1;
    unsigned int    pj4_ps:4;
    unsigned int    pj4_pd:1;
    unsigned int    pj4_pu:1;
    unsigned int    pj4_sr:1;
    unsigned int    pj4_ds:1;
}PJ_cfg0;

typedef struct
{
    unsigned int    pj3_ps:4;
    unsigned int    pj3_pd:1;
    unsigned int    pj3_pu:1;
    unsigned int    pj3_sr:1;
    unsigned int    pj3_ds:1;
    unsigned int    pj2_ps:4;
    unsigned int    pj2_pd:1;
    unsigned int    pj2_pu:1;
    unsigned int    pj2_sr:1;
    unsigned int    pj2_ds:1;
    unsigned int    pj1_ps:4;
    unsigned int    pj1_pd:1;
    unsigned int    pj1_pu:1;
    unsigned int    pj1_sr:1;
    unsigned int    pj1_ds:1;
    unsigned int    pj0_ps:4;
    unsigned int    pj0_pd:1;
    unsigned int    pj0_pu:1;
    unsigned int    pj0_sr:1;
    unsigned int    pj0_ds:1;
}PJ_cfg1;

typedef struct
{
    unsigned int    pk7_ps:4;
    unsigned int    pk7_pd:1;
    unsigned int    pk7_pu:1;
    unsigned int    pk7_sr:1;
    unsigned int    pk7_ds:1;
    unsigned int    pk6_ps:4;
    unsigned int    pk6_pd:1;
    unsigned int    pk6_pu:1;
    unsigned int    pk6_sr:1;
    unsigned int    pk6_ds:1;
    unsigned int    pk5_ps:4;
    unsigned int    pk5_pd:1;
    unsigned int    pk5_pu:1;
    unsigned int    pk5_sr:1;
    unsigned int    pk5_ds:1;
    unsigned int    pk4_ps:4;
    unsigned int    pk4_pd:1;
    unsigned int    pk4_pu:1;
    unsigned int    pk4_sr:1;
    unsigned int    pk4_ds:1;
}PK_cfg0;

typedef struct
{
    unsigned int    pk3_ps:4;
    unsigned int    pk3_pd:1;
    unsigned int    pk3_pu:1;
    unsigned int    pk3_sr:1;
    unsigned int    pk3_ds:1;
    unsigned int    pk2_ps:4;
    unsigned int    pk2_pd:1;
    unsigned int    pk2_pu:1;
    unsigned int    pk2_sr:1;
    unsigned int    pk2_ds:1;
    unsigned int    pk1_ps:4;
    unsigned int    pk1_pd:1;
    unsigned int    pk1_pu:1;
    unsigned int    pk1_sr:1;
    unsigned int    pk1_ds:1;
    unsigned int    pk0_ps:4;
    unsigned int    pk0_pd:1;
    unsigned int    pk0_pu:1;
    unsigned int    pk0_sr:1;
    unsigned int    pk0_ds:1;
}PK_cfg1;

typedef struct
{
    unsigned int    pl7_ps:4;
    unsigned int    pl7_pd:1;
    unsigned int    pl7_pu:1;
    unsigned int    pl7_sr:1;
    unsigned int    pl7_ds:1;
    unsigned int    pl6_ps:4;
    unsigned int    pl6_pd:1;
    unsigned int    pl6_pu:1;
    unsigned int    pl6_sr:1;
    unsigned int    pl6_ds:1;
    unsigned int    pl5_ps:4;
    unsigned int    pl5_pd:1;
    unsigned int    pl5_pu:1;
    unsigned int    pl5_sr:1;
    unsigned int    pl5_ds:1;
    unsigned int    pl4_ps:4;
    unsigned int    pl4_pd:1;
    unsigned int    pl4_pu:1;
    unsigned int    pl4_sr:1;
    unsigned int    pl4_ds:1;
}PL_cfg0;

typedef struct
{
    unsigned int    pl3_ps:4;
    unsigned int    pl3_pd:1;
    unsigned int    pl3_pu:1;
    unsigned int    pl3_sr:1;
    unsigned int    pl3_ds:1;
    unsigned int    pl2_ps:4;
    unsigned int    pl2_pd:1;
    unsigned int    pl2_pu:1;
    unsigned int    pl2_sr:1;
    unsigned int    pl2_ds:1;
    unsigned int    pl1_ps:4;
    unsigned int    pl1_pd:1;
    unsigned int    pl1_pu:1;
    unsigned int    pl1_sr:1;
    unsigned int    pl1_ds:1;
    unsigned int    pl0_ps:4;
    unsigned int    pl0_pd:1;
    unsigned int    pl0_pu:1;
    unsigned int    pl0_sr:1;
    unsigned int    pl0_ds:1;
}PL_cfg1;

typedef struct
{
    unsigned int    pm7_ps_dummy:32;
}PM_cfg0;

typedef struct
{
    unsigned int    reserved_0:32;
}PM_cfg1;

typedef struct
{
    unsigned int    reserved_0:32;
}PN_cfg0;

typedef struct
{
    unsigned int    reserved_0:32;
}PN_cfg1;

typedef struct
{
    unsigned int    reserved_0:32;
}PO_cfg0;

typedef struct
{
    unsigned int    reserved_0:32;
}PO_cfg1;

typedef struct
{
    unsigned int    reserved_0:32;
}PP_cfg0;

typedef struct
{
    unsigned int    reserved_0:32;
}PP_cfg1;

typedef struct
{
    unsigned int    reserved_0:32;
}PQ_cfg0;

typedef struct
{
    unsigned int    reserved_0:32;
}PQ_cfg1;

typedef struct
{
    unsigned int    reserved_0:32;
}PS_cfg0;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    ps0_ds:1;
}PS_cfg1;

typedef struct
{
    unsigned int    reserved_0:32;
}PT_cfg0;

typedef struct
{
    unsigned int    reserved_0:32;
}PT_cfg1;

typedef struct
{
    unsigned int    reserved_0:32;
}PU_cfg0;

typedef struct
{
    unsigned int    reserved_0:32;
}PU_cfg1;

typedef struct
{
    unsigned int    reserved_0:32;
}PV_cfg0;

typedef struct
{
    unsigned int    reserved_0:32;
}PV_cfg1;

typedef struct
{
    unsigned int    reserved_0:32;
}PW_cfg0;

typedef struct
{
    unsigned int    reserved_0:32;
}PW_cfg1;

typedef struct
{
    unsigned int    px7_ps:4;
    unsigned int    px7_pd:1;
    unsigned int    px7_pu:1;
    unsigned int    px7_sr:1;
    unsigned int    px7_ds:1;
    unsigned int    px6_pd:1;
    unsigned int    px6_pu:1;
    unsigned int    px6_sr:1;
    unsigned int    px6_ds:1;
    unsigned int    px5_pd:1;
    unsigned int    px5_pu:1;
    unsigned int    px5_sr:1;
    unsigned int    px5_ds:1;
    unsigned int    px4_pd:1;
    unsigned int    px4_pu:1;
    unsigned int    px4_sr:1;
    unsigned int    px4_ds:1;
    unsigned int    px3_pd:1;
    unsigned int    px3_pu:1;
    unsigned int    px3_sr:1;
    unsigned int    px3_ds:1;
    unsigned int    px2_pd:1;
    unsigned int    px2_pu:1;
    unsigned int    px2_sr:1;
    unsigned int    px2_ds:1;
    unsigned int    px1_pd:1;
    unsigned int    px1_pu:1;
    unsigned int    px1_sr:1;
    unsigned int    px1_ds:1;
}PX_cfg0;

typedef struct
{
    unsigned int    px0_pd:1;
    unsigned int    px0_pu:1;
    unsigned int    px0_sr:1;
    unsigned int    px0_ds:1;
    unsigned int    reserved_0:1;
    unsigned int    avs0_pd1_ps:3;
    unsigned int    avs0_pd1_pd:1;
    unsigned int    avs0_pd1_pu:1;
    unsigned int    avs0_pd1_sr:1;
    unsigned int    avs0_pd1_ds:1;
    unsigned int    reserved_1:11;
    unsigned int    reserved_2:1;
    unsigned int    lvdspll_wll:1;
    unsigned int    reserved_3:3;
    unsigned int    boption_status:4;
}PXY_cfg1;

typedef struct
{
    unsigned int    v10_sel:1;
    unsigned int    usb_host_ctrl_sel:1;
    unsigned int    i2c_m_sel:1;
    unsigned int    i2c_s_sel:1;
    unsigned int    i2c_0_sel:2;
    unsigned int    i2c_1_sel:2;
    unsigned int    spdif_out_sel_dummy:4;
    unsigned int    spdif_in_sel:4;
    unsigned int    irtx_sel_dummy:4;
    unsigned int    irda_rx_sel:4;
    unsigned int    ifagc_sel:1;
    unsigned int    uart_2_sel:3;
    unsigned int    reserved_0:1;
    unsigned int    uart_1_sel:3;
}PIN_mux_ctrl0;

typedef struct
{
    unsigned int    i2s_i_mclk_sel:2;
    unsigned int    i2s_i_clk_sel:2;
    unsigned int    i2s_i_ws_sel:2;
    unsigned int    i2s_i_data0_sel:2;
    unsigned int    i2s_i_data1_sel:2;
    unsigned int    i2s_i_data2_sel:2;
    unsigned int    i2s_i_data3_sel:1;
    unsigned int    i2s_o_data0_sel_dummy:1;
    unsigned int    i2s_o_data1_sel_dummy:1;
    unsigned int    i2s_o_data2_sel_dummy:2;
    unsigned int    i2s_o_data3_sel_dummy:1;
    unsigned int    pcm_dummy:6;
    unsigned int    pcm_mclk_in_sel:2;
    unsigned int    pcm_data_in_sel:2;
    unsigned int    pcm_sync_in_sel:2;
    unsigned int    pcm_clk_in_sel:2;
}PIN_mux_ctrl1;

typedef struct
{
    unsigned int    pin_mux_cfg2_dummy:32;
}PIN_mux_ctrl2;

typedef struct
{
    unsigned int    reserved_0:32;
}GPI_sel_0;

typedef struct
{
    unsigned int    reserved_0:32;
}GPI_sel_1;

typedef struct
{
    unsigned int    reserved_0:32;
}GPI_sel_2;

typedef struct
{
    unsigned int    reserved_0:32;
}GPI_sel_3;

typedef struct
{
    unsigned int    force_normal:32;
}TEST_pin_ctrl;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    testpin_mux:5;
}TEST_pin_mux;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    apowl:6;
    unsigned int    reserved_1:2;
    unsigned int    bpowl:6;
    unsigned int    reserved_2:13;
    unsigned int    ibpowl:1;
    unsigned int    pllpowl:1;
    unsigned int    reserved_3:1;
}LVDS_pwr_ctrl0;

typedef struct
{
    unsigned int    sttlil:1;
    unsigned int    slvdsil:2;
    unsigned int    svocml:3;
    unsigned int    spllil:3;
    unsigned int    spllrl:2;
    unsigned int    wdmodel:2;
    unsigned int    pllpolarl:1;
    unsigned int    ststil:3;
    unsigned int    sibgenl:3;
    unsigned int    sbgl:2;
    unsigned int    sibxl:1;
    unsigned int    enib40ux2l:1;
    unsigned int    aackpolarl:1;
    unsigned int    abckpolarl:1;
    unsigned int    acckpolarl:1;
    unsigned int    adckpolarl:1;
    unsigned int    aeckpolarl:1;
    unsigned int    afckpolarl:1;
    unsigned int    backpolarl:1;
    unsigned int    bbckpolarl:1;
}LVDS_pwr_ctrl2;

typedef struct
{
    unsigned int    reserved_0:15;
    unsigned int    bcckpolarl:1;
    unsigned int    bdckpolarl:1;
    unsigned int    beckpolarl:1;
    unsigned int    bfckpolarl:1;
    unsigned int    lvds_pwr_ctrl3_dummy:12;
    unsigned int    envbpbl:1;
}LVDS_pwr_ctrl3;
#endif

#define PA_CFG0                                                       0x18000800
#define PA_CFG0_reg_addr                                              "0xB8000800"
#define PA_CFG0_reg                                                   0xB8000800
#define PA_CFG0_inst_addr                                             "0x0200"
#define PA_CFG0_inst                                                  0x0200
#define PA_CFG0_pa7_ps_shift                                          (28)
#define PA_CFG0_pa6_ps_shift                                          (20)
#define PA_CFG0_pa5_ps_shift                                          (12)
#define PA_CFG0_pa4_ps_shift                                          (4)
#define PA_CFG0_pa7_ps_mask                                           (0xF0000000)
#define PA_CFG0_pa6_ps_mask                                           (0x00F00000)
#define PA_CFG0_pa5_ps_mask                                           (0x0000F000)
#define PA_CFG0_pa4_ps_mask                                           (0x000000F0)
#define PA_CFG0_pa7_ps(data)                                          (0xF0000000&((data)<<28))
#define PA_CFG0_pa6_ps(data)                                          (0x00F00000&((data)<<20))
#define PA_CFG0_pa5_ps(data)                                          (0x0000F000&((data)<<12))
#define PA_CFG0_pa4_ps(data)                                          (0x000000F0&((data)<<4))
#define PA_CFG0_get_pa7_ps(data)                                      ((0xF0000000&(data))>>28)
#define PA_CFG0_get_pa6_ps(data)                                      ((0x00F00000&(data))>>20)
#define PA_CFG0_get_pa5_ps(data)                                      ((0x0000F000&(data))>>12)
#define PA_CFG0_get_pa4_ps(data)                                      ((0x000000F0&(data))>>4)

#define PA_CFG1                                                       0x18000804
#define PA_CFG1_reg_addr                                              "0xB8000804"
#define PA_CFG1_reg                                                   0xB8000804
#define PA_CFG1_inst_addr                                             "0x0201"
#define PA_CFG1_inst                                                  0x0201
#define PA_CFG1_pa3_ps_shift                                          (28)
#define PA_CFG1_pa2_ps_shift                                          (20)
#define PA_CFG1_pa1_ps_shift                                          (12)
#define PA_CFG1_pa0_ps_shift                                          (4)
#define PA_CFG1_pa3_ps_mask                                           (0xF0000000)
#define PA_CFG1_pa2_ps_mask                                           (0x00F00000)
#define PA_CFG1_pa1_ps_mask                                           (0x0000F000)
#define PA_CFG1_pa0_ps_mask                                           (0x000000F0)
#define PA_CFG1_pa3_ps(data)                                          (0xF0000000&((data)<<28))
#define PA_CFG1_pa2_ps(data)                                          (0x00F00000&((data)<<20))
#define PA_CFG1_pa1_ps(data)                                          (0x0000F000&((data)<<12))
#define PA_CFG1_pa0_ps(data)                                          (0x000000F0&((data)<<4))
#define PA_CFG1_get_pa3_ps(data)                                      ((0xF0000000&(data))>>28)
#define PA_CFG1_get_pa2_ps(data)                                      ((0x00F00000&(data))>>20)
#define PA_CFG1_get_pa1_ps(data)                                      ((0x0000F000&(data))>>12)
#define PA_CFG1_get_pa0_ps(data)                                      ((0x000000F0&(data))>>4)

#define PB_CFG0                                                       0x18000808
#define PB_CFG0_reg_addr                                              "0xB8000808"
#define PB_CFG0_reg                                                   0xB8000808
#define PB_CFG0_inst_addr                                             "0x0202"
#define PB_CFG0_inst                                                  0x0202
#define PB_CFG0_pb7_ps_shift                                          (28)
#define PB_CFG0_pb6_ps_shift                                          (20)
#define PB_CFG0_pb5_ps_shift                                          (12)
#define PB_CFG0_pb4_ps_shift                                          (4)
#define PB_CFG0_pb7_ps_mask                                           (0xF0000000)
#define PB_CFG0_pb6_ps_mask                                           (0x00F00000)
#define PB_CFG0_pb5_ps_mask                                           (0x0000F000)
#define PB_CFG0_pb4_ps_mask                                           (0x000000F0)
#define PB_CFG0_pb7_ps(data)                                          (0xF0000000&((data)<<28))
#define PB_CFG0_pb6_ps(data)                                          (0x00F00000&((data)<<20))
#define PB_CFG0_pb5_ps(data)                                          (0x0000F000&((data)<<12))
#define PB_CFG0_pb4_ps(data)                                          (0x000000F0&((data)<<4))
#define PB_CFG0_get_pb7_ps(data)                                      ((0xF0000000&(data))>>28)
#define PB_CFG0_get_pb6_ps(data)                                      ((0x00F00000&(data))>>20)
#define PB_CFG0_get_pb5_ps(data)                                      ((0x0000F000&(data))>>12)
#define PB_CFG0_get_pb4_ps(data)                                      ((0x000000F0&(data))>>4)

#define PB_CFG1                                                       0x1800080c
#define PB_CFG1_reg_addr                                              "0xB800080C"
#define PB_CFG1_reg                                                   0xB800080C
#define PB_CFG1_inst_addr                                             "0x0203"
#define PB_CFG1_inst                                                  0x0203
#define PB_CFG1_pb3_ps_shift                                          (28)
#define PB_CFG1_pb2_ps_shift                                          (20)
#define PB_CFG1_pb1_ps_shift                                          (12)
#define PB_CFG1_pb0_ps_shift                                          (4)
#define PB_CFG1_pb3_ps_mask                                           (0xF0000000)
#define PB_CFG1_pb2_ps_mask                                           (0x00F00000)
#define PB_CFG1_pb1_ps_mask                                           (0x0000F000)
#define PB_CFG1_pb0_ps_mask                                           (0x000000F0)
#define PB_CFG1_pb3_ps(data)                                          (0xF0000000&((data)<<28))
#define PB_CFG1_pb2_ps(data)                                          (0x00F00000&((data)<<20))
#define PB_CFG1_pb1_ps(data)                                          (0x0000F000&((data)<<12))
#define PB_CFG1_pb0_ps(data)                                          (0x000000F0&((data)<<4))
#define PB_CFG1_get_pb3_ps(data)                                      ((0xF0000000&(data))>>28)
#define PB_CFG1_get_pb2_ps(data)                                      ((0x00F00000&(data))>>20)
#define PB_CFG1_get_pb1_ps(data)                                      ((0x0000F000&(data))>>12)
#define PB_CFG1_get_pb0_ps(data)                                      ((0x000000F0&(data))>>4)

#define PC_CFG0                                                       0x18000810
#define PC_CFG0_reg_addr                                              "0xB8000810"
#define PC_CFG0_reg                                                   0xB8000810
#define PC_CFG0_inst_addr                                             "0x0204"
#define PC_CFG0_inst                                                  0x0204
#define PC_CFG0_pc7_ps_shift                                          (28)
#define PC_CFG0_pc6_ps_shift                                          (20)
#define PC_CFG0_pc5_ps_shift                                          (12)
#define PC_CFG0_pc4_ps_shift                                          (4)
#define PC_CFG0_pc7_ps_mask                                           (0xF0000000)
#define PC_CFG0_pc6_ps_mask                                           (0x00F00000)
#define PC_CFG0_pc5_ps_mask                                           (0x0000F000)
#define PC_CFG0_pc4_ps_mask                                           (0x000000F0)
#define PC_CFG0_pc7_ps(data)                                          (0xF0000000&((data)<<28))
#define PC_CFG0_pc6_ps(data)                                          (0x00F00000&((data)<<20))
#define PC_CFG0_pc5_ps(data)                                          (0x0000F000&((data)<<12))
#define PC_CFG0_pc4_ps(data)                                          (0x000000F0&((data)<<4))
#define PC_CFG0_get_pc7_ps(data)                                      ((0xF0000000&(data))>>28)
#define PC_CFG0_get_pc6_ps(data)                                      ((0x00F00000&(data))>>20)
#define PC_CFG0_get_pc5_ps(data)                                      ((0x0000F000&(data))>>12)
#define PC_CFG0_get_pc4_ps(data)                                      ((0x000000F0&(data))>>4)

#define PC_CFG1                                                       0x18000814
#define PC_CFG1_reg_addr                                              "0xB8000814"
#define PC_CFG1_reg                                                   0xB8000814
#define PC_CFG1_inst_addr                                             "0x0205"
#define PC_CFG1_inst                                                  0x0205
#define PC_CFG1_pc3_ps_shift                                          (28)
#define PC_CFG1_pc2_ps_shift                                          (20)
#define PC_CFG1_pc1_ps_shift                                          (12)
#define PC_CFG1_pc0_ps_shift                                          (4)
#define PC_CFG1_pc3_ps_mask                                           (0xF0000000)
#define PC_CFG1_pc2_ps_mask                                           (0x00F00000)
#define PC_CFG1_pc1_ps_mask                                           (0x0000F000)
#define PC_CFG1_pc0_ps_mask                                           (0x000000F0)
#define PC_CFG1_pc3_ps(data)                                          (0xF0000000&((data)<<28))
#define PC_CFG1_pc2_ps(data)                                          (0x00F00000&((data)<<20))
#define PC_CFG1_pc1_ps(data)                                          (0x0000F000&((data)<<12))
#define PC_CFG1_pc0_ps(data)                                          (0x000000F0&((data)<<4))
#define PC_CFG1_get_pc3_ps(data)                                      ((0xF0000000&(data))>>28)
#define PC_CFG1_get_pc2_ps(data)                                      ((0x00F00000&(data))>>20)
#define PC_CFG1_get_pc1_ps(data)                                      ((0x0000F000&(data))>>12)
#define PC_CFG1_get_pc0_ps(data)                                      ((0x000000F0&(data))>>4)

#define PD_CFG0                                                       0x18000818
#define PD_CFG0_reg_addr                                              "0xB8000818"
#define PD_CFG0_reg                                                   0xB8000818
#define PD_CFG0_inst_addr                                             "0x0206"
#define PD_CFG0_inst                                                  0x0206
#define PD_CFG0_pd7_ps_shift                                          (28)
#define PD_CFG0_pd6_ps_shift                                          (20)
#define PD_CFG0_pd5_ps_shift                                          (12)
#define PD_CFG0_pd4_ps_shift                                          (4)
#define PD_CFG0_pd7_ps_mask                                           (0xF0000000)
#define PD_CFG0_pd6_ps_mask                                           (0x00F00000)
#define PD_CFG0_pd5_ps_mask                                           (0x0000F000)
#define PD_CFG0_pd4_ps_mask                                           (0x000000F0)
#define PD_CFG0_pd7_ps(data)                                          (0xF0000000&((data)<<28))
#define PD_CFG0_pd6_ps(data)                                          (0x00F00000&((data)<<20))
#define PD_CFG0_pd5_ps(data)                                          (0x0000F000&((data)<<12))
#define PD_CFG0_pd4_ps(data)                                          (0x000000F0&((data)<<4))
#define PD_CFG0_get_pd7_ps(data)                                      ((0xF0000000&(data))>>28)
#define PD_CFG0_get_pd6_ps(data)                                      ((0x00F00000&(data))>>20)
#define PD_CFG0_get_pd5_ps(data)                                      ((0x0000F000&(data))>>12)
#define PD_CFG0_get_pd4_ps(data)                                      ((0x000000F0&(data))>>4)

#define PD_CFG1                                                       0x1800081c
#define PD_CFG1_reg_addr                                              "0xB800081C"
#define PD_CFG1_reg                                                   0xB800081C
#define PD_CFG1_inst_addr                                             "0x0207"
#define PD_CFG1_inst                                                  0x0207
#define PD_CFG1_pd3_ps_shift                                          (28)
#define PD_CFG1_pd3_pd_shift                                          (27)
#define PD_CFG1_pd3_pu_shift                                          (26)
#define PD_CFG1_pd3_sr_shift                                          (25)
#define PD_CFG1_pd3_ds_shift                                          (24)
#define PD_CFG1_pd2_ps_shift                                          (20)
#define PD_CFG1_pd2_pd_shift                                          (19)
#define PD_CFG1_pd2_pu_shift                                          (18)
#define PD_CFG1_pd2_sr_shift                                          (17)
#define PD_CFG1_pd2_ds_shift                                          (16)
#define PD_CFG1_pd1_ps_shift                                          (12)
#define PD_CFG1_pd1_pd_shift                                          (11)
#define PD_CFG1_pd1_pu_shift                                          (10)
#define PD_CFG1_pd1_sr_shift                                          (9)
#define PD_CFG1_pd1_ds_shift                                          (8)
#define PD_CFG1_pd0_ps_shift                                          (4)
#define PD_CFG1_pd0_pd_shift                                          (3)
#define PD_CFG1_pd0_pu_shift                                          (2)
#define PD_CFG1_pd0_sr_shift                                          (1)
#define PD_CFG1_pd0_ds_shift                                          (0)
#define PD_CFG1_pd3_ps_mask                                           (0xF0000000)
#define PD_CFG1_pd3_pd_mask                                           (0x08000000)
#define PD_CFG1_pd3_pu_mask                                           (0x04000000)
#define PD_CFG1_pd3_sr_mask                                           (0x02000000)
#define PD_CFG1_pd3_ds_mask                                           (0x01000000)
#define PD_CFG1_pd2_ps_mask                                           (0x00F00000)
#define PD_CFG1_pd2_pd_mask                                           (0x00080000)
#define PD_CFG1_pd2_pu_mask                                           (0x00040000)
#define PD_CFG1_pd2_sr_mask                                           (0x00020000)
#define PD_CFG1_pd2_ds_mask                                           (0x00010000)
#define PD_CFG1_pd1_ps_mask                                           (0x0000F000)
#define PD_CFG1_pd1_pd_mask                                           (0x00000800)
#define PD_CFG1_pd1_pu_mask                                           (0x00000400)
#define PD_CFG1_pd1_sr_mask                                           (0x00000200)
#define PD_CFG1_pd1_ds_mask                                           (0x00000100)
#define PD_CFG1_pd0_ps_mask                                           (0x000000F0)
#define PD_CFG1_pd0_pd_mask                                           (0x00000008)
#define PD_CFG1_pd0_pu_mask                                           (0x00000004)
#define PD_CFG1_pd0_sr_mask                                           (0x00000002)
#define PD_CFG1_pd0_ds_mask                                           (0x00000001)
#define PD_CFG1_pd3_ps(data)                                          (0xF0000000&((data)<<28))
#define PD_CFG1_pd3_pd(data)                                          (0x08000000&((data)<<27))
#define PD_CFG1_pd3_pu(data)                                          (0x04000000&((data)<<26))
#define PD_CFG1_pd3_sr(data)                                          (0x02000000&((data)<<25))
#define PD_CFG1_pd3_ds(data)                                          (0x01000000&((data)<<24))
#define PD_CFG1_pd2_ps(data)                                          (0x00F00000&((data)<<20))
#define PD_CFG1_pd2_pd(data)                                          (0x00080000&((data)<<19))
#define PD_CFG1_pd2_pu(data)                                          (0x00040000&((data)<<18))
#define PD_CFG1_pd2_sr(data)                                          (0x00020000&((data)<<17))
#define PD_CFG1_pd2_ds(data)                                          (0x00010000&((data)<<16))
#define PD_CFG1_pd1_ps(data)                                          (0x0000F000&((data)<<12))
#define PD_CFG1_pd1_pd(data)                                          (0x00000800&((data)<<11))
#define PD_CFG1_pd1_pu(data)                                          (0x00000400&((data)<<10))
#define PD_CFG1_pd1_sr(data)                                          (0x00000200&((data)<<9))
#define PD_CFG1_pd1_ds(data)                                          (0x00000100&((data)<<8))
#define PD_CFG1_pd0_ps(data)                                          (0x000000F0&((data)<<4))
#define PD_CFG1_pd0_pd(data)                                          (0x00000008&((data)<<3))
#define PD_CFG1_pd0_pu(data)                                          (0x00000004&((data)<<2))
#define PD_CFG1_pd0_sr(data)                                          (0x00000002&((data)<<1))
#define PD_CFG1_pd0_ds(data)                                          (0x00000001&(data))
#define PD_CFG1_get_pd3_ps(data)                                      ((0xF0000000&(data))>>28)
#define PD_CFG1_get_pd3_pd(data)                                      ((0x08000000&(data))>>27)
#define PD_CFG1_get_pd3_pu(data)                                      ((0x04000000&(data))>>26)
#define PD_CFG1_get_pd3_sr(data)                                      ((0x02000000&(data))>>25)
#define PD_CFG1_get_pd3_ds(data)                                      ((0x01000000&(data))>>24)
#define PD_CFG1_get_pd2_ps(data)                                      ((0x00F00000&(data))>>20)
#define PD_CFG1_get_pd2_pd(data)                                      ((0x00080000&(data))>>19)
#define PD_CFG1_get_pd2_pu(data)                                      ((0x00040000&(data))>>18)
#define PD_CFG1_get_pd2_sr(data)                                      ((0x00020000&(data))>>17)
#define PD_CFG1_get_pd2_ds(data)                                      ((0x00010000&(data))>>16)
#define PD_CFG1_get_pd1_ps(data)                                      ((0x0000F000&(data))>>12)
#define PD_CFG1_get_pd1_pd(data)                                      ((0x00000800&(data))>>11)
#define PD_CFG1_get_pd1_pu(data)                                      ((0x00000400&(data))>>10)
#define PD_CFG1_get_pd1_sr(data)                                      ((0x00000200&(data))>>9)
#define PD_CFG1_get_pd1_ds(data)                                      ((0x00000100&(data))>>8)
#define PD_CFG1_get_pd0_ps(data)                                      ((0x000000F0&(data))>>4)
#define PD_CFG1_get_pd0_pd(data)                                      ((0x00000008&(data))>>3)
#define PD_CFG1_get_pd0_pu(data)                                      ((0x00000004&(data))>>2)
#define PD_CFG1_get_pd0_sr(data)                                      ((0x00000002&(data))>>1)
#define PD_CFG1_get_pd0_ds(data)                                      (0x00000001&(data))

#define PE_CFG0                                                       0x18000820
#define PE_CFG0_reg_addr                                              "0xB8000820"
#define PE_CFG0_reg                                                   0xB8000820
#define PE_CFG0_inst_addr                                             "0x0208"
#define PE_CFG0_inst                                                  0x0208
#define PE_CFG0_pe7_ps_shift                                          (28)
#define PE_CFG0_pe6_ps_shift                                          (20)
#define PE_CFG0_pe5_ps_shift                                          (12)
#define PE_CFG0_pe4_ps_shift                                          (4)
#define PE_CFG0_pe7_ps_mask                                           (0xF0000000)
#define PE_CFG0_pe6_ps_mask                                           (0x00F00000)
#define PE_CFG0_pe5_ps_mask                                           (0x0000F000)
#define PE_CFG0_pe4_ps_mask                                           (0x000000F0)
#define PE_CFG0_pe7_ps(data)                                          (0xF0000000&((data)<<28))
#define PE_CFG0_pe6_ps(data)                                          (0x00F00000&((data)<<20))
#define PE_CFG0_pe5_ps(data)                                          (0x0000F000&((data)<<12))
#define PE_CFG0_pe4_ps(data)                                          (0x000000F0&((data)<<4))
#define PE_CFG0_get_pe7_ps(data)                                      ((0xF0000000&(data))>>28)
#define PE_CFG0_get_pe6_ps(data)                                      ((0x00F00000&(data))>>20)
#define PE_CFG0_get_pe5_ps(data)                                      ((0x0000F000&(data))>>12)
#define PE_CFG0_get_pe4_ps(data)                                      ((0x000000F0&(data))>>4)

#define PE_CFG1                                                       0x18000824
#define PE_CFG1_reg_addr                                              "0xB8000824"
#define PE_CFG1_reg                                                   0xB8000824
#define PE_CFG1_inst_addr                                             "0x0209"
#define PE_CFG1_inst                                                  0x0209
#define PE_CFG1_pe3_ps_shift                                          (28)
#define PE_CFG1_pe2_ps_shift                                          (20)
#define PE_CFG1_pe2_pd_shift                                          (19)
#define PE_CFG1_pe2_pu_shift                                          (18)
#define PE_CFG1_pe2_sr_shift                                          (17)
#define PE_CFG1_pe2_ds_shift                                          (16)
#define PE_CFG1_pe1_ps_shift                                          (12)
#define PE_CFG1_pe1_pd_shift                                          (11)
#define PE_CFG1_pe1_pu_shift                                          (10)
#define PE_CFG1_pe1_sr_shift                                          (9)
#define PE_CFG1_pe1_ds_shift                                          (8)
#define PE_CFG1_pe0_ps_shift                                          (4)
#define PE_CFG1_pe0_pd_shift                                          (3)
#define PE_CFG1_pe0_pu_shift                                          (2)
#define PE_CFG1_pe0_sr_shift                                          (1)
#define PE_CFG1_pe0_ds_shift                                          (0)
#define PE_CFG1_pe3_ps_mask                                           (0xF0000000)
#define PE_CFG1_pe2_ps_mask                                           (0x00F00000)
#define PE_CFG1_pe2_pd_mask                                           (0x00080000)
#define PE_CFG1_pe2_pu_mask                                           (0x00040000)
#define PE_CFG1_pe2_sr_mask                                           (0x00020000)
#define PE_CFG1_pe2_ds_mask                                           (0x00010000)
#define PE_CFG1_pe1_ps_mask                                           (0x0000F000)
#define PE_CFG1_pe1_pd_mask                                           (0x00000800)
#define PE_CFG1_pe1_pu_mask                                           (0x00000400)
#define PE_CFG1_pe1_sr_mask                                           (0x00000200)
#define PE_CFG1_pe1_ds_mask                                           (0x00000100)
#define PE_CFG1_pe0_ps_mask                                           (0x000000F0)
#define PE_CFG1_pe0_pd_mask                                           (0x00000008)
#define PE_CFG1_pe0_pu_mask                                           (0x00000004)
#define PE_CFG1_pe0_sr_mask                                           (0x00000002)
#define PE_CFG1_pe0_ds_mask                                           (0x00000001)
#define PE_CFG1_pe3_ps(data)                                          (0xF0000000&((data)<<28))
#define PE_CFG1_pe2_ps(data)                                          (0x00F00000&((data)<<20))
#define PE_CFG1_pe2_pd(data)                                          (0x00080000&((data)<<19))
#define PE_CFG1_pe2_pu(data)                                          (0x00040000&((data)<<18))
#define PE_CFG1_pe2_sr(data)                                          (0x00020000&((data)<<17))
#define PE_CFG1_pe2_ds(data)                                          (0x00010000&((data)<<16))
#define PE_CFG1_pe1_ps(data)                                          (0x0000F000&((data)<<12))
#define PE_CFG1_pe1_pd(data)                                          (0x00000800&((data)<<11))
#define PE_CFG1_pe1_pu(data)                                          (0x00000400&((data)<<10))
#define PE_CFG1_pe1_sr(data)                                          (0x00000200&((data)<<9))
#define PE_CFG1_pe1_ds(data)                                          (0x00000100&((data)<<8))
#define PE_CFG1_pe0_ps(data)                                          (0x000000F0&((data)<<4))
#define PE_CFG1_pe0_pd(data)                                          (0x00000008&((data)<<3))
#define PE_CFG1_pe0_pu(data)                                          (0x00000004&((data)<<2))
#define PE_CFG1_pe0_sr(data)                                          (0x00000002&((data)<<1))
#define PE_CFG1_pe0_ds(data)                                          (0x00000001&(data))
#define PE_CFG1_get_pe3_ps(data)                                      ((0xF0000000&(data))>>28)
#define PE_CFG1_get_pe2_ps(data)                                      ((0x00F00000&(data))>>20)
#define PE_CFG1_get_pe2_pd(data)                                      ((0x00080000&(data))>>19)
#define PE_CFG1_get_pe2_pu(data)                                      ((0x00040000&(data))>>18)
#define PE_CFG1_get_pe2_sr(data)                                      ((0x00020000&(data))>>17)
#define PE_CFG1_get_pe2_ds(data)                                      ((0x00010000&(data))>>16)
#define PE_CFG1_get_pe1_ps(data)                                      ((0x0000F000&(data))>>12)
#define PE_CFG1_get_pe1_pd(data)                                      ((0x00000800&(data))>>11)
#define PE_CFG1_get_pe1_pu(data)                                      ((0x00000400&(data))>>10)
#define PE_CFG1_get_pe1_sr(data)                                      ((0x00000200&(data))>>9)
#define PE_CFG1_get_pe1_ds(data)                                      ((0x00000100&(data))>>8)
#define PE_CFG1_get_pe0_ps(data)                                      ((0x000000F0&(data))>>4)
#define PE_CFG1_get_pe0_pd(data)                                      ((0x00000008&(data))>>3)
#define PE_CFG1_get_pe0_pu(data)                                      ((0x00000004&(data))>>2)
#define PE_CFG1_get_pe0_sr(data)                                      ((0x00000002&(data))>>1)
#define PE_CFG1_get_pe0_ds(data)                                      (0x00000001&(data))

#define PF_CFG0                                                       0x18000828
#define PF_CFG0_reg_addr                                              "0xB8000828"
#define PF_CFG0_reg                                                   0xB8000828
#define PF_CFG0_inst_addr                                             "0x020A"
#define PF_CFG0_inst                                                  0x020A
#define PF_CFG0_pf7_ps_shift                                          (28)
#define PF_CFG0_pf6_ps_shift                                          (20)
#define PF_CFG0_pf5_ps_shift                                          (12)
#define PF_CFG0_pf4_ps_shift                                          (4)
#define PF_CFG0_pf7_ps_mask                                           (0xF0000000)
#define PF_CFG0_pf6_ps_mask                                           (0x00F00000)
#define PF_CFG0_pf5_ps_mask                                           (0x0000F000)
#define PF_CFG0_pf4_ps_mask                                           (0x000000F0)
#define PF_CFG0_pf7_ps(data)                                          (0xF0000000&((data)<<28))
#define PF_CFG0_pf6_ps(data)                                          (0x00F00000&((data)<<20))
#define PF_CFG0_pf5_ps(data)                                          (0x0000F000&((data)<<12))
#define PF_CFG0_pf4_ps(data)                                          (0x000000F0&((data)<<4))
#define PF_CFG0_get_pf7_ps(data)                                      ((0xF0000000&(data))>>28)
#define PF_CFG0_get_pf6_ps(data)                                      ((0x00F00000&(data))>>20)
#define PF_CFG0_get_pf5_ps(data)                                      ((0x0000F000&(data))>>12)
#define PF_CFG0_get_pf4_ps(data)                                      ((0x000000F0&(data))>>4)

#define PF_CFG1                                                       0x1800082c
#define PF_CFG1_reg_addr                                              "0xB800082C"
#define PF_CFG1_reg                                                   0xB800082C
#define PF_CFG1_inst_addr                                             "0x020B"
#define PF_CFG1_inst                                                  0x020B
#define PF_CFG1_pf3_ps_shift                                          (28)
#define PF_CFG1_pf2_ps_shift                                          (20)
#define PF_CFG1_pf1_ps_shift                                          (12)
#define PF_CFG1_pf3_ps_mask                                           (0xF0000000)
#define PF_CFG1_pf2_ps_mask                                           (0x00F00000)
#define PF_CFG1_pf1_ps_mask                                           (0x0000F000)
#define PF_CFG1_pf3_ps(data)                                          (0xF0000000&((data)<<28))
#define PF_CFG1_pf2_ps(data)                                          (0x00F00000&((data)<<20))
#define PF_CFG1_pf1_ps(data)                                          (0x0000F000&((data)<<12))
#define PF_CFG1_get_pf3_ps(data)                                      ((0xF0000000&(data))>>28)
#define PF_CFG1_get_pf2_ps(data)                                      ((0x00F00000&(data))>>20)
#define PF_CFG1_get_pf1_ps(data)                                      ((0x0000F000&(data))>>12)

#define PG_CFG0                                                       0x18000830
#define PG_CFG0_reg_addr                                              "0xB8000830"
#define PG_CFG0_reg                                                   0xB8000830
#define PG_CFG0_inst_addr                                             "0x020C"
#define PG_CFG0_inst                                                  0x020C
#define PG_CFG0_pg7_ps_shift                                          (28)
#define PG_CFG0_pg7_pd_shift                                          (27)
#define PG_CFG0_pg7_pu_shift                                          (26)
#define PG_CFG0_pg7_sr_shift                                          (25)
#define PG_CFG0_pg7_ds_shift                                          (24)
#define PG_CFG0_pg6_ps_shift                                          (20)
#define PG_CFG0_pg6_pd_shift                                          (19)
#define PG_CFG0_pg6_pu_shift                                          (18)
#define PG_CFG0_pg6_sr_shift                                          (17)
#define PG_CFG0_pg6_ds_shift                                          (16)
#define PG_CFG0_pg5_ps_shift                                          (12)
#define PG_CFG0_pg5_pd_shift                                          (11)
#define PG_CFG0_pg5_pu_shift                                          (10)
#define PG_CFG0_pg5_sr_shift                                          (9)
#define PG_CFG0_pg5_ds_shift                                          (8)
#define PG_CFG0_pg4_ps_shift                                          (4)
#define PG_CFG0_pg4_pd_shift                                          (3)
#define PG_CFG0_pg4_pu_shift                                          (2)
#define PG_CFG0_pg4_sr_shift                                          (1)
#define PG_CFG0_pg4_ds_shift                                          (0)
#define PG_CFG0_pg7_ps_mask                                           (0xF0000000)
#define PG_CFG0_pg7_pd_mask                                           (0x08000000)
#define PG_CFG0_pg7_pu_mask                                           (0x04000000)
#define PG_CFG0_pg7_sr_mask                                           (0x02000000)
#define PG_CFG0_pg7_ds_mask                                           (0x01000000)
#define PG_CFG0_pg6_ps_mask                                           (0x00F00000)
#define PG_CFG0_pg6_pd_mask                                           (0x00080000)
#define PG_CFG0_pg6_pu_mask                                           (0x00040000)
#define PG_CFG0_pg6_sr_mask                                           (0x00020000)
#define PG_CFG0_pg6_ds_mask                                           (0x00010000)
#define PG_CFG0_pg5_ps_mask                                           (0x0000F000)
#define PG_CFG0_pg5_pd_mask                                           (0x00000800)
#define PG_CFG0_pg5_pu_mask                                           (0x00000400)
#define PG_CFG0_pg5_sr_mask                                           (0x00000200)
#define PG_CFG0_pg5_ds_mask                                           (0x00000100)
#define PG_CFG0_pg4_ps_mask                                           (0x000000F0)
#define PG_CFG0_pg4_pd_mask                                           (0x00000008)
#define PG_CFG0_pg4_pu_mask                                           (0x00000004)
#define PG_CFG0_pg4_sr_mask                                           (0x00000002)
#define PG_CFG0_pg4_ds_mask                                           (0x00000001)
#define PG_CFG0_pg7_ps(data)                                          (0xF0000000&((data)<<28))
#define PG_CFG0_pg7_pd(data)                                          (0x08000000&((data)<<27))
#define PG_CFG0_pg7_pu(data)                                          (0x04000000&((data)<<26))
#define PG_CFG0_pg7_sr(data)                                          (0x02000000&((data)<<25))
#define PG_CFG0_pg7_ds(data)                                          (0x01000000&((data)<<24))
#define PG_CFG0_pg6_ps(data)                                          (0x00F00000&((data)<<20))
#define PG_CFG0_pg6_pd(data)                                          (0x00080000&((data)<<19))
#define PG_CFG0_pg6_pu(data)                                          (0x00040000&((data)<<18))
#define PG_CFG0_pg6_sr(data)                                          (0x00020000&((data)<<17))
#define PG_CFG0_pg6_ds(data)                                          (0x00010000&((data)<<16))
#define PG_CFG0_pg5_ps(data)                                          (0x0000F000&((data)<<12))
#define PG_CFG0_pg5_pd(data)                                          (0x00000800&((data)<<11))
#define PG_CFG0_pg5_pu(data)                                          (0x00000400&((data)<<10))
#define PG_CFG0_pg5_sr(data)                                          (0x00000200&((data)<<9))
#define PG_CFG0_pg5_ds(data)                                          (0x00000100&((data)<<8))
#define PG_CFG0_pg4_ps(data)                                          (0x000000F0&((data)<<4))
#define PG_CFG0_pg4_pd(data)                                          (0x00000008&((data)<<3))
#define PG_CFG0_pg4_pu(data)                                          (0x00000004&((data)<<2))
#define PG_CFG0_pg4_sr(data)                                          (0x00000002&((data)<<1))
#define PG_CFG0_pg4_ds(data)                                          (0x00000001&(data))
#define PG_CFG0_get_pg7_ps(data)                                      ((0xF0000000&(data))>>28)
#define PG_CFG0_get_pg7_pd(data)                                      ((0x08000000&(data))>>27)
#define PG_CFG0_get_pg7_pu(data)                                      ((0x04000000&(data))>>26)
#define PG_CFG0_get_pg7_sr(data)                                      ((0x02000000&(data))>>25)
#define PG_CFG0_get_pg7_ds(data)                                      ((0x01000000&(data))>>24)
#define PG_CFG0_get_pg6_ps(data)                                      ((0x00F00000&(data))>>20)
#define PG_CFG0_get_pg6_pd(data)                                      ((0x00080000&(data))>>19)
#define PG_CFG0_get_pg6_pu(data)                                      ((0x00040000&(data))>>18)
#define PG_CFG0_get_pg6_sr(data)                                      ((0x00020000&(data))>>17)
#define PG_CFG0_get_pg6_ds(data)                                      ((0x00010000&(data))>>16)
#define PG_CFG0_get_pg5_ps(data)                                      ((0x0000F000&(data))>>12)
#define PG_CFG0_get_pg5_pd(data)                                      ((0x00000800&(data))>>11)
#define PG_CFG0_get_pg5_pu(data)                                      ((0x00000400&(data))>>10)
#define PG_CFG0_get_pg5_sr(data)                                      ((0x00000200&(data))>>9)
#define PG_CFG0_get_pg5_ds(data)                                      ((0x00000100&(data))>>8)
#define PG_CFG0_get_pg4_ps(data)                                      ((0x000000F0&(data))>>4)
#define PG_CFG0_get_pg4_pd(data)                                      ((0x00000008&(data))>>3)
#define PG_CFG0_get_pg4_pu(data)                                      ((0x00000004&(data))>>2)
#define PG_CFG0_get_pg4_sr(data)                                      ((0x00000002&(data))>>1)
#define PG_CFG0_get_pg4_ds(data)                                      (0x00000001&(data))

#define PG_CFG1                                                       0x18000834
#define PG_CFG1_reg_addr                                              "0xB8000834"
#define PG_CFG1_reg                                                   0xB8000834
#define PG_CFG1_inst_addr                                             "0x020D"
#define PG_CFG1_inst                                                  0x020D
#define PG_CFG1_pg3_ps_shift                                          (28)
#define PG_CFG1_pg3_pd_shift                                          (27)
#define PG_CFG1_pg3_pu_shift                                          (26)
#define PG_CFG1_pg3_sr_shift                                          (25)
#define PG_CFG1_pg3_ds_shift                                          (24)
#define PG_CFG1_pg2_ps_shift                                          (20)
#define PG_CFG1_pg2_pd_shift                                          (19)
#define PG_CFG1_pg2_pu_shift                                          (18)
#define PG_CFG1_pg2_sr_shift                                          (17)
#define PG_CFG1_pg2_ds_shift                                          (16)
#define PG_CFG1_pg1_ps_shift                                          (12)
#define PG_CFG1_pg1_pd_shift                                          (11)
#define PG_CFG1_pg1_pu_shift                                          (10)
#define PG_CFG1_pg1_sr_shift                                          (9)
#define PG_CFG1_pg1_ds_shift                                          (8)
#define PG_CFG1_pg0_ps_shift                                          (4)
#define PG_CFG1_pg0_pd_shift                                          (3)
#define PG_CFG1_pg0_pu_shift                                          (2)
#define PG_CFG1_pg0_sr_shift                                          (1)
#define PG_CFG1_pg0_ds_shift                                          (0)
#define PG_CFG1_pg3_ps_mask                                           (0xF0000000)
#define PG_CFG1_pg3_pd_mask                                           (0x08000000)
#define PG_CFG1_pg3_pu_mask                                           (0x04000000)
#define PG_CFG1_pg3_sr_mask                                           (0x02000000)
#define PG_CFG1_pg3_ds_mask                                           (0x01000000)
#define PG_CFG1_pg2_ps_mask                                           (0x00F00000)
#define PG_CFG1_pg2_pd_mask                                           (0x00080000)
#define PG_CFG1_pg2_pu_mask                                           (0x00040000)
#define PG_CFG1_pg2_sr_mask                                           (0x00020000)
#define PG_CFG1_pg2_ds_mask                                           (0x00010000)
#define PG_CFG1_pg1_ps_mask                                           (0x0000F000)
#define PG_CFG1_pg1_pd_mask                                           (0x00000800)
#define PG_CFG1_pg1_pu_mask                                           (0x00000400)
#define PG_CFG1_pg1_sr_mask                                           (0x00000200)
#define PG_CFG1_pg1_ds_mask                                           (0x00000100)
#define PG_CFG1_pg0_ps_mask                                           (0x000000F0)
#define PG_CFG1_pg0_pd_mask                                           (0x00000008)
#define PG_CFG1_pg0_pu_mask                                           (0x00000004)
#define PG_CFG1_pg0_sr_mask                                           (0x00000002)
#define PG_CFG1_pg0_ds_mask                                           (0x00000001)
#define PG_CFG1_pg3_ps(data)                                          (0xF0000000&((data)<<28))
#define PG_CFG1_pg3_pd(data)                                          (0x08000000&((data)<<27))
#define PG_CFG1_pg3_pu(data)                                          (0x04000000&((data)<<26))
#define PG_CFG1_pg3_sr(data)                                          (0x02000000&((data)<<25))
#define PG_CFG1_pg3_ds(data)                                          (0x01000000&((data)<<24))
#define PG_CFG1_pg2_ps(data)                                          (0x00F00000&((data)<<20))
#define PG_CFG1_pg2_pd(data)                                          (0x00080000&((data)<<19))
#define PG_CFG1_pg2_pu(data)                                          (0x00040000&((data)<<18))
#define PG_CFG1_pg2_sr(data)                                          (0x00020000&((data)<<17))
#define PG_CFG1_pg2_ds(data)                                          (0x00010000&((data)<<16))
#define PG_CFG1_pg1_ps(data)                                          (0x0000F000&((data)<<12))
#define PG_CFG1_pg1_pd(data)                                          (0x00000800&((data)<<11))
#define PG_CFG1_pg1_pu(data)                                          (0x00000400&((data)<<10))
#define PG_CFG1_pg1_sr(data)                                          (0x00000200&((data)<<9))
#define PG_CFG1_pg1_ds(data)                                          (0x00000100&((data)<<8))
#define PG_CFG1_pg0_ps(data)                                          (0x000000F0&((data)<<4))
#define PG_CFG1_pg0_pd(data)                                          (0x00000008&((data)<<3))
#define PG_CFG1_pg0_pu(data)                                          (0x00000004&((data)<<2))
#define PG_CFG1_pg0_sr(data)                                          (0x00000002&((data)<<1))
#define PG_CFG1_pg0_ds(data)                                          (0x00000001&(data))
#define PG_CFG1_get_pg3_ps(data)                                      ((0xF0000000&(data))>>28)
#define PG_CFG1_get_pg3_pd(data)                                      ((0x08000000&(data))>>27)
#define PG_CFG1_get_pg3_pu(data)                                      ((0x04000000&(data))>>26)
#define PG_CFG1_get_pg3_sr(data)                                      ((0x02000000&(data))>>25)
#define PG_CFG1_get_pg3_ds(data)                                      ((0x01000000&(data))>>24)
#define PG_CFG1_get_pg2_ps(data)                                      ((0x00F00000&(data))>>20)
#define PG_CFG1_get_pg2_pd(data)                                      ((0x00080000&(data))>>19)
#define PG_CFG1_get_pg2_pu(data)                                      ((0x00040000&(data))>>18)
#define PG_CFG1_get_pg2_sr(data)                                      ((0x00020000&(data))>>17)
#define PG_CFG1_get_pg2_ds(data)                                      ((0x00010000&(data))>>16)
#define PG_CFG1_get_pg1_ps(data)                                      ((0x0000F000&(data))>>12)
#define PG_CFG1_get_pg1_pd(data)                                      ((0x00000800&(data))>>11)
#define PG_CFG1_get_pg1_pu(data)                                      ((0x00000400&(data))>>10)
#define PG_CFG1_get_pg1_sr(data)                                      ((0x00000200&(data))>>9)
#define PG_CFG1_get_pg1_ds(data)                                      ((0x00000100&(data))>>8)
#define PG_CFG1_get_pg0_ps(data)                                      ((0x000000F0&(data))>>4)
#define PG_CFG1_get_pg0_pd(data)                                      ((0x00000008&(data))>>3)
#define PG_CFG1_get_pg0_pu(data)                                      ((0x00000004&(data))>>2)
#define PG_CFG1_get_pg0_sr(data)                                      ((0x00000002&(data))>>1)
#define PG_CFG1_get_pg0_ds(data)                                      (0x00000001&(data))

#define PH_CFG0                                                       0x18000838
#define PH_CFG0_reg_addr                                              "0xB8000838"
#define PH_CFG0_reg                                                   0xB8000838
#define PH_CFG0_inst_addr                                             "0x020E"
#define PH_CFG0_inst                                                  0x020E
#define PH_CFG0_ph7_ps_shift                                          (28)
#define PH_CFG0_ph7_pd_shift                                          (27)
#define PH_CFG0_ph7_pu_shift                                          (26)
#define PH_CFG0_ph7_sr_shift                                          (25)
#define PH_CFG0_ph7_ds_shift                                          (24)
#define PH_CFG0_ph6_ps_shift                                          (20)
#define PH_CFG0_ph6_pd_shift                                          (19)
#define PH_CFG0_ph6_pu_shift                                          (18)
#define PH_CFG0_ph6_sr_shift                                          (17)
#define PH_CFG0_ph6_ds_shift                                          (16)
#define PH_CFG0_ph5_ps_shift                                          (12)
#define PH_CFG0_ph5_pd_shift                                          (11)
#define PH_CFG0_ph5_pu_shift                                          (10)
#define PH_CFG0_ph5_sr_shift                                          (9)
#define PH_CFG0_ph5_ds_shift                                          (8)
#define PH_CFG0_ph4_ps_shift                                          (4)
#define PH_CFG0_ph4_pd_shift                                          (3)
#define PH_CFG0_ph4_pu_shift                                          (2)
#define PH_CFG0_ph4_sr_shift                                          (1)
#define PH_CFG0_ph4_ds_shift                                          (0)
#define PH_CFG0_ph7_ps_mask                                           (0xF0000000)
#define PH_CFG0_ph7_pd_mask                                           (0x08000000)
#define PH_CFG0_ph7_pu_mask                                           (0x04000000)
#define PH_CFG0_ph7_sr_mask                                           (0x02000000)
#define PH_CFG0_ph7_ds_mask                                           (0x01000000)
#define PH_CFG0_ph6_ps_mask                                           (0x00F00000)
#define PH_CFG0_ph6_pd_mask                                           (0x00080000)
#define PH_CFG0_ph6_pu_mask                                           (0x00040000)
#define PH_CFG0_ph6_sr_mask                                           (0x00020000)
#define PH_CFG0_ph6_ds_mask                                           (0x00010000)
#define PH_CFG0_ph5_ps_mask                                           (0x0000F000)
#define PH_CFG0_ph5_pd_mask                                           (0x00000800)
#define PH_CFG0_ph5_pu_mask                                           (0x00000400)
#define PH_CFG0_ph5_sr_mask                                           (0x00000200)
#define PH_CFG0_ph5_ds_mask                                           (0x00000100)
#define PH_CFG0_ph4_ps_mask                                           (0x000000F0)
#define PH_CFG0_ph4_pd_mask                                           (0x00000008)
#define PH_CFG0_ph4_pu_mask                                           (0x00000004)
#define PH_CFG0_ph4_sr_mask                                           (0x00000002)
#define PH_CFG0_ph4_ds_mask                                           (0x00000001)
#define PH_CFG0_ph7_ps(data)                                          (0xF0000000&((data)<<28))
#define PH_CFG0_ph7_pd(data)                                          (0x08000000&((data)<<27))
#define PH_CFG0_ph7_pu(data)                                          (0x04000000&((data)<<26))
#define PH_CFG0_ph7_sr(data)                                          (0x02000000&((data)<<25))
#define PH_CFG0_ph7_ds(data)                                          (0x01000000&((data)<<24))
#define PH_CFG0_ph6_ps(data)                                          (0x00F00000&((data)<<20))
#define PH_CFG0_ph6_pd(data)                                          (0x00080000&((data)<<19))
#define PH_CFG0_ph6_pu(data)                                          (0x00040000&((data)<<18))
#define PH_CFG0_ph6_sr(data)                                          (0x00020000&((data)<<17))
#define PH_CFG0_ph6_ds(data)                                          (0x00010000&((data)<<16))
#define PH_CFG0_ph5_ps(data)                                          (0x0000F000&((data)<<12))
#define PH_CFG0_ph5_pd(data)                                          (0x00000800&((data)<<11))
#define PH_CFG0_ph5_pu(data)                                          (0x00000400&((data)<<10))
#define PH_CFG0_ph5_sr(data)                                          (0x00000200&((data)<<9))
#define PH_CFG0_ph5_ds(data)                                          (0x00000100&((data)<<8))
#define PH_CFG0_ph4_ps(data)                                          (0x000000F0&((data)<<4))
#define PH_CFG0_ph4_pd(data)                                          (0x00000008&((data)<<3))
#define PH_CFG0_ph4_pu(data)                                          (0x00000004&((data)<<2))
#define PH_CFG0_ph4_sr(data)                                          (0x00000002&((data)<<1))
#define PH_CFG0_ph4_ds(data)                                          (0x00000001&(data))
#define PH_CFG0_get_ph7_ps(data)                                      ((0xF0000000&(data))>>28)
#define PH_CFG0_get_ph7_pd(data)                                      ((0x08000000&(data))>>27)
#define PH_CFG0_get_ph7_pu(data)                                      ((0x04000000&(data))>>26)
#define PH_CFG0_get_ph7_sr(data)                                      ((0x02000000&(data))>>25)
#define PH_CFG0_get_ph7_ds(data)                                      ((0x01000000&(data))>>24)
#define PH_CFG0_get_ph6_ps(data)                                      ((0x00F00000&(data))>>20)
#define PH_CFG0_get_ph6_pd(data)                                      ((0x00080000&(data))>>19)
#define PH_CFG0_get_ph6_pu(data)                                      ((0x00040000&(data))>>18)
#define PH_CFG0_get_ph6_sr(data)                                      ((0x00020000&(data))>>17)
#define PH_CFG0_get_ph6_ds(data)                                      ((0x00010000&(data))>>16)
#define PH_CFG0_get_ph5_ps(data)                                      ((0x0000F000&(data))>>12)
#define PH_CFG0_get_ph5_pd(data)                                      ((0x00000800&(data))>>11)
#define PH_CFG0_get_ph5_pu(data)                                      ((0x00000400&(data))>>10)
#define PH_CFG0_get_ph5_sr(data)                                      ((0x00000200&(data))>>9)
#define PH_CFG0_get_ph5_ds(data)                                      ((0x00000100&(data))>>8)
#define PH_CFG0_get_ph4_ps(data)                                      ((0x000000F0&(data))>>4)
#define PH_CFG0_get_ph4_pd(data)                                      ((0x00000008&(data))>>3)
#define PH_CFG0_get_ph4_pu(data)                                      ((0x00000004&(data))>>2)
#define PH_CFG0_get_ph4_sr(data)                                      ((0x00000002&(data))>>1)
#define PH_CFG0_get_ph4_ds(data)                                      (0x00000001&(data))

#define PH_CFG1                                                       0x1800083c
#define PH_CFG1_reg_addr                                              "0xB800083C"
#define PH_CFG1_reg                                                   0xB800083C
#define PH_CFG1_inst_addr                                             "0x020F"
#define PH_CFG1_inst                                                  0x020F
#define PH_CFG1_ph3_ps_shift                                          (28)
#define PH_CFG1_ph3_pd_shift                                          (27)
#define PH_CFG1_ph3_pu_shift                                          (26)
#define PH_CFG1_ph3_sr_shift                                          (25)
#define PH_CFG1_ph3_ds_shift                                          (24)
#define PH_CFG1_ph2_ps_shift                                          (20)
#define PH_CFG1_ph2_pd_shift                                          (19)
#define PH_CFG1_ph2_pu_shift                                          (18)
#define PH_CFG1_ph2_sr_shift                                          (17)
#define PH_CFG1_ph2_ds_shift                                          (16)
#define PH_CFG1_ph1_ps_shift                                          (12)
#define PH_CFG1_ph1_pd_shift                                          (11)
#define PH_CFG1_ph1_pu_shift                                          (10)
#define PH_CFG1_ph1_sr_shift                                          (9)
#define PH_CFG1_ph1_ds_shift                                          (8)
#define PH_CFG1_ph0_ps_shift                                          (4)
#define PH_CFG1_ph0_pd_shift                                          (3)
#define PH_CFG1_ph0_pu_shift                                          (2)
#define PH_CFG1_ph0_sr_shift                                          (1)
#define PH_CFG1_ph0_ds_shift                                          (0)
#define PH_CFG1_ph3_ps_mask                                           (0xF0000000)
#define PH_CFG1_ph3_pd_mask                                           (0x08000000)
#define PH_CFG1_ph3_pu_mask                                           (0x04000000)
#define PH_CFG1_ph3_sr_mask                                           (0x02000000)
#define PH_CFG1_ph3_ds_mask                                           (0x01000000)
#define PH_CFG1_ph2_ps_mask                                           (0x00F00000)
#define PH_CFG1_ph2_pd_mask                                           (0x00080000)
#define PH_CFG1_ph2_pu_mask                                           (0x00040000)
#define PH_CFG1_ph2_sr_mask                                           (0x00020000)
#define PH_CFG1_ph2_ds_mask                                           (0x00010000)
#define PH_CFG1_ph1_ps_mask                                           (0x0000F000)
#define PH_CFG1_ph1_pd_mask                                           (0x00000800)
#define PH_CFG1_ph1_pu_mask                                           (0x00000400)
#define PH_CFG1_ph1_sr_mask                                           (0x00000200)
#define PH_CFG1_ph1_ds_mask                                           (0x00000100)
#define PH_CFG1_ph0_ps_mask                                           (0x000000F0)
#define PH_CFG1_ph0_pd_mask                                           (0x00000008)
#define PH_CFG1_ph0_pu_mask                                           (0x00000004)
#define PH_CFG1_ph0_sr_mask                                           (0x00000002)
#define PH_CFG1_ph0_ds_mask                                           (0x00000001)
#define PH_CFG1_ph3_ps(data)                                          (0xF0000000&((data)<<28))
#define PH_CFG1_ph3_pd(data)                                          (0x08000000&((data)<<27))
#define PH_CFG1_ph3_pu(data)                                          (0x04000000&((data)<<26))
#define PH_CFG1_ph3_sr(data)                                          (0x02000000&((data)<<25))
#define PH_CFG1_ph3_ds(data)                                          (0x01000000&((data)<<24))
#define PH_CFG1_ph2_ps(data)                                          (0x00F00000&((data)<<20))
#define PH_CFG1_ph2_pd(data)                                          (0x00080000&((data)<<19))
#define PH_CFG1_ph2_pu(data)                                          (0x00040000&((data)<<18))
#define PH_CFG1_ph2_sr(data)                                          (0x00020000&((data)<<17))
#define PH_CFG1_ph2_ds(data)                                          (0x00010000&((data)<<16))
#define PH_CFG1_ph1_ps(data)                                          (0x0000F000&((data)<<12))
#define PH_CFG1_ph1_pd(data)                                          (0x00000800&((data)<<11))
#define PH_CFG1_ph1_pu(data)                                          (0x00000400&((data)<<10))
#define PH_CFG1_ph1_sr(data)                                          (0x00000200&((data)<<9))
#define PH_CFG1_ph1_ds(data)                                          (0x00000100&((data)<<8))
#define PH_CFG1_ph0_ps(data)                                          (0x000000F0&((data)<<4))
#define PH_CFG1_ph0_pd(data)                                          (0x00000008&((data)<<3))
#define PH_CFG1_ph0_pu(data)                                          (0x00000004&((data)<<2))
#define PH_CFG1_ph0_sr(data)                                          (0x00000002&((data)<<1))
#define PH_CFG1_ph0_ds(data)                                          (0x00000001&(data))
#define PH_CFG1_get_ph3_ps(data)                                      ((0xF0000000&(data))>>28)
#define PH_CFG1_get_ph3_pd(data)                                      ((0x08000000&(data))>>27)
#define PH_CFG1_get_ph3_pu(data)                                      ((0x04000000&(data))>>26)
#define PH_CFG1_get_ph3_sr(data)                                      ((0x02000000&(data))>>25)
#define PH_CFG1_get_ph3_ds(data)                                      ((0x01000000&(data))>>24)
#define PH_CFG1_get_ph2_ps(data)                                      ((0x00F00000&(data))>>20)
#define PH_CFG1_get_ph2_pd(data)                                      ((0x00080000&(data))>>19)
#define PH_CFG1_get_ph2_pu(data)                                      ((0x00040000&(data))>>18)
#define PH_CFG1_get_ph2_sr(data)                                      ((0x00020000&(data))>>17)
#define PH_CFG1_get_ph2_ds(data)                                      ((0x00010000&(data))>>16)
#define PH_CFG1_get_ph1_ps(data)                                      ((0x0000F000&(data))>>12)
#define PH_CFG1_get_ph1_pd(data)                                      ((0x00000800&(data))>>11)
#define PH_CFG1_get_ph1_pu(data)                                      ((0x00000400&(data))>>10)
#define PH_CFG1_get_ph1_sr(data)                                      ((0x00000200&(data))>>9)
#define PH_CFG1_get_ph1_ds(data)                                      ((0x00000100&(data))>>8)
#define PH_CFG1_get_ph0_ps(data)                                      ((0x000000F0&(data))>>4)
#define PH_CFG1_get_ph0_pd(data)                                      ((0x00000008&(data))>>3)
#define PH_CFG1_get_ph0_pu(data)                                      ((0x00000004&(data))>>2)
#define PH_CFG1_get_ph0_sr(data)                                      ((0x00000002&(data))>>1)
#define PH_CFG1_get_ph0_ds(data)                                      (0x00000001&(data))

#define PI_CFG0                                                       0x18000840
#define PI_CFG0_reg_addr                                              "0xB8000840"
#define PI_CFG0_reg                                                   0xB8000840
#define PI_CFG0_inst_addr                                             "0x0210"
#define PI_CFG0_inst                                                  0x0210
#define PI_CFG0_pi7_ps_shift                                          (28)
#define PI_CFG0_pi7_pd_shift                                          (27)
#define PI_CFG0_pi7_pu_shift                                          (26)
#define PI_CFG0_pi7_sr_shift                                          (25)
#define PI_CFG0_pi7_ds_shift                                          (24)
#define PI_CFG0_pi6_ps_shift                                          (20)
#define PI_CFG0_pi6_pd_shift                                          (19)
#define PI_CFG0_pi6_pu_shift                                          (18)
#define PI_CFG0_pi6_sr_shift                                          (17)
#define PI_CFG0_pi6_ds_shift                                          (16)
#define PI_CFG0_pi5_ps_shift                                          (12)
#define PI_CFG0_pi5_pd_shift                                          (11)
#define PI_CFG0_pi5_pu_shift                                          (10)
#define PI_CFG0_pi5_sr_shift                                          (9)
#define PI_CFG0_pi5_ds_shift                                          (8)
#define PI_CFG0_pi4_ps_shift                                          (4)
#define PI_CFG0_pi4_pd_shift                                          (3)
#define PI_CFG0_pi4_pu_shift                                          (2)
#define PI_CFG0_pi4_sr_shift                                          (1)
#define PI_CFG0_pi4_ds_shift                                          (0)
#define PI_CFG0_pi7_ps_mask                                           (0xF0000000)
#define PI_CFG0_pi7_pd_mask                                           (0x08000000)
#define PI_CFG0_pi7_pu_mask                                           (0x04000000)
#define PI_CFG0_pi7_sr_mask                                           (0x02000000)
#define PI_CFG0_pi7_ds_mask                                           (0x01000000)
#define PI_CFG0_pi6_ps_mask                                           (0x00F00000)
#define PI_CFG0_pi6_pd_mask                                           (0x00080000)
#define PI_CFG0_pi6_pu_mask                                           (0x00040000)
#define PI_CFG0_pi6_sr_mask                                           (0x00020000)
#define PI_CFG0_pi6_ds_mask                                           (0x00010000)
#define PI_CFG0_pi5_ps_mask                                           (0x0000F000)
#define PI_CFG0_pi5_pd_mask                                           (0x00000800)
#define PI_CFG0_pi5_pu_mask                                           (0x00000400)
#define PI_CFG0_pi5_sr_mask                                           (0x00000200)
#define PI_CFG0_pi5_ds_mask                                           (0x00000100)
#define PI_CFG0_pi4_ps_mask                                           (0x000000F0)
#define PI_CFG0_pi4_pd_mask                                           (0x00000008)
#define PI_CFG0_pi4_pu_mask                                           (0x00000004)
#define PI_CFG0_pi4_sr_mask                                           (0x00000002)
#define PI_CFG0_pi4_ds_mask                                           (0x00000001)
#define PI_CFG0_pi7_ps(data)                                          (0xF0000000&((data)<<28))
#define PI_CFG0_pi7_pd(data)                                          (0x08000000&((data)<<27))
#define PI_CFG0_pi7_pu(data)                                          (0x04000000&((data)<<26))
#define PI_CFG0_pi7_sr(data)                                          (0x02000000&((data)<<25))
#define PI_CFG0_pi7_ds(data)                                          (0x01000000&((data)<<24))
#define PI_CFG0_pi6_ps(data)                                          (0x00F00000&((data)<<20))
#define PI_CFG0_pi6_pd(data)                                          (0x00080000&((data)<<19))
#define PI_CFG0_pi6_pu(data)                                          (0x00040000&((data)<<18))
#define PI_CFG0_pi6_sr(data)                                          (0x00020000&((data)<<17))
#define PI_CFG0_pi6_ds(data)                                          (0x00010000&((data)<<16))
#define PI_CFG0_pi5_ps(data)                                          (0x0000F000&((data)<<12))
#define PI_CFG0_pi5_pd(data)                                          (0x00000800&((data)<<11))
#define PI_CFG0_pi5_pu(data)                                          (0x00000400&((data)<<10))
#define PI_CFG0_pi5_sr(data)                                          (0x00000200&((data)<<9))
#define PI_CFG0_pi5_ds(data)                                          (0x00000100&((data)<<8))
#define PI_CFG0_pi4_ps(data)                                          (0x000000F0&((data)<<4))
#define PI_CFG0_pi4_pd(data)                                          (0x00000008&((data)<<3))
#define PI_CFG0_pi4_pu(data)                                          (0x00000004&((data)<<2))
#define PI_CFG0_pi4_sr(data)                                          (0x00000002&((data)<<1))
#define PI_CFG0_pi4_ds(data)                                          (0x00000001&(data))
#define PI_CFG0_get_pi7_ps(data)                                      ((0xF0000000&(data))>>28)
#define PI_CFG0_get_pi7_pd(data)                                      ((0x08000000&(data))>>27)
#define PI_CFG0_get_pi7_pu(data)                                      ((0x04000000&(data))>>26)
#define PI_CFG0_get_pi7_sr(data)                                      ((0x02000000&(data))>>25)
#define PI_CFG0_get_pi7_ds(data)                                      ((0x01000000&(data))>>24)
#define PI_CFG0_get_pi6_ps(data)                                      ((0x00F00000&(data))>>20)
#define PI_CFG0_get_pi6_pd(data)                                      ((0x00080000&(data))>>19)
#define PI_CFG0_get_pi6_pu(data)                                      ((0x00040000&(data))>>18)
#define PI_CFG0_get_pi6_sr(data)                                      ((0x00020000&(data))>>17)
#define PI_CFG0_get_pi6_ds(data)                                      ((0x00010000&(data))>>16)
#define PI_CFG0_get_pi5_ps(data)                                      ((0x0000F000&(data))>>12)
#define PI_CFG0_get_pi5_pd(data)                                      ((0x00000800&(data))>>11)
#define PI_CFG0_get_pi5_pu(data)                                      ((0x00000400&(data))>>10)
#define PI_CFG0_get_pi5_sr(data)                                      ((0x00000200&(data))>>9)
#define PI_CFG0_get_pi5_ds(data)                                      ((0x00000100&(data))>>8)
#define PI_CFG0_get_pi4_ps(data)                                      ((0x000000F0&(data))>>4)
#define PI_CFG0_get_pi4_pd(data)                                      ((0x00000008&(data))>>3)
#define PI_CFG0_get_pi4_pu(data)                                      ((0x00000004&(data))>>2)
#define PI_CFG0_get_pi4_sr(data)                                      ((0x00000002&(data))>>1)
#define PI_CFG0_get_pi4_ds(data)                                      (0x00000001&(data))

#define PI_CFG1                                                       0x18000844
#define PI_CFG1_reg_addr                                              "0xB8000844"
#define PI_CFG1_reg                                                   0xB8000844
#define PI_CFG1_inst_addr                                             "0x0211"
#define PI_CFG1_inst                                                  0x0211
#define PI_CFG1_pi3_ps_shift                                          (28)
#define PI_CFG1_pi3_pd_shift                                          (27)
#define PI_CFG1_pi3_pu_shift                                          (26)
#define PI_CFG1_pi3_sr_shift                                          (25)
#define PI_CFG1_pi3_ds_shift                                          (24)
#define PI_CFG1_pi2_ps_shift                                          (20)
#define PI_CFG1_pi2_pd_shift                                          (19)
#define PI_CFG1_pi2_pu_shift                                          (18)
#define PI_CFG1_pi2_sr_shift                                          (17)
#define PI_CFG1_pi2_ds_shift                                          (16)
#define PI_CFG1_pi1_ps_shift                                          (12)
#define PI_CFG1_pi1_pd_shift                                          (11)
#define PI_CFG1_pi1_pu_shift                                          (10)
#define PI_CFG1_pi1_sr_shift                                          (9)
#define PI_CFG1_pi1_ds_shift                                          (8)
#define PI_CFG1_pi0_ps_dummy_shift                                    (0)
#define PI_CFG1_pi3_ps_mask                                           (0xF0000000)
#define PI_CFG1_pi3_pd_mask                                           (0x08000000)
#define PI_CFG1_pi3_pu_mask                                           (0x04000000)
#define PI_CFG1_pi3_sr_mask                                           (0x02000000)
#define PI_CFG1_pi3_ds_mask                                           (0x01000000)
#define PI_CFG1_pi2_ps_mask                                           (0x00F00000)
#define PI_CFG1_pi2_pd_mask                                           (0x00080000)
#define PI_CFG1_pi2_pu_mask                                           (0x00040000)
#define PI_CFG1_pi2_sr_mask                                           (0x00020000)
#define PI_CFG1_pi2_ds_mask                                           (0x00010000)
#define PI_CFG1_pi1_ps_mask                                           (0x0000F000)
#define PI_CFG1_pi1_pd_mask                                           (0x00000800)
#define PI_CFG1_pi1_pu_mask                                           (0x00000400)
#define PI_CFG1_pi1_sr_mask                                           (0x00000200)
#define PI_CFG1_pi1_ds_mask                                           (0x00000100)
#define PI_CFG1_pi0_ps_dummy_mask                                     (0x000000FF)
#define PI_CFG1_pi3_ps(data)                                          (0xF0000000&((data)<<28))
#define PI_CFG1_pi3_pd(data)                                          (0x08000000&((data)<<27))
#define PI_CFG1_pi3_pu(data)                                          (0x04000000&((data)<<26))
#define PI_CFG1_pi3_sr(data)                                          (0x02000000&((data)<<25))
#define PI_CFG1_pi3_ds(data)                                          (0x01000000&((data)<<24))
#define PI_CFG1_pi2_ps(data)                                          (0x00F00000&((data)<<20))
#define PI_CFG1_pi2_pd(data)                                          (0x00080000&((data)<<19))
#define PI_CFG1_pi2_pu(data)                                          (0x00040000&((data)<<18))
#define PI_CFG1_pi2_sr(data)                                          (0x00020000&((data)<<17))
#define PI_CFG1_pi2_ds(data)                                          (0x00010000&((data)<<16))
#define PI_CFG1_pi1_ps(data)                                          (0x0000F000&((data)<<12))
#define PI_CFG1_pi1_pd(data)                                          (0x00000800&((data)<<11))
#define PI_CFG1_pi1_pu(data)                                          (0x00000400&((data)<<10))
#define PI_CFG1_pi1_sr(data)                                          (0x00000200&((data)<<9))
#define PI_CFG1_pi1_ds(data)                                          (0x00000100&((data)<<8))
#define PI_CFG1_pi0_ps_dummy(data)                                    (0x000000FF&(data))
#define PI_CFG1_get_pi3_ps(data)                                      ((0xF0000000&(data))>>28)
#define PI_CFG1_get_pi3_pd(data)                                      ((0x08000000&(data))>>27)
#define PI_CFG1_get_pi3_pu(data)                                      ((0x04000000&(data))>>26)
#define PI_CFG1_get_pi3_sr(data)                                      ((0x02000000&(data))>>25)
#define PI_CFG1_get_pi3_ds(data)                                      ((0x01000000&(data))>>24)
#define PI_CFG1_get_pi2_ps(data)                                      ((0x00F00000&(data))>>20)
#define PI_CFG1_get_pi2_pd(data)                                      ((0x00080000&(data))>>19)
#define PI_CFG1_get_pi2_pu(data)                                      ((0x00040000&(data))>>18)
#define PI_CFG1_get_pi2_sr(data)                                      ((0x00020000&(data))>>17)
#define PI_CFG1_get_pi2_ds(data)                                      ((0x00010000&(data))>>16)
#define PI_CFG1_get_pi1_ps(data)                                      ((0x0000F000&(data))>>12)
#define PI_CFG1_get_pi1_pd(data)                                      ((0x00000800&(data))>>11)
#define PI_CFG1_get_pi1_pu(data)                                      ((0x00000400&(data))>>10)
#define PI_CFG1_get_pi1_sr(data)                                      ((0x00000200&(data))>>9)
#define PI_CFG1_get_pi1_ds(data)                                      ((0x00000100&(data))>>8)
#define PI_CFG1_get_pi0_ps_dummy(data)                                (0x000000FF&(data))

#define PJ_CFG0                                                       0x18000848
#define PJ_CFG0_reg_addr                                              "0xB8000848"
#define PJ_CFG0_reg                                                   0xB8000848
#define PJ_CFG0_inst_addr                                             "0x0212"
#define PJ_CFG0_inst                                                  0x0212
#define PJ_CFG0_pj7_ps_shift                                          (28)
#define PJ_CFG0_pj7_pd_shift                                          (27)
#define PJ_CFG0_pj7_pu_shift                                          (26)
#define PJ_CFG0_pj7_sr_shift                                          (25)
#define PJ_CFG0_pj7_ds_shift                                          (24)
#define PJ_CFG0_pj6_ps_shift                                          (20)
#define PJ_CFG0_pj6_pd_shift                                          (19)
#define PJ_CFG0_pj6_pu_shift                                          (18)
#define PJ_CFG0_pj6_sr_shift                                          (17)
#define PJ_CFG0_pj6_ds_shift                                          (16)
#define PJ_CFG0_pj5_ps_shift                                          (12)
#define PJ_CFG0_pj5_pd_shift                                          (11)
#define PJ_CFG0_pj5_pu_shift                                          (10)
#define PJ_CFG0_pj5_sr_shift                                          (9)
#define PJ_CFG0_pj5_ds_shift                                          (8)
#define PJ_CFG0_pj4_ps_shift                                          (4)
#define PJ_CFG0_pj4_pd_shift                                          (3)
#define PJ_CFG0_pj4_pu_shift                                          (2)
#define PJ_CFG0_pj4_sr_shift                                          (1)
#define PJ_CFG0_pj4_ds_shift                                          (0)
#define PJ_CFG0_pj7_ps_mask                                           (0xF0000000)
#define PJ_CFG0_pj7_pd_mask                                           (0x08000000)
#define PJ_CFG0_pj7_pu_mask                                           (0x04000000)
#define PJ_CFG0_pj7_sr_mask                                           (0x02000000)
#define PJ_CFG0_pj7_ds_mask                                           (0x01000000)
#define PJ_CFG0_pj6_ps_mask                                           (0x00F00000)
#define PJ_CFG0_pj6_pd_mask                                           (0x00080000)
#define PJ_CFG0_pj6_pu_mask                                           (0x00040000)
#define PJ_CFG0_pj6_sr_mask                                           (0x00020000)
#define PJ_CFG0_pj6_ds_mask                                           (0x00010000)
#define PJ_CFG0_pj5_ps_mask                                           (0x0000F000)
#define PJ_CFG0_pj5_pd_mask                                           (0x00000800)
#define PJ_CFG0_pj5_pu_mask                                           (0x00000400)
#define PJ_CFG0_pj5_sr_mask                                           (0x00000200)
#define PJ_CFG0_pj5_ds_mask                                           (0x00000100)
#define PJ_CFG0_pj4_ps_mask                                           (0x000000F0)
#define PJ_CFG0_pj4_pd_mask                                           (0x00000008)
#define PJ_CFG0_pj4_pu_mask                                           (0x00000004)
#define PJ_CFG0_pj4_sr_mask                                           (0x00000002)
#define PJ_CFG0_pj4_ds_mask                                           (0x00000001)
#define PJ_CFG0_pj7_ps(data)                                          (0xF0000000&((data)<<28))
#define PJ_CFG0_pj7_pd(data)                                          (0x08000000&((data)<<27))
#define PJ_CFG0_pj7_pu(data)                                          (0x04000000&((data)<<26))
#define PJ_CFG0_pj7_sr(data)                                          (0x02000000&((data)<<25))
#define PJ_CFG0_pj7_ds(data)                                          (0x01000000&((data)<<24))
#define PJ_CFG0_pj6_ps(data)                                          (0x00F00000&((data)<<20))
#define PJ_CFG0_pj6_pd(data)                                          (0x00080000&((data)<<19))
#define PJ_CFG0_pj6_pu(data)                                          (0x00040000&((data)<<18))
#define PJ_CFG0_pj6_sr(data)                                          (0x00020000&((data)<<17))
#define PJ_CFG0_pj6_ds(data)                                          (0x00010000&((data)<<16))
#define PJ_CFG0_pj5_ps(data)                                          (0x0000F000&((data)<<12))
#define PJ_CFG0_pj5_pd(data)                                          (0x00000800&((data)<<11))
#define PJ_CFG0_pj5_pu(data)                                          (0x00000400&((data)<<10))
#define PJ_CFG0_pj5_sr(data)                                          (0x00000200&((data)<<9))
#define PJ_CFG0_pj5_ds(data)                                          (0x00000100&((data)<<8))
#define PJ_CFG0_pj4_ps(data)                                          (0x000000F0&((data)<<4))
#define PJ_CFG0_pj4_pd(data)                                          (0x00000008&((data)<<3))
#define PJ_CFG0_pj4_pu(data)                                          (0x00000004&((data)<<2))
#define PJ_CFG0_pj4_sr(data)                                          (0x00000002&((data)<<1))
#define PJ_CFG0_pj4_ds(data)                                          (0x00000001&(data))
#define PJ_CFG0_get_pj7_ps(data)                                      ((0xF0000000&(data))>>28)
#define PJ_CFG0_get_pj7_pd(data)                                      ((0x08000000&(data))>>27)
#define PJ_CFG0_get_pj7_pu(data)                                      ((0x04000000&(data))>>26)
#define PJ_CFG0_get_pj7_sr(data)                                      ((0x02000000&(data))>>25)
#define PJ_CFG0_get_pj7_ds(data)                                      ((0x01000000&(data))>>24)
#define PJ_CFG0_get_pj6_ps(data)                                      ((0x00F00000&(data))>>20)
#define PJ_CFG0_get_pj6_pd(data)                                      ((0x00080000&(data))>>19)
#define PJ_CFG0_get_pj6_pu(data)                                      ((0x00040000&(data))>>18)
#define PJ_CFG0_get_pj6_sr(data)                                      ((0x00020000&(data))>>17)
#define PJ_CFG0_get_pj6_ds(data)                                      ((0x00010000&(data))>>16)
#define PJ_CFG0_get_pj5_ps(data)                                      ((0x0000F000&(data))>>12)
#define PJ_CFG0_get_pj5_pd(data)                                      ((0x00000800&(data))>>11)
#define PJ_CFG0_get_pj5_pu(data)                                      ((0x00000400&(data))>>10)
#define PJ_CFG0_get_pj5_sr(data)                                      ((0x00000200&(data))>>9)
#define PJ_CFG0_get_pj5_ds(data)                                      ((0x00000100&(data))>>8)
#define PJ_CFG0_get_pj4_ps(data)                                      ((0x000000F0&(data))>>4)
#define PJ_CFG0_get_pj4_pd(data)                                      ((0x00000008&(data))>>3)
#define PJ_CFG0_get_pj4_pu(data)                                      ((0x00000004&(data))>>2)
#define PJ_CFG0_get_pj4_sr(data)                                      ((0x00000002&(data))>>1)
#define PJ_CFG0_get_pj4_ds(data)                                      (0x00000001&(data))

#define PJ_CFG1                                                       0x1800084c
#define PJ_CFG1_reg_addr                                              "0xB800084C"
#define PJ_CFG1_reg                                                   0xB800084C
#define PJ_CFG1_inst_addr                                             "0x0213"
#define PJ_CFG1_inst                                                  0x0213
#define PJ_CFG1_pj3_ps_shift                                          (28)
#define PJ_CFG1_pj3_pd_shift                                          (27)
#define PJ_CFG1_pj3_pu_shift                                          (26)
#define PJ_CFG1_pj3_sr_shift                                          (25)
#define PJ_CFG1_pj3_ds_shift                                          (24)
#define PJ_CFG1_pj2_ps_shift                                          (20)
#define PJ_CFG1_pj2_pd_shift                                          (19)
#define PJ_CFG1_pj2_pu_shift                                          (18)
#define PJ_CFG1_pj2_sr_shift                                          (17)
#define PJ_CFG1_pj2_ds_shift                                          (16)
#define PJ_CFG1_pj1_ps_shift                                          (12)
#define PJ_CFG1_pj1_pd_shift                                          (11)
#define PJ_CFG1_pj1_pu_shift                                          (10)
#define PJ_CFG1_pj1_sr_shift                                          (9)
#define PJ_CFG1_pj1_ds_shift                                          (8)
#define PJ_CFG1_pj0_ps_shift                                          (4)
#define PJ_CFG1_pj0_pd_shift                                          (3)
#define PJ_CFG1_pj0_pu_shift                                          (2)
#define PJ_CFG1_pj0_sr_shift                                          (1)
#define PJ_CFG1_pj0_ds_shift                                          (0)
#define PJ_CFG1_pj3_ps_mask                                           (0xF0000000)
#define PJ_CFG1_pj3_pd_mask                                           (0x08000000)
#define PJ_CFG1_pj3_pu_mask                                           (0x04000000)
#define PJ_CFG1_pj3_sr_mask                                           (0x02000000)
#define PJ_CFG1_pj3_ds_mask                                           (0x01000000)
#define PJ_CFG1_pj2_ps_mask                                           (0x00F00000)
#define PJ_CFG1_pj2_pd_mask                                           (0x00080000)
#define PJ_CFG1_pj2_pu_mask                                           (0x00040000)
#define PJ_CFG1_pj2_sr_mask                                           (0x00020000)
#define PJ_CFG1_pj2_ds_mask                                           (0x00010000)
#define PJ_CFG1_pj1_ps_mask                                           (0x0000F000)
#define PJ_CFG1_pj1_pd_mask                                           (0x00000800)
#define PJ_CFG1_pj1_pu_mask                                           (0x00000400)
#define PJ_CFG1_pj1_sr_mask                                           (0x00000200)
#define PJ_CFG1_pj1_ds_mask                                           (0x00000100)
#define PJ_CFG1_pj0_ps_mask                                           (0x000000F0)
#define PJ_CFG1_pj0_pd_mask                                           (0x00000008)
#define PJ_CFG1_pj0_pu_mask                                           (0x00000004)
#define PJ_CFG1_pj0_sr_mask                                           (0x00000002)
#define PJ_CFG1_pj0_ds_mask                                           (0x00000001)
#define PJ_CFG1_pj3_ps(data)                                          (0xF0000000&((data)<<28))
#define PJ_CFG1_pj3_pd(data)                                          (0x08000000&((data)<<27))
#define PJ_CFG1_pj3_pu(data)                                          (0x04000000&((data)<<26))
#define PJ_CFG1_pj3_sr(data)                                          (0x02000000&((data)<<25))
#define PJ_CFG1_pj3_ds(data)                                          (0x01000000&((data)<<24))
#define PJ_CFG1_pj2_ps(data)                                          (0x00F00000&((data)<<20))
#define PJ_CFG1_pj2_pd(data)                                          (0x00080000&((data)<<19))
#define PJ_CFG1_pj2_pu(data)                                          (0x00040000&((data)<<18))
#define PJ_CFG1_pj2_sr(data)                                          (0x00020000&((data)<<17))
#define PJ_CFG1_pj2_ds(data)                                          (0x00010000&((data)<<16))
#define PJ_CFG1_pj1_ps(data)                                          (0x0000F000&((data)<<12))
#define PJ_CFG1_pj1_pd(data)                                          (0x00000800&((data)<<11))
#define PJ_CFG1_pj1_pu(data)                                          (0x00000400&((data)<<10))
#define PJ_CFG1_pj1_sr(data)                                          (0x00000200&((data)<<9))
#define PJ_CFG1_pj1_ds(data)                                          (0x00000100&((data)<<8))
#define PJ_CFG1_pj0_ps(data)                                          (0x000000F0&((data)<<4))
#define PJ_CFG1_pj0_pd(data)                                          (0x00000008&((data)<<3))
#define PJ_CFG1_pj0_pu(data)                                          (0x00000004&((data)<<2))
#define PJ_CFG1_pj0_sr(data)                                          (0x00000002&((data)<<1))
#define PJ_CFG1_pj0_ds(data)                                          (0x00000001&(data))
#define PJ_CFG1_get_pj3_ps(data)                                      ((0xF0000000&(data))>>28)
#define PJ_CFG1_get_pj3_pd(data)                                      ((0x08000000&(data))>>27)
#define PJ_CFG1_get_pj3_pu(data)                                      ((0x04000000&(data))>>26)
#define PJ_CFG1_get_pj3_sr(data)                                      ((0x02000000&(data))>>25)
#define PJ_CFG1_get_pj3_ds(data)                                      ((0x01000000&(data))>>24)
#define PJ_CFG1_get_pj2_ps(data)                                      ((0x00F00000&(data))>>20)
#define PJ_CFG1_get_pj2_pd(data)                                      ((0x00080000&(data))>>19)
#define PJ_CFG1_get_pj2_pu(data)                                      ((0x00040000&(data))>>18)
#define PJ_CFG1_get_pj2_sr(data)                                      ((0x00020000&(data))>>17)
#define PJ_CFG1_get_pj2_ds(data)                                      ((0x00010000&(data))>>16)
#define PJ_CFG1_get_pj1_ps(data)                                      ((0x0000F000&(data))>>12)
#define PJ_CFG1_get_pj1_pd(data)                                      ((0x00000800&(data))>>11)
#define PJ_CFG1_get_pj1_pu(data)                                      ((0x00000400&(data))>>10)
#define PJ_CFG1_get_pj1_sr(data)                                      ((0x00000200&(data))>>9)
#define PJ_CFG1_get_pj1_ds(data)                                      ((0x00000100&(data))>>8)
#define PJ_CFG1_get_pj0_ps(data)                                      ((0x000000F0&(data))>>4)
#define PJ_CFG1_get_pj0_pd(data)                                      ((0x00000008&(data))>>3)
#define PJ_CFG1_get_pj0_pu(data)                                      ((0x00000004&(data))>>2)
#define PJ_CFG1_get_pj0_sr(data)                                      ((0x00000002&(data))>>1)
#define PJ_CFG1_get_pj0_ds(data)                                      (0x00000001&(data))

#define PK_CFG0                                                       0x18000850
#define PK_CFG0_reg_addr                                              "0xB8000850"
#define PK_CFG0_reg                                                   0xB8000850
#define PK_CFG0_inst_addr                                             "0x0214"
#define PK_CFG0_inst                                                  0x0214
#define PK_CFG0_pk7_ps_shift                                          (28)
#define PK_CFG0_pk7_pd_shift                                          (27)
#define PK_CFG0_pk7_pu_shift                                          (26)
#define PK_CFG0_pk7_sr_shift                                          (25)
#define PK_CFG0_pk7_ds_shift                                          (24)
#define PK_CFG0_pk6_ps_shift                                          (20)
#define PK_CFG0_pk6_pd_shift                                          (19)
#define PK_CFG0_pk6_pu_shift                                          (18)
#define PK_CFG0_pk6_sr_shift                                          (17)
#define PK_CFG0_pk6_ds_shift                                          (16)
#define PK_CFG0_pk5_ps_shift                                          (12)
#define PK_CFG0_pk5_pd_shift                                          (11)
#define PK_CFG0_pk5_pu_shift                                          (10)
#define PK_CFG0_pk5_sr_shift                                          (9)
#define PK_CFG0_pk5_ds_shift                                          (8)
#define PK_CFG0_pk4_ps_shift                                          (4)
#define PK_CFG0_pk4_pd_shift                                          (3)
#define PK_CFG0_pk4_pu_shift                                          (2)
#define PK_CFG0_pk4_sr_shift                                          (1)
#define PK_CFG0_pk4_ds_shift                                          (0)
#define PK_CFG0_pk7_ps_mask                                           (0xF0000000)
#define PK_CFG0_pk7_pd_mask                                           (0x08000000)
#define PK_CFG0_pk7_pu_mask                                           (0x04000000)
#define PK_CFG0_pk7_sr_mask                                           (0x02000000)
#define PK_CFG0_pk7_ds_mask                                           (0x01000000)
#define PK_CFG0_pk6_ps_mask                                           (0x00F00000)
#define PK_CFG0_pk6_pd_mask                                           (0x00080000)
#define PK_CFG0_pk6_pu_mask                                           (0x00040000)
#define PK_CFG0_pk6_sr_mask                                           (0x00020000)
#define PK_CFG0_pk6_ds_mask                                           (0x00010000)
#define PK_CFG0_pk5_ps_mask                                           (0x0000F000)
#define PK_CFG0_pk5_pd_mask                                           (0x00000800)
#define PK_CFG0_pk5_pu_mask                                           (0x00000400)
#define PK_CFG0_pk5_sr_mask                                           (0x00000200)
#define PK_CFG0_pk5_ds_mask                                           (0x00000100)
#define PK_CFG0_pk4_ps_mask                                           (0x000000F0)
#define PK_CFG0_pk4_pd_mask                                           (0x00000008)
#define PK_CFG0_pk4_pu_mask                                           (0x00000004)
#define PK_CFG0_pk4_sr_mask                                           (0x00000002)
#define PK_CFG0_pk4_ds_mask                                           (0x00000001)
#define PK_CFG0_pk7_ps(data)                                          (0xF0000000&((data)<<28))
#define PK_CFG0_pk7_pd(data)                                          (0x08000000&((data)<<27))
#define PK_CFG0_pk7_pu(data)                                          (0x04000000&((data)<<26))
#define PK_CFG0_pk7_sr(data)                                          (0x02000000&((data)<<25))
#define PK_CFG0_pk7_ds(data)                                          (0x01000000&((data)<<24))
#define PK_CFG0_pk6_ps(data)                                          (0x00F00000&((data)<<20))
#define PK_CFG0_pk6_pd(data)                                          (0x00080000&((data)<<19))
#define PK_CFG0_pk6_pu(data)                                          (0x00040000&((data)<<18))
#define PK_CFG0_pk6_sr(data)                                          (0x00020000&((data)<<17))
#define PK_CFG0_pk6_ds(data)                                          (0x00010000&((data)<<16))
#define PK_CFG0_pk5_ps(data)                                          (0x0000F000&((data)<<12))
#define PK_CFG0_pk5_pd(data)                                          (0x00000800&((data)<<11))
#define PK_CFG0_pk5_pu(data)                                          (0x00000400&((data)<<10))
#define PK_CFG0_pk5_sr(data)                                          (0x00000200&((data)<<9))
#define PK_CFG0_pk5_ds(data)                                          (0x00000100&((data)<<8))
#define PK_CFG0_pk4_ps(data)                                          (0x000000F0&((data)<<4))
#define PK_CFG0_pk4_pd(data)                                          (0x00000008&((data)<<3))
#define PK_CFG0_pk4_pu(data)                                          (0x00000004&((data)<<2))
#define PK_CFG0_pk4_sr(data)                                          (0x00000002&((data)<<1))
#define PK_CFG0_pk4_ds(data)                                          (0x00000001&(data))
#define PK_CFG0_get_pk7_ps(data)                                      ((0xF0000000&(data))>>28)
#define PK_CFG0_get_pk7_pd(data)                                      ((0x08000000&(data))>>27)
#define PK_CFG0_get_pk7_pu(data)                                      ((0x04000000&(data))>>26)
#define PK_CFG0_get_pk7_sr(data)                                      ((0x02000000&(data))>>25)
#define PK_CFG0_get_pk7_ds(data)                                      ((0x01000000&(data))>>24)
#define PK_CFG0_get_pk6_ps(data)                                      ((0x00F00000&(data))>>20)
#define PK_CFG0_get_pk6_pd(data)                                      ((0x00080000&(data))>>19)
#define PK_CFG0_get_pk6_pu(data)                                      ((0x00040000&(data))>>18)
#define PK_CFG0_get_pk6_sr(data)                                      ((0x00020000&(data))>>17)
#define PK_CFG0_get_pk6_ds(data)                                      ((0x00010000&(data))>>16)
#define PK_CFG0_get_pk5_ps(data)                                      ((0x0000F000&(data))>>12)
#define PK_CFG0_get_pk5_pd(data)                                      ((0x00000800&(data))>>11)
#define PK_CFG0_get_pk5_pu(data)                                      ((0x00000400&(data))>>10)
#define PK_CFG0_get_pk5_sr(data)                                      ((0x00000200&(data))>>9)
#define PK_CFG0_get_pk5_ds(data)                                      ((0x00000100&(data))>>8)
#define PK_CFG0_get_pk4_ps(data)                                      ((0x000000F0&(data))>>4)
#define PK_CFG0_get_pk4_pd(data)                                      ((0x00000008&(data))>>3)
#define PK_CFG0_get_pk4_pu(data)                                      ((0x00000004&(data))>>2)
#define PK_CFG0_get_pk4_sr(data)                                      ((0x00000002&(data))>>1)
#define PK_CFG0_get_pk4_ds(data)                                      (0x00000001&(data))

#define PK_CFG1                                                       0x18000854
#define PK_CFG1_reg_addr                                              "0xB8000854"
#define PK_CFG1_reg                                                   0xB8000854
#define PK_CFG1_inst_addr                                             "0x0215"
#define PK_CFG1_inst                                                  0x0215
#define PK_CFG1_pk3_ps_shift                                          (28)
#define PK_CFG1_pk3_pd_shift                                          (27)
#define PK_CFG1_pk3_pu_shift                                          (26)
#define PK_CFG1_pk3_sr_shift                                          (25)
#define PK_CFG1_pk3_ds_shift                                          (24)
#define PK_CFG1_pk2_ps_shift                                          (20)
#define PK_CFG1_pk2_pd_shift                                          (19)
#define PK_CFG1_pk2_pu_shift                                          (18)
#define PK_CFG1_pk2_sr_shift                                          (17)
#define PK_CFG1_pk2_ds_shift                                          (16)
#define PK_CFG1_pk1_ps_shift                                          (12)
#define PK_CFG1_pk1_pd_shift                                          (11)
#define PK_CFG1_pk1_pu_shift                                          (10)
#define PK_CFG1_pk1_sr_shift                                          (9)
#define PK_CFG1_pk1_ds_shift                                          (8)
#define PK_CFG1_pk0_ps_shift                                          (4)
#define PK_CFG1_pk0_pd_shift                                          (3)
#define PK_CFG1_pk0_pu_shift                                          (2)
#define PK_CFG1_pk0_sr_shift                                          (1)
#define PK_CFG1_pk0_ds_shift                                          (0)
#define PK_CFG1_pk3_ps_mask                                           (0xF0000000)
#define PK_CFG1_pk3_pd_mask                                           (0x08000000)
#define PK_CFG1_pk3_pu_mask                                           (0x04000000)
#define PK_CFG1_pk3_sr_mask                                           (0x02000000)
#define PK_CFG1_pk3_ds_mask                                           (0x01000000)
#define PK_CFG1_pk2_ps_mask                                           (0x00F00000)
#define PK_CFG1_pk2_pd_mask                                           (0x00080000)
#define PK_CFG1_pk2_pu_mask                                           (0x00040000)
#define PK_CFG1_pk2_sr_mask                                           (0x00020000)
#define PK_CFG1_pk2_ds_mask                                           (0x00010000)
#define PK_CFG1_pk1_ps_mask                                           (0x0000F000)
#define PK_CFG1_pk1_pd_mask                                           (0x00000800)
#define PK_CFG1_pk1_pu_mask                                           (0x00000400)
#define PK_CFG1_pk1_sr_mask                                           (0x00000200)
#define PK_CFG1_pk1_ds_mask                                           (0x00000100)
#define PK_CFG1_pk0_ps_mask                                           (0x000000F0)
#define PK_CFG1_pk0_pd_mask                                           (0x00000008)
#define PK_CFG1_pk0_pu_mask                                           (0x00000004)
#define PK_CFG1_pk0_sr_mask                                           (0x00000002)
#define PK_CFG1_pk0_ds_mask                                           (0x00000001)
#define PK_CFG1_pk3_ps(data)                                          (0xF0000000&((data)<<28))
#define PK_CFG1_pk3_pd(data)                                          (0x08000000&((data)<<27))
#define PK_CFG1_pk3_pu(data)                                          (0x04000000&((data)<<26))
#define PK_CFG1_pk3_sr(data)                                          (0x02000000&((data)<<25))
#define PK_CFG1_pk3_ds(data)                                          (0x01000000&((data)<<24))
#define PK_CFG1_pk2_ps(data)                                          (0x00F00000&((data)<<20))
#define PK_CFG1_pk2_pd(data)                                          (0x00080000&((data)<<19))
#define PK_CFG1_pk2_pu(data)                                          (0x00040000&((data)<<18))
#define PK_CFG1_pk2_sr(data)                                          (0x00020000&((data)<<17))
#define PK_CFG1_pk2_ds(data)                                          (0x00010000&((data)<<16))
#define PK_CFG1_pk1_ps(data)                                          (0x0000F000&((data)<<12))
#define PK_CFG1_pk1_pd(data)                                          (0x00000800&((data)<<11))
#define PK_CFG1_pk1_pu(data)                                          (0x00000400&((data)<<10))
#define PK_CFG1_pk1_sr(data)                                          (0x00000200&((data)<<9))
#define PK_CFG1_pk1_ds(data)                                          (0x00000100&((data)<<8))
#define PK_CFG1_pk0_ps(data)                                          (0x000000F0&((data)<<4))
#define PK_CFG1_pk0_pd(data)                                          (0x00000008&((data)<<3))
#define PK_CFG1_pk0_pu(data)                                          (0x00000004&((data)<<2))
#define PK_CFG1_pk0_sr(data)                                          (0x00000002&((data)<<1))
#define PK_CFG1_pk0_ds(data)                                          (0x00000001&(data))
#define PK_CFG1_get_pk3_ps(data)                                      ((0xF0000000&(data))>>28)
#define PK_CFG1_get_pk3_pd(data)                                      ((0x08000000&(data))>>27)
#define PK_CFG1_get_pk3_pu(data)                                      ((0x04000000&(data))>>26)
#define PK_CFG1_get_pk3_sr(data)                                      ((0x02000000&(data))>>25)
#define PK_CFG1_get_pk3_ds(data)                                      ((0x01000000&(data))>>24)
#define PK_CFG1_get_pk2_ps(data)                                      ((0x00F00000&(data))>>20)
#define PK_CFG1_get_pk2_pd(data)                                      ((0x00080000&(data))>>19)
#define PK_CFG1_get_pk2_pu(data)                                      ((0x00040000&(data))>>18)
#define PK_CFG1_get_pk2_sr(data)                                      ((0x00020000&(data))>>17)
#define PK_CFG1_get_pk2_ds(data)                                      ((0x00010000&(data))>>16)
#define PK_CFG1_get_pk1_ps(data)                                      ((0x0000F000&(data))>>12)
#define PK_CFG1_get_pk1_pd(data)                                      ((0x00000800&(data))>>11)
#define PK_CFG1_get_pk1_pu(data)                                      ((0x00000400&(data))>>10)
#define PK_CFG1_get_pk1_sr(data)                                      ((0x00000200&(data))>>9)
#define PK_CFG1_get_pk1_ds(data)                                      ((0x00000100&(data))>>8)
#define PK_CFG1_get_pk0_ps(data)                                      ((0x000000F0&(data))>>4)
#define PK_CFG1_get_pk0_pd(data)                                      ((0x00000008&(data))>>3)
#define PK_CFG1_get_pk0_pu(data)                                      ((0x00000004&(data))>>2)
#define PK_CFG1_get_pk0_sr(data)                                      ((0x00000002&(data))>>1)
#define PK_CFG1_get_pk0_ds(data)                                      (0x00000001&(data))

#define PL_CFG0                                                       0x18000858
#define PL_CFG0_reg_addr                                              "0xB8000858"
#define PL_CFG0_reg                                                   0xB8000858
#define PL_CFG0_inst_addr                                             "0x0216"
#define PL_CFG0_inst                                                  0x0216
#define PL_CFG0_pl7_ps_shift                                          (28)
#define PL_CFG0_pl7_pd_shift                                          (27)
#define PL_CFG0_pl7_pu_shift                                          (26)
#define PL_CFG0_pl7_sr_shift                                          (25)
#define PL_CFG0_pl7_ds_shift                                          (24)
#define PL_CFG0_pl6_ps_shift                                          (20)
#define PL_CFG0_pl6_pd_shift                                          (19)
#define PL_CFG0_pl6_pu_shift                                          (18)
#define PL_CFG0_pl6_sr_shift                                          (17)
#define PL_CFG0_pl6_ds_shift                                          (16)
#define PL_CFG0_pl5_ps_shift                                          (12)
#define PL_CFG0_pl5_pd_shift                                          (11)
#define PL_CFG0_pl5_pu_shift                                          (10)
#define PL_CFG0_pl5_sr_shift                                          (9)
#define PL_CFG0_pl5_ds_shift                                          (8)
#define PL_CFG0_pl4_ps_shift                                          (4)
#define PL_CFG0_pl4_pd_shift                                          (3)
#define PL_CFG0_pl4_pu_shift                                          (2)
#define PL_CFG0_pl4_sr_shift                                          (1)
#define PL_CFG0_pl4_ds_shift                                          (0)
#define PL_CFG0_pl7_ps_mask                                           (0xF0000000)
#define PL_CFG0_pl7_pd_mask                                           (0x08000000)
#define PL_CFG0_pl7_pu_mask                                           (0x04000000)
#define PL_CFG0_pl7_sr_mask                                           (0x02000000)
#define PL_CFG0_pl7_ds_mask                                           (0x01000000)
#define PL_CFG0_pl6_ps_mask                                           (0x00F00000)
#define PL_CFG0_pl6_pd_mask                                           (0x00080000)
#define PL_CFG0_pl6_pu_mask                                           (0x00040000)
#define PL_CFG0_pl6_sr_mask                                           (0x00020000)
#define PL_CFG0_pl6_ds_mask                                           (0x00010000)
#define PL_CFG0_pl5_ps_mask                                           (0x0000F000)
#define PL_CFG0_pl5_pd_mask                                           (0x00000800)
#define PL_CFG0_pl5_pu_mask                                           (0x00000400)
#define PL_CFG0_pl5_sr_mask                                           (0x00000200)
#define PL_CFG0_pl5_ds_mask                                           (0x00000100)
#define PL_CFG0_pl4_ps_mask                                           (0x000000F0)
#define PL_CFG0_pl4_pd_mask                                           (0x00000008)
#define PL_CFG0_pl4_pu_mask                                           (0x00000004)
#define PL_CFG0_pl4_sr_mask                                           (0x00000002)
#define PL_CFG0_pl4_ds_mask                                           (0x00000001)
#define PL_CFG0_pl7_ps(data)                                          (0xF0000000&((data)<<28))
#define PL_CFG0_pl7_pd(data)                                          (0x08000000&((data)<<27))
#define PL_CFG0_pl7_pu(data)                                          (0x04000000&((data)<<26))
#define PL_CFG0_pl7_sr(data)                                          (0x02000000&((data)<<25))
#define PL_CFG0_pl7_ds(data)                                          (0x01000000&((data)<<24))
#define PL_CFG0_pl6_ps(data)                                          (0x00F00000&((data)<<20))
#define PL_CFG0_pl6_pd(data)                                          (0x00080000&((data)<<19))
#define PL_CFG0_pl6_pu(data)                                          (0x00040000&((data)<<18))
#define PL_CFG0_pl6_sr(data)                                          (0x00020000&((data)<<17))
#define PL_CFG0_pl6_ds(data)                                          (0x00010000&((data)<<16))
#define PL_CFG0_pl5_ps(data)                                          (0x0000F000&((data)<<12))
#define PL_CFG0_pl5_pd(data)                                          (0x00000800&((data)<<11))
#define PL_CFG0_pl5_pu(data)                                          (0x00000400&((data)<<10))
#define PL_CFG0_pl5_sr(data)                                          (0x00000200&((data)<<9))
#define PL_CFG0_pl5_ds(data)                                          (0x00000100&((data)<<8))
#define PL_CFG0_pl4_ps(data)                                          (0x000000F0&((data)<<4))
#define PL_CFG0_pl4_pd(data)                                          (0x00000008&((data)<<3))
#define PL_CFG0_pl4_pu(data)                                          (0x00000004&((data)<<2))
#define PL_CFG0_pl4_sr(data)                                          (0x00000002&((data)<<1))
#define PL_CFG0_pl4_ds(data)                                          (0x00000001&(data))
#define PL_CFG0_get_pl7_ps(data)                                      ((0xF0000000&(data))>>28)
#define PL_CFG0_get_pl7_pd(data)                                      ((0x08000000&(data))>>27)
#define PL_CFG0_get_pl7_pu(data)                                      ((0x04000000&(data))>>26)
#define PL_CFG0_get_pl7_sr(data)                                      ((0x02000000&(data))>>25)
#define PL_CFG0_get_pl7_ds(data)                                      ((0x01000000&(data))>>24)
#define PL_CFG0_get_pl6_ps(data)                                      ((0x00F00000&(data))>>20)
#define PL_CFG0_get_pl6_pd(data)                                      ((0x00080000&(data))>>19)
#define PL_CFG0_get_pl6_pu(data)                                      ((0x00040000&(data))>>18)
#define PL_CFG0_get_pl6_sr(data)                                      ((0x00020000&(data))>>17)
#define PL_CFG0_get_pl6_ds(data)                                      ((0x00010000&(data))>>16)
#define PL_CFG0_get_pl5_ps(data)                                      ((0x0000F000&(data))>>12)
#define PL_CFG0_get_pl5_pd(data)                                      ((0x00000800&(data))>>11)
#define PL_CFG0_get_pl5_pu(data)                                      ((0x00000400&(data))>>10)
#define PL_CFG0_get_pl5_sr(data)                                      ((0x00000200&(data))>>9)
#define PL_CFG0_get_pl5_ds(data)                                      ((0x00000100&(data))>>8)
#define PL_CFG0_get_pl4_ps(data)                                      ((0x000000F0&(data))>>4)
#define PL_CFG0_get_pl4_pd(data)                                      ((0x00000008&(data))>>3)
#define PL_CFG0_get_pl4_pu(data)                                      ((0x00000004&(data))>>2)
#define PL_CFG0_get_pl4_sr(data)                                      ((0x00000002&(data))>>1)
#define PL_CFG0_get_pl4_ds(data)                                      (0x00000001&(data))

#define PL_CFG1                                                       0x1800085c
#define PL_CFG1_reg_addr                                              "0xB800085C"
#define PL_CFG1_reg                                                   0xB800085C
#define PL_CFG1_inst_addr                                             "0x0217"
#define PL_CFG1_inst                                                  0x0217
#define PL_CFG1_pl3_ps_shift                                          (28)
#define PL_CFG1_pl3_pd_shift                                          (27)
#define PL_CFG1_pl3_pu_shift                                          (26)
#define PL_CFG1_pl3_sr_shift                                          (25)
#define PL_CFG1_pl3_ds_shift                                          (24)
#define PL_CFG1_pl2_ps_shift                                          (20)
#define PL_CFG1_pl2_pd_shift                                          (19)
#define PL_CFG1_pl2_pu_shift                                          (18)
#define PL_CFG1_pl2_sr_shift                                          (17)
#define PL_CFG1_pl2_ds_shift                                          (16)
#define PL_CFG1_pl1_ps_shift                                          (12)
#define PL_CFG1_pl1_pd_shift                                          (11)
#define PL_CFG1_pl1_pu_shift                                          (10)
#define PL_CFG1_pl1_sr_shift                                          (9)
#define PL_CFG1_pl1_ds_shift                                          (8)
#define PL_CFG1_pl0_ps_shift                                          (4)
#define PL_CFG1_pl0_pd_shift                                          (3)
#define PL_CFG1_pl0_pu_shift                                          (2)
#define PL_CFG1_pl0_sr_shift                                          (1)
#define PL_CFG1_pl0_ds_shift                                          (0)
#define PL_CFG1_pl3_ps_mask                                           (0xF0000000)
#define PL_CFG1_pl3_pd_mask                                           (0x08000000)
#define PL_CFG1_pl3_pu_mask                                           (0x04000000)
#define PL_CFG1_pl3_sr_mask                                           (0x02000000)
#define PL_CFG1_pl3_ds_mask                                           (0x01000000)
#define PL_CFG1_pl2_ps_mask                                           (0x00F00000)
#define PL_CFG1_pl2_pd_mask                                           (0x00080000)
#define PL_CFG1_pl2_pu_mask                                           (0x00040000)
#define PL_CFG1_pl2_sr_mask                                           (0x00020000)
#define PL_CFG1_pl2_ds_mask                                           (0x00010000)
#define PL_CFG1_pl1_ps_mask                                           (0x0000F000)
#define PL_CFG1_pl1_pd_mask                                           (0x00000800)
#define PL_CFG1_pl1_pu_mask                                           (0x00000400)
#define PL_CFG1_pl1_sr_mask                                           (0x00000200)
#define PL_CFG1_pl1_ds_mask                                           (0x00000100)
#define PL_CFG1_pl0_ps_mask                                           (0x000000F0)
#define PL_CFG1_pl0_pd_mask                                           (0x00000008)
#define PL_CFG1_pl0_pu_mask                                           (0x00000004)
#define PL_CFG1_pl0_sr_mask                                           (0x00000002)
#define PL_CFG1_pl0_ds_mask                                           (0x00000001)
#define PL_CFG1_pl3_ps(data)                                          (0xF0000000&((data)<<28))
#define PL_CFG1_pl3_pd(data)                                          (0x08000000&((data)<<27))
#define PL_CFG1_pl3_pu(data)                                          (0x04000000&((data)<<26))
#define PL_CFG1_pl3_sr(data)                                          (0x02000000&((data)<<25))
#define PL_CFG1_pl3_ds(data)                                          (0x01000000&((data)<<24))
#define PL_CFG1_pl2_ps(data)                                          (0x00F00000&((data)<<20))
#define PL_CFG1_pl2_pd(data)                                          (0x00080000&((data)<<19))
#define PL_CFG1_pl2_pu(data)                                          (0x00040000&((data)<<18))
#define PL_CFG1_pl2_sr(data)                                          (0x00020000&((data)<<17))
#define PL_CFG1_pl2_ds(data)                                          (0x00010000&((data)<<16))
#define PL_CFG1_pl1_ps(data)                                          (0x0000F000&((data)<<12))
#define PL_CFG1_pl1_pd(data)                                          (0x00000800&((data)<<11))
#define PL_CFG1_pl1_pu(data)                                          (0x00000400&((data)<<10))
#define PL_CFG1_pl1_sr(data)                                          (0x00000200&((data)<<9))
#define PL_CFG1_pl1_ds(data)                                          (0x00000100&((data)<<8))
#define PL_CFG1_pl0_ps(data)                                          (0x000000F0&((data)<<4))
#define PL_CFG1_pl0_pd(data)                                          (0x00000008&((data)<<3))
#define PL_CFG1_pl0_pu(data)                                          (0x00000004&((data)<<2))
#define PL_CFG1_pl0_sr(data)                                          (0x00000002&((data)<<1))
#define PL_CFG1_pl0_ds(data)                                          (0x00000001&(data))
#define PL_CFG1_get_pl3_ps(data)                                      ((0xF0000000&(data))>>28)
#define PL_CFG1_get_pl3_pd(data)                                      ((0x08000000&(data))>>27)
#define PL_CFG1_get_pl3_pu(data)                                      ((0x04000000&(data))>>26)
#define PL_CFG1_get_pl3_sr(data)                                      ((0x02000000&(data))>>25)
#define PL_CFG1_get_pl3_ds(data)                                      ((0x01000000&(data))>>24)
#define PL_CFG1_get_pl2_ps(data)                                      ((0x00F00000&(data))>>20)
#define PL_CFG1_get_pl2_pd(data)                                      ((0x00080000&(data))>>19)
#define PL_CFG1_get_pl2_pu(data)                                      ((0x00040000&(data))>>18)
#define PL_CFG1_get_pl2_sr(data)                                      ((0x00020000&(data))>>17)
#define PL_CFG1_get_pl2_ds(data)                                      ((0x00010000&(data))>>16)
#define PL_CFG1_get_pl1_ps(data)                                      ((0x0000F000&(data))>>12)
#define PL_CFG1_get_pl1_pd(data)                                      ((0x00000800&(data))>>11)
#define PL_CFG1_get_pl1_pu(data)                                      ((0x00000400&(data))>>10)
#define PL_CFG1_get_pl1_sr(data)                                      ((0x00000200&(data))>>9)
#define PL_CFG1_get_pl1_ds(data)                                      ((0x00000100&(data))>>8)
#define PL_CFG1_get_pl0_ps(data)                                      ((0x000000F0&(data))>>4)
#define PL_CFG1_get_pl0_pd(data)                                      ((0x00000008&(data))>>3)
#define PL_CFG1_get_pl0_pu(data)                                      ((0x00000004&(data))>>2)
#define PL_CFG1_get_pl0_sr(data)                                      ((0x00000002&(data))>>1)
#define PL_CFG1_get_pl0_ds(data)                                      (0x00000001&(data))

#define PM_CFG0                                                       0x18000860
#define PM_CFG0_reg_addr                                              "0xB8000860"
#define PM_CFG0_reg                                                   0xB8000860
#define PM_CFG0_inst_addr                                             "0x0218"
#define PM_CFG0_inst                                                  0x0218
#define PM_CFG0_pm7_ps_dummy_shift                                    (0)
#define PM_CFG0_pm7_ps_dummy_mask                                     (0xFFFFFFFF)
#define PM_CFG0_pm7_ps_dummy(data)                                    (0xFFFFFFFF&(data))
#define PM_CFG0_get_pm7_ps_dummy(data)                                (0xFFFFFFFF&(data))

#define PM_CFG1                                                       0x18000864
#define PM_CFG1_reg_addr                                              "0xB8000864"
#define PM_CFG1_reg                                                   0xB8000864
#define PM_CFG1_inst_addr                                             "0x0219"
#define PM_CFG1_inst                                                  0x0219

#define PN_CFG0                                                       0x18000868
#define PN_CFG0_reg_addr                                              "0xB8000868"
#define PN_CFG0_reg                                                   0xB8000868
#define PN_CFG0_inst_addr                                             "0x021A"
#define PN_CFG0_inst                                                  0x021A

#define PN_CFG1                                                       0x1800086c
#define PN_CFG1_reg_addr                                              "0xB800086C"
#define PN_CFG1_reg                                                   0xB800086C
#define PN_CFG1_inst_addr                                             "0x021B"
#define PN_CFG1_inst                                                  0x021B

#define PO_CFG0                                                       0x18000870
#define PO_CFG0_reg_addr                                              "0xB8000870"
#define PO_CFG0_reg                                                   0xB8000870
#define PO_CFG0_inst_addr                                             "0x021C"
#define PO_CFG0_inst                                                  0x021C

#define PO_CFG1                                                       0x18000874
#define PO_CFG1_reg_addr                                              "0xB8000874"
#define PO_CFG1_reg                                                   0xB8000874
#define PO_CFG1_inst_addr                                             "0x021D"
#define PO_CFG1_inst                                                  0x021D

#define PP_CFG0                                                       0x18000878
#define PP_CFG0_reg_addr                                              "0xB8000878"
#define PP_CFG0_reg                                                   0xB8000878
#define PP_CFG0_inst_addr                                             "0x021E"
#define PP_CFG0_inst                                                  0x021E

#define PP_CFG1                                                       0x1800087c
#define PP_CFG1_reg_addr                                              "0xB800087C"
#define PP_CFG1_reg                                                   0xB800087C
#define PP_CFG1_inst_addr                                             "0x021F"
#define PP_CFG1_inst                                                  0x021F

#define PQ_CFG0                                                       0x18000880
#define PQ_CFG0_reg_addr                                              "0xB8000880"
#define PQ_CFG0_reg                                                   0xB8000880
#define PQ_CFG0_inst_addr                                             "0x0220"
#define PQ_CFG0_inst                                                  0x0220

#define PQ_CFG1                                                       0x18000884
#define PQ_CFG1_reg_addr                                              "0xB8000884"
#define PQ_CFG1_reg                                                   0xB8000884
#define PQ_CFG1_inst_addr                                             "0x0221"
#define PQ_CFG1_inst                                                  0x0221

#define PS_CFG0                                                       0x18000890
#define PS_CFG0_reg_addr                                              "0xB8000890"
#define PS_CFG0_reg                                                   0xB8000890
#define PS_CFG0_inst_addr                                             "0x0224"
#define PS_CFG0_inst                                                  0x0224

#define PS_CFG1                                                       0x18000894
#define PS_CFG1_reg_addr                                              "0xB8000894"
#define PS_CFG1_reg                                                   0xB8000894
#define PS_CFG1_inst_addr                                             "0x0225"
#define PS_CFG1_inst                                                  0x0225
#define PS_CFG1_ps0_ds_shift                                          (0)
#define PS_CFG1_ps0_ds_mask                                           (0x00000001)
#define PS_CFG1_ps0_ds(data)                                          (0x00000001&(data))
#define PS_CFG1_get_ps0_ds(data)                                      (0x00000001&(data))

#define PT_CFG0                                                       0x18000898
#define PT_CFG0_reg_addr                                              "0xB8000898"
#define PT_CFG0_reg                                                   0xB8000898
#define PT_CFG0_inst_addr                                             "0x0226"
#define PT_CFG0_inst                                                  0x0226

#define PT_CFG1                                                       0x1800089c
#define PT_CFG1_reg_addr                                              "0xB800089C"
#define PT_CFG1_reg                                                   0xB800089C
#define PT_CFG1_inst_addr                                             "0x0227"
#define PT_CFG1_inst                                                  0x0227

#define PU_CFG0                                                       0x180008a0
#define PU_CFG0_reg_addr                                              "0xB80008A0"
#define PU_CFG0_reg                                                   0xB80008A0
#define PU_CFG0_inst_addr                                             "0x0228"
#define PU_CFG0_inst                                                  0x0228

#define PU_CFG1                                                       0x180008a4
#define PU_CFG1_reg_addr                                              "0xB80008A4"
#define PU_CFG1_reg                                                   0xB80008A4
#define PU_CFG1_inst_addr                                             "0x0229"
#define PU_CFG1_inst                                                  0x0229

#define PV_CFG0                                                       0x180008a8
#define PV_CFG0_reg_addr                                              "0xB80008A8"
#define PV_CFG0_reg                                                   0xB80008A8
#define PV_CFG0_inst_addr                                             "0x022A"
#define PV_CFG0_inst                                                  0x022A

#define PV_CFG1                                                       0x180008ac
#define PV_CFG1_reg_addr                                              "0xB80008AC"
#define PV_CFG1_reg                                                   0xB80008AC
#define PV_CFG1_inst_addr                                             "0x022B"
#define PV_CFG1_inst                                                  0x022B

#define PW_CFG0                                                       0x180008b0
#define PW_CFG0_reg_addr                                              "0xB80008B0"
#define PW_CFG0_reg                                                   0xB80008B0
#define PW_CFG0_inst_addr                                             "0x022C"
#define PW_CFG0_inst                                                  0x022C

#define PW_CFG1                                                       0x180008b4
#define PW_CFG1_reg_addr                                              "0xB80008B4"
#define PW_CFG1_reg                                                   0xB80008B4
#define PW_CFG1_inst_addr                                             "0x022D"
#define PW_CFG1_inst                                                  0x022D

#define PX_CFG0                                                       0x180008b8
#define PX_CFG0_reg_addr                                              "0xB80008B8"
#define PX_CFG0_reg                                                   0xB80008B8
#define PX_CFG0_inst_addr                                             "0x022E"
#define PX_CFG0_inst                                                  0x022E
#define PX_CFG0_px7_ps_shift                                          (28)
#define PX_CFG0_px7_pd_shift                                          (27)
#define PX_CFG0_px7_pu_shift                                          (26)
#define PX_CFG0_px7_sr_shift                                          (25)
#define PX_CFG0_px7_ds_shift                                          (24)
#define PX_CFG0_px6_pd_shift                                          (23)
#define PX_CFG0_px6_pu_shift                                          (22)
#define PX_CFG0_px6_sr_shift                                          (21)
#define PX_CFG0_px6_ds_shift                                          (20)
#define PX_CFG0_px5_pd_shift                                          (19)
#define PX_CFG0_px5_pu_shift                                          (18)
#define PX_CFG0_px5_sr_shift                                          (17)
#define PX_CFG0_px5_ds_shift                                          (16)
#define PX_CFG0_px4_pd_shift                                          (15)
#define PX_CFG0_px4_pu_shift                                          (14)
#define PX_CFG0_px4_sr_shift                                          (13)
#define PX_CFG0_px4_ds_shift                                          (12)
#define PX_CFG0_px3_pd_shift                                          (11)
#define PX_CFG0_px3_pu_shift                                          (10)
#define PX_CFG0_px3_sr_shift                                          (9)
#define PX_CFG0_px3_ds_shift                                          (8)
#define PX_CFG0_px2_pd_shift                                          (7)
#define PX_CFG0_px2_pu_shift                                          (6)
#define PX_CFG0_px2_sr_shift                                          (5)
#define PX_CFG0_px2_ds_shift                                          (4)
#define PX_CFG0_px1_pd_shift                                          (3)
#define PX_CFG0_px1_pu_shift                                          (2)
#define PX_CFG0_px1_sr_shift                                          (1)
#define PX_CFG0_px1_ds_shift                                          (0)
#define PX_CFG0_px7_ps_mask                                           (0xF0000000)
#define PX_CFG0_px7_pd_mask                                           (0x08000000)
#define PX_CFG0_px7_pu_mask                                           (0x04000000)
#define PX_CFG0_px7_sr_mask                                           (0x02000000)
#define PX_CFG0_px7_ds_mask                                           (0x01000000)
#define PX_CFG0_px6_pd_mask                                           (0x00800000)
#define PX_CFG0_px6_pu_mask                                           (0x00400000)
#define PX_CFG0_px6_sr_mask                                           (0x00200000)
#define PX_CFG0_px6_ds_mask                                           (0x00100000)
#define PX_CFG0_px5_pd_mask                                           (0x00080000)
#define PX_CFG0_px5_pu_mask                                           (0x00040000)
#define PX_CFG0_px5_sr_mask                                           (0x00020000)
#define PX_CFG0_px5_ds_mask                                           (0x00010000)
#define PX_CFG0_px4_pd_mask                                           (0x00008000)
#define PX_CFG0_px4_pu_mask                                           (0x00004000)
#define PX_CFG0_px4_sr_mask                                           (0x00002000)
#define PX_CFG0_px4_ds_mask                                           (0x00001000)
#define PX_CFG0_px3_pd_mask                                           (0x00000800)
#define PX_CFG0_px3_pu_mask                                           (0x00000400)
#define PX_CFG0_px3_sr_mask                                           (0x00000200)
#define PX_CFG0_px3_ds_mask                                           (0x00000100)
#define PX_CFG0_px2_pd_mask                                           (0x00000080)
#define PX_CFG0_px2_pu_mask                                           (0x00000040)
#define PX_CFG0_px2_sr_mask                                           (0x00000020)
#define PX_CFG0_px2_ds_mask                                           (0x00000010)
#define PX_CFG0_px1_pd_mask                                           (0x00000008)
#define PX_CFG0_px1_pu_mask                                           (0x00000004)
#define PX_CFG0_px1_sr_mask                                           (0x00000002)
#define PX_CFG0_px1_ds_mask                                           (0x00000001)
#define PX_CFG0_px7_ps(data)                                          (0xF0000000&((data)<<28))
#define PX_CFG0_px7_pd(data)                                          (0x08000000&((data)<<27))
#define PX_CFG0_px7_pu(data)                                          (0x04000000&((data)<<26))
#define PX_CFG0_px7_sr(data)                                          (0x02000000&((data)<<25))
#define PX_CFG0_px7_ds(data)                                          (0x01000000&((data)<<24))
#define PX_CFG0_px6_pd(data)                                          (0x00800000&((data)<<23))
#define PX_CFG0_px6_pu(data)                                          (0x00400000&((data)<<22))
#define PX_CFG0_px6_sr(data)                                          (0x00200000&((data)<<21))
#define PX_CFG0_px6_ds(data)                                          (0x00100000&((data)<<20))
#define PX_CFG0_px5_pd(data)                                          (0x00080000&((data)<<19))
#define PX_CFG0_px5_pu(data)                                          (0x00040000&((data)<<18))
#define PX_CFG0_px5_sr(data)                                          (0x00020000&((data)<<17))
#define PX_CFG0_px5_ds(data)                                          (0x00010000&((data)<<16))
#define PX_CFG0_px4_pd(data)                                          (0x00008000&((data)<<15))
#define PX_CFG0_px4_pu(data)                                          (0x00004000&((data)<<14))
#define PX_CFG0_px4_sr(data)                                          (0x00002000&((data)<<13))
#define PX_CFG0_px4_ds(data)                                          (0x00001000&((data)<<12))
#define PX_CFG0_px3_pd(data)                                          (0x00000800&((data)<<11))
#define PX_CFG0_px3_pu(data)                                          (0x00000400&((data)<<10))
#define PX_CFG0_px3_sr(data)                                          (0x00000200&((data)<<9))
#define PX_CFG0_px3_ds(data)                                          (0x00000100&((data)<<8))
#define PX_CFG0_px2_pd(data)                                          (0x00000080&((data)<<7))
#define PX_CFG0_px2_pu(data)                                          (0x00000040&((data)<<6))
#define PX_CFG0_px2_sr(data)                                          (0x00000020&((data)<<5))
#define PX_CFG0_px2_ds(data)                                          (0x00000010&((data)<<4))
#define PX_CFG0_px1_pd(data)                                          (0x00000008&((data)<<3))
#define PX_CFG0_px1_pu(data)                                          (0x00000004&((data)<<2))
#define PX_CFG0_px1_sr(data)                                          (0x00000002&((data)<<1))
#define PX_CFG0_px1_ds(data)                                          (0x00000001&(data))
#define PX_CFG0_get_px7_ps(data)                                      ((0xF0000000&(data))>>28)
#define PX_CFG0_get_px7_pd(data)                                      ((0x08000000&(data))>>27)
#define PX_CFG0_get_px7_pu(data)                                      ((0x04000000&(data))>>26)
#define PX_CFG0_get_px7_sr(data)                                      ((0x02000000&(data))>>25)
#define PX_CFG0_get_px7_ds(data)                                      ((0x01000000&(data))>>24)
#define PX_CFG0_get_px6_pd(data)                                      ((0x00800000&(data))>>23)
#define PX_CFG0_get_px6_pu(data)                                      ((0x00400000&(data))>>22)
#define PX_CFG0_get_px6_sr(data)                                      ((0x00200000&(data))>>21)
#define PX_CFG0_get_px6_ds(data)                                      ((0x00100000&(data))>>20)
#define PX_CFG0_get_px5_pd(data)                                      ((0x00080000&(data))>>19)
#define PX_CFG0_get_px5_pu(data)                                      ((0x00040000&(data))>>18)
#define PX_CFG0_get_px5_sr(data)                                      ((0x00020000&(data))>>17)
#define PX_CFG0_get_px5_ds(data)                                      ((0x00010000&(data))>>16)
#define PX_CFG0_get_px4_pd(data)                                      ((0x00008000&(data))>>15)
#define PX_CFG0_get_px4_pu(data)                                      ((0x00004000&(data))>>14)
#define PX_CFG0_get_px4_sr(data)                                      ((0x00002000&(data))>>13)
#define PX_CFG0_get_px4_ds(data)                                      ((0x00001000&(data))>>12)
#define PX_CFG0_get_px3_pd(data)                                      ((0x00000800&(data))>>11)
#define PX_CFG0_get_px3_pu(data)                                      ((0x00000400&(data))>>10)
#define PX_CFG0_get_px3_sr(data)                                      ((0x00000200&(data))>>9)
#define PX_CFG0_get_px3_ds(data)                                      ((0x00000100&(data))>>8)
#define PX_CFG0_get_px2_pd(data)                                      ((0x00000080&(data))>>7)
#define PX_CFG0_get_px2_pu(data)                                      ((0x00000040&(data))>>6)
#define PX_CFG0_get_px2_sr(data)                                      ((0x00000020&(data))>>5)
#define PX_CFG0_get_px2_ds(data)                                      ((0x00000010&(data))>>4)
#define PX_CFG0_get_px1_pd(data)                                      ((0x00000008&(data))>>3)
#define PX_CFG0_get_px1_pu(data)                                      ((0x00000004&(data))>>2)
#define PX_CFG0_get_px1_sr(data)                                      ((0x00000002&(data))>>1)
#define PX_CFG0_get_px1_ds(data)                                      (0x00000001&(data))

#define PXY_CFG1                                                      0x180008bc
#define PXY_CFG1_reg_addr                                             "0xB80008BC"
#define PXY_CFG1_reg                                                  0xB80008BC
#define PXY_CFG1_inst_addr                                            "0x022F"
#define PXY_CFG1_inst                                                 0x022F
#define PXY_CFG1_px0_pd_shift                                         (31)
#define PXY_CFG1_px0_pu_shift                                         (30)
#define PXY_CFG1_px0_sr_shift                                         (29)
#define PXY_CFG1_px0_ds_shift                                         (28)
#define PXY_CFG1_avs0_pd1_ps_shift                                    (24)
#define PXY_CFG1_avs0_pd1_pd_shift                                    (23)
#define PXY_CFG1_avs0_pd1_pu_shift                                    (22)
#define PXY_CFG1_avs0_pd1_sr_shift                                    (21)
#define PXY_CFG1_avs0_pd1_ds_shift                                    (20)
#define PXY_CFG1_lvdspll_wll_shift                                    (7)
#define PXY_CFG1_boption_status_shift                                 (0)
#define PXY_CFG1_px0_pd_mask                                          (0x80000000)
#define PXY_CFG1_px0_pu_mask                                          (0x40000000)
#define PXY_CFG1_px0_sr_mask                                          (0x20000000)
#define PXY_CFG1_px0_ds_mask                                          (0x10000000)
#define PXY_CFG1_avs0_pd1_ps_mask                                     (0x07000000)
#define PXY_CFG1_avs0_pd1_pd_mask                                     (0x00800000)
#define PXY_CFG1_avs0_pd1_pu_mask                                     (0x00400000)
#define PXY_CFG1_avs0_pd1_sr_mask                                     (0x00200000)
#define PXY_CFG1_avs0_pd1_ds_mask                                     (0x00100000)
#define PXY_CFG1_lvdspll_wll_mask                                     (0x00000080)
#define PXY_CFG1_boption_status_mask                                  (0x0000000F)
#define PXY_CFG1_px0_pd(data)                                         (0x80000000&((data)<<31))
#define PXY_CFG1_px0_pu(data)                                         (0x40000000&((data)<<30))
#define PXY_CFG1_px0_sr(data)                                         (0x20000000&((data)<<29))
#define PXY_CFG1_px0_ds(data)                                         (0x10000000&((data)<<28))
#define PXY_CFG1_avs0_pd1_ps(data)                                    (0x07000000&((data)<<24))
#define PXY_CFG1_avs0_pd1_pd(data)                                    (0x00800000&((data)<<23))
#define PXY_CFG1_avs0_pd1_pu(data)                                    (0x00400000&((data)<<22))
#define PXY_CFG1_avs0_pd1_sr(data)                                    (0x00200000&((data)<<21))
#define PXY_CFG1_avs0_pd1_ds(data)                                    (0x00100000&((data)<<20))
#define PXY_CFG1_lvdspll_wll(data)                                    (0x00000080&((data)<<7))
#define PXY_CFG1_boption_status(data)                                 (0x0000000F&(data))
#define PXY_CFG1_get_px0_pd(data)                                     ((0x80000000&(data))>>31)
#define PXY_CFG1_get_px0_pu(data)                                     ((0x40000000&(data))>>30)
#define PXY_CFG1_get_px0_sr(data)                                     ((0x20000000&(data))>>29)
#define PXY_CFG1_get_px0_ds(data)                                     ((0x10000000&(data))>>28)
#define PXY_CFG1_get_avs0_pd1_ps(data)                                ((0x07000000&(data))>>24)
#define PXY_CFG1_get_avs0_pd1_pd(data)                                ((0x00800000&(data))>>23)
#define PXY_CFG1_get_avs0_pd1_pu(data)                                ((0x00400000&(data))>>22)
#define PXY_CFG1_get_avs0_pd1_sr(data)                                ((0x00200000&(data))>>21)
#define PXY_CFG1_get_avs0_pd1_ds(data)                                ((0x00100000&(data))>>20)
#define PXY_CFG1_get_lvdspll_wll(data)                                ((0x00000080&(data))>>7)
#define PXY_CFG1_get_boption_status(data)                             (0x0000000F&(data))

#define PIN_MUX_CTRL0                                                 0x180008c0
#define PIN_MUX_CTRL0_reg_addr                                        "0xB80008C0"
#define PIN_MUX_CTRL0_reg                                             0xB80008C0
#define PIN_MUX_CTRL0_inst_addr                                       "0x0230"
#define PIN_MUX_CTRL0_inst                                            0x0230
#define PIN_MUX_CTRL0_v10_sel_shift                                   (31)
#define PIN_MUX_CTRL0_usb_host_ctrl_sel_shift                         (30)
#define PIN_MUX_CTRL0_i2c_m_sel_shift                                 (29)
#define PIN_MUX_CTRL0_i2c_s_sel_shift                                 (28)
#define PIN_MUX_CTRL0_i2c_0_sel_shift                                 (26)
#define PIN_MUX_CTRL0_i2c_1_sel_shift                                 (24)
#define PIN_MUX_CTRL0_spdif_out_sel_dummy_shift                       (20)
#define PIN_MUX_CTRL0_spdif_in_sel_shift                              (16)
#define PIN_MUX_CTRL0_irtx_sel_dummy_shift                            (12)
#define PIN_MUX_CTRL0_irda_rx_sel_shift                               (8)
#define PIN_MUX_CTRL0_ifagc_sel_shift                                 (7)
#define PIN_MUX_CTRL0_uart_2_sel_shift                                (4)
#define PIN_MUX_CTRL0_uart_1_sel_shift                                (0)
#define PIN_MUX_CTRL0_v10_sel_mask                                    (0x80000000)
#define PIN_MUX_CTRL0_usb_host_ctrl_sel_mask                          (0x40000000)
#define PIN_MUX_CTRL0_i2c_m_sel_mask                                  (0x20000000)
#define PIN_MUX_CTRL0_i2c_s_sel_mask                                  (0x10000000)
#define PIN_MUX_CTRL0_i2c_0_sel_mask                                  (0x0C000000)
#define PIN_MUX_CTRL0_i2c_1_sel_mask                                  (0x03000000)
#define PIN_MUX_CTRL0_spdif_out_sel_dummy_mask                        (0x00F00000)
#define PIN_MUX_CTRL0_spdif_in_sel_mask                               (0x000F0000)
#define PIN_MUX_CTRL0_irtx_sel_dummy_mask                             (0x0000F000)
#define PIN_MUX_CTRL0_irda_rx_sel_mask                                (0x00000F00)
#define PIN_MUX_CTRL0_ifagc_sel_mask                                  (0x00000080)
#define PIN_MUX_CTRL0_uart_2_sel_mask                                 (0x00000070)
#define PIN_MUX_CTRL0_uart_1_sel_mask                                 (0x00000007)
#define PIN_MUX_CTRL0_v10_sel(data)                                   (0x80000000&((data)<<31))
#define PIN_MUX_CTRL0_usb_host_ctrl_sel(data)                         (0x40000000&((data)<<30))
#define PIN_MUX_CTRL0_i2c_m_sel(data)                                 (0x20000000&((data)<<29))
#define PIN_MUX_CTRL0_i2c_s_sel(data)                                 (0x10000000&((data)<<28))
#define PIN_MUX_CTRL0_i2c_0_sel(data)                                 (0x0C000000&((data)<<26))
#define PIN_MUX_CTRL0_i2c_1_sel(data)                                 (0x03000000&((data)<<24))
#define PIN_MUX_CTRL0_spdif_out_sel_dummy(data)                       (0x00F00000&((data)<<20))
#define PIN_MUX_CTRL0_spdif_in_sel(data)                              (0x000F0000&((data)<<16))
#define PIN_MUX_CTRL0_irtx_sel_dummy(data)                            (0x0000F000&((data)<<12))
#define PIN_MUX_CTRL0_irda_rx_sel(data)                               (0x00000F00&((data)<<8))
#define PIN_MUX_CTRL0_ifagc_sel(data)                                 (0x00000080&((data)<<7))
#define PIN_MUX_CTRL0_uart_2_sel(data)                                (0x00000070&((data)<<4))
#define PIN_MUX_CTRL0_uart_1_sel(data)                                (0x00000007&(data))
#define PIN_MUX_CTRL0_get_v10_sel(data)                               ((0x80000000&(data))>>31)
#define PIN_MUX_CTRL0_get_usb_host_ctrl_sel(data)                     ((0x40000000&(data))>>30)
#define PIN_MUX_CTRL0_get_i2c_m_sel(data)                             ((0x20000000&(data))>>29)
#define PIN_MUX_CTRL0_get_i2c_s_sel(data)                             ((0x10000000&(data))>>28)
#define PIN_MUX_CTRL0_get_i2c_0_sel(data)                             ((0x0C000000&(data))>>26)
#define PIN_MUX_CTRL0_get_i2c_1_sel(data)                             ((0x03000000&(data))>>24)
#define PIN_MUX_CTRL0_get_spdif_out_sel_dummy(data)                   ((0x00F00000&(data))>>20)
#define PIN_MUX_CTRL0_get_spdif_in_sel(data)                          ((0x000F0000&(data))>>16)
#define PIN_MUX_CTRL0_get_irtx_sel_dummy(data)                        ((0x0000F000&(data))>>12)
#define PIN_MUX_CTRL0_get_irda_rx_sel(data)                           ((0x00000F00&(data))>>8)
#define PIN_MUX_CTRL0_get_ifagc_sel(data)                             ((0x00000080&(data))>>7)
#define PIN_MUX_CTRL0_get_uart_2_sel(data)                            ((0x00000070&(data))>>4)
#define PIN_MUX_CTRL0_get_uart_1_sel(data)                            (0x00000007&(data))

#define PIN_MUX_CTRL1                                                 0x180008c4
#define PIN_MUX_CTRL1_reg_addr                                        "0xB80008C4"
#define PIN_MUX_CTRL1_reg                                             0xB80008C4
#define PIN_MUX_CTRL1_inst_addr                                       "0x0231"
#define PIN_MUX_CTRL1_inst                                            0x0231
#define PIN_MUX_CTRL1_i2s_i_mclk_sel_shift                            (30)
#define PIN_MUX_CTRL1_i2s_i_clk_sel_shift                             (28)
#define PIN_MUX_CTRL1_i2s_i_ws_sel_shift                              (26)
#define PIN_MUX_CTRL1_i2s_i_data0_sel_shift                           (24)
#define PIN_MUX_CTRL1_i2s_i_data1_sel_shift                           (22)
#define PIN_MUX_CTRL1_i2s_i_data2_sel_shift                           (20)
#define PIN_MUX_CTRL1_i2s_i_data3_sel_shift                           (19)
#define PIN_MUX_CTRL1_i2s_o_data0_sel_dummy_shift                     (18)
#define PIN_MUX_CTRL1_i2s_o_data1_sel_dummy_shift                     (17)
#define PIN_MUX_CTRL1_i2s_o_data2_sel_dummy_shift                     (15)
#define PIN_MUX_CTRL1_i2s_o_data3_sel_dummy_shift                     (14)
#define PIN_MUX_CTRL1_pcm_dummy_shift                                 (8)
#define PIN_MUX_CTRL1_pcm_mclk_in_sel_shift                           (6)
#define PIN_MUX_CTRL1_pcm_data_in_sel_shift                           (4)
#define PIN_MUX_CTRL1_pcm_sync_in_sel_shift                           (2)
#define PIN_MUX_CTRL1_pcm_clk_in_sel_shift                            (0)
#define PIN_MUX_CTRL1_i2s_i_mclk_sel_mask                             (0xC0000000)
#define PIN_MUX_CTRL1_i2s_i_clk_sel_mask                              (0x30000000)
#define PIN_MUX_CTRL1_i2s_i_ws_sel_mask                               (0x0C000000)
#define PIN_MUX_CTRL1_i2s_i_data0_sel_mask                            (0x03000000)
#define PIN_MUX_CTRL1_i2s_i_data1_sel_mask                            (0x00C00000)
#define PIN_MUX_CTRL1_i2s_i_data2_sel_mask                            (0x00300000)
#define PIN_MUX_CTRL1_i2s_i_data3_sel_mask                            (0x00080000)
#define PIN_MUX_CTRL1_i2s_o_data0_sel_dummy_mask                      (0x00040000)
#define PIN_MUX_CTRL1_i2s_o_data1_sel_dummy_mask                      (0x00020000)
#define PIN_MUX_CTRL1_i2s_o_data2_sel_dummy_mask                      (0x00018000)
#define PIN_MUX_CTRL1_i2s_o_data3_sel_dummy_mask                      (0x00004000)
#define PIN_MUX_CTRL1_pcm_dummy_mask                                  (0x00003F00)
#define PIN_MUX_CTRL1_pcm_mclk_in_sel_mask                            (0x000000C0)
#define PIN_MUX_CTRL1_pcm_data_in_sel_mask                            (0x00000030)
#define PIN_MUX_CTRL1_pcm_sync_in_sel_mask                            (0x0000000C)
#define PIN_MUX_CTRL1_pcm_clk_in_sel_mask                             (0x00000003)
#define PIN_MUX_CTRL1_i2s_i_mclk_sel(data)                            (0xC0000000&((data)<<30))
#define PIN_MUX_CTRL1_i2s_i_clk_sel(data)                             (0x30000000&((data)<<28))
#define PIN_MUX_CTRL1_i2s_i_ws_sel(data)                              (0x0C000000&((data)<<26))
#define PIN_MUX_CTRL1_i2s_i_data0_sel(data)                           (0x03000000&((data)<<24))
#define PIN_MUX_CTRL1_i2s_i_data1_sel(data)                           (0x00C00000&((data)<<22))
#define PIN_MUX_CTRL1_i2s_i_data2_sel(data)                           (0x00300000&((data)<<20))
#define PIN_MUX_CTRL1_i2s_i_data3_sel(data)                           (0x00080000&((data)<<19))
#define PIN_MUX_CTRL1_i2s_o_data0_sel_dummy(data)                     (0x00040000&((data)<<18))
#define PIN_MUX_CTRL1_i2s_o_data1_sel_dummy(data)                     (0x00020000&((data)<<17))
#define PIN_MUX_CTRL1_i2s_o_data2_sel_dummy(data)                     (0x00018000&((data)<<15))
#define PIN_MUX_CTRL1_i2s_o_data3_sel_dummy(data)                     (0x00004000&((data)<<14))
#define PIN_MUX_CTRL1_pcm_dummy(data)                                 (0x00003F00&((data)<<8))
#define PIN_MUX_CTRL1_pcm_mclk_in_sel(data)                           (0x000000C0&((data)<<6))
#define PIN_MUX_CTRL1_pcm_data_in_sel(data)                           (0x00000030&((data)<<4))
#define PIN_MUX_CTRL1_pcm_sync_in_sel(data)                           (0x0000000C&((data)<<2))
#define PIN_MUX_CTRL1_pcm_clk_in_sel(data)                            (0x00000003&(data))
#define PIN_MUX_CTRL1_get_i2s_i_mclk_sel(data)                        ((0xC0000000&(data))>>30)
#define PIN_MUX_CTRL1_get_i2s_i_clk_sel(data)                         ((0x30000000&(data))>>28)
#define PIN_MUX_CTRL1_get_i2s_i_ws_sel(data)                          ((0x0C000000&(data))>>26)
#define PIN_MUX_CTRL1_get_i2s_i_data0_sel(data)                       ((0x03000000&(data))>>24)
#define PIN_MUX_CTRL1_get_i2s_i_data1_sel(data)                       ((0x00C00000&(data))>>22)
#define PIN_MUX_CTRL1_get_i2s_i_data2_sel(data)                       ((0x00300000&(data))>>20)
#define PIN_MUX_CTRL1_get_i2s_i_data3_sel(data)                       ((0x00080000&(data))>>19)
#define PIN_MUX_CTRL1_get_i2s_o_data0_sel_dummy(data)                 ((0x00040000&(data))>>18)
#define PIN_MUX_CTRL1_get_i2s_o_data1_sel_dummy(data)                 ((0x00020000&(data))>>17)
#define PIN_MUX_CTRL1_get_i2s_o_data2_sel_dummy(data)                 ((0x00018000&(data))>>15)
#define PIN_MUX_CTRL1_get_i2s_o_data3_sel_dummy(data)                 ((0x00004000&(data))>>14)
#define PIN_MUX_CTRL1_get_pcm_dummy(data)                             ((0x00003F00&(data))>>8)
#define PIN_MUX_CTRL1_get_pcm_mclk_in_sel(data)                       ((0x000000C0&(data))>>6)
#define PIN_MUX_CTRL1_get_pcm_data_in_sel(data)                       ((0x00000030&(data))>>4)
#define PIN_MUX_CTRL1_get_pcm_sync_in_sel(data)                       ((0x0000000C&(data))>>2)
#define PIN_MUX_CTRL1_get_pcm_clk_in_sel(data)                        (0x00000003&(data))

#define PIN_MUX_CTRL2                                                 0x180008c8
#define PIN_MUX_CTRL2_reg_addr                                        "0xB80008C8"
#define PIN_MUX_CTRL2_reg                                             0xB80008C8
#define PIN_MUX_CTRL2_inst_addr                                       "0x0232"
#define PIN_MUX_CTRL2_inst                                            0x0232
#define PIN_MUX_CTRL2_pin_mux_cfg2_dummy_shift                        (0)
#define PIN_MUX_CTRL2_pin_mux_cfg2_dummy_mask                         (0xFFFFFFFF)
#define PIN_MUX_CTRL2_pin_mux_cfg2_dummy(data)                        (0xFFFFFFFF&(data))
#define PIN_MUX_CTRL2_get_pin_mux_cfg2_dummy(data)                    (0xFFFFFFFF&(data))

#define GPI_SEL_0                                                     0x18000900
#define GPI_SEL_0_reg_addr                                            "0xB8000900"
#define GPI_SEL_0_reg                                                 0xB8000900
#define GPI_SEL_0_inst_addr                                           "0x0240"
#define GPI_SEL_0_inst                                                0x0240

#define GPI_SEL_1                                                     0x18000904
#define GPI_SEL_1_reg_addr                                            "0xB8000904"
#define GPI_SEL_1_reg                                                 0xB8000904
#define GPI_SEL_1_inst_addr                                           "0x0241"
#define GPI_SEL_1_inst                                                0x0241

#define GPI_SEL_2                                                     0x18000908
#define GPI_SEL_2_reg_addr                                            "0xB8000908"
#define GPI_SEL_2_reg                                                 0xB8000908
#define GPI_SEL_2_inst_addr                                           "0x0242"
#define GPI_SEL_2_inst                                                0x0242

#define GPI_SEL_3                                                     0x1800090c
#define GPI_SEL_3_reg_addr                                            "0xB800090C"
#define GPI_SEL_3_reg                                                 0xB800090C
#define GPI_SEL_3_inst_addr                                           "0x0243"
#define GPI_SEL_3_inst                                                0x0243

#define TEST_PIN_CTRL                                                 0x18000910
#define TEST_PIN_CTRL_reg_addr                                        "0xB8000910"
#define TEST_PIN_CTRL_reg                                             0xB8000910
#define TEST_PIN_CTRL_inst_addr                                       "0x0244"
#define TEST_PIN_CTRL_inst                                            0x0244
#define TEST_PIN_CTRL_force_normal_shift                              (0)
#define TEST_PIN_CTRL_force_normal_mask                               (0xFFFFFFFF)
#define TEST_PIN_CTRL_force_normal(data)                              (0xFFFFFFFF&(data))
#define TEST_PIN_CTRL_get_force_normal(data)                          (0xFFFFFFFF&(data))

#define TEST_PIN_MUX                                                  0x18000914
#define TEST_PIN_MUX_reg_addr                                         "0xB8000914"
#define TEST_PIN_MUX_reg                                              0xB8000914
#define TEST_PIN_MUX_inst_addr                                        "0x0245"
#define TEST_PIN_MUX_inst                                             0x0245
#define TEST_PIN_MUX_testpin_mux_shift                                (0)
#define TEST_PIN_MUX_testpin_mux_mask                                 (0x0000001F)
#define TEST_PIN_MUX_testpin_mux(data)                                (0x0000001F&(data))
#define TEST_PIN_MUX_get_testpin_mux(data)                            (0x0000001F&(data))

#define LVDS_PWR_CTRL0                                                0x1800091c
#define LVDS_PWR_CTRL0_reg_addr                                       "0xB800091C"
#define LVDS_PWR_CTRL0_reg                                            0xB800091C
#define LVDS_PWR_CTRL0_inst_addr                                      "0x0247"
#define LVDS_PWR_CTRL0_inst                                           0x0247
#define LVDS_PWR_CTRL0_apowl_shift                                    (24)
#define LVDS_PWR_CTRL0_bpowl_shift                                    (16)
#define LVDS_PWR_CTRL0_ibpowl_shift                                   (2)
#define LVDS_PWR_CTRL0_pllpowl_shift                                  (1)
#define LVDS_PWR_CTRL0_apowl_mask                                     (0x3F000000)
#define LVDS_PWR_CTRL0_bpowl_mask                                     (0x003F0000)
#define LVDS_PWR_CTRL0_ibpowl_mask                                    (0x00000004)
#define LVDS_PWR_CTRL0_pllpowl_mask                                   (0x00000002)
#define LVDS_PWR_CTRL0_apowl(data)                                    (0x3F000000&((data)<<24))
#define LVDS_PWR_CTRL0_bpowl(data)                                    (0x003F0000&((data)<<16))
#define LVDS_PWR_CTRL0_ibpowl(data)                                   (0x00000004&((data)<<2))
#define LVDS_PWR_CTRL0_pllpowl(data)                                  (0x00000002&((data)<<1))
#define LVDS_PWR_CTRL0_get_apowl(data)                                ((0x3F000000&(data))>>24)
#define LVDS_PWR_CTRL0_get_bpowl(data)                                ((0x003F0000&(data))>>16)
#define LVDS_PWR_CTRL0_get_ibpowl(data)                               ((0x00000004&(data))>>2)
#define LVDS_PWR_CTRL0_get_pllpowl(data)                              ((0x00000002&(data))>>1)

#define LVDS_PWR_CTRL2                                                0x18000924
#define LVDS_PWR_CTRL2_reg_addr                                       "0xB8000924"
#define LVDS_PWR_CTRL2_reg                                            0xB8000924
#define LVDS_PWR_CTRL2_inst_addr                                      "0x0249"
#define LVDS_PWR_CTRL2_inst                                           0x0249
#define LVDS_PWR_CTRL2_sttlil_shift                                   (31)
#define LVDS_PWR_CTRL2_slvdsil_shift                                  (29)
#define LVDS_PWR_CTRL2_svocml_shift                                   (26)
#define LVDS_PWR_CTRL2_spllil_shift                                   (23)
#define LVDS_PWR_CTRL2_spllrl_shift                                   (21)
#define LVDS_PWR_CTRL2_wdmodel_shift                                  (19)
#define LVDS_PWR_CTRL2_pllpolarl_shift                                (18)
#define LVDS_PWR_CTRL2_ststil_shift                                   (15)
#define LVDS_PWR_CTRL2_sibgenl_shift                                  (12)
#define LVDS_PWR_CTRL2_sbgl_shift                                     (10)
#define LVDS_PWR_CTRL2_sibxl_shift                                    (9)
#define LVDS_PWR_CTRL2_enib40ux2l_shift                               (8)
#define LVDS_PWR_CTRL2_aackpolarl_shift                               (7)
#define LVDS_PWR_CTRL2_abckpolarl_shift                               (6)
#define LVDS_PWR_CTRL2_acckpolarl_shift                               (5)
#define LVDS_PWR_CTRL2_adckpolarl_shift                               (4)
#define LVDS_PWR_CTRL2_aeckpolarl_shift                               (3)
#define LVDS_PWR_CTRL2_afckpolarl_shift                               (2)
#define LVDS_PWR_CTRL2_backpolarl_shift                               (1)
#define LVDS_PWR_CTRL2_bbckpolarl_shift                               (0)
#define LVDS_PWR_CTRL2_sttlil_mask                                    (0x80000000)
#define LVDS_PWR_CTRL2_slvdsil_mask                                   (0x60000000)
#define LVDS_PWR_CTRL2_svocml_mask                                    (0x1C000000)
#define LVDS_PWR_CTRL2_spllil_mask                                    (0x03800000)
#define LVDS_PWR_CTRL2_spllrl_mask                                    (0x00600000)
#define LVDS_PWR_CTRL2_wdmodel_mask                                   (0x00180000)
#define LVDS_PWR_CTRL2_pllpolarl_mask                                 (0x00040000)
#define LVDS_PWR_CTRL2_ststil_mask                                    (0x00038000)
#define LVDS_PWR_CTRL2_sibgenl_mask                                   (0x00007000)
#define LVDS_PWR_CTRL2_sbgl_mask                                      (0x00000C00)
#define LVDS_PWR_CTRL2_sibxl_mask                                     (0x00000200)
#define LVDS_PWR_CTRL2_enib40ux2l_mask                                (0x00000100)
#define LVDS_PWR_CTRL2_aackpolarl_mask                                (0x00000080)
#define LVDS_PWR_CTRL2_abckpolarl_mask                                (0x00000040)
#define LVDS_PWR_CTRL2_acckpolarl_mask                                (0x00000020)
#define LVDS_PWR_CTRL2_adckpolarl_mask                                (0x00000010)
#define LVDS_PWR_CTRL2_aeckpolarl_mask                                (0x00000008)
#define LVDS_PWR_CTRL2_afckpolarl_mask                                (0x00000004)
#define LVDS_PWR_CTRL2_backpolarl_mask                                (0x00000002)
#define LVDS_PWR_CTRL2_bbckpolarl_mask                                (0x00000001)
#define LVDS_PWR_CTRL2_sttlil(data)                                   (0x80000000&((data)<<31))
#define LVDS_PWR_CTRL2_slvdsil(data)                                  (0x60000000&((data)<<29))
#define LVDS_PWR_CTRL2_svocml(data)                                   (0x1C000000&((data)<<26))
#define LVDS_PWR_CTRL2_spllil(data)                                   (0x03800000&((data)<<23))
#define LVDS_PWR_CTRL2_spllrl(data)                                   (0x00600000&((data)<<21))
#define LVDS_PWR_CTRL2_wdmodel(data)                                  (0x00180000&((data)<<19))
#define LVDS_PWR_CTRL2_pllpolarl(data)                                (0x00040000&((data)<<18))
#define LVDS_PWR_CTRL2_ststil(data)                                   (0x00038000&((data)<<15))
#define LVDS_PWR_CTRL2_sibgenl(data)                                  (0x00007000&((data)<<12))
#define LVDS_PWR_CTRL2_sbgl(data)                                     (0x00000C00&((data)<<10))
#define LVDS_PWR_CTRL2_sibxl(data)                                    (0x00000200&((data)<<9))
#define LVDS_PWR_CTRL2_enib40ux2l(data)                               (0x00000100&((data)<<8))
#define LVDS_PWR_CTRL2_aackpolarl(data)                               (0x00000080&((data)<<7))
#define LVDS_PWR_CTRL2_abckpolarl(data)                               (0x00000040&((data)<<6))
#define LVDS_PWR_CTRL2_acckpolarl(data)                               (0x00000020&((data)<<5))
#define LVDS_PWR_CTRL2_adckpolarl(data)                               (0x00000010&((data)<<4))
#define LVDS_PWR_CTRL2_aeckpolarl(data)                               (0x00000008&((data)<<3))
#define LVDS_PWR_CTRL2_afckpolarl(data)                               (0x00000004&((data)<<2))
#define LVDS_PWR_CTRL2_backpolarl(data)                               (0x00000002&((data)<<1))
#define LVDS_PWR_CTRL2_bbckpolarl(data)                               (0x00000001&(data))
#define LVDS_PWR_CTRL2_get_sttlil(data)                               ((0x80000000&(data))>>31)
#define LVDS_PWR_CTRL2_get_slvdsil(data)                              ((0x60000000&(data))>>29)
#define LVDS_PWR_CTRL2_get_svocml(data)                               ((0x1C000000&(data))>>26)
#define LVDS_PWR_CTRL2_get_spllil(data)                               ((0x03800000&(data))>>23)
#define LVDS_PWR_CTRL2_get_spllrl(data)                               ((0x00600000&(data))>>21)
#define LVDS_PWR_CTRL2_get_wdmodel(data)                              ((0x00180000&(data))>>19)
#define LVDS_PWR_CTRL2_get_pllpolarl(data)                            ((0x00040000&(data))>>18)
#define LVDS_PWR_CTRL2_get_ststil(data)                               ((0x00038000&(data))>>15)
#define LVDS_PWR_CTRL2_get_sibgenl(data)                              ((0x00007000&(data))>>12)
#define LVDS_PWR_CTRL2_get_sbgl(data)                                 ((0x00000C00&(data))>>10)
#define LVDS_PWR_CTRL2_get_sibxl(data)                                ((0x00000200&(data))>>9)
#define LVDS_PWR_CTRL2_get_enib40ux2l(data)                           ((0x00000100&(data))>>8)
#define LVDS_PWR_CTRL2_get_aackpolarl(data)                           ((0x00000080&(data))>>7)
#define LVDS_PWR_CTRL2_get_abckpolarl(data)                           ((0x00000040&(data))>>6)
#define LVDS_PWR_CTRL2_get_acckpolarl(data)                           ((0x00000020&(data))>>5)
#define LVDS_PWR_CTRL2_get_adckpolarl(data)                           ((0x00000010&(data))>>4)
#define LVDS_PWR_CTRL2_get_aeckpolarl(data)                           ((0x00000008&(data))>>3)
#define LVDS_PWR_CTRL2_get_afckpolarl(data)                           ((0x00000004&(data))>>2)
#define LVDS_PWR_CTRL2_get_backpolarl(data)                           ((0x00000002&(data))>>1)
#define LVDS_PWR_CTRL2_get_bbckpolarl(data)                           (0x00000001&(data))

#define LVDS_PWR_CTRL3                                                0x18000928
#define LVDS_PWR_CTRL3_reg_addr                                       "0xB8000928"
#define LVDS_PWR_CTRL3_reg                                            0xB8000928
#define LVDS_PWR_CTRL3_inst_addr                                      "0x024A"
#define LVDS_PWR_CTRL3_inst                                           0x024A
#define LVDS_PWR_CTRL3_bcckpolarl_shift                               (16)
#define LVDS_PWR_CTRL3_bdckpolarl_shift                               (15)
#define LVDS_PWR_CTRL3_beckpolarl_shift                               (14)
#define LVDS_PWR_CTRL3_bfckpolarl_shift                               (13)
#define LVDS_PWR_CTRL3_lvds_pwr_ctrl3_dummy_shift                     (1)
#define LVDS_PWR_CTRL3_envbpbl_shift                                  (0)
#define LVDS_PWR_CTRL3_bcckpolarl_mask                                (0x00010000)
#define LVDS_PWR_CTRL3_bdckpolarl_mask                                (0x00008000)
#define LVDS_PWR_CTRL3_beckpolarl_mask                                (0x00004000)
#define LVDS_PWR_CTRL3_bfckpolarl_mask                                (0x00002000)
#define LVDS_PWR_CTRL3_lvds_pwr_ctrl3_dummy_mask                      (0x00001FFE)
#define LVDS_PWR_CTRL3_envbpbl_mask                                   (0x00000001)
#define LVDS_PWR_CTRL3_bcckpolarl(data)                               (0x00010000&((data)<<16))
#define LVDS_PWR_CTRL3_bdckpolarl(data)                               (0x00008000&((data)<<15))
#define LVDS_PWR_CTRL3_beckpolarl(data)                               (0x00004000&((data)<<14))
#define LVDS_PWR_CTRL3_bfckpolarl(data)                               (0x00002000&((data)<<13))
#define LVDS_PWR_CTRL3_lvds_pwr_ctrl3_dummy(data)                     (0x00001FFE&((data)<<1))
#define LVDS_PWR_CTRL3_envbpbl(data)                                  (0x00000001&(data))
#define LVDS_PWR_CTRL3_get_bcckpolarl(data)                           ((0x00010000&(data))>>16)
#define LVDS_PWR_CTRL3_get_bdckpolarl(data)                           ((0x00008000&(data))>>15)
#define LVDS_PWR_CTRL3_get_beckpolarl(data)                           ((0x00004000&(data))>>14)
#define LVDS_PWR_CTRL3_get_bfckpolarl(data)                           ((0x00002000&(data))>>13)
#define LVDS_PWR_CTRL3_get_lvds_pwr_ctrl3_dummy(data)                 ((0x00001FFE&(data))>>1)
#define LVDS_PWR_CTRL3_get_envbpbl(data)                              (0x00000001&(data))
#endif
