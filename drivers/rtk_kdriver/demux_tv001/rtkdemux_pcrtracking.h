#ifndef RTKDEMUX_PCRTRACKING_H
#define RTKDEMUX_PCRTRACKING_H

#include <linux/kernel.h>
#include <linux/mutex.h>
#include <linux/kthread.h>
#include <linux/wait.h>
#include "rtkdemux_common.h"
#include "rtkdemux_clock.h"
#include "rtkdemux_pcrsync.h"


#define NO_TRACKING      -1
#define PCR_TRACKING      0
#define ABUFFER_TRACKING  1
#define VBUFFER_TRACKING  2


#ifdef CONFIG_RTK_KDRV_MULTI_TP_CLOCK
#define DEMUX_PCRTRACKING_MANAGER_NUM 2

#else
#define DEMUX_PCRTRACKING_MANAGER_NUM 1
#endif

#define TRACKING_TREND_NUM  10

#define RCD_SAMPLE_NUM 10

typedef struct {
	int64_t pcr;
	int64_t stc;
	int64_t lastPcr;
	int64_t lastStc;

	int64_t videoDiff;
	int64_t audioDiff;

	int64_t prevRCD;
	int speed_advice; /* 1: go faster, 0: no need to change, -1: go slower */
	int64_t updateIntervalTick;

	/*For Pcr master determine. */
	int     rcdIdx;
	int64_t sampleRCD[RCD_SAMPLE_NUM];

	int64_t baseRCD;
} PCRTRK_SAMPLING_T;

typedef struct {
    volatile unsigned int *sys_pll_disp_sd1;
    volatile unsigned int *sys_pll_disp_sd2;
    volatile unsigned int *sys_dvfs_dds;
    volatile unsigned int *sys_pll_dispa_sd1;
    volatile unsigned int *sys_pll_dispa_sd2;
    volatile unsigned int *sys_dvfs_ddsa;
    volatile unsigned int *sys_pll_dispb_sd1;
    volatile unsigned int *sys_pll_dispb_sd2;
    volatile unsigned int *sys_dvfs_ddsb;

} PCRTRK_REGISTER_T;

typedef enum {
	PCRTRK_TM_INIT,
	PCRTRK_TM_START,
	PCRTRK_TM_NORMAL,
	PCRTRK_TM_FINE_TUNE,
} PCRTRK_TUNING_MODE_E;

typedef enum {
    PCRTRK_SUSPEND,    /*go to READY if bIsSuspending = false*/
    PCRTRK_READY,
    PCRTRK_SAMPLING,
    PCRTRK_DETERMINE,
    PCRTRK_SET_CLOCK,		/* no pcr smoothing */
    PCRTRK_WAITING,
} PCRTRK_STATE_E;

typedef struct PCRTRK_MANAGER_T_{
	PCRTRK_SAMPLING_T sampling;
	PCRTRK_REGISTER_T registers;
	PCRTRK_STATE_E    state;

	unsigned char tunerHandle;

	int isTrackingMode;
	int trackingMode;

	bool infoUpdated;
	bool adjustUpdated;
	int  speedAdjust; /* 1: go faster, 0: no need to change, -1: go slower */

	unsigned char switchStepSpan;
	PCRTRK_TUNING_MODE_E tuningMode;

	int64_t nextPCR;
	int64_t nextSTC;
	int64_t RCD;
	int64_t videoPTS;
	int64_t audioPTS;
	int64_t videoSysPTS;
	int64_t audioSysPTS;
	int64_t cc;

	struct task_struct *pThread;
	struct mutex        mutex;
	bool                bIsSuspending;
	bool                bIsTerminating;
	bool                bInitialized;

	int                currentStepIdx;
	int                nextStepIdx;    

	int                trendCountDown;
	int                lastTrackingTrend[TRACKING_TREND_NUM];
	int                extremeStep;
	int                extremeStepCountDown;

	wait_queue_head_t  resumeWQ;
} PCRTRK_MANAGER_T;

struct DEMUX_PCRSYNC_T_;

void PCRTRACK_Initialize(PCRTRK_MANAGER_T *pManager, unsigned char tunerHandle);
void PCRTRACK_Release(PCRTRK_MANAGER_T *pManager);
bool PCRTRACK_Start(PCRTRK_MANAGER_T *pManager, unsigned char tunerHandle);
void PCRTRACK_Stop(PCRTRK_MANAGER_T *pManager);
void PCRTRACK_UpdateSpeedAdjust(PCRTRK_MANAGER_T *pManager, int adjust, bool updated);
int  PCRTRACK_GetSpeedAdjust(PCRTRK_MANAGER_T *pManager);
void PCRTRACK_CheckTrackingSteady(PCRTRK_MANAGER_T *pManager, struct DEMUX_PCRSYNC_T_ *pPcrProcesser);
void PCRTRACK_UpdatePosition(PCRTRK_MANAGER_T *pManager, struct DEMUX_PCRSYNC_T_ *pPcrProcesser);
long PCRTRACK_ChoosePCRClock (unsigned char tunerHandle);
void PCRTRACK_SMP_Reset(PCRTRK_SAMPLING_T *pSampling);
void PCRTRACK_REG_ResetClock(PCRTRK_REGISTER_T *pRegister);
void PCRTRACK_REG_Set_NCODE(PCRTRK_REGISTER_T *pRegister, unsigned long value);
void PCRTRACK_REG_Set_FCODE(PCRTRK_REGISTER_T *pRegister, unsigned long value);
void PCRTRACK_REG_Set_PLLDDS_OC(PCRTRK_REGISTER_T *pRegister, unsigned char value);
#endif /*RTKDEMUX_PCRTRACKING_H*/
