#ifndef __DVBT2_DEMOD_BASE_H
#define __DVBT2_DEMOD_BASE_H

#include "foundation.h"

#ifdef __cplusplus
extern "C" {
#endif

#if 0
// Common Register Index
#define TV_REG_API_ID                           0
#define TV_REG_DEMOD_ID                         1
#define TV_REG_BUILD_ID                         2
#define TV_REG_CONTROL                          3   //Cmd Reg
#define TV_REG_STATE                            4
#define TV_REG_TUNER_FREQ                       5   //Cmd Reg
#define TV_REG_TUNER_BW                         6
#define TV_REG_TUNER_GRID_BASE                  7
#define TV_REG_TUNER_GRID_INCR                  8
#define TV_REG_NOTCH_FREQ                       9   //Cmd Reg
#define TV_REG_NOTCH_BW                         10
#define TV_REG_ACTIVE_TUNER_FREQ                11
#define TV_REG_ACTIVE_TUNER_BW                  12
#define TV_REG_ACTIVE_TUNER_GAIN                13
#define TV_REG_ACTIVE_TUNER_RSSI                14
#define TV_REG_AGC_PARAMS                       15
#define TV_REG_TSO_CONFIG                       16
#define TV_REG_TSO_CLK_RATE_MARGIN              17
#define TV_REG_TSO_CLK_RATE_MAX                 18
#define TV_REG_DEBUG_VECTOR_OP_SEL              19  //Cmd Reg
#define TV_REG_DEBUG_VECTOR_OP_PARAMS           20
#define TV_REG_DEBUG_VECTOR_TRANSFER_LEN        21
#define TV_REG_DEBUG_VECTOR_BUFF_PTR            22
#define TV_REG_DEBUG_VECTOR_BUFF_SIZE           23
#define TV_REG_ENSIGMA_SDK_LOGGING              24  //Cmd Reg
#define TV_REG_ENSIGMA_SDK_BUFF_PTR             25
#define TV_REG_ENSIGMA_SDK_BUFF_SIZE            26
#define TV_REG_LOCK_TIME                        27
#define TV_REG_TUNER_CFG_OVERRIDE               28
#define TV_REG_PFM_SET_IF_GAIN_CTRL             29
#define TV_REG_PFM_FLAGS                        30
#define TV_REG_PFM_IF_FREQ                      31
#define TV_REG_PFM_OVERRIDE                     32
#define TV_REG_PFM_IF_CLK_FREQUENCY             33
#define TV_REG_PFM_LDPC_CLK_FREQUENCY           34
#define TV_REG_PFM_UCC_CLK_FREQUENCY            35
#define TV_REG_PFM_MCU_CLK_FREQUENCY            36
#define TV_REG_DVBT_LOCK_TIME                   27
#endif

// Common Register Setting
#define REALTEK_I_NOTCH_EN                                       0
#define REALTEK_I_NOTCH_FREQ                                     500000000
#define REALTEK_I_NOTCH_BW                                       1//0~87
#define REALTEK_I_TS_DIS_MASK                                    0x00000001
#define REALTEK_I_TS_SERIAL_MASK                                 0x00000002
#define REALTEK_I_TS_CLK_PHASE_INV_MASK                          0x00000004
#define REALTEK_I_TS_PACKETS_188_MASK                            0x00000008
#define REALTEK_I_TS_CLOCK_GATE_MASK   0x00000020

// DVBT2 Demod Module Pre-Definition
typedef struct DVBT2_DEMOD_MODULE_TAG DVBT2_DEMOD_MODULE;

typedef enum _REALTEK_I_DVBT2_QAM_MODE {
	DVBT2_QAM_4,				///<   QPSK
	DVBT2_QAM_16,				///<   16 QAM
	DVBT2_QAM_64,				///<   64 QAM
	DVBT2_QAM_256,				///<   256 QAM
	DVBT2_QAM_AUTO
} REALTEK_I_DVBT2_QAM_MODE;

typedef enum _REALTEK_I_DEMOD_DVBT2_QAM_MODE {
	DVBT2_DEMOD_QAM_4 = 0,
	DVBT2_DEMOD_QAM_16,
	DVBT2_DEMOD_QAM_64,
	DVBT2_DEMOD_QAM_256,
	DVBT2_DEMOD_QAM_OTHER
} _REALTEK_I_DEMOD_DVBT2_QAM_MODE;

typedef enum {
	DVBT2_DEMOD_BW_UNKNOWN = 0,          /**< Unknown bandwidth */
	DVBT2_DEMOD_BW_1_7_MHZ = 1,          /**< 1.7MHz bandwidth (Valid option for DVB-T2 only) */
	DVBT2_DEMOD_BW_5_MHZ = 5,            /**< 5MHz bandwidth (Valid option for DVB-T / T2) */
	DVBT2_DEMOD_BW_6_MHZ = 6,            /**< 6MHz bandwidth (Valid option for DVB-T / T2 / C2) */
	DVBT2_DEMOD_BW_7_MHZ = 7,            /**< 7MHz bandwidth (Valid option for DVB-T / T2) */
	DVBT2_DEMOD_BW_8_MHZ = 8             /**< 8MHz bandwidth (Valid option for DVB-T / T2 / C / C2) */
} REALTEK_I_DEMOD_DVBT2_BANDWIDTH;

typedef enum _REALTEK_I_DEMOD_TYPE {
	UCC_STANDARD_NOT_SIGNALLED = 0,
	UCC_STANDARD_DVBT,
	UCC_STANDARD_DVBH,
	UCC_STANDARD_ISDBT_1SEG,
	UCC_STANDARD_ISDBT_3SEG,
	UCC_STANDARD_ISDBT_13SEG,
	UCC_STANDARD_DAB,
	UCC_STANDARD_FM,
	UCC_STANDARD_ATSC,
	UCC_STANDARD_DVBC,
	UCC_STANDARD_J83B,
	UCC_STANDARD_ISDBC,
	UCC_STANDARD_DVBT2,
	UCC_STANDARD_DVBS,
	UCC_STANDARD_DVBS2,
	UCC_STANDARD_ISDBS,
	UCC_STANDARD_GB206,
	UCC_STANDARD_ATV,
	UCC_STANDARD_DVBC_ISDBC
} REALTEK_I_DEMOD_TYPE;

typedef enum _REALTEK_I_DEMOD_CTRL {
	TV_CMD_NULL = 0,
	TV_CMD_STOP,
	TV_CMD_DETECT,
	TV_CMD_RUN,
	TV_CMD_UPDATE_RSSI,
	TV_CMD_RESET_COUNTERS,
	TV_CMD_UPDATE_COUNTERS,
	TV_CMD_SET_AGC,
	TV_CMD_UPDATE_AGC,
	TV_CMD_QUERY_STATUS,
} REALTEK_I_DEMOD_CTRL;

typedef int
(*DVBT2_DEMOD_FP_ADDR_8BIT_SET_REG_PAGE)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned long PageNo
);

typedef int
(*DVBT2_DEMOD_FP_ADDR_8BIT_SET_REG_BYTES)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	const unsigned char *pWritingBytes,
	unsigned long ByteNum
);

typedef int
(*DVBT2_DEMOD_FP_ADDR_16BIT_SET_REG_BYTES)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	const unsigned char *pWritingBytes,
	unsigned long ByteNum
);

typedef int
(*DVBT2_DEMOD_FP_ADDR_8BIT_GET_REG_BYTES)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char *pReadingBytes,
	unsigned long ByteNum
);

typedef int
(*DVBT2_DEMOD_FP_ADDR_16BIT_GET_REG_BYTES)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char *pReadingBytes,
	unsigned long ByteNum
);

typedef int
(*DVBT2_DEMOD_FP_ADDR_8BIT_SET_REG_MASK_BITS)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	const unsigned long WritingValue
);

typedef int
(*DVBT2_DEMOD_FP_ADDR_16BIT_SET_REG_MASK_BITS)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	const unsigned long WritingValue
);

typedef int
(*DVBT2_DEMOD_FP_ADDR_8BIT_GET_REG_MASK_BITS)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	unsigned long *pReadingValue
);

typedef int
(*DVBT2_DEMOD_FP_ADDR_16BIT_GET_REG_MASK_BITS)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	unsigned long *pReadingValue
);

typedef int
(*DVBT2_DEMOD_FP_ADDR_8BIT_SET_REG_BITS)(
	DVBT2_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

typedef int
(*DVBT2_DEMOD_FP_ADDR_16BIT_SET_REG_BITS)(
	DVBT2_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

typedef int
(*DVBT2_DEMOD_FP_ADDR_8BIT_GET_REG_BITS)(
	DVBT2_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

typedef int
(*DVBT2_DEMOD_FP_ADDR_16BIT_GET_REG_BITS)(
	DVBT2_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

typedef int
(*DVBT2_DEMOD_FP_ADDR_8BIT_SET_REG_BITS_WITH_PAGE)(
	DVBT2_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

typedef int
(*DVBT2_DEMOD_FP_ADDR_8BIT_GET_REG_BITS_WITH_PAGE)(
	DVBT2_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

// Demod Register Access for 8-bit Address
typedef struct {
	DVBT2_DEMOD_FP_ADDR_8BIT_SET_REG_PAGE             SetRegPage;
	DVBT2_DEMOD_FP_ADDR_8BIT_SET_REG_BYTES            SetRegBytes;
	DVBT2_DEMOD_FP_ADDR_8BIT_GET_REG_BYTES            GetRegBytes;
	DVBT2_DEMOD_FP_ADDR_8BIT_SET_REG_MASK_BITS        SetRegMaskBits;
	DVBT2_DEMOD_FP_ADDR_8BIT_GET_REG_MASK_BITS        GetRegMaskBits;
	DVBT2_DEMOD_FP_ADDR_8BIT_SET_REG_BITS             SetRegBits;
	DVBT2_DEMOD_FP_ADDR_8BIT_GET_REG_BITS             GetRegBits;
	DVBT2_DEMOD_FP_ADDR_8BIT_SET_REG_BITS_WITH_PAGE   SetRegBitsWithPage;
	DVBT2_DEMOD_FP_ADDR_8BIT_GET_REG_BITS_WITH_PAGE   GetRegBitsWithPage;
}
DVBT2_DEMOD_REG_ACCESS_ADDR_8BIT;

// Demod Register Access for 16-bit Address
typedef struct {
	DVBT2_DEMOD_FP_ADDR_16BIT_SET_REG_BYTES       SetRegBytes;
	DVBT2_DEMOD_FP_ADDR_16BIT_GET_REG_BYTES       GetRegBytes;
	DVBT2_DEMOD_FP_ADDR_16BIT_SET_REG_MASK_BITS   SetRegMaskBits;
	DVBT2_DEMOD_FP_ADDR_16BIT_GET_REG_MASK_BITS   GetRegMaskBits;
	DVBT2_DEMOD_FP_ADDR_16BIT_SET_REG_BITS        SetRegBits;
	DVBT2_DEMOD_FP_ADDR_16BIT_GET_REG_BITS        GetRegBits;
}
DVBT2_DEMOD_REG_ACCESS_ADDR_16BIT;

typedef void
(*DVBT2_DEMOD_FP_GET_DEMOD_TYPE)(
	DVBT2_DEMOD_MODULE *pDemod,
	int *pDemodType
);

typedef void
(*DVBT2_DEMOD_FP_GET_DEVICE_ADDR)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned char *pDeviceAddr
);

typedef void
(*DVBT2_DEMOD_FP_GET_CRYSTAL_FREQ_HZ)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned long *pCrystalFreqHz
);

// Demod Common Function Pointer
typedef int
(*DVBT2_DEMOD_FP_CHECK_RPU_READY)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *IsRpuReady
);

typedef int
(*DVBT2_DEMOD_FP_PING_RPU)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *IsLive
);

typedef int
(*DVBT2_DEMOD_FP_SHUT_DOWN)(
	DVBT2_DEMOD_MODULE *pDemod
);

typedef int
(*DVBT2_DEMOD_FP_ACTIVATE_CORE)(
	DVBT2_DEMOD_MODULE *pDemod
);

typedef int
(*DVBT2_DEMOD_FP_DEACTIVATE_CORE)(
	DVBT2_DEMOD_MODULE *pDemod
);

typedef int
(*DVBT2_DEMOD_FP_SWITCH_TO_BUFFER)(
	DVBT2_DEMOD_MODULE *pDemod
);

typedef int
(*DVBT2_DEMOD_FP_GET_DEMOD_INFO)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DemodType
);

typedef int
(*DVBT2_DEMOD_FP_GET_BUILD_ID)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *BuildId
);

typedef int
(*DVBT2_DEMOD_FP_DEMOD_CTRL_STOP)(
	DVBT2_DEMOD_MODULE *pDemod
);

typedef int
(*DVBT2_DEMOD_FP_DEMOD_CTRL_DETECT)(
	DVBT2_DEMOD_MODULE *pDemod
);

typedef int
(*DVBT2_DEMOD_FP_DEMOD_CTRL_RUN)(
	DVBT2_DEMOD_MODULE *pDemod
);

typedef int
(*DVBT2_DEMOD_FP_DEMOD_CTRL_UPDATE_RSSI)(
	DVBT2_DEMOD_MODULE *pDemod
);

typedef int
(*DVBT2_DEMOD_FP_DEMOD_CTRL_RESET_COUNTERS)(
	DVBT2_DEMOD_MODULE *pDemod
);

typedef int
(*DVBT2_DEMOD_FP_DEMOD_CTRL_UPDATE_COUNTERS)(
	DVBT2_DEMOD_MODULE *pDemod
);

typedef int
(*DVBT2_DEMOD_FP_DEMOD_CTRL_SET_AGC)(
	DVBT2_DEMOD_MODULE *pDemod
);

typedef int
(*DVBT2_DEMOD_FP_DEMOD_CTRL_UPDATE_AGC)(
	DVBT2_DEMOD_MODULE *pDemod
);

typedef int
(*DVBT2_DEMOD_FP_DEMOD_CTRL_QUERY_STATUS)(
	DVBT2_DEMOD_MODULE *pDemod
);

typedef int
(*DVBT2_DEMOD_FP_GET_DEMOD_STATUS)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DemodStatus
);

typedef int
(*DVBT2_DEMOD_FP_SET_TUNER_FREQ)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int TunerFreqHz
);

typedef int
(*DVBT2_DEMOD_FP_SET_TUNER_BANDWIDTH)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int TunerBandwidthHz
);

typedef int
(*DVBT2_DEMOD_FP_SET_TUNER_GRID_BASE)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int TunerGridBaseHz
);

typedef int
(*DVBT2_DEMOD_FP_SET_TUNER_GRID_INCR)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int TunerGridIncrHz
);

typedef int
(*DVBT2_DEMOD_FP_SET_NOTCH_FREQ)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int NotchFreqHz
);

typedef int
(*DVBT2_DEMOD_FP_SET_NOTCH_BANDWIDTH)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int NotchBandwidth
);

typedef int
(*DVBT2_DEMOD_FP_GET_ACT_TUNER_FREQ)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *ActiveFreqHz
);

typedef int
(*DVBT2_DEMOD_FP_GET_ACT_TUNER_BANDWIDTH)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *ActiveBandwidth
);

typedef int
(*DVBT2_DEMOD_FP_GET_ACT_TUNER_GAIN)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *ActiveTunerGain
);

typedef int
(*DVBT2_DEMOD_FP_GET_ACT_TUNER_RSSI)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *ActiveTunerRssi
);

typedef int
(*DVBT2_DEMOD_FP_SET_AGC_PARAMS)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int AgcParam,
	unsigned int Index
);

typedef int
(*DVBT2_DEMOD_FP_GET_AGC_PARAMS)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *AgcParam,
	unsigned int Index
);

typedef int
(*DVBT2_DEMOD_FP_SET_TS_CONFIG)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int IsTsDis,
	unsigned int IsSerial,
	unsigned int IsInv,
	unsigned int IsPacket188
);

typedef int
(*DVBT2_DEMOD_FP_SET_TS_CLK_RATE_MARGIN)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int TsClkMargin
);

typedef int
(*DVBT2_DEMOD_FP_SET_TS_CLK_RATE_MAX)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int TsClkRateMax
);

typedef int
(*DVBT2_DEMOD_FP_GET_DEMOD_LOCK_TIME)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DemodLockTimeMs
);

typedef int
(*DVBT2_DEMOD_FP_GET_DVBT_DEMOD_LOCK_TIME)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DemodLockTimeMs
);

typedef int
(*DVBT2_DEMOD_FP_SET_XML_TUNER_CFG_OVERRIDE)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int TunerCfg
);

typedef int
(*DVBT2_DEMOD_FP_SET_XML_TUNER_GAIN_CTRL)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int TunerGainCtrl
);

typedef int
(*DVBT2_DEMOD_FP_SET_XML_FLAGS)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int Flags
);

typedef int
(*DVBT2_DEMOD_FP_SET_XML_IF_FREQ)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int IfFreq
);

typedef int
(*DVBT2_DEMOD_FP_SET_XML_PLFT_CFG_OVERRIDE)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int PlatformCfg
);

typedef int
(*DVBT2_DEMOD_FP_SET_XML_IF_CLK)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int IfClk
);

typedef int
(*DVBT2_DEMOD_FP_SET_XML_LDPC_CLK)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int LdpcClk
);

typedef int
(*DVBT2_DEMOD_FP_SET_XML_UCC_CLK)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int UccClk
);

typedef int
(*DVBT2_DEMOD_FP_SET_XML_MCU_CLK)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int McuClk
);

typedef int
(*DVBT2_DEMOD_FP_SET_VIRTUAL_REGISTER)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int RegAddr,
	unsigned int RegVal
);

typedef int
(*DVBT2_DEMOD_FP_GET_VIRTUAL_REGISTER)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int RegAddr,
	unsigned int *RegVal
);

typedef int
(*DVBT2_DEMOD_FP_SET_CTRL_VIRTUAL_REGISTER)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int PriRegAddr,
	unsigned int SecRegAddr,
	unsigned int RegVal
);

typedef int
(*DVBT2_DEMOD_FP_GET_CTRL_VIRTUAL_REGISTER)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int PriRegAddr,
	unsigned int SecRegAddr,
	unsigned int *RegVal
);

typedef int
(*DVBT2_DEMOD_FP_SET_HW_REGISTER)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int RegAddr,
	unsigned int RegVal
);

typedef int
(*DVBT2_DEMOD_FP_GET_HW_REGISTER)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int RegAddr,
	unsigned int *RegVal
);

// DVBT2 Specific Function Pointer
typedef int
(*DVBT2_DEMOD_FP_SET_T2_PROFILE_CMD)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int T2Profile
);

typedef int
(*DVBT2_DEMOD_FP_SET_DETECT_TIME_CMD)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int DetectTime
);

typedef int
(*DVBT2_DEMOD_FP_SET_HOLD_OFF_TIME_MS)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int HoldOffTimeMs
);

typedef int
(*DVBT2_DEMOD_FP_GET_SIGNAL_INDICATOR)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *SignalIndicator
);

typedef int
(*DVBT2_DEMOD_FP_GET_TS_LOCK_TIME)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *TsLockTime
);

typedef int
(*DVBT2_DEMOD_FP_SET_DVBT2DVBT_SEARCH_MODE)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int DvbT2DvbTSearchMode
);

typedef int
(*DVBT2_DEMOD_FP_SET_P1_SEARCH_TIMEOUT)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int P1SearchTimeout
);

typedef int
(*DVBT2_DEMOD_FP_SET_MIN_P1_CNT)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int MinP1Cnt
);

typedef int
(*DVBT2_DEMOD_FP_SET_DVBT2DVBT_SEARCH_TIMEOUT)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int DvbT2DvbtSearchTimeout
);

typedef int
(*DVBT2_DEMOD_FP_SET_DVBT2DVBT_SEARCH_UPDATE_PERIOD)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int DvbT2DvbtSearchUpdatePeriod
);

typedef int
(*DVBT2_DEMOD_FP_SET_DVBT2DVBT_SEARCH_DECISION_TH1)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int DvbT2DvbtSearchDecisionTh1
);

typedef int
(*DVBT2_DEMOD_FP_SET_DVBT2DVBT_SEARCH_DECISION_TH2)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int DvbT2DvbtSearchDecisionTh2
);

typedef int
(*DVBT2_DEMOD_FP_SET_DVBT2DVBT_SEARCH_RESULT)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int DvbT2DvbTSearchStatus,
	unsigned int DvbT2DvbTSearchResult
);

typedef int
(*DVBT2_DEMOD_FP_GET_DVBT2DVBT_SEARCH_RESULT)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DvbT2DvbTSearchStatus,
	unsigned int *DvbT2DvbTSearchResult
);

typedef int
(*DVBT2_DEMOD_FP_SET_DATA_PLP_ID_SELECT_CMD)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int DataPlpIdSelect
);

typedef int
(*DVBT2_DEMOD_FP_GET_ACTIVE_DATA_PLP_ID)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *ActiveDataPlpId
);

typedef int
(*DVBT2_DEMOD_FP_GET_NUM_DATA_PLPS)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *NumDataPlps
);

typedef int
(*DVBT2_DEMOD_FP_GET_LIST_OF_DATA_PLPS)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int PlpLoopIdx,
	unsigned int *PayloadType,
	unsigned int *PlpType,
	unsigned int *PlpId
);

typedef int
(*DVBT2_DEMOD_FP_GET_DATA_PLP_CODE_RATE)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataPlpCodeRate
);

typedef int
(*DVBT2_DEMOD_FP_GET_DATA_PLP_MODULATION)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataPlpModulation
);

typedef int
(*DVBT2_DEMOD_FP_SET_SFOPPM)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int SfoPppmQ16_15
);

typedef int
(*DVBT2_DEMOD_FP_GET_SFOPPM)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *SfoPpmQ16_15
);

typedef int
(*DVBT2_DEMOD_FP_SET_DTAT_ERROR_COUNTERS_CMD)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int DataErrorCount
);

typedef int
(*DVBT2_DEMOD_FP_GET_DATA_DECODED_FRAMES)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataDecodedFrames
);

typedef int
(*DVBT2_DEMOD_FP_GET_DATA_LDPC_STUCK_FRAMES)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataLdpcStuckFrames
);

typedef int
(*DVBT2_DEMOD_FP_GET_DATA_LDPC_UNSTABLE_FRAMES)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataLdpcUnstableFrames
);

typedef int
(*DVBT2_DEMOD_FP_GET_LDPC_FRAMES_WITH_PARITY_FAILURE)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataLdpcFramesWithParityFailure
);

typedef int
(*DVBT2_DEMOD_FP_GET_DATA_LDPC_PARITY_CHECK_FAILURE)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataLdpcParityCheckFailure
);

typedef int
(*DVBT2_DEMOD_FP_GET_UNCORRECTABLE_BCH_CWS)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *UncorrectableBchCws
);

typedef int
(*DVBT2_DEMOD_FP_GET_CORRECTED_BCH_BYTES)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CorrectedBchBytes
);

typedef int
(*DVBT2_DEMOD_FP_GET_CORRECTED_BCH_BITS)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CorrectedBchBits
);

typedef int
(*DVBT2_DEMOD_FP_SET_COMMON_PLP_ERROR_COUNTER_CMD)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int CommonPlpErrorCounter
);

typedef int
(*DVBT2_DEMOD_FP_GET_COMMON_DECODED_FRAMES)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonDecodedFrames
);

typedef int
(*DVBT2_DEMOD_FP_GET_COMMON_LDPC_STUCK_FRAMES)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonLdpcStuckFrames
);

typedef int
(*DVBT2_DEMOD_FP_GET_COMMON_LDPC_UNSTABLE_FRAMES)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonLdpcUnstableFrames
);

typedef int
(*DVBT2_DEMOD_FP_GET_COMMON_LDPC_FRAMES_WITH_PARITY_FAILURE)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonLDPCFrameWithParityFailure
);

typedef int
(*DVBT2_DEMOD_FP_GET_COMMON_LDPC_PARITY_CHECK_FAILURE)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonLDPCParityCheckFailure
);

typedef int
(*DVBT2_DEMOD_FP_GET_COMMON_BCH_UNCORRECTABLE_CWS)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonBchUncorrectableCws
);

typedef int
(*DVBT2_DEMOD_FP_GET_COMMON_BCH_CORRECTED_BYTES)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonBchCorrectedByte
);

typedef int
(*DVBT2_DEMOD_FP_GET_COMMON_BCH_CORRECTED_BITS)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonBchCorrectedBit
);

typedef int
(*DVBT2_DEMOD_FP_SET_ERR_RATE_INTEG_PERIOD)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int ErrRateIntegPeriod
);

typedef int
(*DVBT2_DEMOD_FP_GET_ERR_RATE_INTEG_PERIOD)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *ErrRateIntegPeriod
);

typedef int
(*DVBT2_DEMOD_FP_GET_ERROR_RATE_UPDATES)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataErrorRateUpdate
);

typedef int
(*DVBT2_DEMOD_FP_GET_DATA_LDPC_OUTPUT_FER)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataLdpcOutputFer
);

typedef int
(*DVBT2_DEMOD_FP_GET_DATA_BCH_INPUT_BER)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataBchInputBer
);

typedef int
(*DVBT2_DEMOD_FP_GET_BCH_OUTPUT_FER)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataBchcOutputFer
);

typedef int
(*DVBT2_DEMOD_FP_GET_TS_BAD_PACKETS)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataTsBadPackets
);

typedef int
(*DVBT2_DEMOD_FP_GET_SQI)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *Sqi
);

typedef int
(*DVBT2_DEMOD_FP_GET_COMMON_RATE_UPDATE)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonRateUpdate
);

typedef int
(*DVBT2_DEMOD_FP_GET_COMMON_LDPC_INPUT_BER)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonLdpcInputBer
);

typedef int
(*DVBT2_DEMOD_FP_GET_COMMON_BCH_INPUT_BER)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonBchInputBer
);

typedef int
(*DVBT2_DEMOD_FP_GET_COMMON_BCH_OUTPUT_FER)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonBchOutputFer
);

typedef int
(*DVBT2_DEMOD_FP_GET_SYM_STATUS_UPDATES)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *SymStatusUpdate
);

typedef int
(*DVBT2_DEMOD_FP_GET_SYM_SYMBOL_COUNT)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *SymSymbolCount
);

typedef int
(*DVBT2_DEMOD_FP_GET_SYM_FRAME_COUNT)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *SymSymbolCount
);

typedef int
(*DVBT2_DEMOD_FP_GET_SYM_CSI_SNR)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *SymCsiSnr
);

typedef int
(*DVBT2_DEMOD_FP_GET_SYM_NOISE_VER)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *SymNoiseVar
);

typedef int
(*DVBT2_DEMOD_FP_GET_SYM_CHANNEL_DELAY_SPREAD)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *SymChannelDelaySpread
);

typedef int
(*DVBT2_DEMOD_FP_GET_SSI)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *SymSsi
);

typedef int
(*DVBT2_DEMOD_FP_GET_DATA_HEM)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataHem
);

typedef int
(*DVBT2_DEMOD_FP_GET_DATA_ISSYI)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataIssyi
);

typedef int
(*DVBT2_DEMOD_FP_GET_DATA_NPD)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataNpd
);

typedef int
(*DVBT2_DEMOD_FP_GET_DATA_VAR_DFL)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataBarDfl
);

typedef int
(*DVBT2_DEMOD_FP_GET_DATA_PACKETS)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataPackets
);

typedef int
(*DVBT2_DEMOD_FP_GET_DATA_BIT_RATE)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DataBitRate
);

typedef int
(*DVBT2_DEMOD_FP_GET_COMMON_HEM)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonHem
);

typedef int
(*DVBT2_DEMOD_FP_GET_COMMON_ISSYI)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonIssyi
);

typedef int
(*DVBT2_DEMOD_FP_GET_COMMON_NPD)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonNpd
);

typedef int
(*DVBT2_DEMOD_FP_GET_COMMON_VAR_DFL)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonVarDfl
);

typedef int
(*DVBT2_DEMOD_FP_GET_COMMON_PACKETS)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonPackets
);

typedef int
(*DVBT2_DEMOD_FP_GET_COMMON_BIT_RATE)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *CommonBitRate
);

typedef int
(*DVBT2_DEMOD_FP_GET_L1_INFO)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *L1Info
);

typedef int
(*DVBT2_DEMOD_FP_SET_CONS_BUFF_HOST_STATUS_CMD)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int ConsBuffHostStatus
);

typedef int
(*DVBT2_DEMOD_FP_GET_CONS_BUFF_HOST_STATUS_CMD)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *ConsBuffHostStatus
);

typedef int
(*DVBT2_DEMOD_FP_GET_CONS_BUFF_ADDRESS)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *ConsBuffHostAddress
);

typedef int
(*DVBT2_DEMOD_FP_GET_CONS_SAMPLE_NUM)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *ConsSampleNum
);

typedef int
(*DVBT2_DEMOD_FP_GET_DVBT_TPS_SYNC_RESULT)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DvbTTpsSyncRst
);

typedef int
(*DVBT2_DEMOD_FP_GET_DVBT_SSI)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DvbTSsi
);

typedef int
(*DVBT2_DEMOD_FP_GET_DVBT_SQI)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DvbTSqi
);

typedef int
(*DVBT2_DEMOD_FP_SET_DVBT_STAT_CTRL)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int StatCtrl
);

typedef int
(*DVBT2_DEMOD_FP_GET_DVBT_SNR)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *StatSnr
);

typedef int
(*DVBT2_DEMOD_FP_SET_DVBT_BER_PERIOD)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int BerPeriod
);

typedef int
(*DVBT2_DEMOD_FP_GET_DVBT_RS_BER)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *BerRsBer
);

typedef int
(*DVBT2_DEMOD_FP_GET_DVBT_TS_PER)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *BerTsPer
);

typedef int
(*DVBT2_DEMOD_FP_GET_DVBT_TS_BAD_PKT_CNT)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *StatTsBadPktCount
);

typedef int
(*DVBT2_DEMOD_FP_GET_DVBT_TUN_MOD)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *TunMod
);

typedef int
(*DVBT2_DEMOD_FP_GET_DVBT_TUN_CODE_RATE)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *TunCodeRate
);

typedef int
(*DVBT2_DEMOD_FP_GET_DVBT_TS_PKT_CNT)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *TPktCnt
);

typedef int
(*DVBT2_DEMOD_FP_GET_DVBT_CFO)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *Cfo
);

typedef int
(*DVBT2_DEMOD_FP_SET_DVBT_DETECT_MASK)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int DetectMask
);

typedef int
(*DVBT2_DEMOD_FP_GET_IF_AGC_GAIN)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *IfAgcGain
);


typedef int
(*DVBT2_DEMOD_FP_SET_TUN_HIERARCHICAL)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int TunHierarchical
);

typedef int
(*DVBT2_DEMOD_FP_GET_TUN_HIERARCHICAL)(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *TunHierarchical
);

// DVBT2 Demod Default I2C Functions for 8-bit Address
int
dvbt2_demod_addr_8bit_default_SetRegPage(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned long PageNo
);

int
dvbt2_demod_addr_8bit_default_SetRegBytes(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	const unsigned char *pWritingBytes,
	unsigned long ByteNum
);

int
dvbt2_demod_addr_8bit_default_GetRegBytes(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char *pReadingBytes,
	unsigned long ByteNum
);

int
dvbt2_demod_addr_8bit_default_SetRegMaskBits(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	const unsigned long WritingValue
);

int
dvbt2_demod_addr_8bit_default_GetRegMaskBits(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	unsigned long *pReadingValue
);

int
dvbt2_demod_addr_8bit_default_SetRegBits(
	DVBT2_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

int
dvbt2_demod_addr_8bit_default_GetRegBits(
	DVBT2_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

int
dvbt2_demod_addr_8bit_default_SetRegBitsWithPage(
	DVBT2_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

int
dvbt2_demod_addr_8bit_default_GetRegBitsWithPage(
	DVBT2_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

// DVBT2 Demod Default I2C Functions for 16-bit Address
int
dvbt2_demod_addr_16bit_default_SetRegBytes(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	const unsigned char *pWritingBytes,
	unsigned long ByteNum
);

int
dvbt2_demod_addr_16bit_default_GetRegBytes(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char *pReadingBytes,
	unsigned long ByteNum
);

int
dvbt2_demod_addr_16bit_default_SetRegMaskBits(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	const unsigned long WritingValue
);

int
dvbt2_demod_addr_16bit_default_GetRegMaskBits(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	unsigned long *pReadingValue
);

int
dvbt2_demod_addr_16bit_default_SetRegBits(
	DVBT2_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

int
dvbt2_demod_addr_16bit_default_GetRegBits(
	DVBT2_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

// DVBT2 Demod Default Manipulating Functions
void
dvbt2_demod_default_GetDemodType(
	DVBT2_DEMOD_MODULE *pDemod,
	int *pDemodType
);

void
dvbt2_demod_default_GetDeviceAddr(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned char *pDeviceAddr
);

void
dvbt2_demod_default_GetCrystalFreqHz(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned long *pCrystalFreqHz
);

int
dvbt2_demod_default_GetQamMode(
	DVBT2_DEMOD_MODULE *pDemod,
	int *pQamMode
);

int
dvbt2_demod_default_GetSymbolRateHz(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned long *pSymbolRateHz
);

int
dvbt2_demod_default_GetAlphaMode(
	DVBT2_DEMOD_MODULE *pDemod,
	int *pAlphaMode
);

int
dvbt2_demod_default_GetIfFreqHz(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned long *pIfFreqHz
);

int
dvbt2_demod_default_GetSpectrumMode(
	DVBT2_DEMOD_MODULE *pDemod,
	int *pSpectrumMode
);

// Demod Common Function
int
realtek_i_dvbt2_common_CheckRpuReady(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *IsRpuReady
);

int
realtek_i_dvbt2_common_PingRpu(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *IsLive
);

int
realtek_i_dvbt2_common_ShutDown(
	DVBT2_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbt2_common_ActivateCore(
	DVBT2_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbt2_common_DeactivateCore(
	DVBT2_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbt2_common_SwitchToBuffer(
	DVBT2_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbt2_common_GetDemodInfo(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DemodType
);

int
realtek_i_dvbt2_common_GetBuildId(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *BuildId
);

int
realtek_i_dvbt2_common_DemodCtrlStopCmd(
	DVBT2_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbt2_common_DemodCtrlDetectCmd(
	DVBT2_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbt2_common_DemodCtrlRunCmd(
	DVBT2_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbt2_common_DemodCtrlUpdateRssiCmd(
	DVBT2_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbt2_common_DemodCtrlResetCountersCmd(
	DVBT2_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbt2_common_DemodCtrlUpdateCountersCmd(
	DVBT2_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbt2_common_DemodCtrlSetAgcCmd(
	DVBT2_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbt2_common_DemodCtrlUpdateAgcCmd(
	DVBT2_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbt2_common_DemodCtrlQueryStatusCmd(
	DVBT2_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbt2_common_GetDemodStatus(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DemodStatus
);

int
realtek_i_dvbt2_common_SetTunerFreqCmd(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int TunerFreqHz
);

int
realtek_i_dvbt2_common_SetTunerBandwidth(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int TunerBandwidthHz
);

int
realtek_i_dvbt2_common_SetTunerGridBase(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int TunerGridBaseHz
);

int
realtek_i_dvbt2_common_SetTunerGridIncr(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int TunerGridIncrHz
);

int
realtek_i_dvbt2_common_SetNotchFreqCmd(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int NotchFreqHz
);

int
realtek_i_dvbt2_common_SetNotchBandwidth(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int NotchBandwidth
);

int
realtek_i_dvbt2_common_GetActiveTunerFreq(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *ActiveFreqHz
);

int
realtek_i_dvbt2_common_GetActiveTunerBandwidth(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *ActiveBandwidth
);

int
realtek_i_dvbt2_common_GetActiveTunerGain(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *ActiveTunerGain
);

int
realtek_i_dvbt2_common_GetActiveTunerRssi(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *ActiveTunerRssi
);

int
realtek_i_dvbt2_common_SetAgcParams(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int AgcParam,
	unsigned int Index
);

int
realtek_i_dvbt2_common_GetAgcParams(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *AgcParam,
	unsigned int Index
);

int
realtek_i_dvbt2_common_SetTsConfig(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int IsTsDis,
	unsigned int IsSerial,
	unsigned int IsInv,
	unsigned int IsPacket188
);

int
realtek_i_dvbt2_common_SetTsClkRateMargin(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int TsClkMargin
);

int
realtek_i_dvbt2_common_SetTsClkRateMax(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int TsClkRateMax
);

int
realtek_i_dvbt2_common_GetDemodLockTime(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DemodLockTimeMs
);

int
realtek_i_dvbt2_common_GetDvbTDemodLockTime(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int *DemodLockTimeMs
);

int
realtek_i_dvbt2_common_SetXmlTunerCfgOverride(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int TunerCfg
);

int
realtek_i_dvbt2_common_SetXmlTunerGainCtrl(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int TunerGainCtrl
);

int
realtek_i_dvbt2_common_SetXmlFlags(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int Flags
);

int
realtek_i_dvbt2_common_SetXmlIfFreq(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int IfFreq
);

int
realtek_i_dvbt2_common_SetXmlPlatformCfgOverride(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int PlatformCfg
);

int
realtek_i_dvbt2_common_SetXmlIfClk(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int IfClk
);

int
realtek_i_dvbt2_common_SetXmlLdpcClk(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int LdpcClk
);

int
realtek_i_dvbt2_common_SetXmlUccClk(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int UccClk
);

int
realtek_i_dvbt2_common_SetXmlMcuClk(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int McuClk
);

int
realtek_i_dvbt2_common_SetVirtualRegister(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int RegAddr,
	unsigned int RegVal
);

int
realtek_i_dvbt2_common_GetVirtualRegister(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int RegAddr,
	unsigned int *RegVal
);

int
realtek_i_dvbt2_common_SetCtrlVirtualRegister(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int PriRegAddr,
	unsigned int SecRegAddr,
	unsigned int RegVal
);

int
realtek_i_dvbt2_common_GetCtrlVirtualRegister(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int PriRegAddr,
	unsigned int SecRegAddr,
	unsigned int *RegVal
);

int
realtek_i_dvbt2_common_SetHwRegister(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int RegAddr,
	unsigned int RegVal
);

int
realtek_i_dvbt2_common_GetHwRegister(
	DVBT2_DEMOD_MODULE *pDemod,
	unsigned int RegAddr,
	unsigned int *RegVal
);


// DVBT2 Demod Module Structure
struct DVBT2_DEMOD_MODULE_TAG {
	// Private Variables
	int           DemodType;
	unsigned char DeviceAddr;
	unsigned long CrystalFreqHz;
	int           TsInterfaceMode;

	int           QamMode;
	unsigned long SymbolRateHz;
	int           AlphaMode;
	unsigned long IfFreqHz;
	int           SpectrumMode;
	unsigned long TunerFreqHz;//Hz
	//REALTEK_I_TV_SYSTEM DemodSystem;

	int           IsQamModeSet;
	int           IsSymbolRateHzSet;
	int           IsAlphaModeSet;
	int           IsIfFreqHzSet;
	int           IsSpectrumModeSet;

	BASE_INTERFACE_MODULE *pBaseInterface;
	I2C_BRIDGE_MODULE *pI2cBridge;

	// Demod I2C Function Pointers
	union {
		DVBT2_DEMOD_REG_ACCESS_ADDR_8BIT  Addr8Bit;
		DVBT2_DEMOD_REG_ACCESS_ADDR_16BIT Addr16Bit;
	}
	RegAccess;

	// Demod Manipulating Function Pointers
	DVBT2_DEMOD_FP_GET_DEMOD_TYPE                   GetDemodType;
	DVBT2_DEMOD_FP_GET_DEVICE_ADDR                  GetDeviceAddr;
	DVBT2_DEMOD_FP_GET_CRYSTAL_FREQ_HZ              GetCrystalFreqHz;

	// Common TV Api
	DVBT2_DEMOD_FP_CHECK_RPU_READY                  CheckRpuReady;
	DVBT2_DEMOD_FP_PING_RPU                         PingRpu;
	DVBT2_DEMOD_FP_SHUT_DOWN                        ShutDown;
	DVBT2_DEMOD_FP_ACTIVATE_CORE                    ActivateCore;
	DVBT2_DEMOD_FP_DEACTIVATE_CORE                  DeactivateCore;
	DVBT2_DEMOD_FP_GET_DEMOD_INFO                   GetDemodInfo;
	DVBT2_DEMOD_FP_GET_BUILD_ID                     GetBuildId;
	DVBT2_DEMOD_FP_DEMOD_CTRL_STOP                  DemodCtrlStop;
	DVBT2_DEMOD_FP_DEMOD_CTRL_DETECT                DemodCtrlDetect;
	DVBT2_DEMOD_FP_DEMOD_CTRL_RUN                   DemodCtrlRun;
	DVBT2_DEMOD_FP_DEMOD_CTRL_UPDATE_RSSI           DemodCtrlUpdateRssi;
	DVBT2_DEMOD_FP_DEMOD_CTRL_RESET_COUNTERS        DemodCtrlResetCounters;
	DVBT2_DEMOD_FP_DEMOD_CTRL_UPDATE_COUNTERS       DemodCtrlUpdateCounters;
	DVBT2_DEMOD_FP_DEMOD_CTRL_SET_AGC               DemodCtrlSetAgc;
	DVBT2_DEMOD_FP_DEMOD_CTRL_UPDATE_AGC            DemodCtrlUpdateAgc;
	DVBT2_DEMOD_FP_DEMOD_CTRL_QUERY_STATUS          DemodCtrlQueryStatus;
	DVBT2_DEMOD_FP_GET_DEMOD_STATUS                 GetDemodStatus;
	DVBT2_DEMOD_FP_SET_TUNER_FREQ                   SetTunerFreq;
	DVBT2_DEMOD_FP_SET_TUNER_BANDWIDTH              SetTunerBandwidth;
	DVBT2_DEMOD_FP_SET_TUNER_GRID_BASE              SetTunerGridBase;
	DVBT2_DEMOD_FP_SET_TUNER_GRID_INCR              SetTunerGridIncr;
	DVBT2_DEMOD_FP_SET_NOTCH_FREQ                   SetNotchFreq;
	DVBT2_DEMOD_FP_SET_NOTCH_BANDWIDTH              SetNotchBandwidth;
	DVBT2_DEMOD_FP_GET_ACT_TUNER_FREQ               GetActiveTunerFreq;
	DVBT2_DEMOD_FP_GET_ACT_TUNER_BANDWIDTH          GetActiveTunerBandwidth;
	DVBT2_DEMOD_FP_GET_ACT_TUNER_GAIN               GetActiveTunerGain;
	DVBT2_DEMOD_FP_GET_ACT_TUNER_RSSI               GetActiveTunerRssi;
	DVBT2_DEMOD_FP_SET_AGC_PARAMS                   SetAgcParams;
	DVBT2_DEMOD_FP_GET_AGC_PARAMS                   GetAgcParams;
	DVBT2_DEMOD_FP_SET_TS_CONFIG                    SetTsConfig;
	DVBT2_DEMOD_FP_SET_TS_CLK_RATE_MARGIN           SetTsClkRateMargin;
	DVBT2_DEMOD_FP_SET_TS_CLK_RATE_MAX              SetTsClkRateMax;
	DVBT2_DEMOD_FP_GET_DEMOD_LOCK_TIME              GetDemodLockTime;
	DVBT2_DEMOD_FP_GET_DVBT_DEMOD_LOCK_TIME         GetDvbTDemodLockTime;
	DVBT2_DEMOD_FP_SET_XML_TUNER_CFG_OVERRIDE       SetXmlTunerCfgOverride;
	DVBT2_DEMOD_FP_SET_XML_TUNER_GAIN_CTRL          SetXmlTunerGainCtrl;
	DVBT2_DEMOD_FP_SET_XML_FLAGS                    SetXmlFlags;
	DVBT2_DEMOD_FP_SET_XML_IF_FREQ                  SetXmlIfFreq;
	DVBT2_DEMOD_FP_SET_XML_PLFT_CFG_OVERRIDE        SetXmlPlftCfgOverride;
	DVBT2_DEMOD_FP_SET_XML_IF_CLK                   SetXmlIfClk;
	DVBT2_DEMOD_FP_SET_XML_LDPC_CLK                 SetXmlLdpcClk;
	DVBT2_DEMOD_FP_SET_XML_UCC_CLK                  SetXmlUccClk;
	DVBT2_DEMOD_FP_SET_XML_MCU_CLK                  SetXmlMcuClk;
	DVBT2_DEMOD_FP_SET_VIRTUAL_REGISTER             SetVirtualRegister;
	DVBT2_DEMOD_FP_GET_VIRTUAL_REGISTER             GetVirtualRegister;
	DVBT2_DEMOD_FP_SET_CTRL_VIRTUAL_REGISTER        SetCtrlVirtualRegister;
	DVBT2_DEMOD_FP_GET_CTRL_VIRTUAL_REGISTER        GetCtrlVirtualRegister;
	DVBT2_DEMOD_FP_SET_HW_REGISTER                  SetHwRegister;
	DVBT2_DEMOD_FP_GET_HW_REGISTER                  GetHwRegister;
	DVBT2_DEMOD_FP_SWITCH_TO_BUFFER                 SwitchToBuffer;

	// DVBT2 Specific Api
	DVBT2_DEMOD_FP_SET_T2_PROFILE_CMD                           SetT2ProfileCmd;
	DVBT2_DEMOD_FP_SET_DETECT_TIME_CMD                          SetDetectTimeCmd;
	DVBT2_DEMOD_FP_SET_HOLD_OFF_TIME_MS                         SetHoldOffTimeMs;
	DVBT2_DEMOD_FP_GET_SIGNAL_INDICATOR                         GetSignalIndicator;
	DVBT2_DEMOD_FP_GET_TS_LOCK_TIME                             GetTsLockTime;
	DVBT2_DEMOD_FP_SET_DVBT2DVBT_SEARCH_MODE                    SetDvbT2DvbTSearchMode;
	DVBT2_DEMOD_FP_SET_P1_SEARCH_TIMEOUT                        SetP1SearchTimeout;
	DVBT2_DEMOD_FP_SET_MIN_P1_CNT                               SetMinP1Cnt;
	DVBT2_DEMOD_FP_SET_DVBT2DVBT_SEARCH_TIMEOUT                 SetDvbT2DvbtSearchTimeout;
	DVBT2_DEMOD_FP_SET_DVBT2DVBT_SEARCH_UPDATE_PERIOD           SetDvbT2DvbtSearchUpdatePeriod;
	DVBT2_DEMOD_FP_SET_DVBT2DVBT_SEARCH_DECISION_TH1            SetDvbT2DvbtSearchDecisionTh1;
	DVBT2_DEMOD_FP_SET_DVBT2DVBT_SEARCH_DECISION_TH2            SetDvbT2DvbtSearchDecisionTh2;
	DVBT2_DEMOD_FP_SET_DVBT2DVBT_SEARCH_RESULT                  SetDvbT2DvbTSearchResult;
	DVBT2_DEMOD_FP_GET_DVBT2DVBT_SEARCH_RESULT                  GetDvbT2DvbTSearchResult;
	DVBT2_DEMOD_FP_SET_DATA_PLP_ID_SELECT_CMD                   SetDataPlpIdSelectCmd;
	DVBT2_DEMOD_FP_GET_ACTIVE_DATA_PLP_ID                       GetActiveDataPlpId;
	DVBT2_DEMOD_FP_GET_NUM_DATA_PLPS                            GetNumDataPlps;
	DVBT2_DEMOD_FP_GET_LIST_OF_DATA_PLPS                        GetListOfDataPlps;
	DVBT2_DEMOD_FP_GET_DATA_PLP_CODE_RATE                       GetDataPlpCodeRate;
	DVBT2_DEMOD_FP_GET_DATA_PLP_MODULATION                      GetDataPlpModulation;
	DVBT2_DEMOD_FP_SET_SFOPPM                                   SetSfoPpm;
	DVBT2_DEMOD_FP_GET_SFOPPM                                   GetSfoPpm;
	DVBT2_DEMOD_FP_SET_DTAT_ERROR_COUNTERS_CMD                  SetDataErrorCountersCmd;
	DVBT2_DEMOD_FP_GET_DATA_DECODED_FRAMES                      GetDataDecodedFrames;
	DVBT2_DEMOD_FP_GET_DATA_LDPC_STUCK_FRAMES                   GetDataLdpcStuckFrames;
	DVBT2_DEMOD_FP_GET_DATA_LDPC_UNSTABLE_FRAMES                GetDataPlpLdpcUnstableFrames;
	DVBT2_DEMOD_FP_GET_LDPC_FRAMES_WITH_PARITY_FAILURE          GetDataLdpcFramesWithParityFailure;
	DVBT2_DEMOD_FP_GET_DATA_LDPC_PARITY_CHECK_FAILURE           GetDataLdpcParityCheckFailure;
	DVBT2_DEMOD_FP_GET_UNCORRECTABLE_BCH_CWS                    GetUncorrectableBchCws;
	DVBT2_DEMOD_FP_GET_CORRECTED_BCH_BYTES                      GetCorrectedBchBytes;
	DVBT2_DEMOD_FP_GET_CORRECTED_BCH_BITS                       GetCorrectedBchBits;
	DVBT2_DEMOD_FP_SET_COMMON_PLP_ERROR_COUNTER_CMD             SetCommonPlpErrorCounterCmd;
	DVBT2_DEMOD_FP_GET_COMMON_DECODED_FRAMES                    GetCommonDecodedFrames;
	DVBT2_DEMOD_FP_GET_COMMON_LDPC_STUCK_FRAMES                 GetCommonLdpcStuckFrames;
	DVBT2_DEMOD_FP_GET_COMMON_LDPC_UNSTABLE_FRAMES              GetCommonLdpcUnstableFrames;
	DVBT2_DEMOD_FP_GET_COMMON_LDPC_FRAMES_WITH_PARITY_FAILURE   GetCommonLdpcFrameWithParityFailure;
	DVBT2_DEMOD_FP_GET_COMMON_LDPC_PARITY_CHECK_FAILURE         GetCommonLdcpParityCheckFailure;
	DVBT2_DEMOD_FP_GET_COMMON_BCH_UNCORRECTABLE_CWS             GetCommonBchUncorrectableCws;
	DVBT2_DEMOD_FP_GET_COMMON_BCH_CORRECTED_BYTES               GetCommonBchCorrectedBytes;
	DVBT2_DEMOD_FP_GET_COMMON_BCH_CORRECTED_BITS                GetCommonBchCorrectedBits;
	DVBT2_DEMOD_FP_SET_ERR_RATE_INTEG_PERIOD                    SetErrRateIntegPeriod;
	DVBT2_DEMOD_FP_GET_ERR_RATE_INTEG_PERIOD                    GetErrRateIntegPeriod;
	DVBT2_DEMOD_FP_GET_ERROR_RATE_UPDATES                       GetDataErrorRateUpdates;
	DVBT2_DEMOD_FP_GET_DATA_LDPC_OUTPUT_FER                     GetDataLdpcOutputFer;
	DVBT2_DEMOD_FP_GET_DATA_BCH_INPUT_BER                       GetDataBchInputBer;
	DVBT2_DEMOD_FP_GET_BCH_OUTPUT_FER                           GetDataBchOutputFer;
	DVBT2_DEMOD_FP_GET_TS_BAD_PACKETS                           GetTsBadPackets;
	DVBT2_DEMOD_FP_GET_SQI                                      GetSqi;
	DVBT2_DEMOD_FP_GET_COMMON_RATE_UPDATE                       GetCommonRateUpdate;
	DVBT2_DEMOD_FP_GET_COMMON_LDPC_INPUT_BER                    GetCommonLdpcInputBer;
	DVBT2_DEMOD_FP_GET_COMMON_BCH_INPUT_BER                     GetCommonBchInputBer;
	DVBT2_DEMOD_FP_GET_COMMON_BCH_OUTPUT_FER                    GetCommonBchOutputFer;
	DVBT2_DEMOD_FP_GET_SYM_STATUS_UPDATES                       GetSymStatusUpdates;
	DVBT2_DEMOD_FP_GET_SYM_SYMBOL_COUNT                         GetSymSymbolCount;
	DVBT2_DEMOD_FP_GET_SYM_FRAME_COUNT                          GetSymFrameCount;
	DVBT2_DEMOD_FP_GET_SYM_CSI_SNR                              GetSymCsiSnr;
	DVBT2_DEMOD_FP_GET_SYM_NOISE_VER                            GetSymNoiseVar;
	DVBT2_DEMOD_FP_GET_SYM_CHANNEL_DELAY_SPREAD                 GetSymChannelDelaySpread;
	DVBT2_DEMOD_FP_GET_SSI                                      GetSsi;
	DVBT2_DEMOD_FP_GET_DATA_HEM                                 GetDataHem;
	DVBT2_DEMOD_FP_GET_DATA_ISSYI                               GetDataIssyi;
	DVBT2_DEMOD_FP_GET_DATA_NPD                                 GetDataNpd;
	DVBT2_DEMOD_FP_GET_DATA_VAR_DFL                             GetDataVarDfl;
	DVBT2_DEMOD_FP_GET_DATA_PACKETS                             GetDataPackets;
	DVBT2_DEMOD_FP_GET_DATA_BIT_RATE                            GetDataBitRate;
	DVBT2_DEMOD_FP_GET_COMMON_HEM                               GetCommonHem;
	DVBT2_DEMOD_FP_GET_COMMON_ISSYI                             GetCommonIssyi;
	DVBT2_DEMOD_FP_GET_COMMON_NPD                               GetCommonNpd;
	DVBT2_DEMOD_FP_GET_COMMON_VAR_DFL                           GetCommonVarDfl;
	DVBT2_DEMOD_FP_GET_COMMON_PACKETS                           GetCommonPackets;
	DVBT2_DEMOD_FP_GET_COMMON_BIT_RATE                          GetCommonBitRate;
	DVBT2_DEMOD_FP_GET_L1_INFO                                  GetL1Info;
	DVBT2_DEMOD_FP_SET_CONS_BUFF_HOST_STATUS_CMD                SetConsBuffHostStatusCmd;
	DVBT2_DEMOD_FP_GET_CONS_BUFF_HOST_STATUS_CMD                GetConsBuffHostStatusCmd;
	DVBT2_DEMOD_FP_GET_CONS_BUFF_ADDRESS                        GetConsBuffAddress;
	DVBT2_DEMOD_FP_GET_CONS_SAMPLE_NUM                          GetConsSampleNum;
	DVBT2_DEMOD_FP_GET_DVBT_TPS_SYNC_RESULT                     GetDvbTTpsSyncResult;
	DVBT2_DEMOD_FP_GET_DVBT_SSI                                 GetDvbTSsi;
	DVBT2_DEMOD_FP_GET_DVBT_SQI                                 GetDvbTSqi;
	DVBT2_DEMOD_FP_SET_DVBT_STAT_CTRL                           SetDvbTStatCtrl;
	DVBT2_DEMOD_FP_GET_DVBT_SNR                                 GetDvbTSnr;
	DVBT2_DEMOD_FP_SET_DVBT_BER_PERIOD                          SetDvbTBerPeriod;
	DVBT2_DEMOD_FP_GET_DVBT_RS_BER                              GetDvbTRsBer;
	DVBT2_DEMOD_FP_GET_DVBT_TS_PER                              GetDvbTTsPer;
	DVBT2_DEMOD_FP_GET_DVBT_TS_BAD_PKT_CNT                      GetDvbTTsBadPktCount;
	DVBT2_DEMOD_FP_GET_DVBT_TUN_MOD                             GetDvbTTunMod;
	DVBT2_DEMOD_FP_GET_DVBT_TUN_CODE_RATE                       GetDvbTTunCodeRate;
	DVBT2_DEMOD_FP_GET_DVBT_TS_PKT_CNT                          GetDvbTTsPktCnt;
	DVBT2_DEMOD_FP_GET_DVBT_CFO                                 GetDvbTCfo;
	DVBT2_DEMOD_FP_SET_DVBT_DETECT_MASK                         SetDvbTDetectMask;
	DVBT2_DEMOD_FP_GET_IF_AGC_GAIN                              GetIfAgcGain;
	DVBT2_DEMOD_FP_SET_TUN_HIERARCHICAL                     SetDvbTTunHierarchical;
	DVBT2_DEMOD_FP_GET_TUN_HIERARCHICAL                     GetDvbTTunHierarchical;
};

#define REALTEK_I_DVBT2_BASE_PRINT_LVL_DBG      0
#define REALTEK_I_DVBT2_BASE_PRINT_LVL_INFO     1
#define REALTEK_I_DVBT2_BASE_PRINT_LVL_WARNING  2


#ifndef REALTEK_I_DVBT2_BASE_PRINT_LVL
#define REALTEK_I_DVBT2_BASE_PRINT_LVL          REALTEK_I_DVBT2_BASE_PRINT_LVL_INFO
#endif

#define REALTEK_I_DVBT2_BASE_DBG(fmt, args...)        rtd_printk_demod(KERN_DEBUG, "DEMO", "DVBT2_BASE_DEBUG, " fmt, ##args);
#define REALTEK_I_DVBT2_BASE_INFO(fmt, args...)       rtd_printk_demod(KERN_DEBUG, "DEMO", "DVBT2_BASE_DEBUG, " fmt, ##args);
#define REALTEK_I_DVBT2_BASE_WARNING(fmt, args...)    rtd_printk_demod(KERN_WARNING, "DEMO", "DVBT2_BASE_WARNING, " fmt, ##args);


#ifdef __cplusplus
}
#endif
#endif
