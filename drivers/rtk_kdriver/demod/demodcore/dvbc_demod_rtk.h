#ifndef __DVBC_DEMOD_REALTEK_I_H
#define __DVBC_DEMOD_REALTEK_I_H

#include "dvbc_demod_base.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_BIT_PRECISION        	5
#define FRAC_BITMASK            		0x1F
#define LOG2_10_100X            		332
#define LOG2_E_100X             		14

// DVBC Virtual Register Address/Mask
//#define CABLE_REG_SYSTEM_STATE                              0x8000 //Read Only
    #define CABLE_BITFLD_SYSTEM_STATE               0x00000007
//#define CABLE_REG_CCS_STATE                                 0x8001 //Read Only
    #define CABLE_BITFLD_CCS_STATE                  0x00000007
//#define CABLE_REG_EQADAPT_STATE                             0x8002 //Read Only
    #define CABLE_BITFLD_EQADAPT_STATE              0x00000007
//#define CABLE_REG_SIGNAL_NOT_FOUND                          0x8003 //Read Only
    #define CABLE_BITFLD_SIGNAL_NOT_FOUND           0x00000001
//#define CABLE_REG_SYM_RATE_MON                              0x8004 //Read Only
    #define CABLE_BITFLD_SYM_RATE_MON               0xFFFFFFFF
//#define CABLE_REG_CARR_FREQ_MON                             0x8005 //Read Only
    #define CABLE_BITFLD_CARR_FREQ_MON              0xFFFFFFFF
//#define CABLE_REG_QAM_MON                                   0x8006 //Read Only
    #define CABLE_BITFLD_QAM_MON                    0x00000007
//#define CABLE_REG_SPEC_INV_MON                              0x8007 //Read Only
    #define CABLE_BITFLD_SPEC_INV_MON               0x00000001
//#define CABLE_REG_AQUISITION_TIME                           0x8008 //Read Only
    #define CABLE_BITFLD_AQUISITION_TIME            0xFFFFFFFF
//#define CABLE_REG_AQUISITION_TIME_RESET                     0x8009 //Read/Write
    #define CABLE_BITFLD_AQUISITION_TIME_RESET      0x00000001
//#define CABLE_REG_EQ_SNR_DB                                 0x800A //Read Only
    #define CABLE_BITFLD_EQ_SNR_DB                  0x0000FFFF
//#define CABLE_REG_NUM_PKTS                                  0x800B //Read Only
    #define CABLE_BITFLD_NUM_PKTS                   0xFFFFFFFF
//#define CABLE_REG_NUM_BADPKTS                               0x800C //Read Only
    #define CABLE_BITFLD_NUM_BADPKTS                0xFFFFFFFF
//#define CABLE_REG_NUM_BYTE_ERRS                             0x800D //Read Only
    #define CABLE_BITFLD_NUM_BYTE_ERRS              0xFFFFFFFF
//#define CABLE_REG_NUM_BIT_ERRS                              0x800E //Read Only
    #define CABLE_BITFLD_NUM_BIT_ERRS               0xFFFFFFFF
//#define CABLE_REG_NUM_SECS_BER_AVERAGE                      0x800F //Read/Write
    #define CABLE_BITFLD_NUM_SECS_BER_AVERAGE       0x0000001F
//#define CABLE_REG_RS_AVERAGE_BER                            0x8010 //Read Only
    #define CABLE_BITFLD_RS_AVERAGE_BER             0xFFFFFFFF
//#define CABLE_REG_RS_AVERAGE_PER                            0x8011 //Read Only
    #define CABLE_BITFLD_RS_AVERAGE_PER             0xFFFFFFFF
//#define CABLE_REG_EQ_AVERAGE_SNR                            0x8012 //Read Only
    #define CABLE_BITFLD_EQ_AVERAGE_SNR             0xFFFFFFFF
//#define CABLE_REG_FAILURE_COUNTERS_RESET                    0x8013 //Read/Write
    #define CABLE_BITFLD_FAILURE_COUNTERS_RESET     0x00000001
//#define CABLE_REG_NUM_COARSE_SYMTIM_FAILURE                 0x8014 //Read Only
    #define CABLE_BITFLD_NUM_COARSE_SYMTIM_FAILURE  0xFFFFFFFF
//#define CABLE_REG_NUM_FINE_SYMTIM_FAILURE                   0x8015 //Read Only
    #define CABLE_BITFLD_NUM_FINE_SYMTIM_FAILURE    0xFFFFFFFF
//#define CABLE_REG_NUM_CARRSYNC_FAILURE                      0x8016 //Read Only
    #define CABLE_BITFLD_NUM_CARRSYNC_FAILURE       0xFFFFFFFF
//#define CABLE_REG_NUM_QAM_SEARCH_FAILURE                    0x8017 //Read Only
    #define CABLE_BITFLD_NUM_QAM_SEARCH_FAILURE     0xFFFFFFFF
//#define CABLE_REG_NUM_SPECINV_SEARCH_FAILURE                0x8018 //Read Only
    #define CABLE_BITFLD_NUM_SPECINV_SEARCH_FAILURE 0xFFFFFFFF
//#define CABLE_REG_NUM_TS_RATE_FAILURE                       0x8019 //Read Only
    #define CABLE_BITFLD_NUM_TS_RATE_FAILURE        0xFFFFFFFF
//#define CABLE_REG_NUM_PER_FAILURE                           0x801A //Read Only
    #define CABLE_BITFLD_NUM_PER_FAILURE            0xFFFFFFFF
//#define CABLE_REG_NUM_SIGNAL_DROPOUT_FAILURE                0x801B //Read Only
    #define CABLE_BITFLD_NUM_SIGNAL_DROPOUT_FAILURE 0xFFFFFFFF
//#define CABLE_REG_LAST_FAILURE                              0x801C //Read Only
    #define CABLE_BITFLD_LAST_FAILURE               0xFFFFFFFF
//#define CABLE_REG_CORE_CLK                                  0x801D //Read/Write
    #define CABLE_BITFLD_CORE_CLK                   0xFFFFFFFF
//#define CABLE_REG_QAM_SEARCH_ENABLE                         0x801E //Read/Write
    #define CABLE_BITFLD_QAM_SEARCH_ENABLE          0x00000001
//#define CABLE_REG_QAM_FIXED                                 0x801F //Read/Write
    #define CABLE_BITFLD_QAM_FIXED                  0x00000007
//#define CABLE_REG_QAM_SEARCH                                0x8020 //Read/Write
    #define CABLE_BITFLD_QAM_SEARCH_256QAM          0x00000010
    #define CABLE_BITFLD_QAM_SEARCH_128QAM          0x00000008
    #define CABLE_BITFLD_QAM_SEARCH_64QAM           0x00000004
    #define CABLE_BITFLD_QAM_SEARCH_32QAM           0x00000002
    #define CABLE_BITFLD_QAM_SEARCH_16QAM           0x00000001
//#define CABLE_REG_SYM_SEARCH_MODE                           0x8021 //Read/Write
    #define CABLE_BITFLD_SYM_SEARCH_MODE            0x00000003
//#define CABLE_REG_SYM_FIXED                                 0x8022 //Read/Write
    #define CABLE_BITFLD_SYM_FIXED                  0xFFFFFFFF
//#define CABLE_REG_SYM_LIST0                                 0x8023 //Read/Write
    #define CABLE_BITFLD_SYM_LIST0                  0xFFFFFFFF
//#define CABLE_REG_SYM_LIST1                                 0x8024 //Read/Write
    #define CABLE_BITFLD_SYM_LIST1                  0xFFFFFFFF
//#define CABLE_REG_SYM_LIST2                                 0x8025 //Read/Write
    #define CABLE_BITFLD_SYM_LIST2                  0xFFFFFFFF
//#define CABLE_REG_SYM_LIST3                                 0x8026 //Read/Write
    #define CABLE_BITFLD_SYM_LIST3                  0xFFFFFFFF
//#define CABLE_REG_SYM_LIST4                                 0x8027 //Read/Write
    #define CABLE_BITFLD_SYM_LIST4                  0xFFFFFFFF
//#define CABLE_REG_SYM_LIST5                                 0x8028 //Read/Write
    #define CABLE_BITFLD_SYM_LIST5                  0xFFFFFFFF
//#define CABLE_REG_SYM_LIST6                                 0x8029 //Read/Write
    #define CABLE_BITFLD_SYM_LIST6                  0xFFFFFFFF
//#define CABLE_REG_SYM_LIST7                                 0x802A //Read/Write
    #define CABLE_BITFLD_SYM_LIST7                  0xFFFFFFFF
//#define CABLE_REG_SYM_MIN                                   0x802B //Read/Write
    #define CABLE_BITFLD_SYM_MIN                    0xFFFFFFFF
//#define CABLE_REG_SYM_MAX                                   0x802C //Read/Write
    #define CABLE_BITFLD_SYM_MAX                    0xFFFFFFFF
//#define CABLE_REG_SPECINV_SEARCH_ENABLE                     0x802D //Read/Write
    #define CABLE_BITFLD_SPECINV_SEARCH_ENABLE      0x00000001
//#define CABLE_REG_SPECTRUM_INVERSION                        0x802E //Read/Write
    #define CABLE_BITFLD_SPECTRUM_INVERSION         0x00000001
//#define CABLE_REG_BYTE_ERR_BADPKTS                          0x802F //Read/Write
    #define CABLE_BITFLD_BYTE_ERR_BADPKTS           0xFFFFFFFF
//#define CABLE_REG_BIT_ERR_BADPKTS                           0x8030 //Read/Write
    #define CABLE_BITFLD_BIT_ERR_BADPKTS            0xFFFFFFFF
//#define CABLE_REG_PERCENT_BADPKTS_BADSET                    0x8031 //Read/Write
    #define CABLE_BITFLD_PERCENT_BADPKTS_BADSET     0x00000003
//#define CABLE_REG_SER_FAILURE                               0x8032 //Read/Write
    #define CABLE_BITFLD_SER_FAILURE                0xFFFFFFFF
//#define CABLE_REG_PTGAIN_16QAM                              0x8033 //Read/Write
    #define CABLE_BITFLD_PTGAIN16QAM                0x0000001F
//#define CABLE_REG_PTGAIN_32QAM                              0x8034 //Read/Write
    #define CABLE_BITFLD_PTGAIN32QAM                0x0000001F
//#define CABLE_REG_PTGAIN_64QAM                              0x8035 //Read/Write
    #define CABLE_BITFLD_PTGAIN64QAM                0x0000001F
//#define CABLE_REG_PTGAIN_128QAM                             0x8036 //Read/Write
    #define CABLE_BITFLD_PTGAIN128QAM               0x0000001F
//#define CABLE_REG_PTGAIN_256QAM                             0x8037 //Read/Write
    #define CABLE_BITFLD_PTGAIN256QAM               0x0000001F
//#define CABLE_REG_TUNE_DAGC_POWER                           0x8038 //Read/Write
    #define CABLE_BITFLD_TUNE_DAGC_POWER            0x00FFFFFF
//#define CABLE_REG_TUNE_EQ_UPDATE_STEPSIZE                   0x8039 //Read/Write
    #define CABLE_BITFLD_TUNE_EQ_UPDATE_STEPSIZE    0x00FFFFFF

// Builder
void
BuildRealtekIDvbCModule(
	DVBC_DEMOD_MODULE **ppDemod,
	DVBC_DEMOD_MODULE *pDvbCDemodModuleMemory,
	BASE_INTERFACE_MODULE *pBaseInterfaceModuleMemory,
	I2C_BRIDGE_MODULE *pI2cBridgeModuleMemory,
	unsigned char DeviceAddr,
	unsigned long CrystalFreqHz
);

// DVBC Virtual Register
int
realtek_i_dvbc_GetSystemState(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *SystemState
);

int
realtek_i_dvbc_GetCoarseCarrierSyncSubState(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *SyncSubState
);

int
realtek_i_dvbc_GetEqAdaptationSubState(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *EqAdaptState
);

int
realtek_i_dvbc_GetIsNoSignal(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *IsSignalFound
);

int
realtek_i_dvbc_GetMonitorSymbolRate(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *MonSymbolRate
);

int
realtek_i_dvbc_GetMonitorCarrierFrequency(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *MonCarrierFreq
);

int
realtek_i_dvbc_GetMonitorQamSize(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *MonQamSize
);

int
realtek_i_dvbc_GetMonitorSpectrumInversion(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *MonSpecInv
);

int
realtek_i_dvbc_GetAcquisitionTime(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *AcqTime
);

int
realtek_i_dvbc_SetAcquisitionTimerReset(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int AcqTimerReset
);

int
realtek_i_dvbc_GetAcquisitionTimerReset(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *AcqTimerReset
);

int
realtek_i_dvbc_GetEqOutputSnr(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *EqOutSnr
);

int
realtek_i_dvbc_GetTsPacketNumber(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *TsPacketNumber
);

int
realtek_i_dvbc_GetBadPacketNumber(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *BadPacketNumber
);

int
realtek_i_dvbc_GetByteErrorNumber(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *ByteErrorNumber
);

int
realtek_i_dvbc_GetBitErrorNumber(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *BitErrorNumber
);

int
realtek_i_dvbc_SetBerAveLength(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int BerAveLength
);

int
realtek_i_dvbc_GetBerAveLength(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *BerAveLength
);

int
realtek_i_dvbc_GetRsAveBer(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *RsBer
);

int
realtek_i_dvbc_GetRsAvePer(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *RsPer
);

int
realtek_i_dvbc_GetEqAveSnr(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *EqSnr
);

int
realtek_i_dvbc_SetFailCounterReset(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int FailCntRst
);

int
realtek_i_dvbc_GetFailCounterReset(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *FailCntRst
);

int
realtek_i_dvbc_GetCoastSymbolTimingFailNumber(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *CourseSymbolFailNum
);

int
realtek_i_dvbc_GetFineSymbolTimingFailNumber(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *FineSymbolFailNum
);

int
realtek_i_dvbc_GetCarrierSyncFailNumber(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *CarrierSyncFailNum
);

int
realtek_i_dvbc_GetQamSearchFailNumber(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *QamSearchFailNum
);

int
realtek_i_dvbc_GetSpectrumInversionSearchFailNumber(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *SpecInvSearchFailNum
);

int
realtek_i_dvbc_GetUnSupportTsRateFailNumber(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *UnSuppTsRateFailNum
);

int
realtek_i_dvbc_GetPerFailNumber(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *PerFailNum
);

int
realtek_i_dvbc_GetSignalDropoutFailNumber(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *SignalDropFailNum
);

int
realtek_i_dvbc_GetLastFailCase(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *LastFailCase
);

int
realtek_i_dvbc_SetEnableQamSearch(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int EnQamSearch
);

int
realtek_i_dvbc_GetEnableQamSearch(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *EnQamSearch
);

int
realtek_i_dvbc_SetFixQamSize(
	DVBC_DEMOD_MODULE *pDemod,
	int QamMode
);

int
realtek_i_dvbc_GetFixQamSize(
	DVBC_DEMOD_MODULE *pDemod,
	int *QamMode
);

int
realtek_i_dvbc_SetQamSearchList(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int QamSearchList
);

int
realtek_i_dvbc_GetQamSearchList(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *QamSearchList
);

int
realtek_i_dvbc_SetSymbolRateSearchMode(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int SrSearchMode
);

int
realtek_i_dvbc_GetSymbolRateSearchMode(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *SrSearchMode
);

int
realtek_i_dvbc_SetFixSymbolRate(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int FixSymbolRate
);

int
realtek_i_dvbc_GetFixSymbolRate(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *FixSymbolRate
);

int
realtek_i_dvbc_SetSymbolRateList(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int ListIndex,
	unsigned int ListSymbolRate
);

int
realtek_i_dvbc_GetSymbolRateList(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int ListIndex,
	unsigned int *ListSymbolRate
);

int
realtek_i_dvbc_SetMinSymbolRate(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int MinSymbolRate
);

int
realtek_i_dvbc_GetMinSymbolRate(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *MinSymbolRate
);

int
realtek_i_dvbc_SetMaxSymbolRate(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int MaxSymbolRate
);

int
realtek_i_dvbc_GetMaxSymbolRate(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *MaxSymbolRate
);

int
realtek_i_dvbc_SetEnableSpectrumInversionSearch(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int EnSpecInvSearch
);

int
realtek_i_dvbc_GetEnableSpectrumInversionSearch(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *EnSpecInvSearch
);

int
realtek_i_dvbc_SetFixSpectrumInverseMode(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int FixSpecInvMode
);

int
realtek_i_dvbc_GetFixSpectrumInverseMode(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *FixSpecInvMode
);

int
realtek_i_dvbc_SetBadPacketByteErrorNumber(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int BadPktByteErrNum
);

int
realtek_i_dvbc_GetBadPacketByteErrorNumber(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *BadPktByteErrNum
);

int
realtek_i_dvbc_SetBadPacketBitErrorNumber(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int BadPktBitErrNum
);

int
realtek_i_dvbc_GetBadPacketBitErrorNumber(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *BadPktBitErrNum
);

int
realtek_i_dvbc_SetBadSetBadPacketPercentage(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int BadSetBadPktPercentage
);

int
realtek_i_dvbc_GetBadSetBadPacketPercentage(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *BadSetBadPktPercentage
);

int
realtek_i_dvbc_SetFailErrorRate(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int BadSetBadPktPercentage
);

int
realtek_i_dvbc_GetFailErrorRate(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *BadSetBadPktPercentage
);

int
realtek_i_dvbc_SetPhaseTrackerLoopGain(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int QamMode,
	unsigned int PhaseTrackLoopGain
);

int
realtek_i_dvbc_GetPhaseTrackerLoopGain(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int QamMode,
	unsigned int *PhaseTrackLoopGain
);

int
realtek_i_dvbc_SetDagcPower(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int DagcPower
);

int
realtek_i_dvbc_GetDagcPower(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *DagcPower
);

int
realtek_i_dvbc_SetEqUpdateRate(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int EqUpdateRate
);

int
realtek_i_dvbc_GetEqUpdateRate(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *EqUpdateRate
);

int
realtek_i_dvbc_GetSignalSSI(
	DVBC_DEMOD_MODULE *pDemod,
	int rf_level,
	unsigned char *ssi
);

int
realtek_i_dvbc_GetSignalSQI(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned char *sqi
);

int
realtek_i_dvbc_UpdateFunction(
	DVBC_DEMOD_MODULE *pDemod
);

unsigned long 
realtek_i_dvbc_math_log2 (
unsigned long x
);

unsigned long 
realtek_i_dvbc_math_log10 (
unsigned long x
);
#ifdef __cplusplus
}
#endif
#endif
