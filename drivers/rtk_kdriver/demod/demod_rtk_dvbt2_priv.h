#ifndef  __DEMOD_REALTEK_I_DVBT2_PRIV_H__
#define  __DEMOD_REALTEK_I_DVBT2_PRIV_H__

#include "dvbt2_demod_rtk.h"
#include "demod_rtk_common.h"

#define GET_SIGNAL_STRENGTH_FROM_SNR

typedef struct {
    DVBT2_DEMOD_MODULE*     pDemod;
    BASE_INTERFACE_MODULE*  pBaseInterface;
    I2C_BRIDGE_MODULE*      pI2CBridge;
    unsigned char           DeviceAddr;
    unsigned long           CrystalFreqHz;
} REALTEK_I_DVBT2_DRIVER_DATA;


#define DECODE_LOCK(x)      ((x==YES) ? DTV_SIGNAL_LOCK : DTV_SIGNAL_NOT_LOCK)


extern REALTEK_I_DVBT2_DRIVER_DATA* AllocRealtekIDvbt2Driver(
    COMM*               pComm,
    unsigned char       Addr,
    unsigned long       CrystalFreq
);

extern void ReleaseRealtekIDvbt2Driver(REALTEK_I_DVBT2_DRIVER_DATA *pDriver);

//--------------------------------------------------------------------------
// Optimization Setting for Tuner
//--------------------------------------------------------------------------
/*
static const REG_VALUE_ENTRY SI2158_OPT_VALUE_DVBT2[] = {
    // RegBitName,              Value
    {DVBT2_IF_AAGC_MAX,             0x0     },
    {DVBT2_IF_AAGC_MIN,             0x0     },
};
static const REG_VALUE_ENTRY SI2178B_OPT_VALUE_DVBT2[] = {
    // RegBitName,              Value
    {DVBT2_AAGC_TARGET,             0x90    },
};
*/
#endif // __DEMOD_REALTEK_I_DVBT2_PRIV_H__
