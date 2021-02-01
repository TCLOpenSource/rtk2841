/***************************************************************************************************
  File        : demod_rtk_atsc.cpp
  Description : REALTEK_R_ATSC demod
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
//#include <kadp_OSAL.h>
#include "demodcore/foundation.h"
#include "demod_rtk_atsc.h"
#include "demod_rtk_atsc_priv.h"

#define REALTEK_R_ATSC_8051FW_PATCH
//#define REALTEK_R_ATSC_LGE_STREAM_PATCH_I37
/*----------------------------------------------------------------------
 * Func : REALTEK_R_ATSC
 *
 * Desc : constructor
 *
 * Parm : device_addr : device address
 *        output_mode : REALTEK_R_ATSC_OUT_IF_SERIAL / REALTEK_R_ATSC_OUT_IF_PARALLEL
 *        output_freq : REALTEK_R_ATSC_OUT_FREQ_6M / REALTEK_R_ATSC_OUT_FREQ_10M
 *        pComm       : hadle of COMM
 *
 * Retn : handle of demod
 *----------------------------------------------------------------------*/
void REALTEK_R_ATSC_Constructors(DEMOD* pDemodKernel, unsigned char addr, unsigned char output_mode, unsigned char output_freq, COMM* pComm)
{
	REALTEK_R_ATSC* pRealtekRATSC;

	pDemodKernel->private_data = kmalloc(sizeof(REALTEK_R_ATSC), GFP_KERNEL);
	pRealtekRATSC = (REALTEK_R_ATSC*)(pDemodKernel->private_data);
	Demod_Constructors(pDemodKernel);
	
	pDemodKernel->m_id                 = DTV_DEMOD_REALTEK_R_ATSC;
	pDemodKernel->m_addr               = addr;
	pDemodKernel->m_pTuner             = NULL;
	pDemodKernel->m_pComm              = pComm;
	pDemodKernel->m_ScanRange          = SCAN_RANGE_2_6;
	pDemodKernel->m_ScanMode           = CH_UNKNOW;
	pDemodKernel->m_Capability         = TV_SYS_TYPE_ATSC;
	pDemodKernel->m_update_interval_ms = 1000;
	pDemodKernel->m_if.freq            = 36125000;
	pDemodKernel->m_if.inversion       = 1;
	pDemodKernel->m_if.agc_pola        = 0;
	pDemodKernel->m_clock              = CRYSTAL_FREQ_27000000HZ;
	pRealtekRATSC->m_output_freq        = output_freq;
	pRealtekRATSC->m_private            = (void*) AllocRealtekRAtscDriver(
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
    pDemodKernel->m_ts.tsOutEn 		   = 1;
	pRealtekRATSC->m_low_snr_detect     = 0;
	pRealtekRATSC->m_low_snr_recover    = 0;
	pRealtekRATSC->m_auto_tune_enable   = 0;
	pDemodKernel->m_pComm->SetTargetName(pDemodKernel->m_pComm, pDemodKernel->m_addr, "REALTEK_R_ATSC");
	pRealtekRATSC->m_pTunerOptReg       = NULL;
	pRealtekRATSC->m_TunerOptRegCnt     = 0;
	pDemodKernel->Init = REALTEK_R_ATSC_Init;
	pDemodKernel->Reset = Demod_Reset;
	pDemodKernel->AcquireSignal = REALTEK_R_ATSC_AcquireSignal;
	pDemodKernel->ScanSignal = REALTEK_R_ATSC_ScanSignal;
	pDemodKernel->SetIF = REALTEK_R_ATSC_SetIF;
	pDemodKernel->SetTSMode = REALTEK_R_ATSC_SetTSMode;
	pDemodKernel->SetTVSysEx = REALTEK_R_ATSC_SetTVSysEx;
	pDemodKernel->SetMode = REALTEK_R_ATSC_SetMode;
	pDemodKernel->SetTVSys = REALTEK_R_ATSC_SetTVSys;
	pDemodKernel->GetLockStatus = REALTEK_R_ATSC_GetLockStatus;
	pDemodKernel->GetSegmentNum = Demod_GetSegmentNum;
	pDemodKernel->GetSignalInfo = REALTEK_R_ATSC_GetSignalInfo;
	pDemodKernel->GetSignalQuality = REALTEK_R_ATSC_GetSignalQuality;
    pDemodKernel->ChangeT2PLP = Demod_ChangeT2PLP;
	pDemodKernel->GetT2PLPInfo = Demod_GetT2PLPInfo;
	pDemodKernel->GetT2L1PreInfo = Demod_GetT2L1PreInfo;
	pDemodKernel->GetT2L1PostInfo = Demod_GetT2L1PostInfo;
	pDemodKernel->GetDemodStatus = Demod_GetDemodStatus;
	pDemodKernel->GetCarrierOffset = REALTEK_R_ATSC_GetCarrierOffset;
	pDemodKernel->ForwardI2C = REALTEK_R_ATSC_ForwardI2C;
	pDemodKernel->AutoTune = REALTEK_R_ATSC_AutoTune;
	pDemodKernel->GetCapability = Demod_GetCapability;
	pDemodKernel->Suspend = Demod_Suspend;
	pDemodKernel->Resume = Demod_Resume;
	pDemodKernel->SetTvMode = REALTEK_R_ATSC_SetTvMode;
	pDemodKernel->DebugInfo = REALTEK_R_ATSC_DebugInfo;	  	  // Add monitor function that used to monitor demod status
	pDemodKernel->InspectSignal = REALTEK_R_ATSC_InspectSignal; // Add monitor function that used to monitor demod status
	pDemodKernel->AttachTuner = Demod_AttachTuner;
	pDemodKernel->GetTSParam = Demod_GetTSParam;
	pDemodKernel->Lock = REALTEK_R_ATSC_Lock;
	pDemodKernel->Unlock = REALTEK_R_ATSC_Unlock;
	//pDemodKernel->Activate = REALTEK_R_ATSC_Activate;
	pDemodKernel->Destory = REALTEK_R_ATSC_Destructors;
}


/*----------------------------------------------------------------------
 * Func : ~REALTEK_R_ATSC
 *
 * Desc : Destructor of REALTEK_R_ATSC
 *
 * Parm : pDemod : handle of Demod
 *
 * Retn : N/A
 *----------------------------------------------------------------------*/
void REALTEK_R_ATSC_Destructors(DEMOD* pDemodKernel)
{
	REALTEK_R_ATSC* pRealtekRATSC;
	pRealtekRATSC = (REALTEK_R_ATSC*)(pDemodKernel->private_data);
	
	if (pRealtekRATSC->m_private != NULL)
		ReleaseRealtekRAtscDriver((REALTEK_R_ATSC_DRIVER_DATA*)pRealtekRATSC->m_private);

	kfree(pRealtekRATSC);
	//pDemodKernel->Destory(pDemodKernel);
	REALTEK_R_ATSC_INFO("REALTEK_R_ATSC_Destructors Complete\n"); 
}


/*----------------------------------------------------------------------
 * Func : Init
 *
 * Desc : Initial realtek_r
 *
 * Parm : N/A
 *
 * Retn : TUNER_CTRL_OK / TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_R_ATSC_Init(DEMOD* pDemodKernel)
{
	int i;
	unsigned char PGAEnable = 0;
	IFADCGAIN PGAGain;
	
	REALTEK_R_ATSC* pRealtekRATSC;
	ATSC_DEMOD_MODULE* pDemod;
	
	pRealtekRATSC = (REALTEK_R_ATSC*)(pDemodKernel->private_data);
	
	if (pDemodKernel->m_pComm == NULL || pRealtekRATSC->m_private == NULL)
		return TUNER_CTRL_FAIL;
	
	pDemod = ((REALTEK_R_ATSC_DRIVER_DATA*) pRealtekRATSC->m_private)->pDemod;

	pDemodKernel->Lock(pDemodKernel);
	pDemodKernel->m_ScanMode = CH_UNKNOW;

	//DtvDemodClockEnable(1);
	DtvDemodInitialization(RTK_DEMOD_MODE_ATSC, 1);
	pRealtekRATSC->m_patch_cnt = 0;
	
	// check tuner information
	PGAEnable = 2;
	PGAGain = PGAFIX_2DB;
	if (pDemodKernel->m_pTuner) {
		TUNER_PARAM Param;

		if (pDemodKernel->m_pTuner->GetParam(pDemodKernel->m_pTuner, TV_SYS_ATSC, &Param) == TUNER_CTRL_OK) {
			switch (Param.id) {
			case TV_TUNER_SILICONLABS_SI2151:
				REALTEK_R_ATSC_INFO("Tuner id %u, TV_TUNER_SILICONLABS_SI2151\n", Param.id);
				pRealtekRATSC->m_pTunerOptReg = (REG_VALUE_ENTRY*) SI215x_OPT_VALUE_ATSC;
				pRealtekRATSC->m_TunerOptRegCnt  = sizeof(SI215x_OPT_VALUE_ATSC) / sizeof(REG_VALUE_ENTRY);
				break;
			case TV_TUNER_SILICONLABS_SI2178B:
			case TV_TUNER_NO_TUNER:
				REALTEK_R_ATSC_INFO("Tuner id %u, TV_TUNER_SILICONLABS_SI2178B\n", Param.id);
				pRealtekRATSC->m_pTunerOptReg = (REG_VALUE_ENTRY*) SI2178B_OPT_VALUE_ATSC;
				pRealtekRATSC->m_TunerOptRegCnt  = sizeof(SI2178B_OPT_VALUE_ATSC) / sizeof(REG_VALUE_ENTRY);
				break;
			case TV_TUNER_MAXLINEAR_MXL661:
				REALTEK_R_ATSC_INFO("Tuner id %u, TV_TUNER_MAXLINEAR_MXL661\n", Param.id);
				break;
			case TV_TUNER_NXP_TDA18275A:
				REALTEK_R_ATSC_INFO("Tuner id %u, TV_TUNER_NXP_TDA18275A\n", Param.id);
				break;
			case TV_TUNER_RAFAEL_R840:
				REALTEK_R_ATSC_INFO("Tuner id %u, TV_TUNER_RAFAEL_R840\n", Param.id);
				break;
			default:
				REALTEK_R_ATSC_INFO("unknown tuner id %u, using default setting\n", Param.id);
				break;
			}

			pDemodKernel->m_if.freq      = Param.if_freq;
			pDemodKernel->m_if.inversion = Param.if_inversion;
			pDemodKernel->m_if.agc_pola  = Param.if_agc_pola;

			REALTEK_R_ATSC_INFO("if_freq = %lu, if_inversion = %u, if_agc_pola = %u\n", 
				pDemodKernel->m_if.freq, pDemodKernel->m_if.inversion, pDemodKernel->m_if.agc_pola);
		}
	}

	DtvPGAControl(PGAEnable, PGAGain);

	// Initial Driver
	if (pDemod->Initialize(pDemod) != FUNCTION_SUCCESS)
		goto init_fail;

	ClearDemodReset(RTK_DEMOD_MODE_ATSC);

	// Run Optimize Configuration for specified tuner
	for (i = 0; i < pRealtekRATSC->m_TunerOptRegCnt; i++) {
		int Reg = pRealtekRATSC->m_pTunerOptReg[i].RegBitName;
		unsigned long Val = pRealtekRATSC->m_pTunerOptReg[i].Value;
		
		if (pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, Reg, Val) != FUNCTION_SUCCESS)
			goto init_fail;
	}

	if (pDemodKernel->SetIF(pDemodKernel, &pDemodKernel->m_if) != TUNER_CTRL_OK)
		goto init_fail;

	if (pDemodKernel->SetTSMode(pDemodKernel, &pDemodKernel->m_ts) != TUNER_CTRL_OK)
		goto init_fail;

	REALTEK_R_ATSC_DBG("REALTEK_R_ATSC Init Complete\n");
	pDemodKernel->Unlock(pDemodKernel);
	return TUNER_CTRL_OK;

init_fail:
	REALTEK_R_ATSC_WARNING("REALTEK_R_ATSC Init Fail\n");
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
int REALTEK_R_ATSC_SetTVSys(DEMOD* pDemodKernel, TV_SYSTEM sys)
{
	REALTEK_R_ATSC* pRealtekRATSC;
	pRealtekRATSC = (REALTEK_R_ATSC*)(pDemodKernel->private_data);
	
	REALTEK_R_ATSC_INFO("\033[1;32;31m" "%s %s %d, sys = %d\n" "\033[m", __FILE__, __func__, __LINE__, sys);
	
	return pDemodKernel->SetTVSysEx(pDemodKernel, sys, NULL);
}


/*----------------------------------------------------------------------
 * Func : SetTVSysEx
 *
 * Desc : Set TV System
 *
 * Parm : sys : TV System
 *        pSigInfo : signal information
 *
 * Retn : TUNER_CTRL_OK / TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_R_ATSC_SetTVSysEx(DEMOD* pDemodKernel, TV_SYSTEM sys, const TV_SIG_INFO*  pSigInfo)
{
	CH_MODE AtscScanMode;
	TUNER_PARAM Param;
	REALTEK_R_ATSC* pRealtekRATSC;
	ATSC_DEMOD_MODULE* pDemod;
	
	pRealtekRATSC = (REALTEK_R_ATSC*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_R_ATSC_DRIVER_DATA*) pRealtekRATSC->m_private)->pDemod;

	if (pSigInfo != NULL)
		AtscScanMode = pSigInfo->vsb.scan_mode ? CH_SCAN_MODE : CH_NORMAL_MODE;
	else
		AtscScanMode = CH_NORMAL_MODE;

	REALTEK_R_ATSC_INFO("\033[1;32;31m" "%s %s %d, system = %d, AtscScanMode = %d\n" "\033[m", __FILE__, __func__, __LINE__, sys, AtscScanMode);
	
	if (!IsAtscSys(sys))
	{
		REALTEK_R_ATSC_WARNING("Set TV system failed, unsupported TV system\n");
		
		return  TUNER_CTRL_FAIL;
	}
	pDemodKernel->m_tv_sys = sys;
	pRealtekRATSC->m_patch_cnt = 0;
	pDemodKernel->Lock(pDemodKernel);
	
	if (pDemodKernel->m_pTuner->GetParam(pDemodKernel->m_pTuner, pDemodKernel->m_tv_sys, &Param) == TUNER_CTRL_OK) 
	{
		if ((pDemodKernel->m_if.freq != Param.if_freq) || (pDemodKernel->m_if.inversion != Param.if_inversion) || (pDemodKernel->m_if.agc_pola != Param.if_agc_pola)) 
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
	
	if (AtscScanMode == CH_SCAN_MODE) {
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, DW_8051_RST, 0); //reset 8051
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_FFE_SP_HOLD, 0);
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_CR_LPF_SHIFT, 537);
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_CR_PMU_COMP1, 0);
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_CR_FMU_UPD_OPT, 4);
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_FSM_RAM_ROW, 32);
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_FSM_RAM_COL, 14);
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_FSM_RAM_DATA, 207);
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_FSM_RAM_COL, 15);
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_FSM_RAM_DATA, 218);
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_FSM_RAM_ROW, 33);
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_FSM_RAM_COL, 14);
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_FSM_RAM_DATA, 207);
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_FSM_RAM_COL, 15);
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_FSM_RAM_DATA, 218);
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_FSM_RAM_ROW, 34);
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_FSM_RAM_COL, 14);
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_FSM_RAM_DATA, 207);
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_FSM_RAM_COL, 15);
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_FSM_RAM_DATA, 217);
	} else {
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, DW_8051_RST, 0); //reset 8051
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_CR_LPF_SHIFT, 537);
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_CR_PMU_COMP1, 0);
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_CR_FMU_UPD_OPT, 4);
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_FSM_RAM_ROW, 32);
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_FSM_RAM_COL, 14);
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_FSM_RAM_DATA, 207);
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_FSM_RAM_COL, 15);
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_FSM_RAM_DATA, 218);
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_FSM_RAM_ROW, 33);
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_FSM_RAM_COL, 14);
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_FSM_RAM_DATA, 207);
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_FSM_RAM_COL, 15);
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_FSM_RAM_DATA, 218);
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_FSM_RAM_ROW, 34);
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_FSM_RAM_COL, 14);
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_FSM_RAM_DATA, 207);
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_FSM_RAM_COL, 15);
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_FSM_RAM_DATA, 217);

#ifdef REALTEK_R_ATSC_8051FW_PATCH
		//Set dummy register for channel change indicator
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, Dummy_CHANGE_CHANNEL_IND, 1);
#endif

		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, DW_8051_RST, 1);
	}

#ifdef REALTEK_R_ATSC_LGE_STREAM_PATCH_I37
	pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_LD_MSE_FIELD_TH_H, 0x0);
	pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_LD_MSE_FIELD_TH_L, 0x2fa0000);
#endif

	pDemod->SoftwareReset(pDemod);   //Restart demod FSM
	pDemodKernel->m_ScanMode = AtscScanMode;
	pDemodKernel->Unlock(pDemodKernel);
	return TUNER_CTRL_OK;
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
int REALTEK_R_ATSC_SetIF(DEMOD* pDemodKernel, IF_PARAM* pParam)
{
	int ret = TUNER_CTRL_OK;
	
	REALTEK_R_ATSC* pRealtekRATSC;
	ATSC_DEMOD_MODULE* pDemod;
	
	pRealtekRATSC = (REALTEK_R_ATSC*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_R_ATSC_DRIVER_DATA*) pRealtekRATSC->m_private)->pDemod;

	pDemodKernel->Lock(pDemodKernel);
	REALTEK_R_ATSC_INFO("SetIF: IF_freq = %lu, spectrumn inv = %u, agc_pola = %u\n", pParam->freq, pParam->inversion, pParam->agc_pola);

	ret  = DECODE_RET(pDemod->SetIfFreqHz(pDemod, pParam->freq));
	ret |= DECODE_RET(pDemod->SetSpectrumMode(pDemod, (pParam->inversion) ? 0 : 1));
	ret |= DECODE_RET(pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_POLAR_IFAGC, pParam->agc_pola));
	ret |= DECODE_RET(pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_OPT_IF_AAGC_DRIVE, 1));   // push pull mode
	//ret |= DECODE_RET(pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_OPT_PAR_IF_SD_IB, 1));   // agc if non-invert
	
	ret |= DECODE_RET(pDemod->SoftwareReset(pDemod));
	pRealtekRATSC->m_low_snr_detect     = 0;
	pRealtekRATSC->m_low_snr_recover    = 0;
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
int REALTEK_R_ATSC_SetMode(DEMOD* pDemodKernel, TV_OP_MODE mode)
{
	unsigned char val;
	REALTEK_R_ATSC* pRealtekRATSC;
	ATSC_DEMOD_MODULE* pDemod;
	
	pRealtekRATSC = (REALTEK_R_ATSC*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_R_ATSC_DRIVER_DATA*) pRealtekRATSC->m_private)->pDemod;
	
	switch (mode) {
	case TV_OP_MODE_NORMAL:
	case TV_OP_MODE_SCANING:
		REALTEK_R_ATSC_INFO("demod enabled\n");
		val = 1;
		pDemod->RegAccess.Addr16Bit.SetRegBytes(pDemod, 0xd004, &val, 1);  // enable ATSC demod
		pDemodKernel->AcquireSignal(pDemodKernel, 0);             // reset demod....
		break;
	case TV_OP_MODE_STANDBY:
		REALTEK_R_ATSC_INFO("demod disabled\n");
		val = 0;
		pDemod->RegAccess.Addr16Bit.SetRegBytes(pDemod, 0xd004, &val, 1);  // disable ATSC demod
		break;
	case TV_OP_MODE_ATV_NORMAL:
	case TV_OP_MODE_TP_ONLY:
		break;
	default:
		REALTEK_R_ATSC_INFO("unknown TV_OP_MODE\n");
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
int REALTEK_R_ATSC_SetTSMode(DEMOD* pDemodKernel, TS_PARAM* pParam)
{
	int ret = TUNER_CTRL_OK;
	
	REALTEK_R_ATSC* pRealtekRATSC;
	ATSC_DEMOD_MODULE* pDemod;
	
	pRealtekRATSC = (REALTEK_R_ATSC*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_R_ATSC_DRIVER_DATA*) pRealtekRATSC->m_private)->pDemod;

	pDemodKernel->Lock(pDemodKernel);
	switch (pParam->mode) {
	case PARALLEL_MODE:
		REALTEK_R_ATSC_DBG("TS Mode: PARALLEL\n");
		ret  = DECODE_RET(pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_SERIAL,   0));
		ret  = DECODE_RET(pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_CDIV_PH0, 5));
		ret  = DECODE_RET(pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_CDIV_PH1, 5));
		break;
	case SERIAL_MODE:
		REALTEK_R_ATSC_DBG("TS Mode: SERIAL\n");
		ret  = DECODE_RET(pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_SERIAL,   1));
		ret  = DECODE_RET(pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_CDIV_PH0, 0));
		ret  = DECODE_RET(pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_CDIV_PH1, 0));
		break;
	default:
		REALTEK_R_ATSC_DBG("unknown TS Mode\n");
		ret = TUNER_CTRL_FAIL;
		break;
	}

	switch (pParam->clk_pol) {
	case RISING_EDGE:
		REALTEK_R_ATSC_DBG("MPEG CLK POL: RISING_EDGE\n");
		ret  = DECODE_RET(pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_CKOUTPAR, 1));
		break;
	case FALLING_EDGE:
		REALTEK_R_ATSC_DBG("MPEG CLK POL: FALLING_EDGE\n");
		ret  = DECODE_RET(pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_CKOUTPAR, 0));
		break;
	default:
		REALTEK_R_ATSC_DBG("unknown MPEG CLK POL\n");
		ret = TUNER_CTRL_FAIL;
		break;
	}

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
int REALTEK_R_ATSC_GetLockStatus(DEMOD* pDemodKernel, unsigned char* pLock)
{
    int ret = TUNER_CTRL_OK;
    int FrameLock;

	REALTEK_R_ATSC* pRealtekRATSC;
	ATSC_DEMOD_MODULE* pDemod;
	
	pRealtekRATSC = (REALTEK_R_ATSC*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_R_ATSC_DRIVER_DATA*) pRealtekRATSC->m_private)->pDemod;

	if (DtvIsDemodClockEnable(RTK_DEMOD_MODE_ATSC) == 0)
		return TUNER_CTRL_FAIL;

	pDemodKernel->Lock(pDemodKernel);
	ret = DECODE_RET(pDemod->IsFrameLocked(pDemod, &FrameLock));

	if (ret == TUNER_CTRL_OK)
		*pLock = DECODE_LOCK(FrameLock);

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
int REALTEK_R_ATSC_GetSignalInfo(DEMOD* pDemodKernel, TV_SIG_INFO* pInfo)
{
	REALTEK_R_ATSC*	pRealtekRATSC;
	ATSC_DEMOD_MODULE*	pDemod;
	
	pRealtekRATSC = (REALTEK_R_ATSC*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_R_ATSC_DRIVER_DATA*) pRealtekRATSC->m_private)->pDemod;
	
	pInfo->mod = TV_MODULATION_VSB;
	pInfo->vsb.level = 8;
	REALTEK_R_ATSC_INFO("GetSignalInfo: level = %u\n", pInfo->vsb.level);
	
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
int REALTEK_R_ATSC_GetSignalQuality(DEMOD* pDemodKernel, ENUM_TV_QUAL id,	TV_SIG_QUAL* pQuality)
{
	int ret = TUNER_CTRL_OK;
	
	unsigned char FrameLock = 0;
	int LockStatus = 0;
	long SnrNum, SnrDen;
	unsigned long BerNum = 1, BerDen = 1;
	unsigned long PerNum = 1, PerDen = 1;
	long IfAgc = -1;
	
	REALTEK_R_ATSC* pRealtekRATSC;
	ATSC_DEMOD_MODULE* pDemod;
	
	pRealtekRATSC = (REALTEK_R_ATSC*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_R_ATSC_DRIVER_DATA*) pRealtekRATSC->m_private)->pDemod;

	if (DtvIsDemodClockEnable(RTK_DEMOD_MODE_ATSC) == 0)
		return TUNER_CTRL_FAIL;

	pDemodKernel->GetLockStatus(pDemodKernel, &FrameLock);
	pDemodKernel->Lock(pDemodKernel);
	
	switch (id) {
	case TV_QUAL_NOSIG :
		ret = pDemod->IsNoSig(pDemod, &LockStatus);
		pQuality->nosig = (LockStatus) ? 1 : 0;
		break;

	case TV_QUAL_INNERLOCK :
		ret = pDemod->IsInnerLocked(pDemod, &LockStatus);
		pQuality->inner = (LockStatus) ? 1 : 0;
		break;

	case TV_QUAL_SNR :
		ret = DECODE_RET(pDemod->GetSnrDb(pDemod, &SnrNum, &SnrDen));

		if (ret == TUNER_CTRL_OK)
			pQuality->snr = SnrNum * 10000 / SnrDen;
		break;

	case TV_QUAL_BEC :
	case TV_QUAL_PEC :
	case TV_QUAL_BER :
	case TV_QUAL_PER :
		ret = (FrameLock) ? DECODE_RET(pDemod->GetErrorRate(pDemod,  5, 1000, &BerNum, &BerDen, &PerNum, &PerDen)) : TUNER_CTRL_OK;
		REALTEK_R_ATSC_DBG("BerNum = %lu, BerDen = %lu, PerNum = %lu, PerDen = %lu\n", BerNum, BerDen, PerNum, PerDen);
		
		if (id == TV_QUAL_BER)
			pQuality->ber = BerNum * 10000 / BerDen;
		else if (id == TV_QUAL_PER)
			pQuality->per = PerNum * 10000 / PerDen;
		else if (id == TV_QUAL_BEC) {
			pQuality->layer_ber.ber_num = BerNum;
			pQuality->layer_ber.ber_den = BerDen;
		} else if (id == TV_QUAL_PEC) {
			pQuality->layer_per.per_num = PerNum;
			pQuality->layer_per.per_den = PerDen;
		}
		break;

	case TV_QUAL_UCBLOCKS :
		pQuality->ucblocks = 0;
		ret = TUNER_CTRL_OK;
		break;

	case TV_QUAL_SIGNAL_STRENGTH:
		#ifdef GET_SIGNAL_STRENGTH_FROM_SNR
		ret = pDemodKernel->GetSignalQuality(pDemodKernel, TV_QUAL_SNR, pQuality);

		if (ret == TUNER_CTRL_OK)
			pQuality->strength = Snr2Str(pQuality->snr / 10000); // convert snr to signal strength
		#else
		unsigned long SignalStrength;

		ret = DECODE_RET(pDemod->GetSignalStrength(pDemod, &SignalStrength));

		if (ret == TUNER_CTRL_OK)
			pQuality->strength = (unsigned char) SignalStrength;
		#endif
		break;

	case TV_QUAL_SIGNAL_QUALITY:
		ret = pDemodKernel->GetSignalQuality(pDemodKernel, TV_QUAL_BER, pQuality);

		if (ret == TUNER_CTRL_OK)
			pQuality->quality = Ber2Quality(pQuality->ber);  // convert ber to signal quality
		break;

	case TV_QUAL_AGC:
		ret = pDemod->GetIfAgc(pDemod, &IfAgc);

		if (ret == TUNER_CTRL_OK)
			pQuality->agc = ((IfAgc + 8191) * 100) / 16384;
		break;

	default:
		REALTEK_R_ATSC_DBG("unknown ENUM_TV_QUAL id\n");
		ret = TUNER_CTRL_FAIL;
		break;
	}

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
int REALTEK_R_ATSC_GetCarrierOffset(DEMOD* pDemodKernel, long* pOffset)
{
	int ret = TUNER_CTRL_OK;
    unsigned char LockStatus = 0;

	REALTEK_R_ATSC* pRealtekRATSC;
	ATSC_DEMOD_MODULE* pDemod;
	
	pRealtekRATSC = (REALTEK_R_ATSC*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_R_ATSC_DRIVER_DATA*) pRealtekRATSC->m_private)->pDemod;

	pDemodKernel->Lock(pDemodKernel);
	pDemodKernel->GetLockStatus(pDemodKernel, &LockStatus);
	pDemodKernel->Unlock(pDemodKernel);

	if (LockStatus == 0) {
		REALTEK_R_ATSC_INFO("GetCarrierOffset fail beacause demod is unlock\n");
		return TUNER_CTRL_FAIL;
	}

	pDemodKernel->Lock(pDemodKernel);
	ret = DECODE_RET(pDemod->GetCrOffsetHz(pDemod, pOffset));

	if (ret == TUNER_CTRL_OK) {
		/*-----------------------------------------------------------------
		  CrOffset = Current Frequency - Target Frequency
		  returned offset = Target Freq - Current Offset = -CrOffset
		  Note: REALTEK_R ATSC Demod will handle IF polarity automatically
		------------------------------------------------------------------*/
		*pOffset *= -1;
	} else
		*pOffset = 0;

	pDemodKernel->Unlock(pDemodKernel);
	REALTEK_R_ATSC_INFO("Carrier Offset = %ld Hz\n", *pOffset);
	
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
int REALTEK_R_ATSC_GetDebugLogBuf(DEMOD* pDemodKernel, unsigned int* LogBufAddr, unsigned int* LogBufSize)
{
	int ret = TUNER_CTRL_OK;
	
	REALTEK_R_ATSC* pRealtekRATSC;
	ATSC_DEMOD_MODULE* pDemod;
	
	pRealtekRATSC = (REALTEK_R_ATSC*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_R_ATSC_DRIVER_DATA*) pRealtekRATSC->m_private)->pDemod;

    //unsigned int ReadValue=0;
    pDemodKernel->Lock(pDemodKernel);
	
	#if 0
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
    #endif
	
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
 *        0 : don't wait
 *          others: wait for signal lock
 *
 * Retn : TUNER_CTRL_OK / TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_R_ATSC_AcquireSignal(DEMOD* pDemodKernel, unsigned char WaitSignalLock)
{
    unsigned long stime;
	int lock = 0, no_signal = 1;

#ifdef REALTEK_R_ATSC_LGE_STREAM_PATCH_I37
	unsigned long BerNum = 1, BerDen = 1;
	unsigned long PerNum = 1, PerDen = 1;
	unsigned long percnt = 0;
#endif

	REALTEK_R_ATSC* pRealtekRATSC;
	ATSC_DEMOD_MODULE* pDemod;
	
	pRealtekRATSC = (REALTEK_R_ATSC*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_R_ATSC_DRIVER_DATA*) pRealtekRATSC->m_private)->pDemod;

	REALTEK_R_ATSC_INFO("\033[1;32;31m" "%s %s %d, WaitSignalLock = %u\n" "\033[m", __FILE__, __func__, __LINE__, WaitSignalLock);

	if (!WaitSignalLock)
		return TUNER_CTRL_OK;

	pDemodKernel->Lock(pDemodKernel);
	pRealtekRATSC->m_auto_tune_enable = 0;
	stime = tv_osal_time();

	while ((tv_osal_time() - stime) <= 200) {
		pDemod->IsNoSig(pDemod, &no_signal);
		tv_osal_msleep_interruptible(5);
		
		if (no_signal == 0) break;
	}
	REALTEK_R_ATSC_INFO("no signal = %d, time = %lu\n", no_signal, tv_osal_time() - stime);

	if (no_signal == 1) goto acquire_signal_result;

	while ((tv_osal_time() - stime) <= 1100) {
		tv_osal_msleep_interruptible(5);
		pDemod->IsInnerLocked(pDemod, &lock);
		
		if (lock) break;
	}
	REALTEK_R_ATSC_INFO("demod inner lock = %d, time = %lu\n", lock, tv_osal_time() - stime);

#ifdef REALTEK_R_ATSC_LGE_STREAM_PATCH_I37
	if (lock == 0) goto acquire_signal_result;
	
	if (pDemodKernel->m_ScanMode == CH_NORMAL_MODE)
	{
		pDemodKernel->Unlock(pDemodKernel);
		return TUNER_CTRL_OK;
	}

	while ((tv_osal_time() - stime) <= 9550) {
		//pDemod->IsInnerLocked(pDemod, &lock2);
		pDemod->GetErrorRate(pDemod,  5, 1000, &BerNum, &BerDen, &PerNum, &PerDen);
		//REALTEK_R_ATSC_INFO("lock2 = %d, PerNum = %lu, PerDen = %lu, percnt = %lu, dtime = %lu\n", lock2, PerNum, PerDen, percnt, tv_osal_time() - stime);

		if (PerNum == 0) 
			break;
		else if (PerNum * 5 < PerDen) 
			percnt++;
		else percnt = 0;

		if (percnt == 1) {
			pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_LD_AI_EN_5, 0);
			//pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_LD_MSE_FIELD_TH_1, 0x37216ec);
			pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_LD_MSE_FIELD_TH_H, 0x0);
			pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_LD_MSE_FIELD_TH_L, 0x37216ec);
			pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_LD_AI_EN_5, 1);
		}

		if (percnt > 2) break;
		tv_osal_msleep_interruptible(15);
	}

	if (percnt < 1) {
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_LD_AI_EN_5, 0);
		//pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_LD_MSE_FIELD_TH_1, 0x37216ec);
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_LD_MSE_FIELD_TH_H, 0x0);
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_LD_MSE_FIELD_TH_L, 0x37216ec);
		pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_LD_AI_EN_5, 1);
	}
	REALTEK_R_ATSC_INFO("PerNum = %lu, PerDen = %lu, dtime = %lu\n", PerNum, PerDen, tv_osal_time() - stime);
#endif

acquire_signal_result:
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
int REALTEK_R_ATSC_ScanSignal(DEMOD* pDemodKernel, long* pOffset, SCAN_RANGE range)
{
	REALTEK_R_ATSC* pRealtekRATSC;
	ATSC_DEMOD_MODULE* pDemod;
	
	pRealtekRATSC = (REALTEK_R_ATSC*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_R_ATSC_DRIVER_DATA*) pRealtekRATSC->m_private)->pDemod;
			
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
int REALTEK_R_ATSC_ForwardI2C(DEMOD* pDemodKernel, unsigned char on_off)
{
	int ret = TUNER_CTRL_OK;

	REALTEK_R_ATSC* pRealtekRATSC;
	ATSC_DEMOD_MODULE* pDemod;
	
	pRealtekRATSC = (REALTEK_R_ATSC*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_R_ATSC_DRIVER_DATA*) pRealtekRATSC->m_private)->pDemod;

	pDemodKernel->Lock(pDemodKernel);
	if (pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_OPT_I2C_RELAY, (on_off) ? 1 : 0) != FUNCTION_SUCCESS)
		ret = TUNER_CTRL_FAIL;

	pDemodKernel->Unlock(pDemodKernel);

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
int REALTEK_R_ATSC_AutoTune(DEMOD* pDemodKernel)
{
	REALTEK_R_ATSC* pRealtekRATSC;
	pRealtekRATSC = (REALTEK_R_ATSC*)(pDemodKernel->private_data);

	return TUNER_CTRL_OK;	
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
int REALTEK_R_ATSC_DebugInfo(DEMOD* pDemodKernel, unsigned char debug_mode)
{
	int ret = TUNER_CTRL_OK;
	
	BASE_INTERFACE_MODULE* pBaseInterface;
	REALTEK_R_ATSC* pRealtekRATSC;
	ATSC_DEMOD_MODULE* pDemod;
	
	pRealtekRATSC = (REALTEK_R_ATSC*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_R_ATSC_DRIVER_DATA*) pRealtekRATSC->m_private)->pDemod;

	pDemodKernel->Lock(pDemodKernel);
	if (pDemod) {
		switch (debug_mode) {
		case 0: //ADC dump
			pBaseInterface = pDemod->pBaseInterface;
			DtvDemodDMAAllocateMemory();
			DtvDemodDMADump(pBaseInterface, pDemodKernel->m_addr, 0);
			break;
		case 1: //reg dump
			DtvDumpShareRegStatus();
			break;
		case 2: //sysinfo dump
			REALTEK_R_ATSC_DumpSysInfo();
			break;
		default:
			REALTEK_R_ATSC_INFO("[DEMOD][DEBUGINFO]unknown debug mode\n");
			break;
		}
	}

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
int REALTEK_R_ATSC_InspectSignal(DEMOD* pDemodKernel)
{
    int ret = TUNER_CTRL_OK;
	long IfAgc = -1;
	long RfAgc = -1;
	long TrOffsetPpm = -1;
	long CrOffsetHz  = -1;
	unsigned long DiAgc = 0;
	int AgcLock   = 0;
	int FrameLock = 0;
	unsigned long BerNum = 1;
	unsigned long BerDen = 1;
	unsigned long PerNum = 1;
	unsigned long PerDen = 1;
	long SnrDbNum = 1;
	long SnrDbDen = 1;

	REALTEK_R_ATSC* pRealtekRATSC;
	ATSC_DEMOD_MODULE* pDemod;
	
	pRealtekRATSC = (REALTEK_R_ATSC*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_R_ATSC_DRIVER_DATA*) pRealtekRATSC->m_private)->pDemod;

	if (DtvIsDemodClockEnable(RTK_DEMOD_MODE_ATSC) == 0)
		return TUNER_CTRL_OK;

	pDemodKernel->Lock(pDemodKernel);
	pDemod->GetRfAgc(pDemod, &RfAgc);
	pDemod->GetIfAgc(pDemod, &IfAgc);
	pDemod->GetDiAgc(pDemod, &DiAgc);
	pDemod->GetTrOffsetPpm(pDemod, &TrOffsetPpm);
	pDemod->GetCrOffsetHz(pDemod, &CrOffsetHz);
	pDemod->IsAagcLocked(pDemod, &AgcLock);
	pDemod->IsFrameLocked(pDemod, &FrameLock);
	pDemod->GetErrorRate(pDemod, 3, 600, &BerNum, &BerDen, &PerNum, &PerDen);
	pDemod->GetSnrDb(pDemod, &SnrDbNum, &SnrDbDen);
	pDemodKernel->Unlock(pDemodKernel);

	IfAgc = ((IfAgc + 8191) * 100) / 16384;
	RfAgc = ((RfAgc + 8191) * 100) / 16384;
	DiAgc = (DiAgc * 100) / 8192;

#if 0
	printk("[REALTEK_R_ATSC] lock(agc/frame)=%d/%d, agc(rf/if/di)=%ld/%ld/%lu, ofst(tr/cr)=%ld/%ld,  error_rate(ber/per)=%f/%f, snr=%f\n",
		   AgcLock, FrameLock,
		   RfAgc, IfAgc, DiAgc,
		   TrOffsetPpm, CrOffsetHz,
		   (double)BerNum / (double)BerDen,
		   (double)PerNum / (double)PerDen,
		   (double)SnrDbNum / (double) SnrDbDen);
#endif

	ret = 1;

#ifdef REALTEK_R_DUMP_SHARE_REG
	printf("dump dtv reg:\n");
	DtvDumpShareRegStatus();
#endif

	return ret;
}


/*----------------------------------------------------------------------
 * Func : Activate REALTEK_R ATSC Demod
 *
 * Desc : Run Auto Tuning for CCI
 *
 * Parm : N/A
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_R_ATSC_Activate(DEMOD* pDemodKernel, unsigned char force_rst)
{
	int i;
	unsigned char Val;
	
	REALTEK_R_ATSC* pRealtekRATSC;
	ATSC_DEMOD_MODULE* pDemod;
	
	pRealtekRATSC = (REALTEK_R_ATSC*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_R_ATSC_DRIVER_DATA*) pRealtekRATSC->m_private)->pDemod;

	pDemodKernel->Lock(pDemodKernel);
	if (DtvDemodInitialization(RTK_DEMOD_MODE_ATSC, force_rst)) {
		REALTEK_R_ATSC_INFO("Demod PLL changed, re-init ATSC Demod\n");
		// pll has been changed and demod has been reset
		// we need to re-init demod

		if (pDemod->Initialize(pDemod) != FUNCTION_SUCCESS)
			goto activate_demod_fail;

		ClearDemodReset(RTK_DEMOD_MODE_ATSC);

		for (i = 0; i < pRealtekRATSC->m_TunerOptRegCnt && pRealtekRATSC->m_pTunerOptReg; i++) {
			int Reg = pRealtekRATSC->m_pTunerOptReg[i].RegBitName;
			unsigned long Val = pRealtekRATSC->m_pTunerOptReg[i].Value;
			
			if (pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, Reg, Val) != FUNCTION_SUCCESS)
				goto activate_demod_fail;
		}

		if (pDemodKernel->SetIF(pDemodKernel, &pDemodKernel->m_if) != TUNER_CTRL_OK)
			goto activate_demod_fail;

		if (pDemodKernel->SetTSMode(pDemodKernel, &pDemodKernel->m_ts) != TUNER_CTRL_OK)
			goto activate_demod_fail;
	}

	pDemod->RegAccess.Addr16Bit.GetRegBytes(pDemod, 0xe401, &Val, 1);
	Val &= ~0x3;
	Val |= 0x2;
	pDemod->RegAccess.Addr16Bit.SetRegBytes(pDemod, 0xe401, &Val, 1);
	pDemodKernel->Unlock(pDemodKernel);

	return TUNER_CTRL_OK;

activate_demod_fail:
	pDemodKernel->Unlock(pDemodKernel);
	
	return TUNER_CTRL_FAIL;
}


int REALTEK_R_ATSC_SetTvMode(DEMOD* pDemodKernel, TV_SYSTEM_TYPE mode)
{
	int ret = TUNER_CTRL_FAIL;
	REALTEK_R_ATSC* pRealtekRATSC;

	pRealtekRATSC = (REALTEK_R_ATSC*)(pDemodKernel->private_data);
	pDemodKernel->Lock(pDemodKernel);

	REALTEK_R_ATSC_INFO("REALTEK_R_ATSC_SetTvMode(%d)\n", mode);
	
	switch (mode) 
	{
	case TV_SYS_TYPE_ATSC:
		REALTEK_R_ATSC_INFO("Set to ATSC\n");
		ret = pDemodKernel->Init(pDemodKernel);
		ret |= pDemodKernel->SetTSMode(pDemodKernel, &pDemodKernel->m_ts);
		
		if (ret != TUNER_CTRL_OK) 
		{
			REALTEK_R_ATSC_WARNING("Set REALTEK_R_ATSC to ATSC mode failed\n");
			goto set_demod_mode_failed;
		}
		break;

	default:
		REALTEK_R_ATSC_INFO("unknown TV_SYSTEM_TYPE\n");
		goto set_demod_mode_failed;
	}

	ret = TUNER_CTRL_OK;
	REALTEK_R_ATSC_INFO("Set REALTEK_R_ATSC to appointed DTV mode successed\n");
	pDemodKernel->Unlock(pDemodKernel);

	return ret;

set_demod_mode_failed:
	pDemodKernel->Unlock(pDemodKernel);
	
	return TUNER_CTRL_FAIL;
}


/*-----------------------------------------------------------------
 *     BASE_INTERFACE for REALTEK_R_ATSC API
 *----------------------------------------------------------------*/
void REALTEK_R_ATSC_Lock(DEMOD* pDemodKernel)
{
	//FUNCTION_NAME_PRINT("LOCK 0x%x\n",&pDemodKernel->m_lock);
	//mutex_lock(&pDemodKernel->m_lock);
}

void REALTEK_R_ATSC_Unlock(DEMOD* pDemodKernel)
{
	//FUNCTION_NAME_PRINT("UN_LOCK 0x%x\n",&pDemodKernel->m_lock);
	//mutex_unlock(&pDemodKernel->m_lock);
}


/*----------------------------------------------------------------------
 * Func : DumpSysInfo
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
void REALTEK_R_ATSC_DumpSysInfo()
{
	REALTEK_R_ATSC_INFO("[DEMOD][DUMPSYSINFO]tv_sys is ATSC\n");
}


void ReleaseRealtekRAtscDriver(REALTEK_R_ATSC_DRIVER_DATA *pDriver)
{
	kfree(pDriver);
}


REALTEK_R_ATSC_DRIVER_DATA* AllocRealtekRAtscDriver(
	COMM*               pComm,
	unsigned char       Addr,
	unsigned long       CrystalFreq
)
{
	REALTEK_R_ATSC_DRIVER_DATA* pDriver = (REALTEK_R_ATSC_DRIVER_DATA*) kmalloc(
											sizeof(REALTEK_R_ATSC_DRIVER_DATA) +
											sizeof(ATSC_DEMOD_MODULE)   +
											sizeof(I2C_BRIDGE_MODULE)   +
											sizeof(BASE_INTERFACE_MODULE), GFP_KERNEL);

	if (pDriver) 
	{
		BASE_INTERFACE_MODULE* pBIF;
		ATSC_DEMOD_MODULE* pDemod;
		
		memset(pDriver, 0, sizeof(REALTEK_R_ATSC_DRIVER_DATA));
		pDriver->pDemod                = (ATSC_DEMOD_MODULE*)(((unsigned char*)pDriver) + sizeof(REALTEK_R_ATSC_DRIVER_DATA));
		pDriver->pBaseInterface        = (BASE_INTERFACE_MODULE*)(((unsigned char*)pDriver->pDemod) + sizeof(ATSC_DEMOD_MODULE));
		pDriver->pI2CBridge            = (I2C_BRIDGE_MODULE*)(((unsigned char*)pDriver->pBaseInterface) + sizeof(BASE_INTERFACE_MODULE));
		pDriver->DeviceAddr            = Addr;
		pDriver->CrystalFreqHz         = CrystalFreq;

		// Init Base IF
		pBIF = pDriver->pBaseInterface;
		pBIF->I2cReadingByteNumMax      = RTK_DEMOD_BIF_RX_FIFO_DEPTH;
		pBIF->I2cWritingByteNumMax      = RTK_DEMOD_BIF_TX_FIFO_DEPTH;
		pBIF->I2cRead                   = __realtek_rbus_i2c_read;
		pBIF->I2cWrite                  = __realtek_rbus_i2c_write;
		pBIF->WaitMs                    = __realtek_wait_ms;
		pBIF->SetUserDefinedDataPointer = base_interface_SetUserDefinedDataPointer;
		pBIF->GetUserDefinedDataPointer = base_interface_GetUserDefinedDataPointer;
		pBIF->SetUserDefinedDataPointer(pBIF, (void*)pComm);
		pBIF->useI2C = 0;

		// Init Demod Driver
		BuildRealtekRAtscModule(&pDemod,
							   pDriver->pDemod,
							   pDriver->pBaseInterface,
							   pDriver->pI2CBridge,
							   Addr,
							   CrystalFreq);
	}
	
	return pDriver;
}


