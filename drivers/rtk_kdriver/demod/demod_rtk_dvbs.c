/***************************************************************************************************
  File        : demod_rtk.cpp
  Description : REALTEK_I DVB-S demod
  Author      : Kevin Wang
****************************************************************************************************
    Update List :
----------------------------------------------------------------------------------------------------
    20120207    | create phase
***************************************************************************************************/
#include <linux/kernel.h>
#include <linux/slab.h>
#include <asm/cacheflush.h>
#include "comm.h"
#include "foundation.h"
#include "demod_rtk_dvbs.h"
#include "dvbs_demod_rtk.h"
#include "demod_rtk_dvbs_priv.h"
#include "dvbs_tvcore_registers.h"
#include "dvbs_registers.h"
#include "spec_an_registers.h"
#include <mach/io.h>
#include "rbus/demod_sd_reg.h"

//#define SPEC_AN_DEBUG
//#define PULL_IN_RANGE_ENHANCEMENT
//#define INVERSE_SPECTRUM

#define DVBS_CR_1_2	 	0
#define DVBS_CR_2_3		1
#define DVBS_CR_3_4		2
#define DVBS_CR_5_6		3
#define DVBS_CR_7_8		4

typedef struct _s_DvbSSignalQualityBound
{
    unsigned int HighBound;
    unsigned int MidBound;
    unsigned int LowBound;    
}s_DvbSSignalQualityBound;

typedef struct _s_DvbSSignalQualityMapping
{
    unsigned int CodeRate;
    s_DvbSSignalQualityBound sBound;
}s_DvbSSignalQualityMapping;

static const s_DvbSSignalQualityMapping _gsDvbSSigQualityMappingTable[] =
{
    {DVBS_CR_1_2,    {104, 64, 44}},
    {DVBS_CR_2_3,    {132, 82, 62}},
    {DVBS_CR_3_4,    {141, 91, 72}},
    {DVBS_CR_5_6,    {152, 102, 82}},
    {DVBS_CR_7_8,    {159, 109, 89}}
};
#define DVBS_SIG_QUALITY_TABLE_SIZE sizeof(_gsDvbSSigQualityMappingTable)/sizeof(s_DvbSSignalQualityMapping)


//static int DvbS_Keep_22k_on_off;
/*----------------------------------------------------------------------
 * Func : REALTEK_I_DVBS
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
void REALTEK_I_DVBS_Constructors(DEMOD* pDemodKernel, unsigned char addr, unsigned char output_mode, unsigned char output_freq, COMM* pComm)
{
    REALTEK_I_DVBS* pRealtekIDVBS;

    pDemodKernel->private_data = kmalloc(sizeof(REALTEK_I_DVBS), GFP_KERNEL);
    pRealtekIDVBS = (REALTEK_I_DVBS*)(pDemodKernel->private_data);

    Demod_Constructors(pDemodKernel);

    pDemodKernel->m_id                 = DTV_DEMOD_REALTEK_I_DVBS;
    pDemodKernel->m_addr               = addr;
    pDemodKernel->m_pTuner             = NULL;
    pDemodKernel->m_pComm              = pComm;
    pDemodKernel->m_ScanRange          = SCAN_RANGE_3_6;
    pDemodKernel->m_Capability         = TV_SYS_TYPE_DVBS;
    pDemodKernel->m_update_interval_ms = 300;
    pDemodKernel->m_if.freq            = 36125000;
    pDemodKernel->m_if.inversion       = 1;
    pDemodKernel->m_if.agc_pola        = 0;
    pDemodKernel->m_clock              = CRYSTAL_FREQ_27000000HZ;
    pRealtekIDVBS->m_output_freq        = output_freq;

    pRealtekIDVBS->m_private            = (void*) AllocRealtekIDvbsDriver(pDemodKernel->m_pComm, pDemodKernel->m_addr, pDemodKernel->m_clock);

    pDemodKernel->m_ts.mode            = (output_mode == RTK_DEMOD_OUT_IF_PARALLEL) ? PARALLEL_MODE : SERIAL_MODE;
    pDemodKernel->m_ts.data_order      = MSB_D7;
    pDemodKernel->m_ts.datapin         = MSB_FIRST;
    pDemodKernel->m_ts.err_pol         = ACTIVE_HIGH;
    pDemodKernel->m_ts.sync_pol        = ACTIVE_HIGH;
    pDemodKernel->m_ts.val_pol         = ACTIVE_HIGH;
    pDemodKernel->m_ts.clk_pol         = FALLING_EDGE;
    pDemodKernel->m_ts.internal_demod_input = 1;
    pDemodKernel->m_ts.tsOutEn = 1;
    pRealtekIDVBS->m_TunerOptRegCnt = 0;
    pRealtekIDVBS->m_auto_tune_en = 0;
    pRealtekIDVBS->m_pTunerOptReg = NULL;

    pDemodKernel->m_pComm->SetTargetName(pDemodKernel->m_pComm, pDemodKernel->m_addr, "REALTEK_I_DVBS");

    pDemodKernel->Init = REALTEK_I_DVBS_Init;
    pDemodKernel->Reset = Demod_Reset;
    pDemodKernel->AcquireSignal = REALTEK_I_DVBS_AcquireSignal;
    pDemodKernel->ScanSignal = REALTEK_I_DVBS_ScanSignal;
    pDemodKernel->SetIF = REALTEK_I_DVBS_SetIF;
    pDemodKernel->SetTSMode = REALTEK_I_DVBS_SetTSMode;
    pDemodKernel->SetTVSysEx = REALTEK_I_DVBS_SetTVSysEx;
    pDemodKernel->SetMode = REALTEK_I_DVBS_SetMode;
    pDemodKernel->SetTVSys = REALTEK_I_DVBS_SetTVSys;
    pDemodKernel->GetLockStatus = REALTEK_I_DVBS_GetLockStatus;
    pDemodKernel->GetSegmentNum = Demod_GetSegmentNum;
    pDemodKernel->GetSignalInfo = REALTEK_I_DVBS_GetSignalInfo;
    pDemodKernel->GetSignalQuality = REALTEK_I_DVBS_GetSignalQuality;
    pDemodKernel->ChangeT2PLP = Demod_ChangeT2PLP;
    pDemodKernel->GetT2PLPInfo = Demod_GetT2PLPInfo;
    pDemodKernel->GetT2L1PreInfo = Demod_GetT2L1PreInfo;
    pDemodKernel->GetT2L1PostInfo = Demod_GetT2L1PostInfo;
    pDemodKernel->GetDemodStatus = Demod_GetDemodStatus;
    pDemodKernel->GetCarrierOffset = REALTEK_I_DVBS_GetCarrierOffset;
    pDemodKernel->ForwardI2C = REALTEK_I_DVBS_ForwardI2C;
    pDemodKernel->AutoTune = REALTEK_I_DVBS_AutoTune;
    pDemodKernel->GetCapability = Demod_GetCapability;
    pDemodKernel->Suspend = Demod_Suspend;
    pDemodKernel->Resume = Demod_Resume;
    pDemodKernel->SetTvMode = REALTEK_I_DVBS_SetTvMode;
    pDemodKernel->InspectSignal = REALTEK_I_DVBS_InspectSignal;     // Add monitor function that used to monitor demod status
    pDemodKernel->AttachTuner = Demod_AttachTuner;
    pDemodKernel->GetTSParam = Demod_GetTSParam;
    
    pDemodKernel->SpecAnGetSpectrum = REALTEK_I_DVBS_SpecAnGetSpectrum;
    pDemodKernel->SpecAnGetCp1Cp2 = REALTEK_I_DVBS_SpecAnGetCp1Cp2;
    pDemodKernel->SpecAnCalCfoCsr = REALTEK_I_DVBS_SpecAnCalCfoCsr;
    pDemodKernel->SpecAnSearchMaxMin = REALTEK_I_DVBS_SpecAnSearchMaxMin;
    pDemodKernel->CarrierAnalyzeSpectrum = REALTEK_I_DVBS_CarrierAnalyzeSpectrum;
    pDemodKernel->GetSignalCarrierFrequencyOffset = REALTEK_I_DVBS_GetSignalCarrierFrequencyOffset;
    
    //pDemodKernel->Lock = Demod_Lock;
    //pDemodKernel->Unlock = Demod_Unlock;
    pDemodKernel->Lock = REALTEK_I_DVBS_Lock;
    pDemodKernel->Unlock = REALTEK_I_DVBS_Unlock;

    //pDemodKernel->Activate = REALTEK_I_DVBS_Activate;
    pDemodKernel->Destory = REALTEK_I_DVBS_Destructors;

}


/*----------------------------------------------------------------------
 * Func : ~REALTEK_I_DVBS
 *
 * Desc : Destructor of REALTEK_I_DVBS
 *
 * Parm : pDemod : handle of Demod
 *
 * Retn : N/A
 *----------------------------------------------------------------------*/
void REALTEK_I_DVBS_Destructors(DEMOD* pDemodKernel)
{
    REALTEK_I_DVBS* pRealtekIDVBS;
    pRealtekIDVBS = (REALTEK_I_DVBS*)(pDemodKernel->private_data);

    if (pRealtekIDVBS->m_private != NULL)
        ReleaseRealtekIDvbsDriver((REALTEK_I_DVBS_DRIVER_DATA*)pRealtekIDVBS->m_private);

    kfree(pRealtekIDVBS);
    //pDemodKernel->Destory(pDemodKernel);
    REALTEK_I_DVBS_INFO("REALTEK_I_DVBS_Destructors Complete\n");
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
int REALTEK_I_DVBS_Init(DEMOD* pDemodKernel)
{   
    int ret = TUNER_CTRL_OK;
    unsigned char PGAEnable = 0;
    IFADCGAIN PGAGain;
    unsigned int IsRpuLowReady = 0, IsRpuHighReady = 0;
    unsigned int BuildId = 0, DemodType = 0;
    unsigned int InitRetry = 0;

    REALTEK_I_DVBS* pRealtekIDVBS;
    REG_VALUE_ENTRY*  OptRegTable;
    DVBS_DEMOD_MODULE* pDemod;
    pRealtekIDVBS = (REALTEK_I_DVBS*)(pDemodKernel->private_data);

    if (pDemodKernel->m_pComm == NULL || pRealtekIDVBS->m_private == NULL)
        return TUNER_CTRL_FAIL;
    
    pDemod = ((REALTEK_I_DVBS_DRIVER_DATA*) pRealtekIDVBS->m_private)->pDemod;
    
    pDemodKernel->Lock(pDemodKernel);

    pRealtekIDVBS->m_auto_tune_en = 0;
    
demod_re_init:
	DtvDemodInitialization(RTK_DEMOD_MODE_DVBS, 1);

    ret |= DECODE_RET(pDemod->CheckRpuReady(pDemod, &IsRpuLowReady));//Check for Low level Header
    ret |= DECODE_RET(pDemod->CheckRpuReady(pDemod, &IsRpuHighReady));//Check for High level Msg

    if(IsRpuLowReady != 1 || IsRpuHighReady != 1)
    {
        REALTEK_I_DVBS_INFO("Waiting for Demod Init Done; Demod Has No Reply !!!!\n");
        REALTEK_I_DVBS_INFO("Waiting for Demod Init Done; Demod Has No Reply !!!!\n");
        REALTEK_I_DVBS_INFO("Waiting for Demod Init Done; Demod Has No Reply !!!!\n");
        REALTEK_I_DVBS_INFO("Waiting for Demod Init Done; Demod Has No Reply !!!!\n");
        REALTEK_I_DVBS_INFO("RpuLowReady = %d, RpuHighReady = %d\n", IsRpuLowReady, IsRpuHighReady);
        
        if(!InitRetry)
        {
            InitRetry = 1;
            REALTEK_I_DVBS_INFO("\033[1;32;32m" "RPU Auto Re-Init in Demod Init\n" "\033[m");
            goto demod_re_init;
        }
        else
        {
            goto init_fail;
        }
    }

    //Change To Buffer Mode
    REALTEK_I_DVBS_INFO("Change To Buffer Mode........\n");
    ret |= DECODE_RET(pDemod->SwitchToBuffer(pDemod));
    if (ret!= TUNER_CTRL_OK)
    {
        REALTEK_I_DVBS_INFO("Change To Buffer Mode Fail !!!!!\n");
        goto init_fail;
    }

    ret |= DECODE_RET(pDemod->ActivateCore(pDemod));

    PGAEnable = 2;
    PGAGain = PGAFIX_2DB;

    if (pDemodKernel->m_pTuner) {
        TUNER_PARAM Param;

        if (pDemodKernel->m_pTuner->GetParam(pDemodKernel->m_pTuner, TV_SYS_DVBS, &Param) == TUNER_CTRL_OK) {
            switch (Param.id)  {
            case TV_TUNER_AV2018:
                REALTEK_I_DVBS_INFO("Tuner id %d, TV_TUNER_AV2018\n", Param.id);
                break;
            case TV_TUNER_NO_TUNER:
                REALTEK_I_DVBS_INFO("Tuner id %d, TV_TUNER_NO_TUNER\n", Param.id);
                break;
            default:
                REALTEK_I_DVBS_INFO("Unkonw tuner id %d, using default setting\n", Param.id);
                break;
            }

            pDemodKernel->m_if.freq      = Param.if_freq;
            pDemodKernel->m_if.inversion = Param.if_inversion;
            pDemodKernel->m_if.agc_pola  = Param.if_agc_pola;
        }
    }

    DtvPGAControl(PGAEnable, PGAGain);

	ClearDemodReset(RTK_DEMOD_MODE_DVBS);

    if (pDemodKernel->SetTSMode(pDemodKernel, &pDemodKernel->m_ts) != TUNER_CTRL_OK)
        goto init_fail;

    REALTEK_I_DVBS_DBG("REALTEK_I_DVBS Init Complete\n");
    
	ret	|= pDemod->GetVirtualRegister(pDemod, TV_REG_DEMOD_ID, NULL_SEC_ADDR, &DemodType);
	DemodType = ((DemodType&0xFF000000)>>24);
	ret	|= pDemod->GetVirtualRegister(pDemod, TV_REG_BUILD_ID, NULL_SEC_ADDR, &BuildId);
    REALTEK_I_DVBS_INFO("DemodType = %x, BuildId = %x\n", DemodType, BuildId);

    //Set Ber Cal Period to 1 Sec
	ret	|= pDemod->SetVirtualRegister(pDemod, DVBS_REG_NUM_SECONDS_BER_AVERAGING, NULL_SEC_ADDR, 0x00000001 & DVBS_BITFLD_NUM_SECONDS_BER_AVERAGING);
	
    
    pDemodKernel->Unlock(pDemodKernel);

    return TUNER_CTRL_OK;

init_fail:

    REALTEK_I_DVBS_WARNING("REALTEK_I_DVBS Init Failed\n");

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
int REALTEK_I_DVBS_SetTVSys(DEMOD* pDemodKernel, TV_SYSTEM sys)
{
    REALTEK_I_DVBS* pRealtekIDVBS;
    pRealtekIDVBS = (REALTEK_I_DVBS*)(pDemodKernel->private_data);

    TV_SIG_INFO   SigInfo;

    SigInfo.mod = TV_MODULATION_DVBS;
    SigInfo.dvbs.mod = TV_MODULATION_DVBS;
    SigInfo.dvbs.symbol_rate = 27500000;
    SigInfo.dvbs.lnb_mode = LNB_MODE_13V_WITH_22K_BURST;

    return pDemodKernel->SetTVSysEx(pDemodKernel, sys, &SigInfo);
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
int REALTEK_I_DVBS_SetTVSysEx(DEMOD* pDemodKernel, TV_SYSTEM sys, const TV_SIG_INFO*  pSigInfo)
{
    int ret = TUNER_CTRL_OK;
    TUNER_PARAM Param;
    
    REALTEK_I_DVBS* pRealtekIDVBS;
    DVBS_DEMOD_MODULE* pDemod;
    pRealtekIDVBS = (REALTEK_I_DVBS*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS_DRIVER_DATA*) pRealtekIDVBS->m_private)->pDemod;

    if (!IsDvbsSys(sys)) {
        REALTEK_I_DVBS_WARNING("Set TV system failed, unsupported TV system\n");

        return TUNER_CTRL_FAIL;
    }
    
    if (!pSigInfo) {
        REALTEK_I_DVBS_INFO("Siginfo doesn't specified, SetTVSysEx Fail\n");

        return TUNER_CTRL_FAIL;
    }
    
    if(pSigInfo->dvbs.symbol_rate == 0)
    {
        REALTEK_I_DVBS_WARNING("Null Symbol Rate, Break\n");

        return TUNER_CTRL_OK;
    }

    pRealtekIDVBS->m_auto_tune_en = 0;

    pDemodKernel->Lock(pDemodKernel);

    //TUNER_PARAM Param;
    if (pDemodKernel->m_pTuner->GetParam(pDemodKernel->m_pTuner, sys, &Param) == TUNER_CTRL_OK) {
        if ((pDemodKernel->m_if.freq != Param.if_freq) || (pDemodKernel->m_if.inversion != Param.if_inversion) || (pDemodKernel->m_if.agc_pola  != Param.if_agc_pola)) {
            pDemodKernel->m_if.freq = Param.if_freq;
            pDemodKernel->m_if.inversion = Param.if_inversion;
            pDemodKernel->m_if.agc_pola = Param.if_agc_pola;
            if (pDemodKernel->SetIF(pDemodKernel, &pDemodKernel->m_if) != TUNER_CTRL_OK)  return  TUNER_CTRL_FAIL;

        }
    }

    pDemodKernel->Unlock(pDemodKernel);
    
    // with specified information
    switch (pSigInfo->dvbs.lnb_mode) {
    case LNB_MODE_13V_WITH_22K_BURST:
        REALTEK_I_DVBS_INFO("LNB 13V with 22K ON\n");
        break;
    case LNB_MODE_18V_WITH_22K_BURST:
        REALTEK_I_DVBS_INFO("LNB 18V with 22K ON\n");
        break;
    case LNB_MODE_13V:
        REALTEK_I_DVBS_INFO("LNB 13V with 22K OFF\n");
        break;
    case LNB_MODE_18V:
        REALTEK_I_DVBS_INFO("LNB 18V with 22K OFF\n");
        break;
    case LNB_MODE_OFF:
        REALTEK_I_DVBS_INFO("LNB OFF\n");
        break;
    default:
        REALTEK_I_DVBS_WARNING("set TV LNB failed, invalid mode %d\n", pSigInfo->dvbs.lnb_mode);
        return TUNER_CTRL_FAIL;
    }

    pRealtekIDVBS->m_dvbs_zapping_mode = (unsigned char)pSigInfo->dvbs.zapping_mode;
    pRealtekIDVBS->m_current_bw = (unsigned int)pSigInfo->dvbs.symbol_rate;
    pRealtekIDVBS->m_dvbs_manual_code_rate = (unsigned char)pSigInfo->dvbs.code_rate;
    pRealtekIDVBS->m_dvbs_manual_spec_invert = (unsigned char)pSigInfo->dvbs.spec_invert;
    pRealtekIDVBS->m_info.dvbs.symbol_rate= (unsigned int)pSigInfo->dvbs.symbol_rate;
    
    pDemodKernel->m_tv_sys = sys;

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
int REALTEK_I_DVBS_SetIF(DEMOD* pDemodKernel, IF_PARAM* pParam)
{
    int ret = TUNER_CTRL_OK;
    REALTEK_I_DVBS* pRealtekIDVBS;
    DVBS_DEMOD_MODULE* pDemod;
    pRealtekIDVBS = (REALTEK_I_DVBS*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS_DRIVER_DATA*) pRealtekIDVBS->m_private)->pDemod;

    pDemodKernel->Lock(pDemodKernel);

    REALTEK_I_DVBS_DBG("SetIF, IF_freq=%lu, spectrumn inv=%d, agc_pola=%d\n",
                     pParam->freq, pParam->inversion, pParam->agc_pola);

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
int REALTEK_I_DVBS_SetMode(DEMOD* pDemodKernel, TV_OP_MODE mode)
{
    REALTEK_I_DVBS* pRealtekIDVBS;
    pRealtekIDVBS = (REALTEK_I_DVBS*)(pDemodKernel->private_data);
    
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
int REALTEK_I_DVBS_SetTSMode(DEMOD* pDemodKernel, TS_PARAM* pParam)
{
    int ret = TUNER_CTRL_OK;
    unsigned char TsOutEn = 0, TsSerial = 0, ClkPhase = 0;
	unsigned int TsConfig = 0;

    REALTEK_I_DVBS* pRealtekIDVBS;
    DVBS_DEMOD_MODULE* pDemod;
    pRealtekIDVBS = (REALTEK_I_DVBS*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS_DRIVER_DATA*) pRealtekIDVBS->m_private)->pDemod;

    TsOutEn = (pParam->tsOutEn==1) ? RTK_DEMOD_TS_EN : RTK_DEMOD_TS_DIS;
    TsSerial = (pParam->mode==SERIAL_MODE) ? RTK_DEMOD_TS_SERIAL : RTK_DEMOD_TS_PARALLEL;
    ClkPhase = (pParam->clk_pol==FALLING_EDGE) ? RTK_DEMOD_TS_CLK_PHASE_NOR : RTK_DEMOD_TS_CLK_PHASE_INV;

    pDemodKernel->Lock(pDemodKernel);

	ret	|= pDemod->SetVirtualRegister(pDemod, TV_REG_TSO_CLK_RATE_MARGIN, NULL_SEC_ADDR, 0x00011170);
	
	TsConfig &= ~(REALTEK_I_TS_DIS_MASK|REALTEK_I_TS_SERIAL_MASK|REALTEK_I_TS_CLK_PHASE_INV_MASK|REALTEK_I_TS_PACKETS_188_MASK);
    if(TsOutEn)
        TsConfig |= REALTEK_I_TS_DIS_MASK;
    if(TsSerial)
        TsConfig |= REALTEK_I_TS_SERIAL_MASK;
    if(ClkPhase)
        TsConfig |= REALTEK_I_TS_CLK_PHASE_INV_MASK;
    if(RTK_DEMOD_TS_PACKETS_204)
        TsConfig |= REALTEK_I_TS_PACKETS_188_MASK;
    else
        TsConfig |= REALTEK_I_TS_CLOCK_GATE_MASK;
	ret	|= pDemod->SetVirtualRegister(pDemod, TV_REG_TSO_CONFIG, NULL_SEC_ADDR, TsConfig);

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
int REALTEK_I_DVBS_GetLockStatus(DEMOD* pDemodKernel, unsigned char* pLock)
{
    unsigned char lock = 0;
    unsigned int DemodStatus = 0;
    int ret = TUNER_CTRL_OK;

    REALTEK_I_DVBS* pRealtekIDVBS;
    DVBS_DEMOD_MODULE* pDemod;
    pRealtekIDVBS = (REALTEK_I_DVBS*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS_DRIVER_DATA*)pRealtekIDVBS->m_private)->pDemod;

    if (!DtvIsDemodClockEnable(RTK_DEMOD_MODE_DVBS))
        return TUNER_CTRL_FAIL;

    pDemodKernel->Lock(pDemodKernel);

	ret	|= pDemod->GetVirtualRegister(pDemod, TV_REG_STATE, NULL_SEC_ADDR, &DemodStatus);
    lock = (DemodStatus == 5) ? YES : NO;

    if (ret == TUNER_CTRL_OK)
        *pLock = DECODE_LOCK(lock);
    else
        *pLock = 0;

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
int REALTEK_I_DVBS_GetSignalInfo(DEMOD* pDemodKernel, TV_SIG_INFO* pInfo)
{
    int ret = TUNER_CTRL_OK;
    REALTEK_I_DVBS* pRealtekIDVBS;
    DVBS_DEMOD_MODULE* pDemod;
    unsigned int spec_inv = 0, code_rate = 0, modulation = 0;

    pRealtekIDVBS = (REALTEK_I_DVBS*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS_DRIVER_DATA*)pRealtekIDVBS->m_private)->pDemod;

    #if 0
    typedef struct
    {
        BOOLEAN                         bIsDVBS2;        /* 1 bit */
        BOOLEAN                         bSpectrumInv;    /* 1 bit */
        UINT32                          symbolRate;
        HAL_DEMOD_TPS_CODERATE_T        codeRate;
        HAL_DEMOD_TPS_CONSTELLATION_T   constellation;
    } HAL_DEMOD_SPECDATA_DVBS_T;
    #endif

    pInfo->mod = TV_MODULATION_DVBS;                        //bIsDVBS2
    
    pDemodKernel->Lock(pDemodKernel);
    
	ret	|= pDemod->GetVirtualRegister(pDemod, DVBS_REG_ACTIVE_SPECTRUM_INVERSION, NULL_SEC_ADDR, &spec_inv);
	spec_inv &= DVBS_BITFLD_ACTIVE_SPECTRUM_INVERSION;
	ret	|= pDemod->GetVirtualRegister(pDemod, DVBS_REG_ACTIVE_CODE_RATE, NULL_SEC_ADDR, &code_rate); //codeRate
	code_rate &= DVBS_BITFLD_ACTIVE_CODE_RATE;

    pDemodKernel->Unlock(pDemodKernel);

    pInfo->dvbs.spec_invert = spec_inv;
    pInfo->dvbs.symbol_rate = pRealtekIDVBS->m_current_bw;

    switch (code_rate) 
    {
        case 0://Code Rate 1/2
            pInfo->dvbs.code_rate = DVBS2_CR_1_2;
            break;
        case 1://Code Rate 2/3
            pInfo->dvbs.code_rate = DVBS2_CR_2_3;
            break;
        case 2://Code Rate 3/4
            pInfo->dvbs.code_rate = DVBS2_CR_3_4;
            break;
        case 3://Code Rate 5/6
            pInfo->dvbs.code_rate = DVBS2_CR_5_6;
            break;
        case 4://Code Rate 7/8
            pInfo->dvbs.code_rate = DVBS2_CR_7_8;
            break;
    }

    pInfo->dvbs.modulation = DVBS2_QPSK;                    //constellation

    REALTEK_I_DVBS_INFO("GetSignalInfo, SPEC_INV = %u, SYMBOL_RATE = %u, CODE_RATE = %u, MODULATION = %u\n", 
        pInfo->dvbs.spec_invert, pInfo->dvbs.symbol_rate, pInfo->dvbs.code_rate, pInfo->dvbs.modulation);

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
int REALTEK_I_DVBS_GetSignalQuality(DEMOD* pDemodKernel, ENUM_TV_QUAL id, TV_SIG_QUAL* pQuality)
{
    unsigned int Snr = 0, Ber = 0, Per = 0, Ubc = 0, PakN = 0, BadPakN = 0, IfAgcGain = 0, Agc = 0;
    int ret = TUNER_CTRL_OK;

    REALTEK_I_DVBS* pRealtekIDVBS;
    DVBS_DEMOD_MODULE* pDemod;
    pRealtekIDVBS = (REALTEK_I_DVBS*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS_DRIVER_DATA*) pRealtekIDVBS->m_private)->pDemod;

    if (!DtvIsDemodClockEnable(RTK_DEMOD_MODE_DVBS))
        return TUNER_CTRL_FAIL;

    pDemodKernel->Lock(pDemodKernel);

	ret	|= pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_UPDATE_COUNTERS);

    switch (id) {
    case TV_QUAL_SNR:
		ret	|= pDemod->GetVirtualRegister(pDemod, DVBS_REG_SNR_ESTIMATE, NULL_SEC_ADDR, &Snr);
		Snr &= DVBS_BITFLD_SNR_ESTIMATE;
        pQuality->snr = (Snr*100)/655;
        pRealtekIDVBS->m_dvbs_snr = pQuality->snr;
		ret	|= pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_RESET_COUNTERS);
        break;
    case TV_QUAL_BER:
        //DVBS only have RS Iutput BER
		//ret	|= pDemod->GetVirtualRegister(pDemod, DVBS_REG_BER_AT_RS_INPUT, NULL_SEC_ADDR, &Ber);
		//Ber &= DVBS_BITFLD_BER_AT_RS_INPUT;
        //pQuality->ber = ((double)Ber)/4294967296;
        pQuality->ber = 0;
        break;
    case TV_QUAL_PER:
		ret	|= pDemod->GetVirtualRegister(pDemod, DVBS_REG_PER_AT_OUTPUT, NULL_SEC_ADDR, &Per);
		Per &= DVBS_BITFLD_PER_AT_OUTPUT;
        pQuality->per = (Per*10000)/4294967296;
        break;
    case TV_QUAL_UCBLOCKS:
		ret	|= pDemod->GetVirtualRegister(pDemod, DVBS_REG_BAD_PACKET_COUNT, NULL_SEC_ADDR, &Ubc);
		Ubc &= DVBS_BITFLD_BAD_PACKET_COUNT;
        if(Ubc >= pRealtekIDVBS->m_PreUbc)
            pQuality->ucblocks = Ubc - pRealtekIDVBS->m_PreUbc;
        else
            pQuality->ucblocks = Ubc + ((2^32) - pRealtekIDVBS->m_PreUbc);
        pRealtekIDVBS->m_PreUbc = Ubc;
        break;
    case TV_QUAL_SIGNAL_STRENGTH:
        pQuality->strength =REALTEK_I_DVBS_CalDvbSSsi(pDemodKernel);
        break;
    case TV_QUAL_SIGNAL_QUALITY:
        pQuality->quality = REALTEK_I_DVBS_CalDvbSSqi(pDemodKernel);
        break;
    case TV_QUAL_AGC:
        //ret = DECODE_RET(pDemod->GetIfAgcGain(pDemod, &IfAgcGain));
        //pQuality->agc = IfAgcGain >> 20;
		Agc = rtd_inl(DEMOD_SD_SIGMA_DELTA_INPUT_reg)&0x7ff;
		Agc =  Agc*100/0x7ff;
		pQuality->agc = Agc;
        break;
    case TV_QUAL_BEC:
		ret	|= pDemod->GetVirtualRegister(pDemod, DVBS_REG_TS_PACKET_COUNT, NULL_SEC_ADDR, &PakN);
		PakN &= DVBS_BITFLD_TS_PACKET_COUNT;
		ret	|= pDemod->GetVirtualRegister(pDemod, DVBS_REG_BAD_PACKET_COUNT, NULL_SEC_ADDR, &BadPakN);
		BadPakN &= DVBS_BITFLD_BAD_PACKET_COUNT;
        if (PakN > 0) {
            pQuality->layer_ber.ber_num = BadPakN * 36;
            pQuality->layer_ber.ber_den = (PakN * 204 * 8);
        }  else  {
            pQuality->layer_ber.ber_num = 0xffffffff;
            pQuality->layer_ber.ber_den = 0xffffffff;
        }
        break;
    case TV_QUAL_PEC:
		ret	|= pDemod->GetVirtualRegister(pDemod, DVBS_REG_TS_PACKET_COUNT, NULL_SEC_ADDR, &PakN);
		PakN &= DVBS_BITFLD_TS_PACKET_COUNT;
		ret	|= pDemod->GetVirtualRegister(pDemod, DVBS_REG_BAD_PACKET_COUNT, NULL_SEC_ADDR, &BadPakN);
		BadPakN &= DVBS_BITFLD_BAD_PACKET_COUNT;
        if (PakN > 0) {
            pQuality->layer_per.per_num = BadPakN;
            pQuality->layer_per.per_den = PakN;
        } else  {
            pQuality->layer_per.per_num = 0xffffffff;
            pQuality->layer_per.per_den = 0xffffffff;
        }
        break;
    case TV_QUAL_DEMODFWVERSION:
        pQuality->DemodFwVersion = 0x000001;
        break;
    default:
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
int REALTEK_I_DVBS_GetCarrierOffset(DEMOD* pDemodKernel, long* pOffset)
{
    int ret = TUNER_CTRL_OK;
    REALTEK_I_DVBS* pRealtekIDVBS;
    DVBS_DEMOD_MODULE* pDemod;
    pRealtekIDVBS = (REALTEK_I_DVBS*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS_DRIVER_DATA*) pRealtekIDVBS->m_private)->pDemod;
    unsigned int Cfo = 0;

    if (!DtvIsDemodClockEnable(RTK_DEMOD_MODE_DVBS))
        return TUNER_CTRL_FAIL;

    pDemodKernel->Lock(pDemodKernel);
    
	ret	|= pDemod->GetVirtualRegister(pDemod, DVBS_REG_CARRIER_FREQ_OFFSET, NULL_SEC_ADDR, &Cfo);
	Cfo &= DVBS_BITFLD_CARRIER_FREQ_OFFSET;
    *pOffset = -Cfo;

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
int REALTEK_I_DVBS_GetDebugLogBuf(DEMOD* pDemodKernel, unsigned int* LogBufAddr, unsigned int* LogBufSize)
{
	int ret = TUNER_CTRL_OK;
	REALTEK_I_DVBS* pRealtekIDVBS;
	DVBS_DEMOD_MODULE* pDemod;
	pRealtekIDVBS = (REALTEK_I_DVBS*)(pDemodKernel->private_data);
	pDemod = ((REALTEK_I_DVBS_DRIVER_DATA*) pRealtekIDVBS->m_private)->pDemod;
    unsigned int ReadValue=0;
    
	pDemodKernel->Lock(pDemodKernel);
    
	if (pDemod) {
        ret|=pDemod->GetVirtualRegister(pDemod, TV_REG_ENSIGMA_SDK_BUFF_PTR, NULL_SEC_ADDR, &ReadValue);
        * LogBufAddr = ReadValue;
        ret|=pDemod->GetVirtualRegister(pDemod, TV_REG_ENSIGMA_SDK_BUFF_SIZE, NULL_SEC_ADDR, &ReadValue);
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
 * Func : CarrierAnalyzeSpectrum
 *
 * Desc : Analyze spectrum.
 *
 * Parm : SignalFound : Is there a signal in the spectrum
 *        InputSigSr : Input siganl symbol rate
 *        SigCfo : Signal carrier offest in the spectrum (unit : Hz)
 *        SigCsr : Signal course symbol rate in the spectrum (unit : Hz)
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS_CarrierAnalyzeSpectrum(DEMOD* pDemodKernel, unsigned char *SignalFound, unsigned int InputSigSr, int *SigCfo, unsigned int *SigCsr)
{
    REALTEK_I_DVBS* pRealtekIDVBS;
    DVBS_DEMOD_MODULE* pDemod;
    pRealtekIDVBS = (REALTEK_I_DVBS*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS_DRIVER_DATA*) pRealtekIDVBS->m_private)->pDemod;
    unsigned int MaxPower = 0, MinPower = 0, CutTh = 0, Cp1 = 0, Cp2 = 0, Sp = 0, Ep = 0;

    *SignalFound = 1;
    
    REALTEK_I_DVBS_SpecAnSearchMaxMin(pDemodKernel, pRealtekIDVBS->CapturedSpectrum_dvbs, 0, pRealtekIDVBS->m_carrier_spectrum_len, &MaxPower, &MinPower);

    CutTh = MaxPower - (5*256);

    #ifdef SPEC_AN_DEBUG
    REALTEK_I_DVBS_INFO("\033[1;32;31m" "MaxPower = %u(%u)\n" "\033[m", MaxPower, MaxPower/256);
    REALTEK_I_DVBS_INFO("\033[1;32;31m" "MinPower = %u(%u)\n" "\033[m", MinPower, MinPower/256);	
    REALTEK_I_DVBS_INFO("\033[1;32;31m" "SrTh = %u\n" "\033[m", CutTh/256);
    #endif

    //Start Search Signal
    Sp = 1;
    Ep = pRealtekIDVBS->m_carrier_spectrum_len-1;
    REALTEK_I_DVBS_SpecAnGetCp1Cp2(pDemodKernel, pRealtekIDVBS->CapturedSpectrum_dvbs, CutTh, Sp, Ep, &Cp1, &Cp2);
    REALTEK_I_DVBS_SpecAnCalCfoCsr(pDemodKernel, REALTEK_I_SPEC_AN_CFO_MODE, Cp1, Cp2, SigCfo, SigCsr);
    #ifdef SPEC_AN_DEBUG
    REALTEK_I_DVBS_INFO("\033[1;32;31m" "1st SigCfo = %d\n" "\033[m", *SigCfo);
    REALTEK_I_DVBS_INFO("\033[1;32;31m" "1st SigCsr = %u\n" "\033[m", *SigCsr);
    #endif

    //Skip Interference and DC
    while(*SigCsr < (InputSigSr*6/10))
    {
        if((pRealtekIDVBS->m_carrier_spectrum_len - Sp) < 10)
        {
            *SignalFound = 0;
            #ifdef SPEC_AN_DEBUG
            REALTEK_I_DVBS_INFO("\033[1;32;32m" "Break in [Sp Near Ep]\n" "\033[m");
            #endif
            break;
        }
        else if(Cp1 == -1 && Cp2 == -1)
        {
            *SignalFound = 0;
            #ifdef SPEC_AN_DEBUG
            REALTEK_I_DVBS_INFO("\033[1;32;32m" "Break in [No Signal Found]\n" "\033[m");
            #endif
            break;
        }
        else if(Cp2 == -1)
        {
            *SignalFound = 0;
            #ifdef SPEC_AN_DEBUG
            REALTEK_I_DVBS_INFO("\033[1;32;32m" "Break in [Partial Signal Found]\n" "\033[m");
            #endif
            break;
        }
        #ifdef SPEC_AN_DEBUG
        REALTEK_I_DVBS_INFO("\033[1;32;32m" "Interference and DC Detected Skip\n" "\033[m");
        #endif
        Sp = Cp2+1;
        Ep = pRealtekIDVBS->m_carrier_spectrum_len-1;
        REALTEK_I_DVBS_SpecAnGetCp1Cp2(pDemodKernel, pRealtekIDVBS->CapturedSpectrum_dvbs, CutTh, Sp, Ep, &Cp1, &Cp2);
        REALTEK_I_DVBS_SpecAnCalCfoCsr(pDemodKernel, REALTEK_I_SPEC_AN_CFO_MODE, Cp1, Cp2, SigCfo, SigCsr);
        #ifdef SPEC_AN_DEBUG
        REALTEK_I_DVBS_INFO("\033[1;32;31m" "Cont. SigCfo = %d\n" "\033[m", *SigCfo);
        REALTEK_I_DVBS_INFO("\033[1;32;31m" "Cont. SigCsr = %u\n" "\033[m", *SigCsr);
        #endif
    }

    return TUNER_CTRL_OK;
}


int REALTEK_I_DVBS_GetSignalCarrierFrequencyOffset(DEMOD* pDemodKernel, int *SigCfo)
{
    int ret = TUNER_CTRL_OK;
    REALTEK_I_DVBS* pRealtekIDVBS;
    DVBS_DEMOD_MODULE* pDemod;
    pRealtekIDVBS = (REALTEK_I_DVBS*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS_DRIVER_DATA*) pRealtekIDVBS->m_private)->pDemod;

    REALTEK_I_DVBS_SpecAnGetSpectrum(pDemodKernel, REALTEK_I_SPEC_AN_CFO_MODE, pRealtekIDVBS->CapturedSpectrum_dvbs, &pRealtekIDVBS->m_carrier_spectrum_len);
    REALTEK_I_DVBS_CarrierAnalyzeSpectrum(pDemodKernel, &pRealtekIDVBS->m_carrier_signal_found, pRealtekIDVBS->m_current_bw, &pRealtekIDVBS->m_carrier_signal_cfo, &pRealtekIDVBS->m_carrier_signal_csr);

    *SigCfo = 0;
    if(pRealtekIDVBS->m_carrier_signal_found)
        *SigCfo = pRealtekIDVBS->m_carrier_signal_cfo;

    return TUNER_CTRL_OK;
}


#ifdef INVERSE_SPECTRUM
void REALTEK_I_DVBS_ReverseArray(unsigned short *pintArray, unsigned int intArraySize)
{
    unsigned short intBuf = 0;
    int i = 0;
    
    for(i=(intArraySize-1);i>(intArraySize-1)/2;i--)
    {
        if(i!=(intArraySize-1-i))
        {
            intBuf=*(pintArray+i);
            *(pintArray+i)=*(pintArray+(intArraySize-1-i));
            *(pintArray+(intArraySize-1-i))=intBuf;
        }
        else
        {
            break;
        }
    }
}
#endif


/*----------------------------------------------------------------------
 * Func : SpecAnGetSpectrum
 *
 * Desc : Get spectrum data.
 *
 * Parm : Mode : Select mode for getting spectrum
 *        SpectrumArray : Spectrum data result
 *        SpectrumLength : Spectrum data length
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS_SpecAnGetSpectrum(DEMOD* pDemodKernel, unsigned int Mode, unsigned short *SpectrumArray, unsigned int *SpectrumLength)
{
    int ret = TUNER_CTRL_OK;
    unsigned long stime = 0, etime = 0;
    unsigned char lock = 0;
    unsigned int DemodStatus = 0, BwRequest = 0, FreqRequest = 0;
    unsigned int SpecMemType = 0, SpecMemPtr = 0, RegVal = 0;

    REALTEK_I_DVBS* pRealtekIDVBS;
    DVBS_DEMOD_MODULE* pDemod;
    pRealtekIDVBS = (REALTEK_I_DVBS*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS_DRIVER_DATA*) pRealtekIDVBS->m_private)->pDemod;

    REALTEK_I_DVBS_ChangeStandard(pDemodKernel, Mode);

    pDemodKernel->Lock(pDemodKernel);

	ret	|= pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_DETECT);

    stime = tv_osal_time();
    lock = NO;
    while ((tv_osal_time() - stime) <= 2000) {
        tv_osal_msleep(5);

		ret	|= pDemod->GetVirtualRegister(pDemod, TV_REG_ACTIVE_TUNER_BW, NULL_SEC_ADDR, &BwRequest);
		ret	|= pDemod->GetVirtualRegister(pDemod, TV_REG_ACTIVE_TUNER_FREQ, NULL_SEC_ADDR, &FreqRequest);

        if(BwRequest!=0 && FreqRequest!=0xFFFFFFFF)
        {
			ret	|= pDemod->SetVirtualRegister(pDemod, TV_REG_TUNER_BW, NULL_SEC_ADDR, BwRequest);
			FreqRequest &= DVBS_BITFLD_TUNE_REQUEST;
			ret	|= pDemod->SetVirtualRegister(pDemod, DVBS_REG_TUNE_REQUEST, NULL_SEC_ADDR, FreqRequest);
        }

		ret	|= pDemod->GetVirtualRegister(pDemod, TV_REG_STATE, NULL_SEC_ADDR, &DemodStatus);
        if(DemodStatus == 3)
        {
            etime = tv_osal_time();
            lock = YES;
			ret	|= pDemod->GetVirtualRegister(pDemod, SA_REG_OUT_SPECTRUM_PTR, NULL_SEC_ADDR, &RegVal);
			SpecMemType = (RegVal & SA_BITFLD_OUT_SPECTRUM_MEM_TYPE) >> 30;
			SpecMemPtr = (RegVal & SA_BITFLD_OUT_SPECTRUM_PTR);
			ret	|= pDemod->GetVirtualRegister(pDemod, SA_OUT_SPECTRUM_LEN, NULL_SEC_ADDR, SpectrumLength);
			*SpectrumLength &= SA_BITFLD_OUT_SPECTRUM_LEN;
            #ifdef SPEC_AN_DEBUG
            REALTEK_I_DVBS_INFO("\033[1;32;31m" "Spectrum Analyzer Done!!!\n" "\033[m");
            REALTEK_I_DVBS_INFO("\033[1;32;31m" "SpecMemType = %d, SpecMemPtr = 0x%x\n" "\033[m", SpecMemType, SpecMemPtr);
            REALTEK_I_DVBS_INFO("\033[1;32;31m" "OutSpectrumLen = %d\n" "\033[m", *SpectrumLength);
            #endif
            break;
        }
        etime = tv_osal_time();
    }
    #ifdef SPEC_AN_DEBUG
    REALTEK_I_DVBS_INFO("signal lock = %u, driver time = %lu\n", lock, etime-stime);
    #endif
    
    pDemodKernel->Unlock(pDemodKernel);
	
    static unsigned int DemodVirAddrStart = NULL;
    static unsigned int DemodVirAddrtEnd = NULL;

    DemodVirAddrStart = phys_to_virt(DEMOD_MEM_START_PHYS);
    DemodVirAddrtEnd = phys_to_virt(DEMOD_MEM_END_PHYS);

    #ifdef SPEC_AN_DEBUG
    REALTEK_I_DVBS_INFO("spectrum address = 0x%x\n", ((SpecMemPtr-0x840000)<<2)+0x100000);
    #endif

    memcpy(SpectrumArray, (DemodVirAddrStart+((SpecMemPtr-0x840000)<<2)+0x100000), (*SpectrumLength*2));

    dmac_flush_range(DemodVirAddrStart, DemodVirAddrtEnd);
    outer_flush_range(DEMOD_MEM_START_PHYS, DEMOD_MEM_END_PHYS);

    #ifdef INVERSE_SPECTRUM
    REALTEK_I_DVBS_ReverseArray(SpectrumArray, *SpectrumLength);
    #endif

    #ifdef SPEC_AN_DEBUG
    unsigned int x = 0;
    REALTEK_I_DVBS_INFO("\033[1;32;31m" "====================================\n" "\033[m");
    for(x=0;x<*SpectrumLength;x++)
    {
        printk("\033[1;32;31m" "%d\n" "\033[m", SpectrumArray[x]);
    }
    REALTEK_I_DVBS_INFO("\033[1;32;31m" "====================================\n" "\033[m");
    #endif

    return TUNER_CTRL_OK;
}


/*----------------------------------------------------------------------
 * Func : SpecAnGetCp1Cp2
 *
 * Desc : Get cross points in the spectrum.
 *
 * Parm : SpectrumArray : Input spectrum data
 *        CutTh : Set threshold for finding cross points
 *        CutSp : Set start point for finding cross points
 *        CutEp : Set end point for finding cross points
 *        ReturnCp1 : Cross point 1 result
 *        ReturnCp2 : Cross point 2 result
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS_SpecAnGetCp1Cp2(
    DEMOD* pDemodKernel, 
    unsigned short *SpectrumArray,
    unsigned int CutTh, 
    unsigned int CutSp, 
    unsigned int CutEp, 
    unsigned int *ReturnCp1, 
    unsigned int *ReturnCp2
)
{
    unsigned int SpecIdx = 0, Cp1 = -1, Cp2 = -1, Cp1Pwr = -1, Cp2Pwr = -1, Cp1Done = 0;

    *ReturnCp1 = Cp1;
    *ReturnCp2 = Cp2;

    for(SpecIdx=CutSp; SpecIdx<CutEp; SpecIdx++)
    {
        if(SpectrumArray[SpecIdx-1]<CutTh && SpectrumArray[SpecIdx]>=CutTh && Cp1Done == 0)
        {
            *ReturnCp1 = SpecIdx;
            Cp1Pwr = SpectrumArray[SpecIdx];
            Cp1Done = 1;
            #ifdef SPEC_AN_DEBUG
            REALTEK_I_DVBS_INFO("\033[1;32;31m" "Cp1 = %u\n" "\033[m", *ReturnCp1);
            REALTEK_I_DVBS_INFO("\033[1;32;31m" "Cp1 SpectrumArray[SpecIdx-1] = %u\n" "\033[m", SpectrumArray[SpecIdx-1]);
            REALTEK_I_DVBS_INFO("\033[1;32;31m" "Cp1 SpectrumArray[SpecIdx] = %u\n" "\033[m", SpectrumArray[SpecIdx]);
            #endif
        }
        if(SpectrumArray[SpecIdx-1]>CutTh && SpectrumArray[SpecIdx]<=CutTh && Cp1Done == 1)
        {
            *ReturnCp2 = SpecIdx;
            Cp2Pwr = SpectrumArray[SpecIdx];
            #ifdef SPEC_AN_DEBUG
            REALTEK_I_DVBS_INFO("\033[1;32;31m" "Cp2 = %u\n" "\033[m", *ReturnCp2);
            REALTEK_I_DVBS_INFO("\033[1;32;31m" "Cp2 SpectrumArray[SpecIdx-1] = %u\n" "\033[m", SpectrumArray[SpecIdx-1]);
            REALTEK_I_DVBS_INFO("\033[1;32;31m" "Cp2 SpectrumArray[SpecIdx] = %u\n" "\033[m", SpectrumArray[SpecIdx]);
            #endif
            break;
        }
    }
    
    return TUNER_CTRL_OK;
}


/*----------------------------------------------------------------------
 * Func : SpecAnCalCfoCsr
 *
 * Desc : Calculate signal carrier frequency offset and course symbol rate.
 *
 * Parm : Mode : Calculation mode
 *        Cp1 : Input cross point 1
 *        Cp2 : Input cross point 2
 *        SigCfo : Carrier frequency offset calculation result
 *        SigCsr : Course symbol rate calculation result
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS_SpecAnCalCfoCsr(DEMOD* pDemodKernel, unsigned int Mode, unsigned int Cp1, unsigned int Cp2, int *SigCfo, unsigned int *SigCsr)
{
    REALTEK_I_DVBS* pRealtekIDVBS;
    DVBS_DEMOD_MODULE* pDemod;
    pRealtekIDVBS = (REALTEK_I_DVBS*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS_DRIVER_DATA*) pRealtekIDVBS->m_private)->pDemod;
    
    if(Cp1 != -1 && Cp2 != -1)
    {
        #ifdef SPEC_AN_DEBUG
        REALTEK_I_DVBS_INFO("\033[1;32;32m" "Full Signal Found\n" "\033[m");
        #endif

        //if(Mode == REALTEK_I_SPEC_AN_BS_MODE)
        //{
        //    *SigCfo = (((Cp1+Cp2)/2)-(pRealtekIDVBS->m_blindscan_spectrum_len/2))*BS_FFT_RESOLUTION;
        //    *SigCsr = (Cp2-Cp1)*BS_FFT_RESOLUTION;
        //
        //    if((Cp2-Cp1)*BS_FFT_RESOLUTION >= 27500000) //>27.5M
        //    {
        //        #ifdef SPEC_AN_DEBUG
        //        REALTEK_I_DVBS_INFO("\033[1;32;32m" "Csr >= 10M; Csr*1.3\n" "\033[m");
        //        #endif
        //        *SigCsr = *SigCsr*13/10;
        //    }
        //}
        //else if(Mode == REALTEK_I_SPEC_AN_CFO_MODE)
        //{
            *SigCfo = (((Cp1+Cp2)/2)-(pRealtekIDVBS->m_carrier_spectrum_len/2))*CFO_FFT_RESOLUTION;
            *SigCsr = (Cp2-Cp1)*CFO_FFT_RESOLUTION;
        //}
    }
    else
    {
        #ifdef SPEC_AN_DEBUG
        REALTEK_I_DVBS_INFO("\033[1;32;32m" "Not Full Signal\n" "\033[m");
        #endif
        *SigCfo = 0;
        *SigCsr = 0;
    }
    #ifdef SPEC_AN_DEBUG
    REALTEK_I_DVBS_INFO("\033[1;32;32m" "Cal Cfo=%d; Csr=%u\n" "\033[m", *SigCfo, *SigCsr);
    #endif

    return TUNER_CTRL_OK;
}


/*----------------------------------------------------------------------
 * Func : SpecAnSearchMaxMin
 *
 * Desc : Get max and min level in the spectrum.
 *
 * Parm : SpectrumArray : Input spectrum data
 *        Sp : Start search point
 *        Ep : End search point
 *        MaxPower : Max level of input spectrum between Sp and Ep
 *        MinPower : Min level of input spectrum between Sp and Ep
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS_SpecAnSearchMaxMin(DEMOD* pDemodKernel, unsigned short *SpectrumArray, unsigned int Sp, unsigned int Ep, unsigned int *MaxPower, unsigned int *MinPower)
{
    unsigned int SpecIdx = 0;

    *MaxPower = SpectrumArray[0];
    *MinPower = SpectrumArray[0];

    for(SpecIdx=Sp; SpecIdx<Ep; SpecIdx++)
    {
        if(SpectrumArray[SpecIdx]>*MaxPower)
            *MaxPower = SpectrumArray[SpecIdx];
        if(SpectrumArray[SpecIdx]<*MinPower)
            *MinPower = SpectrumArray[SpecIdx];
    }
    return TUNER_CTRL_OK;
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
int REALTEK_I_DVBS_AcquireSignal(DEMOD* pDemodKernel, unsigned char WaitSignalLock)
{
    return REALTEK_I_DVBS_AcquireSignalEx(pDemodKernel, WaitSignalLock,0,NULL);
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
int REALTEK_I_DVBS_AcquireSignalEx(DEMOD* pDemodKernel, unsigned char WaitSignalLock, unsigned char  DiseqcCmdCnt, const unsigned char     *pDiseqcCmd)
{
    unsigned long stime = 0, etime = 0;
    unsigned char lock = 0;
    unsigned int DemodStatus = 0, AcqTime = 0;
    int ret = TUNER_CTRL_OK;
    
    REALTEK_I_DVBS* pRealtekIDVBS;
    DVBS_DEMOD_MODULE* pDemod;
    pRealtekIDVBS = (REALTEK_I_DVBS*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS_DRIVER_DATA*) pRealtekIDVBS->m_private)->pDemod;

    pRealtekIDVBS->m_dvbs_freq_offset = 0;
    #ifdef PULL_IN_RANGE_ENHANCEMENT
    if(pRealtekIDVBS->m_current_bw < 15000000 && pRealtekIDVBS->m_current_bw >= 1800000)
    {
        stime = tv_osal_time();
        REALTEK_I_DVBS_GetSignalCarrierFrequencyOffset(pDemodKernel, &pRealtekIDVBS->m_dvbs_freq_offset);
        //pRealtekIDVBS->m_dvbs_freq_offset = -(pRealtekIDVBS->m_dvbs_freq_offset);
        if(pRealtekIDVBS->m_current_bw == 5000000 && (pRealtekIDVBS->m_dvbs_freq_offset > 4400000 || pRealtekIDVBS->m_dvbs_freq_offset < -4400000))
        {
            pRealtekIDVBS->m_dvbs_freq_offset = 0;
        }
        else if(pRealtekIDVBS->m_current_bw == 4420000 && (pRealtekIDVBS->m_dvbs_freq_offset > 4000000 || pRealtekIDVBS->m_dvbs_freq_offset < -4000000))
        {
            pRealtekIDVBS->m_dvbs_freq_offset = 0;
        }
        etime = tv_osal_time();
        REALTEK_I_DVBS_INFO("Final m_dvbs_freq_offset = %d\n", pRealtekIDVBS->m_dvbs_freq_offset);
        REALTEK_I_DVBS_INFO("Get Frequency Offest Time = %d\n", etime-stime);
    }
    #endif

    pRealtekIDVBS->m_auto_tune_en = 0;
    AcqTime = 0;
    
    REALTEK_I_DVBS_ChangeStandard(pDemodKernel, REALTEK_I_DVBS_MODE);

    pDemodKernel->Lock(pDemodKernel);
	ret	|= pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_STOP);
	ret	|= pDemod->SetVirtualRegister(pDemod, DVBS_REG_TUNED_FREQ_OFFSET, NULL_SEC_ADDR, (unsigned int)pRealtekIDVBS->m_dvbs_freq_offset & DVBS_BITFLD_TUNED_FREQ_OFFSET);
    REALTEK_I_DVBS_INFO("DvbSSetTunedFreqOffset = %d\n", pRealtekIDVBS->m_dvbs_freq_offset);
	ret	|= pDemod->SetVirtualRegister(pDemod, DVBS_REG_BAUD_RATE, NULL_SEC_ADDR, pRealtekIDVBS->m_current_bw & DVBS_BITFLD_BAUD_RATE);
    REALTEK_I_DVBS_INFO("symbol_rate=%u\n", pRealtekIDVBS->m_current_bw);

    if(pRealtekIDVBS->m_dvbs_zapping_mode == 1)
    {
        REALTEK_I_DVBS_INFO("Zapping Mode\n");
		ret	|= pDemod->SetVirtualRegister(pDemod, DVBS_REG_CODE_RATE, NULL_SEC_ADDR, (unsigned int)pRealtekIDVBS->m_dvbs_manual_code_rate & DVBS_BITFLD_CODE_RATE);
        REALTEK_I_DVBS_INFO("code_rate=%u\n", (unsigned int)pRealtekIDVBS->m_dvbs_manual_code_rate);
		ret	|= pDemod->SetVirtualRegister(pDemod, DVBS_REG_SPECTRUM_INVERSION, NULL_SEC_ADDR, (unsigned int)pRealtekIDVBS->m_dvbs_manual_spec_invert & DVBS_BITFLD_SPECTRUM_INVERSION);
        REALTEK_I_DVBS_INFO("spec_invert=%u\n", (unsigned int)pRealtekIDVBS->m_dvbs_manual_spec_invert);
    }
    //else
    //{
	//  ret	|= pDemod->SetVirtualRegister(pDemod, DVBS_REG_CODE_RATE, NULL_SEC_ADDR, (unsigned int)0 & DVBS_BITFLD_CODE_RATE);
	//  ret	|= pDemod->SetVirtualRegister(pDemod, DVBS_REG_SPECTRUM_INVERSION, NULL_SEC_ADDR, (unsigned int)0 & DVBS_BITFLD_SPECTRUM_INVERSION);
    //}

	ret	|= pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_DETECT);

    //Set Bandwidth and Frequency to Acknowledge Demod to Lock
	ret	|= pDemod->SetVirtualRegister(pDemod, TV_REG_TUNER_BW, NULL_SEC_ADDR, (unsigned int)pRealtekIDVBS->m_info.dvbs.symbol_rate);
	ret	|= pDemod->SetVirtualRegister(pDemod, DVBS_REG_TUNE_REQUEST, NULL_SEC_ADDR, 1500000000 & DVBS_BITFLD_TUNE_REQUEST);//Set Frequency and Bandwidth together

    if (!WaitSignalLock)
    {
        pDemodKernel->Unlock(pDemodKernel);

        pRealtekIDVBS->m_auto_tune_en = 1;
        pRealtekIDVBS->m_PreUbc = 0;

        return TUNER_CTRL_OK;
    }

    /*
    //Timo@20160606 Depend on Symbol Rate to Set DVBS Acquisition Time Out Value
    pRealtekIDVBS->m_AcqTimeOut = 10000;
    for(u8i = 0; u8i < DVBS_ACQ_TIMEOUT_TABLE_SIZE; u8i++)
    {
        if((pRealtekIDVBS->m_current_bw/1000) >= _sDvbSLockTimeOutTable[u8i].SymbolRateKhz)
        {
            pRealtekIDVBS->m_AcqTimeOut = _sDvbSLockTimeOutTable[u8i].TimeOutMs;
            break;
        }
    }
    REALTEK_I_DVBS_INFO("DVBS Acq TimeOut = %d\n", m_AcqTimeOut);
    */
    pRealtekIDVBS->m_AcqTimeOut = 2300;
    if(pRealtekIDVBS->m_current_bw == 0)
    {
        pRealtekIDVBS->m_AcqTimeOut = 0;
    }
    REALTEK_I_DVBS_INFO("DVBS Acq TimeOut = %d\n", pRealtekIDVBS->m_AcqTimeOut);

    stime = tv_osal_time();
    lock = NO;

    while ((tv_osal_time() - stime) <= pRealtekIDVBS->m_AcqTimeOut) { //increase timeout for low symbol rate locking time
        tv_osal_msleep(5);
    
		ret	|= pDemod->GetVirtualRegister(pDemod, TV_REG_STATE, NULL_SEC_ADDR, &DemodStatus);

        if(DemodStatus == 5)
        {
            etime = tv_osal_time();
            lock = YES;
            pRealtekIDVBS->m_PreUbc = 0;
			ret	|= pDemod->GetVirtualRegister(pDemod, DVBS_REG_ACQUISITION_TIME, NULL_SEC_ADDR, &AcqTime);
			AcqTime  &= DVBS_BITFLD_ACQUISITION_TIME;
            REALTEK_I_DVBS_INFO("\033[1;32;31m" "DVBS Signal Lock!!!\n" "\033[m");
            break;
        }
        if(DiseqcCmdCnt>0)
        {
            pDemod->SetDiseqcCmd(DiseqcCmdCnt, (unsigned char*)pDiseqcCmd);
            tv_osal_msleep((3*8*DiseqcCmdCnt)/2+15+10-5);
        
        }
        etime = tv_osal_time();
    }
    REALTEK_I_DVBS_INFO("signal lock = %u, driver time = %lu, HW time = %lu\n", lock, etime-stime, AcqTime);

    pRealtekIDVBS->m_auto_tune_en = 1;

    pDemodKernel->Unlock(pDemodKernel);

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
int REALTEK_I_DVBS_ScanSignal(DEMOD* pDemodKernel, long* pOffset, SCAN_RANGE range)
{
    REALTEK_I_DVBS* pRealtekIDVBS;
    DVBS_DEMOD_MODULE* pDemod;
    pRealtekIDVBS = (REALTEK_I_DVBS*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS_DRIVER_DATA*) pRealtekIDVBS->m_private)->pDemod;

    pDemodKernel->Lock(pDemodKernel);

    pDemodKernel->Unlock(pDemodKernel);

    return TUNER_CTRL_FAIL;
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
int REALTEK_I_DVBS_ForwardI2C(DEMOD* pDemodKernel, unsigned char on_off)
{
    int ret = TUNER_CTRL_OK;

    REALTEK_I_DVBS* pRealtekIDVBS;
    DVBS_DEMOD_MODULE* pDemod;
    pRealtekIDVBS = (REALTEK_I_DVBS*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS_DRIVER_DATA*) pRealtekIDVBS->m_private)->pDemod;

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
int REALTEK_I_DVBS_AutoTune(DEMOD* pDemodKernel)
{
    #ifdef PULL_IN_RANGE_ENHANCEMENT
    unsigned char lock = 0;
    unsigned int DemodStatus = 0;
    static unsigned long stime = 0, cfo_stime = 0, cfo_etime = 0;
    int ret = TUNER_CTRL_OK;
    
    REALTEK_I_DVBS* pRealtekIDVBS;
    pRealtekIDVBS = (REALTEK_I_DVBS*)(pDemodKernel->private_data);
    DVBS_DEMOD_MODULE* pDemod = ((REALTEK_I_DVBS_DRIVER_DATA*) pRealtekIDVBS->m_private)->pDemod;

    if(pRealtekIDVBS->m_auto_tune_en)
    {
        if(pRealtekIDVBS->m_current_bw < 15000000 && pRealtekIDVBS->m_current_bw >= 1800000)
        {
            if(stime == 0)
                stime = tv_osal_time();
            
            if(tv_osal_time() - stime >= (pRealtekIDVBS->m_AcqTimeOut+600))
            {
                pDemodKernel->Lock(pDemodKernel);
				ret	|= pDemod->GetVirtualRegister(pDemod, TV_REG_STATE, NULL_SEC_ADDR, &DemodStatus);
                pDemodKernel->Unlock(pDemodKernel);
                
                if(DemodStatus != 5)
                {
                    pDemodKernel->Lock(pDemodKernel);

                    pRealtekIDVBS->m_dvbs_freq_offset = 0;
                    cfo_stime = tv_osal_time();
                    REALTEK_I_DVBS_GetSignalCarrierFrequencyOffset(pDemodKernel, &pRealtekIDVBS->m_dvbs_freq_offset);
                    //pRealtekIDVBS->m_dvbs_freq_offset = -(pRealtekIDVBS->m_dvbs_freq_offset);
                    if(pRealtekIDVBS->m_current_bw == 5000000 && (pRealtekIDVBS->m_dvbs_freq_offset > 4400000 || pRealtekIDVBS->m_dvbs_freq_offset < -4400000))
                    {
                        pRealtekIDVBS->m_dvbs_freq_offset = 0;
                    }
                    else if(pRealtekIDVBS->m_current_bw == 4420000 && (pRealtekIDVBS->m_dvbs_freq_offset > 4000000 || pRealtekIDVBS->m_dvbs_freq_offset < -4000000))
                    {
                        pRealtekIDVBS->m_dvbs_freq_offset = 0;
                    }
                    cfo_etime = tv_osal_time();
                    REALTEK_I_DVBS_INFO("Final m_dvbs_freq_offset = %d\n", pRealtekIDVBS->m_dvbs_freq_offset);
                    REALTEK_I_DVBS_INFO("Get Frequency Offest Time = %d\n", cfo_etime-cfo_stime);

                    REALTEK_I_DVBS_ChangeStandard(pDemodKernel, REALTEK_I_DVBS_MODE);
					ret	|= pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_STOP);
					ret	|= pDemod->SetVirtualRegister(pDemod, DVBS_REG_TUNED_FREQ_OFFSET, NULL_SEC_ADDR, (unsigned int)pRealtekIDVBS->m_dvbs_freq_offset & DVBS_BITFLD_TUNED_FREQ_OFFSET);
                    REALTEK_I_DVBS_INFO("DvbSSetTunedFreqOffset = %d\n", pRealtekIDVBS->m_dvbs_freq_offset);
					ret	|= pDemod->SetVirtualRegister(pDemod, DVBS_REG_BAUD_RATE, NULL_SEC_ADDR, pRealtekIDVBS->m_current_bw & DVBS_BITFLD_BAUD_RATE);
                    REALTEK_I_DVBS_INFO("symbol_rate=%u\n", pRealtekIDVBS->m_current_bw);

                    ret	|= pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_DETECT);

                    //Set Bandwidth and Frequency to Acknowledge Demod to Lock
					ret	|= pDemod->SetVirtualRegister(pDemod, TV_REG_TUNER_BW, NULL_SEC_ADDR, (unsigned int)pRealtekIDVBS->m_info.dvbs.symbol_rate);
					ret	|= pDemod->SetVirtualRegister(pDemod, DVBS_REG_TUNE_REQUEST, NULL_SEC_ADDR, 1500000000 & DVBS_BITFLD_TUNE_REQUEST);//Set Frequency and Bandwidth together

                    pDemodKernel->Unlock(pDemodKernel);
                }
                stime = tv_osal_time();
            }
            pRealtekIDVBS->m_auto_tune_en = 1;
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
int REALTEK_I_DVBS_InspectSignal(DEMOD* pDemodKernel)
{
    unsigned int DemodStatus = 0, SigLock = 0, Per = 0, Snr = 0, TsPktCnt = 0, AcqTime = 0;
    float SnrResult = 0, PerResult = 0;
    int ret = TUNER_CTRL_OK;
    
    REALTEK_I_DVBS* pRealtekIDVBS;
    DVBS_DEMOD_MODULE* pDemod;
    pRealtekIDVBS = (REALTEK_I_DVBS*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS_DRIVER_DATA*) pRealtekIDVBS->m_private)->pDemod;

    if (!DtvIsDemodClockEnable(RTK_DEMOD_MODE_DVBS))
        return 0;

    pDemodKernel->Lock(pDemodKernel);

	ret	|= pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_UPDATE_COUNTERS);

	ret	|= pDemod->GetVirtualRegister(pDemod, TV_REG_STATE, NULL_SEC_ADDR, &DemodStatus);
    if((ret == TUNER_CTRL_OK)&&(DemodStatus == 5))
        SigLock = YES;
    else
        SigLock = NO;

	ret	|= pDemod->GetVirtualRegister(pDemod, DVBS_REG_SNR_ESTIMATE, NULL_SEC_ADDR, &Snr);
	Snr &= DVBS_BITFLD_SNR_ESTIMATE;
    SnrResult = ((double)Snr)/65536;
	ret	|= pDemod->GetVirtualRegister(pDemod, DVBS_REG_PER_AT_OUTPUT, NULL_SEC_ADDR, &Per);
	Per &= DVBS_BITFLD_PER_AT_OUTPUT;
    PerResult = ((double)Per)/4294967296;
	ret	|= pDemod->GetVirtualRegister(pDemod, DVBS_REG_TS_PACKET_COUNT, NULL_SEC_ADDR, &TsPktCnt);
	TsPktCnt &= DVBS_BITFLD_TS_PACKET_COUNT;
	ret	|= pDemod->GetVirtualRegister(pDemod, DVBS_REG_ACQUISITION_TIME, NULL_SEC_ADDR, &AcqTime);
	AcqTime  &= DVBS_BITFLD_ACQUISITION_TIME;

    pDemodKernel->Unlock(pDemodKernel);

    #if 0
    ret = snprintf(pBuff, BufferSize, "[REALTEK_I_DVBS] lock=%u, snr=%f, error_rate(PktER)=%f, ts_pkt_cnt=%u, demod_lock_time=%u\n",
                SigLock, (double)Snr,
                (double)PerResult, TsPktCnt, AcqTime);
#endif

    return ret;
}


/*----------------------------------------------------------------------
 * Func : Activate
 *
 * Desc : Activate REALTEK_I_ QAM Demod
 *
 * Parm : N/A
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS_Activate(DEMOD* pDemodKernel, unsigned char force_rst)
{
    REALTEK_I_DVBS* pRealtekIDVBS;
    DVBS_DEMOD_MODULE* pDemod;
    pRealtekIDVBS = (REALTEK_I_DVBS*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS_DRIVER_DATA*) pRealtekIDVBS->m_private)->pDemod;

    pDemodKernel->Init(pDemodKernel);

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
 * Parm : mode :    RTK_DEMOD_MODE_DVBS : DVBS mode
 *                  RTK_DEMOD_MODE_DVBC  : DVBC mode
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS_SetTvMode(DEMOD* pDemodKernel, TV_SYSTEM_TYPE mode)
{
    int ret = TUNER_CTRL_FAIL;
    REALTEK_I_DVBS* pRealtekIDVBS;
    pRealtekIDVBS = (REALTEK_I_DVBS*)(pDemodKernel->private_data);

    pDemodKernel->Lock(pDemodKernel);

    REALTEK_I_DVBS_INFO("REALTEK_I_DVBS::SetTvMode(%d)\n", mode);

    switch (mode) {

    case TV_SYS_TYPE_DVBS:

        REALTEK_I_DVBS_INFO("Set to DVBS\n");
        ret = pDemodKernel->Init(pDemodKernel);
        ret |= pDemodKernel->SetTSMode(pDemodKernel, &pDemodKernel->m_ts);

        if (ret != TUNER_CTRL_OK) {
            REALTEK_I_DVBS_WARNING("Set REALTEK_I_DVBS to DVBS mode failed\n");
            goto set_demod_mode_failed;
        }

        break;

    default:
        goto set_demod_mode_failed;
    }

    ret = TUNER_CTRL_OK;
    REALTEK_I_DVBS_INFO("Set REALTEK_I_DVBS to appointed DTV mode successed\n");


//end_proc:

    pDemodKernel->Unlock(pDemodKernel);
    return ret;

//--------------
set_demod_mode_failed:
    pDemodKernel->Unlock(pDemodKernel);

    return TUNER_CTRL_FAIL;
}


void REALTEK_I_DVBS_Lock(DEMOD* pDemodKernel)
{
    //mutex_lock(&pDemodKernel->m_lock);
}


void REALTEK_I_DVBS_Unlock(DEMOD* pDemodKernel)
{
    //mutex_unlock(&pDemodKernel->m_lock);
}


/*-----------------------------------------------------------------
 *     BASE_INTERFACE for REALTEK_I_DVBS API
 *----------------------------------------------------------------*/


void ReleaseRealtekIDvbsDriver(REALTEK_I_DVBS_DRIVER_DATA *pDriver)
{
    kfree(pDriver);
}


REALTEK_I_DVBS_DRIVER_DATA* AllocRealtekIDvbsDriver(
    COMM*               pComm,
    unsigned char       Addr,
    unsigned long       CrystalFreq
)
{
    REALTEK_I_DVBS_DRIVER_DATA* pDriver = (REALTEK_I_DVBS_DRIVER_DATA*) kmalloc(
                                            sizeof(REALTEK_I_DVBS_DRIVER_DATA) +
                                            sizeof(DVBS_DEMOD_MODULE)   +
                                            sizeof(I2C_BRIDGE_MODULE)   +
                                            sizeof(BASE_INTERFACE_MODULE), GFP_KERNEL);

    if (pDriver) {
        BASE_INTERFACE_MODULE* pBIF;
        DVBS_DEMOD_MODULE* pDemod;
        memset(pDriver, 0, sizeof(REALTEK_I_DVBS_DRIVER_DATA));

        pDriver->pDemod                = (DVBS_DEMOD_MODULE*)(((unsigned char*)pDriver) + sizeof(REALTEK_I_DVBS_DRIVER_DATA));
        pDriver->pBaseInterface        = (BASE_INTERFACE_MODULE*)(((unsigned char*)pDriver->pDemod) + sizeof(DVBS_DEMOD_MODULE));
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
        BuildRealtekIDvbsModule(&pDemod,
                               pDriver->pDemod,
                               pDriver->pBaseInterface,
                               pDriver->pI2CBridge,
                               Addr,
                               CrystalFreq);            // Spectrum mode is inverse.
    }

    return pDriver;
}


/*----------------------------------------------------------------------
 * Func : GetChannelInfo
 *
 * Desc : GetChannelInfo
 *        This function should be called after acquisition lock.
 *
 * Parm : 
 *
 *
 * Retn : TUNER_CTRL_OK / TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS_GetChannelInfo(DEMOD* pDemodKernel, unsigned char* Modulation, unsigned char* CodeRate, unsigned char* PilotOnOff, unsigned char* Inverse)
{
    unsigned char lock = 0;
    unsigned int DemodStatus = 0, GetValue = 0;
    int ret = TUNER_CTRL_OK;

    REALTEK_I_DVBS* pRealtekIDVBS;
    DVBS_DEMOD_MODULE* pDemod;
    pRealtekIDVBS = (REALTEK_I_DVBS*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS_DRIVER_DATA*) pRealtekIDVBS->m_private)->pDemod;

    pDemodKernel->Lock(pDemodKernel);
    
    lock = NO;

	ret	|= pDemod->GetVirtualRegister(pDemod, TV_REG_STATE, NULL_SEC_ADDR, &DemodStatus);

    if(DemodStatus == 5)
    {
        lock = YES;

        *Modulation = 0;
        *PilotOnOff = 0;
		ret	|= pDemod->GetVirtualRegister(pDemod, DVBS_REG_ACTIVE_CODE_RATE, NULL_SEC_ADDR, &GetValue); //codeRate
		GetValue &= DVBS_BITFLD_ACTIVE_CODE_RATE;
        *CodeRate = (unsigned char)GetValue;
		ret	|= pDemod->GetVirtualRegister(pDemod, DVBS_REG_ACTIVE_SPECTRUM_INVERSION, NULL_SEC_ADDR, &GetValue);
		GetValue &= DVBS_BITFLD_ACTIVE_SPECTRUM_INVERSION;
        *Inverse = (unsigned char)GetValue;
    }
    else
    {
        *Modulation = 0;
        *CodeRate = 0;
        *PilotOnOff = 0;
        *Inverse = 0;
    }

    REALTEK_I_DVBS_INFO("\033[1;32;31m" "GetActiveModulation = %x\n" "\033[m", *Modulation);
    REALTEK_I_DVBS_INFO("\033[1;32;31m" "GetActiveCodeRate = %x\n" "\033[m", *CodeRate);
    REALTEK_I_DVBS_INFO("\033[1;32;31m" "GetActivePilotPresent = %x\n" "\033[m", *PilotOnOff);
    REALTEK_I_DVBS_INFO("\033[1;32;31m" "GetActiveSpectrumInversion = %x\n" "\033[m", *Inverse);

    pDemodKernel->Unlock(pDemodKernel);

    return (lock) ? TUNER_CTRL_OK : TUNER_CTRL_NO_SIGNAL;
}


/*----------------------------------------------------------------------
 * Func : ChangeStandard
 *
 * Desc :
 *
 * Parm :
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS_ChangeStandard(DEMOD* pDemodKernel, unsigned int Mode)
{
    int ret = TUNER_CTRL_OK;
    unsigned char PGAEnable = 0;
    IFADCGAIN PGAGain;
    unsigned int IsRpuLowReady = 0, IsRpuHighReady = 0;
    unsigned int BuildId = 0, DemodType = 0;
    unsigned int InitRetry = 0;
	unsigned int RegVal = 0;

    REALTEK_I_DVBS* pRealtekIDVBS;
    REG_VALUE_ENTRY*  OptRegTable;
    DVBS_DEMOD_MODULE* pDemod;
    pRealtekIDVBS = (REALTEK_I_DVBS*)(pDemodKernel->private_data);

    if (pDemodKernel->m_pComm == NULL || pRealtekIDVBS->m_private == NULL)
        return TUNER_CTRL_FAIL;
    
    pDemod = ((REALTEK_I_DVBS_DRIVER_DATA*) pRealtekIDVBS->m_private)->pDemod;
    
    pDemodKernel->Lock(pDemodKernel);

    pRealtekIDVBS->m_auto_tune_en = 0;
    
demod_re_init:
    if(Mode == REALTEK_I_DVBS_MODE)
    {
        DtvDemodInitialization(RTK_DEMOD_MODE_DVBS, 1);
    }
    else if(Mode == REALTEK_I_DVBS2_MODE)
    {
        DtvDemodInitialization(RTK_DEMOD_MODE_DVBS2, 1);
    }
    else //Standard == REALTEK_I_SPEC_AN_CFO_MODE || Standard == REALTEK_I_SPEC_AN_BS_MODE 
    {
        DtvDemodInitialization(RTK_DEMOD_MODE_SPEC_AN, 1);
    }

    ret |= DECODE_RET(pDemod->CheckRpuReady(pDemod, &IsRpuLowReady));//Check for Low level Header
    ret |= DECODE_RET(pDemod->CheckRpuReady(pDemod, &IsRpuHighReady));//Check for High level Msg

    if(IsRpuLowReady != 1 || IsRpuHighReady != 1)
    {
        REALTEK_I_DVBS_INFO("Waiting for Demod Init Done; Demod Has No Reply !!!!\n");
        REALTEK_I_DVBS_INFO("Waiting for Demod Init Done; Demod Has No Reply !!!!\n");
        REALTEK_I_DVBS_INFO("Waiting for Demod Init Done; Demod Has No Reply !!!!\n");
        REALTEK_I_DVBS_INFO("Waiting for Demod Init Done; Demod Has No Reply !!!!\n");
        REALTEK_I_DVBS_INFO("RpuLowReady = %d, RpuHighReady = %d\n", IsRpuLowReady, IsRpuHighReady);
        
        if(!InitRetry)
        {
            InitRetry = 1;
            REALTEK_I_DVBS_INFO("\033[1;32;32m" "RPU Auto Re-Init in Demod Init\n" "\033[m");
            goto demod_re_init;
        }
        else
        {
            goto init_fail;
        }
    }

    //Change To Buffer Mode
    REALTEK_I_DVBS_INFO("Change To Buffer Mode........\n");
    ret |= DECODE_RET(pDemod->SwitchToBuffer(pDemod));
    if (ret!= TUNER_CTRL_OK)
    {
        REALTEK_I_DVBS_INFO("Change To Buffer Mode Fail !!!!!\n");
        goto init_fail;
    }

    ret |= DECODE_RET(pDemod->ActivateCore(pDemod));

    //pDemod->SetContinue22kOnOff(DvbS_Keep_22k_on_off);

	ret	|= pDemod->GetVirtualRegister(pDemod, TV_REG_DEMOD_ID, NULL_SEC_ADDR, &DemodType);
	DemodType = ((DemodType&0xFF000000)>>24);
	ret	|= pDemod->GetVirtualRegister(pDemod, TV_REG_BUILD_ID, NULL_SEC_ADDR, &BuildId);
    REALTEK_I_DVBS_INFO("DemodType = %x, BuildId = %x\n", DemodType, BuildId);

    if(Mode == REALTEK_I_DVBS_MODE)
    {
        /*
        //DVBS 10.3.0 Support Run Time Change XML Parmeters
        ret |= DECODE_RET(pDemod->SetXmlTunerGainCtrl(pDemod, pRealtekIDVBS->m_dvbs_AgcScale|(RTK_DEMOD_XML_EXT_GAIN1<<16)|(RTK_DEMOD_XML_GAIN_POLARITY_POS<<18)));
        ret |= DECODE_RET(pDemod->SetXmlFlags(pDemod, RTK_DEMOD_XML_COMPLEX_IF|(pRealtekIDVBS->m_dvbs_Invert<<1)|(RTK_DEMOD_XML_UNSIGNED<<2)));
        ret |= DECODE_RET(pDemod->SetXmlIfFreq(pDemod, 0));
        ret |= DECODE_RET(pDemod->SetXmlTunerCfgOverride(pDemod, 0x00000001));

        ret |= DECODE_RET(pDemod->SetXmlIfClk(pDemod, 90000000));
        ret |= DECODE_RET(pDemod->SetXmlLdpcClk(pDemod, 500000000));
        ret |= DECODE_RET(pDemod->SetXmlUccClk(pDemod, 250000000));
        ret |= DECODE_RET(pDemod->SetXmlMcuClk(pDemod, 500000000));
        ret |= DECODE_RET(pDemod->SetXmlPlftCfgOverride(pDemod, 0x00000001));
        */
        
        if (pDemodKernel->SetTSMode(pDemodKernel, &pDemodKernel->m_ts) != TUNER_CTRL_OK)
            goto init_fail;

        REALTEK_I_DVBS_DBG("REALTEK_I_DVBS Init Complete\n");
    
        //Set Ber Cal Period to 1 Sec
		ret	|= pDemod->SetVirtualRegister(pDemod, DVBS_REG_NUM_SECONDS_BER_AVERAGING, NULL_SEC_ADDR, 0x00000001 & DVBS_BITFLD_NUM_SECONDS_BER_AVERAGING);
    }
    else if(Mode == REALTEK_I_SPEC_AN_CFO_MODE)
    {
		ret	|= pDemod->SetVirtualRegister(pDemod, TV_REG_TUNER_BW, NULL_SEC_ADDR, 140000000);
		ret	|= pDemod->SetVirtualRegister(pDemod, DVBS_REG_TUNE_REQUEST, NULL_SEC_ADDR, 1000000000 & DVBS_BITFLD_TUNE_REQUEST);
        //ret |= DECODE_RET(pDemod->DvbSSetSpecAnScanRange(pDemod, 0));
		ret	|= pDemod->SetVirtualRegister(pDemod, SA_SCAN_RESOLUTION, NULL_SEC_ADDR, CFO_FFT_RESOLUTION & SA_BITFLD_SCAN_RESOLUTION);
        //ret |= DECODE_RET(pDemod->SetTunerGridBase(pDemod, 0));
		ret	|= pDemod->SetVirtualRegister(pDemod, TV_REG_TUNER_GRID_INCR, NULL_SEC_ADDR, 1000000);

		RegVal |= (((8 << 8) & SA_BITFLD_AVERAGING_PERIOD_M));
		RegVal |= (2 & SA_BITFLD_AVERAGING_PERIOD_N);
		ret	|= pDemod->SetVirtualRegister(pDemod, SA_AVERAGING_PERIOD, NULL_SEC_ADDR, RegVal);
		
		RegVal |= (((0 << 9) & SA_BITFLD_ENABLE_DC_COMP));
		RegVal |= (((1 << 6) & SA_BITFLD_WINDOW));
		RegVal |= (((0 << 3) & SA_BITFLD_SIGNAL_TYPE));
		RegVal |= (0 & SA_BITFLD_MAX_PEAK_WIDTH);
		ret	|= pDemod->SetVirtualRegister(pDemod, SA_MEASUREMENT_CONTROL, NULL_SEC_ADDR, RegVal);
        //ret |= DECODE_RET(pDemod->DvbSSetSpecAnIfGainOverride(pDemod, 0, 0));
		
        if(pRealtekIDVBS->m_current_bw <= 6000000)
		{
			RegVal |= (((0 << 30) & SA_BITFLD_TUNING_STEP_AUTO));
			RegVal |= ((pRealtekIDVBS->m_current_bw*35/10) & SA_BITFLD_TUNING_STEP);
			ret	|= pDemod->SetVirtualRegister(pDemod, SA_TUNING_STEP, NULL_SEC_ADDR, RegVal);
		}
        else
		{
			RegVal |= (((0 << 30) & SA_BITFLD_TUNING_STEP_AUTO));
			RegVal |= ((pRealtekIDVBS->m_current_bw*22/10) & SA_BITFLD_TUNING_STEP);
			ret	|= pDemod->SetVirtualRegister(pDemod, SA_TUNING_STEP, NULL_SEC_ADDR, RegVal);
		}
    }
    
    pDemodKernel->Unlock(pDemodKernel);

    return TUNER_CTRL_OK;

init_fail:

    REALTEK_I_DVBS_WARNING("REALTEK_I_DVBS Init Failed\n");

    pDemodKernel->Unlock(pDemodKernel);

    return TUNER_CTRL_FAIL;
}


/*----------------------------------------------------------------------
 * Func : CalDvbSSsi
 *
 * Desc :
 *
 * Parm :
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS_CalDvbSSsi(DEMOD* pDemodKernel)
{
    unsigned int DemodStatus = 0, IfAgcGain = 0, Ssi = 0;
    int ret = TUNER_CTRL_OK;

    REALTEK_I_DVBS* pRealtekIDVBS;
    DVBS_DEMOD_MODULE* pDemod;
    pRealtekIDVBS = (REALTEK_I_DVBS*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS_DRIVER_DATA*) pRealtekIDVBS->m_private)->pDemod;
    
    pDemodKernel->Lock(pDemodKernel);

	ret	|= pDemod->GetVirtualRegister(pDemod, TV_REG_STATE, NULL_SEC_ADDR, &DemodStatus);
    ret = DECODE_RET(pDemod->GetIfAgcGain(pDemod, &IfAgcGain));
    IfAgcGain = IfAgcGain >> 20;
    
    pDemodKernel->Unlock(pDemodKernel);

    if(DemodStatus == 5)
    {
        Ssi = (((0xFFF - IfAgcGain)*40)/0xFFF)+ 60;

        if(Ssi > 100)
            Ssi = 100;
        else if(Ssi < 50)
            Ssi = 50;
    }
    else
    {
        Ssi = 0;
    }

    return Ssi;
}


/*----------------------------------------------------------------------
 * Func : CalDvbSSqi
 *
 * Desc :
 *
 * Parm :
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS_CalDvbSSqi(DEMOD* pDemodKernel)
{
    int ret = TUNER_CTRL_OK;
    unsigned int CalHighBound = 0, CalMidBound = 0, CalLowBound = 0, CodeRate = 0, DemodStatus = 0, Sqi = 0;
    unsigned char u8i = 0;

    REALTEK_I_DVBS* pRealtekIDVBS;
    DVBS_DEMOD_MODULE* pDemod;
    pRealtekIDVBS = (REALTEK_I_DVBS*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS_DRIVER_DATA*) pRealtekIDVBS->m_private)->pDemod;

    pDemodKernel->Lock(pDemodKernel);
    
	ret	|= pDemod->GetVirtualRegister(pDemod, DVBS_REG_ACTIVE_CODE_RATE, NULL_SEC_ADDR, &CodeRate); //codeRate
	CodeRate &= DVBS_BITFLD_ACTIVE_CODE_RATE;
	ret	|= pDemod->GetVirtualRegister(pDemod, TV_REG_STATE, NULL_SEC_ADDR, &DemodStatus);

    pDemodKernel->Unlock(pDemodKernel);

    if(DemodStatus == 5)
    {
        for(u8i = 0; u8i < DVBS_SIG_QUALITY_TABLE_SIZE; u8i++)
        {
            if(_gsDvbSSigQualityMappingTable[u8i].CodeRate == CodeRate)
            {
                CalHighBound = _gsDvbSSigQualityMappingTable[u8i].sBound.HighBound;
                CalMidBound = _gsDvbSSigQualityMappingTable[u8i].sBound.MidBound;
                CalLowBound = _gsDvbSSigQualityMappingTable[u8i].sBound.LowBound;
                break;
            }
        }

        if((pRealtekIDVBS->m_dvbs_snr * 10/10000) >= CalHighBound)
        {
            Sqi = 100;
        }
        else if((pRealtekIDVBS->m_dvbs_snr * 10/10000) >= CalMidBound)
        {
            Sqi = (((pRealtekIDVBS->m_dvbs_snr * 10) - (CalMidBound*10000))*40) / (CalHighBound*10000)+ 60;
        }
        else if((pRealtekIDVBS->m_dvbs_snr * 10/10000) >= CalLowBound)
        {
            Sqi = (((pRealtekIDVBS->m_dvbs_snr * 10) - (CalLowBound*10000))*40) / (CalMidBound*10000) + 20;
        }
        else
        {
            Sqi = 20;
        }
    }
    else
    {
        Sqi = 0;
    }

    return Sqi;
}


/*----------------------------------------------------------------------
 * Func : SetDiseqcContinue22kOnOff
 *
 * Desc : Set Diseqc 22K always ON/OFF
 *
 * Parm : 
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS_SetDiseqcContinue22kOnOff(DEMOD* pDemodKernel, int OnOff)
{
    REALTEK_I_DVBS* pRealtekIDVBS;
    DVBS_DEMOD_MODULE* pDemod;
    pRealtekIDVBS = (REALTEK_I_DVBS*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS_DRIVER_DATA*) pRealtekIDVBS->m_private)->pDemod;
        
    pDemod->SetContinue22kOnOff(OnOff);

    return TUNER_CTRL_OK;
}


/*----------------------------------------------------------------------
 * Func : SetDiseqcCmd
 *
 * Desc : Set Diseqc command
 *
 * Parm : 
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS_SetDiseqcCmd(DEMOD* pDemodKernel, unsigned int Length, unsigned char *Data)
{
    REALTEK_I_DVBS* pRealtekIDVBS;
    DVBS_DEMOD_MODULE* pDemod;
    pRealtekIDVBS = (REALTEK_I_DVBS*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS_DRIVER_DATA*) pRealtekIDVBS->m_private)->pDemod;
        
    pDemod->SetDiseqcCmd(Length, Data);

    return TUNER_CTRL_OK;
}


/*----------------------------------------------------------------------
 * Func : SetDiseqcUnModToneBurst
 *
 * Desc : Set Un-Modulated Tone Burst(SA)
 *
 * Parm : 
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS_SetDiseqcUnModToneBurst(DEMOD* pDemodKernel)
{
    REALTEK_I_DVBS* pRealtekIDVBS;
    DVBS_DEMOD_MODULE* pDemod;
    pRealtekIDVBS = (REALTEK_I_DVBS*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS_DRIVER_DATA*) pRealtekIDVBS->m_private)->pDemod;
        
    pDemod->SetUnModToneBurst();

    return TUNER_CTRL_OK;
}


/*----------------------------------------------------------------------
 * Func : SetDiseqcModToneBurst
 *
 * Desc : Set Modulated Tone Burst(SB)
 *
 * Parm : 
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS_SetDiseqcModToneBurst(DEMOD* pDemodKernel)
{
    REALTEK_I_DVBS* pRealtekIDVBS;
    DVBS_DEMOD_MODULE* pDemod;
    pRealtekIDVBS = (REALTEK_I_DVBS*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS_DRIVER_DATA*) pRealtekIDVBS->m_private)->pDemod;
        
    pDemod->SetModToneBurst();

    return TUNER_CTRL_OK;
}

