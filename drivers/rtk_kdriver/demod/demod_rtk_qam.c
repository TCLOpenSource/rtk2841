/***************************************************************************************************
  File        : demod_rtk_qam.cpp
  Description : REALTEK_I QAM (OpenCable/J83.B) demod
  Author      : Kevin Wang
****************************************************************************************************
    Update List :
----------------------------------------------------------------------------------------------------
    20120207    | create phase
***************************************************************************************************/
#include <linux/kernel.h>
#include <linux/slab.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include "foundation.h"
#include "demod_rtk_qam.h"
#include "demod_rtk_qam_priv.h"
#include "qam_tvcore_registers.h"


/*----------------------------------------------------------------------
 * Func : REALTEK_I_QAM
 *
 * Desc : constructor
 *
 * Parm : device_addr : device address
 *        output_mode : REALTEK_I_QAM_OUT_IF_SERIAL / REALTEK_I_QAM_OUT_IF_PARALLEL
 *        output_freq : REALTEK_I_QAM_OUT_FREQ_6M / REALTEK_I_QAM_OUT_FREQ_10M
 *        pComm       : hadle of COMM
 *
 * Retn : handle of demod
 *----------------------------------------------------------------------*/
void REALTEK_I_QAM_Constructors(DEMOD* pDemodKernel, unsigned char addr, unsigned char output_mode, unsigned char output_freq, COMM* pComm)
{
	REALTEK_I_QAM* pRealtekIQAM;

	pDemodKernel->private_data = kmalloc(sizeof(REALTEK_I_QAM), GFP_KERNEL);
	pRealtekIQAM = (REALTEK_I_QAM*)(pDemodKernel->private_data);
	Demod_Constructors(pDemodKernel);
	
	pDemodKernel->m_id                 = DTV_DEMOD_REALTEK_I_QAM;
	pDemodKernel->m_addr               = addr;
	pDemodKernel->m_pTuner             = NULL;
	pDemodKernel->m_pComm              = pComm;
	pDemodKernel->m_ScanRange          = SCAN_RANGE_1_6;
	pDemodKernel->m_Capability         = TV_SYS_TYPE_OPENCABLE;
	pDemodKernel->m_update_interval_ms = 200;
	pDemodKernel->m_if.freq            = 36125000;
	pDemodKernel->m_if.inversion       = 1;
	pDemodKernel->m_if.agc_pola        = 0;
	pDemodKernel->m_clock              = CRYSTAL_FREQ_25200000HZ;
	pRealtekIQAM->m_output_freq         = output_freq;
	pRealtekIQAM->m_private             = (void*) AllocRealtekIQamDriver(
			pDemodKernel->m_pComm,
			pDemodKernel->m_addr,
			pDemodKernel->m_clock);
	pDemodKernel->m_ts.mode            = (output_mode == RTK_DEMOD_OUT_IF_PARALLEL) ? PARALLEL_MODE : SERIAL_MODE;
	pDemodKernel->m_ts.data_order      = MSB_D7;
	pDemodKernel->m_ts.datapin         = MSB_FIRST;
	pDemodKernel->m_ts.err_pol         = ACTIVE_HIGH;
	pDemodKernel->m_ts.sync_pol        = ACTIVE_HIGH;
	pDemodKernel->m_ts.val_pol         = ACTIVE_HIGH;
	pDemodKernel->m_ts.clk_pol         = FALLING_EDGE;
	pDemodKernel->m_ts.internal_demod_input = 1;
    pDemodKernel->m_ts.tsOutEn = 1;
	pRealtekIQAM->m_low_snr_detect     = 0;
	pRealtekIQAM->m_low_snr_recover    = 0;
	pRealtekIQAM->m_TunerOptRegCnt     = 0;
	pRealtekIQAM->m_pTunerOptReg       = NULL;
	pDemodKernel->m_pComm->SetTargetName(pDemodKernel->m_pComm, pDemodKernel->m_addr, "REALTEK_I_QAM");
	pDemodKernel->Init = REALTEK_I_QAM_Init;
	pDemodKernel->Reset = Demod_Reset;
	pDemodKernel->AcquireSignal = REALTEK_I_QAM_AcquireSignal;
	pDemodKernel->ScanSignal = REALTEK_I_QAM_ScanSignal;
	pDemodKernel->SetIF = REALTEK_I_QAM_SetIF;
	pDemodKernel->SetTSMode = REALTEK_I_QAM_SetTSMode;
	pDemodKernel->SetTVSysEx = REALTEK_I_QAM_SetTVSysEx;
	pDemodKernel->SetMode = REALTEK_I_QAM_SetMode;
	pDemodKernel->SetTVSys = REALTEK_I_QAM_SetTVSys;
	pDemodKernel->GetLockStatus = REALTEK_I_QAM_GetLockStatus;
	pDemodKernel->GetSegmentNum = Demod_GetSegmentNum;
	pDemodKernel->GetSignalInfo = REALTEK_I_QAM_GetSignalInfo;
	pDemodKernel->GetSignalQuality = REALTEK_I_QAM_GetSignalQuality;
    pDemodKernel->ChangeT2PLP = Demod_ChangeT2PLP;
	pDemodKernel->GetT2PLPInfo = Demod_GetT2PLPInfo;
	pDemodKernel->GetT2L1PreInfo = Demod_GetT2L1PreInfo;
	pDemodKernel->GetT2L1PostInfo = Demod_GetT2L1PostInfo;
	pDemodKernel->GetDemodStatus = Demod_GetDemodStatus;
	pDemodKernel->GetCarrierOffset = REALTEK_I_QAM_GetCarrierOffset;
	pDemodKernel->ForwardI2C = REALTEK_I_QAM_ForwardI2C;
	pDemodKernel->AutoTune = REALTEK_I_QAM_AutoTune;
	pDemodKernel->GetCapability = Demod_GetCapability;
	pDemodKernel->Suspend = Demod_Suspend;
	pDemodKernel->Resume = Demod_Resume;
	pDemodKernel->SetTvMode = REALTEK_I_QAM_SetTvMode;
	pDemodKernel->InspectSignal = REALTEK_I_QAM_InspectSignal;	  // Add monitor function that used to monitor demod status
	pDemodKernel->AttachTuner = Demod_AttachTuner;
	pDemodKernel->GetTSParam = Demod_GetTSParam;
	pDemodKernel->Lock = REALTEK_I_QAM_Lock;
	pDemodKernel->Unlock = REALTEK_I_QAM_Unlock;
	//pDemodKernel->Activate = REALTEK_I_QAM_Activate;
	pDemodKernel->Destory = REALTEK_I_QAM_Destructors;
}


/*----------------------------------------------------------------------
 * Func : ~REALTEK_I_QAM
 *
 * Desc : Destructor of REALTEK_I_QAM
 *
 * Parm : pDemod : handle of Demod
 *
 * Retn : N/A
 *----------------------------------------------------------------------*/
void REALTEK_I_QAM_Destructors(DEMOD* pDemodKernel)
{
	REALTEK_I_QAM* pRealtekIQAM;
	pRealtekIQAM = (REALTEK_I_QAM*)(pDemodKernel->private_data);
	
	if (pRealtekIQAM->m_private != NULL)
		ReleaseRealtekIQamDriver((REALTEK_I_QAM_DRIVER_DATA*)pRealtekIQAM->m_private);

	kfree(pRealtekIQAM);
	//pDemodKernel->Destory(pDemodKernel);
	REALTEK_I_QAM_DBG("REALTEK_R_QAM_Destructors Complete\n");
}


/*----------------------------------------------------------------------
 * Func : Init
 *
 * Desc : Initial realtek_i
 *
 * Parm : N/A
 *
 * Retn : TUNER_CTRL_OK / TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_QAM_Init(DEMOD* pDemodKernel)
{
	int ret = TUNER_CTRL_OK;
	unsigned char PGAEnable = 0;
	IFADCGAIN PGAGain;
	unsigned int IsRpuLowReady, IsRpuHighReady;
	unsigned int BuildId, DemodType;
	REALTEK_I_QAM* pRealtekIQAM;
	QAM_DEMOD_MODULE* pDemod;

	pRealtekIQAM = (REALTEK_I_QAM*)(pDemodKernel->private_data);
	
	if (pDemodKernel->m_pComm == NULL || pRealtekIQAM->m_private == NULL)
		return TUNER_CTRL_FAIL;
	
	pDemod = ((REALTEK_I_QAM_DRIVER_DATA*) pRealtekIQAM->m_private)->pDemod;

	memset(&PGAGain, 0, sizeof(IFADCGAIN)); 
	pDemodKernel->Lock(pDemodKernel);
	pRealtekIQAM->m_auto_tune_en = 0;
	//DtvDemodClockEnable(1);
	DtvDemodInitialization(RTK_DEMOD_MODE_QAM, 1);

	ret = DECODE_RET(pDemod->CheckRpuReady(pDemod, &IsRpuLowReady));//Check for Low level Header
	ret |= DECODE_RET(pDemod->CheckRpuReady(pDemod, &IsRpuHighReady));//Check for High level Msg
	
	if (IsRpuLowReady != 1 || IsRpuHighReady != 1 || ret != TUNER_CTRL_OK) 
	{
		REALTEK_I_QAM_INFO("Waiting for Demod Init Done, Demod Has No Reply !!!!\n");
		REALTEK_I_QAM_INFO("RpuLowReady = %u, RpuHighReady = %u\n", IsRpuLowReady, IsRpuHighReady);
		goto init_fail;
	}
	
	//Change To Buffer Mode
	REALTEK_I_QAM_INFO("Change To Buffer Mode........\n");
	ret |= DECODE_RET(pDemod->SwitchToBuffer(pDemod));
	if (ret != TUNER_CTRL_OK) {
		REALTEK_I_QAM_INFO("Change To Buffer Mode Fail !!!!!\n");
		goto init_fail;
	}

	pDemod->ActivateCore(pDemod);
	if (ret != TUNER_CTRL_OK) {
		REALTEK_I_QAM_INFO("ActivateCore Fail !!!!!\n");
		goto init_fail;
	}
	
	// check tuner information
	PGAEnable = 2;
	PGAGain = PGAFIX_2DB;

	if (pDemodKernel->m_pTuner) 
	{
		TUNER_PARAM Param;
		if (pDemodKernel->m_pTuner->GetParam(pDemodKernel->m_pTuner, TV_SYS_OPENCABLE_64, &Param) == TUNER_CTRL_OK) 
		{
			switch (Param.id) 
			{
			case TV_TUNER_NXP_TDA18275A:
				REALTEK_I_QAM_INFO("Tuner id %u, TV_TUNER_NXP_TDA18275A\n", Param.id);
				pRealtekIQAM->m_qam_AgcScale = 33;//33/128=0.257
				pRealtekIQAM->m_qam_ext_gain_dis = RTK_DEMOD_XML_EXT_GAIN_EN;
				break;
			case TV_TUNER_SILICONLABS_SI2151:
				REALTEK_I_QAM_INFO("Tuner id %u, TV_TUNER_SILICONLABS_SI2151\n", Param.id);
				pRealtekIQAM->m_qam_AgcScale = 89;//89/128=0.695
				pRealtekIQAM->m_qam_ext_gain_dis = RTK_DEMOD_XML_EXT_GAIN_DIS;
				ImgDemodFixIfagc(RTK_DEMOD_MODE_QAM, 0x1, 0x0);//Fix IFAGC at 0V when IFAGC controlled by Tuner
				break;
			case TV_TUNER_SILICONLABS_SI2178B:
			case TV_TUNER_NO_TUNER:
				REALTEK_I_QAM_INFO("Tuner id %u, TV_TUNER_SILICONLABS_SI2178B\n", Param.id);
				pRealtekIQAM->m_qam_AgcScale = 89;//89/128=0.695
				pRealtekIQAM->m_qam_ext_gain_dis = RTK_DEMOD_XML_EXT_GAIN_EN;
				break;
			case TV_TUNER_MAXLINEAR_MXL661:
				REALTEK_I_QAM_INFO("Tuner id %u, TV_TUNER_MAXLINEAR_MXL661\n", Param.id);
				break;
			case TV_TUNER_RAFAEL_R840:
				REALTEK_I_QAM_INFO("Tuner id %u, TV_TUNER_RAFAEL_R840\n", Param.id);
				break;
			default:
				REALTEK_I_QAM_INFO("unknow tuner id %u, using default setting\n", Param.id);
				break;
			}
			pDemodKernel->m_if.freq      = Param.if_freq;
			pDemodKernel->m_if.inversion = Param.if_inversion;
			pDemodKernel->m_if.agc_pola  = Param.if_agc_pola;
			
			REALTEK_I_QAM_INFO("AGC Scaling = %u/128, ext_gain_dis = %u, if_freq = %lu, Inverse = %u, if_agc_pola = %u\n", 
				pRealtekIQAM->m_qam_AgcScale, pRealtekIQAM->m_qam_ext_gain_dis, pDemodKernel->m_if.freq, pDemodKernel->m_if.inversion, pDemodKernel->m_if.agc_pola);
		}
	}
	
	DtvPGAControl(PGAEnable, PGAGain);
	
	// Initial Driver
	ClearDemodReset(RTK_DEMOD_MODE_QAM);

	if (pDemodKernel->SetTSMode(pDemodKernel, &pDemodKernel->m_ts) != TUNER_CTRL_OK)
		goto init_fail;

	REALTEK_I_QAM_DBG("REALTEK_I_QAM Init Complete\n");
	
	ret |= DECODE_RET(pDemod->GetDemodInfo(pDemod, &DemodType));
	ret |= DECODE_RET(pDemod->GetBuildId(pDemod, &BuildId));
	REALTEK_I_QAM_INFO("DemodType = 0x%x, BuildId = 0x%x\n", DemodType, BuildId);

	//OpenCable (QAM), Support Run Time Change XML Parmeters
	//ret |= DECODE_RET(pDemod->SetXmlTunerGainCtrl(pDemod, pRealtekIQAM->m_qam_AgcScale | (RTK_DEMOD_XML_EXT_GAIN1 << 16) | ((pDemodKernel->m_if.agc_pola ? 1 : 0) << 18)));
	ret |= DECODE_RET(pDemod->SetXmlTunerGainCtrl(pDemod, pRealtekIQAM->m_qam_AgcScale | (RTK_DEMOD_XML_EXT_GAIN1 << 16) | (pDemodKernel->m_if.agc_pola << 18)));
	ret |= DECODE_RET(pDemod->SetXmlFlags(pDemod, RTK_DEMOD_XML_REAL_IF | (pDemodKernel->m_if.inversion << 1) | (RTK_DEMOD_XML_UNSIGNED << 2) | (pRealtekIQAM->m_qam_ext_gain_dis << 3)));
	ret |= DECODE_RET(pDemod->SetXmlIfFreq(pDemod, pDemodKernel->m_if.freq));
	ret |= DECODE_RET(pDemod->SetXmlTunerCfgOverride(pDemod, 0x00000001));

	ret |= DECODE_RET(pDemod->SetXmlIfClk(pDemod, 30000000));
	ret |= DECODE_RET(pDemod->SetXmlLdpcClk(pDemod, 270000000));
	ret |= DECODE_RET(pDemod->SetXmlUccClk(pDemod, 135000000));
	ret |= DECODE_RET(pDemod->SetXmlMcuClk(pDemod, 135000000));
	ret |= DECODE_RET(pDemod->SetXmlPlftCfgOverride(pDemod, 0x00000001));

	pDemodKernel->Unlock(pDemodKernel);
	REALTEK_I_QAM_INFO("REALTEK_I_QAM Init Complete\n");
	return TUNER_CTRL_OK;

init_fail:
	REALTEK_I_QAM_WARNING("REALTEK_I_QAM Init Fail\n");
	pDemodKernel->Unlock(pDemodKernel);

	return TUNER_CTRL_FAIL;
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
int REALTEK_I_QAM_SetTVSys(DEMOD* pDemodKernel, TV_SYSTEM sys)
{
	REALTEK_I_QAM* pRealtekIQAM;
	pRealtekIQAM = (REALTEK_I_QAM*)(pDemodKernel->private_data);
	
	REALTEK_I_QAM_INFO("\033[1;32;31m" "%s %s %d\n" "\033[m", __FILE__, __func__, __LINE__);
	pDemodKernel->SetTVSysEx(pDemodKernel, sys, NULL);
	
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
int REALTEK_I_QAM_SetTVSysEx(DEMOD* pDemodKernel, TV_SYSTEM sys,const TV_SIG_INFO* pSigInfo)
{
	int ret = TUNER_CTRL_OK;
	CH_MODE QamScanMode;
    TUNER_PARAM Param;
    REALTEK_I_QAM* pRealtekIQAM;
	QAM_DEMOD_MODULE* pDemod;

	pRealtekIQAM = (REALTEK_I_QAM*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_QAM_DRIVER_DATA*) pRealtekIQAM->m_private)->pDemod;
	
	if (pSigInfo != NULL)
		QamScanMode = pSigInfo->qam.scan_mode ? CH_SCAN_MODE : CH_NORMAL_MODE;
	else
		QamScanMode = CH_NORMAL_MODE;

	REALTEK_I_QAM_INFO("\033[1;32;31m" "%s %s %d, system = %d, QamScanMode = %d\n" "\033[m", __FILE__, __func__, __LINE__, sys, QamScanMode);

	if (!IsOpenCableSys(sys)) 
	{
		REALTEK_I_QAM_WARNING("Set TV system failed, unsupported TV system\n");

		return TUNER_CTRL_FAIL;
	}
	
	pRealtekIQAM->m_auto_tune_en = 0;
	pDemodKernel->Lock(pDemodKernel);
	
	//TUNER_PARAM Param;
	if (pDemodKernel->m_pTuner->GetParam(pDemodKernel->m_pTuner, pDemodKernel->m_tv_sys, &Param) == TUNER_CTRL_OK) 
	{
		if ((pDemodKernel->m_if.freq != Param.if_freq) || (pDemodKernel->m_if.inversion != Param.if_inversion) || (pDemodKernel->m_if.agc_pola  != Param.if_agc_pola)) 
		{
			pDemodKernel->m_if.freq = Param.if_freq;
			pDemodKernel->m_if.inversion = Param.if_inversion;
			pDemodKernel->m_if.agc_pola = Param.if_agc_pola;
			if (pDemodKernel->SetIF(pDemodKernel, &pDemodKernel->m_if) != TUNER_CTRL_OK)  
			{
				pDemodKernel->Unlock(pDemodKernel);
				return  TUNER_CTRL_FAIL;
			}
		}
	}

	if (!pSigInfo) {
		REALTEK_I_QAM_WARNING("Siginfo doesn't specified, SetTVSysEx Fail\n");
		goto SetTVSysEx_fail;
	}

	pDemodKernel->m_tv_sys = sys;
	
	//Set Bandwidth and Frequency to Acknowledge Demod to Lock
	ret = DECODE_RET(pDemod->DemodCtrlStop(pDemod));
	REALTEK_I_QAM_INFO("REALTEK_I_QAM DemodCtrlStop %d\n", ret);
		
	ret = DECODE_RET(pDemod->SetTunerBandwidth(pDemod, 6000000));
	REALTEK_I_QAM_INFO("REALTEK_I_QAM SetTunerBandwidth %d\n", ret);
	
	ret = DECODE_RET(pDemod->SetTunerFreq(pDemod, 666000000));
	REALTEK_I_QAM_INFO("REALTEK_I_QAM SetTunerFreq %d\n", ret);
	
	ret = DECODE_RET(pDemod->DemodCtrlDetect(pDemod));
	REALTEK_I_QAM_INFO("REALTEK_I_QAM DemodCtrlDetect %d\n",ret);
	
	REALTEK_I_QAM_INFO("REALTEK_I_QAM SetTVSysEx Complete\n");
	pDemodKernel->Unlock(pDemodKernel);
	
	return ret;

SetTVSysEx_fail:
	pDemodKernel->Unlock(pDemodKernel);
	return TUNER_CTRL_FAIL;
	
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
int REALTEK_I_QAM_SetIF(DEMOD* pDemodKernel, IF_PARAM* pParam)
{
	int ret = TUNER_CTRL_OK;
	REALTEK_I_QAM* pRealtekIQAM;
	QAM_DEMOD_MODULE* pDemod;

	pRealtekIQAM = (REALTEK_I_QAM*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_QAM_DRIVER_DATA*) pRealtekIQAM->m_private)->pDemod;

	pDemodKernel->Lock(pDemodKernel);
	REALTEK_I_QAM_INFO("SetIF, IF_freq = %lu, spectrumn inv = %u, agc_pola = %u\n", pParam->freq, pParam->inversion, pParam->agc_pola);

	//ret |= DECODE_RET(pDemod->SetXmlTunerGainCtrl(pDemod, pRealtekIQAM->m_qam_AgcScale | (RTK_DEMOD_XML_EXT_GAIN1 << 16) | ((pParam->agc_pola ? 1 : 0) << 18)));
	ret |= DECODE_RET(pDemod->SetXmlTunerGainCtrl(pDemod, pRealtekIQAM->m_qam_AgcScale | (RTK_DEMOD_XML_EXT_GAIN1 << 16) | (pParam->agc_pola << 18)));
	ret |= DECODE_RET(pDemod->SetXmlFlags(pDemod, RTK_DEMOD_XML_REAL_IF | (pParam->inversion << 1) | (RTK_DEMOD_XML_UNSIGNED << 2) | (pRealtekIQAM->m_qam_ext_gain_dis << 3)));
	ret |= DECODE_RET(pDemod->SetXmlIfFreq(pDemod, pParam->freq));
	ret |= DECODE_RET(pDemod->SetXmlTunerCfgOverride(pDemod, 0x00000001));
	
	pDemodKernel->m_if = *pParam;
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
int REALTEK_I_QAM_SetMode(DEMOD* pDemodKernel, TV_OP_MODE mode)
{
	REALTEK_I_QAM* pRealtekIQAM;
	QAM_DEMOD_MODULE* pDemod;
	
	pRealtekIQAM = (REALTEK_I_QAM*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_QAM_DRIVER_DATA*) pRealtekIQAM->m_private)->pDemod;
	
	switch (mode) 
	{
	case TV_OP_MODE_NORMAL:
	case TV_OP_MODE_SCANING:
		REALTEK_I_QAM_INFO("demod enabled\n");
		break;
	case TV_OP_MODE_STANDBY:
		REALTEK_I_QAM_INFO("demod disabled\n");
		break;
	case TV_OP_MODE_ATV_NORMAL:
	case TV_OP_MODE_TP_ONLY:
		break;
	default:
		REALTEK_I_QAM_INFO("unknown TV_OP_MODE\n");
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
int REALTEK_I_QAM_SetTSMode(DEMOD* pDemodKernel, TS_PARAM* pParam)
{
	int ret = TUNER_CTRL_OK;
    unsigned char TsOutEn, TsSerial, ClkPhase;
	REALTEK_I_QAM* pRealtekIQAM;
	QAM_DEMOD_MODULE* pDemod;

	pRealtekIQAM = (REALTEK_I_QAM*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_QAM_DRIVER_DATA*) pRealtekIQAM->m_private)->pDemod;
	
	TsOutEn = (pParam->tsOutEn == 1) ? RTK_DEMOD_TS_EN : RTK_DEMOD_TS_DIS;
	TsSerial = (pParam->mode == SERIAL_MODE) ? RTK_DEMOD_TS_SERIAL : RTK_DEMOD_TS_PARALLEL;
	ClkPhase = (pParam->clk_pol == RISING_EDGE) ? RTK_DEMOD_TS_CLK_PHASE_NOR : RTK_DEMOD_TS_CLK_PHASE_INV;

	pDemodKernel->Lock(pDemodKernel);
	ret |= DECODE_RET(pDemod->SetTsClkRateMargin(pDemod, 0x00011170));//Set TV_REG_TSO_CLK_RATE_MARGIN to 7%
	ret |= DECODE_RET(pDemod->SetTsConfig(pDemod, TsOutEn, TsSerial, ClkPhase, RTK_DEMOD_TS_PACKETS_204));
	
	if (ret == TUNER_CTRL_OK)
		pDemodKernel->m_ts = *pParam;
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
int REALTEK_I_QAM_GetLockStatus(DEMOD* pDemodKernel, unsigned char* pLock)
{
	int ret = TUNER_CTRL_OK;
	unsigned char lock;
    unsigned int DemodStatus;
	REALTEK_I_QAM* pRealtekIQAM;
	QAM_DEMOD_MODULE* pDemod;

	pRealtekIQAM = (REALTEK_I_QAM*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_QAM_DRIVER_DATA*) pRealtekIQAM->m_private)->pDemod;
	
	if (DtvIsDemodClockEnable(RTK_DEMOD_MODE_QAM) == 0)
		return TUNER_CTRL_FAIL;

	pDemodKernel->Lock(pDemodKernel);
	ret |= DECODE_RET(pDemod->GetDemodStatus(pDemod, &DemodStatus));
    lock = (DemodStatus == 5) ? YES : NO;
	
    if (ret == TUNER_CTRL_OK)
       	*pLock = DECODE_LOCK(lock);
    else{
        *pLock = 0;
    }
	pDemodKernel->Unlock(pDemodKernel);
	//REALTEK_I_QAM_INFO("GetLockStatus = %u\n", DemodStatus);
	
	return TUNER_CTRL_OK;
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
int REALTEK_I_QAM_GetSignalInfo(DEMOD* pDemodKernel, TV_SIG_INFO* pInfo)
{
	unsigned int qam_mode = 0, spec_mode = 0;
	REALTEK_I_QAM* pRealtekIQAM;
	QAM_DEMOD_MODULE* pDemod;
	
	pRealtekIQAM = (REALTEK_I_QAM*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_QAM_DRIVER_DATA*) pRealtekIQAM->m_private)->pDemod;
	pInfo->mod = TV_MODULATION_QAM;
	
	pDemodKernel->Lock(pDemodKernel);
	pDemod->DemodCtrlUpdateCounters(pDemod);	
	pDemod->GetQamSizeMonitor(pDemod, &qam_mode);
	pDemod->GetSpectrumInversionMonitor(pDemod, &spec_mode);
	pDemodKernel->Unlock(pDemodKernel);
	
	switch (qam_mode) 
	{
	case QAM_DEMOD_QAM_64:
		pInfo->qam.constellation = QAM_CONST_64;
		break;
		
	case QAM_DEMOD_QAM_256:
		pInfo->qam.constellation = QAM_CONST_256;
		break;
	default:
		REALTEK_I_QAM_DBG("GetSignalInfo: unknown QAM mode\n");
		break;
	}

	if (spec_mode) 
	{
		pInfo->qam.spectrum_inverse = QAM_SPEC_INVERSE;
	} 
	else 
	{
		pInfo->qam.spectrum_inverse = QAM_SPEC_NORMAL;
	}
	
	REALTEK_I_QAM_INFO("GetSignalInfo: QAM_MODE = %u, SPEC_INV = %u\n", pInfo->qam.constellation, pInfo->qam.spectrum_inverse);

	return TUNER_CTRL_OK;
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
int REALTEK_I_QAM_GetSignalQuality(DEMOD* pDemodKernel, ENUM_TV_QUAL id, TV_SIG_QUAL* pQuality)
{
	int ret = TUNER_CTRL_OK;
	unsigned char lock, sqi = 0;
	unsigned int Eqout=0, PakNum=0, BadPakNum=0, ErrBit=0;
	unsigned int DemodStatus, IfAgcGain;
	REALTEK_I_QAM* pRealtekIQAM;
	QAM_DEMOD_MODULE* pDemod;

	pRealtekIQAM = (REALTEK_I_QAM*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_QAM_DRIVER_DATA*) pRealtekIQAM->m_private)->pDemod;
	
	if (DtvIsDemodClockEnable(RTK_DEMOD_MODE_QAM) == 0)
		return TUNER_CTRL_FAIL;

	pDemodKernel->Lock(pDemodKernel);
	ret |= (pDemod->GetDemodStatus(pDemod, &DemodStatus));
	lock = (DemodStatus == 5)? 1 : 0;
	ret |= (pDemod->DemodCtrlUpdateCounters(pDemod));
	
	switch (id) 
	{
	case TV_QUAL_NOSIG:
		pQuality->nosig = !(lock);
		break;				
		
	case TV_QUAL_INNERLOCK:
		pQuality->inner = lock;
		//REALTEK_I_QAM_INFO("InnerLock=%u\n",lock);
		break;				
		
	case TV_QUAL_SNR:
		ret |= pDemod->GetEqOutputSnr(pDemod, &Eqout);
		pQuality->snr = (Eqout/256)*10000;
		//REALTEK_I_QAM_INFO("SNR=%u\n", Eqout);
		break;				

	case TV_QUAL_BEC:
	case TV_QUAL_PEC:	
	case TV_QUAL_BER:
	case TV_QUAL_PER:
	case TV_QUAL_UCBLOCKS:		
		ret |= pDemod->GetMpegTsPacketNumber(pDemod, &PakNum);
		ret |= pDemod->GetBadPacketNumber(pDemod, &BadPakNum);
		ret |= pDemod->GetBitErrorNumber(pDemod, &ErrBit);
		ret |= pDemod->DemodCtrlResetCounters(pDemod);
		if (PakNum>0)
		{
			if (id == TV_QUAL_BEC)
			{
				pQuality->layer_ber.ber_num = ErrBit;//total error bits
				pQuality->layer_ber.ber_den = (PakNum*204*8);
			}
			else if (id == TV_QUAL_PEC)
			{
				pQuality->layer_per.per_num = BadPakNum;
				pQuality->layer_per.per_den = PakNum;
			}	
			else if (id == TV_QUAL_BER) 
				pQuality->ber = ((ErrBit*10000)/(PakNum*204*8));
			else if (id == TV_QUAL_PER) 
				pQuality->per = ((BadPakNum*10000)/PakNum);
			else if (id == TV_QUAL_UCBLOCKS) 
				pQuality->ucblocks = BadPakNum;	
		}
		else
		{
			if (id == TV_QUAL_BEC)
			{
				pQuality->layer_ber.ber_num = 0xffffffff;
				pQuality->layer_ber.ber_den = 0xffffffff;
			}
			else if (id == TV_QUAL_PEC)
			{
				pQuality->layer_per.per_num = 0xffffffff;
				pQuality->layer_per.per_den = 0xffffffff;
			}
			else if (id == TV_QUAL_BER) 
				pQuality->ber = 1;
			else if (id == TV_QUAL_PER) 
				pQuality->per = 1;
			else if (id == TV_QUAL_UCBLOCKS)  
				pQuality->ucblocks = 0xffffffff;
		}
		//REALTEK_I_QAM_INFO("PakNum=%u, BadPakNum=%u, Total Bit Error=%u\n", pQuality->layer_per.per_den, pQuality->layer_per.per_num, pQuality->layer_ber.ber_num);
		break;				
		
	case TV_QUAL_SIGNAL_STRENGTH:
		//ret |= DECODE_RET(pDemod->GetSignalSSI(pDemod, (int) pQuality->rflevel, &ssi));
		if(pQuality->rflevel >= -44 ){
			pQuality->strength = 100;
		}else if(pQuality->rflevel >= -64){
			pQuality->strength = 30 + (pQuality->rflevel + 64) * 7/2;
		}else if(pQuality->rflevel >= -80){
			pQuality->strength = (pQuality->rflevel + 80) * 15 / 8;
		}else{
			pQuality->strength = 0;
		}

		REALTEK_I_QAM_INFO("SSI=%d  rflevel = %d  \n", pQuality->strength,pQuality->rflevel);
		break;				
		
	case TV_QUAL_SIGNAL_QUALITY:
		ret |= DECODE_RET(pDemod->GetSignalQualityIndicator(pDemod, &sqi));
		pQuality->quality = sqi;
		break;		
		
	case TV_QUAL_AGC:
		ret |= DECODE_RET(pDemod->DemodCtrlUpdateAgc(pDemod));
		ret |= DECODE_RET(pDemod->GetIfAgcGain(pDemod, &IfAgcGain));
		IfAgcGain = IfAgcGain >> 20;
		pQuality->agc = IfAgcGain;
		break;		
                
    case TV_QUAL_DEMODFWVERSION:
		pQuality->DemodFwVersion = 0x000001;
		break;	
                
	default:
		REALTEK_I_QAM_DBG("unknown ENUM_TV_QUAL id\n");
		break;
	}
		
	pDemodKernel->Unlock(pDemodKernel);

	return TUNER_CTRL_OK;
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
int REALTEK_I_QAM_GetCarrierOffset(DEMOD* pDemodKernel, long* pOffset)
{
	int ret = TUNER_CTRL_OK;
	unsigned char lock = 0;
	unsigned int CarrierFreq;
	unsigned int DemodStatus;
	
	REALTEK_I_QAM* pRealtekIQAM;
	QAM_DEMOD_MODULE* pDemod;
	
	pRealtekIQAM = (REALTEK_I_QAM*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_QAM_DRIVER_DATA*) pRealtekIQAM->m_private)->pDemod;
	
	if (DtvIsDemodClockEnable(RTK_DEMOD_MODE_QAM) == 0)
		return TUNER_CTRL_FAIL;

	pDemodKernel->Lock(pDemodKernel);
	ret |= DECODE_RET(pDemod->GetDemodStatus(pDemod, &DemodStatus));
	lock = (DemodStatus == 5)? 1 : 0;
	
	if(lock == 0) 
	{
		REALTEK_I_QAM_INFO("GetCarrierOffset fail beacause demod is unlock\n");
		pDemodKernel->Unlock(pDemodKernel);
		
		return TUNER_CTRL_FAIL;
	}
	
	ret |= DECODE_RET(pDemod->GetCarrierFrequencyMonitor(pDemod, &CarrierFreq));

	if (ret == TUNER_CTRL_OK)
	{
		*pOffset = CarrierFreq;
		*pOffset = -(*pOffset + 6000000);
	}
	else
		*pOffset = 0;
	pDemodKernel->Unlock(pDemodKernel);

 	REALTEK_I_QAM_INFO("CarrierFreq = %u, GetCarrierOffset(Hz) = %ld\n", CarrierFreq, *pOffset);
	
	return ret;
}

/*----------------------------------------------------------------------
 * Func : GetDebugLogBuf
 *
 * Desc : Get the debug log Buf.
 *
 * Parm : 
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_QAM_GetDebugLogBuf(DEMOD* pDemodKernel, unsigned int* LogBufAddr, unsigned int* LogBufSize)
{
	int ret = TUNER_CTRL_OK;
	unsigned int ReadValue=0;
	REALTEK_I_QAM* pRealtekIQAM;
	QAM_DEMOD_MODULE* pDemod;
    
	pRealtekIQAM = (REALTEK_I_QAM*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_QAM_DRIVER_DATA*) pRealtekIQAM->m_private)->pDemod;
	pDemodKernel->Lock(pDemodKernel);
	if (pDemod) {
        ret|=pDemod->GetVirtualRegister(pDemod, TV_REG_ENSIGMA_SDK_BUFF_PTR, &ReadValue);
        * LogBufAddr = ReadValue;
        ret|=pDemod->GetVirtualRegister(pDemod, TV_REG_ENSIGMA_SDK_BUFF_SIZE, &ReadValue);
        * LogBufSize = ReadValue;
        if(ret!=TUNER_CTRL_OK)
        {
            * LogBufAddr = 0;
            * LogBufSize = 0;
        }
	}
    else
    {
        * LogBufAddr = 0;
        * LogBufSize = 0;
    }
    
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
int REALTEK_I_QAM_AcquireSignal(DEMOD* pDemodKernel, unsigned char WaitSignalLock)
{
	int ret = TUNER_CTRL_OK;
	unsigned long stime;
	unsigned char lock;
	unsigned int DemodStatus, AcqTime, no_signal;
	REALTEK_I_QAM* pRealtekIQAM;
	QAM_DEMOD_MODULE* pDemod;
	
	pRealtekIQAM = (REALTEK_I_QAM*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_QAM_DRIVER_DATA*) pRealtekIQAM->m_private)->pDemod;

	REALTEK_I_QAM_INFO("\033[1;32;31m" "%s %s %d, WaitSignalLock = %u\n" "\033[m", __FILE__, __func__, __LINE__, WaitSignalLock);
	
	pRealtekIQAM->m_auto_tune_en = 0;
	AcqTime = 0;
	
	pDemodKernel->Lock(pDemodKernel);
	#ifdef REALTEK_I_TUNER_AGC_SELF_CTRL
		tv_osal_msleep(50);//Tuner Self Control AGC, Wait for Tuner Stable in Demod
	#endif

	if (!WaitSignalLock) 
	{
		pDemodKernel->Unlock(pDemodKernel);
		pRealtekIQAM->m_auto_tune_en = 1;
		
		return TUNER_CTRL_OK;
	}

	stime = tv_osal_time();
	no_signal = YES;
	lock = NO;
	
	while ((tv_osal_time() - stime) <= 270) 
	{
		ret |= DECODE_RET(pDemod->GetDemodStatus(pDemod, &DemodStatus));
		tv_osal_msleep(5);
		if ((DemodStatus == 3) || (DemodStatus == 5))
		{
			no_signal = NO;
			break;
		}
	}
	
	REALTEK_I_QAM_INFO("no signal = %u, time = %lu\n", no_signal, tv_osal_time() - stime);

	if (no_signal == 1) goto acquire_signal_result;
	
	while ((tv_osal_time() - stime) <= 1000) 
	{
		tv_osal_msleep(5);
		ret |= DECODE_RET(pDemod->GetDemodStatus(pDemod, &DemodStatus));
		if (DemodStatus == 5) 
		{
			lock = YES;
			ret |= DECODE_RET(pDemod->GetDemodLockTime(pDemod, &AcqTime));
			//AcqTime /= 1000;
			//REALTEK_I_QAM_INFO("\033[1;32;31m" "QAM Signal Lock!!!\n" "\033[m");
			break;
		}
	}
	
	REALTEK_I_QAM_INFO("signal lock = %u, driver time = %lu, HW time = %u\n", lock, tv_osal_time()-stime, AcqTime);
	pDemodKernel->Unlock(pDemodKernel);

	return (lock) ? TUNER_CTRL_OK : TUNER_CTRL_NO_SIGNAL;
	
acquire_signal_result:
	pDemodKernel->Unlock(pDemodKernel);
	if (no_signal == 1)
		return TUNER_CTRL_NO_SIGNAL;
	else if (lock)
		return TUNER_CTRL_OK;
	else
		return TUNER_CTRL_NO_SIGNAL;
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
int REALTEK_I_QAM_ScanSignal(DEMOD* pDemodKernel, long* pOffset,	SCAN_RANGE range)
{
	REALTEK_I_QAM* pRealtekIQAM;
	QAM_DEMOD_MODULE* pDemod;
	
	pRealtekIQAM = (REALTEK_I_QAM*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_QAM_DRIVER_DATA*) pRealtekIQAM->m_private)->pDemod;

	return TUNER_CTRL_OK;
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
int REALTEK_I_QAM_ForwardI2C(DEMOD* pDemodKernel, unsigned char on_off)
{
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
int REALTEK_I_QAM_AutoTune(DEMOD* pDemodKernel)
{
#if 0
	REALTEK_I_QAM* pRealtekIQAM;
	QAM_DEMOD_MODULE* pDemod;
	
	pRealtekIQAM = (REALTEK_I_QAM*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_QAM_DRIVER_DATA*) pRealtekIQAM->m_private)->pDemod;
#endif

	return TUNER_CTRL_OK;
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
int REALTEK_I_QAM_InspectSignal(DEMOD* pDemodKernel)
{
	int ret = TUNER_CTRL_OK;
	long CrOffsetHz  = -1;
	unsigned char lock;
	unsigned int DemodStatus;
	unsigned int CarrierFreq = 0;
	unsigned int ErrBit = 1;
	unsigned int PakNum = 1;
	unsigned int TotalBit = 1;
	unsigned int BadPakNum = 1;
	unsigned int Eqout = 0;
	REALTEK_I_QAM* pRealtekIQAM;
	QAM_DEMOD_MODULE* pDemod;
	
	pRealtekIQAM = (REALTEK_I_QAM*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_QAM_DRIVER_DATA*) pRealtekIQAM->m_private)->pDemod;
	
	if (DtvIsDemodClockEnable(RTK_DEMOD_MODE_QAM) == 0)
		return TUNER_CTRL_OK;

	pDemodKernel->Lock(pDemodKernel);
	ret |= (pDemod->GetDemodStatus(pDemod, &DemodStatus));
	lock = (DemodStatus == 5)? 1 : 0;
	
	if (lock) 
	{
		ret |= pDemod->GetCarrierFrequencyMonitor(pDemod, &CarrierFreq);
		ret |= pDemod->GetEqOutputSnr(pDemod, &Eqout);
		ret |= pDemod->DemodCtrlUpdateCounters(pDemod);
		ret |= pDemod->GetMpegTsPacketNumber(pDemod, &PakNum);
		ret |= pDemod->GetBadPacketNumber(pDemod, &BadPakNum);
		ret |= pDemod->GetBitErrorNumber(pDemod, &ErrBit);
		ret |= pDemod->DemodCtrlResetCounters(pDemod);
		TotalBit = PakNum*204*8;
		CrOffsetHz = CarrierFreq;
	}

	pDemodKernel->Unlock(pDemodKernel);
#if 0
	REALTEK_I_QAM_INFO("lock=%u, error_rate(ber/per)=%f/%f, snr=%f, ofst(cr)=%ld\n",
				   lock,
				   (double)ErrBit/((double)TotalBit),
				   (double)BadPakNum/(double)PakNum,
				   (double)Eqout/256,
				   CrOffsetHz);
#endif

	ret = 1;

	return ret;
}


/*----------------------------------------------------------------------
 * Func : Activate
 *
 * Desc : Activate REALTEK_I QAM Demod
 *
 * Parm : N/A
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_QAM_Activate(DEMOD* pDemodKernel, unsigned char force_rst)
{
	REALTEK_I_QAM* pRealtekIQAM;
	QAM_DEMOD_MODULE* pDemod;
	
	pRealtekIQAM = (REALTEK_I_QAM*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_QAM_DRIVER_DATA*) pRealtekIQAM->m_private)->pDemod;
	
	pDemodKernel->Lock(pDemodKernel);
	if (DtvDemodInitialization(RTK_DEMOD_MODE_QAM, force_rst)) 
	{
		REALTEK_I_QAM_WARNING("Demod PLL changed, reinit QAM Demod\n");
		
		// pll has been changed and demod has been reset
		// we need to re-init demod
		if (pDemod->ActivateCore(pDemod) != FUNCTION_SUCCESS)
			goto activate_demod_fail;

		ClearDemodReset(RTK_DEMOD_MODE_QAM);

		if (pDemodKernel->SetTSMode(pDemodKernel, &pDemodKernel->m_ts) != TUNER_CTRL_OK)
			goto activate_demod_fail;

		if (pDemodKernel->SetTVSys(pDemodKernel, pDemodKernel->m_tv_sys) != TUNER_CTRL_OK)
			goto activate_demod_fail;
	}
	pDemodKernel->Unlock(pDemodKernel);

	return TUNER_CTRL_OK;

//--------------------------
activate_demod_fail:
	pDemodKernel->Unlock(pDemodKernel);
	
	return TUNER_CTRL_FAIL;
}


/*----------------------------------------------------------------------
 * Func : SetTvMode
 *
 * Desc : Set Mode of REALTEK_I_ALL
 *
 * Parm : mode :    RTK_DEMOD_MODE_DVBT : DVBT mode
 *                  RTK_DEMOD_MODE_DVBC  : DVBC mode
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_QAM_SetTvMode(DEMOD* pDemodKernel, TV_SYSTEM_TYPE mode)
{
	int ret = TUNER_CTRL_FAIL;
	REALTEK_I_QAM* pRealtekIQAM;

	pRealtekIQAM = (REALTEK_I_QAM*)(pDemodKernel->private_data);
	
	pDemodKernel->Lock(pDemodKernel);
	RTK_DEMOD_INFO("REALTEK_I_QAM::SetTvMode(%d)\n", mode);
	switch (mode) 
	{
	case TV_SYS_TYPE_OPENCABLE:
		RTK_DEMOD_INFO("Set to OPENCABLE\n");
		ret = pDemodKernel->Init(pDemodKernel);
		ret |= pDemodKernel->SetTSMode(pDemodKernel, &pDemodKernel->m_ts);
		if (ret != TUNER_CTRL_OK) 
		{
			RTK_DEMOD_WARNING("Set REALTEK_I_QAM to QAM mode failed\n");
			goto set_demod_mode_failed;
		}
		break;

	default:
		RTK_DEMOD_DBG("unknown TV_SYSTEM_TYPE\n");
		goto set_demod_mode_failed;
	}

	ret = TUNER_CTRL_OK;
	RTK_DEMOD_INFO("Set REALTEK_I_QAM to appointed DTV mode successed\n");

	pDemodKernel->Unlock(pDemodKernel);
	return ret;

set_demod_mode_failed:
	pDemodKernel->Unlock(pDemodKernel);
	
	return TUNER_CTRL_FAIL;
}

void REALTEK_I_QAM_Lock(DEMOD* pDemodKernel)
{
	//FUNCTION_NAME_PRINT("LOCK 0x%x\n",&pDemodKernel->m_lock);
	//mutex_lock(&pDemodKernel->m_lock);
}

void REALTEK_I_QAM_Unlock(DEMOD* pDemodKernel)
{
	//FUNCTION_NAME_PRINT("UN_LOCK 0x%x\n",&pDemodKernel->m_lock);
	//mutex_unlock(&pDemodKernel->m_lock);
}


/*-----------------------------------------------------------------
 *     BASE_INTERFACE for REALTEK_I_QAM API
 *----------------------------------------------------------------*/
void ReleaseRealtekIQamDriver(REALTEK_I_QAM_DRIVER_DATA *pDriver)
{
	kfree(pDriver);
}


REALTEK_I_QAM_DRIVER_DATA* AllocRealtekIQamDriver(
	COMM*               pComm,
	unsigned char       Addr,
	unsigned long       CrystalFreq
)
{
	REALTEK_I_QAM_DRIVER_DATA* pDriver = (REALTEK_I_QAM_DRIVER_DATA*) kmalloc(
										   sizeof(REALTEK_I_QAM_DRIVER_DATA) +
										   sizeof(QAM_DEMOD_MODULE)   +
										   sizeof(I2C_BRIDGE_MODULE)   +
										   sizeof(BASE_INTERFACE_MODULE), GFP_KERNEL);

	if (pDriver) 
	{
        BASE_INTERFACE_MODULE* pBIF;
	    QAM_DEMOD_MODULE* pDemod;

		memset(pDriver, 0, sizeof(REALTEK_I_QAM_DRIVER_DATA));
		pDriver->pDemod                = (QAM_DEMOD_MODULE*)(((unsigned char*)pDriver) + sizeof(REALTEK_I_QAM_DRIVER_DATA));
		pDriver->pBaseInterface        = (BASE_INTERFACE_MODULE*)(((unsigned char*)pDriver->pDemod) + sizeof(QAM_DEMOD_MODULE));
		pDriver->pI2CBridge            = (I2C_BRIDGE_MODULE*)(((unsigned char*)pDriver->pBaseInterface) + sizeof(BASE_INTERFACE_MODULE));
		pDriver->DeviceAddr            = Addr;
		pDriver->CrystalFreqHz         = CrystalFreq;

		// Init Base IF
		pBIF = pDriver->pBaseInterface;
		pBIF->I2cReadingByteNumMax      = RTK_DEMOD_BIF_RX_FIFO_DEPTH;
		pBIF->I2cWritingByteNumMax      = RTK_DEMOD_BIF_TX_FIFO_DEPTH;
		pBIF->I2cRead                   = __realtek_i2c_read;
		pBIF->I2cWrite                  = __realtek_i2c_write;
		pBIF->WaitMs                    = __realtek_wait_ms;
		pBIF->SetUserDefinedDataPointer = base_interface_SetUserDefinedDataPointer;
		pBIF->GetUserDefinedDataPointer = base_interface_GetUserDefinedDataPointer;
		pBIF->SetUserDefinedDataPointer(pBIF, (void*)pComm);

		// Init Demod Driver
		BuildRealtekIQamModule(&pDemod,
							  pDriver->pDemod,
							  pDriver->pBaseInterface,
							  pDriver->pI2CBridge,
							  Addr,
							  CrystalFreq);
	}
	return pDriver;
}


