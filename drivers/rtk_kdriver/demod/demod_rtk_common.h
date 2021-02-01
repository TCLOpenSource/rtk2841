#ifndef __DEMOD_REALTEK_COMMON_H__
#define __DEMOD_REALTEK_COMMON_H__

#include "demodcore/foundation.h"
#include "demod_rtk_def.h"

//#define DEMOD_DVBT2_METACLOCK_594MHZ
//#define DEMOD_DTMB_DTVFRONTEND_BYPASS
#define DEMOD_DTMB_DTVFRONTEND_DOWDSAMPLE

//#define DEMOD_LDR_CAHNGE_BY_FILE
#define DEMOD_MEM_START_PHYS 0x02000000
#define DEMOD_MEM_END_PHYS 0x027fffff
#define DEMOD_MEM_LENGTH 0x00800000

#ifndef _TRUE
#define _TRUE 1
#endif
#ifndef _FALSE
#define _FALSE 0
#endif


typedef enum {
	PGAFIX_N7DB = -7,
	PGAFIX_N6DB = -6,
	PGAFIX_N5DB = -5,
	PGAFIX_N4DB = -5,
	PGAFIX_N3DB = -5,
	PGAFIX_N2DB = -5,
	PGAFIX_N1DB = -5,
	PGAFIX_0DB = 0,
	PGAFIX_1DB = 1,
	PGAFIX_2DB = 2,
	PGAFIX_3DB = 3,
	PGAFIX_4DB = 4,
	PGAFIX_5DB = 5,
	PGAFIX_6DB = 6,
	PGAFIX_7DB = 7,
	PGAFIX_8DB = 8,
	PGAFIX_9DB = 9,
	PGAFIX_10DB = 10,
	PGAFIX_11DB = 11,
	PGAFIX_12DB = 12,
} IFADCGAIN;


int DtvGetChipVersion(void);
int DtvGetICVersion(void);
int DtvPGAControl(unsigned char on, IFADCGAIN val);
int DtvDemodInitialization(RTK_DEMOD_MODE mode, int force_rst);
int DtvDemodCheckPll(RTK_DEMOD_MODE mode);
int DtvDemodPllSettingCheck(RTK_DEMOD_MODE mode);
int DtvDemodCRTSettingCheck(void);
int DtvDemodClockEnable(unsigned char On);
int DtvIsDemodClockEnable(RTK_DEMOD_MODE mode);
int DtvDemodPowerControl(unsigned char On);
int DtvDemodGetPowerStatus(void);
int DtvDemodAdcPower(unsigned char on);
int DtvDemodAdcPowerCheck(void);
int GetDemodTvSysMode(TV_SYSTEM_TYPE* mode);
int CheckDemodReset(RTK_DEMOD_MODE mode);
void ClearDemodReset(RTK_DEMOD_MODE mode);
void DtvDumpShareRegStatus(void);
int AtvDemodInitialization(RTK_DEMOD_MODE mode);
int AtvDemodPowerControl(unsigned char On);
int DtvDemodDMAAllocateMemory(void);
int DtvDemodDMADump(BASE_INTERFACE_MODULE* pBaseInterface, unsigned char DeviceAddr, unsigned char mode);
int ImgIndirectRegAccess(unsigned int RegAddr, unsigned int RegVal);
int ImgDemodFixIfagc(RTK_DEMOD_MODE mode, unsigned char FixIfagcEn, unsigned int FixIfagcVal);

#ifdef DEMOD_LDR_CAHNGE_BY_FILE
struct device* get_rtkdemod_device_ptr(void);
#endif

#define RTK_DEMOD_BIF_TX_FIFO_DEPTH       16
#define RTK_DEMOD_BIF_RX_FIFO_DEPTH       16


extern void __realtek_wait_ms(
	BASE_INTERFACE_MODULE*      pBaseInterface,
	unsigned long               ms
);

extern int __realtek_i2c_write(
	BASE_INTERFACE_MODULE*      pBaseInterface,
	unsigned char               DeviceAddr,
	const unsigned char*        pWritingBytes,
	unsigned long               ByteNum
);

extern int __realtek_i2c_read(
	BASE_INTERFACE_MODULE*      pBaseInterface,
	unsigned char               DeviceAddr,
	unsigned char*              pReadingBytes,
	unsigned long               ByteNum
);

extern int __realtek_rbus_i2c_write(
	BASE_INTERFACE_MODULE*      pBaseInterface,
	unsigned char               DeviceAddr,
	const unsigned char*        pWritingBytes,
	unsigned long               ByteNum
);

extern int __realtek_rbus_i2c_read(
	BASE_INTERFACE_MODULE*      pBaseInterface,
	unsigned char               DeviceAddr,
	unsigned char*              pReadingBytes,
	unsigned long               ByteNum
);


#define DECODE_RET(x)       ((x==FUNCTION_SUCCESS) ? TUNER_CTRL_OK : TUNER_CTRL_FAIL)
#define ENCODE_RET(x)       ((x==TUNER_CTRL_OK) ?  FUNCTION_SUCCESS : FUNCTION_ERROR)

#define RTK_DEMOD_PRINT_LVL_DBG      0
#define RTK_DEMOD_PRINT_LVL_INFO     1
#define RTK_DEMOD_PRINT_LVL_WARNING  2

#ifndef RTK_DEMOD_PRINT_LVL
#define RTK_DEMOD_PRINT_LVL          RTK_DEMOD_PRINT_LVL_WARNING
#endif


#define RTK_DEMOD_CALLER(fmt, args...)     rtd_printk_demod(KERN_DEBUG,"DEMO","CALLER, " fmt, ##args);
#define RTK_DEMOD_DBG(fmt, args...)        rtd_printk_demod(KERN_DEBUG, "DEMO", "Debug, " fmt, ##args);
#define RTK_DEMOD_INFO(fmt, args...)       rtd_printk_demod(KERN_INFO, "DEMO", "Info, " fmt, ##args);
#define RTK_DEMOD_WARNING(fmt, args...)    rtd_printk_demod(KERN_WARNING, "DEMO", "Warning, " fmt, ##args);

#endif // __DEMOD_REALTEK_COMMON_H__