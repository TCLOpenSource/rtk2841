/**
* @file rbusGsysSEReg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2008/5/14
* @version 1.1
* @ingroup model_rbus
*
*/

#ifndef _RBUS_GSYSSE_REG_H_
#define _RBUS_GSYSSE_REG_H_

#include "rbus/rbusTypes.h"




// GSYSSE Register Address
#define GSYSSE_SE_SA_ADDR                          (0x18048510)
#define GSYSSE_SE_CR_ADDR                          (0x18048514)
#define GSYSSE_SE_SR_ADDR                          (0x18048518)
#define GSYSSE_VD_FHL_ADDR                         (0x18048528)
#define GSYSSE_VD_FVL_ADDR                         (0x1804852c)
#define GSYSSE_VD_FC_ADDR                          (0x18048534)
#define GSYSSE_SE_VER_ADDR                         (0x1804853c)
#define GSYSSE_SUBTITLE_DOU_ADDR                   (0x18048550)
#define GSYSSE_FLASH_CONTROL_ADDR                  (0x18048554)
#define GSYSSE_FLASH_COLOR_OBJECT1_ADDR            (0x18048558)
#define GSYSSE_FLASH_COLOR_OBJECT2_ADDR            (0x1804855c)
#define GSYSSE_FLASH_COLOR_OBJECT3_ADDR            (0x18048560)
#define GSYSSE_FLASH_COLOR_OBJECT4_ADDR            (0x18048564)
#define GSYSSE_CLUT_CONTROL_ADDR                   (0x18048568)
#define GSYSSE_CLUT_DATA_ADDR                      (0x1804856c)
#define GSYSSE_SUBTITLE_SCALEUP_CTRL_ADDR          (0x18048700)
#define GSYSSE_SUBTITLE_SCALEUP_SUBTITLE_SCALEUP_HOR_FACTOR_ADDR  (0x18048704)
#define GSYSSE_SUBTITLE_SCALEUP_SUBTITLE_SCALEUP_VER_FACTOR_ADDR  (0x18048708)
#define GSYSSE_SUBTITLE_SCALEUP_INITIAL_VALUE_ADDR (0x1804870c)
#define GSYSSE_SUBTITLE_SCALEUP_INPUT_SIZE_ADDR    (0x18048710)
#define GSYSSE_SUBTITLE_SCALEUP_CRC_CTRL_ADDR      (0x18048714)
#define GSYSSE_SUBTITLE_SCALEUP_CRC_RESULT_ADDR    (0x18048718)
#define GSYSSE_SUBTITLE_SCALEUP_FIR_COEF_VER_HOR_C0_C3_ADDR  (0x1804871c)
#define GSYSSE_SUBTITLE_SCALEUP_FIR_COEF_VER_HOR_C4_C7_ADDR  (0x18048720)
#define GSYSSE_SUBTITLE_SCALEUP_FIR_COEF_VER_HOR_C8_C11_ADDR  (0x18048724)
#define GSYSSE_SUBTITLE_SCALEUP_FIR_COEF_VER_HOR_C12_C15_ADDR  (0x18048728)
#define GSYSSE_SUBTITLE_SCALEDOWN_CTRL0_ADDR       (0x18048730)
#define GSYSSE_SUBTITLE_H_SCALEDOWN_INPUT_SIZE_ADDR  (0x18048734)
#define GSYSSE_SUBTITLE_SCALEDOWN_SCALE_HOR_FACTOR_ADDR  (0x18048738)
#define GSYSSE_SUBTITLE_SCALEDOWN_INITIAL_VALUE_ADDR  (0x1804873c)

#define GSYSSE_SE_SA_VADDR                         (0xb8048510)
#define GSYSSE_SE_CR_VADDR                         (0xb8048514)
#define GSYSSE_SE_SR_VADDR                         (0xb8048518)
#define GSYSSE_VD_FHL_VADDR                        (0xb8048528)
#define GSYSSE_VD_FVL_VADDR                        (0xb804852c)
#define GSYSSE_VD_FC_VADDR                         (0xb8048534)
#define GSYSSE_SE_VER_VADDR                        (0xb804853c)
#define GSYSSE_SUBTITLE_DOU_VADDR                  (0xb8048550)
#define GSYSSE_FLASH_CONTROL_VADDR                 (0xb8048554)
#define GSYSSE_FLASH_COLOR_OBJECT1_VADDR           (0xb8048558)
#define GSYSSE_FLASH_COLOR_OBJECT2_VADDR           (0xb804855c)
#define GSYSSE_FLASH_COLOR_OBJECT3_VADDR           (0xb8048560)
#define GSYSSE_FLASH_COLOR_OBJECT4_VADDR           (0xb8048564)
#define GSYSSE_CLUT_CONTROL_VADDR                  (0xb8048568)
#define GSYSSE_CLUT_DATA_VADDR                     (0xb804856c)
#define GSYSSE_SUBTITLE_SCALEUP_CTRL_VADDR         (0xb8048700)
#define GSYSSE_SUBTITLE_SCALEUP_SUBTITLE_SCALEUP_HOR_FACTOR_VADDR  (0xb8048704)
#define GSYSSE_SUBTITLE_SCALEUP_SUBTITLE_SCALEUP_VER_FACTOR_VADDR  (0xb8048708)
#define GSYSSE_SUBTITLE_SCALEUP_INITIAL_VALUE_VADDR  (0xb804870c)
#define GSYSSE_SUBTITLE_SCALEUP_INPUT_SIZE_VADDR   (0xb8048710)
#define GSYSSE_SUBTITLE_SCALEUP_CRC_CTRL_VADDR     (0xb8048714)
#define GSYSSE_SUBTITLE_SCALEUP_CRC_RESULT_VADDR   (0xb8048718)
#define GSYSSE_SUBTITLE_SCALEUP_FIR_COEF_VER_HOR_C0_C3_VADDR  (0xb804871c)
#define GSYSSE_SUBTITLE_SCALEUP_FIR_COEF_VER_HOR_C4_C7_VADDR  (0xb8048720)
#define GSYSSE_SUBTITLE_SCALEUP_FIR_COEF_VER_HOR_C8_C11_VADDR  (0xb8048724)
#define GSYSSE_SUBTITLE_SCALEUP_FIR_COEF_VER_HOR_C12_C15_VADDR  (0xb8048728)
#define GSYSSE_SUBTITLE_SCALEDOWN_CTRL0_VADDR      (0xb8048730)
#define GSYSSE_SUBTITLE_H_SCALEDOWN_INPUT_SIZE_VADDR  (0xb8048734)
#define GSYSSE_SUBTITLE_SCALEDOWN_SCALE_HOR_FACTOR_VADDR  (0xb8048738)
#define GSYSSE_SUBTITLE_SCALEDOWN_INITIAL_VALUE_VADDR  (0xb804873c)




#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======GSYSSE register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  samsb:1;
        RBus_UInt32  sa:24;
        RBus_UInt32  zero:2;
    };
}se_sa_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  fcr:1;
        RBus_UInt32  fce:1;
        RBus_UInt32  fshow:8;
        RBus_UInt32  fhide:8;
        RBus_UInt32  res2:5;
        RBus_UInt32  rde:1;
        RBus_UInt32  ase:1;
        RBus_UInt32  see:1;
    };
}se_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  rdp:1;
        RBus_UInt32  asp:1;
        RBus_UInt32  res2:1;
    };
}se_sr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  lfhle:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  lfhls:11;
    };
}vd_fhl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  lfvle:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  lfvls:11;
    };
}vd_fvl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  von:1;
    };
}vd_fc_RBUS;

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
}se_ver_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  dummy18048550_11_1:11;
        RBus_UInt32  subdou:1;
    };
}subtitle_dou_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  subtitle_flash_enable:1;
    };
}flash_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  color_object1:32;
    };
}flash_color_object1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  color_object2:32;
    };
}flash_color_object2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  color_object3:32;
    };
}flash_color_object3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  color_object4:32;
    };
}flash_color_object4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  address:8;
        RBus_UInt32  res1:18;
        RBus_UInt32  index_selection:1;
        RBus_UInt32  dummy18048568_4:1;
        RBus_UInt32  togglesram:1;
        RBus_UInt32  status_sram:1;
        RBus_UInt32  read_write_sel:1;
        RBus_UInt32  access:1;
    };
}clut_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  color_data:32;
    };
}clut_data_RBUS;

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
        RBus_UInt32  dummy18048700_11_2:10;
        RBus_UInt32  v_subtitle_scaleup_en:1;
        RBus_UInt32  h_subtitle_scaleup_en:1;
    };
}subtitle_scaleup_Ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  hor_factor:20;
    };
}subtitle_scaleup_Subtitle_scaleup_Hor_Factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  ver_factor:20;
    };
}subtitle_scaleup_Subtitle_scaleup_Ver_Factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  hor_ini:8;
        RBus_UInt32  ver_ini:8;
    };
}subtitle_scaleup_Initial_Value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  hor_input_size:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  ver_input_size:11;
    };
}subtitle_scaleup_Input_Size_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  conti:1;
        RBus_UInt32  start:1;
    };
}subtitle_scaleup_CRC_CTRL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mem_crc:32;
    };
}subtitle_scaleup_CRC_Result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_hor_c0:8;
        RBus_UInt32  ver_hor_c1:8;
        RBus_UInt32  ver_hor_c2:8;
        RBus_UInt32  ver_hor_c3:8;
    };
}subtitle_scaleup_FIR_Coef_Ver_hor_C0_C3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_hor_c4:8;
        RBus_UInt32  ver_hor_c5:8;
        RBus_UInt32  ver_hor_c6:8;
        RBus_UInt32  ver_hor_c7:8;
    };
}subtitle_scaleup_FIR_Coef_Ver_hor_C4_C7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_hor_c8:8;
        RBus_UInt32  ver_hor_c9:8;
        RBus_UInt32  ver_hor_c10:8;
        RBus_UInt32  ver_hor_c11:8;
    };
}subtitle_scaleup_FIR_Coef_Ver_hor_C8_C11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_hor_c12:8;
        RBus_UInt32  ver_hor_c13:8;
        RBus_UInt32  ver_hor_c14:8;
        RBus_UInt32  ver_hor_c15:8;
    };
}subtitle_scaleup_FIR_Coef_Ver_hor_C12_C15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18048730_31_2:30;
        RBus_UInt32  v_zoom_en:1;
        RBus_UInt32  h_zoom_en:1;
    };
}subtitle_scaledown_Ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  dummy18048734_26_16:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  dummy18048734_10_0:11;
    };
}subtitle_h_scaledown_Input_Size_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hor_fac:24;
    };
}subtitle_scaledown_Scale_Hor_Factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  hor_ini:8;
    };
}subtitle_scaledown_Initial_Value_RBUS;





#else //apply LITTLE_ENDIAN


//======GSYSSE register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  zero:2;
        RBus_UInt32  sa:24;
        RBus_UInt32  samsb:1;
        RBus_UInt32  res1:5;
    };
}se_sa_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  see:1;
        RBus_UInt32  ase:1;
        RBus_UInt32  rde:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  fhide:8;
        RBus_UInt32  fshow:8;
        RBus_UInt32  fce:1;
        RBus_UInt32  fcr:1;
        RBus_UInt32  res1:6;
    };
}se_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:1;
        RBus_UInt32  asp:1;
        RBus_UInt32  rdp:1;
        RBus_UInt32  res1:29;
    };
}se_sr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lfhls:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  lfhle:11;
        RBus_UInt32  res1:5;
    };
}vd_fhl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lfvls:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  lfvle:11;
        RBus_UInt32  res1:5;
    };
}vd_fvl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  von:1;
        RBus_UInt32  res1:31;
    };
}vd_fc_RBUS;

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
}se_ver_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  subdou:1;
        RBus_UInt32  dummy18048550_11_1:11;
        RBus_UInt32  res1:20;
    };
}subtitle_dou_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  subtitle_flash_enable:1;
        RBus_UInt32  res1:31;
    };
}flash_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  color_object1:32;
    };
}flash_color_object1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  color_object2:32;
    };
}flash_color_object2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  color_object3:32;
    };
}flash_color_object3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  color_object4:32;
    };
}flash_color_object4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  access:1;
        RBus_UInt32  read_write_sel:1;
        RBus_UInt32  status_sram:1;
        RBus_UInt32  togglesram:1;
        RBus_UInt32  dummy18048568_4:1;
        RBus_UInt32  index_selection:1;
        RBus_UInt32  res1:18;
        RBus_UInt32  address:8;
    };
}clut_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  color_data:32;
    };
}clut_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_subtitle_scaleup_en:1;
        RBus_UInt32  v_subtitle_scaleup_en:1;
        RBus_UInt32  dummy18048700_11_2:10;
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
}subtitle_scaleup_Ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_factor:20;
        RBus_UInt32  res1:12;
    };
}subtitle_scaleup_Subtitle_scaleup_Hor_Factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_factor:20;
        RBus_UInt32  res1:12;
    };
}subtitle_scaleup_Subtitle_scaleup_Ver_Factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_ini:8;
        RBus_UInt32  hor_ini:8;
        RBus_UInt32  res1:16;
    };
}subtitle_scaleup_Initial_Value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_input_size:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  hor_input_size:11;
        RBus_UInt32  res1:5;
    };
}subtitle_scaleup_Input_Size_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  start:1;
        RBus_UInt32  conti:1;
        RBus_UInt32  res1:30;
    };
}subtitle_scaleup_CRC_CTRL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mem_crc:32;
    };
}subtitle_scaleup_CRC_Result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_hor_c3:8;
        RBus_UInt32  ver_hor_c2:8;
        RBus_UInt32  ver_hor_c1:8;
        RBus_UInt32  ver_hor_c0:8;
    };
}subtitle_scaleup_FIR_Coef_Ver_hor_C0_C3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_hor_c7:8;
        RBus_UInt32  ver_hor_c6:8;
        RBus_UInt32  ver_hor_c5:8;
        RBus_UInt32  ver_hor_c4:8;
    };
}subtitle_scaleup_FIR_Coef_Ver_hor_C4_C7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_hor_c11:8;
        RBus_UInt32  ver_hor_c10:8;
        RBus_UInt32  ver_hor_c9:8;
        RBus_UInt32  ver_hor_c8:8;
    };
}subtitle_scaleup_FIR_Coef_Ver_hor_C8_C11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_hor_c15:8;
        RBus_UInt32  ver_hor_c14:8;
        RBus_UInt32  ver_hor_c13:8;
        RBus_UInt32  ver_hor_c12:8;
    };
}subtitle_scaleup_FIR_Coef_Ver_hor_C12_C15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_zoom_en:1;
        RBus_UInt32  v_zoom_en:1;
        RBus_UInt32  dummy18048730_31_2:30;
    };
}subtitle_scaledown_Ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18048734_10_0:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  dummy18048734_26_16:11;
        RBus_UInt32  res1:5;
    };
}subtitle_h_scaledown_Input_Size_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_fac:24;
        RBus_UInt32  res1:8;
    };
}subtitle_scaledown_Scale_Hor_Factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_ini:8;
        RBus_UInt32  res1:24;
    };
}subtitle_scaledown_Initial_Value_RBUS;


#endif







#endif //_RBUS_GSYSSE_REG_H_

