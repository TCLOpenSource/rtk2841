/***************************************************************************************************
  File        : demod_rtk_dvbt2.cpp
  Description : REALTEK_I DVB-T/T2 demod
  Author      : Kevin Wang
****************************************************************************************************
    Update List :
----------------------------------------------------------------------------------------------------
    20120207    | create phase
***************************************************************************************************/
#include <linux/kernel.h>
#include <linux/slab.h>
#include "foundation.h"
#include "demod_rtk_dvbt2.h"
#include "dvbt2_demod_rtk.h"
#include "demod_rtk_dvbt2_priv.h"
#include "dvbt2_tvcore_registers.h"
#include "dvbt2_registers.h"
#include "dvbt_registers.h"
#include <mach/io.h>
#include "rbus/demod_sd_reg.h"
#include "rbus/dtv_frontend_reg.h"

//#define ENABLE_LDR_LOADER
#define SUPPORT_WINTOOL
#define SUPPORT_DEMOD_AUTOTEST

#define COMMON_BASE_ADDRESS     0xc27ff100
#define VR_BASE_ADDRESS         0xc27ff200

#define CONSTELL_EQ_ADDRESS     0xc27ff300
#define CONSTELL_HD_ADDRESS     0xc27ff400

#define DEBUG_MODE_EN_ADDRESS   0xc27ff500
#define DEBUG_MODE_SEL_ADDRESS  0xc27ff504
#define HANDSHAKE_ADDRESS       0xc27ff508
#define PRI_VR_INDEX_ADDRESS    0xc27ff50c
#define SEC_VR_INDEX_ADDRESS    0xc27ff510
#define VR_VALUE_ADDRESS        0xc27ff514

#define IMG_DEMOD_DVBT2_EQ_CONST_ADDRESS 0x371503B8
#define IMG_DEMOD_DVBT2_HD_CONST_ADDRESS 0x36058e08

#define SCAN_THREAD_ENABLE

//------------------------------------------------------------------------------------------
//define new DVBT2 SSI (*256)                   
#define   DVBT2_SSI_NEG100p5_Q8    (-25728)
#define   DVBT2_SSI_NEG15_Q8       (-3840)      // (-15 *256)Lower range of Power level in dBm
#define   DVBT2_SSI_20_Q8          (5120)       // (20 *256)Second threshold for power level
#define   DVBT2_SSI_35_Q8          (8960)       // (35 *256)Upper level for power threshold
#define   DVBT2_SSI_100_Q8         (25600)      // (100 *256)Maximum level of SSI which is an indication for high input power
#define   DVBT2_SSI_ZERO_Q8        (0)          // (0)First threshold for power level
#define   DVBT2_NUM_PLP_CONSTELLATIONS      4
#define   DVBT2_NUM_DATA_PLP_CODE_RATES     8
/* Array to hold the Pref level as in Nordig 2.3 pp 43 */
static signed char prefLevel[DVBT2_NUM_PLP_CONSTELLATIONS][DVBT2_NUM_DATA_PLP_CODE_RATES] = {
	/* Rate:  1/2    3/5     2/3     3/4     4/5     5/6    1/3     2/5           */
	{ -96,   -95,    -94,    -93,    -92,    -92,   -98,    -97},  /* QPSK    */
	{ -91,   -89,    -88,    -87,    -86,    -86,   -94,    -93},  /* 16-QAM  */
	{ -86,   -85,    -83,    -82,    -81,    -80,   -90,    -88},  /* 64-QAM  */
	{ -82,   -80,    -78,    -76,    -75,    -74,   -87,    -85}   /* 256-QAM */
};
//------------------------------------------------------------------------------------------
//DVBT SSI
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


unsigned long acquire_sig_stime;

/*----------------------------------------------------------------------
 * Func : REALTEK_I_DVBT2
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
void REALTEK_I_DVBT2_Constructors(DEMOD* pDemodKernel, unsigned char addr, unsigned char output_mode, unsigned char output_freq, COMM*    pComm)
{
	REALTEK_I_DVBT2* pRealtekIDVBT2;

	pDemodKernel->private_data = kmalloc(sizeof(REALTEK_I_DVBT2), GFP_KERNEL);
	pRealtekIDVBT2 = (REALTEK_I_DVBT2*)(pDemodKernel->private_data);

	Demod_Constructors(pDemodKernel);

	pDemodKernel->m_id                 = DTV_DEMOD_REALTEK_I_DVBT2;
	pDemodKernel->m_addr               = addr;
	pDemodKernel->m_pTuner             = NULL;
	pDemodKernel->m_pComm              = pComm;
	pDemodKernel->m_ScanRange          = SCAN_RANGE_3_6;
	pDemodKernel->m_Capability         = TV_SYS_TYPE_DVBT2;
	pDemodKernel->m_update_interval_ms = 300;
	pDemodKernel->m_if.freq            = 5000000;
	pDemodKernel->m_if.inversion       = 0;
	pDemodKernel->m_if.agc_pola        = 0;
	pDemodKernel->m_clock              = CRYSTAL_FREQ_27000000HZ;
	pRealtekIDVBT2->m_output_freq        = output_freq;

	pRealtekIDVBT2->m_private            = (void*) AllocRealtekIDvbt2Driver(pDemodKernel->m_pComm, pDemodKernel->m_addr, pDemodKernel->m_clock);

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
	pRealtekIDVBT2->m_TunerOptRegCnt = 0;
	pRealtekIDVBT2->m_acquire_sig_en = 0;
	pRealtekIDVBT2->m_pTunerOptReg = NULL;

	pRealtekIDVBT2->m_dvbt2_AgcScale = 48;
	pRealtekIDVBT2->m_dvbt2_ext_gain_dis = RTK_DEMOD_XML_EXT_GAIN_EN;
	pRealtekIDVBT2->m_dvbt_AgcScale = 64;
	pRealtekIDVBT2->m_dvbt_ext_gain_dis = RTK_DEMOD_XML_EXT_GAIN_EN;
	pRealtekIDVBT2->m_unlock_cnt = 0;
	pRealtekIDVBT2->m_auto_tune_en = 0;
	pRealtekIDVBT2->m_dvbt2_sfo = 0;

	pDemodKernel->m_pComm->SetTargetName(pDemodKernel->m_pComm, pDemodKernel->m_addr, "REALTEK_I_DVBT2");

	pDemodKernel->Init = REALTEK_I_DVBT2_Init;
	pDemodKernel->Reset = Demod_Reset;
	pDemodKernel->AcquireSignal = REALTEK_I_DVBT2_AcquireSignal;
	pDemodKernel->ScanSignal = REALTEK_I_DVBT2_ScanSignal;
	pDemodKernel->SetIF = REALTEK_I_DVBT2_SetIF;
	pDemodKernel->SetTSMode = REALTEK_I_DVBT2_SetTSMode;
	pDemodKernel->SetTVSysEx = REALTEK_I_DVBT2_SetTVSysEx;
	pDemodKernel->SetMode = REALTEK_I_DVBT2_SetMode;
	pDemodKernel->SetTVSys = REALTEK_I_DVBT2_SetTVSys;
	pDemodKernel->GetLockStatus = REALTEK_I_DVBT2_GetLockStatus;
	pDemodKernel->GetSegmentNum = Demod_GetSegmentNum;
	pDemodKernel->GetSignalInfo = REALTEK_I_DVBT2_GetSignalInfo;
	pDemodKernel->GetSignalQuality = REALTEK_I_DVBT2_GetSignalQuality;
	pDemodKernel->GetT2PLPInfo = REALTEK_I_DVBT2_GetT2PLPInfo;
	pDemodKernel->ChangeT2PLP = REALTEK_I_DVBT2_ChangeT2PLP;
	pDemodKernel->GetT2L1PreInfo = Demod_GetT2L1PreInfo;
	pDemodKernel->GetT2L1PostInfo = Demod_GetT2L1PostInfo;
	pDemodKernel->GetDemodStatus = Demod_GetDemodStatus;
	pDemodKernel->GetCarrierOffset = REALTEK_I_DVBT2_GetCarrierOffset;
	pDemodKernel->GetDebugLogBuf = REALTEK_I_DVBT2_GetDebugLogBuf;
	pDemodKernel->ForwardI2C = REALTEK_I_DVBT2_ForwardI2C;
	pDemodKernel->AutoTune = REALTEK_I_DVBT2_AutoTune;
	pDemodKernel->KernelAutoTune = REALTEK_I_DVBT2_KernelAutoTune;
	pDemodKernel->GetCapability = Demod_GetCapability;
	pDemodKernel->Suspend = Demod_Suspend;
	pDemodKernel->Resume = Demod_Resume;
	pDemodKernel->SetTvMode = REALTEK_I_DVBT2_SetTvMode;
	pDemodKernel->InspectSignal = REALTEK_I_DVBT2_InspectSignal;    // Add monitor function that used to monitor demod status
	pDemodKernel->AttachTuner = Demod_AttachTuner;
	pDemodKernel->GetTSParam = Demod_GetTSParam;
	//pDemodKernel->Lock = Demod_Lock;
	//pDemodKernel->Unlock = Demod_Unlock;
	pDemodKernel->Lock = REALTEK_I_DVBT2_Lock;
	pDemodKernel->Unlock = REALTEK_I_DVBT2_Unlock;

	//pDemodKernel->Activate = REALTEK_I_DVBT2_Activate;
	pDemodKernel->Destory = REALTEK_I_DVBT2_Destructors;

#ifdef SUPPORT_WINTOOL
	pRealtekIDVBT2->m_debug_tool_en = 0;
	rtd_outl(DEBUG_MODE_EN_ADDRESS, 0);
	rtd_outl(DEBUG_MODE_SEL_ADDRESS, 0);
#endif
}


/*----------------------------------------------------------------------
 * Func : ~REALTEK_I_DVBT2
 *
 * Desc : Destructor of REALTEK_I_DVBT2
 *
 * Parm : pDemod : handle of Demod
 *
 * Retn : N/A
 *----------------------------------------------------------------------*/
void REALTEK_I_DVBT2_Destructors(DEMOD* pDemodKernel)
{
	REALTEK_I_DVBT2* pRealtekIDVBT2;
	pRealtekIDVBT2 = (REALTEK_I_DVBT2*)(pDemodKernel->private_data);

	if (pRealtekIDVBT2->m_private != NULL)
		ReleaseRealtekIDvbt2Driver((REALTEK_I_DVBT2_DRIVER_DATA*)pRealtekIDVBT2->m_private);

	kfree(pRealtekIDVBT2);
	//pDemodKernel->Destory(pDemodKernel);
	REALTEK_I_DVBT2_INFO("REALTEK_A_DVBTX_Destructors Complete\n");
}


/*----------------------------------------------------------------------
 * Func : Init
 *
 * Desc : Initial realtekI
 *
 * Parm : N/A
 *
 * Retn : TUNER_CTRL_OK / TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBT2_Init(DEMOD* pDemodKernel)
{
	unsigned char     PGAEnable = 0;
	IFADCGAIN         PGAGain;
	unsigned int      IsRpuLowReady, IsRpuHighReady;
	//unsigned int      BuildId, DemodType;
	//unsigned int      InitRetry = 0;
	int               ret = TUNER_CTRL_OK;

	REALTEK_I_DVBT2* pRealtekIDVBT2;
	REG_VALUE_ENTRY*  OptRegTable;
	DVBT2_DEMOD_MODULE* pDemod;
	pRealtekIDVBT2 = (REALTEK_I_DVBT2*)(pDemodKernel->private_data);


	//REALTEK_I_DVBT2_INFO("\033[1;32;31m" "%s %s %d\n" "\033[m", __FILE__, __func__, __LINE__);

	if (pDemodKernel->m_pComm == NULL || pRealtekIDVBT2->m_private == NULL)
		return TUNER_CTRL_FAIL;

	pDemod = ((REALTEK_I_DVBT2_DRIVER_DATA*) pRealtekIDVBT2->m_private)->pDemod;

	//////////////////////////////////////////////////
	//DVBT2_DEMOD_MODULE* pDemod = ((REALTEK_I_DVBT2_DRIVER_DATA*) pRealtekIDVBT2->m_private)->pDemod;

	//////////////////////////////////////////////////

	pDemodKernel->Lock(pDemodKernel);

	pRealtekIDVBT2->m_auto_tune_en = 0;
	pRealtekIDVBT2->m_unlock_cnt = 0;

	DtvDemodInitialization(RTK_DEMOD_MODE_DVBT2, 1);
	pRealtekIDVBT2->m_dvbt2_dvbt_mode = REALTEK_I_DVBT2_MODE;

	ret = DECODE_RET(pDemod->CheckRpuReady(pDemod, &IsRpuLowReady));//Check for Low level Header
	ret |= DECODE_RET(pDemod->CheckRpuReady(pDemod, &IsRpuHighReady));//Check for High level Msg

	if (IsRpuLowReady != 1 || IsRpuHighReady != 1 || ret != TUNER_CTRL_OK) {
		REALTEK_I_DVBT2_INFO("Waiting for Demod Init Done; Demod Has No Reply !!!!\n");
		REALTEK_I_DVBT2_INFO("RpuLowReady = %d, RpuHighReady = %d\n", IsRpuLowReady, IsRpuHighReady);
		goto init_fail;
	}

	//Change To Buffer Mode
	REALTEK_I_DVBT2_INFO("Change To Buffer Mode........\n");
	ret |= DECODE_RET(pDemod->SwitchToBuffer(pDemod));
	if (ret != TUNER_CTRL_OK) {
		REALTEK_I_DVBT2_INFO("Change To Buffer Mode Fail !!!!!\n");
		goto init_fail;
	}

	ret |= DECODE_RET(pDemod->ActivateCore(pDemod));

	// check tuner information
	PGAEnable = 2;
	PGAGain = PGAFIX_2DB;
	
	if (pDemodKernel->m_pTuner) {
		TUNER_PARAM Param;

		if (pDemodKernel->m_pTuner->GetParam(pDemodKernel->m_pTuner, TV_SYS_DVBT2_6M, &Param) == TUNER_CTRL_OK) {
			switch (Param.id)  {
			case TV_TUNER_NXP_TDA18275A:
				REALTEK_I_DVBT2_INFO("Tuner id %d, TV_TUNER_NXP_TDA182XX\n", Param.id);
				pRealtekIDVBT2->m_dvbt2_AgcScale = 61;//61/128=0.475
				pRealtekIDVBT2->m_dvbt2_ext_gain_dis = RTK_DEMOD_XML_EXT_GAIN_EN;
				pRealtekIDVBT2->m_dvbt_AgcScale = 39;//39/128=0.305
				pRealtekIDVBT2->m_dvbt_ext_gain_dis = RTK_DEMOD_XML_EXT_GAIN_EN;
				break;
			case TV_TUNER_SILICONLABS_SI2151:
			case TV_TUNER_SILICONLABS_SI2178B:
			case TV_TUNER_NO_TUNER:
				REALTEK_I_DVBT2_INFO("Tuner id %d, TV_TUNER_SILICONLABS_SI21XX\n", Param.id);
				pRealtekIDVBT2->m_dvbt2_AgcScale = 48;
				pRealtekIDVBT2->m_dvbt2_ext_gain_dis = RTK_DEMOD_XML_EXT_GAIN_EN;
				pRealtekIDVBT2->m_dvbt_AgcScale = 64;
				pRealtekIDVBT2->m_dvbt_ext_gain_dis = RTK_DEMOD_XML_EXT_GAIN_EN;
				break;
			case TV_TUNER_RAFAEL_R840:
				REALTEK_I_DVBT2_INFO("Tuner id %d, TV_TUNER_RAFAEL_R840\n", Param.id);
				pRealtekIDVBT2->m_dvbt2_AgcScale = 61;//61/128=0.475
				pRealtekIDVBT2->m_dvbt2_ext_gain_dis = RTK_DEMOD_XML_EXT_GAIN_EN;
				pRealtekIDVBT2->m_dvbt_AgcScale = 64;//64/128=0.5
				pRealtekIDVBT2->m_dvbt_ext_gain_dis = RTK_DEMOD_XML_EXT_GAIN_EN;
				break;
			case TV_TUNER_MAXLINEAR_MXL661:
				REALTEK_I_DVBT2_INFO("Tuner id %d, TV_TUNER_MAXLINEAR_MXL6X1\n", Param.id);
				pRealtekIDVBT2->m_dvbt2_AgcScale = 90;//90/128=0.7
				pRealtekIDVBT2->m_dvbt2_ext_gain_dis = RTK_DEMOD_XML_EXT_GAIN_EN;
				pRealtekIDVBT2->m_dvbt_AgcScale = 90;//90/128=0.7
				pRealtekIDVBT2->m_dvbt_ext_gain_dis = RTK_DEMOD_XML_EXT_GAIN_EN;
				break;
			default:
				REALTEK_I_DVBT2_INFO("Unkonw tuner id %d, using default setting\n", Param.id);
				pRealtekIDVBT2->m_dvbt2_AgcScale = 128;
				pRealtekIDVBT2->m_dvbt2_ext_gain_dis = RTK_DEMOD_XML_EXT_GAIN_EN;
				pRealtekIDVBT2->m_dvbt_AgcScale = 128;
				pRealtekIDVBT2->m_dvbt_ext_gain_dis = RTK_DEMOD_XML_EXT_GAIN_EN;
				break;
			}

			//REALTEK_I_DVBT2_INFO("AGC Scaling = %d /128; Inverse = %d\n", pRealtekIDVBT2->m_dvbt2_AgcScale, pRealtekIDVBT2->m_dvbt2_Invert);
			pDemodKernel->m_if.freq      = Param.if_freq;
			pDemodKernel->m_if.inversion = Param.if_inversion;
			pDemodKernel->m_if.agc_pola  = Param.if_agc_pola;
		}
	}

	DtvPGAControl(PGAEnable, PGAGain);

	ClearDemodReset(RTK_DEMOD_MODE_DVBT2);

#if 1
	//DVBT2 10.3.1 Support Run Time Change XML Parmeters
	ret |= DECODE_RET(pDemod->SetXmlTunerGainCtrl(pDemod, pRealtekIDVBT2->m_dvbt2_AgcScale | (RTK_DEMOD_XML_EXT_GAIN1 << 16) | (pDemodKernel->m_if.agc_pola << 18)));
	ret |= DECODE_RET(pDemod->SetXmlFlags(pDemod, RTK_DEMOD_XML_REAL_IF | (pDemodKernel->m_if.inversion << 1) | (RTK_DEMOD_XML_UNSIGNED << 2) | (pRealtekIDVBT2->m_dvbt2_ext_gain_dis << 3)));
	ret |= DECODE_RET(pDemod->SetXmlIfFreq(pDemod, pDemodKernel->m_if.freq));
	ret |= DECODE_RET(pDemod->SetXmlTunerCfgOverride(pDemod, 0x00000001));

	ret |= DECODE_RET(pDemod->SetXmlIfClk(pDemod, 30000000));
	ret |= DECODE_RET(pDemod->SetXmlLdpcClk(pDemod, DVBT2_META_2X_CLOCK));
	ret |= DECODE_RET(pDemod->SetXmlUccClk(pDemod, DVBT2_META_1X_CLOCK));
	ret |= DECODE_RET(pDemod->SetXmlMcuClk(pDemod, DVBT2_META_2X_CLOCK));
	ret |= DECODE_RET(pDemod->SetXmlPlftCfgOverride(pDemod, 0x00000001));
#endif

	//Set DVBT2 Ber Cal Period to 1 Sec
	ret |= DECODE_RET(pDemod->SetErrRateIntegPeriod(pDemod, 0x00000001));

	if (pDemodKernel->SetTSMode(pDemodKernel, &pDemodKernel->m_ts) != TUNER_CTRL_OK) {
		goto init_fail;
	}
	REALTEK_I_DVBT2_DBG("REALTEK_I_DVBT2 Init Complete\n");

	pDemodKernel->Unlock(pDemodKernel);

	return TUNER_CTRL_OK;

init_fail:

	REALTEK_I_DVBT2_WARNING("REALTEK_I_DVBT2 Init Failed\n");

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
int REALTEK_I_DVBT2_SetTVSys(DEMOD* pDemodKernel, TV_SYSTEM sys)
{
       int ret; 
	REALTEK_I_DVBT2* pRealtekIDVBT2;
	pRealtekIDVBT2 = (REALTEK_I_DVBT2*)(pDemodKernel->private_data);

	TV_SIG_INFO   *pSigInfo;
        pSigInfo = kmalloc(sizeof(TV_SIG_INFO), GFP_KERNEL); 
	

	REALTEK_I_DVBT2_INFO("\033[1;32;31m" "%s %s %d\n" "\033[m", __FILE__, __func__, __LINE__);

	pSigInfo->dvbt2_ofdm.scan_mode = CH_NORMAL_MODE;
	pSigInfo->dvbt2_ofdm.mod = TV_MODULATION_DVBT2_OFDM;
	pSigInfo->dvbt2_ofdm.constellation = QAM_CONST_64;
	pSigInfo->dvbt2_ofdm.profile = 0;

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
int REALTEK_I_DVBT2_SetTVSysEx(DEMOD* pDemodKernel, TV_SYSTEM sys, const TV_SIG_INFO*  pSigInfo)
{
	int ret = TUNER_CTRL_OK;
	TUNER_PARAM Param;
	unsigned int SpectrumInvert, ext_gain_dis, TunHierarchical;
	CH_MODE Dvbt2ScanMode;
	TV_SYSTEM_TYPE TvSysMode;
	int i;


	REALTEK_I_DVBT2* pRealtekIDVBT2;
	DVBT2_DEMOD_MODULE* pDemod;
	pRealtekIDVBT2 = (REALTEK_I_DVBT2*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_DVBT2_DRIVER_DATA*) pRealtekIDVBT2->m_private)->pDemod;

	REALTEK_I_DVBT2_INFO("\033[1;32;31m" "%s %s %d\n" "\033[m", __FILE__, __func__, __LINE__);

	if (IsDvbt2Sys(sys) == 0 && IsDvbtSys(sys) == 0) {
		REALTEK_I_DVBT2_WARNING("Set TV system failed, unsupported TV system\n");
		return TUNER_CTRL_FAIL;
	}

	if (!pSigInfo) {
		REALTEK_I_DVBT2_INFO("Siginfo doesn't specified, SetTVSysEx Fail\n");
		return TUNER_CTRL_FAIL;
	}


	pDemodKernel->Lock(pDemodKernel);

	pRealtekIDVBT2->m_auto_tune_en = 0;
	pDemodKernel->m_tv_sys = sys;
	Dvbt2ScanMode = pSigInfo->dvbt2_ofdm.scan_mode ? CH_SCAN_MODE : CH_NORMAL_MODE;

	GetDemodTvSysMode(&TvSysMode);

	if (Dvbt2ScanMode == CH_SCAN_MODE && pSigInfo->dvbt2_ofdm.bProfileHP == 1) {
		switch (sys) {
		case TV_SYS_DVBT_8M:
			sys = TV_SYS_AUTOSCAN_8M;
			break;
		case TV_SYS_DVBT_7M:
			sys = TV_SYS_AUTOSCAN_7M;
			break;
		case TV_SYS_DVBT_6M:
			sys = TV_SYS_AUTOSCAN_6M;
			break;
		}
	}

	if (IsDvbtSys(sys) == 1 && TvSysMode != TV_SYS_TYPE_DVBT)
		REALTEK_I_DVBT2_ChangeStandard(pDemodKernel, REALTEK_I_DVBT_MODE);
	else if (IsDvbt2Sys(sys) == 1 && TvSysMode != TV_SYS_TYPE_DVBT2)
		REALTEK_I_DVBT2_ChangeStandard(pDemodKernel, REALTEK_I_DVBT2_MODE);


	//TUNER_PARAM Param;
	if (pDemodKernel->m_pTuner->GetParam(pDemodKernel->m_pTuner, sys, &Param) == TUNER_CTRL_OK) {
		if ((pDemodKernel->m_if.freq != Param.if_freq) || (pDemodKernel->m_if.inversion != Param.if_inversion) || (pDemodKernel->m_if.agc_pola  != Param.if_agc_pola)) {
			pDemodKernel->m_if.freq = Param.if_freq;
			pDemodKernel->m_if.inversion = Param.if_inversion;
			pDemodKernel->m_if.agc_pola = Param.if_agc_pola;
			if (pDemodKernel->SetIF(pDemodKernel, &pDemodKernel->m_if) != TUNER_CTRL_OK)  return  TUNER_CTRL_FAIL;

		}
	}

	pRealtekIDVBT2->m_plp_id  = ((pSigInfo->dvbt2_ofdm.plp_select < 256) && (pSigInfo->dvbt2_ofdm.plp_select > 0)) ? pSigInfo->dvbt2_ofdm.plp_select : 0;
	pRealtekIDVBT2->m_profileHP = (pSigInfo->dvbt2_ofdm.bProfileHP <= 1) ? pSigInfo->dvbt2_ofdm.bProfileHP : 1;

	if (Dvbt2ScanMode == CH_NORMAL_MODE) {
		if (IsDvbt2Sys(sys))
			//SpectrumInvert = (pSigInfo->dvbt2_ofdm.bSpectrumInv == 1) ? (!pDemodKernel->m_if.inversion) : pDemodKernel->m_if.inversion;
			SpectrumInvert = pDemodKernel->m_if.inversion;
		else
			SpectrumInvert = (pSigInfo->dvbt2_ofdm.bSpectrumInv == 1) ? (!pDemodKernel->m_if.inversion) : pDemodKernel->m_if.inversion;
	} else
		SpectrumInvert = pDemodKernel->m_if.inversion;

	ext_gain_dis = IsDvbt2Sys(sys) ? pRealtekIDVBT2->m_dvbt2_ext_gain_dis : pRealtekIDVBT2->m_dvbt_ext_gain_dis;


	//Set Demod for Avoiding Any Problems
	switch (sys) {
	case TV_SYS_DVBT2_1D7M_PLP:
		pRealtekIDVBT2->m_current_bw = 1700000;
		pRealtekIDVBT2->m_fastscan_en = 0;
		break;
	case TV_SYS_DVBT2_5M:
		pRealtekIDVBT2->m_current_bw = 5000000;
		pRealtekIDVBT2->m_fastscan_en = 0;
		pRealtekIDVBT2->m_dvbt_bandwidth_mask = 0x8000087F;//Fix bandwidth by SetTvSysEx Setting
		break;
	case TV_SYS_DVBT2_6M_PLP:
	case TV_SYS_DVBT2_6M:
	case TV_SYS_DVBT_6M:
		pRealtekIDVBT2->m_current_bw = 6000000;
		pRealtekIDVBT2->m_fastscan_en = 0;
		pRealtekIDVBT2->m_dvbt_bandwidth_mask = 0x8000047F;//Fix bandwidth by SetTvSysEx Setting
		break;
	case TV_SYS_DVBT2_7M_PLP:
	case TV_SYS_DVBT2_7M:
	case TV_SYS_DVBT_7M:
		pRealtekIDVBT2->m_current_bw = 7000000;
		pRealtekIDVBT2->m_fastscan_en = 0;
		pRealtekIDVBT2->m_dvbt_bandwidth_mask = 0x8000027F;//Fix bandwidth by SetTvSysEx Setting
		break;
	case TV_SYS_DVBT2_8M_PLP:
	case TV_SYS_DVBT2_8M:
	case TV_SYS_DVBT_8M:
		pRealtekIDVBT2->m_current_bw = 8000000;
		pRealtekIDVBT2->m_fastscan_en = 0;
		pRealtekIDVBT2->m_dvbt_bandwidth_mask = 0x8000017F;//Fix bandwidth by SetTvSysEx Setting
		break;
	case TV_SYS_AUTOSCAN_6M:
		pRealtekIDVBT2->m_current_bw = 6000000;
		pRealtekIDVBT2->m_fastscan_en = 1;
		pRealtekIDVBT2->m_dvbt_bandwidth_mask = 0x8000047F;//Fix bandwidth by SetTvSysEx Setting
		break;
	case TV_SYS_AUTOSCAN_7M:
		pRealtekIDVBT2->m_current_bw = 7000000;
		pRealtekIDVBT2->m_fastscan_en = 1;
		pRealtekIDVBT2->m_dvbt_bandwidth_mask = 0x8000027F;//Fix bandwidth by SetTvSysEx Setting
		break;
	case TV_SYS_AUTOSCAN_8M:
	default:
		pRealtekIDVBT2->m_current_bw = 8000000;
		pRealtekIDVBT2->m_fastscan_en = 1;
		pRealtekIDVBT2->m_dvbt_bandwidth_mask = 0x8000017F;//Fix bandwidth by SetTvSysEx Setting
		break;
	}
	REALTEK_I_DVBT2_INFO("System=%u, BW= %u, scan mode=%d, bSpectrumInv = %u, ProfileHP(T)=%d, PLP_ID(T2)=%u\n", sys, pRealtekIDVBT2->m_current_bw, Dvbt2ScanMode, SpectrumInvert, pRealtekIDVBT2->m_profileHP, pRealtekIDVBT2->m_plp_id);

	ret |= DECODE_RET(pDemod->DemodCtrlStop(pDemod));
	ret |= DECODE_RET(pDemod->SetXmlFlags(pDemod, RTK_DEMOD_XML_REAL_IF | (SpectrumInvert << 1) | (RTK_DEMOD_XML_UNSIGNED << 2) | (ext_gain_dis << 3)));

	if (pRealtekIDVBT2->m_fastscan_en == 1) {

		ret |= DECODE_RET(pDemod->SetDvbT2DvbTSearchMode(pDemod, 0x00000008));//Set to Auto DVBT2/DVBT Mode
		ret |= DECODE_RET(pDemod->SetDvbT2DvbtSearchDecisionTh1(pDemod, 0x200));
		ret |= DECODE_RET(pDemod->SetP1SearchTimeout(pDemod, 500));//P1 Time Out 500ms for FEF
		ret |= DECODE_RET(pDemod->SetDvbT2DvbTSearchResult(pDemod, 0, 0));
		ret |= DECODE_RET(pDemod->SetTunerBandwidth(pDemod, pRealtekIDVBT2->m_current_bw));//Change Bandwidth
		ret |= DECODE_RET(pDemod->SetTunerFreq(pDemod, 666000000));//Set Frequency and Bandwidth together
		ret |= DECODE_RET(pDemod->SetDataPlpIdSelectCmd(pDemod, (unsigned int)pRealtekIDVBT2->m_plp_id));
		ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBT2_REG_SFOPPM_Q16_15, pRealtekIDVBT2->m_dvbt2_sfo));
		ret |= DECODE_RET(pDemod->DemodCtrlRun(pDemod));


	} else {

		if (IsDvbt2Sys(sys) == 1) {
			ret |= DECODE_RET(pDemod->SetDvbT2DvbTSearchMode(pDemod, 0x00000001));//Disable Auto DVBT2/DVBT Mode
			ret |= DECODE_RET(pDemod->SetDvbT2DvbtSearchDecisionTh1(pDemod, 0x200));
			ret |= DECODE_RET(pDemod->SetTunerBandwidth(pDemod, pRealtekIDVBT2->m_current_bw));//Change Bandwidth
			ret |= DECODE_RET(pDemod->SetTunerFreq(pDemod, 666000000));//Set Frequency and Bandwidth together
			ret |= DECODE_RET(pDemod->SetDataPlpIdSelectCmd(pDemod, (unsigned int)pRealtekIDVBT2->m_plp_id));
			ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBT2_REG_SFOPPM_Q16_15, pRealtekIDVBT2->m_dvbt2_sfo));
			ret |= DECODE_RET(pDemod->DemodCtrlRun(pDemod));

		} else {
			ret |= DECODE_RET(pDemod->SetDvbTDetectMask(pDemod, pRealtekIDVBT2->m_dvbt_bandwidth_mask));//Set DVBT bandwidth filter
			ret |= DECODE_RET(pDemod->SetTunerBandwidth(pDemod, pRealtekIDVBT2->m_current_bw));//Change Bandwidth
			ret |= DECODE_RET(pDemod->SetTunerFreq(pDemod, 666000000));//Set Frequency and Bandwidth together
			ret |= DECODE_RET(pDemod->SetDvbTTunHierarchical(pDemod, pRealtekIDVBT2->m_profileHP ? 0 : 1));
			ret |= DECODE_RET(pDemod->DemodCtrlDetect(pDemod));
		}
	}

	pDemodKernel->Unlock(pDemodKernel);
	pDemodKernel->m_ScanMode = Dvbt2ScanMode;
	pRealtekIDVBT2->m_acquire_sig_en = 1;
	pRealtekIDVBT2->m_unlock_cnt = 0;
	pRealtekIDVBT2->m_auto_tune_en = 1;
	acquire_sig_stime = tv_osal_time();
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
int REALTEK_I_DVBT2_SetIF(DEMOD* pDemodKernel, IF_PARAM* pParam)
{
	int ret = TUNER_CTRL_OK;
	REALTEK_I_DVBT2* pRealtekIDVBT2;
	DVBT2_DEMOD_MODULE* pDemod;
	pRealtekIDVBT2 = (REALTEK_I_DVBT2*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_DVBT2_DRIVER_DATA*) pRealtekIDVBT2->m_private)->pDemod;

	//REALTEK_I_DVBT2_INFO("\033[1;32;31m" "%s %s %d\n" "\033[m", __FILE__, __func__, __LINE__);
	pDemodKernel->Lock(pDemodKernel);

	REALTEK_I_DVBT2_DBG("SetIF, IF_freq=%lu, spectrumn inv=%d, agc_pola=%d\n", pParam->freq, pParam->inversion, pParam->agc_pola);

	ret |= DECODE_RET(pDemod->SetXmlTunerGainCtrl(pDemod, pRealtekIDVBT2->m_dvbt2_AgcScale | (RTK_DEMOD_XML_EXT_GAIN1 << 16) | (pParam->agc_pola << 18)));
	ret |= DECODE_RET(pDemod->SetXmlFlags(pDemod, RTK_DEMOD_XML_REAL_IF | (pParam->inversion << 1) | (RTK_DEMOD_XML_UNSIGNED << 2) | (pRealtekIDVBT2->m_dvbt2_ext_gain_dis << 3)));
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
int REALTEK_I_DVBT2_SetMode(DEMOD* pDemodKernel, TV_OP_MODE mode)
{
	REALTEK_I_DVBT2* pRealtekIDVBT2;
	pRealtekIDVBT2 = (REALTEK_I_DVBT2*)(pDemodKernel->private_data);

	//REALTEK_I_DVBT2_INFO("\033[1;32;31m" "%s %s %d\n" "\033[m", __FILE__, __func__, __LINE__);

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
int REALTEK_I_DVBT2_SetTSMode(DEMOD* pDemodKernel, TS_PARAM* pParam)
{
	int ret = TUNER_CTRL_OK;
	unsigned char TsOutEn, TsSerial, ClkPhase;

	REALTEK_I_DVBT2* pRealtekIDVBT2;
	DVBT2_DEMOD_MODULE* pDemod;
	pRealtekIDVBT2 = (REALTEK_I_DVBT2*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_DVBT2_DRIVER_DATA*) pRealtekIDVBT2->m_private)->pDemod;

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
int REALTEK_I_DVBT2_GetLockStatus(DEMOD* pDemodKernel, unsigned char* pLock)
{
	unsigned char   lock;
	unsigned int    DemodStatus, TsPktCnt;
	int ret = TUNER_CTRL_OK;
	unsigned int ReadValue = 0;

	REALTEK_I_DVBT2* pRealtekIDVBT2;
	DVBT2_DEMOD_MODULE* pDemod;
	pRealtekIDVBT2 = (REALTEK_I_DVBT2*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_DVBT2_DRIVER_DATA*)pRealtekIDVBT2->m_private)->pDemod;

	if (!DtvIsDemodClockEnable(RTK_DEMOD_MODE_DVBT2))
		return TUNER_CTRL_FAIL;

	pDemodKernel->Lock(pDemodKernel);

#ifdef SUPPORT_WINTOOL
	if (!pRealtekIDVBT2->m_debug_tool_en) {
#endif




	ret |= DECODE_RET(pDemod->GetDemodStatus(pDemod, &DemodStatus));
	lock = (DemodStatus == 5) ? YES : NO;

	if (lock == YES && ret == TUNER_CTRL_OK) {
		*pLock = DECODE_LOCK(lock);

		if ((pRealtekIDVBT2->m_dvbt2_dvbt_mode == REALTEK_I_DVBT2_MODE) && (pDemod->GetVirtualRegister(pDemod, DVBT2_REG_SFOPPM_Q16_15, &ReadValue) == TUNER_CTRL_OK))
			pRealtekIDVBT2->m_dvbt2_sfo = ReadValue;

		pRealtekIDVBT2->m_autotune_stime = tv_osal_time() + AUTODETECT_SIG_UPDATE_INTERVAL_MS;
	} else
		*pLock = 0;

	pRealtekIDVBT2->m_unlock_cnt = (*pLock) ? 0 : pRealtekIDVBT2->m_unlock_cnt + 1;
	REALTEK_I_DVBT2_DBG("Mode = %u, DemodStatus=%u, *pLock = %u, unlockcnt=%u\n", pRealtekIDVBT2->m_dvbt2_dvbt_mode, DemodStatus, *pLock, pRealtekIDVBT2->m_unlock_cnt);




#ifdef SUPPORT_WINTOOL
	} else {
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
int REALTEK_I_DVBT2_GetSignalInfo(DEMOD* pDemodKernel, TV_SIG_INFO* pInfo)
{
	int ret = TUNER_CTRL_OK;

	REALTEK_I_DVBT2* pRealtekIDVBT2;
	DVBT2_DEMOD_MODULE* pDemod;
	unsigned int fft_size = 0, guard = 0, code_rate = 0, constellation = 0, cell_id = 0, hierarchy = 0, spec_inv = 0, profile = 0;

	pRealtekIDVBT2 = (REALTEK_I_DVBT2*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_DVBT2_DRIVER_DATA*)pRealtekIDVBT2->m_private)->pDemod;

#ifdef SUPPORT_WINTOOL
	if (!pRealtekIDVBT2->m_debug_tool_en) {
#endif




	if (pRealtekIDVBT2->m_dvbt2_dvbt_mode == REALTEK_I_DVBT2_MODE) {
		pInfo->dvbt2_ofdm.bandwidth = pRealtekIDVBT2->m_current_bw;
		pInfo->mod = TV_MODULATION_DVBT2_OFDM;
		pDemodKernel->Lock(pDemodKernel);
		pDemodKernel->GetT2PLPInfo(pDemodKernel, pInfo);
		pDemod->GetVirtualRegister(pDemod, DVBT2_REG_SPECTRUM_INVERTED, &spec_inv);     //bSpectrumInv
		pDemod->GetVirtualRegister(pDemod, DVBT2_REG_S2, &fft_size);                    //carrierMode
		pDemod->GetVirtualRegister(pDemod, DVBT2_REG_GUARD_INTERVAL, &guard);           //guardInterval
		pDemod->GetVirtualRegister(pDemod, DVBT2_REG_DATA_PLP_COD, &code_rate);         //codeRate
		pDemod->GetVirtualRegister(pDemod, DVBT2_REG_DATA_PLP_MOD, &constellation);     //constellation
		pDemod->GetVirtualRegister(pDemod, DVBT2_REG_CELL_ID, &cell_id);                //cell id
		pDemodKernel->Unlock(pDemodKernel);

		switch (fft_size) {
		case 0://FFT 2k
			pInfo->dvbt2_ofdm.fft_mode = OFDM_FFT_2K;
			break;
		case 1://FFT 8k
			pInfo->dvbt2_ofdm.fft_mode = OFDM_FFT_8K;
			break;
		case 2://FFT 4k
			pInfo->dvbt2_ofdm.fft_mode = OFDM_FFT_4K;
			break;
		case 3://FFT 1k
			pInfo->dvbt2_ofdm.fft_mode = OFDM_FFT_1K;
			break;
		case 4://FFT 16k
			pInfo->dvbt2_ofdm.fft_mode = OFDM_FFT_16K;
			break;
		case 5://FFT 32k
			pInfo->dvbt2_ofdm.fft_mode = OFDM_FFT_32K;
			break;
		case 6://FFT 8k
			pInfo->dvbt2_ofdm.fft_mode = OFDM_FFT_8K;
			break;
		case 7://FFT 32k
		default:
			pInfo->dvbt2_ofdm.fft_mode = OFDM_FFT_32K;
			break;
		}

		switch (guard) {
		case 0://Guard 1/32
			pInfo->dvbt2_ofdm.guard_interval = OFDM_GI_1_32;
			break;
		case 1://Guard 1/16
			pInfo->dvbt2_ofdm.guard_interval = OFDM_GI_1_16;
			break;
		case 2://Guard 1/8
			pInfo->dvbt2_ofdm.guard_interval = OFDM_GI_1_8;
			break;
		case 3://Guard 1/4
			pInfo->dvbt2_ofdm.guard_interval = OFDM_GI_1_4;
			break;
		case 4://Guard 1/128
			pInfo->dvbt2_ofdm.guard_interval = OFDM_GI_1_128;
			break;
		case 5://Guard 19/128
			pInfo->dvbt2_ofdm.guard_interval = OFDM_GI_19_128;
			break;
		case 6://Guard 19/256
		default:
			pInfo->dvbt2_ofdm.guard_interval = OFDM_GI_19_256;
			break;
		}

		switch (code_rate) {
		case 0://Code Rate 1/2
			pInfo->dvbt2_ofdm.code_rate_hp = OFDM_CODE_RATE_1_2;
			break;
		case 1://Code Rate 3/5
			pInfo->dvbt2_ofdm.code_rate_hp = OFDM_CODE_RATE_3_5;
			break;
		case 2://Code Rate 2/3
			pInfo->dvbt2_ofdm.code_rate_hp = OFDM_CODE_RATE_2_3;
			break;
		case 3://Code Rate 3/4
			pInfo->dvbt2_ofdm.code_rate_hp = OFDM_CODE_RATE_3_4;
			break;
		case 4://Code Rate 4/5
			pInfo->dvbt2_ofdm.code_rate_hp = OFDM_CODE_RATE_4_5;
			break;
		case 5://Code Rate 5/6
		default:
			pInfo->dvbt2_ofdm.code_rate_hp = OFDM_CODE_RATE_5_6;
			break;
		}

		switch (constellation) {
		case 0://QPSK
			pInfo->dvbt2_ofdm.constellation = OFDM_CONST_4;
			break;
		case 1://16QAM
			pInfo->dvbt2_ofdm.constellation = OFDM_CONST_16;
			break;
		case 2://64QAM
			pInfo->dvbt2_ofdm.constellation = OFDM_CONST_64;
			break;
		case 3://256QAM
		default:
			pInfo->dvbt2_ofdm.constellation = OFDM_CONST_256;
			break;
		}

		pInfo->dvbt2_ofdm.cell_ID = cell_id;
		pInfo->dvbt2_ofdm.bSpectrumInv = spec_inv;

		REALTEK_I_DVBT2_INFO("T2::GetSignalInfo, FFT = %u, GUARD = %u, CODE_RATE = %u, CONSTELLATION = %u, CELL_ID = %u, bSpectrumInv = %u, bandwidth = %d\n",
						   pInfo->dvbt2_ofdm.fft_mode, pInfo->dvbt2_ofdm.guard_interval, pInfo->dvbt2_ofdm.code_rate_hp, pInfo->dvbt2_ofdm.constellation, pInfo->dvbt2_ofdm.cell_ID, pInfo->dvbt2_ofdm.bSpectrumInv, pInfo->dvbt2_ofdm.bandwidth);
	} else {
		pInfo->dvbt2_ofdm.bandwidth = pRealtekIDVBT2->m_current_bw;
		pInfo->mod = TV_MODULATION_OFDM;
		pInfo->dvbt2_ofdm.plp_cnt = 1;

		pDemodKernel->Lock(pDemodKernel);
               pDemod->SetDvbTStatCtrl(pDemod, 0); 
		pDemod->GetVirtualRegister(pDemod, DVBT_REG_TUN_SPECT_INV, &spec_inv);      //spec_inv
		pDemod->GetVirtualRegister(pDemod, DVBT_REG_TUN_HIERARCHICAL, &profile);    //profile
		pDemod->GetVirtualRegister(pDemod, DVBT_REG_TUN_ALPHA, &hierarchy);         //hierarchy
		pDemod->GetVirtualRegister(pDemod, DVBT_REG_TUN_FFT, &fft_size);            //fft_size
		pDemod->GetVirtualRegister(pDemod, DVBT_REG_TUN_GUARD, &guard);             //guardInterval
		pDemod->GetDvbTTunCodeRate(pDemod, &code_rate);                             //codeRate
		pDemod->GetDvbTTunMod(pDemod, &constellation);                              //constellation
		pDemod->GetVirtualRegister(pDemod, DVBT_REG_STAT_CELL_ID, &cell_id);                //cell id 

		pDemodKernel->Unlock(pDemodKernel);

		pInfo->dvbt2_ofdm.bSpectrumInv = spec_inv;
		pInfo->dvbt2_ofdm.bProfileHP = profile ? 0 : 1;
		switch (hierarchy) {
		case 0://Alpha 0
			pInfo->dvbt2_ofdm.hierarchy = OFDM_ALPHA_0;
			break;
		case 1://Alpha 1
			pInfo->dvbt2_ofdm.hierarchy = OFDM_ALPHA_1;
			break;
		case 2://Alpha 2
			pInfo->dvbt2_ofdm.hierarchy = OFDM_ALPHA_2;
			break;
		case 3://Alpha 4
			pInfo->dvbt2_ofdm.hierarchy = OFDM_ALPHA_4;
			break;
		}
		switch (fft_size) {
		case 0://FFT 8k
			pInfo->dvbt2_ofdm.fft_mode = OFDM_FFT_8K;
			break;
		case 1://FFT 4k
			pInfo->dvbt2_ofdm.fft_mode = OFDM_FFT_4K;
			break;
		case 2://FFT 2k
			pInfo->dvbt2_ofdm.fft_mode = OFDM_FFT_2K;
			break;
		}
		switch (guard) {
		case 0://Guard 1/4
			pInfo->dvbt2_ofdm.guard_interval = OFDM_GI_1_4;
			break;
		case 1://Guard 1/8
			pInfo->dvbt2_ofdm.guard_interval = OFDM_GI_1_8;
			break;
		case 2://Guard 1/16
			pInfo->dvbt2_ofdm.guard_interval = OFDM_GI_1_16;
			break;
		case 3://Guard 1/32
			pInfo->dvbt2_ofdm.guard_interval = OFDM_GI_1_32;
			break;
		}
		switch (code_rate) {
		case 0://Code Rate 1/2
			pInfo->dvbt2_ofdm.code_rate_hp = OFDM_CODE_RATE_1_2;
			break;
		case 1://Code Rate 2/3
			pInfo->dvbt2_ofdm.code_rate_hp = OFDM_CODE_RATE_2_3;
			break;
		case 2://Code Rate 3/4
			pInfo->dvbt2_ofdm.code_rate_hp = OFDM_CODE_RATE_3_4;
			break;
		case 3://Code Rate 5/6
			pInfo->dvbt2_ofdm.code_rate_hp = OFDM_CODE_RATE_5_6;
			break;
		case 4://Code Rate 7/8
			pInfo->dvbt2_ofdm.code_rate_hp = OFDM_CODE_RATE_7_8;
			break;
		}
		switch (constellation) {
		case 0://QPSK
			pInfo->dvbt2_ofdm.constellation = OFDM_CONST_4;
			break;
		case 1://16QAM
			pInfo->dvbt2_ofdm.constellation = OFDM_CONST_16;
			break;
		case 2://64QAM
			pInfo->dvbt2_ofdm.constellation = OFDM_CONST_64;
			break;
		}

		pInfo->dvbt2_ofdm.cell_ID = cell_id;

		REALTEK_I_DVBT2_INFO("T::GetSignalInfo, SPEC_INV = %u, PROFILE = %u, ALPHA = %u, FFT = %u, GUARD = %u, CODE_RATE = %u, CONSTELLATION = %u, bandwidth = %d, , CELL_ID=%d\n",
						   pInfo->dvbt2_ofdm.bSpectrumInv, pInfo->dvbt2_ofdm.bProfileHP, pInfo->dvbt2_ofdm.hierarchy, pInfo->dvbt2_ofdm.fft_mode, pInfo->dvbt2_ofdm.guard_interval, pInfo->dvbt2_ofdm.code_rate_hp, pInfo->dvbt2_ofdm.constellation, pInfo->dvbt2_ofdm.bandwidth, pInfo->dvbt2_ofdm.cell_ID);
	}




#ifdef SUPPORT_WINTOOL
	}
#endif

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
int REALTEK_I_DVBT2_GetSignalQuality(DEMOD* pDemodKernel, ENUM_TV_QUAL id,    TV_SIG_QUAL* pQuality)
{
	unsigned int Snr, Ber, Per, Ubc, Sqi, PakN, BchFer, BadPakN, Agc;
	int ret = TUNER_CTRL_OK;
    unsigned int code_rate = 0, constellation = 0, Sqi_CR = 0, Sqi_QamMode = 0;
    

	REALTEK_I_DVBT2* pRealtekIDVBT2;
	DVBT2_DEMOD_MODULE* pDemod;
	pRealtekIDVBT2 = (REALTEK_I_DVBT2*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_DVBT2_DRIVER_DATA*) pRealtekIDVBT2->m_private)->pDemod;

	if (!DtvIsDemodClockEnable(RTK_DEMOD_MODE_DVBT2))
		return TUNER_CTRL_FAIL;

	pDemodKernel->Lock(pDemodKernel);

#ifdef SUPPORT_WINTOOL
	if (!pRealtekIDVBT2->m_debug_tool_en) {
#endif




	if (pRealtekIDVBT2->m_dvbt2_dvbt_mode == REALTEK_I_DVBT2_MODE) {
		ret |= DECODE_RET(pDemod->DemodCtrlUpdateCounters(pDemod));
	} else {
		ret |= DECODE_RET(pDemod->SetDvbTStatCtrl(pDemod, 0));
	}

	switch (id) {
	case TV_QUAL_SNR: {
		if (pRealtekIDVBT2->m_dvbt2_dvbt_mode == REALTEK_I_DVBT2_MODE) {
			ret |= DECODE_RET(pDemod->GetSymCsiSnr(pDemod, &Snr));
			pQuality->snr = (Snr * 100) / 328;//(Snr * 10000) / 32768
			ret |= DECODE_RET(pDemod->DemodCtrlResetCounters(pDemod));
		} else {
			ret |= DECODE_RET(pDemod->GetDvbTSnr(pDemod, &Snr));
			pQuality->snr = (Snr * 100);//(Snr * 10000) / 100
			ret |= DECODE_RET(pDemod->SetDvbTStatCtrl(pDemod, 1));
		}
	}
	break;
	case TV_QUAL_BER: {
		if (pRealtekIDVBT2->m_dvbt2_dvbt_mode == REALTEK_I_DVBT2_MODE) {
			ret |= DECODE_RET(pDemod->GetDataBchInputBer(pDemod, &Ber));
			pQuality->ber = (Ber * 10000) / 4294967296;
		} else {
			ret |= DECODE_RET(pDemod->GetDvbTRsBer(pDemod, &Ber));
			pQuality->ber = (Ber * 10000) / 4294967296;
		}
	}
	break;
	case TV_QUAL_PER: {
		if (pRealtekIDVBT2->m_dvbt2_dvbt_mode == REALTEK_I_DVBT2_MODE) {
			ret |= DECODE_RET(pDemod->GetDataBchOutputFer(pDemod, &Per));
			pQuality->per = (Per * 10000) / 4294967296;
		} else {
			ret |= DECODE_RET(pDemod->GetDvbTTsPer(pDemod, &Per));
			pQuality->per = (Per * 10000) / 4294967296;
		}
	}
	break;
	case TV_QUAL_UCBLOCKS: {
		if (pRealtekIDVBT2->m_dvbt2_dvbt_mode == REALTEK_I_DVBT2_MODE) {
			pQuality->ucblocks = 0;
		} else {
			ret |= DECODE_RET(pDemod->GetDvbTTsBadPktCount(pDemod, &Ubc));
			if (Ubc >= pRealtekIDVBT2->m_PreUbc)
				pQuality->ucblocks = Ubc - pRealtekIDVBT2->m_PreUbc;
			else
				pQuality->ucblocks = Ubc + ((2 ^ 32) - pRealtekIDVBT2->m_PreUbc);
			pRealtekIDVBT2->m_PreUbc = Ubc;
		}
	}
	break;
	case TV_QUAL_SIGNAL_STRENGTH: {
		if (pRealtekIDVBT2->m_dvbt2_dvbt_mode == REALTEK_I_DVBT2_MODE) {
			pQuality->strength = REALTEK_I_DVBT2_CalDvbT2Ssi(pDemodKernel, (int)(pQuality->rflevel));
            REALTEK_I_DVBT2_INFO("\033[1;32;32m" "DVBT2_CalDvbT2Ssi = %d\n""\033[m", (int)(pQuality->rflevel));
			pRealtekIDVBT2->m_dvbt2_Ssi = pQuality->strength;
		} else {
			pQuality->strength = REALTEK_I_DVBT2_CalDvbTSsi(pDemodKernel, (int)(pQuality->rflevel));
            REALTEK_I_DVBT2_INFO("\033[1;32;32m""DVBT_CalDvbTSsi = %d\n""\033[m", (int)(pQuality->rflevel));
			pRealtekIDVBT2->m_dvbt2_dvbt_Ssi = pQuality->strength;
		}
	}
	break;
	case TV_QUAL_SIGNAL_QUALITY: {
		if (pRealtekIDVBT2->m_dvbt2_dvbt_mode == REALTEK_I_DVBT2_MODE) {
			ret |= DECODE_RET(pDemod->GetSqi(pDemod, &Sqi));
            
            REALTEK_I_DVBT2_INFO("DVBT2_SQI = %d\n", Sqi);
			pQuality->quality = Sqi;
                        
		} 
        else {
            pDemodKernel->Lock(pDemodKernel);
            Sqi_CR = 0;
            Sqi_QamMode = 0;
            ret |= DECODE_RET(pDemod->SetDvbTStatCtrl(pDemod, 0));				
		    ret |= DECODE_RET(pDemod->GetDvbTTunCodeRate(pDemod, &code_rate));   //Get codeRate
		    ret |= DECODE_RET(pDemod->GetDvbTTunMod(pDemod, &constellation));    //Get constellation
		    Sqi_CR = code_rate;
            Sqi_QamMode = constellation;
            pDemodKernel->Unlock(pDemodKernel);
		    
            ret |= DECODE_RET(pDemod->GetDvbTSqi(pDemod, &Sqi));				//Get SQI
            ret |= DECODE_RET(pDemod->GetDvbTSnr(pDemod, &Snr));				//Get SNR
            ret |= DECODE_RET(pDemod->SetDvbTStatCtrl(pDemod, 1));				//Reset 
            ret |= DECODE_RET(pDemod->GetDvbTRsBer(pDemod, &Ber));
            if((constellation == 2 )&&((code_rate ==1)||(code_rate == 2))){     //{64QAM, CR=2/3} and {64QAM, CR=3/4} SQI recalculate
                //--- SNR < 21dB, offset SQI value------//
                if(Snr <=2100){
                    if(Snr < 2000){
                        Sqi=(Sqi>18)? Sqi-18:Sqi; //20dB < SNR, SQI-18
                    }
                    else{
                        Sqi=(Sqi>10)? Sqi-10:Sqi; //20dB <= SNR =< 2100, SQI-10
                    }
                }
            }
            
			pQuality->quality = Sqi;            //SNR > 21 dB, didn't offset SQI
            REALTEK_I_DVBT2_INFO("DVBT_SQI = %d\n", Sqi);
		}
	}
	break;
	case TV_QUAL_AGC:
		Agc = (rtd_inl(DEMOD_SD_SIGMA_DELTA_INPUT_reg) >> 12) & 0x7ff;
		Agc =  Agc * 100 / 0x7ff;
		pQuality->agc = Agc;
		break;
	case TV_QUAL_BEC: {
		if (pRealtekIDVBT2->m_dvbt2_dvbt_mode == REALTEK_I_DVBT2_MODE) {
			ret |= pDemod->GetDataPackets(pDemod, &PakN);
			ret |= pDemod->GetTsBadPackets(pDemod, &BadPakN);

			if (PakN > 0) {
				pQuality->layer_ber.ber_num = BadPakN * 36;
				pQuality->layer_ber.ber_den = (PakN * 204 * 8);
			}  else  {
				pQuality->layer_ber.ber_num = 0xffffffff;
				pQuality->layer_ber.ber_den = 0xffffffff;
			}
		} else {
			ret |= pDemod->GetDvbTTsPktCnt(pDemod, &PakN);
			ret |= pDemod->GetDvbTTsBadPktCount(pDemod, &BadPakN);
			if (PakN > 0) {
				pQuality->layer_ber.ber_num = BadPakN * 36;
				pQuality->layer_ber.ber_den = (PakN * 204 * 8);
			}  else  {
				pQuality->layer_ber.ber_num = 0xffffffff;
				pQuality->layer_ber.ber_den = 0xffffffff;
			}
		}
	}
	break;
	case TV_QUAL_PEC: {
		if (pRealtekIDVBT2->m_dvbt2_dvbt_mode == REALTEK_I_DVBT2_MODE) {
			ret |= pDemod->GetDataPackets(pDemod, &PakN);
			ret |= pDemod->GetTsBadPackets(pDemod, &BadPakN);

			if (PakN > 0) {
				pQuality->layer_per.per_num = BadPakN;
				pQuality->layer_per.per_den = PakN;
			} else  {
				pQuality->layer_per.per_num = 0xffffffff;
				pQuality->layer_per.per_den = 0xffffffff;
			}
		} else {
			ret |= pDemod->GetDvbTTsPktCnt(pDemod, &PakN);
			ret |= pDemod->GetDvbTTsBadPktCount(pDemod, &BadPakN);
			if (PakN > 0) {
				pQuality->layer_per.per_num = BadPakN;
				pQuality->layer_per.per_den = PakN;
			}  else  {
				pQuality->layer_ber.ber_num = 0xffffffff;
				pQuality->layer_ber.ber_den = 0xffffffff;
			}
		}
	}
	break;
	case TV_QUAL_DEMODFWVERSION:
		pQuality->DemodFwVersion = 0x000001;
		break;

	case TV_QUAL_CUSTOMER_LG:

		if (pRealtekIDVBT2->m_dvbt2_dvbt_mode == REALTEK_I_DVBT2_MODE) {
			pQuality->strength = REALTEK_I_DVBT2_CalDvbT2Ssi(pDemodKernel, (int)pQuality->rflevel);
			ret |= DECODE_RET(pDemod->GetSqi(pDemod, &Sqi));
			ret |= pDemod->GetDataPackets(pDemod, &PakN);
			ret |= pDemod->GetTsBadPackets(pDemod, &BadPakN);
			ret |= DECODE_RET(pDemod->GetSymCsiSnr(pDemod, &Snr));
			ret |= DECODE_RET(pDemod->DemodCtrlResetCounters(pDemod));

			pRealtekIDVBT2->m_dvbt2_Ssi = pQuality->strength;
			pQuality->quality = Sqi;
			pQuality->snr = (Snr * 100) / 328;//(Snr * 10000) / 32768

			if (PakN > 0) {
				pQuality->layer_per.per_num = BadPakN;
				pQuality->layer_per.per_den = PakN;
				pQuality->layer_ber.ber_num = BadPakN * 36;
				pQuality->layer_ber.ber_den = (PakN * 204 * 8);
			} else  {
				pQuality->layer_per.per_num = 0xffffffff;
				pQuality->layer_per.per_den = 0xffffffff;
				pQuality->layer_ber.ber_num = 0xffffffff;
				pQuality->layer_ber.ber_den = 0xffffffff;
			}


		} else {
			pQuality->strength = REALTEK_I_DVBT2_CalDvbTSsi(pDemodKernel, (int)pQuality->rflevel);
			ret |= DECODE_RET(pDemod->GetDvbTSqi(pDemod, &Sqi));
			ret |= pDemod->GetDvbTTsPktCnt(pDemod, &PakN);
			ret |= pDemod->GetDvbTTsBadPktCount(pDemod, &BadPakN);
			ret |= DECODE_RET(pDemod->GetDvbTSnr(pDemod, &Snr));
			ret |= DECODE_RET(pDemod->SetDvbTStatCtrl(pDemod, 1));

			pRealtekIDVBT2->m_dvbt2_dvbt_Ssi = pQuality->strength;
			pQuality->quality = Sqi;
			pQuality->snr = (Snr * 100);//(Snr * 10000) / 100


			if (PakN > 0) {
				pQuality->layer_per.per_num = BadPakN;
				pQuality->layer_per.per_den = PakN;
				pQuality->layer_ber.ber_num = BadPakN * 36;
				pQuality->layer_ber.ber_den = (PakN * 204 * 8);
			}  else  {
				pQuality->layer_ber.ber_num = 0xffffffff;
				pQuality->layer_ber.ber_den = 0xffffffff;
				pQuality->layer_ber.ber_num = 0xffffffff;
				pQuality->layer_ber.ber_den = 0xffffffff;
			}

		}

			Agc = (rtd_inl(DEMOD_SD_SIGMA_DELTA_INPUT_reg) >> 12) & 0xfff;
			Agc =  Agc * 100 / 0xfff;
		pQuality->agc = Agc;
		REALTEK_I_DVBT2_INFO("\033[1;32;31m" "IsDVBT=%d,  SNR = %u, AGC=%u, pkt_error=%u, total_pkt = %u\n" "\033[m", pRealtekIDVBT2->m_dvbt2_dvbt_mode, pQuality->snr, pQuality->agc, pQuality->layer_per.per_num, pQuality->layer_per.per_den);

		break;

	default:
		break;
	}




#ifdef SUPPORT_WINTOOL
	}
#endif

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
int REALTEK_I_DVBT2_GetCarrierOffset(DEMOD* pDemodKernel, long* pOffset)
{
	int ret = TUNER_CTRL_OK;
	REALTEK_I_DVBT2* pRealtekIDVBT2;
	DVBT2_DEMOD_MODULE* pDemod;
	pRealtekIDVBT2 = (REALTEK_I_DVBT2*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_DVBT2_DRIVER_DATA*) pRealtekIDVBT2->m_private)->pDemod;
	unsigned int Cfo = 0;

	if (!DtvIsDemodClockEnable(RTK_DEMOD_MODE_DVBT2))
		return TUNER_CTRL_FAIL;

	pDemodKernel->Lock(pDemodKernel);

#ifdef SUPPORT_WINTOOL
	if (!pRealtekIDVBT2->m_debug_tool_en) {
#endif


	if (pRealtekIDVBT2->m_dvbt2_dvbt_mode == REALTEK_I_DVBT2_MODE) {
		pDemod->GetVirtualRegister(pDemod, DVBT2_REG_SYM_CFO_HZ, &Cfo);
		*pOffset = - Cfo;
	} else {
	       ret |= DECODE_RET(pDemod->SetDvbTStatCtrl(pDemod, 0)); 
		ret |= pDemod->GetDvbTCfo(pDemod, &Cfo);
		*pOffset = Cfo;
	}

	pDemodKernel->Unlock(pDemodKernel);
	REALTEK_I_DVBT2_DBG("GetCarrierOffset=%ldHz\n", *pOffset);




#ifdef SUPPORT_WINTOOL
	}
#endif

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
int REALTEK_I_DVBT2_GetDebugLogBuf(DEMOD* pDemodKernel, unsigned int* LogBufAddr, unsigned int* LogBufSize)
{
	int ret = TUNER_CTRL_OK;
	REALTEK_I_DVBT2* pRealtekIDVBT2;
	DVBT2_DEMOD_MODULE* pDemod;
	pRealtekIDVBT2 = (REALTEK_I_DVBT2*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_DVBT2_DRIVER_DATA*) pRealtekIDVBT2->m_private)->pDemod;
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
int REALTEK_I_DVBT2_AcquireSignal(DEMOD* pDemodKernel, unsigned char WaitSignalLock)
{

	unsigned long cur_time;

	REALTEK_I_DVBT2* pRealtekIDVBT2;
	DVBT2_DEMOD_MODULE* pDemod;
	pRealtekIDVBT2 = (REALTEK_I_DVBT2*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_DVBT2_DRIVER_DATA*) pRealtekIDVBT2->m_private)->pDemod;

#ifdef SUPPORT_WINTOOL
	pRealtekIDVBT2->m_debug_tool_en = 0;
#endif

	if (WaitSignalLock == 0)
		return TUNER_CTRL_OK;

#ifdef CONFIG_RTK_KDRV_DEMOD_SCAN_THREAD_ENABLE

	cur_time = tv_osal_time();

	while ((tv_osal_time() - cur_time) <= 15) {
		if (pRealtekIDVBT2->m_acquire_sig_en == 0)
			return TUNER_CTRL_OK;
		tv_osal_msleep(5);
	}

	return TUNER_CTRL_FAIL;

#else

	REALTEK_I_DVBT2_AcquireSignalThread(pDemodKernel);
	pRealtekIDVBT2->m_autotune_stime = tv_osal_time() + AUTODETECT_SIG_UPDATE_INTERVAL_MS;
	return TUNER_CTRL_OK;

#endif



}


/*----------------------------------------------------------------------
 * Func : AcquireSignalThread
 *
 * Desc : Reset Demodulator and Acquire Signal.
 *        This function should be called when channel changed.
 *
 * Parm :
 *
 * Retn : TUNER_CTRL_OK / TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBT2_AcquireSignalThread(DEMOD* pDemodKernel)
{
	unsigned long   det_stime = 0, acq_stime = 0, det_timeout = 900;
	unsigned char   lock = 0;
	unsigned int    DemodStatus = 0, IsNoSignal = 0, DetectStatus = 0;
	unsigned int    StandardSeatchStatus = 0, StandardSeatchResult = 0;
	unsigned int    ActivePlpId = 0, TsPktCnt = 0;
	TV_SYSTEM_TYPE TvSysMode, DetectionTvSysTpe;
	int             ret = TUNER_CTRL_OK;
	unsigned int TotalAcqTime = 0, HWAcqTime = 0;

	REALTEK_I_DVBT2* pRealtekIDVBT2;
	DVBT2_DEMOD_MODULE* pDemod;
	pRealtekIDVBT2 = (REALTEK_I_DVBT2*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_DVBT2_DRIVER_DATA*) pRealtekIDVBT2->m_private)->pDemod;


	if (pRealtekIDVBT2->m_acquire_sig_en == 0)
		return TUNER_CTRL_OK;

	REALTEK_I_DVBT2_INFO("\033[1;32;32m" "%s %s %d\n" "\033[m", __FILE__, __func__, __LINE__);


	pDemodKernel->Lock(pDemodKernel);


	if (pRealtekIDVBT2->m_fastscan_en) {

		det_stime = tv_osal_time();

		StandardSeatchStatus = 0;
		while (StandardSeatchStatus < 9 && (tv_osal_time() - det_stime) <= 850) {
			tv_osal_msleep(5);
			ret |= DECODE_RET(pDemod->GetDvbT2DvbTSearchResult(pDemod, &StandardSeatchStatus, &StandardSeatchResult));
		}
		REALTEK_I_DVBT2_INFO("\033[1;32;31m" "BW=%d, Detect Result Status=%d Result=%x Detect Time=%d, total_acquire_time = %lu\n" "\033[m", pRealtekIDVBT2->m_current_bw, StandardSeatchStatus, StandardSeatchResult, tv_osal_time() - det_stime, tv_osal_time() - acquire_sig_stime);
		//REALTEK_I_DVBT2_INFO("\033[1;32;31m" "BW=%d, Detect Result Status=%d Result=%x Detect Time=%d\n" "\033[m", pRealtekIDVBT2->m_current_bw, StandardSeatchStatus, StandardSeatchResult, tv_osal_time() - det_stime);


		if (StandardSeatchStatus < 9) {
			REALTEK_I_DVBT2_INFO("\033[1;32;32m" "Fast Scan Timeout\n" "\033[m");
			goto acquire_signal_done;

		} else {
			if (pRealtekIDVBT2->m_current_bw == 8000000)
				StandardSeatchResult = StandardSeatchResult & DVBTT2_FAST_SCAN_RESULT_8M_MASK;
			else if (pRealtekIDVBT2->m_current_bw == 7000000)
				StandardSeatchResult = StandardSeatchResult & DVBTT2_FAST_SCAN_RESULT_7M_MASK;
			else if (pRealtekIDVBT2->m_current_bw == 6000000)
				StandardSeatchResult = StandardSeatchResult & DVBTT2_FAST_SCAN_RESULT_6M_MASK;
			else if (pRealtekIDVBT2->m_current_bw == 5000000)
				StandardSeatchResult = StandardSeatchResult & DVBTT2_FAST_SCAN_RESULT_5M_MASK;

			if (StandardSeatchResult == 0) {
				REALTEK_I_DVBT2_INFO("\033[1;32;32m" "Detect No Signal\n" "\033[m");
				goto acquire_signal_done;

			} else if (StandardSeatchResult >= 0x1000) {
				REALTEK_I_DVBT2_INFO("\033[1;32;32m" "Detect DVBT2 BW=%dHz\n" "\033[m", pRealtekIDVBT2->m_current_bw);
				DetectionTvSysTpe = TV_SYS_TYPE_DVBT2;

			} else if (StandardSeatchResult < 0x1000) {
				REALTEK_I_DVBT2_INFO("\033[1;32;32m" "Detect DVBT BW=%dHz\n" "\033[m", pRealtekIDVBT2->m_current_bw);
				DetectionTvSysTpe = TV_SYS_TYPE_DVBT;
			}
		}

		if (DetectionTvSysTpe == TV_SYS_TYPE_DVBT2) {
			DetectStatus = 1;//Wait for DVBT2 Lock
			det_timeout = 1300;
		} else if (DetectionTvSysTpe == TV_SYS_TYPE_DVBT) {

			ret |= REALTEK_I_DVBT2_ChangeStandard(pDemodKernel, REALTEK_I_DVBT_MODE);
			DetectStatus = 2;//Wait for DVBT Lock
			//tv_osal_msleep(50);

			//ret |= DECODE_RET(pDemod->DemodCtrlStop(pDemod));
			ret |= DECODE_RET(pDemod->SetTunerBandwidth(pDemod, pRealtekIDVBT2->m_current_bw));//Change Bandwidth
			ret |= DECODE_RET(pDemod->SetTunerFreq(pDemod, 666000000));//Set Frequency and Bandwidth together
			ret |= DECODE_RET(pDemod->SetDvbTDetectMask(pDemod, pRealtekIDVBT2->m_dvbt_bandwidth_mask));//Set DVBT bandwidth filter
			ret |= DECODE_RET(pDemod->DemodCtrlDetect(pDemod));
			det_timeout = 1600;
		}


	} else {

		if (pRealtekIDVBT2->m_dvbt2_dvbt_mode == REALTEK_I_DVBT2_MODE) {
			DetectStatus = 1;//Wait for DVBT2 Lock
			det_timeout = 1300;
		} else {
			DetectStatus = 2;//Wait for DVBT Lock
			det_timeout = 1600;
		}
	}

	lock = NO;
	acq_stime = tv_osal_time();

	while ((tv_osal_time() - acq_stime) <= det_timeout) {
		tv_osal_msleep(5);

		ret |= DECODE_RET(pDemod->GetDemodStatus(pDemod, &DemodStatus));

		if (DemodStatus == 5) {
			lock = YES;
			pRealtekIDVBT2->m_PreUbc = 0;
			break;
		}


		if (acq_stime > tv_osal_time())
			acq_stime = 0;
	}

#if 0
	TotalAcqTime = tv_osal_time() - acquire_sig_stime;
	ret |= DECODE_RET(pDemod->GetDemodLockTime(pDemod, &HWAcqTime));

	REALTEK_I_DVBT2_INFO("\033[1;32;32m" "DVBT(2)/T2(1) Mode standard = %d,  signal lock = %u, TsPktCnt=%u, Lock driver time = %lu, HW_time = %lu, total_acquire_time = %lu\n" "\033[m", DetectStatus, lock, TsPktCnt, tv_osal_time() - acq_stime, HWAcqTime, TotalAcqTime);
#else

	REALTEK_I_DVBT2_INFO("\033[1;32;32m" "DVBT(2)/T2(1) Mode standard = %d,  signal lock = %u, Lock driver time = %lu, total_acquire_time = %lu\n" "\033[m", DetectStatus, lock, tv_osal_time() - acq_stime, tv_osal_time() - acquire_sig_stime);

#endif


acquire_signal_done:
	pDemodKernel->Unlock(pDemodKernel);
	pRealtekIDVBT2->m_acquire_sig_en = 0;
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
int REALTEK_I_DVBT2_ScanSignal(DEMOD* pDemodKernel, long* pOffset, SCAN_RANGE range)
{
	REALTEK_I_DVBT2* pRealtekIDVBT2;
	DVBT2_DEMOD_MODULE* pDemod;
	pRealtekIDVBT2 = (REALTEK_I_DVBT2*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_DVBT2_DRIVER_DATA*) pRealtekIDVBT2->m_private)->pDemod;

	//REALTEK_I_DVBT2_INFO("\033[1;32;31m" "%s %s %d\n" "\033[m", __FILE__, __func__, __LINE__);

	pDemodKernel->Lock(pDemodKernel);

	pDemodKernel->Unlock(pDemodKernel);

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
int REALTEK_I_DVBT2_ForwardI2C(DEMOD* pDemodKernel, unsigned char on_off)
{
	int ret = TUNER_CTRL_OK;

	REALTEK_I_DVBT2* pRealtekIDVBT2;
	DVBT2_DEMOD_MODULE* pDemod;
	pRealtekIDVBT2 = (REALTEK_I_DVBT2*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_DVBT2_DRIVER_DATA*) pRealtekIDVBT2->m_private)->pDemod;

	//REALTEK_I_DVBT2_INFO("\033[1;32;31m" "%s %s %d\n" "\033[m", __FILE__, __func__, __LINE__);

	pDemodKernel->Lock(pDemodKernel);

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
int REALTEK_I_DVBT2_AutoTune(DEMOD* pDemodKernel)
{
	int ret = TUNER_CTRL_OK;

#ifdef SUPPORT_WINTOOL
	REALTEK_I_DVBT2* pRealtekIDVBT2;
	pRealtekIDVBT2 = (REALTEK_I_DVBT2*)(pDemodKernel->private_data);
	DVBT2_DEMOD_MODULE* pDemod = ((REALTEK_I_DVBT2_DRIVER_DATA*) pRealtekIDVBT2->m_private)->pDemod;

	unsigned int dbg_pri_addr = 0, dbg_sec_addr = 0, dbg_val = 0, ConstData = 0, u8i = 0;
	
	if (rtd_inl(DEBUG_MODE_EN_ADDRESS) == 0x00022243) {
        REALTEK_I_DVBT2_INFO("\033[1;32;33m" "WINTOOL ENABLED\n" "\033[m");
		if (rtd_inl(DEBUG_MODE_SEL_ADDRESS) == 0xFFFFFFFF) { //Dump All Virtual Register
			pRealtekIDVBT2->m_debug_tool_en = 1;
			if (rtd_inl(HANDSHAKE_ADDRESS) == 0x00000001) { //tool done
				ret |= DECODE_RET(pDemod->DemodCtrlUpdateCounters(pDemod));
				for (dbg_pri_addr = 0; dbg_pri_addr <= 4; dbg_pri_addr++) {
					ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, dbg_pri_addr, &dbg_val));
					rtd_outl(COMMON_BASE_ADDRESS+dbg_pri_addr*4, dbg_val);
				}
				
				for (dbg_pri_addr = 0; dbg_pri_addr <= (DVBT2_REG_TOTALREG - TV_REG_NUM_COMMON_REG); dbg_pri_addr++) {
					ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, (0x8000+dbg_pri_addr), &dbg_val));
					rtd_outl(VR_BASE_ADDRESS+dbg_pri_addr*4, dbg_val);
				}
				//EQ/HD Constellation
				/*
				for(u8i = 0; u8i < 6; u8i++)
				{
					pDemod->GetHwRegister(pDemod, IMG_DEMOD_DVBT2_EQ_CONST_ADDRESS+u8i*4, &ConstData);
					rtd_outl(CONSTELL_EQ_ADDRESS+u8i*4, ConstData);
					
					pDemod->GetHwRegister(pDemod, IMG_DEMOD_DVBT2_HD_CONST_ADDRESS+u8i*4, &ConstData);
					rtd_outl(CONSTELL_HD_ADDRESS+u8i*4, ConstData);
				}
				*/
				
				rtd_outl(HANDSHAKE_ADDRESS, 0x00000002);//driver done
			}
		} else if (rtd_inl(DEBUG_MODE_SEL_ADDRESS) == 0xFFFFFFFE) { //GetVirtualRegister
			pRealtekIDVBT2->m_debug_tool_en = 1;
			if (rtd_inl(HANDSHAKE_ADDRESS) == 0x00000001) { //tool done
				dbg_pri_addr = rtd_inl(PRI_VR_INDEX_ADDRESS);//get vr index
				dbg_sec_addr = rtd_inl(SEC_VR_INDEX_ADDRESS);//get vr index
				ret |= DECODE_RET(pDemod->GetCtrlVirtualRegister(pDemod, dbg_pri_addr, dbg_sec_addr, &dbg_val));
				rtd_outl(VR_VALUE_ADDRESS, dbg_val);//get vr value

				rtd_outl(HANDSHAKE_ADDRESS, 0x00000002);//driver done
			}
		} else if (rtd_inl(DEBUG_MODE_SEL_ADDRESS) == 0xFFFFFFFD) { //SetVirtualRegister
			pRealtekIDVBT2->m_debug_tool_en = 1;
			if (rtd_inl(HANDSHAKE_ADDRESS) == 0x00000001) { //tool done
				dbg_pri_addr = rtd_inl(PRI_VR_INDEX_ADDRESS);//get vr index
				dbg_sec_addr = rtd_inl(SEC_VR_INDEX_ADDRESS);//get vr index
				dbg_val = rtd_inl(VR_VALUE_ADDRESS);//get vr value
				ret |= DECODE_RET(pDemod->SetCtrlVirtualRegister(pDemod, dbg_pri_addr, dbg_sec_addr, dbg_val));

				rtd_outl(HANDSHAKE_ADDRESS, 0x00000002);//driver done
			}
		}
	}
#endif

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
int REALTEK_I_DVBT2_KernelAutoTune(DEMOD* pDemodKernel)
{

	unsigned long cur_time ;
	int             ret = TUNER_CTRL_OK;
	TV_SYSTEM_TYPE TvSysMode;

	REALTEK_I_DVBT2* pRealtekIDVBT2;
	DVBT2_DEMOD_MODULE* pDemod;
	pRealtekIDVBT2 = (REALTEK_I_DVBT2*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_DVBT2_DRIVER_DATA*) pRealtekIDVBT2->m_private)->pDemod;

	cur_time = tv_osal_time();


	if (pRealtekIDVBT2->m_acquire_sig_en) {
#ifdef CONFIG_RTK_KDRV_DEMOD_SCAN_THREAD_ENABLE
		REALTEK_I_DVBT2_AcquireSignalThread(pDemodKernel);
		pRealtekIDVBT2->m_autotune_stime = tv_osal_time() + AUTODETECT_SIG_UPDATE_INTERVAL_MS;
#endif



#ifdef SUPPORT_DEMOD_AUTOTEST
	} else if ((cur_time > pRealtekIDVBT2->m_autotune_stime || (pRealtekIDVBT2->m_autotune_stime - cur_time) > AUTODETECT_SIG_UPDATE_INTERVAL_MS) && pRealtekIDVBT2->m_unlock_cnt > 5 && (((rtd_inl(DTV_FRONTEND_DTV_FRONTEND_DUMMY5_reg) >> 31) & 0x1) == 0x0)) {
#else
	} else if ((cur_time > pRealtekIDVBT2->m_autotune_stime || (pRealtekIDVBT2->m_autotune_stime - cur_time) > AUTODETECT_SIG_UPDATE_INTERVAL_MS) && pRealtekIDVBT2->m_unlock_cnt > 5) {
#endif

		REALTEK_I_DVBT2_INFO("\033[1;32;31m" "DVBT/T2 signal auto detection!!! unlockCnt = %u\n" "\033[m", pRealtekIDVBT2->m_unlock_cnt);
		GetDemodTvSysMode(&TvSysMode);
		if (TvSysMode != TV_SYS_TYPE_DVBT2)
			REALTEK_I_DVBT2_ChangeStandard(pDemodKernel, REALTEK_I_DVBT2_MODE);

		pRealtekIDVBT2->m_fastscan_en = 1;
		ret |= DECODE_RET(pDemod->DemodCtrlStop(pDemod));
		ret |= DECODE_RET(pDemod->SetXmlFlags(pDemod, RTK_DEMOD_XML_REAL_IF | (pDemodKernel->m_if.inversion << 1) | (RTK_DEMOD_XML_UNSIGNED << 2) | (pRealtekIDVBT2->m_dvbt2_ext_gain_dis << 3)));
		ret |= DECODE_RET(pDemod->SetDvbT2DvbTSearchMode(pDemod, 0x00000008));//Set to Auto DVBT2/DVBT Mode
		ret |= DECODE_RET(pDemod->SetDataPlpIdSelectCmd(pDemod, (unsigned int) pRealtekIDVBT2->m_plp_id));
		ret |= DECODE_RET(pDemod->SetDvbT2DvbtSearchDecisionTh1(pDemod, 0x200));
		ret |= DECODE_RET(pDemod->SetP1SearchTimeout(pDemod, 500));//P1 Time Out 500ms for FEF
		ret |= DECODE_RET(pDemod->SetDvbT2DvbTSearchResult(pDemod, 0, 0));
		ret |= DECODE_RET(pDemod->SetTunerBandwidth(pDemod, pRealtekIDVBT2->m_current_bw));//Change Bandwidth
		ret |= DECODE_RET(pDemod->SetTunerFreq(pDemod, 666000000));//Set Frequency and Bandwidth together
		ret |= DECODE_RET(pDemod->DemodCtrlRun(pDemod));
		pRealtekIDVBT2->m_acquire_sig_en = 1;
		pRealtekIDVBT2->m_unlock_cnt = 0;
		acquire_sig_stime = tv_osal_time();

		REALTEK_I_DVBT2_AcquireSignalThread(pDemodKernel);
		pRealtekIDVBT2->m_autotune_stime = tv_osal_time() + AUTODETECT_SIG_UPDATE_INTERVAL_MS;
	}


#ifdef ENABLE_LDR_LOADER
	if ((rtd_inl(0xb8000200) & 0x60) == 0x60) {
		while (1) {

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
int REALTEK_I_DVBT2_InspectSignal(DEMOD* pDemodKernel)
{
	int ret = TUNER_CTRL_OK;
	unsigned int DemodStatus, SigLock, Sqi, Snr, Ber, TsPktCnt, IfAgcGain, TsLockTime, AcqTime;
	float BerResult, SnrResult;

	REALTEK_I_DVBT2* pRealtekIDVBT2;
	DVBT2_DEMOD_MODULE* pDemod;
	pRealtekIDVBT2 = (REALTEK_I_DVBT2*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_DVBT2_DRIVER_DATA*) pRealtekIDVBT2->m_private)->pDemod;

	if (!DtvIsDemodClockEnable(RTK_DEMOD_MODE_DVBT2))
		return 0;
#if 0
	pDemodKernel->Lock(pDemodKernel);

	ret |= DECODE_RET(pDemod->GetDemodStatus(pDemod, &DemodStatus));
	if ((ret == TUNER_CTRL_OK) && (DemodStatus == 5))
		SigLock = YES;
	else
		SigLock = NO;

	if (pRealtekIDVBT2->m_dvbt2_dvbt_mode == REALTEK_I_DVBT2_MODE) {
		ret |= DECODE_RET(pDemod->GetSqi(pDemod, &Sqi));
		ret |= DECODE_RET(pDemod->GetSymCsiSnr(pDemod, &Snr));
		SnrResult = ((double)Snr) / 32768;
		ret |= DECODE_RET(pDemod->GetDataBchOutputFer(pDemod, &Ber));
		BerResult = ((double)Ber) / 4294967296;
		ret |= DECODE_RET(pDemod->GetDataPackets(pDemod, &TsPktCnt));
		ret |= DECODE_RET(pDemod->GetTsLockTime(pDemod, &TsLockTime));
	} else {
		ret |= DECODE_RET(pDemod->SetDvbTStatCtrl(pDemod, 0));//Update Status

		ret |= DECODE_RET(pDemod->GetDvbTSqi(pDemod, &Sqi));
		ret |= DECODE_RET(pDemod->GetDvbTSnr(pDemod, &Snr));
		SnrResult = ((double)Snr) / 100;
		ret |= DECODE_RET(pDemod->GetDvbTRsBer(pDemod, &Ber));
		BerResult = ((double)Ber) / 4294967296;
		ret |= DECODE_RET(pDemod->GetDvbTTsPktCnt(pDemod, &TsPktCnt));
	}
	ret |= DECODE_RET(pDemod->GetIfAgcGain(pDemod, &IfAgcGain));
	IfAgcGain = IfAgcGain >> 20;

	ret |= DECODE_RET(pDemod->GetDemodLockTime(pDemod, &AcqTime));
	AcqTime /= 1000;

	pDemodKernel->Unlock(pDemodKernel);
#endif
#if 0
	ret = snprintf(pBuff, BufferSize, "[REALTEK_I_DVBT2] lock=%u, sqi=%u, snr=%f, if_agc_gain=%u, error_rate=%f, ts_pkt_cnt=%u, demod_lock_time=%u, ts_lock_time=%u\n",
				   SigLock, Sqi,
				   (double)SnrResult, IfAgcGain, (double)BerResult, TsPktCnt, AcqTime, TsLockTime);
#endif

	return ret;
}


/*----------------------------------------------------------------------
 * Func : Activate
 *
 * Desc : Activate RTK_DEMOD_DVBT2 Demod
 *
 * Parm : N/A
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBT2_Activate(DEMOD* pDemodKernel, unsigned char force_rst)
{

	REALTEK_I_DVBT2* pRealtekIDVBT2;
	DVBT2_DEMOD_MODULE* pDemod;
	pRealtekIDVBT2 = (REALTEK_I_DVBT2*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_DVBT2_DRIVER_DATA*) pRealtekIDVBT2->m_private)->pDemod;

	pDemodKernel->Init(pDemodKernel);

	pDemodKernel->Lock(pDemodKernel);

	pDemodKernel->Unlock(pDemodKernel);

	return TUNER_CTRL_OK;

activate_demod_fail:
	pDemodKernel->Unlock(pDemodKernel);
	return TUNER_CTRL_FAIL;
}


/*----------------------------------------------------------------------
 * Func : SetTvMode
 *
 * Desc : Set Mode of RTK_DEMOD_DVBT2
 *
 * Parm : mode :    RTK_DEMOD_MODE_DVBT2 : DVBT2 mode
 *                  RTK_DEMOD_MODE_DVBC  : DVBC mode
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBT2_SetTvMode(DEMOD* pDemodKernel, TV_SYSTEM_TYPE mode)
{
	int ret = TUNER_CTRL_FAIL;
	REALTEK_I_DVBT2* pRealtekIDVBT2;
	pRealtekIDVBT2 = (REALTEK_I_DVBT2*)(pDemodKernel->private_data);

	pDemodKernel->Lock(pDemodKernel);

	REALTEK_I_DVBT2_INFO("REALTEK_I_DVBT2::SetTvMode(%d)\n", mode);

	switch (mode) {

	case TV_SYS_TYPE_DVBT:
	case TV_SYS_TYPE_DVBT2:

		REALTEK_I_DVBT2_INFO("Set to DVBT2\n");
		ret = pDemodKernel->Init(pDemodKernel);

		if (ret != TUNER_CTRL_OK) {
			REALTEK_I_DVBT2_WARNING("Set REALTEK_I_DVBT2 to DVBT2 mode failed\n");
			goto set_demod_mode_failed;
		}

		break;

	default:
		goto set_demod_mode_failed;
	}

	ret = TUNER_CTRL_OK;
	REALTEK_I_DVBT2_INFO("Set REALTEK_I_DVBT2 to appointed DTV mode successed\n");

	pDemodKernel->Unlock(pDemodKernel);
	return ret;

set_demod_mode_failed:
	pDemodKernel->Unlock(pDemodKernel);

	return TUNER_CTRL_FAIL;
}

void REALTEK_I_DVBT2_Lock(DEMOD* pDemodKernel)
{
	//mutex_lock(&pDemodKernel->m_lock);
}

void REALTEK_I_DVBT2_Unlock(DEMOD* pDemodKernel)
{
	//mutex_unlock(&pDemodKernel->m_lock);
}


/*-----------------------------------------------------------------
 *     BASE_INTERFACE for REALTEK_I_DVBT2 API
 *----------------------------------------------------------------*/


void ReleaseRealtekIDvbt2Driver(REALTEK_I_DVBT2_DRIVER_DATA *pDriver)
{
	kfree(pDriver);
}


REALTEK_I_DVBT2_DRIVER_DATA* AllocRealtekIDvbt2Driver(
	COMM*               pComm,
	unsigned char       Addr,
	unsigned long       CrystalFreq
)
{
	REALTEK_I_DVBT2_DRIVER_DATA* pDriver = (REALTEK_I_DVBT2_DRIVER_DATA*) kmalloc(
			sizeof(REALTEK_I_DVBT2_DRIVER_DATA) +
			sizeof(DVBT2_DEMOD_MODULE)   +
			sizeof(I2C_BRIDGE_MODULE)   +
			sizeof(BASE_INTERFACE_MODULE), GFP_KERNEL);

	if (pDriver) {
		BASE_INTERFACE_MODULE* pBIF;
		DVBT2_DEMOD_MODULE* pDemod;
		memset(pDriver, 0, sizeof(REALTEK_I_DVBT2_DRIVER_DATA));

		pDriver->pDemod                = (DVBT2_DEMOD_MODULE*)(((unsigned char*)pDriver) + sizeof(REALTEK_I_DVBT2_DRIVER_DATA));
		pDriver->pBaseInterface        = (BASE_INTERFACE_MODULE*)(((unsigned char*)pDriver->pDemod) + sizeof(DVBT2_DEMOD_MODULE));
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
		BuildRealtekIDvbt2Module(&pDemod,
								pDriver->pDemod,
								pDriver->pBaseInterface,
								pDriver->pI2CBridge,
								Addr,
								CrystalFreq);            // Spectrum mode is inverse.
	}

	return pDriver;
}


/*----------------------------------------------------------------------
 * Func : ChangeStandard
 *
 * Desc : ChangeStandard to DVBT2 or DVBT
 *
 * Parm :
 *
 * Retn : TUNER_CTRL_OK / TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBT2_ChangeStandard(DEMOD* pDemodKernel, unsigned int Standard)
{
	unsigned int      IsRpuLowReady, IsRpuHighReady;
	//unsigned int      BuildId, DemodType, temp;
	//unsigned int      InitRetry = 0;
	int               ret = TUNER_CTRL_OK;
	unsigned char     PGAEnable = 0;
	IFADCGAIN         PGAGain;

	REALTEK_I_DVBT2* pRealtekIDVBT2;
	DVBT2_DEMOD_MODULE* pDemod;
	pRealtekIDVBT2 = (REALTEK_I_DVBT2*)(pDemodKernel->private_data);

	if (pDemodKernel->m_pComm == NULL || pRealtekIDVBT2->m_private == NULL)
		return TUNER_CTRL_FAIL;

	pDemod = ((REALTEK_I_DVBT2_DRIVER_DATA*) pRealtekIDVBT2->m_private)->pDemod;



	if (Standard == REALTEK_I_DVBT_MODE) {
		REALTEK_I_DVBT2_INFO("\033[1;32;31m" "REALTEK_I_DVBT_MODE\n" "\033[m");
		DtvDemodInitialization(RTK_DEMOD_MODE_DVBT, 1);
		pRealtekIDVBT2->m_dvbt2_dvbt_mode = REALTEK_I_DVBT_MODE;
	} else { //REALTEK_I_DVBT2_MODE
		REALTEK_I_DVBT2_INFO("\033[1;32;31m" "REALTEK_I_DVBT2_MODE\n" "\033[m");
		DtvDemodInitialization(RTK_DEMOD_MODE_DVBT2, 1);
		pRealtekIDVBT2->m_dvbt2_dvbt_mode = REALTEK_I_DVBT2_MODE;
	}

	pRealtekIDVBT2->m_dvbt2_dvbt_mode = Standard;
	PGAEnable = 2;
	PGAGain = PGAFIX_2DB;
	DtvPGAControl(PGAEnable, PGAGain);

	ret |= DECODE_RET(pDemod->CheckRpuReady(pDemod, &IsRpuLowReady));//Check for Low level Header
	ret |= DECODE_RET(pDemod->CheckRpuReady(pDemod, &IsRpuHighReady));//Check for High level Msg

	if (IsRpuLowReady != 1 || IsRpuHighReady != 1 || ret != TUNER_CTRL_OK) {
		REALTEK_I_DVBT2_INFO("Waiting for Demod Init Done; Demod Has No Reply !!!!\n");
		REALTEK_I_DVBT2_INFO("Waiting for Demod Init Done; Demod Has No Reply !!!!\n");
		REALTEK_I_DVBT2_INFO("RpuLowReady = %d, RpuHighReady = %d, ret = %d\n", IsRpuLowReady, IsRpuHighReady, ret);
		goto init_fail;

	}

	//Change To Buffer Mode
	REALTEK_I_DVBT2_INFO("Change To Buffer Mode........\n");
	ret |= DECODE_RET(pDemod->SwitchToBuffer(pDemod));
	if (ret != TUNER_CTRL_OK) {
		REALTEK_I_DVBT2_INFO("Change To Buffer Mode Fail !!!!!\n");
		goto init_fail;
	}

	ret |= DECODE_RET(pDemod->ActivateCore(pDemod));

	//ret |= DECODE_RET(pDemod->GetDemodInfo(pDemod, &DemodType));
	//ret |= DECODE_RET(pDemod->GetBuildId(pDemod, &BuildId));
	//REALTEK_I_DVBT2_INFO("DemodType = %x, BuildId = %x\n", DemodType, BuildId);
	//REALTEK_I_DVBT2_INFO("DVBT2 AGC Scaling = %d /128; DVBT AGC Scaling = %d /128; DVBT2 Inverse = %d; DVBT Inverse = %d\n", pRealtekIDVBT2->m_dvbt2_AgcScale, pRealtekIDVBT2->m_dvbt_AgcScale, pRealtekIDVBT2->m_dvbt2_Invert, pRealtekIDVBT2->m_dvbt_Invert);

	if (Standard == REALTEK_I_DVBT2_MODE) {
		//DVBT2 10.3.1 Support Run Time Change XML Parmeters
		ret |= DECODE_RET(pDemod->SetXmlTunerGainCtrl(pDemod, pRealtekIDVBT2->m_dvbt2_AgcScale | (RTK_DEMOD_XML_EXT_GAIN1 << 16) | (pDemodKernel->m_if.agc_pola << 18)));
		ret |= DECODE_RET(pDemod->SetXmlFlags(pDemod, RTK_DEMOD_XML_REAL_IF | (pDemodKernel->m_if.inversion << 1) | (RTK_DEMOD_XML_UNSIGNED << 2) | (pRealtekIDVBT2->m_dvbt2_ext_gain_dis << 3)));
		ret |= DECODE_RET(pDemod->SetXmlIfFreq(pDemod, pDemodKernel->m_if.freq));
		ret |= DECODE_RET(pDemod->SetXmlTunerCfgOverride(pDemod, 0x00000001));

		ret |= DECODE_RET(pDemod->SetXmlIfClk(pDemod, 30000000));
		ret |= DECODE_RET(pDemod->SetXmlLdpcClk(pDemod, DVBT2_META_2X_CLOCK));
		ret |= DECODE_RET(pDemod->SetXmlUccClk(pDemod, DVBT2_META_1X_CLOCK));
		ret |= DECODE_RET(pDemod->SetXmlMcuClk(pDemod, DVBT2_META_2X_CLOCK));
		ret |= DECODE_RET(pDemod->SetXmlPlftCfgOverride(pDemod, 0x00000001));
		//Set DVBT2 Ber Cal Period to 1 Sec
		ret |= DECODE_RET(pDemod->SetErrRateIntegPeriod(pDemod, 0x00000001));
	} else {
		//DVBT 10.1.0 Support Run Time Change XML Parmeters
		ret |= DECODE_RET(pDemod->SetXmlTunerGainCtrl(pDemod, pRealtekIDVBT2->m_dvbt_AgcScale | (RTK_DEMOD_XML_EXT_GAIN1 << 16) | (pDemodKernel->m_if.agc_pola << 18)));
		ret |= DECODE_RET(pDemod->SetXmlFlags(pDemod, RTK_DEMOD_XML_REAL_IF | (pDemodKernel->m_if.inversion << 1) | (RTK_DEMOD_XML_UNSIGNED << 2) | (pRealtekIDVBT2->m_dvbt_ext_gain_dis << 3)));
		ret |= DECODE_RET(pDemod->SetXmlIfFreq(pDemod, pDemodKernel->m_if.freq));
		ret |= DECODE_RET(pDemod->SetXmlTunerCfgOverride(pDemod, 0x00000001));

		ret |= DECODE_RET(pDemod->SetXmlIfClk(pDemod, 30000000));
		ret |= DECODE_RET(pDemod->SetXmlLdpcClk(pDemod, DVBT_META_2X_CLOCK));
		ret |= DECODE_RET(pDemod->SetXmlUccClk(pDemod, DVBT_META_1X_CLOCK));
		ret |= DECODE_RET(pDemod->SetXmlMcuClk(pDemod, DVBT_META_2X_CLOCK));
		ret |= DECODE_RET(pDemod->SetXmlPlftCfgOverride(pDemod, 0x00000001));
		//Set DVBT Ber Cal Period to 1 Sec
		ret |= DECODE_RET(pDemod->SetDvbTBerPeriod(pDemod, 0x00000001));
	}

	if (pDemodKernel->SetTSMode(pDemodKernel, &pDemodKernel->m_ts) != TUNER_CTRL_OK) {
		goto init_fail;
	}

	REALTEK_I_DVBT2_INFO("REALTEK_I_DVBT/DVBT2 Init Complete\n");

	return TUNER_CTRL_OK;

init_fail:
	REALTEK_I_DVBT2_WARNING("REALTEK_I_DVBT/DVBT2 Init Failed\n");

	return ret;
}


/*----------------------------------------------------------------------
 * Func : GetT2PLPInfo
 *
 * Desc : Get T2 PLP Information
 *
 * Parm : pInfo : PLP Information
 *
 * Retn : TUNER_CTRL_OK / TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBT2_GetT2PLPInfo(DEMOD* pDemodKernel, TV_SIG_INFO* pInfo)
{
	unsigned char PlpList[256];
	unsigned int PlpCount = 0, PlpId = 0, PlpType = 0, PayloadType = 0, ActivePlpId = 0;
	unsigned char i = 0;
	int ret = TUNER_CTRL_OK;

	REALTEK_I_DVBT2* pRealtekIDVBT2;
	DVBT2_DEMOD_MODULE* pDemod;

	if (pDemodKernel == NULL) {
		ret = TUNER_CTRL_FAIL;
		goto GetT2PLPInfo_End;
	}

	pRealtekIDVBT2 = (REALTEK_I_DVBT2*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_DVBT2_DRIVER_DATA*) pRealtekIDVBT2->m_private)->pDemod;

	if (pRealtekIDVBT2->m_dvbt2_dvbt_mode != REALTEK_I_DVBT2_MODE) {

		REALTEK_I_DVBT2_INFO("\033[1;32;32m" "REALTEK_I_DVBT2_ChangeT2PLP fail. standrd now is not DVBT2!!!!!!!!\n" "\033[m");
		return TUNER_CTRL_OK;
	}



	/*PLP Data and PLP Type*/
	ret |= DECODE_RET(pDemod->GetNumDataPlps(pDemod, &PlpCount));
	pInfo->dvbt2_ofdm.plp_cnt = (unsigned char)PlpCount;
	REALTEK_I_DVBT2_DBG("pInfo->dvbt2_ofdm.plp_cnt=%u\n", pInfo->dvbt2_ofdm.plp_cnt);

	if (pInfo->dvbt2_ofdm.plp_cnt != 1) {
		for (i = 0; i < pInfo->dvbt2_ofdm.plp_cnt; i++) {
			ret |= DECODE_RET(pDemod->GetListOfDataPlps(pDemod, i, &PayloadType, &PlpType, &PlpId));
			pInfo->dvbt2_ofdm.plp[i] = (unsigned char)PlpId;
			pInfo->dvbt2_ofdm.plp_type[i] = (unsigned char)PlpType;
			REALTEK_I_DVBT2_DBG("PLPdata(%d)=%u;PLPType(%d)=%u\n", i, pInfo->dvbt2_ofdm.plp[i], i, pInfo->dvbt2_ofdm.plp_type[i]);
		}
	} else if (pInfo->dvbt2_ofdm.plp_cnt = 1)
		pInfo->dvbt2_ofdm.plp[0] = 0;

GetT2PLPInfo_End:
	return ret;
}

/*----------------------------------------------------------------------
 * Func : ChangeT2PLP
 *
 * Desc : Get T2 PLP Information
 *
 * Parm : pInfo : PLP Information
 *
 * Retn : TUNER_CTRL_OK / TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBT2_ChangeT2PLP(DEMOD* pDemodKernel, TV_SIG_INFO* pInfo)
{

	unsigned int   ActivePlpId = 0, DemodStatus = 0, TsPktCnt = 0;
	unsigned long   stime = 0;
	int ret = TUNER_CTRL_OK;
	int plp_selcet = 0;

	REALTEK_I_DVBT2* pRealtekIDVBT2;
	DVBT2_DEMOD_MODULE* pDemod;

	if (pDemodKernel == NULL)
		return TUNER_CTRL_FAIL;

	pRealtekIDVBT2 = (REALTEK_I_DVBT2*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_DVBT2_DRIVER_DATA*) pRealtekIDVBT2->m_private)->pDemod;


	if (pRealtekIDVBT2->m_dvbt2_dvbt_mode != REALTEK_I_DVBT2_MODE) {

		REALTEK_I_DVBT2_INFO("\033[1;32;32m" "REALTEK_I_DVBT2_ChangeT2PLP fail. standrd now is not DVBT2!!!!!!!!\n" "\033[m");
		return TUNER_CTRL_OK;
	}

	pDemodKernel->Lock(pDemodKernel);

	plp_selcet  = ((pInfo->dvbt2_ofdm.plp_select < 256) && (pInfo->dvbt2_ofdm.plp_select > 0)) ? pInfo->dvbt2_ofdm.plp_select : 0;

	ret |= DECODE_RET(pDemod->SetDataPlpIdSelectCmd(pDemod, (unsigned int)plp_selcet));

	if (ret == TUNER_CTRL_FAIL)
		goto ChangeT2PLP_Fail;

	stime = tv_osal_time();

	while ((tv_osal_time() - stime) <= 1300) {
		tv_osal_msleep(5);

		ret |= DECODE_RET(pDemod->GetDemodStatus(pDemod, &DemodStatus));

		if (DemodStatus == 5) {
			break;
		}

		if (stime > tv_osal_time())
			stime = 0;
	}


	if (DemodStatus != 5)
		goto ChangeT2PLP_Fail;

	/*
	while ((tv_osal_time() - stime) <= 1500) {

		tv_osal_msleep(10);

			pDemod->GetActiveDataPlpId(pDemod, &ActivePlpId);
			if (ActivePlpId == (unsigned int)plp_selcet) {
				ret |= DECODE_RET(pDemod->DemodCtrlUpdateCounters(pDemod));
				ret |= pDemod->GetDataPackets(pDemod, &TsPktCnt);
				if (TsPktCnt > 0)
					break;
			}

			if (stime > tv_osal_time())
				stime = 0;
			}

	*/

	pDemodKernel->Unlock(pDemodKernel);
	pRealtekIDVBT2->m_plp_id = plp_selcet;
	REALTEK_I_DVBT2_INFO("[ChangeT2PLP] Plp ID = %d, Switch Time = %u\n", plp_selcet,  tv_osal_time() - stime);

	return TUNER_CTRL_OK;

ChangeT2PLP_Fail:

	pDemodKernel->Unlock(pDemodKernel);
	REALTEK_I_DVBT2_INFO("[ChangeT2PLP]Fail!!!!!!\n");

	return ret;

}


/*----------------------------------------------------------------------
 * Func : CalDvbT2Ssi
 *
 * Desc :
 *
 * Parm :
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBT2_CalDvbT2Ssi(DEMOD* pDemodKernel, int Prec)
{
	unsigned int measSsi = 0, Modulation = 0, CodeRate = 0;
	int Prel = 0;
	int ret = TUNER_CTRL_OK;

	REALTEK_I_DVBT2* pRealtekIDVBT2;
	DVBT2_DEMOD_MODULE* pDemod;

	if (pDemodKernel == NULL) {
		ret = TUNER_CTRL_FAIL;
		goto CalDvbT2Ssi_End;
	}
	pRealtekIDVBT2 = (REALTEK_I_DVBT2*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_DVBT2_DRIVER_DATA*) pRealtekIDVBT2->m_private)->pDemod;
	pDemodKernel->Lock(pDemodKernel);

	ret |= DECODE_RET(pDemod->GetDataPlpModulation(pDemod, &Modulation));
	ret |= DECODE_RET(pDemod->GetDataPlpCodeRate(pDemod, &CodeRate));

	Modulation = (Modulation >= DVBT2_NUM_PLP_CONSTELLATIONS) ? 0 : Modulation;
	CodeRate = (CodeRate >= DVBT2_NUM_DATA_PLP_CODE_RATES) ? 0 : CodeRate;
    //Used define new DVBT2 SSI Prec * PHY_ONE_Q8(256)
    if (ret == TUNER_CTRL_OK) {
        Prec = Prec * PHY_ONE_Q8;                                    
		Prel = (int)(Prec - PHY_ONE_Q8 * prefLevel[Modulation][CodeRate]);

		if (Prel < (DVBT2_SSI_NEG15_Q8)) {                           
			measSsi = 0;                                             /* Lower level SSI */
		} else if ((Prel >= DVBT2_SSI_NEG15_Q8) && (Prel < (DVBT2_SSI_ZERO_Q8))) {
            measSsi = (2  * (Prel - DVBT2_SSI_NEG15_Q8 ))/ 3;        /* Mid level SSI */
		} else if ((Prel >= (DVBT2_SSI_ZERO_Q8)) && (Prel < (DVBT2_SSI_20_Q8))) {
			measSsi = 4 * Prel + 10*PHY_ONE_Q8;                      /* Second mid level SSI */
		} else if ((Prel >= DVBT2_SSI_20_Q8) && (Prel <= DVBT2_SSI_35_Q8)) {
			measSsi = (2 * (Prel - DVBT2_SSI_20_Q8) + (90*PHY_ONE_Q8) * 3) / 3;  /* third SSI level */
		} else if (Prel > DVBT2_SSI_35_Q8) {                         /* The highest SSI threshold */
			measSsi = DVBT2_SSI_100_Q8 ;                             /* SSI = 100% */
		}
        measSsi = measSsi / PHY_ONE_Q8;
	}
    //REALTEK_I_DVBT2_INFO("\033[1;32;32m""REALTEK_I_DVBT2_CalDvbT2Ssi T2_measSsi value = %d\n""\033[m",measSsi);
	pDemodKernel->Unlock(pDemodKernel);

CalDvbT2Ssi_End:

	return measSsi;
}


/*----------------------------------------------------------------------
 * Func : CalDvbTSsi
 *
 * Desc :
 *
 * Parm :
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBT2_CalDvbTSsi(DEMOD* pDemodKernel, int Prec)
{
	unsigned int Modulation = 0, CodeRate = 0;
	long rfLevelQ8 = 0, PrelQ8 = 0, ssiQ8 = 0;
	int ret = TUNER_CTRL_OK;

	REALTEK_I_DVBT2* pRealtekIDVBT2;
	DVBT2_DEMOD_MODULE* pDemod;

	if (pDemodKernel == NULL) {
		ret = TUNER_CTRL_FAIL;
		goto CalDvbTSsi_End;
	}

	pRealtekIDVBT2 = (REALTEK_I_DVBT2*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_DVBT2_DRIVER_DATA*) pRealtekIDVBT2->m_private)->pDemod;
	ret |= DECODE_RET(pDemod->GetDvbTTunMod(pDemod, &Modulation));
	ret |= DECODE_RET(pDemod->GetDvbTTunCodeRate(pDemod, &CodeRate));

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
			ssiQ8 = DVBT_SSI_100_Q8   ;
		}
		ssiQ8 = ((ssiQ8 + (1 << (8 - 1))) >> 8);
	}
CalDvbTSsi_End:

	return ssiQ8;
}

