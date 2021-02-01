#include <linux/math64.h>
#include <linux/string.h>
#include <linux/kernel.h>
#include "rtkdemux.h"
#include "rtkdemux_clock.h"
#include "rtkdemux_debug.h"
#include "rtkdemux_pcrsync.h"
#include "rtkdemux_refclk.h"


#define DTV_DELAY_TIME        (200*DEMUX_CLOCKS_PER_MS )

/* Please check the comment for abs in include/linux/kernel.h */
#ifndef abs64
#define abs64 abs
#endif


void PCRSYNC_GetCloser(DEMUX_PCRSYNC_T *pPcrProcesser, NAVDTVPCRINFO pcrinfo, NAVDTVSWDEMUXPCRINFO *closerInfo);
void PCRSYNC_SmoothPCR(DEMUX_PCRSYNC_T *pPcrProcesser , NAVDTVPCRINFO *pPcrinfo);
void PCRSYNC_HandleRCD(DEMUX_PCRSYNC_T *pPcrProcesser, NAVDTVPCRINFO pcrinfo);
void PCRSYNC_AdjustRCD(DEMUX_PCRSYNC_T *pPcrProcesser, NAVDTVPCRINFO pcrinfo);

void PCRSYNC_UpdatePCRStableStatus(DEMUX_PCRSYNC_T *pPcrProcesser, int pcrpid, NAVDTVPCRINFO pcrinfo);
void PCRSYNC_CheckPCRStable(DEMUX_PCRSYNC_T *pPcrProcesser);
void PCRSYNC_UpdatePTSStableStatus(DEMUX_PCRSYNC_T *pPcrProcesser, int64_t audioPTS, int64_t videoPTS);
void PCRSYNC_CheckPTSStable(DEMUX_PCRSYNC_T *pPcrProcesser);
void PCRSYNC_UpdateSignalStableStatus(DEMUX_PCRSYNC_T *pPcrProcesser);
void PCRSYNC_CheckSignalStable(DEMUX_PCRSYNC_T *pPcrProcesser);
void PCRSYNC_UpdateOutputStatus(DEMUX_PCRSYNC_T *pPcrProcesser);
void PCRSYNC_CheckOutputStable(DEMUX_PCRSYNC_T *pPcrProcesser);
void PCRSYNC_UpdateFullnessStatus(DEMUX_PCRSYNC_T *pPcrProcesser);
void PCRSYNC_CheckFullness(DEMUX_PCRSYNC_T *pPcrProcesser);
void PCRSYNC_UpdateRCDStableStatus(DEMUX_PCRSYNC_T *pPcrProcesser, NAVDTVPCRINFO pcrinfo);
void PCRSYNC_CheckRCDStable(DEMUX_PCRSYNC_T *pPcrProcesser);
void PCRSYNC_UpdateAVPTSStableStatus(DEMUX_PCRSYNC_T *pPcrProcesser);
void PCRSYNC_CheckAVPTSStable(DEMUX_PCRSYNC_T *pPcrProcesser);

void PCRSYNC_DEBUG_SaveAvSyncInfo(DEMUX_PCRSYNC_T *pPcrProcesser, NAVDTVPCRINFO *pcrinfo);


void SWDEMUXPCR_Reset(SWDEMUXPCR* pSwPCRInfo)
{
	memset(pSwPCRInfo, 0, sizeof(SWDEMUXPCR));
	pSwPCRInfo->aPcrRef = -1;
	pSwPCRInfo->vPcrRef = -1;
	pSwPCRInfo->aDemuxPCR = -1;
	pSwPCRInfo->vDemuxPCR = -1;
	pSwPCRInfo->aDemuxPTS = -1;
	pSwPCRInfo->vDemuxPTS = -1;
	pSwPCRInfo->avPCR = -1;
	pSwPCRInfo->aPTS = -1;
	pSwPCRInfo->vPTS = -1;
}

void PCRSYNC_ResetAbnormalCounters(DEMUX_PCRSYNC_T *pPcrProcesser)
{
	pPcrProcesser->audioFullnessHighCount = 0;
	pPcrProcesser->audioFullnessHighCheckCount = 0;
	pPcrProcesser->audioFullnessLowCount = 0;
	pPcrProcesser->audioFullnessLowCheckCount = 0;

	pPcrProcesser->videoFullnessHighCount = 0;
	pPcrProcesser->videoFullnessHighCheckCount = 0;
	pPcrProcesser->videoFullnessLowCount = 0;
	pPcrProcesser->videoFullnessLowCheckCount = 0;
}

void PCRSYNC_ResetVariables(DEMUX_PCRSYNC_T *pPcrProcesser)
{
	dmx_mask_print(DEMUX_PCRSYC_DEBUG,"[dtv(%d)] Reset Variables. first(PCR, STC)=(%lld, %lld).\n", (int)pPcrProcesser->tunerHandle, pPcrProcesser->firstPCR, pPcrProcesser->firstSTC);
	LRegress_Reset(&pPcrProcesser->LRegress);
	SWDEMUXPCR_Reset(&pPcrProcesser->swPCRInfo);

	pPcrProcesser->trackingMode = NO_TRACKING;
	pPcrProcesser->isTrackingSteady = 0;
	pPcrProcesser->bAdjusted = false;
	pPcrProcesser->bHighWaterLevelMode = false;
	pPcrProcesser->bVirtualPcrMode = false;
	pPcrProcesser->isUnderFreeRunMode = false;
	pPcrProcesser->isUnderFreeRunModePTS = false;
	pPcrProcesser->AVPtsCheckFlag = false;

	pPcrProcesser->startAudioPts = -1;
	pPcrProcesser->startVideoPts = -1;

	pPcrProcesser->lastDemuxAudioPTS = -1;
	pPcrProcesser->lastDemuxVideoPTS = -1;
	pPcrProcesser->prevAudioDemuxPTS = -1;
	pPcrProcesser->prevVideoDemuxPTS = -1;
	pPcrProcesser->lastDemuxSubAudioPTS = -1;

	pPcrProcesser->stc = -1;
	pPcrProcesser->pcr = -1;
	pPcrProcesser->rcd = -1;
	pPcrProcesser->nextSTC = -1;
	pPcrProcesser->nextPCR = -1;

	pPcrProcesser->firstSTC = -1;
	pPcrProcesser->firstPCR = -1;
	pPcrProcesser->realSTC = -1;
	pPcrProcesser->realPCR = -1;

	pPcrProcesser->lastVideoSystemPTS = -1;
	pPcrProcesser->lastAudioSystemPTS = -1;
	pPcrProcesser->prevAudioSystemPTS = -1;
	pPcrProcesser->prevVideoSystemPTS = -1;

	pPcrProcesser->afterGapVideoPTS = -1;
	pPcrProcesser->afterGapAudioPTS = -1;

	pPcrProcesser->pcrDefaultOffset = DTV_DELAY_TIME;
	pPcrProcesser->pcrOffset        = DTV_DELAY_TIME;

	pPcrProcesser->bCheckPcrOffsetAgain = false;
	pPcrProcesser->bPassGap = false;

	pPcrProcesser->checkPcrOffset = PREPARE_TO_GET_OFFSET;
	pPcrProcesser->pcrGapType = NO_GAP;
	pPcrProcesser->preferAVPTS = NONE;
	pPcrProcesser->referenceAVPTS = NONE;

	pPcrProcesser->bBadSignal = false;
	pPcrProcesser->noSignalCounter = 0;
	pPcrProcesser->SignalCounter = 0;

	pPcrProcesser->bNoPCR = false;
	pPcrProcesser->noPCRCounter = 0;
	pPcrProcesser->PCRCounter = 0;

	pPcrProcesser->bHasAudioPidOrDest = true;
	pPcrProcesser->bNoAudioPts = false;
	pPcrProcesser->noAudioPtsCounter = 0;
	pPcrProcesser->audioPtsCounter = 0;

	// (case1) change channl to audio only, bHasVideoPidOrDest shoud be false. 
	//          So bHasVideoPidOrDest default value should be false.
	// (Case2) chnage chanel has vidio channel. The flow is set video pid then video flush(PCRSyncReset)
	//          the bHasVideoPidOrDest will channge to false. This status is wrong
	// Base on Case1 and Casae2 , bHasVideoPidOrDest can not reset in here
	//pPcrProcesser->bHasVideoPidOrDest = false;
	pPcrProcesser->bNoVideoPts = false;
	pPcrProcesser->noVideoPtsCounter = 0;
	pPcrProcesser->videoPtsCounter = 0;

	pPcrProcesser->bNoAudioOutputPts = false;
	pPcrProcesser->noAoutPtsCounter = 0;
	pPcrProcesser->aoutPtsCounter = 0;

	pPcrProcesser->bNoVideoOutputPts = false;
	pPcrProcesser->noVoutPtsCounter = 0;
	pPcrProcesser->voutPtsCounter = 0;

	PCRSYNC_ResetAbnormalCounters(pPcrProcesser);

	pPcrProcesser->pcrCheckPTS = 0;
	pPcrProcesser->pcrPrintPTS = 0;



	pPcrProcesser->AptsStableCounter = 0;
	pPcrProcesser->AptsUnStableCounter = 0;
	pPcrProcesser->lastAudioClock = 0;
	pPcrProcesser->AudioPTSDiff = 0;
	pPcrProcesser->AudioCheckClkDiff = 0;

	pPcrProcesser->resetPTS = CLOCK_GetPTS();
	pPcrProcesser->checkVideoPidStart = CLOCK_GetPTS();
	memset(&pPcrProcesser->rcdStabilityMonitor, 0, sizeof(DEMUX_RCD_STABILITY_MONITOR_T));
}

void PCRSYNC_FlushAudioPidOrDest(DEMUX_PCRSYNC_T *pPcrProcesser, bool HasAudioPidOrDest)
{
	pPcrProcesser->bHasAudioPidOrDest = HasAudioPidOrDest;
}

void PCRSYNC_FlushVideoPidOrDest(DEMUX_PCRSYNC_T *pPcrProcesser, bool HasVideoPidOrDest)
{
	pPcrProcesser->bHasVideoPidOrDest = HasVideoPidOrDest;
}

void PCRSYNC_Reset(DEMUX_PCRSYNC_T *pPcrProcesser, REFCLOCK *pRefClock, unsigned char tunerHandle, PCRTRK_MANAGER_T *pPcrRecoveryManager)
{
	pPcrProcesser->tunerHandle = tunerHandle;
	pPcrProcesser->pRefClock = pRefClock;
	pPcrProcesser->pPcrRecoveryManager = pPcrRecoveryManager;

	PCRSYNC_ResetVariables(pPcrProcesser);

	PCRDEBUG_Reset(&pPcrProcesser->pcrDebugger);
	rtkdemux_dbg_dump_avsync_info_reset(tunerHandle);
}

bool PCRSYNC_GetPCR(DEMUX_PCRSYNC_T *pPcrProcesser, int pcrpid, NAVDTVPCRINFO *pcrinfo, int64_t currPTS)
{
	int64_t ret = TPK_SUCCESS;
	int64_t tmpPCR = 0;
	int64_t tmpSTC = 0;

	if ((pPcrProcesser->bBadSignal == true) || (currPTS - pPcrProcesser->pcrCheckPTS) > 900) {
		if (pcrpid > 0) {
			ret = RHAL_GetPCRTrackingStatus(pPcrProcesser->tunerHandle, &pcrinfo->pcr, &pcrinfo->stc, &pcrinfo->pcrBase, &pcrinfo->stcBase) ;
			if (ret != TPK_SUCCESS)
				memset(pcrinfo, 0, sizeof(NAVDTVPCRINFO));
			else {
				if ((pPcrProcesser->bBadSignal == true) && (pcrinfo->pcr > 0) && (pcrinfo->pcr != pPcrProcesser->firstPCR))
					PCRSYNC_ResetVariables(pPcrProcesser);
			}
		}

		if (pPcrProcesser->bBadSignal == true) {
			if ((currPTS - pPcrProcesser->pcrCheckPTS) > 900)
				pPcrProcesser->pcrCheckPTS = currPTS;
			else {
				if (currPTS < pPcrProcesser->pcrCheckPTS)
					pPcrProcesser->pcrCheckPTS = currPTS;
				return false;
			}
		} else {
			pPcrProcesser->pcrCheckPTS = currPTS;
		}
	} else {
		if (currPTS < pPcrProcesser->pcrCheckPTS)
			pPcrProcesser->pcrCheckPTS = currPTS;
		return false;
	}

	if (pPcrProcesser->firstPCR == -1) {
		if (pcrinfo->pcr > 0) {
			//printf("get first (pcr)(stc):(%lld)(%lld).\n", pcrinfo->pcr, pcrinfo->stc);
			pPcrProcesser->firstPCR = pcrinfo->pcr;
			pPcrProcesser->firstSTC = pcrinfo->stc;
		}
	} else {
		if ((pPcrProcesser->firstPCR != pcrinfo->pcr) || (pPcrProcesser->firstSTC != pcrinfo->stc)) {
			tmpPCR = pPcrProcesser->nextPCR;
			pPcrProcesser->nextPCR = pcrinfo->pcr;
	
			tmpSTC = pPcrProcesser->nextSTC;
			pPcrProcesser->nextSTC = pcrinfo->stc;
		}
	}

	pcrinfo->pcr = tmpPCR;
	pcrinfo->stc = tmpSTC;
	return true;
}

void PCRSYNC_GetCloser(DEMUX_PCRSYNC_T *pPcrProcesser, NAVDTVPCRINFO pcrinfo, NAVDTVSWDEMUXPCRINFO *closerInfo)
{
	enum {
		PICK_BY_PREFERENCE = 0,
		PICK_AUDIO_ONLY = 1,
		PICK_VIDEO_ONLY = 2,
	} pick = PICK_BY_PREFERENCE;
	int64_t pcr = -1, aPTS = -1, vPTS = -1;
	SWDEMUXPCR* pSwPCRInfo;

	if ((pPcrProcesser == NULL) || (closerInfo == NULL))
		return;

	pSwPCRInfo = &pPcrProcesser->swPCRInfo;

	closerInfo->demuxPCR = -1;
	closerInfo->demuxAPTS = -1;
	closerInfo->demuxVPTS = -1;

	if (pPcrProcesser->bNoPCR == false) {
		pcr = pSwPCRInfo->avPCR;
		aPTS = pSwPCRInfo->aPTS;
		vPTS = pSwPCRInfo->vPTS;

		if (pcr == -1) {
			if (pcrinfo.pcr == -1)
				return;
			
			pcr = pcrinfo.pcr;
			if (pPcrProcesser->bNoAudioPts == false)
				aPTS = pPcrProcesser->lastDemuxAudioPTS;
			else
				aPTS = -1;

			if (pPcrProcesser->bNoVideoPts == false)
				vPTS = pPcrProcesser->lastDemuxVideoPTS;
			else
				vPTS = -1;
		} else {
			if (pPcrProcesser->bNoAudioPts == true)
				aPTS = -1;

			if (pPcrProcesser->bNoVideoPts == true)
				vPTS = -1;
		}
	} else {
		pcr = pSwPCRInfo->avPCR;
		if (pcr != -1) {
			aPTS = pSwPCRInfo->aPTS;
			vPTS = pSwPCRInfo->vPTS;
		} else {
			aPTS = pPcrProcesser->lastDemuxAudioPTS;
			vPTS = pPcrProcesser->lastDemuxVideoPTS;
		}
	}

	if ((aPTS == -1) && (vPTS == -1))
		return;

	if (pcr == -1)
		pick = PICK_BY_PREFERENCE;
	else if(aPTS == -1)
		pick = PICK_VIDEO_ONLY;
	else if(vPTS == -1)
		pick = PICK_AUDIO_ONLY;
	else {
		int64_t avdiff = abs(aPTS - vPTS);
		if (pPcrProcesser->preferAVPTS == AUDIO_TYPE)
			pick = PICK_AUDIO_ONLY;
		else if (pPcrProcesser->preferAVPTS == VIDEO_TYPE)
			pick = PICK_VIDEO_ONLY;
		else if (avdiff > 720000) {
			if (aPTS < vPTS)
				pick = PICK_VIDEO_ONLY;
			else
				pick = PICK_AUDIO_ONLY;
		} else {
			if (aPTS < vPTS)
				pick = PICK_AUDIO_ONLY;
			else
				pick = PICK_VIDEO_ONLY;
		}
	}

	if (pick == PICK_AUDIO_ONLY) {
		closerInfo->demuxPCR = pcr;
		closerInfo->demuxAPTS = aPTS;
		closerInfo->demuxVPTS = -1;
	} else if(pick == PICK_VIDEO_ONLY) {
		closerInfo->demuxPCR = pcr;
		closerInfo->demuxAPTS = -1;
		closerInfo->demuxVPTS = vPTS - (DTV_DELAY_TIME*2);
	} else {
		if (aPTS == -1) {
			closerInfo->demuxPCR = pcr;
			closerInfo->demuxAPTS = -1;
			closerInfo->demuxVPTS = vPTS - (DTV_DELAY_TIME*2);
		} else if (vPTS == -1) {
			closerInfo->demuxPCR = pcr;
			closerInfo->demuxAPTS = aPTS;
			closerInfo->demuxVPTS = -1;
		} else {
			if (pPcrProcesser->preferAVPTS == AUDIO_TYPE) {
				closerInfo->demuxPCR = pcr;
				closerInfo->demuxAPTS = aPTS;
				closerInfo->demuxVPTS = -1;
			} else if(pPcrProcesser->preferAVPTS == VIDEO_TYPE) {
				closerInfo->demuxPCR = pcr;
				closerInfo->demuxAPTS = -1;
				closerInfo->demuxVPTS = vPTS - (DTV_DELAY_TIME*2);
			} else {
				if (aPTS < vPTS) {
					closerInfo->demuxPCR = pcr;
					closerInfo->demuxAPTS = aPTS;
					closerInfo->demuxVPTS = -1;
				} else {
					closerInfo->demuxPCR = pcr;
					closerInfo->demuxAPTS = -1;
					closerInfo->demuxVPTS = vPTS - (DTV_DELAY_TIME*2);
				}
			}
		}
	}
}

void PCRSYNC_UpdateRCD(DEMUX_PCRSYNC_T *pPcrProcesser, int pcrpid)
{
	NAVDTVPCRINFO pcrinfo;
	PRESENTATION_POSITIONS position;
	int beforeCheckPcrOffset = pPcrProcesser->checkPcrOffset;
	int64_t currPTS = CLOCK_GetPTS();

	if (currPTS < pPcrProcesser->resetPTS)
		pPcrProcesser->resetPTS = currPTS;

	memset(&pcrinfo, 0, sizeof(pcrinfo));
	if (PCRSYNC_GetPCR(pPcrProcesser, pcrpid, &pcrinfo, currPTS) == false)
		return;
	
	if (pPcrProcesser->firstPCR > 0 || pPcrProcesser->startAudioPts > 0 || pPcrProcesser->startVideoPts > 0 || (currPTS - pPcrProcesser->resetPTS) > DEMUX_CLOCKS_PER_SEC) {
		PCRSYNC_UpdatePCRStableStatus(pPcrProcesser, pcrpid, pcrinfo);
		PCRSYNC_CheckPCRStable(pPcrProcesser);
		PCRSYNC_UpdateAVPTSStableStatus(pPcrProcesser);
		PCRSYNC_CheckAVPTSStable(pPcrProcesser);
	}

	if ((pPcrProcesser->lastDemuxAudioPTS == pPcrProcesser->prevAudioDemuxPTS) && (pPcrProcesser->lastDemuxVideoPTS == pPcrProcesser->prevVideoDemuxPTS)) {
		PCRSYNC_UpdatePTSStableStatus(pPcrProcesser, -1, -1);
		PCRSYNC_CheckPTSStable(pPcrProcesser);
	}

	PCRSYNC_UpdateSignalStableStatus(pPcrProcesser);
	PCRSYNC_CheckSignalStable(pPcrProcesser);

	PCRDEBUG_Insert(&pPcrProcesser->pcrDebugger, pcrinfo.pcr, pcrinfo.stc, pPcrProcesser->lastDemuxAudioPTS, pPcrProcesser->lastDemuxVideoPTS);

	if (pPcrProcesser->bVirtualPcrMode == false) {
		/* Might be predict next pcr.  */
		PCRSYNC_SmoothPCR(pPcrProcesser, &pcrinfo);
	}
	
	REFCLK_GetPresentationPositions(pPcrProcesser->pRefClock, &position);
	pPcrProcesser->lastAudioSystemPTS = position.audioSystemPTS;
	pPcrProcesser->lastVideoSystemPTS = position.videoSystemPTS;
	PCRSYNC_UpdateOutputStatus(pPcrProcesser);
	PCRSYNC_CheckOutputStable(pPcrProcesser);

	if (pPcrProcesser->checkPcrOffset == HAVE_STEADY_OFFSET) {
		PCRTRACK_CheckTrackingSteady(pPcrProcesser->pPcrRecoveryManager, pPcrProcesser);
		PCRSYNC_UpdateFullnessStatus(pPcrProcesser);
		PCRSYNC_UpdateRCDStableStatus(pPcrProcesser, pcrinfo);
	}
	PCRSYNC_CheckFullness(pPcrProcesser);
	PCRSYNC_CheckRCDStable(pPcrProcesser);

	PCRSYNC_AdjustRCD(pPcrProcesser, pcrinfo);

	if ((pPcrProcesser->checkPcrOffset == EVALUATE_STEADY) && (beforeCheckPcrOffset != EVALUATE_STEADY)) {
		pPcrProcesser->noAoutPtsCounter = 0;
		pPcrProcesser->aoutPtsCounter = 0;
		pPcrProcesser->noVoutPtsCounter = 0;
		pPcrProcesser->voutPtsCounter = 0;

		PCRSYNC_ResetAbnormalCounters(pPcrProcesser);

		if (pPcrProcesser->bVirtualPcrMode == true) {
			if (pPcrProcesser->bNoAudioPts == true || pPcrProcesser->referenceAVPTS == VIDEO_TYPE)
				pPcrProcesser->trackingMode = VBUFFER_TRACKING;
			else
				pPcrProcesser->trackingMode = ABUFFER_TRACKING;
		} else
			pPcrProcesser->trackingMode = PCR_TRACKING;

		pPcrProcesser->bAdjusted = true;
		pPcrProcesser->resetPTS = CLOCK_GetPTS();
	} else {
		PCRSYNC_HandleRCD(pPcrProcesser, pcrinfo);
	}

	pPcrProcesser->stc = pcrinfo.stc;
	pPcrProcesser->pcr = pcrinfo.pcr;
	pPcrProcesser->prevVideoDemuxPTS = pPcrProcesser->lastDemuxVideoPTS;
	pPcrProcesser->prevAudioDemuxPTS = pPcrProcesser->lastDemuxAudioPTS;
	pPcrProcesser->prevVideoSystemPTS = pPcrProcesser->lastVideoSystemPTS;
	pPcrProcesser->prevAudioSystemPTS = pPcrProcesser->lastAudioSystemPTS;

	PCRTRACK_UpdatePosition(pPcrProcesser->pPcrRecoveryManager, pPcrProcesser);

	PCRSYNC_DEBUG_SaveAvSyncInfo(pPcrProcesser, &pcrinfo);
}

void PCRSYNC_HandleRCD(DEMUX_PCRSYNC_T *pPcrProcesser, NAVDTVPCRINFO pcrinfo)
{
	int64_t currPTS = CLOCK_GetPTS();
	int64_t pll  = CLOCK_GetAVSyncPTS(pPcrProcesser->pRefClock);
	int64_t RCD = REFCLK_GetRCD(pPcrProcesser->pRefClock);
	int64_t mpts = 0;

	if (pPcrProcesser->bVirtualPcrMode == true) {
		if ((pPcrProcesser->rcd != -1) && (pPcrProcesser->rcd != RCD)) {
			RCD = pPcrProcesser->rcd;
			REFCLK_SetRCD(pPcrProcesser->pRefClock, RCD);
		}
	} else {
		if ((pPcrProcesser->rcd != -1) && ((pcrinfo.stc > 0 && pPcrProcesser->stc != pcrinfo.stc)
			|| ((pPcrProcesser->bBadSignal == false) && (RCD == -1)))) {
			if ((pPcrProcesser->bBadSignal == false) && (RCD == -1) && !(pcrinfo.stc > 0 && pcrinfo.pcr > 0)) {
				RCD = pPcrProcesser->rcd;
				REFCLK_SetRCD(pPcrProcesser->pRefClock, RCD);
			} else {
				RCD = pcrinfo.pcr - pcrinfo.stc - pPcrProcesser->pcrOffset;
				if(RCD == -1)
					RCD = -2;
				REFCLK_SetRCD(pPcrProcesser->pRefClock, RCD);
			}
			pPcrProcesser->rcd = RCD;
		}
	}
	
	if ((currPTS - pPcrProcesser->pcrPrintPTS) >= DEMUX_CLOCKS_PER_SEC) {
		long clk_src = REFCLK_GetClockMode(pPcrProcesser->pRefClock);
	
		mpts = RCD + pll;
		dmx_mask_print(DEMUX_PCRSYC_DEBUG,"[dtv(%d)]:PCR=%lld, RCD=%lld, MPTS=%lld, APTS=%lld, SubAPTS=%lld, VPTS=%lld, stc=%lld, offset=%lld(%lld), pll=%lld, sysPTS=%lld, chk_mod=%d, clk_src=%d\n", (int)pPcrProcesser->tunerHandle, pcrinfo.pcr, RCD, mpts, pPcrProcesser->lastDemuxAudioPTS, pPcrProcesser->lastDemuxSubAudioPTS, pPcrProcesser->lastDemuxVideoPTS, pcrinfo.stc, pPcrProcesser->pcrOffset, pPcrProcesser->pcrDefaultOffset, pll, currPTS, pPcrProcesser->checkPcrOffset, (int)clk_src);
		pPcrProcesser->pcrPrintPTS = currPTS;
	} else if(currPTS < pPcrProcesser->pcrPrintPTS) {
		pPcrProcesser->pcrPrintPTS = currPTS;
	}
}

void PCRSYNC_SmoothPCR(DEMUX_PCRSYNC_T *pPcrProcesser , NAVDTVPCRINFO *pPcrinfo)
{
	if (pPcrinfo->stc <= 0 || pPcrinfo->pcr <= 0)
		return;
	
	if (pPcrinfo->stc != pPcrProcesser->realSTC) {
		bool bAvailable = true;
		int64_t tmp_pcr = 0;
		/* Reset when got abnormal Pcr.  */
		if (pPcrinfo->pcr != pPcrProcesser->realPCR) {
			if ((pPcrProcesser->stc > 0 && pPcrinfo->stc < pPcrProcesser->stc)) {
				dmx_mask_print(DEMUX_PCRSYC_DEBUG|DEMUX_NOTICE_PRINT,"\033[1;36m [%s %d]LRegress_Reset() pcr:%lld, pre_pcr:%lld\033[m\n",__func__ , __LINE__ ,pPcrinfo->pcr, pPcrProcesser->pcr);
				LRegress_Reset(&pPcrProcesser->LRegress);
				bAvailable = true;
			} else {
				if ((pPcrProcesser->pcr > 0 && abs((pPcrinfo->pcr - pPcrinfo->stc) - (pPcrProcesser->pcr - pPcrProcesser->stc)) > DEMUX_CLOCKS_PER_SEC)) {
					bAvailable = false;
					if (pPcrProcesser->nextPCR > 0 && pPcrProcesser->nextPCR > pPcrinfo->pcr && pPcrProcesser->nextSTC > pPcrinfo->stc && abs((pPcrinfo->pcr - pPcrinfo->stc) - (pPcrProcesser->nextPCR - pPcrProcesser->nextSTC)) < 9000) {
						LRegress_Reset(&pPcrProcesser->LRegress);
						bAvailable = true;
					}
				}
			}

			tmp_pcr = LRegress_GetPredictY(&pPcrProcesser->LRegress, pPcrinfo->stc);

			/*dmx_dbg("\033[1;36m [%s %d]URCD[%lld, %lld, %lld](%lld) \033[m\n",__func__ , __LINE__ , pPcrinfo->pcr , pPcrinfo->stc, tmp_pcr , pPcrinfo->pcr-tmp_pcr); */

			if (bAvailable == true) {
				LINEARPAIR pair;
				pair.x = pPcrinfo->stc;
				pair.y = pPcrinfo->pcr;
				LRegress_InsertDataPair(&pPcrProcesser->LRegress,pair);
				pPcrProcesser->realSTC = pPcrinfo->stc;
				pPcrProcesser->realPCR = pPcrinfo->pcr;
			}

			if (pPcrinfo->pcr > 0 && tmp_pcr > 0 && abs(pPcrinfo->pcr - tmp_pcr) > 100)
				pPcrinfo->pcr = tmp_pcr;

		} else {
			tmp_pcr = LRegress_GetPredictY(&pPcrProcesser->LRegress, pPcrinfo->stc);

			if (tmp_pcr > 0 && abs(pPcrinfo->pcr - tmp_pcr) > 100)
				pPcrinfo->pcr = tmp_pcr;
		}
	} else {
		pPcrinfo->stc = pPcrProcesser->stc;
		pPcrinfo->pcr = pPcrProcesser->pcr;
	}
}

void PCRSYNC_AdjustPcrOffset(DEMUX_PCRSYNC_T *pPcrProcesser, NAVDTVPCRINFO pcrinfo, int64_t pll)
{
	NAVDTVSWDEMUXPCRINFO closerInfo;
	if (pPcrProcesser->bPassGap != true)
		return;

	PCRSYNC_GetCloser(pPcrProcesser, pcrinfo, &closerInfo);
	if (closerInfo.demuxAPTS != -1 || closerInfo.demuxVPTS != -1) {
		int64_t mpts = 0, pcr = 0, pts = 0, pcrDiff = 0, audioDiff = 0;
		int beforeReferenceAVPTS = pPcrProcesser->referenceAVPTS;
		pPcrProcesser->referenceAVPTS = (closerInfo.demuxAPTS != -1) ? AUDIO_TYPE : VIDEO_TYPE;
		if(pPcrProcesser->referenceAVPTS == AUDIO_TYPE) {
			pcrDiff = closerInfo.demuxPCR - closerInfo.demuxAPTS;
			pcr = pcrinfo.pcr;
			pts = pPcrProcesser->lastDemuxAudioPTS;
		} else {
			pcrDiff = closerInfo.demuxPCR - closerInfo.demuxVPTS;
			pcr = pcrinfo.pcr;
			pts = pPcrProcesser->lastDemuxVideoPTS;
		}

		/*
			Consider the difference of main and sub is large,
			we use sub apts as reference and enlarge our offset
		*/
		if (pPcrProcesser->referenceAVPTS == AUDIO_TYPE &&
		   pPcrProcesser->lastDemuxSubAudioPTS > 0 && pPcrProcesser->lastDemuxAudioPTS > 0) {
			audioDiff = pPcrProcesser->lastDemuxAudioPTS - pPcrProcesser->lastDemuxSubAudioPTS;
			if (audioDiff >= 2*DTV_DELAY_TIME && audioDiff <= 4*DTV_DELAY_TIME) {
				pts = pPcrProcesser->lastDemuxSubAudioPTS;
				pcrDiff = pcr - pts;
				dmx_mask_print(DEMUX_PCRSYC_DEBUG,"AD case: Change reference PTS, audioDiff = %lld pcr - pts = %lld\n", audioDiff, pcr - pts);
			}
			else
				audioDiff = 0;
		}

		if ((pPcrProcesser->bAdjusted == false) && (pPcrProcesser->rcd != -1) && (pPcrProcesser->referenceAVPTS == beforeReferenceAVPTS)) {
			/*
				We have got RCD already even if the flag of bAdjusted is false
				which means that we may not adjust pcrOffset yet.
				When reference PTS is the same as before, we only calculate mpts to handle RCD to
				prevent re-calculate pcrOffset again.
			*/
			mpts = pPcrProcesser->rcd + pll;
		} else if (pPcrProcesser->bVirtualPcrMode == true) {
			/*
				No PCR
			*/
			if(pPcrProcesser->bNoVideoPts == false)
				pPcrProcesser->pcrDefaultOffset = 5*DTV_DELAY_TIME;
			else
				pPcrProcesser->pcrDefaultOffset = DTV_DELAY_TIME;
			pPcrProcesser->pcrOffset = pPcrProcesser->pcrDefaultOffset;
			pPcrProcesser->rcd = pts - pPcrProcesser->pcrOffset - pll;
			if(pPcrProcesser->rcd == -1)
				pPcrProcesser->rcd = -2;
			mpts = pPcrProcesser->rcd + pll;
		} else if (pPcrProcesser->bHighWaterLevelMode == false && pcrDiff <= DTV_DELAY_TIME && pcrDiff >= -(2*DTV_DELAY_TIME)) {
			/*
				Normal water level
				Compensate offset in the audio mix case
			*/
			pPcrProcesser->pcrDefaultOffset = (pcrDiff > 0) ? (DTV_DELAY_TIME + div_s64(pcrDiff, 1000)*1000) : DTV_DELAY_TIME;
			pPcrProcesser->pcrDefaultOffset = (pPcrProcesser->pcrDefaultOffset > audioDiff) ? pPcrProcesser->pcrDefaultOffset : div_s64(audioDiff, 1000)*1000;
			pPcrProcesser->pcrOffset = pPcrProcesser->pcrDefaultOffset;
			pPcrProcesser->rcd = pts - pPcrProcesser->pcrOffset - pll;
			if(pPcrProcesser->rcd == -1)
				pPcrProcesser->rcd = -2;
			mpts = pcrinfo.pcr - pcrinfo.stc - pPcrProcesser->pcrOffset + pll;
		} else {
			/*
				High water level
				Compensate offset in the audio mix case
			*/
			pPcrProcesser->bHighWaterLevelMode = true;
			pPcrProcesser->pcrDefaultOffset = 3*DTV_DELAY_TIME;
			pPcrProcesser->pcrDefaultOffset = (pPcrProcesser->pcrDefaultOffset > audioDiff) ? pPcrProcesser->pcrDefaultOffset : div_s64(audioDiff, 1000)*1000;

			/*
				Consider pcr wrap-around case
			*/
			if((((pPcrProcesser->pcr - pPcrProcesser->stc) - (pcrinfo.pcr - pcrinfo.stc)) > DEMUX_CLOCKS_PER_SEC) || ( (pcr - pts) > 5*DEMUX_CLOCKS_PER_SEC) || ((pts-pcr) > 10*DEMUX_CLOCKS_PER_SEC)) {
				pPcrProcesser->pcrOffset = pcr - pts + pPcrProcesser->pcrDefaultOffset;
			}
			/* at first use DTV_DELAY_TIME to calc mpts, if apts less than mpts, should enlarge pcr offset */
			else if(closerInfo.demuxAPTS < (pcrinfo.pcr - pcrinfo.stc - DTV_DELAY_TIME + pll)){
				pPcrProcesser->pcrOffset = pcr - pts + pPcrProcesser->pcrDefaultOffset;
			}
			else {
				/*
				This hack is for audio track change
				which the diff of PCR and PTS is not consistent in all track.
				The offset of track 1 might be underestimated for track 2.
				We enlarge pcrOffset to prevent audio underflow.
				*/
				pPcrProcesser->pcrOffset = DTV_DELAY_TIME;
			}

			pPcrProcesser->rcd = pts - pPcrProcesser->pcrOffset - pll;
			if (pPcrProcesser->rcd == -1)
				pPcrProcesser->rcd = -2;
			mpts = pcrinfo.pcr - pcrinfo.stc - pPcrProcesser->pcrOffset + pll;
		}

		dmx_mask_print(DEMUX_PCRSYC_DEBUG,"[dtv(%d)] reset: rcd = %lld, pts = %lld, pcr = %lld, apts = %lld, vpts = %lld, pll = %lld.\n", (int)pPcrProcesser->tunerHandle, pPcrProcesser->rcd, pts, pcr, closerInfo.demuxAPTS, closerInfo.demuxVPTS, pll);
		if ((pPcrProcesser->bAdjusted == false)
		  || ((pPcrProcesser->referenceAVPTS == AUDIO_TYPE) && (mpts < pPcrProcesser->lastDemuxAudioPTS))
		  || ((pPcrProcesser->referenceAVPTS == VIDEO_TYPE) && (mpts < pPcrProcesser->lastDemuxVideoPTS))) {
			PCRSYNC_HandleRCD(pPcrProcesser, pcrinfo);
			pPcrProcesser->checkPcrOffset = EVALUATE_STEADY;
			pPcrProcesser->bPassGap = false;
			if (pPcrProcesser->bNoPCR == true &&
			    pPcrProcesser->lastDemuxVideoPTS != -1 && pPcrProcesser->lastDemuxAudioPTS != -1 &&
			   (pPcrProcesser->lastDemuxVideoPTS - pPcrProcesser->lastDemuxAudioPTS) > 6*200*DEMUX_CLOCKS_PER_MS &&
			   (pPcrProcesser->lastDemuxVideoPTS - pPcrProcesser->lastDemuxAudioPTS) < 9*200*DEMUX_CLOCKS_PER_MS) {
				dmx_mask_print(DEMUX_PCRSYC_DEBUG, "Special case: No PCR and V(%lld) - A(%lld) > 1.2s, Set Video freerun th = 1.2s\n", pPcrProcesser->lastDemuxVideoPTS, pPcrProcesser->lastDemuxAudioPTS);
				REFCLK_SetVideoFreeRunThreshold(pPcrProcesser->pRefClock, 6*200*DEMUX_CLOCKS_PER_MS);
			}
			else if (pPcrProcesser->bNoVideoPts == false)
				REFCLK_SetVideoFreeRunThreshold(pPcrProcesser->pRefClock, MAX_FREE_RUN_THRESHOLD);
			if (pPcrProcesser->bNoAudioPts == false)
				REFCLK_SetAudioFreeRunThreshold(pPcrProcesser->pRefClock, MAX_FREE_RUN_THRESHOLD, MAX_FREE_RUN_THRESHOLD);
		}
	}

}

void PCRSYNC_AdjustRCD(DEMUX_PCRSYNC_T *pPcrProcesser, NAVDTVPCRINFO pcrinfo)
{
	int64_t currPTS = 0;
	int64_t pll = 0;
	int64_t RCD = 0;

	SWDEMUXPCR* pSwPCRInfo = &pPcrProcesser->swPCRInfo;

	if(pPcrProcesser->lastDemuxAudioPTS == -1 && pPcrProcesser->lastDemuxVideoPTS == -1)
		return;

	RCD = REFCLK_GetRCD(pPcrProcesser->pRefClock);
	currPTS = CLOCK_GetPTS();
	pll = CLOCK_GetAVSyncPTS(pPcrProcesser->pRefClock);

	if (pPcrProcesser->bAdjusted == false) {
		if (((pPcrProcesser->bNoPCR == true) || (pcrinfo.pcr > pPcrProcesser->pcr && pPcrProcesser->pcr > 0))
		  && ((pPcrProcesser->lastDemuxAudioPTS > 0 && pPcrProcesser->lastDemuxVideoPTS > 0)
			|| (pPcrProcesser->lastDemuxAudioPTS > pPcrProcesser->prevAudioDemuxPTS && pPcrProcesser->prevAudioDemuxPTS > 0) || (pPcrProcesser->lastDemuxVideoPTS > pPcrProcesser->prevVideoDemuxPTS && pPcrProcesser->prevVideoDemuxPTS > 0))) {
			pPcrProcesser->bPassGap = true;
			pPcrProcesser->bCheckPcrOffsetAgain = false;
			PCRSYNC_AdjustPcrOffset(pPcrProcesser, pcrinfo, pll);
		} else if (((pPcrProcesser->lastDemuxAudioPTS > 0 && pPcrProcesser->bNoAudioPts == true) || (pPcrProcesser->lastDemuxVideoPTS > 0 && pPcrProcesser->bNoVideoPts == true))
				  && (currPTS - pPcrProcesser->resetPTS) > 2*DEMUX_CLOCKS_PER_SEC) {
			pPcrProcesser->bPassGap = true;
			pPcrProcesser->bCheckPcrOffsetAgain = false;
			PCRSYNC_AdjustPcrOffset(pPcrProcesser, pcrinfo, pll);
		}
	} else if (pPcrProcesser->checkPcrOffset == PREPARE_TO_GET_OFFSET) {
		pPcrProcesser->checkPcrOffset = GOTO_GET_OFFSET;
		if (pPcrProcesser->pcrGapType == NO_GAP)
			pPcrProcesser->bPassGap = true;
		pPcrProcesser->bCheckPcrOffsetAgain = false;
		SWDEMUXPCR_Reset(&pPcrProcesser->swPCRInfo);
	} else {
		if ((pPcrProcesser->bVirtualPcrMode == false && ((pPcrProcesser->pcr - pPcrProcesser->stc) - (pcrinfo.pcr - pcrinfo.stc)) > DEMUX_CLOCKS_PER_SEC)
		  || ((pPcrProcesser->bNoAudioPts == false) && pPcrProcesser->lastDemuxAudioPTS != -1 && pPcrProcesser->prevAudioDemuxPTS != -1 && (pPcrProcesser->prevAudioDemuxPTS - pPcrProcesser->lastDemuxAudioPTS) > 2*DEMUX_CLOCKS_PER_SEC)
		  || ((pPcrProcesser->bNoVideoPts == false) && pPcrProcesser->lastDemuxVideoPTS != -1 && pPcrProcesser->prevVideoDemuxPTS != -1 && (pPcrProcesser->prevVideoDemuxPTS - pPcrProcesser->lastDemuxVideoPTS) > 2*DEMUX_CLOCKS_PER_SEC) ) {
			if (RCD != -1) {
				if ((pPcrProcesser->bNoVideoPts == false) && (pPcrProcesser->bNoVideoOutputPts == false) && (pPcrProcesser->lastVideoSystemPTS > pPcrProcesser->lastDemuxVideoPTS)) {
					REFCLK_SetVideoFreeRunThreshold(pPcrProcesser->pRefClock, MIN_FREE_RUN_THRESHOLD);
					pPcrProcesser->afterGapVideoPTS = pPcrProcesser->lastDemuxVideoPTS;
				}
				if ((pPcrProcesser->bNoAudioPts == false) && (pPcrProcesser->bNoAudioOutputPts == false) && (pPcrProcesser->lastAudioSystemPTS > pPcrProcesser->lastDemuxAudioPTS)) {
					REFCLK_SetAudioFreeRunThreshold(pPcrProcesser->pRefClock, MIN_FREE_RUN_THRESHOLD, MIN_FREE_RUN_THRESHOLD);
					pPcrProcesser->afterGapAudioPTS = pPcrProcesser->lastDemuxAudioPTS;
				}
			}

			pPcrProcesser->pcrGapType = WRAP_AROUND_GAP;
			pPcrProcesser->checkPcrOffset = GOTO_GET_OFFSET;
			pPcrProcesser->bPassGap = false;
			pPcrProcesser->bCheckPcrOffsetAgain = false;
			pPcrProcesser->trackingMode = NO_TRACKING;
			SWDEMUXPCR_Reset(&pPcrProcesser->swPCRInfo);
			//printf("%s,%s,%d, after gap = [%lld, %lld], avout = [%lld, %lld].\n", __FILE__, __func__, __LINE__, pPcrProcesser->afterGapAudioPTS, pPcrProcesser->afterGapVideoPTS, pPcrProcesser->lastAudioSystemPTS, pPcrProcesser->lastVideoSystemPTS);
		} else if ((pPcrProcesser->bVirtualPcrMode == false && ((pcrinfo.pcr - pcrinfo.stc) - (pPcrProcesser->pcr - pPcrProcesser->stc)) > DEMUX_CLOCKS_PER_SEC)
			|| ((pPcrProcesser->bNoAudioPts == false) && pPcrProcesser->lastDemuxAudioPTS != -1 && pPcrProcesser->prevAudioDemuxPTS != -1 && (pPcrProcesser->lastDemuxAudioPTS - pPcrProcesser->prevAudioDemuxPTS) > 2*DEMUX_CLOCKS_PER_SEC)
			|| ((pPcrProcesser->bNoVideoPts == false) && pPcrProcesser->lastDemuxVideoPTS != -1 && pPcrProcesser->prevVideoDemuxPTS != -1 && (pPcrProcesser->lastDemuxVideoPTS - pPcrProcesser->prevVideoDemuxPTS) > 2*DEMUX_CLOCKS_PER_SEC) ) {
			if (RCD != -1) {
				if ((pPcrProcesser->bNoVideoPts == false) && (pPcrProcesser->bNoVideoOutputPts == false) && ((pPcrProcesser->lastDemuxVideoPTS - pPcrProcesser->prevVideoDemuxPTS) > 2*DEMUX_CLOCKS_PER_SEC)) {
					REFCLK_SetVideoFreeRunThreshold(pPcrProcesser->pRefClock, MIN_FREE_RUN_THRESHOLD);
					pPcrProcesser->afterGapVideoPTS = pPcrProcesser->lastDemuxVideoPTS;
				}
				if ((pPcrProcesser->bNoAudioPts == false) && (pPcrProcesser->bNoAudioOutputPts == false) && ((pPcrProcesser->lastDemuxAudioPTS - pPcrProcesser->prevAudioDemuxPTS) > 2*DEMUX_CLOCKS_PER_SEC)) {
					REFCLK_SetAudioFreeRunThreshold(pPcrProcesser->pRefClock, MIN_FREE_RUN_THRESHOLD, MIN_FREE_RUN_THRESHOLD);
					pPcrProcesser->afterGapAudioPTS = pPcrProcesser->lastDemuxAudioPTS;
				}
			}

			pPcrProcesser->pcrGapType = JUMP_GAP;
			pPcrProcesser->checkPcrOffset = GOTO_GET_OFFSET;
			pPcrProcesser->bPassGap = false;
			pPcrProcesser->bCheckPcrOffsetAgain = false;
			pPcrProcesser->trackingMode = NO_TRACKING;
			SWDEMUXPCR_Reset(&pPcrProcesser->swPCRInfo);
			//printf("%s,%s,%d, after gap = [%lld, %lld], avout = [%lld, %lld].\n", __FILE__, __func__, __LINE__, pPcrProcesser->afterGapAudioPTS, pPcrProcesser->afterGapVideoPTS, pPcrProcesser->lastAudioSystemPTS, pPcrProcesser->lastVideoSystemPTS);
		} else if (pPcrProcesser->bCheckPcrOffsetAgain == true
		  && ((pPcrProcesser->bNoAudioPts == false) && (pPcrProcesser->prevAudioDemuxPTS != -1) && (pPcrProcesser->lastDemuxAudioPTS >= pPcrProcesser->prevAudioDemuxPTS)
			&& (pPcrProcesser->bNoVideoPts == false) && (pPcrProcesser->prevVideoDemuxPTS != -1) && (pPcrProcesser->lastDemuxVideoPTS >= pPcrProcesser->prevVideoDemuxPTS))
		  && (((pPcrProcesser->prevVideoDemuxPTS > pPcrProcesser->prevAudioDemuxPTS) && (pPcrProcesser->lastDemuxAudioPTS > pPcrProcesser->lastDemuxVideoPTS))
			|| ((pPcrProcesser->prevAudioDemuxPTS > pPcrProcesser->prevVideoDemuxPTS) && (pPcrProcesser->lastDemuxVideoPTS > pPcrProcesser->lastDemuxAudioPTS)))) {

			pPcrProcesser->bCheckPcrOffsetAgain = false;

		} else if (pPcrProcesser->checkPcrOffset == GOTO_GET_OFFSET) {

			if ((pPcrProcesser->bVirtualPcrMode == true || (pPcrProcesser->pcr != -1 && (pcrinfo.pcr > pPcrProcesser->pcr)))
			  && ((pPcrProcesser->bNoAudioPts == true) || (pPcrProcesser->prevAudioDemuxPTS != -1 && (pPcrProcesser->lastDemuxAudioPTS > pPcrProcesser->prevAudioDemuxPTS)))
			  && ((pPcrProcesser->bNoVideoPts == true) || (pPcrProcesser->prevVideoDemuxPTS != -1 && (pPcrProcesser->lastDemuxVideoPTS > pPcrProcesser->prevVideoDemuxPTS)))) {

				if (((pPcrProcesser->pcrGapType == WRAP_AROUND_GAP) || (pPcrProcesser->pcrGapType == JUMP_GAP))
				  && ((pPcrProcesser->bNoAudioPts == true) 	|| (pPcrProcesser->bNoAudioOutputPts == true) || ((pPcrProcesser->lastDemuxAudioPTS > pPcrProcesser->lastAudioSystemPTS)
					&& (pPcrProcesser->afterGapAudioPTS == -1 || (((pPcrProcesser->lastAudioSystemPTS >= pPcrProcesser->afterGapAudioPTS) && (pSwPCRInfo->aPTS == -1 || (pSwPCRInfo->aPTS >= pPcrProcesser->afterGapAudioPTS))) || pPcrProcesser->lastDemuxAudioPTS < pPcrProcesser->afterGapAudioPTS))))
				  && ((pPcrProcesser->bNoVideoPts == true) || (pPcrProcesser->bNoVideoOutputPts == true) || ((pPcrProcesser->lastDemuxVideoPTS > pPcrProcesser->lastVideoSystemPTS)
					&& (pPcrProcesser->afterGapVideoPTS == -1 || (((pPcrProcesser->lastVideoSystemPTS >= pPcrProcesser->afterGapVideoPTS) && (pSwPCRInfo->vPTS == -1 || (pSwPCRInfo->vPTS >= pPcrProcesser->afterGapVideoPTS))) || pPcrProcesser->lastDemuxVideoPTS < pPcrProcesser->afterGapVideoPTS))))) {
					//printf("%s,%s,%d, after gap = [%lld, %lld], avout = [%lld, %lld].\n", __FILE__, __func__, __LINE__, pPcrProcesser->afterGapAudioPTS, pPcrProcesser->afterGapVideoPTS, pPcrProcesser->lastAudioSystemPTS, pPcrProcesser->lastVideoSystemPTS);
					pPcrProcesser->pcrGapType = NO_GAP;
					pPcrProcesser->afterGapAudioPTS = -1;
					pPcrProcesser->afterGapVideoPTS = -1;
					pPcrProcesser->bPassGap = true;
				} else if ((pPcrProcesser->bNoAudioPts == true) && (pPcrProcesser->bNoVideoPts == true)) {
					pPcrProcesser->checkPcrOffset = HAVE_STEADY_OFFSET;
					pPcrProcesser->bPassGap = false;
					pPcrProcesser->bCheckPcrOffsetAgain = false;
					REFCLK_SetAudioFreeRunThreshold(pPcrProcesser->pRefClock, DEFAULT_FREE_RUN_THRESHOLD, DEFAULT_FREE_RUN_THRESHOLD);
					REFCLK_SetVideoFreeRunThreshold(pPcrProcesser->pRefClock, DEFAULT_FREE_RUN_THRESHOLD);
					//printf("%s,%s,%d, set FreeRunThreshold %d.\n", __FILE__, __func__, __LINE__, DEFAULT_FREE_RUN_THRESHOLD);
				}
				PCRSYNC_AdjustPcrOffset(pPcrProcesser, pcrinfo, pll);
			}
			SWDEMUXPCR_Reset(&pPcrProcesser->swPCRInfo);
		} else if (pPcrProcesser->checkPcrOffset == EVALUATE_STEADY) {
			if ((currPTS - pPcrProcesser->resetPTS) > 2*DEMUX_CLOCKS_PER_SEC) {
				int64_t mpts = RCD + pll;
				if (((pPcrProcesser->referenceAVPTS == AUDIO_TYPE)
					&& ((pPcrProcesser->bNoAudioOutputPts == true) || abs(mpts - pPcrProcesser->lastAudioSystemPTS) < 2*DEMUX_CLOCKS_PER_SEC)
					&& ((pPcrProcesser->bNoVideoOutputPts == true) || abs(mpts - pPcrProcesser->lastVideoSystemPTS) < 2*DEMUX_CLOCKS_PER_SEC || (pPcrProcesser->lastDemuxVideoPTS - pPcrProcesser->lastVideoSystemPTS) < 2*DEMUX_CLOCKS_PER_SEC))
				  || ((pPcrProcesser->referenceAVPTS == VIDEO_TYPE)
					&& ((pPcrProcesser->bNoVideoOutputPts == true) || abs(mpts - pPcrProcesser->lastVideoSystemPTS) < 2*DEMUX_CLOCKS_PER_SEC)
					&& ((pPcrProcesser->bNoAudioOutputPts == true) || abs(mpts - pPcrProcesser->lastAudioSystemPTS) < 2*DEMUX_CLOCKS_PER_SEC || (pPcrProcesser->lastDemuxAudioPTS - pPcrProcesser->lastAudioSystemPTS) < 2*DEMUX_CLOCKS_PER_SEC))) {

					pPcrProcesser->checkPcrOffset = HAVE_STEADY_OFFSET;
					REFCLK_SetAudioFreeRunThreshold(pPcrProcesser->pRefClock, DEFAULT_FREE_RUN_THRESHOLD, DEFAULT_FREE_RUN_THRESHOLD);
					if (pPcrProcesser->bNoPCR == true &&
					    pPcrProcesser->lastDemuxVideoPTS != -1 && pPcrProcesser->lastDemuxAudioPTS != -1 &&
					   (pPcrProcesser->lastDemuxVideoPTS - pPcrProcesser->lastDemuxAudioPTS) > 6*200*DEMUX_CLOCKS_PER_MS &&
					   (pPcrProcesser->lastDemuxVideoPTS - pPcrProcesser->lastDemuxAudioPTS) < 9*200*DEMUX_CLOCKS_PER_MS) {
						dmx_mask_print(DEMUX_PCRSYC_DEBUG, "Special case: No PCR and V(%lld) - A(%lld) > 1.2s, Set Video freerun th = 1.2s\n", pPcrProcesser->lastDemuxVideoPTS, pPcrProcesser->lastDemuxAudioPTS);
		                                REFCLK_SetVideoFreeRunThreshold(pPcrProcesser->pRefClock, 6*200*DEMUX_CLOCKS_PER_MS);
					}
					else
						REFCLK_SetVideoFreeRunThreshold(pPcrProcesser->pRefClock, DEFAULT_FREE_RUN_THRESHOLD);
					//printf("%s,%s,%d, set FreeRunThreshold %d.\n", __FILE__, __func__, __LINE__, DEFAULT_FREE_RUN_THRESHOLD);
				}
			}
		} else {
			if((RCD != -1) && ((pPcrProcesser->bNoAudioPts == false) || (pPcrProcesser->bNoVideoPts == false)) && (currPTS - pPcrProcesser->resetPTS) > DEMUX_CLOCKS_PER_SEC) {
				bool isFreeRun = false;
				int64_t mpts = RCD + pll;
				if((pPcrProcesser->bNoAudioPts == false) && (pPcrProcesser->lastDemuxAudioPTS > 0)) {
					if(pPcrProcesser->referenceAVPTS == AUDIO_TYPE) {
						if((pPcrProcesser->bHighWaterLevelMode == true && pPcrProcesser->bCheckPcrOffsetAgain == false && ((mpts - pPcrProcesser->lastDemuxAudioPTS) > DEMUX_CLOCKS_PER_SEC))
						  || ((pPcrProcesser->bVirtualPcrMode == true) && (mpts > pPcrProcesser->lastDemuxAudioPTS))) {
							REFCLK_SetAudioFreeRunThreshold(pPcrProcesser->pRefClock, MIN_FREE_RUN_THRESHOLD, MIN_FREE_RUN_THRESHOLD);
							isFreeRun = true;
						}
					} else {
						if(mpts > pPcrProcesser->lastDemuxAudioPTS)
							REFCLK_SetAudioFreeRunThreshold(pPcrProcesser->pRefClock, MIN_FREE_RUN_THRESHOLD, MIN_FREE_RUN_THRESHOLD);
					}
				}
				if((pPcrProcesser->bNoVideoPts == false) && (pPcrProcesser->lastDemuxVideoPTS > 0) && (mpts > pPcrProcesser->lastDemuxVideoPTS)) {
					if(pPcrProcesser->referenceAVPTS == VIDEO_TYPE) {
						if((pPcrProcesser->bHighWaterLevelMode == true && pPcrProcesser->bCheckPcrOffsetAgain == false && ((mpts - pPcrProcesser->lastDemuxVideoPTS) > DEMUX_CLOCKS_PER_SEC))
						  || ((pPcrProcesser->bVirtualPcrMode == true) && (mpts > pPcrProcesser->lastDemuxVideoPTS))) {
							REFCLK_SetVideoFreeRunThreshold(pPcrProcesser->pRefClock, MIN_FREE_RUN_THRESHOLD);
							isFreeRun = true;
						}
					} else {
						if(mpts > pPcrProcesser->lastDemuxVideoPTS)
							REFCLK_SetVideoFreeRunThreshold(pPcrProcesser->pRefClock, MIN_FREE_RUN_THRESHOLD);
					}
				} else if(pPcrProcesser->bNoPCR == true &&
					  pPcrProcesser->lastDemuxVideoPTS != -1 && pPcrProcesser->lastDemuxAudioPTS != -1 &&
					 (pPcrProcesser->lastDemuxVideoPTS - pPcrProcesser->lastDemuxAudioPTS) > 6*200*DEMUX_CLOCKS_PER_MS &&
					 (pPcrProcesser->lastDemuxVideoPTS - pPcrProcesser->lastDemuxAudioPTS) < 9*200*DEMUX_CLOCKS_PER_MS) {
						REFCLK_SetVideoFreeRunThreshold(pPcrProcesser->pRefClock, 6*200*DEMUX_CLOCKS_PER_MS);
				} else if(mpts < pPcrProcesser->lastDemuxVideoPTS && mpts > pPcrProcesser->prevVideoDemuxPTS) { //add by xiangzhu for ML3RTANOM-433
					REFCLK_SetVideoFreeRunThreshold(pPcrProcesser->pRefClock, DEFAULT_FREE_RUN_THRESHOLD);
				}
				if(isFreeRun == true) {
					pPcrProcesser->checkPcrOffset = GOTO_GET_OFFSET;
					if(pPcrProcesser->pcrGapType == NO_GAP)
						pPcrProcesser->bPassGap = true;
					pPcrProcesser->bCheckPcrOffsetAgain = true;
					SWDEMUXPCR_Reset(&pPcrProcesser->swPCRInfo);
				}
			}
		}
	}
}

void PCRSYNC_UpdatePCRStableStatus(DEMUX_PCRSYNC_T *pPcrProcesser, int pcrpid, NAVDTVPCRINFO pcrinfo)
{
	if (pcrpid <= 0)
		pPcrProcesser->noPCRCounter += 10;
	else if(pPcrProcesser->bNoVideoPts && (pPcrProcesser->noPCRCounter > 10))
		pPcrProcesser->noPCRCounter += 50;
	else if(pPcrProcesser->noPCRCounter > 10 && pPcrProcesser->rcd == -1
	  && ((pPcrProcesser->startAudioPts > 0 && (pPcrProcesser->lastDemuxAudioPTS - pPcrProcesser->startAudioPts) > 2*DEMUX_CLOCKS_PER_SEC)
		|| (pPcrProcesser->startVideoPts > 0 && (pPcrProcesser->lastDemuxVideoPTS - pPcrProcesser->startVideoPts) > 2*DEMUX_CLOCKS_PER_SEC)
		|| (pPcrProcesser->startVideoPts > 0 && (abs64( CLOCK_GetPTS() - pPcrProcesser->checkVideoPidStart ) > 2*DEMUX_CLOCKS_PER_SEC)))) {
		pPcrProcesser->noPCRCounter += 100;
	} else if(pcrinfo.stc == pPcrProcesser->stc || pcrinfo.pcr == pPcrProcesser->pcr)
		pPcrProcesser->noPCRCounter++;
	else {
		pPcrProcesser->PCRCounter++;
		pPcrProcesser->noPCRCounter = 0;
	}
	//printf("No PCR (%d)(%d)\n", pPcrProcesser->noPCRCounter, pPcrProcesser->PCRCounter);
}

void PCRSYNC_CheckPCRStable(DEMUX_PCRSYNC_T *pPcrProcesser)
{
	bool bNoPCR = pPcrProcesser->bNoPCR;
	if (pPcrProcesser->noPCRCounter > 100)
		pPcrProcesser->bNoPCR = true;
	else if (pPcrProcesser->PCRCounter > 2)
		pPcrProcesser->bNoPCR = false;

	//printf("[%s %d] m_PCRCounter=%d, m_noPCRCounter=%d, m_bNoPCR=%d\n", __FILE__, __LINE__, m_PCRCounter, m_noPCRCounter, m_bNoPCR);
	if (pPcrProcesser->bNoPCR != bNoPCR) {
		if (pPcrProcesser->bNoPCR == true) {
			pPcrProcesser->bVirtualPcrMode = true;
			pPcrProcesser->bHighWaterLevelMode = true;
			pPcrProcesser->checkPcrOffset = PREPARE_TO_GET_OFFSET;
			//printf("[%s %d] PCR Check: [%d][%d/%d].\n", __func__, __LINE__, m_bNoPCR, m_noPCRCounter, m_PCRCounter);
		} else {
			pPcrProcesser->bVirtualPcrMode = false;
			pPcrProcesser->bHighWaterLevelMode = false;
			pPcrProcesser->checkPcrOffset = PREPARE_TO_GET_OFFSET;
			//printf("[%s %d] PCR Check: [%d][%d/%d].\n", __func__, __LINE__, m_bNoPCR, m_noPCRCounter, m_PCRCounter);
		}
	}

	if ((pPcrProcesser->bNoPCR != bNoPCR) || (pPcrProcesser->noPCRCounter + pPcrProcesser->PCRCounter) > 1000) {
		dmx_mask_print(DEMUX_PCRSYC_DEBUG,"[dtv(%d)]:PCR Check: [%d][%d/%d].\n", pPcrProcesser->tunerHandle, pPcrProcesser->bNoPCR, pPcrProcesser->noPCRCounter, pPcrProcesser->PCRCounter);
		pPcrProcesser->noPCRCounter = 0;
		pPcrProcesser->PCRCounter = 0;
	}

}

void PCRSYNC_UpdateAVPTSStableStatus(DEMUX_PCRSYNC_T *pPcrProcesser)
{
	int32_t APtsQuo;

	if(pPcrProcesser->AVPtsCheckFlag == 0)
	{
		//dmx_mask_print(DEMUX_PCRSYC_DEBUG,"PCRSYNC_UpdateAVPTSStableStatus return");
		return;
    }

	APtsQuo = div_s64(pPcrProcesser->AudioPTSDiff * 1000,pPcrProcesser->AudioCheckClkDiff);

	if(abs(APtsQuo - 1000) >= AVPTS_UNSTABLE_THRESHOLD_LOW){
		pPcrProcesser->AptsUnStableCounter++;
		pPcrProcesser->AptsStableCounter = 0;
	}else{
		pPcrProcesser->AptsStableCounter++;
		pPcrProcesser->AptsUnStableCounter = 0;
	}

	pPcrProcesser->AudioPTSDiff = 0;
	pPcrProcesser->AudioCheckClkDiff = 0;
	pPcrProcesser->AVPtsCheckFlag = false;

}

void PCRSYNC_CheckAVPTSStable(DEMUX_PCRSYNC_T *pPcrProcesser)
{
	long VFreerunThresholdValue = 0, AFreerunThresholdValue = 0, AFreerunThrToWaitValue = 0;

	if(pPcrProcesser->AptsStableCounter >= AVPTS_UNSTABLE_THRESHOLD_COUNTER_MID)
		pPcrProcesser->isUnderFreeRunModePTS = false;
	if(pPcrProcesser->AptsUnStableCounter >= AVPTS_UNSTABLE_THRESHOLD_COUNTER_LOW)
		pPcrProcesser->isUnderFreeRunModePTS = true;

	REFCLK_GetFreeRunThreshold(pPcrProcesser->pRefClock,&VFreerunThresholdValue,&AFreerunThresholdValue,&AFreerunThrToWaitValue);

	if(!pPcrProcesser->isUnderFreeRunModePTS){
		if(!pPcrProcesser->isUnderFreeRunMode)
		{
			if(AFreerunThresholdValue == MIN_FREE_RUN_THRESHOLD){
				REFCLK_SetAudioFreeRunThreshold(pPcrProcesser->pRefClock, DEFAULT_FREE_RUN_THRESHOLD, DEFAULT_FREE_RUN_THRESHOLD);			
				dmx_mask_print(DEMUX_PCRSYC_DEBUG,"PTS is stable,RCD is stable,set to pcr master!!! isUnderFreeRunModePTS = %d\n",pPcrProcesser->isUnderFreeRunModePTS);
			}
		}
	}else if(pPcrProcesser->isUnderFreeRunModePTS){
		if(!pPcrProcesser->isUnderFreeRunMode)
		{			
			if(AFreerunThresholdValue > MIN_FREE_RUN_THRESHOLD && AFreerunThresholdValue <= MAX_FREE_RUN_THRESHOLD){
				dmx_mask_print(DEMUX_PCRSYC_DEBUG,"PTS is not Stable,RCD is stable,set to free run!!! isUnderFreeRunModePTS = %d\n",pPcrProcesser->isUnderFreeRunModePTS);
				REFCLK_SetAudioFreeRunThreshold(pPcrProcesser->pRefClock, MIN_FREE_RUN_THRESHOLD, MIN_FREE_RUN_THRESHOLD);
			}
		}
	}

}

void PCRSYNC_UpdatePTSStableStatus(DEMUX_PCRSYNC_T *pPcrProcesser, int64_t audioPTS, int64_t videoPTS)
{
	if (pPcrProcesser->bHasAudioPidOrDest == false)
		pPcrProcesser->noAudioPtsCounter += 30;
	else if (audioPTS == -1 || audioPTS == pPcrProcesser->lastDemuxAudioPTS)
		pPcrProcesser->noAudioPtsCounter++;
	else {
		pPcrProcesser->audioPtsCounter++;
		pPcrProcesser->noAudioPtsCounter = 0;
	}
	//printf("No Audio PTS (%d)\n", m_noAudioPtsCounter);

	if (videoPTS == -1 || videoPTS == pPcrProcesser->lastDemuxVideoPTS)
	{
		if( (pPcrProcesser->bHasVideoPidOrDest == false) && (abs64( CLOCK_GetPTS() - pPcrProcesser->checkVideoPidStart ) > ((DEMUX_CLOCKS_PER_SEC/10)* 2)) && (pPcrProcesser->noVideoPtsCounter > 2) )	{
			pPcrProcesser->noVideoPtsCounter = 301;
			dmx_mask_print(DEMUX_PCRSYC_DEBUG,"[dtv(%d)]:no find vidoe pid and video PTS. set bNoVideoPts to true\n", pPcrProcesser->tunerHandle);
		}
		else
			pPcrProcesser->noVideoPtsCounter++;
	}
	else {
		pPcrProcesser->videoPtsCounter++;
		pPcrProcesser->noVideoPtsCounter = 0;
	}
	//printf("No Video PTS (%d)\n", m_noVideoPtsCounter);

}

void PCRSYNC_CheckPTSStable(DEMUX_PCRSYNC_T *pPcrProcesser)
{
	bool bNoAudioPts, bNoVideoPts;
	int beforePreferAVPTS;

	//if((m_noAudioPtsCounter + m_audioPtsCounter) > 100)
	{
		bNoAudioPts = pPcrProcesser->bNoAudioPts;
		if(pPcrProcesser->noAudioPtsCounter > 300)
			pPcrProcesser->bNoAudioPts = true;
		else if(pPcrProcesser->audioPtsCounter > 5)
			pPcrProcesser->bNoAudioPts = false;
		else if(pPcrProcesser->audioPtsCounter == 0)
			pPcrProcesser->noAudioPtsCounter++;

		//printf("[%s %d] m_audioPtsCounter=%d, m_noAudioPtsCounter=%d, m_bNoAudioPts=%d\n", __FILE__, __LINE__, m_audioPtsCounter, m_noAudioPtsCounter, m_bNoAudioPts);
		if((pPcrProcesser->audioFullnessHighCount > 0) || (bNoAudioPts != pPcrProcesser->bNoAudioPts) || (pPcrProcesser->noAudioPtsCounter + pPcrProcesser->audioPtsCounter) > 1000)
		{
			if((bNoAudioPts != pPcrProcesser->bNoAudioPts) || (pPcrProcesser->noAudioPtsCounter + pPcrProcesser->audioPtsCounter) > 1000)
				dmx_mask_print(DEMUX_PCRSYC_DEBUG,"[dtv(%d)]:Audio PTS Check: [%d][%d/%d].\n", pPcrProcesser->tunerHandle, pPcrProcesser->bNoAudioPts, pPcrProcesser->noAudioPtsCounter, pPcrProcesser->audioPtsCounter);

			pPcrProcesser->noAudioPtsCounter = 0;
			pPcrProcesser->audioPtsCounter = 0;
		}
	}

	//if((m_noVideoPtsCounter + m_videoPtsCounter) > 100)
	{
		bNoVideoPts = pPcrProcesser->bNoVideoPts;
		if(pPcrProcesser->noVideoPtsCounter > 300)
			pPcrProcesser->bNoVideoPts = true;
		else if(pPcrProcesser->videoPtsCounter > 5)
			pPcrProcesser->bNoVideoPts = false;
		else if(pPcrProcesser->videoPtsCounter == 0)
			pPcrProcesser->noVideoPtsCounter++;
	
		//printf("[%s %d] m_videoPtsCounter=%d, m_noVideoPtsCounter=%d, m_bNoVideoPts=%d\n", __FILE__, __LINE__, m_videoPtsCounter, m_noVideoPtsCounter, m_bNoVideoPts);
		if((pPcrProcesser->videoFullnessHighCount > 0) || (bNoVideoPts != pPcrProcesser->bNoVideoPts) || (pPcrProcesser->noVideoPtsCounter + pPcrProcesser->videoPtsCounter) > 1000)
		{
			if((bNoVideoPts != pPcrProcesser->bNoVideoPts) || (pPcrProcesser->noVideoPtsCounter + pPcrProcesser->videoPtsCounter) > 1000)
				dmx_mask_print(DEMUX_PCRSYC_DEBUG,"[dtv(%d)]:Video PTS Check: [%d][%d/%d].\n", pPcrProcesser->tunerHandle, pPcrProcesser->bNoVideoPts, pPcrProcesser->noVideoPtsCounter, pPcrProcesser->videoPtsCounter);

			pPcrProcesser->noVideoPtsCounter = 0;
			pPcrProcesser->videoPtsCounter = 0;
		}
	}

	if((pPcrProcesser->bNoAudioPts != bNoAudioPts) || (pPcrProcesser->bNoVideoPts != bNoVideoPts))
	{
		beforePreferAVPTS = pPcrProcesser->preferAVPTS;
		if((pPcrProcesser->bNoAudioPts == true) && (pPcrProcesser->bNoVideoPts == false))
		{
			pPcrProcesser->preferAVPTS = VIDEO_TYPE;
		}
		else if((pPcrProcesser->bNoAudioPts == false) && (pPcrProcesser->bNoVideoPts == true))
		{
			pPcrProcesser->preferAVPTS = AUDIO_TYPE;
		}
		else
		{
			pPcrProcesser->preferAVPTS = NONE;
		}
		if((pPcrProcesser->referenceAVPTS > NONE) && (pPcrProcesser->preferAVPTS != pPcrProcesser->referenceAVPTS) && (pPcrProcesser->preferAVPTS != beforePreferAVPTS))
			pPcrProcesser->checkPcrOffset = PREPARE_TO_GET_OFFSET;
	}
}

void PCRSYNC_UpdateSignalStableStatus(DEMUX_PCRSYNC_T *pPcrProcesser)
{
	if (pPcrProcesser->bNoPCR == true && pPcrProcesser->bNoAudioPts == true && pPcrProcesser->bNoVideoPts == true)
		pPcrProcesser->noSignalCounter++;
	else {
		pPcrProcesser->SignalCounter++;
		pPcrProcesser->noSignalCounter = 0;
	}
}

void PCRSYNC_CheckSignalStable(DEMUX_PCRSYNC_T *pPcrProcesser)
{
	bool bBadSignal = pPcrProcesser->bBadSignal;
	if (pPcrProcesser->noSignalCounter > 100)
		pPcrProcesser->bBadSignal = true;
	else if (pPcrProcesser->SignalCounter > 2)
		pPcrProcesser->bBadSignal = false;

	if ((pPcrProcesser->bBadSignal != bBadSignal) || (pPcrProcesser->noSignalCounter + pPcrProcesser->SignalCounter) > 1000) {
		dmx_mask_print(DEMUX_PCRSYC_DEBUG,"[dtv(%d)]:Signal Check: [%d][%d/%d].\n", pPcrProcesser->tunerHandle, pPcrProcesser->bBadSignal, pPcrProcesser->noSignalCounter, pPcrProcesser->SignalCounter);
		pPcrProcesser->noSignalCounter = 0;
		pPcrProcesser->SignalCounter = 0;
	}

	if (bBadSignal == false && pPcrProcesser->bBadSignal != bBadSignal) {
		PCRSYNC_ResetVariables(pPcrProcesser);
	}
}

void PCRSYNC_UpdateOutputStatus(DEMUX_PCRSYNC_T *pPcrProcesser)
{
/*
[MANTIS-154376]
In wrap around case, we need to set video free run threshold early;
otherwise, video output is blocked by MAX_FREE_RUN_THRESHOLD at least 10s.
*/
	int64_t RCD = 0;
	
	RCD = REFCLK_GetRCD(pPcrProcesser->pRefClock);
	if (RCD == -1)
		return;

	if (pPcrProcesser->lastAudioSystemPTS == -1 || pPcrProcesser->lastAudioSystemPTS == pPcrProcesser->prevAudioSystemPTS)
		pPcrProcesser->noAoutPtsCounter+=10;
	else {
		pPcrProcesser->aoutPtsCounter++;
		pPcrProcesser->noAoutPtsCounter = 0;
	}
	//printf("No Aout PTS (%d)\n", m_noAoutPtsCounter);

	if (pPcrProcesser->lastVideoSystemPTS == -1 || pPcrProcesser->lastVideoSystemPTS == pPcrProcesser->prevVideoSystemPTS)
		pPcrProcesser->noVoutPtsCounter+=10;
	else {
		pPcrProcesser->voutPtsCounter++;
		pPcrProcesser->noVoutPtsCounter = 0;
	}
	//printf("No Vout PTS (%d)\n", m_noVoutPtsCounter);

}

void PCRSYNC_CheckOutputStable(DEMUX_PCRSYNC_T *pPcrProcesser)
{
	bool bNoVideoOutputPts;
	bool bNoAudioOutputPts = pPcrProcesser->bNoAudioOutputPts;
	if (pPcrProcesser->noAoutPtsCounter > 100)
		pPcrProcesser->bNoAudioOutputPts = true;
	else if (pPcrProcesser->aoutPtsCounter > 10)
		pPcrProcesser->bNoAudioOutputPts = false;

	//printf("[%s %d] m_aoutPtsCounter=%d, m_noAoutPtsCounter=%d, m_bNoAudioOutputPts=%d\n", __FILE__, __LINE__, m_aoutPtsCounter, m_noAoutPtsCounter, m_bNoAudioOutputPts);
	if ((bNoAudioOutputPts != pPcrProcesser->bNoAudioOutputPts) || (pPcrProcesser->noAoutPtsCounter + pPcrProcesser->aoutPtsCounter) > 1000) {
		dmx_mask_print(DEMUX_PCRSYC_DEBUG,"[dtv(%d)]:AOut PTS Check: [%d][%d/%d].\n", pPcrProcesser->tunerHandle, pPcrProcesser->bNoAudioOutputPts, pPcrProcesser->noAoutPtsCounter, pPcrProcesser->aoutPtsCounter);
	
		pPcrProcesser->noAoutPtsCounter = 0;
		pPcrProcesser->aoutPtsCounter = 0;
	}


	bNoVideoOutputPts = pPcrProcesser->bNoVideoOutputPts;
	if (pPcrProcesser->noVoutPtsCounter > 100)
		pPcrProcesser->bNoVideoOutputPts = true;
	else if (pPcrProcesser->voutPtsCounter > 10)
		pPcrProcesser->bNoVideoOutputPts = false;
	
	//printf("[%s %d] m_voutPtsCounter=%d, m_noVoutPtsCounter=%d, m_bNoVideoOutputPts=%d\n", __FILE__, __LINE__, m_voutPtsCounter, m_noVoutPtsCounter, m_bNoVideoOutputPts);
	if ((bNoVideoOutputPts != pPcrProcesser->bNoVideoOutputPts) || (pPcrProcesser->noVoutPtsCounter + pPcrProcesser->voutPtsCounter) > 1000) {
		dmx_mask_print(DEMUX_PCRSYC_DEBUG,"[dtv(%d)]:VOut PTS Check: [%d][%d/%d].\n", pPcrProcesser->tunerHandle, pPcrProcesser->bNoVideoOutputPts, pPcrProcesser->noVoutPtsCounter, pPcrProcesser->voutPtsCounter);
	
		pPcrProcesser->noVoutPtsCounter = 0;
		pPcrProcesser->voutPtsCounter = 0;
	}

}

void PCRSYNC_UpdateFullnessStatus(DEMUX_PCRSYNC_T *pPcrProcesser)
{
	long videoUnderflow = 0, audioUnderflow = 0;
	int64_t mpts;
	int64_t RCD = REFCLK_GetRCD(pPcrProcesser->pRefClock);
	
	REFCLK_CheckUnderflow(pPcrProcesser->pRefClock, &videoUnderflow, &audioUnderflow);
	if(RCD == -1)
		return;

	mpts = RCD + CLOCK_GetAVSyncPTS(pPcrProcesser->pRefClock);
	if (pPcrProcesser->bNoAudioPts == false && pPcrProcesser->lastDemuxAudioPTS != -1 && pPcrProcesser->lastAudioSystemPTS != -1) {

		if ((pPcrProcesser->isTrackingSteady == 1 || pPcrProcesser->isTrackingSteady == 2) && pPcrProcesser->bAudioRingBufferFull == true)
			pPcrProcesser->audioFullnessHighCount++;

		if (pPcrProcesser->audioFullnessHighCount)
			pPcrProcesser->audioFullnessHighCheckCount++;

		//printf("[%s %d] FullnessHighCheck: A:[%d][%d/%d].\n", __FUNCTION__, __LINE__,
		//  status.isSteady, m_audioFullnessHighCount, m_audioFullnessHighCheckCount);

		if (pPcrProcesser->bVirtualPcrMode == false && (pPcrProcesser->isTrackingSteady == 1 || pPcrProcesser->isTrackingSteady == 3 || pPcrProcesser->bHighWaterLevelMode == false) && ((pPcrProcesser->bNoAudioOutputPts == false && audioUnderflow != 0) || (pPcrProcesser->referenceAVPTS == AUDIO_TYPE && mpts > pPcrProcesser->lastDemuxAudioPTS)))
			pPcrProcesser->audioFullnessLowCount++;

		if (pPcrProcesser->audioFullnessLowCount)
			pPcrProcesser->audioFullnessLowCheckCount++;

		//printf("[%s %d] FullnessLowCheck: A:[%d/%d][%d/%d].\n", __FUNCTION__, __LINE__,
		//  status.isSteady, m_referenceAVPTS, m_audioFullnessLowCount, m_audioFullnessLowCheckCount);
	}

	if (pPcrProcesser->bNoVideoPts == false && pPcrProcesser->lastDemuxVideoPTS != -1 && pPcrProcesser->lastVideoSystemPTS != -1) {
		int64_t vdiff = pPcrProcesser->lastDemuxVideoPTS - pPcrProcesser->lastVideoSystemPTS;


		if ((pPcrProcesser->isTrackingSteady == 1 || pPcrProcesser->isTrackingSteady == 2) && pPcrProcesser->bVideoRingBufferFull == true)
			pPcrProcesser->videoFullnessHighCount++;

		if (pPcrProcesser->videoFullnessHighCount)
			pPcrProcesser->videoFullnessHighCheckCount++;

		//printf("[%s %d] FullnessHighCheck: V:[%d][%d/%d].\n", __FUNCTION__, __LINE__,
		//  status.isSteady, m_videoFullnessHighCount, m_videoFullnessHighCheckCount);

		if (pPcrProcesser->bVirtualPcrMode == false && pPcrProcesser->referenceAVPTS == VIDEO_TYPE && (pPcrProcesser->isTrackingSteady == 1 || pPcrProcesser->isTrackingSteady == 3 || pPcrProcesser->bHighWaterLevelMode == false) && ((vdiff >= 0 && vdiff < 10000) || (mpts > pPcrProcesser->lastDemuxVideoPTS)))
			pPcrProcesser->videoFullnessLowCount++;

		if (pPcrProcesser->videoFullnessLowCount)
			pPcrProcesser->videoFullnessLowCheckCount++;

		//printf("[%s %d] FullnessLowCheck: V:[%d/%d][%d/%d].\n", __FUNCTION__, __LINE__,
		//    status.isSteady, m_referenceAVPTS, m_videoFullnessLowCount, m_videoFullnessLowCheckCount);
	}
}

void PCRSYNC_CheckFullness(DEMUX_PCRSYNC_T *pPcrProcesser)
{
	if (pPcrProcesser->bHighWaterLevelMode == false && ((pPcrProcesser->audioFullnessLowCount > 100) || (pPcrProcesser->videoFullnessLowCount > 100))) {
		pPcrProcesser->bHighWaterLevelMode = true;
		pPcrProcesser->checkPcrOffset = PREPARE_TO_GET_OFFSET;

		dmx_mask_print(DEMUX_PCRSYC_DEBUG,"[dtv(%d)]:Fullness Low Check A:[%d][%d/%d], V:[%d][%d/%d].\n", pPcrProcesser->tunerHandle,
		pPcrProcesser->bNoAudioPts, pPcrProcesser->audioFullnessLowCount, pPcrProcesser->audioFullnessLowCheckCount,
		pPcrProcesser->bNoVideoPts, pPcrProcesser->videoFullnessLowCount, pPcrProcesser->videoFullnessLowCheckCount);
	} else if ((pPcrProcesser->audioFullnessLowCount > 300) || (pPcrProcesser->videoFullnessLowCount > 300)) {
		if (pPcrProcesser->bVirtualPcrMode == false && pPcrProcesser->isTrackingSteady == 3 && pPcrProcesser->preferAVPTS == NONE) {
			if (pPcrProcesser->referenceAVPTS == AUDIO_TYPE && pPcrProcesser->audioFullnessLowCount > 300)
				pPcrProcesser->preferAVPTS = VIDEO_TYPE;
			else if (pPcrProcesser->referenceAVPTS == VIDEO_TYPE && pPcrProcesser->videoFullnessLowCount > 300)
				pPcrProcesser->preferAVPTS = AUDIO_TYPE;
		}
		else
			pPcrProcesser->bVirtualPcrMode = true;

		pPcrProcesser->bHighWaterLevelMode = true;
		pPcrProcesser->checkPcrOffset = PREPARE_TO_GET_OFFSET;

		dmx_mask_print(DEMUX_PCRSYC_DEBUG,"[dtv(%d)]:Fullness Low Check A:[%d][%d/%d], V:[%d][%d/%d].\n", pPcrProcesser->tunerHandle,
		pPcrProcesser->bNoAudioPts, pPcrProcesser->audioFullnessLowCount, pPcrProcesser->audioFullnessLowCheckCount,
		pPcrProcesser->bNoVideoPts, pPcrProcesser->videoFullnessLowCount, pPcrProcesser->videoFullnessLowCheckCount);
	} else if ((pPcrProcesser->audioFullnessHighCount > 300) || (pPcrProcesser->videoFullnessHighCount > 300)) {
		if (pPcrProcesser->bVirtualPcrMode == true) {
			if (pPcrProcesser->videoFullnessHighCount > 300)
				pPcrProcesser->preferAVPTS = VIDEO_TYPE;
			else
				pPcrProcesser->preferAVPTS = AUDIO_TYPE;
		}
		pPcrProcesser->bVirtualPcrMode = true;
		pPcrProcesser->bHighWaterLevelMode = true;
		pPcrProcesser->checkPcrOffset = PREPARE_TO_GET_OFFSET;

		dmx_mask_print(DEMUX_PCRSYC_DEBUG,"[dtv(%d)]:Fullness High Check A:[%d][%d/%d], V:[%d][%d/%d].\n", pPcrProcesser->tunerHandle,
		pPcrProcesser->bNoAudioPts, pPcrProcesser->audioFullnessHighCount, pPcrProcesser->audioFullnessHighCheckCount,
		pPcrProcesser->bNoVideoPts, pPcrProcesser->videoFullnessHighCount, pPcrProcesser->videoFullnessHighCheckCount);
	}

	if(pPcrProcesser->checkPcrOffset != HAVE_STEADY_OFFSET || pPcrProcesser->audioFullnessLowCheckCount > 1000) {
		if (pPcrProcesser->audioFullnessLowCheckCount > 1000)
			dmx_mask_print(DEMUX_PCRSYC_DEBUG,"[dtv(%d)]:Fullness Low Check A:[%d][%d/%d].\n", pPcrProcesser->tunerHandle, pPcrProcesser->bNoAudioPts, pPcrProcesser->audioFullnessLowCount, pPcrProcesser->audioFullnessLowCheckCount);

		pPcrProcesser->audioFullnessLowCount = 0;
		pPcrProcesser->audioFullnessLowCheckCount = 0;
	}
	if(pPcrProcesser->checkPcrOffset != HAVE_STEADY_OFFSET || pPcrProcesser->audioFullnessHighCheckCount > 1000) {
		if (pPcrProcesser->audioFullnessHighCheckCount > 1000)
			dmx_mask_print(DEMUX_PCRSYC_DEBUG,"[dtv(%d)]:Fullness High Check A:[%d][%d/%d].\n", pPcrProcesser->tunerHandle, pPcrProcesser->bNoAudioPts, pPcrProcesser->audioFullnessHighCount, pPcrProcesser->audioFullnessHighCheckCount);

		pPcrProcesser->audioFullnessHighCount = 0;
		pPcrProcesser->audioFullnessHighCheckCount = 0;
	}
	if(pPcrProcesser->checkPcrOffset != HAVE_STEADY_OFFSET || pPcrProcesser->videoFullnessLowCheckCount > 1000) {
		if (pPcrProcesser->videoFullnessLowCheckCount > 1000)
			dmx_mask_print(DEMUX_PCRSYC_DEBUG,"[dtv(%d)]:Fullness Low Check V:[%d][%d/%d].\n", pPcrProcesser->tunerHandle, pPcrProcesser->bNoVideoPts, pPcrProcesser->videoFullnessLowCount, pPcrProcesser->videoFullnessLowCheckCount);

		pPcrProcesser->videoFullnessLowCount = 0;
		pPcrProcesser->videoFullnessLowCheckCount = 0;
	}
	if (pPcrProcesser->checkPcrOffset != HAVE_STEADY_OFFSET || pPcrProcesser->videoFullnessHighCheckCount > 1000) {
		if (pPcrProcesser->videoFullnessHighCheckCount > 1000)
			dmx_mask_print(DEMUX_PCRSYC_DEBUG,"[dtv(%d)]:Fullness High Check V:[%d][%d/%d].\n", pPcrProcesser->tunerHandle, pPcrProcesser->bNoVideoPts, pPcrProcesser->videoFullnessHighCount, pPcrProcesser->videoFullnessHighCheckCount);

		pPcrProcesser->videoFullnessHighCount = 0;
		pPcrProcesser->videoFullnessHighCheckCount = 0;
	}
}

void PCRSYNC_UpdateRCDStableStatus(DEMUX_PCRSYNC_T *pPcrProcesser, NAVDTVPCRINFO pcrinfo)
{
	int64_t rcd = pcrinfo.pcr - pcrinfo.stc - pPcrProcesser->pcrOffset;
	int64_t prev_rcd = pPcrProcesser->pcr - pPcrProcesser->stc - pPcrProcesser->pcrOffset;
	int64_t rcd_diff = abs(rcd - prev_rcd);

	DEMUX_RCD_STABILITY_MONITOR_T* rcdMonitor = &pPcrProcesser->rcdStabilityMonitor;

	if (pPcrProcesser->rcd == -1 || pcrinfo.stc <= 0 || pcrinfo.stc == pPcrProcesser->stc)
		return;

	if (rcdMonitor->bIsArrayWrapAround) {
		rcdMonitor->rcdUnstableTotal -= rcdMonitor->array[rcdMonitor->index];
	}

	if (rcd_diff >= RCD_UNSTABLE_LEVEL_S) {
		rcdMonitor->array[rcdMonitor->index] = RCD_UNSTABLE_WEIGHTS_S;
	} else if (rcd_diff >= RCD_UNSTABLE_LEVEL_A) {
		rcdMonitor->array[rcdMonitor->index] = RCD_UNSTABLE_WEIGHTS_A;
	} else if (rcd_diff >= RCD_UNSTABLE_LEVEL_B) {
		rcdMonitor->array[rcdMonitor->index] = RCD_UNSTABLE_WEIGHTS_B;
	} else if (rcd_diff >= RCD_UNSTABLE_LEVEL_C) {
		rcdMonitor->array[rcdMonitor->index] = RCD_UNSTABLE_WEIGHTS_C;
	} else {
		rcdMonitor->array[rcdMonitor->index] = RCD_UNSTABLE_WEIGHTS_STABLE;
	}

	rcdMonitor->rcdUnstableTotal += rcdMonitor->array[rcdMonitor->index];

	if (++rcdMonitor->index >= RCD_STABILITY_SAMPLE_NUM) {
		rcdMonitor->bIsArrayWrapAround = true;
		rcdMonitor->index = 0;
	}

	//dmx_mask_print(DEMUX_PCRSYC_DEBUG, "rcd_diff = %lld.\n", rcd_diff);
}

// FIXME Need to fine tune
void PCRSYNC_CheckRCDStable(DEMUX_PCRSYNC_T *pPcrProcesser)
{
	int rcdUnstableValue = 0, rcdStabilityCount = 0;
	bool bIsWrapAround = pPcrProcesser->rcdStabilityMonitor.bIsArrayWrapAround;
	long VFreerunThresholdValue = 0, AFreerunThresholdValue = 0, AFreerunThrToWaitValue = 0;

	rcdStabilityCount = bIsWrapAround ? RCD_STABILITY_SAMPLE_NUM : pPcrProcesser->rcdStabilityMonitor.index;
	if (rcdStabilityCount < RCD_STABILITY_SAMPLE_NUM)
		return;

	rcdUnstableValue = (pPcrProcesser->rcdStabilityMonitor.rcdUnstableTotal*100)/rcdStabilityCount;
	REFCLK_GetFreeRunThreshold(pPcrProcesser->pRefClock,&VFreerunThresholdValue,&AFreerunThresholdValue,&AFreerunThrToWaitValue);
	//dmx_mask_print(DEMUX_PCRSYC_DEBUG,"RCD value [%d]\n",rcdUnstableValue);
#ifdef ENTER_FREE_RUN_MODE_WHEN_RCD_UNSTABLE
	if(rcdUnstableValue >= RCD_UNSTABLE_THRESHOLD_HIGH){
		pPcrProcesser->isUnderFreeRunMode = true;		//rcd unstable
		if((VFreerunThresholdValue > MIN_FREE_RUN_THRESHOLD && VFreerunThresholdValue <= MAX_FREE_RUN_THRESHOLD) || 
			(AFreerunThresholdValue > MIN_FREE_RUN_THRESHOLD && AFreerunThresholdValue <= MAX_FREE_RUN_THRESHOLD)){
		    dmx_crit("[dtv(%d)]:RCD[%d/%d] RCD not stable, set to free run!!!\n", pPcrProcesser->tunerHandle, rcdUnstableValue, RCD_UNSTABLE_THRESHOLD_HIGH);
		    REFCLK_SetVideoFreeRunThreshold(pPcrProcesser->pRefClock, MIN_FREE_RUN_THRESHOLD);
		    REFCLK_SetAudioFreeRunThreshold(pPcrProcesser->pRefClock, MIN_FREE_RUN_THRESHOLD, MIN_FREE_RUN_THRESHOLD);	
		}
	}else{
		pPcrProcesser->isUnderFreeRunMode = false;		//rcd stable
		if(!pPcrProcesser->isUnderFreeRunModePTS){
			if(VFreerunThresholdValue == MIN_FREE_RUN_THRESHOLD || AFreerunThresholdValue == MIN_FREE_RUN_THRESHOLD){
				dmx_crit("[dtv(%d)]:RCD[%d/%d] RCD and PTS is stable, set to pcr master!!!\n", pPcrProcesser->tunerHandle, rcdUnstableValue, RCD_UNSTABLE_THRESHOLD_HIGH);
				REFCLK_SetVideoFreeRunThreshold(pPcrProcesser->pRefClock, DEFAULT_FREE_RUN_THRESHOLD);
				REFCLK_SetAudioFreeRunThreshold(pPcrProcesser->pRefClock, DEFAULT_FREE_RUN_THRESHOLD, DEFAULT_FREE_RUN_THRESHOLD);
			}
		}else{
			if((VFreerunThresholdValue > MIN_FREE_RUN_THRESHOLD && VFreerunThresholdValue <= MAX_FREE_RUN_THRESHOLD) || 
			(AFreerunThresholdValue > MIN_FREE_RUN_THRESHOLD && AFreerunThresholdValue <= MAX_FREE_RUN_THRESHOLD)){
				dmx_crit("[dtv(%d)]:RCD[%d/%d] RCD stable, but PTS is not stable, set to free run!!!\n", pPcrProcesser->tunerHandle, rcdUnstableValue, RCD_UNSTABLE_THRESHOLD_HIGH);
				REFCLK_SetVideoFreeRunThreshold(pPcrProcesser->pRefClock, MIN_FREE_RUN_THRESHOLD);
				REFCLK_SetAudioFreeRunThreshold(pPcrProcesser->pRefClock, MIN_FREE_RUN_THRESHOLD, MIN_FREE_RUN_THRESHOLD);	
			}
		}
	}
#else
	/* Status change(bVirtualPcrMode)*/
	if (pPcrProcesser->bVirtualPcrMode == true && rcdUnstableValue < RCD_UNSTABLE_THRESHOLD_LOW) {
		pPcrProcesser->bVirtualPcrMode = false;
		pPcrProcesser->bHighWaterLevelMode = false;
		pPcrProcesser->checkPcrOffset = PREPARE_TO_GET_OFFSET;
		dmx_mask_print(DEMUX_PCRSYC_DEBUG,"[dtv(%d)]:RCD Check: NoPCR[%d] virtualPcrMode[%d] RCD[%d/%d].\n", pPcrProcesser->tunerHandle, pPcrProcesser->bNoPCR, pPcrProcesser->bVirtualPcrMode, rcdUnstableValue, RCD_UNSTABLE_THRESHOLD_LOW);
	} else if (pPcrProcesser->bVirtualPcrMode == false && rcdUnstableValue >= RCD_UNSTABLE_THRESHOLD_HIGH) {
		pPcrProcesser->bVirtualPcrMode = true;
		pPcrProcesser->bHighWaterLevelMode = true;
		pPcrProcesser->checkPcrOffset = PREPARE_TO_GET_OFFSET;
		dmx_mask_print(DEMUX_PCRSYC_DEBUG,"[dtv(%d)]:RCD Check: NoPCR[%d] virtualPcrMode[%d] RCD[%d/%d].\n", pPcrProcesser->tunerHandle, pPcrProcesser->bNoPCR, pPcrProcesser->bVirtualPcrMode, rcdUnstableValue, RCD_UNSTABLE_THRESHOLD_HIGH);
	}
#endif
}

void PCRSYNC_UpdateDemuxPTS(DEMUX_PCRSYNC_T *pPcrProcesser, bool bVideo, bool bAudio, int64_t pts, bool bIsSubAudio)
{
	if (bVideo) {
		PCRSYNC_UpdatePTSStableStatus(pPcrProcesser, -1, pts);

		if (pPcrProcesser->startVideoPts == -1) {
			dmx_crit("[dtv] deliver first video pts = %lld, time = %lld, lastDemuxAudioPTS = %lld\n", pts, CLOCK_GetAVSyncPTS(pPcrProcesser->pRefClock), pPcrProcesser->lastDemuxAudioPTS);
			pPcrProcesser->startVideoPts = pts;

			if((pPcrProcesser->startVideoPts != -1) && (pPcrProcesser->bAdjusted == true) && (pPcrProcesser->startAudioPts != -1)) {
				pPcrProcesser->bVirtualPcrMode = false;
				pPcrProcesser->bHighWaterLevelMode = false;
				pPcrProcesser->checkPcrOffset = PREPARE_TO_GET_OFFSET;
				pPcrProcesser->bAdjusted = false;
			}
		}

		pPcrProcesser->lastDemuxVideoPTS = pts;

	}
	else if (bAudio) {	
		if (!bIsSubAudio) { /*main Audio*/
			PCRSYNC_UpdatePTSStableStatus(pPcrProcesser, pts, -1);

			if (pPcrProcesser->startAudioPts == -1) {
				dmx_crit("[dtv] deliver first audio pts = %lld, time = %lld, lastDemuxVideoPTS = %lld\n", pts, CLOCK_GetAVSyncPTS(pPcrProcesser->pRefClock), pPcrProcesser->lastDemuxVideoPTS);
				pPcrProcesser->startAudioPts = pts;

				if((pPcrProcesser->startAudioPts != -1) && (pPcrProcesser->bAdjusted == true) && (pPcrProcesser->startVideoPts != -1)) {
					pPcrProcesser->bVirtualPcrMode = false;
					pPcrProcesser->bHighWaterLevelMode = false;
					pPcrProcesser->checkPcrOffset = PREPARE_TO_GET_OFFSET;
					pPcrProcesser->bAdjusted = false;
				}
			}

			pPcrProcesser->AudioPTSDiff += pts - pPcrProcesser->lastDemuxAudioPTS;
			pPcrProcesser->lastDemuxAudioPTS = pts;
			pPcrProcesser->AudioCheckClkDiff += abs(CLOCK_GetAVSyncPTS(pPcrProcesser->pRefClock) - pPcrProcesser->lastAudioClock);
			pPcrProcesser->lastAudioClock = CLOCK_GetAVSyncPTS(pPcrProcesser->pRefClock);
			
			if(pPcrProcesser->AudioCheckClkDiff >= AVPTS_UNSTABLE_THRESHOLD_CLOCK)
				pPcrProcesser->AVPtsCheckFlag = true;
			else
				pPcrProcesser->AVPtsCheckFlag = false;

		} else { /*sub Audio: AD case*/
			if (pPcrProcesser->lastDemuxSubAudioPTS == -1) {
				dmx_crit("[dtv] deliver first sub audio pts = %lld, time = %lld\n", pts, CLOCK_GetAVSyncPTS(pPcrProcesser->pRefClock));
				pPcrProcesser->checkPcrOffset = PREPARE_TO_GET_OFFSET;
			}
			pPcrProcesser->lastDemuxSubAudioPTS = pts;
		}
	}
	PCRSYNC_CheckPTSStable(pPcrProcesser);
}

void PCRSYNC_DEBUG_SaveAvSyncInfo(DEMUX_PCRSYNC_T *pPcrProcesser, NAVDTVPCRINFO *pcrinfo)
{
	RTKDEMUX_AVSYNC_INFO_T info;
	int64_t pll;

	if (!rtkdemux_dbg_dump_avsync_info_is_enabled(pPcrProcesser->tunerHandle))
		return;

	pll = CLOCK_GetAVSyncPTS(pPcrProcesser->pRefClock);

	info.Pcr = pcrinfo->pcr;
	info.Stc = pcrinfo->stc;
	info.Rcd = pPcrProcesser->rcd;
	info.AudioDemuxPts = pPcrProcesser->lastDemuxAudioPTS;
	info.VideoDemuxPts = pPcrProcesser->lastDemuxVideoPTS;
	info.SubAudioDemuxPts = pPcrProcesser->lastDemuxSubAudioPTS;
	info.AudioSystemPts = pPcrProcesser->lastAudioSystemPTS;
	info.VideoSystemPts = pPcrProcesser->lastVideoSystemPTS;
	info.PcrOffset = pPcrProcesser->pcrOffset;
	info.MasterPTS = pPcrProcesser->rcd + pll;
	info.SystemPts = pll;

	rtkdemux_dbg_dump_avsync_info(pPcrProcesser->tunerHandle, &info);

}

void PCRSYNC_UpdateAudioSWPCRInfo(DEMUX_PCRSYNC_T *pPcrProcesser, int64_t pts)
{
	SWDEMUXPCR* pSwPCRInfo = &pPcrProcesser->swPCRInfo;
	if (pSwPCRInfo->aPcrRef == -1)
		return;

	pSwPCRInfo->aDemuxPCR = pSwPCRInfo->aPcrRef;
	pSwPCRInfo->aPcrRef = -1;
	pSwPCRInfo->aDemuxPTS = pts;
	if (pSwPCRInfo->aDemuxPCR != -1 && pSwPCRInfo->vDemuxPCR != -1) {

		if (pSwPCRInfo->aDemuxPCR == pSwPCRInfo->vDemuxPCR) {
			pSwPCRInfo->avPCR = pSwPCRInfo->aDemuxPCR;
			pSwPCRInfo->aPTS = pSwPCRInfo->aDemuxPTS;
			pSwPCRInfo->vPTS = pSwPCRInfo->vDemuxPTS;
		}
	}

}
void PCRSYNC_UpdateVideoSWPCRInfo(DEMUX_PCRSYNC_T *pPcrProcesser, int64_t pts)
{
	SWDEMUXPCR* pSwPCRInfo = &pPcrProcesser->swPCRInfo;
	if (pSwPCRInfo->vPcrRef == -1)
		return;

	pSwPCRInfo->vDemuxPCR = pSwPCRInfo->vPcrRef;
	pSwPCRInfo->vPcrRef = -1;
	pSwPCRInfo->vDemuxPTS = pts;
	if (pSwPCRInfo->vDemuxPCR != -1 && pSwPCRInfo->aDemuxPCR != -1) {
		if (pSwPCRInfo->aDemuxPCR == pSwPCRInfo->vDemuxPCR) {
				pSwPCRInfo->avPCR = pSwPCRInfo->vDemuxPCR;
				pSwPCRInfo->aPTS = pSwPCRInfo->aDemuxPTS;
				pSwPCRInfo->vPTS = pSwPCRInfo->vDemuxPTS;
		}
	}
}
