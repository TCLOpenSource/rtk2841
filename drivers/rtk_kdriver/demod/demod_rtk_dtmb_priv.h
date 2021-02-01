#ifndef  __DEMOD_REALTEK_H_DTMB_PRIV_H__
#define  __DEMOD_REALTEK_H_DTMB_PRIV_H__

#include "dtmb_demod_base.h"
#include "dtmb_demod_rtk.h"
#include "dtmb_demod_rtk_user.h"
#include "dtmb_demod_rtk_type.h"

typedef struct {
	DTMB_DEMOD_MODULE*      pDemod;
	BASE_INTERFACE_MODULE*  pBaseInterface;
	I2C_BRIDGE_MODULE*      pI2CBridge;
	unsigned char           DeviceAddr;
	unsigned long           CrystalFreqHz;
} REALTEK_H_DTMB_DRIVER_DATA;


#define DECODE_LOCK(x)      ((x==YES) ? DTV_SIGNAL_LOCK : DTV_SIGNAL_NOT_LOCK)


extern REALTEK_H_DTMB_DRIVER_DATA* AllocRealtekHDtmbDriver(
	COMM*               pComm,
	unsigned char       Addr,
	unsigned long       CrystalFreq
);

extern void ReleaseRealtekHDtmbDriver(REALTEK_H_DTMB_DRIVER_DATA *pDriver);


#endif

