
/*=============================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2009
  * All rights reserved.
  * ============================================ */

/*================= File Description ================= */
/**
 * @file
 * 	This file is for the main function and some initial functions.
 *
 * @author 	$Author: Jennifer $
 * @date 	$Date: 2015/06/09 08:22 $
 * @version 	$Revision: 0.1 $
 * @ingroup 	VIDEO_DECODER
 */

/**
 * @addtogroup vdc
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif
#include <tvscalercontrol/vdc/video.h>

#ifdef scart_vdc_auto_balance_en
#define scart_rgb_max_target_level 597//640//600//597//564//(940/(1.7))
#define scart_rgb_min_target_level 4
#define scart_yuv_max_target_level_y_black 64
#define scart_yuv_max_target_level_y (1022 - scart_yuv_max_target_level_y_black)//940
#define scart_yuv_max_target_level_u 809
#define scart_yuv_max_target_level_v 887
#define SELECT_BLACK 0x8
#endif

typedef enum VDC_CLAMP_TYPE {
	CLAMP_CVBS = 0,
	CLAMP_IFD = 1,
} VDC_CLAMP_TYPE;

extern unsigned char ucVin;
extern unsigned char ucVgnd;

void module_vdc_ADC_common_setting(void);
unsigned char module_vdc_SetADCPath(unsigned char path_signal, unsigned char path_gnd);
unsigned char module_vdc_SetRGBADCPath(unsigned char path_signal, unsigned char path_gnd);
void module_vdc_ClampType_set(unsigned char ClampTpye, unsigned char ClampADC);
void module_vdc_SetInput_Y(unsigned char Y_path, unsigned char Y_Gnd_path);
void module_vdc_SetInput_YC(unsigned char Y_path, unsigned char Y_Gnd_path, unsigned char C_path, unsigned char C_Gnd_path, unsigned char SV_Type);
#ifdef CONFIG_SCART_ENABLE
void module_vdc_SetInput_YRGB(unsigned char Y_path, unsigned char B_path, unsigned char G_path, unsigned char R_path, unsigned char YRGB_Gnd_path);
#endif
void drvif_module_vdc_AVoutEnable(VDC_VIDEO_AVOUT_ENABLE on_off);
void drvif_module_vdc_AVout_Delay(unsigned short value);
unsigned short drvif_module_vdc_read_AVout_Delay(void);
void drvif_module_vdc_AVout_Hsync_Only(void);
void drvif_module_vdc_AVout_Normal(void);
void module_vdc_clamp_type(VDC_CLAMP_TYPE ucClamp);
void module_vdc_PathSelect(unsigned char ucSourceIndex, void* stPath);
#ifdef scart_vdc_auto_balance_en
unsigned char drvif_vdc_scart_adc_autobalance_standard(unsigned char display);
unsigned short drvif_module_color_scart_adjustment_yuv(unsigned char display);
unsigned char drvif_scart_auto_tuneBrSat(unsigned char display, unsigned char ucColor, unsigned short *pMargin, unsigned short ucMax_Target, unsigned short *pPosition);
unsigned char drvif_auto_measure_YUV(unsigned char color, unsigned short* rev, unsigned short* pPosition);
static unsigned char scart_auto_vdBrSatchange(unsigned char display, unsigned char color, unsigned short delta, unsigned char inc);
static unsigned char scart_auto_vdBrSatAdjust(unsigned char color, unsigned short delta, unsigned char inc, unsigned char saturate, unsigned short *BrSat);
#ifndef ENABLE_NET_NEWFUNC
extern void drvif_color_write_smartfit_dragon(unsigned short Hstart, unsigned short Hend, unsigned short Vstart, unsigned short Vend, unsigned char Ch);
#endif
#endif

#ifdef __cplusplus
}
#endif
