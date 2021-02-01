// This file is generated using the spec version 1.39, firmware template version 1.39and SRIF Parser                                                                                source code SVN rev:780                    Version flow no.:1.1.20
#ifndef _UART_REG_H_INCLUDED_
#define _UART_REG_H_INCLUDED_

//#define  _UART_USE_STRUCT
#ifdef _UART_USE_STRUCT

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
    unsigned int    dll:8;
}ST_uart2_dll;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    dlm:8;
}ST_uart2_dlm;

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
    unsigned int    dll:8;
}ST_uart3_dll;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    dlm:8;
}ST_uart3_dlm;

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
#endif


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
#endif
