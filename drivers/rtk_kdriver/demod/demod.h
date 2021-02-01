/***************************************************************************************************
  File        : demod.h
  Description : Base Class of All DVB-T/ATSC Demod
  Author      :
****************************************************************************************************
    Update List :
----------------------------------------------------------------------------------------------------
    1.0a     |   20080721    | Add Function - GetTSParam to get current TS Interface configuration of Demod
***************************************************************************************************/
#ifndef __DEMOD_HANDLE_H__
#define __DEMOD_HANDLE_H__
#include "tv_osal.h"
#include "rtk_tv_fe_types.h"
#include "tv_fe_aux.h"
//#include "comm.h"
#include "tuner.h"

#define MAX_DEMOD_ADDR_COUNT   4


enum {
	DTV_DEMOD_NO_DEMOD = 0,
	DTV_DEMOD_REALTEK_RL6259,
	DTV_DEMOD_REALTEK_RTL2830,
	DTV_DEMOD_REALTEK_RTL2831,
	DTV_DEMOD_REALTEK_RTL2832,
	DTV_DEMOD_REALTEK_RTL2836,
	DTV_DEMOD_REALTEK_RTL2836B,
	DTV_DEMOD_REALTEK_RTL2840,
	DTV_DEMOD_REALTEK_RTL2810,
	DTV_DEMOD_REALTEK_RTL2810_OC,
	DTV_DEMOD_REALTEK_RTD2812,
	DTV_DEMOD_REALTEK_RTD2810B,
	DTV_DEMOD_REALTEK_RTD2810B_ATSC,
	DTV_DEMOD_REALTEK_RTD2810B_QAM,
	DTV_DEMOD_REALTEK_RTD2810B_ATSC_QAM,
	DTV_DEMOD_REALTEK_RTD2974_DTMB,
	DTV_DEMOD_REALTEK_RTD2974_DVBC,
	DTV_DEMOD_REALTEK_RTD2974_ATSC,
	DTV_DEMOD_REALTEK_RTD2974_QAM,
	DTV_DEMOD_REALTEK_RTD2974_ATSC_QAM,
	DTV_DEMOD_REALTEK_RTD2995_DTMB,
	DTV_DEMOD_REALTEK_RTD2995_DVBC,
	DTV_DEMOD_REALTEK_RTD2995_DTMB_DVBC,
	DTV_DEMOD_REALTEK_RTD2995_QAM,
	DTV_DEMOD_REALTEK_ATBM8878_DTMB,
	DTV_DEMOD_REALTEK_ATBM8878_DVBC,
	DTV_DEMOD_REALTEK_ATBM8878_DTMB_DVBC,
	DTV_DEMOD_REALTEK_ATBM8880_DTMB,

	DTV_DEMOD_REALTEK_RTD2648_DVBT,
	DTV_DEMOD_REALTEK_RTD2648_DVBC,
	DTV_DEMOD_REALTEK_RTD2648_ISDBT,
	DTV_DEMOD_REALTEK_RTD2648_ATSC,
	DTV_DEMOD_REALTEK_RTD2648_QAM,
	DTV_DEMOD_REALTEK_RTD2648_ATSC_QAM,
	DTV_DEMOD_REALTEK_RTD2648_DVBT_DVBC,

	DTV_DEMOD_REALTEK_RTD2945_DVBT,
	DTV_DEMOD_REALTEK_RTD2945_DVBC,
	DTV_DEMOD_REALTEK_RTD2945_DVBT_DVBC,
	DTV_DEMOD_REALTEK_RTD2945_ISDBT,
	DTV_DEMOD_REALTEK_RTD2945_ATSC,
	DTV_DEMOD_REALTEK_RTD2945_QAM,
	DTV_DEMOD_REALTEK_RTD2945_ATSC_QAM,
	DTV_DEMOD_REALTEK_RTD2945_DTMB,
	DTV_DEMOD_REALTEK_RTD2945_DTMB_DVBC,
	DTV_DEMOD_REALTEK_RTD2945_ALL,

	DTV_DEMOD_REALTEK_RTD299S_DVBT,
	DTV_DEMOD_REALTEK_RTD299S_DVBC,
	DTV_DEMOD_REALTEK_RTD299S_DVBT_DVBC,
	DTV_DEMOD_REALTEK_RTD299S_ISDBT,
	DTV_DEMOD_REALTEK_RTD299S_ATSC,
	DTV_DEMOD_REALTEK_RTD299S_QAM,
	DTV_DEMOD_REALTEK_RTD299S_ATSC_QAM,
	DTV_DEMOD_REALTEK_RTD299S_DTMB,
	DTV_DEMOD_REALTEK_RTD299S_DTMB_DVBC,
	DTV_DEMOD_REALTEK_RTD299S_ALL,

	DTV_DEMOD_REALTEK_MERLIN2_DVBT,
	DTV_DEMOD_REALTEK_MERLIN2_DVBT2,
	DTV_DEMOD_REALTEK_MERLIN2_DVBC,
	DTV_DEMOD_REALTEK_MERLIN2_ISDBT,
	DTV_DEMOD_REALTEK_MERLIN2_ATSC,
	DTV_DEMOD_REALTEK_MERLIN2_QAM,
	DTV_DEMOD_REALTEK_MERLIN2_DVBS,
	DTV_DEMOD_REALTEK_MERLIN2_DVBS2,
	DTV_DEMOD_REALTEK_MERLIN2_ALL,

	DTV_DEMOD_REALTEK_I_DVBT,
	DTV_DEMOD_REALTEK_I_DVBT2,
	DTV_DEMOD_REALTEK_I_DVBC,
	DTV_DEMOD_REALTEK_I_ISDBT,
	DTV_DEMOD_REALTEK_I_QAM,
	DTV_DEMOD_REALTEK_I_DVBS,
	DTV_DEMOD_REALTEK_I_DVBS2,
	DTV_DEMOD_REALTEK_H_DTMB,
	DTV_DEMOD_REALTEK_R_DTMB,
	DTV_DEMOD_REALTEK_R_ATSC,
	DTV_DEMOD_REALTEK_R_DVBC,
	DTV_DEMOD_REALTEK_R_ATV,
	DTV_DEMOD_REALTEK_ALL,

	DTV_DEMOD_HD2311,
	DTV_DEMOD_HD2311_DTMB,
	DTV_DEMOD_NXP_TDA10048,
	DTV_DEMOD_THOMSON_T4111A,
	DTV_DEMOD_SAMSUNG_S5H1411X,
	DTV_DEMOD_LS_LGS8G42,
	DTV_DEMOD_LS_LGS8G52,
	DTV_DEMOD_MAXSCEND_MXD1320,
	DTV_DEMOD_NUMBER_MAX,
	DTV_DEMOD_SILICONLABS_SI2168,
	DTV_DEMOD_SILICONLABS_SI2169C,
	DTV_DEMOD_PANASONIC_MN88472,
	DTV_DEMOD_SONY_CXD2837ER,
	DTV_DEMOD_SONY_CXD2826ER,
	DTV_DEMOD_TOSHIBA_TC90527
};

typedef struct sDEMOD {
	void *private_data;

	int (* Init)(struct sDEMOD *demod);
	int (* Reset)(struct sDEMOD *demod);
	int (* AcquireSignal)(struct sDEMOD *demod, unsigned char WaitSignalLock);
	int (* ScanSignal)(struct sDEMOD *demod, long* offset, SCAN_RANGE range);
	int (* SetIF)(struct sDEMOD *demod, IF_PARAM* pParam);
	int (* SetTSMode)(struct sDEMOD *demod, TS_PARAM* pParam);
	int (* SetTVSysEx)(struct sDEMOD *demod, TV_SYSTEM sys, const TV_SIG_INFO* pSigInfo);
	int (* SetMode)(struct sDEMOD *demod, TV_OP_MODE mode);
	int (* SetTVSys)(struct sDEMOD *demod, TV_SYSTEM sys);
	int (* GetLockStatus)(struct sDEMOD *demod, unsigned char* pLock);
	int (* GetSegmentNum)(struct sDEMOD *demod, int layerIndex, unsigned char* pNum);
	int (* GetSignalInfo)(struct sDEMOD *demod, TV_SIG_INFO* pInfo);
	int (* GetSignalQuality)(struct sDEMOD *demod, ENUM_TV_QUAL id, TV_SIG_QUAL* pQuality);
	int (* GetT2PLPInfo)(struct sDEMOD *demod, TV_SIG_INFO* pInfo);
	int (* GetT2L1PreInfo)(struct sDEMOD *demod, TV_SIG_INFO* pInfo);
	int (* GetT2L1PostInfo)(struct sDEMOD *demod, TV_SIG_INFO* pInfo);
	int (* ChangeT2PLP)(struct sDEMOD *demod, TV_SIG_INFO* pInfo);
	int (* GetDemodStatus)(struct sDEMOD *demod, unsigned long* pStatus);
	int (* GetCarrierOffset)(struct sDEMOD *demod, long* pOffset);
	int (* GetTunerTablePara)(struct sDEMOD *demod, TUNER_TABLE_PARAM *pTunerPara);
	int (* GetChannelInfo)(struct sDEMOD *demod, unsigned char* Standard, unsigned char* Modulation, unsigned char* CodeRate, unsigned char* PilotOnOff, unsigned char* Inverse);
	int (* GetDebugLogBuf)(struct sDEMOD *demod, unsigned int* LogBufAddr, unsigned int* LogBufSize);
	int (* ForwardI2C)(struct sDEMOD *demod, unsigned char on_off);
	int (* AutoTune)(struct sDEMOD *demod);
	int (* KernelAutoTune)(struct sDEMOD *demod);
	unsigned long (* GetCapability)(struct sDEMOD *demod);
	int (* Suspend)(struct sDEMOD *demod);
	int (* Resume)(struct sDEMOD *demod);
	int (* SetTvMode)(struct sDEMOD *demod, TV_SYSTEM_TYPE sys_type);
	int (* GetDemodInfo)(struct sDEMOD *demod, TV_DEMOD_INFO* pDemodInfo);
	int (* DebugInfo)(struct sDEMOD *demod, unsigned char debug_mode);
	int (* InspectSignal)(struct sDEMOD *demod);	  // Add monitor function that used to monitor demod status
	void(*AttachTuner)(struct sDEMOD *demod, TUNER* pTuner);
	TS_PARAM(* GetTSParam)(struct sDEMOD *demod);
	int (* GetRegCmd)(struct sDEMOD *demod, unsigned int RegAddr, unsigned int *RegValue);//Add for outer module to get register
	int (* SetRegCmd)(struct sDEMOD *demod, unsigned int RegAddr, unsigned int RegValue);//Add for outer module to set register


	int (*BlindScan_Init)(struct sDEMOD *demod, unsigned int StartFreqMhz, unsigned int EndFreqMhz);
	int (*BlindScan_GetTunerFreq)(struct sDEMOD *demod, unsigned int *TunerCenterFreqMhz, unsigned int *TunerCutOffFreqKhz);
	int (*BlindScan_NextFreq)(struct sDEMOD *demod, unsigned int *bBlindScanEnd);
	int (*BlindScan_GetStatus)(struct sDEMOD *demod, unsigned char *Status, unsigned int *bBlindScanLock);
	int (*BlindScan_AcquireSignal)(struct sDEMOD *demod, unsigned int *SymbolRateKhz, int *Fcfo, unsigned char *bTpLock);
	int (*BlindScan_End)(struct sDEMOD *demod);
	int (*BlindScan_GetFoundTP)(struct sDEMOD *demod, unsigned int *FreqMhz, unsigned int *SymbolRateKhz);


	int (* SetDiseqcContinue22kOnOff)(struct sDEMOD *demod, unsigned int OnOff);
	int (* SetDiseqcCmd)(struct sDEMOD *demod, unsigned int Length, unsigned char *Data);
	int (* SetDiseqcToneBurst)(struct sDEMOD *demod, DISEQC_TONE_MODE mode);
	int (* SetDiseqcUnModToneBurst)(struct sDEMOD *demod);
	int (* SetDiseqcModToneBurst)(struct sDEMOD *demod);
	int (* SetTunerInputMode)(struct sDEMOD *demod, unsigned char Mode);

	void (* Lock)(struct sDEMOD *demod);
	void (* Unlock)(struct sDEMOD *demod);

	void (*Destory)(struct sDEMOD *demod);

	unsigned short m_id;
	unsigned char  m_addr;
	unsigned long  m_update_interval_ms;
	COMM*		   m_pComm;
	TUNER*		   m_pTuner;
	SCAN_RANGE	   m_ScanRange;
	unsigned long  m_Capability;
	CH_MODE	   m_ScanMode;

	unsigned long  m_clock;
	IF_PARAM	   m_if;
	TS_PARAM	   m_ts;
	TV_SYSTEM	   m_tv_sys;
	struct mutex   m_lock;
} DEMOD;

int Demod_Init(DEMOD* pDemodKernel);
int Demod_Reset(DEMOD* pDemodKernel);
int Demod_AcquireSignal(DEMOD* pDemodKernel, unsigned char WaitSignalLock);
int Demod_ScanSignal(DEMOD* pDemodKernel, long* offset, SCAN_RANGE range);
int Demod_SetIF(DEMOD* pDemodKernel, IF_PARAM* pParam);
int Demod_SetTSMode(DEMOD* pDemodKernel, TS_PARAM* pParam);
int Demod_SetTVSysEx(DEMOD* pDemodKernel, TV_SYSTEM sys, const TV_SIG_INFO* pSigInfo);
int Demod_SetMode(DEMOD* pDemodKernel, TV_OP_MODE mode);
int Demod_SetTVSys(DEMOD* pDemodKernel, TV_SYSTEM sys);
int Demod_GetLockStatus(DEMOD* pDemodKernel, unsigned char* pLock);
int Demod_GetSegmentNum(DEMOD* pDemodKernel, int layerIndex, unsigned char* pNum);
int Demod_GetSignalInfo(DEMOD* pDemodKernel, TV_SIG_INFO* pInfo);
int Demod_GetSignalQuality(DEMOD* pDemodKernel, ENUM_TV_QUAL id, TV_SIG_QUAL* pQuality);
int Demod_ChangeT2PLP(DEMOD* pDemodKernel, TV_SIG_INFO* pInfo);
int Demod_GetT2PLPInfo(DEMOD* pDemodKernel, TV_SIG_INFO* pInfo);
int Demod_GetT2L1PreInfo(DEMOD* pDemodKernel, TV_SIG_INFO* pInfo);
int Demod_GetT2L1PostInfo(DEMOD* pDemodKernel, TV_SIG_INFO* pInfo);
int Demod_GetDemodStatus(DEMOD* pDemodKernel, unsigned long* pStatus);
int Demod_GetCarrierOffset(DEMOD* pDemodKernel, long* pOffset);
int Demod_GetChannelInfo(DEMOD* pDemodKernel, unsigned char* Standard, unsigned char* Modulation, unsigned char* CodeRate, unsigned char* PilotOnOff, unsigned char* Inverse);
int Demod_GetDebugLogBuf(DEMOD* pDemodKernel, unsigned int* LogBufAddr, unsigned int* LogBufSize);
int Demod_ForwardI2C(DEMOD* pDemodKernel, unsigned char on_off);
int Demod_AutoTune(DEMOD* pDemodKernel);
int Demod_KernelAutoTune(DEMOD* pDemodKernel);
unsigned long Demod_GetCapability(DEMOD* pDemodKernel);
int Demod_Suspend(DEMOD* pDemodKernel);
int Demod_Resume(DEMOD* pDemodKernel);
int Demod_SetTvMode(DEMOD* pDemodKernel, TV_SYSTEM_TYPE sys_type);
int Demod_InspectSignal(DEMOD* pDemodKernel);      // Add monitor function that used to monitor demod status
void Demod_AttachTuner(DEMOD* pDemodKernel, TUNER* pTuner);
TS_PARAM Demod_GetTSParam(DEMOD* pDemodKernel);
void Demod_Lock(DEMOD* pDemodKernel);
void Demod_Unlock(DEMOD* pDemodKernel);
void Demod_Destructors(DEMOD* pDemodKernel);
void Demod_Constructors(DEMOD* pDemodKernel);

//=============================================================
#define DEMOD_CALLER(fmt, args...)          rtd_printk_demod(KERN_DEBUG, "DEMO", "DTV_CALLER, " fmt, ##args);
#define DEMOD_DBG(fmt, args...)          rtd_printk_demod(KERN_DEBUG, "DEMO", "DTV_DEBUG, " fmt, ##args);
#define DEMOD_INFO(fmt, args...)               rtd_printk_demod(KERN_INFO, "DEMO", "DTV_INFO, " fmt, ##args);
#define DEMOD_WARNING(fmt, args...)         rtd_printk_demod(KERN_WARNING, "DEMO", "DTV_WARNING, " fmt, ##args);


#endif  //__DEMOD_HANDLE_H__
