#ifndef __DEMOD_REALTEK_R_ATV_HANDLE_H__
#define __DEMOD_REALTEK_R_ATV_HANDLE_H__

#ifdef __cplusplus
extern "C"
{
#endif //#ifdef __cplusplus

#include "demod.h"

typedef struct {
	unsigned char m_scan_step;
	bool m_scan_mode;
	unsigned char m_sys;
	bool m_scan_aft_en;

	//void (* Destory)(void *merlin2_all);
	//void (* Destory)(struct sDEMOD *demod);
} REALTEK_R_ATV;

void REALTEK_R_ATV_Constructors(DEMOD* pDemodKernel);
void REALTEK_R_ATV_Destructors(DEMOD* pDemodKernel);
int REALTEK_R_ATV_Init(DEMOD* pDemodKernel);
int REALTEK_R_ATV_Reset(DEMOD* pDemodKernel);
int REALTEK_R_ATV_SetTVSys(DEMOD* pDemodKernel, TV_SYSTEM sys);
int REALTEK_R_ATV_SetTVSysEx(DEMOD* pDemodKernel, TV_SYSTEM sys, const	TV_SIG_INFO *pSigInfo);
int REALTEK_R_ATV_SetTvMode(DEMOD* pDemodKernel, TV_SYSTEM_TYPE mode);
int REALTEK_R_ATV_SetMode(DEMOD* pDemodKernel, TV_OP_MODE mode);
int REALTEK_R_ATV_GetLockStatus(DEMOD* pDemodKernel, unsigned char *pLock);
int REALTEK_R_ATV_GetCarrierOffset(DEMOD* pDemodKernel, long *pOffset);
int REALTEK_R_ATV_GetSignalInfo(DEMOD* pDemodKernel, TV_SIG_INFO *pInfo);
int REALTEK_R_ATV_GetSignalQuality(DEMOD* pDemodKernel, ENUM_TV_QUAL id, TV_SIG_QUAL *pQuality);
int REALTEK_R_ATV_AcquireSignal(DEMOD* pDemodKernel, 	unsigned char WaitSignalLock);
int REALTEK_R_ATV_Suspend(DEMOD* pDemodKernel);
int REALTEK_R_ATV_Resume(DEMOD* pDemodKernel);
int REALTEK_R_ATV_InspectSignal(DEMOD* pDemodKernel,	char *pBuff, unsigned long BufferSize);
void REALTEK_R_ATV_Lock(DEMOD* pDemodKernel);
void REALTEK_R_ATV_Unlock(DEMOD* pDemodKernel);

#ifdef __cplusplus
}
#endif //#ifdef __cplusplus

#endif // __DEMOD_REALTEK_R_ATV_HANDLE_H__
