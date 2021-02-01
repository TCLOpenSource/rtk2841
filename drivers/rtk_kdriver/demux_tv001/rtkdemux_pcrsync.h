#ifndef RTKDEMUX_PCRSYNC_H
#define RTKDEMUX_PCRSYNC_H

#include <linux/kernel.h>
#include "rtkdemux_common.h"
#include "rtkdemux_pcrdebugger.h"
#include "rtkdemux_pcrqueue.h"
#include "rtkdemux_LinearRegression.h"
#include "rtkdemux_pcrtracking.h"

#define RCD_STABILITY_SAMPLE_NUM 150

typedef struct {
	int64_t pcrBase; /*the first pcr*/
	int64_t stcBase; /*the time when receive the first pcr*/
	int64_t pcr;	 /*current pcr*/
	int64_t stc;	 /*current time*/
} NAVDTVPCRINFO;

typedef struct {
	int64_t aPcrRef;    /*the lastest PCR parsed from AF*/
	int64_t vPcrRef;    /*the lastest PCR parsed from AF*/
	int64_t aDemuxPCR;  /*the closest PCR to the latest demux audio pts*/
	int64_t vDemuxPCR;  /*the closest PCR to the latest demux video pts*/
	int64_t aDemuxPTS;  /*the first demux audio pts after aDemuxPCR*/
	int64_t vDemuxPTS;  /*the first demux video pts after vDemuxPCR*/
	int64_t avPCR;      /*the PCR if aDemuxPCR = vDemuxPCR*/
	int64_t aPTS;       /*the first demux audio pts after avPCR*/
	int64_t vPTS;       /*the first demux video pts after avPCR*/
} SWDEMUXPCR;

typedef struct
{
	int64_t demuxPCR;
	int64_t demuxAPTS;
	int64_t demuxVPTS;
} NAVDTVSWDEMUXPCRINFO; 		// pcr & pts pair

enum RCD_UNSTABLE_LEVEL_
{
	RCD_UNSTABLE_LEVEL_S = 1600,
	RCD_UNSTABLE_LEVEL_A = 1200,
	RCD_UNSTABLE_LEVEL_B = 800,
	RCD_UNSTABLE_LEVEL_C = 400,
};

enum RCD_UNSTABLE_WEIGHTS_
{
	RCD_UNSTABLE_WEIGHTS_S = 512,
	RCD_UNSTABLE_WEIGHTS_A = 64,
	RCD_UNSTABLE_WEIGHTS_B = 8,
	RCD_UNSTABLE_WEIGHTS_C = 1,
	RCD_UNSTABLE_WEIGHTS_STABLE = 0,
};

enum RCD_UNSTABLE_THRESHOLD_
{
	RCD_UNSTABLE_THRESHOLD_LOW = 10,
	RCD_UNSTABLE_THRESHOLD_HIGH = 800,
};

enum AVPTS_UNSTABLE_THRESHOLD_
{
	AVPTS_UNSTABLE_THRESHOLD_LOW = 500,
	AVPTS_UNSTABLE_THRESHOLD_CLOCK = 18000,
};

enum AVPTS_UNSTABLE_THRESHOLD_COUNTER_
{
	AVPTS_UNSTABLE_THRESHOLD_COUNTER_LOW = 10,
	AVPTS_UNSTABLE_THRESHOLD_COUNTER_MID = 30,
};

typedef struct DEMUX_RCD_STABILITY_MONITOR_T_ {
	int array[RCD_STABILITY_SAMPLE_NUM];
	int index;
	int rcdUnstableTotal;           /* total rcd statble value in an array */
	bool bIsArrayWrapAround;        /* flag is 1 means wrap-around; otherwise, the flag is 0 */
} DEMUX_RCD_STABILITY_MONITOR_T;

struct PCRTRK_MANAGER_T_;

typedef struct DEMUX_PCRSYNC_T_ {
	REFCLOCK *pRefClock;
	struct PCRTRK_MANAGER_T_ *pPcrRecoveryManager;

	unsigned char tunerHandle;
	bool isUnderFreeRunMode; //Enter this mode due to unstable RCD
	bool isUnderFreeRunModePTS; //Enter this mode due to unstable PTS

	DEMUX_LINEARREGRESSION_T LRegress;
	SWDEMUXPCR swPCRInfo;

	int trackingMode;
	int isTrackingSteady;

	bool bAdjusted;
	bool bHighWaterLevelMode;
	bool bVirtualPcrMode;

	bool bHasAudioPidOrDest;
	bool bHasVideoPidOrDest;

	int64_t startAudioPts;  /*the first audio demux pts*/
	int64_t startVideoPts;  /*the first video demux pts*/
	int64_t lastDemuxAudioPTS;
	int64_t lastDemuxVideoPTS;
	int64_t lastDemuxSubAudioPTS;
	int64_t prevAudioDemuxPTS;  /*the second latest audio demux pts*/
	int64_t prevVideoDemuxPTS;  /*the second latest video demux pts*/
	int64_t afterGapAudioPTS;    /*the first audio demux pts after a big pts gap happen*/
	int64_t afterGapVideoPTS;    /*the first video demux pts after a big pts gap happend*/

	int64_t rcd;    /*the latest rcd*/
	int64_t stc;    /*the latest stc*/
	int64_t pcr;    /*the latest pcr*/
	int64_t nextPCR;    /*the next pcr*/
	int64_t nextSTC;    /*the next pcr*/

	int64_t firstSTC;
	int64_t firstPCR;
	int64_t realSTC;
	int64_t realPCR;

	int64_t lastAudioSystemPTS ;    /*the latest audio presentation pts*/
	int64_t lastVideoSystemPTS ;    /*the latest video presentation pts*/
	int64_t prevAudioSystemPTS;
	int64_t prevVideoSystemPTS;
	

	int64_t pcrDefaultOffset;   /*initial pcr offset. it may depend on video codec or project setting*/
	int64_t pcrOffset;          /*current pcr offset*/

	DEMUX_RCD_STABILITY_MONITOR_T rcdStabilityMonitor;

	int audioFullnessHighCount;
	int audioFullnessHighCheckCount;
	int audioFullnessLowCount;
	int audioFullnessLowCheckCount;

	int videoFullnessHighCount;
	int videoFullnessHighCheckCount;
	int videoFullnessLowCount;
	int videoFullnessLowCheckCount;

	bool bCheckPcrOffsetAgain;
	bool bPassGap;
	enum {
		HAVE_STEADY_OFFSET = 0,
		PREPARE_TO_GET_OFFSET = 1,
		GOTO_GET_OFFSET = 2,
		EVALUATE_STEADY = 3,
	} checkPcrOffset;    /*calculate pcr offset at the first time. bCheckPcrOffset = true means pcrOffset is indeterminate.*/

	enum {
		NO_GAP = 0,
		WRAP_AROUND_GAP = 1,
		JUMP_GAP = 2,
	} pcrGapType;

	enum {
		NONE = 0,
		AUDIO_TYPE = 1,
		VIDEO_TYPE = 2,
	} preferAVPTS, referenceAVPTS;

	bool bAudioRingBufferFull;
	bool bVideoRingBufferFull;

	/* to evaluate if it is weak signal or not*/
	bool bBadSignal ;
	int  noSignalCounter ;
	int  SignalCounter ;

	/* to evaluate if the channel contain PCR or not */
	bool bNoPCR ;
	int  noPCRCounter ;
	int  PCRCounter ;

	/* to evaluate if the channel contain audio pts or not */
	bool bNoAudioPts ;
	int  noAudioPtsCounter ;
	int  audioPtsCounter ;

	/* to evaluate if the channel contain video pts or not*/
	bool bNoVideoPts ;
	int  noVideoPtsCounter ;
	int  videoPtsCounter ;

	bool bNoAudioOutputPts ;
	int  noAoutPtsCounter ;
	int  aoutPtsCounter ;

	bool bNoVideoOutputPts ;
	int  noVoutPtsCounter ;
	int  voutPtsCounter ;
	int64_t checkVideoPidStart;

	int64_t pcrCheckPTS;

	int64_t resetPTS;

	int32_t AptsStableCounter;
	int32_t AptsUnStableCounter;
	bool AVPtsCheckFlag;
	int64_t lastAudioClock;
	int64_t AudioPTSDiff;
	int64_t AudioCheckClkDiff;

	/*for debug*/
	PCR_DEBUGGER_T pcrDebugger;
	int64_t pcrPrintPTS;

} DEMUX_PCRSYNC_T;

void PCRSYNC_Reset(DEMUX_PCRSYNC_T *pPcrProcesser, REFCLOCK *pRefClock, unsigned char tunerHandle, struct PCRTRK_MANAGER_T_ *pPcrRecoveryManager);
void PCRSYNC_FlushAudioPidOrDest(DEMUX_PCRSYNC_T *pPcrProcesser, bool HasAudioPidOrDest);
void PCRSYNC_FlushVideoPidOrDest(DEMUX_PCRSYNC_T *pPcrProcesser, bool HasVideoPidOrDest);
void PCRSYNC_UpdateRCD(DEMUX_PCRSYNC_T *pPcrProcesser, int pcrpid);
void PCRSYNC_UpdateDemuxPTS(DEMUX_PCRSYNC_T *pPcrProcesser, bool bVideo, bool bAudio, int64_t pts, bool IsSubAudio);
void PCRSYNC_UpdateAudioSWPCRInfo(DEMUX_PCRSYNC_T *pPcrProcesser, int64_t pts);
void PCRSYNC_UpdateVideoSWPCRInfo(DEMUX_PCRSYNC_T *pPcrProcesser, int64_t pts);

#endif /*RTKDEMUX_PCRSYNC_H*/
