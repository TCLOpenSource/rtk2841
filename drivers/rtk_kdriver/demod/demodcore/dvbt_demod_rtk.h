#ifndef __DVBT_DEMOD_REALTEK_I_H
#define __DVBT_DEMOD_REALTEK_I_H

#include "dvbt_demod_base.h"

#ifdef __cplusplus
extern "C" {
#endif

#define DVBT_REALTEK_I_DEFAULT_BANDWIDTH 8000000

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
BuildRealtekIDvbtModule(
	DVBT_DEMOD_MODULE **ppDemod,
	DVBT_DEMOD_MODULE *pDvbTDemodModuleMemory,
	BASE_INTERFACE_MODULE *pBaseInterfaceModuleMemory,
	I2C_BRIDGE_MODULE *pI2cBridgeModuleMemory,
	unsigned char DeviceAddr,
	unsigned long CrystalFreqHz
);

int
realtek_i_dvbt_SetDetectMask(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int DetectMask
);

int
realtek_i_dvbt_GetDetectMask(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *DetectMask
);

int
realtek_i_dvbt_SetTunFft(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int TunFft
);

int
realtek_i_dvbt_GetTunFft(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *TunFft
);

int
realtek_i_dvbt_SetTunGuard(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int TunGuard
);

int
realtek_i_dvbt_GetTunGuard(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *TunGuard
);

int
realtek_i_dvbt_SetTunMod(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int TunMod
);

int
realtek_i_dvbt_GetTunMod(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *TunMod
);

int
realtek_i_dvbt_SetTunCodeRate(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int TunCodeRate
);

int
realtek_i_dvbt_GetTunCodeRate(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *TunCodeRate
);

int
realtek_i_dvbt_SetTunAlpha(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int TunAlpha
);

int
realtek_i_dvbt_GetTunAlpha(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *TunAlpha
);

int
realtek_i_dvbt_SetTunInterleaver(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int TunInterleaver
);

int
realtek_i_dvbt_GetTunInterleaver(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *TunInterleaver
);

int
realtek_i_dvbt_SetTunHierarchical(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int TunHierarchical
);

int
realtek_i_dvbt_GetTunHierarchical(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *TunHierarchical
);

int
realtek_i_dvbt_SetTunSpectInv(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int TunSpectInv
);

int
realtek_i_dvbt_GetTunSpectInv(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *TunSpectInv
);

int
realtek_i_dvbt_SetCalibCtrlCmd(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int CalibCtrl
);

int
realtek_i_dvbt_SetCalibXtalOffset(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int CalibXtalOffset
);

int
realtek_i_dvbt_GetCalibXtalOffset(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *CalibXtalOffset
);

int
realtek_i_dvbt_SetStatCtrlCmd(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int StatCtrl
);

int
realtek_i_dvbt_GetStatUpdata(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *StatUpdata
);

int
realtek_i_dvbt_GetStatSsi(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *StatSsi
);

int
realtek_i_dvbt_GetStatSnr(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *StatSnr
);

int
realtek_i_dvbt_GetStatCarrierOffset(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *StatCarrierOffset
);

int
realtek_i_dvbt_GetStatTsPktCount(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *StatTsPktCount
);

int
realtek_i_dvbt_GetStatTsBadPktCount(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *StatTsBadPktCount
);

int
realtek_i_dvbt_GetStatTsByteErrs(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *StatTsByteErrs
);

int
realtek_i_dvbt_GetStatTsBitErrs(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *StatTsByteErrs
);

int
realtek_i_dvbt_GetStatViterbiBer(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *StatViterbiBer
);

int
realtek_i_dvbt_GetStatTsSync(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *StatTsSync
);

int
realtek_i_dvbt_GetStatTpsSync(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *StatTpsSync
);

int
realtek_i_dvbt_GetStatIfAgcLevel(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *StatIfAgcLevel
);

int
realtek_i_dvbt_GetStatNumSymbols(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *StatNumSymbols
);

int
realtek_i_dvbt_GetStatNumReaqc(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *StatNumReaqc
);

int
realtek_i_dvbt_GetStatAciDetect(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *StatAciDetect
);

int
realtek_i_dvbt_SetBerPeriod(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int BerPeriod
);

int
realtek_i_dvbt_GetBerPeriod(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *BerPeriod
);

int
realtek_i_dvbt_GetBerUpdate(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *BerUpdate
);

int
realtek_i_dvbt_GetBerRsBer(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *BerRsBer
);

int
realtek_i_dvbt_GetBerTsPer(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *BerTsPer
);

int
realtek_i_dvbt_GetBerSqi(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *BerSqi
);

int
realtek_i_dvbt_GetIfAgcGain(
	DVBT_DEMOD_MODULE *pDemod,
	unsigned int *IfAgcGain
);

#ifdef __cplusplus
}
#endif
#endif
