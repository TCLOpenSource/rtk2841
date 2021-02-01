/***************************************************************************************************
  File        : demod_rtk_isdbt.cpp
  Description : REALTEK_I ISDB-T demod
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
//#include <assert.h>
#include <linux/pageremap.h>
#include "foundation.h"
#include "demod_rtk_isdbt.h"
#include "isdbt_demod_rtk.h"
#include "demod_rtk_isdbt_priv.h"
#include "isdbt_tvcore_registers.h"

#include <mach/io.h>
#include "rbus/demod_sd_reg.h"

#define SET_TV_REG_DEMOD_LOCK_TIMEOUT_VALUE 1500
//ISDBT SSI
#define DVBT_SSI_NEG100p5_Q8    (-25728)
#define DVBT_SSI_NEG15_Q8       (-3840)
#define DVBT_SSI_10_Q8          (2560)
#define DVBT_SSI_15_Q8          (3840)
#define DVBT_SSI_20_Q8          (5120)
#define DVBT_SSI_35_Q8          (8960)
#define DVBT_SSI_90_Q8          (23040)
#define DVBT_SSI_100_Q8         (25600)
#define DVBT_SSI_ZERO_Q8        (0)
#define PHY_ONE_Q8              (1<<8)
/* Lookup tables for SSI/SQI */
static const signed char PHY_Pref[3][5] = {
	/* 1R2  2R3  3R4  5R6  7R8 */
	{  -93, -91, -90, -89, -88 },   /* QPSK  */
	{  -87, -85, -84, -83, -82 },   /* 16QAM */
	{  -82, -80, -78, -77, -76 }    /* 64QAM */
};

#define CONTINUOUS_MOSAIC_CNT_THD 2
static unsigned char g1stGI1_4 = 0;
static unsigned char gIsResetDemod = 0;
static unsigned char IsGiChanged = 0;
static unsigned int PreGuardInterval = 0;
unsigned long autotune_stime = 0;
static unsigned gMaxSegLayer = 0;
/*----------------------------------------------------------------------
 * Func : REALTEK_I_ISDBT
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
void REALTEK_I_ISDBT_Constructors(DEMOD* pDemodKernel, unsigned char addr, 	unsigned char output_mode, unsigned char output_freq, COMM* pComm)
{
	REALTEK_I_ISDB* pRealtekIISDB;
	pDemodKernel->private_data = kmalloc(sizeof(REALTEK_I_ISDB), GFP_KERNEL);
	pRealtekIISDB = (REALTEK_I_ISDB*)(pDemodKernel->private_data);
	Demod_Constructors(pDemodKernel);

	pDemodKernel->m_id                 = DTV_DEMOD_REALTEK_I_ISDBT;
	pDemodKernel->m_addr               = addr;
	pDemodKernel->m_pTuner             = NULL;
	pDemodKernel->m_pComm              = pComm;
	pDemodKernel->m_ScanRange          = SCAN_RANGE_3_6;
	pDemodKernel->m_Capability         = TV_SYS_TYPE_ISDBT;
	pDemodKernel->m_update_interval_ms = 300;
	pDemodKernel->m_if.freq            = 5000000;
	pDemodKernel->m_if.inversion       = 0;
	pDemodKernel->m_if.agc_pola        = 0;
	pDemodKernel->m_clock              = CRYSTAL_FREQ_27000000HZ;
	pRealtekIISDB->m_output_freq        = output_freq;

	pRealtekIISDB->m_private            = (void*) AllocRealtekIDriver_ISDBT(
			pDemodKernel->m_pComm,
			pDemodKernel->m_addr,
			pDemodKernel->m_clock,
			(output_mode == RTK_DEMOD_OUT_IF_PARALLEL) ? TS_INTERFACE_PARALLEL : TS_INTERFACE_SERIAL);

	pDemodKernel->m_ts.mode            = (output_mode == RTK_DEMOD_OUT_IF_PARALLEL) ? PARALLEL_MODE : SERIAL_MODE;
	pDemodKernel->m_ts.data_order      = MSB_D7;
	pDemodKernel->m_ts.datapin         = MSB_FIRST;
	pDemodKernel->m_ts.err_pol         = ACTIVE_HIGH;
	pDemodKernel->m_ts.sync_pol        = ACTIVE_HIGH;
	pDemodKernel->m_ts.val_pol         = ACTIVE_HIGH;
	pDemodKernel->m_ts.clk_pol         = FALLING_EDGE;
	pDemodKernel->m_ts.internal_demod_input = 1;
	pDemodKernel->m_ts.tsOutEn = 1;
	pRealtekIISDB->m_low_snr_detect     = 0;
	pRealtekIISDB->m_low_snr_recover    = 0;
	pRealtekIISDB->m_auto_tune_enable   = 0;
	pRealtekIISDB->m_TunerOptRegCnt     = 0;
	pRealtekIISDB->m_pTunerOptReg       = NULL;

	pRealtekIISDB->m_AgcScale = 89;//89/128=0.7

	pDemodKernel->m_pComm->SetTargetName(pDemodKernel->m_pComm, pDemodKernel->m_addr, "REALTEK_I_ISDBT");

	pDemodKernel->Init = REALTEK_I_ISDBT_Init;
	pDemodKernel->Reset = Demod_Reset;
	pDemodKernel->AcquireSignal = REALTEK_I_ISDBT_AcquireSignal;
	pDemodKernel->ScanSignal = REALTEK_I_ISDBT_ScanSignal;
	pDemodKernel->SetIF = REALTEK_I_ISDBT_SetIF;
	pDemodKernel->SetTSMode = REALTEK_I_ISDBT_SetTSMode;
	pDemodKernel->SetTVSysEx = REALTEK_I_ISDBT_SetTVSysEx;
	pDemodKernel->SetMode = REALTEK_I_ISDBT_SetMode;
	pDemodKernel->SetTVSys = REALTEK_I_ISDBT_SetTVSys;
	pDemodKernel->GetLockStatus = REALTEK_I_ISDBT_GetLockStatus;
	pDemodKernel->GetSegmentNum = REALTEK_I_ISDBT_GetSegmentNum;
	pDemodKernel->GetSignalInfo = REALTEK_I_ISDBT_GetSignalInfo;
	pDemodKernel->GetSignalQuality = REALTEK_I_ISDBT_GetSignalQuality;
        pDemodKernel->ChangeT2PLP = Demod_ChangeT2PLP;
	pDemodKernel->GetT2PLPInfo = Demod_GetT2PLPInfo;
	pDemodKernel->GetT2L1PreInfo = Demod_GetT2L1PreInfo;
	pDemodKernel->GetT2L1PostInfo = Demod_GetT2L1PostInfo;
	pDemodKernel->GetDemodStatus = Demod_GetDemodStatus;
	pDemodKernel->GetCarrierOffset = REALTEK_I_ISDBT_GetCarrierOffset;
	pDemodKernel->ForwardI2C = REALTEK_I_ISDBT_ForwardI2C;
	pDemodKernel->AutoTune = REALTEK_I_ISDBT_AutoTune;
	pDemodKernel->GetCapability = Demod_GetCapability;
	pDemodKernel->Suspend = Demod_Suspend;
	pDemodKernel->Resume = Demod_Resume;
	pDemodKernel->SetTvMode = REALTEK_I_ISDBT_SetTvMode;
	pDemodKernel->InspectSignal = REALTEK_I_ISDBT_InspectSignal;	  // Add monitor function that used to monitor demod status
	pDemodKernel->AttachTuner = Demod_AttachTuner;
	pDemodKernel->GetTSParam = Demod_GetTSParam;
	pDemodKernel->Lock = REALTEK_I_ISDBT_Lock;
	pDemodKernel->Unlock = REALTEK_I_ISDBT_Unlock;

	//pDemodKernel->Activate = REALTEK_I_ISDBT_Activate;
	pDemodKernel->Destory = REALTEK_I_ISDBT_Destructors;

}



/*----------------------------------------------------------------------
 * Func : ~REALTEK_I_ISDBT
 *
 * Desc : Destructor of REALTEK_I_ISDBT
 *
 * Parm : pDemod : handle of Demod
 *
 * Retn : N/A
 *----------------------------------------------------------------------*/
void REALTEK_I_ISDBT_Destructors(DEMOD* pDemodKernel)
{
	REALTEK_I_ISDB* pRealtekIISDB;
	pRealtekIISDB = (REALTEK_I_ISDB*)(pDemodKernel->private_data);

	if (pRealtekIISDB->m_private != NULL)
		ReleaseRealtekIDriver((REALTEK_I_ISDBT_DRIVER_DATA*)pRealtekIISDB->m_private);

	kfree(pRealtekIISDB);
	//pDemodKernel->Destory(pDemodKernel);
	REALTEK_I_ISDBT_DBG("RTK_R_ISDBT_Destructors Complete\n");
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
int REALTEK_I_ISDBT_Init(DEMOD* pDemodKernel)
{
	int ret = TUNER_CTRL_OK;
	unsigned char     PGAEnable = 0;
	IFADCGAIN      PGAGain;
	unsigned int      IsRpuLowReady, IsRpuHighReady;

	REALTEK_I_ISDB* pRealtekIISDB;
	ISDBT_DEMOD_MODULE* pDemod;
	pRealtekIISDB = (REALTEK_I_ISDB*)(pDemodKernel->private_data);

        memset(&PGAGain, 0, sizeof(IFADCGAIN));  

	if (pDemodKernel->m_pComm == NULL || pRealtekIISDB->m_private == NULL)
		return TUNER_CTRL_FAIL;

	pDemod = ((REALTEK_I_ISDBT_DRIVER_DATA*) pRealtekIISDB->m_private)->pDemod;

	//////////////////////////////////////////////////
	//ISDBT_DEMOD_MODULE* pDemod = ((REALTEK_I_ISDBT_DRIVER_DATA*) pRealtekIISDB->m_private)->pDemod;

	//////////////////////////////////////////////////
	//BASE_INTERFACE_MODULE*  pBaseInterface = ((REALTEK_I_ISDBT_DRIVER_DATA*) pRealtekIISDB->m_private)->pBaseInterface;

        pDemodKernel->Lock(pDemodKernel); 

	pRealtekIISDB->m_auto_tune_enable = 0;


	DtvDemodInitialization(RTK_DEMOD_MODE_ISDB, 1);

	ret = DECODE_RET(pDemod->CheckRpuReady(pDemod, &IsRpuLowReady));//Check for Low level Header
	ret |= DECODE_RET(pDemod->CheckRpuReady(pDemod, &IsRpuHighReady));//Check for High level Msg

	if (IsRpuLowReady != 1 || IsRpuHighReady != 1) {
		REALTEK_I_ISDBT_INFO("Waiting for Demod Init Done; Demod Has No Reply !!!!\n");
		REALTEK_I_ISDBT_INFO("Waiting for Demod Init Done; Demod Has No Reply !!!!\n");
		REALTEK_I_ISDBT_INFO("Waiting for Demod Init Done; Demod Has No Reply !!!!\n");
		REALTEK_I_ISDBT_INFO("Waiting for Demod Init Done; Demod Has No Reply !!!!\n");
		REALTEK_I_ISDBT_INFO("RpuLowReady = %d, RpuHighReady = %d\n", IsRpuLowReady, IsRpuHighReady);
			goto init_fail;
		}

	//Change To Buffer Mode
	REALTEK_I_ISDBT_INFO("Change To Buffer Mode........\n");
	ret |= DECODE_RET(pDemod->SwitchToBuffer(pDemod));
	if (ret != TUNER_CTRL_OK) {
		REALTEK_I_ISDBT_INFO("Change To Buffer Mode Fail !!!!!\n");
		goto init_fail;
	}

	// ActivateCore ISDBT
	ret |= DECODE_RET(pDemod->ActivateCore(pDemod));
	if (ret != TUNER_CTRL_OK) {
		REALTEK_I_ISDBT_INFO("ActivateCore Fail !!!!!\n");
		goto init_fail;
	}

	// check tuner information
	PGAEnable = 2;
	PGAGain = PGAFIX_2DB;

	if (pDemodKernel->m_pTuner) {
		TUNER_PARAM Param;

		if (pDemodKernel->m_pTuner->GetParam(pDemodKernel->m_pTuner, TV_SYS_ISDBT_6M, &Param) == TUNER_CTRL_OK) {
			switch (Param.id) {
			case TV_TUNER_NXP_TDA18275A:
				REALTEK_I_ISDBT_INFO("Tuner id %d, TV_TUNER_NXP_TDA18275A\n", Param.id);
				pRealtekIISDB->m_AgcScale = 89;//89/128=0.7
				pRealtekIISDB->m_ext_gain_dis=RTK_DEMOD_XML_EXT_GAIN_EN;
				break;

			case TV_TUNER_SILICONLABS_SI2151:
			case TV_TUNER_SILICONLABS_SI2178B:
			case TV_TUNER_NO_TUNER:
				REALTEK_I_ISDBT_INFO("Tuner id %d, TV_TUNER_SILICONLABS_SI21XX\n", Param.id);
				pRealtekIISDB->m_AgcScale = 89;//89/128=0.7
				pRealtekIISDB->m_ext_gain_dis=RTK_DEMOD_XML_EXT_GAIN_DIS;
				rtd_outl(0xb8071004, 0x00010000);
				REALTEK_I_ISDBT_INFO("Fix IFAGC PIN at 0V !!!!!\n");
				break;
				
			case TV_TUNER_MAXLINEAR_MXL661:
				REALTEK_I_ISDBT_INFO("Tuner id %d, TV_TUNER_MAXLINEAR_MXL6x1\n", Param.id);
				pRealtekIISDB->m_AgcScale = 89;//89/128=0.7
				pRealtekIISDB->m_ext_gain_dis=RTK_DEMOD_XML_EXT_GAIN_EN;
				break;
				
			case TV_TUNER_RAFAEL_R840:
				REALTEK_I_ISDBT_INFO("Tuner id %d, TV_TUNER_RAFAEL_R840\n", Param.id);
				pRealtekIISDB->m_AgcScale = 89;//89/128=0.7
				pRealtekIISDB->m_ext_gain_dis=RTK_DEMOD_XML_EXT_GAIN_EN;
				break;

			default:
				REALTEK_I_ISDBT_WARNING("unkonw tuner id %d, using default setting\n", Param.id);
				pRealtekIISDB->m_AgcScale = 89;//89/128=0.7
				pRealtekIISDB->m_ext_gain_dis=RTK_DEMOD_XML_EXT_GAIN_EN;
				break;
			}

			pDemodKernel->m_if.freq      = Param.if_freq;
			pDemodKernel->m_if.inversion = Param.if_inversion;
			pDemodKernel->m_if.agc_pola  = Param.if_agc_pola;

		}
	}

	DtvPGAControl(PGAEnable, PGAGain);

	ClearDemodReset(RTK_DEMOD_MODE_ISDB);


	ret |= DECODE_RET(pDemod->SetXmlTunerGainCtrl(pDemod, pRealtekIISDB->m_AgcScale | (RTK_DEMOD_XML_EXT_GAIN1 << 16) | (pDemodKernel->m_if.agc_pola << 18)));
	ret |= DECODE_RET(pDemod->SetXmlFlags(pDemod, RTK_DEMOD_XML_REAL_IF | (pDemodKernel->m_if.inversion << 1) | (RTK_DEMOD_XML_UNSIGNED << 2)|(pRealtekIISDB->m_ext_gain_dis << 3)));
	ret |= DECODE_RET(pDemod->SetXmlIfFreq(pDemod, pDemodKernel->m_if.freq));
	ret |= DECODE_RET(pDemod->SetXmlTunerCfgOverride(pDemod, 0x00000001));

	ret |= DECODE_RET(pDemod->SetXmlIfClk(pDemod, 30000000));
	ret |= DECODE_RET(pDemod->SetXmlLdpcClk(pDemod, 540000000));
	ret |= DECODE_RET(pDemod->SetXmlUccClk(pDemod, 270000000));
	ret |= DECODE_RET(pDemod->SetXmlMcuClk(pDemod, 540000000));
	ret |= DECODE_RET(pDemod->SetXmlPlftCfgOverride(pDemod, 0x00000001));

	//Set Ber Cal Period to 1 Sec
	ret |= DECODE_RET(pDemod->SetRegBerPeriod(pDemod, 0x00000001));
 
	//For GI mosaic parameter
	g1stGI1_4 = 0;
	gIsResetDemod = 0;
	gMaxSegLayer = 0;
	pDemodKernel->Unlock(pDemodKernel);

	if (pDemodKernel->SetTSMode(pDemodKernel, &pDemodKernel->m_ts) != TUNER_CTRL_OK) {

		REALTEK_I_ISDBT_WARNING("MERLIN2_ISDBT Init set ts mode Failed\n");
		return TUNER_CTRL_FAIL;
	}

	REALTEK_I_ISDBT_INFO("MERLIN2_ISDBT Init Complete\n");
	return TUNER_CTRL_OK;

init_fail:

	REALTEK_I_ISDBT_WARNING("REALTEK_I_ISDBT Init Failed\n");
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
int REALTEK_I_ISDBT_SetTVSys(DEMOD* pDemodKernel, TV_SYSTEM sys)
{
	REALTEK_I_ISDB* pRealtekIISDB;
	pRealtekIISDB = (REALTEK_I_ISDB*)(pDemodKernel->private_data);

	return pDemodKernel->SetTVSysEx(pDemodKernel, sys, NULL);
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
int REALTEK_I_ISDBT_SetTVSysEx(DEMOD* pDemodKernel, TV_SYSTEM sys, const TV_SIG_INFO* pSigInfo)
{

	TUNER_PARAM Param;
	int ret = TUNER_CTRL_OK;
	CH_MODE ISDBTScanMode;
	unsigned int SpectrumInvert;
	unsigned int ReadValue = 0;

	REALTEK_I_ISDB* pRealtekIISDB;
	ISDBT_DEMOD_MODULE* pDemod;
	pRealtekIISDB = (REALTEK_I_ISDB*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_ISDBT_DRIVER_DATA*) pRealtekIISDB->m_private)->pDemod;


	if (!IsIsdbtSys(sys)) {
		REALTEK_I_ISDBT_WARNING("Set TV system failed, unsupported TV system\n");

		return TUNER_CTRL_FAIL;
	}

	pRealtekIISDB->m_auto_tune_enable = 0;
	PreGuardInterval = 0;
	IsGiChanged = 0;
	gIsResetDemod = 0;
	gMaxSegLayer = 0;

	if (!pSigInfo) {
		REALTEK_I_ISDBT_INFO("Siginfo doesn't specified in SetTVSysEx\n");
	}else{
        ISDBTScanMode = pSigInfo->isdbt.scan_mode ? CH_SCAN_MODE : CH_NORMAL_MODE;  
		REALTEK_I_ISDBT_INFO("pSigInfo->isdbt.scan_mode = %u\n", pSigInfo->isdbt.scan_mode);
          
		if(g1stGI1_4 == 1){
			ResetDemod(pDemodKernel);
			REALTEK_I_ISDBT_INFO("\033[1;32;31m""ResetDemod after GI 4/8/16 in SetDemod\n""\033[m");
			g1stGI1_4 = 0;
			gIsResetDemod = 1;
		}

	}

	//TUNER_PARAM Param;
	if (pDemodKernel->m_pTuner->GetParam(pDemodKernel->m_pTuner, sys, &Param) == TUNER_CTRL_OK) {
		if ((pDemodKernel->m_if.freq != Param.if_freq) || (pDemodKernel->m_if.inversion != Param.if_inversion) || (pDemodKernel->m_if.agc_pola  != Param.if_agc_pola)) {
			pDemodKernel->m_if.freq = Param.if_freq;
			pDemodKernel->m_if.inversion = Param.if_inversion;
			pDemodKernel->m_if.agc_pola = Param.if_agc_pola;
			if (pDemodKernel->SetIF(pDemodKernel, &pDemodKernel->m_if) != TUNER_CTRL_OK)  return  TUNER_CTRL_FAIL;
		}
	}

	if (ISDBTScanMode == CH_NORMAL_MODE)
		SpectrumInvert = (pSigInfo->isdbt.bSpectrumInv == 1) ? (!pDemodKernel->m_if.inversion) : pDemodKernel->m_if.inversion;
	else
		SpectrumInvert = pDemodKernel->m_if.inversion;



	//Set Demod for Avoiding Any Problems
	switch (sys) {
	case TV_SYS_ISDBT_8M:
		pRealtekIISDB->m_current_bw = 8000000;
		break;
	case TV_SYS_ISDBT_6M:
	default:
		pRealtekIISDB->m_current_bw = 6000000;
		break;
	}

	ret |= DECODE_RET(pDemod->DemodCtrlStop(pDemod));
	ret |= DECODE_RET(pDemod->SetTunerBandwidth(pDemod, pRealtekIISDB->m_current_bw));
	ret |= DECODE_RET(pDemod->SetTunerFreq(pDemod, 666000000));//Set Frequency and Bandwidth together
	ret |= DECODE_RET(pDemod->DemodCtrlDetect(pDemod));
	ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_DEMOD_LOCK_TIMEOUT, SET_TV_REG_DEMOD_LOCK_TIMEOUT_VALUE));
	ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_DEMOD_LOCK_TIMEOUT, &ReadValue));
	REALTEK_I_ISDBT_INFO("TV_REG_DEMOD_LOCK_TIMEOUTsetting = %d\n", ReadValue);

	pDemodKernel->m_tv_sys = sys;
	pRealtekIISDB->m_SigInfo.mod = TV_MODULATION_ISDBT;
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
int REALTEK_I_ISDBT_SetIF(DEMOD* pDemodKernel, IF_PARAM* pParam)
{
	int ret = TUNER_CTRL_OK;

	REALTEK_I_ISDB* pRealtekIISDB;
	ISDBT_DEMOD_MODULE* pDemod;
	pRealtekIISDB = (REALTEK_I_ISDB*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_ISDBT_DRIVER_DATA*) pRealtekIISDB->m_private)->pDemod;

	pDemodKernel->Lock(pDemodKernel);

	REALTEK_I_ISDBT_INFO("SetIF, IF_freq = %lu, spectrumn inv = %u, agc_pola = %u\n", pParam->freq, pParam->inversion, pParam->agc_pola);

	ret |= DECODE_RET(pDemod->SetXmlTunerGainCtrl(pDemod, pRealtekIISDB->m_AgcScale | (RTK_DEMOD_XML_EXT_GAIN1 << 16) | (pParam->agc_pola << 18)));
	ret |= DECODE_RET(pDemod->SetXmlFlags(pDemod, RTK_DEMOD_XML_REAL_IF | (pParam->inversion << 1) | (RTK_DEMOD_XML_UNSIGNED << 2) | (pRealtekIISDB->m_ext_gain_dis << 3)));
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
int REALTEK_I_ISDBT_SetMode(DEMOD* pDemodKernel, TV_OP_MODE mode)
{
	REALTEK_I_ISDB* pRealtekIISDB;
	pRealtekIISDB = (REALTEK_I_ISDB*)(pDemodKernel->private_data);

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
int REALTEK_I_ISDBT_SetTSMode(DEMOD* pDemodKernel, TS_PARAM* pParam)
{
	unsigned char TsOutEn, TsSerial, ClkPhase;
	int ret = TUNER_CTRL_OK;

	REALTEK_I_ISDB* pRealtekIISDB;
	ISDBT_DEMOD_MODULE* pDemod;
	pRealtekIISDB = (REALTEK_I_ISDB*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_ISDBT_DRIVER_DATA*) pRealtekIISDB->m_private)->pDemod;

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
int REALTEK_I_ISDBT_GetLockStatus(DEMOD* pDemodKernel, unsigned char* pLock)
{
	unsigned int DemodStatus;
	int ret = TUNER_CTRL_OK;

	REALTEK_I_ISDB* pRealtekIISDB;
	ISDBT_DEMOD_MODULE* pDemod;
	pRealtekIISDB = (REALTEK_I_ISDB*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_ISDBT_DRIVER_DATA*) pRealtekIISDB->m_private)->pDemod;

	pDemodKernel->Lock(pDemodKernel);

	ret |= DECODE_RET(pDemod->GetDemodStatus(pDemod, &DemodStatus));

    if( (DemodStatus < 0) || (DemodStatus > 5) )
    {
        REALTEK_I_ISDBT_INFO("DemodStatus = %d, Demod will reset and re-init!!!\n", DemodStatus);
        ResetDemod(pDemodKernel);
        *pLock = 1;

        pDemodKernel->Unlock(pDemodKernel);
        
        return TUNER_CTRL_OK;
    }

	if (DemodStatus == 5)
		*pLock = 1;
	else
		*pLock = 0;


	pDemodKernel->Unlock(pDemodKernel);

	return ret;
}

int REALTEK_I_ISDBT_GetSegmentNum(DEMOD* pDemodKernel, int layerIndex, unsigned char* pNum)
{
	REALTEK_I_ISDB* pRealtekIISDB;
	ISDBT_DEMOD_MODULE* pDemod;
	pRealtekIISDB = (REALTEK_I_ISDB*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_ISDBT_DRIVER_DATA*) pRealtekIISDB->m_private)->pDemod;

	pDemodKernel->Lock(pDemodKernel);


	pDemodKernel->Unlock(pDemodKernel);

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
int REALTEK_I_ISDBT_GetSignalInfo(DEMOD* pDemodKernel, TV_SIG_INFO* pInfo)
{
	unsigned int layer_constel, layer_code_rate, layer_time_intlv, layer_segments;
	unsigned int guard_interval, trans_mode, subchanel;

	REALTEK_I_ISDB* pRealtekIISDB;
	ISDBT_DEMOD_MODULE* pDemod;
	pRealtekIISDB = (REALTEK_I_ISDB*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_ISDBT_DRIVER_DATA*) pRealtekIISDB->m_private)->pDemod;


	if (!DtvIsDemodClockEnable(RTK_DEMOD_MODE_ISDB))
		return TUNER_CTRL_FAIL;

	pDemodKernel->Lock(pDemodKernel);
	pRealtekIISDB->m_auto_tune_enable = 1;
	gMaxSegLayer = 0;
	
	pDemod->DemodCtrlUpdateCounters(pDemod);
	//pDemod->SetTunCtrlCmd(pDemod, 1);        //update TMCC info
	pDemod->GetTunSubCh(pDemod, &subchanel);
	pDemod->GetTunMode(pDemod, &trans_mode);
	pDemod->GetTunGuard(pDemod, &guard_interval);



	pInfo->isdbt.subchannel_num = subchanel;

	pInfo->mod = TV_MODULATION_ISDBT;

	switch (trans_mode) {
	case ISDBT_FFT_MODE_2K:
		pInfo->isdbt.trans_mode  = OFDM_FFT_2K;
		break;
	case ISDBT_FFT_MODE_4K:
		pInfo->isdbt.trans_mode  = OFDM_FFT_4K;
		break;
	case ISDBT_FFT_MODE_8K:
		pInfo->isdbt.trans_mode  = OFDM_FFT_8K;
		break;
	}


	switch (guard_interval) {
	case ISDBT_GUARD_INTERVAL_1_OVER_32:
		pInfo->isdbt.guard_interval  = OFDM_GI_1_32;
		break;
	case ISDBT_GUARD_INTERVAL_1_OVER_16:
		pInfo->isdbt.guard_interval  = OFDM_GI_1_16;
		break;
	case ISDBT_GUARD_INTERVAL_1_OVER_8:
		pInfo->isdbt.guard_interval  = OFDM_GI_1_8;
		break;
	case ISDBT_GUARD_INTERVAL_1_OVER_4:
		pInfo->isdbt.guard_interval  = OFDM_GI_1_4;
		break;
	}
    REALTEK_I_ISDBT_INFO("\033[1;32;31m""GuardInterval %d\n""\033[m", pInfo->isdbt.guard_interval);


	//Layer A

	pDemod->GetTunModeA(pDemod, &layer_constel);
	pDemod->GetTunCodeRateA(pDemod, &layer_code_rate);
	pDemod->GetTunInterleaverA(pDemod, &layer_time_intlv);
	pDemod->GetTunSegsA(pDemod, &layer_segments);

	pInfo->isdbt.layer[ISDBT_HIERARCHICAL_LAYER_A].segment_num = layer_segments;
	pInfo->isdbt.layer[ISDBT_HIERARCHICAL_LAYER_A].constellation = IMGConstel2Rtk(layer_constel);
	pInfo->isdbt.layer[ISDBT_HIERARCHICAL_LAYER_A].code_rate = IMGCoderate2Rtk(layer_code_rate);
	pInfo->isdbt.layer[ISDBT_HIERARCHICAL_LAYER_A].time_intlv =  IMGTimeintlv2Rtk(layer_time_intlv);
	REALTEK_I_ISDBT_INFO("[Layer A]Seg %d, Constellation %d, Code Rate 0x%X\n", pInfo->isdbt.layer[ISDBT_HIERARCHICAL_LAYER_A].segment_num, pInfo->isdbt.layer[ISDBT_HIERARCHICAL_LAYER_A].constellation, pInfo->isdbt.layer[ISDBT_HIERARCHICAL_LAYER_A].code_rate);

	//Layer B
	pDemod->GetTunModeB(pDemod, &layer_constel);
	pDemod->GetTunCodeRateB(pDemod, &layer_code_rate);
	pDemod->GetTunInterleaverB(pDemod, &layer_time_intlv);
	pDemod->GetTunSegsB(pDemod, &layer_segments);

	pInfo->isdbt.layer[ISDBT_HIERARCHICAL_LAYER_B].segment_num = layer_segments;
	pInfo->isdbt.layer[ISDBT_HIERARCHICAL_LAYER_B].constellation = IMGConstel2Rtk(layer_constel);
	pInfo->isdbt.layer[ISDBT_HIERARCHICAL_LAYER_B].code_rate = IMGCoderate2Rtk(layer_code_rate);
	pInfo->isdbt.layer[ISDBT_HIERARCHICAL_LAYER_B].time_intlv =  IMGTimeintlv2Rtk(layer_time_intlv);
	REALTEK_I_ISDBT_INFO("[Layer B]Seg %d, Constellation %d, Code Rate 0x%X\n", pInfo->isdbt.layer[ISDBT_HIERARCHICAL_LAYER_B].segment_num, pInfo->isdbt.layer[ISDBT_HIERARCHICAL_LAYER_B].constellation, pInfo->isdbt.layer[ISDBT_HIERARCHICAL_LAYER_B].code_rate);
	if(pInfo->isdbt.layer[ISDBT_HIERARCHICAL_LAYER_B].segment_num > pInfo->isdbt.layer[ISDBT_HIERARCHICAL_LAYER_A].segment_num)
		gMaxSegLayer = 1;
	//Layer C
	pDemod->GetTunModeC(pDemod, &layer_constel);
	pDemod->GetTunCodeRateC(pDemod, &layer_code_rate);
	pDemod->GetTunInterleaverC(pDemod, &layer_time_intlv);
	pDemod->GetTunSegsC(pDemod, &layer_segments);

	pInfo->isdbt.layer[ISDBT_HIERARCHICAL_LAYER_C].segment_num = layer_segments;
	pInfo->isdbt.layer[ISDBT_HIERARCHICAL_LAYER_C].constellation = IMGConstel2Rtk(layer_constel);
	pInfo->isdbt.layer[ISDBT_HIERARCHICAL_LAYER_C].code_rate = IMGCoderate2Rtk(layer_code_rate);
	pInfo->isdbt.layer[ISDBT_HIERARCHICAL_LAYER_C].time_intlv =  IMGTimeintlv2Rtk(layer_time_intlv);
	REALTEK_I_ISDBT_INFO("[Layer C]Seg %d, Constellation %d, Code Rate 0x%X\n", pInfo->isdbt.layer[ISDBT_HIERARCHICAL_LAYER_C].segment_num, pInfo->isdbt.layer[ISDBT_HIERARCHICAL_LAYER_C].constellation, pInfo->isdbt.layer[ISDBT_HIERARCHICAL_LAYER_C].code_rate);
	if(gMaxSegLayer == 0){
		if(pInfo->isdbt.layer[ISDBT_HIERARCHICAL_LAYER_C].segment_num > pInfo->isdbt.layer[ISDBT_HIERARCHICAL_LAYER_A].segment_num){
			gMaxSegLayer = 2;
		}
	}else{
		if(pInfo->isdbt.layer[ISDBT_HIERARCHICAL_LAYER_C].segment_num > pInfo->isdbt.layer[ISDBT_HIERARCHICAL_LAYER_B].segment_num){
			gMaxSegLayer = 2;
		}
	}

	if( pInfo->isdbt.guard_interval  != OFDM_GI_1_32){
		g1stGI1_4 = 1;
	}
	pDemodKernel->Unlock(pDemodKernel);

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
int REALTEK_I_ISDBT_GetSignalQuality(DEMOD* pDemodKernel, ENUM_TV_QUAL id, TV_SIG_QUAL* pQuality)
{
	unsigned int Snr, Ssi, Sqi, RegEaf, PakN, BadPakN, ErrBit, Agc;
	int ret = TUNER_CTRL_OK;

	REALTEK_I_ISDB* pRealtekIISDB;
	ISDBT_DEMOD_MODULE* pDemod;
	pRealtekIISDB = (REALTEK_I_ISDB*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_ISDBT_DRIVER_DATA*) pRealtekIISDB->m_private)->pDemod;

	pDemodKernel->Lock(pDemodKernel);


	ret |= DECODE_RET(pDemod->DemodCtrlUpdateCounters(pDemod));
	//ret |= DECODE_RET(pDemod->SetRegStatCtrlBCmd(pDemod, 0x00000004));//Update Layer B status
	//ret |= DECODE_RET(pDemod->SetRegStatCtrlCCmd(pDemod, 0x00000004));//Update Layer C status

	switch (id) {
	case TV_QUAL_SNR:
		ret |= DECODE_RET(pDemod->GetRegStatSnr(pDemod, &Snr));
		ret |= pDemod->DemodCtrlResetCounters(pDemod);
		pQuality->snr = (Snr * 10000) / 10;
		break;

	case TV_QUAL_BER:
		ret |= pDemod->GetRegStatTsPktCountA(pDemod, &PakN);
		ret |= pDemod->GetRegStatTsBadPktCountA(pDemod, &BadPakN);
		ret |= pDemod->GetRegStatTsBitErrsA(pDemod, &ErrBit);

		if (PakN > 0)
			pQuality->ber = ((BadPakN * 36 + ErrBit) * 10000)  / (PakN * 204 * 8);
		else
			pQuality->ber = 1;

		break;

	case TV_QUAL_BEC:
		ret |= pDemod->GetRegStatTsPktCountA(pDemod, &PakN);
		ret |= pDemod->GetRegStatTsBadPktCountA(pDemod, &BadPakN);
		ret |= pDemod->GetRegStatTsBitErrsA(pDemod, &ErrBit);

		if (PakN > 0) {
			pQuality->layer_ber.ber_num = BadPakN * 36 + ErrBit;
			pQuality->layer_ber.ber_den = (PakN * 204 * 8);
		}  else  {

			pQuality->layer_ber.ber_num = 0xffffffff;
			pQuality->layer_ber.ber_den = 0xffffffff;
		}

		break;

	case TV_QUAL_PER:
		ret |= pDemod->GetRegStatTsPktCountA(pDemod, &PakN);
		ret |= pDemod->GetRegStatTsBadPktCountA(pDemod, &BadPakN);

		if (PakN > 0)
			pQuality->per = ((BadPakN * 10000) / PakN);
		else
			pQuality->per = 1;
		break;


	case TV_QUAL_PEC:
		ret |= pDemod->GetRegStatTsPktCountA(pDemod, &PakN);
		ret |= pDemod->GetRegStatTsBadPktCountA(pDemod, &BadPakN);

		if (PakN > 0) {
			pQuality->layer_per.per_num = BadPakN;
			pQuality->layer_per.per_den = PakN;
		} else  {

			pQuality->layer_per.per_num = 0xffffffff;
			pQuality->layer_per.per_den = 0xffffffff;
		}

		break;

	case TV_QUAL_UCBLOCKS:
		ret |= pDemod->GetRegStatTsPktCountA(pDemod, &PakN);
		ret |= pDemod->GetRegStatTsBadPktCountA(pDemod, &BadPakN);

		if (PakN > 0)
			pQuality->ucblocks = BadPakN;
		else

			pQuality->ucblocks = 0xffffffff;

		break;

	case TV_QUAL_SIGNAL_STRENGTH:
		pQuality->strength = (unsigned char)REALTEK_I_ISDBT_CalSsi(pDemodKernel, (int)pQuality->rflevel);
		break;
	case TV_QUAL_SIGNAL_QUALITY:
		ret |= DECODE_RET(pDemod->GetRegStatSnr(pDemod, &Snr));
		REALTEK_I_ISDBT_INFO("\033[1;32;31m  SNR = %lu  \n" ,Snr);
		//Snr = (Snr * 10000) / 10;
		pQuality->quality = Snr / 3;
		if (pQuality->quality > 100)
			pQuality->quality = 100;
		break;
	case TV_QUAL_AGC:
		Agc = (rtd_inl(DEMOD_SD_SIGMA_DELTA_INPUT_reg) >> 12) & 0x7ff;
		Agc =  Agc * 100 / 0x7ff;
		pQuality->agc = Agc;
		break;
	case TV_QUAL_DEMODFWVERSION:
		pQuality->DemodFwVersion = 0x000001;
		break;
	case TV_QUAL_EMERGENCY_FLAG:
		ret |= DECODE_RET(pDemod->GetRegEaf(pDemod, &RegEaf));
		pQuality->emergency_flag = (RegEaf & 0x3) >> 1;
		break;

        case TV_QUAL_CUSTOMER_LG:

			ret |= pDemod->GetRegStatTsPktCountA(pDemod, &PakN);
		       ret |= pDemod->GetRegStatTsBadPktCountA(pDemod, &BadPakN);
		       ret |= pDemod->GetRegStatTsBitErrsA(pDemod, &ErrBit);
			ret |= DECODE_RET(pDemod->GetRegStatSnr(pDemod, &Snr));
		       ret |= pDemod->DemodCtrlResetCounters(pDemod);

			pQuality->snr = (Snr * 10000) / 10;
			pQuality->strength = 0;
			pQuality->quality = 0;
			

		if (PakN > 0) {
			pQuality->layer_ber.ber_num = BadPakN * 36 + ErrBit;
			pQuality->layer_ber.ber_den = (PakN * 204 * 8);
			pQuality->layer_per.per_num = BadPakN;
			pQuality->layer_per.per_den = PakN;
		}  else  {
			pQuality->layer_ber.ber_num = 0xffffffff;
			pQuality->layer_ber.ber_den = 0xffffffff;
			pQuality->layer_per.per_num = 0xffffffff;
			pQuality->layer_per.per_den = 0xffffffff;
		}

		Agc = (rtd_inl(DEMOD_SD_SIGMA_DELTA_INPUT_reg) >> 12) & 0x7ff;
		Agc =  Agc * 100 / 0x7ff;
		pQuality->agc = Agc;
		REALTEK_I_ISDBT_INFO("\033[1;32;31m" "SNR = %lu, AGC=%lu, pkt_error=%lu, total_pkt = %lu\n" "\033[m", pQuality->snr, pQuality->agc, pQuality->layer_per.per_num, pQuality->layer_per.per_den);
		break;

	default:
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
int REALTEK_I_ISDBT_GetCarrierOffset(DEMOD * pDemodKernel, long * pOffset)
{
	int ret = TUNER_CTRL_OK;
	unsigned int Cfo = 0;

	REALTEK_I_ISDB* pRealtekIISDB;
	ISDBT_DEMOD_MODULE* pDemod;
	pRealtekIISDB = (REALTEK_I_ISDB*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_ISDBT_DRIVER_DATA*) pRealtekIISDB->m_private)->pDemod;

	if (!DtvIsDemodClockEnable(RTK_DEMOD_MODE_ISDB))
		return TUNER_CTRL_FAIL;

	pDemodKernel->Lock(pDemodKernel);

	ret |= pDemod->GetRegStatCarrierAcquisitionOffset(pDemod, &Cfo);
	*pOffset = Cfo;

	pDemodKernel->Unlock(pDemodKernel);
	REALTEK_I_ISDBT_INFO("GetCarrierOffset=%ldHz\n", *pOffset);

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
int REALTEK_I_ISDBT_GetDebugLogBuf(DEMOD* pDemodKernel, unsigned int* LogBufAddr, unsigned int* LogBufSize)
{
	int ret = TUNER_CTRL_OK;
#if 0
	REALTEK_I_ISDBT* pRealtekIISDBT;
	ISDBT_DEMOD_MODULE* pDemod;
	pRealtekIISDBT = (REALTEK_I_ISDBT*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_ISDBT_DRIVER_DATA*) pRealtekIISDBT->m_private)->pDemod;
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
#endif
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
int REALTEK_I_ISDBT_AcquireSignal(DEMOD * pDemodKernel, unsigned char WaitSignalLock)
{
	unsigned long   stime;
	unsigned char	lock;
	unsigned int	DemodStatus, AcqTime;

	unsigned int IsdbtWaitLockTimeout =6000;   
	unsigned int FailureCountPerTimeout = 0, FailureCountOther = 0;
	unsigned int IsdbtWaitTmccGoodTimeout = 900;
	unsigned int TmccGoodDecodeCount = 0;
	unsigned char TmccGood = 0;
	int ret = TUNER_CTRL_OK;

	REALTEK_I_ISDB* pRealtekIISDB;
	ISDBT_DEMOD_MODULE* pDemod;
	pRealtekIISDB = (REALTEK_I_ISDB*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_ISDBT_DRIVER_DATA*) pRealtekIISDB->m_private)->pDemod;
	TV_SIG_INFO* pInfo = (TV_SIG_INFO*)kmalloc(sizeof(TV_SIG_INFO), GFP_KERNEL);


	REALTEK_I_ISDBT_DBG("\033[1;32;31m" "%s %s %d\n" "\033[m", __FILE__, __func__, __LINE__);
	REALTEK_I_ISDBT_INFO("WaitSignalLock = %d\n", WaitSignalLock);

	pRealtekIISDB->m_auto_tune_enable = 0;
	AcqTime = 0;

	if (pDemod == NULL) {
		REALTEK_I_ISDBT_INFO("pDemod is NULL\n");
		kfree(pInfo);
		return TUNER_CTRL_FAIL;
	}

	pDemodKernel->Lock(pDemodKernel);

	if (0) {//if (!WaitSignalLock) {
		pDemodKernel->Unlock(pDemodKernel);
		pRealtekIISDB->m_auto_tune_enable = 1;
		pRealtekIISDB->m_PreUbc = 0;
		kfree(pInfo);
		return TUNER_CTRL_OK;
	}
    IsdbtWaitLockTimeout = WaitSignalLock ? 6000 : 3000;

	stime = tv_osal_time();
	lock = NO;

	while ((tv_osal_time() - stime) <= IsdbtWaitTmccGoodTimeout)
	{
		ret |= DECODE_RET(pDemod->GetRegTmccGoodDecodeCount(pDemod, &TmccGoodDecodeCount));
		if (TmccGoodDecodeCount > 0){
			TmccGood = YES;
			REALTEK_I_ISDBT_INFO("TMCC > 0!! TmccGoodDecodeCount = %d\n", TmccGoodDecodeCount);
			break;
		}

		tv_osal_msleep(5);
	}
	if (TmccGood != YES){
		REALTEK_I_ISDBT_INFO("TMCC_TIMEOUT!! TmccGoodDecodeCount = %d\n", TmccGoodDecodeCount);
		goto ret_acquire_result;
	}
    
	while ((tv_osal_time() - stime) <= IsdbtWaitLockTimeout) {
		tv_osal_msleep(5);

		ret |= DECODE_RET(pDemod->GetDemodStatus(pDemod, &DemodStatus));
        ret |= DECODE_RET(pDemod->GetRegDemodFailureCountPerTimeout(pDemod, &FailureCountPerTimeout));
		ret |= DECODE_RET(pDemod->GetRegDemodFailureCountOther(pDemod, &FailureCountOther));

		if (DemodStatus == 5) {
			lock = YES;
			pRealtekIISDB->m_auto_tune_enable = 1;
			pRealtekIISDB->m_PreUbc = 0;
			ret |= DECODE_RET(pDemod->GetDemodLockTime(pDemod, &AcqTime));
			AcqTime /= 1000;
			REALTEK_I_ISDBT_INFO("\033[1;32;31m" "ISDBT Signal Lock!!!\n" "\033[m");
			autotune_stime = tv_osal_time();
			REALTEK_I_ISDBT_GetSignalInfo(pDemodKernel, pInfo);
			break;
		}
		tv_osal_msleep(5);
		REALTEK_I_ISDBT_INFO("signal lock = %u, demod state = %d, FailureCountPerTimeout = %u, FailureCountOther = %u, driver time = %lu, HW time = %u\n", lock, DemodStatus, FailureCountPerTimeout,  FailureCountOther, (tv_osal_time() - stime), AcqTime);
        
	}
ret_acquire_result:
	REALTEK_I_ISDBT_INFO("signal lock = %u, demod state = %d, FailureCountPerTimeout = %u, FailureCountOther = %u, driver time = %lu, HW time = %u\n", lock, DemodStatus, FailureCountPerTimeout,  FailureCountOther, (tv_osal_time() - stime), AcqTime);
	pDemodKernel->Unlock(pDemodKernel);
	kfree(pInfo);
	return (lock) ? TUNER_CTRL_OK : TUNER_CTRL_NO_SIGNAL;

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
int REALTEK_I_ISDBT_ScanSignal(DEMOD * pDemodKernel, long * pOffset, SCAN_RANGE range)
{

	REALTEK_I_ISDB* pRealtekIISDB;
	ISDBT_DEMOD_MODULE* pDemod;
	pRealtekIISDB = (REALTEK_I_ISDB*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_ISDBT_DRIVER_DATA*) pRealtekIISDB->m_private)->pDemod;


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
int REALTEK_I_ISDBT_ForwardI2C(DEMOD * pDemodKernel, unsigned char on_off)
{
	int ret = TUNER_CTRL_OK;

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
int REALTEK_I_ISDBT_AutoTune(DEMOD * pDemodKernel)
{
	unsigned int DemodStatus;
	int ret = TUNER_CTRL_OK;
	unsigned int Per = 0;
	static unsigned char ContinuousMosaicCnt = 0;

	REALTEK_I_ISDB* pRealtekIISDB;
	ISDBT_DEMOD_MODULE* pDemod;
	pRealtekIISDB = (REALTEK_I_ISDB*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_ISDBT_DRIVER_DATA*) pRealtekIISDB->m_private)->pDemod;
    TV_SIG_INFO* pInfo = (TV_SIG_INFO*)kmalloc(sizeof(TV_SIG_INFO), GFP_KERNEL);
	
	if(pRealtekIISDB->m_auto_tune_enable){
		if((tv_osal_time() - autotune_stime) >= 1000){			pDemodKernel->Lock(pDemodKernel);
			autotune_stime = tv_osal_time();
			ret |= DECODE_RET(pDemod->GetDemodStatus(pDemod, &DemodStatus));

			if( (DemodStatus < 0) || (DemodStatus > 5) ){
		        REALTEK_I_ISDBT_INFO("DemodStatus = %d, Demod will reset and re-init!!!\n", DemodStatus);
		        ResetDemod(pDemodKernel);
				pRealtekIISDB->m_auto_tune_enable = 1;
		        REALTEK_I_ISDBT_GetSignalInfo(pDemodKernel, pInfo);
		        kfree(pInfo);
		        pDemodKernel->Unlock(pDemodKernel);
		        
		        return TUNER_CTRL_OK;
		    }

			if (DemodStatus == 5){
		        REALTEK_I_ISDBT_GetSignalInfo(pDemodKernel, pInfo);
				ret |= DECODE_RET(pDemod->DemodCtrlUpdateCounters(pDemod));
				if(gMaxSegLayer == 0){
				ret |= DECODE_RET(pDemod->GetRegBerTsPerA(pDemod, &Per));				
				}else if(gMaxSegLayer == 1){
					ret |= DECODE_RET(pDemod->GetRegBerTsPerB(pDemod, &Per));
				}else{
					ret |= DECODE_RET(pDemod->GetRegBerTsPerC(pDemod, &Per));
				}
				REALTEK_I_ISDBT_INFO("Layer%d, Per = %u\n", gMaxSegLayer, Per);

				if( (pInfo->isdbt.guard_interval != PreGuardInterval) && (pInfo->isdbt.guard_interval > PreGuardInterval) )
				{	
					if(PreGuardInterval != 0) {
						IsGiChanged = 1;
					}
				}
				REALTEK_I_ISDBT_INFO("PreGi =%d, GI = %d, Per = %u, IsGiChanged =%d\n", PreGuardInterval, pInfo->isdbt.guard_interval, Per, IsGiChanged);
				if(IsGiChanged) {
					if(Per >= 0x07000000)
						ContinuousMosaicCnt++;
					else
						ContinuousMosaicCnt = 0;

					if( ContinuousMosaicCnt > CONTINUOUS_MOSAIC_CNT_THD )
					{
						ResetDemod(pDemodKernel);
						pRealtekIISDB->m_auto_tune_enable = 1;
						IsGiChanged = 0;
						ContinuousMosaicCnt = 0;
						REALTEK_I_ISDBT_INFO("\033[1;32;31m""ResetDemod by changing GI then mosaic\n""\033[m");
					}
				}
				PreGuardInterval = pInfo->isdbt.guard_interval;
			}

			pDemodKernel->Unlock(pDemodKernel);
		}
	}
    kfree(pInfo); //put here, avoid ISDB DTV kernel halt/crash

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
int REALTEK_I_ISDBT_InspectSignal(DEMOD * pDemodKernel)
{
	unsigned int DemodStatus, lock, Snr, Ber, Per, Ubc;
	float SnrResult, BerResult, PerResult;
	int ret = TUNER_CTRL_OK;

	REALTEK_I_ISDB* pRealtekIISDB;
	ISDBT_DEMOD_MODULE* pDemod;
	pRealtekIISDB = (REALTEK_I_ISDB*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_ISDBT_DRIVER_DATA*) pRealtekIISDB->m_private)->pDemod;

	if (DtvIsDemodClockEnable(RTK_DEMOD_MODE_ISDB) == 0)
		return 0;

	DtvDumpShareRegStatus();

	pDemodKernel->Lock(pDemodKernel);

	ret |= DECODE_RET(pDemod->DemodCtrlUpdateCounters(pDemod));
	//ret |= DECODE_RET(pDemod->SetRegStatCtrlACmd(pDemod, 0x00000004));//Update Layer A status
	//ret |= DECODE_RET(pDemod->SetRegStatCtrlB(pDemod, 0x00000004));//Update Layer B status
	//ret |= DECODE_RET(pDemod->SetRegStatCtrlC(pDemod, 0x00000004));//Update Layer C status

	ret |= DECODE_RET(pDemod->GetDemodStatus(pDemod, &DemodStatus));

	if (DemodStatus == 5)
		lock = 1;
	else
		lock = 0;

	ret |= DECODE_RET(pDemod->GetRegStatSnr(pDemod, &Snr));
	SnrResult = ((double)Snr) / 10;

	ret |= DECODE_RET(pDemod->GetRegBerRsBerA(pDemod, &Ber));
	BerResult = ((double)Ber) / 1000000;

	ret |= DECODE_RET(pDemod->GetRegBerTsPerA(pDemod, &Per));
	PerResult = ((double)Per) / 1000000;

	ret |= DECODE_RET(pDemod->GetRegStatTsBadPktCountA(pDemod, &Ubc));

	pDemodKernel->Unlock(pDemodKernel);

#if 0
	ret = snprintf(pBuff, BufferSize, "[REALTEK_I_ISDBT] lock=%u, snr=%f, error_rate(Ber/Per)=%f/%f, ts_bad_pkt_cnt=%u\n",
				   lock, (double)SnrResult,
				   (double)BerResult, (double)PerResult, Ubc);
#endif
	ret = 1;

#ifdef REALTEK_I_DUMP_SHARE_REG
	DtvDumpShareRegStatus();
#endif

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
int REALTEK_I_ISDBT_Activate(DEMOD * pDemodKernel, unsigned char force_rst)
{
	REALTEK_I_ISDB* pRealtekIISDB;
	ISDBT_DEMOD_MODULE* pDemod;
	pRealtekIISDB = (REALTEK_I_ISDB*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_ISDBT_DRIVER_DATA*) pRealtekIISDB->m_private)->pDemod;

	pDemodKernel->Lock(pDemodKernel);

	/*
		if (pDemod->Init(pDemod) != FUNCTION_SUCCESS)
				goto activate_demod_fail;

			ClearDemodReset(RTK_DEMOD_MODE_ISDB);

			if (pDemodKernel->SetIF(pDemodKernel, &pDemodKernel->m_if) != TUNER_CTRL_OK)
				goto activate_demod_fail;

			if (pDemodKernel->SetTSMode(pDemodKernel, &pDemodKernel->m_ts) != TUNER_CTRL_OK)
				goto activate_demod_fail;

			if (pDemodKernel->SetTVSysEx(pDemodKernel, pDemodKernel->m_tv_sys, &pRealtekIISDB->m_SigInfo) != TUNER_CTRL_OK)
				goto activate_demod_fail;
	*/
	pDemodKernel->Unlock(pDemodKernel);

	return TUNER_CTRL_OK;

//--------------------------
/*
activate_demod_fail:
	pDemodKernel->Unlock(pDemodKernel);
	return TUNER_CTRL_FAIL;
*/
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
int REALTEK_I_ISDBT_SetTvMode(DEMOD * pDemodKernel, TV_SYSTEM_TYPE mode)
{
	int ret = TUNER_CTRL_FAIL;
	REALTEK_I_ISDB* pRealtekIISDB;
	pRealtekIISDB = (REALTEK_I_ISDB*)(pDemodKernel->private_data);

	pDemodKernel->Lock(pDemodKernel);

	RTK_DEMOD_INFO("REALTEK_I_ISDBT::SetTvMode(%d)\n", mode);

	switch (mode) {

	case TV_SYS_TYPE_ISDBT:
		RTK_DEMOD_INFO("Set to ISDBT\n");
		ret  = pDemodKernel->Init(pDemodKernel);
		ret |= pDemodKernel->SetTSMode(pDemodKernel, &pDemodKernel->m_ts);
		if (ret != TUNER_CTRL_OK) {
			RTK_DEMOD_WARNING("Set REALTEK_I_ISDBT to ISDBT mode failed\n");
			goto set_demod_mode_failed;
		}

		break;

	default:
		goto set_demod_mode_failed;
	}

	ret = TUNER_CTRL_OK;
	RTK_DEMOD_INFO("Set REALTEK_I_ISDBT to appointed DTV mode successed\n");


//end_proc:

	pDemodKernel->Unlock(pDemodKernel);
	return ret;

//--------------
set_demod_mode_failed:
	pDemodKernel->Unlock(pDemodKernel);
	return TUNER_CTRL_FAIL;
}

void REALTEK_I_ISDBT_Lock(DEMOD * pDemodKernel)
{
	//FUNCTION_NAME_PRINT("LOCK 0x%x\n",&pDemodKernel->m_lock);
	//mutex_lock(&pDemodKernel->m_lock);
}

void REALTEK_I_ISDBT_Unlock(DEMOD * pDemodKernel)
{
	//FUNCTION_NAME_PRINT("UN_LOCK 0x%x\n",&pDemodKernel->m_lock);
	//mutex_unlock(&pDemodKernel->m_lock);
}


/*-----------------------------------------------------------------
 *     BASE_INTERFACE for REALTEK_I_ISDBT API
 *----------------------------------------------------------------*/


void ReleaseRealtekIDriver(REALTEK_I_ISDBT_DRIVER_DATA * pDriver)
{

	kfree(pDriver);
}


REALTEK_I_ISDBT_DRIVER_DATA* AllocRealtekIDriver_ISDBT(COMM * pComm,	unsigned char Addr,	unsigned long CrystalFreq, int TSMode)
{
	REALTEK_I_ISDBT_DRIVER_DATA* pDriver = (REALTEK_I_ISDBT_DRIVER_DATA*) kmalloc(
			sizeof(REALTEK_I_ISDBT_DRIVER_DATA) +
			sizeof(ISDBT_DEMOD_MODULE)   +
			sizeof(I2C_BRIDGE_MODULE)   +
			sizeof(BASE_INTERFACE_MODULE), GFP_KERNEL);

	if (pDriver) {
		BASE_INTERFACE_MODULE* pBIF;
		ISDBT_DEMOD_MODULE* pDemod;
		memset(pDriver, 0, sizeof(REALTEK_I_ISDBT_DRIVER_DATA));

		pDriver->pDemod                = (ISDBT_DEMOD_MODULE*)(((unsigned char*)pDriver) + sizeof(REALTEK_I_ISDBT_DRIVER_DATA));
		pDriver->pBaseInterface        = (BASE_INTERFACE_MODULE*)(((unsigned char*)pDriver->pDemod) + sizeof(ISDBT_DEMOD_MODULE));
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


		// Init Demod Driver		// Init Demod Driver
		BuildRealtekIIsdbtModule(&pDemod,	pDriver->pDemod,
								pDriver->pBaseInterface,
								pDriver->pI2CBridge,
								Addr,
								CrystalFreq);

	}

	return pDriver;
}


unsigned int IMGConstel2Rtk(unsigned int constel)
{
	unsigned int ans = 0;

	switch (constel) {
	case ISDBT_CONSTELLATION_DQPSK:
		ans  = OFDM_CONST_DQPSK;
		break;
	case ISDBT_CONSTELLATION_QPSK:
		ans  = OFDM_CONST_4;
		break;
	case ISDBT_CONSTELLATION_16QAM:
		ans  = OFDM_CONST_16;
		break;
	case ISDBT_CONSTELLATION_64QAM:
		ans  = OFDM_CONST_64;
		break;
	}

	return ans;

}

unsigned int IMGCoderate2Rtk(unsigned int coderate)
{
	unsigned int ans = 0;

	switch (coderate) {
	case ISDBT_CODE_RATE_1_OVER_2:
		ans  = OFDM_CODE_RATE_1_2;
		break;
	case ISDBT_CODE_RATE_2_OVER_3:
		ans  = OFDM_CODE_RATE_2_3;
		break;
	case ISDBT_CODE_RATE_3_OVER_4:
		ans  = OFDM_CODE_RATE_3_4;
		break;
	case ISDBT_CODE_RATE_5_OVER_6:
		ans  = OFDM_CODE_RATE_5_6;
		break;
	case ISDBT_CODE_RATE_7_OVER_8:
		ans  = OFDM_CODE_RATE_7_8;
		break;
	}

	return ans;
}
unsigned int IMGTimeintlv2Rtk(unsigned int timeintlv)
{
	unsigned int ans = 0;

	switch (timeintlv) {
	case ISDBT_INTERLEAVING_LEN_0:
		ans  = OFDM_INTERLEAVING_LEN_0;
		break;
	case ISDBT_INTERLEAVING_LEN_1:
		ans  = OFDM_INTERLEAVING_LEN_1;
		break;
	case ISDBT_INTERLEAVING_LEN_2:
		ans  = OFDM_INTERLEAVING_LEN_2;
		break;
	case ISDBT_INTERLEAVING_LEN_4:
		ans  = OFDM_INTERLEAVING_LEN_4;
		break;
	}

	return ans;
}

unsigned int ResetDemod(DEMOD* pDemodKernel)
{
    unsigned char     PGAEnable = 0;
	IFADCGAIN         PGAGain = 0;
	unsigned int      IsRpuLowReady, IsRpuHighReady;
	int               ret = TUNER_CTRL_OK;
	TUNER_PARAM       Param;

    REALTEK_I_ISDB* pRealtekIISDB;
	ISDBT_DEMOD_MODULE* pDemod;
	pRealtekIISDB = (REALTEK_I_ISDB*)(pDemodKernel->private_data);

    memset(&PGAGain, 0, sizeof(IFADCGAIN)); 

	if (pDemodKernel->m_pComm == NULL || pRealtekIISDB->m_private == NULL)
	{
        REALTEK_I_ISDBT_INFO("pDemodKernel->m_pComm == NULL || pDemodKernel->m_private == NULL !!!!\n");
	    //return TUNER_CTRL_FAIL;
	}

	pDemod = ((REALTEK_I_ISDBT_DRIVER_DATA*) pRealtekIISDB->m_private)->pDemod;
    pDemodKernel->Lock(pDemodKernel); 
    //m_auto_tune_en = 0;
    pRealtekIISDB->m_auto_tune_enable = 0;
    
    DtvDemodInitialization(RTK_DEMOD_MODE_ISDB, 1);

    ret = DECODE_RET(pDemod->CheckRpuReady(pDemod, &IsRpuLowReady));//Check for Low level Header
	ret |= DECODE_RET(pDemod->CheckRpuReady(pDemod, &IsRpuHighReady));//Check for High level Msg

    if (IsRpuLowReady != 1 || IsRpuHighReady != 1) {
		REALTEK_I_ISDBT_INFO("Waiting for Demod Init Done; Demod Has No Reply !!!!\n");
		REALTEK_I_ISDBT_INFO("Waiting for Demod Init Done; Demod Has No Reply !!!!\n");
		REALTEK_I_ISDBT_INFO("Waiting for Demod Init Done; Demod Has No Reply !!!!\n");
		REALTEK_I_ISDBT_INFO("Waiting for Demod Init Done; Demod Has No Reply !!!!\n");
		REALTEK_I_ISDBT_INFO("RpuLowReady = %d, RpuHighReady = %d\n", IsRpuLowReady, IsRpuHighReady);
		//goto init_fail;
	}

	REALTEK_I_ISDBT_INFO("Change To Buffer Mode........\n");
	ret |= DECODE_RET(pDemod->SwitchToBuffer(pDemod));
	if (ret != TUNER_CTRL_OK) {
		REALTEK_I_ISDBT_INFO("Change To Buffer Mode Fail !!!!!\n");
		goto init_fail;
	}
    
    ret |= DECODE_RET(pDemod->ActivateCore(pDemod));


	// check tuner information
	PGAEnable = 2;
	PGAGain = PGAFIX_2DB;


	if (pDemodKernel->m_pTuner->GetParam(pDemodKernel->m_pTuner, TV_SYS_ISDBT_6M, &Param) == TUNER_CTRL_OK)  {

			switch (Param.id) {
			case TV_TUNER_NXP_TDA18275A:
				REALTEK_I_ISDBT_INFO("Tuner id %d, TV_TUNER_NXP_TDA18275A\n", Param.id);
				pRealtekIISDB->m_AgcScale = 89;//89/128=0.7
				pRealtekIISDB->m_ext_gain_dis=RTK_DEMOD_XML_EXT_GAIN_EN;
				break;

			case TV_TUNER_SILICONLABS_SI2151:
			case TV_TUNER_SILICONLABS_SI2178B:
			case TV_TUNER_NO_TUNER:
				REALTEK_I_ISDBT_INFO("Tuner id %d, TV_TUNER_SILICONLABS_SI21XX\n", Param.id);
				pRealtekIISDB->m_AgcScale = 89;//89/128=0.7
				pRealtekIISDB->m_ext_gain_dis=RTK_DEMOD_XML_EXT_GAIN_EN;
                rtd_outl(0xb8071004, 0x00010000);
				REALTEK_I_ISDBT_INFO("Fix IFAGC PIN at 0V !!!!!\n");
				break;
				
			case TV_TUNER_MAXLINEAR_MXL661:
				REALTEK_I_ISDBT_INFO("Tuner id %d, TV_TUNER_MAXLINEAR_MXL6x1\n", Param.id);
				pRealtekIISDB->m_AgcScale = 89;//89/128=0.7
				pRealtekIISDB->m_ext_gain_dis=RTK_DEMOD_XML_EXT_GAIN_EN;
				break;
				
			case TV_TUNER_RAFAEL_R840:
				REALTEK_I_ISDBT_INFO("Tuner id %d, TV_TUNER_RAFAEL_R840\n", Param.id);
				pRealtekIISDB->m_AgcScale = 89;//89/128=0.7
				pRealtekIISDB->m_ext_gain_dis=RTK_DEMOD_XML_EXT_GAIN_EN;
				break;

			default:
				REALTEK_I_ISDBT_WARNING("unkonw tuner id %d, using default setting\n", Param.id);
				pRealtekIISDB->m_AgcScale = 89;//89/128=0.7
				pRealtekIISDB->m_ext_gain_dis=RTK_DEMOD_XML_EXT_GAIN_EN;
				break;
			}

            pDemodKernel->m_if.freq      = Param.if_freq;
			pDemodKernel->m_if.inversion = Param.if_inversion;
			pDemodKernel->m_if.agc_pola  = Param.if_agc_pola;
			
	}
    else{
        REALTEK_I_ISDBT_INFO("m_pTuner->GetParam(TV_SYS_ISDBT_6M, &Param) != TUNER_CTRL_OK\n");
    }
	DtvPGAControl(PGAEnable, PGAGain);

	ClearDemodReset(RTK_DEMOD_MODE_ISDB);

	ret |= DECODE_RET(pDemod->SetXmlTunerGainCtrl(pDemod, pRealtekIISDB->m_AgcScale | (RTK_DEMOD_XML_EXT_GAIN1 << 16) | (pDemodKernel->m_if.agc_pola << 18)));
	ret |= DECODE_RET(pDemod->SetXmlFlags(pDemod, RTK_DEMOD_XML_REAL_IF | (pDemodKernel->m_if.inversion << 1) | (RTK_DEMOD_XML_UNSIGNED << 2)|(pRealtekIISDB->m_ext_gain_dis << 3)));
	ret |= DECODE_RET(pDemod->SetXmlIfFreq(pDemod, pDemodKernel->m_if.freq));
	ret |= DECODE_RET(pDemod->SetXmlTunerCfgOverride(pDemod, 0x00000001));

	ret |= DECODE_RET(pDemod->SetXmlIfClk(pDemod, 30000000));
	ret |= DECODE_RET(pDemod->SetXmlLdpcClk(pDemod, 270000000));
	ret |= DECODE_RET(pDemod->SetXmlUccClk(pDemod, 270000000));
	ret |= DECODE_RET(pDemod->SetXmlMcuClk(pDemod, 270000000));
	ret |= DECODE_RET(pDemod->SetXmlPlftCfgOverride(pDemod, 0x00000001));

	//Set Ber Cal Period to 1 Sec
	ret |= DECODE_RET(pDemod->SetRegBerPeriod(pDemod, 0x00000001));

	if (pDemodKernel->SetTSMode(pDemodKernel, &pDemodKernel->m_ts) != TUNER_CTRL_OK) {

		REALTEK_I_ISDBT_WARNING("MERLIN2_ISDBT Init set ts mode Failed\n");
		//return TUNER_CTRL_FAIL;
	}

    if (pDemodKernel->SetIF(pDemodKernel, &pDemodKernel->m_if) != TUNER_CTRL_OK)  {
        REALTEK_I_ISDBT_WARNING("MERLIN2_ISDBT Init set IF Failed\n");
        //return  TUNER_CTRL_FAIL;
    }

	REALTEK_I_ISDBT_INFO("MERLIN2_ISDBT Init Complete\n");
    //Set demod
    ret |= DECODE_RET(pDemod->DemodCtrlStop(pDemod));
	ret |= DECODE_RET(pDemod->SetTunerBandwidth(pDemod, pRealtekIISDB->m_current_bw));
	ret |= DECODE_RET(pDemod->SetTunerFreq(pDemod, 666000000));//Set Frequency and Bandwidth together
	ret |= DECODE_RET(pDemod->DemodCtrlDetect(pDemod));
    pDemodKernel->Unlock(pDemodKernel);
	return TUNER_CTRL_OK;

init_fail:
	REALTEK_I_ISDBT_WARNING("REALTEK_I_ISDBT Init Failed\n");
    pDemodKernel->Unlock(pDemodKernel);
	return TUNER_CTRL_FAIL;
}



/*----------------------------------------------------------------------
 * Func : CalSsi
 *
 * Desc :
 *
 * Parm :
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
 
int REALTEK_I_ISDBT_CalSsi(DEMOD* pDemodKernel, int Prec)
{
	unsigned int Modulation = 0, CodeRate = 0;
	long rfLevelQ8 = 0, PrelQ8 = 0, ssiQ8 = 0;
	int ret = TUNER_CTRL_OK;

    REALTEK_I_ISDB* pRealtekIISDB;
	ISDBT_DEMOD_MODULE* pDemod;
	
    REALTEK_I_ISDBT_INFO("CalSsi pQuality->rflevel(%d)\n", Prec);
	if (pDemodKernel == NULL) {
		ret = TUNER_CTRL_FAIL;
		goto CalSsi_End;
	}

    pRealtekIISDB = (REALTEK_I_ISDB*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_ISDBT_DRIVER_DATA*) pRealtekIISDB->m_private)->pDemod;

	ret |= pDemod->GetTunModeA(pDemod, &Modulation);
	ret |= pDemod->GetTunCodeRateA(pDemod, &CodeRate);

	Modulation = (Modulation >= 3) ? 0 : Modulation;
	CodeRate = (CodeRate >= 5) ? 0 : CodeRate;

	if (ret == TUNER_CTRL_OK) {
		rfLevelQ8 = Prec * PHY_ONE_Q8;

		PrelQ8 = rfLevelQ8 - PHY_ONE_Q8 * (int)PHY_Pref[Modulation][CodeRate];

		if (PrelQ8 < DVBT_SSI_NEG15_Q8) {
			ssiQ8 = DVBT_SSI_ZERO_Q8;
		} else if (PrelQ8 < DVBT_SSI_ZERO_Q8) {
			ssiQ8 = (2 * (PrelQ8 + DVBT_SSI_15_Q8)) / 3;
		} else if (PrelQ8 < DVBT_SSI_20_Q8) {
			ssiQ8 = 4 * PrelQ8 + DVBT_SSI_10_Q8;
		} else if (PrelQ8 < DVBT_SSI_35_Q8) {
			ssiQ8 = (2 * (PrelQ8 - DVBT_SSI_20_Q8)) / 3 + DVBT_SSI_90_Q8;
		} else {
			ssiQ8 = DVBT_SSI_100_Q8;
		}

		if (ssiQ8 < DVBT_SSI_ZERO_Q8) {
			ssiQ8 = DVBT_SSI_ZERO_Q8;
		}
		if (ssiQ8 > DVBT_SSI_100_Q8) {
			ssiQ8 = DVBT_SSI_100_Q8;
		}

		ssiQ8 = ((ssiQ8 + (1 << (8 - 1))) >> 8);
	}
CalSsi_End:

	return ssiQ8;
}

