/* #include <Application/AppClass/channeldef.h> */
#include <linux/kernel.h>
#include <linux/slab.h>
#include "tv_osal.h"
#include "rtk_tv_fe_types.h"
#include "tv_fe_aux.h"
#include "comm.h"
#include "tuner.h"

void Tuner_Constructors(TUNER* pTunerKernel)
{
	pTunerKernel->m_addr			= 0;
	pTunerKernel->m_id			= TV_TUNER_NO_TUNER;
	pTunerKernel->m_capability	= TV_SYSTEM_TYPE_DVB | TV_SYSTEM_TYPE_ATSC;
	pTunerKernel->m_pComm 		= NULL;
	pTunerKernel->m_tv_sys		= TV_SYS_UNKNOWN;
	pTunerKernel->m_freq			= 0;
	pTunerKernel->m_op_mode		= TV_OP_MODE_NORMAL;
	pTunerKernel->DemodParamEn	= 0;

	pTunerKernel->TunerParam.if_inversion = 0;
	pTunerKernel->TunerParam.if_agc_pola = 0;
	pTunerKernel->TunerParam.if_freq = 5000000;

	pTunerKernel->Init = Tuner_Init;
	pTunerKernel->Reset = Tuner_Reset;
	pTunerKernel->SetTuner = Tuner_SetTuner;
	pTunerKernel->SetTunerEx = Tuner_SetTunerEx;
	pTunerKernel->GetParam = Tuner_GetParam;
	pTunerKernel->Destory = Tuner_Destructors;
}

void Tuner_Destructors(TUNER* pDemodKernel)
{
}


int Tuner_GetParam(TUNER* pTunerKernel, TV_SYSTEM sys, TUNER_PARAM *pParam)
{
	pParam->id = pTunerKernel->TunerParam.id;
	pParam->std = pTunerKernel->TunerParam.std;
	pParam->step_freq = pTunerKernel->TunerParam.step_freq;
	pParam->if_freq = pTunerKernel->TunerParam.if_freq;
	pParam->if_inversion = pTunerKernel->TunerParam.if_inversion;
	pParam->if_agc_pola = pTunerKernel->TunerParam.if_agc_pola;
	pParam->min_freq = pTunerKernel->TunerParam.min_freq;
	pParam->max_freq = pTunerKernel->TunerParam.max_freq;
	pParam->lowband_midband_limit_freq = pTunerKernel->TunerParam.lowband_midband_limit_freq;
	pParam->midband_highband_limit_freq = pTunerKernel->TunerParam.midband_highband_limit_freq;
	return TUNER_CTRL_OK;
}

int Tuner_Init(TUNER* pTunerKernel)
{
	return TUNER_CTRL_OK;
}

int Tuner_Reset(TUNER* pTunerKernel)
{
	return TUNER_CTRL_OK;
}

int Tuner_SetTuner(TUNER* pTunerKernel, unsigned long freq, TV_SYSTEM sys)
{
	return TUNER_CTRL_OK;
}

int Tuner_SetTunerEx(TUNER* pTunerKernel, unsigned long freq, TV_SYSTEM sys, const TV_SIG_INFO *pSigInfo)
{
	return pTunerKernel->SetTuner(pTunerKernel, freq, sys);
}

