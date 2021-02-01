/***************************************************************************
                          scalerDI.h  -  description
                             -------------------
    begin                : Wed Dec 11 2013
    copyright           : (C) 2013 by LearnRPG
    email                : learnrpg@realtek.com
    history              : Original from auto_ma, then scalerVIP, finally scalerDI
 ***************************************************************************/

#ifndef __SCALERDI_H__
#define __SCALERDI_H__

//#include "rtd_types.h"
#include "vgip_isr/scalerVIP.h"

#ifdef CONFIG_3D_DEBUG // print scaler's debug messages in linux kernel space, open it by make menuconfig
	#define VDCPrint printk
#else
	#define VDCPrint(format,args...)
#endif

/*
	SMART INTEGRATION STATUS (SIS) by LearnRPG@20140225

	Collection and combination all those status by long time experience.
	We suggest in kernal API don't have below code
	(that's mean kernal API must independent operation)
	1. no global variable, must use function parameter be input.
	2. don't change global status in function, must use middle layer to update status.
*/

typedef struct _ScreenNormalStatus
{
	unsigned char DARK_LEVEL;
} ScreenNormalStatus;

typedef enum _SIS_STATUS{
	STATUS_MOTION, //0~48, 0:condition error 1:no motion very still, 48: very motion
	STATUS_HMC, // 0:no hmc, 1: hmc
	STATUS_HMC_HIST, // 0: old, 1: newn
	STATUS_PAN, // 0:no pan, 1: pan				for hmcnr
	STATUS_PAN_STR, // 0:no pan, 1: pan		for pan compensation
	STATUS_PAN_LEVEL, // 0~32 mv, 16=mv zero, return rank 1 mv
	STATUS_VPAN, // 0: no vpan, 1: vpan up, 2: vpan down
	STATUS_SPAN, // 0: no span, 1: right-up pan, 2: right-down pan, 3: left-up pan, 4: left-down pan
	STATUS_HMCNR, // 0: not hmcnr, hmcnr
	STATUS_ZOOMMOTION, // 0: no zoom, 1: zoom out, 2: zoom in
	STATUS_SLOWMOTION, // 0: no slowmotion, 1: slowmotion
	STATUS_SCENECHANGE, // 0: no scene change, 1: scene change (delay 2 field)
	STATUS_FADING, // 0: no fading, 1: fade
	STATUS_HIGHFREQUENCY, // 0: no hf, 1: hf (level>400)
	STATUS_HIGHFREQUENCY_LEVEL, // 0~1000 score, 0: low hf, 1000: max hf
	STATUS_FILM, // 0: no film, 1: film
	STATUS_BLACKWHITE,
	STATUS_SATURATION,
	STATUS_NOISE,
	STATUS_CONTENT_SPATIAL_NOISE_LEVEL, // 0~15, 0: no noise, 15: max noise
	STATUS_CONTENT_SPATIAL_NOISE_LEVEL_RELIABLE, // 0: not reliable, 1: reliable
	STATUS_CONTENT_TEMPORAL_NOISE_LEVEL, // 0~15, 0: no noise, 15: max noise
	STATUS_CONTENT_TEMPORAL_NOISE_RELIABLE, // 0: not reliable, 1: reliable
	STATUS_STILL_CONCENTRIC_CIRCLES, // 0: no scc, 1: scc
	STATUS_CUSTOMER_HMC_VMC, // 0: not this pattern, 1: yes
	STATUS_MOVING_CAN, // 0: not this patten, 1:yes (from VD extern variable)
	STATUS_SMD,
	STATUS_PAN_SPECIAL_CASE,
}SIS_STATUS;

typedef struct _ScreenActionStatus
{
	unsigned char HMC_detect;
	unsigned char PAN_detect;
	unsigned char PAN_detect_str;
	unsigned char VPAN_detect;
	unsigned char SPAN_detect;
	unsigned char HMCNR_detect;
	unsigned char ZOOMMOTION_detect;
	unsigned char SLOWMOTION_detect;
	unsigned char SCENECHANGE_detect;
	unsigned char FADING_detect;
	unsigned char HIGHFREQUENCY_detect;
	unsigned char FILM_detect;
	unsigned char BLACKWHITE_detect;
	unsigned char SATURATION_detect;
} ScreenActionStatus;

#define MOTION_COUNT 10
#define MOTION_SCALE 1000
typedef struct _ScreenMotionStatus
{
	unsigned int Total_FM_SUM_Sequence[MOTION_COUNT];
	unsigned int Large_FM_PXL_Sequence[MOTION_COUNT];
	unsigned int Large_FM_SUM_Sequence[MOTION_COUNT];
	unsigned short Large_FM_PXL; // 0~1000
	unsigned short Large_FM_SUM_ENERGY; // 0~1000
	unsigned short Small_FM_PXL; // 0~1000
	unsigned short Zero_FM_PXL; // 0~1000
	unsigned short MOTION_LEVEL_Sequence[MOTION_COUNT];
	unsigned short MOTION_LEVEL;
	unsigned char Show_Debug_MSG;
}ScreenMotionStatus;

#define SPATIAL_NOISELEVEL_CNT 10
#define SPATIAL_NOISELEVEL_RELIABLE_CNT 10
typedef struct _ScreenNoiseStatus_Spatial
{
	unsigned char TMP_NOISE_LEVEL_RELIABLE[SPATIAL_NOISELEVEL_RELIABLE_CNT];
	unsigned char TMP_NOISE_LEVEL[SPATIAL_NOISELEVEL_CNT];
	unsigned char TMP_NOISE_LEVEL_RELIABLE_CUR;
	unsigned char TMP_NOISE_LEVEL_CUR;
	unsigned char RESULT_NOISE_LEVEL_RELIABLE;
	unsigned char RESULT_NOISE_LEVEL;
	unsigned char  Show_Debug_MSG;
} ScreenNoiseStatus_Spatial;

#define TEMPORAL_NOISELEVEL_COUNT 10
typedef struct _ScreenNoiseStatus_Temporal
{
	unsigned short Result_Sequence_Reliable[TEMPORAL_NOISELEVEL_COUNT];
	unsigned short Result_Sequence[TEMPORAL_NOISELEVEL_COUNT];
	unsigned char RESULT_NOISE_RELIABLE;
	unsigned char RESULT_NOISE_LEVEL;
	unsigned char Show_Debug_MSG;
}ScreenNoiseStatus_Temporal;

typedef struct _ScreenNoiseStatus
{
	ScreenNoiseStatus_Spatial CONTENT_SPATIAL_NOISE;
	ScreenNoiseStatus_Temporal CONTENT_TEMPORAL_NOISE;
	unsigned char VD_SIGNAL_NOISE_LEVEL;
} ScreenNoiseStatus;

#define HMC_BIN_COUNT 33
#define HMC_PASS_COUNT 120
typedef struct _ScreenHMCStatus
{
	unsigned short BIN_Histogram[HMC_BIN_COUNT]; // center at 17,
	unsigned char BIN_Histogram_flag;
	unsigned char BIN_Histogram_flag_pre;
	unsigned char BIN_Rank[HMC_BIN_COUNT];
	unsigned char Pass_Result_Sequence[HMC_PASS_COUNT];
	unsigned char Pass_Result_Total;
	int Pre3_Top5_Total;
	int Pre2_Top5_Total;
	int Pre_Top5_Total;
	int Cur_Top5_Total;
	unsigned char  Show_Debug_MSG;
} ScreenHMCStatus;

#define HPAN_PASS_COUNT 120
typedef struct _ScreenHPANStatus
{
	unsigned char Pass_Result_Sequence[HPAN_PASS_COUNT];
	unsigned char Mv_Result_Sequence[HPAN_PASS_COUNT];
	unsigned char Pan_mv;
	unsigned char Pan_det;
	unsigned char Pan_det_str;
	unsigned char  Show_Debug_MSG;
	unsigned char Pen_special_case;
}ScreenHPANStatus;

#define VPAN_PASS_COUNT 30
typedef struct _ScreenVPANStatus
{
	unsigned char Pass_Result_Sequence[VPAN_PASS_COUNT];
	unsigned char Pass_Result_Total_VPanUp;
	unsigned char Pass_Result_Total_VPanDown;
}ScreenVPANStatus;

#define SPAN_PASS_COUNT 30
typedef struct _ScreenSPANStatus
{
	unsigned char Pass_Result_Sequence[SPAN_PASS_COUNT];
	unsigned char Pass_Result_Total_SPanRU;
	unsigned char Pass_Result_Total_SPanRD;
	unsigned char Pass_Result_Total_SPanLU;
	unsigned char Pass_Result_Total_SPanLD;
	unsigned char Show_Debug_MSG;
}ScreenSPANStatus;

typedef struct _ScreenHMCNRStatus
{
	unsigned char Show_Debug_MSG;
}ScreenHMCNRStatus;

#define ZOOMMOTION_PASS_COUNT 30
typedef struct _ScreenZOOMMOTIONStatus
{
	unsigned char Pass_Result_Sequence[ZOOMMOTION_PASS_COUNT];
	unsigned char Pass_Result_Total_ZoomIn;
	unsigned char Pass_Result_Total_ZoomOut;
}ScreenZOOMMOTIONStatus;

#define SLOWMOTION_PASS_COUNT 15
typedef struct _ScreenSLOWMOTIONStatus
{
	unsigned char Pass_Result_Sequence[SLOWMOTION_PASS_COUNT];
	unsigned char Pass_Result_Total_Slow;
	unsigned char Show_Debug_MSG;
}ScreenSLOWMOTIONStatus;

#define SCENECHANGE_COUNT 10
typedef struct _ScreenSCENECHANGEStatus
{
	unsigned int Result_Sequence[SCENECHANGE_COUNT];
	unsigned char pass_ratio;
	unsigned char pass_couter;
	unsigned char  Show_Debug_MSG;
}ScreenSCENECHANGEStatus;

#define FADING_PASS_COUNT 60
typedef struct _ScreenFADINGStatus
{
	unsigned int Result_Sequence[FADING_PASS_COUNT];
	unsigned char Pass_Result_Total_FadeIn;
	unsigned char Pass_Result_Total_FadeOut;
}ScreenFADINGStatus;

#define HIGHFREQUENCY_PASS_COUNT 30
#define HIGHFREQUENCY_SCALE 1000
typedef struct _ScreenHIGHFREQUENCYStatus
{
	unsigned short Pass_Result_Sequence[HIGHFREQUENCY_PASS_COUNT];
	unsigned short Pass_Result_FIR;
}ScreenHIGHFREQUENCYStatus;

typedef struct _ScreenSpecialStatus
{
	unsigned char STILL_CONCENTRIC_CIRCLES_detect;
	unsigned char CUSTOMER_HMC_VMC_detect;
	unsigned char MOVING_CAN_detect;
} ScreenSpecialStatus;

#define SMD_PASS_COUNT 15
typedef struct _ScreenSMDStatus
{
	unsigned int Result_Sequence[SMD_PASS_COUNT];
	unsigned char  Show_Debug_MSG;
}ScreenSMDStatus;

#define HISTOGRAM_SIZE 32
#define PROFILE_SIZE 16
typedef struct _ScalerDIGlobalStatus
{
	unsigned short DI_WIDTH;
	unsigned short DI_HEIGHT;
	unsigned char   Mode_3A;
	unsigned char   Mode_Progressive;
	VIP_SOURCE_TIMING Vip_Source_Timing;
	unsigned char   Y_10_BITS;
	unsigned char   C_10_BITS;
	unsigned char   DMA_MODE;
	unsigned char   BTR_EN;
	unsigned char   SMD_EN;
	unsigned char   RTNR_MORE_K_EN;
	unsigned int Y_Histogram[HISTOGRAM_SIZE];
	unsigned short Y_H_Block[PROFILE_SIZE];
	unsigned short Y_V_Block[PROFILE_SIZE];
	ScreenNormalStatus SCREEN_NORMAL_STATUS;
	ScreenActionStatus SCREEN_ACTION_STATUS;
	ScreenMotionStatus SCREEN_MOTION_STATUS;
	ScreenNoiseStatus SCREEN_NOISE_STATUS;
	ScreenHMCStatus SCREEN_HMC_STATUS;
	ScreenHPANStatus SCREEN_HPAN_STATUS;
	ScreenVPANStatus SCREEN_VPAN_STATUS;
	ScreenSPANStatus SCREEN_SPAN_STATUS;
	ScreenHMCNRStatus SCREEN_HMCNR_STATUS;
	ScreenZOOMMOTIONStatus SCREEN_ZOOMMOTION_STATUS;
	ScreenSLOWMOTIONStatus SCREEN_SLOWMOTION_STATUS;
	ScreenSCENECHANGEStatus SCREEN_SCENECHANGE_STATUS;
	ScreenFADINGStatus SCREEN_FADING_STATUS;
	ScreenHIGHFREQUENCYStatus SCREEN_HIGHFREQUENCY_STATUS;
	ScreenSpecialStatus SCREEN_SPECIAL_STATUS;
	ScreenSMDStatus SCREEN_SMD_STATUS;
	unsigned int Frame_Couter;
} ScalerDIGlobalStatus;

typedef struct _FILM_FWMode
{
	unsigned char fw_StatusFilmSequence;
	unsigned char fw_Status32Detected1;
	unsigned char fw_Status32Detected2;
	unsigned char fw_Status22Detected;
	unsigned char Fw_StatusFilmWeaveMode;
	unsigned char Fw_MixedFilmConfuse;
	unsigned char Fw_StatusMixedFilmDetected;
	unsigned char Fw_StatusFilmDetected;
	unsigned int Fw_TopLine1;
	unsigned int Fw_BotLine1;
	unsigned int Fw_TopLine2;
	unsigned int Fw_BotLine2;
	unsigned int Fw_TopLine3;
	unsigned int Fw_BotLine3;

}FILM_FWMode;

typedef struct _FILM_FW_ShareMem_ISR
{
	unsigned char version;
	unsigned char flag_Trigger;
	unsigned char st_DI_STATUS_VPAN;
	unsigned char smooth_toggle_film;
	unsigned char film_en_ap_status;
	unsigned char reserved5;
	unsigned char reserved6;
	unsigned char reserved7;
} FILM_FW_ShareMem_ISR;

#define _TV_NTSC	0
#define _TV_PAL		1
#define _AV_NTSC	2
#define _AV_PAL		3
#define _Table_total	4

void scalerVIP_DI_MiddleWare_StatusInit(VIP_SOURCE_TIMING cur_vip_source);
void scalerVIP_DI_MiddleWare_HistUpdate(unsigned int *HistCnt);
void scalerVIP_DI_MiddleWare_ProfileUpdate(unsigned short h_block[16], unsigned short v_block[16]);
void scalerVIP_DI_MiddleWare_StatusUpdate(void);
unsigned int scalerVIP_DI_MiddleWare_GetStatus(SIS_STATUS access);
void scalerVIP_DI_MiddleWare_SetStatus(SIS_STATUS access, unsigned char status);
void scalerVIP_DI_MiddleWare_DebugMode(SIS_STATUS access, unsigned char timer);
void scalerVIP_DI_MiddleWare_HMC_Apply(void);
void scalerVIP_DI_MiddleWare_PAN_Apply(void);
void scalerVIP_DI_MiddleWare_HMCNR_Apply(unsigned char weight);
void scalerVIP_DI_MiddleWare_MCNR_Ctrl(unsigned char weight);
void scalerVIP_DI_MiddleWare_MCNR_Ctrl2(unsigned char weight);
void scalerVIP_DI_MiddleWare_MCNR_Set_GMV_Ratio(int GMV_xy_ratio);

unsigned char scalerVIP_DI_MiddleWare_MCNR_Get_GMV_Ratio(void);

unsigned char scalerVIP_DI_MiddleWare_MCNR_Get_Pan_Flag(void);
void scalerVIP_DI_MiddleWare_MCNR_Set_Pan_Flag(unsigned char pan_flag);
unsigned char scalerVIP_DI_MiddleWare_MCNR_Get_V_Pan_Flag(void);
void scalerVIP_DI_MiddleWare_MCNR_Set_V_Pan_Flag(unsigned char pan_flag);

void scalerVIP_DI_MiddleWare_FILM_Apply(void);
void scalerVIP_DI_MiddleWare_ZOOMMOTION_Apply(unsigned char offset);
void scalerVIP_DI_MiddleWare_SLOWMOTION_Apply(unsigned char offset);
void scalerVIP_DI_MiddleWare_FADING_Apply(unsigned char offset);
void scalerVIP_DI_MiddleWare_SPECIAL_Apply(unsigned char source_timing_index);
void scalerVIP_DI_MiddleWare_SMD_Apply(void);

unsigned char scalerVIP_DI_HMC_Continue(void);
unsigned char scalerVIP_DI_HMC_Rank_Check(unsigned char fromRank, unsigned char inRank, unsigned char fixRank, unsigned char vsync_time);
unsigned char scalerVIP_DI_HMC_LR_Check(void);
void scalerVIP_DI_MOTION_StatusUpdate(void);
void scalerVIP_DI_HMC_StatusUpdate(void);
void scalerVIP_DI_PAN_HistSwitch(void);
void scalerVIP_DI_PAN_StatusUpdate(void);
void scalerVIP_DI_VPAN_StatusUpdate(void);
void scalerVIP_DI_SPAN_StatusUpdate(void);
void scalerVIP_DI_ZOOMMOTION_StatusUpdate(void);
void scalerVIP_DI_SLOWMOTION_StatusUpdate(void);
void scalerVIP_DI_SCENECHANGE_StatusUpdate(void);
void scalerVIP_DI_FADING_StatusUpdate(void);
void scalerVIP_DI_HIGHFREQUENCY_StatusUpdate(void);
void scalerVIP_NOISE_LEVEL_StatusUpdate(void);
void scalerVIP_SPATIAL_NOISE_LEVEL_StatusUpdate(void);
void scalerVIP_DI_TEMPORAL_NOISE_LEVEL_StatusUpdate(void);
void scalerVIP_DI_FILM_StatusUpdate(void);
void scalerVIP_DI_SMD_StautsUpdate(void);

void scalerVIP_colorMAQuickSetTh(unsigned char Level);
void scalerVIP_colorMABeanDrop(unsigned char mode, unsigned int en_test);
int scalerVIP_colorMABeerProblem(unsigned int en_test);
int drvif_color_Zoom(void);
void scaleVIP_color_tnrxc(unsigned char display, unsigned char Level);
void scalerVIP_DI_Dynamic_VDNoise_FrameMotion(void);
void scalerVIP_DI_Dynamic_Status_Adjust_by_Global_Motion(MOTION_LEVEL motion_level_flag);

static void scalerVIP_film_FWmode(void);
static FILM_FWMode DETECTION_scalerVIP_film_FWmode(void);
void APPLY_scalerVIP_film_FWmode_isr(FILM_FWMode DetInformation);
void	scalerVIP_film_FWmode_detection1_isr(unsigned int FrameStaticPattern,unsigned int FramePairPattern,
		unsigned int PrevStaticPattern, unsigned int NextStaticPattern, unsigned char Strict,
		unsigned char *ExactMatch, unsigned char *Violate, unsigned int *film_index,unsigned int *count_still,
		unsigned char *p32Detected1, unsigned int *p32Sequence1,unsigned char film_Pair_en_auto,
		unsigned char film_Pair1_en,unsigned char film_HiFreq_flag,unsigned char film_Violate_strict_en);

void scalerVIP_film_FWmode_detection2_isr(unsigned int NextStaticPattern, unsigned char Strict,
								unsigned int FrameStaticPattern,
								unsigned char PrevFieldMotion, unsigned char NextFieldMotion,
							    unsigned char *ExactMatch, unsigned char *Violate, unsigned int *film_index,
								unsigned char *p32Detected2, unsigned int *p32Sequence2,unsigned char film_Violate_strict_en);

void	scalerVIP_film_FWmode_detection22_isr(	unsigned int NextStaticPattern, unsigned char Strict,
								unsigned char PrevFieldMotion, unsigned char NextFieldMotion,
							    unsigned char *ExactMatch, unsigned char *Violate, unsigned int *film_index, unsigned int *count_still22,
								unsigned char *p22Detected, unsigned int *p22Sequence,unsigned char film_Violate_strict_en);

void	scalerVIP_film_FWmode_detection22new_isr(	unsigned int NextStaticPattern, unsigned char Strict,
								unsigned char PrevFieldMotion, unsigned char NextFieldMotion,
							    unsigned char *ExactMatch, unsigned char *Violate, unsigned int *film_index, unsigned int *count_still22,
								unsigned char *p22Detected, unsigned int *p22Sequence);

static void scalerVIP_film_FWmode_film32_debounce(unsigned char *Detected_flag, unsigned int *Detected_cnt,unsigned char FieldNum);
static void scalerVIP_film_FWmode_film22_debounce(unsigned char *Detected_flag, unsigned int *Detected_cnt,unsigned char FieldNum);
void scalerVIP_film_FWmode_film_reset(void);
//void drvif_module_fw_film_init(void);
//void scalerVIP_film_FWmode_3D_start(void);
//void scalerVIP_film_FWmode_3D_end(void);
////20140103 Chris
void scalerVIP_rtnr_noise_measure(void);
void scalerVIP_DI_MCNR_RTNR_bottom_fresh_line_patch(unsigned char enable);
void scalerVIP_Get_DI_Width_Height(unsigned short *pWidth, unsigned short *pHeight);
void scalerDI_Set_DI_SMD(unsigned char DI_SMD_enable);
void scalerVIP_Set_FW_FILM_Share_Memory(unsigned long arg);
unsigned char scalerVIP_Get_film_enable_ap_status(void);
#endif



