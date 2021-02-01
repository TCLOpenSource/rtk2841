// This file is generated using the spec version 0.01, firmware template version 1.39and DVR_Parser_0.46
#ifndef _VO_REG_H_INCLUDED_
#define _VO_REG_H_INCLUDED_

//#define  _VO_USE_STRUCT
#ifdef _VO_USE_STRUCT

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    write_enable1:1;
    unsigned int    len:10;
    unsigned int    write_enable2:1;
    unsigned int    bstlen:3;
    unsigned int    write_enable3:1;
    unsigned int    vods_y:6;
    unsigned int    write_enable4:1;
    unsigned int    vods_c:6;
}vo_DSDMA_CTRL1;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    write_enable1:1;
    unsigned int    nline_y:10;
    unsigned int    write_enable2:1;
    unsigned int    nline_c:10;
    unsigned int    write_enable2:1;
    unsigned int    go:1;
}vo_DSDMA_CTRL2;

typedef struct
{
    unsigned int    reserved_0:30;
    unsigned int    y_err:1;
    unsigned int    c_err:1;
}vo_DSDMA_ERR;

typedef struct
{
    unsigned int    reserved_0:29;
    unsigned int    yen:1;
    unsigned int    cen:1;
    unsigned int    write_data:1;
}vo_VSCCTL1;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    write_enable1:1;
    unsigned int    yonp:11;
    unsigned int    write_enable2:1;
    unsigned int    ydphs:17;
}vo_VYSC1;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    write_enable1:1;
    unsigned int    conp:11;
    unsigned int    write_enable2:1;
    unsigned int    cdphs:17;
}vo_VCSC1;

typedef struct
{
    unsigned int    reserved_0:21;
    unsigned int    endline:11;
}vo_VYEPOS1;

typedef struct
{
    unsigned int    reserved_0:21;
    unsigned int    endline:11;
}vo_VCEPOS1;

typedef struct
{
    unsigned int    reserved_0:29;
    unsigned int    yen:1;
    unsigned int    cen:1;
    unsigned int    write_data:1;
}vo_HSCCTL1;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    begin_point:11;
    unsigned int    end_point:11;
}vo_HYEPOS1;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    shift:5;
    unsigned int    width:11;
}vo_HYWIDTH1;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    write_enable1:1;
    unsigned int    yonp:11;
    unsigned int    write_enable2:1;
    unsigned int    ydphs:17;
}vo_HYSC1;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    write_enable1:1;
    unsigned int    conp:11;
    unsigned int    write_enable2:1;
    unsigned int    cdphs:17;
}vo_HCSC1;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    write_enable1:1;
    unsigned int    en:1;
    unsigned int    write_enable2:1;
    unsigned int    cr:8;
    unsigned int    write_enable3:1;
    unsigned int    cb:8;
    unsigned int    write_enable4:1;
    unsigned int    y:8;
}vo_MixBG;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    write_enable1:1;
    unsigned int    yend:10;
    unsigned int    write_enable2:1;
    unsigned int    xend:10;
}vo_MixWindow;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    write_enable1:1;
    unsigned int    end:10;
    unsigned int    write_enable2:1;
    unsigned int    st:10;
}vo_MixVX;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    write_enable1:1;
    unsigned int    end:10;
    unsigned int    write_enable2:1;
    unsigned int    st:10;
}vo_MixVY;

typedef struct
{
    unsigned int    reserved_0:29;
    unsigned int    topfld:1;
    unsigned int    ien:1;
    unsigned int    write_data:1;
}vo_REINTERLACE;

typedef struct
{
    unsigned int    reserved_0:29;
    unsigned int    pudflw:1;
    unsigned int    iudflw:1;
    unsigned int    write_data:1;
}vo_VINTEN;

typedef struct
{
    unsigned int    reserved_0:29;
    unsigned int    pudflw:1;
    unsigned int    iudflw:1;
    unsigned int    write_data:1;
}vo_VINTST;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    write_enable3:1;
    unsigned int    vo_dbg_sel:7;
    unsigned int    write_enable1:1;
    unsigned int    enable:1;
}vo_DBG;
#endif

#define VO_DSDMA_CTRL1                                                0x18005000
#define VO_DSDMA_CTRL1_reg_addr                                       "0xB8005000"
#define VO_DSDMA_CTRL1_reg                                            0xB8005000
#define VO_DSDMA_CTRL1_inst_addr                                      "0x0000"
#define VO_DSDMA_CTRL1_inst                                           0x0000
#define VO_DSDMA_CTRL1_write_enable1_shift                            (28)
#define VO_DSDMA_CTRL1_len_shift                                      (18)
#define VO_DSDMA_CTRL1_write_enable2_shift                            (17)
#define VO_DSDMA_CTRL1_bstlen_shift                                   (14)
#define VO_DSDMA_CTRL1_write_enable3_shift                            (13)
#define VO_DSDMA_CTRL1_vods_y_shift                                   (7)
#define VO_DSDMA_CTRL1_write_enable4_shift                            (6)
#define VO_DSDMA_CTRL1_vods_c_shift                                   (0)
#define VO_DSDMA_CTRL1_write_enable1_mask                             (0x10000000)
#define VO_DSDMA_CTRL1_len_mask                                       (0x0FFC0000)
#define VO_DSDMA_CTRL1_write_enable2_mask                             (0x00020000)
#define VO_DSDMA_CTRL1_bstlen_mask                                    (0x0001C000)
#define VO_DSDMA_CTRL1_write_enable3_mask                             (0x00002000)
#define VO_DSDMA_CTRL1_vods_y_mask                                    (0x00001F80)
#define VO_DSDMA_CTRL1_write_enable4_mask                             (0x00000040)
#define VO_DSDMA_CTRL1_vods_c_mask                                    (0x0000003F)
#define VO_DSDMA_CTRL1_write_enable1(data)                            (0x10000000&((data)<<28))
#define VO_DSDMA_CTRL1_len(data)                                      (0x0FFC0000&((data)<<18))
#define VO_DSDMA_CTRL1_write_enable2(data)                            (0x00020000&((data)<<17))
#define VO_DSDMA_CTRL1_bstlen(data)                                   (0x0001C000&((data)<<14))
#define VO_DSDMA_CTRL1_write_enable3(data)                            (0x00002000&((data)<<13))
#define VO_DSDMA_CTRL1_vods_y(data)                                   (0x00001F80&((data)<<7))
#define VO_DSDMA_CTRL1_write_enable4(data)                            (0x00000040&((data)<<6))
#define VO_DSDMA_CTRL1_vods_c(data)                                   (0x0000003F&(data))
#define VO_DSDMA_CTRL1_get_write_enable1(data)                        ((0x10000000&(data))>>28)
#define VO_DSDMA_CTRL1_get_len(data)                                  ((0x0FFC0000&(data))>>18)
#define VO_DSDMA_CTRL1_get_write_enable2(data)                        ((0x00020000&(data))>>17)
#define VO_DSDMA_CTRL1_get_bstlen(data)                               ((0x0001C000&(data))>>14)
#define VO_DSDMA_CTRL1_get_write_enable3(data)                        ((0x00002000&(data))>>13)
#define VO_DSDMA_CTRL1_get_vods_y(data)                               ((0x00001F80&(data))>>7)
#define VO_DSDMA_CTRL1_get_write_enable4(data)                        ((0x00000040&(data))>>6)
#define VO_DSDMA_CTRL1_get_vods_c(data)                               (0x0000003F&(data))

#define VO_DSDMA_CTRL2                                                0x18005004
#define VO_DSDMA_CTRL2_reg_addr                                       "0xB8005004"
#define VO_DSDMA_CTRL2_reg                                            0xB8005004
#define VO_DSDMA_CTRL2_inst_addr                                      "0x0001"
#define VO_DSDMA_CTRL2_inst                                           0x0001
#define VO_DSDMA_CTRL2_write_enable1_shift                            (23)
#define VO_DSDMA_CTRL2_nline_y_shift                                  (13)
#define VO_DSDMA_CTRL2_write_enable2_shift                            (12)
#define VO_DSDMA_CTRL2_nline_c_shift                                  (2)
#define VO_DSDMA_CTRL2_write_enable3_shift                            (1)
#define VO_DSDMA_CTRL2_go_shift                                       (0)
#define VO_DSDMA_CTRL2_write_enable1_mask                             (0x00800000)
#define VO_DSDMA_CTRL2_nline_y_mask                                   (0x007FE000)
#define VO_DSDMA_CTRL2_write_enable2_mask                             (0x00001000)
#define VO_DSDMA_CTRL2_nline_c_mask                                   (0x00000FFC)
#define VO_DSDMA_CTRL2_write_enable3_mask                             (0x00000002)
#define VO_DSDMA_CTRL2_go_mask                                        (0x00000001)
#define VO_DSDMA_CTRL2_write_enable1(data)                            (0x00800000&((data)<<23))
#define VO_DSDMA_CTRL2_nline_y(data)                                  (0x007FE000&((data)<<13))
#define VO_DSDMA_CTRL2_write_enable2(data)                            (0x00001000&((data)<<12))
#define VO_DSDMA_CTRL2_nline_c(data)                                  (0x00000FFC&((data)<<2))
#define VO_DSDMA_CTRL2_write_enable3(data)                            (0x00000002&((data)<<1))
#define VO_DSDMA_CTRL2_go(data)                                       (0x00000001&(data))
#define VO_DSDMA_CTRL2_get_write_enable1(data)                        ((0x00800000&(data))>>23)
#define VO_DSDMA_CTRL2_get_nline_y(data)                              ((0x007FE000&(data))>>13)
#define VO_DSDMA_CTRL2_get_write_enable2(data)                        ((0x00001000&(data))>>12)
#define VO_DSDMA_CTRL2_get_nline_c(data)                              ((0x00000FFC&(data))>>2)
#define VO_DSDMA_CTRL2_get_write_enable3(data)                        ((0x00000002&(data))>>1)
#define VO_DSDMA_CTRL2_get_go(data)                                   (0x00000001&(data))

#define VO_DSDMA_ERR                                                  0x18005008
#define VO_DSDMA_ERR_reg_addr                                         "0xB8005008"
#define VO_DSDMA_ERR_reg                                              0xB8005008
#define VO_DSDMA_ERR_inst_addr                                        "0x0002"
#define VO_DSDMA_ERR_inst                                             0x0002
#define VO_DSDMA_ERR_y_err_shift                                      (1)
#define VO_DSDMA_ERR_c_err_shift                                      (0)
#define VO_DSDMA_ERR_y_err_mask                                       (0x00000002)
#define VO_DSDMA_ERR_c_err_mask                                       (0x00000001)
#define VO_DSDMA_ERR_y_err(data)                                      (0x00000002&((data)<<1))
#define VO_DSDMA_ERR_c_err(data)                                      (0x00000001&(data))
#define VO_DSDMA_ERR_get_y_err(data)                                  ((0x00000002&(data))>>1)
#define VO_DSDMA_ERR_get_c_err(data)                                  (0x00000001&(data))

#define VO_VSCCTL1                                                    0x1800500C
#define VO_VSCCTL1_reg_addr                                           "0xB800500C"
#define VO_VSCCTL1_reg                                                0xB800500C
#define VO_VSCCTL1_inst_addr                                          "0x0003"
#define VO_VSCCTL1_inst                                               0x0003
#define VO_VSCCTL1_yen_shift                                          (2)
#define VO_VSCCTL1_cen_shift                                          (1)
#define VO_VSCCTL1_write_data_shift                                   (0)
#define VO_VSCCTL1_yen_mask                                           (0x00000004)
#define VO_VSCCTL1_cen_mask                                           (0x00000002)
#define VO_VSCCTL1_write_data_mask                                    (0x00000001)
#define VO_VSCCTL1_yen(data)                                          (0x00000004&((data)<<2))
#define VO_VSCCTL1_cen(data)                                          (0x00000002&((data)<<1))
#define VO_VSCCTL1_write_data(data)                                   (0x00000001&(data))
#define VO_VSCCTL1_get_yen(data)                                      ((0x00000004&(data))>>2)
#define VO_VSCCTL1_get_cen(data)                                      ((0x00000002&(data))>>1)
#define VO_VSCCTL1_get_write_data(data)                               (0x00000001&(data))

#define VO_VYSC1                                                      0x18005010
#define VO_VYSC1_reg_addr                                             "0xB8005010"
#define VO_VYSC1_reg                                                  0xB8005010
#define VO_VYSC1_inst_addr                                            "0x0004"
#define VO_VYSC1_inst                                                 0x0004
#define VO_VYSC1_write_enable1_shift                                  (29)
#define VO_VYSC1_yonp_shift                                           (18)
#define VO_VYSC1_write_enable2_shift                                  (17)
#define VO_VYSC1_ydphs_shift                                          (0)
#define VO_VYSC1_write_enable1_mask                                   (0x20000000)
#define VO_VYSC1_yonp_mask                                            (0x1FFC0000)
#define VO_VYSC1_write_enable2_mask                                   (0x00020000)
#define VO_VYSC1_ydphs_mask                                           (0x0001FFFF)
#define VO_VYSC1_write_enable1(data)                                  (0x20000000&((data)<<29))
#define VO_VYSC1_yonp(data)                                           (0x1FFC0000&((data)<<18))
#define VO_VYSC1_write_enable2(data)                                  (0x00020000&((data)<<17))
#define VO_VYSC1_ydphs(data)                                          (0x0001FFFF&(data))
#define VO_VYSC1_get_write_enable1(data)                              ((0x20000000&(data))>>29)
#define VO_VYSC1_get_yonp(data)                                       ((0x1FFC0000&(data))>>18)
#define VO_VYSC1_get_write_enable2(data)                              ((0x00020000&(data))>>17)
#define VO_VYSC1_get_ydphs(data)                                      (0x0001FFFF&(data))

#define VO_VCSC1                                                      0x18005014
#define VO_VCSC1_reg_addr                                             "0xB8005014"
#define VO_VCSC1_reg                                                  0xB8005014
#define VO_VCSC1_inst_addr                                            "0x0005"
#define VO_VCSC1_inst                                                 0x0005
#define VO_VCSC1_write_enable1_shift                                  (29)
#define VO_VCSC1_conp_shift                                           (18)
#define VO_VCSC1_write_enable2_shift                                  (17)
#define VO_VCSC1_cdphs_shift                                          (0)
#define VO_VCSC1_write_enable1_mask                                   (0x20000000)
#define VO_VCSC1_conp_mask                                            (0x1FFC0000)
#define VO_VCSC1_write_enable2_mask                                   (0x00020000)
#define VO_VCSC1_cdphs_mask                                           (0x0001FFFF)
#define VO_VCSC1_write_enable1(data)                                  (0x20000000&((data)<<29))
#define VO_VCSC1_conp(data)                                           (0x1FFC0000&((data)<<18))
#define VO_VCSC1_write_enable2(data)                                  (0x00020000&((data)<<17))
#define VO_VCSC1_cdphs(data)                                          (0x0001FFFF&(data))
#define VO_VCSC1_get_write_enable1(data)                              ((0x20000000&(data))>>29)
#define VO_VCSC1_get_conp(data)                                       ((0x1FFC0000&(data))>>18)
#define VO_VCSC1_get_write_enable2(data)                              ((0x00020000&(data))>>17)
#define VO_VCSC1_get_cdphs(data)                                      (0x0001FFFF&(data))

#define VO_VYEPOS1                                                    0x18005018
#define VO_VYEPOS1_reg_addr                                           "0xB8005018"
#define VO_VYEPOS1_reg                                                0xB8005018
#define VO_VYEPOS1_inst_addr                                          "0x0006"
#define VO_VYEPOS1_inst                                               0x0006
#define VO_VYEPOS1_endline_shift                                      (0)
#define VO_VYEPOS1_endline_mask                                       (0x000007FF)
#define VO_VYEPOS1_endline(data)                                      (0x000007FF&(data))
#define VO_VYEPOS1_get_endline(data)                                  (0x000007FF&(data))

#define VO_VCEPOS1                                                    0x1800501C
#define VO_VCEPOS1_reg_addr                                           "0xB800501C"
#define VO_VCEPOS1_reg                                                0xB800501C
#define VO_VCEPOS1_inst_addr                                          "0x0007"
#define VO_VCEPOS1_inst                                               0x0007
#define VO_VCEPOS1_endline_shift                                      (0)
#define VO_VCEPOS1_endline_mask                                       (0x000007FF)
#define VO_VCEPOS1_endline(data)                                      (0x000007FF&(data))
#define VO_VCEPOS1_get_endline(data)                                  (0x000007FF&(data))

#define VO_HSCCTL1                                                    0x18005020
#define VO_HSCCTL1_reg_addr                                           "0xB8005020"
#define VO_HSCCTL1_reg                                                0xB8005020
#define VO_HSCCTL1_inst_addr                                          "0x0008"
#define VO_HSCCTL1_inst                                               0x0008
#define VO_HSCCTL1_yen_shift                                          (2)
#define VO_HSCCTL1_cen_shift                                          (1)
#define VO_HSCCTL1_write_data_shift                                   (0)
#define VO_HSCCTL1_yen_mask                                           (0x00000004)
#define VO_HSCCTL1_cen_mask                                           (0x00000002)
#define VO_HSCCTL1_write_data_mask                                    (0x00000001)
#define VO_HSCCTL1_yen(data)                                          (0x00000004&((data)<<2))
#define VO_HSCCTL1_cen(data)                                          (0x00000002&((data)<<1))
#define VO_HSCCTL1_write_data(data)                                   (0x00000001&(data))
#define VO_HSCCTL1_get_yen(data)                                      ((0x00000004&(data))>>2)
#define VO_HSCCTL1_get_cen(data)                                      ((0x00000002&(data))>>1)
#define VO_HSCCTL1_get_write_data(data)                               (0x00000001&(data))

#define VO_HYEPOS1                                                    0x1800512C
#define VO_HYEPOS1_reg_addr                                           "0xB800512C"
#define VO_HYEPOS1_reg                                                0xB800512C
#define VO_HYEPOS1_inst_addr                                          "0x004B"
#define VO_HYEPOS1_inst                                               0x004B
#define VO_HYEPOS1_begin_point_shift                                  (11)
#define VO_HYEPOS1_end_point_shift                                    (0)
#define VO_HYEPOS1_begin_point_mask                                   (0x003FF800)
#define VO_HYEPOS1_end_point_mask                                     (0x000007FF)
#define VO_HYEPOS1_begin_point(data)                                  (0x003FF800&((data)<<11))
#define VO_HYEPOS1_end_point(data)                                    (0x000007FF&(data))
#define VO_HYEPOS1_get_begin_point(data)                              ((0x003FF800&(data))>>11)
#define VO_HYEPOS1_get_end_point(data)                                (0x000007FF&(data))

#define VO_HYWIDTH1                                                   0x18005130
#define VO_HYWIDTH1_reg_addr                                          "0xB8005130"
#define VO_HYWIDTH1_reg                                               0xB8005130
#define VO_HYWIDTH1_inst_addr                                         "0x004C"
#define VO_HYWIDTH1_inst                                              0x004C
#define VO_HYWIDTH1_shift_shift                                       (11)
#define VO_HYWIDTH1_width_shift                                       (0)
#define VO_HYWIDTH1_shift_mask                                        (0x0000F800)
#define VO_HYWIDTH1_width_mask                                        (0x000007FF)
#define VO_HYWIDTH1_shift(data)                                       (0x0000F800&((data)<<11))
#define VO_HYWIDTH1_width(data)                                       (0x000007FF&(data))
#define VO_HYWIDTH1_get_shift(data)                                   ((0x0000F800&(data))>>11)
#define VO_HYWIDTH1_get_width(data)                                   (0x000007FF&(data))

#define VO_HYSC1                                                      0x18005134
#define VO_HYSC1_reg_addr                                             "0xB8005134"
#define VO_HYSC1_reg                                                  0xB8005134
#define VO_HYSC1_inst_addr                                            "0x004D"
#define VO_HYSC1_inst                                                 0x004D
#define VO_HYSC1_write_enable1_shift                                  (29)
#define VO_HYSC1_yonp_shift                                           (18)
#define VO_HYSC1_write_enable2_shift                                  (17)
#define VO_HYSC1_ydphs_shift                                          (0)
#define VO_HYSC1_write_enable1_mask                                   (0x20000000)
#define VO_HYSC1_yonp_mask                                            (0x1FFC0000)
#define VO_HYSC1_write_enable2_mask                                   (0x00020000)
#define VO_HYSC1_ydphs_mask                                           (0x0001FFFF)
#define VO_HYSC1_write_enable1(data)                                  (0x20000000&((data)<<29))
#define VO_HYSC1_yonp(data)                                           (0x1FFC0000&((data)<<18))
#define VO_HYSC1_write_enable2(data)                                  (0x00020000&((data)<<17))
#define VO_HYSC1_ydphs(data)                                          (0x0001FFFF&(data))
#define VO_HYSC1_get_write_enable1(data)                              ((0x20000000&(data))>>29)
#define VO_HYSC1_get_yonp(data)                                       ((0x1FFC0000&(data))>>18)
#define VO_HYSC1_get_write_enable2(data)                              ((0x00020000&(data))>>17)
#define VO_HYSC1_get_ydphs(data)                                      (0x0001FFFF&(data))

#define VO_HCSC1                                                      0x18005138
#define VO_HCSC1_reg_addr                                             "0xB8005138"
#define VO_HCSC1_reg                                                  0xB8005138
#define VO_HCSC1_inst_addr                                            "0x004E"
#define VO_HCSC1_inst                                                 0x004E
#define VO_HCSC1_write_enable1_shift                                  (29)
#define VO_HCSC1_conp_shift                                           (18)
#define VO_HCSC1_write_enable2_shift                                  (17)
#define VO_HCSC1_cdphs_shift                                          (0)
#define VO_HCSC1_write_enable1_mask                                   (0x20000000)
#define VO_HCSC1_conp_mask                                            (0x1FFC0000)
#define VO_HCSC1_write_enable2_mask                                   (0x00020000)
#define VO_HCSC1_cdphs_mask                                           (0x0001FFFF)
#define VO_HCSC1_write_enable1(data)                                  (0x20000000&((data)<<29))
#define VO_HCSC1_conp(data)                                           (0x1FFC0000&((data)<<18))
#define VO_HCSC1_write_enable2(data)                                  (0x00020000&((data)<<17))
#define VO_HCSC1_cdphs(data)                                          (0x0001FFFF&(data))
#define VO_HCSC1_get_write_enable1(data)                              ((0x20000000&(data))>>29)
#define VO_HCSC1_get_conp(data)                                       ((0x1FFC0000&(data))>>18)
#define VO_HCSC1_get_write_enable2(data)                              ((0x00020000&(data))>>17)
#define VO_HCSC1_get_cdphs(data)                                      (0x0001FFFF&(data))

#define VO_MixBG                                                      0x1800513C
#define VO_MixBG_reg_addr                                             "0xB800513C"
#define VO_MixBG_reg                                                  0xB800513C
#define VO_MixBG_inst_addr                                            "0x004F"
#define VO_MixBG_inst                                                 0x004F
#define VO_MixBG_write_enable1_shift                                  (28)
#define VO_MixBG_en_shift                                             (27)
#define VO_MixBG_write_enable2_shift                                  (26)
#define VO_MixBG_cr_shift                                             (18)
#define VO_MixBG_write_enable3_shift                                  (17)
#define VO_MixBG_cb_shift                                             (9)
#define VO_MixBG_write_enable4_shift                                  (8)
#define VO_MixBG_y_shift                                              (0)
#define VO_MixBG_write_enable1_mask                                   (0x10000000)
#define VO_MixBG_en_mask                                              (0x08000000)
#define VO_MixBG_write_enable2_mask                                   (0x04000000)
#define VO_MixBG_cr_mask                                              (0x03FC0000)
#define VO_MixBG_write_enable3_mask                                   (0x00020000)
#define VO_MixBG_cb_mask                                              (0x0001FE00)
#define VO_MixBG_write_enable4_mask                                   (0x00000100)
#define VO_MixBG_y_mask                                               (0x000000FF)
#define VO_MixBG_write_enable1(data)                                  (0x10000000&((data)<<28))
#define VO_MixBG_en(data)                                             (0x08000000&((data)<<27))
#define VO_MixBG_write_enable2(data)                                  (0x04000000&((data)<<26))
#define VO_MixBG_cr(data)                                             (0x03FC0000&((data)<<18))
#define VO_MixBG_write_enable3(data)                                  (0x00020000&((data)<<17))
#define VO_MixBG_cb(data)                                             (0x0001FE00&((data)<<9))
#define VO_MixBG_write_enable4(data)                                  (0x00000100&((data)<<8))
#define VO_MixBG_y(data)                                              (0x000000FF&(data))
#define VO_MixBG_get_write_enable1(data)                              ((0x10000000&(data))>>28)
#define VO_MixBG_get_en(data)                                         ((0x08000000&(data))>>27)
#define VO_MixBG_get_write_enable2(data)                              ((0x04000000&(data))>>26)
#define VO_MixBG_get_cr(data)                                         ((0x03FC0000&(data))>>18)
#define VO_MixBG_get_write_enable3(data)                              ((0x00020000&(data))>>17)
#define VO_MixBG_get_cb(data)                                         ((0x0001FE00&(data))>>9)
#define VO_MixBG_get_write_enable4(data)                              ((0x00000100&(data))>>8)
#define VO_MixBG_get_y(data)                                          (0x000000FF&(data))

#define VO_MixWindow                                                  0x18005140
#define VO_MixWindow_reg_addr                                         "0xB8005140"
#define VO_MixWindow_reg                                              0xB8005140
#define VO_MixWindow_inst_addr                                        "0x0050"
#define VO_MixWindow_inst                                             0x0050
#define VO_MixWindow_write_enable1_shift                              (21)
#define VO_MixWindow_yend_shift                                       (11)
#define VO_MixWindow_write_enable2_shift                              (10)
#define VO_MixWindow_xend_shift                                       (0)
#define VO_MixWindow_write_enable1_mask                               (0x00200000)
#define VO_MixWindow_yend_mask                                        (0x001FF800)
#define VO_MixWindow_write_enable2_mask                               (0x00000400)
#define VO_MixWindow_xend_mask                                        (0x000003FF)
#define VO_MixWindow_write_enable1(data)                              (0x00200000&((data)<<21))
#define VO_MixWindow_yend(data)                                       (0x001FF800&((data)<<11))
#define VO_MixWindow_write_enable2(data)                              (0x00000400&((data)<<10))
#define VO_MixWindow_xend(data)                                       (0x000003FF&(data))
#define VO_MixWindow_get_write_enable1(data)                          ((0x00200000&(data))>>21)
#define VO_MixWindow_get_yend(data)                                   ((0x001FF800&(data))>>11)
#define VO_MixWindow_get_write_enable2(data)                          ((0x00000400&(data))>>10)
#define VO_MixWindow_get_xend(data)                                   (0x000003FF&(data))

#define VO_MixVX                                                      0x18005144
#define VO_MixVX_reg_addr                                             "0xB8005144"
#define VO_MixVX_reg                                                  0xB8005144
#define VO_MixVX_inst_addr                                            "0x0051"
#define VO_MixVX_inst                                                 0x0051
#define VO_MixVX_write_enable1_shift                                  (21)
#define VO_MixVX_end_shift                                            (11)
#define VO_MixVX_write_enable2_shift                                  (10)
#define VO_MixVX_st_shift                                             (0)
#define VO_MixVX_write_enable1_mask                                   (0x00200000)
#define VO_MixVX_end_mask                                             (0x001FF800)
#define VO_MixVX_write_enable2_mask                                   (0x00000400)
#define VO_MixVX_st_mask                                              (0x000003FF)
#define VO_MixVX_write_enable1(data)                                  (0x00200000&((data)<<21))
#define VO_MixVX_end(data)                                            (0x001FF800&((data)<<11))
#define VO_MixVX_write_enable2(data)                                  (0x00000400&((data)<<10))
#define VO_MixVX_st(data)                                             (0x000003FF&(data))
#define VO_MixVX_get_write_enable1(data)                              ((0x00200000&(data))>>21)
#define VO_MixVX_get_end(data)                                        ((0x001FF800&(data))>>11)
#define VO_MixVX_get_write_enable2(data)                              ((0x00000400&(data))>>10)
#define VO_MixVX_get_st(data)                                         (0x000003FF&(data))

#define VO_MixVY                                                      0x18005148
#define VO_MixVY_reg_addr                                             "0xB8005148"
#define VO_MixVY_reg                                                  0xB8005148
#define VO_MixVY_inst_addr                                            "0x0052"
#define VO_MixVY_inst                                                 0x0052
#define VO_MixVY_write_enable1_shift                                  (21)
#define VO_MixVY_end_shift                                            (11)
#define VO_MixVY_write_enable2_shift                                  (10)
#define VO_MixVY_st_shift                                             (0)
#define VO_MixVY_write_enable1_mask                                   (0x00200000)
#define VO_MixVY_end_mask                                             (0x001FF800)
#define VO_MixVY_write_enable2_mask                                   (0x00000400)
#define VO_MixVY_st_mask                                              (0x000003FF)
#define VO_MixVY_write_enable1(data)                                  (0x00200000&((data)<<21))
#define VO_MixVY_end(data)                                            (0x001FF800&((data)<<11))
#define VO_MixVY_write_enable2(data)                                  (0x00000400&((data)<<10))
#define VO_MixVY_st(data)                                             (0x000003FF&(data))
#define VO_MixVY_get_write_enable1(data)                              ((0x00200000&(data))>>21)
#define VO_MixVY_get_end(data)                                        ((0x001FF800&(data))>>11)
#define VO_MixVY_get_write_enable2(data)                              ((0x00000400&(data))>>10)
#define VO_MixVY_get_st(data)                                         (0x000003FF&(data))

#define VO_REINTERLACE                                                0x1800514C
#define VO_REINTERLACE_reg_addr                                       "0xB800514C"
#define VO_REINTERLACE_reg                                            0xB800514C
#define VO_REINTERLACE_inst_addr                                      "0x0053"
#define VO_REINTERLACE_inst                                           0x0053
#define VO_REINTERLACE_topfld_shift                                   (2)
#define VO_REINTERLACE_ien_shift                                      (1)
#define VO_REINTERLACE_write_data_shift                               (0)
#define VO_REINTERLACE_topfld_mask                                    (0x00000004)
#define VO_REINTERLACE_ien_mask                                       (0x00000002)
#define VO_REINTERLACE_write_data_mask                                (0x00000001)
#define VO_REINTERLACE_topfld(data)                                   (0x00000004&((data)<<2))
#define VO_REINTERLACE_ien(data)                                      (0x00000002&((data)<<1))
#define VO_REINTERLACE_write_data(data)                               (0x00000001&(data))
#define VO_REINTERLACE_get_topfld(data)                               ((0x00000004&(data))>>2)
#define VO_REINTERLACE_get_ien(data)                                  ((0x00000002&(data))>>1)
#define VO_REINTERLACE_get_write_data(data)                           (0x00000001&(data))

#define VO_VINTEN                                                     0x18005150
#define VO_VINTEN_reg_addr                                            "0xB8005150"
#define VO_VINTEN_reg                                                 0xB8005150
#define VO_VINTEN_inst_addr                                           "0x0054"
#define VO_VINTEN_inst                                                0x0054
#define VO_VINTEN_pudflw_shift                                        (2)
#define VO_VINTEN_iudflw_shift                                        (1)
#define VO_VINTEN_write_data_shift                                    (0)
#define VO_VINTEN_pudflw_mask                                         (0x00000004)
#define VO_VINTEN_iudflw_mask                                         (0x00000002)
#define VO_VINTEN_write_data_mask                                     (0x00000001)
#define VO_VINTEN_pudflw(data)                                        (0x00000004&((data)<<2))
#define VO_VINTEN_iudflw(data)                                        (0x00000002&((data)<<1))
#define VO_VINTEN_write_data(data)                                    (0x00000001&(data))
#define VO_VINTEN_get_pudflw(data)                                    ((0x00000004&(data))>>2)
#define VO_VINTEN_get_iudflw(data)                                    ((0x00000002&(data))>>1)
#define VO_VINTEN_get_write_data(data)                                (0x00000001&(data))

#define VO_VINTST                                                     0x18005154
#define VO_VINTST_reg_addr                                            "0xB8005154"
#define VO_VINTST_reg                                                 0xB8005154
#define VO_VINTST_inst_addr                                           "0x0055"
#define VO_VINTST_inst                                                0x0055
#define VO_VINTST_pudflw_shift                                        (2)
#define VO_VINTST_iudflw_shift                                        (1)
#define VO_VINTST_write_data_shift                                    (0)
#define VO_VINTST_pudflw_mask                                         (0x00000004)
#define VO_VINTST_iudflw_mask                                         (0x00000002)
#define VO_VINTST_write_data_mask                                     (0x00000001)
#define VO_VINTST_pudflw(data)                                        (0x00000004&((data)<<2))
#define VO_VINTST_iudflw(data)                                        (0x00000002&((data)<<1))
#define VO_VINTST_write_data(data)                                    (0x00000001&(data))
#define VO_VINTST_get_pudflw(data)                                    ((0x00000004&(data))>>2)
#define VO_VINTST_get_iudflw(data)                                    ((0x00000002&(data))>>1)
#define VO_VINTST_get_write_data(data)                                (0x00000001&(data))

#define VO_DBG                                                        0x18005158
#define VO_DBG_reg_addr                                               "0xB8005158"
#define VO_DBG_reg                                                    0xB8005158
#define VO_DBG_inst_addr                                              "0x0056"
#define VO_DBG_inst                                                   0x0056
#define VO_DBG_write_enable3_shift                                    (9)
#define VO_DBG_vo_dbg_sel_shift                                       (2)
#define VO_DBG_write_enable1_shift                                    (1)
#define VO_DBG_enable_shift                                           (0)
#define VO_DBG_write_enable3_mask                                     (0x00000200)
#define VO_DBG_vo_dbg_sel_mask                                        (0x000001FC)
#define VO_DBG_write_enable1_mask                                     (0x00000002)
#define VO_DBG_enable_mask                                            (0x00000001)
#define VO_DBG_write_enable3(data)                                    (0x00000200&((data)<<9))
#define VO_DBG_vo_dbg_sel(data)                                       (0x000001FC&((data)<<2))
#define VO_DBG_write_enable1(data)                                    (0x00000002&((data)<<1))
#define VO_DBG_enable(data)                                           (0x00000001&(data))
#define VO_DBG_get_write_enable3(data)                                ((0x00000200&(data))>>9)
#define VO_DBG_get_vo_dbg_sel(data)                                   ((0x000001FC&(data))>>2)
#define VO_DBG_get_write_enable1(data)                                ((0x00000002&(data))>>1)
#define VO_DBG_get_enable(data)                                       (0x00000001&(data))
#endif
