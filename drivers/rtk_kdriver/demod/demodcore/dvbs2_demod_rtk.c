//#include <stdio.h>
#include "dvbs2_demod_rtk.h"
#include "dvbs2_registers.h"
#include "dvbs_registers.h"
#include "spec_an_registers.h"
#include "message_func_rtk.h"
#include "diseqc_rtk.h"
#include <rtk_kdriver/rtk_diseqc.h>


/**

@brief   REALTEK_I DVBS2 demod module builder

Use BuildRealtekIDvbS2Module() to build REALTEK_I DVBS2 module, set all module function pointers with the corresponding
functions, and initialize module private variables.


@param [in]   ppDemod                        Pointer to REALTEK_I DVBS2 demod module pointer
@param [in]   pDvbs2DemodModuleMemory        Pointer to an allocated DVBS2 demod module memory
@param [in]   pBaseInterfaceModuleMemory     Pointer to an allocated base interface module memory
@param [in]   pI2cBridgeModuleMemory         Pointer to an allocated I2C bridge module memory
@param [in]   DeviceAddr                     REALTEK_I DVBS2 I2C device address
@param [in]   CrystalFreqHz                  REALTEK_I DVBS2 crystal frequency in Hz

@note
	-# One should call BuildRealtekIDvbS2Module() to build REALTEK_I DVBS2 module before using it.

*/
void
BuildRealtekIDvbs2Module(
	DVBS2_DEMOD_MODULE **ppDemod,
	DVBS2_DEMOD_MODULE *pDvbS2DemodModuleMemory,
	BASE_INTERFACE_MODULE *pBaseInterfaceModuleMemory,
	I2C_BRIDGE_MODULE *pI2cBridgeModuleMemory,
	unsigned char DeviceAddr,
	unsigned long CrystalFreqHz
)
{
	DVBS2_DEMOD_MODULE *pDemod;

	// Set demod module pointer and get demod module.
	*ppDemod = pDvbS2DemodModuleMemory;
	pDemod = *ppDemod;

	// Set base interface module pointer and I2C bridge module pointer.
	pDemod->pBaseInterface = pBaseInterfaceModuleMemory;
	pDemod->pI2cBridge     = pI2cBridgeModuleMemory;

	// Set demod type.
	pDemod->DemodType = DVBS2_DEMOD_TYPE_REALTEK_I;

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
	pDemod->RegAccess.Addr16Bit.SetRegBytes        = dvbs2_demod_addr_16bit_default_SetRegBytes;
	pDemod->RegAccess.Addr16Bit.GetRegBytes        = dvbs2_demod_addr_16bit_default_GetRegBytes;
	pDemod->RegAccess.Addr16Bit.GetRegMaskBits     = dvbs2_demod_addr_16bit_default_GetRegMaskBits;
	pDemod->RegAccess.Addr16Bit.SetRegBits         = dvbs2_demod_addr_16bit_default_SetRegBits;
	pDemod->RegAccess.Addr16Bit.GetRegBits         = dvbs2_demod_addr_16bit_default_GetRegBits;
	*/

    pDemod->CheckRpuReady                   = realtek_i_dvbs2_common_CheckRpuReady;
    pDemod->PingRpu                         = realtek_i_dvbs2_common_PingRpu;
    pDemod->ShutDown                        = realtek_i_dvbs2_common_ShutDown;
    pDemod->ActivateCore                    = realtek_i_dvbs2_common_ActivateCore;
    pDemod->DeactivateCore                  = realtek_i_dvbs2_common_DeactivateCore;
    pDemod->SwitchToBuffer                  = realtek_i_dvbs2_common_SwitchToBuffer;

    pDemod->GetDemodInfo                    = realtek_i_dvbs2_common_GetDemodInfo;
    pDemod->GetBuildId                      = realtek_i_dvbs2_common_GetBuildId;

    pDemod->DemodCtrlStop                   = realtek_i_dvbs2_common_DemodCtrlStopCmd;
    pDemod->DemodCtrlDetect                 = realtek_i_dvbs2_common_DemodCtrlDetectCmd;
    pDemod->DemodCtrlRun                    = realtek_i_dvbs2_common_DemodCtrlRunCmd;
    pDemod->DemodCtrlUpdateRssi             = realtek_i_dvbs2_common_DemodCtrlUpdateRssiCmd;
    pDemod->DemodCtrlResetCounters          = realtek_i_dvbs2_common_DemodCtrlResetCountersCmd;
    pDemod->DemodCtrlUpdateCounters         = realtek_i_dvbs2_common_DemodCtrlUpdateCountersCmd;
    pDemod->DemodCtrlSetAgc                 = realtek_i_dvbs2_common_DemodCtrlSetAgcCmd;
    pDemod->DemodCtrlUpdateAgc              = realtek_i_dvbs2_common_DemodCtrlUpdateAgcCmd;
    pDemod->DemodCtrlQueryStatus            = realtek_i_dvbs2_common_DemodCtrlQueryStatusCmd;

    pDemod->GetDemodStatus                  = realtek_i_dvbs2_common_GetDemodStatus;

    pDemod->SetTunerFreq                    = realtek_i_dvbs2_common_SetTunerFreqCmd;
    pDemod->SetTunerBandwidth               = realtek_i_dvbs2_common_SetTunerBandwidth;
    pDemod->SetTunerGridBase                = realtek_i_dvbs2_common_SetTunerGridBase;
    pDemod->SetTunerGridIncr                = realtek_i_dvbs2_common_SetTunerGridIncr;
    pDemod->GetActiveTunerFreq              = realtek_i_dvbs2_common_GetActiveTunerFreq;
    pDemod->GetActiveTunerBandwidth         = realtek_i_dvbs2_common_GetActiveTunerBandwidth;
    pDemod->GetActiveTunerGain              = realtek_i_dvbs2_common_GetActiveTunerGain;
    pDemod->GetActiveTunerRssi              = realtek_i_dvbs2_common_GetActiveTunerRssi;

    pDemod->SetNotchFreq                    = realtek_i_dvbs2_common_SetNotchFreqCmd;
    pDemod->SetNotchBandwidth               = realtek_i_dvbs2_common_SetNotchBandwidth;

    pDemod->SetAgcParams                    = realtek_i_dvbs2_common_SetAgcParams;
    pDemod->GetAgcParams                    = realtek_i_dvbs2_common_GetAgcParams;
    pDemod->SetTsConfig                     = realtek_i_dvbs2_common_SetTsConfig;
    pDemod->SetTsClkRateMargin              = realtek_i_dvbs2_common_SetTsClkRateMargin;
    pDemod->SetTsClkRateMax                 = realtek_i_dvbs2_common_SetTsClkRateMax;
    pDemod->GetDemodLockTime                = realtek_i_dvbs2_common_GetDemodLockTime;
    
    pDemod->SetXmlTunerGainCtrl             = realtek_i_dvbs2_common_SetXmlTunerGainCtrl;
    pDemod->SetXmlFlags                     = realtek_i_dvbs2_common_SetXmlFlags;
    pDemod->SetXmlIfFreq                    = realtek_i_dvbs2_common_SetXmlIfFreq;
    pDemod->SetXmlTunerCfgOverride          = realtek_i_dvbs2_common_SetXmlTunerCfgOverride;
    pDemod->SetXmlIfClk                     = realtek_i_dvbs2_common_SetXmlIfClk;
    pDemod->SetXmlLdpcClk                   = realtek_i_dvbs2_common_SetXmlLdpcClk;
    pDemod->SetXmlUccClk                    = realtek_i_dvbs2_common_SetXmlUccClk;
    pDemod->SetXmlMcuClk                    = realtek_i_dvbs2_common_SetXmlMcuClk;
    pDemod->SetXmlPlftCfgOverride           = realtek_i_dvbs2_common_SetXmlPlatformCfgOverride;
    
    pDemod->SetVirtualRegister              = realtek_i_dvbs2_common_SetVirtualRegister;
    pDemod->GetVirtualRegister              = realtek_i_dvbs2_common_GetVirtualRegister;
    pDemod->SetCmdVirtualRegister           = realtek_i_dvbs2_common_SetCmdVirtualRegister;//Call MsgSetCmdReg
    //pDemod->SetCtrlVirtualRegister          = realtek_i_dvbs2_common_SetCtrlVirtualRegister;//removed on S4AP
    //pDemod->GetCtrlVirtualRegister          = realtek_i_dvbs2_common_GetCtrlVirtualRegister;//removed on S4AP
    pDemod->SetHwRegValue                   = realtek_i_dvbs2_common_SetHwRegValue;
    pDemod->GetHwRegValue                   = realtek_i_dvbs2_common_GetHwRegValue;

    pDemod->SetBaudRate                     = realtek_i_dvbs2_SetBaudRate;
    pDemod->GetBaudRate                     = realtek_i_dvbs2_GetBaudRate;
    pDemod->SetModulation                   = realtek_i_dvbs2_SetModulation;
    pDemod->GetModulation                   = realtek_i_dvbs2_GetModulation;
    pDemod->SetCodeRate                     = realtek_i_dvbs2_SetCodeRate;
    pDemod->GetCodeRate                     = realtek_i_dvbs2_GetCodeRate;
    pDemod->SetPilotPresent                 = realtek_i_dvbs2_SetPilotPresent;
    pDemod->GetPilotPresent                 = realtek_i_dvbs2_GetPilotPresent;
    pDemod->SetRolloffFactor                = realtek_i_dvbs2_SetRolloffFactor;
    pDemod->GetRolloffFactor                = realtek_i_dvbs2_GetRolloffFactor;
    pDemod->GetActiveBaudRate               = realtek_i_dvbs2_GetActiveBaudRate;
    pDemod->GetActiveModulation             = realtek_i_dvbs2_GetActiveModulation;
    pDemod->GetActiveCodeRate               = realtek_i_dvbs2_GetActiveCodeRate;
    pDemod->GetActivePilotPresent           = realtek_i_dvbs2_GetActivePilotPresent;
    pDemod->GetActiveRolloffFactor          = realtek_i_dvbs2_GetActiveRolloffFactor;
    pDemod->GetLdpcOutputFer                = realtek_i_dvbs2_GetLdpcOutputFer;
    pDemod->GetBchInputBer                  = realtek_i_dvbs2_GetBchInputBer;
    pDemod->GetBchOutputFer                 = realtek_i_dvbs2_GetBchOutputFer;
    pDemod->GetSysOutputPer                 = realtek_i_dvbs2_GetSysOutputPer;
    pDemod->SetBerAveSecNum                 = realtek_i_dvbs2_SetBerAveSecNum;
    pDemod->GetBerAveSecNum                 = realtek_i_dvbs2_GetBerAveSecNum;
    pDemod->GetTsPktCnt                     = realtek_i_dvbs2_GetTsPktCnt;
    pDemod->GetBadPktCnt                    = realtek_i_dvbs2_GetBadPktCnt;
    pDemod->GetOutputBitRate                = realtek_i_dvbs2_GetOutputBitRate;
    pDemod->GetSnr                          = realtek_i_dvbs2_GetSnr;
    pDemod->SetCarrierFreqSearchRange       = realtek_i_dvbs2_SetCarrierFreqSearchRange;
    pDemod->GetCarrierFreqSearchRange       = realtek_i_dvbs2_GetCarrierFreqSearchRange;
    pDemod->SetSymbolRateSearchRange        = realtek_i_dvbs2_SetSymbolRateSearchRange;
    pDemod->GetSymbolRateSearchRange        = realtek_i_dvbs2_GetSymbolRateSearchRange;
    pDemod->GetAcquisitionState             = realtek_i_dvbs2_GetAcquisitionState;
    pDemod->SetSignalAcquisitionCnt         = realtek_i_dvbs2_SetSignalAcquisitionCnt;
    pDemod->GetSignalAcquisitionCnt         = realtek_i_dvbs2_GetSignalAcquisitionCnt;
    pDemod->GetAcquisitionFailCode          = realtek_i_dvbs2_GetAcquisitionFailCode;
    pDemod->SetDemodErrorCode               = realtek_i_dvbs2_SetDemodErrorCode;
    pDemod->GetDemodErrorCode               = realtek_i_dvbs2_GetDemodErrorCode;
    pDemod->GetAmplitudeI                   = realtek_i_dvbs2_GetAmplitudeI;
    pDemod->GetAmplitudeQ                   = realtek_i_dvbs2_GetAmplitudeQ;
    pDemod->GetAnalogGain                   = realtek_i_dvbs2_GetAnalogGain;
    pDemod->GetDigitalGain                  = realtek_i_dvbs2_GetDigitalGain;
    pDemod->GetAcquisitionTime              = realtek_i_dvbs2_GetAcquisitionTime;
    pDemod->GetCarrierFreqOffset            = realtek_i_dvbs2_GetCarrierFreqOffset;
    pDemod->SetPhyCtrl                      = realtek_i_dvbs2_SetPhyCtrl;
    pDemod->GetPhyCtrl                      = realtek_i_dvbs2_GetPhyCtrl;
    pDemod->SetManualDfeCoeff0              = realtek_i_dvbs2_SetManualDfeCoeff0;
    pDemod->GetManualDfeCoeff0              = realtek_i_dvbs2_GetManualDfeCoeff0;
    pDemod->SetSpectrumInversion            = realtek_i_dvbs2_SetSpectrumInversion;
    pDemod->GetSpectrumInversion            = realtek_i_dvbs2_GetSpectrumInversion;
    pDemod->GetActiveSpectrumInversion      = realtek_i_dvbs2_GetActiveSpectrumInversion;
    //pDemod->SetSystemClockInfo              = realtek_i_dvbs2_SetSystemClockInfo;
    pDemod->SetToneDetectionCtrl            = realtek_i_dvbs2_SetToneDetectionCtrl;
    pDemod->GetToneDetectionValue           = realtek_i_dvbs2_GetToneDetectionValue;
    pDemod->SetDfePhaseTrackerState         = realtek_i_dvbs2_SetDfePhaseTrackerState;
    pDemod->GetDfePhaseTrackerState         = realtek_i_dvbs2_GetDfePhaseTrackerState;
    pDemod->GetDfePhaseTrackerOverrideCtrl  = realtek_i_dvbs2_GetDfePhaseTrackerOverrideCtrl;
    pDemod->SetTunedFreqOffset              = realtek_i_dvbs2_SetTunedFreqOffset;
    pDemod->GetTunedFreqOffset              = realtek_i_dvbs2_GetTunedFreqOffset;
    pDemod->SetTunerFreqRequest             = realtek_i_dvbs2_SetTunerFreqRequest;
    pDemod->GetTunerFreqRequest             = realtek_i_dvbs2_GetTunerFreqRequest;
    pDemod->SetTunerBandwidthRequest        = realtek_i_dvbs2_SetTunerBandwidthRequest;
    pDemod->GetTunerBandwidthRequest        = realtek_i_dvbs2_GetTunerBandwidthRequest;
    pDemod->GetIfAgcGain                    = realtek_i_dvbs2_GetIfAgcGain;

    //DvbS
    pDemod->DvbSSetCodeRate                 = realtek_i_dvbs2_DvbSSetCodeRate;
    pDemod->DvbSSetSpectrumInversion        = realtek_i_dvbs2_DvbSSetSpectrumInversion;
    pDemod->DvbSGetActiveBaudRate           = realtek_i_dvbs2_DvbSGetActiveBaudRate;
    pDemod->DvbSGetActiveCodeRate           = realtek_i_dvbs2_DvbSGetActiveCodeRate;
    pDemod->DvbSGetActiveSpectrumInversion  = realtek_i_dvbs2_DvbSGetActiveSpectrumInversion;
    pDemod->DvbSGetCarrierFreqOffset        = realtek_i_dvbs2_DvbSGetCarrierFreqOffset;
    pDemod->DvbSSetNumSecBerAvg             = realtek_i_dvbs2_DvbSSetNumSecBerAvg;
    pDemod->DvbSSetTunedFreqOffset          = realtek_i_dvbs2_DvbSSetTunedFreqOffset;
    pDemod->DvbSGetAcquisitionTime          = realtek_i_dvbs2_DvbSGetAcquisitionTime;
    
    //DiSEqC Control
    pDemod->SetDiseqcContinue22kOnOff       = realtek_i_Diseqc_SetDiseqcContinue22kOnOff;
    pDemod->SetDiseqcCmd                    = realtek_i_Diseqc_SetDiseqcCmd;
    pDemod->SetDiseqcToneBurst              = realtek_i_Diseqc_SetDiseqcToneBurst;
    pDemod->SetDiseqcUnModToneBurst         = realtek_i_Diseqc_SetDiseqcUnModToneBurst;
    pDemod->SetDiseqcModToneBurst           = realtek_i_Diseqc_SetDiseqcModToneBurst;
    
    //Spectrum Analyzer
    pDemod->DvbS2SetSpecAnScanRange              = realtek_i_SpecAn_DvbS2SetSpecAnScanRange;
    pDemod->DvbS2GetSpecAnScanRange              = realtek_i_SpecAn_DvbS2GetSpecAnScanRange;
    pDemod->DvbS2SetSpecAnScanResolution         = realtek_i_SpecAn_DvbS2SetSpecAnScanResolution;
    pDemod->DvbS2GetSpecAnScanResolution         = realtek_i_SpecAn_DvbS2GetSpecAnScanResolution;
    pDemod->DvbS2SetSpecAnTuningStep             = realtek_i_SpecAn_DvbS2SetSpecAnTuningStep;
    pDemod->DvbS2GetSpecAnTuningStep             = realtek_i_SpecAn_DvbS2GetSpecAnTuningStep;
    pDemod->DvbS2SetSpecAnMeasureCtrl            = realtek_i_SpecAn_DvbS2SetSpecAnMeasureCtrl;
    pDemod->DvbS2GetSpecAnMeasureCtrl            = realtek_i_SpecAn_DvbS2GetSpecAnMeasureCtrl;
    pDemod->DvbS2SetSpecAnAveragePeriod          = realtek_i_SpecAn_DvbS2SetSpecAnAveragePeriod;
    pDemod->DvbS2GetSpecAnAveragePeriod          = realtek_i_SpecAn_DvbS2GetSpecAnAveragePeriod;
    pDemod->DvbS2SetSpecAnIfGainOverride         = realtek_i_SpecAn_DvbS2SetSpecAnIfGainOverride;
    pDemod->DvbS2GetSpecAnIfGainOverride         = realtek_i_SpecAn_DvbS2GetSpecAnIfGainOverride;
    pDemod->DvbS2SetSpecAnTuner3dBPoint          = realtek_i_SpecAn_DvbS2SetSpecAnTuner3dBPoint;
    pDemod->DvbS2SetSpecAnTuner6dBPoint          = realtek_i_SpecAn_DvbS2SetSpecAnTuner6dBPoint;
    pDemod->DvbS2SetSpecAnTuner9dBPoint          = realtek_i_SpecAn_DvbS2SetSpecAnTuner9dBPoint;
    pDemod->DvbS2SetSpecAnTuner12dBPoint         = realtek_i_SpecAn_DvbS2SetSpecAnTuner12dBPoint;
    pDemod->DvbS2GetSpecAnOutSpectrumPtr         = realtek_i_SpecAn_DvbS2GetSpecAnOutSpectrumPtr;
    pDemod->DvbS2GetSpecAnOutSpectrumLen         = realtek_i_SpecAn_DvbS2GetSpecAnOutSpectrumLen;
    pDemod->DvbS2GetSpecAnMaxRssi                = realtek_i_SpecAn_DvbS2GetSpecAnMaxRssi;
    pDemod->DvbS2GetSpecAnRefIfGain              = realtek_i_SpecAn_DvbS2GetSpecAnRefIfGain;
    pDemod->DvbS2GetSpecAnMaxPwr                 = realtek_i_SpecAn_DvbS2GetSpecAnMaxPwr;
    pDemod->DvbS2GetSpecAnFailureCode            = realtek_i_SpecAn_DvbS2GetSpecAnFailureCode;
    pDemod->DvbS2GetSpecAnCompletionPercent      = realtek_i_SpecAn_DvbS2GetSpecAnCompletionPercent;

	return;
}


/*
Nominal symbol rate in Baud. When scanning for a signal this value is
taken as the centre of the symbol rate search range. This value must be
written by the controlling application prior to signal acquisition. Valid range
from 5000000 Baud up to 9/16 of the ADC clock rate (for QPSK signals) or
up to 30000000 Baud (8PSK signals)
Note that after successful signal acquisition the system reports detected
Baud rate in the DVBS2_REG_ACTIVE_BAUD_RATE register.
*/
int
realtek_i_dvbs2_SetBaudRate(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int BaudRate
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    BaudRate &= DVBS2_BITFLD_BAUD_RATE;
    
    if(MsgSetReg(DVBS2_REG_BAUD_RATE, 0, BaudRate) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbs2_GetBaudRate(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *BaudRate
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS2_REG_BAUD_RATE, 0, BaudRate) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *BaudRate &= DVBS2_BITFLD_BAUD_RATE;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Modulation type:
0: QPSK
1: 8PSK
This register may be written by the application prior to signal acquisition.
The system will auto-detect if the wrong modulation is specified, however
setting the correct value in this register may slightly speed signal
acquisition.
Note that after successful signal acquisition the system reports detected
modulation type in the DVBS2_REG_ACTIVE_MODULATION register
*/
int
realtek_i_dvbs2_SetModulation(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int Modulation
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    Modulation &= DVBS2_BITFLD_MODULATION;
    
    if(MsgSetReg(DVBS2_REG_MODULATION, 0, Modulation) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbs2_GetModulation(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *Modulation
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS2_REG_MODULATION, 0, Modulation) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *Modulation &= DVBS2_BITFLD_MODULATION;

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
4: reserved
5: Rate 3/5
6: Rate 4/5
7: Rate 8/9
8: Rate 9/10
This register may be written by the application prior to signal acquisition.
The system will auto-detect if the wrong code rate is specified, however
setting the correct code rate in this register may slightly speed signal
acquisition.
Note that after successful signal acquisition the system reports detected
code rate in the DVBS2_REG_ACTIVE_CODE_RATE register.
*/
int
realtek_i_dvbs2_SetCodeRate(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int CodeRate
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    CodeRate &= DVBS2_BITFLD_CODE_RATE;
    
    if(MsgSetReg(DVBS2_REG_CODE_RATE, 0, CodeRate) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbs2_GetCodeRate(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *CodeRate
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS2_REG_CODE_RATE, 0, CodeRate) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *CodeRate &= DVBS2_BITFLD_CODE_RATE;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
0: Signal does not contain pilots
1: Signal contains pilots
This register may be written by the application prior to signal acquisition.
The system will auto-detect if the wrong value is specified, however setting
the correct value in this register may slightly speed signal acquisition.
Note that after successful signal acquisition the system reports the detected
value for this setting in the DVBS2_REG_ACTIVE_PILOTS_PRESENT
register.
*/
int
realtek_i_dvbs2_SetPilotPresent(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int PilotPresent
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    PilotPresent &= DVBS2_BITFLD_PILOTS_PRESENT;
    
    if(MsgSetReg(DVBS2_REG_PILOTS_PRESENT, 0, PilotPresent) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbs2_GetPilotPresent(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *PilotPresent
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS2_REG_PILOTS_PRESENT, 0, PilotPresent) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *PilotPresent &= DVBS2_BITFLD_PILOTS_PRESENT;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Root-raised cosine rolloff factor used for signal transmission:
0: Alpha = 0.35
1: Alpha = 0.2
2: Alpha = 0.25
This register may be written by the application prior to signal acquisition.
The system will auto-detect if the wrong value is specified, however setting
the correct value in this register may slightly speed signal acquisition.
Note that after successful signal acquisition the system reports the
detected value for this setting in the
DVBS2_REG_ACTIVE_ROLLOFF_FACTOR register.
*/
int
realtek_i_dvbs2_SetRolloffFactor(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int RolloffFactor
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    RolloffFactor &= DVBS2_BITFLD_RRC_ROLLOFF_FACTOR;
    
    if(MsgSetReg(DVBS2_REG_RRC_ROLLOFF_FACTOR, 0, RolloffFactor) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbs2_GetRolloffFactor(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *RolloffFactor
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS2_REG_RRC_ROLLOFF_FACTOR, 0, RolloffFactor) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *RolloffFactor &= DVBS2_BITFLD_RRC_ROLLOFF_FACTOR;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Measured symbol rate in Baud. This measurement will be valid while in
the DEMODULATING state.
*/
int
realtek_i_dvbs2_GetActiveBaudRate(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ActiveBaudRate
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS2_REG_ACTIVE_BAUD_RATE, 0, ActiveBaudRate) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *ActiveBaudRate &= DVBS2_BITFLD_ACTIVE_BAUD_RATE;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Detected modulation type:
0: QPSK
1: 8PSK
This measurement will be valid while in the DEMODULATING state.
*/
int
realtek_i_dvbs2_GetActiveModulation(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ActiveModulation
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS2_REG_ACTIVE_MODULATION, 0, ActiveModulation) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *ActiveModulation &= DVBS2_BITFLD_ACTIVE_MODULATION;

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
4: reserved
5: Rate 3/5
6: Rate 4/5
7: Rate 8/9
8: Rate 9/10
This register contains valid contents while in the DEMODULATING state.
*/
int
realtek_i_dvbs2_GetActiveCodeRate(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ActiveCodeRate
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS2_REG_ACTIVE_CODE_RATE, 0, ActiveCodeRate) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *ActiveCodeRate &= DVBS2_BITFLD_ACTIVE_CODE_RATE;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
0: Signal does not contain pilots
1: Signal contains pilots
This register contains valid contents while in the DEMODULATING
state.
*/
int
realtek_i_dvbs2_GetActivePilotPresent(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ActivePilotPresent
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS2_REG_ACTIVE_PILOTS_PRESENT, 0, ActivePilotPresent) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *ActivePilotPresent &= DVBS2_BITFLD_ACTIVE_PILOTS_PRESENT;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Root-raised cosine rolloff factor used for signal transmission:
0: Alpha = 0.35
1: Alpha = 0.2
2: Alpha = 0.25
This register contains valid contents while in the DEMODULATING
state.
*/
int
realtek_i_dvbs2_GetActiveRolloffFactor(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ActiveRolloffFactor
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS2_REG_ACTIVE_ROLLOFF_FACTOR, 0, ActiveRolloffFactor) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *ActiveRolloffFactor &= DVBS2_BITFLD_ACTIVE_ROLLOFF_FACTOR;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Measured PL frame error rate at the LDPC decoder output. Unsigned
ratio with 32 fractional bits, saturating at 0xFFFFFFFF.
This measurement is averaged over an interval specified by
DVBS2_REG_NUM_SECONDS_BER_AVERAGING. It will be valid
while in the DEMODULATING state, and is updated once per second.
It may be reset using the TV_CMD_RESET_COUNTERS command.
*/
int
realtek_i_dvbs2_GetLdpcOutputFer(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *LdpcOutputFer
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS2_REG_FER_AT_LDPC_OUTPUT, 0, LdpcOutputFer) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *LdpcOutputFer &= DVBS2_BITFLD_FER_AT_LDPC_OUTPUT;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Measured bit error rate at the BCH decoder input. Unsigned ratio with 32
fractional bits, saturating at 0xFFFFFFFF.
This measurement is averaged over an interval specified by
DVBS2_REG_NUM_SECONDS_BER_AVERAGING. It will be valid
while in the DEMODULATING state, and is updated once per second.
It may be reset using the TV_CMD_RESET_COUNTERS command.
*/
int
realtek_i_dvbs2_GetBchInputBer(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *BchInputBer
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS2_REG_BER_AT_BCH_INPUT, 0, BchInputBer) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *BchInputBer &= DVBS2_BITFLD_BER_AT_BCH_INPUT;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Measured baseband frame error rate at the BCH decoder output.
Unsigned ratio with 32 fractional bits, saturating at 0xFFFFFFFF.
This measurement is averaged over an interval specified by
DVBS2_REG_NUM_SECONDS_BER_AVERAGING. It will be valid
while in the DEMODULATING state, and is updated once per second.
It may be reset using the TV_CMD_RESET_COUNTERS command.
*/
int
realtek_i_dvbs2_GetBchOutputFer(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *BchOutputFer
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS2_REG_FER_AT_BCH_OUTPUT, 0, BchOutputFer) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *BchOutputFer &= DVBS2_BITFLD_FER_AT_BCH_OUTPUT;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Measured TS packet error rate at the system output. Unsigned ratio with
32 fractional bits, saturating at 0xFFFFFFFF.
This measurement is averaged over an interval specified by
DVBS2_REG_NUM_SECONDS_BER_AVERAGING. It will be valid while
in the DEMODULATING state, and is updated once per second.
It may be reset using the TV_CMD_RESET_COUNTERS command.
*/
int
realtek_i_dvbs2_GetSysOutputPer(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *SysOutputPer
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS2_REG_PER_AT_OUTPUT, 0, SysOutputPer) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *SysOutputPer &= DVBS2_BITFLD_PER_AT_OUTPUT;

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
realtek_i_dvbs2_SetBerAveSecNum(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int BerAveSecNum
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    BerAveSecNum &= DVBS2_BITFLD_NUM_SECONDS_BER_AVERAGING;
    
    if(MsgSetReg(DVBS2_REG_NUM_SECONDS_BER_AVERAGING, 0, BerAveSecNum) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbs2_GetBerAveSecNum(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *BerAveSecNum
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS2_REG_NUM_SECONDS_BER_AVERAGING, 0, BerAveSecNum) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *BerAveSecNum &= DVBS2_BITFLD_NUM_SECONDS_BER_AVERAGING;

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
realtek_i_dvbs2_GetTsPktCnt(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *TsPktCnt
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS2_REG_TS_PACKET_COUNT, 0, TsPktCnt) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *TsPktCnt &= DVBS2_BITFLD_TS_PACKET_COUNT;

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
realtek_i_dvbs2_GetBadPktCnt(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *BadPktCnt
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS2_REG_BAD_PACKET_COUNT, 0, BadPktCnt) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *BadPktCnt &= DVBS2_BITFLD_BAD_PACKET_COUNT;

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
realtek_i_dvbs2_GetOutputBitRate(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *OutputBitRat
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS2_REG_BIT_RATE, 0, OutputBitRat) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *OutputBitRat &= DVBS2_BITFLD_BIT_RATE;

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
realtek_i_dvbs2_GetSnr(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *Snr
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS2_REG_SNR_ESTIMATE, 0, Snr) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *Snr &= DVBS2_BITFLD_SNR_ESTIMATE;

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
realtek_i_dvbs2_SetCarrierFreqSearchRange(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int CarrierFreqSearchRange
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    CarrierFreqSearchRange &= DVBS2_BITFLD_CARRIER_FREQ_SEARCH_RANGE;
    
    if(MsgSetReg(DVBS2_CARRIER_FREQ_SEARCH_RANGE, 0, CarrierFreqSearchRange) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbs2_GetCarrierFreqSearchRange(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *CarrierFreqSearchRange
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS2_CARRIER_FREQ_SEARCH_RANGE, 0, CarrierFreqSearchRange) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *CarrierFreqSearchRange &= DVBS2_BITFLD_CARRIER_FREQ_SEARCH_RANGE;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Range of symbol rate to search in each direction around the
nominal symbol rate (as specified by
DVBS2_REG_BAUD_RATE), when the DETECT command is
issued. Value in Baud.
*/
int
realtek_i_dvbs2_SetSymbolRateSearchRange(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int SymbolRateSearchRange
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    SymbolRateSearchRange &= DVBS2_BITFLD_SYMBOL_RATE_SEARCH_RANGE;
    
    if(MsgSetReg(DVBS2_SYMBOL_RATE_SEARCH_RANGE, 0, SymbolRateSearchRange) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbs2_GetSymbolRateSearchRange(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *SymbolRateSearchRange
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS2_SYMBOL_RATE_SEARCH_RANGE, 0, SymbolRateSearchRange) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *SymbolRateSearchRange &= DVBS2_BITFLD_SYMBOL_RATE_SEARCH_RANGE;

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
12: PL header search phase 1
13: PL header search phase 2
14: PL frame alignment
15: Re-configuration due to MODCOD change
16: Baseband Frame header detection
17: Phase tracking
18: Demodulating
*/
int
realtek_i_dvbs2_GetAcquisitionState(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *AcquisitionState
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS2_REG_ACQUISITION_STATE, 0, AcquisitionState) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *AcquisitionState &= DVBS2_BITFLD_ACQUISITION_STATE;

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
realtek_i_dvbs2_SetSignalAcquisitionCnt(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int SignalAcquisitionCnt
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    SignalAcquisitionCnt &= DVBS2_BITFLD_NUM_ACQUISITIONS;
    
    if(MsgSetReg(DVBS2_REG_NUM_ACQUISITIONS, 0, SignalAcquisitionCnt) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbs2_GetSignalAcquisitionCnt(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *SignalAcquisitionCnt
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS2_REG_NUM_ACQUISITIONS, 0, SignalAcquisitionCnt) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *SignalAcquisitionCnt &= DVBS2_BITFLD_NUM_ACQUISITIONS;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Code indicating the reason for the most recent signal
acquisition failure as follows:
0: No acquisition failure reported
1: Insufficient signal power detected
2: Failed to obtain symbol lock
3: Failed to identify a carrier
4: Carrier frequency offset out of range
5: PL frame header not detected
6: Failed to obtain PL frame synchronization
7: Unsupported modulation / coding system
8: Demodulation failed, too high a packet error rate
*/
int
realtek_i_dvbs2_GetAcquisitionFailCode(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *AcquisitionFailCode
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS2_BITFLD_ACQUISITION_FAILURE_CODE, 0, AcquisitionFailCode) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *AcquisitionFailCode &= DVBS2_BITFLD_NUM_ACQUISITIONS;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
7: A 1 on this bit indicates that the system timed out waiting for
response from a host-controlled tuner when attempting to retune
6: A 1 on this bit indicates that an invalid modulation and coding
combination has been requested or detected
5: A 1 on this bit indicates under-run in baseband frame
processing, normally due to a lack of Meta MIPS. This error is
critical (will result in corrupted output)
4: A 1 on this bit indicates that the TIMERCONFIG register within
the Meta processor does not indicate a valid clock
3: A 1 on this bit indicates an under-run in control loop processing
on Meta, normally due to a lack of Meta MIPS. This error may
not be critical (the system can operate with occasional underrun)
but should be avoided for reliable operation.
2: A 1 on this bit indicates an overflow condition on the SCP input.
If this error is seen it indicates either the IF clock / core clock
ratio is too high, or the SCP is running too slow (perhaps for
example because features such as notch filter / impulsive noise
filter have been enabled)
1: A 1 on this bit indicates a FIFO overflow on the SCP output. If
this error is seen it indicates that the SCP driver is unable to
keep up with the flow of samples out of the SCP (perhaps
because the IF clock frequency is too high, or incorrect resample
factor / decimation factor)
0: A 1 on this bit indicates an out-of-range value was written to the
symbol rate register
flags are sticky, write 0 to clear
*/
int
realtek_i_dvbs2_SetDemodErrorCode(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int DemodErrorCode
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
/*
    DemodErrorCode &= (DVBS2_BITFLD_TUNING_TIMEOUT_ERROR | DVBS2_BITFLD_UNSUPPORTED_MODCOD_ERROR | DVBS2_BITFLD_BBFRAME_PROC_UNDERRUN_ERROR |
                        DVBS2_BITFLD_TIMER_CONFIG_ERROR | DVBS2_BITFLD_LOOP_PROC_UNDERRUN_ERROR | DVBS2_BITFLD_SCP_IP_SYNCHRONISER_OFLOW_ERROR |
                        DVBS2_BITFLD_SCP_TBUS_OFLOW_ERROR | DVBS2_BITFLD_BAUD_RATE_RANGE_ERROR);

    if(MsgSetReg(DVBS2_REG_ERROR_CODE, 0, DemodErrorCode) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
*/
    return FUNCTION_ERROR;
}


int
realtek_i_dvbs2_GetDemodErrorCode(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *DemodErrorCode
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
/*
    if(MsgGetReg(DVBS2_REG_ERROR_CODE, 0, DemodErrorCode) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *DemodErrorCode &= (DVBS2_BITFLD_TUNING_TIMEOUT_ERROR | DVBS2_BITFLD_UNSUPPORTED_MODCOD_ERROR | DVBS2_BITFLD_BBFRAME_PROC_UNDERRUN_ERROR |
                        DVBS2_BITFLD_TIMER_CONFIG_ERROR | DVBS2_BITFLD_LOOP_PROC_UNDERRUN_ERROR | DVBS2_BITFLD_SCP_IP_SYNCHRONISER_OFLOW_ERROR |
                        DVBS2_BITFLD_SCP_TBUS_OFLOW_ERROR | DVBS2_BITFLD_BAUD_RATE_RANGE_ERROR);

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
realtek_i_dvbs2_GetAmplitudeI(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *AmplitudeI
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS2_REG_I_AMP, 0, AmplitudeI) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *AmplitudeI &= DVBS2_BITFLD_I_AMP;

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
realtek_i_dvbs2_GetAmplitudeQ(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *AmplitudeQ
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS2_BITFLD_Q_AMP, 0, AmplitudeQ) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *AmplitudeQ &= DVBS2_BITFLD_Q_AMP;

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
realtek_i_dvbs2_GetAnalogGain(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *AnalogGain
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS2_REG_ANALOG_GAIN, 0, AnalogGain) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *AnalogGain &= DVBS2_BITFLD_ANALOG_GAIN;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
13:16 :Digital gain setting for the I channel. Unsigned value with 8 fractional bits.
15:0 :Digital gain setting for the Q channel. Unsigned value with 8 fractional bits.
*/
int
realtek_i_dvbs2_GetDigitalGain(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *DigitalGainI,
	unsigned int *DigitalGainQ
)
{
    unsigned int RegVal = 0;

    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

    if(MsgGetReg(DVBS2_REG_DIGITAL_GAIN, 0, &RegVal) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *DigitalGainI &= (RegVal & DVBS2_BITFLD_DIGITAL_GAIN_I);
    *DigitalGainQ &= (RegVal & DVBS2_BITFLD_DIGITAL_GAIN_Q);

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Acquisition time for the most recent acquisition, measured in ms.
*/
int
realtek_i_dvbs2_GetAcquisitionTime(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *AcquisitionTime
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS2_REG_ACQUISITION_TIME, 0, AcquisitionTime) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *AcquisitionTime &= DVBS2_BITFLD_ACQUISITION_TIME;

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
realtek_i_dvbs2_GetCarrierFreqOffset(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *CarrierFreqOffset
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS2_REG_CARRIER_FREQ_OFFSET, 0, CarrierFreqOffset) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *CarrierFreqOffset &= DVBS2_BITFLD_CARRIER_FREQ_OFFSET;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
1: If this bit is set to 1 then the values in the registers
DVBS2_REG_FER_AT_LDPC_OUTPUT,
DVBS2_REG_BER_AT_BCH_INPUT
DVBS2_REG_FER_AT_BCH_OUTPUT,
DVBS2_REG_PER_AT_OUTPUT,
DVBS2_REG_TS_PACKET_COUNT and
DVBS2_REG_BAD_PACKET_COUNT will be reset
automatically whenever re-acquisition to a signal occurs. If
this bit is left at 0 then these values are only reset on
activation, or through use of the
TV_CMD_RESET_COUNTERS command.
2: If this bit is set to 0 then the system will adapt coefficients for
a Decision Feedback Equaliser (DFE), which attempts to
correct for echo present in the channel (typically introduced
by the cable distribution from the LNB). If this bit is set to 1
then the DFE coefficients can be set manually using
registers DVBS2_MANUAL_DFE_COEFFS00 through
DVBS2_MANUAL_DFE_COEFFS15.
Signal acquisition will be quicker if this bit is set to 1. Typical
use of this control would be to use adaptive mode to
discover the channel response (as obtained by reading the
coefficient registers). This response will be constant for a
given installation, therefore coefficients can be calculated for
manual application when tuning subsequently.
Changes to this register will only take effect on signal
acquisition.
*/
int
realtek_i_dvbs2_SetPhyCtrl(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int ReAcqResetMetricsEn,
	unsigned int CoeffsCtrlMode
)
{
    unsigned int RegVal = 0;

    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    RegVal |= (((ReAcqResetMetricsEn << 1) & DVBS2_BITFLD_RESET_METRICS_ON_REACQUISITION));
    RegVal |= (CoeffsCtrlMode & DVBS2_BITFLD_DFE_COEFFS_CONTROL_MODE);
    if(MsgSetReg(DVBS2_REG_CTRL, 0, RegVal) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbs2_GetPhyCtrl(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ReAcqResetMetricsEn,
	unsigned int *CoeffsCtrlMode
)
{
    unsigned int RegVal = 0;
    
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS2_REG_CTRL, 0, &RegVal) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *ReAcqResetMetricsEn = (RegVal & DVBS2_BITFLD_RESET_METRICS_ON_REACQUISITION) >> 1;
    *CoeffsCtrlMode = (RegVal & DVBS2_BITFLD_DFE_COEFFS_CONTROL_MODE);
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
The Decision Feedback Equaliser (DFE) is a hardware component within the UCCP which is used for
equalisation of channel response (particularly echo). This set of 16 registers allows the user either to
read coefficients from the DFE, after they have been adapted by the DVB-S2 software (with
DVBS2_REG_DFE_COEFFS_CONTROL_MODE=0, i.e. adaptive mode); or to write DFE coefficients
for use with DVBS2_REG_DFE_COEFFS_CONTROL_MODE=1 (manual mode).
*/
int
realtek_i_dvbs2_SetManualDfeCoeff0(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int ManualCoeffReal0,
	unsigned int ManualCoeffImg0
)
{
    unsigned int RegVal = 0;

    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    RegVal |= (((ManualCoeffReal0 << 16) & DVBS2_BITFLD_DFE_COEFF_REAL_0));
    RegVal |= (ManualCoeffImg0 & DVBS2_BITFLD_DFE_COEFF_IMAG_0);
    if(MsgSetReg(DVBS2_REG_MANUAL_DFE_COEFFS00, 0, RegVal) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbs2_GetManualDfeCoeff0(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ManualCoeffReal0,
	unsigned int *ManualCoeffImg0
)
{
    unsigned int RegVal = 0;
    
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS2_REG_MANUAL_DFE_COEFFS00, 0, &RegVal) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *ManualCoeffReal0 = (RegVal & DVBS2_BITFLD_DFE_COEFF_REAL_0) >> 16;
    *ManualCoeffImg0 = (RegVal & DVBS2_BITFLD_DFE_COEFF_IMAG_0);
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
0: Spectrum is inverted (I and Q swapped at transmitter)
1: Spectrum is not inverted
This register may be written by the application prior to signal
acquisition. The system will auto-detect if the wrong value is
specified, however setting the correct value in this register may slightly
speed signal acquisition.
Note that after successful signal acquisition the system reports the
detected value for this setting in the
DVBS2_REG_ACTIVE_SPECTRUM_INVERSION register.
*/
int
realtek_i_dvbs2_SetSpectrumInversion(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int SpectrumInversion
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    SpectrumInversion &= DVBS2_BITFLD_SPECTRUM_INVERSION;
    
    if(MsgSetReg(DVBS2_REG_SPECTRUM_INVERSION, 0, SpectrumInversion) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbs2_GetSpectrumInversion(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *SpectrumInversion
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS2_REG_SPECTRUM_INVERSION, 0, SpectrumInversion) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *SpectrumInversion &= DVBS2_BITFLD_SPECTRUM_INVERSION;

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
realtek_i_dvbs2_GetActiveSpectrumInversion(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ActiveSpectrumInversion
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS2_REG_ACTIVE_SPECTRUM_INVERSION, 0, ActiveSpectrumInversion) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *ActiveSpectrumInversion &= DVBS2_BITFLD_ACTIVE_SPECTRUM_INVERSION;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
bit0: 0: LDPC clock frequency is 1x core clock, 1: LDPC clock frequency is 2x core clock
bit1: 0: Meta clock frequency is 1x core clock, 1: Meta clock frequency is 2x core clock
*/
/*int
realtek_i_dvbs2_SetSystemClockInfo(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int LdpcClockFreq,
	unsigned int MetaClockFreq
)
{
    unsigned int RegVal = 0;

    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    RegVal |= (((LdpcClockFreq << 1) & DVBS2_BITFLD_LDPC_CLOCK_FREQ));
    RegVal |= (MetaClockFreq & DVBS2_BITFLD_META_CLOCK_FREQ);
    if(MsgSetReg(DVBS2_REG_CLOCKING_INFO, 0, RegVal) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}
*/

/*
bit16: Set to 1 to enable monitoring of automatic gain control (AGC).
bit15: Set to 1 to enable input signal spectra measurement. A 512 bin FFT is
taken over four blocks and averaged into a power spectral density
buffer every 500ms when this is enabled. The inner 256 bins are
searched for a peak on completion (see 3.1.38). The PSD buffer can
be transferred to the debug vector (see section 4).
bit14~8: AGC tone detection period in milliseconds.
bit7~0: Tone detection threshold as a percentage change in squared AGC
level over the defined period.
*/
int
realtek_i_dvbs2_SetToneDetectionCtrl(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int ToneDetEn,
	unsigned int ToneDetPsdEn,
	unsigned int ToneDetPeriod,
	unsigned int ToneDetTh
)
{
    unsigned int RegVal = 0;

    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    RegVal |= (((ToneDetEn << 16) & DVBS2_BITFLD_TONE_DETECT_ENABLE));
    RegVal |= (((ToneDetPsdEn << 15) & DVBS2_BITFLD_TONE_DETECT_ENABLE_PSD));
    RegVal |= (((ToneDetPeriod << 8) & DVBS2_BITFLD_TONE_DETECT_PERIOD));
    RegVal |= (ToneDetTh & DVBS2_BITFLD_TONE_DETECT_THRESHOLD);
    if(MsgSetReg(DVBS2_REG_TONE_DETECT_CTRL, 0, RegVal) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


/*
bit31~24: If DVBS2_TONE_DETECT_ENABLE is 1 and a change, exceeding
the parameters defined by DVBS2_TONE_DETECT_PERIOD and
DVBS2_TONE_DETECT_THRESHOLD, in the squared AGC level
is detected, the change is reported as a percentage in Q7.1 format.
The value will clear when the squared AGC level falls by a quarter
of the threshold defined.
bit23~15:If DVBS2_TONE_DETECT_ENABLE_PSD is 1, a peak index is
reported. The value is updated on completion of the PSD measure.
bit14~0: If DVBS2_TONE_DETECT_ENABLE_PSD is 1, an integer peak-tomean
ratio is reported. The mean is calculated from the inner 256
bins. The value is updated on completion of the PSD measure.
*/
int
realtek_i_dvbs2_GetToneDetectionValue(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ToneDetChange,
	unsigned int *ToneDetPeakIdx,
	unsigned int *ToneDetPeakRatio
)
{
    unsigned int RegVal = 0;

    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS2_REG_TONE_DETECT_VALUE, 0, &RegVal) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *ToneDetChange = (RegVal & DVBS2_BITFLD_TONE_DETECT_CTRL_CHANGE) >> 24;
    *ToneDetPeakIdx = (RegVal & DVBS2_BITFLD_TONE_DETECT_PEAK_IDX) >> 15;
    *ToneDetPeakRatio = (RegVal & DVBS2_BITFLD_TONE_DETECT_PEAK_RATIO);

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
bit31~28: DFE phase tracking mode; 0. ADAPTIVE; 1. FIXED; 2. PILOTS PLUS ADAPTION; 3. PILOTS_ONLY
bit27~24: DFE phase tracker gain control (negative shift such that gain = 2^-x).
bit23~0: DFE phase tracker mean-squared phase error (pre-phase correction
measurement).
*/
int
realtek_i_dvbs2_SetDfePhaseTrackerState(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int DfePhaseTrackMode,
	unsigned int DfePhaseTrackGain,
	unsigned int DfePhaseTrackErr
)
{
    unsigned int RegVal = 0;

    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    RegVal |= (((DfePhaseTrackMode << 28) & DVBS2_BITFLD_DFE_PHASE_TRACKING_MODE));
    RegVal |= (((DfePhaseTrackGain << 24) & DVBS2_BITFLD_DFE_PHASE_TRACKING_GAIN_CTRL));
    RegVal |= (DfePhaseTrackErr & DVBS2_BITFLD_DFE_PHASE_TRACKER_MS_PHASE_ERROR);
    if(MsgSetReg(DVBS2_REG_PHASE_TRACK_STATE, 0, RegVal) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbs2_GetDfePhaseTrackerState(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *DfePhaseTrackMode,
	unsigned int *DfePhaseTrackGain,
	unsigned int *DfePhaseTrackErr
)
{
    unsigned int RegVal = 0;

    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS2_REG_PHASE_TRACK_STATE, 0, &RegVal) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *DfePhaseTrackMode = (RegVal & DVBS2_BITFLD_DFE_PHASE_TRACKING_MODE) >> 28;
    *DfePhaseTrackGain = (RegVal & DVBS2_BITFLD_DFE_PHASE_TRACKING_GAIN_CTRL) >> 24;
    *DfePhaseTrackErr = (RegVal & DVBS2_BITFLD_DFE_PHASE_TRACKER_MS_PHASE_ERROR);
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
bit31: 1 - Set DFE phase tracker gain (override defaults); 0 - No change.
bit30: 1 - Set DFE phase tracker core and clip level; 0 - No change.
bit29~28: Reserved
bit27~16: Core level (default 0x000).
bit15~4: Clip level (default 0xFFF).
bit3~0: DFE phase tracker gain negative shift (must be between 6 and 15). Gain = 2^-x
*/
int
realtek_i_dvbs2_GetDfePhaseTrackerOverrideCtrl(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *DfePhaseTrackGain,
	unsigned int *DfePhaseTrackCoreClipLvl,
	unsigned int *CoreLvl,
	unsigned int *ClipLvl,
	unsigned int *DfePhaseTrackGainNegShift
)
{
    unsigned int RegVal = 0;

    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS2_REG_PHASE_TRACK_CTRL_8PSK, 0, &RegVal) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *DfePhaseTrackGain = (RegVal & DVBS2_BITFLD_DFE_PHASE_TRACKER_GAIN) >> 31;
    *DfePhaseTrackCoreClipLvl = (RegVal & DVBS2_BITFLD_DFE_PHASE_CORE_CLIP_LVL) >> 30;
    *CoreLvl = (RegVal & DVBS2_BITFLD_DFE_PHASE_CORE_LVL) >> 16;
    *ClipLvl = (RegVal & DVBS2_BITFLD_DFE_PHASE_CLIP_LVL) >> 4;
    *DfePhaseTrackGainNegShift = (RegVal & DVBS2_BITFLD_DFE_PHASE_TRACKER_GAIN_NEG_SHIFT);
    
    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Offset (in Hz) between tuned frequency and wanted carrier frequency.
This register may be written by the application prior to signal
acquisition. This offset is normally left at zero, but can be used to
avoid locating the carrier at DC when operating at low symbol rate.
A positive offset indicates that the tuned frequency is higher than the
carrier frequency.
*/
int
realtek_i_dvbs2_SetTunedFreqOffset(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int TunedFreqOffset
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    TunedFreqOffset &= DVBS2_BITFLD_TUNED_FREQ_OFFSET;
    
    if(MsgSetReg(DVBS2_REG_TUNED_FREQ_OFFSET, 0, TunedFreqOffset) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbs2_GetTunedFreqOffset(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *TunedFreqOffset
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS2_REG_TUNED_FREQ_OFFSET, 0, TunedFreqOffset) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *TunedFreqOffset &= DVBS2_BITFLD_TUNED_FREQ_OFFSET;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Set tuner frequency, in Hertz, when using an external tuner. Overrides
the TV_REG_TUNER_FREQ and TV_REG_TUNER_BW when nonzero.
*/
int
realtek_i_dvbs2_SetTunerFreqRequest(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int TunedFreqReq
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    TunedFreqReq &= DVBS2_BITFLD_TUNE_REQUEST;
    
    if(MsgSetReg(DVBS2_REG_TUNE_REQUEST, 0, TunedFreqReq) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbs2_GetTunerFreqRequest(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *TunedFreqReq
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS2_REG_TUNE_REQUEST, 0, TunedFreqReq) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *TunedFreqReq &= DVBS2_BITFLD_TUNE_REQUEST;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Set tuner bandwidth, in Hertz, when using an external tuner. Overrides the
TV_REG_TUNER_FREQ and TV_REG_TUNER_BW when non-zero.
*/
int
realtek_i_dvbs2_SetTunerBandwidthRequest(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int TunedFreqReq
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    TunedFreqReq &= DVBS2_BITFLD_BW_REQUEST;
    
    if(MsgSetReg(DVBS2_REG_BW_REQUEST, 0, TunedFreqReq) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbs2_GetTunerBandwidthRequest(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *TunedFreqReq
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(DVBS2_REG_BW_REQUEST, 0, TunedFreqReq) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *TunedFreqReq &= DVBS2_BITFLD_BW_REQUEST;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbs2_GetIfAgcGain(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *IfAgcGain
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

    if(GetHwRegValue(0x02041090, IfAgcGain) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

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
realtek_i_dvbs2_DvbSSetCodeRate(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int DemodCodeRate
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    //DemodCodeRate &= DVBS_BITFLD_CODE_RATE;
    
    if(MsgSetReg(0x8001, 0, DemodCodeRate) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
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
realtek_i_dvbs2_DvbSSetSpectrumInversion(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int SpectrumInversion
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    //SpectrumInversion &= DVBS_BITFLD_SPECTRUM_INVERSION;
    
    if(MsgSetReg(0x8029, 0, SpectrumInversion) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


/*
Measured symbol rate in Baud. This measurement will be valid while in
the DEMODULATING state.
*/
int
realtek_i_dvbs2_DvbSGetActiveBaudRate(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ActiveBaudRate
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(0x8002, 0, ActiveBaudRate) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    //*ActiveBaudRate &= 0xFFFFFFFF;

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
realtek_i_dvbs2_DvbSGetActiveCodeRate(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ActiveCodeRate
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(0x8003, 0, ActiveCodeRate) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    //*ActiveCodeRate &= DVBS_BITFLD_ACTIVE_CODE_RATE;

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
realtek_i_dvbs2_DvbSGetActiveSpectrumInversion(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ActiveSpectrumInversion
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(0x802A, 0, ActiveSpectrumInversion) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

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
realtek_i_dvbs2_DvbSGetCarrierFreqOffset(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *CarrierFreqOffset
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(0x8017, 0, CarrierFreqOffset) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *CarrierFreqOffset &= 0xFFFFFFFF;

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
realtek_i_dvbs2_DvbSSetNumSecBerAvg(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int NumSecBerAvg
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    NumSecBerAvg &= DVBS_BITFLD_NUM_SECONDS_BER_AVERAGING;
    
    if(MsgSetReg(DVBS_REG_NUM_SECONDS_BER_AVERAGING, 0, NumSecBerAvg) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbs2_DvbSSetTunedFreqOffset(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int TunedFreqOffset
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    TunedFreqOffset &= 0xFFFFFFFF;
    
    if(MsgSetReg(0x802F, 0, TunedFreqOffset) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbs2_DvbSGetAcquisitionTime(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *AcquisitionTime
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(0x8016, 0, AcquisitionTime) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    *AcquisitionTime &= 0xFFFFFFFF;

    return FUNCTION_SUCCESS;
	
error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
Frequency range between start and end points of the scan, in Hz.
*/
int
realtek_i_SpecAn_DvbS2SetSpecAnScanRange(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int ScanRange
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    ScanRange &= SA_BITFLD_SCAN_RANGE;
    
    if(MsgSetReg(SA_SCAN_RANGE, 0, ScanRange) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_SpecAn_DvbS2GetSpecAnScanRange(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ScanRange
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
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
realtek_i_SpecAn_DvbS2SetSpecAnScanResolution(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int ScanResolution
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    ScanResolution &= SA_BITFLD_SCAN_RESOLUTION;
    
    if(MsgSetReg(SA_SCAN_RESOLUTION, 0, ScanResolution) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_SpecAn_DvbS2GetSpecAnScanResolution(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ScanResolution
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
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
realtek_i_SpecAn_DvbS2SetSpecAnTuningStep(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int TuningStepAuto,
	unsigned int TuningStep
)
{
    unsigned int RegVal = 0;

    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    RegVal |= (((TuningStepAuto << 30) & SA_BITFLD_TUNING_STEP_AUTO));
    RegVal |= (TuningStep & SA_BITFLD_TUNING_STEP);
	
    if(MsgSetReg(SA_TUNING_STEP, 0, RegVal) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_SpecAn_DvbS2GetSpecAnTuningStep(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *TuningStepAuto,
	unsigned int *TuningStep
)
{
    unsigned int RegVal = 0;

    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
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
realtek_i_SpecAn_DvbS2SetSpecAnMeasureCtrl(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int EnDcComp,
	unsigned int Window,
	unsigned int SignalType,
	unsigned int MaxPickWidth
)
{
    unsigned int RegVal = 0;

    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
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
realtek_i_SpecAn_DvbS2GetSpecAnMeasureCtrl(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *EnDcComp,
	unsigned int *Window,
	unsigned int *SignalType,
	unsigned int *MaxPickWidth
)
{
    unsigned int RegVal = 0;

    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
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
realtek_i_SpecAn_DvbS2SetSpecAnAveragePeriod(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int AveragePeriodM,
	unsigned int AveragePeriodN
)
{
    unsigned int RegVal = 0;

    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    RegVal |= (((AveragePeriodM << 8) & SA_BITFLD_AVERAGING_PERIOD_M));
    RegVal |= (AveragePeriodN & SA_BITFLD_AVERAGING_PERIOD_N);
	
    if(MsgSetReg(SA_AVERAGING_PERIOD, 0, RegVal) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_SpecAn_DvbS2GetSpecAnAveragePeriod(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *AveragePeriodM,
	unsigned int *AveragePeriodN
)
{
    unsigned int RegVal = 0;

    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
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
realtek_i_SpecAn_DvbS2SetSpecAnIfGainOverride(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int OverrideIfGain,
	unsigned int IfGain
)
{
    unsigned int RegVal = 0;

    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    RegVal |= (((OverrideIfGain << 16) & SA_BITFLD_OVERRIDE_IF_GAIN));
    RegVal |= (IfGain & SA_BITFLD_IF_GAIN);
	
    if(MsgSetReg(SA_IF_GAIN_OVERRIDE, 0, RegVal) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;
	
error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_SpecAn_DvbS2GetSpecAnIfGainOverride(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *OverrideIfGain,
	unsigned int *IfGain
)
{
    unsigned int RegVal = 0;

    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
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
realtek_i_SpecAn_DvbS2SetSpecAnTuner3dBPoint(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int FreqSpacing
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
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
realtek_i_SpecAn_DvbS2SetSpecAnTuner6dBPoint(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int FreqSpacing
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
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
realtek_i_SpecAn_DvbS2SetSpecAnTuner9dBPoint(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int FreqSpacing
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
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
realtek_i_SpecAn_DvbS2SetSpecAnTuner12dBPoint(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int FreqSpacing
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
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
realtek_i_SpecAn_DvbS2GetSpecAnOutSpectrumPtr(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *OutSpecMemType,
	unsigned int *SpecMemPtr
)
{
    unsigned int RegVal = 0;

    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
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
realtek_i_SpecAn_DvbS2GetSpecAnOutSpectrumLen(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *OutSpecLen
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

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
realtek_i_SpecAn_DvbS2GetSpecAnMaxRssi(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *MaxRssi,
	unsigned int *MaxRssiIdx
)
{
    unsigned int RegVal = 0;

    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
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
realtek_i_SpecAn_DvbS2GetSpecAnRefIfGain(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *RefIfGain
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

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
realtek_i_SpecAn_DvbS2GetSpecAnMaxPwr(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int Number,
	unsigned int *MaxPwrDb,
	unsigned int *MaxPwrindex
)
{
    unsigned int temp;
    
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

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
realtek_i_SpecAn_DvbS2GetSpecAnFailureCode(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *OutOfMem
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

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
realtek_i_SpecAn_DvbS2GetSpecAnCompletionPercent(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *CompPercent
)
{
    REALTEK_I_DVBS2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

    if(MsgGetReg(SA_COMPLETION_PERCENT, 0, CompPercent) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;
	
	*CompPercent &= SA_BITFLD_COMPLETION_PERCENT;

    return FUNCTION_SUCCESS;

error_status_get_demod_registers:
    return FUNCTION_ERROR;
}
