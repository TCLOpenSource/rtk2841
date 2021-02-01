// This file is generated using the spec version 1.39, firmware template version 1.39and SRIF Parser                                                                                source code SVN rev:779                    Version flow no.:1.1.19
#ifndef _I2C_REG_H_INCLUDED_
#define _I2C_REG_H_INCLUDED_

//#define  _I2C_USE_STRUCT
#ifdef _I2C_USE_STRUCT

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
}SS_scl_lcnt;

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
#endif


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


#define SS_SCL_LCNT                                                   0x18012318
#define SS_SCL_LCNT_reg_addr                                          "0xb8012318"
#define SS_SCL_LCNT_reg                                               0xb8012318
#define SS_SCL_LCNT_inst_addr                                         "0x00C6"
#define SS_SCL_LCNT_inst                                              0x00C6
#define SS_SCL_LCNT_ic_ss_scl_lcnt_shift                              (0)
#define SS_SCL_LCNT_ic_ss_scl_lcnt_mask                               (0x0000FFFF)
#define SS_SCL_LCNT_ic_ss_scl_lcnt(data)                              (0x0000FFFF&(data))
#define SS_SCL_LCNT_get_ic_ss_scl_lcnt(data)                          (0x0000FFFF&(data))


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
#endif
