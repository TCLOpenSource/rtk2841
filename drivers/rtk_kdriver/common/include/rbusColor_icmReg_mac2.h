/**
* @file rbusColor_icmReg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2012-12-20
* @version 1.1
* @ingroup model_rbus
*
*/

#ifndef _RBUS_COLOR_ICM_REG_H_
#define _RBUS_COLOR_ICM_REG_H_

#include "rbusTypes.h"




// COLOR_ICM Register Address
#define COLOR_ICM_DM_ICM_CTRL_ADDR                 (0x1802a100)
#define COLOR_ICM_DM_ICM_CM0_HUE_RANGE_ADDR        (0x1802a104)
#define COLOR_ICM_DM_ICM_CM0_DEL_HUE_CENTER_ADDR   (0x1802a108)
#define COLOR_ICM_DM_ICM_CM0_DEL_HUE_LEFT_RIGHT_ADDR  (0x1802a10c)
#define COLOR_ICM_DM_ICM_CM0_DEL_SAT_ITN_ADDR      (0x1802a110)
#define COLOR_ICM_DM_ICM_CM1_HUE_RANGE_ADDR        (0x1802a114)
#define COLOR_ICM_DM_ICM_CM1_DEL_HUE_CENTER_ADDR   (0x1802a118)
#define COLOR_ICM_DM_ICM_CM1_DEL_HUE_LEFT_RIGHT_ADDR  (0x1802a11c)
#define COLOR_ICM_DM_ICM_CM1_DEL_SAT_ITN_ADDR      (0x1802a120)
#define COLOR_ICM_DM_ICM_CM2_HUE_RANGE_ADDR        (0x1802a124)
#define COLOR_ICM_DM_ICM_CM2_DEL_HUE_CENTER_ADDR   (0x1802a128)
#define COLOR_ICM_DM_ICM_CM2_DEL_HUE_LEFT_RIGHT_ADDR  (0x1802a12c)
#define COLOR_ICM_DM_ICM_CM2_DEL_SAT_ITN_ADDR      (0x1802a130)
#define COLOR_ICM_DM_ICM_CM3_HUE_RANGE_ADDR        (0x1802a134)
#define COLOR_ICM_DM_ICM_CM3_DEL_HUE_CENTER_ADDR   (0x1802a138)
#define COLOR_ICM_DM_ICM_CM3_DEL_HUE_LEFT_RIGHT_ADDR  (0x1802a13c)
#define COLOR_ICM_DM_ICM_CM3_DEL_SAT_ITN_ADDR      (0x1802a140)
#define COLOR_ICM_DM_ICM_CM4_HUE_RANGE_ADDR        (0x1802a144)
#define COLOR_ICM_DM_ICM_CM4_DEL_HUE_CENTER_ADDR   (0x1802a148)
#define COLOR_ICM_DM_ICM_CM4_DEL_HUE_LEFT_RIGHT_ADDR  (0x1802a14c)
#define COLOR_ICM_DM_ICM_CM4_DEL_SAT_ITN_ADDR      (0x1802a150)
#define COLOR_ICM_DM_ICM_CM5_HUE_RANGE_ADDR        (0x1802a154)
#define COLOR_ICM_DM_ICM_CM5_DEL_HUE_CENTER_ADDR   (0x1802a158)
#define COLOR_ICM_DM_ICM_CM5_DEL_HUE_LEFT_RIGHT_ADDR  (0x1802a15c)
#define COLOR_ICM_DM_ICM_CM5_DEL_SAT_ITN_ADDR      (0x1802a160)
#define COLOR_ICM_DM_ICM_CM6_HUE_RANGE_ADDR        (0x1802a164)
#define COLOR_ICM_DM_ICM_CM6_DEL_HUE_CENTER_ADDR   (0x1802a168)
#define COLOR_ICM_DM_ICM_CM6_DEL_HUE_LEFT_RIGHT_ADDR  (0x1802a16c)
#define COLOR_ICM_DM_ICM_CM6_DEL_SAT_ITN_ADDR      (0x1802a170)
#define COLOR_ICM_DM_UV_CORING_ADDR                (0x1802a174)
#define COLOR_ICM_DM_HUE_ALL_ADDR                  (0x1802a178)
#define COLOR_ICM_DM_SAT_ALL_ADDR                  (0x1802a17c)
#define COLOR_ICM_DM_ITN_ALL_ADDR                  (0x1802a180)
#define COLOR_ICM_DM_SOFT_CLAMP_CTRL_ADDR          (0x1802a184)
#define COLOR_ICM_DM_SOFT_CLAMP_SAT_ADDR           (0x1802a188)
#define COLOR_ICM_DM_SOFT_CLAMP_ITN_ADDR           (0x1802a18c)
#define COLOR_ICM_D_AUTO_SAT_CTRL_ADDR             (0x1802a190)
#define COLOR_ICM_D_AUTO_SAT_ITN_ADDR              (0x1802a194)
#define COLOR_ICM_D_AUTO_SAT_PRE_COUNT_ADDR        (0x1802a198)
#define COLOR_ICM_D_AUTO_SAT_AFTER_COUNT_ADDR      (0x1802a19c)
#define COLOR_ICM_ICM_AUTO_CTRL_ADDR               (0x1802a1c8)
#define COLOR_ICM_HUE_HIST_SETTINGS_ADDR           (0x1802a1cc)
#define COLOR_ICM_HUE_COUNT_00_ADDR                (0x1802a1d0)
#define COLOR_ICM_HUE_COUNT_01_ADDR                (0x1802a1d4)
#define COLOR_ICM_HUE_COUNT_02_ADDR                (0x1802a1d8)
#define COLOR_ICM_HUE_COUNT_03_ADDR                (0x1802a1dc)
#define COLOR_ICM_HUE_COUNT_04_ADDR                (0x1802a1e0)
#define COLOR_ICM_HUE_COUNT_05_ADDR                (0x1802a1e4)
#define COLOR_ICM_HUE_COUNT_06_ADDR                (0x1802a1e8)
#define COLOR_ICM_HUE_COUNT_07_ADDR                (0x1802a1ec)
#define COLOR_ICM_HUE_COUNT_08_ADDR                (0x1802a1f0)
#define COLOR_ICM_HUE_COUNT_09_ADDR                (0x1802a1f4)
#define COLOR_ICM_HUE_COUNT_0A_ADDR                (0x1802a1f8)
#define COLOR_ICM_HUE_COUNT_0B_ADDR                (0x1802a1fc)
#define COLOR_ICM_HUE_COUNT_0C_ADDR                (0x1802a200)
#define COLOR_ICM_HUE_COUNT_0D_ADDR                (0x1802a204)
#define COLOR_ICM_HUE_COUNT_0E_ADDR                (0x1802a208)
#define COLOR_ICM_HUE_COUNT_0F_ADDR                (0x1802a20c)
#define COLOR_ICM_HUE_COUNT_10_ADDR                (0x1802a210)
#define COLOR_ICM_HUE_COUNT_11_ADDR                (0x1802a214)
#define COLOR_ICM_HUE_COUNT_12_ADDR                (0x1802a218)
#define COLOR_ICM_HUE_COUNT_13_ADDR                (0x1802a21c)
#define COLOR_ICM_HUE_COUNT_14_ADDR                (0x1802a220)
#define COLOR_ICM_HUE_COUNT_15_ADDR                (0x1802a224)
#define COLOR_ICM_HUE_COUNT_16_ADDR                (0x1802a228)
#define COLOR_ICM_HUE_COUNT_17_ADDR                (0x1802a22c)
#define COLOR_ICM_HUE_SUM_00_ADDR                  (0x1802a230)
#define COLOR_ICM_HUE_SUM_01_ADDR                  (0x1802a234)
#define COLOR_ICM_HUE_SUM_02_ADDR                  (0x1802a238)
#define COLOR_ICM_HUE_SUM_03_ADDR                  (0x1802a23c)
#define COLOR_ICM_HUE_SUM_04_ADDR                  (0x1802a240)
#define COLOR_ICM_HUE_SUM_05_ADDR                  (0x1802a244)
#define COLOR_ICM_DM_ADJ_BYITN_CTRL_ADDR           (0x1802a248)
#define COLOR_ICM_DM_ADJ_BYITN_LB_CM0_3_ADDR       (0x1802a24c)
#define COLOR_ICM_DM_ADJ_BYITN_LB_CM4_6_ADDR       (0x1802a250)
#define COLOR_ICM_DM_ADJ_BYITN_BUF_ADDR            (0x1802a254)
#define COLOR_ICM_DM_ADJ_BYITN_DSAT_DHUE_CM0_ADDR  (0x1802a258)
#define COLOR_ICM_DM_ADJ_BYITN_DSAT_DHUE_CM1_ADDR  (0x1802a25c)
#define COLOR_ICM_DM_ADJ_BYITN_DSAT_DHUE_CM2_ADDR  (0x1802a260)
#define COLOR_ICM_DM_ADJ_BYITN_DSAT_DHUE_CM3_ADDR  (0x1802a264)
#define COLOR_ICM_DM_ADJ_BYITN_DSAT_DHUE_CM4_ADDR  (0x1802a268)
#define COLOR_ICM_DM_ADJ_BYITN_DSAT_DHUE_CM5_ADDR  (0x1802a26c)
#define COLOR_ICM_DM_ADJ_BYITN_DSAT_DHUE_CM6_ADDR  (0x1802a270)
#define COLOR_ICM_DM_SEG_SHY_ADJ_CTRL_ADDR         (0x1802a360)
#define COLOR_ICM_DM_SEG_SHY_SRAM_CTRL_ADDR        (0x1802a364)
#define COLOR_ICM_DM_SEG_SHY_SRAM_BIST_ADDR        (0x1802a368)
#define COLOR_ICM_DM_SEG_SHY_SRAM_BIST_2_ADDR      (0x1802a36c)
#define COLOR_ICM_DM_SEG_SHY_WRITE_SEG_0_ADDR      (0x1802a370)
#define COLOR_ICM_DM_SEG_SHY_WRITE_SEG_1_ADDR      (0x1802a374)
#define COLOR_ICM_DM_SEG_SHY_WRITE_SEG_2_ADDR      (0x1802a378)
#define COLOR_ICM_DM_SEG_SHY_WRITE_SEG_3_ADDR      (0x1802a37c)
#define COLOR_ICM_DM_SEG_SHY_WRITE_SEG_4_ADDR      (0x1802a380)
#define COLOR_ICM_DM_SEG_SHY_WRITE_SEG_5_ADDR      (0x1802a384)
#define COLOR_ICM_DM_SEG_SHY_WRITE_SEG_6_ADDR      (0x1802a388)
#define COLOR_ICM_DM_SEG_SHY_WRITE_SEG_7_ADDR      (0x1802a38c)
#define COLOR_ICM_DM_SEG_SHY_WRITE_SEG_RANDOM_ADDR (0x1802a390)
#define COLOR_ICM_DM_SEG_SHY_READ_SEG_RANDOM_ADDR  (0x1802a394)
#define COLOR_ICM_ICM_CRC_CTRL_ADDR                (0x1802a3d0)
#define COLOR_ICM_ICM_CRC_RESULT_ADDR              (0x1802a3d4)
#define COLOR_ICM_DM_ICM_CM0_DEL_HUE_KERNEL_ADDR   (0x1802a400)
#define COLOR_ICM_DM_ICM_CM0_DEL_SAT_LEFT_ADDR     (0x1802a404)
#define COLOR_ICM_DM_ICM_CM0_DEL_SAT_RIGHT_ADDR    (0x1802a408)
#define COLOR_ICM_DM_ICM_CM1_DEL_HUE_KERNEL_ADDR   (0x1802a40c)
#define COLOR_ICM_DM_ICM_CM1_DEL_SAT_LEFT_ADDR     (0x1802a410)
#define COLOR_ICM_DM_ICM_CM1_DEL_SAT_RIGHT_ADDR    (0x1802a414)
#define COLOR_ICM_DM_ICM_CM2_DEL_HUE_KERNEL_ADDR   (0x1802a418)
#define COLOR_ICM_DM_ICM_CM2_DEL_SAT_LEFT_ADDR     (0x1802a41c)
#define COLOR_ICM_DM_ICM_CM2_DEL_SAT_RIGHT_ADDR    (0x1802a420)
#define COLOR_ICM_DM_ICM_CM3_DEL_HUE_KERNEL_ADDR   (0x1802a424)
#define COLOR_ICM_DM_ICM_CM3_DEL_SAT_LEFT_ADDR     (0x1802a428)
#define COLOR_ICM_DM_ICM_CM3_DEL_SAT_RIGHT_ADDR    (0x1802a42c)
#define COLOR_ICM_DM_ICM_CM4_DEL_HUE_KERNEL_ADDR   (0x1802a430)
#define COLOR_ICM_DM_ICM_CM4_DEL_SAT_LEFT_ADDR     (0x1802a434)
#define COLOR_ICM_DM_ICM_CM4_DEL_SAT_RIGHT_ADDR    (0x1802a438)
#define COLOR_ICM_DM_ICM_CM5_DEL_HUE_KERNEL_ADDR   (0x1802a43c)
#define COLOR_ICM_DM_ICM_CM5_DEL_SAT_LEFT_ADDR     (0x1802a440)
#define COLOR_ICM_DM_ICM_CM5_DEL_SAT_RIGHT_ADDR    (0x1802a444)
#define COLOR_ICM_DM_ICM_CM6_DEL_HUE_KERNEL_ADDR   (0x1802a448)
#define COLOR_ICM_DM_ICM_CM6_DEL_SAT_LEFT_ADDR     (0x1802a44c)
#define COLOR_ICM_DM_ICM_CM6_DEL_SAT_RIGHT_ADDR    (0x1802a450)
#define COLOR_ICM_DM_ICM_MERGE_H_CM01_ADDR         (0x1802a4b0)
#define COLOR_ICM_DM_ICM_MERGE_SI_CM01_ADDR        (0x1802a4b4)
#define COLOR_ICM_DM_ICM_MERGE_H_CM12_ADDR         (0x1802a4b8)
#define COLOR_ICM_DM_ICM_MERGE_SI_CM12_ADDR        (0x1802a4bc)
#define COLOR_ICM_DM_ICM_MERGE_H_CM23_ADDR         (0x1802a4c0)
#define COLOR_ICM_DM_ICM_MERGE_SI_CM23_ADDR        (0x1802a4c4)
#define COLOR_ICM_DM_ICM_MERGE_H_CM34_ADDR         (0x1802a4c8)
#define COLOR_ICM_DM_ICM_MERGE_SI_CM34_ADDR        (0x1802a4cc)
#define COLOR_ICM_DM_ICM_MERGE_H_CM45_ADDR         (0x1802a4d0)
#define COLOR_ICM_DM_ICM_MERGE_SI_CM45_ADDR        (0x1802a4d4)
#define COLOR_ICM_DM_ICM_MERGE_H_CM56_ADDR         (0x1802a4d8)
#define COLOR_ICM_DM_ICM_MERGE_SI_CM56_ADDR        (0x1802a4dc)
#define COLOR_ICM_DM_ICM_MERGE_H_CM60_ADDR         (0x1802a4e0)
#define COLOR_ICM_DM_ICM_MERGE_SI_CM60_ADDR        (0x1802a4e4)
#define COLOR_ICM_DM_ICM_SI_CLIP_ADDR              (0x1802a4e8)
#define COLOR_ICM_DM_ICM_SI_CLIP_THRESHOLD_ADDR    (0x1802a4ec)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_00_ADDR  (0x1802a920)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_01_ADDR  (0x1802a924)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_02_ADDR  (0x1802a928)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_03_ADDR  (0x1802a92c)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_04_ADDR  (0x1802a930)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_05_ADDR  (0x1802a934)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_06_ADDR  (0x1802a938)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_07_ADDR  (0x1802a93c)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_08_ADDR  (0x1802a940)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_09_ADDR  (0x1802a944)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_10_ADDR  (0x1802a948)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_11_ADDR  (0x1802a94c)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_12_ADDR  (0x1802a950)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_13_ADDR  (0x1802a954)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_14_ADDR  (0x1802a958)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_15_ADDR  (0x1802a95c)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_16_ADDR  (0x1802a960)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_17_ADDR  (0x1802a964)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_18_ADDR  (0x1802a968)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_19_ADDR  (0x1802a96c)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_20_ADDR  (0x1802a970)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_21_ADDR  (0x1802a974)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_22_ADDR  (0x1802a978)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_23_ADDR  (0x1802a97c)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_24_ADDR  (0x1802a980)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_25_ADDR  (0x1802a984)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_26_ADDR  (0x1802a988)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_27_ADDR  (0x1802a98c)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_28_ADDR  (0x1802a990)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_29_ADDR  (0x1802a994)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_30_ADDR  (0x1802a998)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_31_ADDR  (0x1802a99c)

#define COLOR_ICM_DM_ICM_CTRL_VADDR                (0xb802a100)
#define COLOR_ICM_DM_ICM_CM0_HUE_RANGE_VADDR       (0xb802a104)
#define COLOR_ICM_DM_ICM_CM0_DEL_HUE_CENTER_VADDR  (0xb802a108)
#define COLOR_ICM_DM_ICM_CM0_DEL_HUE_LEFT_RIGHT_VADDR  (0xb802a10c)
#define COLOR_ICM_DM_ICM_CM0_DEL_SAT_ITN_VADDR     (0xb802a110)
#define COLOR_ICM_DM_ICM_CM1_HUE_RANGE_VADDR       (0xb802a114)
#define COLOR_ICM_DM_ICM_CM1_DEL_HUE_CENTER_VADDR  (0xb802a118)
#define COLOR_ICM_DM_ICM_CM1_DEL_HUE_LEFT_RIGHT_VADDR  (0xb802a11c)
#define COLOR_ICM_DM_ICM_CM1_DEL_SAT_ITN_VADDR     (0xb802a120)
#define COLOR_ICM_DM_ICM_CM2_HUE_RANGE_VADDR       (0xb802a124)
#define COLOR_ICM_DM_ICM_CM2_DEL_HUE_CENTER_VADDR  (0xb802a128)
#define COLOR_ICM_DM_ICM_CM2_DEL_HUE_LEFT_RIGHT_VADDR  (0xb802a12c)
#define COLOR_ICM_DM_ICM_CM2_DEL_SAT_ITN_VADDR     (0xb802a130)
#define COLOR_ICM_DM_ICM_CM3_HUE_RANGE_VADDR       (0xb802a134)
#define COLOR_ICM_DM_ICM_CM3_DEL_HUE_CENTER_VADDR  (0xb802a138)
#define COLOR_ICM_DM_ICM_CM3_DEL_HUE_LEFT_RIGHT_VADDR  (0xb802a13c)
#define COLOR_ICM_DM_ICM_CM3_DEL_SAT_ITN_VADDR     (0xb802a140)
#define COLOR_ICM_DM_ICM_CM4_HUE_RANGE_VADDR       (0xb802a144)
#define COLOR_ICM_DM_ICM_CM4_DEL_HUE_CENTER_VADDR  (0xb802a148)
#define COLOR_ICM_DM_ICM_CM4_DEL_HUE_LEFT_RIGHT_VADDR  (0xb802a14c)
#define COLOR_ICM_DM_ICM_CM4_DEL_SAT_ITN_VADDR     (0xb802a150)
#define COLOR_ICM_DM_ICM_CM5_HUE_RANGE_VADDR       (0xb802a154)
#define COLOR_ICM_DM_ICM_CM5_DEL_HUE_CENTER_VADDR  (0xb802a158)
#define COLOR_ICM_DM_ICM_CM5_DEL_HUE_LEFT_RIGHT_VADDR  (0xb802a15c)
#define COLOR_ICM_DM_ICM_CM5_DEL_SAT_ITN_VADDR     (0xb802a160)
#define COLOR_ICM_DM_ICM_CM6_HUE_RANGE_VADDR       (0xb802a164)
#define COLOR_ICM_DM_ICM_CM6_DEL_HUE_CENTER_VADDR  (0xb802a168)
#define COLOR_ICM_DM_ICM_CM6_DEL_HUE_LEFT_RIGHT_VADDR  (0xb802a16c)
#define COLOR_ICM_DM_ICM_CM6_DEL_SAT_ITN_VADDR     (0xb802a170)
#define COLOR_ICM_DM_UV_CORING_VADDR               (0xb802a174)
#define COLOR_ICM_DM_HUE_ALL_VADDR                 (0xb802a178)
#define COLOR_ICM_DM_SAT_ALL_VADDR                 (0xb802a17c)
#define COLOR_ICM_DM_ITN_ALL_VADDR                 (0xb802a180)
#define COLOR_ICM_DM_SOFT_CLAMP_CTRL_VADDR         (0xb802a184)
#define COLOR_ICM_DM_SOFT_CLAMP_SAT_VADDR          (0xb802a188)
#define COLOR_ICM_DM_SOFT_CLAMP_ITN_VADDR          (0xb802a18c)
#define COLOR_ICM_D_AUTO_SAT_CTRL_VADDR            (0xb802a190)
#define COLOR_ICM_D_AUTO_SAT_ITN_VADDR             (0xb802a194)
#define COLOR_ICM_D_AUTO_SAT_PRE_COUNT_VADDR       (0xb802a198)
#define COLOR_ICM_D_AUTO_SAT_AFTER_COUNT_VADDR     (0xb802a19c)
#define COLOR_ICM_ICM_AUTO_CTRL_VADDR              (0xb802a1c8)
#define COLOR_ICM_HUE_HIST_SETTINGS_VADDR          (0xb802a1cc)
#define COLOR_ICM_HUE_COUNT_00_VADDR               (0xb802a1d0)
#define COLOR_ICM_HUE_COUNT_01_VADDR               (0xb802a1d4)
#define COLOR_ICM_HUE_COUNT_02_VADDR               (0xb802a1d8)
#define COLOR_ICM_HUE_COUNT_03_VADDR               (0xb802a1dc)
#define COLOR_ICM_HUE_COUNT_04_VADDR               (0xb802a1e0)
#define COLOR_ICM_HUE_COUNT_05_VADDR               (0xb802a1e4)
#define COLOR_ICM_HUE_COUNT_06_VADDR               (0xb802a1e8)
#define COLOR_ICM_HUE_COUNT_07_VADDR               (0xb802a1ec)
#define COLOR_ICM_HUE_COUNT_08_VADDR               (0xb802a1f0)
#define COLOR_ICM_HUE_COUNT_09_VADDR               (0xb802a1f4)
#define COLOR_ICM_HUE_COUNT_0A_VADDR               (0xb802a1f8)
#define COLOR_ICM_HUE_COUNT_0B_VADDR               (0xb802a1fc)
#define COLOR_ICM_HUE_COUNT_0C_VADDR               (0xb802a200)
#define COLOR_ICM_HUE_COUNT_0D_VADDR               (0xb802a204)
#define COLOR_ICM_HUE_COUNT_0E_VADDR               (0xb802a208)
#define COLOR_ICM_HUE_COUNT_0F_VADDR               (0xb802a20c)
#define COLOR_ICM_HUE_COUNT_10_VADDR               (0xb802a210)
#define COLOR_ICM_HUE_COUNT_11_VADDR               (0xb802a214)
#define COLOR_ICM_HUE_COUNT_12_VADDR               (0xb802a218)
#define COLOR_ICM_HUE_COUNT_13_VADDR               (0xb802a21c)
#define COLOR_ICM_HUE_COUNT_14_VADDR               (0xb802a220)
#define COLOR_ICM_HUE_COUNT_15_VADDR               (0xb802a224)
#define COLOR_ICM_HUE_COUNT_16_VADDR               (0xb802a228)
#define COLOR_ICM_HUE_COUNT_17_VADDR               (0xb802a22c)
#define COLOR_ICM_HUE_SUM_00_VADDR                 (0xb802a230)
#define COLOR_ICM_HUE_SUM_01_VADDR                 (0xb802a234)
#define COLOR_ICM_HUE_SUM_02_VADDR                 (0xb802a238)
#define COLOR_ICM_HUE_SUM_03_VADDR                 (0xb802a23c)
#define COLOR_ICM_HUE_SUM_04_VADDR                 (0xb802a240)
#define COLOR_ICM_HUE_SUM_05_VADDR                 (0xb802a244)
#define COLOR_ICM_DM_ADJ_BYITN_CTRL_VADDR          (0xb802a248)
#define COLOR_ICM_DM_ADJ_BYITN_LB_CM0_3_VADDR      (0xb802a24c)
#define COLOR_ICM_DM_ADJ_BYITN_LB_CM4_6_VADDR      (0xb802a250)
#define COLOR_ICM_DM_ADJ_BYITN_BUF_VADDR           (0xb802a254)
#define COLOR_ICM_DM_ADJ_BYITN_DSAT_DHUE_CM0_VADDR (0xb802a258)
#define COLOR_ICM_DM_ADJ_BYITN_DSAT_DHUE_CM1_VADDR (0xb802a25c)
#define COLOR_ICM_DM_ADJ_BYITN_DSAT_DHUE_CM2_VADDR (0xb802a260)
#define COLOR_ICM_DM_ADJ_BYITN_DSAT_DHUE_CM3_VADDR (0xb802a264)
#define COLOR_ICM_DM_ADJ_BYITN_DSAT_DHUE_CM4_VADDR (0xb802a268)
#define COLOR_ICM_DM_ADJ_BYITN_DSAT_DHUE_CM5_VADDR (0xb802a26c)
#define COLOR_ICM_DM_ADJ_BYITN_DSAT_DHUE_CM6_VADDR (0xb802a270)
#define COLOR_ICM_DM_SEG_SHY_ADJ_CTRL_VADDR        (0xb802a360)
#define COLOR_ICM_DM_SEG_SHY_SRAM_CTRL_VADDR       (0xb802a364)
#define COLOR_ICM_DM_SEG_SHY_SRAM_BIST_VADDR       (0xb802a368)
#define COLOR_ICM_DM_SEG_SHY_SRAM_BIST_2_VADDR     (0xb802a36c)
#define COLOR_ICM_DM_SEG_SHY_WRITE_SEG_0_VADDR     (0xb802a370)
#define COLOR_ICM_DM_SEG_SHY_WRITE_SEG_1_VADDR     (0xb802a374)
#define COLOR_ICM_DM_SEG_SHY_WRITE_SEG_2_VADDR     (0xb802a378)
#define COLOR_ICM_DM_SEG_SHY_WRITE_SEG_3_VADDR     (0xb802a37c)
#define COLOR_ICM_DM_SEG_SHY_WRITE_SEG_4_VADDR     (0xb802a380)
#define COLOR_ICM_DM_SEG_SHY_WRITE_SEG_5_VADDR     (0xb802a384)
#define COLOR_ICM_DM_SEG_SHY_WRITE_SEG_6_VADDR     (0xb802a388)
#define COLOR_ICM_DM_SEG_SHY_WRITE_SEG_7_VADDR     (0xb802a38c)
#define COLOR_ICM_DM_SEG_SHY_WRITE_SEG_RANDOM_VADDR  (0xb802a390)
#define COLOR_ICM_DM_SEG_SHY_READ_SEG_RANDOM_VADDR (0xb802a394)
#define COLOR_ICM_ICM_CRC_CTRL_VADDR               (0xb802a3d0)
#define COLOR_ICM_ICM_CRC_RESULT_VADDR             (0xb802a3d4)
#define COLOR_ICM_DM_ICM_CM0_DEL_HUE_KERNEL_VADDR  (0xb802a400)
#define COLOR_ICM_DM_ICM_CM0_DEL_SAT_LEFT_VADDR    (0xb802a404)
#define COLOR_ICM_DM_ICM_CM0_DEL_SAT_RIGHT_VADDR   (0xb802a408)
#define COLOR_ICM_DM_ICM_CM1_DEL_HUE_KERNEL_VADDR  (0xb802a40c)
#define COLOR_ICM_DM_ICM_CM1_DEL_SAT_LEFT_VADDR    (0xb802a410)
#define COLOR_ICM_DM_ICM_CM1_DEL_SAT_RIGHT_VADDR   (0xb802a414)
#define COLOR_ICM_DM_ICM_CM2_DEL_HUE_KERNEL_VADDR  (0xb802a418)
#define COLOR_ICM_DM_ICM_CM2_DEL_SAT_LEFT_VADDR    (0xb802a41c)
#define COLOR_ICM_DM_ICM_CM2_DEL_SAT_RIGHT_VADDR   (0xb802a420)
#define COLOR_ICM_DM_ICM_CM3_DEL_HUE_KERNEL_VADDR  (0xb802a424)
#define COLOR_ICM_DM_ICM_CM3_DEL_SAT_LEFT_VADDR    (0xb802a428)
#define COLOR_ICM_DM_ICM_CM3_DEL_SAT_RIGHT_VADDR   (0xb802a42c)
#define COLOR_ICM_DM_ICM_CM4_DEL_HUE_KERNEL_VADDR  (0xb802a430)
#define COLOR_ICM_DM_ICM_CM4_DEL_SAT_LEFT_VADDR    (0xb802a434)
#define COLOR_ICM_DM_ICM_CM4_DEL_SAT_RIGHT_VADDR   (0xb802a438)
#define COLOR_ICM_DM_ICM_CM5_DEL_HUE_KERNEL_VADDR  (0xb802a43c)
#define COLOR_ICM_DM_ICM_CM5_DEL_SAT_LEFT_VADDR    (0xb802a440)
#define COLOR_ICM_DM_ICM_CM5_DEL_SAT_RIGHT_VADDR   (0xb802a444)
#define COLOR_ICM_DM_ICM_CM6_DEL_HUE_KERNEL_VADDR  (0xb802a448)
#define COLOR_ICM_DM_ICM_CM6_DEL_SAT_LEFT_VADDR    (0xb802a44c)
#define COLOR_ICM_DM_ICM_CM6_DEL_SAT_RIGHT_VADDR   (0xb802a450)
#define COLOR_ICM_DM_ICM_MERGE_H_CM01_VADDR        (0xb802a4b0)
#define COLOR_ICM_DM_ICM_MERGE_SI_CM01_VADDR       (0xb802a4b4)
#define COLOR_ICM_DM_ICM_MERGE_H_CM12_VADDR        (0xb802a4b8)
#define COLOR_ICM_DM_ICM_MERGE_SI_CM12_VADDR       (0xb802a4bc)
#define COLOR_ICM_DM_ICM_MERGE_H_CM23_VADDR        (0xb802a4c0)
#define COLOR_ICM_DM_ICM_MERGE_SI_CM23_VADDR       (0xb802a4c4)
#define COLOR_ICM_DM_ICM_MERGE_H_CM34_VADDR        (0xb802a4c8)
#define COLOR_ICM_DM_ICM_MERGE_SI_CM34_VADDR       (0xb802a4cc)
#define COLOR_ICM_DM_ICM_MERGE_H_CM45_VADDR        (0xb802a4d0)
#define COLOR_ICM_DM_ICM_MERGE_SI_CM45_VADDR       (0xb802a4d4)
#define COLOR_ICM_DM_ICM_MERGE_H_CM56_VADDR        (0xb802a4d8)
#define COLOR_ICM_DM_ICM_MERGE_SI_CM56_VADDR       (0xb802a4dc)
#define COLOR_ICM_DM_ICM_MERGE_H_CM60_VADDR        (0xb802a4e0)
#define COLOR_ICM_DM_ICM_MERGE_SI_CM60_VADDR       (0xb802a4e4)
#define COLOR_ICM_DM_ICM_SI_CLIP_VADDR             (0xb802a4e8)
#define COLOR_ICM_DM_ICM_SI_CLIP_THRESHOLD_VADDR   (0xb802a4ec)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_00_VADDR  (0xb802a920)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_01_VADDR  (0xb802a924)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_02_VADDR  (0xb802a928)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_03_VADDR  (0xb802a92c)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_04_VADDR  (0xb802a930)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_05_VADDR  (0xb802a934)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_06_VADDR  (0xb802a938)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_07_VADDR  (0xb802a93c)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_08_VADDR  (0xb802a940)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_09_VADDR  (0xb802a944)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_10_VADDR  (0xb802a948)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_11_VADDR  (0xb802a94c)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_12_VADDR  (0xb802a950)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_13_VADDR  (0xb802a954)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_14_VADDR  (0xb802a958)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_15_VADDR  (0xb802a95c)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_16_VADDR  (0xb802a960)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_17_VADDR  (0xb802a964)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_18_VADDR  (0xb802a968)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_19_VADDR  (0xb802a96c)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_20_VADDR  (0xb802a970)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_21_VADDR  (0xb802a974)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_22_VADDR  (0xb802a978)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_23_VADDR  (0xb802a97c)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_24_VADDR  (0xb802a980)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_25_VADDR  (0xb802a984)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_26_VADDR  (0xb802a988)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_27_VADDR  (0xb802a98c)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_28_VADDR  (0xb802a990)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_29_VADDR  (0xb802a994)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_30_VADDR  (0xb802a998)
#define COLOR_ICM_D_ICM_AUTO_SAT_NEW_MODE_CNT_31_VADDR  (0xb802a99c)




#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======COLOR_ICM register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_ctrl:1;
        RBus_UInt32  bypass_yuv2rgb_enable:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  icm_dummy1:5;
        RBus_UInt32  merge_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  delta_i_smooth_enable:1;
	//RBus_UInt32  res3:2;
	RBus_UInt32  only_one_delta_sat_enable:1;//2012/11/16
	RBus_UInt32  kernel_enable:1;//
        RBus_UInt32  cm_debug:3;
        RBus_UInt32  icm_dummy2:9;
        RBus_UInt32  cm0_enable:1;
        RBus_UInt32  cm1_enable:1;
        RBus_UInt32  cm2_enable:1;
        RBus_UInt32  cm3_enable:1;
        RBus_UInt32  cm4_enable:1;
        RBus_UInt32  cm5_enable:1;
        RBus_UInt32  cm6_enable:1;
    };
}dm_icm_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_kernel:3;
        RBus_UInt32  l_range:3;
        RBus_UInt32  l_buffer:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  r_kernel:3;
        RBus_UInt32  r_range:3;
        RBus_UInt32  r_buffer:3;
        RBus_UInt32  res2:2;
        RBus_UInt32  center:11;
    };
}dm_icm_cm0_hue_range_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  del_center:11;
    };
}dm_icm_cm0_del_hue_center_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  del_left:11;
        RBus_UInt32  del_right:11;
    };
}dm_icm_cm0_del_hue_left_right_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  del_sat:12;
        RBus_UInt32  del_itn:12;
    };
}dm_icm_cm0_del_sat_itn_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_kernel:3;
        RBus_UInt32  l_range:3;
        RBus_UInt32  l_buffer:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  r_kernel:3;
        RBus_UInt32  r_range:3;
        RBus_UInt32  r_buffer:3;
        RBus_UInt32  res2:2;
        RBus_UInt32  center:11;
    };
}dm_icm_cm1_hue_range_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  del_center:11;
    };
}dm_icm_cm1_del_hue_center_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  del_left:11;
        RBus_UInt32  del_right:11;
    };
}dm_icm_cm1_del_hue_left_right_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  del_sat:12;
        RBus_UInt32  del_itn:12;
    };
}dm_icm_cm1_del_sat_itn_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_kernel:3;
        RBus_UInt32  l_range:3;
        RBus_UInt32  l_buffer:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  r_kernel:3;
        RBus_UInt32  r_range:3;
        RBus_UInt32  r_buffer:3;
        RBus_UInt32  res2:2;
        RBus_UInt32  center:11;
    };
}dm_icm_cm2_hue_range_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  del_center:11;
    };
}dm_icm_cm2_del_hue_center_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  del_left:11;
        RBus_UInt32  del_right:11;
    };
}dm_icm_cm2_del_hue_left_right_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  del_sat:12;
        RBus_UInt32  del_itn:12;
    };
}dm_icm_cm2_del_sat_itn_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_kernel:3;
        RBus_UInt32  l_range:3;
        RBus_UInt32  l_buffer:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  r_kernel:3;
        RBus_UInt32  r_range:3;
        RBus_UInt32  r_buffer:3;
        RBus_UInt32  res2:2;
        RBus_UInt32  center:11;
    };
}dm_icm_cm3_hue_range_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  del_center:11;
    };
}dm_icm_cm3_del_hue_center_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  del_left:11;
        RBus_UInt32  del_right:11;
    };
}dm_icm_cm3_del_hue_left_right_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  del_sat:12;
        RBus_UInt32  del_itn:12;
    };
}dm_icm_cm3_del_sat_itn_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_kernel:3;
        RBus_UInt32  l_range:3;
        RBus_UInt32  l_buffer:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  r_kernel:3;
        RBus_UInt32  r_range:3;
        RBus_UInt32  r_buffer:3;
        RBus_UInt32  res2:2;
        RBus_UInt32  center:11;
    };
}dm_icm_cm4_hue_range_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  del_center:11;
    };
}dm_icm_cm4_del_hue_center_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  del_left:11;
        RBus_UInt32  del_right:11;
    };
}dm_icm_cm4_del_hue_left_right_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  del_sat:12;
        RBus_UInt32  del_itn:12;
    };
}dm_icm_cm4_del_sat_itn_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_kernel:3;
        RBus_UInt32  l_range:3;
        RBus_UInt32  l_buffer:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  r_kernel:3;
        RBus_UInt32  r_range:3;
        RBus_UInt32  r_buffer:3;
        RBus_UInt32  res2:2;
        RBus_UInt32  center:11;
    };
}dm_icm_cm5_hue_range_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  del_center:11;
    };
}dm_icm_cm5_del_hue_center_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  del_left:11;
        RBus_UInt32  del_right:11;
    };
}dm_icm_cm5_del_hue_left_right_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  del_sat:12;
        RBus_UInt32  del_itn:12;
    };
}dm_icm_cm5_del_sat_itn_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_kernel:3;
        RBus_UInt32  l_range:3;
        RBus_UInt32  l_buffer:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  r_kernel:3;
        RBus_UInt32  r_range:3;
        RBus_UInt32  r_buffer:3;
        RBus_UInt32  res2:2;
        RBus_UInt32  center:11;
    };
}dm_icm_cm6_hue_range_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  del_center:11;
    };
}dm_icm_cm6_del_hue_center_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  del_left:11;
        RBus_UInt32  del_right:11;
    };
}dm_icm_cm6_del_hue_left_right_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  del_sat:12;
        RBus_UInt32  del_itn:12;
    };
}dm_icm_cm6_del_sat_itn_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  u_coring:8;
        RBus_UInt32  v_coring:8;
    };
}dm_uv_coring_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802a178_31_11:21;
        RBus_UInt32  hue_all:11;
    };
}dm_hue_all_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  sat_all:12;
    };
}dm_sat_all_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  itn_all:12;
    };
}dm_itn_all_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_clip_sel:1;
        RBus_UInt32  sat_multi_clip_sel:1;
        RBus_UInt32  int_clip_sel:1;
        RBus_UInt32  int_multi_clip_sel:1;
        RBus_UInt32  res1:25;
        RBus_UInt32  neg_int_flag_en:1;
        RBus_UInt32  sat_enable:1;
        RBus_UInt32  itn_enable:1;
    };
}dm_soft_clamp_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_slope:4;
        RBus_UInt32  sat_thd:12;
        RBus_UInt32  res1:3;
        RBus_UInt32  sat_max:13;
    };
}dm_soft_clamp_sat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  itn_slope:4;
        RBus_UInt32  itn_thd:12;
        RBus_UInt32  res1:3;
        RBus_UInt32  itn_max:13;
    };
}dm_soft_clamp_itn_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  auto_sat_i_u_thre:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  auto_sat_i_l_thre:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  auto_sat_s_thre:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  auto_sat_new_mode:2;
        RBus_UInt32  sat_hist_mode_sel:1;
        RBus_UInt32  hist_sat_ok:1;
        RBus_UInt32  sat_enable:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
    };
}d_auto_sat_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist_ctrl:8;
        RBus_UInt32  l_bound:4;
        RBus_UInt32  u_bound:4;
        RBus_UInt32  gain_lo:4;
        RBus_UInt32  gain_hi:4;
        RBus_UInt32  sat_offset:8;
    };
}d_auto_sat_itn_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist_ctrl_status:8;
        RBus_UInt32  pre_cnt:24;
    };
}d_auto_sat_pre_count_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  aft_cnt:24;
    };
}d_auto_sat_after_count_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  hue_hist_mode_sel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  hist_hue_ok:1;
        RBus_UInt32  hue_enable:1;
        RBus_UInt32  inside_enable:1;
    };
}icm_auto_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_hist_offset_add:8;
        RBus_UInt32  hue_hist_sat_lb:8;
        RBus_UInt32  hue_hist_itn_hb:8;
        RBus_UInt32  hue_hist_itn_lb:8;
    };
}hue_hist_settings_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  lut0:24;
    };
}hue_count_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  lut1:24;
    };
}hue_count_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  lut2:24;
    };
}hue_count_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  lut3:24;
    };
}hue_count_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  lut4:24;
    };
}hue_count_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  lut5:24;
    };
}hue_count_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  lut6:24;
    };
}hue_count_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  lut7:24;
    };
}hue_count_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  lut8:24;
    };
}hue_count_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  lut9:24;
    };
}hue_count_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  lut10:24;
    };
}hue_count_0a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  lut11:24;
    };
}hue_count_0b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  lut12:24;
    };
}hue_count_0c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  lut13:24;
    };
}hue_count_0d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  lut14:24;
    };
}hue_count_0e_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  lut15:24;
    };
}hue_count_0f_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  lut16:24;
    };
}hue_count_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  lut17:24;
    };
}hue_count_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  lut18:24;
    };
}hue_count_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  lut19:24;
    };
}hue_count_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  lut20:24;
    };
}hue_count_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  lut21:24;
    };
}hue_count_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  lut22:24;
    };
}hue_count_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  lut23:24;
    };
}hue_count_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut0:32;
    };
}hue_sum_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut1:32;
    };
}hue_sum_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut2:32;
    };
}hue_sum_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut3:32;
    };
}hue_sum_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut4:32;
    };
}hue_sum_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut5:32;
    };
}hue_sum_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  itnlevel_debug_satlevel_sel:2;
        RBus_UInt32  itnlevel_debug_cm_sel:3;
        RBus_UInt32  itnlevel_debug_enable:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  dhuebyitn_cm0_enable:1;
        RBus_UInt32  dhuebyitn_cm1_enable:1;
        RBus_UInt32  dhuebyitn_cm2_enable:1;
        RBus_UInt32  dhuebyitn_cm3_enable:1;
        RBus_UInt32  dhuebyitn_cm4_enable:1;
        RBus_UInt32  dhuebyitn_cm5_enable:1;
        RBus_UInt32  dhuebyitn_cm6_enable:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  dsatbyitn_cm0_enable:1;
        RBus_UInt32  dsatbyitn_cm1_enable:1;
        RBus_UInt32  dsatbyitn_cm2_enable:1;
        RBus_UInt32  dsatbyitn_cm3_enable:1;
        RBus_UInt32  dsatbyitn_cm4_enable:1;
        RBus_UInt32  dsatbyitn_cm5_enable:1;
        RBus_UInt32  dsatbyitn_cm6_enable:1;
    };
}dm_adj_byitn_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cm3_itn_lb:8;
        RBus_UInt32  cm2_itn_lb:8;
        RBus_UInt32  cm1_itn_lb:8;
        RBus_UInt32  cm0_itn_lb:8;
    };
}dm_adj_byitn_lb_cm0_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cm6_itn_lb:8;
        RBus_UInt32  cm5_itn_lb:8;
        RBus_UInt32  cm4_itn_lb:8;
    };
}dm_adj_byitn_lb_cm4_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  cm6_itn_buffer:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  cm5_itn_buffer:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  cm4_itn_buffer:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  cm3_itn_buffer:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  cm2_itn_buffer:3;
        RBus_UInt32  res6:1;
        RBus_UInt32  cm1_itn_buffer:3;
        RBus_UInt32  res7:1;
        RBus_UInt32  cm0_itn_buffer:3;
    };
}dm_adj_byitn_buf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  cm0_dhue:11;
        RBus_UInt32  cm0_dsat:12;
    };
}dm_adj_byitn_dsat_dhue_cm0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  cm1_dhue:11;
        RBus_UInt32  cm1_dsat:12;
    };
}dm_adj_byitn_dsat_dhue_cm1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  cm2_dhue:11;
        RBus_UInt32  cm2_dsat:12;
    };
}dm_adj_byitn_dsat_dhue_cm2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  cm3_dhue:11;
        RBus_UInt32  cm3_dsat:12;
    };
}dm_adj_byitn_dsat_dhue_cm3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  cm4_dhue:11;
        RBus_UInt32  cm4_dsat:12;
    };
}dm_adj_byitn_dsat_dhue_cm4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  cm5_dhue:11;
        RBus_UInt32  cm5_dsat:12;
    };
}dm_adj_byitn_dsat_dhue_cm5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  cm6_dhue:11;
        RBus_UInt32  cm6_dsat:12;
    };
}dm_adj_byitn_dsat_dhue_cm6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  sha_m_byi_enable:1;
        RBus_UInt32  ssa_m_byi_enable:1;
        RBus_UInt32  delta_i_new_mode_enable:1;
        RBus_UInt32  res2:10;
        RBus_UInt32  dsat_alpha_shift:2;
        RBus_UInt32  dhue_alpha_shift:1;
        RBus_UInt32  seg_debug_enable:1;
        RBus_UInt32  seg_debug_type_sel:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  seg_debug_cm_sel:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  seg_debug_seg_sel:3;
        RBus_UInt32  res5:2;
        RBus_UInt32  sha_m_enable:1;
        RBus_UInt32  ssa_m_enable:1;
    };
}dm_seg_shy_adj_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  shy_address_sub_cm_sel:3;
        RBus_UInt32  shy_address_type_sel:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  shy_address_cm_sel:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  shy_address_seg_sel:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  write_random_access_en:1;
        RBus_UInt32  write_en:1;
        RBus_UInt32  read_en:1;
    };
}dm_seg_shy_sram_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dvs_5:4;
        RBus_UInt32  dvs_4:4;
        RBus_UInt32  dvs_3:4;
        RBus_UInt32  dvs_2:4;
        RBus_UInt32  dvs_1:4;
        RBus_UInt32  dvs_0:4;
        RBus_UInt32  res1:2;
        RBus_UInt32  dvse_5:1;
        RBus_UInt32  dvse_4:1;
        RBus_UInt32  dvse_3:1;
        RBus_UInt32  dvse_2:1;
        RBus_UInt32  dvse_1:1;
        RBus_UInt32  dvse_0:1;
    };
}dm_seg_shy_sram_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  drf_fail_5:1;
        RBus_UInt32  drf_fail_4:1;
        RBus_UInt32  drf_fail_3:1;
        RBus_UInt32  drf_fail_2:1;
        RBus_UInt32  drf_fail_1:1;
        RBus_UInt32  drf_fail_0:1;
        RBus_UInt32  bist_fail_5:1;
        RBus_UInt32  bist_fail_4:1;
        RBus_UInt32  bist_fail_3:1;
        RBus_UInt32  bist_fail_2:1;
        RBus_UInt32  bist_fail_1:1;
        RBus_UInt32  bist_fail_0:1;
    };
}dm_seg_shy_sram_bist_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  v2:12;
        RBus_UInt32  res2:6;
        RBus_UInt32  d2:10;
    };
}dm_seg_shy_write_seg_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  v2:12;
        RBus_UInt32  res2:6;
        RBus_UInt32  d2:10;
    };
}dm_seg_shy_write_seg_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  v2:12;
        RBus_UInt32  res2:6;
        RBus_UInt32  d2:10;
    };
}dm_seg_shy_write_seg_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  v2:12;
        RBus_UInt32  res2:6;
        RBus_UInt32  d2:10;
    };
}dm_seg_shy_write_seg_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  v2:12;
        RBus_UInt32  res2:6;
        RBus_UInt32  d2:10;
    };
}dm_seg_shy_write_seg_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  v2:12;
        RBus_UInt32  res2:6;
        RBus_UInt32  d2:10;
    };
}dm_seg_shy_write_seg_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  v2:12;
        RBus_UInt32  res2:6;
        RBus_UInt32  d2:10;
    };
}dm_seg_shy_write_seg_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  v2:12;
        RBus_UInt32  res2:6;
        RBus_UInt32  d2:10;
    };
}dm_seg_shy_write_seg_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  v2:12;
        RBus_UInt32  res2:6;
        RBus_UInt32  d2:10;
    };
}dm_seg_shy_write_seg_random_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  value:12;
        RBus_UInt32  res2:6;
        RBus_UInt32  delta:10;
    };
}dm_seg_shy_read_seg_random_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  icm_crc_conti:1;
        RBus_UInt32  icm_crc_start:1;
    };
}icm_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  icm_crc_result:32;
    };
}icm_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  del_left_kernel:11;
        RBus_UInt32  del_right_kernel:11;
    };
}dm_icm_cm0_del_hue_kernel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  del_sat_kernel:12;
        RBus_UInt32  del_sat_range:12;
    };
}dm_icm_cm0_del_sat_left_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  del_sat_kernel:12;
        RBus_UInt32  del_sat_range:12;
    };
}dm_icm_cm0_del_sat_right_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  del_left_kernel:11;
        RBus_UInt32  del_right_kernel:11;
    };
}dm_icm_cm1_del_hue_kernel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  del_sat_kernel:12;
        RBus_UInt32  del_sat_range:12;
    };
}dm_icm_cm1_del_sat_left_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  del_sat_kernel:12;
        RBus_UInt32  del_sat_range:12;
    };
}dm_icm_cm1_del_sat_right_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  del_left_kernel:11;
        RBus_UInt32  del_right_kernel:11;
    };
}dm_icm_cm2_del_hue_kernel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  del_sat_kernel:12;
        RBus_UInt32  del_sat_range:12;
    };
}dm_icm_cm2_del_sat_left_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  del_sat_kernel:12;
        RBus_UInt32  del_sat_range:12;
    };
}dm_icm_cm2_del_sat_right_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  del_left_kernel:11;
        RBus_UInt32  del_right_kernel:11;
    };
}dm_icm_cm3_del_hue_kernel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  del_sat_kernel:12;
        RBus_UInt32  del_sat_range:12;
    };
}dm_icm_cm3_del_sat_left_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  del_sat_kernel:12;
        RBus_UInt32  del_sat_range:12;
    };
}dm_icm_cm3_del_sat_right_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  del_left_kernel:11;
        RBus_UInt32  del_right_kernel:11;
    };
}dm_icm_cm4_del_hue_kernel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  del_sat_kernel:12;
        RBus_UInt32  del_sat_range:12;
    };
}dm_icm_cm4_del_sat_left_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  del_sat_kernel:12;
        RBus_UInt32  del_sat_range:12;
    };
}dm_icm_cm4_del_sat_right_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  del_left_kernel:11;
        RBus_UInt32  del_right_kernel:11;
    };
}dm_icm_cm5_del_hue_kernel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  del_sat_kernel:12;
        RBus_UInt32  del_sat_range:12;
    };
}dm_icm_cm5_del_sat_left_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  del_sat_kernel:12;
        RBus_UInt32  del_sat_range:12;
    };
}dm_icm_cm5_del_sat_right_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  del_left_kernel:11;
        RBus_UInt32  del_right_kernel:11;
    };
}dm_icm_cm6_del_hue_kernel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  del_sat_kernel:12;
        RBus_UInt32  del_sat_range:12;
    };
}dm_icm_cm6_del_sat_left_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  del_sat_kernel:12;
        RBus_UInt32  del_sat_range:12;
    };
}dm_icm_cm6_del_sat_right_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  merge_01_en:1;
        RBus_UInt32  merge_12_en:1;
        RBus_UInt32  merge_23_en:1;
        RBus_UInt32  merge_34_en:1;
        RBus_UInt32  merge_45_en:1;
        RBus_UInt32  merge_56_en:1;
        RBus_UInt32  merge_60_en:1;
        RBus_UInt32  del_hue_01:11;
    };
}dm_icm_merge_h_cm01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  del_sat_01:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  del_itn_01:12;
    };
}dm_icm_merge_si_cm01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  del_hue_12:11;
    };
}dm_icm_merge_h_cm12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  del_sat_12:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  del_itn_12:12;
    };
}dm_icm_merge_si_cm12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  del_hue_23:11;
    };
}dm_icm_merge_h_cm23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  del_sat_23:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  del_itn_23:12;
    };
}dm_icm_merge_si_cm23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  del_hue_34:11;
    };
}dm_icm_merge_h_cm34_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  del_sat_34:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  del_itn_34:12;
    };
}dm_icm_merge_si_cm34_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  del_hue_45:11;
    };
}dm_icm_merge_h_cm45_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  del_sat_45:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  del_itn_45:12;
    };
}dm_icm_merge_si_cm45_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  del_hue_56:11;
    };
}dm_icm_merge_h_cm56_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  del_sat_56:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  del_itn_56:12;
    };
}dm_icm_merge_si_cm56_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  del_hue_60:11;
    };
}dm_icm_merge_h_cm60_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  del_sat_60:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  del_itn_60:12;
    };
}dm_icm_merge_si_cm60_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  si_clip_en:1;
        RBus_UInt32  si_clip_left_mode:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  si_clip_right_mode:3;
        RBus_UInt32  si_clip_slope_mode:2;
        RBus_UInt32  res2:9;
        RBus_UInt32  sat_threshold:13;
    };
}dm_icm_si_clip_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  itn_top_threshold:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  itn_bottom_threshold:14;
    };
}dm_icm_si_clip_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  auto_sat_cnt_00:24;
    };
}d_icm_auto_sat_new_mode_cnt_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  auto_sat_cnt_01:24;
    };
}d_icm_auto_sat_new_mode_cnt_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  auto_sat_cnt_02:24;
    };
}d_icm_auto_sat_new_mode_cnt_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  auto_sat_cnt_03:24;
    };
}d_icm_auto_sat_new_mode_cnt_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  auto_sat_cnt_04:24;
    };
}d_icm_auto_sat_new_mode_cnt_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  auto_sat_cnt_05:24;
    };
}d_icm_auto_sat_new_mode_cnt_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  auto_sat_cnt_06:24;
    };
}d_icm_auto_sat_new_mode_cnt_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  auto_sat_cnt_07:24;
    };
}d_icm_auto_sat_new_mode_cnt_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  auto_sat_cnt_08:24;
    };
}d_icm_auto_sat_new_mode_cnt_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  auto_sat_cnt_09:24;
    };
}d_icm_auto_sat_new_mode_cnt_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  auto_sat_cnt_10:24;
    };
}d_icm_auto_sat_new_mode_cnt_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  auto_sat_cnt_11:24;
    };
}d_icm_auto_sat_new_mode_cnt_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  auto_sat_cnt_12:24;
    };
}d_icm_auto_sat_new_mode_cnt_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  auto_sat_cnt_13:24;
    };
}d_icm_auto_sat_new_mode_cnt_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  auto_sat_cnt_14:24;
    };
}d_icm_auto_sat_new_mode_cnt_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  auto_sat_cnt_15:24;
    };
}d_icm_auto_sat_new_mode_cnt_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  auto_sat_cnt_16:24;
    };
}d_icm_auto_sat_new_mode_cnt_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  auto_sat_cnt_17:24;
    };
}d_icm_auto_sat_new_mode_cnt_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  auto_sat_cnt_18:24;
    };
}d_icm_auto_sat_new_mode_cnt_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  auto_sat_cnt_19:24;
    };
}d_icm_auto_sat_new_mode_cnt_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  auto_sat_cnt_20:24;
    };
}d_icm_auto_sat_new_mode_cnt_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  auto_sat_cnt_21:24;
    };
}d_icm_auto_sat_new_mode_cnt_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  auto_sat_cnt_22:24;
    };
}d_icm_auto_sat_new_mode_cnt_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  auto_sat_cnt_23:24;
    };
}d_icm_auto_sat_new_mode_cnt_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  auto_sat_cnt_24:24;
    };
}d_icm_auto_sat_new_mode_cnt_24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  auto_sat_cnt_25:24;
    };
}d_icm_auto_sat_new_mode_cnt_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  auto_sat_cnt_26:24;
    };
}d_icm_auto_sat_new_mode_cnt_26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  auto_sat_cnt_27:24;
    };
}d_icm_auto_sat_new_mode_cnt_27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  auto_sat_cnt_28:24;
    };
}d_icm_auto_sat_new_mode_cnt_28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  auto_sat_cnt_29:24;
    };
}d_icm_auto_sat_new_mode_cnt_29_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  auto_sat_cnt_30:24;
    };
}d_icm_auto_sat_new_mode_cnt_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  auto_sat_cnt_31:24;
    };
}d_icm_auto_sat_new_mode_cnt_31_RBUS;





#else //apply LITTLE_ENDIAN


//======COLOR_ICM register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cm6_enable:1;
        RBus_UInt32  cm5_enable:1;
        RBus_UInt32  cm4_enable:1;
        RBus_UInt32  cm3_enable:1;
        RBus_UInt32  cm2_enable:1;
        RBus_UInt32  cm1_enable:1;
        RBus_UInt32  cm0_enable:1;
        RBus_UInt32  icm_dummy2:9;
        RBus_UInt32  cm_debug:3;
        RBus_UInt32  res3:2;
        RBus_UInt32  delta_i_smooth_enable:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  merge_en:1;
        RBus_UInt32  icm_dummy1:5;
        RBus_UInt32  res1:1;
        RBus_UInt32  bypass_yuv2rgb_enable:1;
        RBus_UInt32  y_ctrl:1;
    };
}dm_icm_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  center:11;
        RBus_UInt32  res2:2;
        RBus_UInt32  r_buffer:3;
        RBus_UInt32  r_range:3;
        RBus_UInt32  r_kernel:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  l_buffer:3;
        RBus_UInt32  l_range:3;
        RBus_UInt32  l_kernel:3;
    };
}dm_icm_cm0_hue_range_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_center:11;
        RBus_UInt32  res1:21;
    };
}dm_icm_cm0_del_hue_center_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_right:11;
        RBus_UInt32  del_left:11;
        RBus_UInt32  res1:10;
    };
}dm_icm_cm0_del_hue_left_right_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_itn:12;
        RBus_UInt32  del_sat:12;
        RBus_UInt32  res1:8;
    };
}dm_icm_cm0_del_sat_itn_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  center:11;
        RBus_UInt32  res2:2;
        RBus_UInt32  r_buffer:3;
        RBus_UInt32  r_range:3;
        RBus_UInt32  r_kernel:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  l_buffer:3;
        RBus_UInt32  l_range:3;
        RBus_UInt32  l_kernel:3;
    };
}dm_icm_cm1_hue_range_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_center:11;
        RBus_UInt32  res1:21;
    };
}dm_icm_cm1_del_hue_center_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_right:11;
        RBus_UInt32  del_left:11;
        RBus_UInt32  res1:10;
    };
}dm_icm_cm1_del_hue_left_right_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_itn:12;
        RBus_UInt32  del_sat:12;
        RBus_UInt32  res1:8;
    };
}dm_icm_cm1_del_sat_itn_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  center:11;
        RBus_UInt32  res2:2;
        RBus_UInt32  r_buffer:3;
        RBus_UInt32  r_range:3;
        RBus_UInt32  r_kernel:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  l_buffer:3;
        RBus_UInt32  l_range:3;
        RBus_UInt32  l_kernel:3;
    };
}dm_icm_cm2_hue_range_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_center:11;
        RBus_UInt32  res1:21;
    };
}dm_icm_cm2_del_hue_center_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_right:11;
        RBus_UInt32  del_left:11;
        RBus_UInt32  res1:10;
    };
}dm_icm_cm2_del_hue_left_right_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_itn:12;
        RBus_UInt32  del_sat:12;
        RBus_UInt32  res1:8;
    };
}dm_icm_cm2_del_sat_itn_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  center:11;
        RBus_UInt32  res2:2;
        RBus_UInt32  r_buffer:3;
        RBus_UInt32  r_range:3;
        RBus_UInt32  r_kernel:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  l_buffer:3;
        RBus_UInt32  l_range:3;
        RBus_UInt32  l_kernel:3;
    };
}dm_icm_cm3_hue_range_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_center:11;
        RBus_UInt32  res1:21;
    };
}dm_icm_cm3_del_hue_center_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_right:11;
        RBus_UInt32  del_left:11;
        RBus_UInt32  res1:10;
    };
}dm_icm_cm3_del_hue_left_right_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_itn:12;
        RBus_UInt32  del_sat:12;
        RBus_UInt32  res1:8;
    };
}dm_icm_cm3_del_sat_itn_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  center:11;
        RBus_UInt32  res2:2;
        RBus_UInt32  r_buffer:3;
        RBus_UInt32  r_range:3;
        RBus_UInt32  r_kernel:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  l_buffer:3;
        RBus_UInt32  l_range:3;
        RBus_UInt32  l_kernel:3;
    };
}dm_icm_cm4_hue_range_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_center:11;
        RBus_UInt32  res1:21;
    };
}dm_icm_cm4_del_hue_center_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_right:11;
        RBus_UInt32  del_left:11;
        RBus_UInt32  res1:10;
    };
}dm_icm_cm4_del_hue_left_right_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_itn:12;
        RBus_UInt32  del_sat:12;
        RBus_UInt32  res1:8;
    };
}dm_icm_cm4_del_sat_itn_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  center:11;
        RBus_UInt32  res2:2;
        RBus_UInt32  r_buffer:3;
        RBus_UInt32  r_range:3;
        RBus_UInt32  r_kernel:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  l_buffer:3;
        RBus_UInt32  l_range:3;
        RBus_UInt32  l_kernel:3;
    };
}dm_icm_cm5_hue_range_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_center:11;
        RBus_UInt32  res1:21;
    };
}dm_icm_cm5_del_hue_center_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_right:11;
        RBus_UInt32  del_left:11;
        RBus_UInt32  res1:10;
    };
}dm_icm_cm5_del_hue_left_right_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_itn:12;
        RBus_UInt32  del_sat:12;
        RBus_UInt32  res1:8;
    };
}dm_icm_cm5_del_sat_itn_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  center:11;
        RBus_UInt32  res2:2;
        RBus_UInt32  r_buffer:3;
        RBus_UInt32  r_range:3;
        RBus_UInt32  r_kernel:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  l_buffer:3;
        RBus_UInt32  l_range:3;
        RBus_UInt32  l_kernel:3;
    };
}dm_icm_cm6_hue_range_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_center:11;
        RBus_UInt32  res1:21;
    };
}dm_icm_cm6_del_hue_center_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_right:11;
        RBus_UInt32  del_left:11;
        RBus_UInt32  res1:10;
    };
}dm_icm_cm6_del_hue_left_right_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_itn:12;
        RBus_UInt32  del_sat:12;
        RBus_UInt32  res1:8;
    };
}dm_icm_cm6_del_sat_itn_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v_coring:8;
        RBus_UInt32  u_coring:8;
        RBus_UInt32  res1:16;
    };
}dm_uv_coring_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_all:11;
        RBus_UInt32  dummy1802a178_31_11:21;
    };
}dm_hue_all_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_all:12;
        RBus_UInt32  res1:20;
    };
}dm_sat_all_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  itn_all:12;
        RBus_UInt32  res1:20;
    };
}dm_itn_all_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  itn_enable:1;
        RBus_UInt32  sat_enable:1;
        RBus_UInt32  neg_int_flag_en:1;
        RBus_UInt32  res1:25;
        RBus_UInt32  int_multi_clip_sel:1;
        RBus_UInt32  int_clip_sel:1;
        RBus_UInt32  sat_multi_clip_sel:1;
        RBus_UInt32  sat_clip_sel:1;
    };
}dm_soft_clamp_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_max:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  sat_thd:12;
        RBus_UInt32  sat_slope:4;
    };
}dm_soft_clamp_sat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  itn_max:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  itn_thd:12;
        RBus_UInt32  itn_slope:4;
    };
}dm_soft_clamp_itn_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res6:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  sat_enable:1;
        RBus_UInt32  hist_sat_ok:1;
        RBus_UInt32  sat_hist_mode_sel:1;
        RBus_UInt32  auto_sat_new_mode:2;
        RBus_UInt32  res4:1;
        RBus_UInt32  auto_sat_s_thre:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  auto_sat_i_l_thre:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  auto_sat_i_u_thre:7;
        RBus_UInt32  res1:1;
    };
}d_auto_sat_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_offset:8;
        RBus_UInt32  gain_hi:4;
        RBus_UInt32  gain_lo:4;
        RBus_UInt32  u_bound:4;
        RBus_UInt32  l_bound:4;
        RBus_UInt32  sat_hist_ctrl:8;
    };
}d_auto_sat_itn_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pre_cnt:24;
        RBus_UInt32  sat_hist_ctrl_status:8;
    };
}d_auto_sat_pre_count_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  aft_cnt:24;
        RBus_UInt32  res1:8;
    };
}d_auto_sat_after_count_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inside_enable:1;
        RBus_UInt32  hue_enable:1;
        RBus_UInt32  hist_hue_ok:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  hue_hist_mode_sel:1;
        RBus_UInt32  res1:27;
    };
}icm_auto_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_hist_itn_lb:8;
        RBus_UInt32  hue_hist_itn_hb:8;
        RBus_UInt32  hue_hist_sat_lb:8;
        RBus_UInt32  hue_hist_offset_add:8;
    };
}hue_hist_settings_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut0:24;
        RBus_UInt32  res1:8;
    };
}hue_count_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut1:24;
        RBus_UInt32  res1:8;
    };
}hue_count_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut2:24;
        RBus_UInt32  res1:8;
    };
}hue_count_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut3:24;
        RBus_UInt32  res1:8;
    };
}hue_count_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut4:24;
        RBus_UInt32  res1:8;
    };
}hue_count_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut5:24;
        RBus_UInt32  res1:8;
    };
}hue_count_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut6:24;
        RBus_UInt32  res1:8;
    };
}hue_count_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut7:24;
        RBus_UInt32  res1:8;
    };
}hue_count_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut8:24;
        RBus_UInt32  res1:8;
    };
}hue_count_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut9:24;
        RBus_UInt32  res1:8;
    };
}hue_count_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut10:24;
        RBus_UInt32  res1:8;
    };
}hue_count_0a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut11:24;
        RBus_UInt32  res1:8;
    };
}hue_count_0b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut12:24;
        RBus_UInt32  res1:8;
    };
}hue_count_0c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut13:24;
        RBus_UInt32  res1:8;
    };
}hue_count_0d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut14:24;
        RBus_UInt32  res1:8;
    };
}hue_count_0e_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut15:24;
        RBus_UInt32  res1:8;
    };
}hue_count_0f_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut16:24;
        RBus_UInt32  res1:8;
    };
}hue_count_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut17:24;
        RBus_UInt32  res1:8;
    };
}hue_count_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut18:24;
        RBus_UInt32  res1:8;
    };
}hue_count_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut19:24;
        RBus_UInt32  res1:8;
    };
}hue_count_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut20:24;
        RBus_UInt32  res1:8;
    };
}hue_count_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut21:24;
        RBus_UInt32  res1:8;
    };
}hue_count_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut22:24;
        RBus_UInt32  res1:8;
    };
}hue_count_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut23:24;
        RBus_UInt32  res1:8;
    };
}hue_count_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut0:32;
    };
}hue_sum_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut1:32;
    };
}hue_sum_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut2:32;
    };
}hue_sum_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut3:32;
    };
}hue_sum_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut4:32;
    };
}hue_sum_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut5:32;
    };
}hue_sum_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dsatbyitn_cm6_enable:1;
        RBus_UInt32  dsatbyitn_cm5_enable:1;
        RBus_UInt32  dsatbyitn_cm4_enable:1;
        RBus_UInt32  dsatbyitn_cm3_enable:1;
        RBus_UInt32  dsatbyitn_cm2_enable:1;
        RBus_UInt32  dsatbyitn_cm1_enable:1;
        RBus_UInt32  dsatbyitn_cm0_enable:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  dhuebyitn_cm6_enable:1;
        RBus_UInt32  dhuebyitn_cm5_enable:1;
        RBus_UInt32  dhuebyitn_cm4_enable:1;
        RBus_UInt32  dhuebyitn_cm3_enable:1;
        RBus_UInt32  dhuebyitn_cm2_enable:1;
        RBus_UInt32  dhuebyitn_cm1_enable:1;
        RBus_UInt32  dhuebyitn_cm0_enable:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  itnlevel_debug_enable:1;
        RBus_UInt32  itnlevel_debug_cm_sel:3;
        RBus_UInt32  itnlevel_debug_satlevel_sel:2;
        RBus_UInt32  res1:10;
    };
}dm_adj_byitn_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cm0_itn_lb:8;
        RBus_UInt32  cm1_itn_lb:8;
        RBus_UInt32  cm2_itn_lb:8;
        RBus_UInt32  cm3_itn_lb:8;
    };
}dm_adj_byitn_lb_cm0_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cm4_itn_lb:8;
        RBus_UInt32  cm5_itn_lb:8;
        RBus_UInt32  cm6_itn_lb:8;
        RBus_UInt32  res1:8;
    };
}dm_adj_byitn_lb_cm4_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cm0_itn_buffer:3;
        RBus_UInt32  res7:1;
        RBus_UInt32  cm1_itn_buffer:3;
        RBus_UInt32  res6:1;
        RBus_UInt32  cm2_itn_buffer:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  cm3_itn_buffer:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  cm4_itn_buffer:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  cm5_itn_buffer:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  cm6_itn_buffer:3;
        RBus_UInt32  res1:5;
    };
}dm_adj_byitn_buf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cm0_dsat:12;
        RBus_UInt32  cm0_dhue:11;
        RBus_UInt32  res1:9;
    };
}dm_adj_byitn_dsat_dhue_cm0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cm1_dsat:12;
        RBus_UInt32  cm1_dhue:11;
        RBus_UInt32  res1:9;
    };
}dm_adj_byitn_dsat_dhue_cm1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cm2_dsat:12;
        RBus_UInt32  cm2_dhue:11;
        RBus_UInt32  res1:9;
    };
}dm_adj_byitn_dsat_dhue_cm2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cm3_dsat:12;
        RBus_UInt32  cm3_dhue:11;
        RBus_UInt32  res1:9;
    };
}dm_adj_byitn_dsat_dhue_cm3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cm4_dsat:12;
        RBus_UInt32  cm4_dhue:11;
        RBus_UInt32  res1:9;
    };
}dm_adj_byitn_dsat_dhue_cm4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cm5_dsat:12;
        RBus_UInt32  cm5_dhue:11;
        RBus_UInt32  res1:9;
    };
}dm_adj_byitn_dsat_dhue_cm5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cm6_dsat:12;
        RBus_UInt32  cm6_dhue:11;
        RBus_UInt32  res1:9;
    };
}dm_adj_byitn_dsat_dhue_cm6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ssa_m_enable:1;
        RBus_UInt32  sha_m_enable:1;
        RBus_UInt32  res5:2;
        RBus_UInt32  seg_debug_seg_sel:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  seg_debug_cm_sel:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  seg_debug_type_sel:1;
        RBus_UInt32  seg_debug_enable:1;
        RBus_UInt32  dhue_alpha_shift:1;
        RBus_UInt32  dsat_alpha_shift:2;
        RBus_UInt32  res2:10;
        RBus_UInt32  delta_i_new_mode_enable:1;
        RBus_UInt32  ssa_m_byi_enable:1;
        RBus_UInt32  sha_m_byi_enable:1;
        RBus_UInt32  res1:2;
    };
}dm_seg_shy_adj_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_en:1;
        RBus_UInt32  write_en:1;
        RBus_UInt32  write_random_access_en:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  shy_address_seg_sel:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  shy_address_cm_sel:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  shy_address_type_sel:3;
        RBus_UInt32  shy_address_sub_cm_sel:3;
        RBus_UInt32  res1:14;
    };
}dm_seg_shy_sram_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dvse_0:1;
        RBus_UInt32  dvse_1:1;
        RBus_UInt32  dvse_2:1;
        RBus_UInt32  dvse_3:1;
        RBus_UInt32  dvse_4:1;
        RBus_UInt32  dvse_5:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  dvs_0:4;
        RBus_UInt32  dvs_1:4;
        RBus_UInt32  dvs_2:4;
        RBus_UInt32  dvs_3:4;
        RBus_UInt32  dvs_4:4;
        RBus_UInt32  dvs_5:4;
    };
}dm_seg_shy_sram_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_fail_0:1;
        RBus_UInt32  bist_fail_1:1;
        RBus_UInt32  bist_fail_2:1;
        RBus_UInt32  bist_fail_3:1;
        RBus_UInt32  bist_fail_4:1;
        RBus_UInt32  bist_fail_5:1;
        RBus_UInt32  drf_fail_0:1;
        RBus_UInt32  drf_fail_1:1;
        RBus_UInt32  drf_fail_2:1;
        RBus_UInt32  drf_fail_3:1;
        RBus_UInt32  drf_fail_4:1;
        RBus_UInt32  drf_fail_5:1;
        RBus_UInt32  res1:20;
    };
}dm_seg_shy_sram_bist_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d2:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  v2:12;
        RBus_UInt32  res1:4;
    };
}dm_seg_shy_write_seg_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d2:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  v2:12;
        RBus_UInt32  res1:4;
    };
}dm_seg_shy_write_seg_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d2:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  v2:12;
        RBus_UInt32  res1:4;
    };
}dm_seg_shy_write_seg_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d2:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  v2:12;
        RBus_UInt32  res1:4;
    };
}dm_seg_shy_write_seg_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d2:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  v2:12;
        RBus_UInt32  res1:4;
    };
}dm_seg_shy_write_seg_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d2:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  v2:12;
        RBus_UInt32  res1:4;
    };
}dm_seg_shy_write_seg_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d2:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  v2:12;
        RBus_UInt32  res1:4;
    };
}dm_seg_shy_write_seg_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d2:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  v2:12;
        RBus_UInt32  res1:4;
    };
}dm_seg_shy_write_seg_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d2:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  v2:12;
        RBus_UInt32  res1:4;
    };
}dm_seg_shy_write_seg_random_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delta:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  value:12;
        RBus_UInt32  res1:4;
    };
}dm_seg_shy_read_seg_random_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  icm_crc_start:1;
        RBus_UInt32  icm_crc_conti:1;
        RBus_UInt32  res1:30;
    };
}icm_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  icm_crc_result:32;
    };
}icm_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_right_kernel:11;
        RBus_UInt32  del_left_kernel:11;
        RBus_UInt32  res1:10;
    };
}dm_icm_cm0_del_hue_kernel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_sat_range:12;
        RBus_UInt32  del_sat_kernel:12;
        RBus_UInt32  res1:8;
    };
}dm_icm_cm0_del_sat_left_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_sat_range:12;
        RBus_UInt32  del_sat_kernel:12;
        RBus_UInt32  res1:8;
    };
}dm_icm_cm0_del_sat_right_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_right_kernel:11;
        RBus_UInt32  del_left_kernel:11;
        RBus_UInt32  res1:10;
    };
}dm_icm_cm1_del_hue_kernel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_sat_range:12;
        RBus_UInt32  del_sat_kernel:12;
        RBus_UInt32  res1:8;
    };
}dm_icm_cm1_del_sat_left_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_sat_range:12;
        RBus_UInt32  del_sat_kernel:12;
        RBus_UInt32  res1:8;
    };
}dm_icm_cm1_del_sat_right_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_right_kernel:11;
        RBus_UInt32  del_left_kernel:11;
        RBus_UInt32  res1:10;
    };
}dm_icm_cm2_del_hue_kernel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_sat_range:12;
        RBus_UInt32  del_sat_kernel:12;
        RBus_UInt32  res1:8;
    };
}dm_icm_cm2_del_sat_left_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_sat_range:12;
        RBus_UInt32  del_sat_kernel:12;
        RBus_UInt32  res1:8;
    };
}dm_icm_cm2_del_sat_right_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_right_kernel:11;
        RBus_UInt32  del_left_kernel:11;
        RBus_UInt32  res1:10;
    };
}dm_icm_cm3_del_hue_kernel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_sat_range:12;
        RBus_UInt32  del_sat_kernel:12;
        RBus_UInt32  res1:8;
    };
}dm_icm_cm3_del_sat_left_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_sat_range:12;
        RBus_UInt32  del_sat_kernel:12;
        RBus_UInt32  res1:8;
    };
}dm_icm_cm3_del_sat_right_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_right_kernel:11;
        RBus_UInt32  del_left_kernel:11;
        RBus_UInt32  res1:10;
    };
}dm_icm_cm4_del_hue_kernel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_sat_range:12;
        RBus_UInt32  del_sat_kernel:12;
        RBus_UInt32  res1:8;
    };
}dm_icm_cm4_del_sat_left_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_sat_range:12;
        RBus_UInt32  del_sat_kernel:12;
        RBus_UInt32  res1:8;
    };
}dm_icm_cm4_del_sat_right_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_right_kernel:11;
        RBus_UInt32  del_left_kernel:11;
        RBus_UInt32  res1:10;
    };
}dm_icm_cm5_del_hue_kernel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_sat_range:12;
        RBus_UInt32  del_sat_kernel:12;
        RBus_UInt32  res1:8;
    };
}dm_icm_cm5_del_sat_left_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_sat_range:12;
        RBus_UInt32  del_sat_kernel:12;
        RBus_UInt32  res1:8;
    };
}dm_icm_cm5_del_sat_right_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_right_kernel:11;
        RBus_UInt32  del_left_kernel:11;
        RBus_UInt32  res1:10;
    };
}dm_icm_cm6_del_hue_kernel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_sat_range:12;
        RBus_UInt32  del_sat_kernel:12;
        RBus_UInt32  res1:8;
    };
}dm_icm_cm6_del_sat_left_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_sat_range:12;
        RBus_UInt32  del_sat_kernel:12;
        RBus_UInt32  res1:8;
    };
}dm_icm_cm6_del_sat_right_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_hue_01:11;
        RBus_UInt32  merge_60_en:1;
        RBus_UInt32  merge_56_en:1;
        RBus_UInt32  merge_45_en:1;
        RBus_UInt32  merge_34_en:1;
        RBus_UInt32  merge_23_en:1;
        RBus_UInt32  merge_12_en:1;
        RBus_UInt32  merge_01_en:1;
        RBus_UInt32  res1:14;
    };
}dm_icm_merge_h_cm01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_itn_01:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  del_sat_01:12;
        RBus_UInt32  res1:4;
    };
}dm_icm_merge_si_cm01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_hue_12:11;
        RBus_UInt32  res1:21;
    };
}dm_icm_merge_h_cm12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_itn_12:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  del_sat_12:12;
        RBus_UInt32  res1:4;
    };
}dm_icm_merge_si_cm12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_hue_23:11;
        RBus_UInt32  res1:21;
    };
}dm_icm_merge_h_cm23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_itn_23:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  del_sat_23:12;
        RBus_UInt32  res1:4;
    };
}dm_icm_merge_si_cm23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_hue_34:11;
        RBus_UInt32  res1:21;
    };
}dm_icm_merge_h_cm34_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_itn_34:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  del_sat_34:12;
        RBus_UInt32  res1:4;
    };
}dm_icm_merge_si_cm34_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_hue_45:11;
        RBus_UInt32  res1:21;
    };
}dm_icm_merge_h_cm45_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_itn_45:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  del_sat_45:12;
        RBus_UInt32  res1:4;
    };
}dm_icm_merge_si_cm45_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_hue_56:11;
        RBus_UInt32  res1:21;
    };
}dm_icm_merge_h_cm56_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_itn_56:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  del_sat_56:12;
        RBus_UInt32  res1:4;
    };
}dm_icm_merge_si_cm56_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_hue_60:11;
        RBus_UInt32  res1:21;
    };
}dm_icm_merge_h_cm60_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  del_itn_60:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  del_sat_60:12;
        RBus_UInt32  res1:4;
    };
}dm_icm_merge_si_cm60_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_threshold:13;
        RBus_UInt32  res2:9;
        RBus_UInt32  si_clip_slope_mode:2;
        RBus_UInt32  si_clip_right_mode:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  si_clip_left_mode:3;
        RBus_UInt32  si_clip_en:1;
    };
}dm_icm_si_clip_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  itn_bottom_threshold:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  itn_top_threshold:14;
        RBus_UInt32  res1:2;
    };
}dm_icm_si_clip_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_sat_cnt_00:24;
        RBus_UInt32  res1:8;
    };
}d_icm_auto_sat_new_mode_cnt_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_sat_cnt_01:24;
        RBus_UInt32  res1:8;
    };
}d_icm_auto_sat_new_mode_cnt_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_sat_cnt_02:24;
        RBus_UInt32  res1:8;
    };
}d_icm_auto_sat_new_mode_cnt_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_sat_cnt_03:24;
        RBus_UInt32  res1:8;
    };
}d_icm_auto_sat_new_mode_cnt_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_sat_cnt_04:24;
        RBus_UInt32  res1:8;
    };
}d_icm_auto_sat_new_mode_cnt_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_sat_cnt_05:24;
        RBus_UInt32  res1:8;
    };
}d_icm_auto_sat_new_mode_cnt_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_sat_cnt_06:24;
        RBus_UInt32  res1:8;
    };
}d_icm_auto_sat_new_mode_cnt_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_sat_cnt_07:24;
        RBus_UInt32  res1:8;
    };
}d_icm_auto_sat_new_mode_cnt_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_sat_cnt_08:24;
        RBus_UInt32  res1:8;
    };
}d_icm_auto_sat_new_mode_cnt_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_sat_cnt_09:24;
        RBus_UInt32  res1:8;
    };
}d_icm_auto_sat_new_mode_cnt_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_sat_cnt_10:24;
        RBus_UInt32  res1:8;
    };
}d_icm_auto_sat_new_mode_cnt_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_sat_cnt_11:24;
        RBus_UInt32  res1:8;
    };
}d_icm_auto_sat_new_mode_cnt_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_sat_cnt_12:24;
        RBus_UInt32  res1:8;
    };
}d_icm_auto_sat_new_mode_cnt_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_sat_cnt_13:24;
        RBus_UInt32  res1:8;
    };
}d_icm_auto_sat_new_mode_cnt_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_sat_cnt_14:24;
        RBus_UInt32  res1:8;
    };
}d_icm_auto_sat_new_mode_cnt_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_sat_cnt_15:24;
        RBus_UInt32  res1:8;
    };
}d_icm_auto_sat_new_mode_cnt_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_sat_cnt_16:24;
        RBus_UInt32  res1:8;
    };
}d_icm_auto_sat_new_mode_cnt_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_sat_cnt_17:24;
        RBus_UInt32  res1:8;
    };
}d_icm_auto_sat_new_mode_cnt_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_sat_cnt_18:24;
        RBus_UInt32  res1:8;
    };
}d_icm_auto_sat_new_mode_cnt_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_sat_cnt_19:24;
        RBus_UInt32  res1:8;
    };
}d_icm_auto_sat_new_mode_cnt_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_sat_cnt_20:24;
        RBus_UInt32  res1:8;
    };
}d_icm_auto_sat_new_mode_cnt_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_sat_cnt_21:24;
        RBus_UInt32  res1:8;
    };
}d_icm_auto_sat_new_mode_cnt_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_sat_cnt_22:24;
        RBus_UInt32  res1:8;
    };
}d_icm_auto_sat_new_mode_cnt_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_sat_cnt_23:24;
        RBus_UInt32  res1:8;
    };
}d_icm_auto_sat_new_mode_cnt_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_sat_cnt_24:24;
        RBus_UInt32  res1:8;
    };
}d_icm_auto_sat_new_mode_cnt_24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_sat_cnt_25:24;
        RBus_UInt32  res1:8;
    };
}d_icm_auto_sat_new_mode_cnt_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_sat_cnt_26:24;
        RBus_UInt32  res1:8;
    };
}d_icm_auto_sat_new_mode_cnt_26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_sat_cnt_27:24;
        RBus_UInt32  res1:8;
    };
}d_icm_auto_sat_new_mode_cnt_27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_sat_cnt_28:24;
        RBus_UInt32  res1:8;
    };
}d_icm_auto_sat_new_mode_cnt_28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_sat_cnt_29:24;
        RBus_UInt32  res1:8;
    };
}d_icm_auto_sat_new_mode_cnt_29_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_sat_cnt_30:24;
        RBus_UInt32  res1:8;
    };
}d_icm_auto_sat_new_mode_cnt_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_sat_cnt_31:24;
        RBus_UInt32  res1:8;
    };
}d_icm_auto_sat_new_mode_cnt_31_RBUS;


#endif







#endif //_RBUS_COLOR_ICM_REG_H_

