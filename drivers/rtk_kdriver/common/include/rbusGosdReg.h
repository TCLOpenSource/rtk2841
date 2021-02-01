/**
* @file rbusGosdReg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2009/7/10
* @version 1.1
* @ingroup model_rbus
*
*/

#ifndef _RBUS_GOSD_REG_H_
#define _RBUS_GOSD_REG_H_

#include "rbus/rbusTypes.h"




// GOSD Register Address
#define GOSD_GOSD_SDSA_ADDR                        (0x18048400)
#define GOSD_GOSD_SHSR_ADDR                        (0x18048404)
#define GOSD_GOSD_CR_ADDR                          (0x18048408)
#define GOSD_GOSD_SR_ADDR                          (0x1804840c)
#define GOSD_CURRENT_START_ADDR_ADDR               (0x18048410)
#define GOSD_GOSD_SE_BISTCR_ADDR                   (0x18048460)
#define GOSD_GOSD_SE_BISTSR_ADDR                   (0x18048464)
#define GOSD_GOSD_CONT_PLT1_ADDR                   (0x18048468)
#define GOSD_GOSD_CONT_PLT2_ADDR                   (0x1804846c)
#define GOSD_GOSD_INTERANL_ADDR                    (0x18048470)
#define GOSD_GOSD_INTER_SR_ADDR                    (0x18048474)
#define GOSD_GOSD_DBG_ADDR                         (0x18048478)
#define GOSD_GOSD_VERSION_ADDR                     (0x1804847c)
#define GOSD_GOSD_FLASH_CTRL_ADDR                  (0x180484e0)
#define GOSD_GOSD_COLOR_ZONE1_ADDR                 (0x180484e4)
#define GOSD_GOSD_COLOR_ZONE2_ADDR                 (0x180484e8)
#define GOSD_GOSD_COLOR_ZONE3_ADDR                 (0x180484ec)
#define GOSD_GOSD_COLOR_ZONE4_ADDR                 (0x180484f0)
#define GOSD_GOSD_COLOR_ZONE5_ADDR                 (0x180484f4)
#define GOSD_GOSD_COLOR_ZONE6_ADDR                 (0x180484f8)
#define GOSD_MSKW1_0_ADDR                          (0x18048420)
#define GOSD_MSKW1_1_ADDR                          (0x18048424)
#define GOSD_MSKW1_2_ADDR                          (0x18048428)
#define GOSD_MSKW1_3_ADDR                          (0x1804842c)
#define GOSD_MSKW1_4_ADDR                          (0x18048430)
#define GOSD_MSKW1_5_ADDR                          (0x18048434)
#define GOSD_MSKW1_6_ADDR                          (0x18048438)
#define GOSD_MSKW1_7_ADDR                          (0x1804843c)
#define GOSD_MSKW2_0_ADDR                          (0x18048440)
#define GOSD_MSKW2_1_ADDR                          (0x18048444)
#define GOSD_MSKW2_2_ADDR                          (0x18048448)
#define GOSD_MSKW2_3_ADDR                          (0x1804844c)
#define GOSD_MSKW2_4_ADDR                          (0x18048450)
#define GOSD_MSKW2_5_ADDR                          (0x18048454)
#define GOSD_MSKW2_6_ADDR                          (0x18048458)
#define GOSD_MSKW2_7_ADDR                          (0x1804845c)
#define GOSD_SCALEUP_CTRL_ADDR                     (0x18048600)
#define GOSD_SCALEUP_SCALE_HOR_FACTOR_ADDR         (0x18048604)
#define GOSD_SCALEUP_SCALE_VER_FACTOR_ADDR         (0x18048608)
#define GOSD_SCALEUP_INITIAL_VALUE_ADDR            (0x1804860c)
#define GOSD_SCALEUP_INPUT_SIZE_ADDR               (0x18048610)
#define GOSD_SCALEUP_MEM_CRC_CTRL_ADDR             (0x18048614)
#define GOSD_SCALEUP_MEM_CRC_RESULT_ADDR           (0x18048618)
#define GOSD_SCALEUP_FIR_COEF_VER_C0_C3_ADDR       (0x1804861c)
#define GOSD_SCALEUP_FIR_COEF_VER_C4_C7_ADDR       (0x18048620)
#define GOSD_SCALEUP_FIR_COEF_VER_C8_C11_ADDR      (0x18048624)
#define GOSD_SCALEUP_FIR_COEF_VER_C12_C15_ADDR     (0x18048628)
#define GOSD_SCALEUP_FIR_COEF_HOR_C0_C3_ADDR       (0x18048640)
#define GOSD_SCALEUP_FIR_COEF_HOR_C4_C7_ADDR       (0x18048644)
#define GOSD_SCALEUP_FIR_COEF_HOR_C8_C11_ADDR      (0x18048648)
#define GOSD_SCALEUP_FIR_COEF_HOR_C12_C15_ADDR     (0x1804864c)
#define GOSD_SCALEUP_FIR_COEF_HOR_C16_C19_ADDR     (0x18048650)
#define GOSD_SCALEUP_FIR_COEF_HOR_C20_C23_ADDR     (0x18048654)
#define GOSD_SCALEUP_FIR_COEF_HOR_C24_C27_ADDR     (0x18048658)
#define GOSD_SCALEUP_FIR_COEF_HOR_C28_C31_ADDR     (0x1804865c)
#define GOSD_GOSD_WINDOW_CTRL0_ADDR                (0x1804862c)
#define GOSD_GOSD_WINDOW_CTRL1_ADDR                (0x18048630)

#define GOSD_GOSD_SDSA_VADDR                       (0xb8048400)
#define GOSD_GOSD_SHSR_VADDR                       (0xb8048404)
#define GOSD_GOSD_CR_VADDR                         (0xb8048408)
#define GOSD_GOSD_SR_VADDR                         (0xb804840c)
#define GOSD_CURRENT_START_ADDR_VADDR              (0xb8048410)
#define GOSD_GOSD_SE_BISTCR_VADDR                  (0xb8048460)
#define GOSD_GOSD_SE_BISTSR_VADDR                  (0xb8048464)
#define GOSD_GOSD_CONT_PLT1_VADDR                  (0xb8048468)
#define GOSD_GOSD_CONT_PLT2_VADDR                  (0xb804846c)
#define GOSD_GOSD_INTERANL_VADDR                   (0xb8048470)
#define GOSD_GOSD_INTER_SR_VADDR                   (0xb8048474)
#define GOSD_GOSD_DBG_VADDR                        (0xb8048478)
#define GOSD_GOSD_VERSION_VADDR                    (0xb804847c)
#define GOSD_GOSD_FLASH_CTRL_VADDR                 (0xb80484e0)
#define GOSD_GOSD_COLOR_ZONE1_VADDR                (0xb80484e4)
#define GOSD_GOSD_COLOR_ZONE2_VADDR                (0xb80484e8)
#define GOSD_GOSD_COLOR_ZONE3_VADDR                (0xb80484ec)
#define GOSD_GOSD_COLOR_ZONE4_VADDR                (0xb80484f0)
#define GOSD_GOSD_COLOR_ZONE5_VADDR                (0xb80484f4)
#define GOSD_GOSD_COLOR_ZONE6_VADDR                (0xb80484f8)
#define GOSD_MSKW1_0_VADDR                         (0xb8048420)
#define GOSD_MSKW1_1_VADDR                         (0xb8048424)
#define GOSD_MSKW1_2_VADDR                         (0xb8048428)
#define GOSD_MSKW1_3_VADDR                         (0xb804842c)
#define GOSD_MSKW1_4_VADDR                         (0xb8048430)
#define GOSD_MSKW1_5_VADDR                         (0xb8048434)
#define GOSD_MSKW1_6_VADDR                         (0xb8048438)
#define GOSD_MSKW1_7_VADDR                         (0xb804843c)
#define GOSD_MSKW2_0_VADDR                         (0xb8048440)
#define GOSD_MSKW2_1_VADDR                         (0xb8048444)
#define GOSD_MSKW2_2_VADDR                         (0xb8048448)
#define GOSD_MSKW2_3_VADDR                         (0xb804844c)
#define GOSD_MSKW2_4_VADDR                         (0xb8048450)
#define GOSD_MSKW2_5_VADDR                         (0xb8048454)
#define GOSD_MSKW2_6_VADDR                         (0xb8048458)
#define GOSD_MSKW2_7_VADDR                         (0xb804845c)
#define GOSD_SCALEUP_CTRL_VADDR                    (0xb8048600)
#define GOSD_SCALEUP_SCALE_HOR_FACTOR_VADDR        (0xb8048604)
#define GOSD_SCALEUP_SCALE_VER_FACTOR_VADDR        (0xb8048608)
#define GOSD_SCALEUP_INITIAL_VALUE_VADDR           (0xb804860c)
#define GOSD_SCALEUP_INPUT_SIZE_VADDR              (0xb8048610)
#define GOSD_SCALEUP_MEM_CRC_CTRL_VADDR            (0xb8048614)
#define GOSD_SCALEUP_MEM_CRC_RESULT_VADDR          (0xb8048618)
#define GOSD_SCALEUP_FIR_COEF_VER_C0_C3_VADDR      (0xb804861c)
#define GOSD_SCALEUP_FIR_COEF_VER_C4_C7_VADDR      (0xb8048620)
#define GOSD_SCALEUP_FIR_COEF_VER_C8_C11_VADDR     (0xb8048624)
#define GOSD_SCALEUP_FIR_COEF_VER_C12_C15_VADDR    (0xb8048628)
#define GOSD_SCALEUP_FIR_COEF_HOR_C0_C3_VADDR      (0xb8048640)
#define GOSD_SCALEUP_FIR_COEF_HOR_C4_C7_VADDR      (0xb8048644)
#define GOSD_SCALEUP_FIR_COEF_HOR_C8_C11_VADDR     (0xb8048648)
#define GOSD_SCALEUP_FIR_COEF_HOR_C12_C15_VADDR    (0xb804864c)
#define GOSD_SCALEUP_FIR_COEF_HOR_C16_C19_VADDR    (0xb8048650)
#define GOSD_SCALEUP_FIR_COEF_HOR_C20_C23_VADDR    (0xb8048654)
#define GOSD_SCALEUP_FIR_COEF_HOR_C24_C27_VADDR    (0xb8048658)
#define GOSD_SCALEUP_FIR_COEF_HOR_C28_C31_VADDR    (0xb804865c)
#define GOSD_GOSD_WINDOW_CTRL0_VADDR               (0xb804862c)
#define GOSD_GOSD_WINDOW_CTRL1_VADDR               (0xb8048630)




#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======GOSD register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  bamsb:2;
        RBus_UInt32  sdsa:24;
        RBus_UInt32  res2:2;
    };
}gosd_sdsa_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  exp_avg:1;
        RBus_UInt32  mt:3;
    };
}gosd_shsr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  pltie:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  ase:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  rdie:1;
        RBus_UInt32  res4:5;
        RBus_UInt32  vima:1;
        RBus_UInt32  big_endian:1;
        RBus_UInt32  gosde:1;
    };
}gosd_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scrolling_repeat_en:1;
        RBus_UInt32  res1:20;
        RBus_UInt32  asp:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  rdip:1;
        RBus_UInt32  res3:7;
        RBus_UInt32  load_clut_sel:1;
    };
}gosd_sr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scroll_start_addr:32;
    };
}current_start_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rst:1;
        RBus_UInt32  en:1;
        RBus_UInt32  res1:30;
    };
}gosd_se_bistcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  done:1;
        RBus_UInt32  done_gosd_l2d:1;
        RBus_UInt32  res1:26;
        RBus_UInt32  mbf3:1;
        RBus_UInt32  mbf2:1;
        RBus_UInt32  mbf1:1;
        RBus_UInt32  mbf0:1;
    };
}gosd_se_bistsr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rst_plt:1;
        RBus_UInt32  en_plt:1;
        RBus_UInt32  res1:29;
        RBus_UInt32  yuvtorgb_en_n:1;
    };
}gosd_cont_plt1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  done_plt:1;
        RBus_UInt32  res1:19;
        RBus_UInt32  outfifo_ovfl:1;
        RBus_UInt32  outfifo_unfl:1;
        RBus_UInt32  dummy1804846c_9_4:6;
        RBus_UInt32  gosddou:1;
        RBus_UInt32  mbf_plta:1;
        RBus_UInt32  mbf_pltb:1;
        RBus_UInt32  mbf_pltc:1;
    };
}gosd_cont_plt2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  owl:7;
    };
}gosd_interanl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  plt_err:3;
        RBus_UInt32  res2:5;
        RBus_UInt32  fifo:3;
    };
}gosd_inter_sr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  tst_sel:2;
    };
}gosd_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  year:4;
        RBus_UInt32  month:8;
        RBus_UInt32  day:8;
        RBus_UInt32  integer:4;
        RBus_UInt32  fraction:8;
    };
}gosd_version_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gosd_pflash_reset:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  gosd_pflash_show:8;
        RBus_UInt32  gosd_pflash_hide:8;
        RBus_UInt32  res2:7;
        RBus_UInt32  gosd_flash_enable:1;
    };
}gosd_flash_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  color1:32;
    };
}gosd_color_zone1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  color2:32;
    };
}gosd_color_zone2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  color3:32;
    };
}gosd_color_zone3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  color4:32;
    };
}gosd_color_zone4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  color5:32;
    };
}gosd_color_zone5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  color6:32;
    };
}gosd_color_zone6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  me:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  bs:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  xs:11;
        RBus_UInt32  bw:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  xe:11;
    };
}mskw1_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  ys:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  ye:11;
    };
}mskw1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  op1:4;
        RBus_UInt32  op2:4;
        RBus_UInt32  ca1:24;
    };
}mskw1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ca2:24;
    };
}mskw1_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cb1:24;
    };
}mskw1_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cb2:24;
    };
}mskw1_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  usc:32;
    };
}mskw1_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bsc:32;
    };
}mskw1_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  me:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  bs:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  xs:11;
        RBus_UInt32  bw:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  xe:11;
    };
}mskw2_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  ys:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  ye:11;
    };
}mskw2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  op1:4;
        RBus_UInt32  op2:4;
        RBus_UInt32  ca1:24;
    };
}mskw2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ca2:24;
    };
}mskw2_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cb1:24;
    };
}mskw2_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cb2:24;
    };
}mskw2_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  usc:32;
    };
}mskw2_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bsc:32;
    };
}mskw2_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  db_apply:1;
        RBus_UInt32  db_en:1;
        RBus_UInt32  bist_fail:1;
        RBus_UInt32  bist_done:1;
        RBus_UInt32  bist_rstn:1;
        RBus_UInt32  bist_mode:1;
        RBus_UInt32  buff_unf:1;
        RBus_UInt32  irq_buf_udf_en:1;
        RBus_UInt32  res1:12;
        RBus_UInt32  dummy18048600_11_2:10;
        RBus_UInt32  v_zoom_en:1;
        RBus_UInt32  h_zoom_en:1;
    };
}scaleup_Ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  hor_factor:20;
    };
}scaleup_Scale_Hor_Factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  ver_factor:20;
    };
}scaleup_Scale_Ver_Factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  hor_ini:8;
        RBus_UInt32  ver_ini:8;
    };
}scaleup_Initial_Value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  hor_input_size:12;
        RBus_UInt32  res2:5;
        RBus_UInt32  ver_input_size:11;
    };
}scaleup_Input_Size_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  conti:1;
        RBus_UInt32  start:1;
    };
}scaleup_MEM_CRC_CTRL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mem_crc:32;
    };
}scaleup_MEM_CRC_Result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_c0:8;
        RBus_UInt32  ver_c1:8;
        RBus_UInt32  ver_c2:8;
        RBus_UInt32  ver_c3:8;
    };
}scaleup_FIR_Coef_Ver_C0_C3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_c4:8;
        RBus_UInt32  ver_c5:8;
        RBus_UInt32  ver_c6:8;
        RBus_UInt32  ver_c7:8;
    };
}scaleup_FIR_Coef_Ver_C4_C7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_c8:8;
        RBus_UInt32  ver_c9:8;
        RBus_UInt32  ver_c10:8;
        RBus_UInt32  ver_c11:8;
    };
}scaleup_FIR_Coef_Ver_C8_C11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_c12:8;
        RBus_UInt32  ver_c13:8;
        RBus_UInt32  ver_c14:8;
        RBus_UInt32  ver_c15:8;
    };
}scaleup_FIR_Coef_Ver_C12_C15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_c0:8;
        RBus_UInt32  hor_c1:8;
        RBus_UInt32  hor_c2:8;
        RBus_UInt32  hor_c3:8;
    };
}scaleup_FIR_Coef_hor_C0_C3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_c4:8;
        RBus_UInt32  hor_c5:8;
        RBus_UInt32  hor_c6:8;
        RBus_UInt32  hor_c7:8;
    };
}scaleup_FIR_Coef_hor_C4_C7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_c8:8;
        RBus_UInt32  hor_c9:8;
        RBus_UInt32  hor_c10:8;
        RBus_UInt32  hor_c11:8;
    };
}scaleup_FIR_Coef_hor_C8_C11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_c12:8;
        RBus_UInt32  hor_c13:8;
        RBus_UInt32  hor_c14:8;
        RBus_UInt32  hor_c15:8;
    };
}scaleup_FIR_Coef_hor_C12_C15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_c16:8;
        RBus_UInt32  hor_c17:8;
        RBus_UInt32  hor_c18:8;
        RBus_UInt32  hor_c19:8;
    };
}scaleup_FIR_Coef_hor_C16_C19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_c20:8;
        RBus_UInt32  hor_c21:8;
        RBus_UInt32  hor_c22:8;
        RBus_UInt32  hor_c23:8;
    };
}scaleup_FIR_Coef_hor_C20_C23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_c24:8;
        RBus_UInt32  hor_c25:8;
        RBus_UInt32  hor_c26:8;
        RBus_UInt32  hor_c27:8;
    };
}scaleup_FIR_Coef_hor_C24_C27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_c28:8;
        RBus_UInt32  hor_c29:8;
        RBus_UInt32  hor_c30:8;
        RBus_UInt32  hor_c31:8;
    };
}scaleup_FIR_Coef_hor_C28_C31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  gosd_hor_start:12;
        RBus_UInt32  res2:5;
        RBus_UInt32  gosd_ver_start:11;
    };
}gosd_Window_CTRL0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  gosd_hor_size:12;
        RBus_UInt32  res2:5;
        RBus_UInt32  gosd_ver_size:11;
    };
}gosd_Window_CTRL1_RBUS;





#else //apply LITTLE_ENDIAN


//======GOSD register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:2;
        RBus_UInt32  sdsa:24;
        RBus_UInt32  bamsb:2;
        RBus_UInt32  res1:4;
    };
}gosd_sdsa_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mt:3;
        RBus_UInt32  exp_avg:1;
        RBus_UInt32  res1:28;
    };
}gosd_shsr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gosde:1;
        RBus_UInt32  big_endian:1;
        RBus_UInt32  vima:1;
        RBus_UInt32  res4:5;
        RBus_UInt32  rdie:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  ase:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  pltie:1;
        RBus_UInt32  res1:19;
    };
}gosd_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  load_clut_sel:1;
        RBus_UInt32  res3:7;
        RBus_UInt32  rdip:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  asp:1;
        RBus_UInt32  res1:20;
        RBus_UInt32  scrolling_repeat_en:1;
    };
}gosd_sr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scroll_start_addr:32;
    };
}current_start_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  en:1;
        RBus_UInt32  rst:1;
    };
}gosd_se_bistcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbf0:1;
        RBus_UInt32  mbf1:1;
        RBus_UInt32  mbf2:1;
        RBus_UInt32  mbf3:1;
        RBus_UInt32  res1:26;
        RBus_UInt32  done_gosd_l2d:1;
        RBus_UInt32  done:1;
    };
}gosd_se_bistsr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  yuvtorgb_en_n:1;
        RBus_UInt32  res1:29;
        RBus_UInt32  en_plt:1;
        RBus_UInt32  rst_plt:1;
    };
}gosd_cont_plt1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbf_pltc:1;
        RBus_UInt32  mbf_pltb:1;
        RBus_UInt32  mbf_plta:1;
        RBus_UInt32  gosddou:1;
        RBus_UInt32  dummy1804846c_9_4:6;
        RBus_UInt32  outfifo_unfl:1;
        RBus_UInt32  outfifo_ovfl:1;
        RBus_UInt32  res1:19;
        RBus_UInt32  done_plt:1;
    };
}gosd_cont_plt2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  owl:7;
        RBus_UInt32  res1:25;
    };
}gosd_interanl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fifo:3;
        RBus_UInt32  res2:5;
        RBus_UInt32  plt_err:3;
        RBus_UInt32  res1:21;
    };
}gosd_inter_sr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tst_sel:2;
        RBus_UInt32  res1:30;
    };
}gosd_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fraction:8;
        RBus_UInt32  integer:4;
        RBus_UInt32  day:8;
        RBus_UInt32  month:8;
        RBus_UInt32  year:4;
    };
}gosd_version_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gosd_flash_enable:1;
        RBus_UInt32  res2:7;
        RBus_UInt32  gosd_pflash_hide:8;
        RBus_UInt32  gosd_pflash_show:8;
        RBus_UInt32  res1:7;
        RBus_UInt32  gosd_pflash_reset:1;
    };
}gosd_flash_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  color1:32;
    };
}gosd_color_zone1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  color2:32;
    };
}gosd_color_zone2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  color3:32;
    };
}gosd_color_zone3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  color4:32;
    };
}gosd_color_zone4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  color5:32;
    };
}gosd_color_zone5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  color6:32;
    };
}gosd_color_zone6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  xe:11;
        RBus_UInt32  res3:1;
        RBus_UInt32  bw:4;
        RBus_UInt32  xs:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  bs:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  me:1;
    };
}mskw1_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ye:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  ys:11;
        RBus_UInt32  res1:5;
    };
}mskw1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ca1:24;
        RBus_UInt32  op2:4;
        RBus_UInt32  op1:4;
    };
}mskw1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ca2:24;
        RBus_UInt32  res1:8;
    };
}mskw1_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cb1:24;
        RBus_UInt32  res1:8;
    };
}mskw1_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cb2:24;
        RBus_UInt32  res1:8;
    };
}mskw1_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  usc:32;
    };
}mskw1_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bsc:32;
    };
}mskw1_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  xe:11;
        RBus_UInt32  res3:1;
        RBus_UInt32  bw:4;
        RBus_UInt32  xs:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  bs:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  me:1;
    };
}mskw2_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ye:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  ys:11;
        RBus_UInt32  res1:5;
    };
}mskw2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ca1:24;
        RBus_UInt32  op2:4;
        RBus_UInt32  op1:4;
    };
}mskw2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ca2:24;
        RBus_UInt32  res1:8;
    };
}mskw2_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cb1:24;
        RBus_UInt32  res1:8;
    };
}mskw2_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cb2:24;
        RBus_UInt32  res1:8;
    };
}mskw2_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  usc:32;
    };
}mskw2_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bsc:32;
    };
}mskw2_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_zoom_en:1;
        RBus_UInt32  v_zoom_en:1;
        RBus_UInt32  dummy18048600_11_2:10;
        RBus_UInt32  res1:12;
        RBus_UInt32  irq_buf_udf_en:1;
        RBus_UInt32  buff_unf:1;
        RBus_UInt32  bist_mode:1;
        RBus_UInt32  bist_rstn:1;
        RBus_UInt32  bist_done:1;
        RBus_UInt32  bist_fail:1;
        RBus_UInt32  db_en:1;
        RBus_UInt32  db_apply:1;
    };
}scaleup_Ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_factor:20;
        RBus_UInt32  res1:12;
    };
}scaleup_Scale_Hor_Factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_factor:20;
        RBus_UInt32  res1:12;
    };
}scaleup_Scale_Ver_Factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_ini:8;
        RBus_UInt32  hor_ini:8;
        RBus_UInt32  res1:16;
    };
}scaleup_Initial_Value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_input_size:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  hor_input_size:12;
        RBus_UInt32  res1:4;
    };
}scaleup_Input_Size_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  start:1;
        RBus_UInt32  conti:1;
        RBus_UInt32  res1:30;
    };
}scaleup_MEM_CRC_CTRL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mem_crc:32;
    };
}scaleup_MEM_CRC_Result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_c3:8;
        RBus_UInt32  ver_c2:8;
        RBus_UInt32  ver_c1:8;
        RBus_UInt32  ver_c0:8;
    };
}scaleup_FIR_Coef_Ver_C0_C3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_c7:8;
        RBus_UInt32  ver_c6:8;
        RBus_UInt32  ver_c5:8;
        RBus_UInt32  ver_c4:8;
    };
}scaleup_FIR_Coef_Ver_C4_C7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_c11:8;
        RBus_UInt32  ver_c10:8;
        RBus_UInt32  ver_c9:8;
        RBus_UInt32  ver_c8:8;
    };
}scaleup_FIR_Coef_Ver_C8_C11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_c15:8;
        RBus_UInt32  ver_c14:8;
        RBus_UInt32  ver_c13:8;
        RBus_UInt32  ver_c12:8;
    };
}scaleup_FIR_Coef_Ver_C12_C15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_c3:8;
        RBus_UInt32  hor_c2:8;
        RBus_UInt32  hor_c1:8;
        RBus_UInt32  hor_c0:8;
    };
}scaleup_FIR_Coef_hor_C0_C3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_c7:8;
        RBus_UInt32  hor_c6:8;
        RBus_UInt32  hor_c5:8;
        RBus_UInt32  hor_c4:8;
    };
}scaleup_FIR_Coef_hor_C4_C7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_c11:8;
        RBus_UInt32  hor_c10:8;
        RBus_UInt32  hor_c9:8;
        RBus_UInt32  hor_c8:8;
    };
}scaleup_FIR_Coef_hor_C8_C11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_c15:8;
        RBus_UInt32  hor_c14:8;
        RBus_UInt32  hor_c13:8;
        RBus_UInt32  hor_c12:8;
    };
}scaleup_FIR_Coef_hor_C12_C15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_c19:8;
        RBus_UInt32  hor_c18:8;
        RBus_UInt32  hor_c17:8;
        RBus_UInt32  hor_c16:8;
    };
}scaleup_FIR_Coef_hor_C16_C19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_c23:8;
        RBus_UInt32  hor_c22:8;
        RBus_UInt32  hor_c21:8;
        RBus_UInt32  hor_c20:8;
    };
}scaleup_FIR_Coef_hor_C20_C23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_c27:8;
        RBus_UInt32  hor_c26:8;
        RBus_UInt32  hor_c25:8;
        RBus_UInt32  hor_c24:8;
    };
}scaleup_FIR_Coef_hor_C24_C27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_c31:8;
        RBus_UInt32  hor_c30:8;
        RBus_UInt32  hor_c29:8;
        RBus_UInt32  hor_c28:8;
    };
}scaleup_FIR_Coef_hor_C28_C31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gosd_ver_start:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  gosd_hor_start:12;
        RBus_UInt32  res1:4;
    };
}gosd_Window_CTRL0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gosd_ver_size:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  gosd_hor_size:12;
        RBus_UInt32  res1:4;
    };
}gosd_Window_CTRL1_RBUS;


#endif







#endif //_RBUS_GOSD_REG_H_

