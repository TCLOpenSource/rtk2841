//#include <stdio.h>
#include "dvbc_demod_rtk.h"
#include "dvbc_registers.h"
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
BuildRealtekIDvbCModule(
	DVBC_DEMOD_MODULE **ppDemod,
	DVBC_DEMOD_MODULE *pDvbCDemodModuleMemory,
	BASE_INTERFACE_MODULE *pBaseInterfaceModuleMemory,
	I2C_BRIDGE_MODULE *pI2cBridgeModuleMemory,
	unsigned char DeviceAddr,
	unsigned long CrystalFreqHz
)
{
	DVBC_DEMOD_MODULE *pDemod;

	// Set demod module pointer and get demod module.
	*ppDemod = pDvbCDemodModuleMemory;
	pDemod = *ppDemod;

	// Set base interface module pointer and I2C bridge module pointer.
	pDemod->pBaseInterface = pBaseInterfaceModuleMemory;
	pDemod->pI2cBridge     = pI2cBridgeModuleMemory;

	// Set demod type.
	pDemod->DemodType = DVBC_DEMOD_TYPE_REALTEK_I;

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

	pDemod->CheckRpuReady                           = realtek_i_dvbc_common_CheckRpuReady;
	pDemod->PingRpu                                 = realtek_i_dvbc_common_PingRpu;
	pDemod->ShutDown                                = realtek_i_dvbc_common_ShutDown;
	pDemod->ActivateCore                            = realtek_i_dvbc_common_ActivateCore;
	pDemod->DeactivateCore                          = realtek_i_dvbc_common_DeactivateCore;
	pDemod->SwitchToBuffer				= realtek_i_dvbc_common_SwitchToBuffer;

	pDemod->GetDemodInfo                            = realtek_i_dvbc_common_GetDemodInfo;
	pDemod->GetBuildId                              = realtek_i_dvbc_common_GetBuildId;

	pDemod->DemodCtrlStop                           = realtek_i_dvbc_common_DemodCtrlStopCmd;
	pDemod->DemodCtrlDetect                         = realtek_i_dvbc_common_DemodCtrlDetectCmd;
	pDemod->DemodCtrlRun                            = realtek_i_dvbc_common_DemodCtrlRunCmd;
	pDemod->DemodCtrlUpdateRssi                     = realtek_i_dvbc_common_DemodCtrlUpdateRssiCmd;
	pDemod->DemodCtrlResetCounters                  = realtek_i_dvbc_common_DemodCtrlResetCountersCmd;
	pDemod->DemodCtrlUpdateCounters                 = realtek_i_dvbc_common_DemodCtrlUpdateCountersCmd;
	pDemod->DemodCtrlSetAgc                         = realtek_i_dvbc_common_DemodCtrlSetAgcCmd;
	pDemod->DemodCtrlUpdateAgc                      = realtek_i_dvbc_common_DemodCtrlUpdateAgcCmd;
	pDemod->DemodCtrlQueryStatus                    = realtek_i_dvbc_common_DemodCtrlQueryStatusCmd;

	pDemod->GetDemodStatus                          = realtek_i_dvbc_common_GetDemodStatus;

	pDemod->SetTunerFreq                            = realtek_i_dvbc_common_SetTunerFreqCmd;
	pDemod->SetTunerBandwidth                       = realtek_i_dvbc_common_SetTunerBandwidth;
	pDemod->SetTunerGridBase                        = realtek_i_dvbc_common_SetTunerGridBase;
	pDemod->SetTunerGridIncr                        = realtek_i_dvbc_common_SetTunerGridIncr;
	pDemod->GetActiveTunerFreq                      = realtek_i_dvbc_common_GetActiveTunerFreq;
	pDemod->GetActiveTunerBandwidth                 = realtek_i_dvbc_common_GetActiveTunerBandwidth;
	pDemod->GetActiveTunerGain                      = realtek_i_dvbc_common_GetActiveTunerGain;
	pDemod->GetActiveTunerRssi                      = realtek_i_dvbc_common_GetActiveTunerRssi;

	pDemod->SetNotchFreq                            = realtek_i_dvbc_common_SetNotchFreqCmd;
	pDemod->SetNotchBandwidth                       = realtek_i_dvbc_common_SetNotchBandwidth;

	pDemod->SetAgcParams                            = realtek_i_dvbc_common_SetAgcParams;
	pDemod->GetAgcParams                            = realtek_i_dvbc_common_GetAgcParams;
	pDemod->SetTsConfig                             = realtek_i_dvbc_common_SetTsConfig;
	pDemod->SetTsClkRateMargin                      = realtek_i_dvbc_common_SetTsClkRateMargin;
	pDemod->SetTsClkRateMax                         = realtek_i_dvbc_common_SetTsClkRateMax;
	pDemod->GetDemodLockTime                        = realtek_i_dvbc_common_GetDemodLockTime;

	pDemod->SetXmlTunerCfgOverride                  = realtek_i_dvbc_common_SetXmlTunerCfgOverride;
	pDemod->SetXmlTunerGainCtrl	                    = realtek_i_dvbc_common_SetXmlTunerGainCtrl;
	pDemod->SetXmlFlags                             = realtek_i_dvbc_common_SetXmlFlags;
	pDemod->SetXmlIfFreq                            = realtek_i_dvbc_common_SetXmlIfFreq;
	pDemod->SetXmlPlftCfgOverride                   = realtek_i_dvbc_common_SetXmlPlatformCfgOverride;
	pDemod->SetXmlIfClk                             = realtek_i_dvbc_common_SetXmlIfClk;
	pDemod->SetXmlLdpcClk                           = realtek_i_dvbc_common_SetXmlLdpcClk;
	pDemod->SetXmlUccClk                            = realtek_i_dvbc_common_SetXmlUccClk;
	pDemod->SetXmlMcuClk                            = realtek_i_dvbc_common_SetXmlMcuClk;

	pDemod->SetVirtualRegister                      = realtek_i_dvbc_common_SetVirtualRegister;
	pDemod->GetVirtualRegister                      = realtek_i_dvbc_common_GetVirtualRegister;
	pDemod->SetCtrlVirtualRegister                  = realtek_i_dvbc_common_SetCtrlVirtualRegister;
	pDemod->GetCtrlVirtualRegister                  = realtek_i_dvbc_common_GetCtrlVirtualRegister;
	pDemod->SetHwRegValue                           = realtek_i_dvbc_common_SetHwRegValue;
	pDemod->GetHwRegValue                           = realtek_i_dvbc_common_GetHwRegValue;

	pDemod->GetIsNoSignal                           = realtek_i_dvbc_GetIsNoSignal;
	pDemod->GetSystemState                          = realtek_i_dvbc_GetSystemState;

	pDemod->SetEnableQamSearch                      = realtek_i_dvbc_SetEnableQamSearch;
	pDemod->GetEnableQamSearch                      = realtek_i_dvbc_GetEnableQamSearch;
	pDemod->SetFixQamSize                           = realtek_i_dvbc_SetFixQamSize;
	pDemod->GetFixQamSize                           = realtek_i_dvbc_GetFixQamSize;
	pDemod->SetQamSearchList                        = realtek_i_dvbc_SetQamSearchList;
	pDemod->GetQamSearchList                        = realtek_i_dvbc_GetQamSearchList;

	pDemod->SetSymbolRateSearchMode                 = realtek_i_dvbc_SetSymbolRateSearchMode;
	pDemod->GetSymbolRateSearchMode                 = realtek_i_dvbc_GetSymbolRateSearchMode;
	pDemod->SetFixSymbolRate                        = realtek_i_dvbc_SetFixSymbolRate;
	pDemod->GetFixSymbolRate                        = realtek_i_dvbc_GetFixSymbolRate;
	pDemod->SetSymbolRateList                       = realtek_i_dvbc_SetSymbolRateList;
	pDemod->GetSymbolRateList                       = realtek_i_dvbc_GetSymbolRateList;
	pDemod->SetMinSymbolRate                        = realtek_i_dvbc_SetMinSymbolRate;
	pDemod->GetMinSymbolRate                        = realtek_i_dvbc_GetMinSymbolRate;
	pDemod->SetMaxSymbolRate                        = realtek_i_dvbc_SetMaxSymbolRate;
	pDemod->GetMaxSymbolRate                        = realtek_i_dvbc_GetMaxSymbolRate;

	pDemod->SetEnableSpectrumInversionSearch        = realtek_i_dvbc_SetEnableSpectrumInversionSearch;
	pDemod->GetEnableSpectrumInversionSearch        = realtek_i_dvbc_GetEnableSpectrumInversionSearch;
	pDemod->SetFixSpectrumInverseMode               = realtek_i_dvbc_SetFixSpectrumInverseMode;
	pDemod->GetFixSpectrumInverseMode               = realtek_i_dvbc_GetFixSpectrumInverseMode;

	pDemod->GetMonitorSymbolRate                    = realtek_i_dvbc_GetMonitorSymbolRate;
	pDemod->GetMonitorCarrierFrequency              = realtek_i_dvbc_GetMonitorCarrierFrequency;
	pDemod->GetMonitorQamSize                       = realtek_i_dvbc_GetMonitorQamSize;
	pDemod->GetMonitorSpectrumInversion             = realtek_i_dvbc_GetMonitorSpectrumInversion;

	pDemod->GetEqOutputSnr                          = realtek_i_dvbc_GetEqOutputSnr;
	pDemod->GetTsPacketNumber                       = realtek_i_dvbc_GetTsPacketNumber;
	pDemod->GetBadPacketNumber                      = realtek_i_dvbc_GetBadPacketNumber;
	pDemod->GetByteErrorNumber                      = realtek_i_dvbc_GetByteErrorNumber;
	pDemod->GetBitErrorNumber                       = realtek_i_dvbc_GetBitErrorNumber;

	pDemod->SetBerAveLength                         = realtek_i_dvbc_SetBerAveLength;
	pDemod->GetBerAveLength                         = realtek_i_dvbc_GetBerAveLength;
	pDemod->GetRsAveBer                             = realtek_i_dvbc_GetRsAveBer;
	pDemod->GetRsAvePer                             = realtek_i_dvbc_GetRsAvePer;
	pDemod->GetEqAveSnr                             = realtek_i_dvbc_GetEqAveSnr;

	pDemod->GetCoarseCarrierSyncSubState            = realtek_i_dvbc_GetCoarseCarrierSyncSubState;
	pDemod->GetEqAdaptationSubState                 = realtek_i_dvbc_GetEqAdaptationSubState;

	pDemod->GetAcquisitionTime                      = realtek_i_dvbc_GetAcquisitionTime;
	pDemod->SetAcquisitionTimerReset                = realtek_i_dvbc_SetAcquisitionTimerReset;
	pDemod->GetAcquisitionTimerReset                = realtek_i_dvbc_GetAcquisitionTimerReset;

	pDemod->SetFailCounterReset                     = realtek_i_dvbc_SetFailCounterReset;
	pDemod->GetFailCounterReset                     = realtek_i_dvbc_GetFailCounterReset;
	pDemod->GetCoastSymbolTimingFailNumber         = realtek_i_dvbc_GetCoastSymbolTimingFailNumber;
	pDemod->GetFineSymbolTimingFailNumber           = realtek_i_dvbc_GetFineSymbolTimingFailNumber;
	pDemod->GetCarrierSyncFailNumber                = realtek_i_dvbc_GetCarrierSyncFailNumber;
	pDemod->GetQamSearchFailNumber                  = realtek_i_dvbc_GetQamSearchFailNumber;
	pDemod->GetSpectrumInversionSearchFailNumber    = realtek_i_dvbc_GetSpectrumInversionSearchFailNumber;
	pDemod->GetUnSupportTsRateFailNumber            = realtek_i_dvbc_GetUnSupportTsRateFailNumber;
	pDemod->GetPerFailNumber                        = realtek_i_dvbc_GetPerFailNumber;
	pDemod->GetSignalDropoutFailNumber              = realtek_i_dvbc_GetSignalDropoutFailNumber;
	pDemod->GetLastFailCase                         = realtek_i_dvbc_GetLastFailCase;

	pDemod->SetEqUpdateRate                         = realtek_i_dvbc_SetEqUpdateRate;
	pDemod->GetEqUpdateRate                         = realtek_i_dvbc_GetEqUpdateRate;

	pDemod->SetBadPacketByteErrorNumber             = realtek_i_dvbc_SetBadPacketByteErrorNumber;
	pDemod->GetBadPacketByteErrorNumber             = realtek_i_dvbc_GetBadPacketByteErrorNumber;
	pDemod->SetBadPacketBitErrorNumber              = realtek_i_dvbc_SetBadPacketBitErrorNumber;
	pDemod->GetBadPacketBitErrorNumber              = realtek_i_dvbc_GetBadPacketBitErrorNumber;
	pDemod->SetBadSetBadPacketPercentage            = realtek_i_dvbc_SetBadSetBadPacketPercentage;
	pDemod->GetBadSetBadPacketPercentage            = realtek_i_dvbc_GetBadSetBadPacketPercentage;
	pDemod->SetFailErrorRate                        = realtek_i_dvbc_SetFailErrorRate;
	pDemod->GetFailErrorRate                        = realtek_i_dvbc_GetFailErrorRate;

	pDemod->SetPhaseTrackerLoopGain                 = realtek_i_dvbc_SetPhaseTrackerLoopGain;
	pDemod->GetPhaseTrackerLoopGain                 = realtek_i_dvbc_GetPhaseTrackerLoopGain;
	pDemod->SetDagcPower                            = realtek_i_dvbc_SetDagcPower;
	pDemod->GetDagcPower                            = realtek_i_dvbc_GetDagcPower;

	pDemod->GetSignalSSI 				= realtek_i_dvbc_GetSignalSSI;
	pDemod->GetSignalSQI 				= realtek_i_dvbc_GetSignalSQI;
	pDemod->UpdateFunction 			= realtek_i_dvbc_UpdateFunction;

	return;
}


/*
Cable system state machine state
0: DAGC convergence state
1: Coarse symbol timing sync state
2: Coarse carrier sync state
3: Equaliser adaptation state
4~5: Reserved
6: Tracking state
7: TS output valid
*/
int
realtek_i_dvbc_GetSystemState(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *SystemState
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_SYSTEM_STATE, 0, SystemState) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*SystemState &= CABLE_BITFLD_SYSTEM_STATE;

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
5~7: Reserved
*/
int
realtek_i_dvbc_GetCoarseCarrierSyncSubState(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *SyncSubState
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_CCS_STATE, 0, SyncSubState) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*SyncSubState &= CABLE_BITFLD_CCS_STATE;

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
4: Fine decision directed (DD) state ¡V Tracking state
5~7: Reserved
*/
int
realtek_i_dvbc_GetEqAdaptationSubState(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *EqAdaptState
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_EQADAPT_STATE, 0, EqAdaptState) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*EqAdaptState &= CABLE_BITFLD_EQADAPT_STATE;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
Signal detection result.
0: Signal detection passed or still in progress.
1: Signal detection routine complete. No signal found.
*/
int
realtek_i_dvbc_GetIsNoSignal(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *IsSignalFound
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_SIGNAL_NOT_FOUND, 0, IsSignalFound) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*IsSignalFound &= CABLE_BITFLD_SIGNAL_NOT_FOUND;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
Current symbol rate in Symbols Per Sec. This value is derived based on given ADC clock rate,
hence if there is error in the ADC clock rate, the number here also contains same ppm error
as ADC clock rate. This value is valid while CABLE_BITFLD_SYSTEM_STATE = 7 (TS output valid state).
*/
int
realtek_i_dvbc_GetMonitorSymbolRate(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *MonSymbolRate
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_SYM_RATE_MON, 0, MonSymbolRate) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*MonSymbolRate &= CABLE_BITFLD_SYM_RATE_MON;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
Current carrier frequency in Hz. This value is derived based on given ADC clock rate,
hence if there is error in the ADC clock rate, the number here also contains same ppm
error as ADC clock rate. This value is valid while CABLE_BITFLD_SYSTEM_STATE = 7 (TS output valid state).
*/
int
realtek_i_dvbc_GetMonitorCarrierFrequency(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *MonCarrierFreq
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_CARR_FREQ_MON, 0, MonCarrierFreq) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*MonCarrierFreq &= CABLE_BITFLD_CARR_FREQ_MON;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
Current QAM size monitor. To get correct QAM size on a particular channel,
it is safe to read this register after CABLE_BITFLD_SYSTEM_STATE = 7 (TS output valid state).
0: 16QAM
1: 32QAM
2: 64QAM
3: 128QAM
4: 256QAM
5~7: Reserved
*/
int
realtek_i_dvbc_GetMonitorQamSize(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *MonQamSize
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_QAM_MON, 0, MonQamSize) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*MonQamSize &= CABLE_BITFLD_QAM_MON;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
Current spectrum inversion setup monitor. To get correct spectrum inversion setup on a particular channel,
it is safe to read this register after CABLE_BITFLD_SYSTEM_STATE = 7 (TS output valid state).
0: No spectrum inversion
1: Spectrum inverted
*/
int
realtek_i_dvbc_GetMonitorSpectrumInversion(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *MonSpecInv
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_SPEC_INV_MON, 0, MonSpecInv) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*MonSpecInv &= CABLE_BITFLD_SPEC_INV_MON;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
Time taken from point of entering TV_STATE_ACQDEMOD to entering CABLE_STATE_TS_OUTPUT_VALID in milliseconds.
This value will accumulate time over any failure cases until TV_CMD_STOP is issued or
CABLE_BITFLD_AQUISITION_TIME_RESET is set to 1.
*/
int
realtek_i_dvbc_GetAcquisitionTime(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *AcqTime
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_AQUISITION_TIME, 0, AcqTime) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*AcqTime &= CABLE_BITFLD_AQUISITION_TIME;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
Reset acquisition timer.
0: Acquisition timer will not be reset, it will accumulate the results
1: Acquisition timer will be reset. Once complete this field will be returned to 0.
*/
int
realtek_i_dvbc_SetAcquisitionTimerReset(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int AcqTimerReset
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	AcqTimerReset &= CABLE_BITFLD_AQUISITION_TIME_RESET;

	if (MsgSetReg(CABLE_REG_AQUISITION_TIME_RESET, 0, AcqTimerReset) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


int
realtek_i_dvbc_GetAcquisitionTimerReset(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *AcqTimerReset
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_AQUISITION_TIME_RESET, 0, AcqTimerReset) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*AcqTimerReset &= CABLE_BITFLD_AQUISITION_TIME_RESET;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
Estimated equaliser output SNR in dB. The SNR is estimated using a hard decision symbol and
equalized symbol to calculate the error power. This field becomes valid at Coarse decision
directed stage in Equaliser adaptation substate. The SNR is encoded as follows:
SNR [dB] = CABLE_BITFLD_EQ_SNR_DB / 256
*/
int
realtek_i_dvbc_GetEqOutputSnr(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *EqOutSnr
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_EQ_SNR_DB, 0, EqOutSnr) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*EqOutSnr &= CABLE_BITFLD_EQ_SNR_DB;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
Number of MPEG-2 TS packets processed.
This register is updated by writing a TV_CMD_UPDATE_COUNTERS command to the TV_REG_CONTROL register.
It is reset by writing a TV_CMD_RESET_COUNTERS command to the TV_REG_CONTROL register.
The CABLE_REG_NUM_BADPKTS, CABLE_REG_NUM_BYTE_ERRS and CABLE_REG_NUM_BIT_ERRS registers
are also affected by issuing these commands
*/
int
realtek_i_dvbc_GetTsPacketNumber(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *TsPacketNumber
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_NUM_PKTS, 0, TsPacketNumber) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*TsPacketNumber &= CABLE_BITFLD_NUM_PKTS;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
Number of packets containing errors after the RS decoder, out of CABLE_BITFLD_NUM_PKTS total packets processed.
Packet error rate (PER) after RS decoder can be calculated as:
PER = CABLE_BITFLD_NUM_BADPKTS / CABLE_BITFLD_NUM_PKTS
This register is updated by writing a TV_CMD_UPDATE_COUNTERS command to the TV_REG_CONTROL register.
It is reset by writing a TV_CMD_RESET_COUNTERS command to the TV_REG_CONTROL register.
The CABLE_REG_NUM_PKTS, CABLE_REG_NUM_BYTE_ERRS and CABLE_REG_NUM_BIT_ERRS registers are
also affected by issuing these commands.
*/
int
realtek_i_dvbc_GetBadPacketNumber(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *BadPacketNumber
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_NUM_BADPKTS, 0, BadPacketNumber) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*BadPacketNumber &= CABLE_BITFLD_NUM_BADPKTS;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
Estimated number of byte errors within CABLE_BITFLD_NUM_PKTS processed packets.
The number of byte errors within bad packets cannot be accurately detected.
Therefore, in estimating the total number of byte errors, bad packets are assumed to
contain CABLE_BITFLD_BYTE_ERR_BADPKTS byte errors.
Byte error rate (ByteER) can be calculated as:
ByteER = CABLE_BITFLD_NUM_BYTE_ERRS / (CABLE_BITFLD_NUM_PKTS*204)
This register is updated by writing a TV_CMD_UPDATE_COUNTERS command to the TV_REG_CONTROL register.
It is reset by writing a TV_CMD_RESET_COUNTERS command to the TV_REG_CONTROL register.
The CABLE_REG_NUM_PKTS, CABLE_REG_NUM_BADPKTS and CABLE_REG_NUM_BIT_ERRS registers
are also affected by issuing these commands.
*/
int
realtek_i_dvbc_GetByteErrorNumber(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *ByteErrorNumber
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_NUM_BYTE_ERRS, 0, ByteErrorNumber) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*ByteErrorNumber &= CABLE_BITFLD_NUM_BYTE_ERRS;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
Estimated number of bit errors within CABLE_BITFLD_NUM_PKTS processed packets.
The number of bit errors within bad packets cannot be accurately detected.
Therefore, in estimating the total number of bit errors, bad packets are
assumed to contain CABLE_BITFLD_BIT_ERR_BADPKTS bit errors.
Bit error rate (BER) can be calculated as:
BER = CABLE_BITFLD_NUM_BIT_ERRS / (CABLE_BITFLD_NUM_PKTS*204*8)
This register is updated by writing a TV_CMD_UPDATE_COUNTERS command to the TV_REG_CONTROL register.
It is reset by writing a TV_CMD_RESET_COUNTERS command to the TV_REG_CONTROL register.
The CABLE_REG_NUM_PKTS, CABLE_REG_NUM_BADPKTS and CABLE_REG_NUM_BYTE_ERRS registers
are also affected by issuing these commands.
*/
int
realtek_i_dvbc_GetBitErrorNumber(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *BitErrorNumber
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_NUM_BIT_ERRS, 0, BitErrorNumber) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*BitErrorNumber &= CABLE_BITFLD_NUM_BIT_ERRS;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
The number of seconds over which the Bit Error Rate, Packet Error Rate and Signal to
Noise Ratio will be averaged. Range 1-30.
*/
int
realtek_i_dvbc_SetBerAveLength(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int BerAveLength
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	BerAveLength &= CABLE_BITFLD_NUM_SECS_BER_AVERAGE;

	if (MsgSetReg(CABLE_REG_NUM_SECS_BER_AVERAGE, 0, BerAveLength) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


int
realtek_i_dvbc_GetBerAveLength(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *BerAveLength
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_NUM_SECS_BER_AVERAGE, 0, BerAveLength) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*BerAveLength &= CABLE_BITFLD_NUM_SECS_BER_AVERAGE;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
Measured RS bit error rate. Unsigned ratio with 32 fractional bits.
This measurement is averaged over the interval specified in CABLE_REG_NUM_SECS_BER_AVERAGE.
It will be valid while in the demodulating state and is updated once per second.
*/
int
realtek_i_dvbc_GetRsAveBer(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *RsBer
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_RS_AVERAGE_BER, 0, RsBer) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*RsBer &= CABLE_BITFLD_RS_AVERAGE_BER;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
Measured RS packet error rate. Unsigned ratio with 32 fractional bits.
This measurement is averaged over the interval specified in CABLE_REG_NUM_SECS_BER_AVERAGE.
It will be valid while in the demodulating state and is updated once per second.
*/
int
realtek_i_dvbc_GetRsAvePer(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *RsPer
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_RS_AVERAGE_PER, 0, RsPer) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*RsPer &= CABLE_BITFLD_RS_AVERAGE_PER;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
Measured equalizer SNR. This value is encoded as below:
SNR [dB] = CABLE_BITFLD_EQ_AVERAGE_SNR / 256
This measurement is averaged over the interval specified in CABLE_REG_NUM_SECS_BER_AVERAGE.
It will be valid while in the demodulating state and is updated once per second.
*/
int
realtek_i_dvbc_GetEqAveSnr(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *EqSnr
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_EQ_AVERAGE_SNR, 0, EqSnr) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*EqSnr &= CABLE_BITFLD_EQ_AVERAGE_SNR;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
Set to initiate resetting failure counters:
And the register is reset when the resetting counters are completed.
*/
int
realtek_i_dvbc_SetFailCounterReset(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int FailCntRst
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	FailCntRst &= CABLE_BITFLD_FAILURE_COUNTERS_RESET;

	if (MsgSetReg(CABLE_REG_FAILURE_COUNTERS_RESET, 0, FailCntRst) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


int
realtek_i_dvbc_GetFailCounterReset(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *FailCntRst
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_FAILURE_COUNTERS_RESET, 0, FailCntRst) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*FailCntRst &= CABLE_BITFLD_FAILURE_COUNTERS_RESET;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
Number of reacquisition¡¦s caused by coarse symbol timing failure.
*/
int
realtek_i_dvbc_GetCoastSymbolTimingFailNumber(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *CourseSymbolFailNum
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_NUM_COARSE_SYMTIM_FAILURE, 0, CourseSymbolFailNum) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*CourseSymbolFailNum &= CABLE_BITFLD_NUM_COARSE_SYMTIM_FAILURE;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
Number of reacquisition¡¦s caused by fine symbol timing failure.
*/
int
realtek_i_dvbc_GetFineSymbolTimingFailNumber(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *FineSymbolFailNum
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_NUM_FINE_SYMTIM_FAILURE, 0, FineSymbolFailNum) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*FineSymbolFailNum &= CABLE_BITFLD_NUM_FINE_SYMTIM_FAILURE;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
Number of reacquisition¡¦s caused by carrier synchronisation failure.
*/
int
realtek_i_dvbc_GetCarrierSyncFailNumber(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *CarrierSyncFailNum
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_NUM_CARRSYNC_FAILURE, 0, CarrierSyncFailNum) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*CarrierSyncFailNum &= CABLE_BITFLD_NUM_CARRSYNC_FAILURE;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
Number of reacquisition¡¦s caused by failure to find QAM size / equalizer adaptation failure.
*/
int
realtek_i_dvbc_GetQamSearchFailNumber(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *QamSearchFailNum
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_NUM_QAM_SEARCH_FAILURE, 0, QamSearchFailNum) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*QamSearchFailNum &= CABLE_BITFLD_NUM_QAM_SEARCH_FAILURE;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
Number of reacquisition¡¦s caused by spectrum to inversion search failure / TSP sync failure.
*/
int
realtek_i_dvbc_GetSpectrumInversionSearchFailNumber(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *SpecInvSearchFailNum
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_NUM_SPECINV_SEARCH_FAILURE, 0, SpecInvSearchFailNum) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*SpecInvSearchFailNum &= CABLE_BITFLD_NUM_SPECINV_SEARCH_FAILURE;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
Number of reacquisition¡¦s caused by the TS data rate exceeding the limits set by the
TV_REG_TSO_CLK_RATE_MARGIN and TV_REG_TSO_CLK_RATE_MAX registers [i].
*/
int
realtek_i_dvbc_GetUnSupportTsRateFailNumber(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *UnSuppTsRateFailNum
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_NUM_TS_RATE_FAILURE, 0, UnSuppTsRateFailNum) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*UnSuppTsRateFailNum &= CABLE_BITFLD_NUM_TS_RATE_FAILURE;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
Number of reacquisition¡¦s caused by PER failure.
*/
int
realtek_i_dvbc_GetPerFailNumber(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *PerFailNum
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_NUM_PER_FAILURE, 0, PerFailNum) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*PerFailNum &= CABLE_BITFLD_NUM_PER_FAILURE;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
Number of reacquisition¡¦s caused by signal dropout failure.
*/
int
realtek_i_dvbc_GetSignalDropoutFailNumber(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *SignalDropFailNum
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_NUM_SIGNAL_DROPOUT_FAILURE, 0, SignalDropFailNum) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*SignalDropFailNum &= CABLE_BITFLD_NUM_SIGNAL_DROPOUT_FAILURE;

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
4: QAM search failure
5: Reserved.
6: Reserved.
7: Spectrum inversion search / TSP sync failure.
8: Unsupported TS data rate failure.
9: PER failure.
*/
int
realtek_i_dvbc_GetLastFailCase(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *LastFailCase
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_LAST_FAILURE, 0, LastFailCase) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*LastFailCase &= CABLE_BITFLD_LAST_FAILURE;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
Enable auto QAM search.
0: Disable QAM search. Using a QAM specified in CABLE_BITFLD_QAM_FIXED.
1: Enable QAM search.Search through a list of QAM specified in CABLE_BITFLD_QAM_SEARCH
*/
int
realtek_i_dvbc_SetEnableQamSearch(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int EnQamSearch
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	EnQamSearch &= CABLE_BITFLD_QAM_SEARCH_ENABLE;

	if (MsgSetReg(CABLE_REG_QAM_SEARCH_ENABLE, 0, EnQamSearch) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


int
realtek_i_dvbc_GetEnableQamSearch(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *EnQamSearch
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_QAM_SEARCH_ENABLE, 0, EnQamSearch) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*EnQamSearch &= CABLE_BITFLD_QAM_SEARCH_ENABLE;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
Specify which QAM is used in QAM_SEARCH_ENABLE = 0 case.
0: 16QAM
1: 32QAM
2: 64QAM
3: 128QAM
4: 256QAM
5~7: Reserved
*/
int
realtek_i_dvbc_SetFixQamSize(
	DVBC_DEMOD_MODULE *pDemod,
	int QamMode
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	unsigned int QamFixSize = 0;

	//Rtd Api Translate to Driver Def
	switch (QamMode) {
	case DVBC_QAM_16:
		QamFixSize = 0;
		break;
	case DVBC_QAM_32:
		QamFixSize = 1;
		break;
	case DVBC_QAM_64:
		QamFixSize = 2;
		break;
	case DVBC_QAM_128:
		QamFixSize = 3;
		break;
	case DVBC_QAM_256:
		QamFixSize = 4;
		break;
	}

	// Set demod QAM mode parameter.
	pDemod->QamMode      = QamMode;
	pDemod->IsQamModeSet = YES;


	QamFixSize &= CABLE_BITFLD_QAM_FIXED;
	if (MsgSetReg(CABLE_REG_QAM_FIXED, 0, QamFixSize) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


int
realtek_i_dvbc_GetFixQamSize(
	DVBC_DEMOD_MODULE *pDemod,
	int *QamMode
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	unsigned int QamFixSize;

	if (MsgGetReg(CABLE_REG_QAM_FIXED, 0, &QamFixSize) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	QamFixSize &= CABLE_BITFLD_QAM_FIXED;

	//Driver Def Translate to Rtd Api
	switch (QamFixSize) {
	case 0:
		*QamMode = DVBC_QAM_16;
		break;
	case 1:
		*QamMode  = DVBC_QAM_32;
		break;
	case 2:
		*QamMode  = DVBC_QAM_64;
		break;
	case 3:
		*QamMode  = DVBC_QAM_128;
		break;
	case 4:
		*QamMode  = DVBC_QAM_256;
		break;
	}

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
Symbol                          Bit(s)  Description
CABLE_BITFLD_QAM_SEARCH_256QAM  4       Set to add 256QAM to a QAM search list.
CABLE_BITFLD_QAM_SEARCH_128QAM  3       Set to add 128QAM to a QAM search list.
CABLE_BITFLD_QAM_SEARCH_64QAM   2       Set to add 64QAM to a QAM search list
CABLE_BITFLD_QAM_SEARCH_32QAM   1       Set to add 32QAM to a QAM search list.
CABLE_BITFLD_QAM_SEARCH_16QAM   0       Set to add 16QAM to a QAM search list.
*/
int
realtek_i_dvbc_SetQamSearchList(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int QamSearchList
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	QamSearchList &= (CABLE_BITFLD_QAM_SEARCH_256QAM | CABLE_BITFLD_QAM_SEARCH_128QAM |
					  CABLE_BITFLD_QAM_SEARCH_64QAM | CABLE_BITFLD_QAM_SEARCH_32QAM | CABLE_BITFLD_QAM_SEARCH_16QAM);

	if (MsgSetReg(CABLE_REG_QAM_SEARCH, 0, QamSearchList) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


int
realtek_i_dvbc_GetQamSearchList(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *QamSearchList
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_QAM_SEARCH, 0, QamSearchList) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*QamSearchList &= (CABLE_BITFLD_QAM_SEARCH_256QAM | CABLE_BITFLD_QAM_SEARCH_128QAM |
					   CABLE_BITFLD_QAM_SEARCH_64QAM | CABLE_BITFLD_QAM_SEARCH_32QAM | CABLE_BITFLD_QAM_SEARCH_16QAM);

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
Symbol rate search mode.
0: Fixed mode. Using symbol rate in Fixed Symbol Rate register
   (CABLE_BITFLD_SYM_FIXED).
1: List mode. Search through in Symbol Rate List 0 ¡V 7 registers.
2: Range mode. Search symbol rate between min/max symbol rate registers.
   (Higher symbol rate tried first, and then it is gradually reduced.)
3: Reserved
*/
int
realtek_i_dvbc_SetSymbolRateSearchMode(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int SrSearchMode
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	SrSearchMode &= CABLE_BITFLD_SYM_SEARCH_MODE;

	if (MsgSetReg(CABLE_REG_SYM_SEARCH_MODE, 0, SrSearchMode) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


int
realtek_i_dvbc_GetSymbolRateSearchMode(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *SrSearchMode
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_SYM_SEARCH_MODE, 0, SrSearchMode) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*SrSearchMode &= CABLE_BITFLD_SYM_SEARCH_MODE;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
Symbol rate in Symbol Per Sec. This number is only used in case that Symbol rate
search mode is set to FIXED MODE (CABLE_BITFLD_SYM_SEARCH_MODE = 0).
If there is no more symbol rate to try, set to 0.
*/
int
realtek_i_dvbc_SetFixSymbolRate(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int FixSymbolRate
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	FixSymbolRate &= CABLE_BITFLD_SYM_FIXED;

	if (MsgSetReg(CABLE_REG_SYM_FIXED, 0, FixSymbolRate) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	// Set demod symbol rate parameter.
	pDemod->SymbolRateHz      = FixSymbolRate;
	pDemod->IsSymbolRateHzSet = YES;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


int
realtek_i_dvbc_GetFixSymbolRate(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *FixSymbolRate
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_SYM_FIXED, 0, FixSymbolRate) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*FixSymbolRate &= CABLE_BITFLD_SYM_FIXED;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
1st symbol rate in symbols per sec. to try in case that Symbol rate search mode is set
to LIST MODE (CABLE_BITFLD_SYM_SEARCH_MODE = 1).
If there is no more symbol rate to try, set to 0.
*/
int
realtek_i_dvbc_SetSymbolRateList(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int ListIndex,
	unsigned int ListSymbolRate
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	unsigned int RegAddr;

	ListSymbolRate &= CABLE_BITFLD_SYM_LIST0;

	if (ListIndex == 0)
		RegAddr = CABLE_REG_SYM_LIST0;
	else if (ListIndex == 1)
		RegAddr = CABLE_REG_SYM_LIST1;
	else if (ListIndex == 2)
		RegAddr = CABLE_REG_SYM_LIST2;
	else if (ListIndex == 3)
		RegAddr = CABLE_REG_SYM_LIST3;
	else if (ListIndex == 4)
		RegAddr = CABLE_REG_SYM_LIST4;
	else if (ListIndex == 5)
		RegAddr = CABLE_REG_SYM_LIST5;
	else if (ListIndex == 6)
		RegAddr = CABLE_REG_SYM_LIST6;
	else if (ListIndex == 7)
		RegAddr = CABLE_REG_SYM_LIST7;
	else
		goto error_status_set_list_index;

	if (MsgSetReg(RegAddr, 0, ListSymbolRate) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_list_index:
error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


int
realtek_i_dvbc_GetSymbolRateList(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int ListIndex,
	unsigned int *ListSymbolRate
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	unsigned int RegAddr;

	if (ListIndex == 0)
		RegAddr = CABLE_REG_SYM_LIST0;
	else if (ListIndex == 1)
		RegAddr = CABLE_REG_SYM_LIST1;
	else if (ListIndex == 2)
		RegAddr = CABLE_REG_SYM_LIST2;
	else if (ListIndex == 3)
		RegAddr = CABLE_REG_SYM_LIST3;
	else if (ListIndex == 4)
		RegAddr = CABLE_REG_SYM_LIST4;
	else if (ListIndex == 5)
		RegAddr = CABLE_REG_SYM_LIST5;
	else if (ListIndex == 6)
		RegAddr = CABLE_REG_SYM_LIST6;
	else if (ListIndex == 7)
		RegAddr = CABLE_REG_SYM_LIST7;
	else
		goto error_status_set_list_index;

	if (MsgGetReg(RegAddr, 0, ListSymbolRate) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*ListSymbolRate &= CABLE_BITFLD_SYM_LIST0;

	return FUNCTION_SUCCESS;

error_status_set_list_index:
error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Minimum symbol rate to try in case that Symbol search mode is set to
RANGE MODE (CABLE_BITFLD_SYM_SEARCH_MODE = 2).
*/
int
realtek_i_dvbc_SetMinSymbolRate(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int MinSymbolRate
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	MinSymbolRate &= CABLE_BITFLD_SYM_MIN;

	if (MsgSetReg(CABLE_REG_SYM_MIN, 0, MinSymbolRate) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


int
realtek_i_dvbc_GetMinSymbolRate(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *MinSymbolRate
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_SYM_MIN, 0, MinSymbolRate) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*MinSymbolRate &= CABLE_BITFLD_SYM_MIN;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
Max symbol rate to try in case that Symbol search mode is set to
RANGE MODE (CABLE_BITFLD_SYM_SEARCH_MODE = 2).
*/
int
realtek_i_dvbc_SetMaxSymbolRate(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int MaxSymbolRate
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	MaxSymbolRate &= CABLE_BITFLD_SYM_MAX;

	if (MsgSetReg(CABLE_REG_SYM_MAX, 0, MaxSymbolRate) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


int
realtek_i_dvbc_GetMaxSymbolRate(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *MaxSymbolRate
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_SYM_MAX, 0, MaxSymbolRate) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*MaxSymbolRate &= CABLE_BITFLD_SYM_MAX;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
Enable auto spectrum inversion search.
0: Disable spectrum inversion search. Using spectrum inversion
   specified in CABLE_BITFLD_SPECTRUM_INVERSION.
1: Enable spectrum inversion search. Check both inverted and non-inverted spectrums,
   starting with spectrum inversion specified in CABLE_BITFLD_SPECTRUM_INVERSION.
*/
int
realtek_i_dvbc_SetEnableSpectrumInversionSearch(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int EnSpecInvSearch
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	EnSpecInvSearch &= CABLE_BITFLD_SPECINV_SEARCH_ENABLE;

	if (MsgSetReg(CABLE_REG_SPECINV_SEARCH_ENABLE, 0, EnSpecInvSearch) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


int
realtek_i_dvbc_GetEnableSpectrumInversionSearch(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *EnSpecInvSearch
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_SPECINV_SEARCH_ENABLE, 0, EnSpecInvSearch) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*EnSpecInvSearch &= CABLE_BITFLD_SPECINV_SEARCH_ENABLE;

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
realtek_i_dvbc_SetFixSpectrumInverseMode(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int FixSpecInvMode
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	FixSpecInvMode &= CABLE_BITFLD_SPECTRUM_INVERSION;

	if (MsgSetReg(CABLE_REG_SPECTRUM_INVERSION, 0, FixSpecInvMode) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


int
realtek_i_dvbc_GetFixSpectrumInverseMode(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *FixSpecInvMode
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_SPECTRUM_INVERSION, 0, FixSpecInvMode) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*FixSpecInvMode &= CABLE_BITFLD_SPECTRUM_INVERSION;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
Specify number of byte errors on a bad packet to calculate CABLE_BITFLD_NUM_BYTE_ERRS register.
As the number of byte errors on bad packets cannot be accurately detected,
the number in this register is used in such a case. Typical number is 9,
as it is true most of case near QEF point.
*/
int
realtek_i_dvbc_SetBadPacketByteErrorNumber(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int BadPktByteErrNum
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	BadPktByteErrNum &= CABLE_BITFLD_BYTE_ERR_BADPKTS;

	if (MsgSetReg(CABLE_REG_BYTE_ERR_BADPKTS, 0, BadPktByteErrNum) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


int
realtek_i_dvbc_GetBadPacketByteErrorNumber(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *BadPktByteErrNum
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_BYTE_ERR_BADPKTS, 0, BadPktByteErrNum) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*BadPktByteErrNum &= CABLE_BITFLD_BYTE_ERR_BADPKTS;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
Specify number of bit errors on a bad packet to calculate CABLE_BITFLD_NUM_BIT_ERRS register.
As the number of bit errors on bad packets cannot be accurately detected,
the number in this register is used in such a case.
Typical number is 16, as it is true most of case near QEF point.
*/
int
realtek_i_dvbc_SetBadPacketBitErrorNumber(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int BadPktBitErrNum
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	BadPktBitErrNum &= CABLE_BITFLD_BIT_ERR_BADPKTS;

	if (MsgSetReg(CABLE_REG_BIT_ERR_BADPKTS, 0, BadPktBitErrNum) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


int
realtek_i_dvbc_GetBadPacketBitErrorNumber(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *BadPktBitErrNum
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_BIT_ERR_BADPKTS, 0, BadPktBitErrNum) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*BadPktBitErrNum &= CABLE_BITFLD_BIT_ERR_BADPKTS;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
Percentage of uncorrectable packets needed in one update period for the set of data
to be considered bad. Each update period is 58240 symbols long.
*/
int
realtek_i_dvbc_SetBadSetBadPacketPercentage(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int BadSetBadPktPercentage
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	BadSetBadPktPercentage &= CABLE_BITFLD_PERCENT_BADPKTS_BADSET;

	if (MsgSetReg(CABLE_REG_PERCENT_BADPKTS_BADSET, 0, BadSetBadPktPercentage) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


int
realtek_i_dvbc_GetBadSetBadPacketPercentage(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *BadSetBadPktPercentage
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_PERCENT_BADPKTS_BADSET, 0, BadSetBadPktPercentage) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*BadSetBadPktPercentage &= CABLE_BITFLD_PERCENT_BADPKTS_BADSET;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
Number of consecutive bad sets as defined in CABLE_BITFLD_PERCENT_BADPKTS_BADSET
for reacquisition due to the PER failure to occur.
Once TS Sync lock occurs the output packets are monitored.
If in one update period the percentage of uncorrectable packets exceeds the value
in CABLE_BITFLD_PERCENT_BADPKTS_BADSET then this set is marked as bad.
If this then occurs repeatedly for the number of consecutive sets defined in
CABLE_BITFLD_SER_FAILURE the system is considered to have failed so the system
is reset and acquisition starts again. The PER failure counter is incremented.
*/
int
realtek_i_dvbc_SetFailErrorRate(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int BadSetBadPktPercentage
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	BadSetBadPktPercentage &= CABLE_BITFLD_SER_FAILURE;

	if (MsgSetReg(CABLE_REG_SER_FAILURE, 0, BadSetBadPktPercentage) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


int
realtek_i_dvbc_GetFailErrorRate(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *BadSetBadPktPercentage
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_SER_FAILURE, 0, BadSetBadPktPercentage) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*BadSetBadPktPercentage &= CABLE_BITFLD_SER_FAILURE;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
Phase tracker loop gain for 16QAM constellation. Valid range 0:9.
Phase Tracker loop bandwidth = SymbolRate * 2^(gain-21),
giving a bandwidth range of SymbolRate * 2^-21 to SymbolRate * 2^-12.
*/
int
realtek_i_dvbc_SetPhaseTrackerLoopGain(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int QamMode,
	unsigned int PhaseTrackLoopGain
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	unsigned int RegAddr;

	PhaseTrackLoopGain &= CABLE_BITFLD_PTGAIN16QAM;

	if (QamMode == 0)
		RegAddr = CABLE_REG_PTGAIN_16QAM;
	else if (QamMode == 1)
		RegAddr = CABLE_REG_PTGAIN_32QAM;
	else if (QamMode == 2)
		RegAddr = CABLE_REG_PTGAIN_64QAM;
	else if (QamMode == 3)
		RegAddr = CABLE_REG_PTGAIN_128QAM;
	else if (QamMode == 4)
		RegAddr = CABLE_REG_PTGAIN_256QAM;
	else
		goto error_status_set_list_index;

	if (MsgSetReg(RegAddr, 0, PhaseTrackLoopGain) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_list_index:
error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


int
realtek_i_dvbc_GetPhaseTrackerLoopGain(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int QamMode,
	unsigned int *PhaseTrackLoopGain
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	unsigned int RegAddr;

	if (QamMode == 0)
		RegAddr = CABLE_REG_PTGAIN_16QAM;
	else if (QamMode == 1)
		RegAddr = CABLE_REG_PTGAIN_32QAM;
	else if (QamMode == 2)
		RegAddr = CABLE_REG_PTGAIN_64QAM;
	else if (QamMode == 3)
		RegAddr = CABLE_REG_PTGAIN_128QAM;
	else if (QamMode == 4)
		RegAddr = CABLE_REG_PTGAIN_256QAM;
	else
		goto error_status_set_list_index;

	if (MsgGetReg(RegAddr, 0, PhaseTrackLoopGain) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*PhaseTrackLoopGain &= CABLE_BITFLD_PTGAIN16QAM;

	return FUNCTION_SUCCESS;

error_status_set_list_index:
error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
Target digital AGC receiver power value Q0.23.
*/
int
realtek_i_dvbc_SetDagcPower(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int DagcPower
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	DagcPower &= CABLE_BITFLD_TUNE_DAGC_POWER;

	if (MsgSetReg(CABLE_REG_TUNE_DAGC_POWER, 0, DagcPower) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


int
realtek_i_dvbc_GetDagcPower(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *DagcPower
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_TUNE_DAGC_POWER, 0, DagcPower) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*DagcPower &= CABLE_BITFLD_TUNE_DAGC_POWER;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
Signed integer exponent of Equalizer update factor 2^(TUNE_EQ_UPDATE_STEPSIZE).
Default initial value of -14 (0xFFFFF2) optimized for normal working conditions. Signed Q23.0.
*/
int
realtek_i_dvbc_SetEqUpdateRate(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int EqUpdateRate
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	EqUpdateRate &= CABLE_BITFLD_TUNE_EQ_UPDATE_STEPSIZE;

	if (MsgSetReg(CABLE_REG_TUNE_EQ_UPDATE_STEPSIZE, 0, EqUpdateRate) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


int
realtek_i_dvbc_GetEqUpdateRate(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *EqUpdateRate
)
{
	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(CABLE_REG_TUNE_EQ_UPDATE_STEPSIZE, 0, EqUpdateRate) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*EqUpdateRate &= CABLE_BITFLD_TUNE_EQ_UPDATE_STEPSIZE;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}

int
realtek_i_dvbc_GetSignalSSI(
	DVBC_DEMOD_MODULE *pDemod,
	int rf_level,
	unsigned char *ssi
)
{
	unsigned int constellation;
	unsigned int SymbolRateHz;
	long prec;
	long prel;
	long pref;
	long tempSSI = 0;
	long noiseFigureDB1000;

	/* Nordig spec C/N (Es/No) minimum performance
	 	  * Note: 32QAM isn't provided in the Nordig unified specification, so has been
	 	  * Implemented based on interpolation and measurements. */
	long cnrNordigdB1000[] = {20000,  23000,  26000,  29000,  32000}; //16QAM   32QAM   64QAM   128QAM  256QAM

	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	//Modify this to suit the tuner noise figure specification value in dB * 1000
	noiseFigureDB1000 = 9000;

	prec = (rf_level * 1000);
	pDemod->GetMonitorQamSize(pDemod, &constellation);
	pDemod->GetMonitorSymbolRate(pDemod, &SymbolRateHz);

	//REALTEK_I_DVBC_BASE_INFO("[SSI] rf_level=%ld\n",rf_level);

	/*Reference sensitivity limit is calcualted from:
	* RefLevel (dB) = (10 * Log(1.38*10^-23 * 290)) + 30 + NoiseFigure + (10 * Log(symbolRate)) + C/N_Offset
	 	* - realtek_i_dvbc_math_log10(x) = 100 * Log(x)
	 	* - Log(1.38*10^-23 * 290) = -20.3977
	 	*
	  	* Therefore:
	  	* RefLevel (dB * 1000) = -203977 + 30000 + (1000 * NoiseFigure) + (100 * Log(symbolRate)) + (1000 * C/N_Offset)
	*/
	pref = -203977 + 30000 + noiseFigureDB1000 + (100 * realtek_i_dvbc_math_log10(SymbolRateHz / 1000)) + cnrNordigdB1000[constellation];
	prel = prec - pref;

	//REALTEK_I_DVBC_BASE_INFO("[SSI] pref=%ld\n",pref);
	//REALTEK_I_DVBC_BASE_INFO("[SSI] prel=%ld\n",prel);

	/* SSI (Signal Strength Indicator) is calculated from:
	 	*
	 	* if (prel < -15dB)              		SSI = 0
	 	* if (-15dB <= prel < 0dB)       	SSI = (2/3) * (prel + 15)
	 	* if (0dB <= prel < 20dB)        	SSI = 4 * prel + 10
	 	* if (20dB <= prel < 35dB)       	SSI = (2/3) * (prel - 20) + 90
	 	* if (prel >= 35dB)              		SSI = 100
	 	*/
	if (prel < -15000) {
		tempSSI = 0;
	} else if (prel < 0) {
		/* Note : prel and 2/3 scaled by 10^3 so divide by 10^6 added */
		tempSSI = ((2 * (prel + 15000)) + 1500) / 3000;
	} else if (prel < 20000) {
		/* Note : prel scaled by 10^3 so divide by 10^3 added */
		tempSSI = (((4 * prel) + 500) / 1000) + 10;
	} else if (prel < 35000) {
		/* Note : prel and 2/3 scaled by 10^3 so divide by 10^6 added */
		tempSSI = (((2 * (prel - 20000)) + 1500) / 3000) + 90;
	} else {
		tempSSI = 100;
	}

	*ssi = (tempSSI > 100) ? 100 : tempSSI;
	//REALTEK_I_DVBC_BASE_INFO("[SSI] tempSSI=%ld\n", tempSSI);

	return FUNCTION_SUCCESS;
}

int
realtek_i_dvbc_GetSignalSQI(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned char *sqi
)
{
	unsigned int constellation;
	unsigned int Eqout = 0, PakN = 0, BadPakN = 0, ErrBit = 0;
	unsigned long ber = 0;
	unsigned char SQI;
	long snr = 0;
	long snRel = 0;
	long berSQI = 0;
	long tmpSQI = 0;
	int ret;

	/* Nordig spec C/N (Es/No) minimum performance
	 	  * Note: 32QAM isn't provided in the Nordig unified specification, so has been
	 	  * Implemented based on interpolation and measurements. */
	long cnrNordigdB1000[] = {20000,  23000,  26000,  29000,  32000}; //16QAM   32QAM   64QAM   128QAM  256QAM

	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	//ret = pDemod->DemodCtrlUpdateCounters (pDemod);
	ret |= pDemod->GetMonitorQamSize(pDemod, &constellation);
	ret |= pDemod->GetEqOutputSnr(pDemod, &Eqout);
	ret |= pDemod->GetTsPacketNumber(pDemod, &PakN);
	ret |= pDemod->GetBadPacketNumber(pDemod, &BadPakN);
	ret |= pDemod->GetBitErrorNumber(pDemod, &ErrBit);
	ret |= pDemod->DemodCtrlResetCounters(pDemod);

	if (PakN > 0)
		//ber = ((((BadPakN*36)*10000000)+(ErrBit)) /(PakN*204*8));
		//ber = ((ErrBit*10000000) /(PakN*204*8));
		ber = ((ErrBit * 6127) / (PakN));
	else
		ber = 1 * 10000000;

	snr = ((Eqout * 1000) / 256);
	//REALTEK_I_DVBC_BASE_INFO("[SQI] per 10^7=%ld, snr 10^3=%ld\n",per, snr);

	snRel = snr - cnrNordigdB1000[constellation];


	/* BER_SQI is calculated from:
	 	* if (BER > 10^-3)          : 0
	 	* if (10^-7 < BER <= 10^-3) : BER_SQI = 20*log10(1/BER) - 40
	 	* if (BER <= 10^-7)         : BER_SQI = 100
	  	*/
	if (ber > 10000) {
		berSQI = 0;
	} else if (ber > 1) {
		/* BER_SQI = 20 * log10(1/BER) - 40
		* BER_SQI = 20 * (log10(1) - log10(BER)) - 40
		*
		* If BER in units of 1e-7
		* BER_SQI = 20 * (log10(1) - (log10(BER) - log10(1e7)) - 40
		*
		* BER_SQI = 20 * (log10(1e7) - log10(BER)) - 40
		* BER_SQI = 20 * (7 - log10 (BER)) - 40
		*/
		berSQI = 10 * realtek_i_dvbc_math_log10(ber);
		berSQI = 20 * (7 * 1000 - (berSQI)) - 40 * 1000;
	} else {
		berSQI = 100 * 1000;
	}

	/* SQI (Signal Quality Indicator) given by:
	* if (C/Nrel < -7dB)         : SQI = 0
	* if (-7dB <= C/Nrel < +3dB) : SQI = (((C/Nrel - 3) / 10) + 1) * BER_SQI
	* if (C/Nrel >= +3dB)        : SQI = BER_SQI
	*/
	if (snRel < -7 * 1000) {
		SQI = 0;
	} else if (snRel < 3 * 1000) {
		tmpSQI = (((snRel - (3 * 1000)) / 10) + 1000);
		SQI = (((tmpSQI * berSQI) + (1000000 / 2)) / (1000000)) & 0xFF;
	} else {
		SQI = ((berSQI + 500) / 1000);
	}

	*sqi = (SQI > 100) ? 100 : SQI;

	return FUNCTION_SUCCESS;
}


/**

@see   QAM_DEMOD_FP_UPDATE_FUNCTION

*/
int
realtek_i_dvbc_UpdateFunction(
	DVBC_DEMOD_MODULE *pDemod
)
{
#if 0
	REALTEK_I_DVBC_EXTRA_MODULE *pExtra = &(pDemod->Extra.RealtekIDvbc);
	int ret;
	unsigned int DemodStatus;
	static unsigned long stime = 0;

	REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (stime == 0)
		stime = tv_osal_time();

	ret = (pDemod->GetDemodStatus(pDemod, &DemodStatus));

	if (ret == FUNCTION_SUCCESS) {
		if (tv_osal_time() - stime >= 3000) {
			if (DemodStatus != 5) {
				REALTEK_I_DVBC_BASE_INFO("\033[1;32;32m" "Auto Re-Acquire\n" "\033[m");
				ret |= (pDemod->DemodCtrlStop(pDemod));
				ret |= (pDemod->SetTunerBandwidth(pDemod, 8000000));
				ret |= (pDemod->SetTunerFreq(pDemod, 666000000));
				ret |= (pDemod->DemodCtrlDetect(pDemod));
			}
			stime = tv_osal_time();
		}
		return FUNCTION_SUCCESS;
	} else {
		return FUNCTION_ERROR;
	}
#else
	return FUNCTION_SUCCESS;
#endif
}

/**

@ For calculate SSI/SQI

*/
unsigned long
realtek_i_dvbc_math_log2(
	unsigned long x
)
{
	unsigned char count = 0;
	unsigned char index = 0;
	unsigned long xval = x;
	unsigned char Dvbclog2LookUp[] = {
		0, /* 0 */ 		4,    	/* 0.04439 */
		9, /* 0.08746 */ 	13, 	/* 0.12928 */
		17, /* 0.16993 */ 	21, 	/* 0.20945 */
		25, /* 0.24793 */ 	29, 	/* 0.28540 */
		32, /* 0.32193 */ 	36, 	/* 0.35755 */
		39, /* 0.39232 */ 	43, 	/* 0.42627 */
		46, /* 0.45943 */ 	49,  	/* 0.49185 */
		52, /* 0.52356 */ 	55, 	/* 0.55249 */
		58, /* 0.58496 */ 	61, 	/* 0.61471 */
		64, /* 0.64386 */ 	67, 	/* 0.67246 */
		70, /* 0.70044 */ 	73, 	/* 0.72792 */
		75, /* 0.75489 */ 	78, 	/* 0.78136 */
		81, /* 0.80736 */ 	83,	/* 0.83289 */
		86, /* 0.85798 */ 	88,	/* 0.88264 */
		91, /* 0.90689 */ 	93, 	/* 0.93074 */
		95, /* 0.95420 */ 	98 	/* 0.97728 */
	};

	/* Get the MSB position. */
	for (x >>= 1; x > 0; x >>= 1) {
		count++;
	}
	x = count * 100;
	if (count > 0) {
		if (count <= MAX_BIT_PRECISION) {
			/* Mask the bottom bits. */
			index = (unsigned char)(xval << (MAX_BIT_PRECISION - count)) & FRAC_BITMASK;
			x += Dvbclog2LookUp[index];
		} else {
			/* Mask the bits just below the radix. */
			index = (unsigned char)(xval >> (count - MAX_BIT_PRECISION)) & FRAC_BITMASK;
			x += Dvbclog2LookUp[index];
		}
	}
	return (x);
}

/**

@ For calculate SSI/SQI

*/
unsigned long
realtek_i_dvbc_math_log10(
	unsigned long x
)
{
	/* log10(x) = log2 (x) / log2 (10) */
	/* Note uses: logN (x) = logM (x) / logM (N) */
	return ((100 * realtek_i_dvbc_math_log2(x) + LOG2_10_100X / 2) / LOG2_10_100X);
}

