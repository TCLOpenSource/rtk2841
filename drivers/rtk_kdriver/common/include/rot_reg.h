// This file is generated using the spec version 1.04, firmware template version 1.39and DVR_Parser_0.46
#ifndef _ROT_REG_H_INCLUDED_
#define _ROT_REG_H_INCLUDED_

//#define  _ROT_USE_STRUCT
#ifdef _ROT_USE_STRUCT

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    startaddress:28;
}rot_SrcFramebuffer_0;

typedef struct
{
    unsigned int    pitchwidth:20;
    unsigned int    reserved_0:8;
    unsigned int    pixelformat:4;
}rot_SrcFramebuffer_1;

typedef struct
{
    unsigned int    picwidht:16;
    unsigned int    picheight:16;
}rot_SrcPicture;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    startaddress:28;
}rot_DstFramebuffer_0;

typedef struct
{
    unsigned int    pitchwidth:20;
    unsigned int    reserved_0:8;
    unsigned int    pixelformat:4;
}rot_DstFramebuffer_1;

typedef struct
{
    unsigned int    rotate:1;
    unsigned int    mcu_transfer:1;
    unsigned int    reserved_0:2;
    unsigned int    angle_n_flip:4;
    unsigned int    reserved_1:22;
    unsigned int    rotation_done_ie:1;
    unsigned int    reset:1;
}rot_Rotate_Ctrl;

typedef struct
{
    unsigned int    rotate_done:1;
    unsigned int    reserved_0:31;
}rot_Rotate_Status;

typedef struct
{
    unsigned int    bist_rstn:1;
    unsigned int    bist_mode:1;
    unsigned int    reserved_0:30;
}rot_Rotate_Bist_Ctrl;

typedef struct
{
    unsigned int    bist_done:1;
    unsigned int    bist_fail:1;
    unsigned int    reserved_0:30;
}rot_Rotate_Bist_Status;



typedef struct
{
    unsigned int    modifybitmask:32;
}SRCCPYMODIFY_check_bitmask;

typedef struct
{
    unsigned int    modifyvalue:32;
}SRCCPYMODIFY_check_value;

typedef struct
{
    unsigned int    modifybitmask:32;
}SRCCPYMODIFY_modify_bitmask;

typedef struct
{
    unsigned int    modifyvalue:32;
}SRCCPYMODIFY_modify_value;

#endif

#define Rot_SrcFramebuffer_0                                          0x18036800
#define Rot_SrcFramebuffer_0_reg_addr                                 "0xB8036800"
#define ROT_SRCFRAMEBUFFER_0_reg                                      0xB8036800
#define Rot_SrcFramebuffer_0_inst_addr                                "0x0000"
#define Rot_SrcFramebuffer_0_inst                                     0x0000
#define Rot_SrcFramebuffer_0_startaddress_shift                       (0)
#define Rot_SrcFramebuffer_0_startaddress_mask                        (0x0FFFFFFF)
#define Rot_SrcFramebuffer_0_startaddress(data)                       (0x0FFFFFFF&(data))
#define Rot_SrcFramebuffer_0_get_startaddress(data)                   (0x0FFFFFFF&(data))

#define Rot_SrcFramebuffer_1                                          0x18036804
#define Rot_SrcFramebuffer_1_reg_addr                                 "0xB8036804"
#define ROT_SRCFRAMEBUFFER_1_reg                                      0xB8036804
#define Rot_SrcFramebuffer_1_inst_addr                                "0x0001"
#define Rot_SrcFramebuffer_1_inst                                     0x0001
#define Rot_SrcFramebuffer_1_pitchwidth_shift                         (12)
#define Rot_SrcFramebuffer_1_pixelformat_shift                        (0)
#define Rot_SrcFramebuffer_1_pitchwidth_mask                          (0xFFFFF000)
#define Rot_SrcFramebuffer_1_pixelformat_mask                         (0x0000000F)
#define Rot_SrcFramebuffer_1_pitchwidth(data)                         (0xFFFFF000&((data)<<12))
#define Rot_SrcFramebuffer_1_pixelformat(data)                        (0x0000000F&(data))
#define Rot_SrcFramebuffer_1_get_pitchwidth(data)                     ((0xFFFFF000&(data))>>12)
#define Rot_SrcFramebuffer_1_get_pixelformat(data)                    (0x0000000F&(data))

#define Rot_SrcPicture                                                0x18036808
#define Rot_SrcPicture_reg_addr                                       "0xB8036808"
#define ROT_SRCPICTURE_reg                                            0xB8036808
#define Rot_SrcPicture_inst_addr                                      "0x0002"
#define Rot_SrcPicture_inst                                           0x0002
#define Rot_SrcPicture_picwidht_shift                                 (16)
#define Rot_SrcPicture_picheight_shift                                (0)
#define Rot_SrcPicture_picwidht_mask                                  (0xFFFF0000)
#define Rot_SrcPicture_picheight_mask                                 (0x0000FFFF)
#define Rot_SrcPicture_picwidht(data)                                 (0xFFFF0000&((data)<<16))
#define Rot_SrcPicture_picheight(data)                                (0x0000FFFF&(data))
#define Rot_SrcPicture_get_picwidht(data)                             ((0xFFFF0000&(data))>>16)
#define Rot_SrcPicture_get_picheight(data)                            (0x0000FFFF&(data))

#define Rot_DstFramebuffer_0                                          0x1803680C
#define Rot_DstFramebuffer_0_reg_addr                                 "0xB803680C"
#define ROT_DSTFRAMEBUFFER_0_reg                                      0xB803680C
#define Rot_DstFramebuffer_0_inst_addr                                "0x0003"
#define Rot_DstFramebuffer_0_inst                                     0x0003
#define Rot_DstFramebuffer_0_startaddress_shift                       (0)
#define Rot_DstFramebuffer_0_startaddress_mask                        (0x0FFFFFFF)
#define Rot_DstFramebuffer_0_startaddress(data)                       (0x0FFFFFFF&(data))
#define Rot_DstFramebuffer_0_get_startaddress(data)                   (0x0FFFFFFF&(data))

#define Rot_DstFramebuffer_1                                          0x18036810
#define Rot_DstFramebuffer_1_reg_addr                                 "0xB8036810"
#define ROT_DSTFRAMEBUFFER_1_reg                                      0xB8036810
#define Rot_DstFramebuffer_1_inst_addr                                "0x0004"
#define Rot_DstFramebuffer_1_inst                                     0x0004
#define Rot_DstFramebuffer_1_pitchwidth_shift                         (12)
#define Rot_DstFramebuffer_1_pixelformat_shift                        (0)
#define Rot_DstFramebuffer_1_pitchwidth_mask                          (0xFFFFF000)
#define Rot_DstFramebuffer_1_pixelformat_mask                         (0x0000000F)
#define Rot_DstFramebuffer_1_pitchwidth(data)                         (0xFFFFF000&((data)<<12))
#define Rot_DstFramebuffer_1_pixelformat(data)                        (0x0000000F&(data))
#define Rot_DstFramebuffer_1_get_pitchwidth(data)                     ((0xFFFFF000&(data))>>12)
#define Rot_DstFramebuffer_1_get_pixelformat(data)                    (0x0000000F&(data))

#define Rot_Rotate_Ctrl                                               0x18036818
#define Rot_Rotate_Ctrl_reg_addr                                      "0xB8036818"
#define ROT_ROTATE_CTRL_reg                                           0xB8036818
#define Rot_Rotate_Ctrl_inst_addr                                     "0x0006"
#define Rot_Rotate_Ctrl_inst                                          0x0006
#define Rot_Rotate_Ctrl_rotate_shift                                  (31)
#define Rot_Rotate_Ctrl_mcu_transfer_shift                            (30)
#define Rot_Rotate_Ctrl_angle_n_flip_shift                            (24)
#define Rot_Rotate_Ctrl_rotation_done_ie_shift                        (1)
#define Rot_Rotate_Ctrl_reset_shift                                   (0)
#define Rot_Rotate_Ctrl_rotate_mask                                   (0x80000000)
#define Rot_Rotate_Ctrl_mcu_transfer_mask                             (0x40000000)
#define Rot_Rotate_Ctrl_angle_n_flip_mask                             (0x0F000000)
#define Rot_Rotate_Ctrl_rotation_done_ie_mask                         (0x00000002)
#define Rot_Rotate_Ctrl_reset_mask                                    (0x00000001)
#define Rot_Rotate_Ctrl_rotate(data)                                  (0x80000000&((data)<<31))
#define Rot_Rotate_Ctrl_mcu_transfer(data)                            (0x40000000&((data)<<30))
#define Rot_Rotate_Ctrl_angle(data)                                   (0x0C000000&((data)<<26))
#define Rot_Rotate_Ctrl_v_flip(data)                                  (0x02000000&((data)<<25))
#define Rot_Rotate_Ctrl_h_flip(data)                                  (0x01000000&((data)<<24))
#define Rot_Rotate_Ctrl_rotation_done_ie(data)                        (0x00000002&((data)<<1))
#define Rot_Rotate_Ctrl_reset(data)                                   (0x00000001&(data))
#define Rot_Rotate_Ctrl_get_rotate(data)                              ((0x80000000&(data))>>31)
#define Rot_Rotate_Ctrl_get_mcu_transfer(data)                        ((0x40000000&(data))>>30)
#define Rot_Rotate_Ctrl_get_angle(data)                               ((0x0C000000&(data))>>26)
#define Rot_Rotate_Ctrl_get_v_flip(data)                              ((0x02000000&(data))>>25)
#define Rot_Rotate_Ctrl_get_h_flip(data)                              ((0x01000000&(data))>>24)
#define Rot_Rotate_Ctrl_get_rotation_done_ie(data)                    ((0x00000002&(data))>>1)
#define Rot_Rotate_Ctrl_get_reset(data)                               (0x00000001&(data))

#define Rot_Rotate_Status                                             0x1803681C
#define Rot_Rotate_Status_reg_addr                                    "0xB803681C"
#define ROT_ROTATE_STATUS_reg                                         0xB803681C
#define Rot_Rotate_Status_inst_addr                                   "0x0007"
#define Rot_Rotate_Status_inst                                        0x0007
#define Rot_Rotate_Status_rotate_done_shift                           (31)
#define Rot_Rotate_Status_rotate_done_mask                            (0x80000000)
#define Rot_Rotate_Status_rotate_done(data)                           (0x80000000&((data)<<31))
#define Rot_Rotate_Status_get_rotate_done(data)                       ((0x80000000&(data))>>31)

#define Rot_Rotate_Bist_Ctrl                                          0x18036820
#define Rot_Rotate_Bist_Ctrl_reg_addr                                 "0xB8036820"
#define ROT_ROTATE_BIST_CTRL_reg                                      0xB8036820
#define Rot_Rotate_Bist_Ctrl_inst_addr                                "0x0008"
#define Rot_Rotate_Bist_Ctrl_inst                                     0x0008
#define Rot_Rotate_Bist_Ctrl_bist_rstn_shift                          (31)
#define Rot_Rotate_Bist_Ctrl_bist_mode_shift                          (30)
#define Rot_Rotate_Bist_Ctrl_bist_rstn_mask                           (0x80000000)
#define Rot_Rotate_Bist_Ctrl_bist_mode_mask                           (0x40000000)
#define Rot_Rotate_Bist_Ctrl_bist_rstn(data)                          (0x80000000&((data)<<31))
#define Rot_Rotate_Bist_Ctrl_bist_mode(data)                          (0x40000000&((data)<<30))
#define Rot_Rotate_Bist_Ctrl_get_bist_rstn(data)                      ((0x80000000&(data))>>31)
#define Rot_Rotate_Bist_Ctrl_get_bist_mode(data)                      ((0x40000000&(data))>>30)

#define ROT_ROTATE_BIST_STATUS                                        0x18036824
#define Rot_Rotate_Bist_Status_reg_addr                               "0xB8036824"
#define ROT_ROTATE_BIST_STATUS_reg                                    0xB8036824
#define Rot_Rotate_Bist_Status_inst_addr                              "0x0009"
#define Rot_Rotate_Bist_Status_inst                                   0x0009
#define Rot_Rotate_Bist_Status_bist_done_shift                        (31)
#define Rot_Rotate_Bist_Status_bist_fail_shift                        (30)
#define Rot_Rotate_Bist_Status_bist_done_mask                         (0x80000000)
#define Rot_Rotate_Bist_Status_bist_fail_mask                         (0x40000000)
#define Rot_Rotate_Bist_Status_bist_done(data)                        (0x80000000&((data)<<31))
#define Rot_Rotate_Bist_Status_bist_fail(data)                        (0x40000000&((data)<<30))
#define Rot_Rotate_Bist_Status_get_bist_done(data)                    ((0x80000000&(data))>>31)
#define Rot_Rotate_Bist_Status_get_bist_fail(data)                    ((0x40000000&(data))>>30)




#define SRCCPYMODIFY_CHECK_BITMASK                                    0x18036040
#define SRCCPYMODIFY_CHECK_BITMASK_reg_addr                           "0xb8036040"
#define SRCCPYMODIFY_CHECK_BITMASK_reg                                0xb8036040
#define SRCCPYMODIFY_CHECK_BITMASK_inst_addr                          "0x0010"
#define SRCCPYMODIFY_CHECK_BITMASK_inst                               0x0010
#define SRCCPYMODIFY_CHECK_BITMASK_modifybitmask_shift                (0)
#define SRCCPYMODIFY_CHECK_BITMASK_modifybitmask_mask                 (0xFFFFFFFF)
#define SRCCPYMODIFY_CHECK_BITMASK_modifybitmask(data)                (0xFFFFFFFF&(data))
#define SRCCPYMODIFY_CHECK_BITMASK_get_modifybitmask(data)            (0xFFFFFFFF&(data))


#define SRCCPYMODIFY_CHECK_VALUE                                      0x18036044
#define SRCCPYMODIFY_CHECK_VALUE_reg_addr                             "0xb8036044"
#define SRCCPYMODIFY_CHECK_VALUE_reg                                  0xb8036044
#define SRCCPYMODIFY_CHECK_VALUE_inst_addr                            "0x0011"
#define SRCCPYMODIFY_CHECK_VALUE_inst                                 0x0011
#define SRCCPYMODIFY_CHECK_VALUE_modifyvalue_shift                    (0)
#define SRCCPYMODIFY_CHECK_VALUE_modifyvalue_mask                     (0xFFFFFFFF)
#define SRCCPYMODIFY_CHECK_VALUE_modifyvalue(data)                    (0xFFFFFFFF&(data))
#define SRCCPYMODIFY_CHECK_VALUE_get_modifyvalue(data)                (0xFFFFFFFF&(data))


#define SRCCPYMODIFY_MODIFY_BITMASK                                   0x18036048
#define SRCCPYMODIFY_MODIFY_BITMASK_reg_addr                          "0xb8036048"
#define SRCCPYMODIFY_MODIFY_BITMASK_reg                               0xb8036048
#define SRCCPYMODIFY_MODIFY_BITMASK_inst_addr                         "0x0012"
#define SRCCPYMODIFY_MODIFY_BITMASK_inst                              0x0012
#define SRCCPYMODIFY_MODIFY_BITMASK_modifybitmask_shift               (0)
#define SRCCPYMODIFY_MODIFY_BITMASK_modifybitmask_mask                (0xFFFFFFFF)
#define SRCCPYMODIFY_MODIFY_BITMASK_modifybitmask(data)               (0xFFFFFFFF&(data))
#define SRCCPYMODIFY_MODIFY_BITMASK_get_modifybitmask(data)           (0xFFFFFFFF&(data))


#define SRCCPYMODIFY_MODIFY_VALUE                                     0x1803604c
#define SRCCPYMODIFY_MODIFY_VALUE_reg_addr                            "0xb803604c"
#define SRCCPYMODIFY_MODIFY_VALUE_reg                                 0xb803604c
#define SRCCPYMODIFY_MODIFY_VALUE_inst_addr                           "0x0013"
#define SRCCPYMODIFY_MODIFY_VALUE_inst                                0x0013
#define SRCCPYMODIFY_MODIFY_VALUE_modifyvalue_shift                   (0)
#define SRCCPYMODIFY_MODIFY_VALUE_modifyvalue_mask                    (0xFFFFFFFF)
#define SRCCPYMODIFY_MODIFY_VALUE_modifyvalue(data)                   (0xFFFFFFFF&(data))
#define SRCCPYMODIFY_MODIFY_VALUE_get_modifyvalue(data)               (0xFFFFFFFF&(data))

#endif
