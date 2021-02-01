#ifndef __I2C_BASE_H
#define __I2C_BASE_H





// I2C types
#define I2C_TYPE_NUM			3
enum I2C_TYPE
{
	I2C_TYPE_PARALLELPORT,
	I2C_TYPE_RTL2832USB,
	I2C_TYPE_RTL2836USB,
};





// Definitions

// I2C multi-module availability definitions
enum
{
	I2C_MULTI_MODULE_NON_AVAILABLE,
	I2C_MULTI_MODULE_AVAILABLE,
};





// I2C module definitions

// I2C module pre-definition
typedef struct I2C_MODULE_TAG I2C_MODULE;





// I2C module function pointers
typedef int
(*I2C_FP_OPEN)(
	I2C_MODULE *pI2c
	);



typedef int
(*I2C_FP_CLOSE)(
	I2C_MODULE *pI2c
	);



typedef int
(*I2C_FP_READ)(
	I2C_MODULE *pI2c,
	unsigned char DeviceAddr,
	unsigned char *pReadingBytes,
	unsigned long ByteNum
	);



typedef int
(*I2C_FP_WRITE)(
	I2C_MODULE *pI2c,
	unsigned char DeviceAddr,
	const unsigned char *pWritingBytes,
	unsigned long ByteNum
	);





// RTL2832USB extra module
typedef struct RTL2832USB_EXTRA_MODULE_TAG RTL2832USB_EXTRA_MODULE;
struct RTL2832USB_EXTRA_MODULE_TAG
{
	// RTL2832USB extra data
	void *Hwnd;
};





// RTL2836USB extra module
typedef struct RTL2836USB_EXTRA_MODULE_TAG RTL2836USB_EXTRA_MODULE;
struct RTL2836USB_EXTRA_MODULE_TAG
{
	// RTL2836USB extra data
	void *Hwnd;
};





// I2C module structure
struct I2C_MODULE_TAG
{
	// I2C type
	int I2cType;

	// Multi-module availability
	int MultiModuleAvailability;

	// I2C extra module used by driving module
	union
	{
		RTL2832USB_EXTRA_MODULE Rtl2832usb;
		RTL2836USB_EXTRA_MODULE Rtl2836usb;
	}
	Extra;

	// I2C module openning and closing function
	I2C_FP_OPEN    Open;
	I2C_FP_CLOSE   Close;

	// I2C reading and writing
	I2C_FP_READ    Read;
	I2C_FP_WRITE   Write;
};












#endif
