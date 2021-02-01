#ifndef __DVBT2_DEMOD_REALTEK_I_H
#define __DVBT2_DEMOD_REALTEK_I_H

#include "dvbt2_demod_base.h"

#ifdef __cplusplus
extern "C" {
#endif

// DVBT2 virtual register address
//#define DVBT2_REG_SELECT_T2_PROFILE_CMD                             0x8000 //Write
#define DVBT2_BITFLD_SELECT_T2_PROFILE_CMD                          0xFFFFFFFF
//#define DVBT2_REG_SELECT_DETECT_TIME_MS_CMD                         0x8001 //Write
#define DVBT2_BITFLD_SELECT_DETECT_TIME_MS_CMD                      0xFFFFFFFF
//#define DVBT2_REG_HOLDOFF_MS                                        0x8002 //Write
#define DVBT2_BITFLD_HOLDOFF_MS                                     0xFFFFFFFF
//#define DVBT2_REG_SIGNAL_INDICATOR                                  0x8003 //Read Only
#define DVBT2_BITFLD_SIGNAL_INDICATOR                               0xFFFFFFFF
//#define DVBT2_REG_TS_LOCK_TIME_MS                                   0x8004 //Read Only
#define DVBT2_BITFLD_TS_LOCK_TIME_MS                                0xFFFFFFFF

//DVBT/T2 Fast Scan Virtual Register[begin]
//#define DVBT2_REG_DVBT_SEARCH_MODE                                  0x8005 //Write
#define DVBT2_BITFLD_DVBT_SEARCH_MODE                               0x0000000F
//#define DVBT2_REG_P1SEARCH_TIMEOUT_MS                               0x8006 //Write
#define DVBT2_BITFLD_P1SEARCH_TIMEOUT_MS                            0x00000FFF
//#define DVBT2_REG_MIN_P1_COUNT                                      0x8007 //Write
#define DVBT2_BITFLD_MIN_P1_COUNT                                   0x0000000F
//#define DVBT2_REG_DVBTSEARCH_TIMEOUT_MS                             0x8008 //Write
#define DVBT2_BITFLD_DVBTSEARCH_TIMEOUT_MS                          0x00000FFF
//#define DVBT2_REG_DVBTSEARCH_REFRESH_PERIOD_MS                      0x8009 //Write
#define DVBT2_BITFLD_DVBTSEARCH_REFRESH_PERIOD_MS                   0x00000FFF
//#define DVBT2_REG_DVBT_DECISION_THRESHOLD_1                         0x800A //Write
#define DVBT2_BITFLD_DVBT_DECISION_THRESHOLD_1                      0xFFFFFFFF
//#define DVBT2_REG_DVBT_DECISION_THRESHOLD_2                         0x800B //Write
#define DVBT2_BITFLD_DVBT_DECISION_THRESHOLD_2                      0xFFFFFFFF
//#define DVBT2_REG_DVBT_SEARCH_RESULTS                               0x800C //Read Only
#define DVBT2_BITFLD_DVBT_SEARCH_STATUS                             0xF0000000
#define DVBT2_BITFLD_DVBT_SEARCH_RESULTS                            0x0000FFFF
//DVBT/T2 Fast Scan Virtual Register[end]

//#define DVBT2_REG_SELECT_DATA_PLP_ID_CMD                            0x800D //Write
#define DVBT2_BITFLD_SELECT_DATA_PLP_ID_CMD                         0x000000FF
//#define DVBT2_REG_ACTIVE_DATA_PLP_ID                                0x800E //Read Only
#define DVBT2_BITFLD_ACTIVE_DATA_PLP_ID                             0x000000FF
//#define DVBT2_REG_NUM_DATA_PLP                                      0x800F //Read Only
#define DVBT2_BITFLD_NUM_DATA_PLP                                   0x000000FF
//#define DVBT2_REG_DATA_PLP_LIST                                     0x8010 //Read Only
#define DVBT2_BITFLD_DATA_PLP_PAYLOAD_TYPE                          0x0000F800
#define DVBT2_BITFLD_DATA_PLP_TYPE                                  0x00000700
#define DVBT2_BITFLD_DATA_PLP_ID                                    0x000000FF
//#define DVBT2_REG_DATA_PLP_COD                                      0x802A //Read Only
#define DVBT2_BITFLD_DATA_PLP_COD                                   0xFFFFFFFF
//#define DVBT2_REG_DATA_PLP_MOD                                      0x802B //Read Only
#define DVBT2_BITFLD_DATA_PLP_MOD                                   0xFFFFFFFF
//#define DVBT2_REG_SFOPPM_Q16_15                                     0x8044 //Write & Read
#define DVBT2_BITFLD_DATA_SFOPPM_Q16_15                             0xFFFFFFFF
//#define DVBT2_REG_DATA_ERROR_COUNTERS_CMD                           0x8045 //Write
#define DVBT2_BITFLD_DATA_ERROR_COUNTERS_CMD                        0xFFFFFFFF
//#define DVBT2_REG_DATA_DECODED_FRAMES                               0x8046 //Read only
#define DVBT2_BITFLD_DATA_DECODED_FRAMES                            0xFFFFFFFF
//#define DVBT2_REG_DATA_LDPC_STUCK_FRAMES                            0x8047 //Read only
#define DVBT2_BITFLD_DATA_LDPC_STUCK_FRAMES                         0xFFFFFFFF
//#define DVBT2_REG_DATA_LDPC_UNSTABLE_FRAMES                         0x8048 //Read only
#define DVBT2_BITFLD_DATA_LDPC_UNSTABLE_FRAMES                      0xFFFFFFFF
//#define DVBT2_REG_DATA_LDPC_FRAMES_WITH_PARITY_FAILURE              0x8049 //Read Only
#define DVBT2_BITFLD_DATA_LDPC_FRAMES_WITH_PARITY_FAILURE           0xFFFFFFFF
//#define DVBT2_REG_DATA_LDPC_PARITY_CHECK_FAILURES                   0x804A //Read Only
#define DVBT2_BITFLD_DATA_LDPC_PARITY_CHECK_FAILURES                0xFFFFFFFF
//#define DVBT2_REG_DATA_BCH_UNCORRECTABLE_CWS                        0x804B //Read Only
#define DVBT2_BITFLD_DATA_BCH_UNCORRECTABLE_CWS                     0xFFFFFFFF
//#define DVBT2_REG_DATA_BCH_CORRECTED_BYTES                          0x804C //Read Only
#define DVBT2_BITFLD_DATA_BCH_CORRECTED_BYTES                       0xFFFFFFFF
//#define DVBT2_REG_DATA_BCH_CORRECTED_BITS                           0x804D //Read Only
#define DVBT2_BITFLD_DATA_BCH_CORRECTED_BITS                        0xFFFFFFFF
//#define DVBT2_REG_COMMON_ERROR_COUNTERS_CMD                         0x804E //Write & Read
#define DVBT2_BITFLD_COMMON_ERROR_COUNTERS_CMD                      0xFFFFFFFF
//#define DVBT2_REG_COMMON_DECODED_FRAMES                             0x804F //Read Only
#define DVBT2_BITFLD_COMMON_DECODED_FRAMES                          0xFFFFFFFF
//#define DVBT2_REG_COMMON_LDPC_STUCK_FRAMES                          0x8050 //Read Only
#define DVBT2_BITFLD_COMMON_LDPC_STUCK_FRAMES                       0xFFFFFFFF
//#define DVBT2_REG_COMMON_LDPC_UNSTABLE_FRAMES                       0x8051 //Read Only
#define DVBT2_BITFLD_COMMON_LDPC_UNSTABLE_FRAMES                    0xFFFFFFFF
//#define DVBT2_REG_COMMON_LDPC_FRAMES_WITH_PARITY_FAILURE            0x8052 //Read Only
#define DVBT2_BITFLD_COMMON_LDPC_FRAMES_WITH_PARITY_FAILURE         0xFFFFFFFF
//#define DVBT2_REG_COMMON_LDPC_PARITY_CHECK_FAILURES                 0x8053 //Read Only
#define DVBT2_BIYFLD_COMMON_LDPC_PARITY_CHECK_FAILURES              0xFFFFFFFF
//#define DVBT2_REG_COMMON_BCH_UNCORRECTABLE_CWS                      0x8054 //Read Only
#define DVBT2_BITFLD_COMMON_BCH_UNCORRECTABLE_CWS                   0xFFFFFFFF
//#define DVBT2_REG_COMMON_BCH_CORRECTED_BYTES                        0x8055 //Read Only
#define DVBT2_BITFLD_COMMON_BCH_CORRECTED_BYTES                     0xFFFFFFFF
//#define DVBT2_REG_COMMON_BCH_CORRECTED_BITS                         0x8056 //Read Only
#define DVBT2_BITFLD_COMMON_BCH_CORRECTED_BITS                      0xFFFFFFFF
//#define DVBT2_REG_ERROR_RATES_INTEGRATION_PERIOD                    0x8057 //Write & Read
#define DVBT2_BITFLD_ERROR_RATES_INTEGRATION_PERIOD                 0xFFFFFFFF
//#define DVBT2_REG_DATA_ERROR_RATES_UPDATES                          0x8058 //Read Only
#define DVBT2_BITFLD_DATA_ERROR_RATES_UPDATES                       0xFFFFFFFF
//#define DVBT2_REG_DATA_LDPC_OUTPUT_FER_Q32                          0x8059 //Ready Only
#define DVBT2_BITFLD_DATA_LDPC_OUTPUT_FER_Q32                       0xFFFFFFFF
//#define DVBT2_REG_DATA_BCH_INPUT_BER_Q32                            0x805A //Read Only
#define DVBT2_BITFLD_DATA_BCH_INPUT_BER_Q32                         0xFFFFFFFF
//#define DVBT2_REG_DATA_BCH_OUTPUT_FER_Q32                           0x805B //Read Only
#define DVBT2_BITFLD_DATA_BCH_OUTPUT_FER_Q32                        0xFFFFFFFF
//#define DVBT2_REG_DATA_SQI                                          0x805C //Read Only
#define DVBT2_BITFLD_DATA_SQI                                       0xFFFFFFFF
//#define DVBT2_REG_COMMON_ERROR_RATES_UPDATES                        0x805D //Read Only
#define DVBT2_BITFLD_COMMON_ERROR_RATES_UPDATES                     0xFFFFFFFF
//#define DVBT2_REG_COMMON_LDPC_INPUT_BER_Q32                         0x805E //Read Only
#define DVBT2_BITFLD_COMMON_LDPC_INPUT_BER_Q32                      0xFFFFFFFF
//#define DVBT2_REG_COMMON_BCH_INPUT_BER_Q32                          0x805F //Read Only
#define DVBT2_BITFLD_COMMON_BCH_INPUT_BER_Q32                       0xFFFFFFFF
//#define DVBT2_REG_COMMON_BCH_OUTPUT_FER_Q32                         0x8060 //Read Only
#define DVBT2_BITFLD_COMMON_BCH_OUTPUT_FER_Q32                      0xFFFFFFFF
//#define DVBT2_REG_SYM_STATUS_UPDATES                                0x8061 //Read Only
#define DVBT2_BITFLD_SYM_STATUS_UPDATES                             0xFFFFFFFF
//#define DVBT2_REG_SYM_SYMBOL_COUNT                                  0x8062 //Read Only
#define DVBT2_BITFLD_SYM_SYMBOL_COUNT                               0xFFFFFFFF
//#define DVBT2_REG_SYM_FRAME_COUNT                                   0x8063 //Read Only
#define DVBT2_BITFLD_SYM_FRAME_COUNT                                0xFFFFFFFF
//#define DVBT2_REG_SYM_CSI_DB_Q16_15                                 0x8064 //Read Only
#define DVBT2_BITFLD_SYM_CSI_DB_Q16_15                              0xFFFFFFFF
//#define DVBT2_REG_SYM_NOISE_VAR_DB_Q16_15                           0x8065 //Read Only
#define DVBT2_BITFLD_SYM_NOISE_VAR_DB_Q16_15                        0xFFFFFFFF
//#define DVBT2_REG_SYM_CHANNEL_DELAY_SPREAD                          0x8066 //Read Only
#define DVBT2_BITFLD_SYM_CHANNEL_DELAY_SPREAD                       0xFFFFFFFF
//#define DVBT2_REG_SSI                                               0x8067 //Read Only
#define DVBT2_BITFLD_SSI                                            0xFFFFFFFF
//#define DVBT2_REG_DATA_HEM                                          0x8068 //Read Only
#define DVBT2_BITFLD_DATA_HEM                                       0xFFFFFFFF
//#define DVBT2_REG_DATA_ISSYI                                        0x8069 //Read Only
#define DVBT2_BITFLD_DATA_ISSYI                                     0xFFFFFFFF
//#define DVBT2_REG_DATA_NPD                                          0x806A //Read Only
#define DVBT2_BITFLD_DATA_NPD                                       0xFFFFFFFF
//#define DVBT2_REG_DATA_VAR_DFL                                      0x806B //Read Only
#define DVBT2_BITFLD_DATA_VAR_DFL                                   0xFFFFFFFF
//#define DVBT2_REG_DATA_PACKETS                                      0x806C //Read Only
#define DVBT2_BITFLD_DATA_PACKETS                                   0xFFFFFFFF
//#define DVBT2_REG_DATA_BITRATE_Q3_29                                0x806D //Read Only
#define DVBT2_BITFLD_DATA_BITRATE_Q3_29                             0xFFFFFFFF
//#define DVBT2_REG_COMMON_HEM                                        0x806E //Read Only
#define DVBT2_BITFLD_COMMON_HEM                                     0xFFFFFFFF
//#define DVBT2_REG_COMMON_ISSYI                                      0x806F //Read Only
#define DVBT2_BITFLD_COMMON_ISSYI                                   0xFFFFFFFF
//#define DVBT2_REG_COMMON_NPD                                        0x8070 //Read Only
#define DVBT2_BITFLD_COMMON_NPD                                     0xFFFFFFFF
//#define DVBT2_REG_COMMON_VAR_DFL                                    0x8071 //Read Only
#define DVBT2_BITFLD_COMMON_VAR_DFL                                 0xFFFFFFFF
//#define DVBT2_REG_COMMON_PACKETS                                    0x8072 //Read Only
#define DVBT2_BITFLD_COMMON_PACKETS                                 0xFFFFFFFF
//#define DVBT2_REG_COMMON_BITRATE_Q3_29                              0x8073 //Read ONly
#define DVBT2_BITFLD_COMMON_BITRATE_Q3_29                           0xFFFFFFFF
//#define DVBT2_REG_L1_INFO                                           0x8074 //Read Only
#define DVBT2_BITFLD_L1_INFO                                        0xFFFFFFFF
//#define DVBT2_REG_CONSTELLATION_BUFFER_HOST_STATUS_CMD              0x8075 //Write & Read
#define DVBT2_BITFLD_CONSTELLATION_BUFFER_HOST_STATUS_CMD           0xFFFFFFFF
//#define DVBT2_REG_CONSTELLATION_BUFFER_ADDRESS                      0x8076 //Read Only
#define DVBT2_BITFLD_CONSTELLATION_BUFFER_ADDRESS                   0xFFFFFFFF
//#define DVBT2_REG_CONSTELLATION_SAMPLE_NUMBER                       0x8077 //Read Only
#define DVBT2_BITFLD_CONSTELLATION_SAMPLE_NUMBER                    0x000007FF
//#define DVBT2_REG_TS_BAD_PACKETS                           0x807D //Read Only
#define DVBT2_BITFLD_TS_BAD_PACKETS                        0xFFFFFFFF


// DVBT Virtual Register Address/Mask
//#define DVBT_REG_DETECT_MASK                                0x8000 // Write & Read
#define DVBT_BITFLD_DETECT_MASK                 0x80000F00
//#define DVBT_REG_TUN_FFT                                    0x8001 // Write & Read
#define DVBT_BITFLD_TUN_FFT                     0x00000007
//#define DVBT_REG_TUN_GUARD                                  0x8002 // Write & Read
#define DVBT_BITFLD_TUN_GUARD                   0x0000000F
//#define DVBT_REG_TUN_MOD                                    0x8003 // Write & Read
#define DVBT_BITFLD_TUN_MOD                     0x00000007
//#define DVBT_REG_TUN_CODE_RATE                              0x8004 // Write & Read
#define DVBT_BITFLD_TUN_CODE_RATE               0x0000001F
//#define DVBT_REG_TUN_ALPHA                                  0x8005 // Write & Read
#define DVBT_BITFLD_TUN_ALPHA                   0x0000000F
//#define DVBT_REG_TUN_INTERLEAVER                            0x8006 // Write & Read
#define DVBT_BITFLD_TUN_INTERLEAVER             0x00000003
//#define DVBT_REG_TUN_HIERARCHICAL                           0x8007 // Write & Read
#define DVBT_BITFLD_TUN_HIERARCHICAL            0x00000003
//#define DVBT_REG_TUN_SPECT_INV                              0x8008 // Write & Read
#define DVBT_BITFLD_TUN_SPECT_INV               0x00000003
//#define DVBT_REG_CALIB_CTRL                                 0x8009 // Write & Read
#define DVBT_BITFLD_CALIB_CTRL                  0x00000003
//#define DVBT_REG_CALIB_XTAL_OFFSET                          0x800A // Write & Read
#define DVBT_BITFLD_CALIB_XTAL_OFFSET           0xFFFFFFFF
//#define DVBT_REG_STAT_CTRL                              0x800B // Write & Read
#define DVBT_BITFLD_STAT_CTRL               0x00000003
//#define DVBT_REG_STAT_UPDATE                                0x800C // Read Only
#define DVBT_BITFLD_STAT_UPDATE                 0xFFFFFFFF
//#define DVBT_REG_STAT_SSI                                   0x800D // Read Only
#define DVBT_BITFLD_STAT_SSI                    0x0000000F
//#define DVBT_REG_STAT_SNR                                   0x800E // Read Only
#define DVBT_BITFLD_STAT_SNR                    0xFFFFFFFF
//#define DVBT_REG_STAT_CARRIER_OFFSET                        0x800F // Read Only
#define DVBT_BITFLD_STAT_CARRIER_OFFSET         0xFFFFFFFF
//#define DVBT_REG_STAT_TS_PKT_COUNT                          0x8010 // Read Only
#define DVBT_BITFLD_STAT_TS_PKT_COUNT           0xFFFFFFFF
//#define DVBT_REG_STAT_TS_BAD_PKT_COUNT                      0x8011 // Read Only
#define DVBT_BITFLD_STAT_TS_BAD_PKT_COUNT       0xFFFFFFFF
//#define DVBT_REG_STAT_TS_BYTE_ERRS                          0x8012 // Read Only
#define DVBT_BITFLD_STAT_TS_BYTE_ERRS           0xFFFFFFFF
//#define DVBT_REG_STAT_TS_BIT_ERRS                           0x8013 // Read Only
#define DVBT_BITFLD_STAT_TS_BIT_ERRS            0xFFFFFFFF
//#define DVBT_REG_STAT_VITERBI_BER                           0x8014 // Read Only
#define DVBT_BITFLD_STAT_VITERBI_BER            0xFFFFFFFF
//#define DVBT_REG_STAT_TS_SYNC                               0x8015 // Read Only
#define DVBT_BITFLD_STAT_TS_SYNC                0x00000001
//#define DVBT_REG_STAT_TPS_SYNC                              0x8016 // Read Only
#define DVBT_BITFLD_STAT_TPS_SYNC               0x00000001
//#define DVBT_REG_STAT_IF_AGC_LEVEL                          0x8017 // Read Only
#define DVBT_BITFLD_STAT_IF_AGC_LEVEL           0x0000FFFF
//#define DVBT_REG_STAT_NUM_SYMBOLS                           0x8018 // Read Only
#define DVBT_BITFLD_STAT_NUM_SYMBOLS            0xFFFFFFFF
//#define DVBT_REG_STAT_NUM_REACQ                             0x8019 // Read Only
#define DVBT_BITFLD_STAT_NUM_REACQ              0xFFFFFFFF
//#define DVBT_REG_STAT_ACI_DETECTED                          0x801A // Read Only
#define DVBT_BITFLD_STAT_ACI_DETECTED           0x00000007
//#define DVBT_REG_BER_PERIOD                                 0x801B // Read Only
#define DVBT_BITFLD_BER_PERIOD                  0x000000FF
//#define DVBT_REG_BER_UPDATE                                 0x801C // Read Only
#define DVBT_BITFLD_BER_UPDATE                  0xFFFFFFFF
//#define DVBT_REG_BER_RS_BER                                 0x801D // Read Only
#define DVBT_BITFLD_BER_RS_BER                  0xFFFFFFFF
//#define DVBT_REG_BER_TS_PER                                 0x801E // Read Only
#define DVBT_BITFLD_BER_TS_PER                  0xFFFFFFFF
//#define DVBT_REG_BER_SQI                                    0x801F // Read Only
#define DVBT_BITFLD_BER_SQI                     0x000000FF




// Builder
void
BuildRealtekIDvbt2Module(
	DVBT2_DEMOD_MODULE **ppDemod,
	DVBT2_DEMOD_MODULE *pDvbT2DemodModuleMemory,
	BASE_INTERFACE_MODULE *pBaseInterfaceModuleMemory,
	I2C_BRIDGE_MODULE *pI2cBridgeModuleMemory,
	unsigned char DeviceAddr,
	unsigned long CrystalFreqHz
);

// DVBT2 Virtual Register
int
realtek_i_dvbt2_SetT2ProfileCmd(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int T2Profile
);

int
realtek_i_dvbt2_SetDetectTimeCmd(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int DetectTime
);

int
realtek_i_dvbt2_SetHoldOffTimeMs(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int HoldOffTimeMs
);

int
realtek_i_dvbt2_GetSignalIndicator(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *SignalIndicator
);

int
realtek_i_dvbt2_GetTsLockTime(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *TsLockTime
);

int
realtek_i_dvbt2_SetDvbT2DvbTSearchMode(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int DvbT2DvbTSearchMode
);

int
realtek_i_dvbt2_SetP1SearchTimeout(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int P1SearchTimeout
);

int
realtek_i_dvbt2_SetMinP1Cnt(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int MinP1Cnt
);

int
realtek_i_dvbt2_SetDvbT2DvbTSearchTimeout(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int DvbT2DvbtSearchTimeout
);

int
realtek_i_dvbt2_SetDvbT2DvbTSearchUpdatePeriod(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int DvbT2DvbtSearchUpdatePeriod
);

int
realtek_i_dvbt2_SetDvbT2DvbTSearchDecisionTh1(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int DvbT2DvbtSearchDecisionTh1
);

int
realtek_i_dvbt2_SetDvbT2DvbTSearchDecisionTh2(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int DvbT2DvbtSearchDecisionTh2
);

int
realtek_i_dvbt2_SetDvbT2DvbTSearchResult(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int DvbT2DvbTSearchStatus,
	unsigned int DvbT2DvbTSearchResult
);

int
realtek_i_dvbt2_GetDvbT2DvbTSearchResult(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DvbT2DvbTSearchStatus,
	unsigned int *DvbT2DvbTSearchResult
);

int
realtek_i_dvbt2_SetDataPlpIdSelectCmd(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int DataPlpIdSelect
);

int
realtek_i_dvbt2_GetActiveDataPlpId(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *ActiveDataPlpId
);

int
realtek_i_dvbt2_GetNumDataPlps(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *NumDataPlps
);

int
realtek_i_dvbt2_GetListOfDataPlps(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int PlpLoopIdx,
	unsigned int *PayloadType,
	unsigned int *PlpType,
	unsigned int *PlpId
);

int
realtek_i_dvbt2_GetDataPlpCodeRate(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataPlpCodeRate
);

int
realtek_i_dvbt2_GetDataPlpModulation(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataPlpModulation
);

int
realtek_i_dvbt2_SetSfoPpm(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int SfoppmQ16_15
);

int
realtek_i_dvbt2_GetSfoPpm(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *SfoppmQ16_15
);

int
realtek_i_dvbt2_SetDataErrorCountersCmd(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int DataErrorCount
);

int
realtek_i_dvbt2_GetDataDecodedFrames(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataDecodedFrames
);

int
realtek_i_dvbt2_GetDataLdpcStuckFrames(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataLdpcStuckFrames
);

int
realtek_i_dvbt2_GetDataPlpLdpcUnstableFrames(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataLdpcUnstableFrames
);

int
realtek_i_dvbt2_GetDataLdpcFramesWithParityFailure(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataLdpcFramesWithParityFailure
);

int
realtek_i_dvbt2_GetDataLdpcParityCheckFailure(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataLdpcParityCheckFailure
);

int
realtek_i_dvbt2_GetUncorrectableBchCws(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *UncorrectableBchCws
);

int
realtek_i_dvbt2_GetCorrectedBchBytes(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CorrectedBchBytes
);

int
realtek_i_dvbt2_GetCorrectedBchBits(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CorrectedBchBits
);

int
realtek_i_dvbt2_SetCommonPlpErrorCounterCmd(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int CommonPlpErrorCounter
);

int
realtek_i_dvbt2_GetCommonDecodedFrames(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonDecodedFrames
);

int
realtek_i_dvbt2_GetCommonLdpcStuckFrames(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonLdpcStuckFrames
);

int
realtek_i_dvbt2_GetCommonLdpcUnstableFrames(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonLdpcUnstableFrames
);

int
realtek_i_dvbt2_GetCommonLdpcFrameWithParityFailure(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonLDPCFrameWithParityFailure
);

int
realtek_i_dvbt2_GetCommonLdcpParityCheckFailure(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonLDPCParityCheckFailure
);

int
realtek_i_dvbt2_GetCommonBchUncorrectableCws(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonBchUncorrectableCws
);

int
realtek_i_dvbt2_GetCommonBchCorrectedBytes(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonBchCorrectedByte
);

int
realtek_i_dvbt2_GetCommonBchCorrectedBits(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonBchCorrectedBit
);

int
rdt2938_dvbt2_SetErrRateIntegPeriod(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int ErrRateIntegPeriod
);

int
realtek_i_dvbt2_GetErrRateIntegPeriod(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *ErrRateIntegPeriod
);

int
realtek_i_dvbt2_GetDataErrorRateUpdates(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataErrorRateUpdate
);

int
realtek_i_dvbt2_GetDataLdpcOutputFer(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataLdpcOutputFer
);

int
realtek_i_dvbt2_GetDataBchInputBer(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataBchInputBer
);

int
realtek_i_dvbt2_GetDataBchOutputFer(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataBchcOutputFer
);

int
realtek_i_dvbt2_GetSqi(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *Sqi
);

int
realtek_i_dvbt2_GetCommonRateUpdate(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonRateUpdate
);

int
realtek_i_dvbt2_GetCommonLdpcInputBer(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonLdpcInputBer
);

int
realtek_i_dvbt2_GetCommonBchInputBer(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonBchInputBer
);

int
realtek_i_dvbt2_GetCommonBchOutputFer(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonBchOutputFer
);

int
realtek_i_dvbt2_GetSymStatusUpdates(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *SymStatusUpdate
);

int
realtek_i_dvbt2_GetSymSymbolCount(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *SymSymbolCount
);

int
realtek_i_dvbt2_GetSymFrameCount(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *SymSymbolCount
);

int
realtek_i_dvbt2_GetSymCsiSnr(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *SymCsiSnr
);

int
realtek_i_dvbt2_GetSymNoiseVar(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *SymNoiseVar
);

int
realtek_i_dvbt2_GetSymChannelDelaySpread(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *SymChannelDelaySpread
);

int
realtek_i_dvbt2_GetSsi(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *SymSsi
);

int
realtek_i_dvbt2_GetDataHem(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataHem
);

int
realtek_i_dvbt2_GetDataIssyi(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataIssyi
);

int
realtek_i_dvbt2_GetDataNpd(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataNpd
);

int
realtek_i_dvbt2_GetDataVarDfl(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataBarDfl
);

int
realtek_i_dvbt2_GetDataPackets(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataPackets
);

int
realtek_i_dvbt2_GetDataBitRate(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataBitRate
);

int
realtek_i_dvbt2_GetCommonHem(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonHem
);

int
realtek_i_dvbt2_GetCommonIssyi(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonIssyi
);


int
realtek_i_dvbt2_GetCommonNpd(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonNpd
);

int
realtek_i_dvbt2_GetCommonVarDfl(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonVarDfl
);

int
realtek_i_dvbt2_GetCommonPackets(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonPackets
);

int
realtek_i_dvbt2_GetCommonBitRate(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonBitRate
);

int
realtek_i_dvbt2_GetL1Info(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *L1Info
);

int
realtek_i_dvbt2_SetConsBuffHostStatusCmd(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int ConsBuffHostStatus
);

int
realtek_i_dvbt2_GetConsBuffHostStatusCmd(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *ConsBuffHostStatus
);

int
realtek_i_dvbt2_GetConsBuffAddress(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *ConsBuffHostAddress
);

int
realtek_i_dvbt2_GetConsSampleNum(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *ConsSampleNum
);

int
realtek_i_dvbt2_GetDvbTTpsSyncResult(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DvbTTpsSyncRst
);

int
realtek_i_dvbt2_GetDvbTSsi(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DvbTSsi
);

int
realtek_i_dvbt2_GetDvbTSqi(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DvbTSqi
);

int
realtek_i_dvbt2_SetDvbTStatCtrl(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int StatCtrl
);

int
realtek_i_dvbt2_GetDvbTSnr(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *StatSnr
);

int
realtek_i_dvbt2_SetDvbTBerPeriod(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int BerPeriod
);

int
realtek_i_dvbt2_GetDvbTRsBer(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *BerRsBer
);

int
realtek_i_dvbt2_GetDvbTTsPer(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *BerTsPer
);

int
realtek_i_dvbt2_GetDvbTTsBadPktCount(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *StatTsBadPktCount
);

int
realtek_i_dvbt2_GetDvbTTunMod(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *TunMod
);

int
realtek_i_dvbt2_GetDvbTTunCodeRate(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *TunCodeRate
);

int
realtek_i_dvbt2_GetDvbTTsPktCnt(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *TsPktCnt
);

int
realtek_i_dvbt2_GetDvbTCfo(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *Cfo
);

int
realtek_i_dvbt2_SetDvbTDetectMask(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int DetectMask
);

int
realtek_i_dvbt2_GetIfAgcGain(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *IfAgcGain
);

int
realtek_i_dvbt2_GetTsBadPackets(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataTsBadPackets
);

int
realtek_i_dvbt_SetTunHierarchical(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int TunHierarchical
);

int
realtek_i_dvbt_GetTunHierarchical(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *TunHierarchical
);

#ifdef __cplusplus
}
#endif
#endif
