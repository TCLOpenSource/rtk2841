#ifndef __SCALER_AVDCTRL_H
#define  __SCALER_AVDCTRL_H

#include <tvscalercontrol/scaler/scalerstruct.h>
#include <scalercommon/scalerCommon.h>
#include <tvscalercontrol/scaler_vfedev.h>
#define DETECT_STAGE_INIT 0
#define DETECT_STAGE_HVLOCK 1
#define DETECT_STAGE_VSTATE_READY 2
#define DETECT_STAGE_FINAL 0xff

extern unsigned char g_ucAtvDetectStage;
extern unsigned char g_ucDetectStage;
extern unsigned char g_ucVDMode;
extern unsigned char g_ucVDPreMode;
extern unsigned char g_ucModeCurr;
extern unsigned char atv_channel_change_start;
extern unsigned int g_ulInitStageCount;

extern VFE_AVD_SCART_FB_STATUS_T g_ucScartMode;
extern unsigned char g_ucSrcType;
extern VFE_AVD_DEMOD_TYPE g_tAVDDemodType;
extern VFE_AVD_COLOR_SYSTEM_T g_tSupportedColorSys;
extern unsigned char g_ucStopVDTimer;
extern unsigned char g_ucTimerEnable;
extern unsigned int g_ucTimerCount;
extern unsigned char avd_good_timing_ready;
extern unsigned char atv_channel_change;
extern unsigned char vdc_resetTV_Count;
extern bool g_bChangeSystem;
extern bool g_bStartChangeSystem;
extern bool g_bMainRunSearchState;
extern bool g_bSubRunSearchState;

extern unsigned int g_ulVDCPhyAddr;
#ifdef CONFIG_ARM64
extern unsigned long g_ulVDCPhyAddr_cache;
extern unsigned long *g_ulVDCPhyAddr_nonCache;
#else
extern unsigned int g_ulVDCPhyAddr_cache;
extern unsigned int *g_ulVDCPhyAddr_nonCache;
#endif
extern unsigned char g_ucMode_Curr;

StructDisplayInfo * Get_AVD_Dispinfo(void);

ModeInformationType * Get_AVD_Timinginfo(void);

void SetAVDLGETimingInfo(void);

int Scaler_AVD_Init(VFE_AVD_CC_TTX_STATUS_T a_ucSupportingVBI);

char Scaler_AVD_Uninit(void);

char Scaler_AVD_Open(void);

char Scaler_AVD_Close(void);

char Scaler_AVD_AV_Connect(unsigned short srcinput);

char Scaler_AVD_AV_Disconnect(void);

char Scaler_AVD_ATV_Connect(unsigned short srcinput);

char Scaler_AVD_ATV_Disconnect(void);

void Scaler_AVD_Set_Scart_Mode(void);

void fw_video_SetModeInfo(unsigned char CurrentSrc);

extern StructDisplayInfo * Get_AVD_ScalerDispinfo(void);

// Scart CVBS
char Scaler_AVD_Scart_Connect(unsigned short srcinput);

// Scart RGB
char Scaler_AVD_ScartRGB_Connect(unsigned short srcinput);

char Scaler_AVD_Scart_Disconnect(void);

unsigned char Scaler_AVD_DetectTiming(void);

VFE_AVD_TIMING_INFO_T* Scaler_AVD_GetLGETimingInfo(unsigned char* a_ucRet);

char Scaler_AVD_SetLGEColorSystem(VFE_AVD_COLOR_SYSTEM_T ColorSystem);

char Scaler_AVD_GetLGEColorSystem(VFE_AVD_AVDECODER_VIDEO_MODE_T *ColorSystem);

unsigned char Scaler_AVD_ATV_DetectTiming(void);

void AVD_OnlineMeasureError_Handler(int srcType);

char Scaler_AVD_SetDemodType(VFE_AVD_DEMOD_TYPE a_tDemodType);

VFE_AVD_DEMOD_TYPE Scaler_AVD_GetDemodType(void);

char Scaler_AVD_GetScartFastBlankingStatus(VFE_AVD_SCART_FB_STATUS_T *pStatus);

char Scaler_AVD_GetScartID(VFE_AVD_SCART_AR_T *pScartAr);

void Scaler_AVD_SetSyncDetectForTuning(unsigned char a_ucFlag);

unsigned char Scaler_AVD_DoesSyncExist(void);

void Scaler_AVD_SetChangeSystem(bool Change);

void Scaler_AVD_SetAutoTuneMode(bool AutoTuneMode);

bool Scaler_AVD_GetChangeSystem(void);

bool Scaler_AVD_GetAutoTuneMode(void);

bool Scaler_AVD_GetRunSearchState(unsigned char a_ucChannel);

void Scaler_AVD_SetRunSearchState(unsigned char a_ucChannel, bool a_bFlag);

unsigned char Scaler_AVD_GetAvdSource(void);

void Scaler_AVD_ClearTimingInfo(void);

void Scaler_AVD_ResetTVCount(void);

//bool Scaler_AVD_GetDetectTimingAgain(void);

//void Scaler_AVD_SetDetectTimingAgain(bool a_bFlag);

unsigned char Scaler_AVD_GetDetectStage(void);

unsigned char Scaler_AVD_GetVDPreMode(void);

unsigned char Scaler_AVD_CheckATVTimingChange(unsigned char a_ucChannel);

void ClearAVDLGETimingInfo(void);

void Scaler_AVD_SetDetectStage(unsigned char stage);

char Scaler_AVD_IsSupportedColorSys(void);

unsigned char AVD_vpq_mem_ctrl(unsigned char bEnable);

unsigned int AVD_vpq_mem_isAllocated(void);

#if 1//def AVD_27M_CONTROL_BY_AP

void Scaler_AVD_SetAP27MEnable(unsigned char a_ucFlag);

void Scaler_AVD_GetAP27MEnable(void);

#endif


void Scaler_AVD_ResetTVCount(void);

unsigned char Scaler_AVD_Break_DetectTiming(void);

void Scaler_AVD_Set_DetTiming_In_AutoScan_Flag(unsigned char a_ucFlag);
bool Scaler_AVD_SetChannelChange(void);//For K4L
bool Scaler_AVD_GetIsChannelChange(void);//For K4L



#endif

