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

#ifndef _VGIP_PTG_REG_H_INCLUDED_
#define _VGIP_PTG_REG_H_INCLUDED_

//#define _VGIP_PTG_USE_STRUCT
#ifdef _VGIP_PTG_USE_STRUCT

typedef struct
{
        unsigned int  reserved_0:9;
        unsigned int  color_bar_mode_en:1;
        unsigned int  reserved_1:15;
        unsigned int  mask_one_eye_en:1;
        unsigned int  mask_one_eye_left:1;
        unsigned int  color_bar_vertical_mode:1;
        unsigned int  color_bar_interlaced_mode:1;
        unsigned int  color_bar_3d_mode:1;
        unsigned int  color_num:2;
}PTG_CTRL;

typedef struct
{
        unsigned int  reserved_0:8;
        unsigned int  i_c0y_92b:8;
        unsigned int  i_c0cr_92b:8;
        unsigned int  i_c0cb_92b:8;
}PTG_C0Y_Cb_Cr;

typedef struct
{
        unsigned int  reserved_0:8;
        unsigned int  i_c1y_92b:8;
        unsigned int  i_c1cr_92b:8;
        unsigned int  i_c1cb_92b:8;
}PTG_C1Y_Cb_Cr;

typedef struct
{
        unsigned int  reserved_0:8;
        unsigned int  i_c2y_92b:8;
        unsigned int  i_c2cr_92b:8;
        unsigned int  i_c2cb_92b:8;
}PTG_C2Y_Cb_Cr;

typedef struct
{
        unsigned int  reserved_0:8;
        unsigned int  i_c3y_92b:8;
        unsigned int  i_c3cr_92b:8;
        unsigned int  i_c3cb_92b:8;
}PTG_C3Y_Cb_Cr;

typedef struct
{
        unsigned int  reserved_0:8;
        unsigned int  i_c4y_92b:8;
        unsigned int  i_c4cr_92b:8;
        unsigned int  i_c4cb_92b:8;
}PTG_C4Y_Cb_Cr;

typedef struct
{
        unsigned int  reserved_0:8;
        unsigned int  i_c5y_92b:8;
        unsigned int  i_c5cr_92b:8;
        unsigned int  i_c5cb_92b:8;
}PTG_C5Y_Cr_Cb;

typedef struct
{
        unsigned int  reserved_0:8;
        unsigned int  i_c6y_92b:8;
        unsigned int  i_c6cr_92b:8;
        unsigned int  i_c6cb_92b:8;
}PTG_C6Y_Cb_Cr;

typedef struct
{
        unsigned int  reserved_0:8;
        unsigned int  i_c7y_92b:8;
        unsigned int  i_c7cr_92b:8;
        unsigned int  i_c7cb_92b:8;
}PTG_C7Y_Cb_Cr;

typedef struct
{
        unsigned int  reserved_0:20;
        unsigned int  vodma_irq_record:1;
        unsigned int  adc_irq_record:1;
        unsigned int  sync_auto_2_irq_record:1;
        unsigned int  sync_auto_1_irq_record:1;
        unsigned int  sync_processor_irq_record:1;
        unsigned int  hist_irq_record:1;
        unsigned int  vgip_irq_record:1;
        unsigned int  offms_irq_record:1;
        unsigned int  onms_2_irq_record:1;
        unsigned int  onms_1_irq_record:1;
        unsigned int  i3ddma_irq_record:1;
        unsigned int  ccdinr_irq_record:1;
}DISPI_IRQ_RECORD;

#define  PTG_CTRL                                                               0x180222C0
#define  PTG_CTRL_reg_addr                                                      "0xB80222C0"
#define  PTG_CTRL_reg                                                           0xB80222C0
#define  PTG_CTRL_inst_addr                                                     "0x0000"
#define  PTG_CTRL_inst                                                          0x0000
#define  PTG_CTRL_color_bar_mode_en_shift                                       (22)
#define  PTG_CTRL_mask_one_eye_en_shift                                         (6)
#define  PTG_CTRL_mask_one_eye_left_shift                                       (5)
#define  PTG_CTRL_color_bar_vertical_mode_shift                                 (4)
#define  PTG_CTRL_color_bar_interlaced_mode_shift                               (3)
#define  PTG_CTRL_color_bar_3d_mode_shift                                       (2)
#define  PTG_CTRL_color_num_shift                                               (0)
#define  PTG_CTRL_color_bar_mode_en_mask                                        (0x00400000)
#define  PTG_CTRL_mask_one_eye_en_mask                                          (0x00000040)
#define  PTG_CTRL_mask_one_eye_left_mask                                        (0x00000020)
#define  PTG_CTRL_color_bar_vertical_mode_mask                                  (0x00000010)
#define  PTG_CTRL_color_bar_interlaced_mode_mask                                (0x00000008)
#define  PTG_CTRL_color_bar_3d_mode_mask                                        (0x00000004)
#define  PTG_CTRL_color_num_mask                                                (0x00000003)
#define  PTG_CTRL_color_bar_mode_en(data)                                       (0x00400000&((data)<<22))
#define  PTG_CTRL_mask_one_eye_en(data)                                         (0x00000040&((data)<<6))
#define  PTG_CTRL_mask_one_eye_left(data)                                       (0x00000020&((data)<<5))
#define  PTG_CTRL_color_bar_vertical_mode(data)                                 (0x00000010&((data)<<4))
#define  PTG_CTRL_color_bar_interlaced_mode(data)                               (0x00000008&((data)<<3))
#define  PTG_CTRL_color_bar_3d_mode(data)                                       (0x00000004&((data)<<2))
#define  PTG_CTRL_color_num(data)                                               (0x00000003&(data))
#define  PTG_CTRL_get_color_bar_mode_en(data)                                   ((0x00400000&(data))>>22)
#define  PTG_CTRL_get_mask_one_eye_en(data)                                     ((0x00000040&(data))>>6)
#define  PTG_CTRL_get_mask_one_eye_left(data)                                   ((0x00000020&(data))>>5)
#define  PTG_CTRL_get_color_bar_vertical_mode(data)                             ((0x00000010&(data))>>4)
#define  PTG_CTRL_get_color_bar_interlaced_mode(data)                           ((0x00000008&(data))>>3)
#define  PTG_CTRL_get_color_bar_3d_mode(data)                                   ((0x00000004&(data))>>2)
#define  PTG_CTRL_get_color_num(data)                                           (0x00000003&(data))

#define  PTG_C0Y_Cb_Cr                                                          0x180222C4
#define  PTG_C0Y_Cb_Cr_reg_addr                                                 "0xB80222C4"
#define  PTG_C0Y_Cb_Cr_reg                                                      0xB80222C4
#define  PTG_C0Y_Cb_Cr_inst_addr                                                "0x0001"
#define  PTG_C0Y_Cb_Cr_inst                                                     0x0001
#define  PTG_C0Y_Cb_Cr_i_c0y_92b_shift                                          (16)
#define  PTG_C0Y_Cb_Cr_i_c0cr_92b_shift                                         (8)
#define  PTG_C0Y_Cb_Cr_i_c0cb_92b_shift                                         (0)
#define  PTG_C0Y_Cb_Cr_i_c0y_92b_mask                                           (0x00FF0000)
#define  PTG_C0Y_Cb_Cr_i_c0cr_92b_mask                                          (0x0000FF00)
#define  PTG_C0Y_Cb_Cr_i_c0cb_92b_mask                                          (0x000000FF)
#define  PTG_C0Y_Cb_Cr_i_c0y_92b(data)                                          (0x00FF0000&((data)<<16))
#define  PTG_C0Y_Cb_Cr_i_c0cr_92b(data)                                         (0x0000FF00&((data)<<8))
#define  PTG_C0Y_Cb_Cr_i_c0cb_92b(data)                                         (0x000000FF&(data))
#define  PTG_C0Y_Cb_Cr_get_i_c0y_92b(data)                                      ((0x00FF0000&(data))>>16)
#define  PTG_C0Y_Cb_Cr_get_i_c0cr_92b(data)                                     ((0x0000FF00&(data))>>8)
#define  PTG_C0Y_Cb_Cr_get_i_c0cb_92b(data)                                     (0x000000FF&(data))

#define  PTG_C1Y_Cb_Cr                                                          0x180222C8
#define  PTG_C1Y_Cb_Cr_reg_addr                                                 "0xB80222C8"
#define  PTG_C1Y_Cb_Cr_reg                                                      0xB80222C8
#define  PTG_C1Y_Cb_Cr_inst_addr                                                "0x0002"
#define  PTG_C1Y_Cb_Cr_inst                                                     0x0002
#define  PTG_C1Y_Cb_Cr_i_c1y_92b_shift                                          (16)
#define  PTG_C1Y_Cb_Cr_i_c1cr_92b_shift                                         (8)
#define  PTG_C1Y_Cb_Cr_i_c1cb_92b_shift                                         (0)
#define  PTG_C1Y_Cb_Cr_i_c1y_92b_mask                                           (0x00FF0000)
#define  PTG_C1Y_Cb_Cr_i_c1cr_92b_mask                                          (0x0000FF00)
#define  PTG_C1Y_Cb_Cr_i_c1cb_92b_mask                                          (0x000000FF)
#define  PTG_C1Y_Cb_Cr_i_c1y_92b(data)                                          (0x00FF0000&((data)<<16))
#define  PTG_C1Y_Cb_Cr_i_c1cr_92b(data)                                         (0x0000FF00&((data)<<8))
#define  PTG_C1Y_Cb_Cr_i_c1cb_92b(data)                                         (0x000000FF&(data))
#define  PTG_C1Y_Cb_Cr_get_i_c1y_92b(data)                                      ((0x00FF0000&(data))>>16)
#define  PTG_C1Y_Cb_Cr_get_i_c1cr_92b(data)                                     ((0x0000FF00&(data))>>8)
#define  PTG_C1Y_Cb_Cr_get_i_c1cb_92b(data)                                     (0x000000FF&(data))

#define  PTG_C2Y_Cb_Cr                                                          0x180222CC
#define  PTG_C2Y_Cb_Cr_reg_addr                                                 "0xB80222CC"
#define  PTG_C2Y_Cb_Cr_reg                                                      0xB80222CC
#define  PTG_C2Y_Cb_Cr_inst_addr                                                "0x0003"
#define  PTG_C2Y_Cb_Cr_inst                                                     0x0003
#define  PTG_C2Y_Cb_Cr_i_c2y_92b_shift                                          (16)
#define  PTG_C2Y_Cb_Cr_i_c2cr_92b_shift                                         (8)
#define  PTG_C2Y_Cb_Cr_i_c2cb_92b_shift                                         (0)
#define  PTG_C2Y_Cb_Cr_i_c2y_92b_mask                                           (0x00FF0000)
#define  PTG_C2Y_Cb_Cr_i_c2cr_92b_mask                                          (0x0000FF00)
#define  PTG_C2Y_Cb_Cr_i_c2cb_92b_mask                                          (0x000000FF)
#define  PTG_C2Y_Cb_Cr_i_c2y_92b(data)                                          (0x00FF0000&((data)<<16))
#define  PTG_C2Y_Cb_Cr_i_c2cr_92b(data)                                         (0x0000FF00&((data)<<8))
#define  PTG_C2Y_Cb_Cr_i_c2cb_92b(data)                                         (0x000000FF&(data))
#define  PTG_C2Y_Cb_Cr_get_i_c2y_92b(data)                                      ((0x00FF0000&(data))>>16)
#define  PTG_C2Y_Cb_Cr_get_i_c2cr_92b(data)                                     ((0x0000FF00&(data))>>8)
#define  PTG_C2Y_Cb_Cr_get_i_c2cb_92b(data)                                     (0x000000FF&(data))

#define  PTG_C3Y_Cb_Cr                                                          0x180222D0
#define  PTG_C3Y_Cb_Cr_reg_addr                                                 "0xB80222D0"
#define  PTG_C3Y_Cb_Cr_reg                                                      0xB80222D0
#define  PTG_C3Y_Cb_Cr_inst_addr                                                "0x0004"
#define  PTG_C3Y_Cb_Cr_inst                                                     0x0004
#define  PTG_C3Y_Cb_Cr_i_c3y_92b_shift                                          (16)
#define  PTG_C3Y_Cb_Cr_i_c3cr_92b_shift                                         (8)
#define  PTG_C3Y_Cb_Cr_i_c3cb_92b_shift                                         (0)
#define  PTG_C3Y_Cb_Cr_i_c3y_92b_mask                                           (0x00FF0000)
#define  PTG_C3Y_Cb_Cr_i_c3cr_92b_mask                                          (0x0000FF00)
#define  PTG_C3Y_Cb_Cr_i_c3cb_92b_mask                                          (0x000000FF)
#define  PTG_C3Y_Cb_Cr_i_c3y_92b(data)                                          (0x00FF0000&((data)<<16))
#define  PTG_C3Y_Cb_Cr_i_c3cr_92b(data)                                         (0x0000FF00&((data)<<8))
#define  PTG_C3Y_Cb_Cr_i_c3cb_92b(data)                                         (0x000000FF&(data))
#define  PTG_C3Y_Cb_Cr_get_i_c3y_92b(data)                                      ((0x00FF0000&(data))>>16)
#define  PTG_C3Y_Cb_Cr_get_i_c3cr_92b(data)                                     ((0x0000FF00&(data))>>8)
#define  PTG_C3Y_Cb_Cr_get_i_c3cb_92b(data)                                     (0x000000FF&(data))

#define  PTG_C4Y_Cb_Cr                                                          0x180222D4
#define  PTG_C4Y_Cb_Cr_reg_addr                                                 "0xB80222D4"
#define  PTG_C4Y_Cb_Cr_reg                                                      0xB80222D4
#define  PTG_C4Y_Cb_Cr_inst_addr                                                "0x0005"
#define  PTG_C4Y_Cb_Cr_inst                                                     0x0005
#define  PTG_C4Y_Cb_Cr_i_c4y_92b_shift                                          (16)
#define  PTG_C4Y_Cb_Cr_i_c4cr_92b_shift                                         (8)
#define  PTG_C4Y_Cb_Cr_i_c4cb_92b_shift                                         (0)
#define  PTG_C4Y_Cb_Cr_i_c4y_92b_mask                                           (0x00FF0000)
#define  PTG_C4Y_Cb_Cr_i_c4cr_92b_mask                                          (0x0000FF00)
#define  PTG_C4Y_Cb_Cr_i_c4cb_92b_mask                                          (0x000000FF)
#define  PTG_C4Y_Cb_Cr_i_c4y_92b(data)                                          (0x00FF0000&((data)<<16))
#define  PTG_C4Y_Cb_Cr_i_c4cr_92b(data)                                         (0x0000FF00&((data)<<8))
#define  PTG_C4Y_Cb_Cr_i_c4cb_92b(data)                                         (0x000000FF&(data))
#define  PTG_C4Y_Cb_Cr_get_i_c4y_92b(data)                                      ((0x00FF0000&(data))>>16)
#define  PTG_C4Y_Cb_Cr_get_i_c4cr_92b(data)                                     ((0x0000FF00&(data))>>8)
#define  PTG_C4Y_Cb_Cr_get_i_c4cb_92b(data)                                     (0x000000FF&(data))

#define  PTG_C5Y_Cr_Cb                                                          0x180222D8
#define  PTG_C5Y_Cr_Cb_reg_addr                                                 "0xB80222D8"
#define  PTG_C5Y_Cr_Cb_reg                                                      0xB80222D8
#define  PTG_C5Y_Cr_Cb_inst_addr                                                "0x0006"
#define  PTG_C5Y_Cr_Cb_inst                                                     0x0006
#define  PTG_C5Y_Cr_Cb_i_c5y_92b_shift                                          (16)
#define  PTG_C5Y_Cr_Cb_i_c5cr_92b_shift                                         (8)
#define  PTG_C5Y_Cr_Cb_i_c5cb_92b_shift                                         (0)
#define  PTG_C5Y_Cr_Cb_i_c5y_92b_mask                                           (0x00FF0000)
#define  PTG_C5Y_Cr_Cb_i_c5cr_92b_mask                                          (0x0000FF00)
#define  PTG_C5Y_Cr_Cb_i_c5cb_92b_mask                                          (0x000000FF)
#define  PTG_C5Y_Cr_Cb_i_c5y_92b(data)                                          (0x00FF0000&((data)<<16))
#define  PTG_C5Y_Cr_Cb_i_c5cr_92b(data)                                         (0x0000FF00&((data)<<8))
#define  PTG_C5Y_Cr_Cb_i_c5cb_92b(data)                                         (0x000000FF&(data))
#define  PTG_C5Y_Cr_Cb_get_i_c5y_92b(data)                                      ((0x00FF0000&(data))>>16)
#define  PTG_C5Y_Cr_Cb_get_i_c5cr_92b(data)                                     ((0x0000FF00&(data))>>8)
#define  PTG_C5Y_Cr_Cb_get_i_c5cb_92b(data)                                     (0x000000FF&(data))

#define  PTG_C6Y_Cb_Cr                                                          0x180222DC
#define  PTG_C6Y_Cb_Cr_reg_addr                                                 "0xB80222DC"
#define  PTG_C6Y_Cb_Cr_reg                                                      0xB80222DC
#define  PTG_C6Y_Cb_Cr_inst_addr                                                "0x0007"
#define  PTG_C6Y_Cb_Cr_inst                                                     0x0007
#define  PTG_C6Y_Cb_Cr_i_c6y_92b_shift                                          (16)
#define  PTG_C6Y_Cb_Cr_i_c6cr_92b_shift                                         (8)
#define  PTG_C6Y_Cb_Cr_i_c6cb_92b_shift                                         (0)
#define  PTG_C6Y_Cb_Cr_i_c6y_92b_mask                                           (0x00FF0000)
#define  PTG_C6Y_Cb_Cr_i_c6cr_92b_mask                                          (0x0000FF00)
#define  PTG_C6Y_Cb_Cr_i_c6cb_92b_mask                                          (0x000000FF)
#define  PTG_C6Y_Cb_Cr_i_c6y_92b(data)                                          (0x00FF0000&((data)<<16))
#define  PTG_C6Y_Cb_Cr_i_c6cr_92b(data)                                         (0x0000FF00&((data)<<8))
#define  PTG_C6Y_Cb_Cr_i_c6cb_92b(data)                                         (0x000000FF&(data))
#define  PTG_C6Y_Cb_Cr_get_i_c6y_92b(data)                                      ((0x00FF0000&(data))>>16)
#define  PTG_C6Y_Cb_Cr_get_i_c6cr_92b(data)                                     ((0x0000FF00&(data))>>8)
#define  PTG_C6Y_Cb_Cr_get_i_c6cb_92b(data)                                     (0x000000FF&(data))

#define  PTG_C7Y_Cb_Cr                                                          0x180222E0
#define  PTG_C7Y_Cb_Cr_reg_addr                                                 "0xB80222E0"
#define  PTG_C7Y_Cb_Cr_reg                                                      0xB80222E0
#define  PTG_C7Y_Cb_Cr_inst_addr                                                "0x0008"
#define  PTG_C7Y_Cb_Cr_inst                                                     0x0008
#define  PTG_C7Y_Cb_Cr_i_c7y_92b_shift                                          (16)
#define  PTG_C7Y_Cb_Cr_i_c7cr_92b_shift                                         (8)
#define  PTG_C7Y_Cb_Cr_i_c7cb_92b_shift                                         (0)
#define  PTG_C7Y_Cb_Cr_i_c7y_92b_mask                                           (0x00FF0000)
#define  PTG_C7Y_Cb_Cr_i_c7cr_92b_mask                                          (0x0000FF00)
#define  PTG_C7Y_Cb_Cr_i_c7cb_92b_mask                                          (0x000000FF)
#define  PTG_C7Y_Cb_Cr_i_c7y_92b(data)                                          (0x00FF0000&((data)<<16))
#define  PTG_C7Y_Cb_Cr_i_c7cr_92b(data)                                         (0x0000FF00&((data)<<8))
#define  PTG_C7Y_Cb_Cr_i_c7cb_92b(data)                                         (0x000000FF&(data))
#define  PTG_C7Y_Cb_Cr_get_i_c7y_92b(data)                                      ((0x00FF0000&(data))>>16)
#define  PTG_C7Y_Cb_Cr_get_i_c7cr_92b(data)                                     ((0x0000FF00&(data))>>8)
#define  PTG_C7Y_Cb_Cr_get_i_c7cb_92b(data)                                     (0x000000FF&(data))

#define  DISPI_IRQ_RECORD                                                       0x180222F0
#define  DISPI_IRQ_RECORD_reg_addr                                              "0xB80222F0"
#define  DISPI_IRQ_RECORD_reg                                                   0xB80222F0
#define  DISPI_IRQ_RECORD_inst_addr                                             "0x0009"
#define  DISPI_IRQ_RECORD_inst                                                  0x0009
#define  DISPI_IRQ_RECORD_vodma_irq_record_shift                                (11)
#define  DISPI_IRQ_RECORD_adc_irq_record_shift                                  (10)
#define  DISPI_IRQ_RECORD_sync_auto_2_irq_record_shift                          (9)
#define  DISPI_IRQ_RECORD_sync_auto_1_irq_record_shift                          (8)
#define  DISPI_IRQ_RECORD_sync_processor_irq_record_shift                       (7)
#define  DISPI_IRQ_RECORD_hist_irq_record_shift                                 (6)
#define  DISPI_IRQ_RECORD_vgip_irq_record_shift                                 (5)
#define  DISPI_IRQ_RECORD_offms_irq_record_shift                                (4)
#define  DISPI_IRQ_RECORD_onms_2_irq_record_shift                               (3)
#define  DISPI_IRQ_RECORD_onms_1_irq_record_shift                               (2)
#define  DISPI_IRQ_RECORD_i3ddma_irq_record_shift                               (1)
#define  DISPI_IRQ_RECORD_ccdinr_irq_record_shift                               (0)
#define  DISPI_IRQ_RECORD_vodma_irq_record_mask                                 (0x00000800)
#define  DISPI_IRQ_RECORD_adc_irq_record_mask                                   (0x00000400)
#define  DISPI_IRQ_RECORD_sync_auto_2_irq_record_mask                           (0x00000200)
#define  DISPI_IRQ_RECORD_sync_auto_1_irq_record_mask                           (0x00000100)
#define  DISPI_IRQ_RECORD_sync_processor_irq_record_mask                        (0x00000080)
#define  DISPI_IRQ_RECORD_hist_irq_record_mask                                  (0x00000040)
#define  DISPI_IRQ_RECORD_vgip_irq_record_mask                                  (0x00000020)
#define  DISPI_IRQ_RECORD_offms_irq_record_mask                                 (0x00000010)
#define  DISPI_IRQ_RECORD_onms_2_irq_record_mask                                (0x00000008)
#define  DISPI_IRQ_RECORD_onms_1_irq_record_mask                                (0x00000004)
#define  DISPI_IRQ_RECORD_i3ddma_irq_record_mask                                (0x00000002)
#define  DISPI_IRQ_RECORD_ccdinr_irq_record_mask                                (0x00000001)
#define  DISPI_IRQ_RECORD_vodma_irq_record(data)                                (0x00000800&((data)<<11))
#define  DISPI_IRQ_RECORD_adc_irq_record(data)                                  (0x00000400&((data)<<10))
#define  DISPI_IRQ_RECORD_sync_auto_2_irq_record(data)                          (0x00000200&((data)<<9))
#define  DISPI_IRQ_RECORD_sync_auto_1_irq_record(data)                          (0x00000100&((data)<<8))
#define  DISPI_IRQ_RECORD_sync_processor_irq_record(data)                       (0x00000080&((data)<<7))
#define  DISPI_IRQ_RECORD_hist_irq_record(data)                                 (0x00000040&((data)<<6))
#define  DISPI_IRQ_RECORD_vgip_irq_record(data)                                 (0x00000020&((data)<<5))
#define  DISPI_IRQ_RECORD_offms_irq_record(data)                                (0x00000010&((data)<<4))
#define  DISPI_IRQ_RECORD_onms_2_irq_record(data)                               (0x00000008&((data)<<3))
#define  DISPI_IRQ_RECORD_onms_1_irq_record(data)                               (0x00000004&((data)<<2))
#define  DISPI_IRQ_RECORD_i3ddma_irq_record(data)                               (0x00000002&((data)<<1))
#define  DISPI_IRQ_RECORD_ccdinr_irq_record(data)                               (0x00000001&(data))
#define  DISPI_IRQ_RECORD_get_vodma_irq_record(data)                            ((0x00000800&(data))>>11)
#define  DISPI_IRQ_RECORD_get_adc_irq_record(data)                              ((0x00000400&(data))>>10)
#define  DISPI_IRQ_RECORD_get_sync_auto_2_irq_record(data)                      ((0x00000200&(data))>>9)
#define  DISPI_IRQ_RECORD_get_sync_auto_1_irq_record(data)                      ((0x00000100&(data))>>8)
#define  DISPI_IRQ_RECORD_get_sync_processor_irq_record(data)                   ((0x00000080&(data))>>7)
#define  DISPI_IRQ_RECORD_get_hist_irq_record(data)                             ((0x00000040&(data))>>6)
#define  DISPI_IRQ_RECORD_get_vgip_irq_record(data)                             ((0x00000020&(data))>>5)
#define  DISPI_IRQ_RECORD_get_offms_irq_record(data)                            ((0x00000010&(data))>>4)
#define  DISPI_IRQ_RECORD_get_onms_2_irq_record(data)                           ((0x00000008&(data))>>3)
#define  DISPI_IRQ_RECORD_get_onms_1_irq_record(data)                           ((0x00000004&(data))>>2)
#define  DISPI_IRQ_RECORD_get_i3ddma_irq_record(data)                           ((0x00000002&(data))>>1)
#define  DISPI_IRQ_RECORD_get_ccdinr_irq_record(data)                           (0x00000001&(data))

#endif 
