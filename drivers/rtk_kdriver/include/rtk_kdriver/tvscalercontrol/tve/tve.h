
/*=============================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2005
  * All rights reserved.
  * ============================================ */

/*================= File Description ================= */
/**
 * @file
 * 	This file is for the main function and some initial functions.
 *
 * @author 	$Author: sky $
 * @date 	$Date: 2013/06/05 03:26 $
 * @version 	$Revision: 0.1 $
 * @ingroup 	tve
 */

/**
 * @addtogroup tve
 * @{
 */
#ifndef __TVE_H__
#define __TVE_H__

#ifdef __cplusplus
extern "C" {
#endif

/*================ Module dependency  =============== */
//#include "tvscalercontrol/scaler/source.h"
#include "tvscalercontrol/vdac/vdac.h"


/*==================== Definitions ================ */
// TVE Register Address

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

typedef struct {
	unsigned char VPS_RUN_IN_BYTE;
	unsigned char VPS_START_CODE;
	unsigned char VPS_BYTE_2;
	unsigned char VPS_BYTE_3;
	unsigned char VPS_BYTE_4;
	unsigned char VPS_BYTE_5;
	unsigned char VPS_BYTE_6;
	unsigned char VPS_BYTE_7;
	unsigned char VPS_BYTE_8;
	unsigned char VPS_BYTE_9;
	unsigned char VPS_BYTE_10;
	unsigned char VPS_BYTE_11;
	unsigned char VPS_BYTE_12;
	unsigned char VPS_BYTE_13;
	unsigned char VPS_BYTE_14;
} Struct_TVE_VPS_DATA;




typedef enum TVE_VIDEO_MODE_SEL{
	  TVE_NTSC= 0,
		TVE_NTSC_J,
		TVE_NTSC_443,
		TVE_PAL_I,
		TVE_PAL_M,
		TVE_PAL_60,
		TVE_PAL_N,
}TVE_VIDEO_MODE_SEL;

typedef enum TVE_CLOCK{
	TVE_CLOCK_DISABLE=0,
	TVE_CLOCK_ENABLE,
}TVE_CLOCK;

typedef enum TVE_AVOUT_EN{
	TVE_AVOUT_DISABLE=0,
	TVE_AVOUT_ENABLE,
}TVE_AVOUT_EN;


typedef enum TVE_AVOUT_MODE{
	 AVOUT_MODE_VD=0,
	 AVOUT_MODE_TVE=6,
}TVE_AVOUT_MODE;


typedef enum TVE_VBI_EN{
	TVE_VBI_DISABLE=0,
	TVE_VBI_ENABLE,
}TVE_VBI_EN;


typedef enum TVE_WSS_EN{
	TVE_WSS_DISABLE=0,
	TVE_WSS_ENABLE,
}TVE_WSS_EN;

typedef enum TVE_VPS_EN{
	TVE_VPS_DISABLE=0,
	TVE_VPS_ENABLE,
}TVE_VPS_EN;

typedef enum TVE_CC_MODE{
	TVE_CC_DISABLE=0,
	TVE_CC_ODD_FIELD,
	TVE_CC_EVEN_FIELD,
	TVE_CC_BOTH_FIELD,
}TVE_CC_MODE;

typedef enum TVE_VBI_TYPE{
	TVE_VBI_TT=0,
	TVE_VBI_CC,
	TVE_VBI_WSS,
	TVE_VBI_VPS
}TVE_VBI_TYPE;

/*==================== Variables ================= */
#define HIGH_BYTE(x)		((x & 0xFF00)>>8)
#define LOW_BYTE(x)		(x & 0x00FF)
#define TVE_ENABLE  (1)
#define TVE_DISABLE (0)
/*==================Definitions for vd2638============================*/


////////////////////extern///////////////////////////////////////////////////



//==========  APIs  ===========================================//

extern unsigned int rtdf_tvedma_inl (unsigned int addr);
extern void drvif_module_tve_init(void);
extern void drvif_module_tve_set_mode(TVE_VIDEO_MODE_SEL mode);
extern void drvif_module_tve_clock_enable(TVE_CLOCK on_off);
extern void drvif_module_tve_AVout_MODE(VDAC_TV_SRC_SEL mode);
extern void drvif_module_tve_AVout_Enable(TVE_AVOUT_EN on_off);
extern void drvif_module_tve_vbi_setting(TVE_VBI_EN on_off);
extern void drvif_module_tve_vbi_memory_setting(unsigned int vbi_addr);
extern void drvif_module_tve_video_memory_setting(unsigned char vflip_en);
extern void drvif_module_tve_cc_setting(TVE_CC_MODE mode);
extern void drvif_module_tve_cc_data(unsigned int odd_data,unsigned int even_data );
extern void drvif_module_tve_vps_setting(TVE_VPS_EN on_off);
extern void drvif_module_tve_vps_data(Struct_TVE_VPS_DATA *VPS_DATA );
extern void drvif_module_tve_wss_setting(TVE_WSS_EN on_off);
extern void drvif_module_tve_wss_data(unsigned int data);
extern void drvif_module_tve_interrupt(int enable);
extern void drvif_module_tve_forcebg(int enable);
extern void drvif_module_tve_change_memory_setting(unsigned int in_width, unsigned char vflip_en);
extern void drvif_module_tve_reset(void);
extern void drvif_module_tve_vbi_pos(unsigned int top_val, unsigned int bottom_val);
extern void drvif_module_tve_wss_pos(unsigned int value);
extern void drvif_module_tve_vps_pos(unsigned int value);
extern void drvif_module_tve_vbi_tt_line_num(unsigned int line_num);
extern void drvif_module_tve_vbidma_trigger(unsigned char triggle_en);
extern void drvif_tve_resume_setting(void);
extern void drv_tve_set_video_pal_i(void);
#ifdef __cplusplus
}
#endif

#endif
