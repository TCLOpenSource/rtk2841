#ifndef __ATSC_DEMOD_BASE_H
#define __ATSC_DEMOD_BASE_H

#include "foundation.h"

#ifdef __cplusplus
extern "C" {
#endif


/**

@file

@brief   ATSC demod base module definition

ATSC demod base module definitions contains demod module structure, demod funciton pointers, and demod definitions.


@par Example:
@code

#include "demod_xxx.h"

int
CustomI2cRead(
	BASE_INTERFACE_MODULE *pBaseInterface,
	unsigned char DeviceAddr,
	unsigned char *pReadingBytes,
	unsigned long ByteNum
	)
{
	// I2C reading format:
	// start_bit + (DeviceAddr | reading_bit) + reading_byte * ByteNum + stop_bit

	...

	return FUNCTION_SUCCESS;

error_status:
	return FUNCTION_ERROR;
}


int
CustomI2cWrite(
	BASE_INTERFACE_MODULE *pBaseInterface,
	unsigned char DeviceAddr,
	const unsigned char *pWritingBytes,
	unsigned long ByteNum
	)
{
	// I2C writing format:
	// start_bit + (DeviceAddr | writing_bit) + writing_byte * ByteNum + stop_bit

	...

	return FUNCTION_SUCCESS;

error_status:
	return FUNCTION_ERROR;
}


void
CustomWaitMs(
	BASE_INTERFACE_MODULE *pBaseInterface,
	unsigned long WaitTimeMs
	)
{
	// Wait WaitTimeMs milliseconds.

	...

	return;
}


int main(void)
{
	BASE_INTERFACE_MODULE *pBaseInterface;
	BASE_INTERFACE_MODULE BaseInterfaceModuleMemory;

	ATSC_DEMOD_MODULE *pDemod;
	ATSC_DEMOD_MODULE AtscDemodModuleMemory;

	I2C_BRIDGE_MODULE I2cBridgeModuleMemory;

	unsigned long IfFreqHz;
	int SpectrumMode;

	int DemodType;
	unsigned char DeviceAddr;
	unsigned long CrystalFreqHz;

	long RfAgc, IfAgc;
	unsigned long DiAgc;

	int Answer;
	long TrOffsetPpm, CrOffsetHz;
	unsigned long ByteErrorRateNum, ByteErrorRateDen, PacketErrorRateNum, PacketErrorRateDen;
	double ByteErrorRate, PacketErrorRate;
	long SnrDbNum, SnrDbDen;
	double SnrDb;
	unsigned long SignalStrength, SignalQuality;

	// Build base interface module.
	BuildBaseInterface(
		&pBaseInterface,
		&BaseInterfaceModuleMemory,
		9,								// Set maximum I2C reading byte number with 9.
		8,								// Set maximum I2C writing byte number with 8.
		CustomI2cRead,					// Employ CustomI2cRead() as basic I2C reading function.
		CustomI2cWrite,					// Employ CustomI2cWrite() as basic I2C writing function.
		CustomWaitMs					// Employ CustomWaitMs() as basic waiting function.
		);


	// Build ATSC demod XXX module.
	BuildXxxModule(
		&pDemod,
		&AtscDemodModuleMemory,
		&BaseInterfaceModuleMemory,
		&I2cBridgeModuleMemory,
		0x20,							// Demod I2C device address is 0x20 in 8-bit format.
		CRYSTAL_FREQ_28800000HZ,		// Demod crystal frequency is 28.8 MHz.
		...								// Other arguments by each demod module
		);


	// ==== Initialize ATSC demod and set its parameters =====

	// Initialize demod.
	pDemod->Initialize(pDemod);


	// Set demod parameters. (symbol rate, IF frequency, spectrum mode)
	// Note: In the example:
	//       1. IF frequency is 44 MHz.
	//       2. Spectrum mode is SPECTRUM_INVERSE.
	IfFreqHz     = IF_FREQ_44000000HZ;
	SpectrumMode = SPECTRUM_INVERSE;

	pDemod->SetIfFreqHz(pDemod,     IfFreqHz);
	pDemod->SetSpectrumMode(pDemod, SpectrumMode);


	// Need to set tuner before demod software reset.
	// The order to set demod and tuner is not important.
	// Note: 1. For 8-bit register address demod, one can use
	//          "pDemod->RegAccess.Addr8Bit.SetRegBitsWithPage(pDemod, ATSC_OPT_I2C_RELAY, 0x1);"
	//          for tuner I2C command forwarding.
	//       2. For 16-bit register address demod, one can use
	//          "pDemod->RegAccess.Addr16Bit.SetRegBits(pDemod, ATSC_OPT_I2C_RELAY, 0x1);"
	//          for tuner I2C command forwarding.


	// Reset demod by software reset.
	pDemod->SoftwareReset(pDemod);


	// Wait maximum 1000 ms for demod converge.
	for(i = 0; i < 25; i++)
	{
		// Wait 40 ms.
		pBaseInterface->WaitMs(pBaseInterface, 40);

		// Check signal lock status through frame lock.
		// Note: If Answer is YES, frame is locked.
		//       If Answer is NO, frame is not locked.
		pDemod->IsFrameLocked(pDemod, &Answer);

		if(Answer == YES)
		{
			// Signal is locked.
			break;
		}
	}


	// ==== Get ATSC demod information =====

	// Get demod type.
	// Note: One can find demod type in MODULE_TYPE enumeration.
	pDemod->GetDemodType(pDemod, &DemodType);

	// Get demod I2C device address.
	pDemod->GetDeviceAddr(pDemod, &DeviceAddr);

	// Get demod crystal frequency in Hz.
	pDemod->GetCrystalFreqHz(pDemod, &CrystalFreqHz);

	// Ask demod if it is connected to I2C bus.
	// Note: If Answer is YES, demod is connected to I2C bus.
	//       If Answer is NO, demod is not connected to I2C bus.
	pDemod->IsConnectedToI2c(pDemod, &Answer);

	// Get demod parameters. (symbol rate, IF frequency, spectrum mode)
	pDemod->GetIfFreqHz(pDemod,     &IfFreqHz);
	pDemod->GetSpectrumMode(pDemod, &SpectrumMode);

	// Get demod AGC value.
	// Note: The range of RF AGC and IF AGC value is -8192 ~ 8191.
	//       The range of digital AGC value is 0 ~ 8191.
	pDemod->GetRfAgc(pDemod, &RfAgc);
	pDemod->GetIfAgc(pDemod, &IfAgc);
	pDemod->GetDiAgc(pDemod, &DiAgc);

	// Get demod lock status.
	// Note: If Answer is YES, it is locked.
	//       If Answer is NO, it is not locked.
	pDemod->IsAagcLocked(pDemod,  &Answer);
	pDemod->IsFrameLocked(pDemod, &Answer);

	// Get TR offset (symbol timing offset) in ppm.
	pDemod->GetTrOffsetPpm(pDemod, &TrOffsetPpm);

	// Get CR offset (RF frequency offset) in Hz.
	pDemod->GetCrOffsetHz(pDemod, &CrOffsetHz);

	// Get byte error rate and packet error rate.
	// Note: Test packet number = pow(2, (2 * 5 + 4)) = 16384
	//       Maximum wait time  = 1000 ms = 1 second
	pDemod->GetErrorRate(pDemod, 5, 1000, &ByteErrorRateNum, &ByteErrorRateDen, &PacketErrorRateNum,
		&PacketErrorRateDen);
	ByteErrorRate = (double)ByteErrorRateNum / (double)ByteErrorRateDen;
	PacketErrorRate = (double)PacketErrorRateNum / (double)PacketErrorRateDen;

	// Get SNR in dB.
	pDemod->GetSnrDb(pDemod, &SnrDbNum, &SnrDbDen);
	SnrDb = (double)SnrDbNum / (double)SnrDbDen;

	// Get signal strength.
	// Note: 1. The range of SignalStrength is 0~100.
	//       2. Need to map SignalStrength value to UI signal strength bar manually.
	pDemod->GetSignalStrength(pDemod, &SignalStrength);

	// Get signal quality.
	// Note: 1. The range of SignalQuality is 0~100.
	//       2. Need to map SignalQuality value to UI signal quality bar manually.
	pDemod->GetSignalQuality(pDemod, &SignalQuality);

	return 0;
}


@endcode

*/


// Definitions

// Page register address
#define ATSC_DEMOD_PAGE_REG_ADDR				0x0


// Register entry definitions

// Register entry for 8-bit address
typedef struct {
	int IsAvailable;
	unsigned long PageNo;
	unsigned char RegStartAddr;
	unsigned char Msb;
	unsigned char Lsb;
}
ATSC_REG_ENTRY_ADDR_8BIT;


// Primary register entry for 8-bit address
typedef struct {
	int RegBitName;
	unsigned long PageNo;
	unsigned char RegStartAddr;
	unsigned char Msb;
	unsigned char Lsb;
}
ATSC_PRIMARY_REG_ENTRY_ADDR_8BIT;


// Register entry for 16-bit address
typedef struct {
	int IsAvailable;
	unsigned short RegStartAddr;
	unsigned char Msb;
	unsigned char Lsb;
}
ATSC_REG_ENTRY_ADDR_16BIT;


// Primary register entry for 16-bit address
typedef struct {
	int RegBitName;
	unsigned short RegStartAddr;
	unsigned char Msb;
	unsigned char Lsb;
}
ATSC_PRIMARY_REG_ENTRY_ADDR_16BIT;


// Register bit name definitions

// Register bit name
enum ATSC_REG_BIT_NAME {
	// Generality
	ATSC_SYS_VERSION,
	ATSC_OPT_I2C_RELAY,
	ATSC_I2CT_EN_CTRL,						// for RTD2648 ATSC only
	ATSC_OPT_SOFT_RESET_ATSC,

	// Miscellany
	ATSC_RO_STROBE,

	// AAGC
	ATSC_OPT_RF_AAGC_DRIVE,
	ATSC_OPT_PAR_RF_SD_IB,
	ATSC_OPT_RF_AAGC_OE,
	ATSC_OPT_RF_AGC_DRIVING,
	ATSC_RF_AGC_MAX,
	ATSC_RF_AGC_MIN,
	ATSC_OPT_IF_AAGC_DRIVE,
	ATSC_OPT_PAR_IF_SD_IB,
	ATSC_OPT_IF_AAGC_OE,
	ATSC_OPT_IF_AGC_DRIVING,
	ATSC_IF_AGC_MAX,
	ATSC_IF_AGC_MIN,
	ATSC_AAGC_TARGET,
	ATSC_POLAR_IFAGC,
	ATSC_AGC_MODE,
	ATSC_VTOP,
	ATSC_KRF,
	ATSC_RO_AAGC_LOCK,
	ATSC_RO_RF_AAGC,						// for RTD2885 only
	ATSC_RO_IF_AAGC,

	// DAGC
	ATSC_RO_DAGC_LEVEL_Q,

	// Demod status
	ATSC_RO_CURRENT_STATE,

	// AD7
	ATSC_AD7_RO,							// for RTL2920 OpenCable only
	ATSC_OPT_AD7_CLK_RATIO,					// for RTL2920 OpenCable only
	ATSC_OPT_AD7_CLK_SEL,					// for RTL2920 OpenCable only
	ATSC_OPT_AD7_RO_STROBE,					// for RTL2920 OpenCable only

	// DDC
	ATSC_DDC_PHASE_INC,
	ATSC_SPEC_INV_ON,
	ATSC_CR_CONST_INC,
	ATSC_CR_ACQ_FREQ_UB,                    // for covering range adjustment...
	ATSC_TR_PHASE_INC,

	// Carrier recovery
	ATSC_RO_CR_OFFSET_N1,
	ATSC_RO_CR_OFFSET_N2,					// for RTL2920 OpenCable only
	ATSC_RO_CR_OFFSET_N2_25_0,				// for RTD2885 only
	ATSC_RO_CR_OFFSET_N2_32_26,				// for RTD2885 only
	ATSC_RO_CR_LOCK_IND,
	ATSC_CR_FMU_UPD_OPT,
	ATSC_CR_LPF_SHIFT,
	ATSC_CR_PMU_COMP1,

	// Timing recovery
	ATSC_RO_TR_OFFSET_N1,					// for RTD2885 only
	ATSC_RO_TR_OFFSET_N2,
	ATSC_RO_TR_LOCK_IND,
	ATSC_RO_TR_FS_FREQ,
	ATSC_TR_MIN_SAT_EN,
	ATSC_TR_LOCK_IND_MODE,
	ATSC_TR_LOCK_TH2,

	// Equalizer
	ATSC_RO_MSE2,							// for RTL2820 OpenCable only
	ATSC_RO_MSE2_23_0,						// for RTD2885 only
	ATSC_RO_MSE2_33_24,						// for RTD2885 only
	ATSC_RO_FBF_COEFF_SUM_H,
	ATSC_FFE_SP_HOLD,
	ATSC_FBF_RO_SUM_ADD,
	//ATSC_LD_MSE_FIELD_TH_1,//[ATSC_LD_MSE_FIELD_TH_H,ATSC_LD_MSE_FIELD_TH_L]
	ATSC_LD_MSE_FIELD_TH_H,
	ATSC_LD_MSE_FIELD_TH_L,

	//FSM
	ATSC_FSM_RAM_ROW,
	ATSC_FSM_RAM_COL,
	ATSC_FSM_RAM_DATA,

	// Outer
	ATSC_BER_RST,
	ATSC_BER_HOLD,
	ATSC_DIS_AUTO_MODE,
	ATSC_TEST_VOLUME,
	ATSC_BER_ONCE,							// for RTD2648 ATSC only
	ATSC_BER_SEL,							// for RTD2648 ATSC only
	ATSC_RO_AO_RS_SER_TRIG,					// for RTD2648 ATSC only
	ATSC_AO_ERR_BYTE_CNT,
	ATSC_AO_PKT_CNT,
	ATSC_AO_CORR_CNT,
	ATSC_AO_UN_CORR_CNT,

	// MPEG TS output interface
	ATSC_OPT_M_OEN,
	ATSC_FIX_TEI,
	ATSC_CKOUTPAR,
	ATSC_CKOUT_PWR,
	ATSC_SYNC_DUR,
	ATSC_ERR_DUR,
	ATSC_ERR_LVL,
	ATSC_VAL_LVL,
	ATSC_SERIAL,
	ATSC_SER_LSB,							// for RTD2885 only
	ATSC_CDIV_PH0,
	ATSC_CDIV_PH1,

	// Smart antenna
	ATSC_OPT_ANT_IO_MODE,
	ATSC_OPT_ANT_PAD_OE,
	ATSC_OPT_ANT_DRIVING,
	ATSC_OPT_ANT_SLEW,						// for RTL2820 OpenCable only
	ATSC_OPT_ANT_RESET_N,
	ATSC_OPT_ANT_ENABLE,

	//dummy register
	Dummy_FAKE_PER_EN,
	Dummy_CHANGE_CHANNEL_IND,

	//8051 FW
	DW_8051_RST,
	ATSC_LD_AI_EN_5,

	// Item terminator
	ATSC_REG_BIT_NAME_ITEM_TERMINATOR,
};


// Register table length definitions
#define ATSC_REG_TABLE_LEN_MAX			ATSC_REG_BIT_NAME_ITEM_TERMINATOR

/// ATSC demod module pre-definition
typedef struct ATSC_DEMOD_MODULE_TAG ATSC_DEMOD_MODULE;


/**

@brief   ATSC demod register page setting function pointer

Demod upper level functions will use ATSC_DEMOD_FP_SET_REG_PAGE() to set demod register page.

@param [in]   pDemod   The demod module pointer
@param [in]   PageNo   Page number

@retval   FUNCTION_SUCCESS   Set register page successfully with page number.
@retval   FUNCTION_ERROR     Set register page unsuccessfully.

@note
	-# Demod building function will set ATSC_DEMOD_FP_SET_REG_PAGE() with the corresponding function.

@par Example:
@code

#include "demod_pseudo.h"


int main(void)
{
	ATSC_DEMOD_MODULE *pDemod;
	ATSC_DEMOD_MODULE AtscDemodModuleMemory;
	PSEUDO_EXTRA_MODULE PseudoExtraModuleMemory;


	// Build pseudo demod module.
	BuildPseudoDemodModule(&pDemod, &AtscDemodModuleMemory, &PseudoExtraModuleMemory);

	...

	// Set demod register page with page number 2.
	pDemod->SetRegPage(pDemod, 2);

	...

	return 0;
}


@endcode

*/
typedef int
(*ATSC_DEMOD_FP_ADDR_8BIT_SET_REG_PAGE)(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned long PageNo
);





/**

@brief   ATSC demod register byte setting function pointer

Demod upper level functions will use ATSC_DEMOD_FP_SET_REG_BYTES() to set demod register bytes.


@param [in]   pDemod          The demod module pointer
@param [in]   RegStartAddr    Demod register start address
@param [in]   pWritingBytes   Pointer to writing bytes
@param [in]   ByteNum         Writing byte number


@retval   FUNCTION_SUCCESS   Set demod register bytes successfully with writing bytes.
@retval   FUNCTION_ERROR     Set demod register bytes unsuccessfully.


@note
	-# Demod building function will set ATSC_DEMOD_FP_SET_REG_BYTES() with the corresponding function.
	-# Need to set register page by ATSC_DEMOD_FP_SET_REG_PAGE() before using ATSC_DEMOD_FP_SET_REG_BYTES().


@see   ATSC_DEMOD_FP_SET_REG_PAGE, ATSC_DEMOD_FP_GET_REG_BYTES



@par Example:
@code


#include "demod_pseudo.h"


int main(void)
{
	ATSC_DEMOD_MODULE *pDemod;
	ATSC_DEMOD_MODULE AtscDemodModuleMemory;
	PSEUDO_EXTRA_MODULE PseudoExtraModuleMemory;
	unsigned char WritingBytes[10];


	// Build pseudo demod module.
	BuildPseudoDemodModule(&pDemod, &AtscDemodModuleMemory, &PseudoExtraModuleMemory);

	...

	// Set demod register bytes (page 1, address 0x17 ~ 0x1b) with 5 writing bytes.
	pDemod->SetRegPage(pDemod, 1);
	pDemod->SetRegBytes(pDemod, 0x17, WritingBytes, 5);

	...

	return 0;
}


@endcode

*/
typedef int
(*ATSC_DEMOD_FP_ADDR_8BIT_SET_REG_BYTES)(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	const unsigned char *pWritingBytes,
	unsigned long ByteNum
);

typedef int
(*ATSC_DEMOD_FP_ADDR_16BIT_SET_REG_BYTES)(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	const unsigned char *pWritingBytes,
	unsigned long ByteNum
);


/**

@brief   ATSC demod register byte getting function pointer

Demod upper level functions will use ATSC_DEMOD_FP_GET_REG_BYTES() to get demod register bytes.


@param [in]    pDemod          The demod module pointer
@param [in]    RegStartAddr    Demod register start address
@param [out]   pReadingBytes   Pointer to an allocated memory for storing reading bytes
@param [in]    ByteNum         Reading byte number


@retval   FUNCTION_SUCCESS   Get demod register bytes successfully with reading byte number.
@retval   FUNCTION_ERROR     Get demod register bytes unsuccessfully.


@note
	-# Demod building function will set ATSC_DEMOD_FP_GET_REG_BYTES() with the corresponding function.
	-# Need to set register page by ATSC_DEMOD_FP_SET_REG_PAGE() before using ATSC_DEMOD_FP_GET_REG_BYTES().


@see   ATSC_DEMOD_FP_SET_REG_PAGE, ATSC_DEMOD_FP_SET_REG_BYTES



@par Example:
@code


#include "demod_pseudo.h"


int main(void)
{
	ATSC_DEMOD_MODULE *pDemod;
	ATSC_DEMOD_MODULE AtscDemodModuleMemory;
	PSEUDO_EXTRA_MODULE PseudoExtraModuleMemory;
	unsigned char ReadingBytes[10];


	// Build pseudo demod module.
	BuildPseudoDemodModule(&pDemod, &AtscDemodModuleMemory, &PseudoExtraModuleMemory);

	...

	// Get demod register bytes (page 1, address 0x17 ~ 0x1b) with reading byte number 5.
	pDemod->SetRegPage(pDemod, 1);
	pDemod->GetRegBytes(pDemod, 0x17, ReadingBytes, 5);

	...

	return 0;
}


@endcode

*/
typedef int
(*ATSC_DEMOD_FP_ADDR_8BIT_GET_REG_BYTES)(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char *pReadingBytes,
	unsigned long ByteNum
);

typedef int
(*ATSC_DEMOD_FP_ADDR_16BIT_GET_REG_BYTES)(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char *pReadingBytes,
	unsigned long ByteNum
);


/**

@brief   ATSC demod register mask bits setting function pointer

Demod upper level functions will use ATSC_DEMOD_FP_SET_REG_MASK_BITS() to set demod register mask bits.


@param [in]   pDemod         The demod module pointer
@param [in]   RegStartAddr   Demod register start address
@param [in]   Msb            Mask MSB with 0-based index
@param [in]   Lsb            Mask LSB with 0-based index
@param [in]   WritingValue   The mask bits writing value


@retval   FUNCTION_SUCCESS   Set demod register mask bits successfully with writing value.
@retval   FUNCTION_ERROR     Set demod register mask bits unsuccessfully.


@note
	-# Demod building function will set ATSC_DEMOD_FP_SET_REG_MASK_BITS() with the corresponding function.
	-# Need to set register page by ATSC_DEMOD_FP_SET_REG_PAGE() before using ATSC_DEMOD_FP_SET_REG_MASK_BITS().
	-# The constraints of ATSC_DEMOD_FP_SET_REG_MASK_BITS() function usage are described as follows:
		-# The mask MSB and LSB must be 0~31.
		-# The mask MSB must be greater than or equal to LSB.


@see   ATSC_DEMOD_FP_SET_REG_PAGE, ATSC_DEMOD_FP_GET_REG_MASK_BITS



@par Example:
@code


#include "demod_pseudo.h"


int main(void)
{
	ATSC_DEMOD_MODULE *pDemod;
	ATSC_DEMOD_MODULE AtscDemodModuleMemory;
	PSEUDO_EXTRA_MODULE PseudoExtraModuleMemory;


	// Build pseudo demod module.
	BuildPseudoDemodModule(&pDemod, &AtscDemodModuleMemory, &PseudoExtraModuleMemory);

	...

	// Set demod register bits (page 1, address {0x18, 0x17} [12:5]) with writing value 0x1d.
	pDemod->SetRegPage(pDemod, 1);
	pDemod->SetRegMaskBits(pDemod, 0x17, 12, 5, 0x1d);


	// Result:
	//
	// Writing value = 0x1d = 0001 1101 b
	//
	// Page 1
	// Register address   0x18          0x17
	// Register value     xxx0 0011 b   101x xxxx b

	...

	return 0;
}


@endcode

*/
typedef int
(*ATSC_DEMOD_FP_ADDR_8BIT_SET_REG_MASK_BITS)(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	const unsigned long WritingValue
);

typedef int
(*ATSC_DEMOD_FP_ADDR_16BIT_SET_REG_MASK_BITS)(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	const unsigned long WritingValue
);


/**

@brief   ATSC demod register mask bits getting function pointer

Demod upper level functions will use ATSC_DEMOD_FP_GET_REG_MASK_BITS() to get demod register mask bits.


@param [in]    pDemod          The demod module pointer
@param [in]    RegStartAddr    Demod register start address
@param [in]    Msb             Mask MSB with 0-based index
@param [in]    Lsb             Mask LSB with 0-based index
@param [out]   pReadingValue   Pointer to an allocated memory for storing reading value


@retval   FUNCTION_SUCCESS   Get demod register mask bits successfully.
@retval   FUNCTION_ERROR     Get demod register mask bits unsuccessfully.


@note
	-# Demod building function will set ATSC_DEMOD_FP_GET_REG_MASK_BITS() with the corresponding function.
	-# Need to set register page by ATSC_DEMOD_FP_SET_REG_PAGE() before using ATSC_DEMOD_FP_GET_REG_MASK_BITS().
	-# The constraints of ATSC_DEMOD_FP_GET_REG_MASK_BITS() function usage are described as follows:
		-# The mask MSB and LSB must be 0~31.
		-# The mask MSB must be greater than or equal to LSB.


@see   ATSC_DEMOD_FP_SET_REG_PAGE, ATSC_DEMOD_FP_SET_REG_MASK_BITS



@par Example:
@code


#include "demod_pseudo.h"


int main(void)
{
	ATSC_DEMOD_MODULE *pDemod;
	ATSC_DEMOD_MODULE AtscDemodModuleMemory;
	PSEUDO_EXTRA_MODULE PseudoExtraModuleMemory;
	unsigned long ReadingValue;


	// Build pseudo demod module.
	BuildPseudoDemodModule(&pDemod, &AtscDemodModuleMemory, &PseudoExtraModuleMemory);

	...

	// Get demod register bits (page 1, address {0x18, 0x17} [12:5]).
	pDemod->SetRegPage(pDemod, 1);
	pDemod->GetRegMaskBits(pDemod, 0x17, 12, 5, &ReadingValue);


	// Result:
	//
	// Page 1
	// Register address   0x18          0x17
	// Register value     xxx0 0011 b   101x xxxx b
	//
	// Reading value = 0001 1101 b = 0x1d

	...

	return 0;
}


@endcode

*/
typedef int
(*ATSC_DEMOD_FP_ADDR_8BIT_GET_REG_MASK_BITS)(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	unsigned long *pReadingValue
);

typedef int
(*ATSC_DEMOD_FP_ADDR_16BIT_GET_REG_MASK_BITS)(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	unsigned long *pReadingValue
);


/**

@brief   ATSC demod register bits setting function pointer

Demod upper level functions will use ATSC_DEMOD_FP_SET_REG_BITS() to set demod register bits with bit name.


@param [in]   pDemod         The demod module pointer
@param [in]   RegBitName     Pre-defined demod register bit name
@param [in]   WritingValue   The mask bits writing value


@retval   FUNCTION_SUCCESS   Set demod register bits successfully with bit name and writing value.
@retval   FUNCTION_ERROR     Set demod register bits unsuccessfully.


@note
	-# Demod building function will set ATSC_DEMOD_FP_SET_REG_BITS() with the corresponding function.
	-# Need to set register page before using ATSC_DEMOD_FP_SET_REG_BITS().
	-# Register bit names are pre-defined keys for bit access, and one can find these in demod header file.


@see   ATSC_DEMOD_FP_SET_REG_PAGE, ATSC_DEMOD_FP_GET_REG_BITS



@par Example:
@code


#include "demod_pseudo.h"


int main(void)
{
	ATSC_DEMOD_MODULE *pDemod;
	ATSC_DEMOD_MODULE AtscDemodModuleMemory;
	PSEUDO_EXTRA_MODULE PseudoExtraModuleMemory;


	// Build pseudo demod module.
	BuildPseudoDemodModule(&pDemod, &AtscDemodModuleMemory, &PseudoExtraModuleMemory);

	...

	// Set demod register bits with bit name PSEUDO_REG_BIT_NAME and writing value 0x1d.
	// The corresponding information of PSEUDO_REG_BIT_NAME is address {0x18, 0x17} [12:5] on page 1.
	pDemod->SetRegPage(pDemod, 1);
	pDemod->SetRegBits(pDemod, PSEUDO_REG_BIT_NAME, 0x1d);


	// Result:
	//
	// Writing value = 0x1d = 0001 1101 b
	//
	// Page 1
	// Register address   0x18          0x17
	// Register value     xxx0 0011 b   101x xxxx b

	...

	return 0;
}


@endcode

*/
typedef int
(*ATSC_DEMOD_FP_ADDR_8BIT_SET_REG_BITS)(
	ATSC_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

typedef int
(*ATSC_DEMOD_FP_ADDR_16BIT_SET_REG_BITS)(
	ATSC_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);


/**

@brief   ATSC demod register bits getting function pointer

Demod upper level functions will use ATSC_DEMOD_FP_GET_REG_BITS() to get demod register bits with bit name.


@param [in]    pDemod          The demod module pointer
@param [in]    RegBitName      Pre-defined demod register bit name
@param [out]   pReadingValue   Pointer to an allocated memory for storing reading value


@retval   FUNCTION_SUCCESS   Get demod register bits successfully with bit name.
@retval   FUNCTION_ERROR     Get demod register bits unsuccessfully.


@note
	-# Demod building function will set ATSC_DEMOD_FP_GET_REG_BITS() with the corresponding function.
	-# Need to set register page before using ATSC_DEMOD_FP_GET_REG_BITS().
	-# Register bit names are pre-defined keys for bit access, and one can find these in demod header file.


@see   ATSC_DEMOD_FP_SET_REG_PAGE, ATSC_DEMOD_FP_SET_REG_BITS



@par Example:
@code


#include "demod_pseudo.h"


int main(void)
{
	ATSC_DEMOD_MODULE *pDemod;
	ATSC_DEMOD_MODULE AtscDemodModuleMemory;
	PSEUDO_EXTRA_MODULE PseudoExtraModuleMemory;
	unsigned long ReadingValue;


	// Build pseudo demod module.
	BuildPseudoDemodModule(&pDemod, &AtscDemodModuleMemory, &PseudoExtraModuleMemory);

	...

	// Get demod register bits with bit name PSEUDO_REG_BIT_NAME.
	// The corresponding information of PSEUDO_REG_BIT_NAME is address {0x18, 0x17} [12:5] on page 1.
	pDemod->SetRegPage(pDemod, 1);
	pDemod->GetRegBits(pDemod, PSEUDO_REG_BIT_NAME, &ReadingValue);


	// Result:
	//
	// Page 1
	// Register address   0x18          0x17
	// Register value     xxx0 0011 b   101x xxxx b
	//
	// Reading value = 0001 1101 b = 0x1d

	...

	return 0;
}


@endcode

*/
typedef int
(*ATSC_DEMOD_FP_ADDR_8BIT_GET_REG_BITS)(
	ATSC_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

typedef int
(*ATSC_DEMOD_FP_ADDR_16BIT_GET_REG_BITS)(
	ATSC_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);


/**

@brief   ATSC demod register bits setting function pointer (with page setting)

Demod upper level functions will use ATSC_DEMOD_FP_SET_REG_BITS_WITH_PAGE() to set demod register bits with bit name and
page setting.


@param [in]   pDemod         The demod module pointer
@param [in]   RegBitName     Pre-defined demod register bit name
@param [in]   WritingValue   The mask bits writing value


@retval   FUNCTION_SUCCESS   Set demod register bits successfully with bit name, page setting, and writing value.
@retval   FUNCTION_ERROR     Set demod register bits unsuccessfully.


@note
	-# Demod building function will set ATSC_DEMOD_FP_SET_REG_BITS_WITH_PAGE() with the corresponding function.
	-# Don't need to set register page before using ATSC_DEMOD_FP_SET_REG_BITS_WITH_PAGE().
	-# Register bit names are pre-defined keys for bit access, and one can find these in demod header file.


@see   ATSC_DEMOD_FP_GET_REG_BITS_WITH_PAGE



@par Example:
@code


#include "demod_pseudo.h"


int main(void)
{
	ATSC_DEMOD_MODULE *pDemod;
	ATSC_DEMOD_MODULE AtscDemodModuleMemory;
	PSEUDO_EXTRA_MODULE PseudoExtraModuleMemory;


	// Build pseudo demod module.
	BuildPseudoDemodModule(&pDemod, &AtscDemodModuleMemory, &PseudoExtraModuleMemory);

	...

	// Set demod register bits with bit name PSEUDO_REG_BIT_NAME and writing value 0x1d.
	// The corresponding information of PSEUDO_REG_BIT_NAME is address {0x18, 0x17} [12:5] on page 1.
	pDemod->SetRegBitsWithPage(pDemod, PSEUDO_REG_BIT_NAME, 0x1d);


	// Result:
	//
	// Writing value = 0x1d = 0001 1101 b
	//
	// Page 1
	// Register address   0x18          0x17
	// Register value     xxx0 0011 b   101x xxxx b

	...

	return 0;
}


@endcode

*/
typedef int
(*ATSC_DEMOD_FP_ADDR_8BIT_SET_REG_BITS_WITH_PAGE)(
	ATSC_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);


/**

@brief   ATSC demod register bits getting function pointer (with page setting)

Demod upper level functions will use ATSC_DEMOD_FP_GET_REG_BITS_WITH_PAGE() to get demod register bits with bit name and
page setting.


@param [in]    pDemod          The demod module pointer
@param [in]    RegBitName      Pre-defined demod register bit name
@param [out]   pReadingValue   Pointer to an allocated memory for storing reading value


@retval   FUNCTION_SUCCESS   Get demod register bits successfully with bit name and page setting.
@retval   FUNCTION_ERROR     Get demod register bits unsuccessfully.


@note
	-# Demod building function will set ATSC_DEMOD_FP_GET_REG_BITS_WITH_PAGE() with the corresponding function.
	-# Don't need to set register page before using ATSC_DEMOD_FP_GET_REG_BITS_WITH_PAGE().
	-# Register bit names are pre-defined keys for bit access, and one can find these in demod header file.


@see   ATSC_DEMOD_FP_SET_REG_BITS_WITH_PAGE



@par Example:
@code


#include "demod_pseudo.h"


int main(void)
{
	ATSC_DEMOD_MODULE *pDemod;
	ATSC_DEMOD_MODULE AtscDemodModuleMemory;
	PSEUDO_EXTRA_MODULE PseudoExtraModuleMemory;
	unsigned long ReadingValue;


	// Build pseudo demod module.
	BuildPseudoDemodModule(&pDemod, &AtscDemodModuleMemory, &PseudoExtraModuleMemory);

	...

	// Get demod register bits with bit name PSEUDO_REG_BIT_NAME.
	// The corresponding information of PSEUDO_REG_BIT_NAME is address {0x18, 0x17} [12:5] on page 1.
	pDemod->GetRegBitsWithPage(pDemod, PSEUDO_REG_BIT_NAME, &ReadingValue);


	// Result:
	//
	// Page 1
	// Register address   0x18          0x17
	// Register value     xxx0 0011 b   101x xxxx b
	//
	// Reading value = 0001 1101 b = 0x1d

	...

	return 0;
}


@endcode

*/
typedef int
(*ATSC_DEMOD_FP_ADDR_8BIT_GET_REG_BITS_WITH_PAGE)(
	ATSC_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);


// Demod register access for 8-bit address
typedef struct {
	ATSC_DEMOD_FP_ADDR_8BIT_SET_REG_PAGE             SetRegPage;
	ATSC_DEMOD_FP_ADDR_8BIT_SET_REG_BYTES            SetRegBytes;
	ATSC_DEMOD_FP_ADDR_8BIT_GET_REG_BYTES            GetRegBytes;
	ATSC_DEMOD_FP_ADDR_8BIT_SET_REG_MASK_BITS        SetRegMaskBits;
	ATSC_DEMOD_FP_ADDR_8BIT_GET_REG_MASK_BITS        GetRegMaskBits;
	ATSC_DEMOD_FP_ADDR_8BIT_SET_REG_BITS             SetRegBits;
	ATSC_DEMOD_FP_ADDR_8BIT_GET_REG_BITS             GetRegBits;
	ATSC_DEMOD_FP_ADDR_8BIT_SET_REG_BITS_WITH_PAGE   SetRegBitsWithPage;
	ATSC_DEMOD_FP_ADDR_8BIT_GET_REG_BITS_WITH_PAGE   GetRegBitsWithPage;
}
ATSC_DEMOD_REG_ACCESS_ADDR_8BIT;


// Demod register access for 16-bit address
typedef struct {
	ATSC_DEMOD_FP_ADDR_16BIT_SET_REG_BYTES       SetRegBytes;
	ATSC_DEMOD_FP_ADDR_16BIT_GET_REG_BYTES       GetRegBytes;
	ATSC_DEMOD_FP_ADDR_16BIT_SET_REG_MASK_BITS   SetRegMaskBits;
	ATSC_DEMOD_FP_ADDR_16BIT_GET_REG_MASK_BITS   GetRegMaskBits;
	ATSC_DEMOD_FP_ADDR_16BIT_SET_REG_BITS        SetRegBits;
	ATSC_DEMOD_FP_ADDR_16BIT_GET_REG_BITS        GetRegBits;
}
ATSC_DEMOD_REG_ACCESS_ADDR_16BIT;


/**

@brief   ATSC demod type getting function pointer

One can use ATSC_DEMOD_FP_GET_DEMOD_TYPE() to get ATSC demod type.


@param [in]    pDemod       The demod module pointer
@param [out]   pDemodType   Pointer to an allocated memory for storing demod type


@note
	-# Demod building function will set ATSC_DEMOD_FP_GET_DEMOD_TYPE() with the corresponding function.


@see   MODULE_TYPE

*/
typedef void
(*ATSC_DEMOD_FP_GET_DEMOD_TYPE)(
	ATSC_DEMOD_MODULE *pDemod,
	int *pDemodType
);


/**

@brief   ATSC demod I2C device address getting function pointer

One can use ATSC_DEMOD_FP_GET_DEVICE_ADDR() to get ATSC demod I2C device address.


@param [in]    pDemod        The demod module pointer
@param [out]   pDeviceAddr   Pointer to an allocated memory for storing demod I2C device address


@note
	-# Demod building function will set ATSC_DEMOD_FP_GET_DEVICE_ADDR() with the corresponding function.

*/
typedef void
(*ATSC_DEMOD_FP_GET_DEVICE_ADDR)(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned char *pDeviceAddr
);


/**

@brief   ATSC demod crystal frequency getting function pointer

One can use ATSC_DEMOD_FP_GET_CRYSTAL_FREQ_HZ() to get ATSC demod crystal frequency in Hz.


@param [in]    pDemod           The demod module pointer
@param [out]   pCrystalFreqHz   Pointer to an allocated memory for storing demod crystal frequency in Hz


@note
	-# Demod building function will set ATSC_DEMOD_FP_GET_CRYSTAL_FREQ_HZ() with the corresponding function.

*/
typedef void
(*ATSC_DEMOD_FP_GET_CRYSTAL_FREQ_HZ)(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned long *pCrystalFreqHz
);


/**

@brief   ATSC demod I2C bus connection asking function pointer

One can use ATSC_DEMOD_FP_IS_CONNECTED_TO_I2C() to ask ATSC demod if it is connected to I2C bus.


@param [in]    pDemod    The demod module pointer
@param [out]   pAnswer   Pointer to an allocated memory for storing answer


@note
	-# Demod building function will set ATSC_DEMOD_FP_IS_CONNECTED_TO_I2C() with the corresponding function.

*/
typedef void
(*ATSC_DEMOD_FP_IS_CONNECTED_TO_I2C)(
	ATSC_DEMOD_MODULE *pDemod,
	int *pAnswer
);


/**

@brief   ATSC demod software resetting function pointer

One can use ATSC_DEMOD_FP_SOFTWARE_RESET() to reset ATSC demod by software reset.


@param [in]   pDemod   The demod module pointer


@retval   FUNCTION_SUCCESS   Reset demod by software reset successfully.
@retval   FUNCTION_ERROR     Reset demod by software reset unsuccessfully.


@note
	-# Demod building function will set ATSC_DEMOD_FP_SOFTWARE_RESET() with the corresponding function.

*/
typedef int
(*ATSC_DEMOD_FP_SOFTWARE_RESET)(
	ATSC_DEMOD_MODULE *pDemod
);


typedef int
(*ATSC_DEMOD_FP_TR_PHASE_INC_RESET)(
	ATSC_DEMOD_MODULE *pDemod
);


/**

@brief   ATSC demod initializing function pointer

One can use ATSC_DEMOD_FP_INITIALIZE() to initialie ATSC demod.


@param [in]   pDemod   The demod module pointer


@retval   FUNCTION_SUCCESS   Initialize demod successfully.
@retval   FUNCTION_ERROR     Initialize demod unsuccessfully.


@note
	-# Demod building function will set ATSC_DEMOD_FP_INITIALIZE() with the corresponding function.

*/
typedef int
(*ATSC_DEMOD_FP_INITIALIZE)(
	ATSC_DEMOD_MODULE *pDemod
);


/**

@brief   ATSC demod IF frequency setting function pointer

One can use ATSC_DEMOD_FP_SET_IF_FREQ_HZ() to set ATSC demod IF frequency in Hz.


@param [in]   pDemod     The demod module pointer
@param [in]   IfFreqHz   IF frequency in Hz for setting


@retval   FUNCTION_SUCCESS   Set demod IF frequency successfully.
@retval   FUNCTION_ERROR     Set demod IF frequency unsuccessfully.


@note
	-# Demod building function will set ATSC_DEMOD_FP_SET_IF_FREQ_HZ() with the corresponding function.


@see   IF_FREQ_HZ

*/
typedef int
(*ATSC_DEMOD_FP_SET_IF_FREQ_HZ)(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned long IfFreqHz
);


/**

@brief   ATSC demod spectrum mode setting function pointer

One can use ATSC_DEMOD_FP_SET_SPECTRUM_MODE() to set ATSC demod spectrum mode.


@param [in]   pDemod         The demod module pointer
@param [in]   SpectrumMode   Spectrum mode for setting


@retval   FUNCTION_SUCCESS   Set demod spectrum mode successfully.
@retval   FUNCTION_ERROR     Set demod spectrum mode unsuccessfully.


@note
	-# Demod building function will set ATSC_DEMOD_FP_SET_SPECTRUM_MODE() with the corresponding function.


@see   SPECTRUM_MODE

*/
typedef int
(*ATSC_DEMOD_FP_SET_SPECTRUM_MODE)(
	ATSC_DEMOD_MODULE *pDemod,
	int SpectrumMode
);


/**

@brief   ATSC demod IF frequency getting function pointer

One can use ATSC_DEMOD_FP_GET_IF_FREQ_HZ() to get ATSC demod IF frequency in Hz.


@param [in]    pDemod      The demod module pointer
@param [out]   pIfFreqHz   Pointer to an allocated memory for storing demod IF frequency in Hz


@retval   FUNCTION_SUCCESS   Get demod IF frequency successfully.
@retval   FUNCTION_ERROR     Get demod IF frequency unsuccessfully.


@note
	-# Demod building function will set ATSC_DEMOD_FP_GET_IF_FREQ_HZ() with the corresponding function.


@see   IF_FREQ_HZ

*/
typedef int
(*ATSC_DEMOD_FP_GET_IF_FREQ_HZ)(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned long *pIfFreqHz
);


/**

@brief   ATSC demod spectrum mode getting function pointer

One can use ATSC_DEMOD_FP_GET_SPECTRUM_MODE() to get ATSC demod spectrum mode.


@param [in]    pDemod          The demod module pointer
@param [out]   pSpectrumMode   Pointer to an allocated memory for storing demod spectrum mode


@retval   FUNCTION_SUCCESS   Get demod spectrum mode successfully.
@retval   FUNCTION_ERROR     Get demod spectrum mode unsuccessfully.


@note
	-# Demod building function will set ATSC_DEMOD_FP_GET_SPECTRUM_MODE() with the corresponding function.


@see   SPECTRUM_MODE

*/
typedef int
(*ATSC_DEMOD_FP_GET_SPECTRUM_MODE)(
	ATSC_DEMOD_MODULE *pDemod,
	int *pSpectrumMode
);


/**

@brief   ATSC demod RF AGC getting function pointer

One can use ATSC_DEMOD_FP_GET_RF_AGC() to get ATSC demod RF AGC value.


@param [in]    pDemod   The demod module pointer
@param [out]   pRfAgc   Pointer to an allocated memory for storing RF AGC value


@retval   FUNCTION_SUCCESS   Get demod RF AGC value successfully.
@retval   FUNCTION_ERROR     Get demod RF AGC value unsuccessfully.


@note
	-# Demod building function will set ATSC_DEMOD_FP_GET_RF_AGC() with the corresponding function.
	-# The range of RF AGC value is (-pow(2, 13)) ~ (pow(2, 13) - 1).

*/
typedef int
(*ATSC_DEMOD_FP_GET_RF_AGC)(
	ATSC_DEMOD_MODULE *pDemod,
	long *pRfAgc
);


/**

@brief   ATSC demod IF AGC getting function pointer

One can use ATSC_DEMOD_FP_GET_IF_AGC() to get ATSC demod IF AGC value.


@param [in]    pDemod   The demod module pointer
@param [out]   pIfAgc   Pointer to an allocated memory for storing IF AGC value


@retval   FUNCTION_SUCCESS   Get demod IF AGC value successfully.
@retval   FUNCTION_ERROR     Get demod IF AGC value unsuccessfully.


@note
	-# Demod building function will set ATSC_DEMOD_FP_GET_IF_AGC() with the corresponding function.
	-# The range of IF AGC value is (-pow(2, 13)) ~ (pow(2, 13) - 1).

*/
typedef int
(*ATSC_DEMOD_FP_GET_IF_AGC)(
	ATSC_DEMOD_MODULE *pDemod,
	long *pIfAgc
);


/**

@brief   ATSC demod digital AGC getting function pointer

One can use ATSC_DEMOD_FP_GET_DI_AGC() to get ATSC demod digital AGC value.


@param [in]    pDemod   The demod module pointer
@param [out]   pDiAgc   Pointer to an allocated memory for storing digital AGC value


@retval   FUNCTION_SUCCESS   Get demod digital AGC value successfully.
@retval   FUNCTION_ERROR     Get demod digital AGC value unsuccessfully.


@note
	-# Demod building function will set ATSC_DEMOD_FP_GET_DI_AGC() with the corresponding function.
	-# The range of digital AGC value is 0 ~ (pow(2, 13) - 1).

*/
typedef int
(*ATSC_DEMOD_FP_GET_DI_AGC)(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned long *pDiAgc
);


/**

@brief   ATSC demod TR offset getting function pointer

One can use ATSC_DEMOD_FP_GET_TR_OFFSET_PPM() to get TR offset in ppm.


@param [in]    pDemod         The demod module pointer
@param [out]   pTrOffsetPpm   Pointer to an allocated memory for storing TR offset in ppm


@retval   FUNCTION_SUCCESS   Get demod TR offset successfully.
@retval   FUNCTION_ERROR     Get demod TR offset unsuccessfully.


@note
	-# Demod building function will set ATSC_DEMOD_FP_GET_TR_OFFSET_PPM() with the corresponding function.

*/
typedef int
(*ATSC_DEMOD_FP_GET_TR_OFFSET_PPM)(
	ATSC_DEMOD_MODULE *pDemod,
	long *pTrOffsetPpm
);


typedef int
(*ATSC_DEMOD_FP_GET_TR_FS_FREQ_SUB_OFFSET_PPM)(
	ATSC_DEMOD_MODULE *pDemod,
	long *pTrOffsetPpm
);


/**

@brief   ATSC demod CR offset getting function pointer

One can use ATSC_DEMOD_FP_GET_CR_OFFSET_HZ() to get CR offset in Hz.


@param [in]    pDemod        The demod module pointer
@param [out]   pCrOffsetHz   Pointer to an allocated memory for storing CR offset in Hz


@retval   FUNCTION_SUCCESS   Get demod CR offset successfully.
@retval   FUNCTION_ERROR     Get demod CR offset unsuccessfully.


@note
	-# Demod building function will set ATSC_DEMOD_FP_GET_CR_OFFSET_HZ() with the corresponding function.

*/
typedef int
(*ATSC_DEMOD_FP_GET_TR_LOOP_SEL)(
	ATSC_DEMOD_MODULE *pDemod,
	long *pTrLoopSel
);
typedef int
(*ATSC_DEMOD_FP_GET_CR_OFFSET_HZ)(
	ATSC_DEMOD_MODULE *pDemod,
	long *pCrOffsetHz
);


/**

@brief   ATSC demod AAGC lock asking function pointer

One can use ATSC_DEMOD_FP_IS_AAGC_LOCKED() to ask ATSC demod if it is AAGC-locked.


@param [in]    pDemod    The demod module pointer
@param [out]   pAnswer   Pointer to an allocated memory for storing answer


@retval   FUNCTION_SUCCESS   Perform AAGC lock asking to demod successfully.
@retval   FUNCTION_ERROR     Perform AAGC lock asking to demod unsuccessfully.


@note
	-# Demod building function will set ATSC_DEMOD_FP_IS_AAGC_LOCKED() with the corresponding function.

*/
typedef int
(*ATSC_DEMOD_FP_IS_AAGC_LOCKED)(
	ATSC_DEMOD_MODULE *pDemod,
	int *pAnswer
);


/**

@brief   ATSC demod frame lock asking function pointer

One can use ATSC_DEMOD_FP_IS_FRAME_LOCKED() to ask ATSC demod if it is frame-locked.


@param [in]    pDemod    The demod module pointer
@param [out]   pAnswer   Pointer to an allocated memory for storing answer


@retval   FUNCTION_SUCCESS   Perform frame lock asking to demod successfully.
@retval   FUNCTION_ERROR     Perform frame lock asking to demod unsuccessfully.


@note
	-# Demod building function will set ATSC_DEMOD_FP_IS_FRAME_LOCKED() with the corresponding function.

*/
typedef int
(*ATSC_DEMOD_FP_IS_FRAME_LOCKED)(
	ATSC_DEMOD_MODULE *pDemod,
	int *pAnswer
);

/**

@brief   ATSC demod tr lock asking function pointer

One can use ATSC_DEMOD_FP_IS_TR_LOCKED() to ask ATSC demod if it is tr-locked.


@param [in]    pDemod    The demod module pointer
@param [out]   pAnswer   Pointer to an allocated memory for storing answer


@retval   FUNCTION_SUCCESS   Perform tr lock asking to demod successfully.
@retval   FUNCTION_ERROR     Perform tr lock asking to demod unsuccessfully.


@note
	-# Demod building function will set ATSC_DEMOD_FP_IS_TR_LOCKED() with the corresponding function.

*/
typedef int
(*ATSC_DEMOD_FP_IS_TR_LOCKED)(
	ATSC_DEMOD_MODULE *pDemod,
	int *pAnswer
);


/**

@brief   ATSC demod Cr lock asking function pointer

One can use ATSC_DEMOD_FP_IS_CR_LOCKED() to ask ATSC demod if it is cr-locked.


@param [in]    pDemod    The demod module pointer
@param [out]   pAnswer   Pointer to an allocated memory for storing answer


@retval   FUNCTION_SUCCESS   Perform cr lock asking to demod successfully.
@retval   FUNCTION_ERROR     Perform cr lock asking to demod unsuccessfully.


@note
	-# Demod building function will set ATSC_DEMOD_FP_IS_CR_LOCKED() with the corresponding function.

*/
typedef int
(*ATSC_DEMOD_FP_IS_CR_LOCKED)(
	ATSC_DEMOD_MODULE *pDemod,
	int *pAnswer
);

/**

@brief   ATSC demod inner lock asking function pointer

One can use ATSC_DEMOD_FP_IS_INNER_LOCKED() to ask ATSC demod if it is inner-locked.


@param [in]    pDemod    The demod module pointer
@param [out]   pAnswer   Pointer to an allocated memory for storing answer


@retval   FUNCTION_SUCCESS   Perform inner lock asking to demod successfully.
@retval   FUNCTION_ERROR     Perform inner lock asking to demod unsuccessfully.


@note
	-# Demod building function will set ATSC_DEMOD_FP_IS_INNER_LOCKED() with the corresponding function.

*/
typedef int
(*ATSC_DEMOD_FP_IS_INNER_LOCKED)(
	ATSC_DEMOD_MODULE *pDemod,
	int *pAnswer
);

/**

@brief   ATSC demod Nosig asking function pointer

One can use ATSC_DEMOD_FP_IS_NO_SIG() to ask ATSC demod if it is Nosig.


@param [in]    pDemod    The demod module pointer
@param [out]   pAnswer   Pointer to an allocated memory for storing answer


@retval   FUNCTION_SUCCESS   Perform no sig asking to demod successfully.
@retval   FUNCTION_ERROR     Perform no sig asking to demod unsuccessfully.


@note
	-# Demod building function will set ATSC_DEMOD_FP_IS_INNER_LOCKED() with the corresponding function.

*/
typedef int
(*ATSC_DEMOD_FP_IS_NO_SIG)(
	ATSC_DEMOD_MODULE *pDemod,
	int *pAnswer
);


/**

@brief   ATSC demod error rate value getting function pointer

One can use ATSC_DEMOD_FP_GET_ERROR_RATE() to get error rate value.


@param [in]    pDemod                The demod module pointer
@param [in]    TestVolume            Test volume for setting
@param [in]    WaitTimeMsMax         Maximum waiting time in ms
@param [out]   pByteErrorRateNum     Pointer to an allocated memory for storing BER numerator
@param [out]   pByteErrorRateDen     Pointer to an allocated memory for storing BER denominator
@param [out]   pPacketErrorRateNum   Pointer to an allocated memory for storing PER numerator
@param [out]   pPacketErrorRateDen   Pointer to an allocated memory for storing PER denominator


@retval   FUNCTION_SUCCESS   Get demod error rate value successfully.
@retval   FUNCTION_ERROR     Get demod error rate value unsuccessfully.


@note
	-# Demod building function will set ATSC_DEMOD_FP_GET_ERROR_RATE() with the corresponding function.
	-# The error test packet number is pow(2, (2 * TestVolume + 4)).

*/
typedef int
(*ATSC_DEMOD_FP_GET_ERROR_RATE)(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned long TestVolume,
	unsigned int WaitTimeMsMax,
	unsigned long *pByteErrorRateNum,
	unsigned long *pByteErrorRateDen,
	unsigned long *pPacketErrorRateNum,
	unsigned long *pPacketErrorRateDen
);


/**

@brief   ATSC demod SNR getting function pointer

One can use ATSC_DEMOD_FP_GET_SNR_DB() to get SNR in dB.


@param [in]    pDemod      The demod module pointer
@param [out]   pSnrDbNum   Pointer to an allocated memory for storing SNR dB numerator
@param [out]   pSnrDbDen   Pointer to an allocated memory for storing SNR dB denominator


@retval   FUNCTION_SUCCESS   Get demod SNR successfully.
@retval   FUNCTION_ERROR     Get demod SNR unsuccessfully.


@note
	-# Demod building function will set ATSC_DEMOD_FP_GET_SNR_DB() with the corresponding function.

*/
typedef int
(*ATSC_DEMOD_FP_GET_SNR_DB)(
	ATSC_DEMOD_MODULE *pDemod,
	long *pSnrDbNum,
	long *pSnrDbDen
);


/**

@brief   ATSC demod signal strength getting function pointer

One can use ATSC_DEMOD_FP_GET_SIGNAL_STRENGTH() to get signal strength.


@param [in]    pDemod            The demod module pointer
@param [out]   pSignalStrength   Pointer to an allocated memory for storing signal strength (value = 0 ~ 100)


@retval   FUNCTION_SUCCESS   Get demod signal strength successfully.
@retval   FUNCTION_ERROR     Get demod signal strength unsuccessfully.


@note
	-# Demod building function will set ATSC_DEMOD_FP_GET_SIGNAL_STRENGTH() with the corresponding function.

*/
typedef int
(*ATSC_DEMOD_FP_GET_SIGNAL_STRENGTH)(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned long *pSignalStrength
);


/**

@brief   ATSC demod signal quality getting function pointer

One can use ATSC_DEMOD_FP_GET_SIGNAL_QUALITY() to get signal quality.


@param [in]    pDemod           The demod module pointer
@param [out]   pSignalQuality   Pointer to an allocated memory for storing signal quality (value = 0 ~ 100)


@retval   FUNCTION_SUCCESS   Get demod signal quality successfully.
@retval   FUNCTION_ERROR     Get demod signal quality unsuccessfully.


@note
	-# Demod building function will set ATSC_DEMOD_FP_GET_SIGNAL_QUALITY() with the corresponding function.

*/
typedef int
(*ATSC_DEMOD_FP_GET_SIGNAL_QUALITY)(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned long *pSignalQuality
);


/**

@brief   ATSC demod updating function pointer

One can use ATSC_DEMOD_FP_UPDATE_FUNCTION() to update demod register setting.


@param [in]   pDemod   The demod module pointer


@retval   FUNCTION_SUCCESS   Update demod setting successfully.
@retval   FUNCTION_ERROR     Update demod setting unsuccessfully.


@note
	-# Demod building function will set ATSC_DEMOD_FP_UPDATE_FUNCTION() with the corresponding function.



@par Example:
@code


#include "demod_pseudo.h"


int main(void)
{
	ATSC_DEMOD_MODULE *pDemod;
	ATSC_DEMOD_MODULE QamDemodModuleMemory;
	PSEUDO_EXTRA_MODULE PseudoExtraModuleMemory;


	// Build pseudo demod module.
	BuildPseudoDemodModule(&pDemod, &QamDemodModuleMemory, &PseudoExtraModuleMemory);

	...

	// Execute ResetFunction() before demod software reset.
	pDemod->ResetFunction(pDemod);

	// Reset demod by software.
	pDemod->SoftwareReset(pDemod);

	...

	return 0;
}


void PeriodicallyExecutingFunction
{
	// Executing UpdateFunction() periodically.
	pDemod->UpdateFunction(pDemod);
}


@endcode

*/
typedef int
(*ATSC_DEMOD_FP_UPDATE_FUNCTION)(
	ATSC_DEMOD_MODULE *pDemod
);


/**

@brief   ATSC demod reseting function pointer

One can use ATSC_DEMOD_FP_RESET_FUNCTION() to reset demod register setting.


@param [in]   pDemod   The demod module pointer


@retval   FUNCTION_SUCCESS   Reset demod setting successfully.
@retval   FUNCTION_ERROR     Reset demod setting unsuccessfully.


@note
	-# Demod building function will set ATSC_DEMOD_FP_RESET_FUNCTION() with the corresponding function.



@par Example:
@code


#include "demod_pseudo.h"


int main(void)
{
	ATSC_DEMOD_MODULE *pDemod;
	ATSC_DEMOD_MODULE QamDemodModuleMemory;
	PSEUDO_EXTRA_MODULE PseudoExtraModuleMemory;


	// Build pseudo demod module.
	BuildPseudoDemodModule(&pDemod, &QamDemodModuleMemory, &PseudoExtraModuleMemory);

	...

	// Execute ResetFunction() before demod software reset.
	pDemod->ResetFunction(pDemod);

	// Reset demod by software.
	pDemod->SoftwareReset(pDemod);

	...

	return 0;
}


void PeriodicallyExecutingFunction
{
	// Executing UpdateFunction() periodically.
	pDemod->UpdateFunction(pDemod);
}


@endcode

*/
typedef int
(*ATSC_DEMOD_FP_RESET_FUNCTION)(
	ATSC_DEMOD_MODULE *pDemod
);


/// ATSC demod module structure
struct ATSC_DEMOD_MODULE_TAG {
	// Private variables
	int           DemodType;
	unsigned char DeviceAddr;
	unsigned long CrystalFreqHz;
	int           TsInterfaceMode;

	unsigned long IfFreqHz;
	int           SpectrumMode;

	int IsIfFreqHzSet;
	int IsSpectrumModeSet;

	void *pExtra;									///<   Demod extra module used by driving module
	BASE_INTERFACE_MODULE *pBaseInterface;
	I2C_BRIDGE_MODULE *pI2cBridge;


	// Demod register table
	union {
		ATSC_REG_ENTRY_ADDR_8BIT  Addr8Bit[ATSC_REG_TABLE_LEN_MAX];
		ATSC_REG_ENTRY_ADDR_16BIT Addr16Bit[ATSC_REG_TABLE_LEN_MAX];
	}
	RegTable;


	// Demod I2C function pointers
	union {
		ATSC_DEMOD_REG_ACCESS_ADDR_8BIT  Addr8Bit;
		ATSC_DEMOD_REG_ACCESS_ADDR_16BIT Addr16Bit;
	}
	RegAccess;


	// Demod manipulating function pointers
	ATSC_DEMOD_FP_GET_DEMOD_TYPE        GetDemodType;
	ATSC_DEMOD_FP_GET_DEVICE_ADDR       GetDeviceAddr;
	ATSC_DEMOD_FP_GET_CRYSTAL_FREQ_HZ   GetCrystalFreqHz;

	ATSC_DEMOD_FP_IS_CONNECTED_TO_I2C   IsConnectedToI2c;
	ATSC_DEMOD_FP_SOFTWARE_RESET        SoftwareReset;
	ATSC_DEMOD_FP_TR_PHASE_INC_RESET    TrPhaseIncReset;

	ATSC_DEMOD_FP_INITIALIZE            Initialize;
	ATSC_DEMOD_FP_SET_IF_FREQ_HZ        SetIfFreqHz;
	ATSC_DEMOD_FP_SET_SPECTRUM_MODE     SetSpectrumMode;
	ATSC_DEMOD_FP_GET_IF_FREQ_HZ        GetIfFreqHz;
	ATSC_DEMOD_FP_GET_SPECTRUM_MODE     GetSpectrumMode;

	ATSC_DEMOD_FP_GET_RF_AGC            GetRfAgc;
	ATSC_DEMOD_FP_GET_IF_AGC            GetIfAgc;
	ATSC_DEMOD_FP_GET_DI_AGC            GetDiAgc;
	ATSC_DEMOD_FP_GET_TR_OFFSET_PPM     GetTrOffsetPpm;
	ATSC_DEMOD_FP_GET_TR_OFFSET_PPM		GetTrFsFreqSubOffsetPpm;
	ATSC_DEMOD_FP_GET_CR_OFFSET_HZ      GetCrOffsetHz;

	ATSC_DEMOD_FP_IS_AAGC_LOCKED        IsAagcLocked;
	ATSC_DEMOD_FP_IS_FRAME_LOCKED       IsFrameLocked;

	ATSC_DEMOD_FP_IS_TR_LOCKED          IsTrLocked;
	ATSC_DEMOD_FP_IS_CR_LOCKED          IsCrLocked;
	ATSC_DEMOD_FP_GET_TR_LOOP_SEL        GetTrLoopSel;
	ATSC_DEMOD_FP_IS_INNER_LOCKED       IsInnerLocked;
	ATSC_DEMOD_FP_IS_NO_SIG             IsNoSig;

	ATSC_DEMOD_FP_GET_ERROR_RATE        GetErrorRate;
	ATSC_DEMOD_FP_GET_SNR_DB            GetSnrDb;

	ATSC_DEMOD_FP_GET_SIGNAL_STRENGTH   GetSignalStrength;
	ATSC_DEMOD_FP_GET_SIGNAL_QUALITY    GetSignalQuality;

	ATSC_DEMOD_FP_UPDATE_FUNCTION       UpdateFunction;
	ATSC_DEMOD_FP_RESET_FUNCTION        ResetFunction;
};


// ATSC demod default I2C functions for 8-bit address
int
atsc_demod_addr_8bit_default_SetRegPage(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned long PageNo
);

int
atsc_demod_addr_8bit_default_SetRegBytes(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	const unsigned char *pWritingBytes,
	unsigned long ByteNum
);

int
atsc_demod_addr_8bit_default_GetRegBytes(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char *pReadingBytes,
	unsigned long ByteNum
);

int
atsc_demod_addr_8bit_default_SetRegMaskBits(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	const unsigned long WritingValue
);

int
atsc_demod_addr_8bit_default_GetRegMaskBits(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	unsigned long *pReadingValue
);

int
atsc_demod_addr_8bit_default_SetRegBits(
	ATSC_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

int
atsc_demod_addr_8bit_default_GetRegBits(
	ATSC_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

int
atsc_demod_addr_8bit_default_SetRegBitsWithPage(
	ATSC_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

int
atsc_demod_addr_8bit_default_GetRegBitsWithPage(
	ATSC_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

// ATSC demod default I2C functions for 16-bit address
int
atsc_demod_addr_16bit_default_SetRegBytes(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	const unsigned char *pWritingBytes,
	unsigned long ByteNum
);

int
atsc_demod_addr_16bit_default_GetRegBytes(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char *pReadingBytes,
	unsigned long ByteNum
);

int
atsc_demod_addr_16bit_default_SetRegMaskBits(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	const unsigned long WritingValue
);

int
atsc_demod_addr_16bit_default_GetRegMaskBits(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	unsigned long *pReadingValue
);

int
atsc_demod_addr_16bit_default_SetRegBits(
	ATSC_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
);

int
atsc_demod_addr_16bit_default_GetRegBits(
	ATSC_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
);

// ATSC demod default manipulaing functions
void
atsc_demod_default_GetDemodType(
	ATSC_DEMOD_MODULE *pDemod,
	int *pDemodType
);

void
atsc_demod_default_GetDeviceAddr(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned char *pDeviceAddr
);

void
atsc_demod_default_GetCrystalFreqHz(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned long *pCrystalFreqHz
);

int
atsc_demod_default_GetIfFreqHz(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned long *pIfFreqHz
);

int
atsc_demod_default_GetSpectrumMode(
	ATSC_DEMOD_MODULE *pDemod,
	int *pSpectrumMode
);

#define REALTEK_R_ATSC_BASE_PRINT_LVL_DBG      0
#define REALTEK_R_ATSC_BASE_PRINT_LVL_INFO     1
#define REALTEK_R_ATSC_BASE_PRINT_LVL_WARNING  2

#ifndef REALTEK_R_ATSC_BASE_PRINT_LVL
#define REALTEK_R_ATSC_BASE_PRINT_LVL          REALTEK_R_ATSC_BASE_PRINT_LVL_INFO
#endif

#define REALTEK_R_ATSC_BASE_DBG(fmt, args...)          rtd_printk(KERN_DEBUG, "DEMO", "ATSC_BASE_DEBUG, " fmt, ##args);
#define REALTEK_R_ATSC_BASE_INFO(fmt, args...)       rtd_printk(KERN_INFO, "DEMO", "ATSC_BASE_INFO, " fmt, ##args);
#define REALTEK_R_ATSC_BASE_WARNING(fmt, args...)    rtd_printk(KERN_WARNING, "DEMO", "ATSC_BASE_WARNING, " fmt, ##args);

#ifdef __cplusplus
}
#endif
#endif
