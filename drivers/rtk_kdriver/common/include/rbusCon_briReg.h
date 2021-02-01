/**
* @file rbusCon_briReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015/2/12
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_CON_BRI_REG_H_
#define _RBUS_CON_BRI_REG_H_

#include "rbusTypes.h"



//  CON_BRI Register Address



#define  CON_BRI_DM_COLOR_RGB_CTRL_VADDR                    	(0xb802a800)
#define  CON_BRI_DM_CONTRAST_A_VADDR                        	(0xb802a804)
#define  CON_BRI_DM_BRIGHTNESS_1_VADDR                      	(0xb802a808)
#define  CON_BRI_DM_CONTRAST_B2B_VADDR                      	(0xb802a80c)
#define  CON_BRI_DM_BRIGHTNESS_2_VADDR                      	(0xb802a814)
#define  CON_BRI_DM_CONTRAST_B2A_VADDR                      	(0xb802a818)
#define  CON_BRI_DM_CONTRAST_A2B_VADDR                      	(0xb802a81c)
#define  CON_BRI_DS_COLOR_RGB_CTRL_VADDR                    	(0xb802a820)
#define  CON_BRI_DS_CONTRAST_A_VADDR                        	(0xb802a824)
#define  CON_BRI_DS_BRIGHTNESS_1_VADDR                      	(0xb802a828)
#define  CON_BRI_DS_CONTRAST_B2B_VADDR                      	(0xb802a82c)
#define  CON_BRI_DS_BRIGHTNESS_2_VADDR                      	(0xb802a834)
#define  CON_BRI_DS_CONTRAST_B2A_VADDR                      	(0xb802a838)
#define  CON_BRI_DS_CONTRAST_A2B_VADDR                      	(0xb802a83c)
#define  CON_BRI_D_OVERLAY_CONTRAST_A2A_VADDR               	(0xb802a840)
#define  CON_BRI_D_OVERLAY_BRIGHTNESS_3_VADDR               	(0xb802a844)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======CON_BRI register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m_blending_factor:5;
        RBus_UInt32  res1:22;
        RBus_UInt32  con_bri_mode:1;
        RBus_UInt32  m_con_toggle:1;
        RBus_UInt32  m_bri_toggle:1;
        RBus_UInt32  m_con_en:1;
        RBus_UInt32  m_bri_en:1;
    };
}con_bri_dm_color_rgb_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  m_con_a_r:10;
        RBus_UInt32  m_con_a_g:10;
        RBus_UInt32  m_con_a_b:10;
    };
}con_bri_dm_contrast_a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  m_bri1_r:10;
        RBus_UInt32  m_bri1_g:10;
        RBus_UInt32  m_bri1_b:10;
    };
}con_bri_dm_brightness_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  m_con_b2b_r:10;
        RBus_UInt32  m_con_b2b_g:10;
        RBus_UInt32  m_con_b2b_b:10;
    };
}con_bri_dm_contrast_b2b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  m_bri2_r:10;
        RBus_UInt32  m_bri2_g:10;
        RBus_UInt32  m_bri2_b:10;
    };
}con_bri_dm_brightness_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  m_con_b2a_r:10;
        RBus_UInt32  m_con_b2a_g:10;
        RBus_UInt32  m_con_b2a_b:10;
    };
}con_bri_dm_contrast_b2a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  m_con_a2b_r:10;
        RBus_UInt32  m_con_a2b_g:10;
        RBus_UInt32  m_con_a2b_b:10;
    };
}con_bri_dm_contrast_a2b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802a820_31_4:28;
        RBus_UInt32  s_con_toggle:1;
        RBus_UInt32  s_bri_toggle:1;
        RBus_UInt32  s_con_en:1;
        RBus_UInt32  s_bri_en:1;
    };
}con_bri_ds_color_rgb_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  s_con_a_r:10;
        RBus_UInt32  s_con_a_g:10;
        RBus_UInt32  s_con_a_b:10;
    };
}con_bri_ds_contrast_a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  s_bri1_r:10;
        RBus_UInt32  s_bri1_g:10;
        RBus_UInt32  s_bri1_b:10;
    };
}con_bri_ds_brightness_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  s_con_b2b_r:10;
        RBus_UInt32  s_con_b2b_g:10;
        RBus_UInt32  s_con_b2b_b:10;
    };
}con_bri_ds_contrast_b2b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  s_bri2_r:10;
        RBus_UInt32  s_bri2_g:10;
        RBus_UInt32  s_bri2_b:10;
    };
}con_bri_ds_brightness_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  s_con_b2a_r:10;
        RBus_UInt32  s_con_b2a_g:10;
        RBus_UInt32  s_con_b2a_b:10;
    };
}con_bri_ds_contrast_b2a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  s_con_a2b_r:10;
        RBus_UInt32  s_con_a2b_g:10;
        RBus_UInt32  s_con_a2b_b:10;
    };
}con_bri_ds_contrast_a2b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  v_con_a2a_r:10;
        RBus_UInt32  v_con_a2a_g:10;
        RBus_UInt32  v_con_a2a_b:10;
    };
}con_bri_d_overlay_contrast_a2a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  v_bri3_r:10;
        RBus_UInt32  v_bri3_g:10;
        RBus_UInt32  v_bri3_b:10;
    };
}con_bri_d_overlay_brightness_3_RBUS;

#else //apply LITTLE_ENDIAN

//======CON_BRI register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m_bri_en:1;
        RBus_UInt32  m_con_en:1;
        RBus_UInt32  m_bri_toggle:1;
        RBus_UInt32  m_con_toggle:1;
        RBus_UInt32  con_bri_mode:1;
        RBus_UInt32  res1:22;
        RBus_UInt32  m_blending_factor:5;
    };
}con_bri_dm_color_rgb_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m_con_a_b:10;
        RBus_UInt32  m_con_a_g:10;
        RBus_UInt32  m_con_a_r:10;
        RBus_UInt32  res1:2;
    };
}con_bri_dm_contrast_a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m_bri1_b:10;
        RBus_UInt32  m_bri1_g:10;
        RBus_UInt32  m_bri1_r:10;
        RBus_UInt32  res1:2;
    };
}con_bri_dm_brightness_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m_con_b2b_b:10;
        RBus_UInt32  m_con_b2b_g:10;
        RBus_UInt32  m_con_b2b_r:10;
        RBus_UInt32  res1:2;
    };
}con_bri_dm_contrast_b2b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m_bri2_b:10;
        RBus_UInt32  m_bri2_g:10;
        RBus_UInt32  m_bri2_r:10;
        RBus_UInt32  res1:2;
    };
}con_bri_dm_brightness_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m_con_b2a_b:10;
        RBus_UInt32  m_con_b2a_g:10;
        RBus_UInt32  m_con_b2a_r:10;
        RBus_UInt32  res1:2;
    };
}con_bri_dm_contrast_b2a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m_con_a2b_b:10;
        RBus_UInt32  m_con_a2b_g:10;
        RBus_UInt32  m_con_a2b_r:10;
        RBus_UInt32  res1:2;
    };
}con_bri_dm_contrast_a2b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s_bri_en:1;
        RBus_UInt32  s_con_en:1;
        RBus_UInt32  s_bri_toggle:1;
        RBus_UInt32  s_con_toggle:1;
        RBus_UInt32  dummy1802a820_31:28;
    };
}con_bri_ds_color_rgb_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s_con_a_b:10;
        RBus_UInt32  s_con_a_g:10;
        RBus_UInt32  s_con_a_r:10;
        RBus_UInt32  res1:2;
    };
}con_bri_ds_contrast_a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s_bri1_b:10;
        RBus_UInt32  s_bri1_g:10;
        RBus_UInt32  s_bri1_r:10;
        RBus_UInt32  res1:2;
    };
}con_bri_ds_brightness_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s_con_b2b_b:10;
        RBus_UInt32  s_con_b2b_g:10;
        RBus_UInt32  s_con_b2b_r:10;
        RBus_UInt32  res1:2;
    };
}con_bri_ds_contrast_b2b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s_bri2_b:10;
        RBus_UInt32  s_bri2_g:10;
        RBus_UInt32  s_bri2_r:10;
        RBus_UInt32  res1:2;
    };
}con_bri_ds_brightness_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s_con_b2a_b:10;
        RBus_UInt32  s_con_b2a_g:10;
        RBus_UInt32  s_con_b2a_r:10;
        RBus_UInt32  res1:2;
    };
}con_bri_ds_contrast_b2a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s_con_a2b_b:10;
        RBus_UInt32  s_con_a2b_g:10;
        RBus_UInt32  s_con_a2b_r:10;
        RBus_UInt32  res1:2;
    };
}con_bri_ds_contrast_a2b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v_con_a2a_b:10;
        RBus_UInt32  v_con_a2a_g:10;
        RBus_UInt32  v_con_a2a_r:10;
        RBus_UInt32  res1:2;
    };
}con_bri_d_overlay_contrast_a2a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v_bri3_b:10;
        RBus_UInt32  v_bri3_g:10;
        RBus_UInt32  v_bri3_r:10;
        RBus_UInt32  res1:2;
    };
}con_bri_d_overlay_brightness_3_RBUS;




#endif 


#endif 
