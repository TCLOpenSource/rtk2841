//#include <stdio.h>
#include "qam_demod_rtk.h"
#include "qam_registers.h"
#include "message_func_rtk.h"

/**
@brief   REALTEK_I QAM demod module builder

Use BuildRealtekIQamModule() to build REALTEK_I QAM module, set all module function pointers with the corresponding
functions, and initialize module private variables.

@param [in]   ppDemod                        Pointer to REALTEK_I QAM demod module pointer
@param [in]   pQamDemodModuleMemory          Pointer to an allocated QAM demod module memory
@param [in]   pBaseInterfaceModuleMemory     Pointer to an allocated base interface module memory
@param [in]   pI2cBridgeModuleMemory         Pointer to an allocated I2C bridge module memory
@param [in]   DeviceAddr                     REALTEK_I QAM I2C device address
@param [in]   CrystalFreqHz                  REALTEK_I QAM crystal frequency in Hz

@note
	-# One should call BuildRealtekIQamModule() to build REALTEK_I QAM module before using it.
**/

void
BuildRealtekIQamModule(
	QAM_DEMOD_MODULE **ppDemod,
	QAM_DEMOD_MODULE *pQamDemodModuleMemory,
	BASE_INTERFACE_MODULE *pBaseInterfaceModuleMemory,
	I2C_BRIDGE_MODULE *pI2cBridgeModuleMemory,
	unsigned char DeviceAddr,
	unsigned long CrystalFreqHz
)
{
	QAM_DEMOD_MODULE *pDemod;

	// Set demod module pointer and get demod module.
	*ppDemod = pQamDemodModuleMemory;
	pDemod = *ppDemod;

	// Set base interface module pointer and I2C bridge module pointer.
	pDemod->pBaseInterface = pBaseInterfaceModuleMemory;
	pDemod->pI2cBridge     = pI2cBridgeModuleMemory;

	// Set demod type.
	pDemod->DemodType = QAM_DEMOD_TYPE_REALTEK_I;

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
	pDemod->RegAccess.Addr16Bit.SetRegBytes         = qam_demod_addr_16bit_default_SetRegBytes;
	pDemod->RegAccess.Addr16Bit.GetRegBytes         = qam_demod_addr_16bit_default_GetRegBytes;
	pDemod->RegAccess.Addr16Bit.GetRegMaskBits      = qam_demod_addr_16bit_default_GetRegMaskBits;
	pDemod->RegAccess.Addr16Bit.SetRegBits          = qam_demod_addr_16bit_default_SetRegBits;
	pDemod->RegAccess.Addr16Bit.GetRegBits          = qam_demod_addr_16bit_default_GetRegBits;
	*/

    pDemod->CheckRpuReady                           = realtek_i_qam_common_CheckRpuReady;
    pDemod->PingRpu                                 = realtek_i_qam_common_PingRpu;
    pDemod->ShutDown                                = realtek_i_qam_common_ShutDown;
    pDemod->ActivateCore                            = realtek_i_qam_common_ActivateCore;
    pDemod->DeactivateCore                          = realtek_i_qam_common_DeactivateCore;
    pDemod->SwitchToBuffer				= realtek_i_qam_common_SwitchToBuffer;
    pDemod->GetDemodInfo                            = realtek_i_qam_common_GetDemodInfo;
    pDemod->GetBuildId                              = realtek_i_qam_common_GetBuildId;
    pDemod->DemodCtrlStop                           = realtek_i_qam_common_DemodCtrlStopCmd;
    pDemod->DemodCtrlDetect                         = realtek_i_qam_common_DemodCtrlDetectCmd;
    pDemod->DemodCtrlRun                            = realtek_i_qam_common_DemodCtrlRunCmd;
    pDemod->DemodCtrlUpdateRssi                     = realtek_i_qam_common_DemodCtrlUpdateRssiCmd;
    pDemod->DemodCtrlResetCounters                  = realtek_i_qam_common_DemodCtrlResetCountersCmd;
    pDemod->DemodCtrlUpdateCounters                 = realtek_i_qam_common_DemodCtrlUpdateCountersCmd;
    pDemod->DemodCtrlSetAgc                         = realtek_i_qam_common_DemodCtrlSetAgcCmd;
    pDemod->DemodCtrlUpdateAgc                      = realtek_i_qam_common_DemodCtrlUpdateAgcCmd;
    pDemod->DemodCtrlQueryStatus                    = realtek_i_qam_common_DemodCtrlQueryStatusCmd;
    pDemod->GetDemodStatus                          = realtek_i_qam_common_GetDemodStatus;
    pDemod->SetTunerFreq                            = realtek_i_qam_common_SetTunerFreqCmd;
    pDemod->SetTunerBandwidth                       = realtek_i_qam_common_SetTunerBandwidth;
    pDemod->SetTunerGridBase                        = realtek_i_qam_common_SetTunerGridBase;
    pDemod->SetTunerGridIncr                        = realtek_i_qam_common_SetTunerGridIncr;
    pDemod->GetActiveTunerFreq                      = realtek_i_qam_common_GetActiveTunerFreq;
    pDemod->GetActiveTunerBandwidth                 = realtek_i_qam_common_GetActiveTunerBandwidth;
    pDemod->GetActiveTunerGain                      = realtek_i_qam_common_GetActiveTunerGain;
    pDemod->GetActiveTunerRssi                      = realtek_i_qam_common_GetActiveTunerRssi;
    pDemod->SetNotchFreq                            = realtek_i_qam_common_SetNotchFreqCmd;
    pDemod->SetNotchBandwidth                       = realtek_i_qam_common_SetNotchBandwidth;
    pDemod->SetAgcParams                            = realtek_i_qam_common_SetAgcParams;
    pDemod->GetAgcParams                            = realtek_i_qam_common_GetAgcParams;
    pDemod->SetTsConfig                             = realtek_i_qam_common_SetTsConfig;
    pDemod->SetTsClkRateMargin                      = realtek_i_qam_common_SetTsClkRateMargin;
    pDemod->SetTsClkRateMax                         = realtek_i_qam_common_SetTsClkRateMax;
    pDemod->GetDemodLockTime                        = realtek_i_qam_common_GetDemodLockTime;

	//Add for Common Virtual Register V7.4
	pDemod->SetXmlTunerCfgOverride                  = realtek_i_qam_common_SetXmlTunerCfgOverride;
    pDemod->SetXmlTunerGainCtrl	                    = realtek_i_qam_common_SetXmlTunerGainCtrl;
    pDemod->SetXmlFlags                             = realtek_i_qam_common_SetXmlFlags;
    pDemod->SetXmlIfFreq                            = realtek_i_qam_common_SetXmlIfFreq;
    pDemod->SetXmlPlftCfgOverride                   = realtek_i_qam_common_SetXmlPlatformCfgOverride;
    pDemod->SetXmlIfClk                             = realtek_i_qam_common_SetXmlIfClk;
    pDemod->SetXmlLdpcClk                           = realtek_i_qam_common_SetXmlLdpcClk;
    pDemod->SetXmlUccClk                            = realtek_i_qam_common_SetXmlUccClk;
    pDemod->SetXmlMcuClk                            = realtek_i_qam_common_SetXmlMcuClk;
    pDemod->SetVirtualRegister                      = realtek_i_qam_common_SetVirtualRegister;
    pDemod->GetVirtualRegister                      = realtek_i_qam_common_GetVirtualRegister;

    //QAM TV Register		
    pDemod->GetSystemStateMachine                	= realtek_i_qam_GetSystemStateMachine;
	pDemod->GetCoarseCarrierSyncSubState            = realtek_i_qam_GetCoarseCarrierSyncSubState;
	pDemod->GetEqAdaptSubState                		= realtek_i_qam_GetEqAdaptSubState;
	pDemod->GetIsNoSignal                			= realtek_i_qam_GetIsNoSignal;
	pDemod->GetSymbolRateMonitor                	= realtek_i_qam_GetSymbolRateMonitor;
	pDemod->GetCarrierFrequencyMonitor              = realtek_i_qam_GetCarrierFrequencyMonitor;
	pDemod->GetQamSizeMonitor                		= realtek_i_qam_GetQamSizeMonitor;
	pDemod->GetSpectrumInversionMonitor             = realtek_i_qam_GetSpectrumInversionMonitor;
	pDemod->GetInterleaverMode                		= realtek_i_qam_GetInterleaverMode;
	pDemod->GetAcquisitionTime                		= realtek_i_qam_GetAcquisitionTime;
	pDemod->SetAcquisitionTimeReset                	= realtek_i_qam_SetAcquisitionTimeReset;
	pDemod->GetAcquisitionTimeReset                	= realtek_i_qam_GetAcquisitionTimeReset;
	pDemod->GetEqOutputSnr                			= realtek_i_qam_GetEqOutputSnr;
	pDemod->GetMpegTsPacketNumber                	= realtek_i_qam_GetMpegTsPacketNumber;
	pDemod->GetBadPacketNumber                		= realtek_i_qam_GetBadPacketNumber;
	pDemod->GetByteErrorNumber                		= realtek_i_qam_GetByteErrorNumber;
	pDemod->GetBitErrorNumber                		= realtek_i_qam_GetBitErrorNumber;
	pDemod->SetBerAveLength                			= realtek_i_qam_SetBerAveLength;
	pDemod->GetBerAveLength                			= realtek_i_qam_GetBerAveLength;
	pDemod->GetRsAveBer                				= realtek_i_qam_GetRsAveBer;
	pDemod->GetRsAvePer                				= realtek_i_qam_GetRsAvePer;
	pDemod->GetEqAveSnr                				= realtek_i_qam_GetEqAveSnr;
	pDemod->SetFailureCounterReset                	= realtek_i_qam_SetFailureCounterReset;
	pDemod->GetFailureCounterReset                	= realtek_i_qam_GetFailureCounterReset;
	pDemod->GetCoarseSymbolTimingFailureNumber      = realtek_i_qam_GetCoarseSymbolTimingFailureNumber;
	pDemod->GetFineSymbolTimingFailureNumber        = realtek_i_qam_GetFineSymbolTimingFailureNumber;
	pDemod->GetCarrierSyncFailureNumber             = realtek_i_qam_GetCarrierSyncFailureNumber;
	pDemod->GetUnSupportedCdiModeFailureNumber      = realtek_i_qam_GetUnSupportedCdiModeFailureNumber;
	pDemod->GetSpectrumInversionSearchFailureNumber = realtek_i_qam_GetSpectrumInversionSearchFailureNumber;
	pDemod->GetUnSupportedTsRateFailureNumber       = realtek_i_qam_GetUnSupportedTsRateFailureNumber;
	pDemod->GetPerFailureNumber                		= realtek_i_qam_GetPerFailureNumber;
	pDemod->GetSignalDropoutFailureNumber           = realtek_i_qam_GetSignalDropoutFailureNumber;
	pDemod->GetLastFailureCase                		= realtek_i_qam_GetLastFailureCase;
	pDemod->SetCoreClockRate                		= realtek_i_qam_SetCoreClockRate;
	pDemod->GetCoreClockRate                		= realtek_i_qam_GetCoreClockRate;
	pDemod->SetQamSearchEnable                		= realtek_i_qam_SetQamSearchEnable;
	pDemod->GetQamSearchEnable                		= realtek_i_qam_GetQamSearchEnable;
	pDemod->SetFixedQamSize                			= realtek_i_qam_SetFixedQamSize;
	pDemod->GetFixedQamSize                			= realtek_i_qam_GetFixedQamSize;
	pDemod->SetSpectrumInversionSearchEnable        = realtek_i_qam_SetSpectrumInversionSearchEnable;
	pDemod->GetSpectrumInversionSearchEnable        = realtek_i_qam_GetSpectrumInversionSearchEnable;
	pDemod->SetSpectrumInversionEnable              = realtek_i_qam_SetSpectrumInversionEnable;
	pDemod->GetSpectrumInversionEnable              = realtek_i_qam_GetSpectrumInversionEnable;
	pDemod->SetByteErrorInBadPacketNumber           = realtek_i_qam_SetByteErrorInBadPacketNumber;
	pDemod->GetByteErrorInBadPacketNumber           = realtek_i_qam_GetByteErrorInBadPacketNumber;
	pDemod->SetBitErrorInBadPacketNumber            = realtek_i_qam_SetBitErrorInBadPacketNumber;
	pDemod->GetBitErrorInBadPacketNumber            = realtek_i_qam_GetBitErrorInBadPacketNumber;
	pDemod->SetBadPacketInBadSetPercentage          = realtek_i_qam_SetBadPacketInBadSetPercentage;
	pDemod->GetBadPacketInBadSetPercentage          = realtek_i_qam_GetBadPacketInBadSetPercentage;
	pDemod->SetFailureSetErrorRate                	= realtek_i_qam_SetFailureSetErrorRate;
	pDemod->GetFailureSetErrorRate                	= realtek_i_qam_GetFailureSetErrorRate;
	pDemod->SetInterleaverLevel                		= realtek_i_qam_SetInterleaverLevel;
	pDemod->GetInterleaverLevel                		= realtek_i_qam_GetInterleaverLevel;
	pDemod->SetPhaseTrackerLoopGain64Qam            = realtek_i_qam_SetPhaseTrackerLoopGain64Qam;
	pDemod->GetPhaseTrackerLoopGain64Qam            = realtek_i_qam_GetPhaseTrackerLoopGain64Qam;
	pDemod->SetPhaseTrackerLoopGain256Qam           = realtek_i_qam_SetPhaseTrackerLoopGain256Qam;
	pDemod->GetPhaseTrackerLoopGain256Qam           = realtek_i_qam_GetPhaseTrackerLoopGain256Qam;
	pDemod->SetDagcTargetPower                		= realtek_i_qam_SetDagcTargetPower;
	pDemod->GetDagcTargetPower                		= realtek_i_qam_GetDagcTargetPower;
	pDemod->SetEqUpdateRate                			= realtek_i_qam_SetEqUpdateRate;
	pDemod->GetEqUpdateRate                			= realtek_i_qam_GetEqUpdateRate;
	pDemod->SetCstPeakToMeanThreshold				= realtek_i_qam_SetCstPeakToMeanThreshold;
	pDemod->GetCstPeakToMeanThreshold				= realtek_i_qam_GetCstPeakToMeanThreshold;
	pDemod->GetIfAgcGain                			= realtek_i_qam_GetIfAgcGain;
	//pDemod->GetSignalSSI                			= realtek_i_qam_GetSignalSSI;
	pDemod->GetSignalQualityIndicator 				= realtek_i_qam_GetSignalQualityIndicator;
	//pDemod->UpdateFunction                			= realtek_i_qam_UpdateFunction;
	
	return;
}


/*
Cable system state machine state.
0: DAGC convergence state
1: Coarse symbol timing sync state
2: Coarse carrier sync state
3: Equalizser adaptation state
4: Puncture phase acquisition state
5: Frame synchronization state
6: Tracking state
7: TS output valid
*/
int
realtek_i_qam_GetSystemStateMachine(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *SystemStateMachine
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_SYSTEM_STATE, 0, SystemStateMachine) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *SystemStateMachine &= CABLE_BITFLD_SYSTEM_STATE;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Sub-state for Coarse Carrier Synchronization State.
0: 1st Linear equalisation state
1: Coarse carrier frequency offset detection
2: 2nd Linear equalization state
3: Coarse carrier frequency/phase tracking
4: Fine carrier frequency/phase tracking
5-7: Reserved
*/
int
realtek_i_qam_GetCoarseCarrierSyncSubState(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *CoarseCarrierSyncSubState
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_CCS_STATE, 0, CoarseCarrierSyncSubState) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *CoarseCarrierSyncSubState &= CABLE_BITFLD_CCS_STATE;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Sub-state for Equaliser adaptation State.
0: Stand-by
1: Coarse blind state
2: Fine blind state
3: Coarse decision directed (DD) state
4: Fine decision directed (DD) state-Tracking state
5-7: Reserved
*/
int
realtek_i_qam_GetEqAdaptSubState(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *EqAdaptSubState
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_EQADAPT_STATE, 0, EqAdaptSubState) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *EqAdaptSubState &= CABLE_BITFLD_EQADAPT_STATE;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Signal detection result.
0: Signal detection passed or still in progress.
1: Signal detection routine complete. No signal found. This is the earliest 
possible indicator from the Cable system that it hasn't found a signal. It 
can be triggered by a number of failure mechanisms, the first being the 
symbol timing acquisition after the system has tried the symbol rates
defined in these registers.
*/
int
realtek_i_qam_GetIsNoSignal(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *IsNoSignal
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_SIGNAL_NOT_FOUND, 0, IsNoSignal) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *IsNoSignal &= CABLE_BITFLD_SIGNAL_NOT_FOUND;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Current symbol rate in Symbols Per Sec. This value is derived based on 
given ADC clock rate, the number here also contains same ppm error as 
ADC clock rate. This value is valid while CABLE_BITFLD_SYSTEM_STATE 
= 7 (TS output valid state).
*/
int
realtek_i_qam_GetSymbolRateMonitor(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *SymbolRateMonitor
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_SYM_RATE_MON, 0, SymbolRateMonitor) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *SymbolRateMonitor &= CABLE_BITFLD_SYM_RATE_MON;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Current carrier frequency in Hz. This value is derived based on 
given ADC clock rate, hence if there is error in the ADC clock rate, 
the number there also contains same ppm error as ADC clock rate. 
This value is valid while CABLE_BITFLD_SYSTEM_STATE = 7 (TS outputvalid state).
*/
int
realtek_i_qam_GetCarrierFrequencyMonitor(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *CarrierFrequencyMonitor
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_CARR_FREQ_MON, 0, CarrierFrequencyMonitor) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *CarrierFrequencyMonitor &= CABLE_BITFLD_CARR_FREQ_MON;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Current QAM size monitor. To get correct QAM size on a paticular channel, 
it is safe to read this register after CABLE_BITFLD_SYSTEM_STATE = 7 (TS output valid state).
0-1: Reserved
2: 64QAM
3: Reserved
4: 256QAM
5-7: Reserved
*/
int
realtek_i_qam_GetQamSizeMonitor(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *QamSizeMonitor
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_QAM_MON, 0, QamSizeMonitor) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *QamSizeMonitor &= CABLE_BITFLD_QAM_MON;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Current spectrum inversion setup monitor. To get correct spectrum 
inversion setup on a particular channel, it is safe to read this register 
after CABLE_BITFLD_SYSTEM_STATE = 7 (TS output valid state).
0: No spectrum inversion
1: Spectrum inverted
*/
int
realtek_i_qam_GetSpectrumInversionMonitor(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *SpectrumInversionMonitor
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_SPEC_INV_MON, 0, SpectrumInversionMonitor) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *SpectrumInversionMonitor &= CABLE_BITFLD_SPEC_INV_MON;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Detected Interleave Mode. This field is valid after
CABLE_BITFLD_SYSTEM_STATE = 7 (TS output valid state).
0: I=128, J=1
1: I=128, J=1
2: I=128, J=2
3: I=64, J=2
4: I=128, J=3
5: I=32, J=4
6: I=128, J=4
7: I=16, J=8
8: I=128, J=5
9: I=8, J=16
10: I=128, J=6
12: I=128, J=7
14: I=128, J=8
Otherwise: Reserved
*/
int
realtek_i_qam_GetInterleaverMode(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *InterleaverMode
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_INTL_MODE, 0, InterleaverMode) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *InterleaverMode &= CABLE_BITFLD_INTL_MODE;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Time taken from point of entering TV_STATE_ACQDEMOD to entering
CABLE_STATE_TS_OUTPUT_VALID in milliseconds.
This value will accumulate time over any failure cases until
TV_CMD_STOP is issued or CABLE_BITFLD_AQUISITION_TIME_RESET
is set to 1.
*/
int
realtek_i_qam_GetAcquisitionTime(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *AcquisitionTime
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_AQUISITION_TIME, 0, AcquisitionTime) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *AcquisitionTime &= CABLE_BITFLD_AQUISITION_TIME;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Reset acquisition timer.
0: Acquisition timer will not be reset, it will accumulate the results.
1: Acquisition timer will be reset. Once complete this field will be
returned to 0.
*/
int
realtek_i_qam_SetAcquisitionTimeReset(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int AcquisitionTimeReset
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    AcquisitionTimeReset &= CABLE_BITFLD_AQUISITION_TIME_RESET;

    if(MsgSetReg(CABLE_REG_AQUISITION_TIME_RESET, 0, AcquisitionTimeReset) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_qam_GetAcquisitionTimeReset(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *AcquisitionTimeReset
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_AQUISITION_TIME_RESET, 0, AcquisitionTimeReset) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *AcquisitionTimeReset &= CABLE_BITFLD_AQUISITION_TIME_RESET;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Estimated equaliser output SNR in dB. The SNR is estimated using a hard decision
symbol and equalized symbol to calculate the error power. This field becomes valid
at Coarse decision directed stage in Equaliser adaptation substate. The SNR is encoded
as follows:
SNR [dB] = CABLE_BITFLD_EQ_SNR_DB/256
*/
int
realtek_i_qam_GetEqOutputSnr(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *EqOutputSnr
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_EQ_SNR_DB, 0, EqOutputSnr) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *EqOutputSnr &= CABLE_BITFLD_EQ_SNR_DB;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Number of MPEG-2 TS packets processed.
This register is updated by writing a TV_CMD_UPDATE_COUNTERS command to the 
TV_REG_CONTROL register. It is reset by writing a TV_CMD_RESET_COUNTERS
command to the TV_REG_CONTROL register.
The CABLE_REG_NUM_BADPKTS, CABLE_REG_NUM_BYTE_ERRS and
CABLE_REG_NUM_BIT_ERRS registers are also affected by issuing these commands.
*/
int
realtek_i_qam_GetMpegTsPacketNumber(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *MpegTsPacketNumber
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_NUM_PKTS, 0, MpegTsPacketNumber) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *MpegTsPacketNumber &= CABLE_BITFLD_NUM_PKTS;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Number of packets containing errors after the RS decoder, out of CABLE_BITFLD_NUM_PKTS
total packets processed. Packet error rate (PER) after RS decoder can be calculated as:
PER = CABLE_BITFLD_NUM_BADPKTS/CABLE_BITFLD_NUM_PKTS
This register is updated by writing a TV_CMD_UPDATE_COUNTERS command to the
TV_REG_CONTROL register. It is reset by writing a TV_CMD_RESET_COUNTERS command 
to the TV_REG_CONTROL register. The CABLE_REG_NUM_PKTS, CABLE_REG_NUM_BYTE_ERRS 
and CABLE_REG_NUM_BIT_ERRS registers are also affected by issuing these commands.
*/
int
realtek_i_qam_GetBadPacketNumber(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *BadPacketNumber
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_NUM_BADPKTS, 0, BadPacketNumber) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *BadPacketNumber &= CABLE_BITFLD_NUM_BADPKTS;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Estimated number of byte errors within CABLE_BITFLD_NUM_PKTS processed packets.
The number of byte errors within bad packets cannot be accurately detected. Therefore,
in estimating the total number of byte errors, bad packets are assumed to contain 
CABLE_BITFLD_BYTE_ERR_BADPKTS byte errors.
Byte error rate (ByteER) can be calculated as:
ByteER = CABLE_BITFLD_NUM_BYTE_ERRS/(CABLE_BITFLD_NUM_PKTS*204)
This register is updated by writing a TV_CMD_UPDATE_COUNTERS cmmand to the 
TV_REG_CONTROL register. It is reset by writing a TV_CMD_RESET_COUNTERS
command to the TV_REG_CONTROL register.
The CABLE_REG_NUM_PKTS, CABLE_REG_NUM_BADPKTS and CABLE_REG_NUM_BIT_ERRS
registers are also affected by issuing these commands.
*/
int
realtek_i_qam_GetByteErrorNumber(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *ByteErrorNumber
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_NUM_BYTE_ERRS, 0, ByteErrorNumber) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *ByteErrorNumber &= CABLE_BITFLD_NUM_BYTE_ERRS;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Estimated number of bit errors within CABLE_BITFLD_NUM_PKTS processed packets.
The number of bit errors within bad packets cannot be accurately detected. Therefore,
in estimating the total number of bit errors, bad packets are assumed to contain
CABLE_BITFLD_BIT_ERR_BADPKTS bit errors. Bit error rate (BER) can be calculated as:
BER = CABLE_BITFLD_NUM_BIT_ERRS/(CABLE_BITFLD_NUM_PKTS*204*8)
This register is updated by writing a TV_CMD_UPDATE_COUNTERS cmmand to the 
TV_REG_CONTROL register. It is reset by writing a TV_CMD_RESET_COUNTERS
command to the TV_REG_CONTROL register.
The CABLE_REG_NUM_PKTS, CABLE_REG_NUM_BADPKTS and CABLE_REG_NUM_BIT_ERRS
registers are also affected by issuing these commands.
*/
int
realtek_i_qam_GetBitErrorNumber(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *BitErrorNumber
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_NUM_BIT_ERRS, 0, BitErrorNumber) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *BitErrorNumber &= CABLE_BITFLD_NUM_BIT_ERRS;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
The number of seconds over which the Bit Error Rate, Packet Error Rate
and Signal to Noise Ratio will be averaged. Range 1-30.
*/
int
realtek_i_qam_SetBerAveLength(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int BerAveLength
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    BerAveLength &= CABLE_BITFLD_NUM_SECS_BER_AVERAGE;

    if(MsgSetReg(CABLE_REG_NUM_SECS_BER_AVERAGE, 0, BerAveLength) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_qam_GetBerAveLength(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *BerAveLength
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_NUM_SECS_BER_AVERAGE, 0, BerAveLength) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *BerAveLength &= CABLE_BITFLD_NUM_SECS_BER_AVERAGE;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Measured RS bit error rate. Unsigned ratio with 32 fractional bits.
This measurement is averaged over the interval specified in 
CABLE_REG_NUM_SECS_BER_AVERAGE.
It will be valid while in the demodulating state and is updated once per second.
*/
int
realtek_i_qam_GetRsAveBer(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *RsAveBer
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_RS_AVERAGE_BER, 0, RsAveBer) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *RsAveBer &= CABLE_BITFLD_RS_AVERAGE_BER;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Measured RS packet error rate. Unsigned ratio with 32 fractional bits.
This measurement is averaged over the interval specified in 
CABLE_REG_NUM_SECS_BER_AVERAGE.
It will be valid while in the demodulating state and is updated once per second.
*/
int
realtek_i_qam_GetRsAvePer(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *RsAvePer
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_RS_AVERAGE_PER, 0, RsAvePer) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *RsAvePer &= CABLE_BITFLD_RS_AVERAGE_PER;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Measured equalizer SNR. This value is encoded as below:
SNR [dB] = CABLE_BITFLD_EQ_AVERAGE_SNR/256
This measurement is averaged over the interval specified in 
CABLE_REG_NUM_SECS_BER_AVERAGE.
It will be valid while in the demodulating state and is updated once 
per second.
*/
int
realtek_i_qam_GetEqAveSnr(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *EqAveSnr
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_EQ_AVERAGE_SNR, 0, EqAveSnr) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *EqAveSnr &= CABLE_BITFLD_EQ_AVERAGE_SNR;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Set to initiate resetting failure counters:
And the register is reset when the resetting counters are completed.
*/
int
realtek_i_qam_SetFailureCounterReset(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int FailureCounterReset
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    FailureCounterReset &= CABLE_BITFLD_FAILURE_COUNTERS_RESET;

    if(MsgSetReg(CABLE_REG_FAILURE_COUNTERS_RESET, 0, FailureCounterReset) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_qam_GetFailureCounterReset(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *FailureCounterReset
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_FAILURE_COUNTERS_RESET, 0, FailureCounterReset) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *FailureCounterReset &= CABLE_BITFLD_FAILURE_COUNTERS_RESET;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Number of reacquisition's caused by coarse symbol timing failure.
*/
int
realtek_i_qam_GetCoarseSymbolTimingFailureNumber(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *CoarseSymbolTimingFailureNumber
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_NUM_COARSE_SYMTIM_FAILURE, 0, CoarseSymbolTimingFailureNumber) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *CoarseSymbolTimingFailureNumber &= CABLE_BITFLD_NUM_COARSE_SYMTIM_FAILURE;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Number of reacquisition's caused by fine symbol timing failure.
*/
int
realtek_i_qam_GetFineSymbolTimingFailureNumber(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *FineSymbolTimingFailureNumber
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_NUM_FINE_SYMTIM_FAILURE, 0, FineSymbolTimingFailureNumber) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *FineSymbolTimingFailureNumber &= CABLE_BITFLD_NUM_FINE_SYMTIM_FAILURE;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Number of reacquisition's caused by carrier synchronisation failure.
*/
int
realtek_i_qam_GetCarrierSyncFailureNumber(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *CarrierSyncFailureNumber
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_NUM_CARRSYNC_FAILURE, 0, CarrierSyncFailureNumber) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *CarrierSyncFailureNumber &= CABLE_BITFLD_NUM_CARRSYNC_FAILURE;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Number of reacquisition's caused by the TS employing an unsupported
CDI configuration.
*/
int
realtek_i_qam_GetUnSupportedCdiModeFailureNumber(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *UnSupportedCdiModeFailureNumber
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_NUM_CDI_MODE_FAILURE, 0, UnSupportedCdiModeFailureNumber) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *UnSupportedCdiModeFailureNumber &= CABLE_BITFLD_NUM_CDI_MODE_FAILURE;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Number of reacquisition's caused by spectrum to inversion search failure/TSP 
sync failure.
*/
int
realtek_i_qam_GetSpectrumInversionSearchFailureNumber(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *SpectrumInversionSearchFailureNumber
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_NUM_SPECINV_SEARCH_FAILURE, 0, SpectrumInversionSearchFailureNumber) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *SpectrumInversionSearchFailureNumber &= CABLE_BITFLD_NUM_SPECINV_SEARCH_FAILURE;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Number of reacquisition's caused by the TS data rate exceeding the limits
set by the TV_REG_TSO_CLK_RATE_MARGIN and TV_REG_TSO_CLK_RATE_MAX
registers [i].
*/
int
realtek_i_qam_GetUnSupportedTsRateFailureNumber(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *UnSupportedTsRateFailureNumber
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_NUM_TS_RATE_FAILURE, 0, UnSupportedTsRateFailureNumber) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *UnSupportedTsRateFailureNumber &= CABLE_BITFLD_NUM_TS_RATE_FAILURE;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Number of reacquisition's caused by PER failure.
*/
int
realtek_i_qam_GetPerFailureNumber(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *PerFailureNumber
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_NUM_PER_FAILURE, 0, PerFailureNumber) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *PerFailureNumber &= CABLE_BITFLD_NUM_PER_FAILURE;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Number of reacquisition's caused by signal dropout failure.
*/
int
realtek_i_qam_GetSignalDropoutFailureNumber(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *SignalDropoutFailureNumber
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_NUM_SIGNAL_DROPOUT_FAILURE, 0, SignalDropoutFailureNumber) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *SignalDropoutFailureNumber &= CABLE_BITFLD_NUM_SIGNAL_DROPOUT_FAILURE;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Cause of most recent reacquisition.
0: No reacquisitions have occurred.
1: Coarse symbol timing failure.
2: Fine symbol timing failure.
3: Carrier sync failure.
4: Reserved.
5: Reserved.
6: Unsupported CDI mode failure.
7: Spectrum inversion search/TSP sync failure.
8: Unsupported TS data rate failure.
9: PER failure.
*/
int
realtek_i_qam_GetLastFailureCase(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *LastFailureCase
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_LAST_FAILURE, 0, LastFailureCase) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *LastFailureCase &= CABLE_BITFLD_LAST_FAILURE;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Core clock rate in Hz. This register must be configured in order to use the 
TV_REG_TSO_CLK_RATE_MARGIN and TV_REG_TSO_CLK_RATE_MAX
registers documented in the common API register interface [i].
*/
int
realtek_i_qam_SetCoreClockRate(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int CoreClockRate
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    CoreClockRate &= CABLE_BITFLD_CORE_CLK;

    if(MsgSetReg(CABLE_REG_CORE_CLK, 0, CoreClockRate) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_qam_GetCoreClockRate(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *CoreClockRate
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_CORE_CLK, 0, CoreClockRate) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *CoreClockRate &= CABLE_BITFLD_CORE_CLK;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Enable auto QAM search.
0: Disable QAM search. Using a QAM specified in CABLE_BITFLD_QAM_FIXED.
1: Enable QAM search.
*/
int
realtek_i_qam_SetQamSearchEnable(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int QamSearchEnable
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    QamSearchEnable &= CABLE_BITFLD_QAM_SEARCH_ENABLE;

    if(MsgSetReg(CABLE_REG_QAM_SEARCH_ENABLE, 0, QamSearchEnable) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_qam_GetQamSearchEnable(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *QamSearchEnable
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_QAM_SEARCH_ENABLE, 0, QamSearchEnable) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *QamSearchEnable &= CABLE_BITFLD_QAM_SEARCH_ENABLE;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Specify which QAM is used in QAM_SEARCH_ENABLE = 0 case.
0-1: Reserved
2: 64QAM
3: Reserved
4: 256QAM
5-7: Reserved
*/
int
realtek_i_qam_SetFixedQamSize(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int FixedQamSize
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    FixedQamSize &= CABLE_BITFLD_QAM_FIXED;

    if(MsgSetReg(CABLE_REG_QAM_FIXED, 0, FixedQamSize) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_qam_GetFixedQamSize(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *FixedQamSize
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_QAM_FIXED, 0, FixedQamSize) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *FixedQamSize &= CABLE_BITFLD_QAM_FIXED;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Enable auto spectrum inversion search.
0: Disable spectrum inversion search. Using spectrum inversion specified in 
CABLE_BITFLD_SPECTRUM_INVERSION.
1: Enable spectrum inversion search. Check both inverted and non-inverted
spectrums, starting with spectrum inversion specified in 
CABLE_BITFLD_SPECTRUM_INVERSION
*/
int
realtek_i_qam_SetSpectrumInversionSearchEnable(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int SpectrumInversionSearchEnable
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    SpectrumInversionSearchEnable &= CABLE_BITFLD_SPECINV_SEARCH_ENABLE;

    if(MsgSetReg(CABLE_REG_SPECINV_SEARCH_ENABLE, 0, SpectrumInversionSearchEnable) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_qam_GetSpectrumInversionSearchEnable(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *SpectrumInversionSearchEnable
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_SPECINV_SEARCH_ENABLE, 0, SpectrumInversionSearchEnable) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *SpectrumInversionSearchEnable &= CABLE_BITFLD_SPECINV_SEARCH_ENABLE;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Specify spectrum inversion to be used in SPECINV_SEARCH_ENABLE = 0 case,
and as the starting point in SPECINV_SEARCH_ENABLE = 1 case.
0: Spectrum inversion disabled.
1: Spectrum inversion enabled.
*/
int
realtek_i_qam_SetSpectrumInversionEnable(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int SpectrumInversionEnable
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    SpectrumInversionEnable &= CABLE_BITFLD_SPECTRUM_INVERSION;

    if(MsgSetReg(CABLE_REG_SPECTRUM_INVERSION, 0, SpectrumInversionEnable) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_qam_GetSpectrumInversionEnable(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *SpectrumInversionEnable
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_SPECTRUM_INVERSION, 0, SpectrumInversionEnable) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *SpectrumInversionEnable &= CABLE_BITFLD_SPECTRUM_INVERSION;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Specify number of byte errors on a bad packet to calculate
CABLE_BITFLD_NUM_BYTE_ERRS register. As the number of byte errors
on bad packets cannot be accurately detected, the number in this register 
is used in such a case. Typical number is 9, as it is true most of case near
QEF point.
*/
int
realtek_i_qam_SetByteErrorInBadPacketNumber(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int ByteErrorInBadPacketNumber
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    ByteErrorInBadPacketNumber &= CABLE_BITFLD_BYTE_ERR_BADPKTS;

    if(MsgSetReg(CABLE_REG_BYTE_ERR_BADPKTS, 0, ByteErrorInBadPacketNumber) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_qam_GetByteErrorInBadPacketNumber(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *ByteErrorInBadPacketNumber
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_BYTE_ERR_BADPKTS, 0, ByteErrorInBadPacketNumber) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *ByteErrorInBadPacketNumber &= CABLE_BITFLD_BYTE_ERR_BADPKTS;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Specify number of bit errors on a bad packet to calculate
CABLE_BITFLD_NUM_BIT_ERRS register. As the number of bit errors
on bad packets cannot be accurately detected, the number in this register 
is used in such a case. Typical number is 16, as it is true most of case near
QEF point.
*/
int
realtek_i_qam_SetBitErrorInBadPacketNumber(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int BitErrorInBadPacketNumber
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    BitErrorInBadPacketNumber &= CABLE_BITFLD_BIT_ERR_BADPKTS;

    if(MsgSetReg(CABLE_REG_BIT_ERR_BADPKTS, 0, BitErrorInBadPacketNumber) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_qam_GetBitErrorInBadPacketNumber(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *BitErrorInBadPacketNumber
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_BIT_ERR_BADPKTS, 0, BitErrorInBadPacketNumber) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *BitErrorInBadPacketNumber &= CABLE_BITFLD_BIT_ERR_BADPKTS;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Percentage of uncorrectable packets needed in one update period for the 
set of data to be considered bad. Each update period is 58240 symbols long.
*/
int
realtek_i_qam_SetBadPacketInBadSetPercentage(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int BadPacketInBadSetPercentage
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    BadPacketInBadSetPercentage &= CABLE_BITFLD_PERCENT_BADPKTS_BADSET;

    if(MsgSetReg(CABLE_REG_PERCENT_BADPKTS_BADSET, 0, BadPacketInBadSetPercentage) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_qam_GetBadPacketInBadSetPercentage(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *BadPacketInBadSetPercentage
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_PERCENT_BADPKTS_BADSET, 0, BadPacketInBadSetPercentage) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *BadPacketInBadSetPercentage &= CABLE_BITFLD_PERCENT_BADPKTS_BADSET;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Number of consecutive bad sets as defined in CABLE_BITFLD_PERCENT_BADPKTS_BADSET
for reacquisition due to the PER failure to occur.
Once TS Sync clock occurs the output packets are monitored. If in one update period the 
percentage of uncorrectable packets exceeds the value in CABLE_BITFLD_PERCENT_BADPKTS_BADSET
then this set is marked as bad. If this then occurs repeatedly for the number of consecutive sets
defined in CABLE_BITFLD_SER_FAILURE the system is considered to have failed so the systme is 
reset and acquisition starts again. The PER failure counter is incremented.
*/
int
realtek_i_qam_SetFailureSetErrorRate(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int FailureSetErrorRate
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    FailureSetErrorRate &= CABLE_BITFLD_SER_FAILURE;

    if(MsgSetReg(CABLE_REG_SER_FAILURE, 0, FailureSetErrorRate) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_qam_GetFailureSetErrorRate(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *FailureSetErrorRate
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_SER_FAILURE, 0, FailureSetErrorRate) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *FailureSetErrorRate &= CABLE_BITFLD_SER_FAILURE;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Specify Interleaver Level.
0: Interleaver level 1
1: Interleaver level 2
Otherwise: Reserved
*/
int
realtek_i_qam_SetInterleaverLevel(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int InterleaverLevel
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    InterleaverLevel &= CABLE_BITFLD_INTL_LEVEL;

    if(MsgSetReg(CABLE_REG_INTL_LEVEL, 0, InterleaverLevel) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_qam_GetInterleaverLevel(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *InterleaverLevel
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_INTL_LEVEL, 0, InterleaverLevel) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *InterleaverLevel &= CABLE_BITFLD_INTL_LEVEL;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Phase tracker loop gain for 64QAM constellation.
Valid range 0:9.
Phase Tracker loop bandwidth = SymbolRate * 2^(gain-21),
giving a bandwidth range of SymbolRate * 2^-21 to SymbolRate *2^-12.
*/
int
realtek_i_qam_SetPhaseTrackerLoopGain64Qam(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int PhaseTrackerLoopGain64Qam
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    PhaseTrackerLoopGain64Qam &= CABLE_BITFLD_PTGAIN_64QAM;

    if(MsgSetReg(CABLE_REG_PTGAIN_64QAM, 0, PhaseTrackerLoopGain64Qam) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_qam_GetPhaseTrackerLoopGain64Qam(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *PhaseTrackerLoopGain64Qam
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_PTGAIN_64QAM, 0, PhaseTrackerLoopGain64Qam) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *PhaseTrackerLoopGain64Qam &= CABLE_BITFLD_PTGAIN_64QAM;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Phase tracker loop gain for 256QAM constellation.
Valid range 0:9.
Phase Tracker loop bandwidth = SymbolRate * 2^(gain-21),
giving a bandwidth range of SymbolRate * 2^-21 to SymbolRate *2^-12.
*/
int
realtek_i_qam_SetPhaseTrackerLoopGain256Qam(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int PhaseTrackerLoopGain256Qam
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    PhaseTrackerLoopGain256Qam &= CABLE_BITFLD_PTGAIN_256QAM;

    if(MsgSetReg(CABLE_REG_PTGAIN_256QAM, 0, PhaseTrackerLoopGain256Qam) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_qam_GetPhaseTrackerLoopGain256Qam(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *PhaseTrackerLoopGain256Qam
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_PTGAIN_256QAM, 0, PhaseTrackerLoopGain256Qam) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *PhaseTrackerLoopGain256Qam &= CABLE_BITFLD_PTGAIN_256QAM;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Target digital AGC receiver power value Q0.23.
*/
int
realtek_i_qam_SetDagcTargetPower(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int DagcTargetPower
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    DagcTargetPower &= CABLE_BITFLD_TUNE_DAGC_POWER;

    if(MsgSetReg(CABLE_REG_TUNE_DAGC_POWER, 0, DagcTargetPower) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_qam_GetDagcTargetPower(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *DagcTargetPower
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_TUNE_DAGC_POWER, 0, DagcTargetPower) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *DagcTargetPower &= CABLE_BITFLD_TUNE_DAGC_POWER;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Signed integer exponent of Equalizer update factor 
2^(TUNE_EQ_UPDATE_STEPSIZE). 
Default initial value of -14 (0xFFFFF2) optimized for normal
working conditions. Signed Q23.0.
*/
int
realtek_i_qam_SetEqUpdateRate(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int EqUpdateRate
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    EqUpdateRate &= CABLE_BITFLD_TUNE_EQ_UPDATE_STEPSIZE;

    if(MsgSetReg(CABLE_REG_TUNE_EQ_UPDATE_STEPSIZE, 0, EqUpdateRate) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_qam_GetEqUpdateRate(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *EqUpdateRate
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_TUNE_EQ_UPDATE_STEPSIZE, 0, EqUpdateRate) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *EqUpdateRate &= CABLE_BITFLD_TUNE_EQ_UPDATE_STEPSIZE;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Signed integer coarse symbol timing acquisition threshold.. Default
initial value of 44 (0x00002C)optimized for normal working
conditions. Signed Q23.0.
*/
int
realtek_i_qam_SetCstPeakToMeanThreshold(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int CstPeakToMeanThreshold
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    CstPeakToMeanThreshold &= CABLE_BITFLD_CST_PEAK_TO_MEAN_THRESHOLD;

    if(MsgSetReg(CABLE_REG_CST_PEAK_TO_MEAN_THRESHOLD, 0, CstPeakToMeanThreshold) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_qam_GetCstPeakToMeanThreshold(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *CstPeakToMeanThreshold
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(CABLE_REG_CST_PEAK_TO_MEAN_THRESHOLD, 0, CstPeakToMeanThreshold) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *CstPeakToMeanThreshold &= CABLE_BITFLD_CST_PEAK_TO_MEAN_THRESHOLD;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_qam_GetIfAgcGain(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *IfAgcGain
)
{
    REALTEK_I_QAM_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

    if(GetHwRegValue(0x02041090, IfAgcGain) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    return FUNCTION_SUCCESS;

error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Get QAM Signal Quality with BER.
*/
int
realtek_i_qam_GetSignalQualityIndicator(
	QAM_DEMOD_MODULE *pDemod,
	unsigned char *SignalQualityIndicator
)
{
	int ret = TUNER_CTRL_OK;
	unsigned char SQI;
	unsigned int PakNum, BadPakNum, ErrBit;
	unsigned long ber;

	//ret |= (pDemod->DemodCtrlUpdateCounters(pDemod));
	ret |= (pDemod->GetMpegTsPacketNumber(pDemod, &PakNum));
	ret |= (pDemod->GetBadPacketNumber(pDemod, &BadPakNum));
	ret |= (pDemod->GetBitErrorNumber(pDemod, &ErrBit));
	//ret |= (pDemod->DemodCtrlResetCounters(pDemod));

	if (PakNum > 0)
	{
		if (ErrBit < 4000)
			ber = (ErrBit*1000000)/(PakNum * 204 * 8);
		else if (ErrBit < 10000)
			ber = ((ErrBit*100000)/(PakNum * 204 * 8))*10;
		else
			ber = ((ErrBit*10000)/(PakNum * 204 * 8))*100;
	}
	else
		ber = 1*1000000;

	//printk("[SR_Debug]PakNum = %u, BadPakNum = %u, ErrBit = %u, ber = %lu", PakNum, BadPakNum, ErrBit, ber);
	
	if (ber <= 10)
    {
        //Good singal : 80~100
        SQI = 100 - (ber*2);
    }
    else if (ber <= 45)   
    {
        //Normal Signal : 45~80
        SQI = 80 - (ber-10);
    }
	else if (ber <= 550)
    {
        //Poor Signal : 5~45
        SQI = 45 - ((ber-45)/13);
    }
    else
    {
        SQI = 0;
    }

	*SignalQualityIndicator = (SQI > 100)? 100 : SQI;

	return FUNCTION_SUCCESS;    
}


