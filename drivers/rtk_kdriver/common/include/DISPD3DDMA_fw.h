// This file is generated using the spec version 1.39, firmware template version 1.39and SRIF Parser                                                                                source code SVN rev:793                    Version flow no.:1.1.45
#ifndef _DISPD3DDMA_REG_H_INCLUDED_
#define _DISPD3DDMA_REG_H_INCLUDED_

//#define  _DISPD3DDMA_USE_STRUCT
#ifdef _DISPD3DDMA_USE_STRUCT

typedef struct
{
    unsigned int    reserved_0:6;
    unsigned int    freeze_en:1;
    unsigned int    cap_en:1;
    unsigned int    reserved_1:3;
    unsigned int    frame_mode:1;
    unsigned int    cap_vs_fall_rst_en:1;
    unsigned int    reserved_2:1;
    unsigned int    bit_sel:2;
    unsigned int    reserved_3:2;
    unsigned int    cap_write_len:6;
    unsigned int    reserved_4:2;
    unsigned int    cap_write_rem:6;
}CAP_ctl0;

typedef struct
{
    unsigned int    dummy_cap_ctl1:9;
    unsigned int    cap_water_lv:7;
    unsigned int    cap_write_num:16;
}CAP_ctl1;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    cap_mem_up_limit:28;
    unsigned int    reserved_1:3;
}CAP_boundaryaddr1;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    cap_mem_low_limit:28;
    unsigned int    reserved_1:3;
}CAP_boundaryaddr2;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    cap_l1_start:28;
    unsigned int    reserved_1:3;
}CAP_l1_start;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    cap_l2_start:28;
    unsigned int    reserved_1:3;
}CAP_l2_start;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    cap_r1_start:28;
    unsigned int    reserved_1:3;
}CAP_r1_start;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    cap_r2_start:28;
    unsigned int    reserved_1:3;
}CAP_r2_start;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    line_step:28;
    unsigned int    reserved_1:3;
}CAP_linestep;

typedef struct
{
    unsigned int    dummy_cap_st:26;
    unsigned int    cap_block:1;
    unsigned int    cap_fifo_full:1;
    unsigned int    cap_fifo_empty:1;
    unsigned int    cap_fifo_overflow:1;
    unsigned int    cap_fifo_underflow:1;
    unsigned int    cap_ddr_over_range:1;
}CAP_status;

typedef struct
{
    unsigned int    reserved_0:15;
    unsigned int    disp2_3ddma_en:1;
    unsigned int    reserved_1:6;
    unsigned int    disp_vs_fall_rst_en:1;
    unsigned int    disp_3ddma_en:1;
    unsigned int    reserved_2:3;
    unsigned int    stop_burst_en:1;
    unsigned int    l_flag_inv:1;
    unsigned int    side_by_side_en:1;
    unsigned int    output_format:2;
}DISPLAY_output;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    disp2_pre_rd_v_start:11;
    unsigned int    reserved_1:5;
    unsigned int    pre_rd_v_start:11;
}DISPLAY_prevstart;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    pixel_num:12;
    unsigned int    reserved_1:1;
    unsigned int    wtlvl:7;
}DISPLAY_numwtl;

typedef struct
{
    unsigned int    read_num:16;
    unsigned int    reserved_0:2;
    unsigned int    read_len:6;
    unsigned int    reserved_1:2;
    unsigned int    read_remain:6;
}DISPLAY_rdnumlenrem;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    line_number:12;
}DISPLAY_linenum;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    blank_r:10;
    unsigned int    blank_g:10;
    unsigned int    blank_b:10;
}DISPLAY_activespace_value;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    disp2_clr_over_range:1;
    unsigned int    disp2_fifo_clr:1;
    unsigned int    disp2_fifo_full:1;
    unsigned int    disp2_fifo_empty:1;
    unsigned int    disp2_fifo_overflow:1;
    unsigned int    disp2_fifo_underflow:1;
    unsigned int    disp2_adr_down_over_range:1;
    unsigned int    disp2_adr_up_over_range:1;
    unsigned int    disp_clr_over_range:1;
    unsigned int    disp_fifo_clr:1;
    unsigned int    disp_fifo_full:1;
    unsigned int    disp_fifo_empty:1;
    unsigned int    disp_fifo_overflow:1;
    unsigned int    disp_fifo_underflow:1;
    unsigned int    disp_adr_down_over_range:1;
    unsigned int    disp_adr_up_over_range:1;
}DISPLAY_status;

typedef struct
{
    unsigned int    reserved_0:7;
    unsigned int    cap_dvs_0:3;
    unsigned int    cap_dvse_0:1;
    unsigned int    disp1_dvs_0:3;
    unsigned int    disp1_dvse_0:1;
    unsigned int    disp2_dvs_0:3;
    unsigned int    disp2_dvse_0:1;
    unsigned int    drf_test_resume:1;
    unsigned int    drf_start_pause:1;
    unsigned int    drf_bist_done:1;
    unsigned int    cap_drf_bist_fail:1;
    unsigned int    disp1_drf_bist_fail:1;
    unsigned int    disp2_drf_bist_fail:1;
    unsigned int    drf_bist_mode:1;
    unsigned int    bist_done:1;
    unsigned int    cap_bist_ok:1;
    unsigned int    disp1_bist_ok:1;
    unsigned int    disp2_bist_ok:1;
    unsigned int    bist_rst:1;
    unsigned int    bist_en:1;
}MBIST;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    r_auto_cmp_en:1;
    unsigned int    l_auto_cmp_en:1;
    unsigned int    reserved_1:5;
    unsigned int    crc_3d_en:1;
    unsigned int    crc_conti:1;
    unsigned int    crc_start:1;
}CAP_crc_ctrl;

typedef struct
{
    unsigned int    crc_l_result:32;
}CAP_crc_l_result;

typedef struct
{
    unsigned int    crc_r_result:32;
}CAP_crc_r_result;

typedef struct
{
    unsigned int    l_des_crc:32;
}CAP_l_des_crc;

typedef struct
{
    unsigned int    r_des_crc:32;
}CAP_r_des_crc;

typedef struct
{
    unsigned int    r_crc_err_cnt:16;
    unsigned int    l_crc_err_cnt:16;
}CAP_crc_err_cnt;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    disp1_start_addr1:28;
    unsigned int    reserved_1:3;
}DISP1_start_addr1;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    disp1_start_addr2:28;
    unsigned int    reserved_1:3;
}DISP1_start_addr2;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    disp2_start_addr1:28;
    unsigned int    reserved_1:3;
}DISP2_start_addr1;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    disp2_start_addr2:28;
    unsigned int    reserved_1:3;
}DISP2_start_addr2;
#endif


#define CAP_CTL0                                                      0x1802c710
#define CAP_CTL0_reg_addr                                             "0xb802c710"
#define CAP_CTL0_reg                                                  0xb802c710
#define CAP_CTL0_inst_addr                                            "0x01C4"
#define CAP_CTL0_inst                                                 0x01C4
#define CAP_CTL0_freeze_en_shift                                      (25)
#define CAP_CTL0_cap_en_shift                                         (24)
#define CAP_CTL0_frame_mode_shift                                     (20)
#define CAP_CTL0_cap_vs_fall_rst_en_shift                             (19)
#define CAP_CTL0_bit_sel_shift                                        (16)
#define CAP_CTL0_cap_write_len_shift                                  (8)
#define CAP_CTL0_cap_write_rem_shift                                  (0)
#define CAP_CTL0_freeze_en_mask                                       (0x02000000)
#define CAP_CTL0_cap_en_mask                                          (0x01000000)
#define CAP_CTL0_frame_mode_mask                                      (0x00100000)
#define CAP_CTL0_cap_vs_fall_rst_en_mask                              (0x00080000)
#define CAP_CTL0_bit_sel_mask                                         (0x00030000)
#define CAP_CTL0_cap_write_len_mask                                   (0x00003F00)
#define CAP_CTL0_cap_write_rem_mask                                   (0x0000003F)
#define CAP_CTL0_freeze_en(data)                                      (0x02000000&((data)<<25))
#define CAP_CTL0_cap_en(data)                                         (0x01000000&((data)<<24))
#define CAP_CTL0_frame_mode(data)                                     (0x00100000&((data)<<20))
#define CAP_CTL0_cap_vs_fall_rst_en(data)                             (0x00080000&((data)<<19))
#define CAP_CTL0_bit_sel(data)                                        (0x00030000&((data)<<16))
#define CAP_CTL0_cap_write_len(data)                                  (0x00003F00&((data)<<8))
#define CAP_CTL0_cap_write_rem(data)                                  (0x0000003F&(data))
#define CAP_CTL0_get_freeze_en(data)                                  ((0x02000000&(data))>>25)
#define CAP_CTL0_get_cap_en(data)                                     ((0x01000000&(data))>>24)
#define CAP_CTL0_get_frame_mode(data)                                 ((0x00100000&(data))>>20)
#define CAP_CTL0_get_cap_vs_fall_rst_en(data)                         ((0x00080000&(data))>>19)
#define CAP_CTL0_get_bit_sel(data)                                    ((0x00030000&(data))>>16)
#define CAP_CTL0_get_cap_write_len(data)                              ((0x00003F00&(data))>>8)
#define CAP_CTL0_get_cap_write_rem(data)                              (0x0000003F&(data))


#define CAP_CTL1                                                      0x1802c714
#define CAP_CTL1_reg_addr                                             "0xb802c714"
#define CAP_CTL1_reg                                                  0xb802c714
#define CAP_CTL1_inst_addr                                            "0x01C5"
#define CAP_CTL1_inst                                                 0x01C5
#define CAP_CTL1_dummy_cap_ctl1_shift                                 (23)
#define CAP_CTL1_cap_water_lv_shift                                   (16)
#define CAP_CTL1_cap_write_num_shift                                  (0)
#define CAP_CTL1_dummy_cap_ctl1_mask                                  (0xFF800000)
#define CAP_CTL1_cap_water_lv_mask                                    (0x007F0000)
#define CAP_CTL1_cap_write_num_mask                                   (0x0000FFFF)
#define CAP_CTL1_dummy_cap_ctl1(data)                                 (0xFF800000&((data)<<23))
#define CAP_CTL1_cap_water_lv(data)                                   (0x007F0000&((data)<<16))
#define CAP_CTL1_cap_write_num(data)                                  (0x0000FFFF&(data))
#define CAP_CTL1_get_dummy_cap_ctl1(data)                             ((0xFF800000&(data))>>23)
#define CAP_CTL1_get_cap_water_lv(data)                               ((0x007F0000&(data))>>16)
#define CAP_CTL1_get_cap_write_num(data)                              (0x0000FFFF&(data))


#define CAP_BOUNDARYADDR1                                             0x1802c718
#define CAP_BOUNDARYADDR1_reg_addr                                    "0xb802c718"
#define CAP_BOUNDARYADDR1_reg                                         0xb802c718
#define CAP_BOUNDARYADDR1_inst_addr                                   "0x01C6"
#define CAP_BOUNDARYADDR1_inst                                        0x01C6
#define CAP_BOUNDARYADDR1_cap_mem_up_limit_shift                      (3)
#define CAP_BOUNDARYADDR1_cap_mem_up_limit_mask                       (0x7FFFFFF8)
#define CAP_BOUNDARYADDR1_cap_mem_up_limit(data)                      (0x7FFFFFF8&((data)<<3))
#define CAP_BOUNDARYADDR1_get_cap_mem_up_limit(data)                  ((0x7FFFFFF8&(data))>>3)


#define CAP_BOUNDARYADDR2                                             0x1802c71c
#define CAP_BOUNDARYADDR2_reg_addr                                    "0xb802c71c"
#define CAP_BOUNDARYADDR2_reg                                         0xb802c71c
#define CAP_BOUNDARYADDR2_inst_addr                                   "0x01C7"
#define CAP_BOUNDARYADDR2_inst                                        0x01C7
#define CAP_BOUNDARYADDR2_cap_mem_low_limit_shift                     (3)
#define CAP_BOUNDARYADDR2_cap_mem_low_limit_mask                      (0x7FFFFFF8)
#define CAP_BOUNDARYADDR2_cap_mem_low_limit(data)                     (0x7FFFFFF8&((data)<<3))
#define CAP_BOUNDARYADDR2_get_cap_mem_low_limit(data)                 ((0x7FFFFFF8&(data))>>3)


#define CAP_L1_START                                                  0x1802c720
#define CAP_L1_START_reg_addr                                         "0xb802c720"
#define CAP_L1_START_reg                                              0xb802c720
#define CAP_L1_START_inst_addr                                        "0x01C8"
#define CAP_L1_START_inst                                             0x01C8
#define CAP_L1_START_cap_l1_start_shift                               (3)
#define CAP_L1_START_cap_l1_start_mask                                (0x7FFFFFF8)
#define CAP_L1_START_cap_l1_start(data)                               (0x7FFFFFF8&((data)<<3))
#define CAP_L1_START_get_cap_l1_start(data)                           ((0x7FFFFFF8&(data))>>3)


#define CAP_L2_START                                                  0x1802c724
#define CAP_L2_START_reg_addr                                         "0xb802c724"
#define CAP_L2_START_reg                                              0xb802c724
#define CAP_L2_START_inst_addr                                        "0x01C9"
#define CAP_L2_START_inst                                             0x01C9
#define CAP_L2_START_cap_l2_start_shift                               (3)
#define CAP_L2_START_cap_l2_start_mask                                (0x7FFFFFF8)
#define CAP_L2_START_cap_l2_start(data)                               (0x7FFFFFF8&((data)<<3))
#define CAP_L2_START_get_cap_l2_start(data)                           ((0x7FFFFFF8&(data))>>3)


#define CAP_R1_START                                                  0x1802c728
#define CAP_R1_START_reg_addr                                         "0xb802c728"
#define CAP_R1_START_reg                                              0xb802c728
#define CAP_R1_START_inst_addr                                        "0x01CA"
#define CAP_R1_START_inst                                             0x01CA
#define CAP_R1_START_cap_r1_start_shift                               (3)
#define CAP_R1_START_cap_r1_start_mask                                (0x7FFFFFF8)
#define CAP_R1_START_cap_r1_start(data)                               (0x7FFFFFF8&((data)<<3))
#define CAP_R1_START_get_cap_r1_start(data)                           ((0x7FFFFFF8&(data))>>3)


#define CAP_R2_START                                                  0x1802c72c
#define CAP_R2_START_reg_addr                                         "0xb802c72c"
#define CAP_R2_START_reg                                              0xb802c72c
#define CAP_R2_START_inst_addr                                        "0x01CB"
#define CAP_R2_START_inst                                             0x01CB
#define CAP_R2_START_cap_r2_start_shift                               (3)
#define CAP_R2_START_cap_r2_start_mask                                (0x7FFFFFF8)
#define CAP_R2_START_cap_r2_start(data)                               (0x7FFFFFF8&((data)<<3))
#define CAP_R2_START_get_cap_r2_start(data)                           ((0x7FFFFFF8&(data))>>3)


#define CAP_LINESTEP                                                  0x1802c730
#define CAP_LINESTEP_reg_addr                                         "0xb802c730"
#define CAP_LINESTEP_reg                                              0xb802c730
#define CAP_LINESTEP_inst_addr                                        "0x01CC"
#define CAP_LINESTEP_inst                                             0x01CC
#define CAP_LINESTEP_line_step_shift                                  (3)
#define CAP_LINESTEP_line_step_mask                                   (0x7FFFFFF8)
#define CAP_LINESTEP_line_step(data)                                  (0x7FFFFFF8&((data)<<3))
#define CAP_LINESTEP_get_line_step(data)                              ((0x7FFFFFF8&(data))>>3)


#define CAP_STATUS                                                    0x1802c734
#define CAP_STATUS_reg_addr                                           "0xb802c734"
#define CAP_STATUS_reg                                                0xb802c734
#define CAP_STATUS_inst_addr                                          "0x01CD"
#define CAP_STATUS_inst                                               0x01CD
#define CAP_STATUS_dummy_cap_st_shift                                 (6)
#define CAP_STATUS_cap_block_shift                                    (5)
#define CAP_STATUS_cap_fifo_full_shift                                (4)
#define CAP_STATUS_cap_fifo_empty_shift                               (3)
#define CAP_STATUS_cap_fifo_overflow_shift                            (2)
#define CAP_STATUS_cap_fifo_underflow_shift                           (1)
#define CAP_STATUS_cap_ddr_over_range_shift                           (0)
#define CAP_STATUS_dummy_cap_st_mask                                  (0xFFFFFFC0)
#define CAP_STATUS_cap_block_mask                                     (0x00000020)
#define CAP_STATUS_cap_fifo_full_mask                                 (0x00000010)
#define CAP_STATUS_cap_fifo_empty_mask                                (0x00000008)
#define CAP_STATUS_cap_fifo_overflow_mask                             (0x00000004)
#define CAP_STATUS_cap_fifo_underflow_mask                            (0x00000002)
#define CAP_STATUS_cap_ddr_over_range_mask                            (0x00000001)
#define CAP_STATUS_dummy_cap_st(data)                                 (0xFFFFFFC0&((data)<<6))
#define CAP_STATUS_cap_block(data)                                    (0x00000020&((data)<<5))
#define CAP_STATUS_cap_fifo_full(data)                                (0x00000010&((data)<<4))
#define CAP_STATUS_cap_fifo_empty(data)                               (0x00000008&((data)<<3))
#define CAP_STATUS_cap_fifo_overflow(data)                            (0x00000004&((data)<<2))
#define CAP_STATUS_cap_fifo_underflow(data)                           (0x00000002&((data)<<1))
#define CAP_STATUS_cap_ddr_over_range(data)                           (0x00000001&(data))
#define CAP_STATUS_get_dummy_cap_st(data)                             ((0xFFFFFFC0&(data))>>6)
#define CAP_STATUS_get_cap_block(data)                                ((0x00000020&(data))>>5)
#define CAP_STATUS_get_cap_fifo_full(data)                            ((0x00000010&(data))>>4)
#define CAP_STATUS_get_cap_fifo_empty(data)                           ((0x00000008&(data))>>3)
#define CAP_STATUS_get_cap_fifo_overflow(data)                        ((0x00000004&(data))>>2)
#define CAP_STATUS_get_cap_fifo_underflow(data)                       ((0x00000002&(data))>>1)
#define CAP_STATUS_get_cap_ddr_over_range(data)                       (0x00000001&(data))


#define DISPLAY_OUTPUT                                                0x1802c780
#define DISPLAY_OUTPUT_reg_addr                                       "0xb802c780"
#define DISPLAY_OUTPUT_reg                                            0xb802c780
#define DISPLAY_OUTPUT_inst_addr                                      "0x01E0"
#define DISPLAY_OUTPUT_inst                                           0x01E0
#define DISPLAY_OUTPUT_disp2_3ddma_en_shift                           (16)
#define DISPLAY_OUTPUT_disp_vs_fall_rst_en_shift                      (9)
#define DISPLAY_OUTPUT_disp_3ddma_en_shift                            (8)
#define DISPLAY_OUTPUT_stop_burst_en_shift                            (4)
#define DISPLAY_OUTPUT_l_flag_inv_shift                               (3)
#define DISPLAY_OUTPUT_side_by_side_en_shift                          (2)
#define DISPLAY_OUTPUT_output_format_shift                            (0)
#define DISPLAY_OUTPUT_disp2_3ddma_en_mask                            (0x00010000)
#define DISPLAY_OUTPUT_disp_vs_fall_rst_en_mask                       (0x00000200)
#define DISPLAY_OUTPUT_disp_3ddma_en_mask                             (0x00000100)
#define DISPLAY_OUTPUT_stop_burst_en_mask                             (0x00000010)
#define DISPLAY_OUTPUT_l_flag_inv_mask                                (0x00000008)
#define DISPLAY_OUTPUT_side_by_side_en_mask                           (0x00000004)
#define DISPLAY_OUTPUT_output_format_mask                             (0x00000003)
#define DISPLAY_OUTPUT_disp2_3ddma_en(data)                           (0x00010000&((data)<<16))
#define DISPLAY_OUTPUT_disp_vs_fall_rst_en(data)                      (0x00000200&((data)<<9))
#define DISPLAY_OUTPUT_disp_3ddma_en(data)                            (0x00000100&((data)<<8))
#define DISPLAY_OUTPUT_stop_burst_en(data)                            (0x00000010&((data)<<4))
#define DISPLAY_OUTPUT_l_flag_inv(data)                               (0x00000008&((data)<<3))
#define DISPLAY_OUTPUT_side_by_side_en(data)                          (0x00000004&((data)<<2))
#define DISPLAY_OUTPUT_output_format(data)                            (0x00000003&(data))
#define DISPLAY_OUTPUT_get_disp2_3ddma_en(data)                       ((0x00010000&(data))>>16)
#define DISPLAY_OUTPUT_get_disp_vs_fall_rst_en(data)                  ((0x00000200&(data))>>9)
#define DISPLAY_OUTPUT_get_disp_3ddma_en(data)                        ((0x00000100&(data))>>8)
#define DISPLAY_OUTPUT_get_stop_burst_en(data)                        ((0x00000010&(data))>>4)
#define DISPLAY_OUTPUT_get_l_flag_inv(data)                           ((0x00000008&(data))>>3)
#define DISPLAY_OUTPUT_get_side_by_side_en(data)                      ((0x00000004&(data))>>2)
#define DISPLAY_OUTPUT_get_output_format(data)                        (0x00000003&(data))


#define DISPLAY_PREVSTART                                             0x1802c784
#define DISPLAY_PREVSTART_reg_addr                                    "0xb802c784"
#define DISPLAY_PREVSTART_reg                                         0xb802c784
#define DISPLAY_PREVSTART_inst_addr                                   "0x01E1"
#define DISPLAY_PREVSTART_inst                                        0x01E1
#define DISPLAY_PREVSTART_disp2_pre_rd_v_start_shift                  (16)
#define DISPLAY_PREVSTART_pre_rd_v_start_shift                        (0)
#define DISPLAY_PREVSTART_disp2_pre_rd_v_start_mask                   (0x07FF0000)
#define DISPLAY_PREVSTART_pre_rd_v_start_mask                         (0x000007FF)
#define DISPLAY_PREVSTART_disp2_pre_rd_v_start(data)                  (0x07FF0000&((data)<<16))
#define DISPLAY_PREVSTART_pre_rd_v_start(data)                        (0x000007FF&(data))
#define DISPLAY_PREVSTART_get_disp2_pre_rd_v_start(data)              ((0x07FF0000&(data))>>16)
#define DISPLAY_PREVSTART_get_pre_rd_v_start(data)                    (0x000007FF&(data))


#define DISPLAY_NUMWTL                                                0x1802c788
#define DISPLAY_NUMWTL_reg_addr                                       "0xb802c788"
#define DISPLAY_NUMWTL_reg                                            0xb802c788
#define DISPLAY_NUMWTL_inst_addr                                      "0x01E2"
#define DISPLAY_NUMWTL_inst                                           0x01E2
#define DISPLAY_NUMWTL_pixel_num_shift                                (8)
#define DISPLAY_NUMWTL_wtlvl_shift                                    (0)
#define DISPLAY_NUMWTL_pixel_num_mask                                 (0x000FFF00)
#define DISPLAY_NUMWTL_wtlvl_mask                                     (0x0000007F)
#define DISPLAY_NUMWTL_pixel_num(data)                                (0x000FFF00&((data)<<8))
#define DISPLAY_NUMWTL_wtlvl(data)                                    (0x0000007F&(data))
#define DISPLAY_NUMWTL_get_pixel_num(data)                            ((0x000FFF00&(data))>>8)
#define DISPLAY_NUMWTL_get_wtlvl(data)                                (0x0000007F&(data))


#define DISPLAY_RDNUMLENREM                                           0x1802c78c
#define DISPLAY_RDNUMLENREM_reg_addr                                  "0xb802c78c"
#define DISPLAY_RDNUMLENREM_reg                                       0xb802c78c
#define DISPLAY_RDNUMLENREM_inst_addr                                 "0x01E3"
#define DISPLAY_RDNUMLENREM_inst                                      0x01E3
#define DISPLAY_RDNUMLENREM_read_num_shift                            (16)
#define DISPLAY_RDNUMLENREM_read_len_shift                            (8)
#define DISPLAY_RDNUMLENREM_read_remain_shift                         (0)
#define DISPLAY_RDNUMLENREM_read_num_mask                             (0xFFFF0000)
#define DISPLAY_RDNUMLENREM_read_len_mask                             (0x00003F00)
#define DISPLAY_RDNUMLENREM_read_remain_mask                          (0x0000003F)
#define DISPLAY_RDNUMLENREM_read_num(data)                            (0xFFFF0000&((data)<<16))
#define DISPLAY_RDNUMLENREM_read_len(data)                            (0x00003F00&((data)<<8))
#define DISPLAY_RDNUMLENREM_read_remain(data)                         (0x0000003F&(data))
#define DISPLAY_RDNUMLENREM_get_read_num(data)                        ((0xFFFF0000&(data))>>16)
#define DISPLAY_RDNUMLENREM_get_read_len(data)                        ((0x00003F00&(data))>>8)
#define DISPLAY_RDNUMLENREM_get_read_remain(data)                     (0x0000003F&(data))


#define DISPLAY_LINENUM                                               0x1802c790
#define DISPLAY_LINENUM_reg_addr                                      "0xb802c790"
#define DISPLAY_LINENUM_reg                                           0xb802c790
#define DISPLAY_LINENUM_inst_addr                                     "0x01E4"
#define DISPLAY_LINENUM_inst                                          0x01E4
#define DISPLAY_LINENUM_line_number_shift                             (0)
#define DISPLAY_LINENUM_line_number_mask                              (0x00000FFF)
#define DISPLAY_LINENUM_line_number(data)                             (0x00000FFF&(data))
#define DISPLAY_LINENUM_get_line_number(data)                         (0x00000FFF&(data))


#define DISPLAY_ACTIVESPACE_VALUE                                     0x1802c794
#define DISPLAY_ACTIVESPACE_VALUE_reg_addr                            "0xb802c794"
#define DISPLAY_ACTIVESPACE_VALUE_reg                                 0xb802c794
#define DISPLAY_ACTIVESPACE_VALUE_inst_addr                           "0x01E5"
#define DISPLAY_ACTIVESPACE_VALUE_inst                                0x01E5
#define DISPLAY_ACTIVESPACE_VALUE_blank_r_shift                       (20)
#define DISPLAY_ACTIVESPACE_VALUE_blank_g_shift                       (10)
#define DISPLAY_ACTIVESPACE_VALUE_blank_b_shift                       (0)
#define DISPLAY_ACTIVESPACE_VALUE_blank_r_mask                        (0x3FF00000)
#define DISPLAY_ACTIVESPACE_VALUE_blank_g_mask                        (0x000FFC00)
#define DISPLAY_ACTIVESPACE_VALUE_blank_b_mask                        (0x000003FF)
#define DISPLAY_ACTIVESPACE_VALUE_blank_r(data)                       (0x3FF00000&((data)<<20))
#define DISPLAY_ACTIVESPACE_VALUE_blank_g(data)                       (0x000FFC00&((data)<<10))
#define DISPLAY_ACTIVESPACE_VALUE_blank_b(data)                       (0x000003FF&(data))
#define DISPLAY_ACTIVESPACE_VALUE_get_blank_r(data)                   ((0x3FF00000&(data))>>20)
#define DISPLAY_ACTIVESPACE_VALUE_get_blank_g(data)                   ((0x000FFC00&(data))>>10)
#define DISPLAY_ACTIVESPACE_VALUE_get_blank_b(data)                   (0x000003FF&(data))


#define DISPLAY_STATUS                                                0x1802c798
#define DISPLAY_STATUS_reg_addr                                       "0xb802c798"
#define DISPLAY_STATUS_reg                                            0xb802c798
#define DISPLAY_STATUS_inst_addr                                      "0x01E6"
#define DISPLAY_STATUS_inst                                           0x01E6
#define DISPLAY_STATUS_disp2_clr_over_range_shift                     (15)
#define DISPLAY_STATUS_disp2_fifo_clr_shift                           (14)
#define DISPLAY_STATUS_disp2_fifo_full_shift                          (13)
#define DISPLAY_STATUS_disp2_fifo_empty_shift                         (12)
#define DISPLAY_STATUS_disp2_fifo_overflow_shift                      (11)
#define DISPLAY_STATUS_disp2_fifo_underflow_shift                     (10)
#define DISPLAY_STATUS_disp2_adr_down_over_range_shift                (9)
#define DISPLAY_STATUS_disp2_adr_up_over_range_shift                  (8)
#define DISPLAY_STATUS_disp_clr_over_range_shift                      (7)
#define DISPLAY_STATUS_disp_fifo_clr_shift                            (6)
#define DISPLAY_STATUS_disp_fifo_full_shift                           (5)
#define DISPLAY_STATUS_disp_fifo_empty_shift                          (4)
#define DISPLAY_STATUS_disp_fifo_overflow_shift                       (3)
#define DISPLAY_STATUS_disp_fifo_underflow_shift                      (2)
#define DISPLAY_STATUS_disp_adr_down_over_range_shift                 (1)
#define DISPLAY_STATUS_disp_adr_up_over_range_shift                   (0)
#define DISPLAY_STATUS_disp2_clr_over_range_mask                      (0x00008000)
#define DISPLAY_STATUS_disp2_fifo_clr_mask                            (0x00004000)
#define DISPLAY_STATUS_disp2_fifo_full_mask                           (0x00002000)
#define DISPLAY_STATUS_disp2_fifo_empty_mask                          (0x00001000)
#define DISPLAY_STATUS_disp2_fifo_overflow_mask                       (0x00000800)
#define DISPLAY_STATUS_disp2_fifo_underflow_mask                      (0x00000400)
#define DISPLAY_STATUS_disp2_adr_down_over_range_mask                 (0x00000200)
#define DISPLAY_STATUS_disp2_adr_up_over_range_mask                   (0x00000100)
#define DISPLAY_STATUS_disp_clr_over_range_mask                       (0x00000080)
#define DISPLAY_STATUS_disp_fifo_clr_mask                             (0x00000040)
#define DISPLAY_STATUS_disp_fifo_full_mask                            (0x00000020)
#define DISPLAY_STATUS_disp_fifo_empty_mask                           (0x00000010)
#define DISPLAY_STATUS_disp_fifo_overflow_mask                        (0x00000008)
#define DISPLAY_STATUS_disp_fifo_underflow_mask                       (0x00000004)
#define DISPLAY_STATUS_disp_adr_down_over_range_mask                  (0x00000002)
#define DISPLAY_STATUS_disp_adr_up_over_range_mask                    (0x00000001)
#define DISPLAY_STATUS_disp2_clr_over_range(data)                     (0x00008000&((data)<<15))
#define DISPLAY_STATUS_disp2_fifo_clr(data)                           (0x00004000&((data)<<14))
#define DISPLAY_STATUS_disp2_fifo_full(data)                          (0x00002000&((data)<<13))
#define DISPLAY_STATUS_disp2_fifo_empty(data)                         (0x00001000&((data)<<12))
#define DISPLAY_STATUS_disp2_fifo_overflow(data)                      (0x00000800&((data)<<11))
#define DISPLAY_STATUS_disp2_fifo_underflow(data)                     (0x00000400&((data)<<10))
#define DISPLAY_STATUS_disp2_adr_down_over_range(data)                (0x00000200&((data)<<9))
#define DISPLAY_STATUS_disp2_adr_up_over_range(data)                  (0x00000100&((data)<<8))
#define DISPLAY_STATUS_disp_clr_over_range(data)                      (0x00000080&((data)<<7))
#define DISPLAY_STATUS_disp_fifo_clr(data)                            (0x00000040&((data)<<6))
#define DISPLAY_STATUS_disp_fifo_full(data)                           (0x00000020&((data)<<5))
#define DISPLAY_STATUS_disp_fifo_empty(data)                          (0x00000010&((data)<<4))
#define DISPLAY_STATUS_disp_fifo_overflow(data)                       (0x00000008&((data)<<3))
#define DISPLAY_STATUS_disp_fifo_underflow(data)                      (0x00000004&((data)<<2))
#define DISPLAY_STATUS_disp_adr_down_over_range(data)                 (0x00000002&((data)<<1))
#define DISPLAY_STATUS_disp_adr_up_over_range(data)                   (0x00000001&(data))
#define DISPLAY_STATUS_get_disp2_clr_over_range(data)                 ((0x00008000&(data))>>15)
#define DISPLAY_STATUS_get_disp2_fifo_clr(data)                       ((0x00004000&(data))>>14)
#define DISPLAY_STATUS_get_disp2_fifo_full(data)                      ((0x00002000&(data))>>13)
#define DISPLAY_STATUS_get_disp2_fifo_empty(data)                     ((0x00001000&(data))>>12)
#define DISPLAY_STATUS_get_disp2_fifo_overflow(data)                  ((0x00000800&(data))>>11)
#define DISPLAY_STATUS_get_disp2_fifo_underflow(data)                 ((0x00000400&(data))>>10)
#define DISPLAY_STATUS_get_disp2_adr_down_over_range(data)            ((0x00000200&(data))>>9)
#define DISPLAY_STATUS_get_disp2_adr_up_over_range(data)              ((0x00000100&(data))>>8)
#define DISPLAY_STATUS_get_disp_clr_over_range(data)                  ((0x00000080&(data))>>7)
#define DISPLAY_STATUS_get_disp_fifo_clr(data)                        ((0x00000040&(data))>>6)
#define DISPLAY_STATUS_get_disp_fifo_full(data)                       ((0x00000020&(data))>>5)
#define DISPLAY_STATUS_get_disp_fifo_empty(data)                      ((0x00000010&(data))>>4)
#define DISPLAY_STATUS_get_disp_fifo_overflow(data)                   ((0x00000008&(data))>>3)
#define DISPLAY_STATUS_get_disp_fifo_underflow(data)                  ((0x00000004&(data))>>2)
#define DISPLAY_STATUS_get_disp_adr_down_over_range(data)             ((0x00000002&(data))>>1)
#define DISPLAY_STATUS_get_disp_adr_up_over_range(data)               (0x00000001&(data))


#define MBIST                                                         0x1802c79c
#define MBIST_reg_addr                                                "0xb802c79c"
#define MBIST_reg                                                     0xb802c79c
#define MBIST_inst_addr                                               "0x01E7"
#define MBIST_inst                                                    0x01E7
#define MBIST_cap_dvs_0_shift                                         (22)
#define MBIST_cap_dvse_0_shift                                        (21)
#define MBIST_disp1_dvs_0_shift                                       (18)
#define MBIST_disp1_dvse_0_shift                                      (17)
#define MBIST_disp2_dvs_0_shift                                       (14)
#define MBIST_disp2_dvse_0_shift                                      (13)
#define MBIST_drf_test_resume_shift                                   (12)
#define MBIST_drf_start_pause_shift                                   (11)
#define MBIST_drf_bist_done_shift                                     (10)
#define MBIST_cap_drf_bist_fail_shift                                 (9)
#define MBIST_disp1_drf_bist_fail_shift                               (8)
#define MBIST_disp2_drf_bist_fail_shift                               (7)
#define MBIST_drf_bist_mode_shift                                     (6)
#define MBIST_bist_done_shift                                         (5)
#define MBIST_cap_bist_ok_shift                                       (4)
#define MBIST_disp1_bist_ok_shift                                     (3)
#define MBIST_disp2_bist_ok_shift                                     (2)
#define MBIST_bist_rst_shift                                          (1)
#define MBIST_bist_en_shift                                           (0)
#define MBIST_cap_dvs_0_mask                                          (0x01C00000)
#define MBIST_cap_dvse_0_mask                                         (0x00200000)
#define MBIST_disp1_dvs_0_mask                                        (0x001C0000)
#define MBIST_disp1_dvse_0_mask                                       (0x00020000)
#define MBIST_disp2_dvs_0_mask                                        (0x0001C000)
#define MBIST_disp2_dvse_0_mask                                       (0x00002000)
#define MBIST_drf_test_resume_mask                                    (0x00001000)
#define MBIST_drf_start_pause_mask                                    (0x00000800)
#define MBIST_drf_bist_done_mask                                      (0x00000400)
#define MBIST_cap_drf_bist_fail_mask                                  (0x00000200)
#define MBIST_disp1_drf_bist_fail_mask                                (0x00000100)
#define MBIST_disp2_drf_bist_fail_mask                                (0x00000080)
#define MBIST_drf_bist_mode_mask                                      (0x00000040)
#define MBIST_bist_done_mask                                          (0x00000020)
#define MBIST_cap_bist_ok_mask                                        (0x00000010)
#define MBIST_disp1_bist_ok_mask                                      (0x00000008)
#define MBIST_disp2_bist_ok_mask                                      (0x00000004)
#define MBIST_bist_rst_mask                                           (0x00000002)
#define MBIST_bist_en_mask                                            (0x00000001)
#define MBIST_cap_dvs_0(data)                                         (0x01C00000&((data)<<22))
#define MBIST_cap_dvse_0(data)                                        (0x00200000&((data)<<21))
#define MBIST_disp1_dvs_0(data)                                       (0x001C0000&((data)<<18))
#define MBIST_disp1_dvse_0(data)                                      (0x00020000&((data)<<17))
#define MBIST_disp2_dvs_0(data)                                       (0x0001C000&((data)<<14))
#define MBIST_disp2_dvse_0(data)                                      (0x00002000&((data)<<13))
#define MBIST_drf_test_resume(data)                                   (0x00001000&((data)<<12))
#define MBIST_drf_start_pause(data)                                   (0x00000800&((data)<<11))
#define MBIST_drf_bist_done(data)                                     (0x00000400&((data)<<10))
#define MBIST_cap_drf_bist_fail(data)                                 (0x00000200&((data)<<9))
#define MBIST_disp1_drf_bist_fail(data)                               (0x00000100&((data)<<8))
#define MBIST_disp2_drf_bist_fail(data)                               (0x00000080&((data)<<7))
#define MBIST_drf_bist_mode(data)                                     (0x00000040&((data)<<6))
#define MBIST_bist_done(data)                                         (0x00000020&((data)<<5))
#define MBIST_cap_bist_ok(data)                                       (0x00000010&((data)<<4))
#define MBIST_disp1_bist_ok(data)                                     (0x00000008&((data)<<3))
#define MBIST_disp2_bist_ok(data)                                     (0x00000004&((data)<<2))
#define MBIST_bist_rst(data)                                          (0x00000002&((data)<<1))
#define MBIST_bist_en(data)                                           (0x00000001&(data))
#define MBIST_get_cap_dvs_0(data)                                     ((0x01C00000&(data))>>22)
#define MBIST_get_cap_dvse_0(data)                                    ((0x00200000&(data))>>21)
#define MBIST_get_disp1_dvs_0(data)                                   ((0x001C0000&(data))>>18)
#define MBIST_get_disp1_dvse_0(data)                                  ((0x00020000&(data))>>17)
#define MBIST_get_disp2_dvs_0(data)                                   ((0x0001C000&(data))>>14)
#define MBIST_get_disp2_dvse_0(data)                                  ((0x00002000&(data))>>13)
#define MBIST_get_drf_test_resume(data)                               ((0x00001000&(data))>>12)
#define MBIST_get_drf_start_pause(data)                               ((0x00000800&(data))>>11)
#define MBIST_get_drf_bist_done(data)                                 ((0x00000400&(data))>>10)
#define MBIST_get_cap_drf_bist_fail(data)                             ((0x00000200&(data))>>9)
#define MBIST_get_disp1_drf_bist_fail(data)                           ((0x00000100&(data))>>8)
#define MBIST_get_disp2_drf_bist_fail(data)                           ((0x00000080&(data))>>7)
#define MBIST_get_drf_bist_mode(data)                                 ((0x00000040&(data))>>6)
#define MBIST_get_bist_done(data)                                     ((0x00000020&(data))>>5)
#define MBIST_get_cap_bist_ok(data)                                   ((0x00000010&(data))>>4)
#define MBIST_get_disp1_bist_ok(data)                                 ((0x00000008&(data))>>3)
#define MBIST_get_disp2_bist_ok(data)                                 ((0x00000004&(data))>>2)
#define MBIST_get_bist_rst(data)                                      ((0x00000002&(data))>>1)
#define MBIST_get_bist_en(data)                                       (0x00000001&(data))


#define CAP_CRC_CTRL                                                  0x1802c7a0
#define CAP_CRC_CTRL_reg_addr                                         "0xb802c7a0"
#define CAP_CRC_CTRL_reg                                              0xb802c7a0
#define CAP_CRC_CTRL_inst_addr                                        "0x01E8"
#define CAP_CRC_CTRL_inst                                             0x01E8
#define CAP_CRC_CTRL_r_auto_cmp_en_shift                              (9)
#define CAP_CRC_CTRL_l_auto_cmp_en_shift                              (8)
#define CAP_CRC_CTRL_crc_3d_en_shift                                  (2)
#define CAP_CRC_CTRL_crc_conti_shift                                  (1)
#define CAP_CRC_CTRL_crc_start_shift                                  (0)
#define CAP_CRC_CTRL_r_auto_cmp_en_mask                               (0x00000200)
#define CAP_CRC_CTRL_l_auto_cmp_en_mask                               (0x00000100)
#define CAP_CRC_CTRL_crc_3d_en_mask                                   (0x00000004)
#define CAP_CRC_CTRL_crc_conti_mask                                   (0x00000002)
#define CAP_CRC_CTRL_crc_start_mask                                   (0x00000001)
#define CAP_CRC_CTRL_r_auto_cmp_en(data)                              (0x00000200&((data)<<9))
#define CAP_CRC_CTRL_l_auto_cmp_en(data)                              (0x00000100&((data)<<8))
#define CAP_CRC_CTRL_crc_3d_en(data)                                  (0x00000004&((data)<<2))
#define CAP_CRC_CTRL_crc_conti(data)                                  (0x00000002&((data)<<1))
#define CAP_CRC_CTRL_crc_start(data)                                  (0x00000001&(data))
#define CAP_CRC_CTRL_get_r_auto_cmp_en(data)                          ((0x00000200&(data))>>9)
#define CAP_CRC_CTRL_get_l_auto_cmp_en(data)                          ((0x00000100&(data))>>8)
#define CAP_CRC_CTRL_get_crc_3d_en(data)                              ((0x00000004&(data))>>2)
#define CAP_CRC_CTRL_get_crc_conti(data)                              ((0x00000002&(data))>>1)
#define CAP_CRC_CTRL_get_crc_start(data)                              (0x00000001&(data))


#define CAP_CRC_L_RESULT                                              0x1802c7a4
#define CAP_CRC_L_RESULT_reg_addr                                     "0xb802c7a4"
#define CAP_CRC_L_RESULT_reg                                          0xb802c7a4
#define CAP_CRC_L_RESULT_inst_addr                                    "0x01E9"
#define CAP_CRC_L_RESULT_inst                                         0x01E9
#define CAP_CRC_L_RESULT_crc_l_result_shift                           (0)
#define CAP_CRC_L_RESULT_crc_l_result_mask                            (0xFFFFFFFF)
#define CAP_CRC_L_RESULT_crc_l_result(data)                           (0xFFFFFFFF&(data))
#define CAP_CRC_L_RESULT_get_crc_l_result(data)                       (0xFFFFFFFF&(data))


#define CAP_CRC_R_RESULT                                              0x1802c7a8
#define CAP_CRC_R_RESULT_reg_addr                                     "0xb802c7a8"
#define CAP_CRC_R_RESULT_reg                                          0xb802c7a8
#define CAP_CRC_R_RESULT_inst_addr                                    "0x01EA"
#define CAP_CRC_R_RESULT_inst                                         0x01EA
#define CAP_CRC_R_RESULT_crc_r_result_shift                           (0)
#define CAP_CRC_R_RESULT_crc_r_result_mask                            (0xFFFFFFFF)
#define CAP_CRC_R_RESULT_crc_r_result(data)                           (0xFFFFFFFF&(data))
#define CAP_CRC_R_RESULT_get_crc_r_result(data)                       (0xFFFFFFFF&(data))


#define CAP_L_DES_CRC                                                 0x1802c7ac
#define CAP_L_DES_CRC_reg_addr                                        "0xb802c7ac"
#define CAP_L_DES_CRC_reg                                             0xb802c7ac
#define CAP_L_DES_CRC_inst_addr                                       "0x01EB"
#define CAP_L_DES_CRC_inst                                            0x01EB
#define CAP_L_DES_CRC_l_des_crc_shift                                 (0)
#define CAP_L_DES_CRC_l_des_crc_mask                                  (0xFFFFFFFF)
#define CAP_L_DES_CRC_l_des_crc(data)                                 (0xFFFFFFFF&(data))
#define CAP_L_DES_CRC_get_l_des_crc(data)                             (0xFFFFFFFF&(data))


#define CAP_R_DES_CRC                                                 0x1802c7b0
#define CAP_R_DES_CRC_reg_addr                                        "0xb802c7b0"
#define CAP_R_DES_CRC_reg                                             0xb802c7b0
#define CAP_R_DES_CRC_inst_addr                                       "0x01EC"
#define CAP_R_DES_CRC_inst                                            0x01EC
#define CAP_R_DES_CRC_r_des_crc_shift                                 (0)
#define CAP_R_DES_CRC_r_des_crc_mask                                  (0xFFFFFFFF)
#define CAP_R_DES_CRC_r_des_crc(data)                                 (0xFFFFFFFF&(data))
#define CAP_R_DES_CRC_get_r_des_crc(data)                             (0xFFFFFFFF&(data))


#define CAP_CRC_ERR_CNT                                               0x1802c7b4
#define CAP_CRC_ERR_CNT_reg_addr                                      "0xb802c7b4"
#define CAP_CRC_ERR_CNT_reg                                           0xb802c7b4
#define CAP_CRC_ERR_CNT_inst_addr                                     "0x01ED"
#define CAP_CRC_ERR_CNT_inst                                          0x01ED
#define CAP_CRC_ERR_CNT_r_crc_err_cnt_shift                           (16)
#define CAP_CRC_ERR_CNT_l_crc_err_cnt_shift                           (0)
#define CAP_CRC_ERR_CNT_r_crc_err_cnt_mask                            (0xFFFF0000)
#define CAP_CRC_ERR_CNT_l_crc_err_cnt_mask                            (0x0000FFFF)
#define CAP_CRC_ERR_CNT_r_crc_err_cnt(data)                           (0xFFFF0000&((data)<<16))
#define CAP_CRC_ERR_CNT_l_crc_err_cnt(data)                           (0x0000FFFF&(data))
#define CAP_CRC_ERR_CNT_get_r_crc_err_cnt(data)                       ((0xFFFF0000&(data))>>16)
#define CAP_CRC_ERR_CNT_get_l_crc_err_cnt(data)                       (0x0000FFFF&(data))


#define DISP1_START_ADDR1                                             0x1802c7b8
#define DISP1_START_ADDR1_reg_addr                                    "0xb802c7b8"
#define DISP1_START_ADDR1_reg                                         0xb802c7b8
#define DISP1_START_ADDR1_inst_addr                                   "0x01EE"
#define DISP1_START_ADDR1_inst                                        0x01EE
#define DISP1_START_ADDR1_disp1_start_addr1_shift                     (3)
#define DISP1_START_ADDR1_disp1_start_addr1_mask                      (0x7FFFFFF8)
#define DISP1_START_ADDR1_disp1_start_addr1(data)                     (0x7FFFFFF8&((data)<<3))
#define DISP1_START_ADDR1_get_disp1_start_addr1(data)                 ((0x7FFFFFF8&(data))>>3)


#define DISP1_START_ADDR2                                             0x1802c7bc
#define DISP1_START_ADDR2_reg_addr                                    "0xb802c7bc"
#define DISP1_START_ADDR2_reg                                         0xb802c7bc
#define DISP1_START_ADDR2_inst_addr                                   "0x01EF"
#define DISP1_START_ADDR2_inst                                        0x01EF
#define DISP1_START_ADDR2_disp1_start_addr2_shift                     (3)
#define DISP1_START_ADDR2_disp1_start_addr2_mask                      (0x7FFFFFF8)
#define DISP1_START_ADDR2_disp1_start_addr2(data)                     (0x7FFFFFF8&((data)<<3))
#define DISP1_START_ADDR2_get_disp1_start_addr2(data)                 ((0x7FFFFFF8&(data))>>3)


#define DISP2_START_ADDR1                                             0x1802c7c0
#define DISP2_START_ADDR1_reg_addr                                    "0xb802c7c0"
#define DISP2_START_ADDR1_reg                                         0xb802c7c0
#define DISP2_START_ADDR1_inst_addr                                   "0x01F0"
#define DISP2_START_ADDR1_inst                                        0x01F0
#define DISP2_START_ADDR1_disp2_start_addr1_shift                     (3)
#define DISP2_START_ADDR1_disp2_start_addr1_mask                      (0x7FFFFFF8)
#define DISP2_START_ADDR1_disp2_start_addr1(data)                     (0x7FFFFFF8&((data)<<3))
#define DISP2_START_ADDR1_get_disp2_start_addr1(data)                 ((0x7FFFFFF8&(data))>>3)


#define DISP2_START_ADDR2                                             0x1802c7c4
#define DISP2_START_ADDR2_reg_addr                                    "0xb802c7c4"
#define DISP2_START_ADDR2_reg                                         0xb802c7c4
#define DISP2_START_ADDR2_inst_addr                                   "0x01F1"
#define DISP2_START_ADDR2_inst                                        0x01F1
#define DISP2_START_ADDR2_disp2_start_addr2_shift                     (3)
#define DISP2_START_ADDR2_disp2_start_addr2_mask                      (0x7FFFFFF8)
#define DISP2_START_ADDR2_disp2_start_addr2(data)                     (0x7FFFFFF8&((data)<<3))
#define DISP2_START_ADDR2_get_disp2_start_addr2(data)                 ((0x7FFFFFF8&(data))>>3)
#endif
