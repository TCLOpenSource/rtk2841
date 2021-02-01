// This file is generated using the spec version 1.39, firmware template version 1.39and SRIF Parser                                                                                source code SVN rev:780                    Version flow no.:1.1.20
#ifndef _I2C1_REG_H_INCLUDED_
#define _I2C1_REG_H_INCLUDED_

//#define  _I2C1_USE_STRUCT
#ifdef _I2C1_USE_STRUCT

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
#endif


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
#endif
