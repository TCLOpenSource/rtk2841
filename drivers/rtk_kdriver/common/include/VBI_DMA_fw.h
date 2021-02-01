// This file is generated using the spec version 1.39, firmware template version 1.39and SRIF Parser                                                                                source code SVN rev:802                    Version flow no.:1.1.69
#ifndef _VBI_DMA_REG_H_INCLUDED_
#define _VBI_DMA_REG_H_INCLUDED_

//#define  _VBI_DMA_USE_STRUCT
#ifdef _VBI_DMA_USE_STRUCT

typedef struct
{
    unsigned int    reserved_0:15;
    unsigned int    tve_vbidma_output_4byte_swap_1:1;
    unsigned int    reserved_1:3;
    unsigned int    tve_vbidma_endian_1:1;
    unsigned int    tve_vbidma_buf_num_1:4;
    unsigned int    reserved_2:3;
    unsigned int    tve_vbidma_fetch_num_1:1;
    unsigned int    reserved_3:3;
    unsigned int    tve_vbidma_total_line_1:1;
}REG18019000;

typedef struct
{
    unsigned int    tve_vbidma_edge_trig_auto_vs_1:1;
    unsigned int    tve_vbidma_edge_trig_auto_window_1:1;
    unsigned int    tve_vbidma_edge_trig_1:1;
    unsigned int    tve_vbidma_start_addr_1:29;
}REG18019004;

typedef struct
{
    unsigned int    reset_error_1:1;
    unsigned int    dummy_1:2;
    unsigned int    tve_vbi_read_start_1:13;
    unsigned int    reserved_0:3;
    unsigned int    tve_vbi_read_end_1:13;
}REG18019008;

typedef struct
{
    unsigned int    req_error_1:1;
    unsigned int    bandwidth_error_1:1;
    unsigned int    error_dummy_1:1;
    unsigned int    tve_vbidma_start_addr_now_1:29;
}REG1801900C;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    vbidma_fifo_full_int_1:1;
    unsigned int    vbidma_fifo_empty_int_1:1;
    unsigned int    vbidma_fifo_full_1:1;
    unsigned int    vbidma_fifo_empty_1:1;
    unsigned int    reserved_1:4;
}REG18019010;

typedef struct
{
    unsigned int    reserved_0:15;
    unsigned int    tve_vbidma_output_4byte_swap_2:1;
    unsigned int    reserved_1:3;
    unsigned int    tve_vbidma_endian_2:1;
    unsigned int    tve_vbidma_buf_num_2:4;
    unsigned int    reserved_2:3;
    unsigned int    tve_vbidma_fetch_num_2:1;
    unsigned int    reserved_3:3;
    unsigned int    tve_vbidma_total_line_2:1;
}REG18019020;

typedef struct
{
    unsigned int    tve_vbidma_edge_trig_auto_vs_2:1;
    unsigned int    tve_vbidma_edge_trig_auto_window_2:1;
    unsigned int    tve_vbidma_edge_trig_2:1;
    unsigned int    tve_vbidma_start_addr_2:29;
}REG18019024;

typedef struct
{
    unsigned int    reset_error_2:1;
    unsigned int    dummy_2:2;
    unsigned int    tve_vbi_read_start_2:13;
    unsigned int    reserved_0:3;
    unsigned int    tve_vbi_read_end_2:13;
}REG18019028;

typedef struct
{
    unsigned int    req_error_2:1;
    unsigned int    bandwidth_error_2:1;
    unsigned int    error_dummy_2:1;
    unsigned int    tve_vbidma_start_addr_now_2:29;
}REG1801902C;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    vbidma_fifo_full_int_2:1;
    unsigned int    vbidma_fifo_empty_int_2:1;
    unsigned int    vbidma_fifo_full_2:1;
    unsigned int    vbidma_fifo_empty_2:1;
    unsigned int    reserved_1:4;
}REG18019030;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    mbist_tve_dvse_2:1;
    unsigned int    mbist_tve_dvs_2:4;
    unsigned int    mbist_tve_dvse_1:1;
    unsigned int    mbist_tve_dvs_1:4;
}REG18019040;

typedef struct
{
    unsigned int    reserved_0:30;
    unsigned int    bist_mode_vbidma_1:1;
    unsigned int    bist_mode_vbidma_2:1;
}REG18019044;

typedef struct
{
    unsigned int    reserved_0:30;
    unsigned int    drf_bist_mode_vbidma_1:1;
    unsigned int    drf_bist_mode_vbidma_2:1;
}REG18019048;

typedef struct
{
    unsigned int    reserved_0:30;
    unsigned int    drf_test_resume_vbidma_1:1;
    unsigned int    drf_test_resume_vbidma_2:1;
}REG1801904C;

typedef struct
{
    unsigned int    reserved_0:30;
    unsigned int    mbist_ls_cntl_1:1;
    unsigned int    mbist_ls_cntl_2:1;
}REG18019050;

typedef struct
{
    unsigned int    reserved_0:30;
    unsigned int    bist_done_vbidma_1:1;
    unsigned int    bist_done_vbidma_2:1;
}REG18019054;

typedef struct
{
    unsigned int    reserved_0:30;
    unsigned int    drf_bist_done_vbidma_1:1;
    unsigned int    drf_bist_done_vbidma_2:1;
}REG18019058;

typedef struct
{
    unsigned int    reserved_0:30;
    unsigned int    bist_fail_vbidma_1:1;
    unsigned int    bist_fail_vbidma_2:1;
}REG1801905C;

typedef struct
{
    unsigned int    reserved_0:30;
    unsigned int    drf_bist_fail_vbidma_1:1;
    unsigned int    drf_bist_fail_vbidma_2:1;
}REG18019060;

typedef struct
{
    unsigned int    reserved_0:30;
    unsigned int    drf_start_pause_vbidma_1:1;
    unsigned int    drf_start_pause_vbidma_2:1;
}REG18019064;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    vline_1:13;
    unsigned int    reserved_1:3;
    unsigned int    vline_2:13;
}REG18019070;
#endif


#define DISP2TVEVBIDMA_CTRL                                           0x18019000
#define DISP2TVEVBIDMA_CTRL_reg_addr                                  "0xb8019000"
#define DISP2TVEVBIDMA_CTRL_reg                                       0xb8019000
#define DISP2TVEVBIDMA_CTRL_inst_addr                                 "0x0000"
#define DISP2TVEVBIDMA_CTRL_inst                                      0x0000
#define set_DISP2TVEVBIDMA_CTRL_reg(data)                             (*((volatile unsigned int*)DISP2TVEVBIDMA_CTRL_reg)=data)
#define get_DISP2TVEVBIDMA_CTRL_reg                                   (*((volatile unsigned int*)DISP2TVEVBIDMA_CTRL_reg))
#define DISP2TVEVBIDMA_CTRL_tve_vbidma_output_4byte_swap_1_shift      (16)
#define DISP2TVEVBIDMA_CTRL_tve_vbidma_endian_1_shift                 (12)
#define DISP2TVEVBIDMA_CTRL_tve_vbidma_buf_num_1_shift                (8)
#define DISP2TVEVBIDMA_CTRL_tve_vbidma_fetch_num_1_shift              (4)
#define DISP2TVEVBIDMA_CTRL_tve_vbidma_total_line_1_shift             (0)
#define DISP2TVEVBIDMA_CTRL_tve_vbidma_output_4byte_swap_1_mask       (0x00010000)
#define DISP2TVEVBIDMA_CTRL_tve_vbidma_endian_1_mask                  (0x00001000)
#define DISP2TVEVBIDMA_CTRL_tve_vbidma_buf_num_1_mask                 (0x00000F00)
#define DISP2TVEVBIDMA_CTRL_tve_vbidma_fetch_num_1_mask               (0x00000010)
#define DISP2TVEVBIDMA_CTRL_tve_vbidma_total_line_1_mask              (0x00000001)
#define DISP2TVEVBIDMA_CTRL_tve_vbidma_output_4byte_swap_1(data)      (0x00010000&((data)<<16))
#define DISP2TVEVBIDMA_CTRL_tve_vbidma_endian_1(data)                 (0x00001000&((data)<<12))
#define DISP2TVEVBIDMA_CTRL_tve_vbidma_buf_num_1(data)                (0x00000F00&((data)<<8))
#define DISP2TVEVBIDMA_CTRL_tve_vbidma_fetch_num_1(data)              (0x00000010&((data)<<4))
#define DISP2TVEVBIDMA_CTRL_tve_vbidma_total_line_1(data)             (0x00000001&(data))
#define DISP2TVEVBIDMA_CTRL_get_tve_vbidma_output_4byte_swap_1(data)  ((0x00010000&(data))>>16)
#define DISP2TVEVBIDMA_CTRL_get_tve_vbidma_endian_1(data)             ((0x00001000&(data))>>12)
#define DISP2TVEVBIDMA_CTRL_get_tve_vbidma_buf_num_1(data)            ((0x00000F00&(data))>>8)
#define DISP2TVEVBIDMA_CTRL_get_tve_vbidma_fetch_num_1(data)          ((0x00000010&(data))>>4)
#define DISP2TVEVBIDMA_CTRL_get_tve_vbidma_total_line_1(data)         (0x00000001&(data))


#define DISP2TVEVBIDMA_START                                          0x18019004
#define DISP2TVEVBIDMA_START_reg_addr                                 "0xb8019004"
#define DISP2TVEVBIDMA_START_reg                                      0xb8019004
#define DISP2TVEVBIDMA_START_inst_addr                                "0x0001"
#define DISP2TVEVBIDMA_START_inst                                     0x0001
#define set_DISP2TVEVBIDMA_START_reg(data)                            (*((volatile unsigned int*)DISP2TVEVBIDMA_START_reg)=data)
#define get_DISP2TVEVBIDMA_START_reg                                  (*((volatile unsigned int*)DISP2TVEVBIDMA_START_reg))
#define DISP2TVEVBIDMA_START_tve_vbidma_edge_trig_auto_vs_1_shift     (31)
#define DISP2TVEVBIDMA_START_tve_vbidma_edge_trig_auto_window_1_shift (30)
#define DISP2TVEVBIDMA_START_tve_vbidma_edge_trig_1_shift             (29)
#define DISP2TVEVBIDMA_START_tve_vbidma_start_addr_1_shift            (0)
#define DISP2TVEVBIDMA_START_tve_vbidma_edge_trig_auto_vs_1_mask      (0x80000000)
#define DISP2TVEVBIDMA_START_tve_vbidma_edge_trig_auto_window_1_mask  (0x40000000)
#define DISP2TVEVBIDMA_START_tve_vbidma_edge_trig_1_mask              (0x20000000)
#define DISP2TVEVBIDMA_START_tve_vbidma_start_addr_1_mask             (0x1FFFFFFF)
#define DISP2TVEVBIDMA_START_tve_vbidma_edge_trig_auto_vs_1(data)     (0x80000000&((data)<<31))
#define DISP2TVEVBIDMA_START_tve_vbidma_edge_trig_auto_window_1(data) (0x40000000&((data)<<30))
#define DISP2TVEVBIDMA_START_tve_vbidma_edge_trig_1(data)             (0x20000000&((data)<<29))
#define DISP2TVEVBIDMA_START_tve_vbidma_start_addr_1(data)            (0x1FFFFFFF&(data))
#define DISP2TVEVBIDMA_START_get_tve_vbidma_edge_trig_auto_vs_1(data) ((0x80000000&(data))>>31)
#define DISP2TVEVBIDMA_START_get_tve_vbidma_edge_trig_auto_window_1(data)  ((0x40000000&(data))>>30)
#define DISP2TVEVBIDMA_START_get_tve_vbidma_edge_trig_1(data)         ((0x20000000&(data))>>29)
#define DISP2TVEVBIDMA_START_get_tve_vbidma_start_addr_1(data)        (0x1FFFFFFF&(data))


#define DISP2TVEVBIDMA_READ_WINDOW                                    0x18019008
#define DISP2TVEVBIDMA_READ_WINDOW_reg_addr                           "0xb8019008"
#define DISP2TVEVBIDMA_READ_WINDOW_reg                                0xb8019008
#define DISP2TVEVBIDMA_READ_WINDOW_inst_addr                          "0x0002"
#define DISP2TVEVBIDMA_READ_WINDOW_inst                               0x0002
#define set_DISP2TVEVBIDMA_READ_WINDOW_reg(data)                      (*((volatile unsigned int*)DISP2TVEVBIDMA_READ_WINDOW_reg)=data)
#define get_DISP2TVEVBIDMA_READ_WINDOW_reg                            (*((volatile unsigned int*)DISP2TVEVBIDMA_READ_WINDOW_reg))
#define DISP2TVEVBIDMA_READ_WINDOW_reset_error_1_shift                (31)
#define DISP2TVEVBIDMA_READ_WINDOW_dummy_1_shift                      (29)
#define DISP2TVEVBIDMA_READ_WINDOW_tve_vbi_read_start_1_shift         (16)
#define DISP2TVEVBIDMA_READ_WINDOW_tve_vbi_read_end_1_shift           (0)
#define DISP2TVEVBIDMA_READ_WINDOW_reset_error_1_mask                 (0x80000000)
#define DISP2TVEVBIDMA_READ_WINDOW_dummy_1_mask                       (0x60000000)
#define DISP2TVEVBIDMA_READ_WINDOW_tve_vbi_read_start_1_mask          (0x1FFF0000)
#define DISP2TVEVBIDMA_READ_WINDOW_tve_vbi_read_end_1_mask            (0x00001FFF)
#define DISP2TVEVBIDMA_READ_WINDOW_reset_error_1(data)                (0x80000000&((data)<<31))
#define DISP2TVEVBIDMA_READ_WINDOW_dummy_1(data)                      (0x60000000&((data)<<29))
#define DISP2TVEVBIDMA_READ_WINDOW_tve_vbi_read_start_1(data)         (0x1FFF0000&((data)<<16))
#define DISP2TVEVBIDMA_READ_WINDOW_tve_vbi_read_end_1(data)           (0x00001FFF&(data))
#define DISP2TVEVBIDMA_READ_WINDOW_get_reset_error_1(data)            ((0x80000000&(data))>>31)
#define DISP2TVEVBIDMA_READ_WINDOW_get_dummy_1(data)                  ((0x60000000&(data))>>29)
#define DISP2TVEVBIDMA_READ_WINDOW_get_tve_vbi_read_start_1(data)     ((0x1FFF0000&(data))>>16)
#define DISP2TVEVBIDMA_READ_WINDOW_get_tve_vbi_read_end_1(data)       (0x00001FFF&(data))


#define DISP2TVEVBIDMA_START_STATUS                                   0x1801900c
#define DISP2TVEVBIDMA_START_STATUS_reg_addr                          "0xb801900c"
#define DISP2TVEVBIDMA_START_STATUS_reg                               0xb801900c
#define DISP2TVEVBIDMA_START_STATUS_inst_addr                         "0x0003"
#define DISP2TVEVBIDMA_START_STATUS_inst                              0x0003
#define set_DISP2TVEVBIDMA_START_STATUS_reg(data)                     (*((volatile unsigned int*)DISP2TVEVBIDMA_START_STATUS_reg)=data)
#define get_DISP2TVEVBIDMA_START_STATUS_reg                           (*((volatile unsigned int*)DISP2TVEVBIDMA_START_STATUS_reg))
#define DISP2TVEVBIDMA_START_STATUS_req_error_1_shift                 (31)
#define DISP2TVEVBIDMA_START_STATUS_bandwidth_error_1_shift           (30)
#define DISP2TVEVBIDMA_START_STATUS_error_dummy_1_shift               (29)
#define DISP2TVEVBIDMA_START_STATUS_tve_vbidma_start_addr_now_1_shift (0)
#define DISP2TVEVBIDMA_START_STATUS_req_error_1_mask                  (0x80000000)
#define DISP2TVEVBIDMA_START_STATUS_bandwidth_error_1_mask            (0x40000000)
#define DISP2TVEVBIDMA_START_STATUS_error_dummy_1_mask                (0x20000000)
#define DISP2TVEVBIDMA_START_STATUS_tve_vbidma_start_addr_now_1_mask  (0x1FFFFFFF)
#define DISP2TVEVBIDMA_START_STATUS_req_error_1(data)                 (0x80000000&((data)<<31))
#define DISP2TVEVBIDMA_START_STATUS_bandwidth_error_1(data)           (0x40000000&((data)<<30))
#define DISP2TVEVBIDMA_START_STATUS_error_dummy_1(data)               (0x20000000&((data)<<29))
#define DISP2TVEVBIDMA_START_STATUS_tve_vbidma_start_addr_now_1(data) (0x1FFFFFFF&(data))
#define DISP2TVEVBIDMA_START_STATUS_get_req_error_1(data)             ((0x80000000&(data))>>31)
#define DISP2TVEVBIDMA_START_STATUS_get_bandwidth_error_1(data)       ((0x40000000&(data))>>30)
#define DISP2TVEVBIDMA_START_STATUS_get_error_dummy_1(data)           ((0x20000000&(data))>>29)
#define DISP2TVEVBIDMA_START_STATUS_get_tve_vbidma_start_addr_now_1(data)  (0x1FFFFFFF&(data))


#define DISP2TVEVBIDMA_FIFOSTATUS                                     0x18019010
#define DISP2TVEVBIDMA_FIFOSTATUS_reg_addr                            "0xb8019010"
#define DISP2TVEVBIDMA_FIFOSTATUS_reg                                 0xb8019010
#define DISP2TVEVBIDMA_FIFOSTATUS_inst_addr                           "0x0004"
#define DISP2TVEVBIDMA_FIFOSTATUS_inst                                0x0004
#define set_DISP2TVEVBIDMA_FIFOSTATUS_reg(data)                       (*((volatile unsigned int*)DISP2TVEVBIDMA_FIFOSTATUS_reg)=data)
#define get_DISP2TVEVBIDMA_FIFOSTATUS_reg                             (*((volatile unsigned int*)DISP2TVEVBIDMA_FIFOSTATUS_reg))
#define DISP2TVEVBIDMA_FIFOSTATUS_vbidma_fifo_full_int_1_shift        (7)
#define DISP2TVEVBIDMA_FIFOSTATUS_vbidma_fifo_empty_int_1_shift       (6)
#define DISP2TVEVBIDMA_FIFOSTATUS_vbidma_fifo_full_1_shift            (5)
#define DISP2TVEVBIDMA_FIFOSTATUS_vbidma_fifo_empty_1_shift           (4)
#define DISP2TVEVBIDMA_FIFOSTATUS_vbidma_fifo_full_int_1_mask         (0x00000080)
#define DISP2TVEVBIDMA_FIFOSTATUS_vbidma_fifo_empty_int_1_mask        (0x00000040)
#define DISP2TVEVBIDMA_FIFOSTATUS_vbidma_fifo_full_1_mask             (0x00000020)
#define DISP2TVEVBIDMA_FIFOSTATUS_vbidma_fifo_empty_1_mask            (0x00000010)
#define DISP2TVEVBIDMA_FIFOSTATUS_vbidma_fifo_full_int_1(data)        (0x00000080&((data)<<7))
#define DISP2TVEVBIDMA_FIFOSTATUS_vbidma_fifo_empty_int_1(data)       (0x00000040&((data)<<6))
#define DISP2TVEVBIDMA_FIFOSTATUS_vbidma_fifo_full_1(data)            (0x00000020&((data)<<5))
#define DISP2TVEVBIDMA_FIFOSTATUS_vbidma_fifo_empty_1(data)           (0x00000010&((data)<<4))
#define DISP2TVEVBIDMA_FIFOSTATUS_get_vbidma_fifo_full_int_1(data)    ((0x00000080&(data))>>7)
#define DISP2TVEVBIDMA_FIFOSTATUS_get_vbidma_fifo_empty_int_1(data)   ((0x00000040&(data))>>6)
#define DISP2TVEVBIDMA_FIFOSTATUS_get_vbidma_fifo_full_1(data)        ((0x00000020&(data))>>5)
#define DISP2TVEVBIDMA_FIFOSTATUS_get_vbidma_fifo_empty_1(data)       ((0x00000010&(data))>>4)


#define DISP2TVEVBIDMA_CTRL_2                                         0x18019020
#define DISP2TVEVBIDMA_CTRL_2_reg_addr                                "0xb8019020"
#define DISP2TVEVBIDMA_CTRL_2_reg                                     0xb8019020
#define DISP2TVEVBIDMA_CTRL_2_inst_addr                               "0x0008"
#define DISP2TVEVBIDMA_CTRL_2_inst                                    0x0008
#define set_DISP2TVEVBIDMA_CTRL_2_reg(data)                           (*((volatile unsigned int*)DISP2TVEVBIDMA_CTRL_2_reg)=data)
#define get_DISP2TVEVBIDMA_CTRL_2_reg                                 (*((volatile unsigned int*)DISP2TVEVBIDMA_CTRL_2_reg))
#define DISP2TVEVBIDMA_CTRL_2_tve_vbidma_output_4byte_swap_2_shift    (16)
#define DISP2TVEVBIDMA_CTRL_2_tve_vbidma_endian_2_shift               (12)
#define DISP2TVEVBIDMA_CTRL_2_tve_vbidma_buf_num_2_shift              (8)
#define DISP2TVEVBIDMA_CTRL_2_tve_vbidma_fetch_num_2_shift            (4)
#define DISP2TVEVBIDMA_CTRL_2_tve_vbidma_total_line_2_shift           (0)
#define DISP2TVEVBIDMA_CTRL_2_tve_vbidma_output_4byte_swap_2_mask     (0x00010000)
#define DISP2TVEVBIDMA_CTRL_2_tve_vbidma_endian_2_mask                (0x00001000)
#define DISP2TVEVBIDMA_CTRL_2_tve_vbidma_buf_num_2_mask               (0x00000F00)
#define DISP2TVEVBIDMA_CTRL_2_tve_vbidma_fetch_num_2_mask             (0x00000010)
#define DISP2TVEVBIDMA_CTRL_2_tve_vbidma_total_line_2_mask            (0x00000001)
#define DISP2TVEVBIDMA_CTRL_2_tve_vbidma_output_4byte_swap_2(data)    (0x00010000&((data)<<16))
#define DISP2TVEVBIDMA_CTRL_2_tve_vbidma_endian_2(data)               (0x00001000&((data)<<12))
#define DISP2TVEVBIDMA_CTRL_2_tve_vbidma_buf_num_2(data)              (0x00000F00&((data)<<8))
#define DISP2TVEVBIDMA_CTRL_2_tve_vbidma_fetch_num_2(data)            (0x00000010&((data)<<4))
#define DISP2TVEVBIDMA_CTRL_2_tve_vbidma_total_line_2(data)           (0x00000001&(data))
#define DISP2TVEVBIDMA_CTRL_2_get_tve_vbidma_output_4byte_swap_2(data)  ((0x00010000&(data))>>16)
#define DISP2TVEVBIDMA_CTRL_2_get_tve_vbidma_endian_2(data)           ((0x00001000&(data))>>12)
#define DISP2TVEVBIDMA_CTRL_2_get_tve_vbidma_buf_num_2(data)          ((0x00000F00&(data))>>8)
#define DISP2TVEVBIDMA_CTRL_2_get_tve_vbidma_fetch_num_2(data)        ((0x00000010&(data))>>4)
#define DISP2TVEVBIDMA_CTRL_2_get_tve_vbidma_total_line_2(data)       (0x00000001&(data))


#define DISP2TVEVBIDMA_START_2                                        0x18019024
#define DISP2TVEVBIDMA_START_2_reg_addr                               "0xb8019024"
#define DISP2TVEVBIDMA_START_2_reg                                    0xb8019024
#define DISP2TVEVBIDMA_START_2_inst_addr                              "0x0009"
#define DISP2TVEVBIDMA_START_2_inst                                   0x0009
#define set_DISP2TVEVBIDMA_START_2_reg(data)                          (*((volatile unsigned int*)DISP2TVEVBIDMA_START_2_reg)=data)
#define get_DISP2TVEVBIDMA_START_2_reg                                (*((volatile unsigned int*)DISP2TVEVBIDMA_START_2_reg))
#define DISP2TVEVBIDMA_START_2_tve_vbidma_edge_trig_auto_vs_2_shift   (31)
#define DISP2TVEVBIDMA_START_2_tve_vbidma_edge_trig_auto_window_2_shift  (30)
#define DISP2TVEVBIDMA_START_2_tve_vbidma_edge_trig_2_shift           (29)
#define DISP2TVEVBIDMA_START_2_tve_vbidma_start_addr_2_shift          (0)
#define DISP2TVEVBIDMA_START_2_tve_vbidma_edge_trig_auto_vs_2_mask    (0x80000000)
#define DISP2TVEVBIDMA_START_2_tve_vbidma_edge_trig_auto_window_2_mask  (0x40000000)
#define DISP2TVEVBIDMA_START_2_tve_vbidma_edge_trig_2_mask            (0x20000000)
#define DISP2TVEVBIDMA_START_2_tve_vbidma_start_addr_2_mask           (0x1FFFFFFF)
#define DISP2TVEVBIDMA_START_2_tve_vbidma_edge_trig_auto_vs_2(data)   (0x80000000&((data)<<31))
#define DISP2TVEVBIDMA_START_2_tve_vbidma_edge_trig_auto_window_2(data)  (0x40000000&((data)<<30))
#define DISP2TVEVBIDMA_START_2_tve_vbidma_edge_trig_2(data)           (0x20000000&((data)<<29))
#define DISP2TVEVBIDMA_START_2_tve_vbidma_start_addr_2(data)          (0x1FFFFFFF&(data))
#define DISP2TVEVBIDMA_START_2_get_tve_vbidma_edge_trig_auto_vs_2(data)  ((0x80000000&(data))>>31)
#define DISP2TVEVBIDMA_START_2_get_tve_vbidma_edge_trig_auto_window_2(data)  ((0x40000000&(data))>>30)
#define DISP2TVEVBIDMA_START_2_get_tve_vbidma_edge_trig_2(data)       ((0x20000000&(data))>>29)
#define DISP2TVEVBIDMA_START_2_get_tve_vbidma_start_addr_2(data)      (0x1FFFFFFF&(data))


#define DISP2TVEVBIDMA_READ_WINDOW_2                                  0x18019028
#define DISP2TVEVBIDMA_READ_WINDOW_2_reg_addr                         "0xb8019028"
#define DISP2TVEVBIDMA_READ_WINDOW_2_reg                              0xb8019028
#define DISP2TVEVBIDMA_READ_WINDOW_2_inst_addr                        "0x000A"
#define DISP2TVEVBIDMA_READ_WINDOW_2_inst                             0x000A
#define set_DISP2TVEVBIDMA_READ_WINDOW_2_reg(data)                    (*((volatile unsigned int*)DISP2TVEVBIDMA_READ_WINDOW_2_reg)=data)
#define get_DISP2TVEVBIDMA_READ_WINDOW_2_reg                          (*((volatile unsigned int*)DISP2TVEVBIDMA_READ_WINDOW_2_reg))
#define DISP2TVEVBIDMA_READ_WINDOW_2_reset_error_2_shift              (31)
#define DISP2TVEVBIDMA_READ_WINDOW_2_dummy_2_shift                    (29)
#define DISP2TVEVBIDMA_READ_WINDOW_2_tve_vbi_read_start_2_shift       (16)
#define DISP2TVEVBIDMA_READ_WINDOW_2_tve_vbi_read_end_2_shift         (0)
#define DISP2TVEVBIDMA_READ_WINDOW_2_reset_error_2_mask               (0x80000000)
#define DISP2TVEVBIDMA_READ_WINDOW_2_dummy_2_mask                     (0x60000000)
#define DISP2TVEVBIDMA_READ_WINDOW_2_tve_vbi_read_start_2_mask        (0x1FFF0000)
#define DISP2TVEVBIDMA_READ_WINDOW_2_tve_vbi_read_end_2_mask          (0x00001FFF)
#define DISP2TVEVBIDMA_READ_WINDOW_2_reset_error_2(data)              (0x80000000&((data)<<31))
#define DISP2TVEVBIDMA_READ_WINDOW_2_dummy_2(data)                    (0x60000000&((data)<<29))
#define DISP2TVEVBIDMA_READ_WINDOW_2_tve_vbi_read_start_2(data)       (0x1FFF0000&((data)<<16))
#define DISP2TVEVBIDMA_READ_WINDOW_2_tve_vbi_read_end_2(data)         (0x00001FFF&(data))
#define DISP2TVEVBIDMA_READ_WINDOW_2_get_reset_error_2(data)          ((0x80000000&(data))>>31)
#define DISP2TVEVBIDMA_READ_WINDOW_2_get_dummy_2(data)                ((0x60000000&(data))>>29)
#define DISP2TVEVBIDMA_READ_WINDOW_2_get_tve_vbi_read_start_2(data)   ((0x1FFF0000&(data))>>16)
#define DISP2TVEVBIDMA_READ_WINDOW_2_get_tve_vbi_read_end_2(data)     (0x00001FFF&(data))


#define DISP2TVEVBIDMA_START_STATUS_2                                 0x1801902c
#define DISP2TVEVBIDMA_START_STATUS_2_reg_addr                        "0xb801902c"
#define DISP2TVEVBIDMA_START_STATUS_2_reg                             0xb801902c
#define DISP2TVEVBIDMA_START_STATUS_2_inst_addr                       "0x000B"
#define DISP2TVEVBIDMA_START_STATUS_2_inst                            0x000B
#define set_DISP2TVEVBIDMA_START_STATUS_2_reg(data)                   (*((volatile unsigned int*)DISP2TVEVBIDMA_START_STATUS_2_reg)=data)
#define get_DISP2TVEVBIDMA_START_STATUS_2_reg                         (*((volatile unsigned int*)DISP2TVEVBIDMA_START_STATUS_2_reg))
#define DISP2TVEVBIDMA_START_STATUS_2_req_error_2_shift               (31)
#define DISP2TVEVBIDMA_START_STATUS_2_bandwidth_error_2_shift         (30)
#define DISP2TVEVBIDMA_START_STATUS_2_error_dummy_2_shift             (29)
#define DISP2TVEVBIDMA_START_STATUS_2_tve_vbidma_start_addr_now_2_shift  (0)
#define DISP2TVEVBIDMA_START_STATUS_2_req_error_2_mask                (0x80000000)
#define DISP2TVEVBIDMA_START_STATUS_2_bandwidth_error_2_mask          (0x40000000)
#define DISP2TVEVBIDMA_START_STATUS_2_error_dummy_2_mask              (0x20000000)
#define DISP2TVEVBIDMA_START_STATUS_2_tve_vbidma_start_addr_now_2_mask  (0x1FFFFFFF)
#define DISP2TVEVBIDMA_START_STATUS_2_req_error_2(data)               (0x80000000&((data)<<31))
#define DISP2TVEVBIDMA_START_STATUS_2_bandwidth_error_2(data)         (0x40000000&((data)<<30))
#define DISP2TVEVBIDMA_START_STATUS_2_error_dummy_2(data)             (0x20000000&((data)<<29))
#define DISP2TVEVBIDMA_START_STATUS_2_tve_vbidma_start_addr_now_2(data)  (0x1FFFFFFF&(data))
#define DISP2TVEVBIDMA_START_STATUS_2_get_req_error_2(data)           ((0x80000000&(data))>>31)
#define DISP2TVEVBIDMA_START_STATUS_2_get_bandwidth_error_2(data)     ((0x40000000&(data))>>30)
#define DISP2TVEVBIDMA_START_STATUS_2_get_error_dummy_2(data)         ((0x20000000&(data))>>29)
#define DISP2TVEVBIDMA_START_STATUS_2_get_tve_vbidma_start_addr_now_2(data)  (0x1FFFFFFF&(data))


#define DISP2TVEVBIDMA_FIFOSTATUS_2                                   0x18019030
#define DISP2TVEVBIDMA_FIFOSTATUS_2_reg_addr                          "0xb8019030"
#define DISP2TVEVBIDMA_FIFOSTATUS_2_reg                               0xb8019030
#define DISP2TVEVBIDMA_FIFOSTATUS_2_inst_addr                         "0x000C"
#define DISP2TVEVBIDMA_FIFOSTATUS_2_inst                              0x000C
#define set_DISP2TVEVBIDMA_FIFOSTATUS_2_reg(data)                     (*((volatile unsigned int*)DISP2TVEVBIDMA_FIFOSTATUS_2_reg)=data)
#define get_DISP2TVEVBIDMA_FIFOSTATUS_2_reg                           (*((volatile unsigned int*)DISP2TVEVBIDMA_FIFOSTATUS_2_reg))
#define DISP2TVEVBIDMA_FIFOSTATUS_2_vbidma_fifo_full_int_2_shift      (7)
#define DISP2TVEVBIDMA_FIFOSTATUS_2_vbidma_fifo_empty_int_2_shift     (6)
#define DISP2TVEVBIDMA_FIFOSTATUS_2_vbidma_fifo_full_2_shift          (5)
#define DISP2TVEVBIDMA_FIFOSTATUS_2_vbidma_fifo_empty_2_shift         (4)
#define DISP2TVEVBIDMA_FIFOSTATUS_2_vbidma_fifo_full_int_2_mask       (0x00000080)
#define DISP2TVEVBIDMA_FIFOSTATUS_2_vbidma_fifo_empty_int_2_mask      (0x00000040)
#define DISP2TVEVBIDMA_FIFOSTATUS_2_vbidma_fifo_full_2_mask           (0x00000020)
#define DISP2TVEVBIDMA_FIFOSTATUS_2_vbidma_fifo_empty_2_mask          (0x00000010)
#define DISP2TVEVBIDMA_FIFOSTATUS_2_vbidma_fifo_full_int_2(data)      (0x00000080&((data)<<7))
#define DISP2TVEVBIDMA_FIFOSTATUS_2_vbidma_fifo_empty_int_2(data)     (0x00000040&((data)<<6))
#define DISP2TVEVBIDMA_FIFOSTATUS_2_vbidma_fifo_full_2(data)          (0x00000020&((data)<<5))
#define DISP2TVEVBIDMA_FIFOSTATUS_2_vbidma_fifo_empty_2(data)         (0x00000010&((data)<<4))
#define DISP2TVEVBIDMA_FIFOSTATUS_2_get_vbidma_fifo_full_int_2(data)  ((0x00000080&(data))>>7)
#define DISP2TVEVBIDMA_FIFOSTATUS_2_get_vbidma_fifo_empty_int_2(data) ((0x00000040&(data))>>6)
#define DISP2TVEVBIDMA_FIFOSTATUS_2_get_vbidma_fifo_full_2(data)      ((0x00000020&(data))>>5)
#define DISP2TVEVBIDMA_FIFOSTATUS_2_get_vbidma_fifo_empty_2(data)     ((0x00000010&(data))>>4)


#define DISP2TVEVBIDMA_BIST_DVS                                       0x18019040
#define DISP2TVEVBIDMA_BIST_DVS_reg_addr                              "0xb8019040"
#define DISP2TVEVBIDMA_BIST_DVS_reg                                   0xb8019040
#define DISP2TVEVBIDMA_BIST_DVS_inst_addr                             "0x0010"
#define DISP2TVEVBIDMA_BIST_DVS_inst                                  0x0010
#define set_DISP2TVEVBIDMA_BIST_DVS_reg(data)                         (*((volatile unsigned int*)DISP2TVEVBIDMA_BIST_DVS_reg)=data)
#define get_DISP2TVEVBIDMA_BIST_DVS_reg                               (*((volatile unsigned int*)DISP2TVEVBIDMA_BIST_DVS_reg))
#define DISP2TVEVBIDMA_BIST_DVS_mbist_tve_dvse_2_shift                (9)
#define DISP2TVEVBIDMA_BIST_DVS_mbist_tve_dvs_2_shift                 (5)
#define DISP2TVEVBIDMA_BIST_DVS_mbist_tve_dvse_1_shift                (4)
#define DISP2TVEVBIDMA_BIST_DVS_mbist_tve_dvs_1_shift                 (0)
#define DISP2TVEVBIDMA_BIST_DVS_mbist_tve_dvse_2_mask                 (0x00000200)
#define DISP2TVEVBIDMA_BIST_DVS_mbist_tve_dvs_2_mask                  (0x000001E0)
#define DISP2TVEVBIDMA_BIST_DVS_mbist_tve_dvse_1_mask                 (0x00000010)
#define DISP2TVEVBIDMA_BIST_DVS_mbist_tve_dvs_1_mask                  (0x0000000F)
#define DISP2TVEVBIDMA_BIST_DVS_mbist_tve_dvse_2(data)                (0x00000200&((data)<<9))
#define DISP2TVEVBIDMA_BIST_DVS_mbist_tve_dvs_2(data)                 (0x000001E0&((data)<<5))
#define DISP2TVEVBIDMA_BIST_DVS_mbist_tve_dvse_1(data)                (0x00000010&((data)<<4))
#define DISP2TVEVBIDMA_BIST_DVS_mbist_tve_dvs_1(data)                 (0x0000000F&(data))
#define DISP2TVEVBIDMA_BIST_DVS_get_mbist_tve_dvse_2(data)            ((0x00000200&(data))>>9)
#define DISP2TVEVBIDMA_BIST_DVS_get_mbist_tve_dvs_2(data)             ((0x000001E0&(data))>>5)
#define DISP2TVEVBIDMA_BIST_DVS_get_mbist_tve_dvse_1(data)            ((0x00000010&(data))>>4)
#define DISP2TVEVBIDMA_BIST_DVS_get_mbist_tve_dvs_1(data)             (0x0000000F&(data))


#define DISP2TVEVBIDMA_BIST_MODE                                      0x18019044
#define DISP2TVEVBIDMA_BIST_MODE_reg_addr                             "0xb8019044"
#define DISP2TVEVBIDMA_BIST_MODE_reg                                  0xb8019044
#define DISP2TVEVBIDMA_BIST_MODE_inst_addr                            "0x0011"
#define DISP2TVEVBIDMA_BIST_MODE_inst                                 0x0011
#define set_DISP2TVEVBIDMA_BIST_MODE_reg(data)                        (*((volatile unsigned int*)DISP2TVEVBIDMA_BIST_MODE_reg)=data)
#define get_DISP2TVEVBIDMA_BIST_MODE_reg                              (*((volatile unsigned int*)DISP2TVEVBIDMA_BIST_MODE_reg))
#define DISP2TVEVBIDMA_BIST_MODE_bist_mode_vbidma_1_shift             (1)
#define DISP2TVEVBIDMA_BIST_MODE_bist_mode_vbidma_2_shift             (0)
#define DISP2TVEVBIDMA_BIST_MODE_bist_mode_vbidma_1_mask              (0x00000002)
#define DISP2TVEVBIDMA_BIST_MODE_bist_mode_vbidma_2_mask              (0x00000001)
#define DISP2TVEVBIDMA_BIST_MODE_bist_mode_vbidma_1(data)             (0x00000002&((data)<<1))
#define DISP2TVEVBIDMA_BIST_MODE_bist_mode_vbidma_2(data)             (0x00000001&(data))
#define DISP2TVEVBIDMA_BIST_MODE_get_bist_mode_vbidma_1(data)         ((0x00000002&(data))>>1)
#define DISP2TVEVBIDMA_BIST_MODE_get_bist_mode_vbidma_2(data)         (0x00000001&(data))


#define DISP2TVEVBIDMA_DRF_BIST_MODE                                  0x18019048
#define DISP2TVEVBIDMA_DRF_BIST_MODE_reg_addr                         "0xb8019048"
#define DISP2TVEVBIDMA_DRF_BIST_MODE_reg                              0xb8019048
#define DISP2TVEVBIDMA_DRF_BIST_MODE_inst_addr                        "0x0012"
#define DISP2TVEVBIDMA_DRF_BIST_MODE_inst                             0x0012
#define set_DISP2TVEVBIDMA_DRF_BIST_MODE_reg(data)                    (*((volatile unsigned int*)DISP2TVEVBIDMA_DRF_BIST_MODE_reg)=data)
#define get_DISP2TVEVBIDMA_DRF_BIST_MODE_reg                          (*((volatile unsigned int*)DISP2TVEVBIDMA_DRF_BIST_MODE_reg))
#define DISP2TVEVBIDMA_DRF_BIST_MODE_drf_bist_mode_vbidma_1_shift     (1)
#define DISP2TVEVBIDMA_DRF_BIST_MODE_drf_bist_mode_vbidma_2_shift     (0)
#define DISP2TVEVBIDMA_DRF_BIST_MODE_drf_bist_mode_vbidma_1_mask      (0x00000002)
#define DISP2TVEVBIDMA_DRF_BIST_MODE_drf_bist_mode_vbidma_2_mask      (0x00000001)
#define DISP2TVEVBIDMA_DRF_BIST_MODE_drf_bist_mode_vbidma_1(data)     (0x00000002&((data)<<1))
#define DISP2TVEVBIDMA_DRF_BIST_MODE_drf_bist_mode_vbidma_2(data)     (0x00000001&(data))
#define DISP2TVEVBIDMA_DRF_BIST_MODE_get_drf_bist_mode_vbidma_1(data) ((0x00000002&(data))>>1)
#define DISP2TVEVBIDMA_DRF_BIST_MODE_get_drf_bist_mode_vbidma_2(data) (0x00000001&(data))


#define DISP2TVEVBIDMA_DRF_TEST_RESUME                                0x1801904c
#define DISP2TVEVBIDMA_DRF_TEST_RESUME_reg_addr                       "0xb801904c"
#define DISP2TVEVBIDMA_DRF_TEST_RESUME_reg                            0xb801904c
#define DISP2TVEVBIDMA_DRF_TEST_RESUME_inst_addr                      "0x0013"
#define DISP2TVEVBIDMA_DRF_TEST_RESUME_inst                           0x0013
#define set_DISP2TVEVBIDMA_DRF_TEST_RESUME_reg(data)                  (*((volatile unsigned int*)DISP2TVEVBIDMA_DRF_TEST_RESUME_reg)=data)
#define get_DISP2TVEVBIDMA_DRF_TEST_RESUME_reg                        (*((volatile unsigned int*)DISP2TVEVBIDMA_DRF_TEST_RESUME_reg))
#define DISP2TVEVBIDMA_DRF_TEST_RESUME_drf_test_resume_vbidma_1_shift (1)
#define DISP2TVEVBIDMA_DRF_TEST_RESUME_drf_test_resume_vbidma_2_shift (0)
#define DISP2TVEVBIDMA_DRF_TEST_RESUME_drf_test_resume_vbidma_1_mask  (0x00000002)
#define DISP2TVEVBIDMA_DRF_TEST_RESUME_drf_test_resume_vbidma_2_mask  (0x00000001)
#define DISP2TVEVBIDMA_DRF_TEST_RESUME_drf_test_resume_vbidma_1(data) (0x00000002&((data)<<1))
#define DISP2TVEVBIDMA_DRF_TEST_RESUME_drf_test_resume_vbidma_2(data) (0x00000001&(data))
#define DISP2TVEVBIDMA_DRF_TEST_RESUME_get_drf_test_resume_vbidma_1(data)  ((0x00000002&(data))>>1)
#define DISP2TVEVBIDMA_DRF_TEST_RESUME_get_drf_test_resume_vbidma_2(data)  (0x00000001&(data))


#define DISP2TVEVBIDMA_LS_CNTL                                        0x18019050
#define DISP2TVEVBIDMA_LS_CNTL_reg_addr                               "0xb8019050"
#define DISP2TVEVBIDMA_LS_CNTL_reg                                    0xb8019050
#define DISP2TVEVBIDMA_LS_CNTL_inst_addr                              "0x0014"
#define DISP2TVEVBIDMA_LS_CNTL_inst                                   0x0014
#define set_DISP2TVEVBIDMA_LS_CNTL_reg(data)                          (*((volatile unsigned int*)DISP2TVEVBIDMA_LS_CNTL_reg)=data)
#define get_DISP2TVEVBIDMA_LS_CNTL_reg                                (*((volatile unsigned int*)DISP2TVEVBIDMA_LS_CNTL_reg))
#define DISP2TVEVBIDMA_LS_CNTL_mbist_ls_cntl_1_shift                  (1)
#define DISP2TVEVBIDMA_LS_CNTL_mbist_ls_cntl_2_shift                  (0)
#define DISP2TVEVBIDMA_LS_CNTL_mbist_ls_cntl_1_mask                   (0x00000002)
#define DISP2TVEVBIDMA_LS_CNTL_mbist_ls_cntl_2_mask                   (0x00000001)
#define DISP2TVEVBIDMA_LS_CNTL_mbist_ls_cntl_1(data)                  (0x00000002&((data)<<1))
#define DISP2TVEVBIDMA_LS_CNTL_mbist_ls_cntl_2(data)                  (0x00000001&(data))
#define DISP2TVEVBIDMA_LS_CNTL_get_mbist_ls_cntl_1(data)              ((0x00000002&(data))>>1)
#define DISP2TVEVBIDMA_LS_CNTL_get_mbist_ls_cntl_2(data)              (0x00000001&(data))


#define DISP2TVEVBIDMA_BIST_DONE                                      0x18019054
#define DISP2TVEVBIDMA_BIST_DONE_reg_addr                             "0xb8019054"
#define DISP2TVEVBIDMA_BIST_DONE_reg                                  0xb8019054
#define DISP2TVEVBIDMA_BIST_DONE_inst_addr                            "0x0015"
#define DISP2TVEVBIDMA_BIST_DONE_inst                                 0x0015
#define set_DISP2TVEVBIDMA_BIST_DONE_reg(data)                        (*((volatile unsigned int*)DISP2TVEVBIDMA_BIST_DONE_reg)=data)
#define get_DISP2TVEVBIDMA_BIST_DONE_reg                              (*((volatile unsigned int*)DISP2TVEVBIDMA_BIST_DONE_reg))
#define DISP2TVEVBIDMA_BIST_DONE_bist_done_vbidma_1_shift             (1)
#define DISP2TVEVBIDMA_BIST_DONE_bist_done_vbidma_2_shift             (0)
#define DISP2TVEVBIDMA_BIST_DONE_bist_done_vbidma_1_mask              (0x00000002)
#define DISP2TVEVBIDMA_BIST_DONE_bist_done_vbidma_2_mask              (0x00000001)
#define DISP2TVEVBIDMA_BIST_DONE_bist_done_vbidma_1(data)             (0x00000002&((data)<<1))
#define DISP2TVEVBIDMA_BIST_DONE_bist_done_vbidma_2(data)             (0x00000001&(data))
#define DISP2TVEVBIDMA_BIST_DONE_get_bist_done_vbidma_1(data)         ((0x00000002&(data))>>1)
#define DISP2TVEVBIDMA_BIST_DONE_get_bist_done_vbidma_2(data)         (0x00000001&(data))


#define DISP2TVEVBIDMA_DRF_BIST_DONE                                  0x18019058
#define DISP2TVEVBIDMA_DRF_BIST_DONE_reg_addr                         "0xb8019058"
#define DISP2TVEVBIDMA_DRF_BIST_DONE_reg                              0xb8019058
#define DISP2TVEVBIDMA_DRF_BIST_DONE_inst_addr                        "0x0016"
#define DISP2TVEVBIDMA_DRF_BIST_DONE_inst                             0x0016
#define set_DISP2TVEVBIDMA_DRF_BIST_DONE_reg(data)                    (*((volatile unsigned int*)DISP2TVEVBIDMA_DRF_BIST_DONE_reg)=data)
#define get_DISP2TVEVBIDMA_DRF_BIST_DONE_reg                          (*((volatile unsigned int*)DISP2TVEVBIDMA_DRF_BIST_DONE_reg))
#define DISP2TVEVBIDMA_DRF_BIST_DONE_drf_bist_done_vbidma_1_shift     (1)
#define DISP2TVEVBIDMA_DRF_BIST_DONE_drf_bist_done_vbidma_2_shift     (0)
#define DISP2TVEVBIDMA_DRF_BIST_DONE_drf_bist_done_vbidma_1_mask      (0x00000002)
#define DISP2TVEVBIDMA_DRF_BIST_DONE_drf_bist_done_vbidma_2_mask      (0x00000001)
#define DISP2TVEVBIDMA_DRF_BIST_DONE_drf_bist_done_vbidma_1(data)     (0x00000002&((data)<<1))
#define DISP2TVEVBIDMA_DRF_BIST_DONE_drf_bist_done_vbidma_2(data)     (0x00000001&(data))
#define DISP2TVEVBIDMA_DRF_BIST_DONE_get_drf_bist_done_vbidma_1(data) ((0x00000002&(data))>>1)
#define DISP2TVEVBIDMA_DRF_BIST_DONE_get_drf_bist_done_vbidma_2(data) (0x00000001&(data))


#define DISP2TVEVBIDMA_BIST_FAIL                                      0x1801905c
#define DISP2TVEVBIDMA_BIST_FAIL_reg_addr                             "0xb801905c"
#define DISP2TVEVBIDMA_BIST_FAIL_reg                                  0xb801905c
#define DISP2TVEVBIDMA_BIST_FAIL_inst_addr                            "0x0017"
#define DISP2TVEVBIDMA_BIST_FAIL_inst                                 0x0017
#define set_DISP2TVEVBIDMA_BIST_FAIL_reg(data)                        (*((volatile unsigned int*)DISP2TVEVBIDMA_BIST_FAIL_reg)=data)
#define get_DISP2TVEVBIDMA_BIST_FAIL_reg                              (*((volatile unsigned int*)DISP2TVEVBIDMA_BIST_FAIL_reg))
#define DISP2TVEVBIDMA_BIST_FAIL_bist_fail_vbidma_1_shift             (1)
#define DISP2TVEVBIDMA_BIST_FAIL_bist_fail_vbidma_2_shift             (0)
#define DISP2TVEVBIDMA_BIST_FAIL_bist_fail_vbidma_1_mask              (0x00000002)
#define DISP2TVEVBIDMA_BIST_FAIL_bist_fail_vbidma_2_mask              (0x00000001)
#define DISP2TVEVBIDMA_BIST_FAIL_bist_fail_vbidma_1(data)             (0x00000002&((data)<<1))
#define DISP2TVEVBIDMA_BIST_FAIL_bist_fail_vbidma_2(data)             (0x00000001&(data))
#define DISP2TVEVBIDMA_BIST_FAIL_get_bist_fail_vbidma_1(data)         ((0x00000002&(data))>>1)
#define DISP2TVEVBIDMA_BIST_FAIL_get_bist_fail_vbidma_2(data)         (0x00000001&(data))


#define DISP2TVEVBIDMA_DRF_BIST_FAIL                                  0x18019060
#define DISP2TVEVBIDMA_DRF_BIST_FAIL_reg_addr                         "0xb8019060"
#define DISP2TVEVBIDMA_DRF_BIST_FAIL_reg                              0xb8019060
#define DISP2TVEVBIDMA_DRF_BIST_FAIL_inst_addr                        "0x0018"
#define DISP2TVEVBIDMA_DRF_BIST_FAIL_inst                             0x0018
#define set_DISP2TVEVBIDMA_DRF_BIST_FAIL_reg(data)                    (*((volatile unsigned int*)DISP2TVEVBIDMA_DRF_BIST_FAIL_reg)=data)
#define get_DISP2TVEVBIDMA_DRF_BIST_FAIL_reg                          (*((volatile unsigned int*)DISP2TVEVBIDMA_DRF_BIST_FAIL_reg))
#define DISP2TVEVBIDMA_DRF_BIST_FAIL_drf_bist_fail_vbidma_1_shift     (1)
#define DISP2TVEVBIDMA_DRF_BIST_FAIL_drf_bist_fail_vbidma_2_shift     (0)
#define DISP2TVEVBIDMA_DRF_BIST_FAIL_drf_bist_fail_vbidma_1_mask      (0x00000002)
#define DISP2TVEVBIDMA_DRF_BIST_FAIL_drf_bist_fail_vbidma_2_mask      (0x00000001)
#define DISP2TVEVBIDMA_DRF_BIST_FAIL_drf_bist_fail_vbidma_1(data)     (0x00000002&((data)<<1))
#define DISP2TVEVBIDMA_DRF_BIST_FAIL_drf_bist_fail_vbidma_2(data)     (0x00000001&(data))
#define DISP2TVEVBIDMA_DRF_BIST_FAIL_get_drf_bist_fail_vbidma_1(data) ((0x00000002&(data))>>1)
#define DISP2TVEVBIDMA_DRF_BIST_FAIL_get_drf_bist_fail_vbidma_2(data) (0x00000001&(data))


#define DISP2TVEVBIDMA_DRF_BIST_PAUSE                                 0x18019064
#define DISP2TVEVBIDMA_DRF_BIST_PAUSE_reg_addr                        "0xb8019064"
#define DISP2TVEVBIDMA_DRF_BIST_PAUSE_reg                             0xb8019064
#define DISP2TVEVBIDMA_DRF_BIST_PAUSE_inst_addr                       "0x0019"
#define DISP2TVEVBIDMA_DRF_BIST_PAUSE_inst                            0x0019
#define set_DISP2TVEVBIDMA_DRF_BIST_PAUSE_reg(data)                   (*((volatile unsigned int*)DISP2TVEVBIDMA_DRF_BIST_PAUSE_reg)=data)
#define get_DISP2TVEVBIDMA_DRF_BIST_PAUSE_reg                         (*((volatile unsigned int*)DISP2TVEVBIDMA_DRF_BIST_PAUSE_reg))
#define DISP2TVEVBIDMA_DRF_BIST_PAUSE_drf_start_pause_vbidma_1_shift  (1)
#define DISP2TVEVBIDMA_DRF_BIST_PAUSE_drf_start_pause_vbidma_2_shift  (0)
#define DISP2TVEVBIDMA_DRF_BIST_PAUSE_drf_start_pause_vbidma_1_mask   (0x00000002)
#define DISP2TVEVBIDMA_DRF_BIST_PAUSE_drf_start_pause_vbidma_2_mask   (0x00000001)
#define DISP2TVEVBIDMA_DRF_BIST_PAUSE_drf_start_pause_vbidma_1(data)  (0x00000002&((data)<<1))
#define DISP2TVEVBIDMA_DRF_BIST_PAUSE_drf_start_pause_vbidma_2(data)  (0x00000001&(data))
#define DISP2TVEVBIDMA_DRF_BIST_PAUSE_get_drf_start_pause_vbidma_1(data)  ((0x00000002&(data))>>1)
#define DISP2TVEVBIDMA_DRF_BIST_PAUSE_get_drf_start_pause_vbidma_2(data)  (0x00000001&(data))


#define DISP2TVEVBIDMA_VLINE                                          0x18019070
#define DISP2TVEVBIDMA_VLINE_reg_addr                                 "0xb8019070"
#define DISP2TVEVBIDMA_VLINE_reg                                      0xb8019070
#define DISP2TVEVBIDMA_VLINE_inst_addr                                "0x001C"
#define DISP2TVEVBIDMA_VLINE_inst                                     0x001C
#define set_DISP2TVEVBIDMA_VLINE_reg(data)                            (*((volatile unsigned int*)DISP2TVEVBIDMA_VLINE_reg)=data)
#define get_DISP2TVEVBIDMA_VLINE_reg                                  (*((volatile unsigned int*)DISP2TVEVBIDMA_VLINE_reg))
#define DISP2TVEVBIDMA_VLINE_vline_1_shift                            (16)
#define DISP2TVEVBIDMA_VLINE_vline_2_shift                            (0)
#define DISP2TVEVBIDMA_VLINE_vline_1_mask                             (0x1FFF0000)
#define DISP2TVEVBIDMA_VLINE_vline_2_mask                             (0x00001FFF)
#define DISP2TVEVBIDMA_VLINE_vline_1(data)                            (0x1FFF0000&((data)<<16))
#define DISP2TVEVBIDMA_VLINE_vline_2(data)                            (0x00001FFF&(data))
#define DISP2TVEVBIDMA_VLINE_get_vline_1(data)                        ((0x1FFF0000&(data))>>16)
#define DISP2TVEVBIDMA_VLINE_get_vline_2(data)                        (0x00001FFF&(data))
#endif
