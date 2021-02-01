/*==========================================================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2009
  * All rights reserved.
  * ========================================================================*/

/**
 * @file
 * 	This file is for gibi and od related functions.
 *
 * @author 	$Author$
 * @date 	$Date$
 * @version $Revision$
 */

/**
 * @addtogroup color
 * @{
 */

#ifndef _GIBI_OD_H
#define _GIBI_OD_H
/*============================ Module dependency  ===========================*/
/*#include "rtd_types.h"*/

/*===================================  Types ================================*/

/*================================== Variables ==============================*/
/*================================ Definitions ==============================*/
#define GIBI_FORMAT_444          0
#define GIBI_FORMAT_422          1
#define GIBI_FORMAT_420          2

#define GIBI_BIT_COUNT          8  /* 8 bits*/
#define OD_table_length	289
#define PCID_table_length	289
#define PCID_TABLE_LEN	289
#define POD_TABLE_LEN	578 //289*2

#if CONFIG_VPQ_TABLE_GENERATE
typedef char bool;
typedef unsigned char UINT8;
typedef unsigned short UINT16;
typedef unsigned int UINT32;
#endif

typedef struct {
	unsigned int table_deltamode[OD_table_length];
	unsigned int table_targetmode[OD_table_length];
	unsigned int table_inversemode[OD_table_length];
} DRV_od_table_t;

typedef struct {
	unsigned char type;
	unsigned char gain;
} DRV_od_table_mode_t;

/*PCID Structure*/
#define _REF_COLOR_R 0
#define _REF_COLOR_G 1
#define _REF_COLOR_B 2

#define _REF_POINT_PREV 0
#define _REF_POINT_CURR 1
#define _REF_POINT_NEXT 2

#define _REF_LINE_PREV 0
#define _REF_LINE_CURR 1

typedef struct {
	unsigned char line_sel;
	unsigned char point_sel;
	unsigned char color_sel;
} DRV_pcid_pixel_ref_setting_t;

typedef struct {
	DRV_pcid_pixel_ref_setting_t line1_even_r;
	DRV_pcid_pixel_ref_setting_t line1_even_g;
	DRV_pcid_pixel_ref_setting_t line1_even_b;

	DRV_pcid_pixel_ref_setting_t line1_odd_r;
	DRV_pcid_pixel_ref_setting_t line1_odd_g;
	DRV_pcid_pixel_ref_setting_t line1_odd_b;

	DRV_pcid_pixel_ref_setting_t line2_even_r;
	DRV_pcid_pixel_ref_setting_t line2_even_g;
	DRV_pcid_pixel_ref_setting_t line2_even_b;

	DRV_pcid_pixel_ref_setting_t line2_odd_r;
	DRV_pcid_pixel_ref_setting_t line2_odd_g;
	DRV_pcid_pixel_ref_setting_t line2_odd_b;

	DRV_pcid_pixel_ref_setting_t line3_even_r;
	DRV_pcid_pixel_ref_setting_t line3_even_g;
	DRV_pcid_pixel_ref_setting_t line3_even_b;

	DRV_pcid_pixel_ref_setting_t line3_odd_r;
	DRV_pcid_pixel_ref_setting_t line3_odd_g;
	DRV_pcid_pixel_ref_setting_t line3_odd_b;

	DRV_pcid_pixel_ref_setting_t line4_even_r;
	DRV_pcid_pixel_ref_setting_t line4_even_g;
	DRV_pcid_pixel_ref_setting_t line4_even_b;

	DRV_pcid_pixel_ref_setting_t line4_odd_r;
	DRV_pcid_pixel_ref_setting_t line4_odd_g;
	DRV_pcid_pixel_ref_setting_t line4_odd_b;

} DRV_pcid_ref_setting_t;

typedef struct {
	// LSB addition
	bool lsb_add_en;
	bool lsb_add_nr_en;
	bool lsb_add_slope_check_en;
	int lsb_add_nr_thd;
	// Noise reduction
	bool pcid_thd_en;
	bool pcid_thd_mode;
	int pcid_tbl1_r_th;
	int pcid_tbl1_g_th;
	int pcid_tbl1_b_th;
	// XTR
	bool xtr_tbl1_en;
	// Mode selection
	bool ref_4line;
	bool boundary_mode;
	// Subpixel reference setting
	DRV_pcid_ref_setting_t pixel_ref;
} DRV_pcid_data_t;

typedef enum {
	_PCID_COLOR_R = 0,
	_PCID_COLOR_G,
	_PCID_COLOR_B,
	_PCID_COLOR_ALL,
	_PCID_COLOR_ERR
} DRV_pcid_channel_t;

/*==================================== Function ==================================*/
void drvif_color_od_for_demo(void);

void drvif_color_od_load_table(UINT32 *input_array);
/*============================================================================*/
/*
*set OD to initial state
*/
/*#ifdef OPEN_CELL_PANEL*/
unsigned char drvif_color_od_init(UINT16 height, UINT16 width, UINT8 bits, UINT8 mode, UINT8 freq);
unsigned char drvif_color_od_pqc(UINT16 height, UINT16 width, UINT8 bits, UINT8 mode, UINT8 FrameLimitBit, int dataColor, int dataFormat);

/*============================================================================*/
/*
*set OD switch
*unsigned char bOD			OverDriver switch
*/
void drvif_color_od(unsigned char bOD);
// henry 170309
void drvif_color_od_table_read(unsigned char *pODtable);
void drvif_color_od_table_seperate(unsigned int *pODtable, unsigned char  tableType);
void drvif_color_od_table_seperate_write(unsigned int *pODtable, unsigned char tableType, char channel);
void drvif_color_od_table_seperate_read(unsigned char *pODtable, unsigned char channel);

// end henry
void drvif_color_od_table(unsigned int *pODtable, unsigned char targetmode);

void drvif_color_safe_od_enable(unsigned char bEnable, unsigned char bOD_OnOff_Switch);
/*#endif*/

/*============================================================================*/
/*
*set OD Gain
*unsigned char hOD			OverDriver switch
*/
void drvif_color_od_gain(unsigned char ucGain);
unsigned char drvif_color_get_od_gain(void);

/*============================================================================*/
/*
*set GIBI to initial state
*
*unsigned char bits	bit count
*unsigned char fmt	C format = 0:444, 1:422, 2:420
*/
void drvif_color_gibi_init(unsigned char bits, unsigned char fmt);

/*============================================================================*/
/*
*set GIBI switch
*unsigned char bGIBI			GIBI switch
*/
void drvif_color_gibi(unsigned char bGIBI);

/*============================================================================*/
/*
*release GIBI
*/
void drvif_color_gibi_release(void);

/*============================================================================*/
/*
*background color control
*/
void drvif_color_gibi_set_bg_color(unsigned char ColorR, unsigned char ColorG, unsigned char ColorB);

/*============================================================================*/

/*PCID*/
void drvif_color_pcid_enable(unsigned char bpcid);
void drvif_color_pcid_valuetable(unsigned int *pPcidtable);
void drvif_color_pcid_pixel_setting(DRV_pcid_data_t* pPcidSetting);

//unsigned int drvif_color_od_memory_alloc_block(unsigned int space, unsigned int *startAddr1, unsigned int *startAddr2);
//void drvif_color_od_uninit(void);

/*default y mode and y mode bias*/
void drvif_color_od_Ymode(unsigned char bEn);

/*LGD Dither for PCID2*/
void drvif_color_LGD_Dither(void);

void drvif_color_set_od_bits(unsigned char FrameLimitBit, unsigned char input_bit_sel);
unsigned char drvif_color_get_od_bits(void);
unsigned char drvif_color_get_od_en(void);
unsigned char drvif_color_set_od_dma_enable(unsigned char enable);
unsigned char drvif_color_get_od_dma_enable(void);

#endif

