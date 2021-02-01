// This file is generated using the spec version 1.39, firmware template version 1.39and SRIF Parser                                                                                source code SVN rev:802                    Version flow no.:1.1.68
#ifndef _PEAKING_REG_H_INCLUDED_
#define _PEAKING_REG_H_INCLUDED_

//#define  _PEAKING_USE_STRUCT
#ifdef _PEAKING_USE_STRUCT

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    peaking_enable:1;
    unsigned int    pxlsel:2;
    unsigned int    c0:8;
    unsigned int    c1:8;
    unsigned int    c2:8;
}ICH2_peaking_filter;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    gain_blr:8;
    unsigned int    gain_pos:8;
    unsigned int    gain_neg:8;
}ICH2_peaking_gain;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    hv_pos:8;
    unsigned int    reserved_1:2;
    unsigned int    hv_neg:8;
    unsigned int    reserved_2:2;
    unsigned int    lv:6;
    unsigned int    reserved_3:2;
}ICH2_peaking_bound;

typedef struct
{
    unsigned int    dcti_enable:1;
    unsigned int    reserved_0:29;
    unsigned int    prevent_pe:1;
    unsigned int    enabled:1;
}ICH1_dcti_options;

typedef struct
{
    unsigned int    reserved_0:21;
    unsigned int    th_value:6;
    unsigned int    gain_value:5;
}ICH1_dcti_1st_value;

typedef struct
{
    unsigned int    reserved_0:21;
    unsigned int    th_value:6;
    unsigned int    gain_value:5;
}ICH1_dcti_2nd_value;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    dummy18023124_27_24:4;
    unsigned int    cp_mpgupperbound_x:8;
    unsigned int    reserved_1:16;
}ICH1_mpegnr1;

typedef struct
{
    unsigned int    cp_mpgdcgain:4;
    unsigned int    reserved_0:4;
    unsigned int    cp_mpgdcqp:8;
    unsigned int    reserved_1:6;
    unsigned int    cp_mpgfiltersel1:1;
    unsigned int    cp_mpgfiltersel2:1;
    unsigned int    cp_mpgidxmode_x:1;
    unsigned int    cp_mpgidx_x:3;
    unsigned int    cp_mpegresultweight_x:3;
    unsigned int    cp_mpegenable_x:1;
}ICH1_mpegnr2;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    cp_histhorend:14;
    unsigned int    reserved_1:2;
    unsigned int    cp_histhorstart:14;
}ICH1_hist_blking_hor_range;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    cp_histverend:14;
    unsigned int    reserved_1:2;
    unsigned int    cp_histverstart:14;
}ICH1_hist_blking_ver_range;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    cp_histhoren:1;
}ICH1_mpegstart;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    cp_cnthor1:14;
    unsigned int    reserved_1:2;
    unsigned int    cp_cnthor0:14;
}ICH1_cnthor0;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    cp_cnthor3:14;
    unsigned int    reserved_1:2;
    unsigned int    cp_cnthor2:14;
}ICH1_cnthor2;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    cp_cnthor5:14;
    unsigned int    reserved_1:2;
    unsigned int    cp_cnthor4:14;
}ICH1_cnthor4;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    cp_cnthor7:14;
    unsigned int    reserved_1:2;
    unsigned int    cp_cnthor6:14;
}ICH1_cnthor6;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    dummy18023170_29_26:4;
    unsigned int    new_function_blend:1;
    unsigned int    reserved_1:3;
    unsigned int    undo_pixel:2;
    unsigned int    reserved_2:5;
    unsigned int    ch1_dlti_gain:6;
    unsigned int    ch1_lope_search_range_left:2;
    unsigned int    ch1_lope_search_range_right:2;
    unsigned int    ch1_mean_search_range:2;
    unsigned int    ch1_lope_det_en:1;
    unsigned int    ch1_filter_det_en:1;
    unsigned int    ch1_dlti_en:1;
}I_dlti_ctrl;

typedef struct
{
    unsigned int    reserved_0:6;
    unsigned int    ch1_upper_th:10;
    unsigned int    reserved_1:6;
    unsigned int    ch1_lower_th:10;
}ICH1_dlti_th;

typedef struct
{
    unsigned int    reserved_0:7;
    unsigned int    ch1_filter_c1:9;
    unsigned int    reserved_1:7;
    unsigned int    ch1_filter_c0:9;
}ICH1_dlti_c0;

typedef struct
{
    unsigned int    reserved_0:7;
    unsigned int    ch1_filter_c3:9;
    unsigned int    reserved_1:7;
    unsigned int    ch1_filter_c2:9;
}ICH1_dlti_c2;

typedef struct
{
    unsigned int    reserved_0:23;
    unsigned int    ch1_filter_c4:9;
}ICH1_dlti_c4;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    fsync_general_standard_num:17;
    unsigned int    reserved_1:6;
    unsigned int    fsync_general_en:1;
    unsigned int    fsync_general_line_num:5;
}FSYNC_general_ctrl1;

typedef struct
{
    unsigned int    fsync_debug_en:1;
    unsigned int    reserved_0:18;
    unsigned int    fsync_general_delta_ratio:13;
}FSYNC_general_ctrl2;

typedef struct
{
    unsigned int    measure_result_tmp:17;
    unsigned int    delta_trunc:15;
}FSYNC_general_ctrl3;

typedef struct
{
    unsigned int    measult_result:32;
}FSYNC_general_ctrl4;

typedef struct
{
    unsigned int    reserved_0:30;
    unsigned int    write_en:1;
    unsigned int    read_en:1;
}ICH1_accessdata_ctrl_pk;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    starty:14;
    unsigned int    reserved_1:2;
    unsigned int    startx:14;
}ICH1_accessdata_posctrl_pk;

typedef struct
{
    unsigned int    reserved_0:6;
    unsigned int    y01:10;
    unsigned int    reserved_1:6;
    unsigned int    y00:10;
}ICH1_readdata_data_y1_pk;

typedef struct
{
    unsigned int    reserved_0:6;
    unsigned int    y11:10;
    unsigned int    reserved_1:6;
    unsigned int    y10:10;
}ICH1_readdata_data_y2_pk;

typedef struct
{
    unsigned int    reserved_0:6;
    unsigned int    v00:10;
    unsigned int    reserved_1:6;
    unsigned int    u00:10;
}ICH1_readdata_data_c1_pk;

typedef struct
{
    unsigned int    reserved_0:6;
    unsigned int    v01:10;
    unsigned int    reserved_1:6;
    unsigned int    u01:10;
}ICH1_readdata_data_c2_pk;

typedef struct
{
    unsigned int    reserved_0:6;
    unsigned int    v10:10;
    unsigned int    reserved_1:6;
    unsigned int    u10:10;
}ICH1_readdata_data_c3_pk;

typedef struct
{
    unsigned int    reserved_0:6;
    unsigned int    v11:10;
    unsigned int    reserved_1:6;
    unsigned int    u11:10;
}ICH1_readdata_data_c4_pk;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    v:4;
    unsigned int    u:4;
    unsigned int    y:4;
}ICH1_writedata_data_pk;

typedef struct
{
    unsigned int    reserved_0:30;
    unsigned int    write_en:1;
    unsigned int    read_en:1;
}ICH2_accessdata_ctrl_pk;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    starty:14;
    unsigned int    reserved_1:2;
    unsigned int    startx:14;
}ICH2_accessdata_posctrl_pk;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    y01:8;
    unsigned int    reserved_1:8;
    unsigned int    y00:8;
}ICH2_readdata_data_y1_pk;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    y11:8;
    unsigned int    reserved_1:8;
    unsigned int    y10:8;
}ICH2_readdata_data_y2_pk;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    v00:8;
    unsigned int    reserved_1:8;
    unsigned int    u00:8;
}ICH2_readdata_data_c1_pk;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    v01:8;
    unsigned int    reserved_1:8;
    unsigned int    u01:8;
}ICH2_readdata_data_c2_pk;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    v10:8;
    unsigned int    reserved_1:8;
    unsigned int    u10:8;
}ICH2_readdata_data_c3_pk;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    v11:8;
    unsigned int    reserved_1:8;
    unsigned int    u11:8;
}ICH2_readdata_data_c4_pk;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    v:4;
    unsigned int    u:4;
    unsigned int    y:4;
}ICH2_writedata_data_pk;

typedef struct
{
    unsigned int    data_sel:1;
    unsigned int    reserved_0:2;
    unsigned int    maxlen:3;
    unsigned int    psmth:10;
    unsigned int    lpmode:2;
    unsigned int    engdiv:2;
    unsigned int    offdiv:2;
    unsigned int    uvgain:6;
    unsigned int    dcti_mode:1;
    unsigned int    dummy180231f8_2:1;
    unsigned int    cur_sel:1;
    unsigned int    dcti_en:1;
}I_dcti_ctrl_1;

typedef struct
{
    unsigned int    reserved_0:29;
    unsigned int    general_db_apply:1;
    unsigned int    general_db_rd_sel:1;
    unsigned int    general_db_en:1;
}ICH1_general_db_ctrl;
#endif


#define ICH2_PEAKING_FILTER                                           0x1802310c
#define ICH2_PEAKING_FILTER_reg_addr                                  "0xb802310c"
#define ICH2_PEAKING_FILTER_reg                                       0xb802310c
#define ICH2_PEAKING_FILTER_inst_addr                                 "0x0043"
#define ICH2_PEAKING_FILTER_inst                                      0x0043
#define ICH2_PEAKING_FILTER_peaking_enable_shift                      (26)
#define ICH2_PEAKING_FILTER_pxlsel_shift                              (24)
#define ICH2_PEAKING_FILTER_c0_shift                                  (16)
#define ICH2_PEAKING_FILTER_c1_shift                                  (8)
#define ICH2_PEAKING_FILTER_c2_shift                                  (0)
#define ICH2_PEAKING_FILTER_peaking_enable_mask                       (0x04000000)
#define ICH2_PEAKING_FILTER_pxlsel_mask                               (0x03000000)
#define ICH2_PEAKING_FILTER_c0_mask                                   (0x00FF0000)
#define ICH2_PEAKING_FILTER_c1_mask                                   (0x0000FF00)
#define ICH2_PEAKING_FILTER_c2_mask                                   (0x000000FF)
#define ICH2_PEAKING_FILTER_peaking_enable(data)                      (0x04000000&((data)<<26))
#define ICH2_PEAKING_FILTER_pxlsel(data)                              (0x03000000&((data)<<24))
#define ICH2_PEAKING_FILTER_c0(data)                                  (0x00FF0000&((data)<<16))
#define ICH2_PEAKING_FILTER_c1(data)                                  (0x0000FF00&((data)<<8))
#define ICH2_PEAKING_FILTER_c2(data)                                  (0x000000FF&(data))
#define ICH2_PEAKING_FILTER_get_peaking_enable(data)                  ((0x04000000&(data))>>26)
#define ICH2_PEAKING_FILTER_get_pxlsel(data)                          ((0x03000000&(data))>>24)
#define ICH2_PEAKING_FILTER_get_c0(data)                              ((0x00FF0000&(data))>>16)
#define ICH2_PEAKING_FILTER_get_c1(data)                              ((0x0000FF00&(data))>>8)
#define ICH2_PEAKING_FILTER_get_c2(data)                              (0x000000FF&(data))


#define ICH2_PEAKING_GAIN                                             0x18023110
#define ICH2_PEAKING_GAIN_reg_addr                                    "0xb8023110"
#define ICH2_PEAKING_GAIN_reg                                         0xb8023110
#define ICH2_PEAKING_GAIN_inst_addr                                   "0x0044"
#define ICH2_PEAKING_GAIN_inst                                        0x0044
#define ICH2_PEAKING_GAIN_gain_blr_shift                              (16)
#define ICH2_PEAKING_GAIN_gain_pos_shift                              (8)
#define ICH2_PEAKING_GAIN_gain_neg_shift                              (0)
#define ICH2_PEAKING_GAIN_gain_blr_mask                               (0x00FF0000)
#define ICH2_PEAKING_GAIN_gain_pos_mask                               (0x0000FF00)
#define ICH2_PEAKING_GAIN_gain_neg_mask                               (0x000000FF)
#define ICH2_PEAKING_GAIN_gain_blr(data)                              (0x00FF0000&((data)<<16))
#define ICH2_PEAKING_GAIN_gain_pos(data)                              (0x0000FF00&((data)<<8))
#define ICH2_PEAKING_GAIN_gain_neg(data)                              (0x000000FF&(data))
#define ICH2_PEAKING_GAIN_get_gain_blr(data)                          ((0x00FF0000&(data))>>16)
#define ICH2_PEAKING_GAIN_get_gain_pos(data)                          ((0x0000FF00&(data))>>8)
#define ICH2_PEAKING_GAIN_get_gain_neg(data)                          (0x000000FF&(data))


#define ICH2_PEAKING_BOUND                                            0x18023114
#define ICH2_PEAKING_BOUND_reg_addr                                   "0xb8023114"
#define ICH2_PEAKING_BOUND_reg                                        0xb8023114
#define ICH2_PEAKING_BOUND_inst_addr                                  "0x0045"
#define ICH2_PEAKING_BOUND_inst                                       0x0045
#define ICH2_PEAKING_BOUND_hv_pos_shift                               (20)
#define ICH2_PEAKING_BOUND_hv_neg_shift                               (10)
#define ICH2_PEAKING_BOUND_lv_shift                                   (2)
#define ICH2_PEAKING_BOUND_hv_pos_mask                                (0x0FF00000)
#define ICH2_PEAKING_BOUND_hv_neg_mask                                (0x0003FC00)
#define ICH2_PEAKING_BOUND_lv_mask                                    (0x000000FC)
#define ICH2_PEAKING_BOUND_hv_pos(data)                               (0x0FF00000&((data)<<20))
#define ICH2_PEAKING_BOUND_hv_neg(data)                               (0x0003FC00&((data)<<10))
#define ICH2_PEAKING_BOUND_lv(data)                                   (0x000000FC&((data)<<2))
#define ICH2_PEAKING_BOUND_get_hv_pos(data)                           ((0x0FF00000&(data))>>20)
#define ICH2_PEAKING_BOUND_get_hv_neg(data)                           ((0x0003FC00&(data))>>10)
#define ICH2_PEAKING_BOUND_get_lv(data)                               ((0x000000FC&(data))>>2)


#define ICH1_DCTI_OPTIONS                                             0x18023118
#define ICH1_DCTI_OPTIONS_reg_addr                                    "0xb8023118"
#define ICH1_DCTI_OPTIONS_reg                                         0xb8023118
#define ICH1_DCTI_OPTIONS_inst_addr                                   "0x0046"
#define ICH1_DCTI_OPTIONS_inst                                        0x0046
#define ICH1_DCTI_OPTIONS_dcti_enable_shift                           (31)
#define ICH1_DCTI_OPTIONS_prevent_pe_shift                            (1)
#define ICH1_DCTI_OPTIONS_enabled_shift                               (0)
#define ICH1_DCTI_OPTIONS_dcti_enable_mask                            (0x80000000)
#define ICH1_DCTI_OPTIONS_prevent_pe_mask                             (0x00000002)
#define ICH1_DCTI_OPTIONS_enabled_mask                                (0x00000001)
#define ICH1_DCTI_OPTIONS_dcti_enable(data)                           (0x80000000&((data)<<31))
#define ICH1_DCTI_OPTIONS_prevent_pe(data)                            (0x00000002&((data)<<1))
#define ICH1_DCTI_OPTIONS_enabled(data)                               (0x00000001&(data))
#define ICH1_DCTI_OPTIONS_get_dcti_enable(data)                       ((0x80000000&(data))>>31)
#define ICH1_DCTI_OPTIONS_get_prevent_pe(data)                        ((0x00000002&(data))>>1)
#define ICH1_DCTI_OPTIONS_get_enabled(data)                           (0x00000001&(data))


#define ICH1_DCTI_1ST_VALUE                                           0x1802311c
#define ICH1_DCTI_1ST_VALUE_reg_addr                                  "0xb802311c"
#define ICH1_DCTI_1ST_VALUE_reg                                       0xb802311c
#define ICH1_DCTI_1ST_VALUE_inst_addr                                 "0x0047"
#define ICH1_DCTI_1ST_VALUE_inst                                      0x0047
#define ICH1_DCTI_1ST_VALUE_th_value_shift                            (5)
#define ICH1_DCTI_1ST_VALUE_gain_value_shift                          (0)
#define ICH1_DCTI_1ST_VALUE_th_value_mask                             (0x000007E0)
#define ICH1_DCTI_1ST_VALUE_gain_value_mask                           (0x0000001F)
#define ICH1_DCTI_1ST_VALUE_th_value(data)                            (0x000007E0&((data)<<5))
#define ICH1_DCTI_1ST_VALUE_gain_value(data)                          (0x0000001F&(data))
#define ICH1_DCTI_1ST_VALUE_get_th_value(data)                        ((0x000007E0&(data))>>5)
#define ICH1_DCTI_1ST_VALUE_get_gain_value(data)                      (0x0000001F&(data))


#define ICH1_DCTI_2ND_VALUE                                           0x18023120
#define ICH1_DCTI_2ND_VALUE_reg_addr                                  "0xb8023120"
#define ICH1_DCTI_2ND_VALUE_reg                                       0xb8023120
#define ICH1_DCTI_2ND_VALUE_inst_addr                                 "0x0048"
#define ICH1_DCTI_2ND_VALUE_inst                                      0x0048
#define ICH1_DCTI_2ND_VALUE_th_value_shift                            (5)
#define ICH1_DCTI_2ND_VALUE_gain_value_shift                          (0)
#define ICH1_DCTI_2ND_VALUE_th_value_mask                             (0x000007E0)
#define ICH1_DCTI_2ND_VALUE_gain_value_mask                           (0x0000001F)
#define ICH1_DCTI_2ND_VALUE_th_value(data)                            (0x000007E0&((data)<<5))
#define ICH1_DCTI_2ND_VALUE_gain_value(data)                          (0x0000001F&(data))
#define ICH1_DCTI_2ND_VALUE_get_th_value(data)                        ((0x000007E0&(data))>>5)
#define ICH1_DCTI_2ND_VALUE_get_gain_value(data)                      (0x0000001F&(data))


#define ICH1_MPEGNR1                                                  0x18023124
#define ICH1_MPEGNR1_reg_addr                                         "0xb8023124"
#define ICH1_MPEGNR1_reg                                              0xb8023124
#define ICH1_MPEGNR1_inst_addr                                        "0x0049"
#define ICH1_MPEGNR1_inst                                             0x0049
#define ICH1_MPEGNR1_dummy18023124_27_24_shift                        (24)
#define ICH1_MPEGNR1_cp_mpgupperbound_x_shift                         (16)
#define ICH1_MPEGNR1_dummy18023124_27_24_mask                         (0x0F000000)
#define ICH1_MPEGNR1_cp_mpgupperbound_x_mask                          (0x00FF0000)
#define ICH1_MPEGNR1_dummy18023124_27_24(data)                        (0x0F000000&((data)<<24))
#define ICH1_MPEGNR1_cp_mpgupperbound_x(data)                         (0x00FF0000&((data)<<16))
#define ICH1_MPEGNR1_get_dummy18023124_27_24(data)                    ((0x0F000000&(data))>>24)
#define ICH1_MPEGNR1_get_cp_mpgupperbound_x(data)                     ((0x00FF0000&(data))>>16)


#define ICH1_MPEGNR2                                                  0x18023128
#define ICH1_MPEGNR2_reg_addr                                         "0xb8023128"
#define ICH1_MPEGNR2_reg                                              0xb8023128
#define ICH1_MPEGNR2_inst_addr                                        "0x004A"
#define ICH1_MPEGNR2_inst                                             0x004A
#define ICH1_MPEGNR2_cp_mpgdcgain_shift                               (28)
#define ICH1_MPEGNR2_cp_mpgdcqp_shift                                 (16)
#define ICH1_MPEGNR2_cp_mpgfiltersel1_shift                           (9)
#define ICH1_MPEGNR2_cp_mpgfiltersel2_shift                           (8)
#define ICH1_MPEGNR2_cp_mpgidxmode_x_shift                            (7)
#define ICH1_MPEGNR2_cp_mpgidx_x_shift                                (4)
#define ICH1_MPEGNR2_cp_mpegresultweight_x_shift                      (1)
#define ICH1_MPEGNR2_cp_mpegenable_x_shift                            (0)
#define ICH1_MPEGNR2_cp_mpgdcgain_mask                                (0xF0000000)
#define ICH1_MPEGNR2_cp_mpgdcqp_mask                                  (0x00FF0000)
#define ICH1_MPEGNR2_cp_mpgfiltersel1_mask                            (0x00000200)
#define ICH1_MPEGNR2_cp_mpgfiltersel2_mask                            (0x00000100)
#define ICH1_MPEGNR2_cp_mpgidxmode_x_mask                             (0x00000080)
#define ICH1_MPEGNR2_cp_mpgidx_x_mask                                 (0x00000070)
#define ICH1_MPEGNR2_cp_mpegresultweight_x_mask                       (0x0000000E)
#define ICH1_MPEGNR2_cp_mpegenable_x_mask                             (0x00000001)
#define ICH1_MPEGNR2_cp_mpgdcgain(data)                               (0xF0000000&((data)<<28))
#define ICH1_MPEGNR2_cp_mpgdcqp(data)                                 (0x00FF0000&((data)<<16))
#define ICH1_MPEGNR2_cp_mpgfiltersel1(data)                           (0x00000200&((data)<<9))
#define ICH1_MPEGNR2_cp_mpgfiltersel2(data)                           (0x00000100&((data)<<8))
#define ICH1_MPEGNR2_cp_mpgidxmode_x(data)                            (0x00000080&((data)<<7))
#define ICH1_MPEGNR2_cp_mpgidx_x(data)                                (0x00000070&((data)<<4))
#define ICH1_MPEGNR2_cp_mpegresultweight_x(data)                      (0x0000000E&((data)<<1))
#define ICH1_MPEGNR2_cp_mpegenable_x(data)                            (0x00000001&(data))
#define ICH1_MPEGNR2_get_cp_mpgdcgain(data)                           ((0xF0000000&(data))>>28)
#define ICH1_MPEGNR2_get_cp_mpgdcqp(data)                             ((0x00FF0000&(data))>>16)
#define ICH1_MPEGNR2_get_cp_mpgfiltersel1(data)                       ((0x00000200&(data))>>9)
#define ICH1_MPEGNR2_get_cp_mpgfiltersel2(data)                       ((0x00000100&(data))>>8)
#define ICH1_MPEGNR2_get_cp_mpgidxmode_x(data)                        ((0x00000080&(data))>>7)
#define ICH1_MPEGNR2_get_cp_mpgidx_x(data)                            ((0x00000070&(data))>>4)
#define ICH1_MPEGNR2_get_cp_mpegresultweight_x(data)                  ((0x0000000E&(data))>>1)
#define ICH1_MPEGNR2_get_cp_mpegenable_x(data)                        (0x00000001&(data))


#define ICH1_HIST_BLKING_HOR_RANGE                                    0x1802312c
#define ICH1_HIST_BLKING_HOR_RANGE_reg_addr                           "0xb802312c"
#define ICH1_HIST_BLKING_HOR_RANGE_reg                                0xb802312c
#define ICH1_HIST_BLKING_HOR_RANGE_inst_addr                          "0x004B"
#define ICH1_HIST_BLKING_HOR_RANGE_inst                               0x004B
#define ICH1_HIST_BLKING_HOR_RANGE_cp_histhorend_shift                (16)
#define ICH1_HIST_BLKING_HOR_RANGE_cp_histhorstart_shift              (0)
#define ICH1_HIST_BLKING_HOR_RANGE_cp_histhorend_mask                 (0x3FFF0000)
#define ICH1_HIST_BLKING_HOR_RANGE_cp_histhorstart_mask               (0x00003FFF)
#define ICH1_HIST_BLKING_HOR_RANGE_cp_histhorend(data)                (0x3FFF0000&((data)<<16))
#define ICH1_HIST_BLKING_HOR_RANGE_cp_histhorstart(data)              (0x00003FFF&(data))
#define ICH1_HIST_BLKING_HOR_RANGE_get_cp_histhorend(data)            ((0x3FFF0000&(data))>>16)
#define ICH1_HIST_BLKING_HOR_RANGE_get_cp_histhorstart(data)          (0x00003FFF&(data))


#define ICH1_HIST_BLKING_VER_RANGE                                    0x18023130
#define ICH1_HIST_BLKING_VER_RANGE_reg_addr                           "0xb8023130"
#define ICH1_HIST_BLKING_VER_RANGE_reg                                0xb8023130
#define ICH1_HIST_BLKING_VER_RANGE_inst_addr                          "0x004C"
#define ICH1_HIST_BLKING_VER_RANGE_inst                               0x004C
#define ICH1_HIST_BLKING_VER_RANGE_cp_histverend_shift                (16)
#define ICH1_HIST_BLKING_VER_RANGE_cp_histverstart_shift              (0)
#define ICH1_HIST_BLKING_VER_RANGE_cp_histverend_mask                 (0x3FFF0000)
#define ICH1_HIST_BLKING_VER_RANGE_cp_histverstart_mask               (0x00003FFF)
#define ICH1_HIST_BLKING_VER_RANGE_cp_histverend(data)                (0x3FFF0000&((data)<<16))
#define ICH1_HIST_BLKING_VER_RANGE_cp_histverstart(data)              (0x00003FFF&(data))
#define ICH1_HIST_BLKING_VER_RANGE_get_cp_histverend(data)            ((0x3FFF0000&(data))>>16)
#define ICH1_HIST_BLKING_VER_RANGE_get_cp_histverstart(data)          (0x00003FFF&(data))


#define ICH1_MPEGSTART                                                0x18023134
#define ICH1_MPEGSTART_reg_addr                                       "0xb8023134"
#define ICH1_MPEGSTART_reg                                            0xb8023134
#define ICH1_MPEGSTART_inst_addr                                      "0x004D"
#define ICH1_MPEGSTART_inst                                           0x004D
#define ICH1_MPEGSTART_cp_histhoren_shift                             (0)
#define ICH1_MPEGSTART_cp_histhoren_mask                              (0x00000001)
#define ICH1_MPEGSTART_cp_histhoren(data)                             (0x00000001&(data))
#define ICH1_MPEGSTART_get_cp_histhoren(data)                         (0x00000001&(data))


#define ICH1_CNTHOR0                                                  0x18023138
#define ICH1_CNTHOR0_reg_addr                                         "0xb8023138"
#define ICH1_CNTHOR0_reg                                              0xb8023138
#define ICH1_CNTHOR0_inst_addr                                        "0x004E"
#define ICH1_CNTHOR0_inst                                             0x004E
#define ICH1_CNTHOR0_cp_cnthor1_shift                                 (16)
#define ICH1_CNTHOR0_cp_cnthor0_shift                                 (0)
#define ICH1_CNTHOR0_cp_cnthor1_mask                                  (0x3FFF0000)
#define ICH1_CNTHOR0_cp_cnthor0_mask                                  (0x00003FFF)
#define ICH1_CNTHOR0_cp_cnthor1(data)                                 (0x3FFF0000&((data)<<16))
#define ICH1_CNTHOR0_cp_cnthor0(data)                                 (0x00003FFF&(data))
#define ICH1_CNTHOR0_get_cp_cnthor1(data)                             ((0x3FFF0000&(data))>>16)
#define ICH1_CNTHOR0_get_cp_cnthor0(data)                             (0x00003FFF&(data))


#define ICH1_CNTHOR2                                                  0x1802313c
#define ICH1_CNTHOR2_reg_addr                                         "0xb802313c"
#define ICH1_CNTHOR2_reg                                              0xb802313c
#define ICH1_CNTHOR2_inst_addr                                        "0x004F"
#define ICH1_CNTHOR2_inst                                             0x004F
#define ICH1_CNTHOR2_cp_cnthor3_shift                                 (16)
#define ICH1_CNTHOR2_cp_cnthor2_shift                                 (0)
#define ICH1_CNTHOR2_cp_cnthor3_mask                                  (0x3FFF0000)
#define ICH1_CNTHOR2_cp_cnthor2_mask                                  (0x00003FFF)
#define ICH1_CNTHOR2_cp_cnthor3(data)                                 (0x3FFF0000&((data)<<16))
#define ICH1_CNTHOR2_cp_cnthor2(data)                                 (0x00003FFF&(data))
#define ICH1_CNTHOR2_get_cp_cnthor3(data)                             ((0x3FFF0000&(data))>>16)
#define ICH1_CNTHOR2_get_cp_cnthor2(data)                             (0x00003FFF&(data))


#define ICH1_CNTHOR4                                                  0x18023140
#define ICH1_CNTHOR4_reg_addr                                         "0xb8023140"
#define ICH1_CNTHOR4_reg                                              0xb8023140
#define ICH1_CNTHOR4_inst_addr                                        "0x0050"
#define ICH1_CNTHOR4_inst                                             0x0050
#define ICH1_CNTHOR4_cp_cnthor5_shift                                 (16)
#define ICH1_CNTHOR4_cp_cnthor4_shift                                 (0)
#define ICH1_CNTHOR4_cp_cnthor5_mask                                  (0x3FFF0000)
#define ICH1_CNTHOR4_cp_cnthor4_mask                                  (0x00003FFF)
#define ICH1_CNTHOR4_cp_cnthor5(data)                                 (0x3FFF0000&((data)<<16))
#define ICH1_CNTHOR4_cp_cnthor4(data)                                 (0x00003FFF&(data))
#define ICH1_CNTHOR4_get_cp_cnthor5(data)                             ((0x3FFF0000&(data))>>16)
#define ICH1_CNTHOR4_get_cp_cnthor4(data)                             (0x00003FFF&(data))


#define ICH1_CNTHOR6                                                  0x18023144
#define ICH1_CNTHOR6_reg_addr                                         "0xb8023144"
#define ICH1_CNTHOR6_reg                                              0xb8023144
#define ICH1_CNTHOR6_inst_addr                                        "0x0051"
#define ICH1_CNTHOR6_inst                                             0x0051
#define ICH1_CNTHOR6_cp_cnthor7_shift                                 (16)
#define ICH1_CNTHOR6_cp_cnthor6_shift                                 (0)
#define ICH1_CNTHOR6_cp_cnthor7_mask                                  (0x3FFF0000)
#define ICH1_CNTHOR6_cp_cnthor6_mask                                  (0x00003FFF)
#define ICH1_CNTHOR6_cp_cnthor7(data)                                 (0x3FFF0000&((data)<<16))
#define ICH1_CNTHOR6_cp_cnthor6(data)                                 (0x00003FFF&(data))
#define ICH1_CNTHOR6_get_cp_cnthor7(data)                             ((0x3FFF0000&(data))>>16)
#define ICH1_CNTHOR6_get_cp_cnthor6(data)                             (0x00003FFF&(data))


#define I_DLTI_CTRL                                                   0x18023170
#define I_DLTI_CTRL_reg_addr                                          "0xb8023170"
#define I_DLTI_CTRL_reg                                               0xb8023170
#define I_DLTI_CTRL_inst_addr                                         "0x005C"
#define I_DLTI_CTRL_inst                                              0x005C
#define I_DLTI_CTRL_dummy18023170_29_26_shift                         (26)
#define I_DLTI_CTRL_new_function_blend_shift                          (25)
#define I_DLTI_CTRL_undo_pixel_shift                                  (20)
#define I_DLTI_CTRL_ch1_dlti_gain_shift                               (9)
#define I_DLTI_CTRL_ch1_lope_search_range_left_shift                  (7)
#define I_DLTI_CTRL_ch1_lope_search_range_right_shift                 (5)
#define I_DLTI_CTRL_ch1_mean_search_range_shift                       (3)
#define I_DLTI_CTRL_ch1_lope_det_en_shift                             (2)
#define I_DLTI_CTRL_ch1_filter_det_en_shift                           (1)
#define I_DLTI_CTRL_ch1_dlti_en_shift                                 (0)
#define I_DLTI_CTRL_dummy18023170_29_26_mask                          (0x3C000000)
#define I_DLTI_CTRL_new_function_blend_mask                           (0x02000000)
#define I_DLTI_CTRL_undo_pixel_mask                                   (0x00300000)
#define I_DLTI_CTRL_ch1_dlti_gain_mask                                (0x00007E00)
#define I_DLTI_CTRL_ch1_lope_search_range_left_mask                   (0x00000180)
#define I_DLTI_CTRL_ch1_lope_search_range_right_mask                  (0x00000060)
#define I_DLTI_CTRL_ch1_mean_search_range_mask                        (0x00000018)
#define I_DLTI_CTRL_ch1_lope_det_en_mask                              (0x00000004)
#define I_DLTI_CTRL_ch1_filter_det_en_mask                            (0x00000002)
#define I_DLTI_CTRL_ch1_dlti_en_mask                                  (0x00000001)
#define I_DLTI_CTRL_dummy18023170_29_26(data)                         (0x3C000000&((data)<<26))
#define I_DLTI_CTRL_new_function_blend(data)                          (0x02000000&((data)<<25))
#define I_DLTI_CTRL_undo_pixel(data)                                  (0x00300000&((data)<<20))
#define I_DLTI_CTRL_ch1_dlti_gain(data)                               (0x00007E00&((data)<<9))
#define I_DLTI_CTRL_ch1_lope_search_range_left(data)                  (0x00000180&((data)<<7))
#define I_DLTI_CTRL_ch1_lope_search_range_right(data)                 (0x00000060&((data)<<5))
#define I_DLTI_CTRL_ch1_mean_search_range(data)                       (0x00000018&((data)<<3))
#define I_DLTI_CTRL_ch1_lope_det_en(data)                             (0x00000004&((data)<<2))
#define I_DLTI_CTRL_ch1_filter_det_en(data)                           (0x00000002&((data)<<1))
#define I_DLTI_CTRL_ch1_dlti_en(data)                                 (0x00000001&(data))
#define I_DLTI_CTRL_get_dummy18023170_29_26(data)                     ((0x3C000000&(data))>>26)
#define I_DLTI_CTRL_get_new_function_blend(data)                      ((0x02000000&(data))>>25)
#define I_DLTI_CTRL_get_undo_pixel(data)                              ((0x00300000&(data))>>20)
#define I_DLTI_CTRL_get_ch1_dlti_gain(data)                           ((0x00007E00&(data))>>9)
#define I_DLTI_CTRL_get_ch1_lope_search_range_left(data)              ((0x00000180&(data))>>7)
#define I_DLTI_CTRL_get_ch1_lope_search_range_right(data)             ((0x00000060&(data))>>5)
#define I_DLTI_CTRL_get_ch1_mean_search_range(data)                   ((0x00000018&(data))>>3)
#define I_DLTI_CTRL_get_ch1_lope_det_en(data)                         ((0x00000004&(data))>>2)
#define I_DLTI_CTRL_get_ch1_filter_det_en(data)                       ((0x00000002&(data))>>1)
#define I_DLTI_CTRL_get_ch1_dlti_en(data)                             (0x00000001&(data))


#define ICH1_DLTI_TH                                                  0x18023174
#define ICH1_DLTI_TH_reg_addr                                         "0xb8023174"
#define ICH1_DLTI_TH_reg                                              0xb8023174
#define ICH1_DLTI_TH_inst_addr                                        "0x005D"
#define ICH1_DLTI_TH_inst                                             0x005D
#define ICH1_DLTI_TH_ch1_upper_th_shift                               (16)
#define ICH1_DLTI_TH_ch1_lower_th_shift                               (0)
#define ICH1_DLTI_TH_ch1_upper_th_mask                                (0x03FF0000)
#define ICH1_DLTI_TH_ch1_lower_th_mask                                (0x000003FF)
#define ICH1_DLTI_TH_ch1_upper_th(data)                               (0x03FF0000&((data)<<16))
#define ICH1_DLTI_TH_ch1_lower_th(data)                               (0x000003FF&(data))
#define ICH1_DLTI_TH_get_ch1_upper_th(data)                           ((0x03FF0000&(data))>>16)
#define ICH1_DLTI_TH_get_ch1_lower_th(data)                           (0x000003FF&(data))


#define ICH1_DLTI_C0                                                  0x18023178
#define ICH1_DLTI_C0_reg_addr                                         "0xb8023178"
#define ICH1_DLTI_C0_reg                                              0xb8023178
#define ICH1_DLTI_C0_inst_addr                                        "0x005E"
#define ICH1_DLTI_C0_inst                                             0x005E
#define ICH1_DLTI_C0_ch1_filter_c1_shift                              (16)
#define ICH1_DLTI_C0_ch1_filter_c0_shift                              (0)
#define ICH1_DLTI_C0_ch1_filter_c1_mask                               (0x01FF0000)
#define ICH1_DLTI_C0_ch1_filter_c0_mask                               (0x000001FF)
#define ICH1_DLTI_C0_ch1_filter_c1(data)                              (0x01FF0000&((data)<<16))
#define ICH1_DLTI_C0_ch1_filter_c0(data)                              (0x000001FF&(data))
#define ICH1_DLTI_C0_get_ch1_filter_c1(data)                          ((0x01FF0000&(data))>>16)
#define ICH1_DLTI_C0_get_ch1_filter_c0(data)                          (0x000001FF&(data))


#define ICH1_DLTI_C2                                                  0x1802317c
#define ICH1_DLTI_C2_reg_addr                                         "0xb802317c"
#define ICH1_DLTI_C2_reg                                              0xb802317c
#define ICH1_DLTI_C2_inst_addr                                        "0x005F"
#define ICH1_DLTI_C2_inst                                             0x005F
#define ICH1_DLTI_C2_ch1_filter_c3_shift                              (16)
#define ICH1_DLTI_C2_ch1_filter_c2_shift                              (0)
#define ICH1_DLTI_C2_ch1_filter_c3_mask                               (0x01FF0000)
#define ICH1_DLTI_C2_ch1_filter_c2_mask                               (0x000001FF)
#define ICH1_DLTI_C2_ch1_filter_c3(data)                              (0x01FF0000&((data)<<16))
#define ICH1_DLTI_C2_ch1_filter_c2(data)                              (0x000001FF&(data))
#define ICH1_DLTI_C2_get_ch1_filter_c3(data)                          ((0x01FF0000&(data))>>16)
#define ICH1_DLTI_C2_get_ch1_filter_c2(data)                          (0x000001FF&(data))


#define ICH1_DLTI_C4                                                  0x18023180
#define ICH1_DLTI_C4_reg_addr                                         "0xb8023180"
#define ICH1_DLTI_C4_reg                                              0xb8023180
#define ICH1_DLTI_C4_inst_addr                                        "0x0060"
#define ICH1_DLTI_C4_inst                                             0x0060
#define ICH1_DLTI_C4_ch1_filter_c4_shift                              (0)
#define ICH1_DLTI_C4_ch1_filter_c4_mask                               (0x000001FF)
#define ICH1_DLTI_C4_ch1_filter_c4(data)                              (0x000001FF&(data))
#define ICH1_DLTI_C4_get_ch1_filter_c4(data)                          (0x000001FF&(data))


#define FSYNC_GENERAL_CTRL1                                           0x180231a0
#define FSYNC_GENERAL_CTRL1_reg_addr                                  "0xb80231a0"
#define FSYNC_GENERAL_CTRL1_reg                                       0xb80231a0
#define FSYNC_GENERAL_CTRL1_inst_addr                                 "0x0068"
#define FSYNC_GENERAL_CTRL1_inst                                      0x0068
#define FSYNC_GENERAL_CTRL1_fsync_general_standard_num_shift          (12)
#define FSYNC_GENERAL_CTRL1_fsync_general_en_shift                    (5)
#define FSYNC_GENERAL_CTRL1_fsync_general_line_num_shift              (0)
#define FSYNC_GENERAL_CTRL1_fsync_general_standard_num_mask           (0x1FFFF000)
#define FSYNC_GENERAL_CTRL1_fsync_general_en_mask                     (0x00000020)
#define FSYNC_GENERAL_CTRL1_fsync_general_line_num_mask               (0x0000001F)
#define FSYNC_GENERAL_CTRL1_fsync_general_standard_num(data)          (0x1FFFF000&((data)<<12))
#define FSYNC_GENERAL_CTRL1_fsync_general_en(data)                    (0x00000020&((data)<<5))
#define FSYNC_GENERAL_CTRL1_fsync_general_line_num(data)              (0x0000001F&(data))
#define FSYNC_GENERAL_CTRL1_get_fsync_general_standard_num(data)      ((0x1FFFF000&(data))>>12)
#define FSYNC_GENERAL_CTRL1_get_fsync_general_en(data)                ((0x00000020&(data))>>5)
#define FSYNC_GENERAL_CTRL1_get_fsync_general_line_num(data)          (0x0000001F&(data))


#define FSYNC_GENERAL_CTRL2                                           0x180231a4
#define FSYNC_GENERAL_CTRL2_reg_addr                                  "0xb80231a4"
#define FSYNC_GENERAL_CTRL2_reg                                       0xb80231a4
#define FSYNC_GENERAL_CTRL2_inst_addr                                 "0x0069"
#define FSYNC_GENERAL_CTRL2_inst                                      0x0069
#define FSYNC_GENERAL_CTRL2_fsync_debug_en_shift                      (31)
#define FSYNC_GENERAL_CTRL2_fsync_general_delta_ratio_shift           (0)
#define FSYNC_GENERAL_CTRL2_fsync_debug_en_mask                       (0x80000000)
#define FSYNC_GENERAL_CTRL2_fsync_general_delta_ratio_mask            (0x00001FFF)
#define FSYNC_GENERAL_CTRL2_fsync_debug_en(data)                      (0x80000000&((data)<<31))
#define FSYNC_GENERAL_CTRL2_fsync_general_delta_ratio(data)           (0x00001FFF&(data))
#define FSYNC_GENERAL_CTRL2_get_fsync_debug_en(data)                  ((0x80000000&(data))>>31)
#define FSYNC_GENERAL_CTRL2_get_fsync_general_delta_ratio(data)       (0x00001FFF&(data))


#define FSYNC_GENERAL_CTRL3                                           0x180231a8
#define FSYNC_GENERAL_CTRL3_reg_addr                                  "0xb80231a8"
#define FSYNC_GENERAL_CTRL3_reg                                       0xb80231a8
#define FSYNC_GENERAL_CTRL3_inst_addr                                 "0x006A"
#define FSYNC_GENERAL_CTRL3_inst                                      0x006A
#define FSYNC_GENERAL_CTRL3_measure_result_tmp_shift                  (15)
#define FSYNC_GENERAL_CTRL3_delta_trunc_shift                         (0)
#define FSYNC_GENERAL_CTRL3_measure_result_tmp_mask                   (0xFFFF8000)
#define FSYNC_GENERAL_CTRL3_delta_trunc_mask                          (0x00007FFF)
#define FSYNC_GENERAL_CTRL3_measure_result_tmp(data)                  (0xFFFF8000&((data)<<15))
#define FSYNC_GENERAL_CTRL3_delta_trunc(data)                         (0x00007FFF&(data))
#define FSYNC_GENERAL_CTRL3_get_measure_result_tmp(data)              ((0xFFFF8000&(data))>>15)
#define FSYNC_GENERAL_CTRL3_get_delta_trunc(data)                     (0x00007FFF&(data))


#define FSYNC_GENERAL_CTRL4                                           0x180231ac
#define FSYNC_GENERAL_CTRL4_reg_addr                                  "0xb80231ac"
#define FSYNC_GENERAL_CTRL4_reg                                       0xb80231ac
#define FSYNC_GENERAL_CTRL4_inst_addr                                 "0x006B"
#define FSYNC_GENERAL_CTRL4_inst                                      0x006B
#define FSYNC_GENERAL_CTRL4_measult_result_shift                      (0)
#define FSYNC_GENERAL_CTRL4_measult_result_mask                       (0xFFFFFFFF)
#define FSYNC_GENERAL_CTRL4_measult_result(data)                      (0xFFFFFFFF&(data))
#define FSYNC_GENERAL_CTRL4_get_measult_result(data)                  (0xFFFFFFFF&(data))


#define ICH1_ACCESSDATA_CTRL_PK                                       0x180231b0
#define ICH1_ACCESSDATA_CTRL_PK_reg_addr                              "0xb80231b0"
#define ICH1_ACCESSDATA_CTRL_PK_reg                                   0xb80231b0
#define ICH1_ACCESSDATA_CTRL_PK_inst_addr                             "0x006C"
#define ICH1_ACCESSDATA_CTRL_PK_inst                                  0x006C
#define ICH1_ACCESSDATA_CTRL_PK_write_en_shift                        (1)
#define ICH1_ACCESSDATA_CTRL_PK_read_en_shift                         (0)
#define ICH1_ACCESSDATA_CTRL_PK_write_en_mask                         (0x00000002)
#define ICH1_ACCESSDATA_CTRL_PK_read_en_mask                          (0x00000001)
#define ICH1_ACCESSDATA_CTRL_PK_write_en(data)                        (0x00000002&((data)<<1))
#define ICH1_ACCESSDATA_CTRL_PK_read_en(data)                         (0x00000001&(data))
#define ICH1_ACCESSDATA_CTRL_PK_get_write_en(data)                    ((0x00000002&(data))>>1)
#define ICH1_ACCESSDATA_CTRL_PK_get_read_en(data)                     (0x00000001&(data))


#define ICH1_ACCESSDATA_POSCTRL_PK                                    0x180231b4
#define ICH1_ACCESSDATA_POSCTRL_PK_reg_addr                           "0xb80231b4"
#define ICH1_ACCESSDATA_POSCTRL_PK_reg                                0xb80231b4
#define ICH1_ACCESSDATA_POSCTRL_PK_inst_addr                          "0x006D"
#define ICH1_ACCESSDATA_POSCTRL_PK_inst                               0x006D
#define ICH1_ACCESSDATA_POSCTRL_PK_starty_shift                       (16)
#define ICH1_ACCESSDATA_POSCTRL_PK_startx_shift                       (0)
#define ICH1_ACCESSDATA_POSCTRL_PK_starty_mask                        (0x3FFF0000)
#define ICH1_ACCESSDATA_POSCTRL_PK_startx_mask                        (0x00003FFF)
#define ICH1_ACCESSDATA_POSCTRL_PK_starty(data)                       (0x3FFF0000&((data)<<16))
#define ICH1_ACCESSDATA_POSCTRL_PK_startx(data)                       (0x00003FFF&(data))
#define ICH1_ACCESSDATA_POSCTRL_PK_get_starty(data)                   ((0x3FFF0000&(data))>>16)
#define ICH1_ACCESSDATA_POSCTRL_PK_get_startx(data)                   (0x00003FFF&(data))


#define ICH1_READDATA_DATA_Y1_PK                                      0x180231b8
#define ICH1_READDATA_DATA_Y1_PK_reg_addr                             "0xb80231b8"
#define ICH1_READDATA_DATA_Y1_PK_reg                                  0xb80231b8
#define ICH1_READDATA_DATA_Y1_PK_inst_addr                            "0x006E"
#define ICH1_READDATA_DATA_Y1_PK_inst                                 0x006E
#define ICH1_READDATA_DATA_Y1_PK_y01_shift                            (16)
#define ICH1_READDATA_DATA_Y1_PK_y00_shift                            (0)
#define ICH1_READDATA_DATA_Y1_PK_y01_mask                             (0x03FF0000)
#define ICH1_READDATA_DATA_Y1_PK_y00_mask                             (0x000003FF)
#define ICH1_READDATA_DATA_Y1_PK_y01(data)                            (0x03FF0000&((data)<<16))
#define ICH1_READDATA_DATA_Y1_PK_y00(data)                            (0x000003FF&(data))
#define ICH1_READDATA_DATA_Y1_PK_get_y01(data)                        ((0x03FF0000&(data))>>16)
#define ICH1_READDATA_DATA_Y1_PK_get_y00(data)                        (0x000003FF&(data))


#define ICH1_READDATA_DATA_Y2_PK                                      0x180231bc
#define ICH1_READDATA_DATA_Y2_PK_reg_addr                             "0xb80231bc"
#define ICH1_READDATA_DATA_Y2_PK_reg                                  0xb80231bc
#define ICH1_READDATA_DATA_Y2_PK_inst_addr                            "0x006F"
#define ICH1_READDATA_DATA_Y2_PK_inst                                 0x006F
#define ICH1_READDATA_DATA_Y2_PK_y11_shift                            (16)
#define ICH1_READDATA_DATA_Y2_PK_y10_shift                            (0)
#define ICH1_READDATA_DATA_Y2_PK_y11_mask                             (0x03FF0000)
#define ICH1_READDATA_DATA_Y2_PK_y10_mask                             (0x000003FF)
#define ICH1_READDATA_DATA_Y2_PK_y11(data)                            (0x03FF0000&((data)<<16))
#define ICH1_READDATA_DATA_Y2_PK_y10(data)                            (0x000003FF&(data))
#define ICH1_READDATA_DATA_Y2_PK_get_y11(data)                        ((0x03FF0000&(data))>>16)
#define ICH1_READDATA_DATA_Y2_PK_get_y10(data)                        (0x000003FF&(data))


#define ICH1_READDATA_DATA_C1_PK                                      0x180231c0
#define ICH1_READDATA_DATA_C1_PK_reg_addr                             "0xb80231c0"
#define ICH1_READDATA_DATA_C1_PK_reg                                  0xb80231c0
#define ICH1_READDATA_DATA_C1_PK_inst_addr                            "0x0070"
#define ICH1_READDATA_DATA_C1_PK_inst                                 0x0070
#define ICH1_READDATA_DATA_C1_PK_v00_shift                            (16)
#define ICH1_READDATA_DATA_C1_PK_u00_shift                            (0)
#define ICH1_READDATA_DATA_C1_PK_v00_mask                             (0x03FF0000)
#define ICH1_READDATA_DATA_C1_PK_u00_mask                             (0x000003FF)
#define ICH1_READDATA_DATA_C1_PK_v00(data)                            (0x03FF0000&((data)<<16))
#define ICH1_READDATA_DATA_C1_PK_u00(data)                            (0x000003FF&(data))
#define ICH1_READDATA_DATA_C1_PK_get_v00(data)                        ((0x03FF0000&(data))>>16)
#define ICH1_READDATA_DATA_C1_PK_get_u00(data)                        (0x000003FF&(data))


#define ICH1_READDATA_DATA_C2_PK                                      0x180231c4
#define ICH1_READDATA_DATA_C2_PK_reg_addr                             "0xb80231c4"
#define ICH1_READDATA_DATA_C2_PK_reg                                  0xb80231c4
#define ICH1_READDATA_DATA_C2_PK_inst_addr                            "0x0071"
#define ICH1_READDATA_DATA_C2_PK_inst                                 0x0071
#define ICH1_READDATA_DATA_C2_PK_v01_shift                            (16)
#define ICH1_READDATA_DATA_C2_PK_u01_shift                            (0)
#define ICH1_READDATA_DATA_C2_PK_v01_mask                             (0x03FF0000)
#define ICH1_READDATA_DATA_C2_PK_u01_mask                             (0x000003FF)
#define ICH1_READDATA_DATA_C2_PK_v01(data)                            (0x03FF0000&((data)<<16))
#define ICH1_READDATA_DATA_C2_PK_u01(data)                            (0x000003FF&(data))
#define ICH1_READDATA_DATA_C2_PK_get_v01(data)                        ((0x03FF0000&(data))>>16)
#define ICH1_READDATA_DATA_C2_PK_get_u01(data)                        (0x000003FF&(data))


#define ICH1_READDATA_DATA_C3_PK                                      0x180231c8
#define ICH1_READDATA_DATA_C3_PK_reg_addr                             "0xb80231c8"
#define ICH1_READDATA_DATA_C3_PK_reg                                  0xb80231c8
#define ICH1_READDATA_DATA_C3_PK_inst_addr                            "0x0072"
#define ICH1_READDATA_DATA_C3_PK_inst                                 0x0072
#define ICH1_READDATA_DATA_C3_PK_v10_shift                            (16)
#define ICH1_READDATA_DATA_C3_PK_u10_shift                            (0)
#define ICH1_READDATA_DATA_C3_PK_v10_mask                             (0x03FF0000)
#define ICH1_READDATA_DATA_C3_PK_u10_mask                             (0x000003FF)
#define ICH1_READDATA_DATA_C3_PK_v10(data)                            (0x03FF0000&((data)<<16))
#define ICH1_READDATA_DATA_C3_PK_u10(data)                            (0x000003FF&(data))
#define ICH1_READDATA_DATA_C3_PK_get_v10(data)                        ((0x03FF0000&(data))>>16)
#define ICH1_READDATA_DATA_C3_PK_get_u10(data)                        (0x000003FF&(data))


#define ICH1_READDATA_DATA_C4_PK                                      0x180231cc
#define ICH1_READDATA_DATA_C4_PK_reg_addr                             "0xb80231cc"
#define ICH1_READDATA_DATA_C4_PK_reg                                  0xb80231cc
#define ICH1_READDATA_DATA_C4_PK_inst_addr                            "0x0073"
#define ICH1_READDATA_DATA_C4_PK_inst                                 0x0073
#define ICH1_READDATA_DATA_C4_PK_v11_shift                            (16)
#define ICH1_READDATA_DATA_C4_PK_u11_shift                            (0)
#define ICH1_READDATA_DATA_C4_PK_v11_mask                             (0x03FF0000)
#define ICH1_READDATA_DATA_C4_PK_u11_mask                             (0x000003FF)
#define ICH1_READDATA_DATA_C4_PK_v11(data)                            (0x03FF0000&((data)<<16))
#define ICH1_READDATA_DATA_C4_PK_u11(data)                            (0x000003FF&(data))
#define ICH1_READDATA_DATA_C4_PK_get_v11(data)                        ((0x03FF0000&(data))>>16)
#define ICH1_READDATA_DATA_C4_PK_get_u11(data)                        (0x000003FF&(data))


#define ICH1_WRITEDATA_DATA_PK                                        0x180231d0
#define ICH1_WRITEDATA_DATA_PK_reg_addr                               "0xb80231d0"
#define ICH1_WRITEDATA_DATA_PK_reg                                    0xb80231d0
#define ICH1_WRITEDATA_DATA_PK_inst_addr                              "0x0074"
#define ICH1_WRITEDATA_DATA_PK_inst                                   0x0074
#define ICH1_WRITEDATA_DATA_PK_v_shift                                (8)
#define ICH1_WRITEDATA_DATA_PK_u_shift                                (4)
#define ICH1_WRITEDATA_DATA_PK_y_shift                                (0)
#define ICH1_WRITEDATA_DATA_PK_v_mask                                 (0x00000F00)
#define ICH1_WRITEDATA_DATA_PK_u_mask                                 (0x000000F0)
#define ICH1_WRITEDATA_DATA_PK_y_mask                                 (0x0000000F)
#define ICH1_WRITEDATA_DATA_PK_v(data)                                (0x00000F00&((data)<<8))
#define ICH1_WRITEDATA_DATA_PK_u(data)                                (0x000000F0&((data)<<4))
#define ICH1_WRITEDATA_DATA_PK_y(data)                                (0x0000000F&(data))
#define ICH1_WRITEDATA_DATA_PK_get_v(data)                            ((0x00000F00&(data))>>8)
#define ICH1_WRITEDATA_DATA_PK_get_u(data)                            ((0x000000F0&(data))>>4)
#define ICH1_WRITEDATA_DATA_PK_get_y(data)                            (0x0000000F&(data))


#define ICH2_ACCESSDATA_CTRL_PK                                       0x180231d4
#define ICH2_ACCESSDATA_CTRL_PK_reg_addr                              "0xb80231d4"
#define ICH2_ACCESSDATA_CTRL_PK_reg                                   0xb80231d4
#define ICH2_ACCESSDATA_CTRL_PK_inst_addr                             "0x0075"
#define ICH2_ACCESSDATA_CTRL_PK_inst                                  0x0075
#define ICH2_ACCESSDATA_CTRL_PK_write_en_shift                        (1)
#define ICH2_ACCESSDATA_CTRL_PK_read_en_shift                         (0)
#define ICH2_ACCESSDATA_CTRL_PK_write_en_mask                         (0x00000002)
#define ICH2_ACCESSDATA_CTRL_PK_read_en_mask                          (0x00000001)
#define ICH2_ACCESSDATA_CTRL_PK_write_en(data)                        (0x00000002&((data)<<1))
#define ICH2_ACCESSDATA_CTRL_PK_read_en(data)                         (0x00000001&(data))
#define ICH2_ACCESSDATA_CTRL_PK_get_write_en(data)                    ((0x00000002&(data))>>1)
#define ICH2_ACCESSDATA_CTRL_PK_get_read_en(data)                     (0x00000001&(data))


#define ICH2_ACCESSDATA_POSCTRL_PK                                    0x180231d8
#define ICH2_ACCESSDATA_POSCTRL_PK_reg_addr                           "0xb80231d8"
#define ICH2_ACCESSDATA_POSCTRL_PK_reg                                0xb80231d8
#define ICH2_ACCESSDATA_POSCTRL_PK_inst_addr                          "0x0076"
#define ICH2_ACCESSDATA_POSCTRL_PK_inst                               0x0076
#define ICH2_ACCESSDATA_POSCTRL_PK_starty_shift                       (16)
#define ICH2_ACCESSDATA_POSCTRL_PK_startx_shift                       (0)
#define ICH2_ACCESSDATA_POSCTRL_PK_starty_mask                        (0x3FFF0000)
#define ICH2_ACCESSDATA_POSCTRL_PK_startx_mask                        (0x00003FFF)
#define ICH2_ACCESSDATA_POSCTRL_PK_starty(data)                       (0x3FFF0000&((data)<<16))
#define ICH2_ACCESSDATA_POSCTRL_PK_startx(data)                       (0x00003FFF&(data))
#define ICH2_ACCESSDATA_POSCTRL_PK_get_starty(data)                   ((0x3FFF0000&(data))>>16)
#define ICH2_ACCESSDATA_POSCTRL_PK_get_startx(data)                   (0x00003FFF&(data))


#define ICH2_READDATA_DATA_Y1_PK                                      0x180231dc
#define ICH2_READDATA_DATA_Y1_PK_reg_addr                             "0xb80231dc"
#define ICH2_READDATA_DATA_Y1_PK_reg                                  0xb80231dc
#define ICH2_READDATA_DATA_Y1_PK_inst_addr                            "0x0077"
#define ICH2_READDATA_DATA_Y1_PK_inst                                 0x0077
#define ICH2_READDATA_DATA_Y1_PK_y01_shift                            (16)
#define ICH2_READDATA_DATA_Y1_PK_y00_shift                            (0)
#define ICH2_READDATA_DATA_Y1_PK_y01_mask                             (0x00FF0000)
#define ICH2_READDATA_DATA_Y1_PK_y00_mask                             (0x000000FF)
#define ICH2_READDATA_DATA_Y1_PK_y01(data)                            (0x00FF0000&((data)<<16))
#define ICH2_READDATA_DATA_Y1_PK_y00(data)                            (0x000000FF&(data))
#define ICH2_READDATA_DATA_Y1_PK_get_y01(data)                        ((0x00FF0000&(data))>>16)
#define ICH2_READDATA_DATA_Y1_PK_get_y00(data)                        (0x000000FF&(data))


#define ICH2_READDATA_DATA_Y2_PK                                      0x180231e0
#define ICH2_READDATA_DATA_Y2_PK_reg_addr                             "0xb80231e0"
#define ICH2_READDATA_DATA_Y2_PK_reg                                  0xb80231e0
#define ICH2_READDATA_DATA_Y2_PK_inst_addr                            "0x0078"
#define ICH2_READDATA_DATA_Y2_PK_inst                                 0x0078
#define ICH2_READDATA_DATA_Y2_PK_y11_shift                            (16)
#define ICH2_READDATA_DATA_Y2_PK_y10_shift                            (0)
#define ICH2_READDATA_DATA_Y2_PK_y11_mask                             (0x00FF0000)
#define ICH2_READDATA_DATA_Y2_PK_y10_mask                             (0x000000FF)
#define ICH2_READDATA_DATA_Y2_PK_y11(data)                            (0x00FF0000&((data)<<16))
#define ICH2_READDATA_DATA_Y2_PK_y10(data)                            (0x000000FF&(data))
#define ICH2_READDATA_DATA_Y2_PK_get_y11(data)                        ((0x00FF0000&(data))>>16)
#define ICH2_READDATA_DATA_Y2_PK_get_y10(data)                        (0x000000FF&(data))


#define ICH2_READDATA_DATA_C1_PK                                      0x180231e4
#define ICH2_READDATA_DATA_C1_PK_reg_addr                             "0xb80231e4"
#define ICH2_READDATA_DATA_C1_PK_reg                                  0xb80231e4
#define ICH2_READDATA_DATA_C1_PK_inst_addr                            "0x0079"
#define ICH2_READDATA_DATA_C1_PK_inst                                 0x0079
#define ICH2_READDATA_DATA_C1_PK_v00_shift                            (16)
#define ICH2_READDATA_DATA_C1_PK_u00_shift                            (0)
#define ICH2_READDATA_DATA_C1_PK_v00_mask                             (0x00FF0000)
#define ICH2_READDATA_DATA_C1_PK_u00_mask                             (0x000000FF)
#define ICH2_READDATA_DATA_C1_PK_v00(data)                            (0x00FF0000&((data)<<16))
#define ICH2_READDATA_DATA_C1_PK_u00(data)                            (0x000000FF&(data))
#define ICH2_READDATA_DATA_C1_PK_get_v00(data)                        ((0x00FF0000&(data))>>16)
#define ICH2_READDATA_DATA_C1_PK_get_u00(data)                        (0x000000FF&(data))


#define ICH2_READDATA_DATA_C2_PK                                      0x180231e8
#define ICH2_READDATA_DATA_C2_PK_reg_addr                             "0xb80231e8"
#define ICH2_READDATA_DATA_C2_PK_reg                                  0xb80231e8
#define ICH2_READDATA_DATA_C2_PK_inst_addr                            "0x007A"
#define ICH2_READDATA_DATA_C2_PK_inst                                 0x007A
#define ICH2_READDATA_DATA_C2_PK_v01_shift                            (16)
#define ICH2_READDATA_DATA_C2_PK_u01_shift                            (0)
#define ICH2_READDATA_DATA_C2_PK_v01_mask                             (0x00FF0000)
#define ICH2_READDATA_DATA_C2_PK_u01_mask                             (0x000000FF)
#define ICH2_READDATA_DATA_C2_PK_v01(data)                            (0x00FF0000&((data)<<16))
#define ICH2_READDATA_DATA_C2_PK_u01(data)                            (0x000000FF&(data))
#define ICH2_READDATA_DATA_C2_PK_get_v01(data)                        ((0x00FF0000&(data))>>16)
#define ICH2_READDATA_DATA_C2_PK_get_u01(data)                        (0x000000FF&(data))


#define ICH2_READDATA_DATA_C3_PK                                      0x180231ec
#define ICH2_READDATA_DATA_C3_PK_reg_addr                             "0xb80231ec"
#define ICH2_READDATA_DATA_C3_PK_reg                                  0xb80231ec
#define ICH2_READDATA_DATA_C3_PK_inst_addr                            "0x007B"
#define ICH2_READDATA_DATA_C3_PK_inst                                 0x007B
#define ICH2_READDATA_DATA_C3_PK_v10_shift                            (16)
#define ICH2_READDATA_DATA_C3_PK_u10_shift                            (0)
#define ICH2_READDATA_DATA_C3_PK_v10_mask                             (0x00FF0000)
#define ICH2_READDATA_DATA_C3_PK_u10_mask                             (0x000000FF)
#define ICH2_READDATA_DATA_C3_PK_v10(data)                            (0x00FF0000&((data)<<16))
#define ICH2_READDATA_DATA_C3_PK_u10(data)                            (0x000000FF&(data))
#define ICH2_READDATA_DATA_C3_PK_get_v10(data)                        ((0x00FF0000&(data))>>16)
#define ICH2_READDATA_DATA_C3_PK_get_u10(data)                        (0x000000FF&(data))


#define ICH2_READDATA_DATA_C4_PK                                      0x180231f0
#define ICH2_READDATA_DATA_C4_PK_reg_addr                             "0xb80231f0"
#define ICH2_READDATA_DATA_C4_PK_reg                                  0xb80231f0
#define ICH2_READDATA_DATA_C4_PK_inst_addr                            "0x007C"
#define ICH2_READDATA_DATA_C4_PK_inst                                 0x007C
#define ICH2_READDATA_DATA_C4_PK_v11_shift                            (16)
#define ICH2_READDATA_DATA_C4_PK_u11_shift                            (0)
#define ICH2_READDATA_DATA_C4_PK_v11_mask                             (0x00FF0000)
#define ICH2_READDATA_DATA_C4_PK_u11_mask                             (0x000000FF)
#define ICH2_READDATA_DATA_C4_PK_v11(data)                            (0x00FF0000&((data)<<16))
#define ICH2_READDATA_DATA_C4_PK_u11(data)                            (0x000000FF&(data))
#define ICH2_READDATA_DATA_C4_PK_get_v11(data)                        ((0x00FF0000&(data))>>16)
#define ICH2_READDATA_DATA_C4_PK_get_u11(data)                        (0x000000FF&(data))


#define ICH2_WRITEDATA_DATA_PK                                        0x180231f4
#define ICH2_WRITEDATA_DATA_PK_reg_addr                               "0xb80231f4"
#define ICH2_WRITEDATA_DATA_PK_reg                                    0xb80231f4
#define ICH2_WRITEDATA_DATA_PK_inst_addr                              "0x007D"
#define ICH2_WRITEDATA_DATA_PK_inst                                   0x007D
#define ICH2_WRITEDATA_DATA_PK_v_shift                                (8)
#define ICH2_WRITEDATA_DATA_PK_u_shift                                (4)
#define ICH2_WRITEDATA_DATA_PK_y_shift                                (0)
#define ICH2_WRITEDATA_DATA_PK_v_mask                                 (0x00000F00)
#define ICH2_WRITEDATA_DATA_PK_u_mask                                 (0x000000F0)
#define ICH2_WRITEDATA_DATA_PK_y_mask                                 (0x0000000F)
#define ICH2_WRITEDATA_DATA_PK_v(data)                                (0x00000F00&((data)<<8))
#define ICH2_WRITEDATA_DATA_PK_u(data)                                (0x000000F0&((data)<<4))
#define ICH2_WRITEDATA_DATA_PK_y(data)                                (0x0000000F&(data))
#define ICH2_WRITEDATA_DATA_PK_get_v(data)                            ((0x00000F00&(data))>>8)
#define ICH2_WRITEDATA_DATA_PK_get_u(data)                            ((0x000000F0&(data))>>4)
#define ICH2_WRITEDATA_DATA_PK_get_y(data)                            (0x0000000F&(data))


#define I_DCTI_CTRL_1                                                 0x180231f8
#define I_DCTI_CTRL_1_reg_addr                                        "0xb80231f8"
#define I_DCTI_CTRL_1_reg                                             0xb80231f8
#define I_DCTI_CTRL_1_inst_addr                                       "0x007E"
#define I_DCTI_CTRL_1_inst                                            0x007E
#define I_DCTI_CTRL_1_data_sel_shift                                  (31)
#define I_DCTI_CTRL_1_maxlen_shift                                    (26)
#define I_DCTI_CTRL_1_psmth_shift                                     (16)
#define I_DCTI_CTRL_1_lpmode_shift                                    (14)
#define I_DCTI_CTRL_1_engdiv_shift                                    (12)
#define I_DCTI_CTRL_1_offdiv_shift                                    (10)
#define I_DCTI_CTRL_1_uvgain_shift                                    (4)
#define I_DCTI_CTRL_1_dcti_mode_shift                                 (3)
#define I_DCTI_CTRL_1_dummy180231f8_2_shift                           (2)
#define I_DCTI_CTRL_1_cur_sel_shift                                   (1)
#define I_DCTI_CTRL_1_dcti_en_shift                                   (0)
#define I_DCTI_CTRL_1_data_sel_mask                                   (0x80000000)
#define I_DCTI_CTRL_1_maxlen_mask                                     (0x1C000000)
#define I_DCTI_CTRL_1_psmth_mask                                      (0x03FF0000)
#define I_DCTI_CTRL_1_lpmode_mask                                     (0x0000C000)
#define I_DCTI_CTRL_1_engdiv_mask                                     (0x00003000)
#define I_DCTI_CTRL_1_offdiv_mask                                     (0x00000C00)
#define I_DCTI_CTRL_1_uvgain_mask                                     (0x000003F0)
#define I_DCTI_CTRL_1_dcti_mode_mask                                  (0x00000008)
#define I_DCTI_CTRL_1_dummy180231f8_2_mask                            (0x00000004)
#define I_DCTI_CTRL_1_cur_sel_mask                                    (0x00000002)
#define I_DCTI_CTRL_1_dcti_en_mask                                    (0x00000001)
#define I_DCTI_CTRL_1_data_sel(data)                                  (0x80000000&((data)<<31))
#define I_DCTI_CTRL_1_maxlen(data)                                    (0x1C000000&((data)<<26))
#define I_DCTI_CTRL_1_psmth(data)                                     (0x03FF0000&((data)<<16))
#define I_DCTI_CTRL_1_lpmode(data)                                    (0x0000C000&((data)<<14))
#define I_DCTI_CTRL_1_engdiv(data)                                    (0x00003000&((data)<<12))
#define I_DCTI_CTRL_1_offdiv(data)                                    (0x00000C00&((data)<<10))
#define I_DCTI_CTRL_1_uvgain(data)                                    (0x000003F0&((data)<<4))
#define I_DCTI_CTRL_1_dcti_mode(data)                                 (0x00000008&((data)<<3))
#define I_DCTI_CTRL_1_dummy180231f8_2(data)                           (0x00000004&((data)<<2))
#define I_DCTI_CTRL_1_cur_sel(data)                                   (0x00000002&((data)<<1))
#define I_DCTI_CTRL_1_dcti_en(data)                                   (0x00000001&(data))
#define I_DCTI_CTRL_1_get_data_sel(data)                              ((0x80000000&(data))>>31)
#define I_DCTI_CTRL_1_get_maxlen(data)                                ((0x1C000000&(data))>>26)
#define I_DCTI_CTRL_1_get_psmth(data)                                 ((0x03FF0000&(data))>>16)
#define I_DCTI_CTRL_1_get_lpmode(data)                                ((0x0000C000&(data))>>14)
#define I_DCTI_CTRL_1_get_engdiv(data)                                ((0x00003000&(data))>>12)
#define I_DCTI_CTRL_1_get_offdiv(data)                                ((0x00000C00&(data))>>10)
#define I_DCTI_CTRL_1_get_uvgain(data)                                ((0x000003F0&(data))>>4)
#define I_DCTI_CTRL_1_get_dcti_mode(data)                             ((0x00000008&(data))>>3)
#define I_DCTI_CTRL_1_get_dummy180231f8_2(data)                       ((0x00000004&(data))>>2)
#define I_DCTI_CTRL_1_get_cur_sel(data)                               ((0x00000002&(data))>>1)
#define I_DCTI_CTRL_1_get_dcti_en(data)                               (0x00000001&(data))


#define ICH1_GENERAL_DB_CTRL                                          0x180231fc
#define ICH1_GENERAL_DB_CTRL_reg_addr                                 "0xb80231fc"
#define ICH1_GENERAL_DB_CTRL_reg                                      0xb80231fc
#define ICH1_GENERAL_DB_CTRL_inst_addr                                "0x007F"
#define ICH1_GENERAL_DB_CTRL_inst                                     0x007F
#define ICH1_GENERAL_DB_CTRL_general_db_apply_shift                   (2)
#define ICH1_GENERAL_DB_CTRL_general_db_rd_sel_shift                  (1)
#define ICH1_GENERAL_DB_CTRL_general_db_en_shift                      (0)
#define ICH1_GENERAL_DB_CTRL_general_db_apply_mask                    (0x00000004)
#define ICH1_GENERAL_DB_CTRL_general_db_rd_sel_mask                   (0x00000002)
#define ICH1_GENERAL_DB_CTRL_general_db_en_mask                       (0x00000001)
#define ICH1_GENERAL_DB_CTRL_general_db_apply(data)                   (0x00000004&((data)<<2))
#define ICH1_GENERAL_DB_CTRL_general_db_rd_sel(data)                  (0x00000002&((data)<<1))
#define ICH1_GENERAL_DB_CTRL_general_db_en(data)                      (0x00000001&(data))
#define ICH1_GENERAL_DB_CTRL_get_general_db_apply(data)               ((0x00000004&(data))>>2)
#define ICH1_GENERAL_DB_CTRL_get_general_db_rd_sel(data)              ((0x00000002&(data))>>1)
#define ICH1_GENERAL_DB_CTRL_get_general_db_en(data)                  (0x00000001&(data))
#endif
