#ifndef __QAM_DEMOD_BASE_H
#define __QAM_DEMOD_BASE_H

#include "foundation.h"

#ifdef __cplusplus
extern "C" {
#endif

#if 0
// Common Register Index
#define TV_REG_API_VERSION                      0
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
#define TV_REG_ENSIGMA_SDK_LOGGING              22  //Cmd Reg
#define TV_REG_LOCK_TIME                        23
#endif

// Common Register Setting
#define REALTEK_I_NOTCH_EN                                       0
#define REALTEK_I_NOTCH_FREQ                                     500000000
#define REALTEK_I_NOTCH_BW                                       1 //0~87
#define REALTEK_I_TS_DIS_MASK                                    0x00000001
#define REALTEK_I_TS_SERIAL_MASK                                 0x00000002
#define REALTEK_I_TS_CLK_PHASE_INV_MASK                          0x00000004
#define REALTEK_I_TS_PACKETS_188_MASK                            0x00000008
#define REALTEK_I_TS_CLOCK_GATE_MASK   0x00000020

// QAM Demod Module Pre-Definition
typedef struct QAM_DEMOD_MODULE_TAG QAM_DEMOD_MODULE;

typedef enum _REALTEK_I_QAM_QAM_MODE {
	QAM_QAM_16,				///<   16 QAM
	QAM_QAM_32,				///<   32 QAM
	QAM_QAM_64,				///<   64 QAM
	QAM_QAM_128,			///<   128 QAM
	QAM_QAM_256,			///<   256 QAM
	QAM_QAM_AUTO
}REALTEK_I_QAM_QAM_MODE;

typedef enum _REALTEK_I_DEMOD_QAM_QAM_MODE {
	DVBC_DEMOD_QAM_16 = 0,
	QAM_DEMOD_QAM_32,
	QAM_DEMOD_QAM_64,
	QAM_DEMOD_QAM_128,
	QAM_DEMOD_QAM_256,
	QAM_DEMOD_QAM_OTHER
}_REALTEK_I_DEMOD_QAM_QAM_MODE;

typedef enum _REALTEK_I_DEMOD_TYPE{
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
}REALTEK_I_DEMOD_TYPE;

typedef enum _REALTEK_I_DEMOD_CTRL{
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
}REALTEK_I_DEMOD_CTRL;

typedef int
(*QAM_DEMOD_FP_ADDR_8BIT_SET_REG_PAGE)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned long PageNo
);

typedef int
(*QAM_DEMOD_FP_ADDR_8BIT_SET_REG_BYTES)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	const unsigned char *pWritingBytes,
	unsigned long ByteNum
);

typedef int
(*QAM_DEMOD_FP_ADDR_16BIT_SET_REG_BYTES)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	const unsigned char *pWritingBytes,
	unsigned long ByteNum
);

typedef int
(*QAM_DEMOD_FP_ADDR_8BIT_GET_REG_BYTES)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char *pReadingBytes,
	unsigned long ByteNum
);

typedef int
(*QAM_DEMOD_FP_ADDR_16BIT_GET_REG_BYTES)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char *pReadingBytes,
	unsigned long ByteNum
);

typedef int
(*QAM_DEMOD_FP_ADDR_8BIT_SET_REG_MASK_BITS)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	const unsigned long WritingValue
);

typedef int
(*QAM_DEMOD_FP_ADDR_16BIT_SET_REG_MASK_BITS)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	const unsigned long WritingValue
);

typedef int
(*QAM_DEMOD_FP_ADDR_8BIT_GET_REG_MASK_BITS)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	unsigned long *pReadingValue
);

typedef int
(*QAM_DEMOD_FP_ADDR_16BIT_GET_REG_MASK_BITS)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	unsigned long *pReadingValue
);

typedef int
(*QAM_DEMOD_FP_ADDR_8BIT_SET_REG_BITS)(
	QAM_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

typedef int
(*QAM_DEMOD_FP_ADDR_16BIT_SET_REG_BITS)(
	QAM_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

typedef int
(*QAM_DEMOD_FP_ADDR_8BIT_GET_REG_BITS)(
	QAM_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

typedef int
(*QAM_DEMOD_FP_ADDR_16BIT_GET_REG_BITS)(
	QAM_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

typedef int
(*QAM_DEMOD_FP_ADDR_8BIT_SET_REG_BITS_WITH_PAGE)(
	QAM_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

typedef int
(*QAM_DEMOD_FP_ADDR_8BIT_GET_REG_BITS_WITH_PAGE)(
	QAM_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

// Demod Register Access for 8-bit Address
typedef struct {
	QAM_DEMOD_FP_ADDR_8BIT_SET_REG_PAGE             SetRegPage;
	QAM_DEMOD_FP_ADDR_8BIT_SET_REG_BYTES            SetRegBytes;
	QAM_DEMOD_FP_ADDR_8BIT_GET_REG_BYTES            GetRegBytes;
	QAM_DEMOD_FP_ADDR_8BIT_SET_REG_MASK_BITS        SetRegMaskBits;
	QAM_DEMOD_FP_ADDR_8BIT_GET_REG_MASK_BITS        GetRegMaskBits;
	QAM_DEMOD_FP_ADDR_8BIT_SET_REG_BITS             SetRegBits;
	QAM_DEMOD_FP_ADDR_8BIT_GET_REG_BITS             GetRegBits;
	QAM_DEMOD_FP_ADDR_8BIT_SET_REG_BITS_WITH_PAGE   SetRegBitsWithPage;
	QAM_DEMOD_FP_ADDR_8BIT_GET_REG_BITS_WITH_PAGE   GetRegBitsWithPage;
}
QAM_DEMOD_REG_ACCESS_ADDR_8BIT;

// Demod Register Access for 16-bit Address
typedef struct {
	QAM_DEMOD_FP_ADDR_16BIT_SET_REG_BYTES       SetRegBytes;
	QAM_DEMOD_FP_ADDR_16BIT_GET_REG_BYTES       GetRegBytes;
	QAM_DEMOD_FP_ADDR_16BIT_SET_REG_MASK_BITS   SetRegMaskBits;
	QAM_DEMOD_FP_ADDR_16BIT_GET_REG_MASK_BITS   GetRegMaskBits;
	QAM_DEMOD_FP_ADDR_16BIT_SET_REG_BITS        SetRegBits;
	QAM_DEMOD_FP_ADDR_16BIT_GET_REG_BITS        GetRegBits;
}
QAM_DEMOD_REG_ACCESS_ADDR_16BIT;

typedef void
(*QAM_DEMOD_FP_GET_DEMOD_TYPE)(
	QAM_DEMOD_MODULE *pDemod,
	int *pDemodType
);

typedef void
(*QAM_DEMOD_FP_GET_DEVICE_ADDR)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned char *pDeviceAddr
);

typedef void
(*QAM_DEMOD_FP_GET_CRYSTAL_FREQ_HZ)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned long *pCrystalFreqHz
);

// Demod Common Function Pointer
typedef int
(*QAM_DEMOD_FP_CHECK_RPU_READY)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *IsRpuReady
);

typedef int
(*QAM_DEMOD_FP_PING_RPU)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *IsLive
);

typedef int
(*QAM_DEMOD_FP_SHUT_DOWN)(
	QAM_DEMOD_MODULE *pDemod
);

typedef int
(*QAM_DEMOD_FP_ACTIVATE_CORE)(
	QAM_DEMOD_MODULE *pDemod
);

typedef int
(*QAM_DEMOD_FP_DEACTIVATE_CORE)(
	QAM_DEMOD_MODULE *pDemod
);

typedef int
(*QAM_DEMOD_FP_SWITCH_TO_BUFFER)(
	QAM_DEMOD_MODULE *pDemod
);

typedef int
(*QAM_DEMOD_FP_GET_DEMOD_INFO)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *DemodType
);

typedef int
(*QAM_DEMOD_FP_GET_BUILD_ID)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *BuildId
);

typedef int
(*QAM_DEMOD_FP_DEMOD_CTRL_STOP)(
	QAM_DEMOD_MODULE *pDemod
);

typedef int
(*QAM_DEMOD_FP_DEMOD_CTRL_DETECT)(
	QAM_DEMOD_MODULE *pDemod
);

typedef int
(*QAM_DEMOD_FP_DEMOD_CTRL_RUN)(
	QAM_DEMOD_MODULE *pDemod
);

typedef int
(*QAM_DEMOD_FP_DEMOD_CTRL_UPDATE_RSSI)(
	QAM_DEMOD_MODULE *pDemod
);

typedef int
(*QAM_DEMOD_FP_DEMOD_CTRL_RESET_COUNTERS)(
	QAM_DEMOD_MODULE *pDemod
);

typedef int
(*QAM_DEMOD_FP_DEMOD_CTRL_UPDATE_COUNTERS)(
	QAM_DEMOD_MODULE *pDemod
);

typedef int
(*QAM_DEMOD_FP_DEMOD_CTRL_SET_AGC)(
	QAM_DEMOD_MODULE *pDemod
);

typedef int
(*QAM_DEMOD_FP_DEMOD_CTRL_UPDATE_AGC)(
	QAM_DEMOD_MODULE *pDemod
);

typedef int
(*QAM_DEMOD_FP_DEMOD_CTRL_QUERY_STATUS)(
	QAM_DEMOD_MODULE *pDemod
);

typedef int
(*QAM_DEMOD_FP_GET_DEMOD_STATUS)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *DemodStatus
);

typedef int
(*QAM_DEMOD_FP_SET_TUNER_FREQ)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int TunerFreqHz
);

typedef int
(*QAM_DEMOD_FP_SET_TUNER_BANDWIDTH)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int TunerBandwidthHz
);

typedef int
(*QAM_DEMOD_FP_SET_TUNER_GRID_BASE)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int TunerGridBaseHz
);

typedef int
(*QAM_DEMOD_FP_SET_TUNER_GRID_INCR)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int TunerGridIncrHz
);

typedef int
(*QAM_DEMOD_FP_SET_NOTCH_FREQ)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int NotchFreqHz
);

typedef int
(*QAM_DEMOD_FP_SET_NOTCH_BANDWIDTH)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int NotchBandwidth
);

typedef int
(*QAM_DEMOD_FP_GET_ACT_TUNER_FREQ)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *ActiveFreqHz
);

typedef int
(*QAM_DEMOD_FP_GET_ACT_TUNER_BANDWIDTH)(
	QAM_DEMOD_MODULE *pDemod,
    unsigned int *ActiveBandwidth
);

typedef int
(*QAM_DEMOD_FP_GET_ACT_TUNER_GAIN)(
	QAM_DEMOD_MODULE *pDemod,
    unsigned int *ActiveTunerGain
);

typedef int
(*QAM_DEMOD_FP_GET_ACT_TUNER_RSSI)(
	QAM_DEMOD_MODULE *pDemod,
    unsigned int *ActiveTunerRssi
);

typedef int
(*QAM_DEMOD_FP_SET_AGC_PARAMS)(
	QAM_DEMOD_MODULE *pDemod,
    unsigned int AgcParam,
    unsigned int Index
);

typedef int
(*QAM_DEMOD_FP_GET_AGC_PARAMS)(
	QAM_DEMOD_MODULE *pDemod,
    unsigned int *AgcParam,
    unsigned int Index
);

typedef int
(*QAM_DEMOD_FP_SET_TS_CONFIG)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int IsTsDis,
	unsigned int IsSerial,
	unsigned int IsInv,
	unsigned int IsPacket188
);

typedef int
(*QAM_DEMOD_FP_SET_TS_CLK_RATE_MARGIN)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int TsClkMargin
);

typedef int
(*QAM_DEMOD_FP_SET_TS_CLK_RATE_MAX)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int TsClkRateMax
);

typedef int
(*QAM_DEMOD_FP_GET_DEMOD_LOCK_TIME)(
	QAM_DEMOD_MODULE *pDemod,
    unsigned int *DemodLockTimeMs
);

//Add for Common Virtual Register V7.4
typedef int
(*QAM_DEMOD_FP_SET_XML_TUNER_CFG_OVERRIDE)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int TunerCfg
);

typedef int
(*QAM_DEMOD_FP_SET_XML_TUNER_GAIN_CTRL)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int TunerGainCtrl
);

typedef int
(*QAM_DEMOD_FP_SET_XML_FLAGS)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int Flags
);

typedef int
(*QAM_DEMOD_FP_SET_XML_IF_FREQ)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int IfFreq
);

typedef int
(*QAM_DEMOD_FP_SET_XML_PLFT_CFG_OVERRIDE)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int PlatformCfg
);

typedef int
(*QAM_DEMOD_FP_SET_XML_IF_CLK)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int IfClk
);

typedef int
(*QAM_DEMOD_FP_SET_XML_LDPC_CLK)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int LdpcClk
);

typedef int
(*QAM_DEMOD_FP_SET_XML_UCC_CLK)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int UccClk
);

typedef int
(*QAM_DEMOD_FP_SET_XML_MCU_CLK)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int McuClk
);

typedef int
(*QAM_DEMOD_FP_SET_VIRTUAL_REGISTER)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int RegAddr,
	unsigned int RegVal
);

typedef int
(*QAM_DEMOD_FP_GET_VIRTUAL_REGISTER)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int RegAddr,
	unsigned int *RegVal
);

// QAM Specific Function Pointer
typedef int
(*QAM_DEMOD_FP_GET_SYSTEM_STATE_MACHINE)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *SystemStateMachine
);

typedef int
(*QAM_DEMOD_FP_GET_COARSE_CARRIER_SYNC_SUB_STATE)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *CoarseCarrierSyncSubState
);

typedef int
(*QAM_DEMOD_FP_GET_EQ_ADAPT_SUB_STATE)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *EqAdaptSubState
);

typedef int
(*QAM_DEMOD_FP_GET_IS_NO_SIGNAL)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *IsNoSignal
);

typedef int
(*QAM_DEMOD_FP_GET_SYMBOL_RATE_MONITOR)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *SymbolRateMonitor
);

typedef int
(*QAM_DEMOD_FP_GET_CARRIER_FREQUENCY_MONITOR)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *CarrierFrequencyMonitor
);

typedef int
(*QAM_DEMOD_FP_GET_GET_QAM_SIZE_MONITOR)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *QamSizeMonitor
);

typedef int
(*QAM_DEMOD_FP_GET_SPECTRUM_INVERSION_MONITOR)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *SpectrumInversionMonitor
);

typedef int
(*QAM_DEMOD_FP_GET_INTERLEAVER_MODE)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *InterleaverMode
);

typedef int
(*QAM_DEMOD_FP_GET_ACQUISITION_TIME)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *AcquisitionTime
);

typedef int
(*QAM_DEMOD_FP_SET_ACQUISITION_TIME_RESET)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int AcquisitionTimeReset
);

typedef int
(*QAM_DEMOD_FP_GET_ACQUISITION_TIME_RESET)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *AcquisitionTimeReset
);

typedef int
(*QAM_DEMOD_FP_GET_EQ_OUTPUT_SNR)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *EqOutputSnr
);

typedef int
(*QAM_DEMOD_FP_GET_MPEG_TS_PACKET_NUMBER)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *MpegTsPacketNumber
);

typedef int
(*QAM_DEMOD_FP_GET_BAD_PACKET_NUMBER)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *BadPacketNumber
);

typedef int
(*QAM_DEMOD_FP_GET_BYTE_ERROR_NUMBER)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *ByteErrorNumber
);

typedef int
(*QAM_DEMOD_FP_GET_BIT_ERROR_NUMBER)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *BitErrorNumber
);

typedef int
(*QAM_DEMOD_FP_SET_BER_AVE_LENGTH)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int BerAveLength
);

typedef int
(*QAM_DEMOD_FP_GET_BER_AVE_LENGTH)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *BerAveLength
);

typedef int
(*QAM_DEMOD_FP_GET_RS_AVE_BER)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *RsAveBer
);

typedef int
(*QAM_DEMOD_FP_GET_RS_AVE_PER)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *RsAvePer
);

typedef int
(*QAM_DEMOD_FP_GET_EQ_AVE_SNR)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *EqAveSnr
);

typedef int
(*QAM_DEMOD_FP_SET_FAILURE_COUNTER_RESET)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int FailureCounterReset
);

typedef int
(*QAM_DEMOD_FP_GET_FAILURE_COUNTER_RESET)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *FailureCounterReset
);

typedef int
(*QAM_DEMOD_FP_GET_COARSE_SYMBOL_TIMING_FAILURE_NUMBER)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *CoarseSymbolTimingFailureNumber
);

typedef int
(*QAM_DEMOD_FP_GET_FINE_SYMBOL_TIMING_FAILURE_NUMBER)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *FineSymbolTimingFailureNumber
);

typedef int
(*QAM_DEMOD_FP_GET_CARRIER_SYNC_FAILURE_NUMBER)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *CarrierSyncFailureNumber
);

typedef int
(*QAM_DEMOD_FP_GET_UN_SUPPORTED_CDI_MODE_FAILURE_NUMBER)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *UnSupportedCdiModeFailureNumber
);

typedef int
(*QAM_DEMOD_FP_GET_SPECTRUM_INVERSION_SEARCH_FAILURE_NUMBER)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *SpectrumInversionSearchFailureNumber
);

typedef int
(*QAM_DEMOD_FP_GET_UN_SUPPORTED_TS_RATE_FAILURE_NUMBER)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *UnSupportedTsRateFailureNumber
);

typedef int
(*QAM_DEMOD_FP_GET_PER_FAILURE_NUMBER)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *PerFailureNumber
);

typedef int
(*QAM_DEMOD_FP_GET_SIGNAL_DROPOUT_FAILURE_NUMBER)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *SignalDropoutFailureNumber
);

typedef int
(*QAM_DEMOD_FP_GET_LAST_FAILURE_CASE)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *LastFailureCase
);

typedef int
(*QAM_DEMOD_FP_SET_CORE_CLOCK_RATE)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int CoreClockRate
);

typedef int
(*QAM_DEMOD_FP_GET_CORE_CLOCK_RATE)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *CoreClockRate
);

typedef int
(*QAM_DEMOD_FP_SET_QAM_SEARCH_ENABLE)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int QamSearchEnable
);

typedef int
(*QAM_DEMOD_FP_GET_QAM_SEARCH_ENABLE)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *QamSearchEnable
);

typedef int
(*QAM_DEMOD_FP_SET_FIXED_QAM_SIZE)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int FixedQamSize
);

typedef int
(*QAM_DEMOD_FP_GET_FIXED_QAM_SIZE)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *FixedQamSize
);

typedef int
(*QAM_DEMOD_FP_SET_SPECTRUM_INVERSION_SEARCH_ENABLE)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int SpectrumInversionSearchEnable
);

typedef int
(*QAM_DEMOD_FP_GET_SPECTRUM_INVERSION_SEARCH_ENABLE)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *SpectrumInversionSearchEnable
);

typedef int
(*QAM_DEMOD_FP_SET_SPECTRUM_INVERSION_ENABLE)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int SpectrumInversionEnable
);

typedef int
(*QAM_DEMOD_FP_GET_SPECTRUM_INVERSION_ENABLE)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *SpectrumInversionEnable
);

typedef int
(*QAM_DEMOD_FP_SET_BYTE_ERROR_IN_BAD_PACKET_NUMBER)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int ByteErrorInBadPacketNumber
);

typedef int
(*QAM_DEMOD_FP_GET_BYTE_ERROR_IN_BAD_PACKET_NUMBER)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *ByteErrorInBadPacketNumber
);

typedef int
(*QAM_DEMOD_FP_SET_BIT_ERROR_IN_BAD_PACKET_NUMBER)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int BitErrorInBadPacketNumber
);

typedef int
(*QAM_DEMOD_FP_GET_BIT_ERROR_IN_BAD_PACKET_NUMBER)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *BitErrorInBadPacketNumber
);

typedef int
(*QAM_DEMOD_FP_SET_BAD_PACKET_IN_BAD_SET_PERCENTAGE)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int BadPacketInBadSetPercentage
);

typedef int
(*QAM_DEMOD_FP_GET_BAD_PACKET_IN_BAD_SET_PERCENTAGE)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *BadPacketInBadSetPercentage
);

typedef int
(*QAM_DEMOD_FP_SET_FAILURE_SET_ERROR_RATE)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int FailureSetErrorRate
);

typedef int
(*QAM_DEMOD_FP_GET_FAILURE_SET_ERROR_RATE)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *FailureSetErrorRate
);

typedef int
(*QAM_DEMOD_FP_SET_INTERLEAVER_LEVEL)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int InterleaverLevel
);

typedef int
(*QAM_DEMOD_FP_GET_INTERLEAVER_LEVEL)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *InterleaverLevel
);

typedef int
(*QAM_DEMOD_FP_SET_PHASE_TRACKER_LOOP_GAIN_64QAM)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int PhaseTrackerLoopGain64Qam
);

typedef int
(*QAM_DEMOD_FP_GET_PHASE_TRACKER_LOOP_GAIN_64QAM)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *PhaseTrackerLoopGain64Qam
);

typedef int
(*QAM_DEMOD_FP_SET_PHASE_TRACKER_LOOP_GAIN_256QAM)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int PhaseTrackerLoopGain256Qam
);

typedef int
(*QAM_DEMOD_FP_GET_PHASE_TRACKER_LOOP_GAIN_256QAM)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *PhaseTrackerLoopGain256Qam
);

typedef int
(*QAM_DEMOD_FP_SET_DAGC_TARGET_POWER)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int DagcTargetPower
);

typedef int
(*QAM_DEMOD_FP_GET_DAGC_TARGET_POWER)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *DagcTargetPower
);

typedef int
(*QAM_DEMOD_FP_SET_EQ_UPDATE_RATE)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int EqUpdateRate
);

typedef int
(*QAM_DEMOD_FP_GET_EQ_UPDATE_RATE)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *EqUpdateRate
);

typedef int
(*QAM_DEMOD_FP_SET_CST_PEAK_TO_MEAN_THRESHOLD)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int CstPeakToMeanThreshold
);

typedef int
(*QAM_DEMOD_FP_GET_CST_PEAK_TO_MEAN_THRESHOLD)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *CstPeakToMeanThreshold
);

typedef int
(*QAM_DEMOD_FP_GET_IF_AGC_GAIN)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *IfAgcGain
);

typedef int
(*QAM_DEMOD_FP_GET_SIGNAL_SSI)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *SignalSSI
);

typedef int
(*QAM_DEMOD_FP_GET_SIGNAL_QUALITY_INDICATOR)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned char *SignalQualityIndicator
);

typedef int
(*QAM_DEMOD_FP_UPDATE_FUNCTION)(
	QAM_DEMOD_MODULE *pDemod
);

#if 0
typedef int
(*QAM_DEMOD_FP_GET_SIGNAL_SSI)(
	QAM_DEMOD_MODULE *pDemod,
	int rf_level,
	unsigned char *ssi
);

typedef int
(*QAM_DEMOD_FP_GET_SIGNAL_SQI)(
	QAM_DEMOD_MODULE *pDemod,
	unsigned char *sqi
);

typedef int
(*QAM_DEMOD_FP_UPDATE_FUNCTION)(
	QAM_DEMOD_MODULE *pDemod
);
#endif

/// REALTEK_I QAM extra module alias
typedef struct REALTEK_I_QAM_EXTRA_MODULE REALTEK_I_QAM_EXTRA_MODULE;

// REALTEK_I QAM extra module
struct REALTEK_I_QAM_EXTRA_MODULE {
	// Variables
	int ConfigMode;
	int ReAcquireCount;
};

// QAM Demod Default I2C Functions for 8-bit Address
int
qam_demod_addr_8bit_default_SetRegPage(
	QAM_DEMOD_MODULE *pDemod,
	unsigned long PageNo
);

int
qam_demod_addr_8bit_default_SetRegBytes(
	QAM_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	const unsigned char *pWritingBytes,
	unsigned long ByteNum
);

int
qam_demod_addr_8bit_default_GetRegBytes(
	QAM_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char *pReadingBytes,
	unsigned long ByteNum
);

int
qam_demod_addr_8bit_default_SetRegMaskBits(
	QAM_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	const unsigned long WritingValue
);

int
qam_demod_addr_8bit_default_GetRegMaskBits(
	QAM_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	unsigned long *pReadingValue
);

int
qam_demod_addr_8bit_default_SetRegBits(
	QAM_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

int
qam_demod_addr_8bit_default_GetRegBits(
	QAM_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

int
qam_demod_addr_8bit_default_SetRegBitsWithPage(
	QAM_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

int
qam_demod_addr_8bit_default_GetRegBitsWithPage(
	QAM_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

// QAM Demod Default I2C Functions for 16-bit Address
int
qam_demod_addr_16bit_default_SetRegBytes(
	QAM_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	const unsigned char *pWritingBytes,
	unsigned long ByteNum
);

int
qam_demod_addr_16bit_default_GetRegBytes(
	QAM_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char *pReadingBytes,
	unsigned long ByteNum
);

int
qam_demod_addr_16bit_default_SetRegMaskBits(
	QAM_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	const unsigned long WritingValue
);

int
qam_demod_addr_16bit_default_GetRegMaskBits(
	QAM_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	unsigned long *pReadingValue
);

int
qam_demod_addr_16bit_default_SetRegBits(
	QAM_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

int
qam_demod_addr_16bit_default_GetRegBits(
	QAM_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

// QAM Demod Default Manipulating Functions
void
qam_demod_default_GetDemodType(
	QAM_DEMOD_MODULE *pDemod,
	int *pDemodType
);

void
qam_demod_default_GetDeviceAddr(
	QAM_DEMOD_MODULE *pDemod,
	unsigned char *pDeviceAddr
);

void
qam_demod_default_GetCrystalFreqHz(
	QAM_DEMOD_MODULE *pDemod,
	unsigned long *pCrystalFreqHz
);

// Demod Common Function
int
realtek_i_qam_common_CheckRpuReady(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *IsRpuReady
);

int
realtek_i_qam_common_PingRpu(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *IsLive
);

int
realtek_i_qam_common_ShutDown(
	QAM_DEMOD_MODULE *pDemod
);

int
realtek_i_qam_common_ActivateCore(
	QAM_DEMOD_MODULE *pDemod
);

int
realtek_i_qam_common_DeactivateCore(
	QAM_DEMOD_MODULE *pDemod
);

int
realtek_i_qam_common_SwitchToBuffer(
	QAM_DEMOD_MODULE *pDemod
);

int
realtek_i_qam_common_GetDemodInfo(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *DemodType
);

int
realtek_i_qam_common_GetBuildId(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *BuildId
);

int
realtek_i_qam_common_DemodCtrlStopCmd(
	QAM_DEMOD_MODULE *pDemod
);

int
realtek_i_qam_common_DemodCtrlDetectCmd(
	QAM_DEMOD_MODULE *pDemod
);

int
realtek_i_qam_common_DemodCtrlRunCmd(
	QAM_DEMOD_MODULE *pDemod
);

int
realtek_i_qam_common_DemodCtrlUpdateRssiCmd(
	QAM_DEMOD_MODULE *pDemod
);

int
realtek_i_qam_common_DemodCtrlResetCountersCmd(
	QAM_DEMOD_MODULE *pDemod
);

int
realtek_i_qam_common_DemodCtrlUpdateCountersCmd(
	QAM_DEMOD_MODULE *pDemod
);

int
realtek_i_qam_common_DemodCtrlSetAgcCmd(
	QAM_DEMOD_MODULE *pDemod
);

int
realtek_i_qam_common_DemodCtrlUpdateAgcCmd(
	QAM_DEMOD_MODULE *pDemod
);

int
realtek_i_qam_common_DemodCtrlQueryStatusCmd(
	QAM_DEMOD_MODULE *pDemod
);

int
realtek_i_qam_common_GetDemodStatus(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *DemodStatus
);

int
realtek_i_qam_common_SetTunerFreqCmd(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int TunerFreqHz
);

int
realtek_i_qam_common_SetTunerBandwidth(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int TunerBandwidthHz
);

int
realtek_i_qam_common_SetTunerGridBase(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int TunerGridBaseHz
);

int
realtek_i_qam_common_SetTunerGridIncr(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int TunerGridIncrHz
);

int
realtek_i_qam_common_SetNotchFreqCmd(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int NotchFreqHz
);

int
realtek_i_qam_common_SetNotchBandwidth(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int NotchBandwidth
);

int
realtek_i_qam_common_GetActiveTunerFreq(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int *ActiveFreqHz
);

int
realtek_i_qam_common_GetActiveTunerBandwidth(
	QAM_DEMOD_MODULE *pDemod,
    unsigned int *ActiveBandwidth
);

int
realtek_i_qam_common_GetActiveTunerGain(
	QAM_DEMOD_MODULE *pDemod,
    unsigned int *ActiveTunerGain
);

int
realtek_i_qam_common_GetActiveTunerRssi(
	QAM_DEMOD_MODULE *pDemod,
    unsigned int *ActiveTunerRssi
);

int
realtek_i_qam_common_SetAgcParams(
	QAM_DEMOD_MODULE *pDemod,
    unsigned int AgcParam,
    unsigned int Index
);

int
realtek_i_qam_common_GetAgcParams(
	QAM_DEMOD_MODULE *pDemod,
    unsigned int *AgcParam,
    unsigned int Index
);

int
realtek_i_qam_common_SetTsConfig(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int IsTsDis,
	unsigned int IsSerial,
	unsigned int IsInv,
	unsigned int IsPacket188
);

int
realtek_i_qam_common_SetTsClkRateMargin(
	QAM_DEMOD_MODULE *pDemod,
    unsigned int TsClkMargin
);

int
realtek_i_qam_common_SetTsClkRateMax(
	QAM_DEMOD_MODULE *pDemod,
    unsigned int TsClkRateMax
);

int
realtek_i_qam_common_GetDemodLockTime(
	QAM_DEMOD_MODULE *pDemod,
    unsigned int *DemodLockTimeMs
);

//Add for Common Virtual Register V7.4
int
realtek_i_qam_common_SetXmlTunerCfgOverride(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int TunerCfg
);

int
realtek_i_qam_common_SetXmlTunerGainCtrl(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int TunerGainCtrl
);

int
realtek_i_qam_common_SetXmlFlags(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int Flags
);

int
realtek_i_qam_common_SetXmlIfFreq(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int IfFreq
);

int
realtek_i_qam_common_SetXmlPlatformCfgOverride(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int PlatformCfg
);

int
realtek_i_qam_common_SetXmlIfClk(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int IfClk
);

int
realtek_i_qam_common_SetXmlLdpcClk(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int LdpcClk
);

int
realtek_i_qam_common_SetXmlUccClk(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int UccClk
);

int
realtek_i_qam_common_SetXmlMcuClk(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int McuClk
);

int
realtek_i_qam_common_SetVirtualRegister(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int RegAddr,
	unsigned int RegVal
);

int
realtek_i_qam_common_GetVirtualRegister(
	QAM_DEMOD_MODULE *pDemod,
	unsigned int RegAddr,
	unsigned int *RegVal
);

// QAM Demod Module Structure
struct QAM_DEMOD_MODULE_TAG {
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
	
	union {										
		REALTEK_I_QAM_EXTRA_MODULE  RealtekIQam;
	}
	Extra;
	
	BASE_INTERFACE_MODULE *pBaseInterface;
	I2C_BRIDGE_MODULE *pI2cBridge;

	// Demod I2C Function Pointers
	union {
		QAM_DEMOD_REG_ACCESS_ADDR_8BIT  Addr8Bit;
		QAM_DEMOD_REG_ACCESS_ADDR_16BIT Addr16Bit;
	}
	RegAccess;

	// Demod Manipulating Function Pointers
	QAM_DEMOD_FP_GET_DEMOD_TYPE                GetDemodType;
	QAM_DEMOD_FP_GET_DEVICE_ADDR               GetDeviceAddr;
	QAM_DEMOD_FP_GET_CRYSTAL_FREQ_HZ           GetCrystalFreqHz;

    // Common TV Api
    QAM_DEMOD_FP_CHECK_RPU_READY               CheckRpuReady;
    QAM_DEMOD_FP_PING_RPU                      PingRpu;
    QAM_DEMOD_FP_SHUT_DOWN                     ShutDown;
    QAM_DEMOD_FP_ACTIVATE_CORE                 ActivateCore;
    QAM_DEMOD_FP_DEACTIVATE_CORE               DeactivateCore;
    QAM_DEMOD_FP_SWITCH_TO_BUFFER		SwitchToBuffer;
    
    QAM_DEMOD_FP_GET_DEMOD_INFO                GetDemodInfo;
    QAM_DEMOD_FP_GET_BUILD_ID                  GetBuildId;
    QAM_DEMOD_FP_DEMOD_CTRL_STOP               DemodCtrlStop;
    QAM_DEMOD_FP_DEMOD_CTRL_DETECT             DemodCtrlDetect;
    QAM_DEMOD_FP_DEMOD_CTRL_RUN                DemodCtrlRun;
    QAM_DEMOD_FP_DEMOD_CTRL_UPDATE_RSSI        DemodCtrlUpdateRssi;
    QAM_DEMOD_FP_DEMOD_CTRL_RESET_COUNTERS     DemodCtrlResetCounters;
    QAM_DEMOD_FP_DEMOD_CTRL_UPDATE_COUNTERS    DemodCtrlUpdateCounters;
    QAM_DEMOD_FP_DEMOD_CTRL_SET_AGC            DemodCtrlSetAgc;
    QAM_DEMOD_FP_DEMOD_CTRL_UPDATE_AGC         DemodCtrlUpdateAgc;
    QAM_DEMOD_FP_DEMOD_CTRL_QUERY_STATUS       DemodCtrlQueryStatus;
    QAM_DEMOD_FP_GET_DEMOD_STATUS              GetDemodStatus;

    QAM_DEMOD_FP_SET_TUNER_FREQ                SetTunerFreq;
    QAM_DEMOD_FP_SET_TUNER_BANDWIDTH           SetTunerBandwidth;
    QAM_DEMOD_FP_SET_TUNER_GRID_BASE           SetTunerGridBase;
    QAM_DEMOD_FP_SET_TUNER_GRID_INCR           SetTunerGridIncr;
    QAM_DEMOD_FP_SET_NOTCH_FREQ                SetNotchFreq;
    QAM_DEMOD_FP_SET_NOTCH_BANDWIDTH           SetNotchBandwidth;
    QAM_DEMOD_FP_GET_ACT_TUNER_FREQ            GetActiveTunerFreq;
    QAM_DEMOD_FP_GET_ACT_TUNER_BANDWIDTH       GetActiveTunerBandwidth;
    QAM_DEMOD_FP_GET_ACT_TUNER_GAIN            GetActiveTunerGain;
    QAM_DEMOD_FP_GET_ACT_TUNER_RSSI            GetActiveTunerRssi;
    QAM_DEMOD_FP_SET_AGC_PARAMS                SetAgcParams;
    QAM_DEMOD_FP_GET_AGC_PARAMS                GetAgcParams;
    QAM_DEMOD_FP_SET_TS_CONFIG                 SetTsConfig;
    QAM_DEMOD_FP_SET_TS_CLK_RATE_MARGIN        SetTsClkRateMargin;
    QAM_DEMOD_FP_SET_TS_CLK_RATE_MAX           SetTsClkRateMax;
    QAM_DEMOD_FP_GET_DEMOD_LOCK_TIME           GetDemodLockTime;

	//Add for Common Virtual Register V7.4
    QAM_DEMOD_FP_SET_XML_TUNER_CFG_OVERRIDE    SetXmlTunerCfgOverride;
    QAM_DEMOD_FP_SET_XML_TUNER_GAIN_CTRL       SetXmlTunerGainCtrl;
    QAM_DEMOD_FP_SET_XML_FLAGS                 SetXmlFlags;
    QAM_DEMOD_FP_SET_XML_IF_FREQ               SetXmlIfFreq;
    QAM_DEMOD_FP_SET_XML_PLFT_CFG_OVERRIDE     SetXmlPlftCfgOverride;
    QAM_DEMOD_FP_SET_XML_IF_CLK                SetXmlIfClk;
    QAM_DEMOD_FP_SET_XML_LDPC_CLK              SetXmlLdpcClk;
    QAM_DEMOD_FP_SET_XML_UCC_CLK               SetXmlUccClk;
    QAM_DEMOD_FP_SET_XML_MCU_CLK               SetXmlMcuClk;
    QAM_DEMOD_FP_SET_VIRTUAL_REGISTER          SetVirtualRegister;
    QAM_DEMOD_FP_GET_VIRTUAL_REGISTER          GetVirtualRegister;

    // QAM Specific Api
    QAM_DEMOD_FP_GET_SYSTEM_STATE_MACHINE						GetSystemStateMachine;
    QAM_DEMOD_FP_GET_COARSE_CARRIER_SYNC_SUB_STATE     			GetCoarseCarrierSyncSubState;
    QAM_DEMOD_FP_GET_EQ_ADAPT_SUB_STATE         				GetEqAdaptSubState;
    QAM_DEMOD_FP_GET_IS_NO_SIGNAL                 				GetIsNoSignal;
    QAM_DEMOD_FP_GET_SYMBOL_RATE_MONITOR                  		GetSymbolRateMonitor;
    QAM_DEMOD_FP_GET_CARRIER_FREQUENCY_MONITOR                  GetCarrierFrequencyMonitor;
    QAM_DEMOD_FP_GET_GET_QAM_SIZE_MONITOR             			GetQamSizeMonitor;
    QAM_DEMOD_FP_GET_SPECTRUM_INVERSION_MONITOR             	GetSpectrumInversionMonitor;
    QAM_DEMOD_FP_GET_INTERLEAVER_MODE                   		GetInterleaverMode;
    QAM_DEMOD_FP_GET_ACQUISITION_TIME                   		GetAcquisitionTime;
    QAM_DEMOD_FP_SET_ACQUISITION_TIME_RESET                   	SetAcquisitionTimeReset;
    QAM_DEMOD_FP_GET_ACQUISITION_TIME_RESET                   	GetAcquisitionTimeReset;
    QAM_DEMOD_FP_GET_EQ_OUTPUT_SNR                   			GetEqOutputSnr;
    QAM_DEMOD_FP_GET_MPEG_TS_PACKET_NUMBER                   	GetMpegTsPacketNumber;
    QAM_DEMOD_FP_GET_BAD_PACKET_NUMBER                   		GetBadPacketNumber;
    QAM_DEMOD_FP_GET_BYTE_ERROR_NUMBER                   		GetByteErrorNumber;
    QAM_DEMOD_FP_GET_BIT_ERROR_NUMBER           				GetBitErrorNumber;
    QAM_DEMOD_FP_SET_BER_AVE_LENGTH                       		SetBerAveLength;
    QAM_DEMOD_FP_GET_BER_AVE_LENGTH                     		GetBerAveLength;
    QAM_DEMOD_FP_GET_RS_AVE_BER              					GetRsAveBer;
    QAM_DEMOD_FP_GET_RS_AVE_PER       							GetRsAvePer;
    QAM_DEMOD_FP_GET_EQ_AVE_SNR         						GetEqAveSnr;
    QAM_DEMOD_FP_SET_FAILURE_COUNTER_RESET          			SetFailureCounterReset;
    QAM_DEMOD_FP_GET_FAILURE_COUNTER_RESET     					GetFailureCounterReset;
    QAM_DEMOD_FP_GET_COARSE_SYMBOL_TIMING_FAILURE_NUMBER       	GetCoarseSymbolTimingFailureNumber;
    QAM_DEMOD_FP_GET_FINE_SYMBOL_TIMING_FAILURE_NUMBER          GetFineSymbolTimingFailureNumber;
    QAM_DEMOD_FP_GET_CARRIER_SYNC_FAILURE_NUMBER               	GetCarrierSyncFailureNumber;
    QAM_DEMOD_FP_GET_UN_SUPPORTED_CDI_MODE_FAILURE_NUMBER      	GetUnSupportedCdiModeFailureNumber;
    QAM_DEMOD_FP_GET_SPECTRUM_INVERSION_SEARCH_FAILURE_NUMBER	GetSpectrumInversionSearchFailureNumber;
    QAM_DEMOD_FP_GET_UN_SUPPORTED_TS_RATE_FAILURE_NUMBER        GetUnSupportedTsRateFailureNumber;
    QAM_DEMOD_FP_GET_PER_FAILURE_NUMBER                 		GetPerFailureNumber;
    QAM_DEMOD_FP_GET_SIGNAL_DROPOUT_FAILURE_NUMBER              GetSignalDropoutFailureNumber;
    QAM_DEMOD_FP_GET_LAST_FAILURE_CASE               			GetLastFailureCase;
    QAM_DEMOD_FP_SET_CORE_CLOCK_RATE                   			SetCoreClockRate;
    QAM_DEMOD_FP_GET_CORE_CLOCK_RATE                     		GetCoreClockRate;
    QAM_DEMOD_FP_SET_QAM_SEARCH_ENABLE                     		SetQamSearchEnable;
    QAM_DEMOD_FP_GET_QAM_SEARCH_ENABLE               			GetQamSearchEnable;
    QAM_DEMOD_FP_SET_FIXED_QAM_SIZE               				SetFixedQamSize;
    QAM_DEMOD_FP_GET_FIXED_QAM_SIZE      						GetFixedQamSize;
    QAM_DEMOD_FP_SET_SPECTRUM_INVERSION_SEARCH_ENABLE           SetSpectrumInversionSearchEnable;
	QAM_DEMOD_FP_GET_SPECTRUM_INVERSION_SEARCH_ENABLE           GetSpectrumInversionSearchEnable;
    QAM_DEMOD_FP_SET_SPECTRUM_INVERSION_ENABLE                  SetSpectrumInversionEnable;
    QAM_DEMOD_FP_GET_SPECTRUM_INVERSION_ENABLE                  GetSpectrumInversionEnable;
    QAM_DEMOD_FP_SET_BYTE_ERROR_IN_BAD_PACKET_NUMBER            SetByteErrorInBadPacketNumber;
    QAM_DEMOD_FP_GET_BYTE_ERROR_IN_BAD_PACKET_NUMBER            GetByteErrorInBadPacketNumber;
    QAM_DEMOD_FP_SET_BIT_ERROR_IN_BAD_PACKET_NUMBER      		SetBitErrorInBadPacketNumber;
    QAM_DEMOD_FP_GET_BIT_ERROR_IN_BAD_PACKET_NUMBER             GetBitErrorInBadPacketNumber;
	QAM_DEMOD_FP_SET_BAD_PACKET_IN_BAD_SET_PERCENTAGE           SetBadPacketInBadSetPercentage;
    QAM_DEMOD_FP_GET_BAD_PACKET_IN_BAD_SET_PERCENTAGE           GetBadPacketInBadSetPercentage;
    QAM_DEMOD_FP_SET_FAILURE_SET_ERROR_RATE                     SetFailureSetErrorRate;
    QAM_DEMOD_FP_GET_FAILURE_SET_ERROR_RATE               		GetFailureSetErrorRate;
	QAM_DEMOD_FP_SET_INTERLEAVER_LEVEL      					SetInterleaverLevel;
    QAM_DEMOD_FP_GET_INTERLEAVER_LEVEL      					GetInterleaverLevel;
    QAM_DEMOD_FP_SET_PHASE_TRACKER_LOOP_GAIN_64QAM              SetPhaseTrackerLoopGain64Qam;
	QAM_DEMOD_FP_GET_PHASE_TRACKER_LOOP_GAIN_64QAM              GetPhaseTrackerLoopGain64Qam;
    QAM_DEMOD_FP_SET_PHASE_TRACKER_LOOP_GAIN_256QAM             SetPhaseTrackerLoopGain256Qam;
    QAM_DEMOD_FP_GET_PHASE_TRACKER_LOOP_GAIN_256QAM             GetPhaseTrackerLoopGain256Qam;
    QAM_DEMOD_FP_SET_DAGC_TARGET_POWER               			SetDagcTargetPower;
    QAM_DEMOD_FP_GET_DAGC_TARGET_POWER               			GetDagcTargetPower;
    QAM_DEMOD_FP_SET_EQ_UPDATE_RATE      						SetEqUpdateRate;
    QAM_DEMOD_FP_GET_EQ_UPDATE_RATE                  			GetEqUpdateRate;
	QAM_DEMOD_FP_SET_CST_PEAK_TO_MEAN_THRESHOLD        			SetCstPeakToMeanThreshold;
	QAM_DEMOD_FP_GET_CST_PEAK_TO_MEAN_THRESHOLD                 GetCstPeakToMeanThreshold;
	QAM_DEMOD_FP_GET_IF_AGC_GAIN	 							GetIfAgcGain;
	QAM_DEMOD_FP_GET_SIGNAL_SSI                   				GetSignalSSI;
    QAM_DEMOD_FP_GET_SIGNAL_QUALITY_INDICATOR                   GetSignalQualityIndicator;
    QAM_DEMOD_FP_UPDATE_FUNCTION                     			UpdateFunction;
};

#define REALTEK_I_QAM_BASE_PRINT_LVL_DBG      0
#define REALTEK_I_QAM_BASE_PRINT_LVL_INFO     1
#define REALTEK_I_QAM_BASE_PRINT_LVL_WARNING  2

#ifndef REALTEK_I_QAM_BASE_PRINT_LVL
#define REALTEK_I_QAM_BASE_PRINT_LVL          REALTEK_I_QAM_BASE_PRINT_LVL_INFO
#endif

#define REALTEK_I_QAM_BASE_DBG(fmt, args...)        rtd_printk(KERN_DEBUG, "DEMO", "QAM_BASE_DEBUG, " fmt, ##args);
#define REALTEK_I_QAM_BASE_INFO(fmt, args...)       rtd_printk(KERN_INFO, "DEMO", "QAM_BASE_INFO, " fmt, ##args);
#define REALTEK_I_QAM_BASE_WARNING(fmt, args...)    rtd_printk(KERN_WARNING, "DEMO", "QAM_BASE_WARNING, " fmt, ##args);

#ifdef __cplusplus
}
#endif
#endif
