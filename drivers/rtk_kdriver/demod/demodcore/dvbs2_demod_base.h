#ifndef __DVBS2_DEMOD_BASE_H
#define __DVBS2_DEMOD_BASE_H

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

// DVBS2 Demod Module Pre-Definition
typedef struct DVBS2_DEMOD_MODULE_TAG DVBS2_DEMOD_MODULE;

typedef enum _REALTEK_I_DEMOD_DVBS2_MOD_MODE {
    DVBS2_DEMOD_MOD_MODE_QPSK = 0,
    DVBS2_DEMOD_MOD_MODE_8PSK
}_REALTEK_I_DEMOD_DVBS2_MOD_MODE;

typedef enum _REALTEK_I_DEMOD_DVBS2_CODE_RATE {
    DVBS2_DEMOD_CODE_RATE_1_2 = 0,
    DVBS2_DEMOD_CODE_RATE_2_3,
    DVBS2_DEMOD_CODE_RATE_3_4,
    DVBS2_DEMOD_CODE_RATE_5_6,
    DVBS2_DEMOD_CODE_RATE_RVSD,
    DVBS2_DEMOD_CODE_RATE_3_5,
    DVBS2_DEMOD_CODE_RATE_4_5,
    DVBS2_DEMOD_CODE_RATE_8_9,
    DVBS2_DEMOD_CODE_RATE_9_10
}_REALTEK_I_DEMOD_DVBS2_CODE_RATE;

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
(*DVBS2_DEMOD_FP_ADDR_8BIT_SET_REG_PAGE)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned long PageNo
);

typedef int
(*DVBS2_DEMOD_FP_ADDR_8BIT_SET_REG_BYTES)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	const unsigned char *pWritingBytes,
	unsigned long ByteNum
);

typedef int
(*DVBS2_DEMOD_FP_ADDR_16BIT_SET_REG_BYTES)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	const unsigned char *pWritingBytes,
	unsigned long ByteNum
);

typedef int
(*DVBS2_DEMOD_FP_ADDR_8BIT_GET_REG_BYTES)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char *pReadingBytes,
	unsigned long ByteNum
);

typedef int
(*DVBS2_DEMOD_FP_ADDR_16BIT_GET_REG_BYTES)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char *pReadingBytes,
	unsigned long ByteNum
);

typedef int
(*DVBS2_DEMOD_FP_ADDR_8BIT_SET_REG_MASK_BITS)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	const unsigned long WritingValue
);

typedef int
(*DVBS2_DEMOD_FP_ADDR_16BIT_SET_REG_MASK_BITS)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	const unsigned long WritingValue
);

typedef int
(*DVBS2_DEMOD_FP_ADDR_8BIT_GET_REG_MASK_BITS)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	unsigned long *pReadingValue
);

typedef int
(*DVBS2_DEMOD_FP_ADDR_16BIT_GET_REG_MASK_BITS)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	unsigned long *pReadingValue
);

typedef int
(*DVBS2_DEMOD_FP_ADDR_8BIT_SET_REG_BITS)(
	DVBS2_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

typedef int
(*DVBS2_DEMOD_FP_ADDR_16BIT_SET_REG_BITS)(
	DVBS2_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

typedef int
(*DVBS2_DEMOD_FP_ADDR_8BIT_GET_REG_BITS)(
	DVBS2_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

typedef int
(*DVBS2_DEMOD_FP_ADDR_16BIT_GET_REG_BITS)(
	DVBS2_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

typedef int
(*DVBS2_DEMOD_FP_ADDR_8BIT_SET_REG_BITS_WITH_PAGE)(
	DVBS2_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

typedef int
(*DVBS2_DEMOD_FP_ADDR_8BIT_GET_REG_BITS_WITH_PAGE)(
	DVBS2_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

// Demod Register Access for 8-bit Address
typedef struct {
	DVBS2_DEMOD_FP_ADDR_8BIT_SET_REG_PAGE             SetRegPage;
	DVBS2_DEMOD_FP_ADDR_8BIT_SET_REG_BYTES            SetRegBytes;
	DVBS2_DEMOD_FP_ADDR_8BIT_GET_REG_BYTES            GetRegBytes;
	DVBS2_DEMOD_FP_ADDR_8BIT_SET_REG_MASK_BITS        SetRegMaskBits;
	DVBS2_DEMOD_FP_ADDR_8BIT_GET_REG_MASK_BITS        GetRegMaskBits;
	DVBS2_DEMOD_FP_ADDR_8BIT_SET_REG_BITS             SetRegBits;
	DVBS2_DEMOD_FP_ADDR_8BIT_GET_REG_BITS             GetRegBits;
	DVBS2_DEMOD_FP_ADDR_8BIT_SET_REG_BITS_WITH_PAGE   SetRegBitsWithPage;
	DVBS2_DEMOD_FP_ADDR_8BIT_GET_REG_BITS_WITH_PAGE   GetRegBitsWithPage;
}
DVBS2_DEMOD_REG_ACCESS_ADDR_8BIT;

// Demod Register Access for 16-bit Address
typedef struct {
	DVBS2_DEMOD_FP_ADDR_16BIT_SET_REG_BYTES       SetRegBytes;
	DVBS2_DEMOD_FP_ADDR_16BIT_GET_REG_BYTES       GetRegBytes;
	DVBS2_DEMOD_FP_ADDR_16BIT_SET_REG_MASK_BITS   SetRegMaskBits;
	DVBS2_DEMOD_FP_ADDR_16BIT_GET_REG_MASK_BITS   GetRegMaskBits;
	DVBS2_DEMOD_FP_ADDR_16BIT_SET_REG_BITS        SetRegBits;
	DVBS2_DEMOD_FP_ADDR_16BIT_GET_REG_BITS        GetRegBits;
}
DVBS2_DEMOD_REG_ACCESS_ADDR_16BIT;

typedef void
(*DVBS2_DEMOD_FP_GET_DEMOD_TYPE)(
	DVBS2_DEMOD_MODULE *pDemod,
	int *pDemodType
);

typedef void
(*DVBS2_DEMOD_FP_GET_DEVICE_ADDR)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned char *pDeviceAddr
);

typedef void
(*DVBS2_DEMOD_FP_GET_CRYSTAL_FREQ_HZ)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned long *pCrystalFreqHz
);

// Demod Common Function Pointer
typedef int
(*DVBS2_DEMOD_FP_CHECK_RPU_READY)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *IsRpuReady
);

typedef int
(*DVBS2_DEMOD_FP_PING_RPU)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *IsLive
);

typedef int
(*DVBS2_DEMOD_FP_SHUT_DOWN)(
	DVBS2_DEMOD_MODULE *pDemod
);

typedef int
(*DVBS2_DEMOD_FP_ACTIVATE_CORE)(
	DVBS2_DEMOD_MODULE *pDemod
);

typedef int
(*DVBS2_DEMOD_FP_DEACTIVATE_CORE)(
	DVBS2_DEMOD_MODULE *pDemod
);

typedef int
(*DVBS2_DEMOD_FP_SWITCH_TO_BUFFER)(
	DVBS2_DEMOD_MODULE *pDemod
);

typedef int
(*DVBS2_DEMOD_FP_GET_DEMOD_INFO)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *DemodType
);

typedef int
(*DVBS2_DEMOD_FP_GET_BUILD_ID)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *BuildId
);

typedef int
(*DVBS2_DEMOD_FP_DEMOD_CTRL_STOP)(
	DVBS2_DEMOD_MODULE *pDemod
);

typedef int
(*DVBS2_DEMOD_FP_DEMOD_CTRL_DETECT)(
	DVBS2_DEMOD_MODULE *pDemod
);

typedef int
(*DVBS2_DEMOD_FP_DEMOD_CTRL_RUN)(
	DVBS2_DEMOD_MODULE *pDemod
);

typedef int
(*DVBS2_DEMOD_FP_DEMOD_CTRL_UPDATE_RSSI)(
	DVBS2_DEMOD_MODULE *pDemod
);

typedef int
(*DVBS2_DEMOD_FP_DEMOD_CTRL_RESET_COUNTERS)(
	DVBS2_DEMOD_MODULE *pDemod
);

typedef int
(*DVBS2_DEMOD_FP_DEMOD_CTRL_UPDATE_COUNTERS)(
	DVBS2_DEMOD_MODULE *pDemod
);

typedef int
(*DVBS2_DEMOD_FP_DEMOD_CTRL_SET_AGC)(
	DVBS2_DEMOD_MODULE *pDemod
);

typedef int
(*DVBS2_DEMOD_FP_DEMOD_CTRL_UPDATE_AGC)(
	DVBS2_DEMOD_MODULE *pDemod
);

typedef int
(*DVBS2_DEMOD_FP_DEMOD_CTRL_QUERY_STATUS)(
	DVBS2_DEMOD_MODULE *pDemod
);

typedef int
(*DVBS2_DEMOD_FP_GET_DEMOD_STATUS)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *DemodStatus
);

typedef int
(*DVBS2_DEMOD_FP_SET_TUNER_FREQ)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int TunerFreqHz
);

typedef int
(*DVBS2_DEMOD_FP_SET_TUNER_BANDWIDTH)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int TunerBandwidthHz
);

typedef int
(*DVBS2_DEMOD_FP_SET_TUNER_GRID_BASE)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int TunerGridBaseHz
);

typedef int
(*DVBS2_DEMOD_FP_SET_TUNER_GRID_INCR)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int TunerGridIncrHz
);

typedef int
(*DVBS2_DEMOD_FP_SET_NOTCH_FREQ)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int NotchFreqHz
);

typedef int
(*DVBS2_DEMOD_FP_SET_NOTCH_BANDWIDTH)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int NotchBandwidth
);

typedef int
(*DVBS2_DEMOD_FP_GET_ACT_TUNER_FREQ)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ActiveFreqHz
);

typedef int
(*DVBS2_DEMOD_FP_GET_ACT_TUNER_BANDWIDTH)(
	DVBS2_DEMOD_MODULE *pDemod,
    unsigned int *ActiveBandwidth
);

typedef int
(*DVBS2_DEMOD_FP_GET_ACT_TUNER_GAIN)(
	DVBS2_DEMOD_MODULE *pDemod,
    unsigned int *ActiveTunerGain
);

typedef int
(*DVBS2_DEMOD_FP_GET_ACT_TUNER_RSSI)(
	DVBS2_DEMOD_MODULE *pDemod,
    unsigned int *ActiveTunerRssi
);

typedef int
(*DVBS2_DEMOD_FP_SET_AGC_PARAMS)(
	DVBS2_DEMOD_MODULE *pDemod,
    unsigned int AgcParam,
    unsigned int Index
);

typedef int
(*DVBS2_DEMOD_FP_GET_AGC_PARAMS)(
	DVBS2_DEMOD_MODULE *pDemod,
    unsigned int *AgcParam,
    unsigned int Index
);

typedef int
(*DVBS2_DEMOD_FP_SET_TS_CONFIG)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int IsTsDis,
	unsigned int IsSerial,
	unsigned int IsInv,
	unsigned int IsPacket188
);

typedef int
(*DVBS2_DEMOD_FP_SET_TS_CLK_RATE_MARGIN)(
	DVBS2_DEMOD_MODULE *pDemod,
    unsigned int TsClkMargin
);

typedef int
(*DVBS2_DEMOD_FP_SET_TS_CLK_RATE_MAX)(
	DVBS2_DEMOD_MODULE *pDemod,
    unsigned int TsClkRateMax
);

typedef int
(*DVBS2_DEMOD_FP_GET_DEMOD_LOCK_TIME)(
	DVBS2_DEMOD_MODULE *pDemod,
    unsigned int *DemodLockTimeMs
);

typedef int
(*DVBS2_DEMOD_FP_SET_HW_REG_VAL)(
	unsigned int Addr,
    unsigned int Val
);

typedef int
(*DVBS2_DEMOD_FP_GET_HW_REG_VAL)(
	unsigned int Addr,
    unsigned int *Val
);

typedef int
(*DVBS2_DEMOD_FP_SET_XML_TUNER_CFG_OVERRIDE)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int TunerCfg
);

typedef int
(*DVBS2_DEMOD_FP_SET_XML_TUNER_GAIN_CTRL)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int TunerGainCtrl
);

typedef int
(*DVBS2_DEMOD_FP_SET_XML_FLAGS)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int Flags
);

typedef int
(*DVBS2_DEMOD_FP_SET_XML_IF_FREQ)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int IfFreq
);

typedef int
(*DVBS2_DEMOD_FP_SET_XML_PLFT_CFG_OVERRIDE)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int PlatformCfg
);

typedef int
(*DVBS2_DEMOD_FP_SET_XML_IF_CLK)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int IfClk
);

typedef int
(*DVBS2_DEMOD_FP_SET_XML_LDPC_CLK)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int LdpcClk
);

typedef int
(*DVBS2_DEMOD_FP_SET_XML_UCC_CLK)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int UccClk
);

typedef int
(*DVBS2_DEMOD_FP_SET_XML_MCU_CLK)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int McuClk
);

typedef int
(*DVBS2_DEMOD_FP_SET_VIRTUAL_REGISTER)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int PriRegAddr,
	unsigned int SecRegAddr,
	unsigned int RegVal
);

typedef int
(*DVBS2_DEMOD_FP_GET_VIRTUAL_REGISTER)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int PriRegAddr,
	unsigned int SecRegAddr,
	unsigned int *RegVal
);

typedef int
(*DVBS2_DEMOD_FP_SET_CMD_VIRTUAL_REGISTER)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int PriRegAddr,
	unsigned int SecRegAddr,
	unsigned int RegVal
);
/*
typedef int
(*DVBS2_DEMOD_FP_SET_CTRL_VIRTUAL_REGISTER)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int PriRegAddr,
	unsigned int SecRegAddr,
	unsigned int RegVal
);

typedef int
(*DVBS2_DEMOD_FP_GET_CTRL_VIRTUAL_REGISTER)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int PriRegAddr,
	unsigned int SecRegAddr,
	unsigned int *RegVal
);
*/
// DVBS2 Specific Function Pointer
typedef int
(*DVBS2_DEMOD_FP_SET_BAUD_RATE)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int BaudRate
);

typedef int
(*DVBS2_DEMOD_FP_GET_BAUD_RATE)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *BaudRate
);

typedef int
(*DVBS2_DEMOD_FP_SET_MODULATION)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int Modulation
);

typedef int
(*DVBS2_DEMOD_FP_GET_MODULATION)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *Modulation
);

typedef int
(*DVBS2_DEMOD_FP_SET_CODE_RATE)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int CodeRate
);

typedef int
(*DVBS2_DEMOD_FP_GET_CODE_RATE)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *CodeRate
);

typedef int
(*DVBS2_DEMOD_FP_SET_PILOT_PRESENT)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int PilotPresent
);

typedef int
(*DVBS2_DEMOD_FP_GET_PILOT_PRESENT)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *PilotPresent
);

typedef int
(*DVBS2_DEMOD_FP_SET_ROLLOFF_FACTOR)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int RolloffFactor
);

typedef int
(*DVBS2_DEMOD_FP_GET_ROLLOFF_FACTOR)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *RolloffFactor
);

typedef int
(*DVBS2_DEMOD_FP_GET_ACTIVE_BAUDRATE)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ActiveBaudRate
);

typedef int
(*DVBS2_DEMOD_FP_GET_ACTIVE_MODULATION)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ActiveModulation
);

typedef int
(*DVBS2_DEMOD_FP_GET_ACTIVE_CODERATE)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ActiveCodeRate
);

typedef int
(*DVBS2_DEMOD_FP_GET_ACTIVE_PILOT_PRESENT)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ActivePilotPresent
);

typedef int
(*DVBS2_DEMOD_FP_GET_ACTIVE_ROLLOFF_FACTOR)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ActiveRolloffFactor
);

typedef int
(*DVBS2_DEMOD_FP_GET_LDPC_OUTPUT_FER)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *LdpcOutputFer
);

typedef int
(*DVBS2_DEMOD_FP_GET_BCH_INPUT_BER)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *BchInputBer
);

typedef int
(*DVBS2_DEMOD_FP_GET_BCH_OUTPUT_FER)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *BchOutputFer
);

typedef int
(*DVBS2_DEMOD_FP_GET_SYS_OUTPUT_PER)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *SysOutputPer
);

typedef int
(*DVBS2_DEMOD_FP_SET_BER_AVE_SEC_NUM)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int BerAveSecNum
);

typedef int
(*DVBS2_DEMOD_FP_GET_BER_AVE_SEC_NUM)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *BerAveSecNum
);

typedef int
(*DVBS2_DEMOD_FP_GET_TS_PKT_CNT)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *TsPktCnt
);

typedef int
(*DVBS2_DEMOD_FP_GET_BAD_PKT_CNT)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *BadPktCnt
);

typedef int
(*DVBS2_DEMOD_FP_GET_OUTPUT_BIT_RATE)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *OutputBitRat
);

typedef int
(*DVBS2_DEMOD_FP_GET_SNR)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *Snr
);

typedef int
(*DVBS2_DEMOD_FP_SET_CARRIER_FREQ_SEARCH_RANGE)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int CarrierFreqSearchRange
);

typedef int
(*DVBS2_DEMOD_FP_GET_CARRIER_FREQ_SEARCH_RANGE)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *CarrierFreqSearchRange
);

typedef int
(*DVBS2_DEMOD_FP_SET_SYMBOLRATE_SEARCH_RANGE)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int SymbolRateSearchRange
);

typedef int
(*DVBS2_DEMOD_FP_GET_SYMBOLRATE_SEARCH_RANGE)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *SymbolRateSearchRange
);

typedef int
(*DVBS2_DEMOD_FP_GET_ACQUISITION_STATE)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *AcquisitionState
);

typedef int
(*DVBS2_DEMOD_FP_SET_SIGNAL_ACQUISITION_CNT)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int SignalAcquisitionCnt
);

typedef int
(*DVBS2_DEMOD_FP_GET_SIGNAL_ACQUISITION_CNT)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *SignalAcquisitionCnt
);

typedef int
(*DVBS2_DEMOD_FP_SET_ACQUISITION_FAIL_CODE)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int AcquisitionFailCode
);

typedef int
(*DVBS2_DEMOD_FP_GET_ACQUISITION_FAIL_CODE)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *AcquisitionFailCode
);

typedef int
(*DVBS2_DEMOD_FP_SET_DEMOD_ERROR_CODE)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int DemodErrorCode
);

typedef int
(*DVBS2_DEMOD_FP_GET_DEMOD_ERROR_CODE)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *DemodErrorCode
);

typedef int
(*DVBS2_DEMOD_FP_GET_AMPLITUDE_I)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *AmplitudeI
);

typedef int
(*DVBS2_DEMOD_FP_GET_AMPLITUDE_Q)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *AmplitudeQ
);

typedef int
(*DVBS2_DEMOD_FP_GET_ANALOG_GAIN)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *AnalogGain
);

typedef int
(*DVBS2_DEMOD_FP_GET_DIGITAL_GAIN)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *DigitalGainI,
	unsigned int *DigitalGainQ
);

typedef int
(*DVBS2_DEMOD_FP_GET_ACQUISITION_TIME)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *AcquisitionTime
);

typedef int
(*DVBS2_DEMOD_FP_GET_CARRIER_FREQ_OFFSET)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *CarrierFreqOffset
);

typedef int
(*DVBS2_DEMOD_FP_SET_PHY_CTRL)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int ReAcqResetMetricsEn,
	unsigned int CoeffsCtrlMode
);

typedef int
(*DVBS2_DEMOD_FP_GET_PHY_CTRL)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ReAcqResetMetricsEn,
	unsigned int *CoeffsCtrlMode
);

typedef int
(*DVBS2_DEMOD_FP_SET_MANUAL_DFE_COEFF0)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int ManualCoeffReal0,
	unsigned int ManualCoeffImg0
);

typedef int
(*DVBS2_DEMOD_FP_GET_MANUAL_DFE_COEFF0)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ManualCoeffReal0,
	unsigned int *ManualCoeffImg0
);

typedef int
(*DVBS2_DEMOD_FP_SET_SPECTRUM_INVERSION)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int SpectrumInversion
);

typedef int
(*DVBS2_DEMOD_FP_GET_SPECTRUM_INVERSION)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *SpectrumInversion
);

typedef int
(*DVBS2_DEMOD_FP_GET_ACTIVE_SPECTRUM_INVERSION)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ActiveSpectrumInversion
);

/*
typedef int
(*DVBS2_DEMOD_FP_SET_SYSTEM_CLOCK_INFO)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int LdpcClockFreq,
	unsigned int MetaClockFreq
);
*/

typedef int
(*DVBS2_DEMOD_FP_SET_TONE_DETECTION_CTRL)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int ToneDetEn,
	unsigned int ToneDetPsdEn,
	unsigned int ToneDetPeriod,
	unsigned int ToneDetTh
);

typedef int
(*DVBS2_DEMOD_FP_GET_TONE_DETECTION_VALUE)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ToneDetChange,
	unsigned int *ToneDetPeakIdx,
	unsigned int *ToneDetPeakRatio
);

typedef int
(*DVBS2_DEMOD_FP_SET_DFE_PHASE_TRACKER_STATE)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int DfePhaseTrackMode,
	unsigned int DfePhaseTrackGain,
	unsigned int DfePhaseTrackErr
);

typedef int
(*DVBS2_DEMOD_FP_GET_DFE_PHASE_TRACKER_STATE)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *DfePhaseTrackMode,
	unsigned int *DfePhaseTrackGain,
	unsigned int *DfePhaseTrackErr
);

typedef int
(*DVBS2_DEMOD_FP_GET_DFE_PHASE_TRACKER_OVERRIDE_CTRL)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *DfePhaseTrackGain,
	unsigned int *DfePhaseTrackCoreClipLvl,
	unsigned int *CoreLvl,
	unsigned int *ClipLvl,
	unsigned int *DfePhaseTrackGainNegShift
);

typedef int
(*DVBS2_DEMOD_FP_SET_TUNED_FREQ_OFFSET)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int TunedFreqOffset
);

typedef int
(*DVBS2_DEMOD_FP_GET_TUNED_FREQ_OFFSET)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *TunedFreqOffset
);

typedef int
(*DVBS2_DEMOD_FP_SET_TUNER_FREQ_REQUEST)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int TunedFreqReq
);

typedef int
(*DVBS2_DEMOD_FP_GET_TUNER_FREQ_REQUEST)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *TunedFreqReq
);

typedef int
(*DVBS2_DEMOD_FP_SET_TUNER_BANDWIDTH_REQUEST)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int TunedFreqReq
);

typedef int
(*DVBS2_DEMOD_FP_GET_TUNER_BANDWIDTH_REQUEST)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *TunedFreqReq
);

typedef int
(*DVBS2_DEMOD_FP_GET_IF_AGC_GAIN)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *IfAgcGain
);

typedef int
(*DVBS2_DEMOD_FP_DVBS_SET_CODERATE)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int DemodCodeRate
);

typedef int
(*DVBS2_DEMOD_FP_DVBS_SET_SPEC_INV)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int SpectrumInversion
);

typedef int
(*DVBS2_DEMOD_FP_DVBS_GET_ACTIVE_BAUDRATE)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ActiveBaudRate
);

typedef int
(*DVBS2_DEMOD_FP_DVBS_GET_ACTIVE_CODERATE)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ActiveCodeRate
);

typedef int
(*DVBS2_DEMOD_FP_DVBS_GET_ACTIVE_SPEC_INV)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ActiveSpectrumInversion
);

typedef int
(*DVBS2_DEMOD_FP_DVBS_GET_CARRIER_FREQ_OFFSET)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *CarrierFreqOffset
);

typedef int
(*DVBS2_DEMOD_FP_DVBS_SET_NUM_SEC_BER_AVG)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int NumSecBerAvg
);

typedef int
(*DVBS2_DEMOD_FP_DVBS_SET_TUNED_FREQ_OFFSET)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int TunedFreqOffset
);

typedef int
(*DVBS2_DEMOD_FP_DVBS_GET_ACQUISITION_TIME)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *AcquisitionTime
);

typedef int
(*SA_DEMOD_FE_SET_SCAN_RANGE)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int ScanRange
);

typedef int
(*SA_DEMOD_FE_GET_SCAN_RANGE)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ScanRange
);

typedef int
(*SA_DEMOD_FE_SET_SCAN_RESOLUTION)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int ScanResolution
);

typedef int
(*SA_DEMOD_FE_GET_SCAN_RANGE)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ScanResolution
);

typedef int
(*SA_DEMOD_FE_SET_TUNING_STEP)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int TuningStepAuto,
	unsigned int TuningStep
);

typedef int
(*SA_DEMOD_FE_GET_TUNING_STEP)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *TuningStepAuto,
	unsigned int *TuningStep
);

typedef int
(*SA_DEMOD_FE_SET_MEASURE_CTRL)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int EnDcComp,
	unsigned int Window,
	unsigned int SignalType,
	unsigned int MaxPickWidth
);

typedef int
(*SA_DEMOD_FE_GET_MEASURE_CTRL)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *EnDcComp,
	unsigned int *Window,
	unsigned int *SignalType,
	unsigned int *MaxPickWidth
);

typedef int
(*SA_DEMOD_FE_SET_AVERAGE_PERIOD)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int AveragePeriodM,
	unsigned int AveragePeriodN
);

typedef int
(*SA_DEMOD_FE_GET_AVERAGE_PERIOD)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *AveragePeriodM,
	unsigned int *AveragePeriodN
);

typedef int
(*SA_DEMOD_FE_SET_IF_GAIN_OVERRIDE)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int OverrideIfGain,
	unsigned int IfGain
);

typedef int
(*SA_DEMOD_FE_GET_IF_GAIN_OVERRIDE)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *OverrideIfGain,
	unsigned int *IfGain
);

typedef int
(*SA_DEMOD_FE_SET_TUNER_3DB_POINT)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int FreqSpacing
);

typedef int
(*SA_DEMOD_FE_SET_TUNER_6DB_POINT)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int FreqSpacing
);

typedef int
(*SA_DEMOD_FE_SET_TUNER_9DB_POINT)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int FreqSpacing
);

typedef int
(*SA_DEMOD_FE_SET_TUNER_12DB_POINT)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int FreqSpacing
);

typedef int
(*SA_DEMOD_FE_GET_OUT_SPECTRUM_PTR)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *OutSpecMemType,
	unsigned int *SpecMemPtr
);

typedef int
(*SA_DEMOD_FE_GET_OUT_SPECTRUM_LEN)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *OutSpecLen
);

typedef int
(*SA_DEMOD_FE_GET_MAX_RSSI)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *MaxRssi,
	unsigned int *MaxRssiIdx
);

typedef int
(*SA_DEMOD_FE_GET_REF_IF_GAIN)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *RefIfGain
);


typedef int
(*SA_DEMOD_FE_GET_MAX_PWR)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int Number,
	unsigned int *MaxPwrDb,
	unsigned int *MaxPwrindex
);

typedef int
(*SA_DEMOD_FE_GET_FAILURE_CODE)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *OutOfMem
);

typedef int
(*SA_DEMOD_FE_GET_COMPLETTION_PERCENT)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *CompPercent
);

typedef int
(*SM_DEMOD_FE_PROCESS_SPECTRUM)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int StartFreq,
	unsigned int *CandidatesFound
);

typedef int
(*SM_DEMOD_FE_GET_CANDIDATE_CHANNELS)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int CandidatesIdx,
	unsigned int *Freq,
	unsigned int *Sr
);

typedef int
(*SM_DEMOD_FE_SETUP_SPECAN)(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int StartFreq,
	unsigned int EndFreq
);

typedef int
(*SM_DEMOD_FE_RUN_DVBS)(
	DVBS2_DEMOD_MODULE *pDemod
);

typedef int
(*SM_DEMOD_FE_RUN_DVBS2)(
	DVBS2_DEMOD_MODULE *pDemod
);

//DiSEqC
typedef int
(*DVBS2_DEMOD_FP_SET_DISEQC_CONT_22K_ON_OFF)(
    unsigned int Diseqc22kOnOff
);

typedef int
(*DVBS2_DEMOD_FP_SET_DISEQC_CMD)(
    unsigned int DataLength,
    unsigned char *Data
);

typedef int
(*DVBS2_DEMOD_FP_SET_DISEQC_TONE_BURST)(
    DISEQC_TONE_MODE mode
);

typedef int
(*DVBS2_DEMOD_FP_SET_DISEQC_UN_MOD_TONE_BURST)(
    void
);

typedef int
(*DVBS2_DEMOD_FP_SET_DISEQC_MOD_TONE_BURST)(
    void
);

// DVBS2 Demod Default I2C Functions for 8-bit Address
int
dvbs2_demod_addr_8bit_default_SetRegPage(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned long PageNo
);

int
dvbs2_demod_addr_8bit_default_SetRegBytes(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	const unsigned char *pWritingBytes,
	unsigned long ByteNum
);

int
dvbs2_demod_addr_8bit_default_GetRegBytes(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char *pReadingBytes,
	unsigned long ByteNum
);

int
dvbs2_demod_addr_8bit_default_SetRegMaskBits(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	const unsigned long WritingValue
);

int
dvbs2_demod_addr_8bit_default_GetRegMaskBits(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	unsigned long *pReadingValue
);

int
dvbs2_demod_addr_8bit_default_SetRegBits(
	DVBS2_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

int
dvbs2_demod_addr_8bit_default_GetRegBits(
	DVBS2_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

int
dvbs2_demod_addr_8bit_default_SetRegBitsWithPage(
	DVBS2_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

int
dvbs2_demod_addr_8bit_default_GetRegBitsWithPage(
	DVBS2_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

// DVBS2 Demod Default I2C Functions for 16-bit Address
int
dvbs2_demod_addr_16bit_default_SetRegBytes(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	const unsigned char *pWritingBytes,
	unsigned long ByteNum
);

int
dvbs2_demod_addr_16bit_default_GetRegBytes(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char *pReadingBytes,
	unsigned long ByteNum
);

int
dvbs2_demod_addr_16bit_default_SetRegMaskBits(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	const unsigned long WritingValue
);

int
dvbs2_demod_addr_16bit_default_GetRegMaskBits(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	unsigned long *pReadingValue
);

int
dvbs2_demod_addr_16bit_default_SetRegBits(
	DVBS2_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

int
dvbs2_demod_addr_16bit_default_GetRegBits(
	DVBS2_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

// DVBS2 Demod Default Manipulating Functions
void
dvbs2_demod_default_GetDemodType(
	DVBS2_DEMOD_MODULE *pDemod,
	int *pDemodType
);

void
dvbs2_demod_default_GetDeviceAddr(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned char *pDeviceAddr
);

void
dvbs2_demod_default_GetCrystalFreqHz(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned long *pCrystalFreqHz
);

// Demod Common Function
int
realtek_i_dvbs2_common_CheckRpuReady(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *IsRpuReady
);

int
realtek_i_dvbs2_common_PingRpu(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *IsLive
);

int
realtek_i_dvbs2_common_ShutDown(
	DVBS2_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbs2_common_ActivateCore(
	DVBS2_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbs2_common_DeactivateCore(
	DVBS2_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbs2_common_SwitchToBuffer(
	DVBS2_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbs2_common_GetDemodInfo(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *DemodType
);

int
realtek_i_dvbs2_common_GetBuildId(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *BuildId
);

int
realtek_i_dvbs2_common_DemodCtrlStopCmd(
	DVBS2_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbs2_common_DemodCtrlDetectCmd(
	DVBS2_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbs2_common_DemodCtrlRunCmd(
	DVBS2_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbs2_common_DemodCtrlUpdateRssiCmd(
	DVBS2_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbs2_common_DemodCtrlResetCountersCmd(
	DVBS2_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbs2_common_DemodCtrlUpdateCountersCmd(
	DVBS2_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbs2_common_DemodCtrlSetAgcCmd(
	DVBS2_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbs2_common_DemodCtrlUpdateAgcCmd(
	DVBS2_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbs2_common_DemodCtrlQueryStatusCmd(
	DVBS2_DEMOD_MODULE *pDemod
);

int
realtek_i_dvbs2_common_GetDemodStatus(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *DemodStatus
);

int
realtek_i_dvbs2_common_SetTunerFreqCmd(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int TunerFreqHz
);

int
realtek_i_dvbs2_common_SetTunerBandwidth(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int TunerBandwidthHz
);

int
realtek_i_dvbs2_common_SetTunerGridBase(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int TunerGridBaseHz
);

int
realtek_i_dvbs2_common_SetTunerGridIncr(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int TunerGridIncrHz
);

int
realtek_i_dvbs2_common_SetNotchFreqCmd(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int NotchFreqHz
);

int
realtek_i_dvbs2_common_SetNotchBandwidth(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int NotchBandwidth
);

int
realtek_i_dvbs2_common_GetActiveTunerFreq(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ActiveFreqHz
);

int
realtek_i_dvbs2_common_GetActiveTunerBandwidth(
	DVBS2_DEMOD_MODULE *pDemod,
    unsigned int *ActiveBandwidth
);

int
realtek_i_dvbs2_common_GetActiveTunerGain(
	DVBS2_DEMOD_MODULE *pDemod,
    unsigned int *ActiveTunerGain
);

int
realtek_i_dvbs2_common_GetActiveTunerRssi(
	DVBS2_DEMOD_MODULE *pDemod,
    unsigned int *ActiveTunerRssi
);

int
realtek_i_dvbs2_common_SetAgcParams(
	DVBS2_DEMOD_MODULE *pDemod,
    unsigned int AgcParam,
    unsigned int Index
);

int
realtek_i_dvbs2_common_GetAgcParams(
	DVBS2_DEMOD_MODULE *pDemod,
    unsigned int *AgcParam,
    unsigned int Index
);

int
realtek_i_dvbs2_common_SetTsConfig(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int IsTsDis,
	unsigned int IsSerial,
	unsigned int IsInv,
	unsigned int IsPacket188
);

int
realtek_i_dvbs2_common_SetTsClkRateMargin(
	DVBS2_DEMOD_MODULE *pDemod,
    unsigned int TsClkMargin
);

int
realtek_i_dvbs2_common_SetTsClkRateMax(
	DVBS2_DEMOD_MODULE *pDemod,
    unsigned int TsClkRateMax
);

int
realtek_i_dvbs2_common_GetDemodLockTime(
	DVBS2_DEMOD_MODULE *pDemod,
    unsigned int *DemodLockTimeMs
);

int
realtek_i_dvbs2_common_SetHwRegValue(
	unsigned int Addr,
    unsigned int Val
);

int
realtek_i_dvbs2_common_GetHwRegValue(
	unsigned int Addr,
    unsigned int *Val
);

int
realtek_i_dvbs2_common_SetXmlTunerCfgOverride(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int TunerCfg
);

int
realtek_i_dvbs2_common_SetXmlTunerGainCtrl(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int TunerGainCtrl
);

int
realtek_i_dvbs2_common_SetXmlFlags(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int Flags
);

int
realtek_i_dvbs2_common_SetXmlIfFreq(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int IfFreq
);

int
realtek_i_dvbs2_common_SetXmlPlatformCfgOverride(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int PlatformCfg
);

int
realtek_i_dvbs2_common_SetXmlIfClk(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int IfClk
);

int
realtek_i_dvbs2_common_SetXmlLdpcClk(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int LdpcClk
);

int
realtek_i_dvbs2_common_SetXmlUccClk(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int UccClk
);

int
realtek_i_dvbs2_common_SetXmlMcuClk(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int McuClk
);

int
realtek_i_dvbs2_common_SetVirtualRegister(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int PriRegAddr,
	unsigned int SecRegAddr,
	unsigned int RegVal
);

int
realtek_i_dvbs2_common_GetVirtualRegister(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int PriRegAddr,
	unsigned int SecRegAddr,
	unsigned int *RegVal
);

int
realtek_i_dvbs2_common_SetCmdVirtualRegister(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int PriRegAddr,
	unsigned int SecRegAddr,
	unsigned int RegVal
);
/*
int
realtek_i_dvbs2_common_SetCtrlVirtualRegister(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int PriRegAddr,
	unsigned int SecRegAddr,
	unsigned int RegVal
);

int
realtek_i_dvbs2_common_GetCtrlVirtualRegister(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int PriRegAddr,
	unsigned int SecRegAddr,
	unsigned int *RegVal
);
*/
// DVBS2 Demod Module Structure
struct DVBS2_DEMOD_MODULE_TAG {
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
		DVBS2_DEMOD_REG_ACCESS_ADDR_8BIT  Addr8Bit;
		DVBS2_DEMOD_REG_ACCESS_ADDR_16BIT Addr16Bit;
	}
	RegAccess;

	// Demod Manipulating Function Pointers
	DVBS2_DEMOD_FP_GET_DEMOD_TYPE                GetDemodType;
	DVBS2_DEMOD_FP_GET_DEVICE_ADDR               GetDeviceAddr;
	DVBS2_DEMOD_FP_GET_CRYSTAL_FREQ_HZ           GetCrystalFreqHz;

    // Common TV Api
    DVBS2_DEMOD_FP_CHECK_RPU_READY               CheckRpuReady;
    DVBS2_DEMOD_FP_PING_RPU                      PingRpu;
    DVBS2_DEMOD_FP_SHUT_DOWN                     ShutDown;
    DVBS2_DEMOD_FP_ACTIVATE_CORE                 ActivateCore;
    DVBS2_DEMOD_FP_DEACTIVATE_CORE               DeactivateCore;
    DVBS2_DEMOD_FP_SWITCH_TO_BUFFER		SwitchToBuffer;
    
    DVBS2_DEMOD_FP_GET_DEMOD_INFO                GetDemodInfo;
    DVBS2_DEMOD_FP_GET_BUILD_ID                  GetBuildId;
    DVBS2_DEMOD_FP_DEMOD_CTRL_STOP               DemodCtrlStop;
    DVBS2_DEMOD_FP_DEMOD_CTRL_DETECT             DemodCtrlDetect;
    DVBS2_DEMOD_FP_DEMOD_CTRL_RUN                DemodCtrlRun;
    DVBS2_DEMOD_FP_DEMOD_CTRL_UPDATE_RSSI        DemodCtrlUpdateRssi;
    DVBS2_DEMOD_FP_DEMOD_CTRL_RESET_COUNTERS     DemodCtrlResetCounters;
    DVBS2_DEMOD_FP_DEMOD_CTRL_UPDATE_COUNTERS    DemodCtrlUpdateCounters;
    DVBS2_DEMOD_FP_DEMOD_CTRL_SET_AGC            DemodCtrlSetAgc;
    DVBS2_DEMOD_FP_DEMOD_CTRL_UPDATE_AGC         DemodCtrlUpdateAgc;
    DVBS2_DEMOD_FP_DEMOD_CTRL_QUERY_STATUS       DemodCtrlQueryStatus;
    DVBS2_DEMOD_FP_GET_DEMOD_STATUS              GetDemodStatus;

    DVBS2_DEMOD_FP_SET_TUNER_FREQ                SetTunerFreq;
    DVBS2_DEMOD_FP_SET_TUNER_BANDWIDTH           SetTunerBandwidth;
    DVBS2_DEMOD_FP_SET_TUNER_GRID_BASE           SetTunerGridBase;
    DVBS2_DEMOD_FP_SET_TUNER_GRID_INCR           SetTunerGridIncr;
    DVBS2_DEMOD_FP_SET_NOTCH_FREQ                SetNotchFreq;
    DVBS2_DEMOD_FP_SET_NOTCH_BANDWIDTH           SetNotchBandwidth;
    DVBS2_DEMOD_FP_GET_ACT_TUNER_FREQ            GetActiveTunerFreq;
    DVBS2_DEMOD_FP_GET_ACT_TUNER_BANDWIDTH       GetActiveTunerBandwidth;
    DVBS2_DEMOD_FP_GET_ACT_TUNER_GAIN            GetActiveTunerGain;
    DVBS2_DEMOD_FP_GET_ACT_TUNER_RSSI            GetActiveTunerRssi;
    DVBS2_DEMOD_FP_SET_AGC_PARAMS                SetAgcParams;
    DVBS2_DEMOD_FP_GET_AGC_PARAMS                GetAgcParams;
    DVBS2_DEMOD_FP_SET_TS_CONFIG                 SetTsConfig;
    DVBS2_DEMOD_FP_SET_TS_CLK_RATE_MARGIN        SetTsClkRateMargin;
    DVBS2_DEMOD_FP_SET_TS_CLK_RATE_MAX           SetTsClkRateMax;
    DVBS2_DEMOD_FP_GET_DEMOD_LOCK_TIME           GetDemodLockTime;

    DVBS2_DEMOD_FP_SET_HW_REG_VAL                SetHwRegValue;
    DVBS2_DEMOD_FP_GET_HW_REG_VAL                GetHwRegValue;

    DVBS2_DEMOD_FP_SET_XML_TUNER_CFG_OVERRIDE    SetXmlTunerCfgOverride;
    DVBS2_DEMOD_FP_SET_XML_TUNER_GAIN_CTRL       SetXmlTunerGainCtrl;
    DVBS2_DEMOD_FP_SET_XML_FLAGS                 SetXmlFlags;
    DVBS2_DEMOD_FP_SET_XML_IF_FREQ               SetXmlIfFreq;
    DVBS2_DEMOD_FP_SET_XML_PLFT_CFG_OVERRIDE     SetXmlPlftCfgOverride;
    DVBS2_DEMOD_FP_SET_XML_IF_CLK                SetXmlIfClk;
    DVBS2_DEMOD_FP_SET_XML_LDPC_CLK              SetXmlLdpcClk;
    DVBS2_DEMOD_FP_SET_XML_UCC_CLK               SetXmlUccClk;
    DVBS2_DEMOD_FP_SET_XML_MCU_CLK               SetXmlMcuClk;

    DVBS2_DEMOD_FP_SET_VIRTUAL_REGISTER          SetVirtualRegister;
    DVBS2_DEMOD_FP_GET_VIRTUAL_REGISTER          GetVirtualRegister;
    DVBS2_DEMOD_FP_SET_CMD_VIRTUAL_REGISTER      SetCmdVirtualRegister;
    //DVBS2_DEMOD_FP_SET_CTRL_VIRTUAL_REGISTER     SetCtrlVirtualRegister;
    //DVBS2_DEMOD_FP_GET_CTRL_VIRTUAL_REGISTER     GetCtrlVirtualRegister;

    // DVBS2 Specific Api
    DVBS2_DEMOD_FP_SET_BAUD_RATE                        SetBaudRate;
    DVBS2_DEMOD_FP_GET_BAUD_RATE                        GetBaudRate;
    DVBS2_DEMOD_FP_SET_MODULATION                       SetModulation;
    DVBS2_DEMOD_FP_GET_MODULATION                       GetModulation;
    DVBS2_DEMOD_FP_SET_CODE_RATE                        SetCodeRate;
    DVBS2_DEMOD_FP_GET_CODE_RATE                        GetCodeRate;
    DVBS2_DEMOD_FP_SET_PILOT_PRESENT                    SetPilotPresent;
    DVBS2_DEMOD_FP_GET_PILOT_PRESENT                    GetPilotPresent;
    DVBS2_DEMOD_FP_SET_ROLLOFF_FACTOR                   SetRolloffFactor;
    DVBS2_DEMOD_FP_GET_ROLLOFF_FACTOR                   GetRolloffFactor;
    DVBS2_DEMOD_FP_GET_ACTIVE_BAUDRATE                  GetActiveBaudRate;
    DVBS2_DEMOD_FP_GET_ACTIVE_MODULATION                GetActiveModulation;
    DVBS2_DEMOD_FP_GET_ACTIVE_CODERATE                  GetActiveCodeRate;
    DVBS2_DEMOD_FP_GET_ACTIVE_PILOT_PRESENT             GetActivePilotPresent;
    DVBS2_DEMOD_FP_GET_ACTIVE_ROLLOFF_FACTOR            GetActiveRolloffFactor;
    DVBS2_DEMOD_FP_GET_LDPC_OUTPUT_FER                  GetLdpcOutputFer;
    DVBS2_DEMOD_FP_GET_BCH_INPUT_BER                    GetBchInputBer;
    DVBS2_DEMOD_FP_GET_BCH_OUTPUT_FER                   GetBchOutputFer;
    DVBS2_DEMOD_FP_GET_SYS_OUTPUT_PER                   GetSysOutputPer;
    DVBS2_DEMOD_FP_SET_BER_AVE_SEC_NUM                  SetBerAveSecNum;
    DVBS2_DEMOD_FP_GET_BER_AVE_SEC_NUM                  GetBerAveSecNum;
    DVBS2_DEMOD_FP_GET_TS_PKT_CNT                       GetTsPktCnt;
    DVBS2_DEMOD_FP_GET_BAD_PKT_CNT                      GetBadPktCnt;
    DVBS2_DEMOD_FP_GET_OUTPUT_BIT_RATE                  GetOutputBitRate;
    DVBS2_DEMOD_FP_GET_SNR                              GetSnr;
    DVBS2_DEMOD_FP_SET_CARRIER_FREQ_SEARCH_RANGE        SetCarrierFreqSearchRange;
    DVBS2_DEMOD_FP_GET_CARRIER_FREQ_SEARCH_RANGE        GetCarrierFreqSearchRange;
    DVBS2_DEMOD_FP_SET_SYMBOLRATE_SEARCH_RANGE          SetSymbolRateSearchRange;
    DVBS2_DEMOD_FP_GET_SYMBOLRATE_SEARCH_RANGE          GetSymbolRateSearchRange;
    DVBS2_DEMOD_FP_GET_ACQUISITION_STATE                GetAcquisitionState;
    DVBS2_DEMOD_FP_SET_SIGNAL_ACQUISITION_CNT           SetSignalAcquisitionCnt;
    DVBS2_DEMOD_FP_GET_SIGNAL_ACQUISITION_CNT           GetSignalAcquisitionCnt;
    DVBS2_DEMOD_FP_SET_ACQUISITION_FAIL_CODE            SetAcquisitionFailCode;
    DVBS2_DEMOD_FP_GET_ACQUISITION_FAIL_CODE            GetAcquisitionFailCode;
    DVBS2_DEMOD_FP_SET_DEMOD_ERROR_CODE                 SetDemodErrorCode;
    DVBS2_DEMOD_FP_GET_DEMOD_ERROR_CODE                 GetDemodErrorCode;
    DVBS2_DEMOD_FP_GET_AMPLITUDE_I                      GetAmplitudeI;
    DVBS2_DEMOD_FP_GET_AMPLITUDE_Q                      GetAmplitudeQ;
    DVBS2_DEMOD_FP_GET_ANALOG_GAIN                      GetAnalogGain;
    DVBS2_DEMOD_FP_GET_DIGITAL_GAIN                     GetDigitalGain;
    DVBS2_DEMOD_FP_GET_ACQUISITION_TIME                 GetAcquisitionTime;
    DVBS2_DEMOD_FP_GET_CARRIER_FREQ_OFFSET              GetCarrierFreqOffset;
    DVBS2_DEMOD_FP_SET_PHY_CTRL                         SetPhyCtrl;
    DVBS2_DEMOD_FP_GET_PHY_CTRL                         GetPhyCtrl;
    DVBS2_DEMOD_FP_SET_MANUAL_DFE_COEFF0                SetManualDfeCoeff0;
    DVBS2_DEMOD_FP_GET_MANUAL_DFE_COEFF0                GetManualDfeCoeff0;
    DVBS2_DEMOD_FP_SET_SPECTRUM_INVERSION               SetSpectrumInversion;
    DVBS2_DEMOD_FP_GET_SPECTRUM_INVERSION               GetSpectrumInversion;
    DVBS2_DEMOD_FP_GET_ACTIVE_SPECTRUM_INVERSION        GetActiveSpectrumInversion;
    //DVBS2_DEMOD_FP_SET_SYSTEM_CLOCK_INFO                SetSystemClockInfo;
    DVBS2_DEMOD_FP_SET_TONE_DETECTION_CTRL              SetToneDetectionCtrl;
    DVBS2_DEMOD_FP_GET_TONE_DETECTION_VALUE             GetToneDetectionValue;
    DVBS2_DEMOD_FP_SET_DFE_PHASE_TRACKER_STATE          SetDfePhaseTrackerState;
    DVBS2_DEMOD_FP_GET_DFE_PHASE_TRACKER_STATE          GetDfePhaseTrackerState;
    DVBS2_DEMOD_FP_GET_DFE_PHASE_TRACKER_OVERRIDE_CTRL  GetDfePhaseTrackerOverrideCtrl;
    DVBS2_DEMOD_FP_SET_TUNED_FREQ_OFFSET                SetTunedFreqOffset;
    DVBS2_DEMOD_FP_GET_TUNED_FREQ_OFFSET                GetTunedFreqOffset;
    DVBS2_DEMOD_FP_SET_TUNER_FREQ_REQUEST               SetTunerFreqRequest;
    DVBS2_DEMOD_FP_GET_TUNER_FREQ_REQUEST               GetTunerFreqRequest;
    DVBS2_DEMOD_FP_SET_TUNER_BANDWIDTH_REQUEST          SetTunerBandwidthRequest;
    DVBS2_DEMOD_FP_GET_TUNER_BANDWIDTH_REQUEST          GetTunerBandwidthRequest;
    DVBS2_DEMOD_FP_GET_IF_AGC_GAIN                      GetIfAgcGain;

    DVBS2_DEMOD_FP_DVBS_SET_CODERATE                    DvbSSetCodeRate;
    DVBS2_DEMOD_FP_DVBS_SET_SPEC_INV                    DvbSSetSpectrumInversion;
    DVBS2_DEMOD_FP_DVBS_GET_ACTIVE_BAUDRATE             DvbSGetActiveBaudRate;
    DVBS2_DEMOD_FP_DVBS_GET_ACTIVE_CODERATE             DvbSGetActiveCodeRate;
    DVBS2_DEMOD_FP_DVBS_GET_ACTIVE_SPEC_INV             DvbSGetActiveSpectrumInversion;
    DVBS2_DEMOD_FP_DVBS_GET_CARRIER_FREQ_OFFSET         DvbSGetCarrierFreqOffset;
    DVBS2_DEMOD_FP_DVBS_SET_NUM_SEC_BER_AVG             DvbSSetNumSecBerAvg;
    DVBS2_DEMOD_FP_DVBS_SET_TUNED_FREQ_OFFSET           DvbSSetTunedFreqOffset;
    DVBS2_DEMOD_FP_DVBS_GET_ACQUISITION_TIME            DvbSGetAcquisitionTime;

    DVBS2_DEMOD_FP_SET_DISEQC_CONT_22K_ON_OFF           SetDiseqcContinue22kOnOff;
    DVBS2_DEMOD_FP_SET_DISEQC_CMD                       SetDiseqcCmd;
    DVBS2_DEMOD_FP_SET_DISEQC_TONE_BURST                SetDiseqcToneBurst;
    DVBS2_DEMOD_FP_SET_DISEQC_UN_MOD_TONE_BURST         SetDiseqcUnModToneBurst;
    DVBS2_DEMOD_FP_SET_DISEQC_MOD_TONE_BURST            SetDiseqcModToneBurst;

    SA_DEMOD_FE_SET_SCAN_RANGE                          DvbS2SetSpecAnScanRange;
    SA_DEMOD_FE_GET_SCAN_RANGE                          DvbS2GetSpecAnScanRange;
    SA_DEMOD_FE_SET_SCAN_RESOLUTION                     DvbS2SetSpecAnScanResolution;
    SA_DEMOD_FE_GET_SCAN_RANGE                          DvbS2GetSpecAnScanResolution;
    SA_DEMOD_FE_SET_TUNING_STEP                         DvbS2SetSpecAnTuningStep;
    SA_DEMOD_FE_GET_TUNING_STEP                         DvbS2GetSpecAnTuningStep;
    SA_DEMOD_FE_SET_MEASURE_CTRL                        DvbS2SetSpecAnMeasureCtrl;
    SA_DEMOD_FE_GET_MEASURE_CTRL                        DvbS2GetSpecAnMeasureCtrl;
    SA_DEMOD_FE_SET_AVERAGE_PERIOD                      DvbS2SetSpecAnAveragePeriod;
    SA_DEMOD_FE_GET_AVERAGE_PERIOD                      DvbS2GetSpecAnAveragePeriod;
    SA_DEMOD_FE_SET_IF_GAIN_OVERRIDE                    DvbS2SetSpecAnIfGainOverride;
    SA_DEMOD_FE_GET_IF_GAIN_OVERRIDE                    DvbS2GetSpecAnIfGainOverride;
    SA_DEMOD_FE_SET_TUNER_3DB_POINT                     DvbS2SetSpecAnTuner3dBPoint;
    SA_DEMOD_FE_SET_TUNER_6DB_POINT                     DvbS2SetSpecAnTuner6dBPoint;
    SA_DEMOD_FE_SET_TUNER_9DB_POINT                     DvbS2SetSpecAnTuner9dBPoint;
    SA_DEMOD_FE_SET_TUNER_12DB_POINT                    DvbS2SetSpecAnTuner12dBPoint;
    SA_DEMOD_FE_GET_OUT_SPECTRUM_PTR                    DvbS2GetSpecAnOutSpectrumPtr;
    SA_DEMOD_FE_GET_OUT_SPECTRUM_LEN                    DvbS2GetSpecAnOutSpectrumLen;
    SA_DEMOD_FE_GET_MAX_RSSI                            DvbS2GetSpecAnMaxRssi;
    SA_DEMOD_FE_GET_REF_IF_GAIN                         DvbS2GetSpecAnRefIfGain;
    SA_DEMOD_FE_GET_MAX_PWR                             DvbS2GetSpecAnMaxPwr;
    SA_DEMOD_FE_GET_FAILURE_CODE                        DvbS2GetSpecAnFailureCode;
    SA_DEMOD_FE_GET_COMPLETTION_PERCENT                 DvbS2GetSpecAnCompletionPercent;
};

#define REALTEK_I_DVBS2_BASE_PRINT_LVL_DBG      0
#define REALTEK_I_DVBS2_BASE_PRINT_LVL_INFO     1
#define REALTEK_I_DVBS2_BASE_PRINT_LVL_WARNING  2


#ifndef REALTEK_I_DVBS2_BASE_PRINT_LVL
#define REALTEK_I_DVBS2_BASE_PRINT_LVL          REALTEK_I_DVBS2_BASE_PRINT_LVL_INFO
#endif

#define REALTEK_I_DVBS2_BASE_DBG(fmt, args...)        rtd_printk(KERN_DEBUG, "DEMO", "DVBS2_BASE_DEBUG, " fmt, ##args);
#define REALTEK_I_DVBS2_BASE_INFO(fmt, args...)       rtd_printk(KERN_INFO, "DEMO", "DVBS2_BASE_INFO, " fmt, ##args);
#define REALTEK_I_DVBS2_BASE_WARNING(fmt, args...)    rtd_printk(KERN_WARNING, "DEMO", "DVBS2_BASE_WARNING, " fmt, ##args);


#ifdef __cplusplus
}
#endif
#endif
