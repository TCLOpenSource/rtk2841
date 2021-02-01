/**

@file

@brief   DVBC demod default function definition

DVBC demod default functions.

*/
//#include <stdio.h>
//#include <string.h>
#include "dvbc_demod_base.h"
#include "dvbc_tvcore_registers.h"
#include "message_func_rtk.h"

#if 0
/**

@see   DVBC_DEMOD_FP_SET_REG_PAGE

*/
int
dvbc_demod_addr_8bit_default_SetRegPage(
	DVBC_DEMOD_MODULE *pDemod,
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
	//       start_bit + (DeviceAddr | writing_bit) + DVBC_DEMOD_PAGE_REG_ADDR + PageNo + stop_bit
	WritingBytes[0] = DVBC_DEMOD_PAGE_REG_ADDR;
	WritingBytes[1] = (unsigned char)PageNo;

	if(pBaseInterface->I2cWrite(pBaseInterface, DeviceAddr, WritingBytes, LEN_2_BYTE) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;


	return FUNCTION_SUCCESS;


error_status_set_demod_registers:
	return FUNCTION_ERROR;
}





/**

@see   DVBC_DEMOD_FP_SET_REG_BYTES

*/
int
dvbc_demod_addr_8bit_default_SetRegBytes(
	DVBC_DEMOD_MODULE *pDemod,
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
	for(i = 0; i < ByteNum; i += WritingByteNumMax)
	{
		// Set register writing address.
		RegWritingAddr = (unsigned char)(RegStartAddr + i);

		// Calculate remainder writing byte number.
		WritingByteNumRem = ByteNum - i;

		// Determine writing byte number.
		WritingByteNum = (WritingByteNumRem > WritingByteNumMax) ? WritingByteNumMax : WritingByteNumRem;


		// Set writing buffer.
		// Note: The I2C format of demod register byte setting is as follows:
		//       start_bit + (DeviceAddr | writing_bit) + RegWritingAddr + writing_bytes (WritingByteNum bytes) +
		//       stop_bit
		WritingBuffer[0] = RegWritingAddr;

		for(j = 0; j < WritingByteNum; j++)
			WritingBuffer[LEN_1_BYTE + j] = pWritingBytes[i + j];


		// Set demod register bytes with writing buffer.
		if(pBaseInterface->I2cWrite(pBaseInterface, DeviceAddr, WritingBuffer, WritingByteNum + LEN_1_BYTE) != FUNCTION_SUCCESS)
			goto error_status_set_demod_registers;
	}


	return FUNCTION_SUCCESS;


error_status_set_demod_registers:
	return FUNCTION_ERROR;
}





/**

@see   DVBC_DEMOD_FP_GET_REG_BYTES

*/
int
dvbc_demod_addr_8bit_default_GetRegBytes(
	DVBC_DEMOD_MODULE *pDemod,
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
	for(i = 0; i < ByteNum; i += ReadingByteNumMax)
	{
		// Set register reading address.
		RegReadingAddr = (unsigned char)(RegStartAddr + i);

		// Calculate remainder reading byte number.
		ReadingByteNumRem = ByteNum - i;

		// Determine reading byte number.
		ReadingByteNum = (ReadingByteNumRem > ReadingByteNumMax) ? ReadingByteNumMax : ReadingByteNumRem;


		// Set demod register reading address.
		// Note: The I2C format of demod register reading address setting is as follows:
		//       start_bit + (DeviceAddr | writing_bit) + RegReadingAddr + stop_bit
		if(pBaseInterface->I2cWrite(pBaseInterface, DeviceAddr, &RegReadingAddr, LEN_1_BYTE) != FUNCTION_SUCCESS)
			goto error_status_set_demod_register_reading_address;

		// Get demod register bytes.
		// Note: The I2C format of demod register byte getting is as follows:
		//       start_bit + (DeviceAddr | reading_bit) + reading_bytes (ReadingByteNum bytes) + stop_bit
		if(pBaseInterface->I2cRead(pBaseInterface, DeviceAddr, &pReadingBytes[i], ReadingByteNum) != FUNCTION_SUCCESS)
			goto error_status_get_demod_registers;
	}


	return FUNCTION_SUCCESS;


error_status_get_demod_registers:
error_status_set_demod_register_reading_address:
	return FUNCTION_ERROR;
}





/**

@see   DVBC_DEMOD_FP_SET_REG_MASK_BITS

*/
int
dvbc_demod_addr_8bit_default_SetRegMaskBits(
	DVBC_DEMOD_MODULE *pDemod,
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

	for(i = Lsb; i < (unsigned char)(Msb + 1); i++)
		Mask |= 0x1 << i;

	Shift = Lsb;


	// Get demod register bytes according to register start adddress and byte number.
	if(pDemod->RegAccess.Addr8Bit.GetRegBytes(pDemod, RegStartAddr, ReadingBytes, ByteNum) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;


	// Combine reading bytes into an unsigned integer value.
	// Note: Put lower address byte on value LSB.
	//       Put upper address byte on value MSB.
	Value = 0;

	for(i = 0; i < ByteNum; i++)
		Value |= (unsigned long)ReadingBytes[i] << (BYTE_SHIFT * i);


	// Reserve unsigned integer value unmask bit with mask and inlay writing value into it.
	Value &= ~Mask;
	Value |= (WritingValue << Shift) & Mask;


	// Separate unsigned integer value into writing bytes.
	// Note: Pick up lower address byte from value LSB.
	//       Pick up upper address byte from value MSB.
	for(i = 0; i < ByteNum; i++)
		WritingBytes[i] = (unsigned char)((Value >> (BYTE_SHIFT * i)) & BYTE_MASK);


	// Write demod register bytes with writing bytes.
	if(pDemod->RegAccess.Addr8Bit.SetRegBytes(pDemod, RegStartAddr, WritingBytes, ByteNum) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;


	return FUNCTION_SUCCESS;


error_status_get_demod_registers:
error_status_set_demod_registers:
	return FUNCTION_ERROR;
}





/**

@see   DVBC_DEMOD_FP_GET_REG_MASK_BITS

*/
int
dvbc_demod_addr_8bit_default_GetRegMaskBits(
	DVBC_DEMOD_MODULE *pDemod,
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

	for(i = Lsb; i < (unsigned char)(Msb + 1); i++)
		Mask |= 0x1 << i;

	Shift = Lsb;


	// Get demod register bytes according to register start adddress and byte number.
	if(pDemod->RegAccess.Addr8Bit.GetRegBytes(pDemod, RegStartAddr, ReadingBytes, ByteNum) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;


	// Combine reading bytes into an unsigned integer value.
	// Note: Put lower address byte on value LSB.
	//       Put upper address byte on value MSB.
	Value = 0;

	for(i = 0; i < ByteNum; i++)
		Value |= (unsigned long)ReadingBytes[i] << (BYTE_SHIFT * i);


	// Get register bits from unsigned integaer value with mask and shift
	*pReadingValue = (Value & Mask) >> Shift;


	return FUNCTION_SUCCESS;


error_status_get_demod_registers:
	return FUNCTION_ERROR;
}





/**

@see   DVBC_DEMOD_FP_SET_REG_BITS

*/
int
dvbc_demod_addr_8bit_default_SetRegBits(
	DVBC_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
	)
{
	unsigned char RegStartAddr;
	unsigned char Msb;
	unsigned char Lsb;


	// Check if register bit name is available.
	if(pDemod->BaseRegTable.Addr8Bit[RegBitName].IsAvailable == NO)
		goto error_status_register_bit_name;


	// Get register start address, MSB, and LSB from base register table with register bit name key.
	RegStartAddr = pDemod->BaseRegTable.Addr8Bit[RegBitName].RegStartAddr;
	Msb          = pDemod->BaseRegTable.Addr8Bit[RegBitName].Msb;
	Lsb          = pDemod->BaseRegTable.Addr8Bit[RegBitName].Lsb;


	// Set register mask bits.
	if(pDemod->RegAccess.Addr8Bit.SetRegMaskBits(pDemod, RegStartAddr, Msb, Lsb, WritingValue) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;


	return FUNCTION_SUCCESS;


error_status_register_bit_name:
error_status_set_demod_registers:
	return FUNCTION_ERROR;
}





/**

@see   DVBC_DEMOD_FP_GET_REG_BITS

*/
int
dvbc_demod_addr_8bit_default_GetRegBits(
	DVBC_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
	)
{
	unsigned char RegStartAddr;
	unsigned char Msb;
	unsigned char Lsb;


	// Check if register bit name is available.
	if(pDemod->BaseRegTable.Addr8Bit[RegBitName].IsAvailable == NO)
		goto error_status_register_bit_name;


	// Get register start address, MSB, and LSB from base register table with register bit name key.
	RegStartAddr = pDemod->BaseRegTable.Addr8Bit[RegBitName].RegStartAddr;
	Msb          = pDemod->BaseRegTable.Addr8Bit[RegBitName].Msb;
	Lsb          = pDemod->BaseRegTable.Addr8Bit[RegBitName].Lsb;


	// Get register mask bits.
	if(pDemod->RegAccess.Addr8Bit.GetRegMaskBits(pDemod, RegStartAddr, Msb, Lsb, pReadingValue) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;


	return FUNCTION_SUCCESS;


error_status_register_bit_name:
error_status_get_demod_registers:
	return FUNCTION_ERROR;
}





/**

@see   DVBC_DEMOD_FP_SET_REG_BITS_WITH_PAGE

*/
int
dvbc_demod_addr_8bit_default_SetRegBitsWithPage(
	DVBC_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
	)
{
	unsigned char PageNo;


	// Get register page number from base register table with register bit name key.
	PageNo = pDemod->BaseRegTable.Addr8Bit[RegBitName].PageNo;


	// Set register page number.
	if(pDemod->RegAccess.Addr8Bit.SetRegPage(pDemod, PageNo) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;


	// Set register mask bits with register bit name key.
	if(pDemod->RegAccess.Addr8Bit.SetRegBits(pDemod, RegBitName, WritingValue) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;


	return FUNCTION_SUCCESS;


error_status_set_demod_registers:
	return FUNCTION_ERROR;
}





/**

@see   DVBC_DEMOD_FP_GET_REG_BITS_WITH_PAGE

*/
int
dvbc_demod_addr_8bit_default_GetRegBitsWithPage(
	DVBC_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
	)
{
	unsigned char PageNo;


	// Get register page number from base register table with register bit name key.
	PageNo = pDemod->BaseRegTable.Addr8Bit[RegBitName].PageNo;


	// Set register page number.
	if(pDemod->RegAccess.Addr8Bit.SetRegPage(pDemod, PageNo) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;


	// Get register mask bits with register bit name key.
	if(pDemod->RegAccess.Addr8Bit.GetRegBits(pDemod, RegBitName, pReadingValue) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;


	return FUNCTION_SUCCESS;


error_status_set_demod_registers:
error_status_get_demod_registers:
	return FUNCTION_ERROR;
}
#endif


#if 0
/**

@see   DVBC_DEMOD_FP_SET_REG_BYTES

*/
int
dvbc_demod_addr_16bit_default_SetRegBytes(
	DVBC_DEMOD_MODULE *pDemod,
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
	for(i = 0; i < ByteNum; i += WritingByteNumMax)
	{
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

		for(j = 0; j < WritingByteNum; j++)
			WritingBuffer[LEN_2_BYTE + j] = pWritingBytes[i + j];


		// Set demod register bytes with writing buffer.
		if(pBaseInterface->I2cWrite(pBaseInterface, DeviceAddr, WritingBuffer, WritingByteNum + LEN_2_BYTE) !=
			FUNCTION_SUCCESS)
			goto error_status_set_demod_registers;
	}


	return FUNCTION_SUCCESS;


error_status_set_demod_registers:
	return FUNCTION_ERROR;
}





/**

@see   DVBC_DEMOD_FP_GET_REG_BYTES

*/
int
dvbc_demod_addr_16bit_default_GetRegBytes(
	DVBC_DEMOD_MODULE *pDemod,
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
	for(i = 0; i < ByteNum; i += ReadingByteNumMax)
	{
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

		if(pBaseInterface->I2cWrite(pBaseInterface, DeviceAddr, WritingBuffer, LEN_2_BYTE) != FUNCTION_SUCCESS)
			goto error_status_set_demod_register_reading_address;

		// Get demod register bytes.
		// Note: The I2C format of demod register byte getting is as follows:
		//       start_bit + (DeviceAddr | reading_bit) + reading_bytes (ReadingByteNum bytes) + stop_bit
		if(pBaseInterface->I2cRead(pBaseInterface, DeviceAddr, &pReadingBytes[i], ReadingByteNum) != FUNCTION_SUCCESS)
			goto error_status_get_demod_registers;
	}


	return FUNCTION_SUCCESS;


error_status_get_demod_registers:
error_status_set_demod_register_reading_address:
	return FUNCTION_ERROR;
}





/**

@see   DVBC_DEMOD_FP_SET_REG_MASK_BITS

*/
int
dvbc_demod_addr_16bit_default_SetRegMaskBits(
	DVBC_DEMOD_MODULE *pDemod,
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

	for(i = Lsb; i < (unsigned char)(Msb + 1); i++)
		Mask |= 0x1 << i;

	Shift = Lsb;


	// Get demod register bytes according to register start adddress and byte number.
	if(pDemod->RegAccess.Addr16Bit.GetRegBytes(pDemod, RegStartAddr, ReadingBytes, ByteNum) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;


	// Combine reading bytes into an unsigned integer value.
	// Note: Put lower address byte on value LSB.
	//       Put upper address byte on value MSB.
	Value = 0;

	for(i = 0; i < ByteNum; i++)
		Value |= (unsigned long)ReadingBytes[i] << (BYTE_SHIFT * i);


	// Reserve unsigned integer value unmask bit with mask and inlay writing value into it.
	Value &= ~Mask;
	Value |= (WritingValue << Shift) & Mask;


	// Separate unsigned integer value into writing bytes.
	// Note: Pick up lower address byte from value LSB.
	//       Pick up upper address byte from value MSB.
	for(i = 0; i < ByteNum; i++)
		WritingBytes[i] = (unsigned char)((Value >> (BYTE_SHIFT * i)) & BYTE_MASK);


	// Write demod register bytes with writing bytes.
	if(pDemod->RegAccess.Addr16Bit.SetRegBytes(pDemod, RegStartAddr, WritingBytes, ByteNum) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;


	return FUNCTION_SUCCESS;


error_status_get_demod_registers:
error_status_set_demod_registers:
	return FUNCTION_ERROR;
}





/**

@see   DVBC_DEMOD_FP_GET_REG_MASK_BITS

*/
int
dvbc_demod_addr_16bit_default_GetRegMaskBits(
	DVBC_DEMOD_MODULE *pDemod,
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

	for(i = Lsb; i < (unsigned char)(Msb + 1); i++)
		Mask |= 0x1 << i;

	Shift = Lsb;


	// Get demod register bytes according to register start adddress and byte number.
	if(pDemod->RegAccess.Addr16Bit.GetRegBytes(pDemod, RegStartAddr, ReadingBytes, ByteNum) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;


	// Combine reading bytes into an unsigned integer value.
	// Note: Put lower address byte on value LSB.
	//       Put upper address byte on value MSB.
	Value = 0;

	for(i = 0; i < ByteNum; i++)
		Value |= (unsigned long)ReadingBytes[i] << (BYTE_SHIFT * i);


	// Get register bits from unsigned integaer value with mask and shift
	*pReadingValue = (Value & Mask) >> Shift;


	return FUNCTION_SUCCESS;


error_status_get_demod_registers:
	return FUNCTION_ERROR;
}





/**

@see   DVBC_DEMOD_FP_SET_REG_BITS

*/
int
dvbc_demod_addr_16bit_default_SetRegBits(
	DVBC_DEMOD_MODULE *pDemod,
	int RegBitName,
	const unsigned long WritingValue
	)
{
	unsigned short RegStartAddr;
	unsigned char Msb;
	unsigned char Lsb;


	// Check if register bit name is available.
	if(pDemod->BaseRegTable.Addr16Bit[RegBitName].IsAvailable == NO)
		goto error_status_register_bit_name;


	// Get register start address, MSB, and LSB from base register table with register bit name key.
	RegStartAddr = pDemod->BaseRegTable.Addr16Bit[RegBitName].RegStartAddr;
	Msb          = pDemod->BaseRegTable.Addr16Bit[RegBitName].Msb;
	Lsb          = pDemod->BaseRegTable.Addr16Bit[RegBitName].Lsb;


	// Set register mask bits.
	if(pDemod->RegAccess.Addr16Bit.SetRegMaskBits(pDemod, RegStartAddr, Msb, Lsb, WritingValue) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;


	return FUNCTION_SUCCESS;


error_status_register_bit_name:
error_status_set_demod_registers:
	return FUNCTION_ERROR;
}





/**

@see   DVBC_DEMOD_FP_GET_REG_BITS

*/
int
dvbc_demod_addr_16bit_default_GetRegBits(
	DVBC_DEMOD_MODULE *pDemod,
	int RegBitName,
	unsigned long *pReadingValue
	)
{
	unsigned short RegStartAddr;
	unsigned char Msb;
	unsigned char Lsb;


	// Check if register bit name is available.
	if(pDemod->BaseRegTable.Addr16Bit[RegBitName].IsAvailable == NO)
		goto error_status_register_bit_name;


	// Get register start address, MSB, and LSB from base register table with register bit name key.
	RegStartAddr = pDemod->BaseRegTable.Addr16Bit[RegBitName].RegStartAddr;
	Msb          = pDemod->BaseRegTable.Addr16Bit[RegBitName].Msb;
	Lsb          = pDemod->BaseRegTable.Addr16Bit[RegBitName].Lsb;


	// Get register mask bits.
	if(pDemod->RegAccess.Addr16Bit.GetRegMaskBits(pDemod, RegStartAddr, Msb, Lsb, pReadingValue) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;


	return FUNCTION_SUCCESS;


error_status_register_bit_name:
error_status_get_demod_registers:
	return FUNCTION_ERROR;
}
#endif


void
dvbc_demod_default_GetDemodType(
	DVBC_DEMOD_MODULE *pDemod,
	int *pDemodType
	)
{
	// Get demod type from demod module.
	*pDemodType = pDemod->DemodType;


	return;
}


void
dvbc_demod_default_GetDeviceAddr(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned char *pDeviceAddr
	)
{
	// Get demod I2C device address from demod module.
	*pDeviceAddr = pDemod->DeviceAddr;


	return;
}


void
dvbc_demod_default_GetCrystalFreqHz(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned long *pCrystalFreqHz
	)
{
	// Get demod crystal frequency in Hz from demod module.
	*pCrystalFreqHz = pDemod->CrystalFreqHz;


	return;
}

// Common Function
int
realtek_i_dvbc_common_CheckRpuReady(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *IsRpuReady
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgCheckRpuReady(IsRpuReady) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    return FUNCTION_SUCCESS;

error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbc_common_PingRpu(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *IsLive
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgPingRpu(IsLive) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    return FUNCTION_SUCCESS;

error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbc_common_ShutDown(
	DVBC_DEMOD_MODULE *pDemod
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgShutDown() != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    return FUNCTION_SUCCESS;

error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbc_common_ActivateCore(
	DVBC_DEMOD_MODULE *pDemod
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgActivateCore(0, 0) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    return FUNCTION_SUCCESS;

error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbc_common_DeactivateCore(
	DVBC_DEMOD_MODULE *pDemod
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgDeactivateCore(0, 0) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    return FUNCTION_SUCCESS;

error_status_get_demod_registers:
    return FUNCTION_ERROR;
}

int
realtek_i_dvbc_common_SwitchToBuffer(
	DVBC_DEMOD_MODULE *pDemod
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    if(MsgSwitchToBuffered() != FUNCTION_SUCCESS)
    	goto error_status_switch_to_buffer;

    return FUNCTION_SUCCESS;
	
error_status_switch_to_buffer:
    return FUNCTION_ERROR;
}

/*
    This read-only register identifies the demodulation standard and the version of 
    the demodulator core software.
    Bits 0...7 contain a miniscule id value.
    Bits 8�K15 contain a minor id value.
    Bits 16�K23 contain a major id value.
    Bits 24...31 indicate the demodulation standard
    For example the TV_REG_DEMOD_ID register for version 2.1.1 of a DVB-T demodulator
    would contain 0x01020101.
*/
int
realtek_i_dvbc_common_GetDemodInfo(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *DemodType
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    unsigned int DemodInfo;

    if(MsgGetReg(TV_REG_DEMOD_ID, 0, &DemodInfo) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    //*DemodType = (REALTEK_I_DEMOD_TYPE*)((DemodInfo&0xFF000000)>>24);
    *DemodType = ((DemodInfo&0xFF000000)>>24);
    /*
    switch((REALTEK_I_DEMOD_TYPE*)DemodType)
    {
        case UCC_STANDARD_NOT_SIGNALLED:
        case UCC_STANDARD_DVBT:
        case UCC_STANDARD_DVBH:
        case UCC_STANDARD_ISDBT_1SEG:
        case UCC_STANDARD_ISDBT_3SEG:
        case UCC_STANDARD_ISDBT_13SEG:
        case UCC_STANDARD_DAB:
        case UCC_STANDARD_FM:
        case UCC_STANDARD_ATSC:
        case UCC_STANDARD_DVBC:
        case UCC_STANDARD_J83B:
        case UCC_STANDARD_ISDBC:
        case UCC_STANDARD_DVBT2:
        case UCC_STANDARD_DVBS:
        case UCC_STANDARD_DVBS2:
        case UCC_STANDARD_ISDBS:
        case UCC_STANDARD_GB206:
        case UCC_STANDARD_ATV:
        case UCC_STANDARD_DVBC_ISDBC:
        default:
            break;
    }
    */

    return FUNCTION_SUCCESS;

error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
    This read-only register is used to contain a unique identifier for a particular build of 
    the demodulator core software.
*/
int
realtek_i_dvbc_common_GetBuildId(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *BuildId
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(TV_REG_BUILD_ID, 0, BuildId) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    return FUNCTION_SUCCESS;

error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
    The control register is the primary operating control of a TV demodulator.
    This register is a command register. 
    Command values are written to this register to:
    - Control the major operating modes of the demodulator.
    - Request updates to certain status registers, which are only updated on demand
    - Reset status monitoring counters
    - Load parameters which modify the internal behaviour of a demodulator.
*/
/*
    Stop command �V TV operations stop and the demodulator returns to the INITIALISED state.
*/
int
realtek_i_dvbc_common_DemodCtrlStopCmd(
	DVBC_DEMOD_MODULE *pDemod
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgSetCmdReg(TV_REG_CONTROL, 0, TV_CMD_STOP) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;

error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


/*
    Detect command �V the TV demodulator enters the DETECTING state.
*/
int
realtek_i_dvbc_common_DemodCtrlDetectCmd(
	DVBC_DEMOD_MODULE *pDemod
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgSetCmdReg(TV_REG_CONTROL, 0, TV_CMD_DETECT) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;

error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


/*
    Run command �V the TV demodulator enters the ACQUIRING state.
*/
int
realtek_i_dvbc_common_DemodCtrlRunCmd(
	DVBC_DEMOD_MODULE *pDemod
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgSetCmdReg(TV_REG_CONTROL, 0, TV_CMD_RUN) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;

error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


/*
    Request update of the TV_REG_ACTIVE_TUNER_RSSI register.
    This command is ignored if the demodulator is inactive (in the INITIALISED state).
*/
int
realtek_i_dvbc_common_DemodCtrlUpdateRssiCmd(
	DVBC_DEMOD_MODULE *pDemod
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgSetCmdReg(TV_REG_CONTROL, 0, TV_CMD_UPDATE_RSSI) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;

error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


/*
    Reset counters and statistics. This command provides a universal way to reset 
    the counters and statistics registers provided by a demodulator.
    Exactly which registers are reset depends on the standard.
*/
int
realtek_i_dvbc_common_DemodCtrlResetCountersCmd(
	DVBC_DEMOD_MODULE *pDemod
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgSetCmdReg(TV_REG_CONTROL, 0, TV_CMD_RESET_COUNTERS) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;

error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


/*
    Update counters and statistics. This command provides a universal way to update
    the counters and statistics registers provided by a demodulator.
    Exactly which registers are updated depends on the standard.
*/
int
realtek_i_dvbc_common_DemodCtrlUpdateCountersCmd(
	DVBC_DEMOD_MODULE *pDemod
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgSetCmdReg(TV_REG_CONTROL, 0, TV_CMD_UPDATE_COUNTERS) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;

error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


/*
    Write TV_REG_AGC_PARAMS registers to the AGC system.
*/
int
realtek_i_dvbc_common_DemodCtrlSetAgcCmd(
	DVBC_DEMOD_MODULE *pDemod
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgSetCmdReg(TV_REG_CONTROL, 0, TV_CMD_SET_AGC) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;

error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


/*
    Update TV_REG_AGC_PARAMS registers with the active AGC parameter values.
*/
int
realtek_i_dvbc_common_DemodCtrlUpdateAgcCmd(
	DVBC_DEMOD_MODULE *pDemod
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgSetCmdReg(TV_REG_CONTROL, 0, TV_CMD_UPDATE_AGC) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;

error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


/*
    Run the standard-specific status query function.
*/
int
realtek_i_dvbc_common_DemodCtrlQueryStatusCmd(
	DVBC_DEMOD_MODULE *pDemod
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgSetCmdReg(TV_REG_CONTROL, 0, TV_CMD_QUERY_STATUS) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;

error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


/*
    The state register indicates the current operating state of the TV demodulator.
*/
int
realtek_i_dvbc_common_GetDemodStatus(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *DemodStatus
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(TV_REG_STATE, 0, DemodStatus) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    //DemodStatus = 0 : TV_STATE_DORMANT
    //DemodStatus = 1 : TV_STATE_INITIALISED
    //DemodStatus = 2 : TV_STATE_DETECTING
    //DemodStatus = 3 : TV_STATE_ACQUIRE
    //DemodStatus = 4 : TV_STATE_RE_DETECTING
    //DemodStatus = 5 : TV_STATE_DEMODULATING

    return FUNCTION_SUCCESS;

error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
    This register is used to set the RF tuner centre frequency.
    It is a command register.
*/
int
realtek_i_dvbc_common_SetTunerFreqCmd(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int TunerFreqHz
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    //Set the Tuner Frequency in Hz
    if(MsgSetCmdReg(TV_REG_TUNER_FREQ, 0, TunerFreqHz) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;

error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


/*
    This register is used to set the RF tuner bandwidth.
    Updates to the tuner bandwidth will not become effective until
    - TV_REG_TUNER_FREQ is written also. I.e. bandwidth changes and centre 
      frequency changes are always made together.
    - Completion of combined frequency and bandwidth update operations is indicated in
      TV_REG_TUNER_FREQ. You should check that TV_REG_TUNER_FREQ is ready for an update
      before writing to TV_REG_TUNER_BW. A bandwidth update may be missed if a frequency
      update (which implies a bandwidth update also) is still in progress.
*/
int
realtek_i_dvbc_common_SetTunerBandwidth(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int TunerBandwidthHz
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgSetReg(TV_REG_TUNER_BW, 0, TunerBandwidthHz) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;

error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


/*
    This register is used (in conjunction with TV_REG_TUNER_GRID_INCR) when the tuner is managed
    by the host processor, to describe a RF frequency grid to the demodulator.
    When a demodulator requests that the host makes a RF frequency change, it will limit such requests
    to frequencies satisfying: F = Base +- N*Incr, where N is an integer.
    Frequency gridding/filtering can be disabled by setting TV_REG_TUNER_GRID_INCR to 0 or 1.
*/
int
realtek_i_dvbc_common_SetTunerGridBase(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int TunerGridBaseHz
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgSetReg(TV_REG_TUNER_GRID_BASE, 0, TunerGridBaseHz) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;

error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


/*
    This register is used (in conjunction with TV_REG_TUNER_GRID_BASE) when the tuner is managed
    by the host processor, to describe a RF frequency grid to the demodulator.
    When a demodulator requests that the host makes a RF frequency change, it will limit such requests
    to frequencies satisfying: F = Base +- N*Incr, where N is an integer.
    Frequency gridding/filtering can be disabled by setting TV_REG_TUNER_GRID_INCR to 0 or 1.
*/
int
realtek_i_dvbc_common_SetTunerGridIncr(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int TunerGridIncrHz
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgSetReg(TV_REG_TUNER_GRID_INCR, 0, TunerGridIncrHz) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;

error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


/*
    Enables the notch filter and sets the centre frequency.
    This register should be written after setting the notch filter bandwidth in TV_REG_NOTCH_BW.
*/
//Set the Notch Bandwidth first, and then set the Notch Freq
int
realtek_i_dvbc_common_SetNotchFreqCmd(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int NotchFreqHz
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    unsigned int NotchSetting;

    NotchSetting = ((REALTEK_I_NOTCH_EN<<24)&0x80000000)|(NotchFreqHz&0x7FFFFFFF);
    if(MsgSetCmdReg(TV_REG_NOTCH_FREQ, 0, NotchSetting) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;

error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


/*
    Sets the notch filter bandwidth. The value written to this register does not become effective until
    TV_REG_NOTCH_FREQ is written, so this register should be written first, when setting up a notch filter.
    - Requested RF notch filter bandwidth. The notch filter bandwidth is specified by a control
      value in the range 0~87, where 0 selects the narrowest bandwidth (around Fs/20000) and
      87 the widest (around Fs/5). The SCP documentation explains notch filter controls in more
      detail.
*/
int
realtek_i_dvbc_common_SetNotchBandwidth(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int NotchBandwidth
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgSetReg(TV_REG_NOTCH_BW, 0, NotchBandwidth) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;

error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


/*
    This register contains the active tuner RF frequency. Often this will simply mirror the value written to
    TV_REG_TUNER_FREQ, but in some TV standards, the requested frequency may be adjusted by the
    demodulator. This register always contains the adjusted frequency.
*/
int
realtek_i_dvbc_common_GetActiveTunerFreq(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *ActiveFreqHz
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(TV_REG_ACTIVE_TUNER_FREQ, 0, ActiveFreqHz) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    return FUNCTION_SUCCESS;

error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
    This register contains the active tuner RF bandwidth. Often this will simply mirror the value written to
    TV_REG_TUNER_BW, but in some TV standards, the requested bandwidth may be adjusted by the
    demodulator. This register always contains the adjusted frequency.
*/
int
realtek_i_dvbc_common_GetActiveTunerBandwidth(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *ActiveBandwidth
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(TV_REG_ACTIVE_TUNER_BW, 0, ActiveBandwidth) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    return FUNCTION_SUCCESS;

error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
    This register indicates the desired tuner IF gain control value calculated by the demodulator. This
    value is calculated by the demodulator��s AGC algorithm and passed to the tuner driver��s gain setting
    function. The register is updated every time the demodulator calculates a gain value.
    The IF gain value is restricted to positive values in the range in the range 0..65535, corresponding to
    the minimum and maximum gains, respectively, that the tuner can apply. The gain value is directly
    proportional to the logarithm of the expected gain to be applied to the incoming signal. I.e., the value
    is proportional to the gain in dB.
*/
int
realtek_i_dvbc_common_GetActiveTunerGain(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *ActiveTunerGain
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(TV_REG_ACTIVE_TUNER_GAIN, 0, ActiveTunerGain) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    return FUNCTION_SUCCESS;

error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
    This register provides the received signal strength indication (RSSI) measured by a tuner.
    The register is updated when a TV_CMD_UPDATE_RSSI command is written to the TV_REG_CONTROL register.
    Valid RSSI values are positive integers in the range 0..32767.
    If the tuner is unable to provide a RSSI measurement, then the RSSI value will be reported as -1.
*/
int
realtek_i_dvbc_common_GetActiveTunerRssi(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *ActiveTunerRssi
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(TV_REG_ACTIVE_TUNER_RSSI, 0, ActiveTunerRssi) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    return FUNCTION_SUCCESS;

error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
    The TV_REG_AGC_PARAMS register is a multi-valued register containing a complete set of AGC
    parameters. Use of this register is governed by TV_CMD_SET_AGC and TV_CMD_UPDATE_AGC
    commands written to the TV_REG_CONTROL register. Just reading or writing TVREG_AGC_PARAMS
    alone has no effect.
    - To read the current AGC parameters, first write TV_CMD_UPDATE_AGC to TV_REG_CONTROL.
      Once the command is acknowledged, the working parameter values are available to read from
      TV_REG_AGC_PARAMS.
    - To change the current AGC parameters, first write the required values to TV_REG_AGC_PARAMS.
      Then write TV_CMD_SET_AGC to TV_REG_CONTROL. The new parameters will be effective once 
      the command is acknowledged.
    The items in the multi-valued TV_REG_AGC_PARAMS register are identified by index. Symbolic and
    numeric index values are listed in Table 6. 
*/
int
realtek_i_dvbc_common_SetAgcParams(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int AgcParam,
	unsigned int Index
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgSetReg(TV_REG_AGC_PARAMS, Index, AgcParam) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;

error_status_set_demod_registers:
    return FUNCTION_ERROR;
}

int
realtek_i_dvbc_common_GetAgcParams(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *AgcParam,
	unsigned int Index
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(TV_REG_AGC_PARAMS, Index, AgcParam) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    return FUNCTION_SUCCESS;

error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
    Changing the value in this register while a TV demodulator is running has an undefined effect.
    Normally this register should be set up prior to issuing a DETECT or RUN command, and left
    unchanged while the system is running.
    Bit0: 0 = TSO enabled, 1 = TSO disabled
    Bit1: 0 = parallel (byte stream) format, 1 = serial (bit stream) format
    Bit2: 0 = TSO clock phase normal, 1 = TSO clock phase inverted
    Bit3: 0 = Packets are padded to 204 bytes, 1 = Packets are 188 bytes
    Bit4~31:  Resverd    
*/
int
realtek_i_dvbc_common_SetTsConfig(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int IsTsDis,
	unsigned int IsSerial,
	unsigned int IsInv,
	unsigned int IsPacket188
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    unsigned int TsConfig = 0;

    TsConfig &= ~(REALTEK_I_TS_DIS_MASK|REALTEK_I_TS_SERIAL_MASK|REALTEK_I_TS_CLK_PHASE_INV_MASK|REALTEK_I_TS_PACKETS_188_MASK);
    if(IsTsDis)
        TsConfig |= REALTEK_I_TS_DIS_MASK;
    if(IsSerial)
        TsConfig |= REALTEK_I_TS_SERIAL_MASK;
    if(IsInv)
        TsConfig |= REALTEK_I_TS_CLK_PHASE_INV_MASK;
    if(IsPacket188)
        TsConfig |= REALTEK_I_TS_PACKETS_188_MASK;
    else
        TsConfig |= REALTEK_I_TS_CLOCK_GATE_MASK;

    if(MsgSetReg(TV_REG_TSO_CONFIG, 0, TsConfig) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;

error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


/*
    Typically digital TV standards will produce an output in the form of an MPEG transport stream which is
    output via a hardware port (The Transport Stream Output or TSO). TS packets are transferred
    asynchronously over this interface, so the clock rate is configured by the standard to be a little higher
    than the exact data rate measured for the input signal. By default, a 10% margin is allowed between
    the byte clock rate used and the minimum required. If desired, this margin may be reduced (for
    example, if there is a requirement to minimise clock speed or power) by programming this register
    with a margin in PPM (Parts per Million). If the margin is set too low then this may result in unreliable
    operation.
    Changing the value in this register while a TV demodulator is running has an undefined effect.
    Normally this register should be set up prior to issuing a DETECT or RUN command, and left
    unchanged while the system is running.
*/
int
realtek_i_dvbc_common_SetTsClkRateMargin(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int TsClkMargin
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgSetReg(TV_REG_TSO_CLK_RATE_MARGIN, 0, TsClkMargin) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;

error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


/*
    Typically digital TV standards will produce an output in the form of an MPEG transport stream which is
    output via a hardware port (The Transport Stream Output or TSO). TS packets are transferred
    asynchronously over this interface, so the clock rate is configured by the standard to be a little higher
    than the exact data rate measured for the input signal. This register, if configured with a non-zero
    value, can be used to ensure that this clock rate will never be set higher than a certain frequency (for
    example, to support downstream hardware which has a maximum frequency of operation).
    Changing the value in this register while a TV demodulator is running has an undefined effect.
    Normally this register should be set up prior to issuing a DETECT or RUN command, and left
    unchanged while the system is running.
*/
int
realtek_i_dvbc_common_SetTsClkRateMax(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int TsClkRateMax
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgSetReg(TV_REG_TSO_CLK_RATE_MAX, 0, TsClkRateMax) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;

error_status_set_demod_registers:
    return FUNCTION_ERROR;
} 


/*
    This register stores the time taken from DETECT/RUN command to the transition into the
    RE_DETECTING state (if no signal is found), or, the DEMODULATING state (when a signal is acquired).
*/
int
realtek_i_dvbc_common_GetDemodLockTime(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int *DemodLockTimeMs
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(TV_REG_LOCK_TIME, 0, DemodLockTimeMs) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    return FUNCTION_SUCCESS;

error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbc_common_SetHwRegValue(
	unsigned int Addr,
    unsigned int Val
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(SetHwRegValue(Addr, Val) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;

error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


int
realtek_i_dvbc_common_GetHwRegValue(
	unsigned int Addr,
    unsigned int *Val
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(GetHwRegValue(Addr, Val) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    return FUNCTION_SUCCESS;

error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
    Override the tunerConfig parameters
*/
realtek_i_dvbc_common_SetXmlTunerCfgOverride(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int TunerCfg
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgSetReg(TV_REG_TUNER_CFG_OVERRIDE, 0, TunerCfg) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;

error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


/*
    Override the platform's support package setIFgain function. The values in this register will only be
    used when tuner config override is in operation (see TV_REG_TUNER_CFG_OVERRIDE)
*/
realtek_i_dvbc_common_SetXmlTunerGainCtrl(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int TunerGainCtrl
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgSetReg(TV_REG_PFM_SET_IF_GAIN_CTRL, 0, TunerGainCtrl) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;

error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


/*
    Provide the current status of certain parameters within PFM_TUNER_PARAM_ENUM_T from
    platformAPI. Only the parameters listed below are supported. The values in this register will only be
    used when tuner config override is in operation (see TV_REG_TUNER_CFG_OVERRIDE)
*/
realtek_i_dvbc_common_SetXmlFlags(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int Flags
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgSetReg(TV_REG_PFM_FLAGS, 0, Flags) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;

error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


/*
    The current final IF frequency of the signal coming into the SCP. . The value in this register will only
    be used when tuner config override is in operation (see TV_REG_TUNER_CFG_OVERRIDE)
*/
realtek_i_dvbc_common_SetXmlIfFreq(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int IfFreq
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgSetReg(TV_REG_PFM_IF_FREQ, 0, IfFreq) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;

error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


/*
    Select whether the override registers listed below or values supplied by the platform support package.
*/
realtek_i_dvbc_common_SetXmlPlatformCfgOverride(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int PlatformCfg
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgSetReg(TV_REG_PFM_OVERRIDE, 0, PlatformCfg) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;

error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


/*
    Select whether the override registers listed below or values supplied by the platform support package.
*/
realtek_i_dvbc_common_SetXmlIfClk(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int IfClk
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgSetReg(TV_REG_PFM_IF_CLK_FREQUENCY, 0, IfClk) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;

error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


/*
    The clock frequency at which the LDPC decoder is currently running (if present).
*/
realtek_i_dvbc_common_SetXmlLdpcClk(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int LdpcClk
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgSetReg(TV_REG_PFM_LDPC_CLK_FREQUENCY, 0, LdpcClk) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;

error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


/*
    The clock frequency at which the UCC is currently running.
*/
realtek_i_dvbc_common_SetXmlUccClk(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int UccClk
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgSetReg(TV_REG_PFM_UCC_CLK_FREQUENCY, 0, UccClk) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;

error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


/*
    The clock frequency at which the MCU is currently running.
*/
realtek_i_dvbc_common_SetXmlMcuClk(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int McuClk
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgSetReg(TV_REG_PFM_MCU_CLK_FREQUENCY, 0, McuClk) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;

error_status_set_demod_registers:
    return FUNCTION_ERROR;
}

/*
    Direct write virtual register
*/
realtek_i_dvbc_common_SetVirtualRegister(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int RegAddr,
	unsigned int RegVal
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgSetReg(RegAddr, 0, RegVal) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;

error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


/*
    Direct read virtual register
*/
realtek_i_dvbc_common_GetVirtualRegister(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int RegAddr,
	unsigned int *RegVal
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(RegAddr, 0, RegVal) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    return FUNCTION_SUCCESS;

error_status_get_demod_registers:
    return FUNCTION_ERROR;
}


/*
    Direct write control virtual register
*/
realtek_i_dvbc_common_SetCtrlVirtualRegister(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int PriRegAddr,
	unsigned int SecRegAddr,
	unsigned int RegVal
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgSetReg(PriRegAddr, SecRegAddr, RegVal) != FUNCTION_SUCCESS)
		goto error_status_set_demod_registers;

    return FUNCTION_SUCCESS;

error_status_set_demod_registers:
    return FUNCTION_ERROR;
}


/*
    Direct read control virtual register
*/
realtek_i_dvbc_common_GetCtrlVirtualRegister(
	DVBC_DEMOD_MODULE *pDemod,
	unsigned int PriRegAddr,
	unsigned int SecRegAddr,
	unsigned int *RegVal
)
{
    REALTEK_I_DVBC_BASE_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
    
    if(MsgGetReg(PriRegAddr, SecRegAddr, RegVal) != FUNCTION_SUCCESS)
		goto error_status_get_demod_registers;

    return FUNCTION_SUCCESS;

error_status_get_demod_registers:
    return FUNCTION_ERROR;
}