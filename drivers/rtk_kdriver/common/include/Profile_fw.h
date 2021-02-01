/*=============================================================
* Copyright C        Realtek Semiconductor Corporation, 2004 *
* All rights reserved.                                       *
* Build by tools[RS_MM2_SD] For FW                           *
*============================================================*/
/*======================= Description =======================*/
/*
 * @date 2014/7/30
 * @version { 1.0 }
*/

#ifndef _PROFILE_REG_H_INCLUDED_
#define _PROFILE_REG_H_INCLUDED_

//#define _PROFILE_USE_STRUCT
#ifdef _PROFILE_USE_STRUCT

typedef struct
{
        unsigned int  reserved_0:13;
        unsigned int  dummy18023400_18_16:3;
        unsigned int  en_8k4k_mode:1;
        unsigned int  en_4k2k_mode:1;
        unsigned int  en_3d_mode:1;
        unsigned int  ch1_pf_yuv_sel:2;
        unsigned int  ch1_pf_test_enable:1;
        unsigned int  ch1_pf_testmode:2;
        unsigned int  ch1_pf_hnsr:2;
        unsigned int  ch1_pf_vnsr:2;
        unsigned int  ch1_pf_field_sel:2;
        unsigned int  ch1_pf_overflow_sel:1;
        unsigned int  ch1_pf_enable_profile:1;
}ICH1_Hist_Profile_CTRL;

typedef struct
{
        unsigned int  reserved_0:6;
        unsigned int  ch1_pf_vsize:10;
        unsigned int  reserved_1:6;
        unsigned int  ch1_pf_hsize:10;
}ICH1_Hist_Profile_size;

typedef struct
{
        unsigned int  reserved_0:18;
        unsigned int  ch1_pf_starth:14;
}ICH1_Hist_Profile_StartH;

typedef struct
{
        unsigned int  reserved_0:18;
        unsigned int  ch1_pf_startv:14;
}ICH1_Hist_Profile_StartV;

typedef struct
{
        unsigned int  ch1_pf_h01:16;
        unsigned int  ch1_pf_h00:16;
}ICH1_Hist_Profile_Data_00;

typedef struct
{
        unsigned int  ch1_pf_h03:16;
        unsigned int  ch1_pf_h02:16;
}ICH1_Hist_Profile_Data_01;

typedef struct
{
        unsigned int  ch1_pf_h05:16;
        unsigned int  ch1_pf_h04:16;
}ICH1_Hist_Profile_Data_02;

typedef struct
{
        unsigned int  ch1_pf_h07:16;
        unsigned int  ch1_pf_h06:16;
}ICH1_Hist_Profile_Data_03;

typedef struct
{
        unsigned int  ch1_pf_h09:16;
        unsigned int  ch1_pf_h08:16;
}ICH1_Hist_Profile_Data_04;

typedef struct
{
        unsigned int  ch1_pf_h11:16;
        unsigned int  ch1_pf_h10:16;
}ICH1_Hist_Profile_Data_05;

typedef struct
{
        unsigned int  ch1_pf_h13:16;
        unsigned int  ch1_pf_h12:16;
}ICH1_Hist_Profile_Data_06;

typedef struct
{
        unsigned int  ch1_pf_h15:16;
        unsigned int  ch1_pf_h14:16;
}ICH1_Hist_Profile_Data_07;

typedef struct
{
        unsigned int  ch1_pf_v01:16;
        unsigned int  ch1_pf_v00:16;
}ICH1_Hist_Profile_Data_08;

typedef struct
{
        unsigned int  ch1_pf_v03:16;
        unsigned int  ch1_pf_v02:16;
}ICH1_Hist_Profile_Data_09;

typedef struct
{
        unsigned int  ch1_pf_v05:16;
        unsigned int  ch1_pf_v04:16;
}ICH1_Hist_Profile_Data_10;

typedef struct
{
        unsigned int  ch1_pf_v07:16;
        unsigned int  ch1_pf_v06:16;
}ICH1_Hist_Profile_Data_11;

typedef struct
{
        unsigned int  ch1_pf_v09:16;
        unsigned int  ch1_pf_v08:16;
}ICH1_Hist_Profile_Data_12;

typedef struct
{
        unsigned int  ch1_pf_v11:16;
        unsigned int  ch1_pf_v10:16;
}ICH1_Hist_Profile_Data_13;

typedef struct
{
        unsigned int  ch1_pf_v13:16;
        unsigned int  ch1_pf_v12:16;
}ICH1_Hist_Profile_Data_14;

typedef struct
{
        unsigned int  ch1_pf_v15:16;
        unsigned int  ch1_pf_v14:16;
}ICH1_Hist_Profile_Data_15;

typedef struct
{
        unsigned int  ch1_pf_h01_right:16;
        unsigned int  ch1_pf_h00_right:16;
}ICH1_Hist_Profile_Data_16;

typedef struct
{
        unsigned int  ch1_pf_h03_right:16;
        unsigned int  ch1_pf_h02_right:16;
}ICH1_Hist_Profile_Data_17;

typedef struct
{
        unsigned int  ch1_pf_h05_right:16;
        unsigned int  ch1_pf_h04_right:16;
}ICH1_Hist_Profile_Data_18;

typedef struct
{
        unsigned int  ch1_pf_h07_right:16;
        unsigned int  ch1_pf_h06_right:16;
}ICH1_Hist_Profile_Data_19;

typedef struct
{
        unsigned int  ch1_pf_h09_right:16;
        unsigned int  ch1_pf_h08_right:16;
}ICH1_Hist_Profile_Data_20;

typedef struct
{
        unsigned int  ch1_pf_h11_right:16;
        unsigned int  ch1_pf_h10_right:16;
}ICH1_Hist_Profile_Data_21;

typedef struct
{
        unsigned int  ch1_pf_h13_right:16;
        unsigned int  ch1_pf_h12_right:16;
}ICH1_Hist_Profile_Data_22;

typedef struct
{
        unsigned int  ch1_pf_h15_right:16;
        unsigned int  ch1_pf_h14_right:16;
}ICH1_Hist_Profile_Data_23;

typedef struct
{
        unsigned int  ch1_pf_v01_right:16;
        unsigned int  ch1_pf_v00_right:16;
}ICH1_Hist_Profile_Data_24;

typedef struct
{
        unsigned int  ch1_pf_v03_right:16;
        unsigned int  ch1_pf_v02_right:16;
}ICH1_Hist_Profile_Data_25;

typedef struct
{
        unsigned int  ch1_pf_v05_right:16;
        unsigned int  ch1_pf_v04_right:16;
}ICH1_Hist_Profile_Data_26;

typedef struct
{
        unsigned int  ch1_pf_v07_right:16;
        unsigned int  ch1_pf_v06_right:16;
}ICH1_Hist_Profile_Data_27;

typedef struct
{
        unsigned int  ch1_pf_v09_right:16;
        unsigned int  ch1_pf_v08_right:16;
}ICH1_Hist_Profile_Data_28;

typedef struct
{
        unsigned int  ch1_pf_v11_right:16;
        unsigned int  ch1_pf_v10_right:16;
}ICH1_Hist_Profile_Data_29;

typedef struct
{
        unsigned int  ch1_pf_v13_right:16;
        unsigned int  ch1_pf_v12_right:16;
}ICH1_Hist_Profile_Data_30;

typedef struct
{
        unsigned int  ch1_pf_v15_right:16;
        unsigned int  ch1_pf_v14_right:16;
}ICH1_Hist_Profile_Data_31;

#define  ICH1_Hist_Profile_CTRL                                                 0x18023400
#define  ICH1_Hist_Profile_CTRL_reg_addr                                        "0xB8023400"
#define  ICH1_Hist_Profile_CTRL_reg                                             0xB8023400
#define  ICH1_Hist_Profile_CTRL_inst_addr                                       "0x0000"
#define  ICH1_Hist_Profile_CTRL_inst                                            0x0000
#define  ICH1_Hist_Profile_CTRL_dummy_shift                                     (16)
#define  ICH1_Hist_Profile_CTRL_en_8k4k_mode_shift                              (15)
#define  ICH1_Hist_Profile_CTRL_en_4k2k_mode_shift                              (14)
#define  ICH1_Hist_Profile_CTRL_en_3d_mode_shift                                (13)
#define  ICH1_Hist_Profile_CTRL_ch1_pf_yuv_sel_shift                            (11)
#define  ICH1_Hist_Profile_CTRL_ch1_pf_test_enable_shift                        (10)
#define  ICH1_Hist_Profile_CTRL_ch1_pf_testmode_shift                           (8)
#define  ICH1_Hist_Profile_CTRL_ch1_pf_hnsr_shift                               (6)
#define  ICH1_Hist_Profile_CTRL_ch1_pf_vnsr_shift                               (4)
#define  ICH1_Hist_Profile_CTRL_ch1_pf_field_sel_shift                          (2)
#define  ICH1_Hist_Profile_CTRL_ch1_pf_overflow_sel_shift                       (1)
#define  ICH1_Hist_Profile_CTRL_ch1_pf_enable_profile_shift                     (0)
#define  ICH1_Hist_Profile_CTRL_dummy_mask                                      (0x00070000)
#define  ICH1_Hist_Profile_CTRL_en_8k4k_mode_mask                               (0x00008000)
#define  ICH1_Hist_Profile_CTRL_en_4k2k_mode_mask                               (0x00004000)
#define  ICH1_Hist_Profile_CTRL_en_3d_mode_mask                                 (0x00002000)
#define  ICH1_Hist_Profile_CTRL_ch1_pf_yuv_sel_mask                             (0x00001800)
#define  ICH1_Hist_Profile_CTRL_ch1_pf_test_enable_mask                         (0x00000400)
#define  ICH1_Hist_Profile_CTRL_ch1_pf_testmode_mask                            (0x00000300)
#define  ICH1_Hist_Profile_CTRL_ch1_pf_hnsr_mask                                (0x000000C0)
#define  ICH1_Hist_Profile_CTRL_ch1_pf_vnsr_mask                                (0x00000030)
#define  ICH1_Hist_Profile_CTRL_ch1_pf_field_sel_mask                           (0x0000000C)
#define  ICH1_Hist_Profile_CTRL_ch1_pf_overflow_sel_mask                        (0x00000002)
#define  ICH1_Hist_Profile_CTRL_ch1_pf_enable_profile_mask                      (0x00000001)
#define  ICH1_Hist_Profile_CTRL_dummy(data)                                     (0x00070000&((data)<<16))
#define  ICH1_Hist_Profile_CTRL_en_8k4k_mode(data)                              (0x00008000&((data)<<15))
#define  ICH1_Hist_Profile_CTRL_en_4k2k_mode(data)                              (0x00004000&((data)<<14))
#define  ICH1_Hist_Profile_CTRL_en_3d_mode(data)                                (0x00002000&((data)<<13))
#define  ICH1_Hist_Profile_CTRL_ch1_pf_yuv_sel(data)                            (0x00001800&((data)<<11))
#define  ICH1_Hist_Profile_CTRL_ch1_pf_test_enable(data)                        (0x00000400&((data)<<10))
#define  ICH1_Hist_Profile_CTRL_ch1_pf_testmode(data)                           (0x00000300&((data)<<8))
#define  ICH1_Hist_Profile_CTRL_ch1_pf_hnsr(data)                               (0x000000C0&((data)<<6))
#define  ICH1_Hist_Profile_CTRL_ch1_pf_vnsr(data)                               (0x00000030&((data)<<4))
#define  ICH1_Hist_Profile_CTRL_ch1_pf_field_sel(data)                          (0x0000000C&((data)<<2))
#define  ICH1_Hist_Profile_CTRL_ch1_pf_overflow_sel(data)                       (0x00000002&((data)<<1))
#define  ICH1_Hist_Profile_CTRL_ch1_pf_enable_profile(data)                     (0x00000001&(data))
#define  ICH1_Hist_Profile_CTRL_get_dummy(data)                                 ((0x00070000&(data))>>16)
#define  ICH1_Hist_Profile_CTRL_get_en_8k4k_mode(data)                          ((0x00008000&(data))>>15)
#define  ICH1_Hist_Profile_CTRL_get_en_4k2k_mode(data)                          ((0x00004000&(data))>>14)
#define  ICH1_Hist_Profile_CTRL_get_en_3d_mode(data)                            ((0x00002000&(data))>>13)
#define  ICH1_Hist_Profile_CTRL_get_ch1_pf_yuv_sel(data)                        ((0x00001800&(data))>>11)
#define  ICH1_Hist_Profile_CTRL_get_ch1_pf_test_enable(data)                    ((0x00000400&(data))>>10)
#define  ICH1_Hist_Profile_CTRL_get_ch1_pf_testmode(data)                       ((0x00000300&(data))>>8)
#define  ICH1_Hist_Profile_CTRL_get_ch1_pf_hnsr(data)                           ((0x000000C0&(data))>>6)
#define  ICH1_Hist_Profile_CTRL_get_ch1_pf_vnsr(data)                           ((0x00000030&(data))>>4)
#define  ICH1_Hist_Profile_CTRL_get_ch1_pf_field_sel(data)                      ((0x0000000C&(data))>>2)
#define  ICH1_Hist_Profile_CTRL_get_ch1_pf_overflow_sel(data)                   ((0x00000002&(data))>>1)
#define  ICH1_Hist_Profile_CTRL_get_ch1_pf_enable_profile(data)                 (0x00000001&(data))

#define  ICH1_Hist_Profile_size                                                 0x18023404
#define  ICH1_Hist_Profile_size_reg_addr                                        "0xB8023404"
#define  ICH1_Hist_Profile_size_reg                                             0xB8023404
#define  ICH1_Hist_Profile_size_inst_addr                                       "0x0001"
#define  ICH1_Hist_Profile_size_inst                                            0x0001
#define  ICH1_Hist_Profile_size_ch1_pf_vsize_shift                              (16)
#define  ICH1_Hist_Profile_size_ch1_pf_hsize_shift                              (0)
#define  ICH1_Hist_Profile_size_ch1_pf_vsize_mask                               (0x03FF0000)
#define  ICH1_Hist_Profile_size_ch1_pf_hsize_mask                               (0x000003FF)
#define  ICH1_Hist_Profile_size_ch1_pf_vsize(data)                              (0x03FF0000&((data)<<16))
#define  ICH1_Hist_Profile_size_ch1_pf_hsize(data)                              (0x000003FF&(data))
#define  ICH1_Hist_Profile_size_get_ch1_pf_vsize(data)                          ((0x03FF0000&(data))>>16)
#define  ICH1_Hist_Profile_size_get_ch1_pf_hsize(data)                          (0x000003FF&(data))

#define  ICH1_Hist_Profile_StartH                                               0x18023408
#define  ICH1_Hist_Profile_StartH_reg_addr                                      "0xB8023408"
#define  ICH1_Hist_Profile_StartH_reg                                           0xB8023408
#define  ICH1_Hist_Profile_StartH_inst_addr                                     "0x0002"
#define  ICH1_Hist_Profile_StartH_inst                                          0x0002
#define  ICH1_Hist_Profile_StartH_ch1_pf_starth_shift                           (0)
#define  ICH1_Hist_Profile_StartH_ch1_pf_starth_mask                            (0x00003FFF)
#define  ICH1_Hist_Profile_StartH_ch1_pf_starth(data)                           (0x00003FFF&(data))
#define  ICH1_Hist_Profile_StartH_get_ch1_pf_starth(data)                       (0x00003FFF&(data))

#define  ICH1_Hist_Profile_StartV                                               0x1802340C
#define  ICH1_Hist_Profile_StartV_reg_addr                                      "0xB802340C"
#define  ICH1_Hist_Profile_StartV_reg                                           0xB802340C
#define  ICH1_Hist_Profile_StartV_inst_addr                                     "0x0003"
#define  ICH1_Hist_Profile_StartV_inst                                          0x0003
#define  ICH1_Hist_Profile_StartV_ch1_pf_startv_shift                           (0)
#define  ICH1_Hist_Profile_StartV_ch1_pf_startv_mask                            (0x00003FFF)
#define  ICH1_Hist_Profile_StartV_ch1_pf_startv(data)                           (0x00003FFF&(data))
#define  ICH1_Hist_Profile_StartV_get_ch1_pf_startv(data)                       (0x00003FFF&(data))

#define  ICH1_Hist_Profile_Data_00                                              0x18023410
#define  ICH1_Hist_Profile_Data_00_reg_addr                                     "0xB8023410"
#define  ICH1_Hist_Profile_Data_00_reg                                          0xB8023410
#define  ICH1_Hist_Profile_Data_00_inst_addr                                    "0x0004"
#define  ICH1_Hist_Profile_Data_00_inst                                         0x0004
#define  ICH1_Hist_Profile_Data_00_ch1_pf_h01_shift                             (16)
#define  ICH1_Hist_Profile_Data_00_ch1_pf_h00_shift                             (0)
#define  ICH1_Hist_Profile_Data_00_ch1_pf_h01_mask                              (0xFFFF0000)
#define  ICH1_Hist_Profile_Data_00_ch1_pf_h00_mask                              (0x0000FFFF)
#define  ICH1_Hist_Profile_Data_00_ch1_pf_h01(data)                             (0xFFFF0000&((data)<<16))
#define  ICH1_Hist_Profile_Data_00_ch1_pf_h00(data)                             (0x0000FFFF&(data))
#define  ICH1_Hist_Profile_Data_00_get_ch1_pf_h01(data)                         ((0xFFFF0000&(data))>>16)
#define  ICH1_Hist_Profile_Data_00_get_ch1_pf_h00(data)                         (0x0000FFFF&(data))

#define  ICH1_Hist_Profile_Data_01                                              0x18023414
#define  ICH1_Hist_Profile_Data_01_reg_addr                                     "0xB8023414"
#define  ICH1_Hist_Profile_Data_01_reg                                          0xB8023414
#define  ICH1_Hist_Profile_Data_01_inst_addr                                    "0x0005"
#define  ICH1_Hist_Profile_Data_01_inst                                         0x0005
#define  ICH1_Hist_Profile_Data_01_ch1_pf_h03_shift                             (16)
#define  ICH1_Hist_Profile_Data_01_ch1_pf_h02_shift                             (0)
#define  ICH1_Hist_Profile_Data_01_ch1_pf_h03_mask                              (0xFFFF0000)
#define  ICH1_Hist_Profile_Data_01_ch1_pf_h02_mask                              (0x0000FFFF)
#define  ICH1_Hist_Profile_Data_01_ch1_pf_h03(data)                             (0xFFFF0000&((data)<<16))
#define  ICH1_Hist_Profile_Data_01_ch1_pf_h02(data)                             (0x0000FFFF&(data))
#define  ICH1_Hist_Profile_Data_01_get_ch1_pf_h03(data)                         ((0xFFFF0000&(data))>>16)
#define  ICH1_Hist_Profile_Data_01_get_ch1_pf_h02(data)                         (0x0000FFFF&(data))

#define  ICH1_Hist_Profile_Data_02                                              0x18023418
#define  ICH1_Hist_Profile_Data_02_reg_addr                                     "0xB8023418"
#define  ICH1_Hist_Profile_Data_02_reg                                          0xB8023418
#define  ICH1_Hist_Profile_Data_02_inst_addr                                    "0x0006"
#define  ICH1_Hist_Profile_Data_02_inst                                         0x0006
#define  ICH1_Hist_Profile_Data_02_ch1_pf_h05_shift                             (16)
#define  ICH1_Hist_Profile_Data_02_ch1_pf_h04_shift                             (0)
#define  ICH1_Hist_Profile_Data_02_ch1_pf_h05_mask                              (0xFFFF0000)
#define  ICH1_Hist_Profile_Data_02_ch1_pf_h04_mask                              (0x0000FFFF)
#define  ICH1_Hist_Profile_Data_02_ch1_pf_h05(data)                             (0xFFFF0000&((data)<<16))
#define  ICH1_Hist_Profile_Data_02_ch1_pf_h04(data)                             (0x0000FFFF&(data))
#define  ICH1_Hist_Profile_Data_02_get_ch1_pf_h05(data)                         ((0xFFFF0000&(data))>>16)
#define  ICH1_Hist_Profile_Data_02_get_ch1_pf_h04(data)                         (0x0000FFFF&(data))

#define  ICH1_Hist_Profile_Data_03                                              0x1802341C
#define  ICH1_Hist_Profile_Data_03_reg_addr                                     "0xB802341C"
#define  ICH1_Hist_Profile_Data_03_reg                                          0xB802341C
#define  ICH1_Hist_Profile_Data_03_inst_addr                                    "0x0007"
#define  ICH1_Hist_Profile_Data_03_inst                                         0x0007
#define  ICH1_Hist_Profile_Data_03_ch1_pf_h07_shift                             (16)
#define  ICH1_Hist_Profile_Data_03_ch1_pf_h06_shift                             (0)
#define  ICH1_Hist_Profile_Data_03_ch1_pf_h07_mask                              (0xFFFF0000)
#define  ICH1_Hist_Profile_Data_03_ch1_pf_h06_mask                              (0x0000FFFF)
#define  ICH1_Hist_Profile_Data_03_ch1_pf_h07(data)                             (0xFFFF0000&((data)<<16))
#define  ICH1_Hist_Profile_Data_03_ch1_pf_h06(data)                             (0x0000FFFF&(data))
#define  ICH1_Hist_Profile_Data_03_get_ch1_pf_h07(data)                         ((0xFFFF0000&(data))>>16)
#define  ICH1_Hist_Profile_Data_03_get_ch1_pf_h06(data)                         (0x0000FFFF&(data))

#define  ICH1_Hist_Profile_Data_04                                              0x18023420
#define  ICH1_Hist_Profile_Data_04_reg_addr                                     "0xB8023420"
#define  ICH1_Hist_Profile_Data_04_reg                                          0xB8023420
#define  ICH1_Hist_Profile_Data_04_inst_addr                                    "0x0008"
#define  ICH1_Hist_Profile_Data_04_inst                                         0x0008
#define  ICH1_Hist_Profile_Data_04_ch1_pf_h09_shift                             (16)
#define  ICH1_Hist_Profile_Data_04_ch1_pf_h08_shift                             (0)
#define  ICH1_Hist_Profile_Data_04_ch1_pf_h09_mask                              (0xFFFF0000)
#define  ICH1_Hist_Profile_Data_04_ch1_pf_h08_mask                              (0x0000FFFF)
#define  ICH1_Hist_Profile_Data_04_ch1_pf_h09(data)                             (0xFFFF0000&((data)<<16))
#define  ICH1_Hist_Profile_Data_04_ch1_pf_h08(data)                             (0x0000FFFF&(data))
#define  ICH1_Hist_Profile_Data_04_get_ch1_pf_h09(data)                         ((0xFFFF0000&(data))>>16)
#define  ICH1_Hist_Profile_Data_04_get_ch1_pf_h08(data)                         (0x0000FFFF&(data))

#define  ICH1_Hist_Profile_Data_05                                              0x18023424
#define  ICH1_Hist_Profile_Data_05_reg_addr                                     "0xB8023424"
#define  ICH1_Hist_Profile_Data_05_reg                                          0xB8023424
#define  ICH1_Hist_Profile_Data_05_inst_addr                                    "0x0009"
#define  ICH1_Hist_Profile_Data_05_inst                                         0x0009
#define  ICH1_Hist_Profile_Data_05_ch1_pf_h11_shift                             (16)
#define  ICH1_Hist_Profile_Data_05_ch1_pf_h10_shift                             (0)
#define  ICH1_Hist_Profile_Data_05_ch1_pf_h11_mask                              (0xFFFF0000)
#define  ICH1_Hist_Profile_Data_05_ch1_pf_h10_mask                              (0x0000FFFF)
#define  ICH1_Hist_Profile_Data_05_ch1_pf_h11(data)                             (0xFFFF0000&((data)<<16))
#define  ICH1_Hist_Profile_Data_05_ch1_pf_h10(data)                             (0x0000FFFF&(data))
#define  ICH1_Hist_Profile_Data_05_get_ch1_pf_h11(data)                         ((0xFFFF0000&(data))>>16)
#define  ICH1_Hist_Profile_Data_05_get_ch1_pf_h10(data)                         (0x0000FFFF&(data))

#define  ICH1_Hist_Profile_Data_06                                              0x18023428
#define  ICH1_Hist_Profile_Data_06_reg_addr                                     "0xB8023428"
#define  ICH1_Hist_Profile_Data_06_reg                                          0xB8023428
#define  ICH1_Hist_Profile_Data_06_inst_addr                                    "0x000A"
#define  ICH1_Hist_Profile_Data_06_inst                                         0x000A
#define  ICH1_Hist_Profile_Data_06_ch1_pf_h13_shift                             (16)
#define  ICH1_Hist_Profile_Data_06_ch1_pf_h12_shift                             (0)
#define  ICH1_Hist_Profile_Data_06_ch1_pf_h13_mask                              (0xFFFF0000)
#define  ICH1_Hist_Profile_Data_06_ch1_pf_h12_mask                              (0x0000FFFF)
#define  ICH1_Hist_Profile_Data_06_ch1_pf_h13(data)                             (0xFFFF0000&((data)<<16))
#define  ICH1_Hist_Profile_Data_06_ch1_pf_h12(data)                             (0x0000FFFF&(data))
#define  ICH1_Hist_Profile_Data_06_get_ch1_pf_h13(data)                         ((0xFFFF0000&(data))>>16)
#define  ICH1_Hist_Profile_Data_06_get_ch1_pf_h12(data)                         (0x0000FFFF&(data))

#define  ICH1_Hist_Profile_Data_07                                              0x1802342C
#define  ICH1_Hist_Profile_Data_07_reg_addr                                     "0xB802342C"
#define  ICH1_Hist_Profile_Data_07_reg                                          0xB802342C
#define  ICH1_Hist_Profile_Data_07_inst_addr                                    "0x000B"
#define  ICH1_Hist_Profile_Data_07_inst                                         0x000B
#define  ICH1_Hist_Profile_Data_07_ch1_pf_h15_shift                             (16)
#define  ICH1_Hist_Profile_Data_07_ch1_pf_h14_shift                             (0)
#define  ICH1_Hist_Profile_Data_07_ch1_pf_h15_mask                              (0xFFFF0000)
#define  ICH1_Hist_Profile_Data_07_ch1_pf_h14_mask                              (0x0000FFFF)
#define  ICH1_Hist_Profile_Data_07_ch1_pf_h15(data)                             (0xFFFF0000&((data)<<16))
#define  ICH1_Hist_Profile_Data_07_ch1_pf_h14(data)                             (0x0000FFFF&(data))
#define  ICH1_Hist_Profile_Data_07_get_ch1_pf_h15(data)                         ((0xFFFF0000&(data))>>16)
#define  ICH1_Hist_Profile_Data_07_get_ch1_pf_h14(data)                         (0x0000FFFF&(data))

#define  ICH1_Hist_Profile_Data_08                                              0x18023430
#define  ICH1_Hist_Profile_Data_08_reg_addr                                     "0xB8023430"
#define  ICH1_Hist_Profile_Data_08_reg                                          0xB8023430
#define  ICH1_Hist_Profile_Data_08_inst_addr                                    "0x000C"
#define  ICH1_Hist_Profile_Data_08_inst                                         0x000C
#define  ICH1_Hist_Profile_Data_08_ch1_pf_v01_shift                             (16)
#define  ICH1_Hist_Profile_Data_08_ch1_pf_v00_shift                             (0)
#define  ICH1_Hist_Profile_Data_08_ch1_pf_v01_mask                              (0xFFFF0000)
#define  ICH1_Hist_Profile_Data_08_ch1_pf_v00_mask                              (0x0000FFFF)
#define  ICH1_Hist_Profile_Data_08_ch1_pf_v01(data)                             (0xFFFF0000&((data)<<16))
#define  ICH1_Hist_Profile_Data_08_ch1_pf_v00(data)                             (0x0000FFFF&(data))
#define  ICH1_Hist_Profile_Data_08_get_ch1_pf_v01(data)                         ((0xFFFF0000&(data))>>16)
#define  ICH1_Hist_Profile_Data_08_get_ch1_pf_v00(data)                         (0x0000FFFF&(data))

#define  ICH1_Hist_Profile_Data_09                                              0x18023434
#define  ICH1_Hist_Profile_Data_09_reg_addr                                     "0xB8023434"
#define  ICH1_Hist_Profile_Data_09_reg                                          0xB8023434
#define  ICH1_Hist_Profile_Data_09_inst_addr                                    "0x000D"
#define  ICH1_Hist_Profile_Data_09_inst                                         0x000D
#define  ICH1_Hist_Profile_Data_09_ch1_pf_v03_shift                             (16)
#define  ICH1_Hist_Profile_Data_09_ch1_pf_v02_shift                             (0)
#define  ICH1_Hist_Profile_Data_09_ch1_pf_v03_mask                              (0xFFFF0000)
#define  ICH1_Hist_Profile_Data_09_ch1_pf_v02_mask                              (0x0000FFFF)
#define  ICH1_Hist_Profile_Data_09_ch1_pf_v03(data)                             (0xFFFF0000&((data)<<16))
#define  ICH1_Hist_Profile_Data_09_ch1_pf_v02(data)                             (0x0000FFFF&(data))
#define  ICH1_Hist_Profile_Data_09_get_ch1_pf_v03(data)                         ((0xFFFF0000&(data))>>16)
#define  ICH1_Hist_Profile_Data_09_get_ch1_pf_v02(data)                         (0x0000FFFF&(data))

#define  ICH1_Hist_Profile_Data_10                                              0x18023438
#define  ICH1_Hist_Profile_Data_10_reg_addr                                     "0xB8023438"
#define  ICH1_Hist_Profile_Data_10_reg                                          0xB8023438
#define  ICH1_Hist_Profile_Data_10_inst_addr                                    "0x000E"
#define  ICH1_Hist_Profile_Data_10_inst                                         0x000E
#define  ICH1_Hist_Profile_Data_10_ch1_pf_v05_shift                             (16)
#define  ICH1_Hist_Profile_Data_10_ch1_pf_v04_shift                             (0)
#define  ICH1_Hist_Profile_Data_10_ch1_pf_v05_mask                              (0xFFFF0000)
#define  ICH1_Hist_Profile_Data_10_ch1_pf_v04_mask                              (0x0000FFFF)
#define  ICH1_Hist_Profile_Data_10_ch1_pf_v05(data)                             (0xFFFF0000&((data)<<16))
#define  ICH1_Hist_Profile_Data_10_ch1_pf_v04(data)                             (0x0000FFFF&(data))
#define  ICH1_Hist_Profile_Data_10_get_ch1_pf_v05(data)                         ((0xFFFF0000&(data))>>16)
#define  ICH1_Hist_Profile_Data_10_get_ch1_pf_v04(data)                         (0x0000FFFF&(data))

#define  ICH1_Hist_Profile_Data_11                                              0x1802343C
#define  ICH1_Hist_Profile_Data_11_reg_addr                                     "0xB802343C"
#define  ICH1_Hist_Profile_Data_11_reg                                          0xB802343C
#define  ICH1_Hist_Profile_Data_11_inst_addr                                    "0x000F"
#define  ICH1_Hist_Profile_Data_11_inst                                         0x000F
#define  ICH1_Hist_Profile_Data_11_ch1_pf_v07_shift                             (16)
#define  ICH1_Hist_Profile_Data_11_ch1_pf_v06_shift                             (0)
#define  ICH1_Hist_Profile_Data_11_ch1_pf_v07_mask                              (0xFFFF0000)
#define  ICH1_Hist_Profile_Data_11_ch1_pf_v06_mask                              (0x0000FFFF)
#define  ICH1_Hist_Profile_Data_11_ch1_pf_v07(data)                             (0xFFFF0000&((data)<<16))
#define  ICH1_Hist_Profile_Data_11_ch1_pf_v06(data)                             (0x0000FFFF&(data))
#define  ICH1_Hist_Profile_Data_11_get_ch1_pf_v07(data)                         ((0xFFFF0000&(data))>>16)
#define  ICH1_Hist_Profile_Data_11_get_ch1_pf_v06(data)                         (0x0000FFFF&(data))

#define  ICH1_Hist_Profile_Data_12                                              0x18023440
#define  ICH1_Hist_Profile_Data_12_reg_addr                                     "0xB8023440"
#define  ICH1_Hist_Profile_Data_12_reg                                          0xB8023440
#define  ICH1_Hist_Profile_Data_12_inst_addr                                    "0x0010"
#define  ICH1_Hist_Profile_Data_12_inst                                         0x0010
#define  ICH1_Hist_Profile_Data_12_ch1_pf_v09_shift                             (16)
#define  ICH1_Hist_Profile_Data_12_ch1_pf_v08_shift                             (0)
#define  ICH1_Hist_Profile_Data_12_ch1_pf_v09_mask                              (0xFFFF0000)
#define  ICH1_Hist_Profile_Data_12_ch1_pf_v08_mask                              (0x0000FFFF)
#define  ICH1_Hist_Profile_Data_12_ch1_pf_v09(data)                             (0xFFFF0000&((data)<<16))
#define  ICH1_Hist_Profile_Data_12_ch1_pf_v08(data)                             (0x0000FFFF&(data))
#define  ICH1_Hist_Profile_Data_12_get_ch1_pf_v09(data)                         ((0xFFFF0000&(data))>>16)
#define  ICH1_Hist_Profile_Data_12_get_ch1_pf_v08(data)                         (0x0000FFFF&(data))

#define  ICH1_Hist_Profile_Data_13                                              0x18023444
#define  ICH1_Hist_Profile_Data_13_reg_addr                                     "0xB8023444"
#define  ICH1_Hist_Profile_Data_13_reg                                          0xB8023444
#define  ICH1_Hist_Profile_Data_13_inst_addr                                    "0x0011"
#define  ICH1_Hist_Profile_Data_13_inst                                         0x0011
#define  ICH1_Hist_Profile_Data_13_ch1_pf_v11_shift                             (16)
#define  ICH1_Hist_Profile_Data_13_ch1_pf_v10_shift                             (0)
#define  ICH1_Hist_Profile_Data_13_ch1_pf_v11_mask                              (0xFFFF0000)
#define  ICH1_Hist_Profile_Data_13_ch1_pf_v10_mask                              (0x0000FFFF)
#define  ICH1_Hist_Profile_Data_13_ch1_pf_v11(data)                             (0xFFFF0000&((data)<<16))
#define  ICH1_Hist_Profile_Data_13_ch1_pf_v10(data)                             (0x0000FFFF&(data))
#define  ICH1_Hist_Profile_Data_13_get_ch1_pf_v11(data)                         ((0xFFFF0000&(data))>>16)
#define  ICH1_Hist_Profile_Data_13_get_ch1_pf_v10(data)                         (0x0000FFFF&(data))

#define  ICH1_Hist_Profile_Data_14                                              0x18023448
#define  ICH1_Hist_Profile_Data_14_reg_addr                                     "0xB8023448"
#define  ICH1_Hist_Profile_Data_14_reg                                          0xB8023448
#define  ICH1_Hist_Profile_Data_14_inst_addr                                    "0x0012"
#define  ICH1_Hist_Profile_Data_14_inst                                         0x0012
#define  ICH1_Hist_Profile_Data_14_ch1_pf_v13_shift                             (16)
#define  ICH1_Hist_Profile_Data_14_ch1_pf_v12_shift                             (0)
#define  ICH1_Hist_Profile_Data_14_ch1_pf_v13_mask                              (0xFFFF0000)
#define  ICH1_Hist_Profile_Data_14_ch1_pf_v12_mask                              (0x0000FFFF)
#define  ICH1_Hist_Profile_Data_14_ch1_pf_v13(data)                             (0xFFFF0000&((data)<<16))
#define  ICH1_Hist_Profile_Data_14_ch1_pf_v12(data)                             (0x0000FFFF&(data))
#define  ICH1_Hist_Profile_Data_14_get_ch1_pf_v13(data)                         ((0xFFFF0000&(data))>>16)
#define  ICH1_Hist_Profile_Data_14_get_ch1_pf_v12(data)                         (0x0000FFFF&(data))

#define  ICH1_Hist_Profile_Data_15                                              0x1802344C
#define  ICH1_Hist_Profile_Data_15_reg_addr                                     "0xB802344C"
#define  ICH1_Hist_Profile_Data_15_reg                                          0xB802344C
#define  ICH1_Hist_Profile_Data_15_inst_addr                                    "0x0013"
#define  ICH1_Hist_Profile_Data_15_inst                                         0x0013
#define  ICH1_Hist_Profile_Data_15_ch1_pf_v15_shift                             (16)
#define  ICH1_Hist_Profile_Data_15_ch1_pf_v14_shift                             (0)
#define  ICH1_Hist_Profile_Data_15_ch1_pf_v15_mask                              (0xFFFF0000)
#define  ICH1_Hist_Profile_Data_15_ch1_pf_v14_mask                              (0x0000FFFF)
#define  ICH1_Hist_Profile_Data_15_ch1_pf_v15(data)                             (0xFFFF0000&((data)<<16))
#define  ICH1_Hist_Profile_Data_15_ch1_pf_v14(data)                             (0x0000FFFF&(data))
#define  ICH1_Hist_Profile_Data_15_get_ch1_pf_v15(data)                         ((0xFFFF0000&(data))>>16)
#define  ICH1_Hist_Profile_Data_15_get_ch1_pf_v14(data)                         (0x0000FFFF&(data))

#define  ICH1_Hist_Profile_Data_16                                              0x18023450
#define  ICH1_Hist_Profile_Data_16_reg_addr                                     "0xB8023450"
#define  ICH1_Hist_Profile_Data_16_reg                                          0xB8023450
#define  ICH1_Hist_Profile_Data_16_inst_addr                                    "0x0014"
#define  ICH1_Hist_Profile_Data_16_inst                                         0x0014
#define  ICH1_Hist_Profile_Data_16_ch1_pf_h01_right_shift                       (16)
#define  ICH1_Hist_Profile_Data_16_ch1_pf_h00_right_shift                       (0)
#define  ICH1_Hist_Profile_Data_16_ch1_pf_h01_right_mask                        (0xFFFF0000)
#define  ICH1_Hist_Profile_Data_16_ch1_pf_h00_right_mask                        (0x0000FFFF)
#define  ICH1_Hist_Profile_Data_16_ch1_pf_h01_right(data)                       (0xFFFF0000&((data)<<16))
#define  ICH1_Hist_Profile_Data_16_ch1_pf_h00_right(data)                       (0x0000FFFF&(data))
#define  ICH1_Hist_Profile_Data_16_get_ch1_pf_h01_right(data)                   ((0xFFFF0000&(data))>>16)
#define  ICH1_Hist_Profile_Data_16_get_ch1_pf_h00_right(data)                   (0x0000FFFF&(data))

#define  ICH1_Hist_Profile_Data_17                                              0x18023454
#define  ICH1_Hist_Profile_Data_17_reg_addr                                     "0xB8023454"
#define  ICH1_Hist_Profile_Data_17_reg                                          0xB8023454
#define  ICH1_Hist_Profile_Data_17_inst_addr                                    "0x0015"
#define  ICH1_Hist_Profile_Data_17_inst                                         0x0015
#define  ICH1_Hist_Profile_Data_17_ch1_pf_h03_right_shift                       (16)
#define  ICH1_Hist_Profile_Data_17_ch1_pf_h02_right_shift                       (0)
#define  ICH1_Hist_Profile_Data_17_ch1_pf_h03_right_mask                        (0xFFFF0000)
#define  ICH1_Hist_Profile_Data_17_ch1_pf_h02_right_mask                        (0x0000FFFF)
#define  ICH1_Hist_Profile_Data_17_ch1_pf_h03_right(data)                       (0xFFFF0000&((data)<<16))
#define  ICH1_Hist_Profile_Data_17_ch1_pf_h02_right(data)                       (0x0000FFFF&(data))
#define  ICH1_Hist_Profile_Data_17_get_ch1_pf_h03_right(data)                   ((0xFFFF0000&(data))>>16)
#define  ICH1_Hist_Profile_Data_17_get_ch1_pf_h02_right(data)                   (0x0000FFFF&(data))

#define  ICH1_Hist_Profile_Data_18                                              0x18023458
#define  ICH1_Hist_Profile_Data_18_reg_addr                                     "0xB8023458"
#define  ICH1_Hist_Profile_Data_18_reg                                          0xB8023458
#define  ICH1_Hist_Profile_Data_18_inst_addr                                    "0x0016"
#define  ICH1_Hist_Profile_Data_18_inst                                         0x0016
#define  ICH1_Hist_Profile_Data_18_ch1_pf_h05_right_shift                       (16)
#define  ICH1_Hist_Profile_Data_18_ch1_pf_h04_right_shift                       (0)
#define  ICH1_Hist_Profile_Data_18_ch1_pf_h05_right_mask                        (0xFFFF0000)
#define  ICH1_Hist_Profile_Data_18_ch1_pf_h04_right_mask                        (0x0000FFFF)
#define  ICH1_Hist_Profile_Data_18_ch1_pf_h05_right(data)                       (0xFFFF0000&((data)<<16))
#define  ICH1_Hist_Profile_Data_18_ch1_pf_h04_right(data)                       (0x0000FFFF&(data))
#define  ICH1_Hist_Profile_Data_18_get_ch1_pf_h05_right(data)                   ((0xFFFF0000&(data))>>16)
#define  ICH1_Hist_Profile_Data_18_get_ch1_pf_h04_right(data)                   (0x0000FFFF&(data))

#define  ICH1_Hist_Profile_Data_19                                              0x1802345C
#define  ICH1_Hist_Profile_Data_19_reg_addr                                     "0xB802345C"
#define  ICH1_Hist_Profile_Data_19_reg                                          0xB802345C
#define  ICH1_Hist_Profile_Data_19_inst_addr                                    "0x0017"
#define  ICH1_Hist_Profile_Data_19_inst                                         0x0017
#define  ICH1_Hist_Profile_Data_19_ch1_pf_h07_right_shift                       (16)
#define  ICH1_Hist_Profile_Data_19_ch1_pf_h06_right_shift                       (0)
#define  ICH1_Hist_Profile_Data_19_ch1_pf_h07_right_mask                        (0xFFFF0000)
#define  ICH1_Hist_Profile_Data_19_ch1_pf_h06_right_mask                        (0x0000FFFF)
#define  ICH1_Hist_Profile_Data_19_ch1_pf_h07_right(data)                       (0xFFFF0000&((data)<<16))
#define  ICH1_Hist_Profile_Data_19_ch1_pf_h06_right(data)                       (0x0000FFFF&(data))
#define  ICH1_Hist_Profile_Data_19_get_ch1_pf_h07_right(data)                   ((0xFFFF0000&(data))>>16)
#define  ICH1_Hist_Profile_Data_19_get_ch1_pf_h06_right(data)                   (0x0000FFFF&(data))

#define  ICH1_Hist_Profile_Data_20                                              0x18023460
#define  ICH1_Hist_Profile_Data_20_reg_addr                                     "0xB8023460"
#define  ICH1_Hist_Profile_Data_20_reg                                          0xB8023460
#define  ICH1_Hist_Profile_Data_20_inst_addr                                    "0x0018"
#define  ICH1_Hist_Profile_Data_20_inst                                         0x0018
#define  ICH1_Hist_Profile_Data_20_ch1_pf_h09_right_shift                       (16)
#define  ICH1_Hist_Profile_Data_20_ch1_pf_h08_right_shift                       (0)
#define  ICH1_Hist_Profile_Data_20_ch1_pf_h09_right_mask                        (0xFFFF0000)
#define  ICH1_Hist_Profile_Data_20_ch1_pf_h08_right_mask                        (0x0000FFFF)
#define  ICH1_Hist_Profile_Data_20_ch1_pf_h09_right(data)                       (0xFFFF0000&((data)<<16))
#define  ICH1_Hist_Profile_Data_20_ch1_pf_h08_right(data)                       (0x0000FFFF&(data))
#define  ICH1_Hist_Profile_Data_20_get_ch1_pf_h09_right(data)                   ((0xFFFF0000&(data))>>16)
#define  ICH1_Hist_Profile_Data_20_get_ch1_pf_h08_right(data)                   (0x0000FFFF&(data))

#define  ICH1_Hist_Profile_Data_21                                              0x18023464
#define  ICH1_Hist_Profile_Data_21_reg_addr                                     "0xB8023464"
#define  ICH1_Hist_Profile_Data_21_reg                                          0xB8023464
#define  ICH1_Hist_Profile_Data_21_inst_addr                                    "0x0019"
#define  ICH1_Hist_Profile_Data_21_inst                                         0x0019
#define  ICH1_Hist_Profile_Data_21_ch1_pf_h11_right_shift                       (16)
#define  ICH1_Hist_Profile_Data_21_ch1_pf_h10_right_shift                       (0)
#define  ICH1_Hist_Profile_Data_21_ch1_pf_h11_right_mask                        (0xFFFF0000)
#define  ICH1_Hist_Profile_Data_21_ch1_pf_h10_right_mask                        (0x0000FFFF)
#define  ICH1_Hist_Profile_Data_21_ch1_pf_h11_right(data)                       (0xFFFF0000&((data)<<16))
#define  ICH1_Hist_Profile_Data_21_ch1_pf_h10_right(data)                       (0x0000FFFF&(data))
#define  ICH1_Hist_Profile_Data_21_get_ch1_pf_h11_right(data)                   ((0xFFFF0000&(data))>>16)
#define  ICH1_Hist_Profile_Data_21_get_ch1_pf_h10_right(data)                   (0x0000FFFF&(data))

#define  ICH1_Hist_Profile_Data_22                                              0x18023468
#define  ICH1_Hist_Profile_Data_22_reg_addr                                     "0xB8023468"
#define  ICH1_Hist_Profile_Data_22_reg                                          0xB8023468
#define  ICH1_Hist_Profile_Data_22_inst_addr                                    "0x001A"
#define  ICH1_Hist_Profile_Data_22_inst                                         0x001A
#define  ICH1_Hist_Profile_Data_22_ch1_pf_h13_right_shift                       (16)
#define  ICH1_Hist_Profile_Data_22_ch1_pf_h12_right_shift                       (0)
#define  ICH1_Hist_Profile_Data_22_ch1_pf_h13_right_mask                        (0xFFFF0000)
#define  ICH1_Hist_Profile_Data_22_ch1_pf_h12_right_mask                        (0x0000FFFF)
#define  ICH1_Hist_Profile_Data_22_ch1_pf_h13_right(data)                       (0xFFFF0000&((data)<<16))
#define  ICH1_Hist_Profile_Data_22_ch1_pf_h12_right(data)                       (0x0000FFFF&(data))
#define  ICH1_Hist_Profile_Data_22_get_ch1_pf_h13_right(data)                   ((0xFFFF0000&(data))>>16)
#define  ICH1_Hist_Profile_Data_22_get_ch1_pf_h12_right(data)                   (0x0000FFFF&(data))

#define  ICH1_Hist_Profile_Data_23                                              0x1802346C
#define  ICH1_Hist_Profile_Data_23_reg_addr                                     "0xB802346C"
#define  ICH1_Hist_Profile_Data_23_reg                                          0xB802346C
#define  ICH1_Hist_Profile_Data_23_inst_addr                                    "0x001B"
#define  ICH1_Hist_Profile_Data_23_inst                                         0x001B
#define  ICH1_Hist_Profile_Data_23_ch1_pf_h15_right_shift                       (16)
#define  ICH1_Hist_Profile_Data_23_ch1_pf_h14_right_shift                       (0)
#define  ICH1_Hist_Profile_Data_23_ch1_pf_h15_right_mask                        (0xFFFF0000)
#define  ICH1_Hist_Profile_Data_23_ch1_pf_h14_right_mask                        (0x0000FFFF)
#define  ICH1_Hist_Profile_Data_23_ch1_pf_h15_right(data)                       (0xFFFF0000&((data)<<16))
#define  ICH1_Hist_Profile_Data_23_ch1_pf_h14_right(data)                       (0x0000FFFF&(data))
#define  ICH1_Hist_Profile_Data_23_get_ch1_pf_h15_right(data)                   ((0xFFFF0000&(data))>>16)
#define  ICH1_Hist_Profile_Data_23_get_ch1_pf_h14_right(data)                   (0x0000FFFF&(data))

#define  ICH1_Hist_Profile_Data_24                                              0x18023470
#define  ICH1_Hist_Profile_Data_24_reg_addr                                     "0xB8023470"
#define  ICH1_Hist_Profile_Data_24_reg                                          0xB8023470
#define  ICH1_Hist_Profile_Data_24_inst_addr                                    "0x001C"
#define  ICH1_Hist_Profile_Data_24_inst                                         0x001C
#define  ICH1_Hist_Profile_Data_24_ch1_pf_v01_right_shift                       (16)
#define  ICH1_Hist_Profile_Data_24_ch1_pf_v00_right_shift                       (0)
#define  ICH1_Hist_Profile_Data_24_ch1_pf_v01_right_mask                        (0xFFFF0000)
#define  ICH1_Hist_Profile_Data_24_ch1_pf_v00_right_mask                        (0x0000FFFF)
#define  ICH1_Hist_Profile_Data_24_ch1_pf_v01_right(data)                       (0xFFFF0000&((data)<<16))
#define  ICH1_Hist_Profile_Data_24_ch1_pf_v00_right(data)                       (0x0000FFFF&(data))
#define  ICH1_Hist_Profile_Data_24_get_ch1_pf_v01_right(data)                   ((0xFFFF0000&(data))>>16)
#define  ICH1_Hist_Profile_Data_24_get_ch1_pf_v00_right(data)                   (0x0000FFFF&(data))

#define  ICH1_Hist_Profile_Data_25                                              0x18023474
#define  ICH1_Hist_Profile_Data_25_reg_addr                                     "0xB8023474"
#define  ICH1_Hist_Profile_Data_25_reg                                          0xB8023474
#define  ICH1_Hist_Profile_Data_25_inst_addr                                    "0x001D"
#define  ICH1_Hist_Profile_Data_25_inst                                         0x001D
#define  ICH1_Hist_Profile_Data_25_ch1_pf_v03_right_shift                       (16)
#define  ICH1_Hist_Profile_Data_25_ch1_pf_v02_right_shift                       (0)
#define  ICH1_Hist_Profile_Data_25_ch1_pf_v03_right_mask                        (0xFFFF0000)
#define  ICH1_Hist_Profile_Data_25_ch1_pf_v02_right_mask                        (0x0000FFFF)
#define  ICH1_Hist_Profile_Data_25_ch1_pf_v03_right(data)                       (0xFFFF0000&((data)<<16))
#define  ICH1_Hist_Profile_Data_25_ch1_pf_v02_right(data)                       (0x0000FFFF&(data))
#define  ICH1_Hist_Profile_Data_25_get_ch1_pf_v03_right(data)                   ((0xFFFF0000&(data))>>16)
#define  ICH1_Hist_Profile_Data_25_get_ch1_pf_v02_right(data)                   (0x0000FFFF&(data))

#define  ICH1_Hist_Profile_Data_26                                              0x18023478
#define  ICH1_Hist_Profile_Data_26_reg_addr                                     "0xB8023478"
#define  ICH1_Hist_Profile_Data_26_reg                                          0xB8023478
#define  ICH1_Hist_Profile_Data_26_inst_addr                                    "0x001E"
#define  ICH1_Hist_Profile_Data_26_inst                                         0x001E
#define  ICH1_Hist_Profile_Data_26_ch1_pf_v05_right_shift                       (16)
#define  ICH1_Hist_Profile_Data_26_ch1_pf_v04_right_shift                       (0)
#define  ICH1_Hist_Profile_Data_26_ch1_pf_v05_right_mask                        (0xFFFF0000)
#define  ICH1_Hist_Profile_Data_26_ch1_pf_v04_right_mask                        (0x0000FFFF)
#define  ICH1_Hist_Profile_Data_26_ch1_pf_v05_right(data)                       (0xFFFF0000&((data)<<16))
#define  ICH1_Hist_Profile_Data_26_ch1_pf_v04_right(data)                       (0x0000FFFF&(data))
#define  ICH1_Hist_Profile_Data_26_get_ch1_pf_v05_right(data)                   ((0xFFFF0000&(data))>>16)
#define  ICH1_Hist_Profile_Data_26_get_ch1_pf_v04_right(data)                   (0x0000FFFF&(data))

#define  ICH1_Hist_Profile_Data_27                                              0x1802347C
#define  ICH1_Hist_Profile_Data_27_reg_addr                                     "0xB802347C"
#define  ICH1_Hist_Profile_Data_27_reg                                          0xB802347C
#define  ICH1_Hist_Profile_Data_27_inst_addr                                    "0x001F"
#define  ICH1_Hist_Profile_Data_27_inst                                         0x001F
#define  ICH1_Hist_Profile_Data_27_ch1_pf_v07_right_shift                       (16)
#define  ICH1_Hist_Profile_Data_27_ch1_pf_v06_right_shift                       (0)
#define  ICH1_Hist_Profile_Data_27_ch1_pf_v07_right_mask                        (0xFFFF0000)
#define  ICH1_Hist_Profile_Data_27_ch1_pf_v06_right_mask                        (0x0000FFFF)
#define  ICH1_Hist_Profile_Data_27_ch1_pf_v07_right(data)                       (0xFFFF0000&((data)<<16))
#define  ICH1_Hist_Profile_Data_27_ch1_pf_v06_right(data)                       (0x0000FFFF&(data))
#define  ICH1_Hist_Profile_Data_27_get_ch1_pf_v07_right(data)                   ((0xFFFF0000&(data))>>16)
#define  ICH1_Hist_Profile_Data_27_get_ch1_pf_v06_right(data)                   (0x0000FFFF&(data))

#define  ICH1_Hist_Profile_Data_28                                              0x18023480
#define  ICH1_Hist_Profile_Data_28_reg_addr                                     "0xB8023480"
#define  ICH1_Hist_Profile_Data_28_reg                                          0xB8023480
#define  ICH1_Hist_Profile_Data_28_inst_addr                                    "0x0020"
#define  ICH1_Hist_Profile_Data_28_inst                                         0x0020
#define  ICH1_Hist_Profile_Data_28_ch1_pf_v09_right_shift                       (16)
#define  ICH1_Hist_Profile_Data_28_ch1_pf_v08_right_shift                       (0)
#define  ICH1_Hist_Profile_Data_28_ch1_pf_v09_right_mask                        (0xFFFF0000)
#define  ICH1_Hist_Profile_Data_28_ch1_pf_v08_right_mask                        (0x0000FFFF)
#define  ICH1_Hist_Profile_Data_28_ch1_pf_v09_right(data)                       (0xFFFF0000&((data)<<16))
#define  ICH1_Hist_Profile_Data_28_ch1_pf_v08_right(data)                       (0x0000FFFF&(data))
#define  ICH1_Hist_Profile_Data_28_get_ch1_pf_v09_right(data)                   ((0xFFFF0000&(data))>>16)
#define  ICH1_Hist_Profile_Data_28_get_ch1_pf_v08_right(data)                   (0x0000FFFF&(data))

#define  ICH1_Hist_Profile_Data_29                                              0x18023484
#define  ICH1_Hist_Profile_Data_29_reg_addr                                     "0xB8023484"
#define  ICH1_Hist_Profile_Data_29_reg                                          0xB8023484
#define  ICH1_Hist_Profile_Data_29_inst_addr                                    "0x0021"
#define  ICH1_Hist_Profile_Data_29_inst                                         0x0021
#define  ICH1_Hist_Profile_Data_29_ch1_pf_v11_right_shift                       (16)
#define  ICH1_Hist_Profile_Data_29_ch1_pf_v10_right_shift                       (0)
#define  ICH1_Hist_Profile_Data_29_ch1_pf_v11_right_mask                        (0xFFFF0000)
#define  ICH1_Hist_Profile_Data_29_ch1_pf_v10_right_mask                        (0x0000FFFF)
#define  ICH1_Hist_Profile_Data_29_ch1_pf_v11_right(data)                       (0xFFFF0000&((data)<<16))
#define  ICH1_Hist_Profile_Data_29_ch1_pf_v10_right(data)                       (0x0000FFFF&(data))
#define  ICH1_Hist_Profile_Data_29_get_ch1_pf_v11_right(data)                   ((0xFFFF0000&(data))>>16)
#define  ICH1_Hist_Profile_Data_29_get_ch1_pf_v10_right(data)                   (0x0000FFFF&(data))

#define  ICH1_Hist_Profile_Data_30                                              0x18023488
#define  ICH1_Hist_Profile_Data_30_reg_addr                                     "0xB8023488"
#define  ICH1_Hist_Profile_Data_30_reg                                          0xB8023488
#define  ICH1_Hist_Profile_Data_30_inst_addr                                    "0x0022"
#define  ICH1_Hist_Profile_Data_30_inst                                         0x0022
#define  ICH1_Hist_Profile_Data_30_ch1_pf_v13_right_shift                       (16)
#define  ICH1_Hist_Profile_Data_30_ch1_pf_v12_right_shift                       (0)
#define  ICH1_Hist_Profile_Data_30_ch1_pf_v13_right_mask                        (0xFFFF0000)
#define  ICH1_Hist_Profile_Data_30_ch1_pf_v12_right_mask                        (0x0000FFFF)
#define  ICH1_Hist_Profile_Data_30_ch1_pf_v13_right(data)                       (0xFFFF0000&((data)<<16))
#define  ICH1_Hist_Profile_Data_30_ch1_pf_v12_right(data)                       (0x0000FFFF&(data))
#define  ICH1_Hist_Profile_Data_30_get_ch1_pf_v13_right(data)                   ((0xFFFF0000&(data))>>16)
#define  ICH1_Hist_Profile_Data_30_get_ch1_pf_v12_right(data)                   (0x0000FFFF&(data))

#define  ICH1_Hist_Profile_Data_31                                              0x1802348C
#define  ICH1_Hist_Profile_Data_31_reg_addr                                     "0xB802348C"
#define  ICH1_Hist_Profile_Data_31_reg                                          0xB802348C
#define  ICH1_Hist_Profile_Data_31_inst_addr                                    "0x0023"
#define  ICH1_Hist_Profile_Data_31_inst                                         0x0023
#define  ICH1_Hist_Profile_Data_31_ch1_pf_v15_right_shift                       (16)
#define  ICH1_Hist_Profile_Data_31_ch1_pf_v14_right_shift                       (0)
#define  ICH1_Hist_Profile_Data_31_ch1_pf_v15_right_mask                        (0xFFFF0000)
#define  ICH1_Hist_Profile_Data_31_ch1_pf_v14_right_mask                        (0x0000FFFF)
#define  ICH1_Hist_Profile_Data_31_ch1_pf_v15_right(data)                       (0xFFFF0000&((data)<<16))
#define  ICH1_Hist_Profile_Data_31_ch1_pf_v14_right(data)                       (0x0000FFFF&(data))
#define  ICH1_Hist_Profile_Data_31_get_ch1_pf_v15_right(data)                   ((0xFFFF0000&(data))>>16)
#define  ICH1_Hist_Profile_Data_31_get_ch1_pf_v14_right(data)                   (0x0000FFFF&(data))

#endif 
