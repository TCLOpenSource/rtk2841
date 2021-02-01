//#include <stdio.h>
#include "isdbt_demod_rtk.h"
#include "isdbt_registers.h"
#include "message_func_rtk.h"


/**

@brief   REALTEK_I DVBC demod module builder

Use BuildRealtekIDvbcModule() to build REALTEK_I DVBC module, set all module function pointers with the corresponding
functions, and initialize module private variables.


@param [in]   ppDemod                        Pointer to REALTEK_I DVBC demod module pointer
@param [in]   pDvbCDemodModuleMemory         Pointer to an allocated DVBC demod module memory
@param [in]   pBaseInterfaceModuleMemory     Pointer to an allocated base interface module memory
@param [in]   pI2cBridgeModuleMemory         Pointer to an allocated I2C bridge module memory
@param [in]   DeviceAddr                     REALTEK_I DVBC I2C device address
@param [in]   CrystalFreqHz                  REALTEK_I DVBC crystal frequency in Hz

@note
	-# One should call BuildRealtekIDvbCModule() to build REALTEK_I DVBC module before using it.

*/
void
BuildRealtekIIsdbtModule(
	ISDBT_DEMOD_MODULE **ppDemod,
	ISDBT_DEMOD_MODULE *pIsdbtDemodModuleMemory,
	BASE_INTERFACE_MODULE *pBaseInterfaceModuleMemory,
	I2C_BRIDGE_MODULE *pI2cBridgeModuleMemory,
	unsigned char DeviceAddr,
	unsigned long CrystalFreqHz
)
{
	ISDBT_DEMOD_MODULE *pDemod;

	// Set demod module pointer and get demod module.
	*ppDemod = pIsdbtDemodModuleMemory;
	pDemod = *ppDemod;

	// Set base interface module pointer and I2C bridge module pointer.
	pDemod->pBaseInterface = pBaseInterfaceModuleMemory;
	pDemod->pI2cBridge     = pI2cBridgeModuleMemory;

	// Set demod type.
	pDemod->DemodType = ISDBT_DEMOD_TYPE_REALTEK_I;

	// Set demod I2C device address.
	pDemod->DeviceAddr = DeviceAddr;

	// Set demod crystal frequency in Hz.
	pDemod->CrystalFreqHz = CrystalFreqHz;

	// Set demod TS interface mode.
	pDemod->TsInterfaceMode = NO_USE;

	// Initialize demod parameter setting status
	pDemod->IsQamModeSet       = NO;
	pDemod->IsSymbolRateHzSet  = NO;
	pDemod->IsAlphaModeSet     = NO;
	pDemod->IsIfFreqHzSet      = NO;
	pDemod->IsSpectrumModeSet  = NO;

	// Set demod module I2C function pointers with default functions.
	/*
	pDemod->RegAccess.Addr16Bit.SetRegBytes         = dvbc_demod_addr_16bit_default_SetRegBytes;
	pDemod->RegAccess.Addr16Bit.GetRegBytes         = dvbc_demod_addr_16bit_default_GetRegBytes;
	pDemod->RegAccess.Addr16Bit.GetRegMaskBits      = dvbc_demod_addr_16bit_default_GetRegMaskBits;
	pDemod->RegAccess.Addr16Bit.SetRegBits          = dvbc_demod_addr_16bit_default_SetRegBits;
	pDemod->RegAccess.Addr16Bit.GetRegBits          = dvbc_demod_addr_16bit_default_GetRegBits;
	*/

    pDemod->CheckRpuReady                           = realtek_i_isdbt_common_CheckRpuReady;
    pDemod->PingRpu                                 = realtek_i_isdbt_common_PingRpu;
    pDemod->ShutDown                                = realtek_i_isdbt_common_ShutDown;
    pDemod->ActivateCore                            = realtek_i_isdbt_common_ActivateCore;
    pDemod->DeactivateCore                          = realtek_i_isdbt_common_DeactivateCore;
    pDemod->SwitchToBuffer				            = realtek_i_isdbt_common_SwitchToBuffer;
                
    pDemod->GetDemodInfo                            = realtek_i_isdbt_common_GetDemodInfo;
    pDemod->GetBuildId                              = realtek_i_isdbt_common_GetBuildId;
                
    pDemod->DemodCtrlStop                           = realtek_i_isdbt_common_DemodCtrlStopCmd;
    pDemod->DemodCtrlDetect                         = realtek_i_isdbt_common_DemodCtrlDetectCmd;
    pDemod->DemodCtrlRun                            = realtek_i_isdbt_common_DemodCtrlRunCmd;
    pDemod->DemodCtrlUpdateRssi                     = realtek_i_isdbt_common_DemodCtrlUpdateRssiCmd;
    pDemod->DemodCtrlResetCounters                  = realtek_i_isdbt_common_DemodCtrlResetCountersCmd;
    pDemod->DemodCtrlUpdateCounters                 = realtek_i_isdbt_common_DemodCtrlUpdateCountersCmd;
    pDemod->DemodCtrlSetAgc                         = realtek_i_isdbt_common_DemodCtrlSetAgcCmd;
    pDemod->DemodCtrlUpdateAgc                      = realtek_i_isdbt_common_DemodCtrlUpdateAgcCmd;
    pDemod->DemodCtrlQueryStatus                    = realtek_i_isdbt_common_DemodCtrlQueryStatusCmd;
                
    pDemod->GetDemodStatus                          = realtek_i_isdbt_common_GetDemodStatus;
                
    pDemod->SetTunerFreq                            = realtek_i_isdbt_common_SetTunerFreqCmd;
    pDemod->SetTunerBandwidth                       = realtek_i_isdbt_common_SetTunerBandwidth;
    pDemod->SetTunerGridBase                        = realtek_i_isdbt_common_SetTunerGridBase;
    pDemod->SetTunerGridIncr                        = realtek_i_isdbt_common_SetTunerGridIncr;
    pDemod->GetActiveTunerFreq                      = realtek_i_isdbt_common_GetActiveTunerFreq;
    pDemod->GetActiveTunerBandwidth                 = realtek_i_isdbt_common_GetActiveTunerBandwidth;
    pDemod->GetActiveTunerGain                      = realtek_i_isdbt_common_GetActiveTunerGain;
    pDemod->GetActiveTunerRssi                      = realtek_i_isdbt_common_GetActiveTunerRssi;
                
    pDemod->SetNotchFreq                            = realtek_i_isdbt_common_SetNotchFreqCmd;
    pDemod->SetNotchBandwidth                       = realtek_i_isdbt_common_SetNotchBandwidth;
                
    pDemod->SetAgcParams                            = realtek_i_isdbt_common_SetAgcParams;
    pDemod->GetAgcParams                            = realtek_i_isdbt_common_GetAgcParams;
    pDemod->SetTsConfig                             = realtek_i_isdbt_common_SetTsConfig;
    pDemod->SetTsClkRateMargin                      = realtek_i_isdbt_common_SetTsClkRateMargin;
    pDemod->SetTsClkRateMax                         = realtek_i_isdbt_common_SetTsClkRateMax;
    pDemod->GetDemodLockTime                        = realtek_i_isdbt_common_GetDemodLockTime;

	pDemod->SetXmlTunerCfgOverride                  = realtek_i_isdbt_common_SetXmlTunerCfgOverride;
    pDemod->SetXmlTunerGainCtrl	                    = realtek_i_isdbt_common_SetXmlTunerGainCtrl;
    pDemod->SetXmlFlags                             = realtek_i_isdbt_common_SetXmlFlags;
    pDemod->SetXmlIfFreq                            = realtek_i_isdbt_common_SetXmlIfFreq;
    pDemod->SetXmlPlftCfgOverride                   = realtek_i_isdbt_common_SetXmlPlatformCfgOverride;
    pDemod->SetXmlIfClk                             = realtek_i_isdbt_common_SetXmlIfClk;
    pDemod->SetXmlLdpcClk                           = realtek_i_isdbt_common_SetXmlLdpcClk;
    pDemod->SetXmlUccClk                            = realtek_i_isdbt_common_SetXmlUccClk;
    pDemod->SetXmlMcuClk                            = realtek_i_isdbt_common_SetXmlMcuClk;

    pDemod->SetVirtualRegister                      = realtek_i_isdbt_common_SetVirtualRegister;
    pDemod->GetVirtualRegister                      = realtek_i_isdbt_common_GetVirtualRegister;

    pDemod->SetTunCtrlCmd                           = realtek_i_isdbt_SetTunCtrlCmd;
    pDemod->SetTunSubCh                             = realtek_i_isdbt_SetTunSubCh;
    pDemod->GetTunSubCh                             = realtek_i_isdbt_GetTunSubCh;
    pDemod->SetTunParital                           = realtek_i_isdbt_SetTunParital;
    pDemod->GetTunParital                           = realtek_i_isdbt_GetTunParital;
    pDemod->SetTunMode                              = realtek_i_isdbt_SetTunMode;
    pDemod->GetTunMode                              = realtek_i_isdbt_GetTunMode;
    pDemod->SetTunGuard                             = realtek_i_isdbt_SetTunGuard;
    pDemod->GetTunGuard                             = realtek_i_isdbt_GetTunGuard;

    pDemod->SetTunModeA                             = realtek_i_isdbt_SetTunModeA;
    pDemod->GetTunModeA                             = realtek_i_isdbt_GetTunModeA;
    pDemod->SetTunCodeRateA                         = realtek_i_isdbt_SetTunCodeRateA;
    pDemod->GetTunCodeRateA                         = realtek_i_isdbt_GetTunCodeRateA;
    pDemod->SetTunInterleaverA                      = realtek_i_isdbt_SetTunInterleaverA;
    pDemod->GetTunInterleaverA                      = realtek_i_isdbt_GetTunInterleaverA;
    pDemod->SetTunSegsA                             = realtek_i_isdbt_SetTunSegsA;
    pDemod->GetTunSegsA                             = realtek_i_isdbt_GetTunSegsA;
    pDemod->SetTunModeB                             = realtek_i_isdbt_SetTunModeB;
    pDemod->GetTunModeB                             = realtek_i_isdbt_GetTunModeB;
    pDemod->SetTunCodeRateB                         = realtek_i_isdbt_SetTunCodeRateB;
    pDemod->GetTunCodeRateB                         = realtek_i_isdbt_GetTunCodeRateB;
    pDemod->SetTunInterleaverB                      = realtek_i_isdbt_SetTunInterleaverB;
    pDemod->GetTunInterleaverB                      = realtek_i_isdbt_GetTunInterleaverB;
    pDemod->SetTunSegsB                             = realtek_i_isdbt_SetTunSegsB;
    pDemod->GetTunSegsB                             = realtek_i_isdbt_GetTunSegsB;
    pDemod->SetTunModeC                             = realtek_i_isdbt_SetTunModeC;
    pDemod->GetTunModeC                             = realtek_i_isdbt_GetTunModeC;
    pDemod->SetTunCodeRateC                         = realtek_i_isdbt_SetTunCodeRateC;
    pDemod->GetTunCodeRateC                         = realtek_i_isdbt_GetTunCodeRateC;
    pDemod->SetTunInterleaverC                      = realtek_i_isdbt_SetTunInterleaverC;
    pDemod->GetTunInterleaverC                      = realtek_i_isdbt_GetTunInterleaverC;
    pDemod->SetTunSegsC                             = realtek_i_isdbt_SetTunSegsC;
    pDemod->GetTunSegsC                             = realtek_i_isdbt_GetTunSegsC;
    pDemod->GetRegEaf                               = realtek_i_isdbt_GetRegEaf;    
    pDemod->GetRegStatTsPktCountA                   = realtek_i_isdbt_GetRegStatTsPktCountA;
    pDemod->GetRegStatTsBadPktCountA                = realtek_i_isdbt_GetRegStatTsBadPktCountA;

    pDemod->GetRegStatTsByteErrsA                   = realtek_i_isdbt_GetRegStatTsByteErrsA;
    pDemod->GetRegStatTsBitErrsA                    = realtek_i_isdbt_GetRegStatTsBitErrsA;
    pDemod->GetRegStatViterbiBerA                   = realtek_i_isdbt_GetRegStatViterbiBerA;
    pDemod->GetRegStatTsPktCountB                   = realtek_i_isdbt_GetRegStatTsPktCountB;
    pDemod->GetRegStatTsBadPktCountB                = realtek_i_isdbt_GetRegStatTsBadPktCountB;
    pDemod->GetRegStatTsByteErrsB                   = realtek_i_isdbt_GetRegStatTsByteErrsB;
    pDemod->GetRegStatTsBitErrsB                    = realtek_i_isdbt_GetRegStatTsBitErrsB;
    pDemod->GetRegStatViterbiBerB                   = realtek_i_isdbt_GetRegStatViterbiBerB;
    pDemod->GetRegStatTsPktCountC                   = realtek_i_isdbt_GetRegStatTsPktCountC;
    pDemod->GetRegStatTsBadPktCountC                = realtek_i_isdbt_GetRegStatTsBadPktCountC;
    pDemod->GetRegStatTsByteErrsC                   = realtek_i_isdbt_GetRegStatTsByteErrsC;
    pDemod->GetRegStatTsBitErrsC                    = realtek_i_isdbt_GetRegStatTsBitErrsC;
    pDemod->GetRegStatViterbiBerC                   = realtek_i_isdbt_GetRegStatViterbiBerC;
    pDemod->GetRegStatNumReaqc                      = realtek_i_isdbt_GetRegStatNumReaqc;
    pDemod->GetRegStatSnr                           = realtek_i_isdbt_GetRegStatSnr;
    pDemod->GetRegStatCarrierAcquisitionOffset      = realtek_i_isdbt_GetRegStatCarrierAcquisitionOffset;
    pDemod->GetRegStatCarrierTrackingOffset         = realtek_i_isdbt_GetRegStatCarrierTrackingOffset;
    pDemod->GetRegStatIfAgcLevel                    = realtek_i_isdbt_GetRegStatIfAgcLevel;
    pDemod->SetRegBerPeriod                         = realtek_i_isdbt_SetRegBerPeriod;
    pDemod->GetRegBerPeriod                         = realtek_i_isdbt_GetRegBerPeriod;
    pDemod->GetRegBerRsBerA                         = realtek_i_isdbt_GetRegBerRsBerA;
    pDemod->GetRegBerTsPerA                         = realtek_i_isdbt_GetRegBerTsPerA;
    pDemod->GetRegBerRsBerB                         = realtek_i_isdbt_GetRegBerRsBerB;
    pDemod->GetRegBerTsPerB                         = realtek_i_isdbt_GetRegBerTsPerB;
    pDemod->GetRegBerRsBerC                         = realtek_i_isdbt_GetRegBerRsBerC;
    pDemod->GetRegBerTsPerC                         = realtek_i_isdbt_GetRegBerTsPerC;

    pDemod->GetRegDemodFailureCode                  = realtek_i_isdbt_GetDemodFailureCode;
    pDemod->GetRegDemodFailureCountPerTimeout  	    = realtek_i_isdbt_GetDemodFailureCountPerTimeout;
    pDemod->GetRegDemodFailureCountOther  	        = realtek_i_isdbt_GetDemodFailureCountOther;
	
    pDemod->GetRegTmccGoodDecodeCount               = realtek_i_isdbt_GetRegTmccGoodDecodeCount;

    
	return;
}


/*
Tune Control ISDBT IMG Demod
*/
int
realtek_i_isdbt_SetTunCtrlCmd(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunCtrl
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    TunCtrl &= ISDBT_BITFLD_CTRL;
    
    if(MsgSetCmdReg(ISDBT_REG_CTRL, 0, TunCtrl) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}

/*
Tune SubChannel ISDBT IMG Demod
*/
int
realtek_i_isdbt_SetTunSubCh(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunSubCh
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    TunSubCh &= ISDBT_BITFLD_TUN_SUBCHANNEL;
    
    if(MsgSetReg(ISDBT_REG_TUN_SUBCHANNEL, 0, TunSubCh) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_isdbt_GetTunSubCh(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunSubCh
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(ISDBT_REG_TUN_SUBCHANNEL, 0, TunSubCh) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *TunSubCh &= ISDBT_BITFLD_TUN_SUBCHANNEL;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Tune Parital Reception ISDBT IMG Demod
*/
int
realtek_i_isdbt_SetTunParital(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunParital
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    TunParital &= ISDBT_BITFLD_TUN_PARTIAL_RECEPTION;
    
    if(MsgSetReg(ISDBT_REG_TUN_PARTIAL_RECEPTION, 0, TunParital) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_isdbt_GetTunParital(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunParital
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(ISDBT_REG_TUN_PARTIAL_RECEPTION, 0, TunParital) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *TunParital &= ISDBT_BITFLD_TUN_PARTIAL_RECEPTION;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Tune mode ISDBT IMG Demod
*/
int
realtek_i_isdbt_SetTunMode(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunMode
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    TunMode &= ISDBT_BITFLD_TUN_MODE;
    
    if(MsgSetReg(ISDBT_REG_TUN_MODE, 0, TunMode) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_isdbt_GetTunMode(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunMode
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(ISDBT_REG_TUN_MODE, 0, TunMode) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *TunMode &= ISDBT_BITFLD_TUN_MODE;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
ISDBT IMG Demod Tune GUARD 
*/
int
realtek_i_isdbt_SetTunGuard(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunGuard
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    TunGuard &= ISDBT_BITFLD_TUN_GUARD;
    
    if(MsgSetReg(ISDBT_REG_TUN_GUARD, 0, TunGuard) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_isdbt_GetTunGuard(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunGuard
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(ISDBT_REG_TUN_GUARD, 0, TunGuard) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *TunGuard &= ISDBT_BITFLD_TUN_MODE;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
ISDBT IMG Demod Tune Mode_A 
*/
int
realtek_i_isdbt_SetTunModeA(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunModeA
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    TunModeA &= ISDBT_BITFLD_TUN_MOD_A;
    
    if(MsgSetReg(ISDBT_REG_TUN_MOD_A, 0, TunModeA) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_isdbt_GetTunModeA(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunModeA
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(ISDBT_REG_TUN_MOD_A, 0, TunModeA) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *TunModeA &= ISDBT_BITFLD_TUN_MOD_A;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
ISDBT IMG Demod Tune CodeRate_A 
*/
int
realtek_i_isdbt_SetTunCodeRateA(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunCodeRateA
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    TunCodeRateA &= ISDBT_BITFLD_TUN_CODE_RATE_A;
    
    if(MsgSetReg(ISDBT_REG_TUN_CODE_RATE_A, 0, TunCodeRateA) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_isdbt_GetTunCodeRateA(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunCodeRateA
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(ISDBT_REG_TUN_CODE_RATE_A, 0, TunCodeRateA) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *TunCodeRateA &= ISDBT_BITFLD_TUN_CODE_RATE_A;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
ISDBT IMG Demod Tune Interleaver_A 
*/
int
realtek_i_isdbt_SetTunInterleaverA(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunInterleaverA
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    TunInterleaverA &= ISDBT_BITFLD_TUN_INTERLEAVER_A;
    
    if(MsgSetReg(ISDBT_REG_TUN_INTERLEAVER_A, 0, TunInterleaverA) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_isdbt_GetTunInterleaverA(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunInterleaverA
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(ISDBT_REG_TUN_INTERLEAVER_A, 0, TunInterleaverA) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *TunInterleaverA &= ISDBT_BITFLD_TUN_INTERLEAVER_A;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
ISDBT IMG Demod Tune Segments_A 
*/
int
realtek_i_isdbt_SetTunSegsA(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunSegsA
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    TunSegsA &= ISDBT_BITFLD_TUN_SEGS_A;
    
    if(MsgSetReg(ISDBT_REG_TUN_SEGS_A, 0, TunSegsA) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_isdbt_GetTunSegsA(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunSegsA
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(ISDBT_REG_TUN_SEGS_A, 0, TunSegsA) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *TunSegsA &= ISDBT_BITFLD_TUN_SEGS_A;
	if(*TunSegsA == 0xF)
		*TunSegsA = 0;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
ISDBT IMG Demod Tune Mode_B
*/
int
realtek_i_isdbt_SetTunModeB(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunModeB
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    TunModeB &= ISDBT_BITFLD_TUN_MOD_B;
    
    if(MsgSetReg(ISDBT_REG_TUN_MOD_B, 0, TunModeB) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_isdbt_GetTunModeB(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunModeB
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(ISDBT_REG_TUN_MOD_B, 0, TunModeB) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *TunModeB &= ISDBT_BITFLD_TUN_MOD_B;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
ISDBT IMG Demod Tune CodeRate_B 
*/
int
realtek_i_isdbt_SetTunCodeRateB(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunCodeRateB
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    TunCodeRateB &= ISDBT_BITFLD_TUN_CODE_RATE_B;
    
    if(MsgSetReg(ISDBT_REG_TUN_CODE_RATE_B, 0, TunCodeRateB) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_isdbt_GetTunCodeRateB(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunCodeRateB
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(ISDBT_REG_TUN_CODE_RATE_B, 0, TunCodeRateB) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *TunCodeRateB &= ISDBT_BITFLD_TUN_CODE_RATE_B;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
ISDBT IMG Demod Tune Interleaver_B 
*/
int
realtek_i_isdbt_SetTunInterleaverB(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunInterleaverB
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    TunInterleaverB &= ISDBT_BITFLD_TUN_INTERLEAVER_B;
    
    if(MsgSetReg(ISDBT_REG_TUN_INTERLEAVER_B, 0, TunInterleaverB) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_isdbt_GetTunInterleaverB(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunInterleaverB
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(ISDBT_REG_TUN_INTERLEAVER_B, 0, TunInterleaverB) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *TunInterleaverB &= ISDBT_BITFLD_TUN_INTERLEAVER_B;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
ISDBT IMG Demod Tune Segments_B 
*/
int
realtek_i_isdbt_SetTunSegsB(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunSegsB
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    TunSegsB &= ISDBT_BITFLD_TUN_SEGS_B;
    
    if(MsgSetReg(ISDBT_REG_TUN_SEGS_B, 0, TunSegsB) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_isdbt_GetTunSegsB(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunSegsB
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(ISDBT_REG_TUN_SEGS_B, 0, TunSegsB) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *TunSegsB &= ISDBT_BITFLD_TUN_SEGS_B;
	if(*TunSegsB == 0xF)
		*TunSegsB = 0;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
ISDBT IMG Demod Tune Mode_C
*/
int
realtek_i_isdbt_SetTunModeC(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunModeC
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    TunModeC &= ISDBT_BITFLD_TUN_MOD_C;
    
    if(MsgSetReg(ISDBT_REG_TUN_MOD_C, 0, TunModeC) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_isdbt_GetTunModeC(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunModeC
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(ISDBT_REG_TUN_MOD_C, 0, TunModeC) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *TunModeC &= ISDBT_BITFLD_TUN_MOD_C;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
ISDBT IMG Demod Tune CodeRate_C 
*/
int
realtek_i_isdbt_SetTunCodeRateC(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunCodeRateC
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    TunCodeRateC &= ISDBT_BITFLD_TUN_CODE_RATE_C;
    
    if(MsgSetReg(ISDBT_REG_TUN_CODE_RATE_C, 0, TunCodeRateC) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_isdbt_GetTunCodeRateC(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunCodeRateC
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(ISDBT_REG_TUN_CODE_RATE_C, 0, TunCodeRateC) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *TunCodeRateC &= ISDBT_BITFLD_TUN_CODE_RATE_C;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
ISDBT IMG Demod Tune Interleaver_C 
*/
int
realtek_i_isdbt_SetTunInterleaverC(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunInterleaverC
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    TunInterleaverC &= ISDBT_BITFLD_TUN_INTERLEAVER_C;
    
    if(MsgSetReg(ISDBT_REG_TUN_INTERLEAVER_C, 0, TunInterleaverC) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_isdbt_GetTunInterleaverC(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunInterleaverC
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(ISDBT_REG_TUN_INTERLEAVER_C, 0, TunInterleaverC) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *TunInterleaverC &= ISDBT_BITFLD_TUN_INTERLEAVER_C;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
ISDBT IMG Demod Tune Segments_C 
*/
int
realtek_i_isdbt_SetTunSegsC(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunSegsC
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    TunSegsC &= ISDBT_BITFLD_TUN_SEGS_C;
    
    if(MsgSetReg(ISDBT_REG_TUN_SEGS_C, 0, TunSegsC) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_isdbt_GetTunSegsC(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunSegsC
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(ISDBT_REG_TUN_SEGS_C, 0, TunSegsC) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *TunSegsC &= ISDBT_BITFLD_TUN_SEGS_C;
	if(*TunSegsC == 0xF)
		*TunSegsC = 0;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
ISDBT Emergency Alarm Flag
*/
int
realtek_i_isdbt_GetRegEaf(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegEaf
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(ISDBT_REG_EAF, 0, RegEaf) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *RegEaf &= ISDBT_BITFLD_EAF;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}

/*
ISDBT IMG Demod Status number of TS packets counted
*/
int
realtek_i_isdbt_GetRegStatTsPktCountA(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatTsPktCountA
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(ISDBT_REG_STAT_TS_PKT_COUNT_A, 0, RegStatTsPktCountA) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *RegStatTsPktCountA &= ISDBT_BITFLD_STAT_TS_PKT_COUNT_A;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
ISDBT IMG Demod Status number of un-correctable TS packets
*/
int
realtek_i_isdbt_GetRegStatTsBadPktCountA(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatTsBadPktCountA
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(ISDBT_REG_STAT_TS_BAD_PKT_COUNT_A, 0, RegStatTsBadPktCountA) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *RegStatTsBadPktCountA &= ISDBT_BITFLD_STAT_TS_BAD_PKT_COUNT_A;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
ISDBT IMG Demod Status Number of bytes errors detected in TS packets
*/
int
realtek_i_isdbt_GetRegStatTsByteErrsA(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatTsByteErrsA
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(ISDBT_REG_STAT_TS_BYTE_ERRS_A, 0, RegStatTsByteErrsA) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *RegStatTsByteErrsA &= ISDBT_BITFLD_STAT_TS_BYTE_ERRS_A;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
ISDBT IMG Demod Status Number of bits errors detected in TS packets
*/
int
realtek_i_isdbt_GetRegStatTsBitErrsA(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatTsBitErrsA
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(ISDBT_REG_STAT_TS_BIT_ERRS_A, 0, RegStatTsBitErrsA) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *RegStatTsBitErrsA &= ISDBT_BITFLD_STAT_TS_BIT_ERRS_A;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
ISDBT IMG Demod Status Number of Viterbi errors in 1e6 bits
*/
int
realtek_i_isdbt_GetRegStatViterbiBerA(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatViterbiBerA
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(ISDBT_REG_VITERBI_BER_A, 0, RegStatViterbiBerA) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *RegStatViterbiBerA &= ISDBT_BITFLD_STAT_TS_VITERBI_BER_A;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
ISDBT IMG Demod Status number of TS packets counted
*/
int
realtek_i_isdbt_GetRegStatTsPktCountB(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatTsPktCountB
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(ISDBT_REG_STAT_TS_PKT_COUNT_B, 0, RegStatTsPktCountB) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *RegStatTsPktCountB &= ISDBT_BITFLD_STAT_TS_PKT_COUNT_B;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
ISDBT IMG Demod Status number of un-correctable TS packets
*/
int
realtek_i_isdbt_GetRegStatTsBadPktCountB(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatTsBadPktCountB
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(ISDBT_REG_STAT_TS_BAD_PKT_COUNT_B, 0, RegStatTsBadPktCountB) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *RegStatTsBadPktCountB &= ISDBT_BITFLD_STAT_TS_BAD_PKT_COUNT_B;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
ISDBT IMG Demod Status Number of bytes errors detected in TS packets
*/
int
realtek_i_isdbt_GetRegStatTsByteErrsB(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatTsByteErrsB
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(ISDBT_REG_STAT_TS_BYTE_ERRS_B, 0, RegStatTsByteErrsB) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *RegStatTsByteErrsB &= ISDBT_BITFLD_STAT_TS_BYTE_ERRS_B;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
ISDBT IMG Demod Status Number of bits errors detected in TS packets
*/
int
realtek_i_isdbt_GetRegStatTsBitErrsB(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatTsBitErrsB
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(ISDBT_REG_STAT_TS_BIT_ERRS_B, 0, RegStatTsBitErrsB) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *RegStatTsBitErrsB &= ISDBT_BITFLD_STAT_TS_BIT_ERRS_B;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
ISDBT IMG Demod Status Number of Viterbi errors in 1e6 bits
*/
int
realtek_i_isdbt_GetRegStatViterbiBerB(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatViterbiBerB
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(ISDBT_REG_VITERBI_BER_B, 0, RegStatViterbiBerB) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *RegStatViterbiBerB &= ISDBT_BITFLD_STAT_TS_VITERBI_BER_B;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
ISDBT IMG Demod Status number of TS packets counted
*/
int
realtek_i_isdbt_GetRegStatTsPktCountC(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatTsPktCountC
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(ISDBT_REG_STAT_TS_PKT_COUNT_C, 0, RegStatTsPktCountC) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *RegStatTsPktCountC &= ISDBT_BITFLD_STAT_TS_PKT_COUNT_C;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
ISDBT IMG Demod Status number of un-correctable TS packets
*/
int
realtek_i_isdbt_GetRegStatTsBadPktCountC(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatTsBadPktCountC
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(ISDBT_REG_STAT_TS_BAD_PKT_COUNT_C, 0, RegStatTsBadPktCountC) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *RegStatTsBadPktCountC &= ISDBT_BITFLD_STAT_TS_BAD_PKT_COUNT_C;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
ISDBT IMG Demod Status Number of bytes errors detected in TS packets
*/
int
realtek_i_isdbt_GetRegStatTsByteErrsC(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatTsByteErrsC
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(ISDBT_REG_STAT_TS_BYTE_ERRS_C, 0, RegStatTsByteErrsC) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *RegStatTsByteErrsC &= ISDBT_BITFLD_STAT_TS_BYTE_ERRS_C;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
ISDBT IMG Demod Status Number of bits errors detected in TS packets
*/
int
realtek_i_isdbt_GetRegStatTsBitErrsC(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatTsBitErrsC
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(ISDBT_REG_STAT_TS_BIT_ERRS_C, 0, RegStatTsBitErrsC) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *RegStatTsBitErrsC &= ISDBT_BITFLD_STAT_TS_BIT_ERRS_C;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
ISDBT IMG Demod Status Number of Viterbi errors in 1e6 bits
*/
int
realtek_i_isdbt_GetRegStatViterbiBerC(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatViterbiBerC
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(ISDBT_REG_VITERBI_BER_C, 0, RegStatViterbiBerC) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *RegStatViterbiBerC &= ISDBT_BITFLD_STAT_TS_VITERBI_BER_C;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*

ISDBT IMG Demod Status Number of time the PHY has re-acquired due to loss of signal
*/
int
realtek_i_isdbt_GetRegStatNumReaqc(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatNumReaqc
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(ISDBT_REG_STAT_NUM_REACQ, 0, RegStatNumReaqc) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *RegStatNumReaqc &= ISDBT_BITFLD_STAT_NUM_REACQ;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
ISDBT IMG Demod Status Measured noise power in dB
*/
int
realtek_i_isdbt_GetRegStatSnr(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatSnr
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(ISDBT_REG_STAT_SNR, 0, RegStatSnr) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *RegStatSnr &= ISDBT_BITFLD_STAT_SNR;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
ISDBT IMG Demod Status Carrier acquisition offset (Hz)
*/
int
realtek_i_isdbt_GetRegStatCarrierAcquisitionOffset(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatCarrierAcquisitionOffset
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(ISDBT_REG_STAT_CARRIER_ACQUISITION_OFFSET, 0, RegStatCarrierAcquisitionOffset) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *RegStatCarrierAcquisitionOffset &= ISDBT_BITFLD_STAT_CARRIER_ACQUISITION_OFFSET;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
ISDBT IMG Demod Status Centre frequency (Hz)
*/
int
realtek_i_isdbt_GetRegStatCarrierTrackingOffset(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatCarrierTrackingOffset
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(ISDBT_REG_STAT_CARRIER_TRACKING_OFFSET, 0, RegStatCarrierTrackingOffset) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *RegStatCarrierTrackingOffset &= ISDBT_REG_STAT_CARRIER_TRACKING_OFFSET;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
ISDBT IMG Demod Status AGC control level ¡V unsigned 16bits number
*/
int
realtek_i_isdbt_GetRegStatIfAgcLevel(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatIfAgcLevel
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(ISDBT_REG_STAT_IF_AGC_LEVEL, 0, RegStatIfAgcLevel) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *RegStatIfAgcLevel &= ISDBT_BITFLD_STAT_IF_AGC_LEVEL;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


// IMG DEMOD BER Testing
/*
ISDBT IMG Demod Integration period for error-rate
*/
int
realtek_i_isdbt_SetRegBerPeriod(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int RegBerPeriod
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    RegBerPeriod &= ISDBT_BITFLD_NUM_SECONDS_BER_AVERAGING;
    
    if(MsgSetReg(ISDBT_REG_NUM_SECONDS_BER_AVERAGING, 0, RegBerPeriod) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_isdbt_GetRegBerPeriod(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegBerPeriod
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(ISDBT_REG_NUM_SECONDS_BER_AVERAGING, 0, RegBerPeriod) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *RegBerPeriod &= ISDBT_BITFLD_NUM_SECONDS_BER_AVERAGING;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
ISDBT IMG Demod Long term pre-RS bit error rate
*/
int
realtek_i_isdbt_GetRegBerRsBerA(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegBerRsBerA
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(ISDBT_REG_RS_BER_A, 0, RegBerRsBerA) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *RegBerRsBerA &= ISDBT_BITFLD_BER_RS_BER_A;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
ISDBT IMG Demod Long term transport stream packet-error rate
*/
int
realtek_i_isdbt_GetRegBerTsPerA(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegBerTsPerA
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(ISDBT_REG_TS_PER_A, 0, RegBerTsPerA) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *RegBerTsPerA &= ISDBT_BITFLD_BER_TS_PER_A;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
ISDBT IMG Demod Long term pre-RS bit error rate
*/
int
realtek_i_isdbt_GetRegBerRsBerB(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegBerRsBerB
)
{
    REALTEK_I_ISDBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(ISDBT_REG_RS_BER_B, 0, RegBerRsBerB) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *RegBerRsBerB &= ISDBT_BITFLD_BER_RS_BER_B;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
ISDBT IMG Demod Long term transport stream packet-error rate
*/
int
realtek_i_isdbt_GetRegBerTsPerB(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegBerTsPerB
)
{
    if(MsgGetReg(ISDBT_REG_TS_PER_B, 0, RegBerTsPerB) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *RegBerTsPerB &= ISDBT_BITFLD_BER_TS_PER_B;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
ISDBT IMG Demod Long term pre-RS bit error rate
*/
int
realtek_i_isdbt_GetRegBerRsBerC(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegBerRsBerC
)
{
    if(MsgGetReg(ISDBT_REG_RS_BER_C, 0, RegBerRsBerC) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *RegBerRsBerC &= ISDBT_BITFLD_BER_RS_BER_C;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
ISDBT IMG Demod Long term transport stream packet-error rate
*/
int
realtek_i_isdbt_GetRegBerTsPerC(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegBerTsPerC
)
{
    if(MsgGetReg(ISDBT_REG_TS_PER_C, 0, RegBerTsPerC) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *RegBerTsPerC &= ISDBT_BITFLD_BER_TS_PER_C;
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}



/*
	In VR "ISDBT_REG_DEMOD_FAILURE_CODE"
	Code indicating the reason for the most recent demod failure as follows:
	
	0: TMCC sync failed on high peak to noise ratio in Mode Scan.
	1: TMCC sync failed after acquisition.
	2: Timeout on excessive number of failed TMCC decodes.
	3: Timeout on loss of sync in TMCC during demod.
	4: Timeout on high PER.
*/
int
realtek_i_isdbt_GetDemodFailureCode(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegFailureCode
)
{
    if(MsgGetReg(ISDBT_REG_FAILURE_CODE, 0, RegFailureCode) != FUNCTION_SUCCESS)
		goto error_status_get_demod_failure_code_registers;

    *RegFailureCode &= ISDBT_BITFLD_FAILURE_CODE;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_failure_code_registers:
    return FUNCTION_ERROR;

}


int
realtek_i_isdbt_GetDemodFailureCountPerTimeout(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegFailureCountPerTimeout
)
{
    if(MsgGetReg(ISDBT_REG_DEMOD_FAILURE_COUNT_PER_TIMEOUT, 0, RegFailureCountPerTimeout) != FUNCTION_SUCCESS)
		goto error_status_get_demod_Failure_Count_Per_Timeout_registers;

    *RegFailureCountPerTimeout &= ISDBT_BITFLD_DEMOD_FAILURE_COUNT_PER_TIMEOUT;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_Failure_Count_Per_Timeout_registers:
    return FUNCTION_ERROR;

}

int
realtek_i_isdbt_GetDemodFailureCountOther(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegFailureCountOther
)
{
    if(MsgGetReg(ISDBT_REG_FAILURE_COUNT_OTHER, 0, RegFailureCountOther) != FUNCTION_SUCCESS)
		goto error_status_get_demod_Failure_Count_Other_registers;

    *RegFailureCountOther &= ISDBT_BITFLD_FAILURE_COUNT_OTHER;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_Failure_Count_Other_registers:
    return FUNCTION_ERROR;

}

int
realtek_i_isdbt_GetRegTmccGoodDecodeCount(
    ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegTmccGoodDecodeCount
)
{
	if(MsgGetReg(ISDBT_REG_TMCC_GOOD_DECODE_COUNT , 0, RegTmccGoodDecodeCount) != FUNCTION_SUCCESS)
		goto error_status_get_reg_tmcc_good_decode_count;
	
	*RegTmccGoodDecodeCount &= ISDBT_BITFLD_TMCC_GOOD_DECODE_COUNT;
	
	return FUNCTION_SUCCESS;
	
error_status_get_reg_tmcc_good_decode_count:
    return FUNCTION_ERROR;
}

