/**
* @file rbusOsdOvlReg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2013/12/30
* @version 1.1
* @ingroup model_rbus
*
*/

#ifndef _OSD_MIXER_REG_H_
#define _OSD_MIXER_REG_H_

#include <linux/types.h>    /* size_t         */




// OSDOVL Register Address

#define OSDOVL_MIXER_CTRL2_VADDR                   (0xb802b000)
#define OSDOVL_OSD1_MIXER_GAIN_CTRL_VADDR          (0xb802b004)
#define OSDOVL_OSD1_MIXER_GAIN_CTRL_OFFSET_VADDR   (0xb802b008)
#define OSDOVL_OSD2_MIXER_GAIN_CTRL_VADDR          (0xb802b00c)
#define OSDOVL_OSD2_MIXER_GAIN_CTRL_OFFSET_VADDR   (0xb802b010)
#define OSDOVL_OSD1_MIXER_ALPHA_GAIN_VADDR         (0xb802b014)
#define OSDOVL_OSD_DB_CTRL_VADDR                   (0xb802b018)
#define OSDOVL_MIXER_CR1_X_VADDR                   (0xb802b01c)
#define OSDOVL_MIXER_CR1_Y_VADDR                   (0xb802b020)
#define OSDOVL_MIXER_CR2_X_VADDR                   (0xb802b024)
#define OSDOVL_MIXER_CR2_Y_VADDR                   (0xb802b028)
#define OSDOVL_MIXER_CR3_X_VADDR                   (0xb802b02c)
#define OSDOVL_MIXER_CR3_Y_VADDR                   (0xb802b030)
#define OSDOVL_MIXER_CRC_SEL_VADDR                 (0xb802b040)
#define OSDOVL_MIXER_CRC_CTRL_VADDR                (0xb802b044)
#define OSDOVL_MIXER_CRC_RESULT_VADDR              (0xb802b048)
#define OSDOVL_MIXER_CTRL1_VADDR                   (0xb802b060)
#define OSDOVL_SUBT_CR_X_VADDR                     (0xb802b064)
#define OSDOVL_SUBT_CR_Y_VADDR                     (0xb802b068)




#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======OSDOVL register structure define==========
typedef union
{
    uint32_t regValue;
    struct{
        uint32_t  res1:15;
        uint32_t  osd_mixer_order:1;
        uint32_t  premultiplyo1_en:1;
        uint32_t  premultiplyo2_en:1;
        uint32_t  premultiply_mode_en:1;
        uint32_t  video_osd_blend_dir:1;
        uint32_t  dummy1802b000_11_10:2;
        uint32_t  blendingo2_en:1;
        uint32_t  mixero2_en:1;
        uint32_t  dummy1802b000_7_6:2;
        uint32_t  blendingo1_en:1;
        uint32_t  mixero1_en:1;
        uint32_t  res2:3;
        uint32_t  mixer_en:1;
    };
}mixer_ctrl2_RBUS;

typedef union
{
    uint32_t regValue;
    struct{
        uint32_t  osd1_gain_en:1;
        uint32_t  res1:7;
        uint32_t  osd1_b_gain:8;
        uint32_t  osd1_g_gain:8;
        uint32_t  osd1_r_gain:8;
    };
}osd1_mixer_gain_ctrl_RBUS;

typedef union
{
    uint32_t regValue;
    struct{
        uint32_t  res1:8;
        uint32_t  osd1_b_gain_offset:8;
        uint32_t  osd1_g_gain_offset:8;
        uint32_t  osd1_r_gain_offset:8;
    };
}osd1_mixer_gain_ctrl_offset_RBUS;

typedef union
{
    uint32_t regValue;
    struct{
        uint32_t  osd2_gain_en:1;
        uint32_t  res1:7;
        uint32_t  osd2_b_gain:8;
        uint32_t  osd2_g_gain:8;
        uint32_t  osd2_r_gain:8;
    };
}osd2_mixer_gain_ctrl_RBUS;

typedef union
{
    uint32_t regValue;
    struct{
        uint32_t  res1:8;
        uint32_t  osd2_b_gain_offset:8;
        uint32_t  osd2_g_gain_offset:8;
        uint32_t  osd2_r_gain_offset:8;
    };
}osd2_mixer_gain_ctrl_offset_RBUS;

typedef union
{
    uint32_t regValue;
    struct{
        uint32_t  res1:16;
        uint32_t  osd2_alpha_gain:8;
        uint32_t  osd1_alpha_gain:8;
    };
}osd1_mixer_alpha_gain_RBUS;

typedef union
{
    uint32_t regValue;
    struct{
        uint32_t  res1:29;
        uint32_t  db_read:1;
        uint32_t  db_en:1;
        uint32_t  db_load:1;
    };
}osd_db_ctrl_RBUS;

typedef union
{
    uint32_t regValue;
    struct{
        uint32_t  dummy1802b01c_31:1;
        uint32_t  mixer_cr1_o2en:1;
        uint32_t  mixer_cr1_o1en:1;
        uint32_t  mixer_cr1_en:1;
        uint32_t  mixer_cr1_xend:13;
        uint32_t  res1:2;
        uint32_t  mixer_cr1_xstart:13;
    };
}mixer_cr1_x_RBUS;

typedef union
{
    uint32_t regValue;
    struct{
        uint32_t  res1:4;
        uint32_t  mixer_cr1_yend:12;
        uint32_t  res2:4;
        uint32_t  mixer_cr1_ystart:12;
    };
}mixer_cr1_y_RBUS;

typedef union
{
    uint32_t regValue;
    struct{
        uint32_t  dummy1802b024_31:1;
        uint32_t  mixer_cr2_o2en:1;
        uint32_t  mixer_cr2_o1en:1;
        uint32_t  mixer_cr2_en:1;
        uint32_t  mixer_cr2_xend:13;
        uint32_t  res1:2;
        uint32_t  mixer_cr2_xstart:13;
    };
}mixer_cr2_x_RBUS;

typedef union
{
    uint32_t regValue;
    struct{
        uint32_t  res1:4;
        uint32_t  mixer_cr2_yend:12;
        uint32_t  res2:4;
        uint32_t  mixer_cr2_ystart:12;
    };
}mixer_cr2_y_RBUS;

typedef union
{
    uint32_t regValue;
    struct{
        uint32_t  dummy1802b02c_31:1;
        uint32_t  mixer_cr3_o2en:1;
        uint32_t  mixer_cr3_o1en:1;
        uint32_t  mixer_cr3_en:1;
        uint32_t  mixer_cr3_xend:13;
        uint32_t  res1:2;
        uint32_t  mixer_cr3_xstart:13;
    };
}mixer_cr3_x_RBUS;

typedef union
{
    uint32_t regValue;
    struct{
        uint32_t  res1:4;
        uint32_t  mixer_cr3_yend:12;
        uint32_t  res2:4;
        uint32_t  mixer_cr3_ystart:12;
    };
}mixer_cr3_y_RBUS;

typedef union
{
    uint32_t regValue;
    struct{
        uint32_t  res1:29;
        uint32_t  mixer_crc_sel:3;
    };
}mixer_crc_sel_RBUS;

typedef union
{
    uint32_t regValue;
    struct{
        uint32_t  res1:29;
        uint32_t  mixer_crc_done:1;
        uint32_t  mixer_crc_cont:1;
        uint32_t  mixer_crc_start:1;
    };
}mixer_crc_ctrl_RBUS;

typedef union
{
    uint32_t regValue;
    struct{
        uint32_t  mixer_crc_result:32;
    };
}mixer_crc_result_RBUS;

typedef union
{
    uint32_t regValue;
    struct{
        uint32_t  res1:15;
        uint32_t  subt_other_ch_ble_sel:1;
        uint32_t  res2:1;
        uint32_t  subt_pop_or_subt_mode:1;
        uint32_t  res3:1;
        uint32_t  subt_dis_conbri:1;
        uint32_t  res4:1;
        uint32_t  subt_dis_srgb:1;
        uint32_t  res5:1;
        uint32_t  subt_dis_gamma:1;
        uint32_t  res6:1;
        uint32_t  subt_en_as_act:1;
        uint32_t  res7:1;
        uint32_t  subt_blending_en:1;
        uint32_t  res8:1;
        uint32_t  subt_chsel:1;
        uint32_t  res9:1;
        uint32_t  subt_en:1;
    };
}mixer_ctrl1_RBUS;

typedef union
{
    uint32_t regValue;
    struct{
        uint32_t  res1:3;
        uint32_t  subt_cr_en:1;
        uint32_t  subt_cr_xend:13;
        uint32_t  res2:2;
        uint32_t  subt_cr_xstart:13;
    };
}subt_cr_x_RBUS;

typedef union
{
    uint32_t regValue;
    struct{
        uint32_t  res1:4;
        uint32_t  subt_cr_yend:12;
        uint32_t  res2:4;
        uint32_t  subt_cr_ystart:12;
    };
}subt_cr_y_RBUS;





#else //apply LITTLE_ENDIAN


//======OSDOVL register structure define==========
typedef union
{
    uint32_t regValue;
    struct{
        uint32_t  mixer_en:1;
        uint32_t  res2:3;
        uint32_t  mixero1_en:1;
        uint32_t  blendingo1_en:1;
        uint32_t  dummy1802b000_7_6:2;
        uint32_t  mixero2_en:1;
        uint32_t  blendingo2_en:1;
        uint32_t  dummy1802b000_11_10:2;
        uint32_t  video_osd_blend_dir:1;
        uint32_t  premultiply_mode_en:1;
        uint32_t  premultiplyo2_en:1;
        uint32_t  premultiplyo1_en:1;
        uint32_t  osd_mixer_order:1;
        uint32_t  res1:15;
    };
}mixer_ctrl2_RBUS;

typedef union
{
    uint32_t regValue;
    struct{
        uint32_t  osd1_r_gain:8;
        uint32_t  osd1_g_gain:8;
        uint32_t  osd1_b_gain:8;
        uint32_t  res1:7;
        uint32_t  osd1_gain_en:1;
    };
}osd1_mixer_gain_ctrl_RBUS;

typedef union
{
    uint32_t regValue;
    struct{
        uint32_t  osd1_r_gain_offset:8;
        uint32_t  osd1_g_gain_offset:8;
        uint32_t  osd1_b_gain_offset:8;
        uint32_t  res1:8;
    };
}osd1_mixer_gain_ctrl_offset_RBUS;

typedef union
{
    uint32_t regValue;
    struct{
        uint32_t  osd2_r_gain:8;
        uint32_t  osd2_g_gain:8;
        uint32_t  osd2_b_gain:8;
        uint32_t  res1:7;
        uint32_t  osd2_gain_en:1;
    };
}osd2_mixer_gain_ctrl_RBUS;

typedef union
{
    uint32_t regValue;
    struct{
        uint32_t  osd2_r_gain_offset:8;
        uint32_t  osd2_g_gain_offset:8;
        uint32_t  osd2_b_gain_offset:8;
        uint32_t  res1:8;
    };
}osd2_mixer_gain_ctrl_offset_RBUS;

typedef union
{
    uint32_t regValue;
    struct{
        uint32_t  osd1_alpha_gain:8;
        uint32_t  osd2_alpha_gain:8;
        uint32_t  res1:16;
    };
}osd1_mixer_alpha_gain_RBUS;

typedef union
{
    uint32_t regValue;
    struct{
        uint32_t  db_load:1;
        uint32_t  db_en:1;
        uint32_t  db_read:1;
        uint32_t  res1:29;
    };
}osd_db_ctrl_RBUS;

typedef union
{
    uint32_t regValue;
    struct{
        uint32_t  mixer_cr1_xstart:13;
        uint32_t  res1:2;
        uint32_t  mixer_cr1_xend:13;
        uint32_t  mixer_cr1_en:1;
        uint32_t  mixer_cr1_o1en:1;
        uint32_t  mixer_cr1_o2en:1;
        uint32_t  dummy1802b01c_31:1;
    };
}mixer_cr1_x_RBUS;

typedef union
{
    uint32_t regValue;
    struct{
        uint32_t  mixer_cr1_ystart:12;
        uint32_t  res2:4;
        uint32_t  mixer_cr1_yend:12;
        uint32_t  res1:4;
    };
}mixer_cr1_y_RBUS;

typedef union
{
    uint32_t regValue;
    struct{
        uint32_t  mixer_cr2_xstart:13;
        uint32_t  res1:2;
        uint32_t  mixer_cr2_xend:13;
        uint32_t  mixer_cr2_en:1;
        uint32_t  mixer_cr2_o1en:1;
        uint32_t  mixer_cr2_o2en:1;
        uint32_t  dummy1802b024_31:1;
    };
}mixer_cr2_x_RBUS;

typedef union
{
    uint32_t regValue;
    struct{
        uint32_t  mixer_cr2_ystart:12;
        uint32_t  res2:4;
        uint32_t  mixer_cr2_yend:12;
        uint32_t  res1:4;
    };
}mixer_cr2_y_RBUS;

typedef union
{
    uint32_t regValue;
    struct{
        uint32_t  mixer_cr3_xstart:13;
        uint32_t  res1:2;
        uint32_t  mixer_cr3_xend:13;
        uint32_t  mixer_cr3_en:1;
        uint32_t  mixer_cr3_o1en:1;
        uint32_t  mixer_cr3_o2en:1;
        uint32_t  dummy1802b02c_31:1;
    };
}mixer_cr3_x_RBUS;

typedef union
{
    uint32_t regValue;
    struct{
        uint32_t  mixer_cr3_ystart:12;
        uint32_t  res2:4;
        uint32_t  mixer_cr3_yend:12;
        uint32_t  res1:4;
    };
}mixer_cr3_y_RBUS;

typedef union
{
    uint32_t regValue;
    struct{
        uint32_t  mixer_crc_sel:3;
        uint32_t  res1:29;
    };
}mixer_crc_sel_RBUS;

typedef union
{
    uint32_t regValue;
    struct{
        uint32_t  mixer_crc_start:1;
        uint32_t  mixer_crc_cont:1;
        uint32_t  mixer_crc_done:1;
        uint32_t  res1:29;
    };
}mixer_crc_ctrl_RBUS;

typedef union
{
    uint32_t regValue;
    struct{
        uint32_t  mixer_crc_result:32;
    };
}mixer_crc_result_RBUS;

typedef union
{
    uint32_t regValue;
    struct{
        uint32_t  subt_en:1;
        uint32_t  res9:1;
        uint32_t  subt_chsel:1;
        uint32_t  res8:1;
        uint32_t  subt_blending_en:1;
        uint32_t  res7:1;
        uint32_t  subt_en_as_act:1;
        uint32_t  res6:1;
        uint32_t  subt_dis_gamma:1;
        uint32_t  res5:1;
        uint32_t  subt_dis_srgb:1;
        uint32_t  res4:1;
        uint32_t  subt_dis_conbri:1;
        uint32_t  res3:1;
        uint32_t  subt_pop_or_subt_mode:1;
        uint32_t  res2:1;
        uint32_t  subt_other_ch_ble_sel:1;
        uint32_t  res1:15;
    };
}mixer_ctrl1_RBUS;

typedef union
{
    uint32_t regValue;
    struct{
        uint32_t  subt_cr_xstart:13;
        uint32_t  res2:2;
        uint32_t  subt_cr_xend:13;
        uint32_t  subt_cr_en:1;
        uint32_t  res1:3;
    };
}subt_cr_x_RBUS;

typedef union
{
    uint32_t regValue;
    struct{
        uint32_t  subt_cr_ystart:12;
        uint32_t  res2:4;
        uint32_t  subt_cr_yend:12;
        uint32_t  res1:4;
    };
}subt_cr_y_RBUS;


#endif







#endif //_OSD_MIXER_REG_H_

