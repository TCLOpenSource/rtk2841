/***************************************************************************************************
  File        : demod_rtk_all.cpp
  Description : REALTEK_ALL demod
  Author      : Kevin Wang
****************************************************************************************************
    Update List :
----------------------------------------------------------------------------------------------------
    20120312   | create phase
***************************************************************************************************/
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <mach/io.h>
#include <linux/sched.h>
#include <linux/kthread.h>
#include "demod.h"
#include "demod_rtk_all.h"
#include "demod_rtk_atsc.h"
#include "demod_rtk_qam.h"
#include "demod_rtk_dvbt.h"
#include "demod_rtk_dvbt2.h"
#include "demod_rtk_dvbs.h"
#include "demod_rtk_dvbs2.h"
#include "demod_rtk_dvbc.h"
#include "demod_rtk_dtmb.h"
#include "demod_rtk_isdbt.h"
#include "demod_rtk_atv.h"
#include "demod_rtk_common.h"
#include "diseqc_rtk.h"
#include <rtk_kdriver/rtk_diseqc.h>
#include "rbus/dtv_frontend_reg.h"
#include "rbus/pll27x_reg_reg.h"

#define SUPPORT_DEMOD_AUTOTEST
#define NOT_SUPPORT_DVBS_AUTOTEST

#ifdef SUPPORT_DEMOD_AUTOTEST
TV_SIG_INFO SigInfo;
TV_SIG_QUAL SigQuality;
#endif

extern unsigned char TunerInputMode;
/*----------------------------------------------------------------------
 * Func : REALTEK_ALL_Constructors
 *
 * Desc : constructor
 *
 * Parm : device_addr : device address
 *        output_mode : REALTEK_ALL_OUT_IF_SERIAL / REALTEK_ALL_OUT_IF_PARALLEL
 *        output_freq : REALTEK_ALL_OUT_FREQ_6M / REALTEK_ALL_OUT_FREQ_10M
 *        pComm       : hadle of COMM
 *
 * Retn : handle of demod
 *----------------------------------------------------------------------*/

void REALTEK_ALL_Constructors(DEMOD* pDemodKernel, unsigned char addr, unsigned char output_mode, unsigned char output_freq, COMM* pComm)
{
	DEMOD_CALLER(" REALTEK_ALL_Constructors\n");
	REALTEK_ALL* pRealtekAll;

	pDemodKernel->private_data = kmalloc(sizeof(REALTEK_ALL), GFP_KERNEL);
	pRealtekAll = (REALTEK_ALL*)(pDemodKernel->private_data);

	Demod_Constructors(pDemodKernel);

	pDemodKernel->m_id                 = DTV_DEMOD_REALTEK_ALL;
	pDemodKernel->m_addr               = addr;
	pDemodKernel->m_pTuner             = NULL;
	pDemodKernel->m_pComm              = pComm;
	pRealtekAll->m_pDemod             = NULL;
	pRealtekAll->m_pATSCDemod         = NULL;
	pRealtekAll->m_pQAMDemod         = NULL;
	pRealtekAll->m_pDVBTDemod         = NULL;
	pRealtekAll->m_pDVBT2Demod         = NULL;
	pRealtekAll->m_pDVBSDemod         = NULL;
	pRealtekAll->m_pDVBS2Demod         = NULL;
	pRealtekAll->m_pDVBCDemod         = NULL;
	pRealtekAll->m_pDTMBDemod         = NULL;
	pRealtekAll->m_pISDBTDemod         = NULL;
	pRealtekAll->m_pATVDemod         	= NULL;
	pDemodKernel->m_ScanRange          = SCAN_RANGE_3_6;
	pDemodKernel->m_Capability         = TV_SYS_TYPE_ATSC | TV_SYS_TYPE_OPENCABLE | TV_SYS_TYPE_DVBT | TV_SYS_TYPE_DVBC | TV_SYS_TYPE_DTMB | TV_SYS_TYPE_ISDBT;
	pDemodKernel->m_update_interval_ms = 300;
	pDemodKernel->m_if.freq            = 36125000;
	pDemodKernel->m_if.inversion       = 0;
	pDemodKernel->m_if.agc_pola        = 0;

	pRealtekAll->m_output_mode        = output_mode;
	pRealtekAll->m_mode               = RTK_DEMOD_MODE_NONE;
	pRealtekAll->m_output_freq        = output_freq;
	pDemodKernel->m_ts.mode            = (pRealtekAll->m_output_mode == RTK_DEMOD_OUT_IF_PARALLEL) ? PARALLEL_MODE : SERIAL_MODE;
	pDemodKernel->m_ts.data_order      = MSB_D7;
	pDemodKernel->m_ts.datapin         = MSB_FIRST;
	pDemodKernel->m_ts.err_pol         = ACTIVE_HIGH;
	pDemodKernel->m_ts.sync_pol        = ACTIVE_HIGH;
	pDemodKernel->m_ts.val_pol         = ACTIVE_HIGH;
	pDemodKernel->m_ts.clk_pol         = FALLING_EDGE;
	pDemodKernel->m_ts.internal_demod_input = 1;
	pDemodKernel->m_ts.tsOutEn = 1;
	pDemodKernel->m_tv_sys = TV_SYS_UNKNOWN;

	pDemodKernel->Init = REALTEK_ALL_Init;
	pDemodKernel->Reset = Demod_Reset;
	pDemodKernel->AcquireSignal = REALTEK_ALL_AcquireSignal;
	pDemodKernel->ScanSignal = REALTEK_ALL_ScanSignal;
	pDemodKernel->SetIF = REALTEK_ALL_SetIF;
	pDemodKernel->SetTSMode = REALTEK_ALL_SetTSMode;
	pDemodKernel->SetTVSysEx = REALTEK_ALL_SetTVSysEx;
	pDemodKernel->SetMode = REALTEK_ALL_SetMode;
	pDemodKernel->SetTVSys = REALTEK_ALL_SetTVSys;
	pDemodKernel->GetLockStatus = REALTEK_ALL_GetLockStatus;
	pDemodKernel->GetSegmentNum = Demod_GetSegmentNum;
	pDemodKernel->GetSignalInfo = REALTEK_ALL_GetSignalInfo;
	pDemodKernel->GetSignalQuality = REALTEK_ALL_GetSignalQuality;
	pDemodKernel->ChangeT2PLP = REALTEK_ALL_ChangeT2PLP;
	pDemodKernel->GetT2PLPInfo = REALTEK_ALL_GetT2PLPInfo;
	pDemodKernel->GetT2L1PreInfo = Demod_GetT2L1PreInfo;
	pDemodKernel->GetT2L1PostInfo = Demod_GetT2L1PostInfo;
	pDemodKernel->GetDemodStatus = Demod_GetDemodStatus;
	pDemodKernel->GetCarrierOffset = REALTEK_ALL_GetCarrierOffset;
	pDemodKernel->GetChannelInfo = REALTEK_ALL_GetChannelInfo;
	pDemodKernel->GetDebugLogBuf = REALTEK_ALL_GetDebugLogBuf;
	pDemodKernel->ForwardI2C = REALTEK_ALL_ForwardI2C;
	pDemodKernel->AutoTune = REALTEK_ALL_AutoTune;
	//pDemodKernel->KernelAutoTune = REALTEK_ALL_KernelAutoTune;
	pDemodKernel->GetCapability = Demod_GetCapability;
	pDemodKernel->Suspend = REALTEK_ALL_Suspend;
	pDemodKernel->Resume = REALTEK_ALL_Resume;
	pDemodKernel->SetTvMode = REALTEK_ALL_SetTvMode;
	pDemodKernel->DebugInfo = REALTEK_ALL_DebugInfo;
	pDemodKernel->InspectSignal = REALTEK_ALL_InspectSignal;	  // Add monitor function that used to monitor demod status
	pDemodKernel->AttachTuner = Demod_AttachTuner;
	pDemodKernel->GetTSParam = Demod_GetTSParam;
	pDemodKernel->GetDemodInfo = REALTEK_ALL_GetDemodInfo;
	pDemodKernel->Lock = Demod_Lock;
	pDemodKernel->Unlock = Demod_Unlock;
	pDemodKernel->GetRegCmd = REALTEK_ALL_GetRegCmd;
	pDemodKernel->SetRegCmd = REALTEK_ALL_SetRegCmd;

	pDemodKernel->SetDiseqcContinue22kOnOff = REALTEK_ALL_Diseqc_SetDiseqcContinue22kOnOff;
	pDemodKernel->SetDiseqcCmd = REALTEK_ALL_Diseqc_SetDiseqcCmd;
	pDemodKernel->SetDiseqcToneBurst = REALTEK_ALL_Diseqc_SetDiseqcToneBurst;
	pDemodKernel->SetTunerInputMode = REALTEK_ALL_SetTunerInputMode;

	pDemodKernel->BlindScan_Init = REALTEK_ALL_BlindScan_Init;
	pDemodKernel->BlindScan_GetTunerFreq = REALTEK_ALL_BlindScan_GetTunerFreq;
	pDemodKernel->BlindScan_NextFreq = REALTEK_ALL_BlindScan_NextFreq;
	pDemodKernel->BlindScan_GetStatus = REALTEK_ALL_BlindScan_GetStatus;
	pDemodKernel->BlindScan_End = REALTEK_ALL_BlindScan_End;
	pDemodKernel->BlindScan_GetFoundTP = REALTEK_ALL_BlindScan_GetFoundTP;
	pDemodKernel->BlindScan_AcquireSignal = REALTEK_ALL_BlindScan_AcquireSignal;

	pRealtekAll->Destory = REALTEK_ALL_Destructors;
	pRealtekAll->m_KernelAutoTuneThread_start = 0;
	pRealtekAll->demod_kernelthread = NULL;
	pRealtekAll->m_kernel_auto_tune_en = 0;
	pRealtekAll->m_auto_tune_en = 0;

#ifdef CONFIG_RTK_KDRV_DEMOD_SCAN_THREAD_ENABLE
	REALTEK_ALL_KernelThread_EN(pDemodKernel, 1);
#endif

}



/*----------------------------------------------------------------------
 * Func :REALTEK_ALL_Destructors
 *
 * Desc : Destructor of REALTEK_ALL
 *
 * Parm : pDemod : handle of Demod
 *
 * Retn : N/A
 *----------------------------------------------------------------------*/
void REALTEK_ALL_Destructors(DEMOD* pDemodKernel)
{
	REALTEK_ALL* pRealtekAll;

	DEMOD_CALLER(" REALTEK_ALL_Destructors\n");

	pRealtekAll = (REALTEK_ALL*)(pDemodKernel->private_data);

#ifdef CONFIG_RTK_KDRV_DEMOD_SCAN_THREAD_ENABLE
	REALTEK_ALL_KernelThread_EN(pDemodKernel, 0);
#endif

	pDemodKernel->Lock(pDemodKernel);

	pRealtekAll->m_mode               = RTK_DEMOD_MODE_NONE;

	if (pRealtekAll->m_pATSCDemod != NULL)
		pRealtekAll->m_pATSCDemod->Destory(pRealtekAll->m_pATSCDemod);

	if (pRealtekAll->m_pQAMDemod != NULL)
		pRealtekAll->m_pQAMDemod->Destory(pRealtekAll->m_pQAMDemod);

	if (pRealtekAll->m_pDVBTDemod != NULL)
		pRealtekAll->m_pDVBTDemod->Destory(pRealtekAll->m_pDVBTDemod);

	if (pRealtekAll->m_pDVBT2Demod != NULL)
		pRealtekAll->m_pDVBT2Demod->Destory(pRealtekAll->m_pDVBT2Demod);

	if (pRealtekAll->m_pDVBSDemod != NULL)
		pRealtekAll->m_pDVBSDemod->Destory(pRealtekAll->m_pDVBSDemod);

	if (pRealtekAll->m_pDVBS2Demod != NULL)
		pRealtekAll->m_pDVBS2Demod->Destory(pRealtekAll->m_pDVBS2Demod);

	if (pRealtekAll->m_pDVBCDemod != NULL)
		pRealtekAll->m_pDVBCDemod->Destory(pRealtekAll->m_pDVBCDemod);

	if (pRealtekAll->m_pDTMBDemod != NULL)
		pRealtekAll->m_pDTMBDemod->Destory(pRealtekAll->m_pDTMBDemod);

	if (pRealtekAll->m_pISDBTDemod != NULL)
		pRealtekAll->m_pISDBTDemod->Destory(pRealtekAll->m_pISDBTDemod);

	if (pRealtekAll->m_pATVDemod != NULL)
		pRealtekAll->m_pATVDemod->Destory(pRealtekAll->m_pATVDemod);

	pDemodKernel->Unlock(pDemodKernel);

	kfree(pRealtekAll);

	pDemodKernel->Destory(pDemodKernel);
}


int REALTEK_ALL_SetTVSys(DEMOD* pDemodKernel, TV_SYSTEM sys)
{
	DEMOD_CALLER("REALTEK_ALL_SetTVSys");
	return TUNER_CTRL_OK;
}


/*----------------------------------------------------------------------
 * Func : Init
 *
 * Desc : Initial REAKTEK_I
 *
 * Parm : N/A
 *
 * Retn : TUNER_CTRL_OK / TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_ALL_Init(DEMOD* pDemodKernel)
{
	DEMOD_CALLER(" REALTEK_ALL_Init\n");
	return TUNER_CTRL_OK;
}



/*----------------------------------------------------------------------
 * Func : SetTVSys
 *
 * Desc : Set TV System
 *
 * Parm : sys : TV System
 *
 * Retn : TUNER_CTRL_OK / TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_ALL_SetTVSysEx(DEMOD* pDemodKernel, TV_SYSTEM sys, const TV_SIG_INFO* pSigInfo)
{

	REALTEK_ALL* pRealtekAll;
	//TUNER_PARAM TunerParm;
	int ret = TUNER_CTRL_OK;
	TV_SYSTEM_TYPE TvSysMode;

	pRealtekAll = (REALTEK_ALL*)(pDemodKernel->private_data);

	if (pRealtekAll->m_mode == RTK_DEMOD_MODE_NONE) {
		DEMOD_INFO("\033[0;32;31m""DEMOD need init first !!!!! demod mode=%d\n""\033[m" , pRealtekAll->m_mode);
		return TUNER_CTRL_FAIL;
	}

	//int pri_mode = pRealtekAll->m_mode;

	pRealtekAll->m_kernel_auto_tune_en = 0;
	pRealtekAll->m_auto_tune_en = 0;

	DEMOD_INFO("REALTEK_ALL_SetTVSysEx: system type=%d\n", sys);

	if (IsDvbs2Sys(sys) || IsDvbsSys(sys)) {

		GetDemodTvSysMode(&TvSysMode);
		if (TvSysMode != TV_SYS_TYPE_DVBS && TvSysMode != TV_SYS_TYPE_DVBS2) {
			REALTEK_ALL_SetTvMode(pDemodKernel, TV_SYS_TYPE_DVBS2);
		}
	}
	pDemodKernel->Lock(pDemodKernel);

	ret = pRealtekAll->m_pDemod->SetTVSysEx(pRealtekAll->m_pDemod, sys, pSigInfo);

	pDemodKernel->Unlock(pDemodKernel);

	if (ret == TUNER_CTRL_OK)
		pDemodKernel->m_tv_sys = sys;


	pRealtekAll->m_kernel_auto_tune_en = 1;
	pRealtekAll->m_auto_tune_en = 1;

	return ret;
}



/*----------------------------------------------------------------------
 * Func : SetIF
 *
 * Desc : Set IF Parameter
 *
 * Parm : pParam : IF Param
 *
 * Retn : TUNER_CTRL_OK / TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_ALL_SetIF(DEMOD* pDemodKernel, IF_PARAM* pParam)
{
	int ret = TUNER_CTRL_FAIL;
	REALTEK_ALL* pRealtekAll;
	DEMOD_CALLER(" REALTEK_ALL_SetIF\n");

	pRealtekAll = (REALTEK_ALL*)(pDemodKernel->private_data);

	if (pRealtekAll->m_mode == RTK_DEMOD_MODE_NONE) {
		DEMOD_INFO("\033[0;32;31m""DEMOD need init first !!!!! demod mode=%d\n""\033[m" , pRealtekAll->m_mode);
		return TUNER_CTRL_FAIL;
	}

	pDemodKernel->Lock(pDemodKernel);

	pDemodKernel->m_if = *pParam;

	if (pRealtekAll->m_pDemod)
		ret = pRealtekAll->m_pDemod->SetIF(pRealtekAll->m_pDemod, pParam);
	pDemodKernel->Unlock(pDemodKernel);
	return ret;
}



/*----------------------------------------------------------------------
 * Func : SetMode
 *
 * Desc : Set operation mode of demod
 *
 * Parm : mode : Demod opreation mode
 *
 * Retn : TUNER_CTRL_OK / TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_ALL_SetMode(DEMOD* pDemodKernel, TV_OP_MODE mode)
{
	REALTEK_ALL* pRealtekAll;
	DEMOD_CALLER(" REALTEK_ALL_SetMode\n");

	pRealtekAll = (REALTEK_ALL*)(pDemodKernel->private_data);

	if (pRealtekAll->m_mode == RTK_DEMOD_MODE_NONE) {
		DEMOD_INFO("\033[0;32;31m""DEMOD need init first !!!!! demod mode=%d\n""\033[m" , pRealtekAll->m_mode);
		return TUNER_CTRL_FAIL;
	}

	switch (mode) {
	case TV_OP_MODE_NORMAL:
	case TV_OP_MODE_SCANING:
		DEMOD_INFO("REALTEK_ALL_SetMode:TV_OP_MODE_NORMAL\n");
		//[todd] need implement
		//if (DtvDemodClockEnable(1))       // reenabler demod clock
		//	pDemodKernel->AcquireSignal(pDemodKernel, 0);        // reset demod....
		break;

	case TV_OP_MODE_STANDBY:
		//[todd] need implement

		DEMOD_INFO("REALTEK_ALL_SetMode:TV_OP_MODE_STANDBY\n");
		//DtvDemodClockEnable(0);          // suspend demod clock
		break;

	case TV_OP_MODE_ATV_NORMAL:
	case TV_OP_MODE_TP_ONLY:
		DEMOD_WARNING("REALTEK_ALL_SetMode: NOT DTV MODE; %s(line%d)\n", __FILE__, __LINE__);
		break;
	}
	return TUNER_CTRL_OK;
}



/*----------------------------------------------------------------------
 * Func : SetTSMode
 *
 * Desc : Set mode of transport stream output
 *
 * Parm : pParam : TS Param
 *
 * Retn : TUNER_CTRL_OK / TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_ALL_SetTSMode(DEMOD* pDemodKernel, TS_PARAM* pParam)
{
	REALTEK_ALL* pRealtekAll;
	int ret = TUNER_CTRL_FAIL;
	DEMOD_CALLER(" REALTEK_ALL_SetTSMode\n");

	pRealtekAll = (REALTEK_ALL*)(pDemodKernel->private_data);

	if (pRealtekAll->m_mode == RTK_DEMOD_MODE_NONE) {
		DEMOD_INFO("\033[0;32;31m""DEMOD need init first !!!!! demod mode=%d\n""\033[m" , pRealtekAll->m_mode);
		return TUNER_CTRL_FAIL;
	}


	pDemodKernel->Lock(pDemodKernel);

	if (pRealtekAll->m_pDemod && pRealtekAll->m_pDemod->SetTSMode(pRealtekAll->m_pDemod, pParam) == TUNER_CTRL_OK) {
		pDemodKernel->m_ts = *pParam;
		ret = TUNER_CTRL_OK;
	}
	pDemodKernel->Unlock(pDemodKernel);
	return ret;
}



/*----------------------------------------------------------------------
 * Func : GetLockStatus
 *
 * Desc : Get Demod Lock Status
 *
 * Parm : pLock : Lock Status
 *
 * Retn : TUNER_CTRL_OK / TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_ALL_GetLockStatus(DEMOD* pDemodKernel, unsigned char* pLock)
{
	REALTEK_ALL* pRealtekAll;
	int ret = TUNER_CTRL_FAIL;
	DEMOD_CALLER(" REALTEK_ALL_GetLockStatus\n");
	pRealtekAll = (REALTEK_ALL*)(pDemodKernel->private_data);

	if (pRealtekAll->m_mode == RTK_DEMOD_MODE_NONE) {
		DEMOD_INFO("\033[0;32;31m""DEMOD need init first !!!!! demod mode=%d\n""\033[m" , pRealtekAll->m_mode);
		return TUNER_CTRL_FAIL;
	}

	pDemodKernel->Lock(pDemodKernel);
	if (pRealtekAll->m_pDemod)
		ret = pRealtekAll->m_pDemod->GetLockStatus(pRealtekAll->m_pDemod, pLock);
	pDemodKernel->Unlock(pDemodKernel);
	return ret;
}



/*----------------------------------------------------------------------
 * Func : GetSignalInfo
 *
 * Desc : Get Signal Information
 *
 * Parm : pInfo : Siganl Information
 *
 * Retn : TUNER_CTRL_OK / TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_ALL_GetSignalInfo(DEMOD* pDemodKernel, TV_SIG_INFO* pInfo)
{
	int ret = TUNER_CTRL_FAIL;
	REALTEK_ALL* pRealtekAll;
	DEMOD_CALLER(" REALTEK_ALL_GetSignalInfo\n");
	pRealtekAll = (REALTEK_ALL*)(pDemodKernel->private_data);

	if (pRealtekAll->m_mode == RTK_DEMOD_MODE_NONE) {
		DEMOD_INFO("\033[0;32;31m""DEMOD need init first !!!!! demod mode=%d\n""\033[m" , pRealtekAll->m_mode);
		return TUNER_CTRL_FAIL;
	}

	pDemodKernel->Lock(pDemodKernel);
	if (pRealtekAll->m_pDemod)
		ret = pRealtekAll->m_pDemod->GetSignalInfo(pRealtekAll->m_pDemod, pInfo);
	pDemodKernel->Unlock(pDemodKernel);
	return ret;
}

int REALTEK_ALL_ChangeT2PLP(DEMOD* pDemodKernel, TV_SIG_INFO* pInfo)
{
	int ret = TUNER_CTRL_FAIL;
	REALTEK_ALL* pRealtekAll;
	DEMOD_CALLER(" REALTEK_ALL_ChangeT2PLP\n");
	pRealtekAll = (REALTEK_ALL*)(pDemodKernel->private_data);

	if (pRealtekAll->m_mode == RTK_DEMOD_MODE_NONE) {
		DEMOD_INFO("\033[0;32;31m""DEMOD need init first !!!!! demod mode=%d\n""\033[m" , pRealtekAll->m_mode);
		return TUNER_CTRL_FAIL;
	}

	pDemodKernel->Lock(pDemodKernel);

	if ((IsDvbt2Sys(pDemodKernel->m_tv_sys) == 1) || (IsDvbtSys(pDemodKernel->m_tv_sys) == 1)) {

		if (pRealtekAll->m_pDemod)
			ret = pRealtekAll->m_pDemod->ChangeT2PLP(pRealtekAll->m_pDemod, pInfo);

	} else {

		ret = TUNER_CTRL_OK;
		DEMOD_WARNING(" REALTEK_ALL_ChangeT2PLP but tv system is not DVBT2; sys=%d\n", pDemodKernel->m_tv_sys);
	}


	pDemodKernel->Unlock(pDemodKernel);


	return ret;
}

int REALTEK_ALL_GetT2PLPInfo(DEMOD* pDemodKernel, TV_SIG_INFO* pInfo)
{
	int ret = TUNER_CTRL_FAIL;
	REALTEK_ALL* pRealtekAll;
	DEMOD_CALLER(" REALTEK_ALL_GetT2PLPInfo\n");
	pRealtekAll = (REALTEK_ALL*)(pDemodKernel->private_data);

	if (pRealtekAll->m_mode == RTK_DEMOD_MODE_NONE) {
		DEMOD_INFO("\033[0;32;31m""DEMOD need init first !!!!! demod mode=%d\n""\033[m" , pRealtekAll->m_mode);
		return TUNER_CTRL_FAIL;
	}

	pDemodKernel->Lock(pDemodKernel);


	if (IsDvbtSys(pDemodKernel->m_tv_sys) == 1 || IsDvbt2Sys(pDemodKernel->m_tv_sys) == 1) {

		if (pRealtekAll->m_pDemod)
			ret = pRealtekAll->m_pDemod->GetT2PLPInfo(pRealtekAll->m_pDemod, pInfo);

	} else {

		ret = TUNER_CTRL_OK;
		DEMOD_WARNING(" REALTEK_ALL_GetT2PLPInfo but tv system is not DVBT2; sys=%d\n", pDemodKernel->m_tv_sys);
	}


	pDemodKernel->Unlock(pDemodKernel);


	return ret;
}


/*----------------------------------------------------------------------
 * Func : GetSignalQuality
 *
 * Desc : Get Signal Information
 *
 * Parm : id : Type of Quality Information
 *        pQuality : Siganl Quality
 *
 * Retn : TUNER_CTRL_OK / TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_ALL_GetSignalQuality(DEMOD* pDemodKernel, ENUM_TV_QUAL id, TV_SIG_QUAL* pQuality)
{
	int ret = TUNER_CTRL_FAIL;
	REALTEK_ALL* pRealtekAll;
	DEMOD_CALLER(" REALTEK_ALL_GetSignalQuality\n");
	pRealtekAll = (REALTEK_ALL*)(pDemodKernel->private_data);

	if (pRealtekAll->m_mode == RTK_DEMOD_MODE_NONE) {
		DEMOD_INFO("\033[0;32;31m""DEMOD need init first !!!!! demod mode=%d\n""\033[m" , pRealtekAll->m_mode);
		return TUNER_CTRL_FAIL;
	}


#ifdef SUPPORT_DEMOD_AUTOTEST
	if (PLL27X_REG_IFADC_1_get_pll27x_ifadc_dtv_cko_en(rtd_inl(PLL27X_REG_IFADC_1_reg)) == 0x1) {

		if (((rtd_inl(DTV_FRONTEND_DTV_FRONTEND_DUMMY5_reg) >> 31) & 0x1) == 0x1)
			return TUNER_CTRL_OK;

	}

#endif

	pDemodKernel->Lock(pDemodKernel);
	if (pRealtekAll->m_pDemod)
		ret = pRealtekAll->m_pDemod->GetSignalQuality(pRealtekAll->m_pDemod, id, pQuality);
	pDemodKernel->Unlock(pDemodKernel);
	return ret;
}


/*----------------------------------------------------------------------
 * Func : GetChannelInfo
 *
 * Desc : Get the channel info.
 *
 * Parm : 
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_ALL_GetChannelInfo(DEMOD* pDemodKernel, unsigned char* Standard, unsigned char* Modulation, unsigned char* CodeRate, unsigned char* PilotOnOff, unsigned char* Inverse)
{
	int ret = TUNER_CTRL_FAIL;
	REALTEK_ALL* pRealtekAll;
	DEMOD_CALLER(" REALTEK_ALL_GetChannelInfo\n");
	pRealtekAll = (REALTEK_ALL*)(pDemodKernel->private_data);

	pDemodKernel->Lock(pDemodKernel);
	if (pRealtekAll->m_pDemod)
		ret = pRealtekAll->m_pDemod->GetChannelInfo(pRealtekAll->m_pDemod, Standard, Modulation, CodeRate, PilotOnOff, Inverse);
	pDemodKernel->Unlock(pDemodKernel);
	return ret;
}


/*----------------------------------------------------------------------
 * Func : GetCarrierOffset
 *
 * Desc : Get the carrier offset.
 *
 * Parm : pOffset : carrier frequency offset output (unit : Hz)
 *
 *          Note: the offset value is only valid as demod is on lock stage.
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_ALL_GetCarrierOffset(DEMOD* pDemodKernel, long* pOffset)
{
	int ret = TUNER_CTRL_FAIL;
	REALTEK_ALL* pRealtekAll;
	DEMOD_CALLER(" REALTEK_ALL_GetCarrierOffset\n");
	pRealtekAll = (REALTEK_ALL*)(pDemodKernel->private_data);

	if (pRealtekAll->m_mode == RTK_DEMOD_MODE_NONE) {
		DEMOD_INFO("\033[0;32;31m""DEMOD need init first !!!!! demod mode=%d\n""\033[m" , pRealtekAll->m_mode);
		return TUNER_CTRL_FAIL;
	}

	pDemodKernel->Lock(pDemodKernel);
	if (pRealtekAll->m_pDemod)
		ret = pRealtekAll->m_pDemod->GetCarrierOffset(pRealtekAll->m_pDemod, pOffset);
	pDemodKernel->Unlock(pDemodKernel);
	return ret;
}
/*----------------------------------------------------------------------
 * Func : GetDebugLogBuf
 *
 * Desc : Get the debug log Buf.
 *
 * Parm :
 *
 *
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_ALL_GetDebugLogBuf(DEMOD* pDemodKernel, unsigned int* LogBufAddr, unsigned int* LogBufSize)
{
	int ret = TUNER_CTRL_FAIL;
	REALTEK_ALL* pRealtekAll;

	pRealtekAll = (REALTEK_ALL*)(pDemodKernel->private_data);

	if (pRealtekAll->m_mode == RTK_DEMOD_MODE_NONE) {
		DEMOD_INFO("\033[0;32;31m""DEMOD need init first !!!!! demod mode=%d\n""\033[m" , pRealtekAll->m_mode);
		return TUNER_CTRL_FAIL;
	}

	pDemodKernel->Lock(pDemodKernel);
	if (pRealtekAll->m_pDemod)
		ret = pRealtekAll->m_pDemod->GetDebugLogBuf(pRealtekAll->m_pDemod, LogBufAddr, LogBufSize);
	pDemodKernel->Unlock(pDemodKernel);

	return ret;
}


/*----------------------------------------------------------------------
 * Func : AcquireSignal
 *
 * Desc : Reset Demodulator and Acquire Signal.
 *        This function should be called when channel changed.
 *
 * Parm : WaitSignalLock : wait until signal lock
 *          0 : don't wait,
 *          others: wait for signal lock
 *
 * Retn : TUNER_CTRL_OK / TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_ALL_AcquireSignal(DEMOD* pDemodKernel, unsigned char WaitSignalLock)
{
	int ret = TUNER_CTRL_FAIL;
	REALTEK_ALL* pRealtekAll;
	DEMOD_CALLER(" REALTEK_ALL_AcquireSignal\n");
	pRealtekAll = (REALTEK_ALL*)(pDemodKernel->private_data);

	if (pRealtekAll->m_mode == RTK_DEMOD_MODE_NONE) {
		DEMOD_INFO("\033[0;32;31m""DEMOD need init first !!!!! demod mode=%d\n""\033[m" , pRealtekAll->m_mode);
		return TUNER_CTRL_FAIL;
	}

	//pDemodKernel->Lock(pDemodKernel);
	if (pRealtekAll->m_pDemod)
		ret = pRealtekAll->m_pDemod->AcquireSignal(pRealtekAll->m_pDemod, WaitSignalLock);
	//pDemodKernel->Unlock(pDemodKernel);
	return ret;
}


/*----------------------------------------------------------------------
 * Func : SetDiseqcContinue22kOnOff
 *
 * Desc : Set Diseqc Continue 22k On/Off.
 *
 * Parm :
 *
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_ALL_Diseqc_SetDiseqcContinue22kOnOff(DEMOD* pDemodKernel, unsigned int OnOff)
{
	int ret = TUNER_CTRL_OK;
	REALTEK_ALL* pRealtekAll;
	DEMOD_CALLER(" REALTEK_ALL_Diseqc_SetDiseqcContinue22kOnOff\n");
	pRealtekAll = (REALTEK_ALL*)(pDemodKernel->private_data);
    
	pRealtekAll->m_kernel_auto_tune_en = 0;
	pRealtekAll->m_auto_tune_en = 0;

	//if (pRealtekAll->m_pDemod)
	//	ret = pRealtekAll->m_pDemod->SetDiseqcContinue22kOnOff(pRealtekAll->m_pDemod, OnOff);
	realtek_i_Diseqc_SetDiseqcContinue22kOnOff(OnOff);
    
	pRealtekAll->m_kernel_auto_tune_en = 1;
	pRealtekAll->m_auto_tune_en = 1;
    
	return ret;
}


/*----------------------------------------------------------------------
 * Func : SetDiseqcCmd
 *
 * Desc : Set Diseqc command
 *
 * Parm :
 *
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_ALL_Diseqc_SetDiseqcCmd(DEMOD* pDemodKernel, unsigned int Length, unsigned char *Data)
{
	int ret = TUNER_CTRL_OK;
	REALTEK_ALL* pRealtekAll;
	DEMOD_CALLER(" REALTEK_ALL_Diseqc_SetDiseqcCmd\n");
	pRealtekAll = (REALTEK_ALL*)(pDemodKernel->private_data);
    
	pRealtekAll->m_kernel_auto_tune_en = 0;
	pRealtekAll->m_auto_tune_en = 0;

	//if (pRealtekAll->m_pDemod)
	//	ret = pRealtekAll->m_pDemod->SetDiseqcCmd(pRealtekAll->m_pDemod, Length, Data);
	realtek_i_Diseqc_SetDiseqcCmd(Length, Data);
    
	pRealtekAll->m_kernel_auto_tune_en = 1;
	pRealtekAll->m_auto_tune_en = 1;
    
	return ret;
}


/*----------------------------------------------------------------------
 * Func :SetDiseqcToneBurst
 *
 * Desc : Set Diseqc tone burst
 *
 * Parm :
 *
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_ALL_Diseqc_SetDiseqcToneBurst(DEMOD* pDemodKernel, DISEQC_TONE_MODE mode)
{
	int ret = TUNER_CTRL_OK;
	REALTEK_ALL* pRealtekAll;
	DEMOD_CALLER(" REALTEK_ALL_Diseqc_SetToneBurst\n");
	pRealtekAll = (REALTEK_ALL*)(pDemodKernel->private_data);
    
	pRealtekAll->m_kernel_auto_tune_en = 0;
	pRealtekAll->m_auto_tune_en = 0;

	//if (pRealtekAll->m_pDemod)
	//	ret = pRealtekAll->m_pDemod->SetDiseqcToneBurst(pRealtekAll->m_pDemod, mode);
	realtek_i_Diseqc_SetDiseqcToneBurst(mode);
    
	pRealtekAll->m_kernel_auto_tune_en = 1;
	pRealtekAll->m_auto_tune_en = 1;
    
	return ret;
}


/*----------------------------------------------------------------------
 * Func : BlindScan_Init
 *
 * Desc : Initiate blindscan.
 *
 * Parm : StartFreqMhz : start frequency for blindscan (unit : Hz)
 *        EndFreqMhz : end frequency for blindscan (unit : Hz)
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_ALL_BlindScan_Init(DEMOD* pDemodKernel, unsigned int StartFreqMhz, unsigned int EndFreqMhz)
{
	int ret = TUNER_CTRL_FAIL;
	REALTEK_ALL* pRealtekAll;
	TV_SYSTEM_TYPE TvSysMode;
	DEMOD_CALLER(" REALTEK_ALL_BlindScan_Init\n");
	pRealtekAll = (REALTEK_ALL*)(pDemodKernel->private_data);

	GetDemodTvSysMode(&TvSysMode);
	if (TvSysMode != TV_SYS_TYPE_DVBS2) {
		REALTEK_ALL_SetTvMode(pDemodKernel, TV_SYS_TYPE_DVBS2);
	}

	pDemodKernel->Lock(pDemodKernel);

	//if (IsDvbs2Sys(pDemodKernel->m_tv_sys)) {

	if (pRealtekAll->m_pDemod)
		ret = pRealtekAll->m_pDemod->BlindScan_Init(pRealtekAll->m_pDemod, StartFreqMhz, EndFreqMhz);

	//} else {

	//ret = TUNER_CTRL_OK;
	//DEMOD_WARNING(" REALTEK_ALL_BlindScan_Init but tv system is not DVBS2; sys=%d\n", pDemodKernel->m_tv_sys);
	//}

	pDemodKernel->Unlock(pDemodKernel);

	return ret;
}


/*----------------------------------------------------------------------
 * Func : BlindScan_GetTunerFreq
 *
 * Desc : Get tuner frequency and tuner bandwidth for current blindscan step.
 *
 * Parm : TunerCenterFreqMhz : tuner frequency (unit : Hz)
 *        TunerCutOffFreqKhz : tuner bandwidth (unit : Hz)
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_ALL_BlindScan_GetTunerFreq(DEMOD* pDemodKernel, unsigned int *TunerCenterFreqMhz, unsigned int *TunerCutOffFreqKhz)
{
	int ret = TUNER_CTRL_FAIL;
	REALTEK_ALL* pRealtekAll;
	DEMOD_CALLER(" REALTEK_ALL_BlindScan_GetTunerFreq\n");
	pRealtekAll = (REALTEK_ALL*)(pDemodKernel->private_data);

	pDemodKernel->Lock(pDemodKernel);

	if (IsDvbs2Sys(pDemodKernel->m_tv_sys)) {

		if (pRealtekAll->m_pDemod)
			ret = pRealtekAll->m_pDemod->BlindScan_GetTunerFreq(pRealtekAll->m_pDemod, TunerCenterFreqMhz, TunerCutOffFreqKhz);

	} else {

		ret = TUNER_CTRL_OK;
		DEMOD_WARNING(" REALTEK_ALL_BlindScan_GetTunerFreq but tv system is not DVBS2; sys=%d\n", pDemodKernel->m_tv_sys);
	}

	pDemodKernel->Unlock(pDemodKernel);

	return ret;
}


/*----------------------------------------------------------------------
 * Func : BlindScan_NextFreq
 *
 * Desc : Check is blindscan done.
 *
 * Parm : bBlindScanEnd : Is blindscan done?
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_ALL_BlindScan_NextFreq(DEMOD* pDemodKernel, unsigned int *bBlindScanEnd)
{
	int ret = TUNER_CTRL_FAIL;
	REALTEK_ALL* pRealtekAll;
	DEMOD_CALLER(" REALTEK_ALL_BlindScan_NextFreq\n");
	pRealtekAll = (REALTEK_ALL*)(pDemodKernel->private_data);

	pDemodKernel->Lock(pDemodKernel);

	if (IsDvbs2Sys(pDemodKernel->m_tv_sys)) {

		if (pRealtekAll->m_pDemod)
			ret = pRealtekAll->m_pDemod->BlindScan_NextFreq(pRealtekAll->m_pDemod, bBlindScanEnd);

	} else {

		ret = TUNER_CTRL_OK;
		DEMOD_WARNING(" REALTEK_ALL_BlindScan_NextFreq but tv system is not DVBS2; sys=%d\n", pDemodKernel->m_tv_sys);
	}

	pDemodKernel->Unlock(pDemodKernel);

	return ret;
}


/*----------------------------------------------------------------------
 * Func : BlindScan_GetStatus
 *
 * Desc : Get blindscan status.
 *
 * Parm : Status : blindscan status
 *        bBlindScanLock : Does blindscan search a signal?
  *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_ALL_BlindScan_GetStatus(DEMOD* pDemodKernel, unsigned char *Status, unsigned int *bBlindScanLock)
{
	int ret = TUNER_CTRL_FAIL;
	REALTEK_ALL* pRealtekAll;
	DEMOD_CALLER(" REALTEK_ALL_BlindScan_GetStatus\n");
	pRealtekAll = (REALTEK_ALL*)(pDemodKernel->private_data);

	pDemodKernel->Lock(pDemodKernel);

	if (IsDvbs2Sys(pDemodKernel->m_tv_sys)) {

		if (pRealtekAll->m_pDemod)
			ret = pRealtekAll->m_pDemod->BlindScan_GetStatus(pRealtekAll->m_pDemod, Status, bBlindScanLock);

	} else {

		ret = TUNER_CTRL_OK;
		DEMOD_WARNING(" REALTEK_ALL_BlindScan_GetStatus but tv system is not DVBS2; sys=%d\n", pDemodKernel->m_tv_sys);
	}

	pDemodKernel->Unlock(pDemodKernel);

	return ret;
}


/*----------------------------------------------------------------------
 * Func : BlindScan_End
 *
 * Desc : End blindscan.
 *
 * Parm : N/A
  *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_ALL_BlindScan_End(DEMOD* pDemodKernel)
{
	int ret = TUNER_CTRL_FAIL;
	REALTEK_ALL* pRealtekAll;
	DEMOD_CALLER(" REALTEK_ALL_BlindScan_End\n");
	pRealtekAll = (REALTEK_ALL*)(pDemodKernel->private_data);

	pDemodKernel->Lock(pDemodKernel);

	if (IsDvbs2Sys(pDemodKernel->m_tv_sys)) {

		if (pRealtekAll->m_pDemod)
			ret = pRealtekAll->m_pDemod->BlindScan_End(pRealtekAll->m_pDemod);

	} else {

		ret = TUNER_CTRL_OK;
		DEMOD_WARNING(" REALTEK_ALL_BlindScan_End but tv system is not DVBS2; sys=%d\n", pDemodKernel->m_tv_sys);
	}

	pDemodKernel->Unlock(pDemodKernel);

	return ret;
}


/*----------------------------------------------------------------------
 * Func : BlindScan_GetFoundTP
 *
 * Desc : Get blindscan search result.
 *
 * Parm : FreqMhz : frequency of found TP (unit : MHz)
 *        SymbolRateKhz : symbol rate of found TP (unit : MHz)
  *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_ALL_BlindScan_GetFoundTP(DEMOD* pDemodKernel, unsigned int *FreqMhz, unsigned int *SymbolRateKhz)
{
	int ret = TUNER_CTRL_FAIL;
	REALTEK_ALL* pRealtekAll;
	DEMOD_CALLER(" REALTEK_ALL_BlindScan_GetFoundTP\n");
	pRealtekAll = (REALTEK_ALL*)(pDemodKernel->private_data);

	pDemodKernel->Lock(pDemodKernel);

	if (IsDvbs2Sys(pDemodKernel->m_tv_sys)) {

		if (pRealtekAll->m_pDemod)
			ret = pRealtekAll->m_pDemod->BlindScan_GetFoundTP(pRealtekAll->m_pDemod, FreqMhz, SymbolRateKhz);

	} else {

		ret = TUNER_CTRL_OK;
		DEMOD_WARNING(" REALTEK_ALL_BlindScan_End but tv system is not DVBS2; sys=%d\n", pDemodKernel->m_tv_sys);
	}

	pDemodKernel->Unlock(pDemodKernel);

	return ret;
}


/*----------------------------------------------------------------------
 * Func : BlindScan_AcquireSignal
 *
 * Desc : Acquire Signal in Blindscan
 *
 * Parm : 
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_ALL_BlindScan_AcquireSignal(DEMOD* pDemodKernel, unsigned int *SymbolRateKhz, int *Fcfo, unsigned char *bTpLock)
{
	int ret = TUNER_CTRL_FAIL;
	REALTEK_ALL* pRealtekAll;
	DEMOD_CALLER(" REALTEK_ALL_BlindScan_AcquireSignal\n");
	pRealtekAll = (REALTEK_ALL*)(pDemodKernel->private_data);

	pDemodKernel->Lock(pDemodKernel);

	//if (IsDvbs2Sys(pDemodKernel->m_tv_sys)) {

		if (pRealtekAll->m_pDemod)
			ret = pRealtekAll->m_pDemod->BlindScan_AcquireSignal(pRealtekAll->m_pDemod, SymbolRateKhz, Fcfo, bTpLock);

	//} else {

		//ret = TUNER_CTRL_OK;
		//DEMOD_WARNING(" REALTEK_ALL_BlindScan_AcquireSignal but tv system is not DVBS2; sys=%d\n", pDemodKernel->m_tv_sys);
	//}

	pDemodKernel->Unlock(pDemodKernel);

	return ret;
}


/*----------------------------------------------------------------------
 * Func : Suspend
 *
 * Desc : Set Mode of REALTEK_ALL
 *
 * Parm : mode :    RTK_DEMOD_MODE_DVBT : DVBT mode
 *                  RTK_DEMOD_MODE_DVBC  : DVBC mode
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_ALL_Suspend(DEMOD* pDemodKernel)
{
	int ret = TUNER_CTRL_OK;
	REALTEK_ALL* pRealtekAll;

	DEMOD_CALLER(" REALTEK_ALL_Suspend\n");

	pDemodKernel->Lock(pDemodKernel);
	pRealtekAll = (REALTEK_ALL*)(pDemodKernel->private_data);
	pRealtekAll->m_kernel_auto_tune_en = 0;
	pRealtekAll->m_auto_tune_en = 0;
	//if (pRealtekAll->m_pDemod)
	//	ret = pRealtekAll->m_pDemod->Suspend(pRealtekAll->m_pDemod);
	pDemodKernel->Unlock(pDemodKernel);
	return TUNER_CTRL_OK;
}


/*----------------------------------------------------------------------
 * Func : Resume
 *
 * Desc : Set Mode of REALTEK_ALL
 *
 * Parm : mode :    RTK_DEMOD_MODE_DVBT : DVBT mode
 *                  RTK_DEMOD_MODE_DVBC  : DVBC mode
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_ALL_Resume(DEMOD* pDemodKernel)
{
	int ret = TUNER_CTRL_OK;
	REALTEK_ALL* pRealtekAll;

	DEMOD_CALLER(" REALTEK_ALL_Resume\n");
	pRealtekAll = (REALTEK_ALL*)(pDemodKernel->private_data);

	pDemodKernel->Lock(pDemodKernel);
	pRealtekAll->m_kernel_auto_tune_en = 0;
	pRealtekAll->m_auto_tune_en = 0;
	if (pRealtekAll->m_pDemod)
		ret = pRealtekAll->m_pDemod->Resume(pRealtekAll->m_pDemod);
	pDemodKernel->Unlock(pDemodKernel);
	return TUNER_CTRL_OK;
}


/*----------------------------------------------------------------------
 * Func : ScanSignal
 *
 * Desc : Ask demodulator to Search signal within specified range
 *        This function should be called every time the channel changed.
 *
 * Parm : pOffset : Offset Output
 *        range   : Scan Range
 *          SCAN_RANGE_NONE : center only
 *          SCAN_RANGE_1_6  : (-)1/6 MHz
 *          SCAN_RANGE_2_6  : (-)2/6 MHz
 *          SCAN_RANGE_3_6  : (-)3/6 MHz
 *
 * Retn : TUNER_CTRL_OK        : signal found and locked
 *        TUNER_CTRL_FAIL      : error occured during scan channel
 *        TUNER_CTRL_NO_SIGNAL : no signal found in specified range
 *----------------------------------------------------------------------*/
int REALTEK_ALL_ScanSignal(DEMOD* pDemodKernel, long* pOffset, SCAN_RANGE range)
{
	int ret = TUNER_CTRL_FAIL;
	REALTEK_ALL* pRealtekAll;
	DEMOD_CALLER(" REALTEK_ALL_ScanSignal\n");
	pRealtekAll = (REALTEK_ALL*)(pDemodKernel->private_data);

	if (pRealtekAll->m_mode == RTK_DEMOD_MODE_NONE) {
		DEMOD_INFO("\033[0;32;31m""DEMOD need init first !!!!! demod mode=%d\n""\033[m" , pRealtekAll->m_mode);
		return TUNER_CTRL_FAIL;
	}

	pDemodKernel->Lock(pDemodKernel);
	if (pRealtekAll->m_pDemod)
		ret = pRealtekAll->m_pDemod->ScanSignal(pRealtekAll->m_pDemod, pOffset, range);
	pDemodKernel->Unlock(pDemodKernel);
	return ret;
}


/*----------------------------------------------------------------------
 * Func : ForwardI2C
 *
 * Desc :
 *
 * Parm :
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_ALL_ForwardI2C(DEMOD* pDemodKernel, unsigned char on_off)
{
	DEMOD_CALLER(" REALTEK_ALL_ForwardI2C\n");
	return TUNER_CTRL_OK;
}




/*----------------------------------------------------------------------
 * Func : AutoTune
 *
 * Desc :
 *
 * Parm :
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_ALL_AutoTune(DEMOD* pDemodKernel)
{
	int ret = TUNER_CTRL_OK;
	REALTEK_ALL* pRealtekAll;
	DEMOD_CALLER(" REALTEK_ALL_AutoTune\n");
	pRealtekAll = (REALTEK_ALL*)(pDemodKernel->private_data);

	if (pRealtekAll != NULL) {
		if (pRealtekAll->m_mode == RTK_DEMOD_MODE_NONE) {
			DEMOD_INFO("\033[0;32;31m""DEMOD need init first !!!!! demod mode=%d\n""\033[m" , pRealtekAll->m_mode);
			return TUNER_CTRL_FAIL;
		}
		if (pRealtekAll->m_auto_tune_en == 1) {
			pDemodKernel->Lock(pDemodKernel);
			if (pRealtekAll->m_pDemod) {
				ret = pRealtekAll->m_pDemod->AutoTune(pRealtekAll->m_pDemod);		
			}
			pDemodKernel->Unlock(pDemodKernel);
		}
	}
	
	return ret;
}

/*----------------------------------------------------------------------
 * Func : AutoTune
 *
 * Desc :
 *
 * Parm :
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_ALL_KernelAutoTune(DEMOD* pDemodKernel)
{
	int ret = TUNER_CTRL_OK;
	REALTEK_ALL* pRealtekAll;
	DEMOD_CALLER(" REALTEK_ALL_KernelAutoTune\n");
	//pRealtekAll = (REALTEK_ALL*)(pDemodKernel->private_data);

#ifdef SUPPORT_DEMOD_AUTOTEST
	int result;
	int result2;
	int OSD_autotest_mode;
	int OSD_load_setting;
	int OSD_BW_setting;
	int OSD_freq_setting;
	int OSD_DTV_flag;
	int OSD_TV_mode;
	int OSD_BW;
	int SymbolRate;
	int SignalInfo_Load;
	int SignalInfo_Type;
	int Per;
	unsigned int SignalInfo_Result = 0;
	unsigned char SignalInfo_Lock;
	TV_SYSTEM OSD_TV_System = TV_SYS_DVBC_8M;
#endif



	while (1)

	{

		pRealtekAll = (REALTEK_ALL*)(pDemodKernel->private_data);


		if (pRealtekAll != NULL) {
			if (pRealtekAll->m_kernel_auto_tune_en == 1) {
				pDemodKernel->Lock(pDemodKernel);
				if (pRealtekAll->m_pDemod) {
					ret = pRealtekAll->m_pDemod->KernelAutoTune(pRealtekAll->m_pDemod);


#ifdef SUPPORT_DEMOD_AUTOTEST

#ifdef NOT_SUPPORT_DVBS_AUTOTEST
                                     if ((PLL27X_REG_IFADC_1_get_pll27x_ifadc_dtv_cko_en(rtd_inl(PLL27X_REG_IFADC_1_reg)) == 0x1) && ( !(IsDvbs2Sys(pDemodKernel->m_tv_sys) || IsDvbsSys(pDemodKernel->m_tv_sys))) ) {
#else
					if (PLL27X_REG_IFADC_1_get_pll27x_ifadc_dtv_cko_en(rtd_inl(PLL27X_REG_IFADC_1_reg)) == 0x1) {
#endif

						result = rtd_inl(DTV_FRONTEND_DTV_FRONTEND_DUMMY5_reg);
						OSD_autotest_mode = (result >> 31) & 0x1;
						OSD_load_setting = (result >> 30) & 0x1;
						OSD_DTV_flag = (result >> 29) & 0x1;
						OSD_TV_mode = (result >> 25) & 0xf;
						OSD_BW_setting = (result >> 23) & 0x3;
						OSD_freq_setting = (result & 0x7FFFFF) * 1000;
						//DEMOD_INFO("[OSD][%d] OSD_load_setting=%d, OSD_DTV_flag=%d, OSD_TV_mode=%d OSD_BW_setting=%d, OSD_freq_setting=%d\n", osd_i,OSD_load_setting, OSD_DTV_flag, OSD_TV_mode, OSD_BW_setting, OSD_freq_setting);

						result = rtd_inl(DTV_FRONTEND_DTV_FRONTEND_DUMMY4_reg);
						SignalInfo_Load = (result >> 31) & 0x1;
						SignalInfo_Type = (result >> 17) & 0x1fff;
						//DEMOD_INFO("[OSD][%d] SignalInfo_Load=%d, SignalInfo_Type=%d\n", osd_i,SignalInfo_Load, SignalInfo_Type);

						/*
							SignalInfo_Type :
							0 : Lock Status
							1 : Ber
							2 : Per
							3 : SNR
							4 : Error pkt
						*/

						if (OSD_autotest_mode) {

							if (SignalInfo_Load == 1) {
								//DTVFE_CTRL_INFO("[OSD][%d] Get Per.... \n",osd_i);

								switch (SignalInfo_Type) {
								case 0:


									if (pRealtekAll->m_pDemod)
										ret = pRealtekAll->m_pDemod->GetLockStatus(pRealtekAll->m_pDemod, &SignalInfo_Lock);
									rtd_outl(DTV_FRONTEND_DTV_FRONTEND_DUMMY3_reg, SignalInfo_Lock);
									break;
								case 1:

									ret = pRealtekAll->m_pDemod->GetSignalQuality(pRealtekAll->m_pDemod, TV_QUAL_BEC, &SigQuality);
									rtd_outl(DTV_FRONTEND_DTV_FRONTEND_DUMMY2_reg, SigQuality.layer_ber.ber_num);
									rtd_outl(DTV_FRONTEND_DTV_FRONTEND_DUMMY3_reg, SigQuality.layer_ber.ber_den);
									break;
								case 2:

									ret = pRealtekAll->m_pDemod->GetSignalQuality(pRealtekAll->m_pDemod, TV_QUAL_PEC, &SigQuality);
									rtd_outl(DTV_FRONTEND_DTV_FRONTEND_DUMMY_reg, SigQuality.layer_per.per_num);
									rtd_outl(DTV_FRONTEND_DTV_FRONTEND_DUMMY3_reg, SigQuality.layer_per.per_den);
#if 0
									DTVFE_CTRL_INFO("[OSD][%d] SigQuality.layer_per.per_num=%d\n", osd_i, SigQuality.layer_per.per_num);
									DTVFE_CTRL_INFO("[OSD][%d] SigQuality.layer_per.per_den=%d\n", osd_i, SigQuality.layer_per.per_den);
#endif
									break;
								case 3:

									ret = pRealtekAll->m_pDemod->GetSignalQuality(pRealtekAll->m_pDemod, TV_QUAL_SNR, &SigQuality);
									rtd_outl(DTV_FRONTEND_DTV_FRONTEND_DUMMY3_reg, SigQuality.snr);
									break;

								default:
									break;
								}
								rtd_maskl(DTV_FRONTEND_DTV_FRONTEND_DUMMY4_reg, ~(0x1 << 31), 0x0); //clear SignalInfo_Load
							}

							/*
								OSD_TV_mode :
								0 : ATSC
								1 : DVBT
								2 : DVBT2
								3 : DVBC
								4 : DVBS
								5 : DVBS2
								6 : OpenCable : 64qam
								7 : OpenCable : 256qam
								8 : DTMB
								9 : ISDBT
							*/

							if (OSD_load_setting & OSD_DTV_flag) {


								switch (OSD_TV_mode) {
								case 0:
									OSD_TV_System = TV_SYS_ATSC;
									break;
								case 1:
									switch (OSD_BW_setting) {
									case 1:
										OSD_TV_System = TV_SYS_DVBT_6M;
										SigInfo.mod = TV_MODULATION_OFDM;
										SigInfo.ofdm.hierarchy = 0;
										break;
									case 2:
										OSD_TV_System = TV_SYS_DVBT_7M;
										SigInfo.mod = TV_MODULATION_OFDM;
										SigInfo.ofdm.hierarchy = 0;
										break;
									case 3:
										OSD_TV_System = TV_SYS_DVBT_8M;
										SigInfo.mod = TV_MODULATION_OFDM;
										SigInfo.ofdm.hierarchy = 0;
										break;
									}
									break;
								case 2:
									switch (OSD_BW_setting) {
									case 0:
										OSD_TV_System = TV_SYS_DVBT2_1D7M;
										SigInfo.mod = TV_MODULATION_DVBT2_OFDM;
										SigInfo.dvbt2_ofdm.plp_select = 0;
										break;
									case 1:
										OSD_TV_System = TV_SYS_DVBT2_6M;
										SigInfo.mod = TV_MODULATION_DVBT2_OFDM;
										SigInfo.dvbt2_ofdm.plp_select = 0;
										break;
									case 2:
										OSD_TV_System = TV_SYS_DVBT2_7M;
										SigInfo.mod = TV_MODULATION_DVBT2_OFDM;
										SigInfo.dvbt2_ofdm.plp_select = 0;
										break;
									case 3:
										OSD_TV_System = TV_SYS_DVBT2_8M;
										SigInfo.mod = TV_MODULATION_DVBT2_OFDM;
										SigInfo.dvbt2_ofdm.plp_select = 0;
										break;
									}
									break;
								case 3:
									switch (OSD_BW_setting) {
									case 1:
										OSD_TV_System = TV_SYS_DVBC_6M;
										SigInfo.mod = TV_MODULATION_DVBC_QAM;
										break;
									case 2:
										OSD_TV_System = TV_SYS_DVBC_7M;
										SigInfo.mod = TV_MODULATION_DVBC_QAM;
										break;
									case 3:
										OSD_TV_System = TV_SYS_DVBC_8M;
										SigInfo.mod = TV_MODULATION_DVBC_QAM;
										break;
									}
									break;
								case 4:
									OSD_TV_System = TV_SYS_DVBS;
									result2 = rtd_inl(DTV_FRONTEND_DTV_FRONTEND_DUMMY4_reg);
									SigInfo.dvbs.symbol_rate = (result2 & 0x1ffff) * 1000;
									break;
								case 5:
									OSD_TV_System = TV_SYS_DVBS2;
									result2 = rtd_inl(DTV_FRONTEND_DTV_FRONTEND_DUMMY4_reg);
									SigInfo.dvbs.symbol_rate = (result2 & 0x1ffff) * 1000;
									break;
								case 6:
									OSD_TV_System = TV_SYS_OPENCABLE_64;
									break;
								case 7:
									OSD_TV_System = TV_SYS_OPENCABLE_64;
									break;
								case 8:
									OSD_TV_System = TV_SYS_DTMB;
									break;
								case 9:
									switch (OSD_BW_setting) {
									case 1:
										OSD_TV_System = TV_SYS_ISDBT_6M;
										break;
									case 2:
										OSD_TV_System = TV_SYS_ISDBT_7M;
										break;
									case 3:
										OSD_TV_System = TV_SYS_ISDBT_8M;
										break;
									}
									break;
								case 10:
									OSD_TV_System = TV_SYS_ABS_S;
									break;

								}
								ret = pRealtekAll->m_pDemod->SetTVSysEx(pRealtekAll->m_pDemod, OSD_TV_System, &SigInfo);
								rtd_maskl(DTV_FRONTEND_DTV_FRONTEND_DUMMY5_reg, ~(0x1 << 30), 0x0); //clear load flag

							}
						}

					}


#endif


				}

				pDemodKernel->Unlock(pDemodKernel);

			}
		}



		if (pRealtekAll->m_KernelAutoTuneThread_start == 0)
			break;

		tv_osal_msleep(KERNEL_AUTOTUNE_UPDATE_INTERVAL_MS);

	}

	return ret;
}

/*----------------------------------------------------------------------
 * Func : DebugInfo
 *
 * Desc :
 *
 * Parm :
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_ALL_DebugInfo(DEMOD* pDemodKernel, unsigned char debug_mode)
{
	int ret = TUNER_CTRL_OK;
	REALTEK_ALL* pRealtekAll;
	DEMOD_CALLER(" REALTEK_ALL_DebugInfo\n");
	pRealtekAll = (REALTEK_ALL*)(pDemodKernel->private_data);

	if (pRealtekAll->m_mode == RTK_DEMOD_MODE_NONE) {
		DEMOD_INFO("\033[0;32;31m""DEMOD need init first !!!!! demod mode=%d\n""\033[m" , pRealtekAll->m_mode);
		return TUNER_CTRL_FAIL;
	}

	pDemodKernel->Lock(pDemodKernel);

	if (pRealtekAll->m_pDemod)
		ret = pRealtekAll->m_pDemod->DebugInfo(pRealtekAll->m_pDemod, debug_mode);

	pDemodKernel->Unlock(pDemodKernel);
	return ret;
}

/*----------------------------------------------------------------------
 * Func : InspectSignal
 *
 * Desc : Inspect Signal Info (for Debug Purpose)
 *
 * Parm : pBuff : message buffer
 *        BufferSize : size of message buffer
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_ALL_InspectSignal(DEMOD* pDemodKernel)
{
	int ret = TUNER_CTRL_OK;
	REALTEK_ALL* pRealtekAll;
	DEMOD_CALLER(" REALTEK_ALL_InspectSignal\n");
	pRealtekAll = (REALTEK_ALL*)(pDemodKernel->private_data);

	if (pRealtekAll->m_mode == RTK_DEMOD_MODE_NONE) {
		DEMOD_INFO("\033[0;32;31m""DEMOD need init first !!!!! demod mode=%d\n""\033[m" , pRealtekAll->m_mode);
		return TUNER_CTRL_FAIL;
	}

	pDemodKernel->Lock(pDemodKernel);

	if (pRealtekAll->m_pDemod)
		ret = pRealtekAll->m_pDemod->InspectSignal(pRealtekAll->m_pDemod);

	pDemodKernel->Unlock(pDemodKernel);
	return ret;
}

/*----------------------------------------------------------------------
 * Func : GetRegCmd
 *
 * Desc : Get register value from out kernel caller
 *
 * Parm : RegAddr : reg addr
 *        RegValue : value of reg
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_ALL_GetRegCmd(DEMOD* pDemodKernel,unsigned int RegAddr, unsigned int *RegValue)
{
	int ret = TUNER_CTRL_OK;
	DEMOD_CALLER(" MERLIN2_ALL_GetRegCmd\n");

	pDemodKernel->Lock(pDemodKernel);
	*RegValue = rtd_inl(RegAddr);
	pDemodKernel->Unlock(pDemodKernel);

	RTK_DEMOD_INFO("GetRegdata RegAddr=0x%x RegValue=0x%x \n",RegAddr, *RegValue);

	return ret;
}

/*----------------------------------------------------------------------
 * Func : SetRegCmd
 *
 * Desc : Set register value from out kernel caller
 *
 * Parm : RegAddr : reg addr
 *        RegValue : value of reg
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/

int REALTEK_ALL_SetRegCmd(DEMOD* pDemodKernel,unsigned int RegAddr, unsigned int RegValue)
{
	int ret = TUNER_CTRL_OK;
	DEMOD_CALLER(" MERLIN2_ALL_SetRegCmd\n");
	RTK_DEMOD_INFO("SetRegdata addr=0x%x value=0x%x \n", RegAddr, RegValue);

	pDemodKernel->Lock(pDemodKernel);
	rtd_outl(RegAddr,RegValue);
	pDemodKernel->Unlock(pDemodKernel);

	return ret;
}

/*----------------------------------------------------------------------
 * Func : SetTvMode
 *
 * Desc : Set Mode of REALTEK_ALL
 *
 * Parm : mode :    RTK_DEMOD_MODE_DVBT : DVBT mode
 *                  RTK_DEMOD_MODE_DVBC  : DVBC mode
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_ALL_SetTvMode(DEMOD* pDemodKernel, TV_SYSTEM_TYPE mode)
{
	int ret = TUNER_CTRL_FAIL;
	REALTEK_ALL* pRealtekAll;
	RTK_DEMOD_INFO("REALTEK_ALL_SetTvMode\n");
	pRealtekAll = (REALTEK_ALL*)(pDemodKernel->private_data);
	pRealtekAll->m_kernel_auto_tune_en = 0;
	pRealtekAll->m_auto_tune_en = 0;
	pRealtekAll->m_mode               = RTK_DEMOD_MODE_NONE; 
	
	pDemodKernel->Lock(pDemodKernel);

	//rtd_maskl(0xB801A604, ~(0x40), 0);	// SB2_DUMMY_1_reg[6]   ///astone

	switch (mode) {
	case TV_SYS_TYPE_DVBT:
	case TV_SYS_TYPE_DVBT2:
	case TV_SYS_TYPE_AUTOSCAN:

		if (pRealtekAll->m_pDVBT2Demod == NULL) {
			RTK_DEMOD_INFO("Open New DVBT2 lib and Set to DVBT2\n");
			pRealtekAll->m_pDVBT2Demod = kmalloc(sizeof(DEMOD), GFP_KERNEL);
			REALTEK_I_DVBT2_Constructors(pRealtekAll->m_pDVBT2Demod, pDemodKernel->m_addr, pRealtekAll->m_output_mode, pRealtekAll->m_output_freq, pDemodKernel->m_pComm);

			pRealtekAll->m_pDVBT2Demod->AttachTuner(pRealtekAll->m_pDVBT2Demod, pDemodKernel->m_pTuner);
			ret  = pRealtekAll->m_pDVBT2Demod->SetTvMode(pRealtekAll->m_pDVBT2Demod, TV_SYS_TYPE_DVBT2);
			ret |= pRealtekAll->m_pDVBT2Demod->SetTSMode(pRealtekAll->m_pDVBT2Demod, &pDemodKernel->m_ts);

			if (ret != TUNER_CTRL_OK) {
				DEMOD_WARNING("Set REALTEK_ALL to DVBT2 mode failed\n");
				pRealtekAll->m_pDVBT2Demod->Destory(pRealtekAll->m_pDVBT2Demod);
				kfree(pRealtekAll->m_pDVBT2Demod);
				pRealtekAll->m_pDVBT2Demod = NULL;
				goto set_demod_mode_failed;
			}
		} else {
			RTK_DEMOD_INFO("Set to DVBT2\n");
			ret  = pRealtekAll->m_pDVBT2Demod->SetTvMode(pRealtekAll->m_pDVBT2Demod, TV_SYS_TYPE_DVBT2);
			ret |= pRealtekAll->m_pDVBT2Demod->SetTSMode(pRealtekAll->m_pDVBT2Demod, &pDemodKernel->m_ts);


			if (ret != TUNER_CTRL_OK) {
				DEMOD_WARNING("Set REALTEK_ALL to DVBT2 mode failed\n");
				pRealtekAll->m_pDVBT2Demod->Destory(pRealtekAll->m_pDVBT2Demod);
				kfree(pRealtekAll->m_pDVBT2Demod);
				pRealtekAll->m_pDVBT2Demod = NULL;
				goto set_demod_mode_failed;
			}
		}

		pRealtekAll->m_pDemod = pRealtekAll->m_pDVBT2Demod;
		pRealtekAll->m_mode               = RTK_DEMOD_MODE_DVBT2;
		break;
//DVBS & DVBS2 share driver file
	/*
		case TV_SYS_TYPE_DVBS:

			if (pRealtekAll->m_pDVBSDemod == NULL) {
				RTK_DEMOD_INFO("Open New DVBS lib and Set to DVBS\n");
				pRealtekAll->m_pDVBSDemod = kmalloc(sizeof(DEMOD), GFP_KERNEL);
				REALTEK_I_DVBS_Constructors(pRealtekAll->m_pDVBSDemod, pDemodKernel->m_addr, pRealtekAll->m_output_mode, pRealtekAll->m_output_freq, pDemodKernel->m_pComm);

				pRealtekAll->m_pDVBSDemod->AttachTuner(pRealtekAll->m_pDVBSDemod, pDemodKernel->m_pTuner);
				ret  = pRealtekAll->m_pDVBSDemod->SetTvMode(pRealtekAll->m_pDVBSDemod, TV_SYS_TYPE_DVBS);
				ret |= pRealtekAll->m_pDVBSDemod->SetTSMode(pRealtekAll->m_pDVBSDemod, &pDemodKernel->m_ts);


				if (ret != TUNER_CTRL_OK) {
					DEMOD_WARNING("Set REALTEK_ALL to DVBS mode failed\n");
					pRealtekAll->m_pDVBSDemod->Destory(pRealtekAll->m_pDVBSDemod);
					kfree(pRealtekAll->m_pDVBSDemod);
					pRealtekAll->m_pDVBSDemod = NULL;
					goto set_demod_mode_failed;
				}
			} else {
				RTK_DEMOD_INFO("Set to DVBS\n");
				ret  = pRealtekAll->m_pDVBSDemod->SetTvMode(pRealtekAll->m_pDVBSDemod, TV_SYS_TYPE_DVBS);
				ret |= pRealtekAll->m_pDVBSDemod->SetTSMode(pRealtekAll->m_pDVBSDemod, &pDemodKernel->m_ts);


				if (ret != TUNER_CTRL_OK) {
					DEMOD_WARNING("Set REALTEK_ALL to DVBS mode failed\n");
					pRealtekAll->m_pDVBSDemod->Destory(pRealtekAll->m_pDVBSDemod);
					kfree(pRealtekAll->m_pDVBSDemod);
					pRealtekAll->m_pDVBSDemod = NULL;
					goto set_demod_mode_failed;
				}
			}

			pRealtekAll->m_pDemod = pRealtekAll->m_pDVBSDemod;
			break;
	*/
	case TV_SYS_TYPE_DVBS:
	case TV_SYS_TYPE_DVBS2:

		if (pRealtekAll->m_pDVBS2Demod == NULL) {
			RTK_DEMOD_INFO("Open New DVBS2 lib and Set to DVBS2\n");
			pRealtekAll->m_pDVBS2Demod = kmalloc(sizeof(DEMOD), GFP_KERNEL);
			REALTEK_I_DVBS2_Constructors(pRealtekAll->m_pDVBS2Demod, pDemodKernel->m_addr, pRealtekAll->m_output_mode, pRealtekAll->m_output_freq, pDemodKernel->m_pComm);

			pRealtekAll->m_pDVBS2Demod->AttachTuner(pRealtekAll->m_pDVBS2Demod, pDemodKernel->m_pTuner);
			ret  = pRealtekAll->m_pDVBS2Demod->SetTvMode(pRealtekAll->m_pDVBS2Demod, TV_SYS_TYPE_DVBS2);
			ret |= pRealtekAll->m_pDVBS2Demod->SetTSMode(pRealtekAll->m_pDVBS2Demod, &pDemodKernel->m_ts);


			if (ret != TUNER_CTRL_OK) {
				DEMOD_WARNING("Set REALTEK_ALL to DVBS2 mode failed\n");
				pRealtekAll->m_pDVBS2Demod->Destory(pRealtekAll->m_pDVBS2Demod);
				kfree(pRealtekAll->m_pDVBS2Demod);
				pRealtekAll->m_pDVBS2Demod = NULL;
				goto set_demod_mode_failed;
			}
		} else {
			RTK_DEMOD_INFO("Set to DVBS2\n");
			ret  = pRealtekAll->m_pDVBS2Demod->SetTvMode(pRealtekAll->m_pDVBS2Demod, TV_SYS_TYPE_DVBS2);
			ret |= pRealtekAll->m_pDVBS2Demod->SetTSMode(pRealtekAll->m_pDVBS2Demod, &pDemodKernel->m_ts);


			if (ret != TUNER_CTRL_OK) {
				DEMOD_WARNING("Set REALTEK_ALL to DVBS2 mode failed\n");
				pRealtekAll->m_pDVBS2Demod->Destory(pRealtekAll->m_pDVBS2Demod);
				kfree(pRealtekAll->m_pDVBS2Demod);
				pRealtekAll->m_pDVBS2Demod = NULL;
				goto set_demod_mode_failed;
			}
		}

		pRealtekAll->m_pDemod = pRealtekAll->m_pDVBS2Demod;
		pRealtekAll->m_mode               = RTK_DEMOD_MODE_DVBS2;
		break;


	case TV_SYS_TYPE_DVBC:
		if (pRealtekAll->m_pDVBCDemod == NULL) {
			RTK_DEMOD_INFO("Open New DVBC lib and Set to DVBC\n");
			pRealtekAll->m_pDVBCDemod = kmalloc(sizeof(DEMOD), GFP_KERNEL);
			REALTEK_I_DVBC_Constructors(pRealtekAll->m_pDVBCDemod, pDemodKernel->m_addr, pRealtekAll->m_output_mode, pRealtekAll->m_output_freq, pDemodKernel->m_pComm);

			pRealtekAll->m_pDVBCDemod->AttachTuner(pRealtekAll->m_pDVBCDemod, pDemodKernel->m_pTuner);
			ret  = pRealtekAll->m_pDVBCDemod->SetTvMode(pRealtekAll->m_pDVBCDemod, TV_SYS_TYPE_DVBC);
			ret |= pRealtekAll->m_pDVBCDemod->SetTSMode(pRealtekAll->m_pDVBCDemod, &pDemodKernel->m_ts);


			if (ret != TUNER_CTRL_OK) {
				DEMOD_WARNING("Set REALTEK_ALL to DVBC mode failed\n");
				pRealtekAll->m_pDVBCDemod->Destory(pRealtekAll->m_pDVBCDemod);
				kfree(pRealtekAll->m_pDVBCDemod);
				pRealtekAll->m_pDVBCDemod = NULL;
				goto set_demod_mode_failed;
			}
		} else {
			RTK_DEMOD_INFO("Set to DVBT\n");
			ret  = pRealtekAll->m_pDVBCDemod->SetTvMode(pRealtekAll->m_pDVBCDemod, TV_SYS_TYPE_DVBC);
			ret |= pRealtekAll->m_pDVBCDemod->SetTSMode(pRealtekAll->m_pDVBCDemod, &pDemodKernel->m_ts);

			if (ret != TUNER_CTRL_OK) {
				DEMOD_WARNING("Set REALTEK_ALL to DVBC mode failed\n");
				pRealtekAll->m_pDVBCDemod->Destory(pRealtekAll->m_pDVBCDemod);
				kfree(pRealtekAll->m_pDVBCDemod);
				pRealtekAll->m_pDVBCDemod = NULL;
				goto set_demod_mode_failed;
			}
		}

		pRealtekAll->m_pDemod = pRealtekAll->m_pDVBCDemod;
		pRealtekAll->m_mode               = RTK_DEMOD_MODE_DVBC;
		break;

	case TV_SYS_TYPE_ATSC:

		if (pRealtekAll->m_pATSCDemod == NULL) {
			pRealtekAll->m_pATSCDemod = kmalloc(sizeof(DEMOD), GFP_KERNEL);
			REALTEK_R_ATSC_Constructors(pRealtekAll->m_pATSCDemod, pDemodKernel->m_addr, pRealtekAll->m_output_mode, pRealtekAll->m_output_freq, pDemodKernel->m_pComm);
			pRealtekAll->m_pATSCDemod->AttachTuner(pRealtekAll->m_pATSCDemod, pDemodKernel->m_pTuner);
			ret  = pRealtekAll->m_pATSCDemod->SetTvMode(pRealtekAll->m_pATSCDemod, TV_SYS_TYPE_ATSC);
			ret |= pRealtekAll->m_pATSCDemod->SetTSMode(pRealtekAll->m_pATSCDemod, &pDemodKernel->m_ts);

			if (ret != TUNER_CTRL_OK) {
				DEMOD_WARNING("Set REALTEK_ALL to ATSC mode failed\n");
				pRealtekAll->m_pATSCDemod->Destory(pRealtekAll->m_pATSCDemod);
				kfree(pRealtekAll->m_pATSCDemod);
				pRealtekAll->m_pATSCDemod = NULL;
				goto set_demod_mode_failed;
			}
		} else {
			RTK_DEMOD_INFO("Set to ATSC\n");
			ret  = pRealtekAll->m_pATSCDemod->SetTvMode(pRealtekAll->m_pATSCDemod, TV_SYS_TYPE_ATSC);
			ret |= pRealtekAll->m_pATSCDemod->SetTSMode(pRealtekAll->m_pATSCDemod, &pDemodKernel->m_ts);

			if (ret != TUNER_CTRL_OK) {
				DEMOD_WARNING("Set REALTEK_ALL to ATSC mode failed\n");
				pRealtekAll->m_pATSCDemod->Destory(pRealtekAll->m_pATSCDemod);
				kfree(pRealtekAll->m_pATSCDemod);
				pRealtekAll->m_pATSCDemod = NULL;
				goto set_demod_mode_failed;
			}
		}

		pRealtekAll->m_pDemod = pRealtekAll->m_pATSCDemod;
		pRealtekAll->m_mode               = RTK_DEMOD_MODE_ATSC;
		break;
	case TV_SYS_TYPE_OPENCABLE:

		if (pRealtekAll->m_pQAMDemod == NULL) {
			pRealtekAll->m_pQAMDemod = kmalloc(sizeof(DEMOD), GFP_KERNEL);
			REALTEK_I_QAM_Constructors(pRealtekAll->m_pQAMDemod, pDemodKernel->m_addr, pRealtekAll->m_output_mode, pRealtekAll->m_output_freq, pDemodKernel->m_pComm);
			pRealtekAll->m_pQAMDemod->AttachTuner(pRealtekAll->m_pQAMDemod, pDemodKernel->m_pTuner);
			ret  = pRealtekAll->m_pQAMDemod->SetTvMode(pRealtekAll->m_pQAMDemod, TV_SYS_TYPE_OPENCABLE);
			ret |= pRealtekAll->m_pQAMDemod->SetTSMode(pRealtekAll->m_pQAMDemod, &pDemodKernel->m_ts);

			if (ret != TUNER_CTRL_OK) {
				DEMOD_WARNING("Set REALTEK_ALL to QAM mode failed\n");
				pRealtekAll->m_pQAMDemod->Destory(pRealtekAll->m_pQAMDemod);
				kfree(pRealtekAll->m_pQAMDemod);
				pRealtekAll->m_pQAMDemod = NULL;
				goto set_demod_mode_failed;
			}
		} else {
			RTK_DEMOD_INFO("Set to OPENCABLE\n");
			ret  = pRealtekAll->m_pQAMDemod->SetTvMode(pRealtekAll->m_pQAMDemod, TV_SYS_TYPE_OPENCABLE);
			ret |= pRealtekAll->m_pQAMDemod->SetTSMode(pRealtekAll->m_pQAMDemod, &pDemodKernel->m_ts);


			if (ret != TUNER_CTRL_OK) {
				DEMOD_WARNING("Set REALTEK_ALL to QAM mode failed\n");
				pRealtekAll->m_pQAMDemod->Destory(pRealtekAll->m_pQAMDemod);
				kfree(pRealtekAll->m_pQAMDemod);
				pRealtekAll->m_pQAMDemod = NULL;
				goto set_demod_mode_failed;
			}
		}
		pRealtekAll->m_pDemod = pRealtekAll->m_pQAMDemod;
		pRealtekAll->m_mode               = RTK_DEMOD_MODE_QAM;
		break;

	case TV_SYS_TYPE_DTMB:

		if (pRealtekAll->m_pDTMBDemod == NULL) {
			RTK_DEMOD_INFO("Open New DTMB lib and Set to DTMB\n");
			pRealtekAll->m_pDTMBDemod = kmalloc(sizeof(DEMOD), GFP_KERNEL);
			REALTEK_H_DTMB_Constructors(pRealtekAll->m_pDTMBDemod, pDemodKernel->m_addr, pRealtekAll->m_output_mode, pRealtekAll->m_output_freq, pDemodKernel->m_pComm);
			pRealtekAll->m_pDTMBDemod->AttachTuner(pRealtekAll->m_pDTMBDemod, pDemodKernel->m_pTuner);
			ret  = pRealtekAll->m_pDTMBDemod->SetTvMode(pRealtekAll->m_pDTMBDemod, TV_SYS_TYPE_DTMB);
			ret |= pRealtekAll->m_pDTMBDemod->SetTSMode(pRealtekAll->m_pDTMBDemod, &pDemodKernel->m_ts);


			if (ret != TUNER_CTRL_OK) {
				DEMOD_WARNING("Set REALTEK_ALL to DTMB mode failed\n");
				//delete pRealtekAll->m_pDTMBDemod;
				pRealtekAll->m_pDTMBDemod->Destory(pRealtekAll->m_pDTMBDemod);
				kfree(pRealtekAll->m_pDTMBDemod);
				pRealtekAll->m_pDTMBDemod = NULL;
				goto set_demod_mode_failed;
			}
		} else {
			RTK_DEMOD_INFO("Set to DTMB\n");
			ret  = pRealtekAll->m_pDTMBDemod->SetTvMode(pRealtekAll->m_pDTMBDemod, TV_SYS_TYPE_DTMB);
			ret |= pRealtekAll->m_pDTMBDemod->SetTSMode(pRealtekAll->m_pDTMBDemod, &pDemodKernel->m_ts);


			if (ret != TUNER_CTRL_OK) {
				DEMOD_WARNING("Set REALTEK_ALL to DTMB mode failed\n");
				pRealtekAll->m_pDTMBDemod->Destory(pRealtekAll->m_pDTMBDemod);
				kfree(pRealtekAll->m_pDTMBDemod);
				pRealtekAll->m_pDTMBDemod = NULL;
				goto set_demod_mode_failed;
			}
		}
		pRealtekAll->m_pDemod = pRealtekAll->m_pDTMBDemod;
		pRealtekAll->m_mode               = RTK_DEMOD_MODE_DTMB;
		break;

	case TV_SYS_TYPE_ISDBT:
		if (pRealtekAll->m_pISDBTDemod == NULL) {
			RTK_DEMOD_INFO("Open New ISDBT lib and Set to ISDBT\n");
			pRealtekAll->m_pISDBTDemod = kmalloc(sizeof(DEMOD), GFP_KERNEL);
			REALTEK_I_ISDBT_Constructors(pRealtekAll->m_pISDBTDemod, pDemodKernel->m_addr, pRealtekAll->m_output_mode, pRealtekAll->m_output_freq, pDemodKernel->m_pComm);
			pRealtekAll->m_pISDBTDemod->AttachTuner(pRealtekAll->m_pISDBTDemod, pDemodKernel->m_pTuner);
			ret  = pRealtekAll->m_pISDBTDemod->SetTvMode(pRealtekAll->m_pISDBTDemod, TV_SYS_TYPE_ISDBT);
			ret |= pRealtekAll->m_pISDBTDemod->SetTSMode(pRealtekAll->m_pISDBTDemod, &pDemodKernel->m_ts);


			if (ret != TUNER_CTRL_OK) {
				DEMOD_WARNING("Set REALTEK_ALL to ISDBT mode failed\n");
				pRealtekAll->m_pISDBTDemod->Destory(pRealtekAll->m_pISDBTDemod);
				kfree(pRealtekAll->m_pISDBTDemod);
				pRealtekAll->m_pISDBTDemod = NULL;
				goto set_demod_mode_failed;
			}
		} else {
			RTK_DEMOD_INFO("Set to ISDBT\n");
			ret  = pRealtekAll->m_pISDBTDemod->SetTvMode(pRealtekAll->m_pISDBTDemod, TV_SYS_TYPE_ISDBT);
			ret |= pRealtekAll->m_pISDBTDemod->SetTSMode(pRealtekAll->m_pISDBTDemod, &pDemodKernel->m_ts);


			if (ret != TUNER_CTRL_OK) {
				DEMOD_WARNING("Set REALTEK_ALL to ISDBT mode failed\n");
				pRealtekAll->m_pISDBTDemod->Destory(pRealtekAll->m_pISDBTDemod);
				kfree(pRealtekAll->m_pISDBTDemod);
				pRealtekAll->m_pISDBTDemod = NULL;
				goto set_demod_mode_failed;
			}
		}

		pRealtekAll->m_pDemod = pRealtekAll->m_pISDBTDemod;
		pRealtekAll->m_mode               = RTK_DEMOD_MODE_ISDB;
		break;

	case TV_SYS_TYPE_BGDKIL:
	case TV_SYS_TYPE_MN:

		if (pRealtekAll->m_pATVDemod == NULL) {
			RTK_DEMOD_INFO("Open New ATV lib and Set to ATV\n");
			pRealtekAll->m_pATVDemod = kmalloc(sizeof(DEMOD), GFP_KERNEL);
			REALTEK_R_ATV_Constructors(pRealtekAll->m_pATVDemod);//, pDemodKernel->m_addr, pRealtekAll->m_output_mode, pRealtekAll->m_output_freq, pDemodKernel->m_pComm);
			pRealtekAll->m_pATVDemod->AttachTuner(pRealtekAll->m_pATVDemod, pDemodKernel->m_pTuner);
			ret  = pRealtekAll->m_pATVDemod->SetTvMode(pRealtekAll->m_pATVDemod, TV_SYS_TYPE_BGDKIL);



			if (ret != TUNER_CTRL_OK) {
				DEMOD_WARNING("Set REALTEK_ALL to ATV mode failed\n");
				pRealtekAll->m_pATVDemod->Destory(pRealtekAll->m_pATVDemod);
				kfree(pRealtekAll->m_pATVDemod);
				pRealtekAll->m_pATVDemod = NULL;
				goto set_demod_mode_failed;
			}
		} else {
			RTK_DEMOD_INFO("Set to ATV\n");
			ret  = pRealtekAll->m_pATVDemod->SetTvMode(pRealtekAll->m_pATVDemod, TV_SYS_TYPE_BGDKIL);


			if (ret != TUNER_CTRL_OK) {
				DEMOD_WARNING("Set REALTEK_ALL to ATV mode failed\n");
				pRealtekAll->m_pATVDemod->Destory(pRealtekAll->m_pATVDemod);
				kfree(pRealtekAll->m_pATVDemod);
				pRealtekAll->m_pATVDemod = NULL;
				goto set_demod_mode_failed;
			}
		}

		pRealtekAll->m_pDemod = pRealtekAll->m_pATVDemod;
		pRealtekAll->m_mode               = RTK_DEMOD_MODE_ATV;
		break;



	default:
		goto set_demod_mode_failed;
	}

	pDemodKernel->m_update_interval_ms = pRealtekAll->m_pDemod->m_update_interval_ms;
	pDemodKernel->m_ScanRange = pRealtekAll->m_pDemod->m_ScanRange;
	ret = TUNER_CTRL_OK;
	RTK_DEMOD_INFO("Set REALTEK_ALL to appointed DTV mode successed\n");


	pDemodKernel->Unlock(pDemodKernel);

	return ret;

set_demod_mode_failed:
	pRealtekAll->m_pDemod = NULL;
	pRealtekAll->m_mode               = RTK_DEMOD_MODE_NONE;
	pDemodKernel->Unlock(pDemodKernel);

	return TUNER_CTRL_FAIL;
}


int REALTEK_ALL_GetDemodInfo(DEMOD* pDemodKernel, TV_DEMOD_INFO* pDemodInfo)
{
	RTK_DEMOD_CALLER("REALTEK_ALL_GetDemodInfo\n");

	pDemodInfo -> IcName = REALTEKALL;
	pDemodInfo -> IcVersion = 0;
	pDemodInfo -> PGAMode = 1;
	pDemodInfo -> PGAGain = 0;
	pDemodInfo -> IfPathType = 0;

	return TUNER_CTRL_OK;
}


int REALTEK_ALL_KernelThread_EN(DEMOD* pDemodKernel, unsigned int thread_en)
{

	REALTEK_ALL* pRealtekAll;
	RTK_DEMOD_INFO("REALTEK_ALL_KernelThread_EN = %u\n", thread_en);

	pRealtekAll = (REALTEK_ALL*)(pDemodKernel->private_data);
	struct task_struct *demod_kernelthread;
	int ret = TUNER_CTRL_OK;

	if (thread_en) {
		if (pRealtekAll->demod_kernelthread != NULL) {
			RTK_DEMOD_INFO("Demod kernel thread is already existed\n");
			return TUNER_CTRL_OK;
		}

		demod_kernelthread = kthread_run(REALTEK_ALL_KernelAutoTune, (void *)pDemodKernel, "KernelAutoTune");    /* no need to pass parameter into thread function */
		if (!IS_ERR(demod_kernelthread)) {
			pRealtekAll->demod_kernelthread = demod_kernelthread;
		} else {
			RTK_DEMOD_INFO("create KernelAutoTune thread failed\n");
			return TUNER_CTRL_FAIL;
		}
		pRealtekAll->m_KernelAutoTuneThread_start = 1;
	} else {
		if (pRealtekAll->demod_kernelthread == NULL) {
			RTK_DEMOD_INFO("KernelAutoTune thread does not exist, just exit\n");
			return TUNER_CTRL_OK;
		}

		pRealtekAll->m_KernelAutoTuneThread_start = 0;
		/* it will wait until thread function exit */
		ret = kthread_stop(pRealtekAll->demod_kernelthread);
		if (ret < 0) {
			RTK_DEMOD_INFO("call kthread_stop return error = %d", ret);
		}
		pRealtekAll->demod_kernelthread = NULL;
	}
	return TUNER_CTRL_OK;

}

/*----------------------------------------------------------------------
 * Func : SetTunerInputMode
 *
 * Desc : Set tuner mode
 *
 * Parm : Mode info from user space 0=single ended 1=differential
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_ALL_SetTunerInputMode(DEMOD* pDemodKernel,unsigned char Mode)
{
	int ret = TUNER_CTRL_OK;
	DEMOD_CALLER(" REALTEK_ALL_SetTunerInputMode\n");

	pDemodKernel->Lock(pDemodKernel);
	TunerInputMode = Mode;
	pDemodKernel->Unlock(pDemodKernel);

	RTK_DEMOD_INFO("SetTunerInputMode Mode=%d \n", TunerInputMode);

	return ret;
}
