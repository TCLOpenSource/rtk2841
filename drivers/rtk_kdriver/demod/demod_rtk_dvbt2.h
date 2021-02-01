#ifndef __DEMOD_REALTEK_I_DVBT2_H__
#define __DEMOD_REALTEK_I_DVBT2_H__

#include "demod.h"
#include "demod_rtk_def.h"

#define REALTEK_I_DVBT2_MODE      0
#define REALTEK_I_DVBT_MODE       1
#include <mach/rtk_log.h>
#define TAG_NAME "DEMO"

#ifdef DEMOD_DVBT2_METACLOCK_675MHZ
#define DVBT2_META_2X_CLOCK 675000000
#define DVBT2_META_1X_CLOCK (DVBT2_META_2X_CLOCK>>1)
#elif defined(DEMOD_DVBT2_METACLOCK_648MHZ)
#define DVBT2_META_2X_CLOCK 648000000
#define DVBT2_META_1X_CLOCK (DVBT2_META_2X_CLOCK>>1)
#elif defined(DEMOD_DVBT2_METACLOCK_621MHZ)
#define DVBT2_META_2X_CLOCK 621000000
#define DVBT2_META_1X_CLOCK (DVBT2_META_2X_CLOCK>>1)
#elif defined(DEMOD_DVBT2_METACLOCK_594MHZ)
#define DVBT2_META_2X_CLOCK 594000000
#define DVBT2_META_1X_CLOCK (DVBT2_META_2X_CLOCK>>1)
#elif defined(DEMOD_DVBT2_METACLOCK_549MHZ)
#define DVBT2_META_2X_CLOCK 549000000
#define DVBT2_META_1X_CLOCK (DVBT2_META_2X_CLOCK>>1)
#elif defined(DEMOD_DVBT2_METACLOCK_504MHZ)
#define DVBT2_META_2X_CLOCK 504000000
#define DVBT2_META_1X_CLOCK (DVBT2_META_2X_CLOCK>>1)
#else
#define DVBT2_META_2X_CLOCK 594000000
#define DVBT2_META_1X_CLOCK (DVBT2_META_2X_CLOCK>>1)
#endif
#define DVBT_META_2X_CLOCK 405000000
#define DVBT_META_1X_CLOCK (DVBT_META_2X_CLOCK>>1)

#define DVBTT2_FAST_SCAN_RESULT_8M_MASK 0x8007
#define DVBTT2_FAST_SCAN_RESULT_7M_MASK 0x4038
#define DVBTT2_FAST_SCAN_RESULT_6M_MASK 0x21c0
#define DVBTT2_FAST_SCAN_RESULT_5M_MASK 0x1e00

#define AUTODETECT_SIG_UPDATE_INTERVAL_MS 5000

typedef struct {
	void*                       m_private;
	unsigned char               m_output_freq;
	REG_VALUE_ENTRY*            m_pTunerOptReg;
	unsigned int                m_TunerOptRegCnt;
	TV_SIG_INFO                 m_info;
	unsigned char               m_auto_tune_en;
	unsigned char               m_acquire_sig_en;
	unsigned char               m_dvbt2_dvbt_mode;
	unsigned int                m_current_bw;
	unsigned int                m_detected_bw;
	unsigned char               m_fastscan_en;
	unsigned int                m_plp_id;
	unsigned int                m_dvbt2_AgcScale;
	unsigned int                m_dvbt2_Invert;
	unsigned int                m_dvbt_AgcScale;
	unsigned int                m_dvbt_Invert;
	unsigned int                m_dvbt2_Ssi;
	unsigned int                m_dvbt2_dvbt_Ssi;
	unsigned int                m_PreUbc;
	unsigned long               m_autotune_stime;
	//unsigned int                m_agc_settle_time;
	unsigned int                m_dvbt2_ext_gain_dis;
	unsigned int                m_dvbt_ext_gain_dis;
	//unsigned char               m_init_done;
	unsigned int                m_dvbt_bandwidth_mask;
	unsigned int                m_unlock_cnt;
	unsigned char               m_profileHP;
	unsigned int                m_dvbt2_sfo;
	unsigned char               m_debug_tool_en;
	//int (*Activate)(struct sDEMOD *demod, unsigned char force_rst);
	//void (*Destory)(struct sDEMOD *demod);
} REALTEK_I_DVBT2;


void REALTEK_I_DVBT2_Constructors(DEMOD* pDemodKernel, unsigned char addr,    unsigned char output_mode, unsigned char output_freq, COMM* pComm);
void REALTEK_I_DVBT2_Destructors(DEMOD* pDemodKernel);
int REALTEK_I_DVBT2_Init(DEMOD* pDemodKernel);
int REALTEK_I_DVBT2_ChangeStandard(DEMOD* pDemodKernel, unsigned int Standard);
int REALTEK_I_DVBT2_ChangeT2PLP(DEMOD* pDemodKernel, TV_SIG_INFO* pInfo);
int REALTEK_I_DVBT2_GetT2PLPInfo(DEMOD* pDemodKernel, TV_SIG_INFO* pInfo);
int REALTEK_I_DVBT2_AcquireSignal(DEMOD* pDemodKernel, unsigned char WaitSignalLock);
int REALTEK_I_DVBT2_AcquireSignalThread(DEMOD* pDemodKernel);
int REALTEK_I_DVBT2_ScanSignal(DEMOD* pDemodKernel, long* offset, SCAN_RANGE range);
int REALTEK_I_DVBT2_SetTVSys(DEMOD* pDemodKernel, TV_SYSTEM sys);
int REALTEK_I_DVBT2_SetTVSysEx(DEMOD* pDemodKernel, TV_SYSTEM sys, const TV_SIG_INFO* pSigInfo);
int REALTEK_I_DVBT2_SetIF(DEMOD* pDemodKernel, IF_PARAM* pParam);
int REALTEK_I_DVBT2_SetMode(DEMOD* pDemodKernel, TV_OP_MODE mode);
int REALTEK_I_DVBT2_SetTSMode(DEMOD* pDemodKernel, TS_PARAM* pParam);
int REALTEK_I_DVBT2_GetLockStatus(DEMOD* pDemodKernel, unsigned char* pLock);
int REALTEK_I_DVBT2_GetSignalInfo(DEMOD* pDemodKernel, TV_SIG_INFO* pInfo);
int REALTEK_I_DVBT2_GetSignalQuality(DEMOD* pDemodKernel, ENUM_TV_QUAL id, TV_SIG_QUAL* pQuality);
int REALTEK_I_DVBT2_GetCarrierOffset(DEMOD* pDemodKernel, long* pOffset);
int REALTEK_I_DVBT2_GetDebugLogBuf(DEMOD* pDemodKernel, unsigned int* LogBufAddr, unsigned int* LogBufSize);
int REALTEK_I_DVBT2_ForwardI2C(DEMOD* pDemodKernel, unsigned char on_off);
int REALTEK_I_DVBT2_Activate(DEMOD* pDemodKernel, unsigned char force_rst);
int REALTEK_I_DVBT2_CalDvbT2Ssi(DEMOD* pDemodKernel, int Prec);
int REALTEK_I_DVBT2_CalDvbTSsi(DEMOD* pDemodKernel, int Prec);
int REALTEK_I_DVBT2_AutoTune(DEMOD* pDemodKernel);
int REALTEK_I_DVBT2_KernelAutoTune(DEMOD* pDemodKernel);
int REALTEK_I_DVBT2_InspectSignal(DEMOD* pDemodKernel);
int REALTEK_I_DVBT2_SetTvMode(DEMOD* pDemodKernel, TV_SYSTEM_TYPE sys_type);
void REALTEK_I_DVBT2_Lock(DEMOD* pDemodKernel);
void REALTEK_I_DVBT2_Unlock(DEMOD* pDemodKernel);

#define REALTEK_I_DVBT2_DBG(fmt, args...)        rtd_printk_demod(KERN_DEBUG, TAG_NAME,"Dvbt2 Debug, " fmt, ##args);
#define REALTEK_I_DVBT2_INFO(fmt, args...)        rtd_printk_demod(KERN_INFO, TAG_NAME,"Dvbt2 Info, " fmt, ##args);
#define REALTEK_I_DVBT2_WARNING(fmt, args...)     rtd_printk_demod(KERN_WARNING, TAG_NAME,"Dvbt2 Warning, " fmt, ##args);
#endif // __DEMOD_REALTEK_I_DVBT2_H__
