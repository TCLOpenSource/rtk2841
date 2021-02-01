#ifndef RTKDEMUX_PCRSYNC_H
#define RTKDEMUX_PCRSYNC_H

#include <linux/kernel.h>
#include "rtkdemux_common.h"
#include "rtkdemux_pcrdebugger.h"
#include "rtkdemux_pcrqueue.h"
#include "rtkdemux_LinearRegression.h"
#include "rtkdemux_pcrtracking.h"


typedef struct {
    int64_t pcrBase;	/*the first pcr*/
    int64_t stcBase;	/*the time when receive the first pcr*/
    int64_t pcr;	/*current pcr*/
    int64_t stc;	/*current time*/
} NAVDTVPCRINFO;

typedef struct {
    int64_t lastPCR;
    int64_t lastSTC;
    int64_t PCR;
    int64_t STC;
    int counter;
    int64_t firstSamplePTS;
} NAVHACKRCD;


typedef struct {
    int     aByteRate;
    int     vByteRate;
    int64_t aPcrOffset;
    int64_t vPcrOffset;
    int64_t aPcrRef;
    int64_t vPcrRef;

    /* variables used to calcuate aPcrOffset and aByteRate */
    int aReadSize;
    int vReadSize;
    int64_t aPCR;
    int64_t vPCR;
    int64_t aPrevDemuxPTS;
    int64_t vPrevDemuxPTS;
} SWDEMUXPCR;

typedef struct {
    int64_t pcrCheckTimeout;
    int64_t oldPCR;
    int64_t newPCR;
    int detectPcrCnt;
    bool checkPcrExitEnd;
    bool checkPacketReady;
} PCREXISTDETECT;

typedef enum {
	PCR_EXIST_STATUS_STILL_CHECK = 0,
	PCR_EXIST_STATUS_ALREADY_GOT,
	PCR_EXIST_STATUS_TIMEOUT,
} PCR_EXIST_STATUS;

struct PCRTRK_MANAGER_T_;

typedef struct DEMUX_PCRSYNC_T_ {
    REFCLOCK *pRefClock;
    struct PCRTRK_MANAGER_T_ *pPcrRecoveryManager;

    unsigned char tunerHandle;
    bool isUnderFreeRunMode; //Enter this mode due to unstable RCD

    AUDIO_DEC_TYPE audioType;

    int64_t rcd;    /*the latest rcd*/
    int64_t stc;    /*the latest stc*/
    int64_t pcr;    /*the latest pcr*/
    int64_t nextPCR;    /*the next pcr*/
    int64_t nextSTC;    /*the next pcr*/
    int64_t lastVideoSystemPTS ;    /*the latest video presentation pts*/
    int64_t lastAudioSystemPTS ;    /*the latest audio presentation pts*/
    int64_t lastDemuxAudioPTS;
    int64_t lastDemuxVideoPTS;
    int64_t prevVideoDemuxPTS;  /*the second latest video demux pts*/
    int64_t prevAudioDemuxPTS;  /*the second latest audio demux pts*/
    int64_t prevRcd;

    // NOTICE: following are virtual PCR mode related variables
    //         do NOT use them directly in code.
    int64_t rcdStableCount;
    int64_t rcdStableCheckCount;
    int64_t rcdUnstableCount;
    int64_t rcdUnstableCheckCount;

    int64_t audioFullnessLowCount;
    int64_t audioFullnessLowCheckNum;
    int64_t lastAudioFullnessLowCheckNum;
    int64_t lastMPTS;           /*the latest master pts*/
    int64_t resetPTS;
	DEMUX_LINEARREGRESSION_T LRegress;

    bool    bCheckPcrOffset;    /*calculate pcr offset at the first time. bCheckPcrOffset = true means pcrOffset is indeterminate.*/
    int64_t pcrOffset;          /*current pcr offset*/
    int64_t pcrTargetOffset;          /*current pcr offset*/
    int64_t pcrDefaultOffset;   /*initial pcr offset. it may depend on video codec or project setting*/
    int64_t pcrOffsetApproachPTS;
    int64_t masterPassPTSFreerunEstimated;
    int64_t freerun_checkTimeout;
    bool    waitForPcrOffsetChanged;
    bool    wrapAroundRecheckPcrOffset;
    bool    audioWrapAroundRecheckPcrOffset;
    bool    videoWrapAroundRecheckPcrOffset;
	unsigned long videoFreeRunThreshold;

    bool bPcrBackTrack;
    bool bWrapAround;

    /*for pcr hack mode*/
    int64_t timeToWaitForBothAVPkt;
    int64_t startAudioPts;  /*the first audio demux pts*/
    int64_t startVideoPts;  /*the first video demux pts*/
    bool bUseHackPCR;
    bool bForceHackPCR;
    bool bUseAudioPTS;
    NAVHACKRCD audioRCD;    /*used when bUseAudioPTS = true*/
    NAVHACKRCD videoRCD;    /*used when bUseAudioPTS = false*/

    /*for pcr/pts stable check*/
   // bool bAudioPCRStable;
  //  bool bVideoPCRStable;
  //  int64_t pcrStableCheckStart;    /*the latest time in PTS to check if pcr is stable*/
  //  int64_t ptsStableCheckStart;    /*the latest time in PTS to check if pts is stable*/
    int  audioPtsUnstableCounter ;
    int  audioPtsStableCounter ;
    int  videoPtsUnstableCounter ;
    int  videoPtsStableCounter ;
    int  avPtsUnstableCounter ;
    int  avPtsStableCounter ;
    bool bAudioPTSStable ;
    bool bVideoPTSStable ;

    int noAudioPtsCounter;
    int audioPtsCounter;
    bool bNoAudioPts;
    bool bVideoFreerun;
    bool bAudioFreerun;
    int noVideoPtsCounter;
    int videoPtsCounter;
    bool bNoVideoPts;

    SWDEMUXPCR swPCRInfo;
    PCREXISTDETECT pcrExistDetect;

    /*for debug*/
    PCR_DEBUGGER_T pcrDebugger;
    int64_t pcrPrintPTS;

} DEMUX_PCRSYNC_T;

void PCRSYNC_Reset(DEMUX_PCRSYNC_T *pPcrProcesser, REFCLOCK *pRefClock, unsigned char tunerHandle, struct PCRTRK_MANAGER_T_ *pPcrRecoveryManager);
void PCRSYNC_UpdateRCD(DEMUX_PCRSYNC_T *pPcrProcesser, NAVDTVPCRINFO pcrinfo);
void PCRSYNC_UpdateDemuxPTS(DEMUX_PCRSYNC_T *pPcrProcesser, bool bVideo, int64_t pts);
bool PCRSYNC_GetAVSyncStatus(DEMUX_PCRSYNC_T *pPcrProcesser);
void PCRSYNC_SetAudioType(DEMUX_PCRSYNC_T *pPcrProcesser, AUDIO_DEC_TYPE audioType);
bool PCRSYNC_GetRCDUnstableStatus(const DEMUX_PCRSYNC_T *pPcrProcesser, int64_t *rcdUnstableCount, int64_t *rcdUnstableCheckCount);
void PCRSYNC_SetFreeRunMode(DEMUX_PCRSYNC_T *processor, bool isUnderFreeRunMode);
bool PCRSYNC_IsUnderFreeRunMode(const DEMUX_PCRSYNC_T *pcrocessor);
bool PCRSYNC_EvaluateRcdStability(DEMUX_PCRSYNC_T *processor, int64_t newPcr, int64_t newStc);
void PCRSYNC_EnterFreeRunMode(DEMUX_PCRSYNC_T *pcrocessor);
void PCRSYNC_ReturnToPCRMaster(DEMUX_PCRSYNC_T *pcrocessor);
bool PCRSYNC_ShouldReturnToPCRMaster(const DEMUX_PCRSYNC_T *processor);
bool PCRSYNC_ShouldResetRcdStabilityCheckStatus(const DEMUX_PCRSYNC_T *processor);
void PCRSYNC_ResetRcdStabilityCheckStatus(DEMUX_PCRSYNC_T *processor);
void PCRSYNC_UpdateProcessorRcd(DEMUX_PCRSYNC_T *processor, int64_t newPcr, int64_t newStc);
void PCRSYNC_CheckPTSDataStable(DEMUX_PCRSYNC_T *pPcrProcesser);
PCR_EXIST_STATUS PCRSYNC_CheckPcrExist(DEMUX_PCRSYNC_T *pPcrProcesser);

#endif /*RTKDEMUX_PCRSYNC_H*/
