//#include <stdio.h>
#include "dvbs_demod_rtk.h"
#include "dvbs_registers.h"
#include "spec_an_registers.h"
#include "message_func_rtk.h"
#include "diseqc_rtk.h"
#include <rtk_kdriver/rtk_diseqc.h>


/**

@brief   REALTEK_I DVBS demod module builder

Use BuildRealtekIDvbSModule() to build REALTEK_I DVBS module, set all module function pointers with the corresponding
functions, and initialize module private variables.


@param [in]   ppDemod                        Pointer to REALTEK_I DVBS demod module pointer
@param [in]   pDvbsDemodModuleMemory         Pointer to an allocated DVBS demod module memory
@param [in]   pBaseInterfaceModuleMemory     Pointer to an allocated base interface module memory
@param [in]   pI2cBridgeModuleMemory         Pointer to an allocated I2C bridge module memory
@param [in]   DeviceAddr                     REALTEK_I DVBS I2C device address
@param [in]   CrystalFreqHz                  REALTEK_I DVBS crystal frequency in Hz

@note
	-# One should call BuildRealtekIDvbSModule() to build REALTEK_I DVBS module before using it.

*/
void
BuildRealtekIDvbsModule(
	DVBS_DEMOD_MODULE **ppDemod,
	DVBS_DEMOD_MODULE *pDvbSDemodModuleMemory,
	BASE_INTERFACE_MODULE *pBaseInterfaceModuleMemory,
	I2C_BRIDGE_MODULE *pI2cBridgeModuleMemory,
	unsigned char DeviceAddr,
	unsigned long CrystalFreqHz
)
{
	DVBS_DEMOD_MODULE *pDemod;

	// Set demod module pointer and get demod module.
	*ppDemod = pDvbSDemodModuleMemory;
	pDemod = *ppDemod;

	// Set base interface module pointer and I2C bridge module pointer.
	pDemod->pBaseInterface = pBaseInterfaceModuleMemory;
	pDemod->pI2cBridge     = pI2cBridgeModuleMemory;

	// Set demod type.
	pDemod->DemodType = DVBS_DEMOD_TYPE_REALTEK_I;

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
	pDemod->RegAccess.Addr16Bit.SetRegBytes        = dvbs_demod_addr_16bit_default_SetRegBytes;
	pDemod->RegAccess.Addr16Bit.GetRegBytes        = dvbs_demod_addr_16bit_default_GetRegBytes;
	pDemod->RegAccess.Addr16Bit.GetRegMaskBits     = dvbs_demod_addr_16bit_default_GetRegMaskBits;
	pDemod->RegAccess.Addr16Bit.SetRegBits         = dvbs_demod_addr_16bit_default_SetRegBits;
	pDemod->RegAccess.Addr16Bit.GetRegBits         = dvbs_demod_addr_16bit_default_GetRegBits;
	*/

    pDemod->CheckRpuReady               = realtek_i_dvbs_common_CheckRpuReady;
    pDemod->PingRpu                     = realtek_i_dvbs_common_PingRpu;
    pDemod->ShutDown                    = realtek_i_dvbs_common_ShutDown;
    pDemod->ActivateCore                = realtek_i_dvbs_common_ActivateCore;
    pDemod->DeactivateCore              = realtek_i_dvbs_common_DeactivateCore;
    pDemod->SwitchToBuffer              = realtek_i_dvbs_common_SwitchToBuffer;
    
    pDemod->GetDemodInfo                = realtek_i_dvbs_common_GetDemodInfo;
    pDemod->GetBuildId                  = realtek_i_dvbs_common_GetBuildId;
    
    pDemod->DemodCtrlStop               = realtek_i_dvbs_common_DemodCtrlStopCmd;
    pDemod->DemodCtrlDetect             = realtek_i_dvbs_common_DemodCtrlDetectCmd;
    pDemod->DemodCtrlRun                = realtek_i_dvbs_common_DemodCtrlRunCmd;
    pDemod->DemodCtrlUpdateRssi         = realtek_i_dvbs_common_DemodCtrlUpdateRssiCmd;
    pDemod->DemodCtrlResetCounters      = realtek_i_dvbs_common_DemodCtrlResetCountersCmd;
    pDemod->DemodCtrlUpdateCounters     = realtek_i_dvbs_common_DemodCtrlUpdateCountersCmd;
    pDemod->DemodCtrlSetAgc             = realtek_i_dvbs_common_DemodCtrlSetAgcCmd;
    pDemod->DemodCtrlUpdateAgc          = realtek_i_dvbs_common_DemodCtrlUpdateAgcCmd;
    pDemod->DemodCtrlQueryStatus        = realtek_i_dvbs_common_DemodCtrlQueryStatusCmd;
    
    pDemod->GetDemodStatus              = realtek_i_dvbs_common_GetDemodStatus;
    
    pDemod->SetTunerFreq                = realtek_i_dvbs_common_SetTunerFreqCmd;
    pDemod->SetTunerBandwidth           = realtek_i_dvbs_common_SetTunerBandwidth;
    pDemod->SetTunerGridBase            = realtek_i_dvbs_common_SetTunerGridBase;
    pDemod->SetTunerGridIncr            = realtek_i_dvbs_common_SetTunerGridIncr;
    pDemod->GetActiveTunerFreq          = realtek_i_dvbs_common_GetActiveTunerFreq;
    pDemod->GetActiveTunerBandwidth     = realtek_i_dvbs_common_GetActiveTunerBandwidth;
    pDemod->GetActiveTunerGain          = realtek_i_dvbs_common_GetActiveTunerGain;
    pDemod->GetActiveTunerRssi          = realtek_i_dvbs_common_GetActiveTunerRssi;
    
    pDemod->SetNotchFreq                = realtek_i_dvbs_common_SetNotchFreqCmd;
    pDemod->SetNotchBandwidth           = realtek_i_dvbs_common_SetNotchBandwidth;
    
    pDemod->SetAgcParams                = realtek_i_dvbs_common_SetAgcParams;
    pDemod->GetAgcParams                = realtek_i_dvbs_common_GetAgcParams;
    pDemod->SetTsConfig                 = realtek_i_dvbs_common_SetTsConfig;
    pDemod->SetTsClkRateMargin          = realtek_i_dvbs_common_SetTsClkRateMargin;
    pDemod->SetTsClkRateMax             = realtek_i_dvbs_common_SetTsClkRateMax;
    pDemod->GetDemodLockTime            = realtek_i_dvbs_common_GetDemodLockTime;

    pDemod->SetVirtualRegister          = realtek_i_dvbs_common_SetVirtualRegister;
    pDemod->GetVirtualRegister          = realtek_i_dvbs_common_GetVirtualRegister;
	pDemod->SetCmdVirtualRegister       = realtek_i_dvbs_common_SetCmdVirtualRegister;//Call MsgSetCmdReg
    //pDemod->SetCtrlVirtualRegister      = realtek_i_dvbs_common_SetCtrlVirtualRegister;//removed on S4AP
    //pDemod->GetCtrlVirtualRegister      = realtek_i_dvbs_common_GetCtrlVirtualRegister;//removed on S4AP
    pDemod->SetHwRegValue               = realtek_i_dvbs_common_SetHwRegValue;
    pDemod->GetHwRegValue               = realtek_i_dvbs_common_GetHwRegValue;

    pDemod->SetBaudRate                 = realtek_i_dvbs_SetBaudRate;
    pDemod->GetBaudRate                 = realtek_i_dvbs_GetBaudRate;
    pDemod->SetCodeRate                 = realtek_i_dvbs_SetCodeRate;
    pDemod->GetCodeRate                 = realtek_i_dvbs_GetCodeRate;
    pDemod->GetActiveBaudRate           = realtek_i_dvbs_GetActiveBaudRate;
    pDemod->GetActiveCodeRate           = realtek_i_dvbs_GetActiveCodeRate;
    pDemod->GetBerAtViterbiInput        = realtek_i_dvbs_GetBerAtViterbiInput;
    pDemod->GetBerAtRsInput             = realtek_i_dvbs_GetBerAtRsInput;
    pDemod->GetPerAtOutput              = realtek_i_dvbs_GetPerAtOutput;
    pDemod->SetNumSecBerAvg             = realtek_i_dvbs_SetNumSecBerAvg;
    pDemod->GetNumSecBerAvg             = realtek_i_dvbs_GetNumSecBerAvg;
    pDemod->GetTsPacketCount            = realtek_i_dvbs_GetTsPacketCount;
    pDemod->GetBadPacketCount           = realtek_i_dvbs_GetBadPacketCount;
    pDemod->GetBitRate                  = realtek_i_dvbs_GetBitRate;
    pDemod->GetSnrEstimate              = realtek_i_dvbs_GetSnrEstimate;
    pDemod->SetCarrierFreqSearchRange   = realtek_i_dvbs_SetCarrierFreqSearchRange;
    pDemod->GetCarrierFreqSearchRange   = realtek_i_dvbs_GetCarrierFreqSearchRange;
    pDemod->SetSymbolRateSearchRange    = realtek_i_dvbs_SetSymbolRateSearchRange;
    pDemod->GetSymbolRateSearchRange    = realtek_i_dvbs_GetSymbolRateSearchRange;
    pDemod->GetAcquisitionState         = realtek_i_dvbs_GetAcquisitionState;
    pDemod->SetNumAcquisitions          = realtek_i_dvbs_SetNumAcquisitions;
    pDemod->GetNumAcquisitions          = realtek_i_dvbs_GetNumAcquisitions;
    pDemod->GetAcqFailureCode           = realtek_i_dvbs_GetAcqFailureCode;
    pDemod->SetDemodErrorCode           = realtek_i_dvbs_SetDemodErrorCode;
    pDemod->GetDemodErrorCode           = realtek_i_dvbs_GetDemodErrorCode;
    pDemod->GetIAmp                     = realtek_i_dvbs_GetIAmp;
    pDemod->GetQAmp                     = realtek_i_dvbs_GetQAmp;
    pDemod->GetAnalogGain               = realtek_i_dvbs_GetAnalogGain;
    pDemod->GetDigitalGain              = realtek_i_dvbs_GetDigitalGain;
    pDemod->GetAcquisitionTime          = realtek_i_dvbs_GetAcquisitionTime;
    pDemod->GetCarrierFreqOffset        = realtek_i_dvbs_GetCarrierFreqOffset;
    pDemod->SetDemodPhyCtrl             = realtek_i_dvbs_SetPhyCtrl;
    pDemod->GetDemodPhyCtrl             = realtek_i_dvbs_GetPhyCtrl;
    pDemod->SetManualDfeCoeff           = realtek_i_dvbs_SetManualDfeCoeff;
    pDemod->GetManualDfeCoeff           = realtek_i_dvbs_GetManualDfeCoeff;
    pDemod->SetSpectrumInversion        = realtek_i_dvbs_SetSpectrumInversion;
    pDemod->GetSpectrumInversion        = realtek_i_dvbs_GetSpectrumInversion;
    pDemod->SetActiveSpectrumInversion  = realtek_i_dvbs_SetActiveSpectrumInversion;
    pDemod->GetActiveSpectrumInversion  = realtek_i_dvbs_GetActiveSpectrumInversion;
    pDemod->SetToneDetectCtrl           = realtek_i_dvbs_SetToneDetectCtrl;
    pDemod->GetToneDetectValue          = realtek_i_dvbs_GetToneDetectValue;
    pDemod->SetDfePhaseTrackerState     = realtek_i_dvbs_SetDfePhaseTrackerState;
    pDemod->GetDfePhaseTrackerState     = realtek_i_dvbs_GetDfePhaseTrackerState;
    pDemod->GetPhaseTrackCtrl           = realtek_i_dvbs_GetPhaseTrackCtrl;
    pDemod->SetTunedFreqOffset          = realtek_i_dvbs_SetTunedFreqOffset;
    pDemod->GetTunedFreqOffset          = realtek_i_dvbs_GetTunedFreqOffset;
    pDemod->SetTunerFreqRequest         = realtek_i_dvbs_SetTunerFreqRequest;
    pDemod->GetTunerFreqRequest         = realtek_i_dvbs_GetTunerFreqRequest;
    pDemod->SetTunerBwRequest           = realtek_i_dvbs_SetTunerBwRequest;
    pDemod->GetTunerBwRequest           = realtek_i_dvbs_GetTunerBwRequest;
    pDemod->SetMetaLogDebugPtr          = realtek_i_dvbs_SetMetaLogDebugPtr;
    pDemod->GetMetaLogDebugPtr          = realtek_i_dvbs_GetMetaLogDebugPtr;
    pDemod->SetMetaLogPtr               = realtek_i_dvbs_SetMetaLogPtr;
    pDemod->GetMetaLogPtr               = realtek_i_dvbs_GetMetaLogPtr;
    pDemod->SetMcpLogPtr                = realtek_i_dvbs_SetMcpLogPtr;
    pDemod->GetMcpLogPtr                = realtek_i_dvbs_GetMcpLogPtr;
    pDemod->SetDcpLogPtr                = realtek_i_dvbs_SetDcpLogPtr;
    pDemod->GetDcpLogPtr                = realtek_i_dvbs_GetDcpLogPtr;
    pDemod->GetIfAgcGain                = realtek_i_dvbs_GetIfAgcGain;

    //DiSEqC Control
    pDemod->SetContinue22kOnOff         = realtek_i_Diseqc_SetContinue22kOnOff;
    pDemod->SetDiseqcCmd                = realtek_i_Diseqc_SetDiseqcCmd;
    pDemod->SetUnModToneBurst           = realtek_i_Diseqc_SetUnModToneBurst;
    pDemod->SetModToneBurst             = realtek_i_Diseqc_SetModToneBurst;
    //pDemod->SetContinue22kOnOff	  = RTK_SetContinue22kOnOff;
    //pDemod->SetDiseqcCmd                = RTK_SetDiseqcCmd;
    //pDemod->SetUnModToneBurst           = RTK_SetUnModToneBurst;
    //pDemod->SetModToneBurst             = RTK_SetModToneBurst;

    //Spectrum Analyzer
    pDemod->DvbSSetSpecAnScanRange          = realtek_i_SpecAn_DvbSSetSpecAnScanRange;
    pDemod->DvbSGetSpecAnScanRange          = realtek_i_SpecAn_DvbSGetSpecAnScanRange;
    pDemod->DvbSSetSpecAnScanResolution     = realtek_i_SpecAn_DvbSSetSpecAnScanResolution;
    pDemod->DvbSGetSpecAnScanResolution     = realtek_i_SpecAn_DvbSGetSpecAnScanResolution;
    pDemod->DvbSSetSpecAnTuningStep         = realtek_i_SpecAn_DvbSSetSpecAnTuningStep;
    pDemod->DvbSGetSpecAnTuningStep         = realtek_i_SpecAn_DvbSGetSpecAnTuningStep;
    pDemod->DvbSSetSpecAnMeasureCtrl        = realtek_i_SpecAn_DvbSSetSpecAnMeasureCtrl;
    pDemod->DvbSGetSpecAnMeasureCtrl        = realtek_i_SpecAn_DvbSGetSpecAnMeasureCtrl;
    pDemod->DvbSSetSpecAnAveragePeriod      = realtek_i_SpecAn_DvbSSetSpecAnAveragePeriod;
    pDemod->DvbSGetSpecAnAveragePeriod      = realtek_i_SpecAn_DvbSGetSpecAnAveragePeriod;
    pDemod->DvbSSetSpecAnIfGainOverride     = realtek_i_SpecAn_DvbSSetSpecAnIfGainOverride;
    pDemod->DvbSGetSpecAnIfGainOverride     = realtek_i_SpecAn_DvbSGetSpecAnIfGainOverride;
    pDemod->DvbSSetSpecAnTuner3dBPoint      = realtek_i_SpecAn_DvbSSetSpecAnTuner3dBPoint;
    pDemod->DvbSSetSpecAnTuner6dBPoint      = realtek_i_SpecAn_DvbSSetSpecAnTuner6dBPoint;
    pDemod->DvbSSetSpecAnTuner9dBPoint      = realtek_i_SpecAn_DvbSSetSpecAnTuner9dBPoint;
    pDemod->DvbSSetSpecAnTuner12dBPoint     = realtek_i_SpecAn_DvbSSetSpecAnTuner12dBPoint;
    pDemod->DvbSGetSpecAnOutSpectrumPtr     = realtek_i_SpecAn_DvbSGetSpecAnOutSpectrumPtr;
    pDemod->DvbSGetSpecAnOutSpectrumLen     = realtek_i_SpecAn_DvbSGetSpecAnOutSpectrumLen;
    pDemod->DvbSGetSpecAnMaxRssi            = realtek_i_SpecAn_DvbSGetSpecAnMaxRssi;
    pDemod->DvbSGetSpecAnRefIfGain          = realtek_i_SpecAn_DvbSGetSpecAnRefIfGain;
    pDemod->DvbSGetSpecAnMaxPwr             = realtek_i_SpecAn_DvbSGetSpecAnMaxPwr;
    pDemod->DvbSGetSpecAnFailureCode        = realtek_i_SpecAn_DvbSGetSpecAnFailureCode;
    pDemod->DvbSGetSpecAnCompletionPercent  = realtek_i_SpecAn_DvbSGetSpecAnCompletionPercent;
    
	return;
}


/*
Nominal symbol rate in Baud. When scanning for a signal this value is
taken as the centre of the symbol rate search range. This value must be
written by the controlling application prior to signal acquisition. Valid range
from 1000000 Baud up to 9/16 of the configured ADC clock rate.
Note that after successful signal acquisition the system reports detected
Baud rate in the DVBS_REG_ACTIVE_BAUD_RATE register.
*/
int
realtek_i_dvbs_SetBaudRate(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int BaudRate
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    BaudRate &= DVBS_BITFLD_BAUD_RATE;
    
    if(MsgSetReg(DVBS_REG_BAUD_RATE, 0, BaudRate) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbs_GetBaudRate(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *BaudRate
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS_REG_BAUD_RATE, 0, BaudRate) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *BaudRate &= DVBS_BITFLD_BAUD_RATE;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Nominal code rate:
0: Rate 1/2
1: Rate 2/3
2: Rate 3/4
3: Rate 5/6
4: Rate 7/8
This register may be written by the application prior to signal acquisition.
The system will auto-detect if the wrong code rate is specified, however
setting the correct code rate in this register may slightly speed signal
acquisition.
Note that after successful signal acquisition the system reports detected
code rate in the DVBS_REG_ACTIVE_CODE_RATE register.
*/
int
realtek_i_dvbs_SetCodeRate(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int DemodCodeRate
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    DemodCodeRate &= DVBS_BITFLD_CODE_RATE;
    
    if(MsgSetReg(DVBS_REG_CODE_RATE, 0, DemodCodeRate) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbs_GetCodeRate(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *DemodCodeRate
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS_REG_CODE_RATE, 0, DemodCodeRate) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *DemodCodeRate &= DVBS_BITFLD_CODE_RATE;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Measured symbol rate in Baud. This measurement will be valid while in
the DEMODULATING state.
*/
int
realtek_i_dvbs_GetActiveBaudRate(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *ActiveBaudRate
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS_REG_ACTIVE_BAUD_RATE, 0, ActiveBaudRate) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *ActiveBaudRate &= DVBS_BITFLD_ACTIVE_BAUD_RATE;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Detected code rate:
0: Rate 1/2
1: Rate 2/3
2: Rate 3/4
3: Rate 5/6
4: Rate 7/8
This register contains valid contents while in the DEMODULATING state.
*/
int
realtek_i_dvbs_GetActiveCodeRate(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *ActiveCodeRate
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS_REG_ACTIVE_CODE_RATE, 0, ActiveCodeRate) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *ActiveCodeRate &= DVBS_BITFLD_ACTIVE_CODE_RATE;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Measured bit error rate at the Viterbi decoder input. Unsigned ratio
with 32 fractional bits, saturating at 0xFFFFFFFF.
This measurement is averaged over an interval specified by
DVBS_REG_NUM_SECONDS_BER_AVERAGING. It will be valid
while in the DEMODULATING state, and is updated once per second.
It may be reset using the TV_CMD_RESET_COUNTERS command.
*/
int
realtek_i_dvbs_GetBerAtViterbiInput(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *BerAtViterbiInput
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS_REG_BER_AT_VITERBI_INPUT, 0, BerAtViterbiInput) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *BerAtViterbiInput &= DVBS_BITFLD_BER_AT_VITERBI_INPUT;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Measured bit error rate at the Reed-Solomon decoder input. Unsigned
ratio with 32 fractional bits, saturating at 0xFFFFFFFF.
This measurement is averaged over an interval specified by
DVBS_REG_NUM_SECONDS_BER_AVERAGING. It will be valid while in
the DEMODULATING state, and is updated once per second.
It may be reset using the TV_CMD_RESET_COUNTERS command.
*/
int
realtek_i_dvbs_GetBerAtRsInput(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *BerAtRsInput
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS_REG_BER_AT_RS_INPUT, 0, BerAtRsInput) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *BerAtRsInput &= DVBS_BITFLD_BER_AT_RS_INPUT;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Measured TS packet error rate at the system output. Unsigned ratio with
32 fractional bits, saturating at 0xFFFFFFFF.
This measurement is averaged over an interval specified by
DVBS_REG_NUM_SECONDS_BER_AVERAGING. It will be valid while in
the DEMODULATING state, and is updated once per second.
It may be reset using the TV_CMD_RESET_COUNTERS command.
*/
int
realtek_i_dvbs_GetPerAtOutput(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *PerAtOutput
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS_REG_PER_AT_OUTPUT, 0, PerAtOutput) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *PerAtOutput &= DVBS_BITFLD_PER_AT_OUTPUT;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
The number of seconds over which the bit error rate and
packet error rate measurements will be averaged (range 1
to 30 seconds).
*/
int
realtek_i_dvbs_SetNumSecBerAvg(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int NumSecBerAvg
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    NumSecBerAvg &= DVBS_BITFLD_NUM_SECONDS_BER_AVERAGING;
    
    if(MsgSetReg(DVBS_REG_NUM_SECONDS_BER_AVERAGING, 0, NumSecBerAvg) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbs_GetNumSecBerAvg(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *NumSecBerAvg
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS_REG_NUM_SECONDS_BER_AVERAGING, 0, NumSecBerAvg) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *NumSecBerAvg &= DVBS_BITFLD_NUM_SECONDS_BER_AVERAGING;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Number of transport stream packets output since signal acquisition. This
value will be valid while in the DEMODULATING state, and is updated
once per second. The value will wrap to zero on a 32-bit boundary.
It may be reset using the TV_CMD_RESET_COUNTERS command.
*/
int
realtek_i_dvbs_GetTsPacketCount(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *TsPacketCount
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS_REG_TS_PACKET_COUNT, 0, TsPacketCount) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *TsPacketCount &= DVBS_BITFLD_TS_PACKET_COUNT;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Number of errored transport stream packets output since signal
acquisition. This value will be valid while in the DEMODULATING state,
and is updated once per second. The value will wrap to zero on a 32-bit
boundary.
It may be reset using the TV_CMD_RESET_COUNTERS command.
*/
int
realtek_i_dvbs_GetBadPacketCount(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *BadPacketCount
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS_REG_BAD_PACKET_COUNT, 0, BadPacketCount) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *BadPacketCount &= DVBS_BITFLD_BAD_PACKET_COUNT;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Measured output bit rate in bits per second, including the TS packet
overhead.
This measurement is averaged over an interval specified by
DVBS_REG_NUM_SECONDS_BER_AVERAGING. It will be valid while in
the DEMODULATING state, and is updated once per second.
*/
int
realtek_i_dvbs_GetBitRate(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *BitRate
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS_REG_BIT_RATE, 0, BitRate) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *BitRate &= DVBS_BITFLD_BIT_RATE;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Measured signal to noise ratio at the equalizer output. This is a signed
value in dB, with 16 fractional bits. The value is measured using the
distance of symbol values from the ideal constellation points; so in high
noise conditions where slicing errors occur, the value will tend to underread.
*/
int
realtek_i_dvbs_GetSnrEstimate(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *SnrEstimate
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS_REG_SNR_ESTIMATE, 0, SnrEstimate) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *SnrEstimate &= DVBS_BITFLD_SNR_ESTIMATE;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Range of carrier frequency to search in each direction around the
nominal carrier frequency (as specified by
TV_REG_TUNER_FREQ), when the DETECT command is
issued. Value in Hz.
*/
int
realtek_i_dvbs_SetCarrierFreqSearchRange(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int CarrierFreqSearchRange
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    CarrierFreqSearchRange &= DVBS_BITFLD_CARRIER_FREQ_SEARCH_RANGE;
    
    if(MsgSetReg(DVBS_CARRIER_FREQ_SEARCH_RANGE, 0, CarrierFreqSearchRange) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbs_GetCarrierFreqSearchRange(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *CarrierFreqSearchRange
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS_CARRIER_FREQ_SEARCH_RANGE, 0, CarrierFreqSearchRange) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *CarrierFreqSearchRange &= DVBS_BITFLD_CARRIER_FREQ_SEARCH_RANGE;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Range of symbol rate to search in each direction around the
nominal symbol rate (as specified by DVBS_REG_BAUD_RATE),
when the DETECT command is issued. Value in Baud.
*/
int
realtek_i_dvbs_SetSymbolRateSearchRange(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int SymbolRateSearchRange
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    SymbolRateSearchRange &= DVBS_BITFLD_SYMBOL_RATE_SEARCH_RANGE;
    
    if(MsgSetReg(DVBS_SYMBOL_RATE_SEARCH_RANGE, 0, SymbolRateSearchRange) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbs_GetSymbolRateSearchRange(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *SymbolRateSearchRange
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS_SYMBOL_RATE_SEARCH_RANGE, 0, SymbolRateSearchRange) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *SymbolRateSearchRange &= DVBS_BITFLD_SYMBOL_RATE_SEARCH_RANGE;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Signal acquisition state:
0: Reset
1: Idle
2: Wait on tune event
3: Analog gain/offset acquisition
4: Symbol timing frequency acquisition
5: Interferer detection
6: Symbol timing phase tracking
7: Equaliser coefficient adaption phase 1
8: Carrier frequency acquisition
9: Carrier phase tracking
10: Equaliser coefficient adaption phase 2
11: Equaliser coefficient adaption phase 3 (strong echo only)
12: Reserved
13: Code rate / puncturing phase / carrier phase detection
14: Reserved
15: Reserved
16: Reserved
17: Phase tracking
18: Demodulating
*/
int
realtek_i_dvbs_GetAcquisitionState(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *AcquisitionState
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS_REG_ACQUISITION_STATE, 0, AcquisitionState) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *AcquisitionState &= DVBS_BITFLD_ACQUISITION_STATE;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Number of signal acquisition attempts since core activation (read/write).
Zero may be written to this register by the controlling application to zero
the count.
*/
int
realtek_i_dvbs_SetNumAcquisitions(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int NumAcquisitions
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    NumAcquisitions &= DVBS_BITFLD_NUM_ACQUISITIONS;
    
    if(MsgSetReg(DVBS_REG_NUM_ACQUISITIONS, 0, NumAcquisitions) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbs_GetNumAcquisitions(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *NumAcquisitions
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS_REG_NUM_ACQUISITIONS, 0, NumAcquisitions) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *NumAcquisitions &= DVBS_BITFLD_NUM_ACQUISITIONS;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Code indicating the reason for the most recent signal acquisition
failure as follows:
0: No acquisition failure reported
1: Insufficient signal power detected
2: Failed to attain symbol lock
3: Failed to identify a carrier
4: Carrier frequency offset out of range
5: Failed to obtain transport stream synchronisation
6: Demodulation failed, too high a packet error rate
*/
int
realtek_i_dvbs_GetAcqFailureCode(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *AcqFailureCode
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS_REG_ACQUISITION_FAILURE_CODE, 0, AcqFailureCode) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *AcqFailureCode &= DVBS_BITFLD_ACQUISITION_FAILURE_CODE;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Error Flags Indicate
*/
int
realtek_i_dvbs_SetDemodErrorCode(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int DemodErrorCode
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
/*
    DemodErrorCode &= (DVBS_BITFLD_TUNING_TIMEOUT | DVBS_BITFLD_TIMER_CONFIG_ERROR | DVBS_BITFLDLOOP_PROC_UNDERRUN_ERROR | 
                        DVBS_BITFLD_SCP_IP_SYNCHRONISER_OFLOW_ERROR | SCP_TBUS_OFLOW_ERROR | BAUD_RATE_RANGE_ERROR);
    
    if(MsgSetReg(DVBS_REG_ERROR_CODE, 0, DemodErrorCode) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
*/
    return FUNCTION_ERROR;
}


int
realtek_i_dvbs_GetDemodErrorCode(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *DemodErrorCode
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
/*
    if(MsgGetReg(DVBS_REG_ERROR_CODE, 0, DemodErrorCode) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *DemodErrorCode &= (DVBS_BITFLD_TUNING_TIMEOUT | DVBS_BITFLD_TIMER_CONFIG_ERROR | DVBS_BITFLDLOOP_PROC_UNDERRUN_ERROR | 
                        DVBS_BITFLD_SCP_IP_SYNCHRONISER_OFLOW_ERROR | SCP_TBUS_OFLOW_ERROR | BAUD_RATE_RANGE_ERROR);

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
*/
    return FUNCTION_ERROR;
}


/*
Average peak-to-peak symbol amplitude on the I channel, measured at the
ADC output. Unsigned value. This value is inferred back from the level
measured at the equaliser output, taking into account the digital gains
applied. Note that peak signal excursions will exceed this value. On a
clean signal this value will normally be set by the analog AGC such that the
peak-to-peak symbol amplitude occupies just over half of the ADC range of
0-4095. As noise is added this level will be reduced to avoid clipping.
This value will be valid while in the DEMODULATING state.
*/
int
realtek_i_dvbs_GetIAmp(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *IAmp
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS_REG_I_AMP, 0, IAmp) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *IAmp &= DVBS_BITFLD_I_AMP;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Average peak-to-peak symbol amplitude on the Q channel, measured at
the ADC output. Unsigned value. This value is inferred back from the level
measured at the equaliser output, taking into account the digital gains
applied. Note that peak signal excursions will exceed this value. On a
clean signal this value will normally be set by the analog AGC such that the
peak-to-peak symbol amplitude occupies just over half of the ADC range of
0-4095. As noise is added this level will be reduced to avoid clipping.
This value will be valid while in the DEMODULATING state.
*/
int
realtek_i_dvbs_GetQAmp(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *QAmp
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS_REG_Q_AMP, 0, QAmp) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *QAmp &= DVBS_BITFLD_Q_AMP;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Analog gain setting: an unsigned integer. The interpretation of this number
will depend on the tuner driver. Typically the MSBs will be used to drive a
DAC producing a control voltage which sets tuner gain.
*/
int
realtek_i_dvbs_GetAnalogGain(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *AnalogGain
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS_REG_ANALOG_GAIN, 0, AnalogGain) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *AnalogGain &= DVBS_BITFLD_ANALOG_GAIN;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Digital gain setting for the I channel. Unsigned value with 31~16 fractional bits.
Digital gain setting for the Q channel. Unsigned value with 15~0  fractional bits.
*/
int
realtek_i_dvbs_GetDigitalGain(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *DigitalGain
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS_REG_DIGITAL_GAIN, 0, DigitalGain) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *DigitalGain &= (DVBS_BITFLD_DIGITAL_GAIN_I | DVBS_BITFLD_DIGITAL_GAIN_Q);

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Acquisition time for the most recent acquisition, measured in ms.
*/
int
realtek_i_dvbs_GetAcquisitionTime(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *AcquisitionTime
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS_REG_ACQUISITION_TIME, 0, AcquisitionTime) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *AcquisitionTime &= DVBS_BITFLD_ACQUISITION_TIME;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Measured carrier frequency offset in Hz. This is the measured
difference between the tune frequency in TV_REG_TUNER_FREQ
and the carrier frequency at the system input.
*/
int
realtek_i_dvbs_GetCarrierFreqOffset(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *CarrierFreqOffset
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS_REG_CARRIER_FREQ_OFFSET, 0, CarrierFreqOffset) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *CarrierFreqOffset &= DVBS_BITFLD_CARRIER_FREQ_OFFSET;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
PHY Control Indicate
*/
int
realtek_i_dvbs_SetPhyCtrl(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int DemodPhyCtrl
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    DemodPhyCtrl &= (DVBS_BITFLD_RESET_METRICS_ON_REACQUISITION | DVBS_BITFLD_DFE_COEFFS_CONTROL_MODE);
    
    if(MsgSetReg(DVBS_REG_CTRL, 0, DemodPhyCtrl) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbs_GetPhyCtrl(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *DemodPhyCtrl
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS_REG_CTRL, 0, DemodPhyCtrl) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *DemodPhyCtrl &= (DVBS_BITFLD_RESET_METRICS_ON_REACQUISITION | DVBS_BITFLD_DFE_COEFFS_CONTROL_MODE);

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
The Decision Feedback Equaliser (DFE) is a hardware component within the UCCP which is used for
equalisation of channel response (particularly echo). This set of 16 registers allows the user either to
read coefficients from the DFE, after they have been adapted by the software (with
DVBS_REG_DFE_COEFFS_CONTROL_MODE=0, i.e. adaptive mode); or to write DFE coefficients
for use with DVBS_REG_DFE_COEFFS_CONTROL_MODE=1 (manual mode).

DFE coefficient n, real part (signed 16-bit value)
DFE coefficient n, imaginary part (signed 16-bit value)
*/
int
realtek_i_dvbs_SetManualDfeCoeff(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int ManualDfeCoeff
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    ManualDfeCoeff &= (DVBS_BITFLD_DFE_COEFF_REAL_n | DVBS_BITFLD_DFE_COEFF_IMAG_n);
    
    if(MsgSetReg(DVBS_REG_MANUAL_DFE_COEFFS00, 0, ManualDfeCoeff) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbs_GetManualDfeCoeff(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *ManualDfeCoeff
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS_REG_MANUAL_DFE_COEFFS00, 0, ManualDfeCoeff) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *ManualDfeCoeff &= (DVBS_BITFLD_DFE_COEFF_REAL_n | DVBS_BITFLD_DFE_COEFF_IMAG_n);

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
0: Spectrum is inverted (I and Q swapped at transmitter)
1: Spectrum is not inverted
This register may be written by the application prior to signal
acquisition. The system will auto-detect if the wrong value is
specified, however setting the correct value in this register may
slightly speed signal acquisition.
Note that after successful signal acquisition the system reports the
detected value for this setting in the
DVBS_REG_ACTIVE_SPECTRUM_INVERSION register.
*/
int
realtek_i_dvbs_SetSpectrumInversion(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int SpectrumInversion
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    SpectrumInversion &= DVBS_BITFLD_SPECTRUM_INVERSION;
    
    if(MsgSetReg(DVBS_REG_SPECTRUM_INVERSION, 0, SpectrumInversion) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbs_GetSpectrumInversion(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *SpectrumInversion
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS_REG_SPECTRUM_INVERSION, 0, SpectrumInversion) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *SpectrumInversion &= DVBS_BITFLD_SPECTRUM_INVERSION;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
0: Spectrum is inverted (I and Q swapped at transmitter)
1: Spectrum is not inverted
This register contains valid contents while in the
DEMODULATING state.
*/
int
realtek_i_dvbs_SetActiveSpectrumInversion(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int ActiveSpectrumInversion
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    ActiveSpectrumInversion &= DVBS_BITFLD_ACTIVE_SPECTRUM_INVERSION;
    
    if(MsgSetReg(DVBS_REG_ACTIVE_SPECTRUM_INVERSION, 0, ActiveSpectrumInversion) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}

int
realtek_i_dvbs_GetActiveSpectrumInversion(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *ActiveSpectrumInversion
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS_REG_ACTIVE_SPECTRUM_INVERSION, 0, ActiveSpectrumInversion) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *ActiveSpectrumInversion &= DVBS_BITFLD_ACTIVE_SPECTRUM_INVERSION;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Set Tone detection control
*/
int
realtek_i_dvbs_SetToneDetectCtrl(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int ToneDetectCtrl
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    ToneDetectCtrl &= (DVBS_BITFLD_TONE_DETECT_ENABLE | DVBS_BITFLD_TONE_DETECT_ENABLE_PSD | 
                        DVBS_BITFLD_TONE_DETECT_PERIOD | DVBS_BITFLD_TONE_DETECT_THRESHOLD);
    
    if(MsgSetReg(DVBS_REG_TONE_DETECT_CTRL, 0, ToneDetectCtrl) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


/*
Get Tone detection values
*/
int
realtek_i_dvbs_GetToneDetectValue(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *ToneDetectValue
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS_REG_TONE_DETECT_VALUE, 0, ToneDetectValue) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *ToneDetectValue &= (DVBS_BITFLD_TONE_DETECT_CTRL_CHANGE | DVBS_BITFLD_TONE_DETECT_PEAK_IDX | 
                          DVBS_BITFLD_TONE_DETECT_PEAK_RATIO);

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Set and get DFE Phase tracker state 
*/
int
realtek_i_dvbs_SetDfePhaseTrackerState(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int DfePhaseTrackerState
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    DfePhaseTrackerState &= (DVBS_BITFLD_DFE_PHASE_TRACKING_MODE | DVBS_BITFLD_DFE_PHASE_TRACKER_GAIN_CONTROL | 
                                DVBS_BITFLD_DFE_PHASE_TRACKER_MEAN_SQUARED_PHASE_ERROR);
    
    if(MsgSetReg(DVBS_REG_PHASE_TRACK_STATE, 0, DfePhaseTrackerState) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbs_GetDfePhaseTrackerState(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *DfePhaseTrackerState
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS_REG_PHASE_TRACK_STATE, 0, DfePhaseTrackerState) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *DfePhaseTrackerState &= (DVBS_BITFLD_DFE_PHASE_TRACKING_MODE | DVBS_BITFLD_DFE_PHASE_TRACKER_GAIN_CONTROL | 
       DVBS_BITFLD_DFE_PHASE_TRACKER_MEAN_SQUARED_PHASE_ERROR);
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Get DFE Phase tracker override control
*/
int
realtek_i_dvbs_GetPhaseTrackCtrl(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *PhaseTrackCtrl
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS_REG_PHASE_TRACK_CTRL_QPSK, 0, PhaseTrackCtrl) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *PhaseTrackCtrl &= (DVBS_BITFLD_PHASE_TRACK_GAIN_ENABLE | DVBS_BITFLD_PHASE_TRACK_CLIP_LEVEL_ENABLE | 
        DVBS_BITFLD_PHASE_TRACK_CORE_LEVEL | DVBS_BITFLD_PHASE_TRACK_CLIP_LEVEL | 
        DVBS_BITFLD_PHASE_TRACK_GAIN_NEG_SHIFT);

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Offset (in Hz) between tuned frequency and wanted carrier
frequency. This register may be written by the application
prior to signal acquisition. This offset is normally left at zero,
but can be used to avoid locating the carrier at DC when
operating at low symbol rate. A positive offset indicates that
the tuned frequency is higher than the carrier frequency. 
*/
int
realtek_i_dvbs_SetTunedFreqOffset(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int TunedFreqOffset
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    TunedFreqOffset &= DVBS_BITFLD_TUNED_FREQ_OFFSET;
    
    if(MsgSetReg(DVBS_REG_TUNED_FREQ_OFFSET, 0, TunedFreqOffset) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbs_GetTunedFreqOffset(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *TunedFreqOffset
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS_REG_TUNED_FREQ_OFFSET, 0, TunedFreqOffset) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *TunedFreqOffset &= DVBS_BITFLD_TUNED_FREQ_OFFSET;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Set tuner frequency, in Hertz, when using an external tuner.
Overrides the TV_REG_TUNER_FREQ and TV_REG_TUNER_BW
when non-zero.
*/
int
realtek_i_dvbs_SetTunerFreqRequest(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int TunerFreqRequest
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    TunerFreqRequest &= DVBS_BITFLD_TUNE_REQUEST;
    
    if(MsgSetReg(DVBS_REG_TUNE_REQUEST, 0, TunerFreqRequest) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbs_GetTunerFreqRequest(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *TunerFreqRequest
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS_REG_TUNE_REQUEST, 0, TunerFreqRequest) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *TunerFreqRequest &= DVBS_BITFLD_TUNE_REQUEST;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Set tuner bandwidth, in Hertz, when using an external tuner. Overrides the
TV_REG_TUNER_FREQ and TV_REG_TUNER_BW when non-zero.
*/
int
realtek_i_dvbs_SetTunerBwRequest(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int TunerBwRequest
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    TunerBwRequest &= DVBS_BITFLD_BW_REQUEST;
    
    if(MsgSetReg(DVBS_REG_BW_REQUEST, 0, TunerBwRequest) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbs_GetTunerBwRequest(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *TunerBwRequest
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS_REG_BW_REQUEST, 0, TunerBwRequest) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *TunerBwRequest &= DVBS_BITFLD_BW_REQUEST;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Context structure pointer, for IMG debugging purposes only.
*/
int
realtek_i_dvbs_SetMetaLogDebugPtr(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int MetaLogDebugPtr
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    MetaLogDebugPtr &= DVBS_BITFLD_DEBUG_PTR;
    
    if(MsgSetReg(DVBS_REG_DEBUG_PTR, 0, MetaLogDebugPtr) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbs_GetMetaLogDebugPtr(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *MetaLogDebugPtr
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS_REG_DEBUG_PTR, 0, MetaLogDebugPtr) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *MetaLogDebugPtr &= DVBS_BITFLD_DEBUG_PTR;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Meta logging pointer, for IMG debugging purposes only.
*/
int
realtek_i_dvbs_SetMetaLogPtr(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int MetaLogPtr
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    MetaLogPtr &= DVBS_BITFLD_META_LOG_PTR;
    
    if(MsgSetReg(DVBS_REG_META_LOG_PTR, 0, MetaLogPtr) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbs_GetMetaLogPtr(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *MetaLogPtr
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS_REG_META_LOG_PTR, 0, MetaLogPtr) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *MetaLogPtr &= DVBS_BITFLD_META_LOG_PTR;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
MCP logging pointer, for IMG debugging purposes only.
*/
int
realtek_i_dvbs_SetMcpLogPtr(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int McpLogPtr
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    McpLogPtr &= DVBS_BITFLD_MCP_LOG_PTR;
    
    if(MsgSetReg(DVBS_REG_MCP_LOG_PTR, 0, McpLogPtr) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbs_GetMcpLogPtr(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *McpLogPtr
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS_REG_MCP_LOG_PTR, 0, McpLogPtr) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *McpLogPtr &= DVBS_BITFLD_MCP_LOG_PTR;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
DCP trace buffer pointer, for IMG debugging purposes only.
*/
int
realtek_i_dvbs_SetDcpLogPtr(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int DcpLogPtr
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    DcpLogPtr &= DVBS_BITFLD_TRACE_BUFF_PTR;
    
    if(MsgSetReg(DVBS_REG_TRACE_BUFF_PTR, 0, DcpLogPtr) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbs_GetDcpLogPtr(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *DcpLogPtr
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS_REG_TRACE_BUFF_PTR, 0, DcpLogPtr) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *DcpLogPtr &= DVBS_BITFLD_TRACE_BUFF_PTR;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbs_GetIfAgcGain(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *IfAgcGain
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

    if(GetHwRegValue(0x02041090, IfAgcGain) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    return FUNCTION_SUCCESS;

error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Frequency range between start and end points of the scan, in Hz.
*/
int
realtek_i_SpecAn_DvbSSetSpecAnScanRange(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int ScanRange
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    ScanRange &= SA_BITFLD_SCAN_RANGE;
    
    if(MsgSetReg(SA_SCAN_RANGE, 0, ScanRange) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_SpecAn_DvbSGetSpecAnScanRange(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *ScanRange
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(SA_SCAN_RANGE, 0, ScanRange) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;
	
	*ScanRange &= SA_BITFLD_SCAN_RANGE;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Frequency interval between spectral measurements, in Hz. This
will be rounded to fit SA_TUNER_GRID_INCR and give a whole
number of readings per tuning step. The rounded value can be
read after beginning a scan.
*/
int
realtek_i_SpecAn_DvbSSetSpecAnScanResolution(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int ScanResolution
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    ScanResolution &= SA_BITFLD_SCAN_RESOLUTION;
    
    if(MsgSetReg(SA_SCAN_RESOLUTION, 0, ScanResolution) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_SpecAn_DvbSGetSpecAnScanResolution(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *ScanResolution
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(SA_SCAN_RESOLUTION, 0, ScanResolution) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;
	
	*ScanResolution &= SA_BITFLD_SCAN_RESOLUTION;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
1: Spectrum analyser will autonomously choose appropriate
tuning positions according to the tuner bandwidth and scan
range settings 0: Spectrum analyser will tune with a spacing
set by SA_TUNING_STEP. This may be desirable for example
if the tuning positions are required to be located according to
defined TV channel allocations.

Increment between tuning positions, in Hz, used when
SA_TUNING_STEP_AUTO = 0. Note that this value must be
less than 90% of the tuner bandwidth setting in
SA_TUNER_BW and will be rounded to the nearest
SA_TUNER_GRID_INCR setting.
*/
int
realtek_i_SpecAn_DvbSSetSpecAnTuningStep(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int TuningStepAuto,
	unsigned int TuningStep
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    unsigned int RegVal = 0;

    RegVal |= (((TuningStepAuto << 30) & SA_BITFLD_TUNING_STEP_AUTO));
    RegVal |= (TuningStep & SA_BITFLD_TUNING_STEP);
	
    if(MsgSetReg(SA_TUNING_STEP, 0, RegVal) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_SpecAn_DvbSGetSpecAnTuningStep(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *TuningStepAuto,
	unsigned int *TuningStep
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    unsigned int RegVal = 0;
    
    if(MsgGetReg(SA_TUNING_STEP, 0, &RegVal) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *TuningStepAuto = (RegVal & SA_BITFLD_TUNING_STEP_AUTO) >> 30;
    *TuningStep = (RegVal & SA_BITFLD_TUNING_STEP);

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Setting this bit to 1 enables a system for correcting for
measurement error at DC. This is useful in the case of a zero-
IF tuner, where the signal level at DC may be corrupted by
residual DC in the analogue circuits prior to the ADCs.

The window function applied to each analysis block before the
Fast Fourier Transform is performed. The following options are
available:0: Rectangular 1: Hamming 2: Hanning Others:
reserved

The type of signal expected at the Spectrum Analyser input.
This field is used to control the scaling of the signal through the
measurement calculations. If the signal type is unknown then
this field should be set to indicate NOISE. The following options
are available: 0: NOISE 1: SINEWAVE Others: reserved

Defines a maximum width for detection of spectral peaks
reported in the SA_MAX_POWER_REG_N registers. When a
peak value is found, other peaks will be ignored in a region of
frequencies around that peak. This region size is given by +/-
(SA_MAX_PEAK_WIDTH * SA_SCAN_RESOLUTION). Note
this register setting does not affect the scan results obtained
from SA_REG_OUT_SPECTRUM_PTR.
*/
int
realtek_i_SpecAn_DvbSSetSpecAnMeasureCtrl(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int EnDcComp,
	unsigned int Window,
	unsigned int SignalType,
	unsigned int MaxPickWidth
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    unsigned int RegVal = 0;

    RegVal |= (((EnDcComp << 9) & SA_BITFLD_ENABLE_DC_COMP));
    RegVal |= (((Window << 6) & SA_BITFLD_WINDOW));
    RegVal |= (((SignalType << 3) & SA_BITFLD_SIGNAL_TYPE));
    RegVal |= (MaxPickWidth & SA_BITFLD_MAX_PEAK_WIDTH);
	
    if(MsgSetReg(SA_MEASUREMENT_CONTROL, 0, RegVal) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_SpecAn_DvbSGetSpecAnMeasureCtrl(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *EnDcComp,
	unsigned int *Window,
	unsigned int *SignalType,
	unsigned int *MaxPickWidth
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    unsigned int RegVal = 0;
    
    if(MsgGetReg(SA_MEASUREMENT_CONTROL, 0, &RegVal) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *EnDcComp = (RegVal & SA_BITFLD_ENABLE_DC_COMP) >> 9;
    *Window = (RegVal & SA_BITFLD_WINDOW) >> 6;
    *SignalType = (RegVal & SA_BITFLD_SIGNAL_TYPE) >> 3;
    *MaxPickWidth = (RegVal & SA_BITFLD_MAX_PEAK_WIDTH);

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
SA_AVERAGING_PERIOD_M is an integer and
SA_AVERAGING_PERIOD_N is an enumerated type, such
that the total number of blocks averaged for each spectral
measurement is given by SA_AVERAGING_PERIOD_M *
(2^(SA_AVERAGING_PERIOD_N+1). A larger number of
blocks averaged gives more noise immunity but extends the
time taken for the scan.

Same description as the one for the previous symbol
applies here.
*/
int
realtek_i_SpecAn_DvbSSetSpecAnAveragePeriod(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int AveragePeriodM,
	unsigned int AveragePeriodN
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    unsigned int RegVal = 0;

    RegVal |= (((AveragePeriodM << 8) & SA_BITFLD_AVERAGING_PERIOD_M));
    RegVal |= (AveragePeriodN & SA_BITFLD_AVERAGING_PERIOD_N);
	
    if(MsgSetReg(SA_AVERAGING_PERIOD, 0, RegVal) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_SpecAn_DvbSGetSpecAnAveragePeriod(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *AveragePeriodM,
	unsigned int *AveragePeriodN
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    unsigned int RegVal = 0;
    
    if(MsgGetReg(SA_AVERAGING_PERIOD, 0, &RegVal) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *AveragePeriodM = (RegVal & SA_BITFLD_AVERAGING_PERIOD_M) >> 8;
    *AveragePeriodN = (RegVal & SA_BITFLD_AVERAGING_PERIOD_N);

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
SA_OVERRIDE_IF_GAIN=1 causes the Spectrum Analyser
application to use the value of IF gain specified in the field
SA_IF_GAIN. This feature can be used to ensure that the
power spectral density measured at one tuner centre
frequency can be compared directly with the power spectral
density measured at a different tuner centre frequency.
SA_OVERRIDE_IF_GAIN=0 causes the Spectrum Analyser
application to use the value of IF gain calculated by the AGC
system.

IF gain value for use when SA_OVERRIDE_IF_GAIN=1. This
gain value is restricted to positive values in the range in the
range 0..65535, corresponding to the minimum and maximum
gains, respectively, that the tuner can apply. The gain value is
directly proportional to the logarithm of the expected gain to be
applied to the incoming signal. I.e., the value is proportional to
the gain in dB; however the translation to an absolute gain
value is tuner- dependent. Note that a suitable setting can be
obtained by reading SA_MIN_IF_GAIN after a scan has been
performed.
*/
int
realtek_i_SpecAn_DvbSSetSpecAnIfGainOverride(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int OverrideIfGain,
	unsigned int IfGain
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    unsigned int RegVal = 0;

    RegVal |= (((OverrideIfGain << 16) & SA_BITFLD_OVERRIDE_IF_GAIN));
    RegVal |= (IfGain & SA_BITFLD_IF_GAIN);
	
    if(MsgSetReg(SA_IF_GAIN_OVERRIDE, 0, RegVal) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_SpecAn_DvbSGetSpecAnIfGainOverride(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *OverrideIfGain,
	unsigned int *IfGain
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    unsigned int RegVal = 0;
    
    if(MsgGetReg(SA_IF_GAIN_OVERRIDE, 0, &RegVal) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *OverrideIfGain = (RegVal & SA_BITFLD_OVERRIDE_IF_GAIN) >> 16;
    *IfGain = (RegVal & SA_BITFLD_IF_GAIN);

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Frequency spacing between the centre of the passband of the
tuner?™s channel filter and the 3dB attenuation frequency for that
filter, in Hz
*/
int
realtek_i_SpecAn_DvbSSetSpecAnTuner3dBPoint(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int FreqSpacing
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    FreqSpacing &= SA_BITFLD_TUNER_3DB_POINT;
    
    if(MsgSetReg(SA_TUNER_3DB_POINT, 0, FreqSpacing) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


/*
Frequency spacing between the centre of the passband of the
tuner?™s channel filter and the 6dB attenuation frequency for that
filter, in Hz
*/
int
realtek_i_SpecAn_DvbSSetSpecAnTuner6dBPoint(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int FreqSpacing
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    FreqSpacing &= SA_BITFLD_TUNER_6DB_POINT;
    
    if(MsgSetReg(SA_TUNER_6DB_POINT, 0, FreqSpacing) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


/*
Frequency spacing between the centre of the passband of the
tuner?™s channel filter and the 9dB attenuation frequency for that
filter, in Hz
*/
int
realtek_i_SpecAn_DvbSSetSpecAnTuner9dBPoint(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int FreqSpacing
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    FreqSpacing &= SA_BITFLD_TUNER_9DB_POINT;
    
    if(MsgSetReg(SA_TUNER_9DB_POINT, 0, FreqSpacing) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


/*
Frequency spacing between the centre of the passband of the
tuner?™s channel filter and the 12dB attenuation frequency for that
filter, in Hz
*/
int
realtek_i_SpecAn_DvbSSetSpecAnTuner12dBPoint(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int FreqSpacing
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    FreqSpacing &= SA_BITFLD_TUNER_12DB_POINT;
    
    if(MsgSetReg(SA_TUNER_12DB_POINT, 0, FreqSpacing) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


/*
Memory region within which the output spectrum may
be located:
0: Global RAM
1: External RAM
2: Reserved
3: Reserved

Pointer to the start of the spectrum output, expressed
as an offset in words from the start of the region
specified by SA_OUT_SPECTRUM_MEM_TYPE.
(Words are 24-bit for global RAM, 32-bit for other
memory types)
*/
int
realtek_i_SpecAn_DvbSGetSpecAnOutSpectrumPtr(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *OutSpecMemType,
	unsigned int *SpecMemPtr
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    unsigned int RegVal = 0;
    
    if(MsgGetReg(SA_REG_OUT_SPECTRUM_PTR, 0, &RegVal) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *OutSpecMemType = (RegVal & SA_BITFLD_OUT_SPECTRUM_MEM_TYPE) >> 30;
    *SpecMemPtr = (RegVal & SA_BITFLD_OUT_SPECTRUM_PTR);

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Length of the output spectrum.
*/
int
realtek_i_SpecAn_DvbSGetSpecAnOutSpectrumLen(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *OutSpecLen
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

    if(MsgGetReg(SA_OUT_SPECTRUM_LEN, 0, OutSpecLen) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;
	
	*OutSpecLen &= SA_BITFLD_OUT_SPECTRUM_LEN;

    return FUNCTION_SUCCESS;

error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Maximum RSSI value recorded from the tuner. This value will
only be valid if the tuner provides an RSSI output. This is a
signed 16-bit integer indicating an approximate signal strength
value in dBm.

Frequency index at the centre of the tuning position where the
maximum RSSI value was recorded. This is an index into the
output vector obtained from SA_OUT_SPECTRUM_PTR. A value
of 0xFFFF indicates that the RSSI feature is unsupported.
*/
int
realtek_i_SpecAn_DvbSGetSpecAnMaxRssi(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *MaxRssi,
	unsigned int *MaxRssiIdx
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    unsigned int RegVal = 0;
    
    if(MsgGetReg(SA_MAX_RSSI_REG, 0, &RegVal) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *MaxRssi = (RegVal & SA_BITFLD_MAX_RSSI) >> 16;
    *MaxRssiIdx = (RegVal & SA_BITFLD_MAX_RSSI_INDEX);

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Reference analogue gain used by the IF AGC sub-system during
the scan. This may be used as an indication of received signal
power. This gain value is restricted to positive values in the
range in the range 0..65535, corresponding to the minimum and
maximum gains, respectively, that the tuner can apply. The gain
value is directly proportional to the logarithm of the expected
gain to be applied to the incoming signal. I.e., the value is
proportional to the gain in dB; however the translation to an
absolute gain value is tuner-dependent.
*/
int
realtek_i_SpecAn_DvbSGetSpecAnRefIfGain(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *RefIfGain
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

    if(MsgGetReg(SA_REF_IF_GAIN_REG, 0, RefIfGain) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;
	
	*RefIfGain &= SA_BITFLD_REF_IF_GAIN_REG;

    return FUNCTION_SUCCESS;

error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
These registers record the 8 largest independent values of spectral power found in the scan. To
ensure that each peak is independent, peaks which are adjacent to another higher peak are excluded.
The ¡§adjacent¡¨ region is defined by the SA_MAX_PEAK_WIDTH register. SA_MAX_POWER_REG_0
records the highest spectral power found, whereas SA_MAX_POWER_REG_7 records the 8th
highest power found.
*/
int
realtek_i_SpecAn_DvbSGetSpecAnMaxPwr(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int Number,
	unsigned int *MaxPwrDb,
	unsigned int *MaxPwrindex
)
{
    unsigned int temp;
    
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

    if(MsgGetReg((SA_MAX_POWER_REG_00+Number), 0, &temp) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *MaxPwrDb = (temp & SA_BITFLD_SA_MAX_POWER) >> 16;
    *MaxPwrindex = temp & SA_BITFLD_MAX_POWER_INDEX;
	
    return FUNCTION_SUCCESS;

error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Not enough memory to perform
scan with given resolution and
range settings.
*/
int
realtek_i_SpecAn_DvbSGetSpecAnFailureCode(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *OutOfMem
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

    if(MsgGetReg(SA_FAILURE_CODE, 0, OutOfMem) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;
	
	*OutOfMem &= SA_BITFLD_SCAN_SIZE_EXCEEDS_AVAILABLE_MEMORY;

    return FUNCTION_SUCCESS;

error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
The percentage of spectrum analysing
*/
int
realtek_i_SpecAn_DvbSGetSpecAnCompletionPercent(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *CompPercent
)
{
    REALTEK_I_DVBS_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

    if(MsgGetReg(SA_COMPLETION_PERCENT, 0, CompPercent) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;
	
	*CompPercent &= SA_BITFLD_COMPLETION_PERCENT;

    return FUNCTION_SUCCESS;

error_status_get_demod_registers:
    return FUNCTION_ERROR;
}
