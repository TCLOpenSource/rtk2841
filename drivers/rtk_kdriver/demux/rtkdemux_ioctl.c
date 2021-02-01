/****************************************************************************
 *
 *   Realtek Demux driver
 *
 *   Copyright(c) 2014 Realtek Semiconductor Corp. All rights reserved.
 *
 *   @author bonds.lu@realtek.com
 *
 *****************************************************************************/
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
#include "rtkdemux_pvr.h"
#include "rtkdemux_clock.h"
#include "rtkdemux_export.h"
#include "rtkdemux_debug.h"
#include "rtkdemux_refclk.h"
#include "rtkdemux_register.h"
#include "rtkdemux_pcrsync.h"
#include "rtkdemux_pcrtracking.h"
#include "rtkdemux_rec.h"
#include "rtkdemux_buf.h"
#include "rtkdemux_MW.h"
#include "rtkdemux_specialhandling.h"
#include <rtk_kdriver/RPCDriver.h>   /* register_kernel_rpc, send_rpc_command */
#include <rtk_kdriver/rpc/VideoRPC_System.h>

#include <tp/tp_drv_global.h>
#define MTP_BUFFER_SIZE (6*1024*1024)
#define MIN_UPLOAD_SIZE_FOR_192 (192*1024)
#define TP_INFO_BUFFER_SIZE (1024*1024)

#define USE_STATIC_RESERVED_BUF
#ifdef USE_STATIC_RESERVED_BUF
#include <mach/rtk_platform.h>
#endif

#define DEMUX_CHECK_CH(x)  \
{\
	if (!demux_device->pChArray || x >= demux_device->chNum || !demux_device->pChArray[x].isInit) { \
		dmx_warn("func %s, line %d, Error(isInit %d, ch %d, chNum %d)!!\n", __func__, __LINE__, (demux_device->pChArray != 0), x, demux_device->chNum); \
		return -ENOTTY; \
	} \
}
#define DEMUX_CHECK_PID(x)  \
{\
	if (x > 0x1fff) { \
		dmx_warn("func %s, line %d, Error(pid : 0x%x)!!\n", __func__, __LINE__, x); \
		return -ENOTTY; \
	} \
}
#define DEMUX_GET_MTP_ID(_ch) (((_ch) == DEMUX_CH_A) ? 0 : (((_ch) == DEMUX_CH_B) ? 1 : 2))

static bool _bcase_print_key_info = false;
int IOCTL_ReConfigTPBuffer(DEMUX_CHANNEL_T ch);
void IOCTL_FreeTPBuffer(int chNum);
int IOCTL_GetBufferInfoImpl(demux_channel *pCh, int pin, int numOfDec);

static INT32 TP_RequestSecBufferCB(void *pContext, UINT8 **ppBuf, UINT16 size)
{
	int ch, index, space, sz, idxR, idxW, ret = 0;
	unsigned int rd, wr ;
	static int64_t printTime = -1, printTime1= -1;
	demux_channel *pCh;
	DEMUX_SEC_LIST_T *pSec;
	UINT32 *pBuf ;
	if (size <= 0 || size > SEC_FILTER_BUFFER_EACH_SIZE) {
		dmx_err("%s, size(%d) is error!\n", __func__, size);
		return -1;
	}
	ch    = ((int)pContext) >> 8 ;
	index = ((int)pContext) & 0x3f ;  /* MAX_SECTION_FILTER_NUM(64) */

/*	dmx_info("%s called, line %d, ch %d, index %d\n", __func__, __LINE__, ch, index) ; */
	pCh   = &demux_device->pChArray[ch];
	pSec  = &pCh->secListCB[index];
	mutex_lock(&pCh->section_mutex);
	mutex_lock(&demux_device->mutex) ;
	sz   = (size + 3) & ~0x3 ;              /* align to 4 bytes */
	rd   = (*pSec->pRdPtr) & ~0x3 ;	        /* align to 4 bytes */
	wr   = (*pSec->pWrPtr + 3) & ~0x3 ;     /* align to 4 bytes */
	idxR = (rd - (unsigned int)demux_device->secFilterBuffer.phyAddr)/SEC_FILTER_BUFFER_UNIT_SIZE;
	idxW = (wr - (unsigned int)demux_device->secFilterBuffer.phyAddr)/SEC_FILTER_BUFFER_UNIT_SIZE;
/*	dmx_info("%s called, line %d, idxR %d, idxW %d, rd 0x%x, wr 0x%x\n", __func__, __LINE__, idxR, idxW, rd, wr) ; */
	if (rd > wr && idxR == idxW) {
		space = rd - wr;
		if (space >= (8+sz)) { /* done */
			pBuf = (UINT32 *)(wr - pSec->phyAddrOffset);
		} else {
			if(printTime == -1)
				printTime = CLOCK_GetPTS();
			else {
				if(CLOCK_GetPTS() - printTime > 3*DEMUX_CLOCKS_PER_SEC) {
					dmx_err(
						"%s(%d), sectionBuffer Full(ch:%d, secIndex: %d, pid:0x%x, rd:0x%x, wp: 0x%x, lowp:0x%lx, upper:0x%lx,size %d) !!\n",
						__func__, __LINE__, ch, index, pSec->param.PID, rd, wr,
						(unsigned long)(uintptr_t)pSec->pBufferLower,
						(unsigned long)(uintptr_t)pSec->pBufferUpper,
						size
					);
					printTime = CLOCK_GetPTS();
				}
			}
			ret = -1;
		}
	} else { /*wr >= rd */
		space = SEC_FILTER_BUFFER_UNIT_SIZE - ((wr - (unsigned int)pSec->pBufferLower)%SEC_FILTER_BUFFER_UNIT_SIZE);
		if (space < (8+sz)) { /* search next unit */
			if (demux_device->secMap[idxW].nextBufIndex != idxR) { /* done */
				if ((idxW + 1) == demux_device->secMap[idxW].nextBufIndex) { /* continuous buffer */
					pBuf = (UINT32 *)(wr - pSec->phyAddrOffset);
				} else { /* discontinuous buffer, move to next index */
					pBuf = (UINT32 *)(wr - pSec->phyAddrOffset);
					/* set (idx to store, size is 0) to indicate the position to AP */
					*pBuf = ((demux_device->secMap[idxW].nextBufIndex << 16) | 0) ;

					idxW = demux_device->secMap[idxW].nextBufIndex;
					pBuf = (UINT32 *)demux_device->secMap[idxW].virAddr;
					/* dmx_info("%s called, line %d, idxW %d, pBuf 0x%x\n", __func__, __LINE__, idxW, pBuf) ;*/
				}
			} else { /* check the space in idxR */
				space = (rd - (unsigned int)pSec->pBufferLower)%SEC_FILTER_BUFFER_UNIT_SIZE;
				if (space >= (8+sz)) { /* get buffer from idxR */
					pBuf = (UINT32 *)(wr - pSec->phyAddrOffset);
					/* set (idx to store, size is 0) to indicate the position to AP */
					*pBuf = ((idxR << 16) | 0) ;
					idxW = idxR;
					pBuf = (UINT32 *)demux_device->secMap[idxW].virAddr;
				} else {
					if(printTime1 == -1)
						printTime1 = CLOCK_GetPTS();
					else {
						if(CLOCK_GetPTS() - printTime1 > 3*DEMUX_CLOCKS_PER_SEC) {
							dmx_err("%s(%d), sectionBuffer Full(ch:%d, secIndex: %d, pid:0x%x, rd:0x%x, wp: 0x%x, lowp:0x%lx, upper:0x%lx,size %d) !!\n",
								__func__, __LINE__, ch, index, pSec->param.PID, rd, wr,
								(unsigned long)(uintptr_t)pSec->pBufferLower,
								(unsigned long)(uintptr_t)pSec->pBufferUpper,
								size
							);
							printTime1 = CLOCK_GetPTS();
						}
					}
					ret = -1;
				}
			}
		} else { /* done, get buffer from idxW */
			pBuf = (UINT32 *)(wr - pSec->phyAddrOffset);
		}
	}
	if (ret >= 0) {
		*pBuf++ = ((idxW << 16) | size) ;
		*ppBuf  = (UINT8 *) pBuf;
		/*dmx_info("%s called, line %d, idxW %d, size %d, pBuf 0x%x\n", __func__, __LINE__, idxW, size, pBuf) ;*/
	}
	mutex_unlock(&demux_device->mutex);
	mutex_unlock(&pCh->section_mutex);
	/*dmx_info("%s called, ret %d, pBuf 0x%x, base 0x%x\n", __func__, ret, pBuf, demux_device->secFilterBuffer.virAddr) ;*/
	return ret;
}

static int TP_CheckSum (unsigned int *pData, int size)
{
	int ret = 0;
	if ((size & 3))
		return -1;
	else {
	const unsigned * const pEnd = pData + (size >> 2);
	for (; pData < pEnd; pData++)
		ret ^= (*pData);
	}
	return ret;
}
static void TP_SecComplete (void *pContext, TPK_SEC_DATA_T *pSecData)
{
	DEMUX_CHANNEL_T ch = (DEMUX_CHANNEL_T)(((int)pContext) >> 8);
	demux_channel *pCh = &demux_device->pChArray[ch];
	int index = ((int)pContext) & 0x3f ;  /* MAX_SECTION_FILTER_NUM(64) */
	DEMUX_SEC_LIST_T *pSec = &pCh->secListCB[index];

	mutex_lock(&pCh->section_mutex);
	mutex_lock(&demux_device->mutex);

	if (pSec->checksum && TP_CheckSum((unsigned int *)pSecData->p_data, pSecData->len) != 0) {
		dmx_err(
			"[%s %d] section buffer checksum fail(pContext = 0x%lx)!!\n",
			__func__, __LINE__, (unsigned long)(uintptr_t)pContext
		);
		mutex_unlock(&demux_device->mutex);
	mutex_unlock(&pCh->section_mutex);
		return;
	}
/* TODO, for debug
	{
		unsigned int size;
		UINT32 *pBuf = (UINT32 *)pSecData->p_data ;
		pBuf-- ;
		size = (*pBuf) & 0xffff ;
		if (size != pSecData->len) {
			dmx_err("[%s %d] something wrong(pContext = 0x%x), pSecData->len(%d) != size(%d)!!\n", __func__, __LINE__, pContext, pSecData->len, size);
		return;
		}
	}
*/
        /*dmx_info("%s called, line %d, ch %d, index %d, pData 0x%x, len %d\n", __func__, __LINE__, ch, index, pSecData->p_data, pSecData->len) ;*/
	/* update write pointer */
	*pSec->pWrPtr = ((int)pSecData->p_data + pSec->phyAddrOffset + pSecData->len + 3) & ~0x3 ;
	/*dmx_info("%s called, line %d, wrPtr = 0x%x\n", __func__, __LINE__, *pSec->pWrPtr) ;*/
	demux_device->filter_flag = 1;
	DEMUX_wakeUpPoll();
	mutex_unlock(&demux_device->mutex);
	mutex_unlock(&pCh->section_mutex);
}

static void IOCTL_ShutDownModule(void)
{
	int i, j, k;

	if (demux_device->pChArray) {
		for (i = 0; i < demux_device->chNum; i++) {
			demux_channel *pCh = &demux_device->pChArray[i];
			if (pCh->state != DEMUX_STATE_STOP) {
				pCh->state = DEMUX_STATE_STOP;
				if (pCh->thread_task)
					kthread_stop(pCh->thread_task);
				pCh->thread_task = 0;
			}

			if (pCh->isInit) {

				/* hw tp */
				RHAL_TPStreamControl(pCh->tunerHandle, TP_STREAM_STOP);
				RHAL_TPUninit(pCh->tunerHandle);
				mutex_destroy(&pCh->mutex);
			}

			DEMUX_BUF_FreeBuffer(&pCh->refClockBuffer);
			IOCTL_FreeTPBuffer(i);
			DEMUX_BUF_FreeBuffer(&pCh->tpBufferH);
		#ifndef DEMUX_VIDEO_USE_PINGPONG_BUFFERS
			DEMUX_BUF_ReturnVideoBuffer(pCh, 0);
			DEMUX_BUF_ReturnVideoBuffer(pCh, 1);
		#endif
		#ifndef DEMUX_AUDIO_USE_GLOBAL_BUFFER
			for (j = 0; j < demux_device->numberOfAD; j++) {
				DEMUX_BUF_FreeBuffer(&pCh->bsAudioBuf[j]);
				DEMUX_BUF_FreeBuffer(&pCh->bsAudioBufH[j]);
				DEMUX_BUF_FreeBuffer(&pCh->ibAudioBuf[j]);
				DEMUX_BUF_FreeBuffer(&pCh->ibAudioBufH[j]);
			}
		#endif
		#ifndef DEMUX_PES_BUFFER_DYNAMIC_ALLOC
			DEMUX_BUF_FreeBuffer(&pCh->pesFilterBuffer);
		#else
			for(k=0; k<MAX_PID_FILTER_CB_NUM;k++){
				DEMUX_BUF_FreeBuffer(&pCh->pesMap[k].pesFilterBuffer);
			}
		#endif
			DEMUX_BUF_FreeBuffer(&pCh->mtpBuffer);
			DEMUX_BUF_FreeBuffer(&pCh->tpInfoBufferH);
			DEMUX_BUF_FreeBuffer(&pCh->tpInfoBuffer);
		}
	#ifdef DEMUX_VIDEO_USE_PINGPONG_BUFFERS
		for (j = 0; j < demux_device->numberOfVD; j++) {
			DEMUX_BUF_FreeBuffer(&demux_device->bsVideoBuf[j]);
			DEMUX_BUF_FreeBuffer(&demux_device->bsVideoBufH[j]);
			DEMUX_BUF_FreeBuffer(&demux_device->ibVideoBuf[j]);
			DEMUX_BUF_FreeBuffer(&demux_device->ibVideoBufH[j]);
		}
	#endif
	#if defined(DEMUX_AUDIO_USE_GLOBAL_BUFFER)
		for (j = 0; j < demux_device->numberOfAD; j++) {
			DEMUX_BUF_FreeBuffer(&demux_device->audioBuffer[j].bsBuffer);
			DEMUX_BUF_FreeBuffer(&demux_device->audioBuffer[j].ibBuffer);
		}
	#endif
		DEMUX_BUF_FreeBuffer(&demux_device->secFilterBuffer);
		DEMUX_BUF_FreeBuffer(&demux_device->bufPoll);
		mutex_destroy(&demux_device->mutex);
		kfree(demux_device->pChArray);
		demux_device->pChArray = NULL;
	}

}


void IOCTL_SetPinInfo(DEMUX_BUF_PIN_T *pPinInfo, RINGBUFFER_HEADER *pRBH, DEMUX_BUF_T *pBuf)
{

	pPinInfo->pWrPtr		= &pRBH->writePtr;
	pPinInfo->pRdPtr		= &pRBH->readPtr[0];
	pPinInfo->pBufferLower  = (unsigned char *)DEMUX_reverseInteger(pRBH->beginAddr);
	pPinInfo->pBufferUpper  = pPinInfo->pBufferLower + DEMUX_reverseInteger(pRBH->size);
	pPinInfo->phyAddrOffset = (long) pBuf->phyAddr - (long) pBuf->virAddr;
	pPinInfo->pRBH		  =  pRBH;
}

#ifdef DEMUX_VIDEO_USE_PINGPONG_BUFFERS
static int IOCTL_UpdateVideoPinInfo(demux_channel *pCh, DEMUX_PES_DEST_T dest, unsigned char bConnect)
{
	int pin, i;

	if (dest == DEMUX_DEST_VDEC0) pin = VIDEO_PIN;
	else if (dest == DEMUX_DEST_VDEC1) pin = VIDEO2_PIN;
	else return -1;

	pCh->tmpPinInfo[pin].pinInfoStatus = PININFO_FREE;
	if (!bConnect) {
		dmx_crit("[%s %d] CH%d remove video buffer %d\n", __func__, __LINE__, pCh->tunerHandle, pCh->tmpPinInfo[pin].bufIndex);
		return 0;
	}


	mutex_lock(&demux_device->mutex) ;

	/* To handle the case : remove buffer 0 and then select buffer 1 soon. */
	if (pCh->tmpPinInfo[pin].pinInfoStatus != PININFO_DONE) {
		if (pCh->tmpPinInfo[pin].bufIndex >= 0) {
			dmx_crit(
				"[%s %d]CH%d video buffer %d is released\n",
				__func__, __LINE__, pCh->tunerHandle,
				pCh->tmpPinInfo[pin].bufIndex
			);
			demux_device->bVideoBufUsed[pCh->tmpPinInfo[pin].bufIndex] = 0;
			pCh->tmpPinInfo[pin].bufIndex = -1;
		}
		pCh->tmpPinInfo[pin].pinInfoStatus = PININFO_DONE;
	}
	for(i = 0; i < MAX_VDEC_NUM; i++) {
		if (demux_device->bVideoBufUsed[i])
			continue;

		demux_device->bVideoBufUsed[i] = 1;
		pCh->tmpPinInfo[pin].bufIndex = i;
		pCh->tmpPinInfo[pin].pinInfoStatus = PININFO_NEW;

		if (IOCTL_GetBufferInfoImpl(pCh, pin, i) < 0)
			break; //to unlock mutex

		mutex_unlock(&demux_device->mutex);
		dmx_crit("[%s %d]CH%d select video buffer %d\n", __func__, __LINE__, pCh->tunerHandle, pCh->tmpPinInfo[pin].bufIndex);
		return 0;
	}
	mutex_unlock(&demux_device->mutex);
	dmx_crit("[%s %d]CH%d ERROR: No free video es buffer\n", __func__, __LINE__, pCh->tunerHandle);
	return -1;
}

#endif

// vidoe pingpang buffer ,/audio nomal buffer solution will use this function.
int IOCTL_GetBufferInfoImpl(demux_channel *pCh, int pin, int numOfDec)
{
	int bsSize, ibSize;
#if !defined(DEMUX_VIDEO_USE_PINGPONG_BUFFERS)
	DEMUX_BUF_PIN_T *pPinInfo, *pPinIBInfo;
#endif
	DEMUX_BUF_T *pBufBS, *pBufIB, *pBufBSH, *pBufIBH;
	dmx_crit("[%s %d] pin = %d, numOfDec = %d\n", __func__, __LINE__, pin, numOfDec);

	if (pin == VIDEO_PIN || pin == VIDEO2_PIN) {
		//pin	  = numOfDec ? VIDEO2_PIN : VIDEO_PIN;
		bsSize   = (rtkdemux_dbg_video_buffer_size > 0) ? rtkdemux_dbg_video_buffer_size : demux_device->sizeOfVideoBS;
		ibSize   = demux_device->sizeOfVideoIB;
	#ifdef DEMUX_VIDEO_USE_PINGPONG_BUFFERS
		pBufBS   = &demux_device->bsVideoBuf[numOfDec];
		pBufIB   = &demux_device->ibVideoBuf[numOfDec];
		pBufBSH  = &demux_device->bsVideoBufH[numOfDec];
		pBufIBH  = &demux_device->ibVideoBufH[numOfDec];
	#else
		pBufBS   = &pCh->bsVideoBuf[numOfDec];
		pBufIB   = &pCh->ibVideoBuf[numOfDec];
		pBufBSH  = &pCh->bsVideoBufH[numOfDec];
		pBufIBH  = &pCh->ibVideoBufH[numOfDec];
	#endif
	} else {
#ifdef DEMUX_AUDIO_USE_GLOBAL_BUFFER
		return 0;
#else
		//pin	  = numOfDec ? AUDIO2_PIN : AUDIO_PIN;
		bsSize   = (rtkdemux_dbg_audio_buffer_size > 0) ? rtkdemux_dbg_audio_buffer_size : demux_device->sizeOfAudioBS;
		ibSize   = demux_device->sizeOfAudioIB;
		pBufBS   = &pCh->bsAudioBuf[numOfDec];
		pBufIB   = &pCh->ibAudioBuf[numOfDec];
		pBufBSH  = &pCh->bsAudioBufH[numOfDec];
		pBufIBH  = &pCh->ibAudioBufH[numOfDec];
#endif
	}

	if (pBufBSH->virAddr == 0) {
		if (DEMUX_BUF_AllocFromPoll(pBufBSH, sizeof(RINGBUFFER_HEADER), &demux_device->bufPoll, 0) < 0) {
			dmx_crit("[%s %d]CH%d out of memory: allocate buffer header fail\n", __func__, __LINE__, pCh->tunerHandle);
			return -1;
		}
	}
	if (pBufIBH->virAddr == 0) {
		if (DEMUX_BUF_AllocFromPoll(pBufIBH, sizeof(RINGBUFFER_HEADER), &demux_device->bufPoll, 0) < 0) {
			dmx_crit("[%s %d]CH%d out of memory: allocate buffer header fail\n", __func__, __LINE__, pCh->tunerHandle);
			return -1;
		}
	}
	if ((pBufBS->virAddr == 0 && DEMUX_BUF_AllocBuffer(pBufBS, bsSize, 1, 1) < 0)
	|| (pBufIB->virAddr == 0 && DEMUX_BUF_AllocBuffer(pBufIB, ibSize, 0, 1) < 0)) {
		DEMUX_BUF_FreeBuffer(pBufBS);
		DEMUX_BUF_FreeBuffer(pBufIB);
		return -1;
	}

	DEMUX_BUF_ResetRBHeader(pBufIBH, pBufIB, RINGBUFFER_COMMAND, 1);
	DEMUX_BUF_ResetRBHeader(pBufBSH, pBufBS, RINGBUFFER_STREAM,  1);

#if !defined(DEMUX_VIDEO_USE_PINGPONG_BUFFERS)
	pPinInfo   = &pCh->pinInfo[pin].bufInfo[DEMUX_STREAM_TYPE_BS];
	pPinIBInfo = &pCh->pinInfo[pin].bufInfo[DEMUX_STREAM_TYPE_IB];

	IOCTL_SetPinInfo(pPinIBInfo, (RINGBUFFER_HEADER *)pBufIBH->virAddr, pBufIB);
	IOCTL_SetPinInfo(pPinInfo, (RINGBUFFER_HEADER *)pBufBSH->virAddr, pBufBS);

	dmx_notice(
		"(CH%d)isVideo(%d) BS PININFO[%d]: %lx,%x,%lx\n",
		pCh->tunerHandle, pin, numOfDec,
		(unsigned long)pPinInfo->phyAddrOffset,
		pBufBS->phyAddr,
		(unsigned long)(uintptr_t)pBufBS->virAddr
	);
	dmx_notice(
		"(CH%d)isVideo(%d) IB PININFO[%d]: %lx,%x,%lx\n",
		pCh->tunerHandle, pin, numOfDec,
		(unsigned long)pPinIBInfo->phyAddrOffset,
		pBufIB->phyAddr,
		(unsigned long)(uintptr_t)pBufIB->virAddr
	);
#endif
	return 0;
}
static void IOCTL_CheckAvSync(demux_channel *pCh)
{
	mutex_lock(&pCh->mutex);
	if (pCh->avSyncMode != MTP_AVSYNC_MODE && (pCh->tp_src == MTP)) {
		DEMUX_ResetAVSync(pCh, MTP_AVSYNC_MODE);
	} else if (pCh->avSyncMode != NAV_AVSYNC_PCR_MASTER && pCh->tp_src != MTP) {
		pCh->avSyncMode = NAV_AVSYNC_PCR_MASTER;
		REFCLK_SetMasterShip(DEMUX_GetReferenceClock(pCh), pCh->avSyncMode);
		REFCLK_SetTimeout(DEMUX_GetReferenceClock(pCh), 3*DEMUX_CLOCKS_PER_SEC);
	}

	mutex_unlock(&pCh->mutex);
}
int IOCTL_AllocateTPBuffer(int chNum, int size)
{
	demux_channel *pCh = &demux_device->pChArray[chNum];
	DEMUX_BUF_T *pBuf = &pCh->tpBuffer;

#ifdef USE_STATIC_RESERVED_BUF

	unsigned int tpBufferZoneSize = 0;
	unsigned int tpBufferZoneStartPhyAddr = 0;
	unsigned int tpBufferPhyAddr =0;
	//unsigned long phyAddr = DEMUX_TP_BUFFER_START + chNum * size;
	tpBufferZoneSize = carvedout_buf_query(CARVEDOUT_TP,(void**)&tpBufferZoneStartPhyAddr);
	dmx_notice("tpBuffer=> startPhyAdd:0x%x, totalSize:%d, ch:%d, chTpSize:%d\n",
			tpBufferZoneStartPhyAddr, tpBufferZoneSize, chNum, size);
	//if ((phyAddr+size) > (DEMUX_TP_BUFFER_START + DEMUX_TP_BUFFER_SIZE))
	//	return DEMUX_BUF_AllocBuffer(pBuf, size, 0, 0);
	if (tpBufferZoneSize > 0){
		tpBufferPhyAddr = tpBufferZoneStartPhyAddr + chNum*size;
		if ((tpBufferPhyAddr+size) <= (tpBufferZoneStartPhyAddr+tpBufferZoneSize)){
			pBuf->phyAddr = tpBufferPhyAddr;
			pBuf->allocSize = size < 0x1000 ? 0x1000 : size ;
			pBuf->cachedaddr = dvr_remap_cached_memory(pBuf->phyAddr, pBuf->allocSize, __builtin_return_address(0));
			pBuf->nonCachedaddr = dvr_remap_uncached_memory(pBuf->phyAddr, pBuf->allocSize, __builtin_return_address(0));
			pBuf->isCache = 0;
			pBuf->virAddr = pBuf->isCache ? pBuf->cachedaddr : pBuf->nonCachedaddr ;
			pBuf->size = size ;
			pBuf->fromPoll = 0 ;

			dmx_notice("[%s]TP[%d] cachedAddr 0x%lx, uncachedAddr 0x%lx, phyAddr 0x%x, allocSize 0x%x\n",
				__func__, chNum,(unsigned long)(uintptr_t)pBuf->cachedaddr,
				(unsigned long)(uintptr_t)pBuf->nonCachedaddr,pBuf->phyAddr, pBuf->allocSize);
			return 0 ;
		}
	}
#else

	return DEMUX_BUF_AllocBuffer(pBuf, size, 0, 0);
#endif
}
void IOCTL_FreeTPBuffer(int chNum)
{
	demux_channel *pCh = &demux_device->pChArray[chNum];
	DEMUX_BUF_T *pBuf = &pCh->tpBuffer;

#ifdef USE_STATIC_RESERVED_BUF
	unsigned int tp_buf_start = 0;
	unsigned int tp_buf_size =0;
	tp_buf_size = carvedout_buf_query(CARVEDOUT_TP, (void**) &tp_buf_start);
	if (pBuf->phyAddr >= tp_buf_start && (pBuf->phyAddr+pBuf->allocSize) <= (tp_buf_start + tp_buf_size)) {
		dvr_unmap_memory((void *)pBuf->cachedaddr, pBuf->allocSize);
		dvr_unmap_memory((void *)pBuf->nonCachedaddr, pBuf->allocSize);
		memset(pBuf, 0, sizeof(DEMUX_BUF_T));
		dmx_notice("[%s %d] CH:%d return carved-out tpBuffer \n",__func__,__LINE__, chNum);
		return;
	}
#endif

	DEMUX_BUF_FreeBuffer(pBuf);
}
int IOCTL_InitModule ()
{
	int i, j, size;
	int ret = 0;
	int tpBufSize, tpDataSize;
	DEMUX_INIT_T init,*pInfo;
	dmx_function_call();

	/* don't init module twice. */
	if (demux_device->pChArray)
		return 0;

	create_tp_controller();

	RHAL_GetHardwareInfo(&demux_device->tpInfo);

	init.useSDT           = ((demux_device->tpInfo.tp_num < 2) || (demux_device->tpInfo.chip_version < RTD294X_TP_PLUS)) ? 0 : 1 ;
	init.numberOfTP       = demux_device->tpInfo.tp_num ;
	init.numberOfVD       = DEMUX_VD_NUM ;
	init.numberOfAD       = DEMUX_AD_NUM ;
	init.sizeOfRefClock   = DEMUX_REFCLK_BUFF_SIZE ;
	init.sizeOfTP         = DEMUX_TP_BUFF_SIZE ;
	init.sizeOfVideoBS    = DEMUX_VD_BS_SIZE ;
	init.sizeOfVideoIB    = DEMUX_VD_IB_SIZE ;
	init.sizeOfAudioBS    = DEMUX_AD_BS_SIZE ;
	init.sizeOfAudioIB    = DEMUX_AD_IB_SIZE ;
	pInfo = &init;

	demux_device->disableCache  = DEMUX_DISABLE_CACHE_BUFFER;  /* for DEBUG */
	demux_device->useSDT        = pInfo->useSDT;
	demux_device->chNum         = demux_device->tpInfo.tp_num;
	demux_device->numberOfVD    = pInfo->numberOfVD;
	demux_device->numberOfAD    = pInfo->numberOfAD;
	demux_device->sizeOfVideoBS = pInfo->sizeOfVideoBS;
	demux_device->sizeOfAudioBS = pInfo->sizeOfAudioBS;
	demux_device->sizeOfVideoIB = pInfo->sizeOfVideoIB;
	demux_device->sizeOfAudioIB = pInfo->sizeOfAudioIB;

	if (pInfo->numberOfVD > MAX_VDEC_NUM || pInfo->numberOfAD > MAX_ADEC_NUM)
		goto demux_init_fail;
	demux_device->pChArray = kmalloc(sizeof(demux_channel)*demux_device->chNum, GFP_KERNEL);
	if (!(demux_device->pChArray)) {
		goto demux_init_fail;
	}
	memset(demux_device->pChArray, 0, sizeof(demux_channel)*demux_device->chNum);

	mutex_init(&demux_device->mutex);
#ifdef DEMUX_AUDIO_USE_GLOBAL_BUFFER
	DEMUX_BUF_InitAudioBuffer();
#endif
	/* allocate buffer pool for ringbuffer header and refclock */
	i = (sizeof(RINGBUFFER_HEADER) + 0xf) & ~0xf;
	j = (pInfo->sizeOfRefClock     + 0xf) & ~0xf;

	size = i *  demux_device->chNum /*tp*/
		+ i * 2 /*tp(0 and 1) info */
		+ i * demux_device->chNum *((demux_device->numberOfVD) << 1)/*video bs+ib rebuffer header*/
#ifdef DEMUX_AUDIO_USE_GLOBAL_BUFFER
		+ i * ((demux_device->numberOfAD) << 1)/*audio bs+ib rebuffer header*/
#else
		+ i * demux_device->chNum *((demux_device->numberOfAD) << 1)
#endif
		+ i *(MAX_SECTION_FILTER_NUM+MAX_PID_FILTER_CB_NUM)*demux_device->chNum/*section and PES ringbuffer header*/
		+ j * demux_device->chNum ; /*reference clock*/
	DEMUX_BUF_FreeBuffer(&demux_device->bufPoll); /* free original pool */
	if (DEMUX_BUF_AllocBuffer(&demux_device->bufPoll, size, 0, 1)   < 0)
		goto demux_init_fail;
	demux_device->usedPollSize = 0;

	if (DEMUX_BUF_AllocBuffer(&demux_device->secFilterBuffer, SEC_FILTER_BUFFER_SIZE, 0, 0)   < 0)
		goto demux_init_fail;

	for (j = 0; j < SEC_FILTER_BUFFER_UNIT_CNT; j++) {
		demux_device->secMap[j].bufIndex = j;
		demux_device->secMap[j].nextBufIndex = (j+1)%SEC_FILTER_BUFFER_UNIT_CNT;
		demux_device->secMap[j].virAddr = demux_device->secFilterBuffer.virAddr + (j*SEC_FILTER_BUFFER_UNIT_SIZE);
	}
	for (j = 0; j < NUMBER_OF_PINS; j++)
		demux_device->pinMap[j].chIndex = demux_device->chNum;

	/* pcr recovery */
	memset(demux_device->pcrTrkManager, 0, sizeof(PCRTRK_MANAGER_T)*DEMUX_PCRTRACKING_MANAGER_NUM);

	DEMUX_RegisterResetExecutionCounters();
	for (i = 0; i < demux_device->chNum; i++) {
		char pstr[10] = {0};

		demux_channel *pCh = &demux_device->pChArray[i];
		pCh->bIsSDT = ((i>1) && demux_device->useSDT);
		pCh->avSyncMode = NAV_AVSYNC_PCR_MASTER;
		pCh->preVideoSystemPTS = -1;
		pCh->preAudioSystemPTS = -1;
		pCh->preRCD = -1;
		pCh->lastStampedPTS = -1;
		pCh->CIKeySel  = -1;
		pCh->PCRPID    = -1;
		pCh->tunerHandle   = i;
		pCh->bUseDDRCopy   = DEMUX_USE_DDR_COPY;
		pCh->dataThreshold = TUNER_DATA_READ_THRESHOLD;
		pCh->videoFreeRunThreshold = DEFAULT_FREE_RUN_VIDEO_THRESHOLD;
		pCh->tsPacketSize  = 188;
		pCh->avSyncStartupFullness = 0;
		pCh->avSyncStartupPTS = 0;
		pCh->bPendingOnFullness = false;
		pCh->bPendingOnPTSCheck = false;
		pCh->bCheckAFState = false;
		//pCh->audioFullnessLowCount = 0;
		//pCh->audioFullnessLowCheckNum = 0;
		pCh->PCRSyncStatusCheckTick = 0;
		pCh->PCRSyncStatusCheckBaseTick = 0;
		pCh->bPcrTrackEnable = 1;
		pCh->audioType = AUDIO_UNKNOWN_TYPE;
		pCh->pvrSpeed = 256;
		pCh->AdChannelTarget = -1;
		for (j = 0; j < DEMUX_NUM_OF_TARGETS; j++) {
			pCh->activeTarget[j].bNewTarget = false;
			pCh->activeTarget[j].pid        = -1;
			pCh->demuxTargetInfo[j].pinIndex = j; /* CHECK IT LATER !*/
			pCh->demuxTargetInfo[j].contiCounter = -1;
			pCh->demuxTargetInfo[j].pts = -1;
			/*pCh->demuxTargetInfo[j].bufferedBytes = 0;*/
			/*pCh->demuxTargetInfo[j].remainingHeaderBytes = 0;*/
			pCh->demuxTargetInfo[j].bResyncStartUnit = true;
			/*pCh->demuxTargetInfo[j].demuxedCount = 0;*/
#ifndef DONTFIXBUG13648
			pCh->demuxTargetInfo[i].bResyncPTS = true;
#endif
		}

		for (j = 0; j < MAX_PID_FILTER_CB_NUM; j++) {
			pCh->activePESTarget[j].bNewTarget = false;
			pCh->activePESTarget[j].pid        = -1;
		}

		memset(pCh->demuxTargetTable  , DEMUX_TARGET_DROP, sizeof(pCh->demuxTargetTable));
		memset(pCh->demuxTargetTableCB, DEMUX_TARGET_DROP, sizeof(pCh->demuxTargetTableCB));
		memset(&pCh->mtpBuffer, 0, sizeof(pCh->mtpBuffer));
		memset(&pCh->adInfo, 0, sizeof(pCh->adInfo));
		mutex_init(&pCh->mutex);
		mutex_init(&pCh->section_mutex);

		if (pCh->bIsSDT) {
			if (DEMUX_BUF_AllocBuffer  (&pCh->tpBuffer, SDT_CH_BUFF_SIZE, 0, 0) < 0)
				goto demux_init_fail;
		} else {
			if (IOCTL_AllocateTPBuffer(i, pInfo->sizeOfTP) < 0)
				goto demux_init_fail;
		}

		if (DEMUX_BUF_AllocFromPoll(&pCh->tpBufferH, sizeof(RINGBUFFER_HEADER), &demux_device->bufPoll, 0) < 0)
			goto demux_init_fail;

		if (DEMUX_BUF_AllocFromPoll(&pCh->refClockBuffer, pInfo->sizeOfRefClock, &demux_device->bufPoll, 0) < 0)
			goto demux_init_fail;
		/* refclock */
		REFCLK_Reset(DEMUX_GetReferenceClock(pCh), pCh->avSyncMode, pCh->videoFreeRunThreshold);
		REFCLK_SetClockMode(DEMUX_GetReferenceClock(pCh), MISC_90KHz);
		/* av sync */
		PCRSYNC_Reset(&pCh->pcrProcesser, DEMUX_GetReferenceClock(pCh), pCh->tunerHandle, pCh->pPcrRecoveryManager);
		BufferFullDroppingReset(pCh, 0, 1);

		if (!pCh->bIsSDT) { /* SDT channel don't need bsbuffer, ONLY used as section filter */

		#ifndef DEMUX_AUDIO_USE_GLOBAL_BUFFER
			for (j = 0; j < demux_device->numberOfAD; j++) {

				if (DEMUX_BUF_AllocFromPoll(&pCh->bsAudioBufH[j], sizeof(RINGBUFFER_HEADER), &demux_device->bufPoll, 0) < 0)
					goto demux_init_fail;
				if (DEMUX_BUF_AllocFromPoll(&pCh->ibAudioBufH[j], sizeof(RINGBUFFER_HEADER), &demux_device->bufPoll, 0) < 0)
					goto demux_init_fail;
			}
		#endif

		#ifndef DEMUX_PES_BUFFER_DYNAMIC_ALLOC
			if (DEMUX_BUF_AllocBuffer(&pCh->pesFilterBuffer, PES_FILTER_BUFFER_SIZE, 1, 0) < 0)
				goto demux_init_fail;

			for (j = 0; j < MAX_PID_FILTER_CB_NUM; j++) {
				RINGBUFFER_HEADER *pRBH = NULL;
				DEMUX_PES_MAP_T   *pPes = &pCh->pesMap[j];
				pPes->virAddr = pCh->pesFilterBuffer.virAddr + j*PES_FILTER_RING_BUFFER_SIZE;
				pPes->phyAddr = (unsigned int)pCh->pesFilterBuffer.phyAddr + j*PES_FILTER_RING_BUFFER_SIZE;
				if (DEMUX_BUF_AllocFromPoll(&pPes->rbHeader, sizeof(RINGBUFFER_HEADER), &demux_device->bufPoll, 0) < 0)
					goto demux_init_fail;
				/*initialize ringbuffer header */
				pRBH = (RINGBUFFER_HEADER *)pPes->rbHeader.virAddr;
				pRBH->beginAddr    = (unsigned long)pPes->phyAddr;
				pRBH->size         = PES_FILTER_RING_BUFFER_SIZE;
				pRBH->writePtr     = pRBH->beginAddr;
				pRBH->numOfReadPtr = 1;
				pRBH->readPtr[0]   = pRBH->beginAddr;

				pPes->pWrPtr        = &pRBH->writePtr;
				pPes->pRdPtr        = &pRBH->readPtr[0];
				pPes->pBufferLower  = (unsigned char *)pRBH->beginAddr;
				pPes->pBufferUpper  = (unsigned char *)(pPes->pBufferLower + PES_FILTER_RING_BUFFER_SIZE);
				pPes->phyAddrOffset = (long) pPes->phyAddr - (long) pPes->virAddr;

			}
		#endif
		}

		/* hw tp */
		RHAL_TPInit(pCh->tunerHandle);

		pCh->tpBuffer.size = pCh->tpBuffer.allocSize - (pCh->tpBuffer.allocSize % (pCh->tsPacketSize == 188 ? (188*1024*2) : (MIN_UPLOAD_SIZE_FOR_192*2)));
		RHAL_SetTPRingBuffer(pCh->tunerHandle, (UINT8 *)pCh->tpBuffer.phyAddr, (UINT8 *)pCh->tpBuffer.nonCachedaddr, pCh->tpBuffer.size);


		tpBufSize = 0;
		tpDataSize = 0;
		if (RHAL_GetTPBufferStatus(pCh->tunerHandle, &tpBufSize, &tpDataSize) == TPK_SUCCESS && tpBufSize != pCh->tpBuffer.size) {

			dmx_crit("[%s %d] buf size not matched: tp %d, tpBufSize = %d, org = %d\n", __func__, __LINE__, pCh->tunerHandle, tpBufSize,  pCh->tpBuffer.size);
			pCh->tpBuffer.size = tpBufSize;
		}

		/* TP Buffer Header */
		DEMUX_BUF_ResetRBHeader(&pCh->tpBufferH, &pCh->tpBuffer, RINGBUFFER_STREAM, 0);
		pCh->phyAddrOffset = (long)pCh->tpBuffer.phyAddr - (long)pCh->tpBuffer.virAddr;


	#ifdef DEMUX_VIDEO_USE_PINGPONG_BUFFERS
		pCh->tmpPinInfo[VIDEO_PIN].bufIndex = -1;
		pCh->tmpPinInfo[VIDEO2_PIN].bufIndex = -1;
	#endif

		/* alloc ringbuffer header from bufPoll for each section index */
		for (j = 0 ; j < MAX_SECTION_FILTER_NUM ; j++) {
			if (DEMUX_BUF_AllocFromPoll(&pCh->secListCB[j].rbHeader, sizeof(RINGBUFFER_HEADER), &demux_device->bufPoll, 0) < 0)
				goto demux_init_fail;
		}

		pCh->state = DEMUX_STATE_STOP;
		snprintf(pstr,9,"DEMUX_%d",i);
		pCh->thread_task = kthread_create(DEMUX_ThreadProcEntry, (void *)pCh, pstr) ;
		if (!(pCh->thread_task))
			goto demux_init_fail;
		pCh->state = DEMUX_STATE_RUNNING;
		wake_up_process(pCh->thread_task);
		pCh->isInit  = 1;

		/* pcr recovery */
#ifdef CONFIG_RTK_KDRV_MULTI_TP_CLOCK
		if (pCh->tunerHandle < DEMUX_PCRTRACKING_MANAGER_NUM)
			pCh->pPcrRecoveryManager = &demux_device->pcrTrkManager[pCh->tunerHandle];
		else
			pCh->pPcrRecoveryManager = NULL;
#else
		pCh->pPcrRecoveryManager = &demux_device->pcrTrkManager[0];
#endif
		if(pCh->pPcrRecoveryManager) {
			PCRTRACK_Initialize(pCh->pPcrRecoveryManager, pCh->tunerHandle);
		}
	}

	demux_device->isInit = 1;
	return 0;

demux_init_fail:
	ret = -ENOMEM;
	IOCTL_ShutDownModule();
	dmx_err("DEMUX init Fail @#@#!!!!!!!!!!@#@#\n");
	BUG();
	return ret;
}
int IOCTL_UnInitModule(void)
{
	int mgr_idx;
	dmx_function_call();

	if (demux_device->pChArray) {
		IOCTL_ShutDownModule();
	}

	for (mgr_idx = 0 ; mgr_idx < DEMUX_PCRTRACKING_MANAGER_NUM ; mgr_idx++) {
		PCRTRACK_Release(&demux_device->pcrTrkManager[mgr_idx]);
	}

	demux_device->isInit = 0;
	return 0;
}

int IOCTL_STDResetInfoPoll()
{

	int i, j;

	dmx_function_call();


	for (i = 0; i < demux_device->chNum; i++) {
		RINGBUFFER_HEADER *pRBH;
		demux_channel *pCh = &demux_device->pChArray[i];

		//1 1.reset refClockBuffer
		/* refclock */
		REFCLK_SetClockMode(DEMUX_GetReferenceClock(pCh), MISC_90KHz);
		//1 2. reset PES HEAD
		if (!pCh->bIsSDT) { /* SDT channel don't need bsbuffer, ONLY used as section filter */
			for (j = 0; j < MAX_PID_FILTER_CB_NUM; j++) {
				DEMUX_PES_MAP_T   *pPes = &pCh->pesMap[j];


				/*initialize ringbuffer header */
				pRBH = (RINGBUFFER_HEADER *)pPes->rbHeader.virAddr;
				if (pRBH && (pPes->phyAddr != 0)){
					pRBH->beginAddr    = (unsigned long)pPes->phyAddr;
					pRBH->size         = PES_FILTER_RING_BUFFER_SIZE;
					pRBH->writePtr     = pRBH->beginAddr;
					pRBH->numOfReadPtr = 1;
					pRBH->readPtr[0]   = pRBH->beginAddr;
				}
			//	printk("initdemux demux_pes buff (%d-%d):phy:0x%x,vir:0x%x, r1:0x%x,r2:0x%x, w1:0x%x,  w:0x%x, b:0x%x, e:0x%x, offset: 0x%x\n",i, j,pPes->phyAddr, pPes->virAddr,pPes->pRdPtr,*(pPes->pRdPtr),pPes->pWrPtr,*(pPes->pWrPtr), pPes->pBufferLower, pPes->pBufferUpper, pPes->phyAddrOffset);
			}
		}

		/* TP Buffer Header */
		//1 3.reset TP HEAD
		DEMUX_BUF_ResetRBHeader(&pCh->tpBufferH, &pCh->tpBuffer, RINGBUFFER_STREAM, 0);

		}

	return 0;
}
int IOCTL_ReleaseBuffer(DEMUX_BUF_INFO_T *pInfo)
{
	demux_channel *pCh;
	int pin;
	DEMUX_CHECK_CH(pInfo->ch);
	dmx_info("func %s, line %d, ch %d\n", __func__, __LINE__, pInfo->ch);

	pCh = &demux_device->pChArray[pInfo->ch];


	switch (pInfo->dest) {
	case DEMUX_DEST_ADEC0: pin = AUDIO_PIN; break;
	case DEMUX_DEST_ADEC1: pin = AUDIO2_PIN; break;
	case DEMUX_DEST_VDEC0: pin = VIDEO_PIN; break;
	case DEMUX_DEST_VDEC1: pin = VIDEO2_PIN; break;
	default:
	    return -1;
	}
	mutex_lock(&pCh->mutex);
#ifdef DEMUX_AUDIO_USE_GLOBAL_BUFFER
	if (DEMUX_BUF_ReleaseAudioBuffer(pCh, pin)<0){
		dmx_err("[%s,%d] ch:%d, pin:%d, release audio buffer fail \n", __func__, __LINE__, pCh->tunerHandle, pin);
	}
	SET_FLAG(pCh->status, STATUS_SET_AUDIO_PIN_INFO);
#endif
	dmx_crit("[%s %d]CH%d pin = %d\n", __func__, __LINE__, pInfo->ch, pin);
	mutex_unlock(&pCh->mutex);

	return 0;
}
int IOCTL_GetBufferInfo(DEMUX_BUF_INFO_T *pInfo)
{
	int index;
	demux_channel *pCh;
	DEMUX_BUF_T   *pIBH, *pBSH = NULL;
	dmx_function_call();
	DEMUX_CHECK_CH(pInfo->ch);
	dmx_mask_print(DEMUX_BUFFER_DEBUG|DEMUX_NOTICE_PRINT,"[%s, %d]\n", __func__, __LINE__);
	pCh = &demux_device->pChArray[pInfo->ch];
	switch (pInfo->dest) {
	case DEMUX_DEST_ADEC0:
	{
	#if defined(DEMUX_AUDIO_USE_GLOBAL_BUFFER)
		mutex_lock(&pCh->mutex);
		if (DEMUX_BUF_RequestAudioBuffer(pCh, AUDIO_PIN)<0)
		{
			dmx_err("[%s,%d] ERROR, ch:%d, pin:%d, get buffer fail\n", __func__, __LINE__, pCh->tunerHandle, AUDIO_PIN);
			return -1;
		}
		if (pCh->pinInfo[AUDIO_PIN].pBuffer->status == BUF_STAT_REUSED_II)
		{
			dmx_mask_print(DEMUX_BUFFER_DEBUG|DEMUX_NOTICE_PRINT,"[%s, %d] ch:%d, pin:%d this pin still hold a releaseing buffer\n",
				__func__, __LINE__, pCh->tunerHandle, AUDIO_PIN);
			pBSH = &pCh->pinInfo[AUDIO_PIN].pBuffer_reserved->bsBufferH;
			pIBH = &pCh->pinInfo[AUDIO_PIN].pBuffer_reserved->ibBufferH;
		}
		else{
			pBSH = &pCh->pinInfo[AUDIO_PIN].pBuffer->bsBufferH;
			pIBH = &pCh->pinInfo[AUDIO_PIN].pBuffer->ibBufferH;
		}
		SET_FLAG(pCh->status, STATUS_SET_AUDIO_PIN_INFO);
		mutex_unlock(&pCh->mutex);
	#else
		if (IOCTL_GetBufferInfoImpl(pCh, AUDIO_PIN, 0) >= 0)
			pBSH = &pCh->bsAudioBufH[0], pIBH = &pCh->ibAudioBufH[0];
	#endif

		break;
	}
	case DEMUX_DEST_ADEC1:
	{
	#if defined(DEMUX_AUDIO_USE_GLOBAL_BUFFER)
		dmx_mask_print(DEMUX_BUFFER_DEBUG|DEMUX_NOTICE_PRINT,"[%s, %d]\n", __func__, __LINE__);
		mutex_lock(&pCh->mutex);
		if (DEMUX_BUF_RequestAudioBuffer(pCh, AUDIO2_PIN)<0)
		{
			dmx_err("[%s,%d] ERROR, ch:%d, pin:%d, get buffer fail\n", __func__, __LINE__, pCh->tunerHandle, AUDIO2_PIN);
			return -1;
		}
		if (pCh->pinInfo[AUDIO2_PIN].pBuffer->status == BUF_STAT_REUSED_II)
		{
			dmx_mask_print(DEMUX_BUFFER_DEBUG|DEMUX_NOTICE_PRINT,"[%s, %d] ch:%d, pin:%d this pin still hold a releaseing buffer\n",
				__func__, __LINE__, pCh->tunerHandle, AUDIO2_PIN);
			pBSH = &pCh->pinInfo[AUDIO2_PIN].pBuffer_reserved->bsBufferH;
			pIBH = &pCh->pinInfo[AUDIO2_PIN].pBuffer_reserved->ibBufferH;
		}
		else{
			pBSH = &pCh->pinInfo[AUDIO2_PIN].pBuffer->bsBufferH;
			pIBH = &pCh->pinInfo[AUDIO2_PIN].pBuffer->ibBufferH;
		}
		SET_FLAG(pCh->status, STATUS_SET_AUDIO_PIN_INFO);
		mutex_unlock(&pCh->mutex);
	#else
		if (IOCTL_GetBufferInfoImpl(pCh, AUDIO2_PIN, 1) >= 0)
			pBSH = &pCh->bsAudioBufH[1], pIBH = &pCh->ibAudioBufH[1];
	#endif

		break;
	}
	case DEMUX_DEST_VDEC0:
	{
	#ifdef DEMUX_VIDEO_USE_PINGPONG_BUFFERS
		index = pCh->tmpPinInfo[VIDEO_PIN].bufIndex;
		if (index < 0)
			return -1;
		pBSH = &demux_device->bsVideoBufH[index], pIBH = &demux_device->ibVideoBufH[index];
	#else
		if (pCh->bsVideoBuf[0].phyAddr) {
			pBSH = &pCh->bsVideoBufH[0], pIBH = &pCh->ibVideoBufH[0];

		}
	#endif
		break;
	}
	case DEMUX_DEST_VDEC1:
	{
	#ifdef DEMUX_VIDEO_USE_PINGPONG_BUFFERS
		index = pCh->tmpPinInfo[VIDEO2_PIN].bufIndex;
		if (index < 0)
			return -1;
		pBSH = &demux_device->bsVideoBufH[index], pIBH = &demux_device->ibVideoBufH[index];

	#else
		if (pCh->bsVideoBuf[1].phyAddr) {
			pBSH = &pCh->bsVideoBufH[1], pIBH = &pCh->ibVideoBufH[1];

		}
	#endif
		break;
	}
	case DEMUX_DEST_RECORD_A:
	case DEMUX_DEST_RECORD_B:

		pBSH = &pCh->tpBufferH;

		pInfo->bsPhyAddr    = pBSH->phyAddr;
		pInfo->bsHeaderSize = pBSH->allocSize;
		pInfo->refClockPhyAddr = 0;
		pInfo->refClockHeaderSize = 0;
		pInfo->ibPhyAddr = 0;
		pInfo->ibHeaderSize = 0;
		return 0;
	default:
		break;
	}

	if (pBSH) {
		pInfo->refClockPhyAddr    = pCh->refClockBuffer.phyAddr;
		pInfo->refClockHeaderSize = pCh->refClockBuffer.allocSize;
		pInfo->bsPhyAddr          = pBSH->phyAddr;
		pInfo->ibPhyAddr          = pIBH->phyAddr;
		pInfo->bsHeaderSize       = pBSH->allocSize;
		pInfo->ibHeaderSize       = pIBH->allocSize;

#ifdef DEMUX_DEBUG
		{
			RINGBUFFER_HEADER *pHeader;
			dmx_mask_print(DEMUX_NOMAL_DEBUG,"(CH%d)REFCLOCK %x, size %d\n", pCh->tunerHandle, pInfo->refClockPhyAddr, pInfo->refClockHeaderSize);
			dmx_mask_print(DEMUX_NOMAL_DEBUG,"(CH%d)BSH: %x,IBH: %x,BS_size: %x,IB_size: %x\n", pInfo->bsPhyAddr, pInfo->ibPhyAddr, pInfo->bsHeaderSize, pInfo->ibHeaderSize);
			pHeader = (RINGBUFFER_HEADER *)pBSH->virAddr;
			dmx_mask_print(DEMUX_NOMAL_DEBUG,"(CH%d)BS: beginAddr:%x, sz %x\n", pCh->tunerHandle, (unsigned int)DEMUX_reverseInteger(pHeader->beginAddr)   , (unsigned int)DEMUX_reverseInteger(pHeader->size));
			dmx_mask_print(DEMUX_NOMAL_DEBUG,"(CH%d)BS: bufferID: %x, wp %x\n", pCh->tunerHandle, (unsigned int)DEMUX_reverseInteger(pHeader->bufferID)    , (unsigned int)DEMUX_reverseInteger(pHeader->writePtr));
			dmx_mask_print(DEMUX_NOMAL_DEBUG,"(CH%d)BS: numOfRP:  %x, rp %x\n", pCh->tunerHandle, (unsigned int)DEMUX_reverseInteger(pHeader->numOfReadPtr), (unsigned int)DEMUX_reverseInteger(pHeader->readPtr[0]));
			pHeader = (RINGBUFFER_HEADER *)pIBH->virAddr;
			dmx_mask_print(DEMUX_NOMAL_DEBUG,"(CH%d)IB: beginAddr:%x, sz %x\n", pCh->tunerHandle, (unsigned int)DEMUX_reverseInteger(pHeader->beginAddr)   , (unsigned int)DEMUX_reverseInteger(pHeader->size));
			dmx_mask_print(DEMUX_NOMAL_DEBUG,"(CH%d)IB: bufferID: %x, wp %x\n", pCh->tunerHandle, (unsigned int)DEMUX_reverseInteger(pHeader->bufferID)    , (unsigned int)DEMUX_reverseInteger(pHeader->writePtr));
			dmx_mask_print(DEMUX_NOMAL_DEBUG,"(CH%d)IB: numOfRP:  %x, rp %x\n", pCh->tunerHandle, (unsigned int)DEMUX_reverseInteger(pHeader->numOfReadPtr), (unsigned int)DEMUX_reverseInteger(pHeader->readPtr[0]));
		}
#endif

		return 0;
	} else {
		dmx_err("func %s, line %d, don't support dest (%d) or alloc buffer fail!!\n", __func__, __LINE__, pInfo->dest);
		return -ENOTTY;
	}
}
int IOCTL_GetSTC(DEMUX_STC_T *pInfo)
{
	REFCLOCK *pRef;
	long long rcd, pts;
	int ret = 0;

	pInfo->stc_hi = 0;
	pInfo->stc_lo = 0;
	dmx_function_call();
	DEMUX_CHECK_CH(pInfo->ch);

	pRef = DEMUX_GetReferenceClock(&demux_device->pChArray[pInfo->ch]);
	if (pRef) {
		rcd = DEMUX_reverseLongInteger(pRef->RCD);
		if (rcd != -1) {
			pts = CLOCK_GetAVSyncPTS(pRef) + rcd;
			pInfo->stc_hi = (UINT32) (pts >> 32);
			pInfo->stc_lo = (UINT32) (pts & 0xffffffff);
			ret = 0;
		}
	}
	return ret;
}
int IOCTL_StartSCrambleCheck(DEMUX_SCRAMBLE_T *pInfo)
{
	demux_channel *pCh;
	int i;
	int ret = -1;
	dmx_function_call();
	DEMUX_CHECK_CH(pInfo->ch);
	DEMUX_CHECK_PID(pInfo->pid);
	pCh = &demux_device->pChArray[pInfo->ch];
	dmx_notice("DEMUX_StartSCrambleCheck: ch:%d, pid:0x%x, type:%d\n",
		pInfo->ch, pInfo->pid, pInfo->pidType);
	mutex_lock(&pCh->mutex);
	for (i = 0; i < pCh->checkScrambleCount; i++) {
		if (pInfo->pidType == pCh->scrambleList[i].pidType && pInfo->pid == pCh->scrambleList[i].pid) {
			if (!pCh->scrambleList[i].bCheck) {
				pCh->scrambleList[i].bCheck = true;
				pCh->scrambleList[i].timeStamp = 0;
				pCh->bUpdateDemuxTarget     = true;
				ret = 0;
			}
			break;
		}
	}

	if (i == pCh->checkScrambleCount && i < MAX_PID_FILTER_NUMBER) {
		pCh->scrambleList[i].bCheck  = true;
		pCh->scrambleList[i].pid     = pInfo->pid;
		pCh->scrambleList[i].pidType = pInfo->pidType;
		pCh->scrambleList[i].timeStamp = 0;
		pCh->checkScrambleCount++;
		SET_FLAG(pCh->events, EVENT_UPDATE_SCRAMBLE_LIST);
		pCh->bUpdateDemuxTarget      = true;
		ret = 0;

		if (!pCh->startStreaming) {
			RHAL_TPStreamControl(pCh->tunerHandle, TP_STREAM_START);
			pCh->startStreaming = 1;
		}
	}
	mutex_unlock(&pCh->mutex);
	return ret;
}
int IOCTL_StopSCrambleCheck(DEMUX_SCRAMBLE_T *pInfo)
{
	demux_channel *pCh;
	int i;
	dmx_function_call();
	DEMUX_CHECK_CH(pInfo->ch);
	DEMUX_CHECK_PID(pInfo->pid);
	pCh = &demux_device->pChArray[pInfo->ch];
	dmx_notice("DEMUX_StopSCrambleCheck: ch:%d, pid:0x%x, type:%d\n",
		pInfo->ch, pInfo->pid, pInfo->pidType);
	mutex_lock(&pCh->mutex);
	for (i = 0; i < pCh->checkScrambleCount; i++) {
		if (pInfo->pidType == pCh->scrambleList[i].pidType && pInfo->pid == pCh->scrambleList[i].pid) {
			if (pCh->scrambleList[i].bCheck)
				pCh->scrambleList[i].bCheck = false;
			SET_FLAG(pCh->events, EVENT_UPDATE_SCRAMBLE_LIST);
			pCh->bUpdateDemuxTarget      = true;
			break;
		}
	}
	mutex_unlock(&pCh->mutex);
	return 0;
}
int IOCTL_CheckSCrambledStatus(DEMUX_SCRAMBLE_T *pInfo)
{
	demux_channel *pCh;
	int ret = -1, i = 0;
	dmx_function_call();
	DEMUX_CHECK_CH(pInfo->ch);
	DEMUX_CHECK_PID(pInfo->pid);
	pCh = &demux_device->pChArray[pInfo->ch];
	for (i = 0; i < pCh->checkScrambleCount; i++) {
		if (pInfo->pidType == pCh->scrambleList[i].pidType && pInfo->pid == pCh->scrambleList[i].pid) {
			if (pCh->scrambleList[i].bCheck){
				ret =HAS_FLAG(pCh->chkScrambleTable[pInfo->pid], PID_SCRAMBLE_CHECKED) ?
						(HAS_FLAG(pCh->chkScrambleTable[pInfo->pid], PID_IS_SCRAMBLE) ? 1 : 0) :
						2;
					if (pCh->scrambleList[i].timeStamp == 0)
						ret = 3;
			}

			break;
		}
	}
	dmx_notice("DEMUX_CheckSCrambledStatus:ch:%d, pid:0x%x, type:%d, status:%d(0:unscrambled, 1:scrambled, 2: no data, 3: filter not set yet)\n",
		  	pInfo->ch, pInfo->pid, pInfo->pidType, ret);
	return ret;//(0:unscrambled, 1:scrambled, 2: no data, 3: filter not set yet )
}
// inplace remove the invalid PID filters from list and return the new list size
static size_t IOCTL_RemoveInvalidPIDFilters(DEMUX_PID_LIST_T* const list, size_t size) {

		DEMUX_PID_LIST_T* const end = list + size;

		DEMUX_PID_LIST_T* last = list;
		DEMUX_PID_LIST_T* next = list;

		for (; next < end; ++next) {
			// only reserve valid pid
			if (0 <= next->pid) {
				if (next != last)
					*last = *next;

					++last;
			}
		}
		return last - list;
}

static inline bool IOCTL_IsVideoDest(DEMUX_PES_DEST_T dest) {
		return dest == DEMUX_DEST_VDEC0 || dest == DEMUX_DEST_VDEC1;
}

static inline bool IOCTL_IsAudioDest(DEMUX_PES_DEST_T dest) {
		return dest == DEMUX_DEST_ADEC0 || dest == DEMUX_DEST_ADEC1;
}

static inline bool IOCTL_IsRecordDest(DEMUX_PES_DEST_T dest) {
		return dest == DEMUX_DEST_RECORD_A|| dest == DEMUX_DEST_RECORD_B;
}
void IOCTL_UpdatePinMap(demux_channel *pCh, DEMUX_PES_DEST_T dest, bool bRemoved)
{
	int pin;

	switch (dest) {
	case DEMUX_DEST_VDEC0: pin = VIDEO_PIN; break;
	case DEMUX_DEST_VDEC1: pin = VIDEO2_PIN; break;
	case DEMUX_DEST_ADEC0: pin = AUDIO_PIN; break;
	case DEMUX_DEST_ADEC1: pin = AUDIO2_PIN; break;
	default : return;
	}
	if (bRemoved) {
		demux_device->pinMap[pin].chIndex = demux_device->chNum ;
		dmx_crit("[%s %d] pin = %d, chIndex = invalid\n", __func__, __LINE__, pin);
		return;
	}
	demux_device->pinMap[pin].chIndex = pCh->tunerHandle;
	dmx_crit("[%s %d] pin = %d, chIndex = %d\n", __func__, __LINE__, pin, demux_device->pinMap[pin].chIndex);

}
static int IOCTL_SetPIDImpl(DEMUX_SET_PID_T *pInfo)
{
	static const short filterRemoveIndicator = 0x1fff;

	demux_channel *pCh;
	int i;
	pCh = &demux_device->pChArray[pInfo->ch];

	for (i = 0; i < pCh->pidFilterCount; i++) {

		DEMUX_PID_LIST_T* const currentFilter = &(pCh->pidFilterList[i]);

		const bool haveSamePIDType = (currentFilter->pidType == pInfo->pidType);
		const bool haveSameDest    = (currentFilter->pesDest == pInfo->dest);
		if (haveSamePIDType && haveSameDest) {
			// ignore the almost same content
			if (currentFilter->pid == pInfo->pid) {
				dmx_info("func %s, line %d, ch %d, pid(%d) has existed in list\n", __func__, __LINE__, pCh->tunerHandle, pInfo->pid);
				return 0;
			} else if (pInfo->pid == filterRemoveIndicator) { /* only clear pid */
				if (HAS_FLAG(pCh->status, STATUS_AUDIO_PAUSED) && IOCTL_IsAudioDest(pInfo->dest)) {
					dmx_notice("[PVR] (CH%d) DONOT RemovePID: pid=%d(0x%x),type=%d,dest=%d\n", pCh->tunerHandle, currentFilter->pid, currentFilter->pid, pInfo->pidType, pInfo->dest);
					return 0;
				} else {
					dmx_notice("[dtv] (CH%d)RemovePID: pid=%d(0x%x),type=%d,dest=%d\n", pCh->tunerHandle, currentFilter->pid, currentFilter->pid, pInfo->pidType, pInfo->dest);


					IOCTL_UpdatePinMap(pCh, currentFilter->pesDest, true);

				#ifdef DEMUX_VIDEO_USE_PINGPONG_BUFFERS
					IOCTL_UpdateVideoPinInfo(pCh, currentFilter->pesDest, false);
				#else
					if (IOCTL_IsVideoDest(currentFilter->pesDest)) {
						int port = (currentFilter->pesDest == DEMUX_DEST_VDEC1);
						pCh->vBufStatus[port] = BUF_STAT_FREE;
						dmx_info("[%s %d]Ch%d port %d is waiting to be free\n", __func__, __LINE__, pCh->tunerHandle, port);
					}
				#endif

				    currentFilter->refCnt--;
					if( 0 == currentFilter->refCnt ) {
						currentFilter->pid = -1;
					} else {
						currentFilter->pesDest = DEMUX_DEST_TSO;
					}
				}
				break;
			} else {
				dmx_info("[%s %d] (CH%d)pidType(%d) is already in list\n", __func__, __LINE__, pCh->tunerHandle, pInfo->pidType);
				// different PIDs have same destination(VDEC/ADEC), remove the one already in list
				if (IOCTL_IsVideoDest(pInfo->dest) || IOCTL_IsAudioDest(pInfo->dest)) {
					currentFilter->refCnt--;
					if( 0 == currentFilter->refCnt )
						currentFilter->pid = -1;
					else{
						dmx_mask_print(DEMUX_PID_DEBUG|DEMUX_NOTICE_PRINT, "[dtv] (CH%d)SameTypeA/V,changeToTSO: pid=%d(0x%x),type=%d,dest=%d\n",
							pCh->tunerHandle, currentFilter->pid, currentFilter->pid, pInfo->pidType, pInfo->dest);
						currentFilter->pesDest = DEMUX_DEST_TSO;
					}
				}
			}
			// in the case if the PID filter was added by descramble related modules
			// and it has destination: DEMUX_DEST_TSO, then treat it is equal
			// to VDEC0/VDEC1 or ADEC0/ADEC1, just drop the newly added one
		} else if (haveSamePIDType) {
			if (currentFilter->pid == pInfo->pid && currentFilter->pesDest == DEMUX_DEST_TSO) {
				if (IOCTL_IsVideoDest(pInfo->dest) || IOCTL_IsAudioDest(pInfo->dest)||IOCTL_IsRecordDest(pInfo->dest)) {
					int test_target = 0;
					dmx_info("func %s, line %d, ch %d, pid(%d) has existed in list, need update dest\n", __func__, __LINE__, pCh->tunerHandle, pInfo->pid);

					test_target = GetTargetIdxFromType(pInfo->pidType, pInfo->dest);
					/* Check audio discription volume seeting need to reset or not */
					if(test_target == pCh->AdChannelTarget){
						SET_FLAG(pCh->events, EVENT_FLUSH_AD_INFO);
					}
					break;
				}
			}
		}
	}


	if (pInfo->pid == filterRemoveIndicator) { /* only clear PID by setting pInfo->pid to 0x1fff */
		const int target = GetTargetIdxFromType(pInfo->pidType, pInfo->dest);
		pCh->pidFilterCount = IOCTL_RemoveInvalidPIDFilters(pCh->pidFilterList, pCh->pidFilterCount);

		if (0 <= target) {
			pCh->activeTarget[target].bNewTarget = false;
			pCh->activeTarget[target].pid        = -1;
		}

	} else if (i == pCh->pidFilterCount) { /* set new pid ,  It means there no the same PID in pidFilterList.*/
		DEMUX_PID_LIST_T*  newFilter = NULL;
		int target = DEMUX_TARGET_DROP;
		dmx_notice("[dtv] (CH%d)AddPID: pid=%d(0x%x),type=%d,dest=%d\n", pCh->tunerHandle, pInfo->pid, pInfo->pid, pInfo->pidType, pInfo->dest);

		pCh->pidFilterCount = IOCTL_RemoveInvalidPIDFilters(pCh->pidFilterList, pCh->pidFilterCount);

		newFilter = pCh->pidFilterList + pCh->pidFilterCount;

		newFilter->pid          = pInfo->pid;
		newFilter->pidType      = pInfo->pidType;
		newFilter->pesDest      = pInfo->dest;
		newFilter->cwIndex      = -1;
		newFilter->enDescramble = 0;
		newFilter->refCnt       = 1;
		target = GetTargetIdxFromType(newFilter->pidType, newFilter->pesDest);

		if (target >= 0 && pCh->activeTarget[target].pid != newFilter->pid) {
			pCh->activeTarget[target].bNewTarget = true;
			pCh->activeTarget[target].pid        = newFilter->pid;
		}

		if (target == DEMUX_TARGET_AUDIO_2ND)
			memset(&pCh->adInfo, 0, sizeof(pCh->adInfo));

		if (pCh->CIKeySel >= 0) {
			newFilter->cwIndex = pCh->CIKeySel;
			newFilter->enDescramble = 1;
		} else {
			int j;
			for (j = 0; j < demux_device->tpInfo.descrambler_num; j++) {
				if (demux_device->cwInfo[j].used && demux_device->cwInfo[j].pid == newFilter->pid && demux_device->cwInfo[j].ch == pInfo->ch) {
					newFilter->cwIndex = j;
					newFilter->enDescramble = 1;
					break;
				}
			}
		}
		IOCTL_UpdatePinMap(pCh, pInfo->dest, false);
	#ifdef DEMUX_VIDEO_USE_PINGPONG_BUFFERS
		IOCTL_UpdateVideoPinInfo(pCh, pInfo->dest, true);
	#else
		DEMUX_BUF_PrepareVideoBuffer(pCh, pInfo->dest);
	#endif
		pCh->pidFilterCount++;
	} else {
		//update dest
		dmx_notice("[dtv] (CH%d)AddPID update_dest: pid=%d(0x%x),type=%d,dest=%d->%d\n", pCh->tunerHandle, pInfo->pid, pInfo->pid, pInfo->pidType, pCh->pidFilterList[i].pesDest, pInfo->dest);

		pCh->pidFilterList[i].pesDest = pInfo->dest;
		pCh->pidFilterList[i].refCnt  += 1;
		IOCTL_UpdatePinMap(pCh, pInfo->dest, false);
	#ifdef DEMUX_VIDEO_USE_PINGPONG_BUFFERS
		IOCTL_UpdateVideoPinInfo(pCh, pInfo->dest, true);
	#else
		DEMUX_BUF_PrepareVideoBuffer(pCh, pInfo->dest);
	#endif
	}

	SET_FLAG(pCh->events, EVENT_UPDATE_TS_LIST);
	if (pInfo->pidType == DEMUX_PID_PCR && pCh->PCRPID != pInfo->pid) {
		pCh->PCRPID = pInfo->pid;
		if (0 < pCh->PCRPID && pCh->PCRPID < 0x1FFF) {
			SET_FLAG(pCh->status, STATUS_PCRTAK_START);
		}
		else{
			RESET_FLAG(pCh->status, STATUS_PCRTAK_START);
			SET_FLAG(pCh->status, STATUS_PCRTAK_STOP);
		}
	}

	/* debug print */
	for (i = 0 ; i < pCh->pidFilterCount ; i++) {
		dmx_mask_print(DEMUX_NOMAL_DEBUG,"[dtv] (CH%d)pidFilterList[%d]:pid=%d,type=%d,dest=%d\n",
			pCh->tunerHandle, i, pCh->pidFilterList[i].pid, pCh->pidFilterList[i].pidType, pCh->pidFilterList[i].pesDest);
	}

	if (pCh->pidFilterCount == 0){
		dmx_notice("set_PID : ch:%d,  DEMUX_PRIVATEINFO_FLUSHTP \n", pInfo->ch);
		dmx_notice("(%s-%d): DEMUX_PRIVATEINFO_FLUSHTP -ch:%d filteramask: %x \n", __FILE__, __LINE__,pInfo->ch,DEMUX_checkFilterCount(pCh));
		SET_FLAG(pCh->events, EVENT_FLUSH_TP);
	}
	pCh->bUpdateDemuxTarget = true;
	if (!pCh->startStreaming) {
		RHAL_TPStreamControl(pCh->tunerHandle, TP_STREAM_START);
		pCh->startStreaming = 1;
	}


	return 0;
}
int IOCTL_SetPID(DEMUX_SET_PID_T *pInfo)
{
	demux_channel *pCh;

	dmx_notice("func %s, line %d, ch %d, pid 0x%x, pidType %d, dest %d\n", __func__, __LINE__, pInfo->ch, pInfo->pid, pInfo->pidType, pInfo->dest);
	DEMUX_CHECK_CH(pInfo->ch);
	DEMUX_CHECK_PID(pInfo->pid);
	pCh = &demux_device->pChArray[pInfo->ch];
	mutex_lock(&pCh->mutex);
	IOCTL_SetPIDImpl(pInfo);
	mutex_unlock(&pCh->mutex);
	return 0;
}
int IOCTL_GetPID(DEMUX_GET_PID_T *pInfo)
{
	demux_channel *pCh;
	int i, ret = -1;
	dmx_mask_print(DEMUX_FILTER_DEBUG,"func %s, line %d, ch %d, pidType %d, dest %d\n", __func__, __LINE__, pInfo->ch, pInfo->pidType, pInfo->dest);
	DEMUX_CHECK_CH(pInfo->ch);
	pCh = &demux_device->pChArray[pInfo->ch];
	mutex_lock(&pCh->mutex);
	//checkpidFilterlist
	for (i = 0; i < pCh->pidFilterCount; i++) {
		if (pCh->pidFilterList[i].pidType == pInfo->pidType && pCh->pidFilterList[i].pesDest == pInfo->dest) {
			ret = pCh->pidFilterList[i].pid;
			break;
		}
	}
	//check PESLIST
	if (ret == -1)
	{
		for (i = 0; i < MAX_PID_FILTER_CB_NUM; i++) {
			if ((pCh->pidFilterListCB[i].used) && (pCh->pidFilterListCB[i].pidType== pInfo->pidType) && (pInfo->dest == DEMUX_DEST_BUFFER) ) {
				ret = pCh->pidFilterListCB[i].pid;
				break;
			}
		}
	}
	//not match filter return 0x1fff
	if(ret == -1)
		ret = 0x1fff;
	mutex_unlock(&pCh->mutex);
	return ret;
}
/* return : section index in this channel */
int IOCTL_AddSectionFilter(DEMUX_ADD_SEC_FILTER_T *pInfo)
{
	demux_channel *pCh;
	int ret, i, cnt;
	dmx_function_call();
	DEMUX_CHECK_CH(pInfo->ch);
	pCh = &demux_device->pChArray[pInfo->ch];
	ret = DEMUX_GetSecIndex(pCh);
	mutex_lock(&pCh->section_mutex);
	if (ret >= 0) {
		DEMUX_SEC_LIST_T *pSec = &pCh->secListCB[ret];
		pInfo->param.Request_buf = TP_RequestSecBufferCB;
		pInfo->param.Complete    = TP_SecComplete;
		pInfo->param.pContext    = (void *)((pInfo->ch << 8) | ret);
		pSec->checksum = (pInfo->param.crc_en == 2);
		if (pSec->checksum) {/* checksum */
			pInfo->param.crc_en = 0;
		}
		/* REMOVE ME!	*/
		dmx_mask_print(DEMUX_SECTION_DEBUG,"AddSection ch:%d,PID: 0x%x, crc %d, one_shoot %d, togMode %d\n", pInfo->ch, pInfo->param.PID, pInfo->param.crc_en, pInfo->param.one_shoot, pInfo->param.toggle_mode_en);
/*
		for (i = 0; i < 10; i++) {
			dmx_info("AddSection(%d) PosVal: %x, PosMsk: %x, NegVal: %x, NegMsk: %x\n", i, pInfo->param.PosVal[i], pInfo->param.PosMsk[i], pInfo->param.NegVal[i], pInfo->param.NegMsk[i]);
		}
*/
		cnt = (pInfo->size + SEC_FILTER_BUFFER_UNIT_SIZE - 1)/SEC_FILTER_BUFFER_UNIT_SIZE;
		i = DEMUX_GetSecRingBuffer(pInfo->param.pContext, cnt > 0 ? cnt : 1); /* return (first buffer index << 16) | last buffer index */
		dmx_mask_print(DEMUX_SECTION_DEBUG,"func %s, line %d, cnt %d, idx %d, first %d, last %d\n", __func__, __LINE__,cnt, i, (i >> 16), (i & 0xffff) ) ;
		if (i < 0 || RHAL_AddSectionFilter(pInfo->ch, pInfo->param, (void *)DEFAULT_FILE_HANDLE, &pSec->handle) != TPK_SUCCESS) {
			if (i >= 0) {
				DEMUX_FreeSecRingBuffer(pInfo->param.pContext, i >> 16);	/* free buffer */
			}
			pSec->used = 0;
			dmx_err("%s,ch:%d, fail to allocate buffer or add section filter,(ret=%d)!!", __func__,pInfo->ch,i);
			ret = -1;
		} else {
			DEMUX_BUF_T *pBuf = &demux_device->secFilterBuffer;
			RINGBUFFER_HEADER *pRBH = (RINGBUFFER_HEADER *)pSec->rbHeader.virAddr;
			pSec->count = cnt ;
			pSec->firstBufIndex = i >> 16 ;
			pSec->lastBufIndex  = i & 0xffff ;
			/*pSec->isConti = (pSec->lastBufIndex - pSec->firstBufIndex + 1) == cnt ;*/
			memset(pRBH, 0 , sizeof(RINGBUFFER_HEADER));
			pRBH->beginAddr    = (unsigned long)pBuf->phyAddr + (pSec->firstBufIndex * SEC_FILTER_BUFFER_UNIT_SIZE);
			pRBH->size         = (pSec->lastBufIndex - pSec->firstBufIndex + 1) * SEC_FILTER_BUFFER_UNIT_SIZE;
			pRBH->writePtr     = pRBH->beginAddr;
			pRBH->numOfReadPtr = 1;
			pRBH->readPtr[0]   = pRBH->beginAddr;
			pRBH->readPtr[1]   = pRBH->beginAddr;
			pSec->pWrPtr        = &pRBH->writePtr;
			pSec->pRdPtr        = &pRBH->readPtr[0];
			pSec->pBufferLower  = (unsigned char *)pRBH->beginAddr;
			pSec->pBufferUpper  = (unsigned char *)pSec->pBufferLower + pRBH->size;
			pSec->phyAddrOffset = (long)pBuf->phyAddr - (long)pBuf->virAddr;
			pInfo->baseAddr      = demux_device->bufPoll.phyAddr ;
			pInfo->baseAllocSize = demux_device->bufPoll.allocSize ;
			pInfo->headerPhyAddr = pSec->rbHeader.phyAddr;
			pInfo->headerSize    = pSec->rbHeader.allocSize;
			pInfo->allocSize = cnt * SEC_FILTER_BUFFER_UNIT_SIZE;
			pSec->used = 1;

			pCh->secListCB[ret].ch = pInfo->ch;
			memcpy(&pCh->secListCB[ret].param, &pInfo->param, sizeof(TPK_SEC_FILTER_PARAM_T));

			if (!pCh->startStreaming) {
				RHAL_TPStreamControl(pCh->tunerHandle, TP_STREAM_START);
				pCh->startStreaming = 1;
			}
		}
	} else {
		dmx_err("%s, fail to get section index!!", __func__);
	}
	mutex_unlock(&pCh->section_mutex);
	return ret;
}
int IOCTL_CancelSectionFilter(DEMUX_CANCEL_SEC_FILTER_T *pInfo)
{
	demux_channel *pCh;
	dmx_mask_print(DEMUX_SECTION_DEBUG,"func %s, line %d, ch %d secfIndex %d\n", __func__, __LINE__, pInfo->ch, pInfo->secfIndex);
	DEMUX_CHECK_CH(pInfo->ch);
	pCh = &demux_device->pChArray[pInfo->ch];

	if (pInfo->secfIndex >= MAX_SECTION_FILTER_NUM || !pCh->secListCB[pInfo->secfIndex].used) {
		dmx_warn("func %s, line %d,ch:%d, wrong index %d\n", __func__, __LINE__,pInfo->ch,  pInfo->secfIndex);
		return -1;
	}
	if (RHAL_RemoveSectionFilter(pInfo->ch, pCh->secListCB[pInfo->secfIndex].handle) == TPK_SUCCESS) {
		DEMUX_FreeSecIndex(pCh, pInfo->secfIndex);
		return 0;
	}
	dmx_err(DGB_COLOR_RED"FAIL func %s, line %d, ch %d secfIndex %d\n"DGB_COLOR_NONE, __func__, __LINE__, pInfo->ch, pInfo->secfIndex);
	return -1;
}
int IOCTL_AddPESFilter(DEMUX_ADD_PES_FILTER_T *pInfo)
{
	demux_channel *pCh;
	DEMUX_PES_MAP_T   *pPes;
	int i, ret = -1;
	dmx_function_call();
	DEMUX_CHECK_CH(pInfo->ch);
	DEMUX_CHECK_PID(pInfo->pid);
	pCh = &demux_device->pChArray[pInfo->ch];
	if (pInfo->size > PES_FILTER_RING_BUFFER_SIZE) {
		dmx_err("%s, size(%d) to be allocated is larger than used!!", __func__, pInfo->size);
	}
	mutex_lock(&pCh->mutex);
	dmx_mask_print(DEMUX_PES_DEBUG|DEMUX_NOTICE_PRINT,"DEMUX_Add_PESFilter: ch:%d,pid:0x%x, type:%d, size:0x%x\n", pInfo->ch, pInfo->pid, pInfo->pidType, pInfo->size);
	for (i = 0 ; i < MAX_PID_FILTER_CB_NUM ; i++) {
		if (!pCh->pidFilterListCB[i].used) {
			pCh->pidFilterListCB[i].pid        = pInfo->pid;
			pCh->pidFilterListCB[i].pidType    = pInfo->pidType;
			pCh->pidFilterListCB[i].cwIndex    = -1;

			pCh->activePESTarget[i].pid        = -1;
			pCh->activePESTarget[i].bNewTarget = true;
			SET_FLAG(pCh->events, EVENT_UPDATE_PES_LIST);
			pCh->bUpdateDemuxTarget            = true;
			ret = i;
			break;
		}
	}

#ifdef DEMUX_PES_BUFFER_DYNAMIC_ALLOC
	if (ret >= 0){
		pPes = &pCh->pesMap[ret];
		if (pPes->bufferStatus == BUFFER_OFFLINE){
			if (DEMUX_PESBuffer_Alloc(pPes) < 0){
				dmx_err("%s-%d : alloc pes buffer for pid:%x, fail\n", __func__, __LINE__, pInfo->pid);
				pCh->pesMap[ret].occupied = 0;
				pCh->pidFilterListCB[ret].used       = 0;
				pCh->activePESTarget[ret].bNewTarget = true;
				pCh->activePESTarget[ret].pid        = -1;
				ret = -1;
			}
   			dmx_mask_print(DEMUX_PES_DEBUG,"Allocate pesBuffer: ch:%d, pesId:%d, virAddr:%p, phyAddr:%x, limit:%p size: %x\n", pInfo->ch, ret, pPes->virAddr, pPes->phyAddr, pPes->pBufferUpper, PES_FILTER_RING_BUFFER_SIZE);
		}
		else if (pPes->bufferStatus == BUFFER_FREE){
			pPes->bufferStatus = BUFFER_NEW;
			dmx_mask_print(DEMUX_PES_DEBUG,"reuse unfree buffer : ch:%d, pesId:%d, virAddr:%p, phyAddr:%x, limit:%p size: %x\n", pInfo->ch, ret, pPes->virAddr, pPes->phyAddr, pPes->pBufferUpper, PES_FILTER_RING_BUFFER_SIZE);
		}
		else
		{
			dmx_err(" %s-%d : PES Filter status not sync !\n", __func__, __LINE__);
			ret = -1;
		}
	}
#endif
	if (ret >= 0) {
		RINGBUFFER_HEADER *pRBH = NULL;
		//alloc memory
		pPes = &pCh->pesMap[ret];
		pRBH = (RINGBUFFER_HEADER *)pPes->rbHeader.virAddr;

#ifdef DEMUX_PES_BUFFER_DYNAMIC_ALLOC
		pRBH->reserve2 = DEMUX_PESBUFFER_OP_PENDING_FOR_INIT;
		pInfo->baseAddr      = pRBH->beginAddr;
		pInfo->baseAllocSize = pRBH->size ;
#else
		pRBH->writePtr     = pRBH->beginAddr;
		pRBH->numOfReadPtr = 1;
		pRBH->readPtr[0]   = pRBH->beginAddr;
		pRBH->readPtr[1]   = pRBH->beginAddr;
		pInfo->baseAddr      = demux_device->bufPoll.phyAddr ;
		pInfo->baseAllocSize = demux_device->bufPoll.allocSize ;

		pPes->unitSize = 0 ;
		pPes->size = 0 ;
		pPes->curWr = (unsigned char *)(uintptr_t)pRBH->beginAddr;
#endif
		pInfo->headerPhyAddr = pPes->rbHeader.phyAddr;
		pInfo->headerSize    = pPes->rbHeader.allocSize;
		pInfo->allocSize = pRBH->size ;

		pPes->occupied = 1;
		pCh->pidFilterListCB[ret].used       = 1;

		if (!pCh->startStreaming) {
			RHAL_TPStreamControl(pCh->tunerHandle, TP_STREAM_START);
			pCh->startStreaming = 1;
		}
	}
	else
		dmx_err("%s(%d) Fail to Add PES, ch:%d, pid: %d, type: %d, size:0x%x \n", __func__, __LINE__, pInfo->ch, pInfo->pid, pInfo->pidType, pInfo->size);

	mutex_unlock(&pCh->mutex);
	return ret ;
}
int IOCTL_CancelPESFilter(DEMUX_CANCEL_PES_FILTER_T *pInfo)
{
	demux_channel *pCh;
	dmx_function_call();
	DEMUX_CHECK_CH(pInfo->ch);
	pCh = &demux_device->pChArray[pInfo->ch];
	if (pInfo->pesfIndex >= MAX_PID_FILTER_CB_NUM || !pCh->pidFilterListCB[pInfo->pesfIndex].used) {
		dmx_err("func %s, line %d, Error(pesfIndex = %d)!!\n", __func__, __LINE__, pInfo->pesfIndex);
		return -ENOTTY;
	}
	dmx_mask_print(DEMUX_PES_DEBUG|DEMUX_NOTICE_PRINT,"%s_%d, ch:%d, pesId:%d \n", __func__, __LINE__, pInfo->ch, pInfo->pesfIndex);
	mutex_lock(&pCh->mutex);
	pCh->pesMap[pInfo->pesfIndex].occupied = 0;
	pCh->pidFilterListCB[pInfo->pesfIndex].used       = 0;
	pCh->activePESTarget[pInfo->pesfIndex].bNewTarget = true;
	pCh->activePESTarget[pInfo->pesfIndex].pid        = -1;
#ifdef DEMUX_PES_BUFFER_DYNAMIC_ALLOC
	pCh->pesMap[pInfo->pesfIndex].bufferStatus = BUFFER_FREE;
#endif
	SET_FLAG(pCh->events, EVENT_UPDATE_PES_LIST);
	pCh->bUpdateDemuxTarget                           = true;
	mutex_unlock(&pCh->mutex);
	return 0;
}

int IOCTL_FreeFilterBuffer(DEMUX_FREE_FILTER_BUFFER_T *pInfo)
{
	dmx_info("[%s %d] %s, NOT implemented!!\n", __FILE__, __LINE__, __func__) ;
	return 0;
}

int IOCTL_StartPCRRecovery(DEMUX_CHANNEL_T *pInfo)
{
	demux_channel *pCh;
	if( NULL == pInfo )
		return -EFAULT;

	dmx_function_call();
	DEMUX_CHECK_CH(*pInfo);
	pCh = &demux_device->pChArray[*pInfo];
	if (Demux_MW_enablePCRTracking(pCh) < 0)
		return -ENOTTY;
	return 0;
}
int IOCTL_StopPCRRecovery(DEMUX_CHANNEL_T *pInfo)
{
	demux_channel *pCh;
	if( NULL == pInfo )
		return -EFAULT;

	dmx_function_call();

	DEMUX_CHECK_CH(*pInfo);
	pCh = &demux_device->pChArray[*pInfo];
	if (Demux_MW_disablePCRTracking(pCh)<0)
		return -EAGAIN;
	return 0;
}
int IOCTL_ResetFilters(DEMUX_RESET_FILTERS_T *pInfo)
{
	demux_channel *pCh;
	bool bVideo = false, bAudio = false, bPCR = false, bPES = false, bSec = false, bRecordA = false, bRecordB = false, bPVR = false, bTSO = false;
	int i;

	dmx_function_call();
	dmx_notice("%s_%d,ch:%d, scope:%d\n", __func__, __LINE__, pInfo->ch, pInfo->scope);
	DEMUX_CHECK_CH(pInfo->ch);
	pCh = &demux_device->pChArray[pInfo->ch];
	mutex_lock(&pCh->mutex);
	switch (pInfo->scope) {
	case DEMUX_CLEAN_AV:
		bVideo = true, bAudio = true;
		break;
	case DEMUX_CLEAN_VIDEO:
		bVideo = true;
		break;
	case DEMUX_CLEAN_AUDIO:
		bAudio = true;
		break;
	case DEMUX_CLEAN_PCR:
		bPCR = true;
		break;
	case DEMUX_CLEAN_WO_AV:
		bPVR     = true;
		bPES     = true;
		bSec     = true;
		bRecordA = true;
		bRecordB = true;
		break;
	case DEMUX_CLEAN_SECTION:
		bSec = true;
		break;
	case DEMUX_CLEAN_PES:
		bPES = true;
		break;
	case DEMUX_CLEAN_RECORD_A:
		bRecordA = true;
		break;
	case DEMUX_CLEAN_RECORD_B:
		bRecordB = true;
		break;
	case DEMUX_CLEAN_PVR:
		bPVR = true;
		break;
	case DEMUX_CLEAN_ALL:
		bVideo    = true;
		bAudio    = true;
		bPCR      = true;
		bPES      = true;
		bSec      = true;
		bRecordA  = true;
		bRecordB  = true;
		bPVR      = true;
		bTSO	  = true;
		if (pCh->startStreaming) {
			pCh->startStreaming = 0;
		}
	default:
		break;
	}


	if(  bVideo || bAudio || bPCR || bRecordA || bRecordB || bTSO ) {
		for (i = 0; i < pCh->pidFilterCount; i++) {
			if( ( bVideo   && (DEMUX_PID_VIDEO	   == pCh->pidFilterList[i].pidType) ) ||
				( bAudio   && (DEMUX_PID_AUDIO	   == pCh->pidFilterList[i].pidType) ) ||
				( bPCR	   && (DEMUX_PID_PCR	   == pCh->pidFilterList[i].pidType) ) ||
				( bRecordA && (DEMUX_DEST_RECORD_A == pCh->pidFilterList[i].pesDest) ) ||
				( bRecordB && (DEMUX_DEST_RECORD_B == pCh->pidFilterList[i].pesDest) ) ||
				( bTSO	   && (DEMUX_DEST_TSO	   == pCh->pidFilterList[i].pesDest) ) ) {
				if( !pCh->startStreaming )
					pCh->pidFilterList[i].pid = -1;
				else {
					pCh->pidFilterList[i].refCnt--;
					if( 0 >= pCh->pidFilterList[i].refCnt )
						pCh->pidFilterList[i].pid = -1;
				}
			}
		}
		if( bPCR ) {
			pCh->PCRPID = -1;

			RESET_FLAG(pCh->status, STATUS_PCRTAK_START);
			SET_FLAG(pCh->status, STATUS_PCRTAK_STOP);
		}
		SET_FLAG(pCh->events, EVENT_UPDATE_TS_LIST);
	}

	if (bPES) {
		for (i = 0; i < MAX_PID_FILTER_CB_NUM; i++) {
			if (pCh->pidFilterListCB[i].used) {
				pCh->pesMap[i].occupied = 0;
				pCh->pidFilterListCB[i].used = 0;
				pCh->activePESTarget[i].bNewTarget = true;
				pCh->activePESTarget[i].pid        = -1;
			#ifdef DEMUX_PES_BUFFER_DYNAMIC_ALLOC
				pCh->pesMap[i].bufferStatus = BUFFER_FREE;
			#endif
				dmx_mask_print(DEMUX_PES_DEBUG,"%s_%d, canclePesfilter: ch:%d, pesId:%d\n", __func__, __LINE__, pInfo->ch, i);
			}
		}
		SET_FLAG(pCh->events, EVENT_UPDATE_PES_LIST);
	}

	if (bSec) {
		for (i = 0; i < MAX_SECTION_FILTER_NUM; i++) {
			if (pCh->secListCB[i].used) {
				RHAL_RemoveSectionFilter(pInfo->ch, pCh->secListCB[i].handle);
				DEMUX_FreeSecIndex(pCh, i);
				dmx_mask_print(DEMUX_SECTION_DEBUG,"%s_%d, cancleSectionfilter: ch:%d, secId:%d\n", __func__, __LINE__, pInfo->ch, i);
			}
		}
	}
	if (bPVR) {/* TODO */
	}

	pCh->pidFilterCount = IOCTL_RemoveInvalidPIDFilters(pCh->pidFilterList, pCh->pidFilterCount);
	pCh->bUpdateDemuxTarget = true;
	mutex_unlock(&pCh->mutex);
	//WOSQRTK-3607:fix deadlock with callback.
	if (pInfo->scope == DEMUX_CLEAN_ALL)
			RHAL_TPStreamControl(pCh->tunerHandle, TP_STREAM_STOP);
	return 0;
}
int IOCTL_InitDescrambler(DEMUX_INIT_DESCRAMBLER_T *pInfo)
{
	dmx_function_call();
	DEMUX_CHECK_CH(pInfo->ch);
	dmx_notice("BCAS_IntDescramble:ch:%d, alg:%d,round:%d\n",pInfo->ch, pInfo->alg.algo,pInfo->alg.round)
	return (RHAL_SetDescrambleAlgorithm(pInfo->ch, pInfo->alg) == TPK_SUCCESS ? 0 : -1);
}
int IOCTL_SetDescramblerMode(DEMUX_DESCRAMBLER_MODE_T *pInfo)
{
	dmx_function_call();
	DEMUX_CHECK_CH(pInfo->ch);
	return (RHAL_DescrambleControl(pInfo->ch, pInfo->mode) == TPK_SUCCESS ? 0 : -1);
}

int IOCTL_GetCWInfo(DEMUX_DESCRAMBLER_CWINFO_T *pInfo)
{
		dmx_function_call();
		if(pInfo->KeySel>=MAX_DESCRAMBLER_INDEX_NUM)
			return -1;
		pInfo->used = demux_device->cwInfo[pInfo->KeySel].used;
		pInfo->pid = demux_device->cwInfo[pInfo->KeySel].pid;
		pInfo->ch = demux_device->cwInfo[pInfo->KeySel].ch;

		return 0;
}

int IOCTL_SetCW(DEMUX_SET_CW_T *pInfo)
{
	demux_channel *pCh;
	unsigned char *pIV;
	int keySel;
	dmx_function_call();
	DEMUX_CHECK_CH(pInfo->ch);
	pCh = &demux_device->pChArray[pInfo->ch];
	keySel = pCh->CIKeySel < 0 ? pInfo->KeySel : pCh->CIKeySel;
	if (keySel >= demux_device->tpInfo.descrambler_num) {
		dmx_err("func %s, line %d, KeySel %d, maxNum %d\n", __func__, __LINE__, keySel, demux_device->tpInfo.descrambler_num);
		return -1;
	}

	if (_bcase_print_key_info)//for debug
	{
		_bcase_print_key_info = 0;
		dmx_notice("BCAS:SetCW:ch:%d, keytype(0:iv, 1:key):%d, keyid:(0:even, 1:odd):%d, keysel:%d, key[1]:0x%x\n",
			pInfo->ch,pInfo->keyType, pInfo->key_id, pInfo->KeySel, (pInfo->keyType == DEMUX_SET_CW_ONLY_KEY)?pInfo->Key[0]:pInfo->IV[0]);
	}
	pIV = pInfo->key_id == TP_SETCW_KEYID_ODD_KEY ? demux_device->cwInfo[keySel].IV_odd : demux_device->cwInfo[keySel].IV_even;
	if (pInfo->keyType != DEMUX_SET_CW_ONLY_KEY) {/* keep IV to data structure before key set */
		if (pInfo->key_id != TP_SETCW_KEYID_MULTI2_SYS_KEY)
			memcpy(pIV, pInfo->IV, sizeof(pInfo->IV));
	}

	if (pInfo->keyType != DEMUX_SET_CW_ONLY_IV) {
		return (RHAL_SetCW(pInfo->ch, keySel, pInfo->key_id, pInfo->Key, pIV) == TPK_SUCCESS ? 0 : -1);
	} else {
		return 0;
	}
}
int IOCTL_GetDescramblerIndex(DEMUX_GET_DESC_INDEX_T *pInfo)
{
	int i, ret = -1;
	dmx_function_call();
	mutex_lock(&demux_device->mutex);
	for (i = 0; i < demux_device->tpInfo.descrambler_num; i++) {
		if (!demux_device->cwInfo[i].used) {
			demux_device->cwInfo[i].used   = 1;
			demux_device->cwInfo[i].desc=pInfo->algo;
			ret = i;
			RHAL_SetPIDDescrambleAlgorithm(i,pInfo->algo);
			break;
		}
	}
	return ret;
}
int IOCTL_MTPFlush(DEMUX_MTP_FLUSH_T *pInfo)
{
	demux_channel *pCh;
	UINT8 mtp_id;
	MTP_BUFF_FLUSH_MODE_T mode;
	DEMUX_CHECK_CH(pInfo->ch);
	pCh = &demux_device->pChArray[pInfo->ch];

	mtp_id = DEMUX_GET_MTP_ID(pInfo->ch);
	mode = (pInfo->mode == DEMUX_MTP_SYNC_TO_BASE) ? MTP_BUFF_FLUSH_TO_BASE :
		(pInfo->mode == DEMUX_MTP_SYNC_TO_RP ? MTP_BUFF_FLUSH_TO_RP : MTP_BUFF_FLUSH_TO_WP);

	/* Don't start streaming until TP buffer is flushed */
	PVR_EnableTPRateControl(pCh, false);
	RHAL_MTPStreamControl(mtp_id, MTP_STREAM_STOP);

	if (RHAL_MTPFlushBuffer(mtp_id, mode) != TPK_SUCCESS)
		return -1;

	mutex_lock(&pCh->mutex);
	SET_FLAG(pCh->events, EVENT_FLUSH_MTP);

	/* Problem : video freeze 1 ~ 2 sec
	 * Root cause : LG MW won't set speed again when FR 2x -> FR 4x.
                        timeout is reset to 3 sec when DEMUX_ResetAVSync is called.
         * Fiexed by remove DEMUX_ResetAVSync here. */
	/* DEMUX_ResetAVSync(pCh, MTP_AVSYNC_MODE); */
	mutex_unlock(&pCh->mutex);
	return 0;
}
int IOCTL_MTPGetBuffer(DEMUX_PVR_BUF_INFO_T *pInfo)
{
	demux_channel *pCh;

	DEMUX_CHECK_CH(pInfo->ch);
	pCh = &demux_device->pChArray[pInfo->ch];
	if (pCh->mtpBuffer.allocSize == 0) {
		if (DEMUX_BUF_AllocBuffer(&pCh->mtpBuffer,  MTP_BUFFER_SIZE, 1, 0) < 0) {
			dmx_crit("[%s %d] fail to allocate MTP buffer\n", __func__, __LINE__);
			return -1;
		}
		IOCTL_ReConfigTPBuffer(pInfo->ch);
	}
	pInfo->bufPhyAddr = pCh->mtpBuffer.phyAddr;
	pInfo->bufSize = pCh->mtpBuffer.allocSize;
	return 0;
}
int IOCTL_FreeMTPBuf(DEMUX_CHANNEL_T *pInfo)
{
	demux_channel *pCh;
        UINT8 mtp_id;

	dmx_crit("[%s, %d] %s()\n", __FILE__, __LINE__, __func__);
	DEMUX_CHECK_CH(*pInfo);
	pCh = &demux_device->pChArray[*pInfo];
        mtp_id = DEMUX_GET_MTP_ID(*pInfo);
        RHAL_SetMTPBuffer(mtp_id, NULL, NULL, 0); /*Notify TP that mtp buffer was freed*/

	mutex_lock(&pCh->mutex);
	DEMUX_BUF_FreeBuffer(&pCh->mtpBuffer);
	RESET_FLAG(pCh->status, STATUS_AUDIO_PAUSED);
	mutex_unlock(&pCh->mutex);
	return 0;
}
int IOCTL_MTPWriteBuffer(DEMUX_MTP_WRITE_T *pInfo)
{
	demux_channel *pCh;
	UINT8 mtp_id;
	DEMUX_CHECK_CH(pInfo->ch);
	pCh = &demux_device->pChArray[pInfo->ch];

	mtp_id = DEMUX_GET_MTP_ID(pInfo->ch);
	/* printk("%s[%d] writeAddr = 0x%ld, writeSize = %d\n", __func__, __LINE__, pInfo->writeAddr, pInfo->writeSize); */
	if (RHAL_WriteMTPBuffer(mtp_id, (UINT8 *)pInfo->writeAddr, pInfo->writeSize) != TPK_SUCCESS)
		return -1;

	return 0;
}
int IOCTL_MTPGetWriteStatus(DEMUX_MTP_WRITE_STATUS_T *pInfo)
{
	demux_channel *pCh;
	UINT8 *pWritePhyAddr = 0;
	UINT32 contiguousWritableSize = 0;
	UINT32 WritableSize = 0;
	UINT8 mtp_id;
	DEMUX_CHECK_CH(pInfo->ch);
	pCh = &demux_device->pChArray[pInfo->ch];

	mtp_id = DEMUX_GET_MTP_ID(pInfo->ch);

	if (RHAL_GetMTPBufferStatus(mtp_id, &pWritePhyAddr, &contiguousWritableSize, &WritableSize) != TPK_SUCCESS)
		return -1;

	pInfo->writeAddr = (ULONG)pWritePhyAddr;
	pInfo->contiguousWritableSize = contiguousWritableSize;
	pInfo->writableSize = WritableSize;
	return 0;
}
int IOCTL_SetTimeStampPadding(DEMUX_TIMESTAMP_SETTING_T *pInfo)
{
	demux_channel *pCh;
	TPK_TP_STATUS_T tpStatus;

	DEMUX_CHECK_CH(pInfo->ch);
	pCh = &demux_device->pChArray[pInfo->ch];

	if (RHAL_GetTpStatus(pCh->tunerHandle, &tpStatus) != TPK_SUCCESS)
		return -1;

#ifdef DEMUX_REC_HACK_TIMESTAMP
	tpStatus.tp_param.prefix_en= false;
#else
	tpStatus.tp_param.prefix_en = pInfo->bEnable;
#endif
	if (pCh->tp_src == MTP) {
	#ifdef DEMUX_REC_HACK_TIMESTAMP
		tpStatus.tp_param.prefix_en = false; /* timestamp is useless during PVR playback ?! */
		tpStatus.tp_param.frc_en = false;
		tpStatus.tp_param.ts_in_tsp_len = byte_192;
	#else
		/* tpStatus.tp_param.prefix_en = false; */ /* timestamp is useless during PVR playback ?! */
		tpStatus.tp_param.frc_en = pInfo->bEnable;
		tpStatus.tp_param.ts_in_tsp_len = (pInfo->bEnable) ? byte_192 : byte_188;
	#endif
	}

	if (RHAL_SetTPMode(pCh->tunerHandle, tpStatus.tp_param) != TPK_SUCCESS)
		return -1;

	IOCTL_ReConfigTPBuffer(pInfo->ch);
	return 0;
}
int IOCTL_SetTPParam(DEMUX_TP_PARAM_T *pInfo)
{
	demux_channel *pCh;

	DEMUX_CHECK_CH(pInfo->ch);
	pCh = &demux_device->pChArray[pInfo->ch];

	if (RHAL_SetTPMode(pCh->tunerHandle, pInfo->tpParam) != TPK_SUCCESS)
		return -1;
	IOCTL_CheckAvSync(pCh);

	return 0;
}
int IOCTL_GetTPParam(DEMUX_TP_PARAM_T *pInfo)
{
	demux_channel *pCh;
	TPK_TP_STATUS_T tpStatus;

	DEMUX_CHECK_CH(pInfo->ch);
	pCh = &demux_device->pChArray[pInfo->ch];

	if (RHAL_GetTpStatus(pCh->tunerHandle, &tpStatus) != TPK_SUCCESS)
		return -1;

	pInfo->tpParam = tpStatus.tp_param;
	return 0;
}
int IOCTL_SetTPSource(DEMUX_TP_SOURCE_T *pInfo)
{
	demux_channel *pCh;

	DEMUX_CHECK_CH(pInfo->ch);
	pCh = &demux_device->pChArray[pInfo->ch];

	if (RHAL_SetTPSource(pCh->tunerHandle, pInfo->tpSrc, pInfo->casType) != TPK_SUCCESS)
		return -1;

	if (pInfo->tpSrc == MTP && pCh->mtpBuffer.allocSize == 0) {
		if (DEMUX_BUF_AllocBuffer(&pCh->mtpBuffer,  MTP_BUFFER_SIZE, 1, 0) < 0)
			return -1;

	}
	IOCTL_ReConfigTPBuffer(pInfo->ch);
	IOCTL_CheckAvSync(pCh);
	return 0;
}
int IOCTL_GetTPSource(DEMUX_TP_SOURCE_T *pInfo)
{
	demux_channel *pCh;
	TPK_TP_STATUS_T tpStatus;

	DEMUX_CHECK_CH(pInfo->ch);
	pCh = &demux_device->pChArray[pInfo->ch];

	if (RHAL_GetTpStatus(pCh->tunerHandle, &tpStatus) != TPK_SUCCESS)
		return -1;

	pInfo->tpSrc = tpStatus.tp_src;
	return 0;
}
int IOCTL_SetPrivateInfo(DEMUX_PRIVATE_INFO_T *pInfo)
{
	demux_channel *pCh;
	int ret = 0;
	dmx_info(
		"func %s, line %d, ch %d, dest %d, info %lu\n",
		__func__, __LINE__, pInfo->ch, pInfo->dest, (unsigned long)pInfo->data[0]
	);
	DEMUX_CHECK_CH(pInfo->ch);
	if (pInfo->dest != DEMUX_DEST_ADEC0 && pInfo->dest != DEMUX_DEST_ADEC1 && pInfo->dest != DEMUX_DEST_VDEC0 && pInfo->dest != DEMUX_DEST_VDEC1) {
		dmx_err("func %s, line %d, dest(%d) is wrong!!\n", __func__, __LINE__, pInfo->dest);
		return -1;
	}
	pCh = &demux_device->pChArray[pInfo->ch];
	mutex_lock(&pCh->mutex);
	switch ((DEMUX_PRIVATEINFO_T)pInfo->data[0]) {
	case DEMUX_PRIVATEINFO_NOTIFY_FLUSHED:
		{
			int status;
			dmx_notice("(%s-%d): DEMUX_PRIVATEINFO_NOTIFY_FLUSHED: dest:%d \n", __FILE__, __LINE__, pInfo->dest);
			status = pInfo->dest == DEMUX_DEST_ADEC0 ? STATUS_SET_AUDIO_FLUSH  :
				pInfo->dest == DEMUX_DEST_ADEC1 ? STATUS_SET_AUDIO2_FLUSH :
				pInfo->dest == DEMUX_DEST_VDEC0 ? STATUS_SET_VIDEO_FLUSH  : STATUS_SET_VIDEO2_FLUSH;
			if (status == STATUS_SET_VIDEO_FLUSH || status == STATUS_SET_VIDEO2_FLUSH) {
				pCh->videoDecodeMode[status == STATUS_SET_VIDEO_FLUSH ? 0 : 1] = pInfo->data[1];
				rtkdemux_dbg_dump_ts_flush_enable(pInfo->ch);
			}
			SET_FLAG(pCh->status, status);
			break;
		}
	case DEMUX_PRIVATEINFO_AUDIO_FORMAT:
		{
			dmx_notice("(%s-%d): DEMUX_PRIVATEINFO_AUDIO_FORMAT: dest:%d \n", __FILE__, __LINE__, pInfo->dest);
			if (pInfo->dest == DEMUX_DEST_ADEC0) {
				SET_FLAG(pCh->status, STATUS_SET_AUDIO_FORMAT);
				pCh->audioFormat = pInfo->data[1];
				memset(pCh->audioPrivateInfo, 0, sizeof(pCh->audioPrivateInfo));
				memcpy(pCh->audioPrivateInfo, &pInfo->data[2], sizeof(ULONG)*8);
			} else {
				SET_FLAG(pCh->status, STATUS_SET_AUDIO2_FORMAT);
				pCh->audioFormat2 = pInfo->data[1];
				memset(pCh->audioPrivateInfo2, 0, sizeof(pCh->audioPrivateInfo2));
				memcpy(pCh->audioPrivateInfo2, &pInfo->data[2], sizeof(ULONG)*8);
			}
			break;
		}
	case DEMUX_PRIVATEINFO_VIDEO_DECODE_MODE:
	{
		int port = (pInfo->dest == DEMUX_DEST_VDEC1);
		pCh->videoDecodeMode[port] = (DECODE_MODE)pInfo->data[1];
		SET_FLAG(pCh->events, (port == 0) ? EVENT_VIDEO0_NEW_DECODE_MODE : EVENT_VIDEO1_NEW_DECODE_MODE);
		dmx_info("[%s %d] VDEC%d decode mode = %d\n", __func__, __LINE__, port, pCh->videoDecodeMode[port]);
		break;
	}
	case DEMUX_PRIVATEINFO_VIDEO_FREERUN_THRESHOLD:
	{
		ULONG ulTemp = 0;
		if( (ulTemp - 1) != pInfo->data[1]) {
			pCh->videoFreeRunThreshold = pInfo->data[1];
		} else {
			pCh->videoFreeRunThreshold = DEFAULT_FREE_RUN_VIDEO_THRESHOLD;
		}
		break;
	}
	case DEMUX_PRIVATEINFO_AUDIO_PAUSE:
	{
		/* Because audio trick play mode is wrong in some cases, for example, double PAUSE,
		 * we reset this status at PVR upload speed is change to play
		 */
		SET_FLAG(pCh->status, STATUS_AUDIO_PAUSED);
		break;
	}
	case DEMUX_PRIVATEINFO_APVR_PLAYBACK_START:
	{
		/* To nitify H264 format which was encoded by our VENC module.
		 * Don't start TP rate control when play APVR file.
		 */
		SET_FLAG(pCh->status, STATUS_APVR_PLAYBACK_START);
		mutex_unlock(&pCh->mutex);
		PVR_EnableTPRateControl(pCh, false);
		dmx_crit("[%s, %d] DEMUX_PRIVATEINFO_APVR_PLAYBACK_START\n", __func__, __LINE__);
		return ret;
	}
	default:
		ret = -1;
		break;
	}
	mutex_unlock(&pCh->mutex);
	if (ret < 0)
		dmx_err("(%s -%d): unKnow Command: %d \n",  __FILE__, __LINE__,(DEMUX_PRIVATEINFO_T)pInfo->data[0]);
	return ret;
}
int IOCTL_ReConfigTPBuffer(DEMUX_CHANNEL_T ch)
{
	SINT32 tpAlignment, tpBufAlignment, mtpAlignment;
	TPK_TP_STATUS_T tpStatus;
	UINT8 mtp_id;
	demux_channel *pCh = &demux_device->pChArray[ch];

	if (RHAL_GetTpStatus(pCh->tunerHandle, &tpStatus) != TPK_SUCCESS)
		return -1;

	mtp_id = DEMUX_GET_MTP_ID(ch);

	tpBufAlignment = tpStatus.tp_param.prefix_en ? (MIN_UPLOAD_SIZE_FOR_192*2) : (188*1024*2);
	tpAlignment    = tpStatus.tp_param.prefix_en ? 192 : 188;
	mtpAlignment   = (tpStatus.tp_param.ts_in_tsp_len == byte_192) ? 192 : 188;
	pCh->tsPacketSize  = tpAlignment;

	/* buffer is packet-aligned. */
	if ((pCh->tpBuffer.size % tpBufAlignment) == 0) {
		if (tpStatus.tp_src != MTP)
		return 0;

	}
	/* if tp starts streaming already, stop it. */
	if (tpStatus.tp_stream_status == TP_STREAM_START)
		RHAL_TPStreamControl(pCh->tunerHandle, TP_STREAM_STOP);

	if (pCh->tpBuffer.size % tpBufAlignment) {
		int tpBufSize, tpDataSize;
		RINGBUFFER_HEADER *pHeader    = (RINGBUFFER_HEADER *)pCh->tpBufferH.virAddr;
		DEMUX_BUF_T       *pBuf       = &pCh->tpBuffer;

		pBuf->size = pBuf->allocSize - (pBuf->allocSize % tpBufAlignment);
		RHAL_SetTPRingBuffer(pCh->tunerHandle, (UINT8 *)pBuf->phyAddr, (UINT8 *)pBuf->nonCachedaddr, pBuf->size);

		tpBufSize = 0;
		tpDataSize = 0;
		if (RHAL_GetTPBufferStatus(pCh->tunerHandle, &tpBufSize, &tpDataSize) == TPK_SUCCESS && tpBufSize != pBuf->size) {
			dmx_crit("[%s %d] buf size not matched: tpBufSize = %d, org = %d\n", __func__, __LINE__, tpBufSize,  pBuf->size);
			pBuf->size = tpBufSize;
		}

		pHeader->size             = pBuf->size;
		pHeader->beginAddr        = pBuf->phyAddr;
		pHeader->writePtr         = pBuf->phyAddr;
		pHeader->readPtr[0]       = pBuf->phyAddr;
		pHeader->readPtr[1]       = pBuf->phyAddr;

		dmx_info(
			"[%s %d] TP readPtr[0] = 0x%lx, readPtr[1] = 0x%lx, writePtr = 0x%lx\n",
			__func__, __LINE__, pHeader->readPtr[0], pHeader->readPtr[1], pHeader->writePtr
		);
		if (RHAL_DumpTPRingBuffer(pCh->tunerHandle, pCh->bStartRec, (UINT8 *)&pHeader->readPtr[0], (UINT8 *)&pHeader->writePtr) != TPK_SUCCESS)
			return -1;


	}

	if (tpStatus.tp_src == MTP && pCh->mtpBuffer.allocSize > 0) {
		pCh->mtpBuffer.size = pCh->mtpBuffer.allocSize - (pCh->mtpBuffer.allocSize % (mtpAlignment*1024)) - mtpAlignment*1024; /*reserve one 192k to handle wrap-around*/
		dmx_crit("[%s %d] pCh->mtpBuffer.phyAddr = 0x%x\n", __func__, __LINE__, pCh->mtpBuffer.phyAddr);
		RHAL_SetMTPBuffer(mtp_id, (UINT8 *)pCh->mtpBuffer.phyAddr, (UINT8 *)pCh->mtpBuffer.virAddr, pCh->mtpBuffer.size);
	}
	/* re-start tp if necessary */
	if (tpStatus.tp_stream_status == TP_STREAM_START)
		RHAL_TPStreamControl(pCh->tunerHandle, TP_STREAM_START);

	return 0;
}

int IOCTL_SetTPStreamControl(DEMUX_TP_STREAM_CONTROL_T *pInfo)
{
	demux_channel *pCh;
	dmx_function_call();
	DEMUX_CHECK_CH(pInfo->ch);
	pCh = &demux_device->pChArray[pInfo->ch];
	if (pCh->startStreaming && pInfo->ctrl == TP_STREAM_STOP) {
		RHAL_TPStreamControl(pCh->tunerHandle, pInfo->ctrl);
		/*RHAL_TPFlushBuffer(pCh->tunerHandle);*/
		pCh->startStreaming = 0;
	} else if (!pCh->startStreaming && pInfo->ctrl == TP_STREAM_START) {
		RHAL_TPStreamControl(pCh->tunerHandle, pInfo->ctrl);
		pCh->startStreaming = 1;
	} else {
		dmx_notice("func %s, line %d, tp %d, donothing, startStreaming %d, ctrl %d\n", __func__, __LINE__, pCh->tunerHandle, pCh->startStreaming, pInfo->ctrl);
	}

	return 0;
}
int IOCTL_SetRecStatus(DEMUX_REC_STATUS_T *pInfo)
{
	demux_channel *pCh;
	RINGBUFFER_HEADER *pHeader = 0;
	DEMUX_PVR_BUF_INFO_T bufInfo;

	DEMUX_CHECK_CH(pInfo->ch);

	pCh = &demux_device->pChArray[pInfo->ch];

	bufInfo.ch = pInfo->ch;
	if(IOCTL_GetTPInfoBuffer(&bufInfo) >= 0) {
		DEMUX_BUF_T *pInfoBuf = &pCh->tpInfoBuffer;
		pHeader = (RINGBUFFER_HEADER *)(pCh->tpInfoBufferH.virAddr);
		if (RHAL_SetTPPatternSearchInfoBuffer(pCh->tunerHandle, (UINT8 *)pInfoBuf->phyAddr, (UINT8 *)pInfoBuf->nonCachedaddr, pInfoBuf->size, (UINT8 *)&pHeader->readPtr[0], (UINT8 *)&pHeader->writePtr) != TPK_SUCCESS) {
			dmx_crit("[%s %d] CH%d fail to set TP info buf\n", __func__, __LINE__, pCh->tunerHandle);
			return -1;
		}
	}
	pHeader = (RINGBUFFER_HEADER *)(pCh->tpBufferH.virAddr);
	if (RHAL_DumpTPRingBuffer(pCh->tunerHandle, pInfo->bStartRec, (UINT8 *)&pHeader->readPtr[0], (UINT8 *)&pHeader->writePtr) != TPK_SUCCESS)
		return -1;
	pHeader->readPtr[1] = pHeader->readPtr[0];

	dmx_mask_print(DEMUX_NOMAL_DEBUG,"[%s %d] download buffer is TP buffer. bStartRec = %d\n", __func__, __LINE__, pInfo->bStartRec);
	pCh->bStartRec = pInfo->bStartRec;
	if (pInfo->bStartRec == false) {
		pHeader->readPtr[0] = pHeader->readPtr[1] = pHeader->writePtr = pHeader->beginAddr;

		//flush info buffer
		pHeader = (RINGBUFFER_HEADER *)(pCh->tpInfoBufferH.virAddr);
		pHeader->readPtr[0] = pHeader->readPtr[1] = pHeader->writePtr = pHeader->beginAddr;
	}
	return 0;
}
int IOCTL_SetMtpStreaming(DEMUX_MTP_STREAMING_STATUS_T *pInfo)
{
	demux_channel *pCh;
	UINT8 mtp_id;
	DEMUX_CHECK_CH(pInfo->ch);

	pCh = &demux_device->pChArray[pInfo->ch];
	mtp_id = DEMUX_GET_MTP_ID(pInfo->ch);
	mutex_lock(&pCh->mutex);
	if(HAS_FLAG(pCh->events, EVENT_FLUSH_MTP))
	{
		RESET_FLAG(pCh->events, EVENT_FLUSH_MTP);
	}
	RESET_FLAG(pCh->status, STATUS_APVR_PLAYBACK_START);
	mutex_unlock(&pCh->mutex);

        /*Allocate mtp buffer first, before start MTP streaming*/
        if(pInfo->bStartStreaming)
        {
            if (pCh->mtpBuffer.allocSize == 0) {
                if (DEMUX_BUF_AllocBuffer(&pCh->mtpBuffer, MTP_BUFFER_SIZE, 1, 0) < 0) {
                    dmx_crit("[%s %d] fail to allocate MTP buffer\n", __func__, __LINE__);
                    return -1;
                }
                IOCTL_ReConfigTPBuffer(pInfo->ch);
            }
        }

	if (TPK_SUCCESS != RHAL_MTPStreamControl(mtp_id, pInfo->bStartStreaming ? MTP_STREAM_START : MTP_STREAM_STOP))
		return -1;

	pCh->pvrSpeed = 256;
	if (pInfo->bStartStreaming == MTP_STREAM_START)
		rtkdemux_dbg_dump_ts_flush_enable(pInfo->ch);
	return 0;
}
int IOCTL_GetBufferInfoEX(DEMUX_BUF_INFO_EX_T *pInfo)
{
	demux_channel *pCh;
	DEMUX_BUF_T   *pBS;
	dmx_function_call();
	DEMUX_CHECK_CH(pInfo->ch);

	pCh = &demux_device->pChArray[pInfo->ch];


	switch (pInfo->bufferType){
#ifndef DEMUX_PES_BUFFER_DYNAMIC_ALLOC
		case DEMUX_BUFFER_TYPE_PES: 				pBS = &pCh->pesFilterBuffer; break;
#endif
		case DEMUX_BUFFER_TYPE_SECTION:				pBS = &demux_device->secFilterBuffer; break;
		case DEMUX_BUFFER_TYPE_REFCLOCK:			pBS = &pCh->refClockBuffer; break;
		case DEMUX_BUFFER_TYPE_BUFFERHEADERPOOL:	pBS = &demux_device->bufPoll; break;
		default: pBS = NULL;
	}
	if (pBS) {
		pInfo->phyAddr = (UINT32) pBS->phyAddr;
		pInfo->size    = (UINT32) pBS->allocSize;
		return 0;
	} else {
		dmx_err("func %s, line %d, don't support filterType (%d)!!\n", __func__, __LINE__, pInfo->bufferType);
		return -ENOTTY;
	}
}

int IOCTL_SetPidDescrambler(DEMUX_ENABLE_DESCRAMBLER_T *pInfo)
{
	demux_channel *pCh;
	int i, target;
	dmx_function_call();
	if (pInfo->KeySel >= demux_device->tpInfo.descrambler_num || !demux_device->cwInfo[pInfo->KeySel].used) {
		dmx_err("func %s, line %d, KeySel %d, maxNum %d\n", __func__, __LINE__, pInfo->KeySel, demux_device->tpInfo.descrambler_num);
		return -1;
	}
	DEMUX_CHECK_CH(pInfo->ch);
	pCh = &demux_device->pChArray[pInfo->ch];
	mutex_lock(&pCh->mutex);
	dmx_notice("BCAS_setPID: ch:%d, pid:0x%x,type:%d, enable:%d, key:%d\n",pInfo->ch, pInfo->pid, pInfo->pidType, pInfo->bEnable, pInfo->KeySel);

	for (i = 0; i < pCh->pidFilterCount; i++) {
		if (pCh->pidFilterList[i].pid == pInfo->pid && pCh->pidFilterList[i].pidType == pInfo->pidType) {
			break;
		}
	}
	if(pInfo->pidType ==DEMUX_PID_AUDIO || pInfo->pidType == DEMUX_PID_VIDEO)
		_bcase_print_key_info = true;//print after set audio/video descramble

	/* It means there no the same PID in pidFilterList. */
	if (i == pCh->pidFilterCount) {
		pCh->pidFilterList[i].pid     = pInfo->pid;
		pCh->pidFilterList[i].pidType = pInfo->pidType;
		pCh->pidFilterList[i].pesDest = DEMUX_DEST_TSO;
		pCh->pidFilterList[i].refCnt  = 1;
		target = GetTargetIdxFromType(pCh->pidFilterList[i].pidType, pCh->pidFilterList[i].pesDest);
		if (target >= 0 && pCh->activeTarget[target].pid != pCh->pidFilterList[i].pid) {
			pCh->activeTarget[target].bNewTarget = true;
			pCh->activeTarget[target].pid        = pCh->pidFilterList[i].pid;
		}

		pCh->pidFilterCount++;
	} else {
		/* There was already been added, just increase refCnt.  */
		pCh->pidFilterList[i].refCnt  += 1;
	}

	pCh->pidFilterList[i].cwIndex      = pInfo->KeySel;
	pCh->pidFilterList[i].enDescramble = pInfo->bEnable;

	/*
	   if (demux_device->cwInfo[pInfo->KeySel].pid == 0xffff)
	   {
	   demux_device->cwInfo[pInfo->KeySel].ch  = pInfo->ch;
	   demux_device->cwInfo[pInfo->KeySel].pid = pInfo->pid;
	   }
	 */
	SET_FLAG(pCh->events, EVENT_UPDATE_TS_LIST);
	pCh->bUpdateDemuxTarget = true;
	mutex_unlock(&pCh->mutex);

	return 0;
}
int IOCTL_IsPidActive(DEMUX_IS_PID_ACTIVE_T *pInfo)
{
	demux_channel *pCh;
	int i, ret = -1;
	dmx_function_call();
	DEMUX_CHECK_CH(pInfo->ch);
	pCh = &demux_device->pChArray[pInfo->ch];
	mutex_lock(&pCh->mutex);
	for (i = 0; i < pCh->pidFilterCount; i++) {
		if (pCh->pidFilterList[i].pid == pInfo->pid && pCh->pidFilterList[i].pidType == pInfo->pidType) {
			ret = pCh->pidFilterList[i].cwIndex;
			break;
		}
	}
	mutex_unlock(&pCh->mutex);

	return ret;
}
int IOCTL_ClearDescrambler(DEMUX_CLEAR_DESCRAMBLER_T *pInfo)
{
	demux_channel *pCh;
	int i;

	dmx_function_call();
	DEMUX_CHECK_CH(pInfo->ch);
	pCh = &demux_device->pChArray[pInfo->ch];
	mutex_lock(&pCh->mutex);
	dmx_notice("BCAS_ClearPid: ch:%d, type:%d, pid:0x%x,  key:%d\n",pInfo->ch, pInfo->pidType, pInfo->pid, pInfo->KeySel);

	for (i = 0; i < pCh->pidFilterCount; i++) {
		if (pCh->pidFilterList[i].pid == pInfo->pid && pCh->pidFilterList[i].pidType == pInfo->pidType) {
			pCh->pidFilterList[i].refCnt--;
			if( 0 == pCh->pidFilterList[i].refCnt )
				pCh->pidFilterList[i].pid = -1;

			pCh->pidFilterList[i].cwIndex = -1;
			pCh->pidFilterList[i].enDescramble = 0;
			SET_FLAG(pCh->events, EVENT_UPDATE_TS_LIST);
			pCh->bUpdateDemuxTarget = true;
		}
	}

	pCh->pidFilterCount = IOCTL_RemoveInvalidPIDFilters(pCh->pidFilterList, pCh->pidFilterCount);
	if (pCh->pidFilterCount == 0){
		dmx_notice("BCAS_ClearPid : ch:%d,  DEMUX_PRIVATEINFO_FLUSHTP \n", pInfo->ch);
		dmx_notice("(%s-%d): DEMUX_PRIVATEINFO_FLUSHTP -ch:%d filteramask: %x \n", __FILE__, __LINE__,pInfo->ch,DEMUX_checkFilterCount(pCh));
		SET_FLAG(pCh->events, EVENT_FLUSH_TP);
	}
	mutex_unlock(&pCh->mutex);
	return 0;
}
int IOCTL_EnableDescrambler(DEMUX_SWITCH_DESCRAMBLER_T *pInfo)
{
	demux_channel *pCh;
	int i , ret = -1;
	dmx_function_call();
	if (pInfo->KeySel >= demux_device->tpInfo.descrambler_num || !demux_device->cwInfo[pInfo->KeySel].used) {
		dmx_err("func %s, line %d, KeySel %d, maxNum %d\n", __func__, __LINE__, pInfo->KeySel, demux_device->tpInfo.descrambler_num);
		return -1;
	}
	DEMUX_CHECK_CH(pInfo->ch);
	pCh = &demux_device->pChArray[pInfo->ch];
	mutex_lock(&pCh->mutex);

	for (i = 0; i < pCh->pidFilterCount; i++) {
		if (pCh->pidFilterList[i].pid == pInfo->pid) {
		dmx_notice("BCAS_EnableDescramble: ch:%d, pid:0x%x, enable:%d, key:%d\n",pInfo->ch, pInfo->pid, pInfo->bEnable, pInfo->KeySel);
		pCh->pidFilterList[i].cwIndex      = pInfo->KeySel;
		pCh->pidFilterList[i].enDescramble = pInfo->bEnable;
		SET_FLAG(pCh->events, EVENT_UPDATE_TS_LIST);
		pCh->bUpdateDemuxTarget = true;
			ret ++;
		}
	}

	if (ret < 0) {
		dmx_notice(
			"BCAS_EnableDescramble Filter not exist: ch:%d, pid:0x%x\n",
			pInfo->ch, pInfo->pid
		);
	}

	mutex_unlock(&pCh->mutex);

	return ret;
}
int IOCTL_SetCIChannel(DEMUX_SET_CI_CHANNEL_T *pInfo)
{
	demux_channel *pCh;
	int i;
	dmx_function_call();
	DEMUX_CHECK_CH(pInfo->ch);
	pCh = &demux_device->pChArray[pInfo->ch];

	if (pInfo->bCI && pCh->CIKeySel < 0) {
		DEMUX_GET_DESC_INDEX_T desc_idx;
		desc_idx.algo.algo=TPK_DESCRAMBLE_ALGO_NONE;
		desc_idx.algo.round=0;
		pCh->CIKeySel = IOCTL_GetDescramblerIndex(&desc_idx);
		if (pCh->CIKeySel < 0)
			return -1;
	} else if (!pInfo->bCI && pCh->CIKeySel >= 0) {
		demux_device->cwInfo[pCh->CIKeySel].used = 0;
		pCh->CIKeySel = -1;
	} else {
		return 0;  /* donothing */
	}

	if (pCh->pidFilterCount) {
		mutex_lock(&pCh->mutex);
		for (i = 0; i < pCh->pidFilterCount; i++) {
			pCh->pidFilterList[i].cwIndex      = pCh->CIKeySel;
			pCh->pidFilterList[i].enDescramble = pCh->CIKeySel >= 0;
		}
		SET_FLAG(pCh->events, EVENT_UPDATE_TS_LIST);
		pCh->bUpdateDemuxTarget = true;
		mutex_unlock(&pCh->mutex);
	}
	return pInfo->bCI ? pCh->CIKeySel : 0;
}


int IOCTL_GetHardwareInfo(DEMUX_GET_TP_HARDWARE_INFO_T *pInfo)
{
	return (RHAL_GetHardwareInfo(&pInfo->tpInfo) == TPK_SUCCESS) ? 0 : -1;
}

int IOCTL_DebugInfo(DEMUX_DEBUG_INFO_T *pInfo)
{
	demux_channel *pCh;
	int i;
	dmx_function_call();
	DEMUX_CHECK_CH(pInfo->ch);
	pCh = &demux_device->pChArray[pInfo->ch];
	switch (pInfo->eType) {
	case DEMUX_DEBUG_PRINT_PID_LIST:
		{
			dmx_mask_print(DEMUX_PID_DEBUG,"DEMUX_DEBUG_PRINT_PID_LIST:\n");
			for (i = 0; i < pCh->pidFilterCount; i++) {
				dmx_mask_print(DEMUX_PID_DEBUG,"ch:%d, pid 0x%x, pidType %d, pesDest %d, cwIndex %d, enDescramble %d\n",pInfo->ch, pCh->pidFilterList[i].pid, pCh->pidFilterList[i].pidType, pCh->pidFilterList[i].pesDest, pCh->pidFilterList[i].cwIndex, pCh->pidFilterList[i].enDescramble);
			}
			break;
		}
	case DEMUX_DEBUG_PRINT_PID_FOR_PES:
		{
			dmx_notice("DEMUX_DEBUG_PRINT_PID_LIST:\n");
			for (i = 0; i < MAX_PID_FILTER_CB_NUM; i++) {
				if (pCh->pidFilterListCB[i].used) {
					dmx_mask_print(DEMUX_PID_DEBUG,"ch: %d ,idx %d, 0x%x, pidType %d, cwIndex %d\n",pInfo->ch, i, pCh->pidFilterListCB[i].pid, pCh->pidFilterListCB[i].pidType, pCh->pidFilterListCB[i].cwIndex);
				}
			}
			break;
		}
	default:
		break;
	}

	return 0;
}

/*
 *   This function can set multiple PID
 */
int IOCTL_SetPidActive(DEMUX_SET_MULTI_PID_T *pInfo)
{
	demux_channel *pCh;
	int i, j;
	DEMUX_PES_DEST_T orgDest = DEMUX_DEST_NONE;
	dmx_function_call();
	DEMUX_CHECK_CH(pInfo->ch);
	if (pInfo->count > DEMUX_MAX_NUM_TO_SET)
		return -1;

	pCh = &demux_device->pChArray[pInfo->ch];
	mutex_lock(&pCh->mutex);
	for (j = 0; j < pInfo->count; j++) {
		for (i = 0; i < pCh->pidFilterCount; i++) {
			/* get original destination and set to new destination */
				  DEMUX_PID_LIST_T* const entry  = &pCh->pidFilterList[i];
			const DEMUX_SET_PID_T * const target = &pInfo->pidlist[j];
			if (entry->pid == target->pid
				&& entry->pidType == target->pidType) {

				dmx_notice(
					"DEMUX_SetPidActive: ch:%d, pid: 0x%x, type: %d"
					", dest: %d->%d\n",
					pInfo->ch, entry->pid, entry->pidType,
					entry->pesDest, target->dest
				);

				orgDest = entry->pesDest;
				entry->pesDest = target->dest;
				break;
			}
		}

		if (i == pCh->pidFilterCount) {
			dmx_err("func %s, line %d, pid(%d) hasn't existed in list\n", __func__, __LINE__, pInfo->pidlist[j].pid);
			continue;
		}
		/*
		   for (i = 0; i < pCh->pidFilterCount; i++)
		   {
		   if (pCh->pidFilterList[i].pesDest == pInfo->pidlist[j].dest && pCh->pidFilterList[i].pid != pInfo->pidlist[j].pid)
		   {
		   pCh->pidFilterList[i].pesDest = orgDest;
		   break;
		   }
		   }
		 */
		SET_FLAG(pCh->events, EVENT_UPDATE_TS_LIST);
		if (pInfo->pidlist[j].pidType == DEMUX_PID_PCR && pCh->PCRPID != pInfo->pidlist[j].pid) {
			pCh->PCRPID = pInfo->pidlist[j].pid;
			if (0 < pCh->PCRPID && pCh->PCRPID < 0x1FFF) {
				SET_FLAG(pCh->status, STATUS_PCRTAK_START);
			}
			else{
				RESET_FLAG(pCh->status, STATUS_PCRTAK_START);
				SET_FLAG(pCh->status, STATUS_PCRTAK_STOP);
			}
		}
		pCh->bUpdateDemuxTarget = true;
	}
	mutex_unlock(&pCh->mutex);

	return 0;
}

int IOCTL_SetPIDs(DEMUX_SET_MULTI_PID_T *pInfo)
{
	demux_channel *pCh;
	int i, j, k, target;
	dmx_function_call();
	DEMUX_CHECK_CH(pInfo->ch);
	if (pInfo->count > DEMUX_MAX_NUM_TO_SET)
		return -1;
	pCh = &demux_device->pChArray[pInfo->ch];
	mutex_lock(&pCh->mutex);
	for (k = 0; k < pInfo->count; k++) {
		for (i = 0; i < pCh->pidFilterCount; i++) {
			if (pCh->pidFilterList[i].pid == pInfo->pidlist[k].pid && pCh->pidFilterList[i].pidType == pInfo->pidlist[k].pidType && pCh->pidFilterList[i].pesDest == pInfo->pidlist[k].dest) {
				dmx_err("func %s, line %d, pid(%d) has existed in list\n", __func__, __LINE__, pInfo->pidlist[k].pid);
				continue;
			}
		}

		if (i == pCh->pidFilterCount) {
			pCh->pidFilterList[i].pid     = pInfo->pidlist[k].pid;
			pCh->pidFilterList[i].pidType = pInfo->pidlist[k].pidType;
			pCh->pidFilterList[i].pesDest = pInfo->pidlist[k].dest;
			pCh->pidFilterList[i].cwIndex = -1;
			pCh->pidFilterList[i].enDescramble = 0;
			pCh->pidFilterList[i].refCnt       = 1;
			target = GetTargetIdxFromType(pCh->pidFilterList[i].pidType, pCh->pidFilterList[i].pesDest);
			if (target >= 0 && pCh->activeTarget[target].pid != pCh->pidFilterList[i].pid) {
				pCh->activeTarget[target].bNewTarget = true;
				pCh->activeTarget[target].pid        = pCh->pidFilterList[i].pid;
			}

			if (pCh->CIKeySel >= 0) {
				pCh->pidFilterList[i].cwIndex = pCh->CIKeySel;
				pCh->pidFilterList[i].enDescramble = 1;
			} else {
				for (j = 0; j < demux_device->tpInfo.descrambler_num; j++) {
					if (demux_device->cwInfo[j].used && demux_device->cwInfo[j].pid == pCh->pidFilterList[i].pid && demux_device->cwInfo[j].ch == pInfo->ch) {
						pCh->pidFilterList[i].cwIndex = j;
						pCh->pidFilterList[i].enDescramble = 1;
						break;
					}
				}
			}
			pCh->pidFilterCount++;
		} else {
			/* There was already been added, just increase refCnt.	*/
			pCh->pidFilterList[i].refCnt  += 1;
		}

		SET_FLAG(pCh->events, EVENT_UPDATE_TS_LIST);
		if (pInfo->pidlist[k].pidType == DEMUX_PID_PCR && pCh->PCRPID != pInfo->pidlist[k].pid) {
			pCh->PCRPID = pInfo->pidlist[k].pid;
			if (0 < pCh->PCRPID && pCh->PCRPID < 0x1FFF) {
				SET_FLAG(pCh->status, STATUS_PCRTAK_START);
			}
			else{
				RESET_FLAG(pCh->status, STATUS_PCRTAK_START);
				SET_FLAG(pCh->status, STATUS_PCRTAK_STOP);
			}
		}
		pCh->bUpdateDemuxTarget = true;
		if (!pCh->startStreaming) {
			RHAL_TPStreamControl(pCh->tunerHandle, TP_STREAM_START);
			pCh->startStreaming = 1;
		}
	}
	mutex_unlock(&pCh->mutex);

	return 0;
}

int IOCTL_RemovePIDs(DEMUX_REMOVE_PID_T *pInfo)
{
	demux_channel *pCh;
	int i, j;
	dmx_function_call();
	DEMUX_CHECK_CH(pInfo->ch);

	if (pInfo->count > DEMUX_MAX_NUM_TO_SET)
		return -1;
	pCh = &demux_device->pChArray[pInfo->ch];
	mutex_lock(&pCh->mutex);

	for (i = 0; i < pCh->pidFilterCount; i++) {
		for (j = 0; j < pInfo->count; j++) {
			if (pCh->pidFilterList[i].pid == pInfo->pid[j]) {
				pCh->pidFilterList[i].refCnt--;
				if( 0 == pCh->pidFilterList[i].refCnt )
					pCh->pidFilterList[i].pid = -1;

				break;
			}
		}
	}

	SET_FLAG(pCh->events, EVENT_UPDATE_TS_LIST);
	pCh->pidFilterCount = IOCTL_RemoveInvalidPIDFilters(pCh->pidFilterList, pCh->pidFilterCount);
	mutex_unlock(&pCh->mutex);

	return 0;
}
int IOCTL_SetInputSourcePol(DEMUX_TP_INPUT_POL_T *pInfo)
{
	if (RHAL_SetInputSourcePol(pInfo->tpi, pInfo->pol) != TPK_SUCCESS)
		return -1;

	return 0;
}

int IOCTL_SetTPOutDataSource(DEMUX_SET_TP_OUT_SOURCE_T *pInfo)
{
	if (RHAL_TPOUTSetDataSource(pInfo->tpout_id, pInfo->tpout_src, pInfo->remux_param) != TPK_SUCCESS)
		return -1;

	return 0;
}

int IOCTL_SetTPOutStreamControl(DEMUX_SET_TP_OUT_STREAM_CONTROL_T *pInfo)
{
	if (RHAL_TPOUTStreamControl(pInfo->tpout_id, pInfo->ctrl) != TPK_SUCCESS)
		return -1;

	return 0;
}

int IOCTL_SetTPOutClockSpeed(DEMUX_SET_TP_OUT_CLOCK_SPEED_T *pInfo)
{
	if (RHAL_TPOUTClockSpeed(pInfo->tpout_id, pInfo->pre_div, pInfo->post_div) != TPK_SUCCESS)
		return -1;

	return 0;
}

/* free descrambler index in this channel */
int IOCTL_FreeAllPIDFilterIndex(DEMUX_FREE_DESCRAMBLE_INDEX_T *pInfo)
{
	demux_channel *pCh;
	int i;
	dmx_function_call();
	DEMUX_CHECK_CH(pInfo->ch);
	pCh = &demux_device->pChArray[pInfo->ch];
	mutex_lock(&pCh->mutex);
	for (i = 0; i < pCh->pidFilterCount; i++) {
			if (pCh->pidFilterList[i].enDescramble) {
				pCh->pidFilterList[i].cwIndex = -1;
				pCh->pidFilterList[i].enDescramble = 0;
			}
		}
	SET_FLAG(pCh->events, EVENT_UPDATE_TS_LIST);
	pCh->bUpdateDemuxTarget = true;

	mutex_lock(&demux_device->mutex);
	for (i = 0; i < demux_device->tpInfo.descrambler_num; i++) {
		if (demux_device->cwInfo[i].used && demux_device->cwInfo[i].ch == pInfo->ch) {
			demux_device->cwInfo[i].used   = 0;
		}
	}
	RHAL_FreePIDDescrambleAlgorithm();
	mutex_unlock(&demux_device->mutex);

	mutex_unlock(&pCh->mutex);

	return 0;
}
int IOCTL_ChangeAvSyncMode(DEMUX_SET_SPEED_T *pInfo)
{
	demux_channel *pCh;
	int i;
	DEMUX_CHECK_CH(pInfo->ch);
	pCh = &demux_device->pChArray[pInfo->ch];
	mutex_lock(&pCh->mutex);

	/* remove audio pid when
	 * 1. step (pause -> pause)
	 * 2. 0.5x (pause -> ff)
	 * 3. pause -> fast rewind
	 */
	if (pCh->pvrSpeed == 0 && (pInfo->speed == 0 || pInfo->speed == 128 || pInfo->speed < 0)) {
		DEMUX_SET_PID_T setPID;

		/*reset flag first or IOCTL_SetPIDImpl will ignore this request*/
		RESET_FLAG(pCh->status, STATUS_AUDIO_PAUSED);

		setPID.ch = pInfo->ch;
		setPID.pid = 0x1fff;
		setPID.pidType = DEMUX_PID_AUDIO;
		setPID.dest = DEMUX_DEST_ADEC0;
		IOCTL_SetPIDImpl(&setPID);

		setPID.dest = DEMUX_DEST_ADEC1;
		IOCTL_SetPIDImpl(&setPID);
	}

	pCh->pvrSpeed = pInfo->speed;
	if (pInfo->speed == 0) {
		mutex_unlock(&pCh->mutex);
		return 0;
	}
	RESET_FLAG(pCh->status, STATUS_AUDIO_PAUSED);

	for (i = 0; i < pCh->pidFilterCount; i++) {
		if (pCh->pidFilterList[i].pidType == DEMUX_PID_VIDEO) {
			unsigned char videoport = (pCh->pidFilterList[i].pesDest == DEMUX_DEST_VDEC0 ? 0 : (pCh->pidFilterList[i].pesDest == DEMUX_DEST_VDEC1 ? 1 : 255));
			long ignore;
			if (send_rpc_command(RPC_VIDEO, VIDEO_RPC_VOUT_ToAgent_SetDemuxSpeed, videoport, pInfo->speed, &ignore)) {
				pr_err("RPC fail!!\n");
			}
			break;
		}
	}
	if (pInfo->speed != 256)
	{
		if(pCh->avSyncMode != NAV_AVSYNC_VIDEO_ONLY)
		{
			/* According to https://harmony.lge.com:8443/issue/browse/KTASKWBS-275, only normal speed have audio */
			DEMUX_ResetAVSync(pCh, NAV_AVSYNC_VIDEO_ONLY);
		}
		/*cannot enable frame rate control for trick play because video should decode frame ASAP*/
		mutex_unlock(&pCh->mutex);
		PVR_EnableTPRateControl(pCh, false);

		return 0;
	}
	else
	{
		if(pCh->avSyncMode == MTP_AVSYNC_MODE) {
			mutex_unlock(&pCh->mutex);
			return 0;
		}
		DEMUX_ResetAVSync(pCh, MTP_AVSYNC_MODE);
	}

	mutex_unlock(&pCh->mutex);
	return 0;

}
int IOCTL_GetTPStatus(DEMUX_TP_STATUS_T *pStatus)
{
	demux_channel *pCh;
	TPK_TP_STATUS_T tpStatus;
	dmx_function_call();

	DEMUX_CHECK_CH(pStatus->ch);
	pCh = &demux_device->pChArray[pStatus->ch];

	if (RHAL_GetTpStatus(pCh->tunerHandle, &tpStatus) != TPK_SUCCESS)
		return -1;

	pStatus->tpStatus = tpStatus;
	return 0;
}

/*------------------------------------------------------------------
 * Func : DEMUX_SetTPInputConfig
 *
 * Desc :
 *      1. stream control
 *      2. set tp param
 *      3. set TP source
 *      4. set tpo
 *      5. alloc buffer for mtp
 *      6. free all filter
 */
int IOCTL_SetTPInputConfig(DEMUX_TP_SOURCE_CONFIG_T *pInfo)
{
	//dmx_notice("0. ch%d portType=%d inputType=%d casType=%d %s, line %d\n", pInfo->ch, pInfo->portType, pInfo->inputType, pInfo->casType ,__func__, __LINE__);

	int tp_id = 0;
	demux_channel *pCh;
	TPK_TP_STATUS_T tpStatus;
	DEMUX_TP_STREAM_CONTROL_T streamCtrl;
	DEMUX_FREE_DESCRAMBLE_INDEX_T data;
	TPK_TP_SOURCE_T tp_src;

	DEMUX_CHECK_CH(pInfo->ch);
	pCh = &demux_device->pChArray[pInfo->ch];
	tp_id = pCh->tunerHandle;

	/* 1. stream control */
	//dmx_notice("%s ch%d stream control\n", __func__, pInfo->ch);
	if (pInfo->inputType == TPK_INPUT_ENABLE || pInfo->inputType == TPK_INPUT_DISABLE)
	{
		streamCtrl.ch =	tp_id;
		if (pInfo->inputType == TPK_INPUT_ENABLE)
                {
			streamCtrl.ctrl	= TP_STREAM_START;
                        dmx_notice("%s ch%d Start streaming!\n", __func__, pInfo->ch);
                }
		else
                {
			streamCtrl.ctrl	= TP_STREAM_STOP;
                        dmx_notice("%s ch%d Stop streaming!\n", __func__, pInfo->ch);
                }
		IOCTL_SetTPStreamControl(&streamCtrl);
		return 0;
	}

	if (RHAL_GetTpStatus(tp_id, &tpStatus) != TPK_SUCCESS)
		return TPK_FAIL;

        /* 2. set tp param */
        /* tp stop streaming to set tp param */
	if(tpStatus.tp_stream_status == TP_STREAM_START)
	{
		streamCtrl.ch = tp_id;
		streamCtrl.ctrl = TP_STREAM_STOP ;
		IOCTL_SetTPStreamControl(&streamCtrl);
	}

	//dmx_notice(" 2.  set tp param  %s, line %d\n", __func__, __LINE__);
	tpStatus.tp_param.serial                	= 0 ;
	tpStatus.tp_param.sync_byte             	= 0x47 ;
	tpStatus.tp_param.ts_in_tsp_len         	= byte_188 ;
	tpStatus.tp_param.clr_tsp_scrmbl_bit    	= 0x1 ;
	tpStatus.tp_param.pid_filter_en         	= 0x1 ;

	if (pInfo->inputType == TPK_INPUT_SERIAL)
	{
		tpStatus.tp_param.serial = 1 ;
		dmx_notice("%s Set TP%d to Serial mode!\n", __func__, tp_id);
	}
	else if (pInfo->inputType == TPK_INPUT_PARALLEL)
	{
		tpStatus.tp_param.serial = 0 ;
		dmx_notice("%s Set TP%d to parallel mode!\n", __func__, tp_id);
	}
	// TODO: add two-bits mode

	if (pInfo->portType == TPK_PORT_FROM_MEM)
	{
	         dmx_notice("%s Set TP%d data from memory!\n", __func__, tp_id);
		/*
                If MW enables timestamp before setting tp source, MTP with 192-byte input won't work,
                because the tp source is not MTP. We have to check prefix_en here.
		*/
		tpStatus.tp_param.frc_en = tpStatus.tp_param.prefix_en;
		tpStatus.tp_param.ts_in_tsp_len = (tpStatus.tp_param.prefix_en) ? byte_192 : byte_188;
		tpStatus.tp_param.keep = (tpStatus.tp_param.prefix_en)? 1:0;
	}
	else
	{
	        dmx_notice("%s Set TP%d data from %d!(1:iD0,2:iD1,3:eI0,4:eI1,5:eI2)\n", __func__, tp_id, pInfo->portType);
		tpStatus.tp_param.keep = 0;
		tpStatus.tp_param.casType = (pInfo->casType == TPK_WITH_CAS) ? TPK_WITH_CAS : TPK_WITHOUT_CAS;
	}

	if (RHAL_SetTPMode(tp_id, tpStatus.tp_param) != TPK_SUCCESS)
		return -1;

	/* 3. set TP source */
        //dmx_notice("%s Ch%d set TP spurce\n", __func__, pInfo->ch);
	tp_src = RHAL_GetTPSource(pInfo->portType);
	if (RHAL_SetTPSource(tp_id, tp_src, pInfo->casType) != TPK_SUCCESS)
		return TPK_FAIL;
	pCh->tp_src = tp_src;

	if(tp_src == MTP) {
		dmx_notice("\033[1;36m %s tp%d STOP PCR tracking..\033[m\n", __func__, tp_id );
		IOCTL_StopPCRRecovery((DEMUX_CHANNEL_T *)&tp_id);
	}
        dmx_notice("%s Set TP%d Source from %d!(1:MTP,2:iD,3:eI0,4:eI1,5:eI2)\n", __func__, tp_id, tp_src);

	/* 4. set tpo */
	if(pInfo->casType == TPK_WITH_CAS)
	{
		TPK_TPOUT_REMUX_PARAM_T remux_param ;
		TPK_TPOUT_SOURCE_T tpout_src;
 		tpout_src = TPK_TPP_TO_TPOUT;
		remux_param.output_sync_byte = 0x47;
		remux_param.tpp_id = 0; /*default use tpp0 */

		if(tp_src == MTP)
			remux_param.tpp_src = MTP ;
		else if(tp_src != TS_UNMAPPING)
			remux_param.tpp_src = Internal_Demod ;
		
		if (RHAL_TPOUTSetDataSource(0, tpout_src, &remux_param) != TPK_SUCCESS)
			return TPK_FAIL;

		dmx_notice("%s Set TPO src(%d)remux from %d!(1:MEM,2:MUX)\n", __func__, tpout_src, remux_param.tpp_src);
	}

	/* 5. alloc buffer for mtp */
	if (pInfo->portType == TPK_PORT_FROM_MEM && pCh->mtpBuffer.allocSize == 0) {
                dmx_notice("%s alloc buffer(%d) for mtp\n", __func__, MTP_BUFFER_SIZE);
		if (DEMUX_BUF_AllocBuffer(&pCh->mtpBuffer,  MTP_BUFFER_SIZE, 1, 0) < 0)
			return -1;
	}
	IOCTL_ReConfigTPBuffer(pInfo->ch);
	IOCTL_CheckAvSync(pCh);

	/* 6. free all filter */
	data.ch = pCh->tunerHandle;
	IOCTL_FreeAllPIDFilterIndex(&data);

	/* feed back tp status*/
	if(tpStatus.tp_stream_status == TP_STREAM_START)
	{
		streamCtrl.ch = tp_id;
		streamCtrl.ctrl = TP_STREAM_START ;
		IOCTL_SetTPStreamControl(&streamCtrl);
	}

	return 0;
}

int IOCTL_GetFilterList(DEMUX_GET_FILTERS_T * pFilterList)
{
	int i = 0, j = 0;

	demux_channel *pCh;

	DEMUX_CHECK_CH(pFilterList->ch);
	pCh = &demux_device->pChArray[pFilterList->ch];

	pFilterList ->size = 0;
	//pid
	for(j =0;j < pCh->pidFilterCount && pFilterList ->size<DEMUX_MAX_NUM_FILTER_TO_GET; j++)
	{
		pFilterList ->filterList[pFilterList ->size].innerIndex 	= j;
		pFilterList ->filterList[pFilterList ->size].pid	 		= pCh->pidFilterList[j].pid;
		pFilterList ->filterList[pFilterList ->size].type 		= pCh->pidFilterList[j].pidType;
		pFilterList ->filterList[pFilterList ->size].tid 			= 0;
		pFilterList ->filterList[pFilterList ->size] .dest 		= pCh->pidFilterList[j].pesDest;
		pFilterList ->filterList[pFilterList ->size].pidClass 		= 0;
		pFilterList ->filterList[pFilterList ->size].cwIndex 		= pCh->pidFilterList[j].cwIndex;
		pFilterList ->filterList[pFilterList ->size].enDescramble	= pCh->pidFilterList[j].enDescramble;
		pFilterList ->size++;
	}
	//pes
	for(j =0;j <MAX_PID_FILTER_CB_NUM && pFilterList ->size<DEMUX_MAX_NUM_FILTER_TO_GET; j++)
	{
		if (pCh->pidFilterListCB[j].used)
		{
			pFilterList ->filterList[pFilterList ->size].innerIndex 	= j;
			pFilterList ->filterList[pFilterList ->size].pid 			= pCh->pidFilterListCB[j].pid;
			pFilterList ->filterList[pFilterList ->size].type 		= pCh->pidFilterListCB[j].pidType;
			pFilterList ->filterList[pFilterList ->size].tid 			= 0;
			pFilterList ->filterList[pFilterList ->size] .dest 		= DEMUX_DEST_BUFFER;
			pFilterList ->filterList[pFilterList ->size].pidClass 		= 1;
			pFilterList ->filterList[pFilterList ->size].gpb_size 		= PES_FILTER_RING_BUFFER_SIZE;
			pFilterList ->filterList[pFilterList ->size].cwIndex 		= pCh->pidFilterListCB[j].cwIndex;
			pFilterList ->filterList[pFilterList ->size].enDescramble	= pCh->pidFilterListCB[i].cwIndex >= 0 ;
			pFilterList ->size++;
		}
	}
	//section
	for(j =0;j < MAX_SECTION_FILTER_NUM && pFilterList ->size<DEMUX_MAX_NUM_FILTER_TO_GET; j++)
	{
		if (pCh->secListCB[j].used)
		{
			pFilterList ->filterList[pFilterList ->size].innerIndex 	= j;
			pFilterList ->filterList[pFilterList ->size].pid 			= pCh->secListCB[j].param.PID;
			pFilterList ->filterList[pFilterList ->size].type			= DEMUX_PID_PSI;
			pFilterList ->filterList[pFilterList ->size].tid 			= pCh->secListCB[j].param.PosVal[0];
			pFilterList ->filterList[pFilterList ->size] .dest 		= DEMUX_DEST_BUFFER;
			pFilterList ->filterList[pFilterList ->size].pidClass 		= 2;
			pFilterList ->filterList[pFilterList ->size].gpb_size		= pCh->secListCB[j].count * SEC_FILTER_BUFFER_UNIT_SIZE;
			pFilterList ->filterList[pFilterList ->size].cwIndex 		= -1;
			pFilterList ->filterList[pFilterList ->size].enDescramble	= 0 ;
			pFilterList ->size++;
		}
	}
	return 0;
}

int IOCTL_GetTPPacketStatus(DEMUX_TP_PACKETSTATUS_T* pTpPs)
{
	demux_channel *pCh;
	dmx_function_call();

	DEMUX_CHECK_CH(pTpPs->ch);
	pCh = &demux_device->pChArray[pTpPs->ch];

	if (RHAL_TrackErrorPacket(pCh->tunerHandle, &(pTpPs->err), &(pTpPs->rev), &(pTpPs->drop)) != TPK_SUCCESS)
		return -1;

	return 0;
}
bool IOCTL_CheckRingBufferData()
{
#define BS_DISTANCE_TO_READ(start, end, base, limit) \
((end) + ((end) >= (start) ? 0 : limit - base) - (start))
	int iChannel, iItem;
	for (iChannel =0; iChannel < demux_device->chNum; iChannel++)
	{
		for ( iItem = 0; iItem < MAX_SECTION_FILTER_NUM; iItem++)
		{
			DEMUX_SEC_LIST_T *pSecItem = &(demux_device->pChArray[iChannel].secListCB[iItem]);
			if (pSecItem->used)
				if(BS_DISTANCE_TO_READ(((RINGBUFFER_HEADER *)(pSecItem->rbHeader.virAddr))->readPtr[1],	*(pSecItem->pWrPtr), pSecItem->pBufferLower, pSecItem->pBufferUpper) > 4)
					return true;
		}
		for ( iItem = 0; iItem < MAX_PID_FILTER_CB_NUM; iItem++)
		{
			DEMUX_PES_MAP_T *pPesMap = &(demux_device->pChArray[iChannel].pesMap[iItem]);
			RINGBUFFER_HEADER * pRBH = (RINGBUFFER_HEADER *)(pPesMap->rbHeader.virAddr);
			if (demux_device->pChArray[iChannel].pidFilterListCB[iItem].used && (pRBH->reserve2 == DEMUX_PESBUFFER_OP_INITIALIZED))
				if(BS_DISTANCE_TO_READ(pRBH->readPtr[1], *(pPesMap->pWrPtr), pPesMap->pBufferLower, pPesMap->pBufferUpper) > 4)
					return true;
		}
	}
	return false;
}
int IOCTL_SetTPPatternSearchPID(DEMUX_TP_PATTERN_SEARCH_T *pInfo)
{
	demux_channel *pCh;
	dmx_function_call();

	DEMUX_CHECK_CH(pInfo->ch);
	pCh = &demux_device->pChArray[pInfo->ch];

	if(pCh->tunerHandle != 0 && pCh->tunerHandle != 1) {
		dmx_crit("[%s %d]TP%d doesn't support start code search\n", __func__, __LINE__, pCh->tunerHandle);
		return -1;
	}
	if (RHAL_SetTPPatternSearchPID(pCh->tunerHandle, pInfo->pid) != TPK_SUCCESS)
		return -1;

	return 0;
}
int IOCTL_GetTPInfoBuffer(DEMUX_PVR_BUF_INFO_T *pInfo)
{
	demux_channel *pCh;
	DEMUX_BUF_T *pInfoH;
	int size;

	DEMUX_CHECK_CH(pInfo->ch);
	pCh = &demux_device->pChArray[pInfo->ch];

	if(pInfo->ch != 0 && pInfo->ch != 1) {
		dmx_crit("[%s %d]TP%d doesn't support start code search\n", __func__, __LINE__, pInfo->ch);
		return -1;
	}
	size = TP_INFO_BUFFER_SIZE & (~0x7); /*each info pack is 8 byte*/
	if (pCh->tpInfoBuffer.allocSize == 0) {
		if (DEMUX_BUF_AllocBuffer(&pCh->tpInfoBuffer, size, 0, 0) < 0) {
			dmx_crit("[%s %d]CH%d fail to allocate TP info buffer\n", __func__, __LINE__, pInfo->ch);
			return -1;
		}
	}
	pInfoH = &pCh->tpInfoBufferH;
	if (pInfoH->virAddr == 0) {
		if (DEMUX_BUF_AllocFromPoll(pInfoH, sizeof(RINGBUFFER_HEADER), &demux_device->bufPoll, 0) < 0) {
			dmx_crit("[%s %d]CH%d out of memory: allocate buffer header fail\n", __func__, __LINE__, pCh->tunerHandle);
			return -1;
		}
		DEMUX_BUF_ResetRBHeader(pInfoH, &pCh->tpInfoBuffer, RINGBUFFER_STREAM, 0);
	}

	pInfo->bufPhyAddr = pInfoH->phyAddr;
	pInfo->bufSize = pInfoH->allocSize;
	return 0;
}
