// This file is generated using the spec version 0.1, firmware template version 1.39and DVR_Parser_0.46
#ifndef _VI_REG_H_INCLUDED_
#define _VI_REG_H_INCLUDED_

//#define  _VI_USE_STRUCT
#ifdef _VI_USE_STRUCT

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    neg:1;
}vi_EXT_EDGENEG;

typedef struct
{
    unsigned int    reserved_0:29;
    unsigned int    ignore:1;
    unsigned int    enable:1;
    unsigned int    write_data:1;
}vi_PBIT;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    error:1;
}vi_PBIT_ERR;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    field:1;
    unsigned int    vcnt:9;
    unsigned int    hcnt:10;
}vi_FVH;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    write_enable1:1;
    unsigned int    vstart:9;
    unsigned int    write_enable2:1;
    unsigned int    vend:9;
}vi_CWV;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    write_enable1:1;
    unsigned int    hstart:10;
    unsigned int    write_enable2:1;
    unsigned int    hend:10;
}vi_CWH;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    delay:5;
}vi_VSYNC;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    enable:1;
}vi_BTDECOEN;

typedef struct
{
    unsigned int    reserved_0:30;
    unsigned int    vsinte:1;
    unsigned int    write_data:1;
}vi_INTEN;

typedef struct
{
    unsigned int    reserved_0:30;
    unsigned int    vsints:1;
    unsigned int    write_data:1;
}vi_INTST;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    write_enable1:1;
    unsigned int    glb_sel:2;
    unsigned int    write_enable2:1;
    unsigned int    enable:1;
}vi_GLB_DBG;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    write_enable2:1;
    unsigned int    vi_dbg_sel:7;
    unsigned int    write_enable1:1;
    unsigned int    enable:1;
}vi_DBG;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    write_enable1:1;
    unsigned int    cvden:1;
    unsigned int    write_enable2:1;
    unsigned int    cvdtp:2;
}vi_CVDEN;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    write_enable1:1;
    unsigned int    t1:8;
    unsigned int    write_enable2:1;
    unsigned int    t2:8;
    unsigned int    write_enable3:1;
    unsigned int    rshiftsize:3;
    unsigned int    write_enable4:1;
    unsigned int    hornr_select:1;
}vi_HORNR_Y;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    write_enable1:1;
    unsigned int    t1:8;
    unsigned int    write_enable2:1;
    unsigned int    t2:8;
    unsigned int    write_enable3:1;
    unsigned int    rshiftsize:3;
}vi_HORNR_C;

typedef struct
{
    unsigned int    reserved_0:29;
    unsigned int    yen:1;
    unsigned int    cen:1;
    unsigned int    write_data:1;
}vi_SCCTL2;

typedef struct
{
    unsigned int    write_enable1:1;
    unsigned int    yonp:13;
    unsigned int    write_enable2:1;
    unsigned int    ydphs:17;
}vi_YSC2;

typedef struct
{
    unsigned int    write_enable1:1;
    unsigned int    conp:13;
    unsigned int    write_enable2:1;
    unsigned int    cdphs:17;
}vi_CSC2;

typedef struct
{
    unsigned int    reserved_0:11;
    unsigned int    write_enable1:1;
    unsigned int    yc:6;
    unsigned int    write_enable2:1;
    unsigned int    yp1:6;
    unsigned int    write_enable3:1;
    unsigned int    yp2:6;
}vi_DIDMA_YADS;

typedef struct
{
    unsigned int    reserved_0:11;
    unsigned int    write_enable1:1;
    unsigned int    cc:6;
    unsigned int    write_enable2:1;
    unsigned int    cp1:6;
    unsigned int    write_enable3:1;
    unsigned int    cp2:6;
}vi_DIDMA_CADS;

typedef struct
{
    unsigned int    reserved_0:18;
    unsigned int    write_enable1:1;
    unsigned int    fmc:6;
    unsigned int    write_enable2:1;
    unsigned int    fmp:6;
}vi_DIDMA_FMADS;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    err_yout:1;
    unsigned int    err_cout:1;
    unsigned int    err_yc:1;
    unsigned int    err_cc:1;
    unsigned int    err_fmc:1;
    unsigned int    err_yp1:1;
    unsigned int    err_yp2:1;
    unsigned int    err_cp1:1;
    unsigned int    err_cp2:1;
    unsigned int    err_fmp:1;
}vi_DIDMA_ERR;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    go:1;
}vi_DIDMA_CTRL;

typedef struct
{
    unsigned int    reserved_0:19;
    unsigned int    write_enable2:1;
    unsigned int    topfield:1;
    unsigned int    write_enable4:1;
    unsigned int    chroma:1;
    unsigned int    write_enable3:1;
    unsigned int    sobel:1;
    unsigned int    write_enable2:1;
    unsigned int    fm:2;
    unsigned int    write_enable1:1;
    unsigned int    mode:3;
}vi_DIMODE;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    write_enable1:1;
    unsigned int    wr:6;
    unsigned int    write_enable2:1;
    unsigned int    cur:6;
    unsigned int    write_enable3:1;
    unsigned int    pre:6;
    unsigned int    write_enable4:1;
    unsigned int    nxt:6;
}vi_Y1PICSET1;

typedef struct
{
    unsigned int    reserved_0:18;
    unsigned int    write_enable1:1;
    unsigned int    pre2:6;
    unsigned int    write_enable2:1;
    unsigned int    nxt2:6;
}vi_Y1PICSET2;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    write_enable1:1;
    unsigned int    wr:6;
    unsigned int    write_enable2:1;
    unsigned int    cur:6;
    unsigned int    write_enable3:1;
    unsigned int    pre:6;
    unsigned int    write_enable4:1;
    unsigned int    nxt:6;
}vi_C1PICSET1;

typedef struct
{
    unsigned int    reserved_0:18;
    unsigned int    write_enable1:1;
    unsigned int    pre2:6;
    unsigned int    write_enable2:1;
    unsigned int    nxt2:6;
}vi_C1PICSET2;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    write_enable2:1;
    unsigned int    h:10;
    unsigned int    write_enable1:1;
    unsigned int    v:10;
}vi_SOBEL;

typedef struct
{
    unsigned int    reserved_0:14;
    unsigned int    write_enable3:1;
    unsigned int    th3:5;
    unsigned int    write_enable2:1;
    unsigned int    th2:5;
    unsigned int    write_enable1:1;
    unsigned int    th1:5;
}vi_CLASSIFY;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    write_enable3:1;
    unsigned int    th3:8;
    unsigned int    write_enable2:1;
    unsigned int    th2:8;
    unsigned int    write_enable1:1;
    unsigned int    th1:8;
}vi_FRAME_S;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    write_enable3:1;
    unsigned int    th3:8;
    unsigned int    write_enable2:1;
    unsigned int    th2:8;
    unsigned int    write_enable1:1;
    unsigned int    th1:8;
}vi_FRAME_RLV;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    write_enable3:1;
    unsigned int    th3:8;
    unsigned int    write_enable2:1;
    unsigned int    th2:8;
    unsigned int    write_enable1:1;
    unsigned int    th1:8;
}vi_FRAME_H;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    write_enable3:1;
    unsigned int    th3:8;
    unsigned int    write_enable2:1;
    unsigned int    th2:8;
    unsigned int    write_enable1:1;
    unsigned int    th1:8;
}vi_FRAME_M;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    write_enable3:1;
    unsigned int    th3:8;
    unsigned int    write_enable2:1;
    unsigned int    th2:8;
    unsigned int    write_enable1:1;
    unsigned int    th1:8;
}vi_FRAMEC_S;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    write_enable3:1;
    unsigned int    th3:8;
    unsigned int    write_enable2:1;
    unsigned int    th2:8;
    unsigned int    write_enable1:1;
    unsigned int    th1:8;
}vi_FRAMEC_RLV;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    write_enable3:1;
    unsigned int    th3:8;
    unsigned int    write_enable2:1;
    unsigned int    th2:8;
    unsigned int    write_enable1:1;
    unsigned int    th1:8;
}vi_FRAMEC_H;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    write_enable3:1;
    unsigned int    th3:8;
    unsigned int    write_enable2:1;
    unsigned int    th2:8;
    unsigned int    write_enable1:1;
    unsigned int    th1:8;
}vi_FRAMEC_M;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    write_enable3:1;
    unsigned int    th3:8;
    unsigned int    write_enable2:1;
    unsigned int    th2:8;
    unsigned int    write_enable1:1;
    unsigned int    th1:8;
}vi_FIELD_SRLV;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    write_enable3:1;
    unsigned int    th3:8;
    unsigned int    write_enable2:1;
    unsigned int    th2:8;
    unsigned int    write_enable1:1;
    unsigned int    th1:8;
}vi_FIELD_HM;

typedef struct
{
    unsigned int    reserved_0:23;
    unsigned int    write_enable1:1;
    unsigned int    th:8;
}vi_FRAME;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    write_enable3:1;
    unsigned int    still:8;
    unsigned int    write_enable2:1;
    unsigned int    var:8;
    unsigned int    write_enable1:1;
    unsigned int    th:8;
}vi_FIELD;

typedef struct
{
    unsigned int    reserved_0:19;
    unsigned int    write_enable2:1;
    unsigned int    th2:3;
    unsigned int    write_enable1:1;
    unsigned int    th1:8;
}vi_BLEND1;

typedef struct
{
    unsigned int    reserved_0:19;
    unsigned int    write_enable2:1;
    unsigned int    th2:3;
    unsigned int    write_enable1:1;
    unsigned int    th1:8;
}vi_BLEND2;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    th:8;
}vi_SMOOTH;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    write_enable2:1;
    unsigned int    inter:1;
    unsigned int    write_enable1:1;
    unsigned int    sobel:1;
}vi_OPTION;

typedef struct
{
    unsigned int    reserved_0:14;
    unsigned int    write_enable2:1;
    unsigned int    adj:8;
    unsigned int    write_enable1:1;
    unsigned int    mid:8;
}vi_WEIGHT;

typedef struct
{
    unsigned int    reserved_0:14;
    unsigned int    write_enable2:1;
    unsigned int    weight:8;
    unsigned int    write_enable1:1;
    unsigned int    th:8;
}vi_PREVDIR;

typedef struct
{
    unsigned int    reserved_0:30;
    unsigned int    m:2;
}vi_CINTRA;

typedef struct
{
    unsigned int    reserved_0:14;
    unsigned int    write_enable1:1;
    unsigned int    bstlen:3;
    unsigned int    write_enable2:1;
    unsigned int    vids_y:6;
    unsigned int    write_enable3:1;
    unsigned int    vids_c:6;
}vi_DSDMA_CTRL;

typedef struct
{
    unsigned int    reserved_0:30;
    unsigned int    y_err:1;
    unsigned int    c_err:1;
}vi_DSDMA_ERR;
#endif

#define VI_EXT_EDGENEG                                                0x18004000
#define VI_EXT_EDGENEG_reg_addr                                       "0xB8004000"
#define VI_EXT_EDGENEG_reg                                            0xB8004000
#define VI_EXT_EDGENEG_inst_addr                                      "0x0000"
#define VI_EXT_EDGENEG_inst                                           0x0000
#define VI_EXT_EDGENEG_neg_shift                                      (0)
#define VI_EXT_EDGENEG_neg_mask                                       (0x00000001)
#define VI_EXT_EDGENEG_neg(data)                                      (0x00000001&(data))
#define VI_EXT_EDGENEG_get_neg(data)                                  (0x00000001&(data))

#define VI_PBIT                                                       0x18004004
#define VI_PBIT_reg_addr                                              "0xB8004004"
#define VI_PBIT_reg                                                   0xB8004004
#define VI_PBIT_inst_addr                                             "0x0001"
#define VI_PBIT_inst                                                  0x0001
#define VI_PBIT_ignore_shift                                          (2)
#define VI_PBIT_enable_shift                                          (1)
#define VI_PBIT_write_data_shift                                      (0)
#define VI_PBIT_ignore_mask                                           (0x00000004)
#define VI_PBIT_enable_mask                                           (0x00000002)
#define VI_PBIT_write_data_mask                                       (0x00000001)
#define VI_PBIT_ignore(data)                                          (0x00000004&((data)<<2))
#define VI_PBIT_enable(data)                                          (0x00000002&((data)<<1))
#define VI_PBIT_write_data(data)                                      (0x00000001&(data))
#define VI_PBIT_get_ignore(data)                                      ((0x00000004&(data))>>2)
#define VI_PBIT_get_enable(data)                                      ((0x00000002&(data))>>1)
#define VI_PBIT_get_write_data(data)                                  (0x00000001&(data))

#define VI_PBIT_ERR                                                   0x18004008
#define VI_PBIT_ERR_reg_addr                                          "0xB8004008"
#define VI_PBIT_ERR_reg                                               0xB8004008
#define VI_PBIT_ERR_inst_addr                                         "0x0002"
#define VI_PBIT_ERR_inst                                              0x0002
#define VI_PBIT_ERR_error_shift                                       (0)
#define VI_PBIT_ERR_error_mask                                        (0x00000001)
#define VI_PBIT_ERR_error(data)                                       (0x00000001&(data))
#define VI_PBIT_ERR_get_error(data)                                   (0x00000001&(data))

#define VI_FVH                                                        0x1800400C
#define VI_FVH_reg_addr                                               "0xB800400C"
#define VI_FVH_reg                                                    0xB800400C
#define VI_FVH_inst_addr                                              "0x0003"
#define VI_FVH_inst                                                   0x0003
#define VI_FVH_field_shift                                            (19)
#define VI_FVH_vcnt_shift                                             (10)
#define VI_FVH_hcnt_shift                                             (0)
#define VI_FVH_field_mask                                             (0x00080000)
#define VI_FVH_vcnt_mask                                              (0x0007FC00)
#define VI_FVH_hcnt_mask                                              (0x000003FF)
#define VI_FVH_field(data)                                            (0x00080000&((data)<<19))
#define VI_FVH_vcnt(data)                                             (0x0007FC00&((data)<<10))
#define VI_FVH_hcnt(data)                                             (0x000003FF&(data))
#define VI_FVH_get_field(data)                                        ((0x00080000&(data))>>19)
#define VI_FVH_get_vcnt(data)                                         ((0x0007FC00&(data))>>10)
#define VI_FVH_get_hcnt(data)                                         (0x000003FF&(data))

#define VI_CWV                                                        0x18004010
#define VI_CWV_reg_addr                                               "0xB8004010"
#define VI_CWV_reg                                                    0xB8004010
#define VI_CWV_inst_addr                                              "0x0004"
#define VI_CWV_inst                                                   0x0004
#define VI_CWV_write_enable1_shift                                    (19)
#define VI_CWV_vstart_shift                                           (10)
#define VI_CWV_write_enable2_shift                                    (9)
#define VI_CWV_vend_shift                                             (0)
#define VI_CWV_write_enable1_mask                                     (0x00080000)
#define VI_CWV_vstart_mask                                            (0x0007FC00)
#define VI_CWV_write_enable2_mask                                     (0x00000200)
#define VI_CWV_vend_mask                                              (0x000001FF)
#define VI_CWV_write_enable1(data)                                    (0x00080000&((data)<<19))
#define VI_CWV_vstart(data)                                           (0x0007FC00&((data)<<10))
#define VI_CWV_write_enable2(data)                                    (0x00000200&((data)<<9))
#define VI_CWV_vend(data)                                             (0x000001FF&(data))
#define VI_CWV_get_write_enable1(data)                                ((0x00080000&(data))>>19)
#define VI_CWV_get_vstart(data)                                       ((0x0007FC00&(data))>>10)
#define VI_CWV_get_write_enable2(data)                                ((0x00000200&(data))>>9)
#define VI_CWV_get_vend(data)                                         (0x000001FF&(data))

#define VI_CWH                                                        0x18004014
#define VI_CWH_reg_addr                                               "0xB8004014"
#define VI_CWH_reg                                                    0xB8004014
#define VI_CWH_inst_addr                                              "0x0005"
#define VI_CWH_inst                                                   0x0005
#define VI_CWH_write_enable1_shift                                    (21)
#define VI_CWH_hstart_shift                                           (11)
#define VI_CWH_write_enable2_shift                                    (10)
#define VI_CWH_hend_shift                                             (0)
#define VI_CWH_write_enable1_mask                                     (0x00200000)
#define VI_CWH_hstart_mask                                            (0x001FF800)
#define VI_CWH_write_enable2_mask                                     (0x00000400)
#define VI_CWH_hend_mask                                              (0x000003FF)
#define VI_CWH_write_enable1(data)                                    (0x00200000&((data)<<21))
#define VI_CWH_hstart(data)                                           (0x001FF800&((data)<<11))
#define VI_CWH_write_enable2(data)                                    (0x00000400&((data)<<10))
#define VI_CWH_hend(data)                                             (0x000003FF&(data))
#define VI_CWH_get_write_enable1(data)                                ((0x00200000&(data))>>21)
#define VI_CWH_get_hstart(data)                                       ((0x001FF800&(data))>>11)
#define VI_CWH_get_write_enable2(data)                                ((0x00000400&(data))>>10)
#define VI_CWH_get_hend(data)                                         (0x000003FF&(data))

#define VI_VSYNC                                                      0x18004018
#define VI_VSYNC_reg_addr                                             "0xB8004018"
#define VI_VSYNC_reg                                                  0xB8004018
#define VI_VSYNC_inst_addr                                            "0x0006"
#define VI_VSYNC_inst                                                 0x0006
#define VI_VSYNC_delay_shift                                          (0)
#define VI_VSYNC_delay_mask                                           (0x0000001F)
#define VI_VSYNC_delay(data)                                          (0x0000001F&(data))
#define VI_VSYNC_get_delay(data)                                      (0x0000001F&(data))

#define VI_BTDECOEN                                                   0x1800401C
#define VI_BTDECOEN_reg_addr                                          "0xB800401C"
#define VI_BTDECOEN_reg                                               0xB800401C
#define VI_BTDECOEN_inst_addr                                         "0x0007"
#define VI_BTDECOEN_inst                                              0x0007
#define VI_BTDECOEN_enable_shift                                      (0)
#define VI_BTDECOEN_enable_mask                                       (0x00000001)
#define VI_BTDECOEN_enable(data)                                      (0x00000001&(data))
#define VI_BTDECOEN_get_enable(data)                                  (0x00000001&(data))

#define VI_INTEN                                                      0x18004020
#define VI_INTEN_reg_addr                                             "0xB8004020"
#define VI_INTEN_reg                                                  0xB8004020
#define VI_INTEN_inst_addr                                            "0x0008"
#define VI_INTEN_inst                                                 0x0008
#define VI_INTEN_vsinte_shift                                         (1)
#define VI_INTEN_write_data_shift                                     (0)
#define VI_INTEN_vsinte_mask                                          (0x00000002)
#define VI_INTEN_write_data_mask                                      (0x00000001)
#define VI_INTEN_vsinte(data)                                         (0x00000002&((data)<<1))
#define VI_INTEN_write_data(data)                                     (0x00000001&(data))
#define VI_INTEN_get_vsinte(data)                                     ((0x00000002&(data))>>1)
#define VI_INTEN_get_write_data(data)                                 (0x00000001&(data))

#define VI_INTST                                                      0x18004024
#define VI_INTST_reg_addr                                             "0xB8004024"
#define VI_INTST_reg                                                  0xB8004024
#define VI_INTST_inst_addr                                            "0x0009"
#define VI_INTST_inst                                                 0x0009
#define VI_INTST_vsints_shift                                         (1)
#define VI_INTST_write_data_shift                                     (0)
#define VI_INTST_vsints_mask                                          (0x00000002)
#define VI_INTST_write_data_mask                                      (0x00000001)
#define VI_INTST_vsints(data)                                         (0x00000002&((data)<<1))
#define VI_INTST_write_data(data)                                     (0x00000001&(data))
#define VI_INTST_get_vsints(data)                                     ((0x00000002&(data))>>1)
#define VI_INTST_get_write_data(data)                                 (0x00000001&(data))

#define VI_GLB_DBG                                                    0x18004028
#define VI_GLB_DBG_reg_addr                                           "0xB8004028"
#define VI_GLB_DBG_reg                                                0xB8004028
#define VI_GLB_DBG_inst_addr                                          "0x000A"
#define VI_GLB_DBG_inst                                               0x000A
#define VI_GLB_DBG_write_enable1_shift                                (4)
#define VI_GLB_DBG_glb_sel_shift                                      (2)
#define VI_GLB_DBG_write_enable2_shift                                (1)
#define VI_GLB_DBG_enable_shift                                       (0)
#define VI_GLB_DBG_write_enable1_mask                                 (0x00000010)
#define VI_GLB_DBG_glb_sel_mask                                       (0x0000000C)
#define VI_GLB_DBG_write_enable2_mask                                 (0x00000002)
#define VI_GLB_DBG_enable_mask                                        (0x00000001)
#define VI_GLB_DBG_write_enable1(data)                                (0x00000010&((data)<<4))
#define VI_GLB_DBG_glb_sel(data)                                      (0x0000000C&((data)<<2))
#define VI_GLB_DBG_write_enable2(data)                                (0x00000002&((data)<<1))
#define VI_GLB_DBG_enable(data)                                       (0x00000001&(data))
#define VI_GLB_DBG_get_write_enable1(data)                            ((0x00000010&(data))>>4)
#define VI_GLB_DBG_get_glb_sel(data)                                  ((0x0000000C&(data))>>2)
#define VI_GLB_DBG_get_write_enable2(data)                            ((0x00000002&(data))>>1)
#define VI_GLB_DBG_get_enable(data)                                   (0x00000001&(data))

#define VI_DBG                                                        0x1800402C
#define VI_DBG_reg_addr                                               "0xB800402C"
#define VI_DBG_reg                                                    0xB800402C
#define VI_DBG_inst_addr                                              "0x000B"
#define VI_DBG_inst                                                   0x000B
#define VI_DBG_write_enable2_shift                                    (9)
#define VI_DBG_vi_dbg_sel_shift                                       (2)
#define VI_DBG_write_enable1_shift                                    (1)
#define VI_DBG_enable_shift                                           (0)
#define VI_DBG_write_enable2_mask                                     (0x00000200)
#define VI_DBG_vi_dbg_sel_mask                                        (0x000001FC)
#define VI_DBG_write_enable1_mask                                     (0x00000002)
#define VI_DBG_enable_mask                                            (0x00000001)
#define VI_DBG_write_enable2(data)                                    (0x00000200&((data)<<9))
#define VI_DBG_vi_dbg_sel(data)                                       (0x000001FC&((data)<<2))
#define VI_DBG_write_enable1(data)                                    (0x00000002&((data)<<1))
#define VI_DBG_enable(data)                                           (0x00000001&(data))
#define VI_DBG_get_write_enable2(data)                                ((0x00000200&(data))>>9)
#define VI_DBG_get_vi_dbg_sel(data)                                   ((0x000001FC&(data))>>2)
#define VI_DBG_get_write_enable1(data)                                ((0x00000002&(data))>>1)
#define VI_DBG_get_enable(data)                                       (0x00000001&(data))

#define VI_CVDEN                                                      0x18004030
#define VI_CVDEN_reg_addr                                             "0xB8004030"
#define VI_CVDEN_reg                                                  0xB8004030
#define VI_CVDEN_inst_addr                                            "0x000C"
#define VI_CVDEN_inst                                                 0x000C
#define VI_CVDEN_write_enable1_shift                                  (4)
#define VI_CVDEN_cvden_shift                                          (3)
#define VI_CVDEN_write_enable2_shift                                  (2)
#define VI_CVDEN_cvdtp_shift                                          (0)
#define VI_CVDEN_write_enable1_mask                                   (0x00000010)
#define VI_CVDEN_cvden_mask                                           (0x00000008)
#define VI_CVDEN_write_enable2_mask                                   (0x00000004)
#define VI_CVDEN_cvdtp_mask                                           (0x00000003)
#define VI_CVDEN_write_enable1(data)                                  (0x00000010&((data)<<4))
#define VI_CVDEN_cvden(data)                                          (0x00000008&((data)<<3))
#define VI_CVDEN_write_enable2(data)                                  (0x00000004&((data)<<2))
#define VI_CVDEN_cvdtp(data)                                          (0x00000003&(data))
#define VI_CVDEN_get_write_enable1(data)                              ((0x00000010&(data))>>4)
#define VI_CVDEN_get_cvden(data)                                      ((0x00000008&(data))>>3)
#define VI_CVDEN_get_write_enable2(data)                              ((0x00000004&(data))>>2)
#define VI_CVDEN_get_cvdtp(data)                                      (0x00000003&(data))

#define VI_HORNR_Y                                                    0x18004034
#define VI_HORNR_Y_reg_addr                                           "0xB8004034"
#define VI_HORNR_Y_reg                                                0xB8004034
#define VI_HORNR_Y_inst_addr                                          "0x000D"
#define VI_HORNR_Y_inst                                               0x000D
#define VI_HORNR_Y_write_enable1_shift                                (23)
#define VI_HORNR_Y_t1_shift                                           (15)
#define VI_HORNR_Y_write_enable2_shift                                (14)
#define VI_HORNR_Y_t2_shift                                           (6)
#define VI_HORNR_Y_write_enable3_shift                                (5)
#define VI_HORNR_Y_rshiftsize_shift                                   (2)
#define VI_HORNR_Y_write_enable4_shift                                (1)
#define VI_HORNR_Y_hornr_select_shift                                 (0)
#define VI_HORNR_Y_write_enable1_mask                                 (0x00800000)
#define VI_HORNR_Y_t1_mask                                            (0x007F8000)
#define VI_HORNR_Y_write_enable2_mask                                 (0x00004000)
#define VI_HORNR_Y_t2_mask                                            (0x00003FC0)
#define VI_HORNR_Y_write_enable3_mask                                 (0x00000020)
#define VI_HORNR_Y_rshiftsize_mask                                    (0x0000001C)
#define VI_HORNR_Y_write_enable4_mask                                 (0x00000002)
#define VI_HORNR_Y_hornr_select_mask                                  (0x00000001)
#define VI_HORNR_Y_write_enable1(data)                                (0x00800000&((data)<<23))
#define VI_HORNR_Y_t1(data)                                           (0x007F8000&((data)<<15))
#define VI_HORNR_Y_write_enable2(data)                                (0x00004000&((data)<<14))
#define VI_HORNR_Y_t2(data)                                           (0x00003FC0&((data)<<6))
#define VI_HORNR_Y_write_enable3(data)                                (0x00000020&((data)<<5))
#define VI_HORNR_Y_rshiftsize(data)                                   (0x0000001C&((data)<<2))
#define VI_HORNR_Y_write_enable4(data)                                (0x00000002&((data)<<1))
#define VI_HORNR_Y_hornr_select(data)                                 (0x00000001&(data))
#define VI_HORNR_Y_get_write_enable1(data)                            ((0x00800000&(data))>>23)
#define VI_HORNR_Y_get_t1(data)                                       ((0x007F8000&(data))>>15)
#define VI_HORNR_Y_get_write_enable2(data)                            ((0x00004000&(data))>>14)
#define VI_HORNR_Y_get_t2(data)                                       ((0x00003FC0&(data))>>6)
#define VI_HORNR_Y_get_write_enable3(data)                            ((0x00000020&(data))>>5)
#define VI_HORNR_Y_get_rshiftsize(data)                               ((0x0000001C&(data))>>2)
#define VI_HORNR_Y_get_write_enable4(data)                            ((0x00000002&(data))>>1)
#define VI_HORNR_Y_get_hornr_select(data)                             (0x00000001&(data))

#define VI_HORNR_C                                                    0x18004038
#define VI_HORNR_C_reg_addr                                           "0xB8004038"
#define VI_HORNR_C_reg                                                0xB8004038
#define VI_HORNR_C_inst_addr                                          "0x000E"
#define VI_HORNR_C_inst                                               0x000E
#define VI_HORNR_C_write_enable1_shift                                (21)
#define VI_HORNR_C_t1_shift                                           (13)
#define VI_HORNR_C_write_enable2_shift                                (12)
#define VI_HORNR_C_t2_shift                                           (4)
#define VI_HORNR_C_write_enable3_shift                                (3)
#define VI_HORNR_C_rshiftsize_shift                                   (0)
#define VI_HORNR_C_write_enable1_mask                                 (0x00200000)
#define VI_HORNR_C_t1_mask                                            (0x001FE000)
#define VI_HORNR_C_write_enable2_mask                                 (0x00001000)
#define VI_HORNR_C_t2_mask                                            (0x00000FF0)
#define VI_HORNR_C_write_enable3_mask                                 (0x00000008)
#define VI_HORNR_C_rshiftsize_mask                                    (0x00000007)
#define VI_HORNR_C_write_enable1(data)                                (0x00200000&((data)<<21))
#define VI_HORNR_C_t1(data)                                           (0x001FE000&((data)<<13))
#define VI_HORNR_C_write_enable2(data)                                (0x00001000&((data)<<12))
#define VI_HORNR_C_t2(data)                                           (0x00000FF0&((data)<<4))
#define VI_HORNR_C_write_enable3(data)                                (0x00000008&((data)<<3))
#define VI_HORNR_C_rshiftsize(data)                                   (0x00000007&(data))
#define VI_HORNR_C_get_write_enable1(data)                            ((0x00200000&(data))>>21)
#define VI_HORNR_C_get_t1(data)                                       ((0x001FE000&(data))>>13)
#define VI_HORNR_C_get_write_enable2(data)                            ((0x00001000&(data))>>12)
#define VI_HORNR_C_get_t2(data)                                       ((0x00000FF0&(data))>>4)
#define VI_HORNR_C_get_write_enable3(data)                            ((0x00000008&(data))>>3)
#define VI_HORNR_C_get_rshiftsize(data)                               (0x00000007&(data))

#define VI_SCCTL2                                                     0x1800403C
#define VI_SCCTL2_reg_addr                                            "0xB800403C"
#define VI_SCCTL2_reg                                                 0xB800403C
#define VI_SCCTL2_inst_addr                                           "0x000F"
#define VI_SCCTL2_inst                                                0x000F
#define VI_SCCTL2_yen_shift                                           (2)
#define VI_SCCTL2_cen_shift                                           (1)
#define VI_SCCTL2_write_data_shift                                    (0)
#define VI_SCCTL2_yen_mask                                            (0x00000004)
#define VI_SCCTL2_cen_mask                                            (0x00000002)
#define VI_SCCTL2_write_data_mask                                     (0x00000001)
#define VI_SCCTL2_yen(data)                                           (0x00000004&((data)<<2))
#define VI_SCCTL2_cen(data)                                           (0x00000002&((data)<<1))
#define VI_SCCTL2_write_data(data)                                    (0x00000001&(data))
#define VI_SCCTL2_get_yen(data)                                       ((0x00000004&(data))>>2)
#define VI_SCCTL2_get_cen(data)                                       ((0x00000002&(data))>>1)
#define VI_SCCTL2_get_write_data(data)                                (0x00000001&(data))

#define VI_YSC2                                                       0x18004040
#define VI_YSC2_reg_addr                                              "0xB8004040"
#define VI_YSC2_reg                                                   0xB8004040
#define VI_YSC2_inst_addr                                             "0x0010"
#define VI_YSC2_inst                                                  0x0010
#define VI_YSC2_write_enable1_shift                                   (31)
#define VI_YSC2_yonp_shift                                            (18)
#define VI_YSC2_write_enable2_shift                                   (17)
#define VI_YSC2_ydphs_shift                                           (0)
#define VI_YSC2_write_enable1_mask                                    (0x80000000)
#define VI_YSC2_yonp_mask                                             (0x7FFC0000)
#define VI_YSC2_write_enable2_mask                                    (0x00020000)
#define VI_YSC2_ydphs_mask                                            (0x0001FFFF)
#define VI_YSC2_write_enable1(data)                                   (0x80000000&((data)<<31))
#define VI_YSC2_yonp(data)                                            (0x7FFC0000&((data)<<18))
#define VI_YSC2_write_enable2(data)                                   (0x00020000&((data)<<17))
#define VI_YSC2_ydphs(data)                                           (0x0001FFFF&(data))
#define VI_YSC2_get_write_enable1(data)                               ((0x80000000&(data))>>31)
#define VI_YSC2_get_yonp(data)                                        ((0x7FFC0000&(data))>>18)
#define VI_YSC2_get_write_enable2(data)                               ((0x00020000&(data))>>17)
#define VI_YSC2_get_ydphs(data)                                       (0x0001FFFF&(data))

#define VI_CSC2                                                       0x18004044
#define VI_CSC2_reg_addr                                              "0xB8004044"
#define VI_CSC2_reg                                                   0xB8004044
#define VI_CSC2_inst_addr                                             "0x0011"
#define VI_CSC2_inst                                                  0x0011
#define VI_CSC2_write_enable1_shift                                   (31)
#define VI_CSC2_conp_shift                                            (18)
#define VI_CSC2_write_enable2_shift                                   (17)
#define VI_CSC2_cdphs_shift                                           (0)
#define VI_CSC2_write_enable1_mask                                    (0x80000000)
#define VI_CSC2_conp_mask                                             (0x7FFC0000)
#define VI_CSC2_write_enable2_mask                                    (0x00020000)
#define VI_CSC2_cdphs_mask                                            (0x0001FFFF)
#define VI_CSC2_write_enable1(data)                                   (0x80000000&((data)<<31))
#define VI_CSC2_conp(data)                                            (0x7FFC0000&((data)<<18))
#define VI_CSC2_write_enable2(data)                                   (0x00020000&((data)<<17))
#define VI_CSC2_cdphs(data)                                           (0x0001FFFF&(data))
#define VI_CSC2_get_write_enable1(data)                               ((0x80000000&(data))>>31)
#define VI_CSC2_get_conp(data)                                        ((0x7FFC0000&(data))>>18)
#define VI_CSC2_get_write_enable2(data)                               ((0x00020000&(data))>>17)
#define VI_CSC2_get_cdphs(data)                                       (0x0001FFFF&(data))

#define VI_DIDMA_YADS                                                 0x18004048
#define VI_DIDMA_YADS_reg_addr                                        "0xB8004048"
#define VI_DIDMA_YADS_reg                                             0xB8004048
#define VI_DIDMA_YADS_inst_addr                                       "0x0012"
#define VI_DIDMA_YADS_inst                                            0x0012
#define VI_DIDMA_YADS_write_enable1_shift                             (20)
#define VI_DIDMA_YADS_yc_shift                                        (14)
#define VI_DIDMA_YADS_write_enable2_shift                             (13)
#define VI_DIDMA_YADS_yp1_shift                                       (7)
#define VI_DIDMA_YADS_write_enable3_shift                             (6)
#define VI_DIDMA_YADS_yp2_shift                                       (0)
#define VI_DIDMA_YADS_write_enable1_mask                              (0x00100000)
#define VI_DIDMA_YADS_yc_mask                                         (0x000FC000)
#define VI_DIDMA_YADS_write_enable2_mask                              (0x00002000)
#define VI_DIDMA_YADS_yp1_mask                                        (0x00001F80)
#define VI_DIDMA_YADS_write_enable3_mask                              (0x00000040)
#define VI_DIDMA_YADS_yp2_mask                                        (0x0000003F)
#define VI_DIDMA_YADS_write_enable1(data)                             (0x00100000&((data)<<20))
#define VI_DIDMA_YADS_yc(data)                                        (0x000FC000&((data)<<14))
#define VI_DIDMA_YADS_write_enable2(data)                             (0x00002000&((data)<<13))
#define VI_DIDMA_YADS_yp1(data)                                       (0x00001F80&((data)<<7))
#define VI_DIDMA_YADS_write_enable3(data)                             (0x00000040&((data)<<6))
#define VI_DIDMA_YADS_yp2(data)                                       (0x0000003F&(data))
#define VI_DIDMA_YADS_get_write_enable1(data)                         ((0x00100000&(data))>>20)
#define VI_DIDMA_YADS_get_yc(data)                                    ((0x000FC000&(data))>>14)
#define VI_DIDMA_YADS_get_write_enable2(data)                         ((0x00002000&(data))>>13)
#define VI_DIDMA_YADS_get_yp1(data)                                   ((0x00001F80&(data))>>7)
#define VI_DIDMA_YADS_get_write_enable3(data)                         ((0x00000040&(data))>>6)
#define VI_DIDMA_YADS_get_yp2(data)                                   (0x0000003F&(data))

#define VI_DIDMA_CADS                                                 0x1800404C
#define VI_DIDMA_CADS_reg_addr                                        "0xB800404C"
#define VI_DIDMA_CADS_reg                                             0xB800404C
#define VI_DIDMA_CADS_inst_addr                                       "0x0013"
#define VI_DIDMA_CADS_inst                                            0x0013
#define VI_DIDMA_CADS_write_enable1_shift                             (20)
#define VI_DIDMA_CADS_cc_shift                                        (14)
#define VI_DIDMA_CADS_write_enable2_shift                             (13)
#define VI_DIDMA_CADS_cp1_shift                                       (7)
#define VI_DIDMA_CADS_write_enable3_shift                             (6)
#define VI_DIDMA_CADS_cp2_shift                                       (0)
#define VI_DIDMA_CADS_write_enable1_mask                              (0x00100000)
#define VI_DIDMA_CADS_cc_mask                                         (0x000FC000)
#define VI_DIDMA_CADS_write_enable2_mask                              (0x00002000)
#define VI_DIDMA_CADS_cp1_mask                                        (0x00001F80)
#define VI_DIDMA_CADS_write_enable3_mask                              (0x00000040)
#define VI_DIDMA_CADS_cp2_mask                                        (0x0000003F)
#define VI_DIDMA_CADS_write_enable1(data)                             (0x00100000&((data)<<20))
#define VI_DIDMA_CADS_cc(data)                                        (0x000FC000&((data)<<14))
#define VI_DIDMA_CADS_write_enable2(data)                             (0x00002000&((data)<<13))
#define VI_DIDMA_CADS_cp1(data)                                       (0x00001F80&((data)<<7))
#define VI_DIDMA_CADS_write_enable3(data)                             (0x00000040&((data)<<6))
#define VI_DIDMA_CADS_cp2(data)                                       (0x0000003F&(data))
#define VI_DIDMA_CADS_get_write_enable1(data)                         ((0x00100000&(data))>>20)
#define VI_DIDMA_CADS_get_cc(data)                                    ((0x000FC000&(data))>>14)
#define VI_DIDMA_CADS_get_write_enable2(data)                         ((0x00002000&(data))>>13)
#define VI_DIDMA_CADS_get_cp1(data)                                   ((0x00001F80&(data))>>7)
#define VI_DIDMA_CADS_get_write_enable3(data)                         ((0x00000040&(data))>>6)
#define VI_DIDMA_CADS_get_cp2(data)                                   (0x0000003F&(data))

#define VI_DIDMA_FMADS                                                0x18004050
#define VI_DIDMA_FMADS_reg_addr                                       "0xB8004050"
#define VI_DIDMA_FMADS_reg                                            0xB8004050
#define VI_DIDMA_FMADS_inst_addr                                      "0x0014"
#define VI_DIDMA_FMADS_inst                                           0x0014
#define VI_DIDMA_FMADS_write_enable1_shift                            (13)
#define VI_DIDMA_FMADS_fmc_shift                                      (7)
#define VI_DIDMA_FMADS_write_enable2_shift                            (6)
#define VI_DIDMA_FMADS_fmp_shift                                      (0)
#define VI_DIDMA_FMADS_write_enable1_mask                             (0x00002000)
#define VI_DIDMA_FMADS_fmc_mask                                       (0x00001F80)
#define VI_DIDMA_FMADS_write_enable2_mask                             (0x00000040)
#define VI_DIDMA_FMADS_fmp_mask                                       (0x0000003F)
#define VI_DIDMA_FMADS_write_enable1(data)                            (0x00002000&((data)<<13))
#define VI_DIDMA_FMADS_fmc(data)                                      (0x00001F80&((data)<<7))
#define VI_DIDMA_FMADS_write_enable2(data)                            (0x00000040&((data)<<6))
#define VI_DIDMA_FMADS_fmp(data)                                      (0x0000003F&(data))
#define VI_DIDMA_FMADS_get_write_enable1(data)                        ((0x00002000&(data))>>13)
#define VI_DIDMA_FMADS_get_fmc(data)                                  ((0x00001F80&(data))>>7)
#define VI_DIDMA_FMADS_get_write_enable2(data)                        ((0x00000040&(data))>>6)
#define VI_DIDMA_FMADS_get_fmp(data)                                  (0x0000003F&(data))

#define VI_DIDMA_ERR                                                  0x18004054
#define VI_DIDMA_ERR_reg_addr                                         "0xB8004054"
#define VI_DIDMA_ERR_reg                                              0xB8004054
#define VI_DIDMA_ERR_inst_addr                                        "0x0015"
#define VI_DIDMA_ERR_inst                                             0x0015
#define VI_DIDMA_ERR_err_yout_shift                                   (9)
#define VI_DIDMA_ERR_err_cout_shift                                   (8)
#define VI_DIDMA_ERR_err_yc_shift                                     (7)
#define VI_DIDMA_ERR_err_cc_shift                                     (6)
#define VI_DIDMA_ERR_err_fmc_shift                                    (5)
#define VI_DIDMA_ERR_err_yp1_shift                                    (4)
#define VI_DIDMA_ERR_err_yp2_shift                                    (3)
#define VI_DIDMA_ERR_err_cp1_shift                                    (2)
#define VI_DIDMA_ERR_err_cp2_shift                                    (1)
#define VI_DIDMA_ERR_err_fmp_shift                                    (0)
#define VI_DIDMA_ERR_err_yout_mask                                    (0x00000200)
#define VI_DIDMA_ERR_err_cout_mask                                    (0x00000100)
#define VI_DIDMA_ERR_err_yc_mask                                      (0x00000080)
#define VI_DIDMA_ERR_err_cc_mask                                      (0x00000040)
#define VI_DIDMA_ERR_err_fmc_mask                                     (0x00000020)
#define VI_DIDMA_ERR_err_yp1_mask                                     (0x00000010)
#define VI_DIDMA_ERR_err_yp2_mask                                     (0x00000008)
#define VI_DIDMA_ERR_err_cp1_mask                                     (0x00000004)
#define VI_DIDMA_ERR_err_cp2_mask                                     (0x00000002)
#define VI_DIDMA_ERR_err_fmp_mask                                     (0x00000001)
#define VI_DIDMA_ERR_err_yout(data)                                   (0x00000200&((data)<<9))
#define VI_DIDMA_ERR_err_cout(data)                                   (0x00000100&((data)<<8))
#define VI_DIDMA_ERR_err_yc(data)                                     (0x00000080&((data)<<7))
#define VI_DIDMA_ERR_err_cc(data)                                     (0x00000040&((data)<<6))
#define VI_DIDMA_ERR_err_fmc(data)                                    (0x00000020&((data)<<5))
#define VI_DIDMA_ERR_err_yp1(data)                                    (0x00000010&((data)<<4))
#define VI_DIDMA_ERR_err_yp2(data)                                    (0x00000008&((data)<<3))
#define VI_DIDMA_ERR_err_cp1(data)                                    (0x00000004&((data)<<2))
#define VI_DIDMA_ERR_err_cp2(data)                                    (0x00000002&((data)<<1))
#define VI_DIDMA_ERR_err_fmp(data)                                    (0x00000001&(data))
#define VI_DIDMA_ERR_get_err_yout(data)                               ((0x00000200&(data))>>9)
#define VI_DIDMA_ERR_get_err_cout(data)                               ((0x00000100&(data))>>8)
#define VI_DIDMA_ERR_get_err_yc(data)                                 ((0x00000080&(data))>>7)
#define VI_DIDMA_ERR_get_err_cc(data)                                 ((0x00000040&(data))>>6)
#define VI_DIDMA_ERR_get_err_fmc(data)                                ((0x00000020&(data))>>5)
#define VI_DIDMA_ERR_get_err_yp1(data)                                ((0x00000010&(data))>>4)
#define VI_DIDMA_ERR_get_err_yp2(data)                                ((0x00000008&(data))>>3)
#define VI_DIDMA_ERR_get_err_cp1(data)                                ((0x00000004&(data))>>2)
#define VI_DIDMA_ERR_get_err_cp2(data)                                ((0x00000002&(data))>>1)
#define VI_DIDMA_ERR_get_err_fmp(data)                                (0x00000001&(data))

#define VI_DIDMA_CTRL                                                 0x18004058
#define VI_DIDMA_CTRL_reg_addr                                        "0xB8004058"
#define VI_DIDMA_CTRL_reg                                             0xB8004058
#define VI_DIDMA_CTRL_inst_addr                                       "0x0016"
#define VI_DIDMA_CTRL_inst                                            0x0016
#define VI_DIDMA_CTRL_go_shift                                        (0)
#define VI_DIDMA_CTRL_go_mask                                         (0x00000001)
#define VI_DIDMA_CTRL_go(data)                                        (0x00000001&(data))
#define VI_DIDMA_CTRL_get_go(data)                                    (0x00000001&(data))

#define VI_DIMODE                                                     0x1800405C
#define VI_DIMODE_reg_addr                                            "0xB800405C"
#define VI_DIMODE_reg                                                 0xB800405C
#define VI_DIMODE_inst_addr                                           "0x0017"
#define VI_DIMODE_inst                                                0x0017
#define VI_DIMODE_write_enable2_shift                                 (12)
#define VI_DIMODE_topfield_shift                                      (11)
#define VI_DIMODE_write_enable4_shift                                 (10)
#define VI_DIMODE_chroma_shift                                        (9)
#define VI_DIMODE_write_enable3_shift                                 (8)
#define VI_DIMODE_sobel_shift                                         (7)
#define VI_DIMODE_write_enable2_shift                                 (6)
#define VI_DIMODE_fm_shift                                            (4)
#define VI_DIMODE_write_enable1_shift                                 (3)
#define VI_DIMODE_mode_shift                                          (0)
#define VI_DIMODE_write_enable2_mask                                  (0x00001000)
#define VI_DIMODE_topfield_mask                                       (0x00000800)
#define VI_DIMODE_write_enable4_mask                                  (0x00000400)
#define VI_DIMODE_chroma_mask                                         (0x00000200)
#define VI_DIMODE_write_enable3_mask                                  (0x00000100)
#define VI_DIMODE_sobel_mask                                          (0x00000080)
#define VI_DIMODE_write_enable2_mask                                  (0x00000040)
#define VI_DIMODE_fm_mask                                             (0x00000030)
#define VI_DIMODE_write_enable1_mask                                  (0x00000008)
#define VI_DIMODE_mode_mask                                           (0x00000007)
#define VI_DIMODE_write_enable2(data)                                 (0x00001000&((data)<<12))
#define VI_DIMODE_topfield(data)                                      (0x00000800&((data)<<11))
#define VI_DIMODE_write_enable4(data)                                 (0x00000400&((data)<<10))
#define VI_DIMODE_chroma(data)                                        (0x00000200&((data)<<9))
#define VI_DIMODE_write_enable3(data)                                 (0x00000100&((data)<<8))
#define VI_DIMODE_sobel(data)                                         (0x00000080&((data)<<7))
#define VI_DIMODE_write_enable2(data)                                 (0x00000040&((data)<<6))
#define VI_DIMODE_fm(data)                                            (0x00000030&((data)<<4))
#define VI_DIMODE_write_enable1(data)                                 (0x00000008&((data)<<3))
#define VI_DIMODE_mode(data)                                          (0x00000007&(data))
#define VI_DIMODE_get_write_enable2(data)                             ((0x00001000&(data))>>12)
#define VI_DIMODE_get_topfield(data)                                  ((0x00000800&(data))>>11)
#define VI_DIMODE_get_write_enable4(data)                             ((0x00000400&(data))>>10)
#define VI_DIMODE_get_chroma(data)                                    ((0x00000200&(data))>>9)
#define VI_DIMODE_get_write_enable3(data)                             ((0x00000100&(data))>>8)
#define VI_DIMODE_get_sobel(data)                                     ((0x00000080&(data))>>7)
#define VI_DIMODE_get_write_enable2(data)                             ((0x00000040&(data))>>6)
#define VI_DIMODE_get_fm(data)                                        ((0x00000030&(data))>>4)
#define VI_DIMODE_get_write_enable1(data)                             ((0x00000008&(data))>>3)
#define VI_DIMODE_get_mode(data)                                      (0x00000007&(data))

#define VI_Y1PICSET1                                                  0x18004060
#define VI_Y1PICSET1_reg_addr                                         "0xB8004060"
#define VI_Y1PICSET1_reg                                              0xB8004060
#define VI_Y1PICSET1_inst_addr                                        "0x0018"
#define VI_Y1PICSET1_inst                                             0x0018
#define VI_Y1PICSET1_write_enable1_shift                              (27)
#define VI_Y1PICSET1_wr_shift                                         (21)
#define VI_Y1PICSET1_write_enable2_shift                              (20)
#define VI_Y1PICSET1_cur_shift                                        (14)
#define VI_Y1PICSET1_write_enable3_shift                              (13)
#define VI_Y1PICSET1_pre_shift                                        (7)
#define VI_Y1PICSET1_write_enable4_shift                              (6)
#define VI_Y1PICSET1_nxt_shift                                        (0)
#define VI_Y1PICSET1_write_enable1_mask                               (0x08000000)
#define VI_Y1PICSET1_wr_mask                                          (0x07E00000)
#define VI_Y1PICSET1_write_enable2_mask                               (0x00100000)
#define VI_Y1PICSET1_cur_mask                                         (0x000FC000)
#define VI_Y1PICSET1_write_enable3_mask                               (0x00002000)
#define VI_Y1PICSET1_pre_mask                                         (0x00001F80)
#define VI_Y1PICSET1_write_enable4_mask                               (0x00000040)
#define VI_Y1PICSET1_nxt_mask                                         (0x0000003F)
#define VI_Y1PICSET1_write_enable1(data)                              (0x08000000&((data)<<27))
#define VI_Y1PICSET1_wr(data)                                         (0x07E00000&((data)<<21))
#define VI_Y1PICSET1_write_enable2(data)                              (0x00100000&((data)<<20))
#define VI_Y1PICSET1_cur(data)                                        (0x000FC000&((data)<<14))
#define VI_Y1PICSET1_write_enable3(data)                              (0x00002000&((data)<<13))
#define VI_Y1PICSET1_pre(data)                                        (0x00001F80&((data)<<7))
#define VI_Y1PICSET1_write_enable4(data)                              (0x00000040&((data)<<6))
#define VI_Y1PICSET1_nxt(data)                                        (0x0000003F&(data))
#define VI_Y1PICSET1_get_write_enable1(data)                          ((0x08000000&(data))>>27)
#define VI_Y1PICSET1_get_wr(data)                                     ((0x07E00000&(data))>>21)
#define VI_Y1PICSET1_get_write_enable2(data)                          ((0x00100000&(data))>>20)
#define VI_Y1PICSET1_get_cur(data)                                    ((0x000FC000&(data))>>14)
#define VI_Y1PICSET1_get_write_enable3(data)                          ((0x00002000&(data))>>13)
#define VI_Y1PICSET1_get_pre(data)                                    ((0x00001F80&(data))>>7)
#define VI_Y1PICSET1_get_write_enable4(data)                          ((0x00000040&(data))>>6)
#define VI_Y1PICSET1_get_nxt(data)                                    (0x0000003F&(data))

#define VI_Y1PICSET2                                                  0x18004064
#define VI_Y1PICSET2_reg_addr                                         "0xB8004064"
#define VI_Y1PICSET2_reg                                              0xB8004064
#define VI_Y1PICSET2_inst_addr                                        "0x0019"
#define VI_Y1PICSET2_inst                                             0x0019
#define VI_Y1PICSET2_write_enable1_shift                              (13)
#define VI_Y1PICSET2_pre2_shift                                       (7)
#define VI_Y1PICSET2_write_enable2_shift                              (6)
#define VI_Y1PICSET2_nxt2_shift                                       (0)
#define VI_Y1PICSET2_write_enable1_mask                               (0x00002000)
#define VI_Y1PICSET2_pre2_mask                                        (0x00001F80)
#define VI_Y1PICSET2_write_enable2_mask                               (0x00000040)
#define VI_Y1PICSET2_nxt2_mask                                        (0x0000003F)
#define VI_Y1PICSET2_write_enable1(data)                              (0x00002000&((data)<<13))
#define VI_Y1PICSET2_pre2(data)                                       (0x00001F80&((data)<<7))
#define VI_Y1PICSET2_write_enable2(data)                              (0x00000040&((data)<<6))
#define VI_Y1PICSET2_nxt2(data)                                       (0x0000003F&(data))
#define VI_Y1PICSET2_get_write_enable1(data)                          ((0x00002000&(data))>>13)
#define VI_Y1PICSET2_get_pre2(data)                                   ((0x00001F80&(data))>>7)
#define VI_Y1PICSET2_get_write_enable2(data)                          ((0x00000040&(data))>>6)
#define VI_Y1PICSET2_get_nxt2(data)                                   (0x0000003F&(data))

#define VI_C1PICSET1                                                  0x18004068
#define VI_C1PICSET1_reg_addr                                         "0xB8004068"
#define VI_C1PICSET1_reg                                              0xB8004068
#define VI_C1PICSET1_inst_addr                                        "0x001A"
#define VI_C1PICSET1_inst                                             0x001A
#define VI_C1PICSET1_write_enable1_shift                              (27)
#define VI_C1PICSET1_wr_shift                                         (21)
#define VI_C1PICSET1_write_enable2_shift                              (20)
#define VI_C1PICSET1_cur_shift                                        (14)
#define VI_C1PICSET1_write_enable3_shift                              (13)
#define VI_C1PICSET1_pre_shift                                        (7)
#define VI_C1PICSET1_write_enable4_shift                              (6)
#define VI_C1PICSET1_nxt_shift                                        (0)
#define VI_C1PICSET1_write_enable1_mask                               (0x08000000)
#define VI_C1PICSET1_wr_mask                                          (0x07E00000)
#define VI_C1PICSET1_write_enable2_mask                               (0x00100000)
#define VI_C1PICSET1_cur_mask                                         (0x000FC000)
#define VI_C1PICSET1_write_enable3_mask                               (0x00002000)
#define VI_C1PICSET1_pre_mask                                         (0x00001F80)
#define VI_C1PICSET1_write_enable4_mask                               (0x00000040)
#define VI_C1PICSET1_nxt_mask                                         (0x0000003F)
#define VI_C1PICSET1_write_enable1(data)                              (0x08000000&((data)<<27))
#define VI_C1PICSET1_wr(data)                                         (0x07E00000&((data)<<21))
#define VI_C1PICSET1_write_enable2(data)                              (0x00100000&((data)<<20))
#define VI_C1PICSET1_cur(data)                                        (0x000FC000&((data)<<14))
#define VI_C1PICSET1_write_enable3(data)                              (0x00002000&((data)<<13))
#define VI_C1PICSET1_pre(data)                                        (0x00001F80&((data)<<7))
#define VI_C1PICSET1_write_enable4(data)                              (0x00000040&((data)<<6))
#define VI_C1PICSET1_nxt(data)                                        (0x0000003F&(data))
#define VI_C1PICSET1_get_write_enable1(data)                          ((0x08000000&(data))>>27)
#define VI_C1PICSET1_get_wr(data)                                     ((0x07E00000&(data))>>21)
#define VI_C1PICSET1_get_write_enable2(data)                          ((0x00100000&(data))>>20)
#define VI_C1PICSET1_get_cur(data)                                    ((0x000FC000&(data))>>14)
#define VI_C1PICSET1_get_write_enable3(data)                          ((0x00002000&(data))>>13)
#define VI_C1PICSET1_get_pre(data)                                    ((0x00001F80&(data))>>7)
#define VI_C1PICSET1_get_write_enable4(data)                          ((0x00000040&(data))>>6)
#define VI_C1PICSET1_get_nxt(data)                                    (0x0000003F&(data))

#define VI_C1PICSET2                                                  0x1800406C
#define VI_C1PICSET2_reg_addr                                         "0xB800406C"
#define VI_C1PICSET2_reg                                              0xB800406C
#define VI_C1PICSET2_inst_addr                                        "0x001B"
#define VI_C1PICSET2_inst                                             0x001B
#define VI_C1PICSET2_write_enable1_shift                              (13)
#define VI_C1PICSET2_pre2_shift                                       (7)
#define VI_C1PICSET2_write_enable2_shift                              (6)
#define VI_C1PICSET2_nxt2_shift                                       (0)
#define VI_C1PICSET2_write_enable1_mask                               (0x00002000)
#define VI_C1PICSET2_pre2_mask                                        (0x00001F80)
#define VI_C1PICSET2_write_enable2_mask                               (0x00000040)
#define VI_C1PICSET2_nxt2_mask                                        (0x0000003F)
#define VI_C1PICSET2_write_enable1(data)                              (0x00002000&((data)<<13))
#define VI_C1PICSET2_pre2(data)                                       (0x00001F80&((data)<<7))
#define VI_C1PICSET2_write_enable2(data)                              (0x00000040&((data)<<6))
#define VI_C1PICSET2_nxt2(data)                                       (0x0000003F&(data))
#define VI_C1PICSET2_get_write_enable1(data)                          ((0x00002000&(data))>>13)
#define VI_C1PICSET2_get_pre2(data)                                   ((0x00001F80&(data))>>7)
#define VI_C1PICSET2_get_write_enable2(data)                          ((0x00000040&(data))>>6)
#define VI_C1PICSET2_get_nxt2(data)                                   (0x0000003F&(data))

#define VI_SOBEL                                                      0x18004070
#define VI_SOBEL_reg_addr                                             "0xB8004070"
#define VI_SOBEL_reg                                                  0xB8004070
#define VI_SOBEL_inst_addr                                            "0x001C"
#define VI_SOBEL_inst                                                 0x001C
#define VI_SOBEL_write_enable2_shift                                  (21)
#define VI_SOBEL_h_shift                                              (11)
#define VI_SOBEL_write_enable1_shift                                  (10)
#define VI_SOBEL_v_shift                                              (0)
#define VI_SOBEL_write_enable2_mask                                   (0x00200000)
#define VI_SOBEL_h_mask                                               (0x001FF800)
#define VI_SOBEL_write_enable1_mask                                   (0x00000400)
#define VI_SOBEL_v_mask                                               (0x000003FF)
#define VI_SOBEL_write_enable2(data)                                  (0x00200000&((data)<<21))
#define VI_SOBEL_h(data)                                              (0x001FF800&((data)<<11))
#define VI_SOBEL_write_enable1(data)                                  (0x00000400&((data)<<10))
#define VI_SOBEL_v(data)                                              (0x000003FF&(data))
#define VI_SOBEL_get_write_enable2(data)                              ((0x00200000&(data))>>21)
#define VI_SOBEL_get_h(data)                                          ((0x001FF800&(data))>>11)
#define VI_SOBEL_get_write_enable1(data)                              ((0x00000400&(data))>>10)
#define VI_SOBEL_get_v(data)                                          (0x000003FF&(data))

#define VI_CLASSIFY                                                   0x18004074
#define VI_CLASSIFY_reg_addr                                          "0xB8004074"
#define VI_CLASSIFY_reg                                               0xB8004074
#define VI_CLASSIFY_inst_addr                                         "0x001D"
#define VI_CLASSIFY_inst                                              0x001D
#define VI_CLASSIFY_write_enable3_shift                               (17)
#define VI_CLASSIFY_th3_shift                                         (12)
#define VI_CLASSIFY_write_enable2_shift                               (11)
#define VI_CLASSIFY_th2_shift                                         (6)
#define VI_CLASSIFY_write_enable1_shift                               (5)
#define VI_CLASSIFY_th1_shift                                         (0)
#define VI_CLASSIFY_write_enable3_mask                                (0x00020000)
#define VI_CLASSIFY_th3_mask                                          (0x0001F000)
#define VI_CLASSIFY_write_enable2_mask                                (0x00000800)
#define VI_CLASSIFY_th2_mask                                          (0x000007C0)
#define VI_CLASSIFY_write_enable1_mask                                (0x00000020)
#define VI_CLASSIFY_th1_mask                                          (0x0000001F)
#define VI_CLASSIFY_write_enable3(data)                               (0x00020000&((data)<<17))
#define VI_CLASSIFY_th3(data)                                         (0x0001F000&((data)<<12))
#define VI_CLASSIFY_write_enable2(data)                               (0x00000800&((data)<<11))
#define VI_CLASSIFY_th2(data)                                         (0x000007C0&((data)<<6))
#define VI_CLASSIFY_write_enable1(data)                               (0x00000020&((data)<<5))
#define VI_CLASSIFY_th1(data)                                         (0x0000001F&(data))
#define VI_CLASSIFY_get_write_enable3(data)                           ((0x00020000&(data))>>17)
#define VI_CLASSIFY_get_th3(data)                                     ((0x0001F000&(data))>>12)
#define VI_CLASSIFY_get_write_enable2(data)                           ((0x00000800&(data))>>11)
#define VI_CLASSIFY_get_th2(data)                                     ((0x000007C0&(data))>>6)
#define VI_CLASSIFY_get_write_enable1(data)                           ((0x00000020&(data))>>5)
#define VI_CLASSIFY_get_th1(data)                                     (0x0000001F&(data))

#define VI_FRAME_S                                                    0x18004078
#define VI_FRAME_S_reg_addr                                           "0xB8004078"
#define VI_FRAME_S_reg                                                0xB8004078
#define VI_FRAME_S_inst_addr                                          "0x001E"
#define VI_FRAME_S_inst                                               0x001E
#define VI_FRAME_S_write_enable3_shift                                (26)
#define VI_FRAME_S_th3_shift                                          (18)
#define VI_FRAME_S_write_enable2_shift                                (17)
#define VI_FRAME_S_th2_shift                                          (9)
#define VI_FRAME_S_write_enable1_shift                                (8)
#define VI_FRAME_S_th1_shift                                          (0)
#define VI_FRAME_S_write_enable3_mask                                 (0x04000000)
#define VI_FRAME_S_th3_mask                                           (0x03FC0000)
#define VI_FRAME_S_write_enable2_mask                                 (0x00020000)
#define VI_FRAME_S_th2_mask                                           (0x0001FE00)
#define VI_FRAME_S_write_enable1_mask                                 (0x00000100)
#define VI_FRAME_S_th1_mask                                           (0x000000FF)
#define VI_FRAME_S_write_enable3(data)                                (0x04000000&((data)<<26))
#define VI_FRAME_S_th3(data)                                          (0x03FC0000&((data)<<18))
#define VI_FRAME_S_write_enable2(data)                                (0x00020000&((data)<<17))
#define VI_FRAME_S_th2(data)                                          (0x0001FE00&((data)<<9))
#define VI_FRAME_S_write_enable1(data)                                (0x00000100&((data)<<8))
#define VI_FRAME_S_th1(data)                                          (0x000000FF&(data))
#define VI_FRAME_S_get_write_enable3(data)                            ((0x04000000&(data))>>26)
#define VI_FRAME_S_get_th3(data)                                      ((0x03FC0000&(data))>>18)
#define VI_FRAME_S_get_write_enable2(data)                            ((0x00020000&(data))>>17)
#define VI_FRAME_S_get_th2(data)                                      ((0x0001FE00&(data))>>9)
#define VI_FRAME_S_get_write_enable1(data)                            ((0x00000100&(data))>>8)
#define VI_FRAME_S_get_th1(data)                                      (0x000000FF&(data))

#define VI_FRAME_RLV                                                  0x1800407C
#define VI_FRAME_RLV_reg_addr                                         "0xB800407C"
#define VI_FRAME_RLV_reg                                              0xB800407C
#define VI_FRAME_RLV_inst_addr                                        "0x001F"
#define VI_FRAME_RLV_inst                                             0x001F
#define VI_FRAME_RLV_write_enable3_shift                              (26)
#define VI_FRAME_RLV_th3_shift                                        (18)
#define VI_FRAME_RLV_write_enable2_shift                              (17)
#define VI_FRAME_RLV_th2_shift                                        (9)
#define VI_FRAME_RLV_write_enable1_shift                              (8)
#define VI_FRAME_RLV_th1_shift                                        (0)
#define VI_FRAME_RLV_write_enable3_mask                               (0x04000000)
#define VI_FRAME_RLV_th3_mask                                         (0x03FC0000)
#define VI_FRAME_RLV_write_enable2_mask                               (0x00020000)
#define VI_FRAME_RLV_th2_mask                                         (0x0001FE00)
#define VI_FRAME_RLV_write_enable1_mask                               (0x00000100)
#define VI_FRAME_RLV_th1_mask                                         (0x000000FF)
#define VI_FRAME_RLV_write_enable3(data)                              (0x04000000&((data)<<26))
#define VI_FRAME_RLV_th3(data)                                        (0x03FC0000&((data)<<18))
#define VI_FRAME_RLV_write_enable2(data)                              (0x00020000&((data)<<17))
#define VI_FRAME_RLV_th2(data)                                        (0x0001FE00&((data)<<9))
#define VI_FRAME_RLV_write_enable1(data)                              (0x00000100&((data)<<8))
#define VI_FRAME_RLV_th1(data)                                        (0x000000FF&(data))
#define VI_FRAME_RLV_get_write_enable3(data)                          ((0x04000000&(data))>>26)
#define VI_FRAME_RLV_get_th3(data)                                    ((0x03FC0000&(data))>>18)
#define VI_FRAME_RLV_get_write_enable2(data)                          ((0x00020000&(data))>>17)
#define VI_FRAME_RLV_get_th2(data)                                    ((0x0001FE00&(data))>>9)
#define VI_FRAME_RLV_get_write_enable1(data)                          ((0x00000100&(data))>>8)
#define VI_FRAME_RLV_get_th1(data)                                    (0x000000FF&(data))

#define VI_FRAME_H                                                    0x18004080
#define VI_FRAME_H_reg_addr                                           "0xB8004080"
#define VI_FRAME_H_reg                                                0xB8004080
#define VI_FRAME_H_inst_addr                                          "0x0020"
#define VI_FRAME_H_inst                                               0x0020
#define VI_FRAME_H_write_enable3_shift                                (26)
#define VI_FRAME_H_th3_shift                                          (18)
#define VI_FRAME_H_write_enable2_shift                                (17)
#define VI_FRAME_H_th2_shift                                          (9)
#define VI_FRAME_H_write_enable1_shift                                (8)
#define VI_FRAME_H_th1_shift                                          (0)
#define VI_FRAME_H_write_enable3_mask                                 (0x04000000)
#define VI_FRAME_H_th3_mask                                           (0x03FC0000)
#define VI_FRAME_H_write_enable2_mask                                 (0x00020000)
#define VI_FRAME_H_th2_mask                                           (0x0001FE00)
#define VI_FRAME_H_write_enable1_mask                                 (0x00000100)
#define VI_FRAME_H_th1_mask                                           (0x000000FF)
#define VI_FRAME_H_write_enable3(data)                                (0x04000000&((data)<<26))
#define VI_FRAME_H_th3(data)                                          (0x03FC0000&((data)<<18))
#define VI_FRAME_H_write_enable2(data)                                (0x00020000&((data)<<17))
#define VI_FRAME_H_th2(data)                                          (0x0001FE00&((data)<<9))
#define VI_FRAME_H_write_enable1(data)                                (0x00000100&((data)<<8))
#define VI_FRAME_H_th1(data)                                          (0x000000FF&(data))
#define VI_FRAME_H_get_write_enable3(data)                            ((0x04000000&(data))>>26)
#define VI_FRAME_H_get_th3(data)                                      ((0x03FC0000&(data))>>18)
#define VI_FRAME_H_get_write_enable2(data)                            ((0x00020000&(data))>>17)
#define VI_FRAME_H_get_th2(data)                                      ((0x0001FE00&(data))>>9)
#define VI_FRAME_H_get_write_enable1(data)                            ((0x00000100&(data))>>8)
#define VI_FRAME_H_get_th1(data)                                      (0x000000FF&(data))

#define VI_FRAME_M                                                    0x18004084
#define VI_FRAME_M_reg_addr                                           "0xB8004084"
#define VI_FRAME_M_reg                                                0xB8004084
#define VI_FRAME_M_inst_addr                                          "0x0021"
#define VI_FRAME_M_inst                                               0x0021
#define VI_FRAME_M_write_enable3_shift                                (26)
#define VI_FRAME_M_th3_shift                                          (18)
#define VI_FRAME_M_write_enable2_shift                                (17)
#define VI_FRAME_M_th2_shift                                          (9)
#define VI_FRAME_M_write_enable1_shift                                (8)
#define VI_FRAME_M_th1_shift                                          (0)
#define VI_FRAME_M_write_enable3_mask                                 (0x04000000)
#define VI_FRAME_M_th3_mask                                           (0x03FC0000)
#define VI_FRAME_M_write_enable2_mask                                 (0x00020000)
#define VI_FRAME_M_th2_mask                                           (0x0001FE00)
#define VI_FRAME_M_write_enable1_mask                                 (0x00000100)
#define VI_FRAME_M_th1_mask                                           (0x000000FF)
#define VI_FRAME_M_write_enable3(data)                                (0x04000000&((data)<<26))
#define VI_FRAME_M_th3(data)                                          (0x03FC0000&((data)<<18))
#define VI_FRAME_M_write_enable2(data)                                (0x00020000&((data)<<17))
#define VI_FRAME_M_th2(data)                                          (0x0001FE00&((data)<<9))
#define VI_FRAME_M_write_enable1(data)                                (0x00000100&((data)<<8))
#define VI_FRAME_M_th1(data)                                          (0x000000FF&(data))
#define VI_FRAME_M_get_write_enable3(data)                            ((0x04000000&(data))>>26)
#define VI_FRAME_M_get_th3(data)                                      ((0x03FC0000&(data))>>18)
#define VI_FRAME_M_get_write_enable2(data)                            ((0x00020000&(data))>>17)
#define VI_FRAME_M_get_th2(data)                                      ((0x0001FE00&(data))>>9)
#define VI_FRAME_M_get_write_enable1(data)                            ((0x00000100&(data))>>8)
#define VI_FRAME_M_get_th1(data)                                      (0x000000FF&(data))

#define VI_FRAMEC_S                                                   0x18004088
#define VI_FRAMEC_S_reg_addr                                          "0xB8004088"
#define VI_FRAMEC_S_reg                                               0xB8004088
#define VI_FRAMEC_S_inst_addr                                         "0x0022"
#define VI_FRAMEC_S_inst                                              0x0022
#define VI_FRAMEC_S_write_enable3_shift                               (26)
#define VI_FRAMEC_S_th3_shift                                         (18)
#define VI_FRAMEC_S_write_enable2_shift                               (17)
#define VI_FRAMEC_S_th2_shift                                         (9)
#define VI_FRAMEC_S_write_enable1_shift                               (8)
#define VI_FRAMEC_S_th1_shift                                         (0)
#define VI_FRAMEC_S_write_enable3_mask                                (0x04000000)
#define VI_FRAMEC_S_th3_mask                                          (0x03FC0000)
#define VI_FRAMEC_S_write_enable2_mask                                (0x00020000)
#define VI_FRAMEC_S_th2_mask                                          (0x0001FE00)
#define VI_FRAMEC_S_write_enable1_mask                                (0x00000100)
#define VI_FRAMEC_S_th1_mask                                          (0x000000FF)
#define VI_FRAMEC_S_write_enable3(data)                               (0x04000000&((data)<<26))
#define VI_FRAMEC_S_th3(data)                                         (0x03FC0000&((data)<<18))
#define VI_FRAMEC_S_write_enable2(data)                               (0x00020000&((data)<<17))
#define VI_FRAMEC_S_th2(data)                                         (0x0001FE00&((data)<<9))
#define VI_FRAMEC_S_write_enable1(data)                               (0x00000100&((data)<<8))
#define VI_FRAMEC_S_th1(data)                                         (0x000000FF&(data))
#define VI_FRAMEC_S_get_write_enable3(data)                           ((0x04000000&(data))>>26)
#define VI_FRAMEC_S_get_th3(data)                                     ((0x03FC0000&(data))>>18)
#define VI_FRAMEC_S_get_write_enable2(data)                           ((0x00020000&(data))>>17)
#define VI_FRAMEC_S_get_th2(data)                                     ((0x0001FE00&(data))>>9)
#define VI_FRAMEC_S_get_write_enable1(data)                           ((0x00000100&(data))>>8)
#define VI_FRAMEC_S_get_th1(data)                                     (0x000000FF&(data))

#define VI_FRAMEC_RLV                                                 0x1800408C
#define VI_FRAMEC_RLV_reg_addr                                        "0xB800408C"
#define VI_FRAMEC_RLV_reg                                             0xB800408C
#define VI_FRAMEC_RLV_inst_addr                                       "0x0023"
#define VI_FRAMEC_RLV_inst                                            0x0023
#define VI_FRAMEC_RLV_write_enable3_shift                             (26)
#define VI_FRAMEC_RLV_th3_shift                                       (18)
#define VI_FRAMEC_RLV_write_enable2_shift                             (17)
#define VI_FRAMEC_RLV_th2_shift                                       (9)
#define VI_FRAMEC_RLV_write_enable1_shift                             (8)
#define VI_FRAMEC_RLV_th1_shift                                       (0)
#define VI_FRAMEC_RLV_write_enable3_mask                              (0x04000000)
#define VI_FRAMEC_RLV_th3_mask                                        (0x03FC0000)
#define VI_FRAMEC_RLV_write_enable2_mask                              (0x00020000)
#define VI_FRAMEC_RLV_th2_mask                                        (0x0001FE00)
#define VI_FRAMEC_RLV_write_enable1_mask                              (0x00000100)
#define VI_FRAMEC_RLV_th1_mask                                        (0x000000FF)
#define VI_FRAMEC_RLV_write_enable3(data)                             (0x04000000&((data)<<26))
#define VI_FRAMEC_RLV_th3(data)                                       (0x03FC0000&((data)<<18))
#define VI_FRAMEC_RLV_write_enable2(data)                             (0x00020000&((data)<<17))
#define VI_FRAMEC_RLV_th2(data)                                       (0x0001FE00&((data)<<9))
#define VI_FRAMEC_RLV_write_enable1(data)                             (0x00000100&((data)<<8))
#define VI_FRAMEC_RLV_th1(data)                                       (0x000000FF&(data))
#define VI_FRAMEC_RLV_get_write_enable3(data)                         ((0x04000000&(data))>>26)
#define VI_FRAMEC_RLV_get_th3(data)                                   ((0x03FC0000&(data))>>18)
#define VI_FRAMEC_RLV_get_write_enable2(data)                         ((0x00020000&(data))>>17)
#define VI_FRAMEC_RLV_get_th2(data)                                   ((0x0001FE00&(data))>>9)
#define VI_FRAMEC_RLV_get_write_enable1(data)                         ((0x00000100&(data))>>8)
#define VI_FRAMEC_RLV_get_th1(data)                                   (0x000000FF&(data))

#define VI_FRAMEC_H                                                   0x18004090
#define VI_FRAMEC_H_reg_addr                                          "0xB8004090"
#define VI_FRAMEC_H_reg                                               0xB8004090
#define VI_FRAMEC_H_inst_addr                                         "0x0024"
#define VI_FRAMEC_H_inst                                              0x0024
#define VI_FRAMEC_H_write_enable3_shift                               (26)
#define VI_FRAMEC_H_th3_shift                                         (18)
#define VI_FRAMEC_H_write_enable2_shift                               (17)
#define VI_FRAMEC_H_th2_shift                                         (9)
#define VI_FRAMEC_H_write_enable1_shift                               (8)
#define VI_FRAMEC_H_th1_shift                                         (0)
#define VI_FRAMEC_H_write_enable3_mask                                (0x04000000)
#define VI_FRAMEC_H_th3_mask                                          (0x03FC0000)
#define VI_FRAMEC_H_write_enable2_mask                                (0x00020000)
#define VI_FRAMEC_H_th2_mask                                          (0x0001FE00)
#define VI_FRAMEC_H_write_enable1_mask                                (0x00000100)
#define VI_FRAMEC_H_th1_mask                                          (0x000000FF)
#define VI_FRAMEC_H_write_enable3(data)                               (0x04000000&((data)<<26))
#define VI_FRAMEC_H_th3(data)                                         (0x03FC0000&((data)<<18))
#define VI_FRAMEC_H_write_enable2(data)                               (0x00020000&((data)<<17))
#define VI_FRAMEC_H_th2(data)                                         (0x0001FE00&((data)<<9))
#define VI_FRAMEC_H_write_enable1(data)                               (0x00000100&((data)<<8))
#define VI_FRAMEC_H_th1(data)                                         (0x000000FF&(data))
#define VI_FRAMEC_H_get_write_enable3(data)                           ((0x04000000&(data))>>26)
#define VI_FRAMEC_H_get_th3(data)                                     ((0x03FC0000&(data))>>18)
#define VI_FRAMEC_H_get_write_enable2(data)                           ((0x00020000&(data))>>17)
#define VI_FRAMEC_H_get_th2(data)                                     ((0x0001FE00&(data))>>9)
#define VI_FRAMEC_H_get_write_enable1(data)                           ((0x00000100&(data))>>8)
#define VI_FRAMEC_H_get_th1(data)                                     (0x000000FF&(data))

#define VI_FRAMEC_M                                                   0x18004094
#define VI_FRAMEC_M_reg_addr                                          "0xB8004094"
#define VI_FRAMEC_M_reg                                               0xB8004094
#define VI_FRAMEC_M_inst_addr                                         "0x0025"
#define VI_FRAMEC_M_inst                                              0x0025
#define VI_FRAMEC_M_write_enable3_shift                               (26)
#define VI_FRAMEC_M_th3_shift                                         (18)
#define VI_FRAMEC_M_write_enable2_shift                               (17)
#define VI_FRAMEC_M_th2_shift                                         (9)
#define VI_FRAMEC_M_write_enable1_shift                               (8)
#define VI_FRAMEC_M_th1_shift                                         (0)
#define VI_FRAMEC_M_write_enable3_mask                                (0x04000000)
#define VI_FRAMEC_M_th3_mask                                          (0x03FC0000)
#define VI_FRAMEC_M_write_enable2_mask                                (0x00020000)
#define VI_FRAMEC_M_th2_mask                                          (0x0001FE00)
#define VI_FRAMEC_M_write_enable1_mask                                (0x00000100)
#define VI_FRAMEC_M_th1_mask                                          (0x000000FF)
#define VI_FRAMEC_M_write_enable3(data)                               (0x04000000&((data)<<26))
#define VI_FRAMEC_M_th3(data)                                         (0x03FC0000&((data)<<18))
#define VI_FRAMEC_M_write_enable2(data)                               (0x00020000&((data)<<17))
#define VI_FRAMEC_M_th2(data)                                         (0x0001FE00&((data)<<9))
#define VI_FRAMEC_M_write_enable1(data)                               (0x00000100&((data)<<8))
#define VI_FRAMEC_M_th1(data)                                         (0x000000FF&(data))
#define VI_FRAMEC_M_get_write_enable3(data)                           ((0x04000000&(data))>>26)
#define VI_FRAMEC_M_get_th3(data)                                     ((0x03FC0000&(data))>>18)
#define VI_FRAMEC_M_get_write_enable2(data)                           ((0x00020000&(data))>>17)
#define VI_FRAMEC_M_get_th2(data)                                     ((0x0001FE00&(data))>>9)
#define VI_FRAMEC_M_get_write_enable1(data)                           ((0x00000100&(data))>>8)
#define VI_FRAMEC_M_get_th1(data)                                     (0x000000FF&(data))

#define VI_FIELD_SRLV                                                 0x18004098
#define VI_FIELD_SRLV_reg_addr                                        "0xB8004098"
#define VI_FIELD_SRLV_reg                                             0xB8004098
#define VI_FIELD_SRLV_inst_addr                                       "0x0026"
#define VI_FIELD_SRLV_inst                                            0x0026
#define VI_FIELD_SRLV_write_enable3_shift                             (26)
#define VI_FIELD_SRLV_th3_shift                                       (18)
#define VI_FIELD_SRLV_write_enable2_shift                             (17)
#define VI_FIELD_SRLV_th2_shift                                       (9)
#define VI_FIELD_SRLV_write_enable1_shift                             (8)
#define VI_FIELD_SRLV_th1_shift                                       (0)
#define VI_FIELD_SRLV_write_enable3_mask                              (0x04000000)
#define VI_FIELD_SRLV_th3_mask                                        (0x03FC0000)
#define VI_FIELD_SRLV_write_enable2_mask                              (0x00020000)
#define VI_FIELD_SRLV_th2_mask                                        (0x0001FE00)
#define VI_FIELD_SRLV_write_enable1_mask                              (0x00000100)
#define VI_FIELD_SRLV_th1_mask                                        (0x000000FF)
#define VI_FIELD_SRLV_write_enable3(data)                             (0x04000000&((data)<<26))
#define VI_FIELD_SRLV_th3(data)                                       (0x03FC0000&((data)<<18))
#define VI_FIELD_SRLV_write_enable2(data)                             (0x00020000&((data)<<17))
#define VI_FIELD_SRLV_th2(data)                                       (0x0001FE00&((data)<<9))
#define VI_FIELD_SRLV_write_enable1(data)                             (0x00000100&((data)<<8))
#define VI_FIELD_SRLV_th1(data)                                       (0x000000FF&(data))
#define VI_FIELD_SRLV_get_write_enable3(data)                         ((0x04000000&(data))>>26)
#define VI_FIELD_SRLV_get_th3(data)                                   ((0x03FC0000&(data))>>18)
#define VI_FIELD_SRLV_get_write_enable2(data)                         ((0x00020000&(data))>>17)
#define VI_FIELD_SRLV_get_th2(data)                                   ((0x0001FE00&(data))>>9)
#define VI_FIELD_SRLV_get_write_enable1(data)                         ((0x00000100&(data))>>8)
#define VI_FIELD_SRLV_get_th1(data)                                   (0x000000FF&(data))

#define VI_FIELD_HM                                                   0x1800409C
#define VI_FIELD_HM_reg_addr                                          "0xB800409C"
#define VI_FIELD_HM_reg                                               0xB800409C
#define VI_FIELD_HM_inst_addr                                         "0x0027"
#define VI_FIELD_HM_inst                                              0x0027
#define VI_FIELD_HM_write_enable3_shift                               (26)
#define VI_FIELD_HM_th3_shift                                         (18)
#define VI_FIELD_HM_write_enable2_shift                               (17)
#define VI_FIELD_HM_th2_shift                                         (9)
#define VI_FIELD_HM_write_enable1_shift                               (8)
#define VI_FIELD_HM_th1_shift                                         (0)
#define VI_FIELD_HM_write_enable3_mask                                (0x04000000)
#define VI_FIELD_HM_th3_mask                                          (0x03FC0000)
#define VI_FIELD_HM_write_enable2_mask                                (0x00020000)
#define VI_FIELD_HM_th2_mask                                          (0x0001FE00)
#define VI_FIELD_HM_write_enable1_mask                                (0x00000100)
#define VI_FIELD_HM_th1_mask                                          (0x000000FF)
#define VI_FIELD_HM_write_enable3(data)                               (0x04000000&((data)<<26))
#define VI_FIELD_HM_th3(data)                                         (0x03FC0000&((data)<<18))
#define VI_FIELD_HM_write_enable2(data)                               (0x00020000&((data)<<17))
#define VI_FIELD_HM_th2(data)                                         (0x0001FE00&((data)<<9))
#define VI_FIELD_HM_write_enable1(data)                               (0x00000100&((data)<<8))
#define VI_FIELD_HM_th1(data)                                         (0x000000FF&(data))
#define VI_FIELD_HM_get_write_enable3(data)                           ((0x04000000&(data))>>26)
#define VI_FIELD_HM_get_th3(data)                                     ((0x03FC0000&(data))>>18)
#define VI_FIELD_HM_get_write_enable2(data)                           ((0x00020000&(data))>>17)
#define VI_FIELD_HM_get_th2(data)                                     ((0x0001FE00&(data))>>9)
#define VI_FIELD_HM_get_write_enable1(data)                           ((0x00000100&(data))>>8)
#define VI_FIELD_HM_get_th1(data)                                     (0x000000FF&(data))

#define VI_FRAME                                                      0x180040A0
#define VI_FRAME_reg_addr                                             "0xB80040A0"
#define VI_FRAME_reg                                                  0xB80040A0
#define VI_FRAME_inst_addr                                            "0x0028"
#define VI_FRAME_inst                                                 0x0028
#define VI_FRAME_write_enable1_shift                                  (8)
#define VI_FRAME_th_shift                                             (0)
#define VI_FRAME_write_enable1_mask                                   (0x00000100)
#define VI_FRAME_th_mask                                              (0x000000FF)
#define VI_FRAME_write_enable1(data)                                  (0x00000100&((data)<<8))
#define VI_FRAME_th(data)                                             (0x000000FF&(data))
#define VI_FRAME_get_write_enable1(data)                              ((0x00000100&(data))>>8)
#define VI_FRAME_get_th(data)                                         (0x000000FF&(data))

#define VI_FIELD                                                      0x180040A4
#define VI_FIELD_reg_addr                                             "0xB80040A4"
#define VI_FIELD_reg                                                  0xB80040A4
#define VI_FIELD_inst_addr                                            "0x0029"
#define VI_FIELD_inst                                                 0x0029
#define VI_FIELD_write_enable3_shift                                  (26)
#define VI_FIELD_still_shift                                          (18)
#define VI_FIELD_write_enable2_shift                                  (17)
#define VI_FIELD_var_shift                                            (9)
#define VI_FIELD_write_enable1_shift                                  (8)
#define VI_FIELD_th_shift                                             (0)
#define VI_FIELD_write_enable3_mask                                   (0x04000000)
#define VI_FIELD_still_mask                                           (0x03FC0000)
#define VI_FIELD_write_enable2_mask                                   (0x00020000)
#define VI_FIELD_var_mask                                             (0x0001FE00)
#define VI_FIELD_write_enable1_mask                                   (0x00000100)
#define VI_FIELD_th_mask                                              (0x000000FF)
#define VI_FIELD_write_enable3(data)                                  (0x04000000&((data)<<26))
#define VI_FIELD_still(data)                                          (0x03FC0000&((data)<<18))
#define VI_FIELD_write_enable2(data)                                  (0x00020000&((data)<<17))
#define VI_FIELD_var(data)                                            (0x0001FE00&((data)<<9))
#define VI_FIELD_write_enable1(data)                                  (0x00000100&((data)<<8))
#define VI_FIELD_th(data)                                             (0x000000FF&(data))
#define VI_FIELD_get_write_enable3(data)                              ((0x04000000&(data))>>26)
#define VI_FIELD_get_still(data)                                      ((0x03FC0000&(data))>>18)
#define VI_FIELD_get_write_enable2(data)                              ((0x00020000&(data))>>17)
#define VI_FIELD_get_var(data)                                        ((0x0001FE00&(data))>>9)
#define VI_FIELD_get_write_enable1(data)                              ((0x00000100&(data))>>8)
#define VI_FIELD_get_th(data)                                         (0x000000FF&(data))

#define VI_BLEND1                                                     0x180040A8
#define VI_BLEND1_reg_addr                                            "0xB80040A8"
#define VI_BLEND1_reg                                                 0xB80040A8
#define VI_BLEND1_inst_addr                                           "0x002A"
#define VI_BLEND1_inst                                                0x002A
#define VI_BLEND1_write_enable2_shift                                 (12)
#define VI_BLEND1_th2_shift                                           (9)
#define VI_BLEND1_write_enable1_shift                                 (8)
#define VI_BLEND1_th1_shift                                           (0)
#define VI_BLEND1_write_enable2_mask                                  (0x00001000)
#define VI_BLEND1_th2_mask                                            (0x00000E00)
#define VI_BLEND1_write_enable1_mask                                  (0x00000100)
#define VI_BLEND1_th1_mask                                            (0x000000FF)
#define VI_BLEND1_write_enable2(data)                                 (0x00001000&((data)<<12))
#define VI_BLEND1_th2(data)                                           (0x00000E00&((data)<<9))
#define VI_BLEND1_write_enable1(data)                                 (0x00000100&((data)<<8))
#define VI_BLEND1_th1(data)                                           (0x000000FF&(data))
#define VI_BLEND1_get_write_enable2(data)                             ((0x00001000&(data))>>12)
#define VI_BLEND1_get_th2(data)                                       ((0x00000E00&(data))>>9)
#define VI_BLEND1_get_write_enable1(data)                             ((0x00000100&(data))>>8)
#define VI_BLEND1_get_th1(data)                                       (0x000000FF&(data))

#define VI_BLEND2                                                     0x180040AC
#define VI_BLEND2_reg_addr                                            "0xB80040AC"
#define VI_BLEND2_reg                                                 0xB80040AC
#define VI_BLEND2_inst_addr                                           "0x002B"
#define VI_BLEND2_inst                                                0x002B
#define VI_BLEND2_write_enable2_shift                                 (12)
#define VI_BLEND2_th2_shift                                           (9)
#define VI_BLEND2_write_enable1_shift                                 (8)
#define VI_BLEND2_th1_shift                                           (0)
#define VI_BLEND2_write_enable2_mask                                  (0x00001000)
#define VI_BLEND2_th2_mask                                            (0x00000E00)
#define VI_BLEND2_write_enable1_mask                                  (0x00000100)
#define VI_BLEND2_th1_mask                                            (0x000000FF)
#define VI_BLEND2_write_enable2(data)                                 (0x00001000&((data)<<12))
#define VI_BLEND2_th2(data)                                           (0x00000E00&((data)<<9))
#define VI_BLEND2_write_enable1(data)                                 (0x00000100&((data)<<8))
#define VI_BLEND2_th1(data)                                           (0x000000FF&(data))
#define VI_BLEND2_get_write_enable2(data)                             ((0x00001000&(data))>>12)
#define VI_BLEND2_get_th2(data)                                       ((0x00000E00&(data))>>9)
#define VI_BLEND2_get_write_enable1(data)                             ((0x00000100&(data))>>8)
#define VI_BLEND2_get_th1(data)                                       (0x000000FF&(data))

#define VI_SMOOTH                                                     0x180040B0
#define VI_SMOOTH_reg_addr                                            "0xB80040B0"
#define VI_SMOOTH_reg                                                 0xB80040B0
#define VI_SMOOTH_inst_addr                                           "0x002C"
#define VI_SMOOTH_inst                                                0x002C
#define VI_SMOOTH_th_shift                                            (0)
#define VI_SMOOTH_th_mask                                             (0x000000FF)
#define VI_SMOOTH_th(data)                                            (0x000000FF&(data))
#define VI_SMOOTH_get_th(data)                                        (0x000000FF&(data))

#define VI_OPTION                                                     0x180040B4
#define VI_OPTION_reg_addr                                            "0xB80040B4"
#define VI_OPTION_reg                                                 0xB80040B4
#define VI_OPTION_inst_addr                                           "0x002D"
#define VI_OPTION_inst                                                0x002D
#define VI_OPTION_write_enable2_shift                                 (3)
#define VI_OPTION_inter_shift                                         (2)
#define VI_OPTION_write_enable1_shift                                 (1)
#define VI_OPTION_sobel_shift                                         (0)
#define VI_OPTION_write_enable2_mask                                  (0x00000008)
#define VI_OPTION_inter_mask                                          (0x00000004)
#define VI_OPTION_write_enable1_mask                                  (0x00000002)
#define VI_OPTION_sobel_mask                                          (0x00000001)
#define VI_OPTION_write_enable2(data)                                 (0x00000008&((data)<<3))
#define VI_OPTION_inter(data)                                         (0x00000004&((data)<<2))
#define VI_OPTION_write_enable1(data)                                 (0x00000002&((data)<<1))
#define VI_OPTION_sobel(data)                                         (0x00000001&(data))
#define VI_OPTION_get_write_enable2(data)                             ((0x00000008&(data))>>3)
#define VI_OPTION_get_inter(data)                                     ((0x00000004&(data))>>2)
#define VI_OPTION_get_write_enable1(data)                             ((0x00000002&(data))>>1)
#define VI_OPTION_get_sobel(data)                                     (0x00000001&(data))

#define VI_WEIGHT                                                     0x180040B8
#define VI_WEIGHT_reg_addr                                            "0xB80040B8"
#define VI_WEIGHT_reg                                                 0xB80040B8
#define VI_WEIGHT_inst_addr                                           "0x002E"
#define VI_WEIGHT_inst                                                0x002E
#define VI_WEIGHT_write_enable2_shift                                 (17)
#define VI_WEIGHT_adj_shift                                           (9)
#define VI_WEIGHT_write_enable1_shift                                 (8)
#define VI_WEIGHT_mid_shift                                           (0)
#define VI_WEIGHT_write_enable2_mask                                  (0x00020000)
#define VI_WEIGHT_adj_mask                                            (0x0001FE00)
#define VI_WEIGHT_write_enable1_mask                                  (0x00000100)
#define VI_WEIGHT_mid_mask                                            (0x000000FF)
#define VI_WEIGHT_write_enable2(data)                                 (0x00020000&((data)<<17))
#define VI_WEIGHT_adj(data)                                           (0x0001FE00&((data)<<9))
#define VI_WEIGHT_write_enable1(data)                                 (0x00000100&((data)<<8))
#define VI_WEIGHT_mid(data)                                           (0x000000FF&(data))
#define VI_WEIGHT_get_write_enable2(data)                             ((0x00020000&(data))>>17)
#define VI_WEIGHT_get_adj(data)                                       ((0x0001FE00&(data))>>9)
#define VI_WEIGHT_get_write_enable1(data)                             ((0x00000100&(data))>>8)
#define VI_WEIGHT_get_mid(data)                                       (0x000000FF&(data))

#define VI_PREVDIR                                                    0x180040BC
#define VI_PREVDIR_reg_addr                                           "0xB80040BC"
#define VI_PREVDIR_reg                                                0xB80040BC
#define VI_PREVDIR_inst_addr                                          "0x002F"
#define VI_PREVDIR_inst                                               0x002F
#define VI_PREVDIR_write_enable2_shift                                (17)
#define VI_PREVDIR_weight_shift                                       (9)
#define VI_PREVDIR_write_enable1_shift                                (8)
#define VI_PREVDIR_th_shift                                           (0)
#define VI_PREVDIR_write_enable2_mask                                 (0x00020000)
#define VI_PREVDIR_weight_mask                                        (0x0001FE00)
#define VI_PREVDIR_write_enable1_mask                                 (0x00000100)
#define VI_PREVDIR_th_mask                                            (0x000000FF)
#define VI_PREVDIR_write_enable2(data)                                (0x00020000&((data)<<17))
#define VI_PREVDIR_weight(data)                                       (0x0001FE00&((data)<<9))
#define VI_PREVDIR_write_enable1(data)                                (0x00000100&((data)<<8))
#define VI_PREVDIR_th(data)                                           (0x000000FF&(data))
#define VI_PREVDIR_get_write_enable2(data)                            ((0x00020000&(data))>>17)
#define VI_PREVDIR_get_weight(data)                                   ((0x0001FE00&(data))>>9)
#define VI_PREVDIR_get_write_enable1(data)                            ((0x00000100&(data))>>8)
#define VI_PREVDIR_get_th(data)                                       (0x000000FF&(data))

#define VI_CINTRA                                                     0x180040C0
#define VI_CINTRA_reg_addr                                            "0xB80040C0"
#define VI_CINTRA_reg                                                 0xB80040C0
#define VI_CINTRA_inst_addr                                           "0x0030"
#define VI_CINTRA_inst                                                0x0030
#define VI_CINTRA_m_shift                                             (0)
#define VI_CINTRA_m_mask                                              (0x00000003)
#define VI_CINTRA_m(data)                                             (0x00000003&(data))
#define VI_CINTRA_get_m(data)                                         (0x00000003&(data))

#define VI_DSDMA_CTRL                                                 0x180040C4
#define VI_DSDMA_CTRL_reg_addr                                        "0xB80040C4"
#define VI_DSDMA_CTRL_reg                                             0xB80040C4
#define VI_DSDMA_CTRL_inst_addr                                       "0x0031"
#define VI_DSDMA_CTRL_inst                                            0x0031
#define VI_DSDMA_CTRL_write_enable1_shift                             (17)
#define VI_DSDMA_CTRL_bstlen_shift                                    (14)
#define VI_DSDMA_CTRL_write_enable2_shift                             (13)
#define VI_DSDMA_CTRL_vids_y_shift                                    (7)
#define VI_DSDMA_CTRL_write_enable3_shift                             (6)
#define VI_DSDMA_CTRL_vids_c_shift                                    (0)
#define VI_DSDMA_CTRL_write_enable1_mask                              (0x00020000)
#define VI_DSDMA_CTRL_bstlen_mask                                     (0x0001C000)
#define VI_DSDMA_CTRL_write_enable2_mask                              (0x00002000)
#define VI_DSDMA_CTRL_vids_y_mask                                     (0x00001F80)
#define VI_DSDMA_CTRL_write_enable3_mask                              (0x00000040)
#define VI_DSDMA_CTRL_vids_c_mask                                     (0x0000003F)
#define VI_DSDMA_CTRL_write_enable1(data)                             (0x00020000&((data)<<17))
#define VI_DSDMA_CTRL_bstlen(data)                                    (0x0001C000&((data)<<14))
#define VI_DSDMA_CTRL_write_enable2(data)                             (0x00002000&((data)<<13))
#define VI_DSDMA_CTRL_vids_y(data)                                    (0x00001F80&((data)<<7))
#define VI_DSDMA_CTRL_write_enable3(data)                             (0x00000040&((data)<<6))
#define VI_DSDMA_CTRL_vids_c(data)                                    (0x0000003F&(data))
#define VI_DSDMA_CTRL_get_write_enable1(data)                         ((0x00020000&(data))>>17)
#define VI_DSDMA_CTRL_get_bstlen(data)                                ((0x0001C000&(data))>>14)
#define VI_DSDMA_CTRL_get_write_enable2(data)                         ((0x00002000&(data))>>13)
#define VI_DSDMA_CTRL_get_vids_y(data)                                ((0x00001F80&(data))>>7)
#define VI_DSDMA_CTRL_get_write_enable3(data)                         ((0x00000040&(data))>>6)
#define VI_DSDMA_CTRL_get_vids_c(data)                                (0x0000003F&(data))

#define VI_DSDMA_ERR                                                  0x180040C8
#define VI_DSDMA_ERR_reg_addr                                         "0xB80040C8"
#define VI_DSDMA_ERR_reg                                              0xB80040C8
#define VI_DSDMA_ERR_inst_addr                                        "0x0032"
#define VI_DSDMA_ERR_inst                                             0x0032
#define VI_DSDMA_ERR_y_err_shift                                      (1)
#define VI_DSDMA_ERR_c_err_shift                                      (0)
#define VI_DSDMA_ERR_y_err_mask                                       (0x00000002)
#define VI_DSDMA_ERR_c_err_mask                                       (0x00000001)
#define VI_DSDMA_ERR_y_err(data)                                      (0x00000002&((data)<<1))
#define VI_DSDMA_ERR_c_err(data)                                      (0x00000001&(data))
#define VI_DSDMA_ERR_get_y_err(data)                                  ((0x00000002&(data))>>1)
#define VI_DSDMA_ERR_get_c_err(data)                                  (0x00000001&(data))
#endif
