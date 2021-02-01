/***************************************************************************
                          scalerVIP.h  -  description
                             -------------------
    begin                : Mon Dec 22 2008
    copyright           : (C) 2008 by hsliao
    email                : hsliao@realtek.com
 ***************************************************************************/

#ifndef __SCALERDCC_H__
#define __SCALERDCC_H__

#include "rtd_types.h"
//#include "kernel/common/gsys_share.h"

// driver header
//#include <kernel/scaler/scalerInfo.h>
#include <scalercommon/vipCommon.h>
#include <scalercommon/scalerCommon.h>
#include <scalercommon/vdcCommon.h>


/*===================================  Types ================================*/

void scalerVIP_colorHistISR(unsigned char channel);
void histogram_new_dcc_write_table(unsigned char display, unsigned char Total_Curve_segment, unsigned char double_buffer_mode_on);

void drvif_color_DCC_Curve_Blending(unsigned char channel,unsigned char bin,unsigned int *Adavance_Control_Curve_Blending_info,unsigned int *Adavance_Control_info);
void histogram_new_III_dcc(unsigned char display, unsigned char bit_num ,unsigned char Curve_bit_num);
void drvif_color_Get_Section_histogram(unsigned char channel, unsigned char C_Channel_select, unsigned char Section_Select, unsigned char Section_bin_Select, unsigned int *Section_Hist);
int drvif_DCC_SC_smoothing_for_curve_delay_applied_condition_check(unsigned char MainDCC_SC, int* Main_preH, int* Gz, unsigned long Curve_diff_thershold, int* Scene_change_DCC_apply_delay_flag);
#if 1 //from Merlin2 20160629
void drvif_color_Get_Idomain_Y_histogram(unsigned char channel, unsigned char C_Channel_select, unsigned int *reg_HistCnt);
#ifdef CONFIG_HW_SUPPORT_D_HISTOGRAM
void drvif_color_Get_Ddomain_Y_histogram(unsigned char channel, unsigned char C_Channel_select, unsigned int *reg_HistCnt);
#endif
#else
void drvif_color_Get_Y_histogram(unsigned char channel, unsigned char C_Channel_select, unsigned int *reg_HistCnt);
#endif

void scalerVIP_SetDCC_Advance_control_table(unsigned long arg);

#if 1
#ifdef CONFIG_HW_SUPPORT_D_HISTOGRAM
void scalerVIP_ddomain_colorHistISR(unsigned char channel);
#endif
void drvif_color_DHIST_SC(unsigned char channel);
void drvif_color_IHIST_SC(unsigned char channel);
#ifdef CONFIG_HW_SUPPORT_D_HISTOGRAM
void scalerDCC_get_D_hist_window(unsigned short *pWidth, unsigned short *pHeight);
#endif
unsigned char scalerVIP_color_D_Hist_Get_APL(unsigned char channel, unsigned int *pHist_Y_APL);
#else
void drvif_color_DCC_SC(unsigned char channel);
#endif
void drvif_color_DCC_SC_TV002(unsigned char channel);
void drvif_color_DCC_SC_TV010(unsigned char channel);
void scalerDCC_tv006_apply_dcc(unsigned char display, unsigned char Curve_bit_num);
void driver_DCC_Chroma_enhance_gain_cal(unsigned char display,unsigned char Table_sel, int *DCC_Apply_Curve,VIP_DCC_Chroma_Compensation_TABLE *table);
void driver_DCC_Chroma_enhance_gain_apply(unsigned char display,unsigned char Table_sel, int *chroma_gain);
unsigned char scalerVIP_colorHist_Get_APL(unsigned char channel, unsigned int *pHist_Y_APL);
void scalerDCC_get_hist_window(unsigned short *pWidth, unsigned short *pHeight);
#ifndef CONFIG_RTK_KDEV_VGIP_INTERRUPT
void scalerDCC_SCPU_ISR_apply_dcc(UINT8 display, UINT8 Curve_bit_num);
#endif
#endif

