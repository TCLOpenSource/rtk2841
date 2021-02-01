#ifndef __DVBS_DEMOD_REALTEK_I_H
#define __DVBS_DEMOD_REALTEK_I_H

#include "dvbs_demod_base.h"

#ifdef __cplusplus
extern "C" {
#endif

// DVBS Virtual Register Address/Mask
//#define DVBS_REG_BAUD_RATE                                      0x8000
    #define DVBS_BITFLD_BAUD_RATE                       0xFFFFFFFF
//#define DVBS_REG_CODE_RATE                                      0x8001
    #define DVBS_BITFLD_CODE_RATE                       0x00000007
//#define DVBS_REG_ACTIVE_BAUD_RATE                               0x8002
    #define DVBS_BITFLD_ACTIVE_BAUD_RATE                0xFFFFFFFF
//#define DVBS_REG_ACTIVE_CODE_RATE                               0x8003
    #define DVBS_BITFLD_ACTIVE_CODE_RATE                0x00000007
//#define DVBS_REG_BER_AT_VITERBI_INPUT                           0x8004
    #define DVBS_BITFLD_BER_AT_VITERBI_INPUT            0xFFFFFFFF
//#define DVBS_REG_BER_AT_RS_INPUT                                0x8005
    #define DVBS_BITFLD_BER_AT_RS_INPUT                 0xFFFFFFFF
//#define DVBS_REG_PER_AT_OUTPUT                                  0x8006
    #define DVBS_BITFLD_PER_AT_OUTPUT                   0xFFFFFFFF
//#define DVBS_REG_NUM_SECONDS_BER_AVERAGING                      0x8007
    #define DVBS_BITFLD_NUM_SECONDS_BER_AVERAGING       0x0000001F
//#define DVBS_REG_TS_PACKET_COUNT                                0x8008
    #define DVBS_BITFLD_TS_PACKET_COUNT                 0xFFFFFFFF
//#define DVBS_REG_BAD_PACKET_COUNT                               0x8009
    #define DVBS_BITFLD_BAD_PACKET_COUNT                0xFFFFFFFF
//#define DVBS_REG_BIT_RATE                                       0x800A
    #define DVBS_BITFLD_BIT_RATE                        0xFFFFFFFF
//#define DVBS_REG_SNR_ESTIMATE                                   0x800B
    #define DVBS_BITFLD_SNR_ESTIMATE                    0xFFFFFFFF
//#define DVBS_CARRIER_FREQ_SEARCH_RANGE                          0x800C
    #define DVBS_BITFLD_CARRIER_FREQ_SEARCH_RANGE       0xFFFFFFFF
//#define DVBS_SYMBOL_RATE_SEARCH_RANGE                           0x800D
    #define DVBS_BITFLD_SYMBOL_RATE_SEARCH_RANGE        0xFFFFFFFF
//#define DVBS_REG_ACQUISITION_STATE                              0x800E
    #define DVBS_BITFLD_ACQUISITION_STATE               0x0000001F
//#define DVBS_REG_NUM_ACQUISITIONS                               0x800F
    #define DVBS_BITFLD_NUM_ACQUISITIONS                0xFFFFFFFF
//#define DVBS_REG_ACQUISITION_FAILURE_CODE                       0x8010
    #define DVBS_BITFLD_ACQUISITION_FAILURE_CODE        0x0000000F
//#define DVBS_REG_ERROR_CODE                                     0x8011
    #define DVBS_BITFLD_TUNING_TIMEOUT                  0x00000080
    #define DVBS_BITFLD_TIMER_CONFIG_ERROR              0x00000010
    #define DVBS_BITFLDLOOP_PROC_UNDERRUN_ERROR         0x00000008
    #define DVBS_BITFLD_SCP_IP_SYNCHRONISER_OFLOW_ERROR 0x00000004
    #define SCP_TBUS_OFLOW_ERROR                        0x00000002
    #define BAUD_RATE_RANGE_ERROR                       0x00000001
//#define DVBS_REG_I_AMP                                          0x8012
    #define DVBS_BITFLD_I_AMP                           0x00000FFF
//#define DVBS_REG_Q_AMP                                          0x8013
    #define DVBS_BITFLD_Q_AMP                           0x00000FFF
//#define DVBS_REG_ANALOG_GAIN                                    0x8014
    #define DVBS_BITFLD_ANALOG_GAIN                     0x0000FFFF
//#define DVBS_REG_DIGITAL_GAIN                                   0x8015
    #define DVBS_BITFLD_DIGITAL_GAIN_I                  0xFFFF0000
    #define DVBS_BITFLD_DIGITAL_GAIN_Q                  0x0000FFFF
//#define DVBS_REG_ACQUISITION_TIME                               0x8016
    #define DVBS_BITFLD_ACQUISITION_TIME                0xFFFFFFFF
//#define DVBS_REG_CARRIER_FREQ_OFFSET                            0x8017
    #define DVBS_BITFLD_CARRIER_FREQ_OFFSET             0xFFFFFFFF
//#define DVBS_REG_CTRL                                           0x8018
    #define DVBS_BITFLD_RESET_METRICS_ON_REACQUISITION  0x00000002
    #define DVBS_BITFLD_DFE_COEFFS_CONTROL_MODE         0x00000001
//#define DVBS_REG_MANUAL_DFE_COEFFS00                            0x8019
    #define DVBS_BITFLD_DFE_COEFF_REAL_n                0xFFFF0000
    #define DVBS_BITFLD_DFE_COEFF_IMAG_n                0x0000FFFF
//#define DVBS_REG_SPECTRUM_INVERSION                             0x8029
    #define DVBS_BITFLD_SPECTRUM_INVERSION              0x00000003
//#define DVBS_REG_ACTIVE_SPECTRUM_INVERSION                      0x802A
    #define DVBS_BITFLD_ACTIVE_SPECTRUM_INVERSION       0x00000003
//#define DVBS_REG_TONE_DETECT_CTRL                               0x802B
    #define DVBS_BITFLD_TONE_DETECT_ENABLE              0x00010000
    #define DVBS_BITFLD_TONE_DETECT_ENABLE_PSD          0x00008000
    #define DVBS_BITFLD_TONE_DETECT_PERIOD              0x00007F00
    #define DVBS_BITFLD_TONE_DETECT_THRESHOLD           0x000000FF
//#define DVBS_REG_TONE_DETECT_VALUE                              0x802C
    #define DVBS_BITFLD_TONE_DETECT_CTRL_CHANGE         0xFF000000
    #define DVBS_BITFLD_TONE_DETECT_PEAK_IDX            0x00FF8000
    #define DVBS_BITFLD_TONE_DETECT_PEAK_RATIO          0x00007FFF
//#define DVBS_REG_PHASE_TRACK_STATE                              0x802D
    #define DVBS_BITFLD_DFE_PHASE_TRACKING_MODE                     0xF0000000
    #define DVBS_BITFLD_DFE_PHASE_TRACKER_GAIN_CONTROL              0x0F000000
    #define DVBS_BITFLD_DFE_PHASE_TRACKER_MEAN_SQUARED_PHASE_ERROR  0x00FFFFFF
//#define DVBS_REG_PHASE_TRACK_CTRL                               0x802E
    #define DVBS_BITFLD_PHASE_TRACK_GAIN_ENABLE         0x80000000
    #define DVBS_BITFLD_PHASE_TRACK_CLIP_LEVEL_ENABLE   0x40000000
    #define DVBS_BITFLD_PHASE_TRACK_CORE_LEVEL          0x0FFF0000
    #define DVBS_BITFLD_PHASE_TRACK_CLIP_LEVEL          0x0000FFF0
    #define DVBS_BITFLD_PHASE_TRACK_GAIN_NEG_SHIFT      0x0000000F
//#define DVBS_REG_TUNED_FREQ_OFFSET                              0x802F
    #define DVBS_BITFLD_TUNED_FREQ_OFFSET               0xFFFFFFFF
//#define DVBS_REG_TUNE_REQUEST                                   0x8030
    #define DVBS_BITFLD_TUNE_REQUEST                    0xFFFFFFFF
//#define DVBS_REG_BW_REQUEST                                     0x8031
    #define DVBS_BITFLD_BW_REQUEST                      0xFFFFFFFF
//#define DVBS_REG_DEBUG_PTR                                      0x8032
    #define DVBS_BITFLD_DEBUG_PTR                       0xFFFFFFFF
//#define DVBS_REG_META_LOG_PTR                                   0x8033
    #define DVBS_BITFLD_META_LOG_PTR                    0xFFFFFFFF
//#define DVBS_REG_MCP_LOG_PTR                                    0x8034
    #define DVBS_BITFLD_MCP_LOG_PTR                     0xFFFFFFFF
//#define DVBS_REG_TRACE_BUFF_PTR                                 0x8035
    #define DVBS_BITFLD_TRACE_BUFF_PTR                  0xFFFFFFFF


//Spectrum Analyzer
//#define SA_SCAN_RANGE                                           0x8000
    #define SA_BITFLD_SCAN_RANGE                        0xFFFFFFFF
//#define SA_SCAN_RESOLUTION                                      0x8001
    #define SA_BITFLD_SCAN_RESOLUTION                   0xFFFFFFFF
//#define SA_TUNING_STEP                                          0x8002
    #define SA_BITFLD_TUNING_STEP_AUTO                  0x80000000
    #define SA_BITFLD_TUNING_STEP                       0x7FFFFFFF
//#define SA_MEASUREMENT_CONTROL                                  0x8003
    #define SA_BITFLD_ENABLE_DC_COMP                    0x00000200
    #define SA_BITFLD_WINDOW                            0x000001C0
    #define SA_BITFLD_SIGNAL_TYPE                       0x00000038
    #define SA_BITFLD_MAX_PEAK_WIDTH                    0x00000007
//#define SA_AVERAGING_PERIOD                                     0x8004
    #define SA_BITFLD_AVERAGING_PERIOD_M                0x0000FF00
    #define SA_BITFLD_AVERAGING_PERIOD_N                0x000000FF
//#define SA_IF_GAIN_OVERRIDE                                     0x8005
    #define SA_BITFLD_OVERRIDE_IF_GAIN                  0x00010000
    #define SA_BITFLD_IF_GAIN                           0x0000FFFF
//#define SA_TUNER_3DB_POINT                                      0x8006
    #define SA_BITFLD_TUNER_3DB_POINT                   0xFFFFFFFF
//#define SA_TUNER_6DB_POINT                                      0x8007
    #define SA_BITFLD_TUNER_6DB_POINT                   0xFFFFFFFF
//#define SA_TUNER_9DB_POINT                                      0x8008
    #define SA_BITFLD_TUNER_9DB_POINT                   0xFFFFFFFF
//#define SA_TUNER_12DB_POINT                                     0x8009
    #define SA_BITFLD_TUNER_12DB_POINT                  0xFFFFFFFF
//#define SA_REG_OUT_SPECTRUM_PTR                                 0x800A
    #define SA_BITFLD_OUT_SPECTRUM_MEM_TYPE             0xC0000000
    #define SA_BITFLD_OUT_SPECTRUM_PTR                  0x3FFFFFFF
//#define SA_OUT_SPECTRUM_LEN                                     0x800B
    #define SA_BITFLD_OUT_SPECTRUM_LEN                  0xFFFFFFFF
//#define SA_MAX_RSSI_REG                                         0x800C
    #define SA_BITFLD_MAX_RSSI                          0xFFFF0000
    #define SA_BITFLD_MAX_RSSI_INDEX                    0x0000FFFF
//#define SA_REF_IF_GAIN_REG                                      0x800D
    #define SA_BITFLD_REF_IF_GAIN_REG                   0xFFFFFFFF
//#define SA_MAX_POWER_REG_00                                     0x800E
//#define SA_MAX_POWER_REG_01                                     0x800F
//#define SA_MAX_POWER_REG_02                                     0x8010
//#define SA_MAX_POWER_REG_03                                     0x8011
//#define SA_MAX_POWER_REG_04                                     0x8012
//#define SA_MAX_POWER_REG_05                                     0x8013
//#define SA_MAX_POWER_REG_06                                     0x8014
//#define SA_MAX_POWER_REG_07                                     0x8015
    #define SA_BITFLD_SA_MAX_POWER                      0x00FF0000
    #define SA_BITFLD_MAX_POWER_INDEX                   0x0000FFFF
//#define SA_FAILURE_CODE                                         0x8016
    #define SA_BITFLD_SCAN_SIZE_EXCEEDS_AVAILABLE_MEMORY 0x00000001
//#define SA_COMPLETION_PERCENT                                   0x8017
    #define SA_BITFLD_COMPLETION_PERCENT                0x000000FF

// Builder
void
BuildRealtekIDvbsModule(
	DVBS_DEMOD_MODULE **ppDemod,
	DVBS_DEMOD_MODULE *pDvbSDemodModuleMemory,
	BASE_INTERFACE_MODULE *pBaseInterfaceModuleMemory,
	I2C_BRIDGE_MODULE *pI2cBridgeModuleMemory,
	unsigned char DeviceAddr,
	unsigned long CrystalFreqHz
);

// DVBS Virtual Register
int
realtek_i_dvbs_SetBaudRate(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int BaudRate
);

int
realtek_i_dvbs_GetBaudRate(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *BaudRate
);

int
realtek_i_dvbs_SetCodeRate(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int CodeRate
);

int
realtek_i_dvbs_GetCodeRate(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *CodeRate
);

int
realtek_i_dvbs_GetActiveBaudRate(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *ActiveBaudRate
);

int
realtek_i_dvbs_GetActiveCodeRate(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *ActiveCodeRate
);

int
realtek_i_dvbs_GetBerAtViterbiInput(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *BerAtViterbiInput
);

int
realtek_i_dvbs_GetBerAtRsInput(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *BerAtRsInput
);

int
realtek_i_dvbs_GetPerAtOutput(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *PerAtOutput
);

int
realtek_i_dvbs_SetNumSecBerAvg(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int NumSecBerAvg
);

int
realtek_i_dvbs_GetNumSecBerAvg(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *NumSecBerAvg
);

int
realtek_i_dvbs_GetTsPacketCount(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *TsPacketCount
);

int
realtek_i_dvbs_GetBadPacketCount(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *BadPacketCount
);

int
realtek_i_dvbs_GetBitRate(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *BitRate
);

int
realtek_i_dvbs_GetSnrEstimate(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *SnrEstimate
);

int
realtek_i_dvbs_SetCarrierFreqSearchRange(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int CarrierFreqSearchRange
);

int
realtek_i_dvbs_GetCarrierFreqSearchRange(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *CarrierFreqSearchRange
);

int
realtek_i_dvbs_SetSymbolRateSearchRange(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int SymbolRateSearchRange
);

int
realtek_i_dvbs_GetSymbolRateSearchRange(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *SymbolRateSearchRange
);

int
realtek_i_dvbs_GetAcquisitionState(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *AcquisitionState
);

int
realtek_i_dvbs_SetNumAcquisitions(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int NumAcquisitions
);

int
realtek_i_dvbs_GetNumAcquisitions(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *NumAcquisitions
);

int
realtek_i_dvbs_GetAcqFailureCode(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *AcqFailureCode
);

int
realtek_i_dvbs_SetDemodErrorCode(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int DemodErrorCode
);

int
realtek_i_dvbs_GetDemodErrorCode(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *DemodErrorCode
);

int
realtek_i_dvbs_GetIAmp(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *IAmp
);

int
realtek_i_dvbs_GetQAmp(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *QAmp
);

int
realtek_i_dvbs_GetAnalogGain(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *AnalogGain
);

int
realtek_i_dvbs_GetDigitalGain(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *DigitalGain
);

int
realtek_i_dvbs_GetAcquisitionTime(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *AcquisitionTime
);

int
realtek_i_dvbs_GetCarrierFreqOffset(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *CarrierFreqOffset
);

int
realtek_i_dvbs_SetPhyCtrl(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int DemodPhyCtrl
);

int
realtek_i_dvbs_GetPhyCtrl(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *DemodPhyCtrl
);

int
realtek_i_dvbs_SetManualDfeCoeff(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int ManualDfeCoeff
);

int
realtek_i_dvbs_GetManualDfeCoeff(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *ManualDfeCoeff
);

int
realtek_i_dvbs_SetSpectrumInversion(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int SpectrumInversion
);

int
realtek_i_dvbs_GetSpectrumInversion(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *SpectrumInversion
);

int
realtek_i_dvbs_SetActiveSpectrumInversion(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int ActiveSpectrumInversion
);

int
realtek_i_dvbs_GetActiveSpectrumInversion(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *ActiveSpectrumInversion
);

int
realtek_i_dvbs_SetToneDetectCtrl(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int ToneDetectCtrl
);

int
realtek_i_dvbs_GetToneDetectValue(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *ToneDetectValue
);

int
realtek_i_dvbs_SetDfePhaseTrackerState(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int DfePhaseTrackerState
);

int
realtek_i_dvbs_GetDfePhaseTrackerState(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *DfePhaseTrackerState
);

int
realtek_i_dvbs_GetPhaseTrackCtrl(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *PhaseTrackCtrl
);

int
realtek_i_dvbs_SetTunedFreqOffset(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int TunedFreqOffset
);

int
realtek_i_dvbs_GetTunedFreqOffset(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *TunedFreqOffset
);

int
realtek_i_dvbs_SetTunerFreqRequest(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int TunerFreqRequest
);

int
realtek_i_dvbs_GetTunerFreqRequest(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *TunerFreqRequest
);

int
realtek_i_dvbs_SetTunerBwRequest(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int TunerBwRequest
);

int
realtek_i_dvbs_GetTunerBwRequest(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *TunerBwRequest
);

int
realtek_i_dvbs_SetMetaLogDebugPtr(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int MetaLogDebugPtr
);

int
realtek_i_dvbs_GetMetaLogDebugPtr(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *MetaLogDebugPtr
);

int
realtek_i_dvbs_SetMetaLogPtr(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int MetaLogPtr
);

int
realtek_i_dvbs_GetMetaLogPtr(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *MetaLogPtr
);

int
realtek_i_dvbs_SetMcpLogPtr(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int McpLogPtr
);

int
realtek_i_dvbs_GetMcpLogPtr(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *McpLogPtr
);

int
realtek_i_dvbs_SetDcpLogPtr(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int DcpLogPtr
);

int
realtek_i_dvbs_GetDcpLogPtr(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *DcpLogPtr
);

int
realtek_i_dvbs_GetIfAgcGain(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *IfAgcGain
);

//Spectrum Analyzer
int
realtek_i_SpecAn_DvbSSetSpecAnScanRange(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int ScanRange
);

int
realtek_i_SpecAn_DvbSGetSpecAnScanRange(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *ScanRange
);

int
realtek_i_SpecAn_DvbSSetSpecAnScanResolution(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int ScanResolution
);

int
realtek_i_SpecAn_DvbSGetSpecAnScanResolution(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *ScanResolution
);

int
realtek_i_SpecAn_DvbSSetSpecAnTuningStep(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int TuningStepAuto,
	unsigned int TuningStep
);

int
realtek_i_SpecAn_DvbSGetSpecAnTuningStep(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *TuningStepAuto,
	unsigned int *TuningStep
);

int
realtek_i_SpecAn_DvbSSetSpecAnMeasureCtrl(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int EnDcComp,
	unsigned int Window,
	unsigned int SignalType,
	unsigned int MaxPickWidth
);

int
realtek_i_SpecAn_DvbSGetSpecAnMeasureCtrl(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *EnDcComp,
	unsigned int *Window,
	unsigned int *SignalType,
	unsigned int *MaxPickWidth
);

int
realtek_i_SpecAn_DvbSSetSpecAnAveragePeriod(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int AveragePeriodM,
	unsigned int AveragePeriodN
);

int
realtek_i_SpecAn_DvbSGetSpecAnAveragePeriod(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *AveragePeriodM,
	unsigned int *AveragePeriodN
);

int
realtek_i_SpecAn_DvbSSetSpecAnIfGainOverride(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int OverrideIfGain,
	unsigned int IfGain
);

int
realtek_i_SpecAn_DvbSGetSpecAnIfGainOverride(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *OverrideIfGain,
	unsigned int *IfGain
);

int
realtek_i_SpecAn_DvbSSetSpecAnTuner3dBPoint(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int FreqSpacing
);

int
realtek_i_SpecAn_DvbSSetSpecAnTuner6dBPoint(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int FreqSpacing
);

int
realtek_i_SpecAn_DvbSSetSpecAnTuner9dBPoint(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int FreqSpacing
);

int
realtek_i_SpecAn_DvbSSetSpecAnTuner12dBPoint(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int FreqSpacing
);

int
realtek_i_SpecAn_DvbSGetSpecAnOutSpectrumPtr(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *OutSpecMemType,
	unsigned int *SpecMemPtr
);

int
realtek_i_SpecAn_DvbSGetSpecAnOutSpectrumLen(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *OutSpecLen
);

int
realtek_i_SpecAn_DvbSGetSpecAnMaxRssi(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *MaxRssi,
	unsigned int *MaxRssiIdx
);

int
realtek_i_SpecAn_DvbSGetSpecAnRefIfGain(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *RefIfGain
);

int
realtek_i_SpecAn_DvbSGetSpecAnMaxPwr(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int Number,
	unsigned int *MaxPwrDb,
	unsigned int *MaxPwrindex
);

int
realtek_i_SpecAn_DvbSGetSpecAnFailureCode(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *OutOfMem
);

int
realtek_i_SpecAn_DvbSGetSpecAnCompletionPercent(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *CompPercent
);

#ifdef __cplusplus
}
#endif
#endif
