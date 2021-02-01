#include "rtkdemux_pvr.h"

#ifndef abs64
#define abs64 abs
#endif

void PVR_CheckPvrAudioStable(demux_channel *pCh, int64_t pts)
{
	REFCLOCK * const pRefClock = DEMUX_GetReferenceClock(pCh);
	int64_t videoSystemPTS = DEMUX_reverseLongInteger(pRefClock->videoSystemPTS);
	long audioFreeRunThreshold = DEMUX_reverseInteger(pRefClock->audioFreeRunThreshold);
	if (videoSystemPTS == -1)
		return;

	if (pts > videoSystemPTS || videoSystemPTS - pts >= audioFreeRunThreshold)
		SET_FLAG(pCh->status, STATUS_PVR_AUDIO_IS_STABLE);
	dmx_mask_print(DEMUX_AUDIO_STABLE_DEBUG,"(((vSysPTS:%lld, aDemuxPTS:%lld, stable = %d)))\n", videoSystemPTS,	pts, HAS_FLAG(pCh->status, STATUS_PVR_AUDIO_IS_STABLE) != 0);

}

void PVR_PvrStartToPlay(demux_channel *pCh)
{
	REFCLOCK * const refClock = DEMUX_GetReferenceClock(pCh);

	/* stop to do buffering */
	pCh->bPendingOnPTSCheck = false;
	pCh->bPendingOnFullness = false;

	/* let master starts to play */
	REFCLK_SetTimeout(refClock, 0);
	PVR_EnableTPRateControl(pCh, true);

	/* from now on, we want to take only 200 ms to check if audio can be stable or not */
	pCh->startCheckAudioStable = CLOCK_GetPTS();

	/* start to check if it is possible that audio can catch video or not */
	SET_FLAG(pCh->status, STATUS_CHECK_PVR_AUDIO_STABLE);

	/* audio is not master at the beginning of presentation */
	RESET_FLAG(pCh->status, STATUS_PVR_AUDIO_IS_STABLE);
}

#define ENABLE_FRAME_RATE_CONTROL
void PVR_EnableTPRateControl(demux_channel *pCh, bool bEnable)
{
	TPK_TP_STATUS_T tpStatus;
	// NOTICE: caller should unlock pCh->mutex first to avoid dead lock happen.
	mutex_lock(&pCh->mutex);
#ifdef ENABLE_FRAME_RATE_CONTROL
	if(bEnable && HAS_FLAG(pCh->status, STATUS_APVR_PLAYBACK_START))
	{
		/* Do not enable TP rate control when APVR file playback */
		mutex_unlock(&pCh->mutex);
		return;
	}
	if (RHAL_GetTpStatus(pCh->tunerHandle, &tpStatus) == TPK_SUCCESS) {
		/*Enable frame rate control if timestamp is available */
		bool bCanTurnOn = bEnable && (tpStatus.tp_param.ts_in_tsp_len == byte_192);
		RHAL_MTPFrameControl(pCh->tunerHandle, bCanTurnOn);
		if (bCanTurnOn)
			SET_FLAG(pCh->status, STATUS_TP_RATE_CONTROL_ENABLED);
		else
			RESET_FLAG(pCh->status, STATUS_TP_RATE_CONTROL_ENABLED);
	}
	else {
		RHAL_MTPFrameControl(pCh->tunerHandle, false);
		RESET_FLAG(pCh->status, STATUS_TP_RATE_CONTROL_ENABLED);
		dmx_crit("[%s %d] Error!RHAL_GetTpStatus fail! Can't start TP Rate Control !\n", __func__, __LINE__);
	}
#else
	RHAL_MTPFrameControl(pCh->tunerHandle, false);
	RESET_FLAG(pCh->status, STATUS_TP_RATE_CONTROL_ENABLED);
#endif
	mutex_unlock(&pCh->mutex);
}

void PVR_DetectAudioOnlyFile(demux_channel *pCh)
{
	if (pCh->tp_src == MTP) {
		if (pCh->activeTarget[DEMUX_TARGET_VIDEO].pid == -1 && pCh->activeTarget[DEMUX_TARGET_VIDEO_2ND].pid == -1 && pCh->avSyncMode != NAV_AVSYNC_AUDIO_ONLY)
			DEMUX_ResetAVSync(pCh, NAV_AVSYNC_AUDIO_ONLY);
	}
}

void PVR_CheckPTSDiff(demux_channel *pCh)
{
	DEMUX_PCRSYNC_T *pPcrProcesser;
	REFCLOCK * const refClock = DEMUX_GetReferenceClock(pCh);
	if (!pCh->bPendingOnPTSCheck)
		return;

	PVR_DetectAudioOnlyFile(pCh);
	pPcrProcesser = &pCh->pcrProcesser;

	if (((pPcrProcesser->startVideoPts > pPcrProcesser->startAudioPts) && (pPcrProcesser->lastDemuxAudioPTS - pPcrProcesser->startVideoPts) >= pCh->avSyncStartupPTS)
       || (pPcrProcesser->startVideoPts <= pPcrProcesser->startAudioPts && (pPcrProcesser->lastDemuxVideoPTS-pPcrProcesser->startAudioPts) >= pCh->avSyncStartupPTS)) {
		PVR_PvrStartToPlay(pCh);
		dmx_crit("[%s %d] Start to play: APTS = %lld, VPTS = %lld\n", __func__, __LINE__, pPcrProcesser->lastDemuxAudioPTS, pPcrProcesser->lastDemuxVideoPTS);
	}

	if (pCh->bPendingOnPTSCheck && REFCLK_GetRCD(refClock) != -1) {
		PVR_PvrStartToPlay(pCh);
		dmx_crit("[%s %d] Check PTS timeout: APTS = %lld, VPTS = %lld\n", __func__, __LINE__, pPcrProcesser->lastDemuxAudioPTS, pPcrProcesser->lastDemuxVideoPTS);
	}

	if ((REFCLK_GetRCD(refClock) == -1 && pPcrProcesser->startVideoPts != -1 && pPcrProcesser->startAudioPts != -1 && abs64(pPcrProcesser->startVideoPts -pPcrProcesser->startAudioPts) >= 3000*DEMUX_CLOCKS_PER_MS)
		|| (REFCLK_GetRCD(refClock) == -1 && pPcrProcesser->startAudioPts == -1 && pCh->activeTarget[DEMUX_TARGET_AUDIO].pid == -1 && pCh->activeTarget[DEMUX_TARGET_AUDIO_2ND].pid == -1)){
		pCh->avSyncStartupFullness = 512 * 1024;
		pCh->bPendingOnFullness = true;
		pCh->avSyncStartupPTS = 0;
		pCh->bPendingOnPTSCheck = false;
		dmx_crit("[%s %d] A/V startPTs diff >= 270000 (3 secs)\n", __func__, __LINE__);
	}
}

