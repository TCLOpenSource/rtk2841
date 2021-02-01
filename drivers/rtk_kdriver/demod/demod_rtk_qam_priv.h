#ifndef  __DEMOD_REALTEK_I_QAM_PRIV_H__
#define  __DEMOD_REALTEK_I_QAM_PRIV_H__

#include "qam_demod_rtk.h"
#include "demod_rtk_common.h"

#define GET_SIGNAL_STRENGTH_FROM_SNR

typedef struct {
	QAM_DEMOD_MODULE*       pDemod;
	BASE_INTERFACE_MODULE*  pBaseInterface;
	I2C_BRIDGE_MODULE*      pI2CBridge;
	unsigned char           DeviceAddr;
	unsigned long           CrystalFreqHz;
} REALTEK_I_QAM_DRIVER_DATA;


#define DECODE_LOCK(x)      ((x==YES) ? DTV_SIGNAL_LOCK : DTV_SIGNAL_NOT_LOCK)


extern REALTEK_I_QAM_DRIVER_DATA* AllocRealtekIQamDriver(
	COMM*               pComm,
	unsigned char       Addr,
	unsigned long       CrystalFreq
);

extern void ReleaseRealtekIQamDriver(REALTEK_I_QAM_DRIVER_DATA *pDriver);

//--------------------------------------------------------------------------
// Optimization Setting for Tuner
//--------------------------------------------------------------------------

#endif // __DEMOD_REALTEK_I_QAM_PRIV_H__
