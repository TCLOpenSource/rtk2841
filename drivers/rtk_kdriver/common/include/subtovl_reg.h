/**
* @file rbusSubtOvlReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_SUBTOVL_REG_H_
#define _RBUS_SUBTOVL_REG_H_

#include "rbus_types.h"



//  SUBTOVL Register Address
#define  SUBTOVL_Mixer_CTRL1                                                     0x1802BF00
#define  SUBTOVL_Mixer_CTRL1_reg_addr                                            "0xB802BF00"
#define  SUBTOVL_Mixer_CTRL1_reg                                                 0xB802BF00
#define  SUBTOVL_Mixer_CTRL1_inst_addr                                           "0x0000"
#define  set_SUBTOVL_Mixer_CTRL1_reg(data)                                       (*((volatile unsigned int*)SUBTOVL_Mixer_CTRL1_reg)=data)
#define  get_SUBTOVL_Mixer_CTRL1_reg                                             (*((volatile unsigned int*)SUBTOVL_Mixer_CTRL1_reg))
#define  SUBTOVL_Mixer_CTRL1_subt_other_ch_ble_sel_shift                         (16)
#define  SUBTOVL_Mixer_CTRL1_subt_pop_or_subt_mode_shift                         (14)
#define  SUBTOVL_Mixer_CTRL1_subt_dis_color_mapping_shift                        (13)
#define  SUBTOVL_Mixer_CTRL1_subt_dis_conbri_shift                               (12)
#define  SUBTOVL_Mixer_CTRL1_subt_dis_color_temp_shift                           (11)
#define  SUBTOVL_Mixer_CTRL1_subt_dis_srgb_shift                                 (10)
#define  SUBTOVL_Mixer_CTRL1_subt_dis_inv_gamma_shift                            (9)
#define  SUBTOVL_Mixer_CTRL1_subt_dis_gamma_shift                                (8)
#define  SUBTOVL_Mixer_CTRL1_subt_dis_3d_lut_shift                               (7)
#define  SUBTOVL_Mixer_CTRL1_subt_en_as_act_shift                                (6)
#define  SUBTOVL_Mixer_CTRL1_subt_blending_en_shift                              (4)
#define  SUBTOVL_Mixer_CTRL1_subt_chsel_shift                                    (2)
#define  SUBTOVL_Mixer_CTRL1_subt_en_shift                                       (0)
#define  SUBTOVL_Mixer_CTRL1_subt_other_ch_ble_sel_mask                          (0x00010000)
#define  SUBTOVL_Mixer_CTRL1_subt_pop_or_subt_mode_mask                          (0x00004000)
#define  SUBTOVL_Mixer_CTRL1_subt_dis_color_mapping_mask                         (0x00002000)
#define  SUBTOVL_Mixer_CTRL1_subt_dis_conbri_mask                                (0x00001000)
#define  SUBTOVL_Mixer_CTRL1_subt_dis_color_temp_mask                            (0x00000800)
#define  SUBTOVL_Mixer_CTRL1_subt_dis_srgb_mask                                  (0x00000400)
#define  SUBTOVL_Mixer_CTRL1_subt_dis_inv_gamma_mask                             (0x00000200)
#define  SUBTOVL_Mixer_CTRL1_subt_dis_gamma_mask                                 (0x00000100)
#define  SUBTOVL_Mixer_CTRL1_subt_dis_3d_lut_mask                                (0x00000080)
#define  SUBTOVL_Mixer_CTRL1_subt_en_as_act_mask                                 (0x00000040)
#define  SUBTOVL_Mixer_CTRL1_subt_blending_en_mask                               (0x00000010)
#define  SUBTOVL_Mixer_CTRL1_subt_chsel_mask                                     (0x00000004)
#define  SUBTOVL_Mixer_CTRL1_subt_en_mask                                        (0x00000001)
#define  SUBTOVL_Mixer_CTRL1_subt_other_ch_ble_sel(data)                         (0x00010000&((data)<<16))
#define  SUBTOVL_Mixer_CTRL1_subt_pop_or_subt_mode(data)                         (0x00004000&((data)<<14))
#define  SUBTOVL_Mixer_CTRL1_subt_dis_color_mapping(data)                        (0x00002000&((data)<<13))
#define  SUBTOVL_Mixer_CTRL1_subt_dis_conbri(data)                               (0x00001000&((data)<<12))
#define  SUBTOVL_Mixer_CTRL1_subt_dis_color_temp(data)                           (0x00000800&((data)<<11))
#define  SUBTOVL_Mixer_CTRL1_subt_dis_srgb(data)                                 (0x00000400&((data)<<10))
#define  SUBTOVL_Mixer_CTRL1_subt_dis_inv_gamma(data)                            (0x00000200&((data)<<9))
#define  SUBTOVL_Mixer_CTRL1_subt_dis_gamma(data)                                (0x00000100&((data)<<8))
#define  SUBTOVL_Mixer_CTRL1_subt_dis_3d_lut(data)                               (0x00000080&((data)<<7))
#define  SUBTOVL_Mixer_CTRL1_subt_en_as_act(data)                                (0x00000040&((data)<<6))
#define  SUBTOVL_Mixer_CTRL1_subt_blending_en(data)                              (0x00000010&((data)<<4))
#define  SUBTOVL_Mixer_CTRL1_subt_chsel(data)                                    (0x00000004&((data)<<2))
#define  SUBTOVL_Mixer_CTRL1_subt_en(data)                                       (0x00000001&(data))
#define  SUBTOVL_Mixer_CTRL1_get_subt_other_ch_ble_sel(data)                     ((0x00010000&(data))>>16)
#define  SUBTOVL_Mixer_CTRL1_get_subt_pop_or_subt_mode(data)                     ((0x00004000&(data))>>14)
#define  SUBTOVL_Mixer_CTRL1_get_subt_dis_color_mapping(data)                    ((0x00002000&(data))>>13)
#define  SUBTOVL_Mixer_CTRL1_get_subt_dis_conbri(data)                           ((0x00001000&(data))>>12)
#define  SUBTOVL_Mixer_CTRL1_get_subt_dis_color_temp(data)                       ((0x00000800&(data))>>11)
#define  SUBTOVL_Mixer_CTRL1_get_subt_dis_srgb(data)                             ((0x00000400&(data))>>10)
#define  SUBTOVL_Mixer_CTRL1_get_subt_dis_inv_gamma(data)                        ((0x00000200&(data))>>9)
#define  SUBTOVL_Mixer_CTRL1_get_subt_dis_gamma(data)                            ((0x00000100&(data))>>8)
#define  SUBTOVL_Mixer_CTRL1_get_subt_dis_3d_lut(data)                           ((0x00000080&(data))>>7)
#define  SUBTOVL_Mixer_CTRL1_get_subt_en_as_act(data)                            ((0x00000040&(data))>>6)
#define  SUBTOVL_Mixer_CTRL1_get_subt_blending_en(data)                          ((0x00000010&(data))>>4)
#define  SUBTOVL_Mixer_CTRL1_get_subt_chsel(data)                                ((0x00000004&(data))>>2)
#define  SUBTOVL_Mixer_CTRL1_get_subt_en(data)                                   (0x00000001&(data))

#define  SUBTOVL_SubT_CR_X                                                       0x1802BF04
#define  SUBTOVL_SubT_CR_X_reg_addr                                              "0xB802BF04"
#define  SUBTOVL_SubT_CR_X_reg                                                   0xB802BF04
#define  SUBTOVL_SubT_CR_X_inst_addr                                             "0x0001"
#define  set_SUBTOVL_SubT_CR_X_reg(data)                                         (*((volatile unsigned int*)SUBTOVL_SubT_CR_X_reg)=data)
#define  get_SUBTOVL_SubT_CR_X_reg                                               (*((volatile unsigned int*)SUBTOVL_SubT_CR_X_reg))
#define  SUBTOVL_SubT_CR_X_subt_cr_en_shift                                      (28)
#define  SUBTOVL_SubT_CR_X_subt_cr_xend_shift                                    (15)
#define  SUBTOVL_SubT_CR_X_subt_cr_xstart_shift                                  (0)
#define  SUBTOVL_SubT_CR_X_subt_cr_en_mask                                       (0x10000000)
#define  SUBTOVL_SubT_CR_X_subt_cr_xend_mask                                     (0x0FFF8000)
#define  SUBTOVL_SubT_CR_X_subt_cr_xstart_mask                                   (0x00001FFF)
#define  SUBTOVL_SubT_CR_X_subt_cr_en(data)                                      (0x10000000&((data)<<28))
#define  SUBTOVL_SubT_CR_X_subt_cr_xend(data)                                    (0x0FFF8000&((data)<<15))
#define  SUBTOVL_SubT_CR_X_subt_cr_xstart(data)                                  (0x00001FFF&(data))
#define  SUBTOVL_SubT_CR_X_get_subt_cr_en(data)                                  ((0x10000000&(data))>>28)
#define  SUBTOVL_SubT_CR_X_get_subt_cr_xend(data)                                ((0x0FFF8000&(data))>>15)
#define  SUBTOVL_SubT_CR_X_get_subt_cr_xstart(data)                              (0x00001FFF&(data))

#define  SUBTOVL_SubT_CR_Y                                                       0x1802BF08
#define  SUBTOVL_SubT_CR_Y_reg_addr                                              "0xB802BF08"
#define  SUBTOVL_SubT_CR_Y_reg                                                   0xB802BF08
#define  SUBTOVL_SubT_CR_Y_inst_addr                                             "0x0002"
#define  set_SUBTOVL_SubT_CR_Y_reg(data)                                         (*((volatile unsigned int*)SUBTOVL_SubT_CR_Y_reg)=data)
#define  get_SUBTOVL_SubT_CR_Y_reg                                               (*((volatile unsigned int*)SUBTOVL_SubT_CR_Y_reg))
#define  SUBTOVL_SubT_CR_Y_subt_cr_yend_shift                                    (16)
#define  SUBTOVL_SubT_CR_Y_subt_cr_ystart_shift                                  (0)
#define  SUBTOVL_SubT_CR_Y_subt_cr_yend_mask                                     (0x0FFF0000)
#define  SUBTOVL_SubT_CR_Y_subt_cr_ystart_mask                                   (0x00000FFF)
#define  SUBTOVL_SubT_CR_Y_subt_cr_yend(data)                                    (0x0FFF0000&((data)<<16))
#define  SUBTOVL_SubT_CR_Y_subt_cr_ystart(data)                                  (0x00000FFF&(data))
#define  SUBTOVL_SubT_CR_Y_get_subt_cr_yend(data)                                ((0x0FFF0000&(data))>>16)
#define  SUBTOVL_SubT_CR_Y_get_subt_cr_ystart(data)                              (0x00000FFF&(data))

#define  SUBTOVL_SubT_CRC_Ctrl                                                   0x1802BF10
#define  SUBTOVL_SubT_CRC_Ctrl_reg_addr                                          "0xB802BF10"
#define  SUBTOVL_SubT_CRC_Ctrl_reg                                               0xB802BF10
#define  SUBTOVL_SubT_CRC_Ctrl_inst_addr                                         "0x0003"
#define  set_SUBTOVL_SubT_CRC_Ctrl_reg(data)                                     (*((volatile unsigned int*)SUBTOVL_SubT_CRC_Ctrl_reg)=data)
#define  get_SUBTOVL_SubT_CRC_Ctrl_reg                                           (*((volatile unsigned int*)SUBTOVL_SubT_CRC_Ctrl_reg))
#define  SUBTOVL_SubT_CRC_Ctrl_subt_crc_done_shift                               (2)
#define  SUBTOVL_SubT_CRC_Ctrl_subt_crc_cont_shift                               (1)
#define  SUBTOVL_SubT_CRC_Ctrl_subt_crc_start_shift                              (0)
#define  SUBTOVL_SubT_CRC_Ctrl_subt_crc_done_mask                                (0x00000004)
#define  SUBTOVL_SubT_CRC_Ctrl_subt_crc_cont_mask                                (0x00000002)
#define  SUBTOVL_SubT_CRC_Ctrl_subt_crc_start_mask                               (0x00000001)
#define  SUBTOVL_SubT_CRC_Ctrl_subt_crc_done(data)                               (0x00000004&((data)<<2))
#define  SUBTOVL_SubT_CRC_Ctrl_subt_crc_cont(data)                               (0x00000002&((data)<<1))
#define  SUBTOVL_SubT_CRC_Ctrl_subt_crc_start(data)                              (0x00000001&(data))
#define  SUBTOVL_SubT_CRC_Ctrl_get_subt_crc_done(data)                           ((0x00000004&(data))>>2)
#define  SUBTOVL_SubT_CRC_Ctrl_get_subt_crc_cont(data)                           ((0x00000002&(data))>>1)
#define  SUBTOVL_SubT_CRC_Ctrl_get_subt_crc_start(data)                          (0x00000001&(data))

#define  SUBTOVL_SubT_CRC_Result                                                 0x1802BF14
#define  SUBTOVL_SubT_CRC_Result_reg_addr                                        "0xB802BF14"
#define  SUBTOVL_SubT_CRC_Result_reg                                             0xB802BF14
#define  SUBTOVL_SubT_CRC_Result_inst_addr                                       "0x0004"
#define  set_SUBTOVL_SubT_CRC_Result_reg(data)                                   (*((volatile unsigned int*)SUBTOVL_SubT_CRC_Result_reg)=data)
#define  get_SUBTOVL_SubT_CRC_Result_reg                                         (*((volatile unsigned int*)SUBTOVL_SubT_CRC_Result_reg))
#define  SUBTOVL_SubT_CRC_Result_subt_crc_result_shift                           (0)
#define  SUBTOVL_SubT_CRC_Result_subt_crc_result_mask                            (0xFFFFFFFF)
#define  SUBTOVL_SubT_CRC_Result_subt_crc_result(data)                           (0xFFFFFFFF&(data))
#define  SUBTOVL_SubT_CRC_Result_get_subt_crc_result(data)                       (0xFFFFFFFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======SUBTOVL register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  subt_other_ch_ble_sel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  subt_pop_or_subt_mode:1;
        RBus_UInt32  subt_dis_color_mapping:1;
        RBus_UInt32  subt_dis_conbri:1;
        RBus_UInt32  subt_dis_color_temp:1;
        RBus_UInt32  subt_dis_srgb:1;
        RBus_UInt32  subt_dis_inv_gamma:1;
        RBus_UInt32  subt_dis_gamma:1;
        RBus_UInt32  subt_dis_3d_lut:1;
        RBus_UInt32  subt_en_as_act:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  subt_blending_en:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  subt_chsel:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  subt_en:1;
    };
}subtovl_mixer_ctrl1_RBUS;

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
}subtovl_subt_cr_x_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  subt_cr_yend:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  subt_cr_ystart:12;
    };
}subtovl_subt_cr_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  subt_crc_done:1;
        RBus_UInt32  subt_crc_cont:1;
        RBus_UInt32  subt_crc_start:1;
    };
}subtovl_subt_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  subt_crc_result:32;
    };
}subtovl_subt_crc_result_RBUS;

#else //apply LITTLE_ENDIAN

//======SUBTOVL register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  subt_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  subt_chsel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  subt_blending_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  subt_en_as_act:1;
        RBus_UInt32  subt_dis_3d_lut:1;
        RBus_UInt32  subt_dis_gamma:1;
        RBus_UInt32  subt_dis_inv_gamma:1;
        RBus_UInt32  subt_dis_srgb:1;
        RBus_UInt32  subt_dis_color_temp:1;
        RBus_UInt32  subt_dis_conbri:1;
        RBus_UInt32  subt_dis_color_mapping:1;
        RBus_UInt32  subt_pop_or_subt_mode:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  subt_other_ch_ble_sel:1;
        RBus_UInt32  res5:15;
    };
}subtovl_mixer_ctrl1_RBUS;

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
}subtovl_subt_cr_x_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  subt_cr_ystart:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  subt_cr_yend:12;
        RBus_UInt32  res2:4;
    };
}subtovl_subt_cr_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  subt_crc_start:1;
        RBus_UInt32  subt_crc_cont:1;
        RBus_UInt32  subt_crc_done:1;
        RBus_UInt32  res1:29;
    };
}subtovl_subt_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  subt_crc_result:32;
    };
}subtovl_subt_crc_result_RBUS;




#endif 


#endif 
