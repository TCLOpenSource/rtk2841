#include <generated/autoconf.h>
#include <asm/uaccess.h>
#include <asm/cacheflush.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/dma-mapping.h>
#include <linux/fs.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/pageremap.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/kthread.h>
#include <linux/string.h>
#include "rtkdemux.h"
#include "rtkdemux_buf.h"
#include "rtkdemux_ioctl_ex.h"
#include "rtkdemux_export.h"
#include "rtkdemux_debug.h"
#include "rtkdemux_specialhandling.h"
#include "rtkdemux_chmgr.h"

int IOCTLEX_PESDestToPin(DEMUX_PES_DEST_T dest)
{
	switch (dest) {
	case DEMUX_DEST_VDEC0: return VIDEO_PIN;
	case DEMUX_DEST_VDEC1: return VIDEO2_PIN;
	case DEMUX_DEST_ADEC0: return AUDIO_PIN;
	case DEMUX_DEST_ADEC1: return AUDIO2_PIN;
	case DEMUX_DEST_SUBTITLE: return SUBTITLE_PIN;
	case DEMUX_DEST_TELETEXT: return TELETEXT_PIN;
	case DEMUX_DEST_ISDB_CC: return ISDB_CC_PIN;
	case DEMUX_DEST_ISDB_CC_SUPERIMPOSE: return ISDB_CC_SUPERIMPOSE_PIN;
	default:
		return NUMBER_OF_PINS;
	}
}
int IOCTLEX_InitChannel(DEMUX_CHANNEL_T *pInfo)
{
	return IOCTLEX_InitChannelImpl((int)(*pInfo));
}
int IOCTLEX_InitChannelImpl(int chIndex)
{
	int j;
	demux_channel *pCh;

	if (chIndex >= demux_device->chNum)
	{
		dmx_err("%s_%d, param is invalid(%d)\n", __func__, __LINE__, chIndex);
		return -1;
	}
	pCh = &demux_device->pChArray[chIndex];
	/* already initialized */
	if (pCh->isInit)
	{
		dmx_warn("%s_%d, demux_%d is already inited \n", __func__, __LINE__, pCh->tunerHandle);
		return 0;
	}
	pCh->tunerHandle = chIndex;
	/* the last tp always used to SDT */
	pCh->bIsSDT = ((pCh->tunerHandle >= (demux_device->chNum -1)) && demux_device->useSDT);
	pCh->avSyncMode = NAV_AVSYNC_PCR_MASTER;
	pCh->pbAvsyncMode = MTP_AVSYNC_MODE;
	pCh->lastStampedPTS = -1;
	pCh->CIKeySel  = -1;
	pCh->PCRPID    = -1;
	pCh->bUseDDRCopy   = DEMUX_USE_DDR_COPY;
	pCh->dataThreshold = TUNER_DATA_READ_THRESHOLD;
	pCh->videoFreeRunThreshold = DEFAULT_FREE_RUN_VIDEO_THRESHOLD;
	pCh->tsPacketSize  = 188;
	pCh->avSyncStartupFullness = 0;
	pCh->avSyncStartupPTS = 0;
	pCh->bPendingOnFullness = false;
	pCh->bPendingOnPTSCheck = false;
	pCh->bCheckAFState = false;
	pCh->bPcrTrackEnable = 1;
	pCh->audioType = AUDIO_UNKNOWN_TYPE;
	pCh->pvrSpeed = 256;
	pCh->AdChannelTarget = -1;
	pCh->pTPRelase = 0;
	pCh->TPReleaseSize = 0;
	pCh->status = 0;
	pCh->events = 0;
	pCh->bUpdateDemuxTarget = 0;
	pCh->mtpUploadUnitSize = 0;
	pCh->audio_newformat_info.Audio.audioPid = -1;
	pCh->audio_newformat_info.Audio.IsSendNewFormat = false;
	pCh->audio_newformat_info.Audio_2ND.audioPid = -1;
	pCh->audio_newformat_info.Audio_2ND.IsSendNewFormat = false;
	for (j = 0; j < DEMUX_NUM_OF_TARGETS; j++) {
		pCh->activeTarget[j].bNewTarget = false;
		pCh->activeTarget[j].pid        = -1;
		pCh->demuxTargetInfo[j].pinIndex = j; /* CHECK IT LATER !*/
		pCh->demuxTargetInfo[j].contiCounter = -1;
		pCh->demuxTargetInfo[j].bCheckContiCounter = (j<=DEMUX_TARGET_AUDIO_2ND)?1:0;
		pCh->demuxTargetInfo[j].PesHeaderParseInfo.pts = -1;
		pCh->demuxTargetInfo[j].PesHeaderParseInfo.bufferedBytes = 0;
		pCh->demuxTargetInfo[j].PesHeaderParseInfo.remainingHeaderBytes = 0;
		pCh->demuxTargetInfo[j].bResyncStartUnit = true;
		pCh->demuxTargetInfo[j].bKeepPES = (j == DEMUX_TARGET_TELETEXT || j == DEMUX_TARGET_ISDB_CC || j == DEMUX_TARGET_ISDB_CC_SUPERIMPOSE);
#ifndef DONTFIXBUG13648
		pCh->demuxTargetInfo[i].bResyncPTS = true;
#endif
	}
	for (j = 0; j < MAX_PID_FILTER_CB_NUM; j++) {
		pCh->activePESTarget[j].bNewTarget = false;
		pCh->activePESTarget[j].pid        = -1;
	}

	memset(&pCh->demuxIn, 0, sizeof(pCh->demuxIn));
	memset(&pCh->demuxOut, 0, sizeof(pCh->demuxOut));
	memset(&pCh->demuxInReserved, 0, sizeof(pCh->demuxInReserved));
	memset(&pCh->demuxOutReserved, 0, sizeof(pCh->demuxOutReserved));
	memset(pCh->demuxTargetTable, DEMUX_TARGET_DROP, sizeof(pCh->demuxTargetTable));
	memset(pCh->demuxTargetTableCB, DEMUX_TARGET_DROP, sizeof(pCh->demuxTargetTableCB));
	memset(&pCh->mtpBuffer, 0, sizeof(pCh->mtpBuffer));
	memset(&pCh->adInfo, 0, sizeof(pCh->adInfo));
	mutex_init(&pCh->mutex);
	mutex_init(&pCh->section_mutex);
	init_waitqueue_head(&pCh->bufStatusWQ);
	BufferFullDroppingReset(pCh, 0, 1);

	if (DEMUX_BUF_AllocTPBuffer(pCh) < 0){
		dmx_err("%s_%d: ch:%d FAIL DEMUX_BUF_AllocTPBuffer!!!!!\n", __func__, __LINE__, pCh->tunerHandle);
		goto init_channel_fail;
	}
	
	/* hw tp */
	RHAL_TPInit(pCh->tunerHandle);
	if (DEMUX_BUF_ConfigTPBuffer(pCh) <  0)
	{
		dmx_err("%s_%d: ch:%d FAIL DEMUX_BUF_ConfigTPBuffer!!!!!\n", __func__, __LINE__, pCh->tunerHandle);
		goto init_channel_fail;
	}
	/* alloc ringbuffer header from bufPoll for each section index */
	for (j = 0 ; j < MAX_SECTION_FILTER_NUM ; j++) {
		if (pCh->secListCB[j].rbHeader.virAddrFromPoll) {
			DEMUX_BUF_RestoreFromPoll(&pCh->secListCB[j].rbHeader);
		} else {
			if (DEMUX_BUF_AllocFromPoll(&pCh->secListCB[j].rbHeader, sizeof(RINGBUFFER_HEADER), &demux_device->bufPoll, 0) < 0)
				goto init_channel_fail;
		}
	}

	/* pcr recovery */
#ifdef CONFIG_RTK_KDRV_MULTI_TP_CLOCK
	if (pCh->tunerHandle < DEMUX_PCRTRACKING_MANAGER_NUM)
		pCh->pPcrRecoveryManager = &demux_device->pcrTrkManager[pCh->tunerHandle];
	else
		pCh->pPcrRecoveryManager = NULL;
#else
	pCh->pPcrRecoveryManager = &demux_device->pcrTrkManager[0];
#endif

	if (DEMUX_GetReferenceClock(pCh) != 0)
		IOCTLEX_ResetRefClock(pCh);

	pCh->state = DEMUX_STATE_STOP;
	pCh->isInit = 1;
	return 0;

init_channel_fail:
	IOCTLEX_UninitChannelImpl(pCh);
	return -1;
}
void IOCTLEX_ResetRefClock(demux_channel *pCh)
{
	REFCLOCK *pRefClock = DEMUX_GetReferenceClock(pCh);

	/* refclock */
	REFCLK_Reset(pRefClock, pCh->avSyncMode, pCh->videoFreeRunThreshold);
	REFCLK_SetClockMode(pRefClock, MISC_90KHz);

	/* av sync */
	PCRSYNC_Reset(&pCh->pcrProcesser, pRefClock, pCh->tunerHandle, pCh->pPcrRecoveryManager);
}
int IOCTLEX_UninitChannel(DEMUX_CHANNEL_T *pInfo)
{
	demux_channel *pCh;

	if (*pInfo >= demux_device->chNum)
		return -1;

	pCh = &demux_device->pChArray[*pInfo];
	return IOCTLEX_UninitChannelImpl(pCh);
}
int IOCTLEX_UninitChannelImpl(demux_channel *pCh)
{
	int i;

	pCh->state = DEMUX_STATE_STOP;
	dmx_notice("[%s %d] thread_task=[%p]\n", __func__, __LINE__, pCh->thread_task);
	if(pCh->thread_task){
		int ret = kthread_stop(pCh->thread_task);
		dmx_notice("[%s %d] ret = %d\n", __func__, __LINE__, ret);
	}
	pCh->thread_task = 0;

	/* hw tp */
	RHAL_TPStreamControl(pCh->tunerHandle, TP_STREAM_STOP);
	RHAL_SetTPRingBuffer(pCh->tunerHandle, 0, 0, 0);


	for (i = 0; i < MAX_SECTION_FILTER_NUM; i++) {
		if (pCh->secListCB[i].used) {
			RHAL_RemoveSectionFilter(pCh->tunerHandle, pCh->secListCB[i].handle);
			DEMUX_FreeSecIndex(pCh, i);
			dmx_mask_print(DEMUX_SECTION_DEBUG, "%s_%d, cancleSectionfilter: ch:%d, secId:%d\n", __func__, __LINE__, pCh->tunerHandle, i);
		}
		if (pCh->secListCB[i].rbHeader.fromPoll == 1) {
			if (pCh->secListCB[i].rbHeader.phyAddrFromPoll == 0 && pCh->secListCB[i].rbHeader.phyAddr) {
				pCh->secListCB[i].rbHeader.phyAddrFromPoll = pCh->secListCB[i].rbHeader.phyAddr;
				pCh->secListCB[i].rbHeader.virAddrFromPoll = pCh->secListCB[i].rbHeader.virAddr;
			}
		}
		DEMUX_BUF_ZeroOutBuffer(&pCh->secListCB[i].rbHeader);
	}
	mutex_destroy(&pCh->mutex);
	mutex_destroy(&pCh->section_mutex);


#ifdef BUFFER_FROM_KERNEL_SPACE
	DEMUX_BUF_FreeBuffer(&pCh->pesFilterBuffer);
#endif
	if (pCh->refClockBuffer.fromPoll == 1) {
                if (pCh->bUseSelfBuf && pCh->refClockBuffer.phyAddrFromPoll == 0 && pCh->refClockBuffer.phyAddr) {
                        /* ownership is changed to AP */
                        pCh->refClockBuffer.virAddrFromPoll = pCh->refClockBuffer.virAddr;
                        pCh->refClockBuffer.phyAddrFromPoll = pCh->refClockBuffer.phyAddr;
                }
        }
	DEMUX_BUF_ReturnRefClockBuffer(pCh);


	for (i = VIDEO_PIN; i < NUMBER_OF_PINS; i++)
	{
		DEMUX_BUF_PIN_T *pPinInfo   = &pCh->pinInfo[i].bufInfo[DEMUX_STREAM_TYPE_BS];
		DEMUX_BUF_PIN_T *pPinIBInfo = &pCh->pinInfo[i].bufInfo[DEMUX_STREAM_TYPE_IB];
		DEMUX_BUF_ReturnDecBuffer(pCh, i);
		memset(pPinIBInfo, 0, sizeof(DEMUX_BUF_PIN_T));
		memset(pPinInfo, 0, sizeof(DEMUX_BUF_PIN_T));
	}

	for(i=0; i<MAX_PID_FILTER_CB_NUM; i++)
		DEMUX_BUF_FreeBuffer(&pCh->pesMap[i].pesFilterBuffer);

	if (pCh->tpInfoBufferH.fromPoll == 1) {
		if (pCh->tpInfoBufferH.phyAddrFromPoll == 0 && pCh->tpInfoBufferH.phyAddr) {
			pCh->tpInfoBufferH.phyAddrFromPoll = pCh->tpInfoBufferH.phyAddr;
			pCh->tpInfoBufferH.virAddrFromPoll = pCh->tpInfoBufferH.virAddr;
		}
	}
	DEMUX_BUF_ZeroOutBuffer(&pCh->tpInfoBufferH);

	if (DEMUX_BUF_MTPBuffer_Destroy(pCh) < 0)
	{
		dmx_err("%s_%d: FAIL DEMUX_BUF_MTPBuffer_Destroy\n!!!", __func__, __LINE__);
	}
	DEMUX_BUF_FreeBuffer(&pCh->tpInfoBuffer);
	DEMUX_BUF_FreeBuffer(&pCh->GIFOBuf);
	DEMUX_BUF_ReturnPSIBuffer(pCh);

	if (DEMUX_BUF_FreeTPBuffer(pCh) < 0)
	{
		dmx_err("%s_%d: FAIL DEMUX_BUF_FreeTPBuffer\n!!!", __func__, __LINE__);
	}
	
#ifdef CONFIG_RTK_KDRV_MULTI_TP_CLOCK
	if (pCh->pPcrRecoveryManager)
		PCRTRACK_Release(pCh->pPcrRecoveryManager);
#endif
	pCh->isInit = 0;
	return 0;
}
int IOCTLEX_StartDemux(DEMUX_CHANNEL_T *pInfo)
{
	demux_channel *pCh;
	char pstr[10] = {0};

	if (*pInfo >= demux_device->chNum)
	{
		dmx_err("%s_%d, param is invalid(%d)\n", __func__, __LINE__, *pInfo);
		return -1;
	}
	pCh = &demux_device->pChArray[*pInfo];
	if (pCh->isInit != 1)
	{
		dmx_err("%s_%d, demux_%d is not init yet\n", __func__, __LINE__, pCh->tunerHandle);
		return -1;
	}
	if (pCh->state == DEMUX_STATE_RUNNING)
	{
		dmx_warn("%s_%d: demux_%d is already Running\n", __func__, __LINE__, pCh->tunerHandle);
		return 0;
	}

	if (pCh->bUseSelfBuf && pCh->refClockBuffer.phyAddr == 0)
		DEMUX_BUF_PrepareSelfRefClockBuf(pCh);

	if (pCh->pPcrRecoveryManager)
		PCRTRACK_Initialize(pCh->pPcrRecoveryManager, pCh->tunerHandle);
	snprintf(pstr, 9, "DEMUX_%d", pCh->tunerHandle);
	pCh->thread_task = kthread_create(DEMUX_ThreadProcEntry, (void *)pCh, pstr);
	if (!(pCh->thread_task) || IS_ERR(pCh->thread_task)) {
		pCh->thread_task = 0;
		return -1;
	}

	pCh->state = DEMUX_STATE_RUNNING;
	wake_up_process(pCh->thread_task);


	return 0;
}
int IOCTLEX_StopDemux(DEMUX_CHANNEL_T *pInfo)
{
	demux_channel *pCh;

	if (*pInfo >= demux_device->chNum)
	{
		dmx_err("%s_%d, param is invalid (%d)\n", __func__, __LINE__, *pInfo);
		return -1;
	}
	pCh = &demux_device->pChArray[*pInfo];
	if (pCh->isInit != 1)
	{
		dmx_err("%s_%d, demux_%d is not init yet\n", __func__, __LINE__, pCh->tunerHandle);
		return -1;
	}
	if (pCh->state == DEMUX_STATE_STOP)
	{
		dmx_warn("%s_%d, demux_%d is already Stop\n", __func__, __LINE__, pCh->tunerHandle);
		return 0;
	}
	dmx_notice("[%s %d] thread_task=[%p]\n", __func__, __LINE__, pCh->thread_task);
	if(pCh->thread_task){
		int ret = kthread_stop(pCh->thread_task);
		dmx_notice("[%s %d] ret = %d\n", __func__, __LINE__, ret);
	}
	pCh->thread_task = 0;
	pCh->state = DEMUX_STATE_STOP;
	pCh->startStreaming = 0;

	if(pCh->pPcrRecoveryManager != 0)
		PCRTRACK_Stop(pCh->pPcrRecoveryManager);

	RHAL_TPStreamControl(pCh->tunerHandle, TP_STREAM_STOP);
	return 0;
}

int IOCTLEX_SetBuffer(DEMUX_BUF_INFO_T *pInfo)
{
	demux_channel *pCh;

	if (pInfo->ch >= demux_device->chNum)
		return -1;

	pCh = &demux_device->pChArray[pInfo->ch];

	if (pInfo->dest == DEMUX_DEST_PSI)
		return DEMUX_BUF_SetupPSIBuffer(pCh, pInfo->bsPhyAddr, pInfo->bsHeaderSize);
	else if (pInfo->dest == DEMUX_DEST_STC0 || pInfo->dest == DEMUX_DEST_STC1)
		return DEMUX_BUF_SetupRefClockBuf(pCh, pInfo->refClockPhyAddr, pInfo->refClockHeaderSize);
	else {
		int ret, pin;

		pin = IOCTLEX_PESDestToPin(pInfo->dest);
		if (pin >= NUMBER_OF_PINS || pCh->bUseSelfBuf) {
			dmx_crit("[%s %d] fail to set buffer because pin = %d, buf owner is %s\n", __func__, __LINE__, pin, pCh->bUseSelfBuf ? "KERNEL" : "APP");
			return -1;
		}

		ret = DEMUX_BUF_SetupDecBuffer(pCh, pin, pInfo->bsPhyAddr, pInfo->bsHeaderSize, pInfo->ibPhyAddr, pInfo->ibHeaderSize);
		if (ret < 0)
			return ret;

	}

	return 0;
}
int IOCTLEX_ReleaseBuffer(DEMUX_BUF_INFO_T *pInfo)
{
	demux_channel *pCh;
	int pin = NUMBER_OF_PINS;

	if (pInfo->ch >= demux_device->chNum)
		return -1;

	dmx_info("func %s, line %d, ch %d\n", __func__, __LINE__, pInfo->ch);

	pCh = &demux_device->pChArray[pInfo->ch];
	if(pCh->isInit == 0)
		return -1;

	if (pInfo->dest == DEMUX_DEST_PSI) {
		if (pCh->state != DEMUX_STATE_STOP) {
			dmx_crit("[%s %d] demux thread is not stop!\n", __func__, __LINE__);
			return -1;
		}
		return DEMUX_BUF_ReturnPSIBuffer(pCh);
	} else if (pInfo->dest == DEMUX_DEST_STC0 || pInfo->dest == DEMUX_DEST_STC1) {
		if (pCh->bUseSelfBuf)
			return 0;
		if (pCh->state != DEMUX_STATE_STOP) {
			dmx_crit("[%s %d] demux thread is not stop!\n", __func__, __LINE__);
			return -1;
		}
		return DEMUX_BUF_ReturnRefClockBuffer(pCh);
	} else {
		pin = IOCTLEX_PESDestToPin(pInfo->dest);
		if (pin >= NUMBER_OF_PINS)
			return -1;

		mutex_lock(&pCh->mutex);

		pCh->pinInfo[pin].bufStatus = BUF_STAT_FREE;
		if (pCh->state == DEMUX_STATE_STOP)
			DEMUX_BUF_UpdatePinInfo(pCh);
		else
			SET_FLAG(pCh->events, EVENT_SET_PIN_INFO);

		dmx_crit("[%s %d]CH%d pin = %d\n", __func__, __LINE__, pInfo->ch, pin);
		mutex_unlock(&pCh->mutex);

		if (wait_event_timeout(pCh->bufStatusWQ, (pCh->pinInfo[pin].bufStatus == BUF_STAT_DONE), WAIT_TO_BE_DONE_TIMEOUT) == 0) {
			/* timeout occurs and condition is false */
			dmx_crit("[%s %d] timeout to free buffer. bufStatus = %d\n", __func__, __LINE__, pCh->pinInfo[pin].bufStatus);
			return -1;
		}
	}


	return 0;
}
int IOCTLEX_SetBufOwner(DEMUX_BUF_OWNER_T *pInfo)
{
	demux_channel *pCh;
	const unsigned char bUseSelfBuf = pInfo->ownership == KERNEL_DRIVER;
	int i;

	if (pInfo->ch >= demux_device->chNum)
		return -1;

	pCh = &demux_device->pChArray[pInfo->ch];
	if (bUseSelfBuf == pCh->bUseSelfBuf)
		return 0;

	if (pCh->state != DEMUX_STATE_STOP) {
		dmx_crit("[%s %d] demux is not stop!\n", __func__, __LINE__);
		return -1;
	}

	if (pCh->refClockBuffer.fromPoll == 1) {
		if (pCh->bUseSelfBuf && pCh->refClockBuffer.phyAddrFromPoll == 0 && pCh->refClockBuffer.phyAddr) {
			/* ownership is changed to AP */
			pCh->refClockBuffer.virAddrFromPoll = pCh->refClockBuffer.virAddr;
			pCh->refClockBuffer.phyAddrFromPoll = pCh->refClockBuffer.phyAddr;
		}
	}
	DEMUX_BUF_ReturnRefClockBuffer(pCh);
	for (i = VIDEO_PIN; i < NUMBER_OF_PINS; i++) {
		if (pCh->bUseSelfBuf && pCh->bsDecBufH[i].phyAddrFromPoll == 0 && pCh->bsDecBufH[i].phyAddr) {
			pCh->bsDecBufH[i].phyAddrFromPoll = pCh->bsDecBufH[i].phyAddr;
			pCh->bsDecBufH[i].virAddrFromPoll = pCh->bsDecBufH[i].virAddr;

			pCh->ibDecBufH[i].phyAddrFromPoll = pCh->ibDecBufH[i].phyAddr;
			pCh->ibDecBufH[i].virAddrFromPoll = pCh->ibDecBufH[i].virAddr;
		}
		pCh->pinInfo[i].bufStatus = BUF_STAT_FREE;
		DEMUX_BUF_UpdatePinInfo(pCh);
	}
	pCh->bUseSelfBuf = bUseSelfBuf;
	return 0;
}
int IOCTLEX_FreeApvrBuffer(void)
{
	dmx_function_call();

	DEMUX_BUF_FreeBuffer(&demux_device->APvrTsBuf);

	return 0;
}

int IOCTLEX_FreeGIFOBuffer(DEMUX_CHANNEL_T *ch)
{
	dmx_function_call();
	DEMUX_CHECK_CH(*ch);

	DEMUX_BUF_FreeBuffer(&demux_device->pChArray[*ch].GIFOBuf);
	return 0;
}

int IOCTLEX_SetPbStreamSource(DEMUX_SET_PB_STREAM_SRC_T *pInfo)
{
	demux_channel *pCh;

	dmx_function_call();
	DEMUX_CHECK_CH(pInfo->ch);
	pCh = &demux_device->pChArray[pInfo->ch];
	if (DEMUX_checkFilterCount(pCh) > 0) {
		dmx_err("Set Playback AVSync Mode Fail.\n");
		return -1;
	}

	mutex_lock(&pCh->mutex);
	if (pInfo->src == DEMUX_PB_SRC_STREAMING)
		pCh->pbAvsyncMode = NAV_AVSYNC_AUDIO_MASTER_AF;
	else if (pInfo->src == DEMUX_PB_SRC_LOCAL_STORAGE)
		pCh->pbAvsyncMode = MTP_AVSYNC_MODE;
	DEMUX_ResetAVSync(pCh, pCh->pbAvsyncMode);
	mutex_unlock(&pCh->mutex);

	return 0;
}

int IOCTLEX_GetPcr(DEMUX_PCR_T *pInfo)
{
	int64_t ret;
	int64_t pcrExt, stcExt;
	demux_channel *pCh;
	DEMUX_CHECK_CH(pInfo->ch);
	pCh = &demux_device->pChArray[pInfo->ch];

	ret = RHAL_GetPCRTrackingStatus(pCh->pcrProcesser.tunerHandle, &pInfo->pcr, &pInfo->stc, &pcrExt, &stcExt);
	if (ret != TPK_SUCCESS)
		return -1;

	return 0;

}

long IOCTLEX_Handle(struct file *filp, unsigned int cmd, unsigned long arg)
{
	int ret = -ENOTTY;

	if (cmd == DEMUX_IOC_SET_BUF_OWNER || cmd == DEMUX_IOC_SET_BUF_OWNER_COMPAT) {
		DEMUX_BUF_OWNER_T data;

		if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(DEMUX_BUF_OWNER_T)))
			ret = -EFAULT;
		else
			ret = IOCTLEX_SetBufOwner(&data);
	} else if (cmd == DEMUX_IOC_SET_BUF || cmd == DEMUX_IOC_SET_BUF_COMPAT) {
		DEMUX_BUF_INFO_T data;

		if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(DEMUX_BUF_INFO_T)))
			ret = -EFAULT;
		else
			ret = IOCTLEX_SetBuffer(&data);
	} else if (cmd == DEMUX_IOC_RELEASE_BUF || cmd == DEMUX_IOC_RELEASE_BUF_COMPAT) {
		DEMUX_BUF_INFO_T data;

		if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(DEMUX_BUF_INFO_T)))
			ret = -EFAULT;
		else
			ret = IOCTLEX_ReleaseBuffer(&data);
	} else if (cmd == DEMUX_IOC_START_DEMUX || cmd == DEMUX_IOC_START_DEMUX_COMPAT) {
		DEMUX_CHANNEL_T data;

		if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(DEMUX_CHANNEL_T)))
			ret = -EFAULT;
		else
			ret = IOCTLEX_StartDemux(&data);
	} else if (cmd == DEMUX_IOC_STOP_DEMUX || cmd == DEMUX_IOC_STOP_DEMUX_COMPAT) {
		DEMUX_CHANNEL_T data;

		if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(DEMUX_CHANNEL_T)))
			ret = -EFAULT;
		else
			ret = IOCTLEX_StopDemux(&data);
	} else if (cmd == DEMUX_IOC_INIT_CHANNEL || cmd == DEMUX_IOC_INIT_CHANNEL_COMPAT) {
		DEMUX_CHANNEL_T data;

		if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(DEMUX_CHANNEL_T)))
			ret = -EFAULT;
		else
			ret = IOCTLEX_InitChannel(&data);
	} else if (cmd == DEMUX_IOC_UNINIT_CHANNEL || cmd == DEMUX_IOC_UNINIT_CHANNEL_COMPAT) {
		DEMUX_CHANNEL_T data;

		if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(DEMUX_CHANNEL_T)))
			ret = -EFAULT;
		else
			ret = IOCTLEX_UninitChannel(&data);
	} else if (cmd == DEMUX_IOC_FREE_APVR || cmd == DEMUX_IOC_FREE_APVR_COMPAT) {
		ret = IOCTLEX_FreeApvrBuffer();
	} else if (cmd == DEMUX_IOC_FREE_GIFO || cmd == DEMUX_IOC_FREE_GIFO_COMPAT) {
		DEMUX_CHANNEL_T data;

		if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(DEMUX_CHANNEL_T)))
			ret = -EFAULT;
		else
			ret = IOCTLEX_FreeGIFOBuffer(&data);
	} else if (cmd == DEMUX_IOC_ACQUIRE_CH || cmd == DEMUX_IOC_ACQUIRE_CH_COMPAT) {
		DEMUX_CH_ACQUIRE_T data;

		if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(DEMUX_CH_ACQUIRE_T))
			||  CHMGR_AcquireChannel(&data) < 0
			||  copy_to_user((void __user *)arg, (void *)&data, sizeof(DEMUX_CH_ACQUIRE_T))) {
			ret = -EFAULT;
			dmx_err("ioctl DEMUX_IOC_ACQUIRE_CH failed !!!!!!!!!!!!!!!\n");
		} else {
			filp->private_data =  (void*)((int)(filp->private_data) | (1 << data.chIndex));
			dmx_err("%s_%d: %p :%d\n",__func__, __LINE__, filp->private_data, data.chIndex);
			ret = 0;
		}
	} else if (cmd == DEMUX_IOC_RELEASE_CH || cmd == DEMUX_IOC_RELEASE_CH_COMPAT) {
		int data;

		if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(int))) {
			ret = -EFAULT;
		} else {
			ret = CHMGR_ReleaseChannel(data);
			filp->private_data = (void*)((int)(filp->private_data) & (~(1 << data)));
			dmx_err("%s_%d: %p :%d\n",__func__, __LINE__, filp->private_data, data);
		}
	} else if (cmd == DEMUX_IOC_SET_PB_STREAM_SOURCE) {
		DEMUX_SET_PB_STREAM_SRC_T data;

		if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(DEMUX_SET_PB_STREAM_SRC_T)))
			ret = -EFAULT;
		else
			ret = IOCTLEX_SetPbStreamSource(&data);
	} else if (cmd == DEMUX_IOC_GET_PCR) {
		DEMUX_PCR_T data;
		ret = 0;
		if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(DEMUX_PCR_T))
		|| IOCTLEX_GetPcr(&data) < 0
		|| copy_to_user((void __user *)arg, (void *)&data, sizeof(DEMUX_PCR_T))) {
			ret = -EFAULT;
			dmx_err("ioctl IOCTLEX_GetPcr failed !!!!!!!!!!!!!!!\n");
		}
	} else {
		dmx_warn("RTKDEMUX: unknown ioctl(0x%08x)\n", cmd);
	}

	return ret;
}
