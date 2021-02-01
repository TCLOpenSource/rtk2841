/***************************************************************************************************
  File        : ademod.h
  Description : Base Class of All Analog ADemod
  Author      : Kevin Wang
****************************************************************************************************
    Update List :
----------------------------------------------------------------------------------------------------
    1.0a     |   20141020    | Create Phase
***************************************************************************************************/
#include <linux/kernel.h>
#include <linux/mutex.h>
#include "tv_osal.h"
#include "rtk_tv_fe_types.h"
#include "tv_fe_aux.h"
//#include "comm.h"
#include "ademod.h"
#include "tuner.h"

void ADemod_Constructors(ADEMOD* pADemodKernel)
{
	pADemodKernel->m_id				 = DTV_ADEMOD_NONE;
	pADemodKernel->m_pTuner			 = NULL;
	pADemodKernel->m_Capability		 = TV_SYS_TYPE_BGDKIL |
									   TV_SYS_TYPE_MN;

	pADemodKernel->m_if.freq			 = 0;
	pADemodKernel->m_if.inversion		 = 0;
	pADemodKernel->m_if.agc_pola		 = 1;
	pADemodKernel->m_tv_sys			 = TV_SYS_UNKNOWN;

	pADemodKernel->Init = ADemod_Init;
	pADemodKernel->Reset = ADemod_Reset;
	pADemodKernel->SetTVSysEx = ADemod_SetTVSysEx;
	pADemodKernel->SetTVSys = ADemod_SetTVSys;
	pADemodKernel->SetTvMode = ADemod_SetTvMode;
	pADemodKernel->SetMode = ADemod_SetMode;
	pADemodKernel->GetLockStatus = ADemod_GetLockStatus;
	pADemodKernel->GetCarrierOffset = ADemod_GetCarrierOffset;
	pADemodKernel->GetSignalQuality = ADemod_GetSignalQuality;
	pADemodKernel->AcquireSignal = ADemod_AcquireSignal;
	pADemodKernel->GetSignalInfo = ADemod_GetSignalInfo;
	pADemodKernel->GetCapability = ADemod_GetCapability;
	pADemodKernel->Suspend = ADemod_Suspend;
	pADemodKernel->Resume = ADemod_Resume;
	pADemodKernel->InspectSignal = ADemod_InspectSignal;
	pADemodKernel->AttachTuner = ADemod_AttachTuner;
	pADemodKernel->Lock = ADemod_Lock;
	pADemodKernel->Unlock = ADemod_Unlock;
	pADemodKernel->Destory = ADemod_Destructors;

	mutex_init(&pADemodKernel->m_lock);
}

void ADemod_Destructors(ADEMOD* pADemodKernel)
{
	mutex_destroy(&pADemodKernel->m_lock);
}

int ADemod_Init(ADEMOD* pADemodKernel)
{
	return TUNER_CTRL_OK;
}


int ADemod_Reset(ADEMOD* pADemodKernel)
{
	return TUNER_CTRL_OK;
}

int ADemod_SetTVSysEx(ADEMOD* pADemodKernel, TV_SYSTEM sys, const TV_SIG_INFO* pSigInfo)
{
	return pADemodKernel->SetTVSys(pADemodKernel, sys);
}

int ADemod_SetTVSys(ADEMOD* pADemodKernel, TV_SYSTEM sys)
{
	return TUNER_CTRL_OK;
}

int ADemod_SetTvMode(ADEMOD* pADemodKernel, TV_SYSTEM_TYPE sys)
{
	return TUNER_CTRL_OK;
}

int ADemod_SetMode(ADEMOD* pADemodKernel, TV_OP_MODE mode)
{
	return TUNER_CTRL_OK;
}

int ADemod_GetLockStatus(ADEMOD* pADemodKernel, unsigned char* pLock)
{
	return TUNER_CTRL_OK;
}

int ADemod_GetCarrierOffset(ADEMOD* pADemodKernel, long* pOffset)
{
	*pOffset = 0;
	return TUNER_CTRL_OK;
}
int ADemod_GetSignalQuality(ADEMOD* pADemodKernel, ENUM_TV_QUAL id, TV_SIG_QUAL* pQuality)
{
	return TUNER_CTRL_OK;
}

int ADemod_AcquireSignal(ADEMOD* pADemodKernel, unsigned char WaitSignalLock)
{
	return TUNER_CTRL_OK;
}

int ADemod_GetSignalInfo(ADEMOD* pADemodKernel, TV_SIG_INFO* pInfo)
{
	return TUNER_CTRL_OK;
}

unsigned long ADemod_GetCapability(ADEMOD* pADemodKernel)
{
	return pADemodKernel->m_Capability;
}

int ADemod_Suspend(ADEMOD* pADemodKernel)
{
	return TUNER_CTRL_OK;
}

int ADemod_Resume(ADEMOD* pADemodKernel)
{
	return TUNER_CTRL_OK;
}

int ADemod_InspectSignal(ADEMOD* pADemodKernel, char* pBuff, unsigned long BufferSize)      // Add monitor function that used to monitor demod status
{
	unsigned char  lock;
	//float          snr;
	//float          ber;
	//TV_SIG_QUAL    quality;

	pADemodKernel->GetLockStatus(pADemodKernel, &lock);
	//return snprintf(pBuff, BufferSize, "lock=%d", lock);
	return 1;
}

void ADemod_AttachTuner(ADEMOD* pADemodKernel, TUNER* pTuner)
{
	pADemodKernel->m_pTuner = pTuner;
}

void ADemod_Lock(ADEMOD* pADemodKernel)
{
	//mutex_lock(&pADemodKernel->m_lock);
}

void ADemod_Unlock(ADEMOD* pADemodKernel)
{
	//mutex_unlock(&pADemodKernel->m_lock);
}
