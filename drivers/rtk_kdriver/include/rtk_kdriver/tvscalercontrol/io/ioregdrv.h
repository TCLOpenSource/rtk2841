#ifndef __IOREGDRV_H__
#define __IOREGDRV_H__



//#include <rtd_types.h>



///////////////////////////////////////////////
// For Read / Write Registers
///////////////////////////////////////////////

/**
	read 32 bits of from the specified address
*/
unsigned int IoReg_Read32 (unsigned int addr);


/**
	write 32 bits of from the specified address
*/
void IoReg_Write32 (unsigned int addr, unsigned int value);


/**
	do AND operation with andMask
	then do OR operation with orMask
*/
void IoReg_Mask32(unsigned int addr, unsigned int andMask, unsigned int orMask);


/**
	any bit in Mask is 1 will be set to the secified address as 1
*/
void IoReg_SetBits(unsigned int addr, unsigned int Mask);

/**
	any bit in Mask is 1 will be set to the secified address as 0
*/
void  IoReg_ClearBits(unsigned int addr, unsigned int Mask);


unsigned char IoReg_ReadByte0(unsigned int addr);
unsigned char IoReg_ReadByte1(unsigned int addr);
unsigned char IoReg_ReadByte2(unsigned int addr);
unsigned char IoReg_ReadByte3(unsigned int addr);

/**
	read the low 16 bits from the specified address
*/
unsigned short IoReg_ReadWord0(unsigned int addr);

/**
	read the high 16 bits from the specified address
*/
unsigned short IoReg_ReadWord1(unsigned int addr);

void IoReg_WriteByte0(unsigned int addr, unsigned char val);
void IoReg_WriteByte1(unsigned int addr, unsigned char val);
void IoReg_WriteByte2(unsigned int addr, unsigned char val);
void IoReg_WriteByte3(unsigned int addr, unsigned char val);

/**
	write the low 16 bits from the specified address
*/
void IoReg_WriteWord0(unsigned int addr, unsigned short val);


/**
	write the high 16 bits from the specified address
*/
void IoReg_WriteWord1(unsigned int addr, unsigned short val);



/**
	check the specificed value of the specified address.
	return TRUE when the value & register value > 0.
	return FALSE when time out
*/
unsigned char IoReg_BusyCheckRegBit(unsigned int addr, unsigned int value, unsigned int timeoutcnt);

/**
	check the specificed value of the specified address.
	return TRUE when the value & register value = 0.
	return FALSE when time out
*/
unsigned char IoReg_BusyCheckRegInverseBit(unsigned int addr, unsigned int value, unsigned int timeoutcnt);


#endif // __IOREGDRV_H__

