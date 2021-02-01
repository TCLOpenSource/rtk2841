// This file is generated using the spec version 1.39, firmware template version 1.39and SRIF Parser                                                                                source code SVN rev:771                    Version flow no.:1.1.0
#ifndef _ROTDMA_REG_H_INCLUDED_
#define _ROTDMA_REG_H_INCLUDED_

//#define  _ROTDMA_USE_STRUCT
#ifdef _ROTDMA_USE_STRUCT

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    startaddress:28;
}SRCFRAMEBUFFER_0;

typedef struct
{
    unsigned int    pitchwidth:20;
    unsigned int    reserved_0:8;
    unsigned int    pixelformat:4;
}SRCFRAMEBUFFER_1;

typedef struct
{
    unsigned int    picwidht:16;
    unsigned int    picheight:16;
}SRCPICTURE;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    startaddress:28;
}DSTFRAMEBUFFER_0;

typedef struct
{
    unsigned int    pitchwidth:20;
    unsigned int    reserved_0:8;
    unsigned int    pixelformat:4;
}DSTFRAMEBUFFER_1;

typedef struct
{
    unsigned int    rotate:1;
    unsigned int    mcu_transfer:1;
    unsigned int    in_little_endian:1;
    unsigned int    out_big_endian:1;
    unsigned int    angle_n_flip:4;
    unsigned int    reserved_0:22;
    unsigned int    rotation_done_ie:1;
    unsigned int    reset:1;
}ROTATE_ctrl;

typedef struct
{
    unsigned int    rotate_done:1;
    unsigned int    reserved_0:31;
}ROTATE_status;

typedef struct
{
    unsigned int    bist_rstn:1;
    unsigned int    bist_mode:1;
    unsigned int    reserved_0:30;
}ROTATE_bist_ctrl;

typedef struct
{
    unsigned int    bist_done:1;
    unsigned int    bist_fail:1;
    unsigned int    reserved_0:30;
}ROTATE_bist_status;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    module_sel:1;
}ROTATE_srccpy_ctrl;
#endif


#define SRCFRAMEBUFFER_0                                              0x18036800
#define SRCFRAMEBUFFER_0_reg_addr                                     "0xb8036800"
#define SRCFRAMEBUFFER_0_reg                                          0xb8036800
#define SRCFRAMEBUFFER_0_inst_addr                                    "0x0200"
#define SRCFRAMEBUFFER_0_inst                                         0x0200
#define SRCFRAMEBUFFER_0_startaddress_shift                           (0)
#define SRCFRAMEBUFFER_0_startaddress_mask                            (0x0FFFFFFF)
#define SRCFRAMEBUFFER_0_startaddress(data)                           (0x0FFFFFFF&(data))
#define SRCFRAMEBUFFER_0_get_startaddress(data)                       (0x0FFFFFFF&(data))


#define SRCFRAMEBUFFER_1                                              0x18036804
#define SRCFRAMEBUFFER_1_reg_addr                                     "0xb8036804"
#define SRCFRAMEBUFFER_1_reg                                          0xb8036804
#define SRCFRAMEBUFFER_1_inst_addr                                    "0x0201"
#define SRCFRAMEBUFFER_1_inst                                         0x0201
#define SRCFRAMEBUFFER_1_pitchwidth_shift                             (12)
#define SRCFRAMEBUFFER_1_pixelformat_shift                            (0)
#define SRCFRAMEBUFFER_1_pitchwidth_mask                              (0xFFFFF000)
#define SRCFRAMEBUFFER_1_pixelformat_mask                             (0x0000000F)
#define SRCFRAMEBUFFER_1_pitchwidth(data)                             (0xFFFFF000&((data)<<12))
#define SRCFRAMEBUFFER_1_pixelformat(data)                            (0x0000000F&(data))
#define SRCFRAMEBUFFER_1_get_pitchwidth(data)                         ((0xFFFFF000&(data))>>12)
#define SRCFRAMEBUFFER_1_get_pixelformat(data)                        (0x0000000F&(data))


#define SRCPICTURE                                                    0x18036808
#define SRCPICTURE_reg_addr                                           "0xb8036808"
#define SRCPICTURE_reg                                                0xb8036808
#define SRCPICTURE_inst_addr                                          "0x0202"
#define SRCPICTURE_inst                                               0x0202
#define SRCPICTURE_picwidht_shift                                     (16)
#define SRCPICTURE_picheight_shift                                    (0)
#define SRCPICTURE_picwidht_mask                                      (0xFFFF0000)
#define SRCPICTURE_picheight_mask                                     (0x0000FFFF)
#define SRCPICTURE_picwidht(data)                                     (0xFFFF0000&((data)<<16))
#define SRCPICTURE_picheight(data)                                    (0x0000FFFF&(data))
#define SRCPICTURE_get_picwidht(data)                                 ((0xFFFF0000&(data))>>16)
#define SRCPICTURE_get_picheight(data)                                (0x0000FFFF&(data))


#define DSTFRAMEBUFFER_0                                              0x1803680c
#define DSTFRAMEBUFFER_0_reg_addr                                     "0xb803680c"
#define DSTFRAMEBUFFER_0_reg                                          0xb803680c
#define DSTFRAMEBUFFER_0_inst_addr                                    "0x0203"
#define DSTFRAMEBUFFER_0_inst                                         0x0203
#define DSTFRAMEBUFFER_0_startaddress_shift                           (0)
#define DSTFRAMEBUFFER_0_startaddress_mask                            (0x0FFFFFFF)
#define DSTFRAMEBUFFER_0_startaddress(data)                           (0x0FFFFFFF&(data))
#define DSTFRAMEBUFFER_0_get_startaddress(data)                       (0x0FFFFFFF&(data))


#define DSTFRAMEBUFFER_1                                              0x18036810
#define DSTFRAMEBUFFER_1_reg_addr                                     "0xb8036810"
#define DSTFRAMEBUFFER_1_reg                                          0xb8036810
#define DSTFRAMEBUFFER_1_inst_addr                                    "0x0204"
#define DSTFRAMEBUFFER_1_inst                                         0x0204
#define DSTFRAMEBUFFER_1_pitchwidth_shift                             (12)
#define DSTFRAMEBUFFER_1_pixelformat_shift                            (0)
#define DSTFRAMEBUFFER_1_pitchwidth_mask                              (0xFFFFF000)
#define DSTFRAMEBUFFER_1_pixelformat_mask                             (0x0000000F)
#define DSTFRAMEBUFFER_1_pitchwidth(data)                             (0xFFFFF000&((data)<<12))
#define DSTFRAMEBUFFER_1_pixelformat(data)                            (0x0000000F&(data))
#define DSTFRAMEBUFFER_1_get_pitchwidth(data)                         ((0xFFFFF000&(data))>>12)
#define DSTFRAMEBUFFER_1_get_pixelformat(data)                        (0x0000000F&(data))


#define ROTDMA_CTRL                                                   0x18036818
#define ROTDMA_CTRL_reg_addr                                          "0xb8036818"
#define ROTDMA_CTRL_reg                                               0xb8036818
#define ROTDMA_CTRL_inst_addr                                         "0x0206"
#define ROTDMA_CTRL_inst                                              0x0206
#define ROTDMA_CTRL_rotate_shift                                      (31)
#define ROTDMA_CTRL_mcu_transfer_shift                                (30)
#define ROTDMA_CTRL_in_little_endian_shift                            (29)
#define ROTDMA_CTRL_out_big_endian_shift                              (28)
#define ROTDMA_CTRL_angle_n_flip_shift                                (24)
#define ROTDMA_CTRL_rotation_done_ie_shift                            (1)
#define ROTDMA_CTRL_reset_shift                                       (0)
#define ROTDMA_CTRL_rotate_mask                                       (0x80000000)
#define ROTDMA_CTRL_mcu_transfer_mask                                 (0x40000000)
#define ROTDMA_CTRL_in_little_endian_mask                             (0x20000000)
#define ROTDMA_CTRL_out_big_endian_mask                               (0x10000000)
#define ROTDMA_CTRL_angle_n_flip_mask                                 (0x0F000000)
#define ROTDMA_CTRL_rotation_done_ie_mask                             (0x00000002)
#define ROTDMA_CTRL_reset_mask                                        (0x00000001)
#define ROTDMA_CTRL_rotate(data)                                      (0x80000000&((data)<<31))
#define ROTDMA_CTRL_mcu_transfer(data)                                (0x40000000&((data)<<30))
#define ROTDMA_CTRL_in_little_endian(data)                            (0x20000000&((data)<<29))
#define ROTDMA_CTRL_out_big_endian(data)                              (0x10000000&((data)<<28))
#define ROTDMA_CTRL_angle_n_flip(data)                                (0x0F000000&((data)<<24))
#define ROTDMA_CTRL_rotation_done_ie(data)                            (0x00000002&((data)<<1))
#define ROTDMA_CTRL_reset(data)                                       (0x00000001&(data))
#define ROTDMA_CTRL_get_rotate(data)                                  ((0x80000000&(data))>>31)
#define ROTDMA_CTRL_get_mcu_transfer(data)                            ((0x40000000&(data))>>30)
#define ROTDMA_CTRL_get_in_little_endian(data)                        ((0x20000000&(data))>>29)
#define ROTDMA_CTRL_get_out_big_endian(data)                          ((0x10000000&(data))>>28)
#define ROTDMA_CTRL_get_angle_n_flip(data)                            ((0x0F000000&(data))>>24)
#define ROTDMA_CTRL_get_rotation_done_ie(data)                        ((0x00000002&(data))>>1)
#define ROTDMA_CTRL_get_reset(data)                                   (0x00000001&(data))


#define ROTATE_STATUS                                                 0x1803681c
#define ROTATE_STATUS_reg_addr                                        "0xb803681c"
#define ROTATE_STATUS_reg                                             0xb803681c
#define ROTATE_STATUS_inst_addr                                       "0x0207"
#define ROTATE_STATUS_inst                                            0x0207
#define ROTATE_STATUS_rotate_done_shift                               (31)
#define ROTATE_STATUS_rotate_done_mask                                (0x80000000)
#define ROTATE_STATUS_rotate_done(data)                               (0x80000000&((data)<<31))
#define ROTATE_STATUS_get_rotate_done(data)                           ((0x80000000&(data))>>31)


#define ROTATE_BIST_CTRL                                              0x18036820
#define ROTATE_BIST_CTRL_reg_addr                                     "0xb8036820"
#define ROTATE_BIST_CTRL_reg                                          0xb8036820
#define ROTATE_BIST_CTRL_inst_addr                                    "0x0208"
#define ROTATE_BIST_CTRL_inst                                         0x0208
#define ROTATE_BIST_CTRL_bist_rstn_shift                              (31)
#define ROTATE_BIST_CTRL_bist_mode_shift                              (30)
#define ROTATE_BIST_CTRL_bist_rstn_mask                               (0x80000000)
#define ROTATE_BIST_CTRL_bist_mode_mask                               (0x40000000)
#define ROTATE_BIST_CTRL_bist_rstn(data)                              (0x80000000&((data)<<31))
#define ROTATE_BIST_CTRL_bist_mode(data)                              (0x40000000&((data)<<30))
#define ROTATE_BIST_CTRL_get_bist_rstn(data)                          ((0x80000000&(data))>>31)
#define ROTATE_BIST_CTRL_get_bist_mode(data)                          ((0x40000000&(data))>>30)


#define ROTATE_BIST_STATUS                                            0x18036824
#define ROTATE_BIST_STATUS_reg_addr                                   "0xb8036824"
#define ROTATE_BIST_STATUS_reg                                        0xb8036824
#define ROTATE_BIST_STATUS_inst_addr                                  "0x0209"
#define ROTATE_BIST_STATUS_inst                                       0x0209
#define ROTATE_BIST_STATUS_bist_done_shift                            (31)
#define ROTATE_BIST_STATUS_bist_fail_shift                            (30)
#define ROTATE_BIST_STATUS_bist_done_mask                             (0x80000000)
#define ROTATE_BIST_STATUS_bist_fail_mask                             (0x40000000)
#define ROTATE_BIST_STATUS_bist_done(data)                            (0x80000000&((data)<<31))
#define ROTATE_BIST_STATUS_bist_fail(data)                            (0x40000000&((data)<<30))
#define ROTATE_BIST_STATUS_get_bist_done(data)                        ((0x80000000&(data))>>31)
#define ROTATE_BIST_STATUS_get_bist_fail(data)                        ((0x40000000&(data))>>30)


#define ROTATE_SRCCPY_CTRL                                            0x18036828
#define ROTATE_SRCCPY_CTRL_reg_addr                                   "0xb8036828"
#define ROTATE_SRCCPY_CTRL_reg                                        0xb8036828
#define ROTATE_SRCCPY_CTRL_inst_addr                                  "0x020A"
#define ROTATE_SRCCPY_CTRL_inst                                       0x020A
#define ROTATE_SRCCPY_CTRL_module_sel_shift                           (0)
#define ROTATE_SRCCPY_CTRL_module_sel_mask                            (0x00000001)
#define ROTATE_SRCCPY_CTRL_module_sel(data)                           (0x00000001&(data))
#define ROTATE_SRCCPY_CTRL_get_module_sel(data)                       (0x00000001&(data))
#endif
