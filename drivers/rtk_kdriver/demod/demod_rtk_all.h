#ifndef __DEMOD_REALTEK_ALL_HANDLE_H__
#define __DEMOD_REALTEK_ALL_HANDLE_H__

#include "demod.h"
#include "demod_rtk_def.h"

#ifdef __cplusplus
extern "C" {
#endif

#define KERNEL_AUTOTUNE_UPDATE_INTERVAL_MS 200

typedef struct {
	DEMOD*                      m_pDemod;
	DEMOD*                      m_pATSCDemod;
	DEMOD*                      m_pQAMDemod;
	DEMOD*                      m_pDVBTDemod;
	DEMOD*                      m_pDVBT2Demod;
	DEMOD*                      m_pDVBSDemod;
	DEMOD*                      m_pDVBS2Demod;
	DEMOD*                      m_pDVBCDemod;
	DEMOD*                      m_pDTMBDemod;
	DEMOD*                      m_pISDBTDemod;
	DEMOD*                      m_pATVDemod;
	RTK_DEMOD_MODE                m_mode;
	unsigned char               m_output_mode;
	unsigned long               m_output_freq;
	struct task_struct *demod_kernelthread;
	unsigned char m_KernelAutoTuneThread_start;
	unsigned char               m_kernel_auto_tune_en;
	unsigned char               m_auto_tune_en;//non-kernel autotune

	int (* SetDTVMode)(struct sDEMOD *demod, RTK_DEMOD_MODE mode);
	void (* Destory)(struct sDEMOD *demod);
} REALTEK_ALL;

void REALTEK_ALL_Constructors(DEMOD* pDemodKernel, unsigned char addr, unsigned char output_mode, unsigned char output_freq, COMM* pComm);
void REALTEK_ALL_Destructors(DEMOD* pDemodKernel);
int REALTEK_ALL_SetTVSys(DEMOD* pDemodKernel, TV_SYSTEM sys);
int REALTEK_ALL_Init(DEMOD* pDemodKernel);
int REALTEK_ALL_SetTVSysEx(DEMOD* pDemodKernel, TV_SYSTEM sys, const TV_SIG_INFO* pSigInfo);
int REALTEK_ALL_SetIF(DEMOD* pDemodKernel, IF_PARAM* pParam);
int REALTEK_ALL_SetMode(DEMOD* pDemodKernel, TV_OP_MODE mode);
int REALTEK_ALL_SetTSMode(DEMOD* pDemodKernel, TS_PARAM* pParam);
int REALTEK_ALL_GetLockStatus(DEMOD* pDemodKernel, unsigned char* pLock);
int REALTEK_ALL_GetSignalInfo(DEMOD* pDemodKernel, TV_SIG_INFO* pInfo);
int REALTEK_ALL_GetSignalQuality(DEMOD* pDemodKernel, ENUM_TV_QUAL id, TV_SIG_QUAL* pQuality);
int REALTEK_ALL_GetCarrierOffset(DEMOD* pDemodKernel, long* pOffset);
int REALTEK_ALL_GetChannelInfo(DEMOD* pDemodKernel, unsigned char* Standard, unsigned char* Modulation, unsigned char* CodeRate, unsigned char* PilotOnOff, unsigned char* Inverse);
int REALTEK_ALL_GetDebugLogBuf(DEMOD* pDemodKernel, unsigned int* LogBufAddr, unsigned int* LogBufSize);
int REALTEK_ALL_AcquireSignal(DEMOD* pDemodKernel, unsigned char WaitSignalLock);
int REALTEK_ALL_Suspend(DEMOD* pDemodKernel);
int REALTEK_ALL_Resume(DEMOD* pDemodKernel);
int REALTEK_ALL_ScanSignal(DEMOD* pDemodKernel, long* pOffset, SCAN_RANGE range);
int REALTEK_ALL_ForwardI2C(DEMOD* pDemodKernel, unsigned char on_off);
int REALTEK_ALL_AutoTune(DEMOD* pDemodKernel);
int REALTEK_ALL_KernelAutoTune(DEMOD* pDemodKernel);
int REALTEK_ALL_InspectSignal(DEMOD* pDemodKernel);
int REALTEK_ALL_SetTvMode(DEMOD* pDemodKernel, TV_SYSTEM_TYPE mode);
int REALTEK_ALL_DebugInfo(DEMOD* pDemodKernel, unsigned char debug_mode);

int REALTEK_ALL_GetDemodInfo(DEMOD* pDemodKernel, TV_DEMOD_INFO* pDemodInfo);

int REALTEK_ALL_GetT2PLPInfo(DEMOD* pDemodKernel, TV_SIG_INFO* pInfo);
int REALTEK_ALL_ChangeT2PLP(DEMOD* pDemodKernel, TV_SIG_INFO* pInfo);

int REALTEK_ALL_Diseqc_SetDiseqcContinue22kOnOff(DEMOD* pDemodKernel, unsigned int OnOff);
int REALTEK_ALL_Diseqc_SetDiseqcCmd(DEMOD* pDemodKernel, unsigned int Length, unsigned char *Data);
int REALTEK_ALL_Diseqc_SetDiseqcToneBurst(DEMOD* pDemodKernel, DISEQC_TONE_MODE mode);
int REALTEK_ALL_GetRegCmd(DEMOD* pDemodKernel, unsigned int RegAddr, unsigned int *RegValue);
int REALTEK_ALL_SetRegCmd(DEMOD* pDemodKernel, unsigned int RegAddr, unsigned int RegValue);
int REALTEK_ALL_SetTunerInputMode(DEMOD* pDemodKernel, unsigned char Mode);

int REALTEK_ALL_BlindScan_Init(DEMOD* pDemodKernel, unsigned int StartFreqMhz, unsigned int EndFreqMhz);
int REALTEK_ALL_BlindScan_GetTunerFreq(DEMOD* pDemodKernel, unsigned int *TunerCenterFreqMhz, unsigned int *TunerCutOffFreqKhz);
int REALTEK_ALL_BlindScan_NextFreq(DEMOD* pDemodKernel, unsigned int *bBlindScanEnd);
int REALTEK_ALL_BlindScan_GetStatus(DEMOD* pDemodKernel, unsigned char *Status, unsigned int *bBlindScanLock);
int REALTEK_ALL_BlindScan_End(DEMOD* pDemodKernel);
int REALTEK_ALL_BlindScan_GetFoundTP(DEMOD* pDemodKernel, unsigned int *FreqMhz, unsigned int *SymbolRateKhz);
int REALTEK_ALL_BlindScan_AcquireSignal(DEMOD* pDemodKernel, unsigned int *SymbolRateKhz, int *Fcfo, unsigned char *bTpLock);
int REALTEK_ALL_KernelThread_EN(DEMOD* pDemodKernel, unsigned int thread_en);

#ifdef __cplusplus
}
#endif

#endif // __DEMOD_REALTEK_ALL_HANDLE_H__