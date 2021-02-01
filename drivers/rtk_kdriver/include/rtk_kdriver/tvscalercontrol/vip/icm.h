 /*==========================================================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2006
  * All rights reserved.
  * ========================================================================*/

/*================= File Description =======================================*/
/**
 * @file
 * 	This file is for color related functions.
 *
 * @author 	$Author$
 * @date 	$Date$
 * @version $Revision$
 */

/**
 * @addtogroup color
 * @{
 */

/*============================ Module dependency  ===========================*/
#ifndef _ICM_H
#define _ICM_H

/*#include "rtd_types.h"*/

#ifdef __cplusplus
extern "C" {
#endif


/*===================================  Types ================================*/


/*================================== Variables ==============================*/


/*================================ Definitions ==============================*/

typedef struct {
	int H; /* or H*/
	int S; /* or S'*/
	int I; /* or Y*/
} COLORELEM;

enum {
	_HUE_ELEM = 0,
	_SAT_ELEM,
	_ITN_ELEM,
};/* WhichElem;*/

#define HUERANGE        1536
#define SATRANGE        4096
#define ITNRANGE        4096
#define SATRANGEEX      8192
#define ITNRANGEEX      8192
#define YUVRANGE		4096

#define HUESEGMAX	64
#define SATSEGMAX	12
#define ITNSEGMAX	12
#define ITN_SUBTRACT_CONST	1752

#if 0	/* move to vipCommon.h*/
#define VIP_ICM_TBL_X 5
#define VIP_ICM_TBL_Y 434 /*12(itn) x 12(sat) x 3(h/s/i) + 2(global settings) = 434*/
#define VIP_ICM_TBL_Z 64
#endif
/*#define SLR_MAIN_DISPLAY 0*/

#define	ICM_Global_hue 0
#define ICM_Global_Sat 1
#define ICM_Global_Itn 2

typedef struct {
	COLORELEM elem[ITNSEGMAX][SATSEGMAX][HUESEGMAX];
} COLORELEM_TAB_T;

typedef struct {
	unsigned char axis;
	short offset;
	short h_sta;
	short h_end;
	short s_sta;
	short s_end;
	short i_sta;
	short i_end;
} COLORELEM_BLOCK_ADJ_PARAM;

typedef struct {
	short dHue[7];
	short dSat[7];
	short dItn[7];

	unsigned char h_fixed_pillar_sta[7];
	unsigned char h_fixed_pillar_end[7];
	unsigned char s_fixed_pillar_sta[7];
	unsigned char s_fixed_pillar_end[7];
	unsigned char i_fixed_pillar_sta[7];
	unsigned char i_fixed_pillar_end[7];
} COLORELEM_COLOR_MANAGEMENT_PARAM_TV006;

typedef struct {
	short dHue[3];

	unsigned char h_fixed_pillar_sta[3];
	unsigned char h_fixed_pillar_end[3];
	unsigned char s_fixed_pillar_sta[3];
	unsigned char s_fixed_pillar_end[3];
	unsigned char i_fixed_pillar_sta[3];
	unsigned char i_fixed_pillar_end[3];
} COLORELEM_PREFERRED_COLOR_PARAM_TV006;


#define CLIP(min, max, val) ((val < min) ? min : (val > max ? max : val))

/*================================== Function ===============================*/

/*============================================================================*/
/**
 * @param <display> {display channel, main=0 / sub=1}
 * @return {none}
 */
/*============================================================================*/
void drvif_color_icm_set_bypass_onoff(unsigned char display, unsigned char bEable);
void drvif_color_icm_hue_histo_init(void);
void drvif_color_icm_table_select(unsigned char display, unsigned short *tICM_ini, unsigned char which_table);
unsigned char drvif_color_icm_global_adjust(int g_dhue_cur, int *g_dsatbysat_cur, int *g_ditnbyitn_cur, unsigned char bSubtractPrevious);
unsigned char drvif_color_icm_Set_global(int g_dhue_cur, int *g_dsatbysat_cur, int *g_ditnbyitn_cur);
unsigned char drvif_color_set_icm_Enable(unsigned char enable_Flag);

unsigned char drvif_color_icm_Get_Global_Ctrl(unsigned char bFromVIPTable, int *g_dhue_cur, int *g_dsatbysat_cur, int *g_ditnbyitn_cur);
void drvif_color_Icm_Enable(unsigned char bEable);
unsigned char drvif_color_Icm_Get_Enable(void);
unsigned char drvif_color_Icm_Read3DTable(COLORELEM ICM_TAB_ACCESS[ITNSEGMAX][SATSEGMAX][HUESEGMAX]);
void drvif_color_seticmhsi(unsigned char display, short Value, unsigned char which_item);
int drvif_color_icm_FormatValue(int value, unsigned char type, unsigned char tab_mode, unsigned char IfWrite);

/*for TV035_1*/
void drvif_color_icm_user_function(unsigned char display, unsigned short *tICM_ini, unsigned char which_table, unsigned char skin_tone, unsigned char color_wheel, unsigned char detail_enhance, unsigned dynamic_tint);
void drvif_color_icm_SKIN_TONE(unsigned char display, unsigned short *tICM_ini, unsigned char which_table, unsigned short nValue);

unsigned char drvif_color_icm_Adjust_Block(unsigned char nAxis, int nOffset, int adjust_len, int h_sta, int h_end, unsigned char h_total, int s_sta, int s_end, unsigned char s_total, int i_sta, int i_end, unsigned char i_total);
unsigned char drvif_color_icm_SramBlockAccessSpeedup(unsigned int *buf, unsigned char if_write_ic, int h_sta, int h_end, int s_sta, int s_end, int i_sta, int i_end);
unsigned char drvif_color_icm_GetBufFromICMTab(unsigned int *buf, COLORELEM ICM_TAB_ACCESS[ITNSEGMAX][SATSEGMAX][HUESEGMAX],	int h_sta, int h_end, int s_sta, int s_end, int i_sta, int i_end);
unsigned char drvif_color_icm_SramBlockWriteSpeedup(unsigned int *buf, int h_sta, int h_end, int s_sta, int s_end, int i_sta, int i_end);
unsigned char drvif_color_icm_SramBlockReadSpeedup(unsigned int *buf, int h_sta, int h_end, int s_sta, int s_end, int i_sta, int i_end, unsigned char nAxis, int nOffset);
unsigned char drvif_color_icm_SetBufToICMTab(unsigned int *buf, COLORELEM ICM_TAB_ACCESS[ITNSEGMAX][SATSEGMAX][HUESEGMAX], int h_sta, int h_end, int s_sta, int s_end, int i_sta, int i_end);
int drvif_color_icm_ReadHueValue(int hue, int ii, int is, int ih);

unsigned char drvif_color_icm_Adjust_Protection(unsigned int *buf, int nOffset, int adjust_len, int h_sta, int h_end, unsigned char h_total, int s_sta, int s_end, unsigned char s_total, int i_sta, int i_end, unsigned char i_total);


unsigned char drvif_color_icm_set_ctrl(unsigned short table_mode, unsigned short hsi_grid_sel, unsigned short out_grid_process, unsigned short y_ctrl);
unsigned char drvif_color_icm_set_uv_coring(unsigned short u_coring, unsigned short v_coring);
unsigned char drvif_color_icm_save_global_of_viptable(unsigned short dhue_cur, unsigned short *dsatbysat_cur, unsigned short *ditnbyitn_cur);
unsigned char drvif_color_icm_set_pillar(unsigned short *h_pillar, unsigned short *s_pillar, unsigned short *i_pillar);
unsigned char drvif_color_icm_Write3DTable(COLORELEM ICM_TAB_ACCESS[ITNSEGMAX][SATSEGMAX][HUESEGMAX]);
void drvif_color_Icm_Enable(unsigned char bEable);

void drvif_color_Icm_ctrl_YUV2RGB(unsigned char data_format_sel, unsigned char data_range_sel);

#ifdef __cplusplus
}
#endif

#endif

