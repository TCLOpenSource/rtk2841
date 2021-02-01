#ifndef __DEMOD_REALTEK_ATV_HANDLE_H__
#define __DEMOD_REALTEK_ATV_HANDLE_H__

#ifdef __cplusplus
extern "C"
{
#endif //#ifdef __cplusplus

#include "ademod.h"

typedef struct {
	unsigned char m_scan_step;
	bool m_scan_mode;
	unsigned char m_sys;
	bool m_scan_aft_en;

	//void (* Destory)(void *merlin2_all);
	void (* Destory)(struct sADEMOD *ademod);
} REALTEK_ATV;

void REALTEK_ATV_Constructors(ADEMOD* pADemodKernel);
void REALTEK_ATV_Destructors(ADEMOD* pADemodKernel);
int REALTEK_ATV_Init(ADEMOD* pADemodKernel);
int REALTEK_ATV_Reset(ADEMOD* pADemodKernel);
int REALTEK_ATV_SetTVSys(ADEMOD* pADemodKernel, TV_SYSTEM sys);
int REALTEK_ATV_SetTVSysEx(ADEMOD* pADemodKernel, TV_SYSTEM sys, const	TV_SIG_INFO *pSigInfo);
int REALTEK_ATV_SetTvMode(ADEMOD* pADemodKernel, TV_SYSTEM_TYPE mode);
int REALTEK_ATV_SetMode(ADEMOD* pADemodKernel, TV_OP_MODE mode);
int REALTEK_ATV_GetLockStatus(ADEMOD* pADemodKernel, unsigned char *pLock);
int REALTEK_ATV_GetCarrierOffset(ADEMOD* pADemodKernel, long *pOffset);
int REALTEK_ATV_GetSignalInfo(ADEMOD* pADemodKernel, TV_SIG_INFO *pInfo);
int REALTEK_ATV_GetSignalQuality(ADEMOD* pADemodKernel, ENUM_TV_QUAL id, TV_SIG_QUAL *pQuality);
int REALTEK_ATV_AcquireSignal(ADEMOD* pADemodKernel, 	unsigned char WaitSignalLock);
int REALTEK_ATV_Suspend(ADEMOD* pADemodKernel);
int REALTEK_ATV_Resume(ADEMOD* pADemodKernel);
int REALTEK_ATV_InspectSignal(ADEMOD* pADemodKernel,	char *pBuff, unsigned long BufferSize);

#ifdef __cplusplus
}
#endif //#ifdef __cplusplus

#endif // __DEMOD_REALTEK_ATV_HANDLE_H__
