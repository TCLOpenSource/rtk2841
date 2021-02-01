#ifndef  __DEMOD_REALTEK_I_ISDBT_PRIV_H__
#define  __DEMOD_REALTEK_I_ISDBT_PRIV_H__

#include "demod_rtk_isdbt.h"
#include "demod_rtk_common.h"

#define GET_SIGNAL_STRENGTH_FROM_SNR

//change memory size from 26Mbs(3.3MBs) to 4MBs because 3.3MBs cause memory trash on MacArthur2
#define REALTEK_I_ISDBTT_DEMUX_DDR_SIZE  (4 * 1024 * 1024)    // 4MBs

typedef struct {
	ISDBT_DEMOD_MODULE*     pDemod;
	BASE_INTERFACE_MODULE*  pBaseInterface;
	I2C_BRIDGE_MODULE*      pI2CBridge;
	unsigned char           DeviceAddr;
	unsigned long           CrystalFreqHz;
	unsigned char*          pShareMemory;
	unsigned long           ShareMemoryPhysicalAddress;
} REALTEK_I_ISDBT_DRIVER_DATA;

#define DECODE_LOCK(x)      ((x==YES) ? DTV_SIGNAL_LOCK : DTV_SIGNAL_NOT_LOCK)


extern REALTEK_I_ISDBT_DRIVER_DATA* AllocRealtekIDriver_ISDBT(
	COMM*               pComm,
	unsigned char       Addr,
	unsigned long       CrystalFreq,
	int                 TSMode
);

extern void ReleaseRealtekIDriver(REALTEK_I_ISDBT_DRIVER_DATA *pDriver);



//--------------------------------------------------------------------------
// Optimization Setting for Tuner
//--------------------------------------------------------------------------

#endif
