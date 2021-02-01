#ifndef  __DEMOD_REALTEK_R_ATSC_PRIV_H__
#define  __DEMOD_REALTEK_R_ATSC_PRIV_H__

#include "demodcore/atsc_demod_rtk.h"
#include "demod_rtk_common.h"

#define GET_SIGNAL_STRENGTH_FROM_SNR

typedef struct {
	ATSC_DEMOD_MODULE*      pDemod;
	BASE_INTERFACE_MODULE*  pBaseInterface;
	I2C_BRIDGE_MODULE*      pI2CBridge;
	unsigned char           DeviceAddr;
	unsigned long           CrystalFreqHz;
} REALTEK_R_ATSC_DRIVER_DATA;

#define DECODE_LOCK(x)      ((x==YES) ? DTV_SIGNAL_LOCK : DTV_SIGNAL_NOT_LOCK)

extern REALTEK_R_ATSC_DRIVER_DATA* AllocRealtekRAtscDriver(
	COMM*               pComm,
	unsigned char       Addr,
	unsigned long       CrystalFreq
);

extern void ReleaseRealtekRAtscDriver(REALTEK_R_ATSC_DRIVER_DATA *pDriver);

//--------------------------------------------------------------------------
// Optimization Setting for Tuner IFAGC (Max/Min)
//--------------------------------------------------------------------------
static const REG_VALUE_ENTRY SI215x_OPT_VALUE_ATSC[] = {
	// RegBitName,				Value
	{ATSC_IF_AGC_MAX,				0x80		},
	{ATSC_IF_AGC_MIN,				0x80		},
};

static const REG_VALUE_ENTRY SI2178B_OPT_VALUE_ATSC[] = {
	// RegBitName,				Value
	{ATSC_IF_AGC_MAX,				0x7f		},
	{ATSC_IF_AGC_MIN,				0x80		},
};

static const REG_VALUE_ENTRY TUNERNULL_OPT_VALUE_ATSC[] = {
	// RegBitName,				Value
	{ATSC_IF_AGC_MAX,				0x7f		},
	{ATSC_IF_AGC_MIN,				0x80		},
};

#endif // __DEMOD_REALTEK_R_ATSC_PRIV_H__
