/**
* @file Mac5-DesignSpec-D-Domain_ConBri
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_CON_BRI_REG_H_
#define _RBUS_CON_BRI_REG_H_

#include "rbus_types.h"



//  CON_BRI Register Address
#define  CON_BRI_DM_COLOR_RGB_CTRL                                               0x1802A800
#define  CON_BRI_DM_COLOR_RGB_CTRL_reg_addr                                      "0xB802A800"
#define  CON_BRI_DM_COLOR_RGB_CTRL_reg                                           0xB802A800
#define  CON_BRI_DM_COLOR_RGB_CTRL_inst_addr                                     "0x0000"
#define  set_CON_BRI_DM_COLOR_RGB_CTRL_reg(data)                                 (*((volatile unsigned int*)CON_BRI_DM_COLOR_RGB_CTRL_reg)=data)
#define  get_CON_BRI_DM_COLOR_RGB_CTRL_reg                                       (*((volatile unsigned int*)CON_BRI_DM_COLOR_RGB_CTRL_reg))
#define  CON_BRI_DM_COLOR_RGB_CTRL_blending_main_sub_sel_shift                   (5)
#define  CON_BRI_DM_COLOR_RGB_CTRL_m_con_en_shift                                (1)
#define  CON_BRI_DM_COLOR_RGB_CTRL_m_bri_en_shift                                (0)
#define  CON_BRI_DM_COLOR_RGB_CTRL_blending_main_sub_sel_mask                    (0x00000020)
#define  CON_BRI_DM_COLOR_RGB_CTRL_m_con_en_mask                                 (0x00000002)
#define  CON_BRI_DM_COLOR_RGB_CTRL_m_bri_en_mask                                 (0x00000001)
#define  CON_BRI_DM_COLOR_RGB_CTRL_blending_main_sub_sel(data)                   (0x00000020&((data)<<5))
#define  CON_BRI_DM_COLOR_RGB_CTRL_m_con_en(data)                                (0x00000002&((data)<<1))
#define  CON_BRI_DM_COLOR_RGB_CTRL_m_bri_en(data)                                (0x00000001&(data))
#define  CON_BRI_DM_COLOR_RGB_CTRL_get_blending_main_sub_sel(data)               ((0x00000020&(data))>>5)
#define  CON_BRI_DM_COLOR_RGB_CTRL_get_m_con_en(data)                            ((0x00000002&(data))>>1)
#define  CON_BRI_DM_COLOR_RGB_CTRL_get_m_bri_en(data)                            (0x00000001&(data))

#define  CON_BRI_DM_CONTRAST_A                                                   0x1802A804
#define  CON_BRI_DM_CONTRAST_A_reg_addr                                          "0xB802A804"
#define  CON_BRI_DM_CONTRAST_A_reg                                               0xB802A804
#define  CON_BRI_DM_CONTRAST_A_inst_addr                                         "0x0001"
#define  set_CON_BRI_DM_CONTRAST_A_reg(data)                                     (*((volatile unsigned int*)CON_BRI_DM_CONTRAST_A_reg)=data)
#define  get_CON_BRI_DM_CONTRAST_A_reg                                           (*((volatile unsigned int*)CON_BRI_DM_CONTRAST_A_reg))
#define  CON_BRI_DM_CONTRAST_A_m_con_a_r_shift                                   (20)
#define  CON_BRI_DM_CONTRAST_A_m_con_a_g_shift                                   (10)
#define  CON_BRI_DM_CONTRAST_A_m_con_a_b_shift                                   (0)
#define  CON_BRI_DM_CONTRAST_A_m_con_a_r_mask                                    (0x3FF00000)
#define  CON_BRI_DM_CONTRAST_A_m_con_a_g_mask                                    (0x000FFC00)
#define  CON_BRI_DM_CONTRAST_A_m_con_a_b_mask                                    (0x000003FF)
#define  CON_BRI_DM_CONTRAST_A_m_con_a_r(data)                                   (0x3FF00000&((data)<<20))
#define  CON_BRI_DM_CONTRAST_A_m_con_a_g(data)                                   (0x000FFC00&((data)<<10))
#define  CON_BRI_DM_CONTRAST_A_m_con_a_b(data)                                   (0x000003FF&(data))
#define  CON_BRI_DM_CONTRAST_A_get_m_con_a_r(data)                               ((0x3FF00000&(data))>>20)
#define  CON_BRI_DM_CONTRAST_A_get_m_con_a_g(data)                               ((0x000FFC00&(data))>>10)
#define  CON_BRI_DM_CONTRAST_A_get_m_con_a_b(data)                               (0x000003FF&(data))

#define  CON_BRI_DM_Brightness_1                                                 0x1802A808
#define  CON_BRI_DM_Brightness_1_reg_addr                                        "0xB802A808"
#define  CON_BRI_DM_Brightness_1_reg                                             0xB802A808
#define  CON_BRI_DM_Brightness_1_inst_addr                                       "0x0002"
#define  set_CON_BRI_DM_Brightness_1_reg(data)                                   (*((volatile unsigned int*)CON_BRI_DM_Brightness_1_reg)=data)
#define  get_CON_BRI_DM_Brightness_1_reg                                         (*((volatile unsigned int*)CON_BRI_DM_Brightness_1_reg))
#define  CON_BRI_DM_Brightness_1_m_bri1_r_shift                                  (20)
#define  CON_BRI_DM_Brightness_1_m_bri1_g_shift                                  (10)
#define  CON_BRI_DM_Brightness_1_m_bri1_b_shift                                  (0)
#define  CON_BRI_DM_Brightness_1_m_bri1_r_mask                                   (0x3FF00000)
#define  CON_BRI_DM_Brightness_1_m_bri1_g_mask                                   (0x000FFC00)
#define  CON_BRI_DM_Brightness_1_m_bri1_b_mask                                   (0x000003FF)
#define  CON_BRI_DM_Brightness_1_m_bri1_r(data)                                  (0x3FF00000&((data)<<20))
#define  CON_BRI_DM_Brightness_1_m_bri1_g(data)                                  (0x000FFC00&((data)<<10))
#define  CON_BRI_DM_Brightness_1_m_bri1_b(data)                                  (0x000003FF&(data))
#define  CON_BRI_DM_Brightness_1_get_m_bri1_r(data)                              ((0x3FF00000&(data))>>20)
#define  CON_BRI_DM_Brightness_1_get_m_bri1_g(data)                              ((0x000FFC00&(data))>>10)
#define  CON_BRI_DM_Brightness_1_get_m_bri1_b(data)                              (0x000003FF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======CON_BRI register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  blending_main_sub_sel:1;
        RBus_UInt32  res2:3;
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

#else //apply LITTLE_ENDIAN

//======CON_BRI register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m_bri_en:1;
        RBus_UInt32  m_con_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  blending_main_sub_sel:1;
        RBus_UInt32  res2:26;
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




#endif 


#endif 
