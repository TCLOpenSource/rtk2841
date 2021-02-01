#ifndef __DEMOD_REALTEK_I_DVBS2_H__
#define __DEMOD_REALTEK_I_DVBS2_H__

#include "demod.h"
#include "demod_rtk_def.h"

#define REALTEK_I_DVBS_MODE            0
#define REALTEK_I_DVBS2_MODE           1
#define REALTEK_I_DVBS_BS_MODE         2
#define REALTEK_I_DVBS2X_MODE          3
#define REALTEK_I_SPEC_AN_BS_MODE      4

#define BS_FFT_RESOLUTION            85000
#define TUNER_STEP_TOLERANCE         0
#define WIN_MARGIN                   8200000
#define BS_FULL_NO_SIGNAL_TH         1350
#define MIN_CSR                      1700000
#define MAX_CSR                      54000000
#define NULL_SEC_ADDR                0//null secendary addr
#define FIX_TUNER_STEP               30000000

typedef struct _s_sDvbSLockTimeOut
{
    unsigned int SymbolRateKhz;
    unsigned int TimeOutMs;
    unsigned int SCAN_ERR_THRESH_FOR_DEMOD_ENTRY;
    unsigned int SCAN_DEMOD_ENTRY_MEASURE_LEN;
    unsigned int SCAN_DEMOD_LOCK_TIMEOUT;
    unsigned int SCAN_ERR_THRESH_FOR_DEMOD_EXIT;
    unsigned int SCAN_DEMOD_EXIT_MEASURE_LEN;
    unsigned int SCAN_LOST_LOCK_TIMEOUT;
    unsigned int ZAP_ERR_THRESH_FOR_DEMOD_ENTRY;
    unsigned int ZAP_DEMOD_ENTRY_MEASURE_LEN;
    unsigned int ZAP_DEMOD_LOCK_TIMEOUT;
    unsigned int ZAP_ERR_THRESH_FOR_DEMOD_EXIT;
    unsigned int ZAP_DEMOD_EXIT_MEASURE_LEN;
    unsigned int ZAP_LOST_LOCK_TIMEOUT;
}s_sDvbSLockTimeOut;

typedef struct _s_sDvbS2LockTimeOut
{
    unsigned int SymbolRateKhz;
    unsigned int TimeOutMs;
    unsigned int SCAN_ERR_THRESH_FOR_DEMOD_ENTRY;
    unsigned int SCAN_DEMOD_ENTRY_MEASURE_LEN;
    unsigned int SCAN_DEMOD_LOCK_TIMEOUT;
    unsigned int SCAN_ERR_THRESH_FOR_DEMOD_EXIT;
    unsigned int SCAN_DEMOD_EXIT_MEASURE_LEN;
    unsigned int SCAN_LOST_LOCK_TIMEOUT;
    unsigned int ZAP_ERR_THRESH_FOR_DEMOD_ENTRY;
    unsigned int ZAP_DEMOD_ENTRY_MEASURE_LEN;
    unsigned int ZAP_DEMOD_LOCK_TIMEOUT;
    unsigned int ZAP_ERR_THRESH_FOR_DEMOD_EXIT;
    unsigned int ZAP_DEMOD_EXIT_MEASURE_LEN;
    unsigned int ZAP_LOST_LOCK_TIMEOUT;
}s_sDvbS2LockTimeOut;

typedef struct _s_sDvbS2XLockTimeOut
{
    unsigned int SymbolRateKhz;
    unsigned int TimeOutMs;
}s_sDvbS2XLockTimeOut;

typedef struct {
    void*                       m_private;
    unsigned char               m_output_freq;
    REG_VALUE_ENTRY*            m_pTunerOptReg;
    unsigned int                m_TunerOptRegCnt;
    TV_SIG_INFO                 m_info;
    unsigned char               m_dvbs_AgcScale;
    unsigned char               m_dvbs_Invert;
    unsigned char               m_dvbs_ext_gain_dis;
    unsigned char               m_dvbs2_AgcScale;
    unsigned char               m_dvbs2_Invert;
    unsigned char               m_dvbs2_ext_gain_dis;
    unsigned char               m_auto_scan_mode;
    unsigned char               m_auto_tune_en;
    unsigned char               m_auto_tune_reset;
    unsigned char               m_dvbs2_zapping_mode;
    unsigned char               m_dvbs2_manual_modulation;
    unsigned char               m_dvbs2_manual_code_rate;
    unsigned char               m_dvbs2_manual_pilot_onoff;
    unsigned char               m_dvbs2_manual_spec_invert;
    unsigned int                m_current_bw;
    unsigned int                m_PreUbc;
    unsigned int                m_AcqTimeOut;
    unsigned int                m_dvbs2_snr;

    unsigned short              BlindscanSpectrum_dvbs2[1024];
    unsigned int                BlindscanSpectrum_dvbs2_convert[1024];
    short                       BlindscanAllCutCandidateCp1[256];
    short                       BlindscanAllCutCandidateCp2[256];
    unsigned int                BlindscanTpFreq[2048];
    unsigned int                BlindscanTpCpDis[2048];
    unsigned int                BlindscanTpCheck[2048];
    unsigned int                BlindscanTpCnt;
    unsigned int                BlindscanAcqTpCnt;
    unsigned char               Blindscan1stPhaseDone;
    unsigned char               BlindscanInitDone;
    unsigned int                BlindscanStime;
    unsigned int                BlindscanEtime;
    unsigned int                BlindscanFoundTpIdx;
    unsigned int                BlindscanFoundTpList[1024];
    
    unsigned char               m_dvbs2_ldr_mode;
    unsigned char               m_blindscan_first_step;
    unsigned char               m_blindscan_signal_found;
    unsigned int                m_blindscan_spectrum_len;
    unsigned int                m_blindscan_start_freq;
    unsigned int                m_blindscan_end_freq;
    unsigned int                m_blindscan_current_freq;
    unsigned int                m_blindscan_next_freq;
    unsigned int                m_blindscan_tuner_step;
    int                         m_blindscan_signal_cfo;
    unsigned int                m_blindscan_signal_csr;
    unsigned int                m_blindscan_signal_frequency;
    unsigned int                m_blindscan_signal_symbolrate;
    
    unsigned short              m_blindscan_sat_index;
    unsigned short              m_blindscan_tp_ref_idx;
    unsigned short              m_blindscan_tp_ref_num;
    unsigned int                m_blindscan_tp_ref_frequency[50];
    unsigned int                m_blindscan_tp_ref_symbolrate[50];
    unsigned short              m_blindscan_tp_lock_idx;
    unsigned int                m_blindscan_tp_lock_frequency[50];
    unsigned int                m_blindscan_tp_lock_symbolrate[50];

    int                         m_dvbs2_freq_offset;
    unsigned int                m_carrier_spectrum_len;
    unsigned int                m_carrier_signal_found;
    int                         m_carrier_signal_cfo;
    unsigned int                m_carrier_signal_csr;

    unsigned char               m_debug_tool_en;
    unsigned char               m_force_unlock_en;

    //int (*Activate)(struct sDEMOD *demod, unsigned char force_rst);
    //void (*Destory)(struct sDEMOD *demod);
} REALTEK_I_DVBS2;

typedef enum {
    RTK_DEMOD_DVBS2_CR_1_2 = 0,
    RTK_DEMOD_DVBS2_CR_2_3,
    RTK_DEMOD_DVBS2_CR_3_4,
    RTK_DEMOD_DVBS2_CR_5_6,
    RTK_DEMOD_DVBS2_CR_Rsv1,
    RTK_DEMOD_DVBS2_CR_3_5,
    RTK_DEMOD_DVBS2_CR_4_5,
    RTK_DEMOD_DVBS2_CR_8_9,
    RTK_DEMOD_DVBS2_CR_9_10,
    RTK_DEMOD_DVBS2_CR_1_4,
    RTK_DEMOD_DVBS2_CR_1_3,// = 10
    RTK_DEMOD_DVBS2_CR_2_5,
    RTK_DEMOD_DVBS2_CR_13_45,
    RTK_DEMOD_DVBS2_CR_9_20,
    RTK_DEMOD_DVBS2_CR_11_20,
    RTK_DEMOD_DVBS2_CR_100_180,
    RTK_DEMOD_DVBS2_CR_104_180,
    RTK_DEMOD_DVBS2_CR_23_36,
    RTK_DEMOD_DVBS2_CR_25_36,
    RTK_DEMOD_DVBS2_CR_13_18,
    RTK_DEMOD_DVBS2_CR_90_180,// = 20
    RTK_DEMOD_DVBS2_CR_96_180,
    RTK_DEMOD_DVBS2_CR_26_45,
    RTK_DEMOD_DVBS2_CR_Rsv2,
    RTK_DEMOD_DVBS2_CR_18_30,
    RTK_DEMOD_DVBS2_CR_28_45,
    RTK_DEMOD_DVBS2_CR_20_30,
    RTK_DEMOD_DVBS2_CR_154_180,
    RTK_DEMOD_DVBS2_CR_128_180,
    RTK_DEMOD_DVBS2_CR_132_180,
    RTK_DEMOD_DVBS2_CR_140_180,// = 30
} RTK_DEMOD_DVBS2_CR;

    void REALTEK_I_DVBS2_Constructors(DEMOD* pDemodKernel, unsigned char addr,    unsigned char output_mode, unsigned char output_freq, COMM* pComm);
    void REALTEK_I_DVBS2_Destructors(DEMOD* pDemodKernel);

    int REALTEK_I_DVBS2_Init(DEMOD* pDemodKernel);
    int REALTEK_I_DVBS2_GetDiffSrParams(DEMOD* pDemodKernel, unsigned int ldr_mode, unsigned long symbolrate, unsigned int scan_mode, unsigned int *AcqTimeOut);
    int REALTEK_I_DVBS2_AcquireSignalEx(DEMOD* pDemodKernel, unsigned char WaitSignalLock, unsigned char  DiseqcCmdCnt, const unsigned char    *pDiseqcCmd);      
    int REALTEK_I_DVBS2_AcquireSignal(DEMOD* pDemodKernel, unsigned char WaitSignalLock);
    int REALTEK_I_DVBS2_GetChannelInfo(DEMOD* pDemodKernel, unsigned char* Standard, unsigned char* Modulation, unsigned char* CodeRate, unsigned char* PilotOnOff, unsigned char* Inverse);
    int REALTEK_I_DVBS2_ScanSignal(DEMOD* pDemodKernel, long* offset, SCAN_RANGE range);
    int REALTEK_I_DVBS2_SetTVSys(DEMOD* pDemodKernel, TV_SYSTEM sys);
    int REALTEK_I_DVBS2_SetTVSysEx(DEMOD* pDemodKernel, TV_SYSTEM sys, const TV_SIG_INFO* pSigInfo);
    int REALTEK_I_DVBS2_SetIF(DEMOD* pDemodKernel, IF_PARAM* pParam);
    int REALTEK_I_DVBS2_SetMode(DEMOD* pDemodKernel, TV_OP_MODE mode);
    int REALTEK_I_DVBS2_SetTSMode(DEMOD* pDemodKernel, TS_PARAM* pParam);
    int REALTEK_I_DVBS2_GetLockStatus(DEMOD* pDemodKernel, unsigned char* pLock);
    int REALTEK_I_DVBS2_GetSignalInfo(DEMOD* pDemodKernel, TV_SIG_INFO* pInfo);
    int REALTEK_I_DVBS2_GetSignalQuality(DEMOD* pDemodKernel, ENUM_TV_QUAL id, TV_SIG_QUAL* pQuality);
    int REALTEK_I_DVBS2_GetCarrierOffset(DEMOD* pDemodKernel, long* pOffset);
    int REALTEK_I_DVBS2_GetDebugLogBuf(DEMOD* pDemodKernel, unsigned int* LogBufAddr, unsigned int* LogBufSize);
    int REALTEK_I_DVBS2_ForwardI2C(DEMOD* pDemodKernel, unsigned char on_off);
    int REALTEK_I_DVBS2_Activate(DEMOD* pDemodKernel, unsigned char force_rst);
    int REALTEK_I_DVBS2_CalDvbS2Ssi(DEMOD* pDemodKernel);
    int REALTEK_I_DVBS2_CalDvbS2Sqi(DEMOD* pDemodKernel);
    int REALTEK_I_DVBS2_CalDvbS2XSsi(DEMOD* pDemodKernel);
    int REALTEK_I_DVBS2_CalDvbS2XSqi(DEMOD* pDemodKernel);
    int REALTEK_I_DVBS2_CalDvbSSsi(DEMOD* pDemodKernel);
    int REALTEK_I_DVBS2_CalDvbSSqi(DEMOD* pDemodKernel);
    int REALTEK_I_DVBS2_AutoTune(DEMOD* pDemodKernel);
    int REALTEK_I_DVBS2_KernelAutoTune(DEMOD* pDemodKernel);
    int REALTEK_I_DVBS2_InspectSignal(DEMOD* pDemodKernel);
    int REALTEK_I_DVBS2_SetTvMode(DEMOD* pDemodKernel, TV_SYSTEM_TYPE sys_type);
    int REALTEK_I_DVBS2_SetDiseqcContinue22kOnOff(DEMOD* pDemodKernel, unsigned int OnOff);
    int REALTEK_I_DVBS2_SetDiseqcCmd(DEMOD* pDemodKernel, unsigned int Length, unsigned char *Data);
    int REALTEK_I_DVBS2_SetDiseqcToneBurst(DEMOD* pDemodKernel, DISEQC_TONE_MODE mode);
    int REALTEK_I_DVBS2_SetDiseqcUnModToneBurst(DEMOD* pDemodKernel);
    int REALTEK_I_DVBS2_SetDiseqcModToneBurst(DEMOD* pDemodKernel);
    
    //void REALTEK_I_DVBS2_ReverseArray(unsigned short *pintArray, unsigned int intArraySize);
    int REALTEK_I_DVBS2_SpecAnGetSpectrum(DEMOD* pDemodKernel, unsigned int *SpectrumArray, unsigned int *SpectrumLength);
    int REALTEK_I_DVBS2_SpecAnGetCp1Cp2(DEMOD* pDemodKernel, unsigned int *SpectrumArray, unsigned int SkipDc, unsigned int CutSp, unsigned int CutEp, short *AllCutCandidateNum, short *AllCutCandidateCp1, short *AllCutCandidateCp2, unsigned int CutTh_1st, unsigned int CutTh_2nd, unsigned int CutTh_3rd, unsigned int CutTh_4th, unsigned int CutTh_5th, unsigned int CutTh_6th);
    int REALTEK_I_DVBS2_SpecAnCalCfoCsr(DEMOD* pDemodKernel, short Cp1, short Cp2, int *SigCfo, unsigned int *SigCsr);
    int REALTEK_I_DVBS2_SpecAnSearchMaxMin(DEMOD* pDemodKernel, unsigned int *SpectrumArray, unsigned int Sp, unsigned int Ep, unsigned int *MaxPower, unsigned int *MaxPowerPos, unsigned int *MinPower, unsigned int *MinPowerPos);
    int REALTEK_I_DVBS2_BlindscanCheckSignalLock(DEMOD* pDemodKernel, unsigned int CCfo, unsigned int Csr, unsigned char *SigLock, unsigned int *FSr, int *FCfo);
    int REALTEK_I_DVBS2_BlindscanAnalyzeSpectrum(DEMOD* pDemodKernel, unsigned char *SignalFound, int *SigCfo, unsigned int *SigCsr, unsigned int *NextStep);
    int REALTEK_I_DVBS2_BlindScan_Init(DEMOD* pDemodKernel, unsigned int StartFreqMhz, unsigned int EndFreqMhz);
    int REALTEK_I_DVBS2_BlindScan_GetTunerFreq(DEMOD* pDemodKernel, unsigned int *TunerCenterFreqMhz, unsigned int *TunerCutOffFreqKhz);
    int REALTEK_I_DVBS2_BlindScan_NextFreq(DEMOD* pDemodKernel, unsigned int *bBlindScanEnd);
    int REALTEK_I_DVBS2_BlindscanRemoveDuplicateTp(DEMOD* pDemodKernel, unsigned char mode);
    int REALTEK_I_DVBS2_BlindScan_GetStatus(DEMOD* pDemodKernel, unsigned char *Status, unsigned int *bBlindScanLock);
    int REALTEK_I_DVBS2_BlindScan_End(DEMOD* pDemodKernel);
    int REALTEK_I_DVBS2_BlindScan_GetFoundTP(DEMOD* pDemodKernel, unsigned int *FreqMhz, unsigned int *SymbolRateKhz);
    int REALTEK_I_DVBS2_BlindScan_AcquireSignal(DEMOD* pDemodKernel, unsigned int *SymbolRateKhz, int *Fcfo, unsigned char *bTpLock);
    int REALTEK_I_DVBS2_Blindscan_TPListEnhancement(DEMOD* pDemodKernel);
    int REALTEK_I_DVBS2_Blindscan_AddTPList(DEMOD* pDemodKernel);
    int REALTEK_I_DVBS2_ChangeStandard(DEMOD* pDemodKernel, unsigned int Mode);

    void REALTEK_I_DVBS2_Lock(DEMOD* pDemodKernel);
    void REALTEK_I_DVBS2_Unlock(DEMOD* pDemodKernel);

#define REALTEK_I_DVBS2_DBG(fmt, args...)        rtd_printk_demod(KERN_DEBUG, "DEMO", "DVBS2_DEBUG, " fmt, ##args); 
#define REALTEK_I_DVBS2_INFO(fmt, args...)      rtd_printk_demod(KERN_INFO, "DEMO", "DVBS2_INFO, " fmt, ##args);
#define REALTEK_I_DVBS2_WARNING(fmt, args...)   rtd_printk_demod(KERN_WARNING, "DEMO", "DVBS2_WARNING, " fmt, ##args);

#endif // __DEMOD_REALTEK_I_DVBS2_H__
