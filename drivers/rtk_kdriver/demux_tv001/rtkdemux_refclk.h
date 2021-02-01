#ifndef RTKDEMUX_REFERENCE_CLOCK_H
#define RTKDEMUX_REFERENCE_CLOCK_H

#include "rtkdemux_common.h"

#define DEFAULT_FREE_RUN_THRESHOLD  (90000 * 4)  // 4 seconds
#define MIN_FREE_RUN_THRESHOLD      0
//#define MAX_FREE_RUN_THRESHOLD      0xffffffff
#define MAX_FREE_RUN_THRESHOLD      (90000 * 10)  // 10 seconds

#define DEFAULT_FREE_RUN_VIDEO_THRESHOLD DEFAULT_FREE_RUN_THRESHOLD
#define DEFAULT_FREE_RUN_AUDIO_THRESHOLD DEFAULT_FREE_RUN_THRESHOLD

//KTASKWBS-3085
//WOSQRTK-4967
#define FREE_RUN_THRESHOLD_FOR_MTP (4*90000)

/*KTASKWBS-5144*/
#define AUDIO_FREE_RUN_THRESHOLD_TO_WAIT (4*90000)

typedef struct { /* unfortunately only ETypes.h can be included by C source, so I have to put this "struct" here ...*/
    int64_t       RCD;
    int64_t       referenceClock;
    int64_t       videoSystemPTS;
    int64_t       audioSystemPTS;
    int64_t       videoRPTS;
    int64_t       audioRPTS;
    unsigned long videoContext;
    unsigned long audioContext;
    long          videoEndOfSegment;
} PRESENTATION_POSITIONS;

typedef enum {
    NAV_AVSYNC_PCR_MASTER = 0,
    NAV_AVSYNC_AUDIO_MASTER_AUTO = 1,
    NAV_AVSYNC_VIDEO_ONLY = 2,
    NAV_AVSYNC_FREE_RUN = 3,
    NAV_AVSYNC_AUDIO_ONLY = 4,
	NAV_AVSYNC_AUDIO_MASTER_AF = 5,
    MASTERSHIP_NUM
} AV_SYNC_MODE;

void REFCLK_Reset(REFCLOCK *pRefClock, AV_SYNC_MODE avSyncMode, unsigned long videoFreeRunThreshold);
int64_t REFCLK_GetGPTSTimeout(REFCLOCK *pRefClock);
int64_t REFCLK_GetRCD(REFCLOCK *pRefClock);
void REFCLK_GetPresentationPositions(REFCLOCK *pRefClock, PRESENTATION_POSITIONS *pPosition);
void REFCLK_SetRCD(REFCLOCK *pRefClock, int64_t rcd);
void REFCLK_SetFreeRunThreshold(REFCLOCK *pRefClock, long videoFreeRunThr, long audioFreeRunThr, long audioFreeRunThrToWait);
void REFCLK_SetAudioFreeRunThreshold(REFCLOCK *pRefClock, long audioFreeRunThr, long audioFreeRunThrToWait);
void REFCLK_SetVideoFreeRunThreshold(REFCLOCK *pRefClock, long videoFreeRunThr);
void REFCLK_GetFreeRunThreshold(REFCLOCK *pRefClock, long *pVideoFreeRunThr, long *pAudioFreeRunThr, long *pAudioFreeRunThrToWait);
void REFCLK_CheckUnderflow(REFCLOCK *pRefClock, long *pVideoUnderflow, long *pAudioUnderflow);
void REFCLK_SetTimeout(REFCLOCK *pRefClock, int64_t timeout);
void REFCLK_SetMasterShip(REFCLOCK *pRefClock, AV_SYNC_MODE avSyncMode);

/* The definition of clock mode is TPK_PCR_CLK_SRC_T declaired in tp_drv_api.h */
void REFCLK_SetClockMode(REFCLOCK *pRefClock, long clockMode);
long REFCLK_GetClockMode(REFCLOCK *pRefClock);

#endif /* RTKDEMUX_REFERENCE_CLOCK_H */

