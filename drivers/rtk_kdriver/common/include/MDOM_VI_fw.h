// This file is generated using the spec version 1.39, firmware template version 1.39and SRIF Parser                                                                                source code SVN rev:802                    Version flow no.:1.1.68
#ifndef _MDOM_VI_REG_H_INCLUDED_
#define _MDOM_VI_REG_H_INCLUDED_

//#define  _MDOM_VI_USE_STRUCT
#ifdef _MDOM_VI_USE_STRUCT

typedef struct
{
	unsigned int    reserved_0:24;
	unsigned int    swap_8byte:1;
	unsigned int    swap_4byte:1;
	unsigned int    swap_2byte:1;
	unsigned int    swap_1byte:1;
	unsigned int    reserved_1:3;
	unsigned int    data_format:1;
}V1_output_fmt;

typedef struct
{
	unsigned int    reserved_0:7;
	unsigned int    hsize:13;
	unsigned int    vsize:12;
}CWVH1;

typedef struct
{
	unsigned int    seq_blk_sel:1;
	unsigned int    dummy18027008_30_9:22;
	unsigned int    dmaen1:1;
	unsigned int    reserved_0:5;
	unsigned int    bstlen:3;
}DMACTL;

typedef struct
{
	unsigned int    reserved_0:16;
	unsigned int    y_water_lvl:6;
	unsigned int    reserved_1:10;
}Y1BUF;

typedef struct
{
	unsigned int    reserved_0:6;
	unsigned int    c_water_lvl:6;
	unsigned int    reserved_1:20;
}C1BUF;

typedef struct
{
	unsigned int    reserved_0:1;
	unsigned int    y_ads_set:7;
	unsigned int    reserved_1:1;
	unsigned int    c_ads_set:7;
	unsigned int    dummy18027014_15_0:16;
}DMACTL1;

typedef struct
{
	unsigned int    reserved_0:3;
	unsigned int    y1c1_min_time:4;
	unsigned int    dummy18027018_24_0:25;
}DMA_min_time;

typedef struct
{
	unsigned int    reserved_0:27;
	unsigned int    dmaerrinte:1;
	unsigned int    reserved_1:1;
	unsigned int    video_in_last_wr_y_flag_ie:1;
	unsigned int    video_in_last_wr_c_flag_ie:1;
	unsigned int    vsinte1:1;
}INTEN;

typedef struct
{
	unsigned int    reserved_0:27;
	unsigned int    dmaerrints:1;
	unsigned int    reserved_1:1;
	unsigned int    video_in_last_wr_y_flag:1;
	unsigned int    video_in_last_wr_c_flag:1;
	unsigned int    vsints1:1;
}INTST;

typedef struct
{
	unsigned int    reserved_0:27;
	unsigned int    vsce1:1;
	unsigned int    reserved_1:4;
}GCTL;

typedef struct
{
	unsigned int    reserved_0:8;
	unsigned int    y_buf_start:8;
	unsigned int    reserved_1:8;
	unsigned int    y_buf_end:8;
}Y1OBUFF;

typedef struct
{
	unsigned int    reserved_0:8;
	unsigned int    c_buf_start:8;
	unsigned int    reserved_1:8;
	unsigned int    c_buf_end:8;
}C1OBUFF;

typedef struct
{
	unsigned int    reserved_0:31;
	unsigned int    vi_ls:1;
}VI_light_sleep_mode;

typedef struct
{
	unsigned int    reserved_0:31;
	unsigned int    vi_ds:1;
}VI_deep_sleep_mode;

typedef struct
{
	unsigned int    reserved_0:31;
	unsigned int    vi_sd:1;
}VI_shut_down_mode;

typedef struct
{
	unsigned int    reserved_0:31;
	unsigned int    vi_rme:1;
}VI_read_margin_enable;

typedef struct
{
	unsigned int    reserved_0:28;
	unsigned int    vi_rm:4;
}VI_read_margin;

typedef struct
{
	unsigned int    reserved_0:31;
	unsigned int    vi_bist_mode:1;
}VI_bist_mode;

typedef struct
{
	unsigned int    reserved_0:31;
	unsigned int    vi_bist_done:1;
}VI_bist_done;

typedef struct
{
	unsigned int    reserved_0:31;
	unsigned int    vi_bist_fail:1;
}VI_bist_fail_group;

typedef struct
{
	unsigned int    reserved_0:31;
	unsigned int    vi_drf_mode:1;
}VI_drf_mode;

typedef struct
{
	unsigned int    reserved_0:31;
	unsigned int    vi_drf_resume:1;
}VI_drf_resume;

typedef struct
{
	unsigned int    reserved_0:31;
	unsigned int    vi_drf_done:1;
}VI_drf_done;

typedef struct
{
	unsigned int    reserved_0:31;
	unsigned int    vi_drf_pause:1;
}VI_drf_pause;

typedef struct
{
	unsigned int    reserved_0:31;
	unsigned int    vi_drf_fail:1;
}VI_drf_fail_group;

typedef struct
{
	unsigned int    reserved_0:26;
	unsigned int    dbg_sel:6;
}VI_dbg;
#endif


#define V1_OUTPUT_FMT                                                 0x18027000
#define V1_OUTPUT_FMT_reg_addr                                        "0xb8027000"
#define V1_OUTPUT_FMT_reg                                             0xb8027000
#define V1_OUTPUT_FMT_inst_addr                                       "0x0000"
#define V1_OUTPUT_FMT_inst                                            0x0000
#define V1_OUTPUT_FMT_swap_8byte_shift                                (7)
#define V1_OUTPUT_FMT_swap_4byte_shift                                (6)
#define V1_OUTPUT_FMT_swap_2byte_shift                                (5)
#define V1_OUTPUT_FMT_swap_1byte_shift                                (4)
#define V1_OUTPUT_FMT_data_format_shift                               (0)
#define V1_OUTPUT_FMT_swap_8byte_mask                                 (0x00000080)
#define V1_OUTPUT_FMT_swap_4byte_mask                                 (0x00000040)
#define V1_OUTPUT_FMT_swap_2byte_mask                                 (0x00000020)
#define V1_OUTPUT_FMT_swap_1byte_mask                                 (0x00000010)
#define V1_OUTPUT_FMT_data_format_mask                                (0x00000001)
#define V1_OUTPUT_FMT_swap_8byte(data)                                (0x00000080&((data)<<7))
#define V1_OUTPUT_FMT_swap_4byte(data)                                (0x00000040&((data)<<6))
#define V1_OUTPUT_FMT_swap_2byte(data)                                (0x00000020&((data)<<5))
#define V1_OUTPUT_FMT_swap_1byte(data)                                (0x00000010&((data)<<4))
#define V1_OUTPUT_FMT_data_format(data)                               (0x00000001&(data))
#define V1_OUTPUT_FMT_get_swap_8byte(data)                            ((0x00000080&(data))>>7)
#define V1_OUTPUT_FMT_get_swap_4byte(data)                            ((0x00000040&(data))>>6)
#define V1_OUTPUT_FMT_get_swap_2byte(data)                            ((0x00000020&(data))>>5)
#define V1_OUTPUT_FMT_get_swap_1byte(data)                            ((0x00000010&(data))>>4)
#define V1_OUTPUT_FMT_get_data_format(data)                           (0x00000001&(data))


#define CWVH1                                                         0x18027004
#define CWVH1_reg_addr                                                "0xb8027004"
#define CWVH1_reg                                                     0xb8027004
#define CWVH1_inst_addr                                               "0x0001"
#define CWVH1_inst                                                    0x0001
#define CWVH1_hsize_shift                                             (12)
#define CWVH1_vsize_shift                                             (0)
#define CWVH1_hsize_mask                                              (0x01FFF000)
#define CWVH1_vsize_mask                                              (0x00000FFF)
#define CWVH1_hsize(data)                                             (0x01FFF000&((data)<<12))
#define CWVH1_vsize(data)                                             (0x00000FFF&(data))
#define CWVH1_get_hsize(data)                                         ((0x01FFF000&(data))>>12)
#define CWVH1_get_vsize(data)                                         (0x00000FFF&(data))


#define DMACTL                                                        0x18027008
#define DMACTL_reg_addr                                               "0xb8027008"
#define DMACTL_reg                                                    0xb8027008
#define DMACTL_inst_addr                                              "0x0002"
#define DMACTL_inst                                                   0x0002
#define DMACTL_seq_blk_sel_shift                                      (31)
#define DMACTL_dummy18027008_30_9_shift                               (9)
#define DMACTL_dmaen1_shift                                           (8)
#define DMACTL_bstlen_shift                                           (0)
#define DMACTL_seq_blk_sel_mask                                       (0x80000000)
#define DMACTL_dummy18027008_30_9_mask                                (0x7FFFFE00)
#define DMACTL_dmaen1_mask                                            (0x00000100)
#define DMACTL_bstlen_mask                                            (0x00000007)
#define DMACTL_seq_blk_sel(data)                                      (0x80000000&((data)<<31))
#define DMACTL_dummy18027008_30_9(data)                               (0x7FFFFE00&((data)<<9))
#define DMACTL_dmaen1(data)                                           (0x00000100&((data)<<8))
#define DMACTL_bstlen(data)                                           (0x00000007&(data))
#define DMACTL_get_seq_blk_sel(data)                                  ((0x80000000&(data))>>31)
#define DMACTL_get_dummy18027008_30_9(data)                           ((0x7FFFFE00&(data))>>9)
#define DMACTL_get_dmaen1(data)                                       ((0x00000100&(data))>>8)
#define DMACTL_get_bstlen(data)                                       (0x00000007&(data))


#define Y1BUF                                                         0x1802700c
#define Y1BUF_reg_addr                                                "0xb802700c"
#define Y1BUF_reg                                                     0xb802700c
#define Y1BUF_inst_addr                                               "0x0003"
#define Y1BUF_inst                                                    0x0003
#define Y1BUF_y_water_lvl_shift                                       (10)
#define Y1BUF_y_water_lvl_mask                                        (0x0000FC00)
#define Y1BUF_y_water_lvl(data)                                       (0x0000FC00&((data)<<10))
#define Y1BUF_get_y_water_lvl(data)                                   ((0x0000FC00&(data))>>10)


#define C1BUF                                                         0x18027010
#define C1BUF_reg_addr                                                "0xb8027010"
#define C1BUF_reg                                                     0xb8027010
#define C1BUF_inst_addr                                               "0x0004"
#define C1BUF_inst                                                    0x0004
#define C1BUF_c_water_lvl_shift                                       (20)
#define C1BUF_c_water_lvl_mask                                        (0x03F00000)
#define C1BUF_c_water_lvl(data)                                       (0x03F00000&((data)<<20))
#define C1BUF_get_c_water_lvl(data)                                   ((0x03F00000&(data))>>20)


#define DMACTL1                                                       0x18027014
#define DMACTL1_reg_addr                                              "0xb8027014"
#define DMACTL1_reg                                                   0xb8027014
#define DMACTL1_inst_addr                                             "0x0005"
#define DMACTL1_inst                                                  0x0005
#define DMACTL1_y_ads_set_shift                                       (24)
#define DMACTL1_c_ads_set_shift                                       (16)
#define DMACTL1_dummy18027014_15_0_shift                              (0)
#define DMACTL1_y_ads_set_mask                                        (0x7F000000)
#define DMACTL1_c_ads_set_mask                                        (0x007F0000)
#define DMACTL1_dummy18027014_15_0_mask                               (0x0000FFFF)
#define DMACTL1_y_ads_set(data)                                       (0x7F000000&((data)<<24))
#define DMACTL1_c_ads_set(data)                                       (0x007F0000&((data)<<16))
#define DMACTL1_dummy18027014_15_0(data)                              (0x0000FFFF&(data))
#define DMACTL1_get_y_ads_set(data)                                   ((0x7F000000&(data))>>24)
#define DMACTL1_get_c_ads_set(data)                                   ((0x007F0000&(data))>>16)
#define DMACTL1_get_dummy18027014_15_0(data)                          (0x0000FFFF&(data))


#define DMA_MIN_TIME                                                  0x18027018
#define DMA_MIN_TIME_reg_addr                                         "0xb8027018"
#define DMA_MIN_TIME_reg                                              0xb8027018
#define DMA_MIN_TIME_inst_addr                                        "0x0006"
#define DMA_MIN_TIME_inst                                             0x0006
#define DMA_MIN_TIME_y1c1_min_time_shift                              (25)
#define DMA_MIN_TIME_dummy18027018_24_0_shift                         (0)
#define DMA_MIN_TIME_y1c1_min_time_mask                               (0x1E000000)
#define DMA_MIN_TIME_dummy18027018_24_0_mask                          (0x01FFFFFF)
#define DMA_MIN_TIME_y1c1_min_time(data)                              (0x1E000000&((data)<<25))
#define DMA_MIN_TIME_dummy18027018_24_0(data)                         (0x01FFFFFF&(data))
#define DMA_MIN_TIME_get_y1c1_min_time(data)                          ((0x1E000000&(data))>>25)
#define DMA_MIN_TIME_get_dummy18027018_24_0(data)                     (0x01FFFFFF&(data))


#define INTEN                                                         0x1802701c
#define INTEN_reg_addr                                                "0xb802701c"
#define INTEN_reg                                                     0xb802701c
#define INTEN_inst_addr                                               "0x0007"
#define INTEN_inst                                                    0x0007
#define INTEN_dmaerrinte_shift                                        (4)
#define INTEN_video_in_last_wr_y_flag_ie_shift                        (2)
#define INTEN_video_in_last_wr_c_flag_ie_shift                        (1)
#define INTEN_vsinte1_shift                                           (0)
#define INTEN_dmaerrinte_mask                                         (0x00000010)
#define INTEN_video_in_last_wr_y_flag_ie_mask                         (0x00000004)
#define INTEN_video_in_last_wr_c_flag_ie_mask                         (0x00000002)
#define INTEN_vsinte1_mask                                            (0x00000001)
#define INTEN_dmaerrinte(data)                                        (0x00000010&((data)<<4))
#define INTEN_video_in_last_wr_y_flag_ie(data)                        (0x00000004&((data)<<2))
#define INTEN_video_in_last_wr_c_flag_ie(data)                        (0x00000002&((data)<<1))
#define INTEN_vsinte1(data)                                           (0x00000001&(data))
#define INTEN_get_dmaerrinte(data)                                    ((0x00000010&(data))>>4)
#define INTEN_get_video_in_last_wr_y_flag_ie(data)                    ((0x00000004&(data))>>2)
#define INTEN_get_video_in_last_wr_c_flag_ie(data)                    ((0x00000002&(data))>>1)
#define INTEN_get_vsinte1(data)                                       (0x00000001&(data))


#define INTST                                                         0x18027020
#define INTST_reg_addr                                                "0xb8027020"
#define INTST_reg                                                     0xb8027020
#define INTST_inst_addr                                               "0x0008"
#define INTST_inst                                                    0x0008
#define INTST_dmaerrints_shift                                        (4)
#define INTST_video_in_last_wr_y_flag_shift                           (2)
#define INTST_video_in_last_wr_c_flag_shift                           (1)
#define INTST_vsints1_shift                                           (0)
#define INTST_dmaerrints_mask                                         (0x00000010)
#define INTST_video_in_last_wr_y_flag_mask                            (0x00000004)
#define INTST_video_in_last_wr_c_flag_mask                            (0x00000002)
#define INTST_vsints1_mask                                            (0x00000001)
#define INTST_dmaerrints(data)                                        (0x00000010&((data)<<4))
#define INTST_video_in_last_wr_y_flag(data)                           (0x00000004&((data)<<2))
#define INTST_video_in_last_wr_c_flag(data)                           (0x00000002&((data)<<1))
#define INTST_vsints1(data)                                           (0x00000001&(data))
#define INTST_get_dmaerrints(data)                                    ((0x00000010&(data))>>4)
#define INTST_get_video_in_last_wr_y_flag(data)                       ((0x00000004&(data))>>2)
#define INTST_get_video_in_last_wr_c_flag(data)                       ((0x00000002&(data))>>1)
#define INTST_get_vsints1(data)                                       (0x00000001&(data))


#define GCTL                                                          0x18027024
#define GCTL_reg_addr                                                 "0xb8027024"
#define GCTL_reg                                                      0xb8027024
#define GCTL_inst_addr                                                "0x0009"
#define GCTL_inst                                                     0x0009
#define GCTL_vsce1_shift                                              (4)
#define GCTL_vsce1_mask                                               (0x00000010)
#define GCTL_vsce1(data)                                              (0x00000010&((data)<<4))
#define GCTL_get_vsce1(data)                                          ((0x00000010&(data))>>4)


#define Y1OBUFF                                                       0x18027028
#define Y1OBUFF_reg_addr                                              "0xb8027028"
#define Y1OBUFF_reg                                                   0xb8027028
#define Y1OBUFF_inst_addr                                             "0x000A"
#define Y1OBUFF_inst                                                  0x000A
#define Y1OBUFF_y_buf_start_shift                                     (16)
#define Y1OBUFF_y_buf_end_shift                                       (0)
#define Y1OBUFF_y_buf_start_mask                                      (0x00FF0000)
#define Y1OBUFF_y_buf_end_mask                                        (0x000000FF)
#define Y1OBUFF_y_buf_start(data)                                     (0x00FF0000&((data)<<16))
#define Y1OBUFF_y_buf_end(data)                                       (0x000000FF&(data))
#define Y1OBUFF_get_y_buf_start(data)                                 ((0x00FF0000&(data))>>16)
#define Y1OBUFF_get_y_buf_end(data)                                   (0x000000FF&(data))


#define C1OBUFF                                                       0x1802702c
#define C1OBUFF_reg_addr                                              "0xb802702c"
#define C1OBUFF_reg                                                   0xb802702c
#define C1OBUFF_inst_addr                                             "0x000B"
#define C1OBUFF_inst                                                  0x000B
#define C1OBUFF_c_buf_start_shift                                     (16)
#define C1OBUFF_c_buf_end_shift                                       (0)
#define C1OBUFF_c_buf_start_mask                                      (0x00FF0000)
#define C1OBUFF_c_buf_end_mask                                        (0x000000FF)
#define C1OBUFF_c_buf_start(data)                                     (0x00FF0000&((data)<<16))
#define C1OBUFF_c_buf_end(data)                                       (0x000000FF&(data))
#define C1OBUFF_get_c_buf_start(data)                                 ((0x00FF0000&(data))>>16)
#define C1OBUFF_get_c_buf_end(data)                                   (0x000000FF&(data))


#define VI_LIGHT_SLEEP_MODE                                           0x18027030
#define VI_LIGHT_SLEEP_MODE_reg_addr                                  "0xb8027030"
#define VI_LIGHT_SLEEP_MODE_reg                                       0xb8027030
#define VI_LIGHT_SLEEP_MODE_inst_addr                                 "0x000C"
#define VI_LIGHT_SLEEP_MODE_inst                                      0x000C
#define VI_LIGHT_SLEEP_MODE_vi_ls_shift                               (0)
#define VI_LIGHT_SLEEP_MODE_vi_ls_mask                                (0x00000001)
#define VI_LIGHT_SLEEP_MODE_vi_ls(data)                               (0x00000001&(data))
#define VI_LIGHT_SLEEP_MODE_get_vi_ls(data)                           (0x00000001&(data))


#define VI_DEEP_SLEEP_MODE                                            0x18027034
#define VI_DEEP_SLEEP_MODE_reg_addr                                   "0xb8027034"
#define VI_DEEP_SLEEP_MODE_reg                                        0xb8027034
#define VI_DEEP_SLEEP_MODE_inst_addr                                  "0x000D"
#define VI_DEEP_SLEEP_MODE_inst                                       0x000D
#define VI_DEEP_SLEEP_MODE_vi_ds_shift                                (0)
#define VI_DEEP_SLEEP_MODE_vi_ds_mask                                 (0x00000001)
#define VI_DEEP_SLEEP_MODE_vi_ds(data)                                (0x00000001&(data))
#define VI_DEEP_SLEEP_MODE_get_vi_ds(data)                            (0x00000001&(data))


#define VI_SHUT_DOWN_MODE                                             0x18027038
#define VI_SHUT_DOWN_MODE_reg_addr                                    "0xb8027038"
#define VI_SHUT_DOWN_MODE_reg                                         0xb8027038
#define VI_SHUT_DOWN_MODE_inst_addr                                   "0x000E"
#define VI_SHUT_DOWN_MODE_inst                                        0x000E
#define VI_SHUT_DOWN_MODE_vi_sd_shift                                 (0)
#define VI_SHUT_DOWN_MODE_vi_sd_mask                                  (0x00000001)
#define VI_SHUT_DOWN_MODE_vi_sd(data)                                 (0x00000001&(data))
#define VI_SHUT_DOWN_MODE_get_vi_sd(data)                             (0x00000001&(data))


#define VI_READ_MARGIN_ENABLE                                         0x1802703c
#define VI_READ_MARGIN_ENABLE_reg_addr                                "0xb802703c"
#define VI_READ_MARGIN_ENABLE_reg                                     0xb802703c
#define VI_READ_MARGIN_ENABLE_inst_addr                               "0x000F"
#define VI_READ_MARGIN_ENABLE_inst                                    0x000F
#define VI_READ_MARGIN_ENABLE_vi_rme_shift                            (0)
#define VI_READ_MARGIN_ENABLE_vi_rme_mask                             (0x00000001)
#define VI_READ_MARGIN_ENABLE_vi_rme(data)                            (0x00000001&(data))
#define VI_READ_MARGIN_ENABLE_get_vi_rme(data)                        (0x00000001&(data))


#define VI_READ_MARGIN                                                0x18027040
#define VI_READ_MARGIN_reg_addr                                       "0xb8027040"
#define VI_READ_MARGIN_reg                                            0xb8027040
#define VI_READ_MARGIN_inst_addr                                      "0x0010"
#define VI_READ_MARGIN_inst                                           0x0010
#define VI_READ_MARGIN_vi_rm_shift                                    (0)
#define VI_READ_MARGIN_vi_rm_mask                                     (0x0000000F)
#define VI_READ_MARGIN_vi_rm(data)                                    (0x0000000F&(data))
#define VI_READ_MARGIN_get_vi_rm(data)                                (0x0000000F&(data))


#define VI_BIST_MODE                                                  0x18027044
#define VI_BIST_MODE_reg_addr                                         "0xb8027044"
#define VI_BIST_MODE_reg                                              0xb8027044
#define VI_BIST_MODE_inst_addr                                        "0x0011"
#define VI_BIST_MODE_inst                                             0x0011
#define VI_BIST_MODE_vi_bist_mode_shift                               (0)
#define VI_BIST_MODE_vi_bist_mode_mask                                (0x00000001)
#define VI_BIST_MODE_vi_bist_mode(data)                               (0x00000001&(data))
#define VI_BIST_MODE_get_vi_bist_mode(data)                           (0x00000001&(data))


#define VI_BIST_DONE                                                  0x18027048
#define VI_BIST_DONE_reg_addr                                         "0xb8027048"
#define VI_BIST_DONE_reg                                              0xb8027048
#define VI_BIST_DONE_inst_addr                                        "0x0012"
#define VI_BIST_DONE_inst                                             0x0012
#define VI_BIST_DONE_vi_bist_done_shift                               (0)
#define VI_BIST_DONE_vi_bist_done_mask                                (0x00000001)
#define VI_BIST_DONE_vi_bist_done(data)                               (0x00000001&(data))
#define VI_BIST_DONE_get_vi_bist_done(data)                           (0x00000001&(data))


#define VI_BIST_FAIL_GROUP                                            0x1802704c
#define VI_BIST_FAIL_GROUP_reg_addr                                   "0xb802704c"
#define VI_BIST_FAIL_GROUP_reg                                        0xb802704c
#define VI_BIST_FAIL_GROUP_inst_addr                                  "0x0013"
#define VI_BIST_FAIL_GROUP_inst                                       0x0013
#define VI_BIST_FAIL_GROUP_vi_bist_fail_shift                         (0)
#define VI_BIST_FAIL_GROUP_vi_bist_fail_mask                          (0x00000001)
#define VI_BIST_FAIL_GROUP_vi_bist_fail(data)                         (0x00000001&(data))
#define VI_BIST_FAIL_GROUP_get_vi_bist_fail(data)                     (0x00000001&(data))


#define VI_DRF_MODE                                                   0x18027050
#define VI_DRF_MODE_reg_addr                                          "0xb8027050"
#define VI_DRF_MODE_reg                                               0xb8027050
#define VI_DRF_MODE_inst_addr                                         "0x0014"
#define VI_DRF_MODE_inst                                              0x0014
#define VI_DRF_MODE_vi_drf_mode_shift                                 (0)
#define VI_DRF_MODE_vi_drf_mode_mask                                  (0x00000001)
#define VI_DRF_MODE_vi_drf_mode(data)                                 (0x00000001&(data))
#define VI_DRF_MODE_get_vi_drf_mode(data)                             (0x00000001&(data))


#define VI_DRF_RESUME                                                 0x18027054
#define VI_DRF_RESUME_reg_addr                                        "0xb8027054"
#define VI_DRF_RESUME_reg                                             0xb8027054
#define VI_DRF_RESUME_inst_addr                                       "0x0015"
#define VI_DRF_RESUME_inst                                            0x0015
#define VI_DRF_RESUME_vi_drf_resume_shift                             (0)
#define VI_DRF_RESUME_vi_drf_resume_mask                              (0x00000001)
#define VI_DRF_RESUME_vi_drf_resume(data)                             (0x00000001&(data))
#define VI_DRF_RESUME_get_vi_drf_resume(data)                         (0x00000001&(data))


#define VI_DRF_DONE                                                   0x18027058
#define VI_DRF_DONE_reg_addr                                          "0xb8027058"
#define VI_DRF_DONE_reg                                               0xb8027058
#define VI_DRF_DONE_inst_addr                                         "0x0016"
#define VI_DRF_DONE_inst                                              0x0016
#define VI_DRF_DONE_vi_drf_done_shift                                 (0)
#define VI_DRF_DONE_vi_drf_done_mask                                  (0x00000001)
#define VI_DRF_DONE_vi_drf_done(data)                                 (0x00000001&(data))
#define VI_DRF_DONE_get_vi_drf_done(data)                             (0x00000001&(data))


#define VI_DRF_PAUSE                                                  0x1802705c
#define VI_DRF_PAUSE_reg_addr                                         "0xb802705c"
#define VI_DRF_PAUSE_reg                                              0xb802705c
#define VI_DRF_PAUSE_inst_addr                                        "0x0017"
#define VI_DRF_PAUSE_inst                                             0x0017
#define VI_DRF_PAUSE_vi_drf_pause_shift                               (0)
#define VI_DRF_PAUSE_vi_drf_pause_mask                                (0x00000001)
#define VI_DRF_PAUSE_vi_drf_pause(data)                               (0x00000001&(data))
#define VI_DRF_PAUSE_get_vi_drf_pause(data)                           (0x00000001&(data))


#define VI_DRF_FAIL_GROUP                                             0x18027060
#define VI_DRF_FAIL_GROUP_reg_addr                                    "0xb8027060"
#define VI_DRF_FAIL_GROUP_reg                                         0xb8027060
#define VI_DRF_FAIL_GROUP_inst_addr                                   "0x0018"
#define VI_DRF_FAIL_GROUP_inst                                        0x0018
#define VI_DRF_FAIL_GROUP_vi_drf_fail_shift                           (0)
#define VI_DRF_FAIL_GROUP_vi_drf_fail_mask                            (0x00000001)
#define VI_DRF_FAIL_GROUP_vi_drf_fail(data)                           (0x00000001&(data))
#define VI_DRF_FAIL_GROUP_get_vi_drf_fail(data)                       (0x00000001&(data))


#define VI_DBG                                                        0x18027064
#define VI_DBG_reg_addr                                               "0xb8027064"
#define VI_DBG_reg                                                    0xb8027064
#define VI_DBG_inst_addr                                              "0x0019"
#define VI_DBG_inst                                                   0x0019
#define VI_DBG_dbg_sel_shift                                          (0)
#define VI_DBG_dbg_sel_mask                                           (0x0000003F)
#define VI_DBG_dbg_sel(data)                                          (0x0000003F&(data))
#define VI_DBG_get_dbg_sel(data)                                      (0x0000003F&(data))
#endif

