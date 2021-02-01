#include <linux/kernel.h>
#include <linux/string.h>
#include "rtkdemux_refclk.h"
#include "rtkdemux_clock.h"
#include "rtkdemux_debug.h"
#include <tp/tp_drv_global.h>

extern unsigned long long DEMUX_reverseLongInteger(unsigned long long value);
extern unsigned long DEMUX_reverseInteger(unsigned long value);

void REFCLK_Reset(REFCLOCK *pRefClock, AV_SYNC_MODE avSyncMode, unsigned long videoFreeRunThreshold)
{
	unsigned long clockMode = pRefClock->clockMode;
	memset(pRefClock, 0 , sizeof(REFCLOCK)) ;

	/* don't reset clockMode */
	pRefClock->clockMode = clockMode;

	pRefClock->GPTSTimeout             = DEMUX_reverseLongInteger(0) ;
	pRefClock->videoFreeRunThreshold   = DEMUX_reverseInteger(videoFreeRunThreshold) ;
	pRefClock->audioFreeRunThreshold   = DEMUX_reverseInteger(DEFAULT_FREE_RUN_AUDIO_THRESHOLD) ;
	pRefClock->audioFreeRunThresholdToWait   = DEMUX_reverseInteger(DEFAULT_FREE_RUN_AUDIO_THRESHOLD) ;
	pRefClock->RCD                     = DEMUX_reverseLongInteger(-1) ;
	pRefClock->RCD_ext                 = DEMUX_reverseInteger(-1) ;
	pRefClock->videoSystemPTS          = DEMUX_reverseLongInteger(-1) ;
	pRefClock->audioSystemPTS          = DEMUX_reverseLongInteger(-1) ;
	pRefClock->videoRPTS               = DEMUX_reverseLongInteger(-1) ;
	pRefClock->audioRPTS               = DEMUX_reverseLongInteger(-1) ;
	pRefClock->videoContext            = DEMUX_reverseInteger(-1) ;
	pRefClock->audioContext            = DEMUX_reverseInteger(-1) ;
	pRefClock->masterGPTS              = DEMUX_reverseLongInteger(-1) ;
	pRefClock->VO_Underflow            = DEMUX_reverseInteger(0) ;
	pRefClock->AO_Underflow            = DEMUX_reverseInteger(0) ;
	pRefClock->videoEndOfSegment       = DEMUX_reverseInteger(-1) ;
	pRefClock->audioEndOfSegment       = DEMUX_reverseInteger(-1) ;
	pRefClock->RCD_Audio               = DEMUX_reverseLongInteger(-1) ;
	pRefClock->RCD_Video               = DEMUX_reverseLongInteger(-1) ;

	REFCLK_SetMasterShip(pRefClock, avSyncMode);


	dmx_notice("%s _%d \n", __func__, __LINE__);
	/* change clock mode in DEMUX_StartPCRRecovery()/DEMUX_StopPCRRecovery */
	/* pRefClock->clockMode			   = DEMUX_reverseInteger(MISC_90KHz); */
}
void REFCLK_SetMasterShip(REFCLOCK *pRefClock, AV_SYNC_MODE avSyncMode)
{	
	if (avSyncMode == NAV_AVSYNC_PCR_MASTER) {
		pRefClock->mastership.systemMode   = (unsigned char)AVSYNC_FORCED_MASTER;
		pRefClock->mastership.videoMode    = (unsigned char)AVSYNC_FORCED_SLAVE;
		pRefClock->mastership.audioMode    = (unsigned char)AVSYNC_FORCED_SLAVE;
		pRefClock->mastership.masterState  = (unsigned char)AUTOMASTER_NOT_MASTER;
	} else if (avSyncMode == NAV_AVSYNC_AUDIO_MASTER_AUTO) {
		pRefClock->mastership.systemMode   = (unsigned char)AVSYNC_FORCED_SLAVE;
		pRefClock->mastership.videoMode    = (unsigned char)AVSYNC_AUTO_SLAVE;
		pRefClock->mastership.audioMode    = (unsigned char)AVSYNC_AUTO_MASTER;
		pRefClock->mastership.masterState  = (unsigned char)AUTOMASTER_NOT_MASTER;
	} else if (avSyncMode == NAV_AVSYNC_AUDIO_MASTER_AF) {
		pRefClock->mastership.systemMode   = (unsigned char)AVSYNC_FORCED_SLAVE;
		pRefClock->mastership.videoMode    = (unsigned char)AVSYNC_FORCED_SLAVE;
		pRefClock->mastership.audioMode    = (unsigned char)AVSYNC_FORCED_MASTER;
		pRefClock->mastership.masterState  = (unsigned char)AUTOMASTER_NOT_MASTER;
	} else if (avSyncMode == NAV_AVSYNC_VIDEO_ONLY) {
		pRefClock->mastership.systemMode   = (unsigned char)AVSYNC_FORCED_SLAVE;
		pRefClock->mastership.videoMode    = (unsigned char)AVSYNC_FORCED_MASTER;
		pRefClock->mastership.audioMode    = (unsigned char)AVSYNC_FORCED_SLAVE;
		pRefClock->mastership.masterState  = (unsigned char)AUTOMASTER_NOT_MASTER;
	} else if (avSyncMode == NAV_AVSYNC_AUDIO_ONLY) {
		pRefClock->mastership.systemMode   = (unsigned char)AVSYNC_FORCED_SLAVE;
		pRefClock->mastership.videoMode    = (unsigned char)AVSYNC_FORCED_SLAVE;
		pRefClock->mastership.audioMode    = (unsigned char)AVSYNC_FORCED_MASTER;
		pRefClock->mastership.masterState  = (unsigned char)AUTOMASTER_NOT_MASTER;
	} else if (avSyncMode == NAV_AVSYNC_FREE_RUN) {
		pRefClock->mastership.systemMode  = (unsigned char)AVSYNC_FORCED_SLAVE;
		pRefClock->mastership.videoMode   = (unsigned char)AVSYNC_FORCED_MASTER;
		pRefClock->mastership.audioMode   = (unsigned char)AVSYNC_FORCED_MASTER;
		pRefClock->mastership.masterState = (unsigned char)AUTOMASTER_NOT_MASTER;
	}
}
int64_t REFCLK_GetGPTSTimeout(REFCLOCK *pRefClock)
{
    int64_t timeout = DEMUX_reverseLongInteger(pRefClock->GPTSTimeout);
    return timeout;
}
int64_t REFCLK_GetRCD(REFCLOCK *pRefClock)
{
    int64_t rcd = DEMUX_reverseLongInteger(pRefClock->RCD);
    return rcd;
}
void REFCLK_GetPresentationPositions(REFCLOCK *pRefClock, PRESENTATION_POSITIONS *pPosition)
{
    pPosition->referenceClock = CLOCK_GetPTS();
    pPosition->RCD = DEMUX_reverseLongInteger(pRefClock->RCD);
    pPosition->videoSystemPTS = DEMUX_reverseLongInteger(pRefClock->videoSystemPTS);
    pPosition->audioSystemPTS = DEMUX_reverseLongInteger(pRefClock->audioSystemPTS);
    pPosition->videoRPTS = DEMUX_reverseLongInteger(pRefClock->videoRPTS);
    pPosition->audioRPTS = DEMUX_reverseLongInteger(pRefClock->audioRPTS);
    pPosition->videoContext = DEMUX_reverseInteger(pRefClock->videoContext);
    pPosition->audioContext = DEMUX_reverseInteger(pRefClock->audioContext);
    pPosition->videoEndOfSegment = DEMUX_reverseInteger(pRefClock->videoEndOfSegment);
}
void REFCLK_SetRCD(REFCLOCK *pRefClock, int64_t rcd)
{
    pRefClock->RCD = DEMUX_reverseLongInteger(rcd);
}
void REFCLK_SetFreeRunThreshold(REFCLOCK *pRefClock, long videoFreeRunThr, long audioFreeRunThr, long audioFreeRunThrToWait)
{
    pRefClock->videoFreeRunThreshold = DEMUX_reverseInteger(videoFreeRunThr);
    pRefClock->audioFreeRunThreshold = DEMUX_reverseInteger(audioFreeRunThr);
    pRefClock->audioFreeRunThresholdToWait = DEMUX_reverseInteger(audioFreeRunThrToWait);
}
void REFCLK_SetAudioFreeRunThreshold(REFCLOCK *pRefClock, long audioFreeRunThr, long audioFreeRunThrToWait)
{
    pRefClock->audioFreeRunThreshold = DEMUX_reverseInteger(audioFreeRunThr);
    pRefClock->audioFreeRunThresholdToWait = DEMUX_reverseInteger(audioFreeRunThrToWait);
}
void REFCLK_SetVideoFreeRunThreshold(REFCLOCK *pRefClock, long videoFreeRunThr)
{
    pRefClock->videoFreeRunThreshold = DEMUX_reverseInteger(videoFreeRunThr);
}
void REFCLK_GetFreeRunThreshold(REFCLOCK *pRefClock, long *pVideoFreeRunThr, long *pAudioFreeRunThr, long *pAudioFreeRunThrToWait)
{
    *pVideoFreeRunThr = DEMUX_reverseInteger(pRefClock->videoFreeRunThreshold);
    *pAudioFreeRunThr = DEMUX_reverseInteger(pRefClock->audioFreeRunThreshold);
    *pAudioFreeRunThrToWait = DEMUX_reverseInteger(pRefClock->audioFreeRunThresholdToWait);
}
void REFCLK_CheckUnderflow(REFCLOCK *pRefClock, long *pVideoUnderflow, long *pAudioUnderflow)
{
    *pVideoUnderflow = DEMUX_reverseInteger(pRefClock->VO_Underflow);
    *pAudioUnderflow = DEMUX_reverseInteger(pRefClock->AO_Underflow);
}
void REFCLK_SetTimeout(REFCLOCK *pRefClock, int64_t timeout)
{
    pRefClock->GPTSTimeout = DEMUX_reverseLongInteger(CLOCK_GetAVSyncPTS(pRefClock)+timeout) ;
}
void REFCLK_SetClockMode(REFCLOCK *pRefClock, long clockMode)
{
	pRefClock->clockMode = DEMUX_reverseInteger(clockMode);
}
long REFCLK_GetClockMode(REFCLOCK *pRefClock)
{
	return (TPK_PCR_CLK_SRC_T)DEMUX_reverseInteger(pRefClock->clockMode);
}

