//#include <stdio.h>
#include "dvbt_demod_rtk.h"
#include "dvbt_registers.h"
#include "message_func_rtk.h"


/**

@brief   REALTEK_I DVBt demod module builder

Use BuildRealtekIDvbTModule() to build REALTEK_I DVBT module, set all module function pointers with the corresponding
functions, and initialize module private variables.


@param [in]   ppDemod                        Pointer to REALTEK_I DVBT demod module pointer
@param [in]   pDvbTDemodModuleMemory         Pointer to an allocated DVBT demod module memory
@param [in]   pBaseInterfaceModuleMemory     Pointer to an allocated base interface module memory
@param [in]   pI2cBridgeModuleMemory         Pointer to an allocated I2C bridge module memory
@param [in]   DeviceAddr                     REALTEK_I DVBT I2C device address
@param [in]   CrystalFreqHz                  REALTEK_I DVBT crystal frequency in Hz

@note
	-# One should call BuildRealtekIDvbTModule() to build REALTEK_I DVBT module before using it.

*/
void
BuildRealtekIDvbtModule(
	DVBT_DEMOD_MODULE **ppDemod,
	DVBT_DEMOD_MODULE *pDvbTDemodModuleMemory,
	BASE_INTERFACE_MODULE *pBaseInterfaceModuleMemory,
	I2C_BRIDGE_MODULE *pI2cBridgeModuleMemory,
	unsigned char DeviceAddr,
	unsigned long CrystalFreqHz
)
{
	DVBT_DEMOD_MODULE *pDemod;

	// Set demod module pointer and get demod module.
	*ppDemod = pDvbTDemodModuleMemory;
	pDemod = *ppDemod;

	// Set base interface module pointer and I2C bridge module pointer.
	pDemod->pBaseInterface = pBaseInterfaceModuleMemory;
	pDemod->pI2cBridge     = pI2cBridgeModuleMemory;

	// Set demod type.
	pDemod->DemodType = DVBT_DEMOD_TYPE_REALTEK_I;

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
	pDemod->RegAccess.Addr16Bit.SetRegBytes         = dvbt_demod_addr_16bit_default_SetRegBytes;
	pDemod->RegAccess.Addr16Bit.GetRegBytes         = dvbt_demod_addr_16bit_default_GetRegBytes;
	pDemod->RegAccess.Addr16Bit.GetRegMaskBits      = dvbt_demod_addr_16bit_default_GetRegMaskBits;
	pDemod->RegAccess.Addr16Bit.SetRegBits          = dvbt_demod_addr_16bit_default_SetRegBits;
	pDemod->RegAccess.Addr16Bit.GetRegBits          = dvbt_demod_addr_16bit_default_GetRegBits;
	*/

    pDemod->CheckRpuReady                           = realtek_i_dvbt_common_CheckRpuReady;
    pDemod->PingRpu                                 = realtek_i_dvbt_common_PingRpu;
    pDemod->ShutDown                                = realtek_i_dvbt_common_ShutDown;
    pDemod->ActivateCore                            = realtek_i_dvbt_common_ActivateCore;
    pDemod->DeactivateCore                          = realtek_i_dvbt_common_DeactivateCore;
    pDemod->SwitchToBuffer                          = realtek_i_dvbt_common_SwitchToBuffer;
                
    pDemod->GetDemodInfo                            = realtek_i_dvbt_common_GetDemodInfo;
    pDemod->GetBuildId                              = realtek_i_dvbt_common_GetBuildId;
                
    pDemod->DemodCtrlStop                           = realtek_i_dvbt_common_DemodCtrlStopCmd;
    pDemod->DemodCtrlDetect                         = realtek_i_dvbt_common_DemodCtrlDetectCmd;
    pDemod->DemodCtrlRun                            = realtek_i_dvbt_common_DemodCtrlRunCmd;
    pDemod->DemodCtrlUpdateRssi                     = realtek_i_dvbt_common_DemodCtrlUpdateRssiCmd;
    pDemod->DemodCtrlResetCounters                  = realtek_i_dvbt_common_DemodCtrlResetCountersCmd;
    pDemod->DemodCtrlUpdateCounters                 = realtek_i_dvbt_common_DemodCtrlUpdateCountersCmd;
    pDemod->DemodCtrlSetAgc                         = realtek_i_dvbt_common_DemodCtrlSetAgcCmd;
    pDemod->DemodCtrlUpdateAgc                      = realtek_i_dvbt_common_DemodCtrlUpdateAgcCmd;
    pDemod->DemodCtrlQueryStatus                    = realtek_i_dvbt_common_DemodCtrlQueryStatusCmd;
                
    pDemod->GetDemodStatus                          = realtek_i_dvbt_common_GetDemodStatus;
                
    pDemod->SetTunerFreq                            = realtek_i_dvbt_common_SetTunerFreqCmd;
    pDemod->SetTunerBandwidth                       = realtek_i_dvbt_common_SetTunerBandwidth;
    pDemod->SetTunerGridBase                        = realtek_i_dvbt_common_SetTunerGridBase;
    pDemod->SetTunerGridIncr                        = realtek_i_dvbt_common_SetTunerGridIncr;
    pDemod->GetActiveTunerFreq                      = realtek_i_dvbt_common_GetActiveTunerFreq;
    pDemod->GetActiveTunerBandwidth                 = realtek_i_dvbt_common_GetActiveTunerBandwidth;
    pDemod->GetActiveTunerGain                      = realtek_i_dvbt_common_GetActiveTunerGain;
    pDemod->GetActiveTunerRssi                      = realtek_i_dvbt_common_GetActiveTunerRssi;
                
    pDemod->SetNotchFreq                            = realtek_i_dvbt_common_SetNotchFreqCmd;
    pDemod->SetNotchBandwidth                       = realtek_i_dvbt_common_SetNotchBandwidth;
                
    pDemod->SetAgcParams                            = realtek_i_dvbt_common_SetAgcParams;
    pDemod->GetAgcParams                            = realtek_i_dvbt_common_GetAgcParams;
    pDemod->SetTsConfig                             = realtek_i_dvbt_common_SetTsConfig;
    pDemod->SetTsClkRateMargin                      = realtek_i_dvbt_common_SetTsClkRateMargin;
    pDemod->SetTsClkRateMax                         = realtek_i_dvbt_common_SetTsClkRateMax;
    pDemod->GetDemodLockTime                        = realtek_i_dvbt_common_GetDemodLockTime;

    pDemod->SetXmlTunerCfgOverride                  = realtek_i_dvbt_common_SetXmlTunerCfgOverride;
    pDemod->SetXmlTunerGainCtrl	                    = realtek_i_dvbt_common_SetXmlTunerGainCtrl;
    pDemod->SetXmlFlags                             = realtek_i_dvbt_common_SetXmlFlags;
    pDemod->SetXmlIfFreq                            = realtek_i_dvbt_common_SetXmlIfFreq;
    pDemod->SetXmlPlftCfgOverride                   = realtek_i_dvbt_common_SetXmlPlatformCfgOverride;
    pDemod->SetXmlIfClk                             = realtek_i_dvbt_common_SetXmlIfClk;
    pDemod->SetXmlLdpcClk                           = realtek_i_dvbt_common_SetXmlLdpcClk;
    pDemod->SetXmlUccClk                            = realtek_i_dvbt_common_SetXmlUccClk;
    pDemod->SetXmlMcuClk                            = realtek_i_dvbt_common_SetXmlMcuClk;

    pDemod->SetVirtualRegister                      = realtek_i_dvbt_common_SetVirtualRegister;
    pDemod->GetVirtualRegister                      = realtek_i_dvbt_common_GetVirtualRegister;
    pDemod->SetCtrlVirtualRegister                  = realtek_i_dvbt_common_SetCtrlVirtualRegister;
    pDemod->GetCtrlVirtualRegister                  = realtek_i_dvbt_common_GetCtrlVirtualRegister;
    pDemod->SetHwRegValue                           = realtek_i_dvbt_common_SetHwRegValue;
    pDemod->GetHwRegValue                           = realtek_i_dvbt_common_GetHwRegValue;

    pDemod->SetDetectMask                           = realtek_i_dvbt_SetDetectMask;
    pDemod->GetDetectMask                           = realtek_i_dvbt_GetDetectMask;
    pDemod->SetTunFft                               = realtek_i_dvbt_SetTunFft;
    pDemod->GetTunFft                               = realtek_i_dvbt_GetTunFft;
    pDemod->SetTunGuard                             = realtek_i_dvbt_SetTunGuard;
    pDemod->GetTunGuard                             = realtek_i_dvbt_GetTunGuard;
    pDemod->SetTunMod                               = realtek_i_dvbt_SetTunMod;
    pDemod->GetTunMod                               = realtek_i_dvbt_GetTunMod;
    pDemod->SetTunCodeRate                          = realtek_i_dvbt_SetTunCodeRate;
    pDemod->GetTunCodeRate                          = realtek_i_dvbt_GetTunCodeRate;
    pDemod->SetTunAlpha                             = realtek_i_dvbt_SetTunAlpha;
    pDemod->GetTunAlpha                             = realtek_i_dvbt_GetTunAlpha;
    pDemod->SetTunInterleaver                       = realtek_i_dvbt_SetTunInterleaver;
    pDemod->GetTunInterleaver                       = realtek_i_dvbt_GetTunInterleaver;
    pDemod->SetTunHierarchical                      = realtek_i_dvbt_SetTunHierarchical;
    pDemod->GetTunHierarchical                      = realtek_i_dvbt_GetTunHierarchical;
    pDemod->SetTunSpectInv                          = realtek_i_dvbt_SetTunSpectInv;
    pDemod->GetTunSpectInv                          = realtek_i_dvbt_GetTunSpectInv;
    pDemod->SetCalibCtrlCmd                         = realtek_i_dvbt_SetCalibCtrlCmd;
    pDemod->SetCalibXtalOffset                      = realtek_i_dvbt_SetCalibXtalOffset;
    pDemod->GetCalibXtalOffset                      = realtek_i_dvbt_GetCalibXtalOffset;
    pDemod->SetStatCtrlCmd                          = realtek_i_dvbt_SetStatCtrlCmd;
    pDemod->GetStatUpdata                           = realtek_i_dvbt_GetStatUpdata;
    pDemod->GetStatSsi                              = realtek_i_dvbt_GetStatSsi;
    pDemod->GetStatSnr                              = realtek_i_dvbt_GetStatSnr;
    pDemod->GetStatCarrierOffset                    = realtek_i_dvbt_GetStatCarrierOffset;
    pDemod->GetStatTsPktCount                       = realtek_i_dvbt_GetStatTsPktCount;
    pDemod->GetStatTsBadPktCount                    = realtek_i_dvbt_GetStatTsBadPktCount;
    pDemod->GetStatTsByteErrs                       = realtek_i_dvbt_GetStatTsByteErrs;
    pDemod->GetStatTsBitErrs                        = realtek_i_dvbt_GetStatTsBitErrs;
    pDemod->GetStatViterbiBer                       = realtek_i_dvbt_GetStatViterbiBer;
    pDemod->GetStatTsSync                           = realtek_i_dvbt_GetStatTsSync;
    pDemod->GetStatTpsSync                          = realtek_i_dvbt_GetStatTpsSync;
    pDemod->GetStatIfAgcLevel                       = realtek_i_dvbt_GetStatIfAgcLevel;
    pDemod->GetStatNumReaqc                         = realtek_i_dvbt_GetStatNumReaqc;
    pDemod->GetStatAciDetect                        = realtek_i_dvbt_GetStatAciDetect;
    pDemod->SetBerPeriod                            = realtek_i_dvbt_SetBerPeriod;
    pDemod->GetBerPeriod                            = realtek_i_dvbt_GetBerPeriod;
    pDemod->GetBerUpdate                            = realtek_i_dvbt_GetBerUpdate;
    pDemod->GetBerRsBer                             = realtek_i_dvbt_GetBerRsBer;
    pDemod->GetBerTsPer                             = realtek_i_dvbt_GetBerTsPer;
    pDemod->GetBerSqi                               = realtek_i_dvbt_GetBerSqi;
    pDemod->GetIfAgcGain                            = realtek_i_dvbt_GetIfAgcGain;
       
	return;
}


/*
This register is used to enable the DETECT command to search for various DVB-T
modes. Searching over more bandwidths makes the detect run more slowly.
*/
int
realtek_i_dvbt_SetDetectMask(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int DetectMask
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    //DetectMask &= DVBT_BITFLD_DETECT_MASK;
    
    if(MsgSetReg(DVBT_REG_DETECT_MASK, 0, DetectMask) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbt_GetDetectMask(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *DetectMask
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBT_REG_DETECT_MASK, 0, DetectMask) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *DetectMask &= DVBT_BITFLD_DETECT_MASK;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Write: Select FFT mode to use for RUN command.
Read: Reports the current FFT mode when demodulating
*/
int
realtek_i_dvbt_SetTunFft(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int TunFft
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    TunFft &= DVBT_BITFLD_TUN_FFT;
    
    if(MsgSetReg(DVBT_REG_TUN_FFT, 0, TunFft) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbt_GetTunFft(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *TunFft
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBT_REG_TUN_FFT, 0, TunFft) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *TunFft &= DVBT_BITFLD_TUN_FFT;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Write: Select guard interval to use for RUN command
Read: Report the guard interval when demodulating
*/
int
realtek_i_dvbt_SetTunGuard(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int TunGuard
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    TunGuard &= DVBT_BITFLD_TUN_GUARD;
    
    if(MsgSetReg(DVBT_REG_TUN_GUARD, 0, TunGuard) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbt_GetTunGuard(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *TunGuard
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBT_REG_TUN_GUARD, 0, TunGuard) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *TunGuard &= DVBT_BITFLD_TUN_GUARD;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Write: Select modulation format to use for RUN command
Read: Reports the modulation format used when demodulating
*/
int
realtek_i_dvbt_SetTunMod(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int TunMod
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    TunMod &= DVBT_BITFLD_TUN_MOD;
    
    if(MsgSetReg(DVBT_REG_TUN_MOD, 0, TunMod) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbt_GetTunMod(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *TunMod
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBT_REG_TUN_MOD, 0, TunMod) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *TunMod &= DVBT_BITFLD_TUN_MOD;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Write: Select the code-rate to use for RUN command
Read: Reports the code-rate used when demodulatin
*/
int
realtek_i_dvbt_SetTunCodeRate(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int TunCodeRate
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    TunCodeRate &= DVBT_BITFLD_TUN_CODE_RATE;
    
    if(MsgSetReg(DVBT_REG_TUN_CODE_RATE, 0, TunCodeRate) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbt_GetTunCodeRate(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *TunCodeRate
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBT_REG_TUN_CODE_RATE, 0, TunCodeRate) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *TunCodeRate &= DVBT_BITFLD_TUN_CODE_RATE;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Write: Select the alpha value to use for RUN command (for hierarchical modes)
Read: Reports the alpha value when demodulating
*/
int
realtek_i_dvbt_SetTunAlpha(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int TunAlpha
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    TunAlpha &= DVBT_BITFLD_TUN_ALPHA;
    
    if(MsgSetReg(DVBT_REG_TUN_ALPHA, 0, TunAlpha) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbt_GetTunAlpha(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *TunAlpha
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBT_REG_TUN_ALPHA, 0, TunAlpha) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *TunAlpha &= DVBT_BITFLD_TUN_ALPHA;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Write: Select the interleaver to use for RUN command
Read: Reports the interleaver used when demodulating
*/
int
realtek_i_dvbt_SetTunInterleaver(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int TunInterleaver
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    TunInterleaver &= DVBT_BITFLD_TUN_INTERLEAVER;
    
    if(MsgSetReg(DVBT_REG_TUN_INTERLEAVER, 0, TunInterleaver) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbt_GetTunInterleaver(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *TunInterleaver
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBT_REG_TUN_INTERLEAVER, 0, TunInterleaver) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *TunInterleaver &= DVBT_BITFLD_TUN_INTERLEAVER;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Select whether to demodulate the high priority or low-priority stream.
*/
int
realtek_i_dvbt_SetTunHierarchical(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int TunHierarchical
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    TunHierarchical &= DVBT_BITFLD_TUN_HIERARCHICAL;
    
    if(MsgSetReg(DVBT_REG_TUN_HIERARCHICAL, 0, TunHierarchical) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbt_GetTunHierarchical(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *TunHierarchical
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBT_REG_TUN_HIERARCHICAL, 0, TunHierarchical) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *TunHierarchical &= DVBT_BITFLD_TUN_HIERARCHICAL;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Write: Select whether spectrum inversion is required.
Read: Read whether spectrum inversion was required after DETECT command
*/
int
realtek_i_dvbt_SetTunSpectInv(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int TunSpectInv
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    TunSpectInv &= DVBT_BITFLD_TUN_SPECT_INV;
    
    if(MsgSetReg(DVBT_REG_TUN_SPECT_INV, 0, TunSpectInv) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbt_GetTunSpectInv(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *TunSpectInv
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBT_REG_TUN_SPECT_INV, 0, TunSpectInv) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *TunSpectInv &= DVBT_BITFLD_TUN_SPECT_INV;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


//*******     DVB-T Calibration  ***************************
//These registers are used to control calibration features of the demodulator. In particular the crystal
//offset can be specified.
int
realtek_i_dvbt_SetCalibCtrlCmd(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int CalibCtrl
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    CalibCtrl &= DVBT_BITFLD_CALIB_CTRL;
    
    if(MsgSetCmdReg(DVBT_REG_CALIB_CTRL, 0, CalibCtrl) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}

/*
Estimate of crystal offset (updated only when TS sync is gained)
Unit is parts per billion (ppb)
*/
int
realtek_i_dvbt_SetCalibXtalOffset(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int CalibXtalOffset
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    CalibXtalOffset &= DVBT_BITFLD_CALIB_XTAL_OFFSET;
    
    if(MsgSetReg(DVBT_REG_CALIB_XTAL_OFFSET, 0, CalibXtalOffset) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbt_GetCalibXtalOffset(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *CalibXtalOffset
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBT_REG_CALIB_XTAL_OFFSET, 0, CalibXtalOffset) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *CalibXtalOffset &= DVBT_BITFLD_CALIB_XTAL_OFFSET;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


//DVB-T Status
//The demodulator updates these status registers periodically during demodulation. A specific update
//can be requested by writing 0 to the DVBT_REG_STAT_CTRL register. Counters can be reset by
//writing 1 to the DVBT_REG_STAT_CTRL register.
int
realtek_i_dvbt_SetStatCtrlCmd(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int StatCtrl
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    StatCtrl &= DVBT_BITFLD_STAT_CTRL;
    
    if(MsgSetCmdReg(DVBT_REG_STAT_CTRL, 0, StatCtrl) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}

/*
DVB-T Counter of the number of times the status has been
updated. 
*/
int
realtek_i_dvbt_GetStatUpdata(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *StatUpdata
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBT_REG_STAT_UPDATE, 0, StatUpdata) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *StatUpdata &= DVBT_BITFLD_STAT_UPDATE;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
DVB-T Singal Strength Indicator 
*/
int
realtek_i_dvbt_GetStatSsi(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *StatSsi
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBT_REG_STAT_SSI, 0, StatSsi) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *StatSsi &= DVBT_BITFLD_STAT_SSI;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
DVB-T Singal to Noise Ratio 
*/
int
realtek_i_dvbt_GetStatSnr(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *StatSnr
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBT_REG_STAT_SNR, 0, StatSnr) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *StatSnr &= DVBT_BITFLD_STAT_SNR;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
DVB-T Measured carrier offset (Hz) 
*/
int
realtek_i_dvbt_GetStatCarrierOffset(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *StatCarrierOffset
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBT_REG_STAT_CARRIER_OFFSET, 0, StatCarrierOffset) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *StatCarrierOffset &= DVBT_BITFLD_STAT_CARRIER_OFFSET;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
DVB-T Total number of transport stream packets counted
*/
int
realtek_i_dvbt_GetStatTsPktCount(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *StatTsPktCount
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBT_REG_STAT_TS_PKT_COUNT, 0, StatTsPktCount) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *StatTsPktCount &= DVBT_BITFLD_STAT_TS_PKT_COUNT;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
DVB-T Number of un-correctable transport stream packets
*/
int
realtek_i_dvbt_GetStatTsBadPktCount(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *StatTsBadPktCount
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBT_REG_STAT_TS_BAD_PKT_COUNT, 0, StatTsBadPktCount) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *StatTsBadPktCount &= DVBT_BITFLD_STAT_TS_BAD_PKT_COUNT;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
DVB-T Number of byte errors detected in transport stream packets
*/
int
realtek_i_dvbt_GetStatTsByteErrs(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *StatTsByteErrs
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBT_REG_STAT_TS_BYTE_ERRS, 0, StatTsByteErrs) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *StatTsByteErrs &= DVBT_BITFLD_STAT_TS_BYTE_ERRS;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
DVB-T Number of bit errors detected in transport stream packets
*/
int
realtek_i_dvbt_GetStatTsBitErrs(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *StatTsBitErrs
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBT_REG_STAT_TS_BIT_ERRS, 0, StatTsBitErrs) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *StatTsBitErrs &= DVBT_BITFLD_STAT_TS_BIT_ERRS;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
DVB-T Estimate of bit error rate at input to Viterbi decoder.
*/
int
realtek_i_dvbt_GetStatViterbiBer(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *StatViterbiBer
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBT_REG_STAT_VITERBI_BER, 0, StatViterbiBer) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *StatViterbiBer &= DVBT_BITFLD_STAT_VITERBI_BER;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
DVB-T Transport steam sync indicator
*/
int
realtek_i_dvbt_GetStatTsSync(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *StatTsSync
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBT_REG_STAT_TS_SYNC, 0, StatTsSync) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *StatTsSync &= DVBT_BITFLD_STAT_TS_SYNC;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
DVB-T TPS Sync indicator.
*/
int
realtek_i_dvbt_GetStatTpsSync(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *StatTpsSync
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBT_REG_STAT_TPS_SYNC, 0, StatTpsSync) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *StatTpsSync &= DVBT_BITFLD_STAT_TPS_SYNC;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
DVB-T IF AGC control level ¡V unsigned 16bits number
*/
int
realtek_i_dvbt_GetStatIfAgcLevel(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *StatIfAgcLevel
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBT_REG_STAT_IF_AGC_LEVEL, 0, StatIfAgcLevel) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *StatIfAgcLevel &= DVBT_BITFLD_STAT_IF_AGC_LEVEL;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
DVB-T Number of time the PHY has re-acquired due to loss of signal
*/
int
realtek_i_dvbt_GetStatNumReaqc(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *StatNumReaqc
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBT_REG_STAT_NUM_REACQ, 0, StatNumReaqc) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *StatNumReaqc &= DVBT_BITFLD_STAT_NUM_REACQ;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
DVB-T Shows whether an adjacent channel interferer (ACI) is detected.
0: NO
1: N_MINUS_1
2: N_PLUS_1
3: BOTH
*/
int
realtek_i_dvbt_GetStatAciDetect(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *StatAciDetect
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBT_REG_STAT_ACI_DETECTED, 0, StatAciDetect) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *StatAciDetect &= DVBT_BITFLD_STAT_ACI_DETECTED;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


// DVB-T  BER Test
/*
Integration period for error-rate counters.
*/
int
realtek_i_dvbt_SetBerPeriod(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int BerPeriod
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    BerPeriod &= DVBT_BITFLD_BER_PERIOD;
    
    if(MsgSetReg(DVBT_REG_BER_PERIOD, 0, BerPeriod) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbt_GetBerPeriod(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *BerPeriod
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBT_REG_BER_PERIOD, 0, BerPeriod) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *BerPeriod &= DVBT_BITFLD_BER_PERIOD;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
DVB-T Counter of the number of times the BER has been updated
*/
int
realtek_i_dvbt_GetBerUpdate(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *BerUpdate
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBT_REG_BER_UPDATE, 0, BerUpdate) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *BerUpdate &= DVBT_BITFLD_BER_UPDATE;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
DVB-T Bit error rate measured at the Reed-Solomon input.
*/
int
realtek_i_dvbt_GetBerRsBer(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *BerRsBer
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBT_REG_BER_RS_BER, 0, BerRsBer) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *BerRsBer &= DVBT_BITFLD_BER_RS_BER;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
DVB-T Transport stream output packet-error rate.
*/
int
realtek_i_dvbt_GetBerTsPer(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *BerTsPer
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBT_REG_BER_TS_PER, 0, BerTsPer) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *BerTsPer &= DVBT_BITFLD_BER_TS_PER;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
DVB-T Signal quality indicator.
*/
int
realtek_i_dvbt_GetBerSqi(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *BerSqi
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBT_REG_BER_SQI, 0, BerSqi) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	if(*BerSqi == -1)
	{
		REALTEK_I_DVBT_BASE_INFO("*BerSqi == -1\n");
		REALTEK_I_DVBT_BASE_INFO("*BerSqi == -1\n");
		*BerSqi = 0;
	}
	else
	{
		*BerSqi &= DVBT_BITFLD_BER_SQI;
	}

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbt_GetIfAgcGain(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *IfAgcGain
)
{
    REALTEK_I_DVBT_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

    if(GetHwRegValue(0x02041090, IfAgcGain) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    return FUNCTION_SUCCESS;

error_status_get_demod_registers:
    return FUNCTION_ERROR;
}

