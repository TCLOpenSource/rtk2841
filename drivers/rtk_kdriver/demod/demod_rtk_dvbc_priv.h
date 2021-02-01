#ifndef  __DEMOD_REALTEK_I_DVBC_PRIV_H__
#define  __DEMOD_REALTEK_I_DVBC_PRIV_H__

#include "dvbc_demod_rtk.h"
#include "demod_rtk_common.h"

#define GET_SIGNAL_STRENGTH_FROM_SNR

typedef struct {
	DVBC_DEMOD_MODULE*      pDemod;
	BASE_INTERFACE_MODULE*  pBaseInterface;
	I2C_BRIDGE_MODULE*      pI2CBridge;
	unsigned char           DeviceAddr;
	unsigned long           CrystalFreqHz;
} REALTEK_I_DVBC_DRIVER_DATA;


#define DECODE_LOCK(x)      ((x==YES) ? DTV_SIGNAL_LOCK : DTV_SIGNAL_NOT_LOCK)


extern REALTEK_I_DVBC_DRIVER_DATA* AllocRealtekIDvbcDriver(
	COMM*               pComm,
	unsigned char       Addr,
	unsigned long       CrystalFreq
);

extern void ReleaseRealtekIDvbcDriver(REALTEK_I_DVBC_DRIVER_DATA *pDriver);

//--------------------------------------------------------------------------
// Optimization Setting for Tuner
//--------------------------------------------------------------------------

#endif // __DEMOD_REALTEK_I_DVBC_PRIV_H__
