#ifndef __DEMOD_REALTEK_R_ATSC_H__
#define __DEMOD_REALTEK_R_ATSC_H__

#include "demod.h"
#include "demod_rtk_def.h"


typedef struct {
	void*                       m_private;
	unsigned char               m_output_freq;
	REG_VALUE_ENTRY*            m_pTunerOptReg;
	unsigned int                m_TunerOptRegCnt;
	unsigned char               m_low_snr_detect;
	unsigned char               m_low_snr_recover;
	unsigned char               m_auto_tune_enable;
	unsigned char               m_patch_cnt;

	//int (*Activate)(struct sDEMOD *demod, unsigned char force_rst);
	//void (*Destory)(struct sDEMOD *demod);
} REALTEK_R_ATSC;

void REALTEK_R_ATSC_Constructors(DEMOD* pDemodKernel, unsigned char addr, 	unsigned char output_mode, unsigned char output_freq, COMM* pComm);
void REALTEK_R_ATSC_Destructors(DEMOD* pDemodKernel);
int REALTEK_R_ATSC_Init(DEMOD* pDemodKernel);
int REALTEK_R_ATSC_SetTVSys(DEMOD* pDemodKernel, TV_SYSTEM sys);
int REALTEK_R_ATSC_SetTVSysEx(DEMOD* pDemodKernel, TV_SYSTEM sys, const TV_SIG_INFO*  pSigInfo);
int REALTEK_R_ATSC_SetIF(DEMOD* pDemodKernel, IF_PARAM* pParam);
int REALTEK_R_ATSC_SetMode(DEMOD* pDemodKernel, TV_OP_MODE mode);
int REALTEK_R_ATSC_SetTSMode(DEMOD* pDemodKernel, TS_PARAM* pParam);
int REALTEK_R_ATSC_GetLockStatus(DEMOD* pDemodKernel, unsigned char* pLock);
int REALTEK_R_ATSC_GetSignalInfo(DEMOD* pDemodKernel, TV_SIG_INFO* pInfo);
int REALTEK_R_ATSC_GetSignalQuality(DEMOD* pDemodKernel, ENUM_TV_QUAL id,	TV_SIG_QUAL* pQuality);
int REALTEK_R_ATSC_GetCarrierOffset(DEMOD* pDemodKernel, long* pOffset);
int REALTEK_R_ATSC_GetDebugLogBuf(DEMOD* pDemodKernel, unsigned int* LogBufAddr, unsigned int* LogBufSize);
int REALTEK_R_ATSC_AcquireSignal(DEMOD* pDemodKernel, unsigned char WaitSignalLock);
int REALTEK_R_ATSC_ScanSignal(DEMOD* pDemodKernel, long* pOffset, SCAN_RANGE range);
int REALTEK_R_ATSC_ForwardI2C(DEMOD* pDemodKernel, unsigned char on_off);
int REALTEK_R_ATSC_AutoTune(DEMOD* pDemodKernel);
int REALTEK_R_ATSC_InspectSignal(DEMOD* pDemodKernel);
int REALTEK_R_ATSC_Activate(DEMOD* pDemodKernel, unsigned char force_rst);
int REALTEK_R_ATSC_SetTvMode(DEMOD* pDemodKernel, TV_SYSTEM_TYPE mode);
void REALTEK_R_ATSC_Lock(DEMOD* pDemodKernel);
void REALTEK_R_ATSC_Unlock(DEMOD* pDemodKernel);
int REALTEK_R_ATSC_DebugInfo(DEMOD* pDemodKernel, unsigned char debug_mode);
void REALTEK_R_ATSC_DumpSysInfo(void);



#define REALTEK_R_ATSC_DBG(fmt, args...)        rtd_printk_demod(KERN_DEBUG, "DEMO", "ATSC_DEBUG, " fmt, ##args);
#define REALTEK_R_ATSC_INFO(fmt, args...)       rtd_printk_demod(KERN_INFO, "DEMO", "ATSC_INFO, " fmt, ##args);
#define REALTEK_R_ATSC_WARNING(fmt, args...)    rtd_printk_demod(KERN_WARNING, "DEMO", "ATSC_WARNING, " fmt, ##args);

#endif // __DEMOD_REALTEK_R_ATSC_H__
