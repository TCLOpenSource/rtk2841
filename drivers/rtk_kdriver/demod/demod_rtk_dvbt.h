#ifndef __DEMOD_MERLIN2_DVBT_H__
#define __DEMOD_MERLIN2_DVBT_H__

#include "demod.h"
#include "demod_rtk_def.h"
#include <mach/rtk_log.h>
#define TAG_NAME "DEMO"

typedef struct {
	void*                       m_private;
	unsigned char               m_output_freq;
	REG_VALUE_ENTRY*            m_pTunerOptReg;
	unsigned int                m_TunerOptRegCnt;
	TV_SIG_INFO                 m_info;
	unsigned char               m_auto_tune_en;
	unsigned int                m_current_bw;
	unsigned int                m_PreBadTsPktNum;
	unsigned int                m_dvbt_AgcScale;
	unsigned int                m_dvbt_Invert;
	unsigned long               m_autotune_stime;
	unsigned int                m_bandwidth_mask;
	unsigned long               m_acquire_stime;
	unsigned int	         m_dvbt_ext_gain_dis;

	//int (*Activate)(struct sDEMOD *demod, unsigned char force_rst);
	//void (*Destory)(struct sDEMOD *demod);
} MERLIN2_DVBT;



void MERLIN2_DVBT_Constructors(DEMOD* pDemodKernel, unsigned char addr,     unsigned char output_mode, unsigned char output_freq, COMM* pComm);
void MERLIN2_DVBT_Destructors(DEMOD* pDemodKernel);
int MERLIN2_DVBT_Init(DEMOD* pDemodKernel);
int MERLIN2_DVBT_AcquireSignal(DEMOD* pDemodKernel, unsigned char WaitSignalLock);
int MERLIN2_DVBT_ScanSignal(DEMOD* pDemodKernel, long* offset, SCAN_RANGE range);
int MERLIN2_DVBT_SetTVSys(DEMOD* pDemodKernel, TV_SYSTEM sys);
int MERLIN2_DVBT_SetTVSysEx(DEMOD* pDemodKernel, TV_SYSTEM sys, const TV_SIG_INFO* pSigInfo);
int MERLIN2_DVBT_SetIF(DEMOD* pDemodKernel, IF_PARAM* pParam);
int MERLIN2_DVBT_SetMode(DEMOD* pDemodKernel, TV_OP_MODE mode);
int MERLIN2_DVBT_SetTSMode(DEMOD* pDemodKernel, TS_PARAM* pParam);
int MERLIN2_DVBT_GetLockStatus(DEMOD* pDemodKernel, unsigned char* pLock);
int MERLIN2_DVBT_GetSignalInfo(DEMOD* pDemodKernel, TV_SIG_INFO* pInfo);
int MERLIN2_DVBT_GetSignalQuality(DEMOD* pDemodKernel, ENUM_TV_QUAL id, TV_SIG_QUAL* pQuality);
int MERLIN2_DVBT_GetCarrierOffset(DEMOD* pDemodKernel, long* pOffset);
int MERLIN2_DVBT_GetDebugLogBuf(DEMOD* pDemodKernel, unsigned int* LogBufAddr, unsigned int* LogBufSize);
int MERLIN2_DVBT_ForwardI2C(DEMOD* pDemodKernel, unsigned char on_off);
int MERLIN2_DVBT_Activate(DEMOD* pDemodKernel, unsigned char force_rst);
int MERLIN2_DVBT_CalDvbTSsi(DEMOD* pDemodKernel, int Prec);
int MERLIN2_DVBT_AutoTune(DEMOD* pDemodKernel);
int MERLIN2_DVBT_InspectSignal(DEMOD* pDemodKernel);
int MERLIN2_DVBT_SetTvMode(DEMOD* pDemodKernel, TV_SYSTEM_TYPE sys_type);
void MERLIN2_DVBT_Lock(DEMOD* pDemodKernel);
void MERLIN2_DVBT_Unlock(DEMOD* pDemodKernel);


#define MERLIN2_DVBT_DBG(fmt, args...)         rtd_printk_demod(KERN_DEBUG, TAG_NAME,"Dvbt Debug, " fmt, ##args);
#define MERLIN2_DVBT_INFO(fmt, args...)        rtd_printk_demod(KERN_INFO, TAG_NAME,"Dvbt Info, " fmt, ##args);
#define MERLIN2_DVBT_WARNING(fmt, args...)     rtd_printk_demod(KERN_WARNING, TAG_NAME,"Dvbt Warning, " fmt, ##args);
#endif // __DEMOD_MERLIN2_DVBT_H__
