// This file is generated using the spec version 1.39, firmware template version 1.39and SRIF Parser                                                                                source code SVN rev:768                    Version flow no.:1.0.254
#ifndef _SRCCPY_REG_H_INCLUDED_
#define _SRCCPY_REG_H_INCLUDED_

//#define  _SRCCPY_USE_STRUCT
#ifdef _SRCCPY_USE_STRUCT

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    startaddress:28;
}SRCCPYSRC_0;

typedef struct
{
    unsigned int    reserved_0:6;
    unsigned int    srccpysrcoffset:14;
    unsigned int    reserved_1:8;
    unsigned int    pixelformat:4;
}SRCCPYSRC_1;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    picwidht:12;
    unsigned int    reserved_1:4;
    unsigned int    picheight:12;
}SRCCPYLEN;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    startaddress:28;
}SRCCPYDST_0;

typedef struct
{
    unsigned int    reserved_0:6;
    unsigned int    srccpydstoffset:14;
    unsigned int    reserved_1:8;
    unsigned int    pixelformat:4;
}SRCCPYDST_1;

typedef struct
{
    unsigned int    srccpy_start:1;
    unsigned int    reserved_0:3;
    unsigned int    srccpy_function_sel:2;
    unsigned int    reserved_1:24;
    unsigned int    rotation_done_ie:1;
    unsigned int    reset:1;
}SRCCPY_ctrl;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    srccpy_enable:1;
}SRCCPY_enable;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    srccpy_int_pending:1;
}SRCCPY_int_status;

typedef struct
{
    unsigned int    bist_rstn:1;
    unsigned int    bist_mode:1;
    unsigned int    reserved_0:30;
}SRCCPY_bist_ctrl;

typedef struct
{
    unsigned int    bist_done:1;
    unsigned int    bist_fail:1;
    unsigned int    reserved_0:30;
}SRCCPY_bist_status;

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


#define SRCCPYSRC_0                                                   0x18036000
#define SRCCPYSRC_0_reg_addr                                          "0xb8036000"
#define SRCCPYSRC_0_reg                                               0xb8036000
#define SRCCPYSRC_0_inst_addr                                         "0x0000"
#define SRCCPYSRC_0_inst                                              0x0000
#define SRCCPYSRC_0_startaddress_shift                                (0)
#define SRCCPYSRC_0_startaddress_mask                                 (0x0FFFFFFF)
#define SRCCPYSRC_0_startaddress(data)                                (0x0FFFFFFF&(data))
#define SRCCPYSRC_0_get_startaddress(data)                            (0x0FFFFFFF&(data))


#define SRCCPYSRC_1                                                   0x18036004
#define SRCCPYSRC_1_reg_addr                                          "0xb8036004"
#define SRCCPYSRC_1_reg                                               0xb8036004
#define SRCCPYSRC_1_inst_addr                                         "0x0001"
#define SRCCPYSRC_1_inst                                              0x0001
#define SRCCPYSRC_1_srccpysrcoffset_shift                             (12)
#define SRCCPYSRC_1_pixelformat_shift                                 (0)
#define SRCCPYSRC_1_srccpysrcoffset_mask                              (0x03FFF000)
#define SRCCPYSRC_1_pixelformat_mask                                  (0x0000000F)
#define SRCCPYSRC_1_srccpysrcoffset(data)                             (0x03FFF000&((data)<<12))
#define SRCCPYSRC_1_pixelformat(data)                                 (0x0000000F&(data))
#define SRCCPYSRC_1_get_srccpysrcoffset(data)                         ((0x03FFF000&(data))>>12)
#define SRCCPYSRC_1_get_pixelformat(data)                             (0x0000000F&(data))


#define SRCCPYLEN                                                     0x18036008
#define SRCCPYLEN_reg_addr                                            "0xb8036008"
#define SRCCPYLEN_reg                                                 0xb8036008
#define SRCCPYLEN_inst_addr                                           "0x0002"
#define SRCCPYLEN_inst                                                0x0002
#define SRCCPYLEN_picwidht_shift                                      (16)
#define SRCCPYLEN_picheight_shift                                     (0)
#define SRCCPYLEN_picwidht_mask                                       (0x0FFF0000)
#define SRCCPYLEN_picheight_mask                                      (0x00000FFF)
#define SRCCPYLEN_picwidht(data)                                      (0x0FFF0000&((data)<<16))
#define SRCCPYLEN_picheight(data)                                     (0x00000FFF&(data))
#define SRCCPYLEN_get_picwidht(data)                                  ((0x0FFF0000&(data))>>16)
#define SRCCPYLEN_get_picheight(data)                                 (0x00000FFF&(data))


#define SRCCPYDST_0                                                   0x1803600c
#define SRCCPYDST_0_reg_addr                                          "0xb803600c"
#define SRCCPYDST_0_reg                                               0xb803600c
#define SRCCPYDST_0_inst_addr                                         "0x0003"
#define SRCCPYDST_0_inst                                              0x0003
#define SRCCPYDST_0_startaddress_shift                                (0)
#define SRCCPYDST_0_startaddress_mask                                 (0x0FFFFFFF)
#define SRCCPYDST_0_startaddress(data)                                (0x0FFFFFFF&(data))
#define SRCCPYDST_0_get_startaddress(data)                            (0x0FFFFFFF&(data))


#define SRCCPYDST_1                                                   0x18036010
#define SRCCPYDST_1_reg_addr                                          "0xb8036010"
#define SRCCPYDST_1_reg                                               0xb8036010
#define SRCCPYDST_1_inst_addr                                         "0x0004"
#define SRCCPYDST_1_inst                                              0x0004
#define SRCCPYDST_1_srccpydstoffset_shift                             (12)
#define SRCCPYDST_1_pixelformat_shift                                 (0)
#define SRCCPYDST_1_srccpydstoffset_mask                              (0x03FFF000)
#define SRCCPYDST_1_pixelformat_mask                                  (0x0000000F)
#define SRCCPYDST_1_srccpydstoffset(data)                             (0x03FFF000&((data)<<12))
#define SRCCPYDST_1_pixelformat(data)                                 (0x0000000F&(data))
#define SRCCPYDST_1_get_srccpydstoffset(data)                         ((0x03FFF000&(data))>>12)
#define SRCCPYDST_1_get_pixelformat(data)                             (0x0000000F&(data))


#define SRCCPY_CTRL                                                   0x18036018
#define SRCCPY_CTRL_reg_addr                                          "0xb8036018"
#define SRCCPY_CTRL_reg                                               0xb8036018
#define SRCCPY_CTRL_inst_addr                                         "0x0006"
#define SRCCPY_CTRL_inst                                              0x0006
#define SRCCPY_CTRL_srccpy_start_shift                                (31)
#define SRCCPY_CTRL_srccpy_function_sel_shift                         (26)
#define SRCCPY_CTRL_rotation_done_ie_shift                            (1)
#define SRCCPY_CTRL_reset_shift                                       (0)
#define SRCCPY_CTRL_srccpy_start_mask                                 (0x80000000)
#define SRCCPY_CTRL_srccpy_function_sel_mask                          (0x0C000000)
#define SRCCPY_CTRL_rotation_done_ie_mask                             (0x00000002)
#define SRCCPY_CTRL_reset_mask                                        (0x00000001)
#define SRCCPY_CTRL_srccpy_start(data)                                (0x80000000&((data)<<31))
#define SRCCPY_CTRL_srccpy_function_sel(data)                         (0x0C000000&((data)<<26))
#define SRCCPY_CTRL_rotation_done_ie(data)                            (0x00000002&((data)<<1))
#define SRCCPY_CTRL_reset(data)                                       (0x00000001&(data))
#define SRCCPY_CTRL_get_srccpy_start(data)                            ((0x80000000&(data))>>31)
#define SRCCPY_CTRL_get_srccpy_function_sel(data)                     ((0x0C000000&(data))>>26)
#define SRCCPY_CTRL_get_rotation_done_ie(data)                        ((0x00000002&(data))>>1)
#define SRCCPY_CTRL_get_reset(data)                                   (0x00000001&(data))


#define SRCCPY_ENABLE                                                 0x18036028
#define SRCCPY_ENABLE_reg_addr                                        "0xb8036028"
#define SRCCPY_ENABLE_reg                                             0xb8036028
#define SRCCPY_ENABLE_inst_addr                                       "0x000A"
#define SRCCPY_ENABLE_inst                                            0x000A
#define SRCCPY_ENABLE_srccpy_enable_shift                             (0)
#define SRCCPY_ENABLE_srccpy_enable_mask                              (0x00000001)
#define SRCCPY_ENABLE_srccpy_enable(data)                             (0x00000001&(data))
#define SRCCPY_ENABLE_get_srccpy_enable(data)                         (0x00000001&(data))


#define SRCCPY_INT_STATUS                                             0x18036030
#define SRCCPY_INT_STATUS_reg_addr                                    "0xb8036030"
#define SRCCPY_INT_STATUS_reg                                         0xb8036030
#define SRCCPY_INT_STATUS_inst_addr                                   "0x000C"
#define SRCCPY_INT_STATUS_inst                                        0x000C
#define SRCCPY_INT_STATUS_srccpy_int_pending_shift                    (0)
#define SRCCPY_INT_STATUS_srccpy_int_pending_mask                     (0x00000001)
#define SRCCPY_INT_STATUS_srccpy_int_pending(data)                    (0x00000001&(data))
#define SRCCPY_INT_STATUS_get_srccpy_int_pending(data)                (0x00000001&(data))


#define SRCCPY_BIST_CTRL                                              0x18036034
#define SRCCPY_BIST_CTRL_reg_addr                                     "0xb8036034"
#define SRCCPY_BIST_CTRL_reg                                          0xb8036034
#define SRCCPY_BIST_CTRL_inst_addr                                    "0x000D"
#define SRCCPY_BIST_CTRL_inst                                         0x000D
#define SRCCPY_BIST_CTRL_bist_rstn_shift                              (31)
#define SRCCPY_BIST_CTRL_bist_mode_shift                              (30)
#define SRCCPY_BIST_CTRL_bist_rstn_mask                               (0x80000000)
#define SRCCPY_BIST_CTRL_bist_mode_mask                               (0x40000000)
#define SRCCPY_BIST_CTRL_bist_rstn(data)                              (0x80000000&((data)<<31))
#define SRCCPY_BIST_CTRL_bist_mode(data)                              (0x40000000&((data)<<30))
#define SRCCPY_BIST_CTRL_get_bist_rstn(data)                          ((0x80000000&(data))>>31)
#define SRCCPY_BIST_CTRL_get_bist_mode(data)                          ((0x40000000&(data))>>30)


#define SRCCPY_BIST_STATUS                                            0x18036038
#define SRCCPY_BIST_STATUS_reg_addr                                   "0xb8036038"
#define SRCCPY_BIST_STATUS_reg                                        0xb8036038
#define SRCCPY_BIST_STATUS_inst_addr                                  "0x000E"
#define SRCCPY_BIST_STATUS_inst                                       0x000E
#define SRCCPY_BIST_STATUS_bist_done_shift                            (31)
#define SRCCPY_BIST_STATUS_bist_fail_shift                            (30)
#define SRCCPY_BIST_STATUS_bist_done_mask                             (0x80000000)
#define SRCCPY_BIST_STATUS_bist_fail_mask                             (0x40000000)
#define SRCCPY_BIST_STATUS_bist_done(data)                            (0x80000000&((data)<<31))
#define SRCCPY_BIST_STATUS_bist_fail(data)                            (0x40000000&((data)<<30))
#define SRCCPY_BIST_STATUS_get_bist_done(data)                        ((0x80000000&(data))>>31)
#define SRCCPY_BIST_STATUS_get_bist_fail(data)                        ((0x40000000&(data))>>30)


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
