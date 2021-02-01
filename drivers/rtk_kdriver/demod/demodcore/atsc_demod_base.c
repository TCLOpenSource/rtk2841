/**
@file

@brief   ATSC demod default function definition

ATSC demod default functions.
*/
//#include <stdio.h>
//#include <string.h>
#include "atsc_demod_base.h"

/**

@see   ATSC_DEMOD_FP_SET_REG_PAGE

*/
int
atsc_demod_addr_8bit_default_SetRegPage(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned long PageNo
)
{
	BASE_INTERFACE_MODULE *pBaseInterface;

	unsigned char DeviceAddr;
	unsigned char WritingBytes[LEN_2_BYTE];

	// Get base interface.
	pBaseInterface = pDemod->pBaseInterface;

	// Get demod device address.
	pDemod->GetDeviceAddr(pDemod, &DeviceAddr);

	// Set demod register page with page number.
	// Note: The I2C format of demod register page setting is as follows:
	//       start_bit + (DeviceAddr | writing_bit) + ATSC_DEMOD_PAGE_REG_ADDR + PageNo + stop_bit
	WritingBytes[0] = ATSC_DEMOD_PAGE_REG_ADDR;
	WritingBytes[1] = (unsigned char)PageNo;

	if (pBaseInterface->I2cWrite(pBaseInterface, DeviceAddr, WritingBytes, LEN_2_BYTE) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/**

@see   ATSC_DEMOD_FP_SET_REG_BYTES

*/
int
atsc_demod_addr_8bit_default_SetRegBytes(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	const unsigned char *pWritingBytes,
	unsigned long ByteNum
)
{
	BASE_INTERFACE_MODULE *pBaseInterface;
	unsigned long i, j;
	unsigned char DeviceAddr;
	unsigned char WritingBuffer[I2C_BUFFER_LEN];
	unsigned long WritingByteNum, WritingByteNumMax, WritingByteNumRem;
	unsigned char RegWritingAddr;

	// Get base interface.
	pBaseInterface = pDemod->pBaseInterface;

	// Get demod I2C device address.
	pDemod->GetDeviceAddr(pDemod, &DeviceAddr);

	// Calculate maximum writing byte number.
	WritingByteNumMax = pBaseInterface->I2cWritingByteNumMax - LEN_1_BYTE;

	// Set demod register bytes with writing bytes.
	// Note: Set demod register bytes considering maximum writing byte number.
	for (i = 0; i < ByteNum; i += WritingByteNumMax) {
		// Set register writing address.
		RegWritingAddr = (unsigned char)(RegStartAddr + i);

		// Calculate remainder writing byte number.
		WritingByteNumRem = ByteNum - i;

		// Determine writing byte number.
		WritingByteNum = (WritingByteNumRem > WritingByteNumMax) ? WritingByteNumMax : WritingByteNumRem;

		// Set writing buffer.
		// Note: The I2C format of demod register byte setting is as follows:
		//       start_bit + (DeviceAddr | writing_bit) + RegWritingAddr + writing_bytes (WritingByteNum bytes) + stop_bit
		WritingBuffer[0] = RegWritingAddr;

		for (j = 0; j < WritingByteNum; j++)
			WritingBuffer[LEN_1_BYTE + j] = pWritingBytes[i + j];

		// Set demod register bytes with writing buffer.
		if (pBaseInterface->I2cWrite(pBaseInterface, DeviceAddr, WritingBuffer, WritingByteNum + LEN_1_BYTE) !=
			FUNCTION_SUCCESS)
			goto error_status_set_demod_registers;
	}

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/**

@see   ATSC_DEMOD_FP_GET_REG_BYTES

*/
int
atsc_demod_addr_8bit_default_GetRegBytes(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char *pReadingBytes,
	unsigned long ByteNum
)
{
	BASE_INTERFACE_MODULE *pBaseInterface;
	unsigned long i;
	unsigned char DeviceAddr;
	unsigned long ReadingByteNum, ReadingByteNumMax, ReadingByteNumRem;
	unsigned char RegReadingAddr;

	// Get base interface.
	pBaseInterface = pDemod->pBaseInterface;

	// Get demod I2C device address.
	pDemod->GetDeviceAddr(pDemod, &DeviceAddr);

	// Calculate maximum reading byte number.
	ReadingByteNumMax = pBaseInterface->I2cReadingByteNumMax;

	// Get demod register bytes.
	// Note: Get demod register bytes considering maximum reading byte number.
	for (i = 0; i < ByteNum; i += ReadingByteNumMax) {
		// Set register reading address.
		RegReadingAddr = (unsigned char)(RegStartAddr + i);

		// Calculate remainder reading byte number.
		ReadingByteNumRem = ByteNum - i;

		// Determine reading byte number.
		ReadingByteNum = (ReadingByteNumRem > ReadingByteNumMax) ? ReadingByteNumMax : ReadingByteNumRem;

		// Set demod register reading address.
		// Note: The I2C format of demod register reading address setting is as follows:
		//       start_bit + (DeviceAddr | writing_bit) + RegReadingAddr + stop_bit
		if (pBaseInterface->I2cWrite(pBaseInterface, DeviceAddr, &RegReadingAddr, LEN_1_BYTE) != FUNCTION_SUCCESS)
			goto error_status_set_demod_register_reading_address;

		// Get demod register bytes.
		// Note: The I2C format of demod register byte getting is as follows:
		//       start_bit + (DeviceAddr | reading_bit) + reading_bytes (ReadingByteNum bytes) + stop_bit
		if (pBaseInterface->I2cRead(pBaseInterface, DeviceAddr, &pReadingBytes[i], ReadingByteNum) != FUNCTION_SUCCESS)
			goto error_status_get_demod_registers;
	}

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
error_status_set_demod_register_reading_address:
	return FUNCTION_ERROR;
}


/**

@see   ATSC_DEMOD_FP_SET_REG_MASK_BITS

*/
int
atsc_demod_addr_8bit_default_SetRegMaskBits(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	const unsigned long WritingValue
)
{
	int i;
	unsigned char ReadingBytes[LEN_4_BYTE];
	unsigned char WritingBytes[LEN_4_BYTE];
	unsigned char ByteNum;
	unsigned long Mask;
	unsigned char Shift;
	unsigned long Value;

	// Calculate writing byte number according to MSB.
	ByteNum = Msb / BYTE_BIT_NUM + LEN_1_BYTE;

	// Generate mask and shift according to MSB and LSB.
	Mask = 0;

	for (i = Lsb; i < (unsigned char)(Msb + 1); i++)
		Mask |= 0x1 << i;

	Shift = Lsb;

	// Generate unsigned integer value for demod register writing.
	if (((Msb % 8) == 7) && ((Lsb % 8) == 0)) {
		// Generate unsigned integer value for byte-wise case.
		Value = (WritingValue << Shift) & Mask;
	} else {
		// Generate unsigned integer value for bit-wise case.

		// Get demod register bytes according to register start adddress and byte number.
		if (pDemod->RegAccess.Addr8Bit.GetRegBytes(pDemod, RegStartAddr, ReadingBytes, ByteNum) != FUNCTION_SUCCESS)
			goto error_status_get_demod_registers;

		// Combine reading bytes into an unsigned integer value.
		// Note: Put lower address byte on value LSB.
		//       Put upper address byte on value MSB.
		Value = 0;

		for (i = 0; i < ByteNum; i++)
			Value |= (unsigned long)ReadingBytes[i] << (BYTE_SHIFT * i);

		// Reserve unsigned integer value unmask bit with mask and inlay writing value into it.
		Value &= ~Mask;
		Value |= (WritingValue << Shift) & Mask;
	}

	// Separate unsigned integer value into writing bytes.
	// Note: Pick up lower address byte from value LSB.
	//       Pick up upper address byte from value MSB.
	for (i = 0; i < ByteNum; i++)
		WritingBytes[i] = (unsigned char)((Value >> (BYTE_SHIFT * i)) & BYTE_MASK);

	// Write demod register bytes with writing bytes.
	if (pDemod->RegAccess.Addr8Bit.SetRegBytes(pDemod, RegStartAddr, WritingBytes, ByteNum) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/**

@see   ATSC_DEMOD_FP_GET_REG_MASK_BITS

*/
int
atsc_demod_addr_8bit_default_GetRegMaskBits(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned char RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	unsigned long *pReadingValue
)
{
	int i;
	unsigned char ReadingBytes[LEN_4_BYTE];
	unsigned char ByteNum;
	unsigned long Mask;
	unsigned char Shift;
	unsigned long Value;

	// Calculate writing byte number according to MSB.
	ByteNum = Msb / BYTE_BIT_NUM + LEN_1_BYTE;

	// Generate mask and shift according to MSB and LSB.
	Mask = 0;

	for (i = Lsb; i < (unsigned char)(Msb + 1); i++)
		Mask |= 0x1 << i;

	Shift = Lsb;

	// Get demod register bytes according to register start adddress and byte number.
	if (pDemod->RegAccess.Addr8Bit.GetRegBytes(pDemod, RegStartAddr, ReadingBytes, ByteNum) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	// Combine reading bytes into an unsigned integer value.
	// Note: Put lower address byte on value LSB.
	//       Put upper address byte on value MSB.
	Value = 0;

	for (i = 0; i < ByteNum; i++)
		Value |= (unsigned long)ReadingBytes[i] << (BYTE_SHIFT * i);

	// Get register bits from unsigned integaer value with mask and shift
	*pReadingValue = (Value & Mask) >> Shift;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/**

@see   ATSC_DEMOD_FP_SET_REG_BITS

*/
int
atsc_demod_addr_8bit_default_SetRegBits(
	ATSC_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
)
{
	unsigned char RegStartAddr;
	unsigned char Msb;
	unsigned char Lsb;

	// Check if register bit name is available.
	if (pDemod->RegTable.Addr8Bit[RegBitName].IsAvailable == NO)
		goto error_status_register_bit_name;

	// Get register start address, MSB, and LSB from register table with register bit name key.
	RegStartAddr = pDemod->RegTable.Addr8Bit[RegBitName].RegStartAddr;
	Msb          = pDemod->RegTable.Addr8Bit[RegBitName].Msb;
	Lsb          = pDemod->RegTable.Addr8Bit[RegBitName].Lsb;

	// Set register mask bits.
	if (pDemod->RegAccess.Addr8Bit.SetRegMaskBits(pDemod, RegStartAddr, Msb, Lsb, WritingValue) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_register_bit_name:
error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/**

@see   ATSC_DEMOD_FP_GET_REG_BITS

*/
int
atsc_demod_addr_8bit_default_GetRegBits(
	ATSC_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
)
{
	unsigned char RegStartAddr;
	unsigned char Msb;
	unsigned char Lsb;

	// Check if register bit name is available.
	if (pDemod->RegTable.Addr8Bit[RegBitName].IsAvailable == NO)
		goto error_status_register_bit_name;

	// Get register start address, MSB, and LSB from register table with register bit name key.
	RegStartAddr = pDemod->RegTable.Addr8Bit[RegBitName].RegStartAddr;
	Msb          = pDemod->RegTable.Addr8Bit[RegBitName].Msb;
	Lsb          = pDemod->RegTable.Addr8Bit[RegBitName].Lsb;

	// Get register mask bits.
	if (pDemod->RegAccess.Addr8Bit.GetRegMaskBits(pDemod, RegStartAddr, Msb, Lsb, pReadingValue) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	return FUNCTION_SUCCESS;

error_status_register_bit_name:
error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/**

@see   ATSC_DEMOD_FP_SET_REG_BITS_WITH_PAGE

*/
int
atsc_demod_addr_8bit_default_SetRegBitsWithPage(
	ATSC_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
)
{
	unsigned long PageNo;

	// Get register page number from register table with register bit name key.
	PageNo = pDemod->RegTable.Addr8Bit[RegBitName].PageNo;

	// Set register page number.
	if (pDemod->RegAccess.Addr8Bit.SetRegPage(pDemod, PageNo) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	// Set register mask bits with register bit name key.
	if (pDemod->RegAccess.Addr8Bit.SetRegBits(pDemod, RegBitName, WritingValue) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/**

@see   ATSC_DEMOD_FP_GET_REG_BITS_WITH_PAGE

*/
int
atsc_demod_addr_8bit_default_GetRegBitsWithPage(
	ATSC_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
)
{
	unsigned long PageNo;

	// Get register page number from register table with register bit name key.
	PageNo = pDemod->RegTable.Addr8Bit[RegBitName].PageNo;

	// Set register page number.
	if (pDemod->RegAccess.Addr8Bit.SetRegPage(pDemod, PageNo) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	// Get register mask bits with register bit name key.
	if (pDemod->RegAccess.Addr8Bit.GetRegBits(pDemod, RegBitName, pReadingValue) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/**

@see   ATSC_DEMOD_FP_SET_REG_BYTES

*/
int
atsc_demod_addr_16bit_default_SetRegBytes(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	const unsigned char *pWritingBytes,
	unsigned long ByteNum
)
{
	BASE_INTERFACE_MODULE *pBaseInterface;
	unsigned long i, j;
	unsigned char DeviceAddr;
	unsigned char WritingBuffer[I2C_BUFFER_LEN];
	unsigned long WritingByteNum, WritingByteNumMax, WritingByteNumRem;
	unsigned short RegWritingAddr;

	// Get base interface.
	pBaseInterface = pDemod->pBaseInterface;

	// Get demod I2C device address.
	pDemod->GetDeviceAddr(pDemod, &DeviceAddr);

	// Calculate maximum writing byte number.
	WritingByteNumMax = pBaseInterface->I2cWritingByteNumMax - LEN_1_BYTE;

	// Set demod register bytes with writing bytes.
	// Note: Set demod register bytes considering maximum writing byte number.
	for (i = 0; i < ByteNum; i += WritingByteNumMax) {
		// Set register writing address.
		RegWritingAddr = (unsigned short)(RegStartAddr + i);

		// Calculate remainder writing byte number.
		WritingByteNumRem = ByteNum - i;

		// Determine writing byte number.
		WritingByteNum = (WritingByteNumRem > WritingByteNumMax) ? WritingByteNumMax : WritingByteNumRem;

		// Set writing buffer.
		// Note: The I2C format of demod register byte setting is as follows:
		//       start_bit + (DeviceAddr | writing_bit) + RegWritingAddrMsb + RegWritingAddrLsb +
		//       writing_bytes (WritingByteNum bytes) + stop_bit
		WritingBuffer[0] = (RegWritingAddr >> BYTE_SHIFT) & BYTE_MASK;
		WritingBuffer[1] = RegWritingAddr & BYTE_MASK;

		for (j = 0; j < WritingByteNum; j++)
			WritingBuffer[LEN_2_BYTE + j] = pWritingBytes[i + j];

		// Set demod register bytes with writing buffer.
		if (pBaseInterface->I2cWrite(pBaseInterface, DeviceAddr, WritingBuffer, WritingByteNum + LEN_2_BYTE) !=
			FUNCTION_SUCCESS)
			goto error_status_set_demod_registers;
	}

	return FUNCTION_SUCCESS;

error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/**

@see   ATSC_DEMOD_FP_GET_REG_BYTES

*/
int
atsc_demod_addr_16bit_default_GetRegBytes(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char *pReadingBytes,
	unsigned long ByteNum
)
{
	BASE_INTERFACE_MODULE *pBaseInterface;

	unsigned long i;
	unsigned char DeviceAddr;
	unsigned long ReadingByteNum, ReadingByteNumMax, ReadingByteNumRem;
	unsigned short RegReadingAddr;
	unsigned char WritingBuffer[LEN_2_BYTE];

	// Get base interface.
	pBaseInterface = pDemod->pBaseInterface;

	// Get demod I2C device address.
	pDemod->GetDeviceAddr(pDemod, &DeviceAddr);

	// Calculate maximum reading byte number.
	ReadingByteNumMax = pBaseInterface->I2cReadingByteNumMax;

	// Get demod register bytes.
	// Note: Get demod register bytes considering maximum reading byte number.
	for (i = 0; i < ByteNum; i += ReadingByteNumMax) {
		// Set register reading address.
		RegReadingAddr = (unsigned short)(RegStartAddr + i);

		// Calculate remainder reading byte number.
		ReadingByteNumRem = ByteNum - i;

		// Determine reading byte number.
		ReadingByteNum = (ReadingByteNumRem > ReadingByteNumMax) ? ReadingByteNumMax : ReadingByteNumRem;

		// Set demod register reading address.
		// Note: The I2C format of demod register reading address setting is as follows:
		//       start_bit + (DeviceAddr | writing_bit) + RegReadingAddrMsb + RegReadingAddrLsb + stop_bit
		WritingBuffer[0] = (RegReadingAddr >> BYTE_SHIFT) & BYTE_MASK;
		WritingBuffer[1] = RegReadingAddr & BYTE_MASK;

		if (pBaseInterface->I2cWrite(pBaseInterface, DeviceAddr, WritingBuffer, LEN_2_BYTE) != FUNCTION_SUCCESS)
			goto error_status_set_demod_register_reading_address;

		// Get demod register bytes.
		// Note: The I2C format of demod register byte getting is as follows:
		//       start_bit + (DeviceAddr | reading_bit) + reading_bytes (ReadingByteNum bytes) + stop_bit
		if (pBaseInterface->I2cRead(pBaseInterface, DeviceAddr, &pReadingBytes[i], ReadingByteNum) != FUNCTION_SUCCESS)
			goto error_status_get_demod_registers;
	}

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
error_status_set_demod_register_reading_address:
	return FUNCTION_ERROR;
}


/**

@see   ATSC_DEMOD_FP_SET_REG_MASK_BITS

*/
int
atsc_demod_addr_16bit_default_SetRegMaskBits(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	const unsigned long WritingValue
)
{
	int i;
	unsigned char ReadingBytes[LEN_4_BYTE];
	unsigned char WritingBytes[LEN_4_BYTE];
	unsigned char ByteNum;
	unsigned long Mask;
	unsigned char Shift;
	unsigned long Value;

	// Calculate writing byte number according to MSB.
	ByteNum = Msb / BYTE_BIT_NUM + LEN_1_BYTE;

	// Generate mask and shift according to MSB and LSB.
	Mask = 0;

	for (i = Lsb; i < (unsigned char)(Msb + 1); i++)
		Mask |= 0x1 << i;

	Shift = Lsb;

	// Get demod register bytes according to register start adddress and byte number.
	if (pDemod->RegAccess.Addr16Bit.GetRegBytes(pDemod, RegStartAddr, ReadingBytes, ByteNum) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	// Combine reading bytes into an unsigned integer value.
	// Note: Put lower address byte on value LSB.
	//       Put upper address byte on value MSB.
	Value = 0;

	for (i = 0; i < ByteNum; i++)
		Value |= (unsigned long)ReadingBytes[i] << (BYTE_SHIFT * i);

	// Reserve unsigned integer value unmask bit with mask and inlay writing value into it.
	Value &= ~Mask;
	Value |= (WritingValue << Shift) & Mask;

	// Separate unsigned integer value into writing bytes.
	// Note: Pick up lower address byte from value LSB.
	//       Pick up upper address byte from value MSB.
	for (i = 0; i < ByteNum; i++)
		WritingBytes[i] = (unsigned char)((Value >> (BYTE_SHIFT * i)) & BYTE_MASK);

	// Write demod register bytes with writing bytes.
	if (pDemod->RegAccess.Addr16Bit.SetRegBytes(pDemod, RegStartAddr, WritingBytes, ByteNum) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/**

@see   ATSC_DEMOD_FP_GET_REG_MASK_BITS

*/
int
atsc_demod_addr_16bit_default_GetRegMaskBits(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned short RegStartAddr,
	unsigned char Msb,
	unsigned char Lsb,
	unsigned long *pReadingValue
)
{
	int i;
	unsigned char ReadingBytes[LEN_4_BYTE];
	unsigned char ByteNum;
	unsigned long Mask;
	unsigned char Shift;
	unsigned long Value;

	// Calculate writing byte number according to MSB.
	ByteNum = Msb / BYTE_BIT_NUM + LEN_1_BYTE;

	// Generate mask and shift according to MSB and LSB.
	Mask = 0;

	for (i = Lsb; i < (unsigned char)(Msb + 1); i++)
		Mask |= 0x1 << i;

	Shift = Lsb;

	// Get demod register bytes according to register start adddress and byte number.
	if (pDemod->RegAccess.Addr16Bit.GetRegBytes(pDemod, RegStartAddr, ReadingBytes, ByteNum) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	// Combine reading bytes into an unsigned integer value.
	// Note: Put lower address byte on value LSB.
	//       Put upper address byte on value MSB.
	Value = 0;

	for (i = 0; i < ByteNum; i++)
		Value |= (unsigned long)ReadingBytes[i] << (BYTE_SHIFT * i);

	// Get register bits from unsigned integaer value with mask and shift
	*pReadingValue = (Value & Mask) >> Shift;

	return FUNCTION_SUCCESS;

error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/**

@see   ATSC_DEMOD_FP_SET_REG_BITS

*/
int
atsc_demod_addr_16bit_default_SetRegBits(
	ATSC_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
)
{
	unsigned short RegStartAddr;
	unsigned char Msb;
	unsigned char Lsb;

	// Check if register bit name is available.
	if (pDemod->RegTable.Addr16Bit[RegBitName].IsAvailable == NO)
		goto error_status_register_bit_name;

	// Get register start address, MSB, and LSB from base register table with register bit name key.
	RegStartAddr = pDemod->RegTable.Addr16Bit[RegBitName].RegStartAddr;
	Msb          = pDemod->RegTable.Addr16Bit[RegBitName].Msb;
	Lsb          = pDemod->RegTable.Addr16Bit[RegBitName].Lsb;

	// Set register mask bits.
	if (pDemod->RegAccess.Addr16Bit.SetRegMaskBits(pDemod, RegStartAddr, Msb, Lsb, WritingValue) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

	return FUNCTION_SUCCESS;

error_status_register_bit_name:
error_status_set_demod_registers:
	return FUNCTION_ERROR;
}


/**

@see   ATSC_DEMOD_FP_GET_REG_BITS

*/
int
atsc_demod_addr_16bit_default_GetRegBits(
	ATSC_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
)
{
	unsigned short RegStartAddr;
	unsigned char Msb;
	unsigned char Lsb;

	// Check if register bit name is available.
	if (pDemod->RegTable.Addr16Bit[RegBitName].IsAvailable == NO)
		goto error_status_register_bit_name;

	// Get register start address, MSB, and LSB from base register table with register bit name key.
	RegStartAddr = pDemod->RegTable.Addr16Bit[RegBitName].RegStartAddr;
	Msb          = pDemod->RegTable.Addr16Bit[RegBitName].Msb;
	Lsb          = pDemod->RegTable.Addr16Bit[RegBitName].Lsb;

	// Get register mask bits.
	if (pDemod->RegAccess.Addr16Bit.GetRegMaskBits(pDemod, RegStartAddr, Msb, Lsb, pReadingValue) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

	return FUNCTION_SUCCESS;

error_status_register_bit_name:
error_status_get_demod_registers:
	return FUNCTION_ERROR;
}


/**

@see   ATSC_DEMOD_FP_GET_DEMOD_TYPE

*/
void
atsc_demod_default_GetDemodType(
	ATSC_DEMOD_MODULE *pDemod,
	int *pDemodType
)
{
	// Get demod type from demod module.
	*pDemodType = pDemod->DemodType;

	return;
}


/**

@see   ATSC_DEMOD_FP_GET_DEVICE_ADDR

*/
void
atsc_demod_default_GetDeviceAddr(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned char *pDeviceAddr
)
{
	// Get demod I2C device address from demod module.
	*pDeviceAddr = pDemod->DeviceAddr;

	return;
}


/**

@see   ATSC_DEMOD_FP_GET_CRYSTAL_FREQ_HZ

*/
void
atsc_demod_default_GetCrystalFreqHz(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned long *pCrystalFreqHz
)
{
	// Get demod crystal frequency in Hz from demod module.
	*pCrystalFreqHz = pDemod->CrystalFreqHz;


	return;
}


/**

@see   ATSC_DEMOD_FP_GET_IF_FREQ_HZ

*/
int
atsc_demod_default_GetIfFreqHz(
	ATSC_DEMOD_MODULE *pDemod,
	unsigned long *pIfFreqHz
)
{
	// Get demod IF frequency in Hz from demod module.
	if (pDemod->IsIfFreqHzSet != YES)
		goto error_status_get_demod_if_frequency;

	*pIfFreqHz = pDemod->IfFreqHz;

	return FUNCTION_SUCCESS;

error_status_get_demod_if_frequency:
	return FUNCTION_ERROR;
}


/**

@see   ATSC_DEMOD_FP_GET_SPECTRUM_MODE

*/
int
atsc_demod_default_GetSpectrumMode(
	ATSC_DEMOD_MODULE *pDemod,
	int *pSpectrumMode
)
{
	// Get demod spectrum mode from demod module.
	if (pDemod->IsSpectrumModeSet != YES)
		goto error_status_get_demod_spectrum_mode;

	*pSpectrumMode = pDemod->SpectrumMode;

	return FUNCTION_SUCCESS;

error_status_get_demod_spectrum_mode:
	return FUNCTION_ERROR;
}

