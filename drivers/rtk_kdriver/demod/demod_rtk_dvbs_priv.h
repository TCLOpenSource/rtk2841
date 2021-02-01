#ifndef  __DEMOD_REALTEK_I_DVBS_PRIV_H__
#define  __DEMOD_REALTEK_I_DVBS_PRIV_H__

#include "dvbs_demod_rtk.h"
#include "demod_rtk_common.h"

#define GET_SIGNAL_STRENGTH_FROM_SNR

typedef struct {
    DVBS_DEMOD_MODULE*     pDemod;
    BASE_INTERFACE_MODULE*  pBaseInterface;
    I2C_BRIDGE_MODULE*      pI2CBridge;
    unsigned char           DeviceAddr;
    unsigned long           CrystalFreqHz;
} REALTEK_I_DVBS_DRIVER_DATA;


#define DECODE_LOCK(x)      ((x==YES) ? DTV_SIGNAL_LOCK : DTV_SIGNAL_NOT_LOCK)


extern REALTEK_I_DVBS_DRIVER_DATA* AllocRealtekIDvbsDriver(
    COMM*               pComm,
    unsigned char       Addr,
    unsigned long       CrystalFreq
);

extern void ReleaseRealtekIDvbsDriver(REALTEK_I_DVBS_DRIVER_DATA *pDriver);

//--------------------------------------------------------------------------
// Optimization Setting for Tuner
//--------------------------------------------------------------------------
/*
static const REG_VALUE_ENTRY SI2158_OPT_VALUE_DVBC[] = {
    // RegBitName,              Value
    {DVBC_IF_AAGC_MAX,              0x0     },
    {DVBC_IF_AAGC_MIN,              0x0     },
};
static const REG_VALUE_ENTRY SI2178B_OPT_VALUE_DVBC[] = {
    // RegBitName,              Value
    {DVBC_AAGC_TARGET,              0x90    },
};
*/
#endif // __DEMOD_REALTEK_I_DVBS_PRIV_H__
