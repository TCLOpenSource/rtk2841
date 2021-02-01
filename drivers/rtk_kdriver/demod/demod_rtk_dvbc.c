/***************************************************************************************************
  File        : demod_realtek_i.cpp
  Description : REALTEK_I_ DVB-T demod
  Author      : Kevin Wang
****************************************************************************************************
    Update List :
----------------------------------------------------------------------------------------------------
    20120207    | create phase
***************************************************************************************************/
#include <linux/kernel.h>
#include <linux/slab.h>
//#include <OSAL.h>
#include "foundation.h"
#include "demod_rtk_dvbc.h"
#include "dvbc_demod_rtk.h"
#include "demod_rtk_dvbc_priv.h"
#include "dvbc_registers.h"
#include "dvbc_tvcore_registers.h"
#include <mach/io.h>
#include "rbus/demod_sd_reg.h"

//#define ENABLE_LDR_LOADER
#define SUPPORT_WINTOOL

#define COMMON_BASE_ADDRESS     0xc27ff100
#define VR_BASE_ADDRESS         0xc27ff200
#define DVBC_SQI_ADDRESS        0xc27ff1f0

#define CONSTELL_EQ_ADDRESS     0xc27ff300
#define CONSTELL_HD_ADDRESS     0xc27ff400

#define DEBUG_MODE_EN_ADDRESS   0xc27ff500
#define DEBUG_MODE_SEL_ADDRESS  0xc27ff504
#define HANDSHAKE_ADDRESS       0xc27ff508
#define PRI_VR_INDEX_ADDRESS    0xc27ff50c
#define SEC_VR_INDEX_ADDRESS    0xc27ff510
#define VR_VALUE_ADDRESS        0xc27ff514

#define DVBC_META_CLOCK 270000000
#define DVBC_SCAN_THREAD_ENABLE /*use in webOS*/

static unsigned char gResetDemodCnt = 0;
/*----------------------------------------------------------------------
 * Func : REALTEK_I_DVBC
 *
 * Desc : constructor
 *
 * Parm : device_addr : device address
 *        output_mode : RTK_DEMOD_OUT_IF_SERIAL / RTK_DEMOD_OUT_IF_PARALLEL
 *        output_freq : RTK_DEMOD_OUT_FREQ_6M / RTK_DEMOD_OUT_FREQ_10M
 *        pComm       : hadle of COMM
 *
 * Retn : handle of demod
 *----------------------------------------------------------------------*/
void REALTEK_I_DVBC_Constructors(DEMOD* pDemodKernel, unsigned char addr, unsigned char output_mode, unsigned char output_freq, COMM*	pComm)
{
	REALTEK_I_DVBC* pRealtekIDVBC;
	//FUNCTION_NAME_PRINT("REALTEK_I_DVBC::REALTEK_I_DVBC\n");

	pDemodKernel->private_data = kmalloc(sizeof(REALTEK_I_DVBC), GFP_KERNEL);
	pRealtekIDVBC = (REALTEK_I_DVBC*)(pDemodKernel->private_data);

	Demod_Constructors(pDemodKernel);

	pDemodKernel->m_id                 = DTV_DEMOD_REALTEK_I_DVBT2;
	pDemodKernel->m_addr               = addr;
	pDemodKernel->m_pTuner             = NULL;
	pDemodKernel->m_pComm              = pComm;
	pDemodKernel->m_ScanRange          = SCAN_RANGE_3_6;
	pDemodKernel->m_Capability         = TV_SYS_TYPE_DVBC;
	pDemodKernel->m_update_interval_ms = 300;
	pDemodKernel->m_if.freq            = 5000000;
	pDemodKernel->m_if.inversion       = 0;
	pDemodKernel->m_if.agc_pola        = 0;
	pDemodKernel->m_clock              = CRYSTAL_FREQ_27000000HZ;
	pRealtekIDVBC->m_output_freq        = output_freq;

	pRealtekIDVBC->m_private            = (void*) AllocRealtekIDvbcDriver(
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
	pDemodKernel->m_ScanMode           = CH_UNKNOW;
	pRealtekIDVBC->m_TunerOptRegCnt     = 0;
	pRealtekIDVBC->m_auto_tune_en     = 0;
	pRealtekIDVBC->m_pTunerOptReg       = NULL;
	pRealtekIDVBC->m_acquire_stime = 0;

	pDemodKernel->m_pComm->SetTargetName(pDemodKernel->m_pComm, pDemodKernel->m_addr, "REALTEK_I_DVBC");

	pDemodKernel->Init = REALTEK_I_DVBC_Init;
	pDemodKernel->Reset = Demod_Reset;
	pDemodKernel->AcquireSignal = REALTEK_I_DVBC_AcquireSignal;
	pDemodKernel->ScanSignal = REALTEK_I_DVBC_ScanSignal;
	pDemodKernel->SetIF = REALTEK_I_DVBC_SetIF;
	pDemodKernel->SetTSMode = REALTEK_I_DVBC_SetTSMode;
	pDemodKernel->SetTVSysEx = REALTEK_I_DVBC_SetTVSysEx;
	pDemodKernel->SetMode = REALTEK_I_DVBC_SetMode;
	pDemodKernel->SetTVSys = REALTEK_I_DVBC_SetTVSys;
	pDemodKernel->GetLockStatus = REALTEK_I_DVBC_GetLockStatus;
	pDemodKernel->GetSegmentNum = Demod_GetSegmentNum;
	pDemodKernel->GetSignalInfo = REALTEK_I_DVBC_GetSignalInfo;
	pDemodKernel->GetSignalQuality = REALTEK_I_DVBC_GetSignalQuality;
	pDemodKernel->ChangeT2PLP = Demod_ChangeT2PLP;
	pDemodKernel->GetT2PLPInfo = Demod_GetT2PLPInfo;
	pDemodKernel->GetT2L1PreInfo = Demod_GetT2L1PreInfo;
	pDemodKernel->GetT2L1PostInfo = Demod_GetT2L1PostInfo;
	pDemodKernel->GetDemodStatus = Demod_GetDemodStatus;
	pDemodKernel->GetCarrierOffset = REALTEK_I_DVBC_GetCarrierOffset;
	pDemodKernel->ForwardI2C = REALTEK_I_DVBC_ForwardI2C;
	pDemodKernel->AutoTune = REALTEK_I_DVBC_AutoTune;
	pDemodKernel->GetCapability = Demod_GetCapability;
	pDemodKernel->Suspend = Demod_Suspend;
	pDemodKernel->Resume = Demod_Resume;
	pDemodKernel->SetTvMode = REALTEK_I_DVBC_SetTvMode;
	pDemodKernel->InspectSignal = REALTEK_I_DVBC_InspectSignal;	  // Add monitor function that used to monitor demod status
	pDemodKernel->AttachTuner = Demod_AttachTuner;
	pDemodKernel->GetTSParam = Demod_GetTSParam;
//	pDemodKernel->Lock = Demod_Lock;
//	pDemodKernel->Unlock = Demod_Unlock;
	pDemodKernel->Lock = REALTEK_I_DVBC_Lock;
	pDemodKernel->Unlock = REALTEK_I_DVBC_Unlock;

	//pDemodKernel->Activate = REALTEK_I_DVBC_Activate;
	pDemodKernel->Destory = REALTEK_I_DVBC_Destructors;

#ifdef SUPPORT_WINTOOL
	pRealtekIDVBC->m_debug_tool_en = 0;
	rtd_outl(DEBUG_MODE_EN_ADDRESS, 0);
	rtd_outl(DEBUG_MODE_SEL_ADDRESS, 0);
#endif
}

/*----------------------------------------------------------------------
 * Func : ~REALTEK_I_DVBC
 *
 * Desc : Destructor of REALTEK_I_DVBC
 *
 * Parm : pDemod : handle of Demod
 *
 * Retn : N/A
 *----------------------------------------------------------------------*/
void REALTEK_I_DVBC_Destructors(DEMOD* pDemodKernel)
{
	REALTEK_I_DVBC* pRealtekIDVBC;
	//FUNCTION_NAME_PRINT("REALTEK_I_DVBC::~REALTEK_I_DVBC\n");
	pRealtekIDVBC = (REALTEK_I_DVBC*)(pDemodKernel->private_data);

	if (pRealtekIDVBC->m_private != NULL)
		ReleaseRealtekIDvbcDriver((REALTEK_I_DVBC_DRIVER_DATA*)pRealtekIDVBC->m_private);

	kfree(pRealtekIDVBC);
	//pDemodKernel->Destory(pDemodKernel);
	REALTEK_I_DVBC_INFO("REALTEK_R_DVBC_Destructors Complete\n");
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
int REALTEK_I_DVBC_Init(DEMOD* pDemodKernel)
{
	unsigned char     PGAEnable = 0;
	IFADCGAIN      PGAGain;
	unsigned int      IsRpuLowReady, IsRpuHighReady;
	unsigned int      BuildId, DemodType;
	unsigned int      InitRetry = 0;
	int               ret = TUNER_CTRL_OK;

	REALTEK_I_DVBC* pRealtekIDVBC;
	REG_VALUE_ENTRY*  OptRegTable;
	DVBC_DEMOD_MODULE* pDemod;
	pRealtekIDVBC = (REALTEK_I_DVBC*)(pDemodKernel->private_data);


	if (pDemodKernel->m_pComm == NULL || pRealtekIDVBC->m_private == NULL)
		return TUNER_CTRL_FAIL;

	pDemod = ((REALTEK_I_DVBC_DRIVER_DATA*) pRealtekIDVBC->m_private)->pDemod;

	//FUNCTION_NAME_PRINT("REALTEK_I_DVBC::Init\n");

	//////////////////////////////////////////////////
	//DVBC_DEMOD_MODULE* pDemod = ((REALTEK_I_DVBC_DRIVER_DATA*) pRealtekIDVBC->m_private)->pDemod;

	//////////////////////////////////////////////////

	pDemodKernel->Lock(pDemodKernel);

	pRealtekIDVBC->m_auto_tune_en = 0;

demod_re_init:
	//DtvDemodClockEnable(1);
	DtvDemodInitialization(RTK_DEMOD_MODE_DVBC, 1);

	ret = DECODE_RET(pDemod->CheckRpuReady(pDemod, &IsRpuLowReady));//Check for Low level Header
	ret |= DECODE_RET(pDemod->CheckRpuReady(pDemod, &IsRpuHighReady));//Check for High level Msg

	if (IsRpuLowReady != 1 || IsRpuHighReady != 1) {
		REALTEK_I_DVBC_INFO("Waiting for Demod Init Done; Demod Has No Reply !!!!\n");
		REALTEK_I_DVBC_INFO("Waiting for Demod Init Done; Demod Has No Reply !!!!\n");
		REALTEK_I_DVBC_INFO("Waiting for Demod Init Done; Demod Has No Reply !!!!\n");
		REALTEK_I_DVBC_INFO("Waiting for Demod Init Done; Demod Has No Reply !!!!\n");
		REALTEK_I_DVBC_INFO("RpuLowReady = %d, RpuHighReady = %d\n", IsRpuLowReady, IsRpuHighReady);

		if (!InitRetry) {
			InitRetry = 1;
			REALTEK_I_DVBC_INFO("\033[1;32;32m" "RPU Auto Re-Init in Demod Init\n" "\033[m");
			goto demod_re_init;
		} else {
			goto init_fail;
		}
	}

	//Change To Buffer Mode
	REALTEK_I_DVBC_INFO("Change To Buffer Mode........\n");
	ret |= DECODE_RET(pDemod->SwitchToBuffer(pDemod));
	if (ret != TUNER_CTRL_OK) {
		REALTEK_I_DVBC_INFO("Change To Buffer Mode Fail !!!!!\n");
		goto init_fail;
	}

	// ActivateCore DVBC
	ret |= DECODE_RET(pDemod->ActivateCore(pDemod));
	if (ret != TUNER_CTRL_OK) {
		REALTEK_I_DVBC_INFO("ActivateCore Fail !!!!!\n");
		goto init_fail;
	}

	// check tuner information	
	PGAEnable = 2;
	PGAGain = PGAFIX_2DB;
	pRealtekIDVBC->m_dvbc_AgcScale = 89;
	pRealtekIDVBC->m_dvbc_ext_gain_dis = RTK_DEMOD_XML_EXT_GAIN_EN;

	if (pDemodKernel->m_pTuner) {
		TUNER_PARAM Param;

		if (pDemodKernel->m_pTuner->GetParam(pDemodKernel->m_pTuner, TV_SYS_DVBC_6M, &Param) == TUNER_CTRL_OK) {
			switch (Param.id) {
			case TV_TUNER_NXP_TDA18275A:
				REALTEK_I_DVBC_INFO("Tuner id %d, TV_TUNER_NXP_TDA1827X\n", Param.id);
				pRealtekIDVBC->m_dvbc_AgcScale = 51;//51/128=0.4
				pRealtekIDVBC->m_dvbc_ext_gain_dis = RTK_DEMOD_XML_EXT_GAIN_EN;
				break;
			case TV_TUNER_SILICONLABS_SI2151:
			case TV_TUNER_SILICONLABS_SI2178B:
			case TV_TUNER_NO_TUNER:
				REALTEK_I_DVBC_INFO("Tuner id %d, TV_TUNER_SILICONLABS_SI215x\n", Param.id);
				pRealtekIDVBC->m_dvbc_AgcScale = 89;
				pRealtekIDVBC->m_dvbc_ext_gain_dis = RTK_DEMOD_XML_EXT_GAIN_EN;
				break;
			case TV_TUNER_MAXLINEAR_MXL661:
				REALTEK_I_DVBC_INFO("Tuner id %d, TV_TUNER_MAXLINEAR_MXL6x1\n", Param.id);
				pRealtekIDVBC->m_dvbc_AgcScale = 89; //64/128=0.5
				pRealtekIDVBC->m_dvbc_ext_gain_dis = RTK_DEMOD_XML_EXT_GAIN_EN;
				break;
			case TV_TUNER_RAFAEL_R840:
				REALTEK_I_DVBC_INFO("Tuner id %d, TV_TUNER_RAFAEL_R840\n", Param.id);
				pRealtekIDVBC->m_dvbc_AgcScale =  51;//51/128=0.4
				pRealtekIDVBC->m_dvbc_ext_gain_dis = RTK_DEMOD_XML_EXT_GAIN_EN;
				break;
			default:
				REALTEK_I_DVBC_WARNING("unkonw tuner id %d, using default setting\n", Param.id);
				pRealtekIDVBC->m_dvbc_AgcScale = 128;
				pRealtekIDVBC->m_dvbc_ext_gain_dis = RTK_DEMOD_XML_EXT_GAIN_EN;
				break;
			}

			pDemodKernel->m_if.freq      = Param.if_freq;
			pDemodKernel->m_if.inversion = Param.if_inversion;
			pDemodKernel->m_if.agc_pola  = Param.if_agc_pola;
		}
	}

	DtvPGAControl(PGAEnable, PGAGain);

	// Initial Driver

	ClearDemodReset(RTK_DEMOD_MODE_DVBC);

	if (pDemodKernel->SetTSMode(pDemodKernel, &pDemodKernel->m_ts) != TUNER_CTRL_OK)
		goto init_fail;

	ret |= DECODE_RET(pDemod->GetDemodInfo(pDemod, &DemodType));
	ret |= DECODE_RET(pDemod->GetBuildId(pDemod, &BuildId));
	REALTEK_I_DVBC_INFO("DemodType = %x, BuildId = %x\n", DemodType, BuildId);

	//10.2.0 Support Run Time Change XML Parmeters
	ret |= DECODE_RET(pDemod->SetXmlTunerGainCtrl(pDemod, pRealtekIDVBC->m_dvbc_AgcScale | (RTK_DEMOD_XML_EXT_GAIN1 << 16) | (pDemodKernel->m_if.agc_pola << 18)));
	ret |= DECODE_RET(pDemod->SetXmlFlags(pDemod, RTK_DEMOD_XML_REAL_IF | (pDemodKernel->m_if.inversion << 1) | (RTK_DEMOD_XML_UNSIGNED << 2) | (pRealtekIDVBC->m_dvbc_ext_gain_dis << 3)));
	ret |= DECODE_RET(pDemod->SetXmlIfFreq(pDemod, pDemodKernel->m_if.freq));
	ret |= DECODE_RET(pDemod->SetXmlTunerCfgOverride(pDemod, 0x00000001));

	ret |= DECODE_RET(pDemod->SetXmlIfClk(pDemod, 30000000));
	ret |= DECODE_RET(pDemod->SetXmlLdpcClk(pDemod, DVBC_META_CLOCK));
	ret |= DECODE_RET(pDemod->SetXmlUccClk(pDemod, DVBC_META_CLOCK));
	ret |= DECODE_RET(pDemod->SetXmlMcuClk(pDemod, DVBC_META_CLOCK));
	ret |= DECODE_RET(pDemod->SetXmlPlftCfgOverride(pDemod, 0x00000001));

	// Set Symbol Rate Search Range
	ret |= DECODE_RET(pDemod->SetSymbolRateSearchMode(pDemod, 0x2));
	ret |= DECODE_RET(pDemod->SetMinSymbolRate(pDemod, 3600000));
	ret |= DECODE_RET(pDemod->SetMaxSymbolRate(pDemod, 7000000));

	pDemodKernel->Unlock(pDemodKernel);
	REALTEK_I_DVBC_INFO("REALTEK_I_DVBC Init Complete\n");
	return TUNER_CTRL_OK;

init_fail:
	REALTEK_I_DVBC_WARNING("REALTEK_I_DVBC Init Failed\n");
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
int REALTEK_I_DVBC_SetTVSys(DEMOD* pDemodKernel, TV_SYSTEM sys)
{
        int ret;
	REALTEK_I_DVBC* pRealtekIDVBC;
	pRealtekIDVBC = (REALTEK_I_DVBC*)(pDemodKernel->private_data);

	//FUNCTION_NAME_PRINT("REALTEK_I_DVBC::SetTVSys\n");
	TV_SIG_INFO   *pSigInfo;
        pSigInfo = kmalloc(sizeof(TV_SIG_INFO), GFP_KERNEL); 

	pSigInfo->mod = TV_MODULATION_DVBC_QAM;
	pSigInfo->dvbc_qam.constellation = QAM_CONST_64;
	pSigInfo->dvbc_qam.symbol_rate = 6875000;

	ret = pDemodKernel->SetTVSysEx(pDemodKernel, sys, pSigInfo);
	kfree(pSigInfo);
	
	return ret;
}



/*----------------------------------------------------------------------
 * Func : SetTVSys
 *
 * Desc : Set TV System
 *
 * Parm : sys : TV System
 *        pSigInfo : signal information
 *
 * Retn : TUNER_CTRL_OK / TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBC_SetTVSysEx(DEMOD* pDemodKernel, TV_SYSTEM sys, const TV_SIG_INFO*  pSigInfo)
{
	int ret = TUNER_CTRL_OK;
	TUNER_PARAM Param;
	CH_MODE DvbcScanMode = CH_NORMAL_MODE;
	gResetDemodCnt = 0;

	REALTEK_I_DVBC* pRealtekIDVBC;
	DVBC_DEMOD_MODULE* pDemod;
	pRealtekIDVBC = (REALTEK_I_DVBC*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_DVBC_DRIVER_DATA*) pRealtekIDVBC->m_private)->pDemod;
	//FUNCTION_NAME_PRINT("REALTEK_I_DVBC::SetTVSysEx\n");

	if (!IsDvbcSys(sys)) {
		REALTEK_I_DVBC_WARNING("Set TV system failed, unsupported TV system\n");
		return TUNER_CTRL_FAIL;
	}

	pRealtekIDVBC->m_auto_tune_en = 0;
	pDemodKernel->Lock(pDemodKernel);

	//TUNER_PARAM Param;
	if (pDemodKernel->m_pTuner->GetParam(pDemodKernel->m_pTuner, pDemodKernel->m_tv_sys, &Param) == TUNER_CTRL_OK) {
		if ((pDemodKernel->m_if.freq != Param.if_freq) || (pDemodKernel->m_if.inversion != Param.if_inversion) || (pDemodKernel->m_if.agc_pola  != Param.if_agc_pola)) {
			pDemodKernel->m_if.freq = Param.if_freq;
			pDemodKernel->m_if.inversion = Param.if_inversion;
			pDemodKernel->m_if.agc_pola = Param.if_agc_pola;
			ret |= pDemodKernel->SetIF(pDemodKernel, &pDemodKernel->m_if);
			if(ret != TUNER_CTRL_OK){
				REALTEK_I_DVBC_INFO("[REALTEK_I_DVBC_SetTVSysEx]pDemodKernel->SetIF != TUNER_CTRL_OK\n");
			}
		}
	}

	if (!pSigInfo) {
		REALTEK_I_DVBC_WARNING("Siginfo doesn't specified, SetTVSysEx Fail\n");
		goto SetTVSysEx_fail;
	}

	if (pSigInfo != NULL)
		DvbcScanMode = pSigInfo->dvbc_qam.scan_mode ? CH_SCAN_MODE : CH_NORMAL_MODE;
	else
		DvbcScanMode = CH_NORMAL_MODE;

	pDemodKernel->m_tv_sys = sys;

	ret |= DECODE_RET(pDemod->DemodCtrlStop(pDemod));
	if(ret != TUNER_CTRL_OK){
		REALTEK_I_DVBC_INFO("[REALTEK_I_DVBC_SetTVSysEx] DemodCtrlStop != TUNER_CTRL_OK\n");
	}
    ret |= DECODE_RET(pDemod->SetFailErrorRate(pDemod, 0x64)); 
	if(ret != TUNER_CTRL_OK){
		REALTEK_I_DVBC_INFO("[REALTEK_I_DVBC_SetTVSysEx] SetFailErrorRate != TUNER_CTRL_OK\n");
	}
	ret |= DECODE_RET(pDemod->SetTunerBandwidth(pDemod, 8000000));
	if(ret != TUNER_CTRL_OK){
		REALTEK_I_DVBC_INFO("[REALTEK_I_DVBC_SetTVSysEx] SetTunerBandwidth != TUNER_CTRL_OK\n");
	}
	ret |= DECODE_RET(pDemod->SetTunerFreq(pDemod, 666000000));
	if(ret != TUNER_CTRL_OK){
		REALTEK_I_DVBC_INFO("[REALTEK_I_DVBC_SetTVSysEx] SetTunerFreq != TUNER_CTRL_OK\n");
	}
	ret |= DECODE_RET(pDemod->DemodCtrlDetect(pDemod));
	if(ret != TUNER_CTRL_OK){
		REALTEK_I_DVBC_INFO("[REALTEK_I_DVBC_SetTVSysEx] DemodCtrlDetect != TUNER_CTRL_OK\n");
	}

	pDemodKernel->m_ScanMode = DvbcScanMode;
	pRealtekIDVBC->m_acquire_stime = tv_osal_time();

	REALTEK_I_DVBC_INFO("REALTEK_I_DVBC SetTVSysEx Complete\n");
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
int REALTEK_I_DVBC_SetIF(DEMOD* pDemodKernel, IF_PARAM* pParam)
{
	int ret = TUNER_CTRL_OK;
	REALTEK_I_DVBC* pRealtekIDVBC;
	DVBC_DEMOD_MODULE* pDemod;
	pRealtekIDVBC = (REALTEK_I_DVBC*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_DVBC_DRIVER_DATA*) pRealtekIDVBC->m_private)->pDemod;

	//FUNCTION_NAME_PRINT("REALTEK_I_DVBC::SetIF\n");

	pDemodKernel->Lock(pDemodKernel);

	REALTEK_I_DVBC_DBG("SetIF, IF_freq=%lu, spectrumn inv=%d, agc_pola=%d\n",
					 pParam->freq, pParam->inversion, pParam->agc_pola);

	ret |= DECODE_RET(pDemod->SetXmlTunerGainCtrl(pDemod, pRealtekIDVBC->m_dvbc_AgcScale | (RTK_DEMOD_XML_EXT_GAIN1 << 16) | (pParam->agc_pola << 18)));
	ret |= DECODE_RET(pDemod->SetXmlFlags(pDemod, RTK_DEMOD_XML_REAL_IF | (pParam->inversion << 1) | (RTK_DEMOD_XML_UNSIGNED << 2) | (pRealtekIDVBC->m_dvbc_ext_gain_dis << 3)));
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
int REALTEK_I_DVBC_SetMode(DEMOD* pDemodKernel, TV_OP_MODE mode)
{
	REALTEK_I_DVBC* pRealtekIDVBC;
	pRealtekIDVBC = (REALTEK_I_DVBC*)(pDemodKernel->private_data);
	//FUNCTION_NAME_PRINT("REALTEK_I_DVBC::SetMode\n");

	switch (mode) {
	case TV_OP_MODE_NORMAL:
	case TV_OP_MODE_SCANING:
		break;
	case TV_OP_MODE_STANDBY:
		break;
	case TV_OP_MODE_ATV_NORMAL:
	case TV_OP_MODE_TP_ONLY:
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
int REALTEK_I_DVBC_SetTSMode(DEMOD* pDemodKernel, TS_PARAM* pParam)
{
	int ret = TUNER_CTRL_OK;
	unsigned char TsOutEn, TsSerial, ClkPhase;

	REALTEK_I_DVBC* pRealtekIDVBC;
	DVBC_DEMOD_MODULE* pDemod;
	pRealtekIDVBC = (REALTEK_I_DVBC*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_DVBC_DRIVER_DATA*) pRealtekIDVBC->m_private)->pDemod;

	TsOutEn = (pParam->tsOutEn == 1) ? RTK_DEMOD_TS_EN : RTK_DEMOD_TS_DIS;
	TsSerial = (pParam->mode == SERIAL_MODE) ? RTK_DEMOD_TS_SERIAL : RTK_DEMOD_TS_PARALLEL;
	ClkPhase = (pParam->clk_pol == RISING_EDGE) ? RTK_DEMOD_TS_CLK_PHASE_NOR : RTK_DEMOD_TS_CLK_PHASE_INV;

	pDemodKernel->Lock(pDemodKernel);

	ret |= DECODE_RET(pDemod->SetTsClkRateMargin(pDemod, 0x00011170));
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
int REALTEK_I_DVBC_GetLockStatus(DEMOD* pDemodKernel, unsigned char* pLock)
{
	unsigned char	lock;
	unsigned int	DemodStatus;
	int ret = TUNER_CTRL_OK;

	REALTEK_I_DVBC* pRealtekIDVBC;
	DVBC_DEMOD_MODULE* pDemod;
	pRealtekIDVBC = (REALTEK_I_DVBC*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_DVBC_DRIVER_DATA*)pRealtekIDVBC->m_private)->pDemod;

	//FUNCTION_NAME_PRINT("REALTEK_I_DVBC::GetLockStatus\n");
	if (!DtvIsDemodClockEnable(RTK_DEMOD_MODE_DVBC))
		return TUNER_CTRL_FAIL;

	pDemodKernel->Lock(pDemodKernel);

#ifdef SUPPORT_WINTOOL
	if(!pRealtekIDVBC->m_debug_tool_en)
	{
#endif




	ret |= DECODE_RET(pDemod->GetDemodStatus(pDemod, &DemodStatus));
	lock = (DemodStatus == 5) ? YES : NO;

	if (ret == TUNER_CTRL_OK)
		*pLock = DECODE_LOCK(lock);
	else
		*pLock = 0;


    

#ifdef SUPPORT_WINTOOL
	}
	else
	{
		lock = YES;
		*pLock = DECODE_LOCK(lock);
	}
#endif

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
int REALTEK_I_DVBC_GetSignalInfo(DEMOD* pDemodKernel, TV_SIG_INFO* pInfo)
{
	unsigned int qam_mode, spec_mode;
	unsigned int pSymbolRateHz = 0;
	int pAlphaMode = 0;

	REALTEK_I_DVBC* pRealtekIDVBC;
	DVBC_DEMOD_MODULE* pDemod;
	pRealtekIDVBC = (REALTEK_I_DVBC*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_DVBC_DRIVER_DATA*)pRealtekIDVBC->m_private)->pDemod;

	//FUNCTION_NAME_PRINT("REALTEK_I_DVBC::GetSignalInfo\n");

	if (!DtvIsDemodClockEnable(RTK_DEMOD_MODE_DVBC))
		return TUNER_CTRL_FAIL;

#ifdef SUPPORT_WINTOOL
	if(!pRealtekIDVBC->m_debug_tool_en)
	{
#endif




	pDemodKernel->Lock(pDemodKernel);

	pDemod->DemodCtrlUpdateCounters(pDemod);
	pDemod->GetMonitorQamSize(pDemod, &qam_mode);
	pDemod->GetMonitorSymbolRate(pDemod, &pSymbolRateHz);
	pDemod->GetMonitorSpectrumInversion(pDemod, &spec_mode);
	pInfo->dvbc_qam.symbol_rate = pSymbolRateHz;

	pDemodKernel->Unlock(pDemodKernel);

	pInfo->mod = TV_MODULATION_DVBC_QAM;

	switch (qam_mode) {
	case DVBC_DEMOD_QAM_16:
		pInfo->dvbc_qam.constellation  = QAM_CONST_16;
		break;
	case DVBC_DEMOD_QAM_32:
		pInfo->dvbc_qam.constellation  = QAM_CONST_32;
		break;
	case DVBC_DEMOD_QAM_64:
		pInfo->dvbc_qam.constellation  = QAM_CONST_64;
		break;
	case DVBC_DEMOD_QAM_128:
		pInfo->dvbc_qam.constellation  = QAM_CONST_128;
		break;
	case DVBC_DEMOD_QAM_256:
		pInfo->dvbc_qam.constellation  = QAM_CONST_256;
		break;
	}

	if (spec_mode)
		pInfo->dvbc_qam.spectrum_inverse = QAM_SPEC_INVERSE;
	else
		pInfo->dvbc_qam.spectrum_inverse = QAM_SPEC_NORMAL;

#ifdef SUPPORT_WINTOOL
	}
#endif

	REALTEK_I_DVBC_INFO("GetSignalInfo QAM_MODE = %d, SPEC_INV = %d, symbol_rate = %d\n", pInfo->dvbc_qam.constellation, pInfo->dvbc_qam.spectrum_inverse, pInfo->dvbc_qam.symbol_rate);
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
int REALTEK_I_DVBC_GetSignalQuality(DEMOD* pDemodKernel, ENUM_TV_QUAL id,	TV_SIG_QUAL* pQuality)
{
	int ret = TUNER_CTRL_OK;
	unsigned char lock;
	unsigned char sqi = 0;
	unsigned char ssi = 0;
	unsigned int Eqout = 0, PakN = 0, BadPakN = 0, ErrBit = 0, Agc = 0;
	unsigned int DemodStatus;
	unsigned int SNR = 0;

	REALTEK_I_DVBC* pRealtekIDVBC;
	DVBC_DEMOD_MODULE* pDemod;
	pRealtekIDVBC = (REALTEK_I_DVBC*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_DVBC_DRIVER_DATA*) pRealtekIDVBC->m_private)->pDemod;

	//FUNCTION_NAME_PRINT("REALTEK_I_DVBC::GetSignalQuality\n");
	if (!DtvIsDemodClockEnable(RTK_DEMOD_MODE_DVBC))
		return TUNER_CTRL_FAIL;

	pDemodKernel->Lock(pDemodKernel);

#ifdef SUPPORT_WINTOOL
	if(!pRealtekIDVBC->m_debug_tool_en)
	{
#endif




	ret |= (pDemod->GetDemodStatus(pDemod, &DemodStatus));
	lock = (DemodStatus == 5) ? 1 : 0;

	ret = pDemod->DemodCtrlUpdateCounters(pDemod);

	switch (id) {
	case TV_QUAL_NOSIG:
		pQuality->nosig = !(lock);
		break;

	case TV_QUAL_INNERLOCK:
		pQuality->nosig = lock;
		//REALTEK_I_DVBC_INFO("InnerLock=%d\n",lock);
		break;

	case TV_QUAL_SNR:
		ret = pDemod->GetEqOutputSnr(pDemod, &Eqout);
		SNR = (Eqout * 10000) / 256;
		pQuality->snr = SNR;
		//REALTEK_I_DVBC_INFO("SNR=%f\n",SNR);
		break;

	case TV_QUAL_BER:
	case TV_QUAL_PER:
	case TV_QUAL_BEC:
	case TV_QUAL_PEC:
	case TV_QUAL_UCBLOCKS:
		ret |= pDemod->GetTsPacketNumber(pDemod, &PakN);
		ret |= pDemod->GetBadPacketNumber(pDemod, &BadPakN);
		ret |= pDemod->GetBitErrorNumber(pDemod, &ErrBit);
		//REALTEK_I_DVBC_INFO("[GetSignalQuality] PakN=%d\n",PakN);
		if (PakN > 0) {
			if (id == TV_QUAL_BER) {
				pQuality->ber = ((ErrBit * 10000)  / (PakN * 204 * 8));
				//REALTEK_I_DVBC_INFO("[GetSignalQuality] ber=%f\n",pQuality->ber);
			}
			if (id == TV_QUAL_PER) {
				pQuality->per = ((BadPakN * 10000) / PakN);
				//REALTEK_I_DVBC_INFO("[GetSignalQuality] per=%f\n",pQuality->per);
			}
			if (id == TV_QUAL_UCBLOCKS) {
				pQuality->ucblocks = BadPakN;
				//REALTEK_I_DVBC_INFO("[GetSignalQuality] ucblocks=%d\n",pQuality->ucblocks);
			}
			if (id == TV_QUAL_BEC) {
				pQuality->layer_ber.ber_num = ErrBit;
				pQuality->layer_ber.ber_den = (PakN * 204 * 8);
				//REALTEK_I_DVBC_INFO("[GetSignalQuality] ber_num=%d; ber_den=%d\n", pQuality->layer_ber.ber_num, pQuality->layer_ber.ber_den);
			}
			if (id == TV_QUAL_PEC) {
				pQuality->layer_per.per_num = BadPakN;
				pQuality->layer_per.per_den = PakN;
				//REALTEK_I_DVBC_INFO("[GetSignalQuality] per_num=%d; per_den=%d\n", pQuality->layer_per.per_num, pQuality->layer_per.per_den);
			}
		} else {
			if (id == TV_QUAL_BER) pQuality->ber = 1;
			if (id == TV_QUAL_PER) pQuality->per = 1;
			if (id == TV_QUAL_UCBLOCKS)  pQuality->ucblocks = 0xffffffff;
			if (id == TV_QUAL_BEC) {
				pQuality->layer_ber.ber_num = 0xffffffff;
				pQuality->layer_ber.ber_den = 0xffffffff;
			}
			if (id == TV_QUAL_PEC) {
				pQuality->layer_per.per_num = 0xffffffff;
				pQuality->layer_per.per_den = 0xffffffff;
			}
		}
		break;

	case TV_QUAL_SIGNAL_STRENGTH:
		ret |= DECODE_RET(pDemod->GetSignalSSI(pDemod, (int) pQuality->rflevel, &ssi));
		pQuality->strength = ssi;
		//REALTEK_I_DVBC_INFO("SSI=%d\n", pQuality->strength);
		break;

	case TV_QUAL_SIGNAL_QUALITY:
		ret |= DECODE_RET(pDemod->GetSignalSQI(pDemod, &sqi));
		pQuality->quality = sqi;
		//REALTEK_I_DVBC_INFO("SQI=%d\n", pQuality->quality);
		break;

	case TV_QUAL_AGC:
		Agc = (rtd_inl(DEMOD_SD_SIGMA_DELTA_INPUT_reg) >> 12) & 0x7ff;
		Agc =  Agc * 100 / 0x7ff;
		pQuality->agc = Agc;
		//REALTEK_I_DVBC_INFO("AGC=%d\n", pQuality->agc);
		break;

	case TV_QUAL_DEMODFWVERSION:
		pQuality->DemodFwVersion = 0x000001;
		break;

	case TV_QUAL_CUSTOMER_LG:
		ret |= pDemod->GetTsPacketNumber(pDemod, &PakN);
		ret |= pDemod->GetBadPacketNumber(pDemod, &BadPakN);
		ret |= pDemod->GetBitErrorNumber(pDemod, &ErrBit);
		ret |= pDemod->GetEqOutputSnr(pDemod, &Eqout);
		ret |= DECODE_RET(pDemod->GetSignalSSI(pDemod, (int) pQuality->rflevel, &ssi));
		ret |= DECODE_RET(pDemod->GetSignalSQI(pDemod, &sqi)); //include reset function
		Agc = (rtd_inl(DEMOD_SD_SIGMA_DELTA_INPUT_reg) >> 12) & 0x7ff;
		Agc =  Agc * 100 / 0x7ff;

		SNR = (Eqout * 10000) / 256;

		pQuality->strength = ssi;
		pQuality->quality = sqi;
		pQuality->agc = Agc;
		pQuality->snr = SNR;
		if (PakN > 0) {
			pQuality->layer_ber.ber_num = ErrBit;
			pQuality->layer_ber.ber_den = (PakN * 204 * 8);
			pQuality->layer_per.per_num = BadPakN;
			pQuality->layer_per.per_den = PakN;
		} else {
			pQuality->layer_ber.ber_num = 0xffffffff;
			pQuality->layer_ber.ber_den = 0xffffffff;
			pQuality->layer_per.per_num = 0xffffffff;
			pQuality->layer_per.per_den = 0xffffffff;
		}

		break;

	default:
		break;
	}


    

#ifdef SUPPORT_WINTOOL
	}
#endif

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
int REALTEK_I_DVBC_GetCarrierOffset(DEMOD* pDemodKernel, long* pOffset)
{
	int ret = TUNER_CTRL_OK;
	unsigned char lock = 0;
	unsigned int CarrierFreq;
	unsigned int  tuner_if = 0;
	unsigned int DemodStatus;

	REALTEK_I_DVBC* pRealtekIDVBC;
	DVBC_DEMOD_MODULE* pDemod;
	pRealtekIDVBC = (REALTEK_I_DVBC*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_DVBC_DRIVER_DATA*) pRealtekIDVBC->m_private)->pDemod;

	//FUNCTION_NAME_PRINT("REALTEK_I_DVBC::GetCarrierOffset\n");
	if (!DtvIsDemodClockEnable(RTK_DEMOD_MODE_DVBC))
		return TUNER_CTRL_FAIL;

	pDemodKernel->Lock(pDemodKernel);

#ifdef SUPPORT_WINTOOL
	if(!pRealtekIDVBC->m_debug_tool_en)
	{
#endif




	ret |= (pDemod->GetDemodStatus(pDemod, &DemodStatus));
	lock = (DemodStatus == 5) ? 1 : 0;

	if (lock == 0) {
		REALTEK_I_DVBC_INFO("GetCarrierOffset fail beacause demod is unlock\n");
		goto GetCarrierOffset_Fail;
	}

	tuner_if = pDemodKernel->m_if.freq; //update from SetTVSysEx

	ret = DECODE_RET(pDemod->GetMonitorCarrierFrequency(pDemod, &CarrierFreq));
	*pOffset = -(tuner_if + CarrierFreq);

	if (ret != TUNER_CTRL_OK)
		*pOffset = 0;

	REALTEK_I_DVBC_INFO("m_if.freq=%dHz, CarrierFreq=%dHz, CarrierOffset = %dHz\n", tuner_if, CarrierFreq, *pOffset);




#ifdef SUPPORT_WINTOOL
	}
#endif

	pDemodKernel->Unlock(pDemodKernel);
	return ret;

GetCarrierOffset_Fail:
	pDemodKernel->Unlock(pDemodKernel);
	return TUNER_CTRL_FAIL;

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
int REALTEK_I_DVBC_GetDebugLogBuf(DEMOD* pDemodKernel, unsigned int* LogBufAddr, unsigned int* LogBufSize)
{
	int ret = TUNER_CTRL_OK;
	REALTEK_I_DVBC* pRealtekIDVBC;
	DVBC_DEMOD_MODULE* pDemod;
	pRealtekIDVBC = (REALTEK_I_DVBC*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_DVBC_DRIVER_DATA*) pRealtekIDVBC->m_private)->pDemod;
	unsigned int ReadValue = 0;
	pDemodKernel->Lock(pDemodKernel);
	if (pDemod) {
		ret |= pDemod->GetVirtualRegister(pDemod, TV_REG_ENSIGMA_SDK_BUFF_PTR, &ReadValue);
		* LogBufAddr = ReadValue;
		ret |= pDemod->GetVirtualRegister(pDemod, TV_REG_ENSIGMA_SDK_BUFF_SIZE, &ReadValue);
		* LogBufSize = ReadValue;
		if (ret != TUNER_CTRL_OK) {
			* LogBufAddr = 0;
			* LogBufSize = 0;
		}
	} else {
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
int REALTEK_I_DVBC_AcquireSignal(DEMOD* pDemodKernel, unsigned char WaitSignalLock)
{
	unsigned char	lock = NO;
	unsigned int	DemodStatus, IsNoSignal, State = 0;
	int ret = TUNER_CTRL_OK;

	REALTEK_I_DVBC* pRealtekIDVBC;
	DVBC_DEMOD_MODULE* pDemod;
	pRealtekIDVBC = (REALTEK_I_DVBC*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_DVBC_DRIVER_DATA*) pRealtekIDVBC->m_private)->pDemod;

	REALTEK_I_DVBC_DBG("AcquireSignal pDemodKernel->m_ScanMode = %d, time=%d\n", pDemodKernel->m_ScanMode, tv_osal_time() - pRealtekIDVBC->m_acquire_stime);

	pRealtekIDVBC->m_auto_tune_en = 0;

#ifdef SUPPORT_WINTOOL
	pRealtekIDVBC->m_debug_tool_en = 0;
#endif

ResetDemod_Reacuire:
	if (!WaitSignalLock)
		return TUNER_CTRL_OK;

	lock = NO;
	IsNoSignal = NO;
	ret = TUNER_CTRL_OK;

	pDemodKernel->Lock(pDemodKernel);

#ifdef CONFIG_RTK_KDRV_DEMOD_SCAN_THREAD_ENABLE

	ret |= DECODE_RET(pDemod->GetSystemState(pDemod, &State));
	if( (ret != TUNER_CTRL_OK) && ( gResetDemodCnt < 1) ) {
		REALTEK_I_DVBC_INFO("[AcquireSignal TH_EN]GetSystemState != TUNER_CTRL_OK\n");
		goto Reset_Demod;
	}
	ret |= DECODE_RET(pDemod->GetDemodStatus(pDemod, &DemodStatus));
	if( (ret != TUNER_CTRL_OK) && ( gResetDemodCnt < 1) ) {
		REALTEK_I_DVBC_INFO("[AcquireSignal TH_EN]GetDemodStatus != TUNER_CTRL_OK\n");
		goto Reset_Demod;
	}
	ret |= DECODE_RET(pDemod->GetIsNoSignal(pDemod, &IsNoSignal));
	if( (ret != TUNER_CTRL_OK) && ( gResetDemodCnt < 1) ) {
		REALTEK_I_DVBC_INFO("[AcquireSignal TH_EN]GetIsNoSignal != TUNER_CTRL_OK\n");
		goto Reset_Demod;
	}

	if (DemodStatus == 5)
		lock = YES;

	pDemodKernel->Unlock(pDemodKernel);

	if (lock) {
		REALTEK_I_DVBC_INFO("\033[1;32;31m" "DVBC Signal Lock!!!\n" "\033[m");
		REALTEK_I_DVBC_INFO("signal lock = %u, DemodState = %d, Time = %lu\n", lock, State, tv_osal_time() - pRealtekIDVBC->m_acquire_stime);
		return TUNER_CTRL_OK;
	} else {
		//if (IsNoSignal || ((tv_osal_time() - pRealtekIDVBC->m_acquire_stime) >  8000)) {  //2200
		if (((IsNoSignal) && ((tv_osal_time() - pRealtekIDVBC->m_acquire_stime) > 2000)) || ((tv_osal_time() - pRealtekIDVBC->m_acquire_stime) >  4000)) {  //2200
			REALTEK_I_DVBC_INFO("\033[1;32;32m" "DVBC No Signal!!!\n" "\033[m");
			REALTEK_I_DVBC_INFO("signal lock = %u, IsNoSignal = %d, DemodState = %d, Time = %lu\n", lock, IsNoSignal, State, tv_osal_time() - pRealtekIDVBC->m_acquire_stime);
			return TUNER_CTRL_OK;
		} else {
			return TUNER_CTRL_FAIL;
		}
	}
	
#else

	while ((tv_osal_time() - pRealtekIDVBC->m_acquire_stime) <= 4000) {  //2200
		tv_osal_msleep(5);
		ret |= DECODE_RET(pDemod->GetSystemState(pDemod, &State));
		if( (ret != TUNER_CTRL_OK) && ( gResetDemodCnt < 1) ) {
			REALTEK_I_DVBC_INFO("[AcquireSignal TH_DIS]GetSystemState != TUNER_CTRL_OK\n");
			goto Reset_Demod;
		}
		ret |= DECODE_RET(pDemod->GetDemodStatus(pDemod, &DemodStatus));
		if( (ret != TUNER_CTRL_OK) && ( gResetDemodCnt < 1) ) {
			REALTEK_I_DVBC_INFO("[AcquireSignal TH_DIS]GetDemodStatus != TUNER_CTRL_OK\n");
			goto Reset_Demod;
		}
		ret |= DECODE_RET(pDemod->GetIsNoSignal(pDemod, &IsNoSignal));
		if( (ret != TUNER_CTRL_OK) && ( gResetDemodCnt < 1) ) {
			REALTEK_I_DVBC_INFO("[AcquireSignal TH_DIS]GetIsNoSignal != TUNER_CTRL_OK\n");
			goto Reset_Demod;
		}
		
		if (DemodStatus == 5) {
			lock = YES;
			REALTEK_I_DVBC_INFO("\033[1;32;31m" "DVBC Signal Lock!!!\n" "\033[m");
			break;
		} else {
			if ((IsNoSignal) && ((tv_osal_time() - pRealtekIDVBC->m_acquire_stime) > 2000) ) {
			//if (IsNoSignal) {
				lock = NO;
				REALTEK_I_DVBC_INFO("\033[1;32;32m" "DVBC No Signal!!!\n" "\033[m");
				break;
			}
		}
	}
	REALTEK_I_DVBC_INFO("signal lock = %u, DemodState = %d, Time = %lu\n", lock, State, tv_osal_time() - pRealtekIDVBC->m_acquire_stime);

	pDemodKernel->Unlock(pDemodKernel);
	return (lock) ? TUNER_CTRL_OK : TUNER_CTRL_NO_SIGNAL;

#endif
Reset_Demod:
	REALTEK_I_DVBC_INFO("[AcquireSignal]ResetDemod caused by api not ok!\n");
	gResetDemodCnt++;
	ResetDemodDvbc(pDemodKernel);
	pDemodKernel->Unlock(pDemodKernel);
	goto ResetDemod_Reacuire;
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
int REALTEK_I_DVBC_ScanSignal(DEMOD* pDemodKernel, long* pOffset, SCAN_RANGE range)
{

	REALTEK_I_DVBC* pRealtekIDVBC;
	DVBC_DEMOD_MODULE* pDemod;
	pRealtekIDVBC = (REALTEK_I_DVBC*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_DVBC_DRIVER_DATA*) pRealtekIDVBC->m_private)->pDemod;


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
int REALTEK_I_DVBC_ForwardI2C(DEMOD* pDemodKernel, unsigned char on_off)
{
	int ret = TUNER_CTRL_OK;

	REALTEK_I_DVBC* pRealtekIDVBC;
	DVBC_DEMOD_MODULE* pDemod;
	pRealtekIDVBC = (REALTEK_I_DVBC*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_DVBC_DRIVER_DATA*) pRealtekIDVBC->m_private)->pDemod;

	//FUNCTION_NAME_PRINT("REALTEK_I_DVBC::ForwardI2C\n");


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
int REALTEK_I_DVBC_AutoTune(DEMOD* pDemodKernel)
{
	int ret = TUNER_CTRL_OK;
	unsigned char	lock;
	unsigned int	DemodStatus;

	REALTEK_I_DVBC* pRealtekIDVBC;
	pRealtekIDVBC = (REALTEK_I_DVBC*)(pDemodKernel->private_data);
	DVBC_DEMOD_MODULE* pDemod = ((REALTEK_I_DVBC_DRIVER_DATA*) pRealtekIDVBC->m_private)->pDemod;

	if (pRealtekIDVBC->m_auto_tune_en) {
		pDemodKernel->Lock(pDemodKernel);
		ret = DECODE_RET(pDemod->UpdateFunction(pDemod));
		pDemodKernel->Unlock(pDemodKernel);
	}
	
#ifdef ENABLE_LDR_LOADER
    if(rtd_inl(0xb8000200) == 0x60)
    {
        while(1)
        {
            
        }
    }
#endif
    
#ifdef SUPPORT_WINTOOL
	unsigned int dbg_pri_addr = 0, dbg_sec_addr = 0, dbg_val = 0, ConstData = 0, sqi = 0, u8i = 0;

	if(rtd_inl(DEBUG_MODE_EN_ADDRESS) == 0x00022243)
	{
        REALTEK_I_DVBC_INFO("\033[1;32;33m" "WINTOOL ENABLED\n" "\033[m");
		if(rtd_inl(DEBUG_MODE_SEL_ADDRESS) == 0xFFFFFFFF)//Dump All Virtual Register
		{
			pRealtekIDVBC->m_debug_tool_en = 1;
			if(rtd_inl(HANDSHAKE_ADDRESS) == 0x00000001)//tool done
			{
				ret |= DECODE_RET(pDemod->DemodCtrlUpdateCounters(pDemod));
				for(dbg_pri_addr = 0; dbg_pri_addr <= 4; dbg_pri_addr++)
				{
					ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, dbg_pri_addr, &dbg_val));
					rtd_outl(COMMON_BASE_ADDRESS+dbg_pri_addr*4, dbg_val);
				}
				
				for(dbg_pri_addr = 0; dbg_pri_addr <= (CABLE_REG_TOTALREG-TV_REG_NUM_COMMON_REG); dbg_pri_addr++)
				{
					ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, (0x8000+dbg_pri_addr), &dbg_val));
					rtd_outl(VR_BASE_ADDRESS+dbg_pri_addr*4, dbg_val);
				}
				
				ret |= DECODE_RET(pDemod->GetSignalSQI(pDemod, &sqi));
				rtd_outl(DVBC_SQI_ADDRESS, sqi);
				
				//EQ/HD Constellation
				ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, 0x13, 0x00000002));
				ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, 0x15, 0x0000038e));
				for(u8i = 0; u8i < 6; u8i++)
				{
					pDemod->GetHwRegValue(0xb602e600+u8i*4, &ConstData);
					rtd_outl(CONSTELL_EQ_ADDRESS+u8i*4, ConstData);
					
					//pDemod->GetHwRegValue(0xb602e600+u8i*4, &ConstData);
					//rtd_outl(CONSTELL_HD_ADDRESS+u8i*4, ConstData);
				}
				
				rtd_outl(HANDSHAKE_ADDRESS, 0x00000002);//driver done
			}
		}
		else if(rtd_inl(DEBUG_MODE_SEL_ADDRESS) == 0xFFFFFFFE)//GetVirtualRegister
		{
			pRealtekIDVBC->m_debug_tool_en = 1;
			if(rtd_inl(HANDSHAKE_ADDRESS) == 0x00000001)//tool done
			{
				dbg_pri_addr = rtd_inl(PRI_VR_INDEX_ADDRESS);//get vr index
				dbg_sec_addr = rtd_inl(SEC_VR_INDEX_ADDRESS);//get vr index
				ret |= DECODE_RET(pDemod->GetCtrlVirtualRegister(pDemod, dbg_pri_addr, dbg_sec_addr, &dbg_val));
				rtd_outl(VR_VALUE_ADDRESS, dbg_val);//get vr value

				rtd_outl(HANDSHAKE_ADDRESS, 0x00000002);//driver done
			}
		}
		else if(rtd_inl(DEBUG_MODE_SEL_ADDRESS) == 0xFFFFFFFD)//SetVirtualRegister
		{
			pRealtekIDVBC->m_debug_tool_en = 1;
			if(rtd_inl(HANDSHAKE_ADDRESS) == 0x00000001)//tool done
			{
				dbg_pri_addr = rtd_inl(PRI_VR_INDEX_ADDRESS);//get vr index
				dbg_sec_addr = rtd_inl(SEC_VR_INDEX_ADDRESS);//get vr index
				dbg_val = rtd_inl(VR_VALUE_ADDRESS);//get vr value
				ret |= DECODE_RET(pDemod->SetCtrlVirtualRegister(pDemod, dbg_pri_addr, dbg_sec_addr, dbg_val));

				rtd_outl(HANDSHAKE_ADDRESS, 0x00000002);//driver done
			}
		}
	}
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
int REALTEK_I_DVBC_InspectSignal(DEMOD* pDemodKernel)
{
	int ret = TUNER_CTRL_OK;
	long CrOffsetHz  = -1;
	unsigned char	lock;
	unsigned int DemodStatus;
	unsigned int CarrierFreq = 0;
	unsigned int ErrBit = 1;
	unsigned int PakN = 1;
	unsigned int TotalBit = 1;
	unsigned int BadPakN = 1;
	unsigned int Eqout = 0;

	REALTEK_I_DVBC* pRealtekIDVBC;
	DVBC_DEMOD_MODULE* pDemod;
	pRealtekIDVBC = (REALTEK_I_DVBC*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_DVBC_DRIVER_DATA*) pRealtekIDVBC->m_private)->pDemod;

	//FUNCTION_NAME_PRINT("REALTEK_I_DVBC::InspectSignal\n");
	if (!DtvIsDemodClockEnable(RTK_DEMOD_MODE_DVBC))
		return TUNER_CTRL_FAIL;

	pDemodKernel->Lock(pDemodKernel);

	ret |= (pDemod->GetDemodStatus(pDemod, &DemodStatus));
	lock = (DemodStatus == 5) ? 1 : 0;

	if (lock) {
		ret = pDemod->GetMonitorCarrierFrequency(pDemod, &CarrierFreq);
		ret |= pDemod->GetEqOutputSnr(pDemod, &Eqout);
		ret |= pDemod->DemodCtrlUpdateCounters(pDemod);
		ret |= pDemod->GetTsPacketNumber(pDemod, &PakN);
		ret |= pDemod->GetBadPacketNumber(pDemod, &BadPakN);
		ret |= pDemod->GetBitErrorNumber(pDemod, &ErrBit);
		ret |= pDemod->DemodCtrlResetCounters(pDemod);
		TotalBit = PakN * 204 * 8;
		CrOffsetHz = pDemodKernel->m_if.freq + CarrierFreq;
	}

	pDemodKernel->Unlock(pDemodKernel);

#if 0
	ret = snprintf(pBuff, BufferSize, "[REALTEK_I_DVBC] lock=%u, error_rate(ber/per)=%f/%f, snr=%f, ofst(cr)=%ld\n",
				   lock,
				   (double) ErrBit  / ((double) TotalBit),
				   (double) BadPakN / (double) PakN,
				   (double) Eqout / 256,
				   CrOffsetHz);
#endif

	return ret;
}



/*----------------------------------------------------------------------
 * Func : Activate
 *
 * Desc : Activate RTK_DEMOD_DVBC Demod
 *
 * Parm : N/A
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBC_Activate(DEMOD* pDemodKernel, unsigned char force_rst)
{

	REALTEK_I_DVBC* pRealtekIDVBC;
	DVBC_DEMOD_MODULE* pDemod;
	pRealtekIDVBC = (REALTEK_I_DVBC*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_DVBC_DRIVER_DATA*) pRealtekIDVBC->m_private)->pDemod;

	//FUNCTION_NAME_PRINT("REALTEK_I_DVBC::Activate\n");
	pDemodKernel->Init(pDemodKernel);

	return TUNER_CTRL_OK;

activate_demod_fail:
	pDemodKernel->Unlock(pDemodKernel);
	return TUNER_CTRL_FAIL;
}

/*----------------------------------------------------------------------
 * Func : SetTvMode
 *
 * Desc : Set Mode of RTK_DEMOD_DVBC
 *
 * Parm : mode :    RTK_DEMOD_MODE_DVBC : DVBC mode
 *                  RTK_DEMOD_MODE_DVBC  : DVBC mode
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBC_SetTvMode(DEMOD* pDemodKernel, TV_SYSTEM_TYPE mode)
{
	int ret = TUNER_CTRL_FAIL;
	REALTEK_I_DVBC* pRealtekIDVBC;
	pRealtekIDVBC = (REALTEK_I_DVBC*)(pDemodKernel->private_data);

	//FUNCTION_NAME_PRINT("REALTEK_I_DVBC::SetTvMode\n");
	pDemodKernel->Lock(pDemodKernel);

	REALTEK_I_DVBC_INFO("REALTEK_I_DVBC::SetTvMode(%d)\n", mode);

	switch (mode) {

	case TV_SYS_TYPE_DVBC:

		REALTEK_I_DVBC_INFO("Set to DVBC\n");
		ret = pDemodKernel->Init(pDemodKernel);
		ret |= pDemodKernel->SetTSMode(pDemodKernel, &pDemodKernel->m_ts);

		if (ret != TUNER_CTRL_OK) {
			REALTEK_I_DVBC_WARNING("Set REALTEK_I_DVBC to DVBC mode failed\n");
			goto set_demod_mode_failed;
		}

		break;

	default:
		goto set_demod_mode_failed;
	}

	ret = TUNER_CTRL_OK;
	REALTEK_I_DVBC_INFO("Set REALTEK_I_DVBC to appointed DTV mode successed\n");

	pDemodKernel->Unlock(pDemodKernel);
	return ret;

set_demod_mode_failed:
	pDemodKernel->Unlock(pDemodKernel);
	return TUNER_CTRL_FAIL;
}

void REALTEK_I_DVBC_Lock(DEMOD* pDemodKernel)
{
	//FUNCTION_NAME_PRINT("LOCK 0x%x\n",&pDemodKernel->m_lock);
	//mutex_lock(&pDemodKernel->m_lock);
}

void REALTEK_I_DVBC_Unlock(DEMOD* pDemodKernel)
{
	//FUNCTION_NAME_PRINT("UN_LOCK 0x%x\n",&pDemodKernel->m_lock);
	//mutex_unlock(&pDemodKernel->m_lock);
}


/*-----------------------------------------------------------------
 *     BASE_INTERFACE for REALTEK_I_DVBC API
 *----------------------------------------------------------------*/

void ReleaseRealtekIDvbcDriver(REALTEK_I_DVBC_DRIVER_DATA *pDriver)
{
	kfree(pDriver);
}


REALTEK_I_DVBC_DRIVER_DATA* AllocRealtekIDvbcDriver(
	COMM*               pComm,
	unsigned char       Addr,
	unsigned long       CrystalFreq
)
{
	REALTEK_I_DVBC_DRIVER_DATA* pDriver = (REALTEK_I_DVBC_DRIVER_DATA*) kmalloc(
											sizeof(REALTEK_I_DVBC_DRIVER_DATA) +
											sizeof(DVBC_DEMOD_MODULE)   +
											sizeof(I2C_BRIDGE_MODULE)   +
											sizeof(BASE_INTERFACE_MODULE), GFP_KERNEL);

	//FUNCTION_NAME_PRINT("AllocRealtekIDvbcDriver\n");
	if (pDriver) {
		BASE_INTERFACE_MODULE* pBIF;
		DVBC_DEMOD_MODULE* pDemod;
		memset(pDriver, 0, sizeof(REALTEK_I_DVBC_DRIVER_DATA));

		pDriver->pDemod                = (DVBC_DEMOD_MODULE*)(((unsigned char*)pDriver) + sizeof(REALTEK_I_DVBC_DRIVER_DATA));
		pDriver->pBaseInterface        = (BASE_INTERFACE_MODULE*)(((unsigned char*)pDriver->pDemod) + sizeof(DVBC_DEMOD_MODULE));
		pDriver->pI2CBridge            = (I2C_BRIDGE_MODULE*)(((unsigned char*)pDriver->pBaseInterface) + sizeof(BASE_INTERFACE_MODULE));
		pDriver->DeviceAddr            = Addr;
		pDriver->CrystalFreqHz         = CrystalFreq;

		// Init Base IF
		pBIF = pDriver->pBaseInterface;

		pBIF->I2cReadingByteNumMax      = RTK_DEMOD_BIF_TX_FIFO_DEPTH;
		pBIF->I2cWritingByteNumMax      = RTK_DEMOD_BIF_RX_FIFO_DEPTH;
		pBIF->I2cRead                   = __realtek_i2c_read;
		pBIF->I2cWrite                  = __realtek_i2c_write;
		pBIF->WaitMs                    = __realtek_wait_ms;
		pBIF->SetUserDefinedDataPointer = base_interface_SetUserDefinedDataPointer;
		pBIF->GetUserDefinedDataPointer = base_interface_GetUserDefinedDataPointer;
		pBIF->SetUserDefinedDataPointer(pBIF, (void*)pComm);

		// Init Demod Driver
		BuildRealtekIDvbCModule(&pDemod,
							   pDriver->pDemod,
							   pDriver->pBaseInterface,
							   pDriver->pI2CBridge,
							   Addr,
							   CrystalFreq);            // Spectrum mode is inverse.
	}

	return pDriver;
}


unsigned int ResetDemodDvbc(DEMOD* pDemodKernel)
{
	unsigned char     PGAEnable = 0;
	IFADCGAIN      PGAGain;
	unsigned int      IsRpuLowReady, IsRpuHighReady;
	unsigned int      BuildId, DemodType;
	unsigned int      InitRetry = 0;
	int               ret = TUNER_CTRL_OK;

	REALTEK_I_DVBC* pRealtekIDVBC;
	REG_VALUE_ENTRY*  OptRegTable;
	DVBC_DEMOD_MODULE* pDemod;
	TUNER_PARAM Param;
	pRealtekIDVBC = (REALTEK_I_DVBC*)(pDemodKernel->private_data);
	
	if (pDemodKernel->m_pComm == NULL || pRealtekIDVBC->m_private == NULL){
		REALTEK_I_DVBC_INFO("[ResetDemod]pDemodKernel->m_pComm == NULL || pRealtekIDVBC->m_private == NULL\n");
		//return TUNER_CTRL_FAIL;
	}
	pDemod = ((REALTEK_I_DVBC_DRIVER_DATA*) pRealtekIDVBC->m_private)->pDemod;

	pDemodKernel->Lock(pDemodKernel);

	pRealtekIDVBC->m_auto_tune_en = 0;

demod_re_init:
	//DtvDemodClockEnable(1);
	DtvDemodInitialization(RTK_DEMOD_MODE_DVBC, 1);

	ret = DECODE_RET(pDemod->CheckRpuReady(pDemod, &IsRpuLowReady));//Check for Low level Header
	ret |= DECODE_RET(pDemod->CheckRpuReady(pDemod, &IsRpuHighReady));//Check for High level Msg

	if (IsRpuLowReady != 1 || IsRpuHighReady != 1) {
		REALTEK_I_DVBC_INFO("Waiting for Demod Init Done; Demod Has No Reply !!!!\n");
		REALTEK_I_DVBC_INFO("Waiting for Demod Init Done; Demod Has No Reply !!!!\n");
		REALTEK_I_DVBC_INFO("Waiting for Demod Init Done; Demod Has No Reply !!!!\n");
		REALTEK_I_DVBC_INFO("Waiting for Demod Init Done; Demod Has No Reply !!!!\n");
		REALTEK_I_DVBC_INFO("RpuLowReady = %d, RpuHighReady = %d\n", IsRpuLowReady, IsRpuHighReady);

		if (!InitRetry) {
			InitRetry = 1;
			REALTEK_I_DVBC_INFO("\033[1;32;32m" "RPU Auto Re-Init in Demod Init\n" "\033[m");
			goto demod_re_init;
		} else {
			goto init_fail;
		}
	}

	//Change To Buffer Mode
	REALTEK_I_DVBC_INFO("Change To Buffer Mode........\n");
	ret |= DECODE_RET(pDemod->SwitchToBuffer(pDemod));
	if (ret != TUNER_CTRL_OK) {
		REALTEK_I_DVBC_INFO("Change To Buffer Mode Fail !!!!!\n");
		goto init_fail;
	}

	// ActivateCore DVBC
	ret |= DECODE_RET(pDemod->ActivateCore(pDemod));
	if (ret != TUNER_CTRL_OK) {
		REALTEK_I_DVBC_INFO("ActivateCore Fail !!!!!\n");
		goto init_fail;
	}

	// check tuner information	
	PGAEnable = 2;
	PGAGain = PGAFIX_2DB;
	pRealtekIDVBC->m_dvbc_AgcScale = 89;
	pRealtekIDVBC->m_dvbc_ext_gain_dis = RTK_DEMOD_XML_EXT_GAIN_EN;

	if (pDemodKernel->m_pTuner->GetParam(pDemodKernel->m_pTuner, TV_SYS_DVBC_6M, &Param) == TUNER_CTRL_OK) {
		switch (Param.id) {
		case TV_TUNER_NXP_TDA18275A:
			REALTEK_I_DVBC_INFO("Tuner id %d, TV_TUNER_NXP_TDA1827X\n", Param.id);
			pRealtekIDVBC->m_dvbc_AgcScale = 51;//51/128=0.4
			pRealtekIDVBC->m_dvbc_ext_gain_dis = RTK_DEMOD_XML_EXT_GAIN_EN;
			break;
		case TV_TUNER_SILICONLABS_SI2151:
		case TV_TUNER_SILICONLABS_SI2178B:
		case TV_TUNER_NO_TUNER:
			REALTEK_I_DVBC_INFO("Tuner id %d, TV_TUNER_SILICONLABS_SI215x\n", Param.id);
			pRealtekIDVBC->m_dvbc_AgcScale = 89;
			pRealtekIDVBC->m_dvbc_ext_gain_dis = RTK_DEMOD_XML_EXT_GAIN_EN;
			break;
		case TV_TUNER_MAXLINEAR_MXL661:
			REALTEK_I_DVBC_INFO("Tuner id %d, TV_TUNER_MAXLINEAR_MXL6x1\n", Param.id);
			pRealtekIDVBC->m_dvbc_AgcScale = 89; //64/128=0.5
			pRealtekIDVBC->m_dvbc_ext_gain_dis = RTK_DEMOD_XML_EXT_GAIN_EN;
			break;
		case TV_TUNER_RAFAEL_R840:
			REALTEK_I_DVBC_INFO("Tuner id %d, TV_TUNER_RAFAEL_R840\n", Param.id);
			pRealtekIDVBC->m_dvbc_AgcScale =  51;//51/128=0.4
			pRealtekIDVBC->m_dvbc_ext_gain_dis = RTK_DEMOD_XML_EXT_GAIN_EN;
			break;
		default:
			REALTEK_I_DVBC_WARNING("unkonw tuner id %d, using default setting\n", Param.id);
			pRealtekIDVBC->m_dvbc_AgcScale = 128;
			pRealtekIDVBC->m_dvbc_ext_gain_dis = RTK_DEMOD_XML_EXT_GAIN_EN;
			break;
		}

		pDemodKernel->m_if.freq      = Param.if_freq;
		pDemodKernel->m_if.inversion = Param.if_inversion;
		pDemodKernel->m_if.agc_pola  = Param.if_agc_pola;
	} else {
		REALTEK_I_DVBC_INFO("[ResetDemod]pDemodKernel->m_pTuner->GetParam(pDemodKernel->m_pTuner, TV_SYS_DVBC_6M, &Param) != TUNER_CTRL_OK\n");
	}

	DtvPGAControl(PGAEnable, PGAGain);

	// Initial Driver

	ClearDemodReset(RTK_DEMOD_MODE_DVBC);

	if (pDemodKernel->SetTSMode(pDemodKernel, &pDemodKernel->m_ts) != TUNER_CTRL_OK){
		REALTEK_I_DVBC_INFO("[ResetDemod]pDemodKernel->SetTSMode(pDemodKernel, &pDemodKernel->m_ts) != TUNER_CTRL_OK\n");
		//goto init_fail;
	}

	ret |= DECODE_RET(pDemod->GetDemodInfo(pDemod, &DemodType));
	ret |= DECODE_RET(pDemod->GetBuildId(pDemod, &BuildId));
	REALTEK_I_DVBC_INFO("DemodType = %x, BuildId = %x\n", DemodType, BuildId);

	//10.2.0 Support Run Time Change XML Parmeters
	ret |= DECODE_RET(pDemod->SetXmlTunerGainCtrl(pDemod, pRealtekIDVBC->m_dvbc_AgcScale | (RTK_DEMOD_XML_EXT_GAIN1 << 16) | (pDemodKernel->m_if.agc_pola << 18)));
	ret |= DECODE_RET(pDemod->SetXmlFlags(pDemod, RTK_DEMOD_XML_REAL_IF | (pDemodKernel->m_if.inversion << 1) | (RTK_DEMOD_XML_UNSIGNED << 2) | (pRealtekIDVBC->m_dvbc_ext_gain_dis << 3)));
	ret |= DECODE_RET(pDemod->SetXmlIfFreq(pDemod, pDemodKernel->m_if.freq));
	ret |= DECODE_RET(pDemod->SetXmlTunerCfgOverride(pDemod, 0x00000001));

	ret |= DECODE_RET(pDemod->SetXmlIfClk(pDemod, 30000000));
	ret |= DECODE_RET(pDemod->SetXmlLdpcClk(pDemod, DVBC_META_CLOCK));
	ret |= DECODE_RET(pDemod->SetXmlUccClk(pDemod, DVBC_META_CLOCK));
	ret |= DECODE_RET(pDemod->SetXmlMcuClk(pDemod, DVBC_META_CLOCK));
	ret |= DECODE_RET(pDemod->SetXmlPlftCfgOverride(pDemod, 0x00000001));

	// Set Symbol Rate Search Range
	ret |= DECODE_RET(pDemod->SetSymbolRateSearchMode(pDemod, 0x2));
	ret |= DECODE_RET(pDemod->SetMinSymbolRate(pDemod, 3600000));
	ret |= DECODE_RET(pDemod->SetMaxSymbolRate(pDemod, 7000000));

	pDemodKernel->Unlock(pDemodKernel);
	REALTEK_I_DVBC_INFO("REALTEK_I_DVBC Init Complete\n");
	return TUNER_CTRL_OK;

init_fail:
	REALTEK_I_DVBC_WARNING("REALTEK_I_DVBC Init Failed\n");
	pDemodKernel->Unlock(pDemodKernel);
	return TUNER_CTRL_FAIL;	
}


