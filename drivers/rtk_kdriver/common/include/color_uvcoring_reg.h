/**
* @file Mac5-DesignSpec-D-Domain_UV_Coring
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_COLOR_UVCORING_REG_H_
#define _RBUS_COLOR_UVCORING_REG_H_

#include "rbus_types.h"



//  COLOR_UVCORING Register Address
#define  COLOR_UVCORING_UVC_CONTROL                                              0x1802AB00
#define  COLOR_UVCORING_UVC_CONTROL_reg_addr                                     "0xB802AB00"
#define  COLOR_UVCORING_UVC_CONTROL_reg                                          0xB802AB00
#define  COLOR_UVCORING_UVC_CONTROL_inst_addr                                    "0x0000"
#define  set_COLOR_UVCORING_UVC_CONTROL_reg(data)                                (*((volatile unsigned int*)COLOR_UVCORING_UVC_CONTROL_reg)=data)
#define  get_COLOR_UVCORING_UVC_CONTROL_reg                                      (*((volatile unsigned int*)COLOR_UVCORING_UVC_CONTROL_reg))
#define  COLOR_UVCORING_UVC_CONTROL_dummy_31_28_shift                            (28)
#define  COLOR_UVCORING_UVC_CONTROL_uvc_yslope_shift                             (18)
#define  COLOR_UVCORING_UVC_CONTROL_uvc_y0_shift                                 (8)
#define  COLOR_UVCORING_UVC_CONTROL_uvc_qdrt4_en_shift                           (7)
#define  COLOR_UVCORING_UVC_CONTROL_uvc_qdrt3_en_shift                           (6)
#define  COLOR_UVCORING_UVC_CONTROL_uvc_qdrt2_en_shift                           (5)
#define  COLOR_UVCORING_UVC_CONTROL_uvc_qdrt1_en_shift                           (4)
#define  COLOR_UVCORING_UVC_CONTROL_uvc_skin_sel_shift                           (3)
#define  COLOR_UVCORING_UVC_CONTROL_uvc_main_en_shift                            (0)
#define  COLOR_UVCORING_UVC_CONTROL_dummy_31_28_mask                             (0xF0000000)
#define  COLOR_UVCORING_UVC_CONTROL_uvc_yslope_mask                              (0x0FFC0000)
#define  COLOR_UVCORING_UVC_CONTROL_uvc_y0_mask                                  (0x0003FF00)
#define  COLOR_UVCORING_UVC_CONTROL_uvc_qdrt4_en_mask                            (0x00000080)
#define  COLOR_UVCORING_UVC_CONTROL_uvc_qdrt3_en_mask                            (0x00000040)
#define  COLOR_UVCORING_UVC_CONTROL_uvc_qdrt2_en_mask                            (0x00000020)
#define  COLOR_UVCORING_UVC_CONTROL_uvc_qdrt1_en_mask                            (0x00000010)
#define  COLOR_UVCORING_UVC_CONTROL_uvc_skin_sel_mask                            (0x00000008)
#define  COLOR_UVCORING_UVC_CONTROL_uvc_main_en_mask                             (0x00000001)
#define  COLOR_UVCORING_UVC_CONTROL_dummy_31_28(data)                            (0xF0000000&((data)<<28))
#define  COLOR_UVCORING_UVC_CONTROL_uvc_yslope(data)                             (0x0FFC0000&((data)<<18))
#define  COLOR_UVCORING_UVC_CONTROL_uvc_y0(data)                                 (0x0003FF00&((data)<<8))
#define  COLOR_UVCORING_UVC_CONTROL_uvc_qdrt4_en(data)                           (0x00000080&((data)<<7))
#define  COLOR_UVCORING_UVC_CONTROL_uvc_qdrt3_en(data)                           (0x00000040&((data)<<6))
#define  COLOR_UVCORING_UVC_CONTROL_uvc_qdrt2_en(data)                           (0x00000020&((data)<<5))
#define  COLOR_UVCORING_UVC_CONTROL_uvc_qdrt1_en(data)                           (0x00000010&((data)<<4))
#define  COLOR_UVCORING_UVC_CONTROL_uvc_skin_sel(data)                           (0x00000008&((data)<<3))
#define  COLOR_UVCORING_UVC_CONTROL_uvc_main_en(data)                            (0x00000001&(data))
#define  COLOR_UVCORING_UVC_CONTROL_get_dummy_31_28(data)                        ((0xF0000000&(data))>>28)
#define  COLOR_UVCORING_UVC_CONTROL_get_uvc_yslope(data)                         ((0x0FFC0000&(data))>>18)
#define  COLOR_UVCORING_UVC_CONTROL_get_uvc_y0(data)                             ((0x0003FF00&(data))>>8)
#define  COLOR_UVCORING_UVC_CONTROL_get_uvc_qdrt4_en(data)                       ((0x00000080&(data))>>7)
#define  COLOR_UVCORING_UVC_CONTROL_get_uvc_qdrt3_en(data)                       ((0x00000040&(data))>>6)
#define  COLOR_UVCORING_UVC_CONTROL_get_uvc_qdrt2_en(data)                       ((0x00000020&(data))>>5)
#define  COLOR_UVCORING_UVC_CONTROL_get_uvc_qdrt1_en(data)                       ((0x00000010&(data))>>4)
#define  COLOR_UVCORING_UVC_CONTROL_get_uvc_skin_sel(data)                       ((0x00000008&(data))>>3)
#define  COLOR_UVCORING_UVC_CONTROL_get_uvc_main_en(data)                        (0x00000001&(data))

#define  COLOR_UVCORING_UVC_GLOBAL_U                                             0x1802AB04
#define  COLOR_UVCORING_UVC_GLOBAL_U_reg_addr                                    "0xB802AB04"
#define  COLOR_UVCORING_UVC_GLOBAL_U_reg                                         0xB802AB04
#define  COLOR_UVCORING_UVC_GLOBAL_U_inst_addr                                   "0x0001"
#define  set_COLOR_UVCORING_UVC_GLOBAL_U_reg(data)                               (*((volatile unsigned int*)COLOR_UVCORING_UVC_GLOBAL_U_reg)=data)
#define  get_COLOR_UVCORING_UVC_GLOBAL_U_reg                                     (*((volatile unsigned int*)COLOR_UVCORING_UVC_GLOBAL_U_reg))
#define  COLOR_UVCORING_UVC_GLOBAL_U_uvc_u_slope2_g_shift                        (24)
#define  COLOR_UVCORING_UVC_GLOBAL_U_uvc_u_thd2_g_shift                          (16)
#define  COLOR_UVCORING_UVC_GLOBAL_U_uvc_u_slope1_g_shift                        (8)
#define  COLOR_UVCORING_UVC_GLOBAL_U_uvc_u_thd1_g_shift                          (0)
#define  COLOR_UVCORING_UVC_GLOBAL_U_uvc_u_slope2_g_mask                         (0xFF000000)
#define  COLOR_UVCORING_UVC_GLOBAL_U_uvc_u_thd2_g_mask                           (0x003F0000)
#define  COLOR_UVCORING_UVC_GLOBAL_U_uvc_u_slope1_g_mask                         (0x0000FF00)
#define  COLOR_UVCORING_UVC_GLOBAL_U_uvc_u_thd1_g_mask                           (0x0000003F)
#define  COLOR_UVCORING_UVC_GLOBAL_U_uvc_u_slope2_g(data)                        (0xFF000000&((data)<<24))
#define  COLOR_UVCORING_UVC_GLOBAL_U_uvc_u_thd2_g(data)                          (0x003F0000&((data)<<16))
#define  COLOR_UVCORING_UVC_GLOBAL_U_uvc_u_slope1_g(data)                        (0x0000FF00&((data)<<8))
#define  COLOR_UVCORING_UVC_GLOBAL_U_uvc_u_thd1_g(data)                          (0x0000003F&(data))
#define  COLOR_UVCORING_UVC_GLOBAL_U_get_uvc_u_slope2_g(data)                    ((0xFF000000&(data))>>24)
#define  COLOR_UVCORING_UVC_GLOBAL_U_get_uvc_u_thd2_g(data)                      ((0x003F0000&(data))>>16)
#define  COLOR_UVCORING_UVC_GLOBAL_U_get_uvc_u_slope1_g(data)                    ((0x0000FF00&(data))>>8)
#define  COLOR_UVCORING_UVC_GLOBAL_U_get_uvc_u_thd1_g(data)                      (0x0000003F&(data))

#define  COLOR_UVCORING_UVC_GLOBAL_V                                             0x1802AB08
#define  COLOR_UVCORING_UVC_GLOBAL_V_reg_addr                                    "0xB802AB08"
#define  COLOR_UVCORING_UVC_GLOBAL_V_reg                                         0xB802AB08
#define  COLOR_UVCORING_UVC_GLOBAL_V_inst_addr                                   "0x0002"
#define  set_COLOR_UVCORING_UVC_GLOBAL_V_reg(data)                               (*((volatile unsigned int*)COLOR_UVCORING_UVC_GLOBAL_V_reg)=data)
#define  get_COLOR_UVCORING_UVC_GLOBAL_V_reg                                     (*((volatile unsigned int*)COLOR_UVCORING_UVC_GLOBAL_V_reg))
#define  COLOR_UVCORING_UVC_GLOBAL_V_uvc_v_slope2_g_shift                        (24)
#define  COLOR_UVCORING_UVC_GLOBAL_V_uvc_v_thd2_g_shift                          (16)
#define  COLOR_UVCORING_UVC_GLOBAL_V_uvc_v_slope1_g_shift                        (8)
#define  COLOR_UVCORING_UVC_GLOBAL_V_uvc_v_thd1_g_shift                          (0)
#define  COLOR_UVCORING_UVC_GLOBAL_V_uvc_v_slope2_g_mask                         (0xFF000000)
#define  COLOR_UVCORING_UVC_GLOBAL_V_uvc_v_thd2_g_mask                           (0x003F0000)
#define  COLOR_UVCORING_UVC_GLOBAL_V_uvc_v_slope1_g_mask                         (0x0000FF00)
#define  COLOR_UVCORING_UVC_GLOBAL_V_uvc_v_thd1_g_mask                           (0x0000003F)
#define  COLOR_UVCORING_UVC_GLOBAL_V_uvc_v_slope2_g(data)                        (0xFF000000&((data)<<24))
#define  COLOR_UVCORING_UVC_GLOBAL_V_uvc_v_thd2_g(data)                          (0x003F0000&((data)<<16))
#define  COLOR_UVCORING_UVC_GLOBAL_V_uvc_v_slope1_g(data)                        (0x0000FF00&((data)<<8))
#define  COLOR_UVCORING_UVC_GLOBAL_V_uvc_v_thd1_g(data)                          (0x0000003F&(data))
#define  COLOR_UVCORING_UVC_GLOBAL_V_get_uvc_v_slope2_g(data)                    ((0xFF000000&(data))>>24)
#define  COLOR_UVCORING_UVC_GLOBAL_V_get_uvc_v_thd2_g(data)                      ((0x003F0000&(data))>>16)
#define  COLOR_UVCORING_UVC_GLOBAL_V_get_uvc_v_slope1_g(data)                    ((0x0000FF00&(data))>>8)
#define  COLOR_UVCORING_UVC_GLOBAL_V_get_uvc_v_thd1_g(data)                      (0x0000003F&(data))

#define  COLOR_UVCORING_UVC_SKIN_U                                               0x1802AB0C
#define  COLOR_UVCORING_UVC_SKIN_U_reg_addr                                      "0xB802AB0C"
#define  COLOR_UVCORING_UVC_SKIN_U_reg                                           0xB802AB0C
#define  COLOR_UVCORING_UVC_SKIN_U_inst_addr                                     "0x0003"
#define  set_COLOR_UVCORING_UVC_SKIN_U_reg(data)                                 (*((volatile unsigned int*)COLOR_UVCORING_UVC_SKIN_U_reg)=data)
#define  get_COLOR_UVCORING_UVC_SKIN_U_reg                                       (*((volatile unsigned int*)COLOR_UVCORING_UVC_SKIN_U_reg))
#define  COLOR_UVCORING_UVC_SKIN_U_uvc_u_slope2_sk_shift                         (24)
#define  COLOR_UVCORING_UVC_SKIN_U_uvc_u_thd2_sk_shift                           (16)
#define  COLOR_UVCORING_UVC_SKIN_U_uvc_u_slope1_sk_shift                         (8)
#define  COLOR_UVCORING_UVC_SKIN_U_uvc_u_thd1_sk_shift                           (0)
#define  COLOR_UVCORING_UVC_SKIN_U_uvc_u_slope2_sk_mask                          (0xFF000000)
#define  COLOR_UVCORING_UVC_SKIN_U_uvc_u_thd2_sk_mask                            (0x003F0000)
#define  COLOR_UVCORING_UVC_SKIN_U_uvc_u_slope1_sk_mask                          (0x0000FF00)
#define  COLOR_UVCORING_UVC_SKIN_U_uvc_u_thd1_sk_mask                            (0x0000003F)
#define  COLOR_UVCORING_UVC_SKIN_U_uvc_u_slope2_sk(data)                         (0xFF000000&((data)<<24))
#define  COLOR_UVCORING_UVC_SKIN_U_uvc_u_thd2_sk(data)                           (0x003F0000&((data)<<16))
#define  COLOR_UVCORING_UVC_SKIN_U_uvc_u_slope1_sk(data)                         (0x0000FF00&((data)<<8))
#define  COLOR_UVCORING_UVC_SKIN_U_uvc_u_thd1_sk(data)                           (0x0000003F&(data))
#define  COLOR_UVCORING_UVC_SKIN_U_get_uvc_u_slope2_sk(data)                     ((0xFF000000&(data))>>24)
#define  COLOR_UVCORING_UVC_SKIN_U_get_uvc_u_thd2_sk(data)                       ((0x003F0000&(data))>>16)
#define  COLOR_UVCORING_UVC_SKIN_U_get_uvc_u_slope1_sk(data)                     ((0x0000FF00&(data))>>8)
#define  COLOR_UVCORING_UVC_SKIN_U_get_uvc_u_thd1_sk(data)                       (0x0000003F&(data))

#define  COLOR_UVCORING_UVC_SKIN_V                                               0x1802AB10
#define  COLOR_UVCORING_UVC_SKIN_V_reg_addr                                      "0xB802AB10"
#define  COLOR_UVCORING_UVC_SKIN_V_reg                                           0xB802AB10
#define  COLOR_UVCORING_UVC_SKIN_V_inst_addr                                     "0x0004"
#define  set_COLOR_UVCORING_UVC_SKIN_V_reg(data)                                 (*((volatile unsigned int*)COLOR_UVCORING_UVC_SKIN_V_reg)=data)
#define  get_COLOR_UVCORING_UVC_SKIN_V_reg                                       (*((volatile unsigned int*)COLOR_UVCORING_UVC_SKIN_V_reg))
#define  COLOR_UVCORING_UVC_SKIN_V_uvc_v_slope2_sk_shift                         (24)
#define  COLOR_UVCORING_UVC_SKIN_V_uvc_v_thd2_sk_shift                           (16)
#define  COLOR_UVCORING_UVC_SKIN_V_uvc_v_slope1_sk_shift                         (8)
#define  COLOR_UVCORING_UVC_SKIN_V_uvc_v_thd1_sk_shift                           (0)
#define  COLOR_UVCORING_UVC_SKIN_V_uvc_v_slope2_sk_mask                          (0xFF000000)
#define  COLOR_UVCORING_UVC_SKIN_V_uvc_v_thd2_sk_mask                            (0x003F0000)
#define  COLOR_UVCORING_UVC_SKIN_V_uvc_v_slope1_sk_mask                          (0x0000FF00)
#define  COLOR_UVCORING_UVC_SKIN_V_uvc_v_thd1_sk_mask                            (0x0000003F)
#define  COLOR_UVCORING_UVC_SKIN_V_uvc_v_slope2_sk(data)                         (0xFF000000&((data)<<24))
#define  COLOR_UVCORING_UVC_SKIN_V_uvc_v_thd2_sk(data)                           (0x003F0000&((data)<<16))
#define  COLOR_UVCORING_UVC_SKIN_V_uvc_v_slope1_sk(data)                         (0x0000FF00&((data)<<8))
#define  COLOR_UVCORING_UVC_SKIN_V_uvc_v_thd1_sk(data)                           (0x0000003F&(data))
#define  COLOR_UVCORING_UVC_SKIN_V_get_uvc_v_slope2_sk(data)                     ((0xFF000000&(data))>>24)
#define  COLOR_UVCORING_UVC_SKIN_V_get_uvc_v_thd2_sk(data)                       ((0x003F0000&(data))>>16)
#define  COLOR_UVCORING_UVC_SKIN_V_get_uvc_v_slope1_sk(data)                     ((0x0000FF00&(data))>>8)
#define  COLOR_UVCORING_UVC_SKIN_V_get_uvc_v_thd1_sk(data)                       (0x0000003F&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======COLOR_UVCORING register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802ab00_31_28:4;
        RBus_UInt32  uvc_yslope:10;
        RBus_UInt32  uvc_y0:10;
        RBus_UInt32  uvc_qdrt4_en:1;
        RBus_UInt32  uvc_qdrt3_en:1;
        RBus_UInt32  uvc_qdrt2_en:1;
        RBus_UInt32  uvc_qdrt1_en:1;
        RBus_UInt32  uvc_skin_sel:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  uvc_main_en:1;
    };
}color_uvcoring_uvc_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uvc_u_slope2_g:8;
        RBus_UInt32  res1:2;
        RBus_UInt32  uvc_u_thd2_g:6;
        RBus_UInt32  uvc_u_slope1_g:8;
        RBus_UInt32  res2:2;
        RBus_UInt32  uvc_u_thd1_g:6;
    };
}color_uvcoring_uvc_global_u_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uvc_v_slope2_g:8;
        RBus_UInt32  res1:2;
        RBus_UInt32  uvc_v_thd2_g:6;
        RBus_UInt32  uvc_v_slope1_g:8;
        RBus_UInt32  res2:2;
        RBus_UInt32  uvc_v_thd1_g:6;
    };
}color_uvcoring_uvc_global_v_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uvc_u_slope2_sk:8;
        RBus_UInt32  res1:2;
        RBus_UInt32  uvc_u_thd2_sk:6;
        RBus_UInt32  uvc_u_slope1_sk:8;
        RBus_UInt32  res2:2;
        RBus_UInt32  uvc_u_thd1_sk:6;
    };
}color_uvcoring_uvc_skin_u_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uvc_v_slope2_sk:8;
        RBus_UInt32  res1:2;
        RBus_UInt32  uvc_v_thd2_sk:6;
        RBus_UInt32  uvc_v_slope1_sk:8;
        RBus_UInt32  res2:2;
        RBus_UInt32  uvc_v_thd1_sk:6;
    };
}color_uvcoring_uvc_skin_v_RBUS;

#else //apply LITTLE_ENDIAN

//======COLOR_UVCORING register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uvc_main_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  uvc_skin_sel:1;
        RBus_UInt32  uvc_qdrt1_en:1;
        RBus_UInt32  uvc_qdrt2_en:1;
        RBus_UInt32  uvc_qdrt3_en:1;
        RBus_UInt32  uvc_qdrt4_en:1;
        RBus_UInt32  uvc_y0:10;
        RBus_UInt32  uvc_yslope:10;
        RBus_UInt32  dummy1802ab00_31_28:4;
    };
}color_uvcoring_uvc_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uvc_u_thd1_g:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  uvc_u_slope1_g:8;
        RBus_UInt32  uvc_u_thd2_g:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  uvc_u_slope2_g:8;
    };
}color_uvcoring_uvc_global_u_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uvc_v_thd1_g:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  uvc_v_slope1_g:8;
        RBus_UInt32  uvc_v_thd2_g:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  uvc_v_slope2_g:8;
    };
}color_uvcoring_uvc_global_v_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uvc_u_thd1_sk:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  uvc_u_slope1_sk:8;
        RBus_UInt32  uvc_u_thd2_sk:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  uvc_u_slope2_sk:8;
    };
}color_uvcoring_uvc_skin_u_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uvc_v_thd1_sk:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  uvc_v_slope1_sk:8;
        RBus_UInt32  uvc_v_thd2_sk:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  uvc_v_slope2_sk:8;
    };
}color_uvcoring_uvc_skin_v_RBUS;




#endif 


#endif 
