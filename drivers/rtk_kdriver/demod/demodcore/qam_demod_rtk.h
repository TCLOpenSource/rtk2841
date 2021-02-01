#ifndef __QAM_DEMOD_REALTEK_I_H
#define __QAM_DEMOD_REALTEK_I_H

#include "qam_demod_base.h"

#ifdef __cplusplus
extern "C" {
#endif

// QAM Specific Register Address/Mask
//#define CABLE_REG_SYSTEM_STATE                           	0x8000 //Read Only
    #define CABLE_BITFLD_SYSTEM_STATE            			0x00000007
//#define CABLE_REG_CCS_STATE                           		0x8001 //Read Only
    #define CABLE_BITFLD_CCS_STATE            				0x00000007
//#define CABLE_REG_EQADAPT_STATE                           	0x8002 //Read Only
    #define CABLE_BITFLD_EQADAPT_STATE            			0x00000007
//#define CABLE_REG_SIGNAL_NOT_FOUND                          0x8003 //Read Only
    #define CABLE_BITFLD_SIGNAL_NOT_FOUND            		0x00000001
//#define CABLE_REG_SYM_RATE_MON                           	0x8004 //Read Only
    #define CABLE_BITFLD_SYM_RATE_MON            			0xFFFFFFFF
//#define CABLE_REG_CARR_FREQ_MON                           	0x8005 //Read Only
    #define CABLE_BITFLD_CARR_FREQ_MON            			0xFFFFFFFF
//#define CABLE_REG_QAM_MON                           		0x8006 //Read Only
    #define CABLE_BITFLD_QAM_MON            				0x00000007
//#define CABLE_REG_SPEC_INV_MON                           	0x8007 //Read Only
    #define CABLE_BITFLD_SPEC_INV_MON            			0x00000001
//#define CABLE_REG_INTL_MODE                           		0x8008 //Read Only
    #define CABLE_BITFLD_INTL_MODE            				0x0000000F
//#define CABLE_REG_AQUISITION_TIME                           0x8009 //Read Only
    #define CABLE_BITFLD_AQUISITION_TIME            		0xFFFFFFFF
//#define CABLE_REG_AQUISITION_TIME_RESET                     0x800A //Read/Write
    #define CABLE_BITFLD_AQUISITION_TIME_RESET            	0x00000001
//#define CABLE_REG_EQ_SNR_DB                           		0x800B //Read Only
    #define CABLE_BITFLD_EQ_SNR_DB            				0x0000FFFF
//#define CABLE_REG_NUM_PKTS                           		0x800C //Read Only
    #define CABLE_BITFLD_NUM_PKTS            				0xFFFFFFFF
//#define CABLE_REG_NUM_BADPKTS                           	0x800D //Read Only
    #define CABLE_BITFLD_NUM_BADPKTS            			0xFFFFFFFF
//#define CABLE_REG_NUM_BYTE_ERRS                           	0x800E //Read Only
    #define CABLE_BITFLD_NUM_BYTE_ERRS            			0xFFFFFFFF
//#define CABLE_REG_NUM_BIT_ERRS                           	0x800F //Read Only
    #define CABLE_BITFLD_NUM_BIT_ERRS            			0xFFFFFFFF
//#define CABLE_REG_NUM_SECS_BER_AVERAGE                      0x8010 //Read Only
    #define CABLE_BITFLD_NUM_SECS_BER_AVERAGE            	0x0000001F
//#define CABLE_REG_RS_AVERAGE_BER                           	0x8011 //Read Only
    #define CABLE_BITFLD_RS_AVERAGE_BER            			0xFFFFFFFF
//#define CABLE_REG_RS_AVERAGE_PER                           	0x8012 //Read Only
    #define CABLE_BITFLD_RS_AVERAGE_PER            			0xFFFFFFFF
//#define CABLE_REG_EQ_AVERAGE_SNR                           	0x8013 //Read Only
    #define CABLE_BITFLD_EQ_AVERAGE_SNR            			0xFFFFFFFF
//#define CABLE_REG_FAILURE_COUNTERS_RESET                    0x8014 //Read/Write
    #define CABLE_BITFLD_FAILURE_COUNTERS_RESET            	0x00000001
//#define CABLE_REG_NUM_COARSE_SYMTIM_FAILURE                 0x8015 //Read Only
    #define CABLE_BITFLD_NUM_COARSE_SYMTIM_FAILURE          0xFFFFFFFF
//#define CABLE_REG_NUM_FINE_SYMTIM_FAILURE                   0x8016 //Read Only
    #define CABLE_BITFLD_NUM_FINE_SYMTIM_FAILURE            0xFFFFFFFF
//#define CABLE_REG_NUM_CARRSYNC_FAILURE                      0x8017 //Read Only
    #define CABLE_BITFLD_NUM_CARRSYNC_FAILURE            	0xFFFFFFFF
//#define CABLE_REG_NUM_CDI_MODE_FAILURE                      0x8018 //Read Only
    #define CABLE_BITFLD_NUM_CDI_MODE_FAILURE            	0xFFFFFFFF
//#define CABLE_REG_NUM_SPECINV_SEARCH_FAILURE                0x8019 //Read Only
    #define CABLE_BITFLD_NUM_SPECINV_SEARCH_FAILURE         0xFFFFFFFF
//#define CABLE_REG_NUM_TS_RATE_FAILURE                       0x801A //Read Only
    #define CABLE_BITFLD_NUM_TS_RATE_FAILURE            	0xFFFFFFFF
//#define CABLE_REG_NUM_PER_FAILURE                           0x801B //Read Only
    #define CABLE_BITFLD_NUM_PER_FAILURE            		0xFFFFFFFF
//#define CABLE_REG_NUM_SIGNAL_DROPOUT_FAILURE                0x801C //Read Only
    #define CABLE_BITFLD_NUM_SIGNAL_DROPOUT_FAILURE         0xFFFFFFFF
//#define CABLE_REG_LAST_FAILURE                           	0x801D //Read Only
    #define CABLE_BITFLD_LAST_FAILURE            			0xFFFFFFFF
//#define CABLE_REG_CORE_CLK                           		0x801E //Read/Write
    #define CABLE_BITFLD_CORE_CLK            				0xFFFFFFFF
//#define CABLE_REG_QAM_SEARCH_ENABLE                         0x801F //Read/Write
    #define CABLE_BITFLD_QAM_SEARCH_ENABLE            		0x00000001
//#define CABLE_REG_QAM_FIXED                           		0x8020 //Read/Write
    #define CABLE_BITFLD_QAM_FIXED            				0x00000007
//#define CABLE_REG_SPECINV_SEARCH_ENABLE                     0x8021 //Read/Write
    #define CABLE_BITFLD_SPECINV_SEARCH_ENABLE            	0x00000001
//#define CABLE_REG_SPECTRUM_INVERSION                        0x8022 //Read/Write
    #define CABLE_BITFLD_SPECTRUM_INVERSION            		0x00000001
//#define CABLE_REG_BYTE_ERR_BADPKTS                          0x8023 //Read/Write
    #define CABLE_BITFLD_BYTE_ERR_BADPKTS            		0xFFFFFFFF
//#define CABLE_REG_BIT_ERR_BADPKTS                           0x8024 //Read/Write
    #define CABLE_BITFLD_BIT_ERR_BADPKTS            		0xFFFFFFFF
//#define CABLE_REG_PERCENT_BADPKTS_BADSET                    0x8025 //Read/Write
    #define CABLE_BITFLD_PERCENT_BADPKTS_BADSET            	0x00000003
//#define CABLE_REG_SER_FAILURE                           	0x8026 //Read/Write
    #define CABLE_BITFLD_SER_FAILURE            			0xFFFFFFFF
//#define CABLE_REG_INTL_LEVEL                           		0x8027 //Read/Write
    #define CABLE_BITFLD_INTL_LEVEL            				0x00000001
//#define CABLE_REG_PTGAIN_64QAM                           	0x8028 //Read/Write
    #define CABLE_BITFLD_PTGAIN_64QAM            			0x0000001F
//#define CABLE_REG_PTGAIN_256QAM                           	0x8029 //Read/Write
    #define CABLE_BITFLD_PTGAIN_256QAM            			0x0000001F
//#define CABLE_REG_TUNE_DAGC_POWER                           0x802A //Read/Write
    #define CABLE_BITFLD_TUNE_DAGC_POWER            		0x00FFFFFF
//#define CABLE_REG_TUNE_EQ_UPDATE_STEPSIZE                   0x802B //Read/Write
    #define CABLE_BITFLD_TUNE_EQ_UPDATE_STEPSIZE            0x00FFFFFF
//#define CABLE_REG_CST_PEAK_TO_MEAN_THRESHOLD  				0x802C
	#define CABLE_BITFLD_CST_PEAK_TO_MEAN_THRESHOLD         0x00FFFFFF

	
// QAM Demod Builder
void
BuildRealtekIQamModule(
	QAM_DEMOD_MODULE **ppDemod,
	QAM_DEMOD_MODULE *pQamDemodModuleMemory,
	BASE_INTERFACE_MODULE *pBaseInterfaceModuleMemory,
	I2C_BRIDGE_MODULE *pI2cBridgeModuleMemory,
	unsigned char DeviceAddr,
	unsigned long CrystalFreqHz
);


// QAM Specific Register
int
realtek_i_qam_GetSystemStateMachine(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *SystemStateMachine
);


int
realtek_i_qam_GetCoarseCarrierSyncSubState(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *CoarseCarrierSyncSubState
);


int
realtek_i_qam_GetEqAdaptSubState(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *EqAdaptSubState
);


int
realtek_i_qam_GetIsNoSignal(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *IsNoSignal
);


int
realtek_i_qam_GetSymbolRateMonitor(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *SymbolRateMonitor
);


int
realtek_i_qam_GetCarrierFrequencyMonitor(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *CarrierFrequencyMonitor
);


int
realtek_i_qam_GetQamSizeMonitor(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *QamSizeMonitor
);


int
realtek_i_qam_GetSpectrumInversionMonitor(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *SpectrumInversionMonitor
);


int
realtek_i_qam_GetInterleaverMode(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *InterleaverMode
);


int
realtek_i_qam_GetAcquisitionTime(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *AcquisitionTime
);


int
realtek_i_qam_SetAcquisitionTimeReset(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int AcquisitionTimeReset
);


int
realtek_i_qam_GetAcquisitionTimeReset(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *AcquisitionTimeReset
);


int
realtek_i_qam_GetEqOutputSnr(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *EqOutputSnr
);


int
realtek_i_qam_GetMpegTsPacketNumber(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *MpegTsPacketNumber
);


int
realtek_i_qam_GetBadPacketNumber(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *BadPacketNumber
);


int
realtek_i_qam_GetByteErrorNumber(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *ByteErrorNumber
);


int
realtek_i_qam_GetBitErrorNumber(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *BitErrorNumber
);


int
realtek_i_qam_SetBerAveLength(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int BerAveLength
);


int
realtek_i_qam_GetBerAveLength(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *BerAveLength
);


int
realtek_i_qam_GetRsAveBer(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *RsAveBer
);


int
realtek_i_qam_GetRsAvePer(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *RsAvePer
);


int
realtek_i_qam_GetEqAveSnr(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *EqAveSnr
);


int
realtek_i_qam_SetFailureCounterReset(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int FailureCounterReset
);


int
realtek_i_qam_GetFailureCounterReset(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *FailureCounterReset
);


int
realtek_i_qam_GetCoarseSymbolTimingFailureNumber(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *CoarseSymbolTimingFailureNumber
);


int
realtek_i_qam_GetFineSymbolTimingFailureNumber(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *FineSymbolTimingFailureNumber
);


int
realtek_i_qam_GetCarrierSyncFailureNumber(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *CarrierSyncFailureNumber
);


int
realtek_i_qam_GetUnSupportedCdiModeFailureNumber(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *UnSupportedCdiModeFailureNumber
);


int
realtek_i_qam_GetSpectrumInversionSearchFailureNumber(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *SpectrumInversionSearchFailureNumber
);


int
realtek_i_qam_GetUnSupportedTsRateFailureNumber(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *UnSupportedTsRateFailureNumber
);


int
realtek_i_qam_GetPerFailureNumber(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *PerFailureNumber
);


int
realtek_i_qam_GetSignalDropoutFailureNumber(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *SignalDropoutFailureNumber
);


int
realtek_i_qam_GetLastFailureCase(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *LastFailureCase
);


int
realtek_i_qam_SetCoreClockRate(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int CoreClockRate
);


int
realtek_i_qam_GetCoreClockRate(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *CoreClockRate
);


int
realtek_i_qam_SetQamSearchEnable(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int QamSearchEnable
);


int
realtek_i_qam_GetQamSearchEnable(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *QamSearchEnable
);


int
realtek_i_qam_SetFixedQamSize(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int FixedQamSize
);


int
realtek_i_qam_GetFixedQamSize(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *FixedQamSize
);


int
realtek_i_qam_SetSpectrumInversionSearchEnable(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int SpectrumInversionSearchEnable
);


int
realtek_i_qam_GetSpectrumInversionSearchEnable(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *SpectrumInversionSearchEnable
);


int
realtek_i_qam_SetSpectrumInversionEnable(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int SpectrumInversionEnable
);


int
realtek_i_qam_GetSpectrumInversionEnable(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *SpectrumInversionEnable
);


int
realtek_i_qam_SetByteErrorInBadPacketNumber(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int ByteErrorInBadPacketNumber
);


int
realtek_i_qam_GetByteErrorInBadPacketNumber(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *ByteErrorInBadPacketNumber
);


int
realtek_i_qam_SetBitErrorInBadPacketNumber(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int BitErrorInBadPacketNumber
);


int
realtek_i_qam_GetBitErrorInBadPacketNumber(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *BitErrorInBadPacketNumber
);


int
realtek_i_qam_SetBadPacketInBadSetPercentage(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int BadPacketInBadSetPercentage
);


int
realtek_i_qam_GetBadPacketInBadSetPercentage(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *BadPacketInBadSetPercentage
);


int
realtek_i_qam_SetFailureSetErrorRate(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int FailureSetErrorRate
);


int
realtek_i_qam_GetFailureSetErrorRate(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *FailureSetErrorRate
);


int
realtek_i_qam_SetInterleaverLevel(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int InterleaverLevel
);


int
realtek_i_qam_GetInterleaverLevel(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *InterleaverLevel
);


int
realtek_i_qam_SetPhaseTrackerLoopGain64Qam(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int PhaseTrackerLoopGain64Qam
);


int
realtek_i_qam_GetPhaseTrackerLoopGain64Qam(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *PhaseTrackerLoopGain64Qam
);


int
realtek_i_qam_SetPhaseTrackerLoopGain256Qam(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int PhaseTrackerLoopGain256Qam
);


int
realtek_i_qam_GetPhaseTrackerLoopGain256Qam(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *PhaseTrackerLoopGain256Qam
);


int
realtek_i_qam_SetDagcTargetPower(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int DagcTargetPower
);


int
realtek_i_qam_GetDagcTargetPower(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *DagcTargetPower
);


int
realtek_i_qam_SetEqUpdateRate(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int EqUpdateRate
);


int
realtek_i_qam_GetEqUpdateRate(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *EqUpdateRate
);


int
realtek_i_qam_SetCstPeakToMeanThreshold(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int CstPeakToMeanThreshold
);


int
realtek_i_qam_GetCstPeakToMeanThreshold(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *CstPeakToMeanThreshold
);


int
realtek_i_qam_GetIfAgcGain(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *IfAgcGain
);


int
realtek_i_qam_GetSignalQualityIndicator(
	QAM_DEMOD_MODULE *pDemod,
	unsigned char *SignalQualityIndicator
);


/*
int
realtek_i_qam_GetSignalSSI(
	QAM_DEMOD_MODULE *pDemod,
	int rf_level,
	unsigned char *ssi
);


int
realtek_i_qam_UpdateFunction(
	QAM_DEMOD_MODULE *pDemod
);
*/

#ifdef __cplusplus
}
#endif
#endif
