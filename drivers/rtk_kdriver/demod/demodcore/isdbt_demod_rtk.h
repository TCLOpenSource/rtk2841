#ifndef __ISDBT_DEMOD_REALTEK_I_H
#define __ISDBT_DEMOD_REALTEK_I_H

#include "isdbt_demod_base.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ISDBT_REALTEK_I_DEFAULT_BANDWIDTH 6000000

//Img ISDBT Virtual Register Address/Mask
//#define ISDBT_REG_CTRL                                       0x8000 // Write & Read
    #define ISDBT_BITFLD_CTRL                       0x00000001 
//#define ISDBT_REG_TUN_SUBCHANNEL                             0x8001 // Write & Read
    #define ISDBT_BITFLD_TUN_SUBCHANNEL             0xFFFFFFFF
//#define ISDBT_REG_TUN_PARTIAL_RECEPTION                      0x8002 // Write & Read
    #define ISDBT_BITFLD_TUN_PARTIAL_RECEPTION      0x00000003    
//#define ISDBT_REG_TUN_MODE                                   0x8003 // Write & Read
    #define ISDBT_BITFLD_TUN_MODE                   0x00000007
//#define ISDBT_REG_TUN_GUARD                                  0x8004 // Write & Read
    #define ISDBT_BITFLD_TUN_GUARD                  0x0000000F
//#define ISDBT_REG_TUN_MOD_A                                  0x8005 // Write & Read
    #define ISDBT_BITFLD_TUN_MOD_A                  0x00000007
//#define ISDBT_REG_TUN_CODE_RATE_A                            0x8006 // Write & Read
    #define ISDBT_BITFLD_TUN_CODE_RATE_A            0x00000007
//#define ISDBT_REG_TUN_INTERLEAVER_A                          0x8007 // Write & Read
    #define ISDBT_BITFLD_TUN_INTERLEAVER_A          0x00000007
//#define ISDBT_REG_TUN_SEGS_A                                 0x8008 // Write & Read
    #define ISDBT_BITFLD_TUN_SEGS_A                 0x0000000F
//#define ISDBT_REG_TUN_MOD_B                                  0x8009 // Write & Read
    #define ISDBT_BITFLD_TUN_MOD_B                  0x00000007
//#define ISDBT_REG_TUN_CODE_RATE_B                            0x800A // Write & Read
    #define ISDBT_BITFLD_TUN_CODE_RATE_B            0x00000007
//#define ISDBT_REG_TUN_INTERLEAVER_B                          0x800B // Write & Read
    #define ISDBT_BITFLD_TUN_INTERLEAVER_B          0x00000007
//#define ISDBT_REG_TUN_SEGS_B                                 0x800C // Write & Read
    #define ISDBT_BITFLD_TUN_SEGS_B                 0x0000000F
//#define  ISDBT_REG_TUN_MOD_C                                 0x800D // Write & Read
    #define ISDBT_BITFLD_TUN_MOD_C                  0x00000007
//#define ISDBT_REG_TUN_CODE_RATE_C                            0x800E // Write & Read
    #define ISDBT_BITFLD_TUN_CODE_RATE_C            0x00000007
//#define ISDBT_REG_TUN_INTERLEAVER_C                          0x800F // Write & Read
    #define ISDBT_BITFLD_TUN_INTERLEAVER_C          0x00000007
//#define ISDBT_REG_TUN_SEGS_C                                 0x8010 // Write & Read
    #define ISDBT_BITFLD_TUN_SEGS_C                 0x0000000F
//#define ISDBT_REG_EAF                                        0x8011 // Read only
    #define ISDBT_BITFLD_EAF                        0x00000003
//#define ISDBT_REG_STAT_TS_PKT_COUNT_A                        0x8012 // Read Only
    #define ISDBT_BITFLD_STAT_TS_PKT_COUNT_A        0xFFFFFFFF
//#define ISDBT_REG_STAT_TS_BAD_PKT_COUNT_A                    0x8013 // Read Only
    #define ISDBT_BITFLD_STAT_TS_BAD_PKT_COUNT_A    0xFFFFFFFF
//#define ISDBT_REG_STAT_TS_BYTE_ERRS_A                        0x8014 // Read Only
    #define ISDBT_BITFLD_STAT_TS_BYTE_ERRS_A        0xFFFFFFFF
//#define ISDBT_REG_STAT_TS_BIT_ERRS_A                         0x8015 // Read Only
    #define ISDBT_BITFLD_STAT_TS_BIT_ERRS_A         0xFFFFFFFF
//#define ISDBT_REG_STAT_TS_PKT_COUNT_B                        0x8016 // Read Only
    #define ISDBT_BITFLD_STAT_TS_PKT_COUNT_B        0xFFFFFFFF
//#define ISDBT_REG_STAT_TS_BAD_PKT_COUNT_B                    0x8017 // Read Only
    #define ISDBT_BITFLD_STAT_TS_BAD_PKT_COUNT_B    0xFFFFFFFF
//#define ISDBT_REG_STAT_TS_BYTE_ERRS_B                        0x8018 // Read Only
    #define ISDBT_BITFLD_STAT_TS_BYTE_ERRS_B        0xFFFFFFFF
//#define ISDBT_REG_STAT_TS_BIT_ERRS_B                         0x8019 // Read Only
    #define ISDBT_BITFLD_STAT_TS_BIT_ERRS_B         0xFFFFFFFF
//#define ISDBT_REG_STAT_TS_PKT_COUNT_C                        0x801A // Read Only
    #define ISDBT_BITFLD_STAT_TS_PKT_COUNT_C        0xFFFFFFFF
//#define ISDBT_REG_STAT_TS_BAD_PKT_COUNT_C                    0x801B // Read Only
    #define ISDBT_BITFLD_STAT_TS_BAD_PKT_COUNT_C    0xFFFFFFFF
//#define ISDBT_REG_STAT_TS_BYTE_ERRS_C                        0x801C // Read Only
    #define ISDBT_BITFLD_STAT_TS_BYTE_ERRS_C        0xFFFFFFFF
//#define ISDBT_REG_STAT_TS_BIT_ERRS_C                         0x801D // Read Only
    #define ISDBT_BITFLD_STAT_TS_BIT_ERRS_C         0xFFFFFFFF
//#define ISDBT_REG_STAT_NUM_REACQ                             0x801E // Read Only
    #define ISDBT_BITFLD_STAT_NUM_REACQ             0xFFFFFFFF
//#define ISDBT_REG_STAT_SNR                                   0x801F // Read Only
    #define ISDBT_BITFLD_STAT_SNR                   0xFFFFFFFF
//#define ISDBT_REG_STAT_CARRIER_ACQUISITION_OFFSET            0x8020 // Read Only
    #define ISDBT_BITFLD_STAT_CARRIER_ACQUISITION_OFFSET    0xFFFFFFFF
//#define ISDBT_REG_STAT_CARRIER_TRACKING_OFFSET               0x8021 // Read Only
    #define ISDBT_BITFLD_STAT_CARRIER_TRACKING_OFFSET       0xFFFFFFFF
//#define ISDBT_REG_STAT_IF_AGC_LEVEL                          0x8022 // Read Only
    #define ISDBT_BITFLD_STAT_IF_AGC_LEVEL          0xFFFFFFFF
//#define ISDBT_REG_NUM_SECONDS_BER_AVERAGING                  0x8023 // Write & Read
    #define ISDBT_BITFLD_NUM_SECONDS_BER_AVERAGING  0x0000000F
//#define ISDBT_REG_VITERBI_BER_A                              0x8024 // Read Only
    #define ISDBT_BITFLD_STAT_TS_VITERBI_BER_A      0xFFFFFFFF
//#define ISDBT_REG_RS_BER_A                                   0x8025 // Write & Read
    #define ISDBT_BITFLD_BER_RS_BER_A               0xFFFFFFFF
//#define ISDBT_REG_TS_PER_A                                   0x8026 // Write & Read
    #define ISDBT_BITFLD_BER_TS_PER_A               0xFFFFFFFF
//#define ISDBT_REG_VITERBI_BER_B                              0x8027 // Read Only
    #define ISDBT_BITFLD_STAT_TS_VITERBI_BER_B      0xFFFFFFFF
//#define ISDBT_REG_RS_BER_B                                   0x8028 // Write & Read
    #define ISDBT_BITFLD_BER_RS_BER_B               0xFFFFFFFF
//#define ISDBT_REG_TS_PER_B                                   0x8029 // Write & Read
    #define ISDBT_BITFLD_BER_TS_PER_B               0xFFFFFFFF
//#define ISDBT_REG_VITERBI_BER_C                              0x802A // Read Only
    #define ISDBT_BITFLD_STAT_TS_VITERBI_BER_C      0xFFFFFFFF
//#define ISDBT_REG_RS_BER_C                                   0x802B // Write & Read
    #define ISDBT_BITFLD_BER_RS_BER_C               0xFFFFFFFF
//#define ISDBT_REG_TS_PER_C                                   0x802C // Write & Read
    #define ISDBT_BITFLD_BER_TS_PER_C               0xFFFFFFFF
//#define ISDBT_REG_FAILURE_CODE                  	           0x802D // Read
    #define ISDBT_BITFLD_FAILURE_CODE 	            0xFFFFFFFF
//#define ISDBT_REG_DEMOD_FAILURE_COUNT_PER_TIMEOUT             0x802E // Read
#define ISDBT_BITFLD_DEMOD_FAILURE_COUNT_PER_TIMEOUT 	0xFFFFFFFF
//#define ISDBT_REG_FAILURE_COUNT_OTHER            	           0x802F // Read
#define ISDBT_BITFLD_FAILURE_COUNT_OTHER            0xFFFFFFFF
//#define ISDBT_REG_TMCC_COUNT                                 0x8030 // Read
    #define ISDBT_BITFLD_TMCC_COUNT                 0xFFFFFFFF
//#define ISDBT_REG_TMCC_GOOD_DECODE_COUNT                     0x8031 //Read
#define ISDBT_BITFLD_TMCC_GOOD_DECODE_COUNT             0xFFFFFFFF
//#define ISDBT_REG_TMCC_COUNTS_RESET                          0x8032 //Write & Read
    #define ISDBT_BITFLD_TMCC_COUNTS_RESET          0xFFFFFFFF
//#define ISDBT_REG_CHANNEL_INTERFERER_OFFSET_HZ               0x8033 //Write & Read
    #define ISDBT_BITFLD_CHANNEL_INTERFERER_OFFSET_HZ 0xFFFFFFFF
    
// Builder
void
BuildRealtekIIsdbtModule(
	ISDBT_DEMOD_MODULE **ppDemod,
	ISDBT_DEMOD_MODULE *pIsdbtDemodModuleMemory,
	BASE_INTERFACE_MODULE *pBaseInterfaceModuleMemory,
	I2C_BRIDGE_MODULE *pI2cBridgeModuleMemory,
	unsigned char DeviceAddr,
	unsigned long CrystalFreqHz
);

// Img ISDBT Virtual Register
int
realtek_i_isdbt_SetTunCtrlCmd(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunCtrl
);

int
realtek_i_isdbt_SetTunSubCh(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunSubCh
);

int
realtek_i_isdbt_GetTunSubCh(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunSubCh
);

int
realtek_i_isdbt_SetTunParital(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunParital
);

int
realtek_i_isdbt_GetTunParital(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunParital
);

int
realtek_i_isdbt_SetTunMode(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunMode
);

int
realtek_i_isdbt_GetTunMode(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunMode
);

int
realtek_i_isdbt_SetTunGuard(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunGuard
);

int
realtek_i_isdbt_GetTunGuard(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunGuard
);

int
realtek_i_isdbt_SetTunModeA(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunModeA
);

int
realtek_i_isdbt_GetTunModeA(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunModeA
);

int
realtek_i_isdbt_SetTunCodeRateA(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunCodeRateA
);

int
realtek_i_isdbt_GetTunCodeRateA(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunCodeRateA
);

int
realtek_i_isdbt_SetTunInterleaverA(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunInterleaverA
);

int
realtek_i_isdbt_GetTunInterleaverA(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunInterleaverA
);

int
realtek_i_isdbt_SetTunSegsA(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunSegsA
);

int
realtek_i_isdbt_GetTunSegsA(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunSegsA
);

int
realtek_i_isdbt_SetTunModeB(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunModeB
);

int
realtek_i_isdbt_GetTunModeB(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunModeB
);

int
realtek_i_isdbt_SetTunCodeRateB(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunCodeRateB
);

int
realtek_i_isdbt_GetTunCodeRateB(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunCodeRateB
);

int
realtek_i_isdbt_SetTunInterleaverB(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunInterleaverB
);

int
realtek_i_isdbt_GetTunInterleaverB(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunInterleaverB
);

int
realtek_i_isdbt_SetTunSegsB(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunSegsB
);

int
realtek_i_isdbt_GetTunSegsB(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunSegsB
);

int
realtek_i_isdbt_SetTunModeC(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunModeC
);

int
realtek_i_isdbt_GetTunModeC(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunModeC
);

int
realtek_i_isdbt_SetTunCodeRateC(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunCodeRateC
);

int
realtek_i_isdbt_GetTunCodeRateC(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunCodeRateC
);

int
realtek_i_isdbt_SetTunInterleaverC(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunInterleaverC
);

int
realtek_i_isdbt_GetTunInterleaverC(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunInterleaverC
);

int
realtek_i_isdbt_SetTunSegsC(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int TunSegsC
);

int
realtek_i_isdbt_GetTunSegsC(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *TunSegsC
);

int
realtek_i_isdbt_GetRegEaf(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegEaf
);

int
realtek_i_isdbt_SetRegCalibCtrlCmd(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int RegCalibCtrl
);

int
realtek_i_isdbt_SetRegCalibTss1(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int RegCalibTss1
);

int
realtek_i_isdbt_GetRegCalibTss1(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegCalibTss1
);

int
realtek_i_isdbt_SetRegCalibTss2(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int RegCalibTss2
);

int
realtek_i_isdbt_GetRegCalibTss2(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegCalibTss2
);

int
realtek_i_isdbt_SetRegStatCtrlACmd(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int RegStatCtrlA
);

int
realtek_i_isdbt_SetRegStatCtrlBCmd(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int RegStatCtrlB
);

int
realtek_i_isdbt_SetRegStatCtrlCCmd(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int RegStatCtrlC
);

int
realtek_i_isdbt_GetRegStatTsPktCountA(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatTsPktCountA
);

int
realtek_i_isdbt_GetRegStatTsBadPktCountA(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatTsBadPktCountA
);

int
realtek_i_isdbt_GetRegStatTsByteErrsA(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatTsByteErrsA
);

int
realtek_i_isdbt_GetRegStatTsBitErrsA(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatTsBitErrsA
);

int
realtek_i_isdbt_GetRegStatViterbiBerA(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatViterbiBerA
);

int
realtek_i_isdbt_GetRegStatTsPktCountB(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatTsPktCountB
);

int
realtek_i_isdbt_GetRegStatTsBadPktCountB(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatTsBadPktCountB
);

int
realtek_i_isdbt_GetRegStatTsByteErrsB(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatTsByteErrsB
);

int
realtek_i_isdbt_GetRegStatTsBitErrsB(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatTsBitErrsB
);

int
realtek_i_isdbt_GetRegStatViterbiBerB(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatViterbiBerB
);

int
realtek_i_isdbt_GetRegStatTsPktCountC(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatTsPktCountC
);

int
realtek_i_isdbt_GetRegStatTsBadPktCountC(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatTsBadPktCountC
);

int
realtek_i_isdbt_GetRegStatTsByteErrsC(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatTsByteErrsC
);

int
realtek_i_isdbt_GetRegStatTsBitErrsC(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatTsBitErrsC
);

int
realtek_i_isdbt_GetRegStatViterbiBerC(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatViterbiBerC
);

int
realtek_i_isdbt_GetRegStatTmccSync(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatTmccSync
);

int
realtek_i_isdbt_GetRegStatNumSymbols(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatNumSymbols
);

int
realtek_i_isdbt_GetRegStatNumReaqc(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatNumReaqc
);

int
realtek_i_isdbt_GetRegStatSigPwr(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *GetRegStatSigPwr
);

int
realtek_i_isdbt_GetRegStatSnr(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatSnr
);

int
realtek_i_isdbt_GetRegStatCarrierAcquisitionOffset(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatCarrierOffset
);

int
realtek_i_isdbt_GetRegStatCarrierTrackingOffset(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatCarrierTrackingOffset
);

int
realtek_i_isdbt_GetRegStatIfAgcLevel(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegStatIfAgcLevel
);

int
realtek_i_isdbt_SetRegBerPeriod(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int RegBerPeriod
);

int
realtek_i_isdbt_GetRegBerPeriod(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegBerPeriod
);

int
realtek_i_isdbt_GetRegBerRsBerA(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegBerRsBerA
);

int
realtek_i_isdbt_GetRegBerTsPerA(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegBerTsPerA
);

int
realtek_i_isdbt_GetRegBerRsBerB(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegBerRsBerB
);

int
realtek_i_isdbt_GetRegBerTsPerB(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegBerTsPerB
);

int
realtek_i_isdbt_GetRegBerRsBerC(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegBerRsBerC
);

int
realtek_i_isdbt_GetRegBerTsPerC(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegBerTsPerC
);



int
realtek_i_isdbt_GetDemodFailureCode(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegFailureCode
);

int
realtek_i_isdbt_GetDemodFailureCountPerTimeout(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegFailureCountPerTimeout
);

int
realtek_i_isdbt_GetDemodFailureCountOther(
	ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegFailureCountOther
);

int
realtek_i_isdbt_GetRegTmccGoodDecodeCount(
    ISDBT_DEMOD_MODULE *pDemod,
	unsigned int *RegTmccGoodDecodeCount
);
#ifdef __cplusplus
}
#endif
#endif
