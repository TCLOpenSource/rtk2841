#ifndef __ATSC_DEMOD_REALTEK_R_H
#define __ATSC_DEMOD_REALTEK_R_H

/**

@file

@brief   REALTEK_R ATSC demod module declaration

One can manipulate REALTEK_R ATSC demod through REALTEK_R ATSC module.
REALTEK_R ATSC module is derived from ATSC demod module.

@par Example:
@code

// The example is the same as the ATSC demod example in atsc_demod_base.h except the listed lines.

#include "demod_realtek_r_atsc.h"


...


int main(void)
{
	ATSC_DEMOD_MODULE *pDemod;

	ATSC_DEMOD_MODULE     AtscDemodModuleMemory;
	BASE_INTERFACE_MODULE BaseInterfaceModuleMemory;
	I2C_BRIDGE_MODULE     I2cBridgeModuleMemory;

	...


	// Build REALTEK_R ATSC demod module.
	BuildRealtekRAtscModule(
		&pDemod,
		&AtscDemodModuleMemory,
		&BaseInterfaceModuleMemory,
		&I2cBridgeModuleMemory,
		0x24,								// I2C device address is 0x24 in 8-bit format.
		CRYSTAL_FREQ_27000000HZ				// Crystal frequency is 27 MHz.
		);

	...


	// Need to set tuner before demod software reset.
	// The order to set demod and tuner is not important.
	// Note: 1. We can use "pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_I2CT_EN_CTRL, 0x1);"
	//          to enable tuner I2C command forwarding.
	//       2. We can use "pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_I2CT_EN_CTRL, 0x0);"
	//          to disable tuner I2C command forwarding.

	...


	// Get byte error rate and packet error rate.
	pDemod->GetErrorRate(pDemod, NO_USE, NO_USE, &ByteErrorRateNum, &ByteErrorRateDen, &PacketErrorRateNum,
		&PacketErrorRateDen);

	...


	// See the example for other ATSC demod functions in atsc_demod_base.h

	...

	return 0;
}

@endcode

*/

#include "atsc_demod_base.h"

#ifdef __cplusplus
extern "C" {
#endif

// Firmware code
#define REALTEK_R_ATSC_FIRMWARE_CODE_TABLE_LEN		3072
// Definitions
#define REALTEK_R_ATSC_REG_TABLE_LEN				50
#define REALTEK_R_ATSC_SYS_VERSION_VALUE			0xa5
#define REALTEK_R_ATSC_SYMBOL_RATE_HZ				10762238

// AGC register
#define REALTEK_R_ATSC_RF_AGC_VALUE_BIT_NUM		14
#define REALTEK_R_ATSC_IF_AGC_VALUE_BIT_NUM		14

// TR offset register
#define REALTEK_R_ATSC_TR_OFFSET_N1_BIT_NUM		11
#define REALTEK_R_ATSC_TR_OFFSET_N2_BIT_NUM		16

// CR offset register
#define REALTEK_R_ATSC_CR_OFFSET_N1_BIT_NUM				18
#define REALTEK_R_ATSC_CR_OFFSET_N2_25_0_BIT_NUM			26
#define REALTEK_R_ATSC_CR_OFFSET_N2_32_26_BIT_NUM			7

// Byte error rate and packet error rate
#define REALTEK_R_ATSC_BER_TEST_PACKET_NUM		8192
#define REALTEK_R_ATSC_BER_TEST_BYTE_NUM			REALTEK_R_ATSC_BER_TEST_PACKET_NUM * 207

// SNR
// Note: REALTEK_R_ATSC_SNR_DB_NUM_CONST = round(10 * log2(21 * pow(2, 26)) * pow(2, REALTEK_R_ATSC_SNR_FRAC_BIT_NUM))
//       REALTEK_R_ATSC_SNR_DB_DEN       = round(log2(10) * pow(2, REALTEK_R_ATSC_SNR_FRAC_BIT_NUM))
#define REALTEK_R_ATSC_SNR_FRAC_BIT_NUM			10
#define REALTEK_R_ATSC_SNR_DB_NUM_CONST			311217
#define REALTEK_R_ATSC_SNR_DB_DEN					3402
#define REALTEK_R_ATSC_MSE2_23_0_BIT_NUM			24
#define REALTEK_R_ATSC_MSE2_33_24_BIT_NUM			10

// Table length
#define REALTEK_R_ATSC_INIT_REG_TABLE_LEN			342

// Builder
void
BuildRealtekRAtscModule(
	ATSC_DEMOD_MODULE **ppDemod,
	ATSC_DEMOD_MODULE *pAtscDemodModuleMemory,
	BASE_INTERFACE_MODULE *pBaseInterfaceModuleMemory,
	I2C_BRIDGE_MODULE *pI2cBridgeModuleMemory,
	unsigned char DeviceAddr,
	unsigned long CrystalFreqHz
);

// Manipulaing functions
void
realtek_r_atsc_IsConnectedToI2c(
	ATSC_DEMOD_MODULE *pDemod,
	int *pAnswer
);

int
realtek_r_atsc_SoftwareReset(
	ATSC_DEMOD_MODULE *pDemod
);

int
realtek_r_atsc_TrPhaseInc_Reset(
	ATSC_DEMOD_MODULE *pDemod
);

int
realtek_r_atsc_Initialize(
	ATSC_DEMOD_MODULE *pDemod
);

int
realtek_r_atsc_SetIfFreqHz(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned long IfFreqHz
);

int
realtek_r_atsc_SetSpectrumMode(
	ATSC_DEMOD_MODULE *pDemod,
	int SpectrumMode
);

int
realtek_r_atsc_GetRfAgc(
	ATSC_DEMOD_MODULE *pDemod,
	long *pRfAgc
);

int
realtek_r_atsc_GetIfAgc(
	ATSC_DEMOD_MODULE *pDemod,
	long *pIfAgc
);

int
realtek_r_atsc_GetDiAgc(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned long *pDiAgc
);

int
realtek_r_atsc_GetTrOffsetPpm(
	ATSC_DEMOD_MODULE *pDemod,
	long *pTrOffsetPpm
);

/*
int
realtek_r_atsc_GetTrFsFreqSubOffsetPpm(
	ATSC_DEMOD_MODULE *pDemod,
	long *pTrOffsetPpm
);
*/
int
realtek_r_atsc_GetTrLoopSel(
	ATSC_DEMOD_MODULE *pDemod,
	long *pTrLoopSel
);

int
realtek_r_atsc_GetCrOffsetHz(
	ATSC_DEMOD_MODULE *pDemod,
	long *pCrOffsetHz
);

int
realtek_r_atsc_IsAagcLocked(
	ATSC_DEMOD_MODULE *pDemod,
	int *pAnswer
);

int
realtek_r_atsc_IsFrameLocked(
	ATSC_DEMOD_MODULE *pDemod,
	int *pAnswer
);

int
realtek_r_atsc_IsTrLocked(
	ATSC_DEMOD_MODULE *pDemod,
	int *pAnswer
);

int
realtek_r_atsc_IsCrLocked(
	ATSC_DEMOD_MODULE *pDemod,
	int *pAnswer
);

int
realtek_r_atsc_IsNoSig(
	ATSC_DEMOD_MODULE *pDemod,
	int *pAnswer
);

int
realtek_r_atsc_GetErrorRate(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned long TestVolume,
	unsigned int WaitTimeMsMax,
	unsigned long *pByteErrorRateNum,
	unsigned long *pByteErrorRateDen,
	unsigned long *pPacketErrorRateNum,
	unsigned long *pPacketErrorRateDen
);

int
realtek_r_atsc_GetSnrDb(
	ATSC_DEMOD_MODULE *pDemod,
	long *pSnrDbNum,
	long *pSnrDbDen
);

int
realtek_r_atsc_GetSignalStrength(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned long *pSignalStrength
);

int
realtek_r_atsc_GetSignalQuality(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned long *pSignalQuality
);

int
realtek_r_atsc_UpdateFunction(
	ATSC_DEMOD_MODULE *pDemod
);

int
realtek_r_atsc_ResetFunction(
	ATSC_DEMOD_MODULE *pDemod
);

// I2C command forwarding functions
int
realtek_r_atsc_ForwardI2cReadingCmd(
	I2C_BRIDGE_MODULE *pI2cBridge,
	unsigned char DeviceAddr,
	unsigned char *pReadingBytes,
	unsigned long ByteNum
);

int
realtek_r_atsc_ForwardI2cWritingCmd(
	I2C_BRIDGE_MODULE *pI2cBridge,
	unsigned char DeviceAddr,
	const unsigned char *pWritingBytes,
	unsigned long ByteNum
);

// Register table initialization
void
realtek_r_atsc_InitRegTable(
	ATSC_DEMOD_MODULE *pDemod
);

// I2C birdge module builder
void
realtek_r_atsc_BuildI2cBridgeModule(
	ATSC_DEMOD_MODULE *pDemod
);

int
realtek_r_atsc_acceleration_SetRegMaskBits(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	const unsigned long WritingValue
);

// Firmware code downloading
int
realtek_r_atsc_DownloadFirmwareCode(
	ATSC_DEMOD_MODULE *pDemod
);

// Firmware code table
extern unsigned char realtek_r_atsc_FirewareCodeTable[REALTEK_R_ATSC_FIRMWARE_CODE_TABLE_LEN];

#ifdef __cplusplus
}
#endif
#endif
