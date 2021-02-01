/**
* @file rbusOsdOvlReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2014/7/29
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_OSDOVL_REG_H_
#define _RBUS_OSDOVL_REG_H_

#include "rbusTypes.h"



//  OSDOVL Register Address



#define  OSDOVL_MIXER_CTRL2_VADDR                           	(0xb802b000)
#define  OSDOVL_OSD1_MIXER_GAIN_CTRL_VADDR                  	(0xb802b004)
#define  OSDOVL_OSD1_MIXER_GAIN_CTRL_OFFSET_VADDR           	(0xb802b008)
#define  OSDOVL_OSD2_MIXER_GAIN_CTRL_VADDR                  	(0xb802b00c)
#define  OSDOVL_OSD2_MIXER_GAIN_CTRL_OFFSET_VADDR           	(0xb802b010)
#define  OSDOVL_OSD1_MIXER_ALPHA_GAIN_VADDR                 	(0xb802b014)
#define  OSDOVL_OSD_DB_CTRL_VADDR                           	(0xb802b018)
#define  OSDOVL_MIXER_CR1_X_VADDR                           	(0xb802b01c)
#define  OSDOVL_MIXER_CR1_Y_VADDR                           	(0xb802b020)
#define  OSDOVL_MIXER_CR2_X_VADDR                           	(0xb802b024)
#define  OSDOVL_MIXER_CR2_Y_VADDR                           	(0xb802b028)
#define  OSDOVL_MIXER_CR3_X_VADDR                           	(0xb802b02c)
#define  OSDOVL_MIXER_CR3_Y_VADDR                           	(0xb802b030)
#define  OSDOVL_MIXER_CRC_SEL_VADDR                         	(0xb802b040)
#define  OSDOVL_MIXER_CRC_CTRL_VADDR                        	(0xb802b044)
#define  OSDOVL_MIXER_CRC_RESULT_VADDR                      	(0xb802b048)
#define  OSDOVL_MIXER_CTRL1_VADDR                           	(0xb802b060)
#define  OSDOVL_SUBT_CR_X_VADDR                             	(0xb802b064)
#define  OSDOVL_SUBT_CR_Y_VADDR                             	(0xb802b068)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======OSDOVL register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  osd_mixer_order:1;
        RBus_UInt32  premultiplyo1_en:1;
        RBus_UInt32  premultiplyo2_en:1;
        RBus_UInt32  premultiply_mode_en:1;
        RBus_UInt32  video_osd_blend_dir:1;
        RBus_UInt32  dummy1802b000_11_10:2;
        RBus_UInt32  blendingo2_en:1;
        RBus_UInt32  mixero2_en:1;
        RBus_UInt32  dummy1802b000_7_6:2;
        RBus_UInt32  blendingo1_en:1;
        RBus_UInt32  mixero1_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  mixer_en:1;
    };
}osdovl_mixer_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd1_gain_en:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  osd1_b_gain:8;
        RBus_UInt32  osd1_g_gain:8;
        RBus_UInt32  osd1_r_gain:8;
    };
}osdovl_osd1_mixer_gain_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  osd1_b_gain_offset:8;
        RBus_UInt32  osd1_g_gain_offset:8;
        RBus_UInt32  osd1_r_gain_offset:8;
    };
}osdovl_osd1_mixer_gain_ctrl_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd2_gain_en:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  osd2_b_gain:8;
        RBus_UInt32  osd2_g_gain:8;
        RBus_UInt32  osd2_r_gain:8;
    };
}osdovl_osd2_mixer_gain_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  osd2_b_gain_offset:8;
        RBus_UInt32  osd2_g_gain_offset:8;
        RBus_UInt32  osd2_r_gain_offset:8;
    };
}osdovl_osd2_mixer_gain_ctrl_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  osd2_alpha_gain:8;
        RBus_UInt32  osd1_alpha_gain:8;
    };
}osdovl_osd1_mixer_alpha_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  db_read:1;
        RBus_UInt32  db_en:1;
        RBus_UInt32  db_load:1;
    };
}osdovl_osd_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802b01c_31:1;
        RBus_UInt32  mixer_cr1_o2en:1;
        RBus_UInt32  mixer_cr1_o1en:1;
        RBus_UInt32  mixer_cr1_en:1;
        RBus_UInt32  mixer_cr1_xend:13;
        RBus_UInt32  res1:2;
        RBus_UInt32  mixer_cr1_xstart:13;
    };
}osdovl_mixer_cr1_x_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  mixer_cr1_yend:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  mixer_cr1_ystart:12;
    };
}osdovl_mixer_cr1_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802b024_31:1;
        RBus_UInt32  mixer_cr2_o2en:1;
        RBus_UInt32  mixer_cr2_o1en:1;
        RBus_UInt32  mixer_cr2_en:1;
        RBus_UInt32  mixer_cr2_xend:13;
        RBus_UInt32  res1:2;
        RBus_UInt32  mixer_cr2_xstart:13;
    };
}osdovl_mixer_cr2_x_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  mixer_cr2_yend:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  mixer_cr2_ystart:12;
    };
}osdovl_mixer_cr2_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802b02c_31:1;
        RBus_UInt32  mixer_cr3_o2en:1;
        RBus_UInt32  mixer_cr3_o1en:1;
        RBus_UInt32  mixer_cr3_en:1;
        RBus_UInt32  mixer_cr3_xend:13;
        RBus_UInt32  res1:2;
        RBus_UInt32  mixer_cr3_xstart:13;
    };
}osdovl_mixer_cr3_x_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  mixer_cr3_yend:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  mixer_cr3_ystart:12;
    };
}osdovl_mixer_cr3_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  mixer_crc_sel:3;
    };
}osdovl_mixer_crc_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  mixer_crc_done:1;
        RBus_UInt32  mixer_crc_cont:1;
        RBus_UInt32  mixer_crc_start:1;
    };
}osdovl_mixer_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mixer_crc_result:32;
    };
}osdovl_mixer_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  subt_other_ch_ble_sel:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  subt_dis_conbri:1;
        RBus_UInt32  subt_dis_srgb:1;
        RBus_UInt32  subt_dis_inv_gamma:1;
        RBus_UInt32  subt_dis_gamma:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  subt_en_as_act:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  subt_blending_en:1;
        RBus_UInt32  res5:3;
        RBus_UInt32  subt_en:1;
    };
}osdovl_mixer_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  subt_cr_en:1;
        RBus_UInt32  subt_cr_xend:13;
        RBus_UInt32  res2:2;
        RBus_UInt32  subt_cr_xstart:13;
    };
}osdovl_subt_cr_x_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  subt_cr_yend:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  subt_cr_ystart:12;
    };
}osdovl_subt_cr_y_RBUS;

#else //apply LITTLE_ENDIAN

//======OSDOVL register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mixer_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  mixero1_en:1;
        RBus_UInt32  blendingo1_en:1;
        RBus_UInt32  dummy1802b000_7:2;
        RBus_UInt32  mixero2_en:1;
        RBus_UInt32  blendingo2_en:1;
        RBus_UInt32  dummy1802b000_11:2;
        RBus_UInt32  video_osd_blend_dir:1;
        RBus_UInt32  premultiply_mode_en:1;
        RBus_UInt32  premultiplyo2_en:1;
        RBus_UInt32  premultiplyo1_en:1;
        RBus_UInt32  osd_mixer_order:1;
        RBus_UInt32  res2:15;
    };
}osdovl_mixer_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd1_r_gain:8;
        RBus_UInt32  osd1_g_gain:8;
        RBus_UInt32  osd1_b_gain:8;
        RBus_UInt32  res1:7;
        RBus_UInt32  osd1_gain_en:1;
    };
}osdovl_osd1_mixer_gain_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd1_r_gain_offset:8;
        RBus_UInt32  osd1_g_gain_offset:8;
        RBus_UInt32  osd1_b_gain_offset:8;
        RBus_UInt32  res1:8;
    };
}osdovl_osd1_mixer_gain_ctrl_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd2_r_gain:8;
        RBus_UInt32  osd2_g_gain:8;
        RBus_UInt32  osd2_b_gain:8;
        RBus_UInt32  res1:7;
        RBus_UInt32  osd2_gain_en:1;
    };
}osdovl_osd2_mixer_gain_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd2_r_gain_offset:8;
        RBus_UInt32  osd2_g_gain_offset:8;
        RBus_UInt32  osd2_b_gain_offset:8;
        RBus_UInt32  res1:8;
    };
}osdovl_osd2_mixer_gain_ctrl_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd1_alpha_gain:8;
        RBus_UInt32  osd2_alpha_gain:8;
        RBus_UInt32  res1:16;
    };
}osdovl_osd1_mixer_alpha_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  db_load:1;
        RBus_UInt32  db_en:1;
        RBus_UInt32  db_read:1;
        RBus_UInt32  res1:29;
    };
}osdovl_osd_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mixer_cr1_xstart:13;
        RBus_UInt32  res1:2;
        RBus_UInt32  mixer_cr1_xend:13;
        RBus_UInt32  mixer_cr1_en:1;
        RBus_UInt32  mixer_cr1_o1en:1;
        RBus_UInt32  mixer_cr1_o2en:1;
        RBus_UInt32  dummy1802b01c_31_31:1;
    };
}osdovl_mixer_cr1_x_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mixer_cr1_ystart:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  mixer_cr1_yend:12;
        RBus_UInt32  res2:4;
    };
}osdovl_mixer_cr1_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mixer_cr2_xstart:13;
        RBus_UInt32  res1:2;
        RBus_UInt32  mixer_cr2_xend:13;
        RBus_UInt32  mixer_cr2_en:1;
        RBus_UInt32  mixer_cr2_o1en:1;
        RBus_UInt32  mixer_cr2_o2en:1;
        RBus_UInt32  dummy1802b024_31_31:1;
    };
}osdovl_mixer_cr2_x_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mixer_cr2_ystart:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  mixer_cr2_yend:12;
        RBus_UInt32  res2:4;
    };
}osdovl_mixer_cr2_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mixer_cr3_xstart:13;
        RBus_UInt32  res1:2;
        RBus_UInt32  mixer_cr3_xend:13;
        RBus_UInt32  mixer_cr3_en:1;
        RBus_UInt32  mixer_cr3_o1en:1;
        RBus_UInt32  mixer_cr3_o2en:1;
        RBus_UInt32  dummy1802b02c_31_31:1;
    };
}osdovl_mixer_cr3_x_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mixer_cr3_ystart:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  mixer_cr3_yend:12;
        RBus_UInt32  res2:4;
    };
}osdovl_mixer_cr3_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mixer_crc_sel:3;
        RBus_UInt32  res1:29;
    };
}osdovl_mixer_crc_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mixer_crc_start:1;
        RBus_UInt32  mixer_crc_cont:1;
        RBus_UInt32  mixer_crc_done:1;
        RBus_UInt32  res1:29;
    };
}osdovl_mixer_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mixer_crc_result:32;
    };
}osdovl_mixer_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  subt_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  subt_blending_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  subt_en_as_act:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  subt_dis_gamma:1;
        RBus_UInt32  subt_dis_inv_gamma:1;
        RBus_UInt32  subt_dis_srgb:1;
        RBus_UInt32  subt_dis_conbri:1;
        RBus_UInt32  res4:4;
        RBus_UInt32  subt_other_ch_ble_sel:1;
        RBus_UInt32  res5:15;
    };
}osdovl_mixer_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  subt_cr_xstart:13;
        RBus_UInt32  res1:2;
        RBus_UInt32  subt_cr_xend:13;
        RBus_UInt32  subt_cr_en:1;
        RBus_UInt32  res2:3;
    };
}osdovl_subt_cr_x_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  subt_cr_ystart:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  subt_cr_yend:12;
        RBus_UInt32  res2:4;
    };
}osdovl_subt_cr_y_RBUS;




#endif 


#endif 
