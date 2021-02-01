/***************************************************************************************************
  File        : ademod.h
  Description : Base Class of All Analog ADemod
  Author      : Kevin Wang
****************************************************************************************************
    Update List :
----------------------------------------------------------------------------------------------------
    1.0a     |   20141020    | Create Phase
***************************************************************************************************/
#ifndef __ADEMOD_H__
#define __ADEMOD_H__

#include "tv_osal.h"
#include "rtk_tv_fe_types.h"
#include "tv_fe_aux.h"
//#include "comm.h"
#include "tuner.h"
#include <mach/rtk_log.h>


enum {
	DTV_ADEMOD_NONE = 0,
	DTV_ADEMOD_REALTEK_RTD2945,
	DTV_ADEMOD_REALTEK_RTD299S,
	DTV_ADEMOD_REALTEK_MERLIN2,
	DTV_ADEMOD_REALTEK,
};

typedef struct sADEMOD {
	void *private_data;

	unsigned short m_id;
	TUNER*         m_pTuner;
	unsigned long  m_Capability;
	IF_PARAM       m_if;
	TV_SYSTEM      m_tv_sys;
	struct mutex   m_lock;

	int (*Init)(struct sADEMOD *ademod);
	int (*Reset)(struct sADEMOD *ademod);
	int (*SetTVSysEx)(struct sADEMOD *ademod, TV_SYSTEM sys, const TV_SIG_INFO* pSigInfo);
	int (*SetTVSys)(struct sADEMOD *ademod, TV_SYSTEM sys);
	int (*SetTvMode)(struct sADEMOD *ademod, TV_SYSTEM_TYPE sys);
	int (*SetMode)(struct sADEMOD *ademod, TV_OP_MODE mode);
	int (*GetLockStatus)(struct sADEMOD *ademod, unsigned char* pLock);
	int (*GetCarrierOffset)(struct sADEMOD *ademod, long* pOffset);
	int (*GetSignalQuality)(struct sADEMOD *ademod, ENUM_TV_QUAL id, TV_SIG_QUAL* pQuality);
	int (*AcquireSignal)(struct sADEMOD *ademod, unsigned char WaitSignalLock);
	int (*GetSignalInfo)(struct sADEMOD *ademod, TV_SIG_INFO* pInfo);
	unsigned long (*GetCapability)(struct sADEMOD *ademod);
	int (*Suspend)(struct sADEMOD *ademod);
	int (*Resume)(struct sADEMOD *ademod);
	int (*InspectSignal)(struct sADEMOD *ademod, char* pBuff, unsigned long BufferSize);
	void (*AttachTuner)(struct sADEMOD *ademod, TUNER* pTuner);
	void (*Lock)(struct sADEMOD *ademod);
	void (*Unlock)(struct sADEMOD *ademod);
	void (*Destory)(struct sADEMOD *ademod);
} ADEMOD;

int ADemod_Init(ADEMOD* pADemodKernel);
int ADemod_Reset(ADEMOD* pADemodKernel);
//int ADemod_SetTVSysEx(ADEMOD* pADemodKernel, TV_SYSTEM sys, const TV_SIG_INFO* pSigInfo = NULL);
int ADemod_SetTVSysEx(ADEMOD* pADemodKernel, TV_SYSTEM sys, const TV_SIG_INFO* pSigInfo);
int ADemod_SetTVSys(ADEMOD* pADemodKernel, TV_SYSTEM sys);
int ADemod_SetTvMode(ADEMOD* pADemodKernel, TV_SYSTEM_TYPE sys);
int ADemod_SetMode(ADEMOD* pADemodKernel, TV_OP_MODE mode);
int ADemod_GetLockStatus(ADEMOD* pADemodKernel, unsigned char* pLock);
int ADemod_GetCarrierOffset(ADEMOD* pADemodKernel, long* pOffset);
int ADemod_GetSignalQuality(ADEMOD* pADemodKernel, ENUM_TV_QUAL id, TV_SIG_QUAL* pQuality);
//int ADemod_AcquireSignal(ADEMOD* pADemodKernel, unsigned char WaitSignalLock = 1);
int ADemod_AcquireSignal(ADEMOD* pADemodKernel, unsigned char WaitSignalLock);
int ADemod_GetSignalInfo(ADEMOD* pADemodKernel, TV_SIG_INFO* pInfo);
unsigned long ADemod_GetCapability(ADEMOD* pADemodKernel);
int ADemod_Suspend(ADEMOD* pADemodKernel);
int ADemod_Resume(ADEMOD* pADemodKernel);
int ADemod_InspectSignal(ADEMOD* pADemodKernel, char* pBuff, unsigned long BufferSize);
void ADemod_AttachTuner(ADEMOD* pADemodKernel, TUNER* pTuner);
void ADemod_Lock(ADEMOD* pADemodKernel);
void ADemod_Unlock(ADEMOD* pADemodKernel);
void ADemod_Constructors(ADEMOD* pADemodKernel);
void ADemod_Destructors(ADEMOD* pADemodKernel);

//=============================================================

#define ADEMOD_CALLER(fmt, args...)         rtd_printk(KERN_DEBUG, "DEMO", "ATV_CALLER, " fmt, ##args);
#define ADEMOD_DBG(fmt, args...)         rtd_printk(KERN_DEBUG, "DEMO", "ATV_DEBUG, " fmt, ##args);
#define ADEMOD_INFO(fmt, args...)               rtd_printk(KERN_INFO, "DEMO", "ATV_INFO, " fmt, ##args);
#define ADEMOD_WARNING(fmt, args...)        rtd_printk(KERN_WARNING, "DEMO", "ATV_WARNING, " fmt, ##args);



#endif  //__DTV_DEMOD_HANDLE_H__
