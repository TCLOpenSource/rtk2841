#ifndef __DVBS_DEMOD_BASE_H
#define __DVBS_DEMOD_BASE_H

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
#endif

// Common Register Setting
#define REALTEK_I_NOTCH_EN                                       0
#define REALTEK_I_NOTCH_FREQ                                     500000000
#define REALTEK_I_NOTCH_BW                                       1 //0~87
#define REALTEK_I_TS_DIS_MASK                                    0x00000001
#define REALTEK_I_TS_SERIAL_MASK                                 0x00000002
#define REALTEK_I_TS_CLK_PHASE_INV_MASK                          0x00000004
#define REALTEK_I_TS_PACKETS_188_MASK                            0x00000008
#define REALTEK_I_TS_CLOCK_GATE_MASK                             0x00000020

// DVBS Demod Module Pre-Definition
typedef struct DVBS_DEMOD_MODULE_TAG DVBS_DEMOD_MODULE;

typedef enum _REALTEK_I_DEMOD_DVBS_MOD_MODE {
    DVBS_DEMOD_MOD_MODE_QPSK = 0,
    DVBS_DEMOD_MOD_MODE_8PSK
}_REALTEK_I_DEMOD_DVBS_MOD_MODE;

typedef enum _REALTEK_I_DEMOD_DVBS_CODE_RATE {
    DVBS_DEMOD_CODE_RATE_1_2 = 0,
    DVBS_DEMOD_CODE_RATE_2_3,
    DVBS_DEMOD_CODE_RATE_3_4,
    DVBS_DEMOD_CODE_RATE_5_6,
    DVBS_DEMOD_CODE_RATE_7_8
}_REALTEK_I_DEMOD_DVBS_CODE_RATE;

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
(*DVBS_DEMOD_FP_ADDR_8BIT_SET_REG_PAGE)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned long PageNo
);

typedef int
(*DVBS_DEMOD_FP_ADDR_8BIT_SET_REG_BYTES)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	const unsigned char *pWritingBytes,
	unsigned long ByteNum
);

typedef int
(*DVBS_DEMOD_FP_ADDR_16BIT_SET_REG_BYTES)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	const unsigned char *pWritingBytes,
	unsigned long ByteNum
);

typedef int
(*DVBS_DEMOD_FP_ADDR_8BIT_GET_REG_BYTES)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char *pReadingBytes,
	unsigned long ByteNum
);

typedef int
(*DVBS_DEMOD_FP_ADDR_16BIT_GET_REG_BYTES)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char *pReadingBytes,
	unsigned long ByteNum
);

typedef int
(*DVBS_DEMOD_FP_ADDR_8BIT_SET_REG_MASK_BITS)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	const unsigned long WritingValue
);

typedef int
(*DVBS_DEMOD_FP_ADDR_16BIT_SET_REG_MASK_BITS)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	const unsigned long WritingValue
);

typedef int
(*DVBS_DEMOD_FP_ADDR_8BIT_GET_REG_MASK_BITS)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	unsigned long *pReadingValue
);

typedef int
(*DVBS_DEMOD_FP_ADDR_16BIT_GET_REG_MASK_BITS)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	unsigned long *pReadingValue
);

typedef int
(*DVBS_DEMOD_FP_ADDR_8BIT_SET_REG_BITS)(
	DVBS_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

typedef int
(*DVBS_DEMOD_FP_ADDR_16BIT_SET_REG_BITS)(
	DVBS_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

typedef int
(*DVBS_DEMOD_FP_ADDR_8BIT_GET_REG_BITS)(
	DVBS_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

typedef int
(*DVBS_DEMOD_FP_ADDR_16BIT_GET_REG_BITS)(
	DVBS_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

typedef int
(*DVBS_DEMOD_FP_ADDR_8BIT_SET_REG_BITS_WITH_PAGE)(
	DVBS_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

typedef int
(*DVBS_DEMOD_FP_ADDR_8BIT_GET_REG_BITS_WITH_PAGE)(
	DVBS_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

// Demod Register Access for 8-bit Address
typedef struct {
	DVBS_DEMOD_FP_ADDR_8BIT_SET_REG_PAGE             SetRegPage;
	DVBS_DEMOD_FP_ADDR_8BIT_SET_REG_BYTES            SetRegBytes;
	DVBS_DEMOD_FP_ADDR_8BIT_GET_REG_BYTES            GetRegBytes;
	DVBS_DEMOD_FP_ADDR_8BIT_SET_REG_MASK_BITS        SetRegMaskBits;
	DVBS_DEMOD_FP_ADDR_8BIT_GET_REG_MASK_BITS        GetRegMaskBits;
	DVBS_DEMOD_FP_ADDR_8BIT_SET_REG_BITS             SetRegBits;
	DVBS_DEMOD_FP_ADDR_8BIT_GET_REG_BITS             GetRegBits;
	DVBS_DEMOD_FP_ADDR_8BIT_SET_REG_BITS_WITH_PAGE   SetRegBitsWithPage;
	DVBS_DEMOD_FP_ADDR_8BIT_GET_REG_BITS_WITH_PAGE   GetRegBitsWithPage;
}
DVBS_DEMOD_REG_ACCESS_ADDR_8BIT;

// Demod Register Access for 16-bit Address
typedef struct {
	DVBS_DEMOD_FP_ADDR_16BIT_SET_REG_BYTES       SetRegBytes;
	DVBS_DEMOD_FP_ADDR_16BIT_GET_REG_BYTES       GetRegBytes;
	DVBS_DEMOD_FP_ADDR_16BIT_SET_REG_MASK_BITS   SetRegMaskBits;
	DVBS_DEMOD_FP_ADDR_16BIT_GET_REG_MASK_BITS   GetRegMaskBits;
	DVBS_DEMOD_FP_ADDR_16BIT_SET_REG_BITS        SetRegBits;
	DVBS_DEMOD_FP_ADDR_16BIT_GET_REG_BITS        GetRegBits;
}
DVBS_DEMOD_REG_ACCESS_ADDR_16BIT;

typedef void
(*DVBS_DEMOD_FP_GET_DEMOD_TYPE)(
	DVBS_DEMOD_MODULE *pDemod,
	int *pDemodType
);

typedef void
(*DVBS_DEMOD_FP_GET_DEVICE_ADDR)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned char *pDeviceAddr
);

typedef void
(*DVBS_DEMOD_FP_GET_CRYSTAL_FREQ_HZ)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned long *pCrystalFreqHz
);

// Demod Common Function Pointer
typedef int
(*DVBS_DEMOD_FP_CHECK_RPU_READY)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *IsRpuReady
);

typedef int
(*DVBS_DEMOD_FP_PING_RPU)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *IsLive
);

typedef int
(*DVBS_DEMOD_FP_SHUT_DOWN)(
	DVBS_DEMOD_MODULE *pDemod
);

typedef int
(*DVBS_DEMOD_FP_ACTIVATE_CORE)(
	DVBS_DEMOD_MODULE *pDemod
);

typedef int
(*DVBS_DEMOD_FP_DEACTIVATE_CORE)(
	DVBS_DEMOD_MODULE *pDemod
);

typedef int
(*DVBS_DEMOD_FP_SWITCH_TO_BUFFER)(
	DVBS_DEMOD_MODULE *pDemod
);

typedef int
(*DVBS_DEMOD_FP_GET_DEMOD_INFO)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *DemodType
);

typedef int
(*DVBS_DEMOD_FP_GET_BUILD_ID)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *BuildId
);

typedef int
(*DVBS_DEMOD_FP_DEMOD_CTRL_STOP)(
	DVBS_DEMOD_MODULE *pDemod
);

typedef int
(*DVBS_DEMOD_FP_DEMOD_CTRL_DETECT)(
	DVBS_DEMOD_MODULE *pDemod
);

typedef int
(*DVBS_DEMOD_FP_DEMOD_CTRL_RUN)(
	DVBS_DEMOD_MODULE *pDemod
);

typedef int
(*DVBS_DEMOD_FP_DEMOD_CTRL_UPDATE_RSSI)(
	DVBS_DEMOD_MODULE *pDemod
);

typedef int
(*DVBS_DEMOD_FP_DEMOD_CTRL_RESET_COUNTERS)(
	DVBS_DEMOD_MODULE *pDemod
);

typedef int
(*DVBS_DEMOD_FP_DEMOD_CTRL_UPDATE_COUNTERS)(
	DVBS_DEMOD_MODULE *pDemod
);

typedef int
(*DVBS_DEMOD_FP_DEMOD_CTRL_SET_AGC)(
	DVBS_DEMOD_MODULE *pDemod
);

typedef int
(*DVBS_DEMOD_FP_DEMOD_CTRL_UPDATE_AGC)(
	DVBS_DEMOD_MODULE *pDemod
);

typedef int
(*DVBS_DEMOD_FP_DEMOD_CTRL_QUERY_STATUS)(
	DVBS_DEMOD_MODULE *pDemod
);

typedef int
(*DVBS_DEMOD_FP_GET_DEMOD_STATUS)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *DemodStatus
);

typedef int
(*DVBS_DEMOD_FP_SET_TUNER_FREQ)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int TunerFreqHz
);

typedef int
(*DVBS_DEMOD_FP_SET_TUNER_BANDWIDTH)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int TunerBandwidthHz
);

typedef int
(*DVBS_DEMOD_FP_SET_TUNER_GRID_BASE)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int TunerGridBaseHz
);

typedef int
(*DVBS_DEMOD_FP_SET_TUNER_GRID_INCR)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int TunerGridIncrHz
);

typedef int
(*DVBS_DEMOD_FP_SET_NOTCH_FREQ)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int NotchFreqHz
);

typedef int
(*DVBS_DEMOD_FP_SET_NOTCH_BANDWIDTH)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int NotchBandwidth
);

typedef int
(*DVBS_DEMOD_FP_GET_ACT_TUNER_FREQ)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *ActiveFreqHz
);

typedef int
(*DVBS_DEMOD_FP_GET_ACT_TUNER_BANDWIDTH)(
	DVBS_DEMOD_MODULE *pDemod,
    unsigned int *ActiveBandwidth
);

typedef int
(*DVBS_DEMOD_FP_GET_ACT_TUNER_GAIN)(
	DVBS_DEMOD_MODULE *pDemod,
    unsigned int *ActiveTunerGain
);

typedef int
(*DVBS_DEMOD_FP_GET_ACT_TUNER_RSSI)(
	DVBS_DEMOD_MODULE *pDemod,
    unsigned int *ActiveTunerRssi
);

typedef int
(*DVBS_DEMOD_FP_SET_AGC_PARAMS)(
	DVBS_DEMOD_MODULE *pDemod,
    unsigned int AgcParam,
    unsigned int Index
);

typedef int
(*DVBS_DEMOD_FP_GET_AGC_PARAMS)(
	DVBS_DEMOD_MODULE *pDemod,
    unsigned int *AgcParam,
    unsigned int Index
);

typedef int
(*DVBS_DEMOD_FP_SET_TS_CONFIG)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int IsTsDis,
	unsigned int IsSerial,
	unsigned int IsInv,
	unsigned int IsPacket188
);

typedef int
(*DVBS_DEMOD_FP_SET_TS_CLK_RATE_MARGIN)(
	DVBS_DEMOD_MODULE *pDemod,
    unsigned int TsClkMargin
);

typedef int
(*DVBS_DEMOD_FP_SET_TS_CLK_RATE_MAX)(
	DVBS_DEMOD_MODULE *pDemod,
    unsigned int TsClkRateMax
);

typedef int
(*DVBS_DEMOD_FP_GET_DEMOD_LOCK_TIME)(
	DVBS_DEMOD_MODULE *pDemod,
    unsigned int *DemodLockTimeMs
);

typedef int
(*DVBS_DEMOD_FP_SET_VIRTUAL_REGISTER)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int PriRegAddr,
	unsigned int SecRegAddr,
	unsigned int RegVal
);

typedef int
(*DVBS_DEMOD_FP_GET_VIRTUAL_REGISTER)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int PriRegAddr,
	unsigned int SecRegAddr,
	unsigned int *RegVal
);

typedef int
(*DVBS_DEMOD_FP_SET_CMD_VIRTUAL_REGISTER)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int PriRegAddr,
	unsigned int SecRegAddr,
	unsigned int RegVal
);
/*
typedef int
(*DVBS_DEMOD_FP_SET_CTRL_VIRTUAL_REGISTER)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int PriRegAddr,
	unsigned int SecRegAddr,
	unsigned int RegVal
);

typedef int
(*DVBS_DEMOD_FP_GET_CTRL_VIRTUAL_REGISTER)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int PriRegAddr,
	unsigned int SecRegAddr,
	unsigned int *RegVal
);
*/
typedef int
(*DVBS_DEMOD_FP_SET_HW_REG_VAL)(
	unsigned int Addr,
    unsigned int Val
);

typedef int
(*DVBS_DEMOD_FP_GET_HW_REG_VAL)(
	unsigned int Addr,
    unsigned int *Val
);

// DVBS Specific Function Pointer
typedef int
(*DVBS_DEMOD_FP_SET_BAUD_RATE)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int BaudRate
);

typedef int
(*DVBS_DEMOD_FP_GET_BAUD_RATE)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *BaudRate
);

typedef int
(*DVBS_DEMOD_FP_SET_CODE_RATE)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int DemodCodeRate
);

typedef int
(*DVBS_DEMOD_FP_GET_CODE_RATE)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *DemodCodeRate
);

typedef int
(*DVBS_DEMOD_FP_GET_ACTIVE_BAUD_RATE)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *ActiveBaudRate
);

typedef int
(*DVBS_DEMOD_FP_GET_ACTIVE_CODE_RATE)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *ActiveCodeRate
);

typedef int
(*DVBS_DEMOD_FP_GET_BER_AT_VITERBI_INPUT)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *BerAtViterbiInput
);

typedef int
(*DVBS_DEMOD_FP_GET_BER_AT_RS_INPUT)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *BerAtRsInput
);

typedef int
(*DVBS_DEMOD_FP_GET_PER_AT_OUTPUT)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *PerAtOutput
);

typedef int
(*DVBS_DEMOD_FP_SET_NUM_SEC_BER_AVG)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int NumSecBerAvg
);

typedef int
(*DVBS_DEMOD_FP_GET_NUM_SEC_BER_AVG)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *NumSecBerAvg
);

typedef int
(*DVBS_DEMOD_FP_GET_TS_PACKET_COUNT)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *TsPacketCount
);

typedef int
(*DVBS_DEMOD_FP_GET_BAD_PACKET_COUNT)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *BadPacketCount
);

typedef int
(*DVBS_DEMOD_FP_GET_BIT_RATE)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *BitRate
);

typedef int
(*DVBS_DEMOD_FP_GET_SNR_ESTIMATE)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *SnrEstimate
);

typedef int
(*DVBS_DEMOD_FP_SET_CARRIER_FREQ_SEARCH_RANGE)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int CarrierFreqSearchRange
);

typedef int
(*DVBS_DEMOD_FP_GET_CARRIER_FREQ_SEARCH_RANGE)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *CarrierFreqSearchRange
);

typedef int
(*DVBS_DEMOD_FP_SET_SYMBOL_RATE_SEARCH_RANGE)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int SymbolRateSearchRange
);

typedef int
(*DVBS_DEMOD_FP_GET_SYMBOL_RATE_SEARCH_RANGE)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *SymbolRateSearchRange
);

typedef int
(*DVBS_DEMOD_FP_GET_ACQUISITION_STATE)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *AcquisitionState
);

typedef int
(*DVBS_DEMOD_FP_SET_NUM_ACQUISITIONS)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int NumAcquisitions
);

typedef int
(*DVBS_DEMOD_FP_GET_NUM_ACQUISITIONS)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *NumAcquisitions
);

typedef int
(*DVBS_DEMOD_FP_GET_ACQ_FAILURE_CODE)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *AcqFailureCode
);

typedef int
(*DVBS_DEMOD_FP_SET_DEMOD_ERROR_CODE)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int DemodErrorCode
);

typedef int
(*DVBS_DEMOD_FP_GET_DEMOD_ERROR_CODE)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *DemodErrorCode
);

typedef int
(*DVBS_DEMOD_FP_GET_I_AMP)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *IAmp
);

typedef int
(*DVBS_DEMOD_FP_GET_Q_AMP)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *QAmp
);

typedef int
(*DVBS_DEMOD_FP_GET_ANALOG_GAIN)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *AnalogGain
);

typedef int
(*DVBS_DEMOD_FP_GET_DIGITAL_GAIN)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *DigitalGain
);

typedef int
(*DVBS_DEMOD_FP_GET_ACQUISITION_TIME)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *AcquisitionTime
);

typedef int
(*DVBS_DEMOD_FP_GET_CARRIER_FREQ_OFFSET)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *CarrierFreqOffset
);

typedef int
(*DVBS_DEMOD_FP_SET_DEMOD_PHY_CTRL)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int DemodPhyCtrl
);

typedef int
(*DVBS_DEMOD_FP_GET_DEMOD_PHY_CTRL)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *DemodPhyCtrl
);

typedef int
(*DVBS_DEMOD_FP_SET_MANUAL_DFE_COEFF)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int ManualDfeCoeff
);

typedef int
(*DVBS_DEMOD_FP_GET_MANUAL_DFE_COEFF)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *ManualDfeCoeff
);

typedef int
(*DVBS_DEMOD_FP_SET_SPECTRUM_INVERSION)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int SpectrumInversion
);

typedef int
(*DVBS_DEMOD_FP_GET_SPECTRUM_INVERSION)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *SpectrumInversion
);

typedef int
(*DVBS_DEMOD_FP_SET_ACTIVE_SPECTRUM_INVERSION)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int ActiveSpectrumInversion
);

typedef int
(*DVBS_DEMOD_FP_GET_ACTIVE_SPECTRUM_INVERSION)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *ActiveSpectrumInversion
);

typedef int
(*DVBS_DEMOD_FP_SET_SYS_CLK_INFO)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int SysClkInfo
);

typedef int
(*DVBS_DEMOD_FP_SET_TONE_DETECT_CTRL)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int ToneDetectCtrl
);

typedef int
(*DVBS_DEMOD_FP_GET_TONE_DETECT_VALUE)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *ToneDetectValue
);

typedef int
(*DVBS_DEMOD_FP_SET_DFE_PHASE_TRACKER_STATE)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int DfePhaseTrackerState
);

typedef int
(*DVBS_DEMOD_FP_GET_DFE_PHASE_TRACKER_STATE)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *DfePhaseTrackerState
);

typedef int
(*DVBS_DEMOD_FP_GET_PHASE_TRACK_CTRL)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *PhaseTrackCtrl
);

typedef int
(*DVBS_DEMOD_FP_SET_TUNED_FREQ_OFFSET)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int TunedFreqOffset
);

typedef int
(*DVBS_DEMOD_FP_GET_TUNED_FREQ_OFFSET)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *TunedFreqOffset
);

typedef int
(*DVBS_DEMOD_FP_SET_TUNER_FREQ_REQUEST)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int TunerFreqRequest
);

typedef int
(*DVBS_DEMOD_FP_GET_TUNER_FREQ_REQUEST)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *TunerFreqRequest
);

typedef int
(*DVBS_DEMOD_FP_SET_TUNER_BW_REQUEST)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int TunerBwRequest
);

typedef int
(*DVBS_DEMOD_FP_GET_TUNER_BW_REQUEST)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *TunerBwRequest
);

typedef int
(*DVBS_DEMOD_FP_SET_META_LOG_DEBUG_PTR)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int MetaLogDebugPtr
);

typedef int
(*DVBS_DEMOD_FP_GET_META_LOG_DEBUG_PTR)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *MetaLogDebugPtr
);

typedef int
(*DVBS_DEMOD_FP_SET_META_LOG_PTR)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int MetaLogPtr
);

typedef int
(*DVBS_DEMOD_FP_GET_META_LOG_PTR)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *MetaLogPtr
);

typedef int
(*DVBS_DEMOD_FP_SET_MCP_LOG_PTR)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int McpLogPtr
);

typedef int
(*DVBS_DEMOD_FP_GET_MCP_LOG_PTR)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *McpLogPtr
);

typedef int
(*DVBS_DEMOD_FP_SET_DCP_LOG_PTR)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int DcpLogPtr
);

typedef int
(*DVBS_DEMOD_FP_GET_DCP_LOG_PTR)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *DcpLogPtr
);

typedef int
(*DVBS_DEMOD_FP_GET_IF_AGC_GAIN)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *IfAgcGain
);

typedef int
(*SA_DEMOD_FE_SET_SCAN_RANGE)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int ScanRange
);

typedef int
(*SA_DEMOD_FE_GET_SCAN_RANGE)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *ScanRange
);

typedef int
(*SA_DEMOD_FE_SET_SCAN_RESOLUTION)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int ScanResolution
);

typedef int
(*SA_DEMOD_FE_GET_SCAN_RANGE)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *ScanResolution
);

typedef int
(*SA_DEMOD_FE_SET_TUNING_STEP)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int TuningStepAuto,
	unsigned int TuningStep
);

typedef int
(*SA_DEMOD_FE_GET_TUNING_STEP)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *TuningStepAuto,
	unsigned int *TuningStep
);

typedef int
(*SA_DEMOD_FE_SET_MEASURE_CTRL)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int EnDcComp,
	unsigned int Window,
	unsigned int SignalType,
	unsigned int MaxPickWidth
);

typedef int
(*SA_DEMOD_FE_GET_MEASURE_CTRL)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *EnDcComp,
	unsigned int *Window,
	unsigned int *SignalType,
	unsigned int *MaxPickWidth
);

typedef int
(*SA_DEMOD_FE_SET_AVERAGE_PERIOD)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int AveragePeriodM,
	unsigned int AveragePeriodN
);

typedef int
(*SA_DEMOD_FE_GET_AVERAGE_PERIOD)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *AveragePeriodM,
	unsigned int *AveragePeriodN
);

typedef int
(*SA_DEMOD_FE_SET_IF_GAIN_OVERRIDE)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int OverrideIfGain,
	unsigned int IfGain
);

typedef int
(*SA_DEMOD_FE_GET_IF_GAIN_OVERRIDE)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *OverrideIfGain,
	unsigned int *IfGain
);

typedef int
(*SA_DEMOD_FE_SET_TUNER_3DB_POINT)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int FreqSpacing
);

typedef int
(*SA_DEMOD_FE_SET_TUNER_6DB_POINT)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int FreqSpacing
);

typedef int
(*SA_DEMOD_FE_SET_TUNER_9DB_POINT)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int FreqSpacing
);

typedef int
(*SA_DEMOD_FE_SET_TUNER_12DB_POINT)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int FreqSpacing
);

typedef int
(*SA_DEMOD_FE_GET_OUT_SPECTRUM_PTR)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *OutSpecMemType,
	unsigned int *SpecMemPtr
);

typedef int
(*SA_DEMOD_FE_GET_OUT_SPECTRUM_LEN)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *OutSpecLen
);

typedef int
(*SA_DEMOD_FE_GET_MAX_RSSI)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *MaxRssi,
	unsigned int *MaxRssiIdx
);

typedef int
(*SA_DEMOD_FE_GET_REF_IF_GAIN)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *RefIfGain
);


typedef int
(*SA_DEMOD_FE_GET_MAX_PWR)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int Number,
	unsigned int *MaxPwrDb,
	unsigned int *MaxPwrindex
);

typedef int
(*SA_DEMOD_FE_GET_FAILURE_CODE)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *OutOfMem
);

typedef int
(*SA_DEMOD_FE_GET_COMPLETTION_PERCENT)(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *CompPercent
);

//DiSEqC
typedef int
(*DVBS_DEMOD_FP_SET_CONT_22K_ON_OFF)(
    unsigned int Diseqc22kOnOff
);

typedef int
(*DVBS_DEMOD_FP_SET_DISEQC_CMD)(
    unsigned int DataLength,
    unsigned char *Data
);

typedef int
(*DVBS_DEMOD_FP_SET_UN_MOD_TONE_BURST)(void);

typedef int
(*DVBS_DEMOD_FP_SET_MOD_TONE_BURST)(void);

int
dvbs_demod_addr_16bit_default_SetRegBits(
	DVBS_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

int
dvbs_demod_addr_16bit_default_GetRegBits(
	DVBS_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

// DVBS Demod Default Manipulating Functions
void
dvbs_demod_default_GetDemodType(
	DVBS_DEMOD_MODULE *pDemod,
	int *pDemodType
);

void
dvbs_demod_default_GetDeviceAddr(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned char *pDeviceAddr
);

void
dvbs_demod_default_GetCrystalFreqHz(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned long *pCrystalFreqHz
);

// Demod Common Function
int
realtek_i_dvbs_common_CheckRpuReady(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *IsRpuReady
);

int
realtek_i_dvbs_common_PingRpu(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *IsLive
);

int
realtek_i_dvbs_common_ShutDown(
	DVBS_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbs_common_ActivateCore(
	DVBS_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbs_common_DeactivateCore(
	DVBS_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbs_common_SwitchToBuffer(
	DVBS_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbs_common_GetDemodInfo(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *DemodType
);

int
realtek_i_dvbs_common_GetBuildId(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *BuildId
);

int
realtek_i_dvbs_common_DemodCtrlStopCmd(
	DVBS_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbs_common_DemodCtrlDetectCmd(
	DVBS_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbs_common_DemodCtrlRunCmd(
	DVBS_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbs_common_DemodCtrlUpdateRssiCmd(
	DVBS_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbs_common_DemodCtrlResetCountersCmd(
	DVBS_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbs_common_DemodCtrlUpdateCountersCmd(
	DVBS_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbs_common_DemodCtrlSetAgcCmd(
	DVBS_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbs_common_DemodCtrlUpdateAgcCmd(
	DVBS_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbs_common_DemodCtrlQueryStatusCmd(
	DVBS_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbs_common_GetDemodStatus(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *DemodStatus
);

int
realtek_i_dvbs_common_SetTunerFreqCmd(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int TunerFreqHz
);

int
realtek_i_dvbs_common_SetTunerBandwidth(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int TunerBandwidthHz
);

int
realtek_i_dvbs_common_SetTunerGridBase(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int TunerGridBaseHz
);

int
realtek_i_dvbs_common_SetTunerGridIncr(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int TunerGridIncrHz
);

int
realtek_i_dvbs_common_SetNotchFreqCmd(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int NotchFreqHz
);

int
realtek_i_dvbs_common_SetNotchBandwidth(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int NotchBandwidth
);

int
realtek_i_dvbs_common_GetActiveTunerFreq(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int *ActiveFreqHz
);

int
realtek_i_dvbs_common_GetActiveTunerBandwidth(
	DVBS_DEMOD_MODULE *pDemod,
    unsigned int *ActiveBandwidth
);

int
realtek_i_dvbs_common_GetActiveTunerGain(
	DVBS_DEMOD_MODULE *pDemod,
    unsigned int *ActiveTunerGain
);

int
realtek_i_dvbs_common_GetActiveTunerRssi(
	DVBS_DEMOD_MODULE *pDemod,
    unsigned int *ActiveTunerRssi
);

int
realtek_i_dvbs_common_SetAgcParams(
	DVBS_DEMOD_MODULE *pDemod,
    unsigned int AgcParam,
    unsigned int Index
);

int
realtek_i_dvbs_common_GetAgcParams(
	DVBS_DEMOD_MODULE *pDemod,
    unsigned int *AgcParam,
    unsigned int Index
);

int
realtek_i_dvbs_common_SetTsConfig(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int IsTsDis,
	unsigned int IsSerial,
	unsigned int IsInv,
	unsigned int IsPacket188
);

int
realtek_i_dvbs_common_SetTsClkRateMargin(
	DVBS_DEMOD_MODULE *pDemod,
    unsigned int TsClkMargin
);

int
realtek_i_dvbs_common_SetTsClkRateMax(
	DVBS_DEMOD_MODULE *pDemod,
    unsigned int TsClkRateMax
);

int
realtek_i_dvbs_common_GetDemodLockTime(
	DVBS_DEMOD_MODULE *pDemod,
    unsigned int *DemodLockTimeMs
);

int
realtek_i_dvbs_common_SetHwRegValue(
	unsigned int Addr,
    unsigned int Val
);

int
realtek_i_dvbs_common_GetHwRegValue(
	unsigned int Addr,
    unsigned int *Val
);

int
realtek_i_dvbs_common_SetXmlTunerCfgOverride(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int TunerCfg
);

int
realtek_i_dvbs_common_SetXmlTunerGainCtrl(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int TunerGainCtrl
);

int
realtek_i_dvbs_common_SetXmlFlags(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int Flags
);

int
realtek_i_dvbs_common_SetXmlIfFreq(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int IfFreq
);

int
realtek_i_dvbs_common_SetXmlPlatformCfgOverride(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int PlatformCfg
);

int
realtek_i_dvbs_common_SetXmlIfClk(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int IfClk
);

int
realtek_i_dvbs_common_SetXmlLdpcClk(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int LdpcClk
);

int
realtek_i_dvbs_common_SetXmlUccClk(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int UccClk
);

int
realtek_i_dvbs_common_SetXmlMcuClk(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int McuClk
);

int
realtek_i_dvbs_common_SetVirtualRegister(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int PriRegAddr,
	unsigned int SecRegAddr,
	unsigned int RegVal
);

int
realtek_i_dvbs_common_GetVirtualRegister(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int PriRegAddr,
	unsigned int SecRegAddr,
	unsigned int *RegVal
);

int
realtek_i_dvbs_common_SetCmdVirtualRegister(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int PriRegAddr,
	unsigned int SecRegAddr,
	unsigned int RegVal
);
/*
int
realtek_i_dvbs_common_SetCtrlVirtualRegister(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int PriRegAddr,
	unsigned int SecRegAddr,
	unsigned int RegVal
);

int
realtek_i_dvbs_common_GetCtrlVirtualRegister(
	DVBS_DEMOD_MODULE *pDemod,
	unsigned int PriRegAddr,
	unsigned int SecRegAddr,
	unsigned int *RegVal
);
*/
// DVBS Demod Module Structure
struct DVBS_DEMOD_MODULE_TAG {
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

	int           IsQamModeSet;
	int           IsSymbolRateHzSet;
	int           IsAlphaModeSet;
	int           IsIfFreqHzSet;
	int           IsSpectrumModeSet;

	BASE_INTERFACE_MODULE *pBaseInterface;
	I2C_BRIDGE_MODULE *pI2cBridge;

	// Demod I2C Function Pointers
	union {
		DVBS_DEMOD_REG_ACCESS_ADDR_8BIT  Addr8Bit;
		DVBS_DEMOD_REG_ACCESS_ADDR_16BIT Addr16Bit;
	}
	RegAccess;

	// Demod Manipulating Function Pointers
	DVBS_DEMOD_FP_GET_DEMOD_TYPE                GetDemodType;
	DVBS_DEMOD_FP_GET_DEVICE_ADDR               GetDeviceAddr;
	DVBS_DEMOD_FP_GET_CRYSTAL_FREQ_HZ           GetCrystalFreqHz;

    // Common TV Api
    DVBS_DEMOD_FP_CHECK_RPU_READY               CheckRpuReady;
    DVBS_DEMOD_FP_PING_RPU                      PingRpu;
    DVBS_DEMOD_FP_SHUT_DOWN                     ShutDown;
    DVBS_DEMOD_FP_ACTIVATE_CORE                 ActivateCore;
    DVBS_DEMOD_FP_DEACTIVATE_CORE               DeactivateCore;
    DVBS_DEMOD_FP_SWITCH_TO_BUFFER		SwitchToBuffer;
    
    DVBS_DEMOD_FP_GET_DEMOD_INFO                GetDemodInfo;
    DVBS_DEMOD_FP_GET_BUILD_ID                  GetBuildId;
    DVBS_DEMOD_FP_DEMOD_CTRL_STOP               DemodCtrlStop;
    DVBS_DEMOD_FP_DEMOD_CTRL_DETECT             DemodCtrlDetect;
    DVBS_DEMOD_FP_DEMOD_CTRL_RUN                DemodCtrlRun;
    DVBS_DEMOD_FP_DEMOD_CTRL_UPDATE_RSSI        DemodCtrlUpdateRssi;
    DVBS_DEMOD_FP_DEMOD_CTRL_RESET_COUNTERS     DemodCtrlResetCounters;
    DVBS_DEMOD_FP_DEMOD_CTRL_UPDATE_COUNTERS    DemodCtrlUpdateCounters;
    DVBS_DEMOD_FP_DEMOD_CTRL_SET_AGC            DemodCtrlSetAgc;
    DVBS_DEMOD_FP_DEMOD_CTRL_UPDATE_AGC         DemodCtrlUpdateAgc;
    DVBS_DEMOD_FP_DEMOD_CTRL_QUERY_STATUS       DemodCtrlQueryStatus;
    DVBS_DEMOD_FP_GET_DEMOD_STATUS              GetDemodStatus;

    DVBS_DEMOD_FP_SET_TUNER_FREQ                SetTunerFreq;
    DVBS_DEMOD_FP_SET_TUNER_BANDWIDTH           SetTunerBandwidth;
    DVBS_DEMOD_FP_SET_TUNER_GRID_BASE           SetTunerGridBase;
    DVBS_DEMOD_FP_SET_TUNER_GRID_INCR           SetTunerGridIncr;
    DVBS_DEMOD_FP_SET_NOTCH_FREQ                SetNotchFreq;
    DVBS_DEMOD_FP_SET_NOTCH_BANDWIDTH           SetNotchBandwidth;
    DVBS_DEMOD_FP_GET_ACT_TUNER_FREQ            GetActiveTunerFreq;
    DVBS_DEMOD_FP_GET_ACT_TUNER_BANDWIDTH       GetActiveTunerBandwidth;
    DVBS_DEMOD_FP_GET_ACT_TUNER_GAIN            GetActiveTunerGain;
    DVBS_DEMOD_FP_GET_ACT_TUNER_RSSI            GetActiveTunerRssi;
    DVBS_DEMOD_FP_SET_AGC_PARAMS                SetAgcParams;
    DVBS_DEMOD_FP_GET_AGC_PARAMS                GetAgcParams;
    DVBS_DEMOD_FP_SET_TS_CONFIG                 SetTsConfig;
    DVBS_DEMOD_FP_SET_TS_CLK_RATE_MARGIN        SetTsClkRateMargin;
    DVBS_DEMOD_FP_SET_TS_CLK_RATE_MAX           SetTsClkRateMax;
    DVBS_DEMOD_FP_GET_DEMOD_LOCK_TIME           GetDemodLockTime;

    
    DVBS_DEMOD_FP_SET_VIRTUAL_REGISTER          SetVirtualRegister;
    DVBS_DEMOD_FP_GET_VIRTUAL_REGISTER          GetVirtualRegister;
	DVBS_DEMOD_FP_SET_CMD_VIRTUAL_REGISTER      SetCmdVirtualRegister;
    //DVBS_DEMOD_FP_SET_CTRL_VIRTUAL_REGISTER     SetCtrlVirtualRegister;
    //DVBS_DEMOD_FP_GET_CTRL_VIRTUAL_REGISTER     GetCtrlVirtualRegister;
    DVBS_DEMOD_FP_SET_HW_REG_VAL                SetHwRegValue;
    DVBS_DEMOD_FP_GET_HW_REG_VAL                GetHwRegValue;

    // DVBS Specific Api
    DVBS_DEMOD_FP_SET_BAUD_RATE                   SetBaudRate;
    DVBS_DEMOD_FP_GET_BAUD_RATE                   GetBaudRate;
    DVBS_DEMOD_FP_SET_CODE_RATE                   SetCodeRate;
    DVBS_DEMOD_FP_GET_CODE_RATE                   GetCodeRate;
    DVBS_DEMOD_FP_GET_ACTIVE_BAUD_RATE            GetActiveBaudRate;
    DVBS_DEMOD_FP_GET_ACTIVE_CODE_RATE            GetActiveCodeRate;
    DVBS_DEMOD_FP_GET_BER_AT_VITERBI_INPUT        GetBerAtViterbiInput;
    DVBS_DEMOD_FP_GET_BER_AT_RS_INPUT             GetBerAtRsInput;
    DVBS_DEMOD_FP_GET_PER_AT_OUTPUT               GetPerAtOutput;
    DVBS_DEMOD_FP_SET_NUM_SEC_BER_AVG             SetNumSecBerAvg;
    DVBS_DEMOD_FP_GET_NUM_SEC_BER_AVG             GetNumSecBerAvg;
    DVBS_DEMOD_FP_GET_TS_PACKET_COUNT             GetTsPacketCount;
    DVBS_DEMOD_FP_GET_BAD_PACKET_COUNT            GetBadPacketCount;
    DVBS_DEMOD_FP_GET_BIT_RATE                    GetBitRate;
    DVBS_DEMOD_FP_GET_SNR_ESTIMATE                GetSnrEstimate;
    DVBS_DEMOD_FP_SET_CARRIER_FREQ_SEARCH_RANGE   SetCarrierFreqSearchRange;
    DVBS_DEMOD_FP_GET_CARRIER_FREQ_SEARCH_RANGE   GetCarrierFreqSearchRange;
    DVBS_DEMOD_FP_SET_SYMBOL_RATE_SEARCH_RANGE    SetSymbolRateSearchRange;
    DVBS_DEMOD_FP_GET_SYMBOL_RATE_SEARCH_RANGE    GetSymbolRateSearchRange;
    DVBS_DEMOD_FP_GET_ACQUISITION_STATE           GetAcquisitionState;
    DVBS_DEMOD_FP_SET_NUM_ACQUISITIONS            SetNumAcquisitions;
    DVBS_DEMOD_FP_GET_NUM_ACQUISITIONS            GetNumAcquisitions;
    DVBS_DEMOD_FP_GET_ACQ_FAILURE_CODE            GetAcqFailureCode;
    DVBS_DEMOD_FP_SET_DEMOD_ERROR_CODE            SetDemodErrorCode;
    DVBS_DEMOD_FP_GET_DEMOD_ERROR_CODE            GetDemodErrorCode;
    DVBS_DEMOD_FP_GET_I_AMP                       GetIAmp;
    DVBS_DEMOD_FP_GET_Q_AMP                       GetQAmp;
    DVBS_DEMOD_FP_GET_ANALOG_GAIN                 GetAnalogGain;
    DVBS_DEMOD_FP_GET_DIGITAL_GAIN                GetDigitalGain;
    DVBS_DEMOD_FP_GET_ACQUISITION_TIME            GetAcquisitionTime;
    DVBS_DEMOD_FP_GET_CARRIER_FREQ_OFFSET         GetCarrierFreqOffset;
    DVBS_DEMOD_FP_SET_DEMOD_PHY_CTRL              SetDemodPhyCtrl;
    DVBS_DEMOD_FP_GET_DEMOD_PHY_CTRL              GetDemodPhyCtrl;
    DVBS_DEMOD_FP_SET_MANUAL_DFE_COEFF            SetManualDfeCoeff;
    DVBS_DEMOD_FP_GET_MANUAL_DFE_COEFF            GetManualDfeCoeff;
    DVBS_DEMOD_FP_SET_SPECTRUM_INVERSION          SetSpectrumInversion;
    DVBS_DEMOD_FP_GET_SPECTRUM_INVERSION          GetSpectrumInversion;
    DVBS_DEMOD_FP_SET_ACTIVE_SPECTRUM_INVERSION   SetActiveSpectrumInversion;
    DVBS_DEMOD_FP_GET_ACTIVE_SPECTRUM_INVERSION   GetActiveSpectrumInversion;
    DVBS_DEMOD_FP_SET_TONE_DETECT_CTRL            SetToneDetectCtrl;
    DVBS_DEMOD_FP_GET_TONE_DETECT_VALUE           GetToneDetectValue;
    DVBS_DEMOD_FP_SET_DFE_PHASE_TRACKER_STATE     SetDfePhaseTrackerState;
    DVBS_DEMOD_FP_GET_DFE_PHASE_TRACKER_STATE     GetDfePhaseTrackerState;
    DVBS_DEMOD_FP_GET_PHASE_TRACK_CTRL            GetPhaseTrackCtrl;
    DVBS_DEMOD_FP_SET_TUNED_FREQ_OFFSET           SetTunedFreqOffset;
    DVBS_DEMOD_FP_GET_TUNED_FREQ_OFFSET           GetTunedFreqOffset;
    DVBS_DEMOD_FP_SET_TUNER_FREQ_REQUEST          SetTunerFreqRequest;
    DVBS_DEMOD_FP_GET_TUNER_FREQ_REQUEST          GetTunerFreqRequest;
    DVBS_DEMOD_FP_SET_TUNER_BW_REQUEST            SetTunerBwRequest;
    DVBS_DEMOD_FP_GET_TUNER_BW_REQUEST            GetTunerBwRequest;
    DVBS_DEMOD_FP_SET_META_LOG_DEBUG_PTR          SetMetaLogDebugPtr;
    DVBS_DEMOD_FP_GET_META_LOG_DEBUG_PTR          GetMetaLogDebugPtr;
    DVBS_DEMOD_FP_SET_META_LOG_PTR                SetMetaLogPtr;
    DVBS_DEMOD_FP_GET_META_LOG_PTR                GetMetaLogPtr;
    DVBS_DEMOD_FP_SET_MCP_LOG_PTR                 SetMcpLogPtr;
    DVBS_DEMOD_FP_GET_MCP_LOG_PTR                 GetMcpLogPtr;
    DVBS_DEMOD_FP_SET_DCP_LOG_PTR                 SetDcpLogPtr;
    DVBS_DEMOD_FP_GET_DCP_LOG_PTR                 GetDcpLogPtr;
    DVBS_DEMOD_FP_GET_IF_AGC_GAIN                 GetIfAgcGain;

    DVBS_DEMOD_FP_SET_CONT_22K_ON_OFF             SetContinue22kOnOff;
    DVBS_DEMOD_FP_SET_DISEQC_CMD                  SetDiseqcCmd;
    DVBS_DEMOD_FP_SET_UN_MOD_TONE_BURST           SetUnModToneBurst;
    DVBS_DEMOD_FP_SET_MOD_TONE_BURST              SetModToneBurst;

    SA_DEMOD_FE_SET_SCAN_RANGE                          DvbSSetSpecAnScanRange;
    SA_DEMOD_FE_GET_SCAN_RANGE                          DvbSGetSpecAnScanRange;
    SA_DEMOD_FE_SET_SCAN_RESOLUTION                     DvbSSetSpecAnScanResolution;
    SA_DEMOD_FE_GET_SCAN_RANGE                          DvbSGetSpecAnScanResolution;
    SA_DEMOD_FE_SET_TUNING_STEP                         DvbSSetSpecAnTuningStep;
    SA_DEMOD_FE_GET_TUNING_STEP                         DvbSGetSpecAnTuningStep;
    SA_DEMOD_FE_SET_MEASURE_CTRL                        DvbSSetSpecAnMeasureCtrl;
    SA_DEMOD_FE_GET_MEASURE_CTRL                        DvbSGetSpecAnMeasureCtrl;
    SA_DEMOD_FE_SET_AVERAGE_PERIOD                      DvbSSetSpecAnAveragePeriod;
    SA_DEMOD_FE_GET_AVERAGE_PERIOD                      DvbSGetSpecAnAveragePeriod;
    SA_DEMOD_FE_SET_IF_GAIN_OVERRIDE                    DvbSSetSpecAnIfGainOverride;
    SA_DEMOD_FE_GET_IF_GAIN_OVERRIDE                    DvbSGetSpecAnIfGainOverride;
    SA_DEMOD_FE_SET_TUNER_3DB_POINT                     DvbSSetSpecAnTuner3dBPoint;
    SA_DEMOD_FE_SET_TUNER_6DB_POINT                     DvbSSetSpecAnTuner6dBPoint;
    SA_DEMOD_FE_SET_TUNER_9DB_POINT                     DvbSSetSpecAnTuner9dBPoint;
    SA_DEMOD_FE_SET_TUNER_12DB_POINT                    DvbSSetSpecAnTuner12dBPoint;
    SA_DEMOD_FE_GET_OUT_SPECTRUM_PTR                    DvbSGetSpecAnOutSpectrumPtr;
    SA_DEMOD_FE_GET_OUT_SPECTRUM_LEN                    DvbSGetSpecAnOutSpectrumLen;
    SA_DEMOD_FE_GET_MAX_RSSI                            DvbSGetSpecAnMaxRssi;
    SA_DEMOD_FE_GET_REF_IF_GAIN                         DvbSGetSpecAnRefIfGain;
    SA_DEMOD_FE_GET_MAX_PWR                             DvbSGetSpecAnMaxPwr;
    SA_DEMOD_FE_GET_FAILURE_CODE                        DvbSGetSpecAnFailureCode;
    SA_DEMOD_FE_GET_COMPLETTION_PERCENT                 DvbSGetSpecAnCompletionPercent;
};

#define REALTEK_I_DVBS_BASE_PRINT_LVL_DBG      0
#define REALTEK_I_DVBS_BASE_PRINT_LVL_INFO     1
#define REALTEK_I_DVBS_BASE_PRINT_LVL_WARNING  2


#ifndef REALTEK_I_DVBS_BASE_PRINT_LVL
#define REALTEK_I_DVBS_BASE_PRINT_LVL          REALTEK_I_DVBS_BASE_PRINT_LVL_INFO
#endif

#define REALTEK_I_DVBS_BASE_DBG(fmt, args...)        rtd_printk(KERN_DEBUG, "DEMO", "DVBS_BASE_DEBUG, " fmt, ##args);
#define REALTEK_I_DVBS_BASE_INFO(fmt, args...)       rtd_printk(KERN_INFO, "DEMO", "DVBS_BASE_INFO, " fmt, ##args);
#define REALTEK_I_DVBS_BASE_WARNING(fmt, args...)    rtd_printk(KERN_WARNING, "DEMO", "DVBS_BASE_WARNING, " fmt, ##args);


#ifdef __cplusplus
}
#endif
#endif
