// This file is generated using the spec version 1.39, firmware template version 1.39and SRIF Parser                                                                                source code SVN rev:777                    Version flow no.:1.1.14
#ifndef _PMM_MIS_REG_H_INCLUDED_
#define _PMM_MIS_REG_H_INCLUDED_

//#define  _PMM_MIS_USE_STRUCT
#ifdef _PMM_MIS_USE_STRUCT

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
    unsigned int    reserved_0:24;
    unsigned int    peri_top_debug:8;
}ST_lsadc_peri_top_debug;

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
    unsigned int    latch_data_en:1;
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
    unsigned int    reserved_0:31;
    unsigned int    rtcstop:1;
}MIS_rtcstop;

typedef struct
{
    unsigned int    reserved_0:29;
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
    unsigned int    reserved_0:25;
    unsigned int    rtcrst:1;
    unsigned int    reserved_1:1;
    unsigned int    almen:1;
    unsigned int    dainte:1;
    unsigned int    huinte:1;
    unsigned int    muinte:1;
    unsigned int    hsuinte:1;
}MIS_rtccr;
#endif


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
#define ST_PWM0_B0_st_pw0cd0_bit_mask                                     (0x0000FF00)
#define ST_PWM0_B0_st_pw0ocd0_bit_mask                                    (0x000000FF)
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
#define ST_PWM0_AD0_pwm0csd_bit_mask                                      (0x0000001F)
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
#define ST_PWM0_B1_st_pw1cd1_bit_mask                                     (0x0000FF00)
#define ST_PWM0_B1_st_pw1ocd1_bit_mask                                    (0x000000FF)
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
#define ST_PWM0_AD1_pwm1csd_bit_mask                                      (0x0000001F)
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


#define ST_LSADC_PERI_TOP_DEBUG                                       0x1801152c
#define ST_LSADC_PERI_TOP_DEBUG_reg_addr                              "0xb801152c"
#define ST_LSADC_PERI_TOP_DEBUG_reg                                   0xb801152c
#define ST_LSADC_PERI_TOP_DEBUG_inst_addr                             "0x014B"
#define ST_LSADC_PERI_TOP_DEBUG_inst                                  0x014B
#define ST_LSADC_PERI_TOP_DEBUG_peri_top_debug_shift                  (0)
#define ST_LSADC_PERI_TOP_DEBUG_peri_top_debug_mask                   (0x000000FF)
#define ST_LSADC_PERI_TOP_DEBUG_peri_top_debug(data)                  (0x000000FF&(data))
#define ST_LSADC_PERI_TOP_DEBUG_get_peri_top_debug(data)              (0x000000FF&(data))


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
#define ST_WR_CR_latch_data_en_shift                                  (3)
#define ST_WR_CR_pwr_sel_shift                                        (2)
#define ST_WR_CR_trig_reset_shift                                     (1)
#define ST_WR_CR_enable_shift                                         (0)
#define ST_WR_CR_ovsel_mask                                           (0xF0000000)
#define ST_WR_CR_dummy18011700_18_12_mask                             (0x0007F000)
#define ST_WR_CR_test_en_mask                                         (0x00000100)
#define ST_WR_CR_latch_data_en_mask                                   (0x00000008)
#define ST_WR_CR_pwr_sel_mask                                         (0x00000004)
#define ST_WR_CR_trig_reset_mask                                      (0x00000002)
#define ST_WR_CR_enable_mask                                          (0x00000001)
#define ST_WR_CR_ovsel(data)                                          (0xF0000000&((data)<<28))
#define ST_WR_CR_dummy18011700_18_12(data)                            (0x0007F000&((data)<<12))
#define ST_WR_CR_test_en(data)                                        (0x00000100&((data)<<8))
#define ST_WR_CR_latch_data_en(data)                                  (0x00000008&((data)<<3))
#define ST_WR_CR_pwr_sel(data)                                        (0x00000004&((data)<<2))
#define ST_WR_CR_trig_reset(data)                                     (0x00000002&((data)<<1))
#define ST_WR_CR_enable(data)                                         (0x00000001&(data))
#define ST_WR_CR_get_ovsel(data)                                      ((0xF0000000&(data))>>28)
#define ST_WR_CR_get_dummy18011700_18_12(data)                        ((0x0007F000&(data))>>12)
#define ST_WR_CR_get_test_en(data)                                    ((0x00000100&(data))>>8)
#define ST_WR_CR_get_latch_data_en(data)                              ((0x00000008&(data))>>3)
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
#define MIS_RTCSTOP_rtcstop_shift                                     (0)
#define MIS_RTCSTOP_rtcstop_mask                                      (0x00000001)
#define MIS_RTCSTOP_rtcstop(data)                                     (0x00000001&(data))
#define MIS_RTCSTOP_get_rtcstop(data)                                 (0x00000001&(data))


#define MIS_RTCACR                                                    0x18011f28
#define MIS_RTCACR_reg_addr                                           "0xb8011f28"
#define MIS_RTCACR_reg                                                0xb8011f28
#define MIS_RTCACR_inst_addr                                          "0x03CA"
#define MIS_RTCACR_inst                                               0x03CA
#define MIS_RTCACR_clksel_shift                                       (2)
#define MIS_RTCACR_bc_shift                                           (0)
#define MIS_RTCACR_clksel_mask                                        (0x00000004)
#define MIS_RTCACR_bc_mask                                            (0x00000003)
#define MIS_RTCACR_clksel(data)                                       (0x00000004&((data)<<2))
#define MIS_RTCACR_bc(data)                                           (0x00000003&(data))
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
#define MIS_RTCCR_rtcrst_shift                                        (6)
#define MIS_RTCCR_almen_shift                                         (4)
#define MIS_RTCCR_dainte_shift                                        (3)
#define MIS_RTCCR_huinte_shift                                        (2)
#define MIS_RTCCR_muinte_shift                                        (1)
#define MIS_RTCCR_hsuinte_shift                                       (0)
#define MIS_RTCCR_rtcrst_mask                                         (0x00000040)
#define MIS_RTCCR_almen_mask                                          (0x00000010)
#define MIS_RTCCR_dainte_mask                                         (0x00000008)
#define MIS_RTCCR_huinte_mask                                         (0x00000004)
#define MIS_RTCCR_muinte_mask                                         (0x00000002)
#define MIS_RTCCR_hsuinte_mask                                        (0x00000001)
#define MIS_RTCCR_rtcrst(data)                                        (0x00000040&((data)<<6))
#define MIS_RTCCR_almen(data)                                         (0x00000010&((data)<<4))
#define MIS_RTCCR_dainte(data)                                        (0x00000008&((data)<<3))
#define MIS_RTCCR_huinte(data)                                        (0x00000004&((data)<<2))
#define MIS_RTCCR_muinte(data)                                        (0x00000002&((data)<<1))
#define MIS_RTCCR_hsuinte(data)                                       (0x00000001&(data))
#define MIS_RTCCR_get_rtcrst(data)                                    ((0x00000040&(data))>>6)
#define MIS_RTCCR_get_almen(data)                                     ((0x00000010&(data))>>4)
#define MIS_RTCCR_get_dainte(data)                                    ((0x00000008&(data))>>3)
#define MIS_RTCCR_get_huinte(data)                                    ((0x00000004&(data))>>2)
#define MIS_RTCCR_get_muinte(data)                                    ((0x00000002&(data))>>1)
#define MIS_RTCCR_get_hsuinte(data)                                   (0x00000001&(data))
#endif
