/***************************************************************************
                          scalerDI.c  -  description
                             -------------------
    begin                : Wed Dec 11 2013
    copyright           : (C) 2013 by LearnRPG
    email                : learnrpg@realtek.com
    history              : Original from auto_ma, then scalerVIP, finally scalerDI
 ***************************************************************************/

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <rtd_macro.h>

// driver header
#include <scalercommon/scalerCommon.h>
//#include <kernel/scaler/scalerInfo.h>
#include "vgip_isr/scalerDI.h"
#include "vgip_isr/scalerVideo.h"
#include "vgip_isr/scalerVIP.h"
//#include <vgip_isr/scaler/scalerDrv.h>
//#include <vgip_isr/scaler/scalerIRQ.h>
//#include <vgip_isr/scaler/scalerIRC.h>

#include <rbus/vdtop_reg.h>
#include <rbus/histogram_reg.h>
#include <rbus/di_reg.h>

#include <tvscalercontrol/vip/vip_reg_def.h>
#include "tvscalercontrol/scaler/scalerstruct.h"
#include <tvscalercontrol/scaler/scalercolorlib_tv002.h>

#ifdef VIP_DEBUG_ENABLE
  #define VIP_DEBUG_PRINTF	printk
#else
  #define VIP_DEBUG_PRINTF(x,y...)
#endif


#define _DISABLE		0
#define _ENABLE		1

//extern UINT32	*reg_HistCnt;	// histogram
extern _clues *SmartPic_clue;

extern unsigned int MA_print_count;
extern unsigned char AutoMADebugMsg;

extern Start_Print_info_t Start_Print;

static unsigned int BeerCount = 0;
static unsigned char BeerFlag = 0;
static unsigned char ZoomInCount = 0;
static unsigned char PanInCount = 0;

unsigned int pre_total_motion_sum;
unsigned int cur_total_motion_sum;
unsigned int CaveCount=0;
unsigned int soft_move=0;
unsigned int static_move=0;

static unsigned char btr_control = 2; // 0: disable, 1: enable, 2: initial value.
static unsigned char SIS_INIT = 0;
static ScalerDIGlobalStatus Smart_Integration_Status; // private variable, nobody can extern me
extern unsigned char DynamicOptimizeSystem[200];

extern _system_setting_info		 	*system_info_structure_table;
extern _RPC_system_setting_info		 	*RPC_system_info_structure_table;
// fw film mode start/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
extern unsigned char TV_05_style_ON;
static unsigned char Mcnr_Pan =0; //0:pan disable 1:pan_enable
static unsigned char Mcnr_V_Pan =0; //0:pan disable 1:pan_enable

int GMV_ratio=0;

#define FILM22 1
#define FILM32 2
#define FILM3223 4
#define FILM64 8
#define FILM55 16
#define FILM2224 32
#define FILM32322 64
#define FILM87 128
#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))

#endif
#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))

#endif

static unsigned int StatusFrameStaticPattern=0,StatusFrameStaticPattern_H1=0,StatusFrameStaticPattern_H2=0,StatusFrameStaticPattern_H3=0;
static unsigned int StatusFrameStaticPattern_V1=0,StatusFrameStaticPattern_V2=0,StatusFrameStaticPattern_V3=0,StatusFrameStaticPattern_C=0;
static unsigned int StatusFramePairPattern=0,StatusFramePairPattern_H1=0,StatusFramePairPattern_H2=0,StatusFramePairPattern_H3=0;
static unsigned int StatusFramePairPattern_V1=0,StatusFramePairPattern_V2=0,StatusFramePairPattern_V3=0,StatusFramePairPattern_C=0;
static unsigned int StatusPrevStaticPattern=0,StatusPrevStaticPattern_H1=0,StatusPrevStaticPattern_H2=0,StatusPrevStaticPattern_H3=0;
static unsigned int StatusPrevStaticPattern_V1=0,StatusPrevStaticPattern_V2=0,StatusPrevStaticPattern_V3=0,StatusPrevStaticPattern_C=0;
static unsigned int StatusNextStaticPattern=0,StatusNextStaticPattern_H1=0,StatusNextStaticPattern_H2=0,StatusNextStaticPattern_H3=0;
static unsigned int StatusNextStaticPattern_V1=0,StatusNextStaticPattern_V2=0,StatusNextStaticPattern_V3=0,StatusNextStaticPattern_C=0;
static unsigned int StatusPrevStaticPattern2=0,StatusPrevStaticPattern2_H1=0,StatusPrevStaticPattern2_H2=0,StatusPrevStaticPattern2_H3=0;
static unsigned int StatusPrevStaticPattern2_V1=0,StatusPrevStaticPattern2_V2=0,StatusPrevStaticPattern2_V3=0,StatusPrevStaticPattern2_C=0;
static unsigned int StatusNextStaticPattern2=0,StatusNextStaticPattern2_H1=0,StatusNextStaticPattern2_H2=0,StatusNextStaticPattern2_H3=0;
static unsigned int StatusNextStaticPattern2_V1=0,StatusNextStaticPattern2_V2=0,StatusNextStaticPattern2_V3=0,StatusNextStaticPattern2_C=0;
static unsigned int StatusNextStaticPattern_film22=0,StatusNextStaticPattern_film22_H1=0,StatusNextStaticPattern_film22_H2=0,StatusNextStaticPattern_film22_H3=0;
static unsigned int StatusNextStaticPattern_film22_V1=0,StatusNextStaticPattern_film22_V2=0,StatusNextStaticPattern_film22_V3=0,StatusNextStaticPattern_film22_C=0;
static unsigned int StatusNextStaticPattern2_film22=0;//,StatusNextStaticPattern2_film22_H1=0,StatusNextStaticPattern2_film22_H2=0,StatusNextStaticPattern2_film22_H3=0;
//unsigned int StatusNextStaticPattern2_film22_V1=0,StatusNextStaticPattern2_film22_V2=0,StatusNextStaticPattern2_film22_V3=0,StatusNextStaticPattern2_film22_C=0;

static unsigned int index32,index32_H1,index32_H2,index32_H3,index32_V1,index32_V2,index32_V3,index32_C;
static unsigned int stillpix_count32=0,stillpix_count32_H1=0,stillpix_count32_H2=0,stillpix_count32_H3=0,stillpix_count32_V1=0,stillpix_count32_V2=0,stillpix_count32_V3=0,stillpix_count32_C=0;
static unsigned char Status32Detected1=0,Status32Detected1_H1=0,Status32Detected1_H2=0,Status32Detected1_H3=0,Status32Detected1_V1=0,Status32Detected1_V2=0,Status32Detected1_V3=0,Status32Detected1_C=0;
static unsigned int Status32Sequence1,Status32Sequence1_H1,Status32Sequence1_H2,Status32Sequence1_H3,Status32Sequence1_V1,Status32Sequence1_V2,Status32Sequence1_V3,Status32Sequence1_C;

static unsigned int index322,index322_H1,index322_H2,index322_H3,index322_V1,index322_V2,index322_V3,index322_C;
static unsigned char Status32Detected2=0,Status32Detected2_H1=0,Status32Detected2_H2=0,Status32Detected2_H3=0,Status32Detected2_V1=0,Status32Detected2_V2=0,Status32Detected2_V3=0,Status32Detected2_C=0;
static unsigned int Status32Sequence2,Status32Sequence2_H1,Status32Sequence2_H2,Status32Sequence2_H3,Status32Sequence2_V1,Status32Sequence2_V2,Status32Sequence2_V3,Status32Sequence2_C;

static unsigned int index22,index22_H1,index22_H2,index22_H3,index22_V1,index22_V2,index22_V3,index22_C;
static unsigned int stillpix_count22=0,stillpix_count22_H1=0,stillpix_count22_H2=0,stillpix_count22_H3=0,stillpix_count22_V1=0,stillpix_count22_V2=0,stillpix_count22_V3=0,stillpix_count22_C=0;
static unsigned char Status22Detected=0,Status22Detected_H1=0,Status22Detected_H2=0,Status22Detected_H3=0,Status22Detected_V1=0,Status22Detected_V2=0,Status22Detected_V3=0,Status22Detected_C=0;
static unsigned int Status22Sequence,Status22Sequence_H1,Status22Sequence_H2,Status22Sequence_H3,Status22Sequence_V1,Status22Sequence_V2,Status22Sequence_V3,Status22Sequence_C;

static unsigned int Status32Detected1_cnt=0,Status32Detected1_H1_cnt=0,Status32Detected1_H2_cnt=0,Status32Detected1_H3_cnt=0;
static unsigned int Status32Detected1_V1_cnt=0,Status32Detected1_V2_cnt=0,Status32Detected1_V3_cnt=0,Status32Detected1_C_cnt=0;
static unsigned int Status32Detected2_cnt=0,Status32Detected2_H1_cnt=0,Status32Detected2_H2_cnt=0,Status32Detected2_H3_cnt=0;
static unsigned int Status32Detected2_V1_cnt=0,Status32Detected2_V2_cnt=0,Status32Detected2_V3_cnt=0,Status32Detected2_C_cnt=0;
static unsigned int Status22Detected_cnt=0,Status22Detected_H1_cnt=0,Status22Detected_H2_cnt=0,Status22Detected_H3_cnt=0;
static unsigned int Status22Detected_V1_cnt=0,Status22Detected_V2_cnt=0,Status22Detected_V3_cnt=0,Status22Detected_C_cnt=0;

static unsigned char MisMatch32=0, MisMatch22=0;
static unsigned char MixedFilmConfuse;

static unsigned char StatusFilmDetected=0;
static unsigned int StatusFilmSequence=0;
static unsigned char StatusMixedFilmDetected=0;
static unsigned int film_index=0;
static unsigned char fw_DI_3A;
static unsigned char force_weave_flag=0;
static unsigned char weave_prev;
static unsigned char NextTopDetected;
static unsigned char PrevTopDetected;
//unsigned char TopDetected_d;
static unsigned char PrevTopDetected_d;
static unsigned char NextTopDetected_d;
static unsigned int  TopLine, BotLine;
static unsigned int  TopLine2, BotLine2;
static unsigned int  TopLine3, BotLine3;

static unsigned int StatusFramePairPattern2=0,StatusFramePairPattern2_H1=0,StatusFramePairPattern2_H2=0,StatusFramePairPattern2_H3=0;
static unsigned int StatusFramePairPattern2_V1=0,StatusFramePairPattern2_V2=0,StatusFramePairPattern2_V3=0,StatusFramePairPattern2_C=0;

static unsigned int Film22_StatusNextStaticPattern_noH3=0;
static unsigned int New_Mcnr_Mv =0;

static int A22_StatusPrevDiffSum[8][8];
static int A22_StatusNextDiffSum[8][8];
static int* p22_StatusPrevDiffSum[8];
static int* p22_StatusNextDiffSum[8];
static int fw_di_film_sawtooth_comparePrevNext=0;
static unsigned int* StatusNextStaticPattern_film22_PTR[8];

int vc_di_film_getDiffSumRemap_isr(int x){
	// copy from experimental C-Model
	// You can adjust this curve in FW.
	int y=0;
	int k;
	int z;
	x=(x+0)>>3;// no round because bitnum issue
	for(k=0;k<4&&x>0;k++){
		z=x>32?32:x;// experimental registers, default 32
		y=y+z;
		x=(x-z)>>1;
	}
	return y+x;
}

#if 0
// R //
unsigned int R_film_StatusFrameStaticPattern=0,R_film_StatusFrameStaticPattern_H1=0,R_film_StatusFrameStaticPattern_H2=0,R_film_StatusFrameStaticPattern_H3=0;
unsigned int R_film_StatusFrameStaticPattern_V1=0,R_film_StatusFrameStaticPattern_V2=0,R_film_StatusFrameStaticPattern_V3=0,R_film_StatusFrameStaticPattern_C=0;
unsigned int R_film_StatusFramePairPattern=0,R_film_StatusFramePairPattern_H1=0,R_film_StatusFramePairPattern_H2=0,R_film_StatusFramePairPattern_H3=0;
unsigned int R_film_StatusFramePairPattern_V1=0,R_film_StatusFramePairPattern_V2=0,R_film_StatusFramePairPattern_V3=0,R_film_StatusFramePairPattern_C=0;
unsigned int R_film_StatusPrevStaticPattern=0,R_film_StatusPrevStaticPattern_H1=0,R_film_StatusPrevStaticPattern_H2=0,R_film_StatusPrevStaticPattern_H3=0;
unsigned int R_film_StatusPrevStaticPattern_V1=0,R_film_StatusPrevStaticPattern_V2=0,R_film_StatusPrevStaticPattern_V3=0,R_film_StatusPrevStaticPattern_C=0;
unsigned int R_film_StatusNextStaticPattern=0,R_film_StatusNextStaticPattern_H1=0,R_film_StatusNextStaticPattern_H2=0,R_film_StatusNextStaticPattern_H3=0;
unsigned int R_film_StatusNextStaticPattern_V1=0,R_film_StatusNextStaticPattern_V2=0,R_film_StatusNextStaticPattern_V3=0,R_film_StatusNextStaticPattern_C=0;
unsigned int R_film_StatusPrevStaticPattern2=0,R_film_StatusPrevStaticPattern2_H1=0,R_film_StatusPrevStaticPattern2_H2=0,R_film_StatusPrevStaticPattern2_H3=0;
unsigned int R_film_StatusPrevStaticPattern2_V1=0,R_film_StatusPrevStaticPattern2_V2=0,R_film_StatusPrevStaticPattern2_V3=0,R_film_StatusPrevStaticPattern2_C=0;
unsigned int R_film_StatusNextStaticPattern2=0,R_film_StatusNextStaticPattern2_H1=0,R_film_StatusNextStaticPattern2_H2=0,R_film_StatusNextStaticPattern2_H3=0;
unsigned int R_film_StatusNextStaticPattern2_V1=0,R_film_StatusNextStaticPattern2_V2=0,R_film_StatusNextStaticPattern2_V3=0,R_film_StatusNextStaticPattern2_C=0;
unsigned int R_film22_StatusNextStaticPattern=0,R_film22_StatusNextStaticPattern_H1=0,R_film22_StatusNextStaticPattern_H2=0,R_film22_StatusNextStaticPattern_H3=0;
unsigned int R_film22_StatusNextStaticPattern_V1=0,R_film22_StatusNextStaticPattern_V2=0,R_film22_StatusNextStaticPattern_V3=0,R_film22_StatusNextStaticPattern_C=0;

unsigned int R_film_index32=0,R_film_index32_H1=0,R_film_index32_H2=0,R_film_index32_H3=0,R_film_index32_V1=0,R_film_index32_V2=0,R_film_index32_V3=0,R_film_index32_C=0;
//unsigned int R_film_stillpix_count32=0,R_film_stillpix_count32_H1=0,R_film_stillpix_count32_H2=0,R_film_stillpix_count32_H3=0,R_film_stillpix_count32_V1=0,R_film_stillpix_count32_V2=0,R_film_stillpix_count32_V3=0,R_film_stillpix_count32_C=0;
unsigned char R_film_Status32Detected1=0,R_film_Status32Detected1_H1=0,R_film_Status32Detected1_H2=0,R_film_Status32Detected1_H3=0,R_film_Status32Detected1_V1=0,R_film_Status32Detected1_V2=0,R_film_Status32Detected1_V3=0,R_film_Status32Detected1_C=0;
unsigned int R_film_Status32Sequence1=0,R_film_Status32Sequence1_H1=0,R_film_Status32Sequence1_H2=0,R_film_Status32Sequence1_H3=0,R_film_Status32Sequence1_V1=0,R_film_Status32Sequence1_V2=0,R_film_Status32Sequence1_V3=0,R_film_Status32Sequence1_C=0;

unsigned int R_film_index322=0,R_film_index322_H1=0,R_film_index322_H2=0,R_film_index322_H3=0,R_film_index322_V1=0,R_film_index322_V2=0,R_film_index322_V3=0,R_film_index322_C=0;
unsigned char R_film_Status32Detected2=0,R_film_Status32Detected2_H1=0,R_film_Status32Detected2_H2=0,R_film_Status32Detected2_H3=0,R_film_Status32Detected2_V1=0,R_film_Status32Detected2_V2=0,R_film_Status32Detected2_V3=0,R_film_Status32Detected2_C=0;
unsigned int R_film_Status32Sequence2=0,R_film_Status32Sequence2_H1=0,R_film_Status32Sequence2_H2=0,R_film_Status32Sequence2_H3=0,R_film_Status32Sequence2_V1=0,R_film_Status32Sequence2_V2=0,R_film_Status32Sequence2_V3=0,R_film_Status32Sequence2_C=0;

unsigned int R_film_index22=0,R_film_index22_H1=0,R_film_index22_H2=0,R_film_index22_H3=0,R_film_index22_V1=0,R_film_index22_V2=0,R_film_index22_V3=0,R_film_index22_C=0;
//unsigned int R_film_stillpix_count22=0,R_film_stillpix_count22_H1=0,R_film_stillpix_count22_H2=0,R_film_stillpix_count22_H3=0,R_film_stillpix_count22_V1=0,R_film_stillpix_count22_V2=0,R_film_stillpix_count22_V3=0,R_film_stillpix_count22_C=0;
unsigned char R_film_Status22Detected=0,R_film_Status22Detected_H1=0,R_film_Status22Detected_H2=0,R_film_Status22Detected_H3=0,R_film_Status22Detected_V1=0,R_film_Status22Detected_V2=0,R_film_Status22Detected_V3=0,R_film_Status22Detected_C=0;
unsigned int R_film_Status22Sequence=0,R_film_Status22Sequence_H1=0,R_film_Status22Sequence_H2=0,R_film_Status22Sequence_H3=0,R_film_Status22Sequence_V1=0,R_film_Status22Sequence_V2=0,R_film_Status22Sequence_V3=0,R_film_Status22Sequence_C=0;

unsigned int R_Status32Detected1_cnt=0,R_Status32Detected1_H1_cnt=0,R_Status32Detected1_H2_cnt=0,R_Status32Detected1_H3_cnt=0;
unsigned int R_Status32Detected1_V1_cnt=0,R_Status32Detected1_V2_cnt=0,R_Status32Detected1_V3_cnt=0,R_Status32Detected1_C_cnt=0;
unsigned int R_Status32Detected2_cnt=0,R_Status32Detected2_H1_cnt=0,R_Status32Detected2_H2_cnt=0,R_Status32Detected2_H3_cnt=0;
unsigned int R_Status32Detected2_V1_cnt=0,R_Status32Detected2_V2_cnt=0,R_Status32Detected2_V3_cnt=0,R_Status32Detected2_C_cnt=0;
unsigned int R_Status22Detected_cnt=0,R_Status22Detected_H1_cnt=0,R_Status22Detected_H2_cnt=0,R_Status22Detected_H3_cnt=0;
unsigned int R_Status22Detected_V1_cnt=0,R_Status22Detected_V2_cnt=0,R_Status22Detected_V3_cnt=0,R_Status22Detected_C_cnt=0;

unsigned char R_film_StatusFilmDetected=0;
unsigned int R_film_StatusFilmSequence=0;
unsigned char R_StatusMixedFilmDetected=0;
unsigned int R_film_index=0;
unsigned char R_force_weave_flag=0;
unsigned char R_weave_prev=0;
unsigned char R_NextTopDetected=0;
unsigned char R_PrevTopDetected=0;
unsigned char R_PrevTopDetected_d=0;
unsigned char R_NextTopDetected_d=0;
unsigned int  R_TopLine=0, R_BotLine=0;
unsigned int  R_TopLine2=0, R_BotLine2=0;
unsigned int  R_TopLine3=0, R_BotLine3=0;

// L //
unsigned int L_film_StatusFrameStaticPattern=0,L_film_StatusFrameStaticPattern_H1=0,L_film_StatusFrameStaticPattern_H2=0,L_film_StatusFrameStaticPattern_H3=0;
unsigned int L_film_StatusFrameStaticPattern_V1=0,L_film_StatusFrameStaticPattern_V2=0,L_film_StatusFrameStaticPattern_V3=0,L_film_StatusFrameStaticPattern_C=0;
unsigned int L_film_StatusFramePairPattern=0,L_film_StatusFramePairPattern_H1=0,L_film_StatusFramePairPattern_H2=0,L_film_StatusFramePairPattern_H3=0;
unsigned int L_film_StatusFramePairPattern_V1=0,L_film_StatusFramePairPattern_V2=0,L_film_StatusFramePairPattern_V3=0,L_film_StatusFramePairPattern_C=0;
unsigned int L_film_StatusPrevStaticPattern=0,L_film_StatusPrevStaticPattern_H1=0,L_film_StatusPrevStaticPattern_H2=0,L_film_StatusPrevStaticPattern_H3=0;
unsigned int L_film_StatusPrevStaticPattern_V1=0,L_film_StatusPrevStaticPattern_V2=0,L_film_StatusPrevStaticPattern_V3=0,L_film_StatusPrevStaticPattern_C=0;
unsigned int L_film_StatusNextStaticPattern=0,L_film_StatusNextStaticPattern_H1=0,L_film_StatusNextStaticPattern_H2=0,L_film_StatusNextStaticPattern_H3=0;
unsigned int L_film_StatusNextStaticPattern_V1=0,L_film_StatusNextStaticPattern_V2=0,L_film_StatusNextStaticPattern_V3=0,L_film_StatusNextStaticPattern_C=0;
unsigned int L_film_StatusPrevStaticPattern2=0,L_film_StatusPrevStaticPattern2_H1=0,L_film_StatusPrevStaticPattern2_H2=0,L_film_StatusPrevStaticPattern2_H3=0;
unsigned int L_film_StatusPrevStaticPattern2_V1=0,L_film_StatusPrevStaticPattern2_V2=0,L_film_StatusPrevStaticPattern2_V3=0,L_film_StatusPrevStaticPattern2_C=0;
unsigned int L_film_StatusNextStaticPattern2=0,L_film_StatusNextStaticPattern2_H1=0,L_film_StatusNextStaticPattern2_H2=0,L_film_StatusNextStaticPattern2_H3=0;
unsigned int L_film_StatusNextStaticPattern2_V1=0,L_film_StatusNextStaticPattern2_V2=0,L_film_StatusNextStaticPattern2_V3=0,L_film_StatusNextStaticPattern2_C=0;
unsigned int L_film22_StatusNextStaticPattern=0,L_film22_StatusNextStaticPattern_H1=0,L_film22_StatusNextStaticPattern_H2=0,L_film22_StatusNextStaticPattern_H3=0;
unsigned int L_film22_StatusNextStaticPattern_V1=0,L_film22_StatusNextStaticPattern_V2=0,L_film22_StatusNextStaticPattern_V3=0,L_film22_StatusNextStaticPattern_C=0;

unsigned int L_film_index32=0,L_film_index32_H1=0,L_film_index32_H2=0,L_film_index32_H3=0,L_film_index32_V1=0,L_film_index32_V2=0,L_film_index32_V3=0,L_film_index32_C=0;
//unsigned int L_film_stillpix_count32=0,L_film_stillpix_count32_H1=0,L_film_stillpix_count32_H2=0,L_film_stillpix_count32_H3=0,L_film_stillpix_count32_V1=0,L_film_stillpix_count32_V2=0,L_film_stillpix_count32_V3=0,L_film_stillpix_count32_C=0;
unsigned char L_film_Status32Detected1=0,L_film_Status32Detected1_H1=0,L_film_Status32Detected1_H2=0,L_film_Status32Detected1_H3=0,L_film_Status32Detected1_V1=0,L_film_Status32Detected1_V2=0,L_film_Status32Detected1_V3=0,L_film_Status32Detected1_C=0;
unsigned int L_film_Status32Sequence1=0,L_film_Status32Sequence1_H1=0,L_film_Status32Sequence1_H2=0,L_film_Status32Sequence1_H3=0,L_film_Status32Sequence1_V1=0,L_film_Status32Sequence1_V2=0,L_film_Status32Sequence1_V3=0,L_film_Status32Sequence1_C=0;

unsigned int L_film_index322=0,L_film_index322_H1=0,L_film_index322_H2=0,L_film_index322_H3=0,L_film_index322_V1=0,L_film_index322_V2=0,L_film_index322_V3=0,L_film_index322_C=0;
unsigned char L_film_Status32Detected2=0,L_film_Status32Detected2_H1=0,L_film_Status32Detected2_H2=0,L_film_Status32Detected2_H3=0,L_film_Status32Detected2_V1=0,L_film_Status32Detected2_V2=0,L_film_Status32Detected2_V3=0,L_film_Status32Detected2_C=0;
unsigned int L_film_Status32Sequence2=0,L_film_Status32Sequence2_H1=0,L_film_Status32Sequence2_H2=0,L_film_Status32Sequence2_H3=0,L_film_Status32Sequence2_V1=0,L_film_Status32Sequence2_V2=0,L_film_Status32Sequence2_V3=0,L_film_Status32Sequence2_C=0;

unsigned int L_film_index22=0,L_film_index22_H1=0,L_film_index22_H2=0,L_film_index22_H3=0,L_film_index22_V1=0,L_film_index22_V2=0,L_film_index22_V3=0,L_film_index22_C=0;
//unsigned int L_film_stillpix_count22=0,L_film_stillpix_count22_H1=0,L_film_stillpix_count22_H2=0,L_film_stillpix_count22_H3=0,L_film_stillpix_count22_V1=0,L_film_stillpix_count22_V2=0,L_film_stillpix_count22_V3=0,L_film_stillpix_count22_C=0;
unsigned char L_film_Status22Detected=0,L_film_Status22Detected_H1=0,L_film_Status22Detected_H2=0,L_film_Status22Detected_H3=0,L_film_Status22Detected_V1=0,L_film_Status22Detected_V2=0,L_film_Status22Detected_V3=0,L_film_Status22Detected_C=0;
unsigned int L_film_Status22Sequence=0,L_film_Status22Sequence_H1=0,L_film_Status22Sequence_H2=0,L_film_Status22Sequence_H3=0,L_film_Status22Sequence_V1=0,L_film_Status22Sequence_V2=0,L_film_Status22Sequence_V3=0,L_film_Status22Sequence_C=0;

unsigned int L_Status32Detected1_cnt=0,L_Status32Detected1_H1_cnt=0,L_Status32Detected1_H2_cnt=0,L_Status32Detected1_H3_cnt=0;
unsigned int L_Status32Detected1_V1_cnt=0,L_Status32Detected1_V2_cnt=0,L_Status32Detected1_V3_cnt=0,L_Status32Detected1_C_cnt=0;
unsigned int L_Status32Detected2_cnt=0,L_Status32Detected2_H1_cnt=0,L_Status32Detected2_H2_cnt=0,L_Status32Detected2_H3_cnt=0;
unsigned int L_Status32Detected2_V1_cnt=0,L_Status32Detected2_V2_cnt=0,L_Status32Detected2_V3_cnt=0,L_Status32Detected2_C_cnt=0;
unsigned int L_Status22Detected_cnt=0,L_Status22Detected_H1_cnt=0,L_Status22Detected_H2_cnt=0,L_Status22Detected_H3_cnt=0;
unsigned int L_Status22Detected_V1_cnt=0,L_Status22Detected_V2_cnt=0,L_Status22Detected_V3_cnt=0,L_Status22Detected_C_cnt=0;

unsigned char L_film_StatusFilmDetected=0;
unsigned int L_film_StatusFilmSequence=0;
unsigned char L_StatusMixedFilmDetected=0;
unsigned int L_film_index=0;
unsigned char L_force_weave_flag=0;
unsigned char L_weave_prev=0;
unsigned char L_NextTopDetected=0;
unsigned char L_PrevTopDetected=0;
unsigned char L_PrevTopDetected_d=0;
unsigned char L_NextTopDetected_d=0;
unsigned int  L_TopLine=0, L_BotLine=0;
unsigned int  L_TopLine2=0, L_BotLine2=0;
unsigned int  L_TopLine3=0, L_BotLine3=0;
#endif
// fw film mode end ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

unsigned char scalerVIP_DI_InArray(unsigned int array[], unsigned int length, unsigned int x)
{
	unsigned int i;

	for (i=0; i<length; i++)
	{
		if (array[i] == x)
			return 1;
	}

	return 0;
}

void scalerVIP_DI_MiddleWare_StatusInit(VIP_SOURCE_TIMING cur_vip_source)
{
	unsigned int i;

	di_im_di_active_window_control_RBUS di_active_window_control_reg;
	di_im_di_weave_window_control_RBUS di_weave_window_control_reg;
	di_im_di_rtnr_control_RBUS im_di_rtnr_control_reg;

	im_di_rtnr_control_reg.regValue = rtd_inl(DI_IM_DI_RTNR_CONTROL_reg);
	di_active_window_control_reg.regValue = rtd_inl(DI_IM_DI_ACTIVE_WINDOW_CONTROL_reg);
	di_weave_window_control_reg.regValue = rtd_inl(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg);

	Smart_Integration_Status.DI_HEIGHT = ((di_weave_window_control_reg.vsize_msb<<10)+di_active_window_control_reg.vsize);
	Smart_Integration_Status.DI_WIDTH = ((di_weave_window_control_reg.hsize_msb<<11)+di_active_window_control_reg.hsize);
	Smart_Integration_Status.Mode_Progressive = im_di_rtnr_control_reg.cp_rtnr_progressive;

	if (Smart_Integration_Status.DI_HEIGHT == 0) {
		Smart_Integration_Status.DI_HEIGHT = 540;
		if (Smart_Integration_Status.SCREEN_HMCNR_STATUS.Show_Debug_MSG)
			VIP_DEBUG_PRINTF("[SIS HMCNR] Error : DI_HEIGHT is zero!!\n");
	}
	if (Smart_Integration_Status.DI_WIDTH == 0) {
		if (Smart_Integration_Status.SCREEN_HMCNR_STATUS.Show_Debug_MSG)
			VIP_DEBUG_PRINTF("[SIS HMCNR] Error : DI_WIDTH is zero!!\n");
		Smart_Integration_Status.DI_WIDTH= 1920;
	}

	if (Smart_Integration_Status.Vip_Source_Timing != cur_vip_source || SIS_INIT == 0) // only initial on vip change source
	{
		VIP_DEBUG_PRINTF("[SIS INIT] %dx%d VIP SOURCE UPDATE : %d -> %d\n", Smart_Integration_Status.DI_WIDTH, Smart_Integration_Status.DI_HEIGHT, Smart_Integration_Status.Vip_Source_Timing, cur_vip_source);

		// initial all status
		for (i=0; i<HMC_BIN_COUNT; i++)
		{
			Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[i] = 0;
			Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Rank[i] = 0;
		}

		Smart_Integration_Status.SCREEN_SCENECHANGE_STATUS.pass_ratio = 64;
		Smart_Integration_Status.SCREEN_SCENECHANGE_STATUS.pass_couter = 6;

		Smart_Integration_Status.Vip_Source_Timing = cur_vip_source;
		SIS_INIT = 1;

		// hmcnr testing, this code is temporal, must remove when release.
		di_im_di_hmc_pan_control_RBUS di_im_di_hmc_pan_control_reg;
		di_im_di_hmc_pan_control_reg.regValue = rtd_inl(DI_IM_DI_HMC_PAN_CONTROL_reg);
		switch(Smart_Integration_Status.Vip_Source_Timing)
		{
			case VIP_QUALITY_CVBS_NTSC:
			case VIP_QUALITY_CVBS_PAL:
			case VIP_QUALITY_YPbPr_480I:
			case VIP_QUALITY_YPbPr_576I:
			case VIP_QUALITY_HDMI_480I:
			case VIP_QUALITY_HDMI_576I:
				di_im_di_hmc_pan_control_reg.dummy18024660_31_24 = 0x8f; // SD disalbe all
				break;

			case VIP_QUALITY_HDMI_1080I:
				di_im_di_hmc_pan_control_reg.dummy18024660_31_24 = 0x8f; // (1100 1111) hmcnr_fw_en / mv_modify_en / mv_avg_count = 15
				break;

			default:
				di_im_di_hmc_pan_control_reg.dummy18024660_31_24 = 0x0; // SD disalbe all
				break;
		}
		rtd_outl(DI_IM_DI_HMC_PAN_CONTROL_reg, di_im_di_hmc_pan_control_reg.regValue);
	}

}

void scalerVIP_DI_MiddleWare_HistUpdate(unsigned int *HistCnt)
{
	unsigned char i=0;
	for (i=0; i<HISTOGRAM_SIZE; i++)
		Smart_Integration_Status.Y_Histogram[i] = HistCnt[i];
}

void scalerVIP_DI_MiddleWare_ProfileUpdate(unsigned short h_block[16], unsigned short v_block[16])
{
	unsigned char i=0;
	for (i=0; i<PROFILE_SIZE; i++)
	{
		Smart_Integration_Status.Y_H_Block[i] = h_block[i];
		Smart_Integration_Status.Y_V_Block[i] = v_block[i];
	}
}

void scalerVIP_DI_MiddleWare_StatusUpdate()
{
	if (Smart_Integration_Status.Frame_Couter > 10000)
		Smart_Integration_Status.Frame_Couter = 0;
	else
		Smart_Integration_Status.Frame_Couter++;

	scalerVIP_DI_MOTION_StatusUpdate();
	scalerVIP_DI_HMC_StatusUpdate();
	scalerVIP_DI_HMC_Continue();
	scalerVIP_DI_PAN_HistSwitch();
	scalerVIP_DI_PAN_StatusUpdate();
	scalerVIP_DI_VPAN_StatusUpdate();
	scalerVIP_DI_SPAN_StatusUpdate();
	scalerVIP_DI_ZOOMMOTION_StatusUpdate();
	//scalerVIP_DI_SLOWMOTION_StatusUpdate(); //rord.tsao mark 2015/07/10
	scalerVIP_DI_SCENECHANGE_StatusUpdate();
	//scalerVIP_DI_FADING_StatusUpdate();
	scalerVIP_DI_HIGHFREQUENCY_StatusUpdate();
	scalerVIP_NOISE_LEVEL_StatusUpdate();
	scalerVIP_DI_FILM_StatusUpdate();
	scalerVIP_DI_SMD_StautsUpdate();
}

unsigned int scalerVIP_DI_MiddleWare_GetStatus(SIS_STATUS access)
{
	unsigned int status = 0;

	if (access == STATUS_MOTION)
	{
		status = Smart_Integration_Status.SCREEN_MOTION_STATUS.MOTION_LEVEL;
	}
	else if (access == STATUS_HMC)
	{
		status = Smart_Integration_Status.SCREEN_ACTION_STATUS.HMC_detect;
	}
	else if (access == STATUS_HMC_HIST)
	{
		status = Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram_flag;
	}
	else if (access == STATUS_PAN)
	{
		status = Smart_Integration_Status.SCREEN_ACTION_STATUS.PAN_detect;
	}
	else if (access == STATUS_PAN_STR)
	{
		status = Smart_Integration_Status.SCREEN_ACTION_STATUS.PAN_detect_str;
	}
	else if (access == STATUS_PAN_LEVEL)
	{
		if (Smart_Integration_Status.SCREEN_ACTION_STATUS.PAN_detect_str == 1)
			status = Smart_Integration_Status.SCREEN_HPAN_STATUS.Mv_Result_Sequence[0];//Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Rank[0]; // return 16 = mv zero
		else
			status = 16;
	}
	else if (access == STATUS_VPAN)
	{
		status = Smart_Integration_Status.SCREEN_ACTION_STATUS.VPAN_detect;
	}
	else if (access == STATUS_SPAN)
	{
		status = Smart_Integration_Status.SCREEN_ACTION_STATUS.SPAN_detect;
	}
	else if (access == STATUS_HMCNR)
	{
		status = Smart_Integration_Status.SCREEN_ACTION_STATUS.HMCNR_detect;
	}
	else if (access == STATUS_ZOOMMOTION)
	{
		status = Smart_Integration_Status.SCREEN_ACTION_STATUS.ZOOMMOTION_detect;
	}
	else if (access == STATUS_SLOWMOTION)
	{
		status = Smart_Integration_Status.SCREEN_ACTION_STATUS.SLOWMOTION_detect;
	}
	else if (access == STATUS_SCENECHANGE)
	{
		status = Smart_Integration_Status.SCREEN_ACTION_STATUS.SCENECHANGE_detect;
	}
	else if (access == STATUS_FADING)
	{
		status = Smart_Integration_Status.SCREEN_ACTION_STATUS.FADING_detect;
	}
	else if (access == STATUS_HIGHFREQUENCY)
	{
		status = Smart_Integration_Status.SCREEN_ACTION_STATUS.HIGHFREQUENCY_detect;
	}
	else if (access == STATUS_HIGHFREQUENCY_LEVEL)
	{
		status = Smart_Integration_Status.SCREEN_HIGHFREQUENCY_STATUS.Pass_Result_FIR;
	}
	else if (access == STATUS_FILM)
	{
		status = Smart_Integration_Status.SCREEN_ACTION_STATUS.FILM_detect;
	}
	else if (access == STATUS_BLACKWHITE)
	{
		status = Smart_Integration_Status.SCREEN_ACTION_STATUS.BLACKWHITE_detect;
	}
	else if (access == STATUS_SATURATION)
	{
		status = Smart_Integration_Status.SCREEN_ACTION_STATUS.SATURATION_detect;
	}
	else if (access == STATUS_NOISE)
	{
		status = MAX(Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_SPATIAL_NOISE.RESULT_NOISE_LEVEL, Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_TEMPORAL_NOISE.RESULT_NOISE_LEVEL);
		status = MAX(Smart_Integration_Status.SCREEN_NOISE_STATUS.VD_SIGNAL_NOISE_LEVEL, status);
	}
	else if (access == STATUS_CONTENT_SPATIAL_NOISE_LEVEL)
	{
		status = Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_SPATIAL_NOISE.RESULT_NOISE_LEVEL;
	}
	else if (access == STATUS_CONTENT_SPATIAL_NOISE_LEVEL_RELIABLE)
	{
		status = Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_SPATIAL_NOISE.RESULT_NOISE_LEVEL_RELIABLE;
	}
	else if (access == STATUS_CONTENT_TEMPORAL_NOISE_LEVEL)
	{
		status = Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_TEMPORAL_NOISE.RESULT_NOISE_LEVEL;
	}
	else if (access == STATUS_CONTENT_TEMPORAL_NOISE_RELIABLE)
	{
		status = Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_TEMPORAL_NOISE.RESULT_NOISE_RELIABLE;
	}
	else if (access == STATUS_STILL_CONCENTRIC_CIRCLES)
	{
		status = Smart_Integration_Status.SCREEN_SPECIAL_STATUS.STILL_CONCENTRIC_CIRCLES_detect;
	}
	else if (access == STATUS_CUSTOMER_HMC_VMC)
	{
		status = Smart_Integration_Status.SCREEN_SPECIAL_STATUS.CUSTOMER_HMC_VMC_detect;
	}
	else if (access == STATUS_MOVING_CAN)
	{
		status = Smart_Integration_Status.SCREEN_SPECIAL_STATUS.MOVING_CAN_detect;
	}

	else if (access == STATUS_PAN_SPECIAL_CASE)
	{
		status = Smart_Integration_Status.SCREEN_HPAN_STATUS.Pen_special_case;
	}




	return status;
}

void scalerVIP_DI_MiddleWare_SetStatus(SIS_STATUS access, unsigned char status)
{
	if (access == STATUS_FADING)
	{
		Smart_Integration_Status.SCREEN_ACTION_STATUS.FADING_detect = status;
	}
	else if (access == STATUS_STILL_CONCENTRIC_CIRCLES)
	{
		Smart_Integration_Status.SCREEN_SPECIAL_STATUS.STILL_CONCENTRIC_CIRCLES_detect = status;
	}
	else if (access == STATUS_CUSTOMER_HMC_VMC)
	{
		Smart_Integration_Status.SCREEN_SPECIAL_STATUS.CUSTOMER_HMC_VMC_detect = status;
	}
	else if (access == STATUS_MOVING_CAN)
	{
		Smart_Integration_Status.SCREEN_SPECIAL_STATUS.MOVING_CAN_detect = status;
	}
}

void scalerVIP_DI_MiddleWare_DebugMode(SIS_STATUS access, unsigned char timer)
{
	if (access == STATUS_MOTION)
	{
		if (timer != 0 && Smart_Integration_Status.Frame_Couter % timer == 0)
		{
			Smart_Integration_Status.SCREEN_MOTION_STATUS.Show_Debug_MSG = 1;
		}
		else
		{
			Smart_Integration_Status.SCREEN_MOTION_STATUS.Show_Debug_MSG = 0;
		}
	}
	else if (access == STATUS_HMC)
	{
		if (timer != 0 && Smart_Integration_Status.Frame_Couter % timer == 0)
		{
			Smart_Integration_Status.SCREEN_HMC_STATUS.Show_Debug_MSG = 1;
		}
		else
		{
			Smart_Integration_Status.SCREEN_HMC_STATUS.Show_Debug_MSG = 0;
		}
	}
	else if (access == STATUS_PAN)
	{
		if (timer != 0 && Smart_Integration_Status.Frame_Couter % timer == 0)
		{
			Smart_Integration_Status.SCREEN_HPAN_STATUS.Show_Debug_MSG = 1;
		}
		else
		{
			Smart_Integration_Status.SCREEN_HPAN_STATUS.Show_Debug_MSG = 0;
		}
	}
	else if (access == STATUS_SPAN)
	{
		if (timer != 0 && Smart_Integration_Status.Frame_Couter % timer == 0)
		{
			Smart_Integration_Status.SCREEN_SPAN_STATUS.Show_Debug_MSG = 1;
		}
		else
		{
			Smart_Integration_Status.SCREEN_SPAN_STATUS.Show_Debug_MSG = 0;
		}
	}
	else if (access == STATUS_HMCNR)
	{
		if (timer != 0 && Smart_Integration_Status.Frame_Couter % timer == 0)
		{
			Smart_Integration_Status.SCREEN_HMCNR_STATUS.Show_Debug_MSG = 1;
		}
		else
		{
			Smart_Integration_Status.SCREEN_HMCNR_STATUS.Show_Debug_MSG = 0;
		}
	}
	else if (access == STATUS_NOISE)
	{
		if (timer != 0 && Smart_Integration_Status.Frame_Couter % timer == 0)
		{
			Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_SPATIAL_NOISE.Show_Debug_MSG = 1;
			Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_TEMPORAL_NOISE.Show_Debug_MSG = 1;
		}
		else
		{
			Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_SPATIAL_NOISE.Show_Debug_MSG = 0;
			Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_TEMPORAL_NOISE.Show_Debug_MSG = 0;
		}
	}
	else if (access == STATUS_SLOWMOTION)
	{
		if (timer != 0 && Smart_Integration_Status.Frame_Couter % timer == 0)
		{
			Smart_Integration_Status.SCREEN_SLOWMOTION_STATUS.Show_Debug_MSG = 1;
		}
		else
		{
			Smart_Integration_Status.SCREEN_SLOWMOTION_STATUS.Show_Debug_MSG = 0;
		}
	}
	else if (access == STATUS_SCENECHANGE)
	{
		if (timer != 0 && Smart_Integration_Status.Frame_Couter % timer == 0)
		{
			Smart_Integration_Status.SCREEN_SCENECHANGE_STATUS.Show_Debug_MSG = 1;
		}
		else
		{
			Smart_Integration_Status.SCREEN_SCENECHANGE_STATUS.Show_Debug_MSG = 0;
		}
	}
	else if (access == STATUS_SMD)
	{
		if (timer != 0 && Smart_Integration_Status.Frame_Couter % timer == 0)
		{
			Smart_Integration_Status.SCREEN_SMD_STATUS.Show_Debug_MSG = 1;
		}
		else
		{
			Smart_Integration_Status.SCREEN_SMD_STATUS.Show_Debug_MSG = 0;
		}
	}
}

void scalerVIP_DI_MiddleWare_HMC_Apply()
{
	di_im_di_hmc_statistic1_RBUS hmc_statistic1_reg;
	di_im_di_control_RBUS di_control_reg;
	di_im_di_hmc_me_refine_ctrl_2_RBUS di_hmc_me_refine_ctrl2_reg;

/*
	int th_start = 1500, th_remain = 0, th_step = 0, lineratio = 0;

	di_im_di_si_film_final_result_RBUS film_final_result_reg;
	film_final_result_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_FINAL_RESULT_reg);
	th_step = film_final_result_reg.dummy180240c4_31_9;

	hmc_statistic1_reg.regValue = rtd_inl(DI_IM_DI_HMC_STATISTIC1_reg);

	th_remain = Smart_Integration_Status.SCREEN_HMC_STATUS.Cur_Top5_Total-th_start;
	if (th_remain<0)
		th_remain = 0;
	lineratio = 12-(th_remain>>th_step);
	if (lineratio < 0)
		lineratio = 1;
	hmc_statistic1_reg.ma_hmc_lineratio = lineratio;
*/
	di_control_reg.regValue = rtd_inl(DI_IM_DI_CONTROL_reg);
	hmc_statistic1_reg.regValue = rtd_inl(DI_IM_DI_HMC_STATISTIC1_reg);
	di_hmc_me_refine_ctrl2_reg.regValue = rtd_inl(DI_IM_DI_HMC_ME_REFINE_CTRL_2_reg);

	unsigned char cur_source=0;
	cur_source=(RPC_system_info_structure_table->VIP_source);

	if((cur_source == VIP_QUALITY_HDMI_576I )||(cur_source == VIP_QUALITY_YPbPr_576I)) // for 576i need more time to enter pan
	{

		if (Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total < 40 || Smart_Integration_Status.SCREEN_ACTION_STATUS.FILM_detect == 1)
		{
			di_hmc_me_refine_ctrl2_reg.hmc_fw_ctrl_bypass = 1;
			hmc_statistic1_reg.ma_hmc_lineratio = 0;
		}
		else if (Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total >= 40 && Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total < 50)
		{
			di_hmc_me_refine_ctrl2_reg.hmc_fw_ctrl_bypass = 0;
			hmc_statistic1_reg.ma_hmc_lineratio = 1;
		}
		else if (Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total >= 50 && Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total < 60)
		{
			di_hmc_me_refine_ctrl2_reg.hmc_fw_ctrl_bypass = 0;
			hmc_statistic1_reg.ma_hmc_lineratio = 2;
		}
		else if (Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total >= 60 && Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total < 70)
		{
			di_hmc_me_refine_ctrl2_reg.hmc_fw_ctrl_bypass = 0;
			hmc_statistic1_reg.ma_hmc_lineratio = 3;
		}
		else if (Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total >= 70 && Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total < 80)
		{
			di_hmc_me_refine_ctrl2_reg.hmc_fw_ctrl_bypass = 0;
			hmc_statistic1_reg.ma_hmc_lineratio = 4;
		}
		else if (Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total >= 80 && Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total < 90)
		{
			di_hmc_me_refine_ctrl2_reg.hmc_fw_ctrl_bypass = 0;
			hmc_statistic1_reg.ma_hmc_lineratio = 5;
		}
		else if (Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total >= 90 && Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total < 100)
		{
			di_hmc_me_refine_ctrl2_reg.hmc_fw_ctrl_bypass = 0;
			hmc_statistic1_reg.ma_hmc_lineratio = 6;
		}
		else if (Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total > 100)
		{
			di_hmc_me_refine_ctrl2_reg.hmc_fw_ctrl_bypass = 0;
			hmc_statistic1_reg.ma_hmc_lineratio = 7;

			if(Smart_Integration_Status.SCREEN_ACTION_STATUS.PAN_detect_str && Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram_flag)
				hmc_statistic1_reg.ma_hmc_lineratio = 8;	//	for sony window pan	if pan teeth enable(avoid OSD teeth)->HMc must compensate all missing pixels

		}

	}
	else
	{

		if (Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total < 40 || Smart_Integration_Status.SCREEN_ACTION_STATUS.FILM_detect == 1)
		{
      			di_hmc_me_refine_ctrl2_reg.hmc_fw_ctrl_bypass = 1;
			hmc_statistic1_reg.ma_hmc_lineratio = 0;
		}
		else if (Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total >= 40 && Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total < 50)
		{
      			di_hmc_me_refine_ctrl2_reg.hmc_fw_ctrl_bypass = 0;
			hmc_statistic1_reg.ma_hmc_lineratio = 1;//3;
		}
		else if (Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total >= 50 && Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total < 60)
		{
			di_hmc_me_refine_ctrl2_reg.hmc_fw_ctrl_bypass = 0;
			hmc_statistic1_reg.ma_hmc_lineratio = 2;//6;
		}
		else if (Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total >= 60 && Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total < 70)
		{
			di_hmc_me_refine_ctrl2_reg.hmc_fw_ctrl_bypass = 0;
			hmc_statistic1_reg.ma_hmc_lineratio = 4;//8;
		}
		else if (Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total >= 70 && Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total < 80)
		{
			di_hmc_me_refine_ctrl2_reg.hmc_fw_ctrl_bypass = 0;
			hmc_statistic1_reg.ma_hmc_lineratio = 6;//12;
		}
		else if (Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total >= 80 && Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total < 90)
		{
			di_hmc_me_refine_ctrl2_reg.hmc_fw_ctrl_bypass = 0;
			hmc_statistic1_reg.ma_hmc_lineratio = 8;//24;
		}
		else if (Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total >= 90 && Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total < 100)
		{
			di_hmc_me_refine_ctrl2_reg.hmc_fw_ctrl_bypass = 0;
			hmc_statistic1_reg.ma_hmc_lineratio = 10;//36;
		}
		else if (Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total > 100)
		{
			di_hmc_me_refine_ctrl2_reg.hmc_fw_ctrl_bypass = 0;
			hmc_statistic1_reg.ma_hmc_lineratio = 12;//48;

			if(Smart_Integration_Status.SCREEN_ACTION_STATUS.PAN_detect_str && Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram_flag)
				hmc_statistic1_reg.ma_hmc_lineratio = 72;	//	for sony window pan	if pan teeth enable(avoid OSD teeth)->HMc must compensate all missing pixels

		}

	}
	//170711 henry for sony pan evaluation
	if(Scaler_access_Project_TV002_Style(0, 0) == 1)
	{
		if (Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total < 40 || Smart_Integration_Status.SCREEN_ACTION_STATUS.FILM_detect == 1)
		{
			di_hmc_me_refine_ctrl2_reg.hmc_fw_ctrl_bypass = 1;
			hmc_statistic1_reg.ma_hmc_lineratio = 0;
		}
		else if (Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total >= 40 && Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total < 50)
		{
			di_hmc_me_refine_ctrl2_reg.hmc_fw_ctrl_bypass = 0;
			hmc_statistic1_reg.ma_hmc_lineratio = 1;
		}
		else if (Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total >= 50 && Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total < 60)
		{
			di_hmc_me_refine_ctrl2_reg.hmc_fw_ctrl_bypass = 0;
			hmc_statistic1_reg.ma_hmc_lineratio = 6;
		}
		else if (Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total >= 60 && Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total < 70)
		{
			di_hmc_me_refine_ctrl2_reg.hmc_fw_ctrl_bypass = 0;
			hmc_statistic1_reg.ma_hmc_lineratio = 6;
		}
		else if (Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total >= 70 && Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total < 80)
		{
			di_hmc_me_refine_ctrl2_reg.hmc_fw_ctrl_bypass = 0;
			hmc_statistic1_reg.ma_hmc_lineratio = 6;
		}
		else if (Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total >= 80 && Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total < 90)
		{
			di_hmc_me_refine_ctrl2_reg.hmc_fw_ctrl_bypass = 0;
			hmc_statistic1_reg.ma_hmc_lineratio = 8;
		}
		else if (Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total >= 90 && Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total < 100)
		{
			di_hmc_me_refine_ctrl2_reg.hmc_fw_ctrl_bypass = 0;
			hmc_statistic1_reg.ma_hmc_lineratio = 10;
		}
		else if (Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total > 100)
		{
			di_hmc_me_refine_ctrl2_reg.hmc_fw_ctrl_bypass = 0;
			hmc_statistic1_reg.ma_hmc_lineratio = 12;
		}
		// 170817 henry
		if(Smart_Integration_Status.SCREEN_ACTION_STATUS.PAN_detect_str && Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram_flag)
			hmc_statistic1_reg.ma_hmc_lineratio = 72;	//	for sony window pan if pan teeth enable(avoid OSD teeth)->HMc must compensate all missing pixels
		// 170817 end
	}
	// end henry

	if(DynamicOptimizeSystem[152] ==1) //for special case
	{
		di_hmc_me_refine_ctrl2_reg.hmc_fw_ctrl_bypass = 1;

	}

	// === Process for teeth and jaggy when pan, henry
//	if (Smart_Integration_Status.SCREEN_SPECIAL_STATUS.MOVING_CAN_detect != 1 &&
//		Smart_Integration_Status.SCREEN_ACTION_STATUS.PAN_detect_str == 1 && (HMC_BIN_COUNT - (Smart_Integration_Status.SCREEN_HPAN_STATUS.Pan_mv))%2==0) //odd mv
//		rtd_setbits(DI_IM_DI_HMC_ADJUSTABLE_reg, _BIT17);
//	else
//		rtd_clearbits(DI_IM_DI_HMC_ADJUSTABLE_reg, _BIT17);

	/*rtd_outl(DI_IM_DI_CONTROL_reg, di_control_reg.regValue);*/ /* for WOSQRTK_10435, ip enable can't enable, cause by isr control, marked this*/
	rtd_outl(DI_IM_DI_HMC_STATISTIC1_reg, hmc_statistic1_reg.regValue);
	rtd_outl(DI_IM_DI_HMC_ME_REFINE_CTRL_2_reg, di_hmc_me_refine_ctrl2_reg.regValue);

	di_im_di_hmc_pan_control_RBUS di_im_di_hmc_pan_control_reg;
	di_im_di_hmc_pan_control_reg.regValue = rtd_inl(DI_IM_DI_HMC_PAN_CONTROL_reg);
	di_im_di_hmc_adjustable3_RBUS di_hmc_adjustable3_reg;
	di_hmc_adjustable3_reg.regValue = rtd_inl(DI_IM_DI_HMC_ADJUSTABLE3_reg);
	di_im_di_hmc_adjustable4_RBUS di_hmc_adjustable4_reg;
	di_hmc_adjustable4_reg.regValue = rtd_inl(DI_IM_DI_HMC_ADJUSTABLE4_reg);

	if(di_im_di_hmc_pan_control_reg.pan_me_fw_control_motion_vector_det
		&& di_im_di_hmc_pan_control_reg.pan_me_fw_control_motion_vector % 2 == 0) // reg_value: 17 = 0
	{
		di_hmc_adjustable4_reg.hmc_mv_refine_sobel_en = 0;
		di_hmc_adjustable4_reg.hmc_mv_refine_sobel_non_edge_th = 0;
		di_hmc_adjustable4_reg.hmc_mv_refine_sobel_diff_th = 0;
		di_hmc_adjustable4_reg.hmc_mv_refine_mor_hh_h_th = 7;
		di_hmc_adjustable4_reg.hmc_mv_refine_mor_hh_v_th = 11;
		di_hmc_adjustable3_reg.hmc_mv_refine_mor_zero_th1 = 0;
		di_hmc_adjustable3_reg.hmc_mv_refine_mor_same_th1 = 0;
		di_hmc_adjustable3_reg.hmc_mv_refine_mor_zero_th2 = 48;
		di_hmc_adjustable3_reg.hmc_mv_refine_mor_same_th2 = 47;
	}
	else
	{
		di_hmc_adjustable4_reg.hmc_mv_refine_sobel_en = 1;
		di_hmc_adjustable4_reg.hmc_mv_refine_sobel_non_edge_th = 5;
		di_hmc_adjustable4_reg.hmc_mv_refine_sobel_diff_th = 10;
		di_hmc_adjustable4_reg.hmc_mv_refine_mor_hh_h_th = 12;
		di_hmc_adjustable4_reg.hmc_mv_refine_mor_hh_v_th = 12;
		di_hmc_adjustable3_reg.hmc_mv_refine_mor_zero_th1 = 20;
		di_hmc_adjustable3_reg.hmc_mv_refine_mor_same_th1 = 30;
		di_hmc_adjustable3_reg.hmc_mv_refine_mor_zero_th2 = 40;
		di_hmc_adjustable3_reg.hmc_mv_refine_mor_same_th2 = 25;
	}
	IoReg_Write32(DI_IM_DI_HMC_ADJUSTABLE3_reg, di_hmc_adjustable3_reg.regValue);
	IoReg_Write32(DI_IM_DI_HMC_ADJUSTABLE4_reg, di_hmc_adjustable4_reg.regValue);
	// === end teeth and jaggy process

	// === diagonal motion setting
	di_im_new_mcnr_control4_RBUS di_im_new_mcnr_control4;
	di_im_new_mcnr_control4.regValue = rtd_inl(DI_IM_NEW_MCNR_CONTROL4_reg);
	if(di_im_new_mcnr_control4.n_mcnr_v_pan_mv > 3 || di_im_new_mcnr_control4.n_mcnr_v_pan_mv < 3)
		di_hmc_me_refine_ctrl2_reg.hmc_fw_ctrl_bypass = 1;
	else
		di_hmc_me_refine_ctrl2_reg.hmc_fw_ctrl_bypass = 0;
	rtd_outl(DI_IM_DI_HMC_ME_REFINE_CTRL_2_reg, di_hmc_me_refine_ctrl2_reg.regValue);
	// === end diagonal motion setting

	if (Smart_Integration_Status.SCREEN_HMC_STATUS.Show_Debug_MSG)
		VIP_DEBUG_PRINTF("[SIS HMC] hmc_pass_total: %d\n", Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total);
}

unsigned char fw_mv[32];
// 170831 henry for diagonal motion
static int gmv_y_cnt = 0;
static int gmv_y_pre = 3;
void scalerVIP_DI_MiddleWare_PAN_Apply()
{
	char hpan_pass_total = 0;
	unsigned char i = 0;

	di_im_di_pan_detection_control_1_RBUS di_pan_detection_control_1_reg;
	di_im_di_hmc_pan_control_RBUS di_im_di_hmc_pan_control_reg;
	di_im_di_pan_detection_control_2_RBUS di_im_di_pan_detection_control_2_reg;
	di_im_di_ma_frame_motion_th_a_RBUS di_ma_frame_motion_th_a_reg;
	di_im_di_ma_frame_motion_th_b_RBUS di_ma_frame_motion_th_b_reg;
	di_im_di_ma_frame_motion_th_c_RBUS di_ma_frame_motion_th_c_reg;

	di_pan_detection_control_1_reg.regValue = rtd_inl(DI_IM_DI_PAN_DETECTION_CONTROL_1_reg);
	di_im_di_hmc_pan_control_reg.regValue = rtd_inl(DI_IM_DI_HMC_PAN_CONTROL_reg);
	di_im_di_pan_detection_control_2_reg.regValue = rtd_inl(DI_IM_DI_PAN_DETECTION_CONTROL_2_reg);
	di_ma_frame_motion_th_a_reg.regValue = rtd_inl(DI_IM_DI_MA_FRAME_MOTION_TH_A_reg);
	di_ma_frame_motion_th_b_reg.regValue = rtd_inl(DI_IM_DI_MA_FRAME_MOTION_TH_B_reg);
	di_ma_frame_motion_th_c_reg.regValue = rtd_inl(DI_IM_DI_MA_FRAME_MOTION_TH_C_reg);

	unsigned char cur_source=0,sd_input=0;
	cur_source=(RPC_system_info_structure_table->VIP_source);

	if((cur_source >= VIP_QUALITY_CVBS_NTSC && cur_source <=VIP_QUALITY_YPbPr_576P)||
		(cur_source >= VIP_QUALITY_HDMI_480I && cur_source <=VIP_QUALITY_HDMI_576P)||
		(cur_source >= VIP_QUALITY_DTV_480I && cur_source <=VIP_QUALITY_DTV_576P)||
		(cur_source >= VIP_QUALITY_PVR_480I && cur_source <=VIP_QUALITY_PVR_576P)||
		(cur_source >= VIP_QUALITY_CVBS_SECAN && cur_source <=VIP_QUALITY_TV_NTSC443))
	{
		sd_input = 1;

		if (Smart_Integration_Status.SCREEN_ACTION_STATUS.VPAN_detect == 0 && Smart_Integration_Status.SCREEN_ACTION_STATUS.SPAN_detect == 0)
			di_pan_detection_control_1_reg.pan_en = 1;
		else
			di_pan_detection_control_1_reg.pan_en = 0;



	}
	else
	{
		di_pan_detection_control_1_reg.pan_en = 0;
		sd_input = 0;

	//if (Smart_Integration_Status.SCREEN_ACTION_STATUS.VPAN_detect == 0 && Smart_Integration_Status.SCREEN_ACTION_STATUS.SPAN_detect == 0)
	//	di_pan_detection_control_1_reg.pan_en = 1;
	//else
	//	di_pan_detection_control_1_reg.pan_en = 0;


	}




	rtd_outl(DI_IM_DI_PAN_DETECTION_CONTROL_1_reg, di_pan_detection_control_1_reg.regValue);

	di_im_di_hmc_pan_control_reg.pan_me_fw_control_motion_vector_det = (Smart_Integration_Status.SCREEN_ACTION_STATUS.PAN_detect_str & Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram_flag);
	if (Smart_Integration_Status.SCREEN_ACTION_STATUS.HMCNR_detect == 1)
		di_im_di_hmc_pan_control_reg.pan_me_fw_control_motion_vector_det = 1; // for HMCNR reason, always enable, disable function use below edge control.
	//di_im_di_hmc_pan_control_reg.pan_me_fw_control_motion_vector = Smart_Integration_Status.SCREEN_HPAN_STATUS.Pan_mv + 1;



	//if(sd_input==1)
	//{
	//	di_im_di_hmc_pan_control_reg.pan_me_fw_control_motion_vector_det = Mcnr_Pan;
	//}


	if (Smart_Integration_Status.SCREEN_ACTION_STATUS.PAN_detect_str & Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram_flag)
	{
		di_im_di_pan_detection_control_2_reg.pan_mc_edge_h = 1;
		di_im_di_pan_detection_control_2_reg.pan_mc_edge_l = 1;
		di_im_di_pan_detection_control_2_reg.pan_mc_edge_n = 1;
		di_im_di_pan_detection_control_2_reg.pan_mc_edge_r = 1;
		di_im_di_pan_detection_control_2_reg.pan_mc_edge_v = 1;
	}
	else
	{
		di_im_di_pan_detection_control_2_reg.pan_mc_edge_h = 0;
		di_im_di_pan_detection_control_2_reg.pan_mc_edge_l = 0;
		di_im_di_pan_detection_control_2_reg.pan_mc_edge_n = 0;
		di_im_di_pan_detection_control_2_reg.pan_mc_edge_r = 0;
		di_im_di_pan_detection_control_2_reg.pan_mc_edge_v = 0;
	}
	//	reverse HPan motion vector
	di_im_di_hmc_pan_control_reg.pan_me_fw_control_motion_vector = HMC_BIN_COUNT -(Smart_Integration_Status.SCREEN_HPAN_STATUS.Pan_mv);

	for (i=31; i>0; i--)
	{
		fw_mv[i] = fw_mv[i-1];
	}
	fw_mv[0] = HMC_BIN_COUNT -(Smart_Integration_Status.SCREEN_HPAN_STATUS.Pan_mv);

	int pre_mv_avg = 0;
	unsigned char mv_avg_count = (di_im_di_hmc_pan_control_reg.dummy18024660_31_24 & 0x3F)+1; // bit29~24
	if (mv_avg_count > 32)
		mv_avg_count = 32;
	for (i=0; i<mv_avg_count; i++)
	{
		pre_mv_avg+=fw_mv[i];
	}
	pre_mv_avg/=mv_avg_count;
	di_im_di_hmc_pan_control_reg.pan_me_fw_control_motion_vector = pre_mv_avg;

	// if mv_avg is +-6, still use +-5 mv for hmcnr brand pan case
	unsigned char mv_modify_en = ((di_im_di_hmc_pan_control_reg.dummy18024660_31_24 & 0x40)>>6); // bit30
	if (mv_modify_en == 1)
	{
		if (di_im_di_hmc_pan_control_reg.pan_me_fw_control_motion_vector == 23)
			di_im_di_hmc_pan_control_reg.pan_me_fw_control_motion_vector = 22;
		if (di_im_di_hmc_pan_control_reg.pan_me_fw_control_motion_vector == 11)
			di_im_di_hmc_pan_control_reg.pan_me_fw_control_motion_vector = 12;
	}

	//if((HMC_BIN_COUNT -(Smart_Integration_Status.SCREEN_HPAN_STATUS.Pan_mv))%2==0)	//	odd mv
		di_im_di_pan_detection_control_2_reg.pan_mc_edge_v = 0;
	//else
	//	di_im_di_pan_detection_control_2_reg.pan_mc_edge_v = 0; //1 rord.tsao form yl

	// === Process for teeth and jaggy when pan, henry
	di_im_di_pan_detection_control_2_reg.pan_mc_teeth_check_en = 1;
	di_im_di_pan_detection_control_2_reg.pan_mc_teeth_check_th = 6;
	di_im_di_hmc_pan_control_reg.pan_mc_adaptive_compensation_en = 1;
	iedge_smooth_edgesmooth_ext_angle_RBUS iedge_smooth_edgesmooth_ext_angle_reg;
	iedge_smooth_edgesmooth_ext_angle_reg.regValue = rtd_inl(IEDGE_SMOOTH_EdgeSmooth_Ext_angle_reg);
	if(di_im_di_hmc_pan_control_reg.pan_me_fw_control_motion_vector_det
		&& di_im_di_hmc_pan_control_reg.pan_me_fw_control_motion_vector % 2 == 0) // reg_value: 17 = 0
		iedge_smooth_edgesmooth_ext_angle_reg.ext_angle_en= 1;
	else
		iedge_smooth_edgesmooth_ext_angle_reg.ext_angle_en = 0;
	rtd_outl(IEDGE_SMOOTH_EdgeSmooth_Ext_angle_reg, iedge_smooth_edgesmooth_ext_angle_reg.regValue);
	// === end teeth and jaggy process

	for (i=0; i<HPAN_PASS_COUNT; i++)
	{
		if (Smart_Integration_Status.SCREEN_HPAN_STATUS.Pass_Result_Sequence[i] == 1)
			hpan_pass_total++;
	}

	// when pattern is SD case, need vertical lowpass filter for smooth
	if (Smart_Integration_Status.Vip_Source_Timing == VIP_QUALITY_CVBS_NTSC/*Smart_Integration_Status.DI_WIDTH <= 960*/)
	{
		scalerVIP_Set_hpan_vfir(hpan_pass_total/8);
        //apply value used void scalerVIP_Dynamic_Vertical_NR(void)
	}
	New_Mcnr_Mv = di_im_di_hmc_pan_control_reg.pan_me_fw_control_motion_vector;

  // 170831 henry - diagonal motion disable pan
  di_im_new_mcnr_control4_RBUS di_im_new_mcnr_control4;
	di_im_new_mcnr_control4.regValue = rtd_inl(DI_IM_NEW_MCNR_CONTROL4_reg);
	if(di_im_new_mcnr_control4.n_mcnr_v_pan_mv != 3)
	{
    if(abs(di_im_new_mcnr_control4.n_mcnr_v_pan_mv-gmv_y_pre)==0)
      gmv_y_cnt+=2;
    else if(abs(di_im_new_mcnr_control4.n_mcnr_v_pan_mv-gmv_y_pre)==1)
      gmv_y_cnt+=1;
    else
      gmv_y_cnt-=1;
	}
  else
      gmv_y_cnt-=2;

  if(gmv_y_cnt<0) gmv_y_cnt=0;
  if(gmv_y_cnt>10) gmv_y_cnt=10;

  if(gmv_y_cnt>7)
    di_im_di_hmc_pan_control_reg.pan_me_fw_control_motion_vector_det = 0;

  gmv_y_pre = di_im_new_mcnr_control4.n_mcnr_v_pan_mv;
  //end henry
	rtd_outl(DI_IM_DI_HMC_PAN_CONTROL_reg, di_im_di_hmc_pan_control_reg.regValue);
	rtd_outl(DI_IM_DI_PAN_DETECTION_CONTROL_2_reg,di_im_di_pan_detection_control_2_reg.regValue);

#if 0  //move to sclervip rord.tsao 2015/12/1
	if(Smart_Integration_Status.SCREEN_HPAN_STATUS.Pen_special_case < 15) {
		/*rock_rau 20150922 Q-tek monoscope pan flicker issue(original setting)*/
		di_ma_frame_motion_th_a_reg.ma_framehtha = 0x04;
		di_ma_frame_motion_th_b_reg.ma_framehthb = 0x0a;
		di_ma_frame_motion_th_c_reg.ma_framehthc = 0x14;
	} else if(Smart_Integration_Status.SCREEN_HPAN_STATUS.Pen_special_case < 30) {
		di_ma_frame_motion_th_a_reg.ma_framehtha = 0x0a;
		di_ma_frame_motion_th_b_reg.ma_framehthb = 0x12;
		di_ma_frame_motion_th_c_reg.ma_framehthc = 0x16;
	}else {
		/*rock_rau 20150922 Q-tek monoscope pan flicker issue(trend weave)*/
		di_ma_frame_motion_th_a_reg.ma_framehtha = 0x14;
		di_ma_frame_motion_th_b_reg.ma_framehthb = 0x16;
		di_ma_frame_motion_th_c_reg.ma_framehthc = 0x18;
	}
	rtd_outl(DI_IM_DI_MA_FRAME_MOTION_TH_A_reg, di_ma_frame_motion_th_a_reg.regValue);
	rtd_outl(DI_IM_DI_MA_FRAME_MOTION_TH_B_reg, di_ma_frame_motion_th_b_reg.regValue);
	rtd_outl(DI_IM_DI_MA_FRAME_MOTION_TH_C_reg, di_ma_frame_motion_th_c_reg.regValue);
#endif

}
unsigned char pre_hmcnr_detect_status = 0;

void scalerVIP_DI_MiddleWare_HMCNR_Apply(unsigned char weight)
{
	char mv = 0, hpan_pass_total = 0;
	unsigned char i = 0, mv_index = 0;
	float ratio;

	di_im_di_rtnr_hmcnr_RBUS di_rtnr_hmcnr_reg;
	di_im_new_mcnr_control2_RBUS new_mcnr_control2_reg;
	di_rtnr_hmcnr_reg.regValue = rtd_inl(DI_IM_DI_RTNR_HMCNR_reg);
	new_mcnr_control2_reg.regValue = rtd_inl(DI_IM_NEW_MCNR_CONTROL2_reg);

//	if (Smart_Integration_Status.SCREEN_ACTION_STATUS.PAN_detect == 1)
		mv = Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Rank[0]; // return 16 = mv zero
//	else
	//	mv = -1;

	mv_index = mv;

	ratio = 1920*540;
	ratio = ratio/(Smart_Integration_Status.DI_HEIGHT*Smart_Integration_Status.DI_WIDTH);
	if(Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram_flag == 0)
	{
		if ((ratio*Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[mv_index]) > 30000)
			mv = mv-16;
		else
			mv = 0;
	}
	else
	{
		if ((ratio*Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[mv_index]) < 12500)
			mv = mv-16;
		else
			mv = 0;
	}

	if (weight > 10)
		weight = 10;

	for (i=0; i<HPAN_PASS_COUNT; i++)
	{
		if (Smart_Integration_Status.SCREEN_HPAN_STATUS.Pass_Result_Sequence[i] == 1)
			hpan_pass_total++;
	}


	switch(RPC_system_info_structure_table->VIP_source)
	{
		case VIP_QUALITY_CVBS_NTSC:
		case VIP_QUALITY_CVBS_PAL:
		case VIP_QUALITY_YPbPr_480I:
		case VIP_QUALITY_YPbPr_576I:
		case VIP_QUALITY_HDMI_480I:
		case VIP_QUALITY_HDMI_576I:

	if (hpan_pass_total < 2)
	{
				new_mcnr_control2_reg.cp_temporal_hmcnr_search_range = 1;
		di_rtnr_hmcnr_reg.cp_temporal_hmcnr_weight = 0;
	}
	else if (hpan_pass_total < 4)
	{
				new_mcnr_control2_reg.cp_temporal_hmcnr_search_range = 2;
		di_rtnr_hmcnr_reg.cp_temporal_hmcnr_weight = 0;
	}
	else if (hpan_pass_total < 6)
	{
				new_mcnr_control2_reg.cp_temporal_hmcnr_search_range = 3;
		di_rtnr_hmcnr_reg.cp_temporal_hmcnr_weight = 0;
	}
	else if (hpan_pass_total < 8)
	{
				new_mcnr_control2_reg.cp_temporal_hmcnr_search_range = 4;
		di_rtnr_hmcnr_reg.cp_temporal_hmcnr_weight = 0;
	}
	else if (hpan_pass_total < 10)
	{
				new_mcnr_control2_reg.cp_temporal_hmcnr_search_range = 5;
		di_rtnr_hmcnr_reg.cp_temporal_hmcnr_weight = 0;
	}
	else if (hpan_pass_total < 12)
	{
				new_mcnr_control2_reg.cp_temporal_hmcnr_search_range = 5;
		di_rtnr_hmcnr_reg.cp_temporal_hmcnr_weight = 1;
	}
	else if (hpan_pass_total < 14)
	{
				new_mcnr_control2_reg.cp_temporal_hmcnr_search_range = 5;
		di_rtnr_hmcnr_reg.cp_temporal_hmcnr_weight = 2;
	}
	else
	{
				new_mcnr_control2_reg.cp_temporal_hmcnr_search_range = 5;
		di_rtnr_hmcnr_reg.cp_temporal_hmcnr_weight = 3;
	}

			break;
		case VIP_QUALITY_HDMI_1080I:

			if (hpan_pass_total < 2)
			{
				new_mcnr_control2_reg.cp_temporal_hmcnr_search_range = 1;
				di_rtnr_hmcnr_reg.cp_temporal_hmcnr_weight = 0;
			}
			else if (hpan_pass_total < 4)
			{
				new_mcnr_control2_reg.cp_temporal_hmcnr_search_range = 2;
				di_rtnr_hmcnr_reg.cp_temporal_hmcnr_weight = 0;
			}
			else if (hpan_pass_total < 6)
			{
				new_mcnr_control2_reg.cp_temporal_hmcnr_search_range = 3;
				di_rtnr_hmcnr_reg.cp_temporal_hmcnr_weight = 0;
			}
			else if (hpan_pass_total < 8)
			{
				new_mcnr_control2_reg.cp_temporal_hmcnr_search_range = 4;
				di_rtnr_hmcnr_reg.cp_temporal_hmcnr_weight = 0;
			}
			else if (hpan_pass_total < 10)
			{
				new_mcnr_control2_reg.cp_temporal_hmcnr_search_range = 5;
				di_rtnr_hmcnr_reg.cp_temporal_hmcnr_weight = 0;
			}
			else if (hpan_pass_total < 12)
			{
				new_mcnr_control2_reg.cp_temporal_hmcnr_search_range = 5;
				di_rtnr_hmcnr_reg.cp_temporal_hmcnr_weight = 1;
			}
			else if (hpan_pass_total < 14)
			{
				new_mcnr_control2_reg.cp_temporal_hmcnr_search_range = 5;
				di_rtnr_hmcnr_reg.cp_temporal_hmcnr_weight = 2;
			}
			else
			{
				new_mcnr_control2_reg.cp_temporal_hmcnr_search_range = 5;
				di_rtnr_hmcnr_reg.cp_temporal_hmcnr_weight = 2;
			}



			break;

		default:
			break;

	}

			int pre_mv_avg = 0;
	for (i=0; i<16; i++) // pre 16 frames mv
	{
		pre_mv_avg+=(Smart_Integration_Status.SCREEN_HPAN_STATUS.Mv_Result_Sequence[i]-16);
	}
	pre_mv_avg/=16;

	pre_hmcnr_detect_status = Smart_Integration_Status.SCREEN_ACTION_STATUS.HMCNR_detect;
	di_im_di_rtnr_k_force_modify_RBUS di_rtnr_k_force_modify_reg;
	di_rtnr_k_force_modify_reg.regValue = rtd_inl(DI_IM_DI_RTNR_K_FORCE_MODIFY_reg);
	if (weight != 0 && pre_mv_avg >= -7 && pre_mv_avg <= 7 && Smart_Integration_Status.Mode_Progressive==0 && hpan_pass_total > 30 && Smart_Integration_Status.SCREEN_MOTION_STATUS.MOTION_LEVEL > 10)
	{
		di_rtnr_hmcnr_reg.cp_temporal_hmcnr_y_en = 1;
//		di_rtnr_hmcnr_reg.cp_temporal_hmcnr_follow_pan_en = 1; /*henry @ Mac5*/

		Smart_Integration_Status.SCREEN_ACTION_STATUS.HMCNR_detect = 1;
	}
	else
	{
		di_rtnr_hmcnr_reg.cp_temporal_hmcnr_y_en = 0;
//		di_rtnr_hmcnr_reg.cp_temporal_hmcnr_follow_pan_en = 0; /*henry @ Mac5*/

		Smart_Integration_Status.SCREEN_ACTION_STATUS.HMCNR_detect = 0;
	}

	if (Smart_Integration_Status.SCREEN_HMCNR_STATUS.Show_Debug_MSG && pre_hmcnr_detect_status != Smart_Integration_Status.SCREEN_ACTION_STATUS.HMCNR_detect)
		VIP_DEBUG_PRINTF("[SIS HMCNR] HMCNR status change!! - current is: %d\n", Smart_Integration_Status.SCREEN_ACTION_STATUS.HMCNR_detect);

	rtd_outl(DI_IM_DI_RTNR_HMCNR_reg, di_rtnr_hmcnr_reg.regValue);
	rtd_outl(DI_IM_NEW_MCNR_CONTROL2_reg, new_mcnr_control2_reg.regValue);

	if (Smart_Integration_Status.SCREEN_HMCNR_STATUS.Show_Debug_MSG)
		VIP_DEBUG_PRINTF("[SIS HMCNR] mv: %d, mv_seq: %d, pre_mv_avg: %d, hpan_total : %d, count: [%d]%d\n", mv, Smart_Integration_Status.SCREEN_HPAN_STATUS.Mv_Result_Sequence[0], pre_mv_avg, hpan_pass_total, Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram_flag, Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[mv_index]);

}
unsigned int scalerVIP_Cal_Idx_Ave_Hpan(unsigned int lv_index, unsigned char isAll_Flag)
{
	#define windowSize_I_hpan 32
	#define windowSizeBit_I_hpan 5

	static unsigned char idx=0;
	static unsigned int levelIdx_arr[windowSize_I_hpan]={0};

	unsigned char i=0;
	unsigned int sum= 0, ret =0 ;

	if(isAll_Flag==1)
	{
		for(i=0;i<windowSize_I_hpan;i++)
			levelIdx_arr[i] = lv_index;
		ret = lv_index;
	}
	else
	{
		levelIdx_arr[idx] = lv_index;

		for(i=0;i<windowSize_I_hpan;i++)
			sum = sum + levelIdx_arr[i];
		ret = sum>>windowSizeBit_I_hpan;

		idx++;
		if(idx==windowSize_I_hpan)
			idx=0;
	}
	return ret;
}
unsigned int scalerVIP_Cal_Idx_Ave_Vpan(unsigned int lv_index, unsigned char isAll_Flag)
{
	#define windowSize_I_vpan 32
	#define windowSizeBit_I_vpan 5

	static unsigned char idx=0;
	static unsigned int levelIdx_arr[windowSize_I_vpan]={0};

	unsigned char i=0;
	unsigned int sum= 0, ret =0 ;

	if(isAll_Flag==1)
	{
		for(i=0;i<windowSize_I_vpan;i++)
			levelIdx_arr[i] = lv_index;
		ret = lv_index;
	}
	else
	{
		levelIdx_arr[idx] = lv_index;

		for(i=0;i<windowSize_I_vpan;i++)
			sum = sum + levelIdx_arr[i];
		ret = sum>>windowSizeBit_I_vpan;

		idx++;
		if(idx==windowSize_I_vpan)
			idx=0;
	}
	return ret;
}
extern unsigned int RTNR_MAD_count_Y_avg;
#if 0
void scalerVIP_DI_MiddleWare_MCNR_Ctrl(unsigned char weight)
{
	int Hpan_value=10;
	int Vpan_value=3;
	unsigned long GMVx=0;
	unsigned long GMVy;// = (rtd_inl(0xb802456c) & 0x00700000)>>20;
	int maxGMV1_ctr=0;
	int maxGMV2_ctr=0;
	int maxGMV3_ctr=0;
	int GMV_ctr=0;
	//int pan_penalty=0;

	char hpan_pass_total = 0;
	unsigned char i = 0;
	int vc_nr_MCNR_mvx_hist[21]={0};
	int vc_nr_MCNR_mvy_hist[7]={0};
	int vc_nr_MCNR_static_hist=0;
	int max_hist_v=0;
	int max_hist_h=0;
	int max_hist_h_MV=10;
	int max_hist_v_MV=3;
	int sum_hist_h=0;
	int sum_hist_v=0;

	int il=0;
	int ir=0;
	int mvx_hist_adj=0;
	int mvx_hist_adj_add=0;
	int mvy_hist_adj=0;
	int mvy_hist_adj_add=0;
	int ration_TH_H=50;
	int ration_TH_V=80;
	static int Vpan_flag_n=0;
	static int Hpan_flag_n=0;
	int mcnr_mode=0;

	unsigned char GMV_ratio_h = 0;
	unsigned char GMV_ratio_v = 0;
	static int GMVx1_acc =0;
	static int GMVx1_ctr_acc =0;

	static int GMVx2_acc = 0;
	static int GMVx2_ctr_acc = 0;

	static int GMVy1_acc =0;
	static int GMVy1_ctr_acc =0;

	static int GMVy2_acc = 0;
	static int GMVy2_ctr_acc = 0;
	int diff_th_h=0;
	int diff_th_v=0;
	int GMV_ctr_th=10;
	unsigned char temp_x=0,temp_y=0,temp_xy;

    	unsigned char Pan_flag=0;
    	unsigned int  mv_value=0,mv_index=0;

	di_im_di_rtnr_hmcnr_RBUS di_rtnr_hmcnr_reg;
	di_rtnr_output_clamp_RBUS di_rtnr_output_clamp_reg;
	di_im_new_mcnr_weighting_condition_RBUS di_im_new_mcnr_weighting_condition;
	di_im_new_mcnr_control4_RBUS di_im_new_mcnr_control4;

	di_im_new_mcnr_control_RBUS di_im_new_mcnr_control;
	di_im_new_mcnr_pan_condition_RBUS di_im_new_mcnr_pan_condition;
	di_im_new_mcnr_clamping_value_RBUS di_im_new_mcnr_clamping_value;

	di_rtnr_hmcnr_reg.regValue = rtd_inl(DI_IM_DI_RTNR_HMCNR_reg);
	di_rtnr_output_clamp_reg.regValue = rtd_inl(DI_RTNR_OUTPUT_CLAMP_reg);
	di_im_new_mcnr_weighting_condition.regValue = rtd_inl(DI_IM_NEW_MCNR_WEIGHTING_CONDITION_reg);
	di_im_new_mcnr_control4.regValue = rtd_inl(DI_IM_NEW_MCNR_CONTROL4_reg);
	di_im_new_mcnr_control.regValue = rtd_inl(DI_IM_NEW_MCNR_CONTROL_reg);
	di_im_new_mcnr_pan_condition.regValue = rtd_inl(DI_IM_NEW_MCNR_PAN_CONDITION_reg);
	di_im_new_mcnr_clamping_value.regValue	= rtd_inl(DI_IM_NEW_MCNR_CLAMPING_VALUE_reg);

	mcnr_mode =Smart_Integration_Status.Mode_Progressive;
	unsigned char cur_source=0,sd_input=0;
	cur_source=(RPC_system_info_structure_table->VIP_source);

	if((cur_source >= VIP_QUALITY_CVBS_NTSC && cur_source <=VIP_QUALITY_YPbPr_576P)||
		(cur_source >= VIP_QUALITY_HDMI_480I && cur_source <=VIP_QUALITY_HDMI_576P)||
		(cur_source >= VIP_QUALITY_DTV_480I && cur_source <=VIP_QUALITY_DTV_576P)||
		(cur_source >= VIP_QUALITY_PVR_480I && cur_source <=VIP_QUALITY_PVR_576P)||
		(cur_source >= VIP_QUALITY_CVBS_SECAN && cur_source <=VIP_QUALITY_TV_NTSC443))
	{
		sd_input = 1;
	}
	else
	{
		sd_input = 0;
	}



		di_di_smd_gmvcoeff3_RBUS init_di_smd_gmvcoeff3_reg;
		di_di_smd_sampling_gmvc_RBUS di_di_smd_sampling_gmvc;
		di_di_smd_gmvcoeff1_RBUS smd_gmvcoeff1_reg;
		di_di_smd_gmvcoeff2_RBUS smd_gmvcoeff2_reg;
		di_di_smd_sampling_gmvb_RBUS di_di_smd_sampling_gmvb_reg;


		di_di_smd_sampling_gmvb_reg.regValue = rtd_inl(DI_DI_SMD_SAMPLING_GMVB_reg);

		init_di_smd_gmvcoeff3_reg.regValue = rtd_inl(DI_DI_SMD_GMVCOEFF3_reg);
		di_di_smd_sampling_gmvc.regValue = rtd_inl(DI_DI_SMD_SAMPLING_GMVC_reg);
		smd_gmvcoeff1_reg.regValue= rtd_inl(DI_DI_SMD_GMVCOEFF1_reg);


		GMVx = init_di_smd_gmvcoeff3_reg.smd_gmv1_x;
		GMVy = di_di_smd_sampling_gmvc.smd_gmvc_y;
		GMV_ctr = smd_gmvcoeff1_reg.smd_gmv_ctr;
		maxGMV1_ctr = smd_gmvcoeff1_reg.smd_gmv1_max_ctr;
		maxGMV2_ctr = smd_gmvcoeff2_reg.smd_gmv2_max_ctr;
		maxGMV3_ctr = smd_gmvcoeff2_reg.smd_gmv3_max_ctr;

		// histograms information /////////////
		di_im_di_rtnr_hmcnr_statistic_1_RBUS	di_im_di_rtnr_hmcnr_statistic_1;
		di_im_di_rtnr_hmcnr_statistic_2_RBUS	di_im_di_rtnr_hmcnr_statistic_2;
		di_im_di_rtnr_hmcnr_statistic_3_RBUS	di_im_di_rtnr_hmcnr_statistic_3;
		di_im_di_rtnr_hmcnr_statistic_4_RBUS	di_im_di_rtnr_hmcnr_statistic_4;
		di_im_di_rtnr_hmcnr_statistic_5_RBUS	di_im_di_rtnr_hmcnr_statistic_5;
		di_im_di_rtnr_hmcnr_statistic_6_RBUS	di_im_di_rtnr_hmcnr_statistic_6;
		di_im_di_rtnr_mcnr_statistic_7_RBUS	di_im_di_rtnr_mcnr_statistic_7;
		di_im_di_rtnr_mcnr_statistic_8_RBUS	di_im_di_rtnr_mcnr_statistic_8;
		di_im_di_rtnr_mcnr_statistic_9_RBUS	di_im_di_rtnr_mcnr_statistic_9;
		di_im_di_rtnr_mcnr_statistic_10_RBUS	di_im_di_rtnr_mcnr_statistic_10;
		di_im_di_rtnr_mcnr_statistic_11_RBUS	di_im_di_rtnr_mcnr_statistic_11;
		di_im_di_rtnr_mcnr_statistic_12_RBUS	di_im_di_rtnr_mcnr_statistic_12;
		di_im_di_rtnr_mcnr_statistic_13_RBUS	di_im_di_rtnr_mcnr_statistic_13;
		di_im_di_rtnr_mcnr_statistic_14_RBUS	di_im_di_rtnr_mcnr_statistic_14;
		di_im_di_rtnr_mcnr_statistic_15_RBUS	di_im_di_rtnr_mcnr_statistic_15;


		di_im_di_rtnr_hmcnr_statistic_1.regValue = rtd_inl(DI_IM_DI_RTNR_HMCNR_STATISTIC_1_reg);
		di_im_di_rtnr_hmcnr_statistic_2.regValue = rtd_inl(DI_IM_DI_RTNR_HMCNR_STATISTIC_2_reg);
		di_im_di_rtnr_hmcnr_statistic_3.regValue = rtd_inl(DI_IM_DI_RTNR_HMCNR_STATISTIC_3_reg);
		di_im_di_rtnr_hmcnr_statistic_4.regValue = rtd_inl(DI_IM_DI_RTNR_HMCNR_STATISTIC_4_reg);
		di_im_di_rtnr_hmcnr_statistic_5.regValue = rtd_inl(DI_IM_DI_RTNR_HMCNR_STATISTIC_5_reg);
		di_im_di_rtnr_hmcnr_statistic_6.regValue = rtd_inl(DI_IM_DI_RTNR_HMCNR_STATISTIC_6_reg);

		di_im_di_rtnr_mcnr_statistic_7.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_7_reg);
		di_im_di_rtnr_mcnr_statistic_8.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_8_reg);
		di_im_di_rtnr_mcnr_statistic_9.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_9_reg);
		di_im_di_rtnr_mcnr_statistic_10.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_10_reg);
		di_im_di_rtnr_mcnr_statistic_11.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_11_reg);
		di_im_di_rtnr_mcnr_statistic_12.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_12_reg);
		di_im_di_rtnr_mcnr_statistic_13.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_13_reg);
		di_im_di_rtnr_mcnr_statistic_14.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_14_reg);
		di_im_di_rtnr_mcnr_statistic_15.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_15_reg);


		vc_nr_MCNR_static_hist=di_im_di_rtnr_mcnr_statistic_15.mcnr_static_sum;

		vc_nr_MCNR_mvy_hist[0]=di_im_di_rtnr_mcnr_statistic_15.mcnr_d3_sum;
		vc_nr_MCNR_mvy_hist[1]=di_im_di_rtnr_mcnr_statistic_14.mcnr_d2_sum;
		vc_nr_MCNR_mvy_hist[2]=di_im_di_rtnr_mcnr_statistic_14.mcnr_d1_sum;
		vc_nr_MCNR_mvy_hist[3]=di_im_di_rtnr_mcnr_statistic_13.mcnr_v0_sum;//-vc_nr_MCNR_static_hist;
		vc_nr_MCNR_mvy_hist[4]=di_im_di_rtnr_mcnr_statistic_13.mcnr_u1_sum;
		vc_nr_MCNR_mvy_hist[5]=di_im_di_rtnr_mcnr_statistic_12.mcnr_u2_sum;
		vc_nr_MCNR_mvy_hist[6]=di_im_di_rtnr_mcnr_statistic_12.mcnr_u3_sum;

		vc_nr_MCNR_mvx_hist[0]=di_im_di_rtnr_mcnr_statistic_11.mcnr_l10_sum;
		vc_nr_MCNR_mvx_hist[1]=di_im_di_rtnr_mcnr_statistic_11.mcnr_l9_sum;
		vc_nr_MCNR_mvx_hist[2]=di_im_di_rtnr_mcnr_statistic_10.mcnr_l8_sum;
		vc_nr_MCNR_mvx_hist[3]=di_im_di_rtnr_mcnr_statistic_10.mcnr_l7_sum;
		vc_nr_MCNR_mvx_hist[4]=di_im_di_rtnr_mcnr_statistic_9.mcnr_l6_sum;
		vc_nr_MCNR_mvx_hist[5]=di_im_di_rtnr_hmcnr_statistic_6.hmcnr_l5_sum;
		vc_nr_MCNR_mvx_hist[6]=di_im_di_rtnr_hmcnr_statistic_5.hmcnr_l4_sum;
		vc_nr_MCNR_mvx_hist[7]=di_im_di_rtnr_hmcnr_statistic_5.hmcnr_l3_sum;
		vc_nr_MCNR_mvx_hist[8]=di_im_di_rtnr_hmcnr_statistic_4.hmcnr_l2_sum;
		vc_nr_MCNR_mvx_hist[9]=di_im_di_rtnr_hmcnr_statistic_4.hmcnr_l1_sum;
		vc_nr_MCNR_mvx_hist[10]=di_im_di_rtnr_hmcnr_statistic_3.hmcnr_c0_sum;//-vc_nr_MCNR_static_hist;
		vc_nr_MCNR_mvx_hist[11]=di_im_di_rtnr_hmcnr_statistic_3.hmcnr_r1_sum;
		vc_nr_MCNR_mvx_hist[12]=di_im_di_rtnr_hmcnr_statistic_2.hmcnr_r2_sum;
		vc_nr_MCNR_mvx_hist[13]=di_im_di_rtnr_hmcnr_statistic_2.hmcnr_r3_sum;
		vc_nr_MCNR_mvx_hist[14]=di_im_di_rtnr_hmcnr_statistic_1.hmcnr_r4_sum;
		vc_nr_MCNR_mvx_hist[15]=di_im_di_rtnr_hmcnr_statistic_1.hmcnr_r5_sum;
		vc_nr_MCNR_mvx_hist[16]=di_im_di_rtnr_mcnr_statistic_9.mcnr_r6_sum;
		vc_nr_MCNR_mvx_hist[17]=di_im_di_rtnr_mcnr_statistic_8.mcnr_r7_sum;
		vc_nr_MCNR_mvx_hist[18]=di_im_di_rtnr_mcnr_statistic_8.mcnr_r8_sum;
		vc_nr_MCNR_mvx_hist[19]=di_im_di_rtnr_mcnr_statistic_7.mcnr_r9_sum;
		vc_nr_MCNR_mvx_hist[20]=di_im_di_rtnr_mcnr_statistic_7.mcnr_r10_sum;


		// find GMVx, GMVy  //////////////////////////
		for(i=0; i<7; i++)
		{
			il=i-1;
			ir=i+1;
		if (il<0)
			il=1;
		if (ir>6)
			il=5;
			mvy_hist_adj=max(vc_nr_MCNR_mvy_hist[il],vc_nr_MCNR_mvy_hist[ir]);
			if(mvy_hist_adj>vc_nr_MCNR_mvy_hist[i])
				mvy_hist_adj=vc_nr_MCNR_mvy_hist[i];

			mvy_hist_adj_add=mvy_hist_adj+vc_nr_MCNR_mvy_hist[i];

			if((mvy_hist_adj_add>max_hist_v) ||(mvy_hist_adj_add==max_hist_v && abs(i-3)<abs(max_hist_v_MV-3)))
			{
				max_hist_v=mvy_hist_adj_add;
				max_hist_v_MV=i;
			}

			sum_hist_v=sum_hist_v+vc_nr_MCNR_mvy_hist[i];
		}

		for(i=0; i<21; i++)
		{
			il=i-1;
			ir=i+1;
			if (il<0)		il=1;
			if (ir>20)		il=19;

if(i==9)	ir=8;
if(i==11)	il=12;

			mvx_hist_adj = max(vc_nr_MCNR_mvx_hist[il],vc_nr_MCNR_mvx_hist[ir]);
			if(mvx_hist_adj > vc_nr_MCNR_mvx_hist[i])
				mvx_hist_adj = vc_nr_MCNR_mvx_hist[i];

if(i==10)
	mvx_hist_adj=0;

			mvx_hist_adj_add = mvx_hist_adj+vc_nr_MCNR_mvx_hist[i];

			if((mvx_hist_adj_add>max_hist_h) ||(mvx_hist_adj_add==max_hist_h && abs(i-10)<abs(max_hist_h_MV-10)))
			{
				max_hist_h=mvx_hist_adj_add;
				max_hist_h_MV=i;
			}

			sum_hist_h=sum_hist_h+vc_nr_MCNR_mvx_hist[i];
		}


		if(sum_hist_h<=0)
			sum_hist_h=1;
		if(sum_hist_v<=0)
			sum_hist_v=1;


		Hpan_value=max_hist_h_MV;
		Vpan_value=max_hist_v_MV;

		GMVx = max_hist_h_MV;
		GMVy = max_hist_v_MV;
	//}

	if(mcnr_mode==0)
	{
		GMVy = max_hist_v_MV;

		GMVx = init_di_smd_gmvcoeff3_reg.smd_gmv1_x;

		GMV_ctr = smd_gmvcoeff1_reg.smd_gmv_ctr;
		maxGMV1_ctr = smd_gmvcoeff1_reg.smd_gmv1_max_ctr;
		maxGMV2_ctr = smd_gmvcoeff2_reg.smd_gmv2_max_ctr;
		maxGMV3_ctr = smd_gmvcoeff2_reg.smd_gmv3_max_ctr;

		if(sd_input==1)
		{
		Vpan_value=GMVy;//-(GMVy-3)+3;
			Hpan_value = New_Mcnr_Mv -7;

			if(((Hpan_value<=11 && Hpan_value>=9) && GMVx==3)&& (RTNR_MAD_count_Y_avg>980))//for interlace
			Hpan_value=10;
		}
		else
		{

			Vpan_value=GMVy;//-(GMVy-3)+3;
			Hpan_value= -(Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Rank[0]+1-17)+10;

			if(((Hpan_value<=11 && Hpan_value>=9) && GMVx==3))//for interlace
				Hpan_value=10;
		}
	}

//==================================Register change===============================================================

	//ration_TH0 = rtd_inl(0xb8022674); for debug
	//ration_TH = rtd_inl(0xb8022678);

//==============================================================================================================

	if(GMV_ctr==0)
		GMV_ctr=1;

	if(mcnr_mode==0)
	{
		GMV_ratio = maxGMV1_ctr*100/GMV_ctr;
		GMV_ratio_h = GMV_ratio;
		GMV_ratio_v = GMV_ratio;
	}
	else
	{
		GMV_ratio_v=max_hist_v*100/sum_hist_v;
		GMV_ratio_h=max_hist_h*100/sum_hist_h;
		GMV_ratio = min(GMV_ratio_h,GMV_ratio_v);
	}


	if(GMV_ratio>=100)
		GMV_ratio=100;

	if(GMV_ratio<0)
		GMV_ratio=0;

	if(Vpan_flag_n==1 && abs(GMVy1_acc-3)>=1)
		diff_th_v=1;
	else
		diff_th_v=0;

	if(Hpan_flag_n==1 && abs(GMVx1_acc-10)>=2)
		 diff_th_h=1;
	else
		 diff_th_h=0;

	 /// calculate GMVy //////////////////////////
	 ////////// calculate GMVy1 ////////////


	if(GMVy1_ctr_acc==0 && Vpan_value!=3  && GMV_ratio_v>=ration_TH_V  && Hpan_value==10&&vc_nr_MCNR_mvy_hist[Vpan_value]>0x1ff)
	{
		GMVy1_acc=Vpan_value;
		GMVy1_ctr_acc=GMVy1_ctr_acc+1;
	}
	else if((GMVy1_ctr_acc>0)&&Vpan_value!=3&&vc_nr_MCNR_mvy_hist[Vpan_value]>0x1ff)
	{
		if(abs(GMVy1_acc-Vpan_value)<=diff_th_v && Hpan_value==10)
		{
			GMVy1_acc=GMVy1_acc;
			if(GMV_ratio_v>=ration_TH_V)
			{
				if(GMVy1_acc==Vpan_value)
					GMVy1_ctr_acc=GMVy1_ctr_acc+1;
				else
					GMVy1_ctr_acc=GMVy1_ctr_acc;
			}
			else
				GMVy1_ctr_acc=GMVy1_ctr_acc-1;
		}
		else
		{
			GMVy1_acc=GMVy1_acc;
			GMVy1_ctr_acc=GMVy1_ctr_acc-2;

			if(GMVy1_ctr_acc<0)
				GMVy1_ctr_acc=0;
		}
	}

	  ////// calculate GMVy2 /////////////
	if(GMVy1_ctr_acc>=0 && (GMVy1_acc!=Vpan_value))
	{
		if(GMVy2_ctr_acc==0 && Vpan_value!=3 && GMV_ratio_v>=ration_TH_V&&vc_nr_MCNR_mvy_hist[Vpan_value]>0x1ff)
		{
			GMVy2_acc=Vpan_value;
		//	if(GMV_ratio>=ration_TH)
				GMVy2_ctr_acc=GMVy2_ctr_acc+1;
		}
		else if(GMVy2_ctr_acc>0)
		{
		//	if(abs(GMVy2_acc-Vpan_value)==0)
			if(abs(GMVy2_acc-Vpan_value)==0 && GMV_ratio_v>=ration_TH_V&&vc_nr_MCNR_mvy_hist[Vpan_value]>0x1ff)
			{
				GMVy2_acc=GMVy2_acc;
				GMVy2_ctr_acc=GMVy2_ctr_acc+1;
			}
			else
			{
				GMVy2_acc=Vpan_value;
				GMVy2_ctr_acc=0;
			}
		}
	}
	else if(GMVy2_ctr_acc>0)
		GMVy2_ctr_acc--;


	  // compare GMVy1 and GMVy2 ////
	if(GMVy2_ctr_acc>GMVy1_ctr_acc)
	{
		GMVy1_acc=GMVy2_acc;
		GMVy1_ctr_acc=GMVy2_ctr_acc-1;
	}
	if(GMVy2_ctr_acc<0)
		GMVy2_ctr_acc=0;

	if(GMVy1_ctr_acc<0)
		GMVy1_ctr_acc=0;


	if(GMVy2_ctr_acc>GMV_ctr_th)
		GMVy2_ctr_acc=GMV_ctr_th;
	if(GMVy1_ctr_acc>GMV_ctr_th)
		GMVy1_ctr_acc=GMV_ctr_th;

	if(GMVy1_ctr_acc>=7 || (Vpan_flag_n==1 && GMVy1_ctr_acc>=5))
        {
		Vpan_flag_n=1;
		//ROSPrintf("\n Vpan =%d \n ",Vpan_value);
		//ROSPrintf("\n hist[0] =%d ,hist[1] =%d hist[2] =%d \n ",vc_nr_MCNR_mvy_hist[0],vc_nr_MCNR_mvy_hist[1],vc_nr_MCNR_mvy_hist[2]);
		//ROSPrintf("\n hist[4] =%d ,hist[5] =%d hist[6] =%d \n ",vc_nr_MCNR_mvy_hist[4],vc_nr_MCNR_mvy_hist[5],vc_nr_MCNR_mvy_hist[6]);

	}
	else
		Vpan_flag_n=0;


	////////// calculate GMVx ////////////
	////////// calculate GMVx1 ////////////
	if(GMVx1_ctr_acc==0 && Hpan_value!=10  && GMV_ratio_h>=ration_TH_H && Vpan_value==3)
	{
		GMVx1_acc=Hpan_value;
		GMVx1_ctr_acc=GMVx1_ctr_acc+1;
	}
	else if(GMVx1_ctr_acc>0)
	{
		if(abs(GMVx1_acc-Hpan_value)<=diff_th_h && Vpan_value==3)
		{
			GMVx1_acc=GMVx1_acc;
			if(GMV_ratio_h>=ration_TH_H)
			{
				if(GMVx1_acc==Hpan_value)
					GMVx1_ctr_acc=GMVx1_ctr_acc+1;
				else
					GMVx1_ctr_acc=GMVx1_ctr_acc;
			}
			else
				GMVx1_ctr_acc=GMVx1_ctr_acc-1;
		}
		else
		{
			GMVx1_acc=GMVx1_acc;
			GMVx1_ctr_acc=GMVx1_ctr_acc-2;
			if(GMVx1_ctr_acc<0)
				GMVx1_ctr_acc=0;
		}
	}

	  ////// calculate GMVx2 /////////////
	if(GMVx1_ctr_acc>=0 && (GMVx1_acc!=Hpan_value))
	{
		if(GMVx2_ctr_acc==0 && Hpan_value!=10 && GMV_ratio_h>=ration_TH_H)
		{
			GMVx2_acc=Hpan_value;
			GMVx2_ctr_acc=GMVx2_ctr_acc+1;
		}
		else if(GMVx2_ctr_acc>0)
		{
		//	if(abs(GMVx2_acc-Hpan_value)==0)
			if(abs(GMVx2_acc-Hpan_value)==0 && GMV_ratio_h>=ration_TH_H)
			{
				GMVx2_acc=GMVx2_acc;
				GMVx2_ctr_acc=GMVx2_ctr_acc+1;
			}
			else
			{
				GMVx2_acc=Hpan_value;
				GMVx2_ctr_acc=0;
			}
		}
	}
	else if(GMVx2_ctr_acc>0)
		GMVx2_ctr_acc--;


	// compare GMVx1 and GMVx2 ////
	if(GMVx2_ctr_acc>GMVx1_ctr_acc)
	{
		GMVx1_acc=GMVx2_acc;
		GMVx1_ctr_acc=GMVx2_ctr_acc-1;
	}
	if(GMVx2_ctr_acc<0)
		GMVx2_ctr_acc=0;

	if(GMVx1_ctr_acc<0)
		GMVx1_ctr_acc=0;

	//int GMV_ctr_th=10;

	if(GMVx2_ctr_acc>GMV_ctr_th)
		GMVx2_ctr_acc=GMV_ctr_th;
	if(GMVx1_ctr_acc>GMV_ctr_th)
		GMVx1_ctr_acc=GMV_ctr_th;

	if(GMVx1_ctr_acc>=7 || (Hpan_flag_n==1 && GMVx1_ctr_acc>=5))
		Hpan_flag_n=1;
	else
		Hpan_flag_n=0;


	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.ID_Pattern_47==TRUE))
	{
		if(rtd_inl(0xb802267c)==0)
		{
			VIP_DEBUG_PRINTF("MC Hpan =%d ,Vpan=%d ,diff_th_h=%d \n",Hpan_value,Vpan_value,diff_th_h);
			VIP_DEBUG_PRINTF("GMVx1_ctr_acc =%d ,GMVx1_acc=%d \n",GMVx1_ctr_acc,GMVx1_acc);
			VIP_DEBUG_PRINTF("GMV_ratio_h =%d ,GMV_ratio_v=%d \n",GMV_ratio_h,GMV_ratio_v);
			VIP_DEBUG_PRINTF("Hpan_flag =%d ,Vpan_flag=%d \n",Hpan_flag_n,Vpan_flag_n);
		}
		else if(rtd_inl(0xb802267c)==1)
		{
			VIP_DEBUG_PRINTF("MC Hpan =%d ,Vpan=%d ,diff_th_v=%d \n",Hpan_value,Vpan_value,diff_th_v);
			VIP_DEBUG_PRINTF("GMVy1_ctr_acc =%d ,GMVy1_acc=%d \n",GMVy1_ctr_acc,GMVy1_acc);
			VIP_DEBUG_PRINTF("GMV_ratio_h =%d ,GMV_ratio_v=%d \n",GMV_ratio_h,GMV_ratio_v);
			VIP_DEBUG_PRINTF("Hpan_flag =%d ,Vpan_flag=%d \n",Hpan_flag_n,Vpan_flag_n);
		}
	}

	///////////////////////////
//	if((Hpan_value<=11 && Hpan_value>=9) && GMVx==3) //for interlace
//		Hpan_value=10;
	///////////////////////////

	//if(rtd_inl(0xb8022680)==1)
	{
	 scalerVIP_Cal_Idx_Ave_Hpan(Hpan_value,0);
	 scalerVIP_Cal_Idx_Ave_Hpan(Vpan_value,0);
	}
	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.ID_Pattern_47==TRUE))
	{

		if(rtd_inl(0xb802267c)==2)
		{
			VIP_DEBUG_PRINTF("Hpan_value =%d ,Vpan=%d \n",Hpan_value,Vpan_value);

		}
	}

	if((mcnr_mode==0)&&(sd_input ==1)) // if interlace mode & sd input
	{
		for (i=0; i<80; i++)
		{
			if (Smart_Integration_Status.SCREEN_HPAN_STATUS.Pass_Result_Sequence[i] == 1)
				hpan_pass_total++;
		}
		int pre_mv_avg = 0;
		for (i=0; i<16; i++) // pre 16 frames mv
		{
			pre_mv_avg+=(Smart_Integration_Status.SCREEN_HPAN_STATUS.Mv_Result_Sequence[i]-16);
		}
		pre_mv_avg/=16;

		int pass_total_th=30;

		if(Pan_flag==1)
		{
			 pass_total_th=10;
		 }

		//if((Hpan_value ==8)&&(DynamicOptimizeSystem[7]==1))



		if((Hpan_value ==8)&&(cur_source!=VIP_QUALITY_CVBS_NTSC)&&
			(cur_source!=VIP_QUALITY_CVBS_PAL))
		{
			di_im_new_mcnr_pan_condition.h_pan_mv_penalty =10;

			Hpan_value=9;
		}
		else
		{

			di_im_new_mcnr_pan_condition.h_pan_mv_penalty =3;

		}

//
		if(cur_source==VIP_QUALITY_CVBS_NTSC || cur_source==VIP_QUALITY_CVBS_PAL)
      			di_im_new_mcnr_pan_condition.h_pan_mv_penalty =5;


		di_im_new_mcnr_pan_condition.h_pan_mv_value = Hpan_value;
		di_im_new_mcnr_control4.n_mcnr_v_pan_mv = Vpan_value;


		//if (((pre_mv_avg >= -7 && pre_mv_avg <= 7 && hpan_pass_total > 20))&&SmartPic_clue->HMC_bin_hist_Ratio[16]<100)
		if ((((pre_mv_avg >= -7 && pre_mv_avg <= 7) && hpan_pass_total > pass_total_th))&& Smart_Integration_Status.SCREEN_MOTION_STATUS.MOTION_LEVEL > 10)
		{
                	Pan_flag=1;

			di_rtnr_output_clamp_reg.rtnr_output_clamp_en = 1; //set output clamp
			di_rtnr_output_clamp_reg.rtnr_output_clamp_luma = 64;
			di_rtnr_output_clamp_reg.rtnr_output_clamp_chroma = 64;

			di_im_new_mcnr_weighting_condition.mv_diff_slope = 0; // set mv diff slope

			// vpan value
		di_im_new_mcnr_control4.n_mcnr_v_pan_mv = 3;
			di_im_new_mcnr_control.n_h_pan_flag =1;
			di_im_new_mcnr_control.n_mcnr_offset = 0;
//			di_im_new_mcnr_pan_condition.h_pan_mv_value = Hpan_value;

			if(hpan_pass_total > 16)
			di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 12;
			else if(hpan_pass_total > 14)
				di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 8;
            		else if(hpan_pass_total > 12)
				di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 4;
			else if(hpan_pass_total > 10)
				di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 0;
			else
			{
				Pan_flag=0;
			}

		}
		else if(Vpan_flag_n==1 &&  Hpan_value==10 && abs(Vpan_value-3)>=1)//Hpan_flag_n==1)
		{
            		Pan_flag=1;

			di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 16;
			di_rtnr_output_clamp_reg.rtnr_output_clamp_en = 1; //set output clamp
			di_rtnr_output_clamp_reg.rtnr_output_clamp_luma = 64;
			di_rtnr_output_clamp_reg.rtnr_output_clamp_chroma = 64;
			di_im_new_mcnr_weighting_condition.mv_diff_slope = 0; // set mv diff slope

//			di_im_new_mcnr_control4.n_mcnr_v_pan_mv = 3;
			di_im_new_mcnr_control.n_h_pan_flag =1;
			di_im_new_mcnr_control.n_mcnr_offset = 0;

//			di_im_new_mcnr_control4.n_mcnr_v_pan_mv = Vpan_value;
			di_im_new_mcnr_pan_condition.h_pan_mv_value = 10;

		}
		else
		{
            		Pan_flag=0;

			di_im_new_mcnr_control.n_mcnr_offset = 2;
			di_im_new_mcnr_control.n_h_pan_flag =0 ;
			di_im_new_mcnr_weighting_condition.mv_diff_slope = 2;
			di_im_new_mcnr_control4.n_mcnr_v_pan_mv =3;
			di_rtnr_output_clamp_reg.rtnr_output_clamp_en =1;

			if (abs(GMVx-3)==0 && abs(GMVy-3)==0)
			{
				if(GMV_ratio>=95)
					di_im_new_mcnr_control.n_mcnr_offset = 6;
				else if(GMV_ratio>=90)
					di_im_new_mcnr_control.n_mcnr_offset = 5;
				else if(GMV_ratio>=85)
					di_im_new_mcnr_control.n_mcnr_offset = 4;
				else if(GMV_ratio>=80)
					di_im_new_mcnr_control.n_mcnr_offset = 3;
				else
					di_im_new_mcnr_control.n_mcnr_offset = 1;

				if(GMV_ratio>=90)
					di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 0;
				else
					di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 16;
			}
			else //if (abs(GMVx-3)<=1 && abs(GMVy-3)<=1)
			{
				di_im_new_mcnr_control.n_mcnr_offset = 2;
				di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 16;

			}
		}

		temp_x=abs(Hpan_value-10);//(abs(GMVx-3));
		temp_y=(abs(GMVy-3));
		temp_xy = max(temp_x,temp_y);

	        if(Pan_flag==0)
	        {

		if((temp_xy==0)&&(GMV_ratio>=80))
		{
			di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 0;
		}
		else if (temp_xy <= 1)
		{
			di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 10;
		}
		else if (temp_xy <= 2)
		{
			di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 12;
		}
		else if (temp_xy <= 3)
		{
			di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 14;
		}
		else
		{
			di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 16;
		}

		if(temp_x>10)
		{
			if(temp_x>20)
				temp_x=20;
			di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 20-temp_x;
 		}
		else if(temp_x>9)
		{
			di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 12;
 		}
		else if(temp_x>8)
		{
			di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 14;
		}
	        }

	}
	else if((mcnr_mode==0)&&(sd_input ==0)) // if interlace mode HD
	{
		for (i=0; i<120; i++)
		{
			if (Smart_Integration_Status.SCREEN_HPAN_STATUS.Pass_Result_Sequence[i] == 1)
				hpan_pass_total++;
		}
		int pre_mv_avg = 0;
		for (i=0; i<16; i++) // pre 16 frames mv
		{
			pre_mv_avg+=(Smart_Integration_Status.SCREEN_HPAN_STATUS.Mv_Result_Sequence[i]-16);
		}
		pre_mv_avg/=16;

		int pass_total_th=30;

		if(Pan_flag==1)
		{
			pass_total_th=10;
		}

		di_im_new_mcnr_pan_condition.h_pan_mv_penalty =3;

		di_im_new_mcnr_pan_condition.h_pan_mv_value = Hpan_value;
		di_im_new_mcnr_control4.n_mcnr_v_pan_mv = Vpan_value;


		//if (((pre_mv_avg >= -7 && pre_mv_avg <= 7 && hpan_pass_total > 20))&&SmartPic_clue->HMC_bin_hist_Ratio[16]<100)
		if (((pre_mv_avg >= -7 && pre_mv_avg <= 7 && hpan_pass_total > 20)))
		{
                	Pan_flag=1;

			di_rtnr_output_clamp_reg.rtnr_output_clamp_en = 1; //set output clamp
			di_rtnr_output_clamp_reg.rtnr_output_clamp_luma = 64;
			di_rtnr_output_clamp_reg.rtnr_output_clamp_chroma = 64;

			di_im_new_mcnr_weighting_condition.mv_diff_slope = 0; // set mv diff slope
			// vpan value
			di_im_new_mcnr_control4.n_mcnr_v_pan_mv = 3;
			di_im_new_mcnr_control.n_h_pan_flag =1;
			di_im_new_mcnr_control.n_mcnr_offset = 0;

			if(hpan_pass_total > 16)
			di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 16;
			else if(hpan_pass_total > 14)
				di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 8;
            		else if(hpan_pass_total > 12)
				di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 4;
			else if(hpan_pass_total > 10)
				di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 0;
			else
			{
				Pan_flag=0;
			}

		}
		else if(Vpan_flag_n==1 &&  Hpan_value==10 && abs(Vpan_value-3)>=1)//Hpan_flag_n==1)
		{
            		Pan_flag=1;

			di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 16;
			di_rtnr_output_clamp_reg.rtnr_output_clamp_en = 1; //set output clamp
			di_rtnr_output_clamp_reg.rtnr_output_clamp_luma = 64;
			di_rtnr_output_clamp_reg.rtnr_output_clamp_chroma = 64;
			di_im_new_mcnr_weighting_condition.mv_diff_slope = 0; // set mv diff slope

//			di_im_new_mcnr_control4.n_mcnr_v_pan_mv = 3;
			di_im_new_mcnr_control.n_h_pan_flag =1;
			di_im_new_mcnr_control.n_mcnr_offset = 0;

//			di_im_new_mcnr_control4.n_mcnr_v_pan_mv = Vpan_value;
			di_im_new_mcnr_pan_condition.h_pan_mv_value = 10;

		}
		else
		{
            		Pan_flag=0;

			di_im_new_mcnr_control.n_mcnr_offset = 2;
			di_im_new_mcnr_control.n_h_pan_flag =0 ;
			di_im_new_mcnr_weighting_condition.mv_diff_slope = 2;
			di_im_new_mcnr_control4.n_mcnr_v_pan_mv =3;
			di_rtnr_output_clamp_reg.rtnr_output_clamp_en =1;

			if (abs(GMVx-3)==0 && abs(GMVy-3)==0)
			{
				if(GMV_ratio>=95)
					di_im_new_mcnr_control.n_mcnr_offset = 6;
				else if(GMV_ratio>=90)
					di_im_new_mcnr_control.n_mcnr_offset = 5;
				else if(GMV_ratio>=85)
					di_im_new_mcnr_control.n_mcnr_offset = 4;
				else if(GMV_ratio>=80)
					di_im_new_mcnr_control.n_mcnr_offset = 3;
				else
					di_im_new_mcnr_control.n_mcnr_offset = 1;

				if(GMV_ratio>=90)
					di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 0;
				else
					di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 16;
			}
			else //if (abs(GMVx-3)<=1 && abs(GMVy-3)<=1)
			{
				di_im_new_mcnr_control.n_mcnr_offset = 1;
				di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 16;

			}




		}

		temp_x=abs(Hpan_value-10);//(abs(GMVx-3));
		temp_y=(abs(GMVy-3));
		temp_xy = max(temp_x,temp_y);
		mv_index =SmartPic_clue->HMC_bin_hist_Ratio[16];


	        if(Pan_flag==0)
	        {
	       //ROSPrintf("\n xy=%d , GMV_ratio=%d ",scalerVIP_Get_Noise_Level(),GMV_ratio);

			if((temp_xy==0)&&(GMV_ratio>=80))
	    		{
	    			di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 0;
				di_im_new_mcnr_weighting_condition.mv_diff_slope = 2;
	    		}
	    		else if (temp_xy <= 1)
	    		{
				if(GMV_ratio>=60)  // this patch for lg test disc #46
				{
					di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 10;
					di_im_new_mcnr_weighting_condition.mv_diff_slope = 1;
				}
				else if (GMV_ratio>=50)
				{
					di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 11;
					di_im_new_mcnr_weighting_condition.mv_diff_slope = 1;

				}
				else if(GMV_ratio>=40)
				{
					di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 12;
					di_im_new_mcnr_weighting_condition.mv_diff_slope = 1;

				}
				else
				{
					di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 13;
					di_im_new_mcnr_weighting_condition.mv_diff_slope = 1;
				}
	    		}
	    		else if (temp_xy <= 2)
	    		{

				if(GMV_ratio>=60)
				{
					di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 12;
					di_im_new_mcnr_weighting_condition.mv_diff_slope = 1;
				}
				else if (GMV_ratio>=50)
				{
					di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 13;
					di_im_new_mcnr_weighting_condition.mv_diff_slope = 1;

				}
				else if(GMV_ratio>=40)
				{
					di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 14;
					di_im_new_mcnr_weighting_condition.mv_diff_slope = 1;

				}
				else
				{
					di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 15;
					di_im_new_mcnr_weighting_condition.mv_diff_slope = 1;
				}
	    		}
	    		else if (temp_xy <= 3)
	    		{

				if(GMV_ratio>=60)
				{
					di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 14;
					di_im_new_mcnr_weighting_condition.mv_diff_slope = 1;
				}
				else if (GMV_ratio>=50)
				{
					di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 15;
					di_im_new_mcnr_weighting_condition.mv_diff_slope = 1;

				}
				else
				{
					di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 15;
					di_im_new_mcnr_weighting_condition.mv_diff_slope = 1;
				}
			}
			else
			{
	    			di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 16;
				di_im_new_mcnr_weighting_condition.mv_diff_slope = 0;
	    		}

		/*
	    		if(temp_x>10)
	    		{
	    			if(temp_x>20)
	    				temp_x=20;
	    			di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 20-temp_x;
	     		}
	    		else if(temp_x>9)
	    		{
	    			di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 12;
	     		}
	    		else if(temp_x>8)
	    		{
	    			di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 14;
	    		}
	    	*/
	        }


		if(mv_index<400) //add new condiction for #109
		{
			di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 16;
			di_im_new_mcnr_control.n_mcnr_offset = 1;
			di_im_new_mcnr_weighting_condition.mv_diff_slope = 1;


		}
		else if (mv_index>500) // for #46 background color noise
		{
			di_im_new_mcnr_control.n_mcnr_offset = 3;
			di_im_new_mcnr_weighting_condition.mv_diff_slope = 3;
		}
		/*
		else if (mv_index<400)
		{
			di_im_new_mcnr_control.n_mcnr_offset = 2;
			di_im_new_mcnr_weighting_condition.mv_diff_slope = 2;
		}
		else //noise very big or full motion
		{
			di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 0;
			di_im_new_mcnr_control.n_mcnr_offset = 6;
			di_im_new_mcnr_weighting_condition.mv_diff_slope = 4;
		}*/


	}
	else
	{

		Hpan_flag_n =0;//k2l progressive mode ,pan info easy mistake , disable it
		Vpan_flag_n =0;//k2l progressive mode ,pan info easy mistake , disable it

		if( Hpan_flag_n==1 && Vpan_value==3 && abs(Hpan_value-10)>=1)
		{
            		Pan_flag=1;

			di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 16;

			di_rtnr_output_clamp_reg.rtnr_output_clamp_en = 1; //set output clamp
			di_rtnr_output_clamp_reg.rtnr_output_clamp_luma = 64;
			di_rtnr_output_clamp_reg.rtnr_output_clamp_chroma = 64;

			di_im_new_mcnr_weighting_condition.mv_diff_slope = 0; // set mv diff slope


			// vpan value

			di_im_new_mcnr_control4.n_mcnr_v_pan_mv = 3;
			di_im_new_mcnr_control.n_h_pan_flag =1;
			di_im_new_mcnr_control.n_mcnr_offset = 0;


			di_im_new_mcnr_pan_condition.h_pan_mv_value = Hpan_value;
		}
		else if(Vpan_flag_n==1 &&  Hpan_value==10 && abs(Vpan_value-3)>=1)//Hpan_flag_n==1)
		{
           		 Pan_flag=1;

		//	di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 16;

			di_rtnr_output_clamp_reg.rtnr_output_clamp_en = 1; //set output clamp
			di_rtnr_output_clamp_reg.rtnr_output_clamp_luma = 64;
			di_rtnr_output_clamp_reg.rtnr_output_clamp_chroma = 64;

			di_im_new_mcnr_weighting_condition.mv_diff_slope = 0; // set mv diff slope


			di_im_new_mcnr_control4.n_mcnr_v_pan_mv = 3;
			di_im_new_mcnr_control.n_h_pan_flag =1;
			di_im_new_mcnr_control.n_mcnr_offset = 0;

			di_im_new_mcnr_control4.n_mcnr_v_pan_mv = Vpan_value;
			di_im_new_mcnr_pan_condition.h_pan_mv_value = 10;
		}

		else
		{
            		Pan_flag=0;

			di_im_new_mcnr_control.n_mcnr_offset = 2;
			di_im_new_mcnr_control.n_h_pan_flag =0 ;
			di_im_new_mcnr_weighting_condition.mv_diff_slope = 2;
			di_im_new_mcnr_control4.n_mcnr_v_pan_mv =0;
			di_rtnr_output_clamp_reg.rtnr_output_clamp_en =1;


			if (abs(GMVx-10)==0 && abs(GMVy-3)==0)
			{
				if(GMV_ratio>=95)
					di_im_new_mcnr_control.n_mcnr_offset = 6;
				else if(GMV_ratio>=90)
					di_im_new_mcnr_control.n_mcnr_offset = 5;
				else if(GMV_ratio>=85)
					di_im_new_mcnr_control.n_mcnr_offset = 4;
				else if(GMV_ratio>=80)
					di_im_new_mcnr_control.n_mcnr_offset = 3;
				else
					di_im_new_mcnr_control.n_mcnr_offset = 1;

			}
			else //if (abs(GMVx-3)<=1 && abs(GMVy-3)<=1)
			{
				di_im_new_mcnr_control.n_mcnr_offset = 2;
			//	di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 16;

			}

		}
        	if(Pan_flag==0)
	        {

			temp_x=(abs(GMVx-10));
			temp_y=(abs(GMVy-3));
			temp_xy = max(temp_x,temp_y);
			//ROSPrintf("\n xy=%d , GMV_ratio=%d ",scalerVIP_Get_Noise_Level(),GMV_ratio);

			if((temp_xy==0)&&(GMV_ratio>=90))
			{
				di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 0;
				di_im_new_mcnr_control.n_h_pan_flag =0;


			}
			else if((scalerVIP_Get_Noise_Level()<=2)) //this patch for hdr big hero building teeth.
			{
				di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 8;
				di_im_new_mcnr_weighting_condition.mv_diff_slope = 1;

			}
			else if (temp_xy <= 1)
			{
				di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 10;
			}
			else if (temp_xy <= 2)
			{
				di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 12;
			}
			else if (temp_xy <= 3)
			{
				di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 14;
			}
			else
			{
				di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 16;
			}
	        }
	}

	if((Pan_flag==0)&&DynamicOptimizeSystem[7]==1)
	{
		di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth =0;
	}

        ////////////////////////////////// special case
	//ROSPrintf("\n GMV =%d \n ",GMV_ratio);

#if 0
	ROSPrintf("gx =%d ,gy=%d ,gmx =%d , gmy =%d \n",init_di_smd_gmvcoeff3_reg.smd_gmv1_x,
		init_di_smd_gmvcoeff3_reg.smd_gmv1_y,di_di_smd_sampling_gmvb_reg.smd_gmvb_x,
		di_di_smd_sampling_gmvb_reg.smd_gmvb_y);

	{
		GMVx = 10+3-init_di_smd_gmvcoeff3_reg.smd_gmv1_x;
		GMVy = 3+3-init_di_smd_gmvcoeff3_reg.smd_gmv1_y;

		if(GMVy>4)
			GMVy=4;

		if(GMVx<9)
			GMVx=9;


		di_im_new_mcnr_pan_condition.h_pan_mv_value = GMVx;
		di_im_new_mcnr_control4.n_mcnr_v_pan_mv = GMVy;


	}

#endif


if((max_hist_h_MV==10)&&(sd_input==1))
{
	di_im_new_mcnr_control.n_h_pan_flag =0;
}
		//	di_im_new_mcnr_control.n_mcnr_offset = 1;
//	di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth=12;


	scalerVIP_DI_MiddleWare_MCNR_Set_Pan_Flag(di_im_new_mcnr_control.n_h_pan_flag);


    mv_value = SmartPic_clue->HMC_bin_hist_Ratio[15]+SmartPic_clue->HMC_bin_hist_Ratio[16]+SmartPic_clue->HMC_bin_hist_Ratio[17];


  //  ROSPrintf("\n hmc_C=%d ,r1=%d,L2 =%d ,mv_value =%d\n",SmartPic_clue->HMC_bin_hist_Ratio[16],SmartPic_clue->HMC_bin_hist_Ratio[15],SmartPic_clue->HMC_bin_hist_Ratio[17],mv_value);

  //  if((Pan_flag==0)&&mv_value>800)
  //      di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth=0;

	rtd_outl(DI_IM_DI_RTNR_HMCNR_reg, di_rtnr_hmcnr_reg.regValue);
	rtd_outl(DI_RTNR_OUTPUT_CLAMP_reg, di_rtnr_output_clamp_reg.regValue);
	rtd_outl(DI_IM_NEW_MCNR_WEIGHTING_CONDITION_reg, di_im_new_mcnr_weighting_condition.regValue);
	rtd_outl(DI_IM_NEW_MCNR_CONTROL4_reg, di_im_new_mcnr_control4.regValue);
	rtd_outl(DI_IM_NEW_MCNR_CONTROL_reg, di_im_new_mcnr_control.regValue);
	rtd_outl(DI_IM_NEW_MCNR_PAN_CONDITION_reg, di_im_new_mcnr_pan_condition.regValue);
	rtd_outl(DI_IM_NEW_MCNR_CLAMPING_VALUE_reg,di_im_new_mcnr_clamping_value.regValue);


}
void scalerVIP_DI_MiddleWare_MCNR_Ctrl2(UINT8 weight)
{
	di_im_new_mcnr_pan_condition_RBUS di_im_new_mcnr_pan_condition;
	di_im_new_mcnr_control4_RBUS di_im_new_mcnr_control4;
	di_im_new_mcnr_control_RBUS di_im_new_mcnr_control;

	di_im_new_mcnr_pan_condition.regValue = rtd_inl(DI_IM_NEW_MCNR_PAN_CONDITION_reg);
	di_im_new_mcnr_control4.regValue = rtd_inl(DI_IM_NEW_MCNR_CONTROL4_reg);
	di_im_new_mcnr_control.regValue = rtd_inl(DI_IM_NEW_MCNR_CONTROL_reg);

	int vc_nr_MCNR_mvx_hist[31]={15};
	int vc_nr_MCNR_mvy_hist[15]={6};
	int i;


	di_im_di_rtnr_hmcnr_statistic_1_RBUS di_im_di_rtnr_hmcnr_statistic_1;
	di_im_di_rtnr_hmcnr_statistic_2_RBUS di_im_di_rtnr_hmcnr_statistic_2;
	di_im_di_rtnr_hmcnr_statistic_3_RBUS di_im_di_rtnr_hmcnr_statistic_3;
	di_im_di_rtnr_hmcnr_statistic_4_RBUS di_im_di_rtnr_hmcnr_statistic_4;
	di_im_di_rtnr_hmcnr_statistic_5_RBUS di_im_di_rtnr_hmcnr_statistic_5;
	di_im_di_rtnr_hmcnr_statistic_6_RBUS di_im_di_rtnr_hmcnr_statistic_6;

	di_im_di_rtnr_mcnr_statistic_7_RBUS di_im_di_rtnr_mcnr_statistic_7;
	di_im_di_rtnr_mcnr_statistic_8_RBUS di_im_di_rtnr_mcnr_statistic_8;
	di_im_di_rtnr_mcnr_statistic_9_RBUS di_im_di_rtnr_mcnr_statistic_9;
	di_im_di_rtnr_mcnr_statistic_10_RBUS di_im_di_rtnr_mcnr_statistic_10;
	di_im_di_rtnr_mcnr_statistic_11_RBUS di_im_di_rtnr_mcnr_statistic_11;
	di_im_di_rtnr_mcnr_statistic_12_RBUS di_im_di_rtnr_mcnr_statistic_12;
	di_im_di_rtnr_mcnr_statistic_13_RBUS di_im_di_rtnr_mcnr_statistic_13;
	di_im_di_rtnr_mcnr_statistic_14_RBUS di_im_di_rtnr_mcnr_statistic_14;
	di_im_di_rtnr_mcnr_statistic_15_RBUS di_im_di_rtnr_mcnr_statistic_15;
	di_im_di_rtnr_mcnr_statistic_16_RBUS di_im_di_rtnr_mcnr_statistic_16;
	di_im_di_rtnr_mcnr_statistic_17_RBUS di_im_di_rtnr_mcnr_statistic_17;
	di_im_di_rtnr_mcnr_statistic_18_RBUS di_im_di_rtnr_mcnr_statistic_18;
	di_im_di_rtnr_mcnr_statistic_19_RBUS di_im_di_rtnr_mcnr_statistic_19;
	di_im_di_rtnr_mcnr_statistic_20_RBUS di_im_di_rtnr_mcnr_statistic_20;
	di_im_di_rtnr_mcnr_statistic_21_RBUS di_im_di_rtnr_mcnr_statistic_21;
	di_im_di_rtnr_mcnr_statistic_22_RBUS di_im_di_rtnr_mcnr_statistic_22;
	di_im_di_rtnr_mcnr_statistic_23_RBUS di_im_di_rtnr_mcnr_statistic_23;


	di_im_di_rtnr_hmcnr_statistic_1.regValue = rtd_inl(DI_IM_DI_RTNR_HMCNR_STATISTIC_1_reg);
	di_im_di_rtnr_hmcnr_statistic_2.regValue = rtd_inl(DI_IM_DI_RTNR_HMCNR_STATISTIC_2_reg);
	di_im_di_rtnr_hmcnr_statistic_3.regValue = rtd_inl(DI_IM_DI_RTNR_HMCNR_STATISTIC_3_reg);
	di_im_di_rtnr_hmcnr_statistic_4.regValue = rtd_inl(DI_IM_DI_RTNR_HMCNR_STATISTIC_4_reg);
	di_im_di_rtnr_hmcnr_statistic_5.regValue = rtd_inl(DI_IM_DI_RTNR_HMCNR_STATISTIC_5_reg);
	di_im_di_rtnr_hmcnr_statistic_6.regValue = rtd_inl(DI_IM_DI_RTNR_HMCNR_STATISTIC_6_reg);

	di_im_di_rtnr_mcnr_statistic_7.regValue  = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_7_reg);
	di_im_di_rtnr_mcnr_statistic_8.regValue  = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_8_reg);
	di_im_di_rtnr_mcnr_statistic_9.regValue  = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_9_reg);
	di_im_di_rtnr_mcnr_statistic_10.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_10_reg);
	di_im_di_rtnr_mcnr_statistic_11.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_11_reg);
	di_im_di_rtnr_mcnr_statistic_12.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_12_reg);
	di_im_di_rtnr_mcnr_statistic_13.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_13_reg);
	di_im_di_rtnr_mcnr_statistic_14.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_14_reg);
	di_im_di_rtnr_mcnr_statistic_15.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_15_reg);
	di_im_di_rtnr_mcnr_statistic_16.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_16_reg);
	di_im_di_rtnr_mcnr_statistic_17.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_17_reg);
	di_im_di_rtnr_mcnr_statistic_18.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_18_reg);
	di_im_di_rtnr_mcnr_statistic_19.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_19_reg);
	di_im_di_rtnr_mcnr_statistic_20.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_20_reg);
	di_im_di_rtnr_mcnr_statistic_21.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_21_reg);
	di_im_di_rtnr_mcnr_statistic_22.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_22_reg);
	di_im_di_rtnr_mcnr_statistic_23.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_23_reg);



	vc_nr_MCNR_mvx_hist[0]=di_im_di_rtnr_mcnr_statistic_19.mcnr_l15_sum;//4a94[15:0]
	vc_nr_MCNR_mvx_hist[1]=di_im_di_rtnr_mcnr_statistic_19.mcnr_l14_sum;//4a94[31:16]
	vc_nr_MCNR_mvx_hist[2]=di_im_di_rtnr_mcnr_statistic_20.mcnr_l13_sum;//4a98[15:0]
	vc_nr_MCNR_mvx_hist[3]=di_im_di_rtnr_mcnr_statistic_20.mcnr_l12_sum;//4a98[31:16]
	vc_nr_MCNR_mvx_hist[4]=di_im_di_rtnr_mcnr_statistic_21.mcnr_l11_sum;//4a9c[15:0]
	vc_nr_MCNR_mvx_hist[5]=di_im_di_rtnr_mcnr_statistic_11.mcnr_l10_sum;//499c[15:0]
	vc_nr_MCNR_mvx_hist[6]=di_im_di_rtnr_mcnr_statistic_11.mcnr_l9_sum;//499c[31:16]
	vc_nr_MCNR_mvx_hist[7]=di_im_di_rtnr_mcnr_statistic_10.mcnr_l8_sum;//4a98[15:0]
	vc_nr_MCNR_mvx_hist[8]=di_im_di_rtnr_mcnr_statistic_10.mcnr_l7_sum;//4a98[31:16]
	vc_nr_MCNR_mvx_hist[9]=di_im_di_rtnr_mcnr_statistic_9.mcnr_l6_sum;//4a94[15:0]
	vc_nr_MCNR_mvx_hist[10]=di_im_di_rtnr_hmcnr_statistic_6.hmcnr_l5_sum;//4858[31:16]
	vc_nr_MCNR_mvx_hist[11]=di_im_di_rtnr_hmcnr_statistic_5.hmcnr_l4_sum;//4854[15:0]
	vc_nr_MCNR_mvx_hist[12]=di_im_di_rtnr_hmcnr_statistic_5.hmcnr_l3_sum;//4854[31:16]
	vc_nr_MCNR_mvx_hist[13]=di_im_di_rtnr_hmcnr_statistic_4.hmcnr_l2_sum;//4850[15:0]
	vc_nr_MCNR_mvx_hist[14]=di_im_di_rtnr_hmcnr_statistic_4.hmcnr_l1_sum;//4850[31:16]
	vc_nr_MCNR_mvx_hist[15]=di_im_di_rtnr_hmcnr_statistic_3.hmcnr_c0_sum;//484c[15:0]
	vc_nr_MCNR_mvx_hist[16]=di_im_di_rtnr_hmcnr_statistic_3.hmcnr_r1_sum;//484c[31:16]
	vc_nr_MCNR_mvx_hist[17]=di_im_di_rtnr_hmcnr_statistic_2.hmcnr_r2_sum;//4848[15:0]
	vc_nr_MCNR_mvx_hist[18]=di_im_di_rtnr_hmcnr_statistic_2.hmcnr_r3_sum;//4848[31:16]
	vc_nr_MCNR_mvx_hist[19]=di_im_di_rtnr_hmcnr_statistic_1.hmcnr_r4_sum;//4844[15:0]
	vc_nr_MCNR_mvx_hist[20]=di_im_di_rtnr_hmcnr_statistic_1.hmcnr_r5_sum;//4844[31:16]
	vc_nr_MCNR_mvx_hist[21]=di_im_di_rtnr_mcnr_statistic_9.mcnr_r6_sum;//4a94[31:16]
	vc_nr_MCNR_mvx_hist[22]=di_im_di_rtnr_mcnr_statistic_8.mcnr_r7_sum;//4a90[15:0]
	vc_nr_MCNR_mvx_hist[23]=di_im_di_rtnr_mcnr_statistic_8.mcnr_r8_sum;//4a90[31:16]
	vc_nr_MCNR_mvx_hist[24]=di_im_di_rtnr_mcnr_statistic_7.mcnr_r9_sum;//4a8c[15:0]
	vc_nr_MCNR_mvx_hist[25]=di_im_di_rtnr_mcnr_statistic_7.mcnr_r10_sum;//4a8c[31:16]
	vc_nr_MCNR_mvx_hist[26]=di_im_di_rtnr_mcnr_statistic_21.mcnr_r11_sum;//4a9c[31:16]
	vc_nr_MCNR_mvx_hist[27]=di_im_di_rtnr_mcnr_statistic_22.mcnr_r12_sum;//4aa0[15:0]
	vc_nr_MCNR_mvx_hist[28]=di_im_di_rtnr_mcnr_statistic_22.mcnr_r13_sum;//4aa0[31:16]
	vc_nr_MCNR_mvx_hist[29]=di_im_di_rtnr_mcnr_statistic_23.mcnr_r14_sum;//4aa4[15:10]
	vc_nr_MCNR_mvx_hist[30]=di_im_di_rtnr_mcnr_statistic_23.mcnr_r15_sum;//4aa4[31:16]



	vc_nr_MCNR_mvy_hist[0]=di_im_di_rtnr_mcnr_statistic_18.mcnr_d6_sum;//4a90[15:0]
	vc_nr_MCNR_mvy_hist[1]=di_im_di_rtnr_mcnr_statistic_17.mcnr_d5_sum;//4a8c[15:0]
	vc_nr_MCNR_mvy_hist[2]=di_im_di_rtnr_mcnr_statistic_17.mcnr_d4_sum;//4a8c[31:16]
	vc_nr_MCNR_mvy_hist[3]=di_im_di_rtnr_mcnr_statistic_15.mcnr_d3_sum;//4a0c[31:16]
	vc_nr_MCNR_mvy_hist[4]=di_im_di_rtnr_mcnr_statistic_14.mcnr_d2_sum;//4a08[15:0]
	vc_nr_MCNR_mvy_hist[5]=di_im_di_rtnr_mcnr_statistic_14.mcnr_d1_sum;//4a08[31:16]
	vc_nr_MCNR_mvy_hist[6]=di_im_di_rtnr_mcnr_statistic_13.mcnr_v0_sum;//4a04[15:0]
	vc_nr_MCNR_mvy_hist[7]=di_im_di_rtnr_mcnr_statistic_13.mcnr_u1_sum;//4a04[31:16]
	vc_nr_MCNR_mvy_hist[8]=di_im_di_rtnr_mcnr_statistic_12.mcnr_u2_sum;//4a00[15:0]
	vc_nr_MCNR_mvy_hist[9]=di_im_di_rtnr_mcnr_statistic_12.mcnr_u3_sum;//4a00[31:16]
	vc_nr_MCNR_mvy_hist[10]=di_im_di_rtnr_mcnr_statistic_16.mcnr_u4_sum;//4a88[15:0]
	vc_nr_MCNR_mvy_hist[11]=di_im_di_rtnr_mcnr_statistic_16.mcnr_u5_sum;//4a88[31:16]
	vc_nr_MCNR_mvy_hist[12]=di_im_di_rtnr_mcnr_statistic_18.mcnr_u6_sum;//4a90[31:16]







	int mcnr_static_sum=di_im_di_rtnr_mcnr_statistic_15.mcnr_static_sum;//4a0c[15:0]



	int sum_h=0;
	int sum_v=0;

	for(i=0; i<31; i++)
	{
		vc_nr_MCNR_mvx_hist[i]=(vc_nr_MCNR_mvx_hist[i]>>4);
		sum_h=sum_h+vc_nr_MCNR_mvx_hist[i];

		if (i==15)
				vc_nr_MCNR_mvx_hist[i]=vc_nr_MCNR_mvx_hist[i]-(mcnr_static_sum>>4);
	}

	int il, ir;
	int mvx_hist_adj ;
	int	max_hist_h=0;
	int max_hist_h_MV=0;
	int	max_hist_v=0;
	int max_hist_v_MV=0;
	int mvx_hist_l, mvx_hist_r;

	int mvx_hist_adj_add;
	int mvy_hist_adj_add;
	int max_hist_h_lr;
	int max_hist_v_lr;

	for(i=0; i<31; i++)
	{
			il=i-1;
	    ir=i+1;
	    if (il<0)		il=1;
	    if (ir>30)		il=29;

	    mvx_hist_adj = max(vc_nr_MCNR_mvx_hist[il],vc_nr_MCNR_mvx_hist[ir]);

	    if(mvx_hist_adj > vc_nr_MCNR_mvx_hist[i])
	       mvx_hist_adj = vc_nr_MCNR_mvx_hist[i];

	    mvx_hist_adj_add = mvx_hist_adj+vc_nr_MCNR_mvx_hist[i];

	    if((mvx_hist_adj_add>max_hist_h) ||(mvx_hist_adj_add==max_hist_h && abs(i-15)<abs(max_hist_h_MV-15)))
	    {
	       max_hist_h=mvx_hist_adj_add;
	       max_hist_h_MV=i;
	    }
	}


	il=max_hist_h_MV-1;
	ir=max_hist_h_MV+1;
	if (il<0)	    il=1;
	if (ir>30)	    il=29;

	mvx_hist_l=vc_nr_MCNR_mvx_hist[il];
	mvx_hist_r=vc_nr_MCNR_mvx_hist[ir];

	if(mvx_hist_l > vc_nr_MCNR_mvx_hist[max_hist_h_MV])
	  mvx_hist_l = vc_nr_MCNR_mvx_hist[max_hist_h_MV];

	if(mvx_hist_r > vc_nr_MCNR_mvx_hist[max_hist_h_MV])
	  mvx_hist_r = vc_nr_MCNR_mvx_hist[max_hist_h_MV];

	max_hist_h_lr = mvx_hist_l+mvx_hist_r+vc_nr_MCNR_mvx_hist[max_hist_h_MV];


	if((mcnr_static_sum>>4)>max_hist_h)
	{
		max_hist_h=mcnr_static_sum>>4;
	  max_hist_h_MV=15;
	}





	for(i=0; i<13; i++)
	{
			vc_nr_MCNR_mvy_hist[i]=(vc_nr_MCNR_mvy_hist[i]>>4);
			sum_v=sum_v+vc_nr_MCNR_mvy_hist[i];

			if (i==6)
				vc_nr_MCNR_mvy_hist[i]=vc_nr_MCNR_mvy_hist[i]-(mcnr_static_sum>>4);
		}

	int mvy_hist_adj=0;
	int mvy_hist_l=0;
	int mvy_hist_r=0;

	for(i=0; i<13; i++)
	{
			il=i-1;
	    ir=i+1;
	    if (il<0)		 il=1;
	    if (ir>12)		 il=11;

	    mvy_hist_adj=max(vc_nr_MCNR_mvy_hist[il],vc_nr_MCNR_mvy_hist[ir]);

	    if(mvy_hist_adj > vc_nr_MCNR_mvy_hist[i])
	       mvy_hist_adj = vc_nr_MCNR_mvy_hist[i];

			mvy_hist_adj_add=mvy_hist_adj+vc_nr_MCNR_mvy_hist[i];

	    if((mvy_hist_adj_add>max_hist_v) ||(mvy_hist_adj_add==max_hist_v && abs(i-6)<abs(max_hist_v_MV-6)))
	    {
		max_hist_v=mvy_hist_adj_add;
		max_hist_v_MV=i;
	    }
	}

	il=max_hist_v_MV-1;
	ir=max_hist_v_MV+1;
	if (il<0)	     il=1;
	if (ir>12)	     il=11;

	mvy_hist_l=vc_nr_MCNR_mvy_hist[il];
	mvy_hist_r=vc_nr_MCNR_mvy_hist[ir];

	if(mvy_hist_l > vc_nr_MCNR_mvy_hist[max_hist_v_MV])
	    mvy_hist_l = vc_nr_MCNR_mvy_hist[max_hist_v_MV];

	if(mvy_hist_r > vc_nr_MCNR_mvy_hist[max_hist_v_MV])
	    mvy_hist_r = vc_nr_MCNR_mvy_hist[max_hist_v_MV];

	max_hist_v_lr=vc_nr_MCNR_mvy_hist[max_hist_v_MV]+mvy_hist_l+mvy_hist_r;



	if((mcnr_static_sum>>4)>max_hist_v)
	{
		max_hist_v=mcnr_static_sum>>4;
	    max_hist_v_MV=6;
	}



	if(sum_h==0)
		sum_h=100;

	if(sum_v==0)
		sum_v=100;

	//int reg_h_pan_mv=max_hist_h_MV;
	//int reg_v_pan_mv=max_hist_v_MV;





	/////////////////////////////////////////////
	/////////////////////////////////////////////////////

	static int Vpan_flag_n=0;
	static int Hpan_flag_n=0;
	static int GMVy1_ctr_acc=0;
	static int GMVy2_ctr_acc=0;
	static int GMVx1_ctr_acc=0;
	static int GMVx2_ctr_acc=0;
	static int GMVy1_acc=0;
	static int GMVy2_acc=0;
	static int GMVx1_acc=0;
	static int GMVx2_acc=0;


	int diff_th_v=0;
	int diff_th_h=0;
	int GMVy1_acc_old=0;
	int GMVy1_ctr_acc_old=0;
	int GMVx1_acc_old=0;
	int GMVx1_ctr_acc_old=0;




	int ratio_TH0=50;
	int GMV_ctr_th=10;
	int ratio_TH1=25;//35;//20;//35;
	bool ratio0_flag=0;
	bool ratio1_flag=0;
	bool ratio0_flag_v=0;
	bool ratio1_flag_v=0;

	int reg_vc_nr_HMCNR_search_range_full=15;
	int reg_vc_nr_MCNR_V_search_range_full=6;


	if(Hpan_flag_n==1 && Vpan_flag_n==1)
			ratio_TH0=25;//35;
	else
			ratio_TH0=50;//50;//40;//50;


	int GMVx=max_hist_h_MV-reg_vc_nr_HMCNR_search_range_full;
	int GMVy=max_hist_v_MV-reg_vc_nr_MCNR_V_search_range_full;

	int GMV_ratio_v=max_hist_v*100/sum_v;
	int GMV_ratio_h=max_hist_h*100/sum_h;

	int GMV_ratio_v_lr=max_hist_v_lr*100/sum_v;
	int GMV_ratio_h_lr=max_hist_h_lr*100/sum_h;

	int ratio_static= 0;
	ratio_static =(mcnr_static_sum>>4)*100/sum_h;


	int diff_range3_h;
	int diff_range3_v;

	if(GMV_ratio_h>=100)	  GMV_ratio_h=100;
	if(GMV_ratio_h<0)	  GMV_ratio_h=0;

	if(GMV_ratio_v>=100)	  GMV_ratio_v=100;
	if(GMV_ratio_v<0)	  GMV_ratio_v=0;

	if(GMV_ratio_h_lr>=100)      GMV_ratio_h_lr=100;
	if(GMV_ratio_h_lr<0)	     GMV_ratio_h_lr=0;

	if(GMV_ratio_v_lr>=100)      GMV_ratio_v_lr=100;
	if(GMV_ratio_v_lr<0)	     GMV_ratio_v_lr=0;



	if(GMV_ratio_v>=ratio_TH1)
	{
		ratio1_flag_v=1;
		diff_range3_v=1;
	}
	else if(GMV_ratio_v_lr>=ratio_TH1 && Vpan_flag_n==1 && Hpan_flag_n==1)
	{
		ratio1_flag_v=1;
		diff_range3_v=2;
	}
	else
	{
		ratio1_flag_v=0;
		diff_range3_v=2;
	}

	if(GMV_ratio_v>=ratio_TH0)
	{
		ratio0_flag_v=1;
		diff_range3_v=1;
	}
	else if(GMV_ratio_v_lr>=ratio_TH0 && Vpan_flag_n==1 && Hpan_flag_n==1)
	{
		ratio0_flag_v=1;
		diff_range3_v=2;
	}
	else
	{
		ratio0_flag_v=0;
		diff_range3_v=2;
	}


	if(GMV_ratio_h>=ratio_TH1)
	{
		ratio1_flag=1;
		diff_range3_h=1;
	}
	else if(GMV_ratio_h_lr>=ratio_TH1 && Vpan_flag_n==1 && Hpan_flag_n==1)
	{
		ratio1_flag=1;
		diff_range3_h=2;
	}
	else
	{
		ratio1_flag=0;
		diff_range3_h=2;
	}

	if(GMV_ratio_h>=ratio_TH0)
	{
		ratio0_flag=1;
		diff_range3_h=1;
	}
	else if(GMV_ratio_h_lr>=ratio_TH0 && Vpan_flag_n==1 && Hpan_flag_n==1)
	{
		ratio0_flag=1;
		diff_range3_h=2;
	}
	else
	{
		ratio0_flag=0;
		diff_range3_h=2;
	}


	if(Vpan_flag_n==1 && abs(GMVy1_acc)>=1)
	  diff_th_v=1;
	else
	  diff_th_v=1;


	if(Hpan_flag_n==1 && abs(GMVx1_acc)>=1)
	  diff_th_h=1;
	else
	  diff_th_h=1;


	int static_flag=1;
	if(GMVy!=0 || GMVx!=0)
		static_flag=0;
	else
		static_flag=1;


	/// calculate GMVy //////////////////////////
	if(GMVy1_ctr_acc==0 && ratio1_flag_v && static_flag==0)
	{
	  GMVy1_acc=GMVy;
	  GMVy1_ctr_acc=GMVy1_ctr_acc+1;
	}
	else if(GMVy1_ctr_acc>0)
	{
	  if(abs(GMVy1_acc-GMVy)<=diff_th_v)
	  {
	    GMVy1_acc=GMVy1_acc;

			if(ratio0_flag_v)
	    {
	       if(GMVy1_acc==GMVy && static_flag==0)
					GMVy1_ctr_acc=GMVy1_ctr_acc+1;
	       else
		GMVy1_ctr_acc=GMVy1_ctr_acc;
	    }
			else
					GMVy1_ctr_acc=GMVy1_ctr_acc-1;
	  }
	  else if(abs(GMVy1_acc-GMVy)<=2)
	  {
	    GMVy1_acc=GMVy1_acc;
			GMVy1_ctr_acc=GMVy1_ctr_acc-1;
	  }
	  else
	  {
	    GMVy1_acc=GMVy1_acc;
			GMVy1_ctr_acc=GMVy1_ctr_acc-2;
	  }
	}
	if(GMVy1_ctr_acc<0)
		GMVy1_ctr_acc=0;

	if(GMVy1_ctr_acc>GMV_ctr_th)
	  GMVy1_ctr_acc=GMV_ctr_th;



	////// calculate GMVy2 /////////////
	if((GMVy1_acc!=GMVy))
	{
		if(GMVy2_ctr_acc==0 && ratio1_flag_v  && static_flag==0)
	  {
			GMVy2_acc=GMVy;
	    GMVy2_ctr_acc=GMVy2_ctr_acc+1;
	  }
	  else if(GMVy2_ctr_acc>0 && ratio0_flag_v)
	  {
	    if(abs(GMVy2_acc-GMVy)==0  && static_flag==0)
	    {
				GMVy2_acc=GMVy2_acc;
	      GMVy2_ctr_acc=GMVy2_ctr_acc+1;
	    }
	    else
	    {
	      GMVy2_acc=GMVy;
				GMVy2_ctr_acc=1;
	    }
	  }
		else
		{
			GMVy2_ctr_acc--;
		}
	}
	else
		GMVy2_ctr_acc--;

	if(GMVy2_ctr_acc<0)
		GMVy2_ctr_acc=0;

	if(GMVy2_ctr_acc>GMV_ctr_th)
		GMVy2_ctr_acc=GMV_ctr_th;


	// compare GMVy1 and GMVy2 ////
	GMVy1_acc_old=GMVy1_acc;
	GMVy1_ctr_acc_old=GMVy1_ctr_acc;

	if(GMVy2_ctr_acc>GMVy1_ctr_acc ||(GMVy2_ctr_acc==GMVy1_ctr_acc && GMVy2_ctr_acc==GMV_ctr_th))
	{
		GMVy1_acc=GMVy2_acc;
	  GMVy1_ctr_acc=GMVy2_ctr_acc;
	}

	if(GMVy1_ctr_acc>=5 || (Vpan_flag_n==1 && GMVy1_ctr_acc>=3))
	  Vpan_flag_n=1;
	else
	  Vpan_flag_n=0;




	/// calculate GMVx //////////////////////////
	if(GMVx1_ctr_acc==0 && ratio1_flag  && static_flag==0)
	{
	  GMVx1_acc=GMVx;
	  GMVx1_ctr_acc=GMVx1_ctr_acc+1;
	}
	else if(GMVx1_ctr_acc>0)
	{
	  if(abs(GMVx1_acc-GMVx)<=diff_th_h)
	  {
			GMVx1_acc=GMVx1_acc;

			if(ratio0_flag)
	    {
	      if(GMVx1_acc==GMVx  && static_flag==0)
					GMVx1_ctr_acc=GMVx1_ctr_acc+1;
	      else
		GMVx1_ctr_acc=GMVx1_ctr_acc;
	    }
			else
				GMVx1_ctr_acc=GMVx1_ctr_acc-1;
	  }
		else if(abs(GMVx1_acc-GMVx)<=2)
	  {
			GMVx1_acc=GMVx1_acc;
			GMVx1_ctr_acc=GMVx1_ctr_acc-1;
		}
	  else
	  {
	    GMVx1_acc=GMVx1_acc;
			GMVx1_ctr_acc=GMVx1_ctr_acc-2;
	  }
	}
	if(GMVx1_ctr_acc<0)
		GMVx1_ctr_acc=0;

	if(GMVx1_ctr_acc>GMV_ctr_th)
	  GMVx1_ctr_acc=GMV_ctr_th;



	////// calculate GMVx2 /////////////
	if((GMVx1_acc!=GMVx))
	{
		if(GMVx2_ctr_acc==0 && ratio1_flag  && static_flag==0)
	  {
			GMVx2_acc=GMVx;
	    GMVx2_ctr_acc=GMVx2_ctr_acc+1;
	  }
	  else if(GMVx2_ctr_acc>0 && ratio0_flag)
	  {
	    if(abs(GMVx2_acc-GMVx)==0  && static_flag==0)
	    {
				GMVx2_acc=GMVx2_acc;
	      GMVx2_ctr_acc=GMVx2_ctr_acc+1;
	    }
	    else
	    {
	      GMVx2_acc=GMVx;
				GMVx2_ctr_acc=1;
	    }
	  }
		else
		{
			GMVx2_ctr_acc--;
		}
	}
	else
		GMVx2_ctr_acc--;

	if(GMVx2_ctr_acc<0)
		GMVx2_ctr_acc=0;

	if(GMVx2_ctr_acc>GMV_ctr_th)
		GMVx2_ctr_acc=GMV_ctr_th;

	// compare GMVx1 and GMVx2 ////
	GMVx1_acc_old=GMVx1_acc;
	GMVx1_ctr_acc_old=GMVx1_ctr_acc;

	if(GMVx2_ctr_acc>GMVx1_ctr_acc ||(GMVx2_ctr_acc==GMVx1_ctr_acc && GMVx2_ctr_acc==GMV_ctr_th))
	{
		GMVx1_acc=GMVx2_acc;
	  GMVx1_ctr_acc=GMVx2_ctr_acc;
	}



	if(GMVx1_ctr_acc>=3 || (Hpan_flag_n==1 && GMVx1_ctr_acc>=3))
		Hpan_flag_n=1;
	else
		Hpan_flag_n=0;


	int pan_flag=(Vpan_flag_n==1 && Hpan_flag_n==1 && (GMVx1_acc!=0 || GMVy1_acc!=0));

	int reg_h_pan_flag;
	if (pan_flag)
		reg_h_pan_flag=1;
	else
		reg_h_pan_flag=0;


	int mv_v_pan;
	int mv_h_pan;

	mv_h_pan=max_hist_h_MV;//GMVx+reg_vc_nr_HMCNR_search_range_full;
	mv_v_pan=max_hist_v_MV;//GMVy+reg_vc_nr_MCNR_V_search_range_full;



	di_im_new_mcnr_control.n_h_pan_flag=reg_h_pan_flag;
	di_im_new_mcnr_pan_condition.h_pan_mv_value=mv_h_pan;
	di_im_new_mcnr_control4.n_mcnr_v_pan_mv=mv_v_pan;



	scalerVIP_DI_MiddleWare_MCNR_Set_Pan_Flag(di_im_new_mcnr_control.n_h_pan_flag);


	rtd_outl(DI_IM_NEW_MCNR_CONTROL_reg,di_im_new_mcnr_control.regValue);
	rtd_outl(DI_IM_NEW_MCNR_PAN_CONDITION_reg,di_im_new_mcnr_pan_condition.regValue);
	rtd_outl(DI_IM_NEW_MCNR_CONTROL4_reg,di_im_new_mcnr_control4.regValue);


}
#else
// chen 170811
unsigned char pattern_gen_flag=0;
unsigned char tower_flag=0;
unsigned char pattern_gen_pan_flag=0;
// end chen 170811
void scalerVIP_DI_MiddleWare_MCNR_Ctrl2(unsigned char weight)
{
	di_im_new_mcnr_pan_condition_RBUS di_im_new_mcnr_pan_condition;
	di_im_new_mcnr_control4_RBUS di_im_new_mcnr_control4;
	di_im_new_mcnr_control_RBUS di_im_new_mcnr_control;
	di_im_new_mcnr_clamping_value_RBUS di_im_new_mcnr_clamping_value;

	di_im_new_mcnr_pan_condition.regValue = rtd_inl(DI_IM_NEW_MCNR_PAN_CONDITION_reg);
	di_im_new_mcnr_control4.regValue = rtd_inl(DI_IM_NEW_MCNR_CONTROL4_reg);
	di_im_new_mcnr_control.regValue = rtd_inl(DI_IM_NEW_MCNR_CONTROL_reg);

	di_im_new_mcnr_gmv_penalty_ctrl_RBUS	di_im_new_mcnr_gmv_penalty_ctrl;
	di_im_new_mcnr_tmv_penalty_ctrl_RBUS	di_im_new_mcnr_tmv_penalty_ctrl;
	di_im_new_mcnr_tmv_diff_th_RBUS				di_im_new_mcnr_tmv_diff_th;

	di_im_new_mcnr_gmv_penalty_ctrl.regValue = rtd_inl(DI_IM_NEW_MCNR_GMV_Penalty_Ctrl_reg);
	di_im_new_mcnr_tmv_penalty_ctrl.regValue = rtd_inl(DI_IM_NEW_MCNR_TMV_Penalty_Ctrl_reg);
	di_im_new_mcnr_tmv_diff_th.regValue 		 = rtd_inl(DI_IM_NEW_MCNR_TMV_Diff_TH_reg);

	di_im_new_mcnr_gmv_hist_ctrl_RBUS		di_im_new_mcnr_gmv_hist_ctrl;
	di_im_new_mcnr_gmv_hist_ctrl.regValue = rtd_inl(DI_IM_NEW_MCNR_GMV_Hist_Ctrl_reg);


	static bool recog_flag=0;
	bool recong_pan_flag=0;

	static int pan_penalty1_ori,pan_penalty2_ori,pan_penalty3_ori;
	static int pan_penalty4_ori,pan_penalty5_ori,pan_penalty6_ori;
	static int messlevel_ori;
	static bool ori_flag=1;

	di_im_new_mcnr_gmv_penalty_th_RBUS 			di_im_new_mcnr_gmv_penalty_th;
	di_im_new_mcnr_control3_RBUS						di_im_new_mcnr_control3;
	di_im_new_mcnr_gmv_penalty_th.regValue = rtd_inl(DI_IM_NEW_MCNR_GMV_Penalty_TH_reg);
	di_im_new_mcnr_control3.regValue = rtd_inl(DI_IM_NEW_MCNR_CONTROL3_reg);


	int Hpan_flag_n2=0;


// chen 170508
	int vc_nr_MCNR_mvx_hist[21]={10};
	int vc_nr_MCNR_mvy_hist[7]={3};

	int i;




	UINT8 cur_source=0,sd_input=0;
	cur_source=(RPC_system_info_structure_table->VIP_source);

	if((cur_source >= VIP_QUALITY_CVBS_NTSC && cur_source <=VIP_QUALITY_YPbPr_576P)||
		(cur_source >= VIP_QUALITY_HDMI_480I && cur_source <=VIP_QUALITY_HDMI_576P)||
		(cur_source >= VIP_QUALITY_DTV_480I && cur_source <=VIP_QUALITY_DTV_576P)||
		(cur_source >= VIP_QUALITY_PVR_480I && cur_source <=VIP_QUALITY_PVR_576P)||
		(cur_source >= VIP_QUALITY_CVBS_SECAN && cur_source <=VIP_QUALITY_TV_NTSC443))
	{
		sd_input = 1;
	}
	else
	{
		sd_input = 0;
	}



	di_im_di_rtnr_hmcnr_statistic_1_RBUS di_im_di_rtnr_hmcnr_statistic_1;
	di_im_di_rtnr_hmcnr_statistic_2_RBUS di_im_di_rtnr_hmcnr_statistic_2;
	di_im_di_rtnr_hmcnr_statistic_3_RBUS di_im_di_rtnr_hmcnr_statistic_3;
	di_im_di_rtnr_hmcnr_statistic_4_RBUS di_im_di_rtnr_hmcnr_statistic_4;
	di_im_di_rtnr_hmcnr_statistic_5_RBUS di_im_di_rtnr_hmcnr_statistic_5;
	di_im_di_rtnr_hmcnr_statistic_6_RBUS di_im_di_rtnr_hmcnr_statistic_6;

	di_im_di_rtnr_mcnr_statistic_7_RBUS di_im_di_rtnr_mcnr_statistic_7;
	di_im_di_rtnr_mcnr_statistic_8_RBUS di_im_di_rtnr_mcnr_statistic_8;
	di_im_di_rtnr_mcnr_statistic_9_RBUS di_im_di_rtnr_mcnr_statistic_9;
	di_im_di_rtnr_mcnr_statistic_10_RBUS di_im_di_rtnr_mcnr_statistic_10;
	di_im_di_rtnr_mcnr_statistic_11_RBUS di_im_di_rtnr_mcnr_statistic_11;
	di_im_di_rtnr_mcnr_statistic_12_RBUS di_im_di_rtnr_mcnr_statistic_12;
	di_im_di_rtnr_mcnr_statistic_13_RBUS di_im_di_rtnr_mcnr_statistic_13;
	di_im_di_rtnr_mcnr_statistic_14_RBUS di_im_di_rtnr_mcnr_statistic_14;
	di_im_di_rtnr_mcnr_statistic_15_RBUS di_im_di_rtnr_mcnr_statistic_15;
/* chen 170508
	di_im_di_rtnr_mcnr_statistic_16_RBUS di_im_di_rtnr_mcnr_statistic_16;
	di_im_di_rtnr_mcnr_statistic_17_RBUS di_im_di_rtnr_mcnr_statistic_17;
	di_im_di_rtnr_mcnr_statistic_18_RBUS di_im_di_rtnr_mcnr_statistic_18;
	di_im_di_rtnr_mcnr_statistic_19_RBUS di_im_di_rtnr_mcnr_statistic_19;
	di_im_di_rtnr_mcnr_statistic_20_RBUS di_im_di_rtnr_mcnr_statistic_20;
	di_im_di_rtnr_mcnr_statistic_21_RBUS di_im_di_rtnr_mcnr_statistic_21;
	di_im_di_rtnr_mcnr_statistic_22_RBUS di_im_di_rtnr_mcnr_statistic_22;
	di_im_di_rtnr_mcnr_statistic_23_RBUS di_im_di_rtnr_mcnr_statistic_23;
*/
	di_im_di_rtnr_hmcnr_statistic_1.regValue = rtd_inl(DI_IM_DI_RTNR_HMCNR_STATISTIC_1_reg);
	di_im_di_rtnr_hmcnr_statistic_2.regValue = rtd_inl(DI_IM_DI_RTNR_HMCNR_STATISTIC_2_reg);
	di_im_di_rtnr_hmcnr_statistic_3.regValue = rtd_inl(DI_IM_DI_RTNR_HMCNR_STATISTIC_3_reg);
	di_im_di_rtnr_hmcnr_statistic_4.regValue = rtd_inl(DI_IM_DI_RTNR_HMCNR_STATISTIC_4_reg);
	di_im_di_rtnr_hmcnr_statistic_5.regValue = rtd_inl(DI_IM_DI_RTNR_HMCNR_STATISTIC_5_reg);
	di_im_di_rtnr_hmcnr_statistic_6.regValue = rtd_inl(DI_IM_DI_RTNR_HMCNR_STATISTIC_6_reg);

	di_im_di_rtnr_mcnr_statistic_7.regValue  = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_7_reg);
	di_im_di_rtnr_mcnr_statistic_8.regValue  = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_8_reg);
	di_im_di_rtnr_mcnr_statistic_9.regValue  = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_9_reg);
	di_im_di_rtnr_mcnr_statistic_10.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_10_reg);
	di_im_di_rtnr_mcnr_statistic_11.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_11_reg);
	di_im_di_rtnr_mcnr_statistic_12.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_12_reg);
	di_im_di_rtnr_mcnr_statistic_13.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_13_reg);
	di_im_di_rtnr_mcnr_statistic_14.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_14_reg);
	di_im_di_rtnr_mcnr_statistic_15.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_15_reg);
/* chen 170508
	di_im_di_rtnr_mcnr_statistic_16.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_16_reg);
	di_im_di_rtnr_mcnr_statistic_17.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_17_reg);
	di_im_di_rtnr_mcnr_statistic_18.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_18_reg);
	di_im_di_rtnr_mcnr_statistic_19.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_19_reg);
	di_im_di_rtnr_mcnr_statistic_20.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_20_reg);
	di_im_di_rtnr_mcnr_statistic_21.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_21_reg);
	di_im_di_rtnr_mcnr_statistic_22.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_22_reg);
	di_im_di_rtnr_mcnr_statistic_23.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_23_reg);
*/


// chen 170508

	vc_nr_MCNR_mvx_hist[0]=di_im_di_rtnr_mcnr_statistic_11.mcnr_l10_sum;//499c[15:0]
	vc_nr_MCNR_mvx_hist[1]=di_im_di_rtnr_mcnr_statistic_11.mcnr_l9_sum;//499c[31:16]
	vc_nr_MCNR_mvx_hist[2]=di_im_di_rtnr_mcnr_statistic_10.mcnr_l8_sum;//4a98[15:0]
	vc_nr_MCNR_mvx_hist[3]=di_im_di_rtnr_mcnr_statistic_10.mcnr_l7_sum;//4a98[31:16]
	vc_nr_MCNR_mvx_hist[4]=di_im_di_rtnr_mcnr_statistic_9.mcnr_l6_sum;//4a94[15:0]
	vc_nr_MCNR_mvx_hist[5]=di_im_di_rtnr_hmcnr_statistic_6.hmcnr_l5_sum;//4858[31:16]
	vc_nr_MCNR_mvx_hist[6]=di_im_di_rtnr_hmcnr_statistic_5.hmcnr_l4_sum;//4854[15:0]
	vc_nr_MCNR_mvx_hist[7]=di_im_di_rtnr_hmcnr_statistic_5.hmcnr_l3_sum;//4854[31:16]
	vc_nr_MCNR_mvx_hist[8]=di_im_di_rtnr_hmcnr_statistic_4.hmcnr_l2_sum;//4850[15:0]
	vc_nr_MCNR_mvx_hist[9]=di_im_di_rtnr_hmcnr_statistic_4.hmcnr_l1_sum;//4850[31:16]
	vc_nr_MCNR_mvx_hist[10]=di_im_di_rtnr_hmcnr_statistic_3.hmcnr_c0_sum;//484c[15:0]
	vc_nr_MCNR_mvx_hist[11]=di_im_di_rtnr_hmcnr_statistic_3.hmcnr_r1_sum;//484c[31:16]
	vc_nr_MCNR_mvx_hist[12]=di_im_di_rtnr_hmcnr_statistic_2.hmcnr_r2_sum;//4848[15:0]
	vc_nr_MCNR_mvx_hist[13]=di_im_di_rtnr_hmcnr_statistic_2.hmcnr_r3_sum;//4848[31:16]
	vc_nr_MCNR_mvx_hist[14]=di_im_di_rtnr_hmcnr_statistic_1.hmcnr_r4_sum;//4844[15:0]
	vc_nr_MCNR_mvx_hist[15]=di_im_di_rtnr_hmcnr_statistic_1.hmcnr_r5_sum;//4844[31:16]
	vc_nr_MCNR_mvx_hist[16]=di_im_di_rtnr_mcnr_statistic_9.mcnr_r6_sum;//4a94[31:16]
	vc_nr_MCNR_mvx_hist[17]=di_im_di_rtnr_mcnr_statistic_8.mcnr_r7_sum;//4a90[15:0]
	vc_nr_MCNR_mvx_hist[18]=di_im_di_rtnr_mcnr_statistic_8.mcnr_r8_sum;//4a90[31:16]
	vc_nr_MCNR_mvx_hist[19]=di_im_di_rtnr_mcnr_statistic_7.mcnr_r9_sum;//4a8c[15:0]
	vc_nr_MCNR_mvx_hist[20]=di_im_di_rtnr_mcnr_statistic_7.mcnr_r10_sum;//4a8c[31:16]


	vc_nr_MCNR_mvy_hist[0]=di_im_di_rtnr_mcnr_statistic_15.mcnr_d3_sum;//4a0c[31:16]
	vc_nr_MCNR_mvy_hist[1]=di_im_di_rtnr_mcnr_statistic_14.mcnr_d2_sum;//4a08[15:0]
	vc_nr_MCNR_mvy_hist[2]=di_im_di_rtnr_mcnr_statistic_14.mcnr_d1_sum;//4a08[31:16]
	vc_nr_MCNR_mvy_hist[3]=di_im_di_rtnr_mcnr_statistic_13.mcnr_v0_sum;//4a04[15:0]
	vc_nr_MCNR_mvy_hist[4]=di_im_di_rtnr_mcnr_statistic_13.mcnr_u1_sum;//4a04[31:16]
	vc_nr_MCNR_mvy_hist[5]=di_im_di_rtnr_mcnr_statistic_12.mcnr_u2_sum;//4a00[15:0]
	vc_nr_MCNR_mvy_hist[6]=di_im_di_rtnr_mcnr_statistic_12.mcnr_u3_sum;//4a00[31:16]

// end chen 170508



	int mcnr_static_sum=di_im_di_rtnr_mcnr_statistic_15.mcnr_static_sum;//4a0c[15:0]



	int sum_h=0;
	int sum_v=0;
	int h_gmv_ratio=0;
	int v_gmv_ratio=0;
	int g_gmv_ratio=0;

	int mvx_10_ratio=0,mvx_11_ratio=0,mvx_12_ratio=0;
	int mvy_0_ratio=0,mvy_1_ratio=0;

// chen 170508
	for(i=0; i<21; i++)
	{
		vc_nr_MCNR_mvx_hist[i]=(vc_nr_MCNR_mvx_hist[i]>>4);
		sum_h=sum_h+vc_nr_MCNR_mvx_hist[i];

// chen 170508
		if (i==10)
		{
				vc_nr_MCNR_mvx_hist[i]=vc_nr_MCNR_mvx_hist[i]-(mcnr_static_sum>>4);

		}


	}



	int il, ir;
	int mvx_hist_adj ;
	int	max_hist_h=0;
	int max_hist_h_MV=0;
	int	max_hist_v=0;
	int max_hist_v_MV=0;
	int mvx_hist_l, mvx_hist_r;

	int mvx_hist_adj_add;
	int mvy_hist_adj_add;
	int max_hist_h_lr;
	int max_hist_v_lr;

	int max_hist_h_MV_ori;


// chen 170508
	for(i=0; i<21; i++)
	{

		if(vc_nr_MCNR_mvx_hist[i]>max_hist_h)
		{
			max_hist_h=vc_nr_MCNR_mvx_hist[i];
			max_hist_h_MV=i;
		}
		max_hist_h_MV_ori=max_hist_h_MV;


			il=i-1;
	    ir=i+1;
	    if (il<0)		il=1;
	    // chen 170508
	    if (ir>20)	ir=19;

	    // chen 170508
			if (i==11)
				il=12;

			// chen 170508
			if (i==9)
				ir=8;

	    mvx_hist_adj = max(vc_nr_MCNR_mvx_hist[il],vc_nr_MCNR_mvx_hist[ir]);

	    if(mvx_hist_adj > vc_nr_MCNR_mvx_hist[i])
	       mvx_hist_adj = vc_nr_MCNR_mvx_hist[i];

// chen 170508
	    if (i==10)
		    mvx_hist_adj_add = vc_nr_MCNR_mvx_hist[i];
	    else

	    mvx_hist_adj_add = mvx_hist_adj+vc_nr_MCNR_mvx_hist[i];

// chen 170508
	    if((mvx_hist_adj_add>max_hist_h) ||(mvx_hist_adj_add==max_hist_h && abs(i-10)<abs(max_hist_h_MV-10)))
	    {
	       max_hist_h=mvx_hist_adj_add;
	       max_hist_h_MV=i;

	    }
	}


	il=max_hist_h_MV-1;
	ir=max_hist_h_MV+1;

	if (il<0)	    il=1;
// chen 170508
	if (ir>20)	    ir=19;




	mvx_hist_l=vc_nr_MCNR_mvx_hist[il];
	mvx_hist_r=vc_nr_MCNR_mvx_hist[ir];

	if(mvx_hist_l > vc_nr_MCNR_mvx_hist[max_hist_h_MV])
	  mvx_hist_l = vc_nr_MCNR_mvx_hist[max_hist_h_MV];

	if(mvx_hist_r > vc_nr_MCNR_mvx_hist[max_hist_h_MV])
	  mvx_hist_r = vc_nr_MCNR_mvx_hist[max_hist_h_MV];

	max_hist_h_lr = mvx_hist_l+mvx_hist_r+vc_nr_MCNR_mvx_hist[max_hist_h_MV];


// chen 170508
	for(i=0; i<7; i++)
	{
			vc_nr_MCNR_mvy_hist[i]=(vc_nr_MCNR_mvy_hist[i]>>4);
			sum_v=sum_v+vc_nr_MCNR_mvy_hist[i];

// chen 170508
	        if (i==3)
		{

				vc_nr_MCNR_mvy_hist[i]=vc_nr_MCNR_mvy_hist[i]-(mcnr_static_sum>>4);

		}
		}


	if(sum_h != 0)
		h_gmv_ratio = (mcnr_static_sum>>4)*100/sum_h;
	if(sum_v!=0)
		v_gmv_ratio = (mcnr_static_sum>>4)*100/sum_v;


	//ROSPrintf("\n h =%d v=%d \n",h_gmv_ratio,h_gmv_ratio);
	int ratio=0;
	ratio = max(h_gmv_ratio,v_gmv_ratio);
	//if(scalerVIP_DI_MiddleWare_MCNR_Get_Pan_Flag()==1)
	//	ratio=100;


	scalerVIP_DI_MiddleWare_MCNR_Set_GMV_Ratio(ratio);


	int mvy_hist_adj=0;
	int mvy_hist_l=0;
	int mvy_hist_r=0;

// chen 170508
	for(i=0; i<7; i++)
	{
			il=i-1;
	    ir=i+1;
	    if (il<0)		 il=1;
	    if (ir>6)		 ir=5;

	    mvy_hist_adj=max(vc_nr_MCNR_mvy_hist[il],vc_nr_MCNR_mvy_hist[ir]);

	    if(mvy_hist_adj > vc_nr_MCNR_mvy_hist[i])
	       mvy_hist_adj = vc_nr_MCNR_mvy_hist[i];

			mvy_hist_adj_add=mvy_hist_adj+vc_nr_MCNR_mvy_hist[i];

	    if((mvy_hist_adj_add>max_hist_v) ||(mvy_hist_adj_add==max_hist_v && abs(i-3)<abs(max_hist_v_MV-3)))
	    {
		max_hist_v=mvy_hist_adj_add;
		max_hist_v_MV=i;
	    }
	}

	il=max_hist_v_MV-1;
	ir=max_hist_v_MV+1;
	if (il<0)	     il=1;
// chen 170508
	if (ir>6)	     ir=5;

	mvy_hist_l=vc_nr_MCNR_mvy_hist[il];
	mvy_hist_r=vc_nr_MCNR_mvy_hist[ir];

	if(mvy_hist_l > vc_nr_MCNR_mvy_hist[max_hist_v_MV])
	    mvy_hist_l = vc_nr_MCNR_mvy_hist[max_hist_v_MV];

	if(mvy_hist_r > vc_nr_MCNR_mvy_hist[max_hist_v_MV])
	    mvy_hist_r = vc_nr_MCNR_mvy_hist[max_hist_v_MV];

	max_hist_v_lr=vc_nr_MCNR_mvy_hist[max_hist_v_MV]+mvy_hist_l+mvy_hist_r;



	if((mcnr_static_sum>>4)>max_hist_v)
	{
		max_hist_v=mcnr_static_sum>>4;
	    max_hist_v_MV=3;
	}


	if(DynamicOptimizeSystem[177]==1 &&
//		max_hist_h_MV>=16 && max_hist_h_MV<=18 && max_hist_v_MV==6)
	// chen 170508
			max_hist_h_MV>=11 && max_hist_h_MV<=13 && max_hist_v_MV==3)

		recong_pan_flag=1;
	else
		recong_pan_flag=0;

	bool pan_static=0;

	if(recong_pan_flag==1 &&(((mcnr_static_sum>>4)>max_hist_h*4) ||
		(sum_h!=0 && ((mcnr_static_sum>>4)*100/sum_h)>65))
	)
		pan_static=1;
	else
		pan_static=0;


	if(((mcnr_static_sum>>4)>max_hist_h) &&	(pan_static==1 || DynamicOptimizeSystem[177]==0))
	{
		max_hist_h=mcnr_static_sum>>4;
	//	max_hist_h_MV=15;
	// chen 170508
			  max_hist_h_MV=10;
	}

	// end chen 161205

	int g_gmv_ratio_y;
	if(sum_h != 0)
	{
	// chen 170508
	if(max_hist_h_MV==10)
	g_gmv_ratio=vc_nr_MCNR_mvx_hist[9]+vc_nr_MCNR_mvx_hist[10]+vc_nr_MCNR_mvx_hist[11]+(mcnr_static_sum>>4);
	if(max_hist_h_MV==9)
	g_gmv_ratio=vc_nr_MCNR_mvx_hist[8]+vc_nr_MCNR_mvx_hist[9]+vc_nr_MCNR_mvx_hist[10]+(mcnr_static_sum>>4);
	if(max_hist_h_MV==11)
	g_gmv_ratio=vc_nr_MCNR_mvx_hist[10]+vc_nr_MCNR_mvx_hist[11]+vc_nr_MCNR_mvx_hist[12]+(mcnr_static_sum>>4);

	g_gmv_ratio_y=vc_nr_MCNR_mvy_hist[3]+vc_nr_MCNR_mvy_hist[2]+vc_nr_MCNR_mvy_hist[4]+(mcnr_static_sum>>4);

		g_gmv_ratio = (g_gmv_ratio)*100/sum_h;
		g_gmv_ratio_y = (g_gmv_ratio_y)*100/sum_h;
	}

	di_im_new_mcnr_clamping_value.regValue = rtd_inl(DI_IM_NEW_MCNR_CLAMPING_VALUE_reg);
	// chen 170508
	if((g_gmv_ratio>50 && g_gmv_ratio_y>50 && max_hist_v_MV==3 && max_hist_h_MV>=9 && max_hist_h_MV<=11)&&sd_input==0)
	{
		di_im_new_mcnr_clamping_value.n_mcnr_weight_mode=1;
	}
	else
	{
		di_im_new_mcnr_clamping_value.n_mcnr_weight_mode=0;
	}
	rtd_outl(DI_IM_NEW_MCNR_CLAMPING_VALUE_reg,di_im_new_mcnr_clamping_value.regValue);

	if(sum_h==0)
		sum_h=100;

	if(sum_v==0)
		sum_v=100;

// chen 170508
	if(((g_gmv_ratio>50&&g_gmv_ratio<95) && (g_gmv_ratio_y>50&&g_gmv_ratio_y<95) && max_hist_v_MV==3 && max_hist_h_MV>=9 && max_hist_h_MV<=11)&&sd_input==0)
	{
		soft_move =1;
	}
	else
	{
		soft_move=0;
	}

// chen 170508
	if(((g_gmv_ratio>80) && (g_gmv_ratio_y>80) && max_hist_v_MV==3 && max_hist_h_MV==10)
		&&(g_gmv_ratio,SmartPic_clue->HMC_bin_hist_Ratio[16]>900)&&sd_input==0)
	{
		static_move =1;
	}
	else
	{
		static_move=0;

	}

	//int reg_h_pan_mv=max_hist_h_MV;
	//int reg_v_pan_mv=max_hist_v_MV;

// chen 170508
	mvx_10_ratio =vc_nr_MCNR_mvx_hist[10]*100/sum_h;
	mvx_11_ratio =vc_nr_MCNR_mvx_hist[11]*100/sum_h;
	mvx_12_ratio =vc_nr_MCNR_mvx_hist[12]*100/sum_h;
	mvy_0_ratio =vc_nr_MCNR_mvy_hist[0]*100/sum_v;
	mvy_1_ratio =vc_nr_MCNR_mvy_hist[1]*100/sum_v;

	//if(rtd_inl(0xb802e4f4)==7)
	//printk("\n x_1=%d,x_2=%d , y3+y4=%d",mvx_15_ratio,mvx_16_ratio,mvy_3_ratio+mvy_4_ratio);

	/////////////////////////////////////////////
	/////////////////////////////////////////////////////

	static int Vpan_flag_n=0;
	static int Hpan_flag_n=0;
	static int GMVy1_ctr_acc=0;
	static int GMVy2_ctr_acc=0;
	static int GMVx1_ctr_acc=0;
	static int GMVx2_ctr_acc=0;
	static int GMVy1_acc=0;
	static int GMVy2_acc=0;
	static int GMVx1_acc=0;
	static int GMVx2_acc=0;

	// chen 161229
	static int pan_ctr=0;

// chen 170508
	static int gmvx_pre=10;
	static int gmvy_pre=3;

	int diff_th_v=0;
	int diff_th_h=0;
	int GMVy1_acc_old=0;
	int GMVy1_ctr_acc_old=0;
	int GMVx1_acc_old=0;
	int GMVx1_ctr_acc_old=0;




	int ratio_TH0=50;
	int GMV_ctr_th=10;
	int ratio_TH1=25;//35;//20;//35;
	bool ratio0_flag=0;
	bool ratio1_flag=0;
	bool ratio0_flag_v=0;
	bool ratio1_flag_v=0;

// chen 170508
	int reg_vc_nr_HMCNR_search_range_full=10;
	int reg_vc_nr_MCNR_V_search_range_full=3;

	/*
		if(Hpan_flag_n==1 && Vpan_flag_n==1)
				ratio_TH0=25;//35;
		else
				ratio_TH0=50;//50;//40;//50;
	*/
	// chen 161205
	if(recong_pan_flag==1)
	{
		ratio_TH0=10;

		ratio_TH1=10;
	}
	else
	{
		if(Hpan_flag_n==1 && Vpan_flag_n==1)
				ratio_TH0=25;//35;
		else
				ratio_TH0=50;

		ratio_TH1=25;
	}

	// end chen 161205

	// chen 161229
	int ratio_static_TH=20;

	// end chen 161229



	int GMVx=max_hist_h_MV-reg_vc_nr_HMCNR_search_range_full;
	int GMVy=max_hist_v_MV-reg_vc_nr_MCNR_V_search_range_full;

	int GMV_ratio_v=max_hist_v*100/sum_v;
	int GMV_ratio_h=max_hist_h*100/sum_h;

	int GMV_ratio_v_lr=max_hist_v_lr*100/sum_v;
	int GMV_ratio_h_lr=max_hist_h_lr*100/sum_h;

	int ratio_static= 0;
	ratio_static =(mcnr_static_sum>>4)*100/sum_h;



	int diff_range3_h;
	int diff_range3_v;

	if(GMV_ratio_h>=100)	  GMV_ratio_h=100;
	if(GMV_ratio_h<0)	  GMV_ratio_h=0;

	if(GMV_ratio_v>=100)	  GMV_ratio_v=100;
	if(GMV_ratio_v<0)	  GMV_ratio_v=0;

	if(GMV_ratio_h_lr>=100)      GMV_ratio_h_lr=100;
	if(GMV_ratio_h_lr<0)	     GMV_ratio_h_lr=0;

	if(GMV_ratio_v_lr>=100)      GMV_ratio_v_lr=100;
	if(GMV_ratio_v_lr<0)	     GMV_ratio_v_lr=0;



	if(GMV_ratio_v>=ratio_TH1)
	{
		ratio1_flag_v=1;
		diff_range3_v=1;
	}
	else if(GMV_ratio_v_lr>=ratio_TH1 && Vpan_flag_n==1 && Hpan_flag_n==1)
	{
		ratio1_flag_v=1;
		diff_range3_v=2;
	}
	else
	{
		ratio1_flag_v=0;
		diff_range3_v=2;
	}

	if(GMV_ratio_v>=ratio_TH0)
	{
		ratio0_flag_v=1;
		diff_range3_v=1;
	}
	else if(GMV_ratio_v_lr>=ratio_TH0 && Vpan_flag_n==1 && Hpan_flag_n==1)
	{
		ratio0_flag_v=1;
		diff_range3_v=2;
	}
	else
	{
		ratio0_flag_v=0;
		diff_range3_v=2;
	}


	if(GMV_ratio_h>=ratio_TH1)
	{
		ratio1_flag=1;
		diff_range3_h=1;
	}
	else if(GMV_ratio_h_lr>=ratio_TH1 && Vpan_flag_n==1 && Hpan_flag_n==1)
	{
		ratio1_flag=1;
		diff_range3_h=2;
	}
	else
	{
		ratio1_flag=0;
		diff_range3_h=2;
	}

	if(GMV_ratio_h>=ratio_TH0)
	{
		ratio0_flag=1;
		diff_range3_h=1;
	}
	else if(GMV_ratio_h_lr>=ratio_TH0 && Vpan_flag_n==1 && Hpan_flag_n==1)
	{
		ratio0_flag=1;
		diff_range3_h=2;
	}
	else
	{
		ratio0_flag=0;
		diff_range3_h=2;
	}


	/*if((rtd_inl(0xb802e4f4)==8)&&scalerVIP_DI_MiddleWare_MCNR_Get_Pan_Flag()==1)
	{
		ROSPrintf("\n H =%d ,V =%d \n",GMV_ratio_h,GMV_ratio_v);
	}
	else if(rtd_inl(0xb802e4f4)==9&&scalerVIP_DI_MiddleWare_MCNR_Get_Pan_Flag()==1)
	{
		ROSPrintf("\n H_lr =%d  ,V_lr =%d \n",GMV_ratio_h_lr,GMV_ratio_v_lr);
	}
	else if(rtd_inl(0xb802e4f4)==10&&scalerVIP_DI_MiddleWare_MCNR_Get_Pan_Flag()==1)
	{
		ROSPrintf("\n H =%d ,V =%d  ,H_lr =%d	,V_lr =%d \n",GMV_ratio_h,GMV_ratio_v,GMV_ratio_h_lr,GMV_ratio_v_lr);
	}*/

	INT8 snr_diff=0,coring_diff=0;
	INT32 coring_diff_h=0,coring_diff_v=0;
	INT32  snr_weight=0;
	di_rtnr_ma_snr_strength_control_RBUS	di_rtnr_ma_snr_strength_control;
	color_sharp_dm_segpk_vpk2_RBUS color_sharp_dm_segpk_vpk2_reg;
	color_sharp_dm_peaking_bound_1_RBUS color_sharp_dm_peaking_bound_1_reg;

	nr_dch1_cp_ctrl_RBUS dch1_cp_ctrl_reg;

	di_rtnr_ma_snr_strength_control.regValue = rtd_inl(DI_RTNR_MA_SNR_STRENGTH_CONTROL_reg);
	color_sharp_dm_segpk_vpk2_reg.regValue = rtd_inl(COLOR_SHARP_DM_SEGPK_VPK2_reg);
	color_sharp_dm_peaking_bound_1_reg.regValue = rtd_inl(COLOR_SHARP_DM_PEAKING_BOUND_1_reg);
	dch1_cp_ctrl_reg.regValue = rtd_inl(NR_DCH1_CP_Ctrl_reg);


	if(cur_source ==VIP_QUALITY_HDMI_1080I)
	{
		if(scalerVIP_DI_MiddleWare_MCNR_Get_Pan_Flag()==1)
		{
			if((GMVy==0) &&abs(GMVx)>=3)
			{
				snr_diff=min(GMV_ratio_h, GMV_ratio_v)-70;
				if(snr_diff<0) snr_diff=0;
				if(snr_diff>15) snr_diff=15;

				di_rtnr_ma_snr_strength_control.rtnr_ma_snr_output_clamp=20-snr_diff;

				snr_weight = (min(GMV_ratio_h, GMV_ratio_v)-70)/2;
				if(snr_weight<0) snr_weight=0;
				if(snr_weight>6) snr_weight=6;

				dch1_cp_ctrl_reg.cp_sresultweight=12-snr_weight;

			}


			coring_diff=(70-min(GMV_ratio_h, GMV_ratio_v))/5;
			if (coring_diff<0)
				coring_diff=0;


			if (coring_diff>3)
				coring_diff=3;


			if(abs(GMVx)-abs(GMVy)>=4)
			{
				coring_diff_v=coring_diff*4/4;
				coring_diff_h=coring_diff*0/4;
			}
			else if(abs(GMVx)-abs(GMVy)>=2)
			{
			 	coring_diff_v=coring_diff*3/4; coring_diff_h=coring_diff*1/4;
			}else if(abs(GMVx)-abs(GMVy)<=-2)
			{
			 	coring_diff_v=coring_diff*1/4;	coring_diff_h=coring_diff*3/4;
			}
			else if(abs(GMVx)-abs(GMVy)<=-3)
			{
			 	coring_diff_v=coring_diff*0/4;
				coring_diff_h=coring_diff*4/4;
			}
			else																 coring_diff_h=coring_diff*2/4; coring_diff_v=coring_diff*2/4;
			{
			 	color_sharp_dm_peaking_bound_1_reg.lv = 1+coring_diff_h;
			 	color_sharp_dm_segpk_vpk2_reg.vpk_lv = 1+coring_diff_v;
			}


		}
		else
		{
			color_sharp_dm_peaking_bound_1_reg.lv = 1;
			color_sharp_dm_segpk_vpk2_reg.vpk_lv = 1;
			di_rtnr_ma_snr_strength_control.rtnr_ma_snr_output_clamp = 20;
		}
		//rtd_outl(COLOR_SHARP_DM_SEGPK_VPK2_reg, color_sharp_dm_segpk_vpk2_reg.regValue);
		rtd_outl(DI_RTNR_MA_SNR_STRENGTH_CONTROL_reg, di_rtnr_ma_snr_strength_control.regValue);
		//rtd_outl(COLOR_SHARP_DM_PEAKING_BOUND_1_reg,color_sharp_dm_peaking_bound_1_reg.regValue);
		//rtd_outl(NR_DCH1_CP_Ctrl_reg,dch1_cp_ctrl_reg.regValue);

	}


//	if(Vpan_flag_n==1 && abs(GMVy1_acc)>=1)
	  diff_th_v=1;
//	else
//	  diff_th_v=1;


	if(Hpan_flag_n==1 && abs(GMVx1_acc)>=1)
		diff_th_h=3;
	else
		diff_th_h=1;


	int static_flag=1;
//	if(GMVy!=0 || GMVx!=0)
// chen 161229
if((GMVy!=0 || GMVx!=0) && ((ratio_static<=ratio_static_TH) ||(DynamicOptimizeSystem[177]=1)))
// end chen 161229
		static_flag=0;
	else
		static_flag=1;


	/// calculate GMVy //////////////////////////
	if(GMVy1_ctr_acc==0 && ratio1_flag_v && static_flag==0)
	{
	  GMVy1_acc=GMVy;
	  GMVy1_ctr_acc=GMVy1_ctr_acc+1;
	}
	else if(GMVy1_ctr_acc>0)
	{
	  if(abs(GMVy1_acc-GMVy)<=diff_th_v)
	  {
	    GMVy1_acc=GMVy1_acc;

			if(ratio0_flag_v)
	    {
	       if(GMVy1_acc==GMVy && static_flag==0)
					GMVy1_ctr_acc=GMVy1_ctr_acc+1;
	       else
		GMVy1_ctr_acc=GMVy1_ctr_acc;
	    }
			else
					GMVy1_ctr_acc=GMVy1_ctr_acc-1;
	  }
	  else if(abs(GMVy1_acc-GMVy)<=2)
	  {
	    GMVy1_acc=GMVy1_acc;
			GMVy1_ctr_acc=GMVy1_ctr_acc-1;
	  }
	  else
	  {
	    GMVy1_acc=GMVy1_acc;
			GMVy1_ctr_acc=GMVy1_ctr_acc-2;
	  }
	}
	if(GMVy1_ctr_acc<0)
		GMVy1_ctr_acc=0;

	if(GMVy1_ctr_acc>GMV_ctr_th)
	  GMVy1_ctr_acc=GMV_ctr_th;



	////// calculate GMVy2 /////////////
	if((GMVy1_acc!=GMVy))
	{
		if(GMVy2_ctr_acc==0 && ratio1_flag_v  && static_flag==0)
	  {
			GMVy2_acc=GMVy;
	    GMVy2_ctr_acc=GMVy2_ctr_acc+1;
	  }
	  else if(GMVy2_ctr_acc>0 && ratio0_flag_v)
	  {
	    if(abs(GMVy2_acc-GMVy)==0  && static_flag==0)
	    {
				GMVy2_acc=GMVy2_acc;
	      GMVy2_ctr_acc=GMVy2_ctr_acc+1;
	    }
	    else
	    {
	      GMVy2_acc=GMVy;
				GMVy2_ctr_acc=1;
	    }
	  }
		else
		{
			GMVy2_ctr_acc--;
		}
	}
	else
		GMVy2_ctr_acc--;

	if(GMVy2_ctr_acc<0)
		GMVy2_ctr_acc=0;

	if(GMVy2_ctr_acc>GMV_ctr_th)
		GMVy2_ctr_acc=GMV_ctr_th;


	// compare GMVy1 and GMVy2 ////
	GMVy1_acc_old=GMVy1_acc;
	GMVy1_ctr_acc_old=GMVy1_ctr_acc;

	if(GMVy2_ctr_acc>GMVy1_ctr_acc ||(GMVy2_ctr_acc==GMVy1_ctr_acc && GMVy2_ctr_acc==GMV_ctr_th))
	{
		GMVy1_acc=GMVy2_acc;
	  GMVy1_ctr_acc=GMVy2_ctr_acc;
	}

	if(GMVy1_ctr_acc>=5 || (Vpan_flag_n==1 && GMVy1_ctr_acc>=3))
// chen 161229
//	if(GMVy1_ctr_acc>=10 || (Vpan_flag_n==1 && GMVy1_ctr_acc>=8))
	  Vpan_flag_n=1;
	else
	  Vpan_flag_n=0;




	/// calculate GMVx //////////////////////////
	if(GMVx1_ctr_acc==0 && ratio1_flag  && static_flag==0)
	{
	  GMVx1_acc=GMVx;
	  GMVx1_ctr_acc=GMVx1_ctr_acc+1;
	}
	else if(GMVx1_ctr_acc>0)
	{
	  if(abs(GMVx1_acc-GMVx)<=diff_th_h)
	  {
			GMVx1_acc=GMVx1_acc;

			if(ratio0_flag)
	    {
	      if(GMVx1_acc==GMVx  && static_flag==0)
					GMVx1_ctr_acc=GMVx1_ctr_acc+1;
	      else
		GMVx1_ctr_acc=GMVx1_ctr_acc;
	    }
			else
				GMVx1_ctr_acc=GMVx1_ctr_acc-1;
	  }
		else if(abs(GMVx1_acc-GMVx)<=2)
	  {
			GMVx1_acc=GMVx1_acc;
			GMVx1_ctr_acc=GMVx1_ctr_acc-1;
		}
	  else
	  {
	    GMVx1_acc=GMVx1_acc;
			GMVx1_ctr_acc=GMVx1_ctr_acc-2;
	  }
	}
	if(GMVx1_ctr_acc<0)
		GMVx1_ctr_acc=0;

	if(GMVx1_ctr_acc>GMV_ctr_th)
	  GMVx1_ctr_acc=GMV_ctr_th;



	////// calculate GMVx2 /////////////
	if((GMVx1_acc!=GMVx))
	{
		if(GMVx2_ctr_acc==0 && ratio1_flag  && static_flag==0)
	  {
			GMVx2_acc=GMVx;
	    GMVx2_ctr_acc=GMVx2_ctr_acc+1;
	  }
	  else if(GMVx2_ctr_acc>0 && ratio0_flag)
	  {
	    if(abs(GMVx2_acc-GMVx)==0  && static_flag==0)
	    {
				GMVx2_acc=GMVx2_acc;
	      GMVx2_ctr_acc=GMVx2_ctr_acc+1;
	    }
	    else
	    {
	      GMVx2_acc=GMVx;
				GMVx2_ctr_acc=1;
	    }
	  }
		else
		{
			GMVx2_ctr_acc--;
		}
	}
	else
		GMVx2_ctr_acc--;

	if(GMVx2_ctr_acc<0)
		GMVx2_ctr_acc=0;

	if(GMVx2_ctr_acc>GMV_ctr_th)
		GMVx2_ctr_acc=GMV_ctr_th;

	// compare GMVx1 and GMVx2 ////
	GMVx1_acc_old=GMVx1_acc;
	GMVx1_ctr_acc_old=GMVx1_ctr_acc;

	if(GMVx2_ctr_acc>GMVx1_ctr_acc ||(GMVx2_ctr_acc==GMVx1_ctr_acc && GMVx2_ctr_acc==GMV_ctr_th))
	{
		GMVx1_acc=GMVx2_acc;
	  GMVx1_ctr_acc=GMVx2_ctr_acc;
	}



	if(GMVx1_ctr_acc>=5 || (Hpan_flag_n==1 && GMVx1_ctr_acc>=5))
// chen 161229
	//if(GMVx1_ctr_acc>=10 || (Hpan_flag_n==1 && GMVx1_ctr_acc>=8))
		Hpan_flag_n=1;
	else
		Hpan_flag_n=0;


		// chen 0707
		char hpan_pass_total = 0;

		for (i=0; i<120; i++)
		{
			if (Smart_Integration_Status.SCREEN_HPAN_STATUS.Pass_Result_Sequence[i] == 1)
				hpan_pass_total++;
		}

		int pre_mv_avg = 0;

		for (i=0; i<16; i++) // pre 16 frames mv
		{
			pre_mv_avg+=(Smart_Integration_Status.SCREEN_HPAN_STATUS.Mv_Result_Sequence[i]-16);
		}
		pre_mv_avg/=16;



	//	if ((((pre_mv_avg >= -7 && pre_mv_avg <= 7) && hpan_pass_total > pass_total_th))&& Smart_Integration_Status.SCREEN_MOTION_STATUS.MOTION_LEVEL > 10)
		if (((pre_mv_avg >= -7 && pre_mv_avg <= 7 && hpan_pass_total > 20)))
			Hpan_flag_n2=1;
		else
			Hpan_flag_n2=0;

		//Hpan_flag_n=(Hpan_flag_n||Hpan_flag_n2);
// chen 161229
		Hpan_flag_n=(Hpan_flag_n||(Hpan_flag_n2&&Smart_Integration_Status.Mode_Progressive==0));


		// end chen 0707

		// chen 161229
		/*if(rtd_inl(0xb802e4f4)==1)
		{
		if(Hpan_flag_n==1)
		pan_ctr++;
		else
		pan_ctr=pan_ctr-2;

		if(Hpan_flag_n2==1&&Smart_Integration_Status.Mode_Progressive==0)
		pan_ctr=10;



		if(pan_ctr>10)
		pan_ctr=10;
		if(pan_ctr<0)
		pan_ctr=0;

		if(ori_flag==1)
		{
			pan_penalty1_ori=di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty1;
			pan_penalty2_ori=di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty2;
			pan_penalty3_ori=di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty3;
			pan_penalty4_ori=di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty4;
			pan_penalty5_ori=di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty5;
			pan_penalty6_ori=di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty6;
		}

		if(pan_ctr<=2)
		{
				di_im_new_mcnr_gmv_penalty_ctrl.n_mcnr_pan_penalty_select=3;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty1=1;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty2=1;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty3=1;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty4=1;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty5=1;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty6=1;
				ori_flag=0;
		}
		else if(pan_ctr<=4)
		{
				di_im_new_mcnr_gmv_penalty_ctrl.n_mcnr_pan_penalty_select=3;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty1=2;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty2=1;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty3=1;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty4=1;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty5=1;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty6=1;
				ori_flag=0;
		}
		else if(pan_ctr<=6)
		{
				di_im_new_mcnr_gmv_penalty_ctrl.n_mcnr_pan_penalty_select=3;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty1=3;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty2=2;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty3=1;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty4=1;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty5=1;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty6=1;
				ori_flag=0;
		}
		else if(pan_ctr<=8)
		{
				di_im_new_mcnr_gmv_penalty_ctrl.n_mcnr_pan_penalty_select=3;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty1=4;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty2=3;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty3=2;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty4=1;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty5=1;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty6=1;
				ori_flag=0;
		}
		else if(pan_ctr<10)
		{
				di_im_new_mcnr_gmv_penalty_ctrl.n_mcnr_pan_penalty_select=3;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty1=4;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty2=3;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty3=3;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty4=2;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty5=1;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty6=1;
				ori_flag=0;
		}
		else
		{
				di_im_new_mcnr_gmv_penalty_ctrl.n_mcnr_pan_penalty_select=0;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty1=pan_penalty1_ori;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty2=pan_penalty2_ori;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty3=pan_penalty3_ori;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty4=pan_penalty4_ori;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty5=pan_penalty5_ori;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty6=pan_penalty6_ori;
				ori_flag=1;
		}
	}*/
		// end chen 161229









	int pan_flag=(Vpan_flag_n==1 && Hpan_flag_n==1 && (GMVx1_acc!=0 || GMVy1_acc!=0) && (GMVx!=0 || GMVy!=0));

	int reg_h_pan_flag;
	if (pan_flag)
		reg_h_pan_flag=1;
	else
		reg_h_pan_flag=0;


	// chen 160822
#if 1
INT32 hmv_th1=0,hmv_th2=0;
// chen 170508
if(reg_h_pan_flag==1 && abs(max_hist_h_MV-10)>6)
	{
	hmv_th1=max_hist_h_MV-5;//0
	hmv_th2=max_hist_h_MV+5;//30;
	//		di_im_new_mcnr_gmv_hist_ctrl.n_mcnr_vmv_th1=max_hist_v_MV-3;// 0
	//		di_im_new_mcnr_gmv_hist_ctrl.n_mcnr_vmv_th2=max_hist_v_MV+3;//12;

	if(hmv_th1<0) hmv_th1=0;
	// chen 170508
	if(hmv_th1>20) hmv_th1=20;
	if(hmv_th2<0) hmv_th2=0;
	// chen 170508
	if(hmv_th2>20) hmv_th2=20;
	/*
	if(di_im_new_mcnr_gmv_hist_ctrl.n_mcnr_vmv_th1<0) di_im_new_mcnr_gmv_hist_ctrl.n_mcnr_vmv_th1=0;
	if(di_im_new_mcnr_gmv_hist_ctrl.n_mcnr_vmv_th1>12) di_im_new_mcnr_gmv_hist_ctrl.n_mcnr_vmv_th1=12;
	if(di_im_new_mcnr_gmv_hist_ctrl.n_mcnr_vmv_th2<0) di_im_new_mcnr_gmv_hist_ctrl.n_mcnr_vmv_th2=0;
	if(di_im_new_mcnr_gmv_hist_ctrl.n_mcnr_vmv_th2>12) di_im_new_mcnr_gmv_hist_ctrl.n_mcnr_vmv_th2=12;
	*/

	di_im_new_mcnr_gmv_hist_ctrl.n_mcnr_hmv_th1=hmv_th1;
	di_im_new_mcnr_gmv_hist_ctrl.n_mcnr_hmv_th2=hmv_th2;
	}
else
{
	di_im_new_mcnr_gmv_hist_ctrl.n_mcnr_hmv_th1=0;
	// chen 170508
	di_im_new_mcnr_gmv_hist_ctrl.n_mcnr_hmv_th2=20;

}
	// end chen 160822

#endif


	int mv_v_pan;
	int mv_h_pan;

	mv_h_pan=max_hist_h_MV;//GMVx+reg_vc_nr_HMCNR_search_range_full;
	mv_v_pan=max_hist_v_MV;//GMVy+reg_vc_nr_MCNR_V_search_range_full;


	//ROSPrintf("\n h_hist[11]=%d, h_hist[12]=%d, h_hist[13]=%d, h_hist[14]=%d, h_hist[15]=%d\n ",vc_nr_MCNR_mvx_hist[11],vc_nr_MCNR_mvx_hist[12],vc_nr_MCNR_mvx_hist[13],vc_nr_MCNR_mvx_hist[14],vc_nr_MCNR_mvx_hist[15]);

	// chen 160714
	/*if(rtd_inl(0xb802e4f4)==1)
	{
		ROSPrintf("\n h_hist[11]=%d, h_hist[12]=%d, h_hist[13]=%d, h_hist[14]=%d, h_hist[15]=%d\n ",vc_nr_MCNR_mvx_hist[11],vc_nr_MCNR_mvx_hist[12],vc_nr_MCNR_mvx_hist[13],vc_nr_MCNR_mvx_hist[14],vc_nr_MCNR_mvx_hist[15]);
		ROSPrintf("\n h_hist[15]=%d, h_hist[16]=%d, h_hist[17]=%d, h_hist[18]=%d, h_hist[19]=%d\n ",vc_nr_MCNR_mvx_hist[15],vc_nr_MCNR_mvx_hist[16],vc_nr_MCNR_mvx_hist[17],vc_nr_MCNR_mvx_hist[18],vc_nr_MCNR_mvx_hist[19]);
	}
	if(rtd_inl(0xb802e4f4)==2)
	{
		max_hist_h_MV=max_hist_h_MV_ori;
	}

	if(rtd_inl(0xb802e4f4)==3)
	{
		if(abs(max_hist_h_MV-15)<=2)
		{
			di_im_new_mcnr_gmv_penalty_ctrl.n_mcnr_pan_diff_range1=1;
			//di_im_new_mcnr_tmv_penalty_ctrl.n_mcnr_tmv_diff_range2=1;
			//di_im_new_mcnr_tmv_diff_th.n_mcnr_diff_tmv_th2=1;
		}
		else
		{
			di_im_new_mcnr_gmv_penalty_ctrl.n_mcnr_pan_diff_range1=2;
			//di_im_new_mcnr_tmv_penalty_ctrl.n_mcnr_tmv_diff_range2=2;
			//di_im_new_mcnr_tmv_diff_th.n_mcnr_diff_tmv_th2=2;
		}
	}

	if(rtd_inl(0xb802e4f4)==4)
	{
			di_im_new_mcnr_gmv_penalty_ctrl.n_mcnr_pan_diff_range1=2;
			di_im_new_mcnr_tmv_penalty_ctrl.n_mcnr_tmv_diff_range2=2;
			di_im_new_mcnr_tmv_diff_th.n_mcnr_diff_tmv_th2=2;
	}

	if(rtd_inl(0xb802e4f4)==5)
	{
		if(mv_h_pan<14 && mv_h_pan==13)
			mv_h_pan=14;
	}
	// end chen 160714

	*/

	if(sd_input ==0)
	{

// chen 170508
		int di_pan_mvx= -(Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Rank[0]+1-17)+10;



		/*(reg_h_pan_flag==1 && (
			(abs(gmvy_pre-max_hist_v_MV)>=1 && abs(max_hist_h_MV-15)>1)
			)
			)
			di_im_new_mcnr_gmv_penalty_ctrl.n_mcnr_pan_diff_range1_v = 2;
		else
			di_im_new_mcnr_gmv_penalty_ctrl.n_mcnr_pan_diff_range1_v = 1;*/

		// chen 161205
		int mvh_th;
		if(recong_pan_flag==1)
			mvh_th=1;
		else
			mvh_th=2;
		// end chen 161205


		// chen 161212
		if(reg_h_pan_flag==1 &&
		// chen 170508
			abs(max_hist_h_MV-10)<=1 &&
			abs(max_hist_v_MV-3)<=1 && recong_pan_flag==0
		)
		{
			di_im_new_mcnr_gmv_penalty_ctrl.n_mcnr_pan_penalty_select=3;

			if(ori_flag==1)
			{
				pan_penalty1_ori=di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty1;
				pan_penalty2_ori=di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty2;
				pan_penalty3_ori=di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty3;
				pan_penalty4_ori=di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty4;
				pan_penalty5_ori=di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty5;
				pan_penalty6_ori=di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty6;

				ori_flag=0;
			}

			di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty1=1;
			di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty2=1;
			di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty3=1;
			di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty4=1;
			di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty5=1;
			di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty6=1;
		}
		else
		{
			di_im_new_mcnr_gmv_penalty_ctrl.n_mcnr_pan_penalty_select=0;

			if(ori_flag==0)
			{
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty1=pan_penalty1_ori;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty2=pan_penalty2_ori;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty3=pan_penalty3_ori;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty4=pan_penalty4_ori;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty5=pan_penalty5_ori;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty6=pan_penalty6_ori;
			}
			ori_flag=1;
		}
		// end chen 161212


		if(reg_h_pan_flag==1 &&
		//  chen 170508
		abs(max_hist_h_MV-10)<=mvh_th &&

			abs(max_hist_v_MV-3)<=1
			)
			di_im_new_mcnr_gmv_penalty_ctrl.n_mcnr_pan_diff_range1 = 1;
		//else
		//	di_im_new_mcnr_gmv_penalty_ctrl.n_mcnr_pan_diff_range1 = 2;

// chen 170508
		if(Smart_Integration_Status.Mode_Progressive==0&&reg_h_pan_flag==1 && abs(max_hist_v_MV-3)==0 && abs(di_pan_mvx-max_hist_h_MV)>=2 && abs(max_hist_h_MV-10)==1 && abs(di_pan_mvx-10)>1)
			mv_h_pan=di_pan_mvx;

		gmvx_pre=mv_h_pan;//max_hist_h_MV;
		gmvy_pre=mv_v_pan;//max_hist_v_MV;

		rtd_outl(DI_IM_NEW_MCNR_GMV_Penalty_Ctrl_reg,di_im_new_mcnr_gmv_penalty_ctrl.regValue);
	}

	if(RPC_system_info_structure_table->VIP_source==VIP_QUALITY_TV_SECAN)
		reg_h_pan_flag=0;




		/* chen 161205
		if(recong_pan_flag==1)
		{
				if(ori_flag==1)
				{
					pan_penalty1_ori=di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty1;
					pan_penalty2_ori=di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty2;
					pan_penalty3_ori=di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty3;
					pan_penalty4_ori=di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty4;
					pan_penalty5_ori=di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty5;
					pan_penalty6_ori=di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty6;

					messlevel_ori=di_im_new_mcnr_control3.n_mcnr_messlevel_th;

					ori_flag=0;
				}

				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty1=2;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty2=1;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty3=1;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty4=1;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty5=1;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty6=1;

				di_im_new_mcnr_control3.n_mcnr_messlevel_th=150;

		}
		else
		{
			if(ori_flag==0)
			{
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty1=pan_penalty1_ori;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty2=pan_penalty2_ori;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty3=pan_penalty3_ori;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty4=pan_penalty4_ori;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty5=pan_penalty5_ori;
				di_im_new_mcnr_gmv_penalty_th.n_mcnr_pan_penalty6=pan_penalty6_ori;

				di_im_new_mcnr_control3.n_mcnr_messlevel_th=messlevel_ori;
			}
			ori_flag=1;
		}

		rtd_outl(DI_IM_NEW_MCNR_GMV_Penalty_TH_reg,di_im_new_mcnr_gmv_penalty_th.regValue);
		rtd_outl(DI_IM_NEW_MCNR_CONTROL3_reg,di_im_new_mcnr_control3.regValue);
		*/
		// end chen 161205


	di_im_new_mcnr_control.n_h_pan_flag=reg_h_pan_flag;
	di_im_new_mcnr_pan_condition.h_pan_mv_value=mv_h_pan;
	di_im_new_mcnr_control4.n_mcnr_v_pan_mv=mv_v_pan;


	scalerVIP_DI_MiddleWare_MCNR_Set_Pan_Flag(reg_h_pan_flag);

	//printk("\n x_1=%d,x_2=%d , y3=%d,y4=%d",mvx_1_ratio,mvx_2_ratio,mvy_3_ratio,mvy_4_ratio);

	//if(rtd_inl(0xb802e4f4)==22)
	//	printk("\n h=%d ,v= %d ,h_r=%d,V_r=%d",mv_h_pan,mv_v_pan,mvx_15_ratio+mvx_16_ratio,mvy_3_ratio+mvy_4_ratio);
	//if(rtd_inl(0xb802e4f4)==21)
	//	printk("\n 15R=%d ,16R= %d ,17R=%d",mvx_15_ratio,mvx_16_ratio,mvx_17_ratio);

// chen 170508
	if(( (mv_h_pan==10 || mv_h_pan==11|| mv_h_pan==12) &&	mv_v_pan==1 ||
		(mv_v_pan==0 && vc_nr_MCNR_mvy_hist[0]<=vc_nr_MCNR_mvy_hist[1]*4)) && reg_h_pan_flag==1)//&&
		//((mvy_3_ratio+mvy_4_ratio>60)&&((mvx_15_ratio+mvx_16_ratio>55)||(mvx_16_ratio+mvx_17_ratio>55))))

	{
		scalerVIP_DI_MiddleWare_MCNR_Set_V_Pan_Flag(1);
	}
	else
	{
		scalerVIP_DI_MiddleWare_MCNR_Set_V_Pan_Flag(0);
	}
	/*if(rtd_inl(0xb802e4f0)==4)
	{
		printk("\n g_gmv_ratio_y=%d ,g_gmv_ratio=%d ,HMC[16]=%d",g_gmv_ratio_y,g_gmv_ratio,SmartPic_clue->HMC_bin_hist_Ratio[16]);

	}*/


	rtd_outl(DI_IM_NEW_MCNR_CONTROL_reg,di_im_new_mcnr_control.regValue);
	rtd_outl(DI_IM_NEW_MCNR_PAN_CONDITION_reg,di_im_new_mcnr_pan_condition.regValue);
	rtd_outl(DI_IM_NEW_MCNR_CONTROL4_reg,di_im_new_mcnr_control4.regValue);

	// chen 160822
	rtd_outl(DI_IM_NEW_MCNR_GMV_Hist_Ctrl_reg,di_im_new_mcnr_gmv_hist_ctrl.regValue);
	// end chen 160822

	// chen 170811
#if 1
	int rt_max=vc_nr_MCNR_mvx_hist[max_hist_h_MV]*100/sum_h;
	int hist_l=max_hist_h_MV-1;
	if (hist_l<0) hist_l=0;
	int hist_r=max_hist_h_MV+1;
	if (hist_r>20) hist_r=20;

	int rt_max_v=vc_nr_MCNR_mvy_hist[max_hist_v_MV]*100/sum_v;
	int hist_d=max_hist_v_MV-1;
	if (hist_d<0) hist_d=0;
	int hist_u=max_hist_v_MV+1;
	if (hist_u>6) hist_u=6;

	int rt_D=vc_nr_MCNR_mvy_hist[hist_d]*100/sum_v;
	int rt_U=vc_nr_MCNR_mvy_hist[hist_u]*100/sum_v;


	int rt_L=vc_nr_MCNR_mvx_hist[hist_l]*100/sum_h;
	int rt_R=vc_nr_MCNR_mvx_hist[hist_r]*100/sum_h;


	if(reg_h_pan_flag==1 &&
 	rt_max>70 && (rt_max+max(rt_L,rt_R)>85) &&
    rt_max_v>80 && (rt_max_v+max(rt_D,rt_U)>85) &&
    ((mv_v_pan)==5 || (mv_v_pan)==1)
    )
 		pattern_gen_flag=1;
	else
		pattern_gen_flag=0;
#endif

	 if(
	   (mv_v_pan==4 ||mv_v_pan==5||mv_v_pan==6) &&
	   (mv_h_pan==10) &&
	   ((vc_nr_MCNR_mvy_hist[5]*2)>vc_nr_MCNR_mvy_hist[4]) &&
	   ((vc_nr_MCNR_mvy_hist[5]*2)>vc_nr_MCNR_mvy_hist[6])
	  )
	  tower_flag=1;
	 else
	  tower_flag=0;

	// end chen 170811

	/* for dynamic De-xc on/off*/
	if(reg_h_pan_flag==1 &&
	 rt_max>85 && (rt_max+max(rt_L,rt_R)>90) &&
	    rt_max_v>85 && (rt_max_v+max(rt_D,rt_U)>90) )
	 pattern_gen_pan_flag=1;
	else
	pattern_gen_pan_flag =0;

	pattern_gen_pan_flag = pattern_gen_pan_flag || pattern_gen_flag;

}
void scalerVIP_DI_MiddleWare_MCNR_Ctrl(unsigned char weight)
{

	int Hpan_value=10;
	int Vpan_value=3;
	unsigned long GMVx=0;
	unsigned long GMVy;// = (rtd_inl(0xb802456c) & 0x00700000)>>20;
	int maxGMV1_ctr=0;
	int maxGMV2_ctr=0;
	int maxGMV3_ctr=0;
	int GMV_ctr=0;
	//int pan_penalty=0;

	char hpan_pass_total = 0;
	unsigned char i = 0;
	int vc_nr_MCNR_mvx_hist[21]={0};
	int vc_nr_MCNR_mvy_hist[7]={0};
	int vc_nr_MCNR_static_hist=0;
	int max_hist_v=0;
	int max_hist_h=0;
	int max_hist_h_MV=10;
	int max_hist_v_MV=3;
	int sum_hist_h=0;
	int sum_hist_v=0;

	int il=0;
	int ir=0;
	int mvx_hist_adj=0;
	int mvx_hist_adj_add=0;
	int mvy_hist_adj=0;
	int mvy_hist_adj_add=0;
	int ration_TH_H=50;
	int ration_TH_V=80;
	static int Vpan_flag_n=0;
	static int Hpan_flag_n=0;
	int mcnr_mode=0;

	unsigned char GMV_ratio_h = 0;
	unsigned char GMV_ratio_v = 0;
	static int GMVx1_acc =0;
	static int GMVx1_ctr_acc =0;

	static int GMVx2_acc = 0;
	static int GMVx2_ctr_acc = 0;

	static int GMVy1_acc =0;
	static int GMVy1_ctr_acc =0;

	static int GMVy2_acc = 0;
	static int GMVy2_ctr_acc = 0;
	int diff_th_h=0;
	int diff_th_v=0;
	int GMV_ctr_th=10;
	unsigned char temp_x=0,temp_y=0,temp_xy;

    	unsigned char Pan_flag=0;
    	unsigned int  mv_value=0,mv_index=0;

	di_im_di_rtnr_hmcnr_RBUS di_rtnr_hmcnr_reg;
	di_rtnr_output_clamp_RBUS di_rtnr_output_clamp_reg;
	di_im_new_mcnr_weighting_condition_RBUS di_im_new_mcnr_weighting_condition;
	di_im_new_mcnr_control3_RBUS di_im_new_mcnr_control3;
	di_im_new_mcnr_control4_RBUS di_im_new_mcnr_control4;
	di_im_new_mcnr_control_RBUS di_im_new_mcnr_control;
	di_im_new_mcnr_pan_condition_RBUS di_im_new_mcnr_pan_condition;
	di_im_new_mcnr_clamping_value_RBUS di_im_new_mcnr_clamping_value;

	di_rtnr_hmcnr_reg.regValue = rtd_inl(DI_IM_DI_RTNR_HMCNR_reg);
	di_rtnr_output_clamp_reg.regValue = rtd_inl(DI_RTNR_OUTPUT_CLAMP_reg);
	di_im_new_mcnr_weighting_condition.regValue = rtd_inl(DI_IM_NEW_MCNR_WEIGHTING_CONDITION_reg);
	di_im_new_mcnr_control3.regValue = rtd_inl(DI_IM_NEW_MCNR_CONTROL3_reg);
	di_im_new_mcnr_control.regValue = rtd_inl(DI_IM_NEW_MCNR_CONTROL_reg);
	di_im_new_mcnr_pan_condition.regValue = rtd_inl(DI_IM_NEW_MCNR_PAN_CONDITION_reg);
	di_im_new_mcnr_clamping_value.regValue	= rtd_inl(DI_IM_NEW_MCNR_CLAMPING_VALUE_reg);
	di_im_new_mcnr_control4.regValue = rtd_inl(DI_IM_NEW_MCNR_CONTROL4_reg);

	mcnr_mode =Smart_Integration_Status.Mode_Progressive;
	unsigned char cur_source=0,sd_input=0;
	cur_source=(RPC_system_info_structure_table->VIP_source);

	if((cur_source >= VIP_QUALITY_CVBS_NTSC && cur_source <=VIP_QUALITY_YPbPr_576P)||
		(cur_source >= VIP_QUALITY_HDMI_480I && cur_source <=VIP_QUALITY_HDMI_576P)||
		(cur_source >= VIP_QUALITY_DTV_480I && cur_source <=VIP_QUALITY_DTV_576P)||
		(cur_source >= VIP_QUALITY_PVR_480I && cur_source <=VIP_QUALITY_PVR_576P)||
		(cur_source >= VIP_QUALITY_CVBS_SECAN && cur_source <=VIP_QUALITY_TV_NTSC443))
	{
		sd_input = 1;
	}
	else
	{
		sd_input = 0;
	}



		di_di_smd_gmvcoeff3_RBUS init_di_smd_gmvcoeff3_reg;
		di_di_smd_sampling_gmvc_RBUS di_di_smd_sampling_gmvc;
		di_di_smd_gmvcoeff1_RBUS smd_gmvcoeff1_reg;
		di_di_smd_gmvcoeff2_RBUS smd_gmvcoeff2_reg;
		di_di_smd_sampling_gmvb_RBUS di_di_smd_sampling_gmvb_reg;


		di_di_smd_sampling_gmvb_reg.regValue = rtd_inl(DI_DI_SMD_Sampling_GMVb_reg);

		init_di_smd_gmvcoeff3_reg.regValue = rtd_inl(DI_DI_SMD_GMVCoeff3_reg);
		di_di_smd_sampling_gmvc.regValue = rtd_inl(DI_DI_SMD_Sampling_GMVc_reg);
		smd_gmvcoeff1_reg.regValue= rtd_inl(DI_DI_SMD_GMVCoeff1_reg);


		GMVx = init_di_smd_gmvcoeff3_reg.smd_gmv1_x;
		GMVy = di_di_smd_sampling_gmvc.smd_gmvc_y;
		GMV_ctr = smd_gmvcoeff1_reg.smd_gmv_ctr;
		maxGMV1_ctr = smd_gmvcoeff1_reg.smd_gmv1_max_ctr;
		maxGMV2_ctr = smd_gmvcoeff2_reg.smd_gmv2_max_ctr;
		maxGMV3_ctr = smd_gmvcoeff2_reg.smd_gmv3_max_ctr;

		// histograms information /////////////
		di_im_di_rtnr_hmcnr_statistic_1_RBUS	di_im_di_rtnr_hmcnr_statistic_1;
		di_im_di_rtnr_hmcnr_statistic_2_RBUS	di_im_di_rtnr_hmcnr_statistic_2;
		di_im_di_rtnr_hmcnr_statistic_3_RBUS	di_im_di_rtnr_hmcnr_statistic_3;
		di_im_di_rtnr_hmcnr_statistic_4_RBUS	di_im_di_rtnr_hmcnr_statistic_4;
		di_im_di_rtnr_hmcnr_statistic_5_RBUS	di_im_di_rtnr_hmcnr_statistic_5;
		di_im_di_rtnr_hmcnr_statistic_6_RBUS	di_im_di_rtnr_hmcnr_statistic_6;
		di_im_di_rtnr_mcnr_statistic_7_RBUS	di_im_di_rtnr_mcnr_statistic_7;
		di_im_di_rtnr_mcnr_statistic_8_RBUS	di_im_di_rtnr_mcnr_statistic_8;
		di_im_di_rtnr_mcnr_statistic_9_RBUS	di_im_di_rtnr_mcnr_statistic_9;
		di_im_di_rtnr_mcnr_statistic_10_RBUS	di_im_di_rtnr_mcnr_statistic_10;
		di_im_di_rtnr_mcnr_statistic_11_RBUS	di_im_di_rtnr_mcnr_statistic_11;
		di_im_di_rtnr_mcnr_statistic_12_RBUS	di_im_di_rtnr_mcnr_statistic_12;
		di_im_di_rtnr_mcnr_statistic_13_RBUS	di_im_di_rtnr_mcnr_statistic_13;
		di_im_di_rtnr_mcnr_statistic_14_RBUS	di_im_di_rtnr_mcnr_statistic_14;
		di_im_di_rtnr_mcnr_statistic_15_RBUS	di_im_di_rtnr_mcnr_statistic_15;


		di_im_di_rtnr_hmcnr_statistic_1.regValue = rtd_inl(DI_IM_DI_RTNR_HMCNR_STATISTIC_1_reg);
		di_im_di_rtnr_hmcnr_statistic_2.regValue = rtd_inl(DI_IM_DI_RTNR_HMCNR_STATISTIC_2_reg);
		di_im_di_rtnr_hmcnr_statistic_3.regValue = rtd_inl(DI_IM_DI_RTNR_HMCNR_STATISTIC_3_reg);
		di_im_di_rtnr_hmcnr_statistic_4.regValue = rtd_inl(DI_IM_DI_RTNR_HMCNR_STATISTIC_4_reg);
		di_im_di_rtnr_hmcnr_statistic_5.regValue = rtd_inl(DI_IM_DI_RTNR_HMCNR_STATISTIC_5_reg);
		di_im_di_rtnr_hmcnr_statistic_6.regValue = rtd_inl(DI_IM_DI_RTNR_HMCNR_STATISTIC_6_reg);

		di_im_di_rtnr_mcnr_statistic_7.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_7_reg);
		di_im_di_rtnr_mcnr_statistic_8.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_8_reg);
		di_im_di_rtnr_mcnr_statistic_9.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_9_reg);
		di_im_di_rtnr_mcnr_statistic_10.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_10_reg);
		di_im_di_rtnr_mcnr_statistic_11.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_11_reg);
		di_im_di_rtnr_mcnr_statistic_12.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_12_reg);
		di_im_di_rtnr_mcnr_statistic_13.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_13_reg);
		di_im_di_rtnr_mcnr_statistic_14.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_14_reg);
		di_im_di_rtnr_mcnr_statistic_15.regValue = rtd_inl(DI_IM_DI_RTNR_MCNR_STATISTIC_15_reg);


		vc_nr_MCNR_static_hist=di_im_di_rtnr_mcnr_statistic_15.mcnr_static_sum;

		vc_nr_MCNR_mvy_hist[0]=di_im_di_rtnr_mcnr_statistic_15.mcnr_d3_sum;
		vc_nr_MCNR_mvy_hist[1]=di_im_di_rtnr_mcnr_statistic_14.mcnr_d2_sum;
		vc_nr_MCNR_mvy_hist[2]=di_im_di_rtnr_mcnr_statistic_14.mcnr_d1_sum;
		vc_nr_MCNR_mvy_hist[3]=di_im_di_rtnr_mcnr_statistic_13.mcnr_v0_sum;//-vc_nr_MCNR_static_hist;
		vc_nr_MCNR_mvy_hist[4]=di_im_di_rtnr_mcnr_statistic_13.mcnr_u1_sum;
		vc_nr_MCNR_mvy_hist[5]=di_im_di_rtnr_mcnr_statistic_12.mcnr_u2_sum;
		vc_nr_MCNR_mvy_hist[6]=di_im_di_rtnr_mcnr_statistic_12.mcnr_u3_sum;

		vc_nr_MCNR_mvx_hist[0]=di_im_di_rtnr_mcnr_statistic_11.mcnr_l10_sum;
		vc_nr_MCNR_mvx_hist[1]=di_im_di_rtnr_mcnr_statistic_11.mcnr_l9_sum;
		vc_nr_MCNR_mvx_hist[2]=di_im_di_rtnr_mcnr_statistic_10.mcnr_l8_sum;
		vc_nr_MCNR_mvx_hist[3]=di_im_di_rtnr_mcnr_statistic_10.mcnr_l7_sum;
		vc_nr_MCNR_mvx_hist[4]=di_im_di_rtnr_mcnr_statistic_9.mcnr_l6_sum;
		vc_nr_MCNR_mvx_hist[5]=di_im_di_rtnr_hmcnr_statistic_6.hmcnr_l5_sum;
		vc_nr_MCNR_mvx_hist[6]=di_im_di_rtnr_hmcnr_statistic_5.hmcnr_l4_sum;
		vc_nr_MCNR_mvx_hist[7]=di_im_di_rtnr_hmcnr_statistic_5.hmcnr_l3_sum;
		vc_nr_MCNR_mvx_hist[8]=di_im_di_rtnr_hmcnr_statistic_4.hmcnr_l2_sum;
		vc_nr_MCNR_mvx_hist[9]=di_im_di_rtnr_hmcnr_statistic_4.hmcnr_l1_sum;
		vc_nr_MCNR_mvx_hist[10]=di_im_di_rtnr_hmcnr_statistic_3.hmcnr_c0_sum;//-vc_nr_MCNR_static_hist;
		vc_nr_MCNR_mvx_hist[11]=di_im_di_rtnr_hmcnr_statistic_3.hmcnr_r1_sum;
		vc_nr_MCNR_mvx_hist[12]=di_im_di_rtnr_hmcnr_statistic_2.hmcnr_r2_sum;
		vc_nr_MCNR_mvx_hist[13]=di_im_di_rtnr_hmcnr_statistic_2.hmcnr_r3_sum;
		vc_nr_MCNR_mvx_hist[14]=di_im_di_rtnr_hmcnr_statistic_1.hmcnr_r4_sum;
		vc_nr_MCNR_mvx_hist[15]=di_im_di_rtnr_hmcnr_statistic_1.hmcnr_r5_sum;
		vc_nr_MCNR_mvx_hist[16]=di_im_di_rtnr_mcnr_statistic_9.mcnr_r6_sum;
		vc_nr_MCNR_mvx_hist[17]=di_im_di_rtnr_mcnr_statistic_8.mcnr_r7_sum;
		vc_nr_MCNR_mvx_hist[18]=di_im_di_rtnr_mcnr_statistic_8.mcnr_r8_sum;
		vc_nr_MCNR_mvx_hist[19]=di_im_di_rtnr_mcnr_statistic_7.mcnr_r9_sum;
		vc_nr_MCNR_mvx_hist[20]=di_im_di_rtnr_mcnr_statistic_7.mcnr_r10_sum;


		// find GMVx, GMVy  //////////////////////////
		for(i=0; i<7; i++)
		{
			il=i-1;
			ir=i+1;
		if (il<0)
			il=1;
		if (ir>6)
			{il=5; ir=6;}
			mvy_hist_adj=max(vc_nr_MCNR_mvy_hist[il],vc_nr_MCNR_mvy_hist[ir]);
			if(mvy_hist_adj>vc_nr_MCNR_mvy_hist[i])
				mvy_hist_adj=vc_nr_MCNR_mvy_hist[i];

			mvy_hist_adj_add=mvy_hist_adj+vc_nr_MCNR_mvy_hist[i];

			if((mvy_hist_adj_add>max_hist_v) ||(mvy_hist_adj_add==max_hist_v && abs(i-3)<abs(max_hist_v_MV-3)))
			{
				max_hist_v=mvy_hist_adj_add;
				max_hist_v_MV=i;
			}

			sum_hist_v=sum_hist_v+vc_nr_MCNR_mvy_hist[i];
		}

		for(i=0; i<21; i++)
		{
			il=i-1;
			ir=i+1;
			if (il<0)		il=1;
			if (ir>20)		{il=19;ir=20;}

if(i==9)	ir=8;
if(i==11)	il=12;

			mvx_hist_adj = max(vc_nr_MCNR_mvx_hist[il],vc_nr_MCNR_mvx_hist[ir]);
			if(mvx_hist_adj > vc_nr_MCNR_mvx_hist[i])
				mvx_hist_adj = vc_nr_MCNR_mvx_hist[i];

if(i==10)
	mvx_hist_adj=0;

			mvx_hist_adj_add = mvx_hist_adj+vc_nr_MCNR_mvx_hist[i];

			if((mvx_hist_adj_add>max_hist_h) ||(mvx_hist_adj_add==max_hist_h && abs(i-10)<abs(max_hist_h_MV-10)))
			{
				max_hist_h=mvx_hist_adj_add;
				max_hist_h_MV=i;
			}

			sum_hist_h=sum_hist_h+vc_nr_MCNR_mvx_hist[i];
		}


		if(sum_hist_h<=0)
			sum_hist_h=1;
		if(sum_hist_v<=0)
			sum_hist_v=1;


		Hpan_value=max_hist_h_MV;
		Vpan_value=max_hist_v_MV;

		GMVx = max_hist_h_MV;
		GMVy = max_hist_v_MV;
	//}

	if(mcnr_mode==0)
	{
		GMVy = max_hist_v_MV;

		GMVx = init_di_smd_gmvcoeff3_reg.smd_gmv1_x;

		GMV_ctr = smd_gmvcoeff1_reg.smd_gmv_ctr;
		maxGMV1_ctr = smd_gmvcoeff1_reg.smd_gmv1_max_ctr;
		maxGMV2_ctr = smd_gmvcoeff2_reg.smd_gmv2_max_ctr;
		maxGMV3_ctr = smd_gmvcoeff2_reg.smd_gmv3_max_ctr;

		if(sd_input==1)
		{
		Vpan_value=GMVy;//-(GMVy-3)+3;

			Hpan_value = New_Mcnr_Mv -7;

			if(((Hpan_value<=11 && Hpan_value>=9) && GMVx==3)&& (RTNR_MAD_count_Y_avg>980))//for interlace
			Hpan_value=10;

		// chen 160714
				Hpan_value = Hpan_value+5;
				Vpan_value = Hpan_value+3;
		// end chen 160714

		}
		else
		{

			Vpan_value=GMVy;//-(GMVy-3)+3;
			Hpan_value= -(Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Rank[0]+1-17)+10;

			if(((Hpan_value<=11 && Hpan_value>=9) && GMVx==3))//for interlace
				Hpan_value=10;
		}
	}

//==================================Register change===============================================================

	//ration_TH0 = rtd_inl(0xb8022674); for debug
	//ration_TH = rtd_inl(0xb8022678);

//==============================================================================================================

	if(GMV_ctr==0)
		GMV_ctr=1;

	if(mcnr_mode==0)
	{
		GMV_ratio = maxGMV1_ctr*100/GMV_ctr;
		GMV_ratio_h = GMV_ratio;
		GMV_ratio_v = GMV_ratio;
	}
	else
	{
		GMV_ratio_v=max_hist_v*100/sum_hist_v;
		GMV_ratio_h=max_hist_h*100/sum_hist_h;
		GMV_ratio = min(GMV_ratio_h,GMV_ratio_v);
	}


	if(GMV_ratio>=100)
		GMV_ratio=100;

	if(GMV_ratio<0)
		GMV_ratio=0;

	if(Vpan_flag_n==1 && abs(GMVy1_acc-3)>=1)
		diff_th_v=1;
	else
		diff_th_v=0;

	if(Hpan_flag_n==1 && abs(GMVx1_acc-10)>=2)
		 diff_th_h=1;
	else
		 diff_th_h=0;

	 /// calculate GMVy //////////////////////////
	 ////////// calculate GMVy1 ////////////


	if(GMVy1_ctr_acc==0 && Vpan_value!=3  && GMV_ratio_v>=ration_TH_V  && Hpan_value==10&&vc_nr_MCNR_mvy_hist[Vpan_value]>0x1ff)
	{
		GMVy1_acc=Vpan_value;
		GMVy1_ctr_acc=GMVy1_ctr_acc+1;
	}
	else if((GMVy1_ctr_acc>0)&&Vpan_value!=3&&vc_nr_MCNR_mvy_hist[Vpan_value]>0x1ff)
	{
		if(abs(GMVy1_acc-Vpan_value)<=diff_th_v && Hpan_value==10)
		{
			GMVy1_acc=GMVy1_acc;
			if(GMV_ratio_v>=ration_TH_V)
			{
				if(GMVy1_acc==Vpan_value)
					GMVy1_ctr_acc=GMVy1_ctr_acc+1;
				else
					GMVy1_ctr_acc=GMVy1_ctr_acc;
			}
			else
				GMVy1_ctr_acc=GMVy1_ctr_acc-1;
		}
		else
		{
			GMVy1_acc=GMVy1_acc;
			GMVy1_ctr_acc=GMVy1_ctr_acc-2;

			if(GMVy1_ctr_acc<0)
				GMVy1_ctr_acc=0;
		}
	}

	  ////// calculate GMVy2 /////////////
	if(GMVy1_ctr_acc>=0 && (GMVy1_acc!=Vpan_value))
	{
		if(GMVy2_ctr_acc==0 && Vpan_value!=3 && GMV_ratio_v>=ration_TH_V&&vc_nr_MCNR_mvy_hist[Vpan_value]>0x1ff)
		{
			GMVy2_acc=Vpan_value;
		//	if(GMV_ratio>=ration_TH)
				GMVy2_ctr_acc=GMVy2_ctr_acc+1;
		}
		else if(GMVy2_ctr_acc>0)
		{
		//	if(abs(GMVy2_acc-Vpan_value)==0)
			if(abs(GMVy2_acc-Vpan_value)==0 && GMV_ratio_v>=ration_TH_V&&vc_nr_MCNR_mvy_hist[Vpan_value]>0x1ff)
			{
				GMVy2_acc=GMVy2_acc;
				GMVy2_ctr_acc=GMVy2_ctr_acc+1;
			}
			else
			{
				GMVy2_acc=Vpan_value;
				GMVy2_ctr_acc=0;
			}
		}
	}
	else if(GMVy2_ctr_acc>0)
		GMVy2_ctr_acc--;


	  // compare GMVy1 and GMVy2 ////
	if(GMVy2_ctr_acc>GMVy1_ctr_acc)
	{
		GMVy1_acc=GMVy2_acc;
		GMVy1_ctr_acc=GMVy2_ctr_acc-1;
	}
	if(GMVy2_ctr_acc<0)
		GMVy2_ctr_acc=0;

	if(GMVy1_ctr_acc<0)
		GMVy1_ctr_acc=0;


	if(GMVy2_ctr_acc>GMV_ctr_th)
		GMVy2_ctr_acc=GMV_ctr_th;
	if(GMVy1_ctr_acc>GMV_ctr_th)
		GMVy1_ctr_acc=GMV_ctr_th;

	if(GMVy1_ctr_acc>=7 || (Vpan_flag_n==1 && GMVy1_ctr_acc>=5))
        {
		Vpan_flag_n=1;
		//ROSPrintf("\n Vpan =%d \n ",Vpan_value);
		//ROSPrintf("\n hist[0] =%d ,hist[1] =%d hist[2] =%d \n ",vc_nr_MCNR_mvy_hist[0],vc_nr_MCNR_mvy_hist[1],vc_nr_MCNR_mvy_hist[2]);
		//ROSPrintf("\n hist[4] =%d ,hist[5] =%d hist[6] =%d \n ",vc_nr_MCNR_mvy_hist[4],vc_nr_MCNR_mvy_hist[5],vc_nr_MCNR_mvy_hist[6]);

	}
	else
		Vpan_flag_n=0;


	////////// calculate GMVx ////////////
	////////// calculate GMVx1 ////////////
	if(GMVx1_ctr_acc==0 && Hpan_value!=10  && GMV_ratio_h>=ration_TH_H && Vpan_value==3)
	{
		GMVx1_acc=Hpan_value;
		GMVx1_ctr_acc=GMVx1_ctr_acc+1;
	}
	else if(GMVx1_ctr_acc>0)
	{
		if(abs(GMVx1_acc-Hpan_value)<=diff_th_h && Vpan_value==3)
		{
			GMVx1_acc=GMVx1_acc;
			if(GMV_ratio_h>=ration_TH_H)
			{
				if(GMVx1_acc==Hpan_value)
					GMVx1_ctr_acc=GMVx1_ctr_acc+1;
				else
					GMVx1_ctr_acc=GMVx1_ctr_acc;
			}
			else
				GMVx1_ctr_acc=GMVx1_ctr_acc-1;
		}
		else
		{
			GMVx1_acc=GMVx1_acc;
			GMVx1_ctr_acc=GMVx1_ctr_acc-2;
			if(GMVx1_ctr_acc<0)
				GMVx1_ctr_acc=0;
		}
	}

	  ////// calculate GMVx2 /////////////
	if(GMVx1_ctr_acc>=0 && (GMVx1_acc!=Hpan_value))
	{
		if(GMVx2_ctr_acc==0 && Hpan_value!=10 && GMV_ratio_h>=ration_TH_H)
		{
			GMVx2_acc=Hpan_value;
			GMVx2_ctr_acc=GMVx2_ctr_acc+1;
		}
		else if(GMVx2_ctr_acc>0)
		{
		//	if(abs(GMVx2_acc-Hpan_value)==0)
			if(abs(GMVx2_acc-Hpan_value)==0 && GMV_ratio_h>=ration_TH_H)
			{
				GMVx2_acc=GMVx2_acc;
				GMVx2_ctr_acc=GMVx2_ctr_acc+1;
			}
			else
			{
				GMVx2_acc=Hpan_value;
				GMVx2_ctr_acc=0;
			}
		}
	}
	else if(GMVx2_ctr_acc>0)
		GMVx2_ctr_acc--;


	// compare GMVx1 and GMVx2 ////
	if(GMVx2_ctr_acc>GMVx1_ctr_acc)
	{
		GMVx1_acc=GMVx2_acc;
		GMVx1_ctr_acc=GMVx2_ctr_acc-1;
	}
	if(GMVx2_ctr_acc<0)
		GMVx2_ctr_acc=0;

	if(GMVx1_ctr_acc<0)
		GMVx1_ctr_acc=0;

	//int GMV_ctr_th=10;

	if(GMVx2_ctr_acc>GMV_ctr_th)
		GMVx2_ctr_acc=GMV_ctr_th;
	if(GMVx1_ctr_acc>GMV_ctr_th)
		GMVx1_ctr_acc=GMV_ctr_th;

	if(GMVx1_ctr_acc>=7 || (Hpan_flag_n==1 && GMVx1_ctr_acc>=5))
		Hpan_flag_n=1;
	else
		Hpan_flag_n=0;


	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.ID_Pattern_47==TRUE))
	{
		if(rtd_inl(0xb802267c)==0)
		{
			VIP_DEBUG_PRINTF("MC Hpan =%d ,Vpan=%d ,diff_th_h=%d \n",Hpan_value,Vpan_value,diff_th_h);
			VIP_DEBUG_PRINTF("GMVx1_ctr_acc =%d ,GMVx1_acc=%d \n",GMVx1_ctr_acc,GMVx1_acc);
			VIP_DEBUG_PRINTF("GMV_ratio_h =%d ,GMV_ratio_v=%d \n",GMV_ratio_h,GMV_ratio_v);
			VIP_DEBUG_PRINTF("Hpan_flag =%d ,Vpan_flag=%d \n",Hpan_flag_n,Vpan_flag_n);
		}
		else if(rtd_inl(0xb802267c)==1)
		{
			VIP_DEBUG_PRINTF("MC Hpan =%d ,Vpan=%d ,diff_th_v=%d \n",Hpan_value,Vpan_value,diff_th_v);
			VIP_DEBUG_PRINTF("GMVy1_ctr_acc =%d ,GMVy1_acc=%d \n",GMVy1_ctr_acc,GMVy1_acc);
			VIP_DEBUG_PRINTF("GMV_ratio_h =%d ,GMV_ratio_v=%d \n",GMV_ratio_h,GMV_ratio_v);
			VIP_DEBUG_PRINTF("Hpan_flag =%d ,Vpan_flag=%d \n",Hpan_flag_n,Vpan_flag_n);
		}
	}

	///////////////////////////
//	if((Hpan_value<=11 && Hpan_value>=9) && GMVx==3) //for interlace
//		Hpan_value=10;
	///////////////////////////

	//if(rtd_inl(0xb8022680)==1)
	{
	 scalerVIP_Cal_Idx_Ave_Hpan(Hpan_value,0);
	 scalerVIP_Cal_Idx_Ave_Hpan(Vpan_value,0);
	}
	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.ID_Pattern_47==TRUE))
	{

		if(rtd_inl(0xb802267c)==2)
		{
			VIP_DEBUG_PRINTF("Hpan_value =%d ,Vpan=%d \n",Hpan_value,Vpan_value);

		}
	}

	if((mcnr_mode==0)&&(sd_input ==1)) // if interlace mode & sd input
	{
		for (i=0; i<80; i++)
		{
			if (Smart_Integration_Status.SCREEN_HPAN_STATUS.Pass_Result_Sequence[i] == 1)
				hpan_pass_total++;
		}
		int pre_mv_avg = 0;
		for (i=0; i<16; i++) // pre 16 frames mv
		{
			pre_mv_avg+=(Smart_Integration_Status.SCREEN_HPAN_STATUS.Mv_Result_Sequence[i]-16);
		}
		pre_mv_avg/=16;

		int pass_total_th=30;

		if(Pan_flag==1)
		{
			 pass_total_th=10;
		 }

		//if((Hpan_value ==8)&&(DynamicOptimizeSystem[7]==1))



		if((Hpan_value ==8)&&(cur_source!=VIP_QUALITY_CVBS_NTSC)&&
			(cur_source!=VIP_QUALITY_CVBS_PAL))
		{
			di_im_new_mcnr_pan_condition.h_pan_mv_penalty =10;

			Hpan_value=9;
		}
		else
		{

			di_im_new_mcnr_pan_condition.h_pan_mv_penalty =3;

		}

//
		if(cur_source==VIP_QUALITY_CVBS_NTSC || cur_source==VIP_QUALITY_CVBS_PAL)
      			di_im_new_mcnr_pan_condition.h_pan_mv_penalty =5;


		di_im_new_mcnr_pan_condition.h_pan_mv_value = Hpan_value;
		di_im_new_mcnr_control4.n_mcnr_v_pan_mv = Vpan_value;


		//if (((pre_mv_avg >= -7 && pre_mv_avg <= 7 && hpan_pass_total > 20))&&SmartPic_clue->HMC_bin_hist_Ratio[16]<100)
		if ((((pre_mv_avg >= -7 && pre_mv_avg <= 7) && hpan_pass_total > pass_total_th))&& Smart_Integration_Status.SCREEN_MOTION_STATUS.MOTION_LEVEL > 10)
		{
                	Pan_flag=1;

			di_rtnr_output_clamp_reg.rtnr_output_clamp_en = 1; //set output clamp
			di_rtnr_output_clamp_reg.rtnr_output_clamp_luma = 64;
			di_rtnr_output_clamp_reg.rtnr_output_clamp_chroma = 64;

			di_im_new_mcnr_weighting_condition.mv_diff_slope = 0; // set mv diff slope

			// vpan value
			//	di_im_new_mcnr_control3.n_mcnr_v_pan_mv = 3;
			// chen 160714
				di_im_new_mcnr_control4.n_mcnr_v_pan_mv = 3+3;
			di_im_new_mcnr_control.n_h_pan_flag =1;
			di_im_new_mcnr_control.n_mcnr_offset = 0;
//			di_im_new_mcnr_pan_condition.h_pan_mv_value = Hpan_value;

			if(hpan_pass_total > 16)
			di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 12;
			else if(hpan_pass_total > 14)
				di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 8;
            		else if(hpan_pass_total > 12)
				di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 4;
			else if(hpan_pass_total > 10)
				di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 0;
			else
			{
				Pan_flag=0;
			}

		}
		else if(Vpan_flag_n==1 &&  Hpan_value==10 && abs(Vpan_value-3)>=1)//Hpan_flag_n==1)
		{
            		Pan_flag=1;

			di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 16;
			di_rtnr_output_clamp_reg.rtnr_output_clamp_en = 1; //set output clamp
			di_rtnr_output_clamp_reg.rtnr_output_clamp_luma = 64;
			di_rtnr_output_clamp_reg.rtnr_output_clamp_chroma = 64;
			di_im_new_mcnr_weighting_condition.mv_diff_slope = 0; // set mv diff slope

//			di_im_new_mcnr_control3.n_mcnr_v_pan_mv = 3;
			di_im_new_mcnr_control.n_h_pan_flag =1;
			di_im_new_mcnr_control.n_mcnr_offset = 0;

//			di_im_new_mcnr_control3.n_mcnr_v_pan_mv = Vpan_value;
			di_im_new_mcnr_pan_condition.h_pan_mv_value = 10;

		}
		else
		{
            		Pan_flag=0;

			di_im_new_mcnr_control.n_mcnr_offset = 2;
			di_im_new_mcnr_control.n_h_pan_flag =0 ;
			di_im_new_mcnr_weighting_condition.mv_diff_slope = 2;
			di_im_new_mcnr_control4.n_mcnr_v_pan_mv =3;
			di_rtnr_output_clamp_reg.rtnr_output_clamp_en =1;

			if (abs(GMVx-3)==0 && abs(GMVy-3)==0)
			{
				if(GMV_ratio>=95)
					di_im_new_mcnr_control.n_mcnr_offset = 6;
				else if(GMV_ratio>=90)
					di_im_new_mcnr_control.n_mcnr_offset = 5;
				else if(GMV_ratio>=85)
					di_im_new_mcnr_control.n_mcnr_offset = 4;
				else if(GMV_ratio>=80)
					di_im_new_mcnr_control.n_mcnr_offset = 3;
				else
					di_im_new_mcnr_control.n_mcnr_offset = 1;

				if(GMV_ratio>=90)
					di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 0;
				else
					di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 16;
			}
			else //if (abs(GMVx-3)<=1 && abs(GMVy-3)<=1)
			{
				di_im_new_mcnr_control.n_mcnr_offset = 2;
				di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 16;

			}
		}

		temp_x=abs(Hpan_value-10);//(abs(GMVx-3));
		temp_y=(abs(GMVy-3));
		temp_xy = max(temp_x,temp_y);

	        if(Pan_flag==0)
	        {

		if((temp_xy==0)&&(GMV_ratio>=80))
		{
			di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 0;
		}
		else if (temp_xy <= 1)
		{
			di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 10;
		}
		else if (temp_xy <= 2)
		{
			di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 12;
		}
		else if (temp_xy <= 3)
		{
			di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 14;
		}
		else
		{
			di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 16;
		}

		if(temp_x>10)
		{
			if(temp_x>20)
				temp_x=20;
			di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 20-temp_x;
 		}
		else if(temp_x>9)
		{
			di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 12;
 		}
		else if(temp_x>8)
		{
			di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 14;
		}
	        }

	}
	else if((mcnr_mode==0)&&(sd_input ==0)) // if interlace mode HD
	{
		for (i=0; i<120; i++)
		{
			if (Smart_Integration_Status.SCREEN_HPAN_STATUS.Pass_Result_Sequence[i] == 1)
				hpan_pass_total++;
		}
		int pre_mv_avg = 0;
		for (i=0; i<16; i++) // pre 16 frames mv
		{
			pre_mv_avg+=(Smart_Integration_Status.SCREEN_HPAN_STATUS.Mv_Result_Sequence[i]-16);
		}
		pre_mv_avg/=16;

		int pass_total_th=30;

		if(Pan_flag==1)
		{
			pass_total_th=10;
		}

		di_im_new_mcnr_pan_condition.h_pan_mv_penalty =3;

		di_im_new_mcnr_pan_condition.h_pan_mv_value = Hpan_value;
		di_im_new_mcnr_control4.n_mcnr_v_pan_mv = Vpan_value;



		//if (((pre_mv_avg >= -7 && pre_mv_avg <= 7 && hpan_pass_total > 20))&&SmartPic_clue->HMC_bin_hist_Ratio[16]<100)
		if (((pre_mv_avg >= -7 && pre_mv_avg <= 7 && hpan_pass_total > 20)))
		{
                	Pan_flag=1;

			di_rtnr_output_clamp_reg.rtnr_output_clamp_en = 1; //set output clamp
			di_rtnr_output_clamp_reg.rtnr_output_clamp_luma = 64;
			di_rtnr_output_clamp_reg.rtnr_output_clamp_chroma = 64;

			di_im_new_mcnr_weighting_condition.mv_diff_slope = 0; // set mv diff slope
			// vpan value
			di_im_new_mcnr_control4.n_mcnr_v_pan_mv = 3;
			di_im_new_mcnr_control.n_h_pan_flag =1;
			di_im_new_mcnr_control.n_mcnr_offset = 0;

			if(hpan_pass_total > 16)
			di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 16;
			else if(hpan_pass_total > 14)
				di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 8;
            		else if(hpan_pass_total > 12)
				di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 4;
			else if(hpan_pass_total > 10)
				di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 0;
			else
			{
				Pan_flag=0;
			}

		}
		else if(Vpan_flag_n==1 &&  Hpan_value==10 && abs(Vpan_value-3)>=1)//Hpan_flag_n==1)
		{
            		Pan_flag=1;

			di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 16;
			di_rtnr_output_clamp_reg.rtnr_output_clamp_en = 1; //set output clamp
			di_rtnr_output_clamp_reg.rtnr_output_clamp_luma = 64;
			di_rtnr_output_clamp_reg.rtnr_output_clamp_chroma = 64;
			di_im_new_mcnr_weighting_condition.mv_diff_slope = 0; // set mv diff slope

//			di_im_new_mcnr_control3.n_mcnr_v_pan_mv = 3;
			di_im_new_mcnr_control.n_h_pan_flag =1;
			di_im_new_mcnr_control.n_mcnr_offset = 0;

//			di_im_new_mcnr_control3.n_mcnr_v_pan_mv = Vpan_value;
			di_im_new_mcnr_pan_condition.h_pan_mv_value = 10;

		}
		else
		{
            		Pan_flag=0;

			di_im_new_mcnr_control.n_mcnr_offset = 2;
			di_im_new_mcnr_control.n_h_pan_flag =0 ;
			di_im_new_mcnr_weighting_condition.mv_diff_slope = 2;
			di_im_new_mcnr_control4.n_mcnr_v_pan_mv =3;
			di_rtnr_output_clamp_reg.rtnr_output_clamp_en =1;

			if (abs(GMVx-3)==0 && abs(GMVy-3)==0)
			{
				if(GMV_ratio>=95)
					di_im_new_mcnr_control.n_mcnr_offset = 6;
				else if(GMV_ratio>=90)
					di_im_new_mcnr_control.n_mcnr_offset = 5;
				else if(GMV_ratio>=85)
					di_im_new_mcnr_control.n_mcnr_offset = 4;
				else if(GMV_ratio>=80)
					di_im_new_mcnr_control.n_mcnr_offset = 3;
				else
					di_im_new_mcnr_control.n_mcnr_offset = 1;

				if(GMV_ratio>=90)
					di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 0;
				else
					di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 16;
			}
			else //if (abs(GMVx-3)<=1 && abs(GMVy-3)<=1)
			{
				di_im_new_mcnr_control.n_mcnr_offset = 1;
				di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 16;

			}




		}

		temp_x=abs(Hpan_value-10);//(abs(GMVx-3));
		temp_y=(abs(GMVy-3));
		temp_xy = max(temp_x,temp_y);
		mv_index =SmartPic_clue->HMC_bin_hist_Ratio[16];


	        if(Pan_flag==0)
	        {
	       //ROSPrintf("\n xy=%d , GMV_ratio=%d ",scalerVIP_Get_Noise_Level(),GMV_ratio);

			if((temp_xy==0)&&(GMV_ratio>=80))
	    		{
	    			di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 0;
				di_im_new_mcnr_weighting_condition.mv_diff_slope = 2;
	    		}
	    		else if (temp_xy <= 1)
	    		{
				if(GMV_ratio>=60)  // this patch for lg test disc #46
				{
					di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 10;
					di_im_new_mcnr_weighting_condition.mv_diff_slope = 1;
				}
				else if (GMV_ratio>=50)
				{
					di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 11;
					di_im_new_mcnr_weighting_condition.mv_diff_slope = 1;

				}
				else if(GMV_ratio>=40)
				{
					di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 12;
					di_im_new_mcnr_weighting_condition.mv_diff_slope = 1;

				}
				else
				{
					di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 13;
					di_im_new_mcnr_weighting_condition.mv_diff_slope = 1;
				}
	    		}
	    		else if (temp_xy <= 2)
	    		{

				if(GMV_ratio>=60)
				{
					di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 12;
					di_im_new_mcnr_weighting_condition.mv_diff_slope = 1;
				}
				else if (GMV_ratio>=50)
				{
					di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 13;
					di_im_new_mcnr_weighting_condition.mv_diff_slope = 1;

				}
				else if(GMV_ratio>=40)
				{
					di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 14;
					di_im_new_mcnr_weighting_condition.mv_diff_slope = 1;

				}
				else
				{
					di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 15;
					di_im_new_mcnr_weighting_condition.mv_diff_slope = 1;
				}
	    		}
	    		else if (temp_xy <= 3)
	    		{

				if(GMV_ratio>=60)
				{
					di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 14;
					di_im_new_mcnr_weighting_condition.mv_diff_slope = 1;
				}
				else if (GMV_ratio>=50)
				{
					di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 15;
					di_im_new_mcnr_weighting_condition.mv_diff_slope = 1;

				}
				else
				{
					di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 15;
					di_im_new_mcnr_weighting_condition.mv_diff_slope = 1;
				}
			}
			else
			{
	    			di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 16;
				di_im_new_mcnr_weighting_condition.mv_diff_slope = 0;
	    		}

		/*
	    		if(temp_x>10)
	    		{
	    			if(temp_x>20)
	    				temp_x=20;
	    			di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 20-temp_x;
	     		}
	    		else if(temp_x>9)
	    		{
	    			di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 12;
	     		}
	    		else if(temp_x>8)
	    		{
	    			di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 14;
	    		}
	    	*/
	        }


		if(mv_index<400) //add new condiction for #109
		{
			di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 16;
			di_im_new_mcnr_control.n_mcnr_offset = 1;
			di_im_new_mcnr_weighting_condition.mv_diff_slope = 1;


		}
		else if (mv_index>500) // for #46 background color noise
		{
			di_im_new_mcnr_control.n_mcnr_offset = 3;
			di_im_new_mcnr_weighting_condition.mv_diff_slope = 3;
		}
		/*
		else if (mv_index<400)
		{
			di_im_new_mcnr_control.n_mcnr_offset = 2;
			di_im_new_mcnr_weighting_condition.mv_diff_slope = 2;
		}
		else //noise very big or full motion
		{
			di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 0;
			di_im_new_mcnr_control.n_mcnr_offset = 6;
			di_im_new_mcnr_weighting_condition.mv_diff_slope = 4;
		}*/


	}
	else
	{

		Hpan_flag_n =0;//k2l progressive mode ,pan info easy mistake , disable it
		Vpan_flag_n =0;//k2l progressive mode ,pan info easy mistake , disable it

		if( Hpan_flag_n==1 && Vpan_value==3 && abs(Hpan_value-10)>=1)
		{
            		Pan_flag=1;

			di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 16;

			di_rtnr_output_clamp_reg.rtnr_output_clamp_en = 1; //set output clamp
			di_rtnr_output_clamp_reg.rtnr_output_clamp_luma = 64;
			di_rtnr_output_clamp_reg.rtnr_output_clamp_chroma = 64;

			di_im_new_mcnr_weighting_condition.mv_diff_slope = 0; // set mv diff slope


			// vpan value

			di_im_new_mcnr_control4.n_mcnr_v_pan_mv = 3;
			di_im_new_mcnr_control.n_h_pan_flag =1;
			di_im_new_mcnr_control.n_mcnr_offset = 0;


			di_im_new_mcnr_pan_condition.h_pan_mv_value = Hpan_value;
		}
		else if(Vpan_flag_n==1 &&  Hpan_value==10 && abs(Vpan_value-3)>=1)//Hpan_flag_n==1)
		{
           		 Pan_flag=1;

		//	di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 16;

			di_rtnr_output_clamp_reg.rtnr_output_clamp_en = 1; //set output clamp
			di_rtnr_output_clamp_reg.rtnr_output_clamp_luma = 64;
			di_rtnr_output_clamp_reg.rtnr_output_clamp_chroma = 64;

			di_im_new_mcnr_weighting_condition.mv_diff_slope = 0; // set mv diff slope


			di_im_new_mcnr_control4.n_mcnr_v_pan_mv = 3;
			di_im_new_mcnr_control.n_h_pan_flag =1;
			di_im_new_mcnr_control.n_mcnr_offset = 0;

			di_im_new_mcnr_control4.n_mcnr_v_pan_mv = Vpan_value;
			di_im_new_mcnr_pan_condition.h_pan_mv_value = 10;
		}

		else
		{
            		Pan_flag=0;

			di_im_new_mcnr_control.n_mcnr_offset = 2;
			di_im_new_mcnr_control.n_h_pan_flag =0 ;
			di_im_new_mcnr_weighting_condition.mv_diff_slope = 2;
			di_im_new_mcnr_control4.n_mcnr_v_pan_mv =0;
			di_rtnr_output_clamp_reg.rtnr_output_clamp_en =1;


			if (abs(GMVx-10)==0 && abs(GMVy-3)==0)
			{
				if(GMV_ratio>=95)
					di_im_new_mcnr_control.n_mcnr_offset = 6;
				else if(GMV_ratio>=90)
					di_im_new_mcnr_control.n_mcnr_offset = 5;
				else if(GMV_ratio>=85)
					di_im_new_mcnr_control.n_mcnr_offset = 4;
				else if(GMV_ratio>=80)
					di_im_new_mcnr_control.n_mcnr_offset = 3;
				else
					di_im_new_mcnr_control.n_mcnr_offset = 1;

			}
			else //if (abs(GMVx-3)<=1 && abs(GMVy-3)<=1)
			{
				di_im_new_mcnr_control.n_mcnr_offset = 2;
			//	di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 16;

			}

		}
        	if(Pan_flag==0)
	        {

			temp_x=(abs(GMVx-10));
			temp_y=(abs(GMVy-3));
			temp_xy = max(temp_x,temp_y);
			//ROSPrintf("\n xy=%d , GMV_ratio=%d ",scalerVIP_Get_Noise_Level(),GMV_ratio);

			if((temp_xy==0)&&(GMV_ratio>=90))
			{
				di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 0;
				di_im_new_mcnr_control.n_h_pan_flag =0;


			}
			else if((scalerVIP_Get_Noise_Level()<=2)) //this patch for hdr big hero building teeth.
			{
				di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 8;
				di_im_new_mcnr_weighting_condition.mv_diff_slope = 1;

			}
			else if (temp_xy <= 1)
			{
				di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 10;
			}
			else if (temp_xy <= 2)
			{
				di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 12;
			}
			else if (temp_xy <= 3)
			{
				di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 14;
			}
			else
			{
				di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth = 16;
			}
	        }
	}

	if((Pan_flag==0)&&DynamicOptimizeSystem[7]==1)
	{
		di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth =0;
	}

        ////////////////////////////////// special case
	//ROSPrintf("\n GMV =%d \n ",GMV_ratio);

#if 0
	ROSPrintf("gx =%d ,gy=%d ,gmx =%d , gmy =%d \n",init_di_smd_gmvcoeff3_reg.smd_gmv1_x,
		init_di_smd_gmvcoeff3_reg.smd_gmv1_y,di_di_smd_sampling_gmvb_reg.smd_gmvb_x,
		di_di_smd_sampling_gmvb_reg.smd_gmvb_y);

	{
		GMVx = 10+3-init_di_smd_gmvcoeff3_reg.smd_gmv1_x;
		GMVy = 3+3-init_di_smd_gmvcoeff3_reg.smd_gmv1_y;

		if(GMVy>4)
			GMVy=4;

		if(GMVx<9)
			GMVx=9;


		di_im_new_mcnr_pan_condition.h_pan_mv_value = GMVx;
		di_im_new_mcnr_control3.n_mcnr_v_pan_mv = GMVy;


	}

#endif


if((max_hist_h_MV==10)&&(sd_input==1))
{
	di_im_new_mcnr_control.n_h_pan_flag =0;
}
		//	di_im_new_mcnr_control.n_mcnr_offset = 1;
//	di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth=12;


	scalerVIP_DI_MiddleWare_MCNR_Set_Pan_Flag(di_im_new_mcnr_control.n_h_pan_flag);


    mv_value = SmartPic_clue->HMC_bin_hist_Ratio[15]+SmartPic_clue->HMC_bin_hist_Ratio[16]+SmartPic_clue->HMC_bin_hist_Ratio[17];


  //  ROSPrintf("\n hmc_C=%d ,r1=%d,L2 =%d ,mv_value =%d\n",SmartPic_clue->HMC_bin_hist_Ratio[16],SmartPic_clue->HMC_bin_hist_Ratio[15],SmartPic_clue->HMC_bin_hist_Ratio[17],mv_value);

  //  if((Pan_flag==0)&&mv_value>800)
  //      di_im_new_mcnr_clamping_value.mcnr_weight_clamp_upth=0;

	rtd_outl(DI_IM_DI_RTNR_HMCNR_reg, di_rtnr_hmcnr_reg.regValue);
	rtd_outl(DI_RTNR_OUTPUT_CLAMP_reg, di_rtnr_output_clamp_reg.regValue);
	rtd_outl(DI_IM_NEW_MCNR_WEIGHTING_CONDITION_reg, di_im_new_mcnr_weighting_condition.regValue);
	rtd_outl(DI_IM_NEW_MCNR_CONTROL4_reg, di_im_new_mcnr_control4.regValue);
	rtd_outl(DI_IM_NEW_MCNR_CONTROL_reg, di_im_new_mcnr_control.regValue);
	rtd_outl(DI_IM_NEW_MCNR_PAN_CONDITION_reg, di_im_new_mcnr_pan_condition.regValue);
	rtd_outl(DI_IM_NEW_MCNR_CLAMPING_VALUE_reg,di_im_new_mcnr_clamping_value.regValue);



}
#endif

void scalerVIP_DI_MiddleWare_MCNR_Set_GMV_Ratio(int GMV_xy_ratio)
{
	GMV_ratio = GMV_xy_ratio;
}


unsigned char scalerVIP_DI_MiddleWare_MCNR_Get_GMV_Ratio(void)
{
	return GMV_ratio;
}

unsigned char scalerVIP_DI_MiddleWare_MCNR_Get_Pan_Flag(void)
{
	return Mcnr_Pan;
}
void scalerVIP_DI_MiddleWare_MCNR_Set_Pan_Flag(unsigned char pan_flag)
{
	Mcnr_Pan = pan_flag;
}
unsigned char scalerVIP_DI_MiddleWare_MCNR_Get_V_Pan_Flag(void)
{
	return Mcnr_V_Pan;
}
void scalerVIP_DI_MiddleWare_MCNR_Set_V_Pan_Flag(unsigned char pan_flag)
{
	Mcnr_V_Pan = pan_flag;
}

void scalerVIP_DI_MiddleWare_FILM_Apply()
{
	di_im_di_film_sawtooth_filmframe_th_RBUS film_sawtooth_filmframe_th_reg;
	di_im_di_si_film_final_result_RBUS im_di_si_film_final_result_reg;
	film_sawtooth_filmframe_th_reg.regValue = rtd_inl(DI_IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_reg);
	im_di_si_film_final_result_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_FINAL_RESULT_reg);

	unsigned char cur_source=(RPC_system_info_structure_table->VIP_source);
	static unsigned char pre_source =255;
	static unsigned char film_SawtoothThl_ref = 22;
	static unsigned char film_FrMotionThl_ref = 18;
	unsigned char film_SawtoothThl = 22;
	unsigned char film_FrMotionThl = 18;
	unsigned char motionMax = 28;
	unsigned char motionMin = 8;
	unsigned char motionl_level;
	unsigned char motionl_level_tmp=0;
	unsigned char motion_ratio = im_di_si_film_final_result_reg.dummy180240c4_31_9 & 0xf;
	motion_ratio = (motion_ratio==0)? 4:motion_ratio;

	if(pre_source !=cur_source)
	{
		film_SawtoothThl_ref = film_sawtooth_filmframe_th_reg.film_sawtooththl;
		film_FrMotionThl_ref = film_sawtooth_filmframe_th_reg.film_frmotionthl;
	}
	pre_source = cur_source;

	motionl_level = scalerVIP_DI_MiddleWare_GetStatus(STATUS_MOTION);
	//	STATUS_MOTION, //0~48, 0:condition error 1:no motion very still, 48: very motion

	//	motion		0	motionMin	motionMax	48
	//	film ratio		0	0			100			100
	motionl_level_tmp = motionl_level;
	motionl_level_tmp = (motionl_level_tmp<motionMin)? motionMin:motionl_level_tmp;
	motionl_level_tmp = (motionl_level_tmp>motionMax)? motionMax:motionl_level_tmp;

	film_SawtoothThl = film_SawtoothThl_ref*(motionl_level_tmp-motionMin)/(motionMax-motionMin);
	film_FrMotionThl = film_FrMotionThl_ref*(motionl_level_tmp-motionMin)/(motionMax-motionMin);

	film_SawtoothThl = (film_SawtoothThl<(film_SawtoothThl_ref/motion_ratio))? (film_SawtoothThl_ref/motion_ratio):film_SawtoothThl;
	film_FrMotionThl = (film_FrMotionThl<(film_FrMotionThl_ref/motion_ratio))? (film_FrMotionThl_ref/motion_ratio):film_FrMotionThl;

	film_sawtooth_filmframe_th_reg.film_sawtooththl =  film_SawtoothThl;
	film_sawtooth_filmframe_th_reg.film_frmotionthl = film_FrMotionThl;

	rtd_outl(DI_IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_reg, film_sawtooth_filmframe_th_reg.regValue);

}

void scalerVIP_DI_MiddleWare_ZOOMMOTION_Apply(unsigned char offset)
{
	di_im_di_zoommotion_detector_RBUS zoommotion_detector_reg;
	di_im_di_zoommotion_det_fm_th_a_RBUS zoommotion_det_fm_th_a_reg;
	di_im_di_zoommotion_det_fm_th_b_RBUS zoommotion_det_fm_th_b_reg;
	di_im_di_zoommotion_det_fm_th_c_RBUS zoommotion_det_fm_th_c_reg;
	di_im_di_ma_frame_motion_th_a_RBUS di_ma_frame_motion_th_a_reg;
	di_im_di_ma_frame_motion_th_b_RBUS di_ma_frame_motion_th_b_reg;
	di_im_di_ma_frame_motion_th_c_RBUS di_ma_frame_motion_th_c_reg;

	zoommotion_detector_reg.regValue = rtd_inl(DI_IM_DI_ZoomMotion_Detector_reg);
	zoommotion_det_fm_th_a_reg.regValue = rtd_inl(DI_IM_DI_ZoomMotion_Det_FM_TH_A_reg);
	zoommotion_det_fm_th_b_reg.regValue = rtd_inl(DI_IM_DI_ZoomMotion_Det_FM_TH_B_reg);
	zoommotion_det_fm_th_c_reg.regValue = rtd_inl(DI_IM_DI_ZoomMotion_Det_FM_TH_C_reg);
	di_ma_frame_motion_th_a_reg.regValue = rtd_inl(DI_IM_DI_MA_FRAME_MOTION_TH_A_reg);
	di_ma_frame_motion_th_b_reg.regValue = rtd_inl(DI_IM_DI_MA_FRAME_MOTION_TH_B_reg);
	di_ma_frame_motion_th_c_reg.regValue = rtd_inl(DI_IM_DI_MA_FRAME_MOTION_TH_C_reg);

	if (Smart_Integration_Status.SCREEN_ACTION_STATUS.ZOOMMOTION_detect == 1)
	{
		zoommotion_det_fm_th_a_reg.smd_zoommotion_ma_framehtha	= di_ma_frame_motion_th_a_reg.ma_framehtha + offset;
		zoommotion_det_fm_th_a_reg.smd_zoommotion_ma_framemtha	= di_ma_frame_motion_th_a_reg.ma_framemtha + offset;
		zoommotion_det_fm_th_a_reg.smd_zoommotion_ma_framerlvtha	= di_ma_frame_motion_th_a_reg.ma_framerlvtha + offset;
		zoommotion_det_fm_th_a_reg.smd_zoommotion_ma_framestha	= di_ma_frame_motion_th_a_reg.ma_framestha + offset;

		zoommotion_det_fm_th_b_reg.smd_zoommotion_ma_framehthb	= di_ma_frame_motion_th_b_reg.ma_framehthb + offset;
		zoommotion_det_fm_th_b_reg.smd_zoommotion_ma_framemthb	= di_ma_frame_motion_th_b_reg.ma_framemthb + offset;
		zoommotion_det_fm_th_b_reg.smd_zoommotion_ma_framerlvthb	= di_ma_frame_motion_th_b_reg.ma_framerlvthb + offset;
		zoommotion_det_fm_th_b_reg.smd_zoommotion_ma_framesthb	= di_ma_frame_motion_th_b_reg.ma_framesthb + offset;

		zoommotion_det_fm_th_c_reg.smd_zoommotion_ma_framehthc	= di_ma_frame_motion_th_c_reg.ma_framehthc + offset;
		zoommotion_det_fm_th_c_reg.smd_zoommotion_ma_framemthc	= di_ma_frame_motion_th_c_reg.ma_framemthc + offset;
		zoommotion_det_fm_th_c_reg.smd_zoommotion_ma_framerlvthc	= di_ma_frame_motion_th_c_reg.ma_framerlvthc + offset;
		zoommotion_det_fm_th_c_reg.smd_zoommotion_ma_framesthc	= di_ma_frame_motion_th_c_reg.ma_framesthc + offset;

		zoommotion_detector_reg.smd_zoommotion_en = 1;
	}
	else
	{
		zoommotion_detector_reg.smd_zoommotion_en = 0;
	}

	rtd_outl(DI_IM_DI_ZoomMotion_Det_FM_TH_A_reg, zoommotion_det_fm_th_a_reg.regValue);
	rtd_outl(DI_IM_DI_ZoomMotion_Det_FM_TH_B_reg, zoommotion_det_fm_th_b_reg.regValue);
	rtd_outl(DI_IM_DI_ZoomMotion_Det_FM_TH_C_reg, zoommotion_det_fm_th_c_reg.regValue);
	rtd_outl(DI_IM_DI_ZoomMotion_Detector_reg, zoommotion_detector_reg.regValue);
}

void scalerVIP_DI_MiddleWare_SLOWMOTION_Apply(unsigned char offset)
{
	di_im_di_slowmotion_detector_1_RBUS slowmotion_detector_1_reg;
	di_im_di_slowmotion_det_fm_th_a_RBUS slowmotion_det_fm_th_a_reg;
	di_im_di_slowmotion_det_fm_th_b_RBUS slowmotion_det_fm_th_b_reg;
	di_im_di_slowmotion_det_fm_th_c_RBUS slowmotion_det_fm_th_c_reg;
	di_im_di_ma_frame_motion_th_a_RBUS di_ma_frame_motion_th_a_reg;
	di_im_di_ma_frame_motion_th_b_RBUS di_ma_frame_motion_th_b_reg;
	di_im_di_ma_frame_motion_th_c_RBUS di_ma_frame_motion_th_c_reg;

	slowmotion_detector_1_reg.regValue = rtd_inl(DI_IM_DI_SlowMotion_Detector_1_reg);
	slowmotion_det_fm_th_a_reg.regValue = rtd_inl(DI_IM_DI_SlowMotion_Det_FM_TH_A_reg);
	slowmotion_det_fm_th_b_reg.regValue = rtd_inl(DI_IM_DI_SlowMotion_Det_FM_TH_B_reg);
	slowmotion_det_fm_th_c_reg.regValue = rtd_inl(DI_IM_DI_SlowMotion_Det_FM_TH_C_reg);
	di_ma_frame_motion_th_a_reg.regValue = rtd_inl(DI_IM_DI_MA_FRAME_MOTION_TH_A_reg);
	di_ma_frame_motion_th_b_reg.regValue = rtd_inl(DI_IM_DI_MA_FRAME_MOTION_TH_B_reg);
	di_ma_frame_motion_th_c_reg.regValue = rtd_inl(DI_IM_DI_MA_FRAME_MOTION_TH_C_reg);

	if (Smart_Integration_Status.SCREEN_ACTION_STATUS.SLOWMOTION_detect == 1 && Smart_Integration_Status.SCREEN_MOTION_STATUS.MOTION_LEVEL < 14)
	{
		slowmotion_det_fm_th_a_reg.smd_slowmotion_ma_framehtha		= di_ma_frame_motion_th_a_reg.ma_framehtha + offset;
		slowmotion_det_fm_th_a_reg.smd_slowmotion_ma_framemtha		= di_ma_frame_motion_th_a_reg.ma_framemtha + offset;
		slowmotion_det_fm_th_a_reg.smd_slowmotion_ma_framerlvtha	= di_ma_frame_motion_th_a_reg.ma_framerlvtha + offset;
		slowmotion_det_fm_th_a_reg.smd_slowmotion_ma_framestha		= di_ma_frame_motion_th_a_reg.ma_framestha + offset;

		slowmotion_det_fm_th_b_reg.smd_slowmotion_ma_framehthb		= di_ma_frame_motion_th_b_reg.ma_framehthb + offset;
		slowmotion_det_fm_th_b_reg.smd_slowmotion_ma_framemthb		= di_ma_frame_motion_th_b_reg.ma_framemthb + offset;
		slowmotion_det_fm_th_b_reg.smd_slowmotion_ma_framerlvthb	= di_ma_frame_motion_th_b_reg.ma_framerlvthb + offset;
		slowmotion_det_fm_th_b_reg.smd_slowmotion_ma_framesthb		= di_ma_frame_motion_th_b_reg.ma_framesthb + offset;

		slowmotion_det_fm_th_c_reg.smd_slowmotion_ma_framehthc		= di_ma_frame_motion_th_c_reg.ma_framehthc + offset;
		slowmotion_det_fm_th_c_reg.smd_slowmotion_ma_framemthc		= di_ma_frame_motion_th_c_reg.ma_framemthc + offset;
		slowmotion_det_fm_th_c_reg.smd_slowmotion_ma_framerlvthc	= di_ma_frame_motion_th_c_reg.ma_framerlvthc + offset;
		slowmotion_det_fm_th_c_reg.smd_slowmotion_ma_framesthc		= di_ma_frame_motion_th_c_reg.ma_framesthc + offset;

		slowmotion_detector_1_reg.smd_slowmotion_en = 1;
	}
	else if (Smart_Integration_Status.SCREEN_ACTION_STATUS.SLOWMOTION_detect == 0 && Smart_Integration_Status.SCREEN_ACTION_STATUS.FADING_detect == 0)
	{
		slowmotion_detector_1_reg.smd_slowmotion_en = 0;
	}

	rtd_outl(DI_IM_DI_SlowMotion_Det_FM_TH_A_reg, slowmotion_det_fm_th_a_reg.regValue);
	rtd_outl(DI_IM_DI_SlowMotion_Det_FM_TH_B_reg, slowmotion_det_fm_th_b_reg.regValue);
	rtd_outl(DI_IM_DI_SlowMotion_Det_FM_TH_C_reg, slowmotion_det_fm_th_c_reg.regValue);
	rtd_outl(DI_IM_DI_SlowMotion_Detector_1_reg, slowmotion_detector_1_reg.regValue);
}

void scalerVIP_DI_MiddleWare_FADING_Apply(unsigned char offset)
{
	di_im_di_slowmotion_detector_1_RBUS slowmotion_detector_1_reg;
	di_im_di_slowmotion_det_fm_th_a_RBUS slowmotion_det_fm_th_a_reg;
	di_im_di_slowmotion_det_fm_th_b_RBUS slowmotion_det_fm_th_b_reg;
	di_im_di_slowmotion_det_fm_th_c_RBUS slowmotion_det_fm_th_c_reg;
	di_im_di_ma_frame_motion_th_a_RBUS di_ma_frame_motion_th_a_reg;
	di_im_di_ma_frame_motion_th_b_RBUS di_ma_frame_motion_th_b_reg;
	di_im_di_ma_frame_motion_th_c_RBUS di_ma_frame_motion_th_c_reg;

	slowmotion_detector_1_reg.regValue = rtd_inl(DI_IM_DI_SlowMotion_Detector_1_reg);
	slowmotion_det_fm_th_a_reg.regValue = rtd_inl(DI_IM_DI_SlowMotion_Det_FM_TH_A_reg);
	slowmotion_det_fm_th_b_reg.regValue = rtd_inl(DI_IM_DI_SlowMotion_Det_FM_TH_B_reg);
	slowmotion_det_fm_th_c_reg.regValue = rtd_inl(DI_IM_DI_SlowMotion_Det_FM_TH_C_reg);
	di_ma_frame_motion_th_a_reg.regValue = rtd_inl(DI_IM_DI_MA_FRAME_MOTION_TH_A_reg);
	di_ma_frame_motion_th_b_reg.regValue = rtd_inl(DI_IM_DI_MA_FRAME_MOTION_TH_B_reg);
	di_ma_frame_motion_th_c_reg.regValue = rtd_inl(DI_IM_DI_MA_FRAME_MOTION_TH_C_reg);

	if (Smart_Integration_Status.SCREEN_ACTION_STATUS.FADING_detect == 1)
	{
		slowmotion_det_fm_th_a_reg.smd_slowmotion_ma_framehtha		= di_ma_frame_motion_th_a_reg.ma_framehtha + offset;
		slowmotion_det_fm_th_a_reg.smd_slowmotion_ma_framemtha		= di_ma_frame_motion_th_a_reg.ma_framemtha + offset;
		slowmotion_det_fm_th_a_reg.smd_slowmotion_ma_framerlvtha	= di_ma_frame_motion_th_a_reg.ma_framerlvtha + offset;
		slowmotion_det_fm_th_a_reg.smd_slowmotion_ma_framestha		= di_ma_frame_motion_th_a_reg.ma_framestha + offset;

		slowmotion_det_fm_th_b_reg.smd_slowmotion_ma_framehthb		= di_ma_frame_motion_th_b_reg.ma_framehthb + offset;
		slowmotion_det_fm_th_b_reg.smd_slowmotion_ma_framemthb		= di_ma_frame_motion_th_b_reg.ma_framemthb + offset;
		slowmotion_det_fm_th_b_reg.smd_slowmotion_ma_framerlvthb	= di_ma_frame_motion_th_b_reg.ma_framerlvthb + offset;
		slowmotion_det_fm_th_b_reg.smd_slowmotion_ma_framesthb		= di_ma_frame_motion_th_b_reg.ma_framesthb + offset;

		slowmotion_det_fm_th_c_reg.smd_slowmotion_ma_framehthc		= di_ma_frame_motion_th_c_reg.ma_framehthc + offset;
		slowmotion_det_fm_th_c_reg.smd_slowmotion_ma_framemthc		= di_ma_frame_motion_th_c_reg.ma_framemthc + offset;
		slowmotion_det_fm_th_c_reg.smd_slowmotion_ma_framerlvthc	= di_ma_frame_motion_th_c_reg.ma_framerlvthc + offset;
		slowmotion_det_fm_th_c_reg.smd_slowmotion_ma_framesthc		= di_ma_frame_motion_th_c_reg.ma_framesthc + offset;

		slowmotion_detector_1_reg.smd_slowmotion_en = 1;
	}
	else if (Smart_Integration_Status.SCREEN_ACTION_STATUS.SLOWMOTION_detect == 0 && Smart_Integration_Status.SCREEN_ACTION_STATUS.FADING_detect == 0)
	{
		slowmotion_detector_1_reg.smd_slowmotion_en = 0;
	}

	rtd_outl(DI_IM_DI_SlowMotion_Det_FM_TH_A_reg, slowmotion_det_fm_th_a_reg.regValue);
	rtd_outl(DI_IM_DI_SlowMotion_Det_FM_TH_B_reg, slowmotion_det_fm_th_b_reg.regValue);
	rtd_outl(DI_IM_DI_SlowMotion_Det_FM_TH_C_reg, slowmotion_det_fm_th_c_reg.regValue);
	rtd_outl(DI_IM_DI_SlowMotion_Detector_1_reg, slowmotion_detector_1_reg.regValue);
}

void scalerVIP_DI_MiddleWare_SPECIAL_Apply(unsigned char source_timing_index)
{
#if 1
	di_di_smd_additionalcoeff2_RBUS smd_additionalcoeff2_reg;
	smd_additionalcoeff2_reg.regValue = rtd_inl(DI_DI_SMD_AdditionalCoeff2_reg);

	if (Smart_Integration_Status.SCREEN_SPECIAL_STATUS.STILL_CONCENTRIC_CIRCLES_detect == 1)
	{
		smd_additionalcoeff2_reg.smd_image_boundary_height = 0;
		smd_additionalcoeff2_reg.smd_image_boundary_width = 0;
	}
	else
	{
		smd_additionalcoeff2_reg.smd_image_boundary_height = 4;
		smd_additionalcoeff2_reg.smd_image_boundary_width = 10;
	}

	rtd_outl(DI_DI_SMD_AdditionalCoeff2_reg, smd_additionalcoeff2_reg.regValue);

#else // dirty solution
	//=========同心圓
	//+++++++++中間DI做intra
	//+++++++++外圍做weave
	unsigned int mcc_solution_table[6][6] =
	{
//		en,		xstart_12_0	ystart_12_0	xend_12_0	yend_12_0	DI fix weave
		{1,		0x0080,		0x0040,		0x01ff,		0x008f,		1		},	//NTSC
		{1,		0x0080,		0x0040,		0x01ff,		0x008f,		1		},	//PAL
		{1,		0x0080,		0x0040,		0x01ff,		0x008f,		1		},	//SD
		{0,		0x0080,		0x0040,		0x01ff,		0x008f,		0		},	//HD
		{0,		0x0080,		0x0040,		0x01ff,		0x008f,		0		},	//VGA
		{1,		0x0080,		0x0040,		0x01ff,		0x008f,		1		},	//HDMI PAL
	};
							// NTSC   PAL      SD        HD       VGA     HDMI PAL
	unsigned int pan_info_table[6] = {0xA000,0xf000,0xBD00,0xf000,0xf000,0xf000};


	static int temp_cnt;
	temp_cnt++;
	//if((motion_concentric_circles_detect(0, scaler_disp_info[_CHANNEL1].DispWid, scaler_disp_info[_CHANNEL1].DispLen) == 1)&&(mcc_solution_table[source_timing_index][0] == 1))
	if((Smart_Integration_Status.SCREEN_SPECIAL_STATUS.STILL_CONCENTRIC_CIRCLES_detect == 1)&&(mcc_solution_table[source_timing_index][0] == 1))
	{
		//VIP_DEBUG_PRINTF("\n    ifififif ifififif ..............= %d <<<<<\n",temp_cnt);
		di_im_di_weave_window_control_RBUS im_di_weave_window_control_reg;
		di_im_di_weave_window_0_start_RBUS im_di_weave_window_0_start_reg;
		di_im_di_weave_window_0_end_RBUS im_di_weave_window_0_end_reg;

		im_di_weave_window_control_reg.regValue = rtd_inl(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg);
		im_di_weave_window_0_start_reg.regValue = rtd_inl(DI_IM_DI_WEAVE_WINDOW_0_START_reg);
		im_di_weave_window_0_end_reg.regValue = rtd_inl(DI_IM_DI_WEAVE_WINDOW_0_END_reg);

		di_im_di_pan_detection_statistic_4_RBUS im_di_pan_detection_statistic_4_reg;
		im_di_pan_detection_statistic_4_reg.regValue = rtd_inl(DI_IM_DI_PAN_DETECTION_STATISTIC_4_reg);

		im_di_weave_window_control_reg.fixedwindowmode = 3;
		if (im_di_pan_detection_statistic_4_reg.hmc_c0_pixelsum > pan_info_table[source_timing_index])
			im_di_weave_window_control_reg.fixedwindow0 = 0;
		else
		{
			//VIP_DEBUG_PRINTF("\n    if if if if ..............= %x <<<<<\n",im_di_pan_detection_statistic_4_reg.hmc_c0_pixelsum);
			im_di_weave_window_control_reg.fixedwindow0 = 1;
		}
		im_di_weave_window_0_start_reg.xstart_12_0 = (mcc_solution_table[source_timing_index][1] + (((Smart_Integration_Status.Frame_Couter*7)%5)-2));		// +/- 2跳動
		im_di_weave_window_0_start_reg.ystart_12_0 = (mcc_solution_table[source_timing_index][2] + (((Smart_Integration_Status.Frame_Couter*7)%5)-2));		// +/- 2跳動
		im_di_weave_window_0_end_reg.xend_12_0 = (mcc_solution_table[source_timing_index][3] + (((Smart_Integration_Status.Frame_Couter*7)%5)-2));		// +/- 2跳動
		im_di_weave_window_0_end_reg.yend_12_0 = (mcc_solution_table[source_timing_index][4] + (((Smart_Integration_Status.Frame_Couter*7)%5)-2));		// +/- 2跳動


		if(mcc_solution_table[source_timing_index][5] == 1)//av pal
		{
			rtd_maskl(DI_IM_DI_CONTROL_reg, 0xfffffff3, 0x8);			//DI fix weave
		}

		//	VIP_DEBUG_PRINTF("\n    source_timing_index= %d <<<<<\n",source_timing_index);
		if( (Scaler_InputSrcGetMainChType()) == _SRC_HDMI&&(source_timing_index == 5) )
		{ // HDMI
			rtd_clearbits(VGIP_VGIP_CHN1_CTRL_reg, _BIT18);
		}
		else if( (Scaler_InputSrcGetMainChType()) == _SRC_CVBS&&(source_timing_index == 1) )
		{
			rtd_setbits(VGIP_VGIP_CHN1_CTRL_reg, _BIT18);
		}
		rtd_outl(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg,im_di_weave_window_control_reg.regValue);
		rtd_outl(DI_IM_DI_WEAVE_WINDOW_0_START_reg,im_di_weave_window_0_start_reg.regValue);
		rtd_outl(DI_IM_DI_WEAVE_WINDOW_0_END_reg,im_di_weave_window_0_end_reg.regValue);
	}
	else
	{
		//VIP_DEBUG_PRINTF("\n    else else ..............= %d <<<<<\n",temp_cnt);
		di_im_di_weave_window_control_RBUS im_di_weave_window_control_reg;

		im_di_weave_window_control_reg.regValue = rtd_inl(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg);
		im_di_weave_window_control_reg.fixedwindowmode = 0;
		im_di_weave_window_control_reg.fixedwindow0 = 0;

		rtd_maskl(DI_IM_DI_CONTROL_reg, 0xfffffff3, 0x4);			//DI MA

		rtd_outl(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg,im_di_weave_window_control_reg.regValue);

		//VIP_DEBUG_PRINTF("\n    out    source_timing_index= %d <<<<<\n",source_timing_index);
		if((Scaler_InputSrcGetMainChType()) == _SRC_HDMI&&(source_timing_index == 5))
		{ // HDMI
			rtd_setbits(VGIP_VGIP_CHN1_CTRL_reg, _BIT18);
		}
		else if((Scaler_InputSrcGetMainChType()) == _SRC_CVBS&&(source_timing_index == 1))
		{
			rtd_clearbits(VGIP_VGIP_CHN1_CTRL_reg, _BIT18);
		}
	}
#endif
}

void scalerVIP_DI_MiddleWare_SMD_Apply()
{

	//Smart_Integration_Status.Vip_Source_Timing
	if (Smart_Integration_Status.DI_WIDTH>1000) //1080i
	{
		di_di_smd_gmvcoeff1_RBUS smd_gmvcoeff1_reg;
		smd_gmvcoeff1_reg.regValue= rtd_inl(DI_DI_SMD_GMVCoeff1_reg);

		di_di_smd_pan1_RBUS smd_pan1_reg;
		smd_pan1_reg.regValue=rtd_inl(DI_DI_SMD_Pan1_reg);


		if (smd_gmvcoeff1_reg.smd_gmv_ctr>2048)
			smd_pan1_reg.smd_hardware_pan_en=1;
		else
			smd_pan1_reg.smd_hardware_pan_en=0;

		rtd_outl(DI_DI_SMD_Pan1_reg, smd_pan1_reg.regValue);

	}

}

void scalerVIP_NR_MiddleWare_RTNR_k128_Apply(unsigned char enable)
{
#if 0  /*henry @ Mac5*/
	unsigned char th_multiple = 2;

	di_im_di_rtnr_new_sad_edge_th_1_RBUS			rtnr_new_sad_edge_th_1_reg;
	di_im_di_rtnr_new_sad_edge_th_2_RBUS			rtnr_new_sad_edge_th_2_reg;
	di_im_di_rtnr_new_sad_nonedge_th_1_RBUS		rtnr_new_sad_nonedge_th_1_reg;
	di_im_di_rtnr_new_sad_nonedge_th_2_RBUS		rtnr_new_sad_nonedge_th_2_reg;
	di_im_di_rtnr_new_sad_count_th_RBUS			rtnr_new_sad_count_th_reg;
	di_im_di_rtnr_new_edgetypediff_th_1_RBUS		rtnr_new_edgetypediff_th_1_reg;
	di_im_di_rtnr_new_edgetypediff_th_2_RBUS		rtnr_new_edgetypediff_th_2_reg;
	di_im_di_rtnr_k128_mode_RBUS					rtnr_k128_mode_reg;
	di_im_di_rtnr_new_sad_th_3_RBUS				rtnr_new_sad_th_3_reg;
	di_im_di_rtnr_new_sad_count_th_2_RBUS			rtnr_new_sad_count_th_2_reg;
	di_im_di_rtnr_new_sta_motion_th_0_RBUS			rtnr_new_sta_motion_th_0_reg;
	di_im_di_rtnr_new_sta_motion_th_1_RBUS			rtnr_new_sta_motion_th_1_reg;
	di_im_di_rtnr_new_sta_motion_th_3_RBUS			rtnr_new_sta_motion_th_3_reg;
	di_im_di_rtnr_new_sad_edge_slope_0_4_RBUS		rtnr_new_sad_edge_slope_0_4_reg;
	di_im_di_rtnr_new_sad_edge_slope_4_8_RBUS		rtnr_new_sad_edge_slope_4_8_reg;
	di_im_di_rtnr_new_sad_nonedge_slope_0_4_RBUS	rtnr_new_sad_nonedge_slope_0_4_reg;
	di_im_di_rtnr_new_sad_nonedge_slope_4_8_RBUS	rtnr_new_sad_nonedge_slope_4_8_reg;
	di_im_di_rtnr_new_sta_motion_slope_0_4_RBUS	rtnr_new_sta_motion_slope_0_4_reg;
	di_im_di_rtnr_new_sta_motion_slope_4_8_RBUS	rtnr_new_sta_motion_slope_4_8_reg;

	rtnr_new_sad_edge_th_1_reg.regValue = rtd_inl(DI_IM_DI_RTNR_NEW_SAD_EDGE_TH_1_reg);
	rtnr_new_sad_edge_th_2_reg.regValue = rtd_inl(DI_IM_DI_RTNR_NEW_SAD_EDGE_TH_2_reg);
	rtnr_new_sad_nonedge_th_1_reg.regValue = rtd_inl(DI_IM_DI_RTNR_NEW_SAD_NONEDGE_TH_1_reg);
	rtnr_new_sad_nonedge_th_2_reg.regValue = rtd_inl(DI_IM_DI_RTNR_NEW_SAD_NONEDGE_TH_2_reg);
	rtnr_new_sad_count_th_reg.regValue = rtd_inl(DI_IM_DI_RTNR_NEW_SAD_COUNT_TH_reg);
	rtnr_new_edgetypediff_th_1_reg.regValue = rtd_inl(DI_IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_1_reg);
	rtnr_new_edgetypediff_th_2_reg.regValue = rtd_inl(DI_IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_2_reg);

	rtnr_k128_mode_reg.regValue = rtd_inl(DI_IM_DI_RTNR_K128_MODE_reg);
	rtnr_new_sad_th_3_reg.regValue = rtd_inl(DI_IM_DI_RTNR_NEW_SAD_TH_3_reg);
	rtnr_new_sad_count_th_2_reg.regValue = rtd_inl(DI_IM_DI_RTNR_NEW_SAD_COUNT_TH_2_reg);
	rtnr_new_sta_motion_th_0_reg.regValue = rtd_inl(DI_IM_DI_RTNR_NEW_STA_MOTION_TH_0_reg);
	rtnr_new_sta_motion_th_1_reg.regValue = rtd_inl(DI_IM_DI_RTNR_NEW_STA_MOTION_TH_1_reg);
	rtnr_new_sta_motion_th_3_reg.regValue = rtd_inl(DI_IM_DI_RTNR_NEW_STA_MOTION_TH_3_reg);
	rtnr_new_sad_edge_slope_0_4_reg.regValue = rtd_inl(DI_IM_DI_RTNR_NEW_SAD_EDGE_SLOPE_0_4_reg);
	rtnr_new_sad_edge_slope_4_8_reg.regValue = rtd_inl(DI_IM_DI_RTNR_NEW_SAD_EDGE_SLOPE_4_8_reg);
	rtnr_new_sad_nonedge_slope_0_4_reg.regValue = rtd_inl(DI_IM_DI_RTNR_NEW_SAD_NONEDGE_SLOPE_0_4_reg);
	rtnr_new_sad_nonedge_slope_4_8_reg.regValue = rtd_inl(DI_IM_DI_RTNR_NEW_SAD_NONEDGE_SLOPE_4_8_reg);
	rtnr_new_sta_motion_slope_0_4_reg.regValue = rtd_inl(DI_IM_DI_RTNR_NEW_STA_MOTION_SLOPE_0_4_reg);
	rtnr_new_sta_motion_slope_4_8_reg.regValue = rtd_inl(DI_IM_DI_RTNR_NEW_STA_MOTION_SLOPE_4_8_reg);

	if (enable)
	{
		rtnr_k128_mode_reg.cp_temporal_k128_mode = 1;

		rtnr_new_sad_edge_slope_0_4_reg.rtnr_calculate_motion_sad_edge_th0_1_slope = (((rtnr_new_sad_edge_th_1_reg.rtnr_calculate_motion_sad_edge_th1<<th_multiple)-(rtnr_new_sad_th_3_reg.rtnr_calculate_motion_sad_edge_th0<<th_multiple))>>2); // >>2 mean ((>>4)<<2) for msb 6 bits
		rtnr_new_sad_edge_slope_0_4_reg.rtnr_calculate_motion_sad_edge_th1_2_slope = (((rtnr_new_sad_edge_th_1_reg.rtnr_calculate_motion_sad_edge_th2<<th_multiple)-(rtnr_new_sad_edge_th_1_reg.rtnr_calculate_motion_sad_edge_th1<<th_multiple))>>2);
		rtnr_new_sad_edge_slope_0_4_reg.rtnr_calculate_motion_sad_edge_th2_3_slope = (((rtnr_new_sad_edge_th_1_reg.rtnr_calculate_motion_sad_edge_th3<<th_multiple)-(rtnr_new_sad_edge_th_1_reg.rtnr_calculate_motion_sad_edge_th2<<th_multiple))>>2);
		rtnr_new_sad_edge_slope_0_4_reg.rtnr_calculate_motion_sad_edge_th3_4_slope = (((rtnr_new_sad_edge_th_1_reg.rtnr_calculate_motion_sad_edge_th4<<th_multiple)-(rtnr_new_sad_edge_th_1_reg.rtnr_calculate_motion_sad_edge_th3<<th_multiple))>>2);
		rtnr_new_sad_edge_slope_4_8_reg.rtnr_calculate_motion_sad_edge_th4_5_slope = (((rtnr_new_sad_edge_th_2_reg.rtnr_calculate_motion_sad_edge_th5<<th_multiple)-(rtnr_new_sad_edge_th_1_reg.rtnr_calculate_motion_sad_edge_th4<<th_multiple))>>2);
		rtnr_new_sad_edge_slope_4_8_reg.rtnr_calculate_motion_sad_edge_th5_6_slope = (((rtnr_new_sad_edge_th_2_reg.rtnr_calculate_motion_sad_edge_th6<<th_multiple)-(rtnr_new_sad_edge_th_2_reg.rtnr_calculate_motion_sad_edge_th5<<th_multiple))>>2);
		rtnr_new_sad_edge_slope_4_8_reg.rtnr_calculate_motion_sad_edge_th6_7_slope = (((rtnr_new_sad_edge_th_2_reg.rtnr_calculate_motion_sad_edge_th7<<th_multiple)-(rtnr_new_sad_edge_th_2_reg.rtnr_calculate_motion_sad_edge_th6<<th_multiple))>>2);
		rtnr_new_sad_edge_slope_4_8_reg.rtnr_calculate_motion_sad_edge_th7_8_slope = (((rtnr_new_sad_edge_th_2_reg.rtnr_calculate_motion_sad_edge_th8<<th_multiple)-(rtnr_new_sad_edge_th_2_reg.rtnr_calculate_motion_sad_edge_th7<<th_multiple))>>2);

		rtnr_new_sad_nonedge_slope_0_4_reg.rtnr_calculate_motion_sad_nonedge_th0_1_slope = (((rtnr_new_sad_nonedge_th_1_reg.rtnr_calculate_motion_sad_nonedge_th1<<th_multiple)-(rtnr_new_sad_th_3_reg.rtnr_calculate_motion_sad_nonedge_th0<<th_multiple))>>2);
		rtnr_new_sad_nonedge_slope_0_4_reg.rtnr_calculate_motion_sad_nonedge_th1_2_slope = (((rtnr_new_sad_nonedge_th_1_reg.rtnr_calculate_motion_sad_nonedge_th2<<th_multiple)-(rtnr_new_sad_nonedge_th_1_reg.rtnr_calculate_motion_sad_nonedge_th1<<th_multiple))>>2);
		rtnr_new_sad_nonedge_slope_0_4_reg.rtnr_calculate_motion_sad_nonedge_th2_3_slope = (((rtnr_new_sad_nonedge_th_1_reg.rtnr_calculate_motion_sad_nonedge_th3<<th_multiple)-(rtnr_new_sad_nonedge_th_1_reg.rtnr_calculate_motion_sad_nonedge_th2<<th_multiple))>>2);
		rtnr_new_sad_nonedge_slope_0_4_reg.rtnr_calculate_motion_sad_nonedge_th3_4_slope = (((rtnr_new_sad_nonedge_th_1_reg.rtnr_calculate_motion_sad_nonedge_th4<<th_multiple)-(rtnr_new_sad_nonedge_th_1_reg.rtnr_calculate_motion_sad_nonedge_th3<<th_multiple))>>2);
		rtnr_new_sad_nonedge_slope_4_8_reg.rtnr_calculate_motion_sad_nonedge_th4_5_slope = (((rtnr_new_sad_nonedge_th_2_reg.rtnr_calculate_motion_sad_nonedge_th5<<th_multiple)-(rtnr_new_sad_nonedge_th_1_reg.rtnr_calculate_motion_sad_nonedge_th4<<th_multiple))>>2);
		rtnr_new_sad_nonedge_slope_4_8_reg.rtnr_calculate_motion_sad_nonedge_th5_6_slope = (((rtnr_new_sad_nonedge_th_2_reg.rtnr_calculate_motion_sad_nonedge_th6<<th_multiple)-(rtnr_new_sad_nonedge_th_2_reg.rtnr_calculate_motion_sad_nonedge_th5<<th_multiple))>>2);
		rtnr_new_sad_nonedge_slope_4_8_reg.rtnr_calculate_motion_sad_nonedge_th6_7_slope = (((rtnr_new_sad_nonedge_th_2_reg.rtnr_calculate_motion_sad_nonedge_th7<<th_multiple)-(rtnr_new_sad_nonedge_th_2_reg.rtnr_calculate_motion_sad_nonedge_th6<<th_multiple))>>2);
		rtnr_new_sad_nonedge_slope_4_8_reg.rtnr_calculate_motion_sad_nonedge_th7_8_slope = (((rtnr_new_sad_nonedge_th_2_reg.rtnr_calculate_motion_sad_nonedge_th8<<th_multiple)-(rtnr_new_sad_nonedge_th_2_reg.rtnr_calculate_motion_sad_nonedge_th7<<th_multiple))>>2);

		rtnr_new_sta_motion_slope_0_4_reg.rtnr_statistic_motion_count_th0_1_slope = (((rtnr_new_sad_count_th_reg.rtnr_statistic_motion_count_th1<<th_multiple)-(rtnr_new_sad_count_th_2_reg.rtnr_statistic_motion_count_th0<<th_multiple))>>2);
		rtnr_new_sta_motion_slope_0_4_reg.rtnr_statistic_motion_count_th1_2_slope = (((rtnr_new_sad_count_th_reg.rtnr_statistic_motion_count_th2<<th_multiple)-(rtnr_new_sad_count_th_reg.rtnr_statistic_motion_count_th1<<th_multiple))>>2);
		rtnr_new_sta_motion_slope_0_4_reg.rtnr_statistic_motion_count_th2_3_slope = (((rtnr_new_sad_count_th_reg.rtnr_statistic_motion_count_th3<<th_multiple)-(rtnr_new_sad_count_th_reg.rtnr_statistic_motion_count_th2<<th_multiple))>>2);
		rtnr_new_sta_motion_slope_0_4_reg.rtnr_statistic_motion_count_th3_4_slope = (((rtnr_new_sad_count_th_reg.rtnr_statistic_motion_count_th4<<th_multiple)-(rtnr_new_sad_count_th_reg.rtnr_statistic_motion_count_th3<<th_multiple))>>2);
		rtnr_new_sta_motion_slope_4_8_reg.rtnr_statistic_motion_count_th4_5_slope = (((rtnr_new_sad_count_th_reg.rtnr_statistic_motion_count_th5<<th_multiple)-(rtnr_new_sad_count_th_reg.rtnr_statistic_motion_count_th4<<th_multiple))>>2);
		rtnr_new_sta_motion_slope_4_8_reg.rtnr_statistic_motion_count_th5_6_slope = (((rtnr_new_sad_count_th_reg.rtnr_statistic_motion_count_th6<<th_multiple)-(rtnr_new_sad_count_th_reg.rtnr_statistic_motion_count_th5<<th_multiple))>>2);
		rtnr_new_sta_motion_slope_4_8_reg.rtnr_statistic_motion_count_th6_7_slope = (((rtnr_new_sad_count_th_2_reg.rtnr_statistic_motion_count_th7<<th_multiple)-(rtnr_new_sad_count_th_reg.rtnr_statistic_motion_count_th6<<th_multiple))>>2);
		rtnr_new_sta_motion_slope_4_8_reg.rtnr_statistic_motion_count_th7_8_slope = (((rtnr_new_sad_count_th_2_reg.rtnr_statistic_motion_count_th8<<th_multiple)-(rtnr_new_sad_count_th_2_reg.rtnr_statistic_motion_count_th7<<th_multiple))>>2);

		rtd_outl(DI_IM_DI_RTNR_NEW_SAD_TH_3_reg, rtnr_new_sad_th_3_reg.regValue);
		rtd_outl(DI_IM_DI_RTNR_NEW_SAD_COUNT_TH_2_reg, rtnr_new_sad_count_th_2_reg.regValue);

		rtd_outl(DI_IM_DI_RTNR_NEW_SAD_EDGE_SLOPE_0_4_reg, rtnr_new_sad_edge_slope_0_4_reg.regValue);
		rtd_outl(DI_IM_DI_RTNR_NEW_SAD_EDGE_SLOPE_4_8_reg, rtnr_new_sad_edge_slope_4_8_reg.regValue);
		rtd_outl(DI_IM_DI_RTNR_NEW_SAD_NONEDGE_SLOPE_0_4_reg, rtnr_new_sad_nonedge_slope_0_4_reg.regValue);
		rtd_outl(DI_IM_DI_RTNR_NEW_SAD_NONEDGE_SLOPE_4_8_reg, rtnr_new_sad_nonedge_slope_4_8_reg.regValue);
		rtd_outl(DI_IM_DI_RTNR_NEW_STA_MOTION_SLOPE_0_4_reg, rtnr_new_sta_motion_slope_0_4_reg.regValue);
		rtd_outl(DI_IM_DI_RTNR_NEW_STA_MOTION_SLOPE_4_8_reg, rtnr_new_sta_motion_slope_4_8_reg.regValue);
	}
	else
	{
		rtnr_k128_mode_reg.cp_temporal_k128_mode = 0;
	}

	rtd_outl(DI_IM_DI_RTNR_K128_MODE_reg, rtnr_k128_mode_reg.regValue);
#endif
}

unsigned char scalerVIP_DI_HMC_Continue()
{
	short i = 0;
	unsigned char hmc_pass_total = 0, pass = 0, ratio = 0, no_pass = 0;
	di_im_di_hmc_pan_control_RBUS di_im_di_hmc_pan_control_reg;
	di_im_di_hmc_pan_control_reg.regValue = rtd_inl(DI_IM_DI_HMC_PAN_CONTROL_reg);

	Smart_Integration_Status.SCREEN_HMC_STATUS.Cur_Top5_Total = ((Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Rank[0]])>>2)+
																((Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Rank[1]])>>2)+
																((Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Rank[2]])>>2)+
																((Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Rank[3]])>>2)+
																((Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Rank[4]])>>2);

	pass = scalerVIP_DI_HMC_Rank_Check(4, 5, 0, 1); // current top 4 rank must in previous 1 frame of top 5 rank, and top 1 rank can't change

	if (Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Rank[0]] < 50)
		pass = 0;
	i = Smart_Integration_Status.SCREEN_HMC_STATUS.Cur_Top5_Total/20;
	if (i<100)
		i = 100;
	if (abs(Smart_Integration_Status.SCREEN_HMC_STATUS.Pre2_Top5_Total - Smart_Integration_Status.SCREEN_HMC_STATUS.Cur_Top5_Total) > i || abs(Smart_Integration_Status.SCREEN_HMC_STATUS.Pre3_Top5_Total - Smart_Integration_Status.SCREEN_HMC_STATUS.Pre_Top5_Total) > i)
		pass = 0;

	// check rank 10~20 is large then maybe problem
	ratio = (1920*540)/(Smart_Integration_Status.DI_HEIGHT*Smart_Integration_Status.DI_WIDTH);
	for (i=0; i<10; i++)
	{
		if ((Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Rank[9+i]]*ratio) > 2500)
			no_pass++;
	}
	if (no_pass > 7)
		pass = 0;

	if (scalerVIP_DI_HMC_LR_Check() == 0)
		pass = 0;

	if (Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram_flag == 1) // when use 2nd histogram, hmc don't check any condition
		pass = 1;

	// assign pass sequence
	for (i=HMC_PASS_COUNT-2; i>=0; i--)
		Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Sequence[i+1] = Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Sequence[i];
	Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Sequence[0] = pass;

	if (Smart_Integration_Status.SCREEN_HMC_STATUS.Show_Debug_MSG)
	{
		VIP_DEBUG_PRINTF("[SIS HMC] Top5 (%d, %d, %d, %d, %d)c: %d, p: %d, p2:%d, p3:%d, pass: %d\n",
			Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Rank[0], Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Rank[1],
			Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Rank[2], Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Rank[3],
			Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Rank[4], Smart_Integration_Status.SCREEN_HMC_STATUS.Cur_Top5_Total,
			Smart_Integration_Status.SCREEN_HMC_STATUS.Pre_Top5_Total, Smart_Integration_Status.SCREEN_HMC_STATUS.Pre2_Top5_Total,
			Smart_Integration_Status.SCREEN_HMC_STATUS.Pre3_Top5_Total, pass);
	}

	Smart_Integration_Status.SCREEN_HMC_STATUS.Pre3_Top5_Total = Smart_Integration_Status.SCREEN_HMC_STATUS.Pre2_Top5_Total;
	Smart_Integration_Status.SCREEN_HMC_STATUS.Pre2_Top5_Total = Smart_Integration_Status.SCREEN_HMC_STATUS.Pre_Top5_Total;
	Smart_Integration_Status.SCREEN_HMC_STATUS.Pre_Top5_Total = Smart_Integration_Status.SCREEN_HMC_STATUS.Cur_Top5_Total;

	for (i=0;i <HMC_PASS_COUNT; i++)
		hmc_pass_total += Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Sequence[i];

	Smart_Integration_Status.SCREEN_HMC_STATUS.Pass_Result_Total = hmc_pass_total;

	if (hmc_pass_total > 80)
		Smart_Integration_Status.SCREEN_ACTION_STATUS.HMC_detect = 1;
	else
		Smart_Integration_Status.SCREEN_ACTION_STATUS.HMC_detect = 0;

	return pass;
}

/*
fromRank : from Rank list of how many Top
inRank : in Rank list of how many Top
fixRank : how many top rank can't change
vsync_time : using how many time

fromRank must smaller/equal to inRank

ie. (3, 5, 1, 1) : Current Top 3 Rank have all in previous 1 frame of Top 5 Rank, and Top 1 rank can't change
*/
unsigned char scalerVIP_DI_HMC_Rank_Check(unsigned char fromRank, unsigned char inRank, unsigned char fixRank, unsigned char vsync_time)
{
	static unsigned char rank[30][HMC_BIN_COUNT]; //[T][Rank]
	unsigned char pass = 0, counter = 0, found = 0;
	int i, j, k, l;

	if (vsync_time == 0)
		return 0;

	if (vsync_time >= 29)
		vsync_time = 29;

	if (fromRank == 0)
		return 0;

	if (inRank == 0)
		return 0;

	if (fromRank >= 10)
		fromRank = 10;

	if (inRank >= 10)
		inRank = 10;

	if (fromRank > inRank)
		fromRank = inRank;

	for (i=0; i<HMC_BIN_COUNT; i++)
	{
		for (j=vsync_time-1; j>=0; j--)
		{
			rank[j+1][i] = rank[j][i];
		}
		rank[0][i] = Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Rank[i];
	}

	pass = 1;
	for (k=0; k<vsync_time; k++)
	{
		counter = 0;
		for (i=0; i<fromRank; i++)
		{
			found = 0;
			for (j=0; j<inRank; j++)
			{
				if (rank[0][i] == rank[k+1][j])
					found = 1;
			}

			if (found)
				counter++;
		}

		if (counter != fromRank)
			pass = 0;

		for (l=0; l<fixRank; l++)
		{
			if (rank[0][l] != rank[k+1][l])
				pass = 0;
		}

		if (Smart_Integration_Status.SCREEN_HMC_STATUS.Show_Debug_MSG)
			VIP_DEBUG_PRINTF("[SIS HMC]HMC Rank Check (vsync:%d): inRank:%d, fromRank:%d, counter:%d, Rank pass:%d\n", k, inRank, fromRank, counter, pass);
	}

	return pass;
}

unsigned char scalerVIP_DI_HMC_LR_Check()
{
	enum LR_FLAG {NO_RL, L_Flag, R_Flag};
	static unsigned char LR_check[360];
	unsigned char pass = 0, R_count = 0, L_count = 0, R_bin_count = 0, L_bin_count = 0;
	int i;

	di_im_di_hmc_pan_control_RBUS di_im_di_hmc_pan_control_reg;
	di_im_di_hmc_pan_control_reg.regValue = rtd_inl(DI_IM_DI_HMC_PAN_CONTROL_reg);

	if(di_im_di_hmc_pan_control_reg.pan_me_select_mv_hist ==0)
	{
		for (i=0; i<HMC_BIN_COUNT; i++)
		{
			if (i<16 && Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[i] > 100)
				R_bin_count++;

			if (i>16 && Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[i] > 100)
				L_bin_count++;
		}
	}

	// assign LR sequence
	for (i=360-2; i>=0; i--)
		LR_check[i+1] = LR_check[i];

	if (R_bin_count >= 3 && L_bin_count == 0)
		LR_check[0] = L_Flag;
	else if (L_bin_count >= 3 && R_bin_count == 0)
		LR_check[0] = R_Flag;
	else
		LR_check[0] = NO_RL;

	for (i=0; i<360-1; i++)
	{
		if (LR_check[i] == L_Flag && LR_check[i+1] == L_Flag)
			L_count++;
		else if (LR_check[i] == R_Flag && LR_check[i+1] == R_Flag)
			R_count++;
	}

	if (L_count >= 20 && R_count >= 20)
		pass = 0;
	else
		pass = 1;

	if (Smart_Integration_Status.SCREEN_HMC_STATUS.Show_Debug_MSG)
		VIP_DEBUG_PRINTF("[SIS HMC]HMC LR Check: R_bin: %d, L_bin: %d, L_count: %d, R_count: %d, pass: %d\n", R_bin_count, L_bin_count, L_count, R_count, pass);
	return pass;
}

void scalerVIP_DI_MOTION_StatusUpdate()
{
	short i=0, tmp=0;
	unsigned int total_pixel = 0, total_score_ratio = 0;
	unsigned char motion_level = 0;
	di_im_di_si_ma_total_fm_sum_RBUS ma_total_fm_sum_reg;
	di_im_di_si_ma_large_fm_pixel_RBUS ma_large_fm_pxl_reg;
	di_im_di_si_ma_large_fm_sum_RBUS ma_large_fm_sum_reg;

	total_pixel = Smart_Integration_Status.DI_WIDTH*Smart_Integration_Status.DI_HEIGHT;

	// assign status sequence
	for (i=MOTION_COUNT-2; i>=0; i--)
	{
		Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL_Sequence[i+1] = Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL_Sequence[i];
		Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_Sequence[i+1] = Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_Sequence[i];
		Smart_Integration_Status.SCREEN_MOTION_STATUS.Total_FM_SUM_Sequence[i+1] = Smart_Integration_Status.SCREEN_MOTION_STATUS.Total_FM_SUM_Sequence[i];
	}

	ma_total_fm_sum_reg.regValue = rtd_inl(DI_IM_DI_SI_MA_TOTAL_FM_SUM_reg);
	ma_large_fm_pxl_reg.regValue = rtd_inl(DI_IM_DI_SI_MA_LARGE_FM_PIXEL_reg);
	ma_large_fm_sum_reg.regValue = rtd_inl(DI_IM_DI_SI_MA_LARGE_FM_SUM_reg);

	Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL_Sequence[0] = ma_large_fm_pxl_reg.large_frame_motion_pixel;
	Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_Sequence[0] = ma_large_fm_sum_reg.large_frame_motion_sum;
	Smart_Integration_Status.SCREEN_MOTION_STATUS.Total_FM_SUM_Sequence[0] = ma_total_fm_sum_reg.total_frame_motion_sum;

	for (i=0; i<MOTION_COUNT; i++)
	{
		total_score_ratio += ((Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL_Sequence[i]*MOTION_SCALE)/(total_pixel==0?1:total_pixel)); // equalizer score to 0~1000
	}
	Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL = total_score_ratio/MOTION_COUNT;

	total_score_ratio = 0;
	for (i=0; i<MOTION_COUNT; i++)
	{
		tmp = (((Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_Sequence[i]*MOTION_SCALE)/(Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL_Sequence[i]+1))-(2*MOTION_SCALE));  // equalizer score to (2000~3000)-2000 = 0~1000
		if (tmp >= 0)
			total_score_ratio += tmp;
	}
	Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_ENERGY = total_score_ratio/MOTION_COUNT;

	total_score_ratio = 0;
	for (i=0; i<MOTION_COUNT; i++)
	{
		// blend mode 1 total pixels (total_fm_sum[0,1,2,3]-large_fm_sum[2,3] = [0,1])
		total_score_ratio += (((Smart_Integration_Status.SCREEN_MOTION_STATUS.Total_FM_SUM_Sequence[i]-Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_Sequence[i])*MOTION_SCALE)/(total_pixel==0?1:total_pixel)); // equalizer score to 0~1000
	}
	Smart_Integration_Status.SCREEN_MOTION_STATUS.Small_FM_PXL = total_score_ratio/MOTION_COUNT;
	Smart_Integration_Status.SCREEN_MOTION_STATUS.Zero_FM_PXL = (MOTION_SCALE-Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL-Smart_Integration_Status.SCREEN_MOTION_STATUS.Small_FM_PXL);

	if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL >= 300 && Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_ENERGY >= 490)
		motion_level = 48;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL >= 300 && Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_ENERGY >= 480)
		motion_level = 47;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL >= 300 && Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_ENERGY >= 470)
		motion_level = 46;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL >= 300 && Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_ENERGY >= 460)
		motion_level = 45;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL >= 300 && Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_ENERGY >= 440)
		motion_level = 44;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL >= 290 && Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_ENERGY >= 420)
		motion_level = 43;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL >= 280 && Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_ENERGY >= 400)
		motion_level = 42;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL >= 270 && Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_ENERGY >= 380)
		motion_level = 41;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL >= 260 && Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_ENERGY >= 360)
		motion_level = 40;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL >= 250 && Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_ENERGY >= 340)
		motion_level = 39;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL >= 240 && Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_ENERGY >= 320)
		motion_level = 38;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL >= 230 && Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_ENERGY >= 300)
		motion_level = 37;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL >= 220 && Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_ENERGY >= 280)
		motion_level = 36;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL >= 210 && Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_ENERGY >= 260)
		motion_level = 35;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL >= 200 && Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_ENERGY >= 240)
		motion_level = 34;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL >= 190 && Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_ENERGY >= 220)
		motion_level = 33;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL >= 180 && Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_ENERGY >= 200)
		motion_level = 32;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL >= 170 && Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_ENERGY >= 180)
		motion_level = 31;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL >= 160 && Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_ENERGY >= 160)
		motion_level = 30;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL >= 150 && Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_ENERGY >= 140)
		motion_level = 29;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL >= 140 && Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_ENERGY >= 120)
		motion_level = 28;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL >= 130 && Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_ENERGY >= 105)
		motion_level = 27;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL >= 120 && Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_ENERGY >= 90)
		motion_level = 26;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL >= 110 && Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_ENERGY >= 75)
		motion_level = 25;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL >= 100 && Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_ENERGY >= 60)
		motion_level = 24;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL >= 90 && Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_ENERGY >= 45)
		motion_level = 23;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL >= 80 && Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_ENERGY >= 30)
		motion_level = 22;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL >= 70 && Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_ENERGY >= 15)
		motion_level = 21;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL >= 60 && Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_ENERGY >= 0)
		motion_level = 20;

	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Zero_FM_PXL == 1000)
		motion_level = 1;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Zero_FM_PXL >= 995)
		motion_level = 2;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Zero_FM_PXL >= 990)
		motion_level = 3;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Zero_FM_PXL >= 980)
		motion_level = 4;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Zero_FM_PXL >= 960)
		motion_level = 5;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Zero_FM_PXL >= 940)
		motion_level = 6;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Zero_FM_PXL >= 920)
		motion_level = 7;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Zero_FM_PXL >= 900)
		motion_level = 8;

	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL < 2 && Smart_Integration_Status.SCREEN_MOTION_STATUS.Zero_FM_PXL >= 900)
		motion_level = 9;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL < 4 && Smart_Integration_Status.SCREEN_MOTION_STATUS.Zero_FM_PXL >= 890)
		motion_level = 10;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL < 6 && Smart_Integration_Status.SCREEN_MOTION_STATUS.Zero_FM_PXL >= 880)
		motion_level = 11;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL < 8 && Smart_Integration_Status.SCREEN_MOTION_STATUS.Zero_FM_PXL >= 865)
		motion_level = 12;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL < 10 && Smart_Integration_Status.SCREEN_MOTION_STATUS.Zero_FM_PXL >= 850)
		motion_level = 13;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL < 15 && (Smart_Integration_Status.SCREEN_MOTION_STATUS.Zero_FM_PXL >= 800 || Smart_Integration_Status.SCREEN_MOTION_STATUS.Small_FM_PXL >= 450))
		motion_level = 14;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL < 20 && (Smart_Integration_Status.SCREEN_MOTION_STATUS.Zero_FM_PXL >= 750 || Smart_Integration_Status.SCREEN_MOTION_STATUS.Small_FM_PXL >= 430))
		motion_level = 15;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL < 30 && (Smart_Integration_Status.SCREEN_MOTION_STATUS.Zero_FM_PXL >= 700 || Smart_Integration_Status.SCREEN_MOTION_STATUS.Small_FM_PXL >= 410))
		motion_level = 16;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL < 40 && (Smart_Integration_Status.SCREEN_MOTION_STATUS.Zero_FM_PXL >= 650 || Smart_Integration_Status.SCREEN_MOTION_STATUS.Small_FM_PXL >= 390))
		motion_level = 17;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL < 50 && (Smart_Integration_Status.SCREEN_MOTION_STATUS.Zero_FM_PXL >= 600 || Smart_Integration_Status.SCREEN_MOTION_STATUS.Small_FM_PXL >= 370))
		motion_level = 18;
	else if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL < 60 && (Smart_Integration_Status.SCREEN_MOTION_STATUS.Zero_FM_PXL >= 550 || Smart_Integration_Status.SCREEN_MOTION_STATUS.Small_FM_PXL >= 350))
		motion_level = 19;
	else	 // debug, check unknown info.
		motion_level = 0;

	for (i=MOTION_COUNT-2; i>=0; i--)
	{
		Smart_Integration_Status.SCREEN_MOTION_STATUS.MOTION_LEVEL_Sequence[i+1] = Smart_Integration_Status.SCREEN_MOTION_STATUS.MOTION_LEVEL_Sequence[i];
	}
	Smart_Integration_Status.SCREEN_MOTION_STATUS.MOTION_LEVEL_Sequence[0] = motion_level;

	total_score_ratio = 0;
	for (i=0; i<MOTION_COUNT; i++)
	{
		total_score_ratio += Smart_Integration_Status.SCREEN_MOTION_STATUS.MOTION_LEVEL_Sequence[i];
	}
	Smart_Integration_Status.SCREEN_MOTION_STATUS.MOTION_LEVEL = total_score_ratio/MOTION_COUNT;

	if (Smart_Integration_Status.SCREEN_MOTION_STATUS.Show_Debug_MSG)
	{
		VIP_DEBUG_PRINTF("[SIS MOTION] LV: %d/48 [large: %d[eg: %d], small: %d, zero: %d]/1000\n", Smart_Integration_Status.SCREEN_MOTION_STATUS.MOTION_LEVEL,
		Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_PXL, Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_ENERGY,
		Smart_Integration_Status.SCREEN_MOTION_STATUS.Small_FM_PXL, Smart_Integration_Status.SCREEN_MOTION_STATUS.Zero_FM_PXL);
	}
}

void scalerVIP_DI_HMC_StatusUpdate()
{
	unsigned int i, j, m;
	unsigned short sort_array[HMC_BIN_COUNT], tmp_value, tmp_index;

	di_im_di_pan_detection_statistic_1_RBUS im_di_pan_detection_statistic_1_reg;
	di_im_di_pan_detection_statistic_2_RBUS im_di_pan_detection_statistic_2_reg;
	di_im_di_pan_detection_statistic_3_RBUS im_di_pan_detection_statistic_3_reg;
	di_im_di_pan_detection_statistic_4_RBUS im_di_pan_detection_statistic_4_reg;
	di_im_di_pan_detection_statistic_5_RBUS im_di_pan_detection_statistic_5_reg;
	di_im_di_pan_detection_statistic_6_RBUS im_di_pan_detection_statistic_6_reg;
	di_im_di_pan_detection_statistic_7_RBUS im_di_pan_detection_statistic_7_reg;
	di_im_di_pan_detection_statistic_8_RBUS im_di_pan_detection_statistic_8_reg;
	di_im_di_pan_detection_statistic_9_RBUS im_di_pan_detection_statistic_9_reg;
	di_im_di_pan_detection_statistic_10_RBUS im_di_pan_detection_statistic_10_reg;
	di_im_di_pan_detection_statistic_11_RBUS im_di_pan_detection_statistic_11_reg;
	di_im_di_pan_detection_statistic_12_RBUS im_di_pan_detection_statistic_12_reg;
	di_im_di_pan_detection_statistic_13_RBUS im_di_pan_detection_statistic_13_reg;
	di_im_di_pan_detection_statistic_14_RBUS im_di_pan_detection_statistic_14_reg;
	di_im_di_pan_detection_statistic_15_RBUS im_di_pan_detection_statistic_15_reg;
	di_im_di_pan_detection_statistic_16_RBUS im_di_pan_detection_statistic_16_reg;
	di_im_di_pan_detection_statistic_17_RBUS im_di_pan_detection_statistic_17_reg;
	di_im_di_hmc_pan_control_RBUS di_im_di_hmc_pan_control_reg;

	im_di_pan_detection_statistic_1_reg.regValue = rtd_inl(DI_IM_DI_PAN_DETECTION_STATISTIC_1_reg);
	im_di_pan_detection_statistic_2_reg.regValue = rtd_inl(DI_IM_DI_PAN_DETECTION_STATISTIC_2_reg);
	im_di_pan_detection_statistic_3_reg.regValue = rtd_inl(DI_IM_DI_PAN_DETECTION_STATISTIC_3_reg);
	im_di_pan_detection_statistic_4_reg.regValue = rtd_inl(DI_IM_DI_PAN_DETECTION_STATISTIC_4_reg);
	im_di_pan_detection_statistic_5_reg.regValue = rtd_inl(DI_IM_DI_PAN_DETECTION_STATISTIC_5_reg);
	im_di_pan_detection_statistic_6_reg.regValue = rtd_inl(DI_IM_DI_PAN_DETECTION_STATISTIC_6_reg);
	im_di_pan_detection_statistic_7_reg.regValue = rtd_inl(DI_IM_DI_PAN_DETECTION_STATISTIC_7_reg);
	im_di_pan_detection_statistic_8_reg.regValue = rtd_inl(DI_IM_DI_PAN_DETECTION_STATISTIC_8_reg);
	im_di_pan_detection_statistic_9_reg.regValue = rtd_inl(DI_IM_DI_PAN_DETECTION_STATISTIC_9_reg);
	im_di_pan_detection_statistic_10_reg.regValue = rtd_inl(DI_IM_DI_PAN_DETECTION_STATISTIC_10_reg);
	im_di_pan_detection_statistic_11_reg.regValue = rtd_inl(DI_IM_DI_PAN_DETECTION_STATISTIC_11_reg);
	im_di_pan_detection_statistic_12_reg.regValue = rtd_inl(DI_IM_DI_PAN_DETECTION_STATISTIC_12_reg);
	im_di_pan_detection_statistic_13_reg.regValue = rtd_inl(DI_IM_DI_PAN_DETECTION_STATISTIC_13_reg);
	im_di_pan_detection_statistic_14_reg.regValue = rtd_inl(DI_IM_DI_PAN_DETECTION_STATISTIC_14_reg);
	im_di_pan_detection_statistic_15_reg.regValue = rtd_inl(DI_IM_DI_PAN_DETECTION_STATISTIC_15_reg);
	im_di_pan_detection_statistic_16_reg.regValue = rtd_inl(DI_IM_DI_PAN_DETECTION_STATISTIC_16_reg);
	im_di_pan_detection_statistic_17_reg.regValue = rtd_inl(DI_IM_DI_PAN_DETECTION_STATISTIC_17_reg);
	di_im_di_hmc_pan_control_reg.regValue = rtd_inl(DI_IM_DI_HMC_PAN_CONTROL_reg);

	Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[0] = im_di_pan_detection_statistic_9_reg.hmc_r16_pixelsum;
	Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[1] = im_di_pan_detection_statistic_9_reg.hmc_r15_pixelsum;
	Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[2] = im_di_pan_detection_statistic_10_reg.hmc_r14_pixelsum;
	Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[3] = im_di_pan_detection_statistic_10_reg.hmc_r13_pixelsum;
	Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[4] = im_di_pan_detection_statistic_11_reg.hmc_r12_pixelsum;
	Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[5] = im_di_pan_detection_statistic_11_reg.hmc_r11_pixelsum;
	Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[6] = im_di_pan_detection_statistic_12_reg.hmc_r10_pixelsum;
	Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[7] = im_di_pan_detection_statistic_12_reg.hmc_r9_pixelsum;
	Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[8] = im_di_pan_detection_statistic_13_reg.hmc_r8_pixelsum;
	Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[9] = im_di_pan_detection_statistic_1_reg.hmc_r7_pixelsum;
	Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[10] = im_di_pan_detection_statistic_1_reg.hmc_r6_pixelsum;
	Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[11] = im_di_pan_detection_statistic_2_reg.hmc_r5_pixelsum;
	Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[12] = im_di_pan_detection_statistic_2_reg.hmc_r4_pixelsum;
	Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[13] = im_di_pan_detection_statistic_3_reg.hmc_r3_pixelsum;
	Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[14] = im_di_pan_detection_statistic_3_reg.hmc_r2_pixelsum;
	Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[15] = im_di_pan_detection_statistic_4_reg.hmc_r1_pixelsum;
	Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[16] = im_di_pan_detection_statistic_4_reg.hmc_c0_pixelsum;
	Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[17] = im_di_pan_detection_statistic_5_reg.hmc_l1_pixelsum;
	Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[18] = im_di_pan_detection_statistic_5_reg.hmc_l2_pixelsum;
	Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[19] = im_di_pan_detection_statistic_6_reg.hmc_l3_pixelsum;
	Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[20] = im_di_pan_detection_statistic_6_reg.hmc_l4_pixelsum;
	Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[21] = im_di_pan_detection_statistic_7_reg.hmc_l5_pixelsum;
	Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[22] = im_di_pan_detection_statistic_7_reg.hmc_l6_pixelsum;
	Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[23] = im_di_pan_detection_statistic_8_reg.hmc_l7_pixelsum;
	Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[24] = im_di_pan_detection_statistic_13_reg.hmc_l8_pixelsum;
	Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[25] = im_di_pan_detection_statistic_14_reg.hmc_l9_pixelsum;
	Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[26] = im_di_pan_detection_statistic_14_reg.hmc_l10_pixelsum;
	Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[27] = im_di_pan_detection_statistic_15_reg.hmc_l11_pixelsum;
	Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[28] = im_di_pan_detection_statistic_15_reg.hmc_l12_pixelsum;
	Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[29] = im_di_pan_detection_statistic_16_reg.hmc_l13_pixelsum;
	Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[30] = im_di_pan_detection_statistic_16_reg.hmc_l14_pixelsum;
	Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[31] = im_di_pan_detection_statistic_17_reg.hmc_l15_pixelsum;
	Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[32] = im_di_pan_detection_statistic_17_reg.hmc_l16_pixelsum;

	if(di_im_di_hmc_pan_control_reg.pan_me_select_mv_hist ==0)
	{
		for (i=0; i<HMC_BIN_COUNT; i++)
		{
			sort_array[i] = Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[i];
			if (i == 16)
				sort_array[i] = 0; // zero mv don't sort
		}

		// sort
		for (i=0; i<HMC_BIN_COUNT-1; i++)
		{
			m = i;
			for (j=i+1; j<HMC_BIN_COUNT; j++)
			{
				if (sort_array[j] > sort_array[m])
					m = j;
			}

			//swap
			if (i != m)
			{
				tmp_value = sort_array[i];
				sort_array[i] = sort_array[m];
				sort_array[m] = tmp_value;

				tmp_index = i;
				Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Rank[i] = m;
				Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Rank[m] = tmp_index;
			}
		}
	}
	else
	{
		for (i=0; i<HMC_BIN_COUNT; i++)
		{
			sort_array[i] = Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[i];
			if (i == 16)
				sort_array[i] = 0xffff; // zero mv don't sort
		}

		// sort
		for (i=0; i<HMC_BIN_COUNT-1; i++)
		{
			m = i;
			for (j=i+1; j<HMC_BIN_COUNT; j++)
			{
				if (sort_array[j] < sort_array[m])
					m = j;
			}

			//swap
			if (i != m)
			{
				tmp_value = sort_array[i];
				sort_array[i] = sort_array[m];
				sort_array[m] = tmp_value;

				tmp_index = i;
				Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Rank[i] = m;
				Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Rank[m] = tmp_index;
			}
		}
	}
}

void scalerVIP_DI_PAN_HistSwitch()
{
	static unsigned int switchCnt=0;
	di_im_di_hmc_pan_control_RBUS di_im_di_hmc_pan_control_reg;
	di_im_di_hmc_pan_control_reg.regValue = rtd_inl(DI_IM_DI_HMC_PAN_CONTROL_reg);

	di_im_di_hmc_pan_dummy_2_RBUS di_im_di_hmc_pan_dummy_2_reg;
	di_im_di_hmc_pan_dummy_2_reg.regValue = rtd_inl(DI_IM_DI_HMC_PAN_DUMMY_2_reg);

	Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram_flag_pre = Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram_flag;

	if (Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram_flag == 0 && Smart_Integration_Status.SCREEN_ACTION_STATUS.PAN_detect_str == 1)
	{
		Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram_flag = 1;
	}
	else if (Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram_flag == 1 && Smart_Integration_Status.SCREEN_ACTION_STATUS.PAN_detect_str == 0 && switchCnt>di_im_di_hmc_pan_dummy_2_reg.panConti+10)
	//else if (Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram_flag == 1 && Smart_Integration_Status.SCREEN_ACTION_STATUS.PAN_detect_str == 0 && switchCnt>(di_im_di_hmc_pan_dummy_2_reg.dummy18024680_31_0 & 0xff0000)+10)
	{
		Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram_flag = 0;
	}

	if(Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram_flag == 0)
		switchCnt=0;
	else
		//switchCnt=(switchCnt>=((di_im_di_hmc_pan_dummy_2_reg.dummy18024680_31_0 & 0xff0000)+20))? ((di_im_di_hmc_pan_dummy_2_reg.dummy18024680_31_0 & 0xff0000)+20):switchCnt+1;
		switchCnt=(switchCnt>=(di_im_di_hmc_pan_dummy_2_reg.panConti+20))? (di_im_di_hmc_pan_dummy_2_reg.panConti+20):switchCnt+1;

	di_im_di_hmc_pan_control_reg.pan_me_select_mv_hist = Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram_flag;

	rtd_outl(DI_IM_DI_HMC_PAN_CONTROL_reg, di_im_di_hmc_pan_control_reg.regValue);

	if (Smart_Integration_Status.SCREEN_HMC_STATUS.Show_Debug_MSG)
	{
		VIP_DEBUG_PRINTF("[SIS HMC] Hist_flag: %d, switchCnt: %d\n", Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram_flag, switchCnt);
	}
}

void scalerVIP_DI_PAN_StatusUpdate()
{
	if(Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram_flag_pre != Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram_flag)
		return;

	unsigned int temp = 0, MaxValue_Pan= 0, SecondMaxValue_Pan = 0, Sum_Pan_Count =0, Pan_Count_Ratio = 0;
	unsigned char MAX_Pan_index = 0, SecondMax_Pan_index = 0, i=0;

	//condiction defined
	static unsigned int Pan_ratio_th = 50;
	unsigned char Pan_counter_th_str = 5;//,Pan_counter_th_upbound = 10;
	unsigned char Pan_counter_th = 5;//,Pan_counter_th_upbound = 10;

	//	chris added from Mac3 - 20140924
	static unsigned char pan_debounce_str=0;
	static unsigned char pan_debounce=0;

	unsigned char pan_mv_loc=0,restIdx=0,pass=0;
	unsigned int diffMinThd=0,restIdxThd=0,diffMaxMin=0;
	unsigned char reg_pan_debounce_str=10,reg_pan_debounce=20;

	int sort_array[HMC_BIN_COUNT];
	unsigned char sort_array_index[HMC_BIN_COUNT];

	di_im_di_hmc_pan_control_RBUS di_im_di_hmc_pan_control_reg;
	di_im_di_hmc_pan_dummy_1_RBUS di_im_di_hmc_pan_dummy_1_reg;
	di_im_di_hmc_pan_dummy_2_RBUS di_im_di_hmc_pan_dummy_2_reg;
	di_im_di_hmc_pan_dummy_3_RBUS di_im_di_hmc_pan_dummy_3_reg;
	di_im_di_hmc_pan_control_reg.regValue = rtd_inl(DI_IM_DI_HMC_PAN_CONTROL_reg);
	di_im_di_hmc_pan_dummy_1_reg.regValue = rtd_inl(DI_IM_DI_HMC_PAN_DUMMY_1_reg);
	di_im_di_hmc_pan_dummy_2_reg.regValue = rtd_inl(DI_IM_DI_HMC_PAN_DUMMY_2_reg);
	di_im_di_hmc_pan_dummy_3_reg.regValue = rtd_inl(DI_IM_DI_HMC_PAN_DUMMY_3_reg);

	diffMinThd = di_im_di_hmc_pan_dummy_1_reg.diffMinThd;
	restIdx = di_im_di_hmc_pan_dummy_1_reg.restIdx;
	restIdxThd = di_im_di_hmc_pan_dummy_1_reg.restIdxThd;
	diffMaxMin = di_im_di_hmc_pan_dummy_2_reg.diffMaxMin;
	Pan_counter_th_str = di_im_di_hmc_pan_dummy_2_reg.panConti_str;
	Pan_counter_th = di_im_di_hmc_pan_dummy_2_reg.panConti;
	reg_pan_debounce_str = di_im_di_hmc_pan_dummy_3_reg.panDeb_str;
	reg_pan_debounce = di_im_di_hmc_pan_dummy_3_reg.panDeb;
	/*
	reg_pan_debounce_str = di_im_di_hmc_pan_dummy_3_reg.dummy18024684_31_0 & 0x0000ff00;
	reg_pan_debounce = di_im_di_hmc_pan_dummy_3_reg.dummy18024684_31_0 & 0x000000ff;
	reg_pan_debounce_str = 20;
	reg_pan_debounce = 20;
	diffMinThd = di_im_di_hmc_pan_dummy_1_reg.dummy1802467c_31_0 & 0x3ff;
	restIdx = di_im_di_hmc_pan_dummy_1_reg.dummy1802467c_31_0 & 0xfc00;
	restIdxThd = di_im_di_hmc_pan_dummy_1_reg.dummy1802467c_31_0 & 0xffff0000;
	diffMaxMin = di_im_di_hmc_pan_dummy_2_reg.dummy18024680_31_0 & 0xffff;
	Pan_counter_th = di_im_di_hmc_pan_dummy_2_reg.dummy18024680_31_0 & 0xff0000;
	*/
	restIdx = (restIdx>=HMC_BIN_COUNT-1)? HMC_BIN_COUNT-1:restIdx;

	if(di_im_di_hmc_pan_control_reg.pan_me_select_mv_hist ==0)
	{
		//	original decision
		for(i=0; i<HMC_BIN_COUNT; i++)
		{
			temp = Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[i]; // must confirm scalerVIP_DI_HMC_StatusUpdate() processing correctly

			Sum_Pan_Count =Sum_Pan_Count + temp;

			if(MaxValue_Pan <= temp)
			{
				SecondMaxValue_Pan = MaxValue_Pan;
				SecondMax_Pan_index = MAX_Pan_index;
				MaxValue_Pan = temp;
				MAX_Pan_index = i;
			}
			else if(SecondMaxValue_Pan <= temp)
			{
				SecondMaxValue_Pan = temp;
				SecondMax_Pan_index = i;
			}
		}
		pan_mv_loc = MAX_Pan_index;

		if(Sum_Pan_Count!=0)
			Pan_Count_Ratio = (MaxValue_Pan*100)/Sum_Pan_Count ;

		if(MAX_Pan_index!=16)
		{
			if(Pan_Count_Ratio>=Pan_ratio_th)
			{
				pass = 1;
				//Pan_ratio_counter = (Pan_ratio_counter>=Pan_counter_th_upbound)?Pan_counter_th_upbound:(Pan_ratio_counter+1);
			}
			else
			{
				pass = 0;
				//Pan_ratio_counter = (Pan_ratio_counter<=0)?0:(Pan_ratio_counter-1);
			}
		}
		else
		{
			pass = 0;
			//Pan_ratio_counter = (Pan_ratio_counter<=0)?0:(Pan_ratio_counter-1);
		}

		/*
		if(Pan_ratio_counter > Pan_counter_th)
		{
			Smart_Integration_Status.SCREEN_ACTION_STATUS.PAN_detect_str = 1;
			Pan_ratio_th = 40;
		}
		else
		{
			Smart_Integration_Status.SCREEN_ACTION_STATUS.PAN_detect_str = 0;
			Pan_ratio_th =70;
		}
		*/

		/* rock_rau 20150923 [special case] Q-tek pan Horizontal DI need trend 3D setting*/
		/* for Q-tek monoscope pan pattern*/
		if(Sum_Pan_Count != 0)
		{
			if((MAX_Pan_index==0 && SecondMax_Pan_index==1) || (MAX_Pan_index==32 && SecondMax_Pan_index==31)) {
				Smart_Integration_Status.SCREEN_HPAN_STATUS.Pen_special_case = (((MaxValue_Pan+SecondMaxValue_Pan)*100)/Sum_Pan_Count);
			} else {
				Smart_Integration_Status.SCREEN_HPAN_STATUS.Pen_special_case = 0;
			}
		}
	}
	else
	{
		for(i=0;i<HMC_BIN_COUNT;i++)
		{
			sort_array[i]=Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram[i];
			sort_array_index[i] = i;
			// henry 161104
			Sum_Pan_Count =Sum_Pan_Count + sort_array[i];
		}

		// henry 161104
		int avg_Pan_count = Sum_Pan_Count/HMC_BIN_COUNT;
		int tmp_var = 0, var_Pan_count = 0;
		for(i=0;i<HMC_BIN_COUNT;i++)
		{
			tmp_var += abs(sort_array[i]-avg_Pan_count);
		}
		var_Pan_count = tmp_var/HMC_BIN_COUNT;
		diffMinThd = (2*avg_Pan_count - 7*var_Pan_count) >> 1;

		// DOS case setting
		_system_setting_info* system_info_structure_table = NULL;
		system_info_structure_table = scaler_GetShare_Memory_system_setting_info_Struct();
		if( system_info_structure_table == NULL )
		{
			if( MA_print_count%360 == 0 )
				ROSPrintf("[%s] share Memory PQ data ERROR, system_info = %x\n", system_info_structure_table);
			return;
		}

		switch( RPC_system_info_structure_table->VIP_source )
		{
			case VIP_QUALITY_CVBS_NTSC:
			case VIP_QUALITY_CVBS_PAL:
			case VIP_QUALITY_HDMI_480I:
			case VIP_QUALITY_YPbPr_480I:
			case VIP_QUALITY_HDMI_576I:
			case VIP_QUALITY_YPbPr_576I:
				if( DynamicOptimizeSystem[7] == 1 || DynamicOptimizeSystem[75] == 1 )
					diffMinThd = 1023;
				break;
			default:
				break;
		}

		// Write information register value protection
		di_im_di_hmc_pan_dummy_1_reg.diffMinThd = (diffMinThd < 0)? 0 : ((diffMinThd>1023)? 1023 : diffMinThd);
		rtd_outl(DI_IM_DI_HMC_PAN_DUMMY_1_reg, di_im_di_hmc_pan_dummy_1_reg.regValue);

		diffMaxMin = avg_Pan_count;
		di_im_di_hmc_pan_dummy_2_reg.diffMaxMin = diffMaxMin;
		rtd_outl(DI_IM_DI_HMC_PAN_DUMMY_2_reg, di_im_di_hmc_pan_dummy_2_reg.regValue);
		// end henry

		int j,m,tmp,tmp_loc;
		for (i=0; i<HMC_BIN_COUNT-1; i++)
		{
			m = i;
			for (j=i+1; j<HMC_BIN_COUNT; j++)
			{
				if (sort_array[j] < sort_array[m])
					m = j;
			}
			//swap
			if (i != m)
			{
				tmp = sort_array[i];
				sort_array[i] = sort_array[m];
				sort_array[m] = tmp;
				tmp_loc = sort_array_index[i];
				sort_array_index[i] = sort_array_index[m];
				sort_array_index[m] = tmp_loc;
			}
		}
		pan_mv_loc = sort_array_index[0];

		if(((sort_array[0] < diffMinThd && sort_array[restIdx] > restIdxThd) ||
		//	modified by chris for a moving windows on a still pic (pattern gen) - start
		(((sort_array[0] * 15) < sort_array[1]*10 && (sort_array[0] * 24) < sort_array[2]*10 && (sort_array[0] * 3) < sort_array[3])
		&& (sort_array[0] < diffMinThd+200))) // 960 condition
			/*(((sort_array[0] * 1.5) < sort_array[1] && (sort_array[0] * 2.4) < sort_array[2] && (sort_array[0] * 3.0) < sort_array[3]) // 960 condition
			) )*/
		//	&& sort_array_index[1] !=16
		//	&& sort_array_index[2] !=16
		//	modified by chris for a moving windows on a still pic (pattern gen) - end
			&& sort_array_index[0] !=16
			&& (abs(sort_array[0]-sort_array[32]) > diffMaxMin)
		)
			pass = 1;
		else
			pass = 0;

		if(pan_mv_loc==16)
			pass = 0;
	}

	di_im_di_hmc_pan_control_reg.pan_me_select_mv_hist = Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram_flag;

	rtd_outl(DI_IM_DI_HMC_PAN_CONTROL_reg, di_im_di_hmc_pan_control_reg.regValue);

	if(pan_mv_loc<0)
		pan_mv_loc=0;
	if(pan_mv_loc>HMC_BIN_COUNT-1)
		pan_mv_loc = HMC_BIN_COUNT-1;

	//	Update to SCREEN_HPAN_STATUS
	Smart_Integration_Status.SCREEN_HPAN_STATUS.Pan_det = pass;
	Smart_Integration_Status.SCREEN_HPAN_STATUS.Pan_mv = pan_mv_loc;

	// assign pass sequence
	for (i=HPAN_PASS_COUNT-1; i>0; i--)
	{
		Smart_Integration_Status.SCREEN_HPAN_STATUS.Pass_Result_Sequence[i] = Smart_Integration_Status.SCREEN_HPAN_STATUS.Pass_Result_Sequence[i-1];
		Smart_Integration_Status.SCREEN_HPAN_STATUS.Mv_Result_Sequence[i] = Smart_Integration_Status.SCREEN_HPAN_STATUS.Mv_Result_Sequence[i-1];
	}
	Smart_Integration_Status.SCREEN_HPAN_STATUS.Pass_Result_Sequence[0] = pass;
	Smart_Integration_Status.SCREEN_HPAN_STATUS.Mv_Result_Sequence[0] = pan_mv_loc;

	//	Update to SCREEN_ACTION_STATUS
	unsigned char hPanCnt_str=0;		//	for pan compensation
	Pan_counter_th_str = (Pan_counter_th_str>(HPAN_PASS_COUNT-2))? (HPAN_PASS_COUNT-2):Pan_counter_th_str;

	for (i=0; i<=Pan_counter_th_str; i++)
	{
		if((Smart_Integration_Status.SCREEN_HPAN_STATUS.Pass_Result_Sequence[i] == 1) &&
		(Smart_Integration_Status.SCREEN_HPAN_STATUS.Mv_Result_Sequence[i] == Smart_Integration_Status.SCREEN_HPAN_STATUS.Mv_Result_Sequence[i+1]))//][MIN(i+1,HPAN_PASS_COUNT-1)]))
		{
			hPanCnt_str++;
		}
	}

	/*unsigned char pan_exit_flg=0;
	if((abs(Smart_Integration_Status.SCREEN_HPAN_STATUS.Mv_Result_Sequence[0]-Smart_Integration_Status.SCREEN_HPAN_STATUS.Mv_Result_Sequence[1])>=8) ||
	())
		pan_exit_flg=1;

	if(pan_exit_flg)
	{
	}
	else */if(hPanCnt_str == (Pan_counter_th_str+1))
	{
		Smart_Integration_Status.SCREEN_ACTION_STATUS.PAN_detect_str = 1;
		Pan_ratio_th = 40;
		pan_debounce_str = reg_pan_debounce_str;
	}
	else
	{
		pan_debounce_str = (pan_debounce_str<=0)? 0: pan_debounce_str-1;
		if(pan_debounce_str==0)
		{
			Smart_Integration_Status.SCREEN_ACTION_STATUS.PAN_detect_str = 0;
			Pan_ratio_th = 50;
		}
	}


	unsigned char hPanCnt=0;		//	for HMCNR stable
	Pan_counter_th = (Pan_counter_th>(HPAN_PASS_COUNT-1))? (HPAN_PASS_COUNT-1):Pan_counter_th;
	for (i=0; i<=Pan_counter_th; i++)
	{
		if(Smart_Integration_Status.SCREEN_HPAN_STATUS.Pass_Result_Sequence[i] == 1)
		{
			hPanCnt++;
		}
	}

	if(hPanCnt == (Pan_counter_th+1))
	{
		Smart_Integration_Status.SCREEN_ACTION_STATUS.PAN_detect = 1;
		pan_debounce = reg_pan_debounce;
	}
	else
	{
		pan_debounce = (pan_debounce<=0)? 0: pan_debounce-1;
		if(pan_debounce==0)
		{
			Smart_Integration_Status.SCREEN_ACTION_STATUS.PAN_detect = 0;
			Pan_ratio_th = 50;
		}
	}

	if (Smart_Integration_Status.SCREEN_HPAN_STATUS.Show_Debug_MSG)
	{
		if (Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram_flag == 0)
		{
			VIP_DEBUG_PRINTF("[SIS PAN 1] max: %d:%d, second: %d:%d, ratio: %d, pass : %d\n", MaxValue_Pan, MAX_Pan_index, SecondMaxValue_Pan, SecondMax_Pan_index, Pan_Count_Ratio, pass);
		}
		else
		{
			VIP_DEBUG_PRINTF("[SIS PAN 2] min:%d %d,rest:%d %d, diff:%d %d, pass : %d\n", sort_array[0],diffMinThd,sort_array[restIdx],restIdxThd,abs(sort_array[0]-sort_array[32]),diffMaxMin, pass);
		}
		VIP_DEBUG_PRINTF("[SIS PAN] mv:%d HstFlg:%d, Pan det:%d %d Deb:%d %d\n",
			HMC_BIN_COUNT -(Smart_Integration_Status.SCREEN_HPAN_STATUS.Pan_mv),
			Smart_Integration_Status.SCREEN_HMC_STATUS.BIN_Histogram_flag,
			Smart_Integration_Status.SCREEN_ACTION_STATUS.PAN_detect_str,
			Smart_Integration_Status.SCREEN_ACTION_STATUS.PAN_detect,pan_debounce_str,pan_debounce);
	}
}

void scalerVIP_DI_VPAN_StatusUpdate()
{
	short i = 0;
	unsigned char vpan_up_pass_total = 0, vpan_down_pass_total = 0, pass = 0;
	di_di_smd_gmvcoeff3_RBUS smd_gmvcoeff3_reg;

	smd_gmvcoeff3_reg.regValue = rtd_inl(DI_DI_SMD_GMVCoeff3_reg);

	if (smd_gmvcoeff3_reg.smd_gmv1_x == 3 && smd_gmvcoeff3_reg.smd_gmv1_y < 3)
		pass = 2; // move up
	else if (smd_gmvcoeff3_reg.smd_gmv1_x == 3 && smd_gmvcoeff3_reg.smd_gmv1_y > 3)
		pass = 1; // move down
	else
		pass = 0;

	// assign pass sequence
	for (i=VPAN_PASS_COUNT-2; i>=0; i--){
		Smart_Integration_Status.SCREEN_VPAN_STATUS.Pass_Result_Sequence[i+1] = Smart_Integration_Status.SCREEN_VPAN_STATUS.Pass_Result_Sequence[i];
	}
	Smart_Integration_Status.SCREEN_VPAN_STATUS.Pass_Result_Sequence[0] = pass;

	for (i=0; i<VPAN_PASS_COUNT; i++)
	{
		if (Smart_Integration_Status.SCREEN_VPAN_STATUS.Pass_Result_Sequence[i] == 2)
			vpan_up_pass_total++;
		else if (Smart_Integration_Status.SCREEN_VPAN_STATUS.Pass_Result_Sequence[i] == 1)
			vpan_down_pass_total++;
	}

	Smart_Integration_Status.SCREEN_VPAN_STATUS.Pass_Result_Total_VPanUp = vpan_up_pass_total;
	Smart_Integration_Status.SCREEN_VPAN_STATUS.Pass_Result_Total_VPanDown = vpan_down_pass_total;

	if (vpan_up_pass_total > 12)
		Smart_Integration_Status.SCREEN_ACTION_STATUS.VPAN_detect = 2;
	else if (vpan_down_pass_total > 12)
		Smart_Integration_Status.SCREEN_ACTION_STATUS.VPAN_detect = 1;
	else
		Smart_Integration_Status.SCREEN_ACTION_STATUS.VPAN_detect = 0;

}

void scalerVIP_DI_SPAN_StatusUpdate()
{
	short i = 0;
	unsigned char span_RU_pass_total = 0, span_RD_pass_total = 0, span_LU_pass_total = 0, span_LD_pass_total = 0, pass = 0;
	unsigned int smd_sad_bin_total = 0, smd_sad_bin_first = 0;
	di_di_smd_gmvcoeff3_RBUS smd_gmvcoeff3_reg;

	di_di_smd_sadhisbina_RBUS di_smd_sadhistbina_reg;
	di_di_smd_sadhisbinb_RBUS di_smd_sadhistbinb_reg;
	di_di_smd_sadhisbinc_RBUS di_smd_sadhistbinc_reg;
	di_di_smd_sadhisbind_RBUS di_smd_sadhistbind_reg;
	di_di_smd_sadhisbine_RBUS di_smd_sadhistbine_reg;
	di_di_smd_sadhisbinf_RBUS di_smd_sadhistbinf_reg;
	di_di_smd_sadhisbing_RBUS di_smd_sadhistbing_reg;
	di_di_smd_sadhisbinh_RBUS di_smd_sadhistbinh_reg;

	di_smd_sadhistbina_reg.regValue = rtd_inl(DI_DI_SMD_SADHisBinA_reg);
	di_smd_sadhistbinb_reg.regValue = rtd_inl(DI_DI_SMD_SADHisBinB_reg);
	di_smd_sadhistbinc_reg.regValue = rtd_inl(DI_DI_SMD_SADHisBinC_reg);
	di_smd_sadhistbind_reg.regValue = rtd_inl(DI_DI_SMD_SADHisBinD_reg);
	di_smd_sadhistbine_reg.regValue = rtd_inl(DI_DI_SMD_SADHisBinE_reg);
	di_smd_sadhistbinf_reg.regValue = rtd_inl(DI_DI_SMD_SADHisBinF_reg);
	di_smd_sadhistbing_reg.regValue = rtd_inl(DI_DI_SMD_SADHisBinG_reg);
	di_smd_sadhistbinh_reg.regValue = rtd_inl(DI_DI_SMD_SADHisBinH_reg);

	smd_sad_bin_total = di_smd_sadhistbina_reg.smd_sad_his_bin0 + di_smd_sadhistbina_reg.smd_sad_his_bin1 +
						di_smd_sadhistbinb_reg.smd_sad_his_bin2 + di_smd_sadhistbinb_reg.smd_sad_his_bin3 +
						di_smd_sadhistbinc_reg.smd_sad_his_bin4 + di_smd_sadhistbinc_reg.smd_sad_his_bin5 +
						di_smd_sadhistbind_reg.smd_sad_his_bin6 + di_smd_sadhistbind_reg.smd_sad_his_bin7 +
						di_smd_sadhistbine_reg.smd_sad_his_bin8 + di_smd_sadhistbine_reg.smd_sad_his_bin9 +
						di_smd_sadhistbinf_reg.smd_sad_his_bin10 + di_smd_sadhistbinf_reg.smd_sad_his_bin11 +
						di_smd_sadhistbing_reg.smd_sad_his_bin12 + di_smd_sadhistbing_reg.smd_sad_his_bin13 +
						di_smd_sadhistbinh_reg.smd_sad_his_bin14 + di_smd_sadhistbinh_reg.smd_sad_his_bin15;

	smd_sad_bin_first = di_smd_sadhistbina_reg.smd_sad_his_bin0;

	smd_gmvcoeff3_reg.regValue = rtd_inl(DI_DI_SMD_GMVCoeff3_reg);

	if (smd_gmvcoeff3_reg.smd_gmv1_x > 3 && smd_gmvcoeff3_reg.smd_gmv1_y > 3)
		pass = 4; // right-down
	else if (smd_gmvcoeff3_reg.smd_gmv1_x > 3 && smd_gmvcoeff3_reg.smd_gmv1_y < 3)
		pass = 3; // right-up
	else if (smd_gmvcoeff3_reg.smd_gmv1_x < 3 && smd_gmvcoeff3_reg.smd_gmv1_y > 3)
		pass = 2; // left-down
	else if (smd_gmvcoeff3_reg.smd_gmv1_x < 3 && smd_gmvcoeff3_reg.smd_gmv1_y < 3)
		pass = 1; // left-up
	else
		pass = 0;

	if ((smd_sad_bin_first*100/(smd_sad_bin_total+1)) < 95)
		pass = 0;

	// assign pass sequence
	for (i=SPAN_PASS_COUNT-2; i>=0; i--)
		Smart_Integration_Status.SCREEN_SPAN_STATUS.Pass_Result_Sequence[i+1] = Smart_Integration_Status.SCREEN_SPAN_STATUS.Pass_Result_Sequence[i];
	Smart_Integration_Status.SCREEN_SPAN_STATUS.Pass_Result_Sequence[0] = pass;

	for (i=0; i<SPAN_PASS_COUNT; i++)
	{
		if (Smart_Integration_Status.SCREEN_SPAN_STATUS.Pass_Result_Sequence[i] == 4)
			span_RD_pass_total++;
		else if (Smart_Integration_Status.SCREEN_SPAN_STATUS.Pass_Result_Sequence[i] == 3)
			span_RU_pass_total++;
		else if (Smart_Integration_Status.SCREEN_SPAN_STATUS.Pass_Result_Sequence[i] == 2)
			span_LD_pass_total++;
		else if (Smart_Integration_Status.SCREEN_SPAN_STATUS.Pass_Result_Sequence[i] == 1)
			span_LU_pass_total++;
	}

	Smart_Integration_Status.SCREEN_SPAN_STATUS.Pass_Result_Total_SPanRU = span_RU_pass_total;
	Smart_Integration_Status.SCREEN_SPAN_STATUS.Pass_Result_Total_SPanRD = span_RD_pass_total;
	Smart_Integration_Status.SCREEN_SPAN_STATUS.Pass_Result_Total_SPanLU = span_LU_pass_total;
	Smart_Integration_Status.SCREEN_SPAN_STATUS.Pass_Result_Total_SPanLD = span_LD_pass_total;

	if (span_RD_pass_total > 12)
		Smart_Integration_Status.SCREEN_ACTION_STATUS.SPAN_detect = 4;
	else if (span_RU_pass_total > 12)
		Smart_Integration_Status.SCREEN_ACTION_STATUS.SPAN_detect = 3;
	else if (span_LD_pass_total > 12)
		Smart_Integration_Status.SCREEN_ACTION_STATUS.SPAN_detect = 2;
	else if (span_LU_pass_total > 12)
		Smart_Integration_Status.SCREEN_ACTION_STATUS.SPAN_detect = 1;
	else
		Smart_Integration_Status.SCREEN_ACTION_STATUS.SPAN_detect = 0;

	if (Smart_Integration_Status.SCREEN_SPAN_STATUS.Show_Debug_MSG)
	{
		VIP_DEBUG_PRINTF("[SIS SPAN] RD: %d, RU: %d, LD: %d, LU: %d, pass: %d\n", span_RD_pass_total, span_RU_pass_total, span_LD_pass_total, span_LU_pass_total, pass);
	}
}

void scalerVIP_DI_ZOOMMOTION_StatusUpdate()
{
	short i = 0;
	unsigned char zoomin_pass_total = 0, zoomout_pass_total = 0;
	di_im_di_zoommotion_detector_RBUS zoommotion_detector_reg;

	zoommotion_detector_reg.regValue = rtd_inl(DI_IM_DI_ZoomMotion_Detector_reg);

	// assign pass sequence
	for (i=ZOOMMOTION_PASS_COUNT-2; i>=0; i--)
		Smart_Integration_Status.SCREEN_ZOOMMOTION_STATUS.Pass_Result_Sequence[i+1] = Smart_Integration_Status.SCREEN_ZOOMMOTION_STATUS.Pass_Result_Sequence[i];
	Smart_Integration_Status.SCREEN_ZOOMMOTION_STATUS.Pass_Result_Sequence[0] = zoommotion_detector_reg.smd_zoommotion_flag;

	for (i=0; i<ZOOMMOTION_PASS_COUNT; i++)
	{
		if (Smart_Integration_Status.SCREEN_ZOOMMOTION_STATUS.Pass_Result_Sequence[i] == 1)
			zoomout_pass_total++;
		else if (Smart_Integration_Status.SCREEN_ZOOMMOTION_STATUS.Pass_Result_Sequence[i] == 2)
			zoomin_pass_total++;
	}

	Smart_Integration_Status.SCREEN_ZOOMMOTION_STATUS.Pass_Result_Total_ZoomIn = zoomin_pass_total;
	Smart_Integration_Status.SCREEN_ZOOMMOTION_STATUS.Pass_Result_Total_ZoomOut = zoomout_pass_total;

	if (zoomin_pass_total > 12)
		Smart_Integration_Status.SCREEN_ACTION_STATUS.ZOOMMOTION_detect = 2;
	else if (zoomout_pass_total > 12)
		Smart_Integration_Status.SCREEN_ACTION_STATUS.ZOOMMOTION_detect = 1;
	else
		Smart_Integration_Status.SCREEN_ACTION_STATUS.ZOOMMOTION_detect = 0;
}

void scalerVIP_DI_SLOWMOTION_StatusUpdate()
{
	short i = 0;
	unsigned char slow_pass_total = 0;
	di_im_di_slowmotion_detector_1_RBUS slowmotion_detector_1_reg;

	slowmotion_detector_1_reg.regValue = rtd_inl(DI_IM_DI_SlowMotion_Detector_1_reg);

	// assign pass sequence
	for (i=SLOWMOTION_PASS_COUNT-2; i>=0; i--)
		Smart_Integration_Status.SCREEN_SLOWMOTION_STATUS.Pass_Result_Sequence[i+1] = Smart_Integration_Status.SCREEN_SLOWMOTION_STATUS.Pass_Result_Sequence[i];
	Smart_Integration_Status.SCREEN_SLOWMOTION_STATUS.Pass_Result_Sequence[0] = slowmotion_detector_1_reg.smd_slowmotion_flag;

	for (i=0; i<SLOWMOTION_PASS_COUNT; i++)
	{
		slow_pass_total += Smart_Integration_Status.SCREEN_SLOWMOTION_STATUS.Pass_Result_Sequence[i];
	}

	Smart_Integration_Status.SCREEN_SLOWMOTION_STATUS.Pass_Result_Total_Slow = slow_pass_total;

	if (Smart_Integration_Status.SCREEN_SLOWMOTION_STATUS.Show_Debug_MSG)
	{
		VIP_DEBUG_PRINTF("[SIS SLOWMOTION] slow_pass_total: %d\n", slow_pass_total);
	}

	if (slow_pass_total > 5)
		Smart_Integration_Status.SCREEN_ACTION_STATUS.SLOWMOTION_detect = 1;
	else
		Smart_Integration_Status.SCREEN_ACTION_STATUS.SLOWMOTION_detect = 0;
}

void scalerVIP_DI_SCENECHANGE_StatusUpdate()
{
	short i = 0;
	unsigned char scenechange_pass_total = 0;
	unsigned int near_compare_diff = 0, far_compare_diff = 0;
	unsigned int total_energy = 0;

	for (i=0; i<HISTOGRAM_SIZE; i++)
		total_energy += Smart_Integration_Status.Y_Histogram[i]*i;

	// because result is from Y Histogram, so MA info must delay 2 field, so pass sequence [0] and [1].
	near_compare_diff = abs(Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_Sequence[2]-Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_Sequence[3]);
	for (i=3; i<SCENECHANGE_COUNT-1; i++)
	{
		far_compare_diff = abs(Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_Sequence[i]-Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_Sequence[i+1]);
		if (near_compare_diff > (Smart_Integration_Status.SCREEN_SCENECHANGE_STATUS.pass_ratio*far_compare_diff) && near_compare_diff > 2000)
			scenechange_pass_total++;
	}

	for (i=SCENECHANGE_COUNT-2; i>=0; i--)
		Smart_Integration_Status.SCREEN_SCENECHANGE_STATUS.Result_Sequence[i+1] = Smart_Integration_Status.SCREEN_SCENECHANGE_STATUS.Result_Sequence[i];
	Smart_Integration_Status.SCREEN_SCENECHANGE_STATUS.Result_Sequence[0] = total_energy;

	if (scenechange_pass_total >= Smart_Integration_Status.SCREEN_SCENECHANGE_STATUS.pass_couter &&
		abs(Smart_Integration_Status.SCREEN_SCENECHANGE_STATUS.Result_Sequence[0]-Smart_Integration_Status.SCREEN_SCENECHANGE_STATUS.Result_Sequence[4]) > 3500)
	{
		Smart_Integration_Status.SCREEN_ACTION_STATUS.SCENECHANGE_detect = 1;

		if (Smart_Integration_Status.SCREEN_SCENECHANGE_STATUS.Show_Debug_MSG)
		{
			VIP_DEBUG_PRINTF("[SIS SCENECHANGE] near: %d, far: %d, %d, %d, %d, Y diff: %d\n", near_compare_diff, far_compare_diff,
				abs(Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_Sequence[1]-Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_Sequence[2]),
				abs(Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_Sequence[2]-Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_Sequence[3]),
				abs(Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_Sequence[3]-Smart_Integration_Status.SCREEN_MOTION_STATUS.Large_FM_SUM_Sequence[4]),
				abs(Smart_Integration_Status.SCREEN_SCENECHANGE_STATUS.Result_Sequence[0]-Smart_Integration_Status.SCREEN_SCENECHANGE_STATUS.Result_Sequence[4]));
		}
	}
	else
		Smart_Integration_Status.SCREEN_ACTION_STATUS.SCENECHANGE_detect = 0;
}

void scalerVIP_DI_FADING_StatusUpdate()
{
	short i = 0;
	unsigned char fadein_pass_total = 0, fadeout_pass_total = 0;
	unsigned int total_energy = 0;

	for (i=0; i<HISTOGRAM_SIZE; i++)
		total_energy += Smart_Integration_Status.Y_Histogram[i]*i;

	// assign pass sequence
	for (i=FADING_PASS_COUNT-2; i>=0; i--)
		Smart_Integration_Status.SCREEN_FADING_STATUS.Result_Sequence[i+1] = Smart_Integration_Status.SCREEN_FADING_STATUS.Result_Sequence[i];
	Smart_Integration_Status.SCREEN_FADING_STATUS.Result_Sequence[0] = total_energy;

	for (i=0; i<FADING_PASS_COUNT-4; i+=4)
	{
		if ((Smart_Integration_Status.SCREEN_FADING_STATUS.Result_Sequence[i] - Smart_Integration_Status.SCREEN_FADING_STATUS.Result_Sequence[i+4]) > 10000)
			fadein_pass_total++;
		else if ((Smart_Integration_Status.SCREEN_FADING_STATUS.Result_Sequence[i] - Smart_Integration_Status.SCREEN_FADING_STATUS.Result_Sequence[i+4]) < 10000)
			fadeout_pass_total++;
	}

//	VIP_DEBUG_PRINTF("[SIS System] fadein:%d, fadeout:%d: cur:%d, pre:%d\n", fadein_pass_total, fadeout_pass_total, Smart_Integration_Status.SCREEN_FADING_STATUS.Result_Sequence[0], Smart_Integration_Status.SCREEN_FADING_STATUS.Result_Sequence[4]);
/*	if (fadein_pass_total > 12)
		Smart_Integration_Status.SCREEN_ACTION_STATUS.FADING_detect = 2;
	else if (fadeout_pass_total > 12)
		Smart_Integration_Status.SCREEN_ACTION_STATUS.FADING_detect = 1;
	else
		Smart_Integration_Status.SCREEN_ACTION_STATUS.FADING_detect = 0;*/
}

void scalerVIP_DI_HIGHFREQUENCY_StatusUpdate()
{
	short i = 0;
	unsigned int total_pixel = 0, total_score_ratio = 0;
	di_im_di_active_window_control_RBUS di_active_window_control_reg;
	di_im_di_weave_window_control_RBUS di_weave_window_control_reg;
	di_im_di_hfd_statistic_RBUS di_hfd_statistic_reg;

	di_active_window_control_reg.regValue = rtd_inl(DI_IM_DI_ACTIVE_WINDOW_CONTROL_reg);
	di_weave_window_control_reg.regValue = rtd_inl(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg);
	di_hfd_statistic_reg.regValue = rtd_inl(DI_IM_DI_HFD_STATISTIC_reg);

	total_pixel = Smart_Integration_Status.DI_WIDTH*Smart_Integration_Status.DI_HEIGHT;

	// assign status sequence
	for (i=HIGHFREQUENCY_PASS_COUNT-2; i>=0; i--)
		Smart_Integration_Status.SCREEN_HIGHFREQUENCY_STATUS.Pass_Result_Sequence[i+1] = Smart_Integration_Status.SCREEN_HIGHFREQUENCY_STATUS.Pass_Result_Sequence[i];
	Smart_Integration_Status.SCREEN_HIGHFREQUENCY_STATUS.Pass_Result_Sequence[0] = ((di_hfd_statistic_reg.hfd_statistic*HIGHFREQUENCY_SCALE)/(total_pixel==0?1:total_pixel));

	for (i=0; i<HIGHFREQUENCY_PASS_COUNT; i++)
	{
		total_score_ratio += Smart_Integration_Status.SCREEN_HIGHFREQUENCY_STATUS.Pass_Result_Sequence[i];
	}

	Smart_Integration_Status.SCREEN_HIGHFREQUENCY_STATUS.Pass_Result_FIR = total_score_ratio/HIGHFREQUENCY_PASS_COUNT;

	if (Smart_Integration_Status.SCREEN_HIGHFREQUENCY_STATUS.Pass_Result_FIR > 400)
		Smart_Integration_Status.SCREEN_ACTION_STATUS.HIGHFREQUENCY_detect = 1;
	else
		Smart_Integration_Status.SCREEN_ACTION_STATUS.HIGHFREQUENCY_detect = 0;
}

void scalerVIP_NOISE_LEVEL_StatusUpdate()
{
	scalerVIP_SPATIAL_NOISE_LEVEL_StatusUpdate();
	scalerVIP_DI_TEMPORAL_NOISE_LEVEL_StatusUpdate();
}

void scalerVIP_SPATIAL_NOISE_LEVEL_StatusUpdate()
{
	short i = 0, cnt1 = 0, cnt2 = 0;
	unsigned char result1 = 0, result2 = 0;

	for (i=SPATIAL_NOISELEVEL_CNT-2; i>=0; i--)
	{
		Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_SPATIAL_NOISE.TMP_NOISE_LEVEL[i+1] = Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_SPATIAL_NOISE.TMP_NOISE_LEVEL[i];
		cnt1 = cnt1 + Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_SPATIAL_NOISE.TMP_NOISE_LEVEL[i+1];
	}
	Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_SPATIAL_NOISE.TMP_NOISE_LEVEL[0] = Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_SPATIAL_NOISE.TMP_NOISE_LEVEL_CUR;
	cnt1 = cnt1 + Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_SPATIAL_NOISE.TMP_NOISE_LEVEL[0];


	for (i=SPATIAL_NOISELEVEL_RELIABLE_CNT-2; i>=0; i--)
	{
		Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_SPATIAL_NOISE.TMP_NOISE_LEVEL_RELIABLE[i+1] = Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_SPATIAL_NOISE.TMP_NOISE_LEVEL_RELIABLE[i];
		cnt2 = cnt2 + Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_SPATIAL_NOISE.TMP_NOISE_LEVEL_RELIABLE[i+1];
	}
	Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_SPATIAL_NOISE.TMP_NOISE_LEVEL_RELIABLE[0] = Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_SPATIAL_NOISE.TMP_NOISE_LEVEL_RELIABLE_CUR;
	cnt2 = cnt2 + Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_SPATIAL_NOISE.TMP_NOISE_LEVEL_RELIABLE[0];

	result1 = (unsigned char)(cnt1/SPATIAL_NOISELEVEL_CNT);
	if(result1 > 15)
		result1 = 15;
	else if(result1 < 0)
		result1 = 0;
	Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_SPATIAL_NOISE.RESULT_NOISE_LEVEL = result1;

	result2 = (unsigned char)(cnt2/SPATIAL_NOISELEVEL_RELIABLE_CNT);
	Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_SPATIAL_NOISE.RESULT_NOISE_LEVEL_RELIABLE = (result2 > 1)? 1:0;

	di_di_rtnr_nm_infor1_RBUS di_rtnr_nm_infor1_reg;
	di_rtnr_nm_infor1_reg.regValue = rtd_inl(DI_DI_RTNR_NM_INFOR1_reg);
	di_rtnr_nm_infor1_reg.nm_noiselevel = result1;

	//di_di_rtnr_nm_infor1_RBUS di_rtnr_nm_infor1_reg;
	//di_rtnr_nm_infor1_reg.regValue = rtd_inl(DI_DI_RTNR_NM_INFOR1_reg);
	unsigned int Sum;
	Sum = di_rtnr_nm_infor1_reg.nm_sumvarnum;
	if(Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_SPATIAL_NOISE.Show_Debug_MSG)
	{
		VIP_DEBUG_PRINTF("Cur NM NoiseLevel : %d , Reliable: %d \n",
			Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_SPATIAL_NOISE.TMP_NOISE_LEVEL[0],
			Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_SPATIAL_NOISE.TMP_NOISE_LEVEL_RELIABLE[0]);
		VIP_DEBUG_PRINTF("Result NM NoiseLevel : %d , Reliable: %d \n",
			Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_SPATIAL_NOISE.RESULT_NOISE_LEVEL,
			Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_SPATIAL_NOISE.RESULT_NOISE_LEVEL_RELIABLE);
		VIP_DEBUG_PRINTF("Cnt: %d, Height : %d, Width : %d\n", Sum,Smart_Integration_Status.DI_HEIGHT,Smart_Integration_Status.DI_WIDTH);
	}
	scaler_rtd_outl(DI_DI_RTNR_NM_INFOR1_reg, di_rtnr_nm_infor1_reg.regValue);

}

void scalerVIP_DI_TEMPORAL_NOISE_LEVEL_StatusUpdate()
{
	short i = 0;
	unsigned int total_pixel = 0;
	unsigned int et_y_count = 0, et_y_sum = 0;
	unsigned short result = 0, result2 = 0;

	di_im_di_rtnr_level_bound_RBUS di_rtnr_level_bound_reg;
	di_im_di_rtnr_et_count_y_RBUS di_rtnr_et_count_y_reg;
	di_im_di_rtnr_et_sum_y_RBUS di_rtnr_et_sum_y_reg;

	di_rtnr_level_bound_reg.regValue = rtd_inl(DI_IM_DI_RTNR_LEVEL_BOUND_reg);
	di_rtnr_level_bound_reg.cp_temporal_nl_low_bnd_y = 0;
	di_rtnr_level_bound_reg.cp_temporal_nl_up_bnd_y = 0xFF;
	rtd_outl(DI_IM_DI_RTNR_LEVEL_BOUND_reg, di_rtnr_level_bound_reg.regValue);

	di_rtnr_et_count_y_reg.regValue = rtd_inl(DI_IM_DI_RTNR_ET_COUNT_Y_reg);
	et_y_count = di_rtnr_et_count_y_reg.cp_temporal_same_et_cnt_y;

	di_rtnr_et_sum_y_reg.regValue = rtd_inl(DI_IM_DI_RTNR_ET_SUM_Y_reg);
	et_y_sum = di_rtnr_et_sum_y_reg.cp_temporal_same_et_sad_sum_y;

	result = et_y_sum/(et_y_count+1);
	total_pixel = Smart_Integration_Status.DI_WIDTH*Smart_Integration_Status.DI_HEIGHT;

	// assign status sequence
	for (i=TEMPORAL_NOISELEVEL_COUNT-2; i>=0; i--)
	{
		Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_TEMPORAL_NOISE.Result_Sequence_Reliable[i+1] = Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_TEMPORAL_NOISE.Result_Sequence_Reliable[i];
		Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_TEMPORAL_NOISE.Result_Sequence[i+1] = Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_TEMPORAL_NOISE.Result_Sequence[i];
	}
	if ((et_y_count*100)>(total_pixel*90))
		Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_TEMPORAL_NOISE.Result_Sequence_Reliable[0] = 4;
	else if ((et_y_count*100)>(total_pixel*85))
		Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_TEMPORAL_NOISE.Result_Sequence_Reliable[0] = 3;
	else if ((et_y_count*100)>(total_pixel*80))
		Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_TEMPORAL_NOISE.Result_Sequence_Reliable[0] = 2;
	else if ((et_y_count*100)>(total_pixel*75))
		Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_TEMPORAL_NOISE.Result_Sequence_Reliable[0] = 1;
	else
		Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_TEMPORAL_NOISE.Result_Sequence_Reliable[0] = 0;

	Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_TEMPORAL_NOISE.Result_Sequence[0] = result;

	result = 0, result2 = 0;
	for (i=0; i<TEMPORAL_NOISELEVEL_COUNT; i++)
	{
		result += Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_TEMPORAL_NOISE.Result_Sequence_Reliable[i];
		result2 += Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_TEMPORAL_NOISE.Result_Sequence[i];
	}
	result = result/TEMPORAL_NOISELEVEL_COUNT;
	result2 = ((result2/TEMPORAL_NOISELEVEL_COUNT)>>4);

	if (result >= 2)
		Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_TEMPORAL_NOISE.RESULT_NOISE_RELIABLE = 1;
	else
		Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_TEMPORAL_NOISE.RESULT_NOISE_RELIABLE = 0;

	Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_TEMPORAL_NOISE.RESULT_NOISE_LEVEL = result2;

	if (Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_TEMPORAL_NOISE.Show_Debug_MSG)
	{
		VIP_DEBUG_PRINTF("[SIS NR_TMP_R: %d, %d, %d, %d, %d, NR_TMP_LEVEL: %d, %d, %d, %d, %d => %d\n",
			Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_TEMPORAL_NOISE.Result_Sequence_Reliable[0],
			Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_TEMPORAL_NOISE.Result_Sequence_Reliable[1],
			Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_TEMPORAL_NOISE.Result_Sequence_Reliable[2],
			Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_TEMPORAL_NOISE.Result_Sequence_Reliable[3],
			Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_TEMPORAL_NOISE.Result_Sequence_Reliable[4],
			Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_TEMPORAL_NOISE.Result_Sequence[0],
			Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_TEMPORAL_NOISE.Result_Sequence[1],
			Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_TEMPORAL_NOISE.Result_Sequence[2],
			Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_TEMPORAL_NOISE.Result_Sequence[3],
			Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_TEMPORAL_NOISE.Result_Sequence[4], (et_y_sum/(et_y_count+1)));
	}
}

void scalerVIP_DI_FILM_StatusUpdate()
{
	di_im_di_film_new_function_main_RBUS film_new_function_main_reg;
	di_im_di_si_film_final_result_RBUS film_final_result_reg;

	film_new_function_main_reg.regValue = rtd_inl(DI_IM_DI_FILM_NEW_FUNCTION_MAIN_reg);
	film_final_result_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_FINAL_RESULT_reg);

	if (film_new_function_main_reg.fw_film_filmdetected == 1 || film_final_result_reg.film_detected == 1)
		Smart_Integration_Status.SCREEN_ACTION_STATUS.FILM_detect = 1;
	else
		Smart_Integration_Status.SCREEN_ACTION_STATUS.FILM_detect = 0;
}

void scalerVIP_DI_SMD_StautsUpdate()
{
	di_di_smd_gmvcoeff1_RBUS smd_gmvcoeff1_reg;
	smd_gmvcoeff1_reg.regValue= rtd_inl(DI_DI_SMD_GMVCoeff1_reg);

	if(Smart_Integration_Status.SCREEN_SMD_STATUS.Show_Debug_MSG == 1)
	{
		//VIP_DEBUG_PRINTF("GMV_global_ctr: %d \n",smd_gmvcoeff1_reg.smd_gmv_ctr);
	}
}

/**
 * Set auto MA threshold ??
 *
 * @param	Level: degree of auto MA level
 * @return	void
 */
void scalerVIP_colorMAQuickSetTh(unsigned char Level)
{
	di_im_di_control_RBUS di_control_reg;
	di_im_di_ma_frame_motion_th_a_RBUS motion_detect_th_a_reg;
	di_im_di_ma_frame_motion_th_b_RBUS motion_detect_th_b_reg;
	di_im_di_ma_frame_motion_th_c_RBUS motion_detect_th_c_reg;
	di_im_di_ma_field_teeth_th_a_RBUS teeth_detect_th_a_reg;
	di_im_di_ma_others_th_RBUS teeth_detect_th_b_reg;
	di_im_di_ma_sawtooth_th_RBUS sawtooth_th_reg;


 	switch (Level)
	{
		case 0: //weave only
			di_control_reg.regValue = rtd_inl(DI_IM_DI_CONTROL_reg);
			di_control_reg.ma_controlmode = 0;// write_enable[2]

			/* henry @ mac5 161219 DI write enable bit */
			//di_control_reg.regValue = di_control_reg.regValue | DI_IM_DI_CONTROL_write_enable_0_mask;
			di_control_reg.write_enable_0 = 1;
			rtd_outl(DI_IM_DI_CONTROL_reg, di_control_reg.regValue);

			break;

		case 10: //inter only

			di_control_reg.regValue = rtd_inl(DI_IM_DI_CONTROL_reg);
			di_control_reg.ma_controlmode = 2;// write_enable[2]

			/* henry @ mac5 161219 DI write enable bit */
			//di_control_reg.regValue = di_control_reg.regValue | DI_IM_DI_CONTROL_write_enable_0_mask;
			di_control_reg.write_enable_0 = 1;
			rtd_outl(DI_IM_DI_CONTROL_reg, di_control_reg.regValue);

			break;

		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			di_control_reg.regValue = scaler_rtd_inl(DI_IM_DI_CONTROL_reg);
			motion_detect_th_a_reg.regValue = scaler_rtd_inl(DI_IM_DI_MA_FRAME_MOTION_TH_A_reg);
			motion_detect_th_b_reg.regValue = scaler_rtd_inl(DI_IM_DI_MA_FRAME_MOTION_TH_B_reg);
			motion_detect_th_c_reg.regValue = scaler_rtd_inl(DI_IM_DI_MA_FRAME_MOTION_TH_C_reg);

			di_control_reg.ma_controlmode = 1;// write_enable[2]

			/* henry @ mac5 161219 DI write enable bit */
			//di_control_reg.regValue = di_control_reg.regValue | DI_IM_DI_CONTROL_write_enable_0_mask;
			di_control_reg.write_enable_0 = 1;
			/*
			if((Scaler_InputSrcGetMainChType() != _SRC_TV))
			{
				di_hmc_me_refine_ctrl2_reg.hmc_fw_ctrl_bypass = 1;
			}
			*/

			//VIP_DEBUG_PRINTF("[Young]scalerVIP_colorMAQuickSetTh88888888\n");

			/*
			motion_detect_th_a_reg.ma_framehtha = 2 + Level;
			motion_detect_th_a_reg.ma_framemtha = 3 + Level;
			motion_detect_th_a_reg.ma_framerlvtha =0x10+ Level;
			motion_detect_th_a_reg.ma_framestha =0x25+ Level;// Level;

			motion_detect_th_b_reg.ma_framehthb = 0x8 + Level;
			motion_detect_th_b_reg.ma_framemthb = 0x12 + Level;
			motion_detect_th_b_reg.ma_framerlvthb = 0x11 + Level;
			motion_detect_th_b_reg.ma_framesthb = 0x26+ Level;//0xa + Level;

			motion_detect_th_c_reg.ma_framehthc = 0x12 + Level;
			motion_detect_th_c_reg.ma_framemthc = 0x30 + Level;
			motion_detect_th_c_reg.ma_framerlvthc = 0x12 + Level;
			motion_detect_th_c_reg.ma_framesthc =0x27+ Level; //0x16 + Level;
  	  		*/

			motion_detect_th_a_reg.ma_framehtha =  (Level-1)<0?0:(Level-1);
			motion_detect_th_a_reg.ma_framemtha =   Level;
			motion_detect_th_a_reg.ma_framerlvtha = Level-3<0?0:(Level-3);
			motion_detect_th_a_reg.ma_framestha =( Level-3)<0?0:(Level-3);

			motion_detect_th_b_reg.ma_framehthb = 0x5 + Level;
			motion_detect_th_b_reg.ma_framemthb = 0x0f + Level;
			motion_detect_th_b_reg.ma_framerlvthb = 0x1 + Level;
			motion_detect_th_b_reg.ma_framesthb = 0x7 + Level;

			motion_detect_th_c_reg.ma_framehthc = 0x0f + Level;
			motion_detect_th_c_reg.ma_framemthc = 0x2d + Level;
			motion_detect_th_c_reg.ma_framerlvthc = 0x0b + Level;
			motion_detect_th_c_reg.ma_framesthc = 0x13 + Level;

			scaler_rtd_outl(DI_IM_DI_CONTROL_reg, di_control_reg.regValue);
			scaler_rtd_outl(DI_IM_DI_MA_FRAME_MOTION_TH_A_reg, motion_detect_th_a_reg.regValue);
			scaler_rtd_outl(DI_IM_DI_MA_FRAME_MOTION_TH_B_reg, motion_detect_th_b_reg.regValue);
			scaler_rtd_outl(DI_IM_DI_MA_FRAME_MOTION_TH_C_reg, motion_detect_th_c_reg.regValue);

			break;

		default:


			di_control_reg.regValue = scaler_rtd_inl(DI_IM_DI_CONTROL_reg);
			motion_detect_th_a_reg.regValue = scaler_rtd_inl(DI_IM_DI_MA_FRAME_MOTION_TH_A_reg);
			motion_detect_th_b_reg.regValue = scaler_rtd_inl(DI_IM_DI_MA_FRAME_MOTION_TH_B_reg);
			motion_detect_th_c_reg.regValue = scaler_rtd_inl(DI_IM_DI_MA_FRAME_MOTION_TH_C_reg);
			teeth_detect_th_a_reg.regValue = scaler_rtd_inl(DI_IM_DI_MA_FIELD_TEETH_TH_A_reg);
			teeth_detect_th_b_reg.regValue = scaler_rtd_inl(DI_IM_DI_MA_OTHERS_TH_reg);
			sawtooth_th_reg.regValue = scaler_rtd_inl(DI_IM_DI_MA_SAWTOOTH_TH_reg);

			di_control_reg.ma_controlmode=1;	// write_enable[2]
			di_control_reg.ma_3aenable=0;		// write_enable[4]
			di_control_reg.ma_messintra90=1;	// write_enable[6]
			di_control_reg.ma_onedirectionweaveen=1;

			//if((Scaler_InputSrcGetMainChType() != _SRC_TV))
				//di_hmc_me_refine_ctrl2_reg.hmc_fw_ctrl_bypass= 1;

			di_control_reg.ma_smoothintra90=1;
			di_control_reg.ma_stilllogoena=1;	// write_enable[8]

			/* henry @ mac5 161219 DI write enable bit */
			#if 0
			di_control_reg.regValue = di_control_reg.regValue |
				DI_IM_DI_CONTROL_write_enable_0_mask |
				DI_IM_DI_CONTROL_write_enable_1_mask |
				DI_IM_DI_CONTROL_write_enable_2_mask |
				DI_IM_DI_CONTROL_write_enable_3_mask;
			#endif
			di_control_reg.write_enable_0 = 1;
			di_control_reg.write_enable_1 = 1;
			di_control_reg.write_enable_2 = 1;
			di_control_reg.write_enable_3 = 1;

			motion_detect_th_a_reg.ma_framehtha=4;
			motion_detect_th_a_reg.ma_framemtha=5;
			motion_detect_th_a_reg.ma_framerlvtha=2;
			motion_detect_th_a_reg.ma_framestha=2;

			motion_detect_th_b_reg.ma_framehthb=0xa;
			motion_detect_th_b_reg.ma_framemthb=0x14;
			motion_detect_th_b_reg.ma_framerlvthb=0x6;
			motion_detect_th_b_reg.ma_framesthb=0xc;

			motion_detect_th_c_reg.ma_framehthc=0x14;
			motion_detect_th_c_reg.ma_framemthc=0x32;
			motion_detect_th_c_reg.ma_framerlvthc=0x10;
			motion_detect_th_c_reg.ma_framesthc=0x18;

			teeth_detect_th_a_reg.ma_fieldteethhtha=0xf;
			teeth_detect_th_a_reg.ma_fieldteethmtha=0xf;
			teeth_detect_th_a_reg.ma_fieldteethrlvtha=0x2;
			teeth_detect_th_a_reg.ma_fieldteethstha=0x2;

			teeth_detect_th_b_reg.ma_fieldteeththb=0x14;
			teeth_detect_th_b_reg.ma_horicomth=0x14;
			teeth_detect_th_b_reg.ma_stilllogovdth=0xf;
			teeth_detect_th_b_reg.ma_ydiffth=0x96;

			sawtooth_th_reg.ma_sawtoothhth=0x14;
			sawtooth_th_reg.ma_sawtoothmth=0x14;
			sawtooth_th_reg.ma_sawtoothrlvth=0xa;
			sawtooth_th_reg.ma_sawtoothsth=0xa;
			scaler_rtd_outl(DI_IM_DI_CONTROL_reg, di_control_reg.regValue);
			scaler_rtd_outl(DI_IM_DI_MA_FRAME_MOTION_TH_A_reg, motion_detect_th_a_reg.regValue);
			scaler_rtd_outl(DI_IM_DI_MA_FRAME_MOTION_TH_B_reg, motion_detect_th_b_reg.regValue);
			scaler_rtd_outl(DI_IM_DI_MA_FRAME_MOTION_TH_C_reg, motion_detect_th_c_reg.regValue);
			scaler_rtd_outl(DI_IM_DI_MA_FIELD_TEETH_TH_A_reg, teeth_detect_th_a_reg.regValue);
			scaler_rtd_outl(DI_IM_DI_MA_OTHERS_TH_reg, teeth_detect_th_b_reg.regValue);
			scaler_rtd_outl(DI_IM_DI_MA_SAWTOOTH_TH_reg, sawtooth_th_reg.regValue);
			break;
	}
}


/**
 * AutoMA bean drop case
 *
 * @param	mode: display mode
 * @param	en_test: debug mode
 * @return	void
 */
void scalerVIP_colorMABeanDrop(unsigned char mode, unsigned int en_test)
{
	static unsigned char BeanCount = 0; //Thur 20070926

	unsigned char th_BeanCntMax = 90;

	unsigned int th_BeanTop = 500;
	unsigned int th_BeanMid = 500;
	unsigned int th_BeanBot = 100;
	unsigned char en_BeanTest = 0;


	di_im_di_control_RBUS di_control_reg;
	di_im_di_debug_mode_RBUS debug_mode_reg; //20070807 Thur test for debug mode
	histogram_ich1_hist_in_cselect_RBUS ich1_hist_in_cselect_reg;
	unsigned int bean_th = 0;

	//scalerDrvPrint( "enter scalerVIP_colorMABeanDrop\n" );

	en_BeanTest = (en_test<<31)>>31;


	di_control_reg.regValue = scaler_rtd_inl(DI_IM_DI_CONTROL_reg); //MA control mode
	debug_mode_reg.regValue = scaler_rtd_inl(DI_IM_DI_DEBUG_MODE_reg); //20070807 Thur Test


	switch (mode) {
		case _MODE_480I:
			break;

		case _MODE_576I:
			th_BeanTop = th_BeanTop*576/480;
			th_BeanMid = th_BeanMid*576/480;
			th_BeanBot = th_BeanBot*576/480;
			break;
		case _MODE_1080I25:
		case _MODE_1080I30:
			th_BeanTop = th_BeanTop*6;
			th_BeanMid = th_BeanMid*6;
			th_BeanBot = th_BeanBot*6;
			break;
	}

//========Bean drop problem========

	ich1_hist_in_cselect_reg.regValue = rtd_inl(HISTOGRAM_ICH1_Hist_IN_CSELECT_reg);
	bean_th = 0x10<<(5-ich1_hist_in_cselect_reg.ch1_his_shift_sel);

#ifndef CONFIG_RTK_KDEV_VGIP_INTERRUPT //. can't use rtd_t_inl in kernel
	if ( ((SmartPic_clue->Y_Main_Hist)[16]) > bean_th && ((SmartPic_clue->Y_Main_Hist)[17]) > bean_th &&
		(
			rtd_t_inl(di_im_di_si_film_motion_next_h_t_RBUS, DI_IM_DI_SI_FILM_MOTION_NEXT_H_T_reg).regValue>th_BeanTop &&
			rtd_t_inl(di_im_di_si_film_motion_next_h_m_RBUS, DI_IM_DI_SI_FILM_MOTION_NEXT_H_M_reg).regValue>th_BeanMid &&
			rtd_t_inl(di_im_di_si_film_motion_next_h_b_RBUS, DI_IM_DI_SI_FILM_MOTION_NEXT_H_B_reg).regValue<th_BeanBot &&
			rtd_t_inl(di_im_di_si_film_motion_pre_h_t_RBUS, DI_IM_DI_SI_FILM_MOTION_PRE_H_T_reg).regValue>th_BeanTop &&
			rtd_t_inl(di_im_di_si_film_motion_pre_h_m_RBUS, DI_IM_DI_SI_FILM_MOTION_PRE_H_M_reg).regValue>th_BeanMid &&
			rtd_t_inl(di_im_di_si_film_motion_pre_h_b_RBUS, DI_IM_DI_SI_FILM_MOTION_PRE_H_B_reg).regValue<th_BeanBot ) )
#else
	di_im_di_si_film_motion_next_h_t_RBUS next_h_t;
	di_im_di_si_film_motion_next_h_m_RBUS next_h_m;
	di_im_di_si_film_motion_next_h_b_RBUS next_h_b;
	di_im_di_si_film_motion_pre_h_t_RBUS pre_h_t;
	di_im_di_si_film_motion_pre_h_m_RBUS pre_h_m;
	di_im_di_si_film_motion_pre_h_b_RBUS pre_h_b;

	next_h_t.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_NEXT_H_T_reg);
	next_h_m.regValue= rtd_inl(DI_IM_DI_SI_FILM_MOTION_NEXT_H_M_reg);
	next_h_b.regValue= rtd_inl(DI_IM_DI_SI_FILM_MOTION_NEXT_H_B_reg);
	pre_h_t.regValue= rtd_inl(DI_IM_DI_SI_FILM_MOTION_PRE_H_T_reg);
	pre_h_m.regValue= rtd_inl(DI_IM_DI_SI_FILM_MOTION_PRE_H_M_reg);
	pre_h_b.regValue= rtd_inl(DI_IM_DI_SI_FILM_MOTION_PRE_H_B_reg);

	if ( ((SmartPic_clue->Y_Main_Hist)[16]) > bean_th && ((SmartPic_clue->Y_Main_Hist)[17]) > bean_th &&
		(
			next_h_t.regValue>th_BeanTop &&
			next_h_m.regValue>th_BeanMid &&
			next_h_b.regValue<th_BeanBot &&
			pre_h_t.regValue>th_BeanTop &&
			pre_h_m.regValue>th_BeanMid &&
			pre_h_b.regValue<th_BeanBot ) )
#endif
	{
		BeanCount = BeanCount + 2;
		if ( BeanCount >= th_BeanCntMax ) {
			BeanCount = th_BeanCntMax;
		}

		if (1)
		{
				di_control_reg.ma_preferintra = 1;
				#if defined (VIP_TEST_MODE)
				if ( en_BeanTest == 1 ) {
					debug_mode_reg.ma_debugmode = 1; //Thur test 20070807
				}
				#endif
		}
	}
	else
	{
		if ( BeanCount > 0 )
			BeanCount--;

#if 0
		if (	rtd_t_inl(i_hist_in_data_17_16_RBUS,HISTOGRAM_I_HIST_IN_DATA_17_16_ADDR).his_hist16>0x10 &&
			rtd_t_inl(i_hist_in_data_17_16_RBUS ,HISTOGRAM_I_HIST_IN_DATA_17_16_ADDR).his_hist17>0x10 &&
#else
		if ( ((SmartPic_clue->Y_Main_Hist)[16])>bean_th && ((SmartPic_clue->Y_Main_Hist)[17])>bean_th &&
#endif


#if 0 //. can't use rtd_t_inl in kernel
			rtd_t_inl(di_im_di_si_film_motion_next_h_t_RBUS, DI_IM_DI_SI_FILM_MOTION_NEXT_H_T_reg).regValue>0x500 &&
			rtd_t_inl(di_im_di_si_film_motion_next_h_m_RBUS, DI_IM_DI_SI_FILM_MOTION_NEXT_H_M_reg).regValue>0x500 &&
			rtd_t_inl(di_im_di_si_film_motion_next_h_b_RBUS, DI_IM_DI_SI_FILM_MOTION_NEXT_H_B_reg).regValue>0x500 )
#else
			next_h_t.regValue>0x500 &&
			next_h_m.regValue>0x500 &&
			next_h_b.regValue>0x500 )
#endif
		{
			BeanCount++;
		}
	}

	if ( BeanCount == 0 )
	{
		di_control_reg.ma_preferintra = 0;
		#if defined (VIP_TEST_MODE)
		if ( en_BeanTest == 1 ) {
			debug_mode_reg.ma_debugmode = 0; //Thur test 20070807
		}
		#endif
	}


	scaler_rtd_outl(DI_IM_DI_CONTROL_reg, di_control_reg.regValue);

	#if defined (VIP_TEST_MODE)
         scaler_rtd_outl(DI_IM_DI_DEBUG_MODE_reg, debug_mode_reg.regValue); //Thur test 20070807
	#endif
}



/**
 * AutoMA beer problem case
 *
 * @param	en_test: debug mode
 * @return	void
 */
int scalerVIP_colorMABeerProblem(unsigned int en_test)
{
	static unsigned char flag_same = 0;
	unsigned char en_BeerTest = 0;
	unsigned char film_still = 0;

       unsigned int total_motion;
       unsigned int large_pixel;
       unsigned int large_motion;
	unsigned int film_motion_c;
	unsigned int film_motion;

	di_im_di_control_RBUS di_control_reg;
	di_im_di_debug_mode_RBUS debug_mode_reg;//20070807 Thur test for debug mode
	di_im_di_ma_frame_motion_th_a_RBUS frame_motion_a_reg;// frame motion a
	di_im_di_ma_frame_motion_th_b_RBUS frame_motion_b_reg;// frame motion b
	di_im_di_ma_frame_motion_th_c_RBUS frame_motion_c_reg;// frame motion c

	frame_motion_a_reg.regValue = rtd_inl(DI_IM_DI_MA_FRAME_MOTION_TH_A_reg);
	frame_motion_b_reg.regValue = rtd_inl(DI_IM_DI_MA_FRAME_MOTION_TH_B_reg);
	frame_motion_c_reg.regValue = rtd_inl(DI_IM_DI_MA_FRAME_MOTION_TH_C_reg);

	//di_im_di_rtnr_k_RBUS RecursiveTemporalK_RBUS_reg;//20090325 jason9.ccc// mark for keep rtnr k free March 20100716
//	di_im_di_rtnr_control_RBUS di_im_di_rtnr_control_RBUS_reg;

     //  RecursiveTemporalK_RBUS_reg.regValue = scaler_rtd_inl(DI_IM_DI_RTNR_K_reg);// mark for keep rtnr k free March 20100716
//	di_im_di_rtnr_control_RBUS_reg.regValue = rtd_inl(DI_IM_DI_RTNR_CONTROL_reg);

	//scalerDrvPrint( "enter scalerVIP_colorMABeerProblem\n" );

	di_control_reg.regValue = scaler_rtd_inl(DI_IM_DI_CONTROL_reg);//MA control mode
	debug_mode_reg.regValue = scaler_rtd_inl(DI_IM_DI_DEBUG_MODE_reg);//20070807 Thur Test

	en_BeerTest = (en_test<<30)>>31;

#ifndef CONFIG_RTK_KDEV_VGIP_INTERRUPT//can't use rtd_t_inl in kernel
	total_motion = rtd_t_inl(di_im_di_si_ma_total_fm_sum_RBUS,DI_IM_DI_SI_MA_TOTAL_FM_SUM_reg).total_frame_motion_sum;
	large_pixel = rtd_t_inl(di_im_di_si_ma_large_fm_pixel_RBUS,DI_IM_DI_SI_MA_LARGE_FM_PIXEL_reg).large_frame_motion_pixel;
	large_motion = rtd_t_inl(di_im_di_si_ma_large_fm_sum_RBUS,DI_IM_DI_SI_MA_LARGE_FM_SUM_reg).large_frame_motion_sum;
	film_motion_c = rtd_t_inl(di_im_di_si_film_motion_c_RBUS,DI_IM_DI_SI_FILM_MOTION_C_reg).film_motionstatus_259_240;
	film_motion = rtd_t_inl(di_im_di_si_film_motion_RBUS,DI_IM_DI_SI_FILM_MOTION_reg).film_motionstatus_399_380;
#else
	di_im_di_si_ma_total_fm_sum_RBUS	ma_total_fm_sum;
	di_im_di_si_ma_large_fm_pixel_RBUS	ma_large_fm_pixel;
	di_im_di_si_ma_large_fm_sum_RBUS	ma_large_fm_sum;
	di_im_di_si_film_motion_c_RBUS		di_si_film_motion_c;
	di_im_di_si_film_motion_RBUS		di_si_film_motion;

	ma_total_fm_sum.regValue = rtd_inl(DI_IM_DI_SI_MA_TOTAL_FM_SUM_reg);
	ma_large_fm_pixel.regValue = rtd_inl(DI_IM_DI_SI_MA_LARGE_FM_PIXEL_reg);
	ma_large_fm_sum.regValue = rtd_inl(DI_IM_DI_SI_MA_LARGE_FM_SUM_reg);
	di_si_film_motion_c.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_C_reg);
	di_si_film_motion.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_reg);

	total_motion = ma_total_fm_sum.total_frame_motion_sum;
	large_pixel = ma_large_fm_pixel.large_frame_motion_pixel;
	large_motion = ma_large_fm_sum.large_frame_motion_sum;
	film_motion_c = di_si_film_motion_c.film_motionstatus_259_240;
	film_motion = di_si_film_motion.film_motionstatus_399_380;
#endif

	//scalerDrvPrint("============== BEER : %d (tm: %d, lp : %d, lm : %d, fmc : %d)=============\n", film_still, total_motion, large_pixel, large_motion, film_motion_c);
	if (total_motion<800 && large_pixel<70 && large_motion<150 && film_motion_c<5)
	{
		flag_same = 1;

		//frame_motion_a_reg.regValue = 0x18191616; //0x04050202;
		//frame_motion_b_reg.regValue = 0x281E1A20; //0x140a060c;
		//frame_motion_c_reg.regValue = 0x4E28242C; //0x3a141018;
		//rtd_outl(DI_IM_DI_MA_FRAME_MOTION_TH_A_reg, frame_motion_a_reg.regValue);
		//rtd_outl(DI_IM_DI_MA_FRAME_MOTION_TH_B_reg, frame_motion_b_reg.regValue);
		//rtd_outl(DI_IM_DI_MA_FRAME_MOTION_TH_C_reg, frame_motion_c_reg.regValue);

		//---enable crct2----
		/*
		#ifdef CONFIG_RTNR_Use_Correction_2
			di_im_di_rtnr_control_RBUS_reg.cp_rtnr_rounding_correction = 0;
			di_im_di_rtnr_control_RBUS_reg.cp_rtnr_rounding_correction2_en= 1;
		#else // add this condition to force original correction 2 into correction 1, 2010015 Jerry Wu
			di_im_di_rtnr_control_RBUS_reg.cp_rtnr_rounding_correction = 1;
			di_im_di_rtnr_control_RBUS_reg.cp_rtnr_rounding_correction2_en= 0;
		#endif
		*/
//		rtd_outl(DI_IM_DI_RTNR_CONTROL_reg, di_im_di_rtnr_control_RBUS_reg.regValue);//rtnr

		#if defined (VIP_TEST_MODE)
		if ( en_BeerTest == 1 )
		{
			debug_mode_reg.ma_debugmode = 1; //Thur test 20070807
		}
		#endif

		BeerCount++;
	}
	else if (film_motion<20 || (film_motion_c < 5 && total_motion < 25000))
	{
		flag_same = 1;
		film_still = 1;
		BeerCount++;
	}
	else
	{
		if ( flag_same == 1 )
		{
			flag_same = 0;

			scalerVIP_colorMAQuickSetTh(5);

			di_control_reg.ma_controlmode = 1;
			di_control_reg.write_enable_0 = 1;

			#if defined (VIP_TEST_MODE)
			if ( en_BeerTest == 1 )
			{
				debug_mode_reg.ma_debugmode = 0; //Thur test 20070807
			}
			#endif
			/*
			//---enable crct1----
			di_im_di_rtnr_control_RBUS_reg.cp_rtnr_rounding_correction = 1;
			di_im_di_rtnr_control_RBUS_reg.cp_rtnr_rounding_correction2_en= 0;
			*/
//			rtd_outl(DI_IM_DI_RTNR_CONTROL_reg, di_im_di_rtnr_control_RBUS_reg.regValue);//rtnr

		}

		if (BeerCount>0)
			BeerCount--;
		if (BeerFlag)
		{
			if (BeerCount > 20)
				BeerCount -=20;
			else
			BeerCount = 0;
		}
	}

	if (BeerCount > 50)
	{
		if (BeerFlag == 0)
		{
			CaveCount =0;
			if(AutoMADebugMsg==1)
				scalerDrvPrint("============== INTO BEER : %d (tm: %d, lp : %d, lm : %d, fmc : %d)=============\n", film_still, total_motion, large_pixel, large_motion, film_motion_c);
		}
		BeerCount  = 50;
		BeerFlag = 1;
	}
	if (BeerCount == 0)
	{
		if (BeerFlag == 1)
		{
			ZoomInCount = 0;
			PanInCount = 0;
			if(AutoMADebugMsg==1)
				scalerDrvPrint("============== LEAVE BEER =============\n");
		}
		BeerFlag = 0;
	}

	if (BeerFlag)
	{
		frame_motion_a_reg.regValue = 0x18190216;//0x18191616; //0x04050202;
		frame_motion_b_reg.regValue = 0x281E1A0C;//0x281E1A20; //0x140a060c;
		frame_motion_c_reg.regValue = 0x3E282418;//0x3E28242C; //0x3a141018;


		if (film_still)
		{
			frame_motion_a_reg.regValue = 0x38393636; //0x04050202;
			frame_motion_b_reg.regValue = 0x483E3A40; //0x140a060c;
			frame_motion_c_reg.regValue = 0x5E48444C; //0x3a141018;

		}

		rtd_outl(DI_IM_DI_MA_FRAME_MOTION_TH_A_reg, frame_motion_a_reg.regValue);
		rtd_outl(DI_IM_DI_MA_FRAME_MOTION_TH_B_reg, frame_motion_b_reg.regValue);
		rtd_outl(DI_IM_DI_MA_FRAME_MOTION_TH_C_reg, frame_motion_c_reg.regValue);

		//drvif_color_ma_TeethCheck(0);
/*		// mark for keep rtnr k free March 20100716
		if( SCALER_GET_RTNR_MODE(_CHANNEL1) )
		{
			RecursiveTemporalK_RBUS_reg.cp_temporal_y_k0=0;
			RecursiveTemporalK_RBUS_reg.cp_temporal_c_k0=0;
			scaler_rtd_outl(DI_IM_DI_RTNR_K_reg, RecursiveTemporalK_RBUS_reg.regValue);
		}
		*/
	}
	else
	{
		scalerVIP_colorMAQuickSetTh(5);

		di_control_reg.ma_controlmode = 1;// write_enable[2]
		di_control_reg.write_enable_0 = 1;


		//drvif_color_ma_TeethCheck(3);
/* 		// mark for keep rtnr k free March 20100716
		if( SCALER_GET_RTNR_MODE(_CHANNEL1) )
		{
			RecursiveTemporalK_RBUS_reg.cp_temporal_y_k0=1;
			RecursiveTemporalK_RBUS_reg.cp_temporal_c_k0=1;
			scaler_rtd_outl(DI_IM_DI_RTNR_K_reg, RecursiveTemporalK_RBUS_reg.regValue);
		}
		*/
	}

	/* henry @ mac5 161219 DI write enable bit */
	//di_control_reg.regValue = di_control_reg.regValue | DI_IM_DI_CONTROL_write_enable_0_mask;
	di_control_reg.write_enable_0 = 1;
	scaler_rtd_outl(DI_IM_DI_CONTROL_reg, di_control_reg.regValue);

	#if defined (VIP_TEST_MODE)
		scaler_rtd_outl(DI_IM_DI_DEBUG_MODE_reg, debug_mode_reg.regValue); //Thur test 20070807
	#endif

	return BeerFlag;
}


int drvif_color_Zoom(void)
{
	unsigned int cur_total_motion;
	unsigned int film_motion_c, film_motion_top, film_motion_bot, film_motion_left, film_motion_right;

	static unsigned char counter = 0;
	static unsigned char ZoomInFlag = 0;

	di_im_di_control_RBUS di_control_reg;
	di_im_di_ma_frame_motion_th_a_RBUS frame_motion_a_reg;// frame motion a
	di_im_di_ma_frame_motion_th_b_RBUS frame_motion_b_reg;// frame motion b
	di_im_di_ma_frame_motion_th_c_RBUS frame_motion_c_reg;// frame motion c

	frame_motion_a_reg.regValue = rtd_inl(DI_IM_DI_MA_FRAME_MOTION_TH_A_reg);
	frame_motion_b_reg.regValue = rtd_inl(DI_IM_DI_MA_FRAME_MOTION_TH_B_reg);
	frame_motion_c_reg.regValue = rtd_inl(DI_IM_DI_MA_FRAME_MOTION_TH_C_reg);


#ifndef CONFIG_RTK_KDEV_VGIP_INTERRUPT//can't use rtd_t_inl in kernel
       cur_total_motion = rtd_t_inl(di_im_di_si_ma_total_fm_sum_RBUS,DI_IM_DI_SI_MA_TOTAL_FM_SUM_reg).total_frame_motion_sum;
	film_motion_c = rtd_t_inl(di_im_di_si_film_motion_c_RBUS,DI_IM_DI_SI_FILM_MOTION_C_reg).film_motionstatus_259_240;
	film_motion_top = rtd_t_inl(di_im_di_si_film_motion_h_t_RBUS,DI_IM_DI_SI_FILM_MOTION_H_T_reg).film_motionstatus_379_360;
	film_motion_bot = rtd_t_inl(di_im_di_si_film_motion_h_b_RBUS,DI_IM_DI_SI_FILM_MOTION_H_B_reg).film_motionstatus_339_320;
	film_motion_left = rtd_t_inl(di_im_di_si_film_motion_v_l_RBUS,DI_IM_DI_SI_FILM_MOTION_V_L_reg).film_motionstatus_319_300;
	film_motion_right = rtd_t_inl(di_im_di_si_film_motion_v_r_RBUS,DI_IM_DI_SI_FILM_MOTION_V_R_reg).film_motionstatus_279_260;
#else
	di_im_di_si_ma_total_fm_sum_RBUS	ma_total_fm_sum;
	di_im_di_si_film_motion_c_RBUS		di_si_film_motion_c;
	di_im_di_si_film_motion_h_t_RBUS		di_si_film_motion_h_t;
	di_im_di_si_film_motion_h_b_RBUS	di_si_film_motion_h_b;
	di_im_di_si_film_motion_v_l_RBUS		di_si_film_motion_v_l;
	di_im_di_si_film_motion_v_r_RBUS		di_si_film_motion_v_r;

	ma_total_fm_sum.regValue = rtd_inl(DI_IM_DI_SI_MA_TOTAL_FM_SUM_reg);
	di_si_film_motion_c.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_C_reg);
	di_si_film_motion_h_t.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_H_T_reg);
	di_si_film_motion_h_b.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_H_B_reg);
	di_si_film_motion_v_l.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_V_L_reg);
	di_si_film_motion_v_r.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_V_R_reg);

       cur_total_motion = ma_total_fm_sum.total_frame_motion_sum;
	film_motion_c = di_si_film_motion_c.film_motionstatus_259_240;
	film_motion_top = di_si_film_motion_h_t.film_motionstatus_379_360;
	film_motion_bot = di_si_film_motion_h_b.film_motionstatus_339_320;
	film_motion_left = di_si_film_motion_v_l.film_motionstatus_319_300;
	film_motion_right = di_si_film_motion_v_r.film_motionstatus_279_260;
#endif

	di_control_reg.regValue = rtd_inl(DI_IM_DI_CONTROL_reg);//MA control mode

	if (counter < 10)
	{
		counter++;
		cur_total_motion_sum += cur_total_motion;
	}
	else
	{
		counter = 0;

		if (cur_total_motion_sum > pre_total_motion_sum)
			ZoomInCount++;
		else
		{
			if (ZoomInCount>2)
				ZoomInCount-=2;
			else
				ZoomInCount=0;
		}

		pre_total_motion_sum = cur_total_motion_sum;
		cur_total_motion_sum = 0;
	}

	if (ZoomInCount > 15)
	{
		ZoomInCount = 15;
        	if (ZoomInFlag == 0)
			VIP_DEBUG_PRINTF(" ====== INTO Zoom Statement =======\n");
		ZoomInFlag = 1;
	}
	if (ZoomInCount == 0)
	{
        	if (ZoomInFlag == 1)
			VIP_DEBUG_PRINTF(" ====== LEAVE Zoom Statement =======\n");
		ZoomInFlag = 0;
	}
	//if((MA_print_count % 30) == 0)
	//VIP_DEBUG_PRINTF("[Zoom]=== %d, %d : %d : %d : %d : %d : %d ===\n", cur_total_motion_sum, pre_total_motion_sum, ZoomInFlag, film_motion_c, film_motion_top, film_motion_bot, film_motion_left, film_motion_right);

	if (ZoomInFlag && film_motion_c < 800)// && film_motion_top > 4 && film_motion_bot > 4 && film_motion_left > 4 && film_motion_right > 4)
	{
		di_control_reg.ma_onedirectionweaveen = 0;

		rtd_outl(DI_IM_DI_CONTROL_reg, di_control_reg.regValue);

		frame_motion_a_reg.regValue = 0x38393636; //0x04050202;
		frame_motion_b_reg.regValue = 0x483E3A40; //0x140a060c;
		frame_motion_c_reg.regValue = 0x5E48444C; //0x3a141018;

		rtd_outl(DI_IM_DI_MA_FRAME_MOTION_TH_A_reg, frame_motion_a_reg.regValue);
		rtd_outl(DI_IM_DI_MA_FRAME_MOTION_TH_B_reg, frame_motion_b_reg.regValue);
		rtd_outl(DI_IM_DI_MA_FRAME_MOTION_TH_C_reg, frame_motion_c_reg.regValue);
	}
	else
	{
		di_control_reg.ma_onedirectionweaveen = 1;

		rtd_outl(DI_IM_DI_CONTROL_reg, di_control_reg.regValue);

		scalerVIP_colorMAQuickSetTh(5);
	}

	return ZoomInFlag;
}

void scaleVIP_color_tnrxc(unsigned char display, unsigned char Level)
{
	//Level = 0~8
	di_im_di_tnr_xc_control_RBUS TNR_XC_reg;
	di_im_di_tnr_th_RBUS Temporal_Thl_reg;
	TNR_XC_reg.regValue = scaler_rtd_inl(DI_IM_DI_TNR_XC_CONTROL_reg);
	Temporal_Thl_reg.regValue = scaler_rtd_inl(DI_IM_DI_TNR_TH_reg);

	if(display == 0) //main
	{
		if (Level==0)
		{
			TNR_XC_reg.cp_temporal_xc_en = 0;
		}
		else if (Level>=8)
		{
			TNR_XC_reg.cp_temporal_xc_en = 1;
			Temporal_Thl_reg.cp_temporalthly = 0xff;
		}
		else
		{
			TNR_XC_reg.cp_temporal_xc_en = 1;
			Temporal_Thl_reg.cp_temporalthly = 1<<Level;
		}
	}

	//20150805 roger, temporalenable must follow cp_temporal_xc_en
	di_im_di_control_RBUS di_control_reg;
	di_control_reg.regValue = rtd_inl(DI_IM_DI_CONTROL_reg);
	di_control_reg.cp_temporalenable = TNR_XC_reg.cp_temporal_xc_en;// write_enable[18]


	/* henry @ mac5 161219 DI write enable bit */
	//di_control_reg.regValue = di_control_reg.regValue | DI_IM_DI_CONTROL_write_enable_6_mask;
	di_control_reg.write_enable_6 = 1;

	rtd_outl(DI_IM_DI_CONTROL_reg, di_control_reg.regValue);

	rtd_outl(DI_IM_DI_TNR_XC_CONTROL_reg, TNR_XC_reg.regValue);
	rtd_outl(DI_IM_DI_TNR_TH_reg, Temporal_Thl_reg.regValue);

}

#if 0
unsigned char scalerVIP_Pan_Detector(void)
{
	unsigned int temp = 0, MaxValue_Pan= 0, SecondMaxValue_Pan = 0, Sum_Pan_Count =0, Pan_Count_Ratio = 0;
	unsigned char MAX_Pan_index = 0, SecondMax_Pan_index = 0, i=0;
	static unsigned char Pan_ratio_counter = 0;
	unsigned char Pan_flag=0;

	//condiction defined
	static unsigned int Pan_ratio_th = 70;
	unsigned char Pan_ratio_counter_th = 5,Pan_counter_th_upbound = 10 ;

//===========================================================
//========================Motion Pan Check =======================
//===========================================================
	di_im_di_pan_detection_statistic_1_RBUS im_di_pan_detection_statistic_1_reg;
	di_im_di_pan_detection_statistic_2_RBUS im_di_pan_detection_statistic_2_reg;
	di_im_di_pan_detection_statistic_3_RBUS im_di_pan_detection_statistic_3_reg;
	di_im_di_pan_detection_statistic_4_RBUS im_di_pan_detection_statistic_4_reg;
	di_im_di_pan_detection_statistic_5_RBUS im_di_pan_detection_statistic_5_reg;
	di_im_di_pan_detection_statistic_6_RBUS im_di_pan_detection_statistic_6_reg;
	di_im_di_pan_detection_statistic_7_RBUS im_di_pan_detection_statistic_7_reg;
	di_im_di_pan_detection_statistic_8_RBUS im_di_pan_detection_statistic_8_reg;
	di_im_di_pan_detection_statistic_9_RBUS im_di_pan_detection_statistic_9_reg;
	di_im_di_pan_detection_statistic_10_RBUS im_di_pan_detection_statistic_10_reg;
	di_im_di_pan_detection_statistic_11_RBUS im_di_pan_detection_statistic_11_reg;
	di_im_di_pan_detection_statistic_12_RBUS im_di_pan_detection_statistic_12_reg;
	di_im_di_pan_detection_statistic_13_RBUS im_di_pan_detection_statistic_13_reg;
	di_im_di_pan_detection_statistic_14_RBUS im_di_pan_detection_statistic_14_reg;
	di_im_di_pan_detection_statistic_15_RBUS im_di_pan_detection_statistic_15_reg;
	di_im_di_pan_detection_statistic_16_RBUS im_di_pan_detection_statistic_16_reg;
	di_im_di_pan_detection_statistic_17_RBUS im_di_pan_detection_statistic_17_reg;

	im_di_pan_detection_statistic_1_reg.regValue = rtd_inl(DI_IM_DI_PAN_DETECTION_STATISTIC_1_reg);
	im_di_pan_detection_statistic_2_reg.regValue = rtd_inl(DI_IM_DI_PAN_DETECTION_STATISTIC_2_reg);
	im_di_pan_detection_statistic_3_reg.regValue = rtd_inl(DI_IM_DI_PAN_DETECTION_STATISTIC_3_reg);
	im_di_pan_detection_statistic_4_reg.regValue = rtd_inl(DI_IM_DI_PAN_DETECTION_STATISTIC_4_reg);
	im_di_pan_detection_statistic_5_reg.regValue = rtd_inl(DI_IM_DI_PAN_DETECTION_STATISTIC_5_reg);
	im_di_pan_detection_statistic_6_reg.regValue = rtd_inl(DI_IM_DI_PAN_DETECTION_STATISTIC_6_reg);
	im_di_pan_detection_statistic_7_reg.regValue = rtd_inl(DI_IM_DI_PAN_DETECTION_STATISTIC_7_reg);
	im_di_pan_detection_statistic_8_reg.regValue = rtd_inl(DI_IM_DI_PAN_DETECTION_STATISTIC_8_reg);
	im_di_pan_detection_statistic_9_reg.regValue = rtd_inl(DI_IM_DI_PAN_DETECTION_STATISTIC_9_reg);
	im_di_pan_detection_statistic_10_reg.regValue = rtd_inl(DI_IM_DI_PAN_DETECTION_STATISTIC_10_reg);
	im_di_pan_detection_statistic_11_reg.regValue = rtd_inl(DI_IM_DI_PAN_DETECTION_STATISTIC_11_reg);
	im_di_pan_detection_statistic_12_reg.regValue = rtd_inl(DI_IM_DI_PAN_DETECTION_STATISTIC_12_reg);
	im_di_pan_detection_statistic_13_reg.regValue = rtd_inl(DI_IM_DI_PAN_DETECTION_STATISTIC_13_reg);
	im_di_pan_detection_statistic_14_reg.regValue = rtd_inl(DI_IM_DI_PAN_DETECTION_STATISTIC_14_reg);
	im_di_pan_detection_statistic_15_reg.regValue = rtd_inl(DI_IM_DI_PAN_DETECTION_STATISTIC_15_reg);
	im_di_pan_detection_statistic_16_reg.regValue = rtd_inl(DI_IM_DI_PAN_DETECTION_STATISTIC_16_reg);
	im_di_pan_detection_statistic_17_reg.regValue = rtd_inl(DI_IM_DI_PAN_DETECTION_STATISTIC_17_reg);

	for(i=0;i<33;i++)//read hor 8 counters
	{
		switch(i)
		{
			case 0:
				temp = im_di_pan_detection_statistic_9_reg.hmc_r16_pixelsum;
				break;
			case 1:
				temp = im_di_pan_detection_statistic_9_reg.hmc_r15_pixelsum;
				break;
			case 2:
				temp = im_di_pan_detection_statistic_10_reg.hmc_r14_pixelsum;
				break;
			case 3:
				temp = im_di_pan_detection_statistic_10_reg.hmc_r13_pixelsum;
				break;
			case 4:
				temp = im_di_pan_detection_statistic_11_reg.hmc_r12_pixelsum;
				break;
			case 5:
				temp = im_di_pan_detection_statistic_11_reg.hmc_r11_pixelsum;
				break;
			case 6:
				temp = im_di_pan_detection_statistic_12_reg.hmc_r10_pixelsum;
				break;
			case 7:
				temp = im_di_pan_detection_statistic_12_reg.hmc_r9_pixelsum;
				break;
			case 8:
				temp = im_di_pan_detection_statistic_13_reg.hmc_r8_pixelsum;
				break;
	    		case 9:
				temp = im_di_pan_detection_statistic_1_reg.hmc_r7_pixelsum;
				break;
			case 10:
				temp = im_di_pan_detection_statistic_1_reg.hmc_r6_pixelsum;
				break;
			case 11:
				temp = im_di_pan_detection_statistic_2_reg.hmc_r5_pixelsum;
				break;
			case 12:
				temp = im_di_pan_detection_statistic_2_reg.hmc_r4_pixelsum;
				break;
			case 13:
				temp = im_di_pan_detection_statistic_3_reg.hmc_r3_pixelsum;
				break;
			case 14:
				temp = im_di_pan_detection_statistic_3_reg.hmc_r2_pixelsum;
				break;
			case 15:
				temp = im_di_pan_detection_statistic_4_reg.hmc_r1_pixelsum;
				break;
			case 16:
				temp = im_di_pan_detection_statistic_4_reg.hmc_c0_pixelsum;
				break;
			case 17:
				temp = im_di_pan_detection_statistic_5_reg.hmc_l1_pixelsum;
				break;
			case 18:
				temp = im_di_pan_detection_statistic_5_reg.hmc_l2_pixelsum;
				break;
			case 19:
				temp = im_di_pan_detection_statistic_6_reg.hmc_l3_pixelsum;
				break;
			case 20:
				temp = im_di_pan_detection_statistic_6_reg.hmc_l4_pixelsum;
				break;
			case 21:
				temp = im_di_pan_detection_statistic_7_reg.hmc_l5_pixelsum;
				break;
			case 22:
				temp = im_di_pan_detection_statistic_7_reg.hmc_l6_pixelsum;
				break;
			case 23:
				temp = im_di_pan_detection_statistic_8_reg.hmc_l7_pixelsum;
				break;
			case 24:
				temp = im_di_pan_detection_statistic_13_reg.hmc_l8_pixelsum;
				break;
			case 25:
				temp = im_di_pan_detection_statistic_14_reg.hmc_l9_pixelsum;
				break;
			case 26:
				temp = im_di_pan_detection_statistic_14_reg.hmc_l10_pixelsum;
				break;
			case 27:
				temp = im_di_pan_detection_statistic_15_reg.hmc_l11_pixelsum;
				break;
			case 28:
				temp = im_di_pan_detection_statistic_15_reg.hmc_l12_pixelsum;
				break;
			case 29:
				temp = im_di_pan_detection_statistic_16_reg.hmc_l13_pixelsum;
				break;
			case 30:
				temp = im_di_pan_detection_statistic_16_reg.hmc_l14_pixelsum;
				break;
			case 31:
				temp = im_di_pan_detection_statistic_17_reg.hmc_l15_pixelsum;
				break;
			case 32:
				temp = im_di_pan_detection_statistic_17_reg.hmc_l16_pixelsum;
				break;
    		}

		Sum_Pan_Count =Sum_Pan_Count + temp;

		if(MaxValue_Pan <= temp)
		{
			SecondMaxValue_Pan = MaxValue_Pan;
			MaxValue_Pan = temp;
			MAX_Pan_index = i;
		}
		else if(SecondMaxValue_Pan <= temp)
		{
			SecondMaxValue_Pan = temp;
			SecondMax_Pan_index = i;
		}
	}

	if(Sum_Pan_Count!=0)
		Pan_Count_Ratio = (MaxValue_Pan*100)/Sum_Pan_Count ;

	if(MAX_Pan_index!=16)
	{
		if(Pan_Count_Ratio>=Pan_ratio_th)
		{
			Pan_ratio_counter = (Pan_ratio_counter>=Pan_counter_th_upbound)?Pan_counter_th_upbound:(Pan_ratio_counter+1);
		}
		else
		{
			Pan_ratio_counter = (Pan_ratio_counter<=0)?0:(Pan_ratio_counter-1);
		}
	}
	else
	{
		Pan_ratio_counter = (Pan_ratio_counter<=0)?0:(Pan_ratio_counter-1);
	}

	if(Pan_ratio_counter > Pan_ratio_counter_th)
	{
		Pan_flag = 1;
		Pan_ratio_th = 40;
	}
	else
	{
		Pan_flag = 0;
		Pan_ratio_th =70;
	}
	return Pan_flag;
}
#endif

void scalerVIP_DI_Dynamic_VDNoise_FrameMotion()
{
/*
	This function is consider VD Noise to dynamic adjust DI frame motion
	VD noise table
	noise_gen		noise value	frame motion
	0_0				0x32
	0_2				0x29
	0_4				0x20
	0_6				0x1a
	0_8				0x15
	0_10/10_0		0x10		+0x10
	10_2			0x0c				+0xc
	10_4			0x0a			+0x8
	10_6			0x07		+0x5
	10_8			0x06			+0x2
	10_10/20_0		0x04		default 0x04050202
	20_2			0x03
	20_4			0x03
	20_6			0x02
	20_8			0x01
	20_10/30_0		0x01

*/

	unsigned int FM_bias;
	vdtop_noise_status_RBUS noise_status_reg;

	di_im_di_ma_frame_motion_th_a_RBUS frame_motion_a_reg;// frame motion a
	di_im_di_ma_frame_motion_th_b_RBUS frame_motion_b_reg;// frame motion b
	di_im_di_ma_frame_motion_th_c_RBUS frame_motion_c_reg;// frame motion c

	frame_motion_a_reg.regValue = rtd_inl(DI_IM_DI_MA_FRAME_MOTION_TH_A_reg);
	frame_motion_b_reg.regValue = rtd_inl(DI_IM_DI_MA_FRAME_MOTION_TH_B_reg);
	frame_motion_c_reg.regValue = rtd_inl(DI_IM_DI_MA_FRAME_MOTION_TH_C_reg);

	noise_status_reg.regValue = VDPQ_rtd_inl(VDTOP_NOISE_STATUS_reg);

	if (noise_status_reg.status_noise > 0x04 && noise_status_reg.status_noise <= 0x06)
		FM_bias = 0x02020202;
	else if (noise_status_reg.status_noise > 0x06 && noise_status_reg.status_noise <= 0x07)
		FM_bias = 0x05050505;
	else if (noise_status_reg.status_noise > 0x07 && noise_status_reg.status_noise <= 0x0a)
		FM_bias = 0x08080808;
	else if (noise_status_reg.status_noise > 0x0a && noise_status_reg.status_noise <= 0x0c)
		FM_bias = 0x0c0c0c0c;
	else if (noise_status_reg.status_noise > 0x0c /*&& noise_status_reg.status_noise <= 0x10*/)
		FM_bias = 0x10101010;
	else
		FM_bias = 0x0;

//	VIP_DEBUG_PRINTF("======================= FM_bias = %d\n", FM_bias);
	frame_motion_a_reg.regValue = 0x04050202+FM_bias; //0x04050202;
	frame_motion_b_reg.regValue = 0x140a060c+FM_bias; //0x140a060c;
	frame_motion_c_reg.regValue = 0x3a141018+FM_bias; //0x3a141018;

	rtd_outl(DI_IM_DI_MA_FRAME_MOTION_TH_A_reg, frame_motion_a_reg.regValue);
	rtd_outl(DI_IM_DI_MA_FRAME_MOTION_TH_B_reg, frame_motion_b_reg.regValue);
	rtd_outl(DI_IM_DI_MA_FRAME_MOTION_TH_C_reg, frame_motion_c_reg.regValue);
}

void scalerVIP_DI_Dynamic_Status_Adjust_by_Global_Motion(MOTION_LEVEL motion_level_flag)
{
	di_im_di_btr_control_RBUS BTR_Control_Reg;

	BTR_Control_Reg.regValue = rtd_inl(DI_IM_DI_BTR_CONTROL_reg);
	if (btr_control == 2) // not assign
	{
		btr_control = BTR_Control_Reg.btr_blendtemporalrecoveryen;
	}

	rtd_clearbits(DI_IM_DI_MPEG_SEQUENCE_APP_reg, _BIT3);
	rtd_clearbits(DI_IM_DI_MPEG_SEQUENCE_APP_reg, _BIT4);
	rtd_clearbits(DI_IM_DI_MPEG_SEQUENCE_APP_reg, _BIT5);
	rtd_clearbits(DI_IM_DI_MPEG_SEQUENCE_APP_reg, _BIT6);

	switch (motion_level_flag)
	{
		case MOTION_LEVEL_VERY_STILL:
			rtd_setbits(DI_IM_DI_MPEG_SEQUENCE_APP_reg, _BIT3);
			BTR_Control_Reg.btr_blendtemporalrecoveryen = 0;
			break;
		case MOTION_LEVEL_STILL:
			rtd_setbits(DI_IM_DI_MPEG_SEQUENCE_APP_reg, _BIT4);
			BTR_Control_Reg.btr_blendtemporalrecoveryen = 0;
			break;
		case MOTION_LEVEL_SLOW_MOTION:
			rtd_setbits(DI_IM_DI_MPEG_SEQUENCE_APP_reg, _BIT5);
			if (btr_control)
			{
				BTR_Control_Reg.btr_blendtemporalrecoveryen = 1;
			}
			break;
		case MOTION_LEVEL_MOTION:
			rtd_setbits(DI_IM_DI_MPEG_SEQUENCE_APP_reg, _BIT6);
			if (btr_control)
			{
				BTR_Control_Reg.btr_blendtemporalrecoveryen = 1;
			}
			break;
		default:
			break;
	}


	rtd_outl(DI_IM_DI_BTR_CONTROL_reg, BTR_Control_Reg.regValue);
}

//////////////////// FM Film ///////////////////////////////
static void scalerVIP_film_FWmode()
{
	FILM_FWMode DetInfo;

	DetInfo = DETECTION_scalerVIP_film_FWmode();

	APPLY_scalerVIP_film_FWmode_isr(DetInfo);
}

//int Count=0;
static unsigned char HFT_prev=1;//,HFT_prev_H1=1,HFT_prev_H2=1,HFT_prev_H3=1,HFT_prev_V1=1,HFT_prev_V2=1,HFT_prev_V3=1,HFT_prev_C=1;
static unsigned int FW_HFT;
static unsigned int FW_StatusNextHighFreqTerm=0;	// for enchance 22
static unsigned int FW_StatusNextStaticPattern2_film22=0;	// for enchance 22

int scalerVIP_film_FWmode_22all_suspect32_isr(int xFrameStatic){
	switch(xFrameStatic&0x3ff)
	{
		case 0x21:
		case 0x42:
		case 0x84:
		case 0x108:
		case 0x210:
		return 1;
	}
	return 0;
}
void scalerVIP_film_FWmode_detection22q_isr(
	unsigned char NextStaticPattern, unsigned char FramePairPattern,
	unsigned char *ExactMatch, unsigned char *Violate, unsigned int *film_index,
	unsigned char *p22Detected, unsigned int *p22Sequence)
{
	*ExactMatch=0;
	*Violate=0;
	if((NextStaticPattern&3)==1){
		*ExactMatch=1;
		*p22Detected=1;
		*p22Sequence=(fw_DI_3A) ? 2 : 1;
		*film_index=FILM22;
	}else if((NextStaticPattern&3)==2){
		*ExactMatch=1;
		*p22Detected=1;
		*p22Sequence=(fw_DI_3A) ? 1 : 2;
		*film_index=FILM22;
	}else if((FramePairPattern&3)==2){
		*ExactMatch=1;
		*p22Detected=1;
		*p22Sequence=(fw_DI_3A) ? 2 : 1;
		*film_index=FILM22;
	}else if((FramePairPattern&3)==1){
		*ExactMatch=1;
		*p22Detected=1;
		*p22Sequence=(fw_DI_3A) ? 1 : 2;
		*film_index=FILM22;
	}else if((NextStaticPattern&3)==3){
		*ExactMatch=0;
		//*Violate=1;
		*p22Detected=0;
		*p22Sequence=0;
		*film_index=0;
	}else if(p22Sequence[0]==1){
		*p22Sequence=2;
	}else if(p22Sequence[0]==2){
		*p22Sequence=1;
	}
}
void scalerVIP_film_FWmode_Quick_detection_isr(
	int x32enable,
	unsigned int FrameStaticPattern,unsigned int FramePairPattern,
	unsigned char NextStaticPattern,unsigned char NextStaticPattern22,
	unsigned char *ExactMatch321, unsigned char *Violate321, unsigned int *index321,
	unsigned char *p32Detected1, unsigned int *p32Sequence1,
	unsigned char *ExactMatch322, unsigned char *Violate322, unsigned int *index322,
	unsigned char *p32Detected2, unsigned int *p32Sequence2,
	unsigned char *ExactMatch22, unsigned char *Violate22, unsigned int *index22,
	unsigned char *p22Detected, unsigned int *p22Sequence
){
	if(x32enable&&p32Detected2[0]){
		*p22Detected=0;
		*p22Sequence=0;
	}else{
		scalerVIP_film_FWmode_detection22q_isr(
			NextStaticPattern22, FramePairPattern,
			ExactMatch22, Violate22,index22,
			p22Detected, p22Sequence
		);
	}
}
static int framestaticonly;
static FILM_FWMode DETECTION_scalerVIP_film_FWmode()
{
	// fw film setting
	// 0 -> 22 enchance
	// 1 -> FILM3223
	// 2 -> FILM64
	// 3 -> FILM55
	// 4 -> FILM2224
	// 5 -> FILM32322
	// 6 -> FILM87

	/// fw film control setting  ///
	static unsigned char fw_film_control_force_weave_en=0;
	static unsigned int MarkMargin=32;

	static unsigned int Weave_Mode_d=2,StatusFilmWeaveMode=2;

	static unsigned char enchance22_en,film3223_en,film64_en,film55_en,film2224_en,film32322_en,film87_en;
	static unsigned char filmQuick_en;

	// parameters from hw  hw_XXX read from register
	static unsigned char hw_film_Status32Detected1,hw_film_Status32Detected2,hw_film_Status22Detected;
	static unsigned char hw_film_StatusFilmDetected,hw_film_StatusMixedFilmDetected,hw_film_MixedFilmConfuse;
	static unsigned int hw_film_StatusFilmSequence;
	static unsigned char hw_film_VerScrollingText_en,hw_film_thumbnail_en;
	static unsigned int hw_film_32Film,hw_film_22Film;
	static unsigned char hw_film_Enable;
	static unsigned char hw_AdoptHDMethod,hw_RTNR_Interlace_Force2D_En;
	static unsigned char hw_film_BadEditor_flag;
	static unsigned int hw_StatusFrameStaticPattern_All,hw_StatusFramePairPattern_All,hw_StatusPrevStaticPattern_All; // 40c8
	static unsigned int hw_StatusNextStaticPattern_All,hw_StatusPrevStaticPattern2_All,hw_StatusNextStaticPattern2_All,hw_StatusNextFieldMotion_All; //40cc
	static unsigned int hw_StatusPrevFieldMotion_All,hw_StatusPrevFieldMotion_film22_All;
	static unsigned int hw_StatusNextFieldMotion_film22_All,hw_StatusNextStaticPattern_film22_All;
	static unsigned int hw_FieldStaticSumThl,hw_FieldMotionSumThl;
	static unsigned int hw_PrevTopMark,hw_PrevBotMark;
	static unsigned int hw_PrevTopMark2,hw_PrevBotMark2;
	static unsigned int hw_PrevTopMark3,hw_PrevBotMark3;
	static unsigned int hw_NextTopMark,hw_NextBotMark;
	static unsigned int hw_NextTopMark2,hw_NextBotMark2;
	static unsigned int hw_NextTopMark3,hw_NextBotMark3;
	static unsigned int hw_PrevTopMarkp,hw_PrevBotMarkp;
	static unsigned int hw_PrevTopMark2p,hw_PrevBotMark2p;
	static unsigned int hw_PrevTopMark3p,hw_PrevBotMark3p;
	static unsigned int hw_NextTopMarkp,hw_NextBotMarkp;
	static unsigned int hw_NextTopMark2p,hw_NextBotMark2p;
	static unsigned int hw_NextTopMark3p,hw_NextBotMark3p;
	static unsigned int PrevTopLine, PrevBotLine;	// fw match hw
	static unsigned int PrevTopLine2, PrevBotLine2;   // fw match hw
	static unsigned int PrevTopLine3, PrevBotLine3;   // fw match hw
	static unsigned int NextTopLine, NextBotLine;	// fw match hw
	static unsigned int NextTopLine2, NextBotLine2;   // fw match hw
	static unsigned int NextTopLine3, NextBotLine3;   // fw match hw

	// parameters for calculate
	static unsigned char ExactMatch321,ExactMatch321_H1,ExactMatch321_H2,ExactMatch321_H3,ExactMatch321_V1,ExactMatch321_V2,ExactMatch321_V3,ExactMatch321_C;
	static unsigned char Violate321,Violate321_H1,Violate321_H2,Violate321_H3,Violate321_V1,Violate321_V2,Violate321_V3,Violate321_C;
	static unsigned char ExactMatch322,ExactMatch322_H1,ExactMatch322_H2,ExactMatch322_H3,ExactMatch322_V1,ExactMatch322_V2,ExactMatch322_V3,ExactMatch322_C;
	static unsigned char Violate322,Violate322_H1,Violate322_H2,Violate322_H3,Violate322_V1,Violate322_V2,Violate322_V3,Violate322_C;
	static unsigned char ExactMatch22,ExactMatch22_H1,ExactMatch22_H2,ExactMatch22_H3,ExactMatch22_V1,ExactMatch22_V2,ExactMatch22_V3,ExactMatch22_C;
	static unsigned char Violate22,Violate22_H1,Violate22_H2,Violate22_H3,Violate22_V1,Violate22_V2,Violate22_V3,Violate22_C;
	static unsigned char Detected_Sub32, Detected_Sub22;
	static unsigned char Detected_Sub32H, Detected_Sub22H;
	static unsigned char Detected_Sub32V, Detected_Sub22V;
	static unsigned int  Sequence_Sub32, Sequence_Sub22;
	static unsigned int  Sequence_Sub32H, Sequence_Sub22H;
	static unsigned int  Sequence_Sub32V, Sequence_Sub22V;
	static unsigned int Detected_Sub32_Num, Detected_Sub22_Num;
	static unsigned int film_index_Sub32,film_index_Sub22;

	// fw results
	static unsigned int fw_TopLine=0x438,fw_BotLine=0x438;
	static unsigned int fw_TopLine2=0x438,fw_BotLine2=0x438;
	static unsigned int fw_TopLine3=0x438,fw_BotLine3=0x438;

	static unsigned int fw_StatusFilmWeaveMode=2,fw_StatusFilmSequence=0;
	static unsigned char fw_Status32Detected1=0,fw_Status32Detected2=0,fw_Status22Detected=0;
	static unsigned char fw_StatusMixedFilmDetected=0,fw_StatusFilmDetected=0,fw_MixedFilmConfuse=0;
	static unsigned char film_Pair_en_auto,film_Pair1_en,film_Violate_strict_en,film_HiFreq_flag,film32_debounce_FieldNum,film22_debounce_FieldNum;
	static unsigned int StatusFilmSequence_tmp = 0; // considering film double buffer

	// RBUS //
	static di_im_di_control_RBUS im_di_control_reg;
	static di_im_di_film_sawtooth_filmframe_th_RBUS im_di_film_sawtooth_filmframe_th_reg;
	static di_im_di_film_static_sum_th_RBUS im_di_film_static_sum_th_reg;
	static di_im_di_film_motion_sum_th_RBUS im_di_film_motion_sum_th_reg;
	static di_im_di_si_film_final_result_RBUS im_di_si_film_final_result_reg;
	static di_im_di_si_film_pattern_a_RBUS im_di_si_film_pattern_a_reg;
	static di_im_di_si_film_pattern_b_RBUS im_di_si_film_pattern_b_reg;
	static di_im_di_si_film_32_result_1_a_RBUS im_di_si_film_32_result_1_a_reg;
	static di_im_di_si_film_32_result_2_a_RBUS im_di_si_film_32_result_2_a_reg;
	static di_im_di_si_film_22_result_a_RBUS im_di_si_film_22_result_a_reg;
	static di_im_di_si_film22_detector_pattern_RBUS im_di_si_film22_detector_pattern_reg;
	static di_im_di_rtnr_control_RBUS im_di_rtnr_control_reg;

	static di_im_di_film_prev_fieldmotion_RBUS im_di_film_prev_fieldmotion_reg;
	static di_im_di_film_mark_information_RBUS im_di_film_mark_information_reg;
	static di_im_di_film_mark_prev1_RBUS im_di_film_mark_prev1_reg;
	static di_im_di_film_mark_prev2_RBUS im_di_film_mark_prev2_reg;
	static di_im_di_film_mark_prev3_RBUS im_di_film_mark_prev3_reg;
	static di_im_di_film_mark_next1_RBUS im_di_film_mark_next1_reg;
	static di_im_di_film_mark_next2_RBUS im_di_film_mark_next2_reg;
	static di_im_di_film_mark_next3_RBUS im_di_film_mark_next3_reg;
	static di_im_di_film_new_function_main_RBUS im_di_film_new_function_main_reg;	// double buffer use

	// enchance 22 use
	static unsigned char Status22Detected2=0;
	static unsigned int Status22Sequence2=0;
	static unsigned int index22new=0;
	static unsigned int FrameDiff=0xff;

	static unsigned int FW_HFT_thd = 120;//120;//480;		// racer 120
	static float FW_HFT_rato_thd = 0.17;//0.17;//0.3;		// racer 0.17
	static unsigned int FW_HFT_diff_thd = 35;//35;//135;	// racer 35
	static float ratioPrevNext = 10;//10;//5;
	static unsigned int PrevDiffMax,NextDiffMax;
	static unsigned int FrameDiff_H1,FrameDiff_H2,FrameDiff_H3,FrameDiff_V1,FrameDiff_V2,FrameDiff_V3,FrameDiff_C;
	static unsigned int PrevDiff,PrevDiff_H1,PrevDiff_H2,PrevDiff_H3,PrevDiff_V1,PrevDiff_V2,PrevDiff_V3,PrevDiff_C;
	static unsigned int NextDiff,NextDiff_H1,NextDiff_H2,NextDiff_H3,NextDiff_V1,NextDiff_V2,NextDiff_V3,NextDiff_C;
	static unsigned int NextDiff_noH3;
	//enchance 22 detection
	static di_im_di_si_film_motion_RBUS im_di_si_film_motion_reg;
	static di_im_di_si_film_motion_h_t_RBUS im_di_si_film_motion_h_t_reg;
	static di_im_di_si_film_motion_h_m_RBUS im_di_si_film_motion_h_m_reg;
	static di_im_di_si_film_motion_h_b_RBUS im_di_si_film_motion_h_b_reg;
	static di_im_di_si_film_motion_v_l_RBUS im_di_si_film_motion_v_l_reg;
	static di_im_di_si_film_motion_v_m_RBUS im_di_si_film_motion_v_m_reg;
	static di_im_di_si_film_motion_v_r_RBUS im_di_si_film_motion_v_r_reg;
	static di_im_di_si_film_motion_c_RBUS im_di_si_film_motion_c_reg;

	static di_im_di_si_film_motion_next_RBUS im_di_si_film_motion_next_reg; //IM_DI_SI_FILM_MOTION_NEXT
	static di_im_di_si_film_motion_next_h_t_RBUS im_di_si_film_motion_next_h_t_reg; //H1
	static di_im_di_si_film_motion_next_h_m_RBUS im_di_si_film_motion_next_h_m_reg; //H2
	static di_im_di_si_film_motion_next_h_b_RBUS im_di_si_film_motion_next_h_b_reg; //H3
	static di_im_di_si_film_motion_next_v_l_RBUS im_di_si_film_motion_next_v_l_reg; //V1
	static di_im_di_si_film_motion_next_v_m_RBUS im_di_si_film_motion_next_v_m_reg; //V2
	static di_im_di_si_film_motion_next_v_r_RBUS im_di_si_film_motion_next_v_r_reg; //V3
	static di_im_di_si_film_motion_next_c_RBUS im_di_si_film_motion_next_c_reg; //C

	static di_im_di_si_film_motion_pre_RBUS im_di_si_film_motion_pre_reg; //IM_DI_SI_FILM_MOTION_PRE
	static di_im_di_si_film_motion_pre_h_t_RBUS im_di_si_film_motion_pre_h_t_reg; //H1
	static di_im_di_si_film_motion_pre_h_m_RBUS im_di_si_film_motion_pre_h_m_reg; //H2
	static di_im_di_si_film_motion_pre_h_b_RBUS im_di_si_film_motion_pre_h_b_reg; //H3
	static di_im_di_si_film_motion_pre_v_l_RBUS im_di_si_film_motion_pre_v_l_reg; //V1
	static di_im_di_si_film_motion_pre_v_m_RBUS im_di_si_film_motion_pre_v_m_reg; //V2
	static di_im_di_si_film_motion_pre_v_r_RBUS im_di_si_film_motion_pre_v_r_reg; //V3
	static di_im_di_si_film_motion_pre_c_RBUS im_di_si_film_motion_pre_c_reg; //C

	im_di_si_film_motion_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_reg);
	im_di_si_film_motion_h_t_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_H_T_reg);
	im_di_si_film_motion_h_m_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_H_M_reg);
	im_di_si_film_motion_h_b_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_H_B_reg);
	im_di_si_film_motion_v_l_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_V_L_reg);
	im_di_si_film_motion_v_m_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_V_M_reg);
	im_di_si_film_motion_v_r_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_V_R_reg);
	im_di_si_film_motion_c_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_C_reg);

	im_di_si_film_motion_next_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_NEXT_reg);
	im_di_si_film_motion_next_h_t_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_NEXT_H_T_reg);
	im_di_si_film_motion_next_h_m_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_NEXT_H_M_reg);
	im_di_si_film_motion_next_h_b_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_NEXT_H_B_reg);
	im_di_si_film_motion_next_v_l_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_NEXT_V_L_reg);
	im_di_si_film_motion_next_v_m_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_NEXT_V_M_reg);
	im_di_si_film_motion_next_v_r_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_NEXT_V_R_reg);
	im_di_si_film_motion_next_c_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_NEXT_C_reg);

	im_di_si_film_motion_pre_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_PRE_reg);
	im_di_si_film_motion_pre_h_t_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_PRE_H_T_reg);
	im_di_si_film_motion_pre_h_m_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_PRE_H_M_reg);
	im_di_si_film_motion_pre_h_b_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_PRE_H_B_reg);
	im_di_si_film_motion_pre_v_l_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_PRE_V_L_reg);
	im_di_si_film_motion_pre_v_m_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_PRE_V_M_reg);
	im_di_si_film_motion_pre_v_r_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_PRE_V_R_reg);
	im_di_si_film_motion_pre_c_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_PRE_C_reg);
	//
	im_di_control_reg.regValue = rtd_inl(DI_IM_DI_CONTROL_reg);
	im_di_film_sawtooth_filmframe_th_reg.regValue = rtd_inl(DI_IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_reg);
	im_di_film_static_sum_th_reg.regValue = rtd_inl(DI_IM_DI_FILM_STATIC_SUM_TH_reg);
	im_di_film_motion_sum_th_reg.regValue = rtd_inl(DI_IM_DI_FILM_MOTION_SUM_TH_reg);
	im_di_si_film_final_result_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_FINAL_RESULT_reg);
	im_di_si_film_pattern_a_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_PATTERN_A_reg);
	im_di_si_film_pattern_b_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_PATTERN_B_reg);
	im_di_si_film_32_result_1_a_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_32_RESULT_1_A_reg);
	im_di_si_film_32_result_2_a_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_32_RESULT_2_A_reg);

	im_di_si_film_22_result_a_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_22_RESULT_A_reg);

	im_di_si_film22_detector_pattern_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM22_DETECTOR_PATTERN_reg);
	im_di_rtnr_control_reg.regValue = rtd_inl(DI_IM_DI_RTNR_CONTROL_reg);

	im_di_film_prev_fieldmotion_reg.regValue = rtd_inl(DI_IM_DI_FILM_PREV_FIELDMOTION_reg);
	im_di_film_mark_information_reg.regValue = rtd_inl(DI_IM_DI_FILM_MARK_INFORMATION_reg);
	im_di_film_mark_prev1_reg.regValue = rtd_inl(DI_IM_DI_FILM_MARK_PREV1_reg);
	im_di_film_mark_prev2_reg.regValue = rtd_inl(DI_IM_DI_FILM_MARK_PREV2_reg);
	im_di_film_mark_prev3_reg.regValue = rtd_inl(DI_IM_DI_FILM_MARK_PREV3_reg);
	im_di_film_mark_next1_reg.regValue = rtd_inl(DI_IM_DI_FILM_MARK_NEXT1_reg);
	im_di_film_mark_next2_reg.regValue = rtd_inl(DI_IM_DI_FILM_MARK_NEXT2_reg);
	im_di_film_mark_next3_reg.regValue = rtd_inl(DI_IM_DI_FILM_MARK_NEXT3_reg);

	im_di_film_new_function_main_reg.regValue = rtd_inl(DI_IM_DI_FILM_NEW_FUNCTION_MAIN_reg);


	if (TV_05_style_ON == 1)
	{
		enchance22_en = 0;//(im_di_film_motion_sum_th_reg.dummy180240b4_23_16 & 0x01);
		film3223_en = 0;//(im_di_film_motion_sum_th_reg.dummy180240b4_23_16 & 0x02)>>1;
		film64_en = 0;//(im_di_film_motion_sum_th_reg.dummy180240b4_23_16 & 0x04)>>2;
		film55_en = 0;//(im_di_film_motion_sum_th_reg.dummy180240b4_23_16 & 0x08)>>3;
		film2224_en = 0;//(im_di_film_motion_sum_th_reg.dummy180240b4_23_16 & 0x10)>>4;
		film32322_en = 0;//(im_di_film_motion_sum_th_reg.dummy180240b4_23_16 & 0x20)>>5;
		film87_en = 0;//(im_di_film_motion_sum_th_reg.dummy180240b4_23_16 & 0x40)>>6;
	}
	else
	{
		enchance22_en = 0;//(im_di_film_motion_sum_th_reg.dummy180240b4_23_16 & 0x01);
		film3223_en = 1;//(im_di_film_motion_sum_th_reg.dummy180240b4_23_16 & 0x02)>>1;
		film64_en = 1;//(im_di_film_motion_sum_th_reg.dummy180240b4_23_16 & 0x04)>>2;
		film55_en = 1;//(im_di_film_motion_sum_th_reg.dummy180240b4_23_16 & 0x08)>>3;
		film2224_en = 1;//(im_di_film_motion_sum_th_reg.dummy180240b4_23_16 & 0x10)>>4;
		film32322_en = 1;//(im_di_film_motion_sum_th_reg.dummy180240b4_23_16 & 0x20)>>5;
		film87_en = 1;//(im_di_film_motion_sum_th_reg.dummy180240b4_23_16 & 0x40)>>6;
		filmQuick_en = (im_di_si_film_final_result_reg.regValue&0x8000)?1:0;
		framestaticonly = (im_di_si_film_final_result_reg.regValue&0x4000)?1:0;

	}

	hw_AdoptHDMethod = im_di_control_reg.ma_3aenable;
	hw_film_Enable = (im_di_control_reg.film_enable & 0x10)>>4;
	hw_film_32Film = ((im_di_control_reg.film_enable & 0x8)>>3) + ((im_di_control_reg.film_enable & 0x2)>>1);
	hw_film_22Film = ((im_di_control_reg.film_enable & 0x4)>>2) + (im_di_control_reg.film_enable & 0x1);
	hw_film_VerScrollingText_en=im_di_film_sawtooth_filmframe_th_reg.film_verscrollingtext_en;
	hw_film_thumbnail_en=im_di_film_sawtooth_filmframe_th_reg.film_thumbnail_en;
	film_Pair_en_auto=im_di_film_sawtooth_filmframe_th_reg.film_pair_en_auto; // 0
	film_Pair1_en = im_di_film_sawtooth_filmframe_th_reg.film_pair1_en; // 1
	film_Violate_strict_en = im_di_film_sawtooth_filmframe_th_reg.film_violate_strict_en; // 1
	hw_FieldStaticSumThl = im_di_film_static_sum_th_reg.film22_fistaticsthl;
	hw_FieldMotionSumThl = im_di_film_motion_sum_th_reg.film22_fieldmotionsumthl;
	film32_debounce_FieldNum = im_di_film_motion_sum_th_reg.film32_debounce_fieldnum;
	film22_debounce_FieldNum = im_di_film_motion_sum_th_reg.film22_debounce_fieldnum;

	hw_film_StatusFilmDetected = im_di_si_film_final_result_reg.film_detected;
	hw_film_StatusMixedFilmDetected = im_di_si_film_final_result_reg.film_subdetected;
	hw_film_StatusFilmSequence = im_di_si_film_final_result_reg.film_sequence;
	hw_film_MixedFilmConfuse = im_di_si_film_final_result_reg.film_confuse;
	film_HiFreq_flag = im_di_si_film_final_result_reg.film_hifreq_flag;
	hw_StatusFrameStaticPattern_All = im_di_si_film_pattern_a_reg.film_framestatic;
	hw_StatusFramePairPattern_All = im_di_si_film_pattern_a_reg.film_framepair;
	hw_StatusPrevStaticPattern_All = im_di_si_film_pattern_a_reg.film_prefistatic1;
	hw_StatusNextStaticPattern_All = im_di_si_film_pattern_b_reg.film_nxtfistatic1;
	hw_StatusPrevStaticPattern2_All = im_di_si_film_pattern_b_reg.film_prefistatic2;
	hw_StatusNextStaticPattern2_All = im_di_si_film_pattern_b_reg.film_nxtfistatic2;
	hw_StatusNextFieldMotion_All = im_di_si_film_pattern_b_reg.film_nxtfimotion;
	hw_film_Status32Detected1 = (im_di_si_film_32_result_1_a_reg.film_detected321 & 0x80)>>7;
	hw_film_Status32Detected2 = (im_di_si_film_32_result_2_a_reg.film_detected322 & 0x80)>>7;
	hw_film_Status22Detected = (im_di_si_film_22_result_a_reg.film_detected22 & 0x80)>>7;
	hw_StatusNextFieldMotion_film22_All = im_di_si_film22_detector_pattern_reg.film22_nxtfimotion;
	hw_StatusNextStaticPattern_film22_All = im_di_si_film22_detector_pattern_reg.film22_nxtfistatic1;
	hw_RTNR_Interlace_Force2D_En = im_di_rtnr_control_reg.cp_rtnr_interlace_force2d_en;

	hw_StatusPrevFieldMotion_All = im_di_film_prev_fieldmotion_reg.film_prevfilmmotion;
	hw_StatusPrevFieldMotion_film22_All = im_di_film_prev_fieldmotion_reg.film22_prevfilmmotion;
	hw_film_BadEditor_flag = im_di_film_prev_fieldmotion_reg.film_badeditor_flag;
	NextTopDetected = im_di_film_mark_information_reg.film_nexttopdetected1;
	PrevTopDetected = im_di_film_mark_information_reg.film_prevtopdetected1;

	fw_DI_3A = hw_AdoptHDMethod || hw_RTNR_Interlace_Force2D_En;

	//scalerVIP_film_FWmode_3D_start();

	StatusFrameStaticPattern = (StatusFrameStaticPattern<<1) + ((hw_StatusFrameStaticPattern_All & 0x80)>>7);
	StatusFrameStaticPattern_H1 = (StatusFrameStaticPattern_H1<<1) + ((hw_StatusFrameStaticPattern_All & 0x40)>>6);
	StatusFrameStaticPattern_H2 = (StatusFrameStaticPattern_H2<<1) + ((hw_StatusFrameStaticPattern_All & 0x20)>>5);
	StatusFrameStaticPattern_H3 = (StatusFrameStaticPattern_H3<<1) + ((hw_StatusFrameStaticPattern_All & 0x10)>>4);
	StatusFrameStaticPattern_V1 = (StatusFrameStaticPattern_V1<<1) + ((hw_StatusFrameStaticPattern_All & 0x08)>>3);
	StatusFrameStaticPattern_V2 = (StatusFrameStaticPattern_V2<<1) + ((hw_StatusFrameStaticPattern_All & 0x04)>>2);
	StatusFrameStaticPattern_V3 = (StatusFrameStaticPattern_V3<<1) + ((hw_StatusFrameStaticPattern_All & 0x02)>>1);
	StatusFrameStaticPattern_C = (StatusFrameStaticPattern_C<<1) + ((hw_StatusFrameStaticPattern_All & 0x01));

	StatusFramePairPattern = ( StatusFramePairPattern<<2 ) + ( (hw_StatusFramePairPattern_All & 0xc000)>>14);
	StatusFramePairPattern_H1 = ( StatusFramePairPattern_H1<<2 ) + ( (hw_StatusFramePairPattern_All & 0x3000)>>12);
	StatusFramePairPattern_H2 = ( StatusFramePairPattern_H2<<2 ) + ( (hw_StatusFramePairPattern_All & 0x0c00)>>10);
	StatusFramePairPattern_H3 = ( StatusFramePairPattern_H3<<2 ) + ( (hw_StatusFramePairPattern_All & 0x0300)>>8);
	StatusFramePairPattern_V1 = ( StatusFramePairPattern_V1<<2 ) + ( (hw_StatusFramePairPattern_All & 0x00c0)>>6);
	StatusFramePairPattern_V2 = ( StatusFramePairPattern_V2<<2 ) + ( (hw_StatusFramePairPattern_All & 0x0030)>>4);
	StatusFramePairPattern_V3 = ( StatusFramePairPattern_V3<<2 ) + ( (hw_StatusFramePairPattern_All & 0x000c)>>2);
	StatusFramePairPattern_C = ( StatusFramePairPattern_C<<2 ) + ( (hw_StatusFramePairPattern_All & 0x0003));

	StatusPrevStaticPattern = ( StatusPrevStaticPattern<<1 ) + ( (hw_StatusPrevStaticPattern_All & 0x80)>>7);
	StatusPrevStaticPattern_H1 = ( StatusPrevStaticPattern_H1<<1 ) + ( (hw_StatusPrevStaticPattern_All & 0x40)>>6);
	StatusPrevStaticPattern_H2 = ( StatusPrevStaticPattern_H2<<1 ) + ( (hw_StatusPrevStaticPattern_All & 0x20)>>5);
	StatusPrevStaticPattern_H3 = ( StatusPrevStaticPattern_H3<<1 ) + ( (hw_StatusPrevStaticPattern_All & 0x10)>>4);
	StatusPrevStaticPattern_V1 = ( StatusPrevStaticPattern_V1<<1 ) + ( (hw_StatusPrevStaticPattern_All & 0x08)>>3);
	StatusPrevStaticPattern_V2 = ( StatusPrevStaticPattern_V2<<1 ) + ( (hw_StatusPrevStaticPattern_All & 0x04)>>2);
	StatusPrevStaticPattern_V3 = ( StatusPrevStaticPattern_V3<<1 ) + ( (hw_StatusPrevStaticPattern_All & 0x02)>>1);
	StatusPrevStaticPattern_C = ( StatusPrevStaticPattern_C<<1 ) + ( (hw_StatusPrevStaticPattern_All & 0x01));

	StatusNextStaticPattern = ( StatusNextStaticPattern<<1 ) + ( (hw_StatusNextStaticPattern_All & 0x80)>>7);
	StatusNextStaticPattern_H1 = ( StatusNextStaticPattern_H1<<1 ) + ( (hw_StatusNextStaticPattern_All & 0x40)>>6);
	StatusNextStaticPattern_H2 = ( StatusNextStaticPattern_H2<<1 ) + ( (hw_StatusNextStaticPattern_All & 0x20)>>5);
	StatusNextStaticPattern_H3 = ( StatusNextStaticPattern_H3<<1 ) + ( (hw_StatusNextStaticPattern_All & 0x10)>>4);
	StatusNextStaticPattern_V1 = ( StatusNextStaticPattern_V1<<1 ) + ( (hw_StatusNextStaticPattern_All & 0x08)>>3);
	StatusNextStaticPattern_V2 = ( StatusNextStaticPattern_V2<<1 ) + ( (hw_StatusNextStaticPattern_All & 0x04)>>2);
	StatusNextStaticPattern_V3 = ( StatusNextStaticPattern_V3<<1 ) + ( (hw_StatusNextStaticPattern_All & 0x02)>>1);
	StatusNextStaticPattern_C = ( StatusNextStaticPattern_C<<1 ) + ( (hw_StatusNextStaticPattern_All & 0x01));

	StatusPrevStaticPattern2 = ( StatusPrevStaticPattern2<<1 ) + ( (hw_StatusPrevStaticPattern2_All & 0x80)>>7);
	StatusPrevStaticPattern2_H1 = ( StatusPrevStaticPattern2_H1<<1 ) + ( (hw_StatusPrevStaticPattern2_All & 0x40)>>6);
	StatusPrevStaticPattern2_H2 = ( StatusPrevStaticPattern2_H2<<1 ) + ( (hw_StatusPrevStaticPattern2_All & 0x20)>>5);
	StatusPrevStaticPattern2_H3 = ( StatusPrevStaticPattern2_H3<<1 ) + ( (hw_StatusPrevStaticPattern2_All & 0x10)>>4);
	StatusPrevStaticPattern2_V1 = ( StatusPrevStaticPattern2_V1<<1 ) + ( (hw_StatusPrevStaticPattern2_All & 0x08)>>3);
	StatusPrevStaticPattern2_V2 = ( StatusPrevStaticPattern2_V2<<1 ) + ( (hw_StatusPrevStaticPattern2_All & 0x04)>>2);
	StatusPrevStaticPattern2_V3 = ( StatusPrevStaticPattern2_V3<<1 ) + ( (hw_StatusPrevStaticPattern2_All & 0x02)>>1);
	StatusPrevStaticPattern2_C = ( StatusPrevStaticPattern2_C<<1 ) + ( (hw_StatusPrevStaticPattern2_All & 0x01));

	StatusNextStaticPattern2 = ( StatusNextStaticPattern2<<1 ) + ( (hw_StatusNextStaticPattern2_All & 0x80)>>7);
	StatusNextStaticPattern2_H1 = ( StatusNextStaticPattern2_H1<<1 ) + ( (hw_StatusNextStaticPattern2_All & 0x40)>>6);
	StatusNextStaticPattern2_H2 = ( StatusNextStaticPattern2_H2<<1 ) + ( (hw_StatusNextStaticPattern2_All & 0x20)>>5);
	StatusNextStaticPattern2_H3 = ( StatusNextStaticPattern2_H3<<1 ) + ( (hw_StatusNextStaticPattern2_All & 0x10)>>4);
	StatusNextStaticPattern2_V1 = ( StatusNextStaticPattern2_V1<<1 ) + ( (hw_StatusNextStaticPattern2_All & 0x08)>>3);
	StatusNextStaticPattern2_V2 = ( StatusNextStaticPattern2_V2<<1 ) + ( (hw_StatusNextStaticPattern2_All & 0x04)>>2);
	StatusNextStaticPattern2_V3 = ( StatusNextStaticPattern2_V3<<1 ) + ( (hw_StatusNextStaticPattern2_All & 0x02)>>1);
	StatusNextStaticPattern2_C = ( StatusNextStaticPattern2_C<<1 ) + ( (hw_StatusNextStaticPattern2_All & 0x01));

	scalerVIP_film_FWmode_detection1_isr(StatusFrameStaticPattern, StatusFramePairPattern,
						StatusPrevStaticPattern2, StatusNextStaticPattern2, 1,
						&ExactMatch321, &Violate321,&index32,&stillpix_count32,
						&Status32Detected1, &Status32Sequence1,film_Pair_en_auto,
						film_Pair1_en,film_HiFreq_flag,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection1_isr(StatusFrameStaticPattern_H1, StatusFramePairPattern_H1,
						StatusPrevStaticPattern_H1, StatusNextStaticPattern_H1, 1,
						&ExactMatch321_H1, &Violate321_H1,&index32_H1,&stillpix_count32_H1,
						&Status32Detected1_H1, &Status32Sequence1_H1,film_Pair_en_auto,
						film_Pair1_en,film_HiFreq_flag,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection1_isr(StatusFrameStaticPattern_H2, StatusFramePairPattern_H2,
						StatusPrevStaticPattern_H2, StatusNextStaticPattern_H2, 1,
						&ExactMatch321_H2, &Violate321_H2,&index32_H2,&stillpix_count32_H2,
						&Status32Detected1_H2, &Status32Sequence1_H2,film_Pair_en_auto,
						film_Pair1_en,film_HiFreq_flag,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection1_isr(StatusFrameStaticPattern_H3, StatusFramePairPattern_H3,
						StatusPrevStaticPattern_H3, StatusNextStaticPattern_H3, 1,
						&ExactMatch321_H3, &Violate321_H3,&index32_H3,&stillpix_count32_H3,
						&Status32Detected1_H3, &Status32Sequence1_H3,film_Pair_en_auto,
						film_Pair1_en,film_HiFreq_flag,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection1_isr(StatusFrameStaticPattern_V1, StatusFramePairPattern_V1,
						StatusPrevStaticPattern_V1, StatusNextStaticPattern_V1, 1,
						&ExactMatch321_V1, &Violate321_V1,&index32_V1,&stillpix_count32_V1,
						&Status32Detected1_V1, &Status32Sequence1_V1,film_Pair_en_auto,
						film_Pair1_en,film_HiFreq_flag,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection1_isr(StatusFrameStaticPattern_V2, StatusFramePairPattern_V2,
						StatusPrevStaticPattern_V2, StatusNextStaticPattern_V2, 1,
						&ExactMatch321_V2, &Violate321_V2,&index32_V2,&stillpix_count32_V2,
						&Status32Detected1_V2, &Status32Sequence1_V2,film_Pair_en_auto,
						film_Pair1_en,film_HiFreq_flag,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection1_isr(StatusFrameStaticPattern_V3, StatusFramePairPattern_V3,
						StatusPrevStaticPattern_V3, StatusNextStaticPattern_V3, 1,
						&ExactMatch321_V3, &Violate321_V3,&index32_V3,&stillpix_count32_V3,
						&Status32Detected1_V3, &Status32Sequence1_V3,film_Pair_en_auto,
						film_Pair1_en,film_HiFreq_flag,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection1_isr(StatusFrameStaticPattern_C, StatusFramePairPattern_C,
						StatusPrevStaticPattern_C, StatusNextStaticPattern_C, 1,
						&ExactMatch321_C, &Violate321_C,&index32_C,&stillpix_count32_C,
						&Status32Detected1_C, &Status32Sequence1_C,film_Pair_en_auto,
						film_Pair1_en,film_HiFreq_flag,film_Violate_strict_en);

	// detection 2
	scalerVIP_film_FWmode_detection2_isr(StatusNextStaticPattern, 1,StatusFrameStaticPattern ,
						(hw_StatusPrevFieldMotion_All & 0x80)>>7, (hw_StatusNextFieldMotion_All & 0x80)>>7,
						&ExactMatch322, &Violate322,&index322,&Status32Detected2, &Status32Sequence2,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection2_isr(StatusNextStaticPattern_H1, 1,StatusFrameStaticPattern_H1,
						(hw_StatusPrevFieldMotion_All & 0x40)>>6, (hw_StatusNextFieldMotion_All & 0x40)>>6,
						&ExactMatch322_H1, &Violate322_H1,&index322_H1,&Status32Detected2_H1, &Status32Sequence2_H1,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection2_isr(StatusNextStaticPattern_H2, 1,StatusFrameStaticPattern_H2,
						(hw_StatusPrevFieldMotion_All & 0x20)>>5, (hw_StatusNextFieldMotion_All & 0x20)>>5,
						&ExactMatch322_H2, &Violate322_H2, &index322_H2,&Status32Detected2_H2, &Status32Sequence2_H2,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection2_isr(StatusNextStaticPattern_H3, 1,StatusFrameStaticPattern_H3,
						(hw_StatusPrevFieldMotion_All & 0x10)>>4, (hw_StatusNextFieldMotion_All & 0x10)>>4,
						&ExactMatch322_H3, &Violate322_H3,&index322_H3,&Status32Detected2_H3, &Status32Sequence2_H3,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection2_isr(StatusNextStaticPattern_V1, 1,StatusFrameStaticPattern_V1,
						(hw_StatusPrevFieldMotion_All & 0x08)>>3, (hw_StatusNextFieldMotion_All & 0x08)>>3,
						&ExactMatch322_V1, &Violate322_V1,&index322_V1,&Status32Detected2_V1, &Status32Sequence2_V1,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection2_isr(StatusNextStaticPattern_V2, 1,StatusFrameStaticPattern_V2,
						(hw_StatusPrevFieldMotion_All & 0x04)>>2, (hw_StatusNextFieldMotion_All & 0x04)>>2,
						&ExactMatch322_V2, &Violate322_V2,&index322_V2,&Status32Detected2_V2, &Status32Sequence2_V2,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection2_isr(StatusNextStaticPattern_V3, 1,StatusFrameStaticPattern_V3,
						(hw_StatusPrevFieldMotion_All & 0x02)>>1, (hw_StatusNextFieldMotion_All & 0x02)>>1,
						&ExactMatch322_V3, &Violate322_V3,&index322_V3,&Status32Detected2_V3, &Status32Sequence2_V3,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection2_isr(StatusNextStaticPattern_C, 1,StatusFrameStaticPattern_C,
						(hw_StatusPrevFieldMotion_All & 0x01), (hw_StatusNextFieldMotion_All & 0x01),
						&ExactMatch322_C, &Violate322_C,&index322_C,&Status32Detected2_C, &Status32Sequence2_C,film_Violate_strict_en);

	//debounce for film32 flag, flora add (Darwin)////////////////////////////////////////////
	scalerVIP_film_FWmode_film32_debounce(&Status32Detected1,&Status32Detected1_cnt,film32_debounce_FieldNum);
	scalerVIP_film_FWmode_film32_debounce(&Status32Detected2,&Status32Detected2_cnt,film32_debounce_FieldNum);

	scalerVIP_film_FWmode_film32_debounce(&Status32Detected1_H1,&Status32Detected1_H1_cnt,film32_debounce_FieldNum);
	scalerVIP_film_FWmode_film32_debounce(&Status32Detected1_H2,&Status32Detected1_H2_cnt,film32_debounce_FieldNum);
	scalerVIP_film_FWmode_film32_debounce(&Status32Detected1_H3,&Status32Detected1_H3_cnt,film32_debounce_FieldNum);
	scalerVIP_film_FWmode_film32_debounce(&Status32Detected1_V1,&Status32Detected1_V1_cnt,film32_debounce_FieldNum);
	scalerVIP_film_FWmode_film32_debounce(&Status32Detected1_V2,&Status32Detected1_V2_cnt,film32_debounce_FieldNum);
	scalerVIP_film_FWmode_film32_debounce(&Status32Detected1_V3,&Status32Detected1_V3_cnt,film32_debounce_FieldNum);
	scalerVIP_film_FWmode_film32_debounce(&Status32Detected1_C ,&Status32Detected1_C_cnt,film32_debounce_FieldNum );

	scalerVIP_film_FWmode_film32_debounce(&Status32Detected2_H1,&Status32Detected2_H1_cnt,film32_debounce_FieldNum);
	scalerVIP_film_FWmode_film32_debounce(&Status32Detected2_H2,&Status32Detected2_H2_cnt,film32_debounce_FieldNum);
	scalerVIP_film_FWmode_film32_debounce(&Status32Detected2_H3,&Status32Detected2_H3_cnt,film32_debounce_FieldNum);
	scalerVIP_film_FWmode_film32_debounce(&Status32Detected2_V1,&Status32Detected2_V1_cnt,film32_debounce_FieldNum);
	scalerVIP_film_FWmode_film32_debounce(&Status32Detected2_V2,&Status32Detected2_V2_cnt,film32_debounce_FieldNum);
	scalerVIP_film_FWmode_film32_debounce(&Status32Detected2_V3,&Status32Detected2_V3_cnt,film32_debounce_FieldNum);
	scalerVIP_film_FWmode_film32_debounce(&Status32Detected2_C ,&Status32Detected2_C_cnt,film32_debounce_FieldNum );
	//end of decounce//////////////////////////////////////////////////////////////////////////

	PrevDiff = im_di_si_film_motion_pre_reg.film_motionstatus_559_540;
	PrevDiff_H1 = im_di_si_film_motion_pre_h_t_reg.film_motionstatus_539_520;
	PrevDiff_H2 = im_di_si_film_motion_pre_h_m_reg.film_motionstatus_519_500;
	PrevDiff_H3 = im_di_si_film_motion_pre_h_b_reg.film_motionstatus_499_480;
	PrevDiff_V1 = im_di_si_film_motion_pre_v_l_reg.film_motionstatus_479_460;
	PrevDiff_V2 = im_di_si_film_motion_pre_v_m_reg.film_motionstatus_459_440;
	PrevDiff_V3 = im_di_si_film_motion_pre_v_r_reg.film_motionstatus_439_420;
	PrevDiff_C = im_di_si_film_motion_pre_c_reg.film_motionstatus_419_400;

	NextDiff = im_di_si_film_motion_next_reg.film_motionstatus_719_700;
	NextDiff_H1 = im_di_si_film_motion_next_h_t_reg.film_motionstatus_699_680;
	NextDiff_H2 = im_di_si_film_motion_next_h_m_reg.film_motionstatus_679_660;
	NextDiff_H3 = im_di_si_film_motion_next_h_b_reg.film_motionstatus_659_640;
	NextDiff_V1 = im_di_si_film_motion_next_v_l_reg.film_motionstatus_639_620;
	NextDiff_V2 = im_di_si_film_motion_next_v_m_reg.film_motionstatus_619_600;
	NextDiff_V3 = im_di_si_film_motion_next_v_r_reg.film_motionstatus_599_580;
	NextDiff_C = im_di_si_film_motion_next_c_reg.film_motionstatus_579_560;
	p22_StatusPrevDiffSum[0]=&PrevDiff;
	p22_StatusPrevDiffSum[1]=&PrevDiff_H1;
	p22_StatusPrevDiffSum[2]=&PrevDiff_H2;
	p22_StatusPrevDiffSum[3]=&PrevDiff_H3;
	p22_StatusPrevDiffSum[4]=&PrevDiff_V1;
	p22_StatusPrevDiffSum[5]=&PrevDiff_V2;
	p22_StatusPrevDiffSum[6]=&PrevDiff_V3;
	p22_StatusPrevDiffSum[7]=&PrevDiff_C;
	p22_StatusNextDiffSum[0]=&NextDiff;
	p22_StatusNextDiffSum[1]=&NextDiff_H1;
	p22_StatusNextDiffSum[2]=&NextDiff_H2;
	p22_StatusNextDiffSum[3]=&NextDiff_H3;
	p22_StatusNextDiffSum[4]=&NextDiff_V1;
	p22_StatusNextDiffSum[5]=&NextDiff_V2;
	p22_StatusNextDiffSum[6]=&NextDiff_V3;
	p22_StatusNextDiffSum[7]=&NextDiff_C;
	StatusNextStaticPattern_film22_PTR[0]=&StatusNextStaticPattern_film22;
	StatusNextStaticPattern_film22_PTR[1]=&StatusNextStaticPattern_film22_H1;
	StatusNextStaticPattern_film22_PTR[2]=&StatusNextStaticPattern_film22_H2;
	StatusNextStaticPattern_film22_PTR[3]=&StatusNextStaticPattern_film22_H3;
	StatusNextStaticPattern_film22_PTR[4]=&StatusNextStaticPattern_film22_V1;
	StatusNextStaticPattern_film22_PTR[5]=&StatusNextStaticPattern_film22_V2;
	StatusNextStaticPattern_film22_PTR[6]=&StatusNextStaticPattern_film22_V3;
	StatusNextStaticPattern_film22_PTR[7]=&StatusNextStaticPattern_film22_C;
	if(fw_di_film_sawtooth_comparePrevNext){
		int i,j,k;
		int reg_vc_di_film22_observe_many_frames=0;// tunable, 0~3
		hw_StatusPrevFieldMotion_film22_All=0;
		hw_StatusNextFieldMotion_film22_All=0;
		for(i=0;i<8;i++){// region number
			for(j=(1<<reg_vc_di_film22_observe_many_frames);j<8;j++){
		A22_StatusPrevDiffSum[i][j]=0;
		A22_StatusNextDiffSum[i][j]=0;
			}
			for(j=(1<<reg_vc_di_film22_observe_many_frames)-1;j>0;j--){
		A22_StatusPrevDiffSum[i][j]=A22_StatusPrevDiffSum[i][j-1];
		A22_StatusNextDiffSum[i][j]=A22_StatusNextDiffSum[i][j-1];
			}
			A22_StatusPrevDiffSum[i][0]=vc_di_film_getDiffSumRemap_isr(p22_StatusPrevDiffSum[i][0]);
			A22_StatusNextDiffSum[i][0]=vc_di_film_getDiffSumRemap_isr(p22_StatusNextDiffSum[i][0]);
			k=(1<<reg_vc_di_film22_observe_many_frames)>>1;
			for(j=0;j<8;j+=2){
				k+=A22_StatusNextDiffSum[i][j]-A22_StatusPrevDiffSum[i][j]
				-A22_StatusNextDiffSum[i][j|1]+A22_StatusPrevDiffSum[i][j|1];
			}
			k=k>>reg_vc_di_film22_observe_many_frames;

			p22_StatusPrevDiffSum[i][0]=128-k;
			p22_StatusNextDiffSum[i][0]=128+k;
			hw_StatusPrevFieldMotion_film22_All=hw_StatusPrevFieldMotion_film22_All| (p22_StatusPrevDiffSum[i][0] > (i?0x90:0xa0) ? 1<<(7^i) : 0);
			StatusNextStaticPattern_film22_PTR[i][0] = (StatusNextStaticPattern_film22_PTR[i][0]<<1)|(p22_StatusNextDiffSum[i][0] < (i?0x90:0xa0) ? 1 : 0);
			hw_StatusNextFieldMotion_film22_All=hw_StatusNextFieldMotion_film22_All| (p22_StatusNextDiffSum[i][0] > (i?0x90:0xa0) ? 1<<(7^i) : 0);
		}
	}else{
	// detection 22
	StatusNextStaticPattern_film22 = ( StatusNextStaticPattern_film22<<1 ) + ( (hw_StatusNextStaticPattern_film22_All & 0x80)>>7);
	StatusNextStaticPattern_film22_H1 = ( StatusNextStaticPattern_film22_H1<<1 ) + ( (hw_StatusNextStaticPattern_film22_All & 0x40)>>6);
	StatusNextStaticPattern_film22_H2 = ( StatusNextStaticPattern_film22_H2<<1 ) + ( (hw_StatusNextStaticPattern_film22_All & 0x20)>>5);
	StatusNextStaticPattern_film22_H3 = ( StatusNextStaticPattern_film22_H3<<1 ) + ( (hw_StatusNextStaticPattern_film22_All & 0x10)>>4);
	StatusNextStaticPattern_film22_V1 = ( StatusNextStaticPattern_film22_V1<<1 ) + ( (hw_StatusNextStaticPattern_film22_All & 0x08)>>3);
	StatusNextStaticPattern_film22_V2 = ( StatusNextStaticPattern_film22_V2<<1 ) + ( (hw_StatusNextStaticPattern_film22_All & 0x04)>>2);
	StatusNextStaticPattern_film22_V3 = ( StatusNextStaticPattern_film22_V3<<1 ) + ( (hw_StatusNextStaticPattern_film22_All & 0x02)>>1);
	StatusNextStaticPattern_film22_C = ( StatusNextStaticPattern_film22_C<<1 ) + ( (hw_StatusNextStaticPattern_film22_All & 0x01));
	}

	if(!filmQuick_en){
	scalerVIP_film_FWmode_detection22_isr(StatusNextStaticPattern_film22, scalerVIP_film_FWmode_22all_suspect32_isr(StatusFrameStaticPattern),
						((hw_StatusPrevFieldMotion_film22_All & 0x80)>>7), ((hw_StatusNextFieldMotion_film22_All & 0x80)>>7),
						&ExactMatch22, &Violate22,&index22, &stillpix_count22,
						&Status22Detected, &Status22Sequence,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection22_isr(StatusNextStaticPattern_film22_H1, 1,
						((hw_StatusPrevFieldMotion_film22_All & 0x40)>>6), ((hw_StatusNextFieldMotion_film22_All & 0x40)>>6),
						&ExactMatch22_H1, &Violate22_H1,&index22_H1, &stillpix_count22_H1,
						&Status22Detected_H1, &Status22Sequence_H1,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection22_isr(StatusNextStaticPattern_film22_H2, 1,
						((hw_StatusPrevFieldMotion_film22_All & 0x20)>>5), ((hw_StatusNextFieldMotion_film22_All & 0x20)>>5),
						&ExactMatch22_H2, &Violate22_H2,&index22_H2, &stillpix_count22_H2,
						&Status22Detected_H2, &Status22Sequence_H2,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection22_isr(StatusNextStaticPattern_film22_H3, 1,
						((hw_StatusPrevFieldMotion_film22_All & 0x10)>>4), ((hw_StatusNextFieldMotion_film22_All & 0x10)>>4),
						&ExactMatch22_H3, &Violate22_H3,&index22_H3, &stillpix_count22_H3,
						&Status22Detected_H3, &Status22Sequence_H3,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection22_isr(StatusNextStaticPattern_film22_V1, 1,
						((hw_StatusPrevFieldMotion_film22_All & 0x08)>>3), ((hw_StatusNextFieldMotion_film22_All & 0x08)>>3),
						&ExactMatch22_V1, &Violate22_V1,&index22_V1, &stillpix_count22_V1,
						&Status22Detected_V1, &Status22Sequence_V1,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection22_isr(StatusNextStaticPattern_film22_V2, 1,
						((hw_StatusPrevFieldMotion_film22_All & 0x04)>>2), ((hw_StatusNextFieldMotion_film22_All & 0x04)>>2),
						&ExactMatch22_V2, &Violate22_V2,&index22_V2, &stillpix_count22_V2,
						&Status22Detected_V2, &Status22Sequence_V2,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection22_isr(StatusNextStaticPattern_film22_V3, 1,
						((hw_StatusPrevFieldMotion_film22_All & 0x02)>>1), ((hw_StatusNextFieldMotion_film22_All & 0x02)>>1),
						&ExactMatch22_V3, &Violate22_V3,&index22_V3, &stillpix_count22_V3,
						&Status22Detected_V3, &Status22Sequence_V3,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection22_isr(StatusNextStaticPattern_film22_C, 1,
						((hw_StatusPrevFieldMotion_film22_All & 0x01)), ((hw_StatusNextFieldMotion_film22_All & 0x01)),
						&ExactMatch22_C, &Violate22_C,&index22_C, &stillpix_count22_C,
						&Status22Detected_C, &Status22Sequence_C,film_Violate_strict_en);
	}
	FrameDiff = im_di_si_film_motion_reg.film_motionstatus_399_380;
	FrameDiff_H1 = im_di_si_film_motion_h_t_reg.film_motionstatus_379_360;
	FrameDiff_H2 = im_di_si_film_motion_h_m_reg.film_motionstatus_359_340;
	FrameDiff_H3 = im_di_si_film_motion_h_b_reg.film_motionstatus_339_320;
	FrameDiff_V1 = im_di_si_film_motion_v_l_reg.film_motionstatus_319_300;
	FrameDiff_V2 = im_di_si_film_motion_v_m_reg.film_motionstatus_299_280;
	FrameDiff_V3 = im_di_si_film_motion_v_r_reg.film_motionstatus_279_260;
	FrameDiff_C = im_di_si_film_motion_c_reg.film_motionstatus_259_240;

	PrevDiff = im_di_si_film_motion_pre_reg.film_motionstatus_559_540;
	PrevDiff_H1 = im_di_si_film_motion_pre_h_t_reg.film_motionstatus_539_520;
	PrevDiff_H2 = im_di_si_film_motion_pre_h_m_reg.film_motionstatus_519_500;
	PrevDiff_H3 = im_di_si_film_motion_pre_h_b_reg.film_motionstatus_499_480;
	PrevDiff_V1 = im_di_si_film_motion_pre_v_l_reg.film_motionstatus_479_460;
	PrevDiff_V2 = im_di_si_film_motion_pre_v_m_reg.film_motionstatus_459_440;
	PrevDiff_V3 = im_di_si_film_motion_pre_v_r_reg.film_motionstatus_439_420;
	PrevDiff_C = im_di_si_film_motion_pre_c_reg.film_motionstatus_419_400;

	NextDiff = im_di_si_film_motion_next_reg.film_motionstatus_719_700;
	NextDiff_H1 = im_di_si_film_motion_next_h_t_reg.film_motionstatus_699_680;
	NextDiff_H2 = im_di_si_film_motion_next_h_m_reg.film_motionstatus_679_660;
	NextDiff_H3 = im_di_si_film_motion_next_h_b_reg.film_motionstatus_659_640;
	NextDiff_V1 = im_di_si_film_motion_next_v_l_reg.film_motionstatus_639_620;
	NextDiff_V2 = im_di_si_film_motion_next_v_m_reg.film_motionstatus_619_600;
	NextDiff_V3 = im_di_si_film_motion_next_v_r_reg.film_motionstatus_599_580;
	NextDiff_C = im_di_si_film_motion_next_c_reg.film_motionstatus_579_560;


	if(enchance22_en)
	{
		PrevDiffMax = MAX(MAX(PrevDiff_H1,PrevDiff_H2),PrevDiff_H3);
		PrevDiffMax = MAX(PrevDiffMax,MAX(MAX(PrevDiff_V1,PrevDiff_V2),PrevDiff_V3));
		NextDiffMax = MAX(MAX(NextDiff_H1,NextDiff_H2),NextDiff_H3);
		NextDiffMax = MAX(NextDiffMax,MAX(MAX(NextDiff_V1,NextDiff_V2),NextDiff_V3));

		// enachance 22
		// 1. - detect high freq term exists
		if(HFT_prev==1 && (FW_HFT<FW_HFT_thd) && (FrameDiff>700)
			&& (((abs(PrevDiff-FW_HFT)<(FW_HFT_rato_thd*FW_HFT)) || (abs(PrevDiff-FW_HFT)< FW_HFT_diff_thd)) ||
			(NextDiff > 20000)) // scene change
		)
		{
			FW_HFT = PrevDiff;
			FW_StatusNextHighFreqTerm = (FW_StatusNextHighFreqTerm<<1) + 1;
			HFT_prev = 0;
		}
		else if(HFT_prev==0 && (FW_HFT<FW_HFT_thd) && (FrameDiff>700)
		&& (((abs(NextDiff-FW_HFT)<(FW_HFT_rato_thd*FW_HFT)) || (abs(NextDiff-FW_HFT)< FW_HFT_diff_thd))||
			(PrevDiff > 20000)) // scene change
		)
		{
			FW_HFT = NextDiff;
			FW_StatusNextHighFreqTerm = (FW_StatusNextHighFreqTerm<<1) + 1;
			HFT_prev = 1;
		}
		else
		{
			FW_HFT = NextDiff;
			FW_StatusNextHighFreqTerm = (FW_StatusNextHighFreqTerm<<1);
			HFT_prev = 1;
		}

		// 2. - use pair to do detection
		if(HFT_prev==0 && ((FW_StatusNextHighFreqTerm&0xf)==0xf) && (PrevDiff * ratioPrevNext < NextDiff))// && (PrevDiff*1.6 < FrameDiff))
		{
			FW_StatusNextStaticPattern2_film22 = (FW_StatusNextStaticPattern2_film22<<1);
		}
		else if(HFT_prev==1 && ((FW_StatusNextHighFreqTerm&0xf)==0xf) && (NextDiff* ratioPrevNext < PrevDiff))// && (NextDiff*1.6 < FrameDiff))
		{
			FW_StatusNextStaticPattern2_film22 = (FW_StatusNextStaticPattern2_film22<<1) + 1;
		}
		else
		{
			FW_StatusNextStaticPattern2_film22 = (FW_StatusNextStaticPattern2_film22<<1);
		}

		scalerVIP_film_FWmode_detection22new_isr(FW_StatusNextStaticPattern2_film22,1,
		((hw_StatusPrevFieldMotion_film22_All & 0x80)>>7), ((hw_StatusNextFieldMotion_film22_All & 0x80)>>7),
		&ExactMatch22, &Violate22,&index22new, &stillpix_count22,&Status22Detected2, &Status22Sequence2);

		if(!Status22Detected && Status22Detected2 && FrameDiff>300)	// if motion is large enough
		{
			Status22Detected = Status22Detected2;
			Status22Sequence = Status22Sequence2;
			index22 = index22new;
		}

		// FW_Status22Sequence = 1 -> next
		// FW_Status22Sequence = 2 -> prev

/* // Marked due to still scene with high frequency contents will go intra path
		if(Status22Detected && ((FrameDiff<100) ||
			(Status22Sequence == 1 && (PrevDiff*5 < FrameDiff))||(Status22Sequence == 2 && (NextDiff*5 < FrameDiff)))
		)
		{
			Status22Detected = 0;
			index22 = 0;
		}
*/
	}

	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Film_Mode==TRUE))
	{
		VIP_DEBUG_PRINTF("f:%d\n",FrameDiff);
		VIP_DEBUG_PRINTF("p:%d\n",PrevDiff);
		VIP_DEBUG_PRINTF("n:%d\n",NextDiff);
	}

	//debounce for film22 flag, flora add (Darwin)////////////////////////////////////////////
	if(!filmQuick_en){
	scalerVIP_film_FWmode_film22_debounce(&Status22Detected,&Status22Detected_cnt,film22_debounce_FieldNum);
	scalerVIP_film_FWmode_film22_debounce(&Status22Detected_H1,&Status22Detected_H1_cnt,film22_debounce_FieldNum);
	scalerVIP_film_FWmode_film22_debounce(&Status22Detected_H2,&Status22Detected_H2_cnt,film22_debounce_FieldNum);
	scalerVIP_film_FWmode_film22_debounce(&Status22Detected_H3,&Status22Detected_H3_cnt,film22_debounce_FieldNum);
	scalerVIP_film_FWmode_film22_debounce(&Status22Detected_V1,&Status22Detected_V1_cnt,film22_debounce_FieldNum);
	scalerVIP_film_FWmode_film22_debounce(&Status22Detected_V2,&Status22Detected_V2_cnt,film22_debounce_FieldNum);
	scalerVIP_film_FWmode_film22_debounce(&Status22Detected_V3,&Status22Detected_V3_cnt,film22_debounce_FieldNum);
	scalerVIP_film_FWmode_film22_debounce(&Status22Detected_C ,&Status22Detected_C_cnt ,film22_debounce_FieldNum);
	}
	//end of debounce//////////////////////////////////////////////////////////////////////////
	if(filmQuick_en){
		scalerVIP_film_FWmode_Quick_detection_isr(
			im_di_control_reg.film_enable&2,
			StatusFrameStaticPattern_H1, StatusFramePairPattern_H1,
			StatusNextStaticPattern_H1,StatusNextStaticPattern_film22_H1,
			&ExactMatch321_H1, &Violate321_H1,&index32_H1,
			&Status32Detected1_H1, &Status32Sequence1_H1,
			&ExactMatch322_H1, &Violate322_H1,&index322_H1,
			&Status32Detected2_H1, &Status32Sequence2_H1,
			&ExactMatch22_H1, &Violate22_H1,&index22_H1,
			&Status22Detected_H1, &Status22Sequence_H1
		);
		scalerVIP_film_FWmode_Quick_detection_isr(
			im_di_control_reg.film_enable&2,
			StatusFrameStaticPattern_H2, StatusFramePairPattern_H2,
			StatusNextStaticPattern_H2,StatusNextStaticPattern_film22_H2,
			&ExactMatch321_H2, &Violate321_H2,&index32_H2,
			&Status32Detected1_H2, &Status32Sequence1_H2,
			&ExactMatch322_H2, &Violate322_H2,&index322_H2,
			&Status32Detected2_H2, &Status32Sequence2_H2,
			&ExactMatch22_H2, &Violate22_H2,&index22_H2,
			&Status22Detected_H2, &Status22Sequence_H2
		);
		scalerVIP_film_FWmode_Quick_detection_isr(
			im_di_control_reg.film_enable&2,
			StatusFrameStaticPattern_H3, StatusFramePairPattern_H3,
			StatusNextStaticPattern_H3,StatusNextStaticPattern_film22_H3,
			&ExactMatch321_H3, &Violate321_H3,&index32_H3,
			&Status32Detected1_H3, &Status32Sequence1_H3,
			&ExactMatch322_H3, &Violate322_H3,&index322_H3,
			&Status32Detected2_H3, &Status32Sequence2_H3,
			&ExactMatch22_H3, &Violate22_H3,&index22_H3,
			&Status22Detected_H3, &Status22Sequence_H3
		);
		scalerVIP_film_FWmode_Quick_detection_isr(
			im_di_control_reg.film_enable&2,
			StatusFrameStaticPattern_V1, StatusFramePairPattern_V1,
			StatusNextStaticPattern_V1,StatusNextStaticPattern_film22_V1,
			&ExactMatch321_V1, &Violate321_V1,&index32_V1,
			&Status32Detected1_V1, &Status32Sequence1_V1,
			&ExactMatch322_V1, &Violate322_V1,&index322_V1,
			&Status32Detected2_V1, &Status32Sequence2_V1,
			&ExactMatch22_V1, &Violate22_V1,&index22_V1,
			&Status22Detected_V1, &Status22Sequence_V1
		);
		scalerVIP_film_FWmode_Quick_detection_isr(
			im_di_control_reg.film_enable&2,
			StatusFrameStaticPattern_V2, StatusFramePairPattern_V2,
			StatusNextStaticPattern_V2,StatusNextStaticPattern_film22_V2,
			&ExactMatch321_V2, &Violate321_V2,&index32_V2,
			&Status32Detected1_V2, &Status32Sequence1_V2,
			&ExactMatch322_V2, &Violate322_V2,&index322_V2,
			&Status32Detected2_V2, &Status32Sequence2_V2,
			&ExactMatch22_V2, &Violate22_V2,&index22_V2,
			&Status22Detected_V2, &Status22Sequence_V2
		);
		scalerVIP_film_FWmode_Quick_detection_isr(
			im_di_control_reg.film_enable&2,
			StatusFrameStaticPattern_V3, StatusFramePairPattern_V3,
			StatusNextStaticPattern_V3,StatusNextStaticPattern_film22_V3,
			&ExactMatch321_V3, &Violate321_V3,&index32_V3,
			&Status32Detected1_V3, &Status32Sequence1_V3,
			&ExactMatch322_V3, &Violate322_V3,&index322_V3,
			&Status32Detected2_V3, &Status32Sequence2_V3,
			&ExactMatch22_V3, &Violate22_V3,&index22_V3,
			&Status22Detected_V3, &Status22Sequence_V3
		);
		scalerVIP_film_FWmode_Quick_detection_isr(
			im_di_control_reg.film_enable&2,
			StatusFrameStaticPattern_C, StatusFramePairPattern_C,
			StatusNextStaticPattern_C,StatusNextStaticPattern_film22_C,
			&ExactMatch321_C, &Violate321_C,&index32_C,
			&Status32Detected1_C, &Status32Sequence1_C,
			&ExactMatch322_C, &Violate322_C,&index322_C,
			&Status32Detected2_C, &Status32Sequence2_C,
			&ExactMatch22_C, &Violate22_C,&index22_C,
			&Status22Detected_C, &Status22Sequence_C
		);
		scalerVIP_film_FWmode_Quick_detection_isr(
			im_di_control_reg.film_enable&8,
			StatusFrameStaticPattern, StatusFramePairPattern,
			StatusNextStaticPattern,StatusNextStaticPattern_film22,
			&ExactMatch321, &Violate321,&index32,
			&Status32Detected1, &Status32Sequence1,
			&ExactMatch322, &Violate322,&index322,
			&Status32Detected2, &Status32Sequence2,
			&ExactMatch22, &Violate22,&index22,
			&Status22Detected, &Status22Sequence
		);
	}

	// decision
	// combined sequence of 32 sub-detections
	Sequence_Sub32 = Status32Sequence1_H1|Status32Sequence1_H2|Status32Sequence1_H3|
					Status32Sequence1_V1|Status32Sequence1_V2|Status32Sequence1_V3|
					 Status32Sequence1_C |
					 Status32Sequence2_H1|Status32Sequence2_H2|Status32Sequence2_H3|
					 Status32Sequence2_V1|Status32Sequence2_V2|Status32Sequence2_V3|
					 Status32Sequence2_C |
					 Status32Sequence1   |Status32Sequence2;
	Sequence_Sub32H = Status32Sequence1_H1|Status32Sequence1_H2|Status32Sequence1_H3|
					  Status32Sequence2_H1|Status32Sequence2_H2|Status32Sequence2_H3;

	Sequence_Sub32V = Status32Sequence1_V1|Status32Sequence1_V2|Status32Sequence1_V3|
					  Status32Sequence2_V1|Status32Sequence2_V2|Status32Sequence2_V3;

	// combined sequence of 22 sub-detections
	Sequence_Sub22 = Status22Sequence_H1|Status22Sequence_H2|Status22Sequence_H3|
					 Status22Sequence_V1|Status22Sequence_V2|Status22Sequence_V3|
					 Status22Sequence_C |Status22Sequence;
	Sequence_Sub22H = Status22Sequence_H1|Status22Sequence_H2|Status22Sequence_H3;
	Sequence_Sub22V = Status22Sequence_V1|Status22Sequence_V2|Status22Sequence_V3;
	// combined detected state of 32 sub-detections
	Detected_Sub32 =!(!((Status32Detected1_H1||Status32Detected1_H2||Status32Detected1_H3) ||
					(Status32Detected2_H1||Status32Detected2_H2||Status32Detected2_H3)  ) &&
					   ((Status32Detected1_V1||Status32Detected1_V2||Status32Detected1_V3) ||
					(Status32Detected2_V1||Status32Detected2_V2||Status32Detected2_V3)  )  ) &&
					((Status32Detected1_H1||Status32Detected1_H2||Status32Detected1_H3||
					Status32Detected1_V1||Status32Detected1_V2||Status32Detected1_V3||
					Status32Detected1_C) ||
					(Status32Detected2_H1||Status32Detected2_H2||Status32Detected2_H3||
					Status32Detected2_V1||Status32Detected2_V2||Status32Detected2_V3||
					Status32Detected2_C) );

	Detected_Sub32H = (Sequence_Sub32H!=0);
	Detected_Sub32V = (Sequence_Sub32V!=0);
	// combined detected state of 22 sub-detections
	Detected_Sub22 = (Sequence_Sub22!=0);
	Detected_Sub22H = (Sequence_Sub22H!=0);
	Detected_Sub22V = (Sequence_Sub22V!=0);

	Detected_Sub22 = (!((!(Status22Detected_H1||Status22Detected_H2||Status22Detected_H3)) &&
						(Status22Detected_V1||Status22Detected_V2||Status22Detected_V3) )) &&
					  (Status22Detected_H1||Status22Detected_H2||Status22Detected_H3||
					   Status22Detected_V1||Status22Detected_V2||Status22Detected_V3||
					   Status22Detected_C) ;

	// use exact pattern match detection as any sub detectors violate film mode
	if( Violate321	 ||	Violate322   ||
		Violate321_H1|| Violate321_H2|| Violate321_H3||
		Violate321_V1|| Violate321_V2|| Violate321_V3||
		Violate321_C ||
		Violate322_H1|| Violate322_H2|| Violate322_H3||
		Violate322_V1|| Violate322_V2|| Violate322_V3||
		Violate322_C ||
		MisMatch32)
	{
		Status32Detected1_H1 = ExactMatch321_H1;
		Status32Detected1_H2 = ExactMatch321_H2;
		Status32Detected1_H3 = ExactMatch321_H3;
		Status32Detected1_V1 = ExactMatch321_V1;
		Status32Detected1_V2 = ExactMatch321_V2;
		Status32Detected1_V3 = ExactMatch321_V3;
		Status32Detected1_C  = ExactMatch321_C;
		Status32Detected2_H1 = ExactMatch322_H1;
		Status32Detected2_H2 = ExactMatch322_H2;
		Status32Detected2_H3 = ExactMatch322_H3;
		Status32Detected2_V1 = ExactMatch322_V1;
		Status32Detected2_V2 = ExactMatch322_V2;
		Status32Detected2_V3 = ExactMatch322_V3;
		Status32Detected2_C  = ExactMatch322_C;
	}

	if( Violate22	||
		Violate22_H1||	Violate22_H2||	Violate22_H3||
		Violate22_V1||	Violate22_V2||	Violate22_V3||
		Violate22_C ||
		MisMatch22)
	{
		Status22Detected_H1 = ExactMatch22_H1;
		Status22Detected_H2 = ExactMatch22_H2;
		Status22Detected_H3 = ExactMatch22_H3;
		Status22Detected_V1 = ExactMatch22_V1;
		Status22Detected_V2 = ExactMatch22_V2;
		Status22Detected_V3 = ExactMatch22_V3;
		Status22Detected_C  = ExactMatch22_C;
	}

	Detected_Sub32_Num = (int) (Status32Detected1_H1||Status32Detected2_H1) +
				 (int) (Status32Detected1_H2||Status32Detected2_H2) +
						 (int) (Status32Detected1_H3||Status32Detected2_H3) +
						 (int) (Status32Detected1_V1||Status32Detected2_V1) +
				 (int) (Status32Detected1_V2||Status32Detected2_V2) +
						 (int) (Status32Detected1_V3||Status32Detected2_V3) +
						 (int) (Status32Detected1_C ||Status32Detected2_C ) ;

	Detected_Sub22_Num = (int) Status22Detected_H1 +
				 (int) Status22Detected_H2 +
						 (int) Status22Detected_H3 +
						 (int) Status22Detected_V1 +
					 (int) Status22Detected_V2 +
						 (int) Status22Detected_V3 +
							 (int) Status22Detected_C ;
	MisMatch32 = MisMatch22 = MixedFilmConfuse = 0;
	film_index_Sub32 = index32_H1|index32_H2|index32_H3|
						  index32_V1|index32_V2|index32_V3|index32_C;
	film_index_Sub22 = index22_H1|index22_H2|index22_H3|
						  index22_V1|index22_V2|index22_V3|index22_C;
	film_index_Sub32 = ((
		(int)((film_index_Sub32 & 0x80)>>7)+ (int)((film_index_Sub32 & 0x40)>>6) + (int)((film_index_Sub32 & 0x20)>>5) +
		(int)((film_index_Sub32 & 0x10)>>4)+ (int)((film_index_Sub32 & 0x08)>>3) + (int)((film_index_Sub32 & 0x04)>>2) +
		(int)((film_index_Sub32 & 0x02)>>1)+ (int)((film_index_Sub32 & 0x01)))==1
		)? film_index_Sub32:0;
	film_index_Sub22 = ((
		(int)((film_index_Sub22 & 0x80)>>7)+ (int)((film_index_Sub22 & 0x40)>>6) + (int)((film_index_Sub22 & 0x20)>>5) +
		(int)((film_index_Sub22 & 0x10)>>4)+ (int)((film_index_Sub22 & 0x08)>>3) + (int)((film_index_Sub22 & 0x04)>>2) +
		(int)((film_index_Sub22 & 0x02)>>1)+ (int)((film_index_Sub22 & 0x01)))==1
		)? film_index_Sub22:0;

	Detected_Sub32_Num = (film_index_Sub32==0)? 0:Detected_Sub32_Num;
	Detected_Sub22_Num = (film_index_Sub22==0)? 0:Detected_Sub22_Num;
	film_index_Sub32 = (Detected_Sub32_Num==0)? 0:film_index_Sub32;
	film_index_Sub22 = (Detected_Sub22_Num==0)? 0:film_index_Sub22;

	// film detection rule
	// detect whole 32 film by 32detection1
	if(Status32Detected1 && hw_film_32Film !=0)
	{
		StatusFilmDetected = Status32Detected1;
		StatusFilmSequence = Status32Sequence1;
		StatusMixedFilmDetected = 0;
		film_index=index32;

		// exit film as detect 22 with different weave direction too
		if( Detected_Sub22 && !filmQuick_en)
		{
			switch(film_index)
			{
				case FILM32:
					if(((Sequence_Sub22==1 && (StatusFilmSequence==2 || StatusFilmSequence==4 || StatusFilmSequence==16)) ||
						(Sequence_Sub22==2 && (StatusFilmSequence==1 || StatusFilmSequence==8)))
					)
					{
						StatusFilmDetected = 0;
						MixedFilmConfuse = 1;
					}
					break;
				case FILM3223:
					if(((Sequence_Sub22==1 && (StatusFilmSequence==4 || StatusFilmSequence==8 || StatusFilmSequence==32 || StatusFilmSequence==128 || StatusFilmSequence==512 || StatusFilmSequence==1)) ||
						(Sequence_Sub22==2 && (StatusFilmSequence==2 || StatusFilmSequence==16 || StatusFilmSequence==64 || StatusFilmSequence==256)))
					)
					{
						StatusFilmDetected = 0;
						MixedFilmConfuse = 1;
					}
					break;
				case FILM64:
					if(((Sequence_Sub22==1 && (StatusFilmSequence==1 || StatusFilmSequence==64)) ||
						(Sequence_Sub22==2 && (StatusFilmSequence==2 || StatusFilmSequence==128)))
					)
					{
						StatusFilmDetected = 0;
						MixedFilmConfuse = 1;
					}
					break;
				case FILM55:
					if(((Sequence_Sub22==1 && (StatusFilmSequence==1)) ||
						(Sequence_Sub22==2 && (StatusFilmSequence==2)))
					)
					{
						StatusFilmDetected = 0;
						MixedFilmConfuse = 1;
					}
					break;
				case FILM2224:
					if(film_index_Sub22==FILM22)
					{
						if(((Sequence_Sub22==1 && (StatusFilmSequence==1 || StatusFilmSequence==4 || StatusFilmSequence==16 || StatusFilmSequence==64)) ||
							(Sequence_Sub22==2 && (StatusFilmSequence==2 || StatusFilmSequence==8 || StatusFilmSequence==32 || StatusFilmSequence==128)))
						)
						{
							StatusFilmDetected = 0;
							MixedFilmConfuse = 1;

						}
					}
					else if(film_index_Sub22==FILM2224)
					{
						/*
						if(Sequence_Sub22!=StatusFilmSequence)
						{
							StatusFilmDetected = 0;
							MixedFilmConfuse = 1;

						}
						*/
					}

					break;
				case FILM32322:
					if(((Sequence_Sub22==1 && (StatusFilmSequence==1 || StatusFilmSequence==8 || StatusFilmSequence==32 || StatusFilmSequence==256 || StatusFilmSequence==1024)) ||
						(Sequence_Sub22==2 && (StatusFilmSequence==2 || StatusFilmSequence==16 || StatusFilmSequence==64 || StatusFilmSequence==512 || StatusFilmSequence==2048)))
					)
					{
						StatusFilmDetected = 0;
						MixedFilmConfuse = 1;
					}
					break;
				case FILM87:
					if(((Sequence_Sub22==1 && (StatusFilmSequence==1 || StatusFilmSequence==256)) ||
						(Sequence_Sub22==2 && (StatusFilmSequence==2 || StatusFilmSequence==512)))
					)
					{
						StatusFilmDetected = 0;
						MixedFilmConfuse = 1;
					}
					break;
				default:
					{
						StatusFilmDetected = 0;
						MixedFilmConfuse = 1;
					}
						break;
			}
		}
	}
	// detect whole 32 film by 32detection2
	else if(Status32Detected2 && hw_film_32Film !=0)
	{
		StatusFilmDetected = Status32Detected2;
		StatusFilmSequence = Status32Sequence2;
		StatusMixedFilmDetected = 0;
		film_index=index322;
		// exit film as detect 22 with different weave direction too
		if(Detected_Sub22 && !filmQuick_en &&
			((Sequence_Sub22==1 && (StatusFilmSequence==2 || StatusFilmSequence==4 || StatusFilmSequence==16)) ||
			 (Sequence_Sub22==2 && (StatusFilmSequence==1 || StatusFilmSequence==8))))
		{
			StatusFilmDetected = 0;
			MixedFilmConfuse = 1;
		}
	}
	// detect whole 22 film by 22detection
	else if(Status22Detected && hw_film_22Film!=0)
	{
		StatusFilmDetected = Status22Detected;
		StatusFilmSequence = Status22Sequence;
		StatusMixedFilmDetected = 0;
		film_index=index22;
		// exit film as detect 32 with different weave direction too
		if(Detected_Sub32 && !filmQuick_en)
		{
			switch(film_index_Sub32)
			{
				case FILM32:
					if(((StatusFilmSequence==1 && (Sequence_Sub32==2 || Sequence_Sub32==4 || Sequence_Sub32==16)) ||
						(StatusFilmSequence==2 && (Sequence_Sub32==1 || Sequence_Sub32==8)))
					)
					{
						StatusFilmDetected = 0;
						MixedFilmConfuse = 1;
					}
					break;
				case FILM3223:
					if(((StatusFilmSequence==1 && (Sequence_Sub32==4 || Sequence_Sub32==8 || Sequence_Sub32==32 || Sequence_Sub32==128 || Sequence_Sub32==512 || Sequence_Sub32==1)) ||
						(StatusFilmSequence==2 && (Sequence_Sub32==2 || Sequence_Sub32==16 || Sequence_Sub32==64 || Sequence_Sub32==256)))
					)
					{
						StatusFilmDetected = 0;
						MixedFilmConfuse = 1;
					}
					break;
				case FILM64:
					if(((StatusFilmSequence==1 && (Sequence_Sub32==1 || Sequence_Sub32==64)) ||
						(StatusFilmSequence==2 && (Sequence_Sub32==2 || Sequence_Sub32==128)))
					)
					{
						StatusFilmDetected = 0;
						MixedFilmConfuse = 1;
					}
					break;
				case FILM55:
					if(((StatusFilmSequence==1 && (Sequence_Sub32==1)) ||
						(StatusFilmSequence==2 && (Sequence_Sub32==2)))
					)
					{
						StatusFilmDetected = 0;
						MixedFilmConfuse = 1;
					}
					break;
				case FILM2224:
					if(((StatusFilmSequence==1 && (Sequence_Sub32==1 || Sequence_Sub32==4 || Sequence_Sub32==16 || Sequence_Sub32==64)) ||
						(StatusFilmSequence==2 && (Sequence_Sub32==2 || Sequence_Sub32==8 || Sequence_Sub32==32 || Sequence_Sub32==128)))
					)
					{
						StatusFilmDetected = 0;
						MixedFilmConfuse = 1;
					}
					break;
				case FILM32322:
					if(((StatusFilmSequence==1 && (Sequence_Sub32==1 || Sequence_Sub32==8 || Sequence_Sub32==32 || Sequence_Sub32==256 || Sequence_Sub32==1024)) ||
						(StatusFilmSequence==2 && (Sequence_Sub32==2 || Sequence_Sub32==16 || Sequence_Sub32==64 || Sequence_Sub32==512 || Sequence_Sub32==2048)))
					)
					{
						StatusFilmDetected = 0;
						MixedFilmConfuse = 1;
					}
					break;
				case FILM87:
					if(((StatusFilmSequence==1 && (Sequence_Sub32==1 || Sequence_Sub32==256)) ||
						(StatusFilmSequence==2 && (Sequence_Sub32==2 || Sequence_Sub32==512)))
					)
					{
						StatusFilmDetected = 0;
						MixedFilmConfuse = 1;
					}
					break;

				default:
					{
						StatusFilmDetected = 0;
						MixedFilmConfuse = 1;
					}
					break;

			}
		}

	}
	else
	{
		StatusFilmDetected = 0;
		film_index=0;
		StatusFilmSequence=0;
		StatusMixedFilmDetected = 0;

	#if 0
		unsigned char thumbnail_case1,thumbnail_case2,thumbnail_case3;
		// 32 sub film detected
		if( Detected_Sub32_Num && (hw_film_32Film  ==2) )
		{
			StatusMixedFilmDetected = 1;
			StatusFilmSequence = Sequence_Sub32;
			film_index=film_index_Sub32;
			// exit film as detect 22 with different weave direction too
			if(Detected_Sub22 && !filmQuick_en)
			{
				switch(film_index)
				{
					case FILM32:
						if(((Sequence_Sub22==1 && (StatusFilmSequence==2 || StatusFilmSequence==4 || StatusFilmSequence==16)) ||
							(Sequence_Sub22==2 && (StatusFilmSequence==1 || StatusFilmSequence==8)))
						)
						{
							StatusMixedFilmDetected = 0;
							MixedFilmConfuse = 1;
						}
						break;
					case FILM3223:
						if(((Sequence_Sub22==1 && (StatusFilmSequence==4 || StatusFilmSequence==8 || StatusFilmSequence==32 || StatusFilmSequence==128 || StatusFilmSequence==512 || StatusFilmSequence==1)) ||
							(Sequence_Sub22==2 && (StatusFilmSequence==2 || StatusFilmSequence==16 || StatusFilmSequence==64 || StatusFilmSequence==256)))
						)
						{
							StatusMixedFilmDetected = 0;
							MixedFilmConfuse = 1;
						}
						break;
					case FILM64:
						if(((Sequence_Sub22==1 && (StatusFilmSequence==1 || StatusFilmSequence==64)) ||
							(Sequence_Sub22==2 && (StatusFilmSequence==2 || StatusFilmSequence==128)))
						)
						{
							StatusMixedFilmDetected = 0;
							MixedFilmConfuse = 1;
						}
						break;
					case FILM55:
						if(((Sequence_Sub22==1 && (StatusFilmSequence==1)) ||
							(Sequence_Sub22==2 && (StatusFilmSequence==2)))
						)
						{
							StatusMixedFilmDetected = 0;
							MixedFilmConfuse = 1;
						}
						break;
					case FILM2224:
						if(((Sequence_Sub22==1 && (StatusFilmSequence==1 || StatusFilmSequence==4 || StatusFilmSequence==16 || StatusFilmSequence==64)) ||
							(Sequence_Sub22==2 && (StatusFilmSequence==2 || StatusFilmSequence==8 || StatusFilmSequence==32 || StatusFilmSequence==128)))
						)
						{
							StatusMixedFilmDetected = 0;
							MixedFilmConfuse = 1;
						}
						break;
					case FILM32322:
						if(((Sequence_Sub22==1 && (StatusFilmSequence==1 || StatusFilmSequence==8 || StatusFilmSequence==32 || StatusFilmSequence==256 || StatusFilmSequence==1024)) ||
							(Sequence_Sub22==2 && (StatusFilmSequence==2 || StatusFilmSequence==16 || StatusFilmSequence==64 || StatusFilmSequence==512 || StatusFilmSequence==2048)))
						)
						{
							StatusMixedFilmDetected = 0;
							MixedFilmConfuse = 1;
						}
						break;
					case FILM87:
						if(((Sequence_Sub22==1 && (StatusFilmSequence==1 || StatusFilmSequence==256)) ||
							(Sequence_Sub22==2 && (StatusFilmSequence==2 || StatusFilmSequence==512)))
						)
						{
							StatusMixedFilmDetected = 0;
							MixedFilmConfuse = 1;
						}
						break;
					default:
						{
							StatusMixedFilmDetected = 0;
							MixedFilmConfuse = 1;
						}
						break;
				}
			}
			// exit film as detect different sequences
			else if((Status32Sequence1_H1!=0 && StatusFilmSequence!=Status32Sequence1_H1)||
					(Status32Sequence1_H2!=0 && StatusFilmSequence!=Status32Sequence1_H2)||
					(Status32Sequence1_H3!=0 && StatusFilmSequence!=Status32Sequence1_H3)||
					(Status32Sequence1_V1!=0 && StatusFilmSequence!=Status32Sequence1_V1)||
					(Status32Sequence1_V2!=0 && StatusFilmSequence!=Status32Sequence1_V2)||
					(Status32Sequence1_V3!=0 && StatusFilmSequence!=Status32Sequence1_V3)||
					(Status32Sequence1_C!=0 && StatusFilmSequence!=Status32Sequence1_C)||
					(Status32Sequence2_H1!=0 && StatusFilmSequence!=Status32Sequence2_H1)||
					(Status32Sequence2_H2!=0 && StatusFilmSequence!=Status32Sequence2_H2)||
					(Status32Sequence2_H3!=0 && StatusFilmSequence!=Status32Sequence2_H3)||
					(Status32Sequence2_V1!=0 && StatusFilmSequence!=Status32Sequence2_V1)||
					(Status32Sequence2_V2!=0 && StatusFilmSequence!=Status32Sequence2_V2)||
					(Status32Sequence2_V3!=0 && StatusFilmSequence!=Status32Sequence2_V3)||
					(Status32Sequence2_C!=0 && StatusFilmSequence!=Status32Sequence2_C))
			{
				MisMatch32 = 1;
				StatusMixedFilmDetected = 0;
			}
			else if(!Detected_Sub32H && Detected_Sub32V)
			{
				//V1 is film, V2 or V3 is still (1073 play thumbnail)
				thumbnail_case1=(Status32Sequence1_V1|Status32Sequence2_V1) &&
								( ( (StatusFrameStaticPattern_V2&1) && (StatusPrevStaticPattern_V2&1) && (StatusNextStaticPattern_V2&1) ) ||
								  ( (StatusFrameStaticPattern_V3&1) && (StatusPrevStaticPattern_V3&1) && (StatusNextStaticPattern_V3&1) )   );
				//V2 is film, V1 or V3 is still
				thumbnail_case2=(Status32Sequence1_V2|Status32Sequence2_V2) &&
								( ( (StatusFrameStaticPattern_V1&1) && (StatusPrevStaticPattern_V1&1) && (StatusNextStaticPattern_V1&1) ) ||
								  ( (StatusFrameStaticPattern_V3&1) && (StatusPrevStaticPattern_V3&1) && (StatusNextStaticPattern_V3&1) )   );
				//V3 is film, V1 or V2 is still
				thumbnail_case3=(Status32Sequence1_V3|Status32Sequence2_V3) &&
								( ( (StatusFrameStaticPattern_V1&1) && (StatusPrevStaticPattern_V1&1) && (StatusNextStaticPattern_V1&1) ) ||
								  ( (StatusFrameStaticPattern_V2&1) && (StatusPrevStaticPattern_V2&1) && (StatusNextStaticPattern_V2&1) )   );

				if( hw_film_thumbnail_en && (thumbnail_case1 || thumbnail_case2 || thumbnail_case3) )
				{
					//StatusMixedFilmDetected = 1;
				}
				else if(hw_film_VerScrollingText_en)//vertical scrolling text
					StatusMixedFilmDetected = 0;
			}
		}
		// 22 sub film detected
		else if((Detected_Sub22_Num>2) && (hw_film_22Film == 2))
		{
			StatusMixedFilmDetected = 1;
			StatusFilmSequence = Sequence_Sub22;
			film_index=film_index_Sub22;
			// exit film as detect 32 with different weave direction too
			if(Detected_Sub32 && !filmQuick_en)
			{
				switch(film_index_Sub32)
				{
					case FILM32:
						if(((Sequence_Sub22==1 && (StatusFilmSequence==2 || StatusFilmSequence==4 || StatusFilmSequence==16)) ||
							(Sequence_Sub22==2 && (StatusFilmSequence==1 || StatusFilmSequence==8)))
						)
						{
							StatusMixedFilmDetected = 0;
							MixedFilmConfuse = 1;
						}
						break;
					case FILM3223:
						if(((Sequence_Sub22==1 && (StatusFilmSequence==4 || StatusFilmSequence==8 || StatusFilmSequence==32 || StatusFilmSequence==128 || StatusFilmSequence==512 || StatusFilmSequence==1)) ||
							(Sequence_Sub22==2 && (StatusFilmSequence==2 || StatusFilmSequence==16 || StatusFilmSequence==64 || StatusFilmSequence==256)))
						)
						{
							StatusMixedFilmDetected = 0;
							MixedFilmConfuse = 1;
						}
						break;
					case FILM64:
						if(((Sequence_Sub22==1 && (StatusFilmSequence==1 || StatusFilmSequence==64)) ||
							(Sequence_Sub22==2 && (StatusFilmSequence==2 || StatusFilmSequence==128)))
						)
						{
							StatusMixedFilmDetected = 0;
							MixedFilmConfuse = 1;
						}
						break;
					case FILM55:
						if(((Sequence_Sub22==1 && (StatusFilmSequence==1)) ||
							(Sequence_Sub22==2 && (StatusFilmSequence==2)))
						)
						{
							StatusMixedFilmDetected = 0;
							MixedFilmConfuse = 1;
						}
						break;
					case FILM2224:
						if(((Sequence_Sub22==1 && (StatusFilmSequence==1 || StatusFilmSequence==4 || StatusFilmSequence==16 || StatusFilmSequence==64)) ||
							(Sequence_Sub22==2 && (StatusFilmSequence==2 || StatusFilmSequence==8 || StatusFilmSequence==32 || StatusFilmSequence==128)))
						)
						{
							StatusMixedFilmDetected = 0;
							MixedFilmConfuse = 1;
						}
						break;
					case FILM32322:
						if(((Sequence_Sub22==1 && (StatusFilmSequence==1 || StatusFilmSequence==8 || StatusFilmSequence==32 || StatusFilmSequence==256 || StatusFilmSequence==1024)) ||
							(Sequence_Sub22==2 && (StatusFilmSequence==2 || StatusFilmSequence==16 || StatusFilmSequence==64 || StatusFilmSequence==512 || StatusFilmSequence==2048)))
						)
						{
							StatusMixedFilmDetected = 0;
							MixedFilmConfuse = 1;
						}
						break;
					case FILM87:
						if(((Sequence_Sub22==1 && (StatusFilmSequence==1 || StatusFilmSequence==256)) ||
							(Sequence_Sub22==2 && (StatusFilmSequence==2 || StatusFilmSequence==512)))
						)
						{
							StatusMixedFilmDetected = 0;
							MixedFilmConfuse = 1;
						}
						break;
					default:
						{
							StatusMixedFilmDetected = 0;
							MixedFilmConfuse = 1;
						}
						break;
				}
			}
			else if((Status22Sequence_H1!=0 && StatusFilmSequence!=Status22Sequence_H1)||
					(Status22Sequence_H2!=0 && StatusFilmSequence!=Status22Sequence_H2)||
					(Status22Sequence_H3!=0 && StatusFilmSequence!=Status22Sequence_H3)||
					(Status22Sequence_V1!=0 && StatusFilmSequence!=Status22Sequence_V1)||
					(Status22Sequence_V2!=0 && StatusFilmSequence!=Status22Sequence_V2)||
					(Status22Sequence_V3!=0 && StatusFilmSequence!=Status22Sequence_V3)||
					(Status22Sequence_C!=0 && StatusFilmSequence!=Status22Sequence_C))
			{
				MisMatch22 = 1;
				StatusMixedFilmDetected = 0;
			}
			else if(!Detected_Sub22H && Detected_Sub22V)
			{
				//V1 is film, V2 or V3 is still (1073 play thumbnail)
				thumbnail_case1=(Status22Sequence_V1) &&
								( ( (StatusFrameStaticPattern_V2&1) && (StatusPrevStaticPattern_V2&1) && (StatusNextStaticPattern_V2&1) ) ||
								( (StatusFrameStaticPattern_V3&1) && (StatusPrevStaticPattern_V3&1) && (StatusNextStaticPattern_V3&1) )   );
				//V2 is film, V1 or V3 is still
				thumbnail_case2=(Status22Sequence_V2) &&
								( ( (StatusFrameStaticPattern_V1&1) && (StatusPrevStaticPattern_V1&1) && (StatusNextStaticPattern_V1&1) ) ||
								( (StatusFrameStaticPattern_V3&1) && (StatusPrevStaticPattern_V3&1) && (StatusNextStaticPattern_V3&1) )   );
				//V3 is film, V1 or V2 is still
				thumbnail_case3=(Status22Sequence_V3) &&
								( ( (StatusFrameStaticPattern_V1&1) && (StatusPrevStaticPattern_V1&1) && (StatusNextStaticPattern_V1&1) ) ||
								  ( (StatusFrameStaticPattern_V2&1) && (StatusPrevStaticPattern_V2&1) && (StatusNextStaticPattern_V2&1) )   );

				if( hw_film_thumbnail_en && (thumbnail_case1 || thumbnail_case2 || thumbnail_case3) )
				{
					//StatusMixedFilmDetected = 1;
				}
				else if(hw_film_VerScrollingText_en)//vertical scrolling text
					StatusMixedFilmDetected = 0;
			}

		}
		// no any film mode detected
		else
		{
			StatusMixedFilmDetected = 0;
			StatusFilmSequence = 0;
		}
	#endif
	}

#define bad_edit_test 0
	SmartPic_clue->film_bad_edit_det = 0;
	if(bad_edit_test)
	{
		unsigned char Status22Detected_noH3 = 0;
		int Status22Sequence_noH3 = 0;

		//	for HQV BD - football court 22
		//	(H1 && H2 && V1 && V3 && C) && (All - H3) && (H3 inverse)

		NextDiff_noH3 = NextDiff - NextDiff_H3;

		if(NextDiff_noH3 < (hw_FieldStaticSumThl *2))
			Film22_StatusNextStaticPattern_noH3 = (Film22_StatusNextStaticPattern_noH3<<1)+1;
		else
			Film22_StatusNextStaticPattern_noH3 = Film22_StatusNextStaticPattern_noH3<<1;

		if((Film22_StatusNextStaticPattern_noH3 & 0xffff) == 0xaaaa)
		{
			Status22Detected_noH3 = 1;
			Status22Sequence_noH3 = (fw_DI_3A) ? 1 : 2;
		}
		else if((Film22_StatusNextStaticPattern_noH3 & 0xffff) == 0x5555)
		{
			Status22Detected_noH3 = 1;
			Status22Sequence_noH3 = (fw_DI_3A) ? 2 : 1;
		}
		else
		{
			Status22Detected_noH3 = 0;
			Status22Sequence_noH3 = 0;
		}

		if((((int)Status22Detected_H1 + (int)Status22Detected_H2
			+ (int)Status22Detected_V1 + (int)Status22Detected_V3
			+ (int)Status22Detected_C)>=3) &&
			(Status22Detected_noH3) &&
			(Status22Detected_H3 && (Status22Sequence_H3 != Status22Sequence_noH3))
		)
		{
			SmartPic_clue->film_bad_edit_det = 1;
		}
		else
		{
			SmartPic_clue->film_bad_edit_det = 0;
		}

		if(SmartPic_clue->film_bad_edit_det)
		{
			StatusFilmDetected = 1;
			film_index = FILM22;
			StatusFilmSequence = Status22Sequence_noH3;
		}
	}

	// weave
	if(StatusFilmDetected || StatusMixedFilmDetected)
	{
		StatusFilmWeaveMode = 2;
		Weave_Mode_d = 2;
		force_weave_flag=0;
		if(film_index==FILM22) // 22
		{
			StatusFilmSequence_tmp = StatusFilmSequence << (im_di_film_new_function_main_reg.fw_film_doublebuffer_en);
			StatusFilmSequence_tmp = (StatusFilmSequence_tmp == 4)? 1:StatusFilmSequence_tmp;
			switch(StatusFilmSequence_tmp)
			{
				case 1:// 2:// 1:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				case 2:// 1:// 2:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 0;
					break;
				default:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
			}
		}
		else if(film_index==FILM32)  // 32
		{
			StatusFilmSequence_tmp = StatusFilmSequence << (im_di_film_new_function_main_reg.fw_film_doublebuffer_en);
			StatusFilmSequence_tmp = (StatusFilmSequence_tmp == 32)? 1:StatusFilmSequence_tmp;

			if (StatusFilmSequence_tmp == 1 || StatusFilmSequence_tmp == 8)
				StatusFilmWeaveMode = 1;

			if (StatusFilmSequence_tmp == 2 || StatusFilmSequence_tmp == 16)
				Weave_Mode_d = 0;
			/*
			switch(StatusFilmSequence_tmp)
			{
				case 1:// 16:// 1:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				case 2:// 1:// 2:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 0;
					break;
				case 4:// 2:// 4:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 8:// 4:// 8:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				case 16:// 8:// 16:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 0;
					break;
				default:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
			}
			*/
		}
		else if(film_index==FILM3223 && film3223_en) // 3223
		{
			StatusFilmSequence_tmp = StatusFilmSequence << (im_di_film_new_function_main_reg.fw_film_doublebuffer_en);
			StatusFilmSequence_tmp = (StatusFilmSequence_tmp == 1024)? 1:StatusFilmSequence_tmp;

			if (StatusFilmSequence_tmp == 2 || StatusFilmSequence_tmp == 16 ||
				StatusFilmSequence_tmp == 64 || StatusFilmSequence_tmp == 256)
				StatusFilmWeaveMode = 1;

			if (StatusFilmSequence_tmp == 4 || StatusFilmSequence_tmp == 32 ||
				StatusFilmSequence_tmp == 128 || StatusFilmSequence_tmp == 512)
				Weave_Mode_d = 0;

			/*
			switch(StatusFilmSequence_tmp)
			{
				case 1:// 512:// 1:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 2:// 1:// 2:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				case 4:// 2:// 4:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 0;
					break;
				case 8:// 4:// 8:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 16:// 8:// 16:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				case 32:// 16:// 32:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 0;
					break;
				case 64:// 32:// 64:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				case 128:// 64:// 128:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 0;
					break;
				case 256:// 128:// 256:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				case 512:// 256:// 512:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 0;
					break;
				default:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
			}
			*/
		}
		else if(film_index==FILM64 && film64_en) // 64
		{
			StatusFilmSequence_tmp = StatusFilmSequence << (im_di_film_new_function_main_reg.fw_film_doublebuffer_en);
			StatusFilmSequence_tmp = (StatusFilmSequence_tmp == 1024)? 1:StatusFilmSequence_tmp;

			if (StatusFilmSequence_tmp == 2 || StatusFilmSequence_tmp == 128)
				StatusFilmWeaveMode = 1;

			if (StatusFilmSequence_tmp == 4 || StatusFilmSequence_tmp == 256)
				Weave_Mode_d = 0;

			/*
			switch(StatusFilmSequence_tmp)
			{
				case 1:// 512:// 1:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 2:// 1:// 2:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				case 4:// 2:// 4:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 0;
					break;
				case 8:// 4:// 8:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 16:// 8:// 16:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 32:// 16:// 32:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 64:// 32:// 64:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 128:// 64:// 128:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				case 256:// 128:// 256:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 0;
					break;
				case 512:// 256:// 512:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				default:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
			}
			*/
		}
		else if(film_index==FILM55 && film55_en) // 55
		{
			StatusFilmSequence_tmp = StatusFilmSequence << (im_di_film_new_function_main_reg.fw_film_doublebuffer_en);
			StatusFilmSequence_tmp = (StatusFilmSequence_tmp == 32)? 1:StatusFilmSequence_tmp;

			if (StatusFilmSequence_tmp == 2)
				StatusFilmWeaveMode = 1;

			if (StatusFilmSequence_tmp == 4)
				Weave_Mode_d = 0;

			/*
			switch(StatusFilmSequence_tmp)
			{
				case 1:// 16:// 1:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 2:// 1:// 2:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				case 4:// 2:// 4:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 0;
					break;
				case 8:// 4:// 8:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 16:// 8:// 16:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				default:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
			}
			*/
		}
		else if(film_index==FILM2224 && film2224_en) // 2224
		{
			StatusFilmSequence_tmp = StatusFilmSequence << (im_di_film_new_function_main_reg.fw_film_doublebuffer_en);
			StatusFilmSequence_tmp = (StatusFilmSequence_tmp == 1024)? 1:StatusFilmSequence_tmp;

			if (StatusFilmSequence_tmp == 2 || StatusFilmSequence_tmp == 8 ||
				StatusFilmSequence_tmp == 32 || StatusFilmSequence_tmp == 128)
				StatusFilmWeaveMode = 1;

			if (StatusFilmSequence_tmp == 4 || StatusFilmSequence_tmp == 16 ||
				StatusFilmSequence_tmp == 64 || StatusFilmSequence_tmp == 256)
				Weave_Mode_d = 0;
			/*
			switch(StatusFilmSequence_tmp)
			{
				case 1:// 512:// 1:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 2:// 1:// 2:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				case 4:// 2:// 4:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 0;
					break;
				case 8:// 4:// 8:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				case 16:// 8:// 16:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 0;
					break;
				case 32:// 16:// 32:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				case 64:// 32:// 64:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 0;
					break;
				case 128:// 64:// 128:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				case 256:// 128:// 256:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 0;
					break;
				case 512:// 256:// 512:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				default:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
			}
			*/
		}
		else if(film_index==FILM32322 && film32322_en) // 32322
		{
			StatusFilmSequence_tmp = StatusFilmSequence << (im_di_film_new_function_main_reg.fw_film_doublebuffer_en);
			StatusFilmSequence_tmp = (StatusFilmSequence_tmp == 4096)? 1:StatusFilmSequence_tmp;

			if (StatusFilmSequence_tmp == 2 || StatusFilmSequence_tmp == 16 ||
				StatusFilmSequence_tmp == 64 || StatusFilmSequence_tmp == 512 ||
				StatusFilmSequence_tmp == 2048)
				StatusFilmWeaveMode = 1;

			if (StatusFilmSequence_tmp == 1 || StatusFilmSequence_tmp == 32 ||
				StatusFilmSequence_tmp == 1024)
				Weave_Mode_d = 0;
			/*
			switch(StatusFilmSequence_tmp)
			{
				case 1:// 2048:// 1:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 0;
					break;
				case 2:// 1:// 2:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				case 4:// 2:// 4:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 8:// 4:// 8:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 16:// 8:// 16:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				case 32:// 16:// 32:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 0;
					break;
				case 64:// 32:// 64:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				case 128:// 64:// 128:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 256:// 128:// 256:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 512:// 256:// 512:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				case 1024:// 512:// 1024:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 0;
					break;
				case 2048:// 1024:// 2048:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				default:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
			}
			*/
		}
		else if(film_index==FILM87 && film87_en) // 87
		{
			StatusFilmSequence_tmp = StatusFilmSequence << (im_di_film_new_function_main_reg.fw_film_doublebuffer_en);
			StatusFilmSequence_tmp = (StatusFilmSequence_tmp == 32768)? 1:StatusFilmSequence_tmp;
			if (StatusFilmSequence_tmp == 2 || StatusFilmSequence_tmp == 512)
				StatusFilmWeaveMode = 1;

			if (StatusFilmSequence_tmp == 4 || StatusFilmSequence_tmp == 1024)
				Weave_Mode_d = 0;

			/*
			switch(StatusFilmSequence_tmp)
			{
				case 1:// 16384:// 1:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 2:// 1:// 2:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				case 4:// 2:// 4:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 0;
					break;
				case 8:// 4:// 8:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 16:// 8:// 16:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 32:// 16:// 32:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 64:// 32:// 64:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 128:// 64:// 128:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 256:// 128:// 256:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 512:// 256:// 512:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				case 1024:// 512:// 1024:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 0;
					break;
				case 2048:// 1024:// 2048:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 4096:// 2048:// 4096:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 8192:// 4096:// 8192:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 16384:// 8192:// 16384:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				default:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
			}
			*/
		}
		else//chris 20130220
		{
			StatusFilmDetected=0;
			StatusMixedFilmDetected = 0;
			StatusFilmSequence = 0;
		}
	}
	else
	{
		switch(StatusFilmSequence)
		{
			case 1:
				StatusFilmWeaveMode = 1;
				Weave_Mode_d = 2;
				break;
			case 2:
				StatusFilmWeaveMode = 2;
				Weave_Mode_d = 0;
				break;
			default:
				StatusFilmWeaveMode = 2;
				Weave_Mode_d = 2;
				break;
		}
		if(fw_film_control_force_weave_en)
		{
			if(!force_weave_flag && ((StatusFrameStaticPattern&3)==1) && !hw_film_BadEditor_flag)
			{
				force_weave_flag=1;
				weave_prev=1;
			}
			else if(force_weave_flag && ((StatusFrameStaticPattern&1)==1) && !hw_film_BadEditor_flag)
			{
				StatusFilmWeaveMode = 2;
				Weave_Mode_d = 2;
				weave_prev=1;
			}
			else if(force_weave_flag && ((StatusFrameStaticPattern&1)==0) && weave_prev && ((((StatusPrevStaticPattern&1)==1) && ((StatusNextStaticPattern&2)==2)) || (StatusFramePairPattern&7)==1) && !hw_film_BadEditor_flag)
			{
				StatusFilmWeaveMode =  (fw_DI_3A) ? 1:2;
				Weave_Mode_d = (fw_DI_3A) ? 2:0;
				weave_prev=!weave_prev;
			}
			else if(force_weave_flag && ((StatusFrameStaticPattern&1)==0) && !weave_prev && ((((StatusPrevStaticPattern&2)==2) && ((StatusNextStaticPattern&1)==1)) || (StatusFramePairPattern&11)==2) && !hw_film_BadEditor_flag)
			{
				StatusFilmWeaveMode = (fw_DI_3A)? 2:1;
				Weave_Mode_d =	(fw_DI_3A) ? 0:2;
				weave_prev=!weave_prev;
			}
			else
				force_weave_flag=0;
		}
	}

	// determine mixedfilm region
	hw_PrevTopMark = im_di_film_mark_prev1_reg.film_prevtopmark1;
	hw_PrevBotMark = im_di_film_mark_prev1_reg.film_prevbotmark1;
	hw_PrevTopMark2 = im_di_film_mark_prev2_reg.film_prevtopmark2;
	hw_PrevBotMark2 = im_di_film_mark_prev2_reg.film_prevbotmark2;
	hw_PrevTopMark3 = im_di_film_mark_prev3_reg.film_prevtopmark3;
	hw_PrevBotMark3 = im_di_film_mark_prev3_reg.film_prevbotmark3;
	hw_NextTopMark = im_di_film_mark_next1_reg.film_nexttopmark1;
	hw_NextBotMark = im_di_film_mark_next1_reg.film_nextbotmark1;
	hw_NextTopMark2 = im_di_film_mark_next2_reg.film_nexttopmark2;
	hw_NextBotMark2 = im_di_film_mark_next2_reg.film_nextbotmark2;
	hw_NextTopMark3 = im_di_film_mark_next3_reg.film_nexttopmark3;
	hw_NextBotMark3 = im_di_film_mark_next3_reg.film_nextbotmark3;

	hw_PrevTopMarkp = hw_PrevTopMark*2;
	hw_PrevBotMarkp = hw_PrevBotMark*2;
	hw_PrevTopMark2p = hw_PrevTopMark2*2;
	hw_PrevBotMark2p = hw_PrevBotMark2*2;
	hw_PrevTopMark3p = hw_PrevTopMark3*2;
	hw_PrevBotMark3p = hw_PrevBotMark3*2;

	hw_NextTopMarkp = hw_NextTopMark*2;
	hw_NextBotMarkp = hw_NextBotMark*2;
	hw_NextTopMark2p = hw_NextTopMark2*2;
	hw_NextBotMark2p = hw_NextBotMark2*2;
	hw_NextTopMark3p = hw_NextTopMark3*2;
	hw_NextBotMark3p = hw_NextBotMark3*2;

	PrevTopLine = (hw_PrevTopMarkp>MarkMargin) ? hw_PrevTopMarkp-MarkMargin : 0;
	PrevBotLine = hw_PrevBotMarkp + MarkMargin +2;
	PrevTopLine2 = hw_PrevTopMark2p - MarkMargin;
	PrevBotLine2 = hw_PrevBotMark2p + MarkMargin +2;
	PrevTopLine3 = hw_PrevTopMark3p - MarkMargin;
	PrevBotLine3 = hw_PrevBotMark3p + MarkMargin +2;

	PrevTopLine = (hw_PrevTopMark==0x7ef)? 0x800:PrevTopLine;
	PrevBotLine = (hw_PrevBotMark==0x7ef)? 0x800:PrevBotLine;
	PrevTopLine2 = (hw_PrevTopMark2==0x7ef)? 0x800:PrevTopLine2;
	PrevBotLine2 = (hw_PrevBotMark2==0x7ef)? 0x800:PrevBotLine2;
	PrevTopLine3 = (hw_PrevTopMark3==0x7ef)? 0x800:PrevTopLine3;
	PrevBotLine3 = (hw_PrevBotMark3==0x7ef)? 0x800:PrevBotLine3;

	NextTopLine = (hw_NextTopMarkp>MarkMargin) ? hw_NextTopMarkp-MarkMargin : 0;
	NextBotLine = hw_NextBotMarkp + MarkMargin +2;
	NextTopLine2 = hw_NextTopMark2p - MarkMargin;
	NextBotLine2 = hw_NextBotMark2p + MarkMargin +2;
	NextTopLine3 = hw_NextTopMark3p - MarkMargin;
	NextBotLine3 = hw_NextBotMark3p + MarkMargin +2;

	NextTopLine = (hw_NextTopMark==0x7ef)? 0x800:NextTopLine;
	NextBotLine = (hw_NextBotMark==0x7ef)? 0x800:NextBotLine;
	NextTopLine2 = (hw_NextTopMark2==0x7ef)? 0x800:NextTopLine2;
	NextBotLine2 = (hw_NextBotMark2==0x7ef)? 0x800:NextBotLine2;
	NextTopLine3 = (hw_NextTopMark3==0x7ef)? 0x800:NextTopLine3;
	NextBotLine3 = (hw_NextBotMark3==0x7ef)? 0x800:NextBotLine3;

	// get the non-film region
	// weave next field
	if(( (!hw_AdoptHDMethod && !hw_RTNR_Interlace_Force2D_En) && StatusFilmWeaveMode==1) || ( fw_DI_3A && Weave_Mode_d==0))
	{
		if(NextTopDetected_d && !NextTopDetected)
		{
			NextTopLine = TopLine;
			NextBotLine = BotLine;
			NextTopLine2 = TopLine2;
			NextBotLine2 = BotLine2;
			NextTopLine3 = TopLine3;
			NextBotLine3 = BotLine3;
		}
		TopLine = NextTopLine;
		BotLine = NextBotLine;
		TopLine2 = NextTopLine2;
		BotLine2 = NextBotLine2;
		TopLine3 = NextTopLine3;
		BotLine3 = NextBotLine3;
		NextTopDetected_d = NextTopDetected;
	}
	else// weave pre field
	{
		if(PrevTopDetected_d && !PrevTopDetected)
		{
			PrevTopLine = TopLine;
			PrevBotLine = BotLine;
			PrevTopLine2 = TopLine2;
			PrevBotLine2 = BotLine2;
			PrevTopLine3 = TopLine3;
			PrevBotLine3 = BotLine3;
		}
		TopLine = PrevTopLine;
		BotLine = PrevBotLine;
		TopLine2 = PrevTopLine2;
		BotLine2 = PrevBotLine2;
		TopLine3 = PrevTopLine3;
		BotLine3 = PrevBotLine3;
		PrevTopDetected_d = PrevTopDetected;
	}
	// write back
	fw_Status32Detected1 =	Status32Detected1;
	fw_Status32Detected2 =	Status32Detected2;
	fw_Status22Detected  =	(scalerVIP_DI_MiddleWare_GetStatus(STATUS_VPAN) != 0)? 0 : Status22Detected;
	fw_StatusMixedFilmDetected = ((scalerVIP_DI_MiddleWare_GetStatus(STATUS_VPAN) != 0) &&
						((Status32Detected1==0) && (Status32Detected2==0)))? 0:StatusMixedFilmDetected;
	fw_StatusFilmDetected = ((scalerVIP_DI_MiddleWare_GetStatus(STATUS_VPAN) != 0) &&
						((Status32Detected1==0) && (Status32Detected2==0)))? 0:(StatusFilmDetected || force_weave_flag);
	/*
#if LG_Demo_flag
	fw_Status32Detected1 = (scalerVIP_DI_MiddleWare_GetStatus(STATUS_VPAN) != 0)? 0 : Status32Detected1;
	fw_Status32Detected2 = (scalerVIP_DI_MiddleWare_GetStatus(STATUS_VPAN) != 0)? 0 : Status32Detected2;
	fw_Status22Detected = (scalerVIP_DI_MiddleWare_GetStatus(STATUS_VPAN) != 0)? 0 : Status22Detected;
	fw_StatusMixedFilmDetected = (scalerVIP_DI_MiddleWare_GetStatus(STATUS_VPAN) != 0)? 0 : StatusMixedFilmDetected;
	fw_StatusFilmDetected = (scalerVIP_DI_MiddleWare_GetStatus(STATUS_VPAN) != 0)? 0 : (StatusFilmDetected || force_weave_flag);
#else
	fw_Status32Detected1 =	Status32Detected1;
	fw_Status32Detected2 =	Status32Detected2;
	fw_Status22Detected  =	Status22Detected;
	fw_StatusMixedFilmDetected = StatusMixedFilmDetected;
	fw_StatusFilmDetected = (StatusFilmDetected || force_weave_flag);
#endif
	*/
	fw_MixedFilmConfuse = MixedFilmConfuse;

	fw_StatusFilmWeaveMode = StatusFilmWeaveMode;
	fw_StatusFilmSequence = hw_film_StatusFilmSequence;

	fw_TopLine = TopLine>>1;
	fw_BotLine =BotLine>>1;
	fw_TopLine2 =TopLine2>>1;
	fw_BotLine2 = BotLine2>>1;
	fw_TopLine3 =TopLine3>>1;
	fw_BotLine3 = BotLine3>>1;

	//scalerVIP_film_FWmode_3D_end();

	static FILM_FWMode DetInformation;
	DetInformation.Fw_StatusFilmDetected = fw_StatusFilmDetected;
	DetInformation.Fw_StatusMixedFilmDetected = fw_StatusMixedFilmDetected;
	DetInformation.fw_StatusFilmSequence = fw_StatusFilmSequence;
	DetInformation.Fw_StatusFilmWeaveMode = fw_StatusFilmWeaveMode;
	DetInformation.Fw_MixedFilmConfuse = fw_MixedFilmConfuse;
	DetInformation.fw_Status32Detected1 = fw_Status32Detected1;
	DetInformation.fw_Status32Detected2 = fw_Status32Detected2;
	DetInformation.fw_Status22Detected = fw_Status22Detected;
	DetInformation.Fw_TopLine1= fw_TopLine;
	DetInformation.Fw_BotLine1 = fw_BotLine;
	DetInformation.Fw_TopLine2= fw_TopLine2;
	DetInformation.Fw_BotLine2 = fw_BotLine2;
	DetInformation.Fw_TopLine3= fw_TopLine3;
	DetInformation.Fw_BotLine3 = fw_BotLine3;

	return DetInformation;
}



void APPLY_scalerVIP_film_FWmode_isr(FILM_FWMode DetInformation)
{
	di_im_di_film_new_function_main_RBUS im_di_film_new_function_main_reg;
	di_im_di_film_topbotline1_RBUS im_di_film_topbotline1_reg;
	di_im_di_film_topbotline2_RBUS im_di_film_topbotline2_reg;
	di_im_di_film_topbotline3_RBUS im_di_film_topbotline3_reg;

	im_di_film_new_function_main_reg.regValue = rtd_inl(DI_IM_DI_FILM_NEW_FUNCTION_MAIN_reg);
	im_di_film_topbotline1_reg.regValue = rtd_inl(DI_IM_DI_FILM_TopBotLine1_reg);
	im_di_film_topbotline2_reg.regValue = rtd_inl(DI_IM_DI_FILM_TopBotLine2_reg);
	im_di_film_topbotline3_reg.regValue = rtd_inl(DI_IM_DI_FILM_TopBotLine3_reg);

	im_di_film_new_function_main_reg.fw_film_mixedfilmdetected = DetInformation.Fw_StatusMixedFilmDetected;
	im_di_film_new_function_main_reg.fw_film_filmweavemode = DetInformation.Fw_StatusFilmWeaveMode;
	im_di_film_new_function_main_reg.fw_film_filmsequence = DetInformation.fw_StatusFilmSequence;
	im_di_film_new_function_main_reg.fw_film_filmdetected = DetInformation.Fw_StatusFilmDetected;
	im_di_film_new_function_main_reg.fw_film_32detected1 = DetInformation.fw_Status32Detected1;
	im_di_film_new_function_main_reg.fw_film_32detected2 = DetInformation.fw_Status32Detected2;
	im_di_film_new_function_main_reg.fw_film_22detected = DetInformation.fw_Status22Detected;
	im_di_film_new_function_main_reg.fw_film_mixedfilmconfuse = DetInformation.Fw_MixedFilmConfuse;

	/*	for Sirius ECO v.3 need to update rbus
	if(SmartPic_clue->film_bad_edit_det && timing = 1080i)	// turn bad edit off
		im_di_film_new_function_main_reg.film_bad_edit_en = 0;
	else									// turn bad edit on
		im_di_film_new_function_main_reg.film_bad_edit_en = 1;
	*/
	di_im_di_control_RBUS im_di_control_reg;
	im_di_control_reg.regValue = rtd_inl(DI_IM_DI_CONTROL_reg);
	if((im_di_control_reg.film_enable & 0x10)>>4) {
		//if(((film_index == 0) || (film_index == FILM22) || (film_index == FILM32))) {
		//	im_di_film_new_function_main_reg.fw_film_en = 0;
		//
		//} else {
			im_di_film_new_function_main_reg.fw_film_en = 1;
		//}
	}

	rtd_outl(DI_IM_DI_FILM_NEW_FUNCTION_MAIN_reg, im_di_film_new_function_main_reg.regValue);

	im_di_film_topbotline1_reg.fw_topline1 = MIN(1080,DetInformation.Fw_TopLine1);
	im_di_film_topbotline1_reg.fw_botline1 = MIN(1080,DetInformation.Fw_BotLine1);
	rtd_outl(DI_IM_DI_FILM_TopBotLine1_reg, im_di_film_topbotline1_reg.regValue);

	im_di_film_topbotline2_reg.fw_topline2 = MIN(1080,DetInformation.Fw_TopLine2);
	im_di_film_topbotline2_reg.fw_botline2 = MIN(1080,DetInformation.Fw_BotLine2);
	rtd_outl(DI_IM_DI_FILM_TopBotLine2_reg, im_di_film_topbotline2_reg.regValue);

	im_di_film_topbotline3_reg.fw_topline3 = MIN(1080,DetInformation.Fw_TopLine3);
	im_di_film_topbotline3_reg.fw_botline3 = MIN(1080,DetInformation.Fw_BotLine3);
	rtd_outl(DI_IM_DI_FILM_TopBotLine3_reg, im_di_film_topbotline3_reg.regValue);

	#if 0
	unsigned char fw_film_en;
	unsigned char hw_film_StatusFilmDetected,hw_film_StatusMixedFilmDetected;
	di_im_di_si_film_final_result_RBUS im_di_si_film_final_result_reg;
	im_di_si_film_final_result_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_FINAL_RESULT_reg);
	hw_film_StatusFilmDetected = im_di_si_film_final_result_reg.film_detected;
	hw_film_StatusMixedFilmDetected = im_di_si_film_final_result_reg.film_subdetected;

	di_im_di_debug_mode_RBUS reg18024008_Reg;
	reg18024008_Reg.regValue = rtd_inl(DI_IM_DI_DEBUG_MODE_reg);
	d_yuv2rgb_control_RBUS reg1802a700_Reg;
	reg1802a700_Reg.regValue = rtd_inl(YUV2RGB_D_YUV2RGB_CONTROL_reg);
	fw_film_en = im_di_film_new_function_main_reg.fw_film_en;
	if(fw_film_en)
	{
		if(reg18024008_Reg.film_debugmode && (DetInformation.Fw_StatusFilmDetected || DetInformation.Fw_StatusMixedFilmDetected))
			reg1802a700_Reg.yuv2rgb_main_en = 0x0;
		else
			reg1802a700_Reg.yuv2rgb_main_en = 0x1;
	}
	else
	{
		if(reg18024008_Reg.film_debugmode && (hw_film_StatusFilmDetected || hw_film_StatusMixedFilmDetected))
			reg1802a700_Reg.yuv2rgb_main_en = 0x0;
		else
			reg1802a700_Reg.yuv2rgb_main_en = 0x1;
	}
	rtd_outl(YUV2RGB_D_YUV2RGB_CONTROL_reg, reg1802a700_Reg.regValue);
	//Count++;
	//if(Count>=600 && Count%60==0 && reg18024008_Reg.film_debugmode)
	//{}
	#endif
}


void	scalerVIP_film_FWmode_detection1_isr(unsigned int FrameStaticPattern,unsigned int FramePairPattern,
		unsigned int PrevStaticPattern, unsigned int NextStaticPattern, unsigned char Strict,
		unsigned char *ExactMatch, unsigned char *Violate, unsigned int *film_index,unsigned int *count_still,
		unsigned char *p32Detected1, unsigned int *p32Sequence1,unsigned char film_Pair_en_auto,
		unsigned char film_Pair1_en,unsigned char film_HiFreq_flag,unsigned char film_Violate_strict_en)
{
	unsigned char LeaveQuick_en=0,reg_vc_di_film_violate_stillpix_en=0;
	unsigned char Pair_en;//,film_Pair_en_auto,film_Pair1_en,film_Violate_strict_en,film_HiFreq_flag;

	if(film_Pair_en_auto)
	{
		if(*p32Detected1 && film_HiFreq_flag)
			Pair_en = 0;
		else
			Pair_en = 1;
	}
	else
		Pair_en = film_Pair1_en;

	*ExactMatch = 0;
	*Violate = 0;

	if(reg_vc_di_film_violate_stillpix_en && (FrameStaticPattern&1)==0 && *p32Detected1)
	{
		if(*count_still%2==1)
		{
			*Violate=1;
			*count_still=0;
			*film_index=0;
			*p32Sequence1=0;
			*p32Detected1=0;
		}
		else
		{
			*count_still=0;
		}
	}


	if(*p32Detected1 && film_Violate_strict_en)
	{
		if(*film_index==FILM32)
		{
				*p32Sequence1 = (*p32Sequence1==16) ? 1 : (*p32Sequence1<<1);
				if(LeaveQuick_en)
				{
					if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x35)==0x34	)) ||
						(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
						(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x2b)==0x2a	)) ||
						(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x2d)==0x2c	)) ||
						(*p32Sequence1==(unsigned int)(16>>(fw_DI_3A*4)) && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x29)==0x28	))
					)
						{
							*Violate = 1;
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*film_index = 0;
						}
				}
				else
				{
					if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0)									)) ||
						(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
						(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0)									)) ||
						(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0)									)) ||
						(*p32Sequence1==(unsigned int)(16>>(fw_DI_3A*4)) && ((!Pair_en || (FramePairPattern&2)!=0)									))
					)
						{
							*Violate = 1;
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*film_index = 0;
						}
				}
		}
		if(*film_index==FILM3223)
		{
				*p32Sequence1 = (*p32Sequence1==512) ? 1 : (*p32Sequence1<<1);
				if(LeaveQuick_en)
				{
					if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x2b)==0x2a	)) ||
						(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x2d)==0x2c	)) ||
						(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
						(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x1b)==0x1a	)) ||
						(*p32Sequence1==(unsigned int)(16<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x2d)==0x2c	)) ||
						(*p32Sequence1==(unsigned int)(32<<fw_DI_3A)	  && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x2d)==0x2c	)) ||
						(*p32Sequence1==(unsigned int)(64<<fw_DI_3A)	  && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x35)==0x34	)) ||
						(*p32Sequence1==(unsigned int)(128<<fw_DI_3A)	   && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x35)==0x34	)) ||
						(*p32Sequence1==(unsigned int)(256<<fw_DI_3A)	   && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x15)==0x14	)) ||
						(*p32Sequence1==(unsigned int)(512>>(fw_DI_3A*9)) && ((!Pair_en || (FramePairPattern&3)!=0) ||	(FrameStaticPattern&0x1)!=1	))
					)
						{
							*Violate = 1;
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*film_index = 0;
						}
				}
				else
				{
					if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0)									)) ||
						(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0)									)) ||
						(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
						(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0)									)) ||
						(*p32Sequence1==(unsigned int)(16<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0)									)) ||
						(*p32Sequence1==(unsigned int)(32<<fw_DI_3A)	  && ((!Pair_en || (FramePairPattern&2)!=0)									)) ||
						(*p32Sequence1==(unsigned int)(64<<fw_DI_3A)	  && ((!Pair_en || (FramePairPattern&1)!=0)									)) ||
						(*p32Sequence1==(unsigned int)(128<<fw_DI_3A)	   && ((!Pair_en || (FramePairPattern&2)!=0)								)) ||
						(*p32Sequence1==(unsigned int)(256<<fw_DI_3A)	   && ((!Pair_en || (FramePairPattern&1)!=0)								)) ||
						(*p32Sequence1==(unsigned int)(512>>(fw_DI_3A*9)) && ((!Pair_en || (FramePairPattern&3)!=0) ||	(FrameStaticPattern&0x1)!=1	))
					)
						{
							*Violate = 1;
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*film_index = 0;
						}
				}
		}
		if(*film_index==FILM64)
		{
				*p32Sequence1 = (*p32Sequence1==512) ? 1 : (*p32Sequence1<<1);
				if(LeaveQuick_en)
				{
					if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x37)==0x36	)) ||
						(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x1d)==0x1c	)) ||
						(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
						(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
						(*p32Sequence1==(unsigned int)(16<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
						(*p32Sequence1==(unsigned int)(32<<fw_DI_3A)	  && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
						(*p32Sequence1==(unsigned int)(64<<fw_DI_3A)	  && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x1f)==0x1e	)) ||
						(*p32Sequence1==(unsigned int)(128<<fw_DI_3A)	   && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x3d)==0x3c	)) ||
						(*p32Sequence1==(unsigned int)(256<<fw_DI_3A)	   && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
						(*p32Sequence1==(unsigned int)(512>>(fw_DI_3A*9)) && ((!Pair_en || (FramePairPattern&3)!=0) ||	(FrameStaticPattern&0x1)!=1	))
					)
						{
							*Violate = 1;
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*film_index = 0;
						}
				}
				else
				{
					if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0)									)) ||
						(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0)									)) ||
						(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
						(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
						(*p32Sequence1==(unsigned int)(16<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
						(*p32Sequence1==(unsigned int)(32<<fw_DI_3A)	  && ((!Pair_en || (FramePairPattern&3)!=0)	|| (FrameStaticPattern&0x1)!=1		)) ||
						(*p32Sequence1==(unsigned int)(64<<fw_DI_3A)	  && ((!Pair_en || (FramePairPattern&2)!=0)									)) ||
						(*p32Sequence1==(unsigned int)(128<<fw_DI_3A)	   && ((!Pair_en || (FramePairPattern&1)!=0)								)) ||
						(*p32Sequence1==(unsigned int)(256<<fw_DI_3A)	   && ((!Pair_en || (FramePairPattern&3)!=0)  || (FrameStaticPattern&0x1)!=1		)) ||
						(*p32Sequence1==(unsigned int)(512>>(fw_DI_3A*9)) && ((!Pair_en || (FramePairPattern&3)!=0) ||	(FrameStaticPattern&0x1)!=1	))
					)
						{
							*Violate = 1;
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*film_index = 0;
						}
				}
		}
		if(*film_index==FILM55)
		{
				*p32Sequence1 = (*p32Sequence1==16) ? 1 : (*p32Sequence1<<1);
				if(LeaveQuick_en)
				{
					if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x2f)==0x2e	)) ||
						(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x3d)==0x3c	)) ||
						(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1	  )) ||
						(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1	    )) ||
						(*p32Sequence1==(unsigned int)(16>>(fw_DI_3A*4)) && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1	    ))
					)
						{
							*Violate = 1;
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*film_index = 0;
						}
				}
				else
				{
					if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0)									)) ||
						(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0)									)) ||
						(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
						(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
						(*p32Sequence1==(unsigned int)(16>>(fw_DI_3A*4)) && ((!Pair_en || (FramePairPattern&3)!=0)	 || (FrameStaticPattern&0x1)!=1 	))
					)
						{
							*Violate = 1;
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*film_index = 0;
						}
				}
		}
		if(*film_index==FILM2224)
		{
				*p32Sequence1 = (*p32Sequence1==512) ? 1 : (*p32Sequence1<<1);
				if(LeaveQuick_en)
				{
					if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x17)==0x16		)) ||
						(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x1d)==0x1c	)) ||
						(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x1d)==0x1c	)) ||
						(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x35)==0x34	)) ||
						(*p32Sequence1==(unsigned int)(16<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x35)==0x34	)) ||
						(*p32Sequence1==(unsigned int)(32<<fw_DI_3A)	  && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x15)==0x14	)) ||
						(*p32Sequence1==(unsigned int)(64<<fw_DI_3A)	  && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x15)==0x14	)) ||
						(*p32Sequence1==(unsigned int)(128<<fw_DI_3A)	   && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x15)==0x14	)) ||
						(*p32Sequence1==(unsigned int)(256<<fw_DI_3A)	   && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
						(*p32Sequence1==(unsigned int)(512>>(fw_DI_3A*9)) && ((!Pair_en || (FramePairPattern&3)!=0) ||	(FrameStaticPattern&0x1)!=1	))
					)
						{
							*Violate = 1;
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*film_index = 0;
						}
				}
				else
				{
					if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0)									)) ||
						(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0)									)) ||
						(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0)								)) ||
						(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0)									)) ||
						(*p32Sequence1==(unsigned int)(16<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0)									)) ||
						(*p32Sequence1==(unsigned int)(32<<fw_DI_3A)	  && ((!Pair_en || (FramePairPattern&1)!=0)									)) ||
						(*p32Sequence1==(unsigned int)(64<<fw_DI_3A)	  && ((!Pair_en || (FramePairPattern&2)!=0)									)) ||
						(*p32Sequence1==(unsigned int)(128<<fw_DI_3A)	   && ((!Pair_en || (FramePairPattern&1)!=0)								)) ||
						(*p32Sequence1==(unsigned int)(256<<fw_DI_3A)	   && ((!Pair_en || (FramePairPattern&3)!=0)  || (FrameStaticPattern&0x1)!=1		)) ||
						(*p32Sequence1==(unsigned int)(512>>(fw_DI_3A*9)) && ((!Pair_en || (FramePairPattern&3)!=0) ||	(FrameStaticPattern&0x1)!=1	  ))
					)
						{
							*Violate = 1;
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*film_index = 0;
						}
				}
		}
		if(*film_index==FILM32322)
		{
				*p32Sequence1 = (*p32Sequence1==2048) ? 1 : (*p32Sequence1<<1);
				if(LeaveQuick_en)
				{
					if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x35)==0x34		)) ||
						(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x15)==0x14			)) ||
						(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1			)) ||
						(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x2b)==0x2a		)) ||
						(*p32Sequence1==(unsigned int)(16<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x2d)==0x2c		)) ||
						(*p32Sequence1==(unsigned int)(32<<fw_DI_3A)	  && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x2d)==0x2c		)) ||
						(*p32Sequence1==(unsigned int)(64<<fw_DI_3A)	  && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x35)==0x34		)) ||
						(*p32Sequence1==(unsigned int)(128<<fw_DI_3A)	   && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1			)) ||
						(*p32Sequence1==(unsigned int)(256<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x2b)==0x2a		)) ||
						(*p32Sequence1==(unsigned int)(512<<fw_DI_3A)	&& ((!Pair_en || (FramePairPattern&1)!=0) ||  (NextStaticPattern&0x2d)==0x2c			)) ||
						(*p32Sequence1==(unsigned int)(1024<<fw_DI_3A)	    && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x2d)==0x2c 		)) ||
						(*p32Sequence1==(unsigned int)(2048>>(fw_DI_3A*11)) && ((!Pair_en || (FramePairPattern&1)!=0) ||  (NextStaticPattern&0x35)==0x34	))
					)
						{
							*Violate = 1;
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*film_index = 0;
						}
				}
				else
				{
					if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0)									)) ||
						(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0)									)) ||
						(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
						(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0)									)) ||
						(*p32Sequence1==(unsigned int)(16<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0)									)) ||
						(*p32Sequence1==(unsigned int)(32<<fw_DI_3A)	  && ((!Pair_en || (FramePairPattern&2)!=0)									)) ||
						(*p32Sequence1==(unsigned int)(64<<fw_DI_3A)	  && ((!Pair_en || (FramePairPattern&1)!=0)									)) ||
						(*p32Sequence1==(unsigned int)(128<<fw_DI_3A)	   && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
						(*p32Sequence1==(unsigned int)(256<<fw_DI_3A)	   && ((!Pair_en || (FramePairPattern&2)!=0)								)) ||
						(*p32Sequence1==(unsigned int)(512<<fw_DI_3A)	&& ((!Pair_en || (FramePairPattern&1)!=0)								)) ||
						(*p32Sequence1==(unsigned int)(1024<<fw_DI_3A)	    && ((!Pair_en || (FramePairPattern&2)!=0)								)) ||
						(*p32Sequence1==(unsigned int)(2048>>(fw_DI_3A*11)) && ((!Pair_en || (FramePairPattern&1)!=0)								))
					)
						{
							*Violate = 1;
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*film_index = 0;
						}
				}
		}
		if(*film_index==FILM87)
		{
				*p32Sequence1 = (*p32Sequence1==16384) ? 1 : (*p32Sequence1<<1);
				if(LeaveQuick_en)
				{
					if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x3f)==0x3e	)) ||
						(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x3d)==0x3c	)) ||
						(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
						(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
						(*p32Sequence1==(unsigned int)(16<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
						(*p32Sequence1==(unsigned int)(32<<fw_DI_3A)	  && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
						(*p32Sequence1==(unsigned int)(64<<fw_DI_3A)	  && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
						(*p32Sequence1==(unsigned int)(128<<fw_DI_3A)	   && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
						(*p32Sequence1==(unsigned int)(256<<fw_DI_3A)	   && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x3f)==0x3e	)) ||
						(*p32Sequence1==(unsigned int)(512<<fw_DI_3A)	&& ((!Pair_en || (FramePairPattern&1)!=0) ||  (NextStaticPattern&0x3d)==0x3c	))||
						(*p32Sequence1==(unsigned int)(1024<<fw_DI_3A)	    && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1	)) ||
						(*p32Sequence1==(unsigned int)(2048<<fw_DI_3A)	    && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1	)) ||
						(*p32Sequence1==(unsigned int)(4096<<fw_DI_3A)	    && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1	)) ||
						(*p32Sequence1==(unsigned int)(8192<<fw_DI_3A)	    && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1	)) ||
						(*p32Sequence1==(unsigned int)(16384>>(fw_DI_3A*14)) && ((!Pair_en || (FramePairPattern&3)!=0) ||  (FrameStaticPattern&0x1)!=1	))
					)
						{
							*Violate = 1;
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*film_index = 0;
						}
				}
				else
				{
					if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0)									)) ||
						(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0)									)) ||
						(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
						(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
						(*p32Sequence1==(unsigned int)(16<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
						(*p32Sequence1==(unsigned int)(32<<fw_DI_3A)	  && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
						(*p32Sequence1==(unsigned int)(64<<fw_DI_3A)	  && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
						(*p32Sequence1==(unsigned int)(128<<fw_DI_3A)	   && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
						(*p32Sequence1==(unsigned int)(256<<fw_DI_3A)	   && ((!Pair_en || (FramePairPattern&2)!=0)								)) ||
						(*p32Sequence1==(unsigned int)(512<<fw_DI_3A)	&& ((!Pair_en || (FramePairPattern&1)!=0)								)) ||
						(*p32Sequence1==(unsigned int)(1024<<fw_DI_3A)	    && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1	)) ||
						(*p32Sequence1==(unsigned int)(2048<<fw_DI_3A)	    && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1	)) ||
						(*p32Sequence1==(unsigned int)(4096<<fw_DI_3A)	    && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1	)) ||
						(*p32Sequence1==(unsigned int)(8192<<fw_DI_3A)	    && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1	)) ||
						(*p32Sequence1==(unsigned int)(16384>>(fw_DI_3A*14)) && ((!Pair_en || (FramePairPattern&3)!=0) ||  (FrameStaticPattern&0x1)!=1	))
					)
						{
							*Violate = 1;
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*film_index = 0;
						}
				}
		}
	}

	if(*p32Detected1) // check FrameStaticPattern and decide pSeq
	{
		if(*film_index==FILM32)
		{
			switch(FrameStaticPattern&0xfffff)
			{
				case 0x84210:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6619866 && (!LeaveQuick_en || (NextStaticPattern&0x31)!=0x30) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x31)!=0x30) )
					)
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 2 : 1;
						*ExactMatch = 1;
						*film_index=FILM32;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x8421:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x19866198) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					)
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 4 : 2;
						*ExactMatch = 1;
						*film_index=FILM32;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x10842:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x26198661 && (!LeaveQuick_en || (PrevStaticPattern&0x2b)!=0x2a) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && ((!LeaveQuick_en || PrevStaticPattern&0x2b)!=0x2a) )
					)

					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 8 : 4;
						*ExactMatch = 1;
						*film_index=FILM32;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x21084:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18661986 && (!LeaveQuick_en || (NextStaticPattern&0x2d)!=0x2c) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x2d)!=0x2c) )
					)
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 16 : 8;
						*ExactMatch = 1;
						*film_index=FILM32;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x42108:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x21986619 && (!LeaveQuick_en || (PrevStaticPattern&0x29)!=0x28) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x29)!=0x28) )
					 )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 1 : 16;
						*ExactMatch = 1;
						*film_index=FILM32;
					}
					else
					{
						*p32Detected1=0;
						*p32Sequence1=0;
						*film_index=0;
					}
					break;

				case 0xfffff:
					if(Strict)
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
						break;
					}

				default:
					{
						if(framestaticonly){
							if( (FrameStaticPattern&0x1)!=1 &&
								(*p32Sequence1==(unsigned int)(2<<fw_DI_3A))
							  )
							{
								*p32Detected1 = 0;
								*p32Sequence1 = 0;
								*Violate = 1;
								*count_still=0;
								*film_index=0;
							}
						}else
						if((FrameStaticPattern&1) || (FramePairPattern&3)==0)
						{
							if(!film_Violate_strict_en)
							{
								*p32Sequence1 = (*p32Sequence1==16) ? 1 : (*p32Sequence1<<1);
								if(LeaveQuick_en)
								{
									if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x35)==0x34	)) ||
										(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
										(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x2b)==0x2a	)) ||
										(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x2d)==0x2c	)) ||
										(*p32Sequence1==(unsigned int)(16>>(fw_DI_3A*4)) && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x29)==0x28	))
									  )
									 {
										*p32Detected1 = 0;
										*p32Sequence1 = 0;
										*Violate = 1;
										*count_still=0;
										*film_index=0;
									}
								}
								else
								{
									if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0)									)) ||
										(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
										(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0)									)) ||
										(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0)									)) ||
										(*p32Sequence1==(unsigned int)(16>>(fw_DI_3A*4)) && ((!Pair_en || (FramePairPattern&2)!=0)									))
									  )
									{
										*p32Detected1 = 0;
										*p32Sequence1 = 0;
										*Violate = 1;
										*count_still=0;
										*film_index=0;
									}
								}
							}
							if(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)) *count_still=0;
							else *count_still=*count_still+1;
						}
						else
						{
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*Violate = 1;
							*count_still=0;
							*film_index=0;
						}
						break;
					}
			}
		}
		else if(*film_index==FILM3223)
		{
			switch(FrameStaticPattern&0xfffff)
			{
				case 0x40902:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x26186661 && (!LeaveQuick_en || (PrevStaticPattern&0x2b)==0x2a	) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x2b)==0x2a		) )
					)
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 2 : 1;
						*ExactMatch = 1;
						*film_index=FILM3223;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x81204:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18619986 && (!LeaveQuick_en || (NextStaticPattern&0x2d)!=0x2c	) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x2d)!=0x2c		) )
					)
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 4 : 2;
						*ExactMatch = 1;
						*film_index=FILM3223;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x2409:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x21866618) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 8 : 4;
						*ExactMatch = 1;
						*film_index=FILM3223;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x4812:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6199861 && (!LeaveQuick_en || (PrevStaticPattern&0x1b)==0x1a	) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x1b)==0x1a		) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 16 : 8;
						*ExactMatch = 1;
						*film_index=FILM3223;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x9024:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18666186 && (!LeaveQuick_en || (NextStaticPattern&0x2d)!=0x2c	) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x2d)!=0x2c		) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 32 : 16;
						*ExactMatch = 1;
						*film_index=FILM3223;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x12048:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x21998619 && (!LeaveQuick_en || (PrevStaticPattern&0x2d)==0x2c	) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x2d)==0x2c		) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 64 : 32;
						*ExactMatch = 1;
						*film_index=FILM3223;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x24090:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6661866 && (!LeaveQuick_en || (NextStaticPattern&0x35)!=0x34	) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x35)!=0x34		) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 128 : 64;
						*ExactMatch = 1;
						*film_index=FILM3223;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x48120:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x19986199 && (!LeaveQuick_en || (PrevStaticPattern&0x35)==0x34	) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x35)==0x34		) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 256 : 128;
						*ExactMatch = 1;
						*film_index=FILM3223;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x90240:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x26618666 && (!LeaveQuick_en || (NextStaticPattern&0x15)!=0x14	) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x15)!=0x14		) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 512 : 256;
						*ExactMatch = 1;
						*film_index=FILM3223;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x20481:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x19861998) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 1 : 512;
						*ExactMatch = 1;
						*film_index=FILM3223;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xfffff:
					if(Strict)
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
						break;
					}

				default:   // decide still pix
					if(framestaticonly){
						if( (FrameStaticPattern&0x1)!=1 &&
							(
								*p32Sequence1==(unsigned int)(4<<fw_DI_3A) ||
								*p32Sequence1==(unsigned int)(512>>(fw_DI_3A*9))
							)
						  )
						{
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*Violate = 1;
							*count_still=0;
							*film_index=0;
						}
					}else
					if((FrameStaticPattern&1) || (FramePairPattern&3)==0)
					{
						if(!film_Violate_strict_en)
						{
							*p32Sequence1 = (*p32Sequence1==512) ? 1 : (*p32Sequence1<<1);
							if(LeaveQuick_en)
							{
								if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x2b)==0x2a	)) ||
									(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x2d)==0x2c	)) ||
									(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
									(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x1b)==0x1a	)) ||
									(*p32Sequence1==(unsigned int)(16<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x2d)==0x2c	)) ||
									(*p32Sequence1==(unsigned int)(32<<fw_DI_3A)	  && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x2d)==0x2c	)) ||
									(*p32Sequence1==(unsigned int)(64<<fw_DI_3A)	  && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x35)==0x34	)) ||
									(*p32Sequence1==(unsigned int)(128<<fw_DI_3A)	   && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x35)==0x34	)) ||
									(*p32Sequence1==(unsigned int)(256<<fw_DI_3A)	   && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x15)==0x14	)) ||
									(*p32Sequence1==(unsigned int)(512>>(fw_DI_3A*9)) && ((!Pair_en || (FramePairPattern&3)!=0) ||	(FrameStaticPattern&0x1)!=1	))
								  )
								{
									*p32Detected1 = 0;
									*p32Sequence1 = 0;
									*Violate = 1;
									*count_still=0;
									*film_index=0;
								}
							}
							else
							{
								if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0)									)) ||
									(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0)									)) ||
									(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
									(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0)									)) ||
									(*p32Sequence1==(unsigned int)(16<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0)									)) ||
									(*p32Sequence1==(unsigned int)(32<<fw_DI_3A)	  && ((!Pair_en || (FramePairPattern&2)!=0)									)) ||
									(*p32Sequence1==(unsigned int)(64<<fw_DI_3A)	  && ((!Pair_en || (FramePairPattern&1)!=0)									)) ||
									(*p32Sequence1==(unsigned int)(128<<fw_DI_3A)	   && ((!Pair_en || (FramePairPattern&2)!=0)								)) ||
									(*p32Sequence1==(unsigned int)(256<<fw_DI_3A)	   && ((!Pair_en || (FramePairPattern&1)!=0)								)) ||
									(*p32Sequence1==(unsigned int)(512>>(fw_DI_3A*9)) && ((!Pair_en || (FramePairPattern&3)!=0) ||	(FrameStaticPattern&0x1)!=1	))
								  )
								{
									*p32Detected1 = 0;
									*p32Sequence1 = 0;
									*Violate = 1;
									*count_still=0;
									*film_index=0;
								}
							}
						}
						if(*p32Sequence1==(unsigned int)(4<<fw_DI_3A) ||*p32Sequence1==(unsigned int)(512>>(fw_DI_3A*9)) ) *count_still=0;
						else *count_still=*count_still+1;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*Violate = 1;
						*count_still=0;
						*film_index=0;
					}
					break;
			}
		}
		else if(*film_index==FILM64)
		{
			switch(FrameStaticPattern&0xfffff)
			{

				case 0x799e6:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18180181 && (!LeaveQuick_en || (PrevStaticPattern&0x37)!=0x36) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x37)!=0x36) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 2 : 1;
						*ExactMatch = 1;
						*film_index=FILM64;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xf33cc:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x20600606 && (!LeaveQuick_en || (NextStaticPattern&0x1d)!=0x1c	) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x1d)!=0x1c) )
					)
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 4 : 2;
						*ExactMatch = 1;
						*film_index=FILM64;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xe6799:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x1801818) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 8 : 4;
						*ExactMatch = 1;
						*film_index=FILM64;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;

					}
					break;
				case 0xccf33:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6006060) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 16 : 8;
						*ExactMatch = 1;
						*film_index=FILM64;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x99e67:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18018180) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 32 : 16;
						*ExactMatch = 1;
						*film_index=FILM64;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x33ccf:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x20060600) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 64 : 32;
						*ExactMatch = 1;
						*film_index=FILM64;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x6799e:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x181801 && (!LeaveQuick_en || (PrevStaticPattern&0x1f)==0x1e) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x1f)==0x1e) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 128 : 64;
						*ExactMatch = 1;
						*film_index=FILM64;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xcf33c:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x606006 && (!LeaveQuick_en || (NextStaticPattern&0x3d)!=0x3c) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x3d)!=0x3c) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 256 : 128;
						*ExactMatch = 1;
						*film_index=FILM64;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;

					}
					break;
				case 0x9e679:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x1818018) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 512 : 256;
						*ExactMatch = 1;
						*film_index=FILM64;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x3ccf3:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6060060) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 1 : 512;
						*ExactMatch = 1;
						*film_index=FILM64;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xfffff:
					if(Strict)
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
						break;
					}

				default:   // decide still pix
					if(framestaticonly){
						if( (FrameStaticPattern&0x1)!=1 &&
							(
								*p32Sequence1==(unsigned int)(4<<fw_DI_3A) ||
								*p32Sequence1==(unsigned int)(8<<fw_DI_3A) ||
								*p32Sequence1==(unsigned int)(16<<fw_DI_3A) ||
								*p32Sequence1==(unsigned int)(32<<fw_DI_3A) ||
								*p32Sequence1==(unsigned int)(256<<fw_DI_3A) ||
								*p32Sequence1==(unsigned int)(512>>(fw_DI_3A*9))
							)
						  )
						{
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*Violate = 1;
							*count_still=0;
							*film_index=0;
						}
					}else
					if((FrameStaticPattern&1) || (FramePairPattern&3)==0)
					{
						if(!film_Violate_strict_en)
						{
							*p32Sequence1 = (*p32Sequence1==512) ? 1 : (*p32Sequence1<<1);
							if(LeaveQuick_en)
							{
								if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x37)==0x36	)) ||
									(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x1d)==0x1c	)) ||
									(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
									(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
									(*p32Sequence1==(unsigned int)(16<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
									(*p32Sequence1==(unsigned int)(32<<fw_DI_3A)	  && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
									(*p32Sequence1==(unsigned int)(64<<fw_DI_3A)	  && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x1f)==0x1e	)) ||
									(*p32Sequence1==(unsigned int)(128<<fw_DI_3A)	   && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x3d)==0x3c	)) ||
									(*p32Sequence1==(unsigned int)(256<<fw_DI_3A)	   && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
									(*p32Sequence1==(unsigned int)(512>>(fw_DI_3A*9)) && ((!Pair_en || (FramePairPattern&3)!=0) ||	(FrameStaticPattern&0x1)!=1	))
								)
								{
									*p32Detected1 = 0;
									*p32Sequence1 = 0;
									*Violate = 1;
									*count_still=0;
									*film_index=0;
								}
							}
							else
							{
								if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0)									)) ||
									(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0)									)) ||
									(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
									(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
									(*p32Sequence1==(unsigned int)(16<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
									(*p32Sequence1==(unsigned int)(32<<fw_DI_3A)	  && ((!Pair_en || (FramePairPattern&3)!=0)	|| (FrameStaticPattern&0x1)!=1		)) ||
									(*p32Sequence1==(unsigned int)(64<<fw_DI_3A)	  && ((!Pair_en || (FramePairPattern&2)!=0)									)) ||
									(*p32Sequence1==(unsigned int)(128<<fw_DI_3A)	   && ((!Pair_en || (FramePairPattern&1)!=0)								)) ||
									(*p32Sequence1==(unsigned int)(256<<fw_DI_3A)	   && ((!Pair_en || (FramePairPattern&3)!=0)  || (FrameStaticPattern&0x1)!=1		)) ||
									(*p32Sequence1==(unsigned int)(512>>(fw_DI_3A*9)) && ((!Pair_en || (FramePairPattern&3)!=0) ||	(FrameStaticPattern&0x1)!=1	))
								)
								{
										*p32Detected1 = 0;
										*p32Sequence1 = 0;
										*Violate = 1;
										*count_still=0;
										*film_index=0;
								}
							}
						}
						if(*p32Sequence1==(unsigned int)(4<<fw_DI_3A) ||*p32Sequence1==(unsigned int)(8<<fw_DI_3A)
						|| *p32Sequence1==(unsigned int)(16<<fw_DI_3A) ||*p32Sequence1==(unsigned int)(32<<fw_DI_3A)
						||*p32Sequence1==(unsigned int)(256<<fw_DI_3A) ||*p32Sequence1==(unsigned int)(512>>(fw_DI_3A*9)))
							*count_still=0;
						else
							*count_still=*count_still+1;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*Violate = 1;
						*count_still=0;
						*film_index=0;
					}
					break;
			}
		}
		else if(*film_index==FILM55)
		{
			switch(FrameStaticPattern&0xfffff)
			{
				case 0x739ce:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x20180601 && (!LeaveQuick_en || (PrevStaticPattern&0x2f)==0x2e) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x2f)==0x2e) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 2 : 1;
						*ExactMatch = 1;
						*film_index=FILM55;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xe739c:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x601806 && (!LeaveQuick_en || (NextStaticPattern&0x3d)!=0x3c) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x3d)!=0x3c) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 4 : 2;
						*ExactMatch = 1;
						*film_index=FILM55;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xce739:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x1806018) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 8 : 4;
						*ExactMatch = 1;
						*film_index=FILM55;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x9ce73:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6018060) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 16 : 8;
						*ExactMatch = 1;
						*film_index=FILM55;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x39ce7:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18060180) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 1 : 16;
						*ExactMatch = 1;
						*film_index=FILM55;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xfffff:
					if(Strict)
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
						break;
					}

				default:   // decide still pix
					if(framestaticonly){
						if( (FrameStaticPattern&0x1)!=1 &&
							(
								*p32Sequence1==(unsigned int)(4<<fw_DI_3A) ||
								*p32Sequence1==(unsigned int)(8<<fw_DI_3A) ||
								*p32Sequence1==(unsigned int)(16>>(fw_DI_3A*4))
							)
						  )
						{
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*Violate = 1;
							*count_still=0;
							*film_index=0;
						}
					}else
					if((FrameStaticPattern&1) || (FramePairPattern&3)==0)
					{
						if(!film_Violate_strict_en)
						{
							*p32Sequence1 = (*p32Sequence1==16) ? 1 : (*p32Sequence1<<1);
							if(LeaveQuick_en)
							{
								if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x2f)==0x2e	)) ||
									(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x3d)==0x3c	)) ||
									(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1	  )) ||
									(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1	    )) ||
									(*p32Sequence1==(unsigned int)(16>>(fw_DI_3A*4)) && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1	    ))
								)
								{
									*p32Detected1 = 0;
									*p32Sequence1 = 0;
									*Violate = 1;
									*count_still=0;
									*film_index=0;
								}
							}
							else
							{
								if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0)									)) ||
									(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0)									)) ||
									(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
									(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
									(*p32Sequence1==(unsigned int)(16>>(fw_DI_3A*4)) && ((!Pair_en || (FramePairPattern&3)!=0)	 || (FrameStaticPattern&0x1)!=1 	))
								)
								{
									*p32Detected1 = 0;
									*p32Sequence1 = 0;
									*Violate = 1;
									*count_still=0;
									*film_index=0;
								}
							}

						}
						if(*p32Sequence1==(unsigned int)(4<<fw_DI_3A) ||*p32Sequence1==(unsigned int)(8<<fw_DI_3A) || *p32Sequence1==(unsigned int)(16>>(fw_DI_3A*4))) *count_still=0;
						else *count_still=*count_still+1;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*Violate = 1;
						*count_still=0;
						*film_index=0;
					}
				break;
			}
		}
		else if(*film_index==FILM2224)
		{
			switch(FrameStaticPattern&0xfffff)
			{
				case 0x1806:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18199981 && (!LeaveQuick_en || (PrevStaticPattern&0x17)!=0x16) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x17)!=0x16) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 2 : 1;
						*ExactMatch = 1;
						*film_index=FILM2224;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x300c:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x20666606 && (!LeaveQuick_en || (NextStaticPattern&0x1d)==0x1c) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x1d)==0x1c) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 4 : 2;
						*ExactMatch = 1;
						*film_index=FILM2224;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x6018:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x1999819 && (!LeaveQuick_en || (PrevStaticPattern&0x1d)==0x1c) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x1d)==0x1c) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 8 : 4;
						*ExactMatch = 1;
						*film_index=FILM2224;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xc030:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6666066 && (!LeaveQuick_en || (NextStaticPattern&0x35)==0x34) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x35)==0x34) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 16 : 8;
						*ExactMatch = 1;
						*film_index=FILM2224;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x18060:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x19998199 && (!LeaveQuick_en || (PrevStaticPattern&0x35)==0x34) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x35)==0x34) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 32 : 16;
						*ExactMatch = 1;
						*film_index=FILM2224;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x300c0:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x26660666 && (!LeaveQuick_en || (NextStaticPattern&0x15)!=0x14) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x15)!=0x14) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 64 : 32;
						*ExactMatch = 1;
						*film_index=FILM2224;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x60180:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x19981999 && (!LeaveQuick_en || (PrevStaticPattern&0x15)==0x14) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x15)==0x14) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 128 : 64;
						*ExactMatch = 1;
						*film_index=FILM2224;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xc0300:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x26606666 && (!LeaveQuick_en || (NextStaticPattern&0x15)!=0x14) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x15)!=0x14) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 256 : 128;
						*ExactMatch = 1;
						*film_index=FILM2224;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x80601:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x19819998) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 512 : 256;
						*ExactMatch = 1;
						*film_index=FILM2224;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xc03:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x26066660) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 1 : 512;
						*ExactMatch = 1;
						*film_index=FILM2224;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xfffff:
					if(Strict)
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
						break;
					}

				default:   // decide still pix
					if(framestaticonly){
						if( (FrameStaticPattern&0x1)!=1 &&
							(
								*p32Sequence1==(unsigned int)(256<<fw_DI_3A) ||
								*p32Sequence1==(unsigned int)(512>>(fw_DI_3A*9))
							)
						  )
						{
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*Violate = 1;
							*count_still=0;
							*film_index=0;
						}
					}else
					if((FrameStaticPattern&1) || (FramePairPattern&3)==0)
					{
						if(!film_Violate_strict_en)
						{
							*p32Sequence1 = (*p32Sequence1==512) ? 1 : (*p32Sequence1<<1);
							if(LeaveQuick_en)
							{
								if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x17)==0x16		)) ||
									(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x1d)==0x1c	)) ||
									(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x1d)==0x1c	)) ||
									(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x35)==0x34	)) ||
									(*p32Sequence1==(unsigned int)(16<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x35)==0x34	)) ||
									(*p32Sequence1==(unsigned int)(32<<fw_DI_3A)	  && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x15)==0x14	)) ||
									(*p32Sequence1==(unsigned int)(64<<fw_DI_3A)	  && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x15)==0x14	)) ||
									(*p32Sequence1==(unsigned int)(128<<fw_DI_3A)	   && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x15)==0x14	)) ||
									(*p32Sequence1==(unsigned int)(256<<fw_DI_3A)	   && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
									(*p32Sequence1==(unsigned int)(512>>(fw_DI_3A*9)) && ((!Pair_en || (FramePairPattern&3)!=0) ||	(FrameStaticPattern&0x1)!=1	))
								)
								{
									*p32Detected1 = 0;
									*p32Sequence1 = 0;
									*Violate = 1;
									*count_still=0;
									*film_index=0;
								}
							}
							else
							{
								if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0)									)) ||
									(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0)									)) ||
									(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0)								)) ||
									(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0)									)) ||
									(*p32Sequence1==(unsigned int)(16<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0)									)) ||
									(*p32Sequence1==(unsigned int)(32<<fw_DI_3A)	  && ((!Pair_en || (FramePairPattern&1)!=0)									)) ||
									(*p32Sequence1==(unsigned int)(64<<fw_DI_3A)	  && ((!Pair_en || (FramePairPattern&2)!=0)									)) ||
									(*p32Sequence1==(unsigned int)(128<<fw_DI_3A)	   && ((!Pair_en || (FramePairPattern&1)!=0)								)) ||
									(*p32Sequence1==(unsigned int)(256<<fw_DI_3A)	   && ((!Pair_en || (FramePairPattern&3)!=0)  || (FrameStaticPattern&0x1)!=1		)) ||
									(*p32Sequence1==(unsigned int)(512>>(fw_DI_3A*9)) && ((!Pair_en || (FramePairPattern&3)!=0) ||	(FrameStaticPattern&0x1)!=1	  ))
								)
								{
									*p32Detected1 = 0;
									*p32Sequence1 = 0;
									*Violate = 1;
									*count_still=0;
									*film_index=0;
								}
							}

						}
						if(*p32Sequence1==(unsigned int)(256<<fw_DI_3A) ||*p32Sequence1==(unsigned int)(512>>(fw_DI_3A*9))) *count_still=0;
						else *count_still=*count_still+1;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*Violate = 1;
						*count_still=0;
						*film_index=0;
					}
					break;
			}
		}
		else if(*film_index==FILM32322)
		{
			switch(FrameStaticPattern&0xfffff)
			{
				case 0x20420:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x19866199 && (!LeaveQuick_en || (PrevStaticPattern&0x35)==0x34	) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x35)==0x34		) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 2 : 1;
						*ExactMatch = 1;
						*film_index=FILM32322;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x40840:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x26198666 && (!LeaveQuick_en || (NextStaticPattern&0x15)!=0x14) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x15)!=0x14) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 4 : 2;
						*ExactMatch = 1;
						*film_index=FILM32322;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x81081:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18661998) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 8 : 4;
						*ExactMatch = 1;
						*film_index=FILM32322;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x2102:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x21986661 && (!LeaveQuick_en || (PrevStaticPattern&0x2b)==0x2a) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x2b)==0x2a) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 16 : 8;
						*ExactMatch = 1;
						*film_index=FILM32322;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x4204:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6619986 && (!LeaveQuick_en || (NextStaticPattern&0x2d)!=0x2c) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x2d)!=0x2c) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 32 : 16;
						*ExactMatch = 1;
						*film_index=FILM32322;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x8408:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x19866619 && (!LeaveQuick_en || (PrevStaticPattern&0x2d)==0x2c) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x2d)==0x2c) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 64 : 32;
						*ExactMatch = 1;
						*film_index=FILM32322;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x10810:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x26199866 && (!LeaveQuick_en || (NextStaticPattern&0x35)!=0x34) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x35)!=0x34) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 128 : 64;
						*ExactMatch = 1;
						*film_index=FILM32322;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x21021:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18666198) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 256 : 128;
						*ExactMatch = 1;
						*film_index=FILM32322;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x42042:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x21998661 && (!LeaveQuick_en || (PrevStaticPattern&0x2b)==0x2a) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x2b)==0x2a) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 512 : 256;
						*ExactMatch = 1;
						*film_index=FILM32322;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x84084:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6661986 && (!LeaveQuick_en || (NextStaticPattern&0x2d)!=0x2c) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x2d)!=0x2c) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 1024 : 512;
						*ExactMatch = 1;
						*film_index=FILM32322;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x8108:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x19986619 && (!LeaveQuick_en || (PrevStaticPattern&0x2d)==0x2c) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x2d)==0x2c) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 2048 : 1024;
						*ExactMatch = 1;
						*film_index=FILM32322;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x10210:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x26619866 && (!LeaveQuick_en || (NextStaticPattern&0x35)!=0x34) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x35)!=0x34) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 1 : 2048;
						*ExactMatch = 1;
						*film_index=FILM32322;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xfffff:
					if(Strict)
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
						break;
					}

				default:   // decide still pix
					if(framestaticonly){
						if( (FrameStaticPattern&0x1)!=1 &&
							(
								*p32Sequence1==(unsigned int)(4<<fw_DI_3A) ||
								*p32Sequence1==(unsigned int)(128<<fw_DI_3A)
							)
						  )
						{
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*Violate = 1;
							*count_still=0;
							*film_index=0;
						}
					}else
					if((FrameStaticPattern&1) || (FramePairPattern&3)==0)
					{
						if(!film_Violate_strict_en)
						{
							*p32Sequence1 = (*p32Sequence1==2048) ? 1 : (*p32Sequence1<<1);
							if(LeaveQuick_en)
							{
								if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x35)==0x34		)) ||
									(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x15)==0x14			)) ||
									(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1			)) ||
									(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x2b)==0x2a		)) ||
									(*p32Sequence1==(unsigned int)(16<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x2d)==0x2c		)) ||
									(*p32Sequence1==(unsigned int)(32<<fw_DI_3A)	  && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x2d)==0x2c		)) ||
									(*p32Sequence1==(unsigned int)(64<<fw_DI_3A)	  && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x35)==0x34		)) ||
									(*p32Sequence1==(unsigned int)(128<<fw_DI_3A)	   && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1			)) ||
									(*p32Sequence1==(unsigned int)(256<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x2b)==0x2a		)) ||
									(*p32Sequence1==(unsigned int)(512<<fw_DI_3A)	&& ((!Pair_en || (FramePairPattern&1)!=0) ||  (NextStaticPattern&0x2d)==0x2c			)) ||
									(*p32Sequence1==(unsigned int)(1024<<fw_DI_3A)	    && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x2d)==0x2c 		)) ||
									(*p32Sequence1==(unsigned int)(2048>>(fw_DI_3A*11)) && ((!Pair_en || (FramePairPattern&1)!=0) ||  (NextStaticPattern&0x35)==0x34	))
								)
								{
									*p32Detected1 = 0;
									*p32Sequence1 = 0;
									*Violate = 1;
									*count_still=0;
									*film_index=0;
								}
							}
							else
							{
								if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0)									)) ||
									(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0)									)) ||
									(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
									(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0)									)) ||
									(*p32Sequence1==(unsigned int)(16<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0)									)) ||
									(*p32Sequence1==(unsigned int)(32<<fw_DI_3A)	  && ((!Pair_en || (FramePairPattern&2)!=0)									)) ||
									(*p32Sequence1==(unsigned int)(64<<fw_DI_3A)	  && ((!Pair_en || (FramePairPattern&1)!=0)									)) ||
									(*p32Sequence1==(unsigned int)(128<<fw_DI_3A)	   && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
									(*p32Sequence1==(unsigned int)(256<<fw_DI_3A)	   && ((!Pair_en || (FramePairPattern&2)!=0)								)) ||
									(*p32Sequence1==(unsigned int)(512<<fw_DI_3A)	&& ((!Pair_en || (FramePairPattern&1)!=0)								)) ||
									(*p32Sequence1==(unsigned int)(1024<<fw_DI_3A)	    && ((!Pair_en || (FramePairPattern&2)!=0)								)) ||
									(*p32Sequence1==(unsigned int)(2048>>(fw_DI_3A*11)) && ((!Pair_en || (FramePairPattern&1)!=0)								))
								)
								{
									*p32Detected1 = 0;
									*p32Sequence1 = 0;
									*Violate = 1;
									*count_still=0;
									*film_index=0;
								}
							}
						}
						if(*p32Sequence1==(unsigned int)(4<<fw_DI_3A) ||*p32Sequence1==(unsigned int)(128<<fw_DI_3A)) *count_still=0;
						else *count_still=*count_still+1;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*Violate = 1;
						*count_still=0;
						*film_index=0;
					}
				break;
			}
		}
		else if(*film_index==FILM87)
		{
			switch(FrameStaticPattern&0xfffff)
			{
				case 0xf3f3e:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x20006001 && (!LeaveQuick_en || (PrevStaticPattern&0x3f)==0x3e) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x3f)==0x3e) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 2 : 1;
						*ExactMatch = 1;
						*film_index=FILM87;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xe7e7c:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18006 && (!LeaveQuick_en || (NextStaticPattern&0x3d)==0x3c) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x3d)==0x3c) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 4 : 2;
						*ExactMatch = 1;
						*film_index=FILM87;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xcfcf9:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x60018) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 8 : 4;
						*ExactMatch = 1;
						*film_index=FILM87;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x9f9f3:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x180060) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 16 : 8;
						*ExactMatch = 1;
						*film_index=FILM87;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x3f3e7:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x600180) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 32 : 16;
						*ExactMatch = 1;
						*film_index=FILM87;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x7e7cf:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x1800600) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 64 : 32;
						*ExactMatch = 1;
						*film_index=FILM87;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xfcf9f:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6001800) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 128 : 64;
						*ExactMatch = 1;
						*film_index=FILM87;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xf9f3f:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18006000) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 256 : 128;
						*ExactMatch = 1;
						*film_index=FILM87;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xf3e7e:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x20018001 && (!LeaveQuick_en || (PrevStaticPattern&0x3f)!=0x3e) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x3f)!=0x3e) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 512 : 256;
						*ExactMatch = 1;
						*film_index=FILM87;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xe7cfc:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x60006 && (!LeaveQuick_en || (NextStaticPattern&0x3d)!=0x3c) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x3d)!=0x3c) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 1024 : 512;
						*ExactMatch = 1;
						*film_index=FILM87;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xcf9f9:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x180018) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 2048 : 1024;
						*ExactMatch = 1;
						*film_index=FILM87;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x9f3f3:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x600060) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 4096 : 2048;
						*ExactMatch = 1;
						*film_index=FILM87;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x3e7e7:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x1800180) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 8192 : 4096;
						*ExactMatch = 1;
						*film_index=FILM87;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x7cfcf:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6000600) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 16384 : 8192;
						*ExactMatch = 1;
						*film_index=FILM87;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xf9f9f:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18001800) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 1 : 16384;
						*ExactMatch = 1;
						*film_index=FILM87;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xfffff:
					if(Strict)
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
						break;
					}

				default:   // decide still pix
					if(framestaticonly){
						if( (FrameStaticPattern&0x1)!=1 &&
							(
								*p32Sequence1==(unsigned int)(4<<fw_DI_3A) ||
								*p32Sequence1==(unsigned int)(8<<fw_DI_3A) ||
								*p32Sequence1==(unsigned int)(16<<fw_DI_3A) ||
								*p32Sequence1==(unsigned int)(32<<fw_DI_3A) ||
								*p32Sequence1==(unsigned int)(64<<fw_DI_3A) ||
								*p32Sequence1==(unsigned int)(128<<fw_DI_3A) ||
								*p32Sequence1==(unsigned int)(1024<<fw_DI_3A) ||
								*p32Sequence1==(unsigned int)(2048<<fw_DI_3A) ||
								*p32Sequence1==(unsigned int)(4096<<fw_DI_3A) ||
								*p32Sequence1==(unsigned int)(8192<<fw_DI_3A) ||
								*p32Sequence1==(unsigned int)(16384>>(fw_DI_3A*14))
							)
						  )
						{
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*Violate = 1;
							*count_still=0;
							*film_index=0;
						}
					}else
					if((FrameStaticPattern&1) || (FramePairPattern&3)==0)
					{
						if(!film_Violate_strict_en)
						{
							*p32Sequence1 = (*p32Sequence1==16384) ? 1 : (*p32Sequence1<<1);
							if(LeaveQuick_en)
							{
								if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x3f)==0x3e	)) ||
									(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x3d)==0x3c	)) ||
									(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
									(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
									(*p32Sequence1==(unsigned int)(16<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
									(*p32Sequence1==(unsigned int)(32<<fw_DI_3A)	  && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
									(*p32Sequence1==(unsigned int)(64<<fw_DI_3A)	  && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
									(*p32Sequence1==(unsigned int)(128<<fw_DI_3A)	   && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
									(*p32Sequence1==(unsigned int)(256<<fw_DI_3A)	   && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x3f)==0x3e	)) ||
									(*p32Sequence1==(unsigned int)(512<<fw_DI_3A)	&& ((!Pair_en || (FramePairPattern&1)!=0) ||  (NextStaticPattern&0x3d)==0x3c	))||
									(*p32Sequence1==(unsigned int)(1024<<fw_DI_3A)	    && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1	)) ||
									(*p32Sequence1==(unsigned int)(2048<<fw_DI_3A)	    && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1	)) ||
									(*p32Sequence1==(unsigned int)(4096<<fw_DI_3A)	    && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1	)) ||
									(*p32Sequence1==(unsigned int)(8192<<fw_DI_3A)	    && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1	)) ||
									(*p32Sequence1==(unsigned int)(16384>>(fw_DI_3A*14)) && ((!Pair_en || (FramePairPattern&3)!=0) ||  (FrameStaticPattern&0x1)!=1	))
								)
								{
									*p32Detected1 = 0;
									*p32Sequence1 = 0;
									*Violate = 1;
									*count_still=0;
									*film_index=0;
								}
							}
							else
							{
								if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&2)!=0)									)) ||
									(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&1)!=0)									)) ||
									(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
									(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
									(*p32Sequence1==(unsigned int)(16<<fw_DI_3A)	 && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
									(*p32Sequence1==(unsigned int)(32<<fw_DI_3A)	  && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
									(*p32Sequence1==(unsigned int)(64<<fw_DI_3A)	  && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
									(*p32Sequence1==(unsigned int)(128<<fw_DI_3A)	   && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
									(*p32Sequence1==(unsigned int)(256<<fw_DI_3A)	   && ((!Pair_en || (FramePairPattern&2)!=0)								)) ||
									(*p32Sequence1==(unsigned int)(512<<fw_DI_3A)	&& ((!Pair_en || (FramePairPattern&1)!=0)								)) ||
									(*p32Sequence1==(unsigned int)(1024<<fw_DI_3A)	    && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1	)) ||
									(*p32Sequence1==(unsigned int)(2048<<fw_DI_3A)	    && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1	)) ||
									(*p32Sequence1==(unsigned int)(4096<<fw_DI_3A)	    && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1	)) ||
									(*p32Sequence1==(unsigned int)(8192<<fw_DI_3A)	    && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1	)) ||
									(*p32Sequence1==(unsigned int)(16384>>(fw_DI_3A*14)) && ((!Pair_en || (FramePairPattern&3)!=0) ||  (FrameStaticPattern&0x1)!=1	))
								)
								{
									*p32Detected1 = 0;
									*p32Sequence1 = 0;
									*Violate = 1;
									*count_still=0;
									*film_index=0;
								}
							}
						}
						if(*p32Sequence1==(unsigned int)(4<<fw_DI_3A) ||*p32Sequence1==(unsigned int)(8<<fw_DI_3A) ||*p32Sequence1==(unsigned int)(16<<fw_DI_3A) ||*p32Sequence1==(unsigned int)(32<<fw_DI_3A) ||
							*p32Sequence1==(unsigned int)(64<<fw_DI_3A) ||*p32Sequence1==(unsigned int)(128<<fw_DI_3A) ||*p32Sequence1==(unsigned int)(1024<<fw_DI_3A) ||
							*p32Sequence1==(unsigned int)(2048<<fw_DI_3A) ||*p32Sequence1==(unsigned int)(4096<<fw_DI_3A) ||*p32Sequence1==(unsigned int)(8192<<fw_DI_3A) ||
							*p32Sequence1==(unsigned int)(16384>>(fw_DI_3A*14))
						) {*count_still=0;}
						else *count_still=*count_still+1;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*Violate = 1;
					*count_still=0;
					*film_index=0;
				}
				break;
			}
		}
		else
		{
			*p32Detected1 = 0;
			*p32Sequence1 = 0;
			*Violate = 1;
			*count_still=0;
			*film_index=0;
		}
	}
	else	// initila detection  p32detection=0
	{
		*count_still=0;
		*p32Detected1 = 0;
		*p32Sequence1 = 0;
		*film_index=0;
		switch(FrameStaticPattern&0xfffff)
		{
// index=5 {5,5}
			case 0x739ce:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x20180601 && (!LeaveQuick_en || (PrevStaticPattern&0x2f)==0x2e) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x2f)==0x2e) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 2 : 1;
					*ExactMatch = 1;
					*film_index=FILM55;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0xe739c:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x601806 && (!LeaveQuick_en || (NextStaticPattern&0x3d)!=0x3c) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x3d)!=0x3c) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 4 : 2;
					*ExactMatch = 1;
					*film_index=FILM55;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0xce739:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x1806018) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 8 : 4;
					*ExactMatch = 1;
					*film_index=FILM55;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x9ce73:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6018060) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 16 : 8;
					*ExactMatch = 1;
					*film_index=FILM55;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x39ce7:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18060180) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 1 : 16;
					*ExactMatch = 1;
					*film_index=FILM55;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
// index=4 {6,4}
			case 0x799e6:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18180181 && (!LeaveQuick_en || (PrevStaticPattern&0x37)!=0x36) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x37)!=0x36) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 2 : 1;
					*ExactMatch = 1;
					*film_index=FILM64;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0xf33cc:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x20600606 && (!LeaveQuick_en || (NextStaticPattern&0x1d)!=0x1c	) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x1d)!=0x1c) )
				)
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 4 : 2;
					*ExactMatch = 1;
					*film_index=FILM64;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0xe6799:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x1801818) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 8 : 4;
					*ExactMatch = 1;
					*film_index=FILM64;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0xccf33:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6006060) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 16 : 8;
					*ExactMatch = 1;
					*film_index=FILM64;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x99e67:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18018180) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 32 : 16;
					*ExactMatch = 1;
					*film_index=FILM64;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x33ccf:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x20060600) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 64 : 32;
					*ExactMatch = 1;
					*film_index=FILM64;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x6799e:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x181801 && (!LeaveQuick_en || (PrevStaticPattern&0x1f)==0x1e) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x1f)==0x1e) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 128 : 64;
					*ExactMatch = 1;
					*film_index=FILM64;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0xcf33c:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x606006 && (!LeaveQuick_en || (NextStaticPattern&0x3d)!=0x3c) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x3d)!=0x3c) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 256 : 128;
					*ExactMatch = 1;
					*film_index=FILM64;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;

				}
				break;
			case 0x9e679:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x1818018) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 512 : 256;
					*ExactMatch = 1;
					*film_index=FILM64;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x3ccf3:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6060060) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 1 : 512;
					*ExactMatch = 1;
					*film_index=FILM64;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;

// index=6 {2,2,2,4}
			case 0x1806:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18199981 && (!LeaveQuick_en || (PrevStaticPattern&0x17)!=0x16) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x17)!=0x16) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 2 : 1;
					*ExactMatch = 1;
					*film_index=FILM2224;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x300c:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x20666606 && (!LeaveQuick_en || (NextStaticPattern&0x1d)==0x1c) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x1d)==0x1c) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 4 : 2;
					*ExactMatch = 1;
					*film_index=FILM2224;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x6018:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x1999819 && (!LeaveQuick_en || (PrevStaticPattern&0x1d)==0x1c) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x1d)==0x1c) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 8 : 4;
					*ExactMatch = 1;
					*film_index=FILM2224;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0xc030:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6666066 && (!LeaveQuick_en || (NextStaticPattern&0x35)==0x34) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x35)==0x34) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 16 : 8;
					*ExactMatch = 1;
					*film_index=FILM2224;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x18060:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x19998199 && (!LeaveQuick_en || (PrevStaticPattern&0x35)==0x34) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x35)==0x34) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 32 : 16;
					*ExactMatch = 1;
					*film_index=FILM2224;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x300c0:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x26660666 && (!LeaveQuick_en || (NextStaticPattern&0x15)!=0x14) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x15)!=0x14) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 64 : 32;
					*ExactMatch = 1;
					*film_index=FILM2224;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x60180:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x19981999 && (!LeaveQuick_en || (PrevStaticPattern&0x15)==0x14) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x15)==0x14) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 128 : 64;
					*ExactMatch = 1;
					*film_index=FILM2224;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0xc0300:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x26606666 && (!LeaveQuick_en || (NextStaticPattern&0x15)!=0x14) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x15)!=0x14) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 256 : 128;
					*ExactMatch = 1;
					*film_index=FILM2224;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x80601:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x19819998) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 512 : 256;
					*ExactMatch = 1;
					*film_index=FILM2224;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0xc03:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x26066660) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 1 : 512;
					*ExactMatch = 1;
					*film_index=FILM2224;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
// index=3 {3,2,2,3}
			case 0x40902:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x26186661 && (!LeaveQuick_en || (PrevStaticPattern&0x2b)==0x2a) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x2b)==0x2a) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 2 : 1;
					*ExactMatch = 1;
					*film_index=FILM3223;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x81204:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18619986 && (!LeaveQuick_en || (NextStaticPattern&0x2d)!=0x2c) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x2d)!=0x2c) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 4 : 2;
					*ExactMatch = 1;
					*film_index=FILM3223;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x2409:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x21866618) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 8 : 4;
					*ExactMatch = 1;
					*film_index=FILM3223;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x4812:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6199861 && (!LeaveQuick_en || (PrevStaticPattern&0x1b)==0x1a) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x1b)==0x1a) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 16 : 8;
					*ExactMatch = 1;
					*film_index=FILM3223;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x9024:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18666186 && (!LeaveQuick_en || (NextStaticPattern&0x2d)!=0x2c) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x2d)!=0x2c) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 32 : 16;
					*ExactMatch = 1;
					*film_index=FILM3223;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x12048:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x21998619 && (!LeaveQuick_en || (PrevStaticPattern&0x2d)==0x2c) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x2d)==0x2c) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 64 : 32;
					*ExactMatch = 1;
					*film_index=FILM3223;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x24090:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6661866 && (!LeaveQuick_en || (NextStaticPattern&0x35)!=0x34) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x35)!=0x34) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 128 : 64;
					*ExactMatch = 1;
					*film_index=FILM3223;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x48120:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x19986199 && (!LeaveQuick_en || (PrevStaticPattern&0x35)==0x34) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x35)==0x34) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 256 : 128;
					*ExactMatch = 1;
					*film_index=FILM3223;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x90240:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x26618666 && (!LeaveQuick_en || (NextStaticPattern&0x15)!=0x14) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x15)!=0x14) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 512 : 256;
					*ExactMatch = 1;
					*film_index=FILM3223;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x20481:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x19861998) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 1 : 512;
					*ExactMatch = 1;
					*film_index=FILM3223;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;

// index=7 {3,2,3,2,2}
			case 0x20420:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x19866199 && (!LeaveQuick_en || (PrevStaticPattern&0x35)==0x34	) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x35)==0x34		) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 2 : 1;
					*ExactMatch = 1;
					*film_index=FILM32322;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x40840:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x26198666 && (!LeaveQuick_en || (NextStaticPattern&0x15)!=0x14) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x15)!=0x14) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 4 : 2;
					*ExactMatch = 1;
					*film_index=FILM32322;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x81081:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18661998) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 8 : 4;
					*ExactMatch = 1;
					*film_index=FILM32322;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x2102:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x21986661 && (!LeaveQuick_en || (PrevStaticPattern&0x2b)==0x2a) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x2b)==0x2a) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 16 : 8;
					*ExactMatch = 1;
					*film_index=FILM32322;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x4204:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6619986 && (!LeaveQuick_en || (NextStaticPattern&0x2d)!=0x2c) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x2d)!=0x2c) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 32 : 16;
					*ExactMatch = 1;
					*film_index=FILM32322;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x8408:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x19866619 && (!LeaveQuick_en || (PrevStaticPattern&0x2d)==0x2c) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x2d)==0x2c) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 64 : 32;
					*ExactMatch = 1;
					*film_index=FILM32322;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x10810:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x26199866 && (!LeaveQuick_en || (NextStaticPattern&0x35)!=0x34) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x35)!=0x34) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 128 : 64;
					*ExactMatch = 1;
					*film_index=FILM32322;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x21021:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18666198) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 256 : 128;
					*ExactMatch = 1;
					*film_index=FILM32322;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x42042:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x21998661 && (!LeaveQuick_en || (PrevStaticPattern&0x2b)==0x2a) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x2b)==0x2a) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 512 : 256;
					*ExactMatch = 1;
					*film_index=FILM32322;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x84084:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6661986 && (!LeaveQuick_en || (NextStaticPattern&0x2d)!=0x2c) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x2d)!=0x2c) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 1024 : 512;
					*ExactMatch = 1;
					*film_index=FILM32322;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x8108:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x19986619 && (!LeaveQuick_en || (PrevStaticPattern&0x2d)==0x2c) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x2d)==0x2c) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 2048 : 1024;
					*ExactMatch = 1;
					*film_index=FILM32322;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x10210:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x26619866 && (!LeaveQuick_en || (NextStaticPattern&0x35)!=0x34) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x35)!=0x34) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 1 : 2048;
					*ExactMatch = 1;
					*film_index=FILM32322;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
// index=2 {3,2}
			case 0x84210:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6619866 && (!LeaveQuick_en || (NextStaticPattern&0x31)!=0x30) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x31)!=0x30) )
				)
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 2 : 1;
					*ExactMatch = 1;
					*film_index=FILM32;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x8421:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x19866198) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				)
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 4 : 2;
					*ExactMatch = 1;
					*film_index=FILM32;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x10842:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x26198661 && (!LeaveQuick_en || (PrevStaticPattern&0x2b)!=0x2a) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && ((!LeaveQuick_en || PrevStaticPattern&0x2b)!=0x2a) )
				)

				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 8 : 4;
					*ExactMatch = 1;
					*film_index=FILM32;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x21084:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18661986 && (!LeaveQuick_en || (NextStaticPattern&0x2d)!=0x2c) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x2d)!=0x2c) )
				)
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 16 : 8;
					*ExactMatch = 1;
					*film_index=FILM32;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x42108:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x21986619 && (!LeaveQuick_en || (PrevStaticPattern&0x29)!=0x28) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x29)!=0x28) )
				 )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 1 : 16;
					*ExactMatch = 1;
					*film_index=FILM32;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
// index=8 {8,7}
			case 0xf3f3e:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x20006001 && (!LeaveQuick_en || (PrevStaticPattern&0x3f)==0x3e) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x3f)==0x3e) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 2 : 1;
					*ExactMatch = 1;
					*film_index=FILM87;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0xe7e7c:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18006 && (!LeaveQuick_en || (NextStaticPattern&0x3d)==0x3c) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x3d)==0x3c) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 4 : 2;
					*ExactMatch = 1;
					*film_index=FILM87;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0xcfcf9:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x60018) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 8 : 4;
					*ExactMatch = 1;
					*film_index=FILM87;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x9f9f3:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x180060) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 16 : 8;
					*ExactMatch = 1;
					*film_index=FILM87;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x3f3e7:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x600180) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 32 : 16;
					*ExactMatch = 1;
					*film_index=FILM87;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x7e7cf:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x1800600) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 64 : 32;
					*ExactMatch = 1;
					*film_index=FILM87;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0xfcf9f:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6001800) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 128 : 64;
					*ExactMatch = 1;
					*film_index=FILM87;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0xf9f3f:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18006000) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 256 : 128;
					*ExactMatch = 1;
					*film_index=FILM87;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0xf3e7e:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x20018001 && (!LeaveQuick_en || (PrevStaticPattern&0x3f)!=0x3e) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x3f)!=0x3e) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 512 : 256;
					*ExactMatch = 1;
					*film_index=FILM87;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0xe7cfc:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x60006 && (!LeaveQuick_en || (NextStaticPattern&0x3d)!=0x3c) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x3d)!=0x3c) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 1024 : 512;
					*ExactMatch = 1;
					*film_index=FILM87;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0xcf9f9:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x180018) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 2048 : 1024;
					*ExactMatch = 1;
					*film_index=FILM87;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x9f3f3:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x600060) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 4096 : 2048;
					*ExactMatch = 1;
					*film_index=FILM87;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x3e7e7:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x1800180) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 8192 : 4096;
					*ExactMatch = 1;
					*film_index=FILM87;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x7cfcf:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6000600) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 16384 : 8192;
					*ExactMatch = 1;
					*film_index=FILM87;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0xf9f9f:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18001800) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 1 : 16384;
					*ExactMatch = 1;
					*film_index=FILM87;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			default:
				*p32Detected1 = 0;
				*p32Sequence1 = 0;
				*film_index=0;
				*ExactMatch=0;
				break;

		}
	}
	*count_still = (*count_still>=0xff2)? 0xf0:*count_still;
}

void scalerVIP_film_FWmode_detection2_isr(unsigned int NextStaticPattern, unsigned char Strict,
								unsigned int FrameStaticPattern,
								unsigned char PrevFieldMotion, unsigned char NextFieldMotion,
							    unsigned char *ExactMatch, unsigned char *Violate, unsigned int *film_index,
								unsigned char *p32Detected2, unsigned int *p32Sequence2,unsigned char film_Violate_strict_en)
{
	*ExactMatch = 0;
	*Violate = 0;

	if(*p32Detected2 && film_Violate_strict_en)
	{
		*p32Sequence2 = (*p32Sequence2==16) ? 1 : (*p32Sequence2<<1);
		if(	(*p32Sequence2==(unsigned int)(2<<fw_DI_3A) && (NextFieldMotion || PrevFieldMotion || (FrameStaticPattern&1)!=1)) ||
			((*p32Sequence2==(unsigned int)(1<<fw_DI_3A) || *p32Sequence2==(unsigned int)(8 <<fw_DI_3A  )) && NextFieldMotion) ||
			((*p32Sequence2==(unsigned int)(4<<fw_DI_3A) || *p32Sequence2==(unsigned int)(16>>fw_DI_3A*4)) && PrevFieldMotion)
		  )
		{
			*Violate = 1;
			*p32Detected2 = 0;
			*p32Sequence2 = 0;
			*film_index = 0;
		}
	}

	// check frame static pattern for film detection
	switch(NextStaticPattern&0xfffff)
	{
		case 0x5ad6b:
			if((FrameStaticPattern&0x8421)==0x8421)
			{
				*p32Detected2 = 1;
				*p32Sequence2 = (fw_DI_3A) ? 4 : 2;
				*ExactMatch = 1;
				*film_index=FILM32;
			}
			else
			{
				*p32Detected2 = 0;
				*p32Sequence2 = 0;
				*film_index=0;
			}
			break;
		case 0xb5ad6:
			if((FrameStaticPattern&0x10842)==0x10842)
			{
				*p32Detected2 = 1;
				*p32Sequence2 = (fw_DI_3A) ? 8 : 4;
				*ExactMatch = 1;
				*film_index=FILM32;
			}
			else
			{
				*p32Detected2 = 0;
				*p32Sequence2 = 0;
				*film_index=0;
			}
			break;
		case 0x6b5ad:
			if((FrameStaticPattern&0x21084)==0x21084)
			{
				*p32Detected2 = 1;
				*p32Sequence2 = (fw_DI_3A) ? 16 : 8;
				*ExactMatch = 1;
				*film_index=FILM32;
			}
			else
			{
				*p32Detected2 = 0;
				*p32Sequence2 = 0;
				*film_index=0;
			}
			break;
		case 0xd6b5a:
			if((FrameStaticPattern&0x42108)==0x42108)
			{
				*p32Detected2 = 1;
				*p32Sequence2 = (fw_DI_3A) ? 1 : 16;
				*ExactMatch = 1;
				*film_index=FILM32;
			}
			else
			{
				*p32Detected2 = 0;
				*p32Sequence2 = 0;
				*film_index=0;
			}
			break;
		case 0xad6b5:
			if((FrameStaticPattern&0x84210)==0x84210)
			{
				*p32Detected2 = 1;
				*p32Sequence2 = (fw_DI_3A) ? 2 : 1;
				*ExactMatch = 1;
				*film_index=FILM32;
			}
			else
			{
				*p32Detected2 = 0;
				*p32Sequence2 = 0;
				*film_index=0;
			}
			break;
		case 0xfffff:
			if(Strict)
			{
				*p32Detected2 = 0;
				*p32Sequence2 = 0;
				*film_index=0;
				break;
			}
		default:
			if(!*p32Detected2)
			{
				switch(NextStaticPattern&0xff)
				{
				case 0x6b://0x0b:
					*p32Sequence2 = (fw_DI_3A) ? 4 : 2;
					break;
				case 0xd6://0x16:
					*p32Sequence2 = (fw_DI_3A) ? 8 : 4;
					break;
				case 0xad://0x0d:
					*p32Sequence2 = (fw_DI_3A) ? 16 : 8;
					break;
				case 0x5a://0x1a:
					*p32Sequence2 = (fw_DI_3A) ? 1 : 16;
					break;
				case 0xb5://0x15:
					*p32Sequence2 = (fw_DI_3A) ? 2 : 1;
					break;
				default:
					*p32Sequence2 = 0;
					break;
				}

			}
			else
			{
				if(!film_Violate_strict_en)
				{
					*p32Sequence2 = (*p32Sequence2==16) ? 1 : (*p32Sequence2<<1);
					if(	(*p32Sequence2==(unsigned int)(2<<fw_DI_3A) && (NextFieldMotion || PrevFieldMotion || (FrameStaticPattern&1)!=1)) ||
						((*p32Sequence2==(unsigned int)(1<<fw_DI_3A) || *p32Sequence2==(unsigned int)(8 <<fw_DI_3A  )) && NextFieldMotion) ||
						((*p32Sequence2==(unsigned int)(4<<fw_DI_3A) || *p32Sequence2==(unsigned int)(16>>fw_DI_3A*4)) && PrevFieldMotion)
					  )
					{
						*p32Detected2 = 0;
						*p32Sequence2 = 0;
						*Violate = 1;
						*film_index=0;
					}
				}
			}
			break;
	}//end of switch
}

void	scalerVIP_film_FWmode_detection22_isr(	unsigned int NextStaticPattern, unsigned char Strict,
								unsigned char PrevFieldMotion, unsigned char NextFieldMotion,
							    unsigned char *ExactMatch, unsigned char *Violate, unsigned int *film_index, unsigned int *count_still22,
								unsigned char *p22Detected, unsigned int *p22Sequence,unsigned char film_Violate_strict_en)
{
	//unsigned char reg_vc_di_film_violate_stillpix_en=0;

	*ExactMatch = 0;
	*Violate = 0;

	/*
	if(reg_vc_di_film_violate_stillpix_en && NextFieldMotion && !PrevFieldMotion  && *p22Detected)
	{
		if(*count_still22%2==1)
		{
			*Violate=1;
			*count_still22=0;
			*film_index=0;
			*p22Sequence=0;
			*p22Detected=0;
			*ExactMatch=0;
		}
		else
		{
			*count_still22=0;
		}
	}
	*/

	if(*p22Detected && film_Violate_strict_en)
	{
		if(*film_index == FILM22)
		{
			*p22Sequence = (*p22Sequence==2) ? 1 : 2;
			if(	((*p22Sequence==(unsigned int)(1<<fw_DI_3A)) && NextFieldMotion) ||
				((*p22Sequence==(unsigned int)(2>>fw_DI_3A)) && PrevFieldMotion))
			{
				*Violate = 1;
				*p22Detected = 0;
				*p22Sequence = 0;
				*film_index=0;
			}
		}

		else if(*film_index == FILM2224)
		{
			*p22Sequence = (*p22Sequence==512) ? 1 : (*p22Sequence<<1);
			if(	((*p22Sequence==(unsigned int)(1<<fw_DI_3A) ||(*p22Sequence==(unsigned int)(4<<fw_DI_3A) )
				||(*p22Sequence==(unsigned int)(16<<fw_DI_3A) ) ||(*p22Sequence==(unsigned int)(64<<fw_DI_3A) )
				) && PrevFieldMotion) ||
				((*p22Sequence==(unsigned int)(2<<fw_DI_3A) ||(*p22Sequence==(unsigned int)(8<<fw_DI_3A) ) ||
				(*p22Sequence==(unsigned int)(32<<fw_DI_3A) ) ||(*p22Sequence==(unsigned int)(128<<fw_DI_3A) )
				) && NextFieldMotion)||
				((*p22Sequence==(unsigned int)(256<<fw_DI_3A) ||(*p22Sequence==(unsigned int)(512>>9*fw_DI_3A) )
				)&& (NextFieldMotion || PrevFieldMotion))
			)
			{
				*Violate = 1;
				*p22Detected = 0;
				*p22Sequence = 0;
				*film_index=0;
			}
		}

	}

	// check frame static pattern for film detection
	switch(NextStaticPattern&0xfffff)
	{
		// (2,2)
		case 0xaaaaa:
		{
			*film_index=FILM22;
			*p22Detected = 1;
			*p22Sequence = (fw_DI_3A) ? 1 : 2;
			*ExactMatch = 1;
			break;
		}
		case 0x55555:
		{
			*film_index=FILM22;
			*p22Detected = 1;
			*p22Sequence = (fw_DI_3A) ? 2 : 1;
			*ExactMatch = 1;
			break;
		}


		/// film 2224
		case 0xabaae: // 1010101110
		{
			*film_index=FILM2224;
			*p22Detected = 1;
			*p22Sequence = (fw_DI_3A) ? 2 : 1;
			*ExactMatch = 1;
			break;
		}
		case 0x5755d: // 0101011101
		{
			*film_index=FILM2224;
			*p22Detected = 1;
			*p22Sequence = (fw_DI_3A) ? 4 : 2;
			*ExactMatch = 1;
			break;
		}
		case 0xaeaba: // 1010111010
		{
			*film_index=FILM2224;
			*p22Detected = 1;
			*p22Sequence = (fw_DI_3A) ? 8 : 4;
			*ExactMatch = 1;
			break;
		}
		case 0x5d575: // 0101110101
		{
			*film_index=FILM2224;
			*p22Detected = 1;
			*p22Sequence = (fw_DI_3A) ? 16 : 8;
			*ExactMatch = 1;
			break;
		}
		case 0xbaaea: // 1011101010
		{
			*film_index=FILM2224;
			*p22Detected = 1;
			*p22Sequence = (fw_DI_3A) ? 32 : 16;
			*ExactMatch = 1;
			break;
		}
		case 0x755d5: // 0111010101
		{
			*film_index=FILM2224;
			*p22Detected = 1;
			*p22Sequence = (fw_DI_3A) ? 64 : 32;
			*ExactMatch = 1;
			break;
		}
		case 0xeabaa: // 1110101010
		{
			*film_index=FILM2224;
			*p22Detected = 1;
			*p22Sequence = (fw_DI_3A) ? 128 : 64;
			*ExactMatch = 1;
			break;
		}
		case 0xd5755: // 1101010101
		{
			*film_index=FILM2224;
			*p22Detected = 1;
			*p22Sequence = (fw_DI_3A) ? 256 : 128;
			*ExactMatch = 1;
			break;
		}
		case 0xaaeab: // 1010101011
		{
			*film_index=FILM2224;
			*p22Detected = 1;
			*p22Sequence = (fw_DI_3A) ? 512 : 256;
			*ExactMatch = 1;
			break;
		}
		case 0x55d57: // 0101010111
		{
			*film_index=FILM2224;
			*p22Detected = 1;
			*p22Sequence = (fw_DI_3A) ? 1 : 512;
			*ExactMatch = 1;
			break;
		}

		case 0xfffff:
			if(Strict)
			{
				*p22Detected = 0;
				*p22Sequence = 0;
				*film_index=0;
				break;
			}
		default:
		{
			if(!*p22Detected)
			{
				switch(NextStaticPattern&0x3ff)
				{
					case 0x155://0x5555://349525:
					// added for special 32 film aabbccdddd
					case 0x157://0x5d57: // 0101010111
					case 0x355://0x5755: // 1101010101
					case 0x1d5://0x55d5: // 0111010101
					case 0x175://0xd575: // 0101110101
					case 0x15d://0x755d: // 0101011101
						*p22Sequence = (fw_DI_3A) ? 2 : 1;
						break;
					case 0x2aa://0xaaaa://699050:
					// added for special 32 film aabbccdddd
					case 0x2ab://0xaeab: // 1010101011
					case 0x3aa://0xabaa: // 1110101010
					case 0x2ea://0xaaea: // 1011101010
					case 0x2ba://0xeaba: // 1010111010
					case 0x2ae://0xbaae: // 1010101110
						*p22Sequence = (fw_DI_3A) ? 1 : 2;
						break;
					default:
						*p22Sequence = 0;
						break;
				}
			}
			else
			{
				if(!film_Violate_strict_en)
				{
					if(*film_index == FILM22)
					{
						*p22Sequence = (*p22Sequence==2) ? 1 : 2;
						if(	((*p22Sequence==(unsigned int)(1<<fw_DI_3A)) && NextFieldMotion) ||
							((*p22Sequence==(unsigned int)(2>>fw_DI_3A)) && PrevFieldMotion))
						{
							*Violate = 1;
							*p22Detected = 0;
							*p22Sequence = 0;
							*film_index=0;
						}
					}
					else if(*film_index == FILM2224)
					{
						*p22Sequence = (*p22Sequence==512) ? 1 : (*p22Sequence<<1);
						if(	((*p22Sequence==(unsigned int)(1<<fw_DI_3A) ||(*p22Sequence==(unsigned int)(4<<fw_DI_3A) )
							||(*p22Sequence==(unsigned int)(16<<fw_DI_3A) ) ||(*p22Sequence==(unsigned int)(64<<fw_DI_3A) )
							) && PrevFieldMotion) ||
							((*p22Sequence==(unsigned int)(2<<fw_DI_3A) ||(*p22Sequence==(unsigned int)(8<<fw_DI_3A) ) ||
							(*p22Sequence==(unsigned int)(32<<fw_DI_3A) ) ||(*p22Sequence==(unsigned int)(128<<fw_DI_3A) )
							) && NextFieldMotion)||
							((*p22Sequence==(unsigned int)(256<<fw_DI_3A) ||(*p22Sequence==(unsigned int)(512>>9*fw_DI_3A) )
							)&& (NextFieldMotion || PrevFieldMotion))
						)
						{
							*Violate = 1;
							*p22Detected = 0;
							*p22Sequence = 0;
							*film_index=0;
						}
					}
					/*
					*p22Sequence = (*p22Sequence==2) ? 1 : 2;
					if(	((*p22Sequence==(unsigned int)(1<<fw_DI_3A)) && NextFieldMotion) ||
						((*p22Sequence==(unsigned int)(2>>fw_DI_3A)) && PrevFieldMotion))
					{
						*p22Detected = 0;
						*p22Sequence = 0;
						*Violate = 1;
						*film_index=0;
					}
					*/
				}
			}
			break;
		}
	}
	*count_still22 = (*count_still22>=0xff2)? 0xf0:*count_still22;
}

void	scalerVIP_film_FWmode_detection22new_isr(	unsigned int NextStaticPattern, unsigned char Strict,
								unsigned char PrevFieldMotion, unsigned char NextFieldMotion,
							    unsigned char *ExactMatch, unsigned char *Violate, unsigned int *film_index, unsigned int *count_still22,
								unsigned char *p22Detected, unsigned int *p22Sequence)
{
	*ExactMatch = 0;
	*Violate = 0;
	// check frame static pattern for film detection
	switch(NextStaticPattern&0xfffff)
	{
		// (2,2)
		case 0xaaaaa:
		{
			*film_index=FILM22;
			*p22Detected = 1;
			*p22Sequence = (fw_DI_3A) ? 1 : 2;
			*ExactMatch = 1;
			break;
		}
		case 0x55555:
		{
			*film_index=FILM22;
			*p22Detected = 1;
			*p22Sequence = (fw_DI_3A) ? 2 : 1;
			*ExactMatch = 1;
			break;
		}
		case 0xfffff:
			if(Strict)
			{
				*p22Detected = 0;
				*p22Sequence = 0;
				*film_index=0;
				break;
			}
		default:
		{
			*p22Detected = 0;
			*p22Sequence = 0;
			*film_index=0;
			break;
		}
	}
}

static void scalerVIP_film_FWmode_film32_debounce(unsigned char *Detected_flag, unsigned int *Detected_cnt,unsigned char FieldNum)
{
	if(*Detected_flag)
	{
		(*Detected_cnt)++;
		if(*Detected_cnt>0xf)
			*Detected_cnt=0xf;
	}
	else
		*Detected_cnt=0;

	if(*Detected_cnt>FieldNum)
		*Detected_flag=1;
	else
		*Detected_flag=0;
}
static void scalerVIP_film_FWmode_film22_debounce(unsigned char *Detected_flag, unsigned int *Detected_cnt,unsigned char FieldNum)
{
	if(*Detected_flag)
	{
		(*Detected_cnt)++;
		if(*Detected_cnt>0xf)
			*Detected_cnt=0xf;
	}
	else
		*Detected_cnt=0;

	if(*Detected_cnt>FieldNum)
		*Detected_flag=1;
	else
		*Detected_flag=0;
}

void scalerVIP_film_FWmode_film_reset()
{
	static unsigned char film32_debounce_FieldNum = 0xf;
	static unsigned char film22_debounce_FieldNum = 0xf;

	di_im_di_si_film_final_result_RBUS im_di_si_film_final_result_reg;
	di_im_di_si_film_motion_RBUS im_di_si_film_motion_reg;
	di_im_di_si_film_motion_h_t_RBUS im_di_si_film_motion_h_t_reg;
	di_im_di_si_film_motion_h_m_RBUS im_di_si_film_motion_h_m_reg;
	di_im_di_si_film_motion_h_b_RBUS im_di_si_film_motion_h_b_reg;
	di_im_di_si_film_motion_v_l_RBUS im_di_si_film_motion_v_l_reg;
	di_im_di_si_film_motion_v_m_RBUS im_di_si_film_motion_v_m_reg;
	di_im_di_si_film_motion_v_r_RBUS im_di_si_film_motion_v_r_reg;
	di_im_di_si_film_motion_c_RBUS im_di_si_film_motion_c_reg;
	di_im_di_film_motion_sum_th_RBUS im_di_film_motion_sum_th_reg;
	di_im_di_film_new_function_main_RBUS di_im_di_film_new_function_main_reg;

	im_di_si_film_final_result_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_FINAL_RESULT_reg);
	im_di_si_film_motion_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_reg);
	im_di_si_film_motion_h_t_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_H_T_reg);
	im_di_si_film_motion_h_m_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_H_M_reg);
	im_di_si_film_motion_h_b_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_H_B_reg);
	im_di_si_film_motion_v_l_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_V_L_reg);
	im_di_si_film_motion_v_m_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_V_M_reg);
	im_di_si_film_motion_v_r_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_V_R_reg);
	im_di_si_film_motion_c_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_C_reg);
	im_di_film_motion_sum_th_reg.regValue = rtd_inl(DI_IM_DI_FILM_MOTION_SUM_TH_reg);
	di_im_di_film_new_function_main_reg.regValue = rtd_inl(DI_IM_DI_FILM_NEW_FUNCTION_MAIN_reg);

	if(	im_di_si_film_motion_reg.film_motionstatus_399_380 == 0 &&
		im_di_si_film_motion_h_t_reg.film_motionstatus_379_360 == 0 &&
		im_di_si_film_motion_h_m_reg.film_motionstatus_359_340 == 0 &&
		im_di_si_film_motion_h_b_reg.film_motionstatus_339_320 == 0 &&
		im_di_si_film_motion_v_l_reg.film_motionstatus_319_300 == 0 &&
		im_di_si_film_motion_v_m_reg.film_motionstatus_299_280 == 0 &&
		im_di_si_film_motion_v_r_reg.film_motionstatus_279_260 == 0 &&
		im_di_si_film_motion_c_reg.film_motionstatus_259_240==0 &&
		im_di_si_film_final_result_reg.film_detected == 1 &&
		(di_im_di_film_new_function_main_reg.fw_film_en == 0 && di_im_di_film_new_function_main_reg.fw_film_filmdetected == 1)
	) {

		film32_debounce_FieldNum = im_di_film_motion_sum_th_reg.film32_debounce_fieldnum;
		film22_debounce_FieldNum = im_di_film_motion_sum_th_reg.film22_debounce_fieldnum;

		im_di_film_motion_sum_th_reg.film32_debounce_fieldnum = 0xf;
		im_di_film_motion_sum_th_reg.film22_debounce_fieldnum = 0xf;

	} else if(film32_debounce_FieldNum!=0xf && film22_debounce_FieldNum!=0xf) {
		im_di_film_motion_sum_th_reg.film32_debounce_fieldnum = film32_debounce_FieldNum;
		im_di_film_motion_sum_th_reg.film22_debounce_fieldnum = film22_debounce_FieldNum;
	}

	scaler_rtd_outl(DI_IM_DI_FILM_MOTION_SUM_TH_reg, im_di_film_motion_sum_th_reg.regValue);
}

#if 0
void scalerVIP_film_FWmode_3D_start()
{
	di_im_di_debug_mode_RBUS reg18024008_Reg;
	di_im_di_si_film_hb_cout_RBUS reg180240c0_Reg;
	reg18024008_Reg.regValue = rtd_inl(DI_IM_DI_DEBUG_MODE_reg);
	reg180240c0_Reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_HB_COUT_reg);
	unsigned char hw_3D_l_flag = reg18024008_Reg.di_3d_l_flag;
	unsigned char hw_3D_mode = reg180240c0_Reg.film_3d_mode;

  	if( (hw_3D_l_flag==0 /*|| reg_vc_3D_Enable==0*/ || hw_3D_mode==2) && (hw_3D_mode!=1) )
	 {
		//Right=======================================
		StatusFrameStaticPattern    = R_film_StatusFrameStaticPattern   ;
		StatusFrameStaticPattern_H1 = R_film_StatusFrameStaticPattern_H1;
		StatusFrameStaticPattern_H2 = R_film_StatusFrameStaticPattern_H2;
		StatusFrameStaticPattern_H3 = R_film_StatusFrameStaticPattern_H3;
		StatusFrameStaticPattern_V1 = R_film_StatusFrameStaticPattern_V1;
		StatusFrameStaticPattern_V2 = R_film_StatusFrameStaticPattern_V2;
		StatusFrameStaticPattern_V3 = R_film_StatusFrameStaticPattern_V3;
		StatusFrameStaticPattern_C  = R_film_StatusFrameStaticPattern_C ;

		StatusFramePairPattern    = R_film_StatusFramePairPattern   ;
		StatusFramePairPattern_H1 = R_film_StatusFramePairPattern_H1;
		StatusFramePairPattern_H2 = R_film_StatusFramePairPattern_H2;
		StatusFramePairPattern_H3 = R_film_StatusFramePairPattern_H3;
		StatusFramePairPattern_V1 = R_film_StatusFramePairPattern_V1;
		StatusFramePairPattern_V2 = R_film_StatusFramePairPattern_V2;
		StatusFramePairPattern_V3 = R_film_StatusFramePairPattern_V3;
		StatusFramePairPattern_C  = R_film_StatusFramePairPattern_C ;

		StatusPrevStaticPattern2    = R_film_StatusPrevStaticPattern2   ;
		StatusPrevStaticPattern2_H1 = R_film_StatusPrevStaticPattern2_H1;
		StatusPrevStaticPattern2_H2 = R_film_StatusPrevStaticPattern2_H2;
		StatusPrevStaticPattern2_H3 = R_film_StatusPrevStaticPattern2_H3;
		StatusPrevStaticPattern2_V1 = R_film_StatusPrevStaticPattern2_V1;
		StatusPrevStaticPattern2_V2 = R_film_StatusPrevStaticPattern2_V2;
		StatusPrevStaticPattern2_V3 = R_film_StatusPrevStaticPattern2_V3;
		StatusPrevStaticPattern2_C  = R_film_StatusPrevStaticPattern2_C ;

		StatusNextStaticPattern    = R_film_StatusNextStaticPattern   ;
		StatusNextStaticPattern_H1 = R_film_StatusNextStaticPattern_H1;
		StatusNextStaticPattern_H2 = R_film_StatusNextStaticPattern_H2;
		StatusNextStaticPattern_H3 = R_film_StatusNextStaticPattern_H3;
		StatusNextStaticPattern_V1 = R_film_StatusNextStaticPattern_V1;
		StatusNextStaticPattern_V2 = R_film_StatusNextStaticPattern_V2;
		StatusNextStaticPattern_V3 = R_film_StatusNextStaticPattern_V3;
		StatusNextStaticPattern_C  = R_film_StatusNextStaticPattern_C ;

		StatusNextStaticPattern2    = R_film_StatusNextStaticPattern2   ;
		StatusNextStaticPattern2_H1 = R_film_StatusNextStaticPattern2_H1;
		StatusNextStaticPattern2_H2 = R_film_StatusNextStaticPattern2_H2;
		StatusNextStaticPattern2_H3 = R_film_StatusNextStaticPattern2_H3;
		StatusNextStaticPattern2_V1 = R_film_StatusNextStaticPattern2_V1;
		StatusNextStaticPattern2_V2 = R_film_StatusNextStaticPattern2_V2;
		StatusNextStaticPattern2_V3 = R_film_StatusNextStaticPattern2_V3;
		StatusNextStaticPattern2_C  = R_film_StatusNextStaticPattern2_C ;

		Status32Detected1    = R_film_Status32Detected1   ;
		Status32Detected2    = R_film_Status32Detected2   ;
		Status32Detected1_H1 = R_film_Status32Detected1_H1;
		Status32Detected1_H2 = R_film_Status32Detected1_H2;
		Status32Detected1_H3 = R_film_Status32Detected1_H3;
		Status32Detected1_V1 = R_film_Status32Detected1_V1;
		Status32Detected1_V2 = R_film_Status32Detected1_V2;
		Status32Detected1_V3 = R_film_Status32Detected1_V3;
		Status32Detected1_C  = R_film_Status32Detected1_C ;
		Status32Detected2_H1 = R_film_Status32Detected2_H1;
		Status32Detected2_H2 = R_film_Status32Detected2_H2;
		Status32Detected2_H3 = R_film_Status32Detected2_H3;
		Status32Detected2_V1 = R_film_Status32Detected2_V1;
		Status32Detected2_V2 = R_film_Status32Detected2_V2;
		Status32Detected2_V3 = R_film_Status32Detected2_V3;
		Status32Detected2_C  = R_film_Status32Detected2_C ;
		Status22Detected     = R_film_Status22Detected    ;
		Status22Detected_H1  = R_film_Status22Detected_H1 ;
		Status22Detected_H2  = R_film_Status22Detected_H2 ;
		Status22Detected_H3  = R_film_Status22Detected_H3 ;
		Status22Detected_V1  = R_film_Status22Detected_V1 ;
		Status22Detected_V2  = R_film_Status22Detected_V2 ;
		Status22Detected_V3  = R_film_Status22Detected_V3 ;
		Status22Detected_C   = R_film_Status22Detected_C  ;

	  	Status32Sequence1    = R_film_Status32Sequence1   ;
	  	Status32Sequence2    = R_film_Status32Sequence2   ;
	  	Status32Sequence1_H1 = R_film_Status32Sequence1_H1;
	  	Status32Sequence1_H2 = R_film_Status32Sequence1_H2;
	  	Status32Sequence1_H3 = R_film_Status32Sequence1_H3;
	  	Status32Sequence1_V1 = R_film_Status32Sequence1_V1;
	  	Status32Sequence1_V2 = R_film_Status32Sequence1_V2;
	  	Status32Sequence1_V3 = R_film_Status32Sequence1_V3;
	  	Status32Sequence1_C  = R_film_Status32Sequence1_C ;
	  	Status32Sequence2_H1 = R_film_Status32Sequence2_H1;
	  	Status32Sequence2_H2 = R_film_Status32Sequence2_H2;
	  	Status32Sequence2_H3 = R_film_Status32Sequence2_H3;
	  	Status32Sequence2_V1 = R_film_Status32Sequence2_V1;
	  	Status32Sequence2_V2 = R_film_Status32Sequence2_V2;
	  	Status32Sequence2_V3 = R_film_Status32Sequence2_V3;
	  	Status32Sequence2_C  = R_film_Status32Sequence2_C ;
	  	Status22Sequence     = R_film_Status22Sequence    ;
	  	Status22Sequence_H1  = R_film_Status22Sequence_H1 ;
	  	Status22Sequence_H2  = R_film_Status22Sequence_H2 ;
	  	Status22Sequence_H3  = R_film_Status22Sequence_H3 ;
	  	Status22Sequence_V1  = R_film_Status22Sequence_V1 ;
	  	Status22Sequence_V2  = R_film_Status22Sequence_V2 ;
	  	Status22Sequence_V3  = R_film_Status22Sequence_V3 ;
	  	Status22Sequence_C   = R_film_Status22Sequence_C  ;

	  	StatusNextStaticPattern_film22    = R_film22_StatusNextStaticPattern   ;
	  	StatusNextStaticPattern_film22_H1 = R_film22_StatusNextStaticPattern_H1;
	  	StatusNextStaticPattern_film22_H2 = R_film22_StatusNextStaticPattern_H2;
	  	StatusNextStaticPattern_film22_H3 = R_film22_StatusNextStaticPattern_H3;
	  	StatusNextStaticPattern_film22_V1 = R_film22_StatusNextStaticPattern_V1;
	  	StatusNextStaticPattern_film22_V2 = R_film22_StatusNextStaticPattern_V2;
	  	StatusNextStaticPattern_film22_V3 = R_film22_StatusNextStaticPattern_V3;
	  	StatusNextStaticPattern_film22_C  = R_film22_StatusNextStaticPattern_C ;

	 	Status32Detected1_cnt   =R_Status32Detected1_cnt   ;
	 	Status32Detected1_H1_cnt=R_Status32Detected1_H1_cnt;
	 	Status32Detected1_H2_cnt=R_Status32Detected1_H2_cnt;
	 	Status32Detected1_H3_cnt=R_Status32Detected1_H3_cnt;
	 	Status32Detected1_V1_cnt=R_Status32Detected1_V1_cnt;
	 	Status32Detected1_V2_cnt=R_Status32Detected1_V2_cnt;
	 	Status32Detected1_V3_cnt=R_Status32Detected1_V3_cnt;
	 	Status32Detected1_C_cnt =R_Status32Detected1_C_cnt ;

	 	Status32Detected2_cnt   =R_Status32Detected2_cnt   ;
	 	Status32Detected2_H1_cnt=R_Status32Detected2_H1_cnt;
	 	Status32Detected2_H2_cnt=R_Status32Detected2_H2_cnt;
	 	Status32Detected2_H3_cnt=R_Status32Detected2_H3_cnt;
	 	Status32Detected2_V1_cnt=R_Status32Detected2_V1_cnt;
	 	Status32Detected2_V2_cnt=R_Status32Detected2_V2_cnt;
	 	Status32Detected2_V3_cnt=R_Status32Detected2_V3_cnt;
	 	Status32Detected2_C_cnt =R_Status32Detected2_C_cnt ;

	 	Status22Detected_cnt   =R_Status22Detected_cnt   ;
	 	Status22Detected_H1_cnt=R_Status22Detected_H1_cnt;
	 	Status22Detected_H2_cnt=R_Status22Detected_H2_cnt;
	 	Status22Detected_H3_cnt=R_Status22Detected_H3_cnt;
	 	Status22Detected_V1_cnt=R_Status22Detected_V1_cnt;
	 	Status22Detected_V2_cnt=R_Status22Detected_V2_cnt;
	 	Status22Detected_V3_cnt=R_Status22Detected_V3_cnt;
	 	Status22Detected_C_cnt =R_Status22Detected_C_cnt ;

		StatusFilmDetected     =  R_film_StatusFilmDetected;
		StatusFilmSequence     =  R_film_StatusFilmSequence;
		StatusMixedFilmDetected=  R_StatusMixedFilmDetected;

		NextTopDetected_d                     =  R_NextTopDetected_d      ;
		NextTopDetected                       =  R_NextTopDetected        ;
		PrevTopDetected_d                     =  R_PrevTopDetected_d      ;
		PrevTopDetected                       =  R_PrevTopDetected        ;
		TopLine                               =  R_TopLine                ;
		BotLine                               =  R_BotLine                ;
		TopLine2                              =  R_TopLine2               ;
		BotLine2                              =  R_BotLine2               ;
		TopLine3                              =  R_TopLine3               ;
		BotLine3                              =  R_BotLine3               ;

		// fw add
		index32 = R_film_index32;
		index32_H1 = R_film_index32_H1;
		index32_H2 = R_film_index32_H2;
		index32_H3 = R_film_index32_H3;
		index32_V1 = R_film_index32_V1;
		index32_V2 = R_film_index32_V2;
		index32_V3 = R_film_index32_V3;
		index32_C = R_film_index32_C;

		/*
		stillpix_count32 = R_film_stillpix_count32;
		stillpix_count32_H1 = R_film_stillpix_count32_H1;
		stillpix_count32_H2 = R_film_stillpix_count32_H2;
		stillpix_count32_H3 = R_film_stillpix_count32_H3;
		stillpix_count32_V1 = R_film_stillpix_count32_V1;
		stillpix_count32_V2 = R_film_stillpix_count32_V2;
		stillpix_count32_V3 = R_film_stillpix_count32_V3;
		stillpix_count32_C = R_film_stillpix_count32_C;
		*/
		index322 = R_film_index322;
		index322_H1 = R_film_index322_H1;
		index322_H2 = R_film_index322_H2;
		index322_H3 = R_film_index322_H3;
		index322_V1 = R_film_index322_V1;
		index322_V2 = R_film_index322_V2;
		index322_V3 = R_film_index322_V3;
		index322_C = R_film_index322_C;

		index22 = R_film_index22;
		index22_H1 = R_film_index22_H1;
		index22_H2 = R_film_index22_H2;
		index22_H3 = R_film_index22_H3;
		index22_V1 = R_film_index22_V1;
		index22_V2 = R_film_index22_V2;
		index22_V3 = R_film_index22_V3;
		index22_C = R_film_index22_C;

		/*
		stillpix_count22 = R_film_stillpix_count22;
		stillpix_count22_H1 = R_film_stillpix_count22_H1;
		stillpix_count22_H2 = R_film_stillpix_count22_H2;
		stillpix_count22_H3 = R_film_stillpix_count22_H3;
		stillpix_count22_V1 = R_film_stillpix_count22_V1;
		stillpix_count22_V2 = R_film_stillpix_count22_V2;
		stillpix_count22_V3 = R_film_stillpix_count22_V3;
		stillpix_count22_C = R_film_stillpix_count22_C;
		*/

		film_index = R_film_index;
		force_weave_flag = R_force_weave_flag;
		weave_prev = R_weave_prev;
	  }
	  else
	  {
		//Left=======================================
		StatusFrameStaticPattern    = L_film_StatusFrameStaticPattern   ;
		StatusFrameStaticPattern_H1 = L_film_StatusFrameStaticPattern_H1;
		StatusFrameStaticPattern_H2 = L_film_StatusFrameStaticPattern_H2;
		StatusFrameStaticPattern_H3 = L_film_StatusFrameStaticPattern_H3;
		StatusFrameStaticPattern_V1 = L_film_StatusFrameStaticPattern_V1;
		StatusFrameStaticPattern_V2 = L_film_StatusFrameStaticPattern_V2;
		StatusFrameStaticPattern_V3 = L_film_StatusFrameStaticPattern_V3;
		StatusFrameStaticPattern_C  = L_film_StatusFrameStaticPattern_C ;

		StatusFramePairPattern    = L_film_StatusFramePairPattern   ;
		StatusFramePairPattern_H1 = L_film_StatusFramePairPattern_H1;
		StatusFramePairPattern_H2 = L_film_StatusFramePairPattern_H2;
		StatusFramePairPattern_H3 = L_film_StatusFramePairPattern_H3;
		StatusFramePairPattern_V1 = L_film_StatusFramePairPattern_V1;
		StatusFramePairPattern_V2 = L_film_StatusFramePairPattern_V2;
		StatusFramePairPattern_V3 = L_film_StatusFramePairPattern_V3;
		StatusFramePairPattern_C  = L_film_StatusFramePairPattern_C ;

		StatusPrevStaticPattern2    = L_film_StatusPrevStaticPattern2   ;
		StatusPrevStaticPattern2_H1 = L_film_StatusPrevStaticPattern2_H1;
		StatusPrevStaticPattern2_H2 = L_film_StatusPrevStaticPattern2_H2;
		StatusPrevStaticPattern2_H3 = L_film_StatusPrevStaticPattern2_H3;
		StatusPrevStaticPattern2_V1 = L_film_StatusPrevStaticPattern2_V1;
		StatusPrevStaticPattern2_V2 = L_film_StatusPrevStaticPattern2_V2;
		StatusPrevStaticPattern2_V3 = L_film_StatusPrevStaticPattern2_V3;
		StatusPrevStaticPattern2_C  = L_film_StatusPrevStaticPattern2_C ;

		StatusNextStaticPattern    = L_film_StatusNextStaticPattern   ;
		StatusNextStaticPattern_H1 = L_film_StatusNextStaticPattern_H1;
		StatusNextStaticPattern_H2 = L_film_StatusNextStaticPattern_H2;
		StatusNextStaticPattern_H3 = L_film_StatusNextStaticPattern_H3;
		StatusNextStaticPattern_V1 = L_film_StatusNextStaticPattern_V1;
		StatusNextStaticPattern_V2 = L_film_StatusNextStaticPattern_V2;
		StatusNextStaticPattern_V3 = L_film_StatusNextStaticPattern_V3;
		StatusNextStaticPattern_C  = L_film_StatusNextStaticPattern_C ;

		StatusNextStaticPattern2    = L_film_StatusNextStaticPattern2   ;
		StatusNextStaticPattern2_H1 = L_film_StatusNextStaticPattern2_H1;
		StatusNextStaticPattern2_H2 = L_film_StatusNextStaticPattern2_H2;
		StatusNextStaticPattern2_H3 = L_film_StatusNextStaticPattern2_H3;
		StatusNextStaticPattern2_V1 = L_film_StatusNextStaticPattern2_V1;
		StatusNextStaticPattern2_V2 = L_film_StatusNextStaticPattern2_V2;
		StatusNextStaticPattern2_V3 = L_film_StatusNextStaticPattern2_V3;
		StatusNextStaticPattern2_C  = L_film_StatusNextStaticPattern2_C ;

		Status32Detected1    = L_film_Status32Detected1   ;
		Status32Detected2    = L_film_Status32Detected2   ;
		Status32Detected1_H1 = L_film_Status32Detected1_H1;
		Status32Detected1_H2 = L_film_Status32Detected1_H2;
		Status32Detected1_H3 = L_film_Status32Detected1_H3;
		Status32Detected1_V1 = L_film_Status32Detected1_V1;
		Status32Detected1_V2 = L_film_Status32Detected1_V2;
		Status32Detected1_V3 = L_film_Status32Detected1_V3;
		Status32Detected1_C  = L_film_Status32Detected1_C ;
		Status32Detected2_H1 = L_film_Status32Detected2_H1;
		Status32Detected2_H2 = L_film_Status32Detected2_H2;
		Status32Detected2_H3 = L_film_Status32Detected2_H3;
		Status32Detected2_V1 = L_film_Status32Detected2_V1;
		Status32Detected2_V2 = L_film_Status32Detected2_V2;
		Status32Detected2_V3 = L_film_Status32Detected2_V3;
		Status32Detected2_C  = L_film_Status32Detected2_C ;
		Status22Detected     = L_film_Status22Detected    ;
		Status22Detected_H1  = L_film_Status22Detected_H1 ;
		Status22Detected_H2  = L_film_Status22Detected_H2 ;
		Status22Detected_H3  = L_film_Status22Detected_H3 ;
		Status22Detected_V1  = L_film_Status22Detected_V1 ;
		Status22Detected_V2  = L_film_Status22Detected_V2 ;
		Status22Detected_V3  = L_film_Status22Detected_V3 ;
		Status22Detected_C   = L_film_Status22Detected_C  ;

	  	Status32Sequence1    = L_film_Status32Sequence1   ;
	  	Status32Sequence2    = L_film_Status32Sequence2   ;
	  	Status32Sequence1_H1 = L_film_Status32Sequence1_H1;
	  	Status32Sequence1_H2 = L_film_Status32Sequence1_H2;
	  	Status32Sequence1_H3 = L_film_Status32Sequence1_H3;
	  	Status32Sequence1_V1 = L_film_Status32Sequence1_V1;
	  	Status32Sequence1_V2 = L_film_Status32Sequence1_V2;
	  	Status32Sequence1_V3 = L_film_Status32Sequence1_V3;
	  	Status32Sequence1_C  = L_film_Status32Sequence1_C ;
	  	Status32Sequence2_H1 = L_film_Status32Sequence2_H1;
	  	Status32Sequence2_H2 = L_film_Status32Sequence2_H2;
	  	Status32Sequence2_H3 = L_film_Status32Sequence2_H3;
	  	Status32Sequence2_V1 = L_film_Status32Sequence2_V1;
	  	Status32Sequence2_V2 = L_film_Status32Sequence2_V2;
	  	Status32Sequence2_V3 = L_film_Status32Sequence2_V3;
	  	Status32Sequence2_C  = L_film_Status32Sequence2_C ;
	  	Status22Sequence     = L_film_Status22Sequence    ;
	  	Status22Sequence_H1  = L_film_Status22Sequence_H1 ;
	  	Status22Sequence_H2  = L_film_Status22Sequence_H2 ;
	  	Status22Sequence_H3  = L_film_Status22Sequence_H3 ;
	  	Status22Sequence_V1  = L_film_Status22Sequence_V1 ;
	  	Status22Sequence_V2  = L_film_Status22Sequence_V2 ;
	  	Status22Sequence_V3  = L_film_Status22Sequence_V3 ;
	  	Status22Sequence_C   = L_film_Status22Sequence_C  ;

	  	StatusNextStaticPattern_film22    = L_film22_StatusNextStaticPattern   ;
	  	StatusNextStaticPattern_film22_H1 = L_film22_StatusNextStaticPattern_H1;
	  	StatusNextStaticPattern_film22_H2 = L_film22_StatusNextStaticPattern_H2;
	  	StatusNextStaticPattern_film22_H3 = L_film22_StatusNextStaticPattern_H3;
	  	StatusNextStaticPattern_film22_V1 = L_film22_StatusNextStaticPattern_V1;
	  	StatusNextStaticPattern_film22_V2 = L_film22_StatusNextStaticPattern_V2;
	  	StatusNextStaticPattern_film22_V3 = L_film22_StatusNextStaticPattern_V3;
	  	StatusNextStaticPattern_film22_C  = L_film22_StatusNextStaticPattern_C ;

	 	Status32Detected1_cnt   =L_Status32Detected1_cnt   ;
	 	Status32Detected1_H1_cnt=L_Status32Detected1_H1_cnt;
	 	Status32Detected1_H2_cnt=L_Status32Detected1_H2_cnt;
	 	Status32Detected1_H3_cnt=L_Status32Detected1_H3_cnt;
	 	Status32Detected1_V1_cnt=L_Status32Detected1_V1_cnt;
	 	Status32Detected1_V2_cnt=L_Status32Detected1_V2_cnt;
	 	Status32Detected1_V3_cnt=L_Status32Detected1_V3_cnt;
	 	Status32Detected1_C_cnt =L_Status32Detected1_C_cnt ;

	 	Status32Detected2_cnt   =L_Status32Detected2_cnt   ;
	 	Status32Detected2_H1_cnt=L_Status32Detected2_H1_cnt;
	 	Status32Detected2_H2_cnt=L_Status32Detected2_H2_cnt;
	 	Status32Detected2_H3_cnt=L_Status32Detected2_H3_cnt;
	 	Status32Detected2_V1_cnt=L_Status32Detected2_V1_cnt;
	 	Status32Detected2_V2_cnt=L_Status32Detected2_V2_cnt;
	 	Status32Detected2_V3_cnt=L_Status32Detected2_V3_cnt;
	 	Status32Detected2_C_cnt =L_Status32Detected2_C_cnt ;

	 	Status22Detected_cnt   =L_Status22Detected_cnt   ;
	 	Status22Detected_H1_cnt=L_Status22Detected_H1_cnt;
	 	Status22Detected_H2_cnt=L_Status22Detected_H2_cnt;
	 	Status22Detected_H3_cnt=L_Status22Detected_H3_cnt;
	 	Status22Detected_V1_cnt=L_Status22Detected_V1_cnt;
	 	Status22Detected_V2_cnt=L_Status22Detected_V2_cnt;
	 	Status22Detected_V3_cnt=L_Status22Detected_V3_cnt;
	 	Status22Detected_C_cnt =L_Status22Detected_C_cnt ;

		StatusFilmDetected	  =  L_film_StatusFilmDetected;
		StatusFilmSequence     =  L_film_StatusFilmSequence;
		StatusMixedFilmDetected=  L_StatusMixedFilmDetected;
		NextTopDetected_d                     =  L_NextTopDetected_d      ;
		NextTopDetected                       =  L_NextTopDetected        ;
		PrevTopDetected_d                     =  L_PrevTopDetected_d      ;
		PrevTopDetected                       =  L_PrevTopDetected        ;
		TopLine                               =  L_TopLine                ;
		BotLine                               =  L_BotLine                ;
		TopLine2                              =  L_TopLine2               ;
		BotLine2                              =  L_BotLine2               ;
		TopLine3                              =  L_TopLine3               ;
		BotLine3                              =  L_BotLine3               ;

		// fw add
		index32 = L_film_index32;
		index32_H1 = L_film_index32_H1;
		index32_H2 = L_film_index32_H2;
		index32_H3 = L_film_index32_H3;
		index32_V1 = L_film_index32_V1;
		index32_V2 = L_film_index32_V2;
		index32_V3 = L_film_index32_V3;
		index32_C = L_film_index32_C;

		/*
		stillpix_count32 = L_film_stillpix_count32;
		stillpix_count32_H1 = L_film_stillpix_count32_H1;
		stillpix_count32_H2 = L_film_stillpix_count32_H2;
		stillpix_count32_H3 = L_film_stillpix_count32_H3;
		stillpix_count32_V1 = L_film_stillpix_count32_V1;
		stillpix_count32_V2 = L_film_stillpix_count32_V2;
		stillpix_count32_V3 = L_film_stillpix_count32_V3;
		stillpix_count32_C = L_film_stillpix_count32_C;
		*/

		index322 = L_film_index322;
		index322_H1 = L_film_index322_H1;
		index322_H2 = L_film_index322_H2;
		index322_H3 = L_film_index322_H3;
		index322_V1 = L_film_index322_V1;
		index322_V2 = L_film_index322_V2;
		index322_V3 = L_film_index322_V3;
		index322_C = L_film_index322_C;

		index22 = L_film_index22;
		index22_H1 = L_film_index22_H1;
		index22_H2 = L_film_index22_H2;
		index22_H3 = L_film_index22_H3;
		index22_V1 = L_film_index22_V1;
		index22_V2 = L_film_index22_V2;
		index22_V3 = L_film_index22_V3;
		index22_C = L_film_index22_C;

		/*
		stillpix_count22 = L_film_stillpix_count22;
		stillpix_count22_H1 = L_film_stillpix_count22_H1;
		stillpix_count22_H2 = L_film_stillpix_count22_H2;
		stillpix_count22_H3 = L_film_stillpix_count22_H3;
		stillpix_count22_V1 = L_film_stillpix_count22_V1;
		stillpix_count22_V2 = L_film_stillpix_count22_V2;
		stillpix_count22_V3 = L_film_stillpix_count22_V3;
		stillpix_count22_C = L_film_stillpix_count22_C;
		*/

		film_index = L_film_index;
		force_weave_flag = L_force_weave_flag;
		weave_prev = L_weave_prev;
	  }
}
void scalerVIP_film_FWmode_3D_end()
{
	di_im_di_debug_mode_RBUS reg18024008_Reg;
	reg18024008_Reg.regValue = rtd_inl(DI_IM_DI_DEBUG_MODE_reg);
	unsigned char hw_3D_l_flag = reg18024008_Reg.di_3d_l_flag;

	  if(hw_3D_l_flag==0)// || reg_vc_3D_Enable==0)
	  {
		//Right=======================================
		R_film_StatusFrameStaticPattern    = StatusFrameStaticPattern   ;
		R_film_StatusFrameStaticPattern_H1 = StatusFrameStaticPattern_H1;
		R_film_StatusFrameStaticPattern_H2 = StatusFrameStaticPattern_H2;
		R_film_StatusFrameStaticPattern_H3 = StatusFrameStaticPattern_H3;
		R_film_StatusFrameStaticPattern_V1 = StatusFrameStaticPattern_V1;
		R_film_StatusFrameStaticPattern_V2 = StatusFrameStaticPattern_V2;
		R_film_StatusFrameStaticPattern_V3 = StatusFrameStaticPattern_V3;
		R_film_StatusFrameStaticPattern_C  = StatusFrameStaticPattern_C ;

		R_film_StatusFramePairPattern    = StatusFramePairPattern   ;
		R_film_StatusFramePairPattern_H1 = StatusFramePairPattern_H1;
		R_film_StatusFramePairPattern_H2 = StatusFramePairPattern_H2;
		R_film_StatusFramePairPattern_H3 = StatusFramePairPattern_H3;
		R_film_StatusFramePairPattern_V1 = StatusFramePairPattern_V1;
		R_film_StatusFramePairPattern_V2 = StatusFramePairPattern_V2;
		R_film_StatusFramePairPattern_V3 = StatusFramePairPattern_V3;
		R_film_StatusFramePairPattern_C  = StatusFramePairPattern_C ;

		R_film_StatusPrevStaticPattern2    = StatusPrevStaticPattern2   ;
		R_film_StatusPrevStaticPattern2_H1 = StatusPrevStaticPattern2_H1;
		R_film_StatusPrevStaticPattern2_H2 = StatusPrevStaticPattern2_H2;
		R_film_StatusPrevStaticPattern2_H3 = StatusPrevStaticPattern2_H3;
		R_film_StatusPrevStaticPattern2_V1 = StatusPrevStaticPattern2_V1;
		R_film_StatusPrevStaticPattern2_V2 = StatusPrevStaticPattern2_V2;
		R_film_StatusPrevStaticPattern2_V3 = StatusPrevStaticPattern2_V3;
		R_film_StatusPrevStaticPattern2_C  = StatusPrevStaticPattern2_C ;

		R_film_StatusNextStaticPattern    = StatusNextStaticPattern   ;
		R_film_StatusNextStaticPattern_H1 = StatusNextStaticPattern_H1;
		R_film_StatusNextStaticPattern_H2 = StatusNextStaticPattern_H2;
		R_film_StatusNextStaticPattern_H3 = StatusNextStaticPattern_H3;
		R_film_StatusNextStaticPattern_V1 = StatusNextStaticPattern_V1;
		R_film_StatusNextStaticPattern_V2 = StatusNextStaticPattern_V2;
		R_film_StatusNextStaticPattern_V3 = StatusNextStaticPattern_V3;
		R_film_StatusNextStaticPattern_C  = StatusNextStaticPattern_C ;

		R_film_StatusNextStaticPattern2    = StatusNextStaticPattern2   ;
		R_film_StatusNextStaticPattern2_H1 = StatusNextStaticPattern2_H1;
		R_film_StatusNextStaticPattern2_H2 = StatusNextStaticPattern2_H2;
		R_film_StatusNextStaticPattern2_H3 = StatusNextStaticPattern2_H3;
		R_film_StatusNextStaticPattern2_V1 = StatusNextStaticPattern2_V1;
		R_film_StatusNextStaticPattern2_V2 = StatusNextStaticPattern2_V2;
		R_film_StatusNextStaticPattern2_V3 = StatusNextStaticPattern2_V3;
		R_film_StatusNextStaticPattern2_C  = StatusNextStaticPattern2_C ;

		R_film_Status32Detected1    = Status32Detected1   ;
		R_film_Status32Detected2    = Status32Detected2   ;
		R_film_Status32Detected1_H1 = Status32Detected1_H1;
		R_film_Status32Detected1_H2 = Status32Detected1_H2;
		R_film_Status32Detected1_H3 = Status32Detected1_H3;
		R_film_Status32Detected1_V1 = Status32Detected1_V1;
		R_film_Status32Detected1_V2 = Status32Detected1_V2;
		R_film_Status32Detected1_V3 = Status32Detected1_V3;
		R_film_Status32Detected1_C  = Status32Detected1_C ;
		R_film_Status32Detected2_H1 = Status32Detected2_H1;
		R_film_Status32Detected2_H2 = Status32Detected2_H2;
		R_film_Status32Detected2_H3 = Status32Detected2_H3;
		R_film_Status32Detected2_V1 = Status32Detected2_V1;
		R_film_Status32Detected2_V2 = Status32Detected2_V2;
		R_film_Status32Detected2_V3 = Status32Detected2_V3;
		R_film_Status32Detected2_C  = Status32Detected2_C ;
		R_film_Status22Detected     = Status22Detected    ;
		R_film_Status22Detected_H1  = Status22Detected_H1 ;
		R_film_Status22Detected_H2  = Status22Detected_H2 ;
		R_film_Status22Detected_H3  = Status22Detected_H3 ;
		R_film_Status22Detected_V1  = Status22Detected_V1 ;
		R_film_Status22Detected_V2  = Status22Detected_V2 ;
		R_film_Status22Detected_V3  = Status22Detected_V3 ;
		R_film_Status22Detected_C   = Status22Detected_C  ;

	  	R_film_Status32Sequence1    = Status32Sequence1   ;
	  	R_film_Status32Sequence2    = Status32Sequence2   ;
	  	R_film_Status32Sequence1_H1 = Status32Sequence1_H1;
	  	R_film_Status32Sequence1_H2 = Status32Sequence1_H2;
	  	R_film_Status32Sequence1_H3 = Status32Sequence1_H3;
	  	R_film_Status32Sequence1_V1 = Status32Sequence1_V1;
	  	R_film_Status32Sequence1_V2 = Status32Sequence1_V2;
	  	R_film_Status32Sequence1_V3 = Status32Sequence1_V3;
	  	R_film_Status32Sequence1_C  = Status32Sequence1_C ;
	  	R_film_Status32Sequence2_H1 = Status32Sequence2_H1;
	  	R_film_Status32Sequence2_H2 = Status32Sequence2_H2;
	  	R_film_Status32Sequence2_H3 = Status32Sequence2_H3;
	  	R_film_Status32Sequence2_V1 = Status32Sequence2_V1;
	  	R_film_Status32Sequence2_V2 = Status32Sequence2_V2;
	  	R_film_Status32Sequence2_V3 = Status32Sequence2_V3;
	  	R_film_Status32Sequence2_C  = Status32Sequence2_C ;
	  	R_film_Status22Sequence     = Status22Sequence    ;
	  	R_film_Status22Sequence_H1  = Status22Sequence_H1 ;
	  	R_film_Status22Sequence_H2  = Status22Sequence_H2 ;
	  	R_film_Status22Sequence_H3  = Status22Sequence_H3 ;
	  	R_film_Status22Sequence_V1  = Status22Sequence_V1 ;
	  	R_film_Status22Sequence_V2  = Status22Sequence_V2 ;
	  	R_film_Status22Sequence_V3  = Status22Sequence_V3 ;
	  	R_film_Status22Sequence_C   = Status22Sequence_C  ;

	  	R_film22_StatusNextStaticPattern    = StatusNextStaticPattern_film22   ;
	  	R_film22_StatusNextStaticPattern_H1 = StatusNextStaticPattern_film22_H1;
	  	R_film22_StatusNextStaticPattern_H2 = StatusNextStaticPattern_film22_H2;
	  	R_film22_StatusNextStaticPattern_H3 = StatusNextStaticPattern_film22_H3;
	  	R_film22_StatusNextStaticPattern_V1 = StatusNextStaticPattern_film22_V1;
	  	R_film22_StatusNextStaticPattern_V2 = StatusNextStaticPattern_film22_V2;
	  	R_film22_StatusNextStaticPattern_V3 = StatusNextStaticPattern_film22_V3;
	  	R_film22_StatusNextStaticPattern_C  = StatusNextStaticPattern_film22_C ;

	 	R_Status32Detected1_cnt   =Status32Detected1_cnt   ;
	 	R_Status32Detected1_H1_cnt=Status32Detected1_H1_cnt;
	 	R_Status32Detected1_H2_cnt=Status32Detected1_H2_cnt;
	 	R_Status32Detected1_H3_cnt=Status32Detected1_H3_cnt;
	 	R_Status32Detected1_V1_cnt=Status32Detected1_V1_cnt;
	 	R_Status32Detected1_V2_cnt=Status32Detected1_V2_cnt;
	 	R_Status32Detected1_V3_cnt=Status32Detected1_V3_cnt;
	 	R_Status32Detected1_C_cnt =Status32Detected1_C_cnt ;

	 	R_Status32Detected2_cnt   =Status32Detected2_cnt   ;
	 	R_Status32Detected2_H1_cnt=Status32Detected2_H1_cnt;
	 	R_Status32Detected2_H2_cnt=Status32Detected2_H2_cnt;
	 	R_Status32Detected2_H3_cnt=Status32Detected2_H3_cnt;
	 	R_Status32Detected2_V1_cnt=Status32Detected2_V1_cnt;
	 	R_Status32Detected2_V2_cnt=Status32Detected2_V2_cnt;
	 	R_Status32Detected2_V3_cnt=Status32Detected2_V3_cnt;
	 	R_Status32Detected2_C_cnt =Status32Detected2_C_cnt ;

	 	R_Status22Detected_cnt   =Status22Detected_cnt   ;
	 	R_Status22Detected_H1_cnt=Status22Detected_H1_cnt;
	 	R_Status22Detected_H2_cnt=Status22Detected_H2_cnt;
	 	R_Status22Detected_H3_cnt=Status22Detected_H3_cnt;
	 	R_Status22Detected_V1_cnt=Status22Detected_V1_cnt;
	 	R_Status22Detected_V2_cnt=Status22Detected_V2_cnt;
	 	R_Status22Detected_V3_cnt=Status22Detected_V3_cnt;
	 	R_Status22Detected_C_cnt =Status22Detected_C_cnt ;

		R_film_StatusFilmDetected=StatusFilmDetected       ;
		R_film_StatusFilmSequence= StatusFilmSequence      ;
		R_StatusMixedFilmDetected= StatusMixedFilmDetected ;
		R_NextTopDetected_d      = NextTopDetected_d                      ;
		R_NextTopDetected        = NextTopDetected                        ;
		R_PrevTopDetected_d      = PrevTopDetected_d                      ;
		R_PrevTopDetected        = PrevTopDetected                        ;
		R_TopLine                = TopLine                                ;
		R_BotLine                = BotLine                                ;
		R_TopLine2               = TopLine2                               ;
		R_BotLine2               = BotLine2                               ;
		R_TopLine3               = TopLine3                               ;
		R_BotLine3               = BotLine3                               ;

		// fw add
		R_film_index32 = index32  ;
		R_film_index32_H1 = index32_H1 ;
		R_film_index32_H2 = index32_H2 ;
		R_film_index32_H3 = index32_H3 ;
		R_film_index32_V1 = index32_V1  ;
		R_film_index32_V2 = index32_V2  ;
		R_film_index32_V3 = index32_V3  ;
		R_film_index32_C = index32_C  ;

		/*
		R_film_stillpix_count32 = stillpix_count32 ;
		R_film_stillpix_count32_H1 = stillpix_count32_H1 ;
		R_film_stillpix_count32_H2 = stillpix_count32_H2 ;
		R_film_stillpix_count32_H3 = stillpix_count32_H3 ;
		R_film_stillpix_count32_V1 = stillpix_count32_V1 ;
		R_film_stillpix_count32_V2 = stillpix_count32_V2 ;
		R_film_stillpix_count32_V3 = stillpix_count32_V3 ;
		R_film_stillpix_count32_C = stillpix_count32_C ;
		*/

		R_film_index322 = index322 ;
		R_film_index322_H1 = index322_H1;
		R_film_index322_H2 = index322_H2;
		R_film_index322_H3 = index322_H3 ;
		R_film_index322_V1 = index322_V1 ;
		R_film_index322_V2 = index322_V2 ;
		R_film_index322_V3 = index322_V3 ;
		R_film_index322_C = index322_C ;

		R_film_index22 = index22 ;
		R_film_index22_H1 = index22_H1 ;
		R_film_index22_H2 = index22_H2 ;
		R_film_index22_H3 = index22_H3  ;
		R_film_index22_V1 = index22_V1  ;
		R_film_index22_V2 = index22_V2  ;
		R_film_index22_V3 = index22_V3  ;
		R_film_index22_C = index22_C ;

		/*
		R_film_stillpix_count22 = stillpix_count22 ;
		R_film_stillpix_count22_H1 = stillpix_count22_H1 ;
		R_film_stillpix_count22_H2 = stillpix_count22_H2 ;
		R_film_stillpix_count22_H3 = stillpix_count22_H3 ;
		R_film_stillpix_count22_V1 = stillpix_count22_V1 ;
		R_film_stillpix_count22_V2 = stillpix_count22_V2 ;
		R_film_stillpix_count22_V3 = stillpix_count22_V3 ;
		R_film_stillpix_count22_C = stillpix_count22_C ;
		*/

		R_film_index = film_index ;
		R_force_weave_flag = force_weave_flag ;
		R_weave_prev = weave_prev ;
	  }
	  else
	  {
		L_film_StatusFrameStaticPattern    = StatusFrameStaticPattern   ;
		L_film_StatusFrameStaticPattern_H1 = StatusFrameStaticPattern_H1;
		L_film_StatusFrameStaticPattern_H2 = StatusFrameStaticPattern_H2;
		L_film_StatusFrameStaticPattern_H3 = StatusFrameStaticPattern_H3;
		L_film_StatusFrameStaticPattern_V1 = StatusFrameStaticPattern_V1;
		L_film_StatusFrameStaticPattern_V2 = StatusFrameStaticPattern_V2;
		L_film_StatusFrameStaticPattern_V3 = StatusFrameStaticPattern_V3;
		L_film_StatusFrameStaticPattern_C  = StatusFrameStaticPattern_C ;

		L_film_StatusFramePairPattern    = StatusFramePairPattern   ;
		L_film_StatusFramePairPattern_H1 = StatusFramePairPattern_H1;
		L_film_StatusFramePairPattern_H2 = StatusFramePairPattern_H2;
		L_film_StatusFramePairPattern_H3 = StatusFramePairPattern_H3;
		L_film_StatusFramePairPattern_V1 = StatusFramePairPattern_V1;
		L_film_StatusFramePairPattern_V2 = StatusFramePairPattern_V2;
		L_film_StatusFramePairPattern_V3 = StatusFramePairPattern_V3;
		L_film_StatusFramePairPattern_C  = StatusFramePairPattern_C ;

		L_film_StatusPrevStaticPattern2    = StatusPrevStaticPattern2   ;
		L_film_StatusPrevStaticPattern2_H1 = StatusPrevStaticPattern2_H1;
		L_film_StatusPrevStaticPattern2_H2 = StatusPrevStaticPattern2_H2;
		L_film_StatusPrevStaticPattern2_H3 = StatusPrevStaticPattern2_H3;
		L_film_StatusPrevStaticPattern2_V1 = StatusPrevStaticPattern2_V1;
		L_film_StatusPrevStaticPattern2_V2 = StatusPrevStaticPattern2_V2;
		L_film_StatusPrevStaticPattern2_V3 = StatusPrevStaticPattern2_V3;
		L_film_StatusPrevStaticPattern2_C  = StatusPrevStaticPattern2_C ;

		L_film_StatusNextStaticPattern    = StatusNextStaticPattern   ;
		L_film_StatusNextStaticPattern_H1 = StatusNextStaticPattern_H1;
		L_film_StatusNextStaticPattern_H2 = StatusNextStaticPattern_H2;
		L_film_StatusNextStaticPattern_H3 = StatusNextStaticPattern_H3;
		L_film_StatusNextStaticPattern_V1 = StatusNextStaticPattern_V1;
		L_film_StatusNextStaticPattern_V2 = StatusNextStaticPattern_V2;
		L_film_StatusNextStaticPattern_V3 = StatusNextStaticPattern_V3;
		L_film_StatusNextStaticPattern_C  = StatusNextStaticPattern_C ;

		L_film_StatusNextStaticPattern2    = StatusNextStaticPattern2   ;
		L_film_StatusNextStaticPattern2_H1 = StatusNextStaticPattern2_H1;
		L_film_StatusNextStaticPattern2_H2 = StatusNextStaticPattern2_H2;
		L_film_StatusNextStaticPattern2_H3 = StatusNextStaticPattern2_H3;
		L_film_StatusNextStaticPattern2_V1 = StatusNextStaticPattern2_V1;
		L_film_StatusNextStaticPattern2_V2 = StatusNextStaticPattern2_V2;
		L_film_StatusNextStaticPattern2_V3 = StatusNextStaticPattern2_V3;
		L_film_StatusNextStaticPattern2_C  = StatusNextStaticPattern2_C ;

		L_film_Status32Detected1    = Status32Detected1   ;
		L_film_Status32Detected2    = Status32Detected2   ;
		L_film_Status32Detected1_H1 = Status32Detected1_H1;
		L_film_Status32Detected1_H2 = Status32Detected1_H2;
		L_film_Status32Detected1_H3 = Status32Detected1_H3;
		L_film_Status32Detected1_V1 = Status32Detected1_V1;
		L_film_Status32Detected1_V2 = Status32Detected1_V2;
		L_film_Status32Detected1_V3 = Status32Detected1_V3;
		L_film_Status32Detected1_C  = Status32Detected1_C ;
		L_film_Status32Detected2_H1 = Status32Detected2_H1;
		L_film_Status32Detected2_H2 = Status32Detected2_H2;
		L_film_Status32Detected2_H3 = Status32Detected2_H3;
		L_film_Status32Detected2_V1 = Status32Detected2_V1;
		L_film_Status32Detected2_V2 = Status32Detected2_V2;
		L_film_Status32Detected2_V3 = Status32Detected2_V3;
		L_film_Status32Detected2_C  = Status32Detected2_C ;
		L_film_Status22Detected     = Status22Detected    ;
		L_film_Status22Detected_H1  = Status22Detected_H1 ;
		L_film_Status22Detected_H2  = Status22Detected_H2 ;
		L_film_Status22Detected_H3  = Status22Detected_H3 ;
		L_film_Status22Detected_V1  = Status22Detected_V1 ;
		L_film_Status22Detected_V2  = Status22Detected_V2 ;
		L_film_Status22Detected_V3  = Status22Detected_V3 ;
		L_film_Status22Detected_C   = Status22Detected_C  ;

	  	L_film_Status32Sequence1    = Status32Sequence1   ;
	  	L_film_Status32Sequence2    = Status32Sequence2   ;
	  	L_film_Status32Sequence1_H1 = Status32Sequence1_H1;
	  	L_film_Status32Sequence1_H2 = Status32Sequence1_H2;
	  	L_film_Status32Sequence1_H3 = Status32Sequence1_H3;
	  	L_film_Status32Sequence1_V1 = Status32Sequence1_V1;
	  	L_film_Status32Sequence1_V2 = Status32Sequence1_V2;
	  	L_film_Status32Sequence1_V3 = Status32Sequence1_V3;
	  	L_film_Status32Sequence1_C  = Status32Sequence1_C ;
	  	L_film_Status32Sequence2_H1 = Status32Sequence2_H1;
	  	L_film_Status32Sequence2_H2 = Status32Sequence2_H2;
	  	L_film_Status32Sequence2_H3 = Status32Sequence2_H3;
	  	L_film_Status32Sequence2_V1 = Status32Sequence2_V1;
	  	L_film_Status32Sequence2_V2 = Status32Sequence2_V2;
	  	L_film_Status32Sequence2_V3 = Status32Sequence2_V3;
	  	L_film_Status32Sequence2_C  = Status32Sequence2_C ;
	  	L_film_Status22Sequence     = Status22Sequence    ;
	  	L_film_Status22Sequence_H1  = Status22Sequence_H1 ;
	  	L_film_Status22Sequence_H2  = Status22Sequence_H2 ;
	  	L_film_Status22Sequence_H3  = Status22Sequence_H3 ;
	  	L_film_Status22Sequence_V1  = Status22Sequence_V1 ;
	  	L_film_Status22Sequence_V2  = Status22Sequence_V2 ;
	  	L_film_Status22Sequence_V3  = Status22Sequence_V3 ;
	  	L_film_Status22Sequence_C   = Status22Sequence_C  ;

	  	L_film22_StatusNextStaticPattern    = StatusNextStaticPattern_film22   ;
	  	L_film22_StatusNextStaticPattern_H1 = StatusNextStaticPattern_film22_H1;
	  	L_film22_StatusNextStaticPattern_H2 = StatusNextStaticPattern_film22_H2;
	  	L_film22_StatusNextStaticPattern_H3 = StatusNextStaticPattern_film22_H3;
	  	L_film22_StatusNextStaticPattern_V1 = StatusNextStaticPattern_film22_V1;
	  	L_film22_StatusNextStaticPattern_V2 = StatusNextStaticPattern_film22_V2;
	  	L_film22_StatusNextStaticPattern_V3 = StatusNextStaticPattern_film22_V3;
	  	L_film22_StatusNextStaticPattern_C  = StatusNextStaticPattern_film22_C ;

	 	L_Status32Detected1_cnt   =Status32Detected1_cnt   ;
	 	L_Status32Detected1_H1_cnt=Status32Detected1_H1_cnt;
	 	L_Status32Detected1_H2_cnt=Status32Detected1_H2_cnt;
	 	L_Status32Detected1_H3_cnt=Status32Detected1_H3_cnt;
	 	L_Status32Detected1_V1_cnt=Status32Detected1_V1_cnt;
	 	L_Status32Detected1_V2_cnt=Status32Detected1_V2_cnt;
	 	L_Status32Detected1_V3_cnt=Status32Detected1_V3_cnt;
	 	L_Status32Detected1_C_cnt =Status32Detected1_C_cnt ;

	 	L_Status32Detected2_cnt   =Status32Detected2_cnt   ;
	 	L_Status32Detected2_H1_cnt=Status32Detected2_H1_cnt;
	 	L_Status32Detected2_H2_cnt=Status32Detected2_H2_cnt;
	 	L_Status32Detected2_H3_cnt=Status32Detected2_H3_cnt;
	 	L_Status32Detected2_V1_cnt=Status32Detected2_V1_cnt;
	 	L_Status32Detected2_V2_cnt=Status32Detected2_V2_cnt;
	 	L_Status32Detected2_V3_cnt=Status32Detected2_V3_cnt;
	 	L_Status32Detected2_C_cnt =Status32Detected2_C_cnt ;

	 	L_Status22Detected_cnt   =Status22Detected_cnt   ;
	 	L_Status22Detected_H1_cnt=Status22Detected_H1_cnt;
	 	L_Status22Detected_H2_cnt=Status22Detected_H2_cnt;
	 	L_Status22Detected_H3_cnt=Status22Detected_H3_cnt;
	 	L_Status22Detected_V1_cnt=Status22Detected_V1_cnt;
	 	L_Status22Detected_V2_cnt=Status22Detected_V2_cnt;
	 	L_Status22Detected_V3_cnt=Status22Detected_V3_cnt;
	 	L_Status22Detected_C_cnt =Status22Detected_C_cnt ;

		L_film_StatusFilmDetected=StatusFilmDetected	      ;
		L_film_StatusFilmSequence= StatusFilmSequence      ;
		L_StatusMixedFilmDetected= StatusMixedFilmDetected ;
		L_NextTopDetected_d      = NextTopDetected_d                      ;
		L_NextTopDetected        = NextTopDetected                        ;
		L_PrevTopDetected_d      = PrevTopDetected_d                      ;
		L_PrevTopDetected        = PrevTopDetected                        ;
		L_TopLine                = TopLine                                ;
		L_BotLine                = BotLine                                ;
		L_TopLine2               = TopLine2                               ;
		L_BotLine2               = BotLine2                               ;
		L_TopLine3               = TopLine3                               ;
		L_BotLine3               = BotLine3                               ;

		// fw add
		L_film_index32 = index32  ;
		L_film_index32_H1 = index32_H1 ;
		L_film_index32_H2 = index32_H2 ;
		L_film_index32_H3 = index32_H3 ;
		L_film_index32_V1 = index32_V1  ;
		L_film_index32_V2 = index32_V2  ;
		L_film_index32_V3 = index32_V3  ;
		L_film_index32_C = index32_C  ;

		/*
		L_film_stillpix_count32 = stillpix_count32 ;
		L_film_stillpix_count32_H1 = stillpix_count32_H1 ;
		L_film_stillpix_count32_H2 = stillpix_count32_H2 ;
		L_film_stillpix_count32_H3 = stillpix_count32_H3 ;
		L_film_stillpix_count32_V1 = stillpix_count32_V1 ;
		L_film_stillpix_count32_V2 = stillpix_count32_V2 ;
		L_film_stillpix_count32_V3 = stillpix_count32_V3 ;
		L_film_stillpix_count32_C = stillpix_count32_C ;
		*/

		L_film_index322 = index322 ;
		L_film_index322_H1 = index322_H1;
		L_film_index322_H2 = index322_H2;
		L_film_index322_H3 = index322_H3 ;
		L_film_index322_V1 = index322_V1 ;
		L_film_index322_V2 = index322_V2 ;
		L_film_index322_V3 = index322_V3 ;
		L_film_index322_C = index322_C ;

		L_film_index22 = index22 ;
		L_film_index22_H1 = index22_H1 ;
		L_film_index22_H2 = index22_H2 ;
		L_film_index22_H3 = index22_H3  ;
		L_film_index22_V1 = index22_V1  ;
		L_film_index22_V2 = index22_V2  ;
		L_film_index22_V3 = index22_V3  ;
		L_film_index22_C = index22_C ;

		/*
		L_film_stillpix_count22 = stillpix_count22 ;
		L_film_stillpix_count22_H1 = stillpix_count22_H1 ;
		L_film_stillpix_count22_H2 = stillpix_count22_H2 ;
		L_film_stillpix_count22_H3 = stillpix_count22_H3 ;
		L_film_stillpix_count22_V1 = stillpix_count22_V1 ;
		L_film_stillpix_count22_V2 = stillpix_count22_V2 ;
		L_film_stillpix_count22_V3 = stillpix_count22_V3 ;
		L_film_stillpix_count22_C = stillpix_count22_C ;
		*/

		L_film_index = film_index ;
		L_force_weave_flag = force_weave_flag ;
		L_weave_prev = weave_prev ;
	  }
}
#endif

// noise measure fw start
// global parameters
void scalerVIP_rtnr_noise_measure(void)
{
	di_di_rtnr_nm_control_RBUS di_rtnr_nm_control_reg;
	di_di_rtnr_nm_hist1_0_RBUS di_rtnr_nm_hist1_0_reg;
	di_di_rtnr_nm_hist1_1_RBUS di_rtnr_nm_hist1_1_reg;
	di_di_rtnr_nm_hist1_2_RBUS di_rtnr_nm_hist1_2_reg;
	di_di_rtnr_nm_hist1_3_RBUS di_rtnr_nm_hist1_3_reg;
	di_di_rtnr_nm_hist1_4_RBUS di_rtnr_nm_hist1_4_reg;
	di_di_rtnr_nm_hist1_5_RBUS di_rtnr_nm_hist1_5_reg;
	di_di_rtnr_nm_hist1_6_RBUS di_rtnr_nm_hist1_6_reg;
	di_di_rtnr_nm_hist1_7_RBUS di_rtnr_nm_hist1_7_reg;
	di_di_rtnr_nm_hist1_8_RBUS di_rtnr_nm_hist1_8_reg;
	di_di_rtnr_nm_hist1_9_RBUS di_rtnr_nm_hist1_9_reg;
	di_di_rtnr_nm_hist1_10_RBUS di_rtnr_nm_hist1_10_reg;
	di_di_rtnr_nm_hist1_11_RBUS di_rtnr_nm_hist1_11_reg;
	di_di_rtnr_nm_hist1_12_RBUS di_rtnr_nm_hist1_12_reg;
	di_di_rtnr_nm_hist1_13_RBUS di_rtnr_nm_hist1_13_reg;
	di_di_rtnr_nm_hist1_14_RBUS di_rtnr_nm_hist1_14_reg;
	di_di_rtnr_nm_hist1_15_RBUS di_rtnr_nm_hist1_15_reg;

	di_di_rtnr_nm_hist2_0_RBUS di_rtnr_nm_hist2_0_reg;
	di_di_rtnr_nm_hist2_1_RBUS di_rtnr_nm_hist2_1_reg;
	di_di_rtnr_nm_hist2_2_RBUS di_rtnr_nm_hist2_2_reg;
	di_di_rtnr_nm_hist2_3_RBUS di_rtnr_nm_hist2_3_reg;
	di_di_rtnr_nm_hist2_4_RBUS di_rtnr_nm_hist2_4_reg;
	di_di_rtnr_nm_hist2_5_RBUS di_rtnr_nm_hist2_5_reg;
	di_di_rtnr_nm_hist2_6_RBUS di_rtnr_nm_hist2_6_reg;
	di_di_rtnr_nm_hist2_7_RBUS di_rtnr_nm_hist2_7_reg;
	di_di_rtnr_nm_hist2_8_RBUS di_rtnr_nm_hist2_8_reg;
	di_di_rtnr_nm_hist2_9_RBUS di_rtnr_nm_hist2_9_reg;
	di_di_rtnr_nm_hist2_10_RBUS di_rtnr_nm_hist2_10_reg;
	di_di_rtnr_nm_hist2_11_RBUS di_rtnr_nm_hist2_11_reg;
	di_di_rtnr_nm_hist2_12_RBUS di_rtnr_nm_hist2_12_reg;
	di_di_rtnr_nm_hist2_13_RBUS di_rtnr_nm_hist2_13_reg;
	di_di_rtnr_nm_hist2_14_RBUS di_rtnr_nm_hist2_14_reg;
	di_di_rtnr_nm_hist2_15_RBUS di_rtnr_nm_hist2_15_reg;

	di_di_rtnr_nm_hist2var_0_RBUS di_rtnr_nm_hist2var_0_reg;
	di_di_rtnr_nm_hist2var_1_RBUS di_rtnr_nm_hist2var_1_reg;
	di_di_rtnr_nm_hist2var_2_RBUS di_rtnr_nm_hist2var_2_reg;
	di_di_rtnr_nm_hist2var_3_RBUS di_rtnr_nm_hist2var_3_reg;
	di_di_rtnr_nm_hist2var_4_RBUS di_rtnr_nm_hist2var_4_reg;
	di_di_rtnr_nm_hist2var_5_RBUS di_rtnr_nm_hist2var_5_reg;
	di_di_rtnr_nm_hist2var_6_RBUS di_rtnr_nm_hist2var_6_reg;
	di_di_rtnr_nm_hist2var_7_RBUS di_rtnr_nm_hist2var_7_reg;
	di_di_rtnr_nm_hist2var_8_RBUS di_rtnr_nm_hist2var_8_reg;
	di_di_rtnr_nm_hist2var_9_RBUS di_rtnr_nm_hist2var_9_reg;
	di_di_rtnr_nm_hist2var_10_RBUS di_rtnr_nm_hist2var_10_reg;
	di_di_rtnr_nm_hist2var_11_RBUS di_rtnr_nm_hist2var_11_reg;
	di_di_rtnr_nm_hist2var_12_RBUS di_rtnr_nm_hist2var_12_reg;
	di_di_rtnr_nm_hist2var_13_RBUS di_rtnr_nm_hist2var_13_reg;
	di_di_rtnr_nm_hist2var_14_RBUS di_rtnr_nm_hist2var_14_reg;
	di_di_rtnr_nm_hist2var_15_RBUS di_rtnr_nm_hist2var_15_reg;

	di_di_rtnr_nm_infor1_RBUS di_rtnr_nm_infor1_reg;
	di_di_rtnr_nm_infor2_RBUS di_rtnr_nm_infor2_reg;	// var sum

	di_im_di_film_motion_sum_th_RBUS im_di_film_motion_sum_th_reg;	// dummy control
	// parameters

	unsigned int VarSum,Sum;
	unsigned int NoiseLevel = 0xff;	// default value
	unsigned int hist1[16];
	unsigned int hist2[16];
	unsigned int hist2var[16];
	unsigned char ref_Y_en,Yref=128,Ydiff=128;
	unsigned char nm_start = 0;
//	unsigned char NM_control = 1; /* henry @ Mac5 */
	unsigned char detReliable = 0;
	unsigned char smplgBit = 0;
	//float NoiseLevel_tmp = 0;

	di_rtnr_nm_infor1_reg.regValue = rtd_inl(DI_DI_RTNR_NM_INFOR1_reg);
	di_rtnr_nm_infor2_reg.regValue = rtd_inl(DI_DI_RTNR_NM_INFOR2_reg);

	di_rtnr_nm_control_reg.regValue = rtd_inl(DI_DI_RTNR_NM_CONTROL_reg);
	di_rtnr_nm_hist1_0_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST1_0_reg);
	di_rtnr_nm_hist1_1_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST1_1_reg);
	di_rtnr_nm_hist1_2_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST1_2_reg);
	di_rtnr_nm_hist1_3_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST1_3_reg);
	di_rtnr_nm_hist1_4_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST1_4_reg);
	di_rtnr_nm_hist1_5_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST1_5_reg);
	di_rtnr_nm_hist1_6_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST1_6_reg);
	di_rtnr_nm_hist1_7_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST1_7_reg);
	di_rtnr_nm_hist1_8_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST1_8_reg);
	di_rtnr_nm_hist1_9_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST1_9_reg);
	di_rtnr_nm_hist1_10_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST1_10_reg);
	di_rtnr_nm_hist1_11_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST1_11_reg);
	di_rtnr_nm_hist1_12_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST1_12_reg);
	di_rtnr_nm_hist1_13_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST1_13_reg);
	di_rtnr_nm_hist1_14_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST1_14_reg);
	di_rtnr_nm_hist1_15_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST1_15_reg);

	di_rtnr_nm_hist2_0_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST2_0_reg);
	di_rtnr_nm_hist2_1_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST2_1_reg);
	di_rtnr_nm_hist2_2_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST2_2_reg);
	di_rtnr_nm_hist2_3_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST2_3_reg);
	di_rtnr_nm_hist2_4_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST2_4_reg);
	di_rtnr_nm_hist2_5_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST2_5_reg);
	di_rtnr_nm_hist2_6_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST2_6_reg);
	di_rtnr_nm_hist2_7_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST2_7_reg);
	di_rtnr_nm_hist2_8_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST2_8_reg);
	di_rtnr_nm_hist2_9_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST2_9_reg);
	di_rtnr_nm_hist2_10_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST2_10_reg);
	di_rtnr_nm_hist2_11_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST2_11_reg);
	di_rtnr_nm_hist2_12_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST2_12_reg);
	di_rtnr_nm_hist2_13_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST2_13_reg);
	di_rtnr_nm_hist2_14_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST2_14_reg);
	di_rtnr_nm_hist2_15_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST2_15_reg);

	di_rtnr_nm_hist2var_0_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST2VAR_0_reg);
	di_rtnr_nm_hist2var_1_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST2VAR_1_reg);
	di_rtnr_nm_hist2var_2_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST2VAR_2_reg);
	di_rtnr_nm_hist2var_3_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST2VAR_3_reg);
	di_rtnr_nm_hist2var_4_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST2VAR_4_reg);
	di_rtnr_nm_hist2var_5_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST2VAR_5_reg);
	di_rtnr_nm_hist2var_6_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST2VAR_6_reg);
	di_rtnr_nm_hist2var_7_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST2VAR_7_reg);
	di_rtnr_nm_hist2var_8_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST2VAR_8_reg);
	di_rtnr_nm_hist2var_9_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST2VAR_9_reg);
	di_rtnr_nm_hist2var_10_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST2VAR_10_reg);
	di_rtnr_nm_hist2var_11_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST2VAR_11_reg);
	di_rtnr_nm_hist2var_12_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST2VAR_12_reg);
	di_rtnr_nm_hist2var_13_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST2VAR_13_reg);
	di_rtnr_nm_hist2var_14_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST2VAR_14_reg);
	di_rtnr_nm_hist2var_15_reg.regValue = rtd_inl(DI_DI_RTNR_NM_HIST2VAR_15_reg);
	im_di_film_motion_sum_th_reg.regValue = rtd_inl(DI_IM_DI_FILM_MOTION_SUM_TH_reg);

	Sum = di_rtnr_nm_infor1_reg.nm_sumvarnum;
	VarSum = di_rtnr_nm_infor2_reg.nm_sumvar;

	ref_Y_en = di_rtnr_nm_control_reg.nm_ref_y_en;
	Yref = di_rtnr_nm_control_reg.nm_fw_yref;
	Ydiff = di_rtnr_nm_control_reg.nm_fw_ydiff;
	nm_start = di_rtnr_nm_control_reg.nm_start;
	smplgBit = di_rtnr_nm_control_reg.nm_samplingbit;
//	NM_control = im_di_film_motion_sum_th_reg.nm_main_enable; /* henry @ Mac5 */

	if(nm_start == 0 /*&& NM_control*/)
	{
		hist1[0] = di_rtnr_nm_hist1_0_reg.hist1_0;
		hist1[1] = di_rtnr_nm_hist1_1_reg.hist1_1;
		hist1[2] = di_rtnr_nm_hist1_2_reg.hist1_2;
		hist1[3] = di_rtnr_nm_hist1_3_reg.hist1_3;
		hist1[4] = di_rtnr_nm_hist1_4_reg.hist1_4;
		hist1[5] = di_rtnr_nm_hist1_5_reg.hist1_5;
		hist1[6] = di_rtnr_nm_hist1_6_reg.hist1_6;
		hist1[7] = di_rtnr_nm_hist1_7_reg.hist1_7;
		hist1[8] = di_rtnr_nm_hist1_8_reg.hist1_8;
		hist1[9] = di_rtnr_nm_hist1_9_reg.hist1_9;
		hist1[10] = di_rtnr_nm_hist1_10_reg.hist1_10;
		hist1[11] = di_rtnr_nm_hist1_11_reg.hist1_11;
		hist1[12] = di_rtnr_nm_hist1_12_reg.hist1_12;
		hist1[13] = di_rtnr_nm_hist1_13_reg.hist1_13;
		hist1[14] = di_rtnr_nm_hist1_14_reg.hist1_14;
		hist1[15] = di_rtnr_nm_hist1_15_reg.hist1_15;

		hist2[0] = di_rtnr_nm_hist2_0_reg.hist2_0;
		hist2[1] = di_rtnr_nm_hist2_1_reg.hist2_1;
		hist2[2] = di_rtnr_nm_hist2_2_reg.hist2_2;
		hist2[3] = di_rtnr_nm_hist2_3_reg.hist2_3;
		hist2[4] = di_rtnr_nm_hist2_4_reg.hist2_4;
		hist2[5] = di_rtnr_nm_hist2_5_reg.hist2_5;
		hist2[6] = di_rtnr_nm_hist2_6_reg.hist2_6;
		hist2[7] = di_rtnr_nm_hist2_7_reg.hist2_7;
		hist2[8] = di_rtnr_nm_hist2_8_reg.hist2_8;
		hist2[9] = di_rtnr_nm_hist2_9_reg.hist2_9;
		hist2[10] = di_rtnr_nm_hist2_10_reg.hist2_10;
		hist2[11] = di_rtnr_nm_hist2_11_reg.hist2_11;
		hist2[12] = di_rtnr_nm_hist2_12_reg.hist2_12;
		hist2[13] = di_rtnr_nm_hist2_13_reg.hist2_13;
		hist2[14] = di_rtnr_nm_hist2_14_reg.hist2_14;
		hist2[15] = di_rtnr_nm_hist2_15_reg.hist2_15;

		hist2var[0] = di_rtnr_nm_hist2var_0_reg.hist2var_0;
		hist2var[1] = di_rtnr_nm_hist2var_1_reg.hist2var_1;
		hist2var[2] = di_rtnr_nm_hist2var_2_reg.hist2var_2;
		hist2var[3] = di_rtnr_nm_hist2var_3_reg.hist2var_3;
		hist2var[4] = di_rtnr_nm_hist2var_4_reg.hist2var_4;
		hist2var[5] = di_rtnr_nm_hist2var_5_reg.hist2var_5;
		hist2var[6] = di_rtnr_nm_hist2var_6_reg.hist2var_6;
		hist2var[7] = di_rtnr_nm_hist2var_7_reg.hist2var_7;
		hist2var[8] = di_rtnr_nm_hist2var_8_reg.hist2var_8;
		hist2var[9] = di_rtnr_nm_hist2var_9_reg.hist2var_9;
		hist2var[10] = di_rtnr_nm_hist2var_10_reg.hist2var_10;
		hist2var[11] = di_rtnr_nm_hist2var_11_reg.hist2var_11;
		hist2var[12] = di_rtnr_nm_hist2var_12_reg.hist2var_12;
		hist2var[13] = di_rtnr_nm_hist2var_13_reg.hist2var_13;
		hist2var[14] = di_rtnr_nm_hist2var_14_reg.hist2var_14;
		hist2var[15] = di_rtnr_nm_hist2var_15_reg.hist2var_15;

		#if 0
		unsigned char k;
		unsigned char vc_rtnr_NM_MaxBinRatio=16;	//if(Hist2[k]!=0 && Hist2[k]>=(maxbin2*reg_vc_rtnr_NM_MaxBinRatio)>>5)
		unsigned char vc_rtnr_NM_BinRatio =16; //if(((sumbin*reg_vc_rtnr_NM_BinRatio)>>3) > maxbin1) // leave criterion
		unsigned char vc_rtnr_NM_VarRatio=32;  // if(((min2_temp*reg_vc_rtnr_NM_VarRatio)>>5)>min_temp)
		unsigned char vc_rtnr_NM_FW_Yref=Yref,vc_rtnr_NM_FW_Ydiff=Ydiff;
		unsigned char index=0;
		unsigned int min_temp=0xffff;
		unsigned int min2_temp=0xffff;
		unsigned int maxbin2=0,maxbin1=0,sumbin=0;
		unsigned char shiftbit = 4;
		if(ref_Y_en)
		{
			for(k=0;k<16;k++)
			{
				sumbin += hist2[k];
				maxbin2 = (maxbin2>hist2[k])? maxbin2:hist2[k];//  max(maxbin2,hist2[k]);
				maxbin1 = (maxbin1>hist1[k])? maxbin1:hist1[k];// max(maxbin1,hist1[k]);
			}
			switch (Ydiff)
			{
				case 128:
					shiftbit = 4;
					break;
				case 64:
					shiftbit = 3;
					break;
				case 32:
					shiftbit = 2;
					break;
				case 16:
					shiftbit = 1;
					break;
				case 8:
					shiftbit = 0;
					break;
				default:
					shiftbit = 4;
					break;
			}

			//sumbin = sumbin>>(*shiftbit-1);
			for(k=0;k<16;k++)
			{
				if(hist2[k]!=0 && hist2[k]>=(maxbin2*vc_rtnr_NM_MaxBinRatio)>>5)
				{
					if((hist2var[k]/hist2[k]) <= min2_temp)
					{
						if((hist2var[k]/hist2[k]) <= min_temp)
						{
							min2_temp = min_temp;
							min_temp = hist2var[k]/hist2[k];
							index = k;
						}
						else
						{
							min2_temp = hist2var[k]/hist2[k];
						}
					}
				}
			}

			if(((sumbin*vc_rtnr_NM_BinRatio)>>3) > maxbin1) // leave criterion
			{
				if(((min2_temp*vc_rtnr_NM_VarRatio)>>5)>=min_temp)
				{
					if(shiftbit>=1)
					{
						vc_rtnr_NM_FW_Yref = vc_rtnr_NM_FW_Yref - vc_rtnr_NM_FW_Ydiff+ index*(1<<(shiftbit));
						vc_rtnr_NM_FW_Ydiff = vc_rtnr_NM_FW_Ydiff>>1;
					}
				}
			}
			else
			{
				vc_rtnr_NM_FW_Yref = 128;
				vc_rtnr_NM_FW_Ydiff = 128;
			}
			if(vc_rtnr_NM_FW_Yref - vc_rtnr_NM_FW_Ydiff <=0)
				vc_rtnr_NM_FW_Yref = vc_rtnr_NM_FW_Ydiff;
			else if(vc_rtnr_NM_FW_Yref + vc_rtnr_NM_FW_Ydiff>=255)
				vc_rtnr_NM_FW_Yref = 256 - vc_rtnr_NM_FW_Ydiff;

			// write back
			di_rtnr_nm_control_reg.nm_fw_yref = vc_rtnr_NM_FW_Yref;
			di_rtnr_nm_control_reg.nm_fw_ydiff = vc_rtnr_NM_FW_Ydiff;
		}
		#endif

		// detection reliable ->    0        1        2         3
		//						25% - 50% - 75%

		if(Sum>(((Smart_Integration_Status.DI_WIDTH*Smart_Integration_Status.DI_HEIGHT*5)>>3)/(13+smplgBit)))
			detReliable = 3;
		else if(Sum>(((Smart_Integration_Status.DI_WIDTH*Smart_Integration_Status.DI_HEIGHT*3)>>3)/(13+smplgBit)))
			detReliable = 2;
		else if(Sum>(((Smart_Integration_Status.DI_WIDTH*Smart_Integration_Status.DI_HEIGHT*1)>>3)/(13+smplgBit)))
			detReliable = 1;
		else
			detReliable = 0;

		//int tmp = (VarSum*4 / (Sum+1)) - 4;//NoiseLevel=uint32, always >0, but NoiseLevel is not>15, so...
		int tmp = VarSum / (Sum+1); // jimmy.lin 20140627: return to simple average, raise precision by adjusting thresholds
		if(tmp>15)
			NoiseLevel = 15;
		else if(tmp<0)
			NoiseLevel = 0;
		else
			NoiseLevel = tmp;

		//di_rtnr_nm_infor1_reg.nm_noiselevel = NoiseLevel;
		di_rtnr_nm_control_reg.nm_start = 1;

		Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_SPATIAL_NOISE.TMP_NOISE_LEVEL_CUR = (unsigned char)NoiseLevel;
		Smart_Integration_Status.SCREEN_NOISE_STATUS.CONTENT_SPATIAL_NOISE.TMP_NOISE_LEVEL_RELIABLE_CUR = detReliable;

		//////////////////////////////////// APPLY ////////////////////////////////////
		//scaler_rtd_outl(DI_DI_RTNR_NM_INFOR1_reg, di_rtnr_nm_infor1_reg.regValue);
		scaler_rtd_outl(DI_DI_RTNR_NM_CONTROL_reg, di_rtnr_nm_control_reg.regValue);
	}
	else // turn on NM_control
	{
//		im_di_film_motion_sum_th_reg.nm_main_enable = 1; /* henry @ Mac5*/
		rtd_outl(DI_IM_DI_FILM_MOTION_SUM_TH_reg, im_di_film_motion_sum_th_reg.regValue);
	}
}
// noise measure fw end

void scalerVIP_DI_MCNR_RTNR_bottom_fresh_line_patch(unsigned char enable)
{
	di_im_di_weave_window_control_RBUS im_di_weave_window_control_reg;
	di_im_di_weave_window_5_start_RBUS im_di_weave_window_5_start_reg;
	di_im_di_weave_window_5_end_RBUS im_di_weave_window_5_end_reg;

	unsigned char motionl_level = scalerVIP_DI_MiddleWare_GetStatus(STATUS_MOTION);
	static unsigned int pre_w = 0, pre_h = 0;
	static unsigned int s_count = 0;

	im_di_weave_window_control_reg.regValue = rtd_inl(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg);

	if (Smart_Integration_Status.DI_WIDTH != pre_w || Smart_Integration_Status.DI_HEIGHT != pre_h)
		s_count = 0;
	s_count++;

	pre_w = Smart_Integration_Status.DI_WIDTH;
	pre_h = Smart_Integration_Status.DI_HEIGHT;

	if (enable && Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_INTERLACE) && (SmartPic_clue->RTNR_MAD_count_Y_avg_ratio > 950|| motionl_level<=2)&& s_count > 5) {
		im_di_weave_window_control_reg.fixedwindow5 = 1;
		im_di_weave_window_5_start_reg.xstart_77_65 = 1;
		im_di_weave_window_5_start_reg.ystart_77_65 = Smart_Integration_Status.DI_HEIGHT;

		im_di_weave_window_5_end_reg.xend_77_65 = Smart_Integration_Status.DI_WIDTH;
		im_di_weave_window_5_end_reg.yend_77_65 = Smart_Integration_Status.DI_HEIGHT;

		rtd_outl(DI_IM_DI_WEAVE_WINDOW_5_START_reg, im_di_weave_window_5_start_reg.regValue);
		rtd_outl(DI_IM_DI_WEAVE_WINDOW_5_END_reg, im_di_weave_window_5_end_reg.regValue);
		s_count = 100;
	} else {
		im_di_weave_window_control_reg.fixedwindow5 = 0;
	}

	rtd_outl(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg, im_di_weave_window_control_reg.regValue);

}

void scalerVIP_Get_DI_Width_Height(unsigned short *pWidth, unsigned short *pHeight)
{
	*pWidth = Smart_Integration_Status.DI_WIDTH;
	*pHeight = Smart_Integration_Status.DI_HEIGHT;
}

void scalerDI_Set_DI_SMD(unsigned char DI_SMD_enable)
{
	di_di_smd_control_candidatelist_RBUS di_smd_control_candiate_reg;
	di_smd_control_candiate_reg.regValue = rtd_inl(DI_DI_SMD_Control_CandidateList_reg);
	di_smd_control_candiate_reg.smd_en = DI_SMD_enable;
	rtd_outl(DI_DI_SMD_Control_CandidateList_reg, di_smd_control_candiate_reg.regValue);
}

FILM_FW_ShareMem_ISR *g_Share_Memory_FILM_FW_isr = NULL;
void scalerVIP_Set_FW_FILM_Share_Memory(unsigned long arg)
{
	g_Share_Memory_FILM_FW_isr = ((FILM_FW_ShareMem_ISR *)arg);
}

unsigned char scalerVIP_Get_film_enable_ap_status(void)
{
	if (g_Share_Memory_FILM_FW_isr == NULL)
		return 0;

	return g_Share_Memory_FILM_FW_isr->film_en_ap_status;
}
