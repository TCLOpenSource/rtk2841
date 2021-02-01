/***************************************************************************************************
  File        : demod.c
  Description : Base Class of All DVB-T/ATSC Demod
  Author      :
****************************************************************************************************
    Update List :
----------------------------------------------------------------------------------------------------
    1.0a     |   20080721    | Add Function - GetTSParam to get current TS Interface configuration of Demod
***************************************************************************************************/
#include <linux/kernel.h>
#include <linux/mutex.h>
#include "tv_osal.h"
#include "rtk_tv_fe_types.h"
#include "tv_fe_aux.h"
#include "comm.h"
#include "demod.h"
#include "tuner.h"

void Demod_Constructors(DEMOD* pDemodKernel)
{
	pDemodKernel->m_addr				 = 0;
	pDemodKernel->m_id				 = DTV_DEMOD_NO_DEMOD;
	pDemodKernel->m_pComm 			 = NULL;
	pDemodKernel->m_pTuner			 = NULL;
	pDemodKernel->m_ScanRange 		 = SCAN_RANGE_NONE;
	pDemodKernel->m_Capability		 = TV_SYS_TYPE_ATSC |
									   TV_SYS_TYPE_OPENCABLE |
									   TV_SYS_TYPE_ISDBT |
									   TV_SYS_TYPE_DVBT |
									   TV_SYS_TYPE_DVBC |
									   TV_SYS_TYPE_DTMB;

	// HW Parameters
	pDemodKernel->m_clock 			 = 0;

	// IF IN MODE
	pDemodKernel->m_if.freq			 = 0;
	pDemodKernel->m_if.inversion		 = 0;
	pDemodKernel->m_if.agc_pola		 = 1;
	pDemodKernel->m_tv_sys			 = TV_SYS_UNKNOWN;

	// TSOUT MODE
	//		  m_ts.mode 		   = SERIAL_MODE;
	pDemodKernel->m_ts.mode			 = PARALLEL_MODE;
	pDemodKernel->m_ts.data_order 	 = MSB_D7;
	pDemodKernel->m_ts.datapin		 = MSB_FIRST;
	pDemodKernel->m_ts.err_pol		 = ACTIVE_HIGH;
	pDemodKernel->m_ts.sync_pol		 = ACTIVE_HIGH;
	pDemodKernel->m_ts.val_pol		 = ACTIVE_HIGH;
	pDemodKernel->m_ts.clk_pol		 = FALLING_EDGE;
	pDemodKernel->m_ts.internal_demod_input = 0;

	pDemodKernel->m_update_interval_ms = TV_UPDATE_INTERVAL_INFINITY;

	pDemodKernel->Init = Demod_Init;
	pDemodKernel->Reset = Demod_Reset;
	pDemodKernel->AcquireSignal = Demod_AcquireSignal;
	pDemodKernel->ScanSignal = Demod_ScanSignal;
	pDemodKernel->SetIF = Demod_SetIF;
	pDemodKernel->SetTSMode = Demod_SetTSMode;
	pDemodKernel->SetTVSysEx = Demod_SetTVSysEx;
	pDemodKernel->SetMode = Demod_SetMode;
	pDemodKernel->SetTVSys = Demod_SetTVSys;
	pDemodKernel->GetLockStatus = Demod_GetLockStatus;
	pDemodKernel->GetSegmentNum = Demod_GetSegmentNum;
	pDemodKernel->GetSignalInfo = Demod_GetSignalInfo;
	pDemodKernel->GetSignalQuality = Demod_GetSignalQuality;
	pDemodKernel->ChangeT2PLP = Demod_ChangeT2PLP;
	pDemodKernel->GetT2PLPInfo = Demod_GetT2PLPInfo;
	pDemodKernel->GetT2L1PreInfo = Demod_GetT2L1PreInfo;
	pDemodKernel->GetT2L1PostInfo = Demod_GetT2L1PostInfo;
	pDemodKernel->GetDemodStatus = Demod_GetDemodStatus;
	pDemodKernel->GetCarrierOffset = Demod_GetCarrierOffset;
	pDemodKernel->GetDebugLogBuf = Demod_GetDebugLogBuf;
	pDemodKernel->ForwardI2C = Demod_ForwardI2C;
	pDemodKernel->AutoTune = Demod_AutoTune;
	pDemodKernel->KernelAutoTune = Demod_KernelAutoTune;
	pDemodKernel->GetCapability = Demod_GetCapability;
	pDemodKernel->Suspend = Demod_Suspend;
	pDemodKernel->Resume = Demod_Resume;
	pDemodKernel->SetTvMode = Demod_SetTvMode;
	pDemodKernel->InspectSignal = Demod_InspectSignal;   // Add monitor function that used to monitor demod status
	pDemodKernel->AttachTuner = Demod_AttachTuner;
	pDemodKernel->GetTSParam = Demod_GetTSParam;
	pDemodKernel->Lock = Demod_Lock;
	pDemodKernel->Unlock = Demod_Unlock;
	pDemodKernel->Destory = Demod_Destructors;

	mutex_init(&pDemodKernel->m_lock);
}

void Demod_Destructors(DEMOD* pDemodKernel)
{
	mutex_destroy(&pDemodKernel->m_lock);
}

int Demod_Init(DEMOD* pDemodKernel)
{
	return TUNER_CTRL_OK;
}

int Demod_Reset(DEMOD* pDemodKernel)
{
	return TUNER_CTRL_OK;
}

//int Demod_AcquireSignal(PDemod pDemodKernel, unsigned char WaitSignalLock = 1)
int Demod_AcquireSignal(DEMOD* pDemodKernel, unsigned char WaitSignalLock)
{
	return TUNER_CTRL_OK;
}

int Demod_ScanSignal(DEMOD* pDemodKernel, long* offset, SCAN_RANGE range)
{
	int ret;
	*offset = 0;
	if ((ret = pDemodKernel->AcquireSignal(pDemodKernel, 1)) == TUNER_CTRL_OK)
		ret = pDemodKernel->GetCarrierOffset(pDemodKernel, offset);
	return ret;
}

int Demod_SetIF(DEMOD* pDemodKernel, IF_PARAM* pParam)
{
	return TUNER_CTRL_OK;
}

int Demod_SetTSMode(DEMOD* pDemodKernel, TS_PARAM* pParam)
{
	return TUNER_CTRL_OK;
}

//int Demod_SetTVSysEx(TV_SYSTEM sys, const TV_SIG_INFO* pSigInfo = NULL)
int Demod_SetTVSysEx(DEMOD* pDemodKernel, TV_SYSTEM sys, const TV_SIG_INFO* pSigInfo)
{
	return pDemodKernel->SetTVSys(pDemodKernel, sys);
}

int Demod_SetMode(DEMOD* pDemodKernel, TV_OP_MODE mode)
{
	return TUNER_CTRL_OK;
}

int Demod_SetTVSys(DEMOD* pDemodKernel, TV_SYSTEM sys)
{
	return TUNER_CTRL_OK;
}

int Demod_GetLockStatus(DEMOD* pDemodKernel, unsigned char* pLock)
{
	return TUNER_CTRL_OK;
}

int Demod_GetSegmentNum(DEMOD* pDemodKernel, int layerIndex, unsigned char* pNum)
{
	return TUNER_CTRL_OK;
}

int Demod_GetSignalInfo(DEMOD* pDemodKernel, TV_SIG_INFO* pInfo)
{
	return TUNER_CTRL_OK;
}

int Demod_GetSignalQuality(DEMOD* pDemodKernel, ENUM_TV_QUAL id, TV_SIG_QUAL* pQuality)
{
	return TUNER_CTRL_OK;
}

int Demod_ChangeT2PLP(DEMOD* pDemodKernel, TV_SIG_INFO* pInfo)
{
	return TUNER_CTRL_OK;
}
int Demod_GetT2PLPInfo(DEMOD* pDemodKernel, TV_SIG_INFO* pInfo)
{
	return TUNER_CTRL_OK;
}
int Demod_GetT2L1PreInfo(DEMOD* pDemodKernel, TV_SIG_INFO* pInfo)
{
	return TUNER_CTRL_OK;
}
int Demod_GetT2L1PostInfo(DEMOD* pDemodKernel, TV_SIG_INFO* pInfo)
{
	return TUNER_CTRL_OK;
}

int Demod_GetDemodStatus(DEMOD* pDemodKernel, unsigned long* pStatus)
{
	return TUNER_CTRL_OK;
}

int Demod_GetCarrierOffset(DEMOD* pDemodKernel, long* pOffset)
{
	*pOffset = 0;
	return TUNER_CTRL_OK;
}
int Demod_GetDebugLogBuf(DEMOD* pDemodKernel, unsigned int* LogBufAddr, unsigned int* LogBufSize)
{
	* LogBufAddr = 0;
	* LogBufSize = 0;
	return TUNER_CTRL_OK;
}

int Demod_ForwardI2C(DEMOD* pDemodKernel, unsigned char on_off)
{
	return TUNER_CTRL_OK;
}

int Demod_AutoTune(DEMOD* pDemodKernel)
{
	return TUNER_CTRL_OK;
}

int Demod_KernelAutoTune(DEMOD* pDemodKernel)
{
	return TUNER_CTRL_OK;
}

unsigned long Demod_GetCapability(DEMOD* pDemodKernel)
{
	return pDemodKernel->m_Capability;
}

int Demod_Suspend(DEMOD* pDemodKernel)
{
	return TUNER_CTRL_OK;
}

int Demod_Resume(DEMOD* pDemodKernel)
{
	return TUNER_CTRL_OK;
}

int Demod_SetTvMode(DEMOD* pDemodKernel, TV_SYSTEM_TYPE sys_type)
{
	return TUNER_CTRL_OK;
}

int Demod_InspectSignal(DEMOD* pDemodKernel)      // Add monitor function that used to monitor demod status
{
	unsigned char  lock;
	//float          snr;
	//float          ber;
	TV_SIG_QUAL    quality;

	pDemodKernel->GetLockStatus(pDemodKernel, &lock);
	pDemodKernel->GetSignalQuality(pDemodKernel, TV_QUAL_SNR, &quality);
	//snr = quality.snr;
	pDemodKernel->GetSignalQuality(pDemodKernel, TV_QUAL_BER, &quality);
	//ber = quality.ber;
	//return printf(pBuff, BufferSize, "lock=%d, snr=%f, ber=%f", lock, snr, ber);
	return 1;
}

void Demod_AttachTuner(DEMOD* pDemodKernel, TUNER* pTuner)
{
	pDemodKernel->m_pTuner = pTuner;
}

TS_PARAM Demod_GetTSParam(DEMOD* pDemodKernel)
{
	return pDemodKernel->m_ts;
}

void Demod_Lock(DEMOD* pDemodKernel)
{
	mutex_lock(&pDemodKernel->m_lock);
}

void Demod_Unlock(DEMOD* pDemodKernel)
{
	mutex_unlock(&pDemodKernel->m_lock);
}

