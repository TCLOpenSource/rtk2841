//#include <stdio.h>
#include "dvbt2_demod_rtk.h"
#include "dvbt2_registers.h"
#include "dvbt_registers.h"
#include "message_func_rtk.h"


/**

@brief   REALTEK_I DVBT2 demod module builder

Use BuildRealtekIDvbT2Module() to build REALTEK_I DVBT2 module, set all module function pointers with the corresponding
functions, and initialize module private variables.


@param [in]   ppDemod                        Pointer to REALTEK_I DVBT2 demod module pointer
@param [in]   pDvbT2DemodModuleMemory        Pointer to an allocated DVBT2 demod module memory
@param [in]   pBaseInterfaceModuleMemory     Pointer to an allocated base interface module memory
@param [in]   pI2cBridgeModuleMemory         Pointer to an allocated I2C bridge module memory
@param [in]   DeviceAddr                     REALTEK_I DVBT2 I2C device address
@param [in]   CrystalFreqHz                  REALTEK_I DVBT2 crystal frequency in Hz

@note
	-# One should call BuildRealtekIDvbT2Module() to build REALTEK_I DVBT2 module before using it.

*/
void
BuildRealtekIDvbt2Module(
	DVBT2_DEMOD_MODULE **ppDemod,
	DVBT2_DEMOD_MODULE *pDvbT2DemodModuleMemory,
	BASE_INTERFACE_MODULE *pBaseInterfaceModuleMemory,
	I2C_BRIDGE_MODULE *pI2cBridgeModuleMemory,
	unsigned char DeviceAddr,
	unsigned long CrystalFreqHz
)
{
	DVBT2_DEMOD_MODULE *pDemod;

	// Set demod module pointer and get demod module.
	*ppDemod = pDvbT2DemodModuleMemory;
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
	pDemod->RegAccess.Addr16Bit.SetRegBytes         = dvbt2_demod_addr_16bit_default_SetRegBytes;
	pDemod->RegAccess.Addr16Bit.GetRegBytes         = dvbt2_demod_addr_16bit_default_GetRegBytes);
	pDemod->RegAccess.Addr16Bit.GetRegMaskBits      = dvbt2_demod_addr_16bit_default_GetRegMaskBits;
	pDemod->RegAccess.Addr16Bit.SetRegBits          = dvbt2_demod_addr_16bit_default_SetRegBits;
	pDemod->RegAccess.Addr16Bit.GetRegBits          = dvbt2_demod_addr_16bit_default_GetRegBits;
	*/

	pDemod->CheckRpuReady                           = realtek_i_dvbt2_common_CheckRpuReady;
	pDemod->PingRpu                                 = realtek_i_dvbt2_common_PingRpu;
	pDemod->ShutDown                                = realtek_i_dvbt2_common_ShutDown;
	pDemod->ActivateCore                            = realtek_i_dvbt2_common_ActivateCore;
	pDemod->DeactivateCore                          = realtek_i_dvbt2_common_DeactivateCore;
	pDemod->SwitchToBuffer				= realtek_i_dvbt2_common_SwitchToBuffer;

	pDemod->GetDemodInfo                            = realtek_i_dvbt2_common_GetDemodInfo;
	pDemod->GetBuildId                              = realtek_i_dvbt2_common_GetBuildId;

	pDemod->DemodCtrlStop                           = realtek_i_dvbt2_common_DemodCtrlStopCmd;
	pDemod->DemodCtrlDetect                         = realtek_i_dvbt2_common_DemodCtrlDetectCmd;
	pDemod->DemodCtrlRun                            = realtek_i_dvbt2_common_DemodCtrlRunCmd;
	pDemod->DemodCtrlUpdateRssi                     = realtek_i_dvbt2_common_DemodCtrlUpdateRssiCmd;
	pDemod->DemodCtrlResetCounters                  = realtek_i_dvbt2_common_DemodCtrlResetCountersCmd;
	pDemod->DemodCtrlUpdateCounters                 = realtek_i_dvbt2_common_DemodCtrlUpdateCountersCmd;
	pDemod->DemodCtrlSetAgc                         = realtek_i_dvbt2_common_DemodCtrlSetAgcCmd;
	pDemod->DemodCtrlUpdateAgc                      = realtek_i_dvbt2_common_DemodCtrlUpdateAgcCmd;
	pDemod->DemodCtrlQueryStatus                    = realtek_i_dvbt2_common_DemodCtrlQueryStatusCmd;

	pDemod->GetDemodStatus                          = realtek_i_dvbt2_common_GetDemodStatus;

	pDemod->SetTunerFreq                            = realtek_i_dvbt2_common_SetTunerFreqCmd;
	pDemod->SetTunerBandwidth                       = realtek_i_dvbt2_common_SetTunerBandwidth;
	pDemod->SetTunerGridBase                        = realtek_i_dvbt2_common_SetTunerGridBase;
	pDemod->SetTunerGridIncr                        = realtek_i_dvbt2_common_SetTunerGridIncr;
	pDemod->GetActiveTunerFreq                      = realtek_i_dvbt2_common_GetActiveTunerFreq;
	pDemod->GetActiveTunerBandwidth                 = realtek_i_dvbt2_common_GetActiveTunerBandwidth;
	pDemod->GetActiveTunerGain                      = realtek_i_dvbt2_common_GetActiveTunerGain;
	pDemod->GetActiveTunerRssi                      = realtek_i_dvbt2_common_GetActiveTunerRssi;

	pDemod->SetNotchFreq                            = realtek_i_dvbt2_common_SetNotchFreqCmd;
	pDemod->SetNotchBandwidth                       = realtek_i_dvbt2_common_SetNotchBandwidth;

	pDemod->SetAgcParams                            = realtek_i_dvbt2_common_SetAgcParams;
	pDemod->GetAgcParams                            = realtek_i_dvbt2_common_GetAgcParams;
	pDemod->SetTsConfig                             = realtek_i_dvbt2_common_SetTsConfig;
	pDemod->SetTsClkRateMargin                      = realtek_i_dvbt2_common_SetTsClkRateMargin;
	pDemod->SetTsClkRateMax                         = realtek_i_dvbt2_common_SetTsClkRateMax;
	pDemod->GetDemodLockTime                        = realtek_i_dvbt2_common_GetDemodLockTime;
	pDemod->GetDvbTDemodLockTime                    = realtek_i_dvbt2_common_GetDvbTDemodLockTime;

	pDemod->SetXmlTunerCfgOverride                  = realtek_i_dvbt2_common_SetXmlTunerCfgOverride;
	pDemod->SetXmlTunerGainCtrl	                = realtek_i_dvbt2_common_SetXmlTunerGainCtrl;
	pDemod->SetXmlFlags                             = realtek_i_dvbt2_common_SetXmlFlags;
	pDemod->SetXmlIfFreq                            = realtek_i_dvbt2_common_SetXmlIfFreq;
	pDemod->SetXmlPlftCfgOverride                   = realtek_i_dvbt2_common_SetXmlPlatformCfgOverride;
	pDemod->SetXmlIfClk                             = realtek_i_dvbt2_common_SetXmlIfClk;
	pDemod->SetXmlLdpcClk                           = realtek_i_dvbt2_common_SetXmlLdpcClk;
	pDemod->SetXmlUccClk                            = realtek_i_dvbt2_common_SetXmlUccClk;
	pDemod->SetXmlMcuClk                            = realtek_i_dvbt2_common_SetXmlMcuClk;

	pDemod->SetVirtualRegister                      = realtek_i_dvbt2_common_SetVirtualRegister;
	pDemod->GetVirtualRegister                      = realtek_i_dvbt2_common_GetVirtualRegister;
	pDemod->SetCtrlVirtualRegister                  = realtek_i_dvbt2_common_SetCtrlVirtualRegister;
	pDemod->GetCtrlVirtualRegister                  = realtek_i_dvbt2_common_GetCtrlVirtualRegister;
	pDemod->SetHwRegister                           = realtek_i_dvbt2_common_SetHwRegister;
	pDemod->GetHwRegister                           = realtek_i_dvbt2_common_GetHwRegister;

	pDemod->SetT2ProfileCmd                         = realtek_i_dvbt2_SetT2ProfileCmd;
	pDemod->SetDetectTimeCmd                        = realtek_i_dvbt2_SetDetectTimeCmd;
	pDemod->SetHoldOffTimeMs                        = realtek_i_dvbt2_SetHoldOffTimeMs;
	pDemod->GetSignalIndicator                      = realtek_i_dvbt2_GetSignalIndicator;
	pDemod->GetTsLockTime                           = realtek_i_dvbt2_GetTsLockTime;

	//DVBT/T2 Fast Scan Virtual Register[begin]
	pDemod->SetDvbT2DvbTSearchMode                  = realtek_i_dvbt2_SetDvbT2DvbTSearchMode;
	pDemod->SetP1SearchTimeout                      = realtek_i_dvbt2_SetP1SearchTimeout;
	pDemod->SetMinP1Cnt                             = realtek_i_dvbt2_SetMinP1Cnt;
	pDemod->SetDvbT2DvbtSearchTimeout               = realtek_i_dvbt2_SetDvbT2DvbTSearchTimeout;
	pDemod->SetDvbT2DvbtSearchUpdatePeriod          = realtek_i_dvbt2_SetDvbT2DvbTSearchUpdatePeriod;
	pDemod->SetDvbT2DvbtSearchDecisionTh1           = realtek_i_dvbt2_SetDvbT2DvbTSearchDecisionTh1;
	pDemod->SetDvbT2DvbtSearchDecisionTh2           = realtek_i_dvbt2_SetDvbT2DvbTSearchDecisionTh2;
	pDemod->SetDvbT2DvbTSearchResult                = realtek_i_dvbt2_SetDvbT2DvbTSearchResult;
	pDemod->GetDvbT2DvbTSearchResult                = realtek_i_dvbt2_GetDvbT2DvbTSearchResult;
	//DVBT/T2 Fast Scan Virtual Register[end]

	pDemod->SetDataPlpIdSelectCmd                   = realtek_i_dvbt2_SetDataPlpIdSelectCmd;
	pDemod->GetActiveDataPlpId                      = realtek_i_dvbt2_GetActiveDataPlpId;
	pDemod->GetNumDataPlps                          = realtek_i_dvbt2_GetNumDataPlps;
	pDemod->GetListOfDataPlps                       = realtek_i_dvbt2_GetListOfDataPlps;
	pDemod->GetDataPlpCodeRate                      = realtek_i_dvbt2_GetDataPlpCodeRate;
	pDemod->GetDataPlpModulation                    = realtek_i_dvbt2_GetDataPlpModulation;
	pDemod->SetSfoPpm                               = realtek_i_dvbt2_SetSfoPpm;
	pDemod->GetSfoPpm                               = realtek_i_dvbt2_GetSfoPpm;

	pDemod->SetDataErrorCountersCmd                 = realtek_i_dvbt2_SetDataErrorCountersCmd;
	pDemod->GetDataDecodedFrames                    = realtek_i_dvbt2_GetDataDecodedFrames;
	pDemod->GetDataLdpcStuckFrames                  = realtek_i_dvbt2_GetDataLdpcStuckFrames;
	pDemod->GetDataPlpLdpcUnstableFrames            = realtek_i_dvbt2_GetDataPlpLdpcUnstableFrames;
	pDemod->GetDataLdpcFramesWithParityFailure      = realtek_i_dvbt2_GetDataLdpcFramesWithParityFailure;
	pDemod->GetDataLdpcParityCheckFailure           = realtek_i_dvbt2_GetDataLdpcParityCheckFailure;
	pDemod->GetUncorrectableBchCws                  = realtek_i_dvbt2_GetUncorrectableBchCws;
	pDemod->GetCorrectedBchBytes                    = realtek_i_dvbt2_GetCorrectedBchBytes;
	pDemod->GetCorrectedBchBits                     = realtek_i_dvbt2_GetCorrectedBchBits;

	pDemod->SetCommonPlpErrorCounterCmd             = realtek_i_dvbt2_SetCommonPlpErrorCounterCmd;
	pDemod->GetCommonDecodedFrames                  = realtek_i_dvbt2_GetCommonDecodedFrames;
	pDemod->GetCommonLdpcStuckFrames                = realtek_i_dvbt2_GetCommonLdpcStuckFrames;
	pDemod->GetCommonLdpcUnstableFrames             = realtek_i_dvbt2_GetCommonLdpcUnstableFrames;
	pDemod->GetCommonLdpcFrameWithParityFailure     = realtek_i_dvbt2_GetCommonLdpcFrameWithParityFailure;
	pDemod->GetCommonLdcpParityCheckFailure         = realtek_i_dvbt2_GetCommonLdcpParityCheckFailure;
	pDemod->GetCommonBchUncorrectableCws            = realtek_i_dvbt2_GetCommonBchUncorrectableCws;
	pDemod->GetCommonBchCorrectedBytes              = realtek_i_dvbt2_GetCommonBchCorrectedBytes;
	pDemod->GetCommonBchCorrectedBits               = realtek_i_dvbt2_GetCommonBchCorrectedBits;

	pDemod->SetErrRateIntegPeriod                   = rdt2938_dvbt2_SetErrRateIntegPeriod;
	pDemod->GetErrRateIntegPeriod                   = realtek_i_dvbt2_GetErrRateIntegPeriod;
	pDemod->GetDataErrorRateUpdates                 = realtek_i_dvbt2_GetDataErrorRateUpdates;
	pDemod->GetDataLdpcOutputFer                    = realtek_i_dvbt2_GetDataLdpcOutputFer;
	pDemod->GetDataBchInputBer                      = realtek_i_dvbt2_GetDataBchInputBer;
	pDemod->GetDataBchOutputFer                     = realtek_i_dvbt2_GetDataBchOutputFer;
	pDemod->GetTsBadPackets                         = realtek_i_dvbt2_GetTsBadPackets;
	pDemod->GetSqi                                  = realtek_i_dvbt2_GetSqi;

	pDemod->GetCommonRateUpdate                     = realtek_i_dvbt2_GetCommonRateUpdate;
	pDemod->GetCommonLdpcInputBer                   = realtek_i_dvbt2_GetCommonLdpcInputBer;
	pDemod->GetCommonBchInputBer                    = realtek_i_dvbt2_GetCommonBchInputBer;
	pDemod->GetCommonBchOutputFer                   = realtek_i_dvbt2_GetCommonBchOutputFer;
	pDemod->GetSymStatusUpdates                     = realtek_i_dvbt2_GetSymStatusUpdates;
	pDemod->GetSymSymbolCount                       = realtek_i_dvbt2_GetSymSymbolCount;
	pDemod->GetSymFrameCount                        = realtek_i_dvbt2_GetSymFrameCount;
	pDemod->GetSymCsiSnr                            = realtek_i_dvbt2_GetSymCsiSnr;
	pDemod->GetSymNoiseVar                          = realtek_i_dvbt2_GetSymNoiseVar;
	pDemod->GetSymChannelDelaySpread                = realtek_i_dvbt2_GetSymChannelDelaySpread;
	pDemod->GetSsi                                  = realtek_i_dvbt2_GetSsi;

	pDemod->GetDataHem                              = realtek_i_dvbt2_GetDataHem;
	pDemod->GetDataIssyi                            = realtek_i_dvbt2_GetDataIssyi;
	pDemod->GetDataNpd                              = realtek_i_dvbt2_GetDataNpd;
	pDemod->GetDataVarDfl                           = realtek_i_dvbt2_GetDataVarDfl;
	pDemod->GetDataPackets                          = realtek_i_dvbt2_GetDataPackets;
	pDemod->GetDataBitRate                          = realtek_i_dvbt2_GetDataBitRate;
	pDemod->GetCommonHem                            = realtek_i_dvbt2_GetCommonHem;
	pDemod->GetCommonIssyi                          = realtek_i_dvbt2_GetCommonIssyi;
	pDemod->GetCommonNpd                            = realtek_i_dvbt2_GetCommonNpd;
	pDemod->GetCommonVarDfl                         = realtek_i_dvbt2_GetCommonVarDfl;
	pDemod->GetCommonPackets                        = realtek_i_dvbt2_GetCommonPackets;
	pDemod->GetCommonBitRate                        = realtek_i_dvbt2_GetCommonBitRate;

	pDemod->GetL1Info                               = realtek_i_dvbt2_GetL1Info;
	pDemod->SetConsBuffHostStatusCmd                = realtek_i_dvbt2_SetConsBuffHostStatusCmd;
	pDemod->GetConsBuffHostStatusCmd                = realtek_i_dvbt2_GetConsBuffHostStatusCmd;
	pDemod->GetConsBuffAddress                      = realtek_i_dvbt2_GetConsBuffAddress;
	pDemod->GetConsSampleNum                        = realtek_i_dvbt2_GetConsSampleNum;
	pDemod->GetDvbTTpsSyncResult                    = realtek_i_dvbt2_GetDvbTTpsSyncResult;
	pDemod->GetDvbTSsi                              = realtek_i_dvbt2_GetDvbTSsi;
	pDemod->GetDvbTSqi                              = realtek_i_dvbt2_GetDvbTSqi;
	pDemod->SetDvbTStatCtrl                         = realtek_i_dvbt2_SetDvbTStatCtrl;
	pDemod->GetDvbTSnr                              = realtek_i_dvbt2_GetDvbTSnr;
	pDemod->SetDvbTBerPeriod                        = realtek_i_dvbt2_SetDvbTBerPeriod;
	pDemod->GetDvbTRsBer                            = realtek_i_dvbt2_GetDvbTRsBer;
	pDemod->GetDvbTTsPer                            = realtek_i_dvbt2_GetDvbTTsPer;
	pDemod->GetDvbTTsBadPktCount                    = realtek_i_dvbt2_GetDvbTTsBadPktCount;
	pDemod->GetDvbTTunMod                           = realtek_i_dvbt2_GetDvbTTunMod;
	pDemod->GetDvbTTunCodeRate                      = realtek_i_dvbt2_GetDvbTTunCodeRate;
	pDemod->GetDvbTTsPktCnt                         = realtek_i_dvbt2_GetDvbTTsPktCnt;
	pDemod->GetDvbTCfo                              = realtek_i_dvbt2_GetDvbTCfo;
	pDemod->SetDvbTDetectMask                       = realtek_i_dvbt2_SetDvbTDetectMask;
	pDemod->GetIfAgcGain                            = realtek_i_dvbt2_GetIfAgcGain;
	pDemod->SetDvbTTunHierarchical                  = realtek_i_dvbt_SetTunHierarchical;
	pDemod->GetDvbTTunHierarchical                  = realtek_i_dvbt_GetTunHierarchical;

	return;
}


/*
T2 Profile Selection
This is a command register that enables the application to select the T2 profile to demodulate
*/
int
realtek_i_dvbt2_SetT2ProfileCmd(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int T2Profile
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	T2Profile &= DVBT2_BITFLD_SELECT_T2_PROFILE_CMD;

	if (MsgSetCmdReg(DVBT2_REG_SELECT_T2_PROFILE_CMD, 0, T2Profile) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Detection Time Selection
This is a command register that enables the application to select the maximum time for signal detection.
If there is no valid T2 signal detected during this period, the "signal not found" indicator below is set.
*/
int
realtek_i_dvbt2_SetDetectTimeCmd(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int DetectTime
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	DetectTime &= DVBT2_BITFLD_SELECT_DETECT_TIME_MS_CMD;

	if (MsgSetCmdReg(DVBT2_REG_SELECT_DETECT_TIME_MS_CMD, 0, DetectTime) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
This register is used to set a hold off period in ms. The hold off will delay the start of the scan or acquire process
*/
int
realtek_i_dvbt2_SetHoldOffTimeMs(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int HoldOffTimeMs
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	//HoldOffTimeMs &= DVBT2_BITFLD_HOLDOFF_MS;

	//if(MsgSetReg(DVBT2_REG_HOLDOFF_MS, 0, HoldOffTimeMs) != FUNCTION_SUCCESS)
	//goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
T2 signal presence inidcator
0:Unknow
1:T2 signal found
2:T2 signal not found
*/
int
realtek_i_dvbt2_GetSignalIndicator(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *SignalIndicator
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_SIGNAL_INDICATOR, 0, SignalIndicator) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*SignalIndicator &= DVBT2_BITFLD_SIGNAL_INDICATOR;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
TS Lock Time
This register indicates the Transport Stream lock time in milliseconds, the time between the detection of a T2 signal and the output of the first valid Transport Stream packets.
No TS lock is also reported.
A value of 0xffffffff inidcates no TS lock
*/
int
realtek_i_dvbt2_GetTsLockTime(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *TsLockTime
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_TS_LOCK_TIME_MS, 0, TsLockTime) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*TsLockTime &= DVBT2_BITFLD_TS_LOCK_TIME_MS;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
This register is used to select the mode of the signal-search.
Note that changing the value in this register does not issue a signal-search,
but it does affect the mode used on the next signal-search.
The default initial value of this register is DVBT2_DVBT_ALL.
Bits used to select the signal-search mode from the five available:
001 = DVBT2_PRIMARY_ONLY
010 = DVBT2_PRIMARY_AND_LOWER
011 = DVBT2_PRIMARY_AND_DVBT
100 = DVBT2_AND_DVBT
101 = DVBT2_DVBT_ALL
*/
int
realtek_i_dvbt2_SetDvbT2DvbTSearchMode(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int DvbT2DvbTSearchMode
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	DvbT2DvbTSearchMode &= DVBT2_BITFLD_DVBT_SEARCH_MODE;

	if (MsgSetReg(DVBT2_REG_DVBT_SEARCH_MODE, 0, DvbT2DvbTSearchMode) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
This register is used to set the time-out period, in milliseconds,
considered in the P1-symbol search. Updates of the P1 search time-out period
only become effective at the beginning of the next ACQUIRING state,
reached for instance, by issuing a RUN command.
The default initial value of this register is 500 ms.
*/
int
realtek_i_dvbt2_SetP1SearchTimeout(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int P1SearchTimeout
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	P1SearchTimeout &= DVBT2_BITFLD_P1SEARCH_TIMEOUT_MS;

	if (MsgSetReg(DVBT2_REG_P1SEARCH_TIMEOUT_MS, 0, P1SearchTimeout) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
This register is used to set the minimum number of P1 symbol detections necessary
to validate a DVB-T2 signal detection. Updates to the P1 minimum count only
become effective at the beginning of the next ACQUIRING state,
reached for instance, by issuing a RUN/DETECT command.
The default initial value of this register is 1.
*/
int
realtek_i_dvbt2_SetMinP1Cnt(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int MinP1Cnt
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	MinP1Cnt &= DVBT2_BITFLD_MIN_P1_COUNT;

	if (MsgSetReg(DVBT2_REG_MIN_P1_COUNT, 0, MinP1Cnt) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
This register is used to set the time-out period, in milliseconds,
considered in the DVB-T signal-search.
Updates of the DVB-T search time-out period only become effective at
the beginning of the next ACQUIRING state, reached for instance,
by issuing a RUN/DETECT command. The default initial value of this register is 250 ms.
*/
int
realtek_i_dvbt2_SetDvbT2DvbTSearchTimeout(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int DvbT2DvbtSearchTimeout
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	DvbT2DvbtSearchTimeout &= DVBT2_BITFLD_DVBTSEARCH_TIMEOUT_MS;

	if (MsgSetReg(DVBT2_REG_DVBTSEARCH_TIMEOUT_MS, 0, DvbT2DvbtSearchTimeout) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
This register is used to set the period, in milliseconds,
between updates of the DVB-T search results.
Changes to the DVB-T search update period only become effective
at the beginning of the next ACQUIRING state, reached for instance,
by issuing a RUN/DETECT command. The default initial value of this register is 125 ms.
*/
int
realtek_i_dvbt2_SetDvbT2DvbTSearchUpdatePeriod(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int DvbT2DvbtSearchUpdatePeriod
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	DvbT2DvbtSearchUpdatePeriod &= DVBT2_BITFLD_DVBTSEARCH_REFRESH_PERIOD_MS;

	if (MsgSetReg(DVBT2_REG_DVBTSEARCH_REFRESH_PERIOD_MS, 0, DvbT2DvbtSearchUpdatePeriod) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
This register is used to set the first decision threshold used in the DVB-T search.
Updates of threshold 1 only become effective at the beginning of the next ACQUIRING state,
reached for instance, by issuing a RUN/DETECT command.
The default initial value of this register is 4.5.
Bits defining the first relative threshold, expressed in unsigned Q 24.8 format,
used in the DVB-T signal-search.
*/
int
realtek_i_dvbt2_SetDvbT2DvbTSearchDecisionTh1(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int DvbT2DvbtSearchDecisionTh1
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	DvbT2DvbtSearchDecisionTh1 &= DVBT2_BITFLD_DVBT_DECISION_THRESHOLD_1;

	if (MsgSetReg(DVBT2_REG_DVBT_DECISION_THRESHOLD_1, 0, DvbT2DvbtSearchDecisionTh1) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
This register is used to set the second decision threshold used in the DVB-T search.
Updates of threshold 1 only become effective at the beginning of the next ACQUIRING state,
reached for instance, by issuing a RUN/DETECT command.
The default initial value of this register is 4.2.
Bits defining the second relative threshold, expressed in unsigned Q 24.8 format,
used in the DVB-T signal-search.
*/
int
realtek_i_dvbt2_SetDvbT2DvbTSearchDecisionTh2(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int DvbT2DvbtSearchDecisionTh2
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	DvbT2DvbtSearchDecisionTh2 &= DVBT2_BITFLD_DVBT_DECISION_THRESHOLD_2;

	if (MsgSetReg(DVBT2_REG_DVBT_DECISION_THRESHOLD_2, 0, DvbT2DvbtSearchDecisionTh2) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
This is a multi-valued register that shows the status and the results of the signal-search.
When a signal-search is running, the mode of that search is indicated in the signal-search status.
Once the search is concluded, this is indicated by the search status and the search-results are
updated. When a RUN or DETECT command is issued, the search-results in zeroed before
a new signal-search is performed.

DVBT2_REG_DVBT_SEARCH_STATUS 31:28
Bits indicating the signal-search status, which can be one of the following:
0001 = search running in mode DVBT2_PRIMARY_ONLY
0010 = search running in mode DVBT2_PRIMARY_AND_LOWER
0011 = search running in mode DVBT2_PRIMARY_AND_DVBT
0100 = search running in mode DVBT2_AND_DVBT
0101 = search running in mode DVBT2_DVBT_ALL
0110 = SEARCH_CONCLUDED

DVBT2_REG_DVBT_SEARCH_RESULTS 15:0
Bits of the signalSearchResult, indicating the DVB-T2 and DVB-T signal search results.
These are updated once the search status is SEARCH_CONCLUDED.
*/
int
realtek_i_dvbt2_SetDvbT2DvbTSearchResult(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int DvbT2DvbTSearchStatus,
	unsigned int DvbT2DvbTSearchResult
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	unsigned int TempVal = 0;

	TempVal |= (DVBT2_BITFLD_DVBT_SEARCH_STATUS & (DvbT2DvbTSearchStatus << 28));
	TempVal |= (DVBT2_BITFLD_DVBT_SEARCH_RESULTS & DvbT2DvbTSearchResult);

	if (MsgSetReg(DVBT2_REG_DVBT_SEARCH_RESULTS, 0, TempVal) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}

int
realtek_i_dvbt2_GetDvbT2DvbTSearchResult(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DvbT2DvbTSearchStatus,
	unsigned int *DvbT2DvbTSearchResult
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	unsigned int TempVal;

	if (MsgGetReg(DVBT2_REG_DVBT_SEARCH_RESULTS, 0, &TempVal) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*DvbT2DvbTSearchStatus = (TempVal & DVBT2_BITFLD_DVBT_SEARCH_STATUS) >> 28;
	*DvbT2DvbTSearchResult = TempVal & DVBT2_BITFLD_DVBT_SEARCH_RESULTS;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Data PLP ID Selection
This command register indicates the required PLP to be extracted from the T2 frame.
If it has an associated common PLP then this will also be extracted.
*/
int
realtek_i_dvbt2_SetDataPlpIdSelectCmd(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int DataPlpIdSelect
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	DataPlpIdSelect &= DVBT2_BITFLD_SELECT_DATA_PLP_ID_CMD;

	if (MsgSetCmdReg(DVBT2_REG_SELECT_DATA_PLP_ID_CMD, 0, DataPlpIdSelect) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Active Data PLP ID
This register indicates the data PLP actually being extracted from the T2 frame.
The active PLP_ID should reflect the one selected by the DVBT2_REG_SELECT_DATA_PLP_ID register.
But if the selected PLP_ID is invalid, the data PLP that was found first is extracted.
*/
int
realtek_i_dvbt2_GetActiveDataPlpId(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *ActiveDataPlpId
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_ACTIVE_DATA_PLP_ID, 0, ActiveDataPlpId) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*ActiveDataPlpId &= DVBT2_BITFLD_ACTIVE_DATA_PLP_ID;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Number of Data PLPs
This register indicates the number of data PLPs carried in the T2 signal.
*/
int
realtek_i_dvbt2_GetNumDataPlps(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *NumDataPlps
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_NUM_DATA_PLP, 0, NumDataPlps) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*NumDataPlps &= DVBT2_BITFLD_NUM_DATA_PLP;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
List of Data PLPs
This is a multivalued register accessing the list of information for all data PLPs.
There are DVBT2_REG_NUM_DATA_PLP valid data PLPs and DVBT2_REG_SELECT_DATA_PLP_ID_CMD should be selected from this list.
The data PLP info reported are PLP_ID, PLP_TYPE and PLP_PAYLOAD_TYPE as defined in [2].
*/
int
realtek_i_dvbt2_GetListOfDataPlps(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int PlpLoopIdx,
	unsigned int *PayloadType,
	unsigned int *PlpType,
	unsigned int *PlpId
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	unsigned int TempVal;

	if (MsgGetReg(DVBT2_REG_DATA_PLP_LIST, PlpLoopIdx, &TempVal) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*PayloadType = (TempVal & DVBT2_BITFLD_DATA_PLP_PAYLOAD_TYPE) >> 11;
	*PlpType = (TempVal & DVBT2_BITFLD_DATA_PLP_TYPE) >> 8;
	*PlpId = TempVal & DVBT2_BITFLD_DATA_PLP_ID;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Get Data Plp Code Rate
*/
int
realtek_i_dvbt2_GetDataPlpCodeRate(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataPlpCodeRate
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_DATA_PLP_COD, 0, DataPlpCodeRate) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*DataPlpCodeRate &= DVBT2_BITFLD_DATA_PLP_COD;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Get Data Plp Modulation
*/
int
realtek_i_dvbt2_GetDataPlpModulation(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataPlpModulation
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_DATA_PLP_MOD, 0, DataPlpModulation) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*DataPlpModulation &= DVBT2_BITFLD_DATA_PLP_MOD;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
SFO Calibration Setting
This register containing the SFO value in ppm and Q16.15 format for the system.
The value of this register is initially used to calibrate the SCP resampler and the system is periodically updating it during the steady state
*/
int
realtek_i_dvbt2_SetSfoPpm(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int SfoPpmQ16_15
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	SfoPpmQ16_15 &= DVBT2_BITFLD_DATA_SFOPPM_Q16_15;

	if (MsgSetReg(DVBT2_REG_SFOPPM_Q16_15, 0, SfoPpmQ16_15) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


int
realtek_i_dvbt2_GetSfoPpm(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *SfoPpmQ16_15
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_SFOPPM_Q16_15, 0, SfoPpmQ16_15) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*SfoPpmQ16_15 &= DVBT2_BITFLD_DATA_SFOPPM_Q16_15;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Data PLP Error Counters Update and Reset
This is a command register that uses the same protocol as TV_REG_CONTROL.
It supports the updating and resetting of the error counters.
*/
int
realtek_i_dvbt2_SetDataErrorCountersCmd(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int DataErrorCount
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	DataErrorCount &= DVBT2_BITFLD_DATA_ERROR_COUNTERS_CMD;

	if (MsgSetCmdReg(DVBT2_REG_DATA_ERROR_COUNTERS_CMD, 0, DataErrorCount) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Number of Data PLP Decoded Frames
This register indicates the number of LDPC decoded baseband frames for the selected data PLP.
*/
int
realtek_i_dvbt2_GetDataDecodedFrames(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataDecodedFrames
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_DATA_DECODED_FRAMES, 0, DataDecodedFrames) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*DataDecodedFrames &= DVBT2_BITFLD_DATA_DECODED_FRAMES;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Number of Data PLP Frames Stuck in LDPC Decoding
This register indicates the number of LDPC stuck frames for the selected data PLP.
*/
int
realtek_i_dvbt2_GetDataLdpcStuckFrames(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataLdpcStuckFrames
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_DATA_LDPC_STUCK_FRAMES, 0, DataLdpcStuckFrames) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*DataLdpcStuckFrames &= DVBT2_BITFLD_DATA_LDPC_STUCK_FRAMES;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Number of Data PLP Frames Unstable in LDPC Decoding
This register indicates the number of LDPC unstable frames for the selected data PLP.
*/
int
realtek_i_dvbt2_GetDataPlpLdpcUnstableFrames(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataLdpcUnstableFrames
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_DATA_LDPC_UNSTABLE_FRAMES, 0, DataLdpcUnstableFrames) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*DataLdpcUnstableFrames &= DVBT2_BITFLD_DATA_LDPC_UNSTABLE_FRAMES;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Number of Data PLP Frames with LDPC Parity Failures
This register indicates the number of LDPC frames with parity failure for the selected data PLP.
*/
int
realtek_i_dvbt2_GetDataLdpcFramesWithParityFailure(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataLdpcFramesWithParityFailure
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_DATA_LDPC_FRAMES_WITH_PARITY_FAILURE, 0, DataLdpcFramesWithParityFailure) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*DataLdpcFramesWithParityFailure &= DVBT2_BITFLD_DATA_LDPC_FRAMES_WITH_PARITY_FAILURE;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Number of LDPC Parity Failures for Data PLP
This register indicates the number of LDPC parity check failures for the selected data PLP.
*/
int
realtek_i_dvbt2_GetDataLdpcParityCheckFailure(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataLdpcParityCheckFailure
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_DATA_LDPC_PARITY_CHECK_FAILURES, 0, DataLdpcParityCheckFailure) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*DataLdpcParityCheckFailure &= DVBT2_BITFLD_DATA_LDPC_PARITY_CHECK_FAILURES;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Number of Data PLP Uncorrectable BCH Codewords
This register indicates the number of LDPC parity check failures for the selected data PLP.
*/
int
realtek_i_dvbt2_GetUncorrectableBchCws(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *UncorrectableBchCws
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_DATA_BCH_UNCORRECTABLE_CWS, 0, UncorrectableBchCws) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*UncorrectableBchCws &= DVBT2_BITFLD_DATA_BCH_UNCORRECTABLE_CWS;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Number of BCH Corrected Bytes for Data PLP
This register indicates the number of BCH uncorrectable code words for the selected data PLP.
*/
int
realtek_i_dvbt2_GetCorrectedBchBytes(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CorrectedBchBytes
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_DATA_BCH_CORRECTED_BYTES, 0, CorrectedBchBytes) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*CorrectedBchBytes &= DVBT2_BITFLD_DATA_BCH_CORRECTED_BYTES;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Number of BCH Corrected Bits for Data PLP
This register indicates the number of BCH corrected bits for the selected data PLP.
*/
int
realtek_i_dvbt2_GetCorrectedBchBits(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CorrectedBchBits
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_DATA_BCH_CORRECTED_BITS, 0, CorrectedBchBits) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*CorrectedBchBits &= DVBT2_BITFLD_DATA_BCH_CORRECTED_BITS;


	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Common PLP Error Counters Update and Reset
This is a command register that uses the same protocol as TV_REG_CONTROL.
It supports the updating and resetting of the error counters.
*/
int
realtek_i_dvbt2_SetCommonPlpErrorCounterCmd(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int CommonPlpErrorCounter
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	CommonPlpErrorCounter &= DVBT2_BITFLD_COMMON_ERROR_COUNTERS_CMD;

	if (MsgSetCmdReg(DVBT2_REG_COMMON_ERROR_COUNTERS_CMD, 0, CommonPlpErrorCounter) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Number of Common PLP Decoded Frames
This register indicates the number of LDPC decoded baseband frames for the associated common PLP.
*/
int
realtek_i_dvbt2_GetCommonDecodedFrames(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonDecodedFrames
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_COMMON_DECODED_FRAMES, 0, CommonDecodedFrames) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;
	*CommonDecodedFrames &= DVBT2_BITFLD_COMMON_DECODED_FRAMES;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Number of Common PLP Frames Stuck in LDPC Decoding
This register indicates the number of LDPC stuck frames for the associated common PLP.
*/
int
realtek_i_dvbt2_GetCommonLdpcStuckFrames(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonLdpcStuckFrames
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_COMMON_LDPC_STUCK_FRAMES, 0, CommonLdpcStuckFrames) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*CommonLdpcStuckFrames &= DVBT2_BITFLD_COMMON_LDPC_STUCK_FRAMES;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Number of Common PLP Frames Unstable in LDPC Decoding
This register indicates the number of LDPC unstable frames for the associated common PLP.
*/
int
realtek_i_dvbt2_GetCommonLdpcUnstableFrames(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonLdpcUnstableFrames
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_COMMON_LDPC_UNSTABLE_FRAMES, 0, CommonLdpcUnstableFrames) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*CommonLdpcUnstableFrames &= DVBT2_BITFLD_COMMON_LDPC_UNSTABLE_FRAMES;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Number of Common PLP Frames with LDPC Parity Failures
This register indicates the number of LDPC frames with parity failure for the associated common PLP.
*/
int
realtek_i_dvbt2_GetCommonLdpcFrameWithParityFailure(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonLDPCFrameWithParityFailure
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_COMMON_LDPC_FRAMES_WITH_PARITY_FAILURE, 0, CommonLDPCFrameWithParityFailure) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*CommonLDPCFrameWithParityFailure &= DVBT2_BITFLD_COMMON_LDPC_FRAMES_WITH_PARITY_FAILURE;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Number of LDPC Parity Failures for Common PLP
This register indicates the number of LDPC parity check failures for the associated common PLP.
*/
int
realtek_i_dvbt2_GetCommonLdcpParityCheckFailure(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonLDPCParityCheckFailure
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_COMMON_LDPC_PARITY_CHECK_FAILURES, 0, CommonLDPCParityCheckFailure) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*CommonLDPCParityCheckFailure &= DVBT2_BIYFLD_COMMON_LDPC_PARITY_CHECK_FAILURES;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Number of Common PLP Uncorrectable BCH Codewords
This register indicates the number of BCH uncorrectable code words for the associated common PLP.
*/
int
realtek_i_dvbt2_GetCommonBchUncorrectableCws(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonBchUncorrectableCws
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_COMMON_BCH_UNCORRECTABLE_CWS, 0, CommonBchUncorrectableCws) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*CommonBchUncorrectableCws &= DVBT2_BITFLD_COMMON_BCH_UNCORRECTABLE_CWS;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Number of BCH Corrected Bytes for Common PLP
This register indicates the number of BCH corrected bytes for the associated common PLP.
*/
int
realtek_i_dvbt2_GetCommonBchCorrectedBytes(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonBchCorrectedByte
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_COMMON_BCH_CORRECTED_BYTES, 0, CommonBchCorrectedByte) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*CommonBchCorrectedByte &= DVBT2_BITFLD_COMMON_BCH_CORRECTED_BYTES;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Number of BCH Corrected Bits for Common PLP
This register indicates the number of BCH corrected bits for the associated common PLP.
*/
int
realtek_i_dvbt2_GetCommonBchCorrectedBits(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonBchCorrectedBit
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_COMMON_BCH_CORRECTED_BITS, 0, CommonBchCorrectedBit) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*CommonBchCorrectedBit &= DVBT2_BITFLD_COMMON_BCH_CORRECTED_BITS;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Error Rate Integration Period
This register indicates the number of seconds over which the following error rates are calculated.
This is applicable to both data and common PLP error rates.
*/
int
rdt2938_dvbt2_SetErrRateIntegPeriod(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int ErrRateIntegPeriod
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	ErrRateIntegPeriod &= DVBT2_BITFLD_ERROR_RATES_INTEGRATION_PERIOD;

	if (MsgSetReg(DVBT2_REG_ERROR_RATES_INTEGRATION_PERIOD, 0, ErrRateIntegPeriod) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


int
realtek_i_dvbt2_GetErrRateIntegPeriod(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *ErrRateIntegPeriod
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_ERROR_RATES_INTEGRATION_PERIOD, 0, ErrRateIntegPeriod) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*ErrRateIntegPeriod &= DVBT2_BITFLD_ERROR_RATES_INTEGRATION_PERIOD;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Number of Data PLP Error Rate Updates
This register indicates the number of times the error rates for the data PLP have been updated.
*/
int
realtek_i_dvbt2_GetDataErrorRateUpdates(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataErrorRateUpdate
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_DATA_ERROR_RATES_UPDATES, 0, DataErrorRateUpdate) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*DataErrorRateUpdate &= DVBT2_BITFLD_DATA_ERROR_RATES_UPDATES;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Data PLP LDPC Output FER
This register indicates the LDPC output frame error rate (LPDC frames with parity failure/decoded frames) for the selected data PLP.
*/
int
realtek_i_dvbt2_GetDataLdpcOutputFer(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataLdpcOutputFer
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_DATA_LDPC_OUTPUT_FER_Q32, 0, DataLdpcOutputFer) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*DataLdpcOutputFer &= DVBT2_BITFLD_DATA_LDPC_OUTPUT_FER_Q32;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Data PLP BCH Input BER
This register indicates the BCH bit error rate (BCH corrected bits/ number of bits in BCH correctable frames) for the selected data PLP.
This is a measure of the BER at the BCH input for the correctable frames, or the BER in the LDPC output for the BCH correctable frames.
*/
int
realtek_i_dvbt2_GetDataBchInputBer(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataBchInputBer
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_DATA_BCH_INPUT_BER_Q32, 0, DataBchInputBer) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*DataBchInputBer &= DVBT2_BITFLD_DATA_BCH_INPUT_BER_Q32;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Data PLP BCH Output FER
This register indicates the BCH output frame error rate (BCH uncorrectable frames/ LDPC decoded frames) for the selected data PLP.
*/
int
realtek_i_dvbt2_GetDataBchOutputFer(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataBchcOutputFer
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_DATA_BCH_OUTPUT_FER_Q32, 0, DataBchcOutputFer) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*DataBchcOutputFer &= DVBT2_BITFLD_DATA_BCH_OUTPUT_FER_Q32;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}

int
realtek_i_dvbt2_GetTsBadPackets(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataTsBadPackets
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_TS_BAD_PACKETS, 0, DataTsBadPackets) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*DataTsBadPackets &= DVBT2_BITFLD_TS_BAD_PACKETS;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Signal Quality Indicator
This register indicates the Signal Quality Indicator as per the Nordig specification
*/
int
realtek_i_dvbt2_GetSqi(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *Sqi
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_DATA_SQI, 0, Sqi) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	if (*Sqi == -1) {
		REALTEK_I_DVBT2_BASE_INFO("*Sqi == -1\n");
		REALTEK_I_DVBT2_BASE_INFO("*Sqi == -1\n");
		*Sqi = 0;
	} else {
		*Sqi &= DVBT2_BITFLD_DATA_SQI;
	}

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Common PLP Error Rate Updates
This register indicates the number of times the error rates for the common PLP have been updated.
*/
int
realtek_i_dvbt2_GetCommonRateUpdate(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonRateUpdate
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_COMMON_ERROR_RATES_UPDATES, 0, CommonRateUpdate) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*CommonRateUpdate &= DVBT2_BITFLD_COMMON_ERROR_RATES_UPDATES;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Common PLP LDPC bit error rate
This register indicates the LDPC bit error rate (LPDC parity failures/decoded bits) in the associated common PLP.
The parity failures are the number of bits not corrected by the LDPC across the whole frame.
This is not a measure of the raw bit errors at the input to the LDPC.
*/
int
realtek_i_dvbt2_GetCommonLdpcInputBer(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonLdpcInputBer
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_COMMON_LDPC_INPUT_BER_Q32, 0, CommonLdpcInputBer) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*CommonLdpcInputBer &= DVBT2_BITFLD_COMMON_LDPC_INPUT_BER_Q32;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Common PLP BCH Input BER
This register indicates the BCH bit error rate (BCH corrected bits/ number of bits in BCH correctable frames) for the associated common PLP.
This is a measure of the BER at the BCH input for the correctable frames, or the BER in the LDPC output for the BCH correctable frames.
*/
int
realtek_i_dvbt2_GetCommonBchInputBer(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonBchInputBer
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_COMMON_BCH_INPUT_BER_Q32, 0, CommonBchInputBer) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*CommonBchInputBer &= DVBT2_BITFLD_COMMON_BCH_INPUT_BER_Q32;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Common PLP BCH Output FER
This register indicates the BCH output frame error rate (BCH uncorrectable frames/ LDPC decoded frames)
for the associated common PLP.
*/
int
realtek_i_dvbt2_GetCommonBchOutputFer(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonBchOutputFer
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_COMMON_BCH_OUTPUT_FER_Q32, 0, CommonBchOutputFer) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*CommonBchOutputFer &= DVBT2_BITFLD_COMMON_BCH_OUTPUT_FER_Q32;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Number of Symbol Manager Status Updates
This register indicates the number of times the status registers for the symbol manager have been updated.
*/
int
realtek_i_dvbt2_GetSymStatusUpdates(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *SymStatusUpdate
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_SYM_STATUS_UPDATES, 0, SymStatusUpdate) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*SymStatusUpdate &= DVBT2_BITFLD_SYM_STATUS_UPDATES;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Number of Demodulated Symbols
This register indicates the status of the symbol manager symbol counter.
*/
int
realtek_i_dvbt2_GetSymSymbolCount(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *SymSymbolCount
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_SYM_SYMBOL_COUNT, 0, SymSymbolCount) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*SymSymbolCount &= DVBT2_BITFLD_SYM_SYMBOL_COUNT;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Number of Demodulated T2-Frames
This register indicates the status of the symbol manager frame counter.
*/
int
realtek_i_dvbt2_GetSymFrameCount(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *SymSymbolCount
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_SYM_FRAME_COUNT, 0, SymSymbolCount) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*SymSymbolCount &= DVBT2_BITFLD_SYM_FRAME_COUNT;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Symbol Manager Channel State Information Measure
This register indicates the status of the symbol manager CSI (channel state information).
*/
int
realtek_i_dvbt2_GetSymCsiSnr(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *SymCsiSnr
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_SYM_CSI_DB_Q16_15, 0, SymCsiSnr) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*SymCsiSnr &= DVBT2_BITFLD_SYM_CSI_DB_Q16_15;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Symbol Manager Noise Variance Measure
This register indicates the status of the symbol manager noise variance measure.
*/
int
realtek_i_dvbt2_GetSymNoiseVar(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *SymNoiseVar
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_SYM_NOISE_VAR_DB_Q16_15, 0, SymNoiseVar) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*SymNoiseVar &= DVBT2_BITFLD_SYM_NOISE_VAR_DB_Q16_15;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Symbol Manager Delay Spread Measure
This register indicates the approximate channel delay spread measured in baseband symbols.
*/
int
realtek_i_dvbt2_GetSymChannelDelaySpread(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *SymChannelDelaySpread
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_SYM_CHANNEL_DELAY_SPREAD, 0, SymChannelDelaySpread) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*SymChannelDelaySpread &= DVBT2_BITFLD_SYM_CHANNEL_DELAY_SPREAD;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Signal Strength Indicator
This register indicates the approximate channel delay spread measured in baseband symbols.
*/
int
realtek_i_dvbt2_GetSsi(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *SymSsi
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_SSI, 0, SymSsi) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*SymSsi &= DVBT2_BITFLD_SSI;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Data PLP High Efficiency Mode
This register indicates the Input Processing High Efficiency Mode [2] for the associated Data PLP.
*/
int
realtek_i_dvbt2_GetDataHem(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataHem
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_DATA_HEM, 0, DataHem) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*DataHem &= DVBT2_BITFLD_DATA_HEM;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Data PLP ISSY Indicator
This register indicates Input Stream Synchronisation for the associated Data PLP.
*/
int
realtek_i_dvbt2_GetDataIssyi(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataIssyi
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_DATA_ISSYI, 0, DataIssyi) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*DataIssyi &= DVBT2_BITFLD_DATA_ISSYI;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Data PLP NPD Indicator
This register indicates Null Packet Deletion for the associated Data PLP.
*/
int
realtek_i_dvbt2_GetDataNpd(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataNpd
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_DATA_NPD, 0, DataNpd) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*DataNpd &= DVBT2_BITFLD_DATA_NPD;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Data PLP Variable DFL Indicator
This register indicates the Data Field Length is variable and ISSY not used for the associated Data PLP.
*/
int
realtek_i_dvbt2_GetDataVarDfl(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataBarDfl
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_DATA_VAR_DFL, 0, DataBarDfl) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*DataBarDfl &= DVBT2_BITFLD_DATA_VAR_DFL;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Number of Data PLP Processed Packets
This register indicates the number of packets output by the system for the associated Data PLP.
*/
int
realtek_i_dvbt2_GetDataPackets(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataPackets
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_DATA_PACKETS, 0, DataPackets) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*DataPackets &= DVBT2_BITFLD_DATA_PACKETS;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Data PLP Estimated Bit Rate
This register indicates the estimated bit rate for the associated Data PLP. It is in units of bits per sample and in Q3.29 format.
*/
int
realtek_i_dvbt2_GetDataBitRate(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataBitRate
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_DATA_BITRATE_Q3_29, 0, DataBitRate) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*DataBitRate &= DVBT2_BITFLD_DATA_BITRATE_Q3_29;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Common PLP High Efficiency Mode
This register indicates the Input Processing High Efficiency Mode [2] for the associated Common PLP.
*/
int
realtek_i_dvbt2_GetCommonHem(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonHem
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_COMMON_HEM, 0, CommonHem) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*CommonHem &= DVBT2_BITFLD_COMMON_HEM;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Common PLP ISSY Indicator
This register indicates Input Stream Synchronisation for the associated Common PLP.
*/
int
realtek_i_dvbt2_GetCommonIssyi(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonIssyi
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_COMMON_ISSYI, 0, CommonIssyi) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*CommonIssyi &= DVBT2_BITFLD_COMMON_ISSYI;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Common PLP NPD Indicator
This register indicates Null Packet Deletion for the associated Common PLP.
*/
int
realtek_i_dvbt2_GetCommonNpd(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonNpd
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_COMMON_NPD, 0, CommonNpd) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*CommonNpd &= DVBT2_BITFLD_COMMON_NPD;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Common PLP Variable DFL Indicator
This register indicates the Data Field Length is variable and ISSY not used for the associated Common PLP.
*/
int
realtek_i_dvbt2_GetCommonVarDfl(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonVarDfl
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_COMMON_VAR_DFL, 0, CommonVarDfl) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*CommonVarDfl &= DVBT2_BITFLD_COMMON_VAR_DFL;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Number of Common PLP Processed Packets
This register indicates the number of packets output by the system for the associated Common PLP.
*/
int
realtek_i_dvbt2_GetCommonPackets(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonPackets
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_COMMON_PACKETS, 0, CommonPackets) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*CommonPackets &= DVBT2_BITFLD_COMMON_PACKETS;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Common PLP Estimated Bit Rate
This register indicates the estimated bit rate for the associated Common PLP. It is in units of bits per sample and in Q3.29 format.
*/
int
realtek_i_dvbt2_GetCommonBitRate(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonBitRate
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_COMMON_BITRATE_Q3_29, 0, CommonBitRate) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*CommonBitRate &= DVBT2_BITFLD_COMMON_BITRATE_Q3_29;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Layer 1 Signalling Information Bits
This is a multivalued register describing the Layer 1 Signalling Bits.
*/
int
realtek_i_dvbt2_GetL1Info(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *L1Info
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_L1_INFO, 0, L1Info) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*L1Info &= DVBT2_BITFLD_L1_INFO;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Constellation Buffer Status For Host
This register holds the status of the constellation buffer as seen from the HOST side.
It is written and read by both the HOST and UCCP controller applications.
The constellation buffer is used to transfer constellation samples from the UCCP controller to the HOST.
The UCCP controller can only write to the buffer when the value of the register is DVBT2_CONSTELLATION_HOST_COPY_COMPLETE. On completion of the buffer write, the UCCP writes DVBT2_CONSTELLATION_HOST_DATA_AVAILABLE to the register.
The HOST queries the register status and read samples only if it sees DVBT2_CONSTELLATION_HOST_DATA_AVAILABLE.
On completion of the buffer read, it will write DVBT2_CONSTELLATION_HOST_COPY_COMPLETE to the register.
Having noticed this, the UCCP controller will be able to write again to the shared buffer.
0=DVBT2_CONSTELLATION_HOST_COPY_COMPLETE
1=DVBT2_CONSTELLATION_HOST_DATA_AVAILABLE
*/
int
realtek_i_dvbt2_SetConsBuffHostStatusCmd(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int ConsBuffHostStatus
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	ConsBuffHostStatus &= DVBT2_BITFLD_CONSTELLATION_BUFFER_HOST_STATUS_CMD;

	if (MsgSetReg(DVBT2_REG_CONSTELLATION_BUFFER_HOST_STATUS_CMD, 0, ConsBuffHostStatus) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


int
realtek_i_dvbt2_GetConsBuffHostStatusCmd(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *ConsBuffHostStatus
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_CONSTELLATION_BUFFER_HOST_STATUS_CMD, 0, ConsBuffHostStatus) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*ConsBuffHostStatus &= DVBT2_BITFLD_CONSTELLATION_BUFFER_HOST_STATUS_CMD;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Constellation Buffer Address
This register contains the address of the constellation buffer in the UCCP controller memory.
The register is set by the UCCP at start-up.
There is currently a 1:1 mapping of the UCCP memory to HOST memory space.
In case this is not true, either the HOST or the UCCP controller will have to map the two address spaces.
*/
int
realtek_i_dvbt2_GetConsBuffAddress(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *ConsBuffHostAddress
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_CONSTELLATION_BUFFER_ADDRESS, 0, ConsBuffHostAddress) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*ConsBuffHostAddress &= DVBT2_REG_CONSTELLATION_BUFFER_ADDRESS;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/*
Number of Constellation Samples To Copy
This register contains the amount of samples which will be copied by the host (after the Meta written them to the shared buffer).
The samples are 32 bit words which contain the IQ components with 12 bits each. Note that the Q component is before the I component.
*/
int
realtek_i_dvbt2_GetConsSampleNum(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *ConsSampleNum
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT2_REG_CONSTELLATION_SAMPLE_NUMBER, 0, ConsSampleNum) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*ConsSampleNum &= DVBT2_BITFLD_CONSTELLATION_SAMPLE_NUMBER;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


int
realtek_i_dvbt2_GetDvbTTpsSyncResult(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DvbTTpsSyncRst
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(0x8016, 0, DvbTTpsSyncRst) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*DvbTTpsSyncRst &= 0x00000001;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


int
realtek_i_dvbt2_GetDvbTSsi(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DvbTSsi
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(0x800D, 0, DvbTSsi) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	*DvbTSsi &= 0x000000FF;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


int
realtek_i_dvbt2_GetDvbTSqi(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DvbTSqi
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(0x801F, 0, DvbTSqi) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	if (*DvbTSqi == -1) {
		REALTEK_I_DVBT2_BASE_INFO("*DvbTSqi == -1\n");
		REALTEK_I_DVBT2_BASE_INFO("*DvbTSqi == -1\n");
		REALTEK_I_DVBT2_BASE_INFO("*DvbTSqi == -1\n");
		REALTEK_I_DVBT2_BASE_INFO("*DvbTSqi == -1\n");
		*DvbTSqi = 0;
	} else {
		*DvbTSqi &= 0x000000FF;
	}

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


int
realtek_i_dvbt2_SetDvbTStatCtrl(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int StatCtrl
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	StatCtrl &= 0x00000001;

	if (MsgSetCmdReg(0x800B, 0, StatCtrl) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


int
realtek_i_dvbt2_GetDvbTSnr(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *StatSnr
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(0x800E, 0, StatSnr) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*StatSnr &= 0xFFFFFFFF;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}

int
realtek_i_dvbt2_SetDvbTBerPeriod(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int BerPeriod
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	BerPeriod &= 0x000000FF;

	if (MsgSetReg(0x801B, 0, BerPeriod) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


int
realtek_i_dvbt2_GetDvbTRsBer(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *BerRsBer
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(0x801D, 0, BerRsBer) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*BerRsBer &= 0xFFFFFFFF;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


int
realtek_i_dvbt2_GetDvbTTsPer(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *BerTsPer
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(0x801E, 0, BerTsPer) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*BerTsPer &= 0xFFFFFFFF;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


int
realtek_i_dvbt2_GetDvbTTsBadPktCount(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *StatTsBadPktCount
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(0x8011, 0, StatTsBadPktCount) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*StatTsBadPktCount &= 0xFFFFFFFF;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


int
realtek_i_dvbt2_GetDvbTTunMod(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *TunMod
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(0x8003, 0, TunMod) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*TunMod &= 0x00000003;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


int
realtek_i_dvbt2_GetDvbTTunCodeRate(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *TunCodeRate
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(0x8004, 0, TunCodeRate) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*TunCodeRate &= 0x00000007;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


int
realtek_i_dvbt2_GetDvbTTsPktCnt(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *TsPktCnt
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(0x8010, 0, TsPktCnt) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*TsPktCnt &= 0xFFFFFFFF;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


int
realtek_i_dvbt2_GetDvbTCfo(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *Cfo
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(0x800F, 0, Cfo) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*Cfo &= 0xFFFFFFFF;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


int
realtek_i_dvbt2_SetDvbTDetectMask(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int DetectMask
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgSetReg(0x8000, 0, DetectMask) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


int
realtek_i_dvbt2_GetIfAgcGain(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *IfAgcGain
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (GetHwRegValue(0x02041090, IfAgcGain) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/*
Select whether to demodulate the high priority or low-priority stream.
*/
int
realtek_i_dvbt_SetTunHierarchical(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int TunHierarchical
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	TunHierarchical &= DVBT_BITFLD_TUN_HIERARCHICAL;

	if (MsgSetReg(DVBT_REG_TUN_HIERARCHICAL, 0, TunHierarchical) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}

int
realtek_i_dvbt_GetTunHierarchical(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *TunHierarchical
)
{
	REALTEK_I_DVBT2_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);

	if (MsgGetReg(DVBT_REG_TUN_HIERARCHICAL, 0, TunHierarchical) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	*TunHierarchical &= DVBT_BITFLD_TUN_HIERARCHICAL;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}

