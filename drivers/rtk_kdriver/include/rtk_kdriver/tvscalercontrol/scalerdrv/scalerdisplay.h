/*==========================================================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2006
  * All rights reserved.
  * ========================================================================*/

/*================= File Description =======================================*/
/**
 * @file
 * 	This file is for scaler display related functions.
 *
 * @author 	$Author$
 * @date		$Date$
 * @version	$Revision$
 * @ingroup	display
 */

/**
 * @addtogroup display
 * @{
 */

#ifndef _SCALER_DISPLAY_H
#define _SCALER_DISPLAY_H

 #ifdef __cplusplus
extern "C" {
#endif
/*============================ Module dependency  ===========================*/
//#include <rtd_types.h>
#include <tvscalercontrol/scaler/source.h>
typedef unsigned char UINT8;
typedef unsigned short UINT16;
typedef unsigned int UINT32;

/*================================ Definitions ==============================*/
#ifndef CONFIG_DUAL_CHANNEL
#define _CHANNEL_NUM 1
#else
#define _CHANNEL_NUM 2
#endif

//#define _DISP_WID (CONFIG_DISP_ACT_END_HPOS - CONFIG_DISP_ACT_STA_HPOS)
//#define _DISP_LEN  (CONFIG_DISP_ACT_END_VPOS - CONFIG_DISP_ACT_STA_VPOS)
#define _DISP_WID (Get_DISP_ACT_END_HPOS() - Get_DISP_ACT_STA_HPOS())
#define _DISP_LEN  (Get_DISP_ACT_END_VPOS()  - Get_DISP_ACT_STA_VPOS() )

/*===================================  Types ================================*/
typedef enum _DISPLAY_REG_TABLE_TYPE{
	DISPLAY_REG_FUNC_OVERSCAN = 0x00,
	DISPLAY_REG_FUNC_GET_SRC_OVERSCAN,
	DISPLAY_REG_FUNC_VGIP_ADJUSTMENT,
	DISPLAY_REG_FUNC_3DOVERSCAN,
#ifdef ENABLE_MHEG5
    DISPLAY_REG_FUNC_MHEG5_ADJUSTMENT,
    DISPLAY_REG_FUNC_MHEG5_DISPLAY_CHANGE_NOTIFY,
#endif
} DISPLAY_REG_TABLE_TYPE;

typedef enum {
	_DISPLAY_BG = 0x00,		///! type of background color
	_DISPLAY_EB,			///! type of external border
	_DISPLAY_HB				///! type of highlight border
} eDISPLAYBORDERTYPE;

typedef struct {
	unsigned char ColorR;			///! color red
	unsigned char ColorG;			///! color green
	unsigned char ColorB;			///! color blue
} stCOLOR;

typedef struct {
	unsigned short HStart;			///! start position in horizontal direction
	unsigned short HEnd;			///! end position in horizontal didrection
	unsigned short HWidth;			///! width
	unsigned short VStart;			///! start position in vertical direction
	unsigned short VEnd;			///! end position in vertical direction
	unsigned short VLength;			///! height
} stWINDOW;

typedef struct {
	stCOLOR BgColor[_CHANNEL_NUM];			///! background color
	stCOLOR EbColor[_CHANNEL_NUM];			///! external border color
	stCOLOR HbColor[_CHANNEL_NUM];			///! highlight border color
	stWINDOW DisplayWindow[_CHANNEL_NUM];	///! display window information
	stWINDOW ActiveWindow[_CHANNEL_NUM];		///! active window information
	unsigned short HStdClkTotal;	///! Standard display clock number in one display horizontal line
	unsigned short VStdClkTotal;	///! Standard display horizontal line in one display frame
	unsigned char PanelSts;			///! indicate panel on/off status
} stDISPLAY;

typedef enum {
	OSD_VBI = 0x00,
	OSD_UINT8MAP,
	OSD_FONTBASED,
	OSD_CURSOR,
	OSD_ALL
} eDISPLAYOSDOVERLAY;

typedef struct
{
	unsigned short HStart;
	unsigned short HWidth;
	unsigned short VStart;
	unsigned short VHeight;
} stDISPLAY_OVERSCAN_DATA;

typedef struct
{
	unsigned char h_ratio_dtv;
	unsigned char v_ratio_dtv;
	unsigned char h_ratio_atv;
	unsigned char v_ratio_atv;
	unsigned char h_ratio_cvbs;
	unsigned char v_ratio_cvbs;
	unsigned char h_ratio_sv;
	unsigned char v_ratio_sv;
	unsigned char h_ratio_ypbpr;
	unsigned char v_ratio_ypbpr;
	unsigned char h_ratio_vga;
	unsigned char v_ratio_vga;
	unsigned char h_ratio_hdmi;
	unsigned char v_ratio_hdmi;
	unsigned char h_ratio_default;
	unsigned char v_ratio_default;
}stDISPLAY_OVERSCAN_INFO;

typedef struct
{
	unsigned char					timing;
	SLR_RATIO_TYPE 		displayratio;
	short					h_start;
	short					h_width;
	short					v_start;
	short					v_length;
}stVGIP_ADJUSTMENT_INFO;

/*================================== Function ===============================*/
/*============================================================================*/
/**
 * drvif_scalerdisplay_init
 * Init display control module. Collect the register, which should be insert only once.
 *
 * @param  { none }
 * @return { none }
 *
 */
void drvif_scalerdisplay_init(void);


/*============================================================================*/
/**
 * drvif_scalerdisplay_set_bg_color
 * This function is used to set background and border color of both main and sub.
 *
 * @param <display> {main or sub display}
 * @param <type> {offset value of background or external or highlight address}
 * @param <color_red> {red value}
 * @param <color_grn> {green value}
 * @param <color_blu> {blue value}
 * @return { none }
 *
 */
void drvif_scalerdisplay_set_bg_color(unsigned char display, eDISPLAYBORDERTYPE BorderType, unsigned int ColorR, unsigned int ColorG, unsigned int ColorB);
#if 0
/*============================================================================*/
/**
 * ScalerDisplay_SetFifo
 * Read width/length of display window before scale-up
 *
 * @param  { none }
 * @return { none }
 *
 */
void ScalerDisplay_SetFifo(void);
#endif

/*============================================================================*/
/**
 * drvif_scalerdisplay_set_freeze
 * This function is used to set background and border color of both main and sub.
 *
 * @param <display> {main or sub display}
 * @param <type> {offset value of background or external or highlight address}
 * @param <color_red> {red value}
 * @param <color_grn> {green value}
 * @param <color_blu> {blue value}
 * @return { none }
 *
 */
void drvif_scalerdisplay_set_freeze(unsigned char display, unsigned char bFreeze);

/*============================================================================*/
/**
 * fw_scalerdisplay_get_display_size
 * Set display window size, it must considers aspect ratio.
 *
 * @param { none }
 * @return none
 *
 */
void fw_scalerdisplay_get_display_size(unsigned char display);

/*============================================================================*/
/**
 * fw_control_force_bg
 * Force display to background
 *
 * @param { nDisplay : Specify to Main/Sub }
 * @param { bEnable  : Enable/Disable Force to Background }
 * @param { nDisplay : Specify to the Background color }
 * @return { none }
 *
 */

unsigned char fwif_display_regTable(DISPLAY_REG_TABLE_TYPE index, void *ptr);

//void fw_control_force_bg(unsigned char nDisplay, unsigned char bEnable, unsigned int nBKColor);
//void drvif_scalerdisplay_force_bg(SCALER_DISP_CHANNEL disp, unsigned char Enable);
void drvif_scalerdisplay_force_black_bg(unsigned char Enable);
unsigned char drvif_scalerdisplay_get_force_bg_status(void);

/*============================================================================*/
/**
 * fw_scalerdisplay_handler
 * This function is used to handle display (page4), including main & sub
 * It contains several parts:
 * 1. timing control
 * 2. main display
 * 3. sub display
 * 4. scaling
 * 5. OSD overlay
 * 6. CRC
 *
 * @param <info> { display-info struecture }
 * @return none
 *
 */
void fw_scalerdisplay_handler(unsigned char display);

#define _FrameSyncMode 0
#define _FRCMode 1

/*============================================================================*/
/**
 * DisplaySetMainDisplayWindow
 * This function is used to set the position of Main display and background window,
 * including the start/end position in both horizontal and vertical direction
 * Besides, it also contains the border and background information
 *
 * @param <DispHSta> {start position in horizontal direction}
 * @param <DispHEnd> {end position in horizontal direction}
 * @param <DispVSta> {start position in vertical direction}
 * @param <DispVEnd> {end position in vertical direction}
 * @param <Border> {border size}
 * @return { none }
 *
 */
//void __init DisplaySetMainDisplayWindow(unsigned short DispHSta, unsigned short DispHEnd, unsigned short DispVSta, unsigned short DispVEnd, unsigned char Border);
void scalerdisplay_set_main_display_window(unsigned short DispHSta, unsigned short DispHEnd, unsigned short DispVSta, unsigned short DispVEnd, unsigned char Border);
void scalerdisplay_set_main_display_window_H(unsigned short DispHSta, unsigned short DispHEnd, unsigned char Border);
void scalerdisplay_set_main_display_window_V(unsigned short DispVSta, unsigned short DispVEnd, unsigned char Border);
void scalerdisplay_set_main_act_window(unsigned short DispHSta, unsigned short DispHEnd, unsigned short DispVSta,unsigned short DispVEnd);
void scalerdisplay_vo_ratio_change(VO_VIDEO_PLANE plane);
#ifdef CONFIG_SDNR_CROP
unsigned char fw_scaler_cal_sdnr_capture(unsigned char display);
#endif
unsigned char fw_scaler_cal_vgip_capture(unsigned char display);
void drvif_scalerdisplay_enable_display(unsigned char display, unsigned char bEnable);
void drvif_scalerdisplay_set_dbuffer_en(SCALER_DISP_CHANNEL display, int En);
void drvif_scalerdisplay_subdisplay_hidenfunc(unsigned char bEnable);
void PIP_OverScan(unsigned char HScalerate,unsigned char VScalerate);
#ifdef CONFIG_CUSTOMER_2 //only use for customer2 tommy add
void fw_control_force_bgInit(unsigned char disp, unsigned char Enable);
#endif
void scalerdisplay_Change_panel_hvtotal(unsigned char enable);

#if 0
unsigned char CModeSetModeHandler(void);
void ScalerDisplay_VideoSet(void);

void ScalerDisplay_EnableOsdOverlay(eDisplayOsdOverlay OsdType);
void ScalerDisplay_DisableOsdOverlay(eDisplayOsdOverlay OsdType);
void ScalerDisplay_SetCRC(void);
void ScalerDisplay_SetClamp(void);
void ScalerDisplay_SetNormal(void);
void ScalerDisplay_SetOsdBlend(eDisplayOsdOverlay OsdType, unsigned char Level);
#endif //#if 0

void fw_scaler_get_main_and_sub_info(stWINDOW *MainWinInfo, stWINDOW *SubWinInfo);
void fw_scaler_zoom_cal_vgip_capture(int ratioH, int ratioV);
//void fw_scaler_zoom_cal_vgip_AspectRatio_capture(void);////removed by coverity 120148 //DEADCODE
void scalerdisplay_set_timing(void);


typedef enum _DISP_DMACLK_SELECT{
	DISP_DMACLK_IS_DPLL = 0,
	DISP_DMACLK_IS_DPLL_DIV_2 = 1,
} DISP_DMACLK_SELECT;

typedef enum _DISP_DCLK_SELECT{
	DISP_DCLK_IS_DPLL = 0,
	DISP_DCLK_IS_DPLL_DIV_2 = 1,
	DISP_DCLK_IS_DPLL_DIV_4 = 2,
} DISP_DCLK_SELECT;

typedef enum _DISP_PIF_TYPE{
	DISP_PIF_TYPE_1_TO_1 = 0, // 1-to-1 or 2-to-2 (3 pair mini-lvds set needed)
	DISP_PIF_TYPE_1_TO_2 = 1,
	DISP_PIF_TYPE_2_TO_4 = 2,
	DISP_PIF_TYPE_1_TO_4 = 3,
} DISP_PIF_TYPE;

typedef enum{
    _TYPE_IVS = 0,
    _TYPE_DVS,
    _TYPE_D3DTG_DVS,
} DISP_VSYNC_TYPE;


typedef enum _SLR_FORCE_BG_TYPE {
	SLR_FORCE_BG_TYPE_VSC = 0,	// background msak for VSC
	SLR_FORCE_BG_TYPE_3D,//background mask for 3d case
	SLR_FORCE_BG_TYPE_LIVEZOOM,
	SLR_FORCE_BG_TYPE_GameMode,
	SLR_FORCE_BG_TYPE_SIG_UNSTABLE,
	SLR_FORCE_BG_TYPE_MAX,
} SLR_FORCE_BG_TYPE;

void drvif_scalerdisplay_set_dclk_sel(DISP_DMACLK_SELECT dma_clk_sel, DISP_DCLK_SELECT dclk_sel);
void  fw_scaler_finetune_tcon(void);
void  fw_scaler_4k2k_color_config(void);
void drvif_scalerdisplay_set_sharpness_line_mode(void);
//void drvif_scalerdisplay_I2CSettingToMillet(MILLET_I2C_INPUT_FORMAT command);
//UINT32 drvif_scalerdisplay_MilletI2C_Read(UINT16 addr);
//UINT32 drvif_scalerdisplay_MilletI2C_Write(UINT16 addr, UINT32 data);
void scaler_Millet3_LVDS_output_control(unsigned char bootMode);
void drvif_scalerdisplay_SFG_Setup(void);
#ifdef CONFIG_TEST_SCALER_DFRC
void scaler_dtg_reconfig_by_sr_mode(unsigned char srmode);
#endif
void scaler_dtg_reconfig(void);
void scalerdisplay_set_3D_Support(bool enable);
void scalerdisplay_set_PWM_Tuning(void);
unsigned int scalerdisplay_get_dclk(void);
unsigned int scalerdisplay_get_framerate(DISP_VSYNC_TYPE VsyncType);
unsigned int scalerdisplay_get_dclk(void);

// PixelWorks PA168 4k2k TCON control
typedef enum _PA168_LVDS_INPUT_FMT{
	LVDS_FMT_8BIT_JEIDA	= 0,
	LVDS_FMT_8BIT_VESA	= 1,
	LVDS_FMT_10BIT_JEIDA	= 2,
	LVDS_FMT_10BIT_VESA	= 3,
	LVDS_FMT_10BIT_MIX	= 4
}PA168_LVDS_INPUT_FMT;

typedef enum _PA168_MEMC_DEMO_MODE{
	MEMC_DEMO_MODE_OFF		= 0,
	MEMC_DEMO_MODE_FULL		= 1,
	MEMC_DEMO_MODE_RIGHT	= 2,
	MEMC_DEMO_MODE_CENTER	= 3,
	MEMC_DEMO_MODE_TOP		= 4,
}PA168_MEMC_DEMO_MODE;

#define PA168_I2C_SLAVE_ID				(0x22 >> 1)	// 1 bit R-shift for Darwin I2C bug?
#define PA168_I2C_CMD_CAPTURE_OFF	(0x27)
#define PA168_I2C_CMD_LVDS_FMT		(0x18)
#define PA168_I2C_CMD_MEMC_DEMO		(0x09)
#define PA168_I2C_CMD_RESET			(0x0e)

//void scaler_PixelWorks_PA168_LVDS_output_control(unsigned char bootMode);
unsigned char scalerdisplay_get_2D_MEMC_support(void);
//void scaler_PixelWorks_PA168_set_LvdsInutFmt(PA168_LVDS_INPUT_FMT lvdsFmt);
//void scaler_PixelWorks_PA168_set_MEMC_demoMode(PA168_MEMC_DEMO_MODE mode);
//void scaler_PixelWorks_PA168_captureDisable(unsigned char mode);
//void scaler_PixelWorks_PA168_lvdsDisable(unsigned char mode);
//void scaler_PixelWorks_PA168_powerReset(unsigned char onOff);

typedef struct
{
	unsigned short		boxDispWid;
	unsigned short		boxDispLen;
	unsigned short		boxDispHDenStart;
	unsigned short		boxDispHDenEnd;
	unsigned short		boxDispVDenStart;
	unsigned short		boxDispVDenEnd;
	unsigned short		boxDispHTotal;
	unsigned short		boxDispVTotal;
}SCALER_TVBOX_DISPINFO;


typedef enum _TVBOXINFO
{
	_BOX_DISP_WID,
	_BOX_DISP_LEN,
	_BOX_DISP_HDENSTART,
	_BOX_DISP_HDENEND,
	_BOX_DISP_VDENSTART,
	_BOX_DISP_VDENEND,
	_BOX_DISP_HTOTAL,
	_BOX_DISP_VTOTAL,
}TVBOXINFO;

unsigned short scalerdisplay_get_BoxDispInfo(TVBOXINFO boxInfo);
void scalerdisplay_change_timing_to_disp2tve(unsigned char mode);
void scalerdisplay_set_disp2tve_flow(unsigned char mode);
void scalerdisplay_set_display_use_tve_size(unsigned char flag);
unsigned char scalerdisplay_get_display_use_tve_size(void);
void scalerdisplay_set_display_tve_mode(unsigned char Mode);
unsigned char scalerdisplay_get_display_tve_mode(void);
void scalerdisplay_force_bg_enable(unsigned int channel, unsigned char enable);
void cal_adaptive_streaming_input(unsigned char display);
StructSrcRect cal_new_input_for_Adaptive(unsigned char display);
void set_input_for_vgip(unsigned char display, unsigned short input_x, unsigned short input_y, unsigned short input_w, unsigned short input_h);/*For set input region*/
void get_input_for_vgip(unsigned char display, StructSrcRect *p_input);
unsigned int scalerdisplay_get_vtotal_by_vfreq(UINT16 vsyncFreq);

void drvif_scalerDTG_set_bg_color(unsigned char ColorR, unsigned char ColorG, unsigned char ColorB,unsigned char enable);
unsigned char Scaler_OpenVOGating(void);
void set_display_forcebg_mask(unsigned char display, unsigned char masktype, unsigned char maskvalue);
unsigned char Get_display_forcebg_mask(unsigned char display, unsigned char masktype);
void forcebg_semaphore_init(void);
struct semaphore* get_forcebg_semaphore(void);
unsigned char Check_AP_Set_Enable_ForceBG(unsigned char display);
void DI_semaphore_init(void);
struct semaphore* get_DI_semaphore(void);
spinlock_t* get_DBreg_spinlock(unsigned char display);
spinlock_t* get_FBreg_spinlock(unsigned char display);
void drvif_scalerdisplay_set_panel_bg_color(unsigned int ColorR, unsigned int ColorG, unsigned int ColorB);//set SFG color
#ifdef __cplusplus
 }
#endif

#endif	// #ifndef _SCALER_DISPLAY_H
/*======================== End of File =======================================*/

/**
  * @}
  */


